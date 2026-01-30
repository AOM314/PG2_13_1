#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <Novice.h>

const char kWindowTitle[] = "GC1D_02_イワタニ_アオイ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// プレイヤー
	Player player;
	player.Init(640, 600);

	// 敵
	Enemy enemies[2];

	enemies[0].Init(300, 180, 4);
	enemies[1].Init(900, 260, -4);

	// 弾

	const int kBulletMax = 20;
	Bullet bullets[kBulletMax];

	for (int i = 0; i < kBulletMax; i++) {
		bullets[i].isAlive = false;
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {

		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player.Update(keys);

		for (int i = 0; i < 2; i++) {

			enemies[i].Update();
		}

		// 弾

		if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {

			for (int i = 0; i < kBulletMax; i++) {

				if (!bullets[i].isAlive) {

					bullets[i].Fire(player.x, player.y);

					break;

				}
			}
		}

		for (int i = 0; i < kBulletMax; i++) {

			bullets[i].Update();

		}

		// 当たり判定
		for (int i = 0; i < 2; i++) {

			for (int j = 0; j < kBulletMax; j++) {

				if (enemies[i].isAlive && bullets[j].isAlive) {

					int dx = enemies[i].x - bullets[j].x;
					int dy = enemies[i].y - bullets[j].y;

					if (dx * dx + dy * dy < 25 * 25) {

						Enemy::isAllDead = true;

						for (int k = 0; k < 2; k++) {
							enemies[k].OnHit();
							enemies[k].isAlive = false;
						}

						bullets[j].isAlive = false;
					}
				}
			}
		}

		// Rキーで敵復活
		if (Enemy::isAllDead && preKeys[DIK_R] == 0 && keys[DIK_R] != 0) {

			for (int i = 0; i < 2; i++) {

				enemies[i].Respawn();
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player.Draw();

		for (int i = 0; i < 2; i++) {

			enemies[i].Draw();

		}

		for (int i = 0; i < kBulletMax; i++) {

			bullets[i].Draw();

		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
