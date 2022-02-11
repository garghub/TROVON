static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 ,
V_2 | V_3 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
F_5 () ;
}
static void T_1 F_6 ( void )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_7 ( V_5 ) ; V_4 ++ ) {
const struct V_6 * V_7 = & V_5 [ V_4 ] ;
F_8 ( V_7 -> V_8 , V_7 -> V_7 , V_7 -> V_9 ) ;
}
F_9 ( V_10 , V_11 , V_12 ) ;
F_9 ( V_10 , V_11 , V_13 ) ;
F_9 ( V_14 , V_15 , V_12 ) ;
F_9 ( V_14 , V_15 , V_13 ) ;
F_9 ( V_16 , V_17 , V_12 ) ;
F_9 ( V_16 , V_18 , V_13 ) ;
F_9 ( V_19 , V_20 , V_12 ) ;
F_9 ( V_19 , V_21 , V_13 ) ;
}
static void T_1 F_10 ( void )
{
#ifdef F_11
struct V_22 * V_23 ;
#endif
if ( V_24 . V_25 )
V_24 . V_25 ( L_2 , 0 ) ;
#ifdef F_12
F_13 () ;
F_6 () ;
#endif
#ifdef F_11
F_14 (np, L_3 , L_4 )
F_15 ( V_23 , 1 ) ;
#endif
}
static void F_16 ( struct V_26 * V_27 )
{
T_2 V_28 , V_29 , V_30 ;
V_28 = F_17 ( V_31 ) ;
V_29 = F_17 ( V_32 ) ;
F_18 ( V_27 , L_5 ) ;
F_18 ( V_27 , L_6 , V_28 ) ;
F_18 ( V_27 , L_7 , V_29 ) ;
V_30 = F_17 ( V_33 ) ;
F_18 ( V_27 , L_8 , ( ( V_30 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_19 ( void )
{
unsigned long V_34 = F_20 () ;
return F_21 ( V_34 , L_9 ) ;
}
static int T_1 F_22 ( void )
{
struct V_22 * V_23 ;
struct V_35 V_36 ;
struct V_37 * V_38 ;
V_23 = F_23 ( NULL , NULL , L_10 ) ;
if ( V_23 == NULL ) {
F_24 ( L_11 ) ;
return - V_39 ;
}
F_25 ( V_23 , 0 , & V_36 ) ;
F_26 ( V_23 ) ;
F_24 ( L_12 , V_36 . V_40 ) ;
V_38 = F_27 ( L_13 , 0 , & V_36 , 1 ) ;
if ( F_28 ( V_38 ) ) {
F_24 ( L_14 ) ;
return F_29 ( V_38 ) ;
}
return 0 ;
}
static int T_1 F_30 ( void )
{
struct V_22 * V_23 ;
struct V_35 V_36 ;
V_23 = F_23 ( NULL , NULL , L_15 ) ;
if ( V_23 == NULL ) {
F_24 ( V_41 L_16 ) ;
return - V_39 ;
}
F_25 ( V_23 , 0 , & V_36 ) ;
F_24 ( V_42 L_17 , & V_36 ) ;
V_43 = F_31 ( V_36 . V_40 , F_32 ( & V_36 ) ) ;
if( ! V_43 )
F_24 ( V_41 L_18 ) ;
F_26 ( V_23 ) ;
return 0 ;
}
void F_33 ( char * V_44 )
{
F_34 () ;
if( V_43 )
F_35 ( V_43 , 0x80 ) ;
while( 1 ) ;
}
