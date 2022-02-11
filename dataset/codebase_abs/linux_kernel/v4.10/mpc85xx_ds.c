static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 () ;
if ( V_5 ) {
F_4 ( V_5 ) ;
}
V_4 -> V_6 ( & V_2 -> V_7 ) ;
}
void T_1 F_5 ( void )
{
struct V_8 * V_8 ;
#ifdef F_6
struct V_9 * V_10 ;
struct V_9 * V_11 = NULL ;
int V_5 ;
#endif
if ( F_7 ( L_1 ) ) {
V_8 = F_8 ( NULL , 0 ,
V_12 |
V_13 |
V_14 ,
0 , 256 , L_2 ) ;
} else {
V_8 = F_8 ( NULL , 0 ,
V_13 |
V_14 ,
0 , 256 , L_2 ) ;
}
F_9 ( V_8 == NULL ) ;
F_10 ( V_8 ) ;
#ifdef F_6
F_11 (np, L_3 )
if ( F_12 ( V_10 , L_4 ) ) {
V_11 = V_10 ;
break;
}
if ( V_11 == NULL ) {
F_13 ( V_15 L_5 ) ;
return;
}
V_5 = F_14 ( V_11 , 0 ) ;
if ( ! V_5 ) {
F_13 ( V_16 L_6 ) ;
return;
}
F_15 ( L_7 , V_5 ) ;
F_16 ( V_11 , 0 ) ;
F_17 ( V_11 ) ;
F_18 ( V_5 , F_1 ) ;
#endif
}
static int F_19 ( struct V_17 * V_18 ,
T_2 V_19 , T_2 V_20 )
{
if ( V_18 -> V_21 == V_22 )
return F_20 ( V_18 , V_19 , V_20 ) ;
return V_23 ;
}
static void T_1 F_21 ( void )
{
#ifdef F_22
struct V_9 * V_24 ;
V_24 = F_23 ( NULL , L_8 ) ;
while ( ( V_22 = F_24 ( V_24 ) ) ) {
F_17 ( V_24 ) ;
V_24 = V_22 ;
if ( V_22 == V_25 ) {
V_26 . V_27 = F_19 ;
break;
}
}
#endif
}
static void T_1 F_25 ( void )
{
if ( V_26 . V_28 )
V_26 . V_28 ( L_9 , 0 ) ;
F_26 () ;
F_27 () ;
F_21 () ;
F_28 () ;
F_13 ( L_10 ) ;
}
static int T_1 F_29 ( void )
{
return ! ! F_7 ( L_11 ) ;
}
static int T_1 F_30 ( void )
{
return ! ! F_7 ( L_12 ) ;
}
static int T_1 F_31 ( void )
{
return ! ! F_7 ( L_13 ) ;
}
