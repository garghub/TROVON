static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= 1 << V_4 ;
V_2 &= ~ ( 1 << V_5 ) ;
F_3 ( V_2 , V_1 + V_3 ) ;
}
static int
F_4 ( void T_1 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
int V_9 = 3 ;
do {
* V_7 = F_2 ( V_6 + V_10 ) ;
* V_8 = F_2 ( V_6 + V_11 ) ;
if ( * V_7 == F_2 ( V_6 + V_10 ) )
break;
} while ( -- V_9 );
if ( ! V_9 ) {
F_5 ( L_1 ) ;
F_5 ( L_2 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_6 ( unsigned long V_13 ,
struct V_14 * V_15 )
{
T_2 V_8 , V_7 ;
T_2 V_2 ;
int V_16 ;
V_16 = F_4 ( V_17 . V_18 , & V_7 , & V_8 ) ;
if ( V_16 )
return V_16 ;
F_3 ( V_8 + V_13 , V_17 . V_18 + V_19 ) ;
V_2 = F_2 ( V_17 . V_18 + V_3 ) ;
V_2 |= ( 1 << V_5 ) ;
F_3 ( V_2 , V_17 . V_18 + V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_20 )
{
F_1 ( V_17 . V_18 ) ;
return 0 ;
}
static void T_3 F_8 ( void )
{
V_21 . V_22 = F_9 ( 0 ) ;
F_10 ( & V_21 ,
V_23 , 6 , 0xffffffff ) ;
}
static T_4 F_11 ( int V_24 , void * V_25 )
{
struct V_14 * V_20 = & V_21 ;
F_1 ( V_17 . V_18 ) ;
V_20 -> V_26 ( V_20 ) ;
return V_27 ;
}
static int T_3 F_12 ( struct V_28 * V_29 )
{
T_5 V_30 ;
struct V_31 * V_32 ;
V_32 = F_13 ( V_29 , NULL ) ;
if ( ! F_14 ( V_32 ) ) {
V_23 = F_15 ( V_32 ) ;
F_16 ( V_32 ) ;
} else if ( ! F_17 ( V_29 , L_3 , & V_30 ) ) {
V_23 = V_30 ;
} else {
F_5 ( L_4 ) ;
return - V_33 ;
}
V_17 . V_34 = F_18 ( V_29 , 0 ) ;
V_17 . V_18 = F_19 ( V_29 , 0 ) ;
F_1 ( V_17 . V_18 ) ;
F_8 () ;
F_20 ( V_17 . V_34 , & V_35 ) ;
F_6 ( ( V_23 / V_36 ) , NULL ) ;
return 0 ;
}
