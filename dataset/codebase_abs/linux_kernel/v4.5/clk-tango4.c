static void T_1 F_1 ( int V_1 , const char * V_2 , void T_2 * V_3 )
{
char V_4 [ 8 ] ;
T_3 V_5 , V_6 , div ;
sprintf ( V_4 , L_1 , V_1 ) ;
V_5 = F_2 ( V_3 + V_1 * 8 ) ;
V_6 = F_3 ( V_5 ) + 1 ;
div = ( F_4 ( V_5 ) + 1 ) << F_5 ( V_5 ) ;
F_6 ( NULL , V_4 , V_2 , 0 , V_6 , div ) ;
}
static int T_1 F_7 ( void T_2 * V_3 )
{
T_4 V_7 [ 16 ] = { 2 , 4 , 3 , 3 , 3 , 3 , 3 , 3 , 4 , 4 , 4 , 4 } ;
int V_1 = F_8 ( F_2 ( V_3 + V_8 ) ) ;
return V_7 [ V_1 ] ;
}
static void T_1 F_9 ( struct V_9 * V_10 )
{
int div , V_11 ;
void T_2 * V_3 = F_10 ( V_10 , 0 ) ;
const char * V_2 = F_11 ( V_10 , 0 ) ;
if ( ! V_3 )
F_12 ( L_2 , V_10 -> V_12 ) ;
F_1 ( 0 , V_2 , V_3 ) ;
F_1 ( 1 , V_2 , V_3 ) ;
V_13 [ 0 ] = F_13 ( NULL , L_3 , L_4 , 0 ,
V_3 + V_14 , 8 , 8 , V_15 , NULL ) ;
div = F_2 ( V_3 + V_16 ) & F_14 ( 23 ) ? F_7 ( V_3 ) : 4 ;
V_13 [ 1 ] = F_6 ( NULL , L_5 , L_6 , 0 , 1 , div ) ;
V_11 = F_15 ( V_10 , V_17 , & V_18 ) ;
if ( F_16 ( V_13 [ 0 ] ) || F_16 ( V_13 [ 1 ] ) || V_11 < 0 )
F_12 ( L_7 , V_10 -> V_12 ) ;
}
