static void T_1 F_1 ( void )
{
struct V_1 * V_1 = F_2 ( NULL , 0 , V_2 ,
0 , 256 , L_1 ) ;
F_3 ( V_1 == NULL ) ;
F_4 ( V_1 ) ;
F_5 () ;
}
static void T_1 F_6 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_7 ( V_4 ) ; V_3 ++ ) {
const struct V_5 * V_6 = & V_4 [ V_3 ] ;
F_8 ( V_6 -> V_7 , V_6 -> V_6 , V_6 -> V_8 ) ;
}
F_9 ( V_9 , V_10 , V_11 ) ;
F_9 ( V_9 , V_10 , V_12 ) ;
F_9 ( V_13 , V_14 , V_11 ) ;
F_9 ( V_13 , V_14 , V_12 ) ;
F_9 ( V_15 , V_16 , V_11 ) ;
F_9 ( V_15 , V_17 , V_12 ) ;
F_9 ( V_18 , V_19 , V_11 ) ;
F_9 ( V_18 , V_20 , V_12 ) ;
}
static void T_1 F_10 ( void )
{
#ifdef F_11
struct V_21 * V_22 ;
#endif
if ( V_23 . V_24 )
V_23 . V_24 ( L_2 , 0 ) ;
#ifdef F_12
F_13 () ;
F_6 () ;
#endif
#ifdef F_11
F_14 (np, L_3 , L_4 )
F_15 ( V_22 , 1 ) ;
#endif
}
static void F_16 ( struct V_25 * V_26 )
{
T_2 V_27 , V_28 , V_29 ;
V_27 = F_17 ( V_30 ) ;
V_28 = F_17 ( V_31 ) ;
F_18 ( V_26 , L_5 ) ;
F_18 ( V_26 , L_6 , V_27 ) ;
F_18 ( V_26 , L_7 , V_28 ) ;
V_29 = F_17 ( V_32 ) ;
F_18 ( V_26 , L_8 , ( ( V_29 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_19 ( void )
{
unsigned long V_33 = F_20 () ;
return F_21 ( V_33 , L_9 ) ;
}
static int T_1 F_22 ( void )
{
struct V_21 * V_22 ;
struct V_34 V_35 ;
struct V_36 * V_37 ;
V_22 = F_23 ( NULL , NULL , L_10 ) ;
if ( V_22 == NULL ) {
F_24 ( L_11 ) ;
return - V_38 ;
}
F_25 ( V_22 , 0 , & V_35 ) ;
F_26 ( V_22 ) ;
F_24 ( L_12 , V_35 . V_39 ) ;
V_37 = F_27 ( L_13 , 0 , & V_35 , 1 ) ;
if ( F_28 ( V_37 ) ) {
F_24 ( L_14 ) ;
return F_29 ( V_37 ) ;
}
return 0 ;
}
static int T_1 F_30 ( void )
{
struct V_21 * V_22 ;
struct V_34 V_35 ;
V_22 = F_23 ( NULL , NULL , L_15 ) ;
if ( V_22 == NULL ) {
F_24 ( V_40 L_16 ) ;
return - V_38 ;
}
F_25 ( V_22 , 0 , & V_35 ) ;
F_24 ( V_41 L_17 , & V_35 ) ;
V_42 = F_31 ( V_35 . V_39 , F_32 ( & V_35 ) ) ;
if( ! V_42 )
F_24 ( V_40 L_18 ) ;
F_26 ( V_22 ) ;
return 0 ;
}
void F_33 ( char * V_43 )
{
F_34 () ;
if( V_42 )
F_35 ( V_42 , 0x80 ) ;
while( 1 ) ;
}
