static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_3 == 0 && F_2 ( V_4 ) == 0 )
return V_5 ;
else
return V_6 ;
}
static void T_2 F_3 ( void )
{
struct V_7 * V_7 = F_4 ( NULL , 0 ,
V_8 | V_9 ,
0 , 256 , L_1 ) ;
F_5 ( V_7 == NULL ) ;
F_6 ( V_7 ) ;
F_7 () ;
}
static void T_2 F_8 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < F_9 ( V_11 ) ; V_10 ++ ) {
const struct V_12 * V_13 = & V_11 [ V_10 ] ;
F_10 ( V_13 -> V_14 , V_13 -> V_13 , V_13 -> V_15 ) ;
}
F_11 ( V_16 , V_17 , V_18 ) ;
F_11 ( V_16 , V_17 , V_19 ) ;
F_11 ( V_20 , V_21 , V_18 ) ;
F_11 ( V_20 , V_21 , V_19 ) ;
F_11 ( V_22 , V_23 , V_18 ) ;
F_11 ( V_22 , V_24 , V_19 ) ;
F_11 ( V_25 , V_26 , V_18 ) ;
F_11 ( V_25 , V_27 , V_19 ) ;
}
static void T_2 F_12 ( void )
{
#ifdef F_13
struct V_28 * V_29 ;
#endif
if ( V_30 . V_31 )
V_30 . V_31 ( L_2 , 0 ) ;
#ifdef F_14
F_15 () ;
F_8 () ;
#endif
#ifdef F_13
F_16 (np, L_3 , L_4 )
F_17 ( V_29 , 1 ) ;
V_30 . V_32 = F_1 ;
#endif
}
static void F_18 ( struct V_33 * V_34 )
{
T_3 V_35 , V_36 , V_37 ;
V_35 = F_19 ( V_38 ) ;
V_36 = F_19 ( V_39 ) ;
F_20 ( V_34 , L_5 ) ;
F_20 ( V_34 , L_6 , V_35 ) ;
F_20 ( V_34 , L_7 , V_36 ) ;
V_37 = F_19 ( V_40 ) ;
F_20 ( V_34 , L_8 , ( ( V_37 >> 24 ) & 0x3f ) ) ;
}
static int T_2 F_21 ( void )
{
unsigned long V_41 = F_22 () ;
return F_23 ( V_41 , L_9 ) ;
}
