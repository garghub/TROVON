static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_6 ;
while ( ( V_6 = F_3 () ) >= 0 )
F_4 ( V_6 ) ;
V_5 -> V_7 ( & V_3 -> V_8 ) ;
}
static void T_1 F_5 ( void )
{
struct V_9 * V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 = NULL ;
#ifdef F_6
int V_1 ;
#endif
V_13 = F_7 ( V_13 , L_1 ) ;
if ( ! V_13 ) {
F_8 ( V_14 L_2 ) ;
return;
}
if ( F_9 ( V_13 , 0 , & V_11 ) ) {
F_8 ( V_14 L_3 ) ;
F_10 ( V_13 ) ;
return;
}
V_9 = F_11 ( V_13 , V_11 . V_15 ,
V_16 | V_17 | V_18 ,
0 , 256 , L_4 ) ;
F_12 ( V_9 == NULL ) ;
F_10 ( V_13 ) ;
F_13 ( V_9 ) ;
#ifdef F_6
V_13 = F_14 ( NULL , NULL , L_5 ) ;
if ( V_13 == NULL ) {
F_8 ( V_14 L_6 ) ;
return;
}
V_1 = F_15 ( V_13 , 0 ) ;
F_16 ( V_13 ) ;
F_10 ( V_13 ) ;
F_17 ( V_1 , F_1 ) ;
#endif
}
static void T_1 F_18 ( void )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < F_19 ( V_20 ) ; V_19 ++ ) {
const struct V_21 * V_22 = & V_20 [ V_19 ] ;
F_20 ( V_22 -> V_23 , V_22 -> V_22 , V_22 -> V_24 ) ;
}
F_21 ( V_25 , V_26 , V_27 ) ;
F_21 ( V_25 , V_26 , V_28 ) ;
F_21 ( V_29 , V_30 , V_27 ) ;
F_21 ( V_29 , V_30 , V_28 ) ;
F_21 ( V_31 , V_32 , V_27 ) ;
F_21 ( V_31 , V_33 , V_28 ) ;
F_21 ( V_34 , V_35 , V_27 ) ;
F_21 ( V_34 , V_36 , V_28 ) ;
}
static void T_1 F_22 ( void )
{
#ifdef F_23
struct V_12 * V_13 ;
#endif
if ( V_37 . V_38 )
V_37 . V_38 ( L_7 , 0 ) ;
#ifdef F_6
F_24 () ;
F_18 () ;
#endif
#ifdef F_23
F_25 (np, L_8 , L_9 )
F_26 ( V_13 , 1 ) ;
#endif
}
static void F_27 ( struct V_39 * V_40 )
{
T_2 V_41 , V_42 , V_43 ;
V_41 = F_28 ( V_44 ) ;
V_42 = F_28 ( V_45 ) ;
F_29 ( V_40 , L_10 ) ;
F_29 ( V_40 , L_11 , V_41 ) ;
F_29 ( V_40 , L_12 , V_42 ) ;
V_43 = F_28 ( V_46 ) ;
F_29 ( V_40 , L_13 , ( ( V_43 >> 24 ) & 0x3f ) ) ;
}
static int T_1 F_30 ( void )
{
F_31 ( NULL , V_47 , NULL ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
unsigned long V_48 = F_33 () ;
return F_34 ( V_48 , L_14 ) ;
}
static int T_1 F_35 ( void )
{
struct V_12 * V_13 ;
struct V_10 V_49 ;
struct V_50 * V_51 ;
V_13 = F_14 ( NULL , NULL , L_15 ) ;
if ( V_13 == NULL ) {
F_8 ( L_16 ) ;
return - V_52 ;
}
F_9 ( V_13 , 0 , & V_49 ) ;
F_10 ( V_13 ) ;
F_8 ( L_17 , V_49 . V_15 ) ;
V_51 = F_36 ( L_18 , 0 , & V_49 , 1 ) ;
if ( F_37 ( V_51 ) ) {
F_8 ( L_19 ) ;
return F_38 ( V_51 ) ;
}
return 0 ;
}
static int T_1 F_39 ( void )
{
struct V_12 * V_13 ;
struct V_10 V_49 ;
V_13 = F_14 ( NULL , NULL , L_20 ) ;
if ( V_13 == NULL ) {
F_8 ( V_53 L_21 ) ;
return - V_52 ;
}
F_9 ( V_13 , 0 , & V_49 ) ;
F_8 ( V_54 L_22 , V_49 . V_15 ) ;
V_55 = F_40 ( V_49 . V_15 , V_49 . V_56 - V_49 . V_15 ) ;
if( ! V_55 )
F_8 ( V_53 L_23 ) ;
F_10 ( V_13 ) ;
return 0 ;
}
void F_41 ( char * V_57 )
{
F_42 () ;
if( V_55 )
F_43 ( V_55 , 0x80 ) ;
while( 1 ) ;
}
