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
static void T_3 F_7 ( void )
{
struct V_12 * V_13 ;
T_4 V_14 ;
V_13 = F_8 ( NULL , V_15 ) ;
if ( ! V_13 )
F_9 ( L_3 ) ;
if ( ! F_10 ( V_13 , L_4 , & V_14 ) )
V_16 = V_14 ;
else
F_9 ( L_5 ) ;
V_17 . V_18 = F_11 ( V_13 , 0 ) ;
V_17 . V_19 = F_12 ( V_13 , 0 ) ;
F_1 ( V_17 . V_19 ) ;
}
static int F_13 ( unsigned long V_20 ,
struct V_21 * V_22 )
{
T_2 V_8 , V_7 ;
T_2 V_2 ;
F_4 ( V_17 . V_19 , & V_7 , & V_8 ) ;
F_3 ( V_8 + V_20 , V_17 . V_19 + V_23 ) ;
V_2 = F_2 ( V_17 . V_19 + V_3 ) ;
V_2 |= ( 1 << V_5 ) ;
F_3 ( V_2 , V_17 . V_19 + V_3 ) ;
return 0 ;
}
static void F_14 ( enum V_24 V_25 ,
struct V_21 * V_22 )
{
switch ( V_25 ) {
case V_26 :
break;
case V_27 :
case V_28 :
default:
F_1 ( V_17 . V_19 ) ;
}
}
static void T_3 F_15 ( void )
{
V_29 . V_30 = F_16 ( 0 ) ;
F_17 ( & V_29 ,
V_16 , 6 , 0xffffffff ) ;
}
static T_5 F_18 ( int V_31 , void * V_32 )
{
struct V_21 * V_33 = & V_29 ;
F_1 ( V_17 . V_19 ) ;
V_33 -> V_34 ( V_33 ) ;
return V_35 ;
}
static void T_3 F_19 ( void )
{
F_7 () ;
F_15 () ;
F_20 ( V_17 . V_18 , & V_36 ) ;
F_13 ( ( V_16 / V_37 ) , NULL ) ;
}
