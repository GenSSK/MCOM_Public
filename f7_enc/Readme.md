# これはなに？
mbedのハードウェアエンコーダを使ったカウンタです。
モータのエンコーダを読み飛ばすことなく、計測することが可能となります。
4chのエンコーダを同時に読み取ることができます。

## 対応ボード
- NUCLEO-F767ZI
- NUCLEO-F746ZG

## 使い方
使い方は、まず`F7_enc.h`をインクルードしてください。

次に、初期化を実行します。
例えば、tim1を使いたい場合は`tim1_init()`を一回実行してください。

最後に、計測したいタイミング（例えば制御周期）で`get_counter_tim1()`を実行してください。
返り値は`int`で、エンコーダのカウント値が返ってきます。
もし、カウンタ値をリセットしたい場合は、引数に`True`を渡してください。

## 接続
以下のように接続してください。

```cpp
/**TIM1 GPIO Configuration
     PE9      ------> TIM1_CH1
     PE11     ------> TIM1_CH2
*/

/**TIM3 GPIO Configuration
     PA6     ------> TIM3_CH1
     PB5     ------> TIM3_CH2
*/

/**TIM4 GPIO Configuration
     PD12     ------> TIM4_CH1
     PD13     ------> TIM4_CH2
*/

/**TIM8 GPIO Configuration
     PC6     ------> TIM8_CH1
     PC7     ------> TIM8_CH2
*/
```

## 中身
例えばtim4の計測は以下。
カウントの差分を計測し、足していくことで、あふれることなく計測ができる。
int16_tにキャスト変換していることが重要。
```cpp
int get_counter_tim4(){
  static int counts;
  static int countsbefore = 0;
  uint16_t temp;

  temp = TIM4->CNT;
  counts += (int16_t)(temp - countsbefore);　//ここでキャスト 0 - 65535 を -32768 - 32767 にする
  countsbefore = temp;

  return counts;
}
```
## 謝辞
このプログラムは、[小林航大氏](https://github.com/k3k8)がB3のときに作成したものをベースにちょこちょこアップデートしています。ここに、感謝の意を表します。

## 今後
F4でもできるっぽいところまでは確認した。