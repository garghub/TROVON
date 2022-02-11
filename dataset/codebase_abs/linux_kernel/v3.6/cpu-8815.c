static struct V_1 *
F_1 ( int V_2 , T_1 V_3 , int V_4 ,
struct V_5 * V_6 )
{
struct V_7 V_8 [] = {
{
. V_9 = V_3 ,
. V_10 = V_3 + 127 ,
. V_11 = V_12 ,
} ,
{
. V_9 = V_4 ,
. V_10 = V_4 ,
. V_11 = V_13 ,
}
} ;
return F_2 ( NULL , L_1 , V_2 ,
V_8 , F_3 ( V_8 ) ,
V_6 , sizeof( * V_6 ) ) ;
}
void F_4 ( T_1 * V_14 , int V_15 , int V_4 ,
struct V_5 * V_6 )
{
int V_16 = 0 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ , V_16 += 32 , V_4 ++ ) {
V_6 -> V_18 = V_16 ;
V_6 -> V_19 = F_5 ( V_16 ) ;
V_6 -> V_20 = 32 ;
F_1 ( V_17 , V_14 [ V_17 ] , V_4 , V_6 ) ;
}
}
static int T_2 F_6 ( void )
{
struct V_5 V_6 = {
} ;
F_4 ( V_21 , F_3 ( V_21 ) ,
V_22 , & V_6 ) ;
F_7 ( NULL , L_2 , V_23 , V_24 , 0 , 0 , NULL , 0 ) ;
F_7 ( NULL , L_3 , V_25 , V_24 , V_26 , 0 , NULL , 0 ) ;
return 0 ;
}
void T_2 F_8 ( void )
{
F_9 ( V_27 , F_3 ( V_27 ) ) ;
}
void T_2 F_10 ( void )
{
F_11 ( F_12 ( V_28 + 0x00 ) , V_29 + 0 , ~ 0 , 0 ) ;
F_11 ( F_12 ( V_28 + 0x20 ) , V_29 + 32 , ~ 0 , 0 ) ;
F_13 () ;
}
void T_2 F_14 ( void )
{
#ifdef F_15
F_16 ( F_12 ( V_30 ) , 0x00730249 , 0xfe000fff ) ;
#endif
return;
}
void F_17 ( char V_31 , const char * V_32 )
{
void T_3 * V_33 = F_12 ( V_34 + 0x18 ) ;
F_18 ( 1 , V_33 ) ;
}
