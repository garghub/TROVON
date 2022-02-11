static inline void F_1 ( T_1 T_2 * V_1 , int V_2 )
{
F_2 ( V_1 , F_3 ( V_1 ) | ( 1 << V_2 ) ) ;
}
static inline void F_4 ( T_1 T_2 * V_1 , int V_2 )
{
F_2 ( V_1 , F_3 ( V_1 ) & ~ ( 1 << V_2 ) ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_4 ( & V_7 -> V_8 , 11 - V_5 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_7 -> V_8 , 11 - V_5 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_7 -> V_8 , 27 - V_5 ) ;
}
static int F_9 ( struct V_3 * V_4 , unsigned int V_9 )
{
T_1 V_10 , type ;
int V_5 = F_6 ( V_4 ) & V_6 ;
void * V_11 = V_12 ;
F_10 ( L_1 , V_13 ,
( int ) F_6 ( V_4 ) , V_5 , V_9 ) ;
switch ( V_9 ) {
case V_14 : type = 0 ; break;
case V_15 : type = 1 ; V_11 = V_16 ; break;
case V_17 : type = 2 ; V_11 = V_16 ; break;
case V_18 : type = 3 ; break;
default:
type = 0 ;
}
V_10 = F_3 ( & V_7 -> V_8 ) ;
V_10 &= ~ ( 0x3 << ( 22 - ( V_5 * 2 ) ) ) ;
V_10 |= ( type << ( 22 - ( V_5 * 2 ) ) ) ;
F_2 ( & V_7 -> V_8 , V_10 ) ;
F_11 ( V_4 , V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , unsigned int V_9 )
{
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_7 -> V_19 , 16 - V_5 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_4 ( & V_7 -> V_19 , 16 - V_5 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_7 -> V_20 , 31 - V_5 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_4 ( & V_7 -> V_20 , 31 - V_5 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_21 -> V_22 , V_5 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_4 ( & V_21 -> V_22 , V_5 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_2 ( & V_21 -> V_23 , 1 << V_5 ) ;
}
static int F_20 ( int V_24 , int V_25 )
{
return ( ( V_24 == 0 ) && ( V_25 == 0 ) ) ||
( ( V_24 == 1 ) && ( V_25 >= 1 ) && ( V_25 <= 3 ) ) ;
}
static int F_21 ( struct V_26 * V_27 , struct V_28 * V_29 ,
const T_1 * V_30 , unsigned int V_31 ,
T_3 * V_32 ,
unsigned int * V_33 )
{
int V_34 ;
int V_35 ;
int V_36 ;
int V_37 ;
if ( V_31 != 3 )
return - 1 ;
V_34 = ( int ) V_30 [ 0 ] ;
V_35 = ( int ) V_30 [ 1 ] ;
V_36 = ( int ) V_30 [ 2 ] & 0x3 ;
V_37 = ( V_34 << V_38 ) &
V_39 ;
V_37 |= V_35 & V_6 ;
* V_32 = V_37 ;
* V_33 = V_40 ;
if ( F_20 ( V_34 , V_35 ) )
* V_33 = V_41 [ V_36 ] ;
F_10 ( L_2 , V_37 , V_34 ,
V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 , unsigned int V_42 ,
T_3 V_43 )
{
int V_44 ;
int V_5 ;
struct V_45 * V_46 ( V_47 ) ;
void * V_48 ;
int type ;
T_1 V_49 ;
V_44 = ( V_43 & V_39 ) >> V_38 ;
V_5 = V_43 & V_6 ;
if ( F_20 ( V_44 , V_5 ) ) {
V_49 = F_3 ( & V_7 -> V_8 ) ;
type = V_41 [ ( V_49 >> ( 22 - V_5 * 2 ) ) & 0x3 ] ;
if ( ( type == V_50 ) ||
( type == V_51 ) )
V_48 = V_16 ;
else
V_48 = V_12 ;
F_23 ( V_42 , & V_52 , V_48 ) ;
F_10 ( L_3 ,
V_13 , V_5 , V_42 , ( int ) V_43 , type ) ;
return 0 ;
}
switch ( V_44 ) {
case V_53 : V_47 = & V_54 ; break;
case V_55 : V_47 = & V_56 ; break;
case V_57 : V_47 = & V_58 ; break;
case V_59 :
F_24 ( L_4 ,
V_13 , V_5 ) ;
F_25 ( V_42 , & V_60 ) ;
return 0 ;
}
F_23 ( V_42 , V_47 , V_12 ) ;
F_10 ( L_5 , V_13 , V_42 , V_44 , V_5 ) ;
return 0 ;
}
void T_4 F_26 ( void )
{
T_1 V_61 ;
struct V_28 * V_62 ;
struct V_28 * V_63 ;
V_62 = F_27 ( NULL , V_64 ) ;
V_7 = F_28 ( V_62 , 0 ) ;
if ( ! V_7 )
F_29 ( __FILE__ L_6
L_7 ) ;
V_63 = F_27 ( NULL , V_65 ) ;
V_21 = F_28 ( V_63 , 0 ) ;
F_30 ( V_63 ) ;
if ( ! V_21 )
F_29 ( __FILE__ L_8
L_7 ) ;
F_10 ( L_9 , V_7 ) ;
F_2 ( & V_21 -> V_23 , 0xffffffff ) ;
F_2 ( & V_21 -> V_22 , 0xffffffff ) ;
F_2 ( & V_7 -> V_20 , 0x7ffffc00 ) ;
F_2 ( & V_7 -> V_19 , 0x00010fff ) ;
V_61 = F_3 ( & V_7 -> V_8 ) ;
V_61 &= 0x00ff0000 ;
V_61 |= 0x0f000000 |
0x00001000 |
0x00000000 |
0x00000001 ;
F_2 ( & V_7 -> V_8 , V_61 ) ;
F_2 ( & V_7 -> V_66 , 0 ) ;
F_2 ( & V_7 -> V_67 , 0 ) ;
F_2 ( & V_7 -> V_68 , 0 ) ;
F_2 ( & V_7 -> V_69 , 0 ) ;
F_2 ( & V_7 -> V_70 , 0 ) ;
V_71 = F_31 ( V_62 ,
V_72 ,
& V_73 , NULL ) ;
if ( ! V_71 )
F_29 ( __FILE__ L_10 ) ;
F_32 ( V_71 ) ;
F_33 ( L_11 ) ;
}
unsigned int F_34 ( void )
{
T_1 V_74 ;
int V_43 ;
V_74 = F_3 ( & V_7 -> V_75 ) ;
if ( V_74 & 0x00000400 ) {
V_43 = ( V_74 >> 8 ) & 0x3 ;
if ( V_43 == 2 )
goto V_76;
V_43 |= ( V_59 << V_38 ) ;
} else if ( V_74 & 0x00200000 ) {
V_43 = ( V_74 >> 16 ) & 0x1f ;
if ( V_43 == 4 )
goto V_76;
V_43 |= ( V_53 << V_38 ) ;
} else if ( V_74 & 0x20000000 ) {
V_76:
V_43 = ( V_74 >> 24 ) & 0x1f ;
if ( V_43 == 0 ) {
V_74 = F_3 ( & V_21 -> V_23 ) ;
V_43 = F_35 ( V_74 ) - 1 ;
V_43 |= ( V_57 << V_38 ) ;
} else {
V_43 |= ( V_55 << V_38 ) ;
}
} else {
return 0 ;
}
return F_36 ( V_71 , V_43 ) ;
}
