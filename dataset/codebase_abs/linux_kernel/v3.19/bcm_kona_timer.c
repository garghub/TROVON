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
static void F_7 ( enum V_18 V_19 ,
struct V_13 * V_14 )
{
switch ( V_19 ) {
case V_20 :
break;
case V_21 :
case V_22 :
default:
F_1 ( V_15 . V_16 ) ;
}
}
static void T_3 F_8 ( void )
{
V_23 . V_24 = F_9 ( 0 ) ;
F_10 ( & V_23 ,
V_25 , 6 , 0xffffffff ) ;
}
static T_4 F_11 ( int V_26 , void * V_27 )
{
struct V_13 * V_28 = & V_23 ;
F_1 ( V_15 . V_16 ) ;
V_28 -> V_29 ( V_28 ) ;
return V_30 ;
}
static void T_3 F_12 ( struct V_31 * V_32 )
{
T_5 V_33 ;
struct V_34 * V_35 ;
if ( ! F_13 ( V_32 ) ) {
F_14 ( L_3 ) ;
return;
}
V_35 = F_15 ( V_32 , NULL ) ;
if ( ! F_16 ( V_35 ) ) {
V_25 = F_17 ( V_35 ) ;
F_18 ( V_35 ) ;
} else if ( ! F_19 ( V_32 , L_4 , & V_33 ) ) {
V_25 = V_33 ;
} else {
F_5 ( L_5 ) ;
return;
}
V_15 . V_36 = F_20 ( V_32 , 0 ) ;
V_15 . V_16 = F_21 ( V_32 , 0 ) ;
F_1 ( V_15 . V_16 ) ;
F_8 () ;
F_22 ( V_15 . V_36 , & V_37 ) ;
F_6 ( ( V_25 / V_38 ) , NULL ) ;
}
