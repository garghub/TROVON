static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_3 == 0 && F_2 ( V_4 ) == 0 )
return V_5 ;
else
return V_6 ;
}
static void F_3 ( unsigned int V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_9 ) ;
int V_12 ;
while ( ( V_12 = F_5 () ) >= 0 )
F_6 ( V_12 ) ;
V_11 -> V_13 ( & V_9 -> V_14 ) ;
}
static void T_2 F_7 ( void )
{
struct V_15 * V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 = NULL ;
#ifdef F_8
int V_7 ;
#endif
V_19 = F_9 ( V_19 , L_1 ) ;
if ( ! V_19 ) {
F_10 ( V_20 L_2 ) ;
return;
}
if ( F_11 ( V_19 , 0 , & V_17 ) ) {
F_10 ( V_20 L_3 ) ;
F_12 ( V_19 ) ;
return;
}
V_15 = F_13 ( V_19 , V_17 . V_21 ,
V_22 | V_23 | V_24 ,
0 , 256 , L_4 ) ;
F_14 ( V_15 == NULL ) ;
F_12 ( V_19 ) ;
F_15 ( V_15 ) ;
#ifdef F_8
V_19 = F_16 ( NULL , NULL , L_5 ) ;
if ( V_19 == NULL ) {
F_10 ( V_20 L_6 ) ;
return;
}
V_7 = F_17 ( V_19 , 0 ) ;
F_18 ( V_19 ) ;
F_12 ( V_19 ) ;
F_19 ( V_7 , F_3 ) ;
#endif
}
static void T_2 F_20 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_21 ( V_26 ) ; V_25 ++ ) {
const struct V_27 * V_28 = & V_26 [ V_25 ] ;
F_22 ( V_28 -> V_29 , V_28 -> V_28 , V_28 -> V_30 ) ;
}
F_23 ( V_31 , V_32 , V_33 ) ;
F_23 ( V_31 , V_32 , V_34 ) ;
F_23 ( V_35 , V_36 , V_33 ) ;
F_23 ( V_35 , V_36 , V_34 ) ;
F_23 ( V_37 , V_38 , V_33 ) ;
F_23 ( V_37 , V_39 , V_34 ) ;
F_23 ( V_40 , V_41 , V_33 ) ;
F_23 ( V_40 , V_42 , V_34 ) ;
}
static void T_2 F_24 ( void )
{
#ifdef F_25
struct V_18 * V_19 ;
#endif
if ( V_43 . V_44 )
V_43 . V_44 ( L_7 , 0 ) ;
#ifdef F_8
F_26 () ;
F_20 () ;
#endif
#ifdef F_25
F_27 (np, L_8 , L_9 )
F_28 ( V_19 , 1 ) ;
V_43 . V_45 = F_1 ;
#endif
}
static void F_29 ( struct V_46 * V_47 )
{
T_3 V_48 , V_49 , V_50 ;
V_48 = F_30 ( V_51 ) ;
V_49 = F_30 ( V_52 ) ;
F_31 ( V_47 , L_10 ) ;
F_31 ( V_47 , L_11 , V_48 ) ;
F_31 ( V_47 , L_12 , V_49 ) ;
V_50 = F_30 ( V_53 ) ;
F_31 ( V_47 , L_13 , ( ( V_50 >> 24 ) & 0x3f ) ) ;
}
static int T_2 F_32 ( void )
{
F_33 ( NULL , V_54 , NULL ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
unsigned long V_55 = F_35 () ;
return F_36 ( V_55 , L_14 ) ;
}
