static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
T_1 V_4 ;
V_4 = 0x80000000 | ( ( V_1 > 1 ) ? ( V_1 - 1 ) : 0 ) ;
F_2 ( V_4 , V_5 + V_6 ) ;
return 0 ;
}
static void F_3 ( enum V_7 V_8 ,
struct V_2 * V_3 )
{
T_1 V_4 ;
F_2 ( 0 , V_5 + V_6 ) ;
switch ( V_8 ) {
case V_9 :
V_4 = 0xC0000000 | ( ( 1000000 / V_10 ) - 1 ) ;
F_2 ( V_4 , V_5 + V_6 ) ;
break;
case V_11 :
break;
case V_12 :
case V_13 :
case V_14 :
break;
}
}
static T_2 T_3 F_4 ( void )
{
return F_5 ( V_15 ) ;
}
static T_2 F_6 ( void )
{
T_1 V_16 = F_7 ( V_17 + V_18 ) ;
T_1 V_19 = F_7 ( V_17 + V_20 ) ;
return ( T_2 ) V_19 * V_21 + V_16 ;
}
static void F_8 ( struct V_22 * V_23 )
{
T_2 V_24 ;
V_25 = V_26 ;
V_26 = F_6 () ;
V_24 = V_26 - V_25 ;
F_9 ( & V_27 , V_24 * V_28 ) ;
* V_23 = V_27 ;
}
static unsigned long F_10 ( void )
{
return F_7 ( V_29 + V_15 ) ;
}
static T_4 F_11 ( int V_30 , void * V_31 )
{
struct V_2 * V_3 = (struct V_2 * ) V_31 ;
F_2 ( 1 << 30 , V_5 + V_32 ) ;
V_3 -> V_33 ( V_3 ) ;
return V_34 ;
}
static void T_5 F_12 ( struct V_35 * V_36 )
{
struct V_37 * V_37 ;
unsigned long V_38 ;
int V_39 ;
V_29 = F_13 ( V_36 , 0 ) ;
if ( ! V_29 ) {
F_14 ( L_1 ) ;
F_15 () ;
}
V_40 . V_30 = F_16 ( V_36 , 2 ) ;
if ( V_40 . V_30 <= 0 ) {
F_14 ( L_2 ) ;
F_15 () ;
}
V_37 = F_17 ( V_36 , 0 ) ;
if ( F_18 ( V_37 ) ) {
F_19 ( L_3 ) ;
V_38 = 12000000 ;
} else {
F_20 ( V_37 ) ;
V_38 = F_21 ( V_37 ) ;
}
switch ( V_38 ) {
case 12000000 :
F_2 ( 0x000b , V_41 ) ;
break;
case 13000000 :
F_2 ( 0x000c , V_41 ) ;
break;
case 19200000 :
F_2 ( 0x045f , V_41 ) ;
break;
case 26000000 :
F_2 ( 0x0019 , V_41 ) ;
break;
default:
F_22 ( 1 , L_4 ) ;
}
F_23 ( F_4 , 32 , 1000000 ) ;
if ( F_24 ( V_29 + V_15 ,
L_5 , 1000000 , 300 , 32 , V_42 ) ) {
F_14 ( L_6 ) ;
F_15 () ;
}
V_43 . V_44 =
F_10 ;
V_43 . V_45 = 1000000 ;
F_25 ( & V_43 ) ;
V_39 = F_26 ( V_40 . V_30 , & V_40 ) ;
if ( V_39 ) {
F_14 ( L_7 , V_39 ) ;
F_15 () ;
}
V_46 . V_47 = V_48 ;
V_46 . V_30 = V_40 . V_30 ;
F_27 ( & V_46 , 1000000 ,
0x1 , 0x1fffffff ) ;
}
static void T_5 F_28 ( struct V_35 * V_36 )
{
struct V_37 * V_37 ;
V_17 = F_13 ( V_36 , 0 ) ;
if ( ! V_17 ) {
F_14 ( L_8 ) ;
F_15 () ;
}
V_37 = F_17 ( V_36 , 0 ) ;
if ( F_18 ( V_37 ) )
F_19 ( L_9 ) ;
else
F_20 ( V_37 ) ;
F_29 ( NULL , F_8 ) ;
}
void F_30 ( void )
{
V_49 = F_5 ( V_41 ) ;
}
void F_31 ( void )
{
F_2 ( V_49 , V_41 ) ;
}
