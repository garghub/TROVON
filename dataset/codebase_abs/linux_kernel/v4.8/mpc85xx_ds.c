static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_5 = F_3 () ;
if ( V_5 != V_6 ) {
F_4 ( V_5 ) ;
}
V_4 -> V_7 ( & V_2 -> V_8 ) ;
}
void T_1 F_5 ( void )
{
struct V_9 * V_9 ;
#ifdef F_6
struct V_10 * V_11 ;
struct V_10 * V_12 = NULL ;
int V_5 ;
#endif
if ( F_7 ( L_1 ) ) {
V_9 = F_8 ( NULL , 0 ,
V_13 |
V_14 |
V_15 ,
0 , 256 , L_2 ) ;
} else {
V_9 = F_8 ( NULL , 0 ,
V_14 |
V_15 ,
0 , 256 , L_2 ) ;
}
F_9 ( V_9 == NULL ) ;
F_10 ( V_9 ) ;
#ifdef F_6
F_11 (np, L_3 )
if ( F_12 ( V_11 , L_4 ) ) {
V_12 = V_11 ;
break;
}
if ( V_12 == NULL ) {
F_13 ( V_16 L_5 ) ;
return;
}
V_5 = F_14 ( V_12 , 0 ) ;
if ( V_5 == V_6 ) {
F_13 ( V_17 L_6 ) ;
return;
}
F_15 ( L_7 , V_5 ) ;
F_16 ( V_12 , 0 ) ;
F_17 ( V_12 ) ;
F_18 ( V_5 , F_1 ) ;
#endif
}
static int F_19 ( struct V_18 * V_19 ,
T_2 V_20 , T_2 V_21 )
{
if ( V_19 -> V_22 == V_23 )
return F_20 ( V_19 , V_20 , V_21 ) ;
return V_24 ;
}
static void T_1 F_21 ( void )
{
#ifdef F_22
struct V_10 * V_25 ;
V_25 = F_23 ( NULL , L_8 ) ;
while ( ( V_23 = F_24 ( V_25 ) ) ) {
F_17 ( V_25 ) ;
V_25 = V_23 ;
if ( V_23 == V_26 ) {
V_27 . V_28 = F_19 ;
break;
}
}
#endif
}
static void T_1 F_25 ( void )
{
if ( V_27 . V_29 )
V_27 . V_29 ( L_9 , 0 ) ;
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
