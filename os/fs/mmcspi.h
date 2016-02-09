/*
 * TacOS Source Code
 *    Tokuyama kousen Educational Computer 16bit Ver.
 *
 * Copyright (C) 2009-2016 by
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
 * fs/mmcspi.h : mmcspi.cmm の外部インタフェース
 *
 * 2015.09.02 : コメントなどの体裁を調整(重村)
 * 2014.06.03 : 村田開発開始
 * 2012.09.14 : バッファの型を char[] から void[] に変更
 * 2012.01.08 : 初期バージョン
 *
 * $Id$
 *
 */

/*----------------------------------------------------------------------------
 * public function
 *---------------------------------------------------------------------------*/
/*
 * initMmcSpi : initialize
 */
public void initMmcSpi();

/*
 * readSct : read block(sector address)
 *  h   : sector address upper
 *  l   : sector address lower
 *  buf : data buffer
 */
public void readSct(int h, int l, void[] buf);

/*
 * writeSct : write block(sector address)
 *  h   : sector address upper
 *  l   : sector address lower
 *  buf : data buffer
 */
public void writeSct(int h, int l, void[] buf);
