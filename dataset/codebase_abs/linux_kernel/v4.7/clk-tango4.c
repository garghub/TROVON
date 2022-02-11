static void T_1 F_1 ( int V_1 , const char * V_2 , void T_2 * V_3 )
{
char V_4 [ 8 ] ;
T_3 V_5 , V_6 , div ;
sprintf ( V_4 , L_1 , V_1 ) ;
V_5 = F_2 ( V_3 + V_1 * 8 ) ;
V_6 = F_3 ( V_5 ) + 1 ;
div = ( F_4 ( V_5 ) + 1 ) << F_5 ( V_5 ) ;
F_6 ( NULL , V_4 , V_2 , 0 , V_6 , div ) ;
if ( F_7 ( V_5 ) != 1 )
F_8 ( L_2 , V_4 ) ;
}
static void T_1 F_9 ( int V_1 , void T_2 * V_3 )
{
char V_4 [ 8 ] ;
T_3 V_5 , V_6 , div ;
sprintf ( V_4 , L_3 , V_1 ) ;
V_5 = F_2 ( V_3 + V_1 * 8 ) ;
V_6 = 1 << 27 ;
div = ( 2 << 27 ) + V_5 ;
F_6 ( NULL , V_4 , L_4 , 0 , V_6 , div ) ;
if ( V_5 > 0xf0000000 )
F_8 ( L_5 , V_4 , V_5 ) ;
}
static void T_1 F_10 ( struct V_7 * V_8 )
{
struct V_9 * * V_10 = V_11 . V_12 ;
void T_2 * V_3 = F_11 ( V_8 , 0 ) ;
const char * V_2 = F_12 ( V_8 , 0 ) ;
if ( ! V_3 )
F_8 ( L_6 , V_8 -> V_4 ) ;
if ( F_2 ( V_3 + V_13 ) & V_14 )
F_8 ( L_7 , V_8 -> V_4 ) ;
if ( F_2 ( V_3 + V_15 ) & V_14 )
F_8 ( L_8 , V_8 -> V_4 ) ;
F_13 ( 0x100 , V_3 + V_13 ) ;
F_1 ( 0 , V_2 , V_3 ) ;
F_1 ( 1 , V_2 , V_3 ) ;
F_1 ( 2 , V_2 , V_3 ) ;
F_9 ( 2 , V_3 + 0x80 ) ;
F_9 ( 6 , V_3 + 0x80 ) ;
V_10 [ 0 ] = F_14 ( NULL , L_9 , L_10 , 0 ,
V_3 + V_13 , 8 , 8 , V_16 , NULL ) ;
V_10 [ 1 ] = F_6 ( NULL , L_11 , L_12 , 0 , 1 , 4 ) ;
V_10 [ 2 ] = F_6 ( NULL , L_13 , L_14 , 0 , 1 , 2 ) ;
V_10 [ 3 ] = F_6 ( NULL , L_15 , L_16 , 0 , 1 , 2 ) ;
if ( F_15 ( V_10 [ 0 ] ) || F_15 ( V_10 [ 1 ] ) || F_15 ( V_10 [ 2 ] ) || F_15 ( V_10 [ 3 ] ) )
F_8 ( L_17 , V_8 -> V_4 ) ;
if ( F_16 ( V_8 , V_17 , & V_11 ) )
F_8 ( L_18 , V_8 -> V_4 ) ;
}
