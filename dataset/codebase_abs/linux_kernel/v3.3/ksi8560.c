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
struct V_6 * V_6 = F_5 ( NULL , 0 ,
V_7 | V_8 ,
0 , 256 , L_2 ) ;
F_6 ( V_6 == NULL ) ;
F_7 ( V_6 ) ;
F_8 () ;
}
static void T_1 F_9 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_10 ( V_10 ) ; V_9 ++ ) {
struct V_11 * V_12 = & V_10 [ V_9 ] ;
F_11 ( V_12 -> V_13 , V_12 -> V_12 , V_12 -> V_14 ) ;
}
F_12 ( V_15 , V_16 , V_17 ) ;
F_12 ( V_15 , V_16 , V_18 ) ;
F_12 ( V_19 , V_20 , V_17 ) ;
F_12 ( V_19 , V_20 , V_18 ) ;
F_12 ( V_21 , V_22 , V_17 ) ;
F_12 ( V_21 , V_23 , V_18 ) ;
}
static void T_1 F_13 ( void )
{
struct V_24 * V_25 ;
V_25 = F_14 ( NULL , NULL , L_3 ) ;
if ( V_25 )
V_2 = F_15 ( V_25 , 0 ) ;
else
F_3 ( V_5 L_4 ) ;
if ( V_26 . V_27 )
V_26 . V_27 ( L_5 , 0 ) ;
#ifdef F_16
F_17 () ;
F_9 () ;
#endif
}
static void F_18 ( struct V_28 * V_29 )
{
T_2 V_30 , V_31 , V_32 ;
V_30 = F_19 ( V_33 ) ;
V_31 = F_19 ( V_34 ) ;
F_20 ( V_29 , L_6 ) ;
F_20 ( V_29 , L_7 ) ;
if ( V_2 ) {
F_20 ( V_29 , L_8 ,
F_21 ( V_2 + V_35 ) ) ;
F_20 ( V_29 , L_9 ,
F_21 ( V_2 + V_36 ) ) ;
} else
F_20 ( V_29 , L_10 ) ;
F_20 ( V_29 , L_11 , V_30 ) ;
F_20 ( V_29 , L_12 , V_31 ) ;
V_32 = F_19 ( V_37 ) ;
F_20 ( V_29 , L_13 , ( ( V_32 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_22 ( void )
{
unsigned long V_38 = F_23 () ;
return F_24 ( V_38 , L_14 ) ;
}
