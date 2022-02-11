static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 , V_8 ;
V_7 = ( V_4 -> V_9 . integer . V_9 [ 0 ] & 0x07 ) ;
V_7 = ( V_7 >= 4 ) ? 4 : ( 3 - V_7 ) ;
V_8 = F_3 ( V_6 , V_10 ) & ( ~ 0x1C0 ) ;
F_4 ( V_6 , V_10 , V_8 | ( V_7 << 6 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_3 ( V_6 , V_10 ) & ( 0x1C0 ) ;
V_7 = V_7 >> 6 ;
V_7 = ( V_7 >= 4 ) ? 4 : ( 3 - V_7 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = V_7 ;
return 0 ;
}
static unsigned F_6 ( int V_11 , int V_12 , int V_13 , int V_14 ,
int V_15 , int V_16 , int V_17 , int V_18 )
{
if ( ( V_11 >= V_12 ) && ( V_11 <= V_13 ) &&
( V_15 >= V_16 ) && ( V_15 <= V_17 ) ) {
int V_19 = V_14 - V_11 ;
int V_20 = V_18 - V_15 ;
return abs ( V_19 ) + abs ( V_20 ) ;
}
return V_21 ;
}
static int F_7 ( int V_22 , T_2 V_14 , T_2 V_18 )
{
int V_23 , V_24 ;
int V_25 = - 1 ;
int V_26 = - 1 ;
int V_27 = 0 ;
unsigned V_28 = V_21 ;
int V_12 , V_13 , V_16 , V_17 ;
V_14 *= V_29 ;
V_18 *= V_29 ;
V_12 = V_14 - ( V_14 >> 5 ) ;
V_13 = V_14 + ( V_14 >> 5 ) ;
V_16 = V_18 - ( V_18 >> 5 ) ;
V_17 = V_18 + ( V_18 >> 5 ) ;
for ( V_23 = 0 ; V_23 < F_8 ( V_30 ) ; V_23 ++ ) {
int V_31 = V_22 / V_30 [ V_23 ] ;
int V_32 = V_33 [ V_23 ] ;
for ( V_24 = 0 ; V_24 < F_8 ( V_34 ) ;
V_24 ++ , V_32 >>= 1 ) {
int V_11 ;
int V_15 ;
int V_35 ;
if ( ( V_32 & 1 ) == 0 )
continue;
V_11 = V_31 * V_34 [ V_24 ] ;
V_15 = V_31 * V_36 [ V_24 ] ;
V_35 = F_6 ( V_11 , V_12 , V_13 , V_14 ,
V_15 , V_16 , V_17 , V_18 ) ;
if ( V_28 > V_35 ) {
V_28 = V_35 ;
V_25 = V_23 ;
V_26 = V_24 ;
V_27 = 0 ;
}
V_35 = F_6 ( ( V_11 >> 1 ) , V_12 , V_13 , V_14 ,
( V_15 >> 1 ) , V_16 , V_17 , V_18 ) ;
if ( ( V_35 != V_21 ) && ( V_28 >= V_35 ) ) {
V_28 = V_35 ;
V_25 = V_23 ;
V_26 = V_24 ;
V_27 = 1 ;
}
}
}
return ( V_26 << 2 ) | V_25 | ( V_27 << V_37 ) ;
}
static void F_9 ( struct V_5 * V_6 , int V_22 ,
T_2 * V_38 , T_2 * V_39 )
{
int V_40 = F_3 ( V_6 , V_41 ) ;
int V_42 = ( V_40 >> 2 ) & 0x0f ;
int V_7 = ( V_22 / V_30 [ V_40 & 3 ] ) ;
int V_11 = ( V_7 * V_34 [ V_42 ] ) / V_29 ;
int V_15 = ( V_7 * V_36 [ V_42 ] ) / V_29 ;
if ( V_40 & V_43 ) {
V_11 >>= 1 ;
V_15 >>= 1 ;
}
* V_38 = V_11 ;
* V_39 = V_15 ;
}
static int F_10 ( struct V_5 * V_6 , int V_22 ,
T_2 V_38 , T_2 V_39 )
{
int V_44 = F_7 ( V_22 , V_38 , V_39 ) ;
if ( V_44 < 0 ) {
F_11 ( V_45 L_1 ,
V_46 , V_38 , V_39 ) ;
return - V_47 ;
}
F_4 ( V_6 , V_41 , V_44 ) ;
#ifdef F_12
{
T_2 V_11 , V_15 ;
F_9 ( V_6 , V_22 , & V_11 , & V_15 ) ;
F_11 ( V_48 L_2 ,
V_11 , V_15 , V_44 ) ;
}
#endif
return 0 ;
}
static int F_13 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
T_1 V_55 ;
int V_56 ;
struct V_57 * V_57 = F_14 ( V_6 ) ;
T_2 V_38 = V_57 -> V_58 ;
T_2 V_39 = V_57 -> V_59 ;
T_2 V_60 = F_15 ( V_52 ) ;
if ( V_50 -> V_61 == V_62 ) {
V_57 -> V_59 = V_39 = V_60 ;
if ( ! V_38 )
V_38 = V_60 ;
} else {
V_57 -> V_58 = V_38 = V_60 ;
if ( ! V_39 )
V_39 = V_60 ;
}
V_56 = F_10 ( V_6 , V_57 -> V_22 , V_38 ,
V_39 ) ;
if ( V_56 < 0 )
return V_56 ;
V_55 = F_3 ( V_6 , V_63 ) & ~ ( 0x03 << 2 ) ;
switch ( F_16 ( V_52 ) ) {
case V_64 :
break;
case V_65 :
V_55 |= ( 0x01 << 2 ) ;
break;
case V_66 :
V_55 |= ( 0x02 << 2 ) ;
break;
case V_67 :
V_55 |= ( 0x03 << 2 ) ;
break;
}
F_4 ( V_6 , V_63 , V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
F_4 ( V_6 , V_68 , 0x0001 ) ;
return 0 ;
}
static void F_18 ( struct V_49 * V_50 ,
struct V_53 * V_54 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
struct V_57 * V_57 = F_14 ( V_6 ) ;
if ( ! F_19 ( V_6 ) ) {
F_20 ( 50 ) ;
F_4 ( V_6 , V_68 , 0x0 ) ;
}
if ( V_50 -> V_61 == V_62 )
V_57 -> V_59 = 0 ;
else
V_57 -> V_58 = 0 ;
}
static int F_21 ( struct V_53 * V_54 , int V_69 )
{
struct V_5 * V_6 = V_54 -> V_6 ;
T_1 V_8 ;
V_8 = F_3 ( V_6 , V_70 ) ;
if ( V_69 )
V_8 |= V_71 ;
else
V_8 &= ~ V_71 ;
F_4 ( V_6 , V_70 , V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_53 * V_72 ,
unsigned int V_73 )
{
struct V_5 * V_6 = V_72 -> V_6 ;
T_1 V_55 ;
V_55 = F_3 ( V_6 , V_63 ) & ( ~ 0x03 ) ;
switch ( V_73 & V_74 ) {
case V_75 :
V_55 |= V_76 ;
break;
case V_77 :
V_55 &= ~ V_76 ;
break;
default:
return - V_47 ;
}
switch ( V_73 & V_78 ) {
case V_79 :
V_55 |= V_80 ;
break;
case V_81 :
V_55 |= V_82 ;
case V_83 :
V_55 |= V_84 ;
break;
case V_85 :
break;
case V_86 :
V_55 |= V_87 ;
break;
default:
return - V_47 ;
}
F_4 ( V_6 , V_63 , V_55 ) ;
return 0 ;
}
static int F_23 ( struct V_53 * V_72 ,
int V_88 , unsigned int V_89 , int V_90 )
{
struct V_57 * V_57 = F_24 ( V_72 ) ;
V_57 -> V_22 = V_89 ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
enum V_91 V_92 )
{
T_1 V_8 = F_3 ( V_6 , V_93 ) & 0x17f ;
switch ( V_92 ) {
case V_94 :
V_8 &= ~ ( V_95 | V_96 | \
V_97 ) ;
F_4 ( V_6 , V_93 , V_8 ) ;
break;
case V_98 :
break;
case V_99 :
F_4 ( V_6 , V_93 ,
V_8 | V_100 ) ;
break;
case V_101 :
F_4 ( V_6 , V_68 , 0x0 ) ;
F_4 ( V_6 , V_93 , 0x1ff ) ;
break;
}
V_6 -> V_102 . V_103 = V_92 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_25 ( V_6 , V_101 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
struct V_57 * V_57 = F_14 ( V_6 ) ;
F_28 ( V_57 -> V_104 ) ;
F_29 ( V_57 -> V_104 ) ;
F_25 ( V_6 , V_99 ) ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
F_4 ( V_6 , V_105 , 0 ) ;
F_25 ( V_6 , V_99 ) ;
F_4 ( V_6 , V_70 , V_106 ) ;
F_31 ( V_6 , V_107 ,
V_108 , V_109 ) ;
F_31 ( V_6 , V_110 ,
V_108 , V_109 ) ;
F_31 ( V_6 , V_10 ,
V_111 | V_112 ,
0 ) ;
F_4 ( V_6 , V_113 ,
V_114 & V_115 ) ;
F_4 ( V_6 , V_116 ,
V_114 & V_115 ) ;
F_4 ( V_6 , V_68 , 0x1 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 )
{
F_25 ( V_6 , V_101 ) ;
return 0 ;
}
int F_33 ( struct V_117 * V_118 , struct V_104 * V_104 )
{
struct V_57 * V_57 ;
if ( F_34 ( V_104 ) )
return F_35 ( V_104 ) ;
V_57 = F_36 ( V_118 , sizeof( struct V_57 ) , V_119 ) ;
if ( V_57 == NULL )
return - V_120 ;
V_57 -> V_104 = V_104 ;
F_37 ( V_118 , V_57 ) ;
return F_38 ( V_118 , & V_121 ,
& V_122 , 1 ) ;
}
