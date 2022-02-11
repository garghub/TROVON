static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= 1 << V_4 ;
V_2 &= ~ ( 1 << V_5 ) ;
F_3 ( V_2 , V_1 + V_3 ) ;
}
static void
F_4 ( void T_1 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
int V_9 = 4 ;
while ( -- V_9 ) {
* V_7 = F_2 ( V_6 + V_10 ) ;
* V_8 = F_2 ( V_6 + V_11 ) ;
if ( * V_7 == F_2 ( V_6 + V_10 ) )
break;
}
if ( ! V_9 ) {
F_5 ( L_1 ) ;
F_5 ( L_2 ) ;
}
return;
}
static int F_6 ( unsigned long V_12 ,
struct V_13 * V_14 )
{
T_2 V_8 , V_7 ;
T_2 V_2 ;
F_4 ( V_15 . V_16 , & V_7 , & V_8 ) ;
F_3 ( V_8 + V_12 , V_15 . V_16 + V_17 ) ;
V_2 = F_2 ( V_15 . V_16 + V_3 ) ;
V_2 |= ( 1 << V_5 ) ;
F_3 ( V_2 , V_15 . V_16 + V_3 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_18 )
{
F_1 ( V_15 . V_16 ) ;
return 0 ;
}
static void T_3 F_8 ( void )
{
V_19 . V_20 = F_9 ( 0 ) ;
F_10 ( & V_19 ,
V_21 , 6 , 0xffffffff ) ;
}
static T_4 F_11 ( int V_22 , void * V_23 )
{
struct V_13 * V_18 = & V_19 ;
F_1 ( V_15 . V_16 ) ;
V_18 -> V_24 ( V_18 ) ;
return V_25 ;
}
static void T_3 F_12 ( struct V_26 * V_27 )
{
T_5 V_28 ;
struct V_29 * V_30 ;
if ( ! F_13 ( V_27 ) ) {
F_14 ( L_3 ) ;
return;
}
V_30 = F_15 ( V_27 , NULL ) ;
if ( ! F_16 ( V_30 ) ) {
V_21 = F_17 ( V_30 ) ;
F_18 ( V_30 ) ;
} else if ( ! F_19 ( V_27 , L_4 , & V_28 ) ) {
V_21 = V_28 ;
} else {
F_5 ( L_5 ) ;
return;
}
V_15 . V_31 = F_20 ( V_27 , 0 ) ;
V_15 . V_16 = F_21 ( V_27 , 0 ) ;
F_1 ( V_15 . V_16 ) ;
F_8 () ;
F_22 ( V_15 . V_31 , & V_32 ) ;
F_6 ( ( V_21 / V_33 ) , NULL ) ;
}
