static void F_1 ( void T_1 * V_1 )
{
T_2 V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
V_2 |= 1 << V_4 ;
V_2 &= ~ ( 1 << V_5 ) ;
F_3 ( V_2 , V_1 + V_3 ) ;
}
static void
F_4 ( void * V_6 , T_2 * V_7 , T_2 * V_8 )
{
void T_1 * V_1 = F_5 ( V_6 ) ;
int V_9 = 4 ;
while ( -- V_9 ) {
* V_7 = F_2 ( V_1 + V_10 ) ;
* V_8 = F_2 ( V_1 + V_11 ) ;
if ( * V_7 == F_2 ( V_1 + V_10 ) )
break;
}
if ( ! V_9 ) {
F_6 ( L_1 ) ;
F_6 ( L_2 ) ;
}
return;
}
static void T_3 F_7 ( struct V_12 * V_13 )
{
T_4 V_14 ;
if ( ! F_8 ( V_13 , L_3 , & V_14 ) )
V_15 = V_14 ;
else
F_9 ( L_4 ) ;
V_16 . V_17 = F_10 ( V_13 , 0 ) ;
V_16 . V_18 = F_11 ( V_13 , 0 ) ;
F_1 ( V_16 . V_18 ) ;
}
static int F_12 ( unsigned long V_19 ,
struct V_20 * V_21 )
{
T_2 V_8 , V_7 ;
T_2 V_2 ;
F_4 ( V_16 . V_18 , & V_7 , & V_8 ) ;
F_3 ( V_8 + V_19 , V_16 . V_18 + V_22 ) ;
V_2 = F_2 ( V_16 . V_18 + V_3 ) ;
V_2 |= ( 1 << V_5 ) ;
F_3 ( V_2 , V_16 . V_18 + V_3 ) ;
return 0 ;
}
static void F_13 ( enum V_23 V_24 ,
struct V_20 * V_21 )
{
switch ( V_24 ) {
case V_25 :
break;
case V_26 :
case V_27 :
default:
F_1 ( V_16 . V_18 ) ;
}
}
static void T_3 F_14 ( void )
{
V_28 . V_29 = F_15 ( 0 ) ;
F_16 ( & V_28 ,
V_15 , 6 , 0xffffffff ) ;
}
static T_5 F_17 ( int V_30 , void * V_31 )
{
struct V_20 * V_32 = & V_28 ;
F_1 ( V_16 . V_18 ) ;
V_32 -> V_33 ( V_32 ) ;
return V_34 ;
}
static void T_3 F_18 ( struct V_12 * V_13 )
{
F_7 ( V_13 ) ;
F_14 () ;
F_19 ( V_16 . V_17 , & V_35 ) ;
F_12 ( ( V_15 / V_36 ) , NULL ) ;
}
