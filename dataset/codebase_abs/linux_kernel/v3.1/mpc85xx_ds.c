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
struct V_11 V_12 ;
struct V_13 * V_14 ;
#ifdef F_6
struct V_13 * V_15 = NULL ;
int V_6 ;
#endif
unsigned long V_16 = F_7 () ;
V_14 = F_8 ( NULL , L_1 ) ;
if ( V_14 == NULL ) {
F_9 ( V_17 L_2 ) ;
return;
}
if ( F_10 ( V_14 , 0 , & V_12 ) ) {
F_9 ( V_17 L_3 ) ;
F_11 ( V_14 ) ;
return;
}
if ( F_12 ( V_16 , L_4 ) ) {
V_10 = F_13 ( V_14 , V_12 . V_18 ,
V_19 |
V_20 | V_21 |
V_22 ,
0 , 256 , L_5 ) ;
} else {
V_10 = F_13 ( V_14 , V_12 . V_18 ,
V_19 | V_23 |
V_20 | V_21 |
V_22 ,
0 , 256 , L_5 ) ;
}
F_14 ( V_10 == NULL ) ;
F_11 ( V_14 ) ;
F_15 ( V_10 ) ;
#ifdef F_6
F_16 (np, L_6 )
if ( F_17 ( V_14 , L_7 ) ) {
V_15 = V_14 ;
break;
}
if ( V_15 == NULL ) {
F_9 ( V_24 L_8 ) ;
return;
}
V_6 = F_18 ( V_15 , 0 ) ;
if ( V_6 == V_7 ) {
F_9 ( V_17 L_9 ) ;
return;
}
F_19 ( L_10 , V_6 ) ;
F_20 ( V_15 , 0 ) ;
F_11 ( V_15 ) ;
F_21 ( V_6 , F_1 ) ;
#endif
}
static int F_22 ( struct V_25 * V_26 ,
T_2 V_27 , T_2 V_28 )
{
struct V_13 * V_29 ;
struct V_11 V_30 ;
V_29 = V_26 -> V_31 ;
F_10 ( V_29 , 0 , & V_30 ) ;
if ( ( V_30 . V_18 & 0xfffff ) == V_32 ) {
return F_23 ( V_26 , V_27 , V_28 ) ;
}
return V_33 ;
}
static void T_1 F_24 ( void )
{
#ifdef F_25
struct V_13 * V_14 ;
struct V_25 * V_26 ;
#endif
T_3 V_34 = 0xffffffff ;
if ( V_35 . V_36 )
V_35 . V_36 ( L_11 , 0 ) ;
#ifdef F_25
F_16 (np, L_12 ) {
if ( F_17 ( V_14 , L_13 ) ||
F_17 ( V_14 , L_14 ) ||
F_17 ( V_14 , L_15 ) ) {
struct V_11 V_30 ;
F_10 ( V_14 , 0 , & V_30 ) ;
if ( ( V_30 . V_18 & 0xfffff ) == V_32 )
F_26 ( V_14 , 1 ) ;
else
F_26 ( V_14 , 0 ) ;
V_26 = F_27 ( V_14 ) ;
V_34 = F_28 ( V_34 , V_26 -> V_37 +
V_26 -> V_38 ) ;
}
}
V_35 . V_39 = F_22 ;
#endif
#ifdef F_29
F_30 () ;
#endif
#ifdef F_31
if ( F_32 () > V_34 ) {
V_40 = 1 ;
F_33 ( & V_41 ) ;
V_35 . V_42 = V_43 ;
}
#endif
F_9 ( L_16 ) ;
}
static int T_1 F_34 ( void )
{
unsigned long V_16 = F_7 () ;
if ( F_12 ( V_16 , L_17 ) ) {
#ifdef F_25
V_32 = 0xb000 ;
#endif
return 1 ;
}
return 0 ;
}
static int T_1 F_35 ( void )
{
return F_36 ( NULL , V_44 , NULL ) ;
}
static int T_1 F_37 ( void )
{
unsigned long V_16 = F_7 () ;
if ( F_12 ( V_16 , L_18 ) ) {
#ifdef F_25
V_32 = 0x8000 ;
#endif
return 1 ;
}
return 0 ;
}
static int T_1 F_38 ( void )
{
unsigned long V_16 = F_7 () ;
if ( F_12 ( V_16 , L_19 ) ) {
#ifdef F_25
V_32 = 0x9000 ;
#endif
return 1 ;
}
return 0 ;
}
