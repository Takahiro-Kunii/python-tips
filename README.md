# python-tips

# 環境
* 望むなら１つのOSに個別の環境（python version 3.3とpython version 3.5等）を作り、切り替えて使う事ができる
* それぞれの環境はディレクトリ単位で管理される

https://docs.python.org/ja/3/library/venv.html?highlight=env

### 手順
1. 環境作成
環境にsandbox1という名前を付け用意する
```
python3 -m venv sandbox1
```
これでカレントディレクトリ直下にsandbox1というディレクトリが作成される。

2. 環境利用開始
作成したsandbox1環境を利用する
```
source sandbox1/bin/activate
```
sandbox1の位置を正しい相対パス、あるいは絶対パスで指定したなら、どの場所からでも実行できる。
プロンプトの先頭に
```
(sandbox1) 
```
が付く。以後、環境利用終了するまで、この環境が適用される。

3. 環境利用終了
```
deactivate
```
プロンプトの先頭から
```
(sandbox1) 
```
が消える。

### 環境で利用されるpythonのバージョン
以下のコマンドで、利用可能なバージョンと現在のバージョンがわかる
```
pyenv versions
```

利用したいバージョンがない場合、以下のコマンドでインストール候補を探す
```
pyenv install --list
```
以下のようにリストが出力される。
```
Available versions:
  2.1.3
  2.2.3
  2.3.7
  ・・・
  anaconda3-2020.11
  anaconda3-2021.05
  anaconda3-2021.11
  graalpython-20.1.0
  ・・・
```
リストの中から、インストールしたいバージョンを指定してインストールする。
anaconda3-2021.11なら
```
pyenv install anaconda3-2021.11
```
インストールしたバージョンを切り替えるには
```
pyenv global anaconda3-2021.11
```
仮想環境のバージョンを切り替える場合
注意）それまでに環境にインストールしたパッケージは削除される。
requirement.txtを作成しておくと、再度インストールしてくれる
```	
(sandbox1)$ pip freeze > requirement.txt
```
新しいバージョンに切り替えた状態で、今のバージョンに切り替わる
```
python -m venv .venv --clear
```


# モジュール
* [C言語でビルドしたモジュールを呼び出す](https://github.com/Takahiro-Kunii/python-tips/tree/master/c)
