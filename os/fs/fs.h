/*
 * TacOS Source Code
 *    Tokuyama kousen Advanced educational Computer.
 *
 * Copyright (C) 2011 - 2016 by
 *                      Dept. of Computer Science and Electronic Engineering,
 *                      Tokuyama College of Technology, JAPAN
 *
 *   上記著作権者は，Free Software Foundation によって公開されている GNU 一般公
 * 衆利用許諾契約書バージョン２に記述されている条件を満たす場合に限り，本ソース
 * コード(本ソースコードを改変したものを含む．以下同様)を使用・複製・改変・再配
 * 布することを無償で許諾する．
 *
 *   本ソースコードは＊全くの無保証＊で提供されるものである。上記著作権者および
 * 関連機関・個人は本ソースコードに関して，その適用可能性も含めて，いかなる保証
 * も行わない．また，本ソースコードの利用により直接的または間接的に生じたいかな
 * る損害に関しても，その責任を負わない．
 *
 *
 */

/*
 * fs/fs.h : fs.cmm の外部インタフェース
 *
 * 2015.12.17 : openDir と readDir を削除
 * 2015.11.20 : open システムコールの引数を変更
 * 2015.11.17 : chkCloseForg() を廃止、 mkDir と rmDir を追加
 * 2015.09.02 : fatFs.h から fs.h に名前変更(重村)
 * 2015.04.24 : chkCloseForg() を宣言
 * 2014.11.25 : seek システムコールを実装
 * 2014.11.04 : mkDir システムコールを実装
 * 2014.11.03 : write システムコールを実装
 * 2014.10.06 : remove システムコールを実装
 * 2014.10.03 : creat システムコールを実装
 * 2014.06.10 : fatFsMain の引数を削除
 * 2014.06.03 : 村田開発開始
 * 2011.05.23 : Boot-- をもとに新規作成
 *
 *
 * $Id$
 *
 */

#include "fsDef.h"                              // 全体に共通の定義

public int fsLink;                              // FS へのリンク番号
public void fsMain();                           // サーバのメインルーチン

/*----------------------------------------------------------------------------
 *   名前   : creat
 *　 戻り値 : int(正常なら0、失敗なら<0)
 *   引数   : char[] path 作成するファイルのパス
 *   解説   : ファイルを新規作成する
 */
public int creat(char[] path);


/*----------------------------------------------------------------------------
 *   名前   : remove
 *　 戻り値 : int (正常なら0、失敗なら<0)
 *   引数   : char[] path 削除するファイルのパス
 *   解説   : ファイルを削除する
 */
public int remove(char[] path);


/*----------------------------------------------------------------------------
 *  名前   : mkDir
 *　戻り値 : int (正常なら0、失敗なら<0)
 *　引数   : char[] path　作成するディレクトリのパス
 *  解説   : ディレクトリを作成する
 */
public int mkDir(char[] path);


/*----------------------------------------------------------------------------
 *   名前   : rmDir
 *　 戻り値 : int(正常なら0、失敗なら<0)
 *　 引数   : char[] path　削除するディレクトリのパス
 *   解説   : ディレクトリを削除する
 */
public int rmDir(char[] path);


/*----------------------------------------------------------------------------
 *   名前   : open
 *   戻り値 : int (ファイル番号(>=0)、-1=エラー)
 *   引数   : char[] path ファイルへのパス
 *            int mode オープンモード(READ_MODE/WRITE_MODE/APPEND_MODE)
 *   解説   : ファイルをオープンし、ファイル番号を返す
 */
public int open(char[] path, int mode);


/*----------------------------------------------------------------------------
 *   名前   : close
 *   戻り値 : int (0=正常、-1=エラー)
 *   引数   : int fd オープン済みファイル番号
 *   解説   : ファイル/ディレクトリをクローズする
 */
public int close(int fd);


/*----------------------------------------------------------------------------
 *   名前   : read
 *   戻り値 : int (読み込んだバイト数(>0)、0=EOF、-1=エラー)
 *   引数   : int fd オープン済みファイル番号
 *            void[] buf データを読み込むバッファ
 *            int len バッファサイズ(バイト単位)
 *   解説   : ファイルからデータを読み込む
 *            # 512バイト単位のリードしかサポートしていない
 */
public int read(int fd, void[] buf, int len);


/*----------------------------------------------------------------------------
 *   名前   : write
 *   戻り値 : int (書き込んだバイト数(>=0)、<0=エラー)
 *   引数   : int fd オープン済みファイル番号
 *            void[] buf 書き込むデータ
 *            int len データサイズ(バイト単位)
 *   解説   : ファイルへからデータを書き込む
 */
public int write(int fd, void[] buf, int len);


/*----------------------------------------------------------------------------
 *   名前   : seek
 *　 戻り値 : int (正常なら0、失敗なら<0)
 *　 引数   : int ptrh　上位絶対バイト位置
 *            int ptrl  下位絶対バイト位置
 *   解説   : ファイルの参照位置を変更する
 */
public int seek(int fd, int ptrh, int ptrl);
