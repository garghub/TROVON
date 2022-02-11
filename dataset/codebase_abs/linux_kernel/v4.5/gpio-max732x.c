static int F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = V_3 ? V_2 -> V_8 : V_2 -> V_9 ;
V_7 = F_2 ( V_6 , V_4 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_10 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = V_3 ? V_2 -> V_8 : V_2 -> V_9 ;
V_7 = F_5 ( V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_10 , L_2 ) ;
return V_7 ;
}
* V_4 = ( T_1 ) V_7 ;
return 0 ;
}
static inline int F_6 ( struct V_1 * V_2 , unsigned V_11 )
{
return ( 1u << V_11 ) & V_2 -> V_12 ;
}
static int F_7 ( struct V_13 * V_14 , unsigned V_11 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
T_1 V_15 ;
int V_7 ;
V_7 = F_4 ( V_2 , F_6 ( V_2 , V_11 ) , & V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
return ! ! ( V_15 & ( 1u << ( V_11 & 0x7 ) ) ) ;
}
static void F_9 ( struct V_13 * V_14 , unsigned V_11 , int V_16 ,
int V_4 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
T_1 V_17 ;
int V_7 ;
F_10 ( & V_2 -> V_18 ) ;
V_17 = ( V_11 > 7 ) ? V_2 -> V_17 [ 1 ] : V_2 -> V_17 [ 0 ] ;
V_17 = ( V_17 & ~ V_16 ) | ( V_4 & V_16 ) ;
V_7 = F_1 ( V_2 , F_6 ( V_2 , V_11 ) , V_17 ) ;
if ( V_7 < 0 )
goto V_19;
if ( V_11 > 7 )
V_2 -> V_17 [ 1 ] = V_17 ;
else
V_2 -> V_17 [ 0 ] = V_17 ;
V_19:
F_11 ( & V_2 -> V_18 ) ;
}
static void F_12 ( struct V_13 * V_14 , unsigned V_11 , int V_4 )
{
unsigned V_20 = V_11 & ~ 0x7 ;
T_1 V_16 = 1u << ( V_11 & 0x7 ) ;
F_9 ( V_14 , V_20 , V_16 , V_4 << ( V_11 & 0x7 ) ) ;
}
static void F_13 ( struct V_13 * V_14 ,
unsigned long * V_16 , unsigned long * V_21 )
{
unsigned V_22 = V_16 [ 0 ] & 0xff ;
unsigned V_23 = ( V_16 [ 0 ] >> 8 ) & 0xff ;
if ( V_22 )
F_9 ( V_14 , 0 , V_22 , V_21 [ 0 ] & 0xff ) ;
if ( V_23 )
F_9 ( V_14 , 8 , V_23 , ( V_21 [ 0 ] >> 8 ) & 0xff ) ;
}
static int F_14 ( struct V_13 * V_14 , unsigned V_11 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
unsigned int V_16 = 1u << V_11 ;
if ( ( V_16 & V_2 -> V_24 ) == 0 ) {
F_15 ( & V_2 -> V_6 -> V_10 , L_3 ,
V_2 -> V_6 -> V_25 , V_11 ) ;
return - V_26 ;
}
if ( ( V_16 & V_2 -> V_27 ) )
F_12 ( V_14 , V_11 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 ,
unsigned V_11 , int V_4 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
unsigned int V_16 = 1u << V_11 ;
if ( ( V_16 & V_2 -> V_27 ) == 0 ) {
F_15 ( & V_2 -> V_6 -> V_10 , L_4 ,
V_2 -> V_6 -> V_25 , V_11 ) ;
return - V_26 ;
}
F_12 ( V_14 , V_11 , V_4 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_4 )
{
int V_7 ;
V_4 = F_18 ( V_4 ) ;
V_7 = F_19 ( V_2 -> V_8 , ( char * ) & V_4 , 2 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_2 -> V_8 -> V_10 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 * V_4 )
{
int V_7 ;
V_7 = F_21 ( V_2 -> V_8 , ( char * ) V_4 , 2 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_2 -> V_8 -> V_10 , L_2 ) ;
return V_7 ;
}
* V_4 = F_22 ( * V_4 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_2 V_28 ;
if ( V_2 -> V_29 == V_2 -> V_30 )
return;
V_2 -> V_29 = V_2 -> V_30 ;
if ( V_2 -> V_31 == V_32 )
return;
F_10 ( & V_2 -> V_18 ) ;
switch ( V_2 -> V_31 ) {
case V_33 :
V_28 = ( V_2 -> V_29 << 8 ) | V_2 -> V_17 [ 0 ] ;
F_17 ( V_2 , V_28 ) ;
break;
case V_34 :
V_28 = V_2 -> V_29 | V_2 -> V_17 [ 0 ] ;
F_1 ( V_2 , 1 , ( T_1 ) V_28 ) ;
break;
}
F_11 ( & V_2 -> V_18 ) ;
}
static void F_24 ( struct V_35 * V_36 )
{
struct V_13 * V_14 = F_25 ( V_36 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
V_2 -> V_30 &= ~ ( 1 << V_36 -> V_37 ) ;
}
static void F_26 ( struct V_35 * V_36 )
{
struct V_13 * V_14 = F_25 ( V_36 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
V_2 -> V_30 |= 1 << V_36 -> V_37 ;
}
static void F_27 ( struct V_35 * V_36 )
{
struct V_13 * V_14 = F_25 ( V_36 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
F_10 ( & V_2 -> V_38 ) ;
V_2 -> V_30 = V_2 -> V_29 ;
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_13 * V_14 = F_25 ( V_36 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
T_2 V_39 ;
T_2 V_40 ;
F_23 ( V_2 ) ;
V_39 = V_2 -> V_41 | V_2 -> V_42 ;
while ( V_39 ) {
V_40 = F_29 ( V_39 ) ;
F_14 ( & V_2 -> V_13 , V_40 ) ;
V_39 &= ~ ( 1 << V_40 ) ;
}
F_11 ( & V_2 -> V_38 ) ;
}
static int F_30 ( struct V_35 * V_36 , unsigned int type )
{
struct V_13 * V_14 = F_25 ( V_36 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
T_2 V_11 = V_36 -> V_37 ;
T_2 V_16 = 1 << V_11 ;
if ( ! ( V_16 & V_2 -> V_24 ) ) {
F_15 ( & V_2 -> V_6 -> V_10 , L_3 ,
V_2 -> V_6 -> V_25 , V_11 ) ;
return - V_26 ;
}
if ( ! ( type & V_43 ) ) {
F_3 ( & V_2 -> V_6 -> V_10 , L_5 ,
V_36 -> V_44 , type ) ;
return - V_45 ;
}
if ( type & V_46 )
V_2 -> V_41 |= V_16 ;
else
V_2 -> V_41 &= ~ V_16 ;
if ( type & V_47 )
V_2 -> V_42 |= V_16 ;
else
V_2 -> V_42 &= ~ V_16 ;
return 0 ;
}
static int F_31 ( struct V_35 * V_48 , unsigned int V_49 )
{
struct V_1 * V_2 = F_25 ( V_48 ) ;
F_32 ( V_2 -> V_6 -> V_44 , V_49 ) ;
return 0 ;
}
static T_1 F_33 ( struct V_1 * V_2 )
{
T_1 V_50 ;
T_1 V_51 ;
T_1 V_52 ;
T_1 V_53 ;
T_2 V_54 ;
int V_7 ;
V_7 = F_20 ( V_2 , & V_54 ) ;
if ( V_7 )
return 0 ;
V_52 = V_54 >> 8 ;
V_52 &= V_2 -> V_29 ;
if ( ! V_52 )
return 0 ;
V_50 = V_54 & 0xFF ;
V_50 &= V_2 -> V_29 ;
V_51 = V_50 ^ V_52 ;
V_53 = ( V_51 & V_2 -> V_41 ) |
( V_50 & V_2 -> V_42 ) ;
V_53 &= V_52 ;
return V_53 ;
}
static T_3 F_34 ( int V_44 , void * V_55 )
{
struct V_1 * V_2 = V_55 ;
T_1 V_53 ;
T_1 V_40 ;
V_53 = F_33 ( V_2 ) ;
if ( ! V_53 )
return V_56 ;
do {
V_40 = F_29 ( V_53 ) ;
F_35 ( F_36 ( V_2 -> V_13 . V_57 ,
V_40 ) ) ;
V_53 &= ~ ( 1 << V_40 ) ;
} while ( V_53 );
return V_56 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_58 * V_59 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_60 * V_61 = F_38 ( & V_6 -> V_10 ) ;
int V_62 = V_63 [ V_59 -> V_64 ] >> 32 ;
int V_65 = 0 ;
int V_7 ;
if ( ( ( V_61 && V_61 -> V_65 ) || V_6 -> V_44 )
&& V_62 != V_66 ) {
if ( V_61 )
V_65 = V_61 -> V_65 ;
V_2 -> V_31 = V_62 ;
F_39 ( & V_2 -> V_38 ) ;
V_7 = F_40 ( & V_6 -> V_10 , V_6 -> V_44 ,
NULL , F_34 , V_67 |
V_68 | V_69 ,
F_41 ( & V_6 -> V_10 ) , V_2 ) ;
if ( V_7 ) {
F_3 ( & V_6 -> V_10 , L_6 ,
V_6 -> V_44 ) ;
return V_7 ;
}
V_7 = F_42 ( & V_2 -> V_13 ,
& V_70 ,
V_65 ,
V_71 ,
V_72 ) ;
if ( V_7 ) {
F_3 ( & V_6 -> V_10 ,
L_7 ) ;
return V_7 ;
}
F_43 ( & V_2 -> V_13 ,
& V_70 ,
V_6 -> V_44 ,
NULL ) ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_58 * V_59 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_60 * V_61 = F_38 ( & V_6 -> V_10 ) ;
int V_62 = V_63 [ V_59 -> V_64 ] >> 32 ;
if ( ( ( V_61 && V_61 -> V_65 ) || V_6 -> V_44 ) && V_62 != V_66 )
F_44 ( & V_6 -> V_10 , L_8 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
const struct V_58 * V_59 ,
unsigned V_73 )
{
struct V_13 * V_14 = & V_2 -> V_13 ;
T_4 V_74 = ( T_4 ) V_63 [ V_59 -> V_64 ] ;
int V_75 , V_76 = 0 ;
for ( V_75 = 0 ; V_75 < 16 ; V_75 ++ , V_74 >>= 2 ) {
unsigned int V_16 = 1 << V_76 ;
switch ( V_74 & 0x3 ) {
case V_77 :
V_2 -> V_27 |= V_16 ;
break;
case V_78 :
V_2 -> V_24 |= V_16 ;
break;
case V_79 :
V_2 -> V_27 |= V_16 ;
V_2 -> V_24 |= V_16 ;
break;
default:
continue;
}
if ( V_75 < 8 )
V_2 -> V_12 |= V_16 ;
V_76 ++ ;
}
if ( V_2 -> V_24 )
V_14 -> V_80 = F_14 ;
if ( V_2 -> V_27 ) {
V_14 -> V_81 = F_16 ;
V_14 -> V_82 = F_12 ;
V_14 -> V_83 = F_13 ;
}
V_14 -> V_84 = F_7 ;
V_14 -> V_85 = true ;
V_14 -> V_20 = V_73 ;
V_14 -> V_86 = V_76 ;
V_14 -> V_87 = V_2 -> V_6 -> V_25 ;
V_14 -> V_88 = & V_2 -> V_6 -> V_10 ;
V_14 -> V_89 = V_90 ;
return V_76 ;
}
static struct V_60 * F_46 ( struct V_91 * V_10 )
{
struct V_60 * V_61 ;
V_61 = F_47 ( V_10 , sizeof( * V_61 ) , V_92 ) ;
if ( ! V_61 )
return NULL ;
V_61 -> V_93 = - 1 ;
return V_61 ;
}
static int F_48 ( struct V_5 * V_6 ,
const struct V_58 * V_59 )
{
struct V_60 * V_61 ;
struct V_94 * V_95 ;
struct V_1 * V_2 ;
struct V_5 * V_96 ;
T_2 V_97 , V_98 ;
int V_7 , V_99 ;
V_61 = F_38 ( & V_6 -> V_10 ) ;
V_95 = V_6 -> V_10 . V_100 ;
if ( ! V_61 && V_95 )
V_61 = F_46 ( & V_6 -> V_10 ) ;
if ( ! V_61 ) {
F_15 ( & V_6 -> V_10 , L_9 ) ;
return - V_45 ;
}
V_2 = F_47 ( & V_6 -> V_10 , sizeof( * V_2 ) , V_92 ) ;
if ( V_2 == NULL )
return - V_101 ;
V_2 -> V_6 = V_6 ;
V_99 = F_45 ( V_2 , V_59 , V_61 -> V_93 ) ;
V_2 -> V_13 . V_88 = & V_6 -> V_10 ;
V_97 = ( V_6 -> V_102 & 0x0f ) | 0x60 ;
V_98 = ( V_6 -> V_102 & 0x0f ) | 0x50 ;
switch ( V_6 -> V_102 & 0x70 ) {
case 0x60 :
V_2 -> V_8 = V_6 ;
if ( V_99 > 8 ) {
V_96 = F_49 ( V_6 -> V_103 , V_98 ) ;
V_2 -> V_9 = V_2 -> V_104 = V_96 ;
}
break;
case 0x50 :
V_2 -> V_9 = V_6 ;
if ( V_99 > 8 ) {
V_96 = F_49 ( V_6 -> V_103 , V_97 ) ;
V_2 -> V_8 = V_2 -> V_104 = V_96 ;
}
break;
default:
F_3 ( & V_6 -> V_10 , L_10 ,
V_6 -> V_102 ) ;
V_7 = - V_45 ;
goto V_105;
}
if ( V_99 > 8 && ! V_2 -> V_104 ) {
F_3 ( & V_6 -> V_10 ,
L_11 ) ;
V_7 = - V_106 ;
goto V_105;
}
F_39 ( & V_2 -> V_18 ) ;
V_7 = F_4 ( V_2 , F_6 ( V_2 , 0 ) , & V_2 -> V_17 [ 0 ] ) ;
if ( V_7 )
goto V_105;
if ( V_99 > 8 ) {
V_7 = F_4 ( V_2 , F_6 ( V_2 , 8 ) , & V_2 -> V_17 [ 1 ] ) ;
if ( V_7 )
goto V_105;
}
V_7 = F_50 ( & V_2 -> V_13 , V_2 ) ;
if ( V_7 )
goto V_105;
V_7 = F_37 ( V_2 , V_59 ) ;
if ( V_7 ) {
F_51 ( & V_2 -> V_13 ) ;
goto V_105;
}
if ( V_61 && V_61 -> V_107 ) {
V_7 = V_61 -> V_107 ( V_6 , V_2 -> V_13 . V_20 ,
V_2 -> V_13 . V_86 , V_61 -> V_108 ) ;
if ( V_7 < 0 )
F_44 ( & V_6 -> V_10 , L_12 , V_7 ) ;
}
F_52 ( V_6 , V_2 ) ;
return 0 ;
V_105:
if ( V_2 -> V_104 )
F_53 ( V_2 -> V_104 ) ;
return V_7 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_60 * V_61 = F_38 ( & V_6 -> V_10 ) ;
struct V_1 * V_2 = F_55 ( V_6 ) ;
if ( V_61 && V_61 -> V_109 ) {
int V_7 ;
V_7 = V_61 -> V_109 ( V_6 , V_2 -> V_13 . V_20 ,
V_2 -> V_13 . V_86 , V_61 -> V_108 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_10 , L_13 ,
L_14 , V_7 ) ;
return V_7 ;
}
}
F_51 ( & V_2 -> V_13 ) ;
if ( V_2 -> V_104 )
F_53 ( V_2 -> V_104 ) ;
return 0 ;
}
static int T_5 F_56 ( void )
{
return F_57 ( & V_110 ) ;
}
static void T_6 F_58 ( void )
{
F_59 ( & V_110 ) ;
}
