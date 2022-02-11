static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
if ( V_4 & V_5 )
F_2 ( V_6 . V_7 ,
F_3 ( V_6 . V_8 ) , V_3 ) ;
else if ( V_4 & V_9 )
F_2 ( V_6 . V_7 ,
F_4 ( V_6 . V_8 ) , V_3 ) ;
}
static void F_5 ( T_1 V_7 ,
T_1 V_10 , int V_8 , struct V_11 * V_12 )
{
T_2 V_13 , V_14 ;
V_13 = F_6 ( V_7 , F_7 ( V_8 ) ) ;
V_14 = F_6 ( V_7 , F_8 ( V_8 ) ) ;
V_12 -> V_15 = V_10 + ( ( unsigned long ) V_13 << 16 ) ;
V_12 -> V_16 = V_12 -> V_15 + ( V_14 + 1 ) * 64 * 1024 ;
}
static int T_3 F_9 ( void )
{
T_1 V_17 , V_7 , V_10 ;
T_2 V_18 , V_19 ;
int V_8 , V_20 , V_21 ;
V_19 = F_6 ( V_22 , V_23 ) ;
V_10 = ( V_19 & 0xffff0000 ) << 8 ;
V_17 = F_10 ( V_24 ) ;
V_7 = F_10 ( V_25 ) ;
V_18 = F_6 ( V_17 , V_26 ) ;
V_21 = V_20 = 0 ;
if ( F_11 () ) {
if ( V_18 & ( 1 << 16 ) )
V_20 = 1 ;
if ( ( V_18 & ( 1 << 15 ) ) == 0 )
V_21 = 1 ;
} else {
if ( ( V_18 & ( 1 << 16 ) ) == 0 )
V_21 = 1 ;
}
V_8 = 0 ;
if ( V_20 ) {
V_6 . V_8 = V_8 ;
V_6 . V_7 = V_7 ;
F_5 ( V_7 , V_10 , V_8 ,
V_27 ) ;
F_2 ( V_7 , F_12 ( V_8 ) ,
V_28 ) ;
F_2 ( V_7 , F_13 ( V_8 ) ,
V_29 ) ;
F_2 ( V_7 , F_14 ( V_8 ) ,
V_30 ) ;
F_15 ( L_1 , V_8 , V_27 ) ;
return F_16 ( & V_31 ) ;
}
if ( V_21 ) {
F_5 ( V_7 , V_10 , V_8 ,
V_32 ) ;
F_15 ( L_2 , V_8 , V_32 ) ;
return F_16 ( & V_33 ) ;
}
return 0 ;
}
