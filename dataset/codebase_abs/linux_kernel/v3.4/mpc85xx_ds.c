static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
unsigned int V_6 = F_3 () ;
if ( V_6 != V_7 ) {
F_4 ( V_6 ) ;
}
V_5 -> V_8 ( & V_3 -> V_9 ) ;
}
void T_1 F_5 ( void )
{
struct V_10 * V_10 ;
#ifdef F_6
struct V_11 * V_12 ;
struct V_11 * V_13 = NULL ;
int V_6 ;
#endif
unsigned long V_14 = F_7 () ;
if ( F_8 ( V_14 , L_1 ) ) {
V_10 = F_9 ( NULL , 0 ,
V_15 |
V_16 |
V_17 ,
0 , 256 , L_2 ) ;
} else {
V_10 = F_9 ( NULL , 0 ,
V_16 |
V_17 ,
0 , 256 , L_2 ) ;
}
F_10 ( V_10 == NULL ) ;
F_11 ( V_10 ) ;
#ifdef F_6
F_12 (np, L_3 )
if ( F_13 ( V_12 , L_4 ) ) {
V_13 = V_12 ;
break;
}
if ( V_13 == NULL ) {
F_14 ( V_18 L_5 ) ;
return;
}
V_6 = F_15 ( V_13 , 0 ) ;
if ( V_6 == V_7 ) {
F_14 ( V_19 L_6 ) ;
return;
}
F_16 ( L_7 , V_6 ) ;
F_17 ( V_13 , 0 ) ;
F_18 ( V_13 ) ;
F_19 ( V_6 , F_1 ) ;
#endif
}
static int F_20 ( struct V_20 * V_21 ,
T_2 V_22 , T_2 V_23 )
{
struct V_11 * V_24 ;
struct V_25 V_26 ;
V_24 = V_21 -> V_27 ;
F_21 ( V_24 , 0 , & V_26 ) ;
if ( ( V_26 . V_28 & 0xfffff ) == V_29 ) {
return F_22 ( V_21 , V_22 , V_23 ) ;
}
return V_30 ;
}
static void T_1 F_23 ( void )
{
#ifdef F_24
struct V_11 * V_12 ;
struct V_20 * V_21 ;
#endif
T_3 V_31 = 0xffffffff ;
if ( V_32 . V_33 )
V_32 . V_33 ( L_8 , 0 ) ;
#ifdef F_24
F_12 (np, L_9 ) {
if ( F_13 ( V_12 , L_10 ) ||
F_13 ( V_12 , L_11 ) ||
F_13 ( V_12 , L_12 ) ) {
struct V_25 V_26 ;
F_21 ( V_12 , 0 , & V_26 ) ;
if ( ( V_26 . V_28 & 0xfffff ) == V_29 )
F_25 ( V_12 , 1 ) ;
else
F_25 ( V_12 , 0 ) ;
V_21 = F_26 ( V_12 ) ;
V_31 = F_27 ( V_31 , V_21 -> V_34 +
V_21 -> V_35 ) ;
}
}
V_32 . V_36 = F_20 ;
#endif
F_28 () ;
#ifdef F_29
if ( F_30 () > V_31 ) {
V_37 = 1 ;
F_31 ( & V_38 ) ;
V_32 . V_39 = V_40 ;
}
#endif
F_14 ( L_13 ) ;
}
static int T_1 F_32 ( void )
{
unsigned long V_14 = F_7 () ;
if ( F_8 ( V_14 , L_14 ) ) {
#ifdef F_24
V_29 = 0xb000 ;
#endif
return 1 ;
}
return 0 ;
}
static int T_1 F_33 ( void )
{
unsigned long V_14 = F_7 () ;
if ( F_8 ( V_14 , L_15 ) ) {
#ifdef F_24
V_29 = 0x8000 ;
#endif
return 1 ;
}
return 0 ;
}
static int T_1 F_34 ( void )
{
unsigned long V_14 = F_7 () ;
if ( F_8 ( V_14 , L_16 ) ) {
#ifdef F_24
V_29 = 0x9000 ;
#endif
return 1 ;
}
return 0 ;
}
