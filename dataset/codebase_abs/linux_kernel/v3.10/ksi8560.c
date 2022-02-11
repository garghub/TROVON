static void F_1 ( char * V_1 )
{
if ( V_2 )
F_2 ( V_2 + V_3 , V_4 ) ;
else
F_3 ( V_5 L_1 ) ;
for (; ; ) ;
}
static void T_1 F_4 ( void )
{
struct V_6 * V_6 = F_5 ( NULL , 0 , V_7 ,
0 , 256 , L_2 ) ;
F_6 ( V_6 == NULL ) ;
F_7 ( V_6 ) ;
F_8 () ;
}
static void T_1 F_9 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_10 ( V_9 ) ; V_8 ++ ) {
struct V_10 * V_11 = & V_9 [ V_8 ] ;
F_11 ( V_11 -> V_12 , V_11 -> V_11 , V_11 -> V_13 ) ;
}
F_12 ( V_14 , V_15 , V_16 ) ;
F_12 ( V_14 , V_15 , V_17 ) ;
F_12 ( V_18 , V_19 , V_16 ) ;
F_12 ( V_18 , V_19 , V_17 ) ;
F_12 ( V_20 , V_21 , V_16 ) ;
F_12 ( V_20 , V_22 , V_17 ) ;
}
static void T_1 F_13 ( void )
{
struct V_23 * V_24 ;
V_24 = F_14 ( NULL , NULL , L_3 ) ;
if ( V_24 )
V_2 = F_15 ( V_24 , 0 ) ;
else
F_3 ( V_5 L_4 ) ;
if ( V_25 . V_26 )
V_25 . V_26 ( L_5 , 0 ) ;
#ifdef F_16
F_17 () ;
F_9 () ;
#endif
}
static void F_18 ( struct V_27 * V_28 )
{
T_2 V_29 , V_30 , V_31 ;
V_29 = F_19 ( V_32 ) ;
V_30 = F_19 ( V_33 ) ;
F_20 ( V_28 , L_6 ) ;
F_20 ( V_28 , L_7 ) ;
if ( V_2 ) {
F_20 ( V_28 , L_8 ,
F_21 ( V_2 + V_34 ) ) ;
F_20 ( V_28 , L_9 ,
F_21 ( V_2 + V_35 ) ) ;
} else
F_20 ( V_28 , L_10 ) ;
F_20 ( V_28 , L_11 , V_29 ) ;
F_20 ( V_28 , L_12 , V_30 ) ;
V_31 = F_19 ( V_36 ) ;
F_20 ( V_28 , L_13 , ( ( V_31 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_22 ( void )
{
unsigned long V_37 = F_23 () ;
return F_24 ( V_37 , L_14 ) ;
}
