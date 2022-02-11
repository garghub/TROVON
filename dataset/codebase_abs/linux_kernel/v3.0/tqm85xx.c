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
struct V_12 * V_13 ;
#ifdef F_6
int V_1 ;
#endif
V_13 = F_7 ( NULL , L_1 ) ;
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
if ( V_1 == V_19 ) {
F_10 ( V_13 ) ;
F_8 ( V_14 L_7 ) ;
return;
}
F_16 ( V_13 ) ;
F_10 ( V_13 ) ;
F_17 ( V_1 , F_1 ) ;
#endif
}
static void T_1 F_18 ( void )
{
#ifdef F_19
struct V_12 * V_13 ;
#endif
if ( V_20 . V_21 )
V_20 . V_21 ( L_8 , 0 ) ;
#ifdef F_6
F_20 () ;
#endif
#ifdef F_19
F_21 (np, L_9 ) {
if ( F_22 ( V_13 , L_10 ) ||
F_22 ( V_13 , L_11 ) ) {
struct V_10 V_22 ;
if ( ! F_9 ( V_13 , 0 , & V_22 ) ) {
if ( ( V_22 . V_15 & 0xfffff ) == 0x8000 )
F_23 ( V_13 , 1 ) ;
else
F_23 ( V_13 , 0 ) ;
}
}
}
#endif
}
static void F_24 ( struct V_23 * V_24 )
{
T_2 V_25 , V_26 , V_27 ;
V_25 = F_25 ( V_28 ) ;
V_26 = F_25 ( V_29 ) ;
F_26 ( V_24 , L_12 ) ;
F_26 ( V_24 , L_13 , V_25 ) ;
F_26 ( V_24 , L_14 , V_26 ) ;
V_27 = F_25 ( V_30 ) ;
F_26 ( V_24 , L_15 , ( ( V_27 >> 24 ) & 0x3f ) ) ;
}
static void T_1 F_27 ( struct V_31 * V_32 )
{
unsigned int V_33 ;
if ( ! F_28 ( V_34 ) )
return;
F_29 ( & V_32 -> V_35 , L_16 ) ;
F_30 ( V_32 , 0x80 , & V_33 ) ;
F_31 ( V_32 , 0x80 , V_33 | ( 1 << 27 ) ) ;
}
static int T_1 F_32 ( void )
{
F_33 ( NULL , V_36 , NULL ) ;
return 0 ;
}
static int T_1 F_34 ( void )
{
return F_35 ( F_36 () , V_37 ) ;
}
