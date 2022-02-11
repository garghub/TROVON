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
unsigned long V_13 = F_7 () ;
if ( F_8 ( V_13 , L_1 ) ) {
V_9 = F_9 ( NULL , 0 ,
V_14 |
V_15 |
V_16 ,
0 , 256 , L_2 ) ;
} else {
V_9 = F_9 ( NULL , 0 ,
V_15 |
V_16 ,
0 , 256 , L_2 ) ;
}
F_10 ( V_9 == NULL ) ;
F_11 ( V_9 ) ;
#ifdef F_6
F_12 (np, L_3 )
if ( F_13 ( V_11 , L_4 ) ) {
V_12 = V_11 ;
break;
}
if ( V_12 == NULL ) {
F_14 ( V_17 L_5 ) ;
return;
}
V_5 = F_15 ( V_12 , 0 ) ;
if ( V_5 == V_6 ) {
F_14 ( V_18 L_6 ) ;
return;
}
F_16 ( L_7 , V_5 ) ;
F_17 ( V_12 , 0 ) ;
F_18 ( V_12 ) ;
F_19 ( V_5 , F_1 ) ;
#endif
}
static int F_20 ( struct V_19 * V_20 ,
T_2 V_21 , T_2 V_22 )
{
if ( V_20 -> V_23 == V_24 )
return F_21 ( V_20 , V_21 , V_22 ) ;
return V_25 ;
}
static void T_1 F_22 ( void )
{
#ifdef F_23
struct V_10 * V_26 ;
V_26 = F_24 ( NULL , L_8 ) ;
while ( ( V_24 = F_25 ( V_26 ) ) ) {
F_18 ( V_26 ) ;
V_26 = V_24 ;
if ( V_24 == V_27 ) {
V_28 . V_29 = F_20 ;
break;
}
}
#endif
}
static void T_1 F_26 ( void )
{
if ( V_28 . V_30 )
V_28 . V_30 ( L_9 , 0 ) ;
F_27 () ;
F_28 () ;
F_22 () ;
F_29 () ;
F_14 ( L_10 ) ;
}
static int T_1 F_30 ( void )
{
unsigned long V_13 = F_7 () ;
return ! ! F_8 ( V_13 , L_11 ) ;
}
static int T_1 F_31 ( void )
{
unsigned long V_13 = F_7 () ;
return ! ! F_8 ( V_13 , L_12 ) ;
}
static int T_1 F_32 ( void )
{
unsigned long V_13 = F_7 () ;
return ! ! F_8 ( V_13 , L_13 ) ;
}
