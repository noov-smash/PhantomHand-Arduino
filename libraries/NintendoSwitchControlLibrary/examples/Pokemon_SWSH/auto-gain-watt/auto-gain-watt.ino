/**
 * 巣穴からワットを回収し続けるスケッチ
 *
 * 初期条件は以下の通り
 * 1.願いのかたまりを投げ入れた巣穴の前にいること
 * 2.巣穴のワットは回収済みであること
 * 3.インターネットで時間をあわせるがOFFになっていること
 * 4.オフライン状態であること
 * 5.無線のコントローラーが接続されていないこと
 * 6.「設定」から「話の速さ」を「速い」にしておくこと
 */

// ライブラリを読み込むためのコード
#include <NintendoSwitchControlLibrary.h>

// ワットを回収するシーケンス
void execWattGainSequence() {
    // 募集開始
    pushButton(Button::A, 3000);
    // ホーム画面 > 設定
    pushButton(Button::HOME, 500);
    pushHat(Hat::DOWN, 25);
    pushHat(Hat::RIGHT, 25, 5);  // SwitchのVer11〜に対応。11未満の場合は、最後の5を4にする必要がある
    pushButton(Button::A, 100);
    // 設定 > 本体 > 日付と時刻
    holdHat(Hat::DOWN, 2000);
    pushHat(Hat::RIGHT, 25);
    pushHat(Hat::DOWN, 25, 4);
    pushButton(Button::A, 200);
    // 日付と時刻 > 現在の日付と時刻
    pushHat(Hat::DOWN, 25, 2);
    pushButton(Button::A, 500);
    pushHat(Hat::RIGHT, 25, 2);
    pushHat(Hat::UP, 25);
    pushHat(Hat::RIGHT, 25, 3);
    pushButton(Button::A, 50);
    // ホーム画面 > ゲーム画面
    pushButton(Button::HOME, 600);
    pushButton(Button::A, 600);
    // レイド募集中止
    pushButton(Button::B, 1000);
    pushButton(Button::A, 4000);
    // ワット回収
    pushButton(Button::A, 1000);
    pushButton(Button::B, 1000);  // ここをBにすることで、月が変わった際にキャンセルできず詰んでしまう問題をスマートに解決できる
    pushButton(Button::A, 1000);
}

// マイコンのセット時に1度だけ行われる処理
void setup() {
    // Switchがマイコンを認識するまでは信号を受け付けないため、適当な処理をさせておく
    pushButton(Button::B, 500, 5);
    // 巣穴をチェックする
    pushButton(Button::A, 1000);
}

// ここに記述した内容がループされ続ける
void loop() {
    execWattGainSequence();
}
