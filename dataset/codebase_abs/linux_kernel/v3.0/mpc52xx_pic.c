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
F_11 ( V_4 -> V_19 , V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , unsigned int V_9 )
{
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_7 -> V_20 , 16 - V_5 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_4 ( & V_7 -> V_20 , 16 - V_5 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_7 -> V_21 , 31 - V_5 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_4 ( & V_7 -> V_21 , 31 - V_5 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_1 ( & V_22 -> V_23 , V_5 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_4 ( & V_22 -> V_23 , V_5 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
int V_5 = F_6 ( V_4 ) & V_6 ;
F_2 ( & V_22 -> V_24 , 1 << V_5 ) ;
}
static int F_20 ( int V_25 , int V_26 )
{
return ( ( V_25 == 0 ) && ( V_26 == 0 ) ) ||
( ( V_25 == 1 ) && ( V_26 >= 1 ) && ( V_26 <= 3 ) ) ;
}
static int F_21 ( struct V_27 * V_28 , struct V_29 * V_30 ,
const T_1 * V_31 , unsigned int V_32 ,
T_3 * V_33 ,
unsigned int * V_34 )
{
int V_35 ;
int V_36 ;
int V_37 ;
int V_38 ;
if ( V_32 != 3 )
return - 1 ;
V_35 = ( int ) V_31 [ 0 ] ;
V_36 = ( int ) V_31 [ 1 ] ;
V_37 = ( int ) V_31 [ 2 ] & 0x3 ;
V_38 = ( V_35 << V_39 ) &
V_40 ;
V_38 |= V_36 & V_6 ;
* V_33 = V_38 ;
* V_34 = V_41 ;
if ( F_20 ( V_35 , V_36 ) )
* V_34 = V_42 [ V_37 ] ;
F_10 ( L_2 , V_38 , V_35 ,
V_36 ) ;
return 0 ;
}
static int F_22 ( struct V_27 * V_28 , unsigned int V_43 ,
T_3 V_19 )
{
int V_44 ;
int V_5 ;
struct V_45 * V_46 ;
void * V_47 ;
int type ;
T_1 V_48 ;
V_44 = ( V_19 & V_40 ) >> V_39 ;
V_5 = V_19 & V_6 ;
if ( F_20 ( V_44 , V_5 ) ) {
V_48 = F_3 ( & V_7 -> V_8 ) ;
type = V_42 [ ( V_48 >> ( 22 - V_5 * 2 ) ) & 0x3 ] ;
if ( ( type == V_49 ) ||
( type == V_50 ) )
V_47 = V_16 ;
else
V_47 = V_12 ;
F_23 ( V_43 , & V_51 , V_47 ) ;
F_10 ( L_3 ,
V_13 , V_5 , V_43 , ( int ) V_19 , type ) ;
return 0 ;
}
switch ( V_44 ) {
case V_52 : V_46 = & V_53 ; break;
case V_54 : V_46 = & V_55 ; break;
case V_56 : V_46 = & V_57 ; break;
default:
F_24 ( L_4 ,
V_13 , V_43 , V_44 , V_5 ) ;
return - V_58 ;
}
F_23 ( V_43 , V_46 , V_12 ) ;
F_10 ( L_5 , V_13 , V_43 , V_44 , V_5 ) ;
return 0 ;
}
void T_4 F_25 ( void )
{
T_1 V_59 ;
struct V_29 * V_60 ;
struct V_29 * V_61 ;
V_60 = F_26 ( NULL , V_62 ) ;
V_7 = F_27 ( V_60 , 0 ) ;
if ( ! V_7 )
F_28 ( __FILE__ L_6
L_7 ) ;
V_61 = F_26 ( NULL , V_63 ) ;
V_22 = F_27 ( V_61 , 0 ) ;
F_29 ( V_61 ) ;
if ( ! V_22 )
F_28 ( __FILE__ L_8
L_7 ) ;
F_10 ( L_9 , V_7 ) ;
F_2 ( & V_22 -> V_24 , 0xffffffff ) ;
F_2 ( & V_22 -> V_23 , 0xffffffff ) ;
F_2 ( & V_7 -> V_21 , 0x7ffffc00 ) ;
F_2 ( & V_7 -> V_20 , 0x00010fff ) ;
V_59 = F_3 ( & V_7 -> V_8 ) ;
V_59 &= 0x00ff0000 ;
V_59 |= 0x0f000000 |
0x00001000 |
0x00000000 |
0x00000001 ;
F_2 ( & V_7 -> V_8 , V_59 ) ;
F_2 ( & V_7 -> V_64 , 0 ) ;
F_2 ( & V_7 -> V_65 , 0 ) ;
F_2 ( & V_7 -> V_66 , 0 ) ;
F_2 ( & V_7 -> V_67 , 0 ) ;
F_2 ( & V_7 -> V_68 , 0 ) ;
V_69 = F_30 ( V_60 , V_70 ,
V_71 ,
& V_72 , - 1 ) ;
if ( ! V_69 )
F_28 ( __FILE__ L_10 ) ;
F_31 ( V_69 ) ;
F_32 ( L_11 ) ;
}
unsigned int F_33 ( void )
{
T_1 V_73 ;
int V_19 ;
V_73 = F_3 ( & V_7 -> V_74 ) ;
if ( V_73 & 0x00000400 ) {
V_19 = ( V_73 >> 8 ) & 0x3 ;
if ( V_19 == 2 )
goto V_75;
V_19 |= ( V_76 << V_39 ) ;
} else if ( V_73 & 0x00200000 ) {
V_19 = ( V_73 >> 16 ) & 0x1f ;
if ( V_19 == 4 )
goto V_75;
V_19 |= ( V_52 << V_39 ) ;
} else if ( V_73 & 0x20000000 ) {
V_75:
V_19 = ( V_73 >> 24 ) & 0x1f ;
if ( V_19 == 0 ) {
V_73 = F_3 ( & V_22 -> V_24 ) ;
V_19 = F_34 ( V_73 ) - 1 ;
V_19 |= ( V_56 << V_39 ) ;
} else {
V_19 |= ( V_54 << V_39 ) ;
}
} else {
return V_77 ;
}
return F_35 ( V_69 , V_19 ) ;
}
