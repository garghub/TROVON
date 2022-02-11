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
if ( V_21 -> V_24 == V_25 )
return F_21 ( V_21 , V_22 , V_23 ) ;
return V_26 ;
}
static void T_1 F_22 ( void )
{
#ifdef F_23
struct V_11 * V_27 ;
V_27 = F_24 ( NULL , L_8 ) ;
while ( ( V_25 = F_25 ( V_27 ) ) ) {
F_18 ( V_27 ) ;
V_27 = V_25 ;
if ( V_25 == V_28 ) {
V_29 . V_30 = F_20 ;
break;
}
}
#endif
}
static void T_1 F_26 ( void )
{
if ( V_29 . V_31 )
V_29 . V_31 ( L_9 , 0 ) ;
F_27 () ;
F_28 () ;
F_22 () ;
F_29 () ;
F_14 ( L_10 ) ;
}
static int T_1 F_30 ( void )
{
unsigned long V_14 = F_7 () ;
return ! ! F_8 ( V_14 , L_11 ) ;
}
static int T_1 F_31 ( void )
{
unsigned long V_14 = F_7 () ;
return ! ! F_8 ( V_14 , L_12 ) ;
}
static int T_1 F_32 ( void )
{
unsigned long V_14 = F_7 () ;
return ! ! F_8 ( V_14 , L_13 ) ;
}
