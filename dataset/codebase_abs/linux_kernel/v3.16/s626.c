static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 = ( V_3 << 16 ) | V_3 ;
F_2 () ;
F_3 ( V_8 , V_6 -> V_9 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_3 << 16 , V_6 -> V_9 + V_4 ) ;
F_2 () ;
}
static bool F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
V_8 = F_6 ( V_6 -> V_9 + V_4 ) ;
return ( V_8 & V_3 ) ? true : false ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
static const int V_10 = 10000 ;
int V_11 ;
F_1 ( V_2 , V_12 , V_13 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
if ( F_5 ( V_2 , V_12 , V_13 ) )
break;
F_8 ( 1 ) ;
}
if ( V_11 == V_10 )
F_9 ( V_2 ,
L_1 ) ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ ) {
if ( ! ( F_6 ( V_6 -> V_9 + V_14 ) & V_15 ) )
break;
F_8 ( 1 ) ;
}
if ( V_11 == V_10 )
F_9 ( V_2 , L_2 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_17 | V_16 , V_6 -> V_9 + V_18 ) ;
F_7 ( V_2 ) ;
return F_6 ( V_6 -> V_9 + V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_16 ,
T_1 V_20 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_21 | V_16 , V_6 -> V_9 + V_18 ) ;
F_3 ( V_20 , V_6 -> V_9 + V_19 ) ;
F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_16 ,
unsigned int V_22 , unsigned int V_20 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
V_16 &= 0xffff ;
F_3 ( V_17 | V_16 , V_6 -> V_9 + V_18 ) ;
F_7 ( V_2 ) ;
F_3 ( V_21 | V_16 , V_6 -> V_9 + V_18 ) ;
V_8 = F_6 ( V_6 -> V_9 + V_19 ) ;
V_8 &= V_22 ;
V_8 |= V_20 ;
F_3 ( V_8 & 0xffff , V_6 -> V_9 + V_19 ) ;
F_7 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned long V_27 )
{
bool V_28 ;
V_28 = F_5 ( V_2 , V_29 , V_13 ) ;
if ( V_28 )
return 0 ;
return - V_30 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_31 ;
int V_32 ;
F_3 ( V_8 , V_6 -> V_9 + V_33 ) ;
F_1 ( V_2 , V_29 , V_13 ) ;
V_32 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_32 )
return V_32 ;
do {
V_31 = F_6 ( V_6 -> V_9 + V_33 ) ;
} while ( ( V_31 & ( V_34 | V_35 ) ) == V_34 );
return V_31 & V_35 ;
}
static T_3 F_16 ( struct V_1 * V_2 , T_3 V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_14 ( V_2 , F_17 ( V_36 ,
V_6 -> V_37 ) |
F_18 ( V_38 , V_16 ) |
F_19 ( V_39 , 0 ) ) )
return 0 ;
if ( F_14 ( V_2 , F_17 ( V_36 ,
( V_6 -> V_37 | 1 ) ) |
F_18 ( V_38 , 0 ) |
F_19 ( V_39 , 0 ) ) )
return 0 ;
return ( F_6 ( V_6 -> V_9 + V_33 ) >> 16 ) & 0xff ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned long V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_28 ;
switch ( V_27 ) {
case V_40 :
V_28 = F_6 ( V_6 -> V_9 + V_41 ) ;
if ( ! ( V_28 & V_42 ) )
return 0 ;
break;
case V_43 :
V_28 = F_6 ( V_6 -> V_9 + V_44 ) ;
if ( V_28 & V_45 )
return 0 ;
break;
case V_46 :
V_28 = F_6 ( V_6 -> V_9 + V_47 ) ;
if ( ! ( V_28 & 0xff000000 ) )
return 0 ;
break;
case V_48 :
V_28 = F_6 ( V_6 -> V_9 + V_47 ) ;
if ( V_28 & 0xff000000 )
return 0 ;
break;
default:
return - V_49 ;
}
return - V_30 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_32 ;
F_11 ( V_2 , V_50 , V_6 -> V_51 ) ;
* V_6 -> V_52 = V_8 ;
F_1 ( V_2 , V_42 , V_41 ) ;
F_3 ( V_53 , V_6 -> V_9 + V_54 ) ;
V_32 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_40 ) ;
if ( V_32 ) {
F_9 ( V_2 , L_3 ) ;
return V_32 ;
}
F_3 ( V_55 | V_56 | V_57 ,
V_6 -> V_9 + F_22 ( 0 ) ) ;
V_32 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_43 ) ;
if ( V_32 ) {
F_9 ( V_2 , L_4 ) ;
return V_32 ;
}
F_3 ( V_55 | V_58 | V_59 | V_57 | V_60 ,
V_6 -> V_9 + F_22 ( 0 ) ) ;
if ( F_6 ( V_6 -> V_9 + V_47 ) & 0xff000000 ) {
V_32 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_46 ) ;
if ( V_32 ) {
F_9 ( V_2 ,
L_5 ) ;
return V_32 ;
}
}
F_3 ( V_56 | V_57 | V_60 ,
V_6 -> V_9 + F_22 ( 0 ) ) ;
V_32 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_48 ) ;
if ( V_32 ) {
F_9 ( V_2 , L_5 ) ;
return V_32 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_61 ,
T_4 V_62 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_63 ;
T_2 V_64 ;
T_2 V_8 ;
V_63 = 1 << V_61 ;
if ( V_62 < 0 ) {
V_62 = - V_62 ;
V_6 -> V_51 |= V_63 ;
} else {
V_6 -> V_51 &= ~ V_63 ;
}
if ( ( T_1 ) V_62 > 0x1FFF )
V_62 = 0x1FFF ;
V_64 = ( V_61 & 2 ) ? V_65 : V_66 ;
F_3 ( V_55 | V_67 | V_64 ,
V_6 -> V_9 + F_22 ( 2 ) ) ;
F_3 ( V_55 | V_68 | V_64 ,
V_6 -> V_9 + F_22 ( 3 ) ) ;
F_3 ( V_55 | V_69 | V_70 ,
V_6 -> V_9 + F_22 ( 4 ) ) ;
F_3 ( V_55 | V_58 | V_70 | V_60 ,
V_6 -> V_9 + F_22 ( 5 ) ) ;
V_8 = 0x0F000000 ;
V_8 |= 0x00004000 ;
V_8 |= ( ( T_2 ) ( V_61 & 1 ) << 15 ) ;
V_8 |= ( T_2 ) V_62 ;
return F_21 ( V_2 , V_8 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_3 V_71 ,
T_3 V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_61 ;
V_6 -> V_73 [ V_71 ] = ( T_3 ) V_72 ;
V_61 = V_74 [ V_71 ] ;
F_3 ( V_55 | V_67 | V_70 ,
V_6 -> V_9 + F_22 ( 2 ) ) ;
F_3 ( V_55 | V_68 | V_70 ,
V_6 -> V_9 + F_22 ( 3 ) ) ;
F_3 ( V_55 | V_69 | V_65 ,
V_6 -> V_9 + F_22 ( 4 ) ) ;
F_3 ( V_55 | V_58 | V_65 | V_60 ,
V_6 -> V_9 + F_22 ( 5 ) ) ;
return F_21 ( V_2 , ( V_61 << 8 ) | V_72 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_3 V_11 ;
int V_32 ;
for ( V_11 = 0 ; V_11 < F_26 ( V_74 ) ; V_11 ++ ) {
V_32 = F_24 ( V_2 , V_11 ,
F_16 ( V_2 , V_75 [ V_11 ] ) ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static T_2 F_27 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
T_2 V_78 ;
V_78 = F_10 ( V_2 , V_77 -> V_79 ) ;
V_78 |= ( ( T_2 ) F_10 ( V_2 , V_77 -> V_79 + 2 ) << 16 ) ;
return V_78 ;
}
static void F_28 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_78 )
{
F_12 ( V_2 , V_77 -> V_80 ,
~ ( V_81 | V_82 ) ,
F_29 ( V_78 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_2 V_78 )
{
F_11 ( V_2 , V_77 -> V_79 , V_78 ) ;
F_11 ( V_2 , V_77 -> V_79 + 2 , V_78 >> 16 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
F_12 ( V_2 , V_77 -> V_80 , ~ V_81 ,
( F_32 ( 1 ) |
F_33 ( 1 ) ) ) ;
}
static void F_34 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
F_12 ( V_2 , V_77 -> V_80 , ~ V_81 ,
( F_32 ( 1 ) |
F_35 ( 1 ) ) ) ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
T_1 V_83 ;
T_1 V_84 ;
T_1 V_85 ;
unsigned V_86 , V_87 , V_88 , V_89 ;
V_83 = F_10 ( V_2 , V_77 -> V_90 ) ;
V_84 = F_10 ( V_2 , V_77 -> V_80 ) ;
V_85 =
F_37 ( F_38 ( V_83 ) ) |
F_39 ( F_40 ( V_84 ) ) |
F_41 ( F_42 ( V_83 ) ) |
F_43 ( F_44 ( V_83 ) ) |
F_45 ( F_46 ( V_83 ) ) |
F_47 ( F_48 ( V_84 ) ) ;
V_86 = F_49 ( V_83 ) ;
if ( V_86 & V_91 ) {
V_89 = V_92 ;
V_88 = V_86 & 1 ;
V_87 = V_93 ;
} else {
V_89 = V_94 ;
V_88 = F_50 ( V_83 ) ;
V_87 = F_51 ( V_83 ) ;
if ( V_87 == V_95 )
V_87 = V_93 ;
}
V_85 |= F_52 ( V_89 ) | F_53 ( V_87 ) |
F_54 ( V_88 ) ;
return V_85 ;
}
static T_1 F_55 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
T_1 V_83 ;
T_1 V_84 ;
T_1 V_85 ;
unsigned V_86 , V_87 , V_88 , V_89 ;
V_83 = F_10 ( V_2 , V_77 -> V_90 ) ;
V_84 = F_10 ( V_2 , V_77 -> V_80 ) ;
V_85 =
F_41 ( F_56 ( V_84 ) ) |
F_39 ( F_40 ( V_84 ) ) |
F_37 ( F_57 ( V_84 ) ) |
F_45 ( F_58 ( V_84 ) ) |
F_47 ( F_59 ( V_84 ) ) |
F_43 ( F_60 ( V_83 ) ) ;
V_86 = F_61 ( V_83 ) ;
V_87 = F_62 ( V_84 ) ;
if ( V_87 == V_95 ) {
V_89 = V_96 ;
V_87 = V_93 ;
V_88 = V_86 & 1 ;
} else if ( V_86 & V_91 ) {
V_89 = V_92 ;
V_87 = V_93 ;
V_88 = V_86 & 1 ;
} else {
V_89 = V_94 ;
V_88 = F_63 ( V_84 ) ;
}
V_85 |= F_52 ( V_89 ) | F_53 ( V_87 ) |
F_54 ( V_88 ) ;
return V_85 ;
}
static void F_64 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_85 ,
T_1 V_97 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_83 ;
T_1 V_84 ;
unsigned V_86 , V_87 , V_88 ;
V_83 = F_65 ( F_66 ( V_85 ) ) ;
V_83 |= F_67 ( F_68 ( V_85 ) ) ;
V_84 = F_32 ( 1 ) | F_33 ( 1 ) ;
V_84 |= F_69 ( F_70 ( V_85 ) ) ;
if ( ! V_97 )
V_83 |= F_71 ( F_72 ( V_85 ) ) ;
V_88 = F_73 ( V_85 ) ;
switch ( F_74 ( V_85 ) ) {
case V_96 :
case V_92 :
V_86 = V_91 ;
V_86 |= V_88 ;
V_88 = 1 ;
V_87 = V_93 ;
break;
default:
V_86 = V_98 ;
V_87 = F_75 ( V_85 ) ;
if ( V_87 == V_95 )
V_87 = V_93 ;
break;
}
V_83 |= F_76 ( V_86 ) | F_77 ( V_88 ) |
F_78 ( V_87 ) ;
if ( F_68 ( V_85 ) != V_99 )
V_83 |= F_79 ( F_80 ( V_85 ) ) ;
if ( V_97 )
V_6 -> V_100 &= ~ V_77 -> V_101 [ 3 ] ;
F_12 ( V_2 , V_77 -> V_90 ,
V_102 | V_103 , V_83 ) ;
F_12 ( V_2 , V_77 -> V_80 ,
~ ( V_81 | V_104 ) , V_84 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_85 ,
T_1 V_97 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_83 ;
T_1 V_84 ;
unsigned V_86 , V_87 , V_88 ;
V_83 = F_82 ( F_68 ( V_85 ) ) ;
V_84 = F_32 ( 1 ) | F_35 ( 1 ) ;
V_84 |= F_83 ( F_70 ( V_85 ) ) ;
V_84 |= F_84 ( F_66 ( V_85 ) ) ;
if ( ! V_97 )
V_84 |= F_85 ( F_72 ( V_85 ) ) ;
V_88 = F_73 ( V_85 ) ;
switch ( F_74 ( V_85 ) ) {
case V_92 :
V_86 = V_91 ;
V_86 |= V_88 ;
V_88 = 1 ;
V_87 = V_93 ;
break;
case V_96 :
V_86 = V_91 ;
V_86 |= V_88 ;
V_88 = 1 ;
V_87 = V_95 ;
break;
default:
V_86 = V_98 ;
V_87 = F_75 ( V_85 ) ;
if ( V_87 == V_95 )
V_87 = V_93 ;
break;
}
V_83 |= F_86 ( V_86 ) ;
V_84 |= F_87 ( V_88 ) | F_88 ( V_87 ) ;
if ( F_68 ( V_85 ) != V_99 )
V_84 |= F_89 ( F_80 ( V_85 ) ) ;
if ( V_97 )
V_6 -> V_100 &= ~ V_77 -> V_101 [ 3 ] ;
F_12 ( V_2 , V_77 -> V_90 ,
~ ( V_102 | V_103 ) , V_83 ) ;
F_12 ( V_2 , V_77 -> V_80 ,
V_104 | V_82 , V_84 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_105 )
{
F_12 ( V_2 , V_77 -> V_80 ,
~ ( V_81 | V_104 ) ,
F_69 ( V_105 ) ) ;
}
static void F_91 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_105 )
{
F_12 ( V_2 , V_77 -> V_80 ,
~ ( V_81 | V_106 ) ,
F_83 ( V_105 ) ) ;
}
static T_1 F_92 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_48 ( F_10 ( V_2 , V_77 -> V_80 ) ) ;
}
static T_1 F_93 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_59 ( F_10 ( V_2 , V_77 -> V_80 ) ) ;
}
static T_1 F_94 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_40 ( F_10 ( V_2 , V_77 -> V_80 ) ) ;
}
static void F_95 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_107 )
{
F_12 ( V_2 , V_77 -> V_90 , ~ V_108 ,
F_65 ( V_107 ) ) ;
}
static void F_96 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_107 )
{
F_12 ( V_2 , V_77 -> V_80 ,
~ ( V_109 | V_81 ) ,
F_84 ( V_107 ) ) ;
}
static T_1 F_97 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_38 ( F_10 ( V_2 , V_77 -> V_90 ) ) ;
}
static T_1 F_98 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_57 ( F_10 ( V_2 , V_77 -> V_80 ) ) ;
}
static void F_99 ( struct V_1 * V_2 ,
const struct V_76 * V_77 ,
T_1 V_110 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_12 ( V_2 , V_77 -> V_80 , ~ V_81 ,
( F_32 ( 1 ) |
F_33 ( 1 ) ) ) ;
F_12 ( V_2 , V_77 -> V_90 , ~ V_111 ,
F_71 ( V_110 ) ) ;
V_6 -> V_100 =
( V_6 -> V_100 & ~ V_77 -> V_101 [ 3 ] ) |
V_77 -> V_101 [ V_110 ] ;
}
static void F_100 ( struct V_1 * V_2 ,
const struct V_76 * V_77 ,
T_1 V_110 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_84 ;
V_84 = F_10 ( V_2 , V_77 -> V_80 ) & ~ V_81 ;
F_11 ( V_2 , V_77 -> V_80 , ( V_84 | F_32 ( 1 ) |
F_35 ( 1 ) ) ) ;
F_11 ( V_2 , V_77 -> V_80 , ( ( V_84 & ~ V_112 ) |
F_85 ( V_110 ) ) ) ;
V_6 -> V_100 =
( V_6 -> V_100 & ~ V_77 -> V_101 [ 3 ] ) |
V_77 -> V_101 [ V_110 ] ;
}
static T_1 F_101 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_42 ( F_10 ( V_2 , V_77 -> V_90 ) ) ;
}
static T_1 F_102 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_56 ( F_10 ( V_2 , V_77 -> V_80 ) ) ;
}
static void F_103 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_78 )
{
V_77 -> V_113 ( V_2 , V_77 , ( ( V_77 -> V_114 ( V_2 , V_77 ) & ~ V_115 ) |
F_53 ( V_78 ) ) , false ) ;
}
static T_1 F_104 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_75 ( V_77 -> V_114 ( V_2 , V_77 ) ) ;
}
static void F_105 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_78 )
{
V_77 -> V_113 ( V_2 , V_77 , ( ( V_77 -> V_114 ( V_2 , V_77 ) & ~ V_116 ) |
F_54 ( V_78 ) ) , false ) ;
}
static T_1 F_106 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_73 ( V_77 -> V_114 ( V_2 , V_77 ) ) ;
}
static void F_107 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_78 )
{
V_77 -> V_113 ( V_2 , V_77 , ( ( V_77 -> V_114 ( V_2 , V_77 ) & ~ V_117 ) |
F_52 ( V_78 ) ) , false ) ;
}
static T_1 F_108 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_74 ( V_77 -> V_114 ( V_2 , V_77 ) ) ;
}
static void F_109 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_78 )
{
V_77 -> V_113 ( V_2 , V_77 , ( ( V_77 -> V_114 ( V_2 , V_77 ) & ~ V_118 ) |
F_45 ( V_78 != 0 ) ) , false ) ;
}
static T_1 F_110 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_80 ( V_77 -> V_114 ( V_2 , V_77 ) ) ;
}
static void F_111 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , T_1 V_78 )
{
V_77 -> V_113 ( V_2 , V_77 , ( ( V_77 -> V_114 ( V_2 , V_77 ) & ~ V_119 ) |
F_43 ( V_78 != 0 ) ) , false ) ;
}
static T_1 F_112 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
return F_68 ( V_77 -> V_114 ( V_2 , V_77 ) ) ;
}
static void F_113 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
T_1 V_83 ;
V_83 = F_10 ( V_2 , V_77 -> V_90 ) ;
F_11 ( V_2 , V_77 -> V_90 , ( V_83 ^ V_120 ) ) ;
F_11 ( V_2 , V_77 -> V_90 , V_83 ) ;
}
static void F_114 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
T_1 V_84 ;
V_84 = F_10 ( V_2 , V_77 -> V_80 ) & ~ V_81 ;
F_11 ( V_2 , V_77 -> V_80 , ( V_84 ^ V_121 ) ) ;
F_11 ( V_2 , V_77 -> V_80 , V_84 ) ;
}
static unsigned int F_115 ( unsigned int V_122 )
{
return ( ( V_122 >> 18 ) & 0x3fff ) ^ 0x2000 ;
}
static int F_116 ( struct V_1 * V_2 , unsigned int V_61 )
{
unsigned int V_123 = V_61 / 16 ;
unsigned int V_22 = 1 << ( V_61 - ( 16 * V_123 ) ) ;
unsigned int V_28 ;
V_28 = F_10 ( V_2 , F_117 ( V_123 ) ) ;
F_11 ( V_2 , F_118 ( V_123 ) , V_22 | V_28 ) ;
V_28 = F_10 ( V_2 , F_119 ( V_123 ) ) ;
F_11 ( V_2 , F_120 ( V_123 ) , V_22 | V_28 ) ;
F_11 ( V_2 , V_124 , V_125 ) ;
V_28 = F_10 ( V_2 , F_121 ( V_123 ) ) ;
F_11 ( V_2 , F_122 ( V_123 ) , V_22 | V_28 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , unsigned int V_123 ,
unsigned int V_22 )
{
F_11 ( V_2 , V_124 , V_126 ) ;
F_11 ( V_2 , F_122 ( V_123 ) , V_22 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
unsigned int V_123 ;
F_11 ( V_2 , V_124 , V_126 ) ;
for ( V_123 = 0 ; V_123 < V_127 ; V_123 ++ )
F_11 ( V_2 , F_122 ( V_123 ) , 0xffff ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 ,
T_1 V_128 , T_3 V_123 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 = V_2 -> V_129 ;
struct V_130 * V_3 = & V_24 -> V_131 -> V_3 ;
F_123 ( V_2 , V_123 , V_128 ) ;
if ( V_6 -> V_132 ) {
if ( ( V_128 >> ( V_3 -> V_133 - ( 16 * V_123 ) ) ) == 1 &&
V_3 -> V_134 == V_135 ) {
F_1 ( V_2 , V_136 , V_41 ) ;
if ( V_3 -> V_137 == V_135 )
F_116 ( V_2 , V_3 -> V_138 ) ;
}
if ( ( V_128 >> ( V_3 -> V_138 - ( 16 * V_123 ) ) ) == 1 &&
V_3 -> V_137 == V_135 ) {
F_1 ( V_2 , V_139 , V_13 ) ;
if ( V_3 -> V_140 == V_135 ) {
V_6 -> V_141 = V_3 -> V_142 ;
F_116 ( V_2 , V_3 -> V_143 ) ;
}
if ( V_3 -> V_140 == V_144 ) {
const struct V_76 * V_77 =
& V_145 [ 5 ] ;
V_6 -> V_141 = V_3 -> V_142 ;
V_77 -> V_146 ( V_2 , V_77 , V_147 ) ;
}
}
if ( ( V_128 >> ( V_3 -> V_143 - ( 16 * V_123 ) ) ) == 1 &&
V_3 -> V_140 == V_135 ) {
F_1 ( V_2 , V_139 , V_13 ) ;
V_6 -> V_141 -- ;
if ( V_6 -> V_141 > 0 )
F_116 ( V_2 , V_3 -> V_143 ) ;
}
}
}
static void F_126 ( struct V_1 * V_2 )
{
T_1 V_128 ;
T_3 V_123 ;
for ( V_123 = 0 ; V_123 < V_127 ; V_123 ++ ) {
V_128 = 0 ;
V_128 = F_10 ( V_2 , F_127 ( V_123 ) ) ;
if ( V_128 ) {
F_125 ( V_2 , V_128 , V_123 ) ;
return;
}
}
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 = V_2 -> V_129 ;
struct V_148 * V_131 = V_24 -> V_131 ;
struct V_130 * V_3 = & V_131 -> V_3 ;
const struct V_76 * V_77 ;
T_1 V_128 ;
V_128 = F_10 ( V_2 , V_149 ) ;
if ( V_128 & V_150 ) {
V_77 = & V_145 [ 0 ] ;
V_77 -> V_151 ( V_2 , V_77 ) ;
}
if ( V_128 & V_152 ) {
V_77 = & V_145 [ 1 ] ;
V_77 -> V_151 ( V_2 , V_77 ) ;
}
if ( V_128 & V_153 ) {
V_77 = & V_145 [ 2 ] ;
V_77 -> V_151 ( V_2 , V_77 ) ;
}
if ( V_128 & V_154 ) {
V_77 = & V_145 [ 3 ] ;
V_77 -> V_151 ( V_2 , V_77 ) ;
}
if ( V_128 & V_155 ) {
V_77 = & V_145 [ 4 ] ;
V_77 -> V_151 ( V_2 , V_77 ) ;
if ( V_6 -> V_141 > 0 ) {
V_6 -> V_141 -- ;
if ( V_6 -> V_141 == 0 )
V_77 -> V_146 ( V_2 , V_77 , V_156 ) ;
if ( V_3 -> V_140 == V_144 ) {
F_1 ( V_2 , V_139 ,
V_13 ) ;
}
}
}
if ( V_128 & V_157 ) {
V_77 = & V_145 [ 5 ] ;
V_77 -> V_151 ( V_2 , V_77 ) ;
if ( V_3 -> V_137 == V_144 ) {
F_1 ( V_2 , V_139 , V_13 ) ;
}
if ( V_3 -> V_140 == V_144 ) {
V_77 = & V_145 [ 4 ] ;
V_6 -> V_141 = V_3 -> V_142 ;
V_77 -> V_146 ( V_2 , V_77 , V_147 ) ;
}
}
}
static bool F_129 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 = V_2 -> V_129 ;
struct V_148 * V_131 = V_24 -> V_131 ;
struct V_130 * V_3 = & V_131 -> V_3 ;
T_2 * V_158 = ( T_2 * ) V_6 -> V_159 . V_160 + 1 ;
bool V_161 = false ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_3 -> V_142 ; V_11 ++ ) {
unsigned short V_162 ;
V_162 = F_115 ( * V_158 ) ;
V_158 ++ ;
F_130 ( V_24 , V_162 ) ;
}
V_131 -> V_163 |= V_164 ;
if ( ! V_6 -> V_165 )
V_6 -> V_166 -- ;
if ( V_6 -> V_166 <= 0 ) {
V_6 -> V_132 = 0 ;
F_4 ( V_2 , V_136 , V_41 ) ;
V_131 -> V_163 |= V_167 ;
V_161 = true ;
}
if ( V_6 -> V_132 && V_3 -> V_137 == V_135 )
F_116 ( V_2 , V_3 -> V_138 ) ;
F_131 ( V_2 , V_24 ) ;
return V_161 ;
}
static T_5 F_132 ( int V_168 , void * V_169 )
{
struct V_1 * V_2 = V_169 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_170 ;
T_2 V_171 , V_172 ;
if ( ! V_2 -> V_173 )
return V_174 ;
F_133 ( & V_2 -> V_175 , V_170 ) ;
V_172 = F_6 ( V_6 -> V_9 + V_176 ) ;
V_171 = F_6 ( V_6 -> V_9 + V_54 ) ;
F_3 ( 0 , V_6 -> V_9 + V_176 ) ;
F_3 ( V_171 , V_6 -> V_9 + V_54 ) ;
switch ( V_171 ) {
case V_177 :
if ( F_129 ( V_2 ) )
V_172 = 0 ;
break;
case V_178 :
F_126 ( V_2 ) ;
F_128 ( V_2 ) ;
break;
}
F_3 ( V_172 , V_6 -> V_9 + V_176 ) ;
F_134 ( & V_2 -> V_175 , V_170 ) ;
return V_179 ;
}
static void F_135 ( struct V_1 * V_2 , T_3 * V_180 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_23 * V_24 = V_2 -> V_129 ;
struct V_130 * V_3 = & V_24 -> V_131 -> V_3 ;
T_2 * V_181 ;
T_2 V_182 ;
T_1 V_11 ;
T_1 V_183 ;
T_2 V_184 ;
F_4 ( V_2 , V_136 , V_41 ) ;
V_181 = ( T_2 * ) V_6 -> V_185 . V_160 ;
F_3 ( ( T_2 ) V_6 -> V_185 . V_186 ,
V_6 -> V_9 + V_187 ) ;
if ( V_3 != NULL && V_3 -> V_137 != V_188 ) {
* V_181 ++ = V_189 | V_190 ;
* V_181 ++ = V_191 | V_190 ;
}
* V_181 ++ = V_192 | ( V_18 >> 2 ) ;
* V_181 ++ = V_21 | V_193 ;
* V_181 ++ = V_192 | ( V_19 >> 2 ) ;
* V_181 ++ = V_194 ;
* V_181 ++ = V_191 | V_195 ;
* V_181 ++ = V_196 | V_195 ;
* V_181 ++ = V_189 | V_195 ;
for ( V_6 -> V_197 = 0 ; V_6 -> V_197 < 16 ;
V_6 -> V_197 ++ ) {
V_184 = ( * V_180 << 8 ) | ( * V_180 & 0x10 ? V_194 :
V_198 ) ;
* V_181 ++ = V_192 | ( V_18 >> 2 ) ;
* V_181 ++ = V_21 | V_193 ;
* V_181 ++ = V_192 | ( V_19 >> 2 ) ;
* V_181 ++ = V_184 ;
* V_181 ++ = V_191 | V_195 ;
* V_181 ++ = V_196 | V_195 ;
* V_181 ++ = V_189 | V_195 ;
* V_181 ++ = V_192 | ( V_18 >> 2 ) ;
* V_181 ++ = V_21 | V_199 ;
* V_181 ++ = V_192 | ( V_19 >> 2 ) ;
* V_181 ++ = V_184 ;
* V_181 ++ = V_191 | V_195 ;
* V_181 ++ = V_196 | V_195 ;
* V_181 ++ = V_189 | V_195 ;
V_182 =
( T_2 ) V_6 -> V_185 . V_186 +
( T_2 ) ( ( unsigned long ) V_181 -
( unsigned long ) V_6 ->
V_185 . V_160 ) ;
for ( V_11 = 0 ; V_11 < ( 10 * V_200 / 2 ) ; V_11 ++ ) {
V_182 += 8 ;
* V_181 ++ = V_201 ;
* V_181 ++ = V_182 ;
}
if ( V_3 != NULL && V_3 -> V_140 != V_202 ) {
* V_181 ++ = V_189 | V_190 ;
* V_181 ++ = V_191 | V_190 ;
}
* V_181 ++ = V_192 | ( V_203 >> 2 ) ;
* V_181 ++ = V_204 | V_205 ;
* V_181 ++ = V_206 ;
* V_181 ++ = V_192 | ( V_203 >> 2 ) ;
* V_181 ++ = V_204 | V_207 ;
* V_181 ++ = V_189 | V_208 ;
* V_181 ++ = V_209 |
( F_136 ( V_210 ) >> 2 ) ;
* V_181 ++ = ( T_2 ) V_6 -> V_159 . V_186 +
( V_6 -> V_197 << 2 ) ;
if ( * V_180 ++ & V_211 ) {
V_6 -> V_197 ++ ;
break;
}
}
for ( V_183 = 0 ; V_183 < ( 2 * V_200 ) ; V_183 ++ )
* V_181 ++ = V_206 ;
* V_181 ++ = V_192 | ( V_203 >> 2 ) ;
* V_181 ++ = V_204 | V_205 ;
* V_181 ++ = V_206 ;
* V_181 ++ = V_192 | ( V_203 >> 2 ) ;
* V_181 ++ = V_204 | V_207 ;
* V_181 ++ = V_189 | V_208 ;
* V_181 ++ = V_209 | ( F_136 ( V_210 ) >> 2 ) ;
* V_181 ++ = ( T_2 ) V_6 -> V_159 . V_186 +
( V_6 -> V_197 << 2 ) ;
if ( V_6 -> V_132 == 1 )
* V_181 ++ = V_212 ;
* V_181 ++ = V_201 ;
* V_181 ++ = ( T_2 ) V_6 -> V_185 . V_186 ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_122 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_11 ;
T_6 * V_158 ;
F_1 ( V_2 , V_139 , V_13 ) ;
while ( F_5 ( V_2 , V_139 , V_13 ) )
;
V_158 = ( T_2 * ) V_6 -> V_159 . V_160 + 1 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_197 ; V_11 ++ ) {
* V_122 = F_115 ( * V_158 ++ ) ;
V_122 ++ ;
}
return V_11 ;
}
static int F_138 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned long V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_28 ;
V_28 = F_6 ( V_6 -> V_9 + V_14 ) ;
if ( V_28 & V_213 )
return 0 ;
return - V_30 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_122 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_61 = F_140 ( V_26 -> V_214 ) ;
T_1 V_215 = F_141 ( V_26 -> V_214 ) ;
T_1 V_216 = 0 ;
T_2 V_217 ;
T_2 V_218 ;
int V_32 ;
int V_183 ;
if ( V_215 == 0 )
V_216 = ( V_61 << 8 ) | ( V_194 ) ;
else
V_216 = ( V_61 << 8 ) | ( V_198 ) ;
F_11 ( V_2 , V_193 , V_216 ) ;
F_11 ( V_2 , V_199 , V_216 ) ;
for ( V_183 = 0 ; V_183 < V_26 -> V_183 ; V_183 ++ ) {
F_8 ( 10 ) ;
V_217 = F_6 ( V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 & ~ V_207 ,
V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 & ~ V_207 ,
V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 & ~ V_207 ,
V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 | V_207 , V_6 -> V_9 + V_203 ) ;
V_32 = F_15 ( V_2 , V_24 , V_26 , F_138 , 0 ) ;
if ( V_32 )
return V_32 ;
if ( V_183 != 0 ) {
V_218 = F_6 ( V_6 -> V_9 + V_210 ) ;
V_122 [ V_183 - 1 ] = F_115 ( V_218 ) ;
}
F_8 ( 4 ) ;
}
V_217 = F_6 ( V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 & ~ V_207 , V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 & ~ V_207 , V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 & ~ V_207 , V_6 -> V_9 + V_203 ) ;
F_3 ( V_217 | V_207 , V_6 -> V_9 + V_203 ) ;
V_32 = F_15 ( V_2 , V_24 , V_26 , F_138 , 0 ) ;
if ( V_32 )
return V_32 ;
if ( V_183 != 0 ) {
V_218 = F_6 ( V_6 -> V_9 + V_210 ) ;
V_122 [ V_183 - 1 ] = F_115 ( V_218 ) ;
}
return V_183 ;
}
static int F_142 ( T_3 * V_180 , struct V_130 * V_3 )
{
int V_183 ;
for ( V_183 = 0 ; V_183 < V_3 -> V_142 ; V_183 ++ ) {
if ( F_141 ( V_3 -> V_219 [ V_183 ] ) == 0 )
V_180 [ V_183 ] = F_140 ( V_3 -> V_219 [ V_183 ] ) | V_220 ;
else
V_180 [ V_183 ] = F_140 ( V_3 -> V_219 [ V_183 ] ) | V_221 ;
}
if ( V_183 != 0 )
V_180 [ V_183 - 1 ] |= V_211 ;
return V_183 ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
unsigned int V_222 )
{
struct V_130 * V_3 = & V_24 -> V_131 -> V_3 ;
if ( V_222 != V_3 -> V_133 )
return - V_49 ;
F_1 ( V_2 , V_136 , V_41 ) ;
V_24 -> V_131 -> V_223 = NULL ;
return 1 ;
}
static int F_144 ( unsigned int * V_224 , int V_225 )
{
int V_226 , V_227 ;
V_227 = 500 ;
switch ( V_225 ) {
case V_228 :
default:
V_226 = ( * V_224 + V_227 / 2 ) / V_227 ;
break;
case V_229 :
V_226 = ( * V_224 ) / V_227 ;
break;
case V_230 :
V_226 = ( * V_224 + V_227 - 1 ) / V_227 ;
break;
}
* V_224 = V_227 * V_226 ;
return V_226 - 1 ;
}
static void F_145 ( struct V_1 * V_2 ,
const struct V_76 * V_77 , int V_231 )
{
T_1 V_85 =
F_37 ( V_232 ) |
F_43 ( V_99 ) |
F_52 ( V_92 ) |
F_54 ( V_233 ) |
F_53 ( V_93 ) |
F_47 ( V_156 ) ;
T_1 V_234 = V_235 ;
V_77 -> V_113 ( V_2 , V_77 , V_85 , false ) ;
F_30 ( V_2 , V_77 , V_231 ) ;
V_77 -> V_236 ( V_2 , V_77 , 0 ) ;
V_77 -> V_237 ( V_2 , V_77 ) ;
V_77 -> V_236 ( V_2 , V_77 , 1 ) ;
V_77 -> V_238 ( V_2 , V_77 , V_239 ) ;
F_28 ( V_2 , V_77 , V_234 ) ;
}
static int F_146 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_180 [ 16 ] ;
struct V_130 * V_3 = & V_24 -> V_131 -> V_3 ;
const struct V_76 * V_77 ;
int V_231 ;
if ( V_6 -> V_132 ) {
F_147 ( V_2 -> V_240 ,
L_6 ) ;
return - V_30 ;
}
F_3 ( 0 , V_6 -> V_9 + V_176 ) ;
F_3 ( V_177 | V_178 , V_6 -> V_9 + V_54 ) ;
F_124 ( V_2 ) ;
V_6 -> V_132 = 0 ;
if ( V_3 == NULL )
return - V_49 ;
F_142 ( V_180 , V_3 ) ;
V_6 -> V_132 = 1 ;
V_6 -> V_141 = 0 ;
switch ( V_3 -> V_137 ) {
case V_188 :
break;
case V_144 :
V_77 = & V_145 [ 5 ] ;
V_231 = F_144 ( & V_3 -> V_138 ,
V_3 -> V_170 & V_241 ) ;
F_145 ( V_2 , V_77 , V_231 ) ;
V_77 -> V_146 ( V_2 , V_77 , V_147 ) ;
break;
case V_135 :
if ( V_3 -> V_134 != V_135 )
F_116 ( V_2 , V_3 -> V_138 ) ;
break;
}
switch ( V_3 -> V_140 ) {
case V_202 :
break;
case V_144 :
V_77 = & V_145 [ 4 ] ;
V_231 = F_144 ( & V_3 -> V_143 ,
V_3 -> V_170 & V_241 ) ;
F_145 ( V_2 , V_77 , V_231 ) ;
V_77 -> V_146 ( V_2 , V_77 , V_156 ) ;
break;
case V_135 :
if ( V_3 -> V_137 != V_135 &&
V_3 -> V_134 == V_135 )
F_116 ( V_2 , V_3 -> V_143 ) ;
break;
}
switch ( V_3 -> V_242 ) {
case V_243 :
V_6 -> V_166 = V_3 -> V_244 ;
V_6 -> V_165 = 0 ;
break;
case V_245 :
V_6 -> V_165 = 1 ;
V_6 -> V_166 = 1 ;
break;
}
F_135 ( V_2 , V_180 ) ;
switch ( V_3 -> V_134 ) {
case V_202 :
F_1 ( V_2 , V_136 , V_41 ) ;
V_24 -> V_131 -> V_223 = NULL ;
break;
case V_135 :
F_116 ( V_2 , V_3 -> V_133 ) ;
V_24 -> V_131 -> V_223 = NULL ;
break;
case V_246 :
V_24 -> V_131 -> V_223 = F_143 ;
break;
}
F_3 ( V_178 | V_177 , V_6 -> V_9 + V_176 ) ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_23 * V_24 , struct V_130 * V_3 )
{
int V_247 = 0 ;
unsigned int V_248 ;
V_247 |= F_149 ( & V_3 -> V_134 ,
V_202 | V_246 | V_135 ) ;
V_247 |= F_149 ( & V_3 -> V_137 ,
V_144 | V_135 | V_188 ) ;
V_247 |= F_149 ( & V_3 -> V_140 ,
V_144 | V_135 | V_202 ) ;
V_247 |= F_149 ( & V_3 -> V_249 , V_243 ) ;
V_247 |= F_149 ( & V_3 -> V_242 , V_243 | V_245 ) ;
if ( V_247 )
return 1 ;
V_247 |= F_150 ( V_3 -> V_134 ) ;
V_247 |= F_150 ( V_3 -> V_137 ) ;
V_247 |= F_150 ( V_3 -> V_140 ) ;
V_247 |= F_150 ( V_3 -> V_242 ) ;
if ( V_247 )
return 2 ;
switch ( V_3 -> V_134 ) {
case V_202 :
case V_246 :
V_247 |= F_151 ( & V_3 -> V_133 , 0 ) ;
break;
case V_135 :
V_247 |= F_152 ( & V_3 -> V_133 , 39 ) ;
break;
}
if ( V_3 -> V_137 == V_135 )
V_247 |= F_152 ( & V_3 -> V_138 , 39 ) ;
if ( V_3 -> V_140 == V_135 )
V_247 |= F_152 ( & V_3 -> V_143 , 39 ) ;
#define F_153 200000
#define F_154 2000000000
if ( V_3 -> V_137 == V_144 ) {
V_247 |= F_155 ( & V_3 -> V_138 ,
F_153 ) ;
V_247 |= F_152 ( & V_3 -> V_138 ,
F_154 ) ;
} else {
}
if ( V_3 -> V_140 == V_144 ) {
V_247 |= F_155 ( & V_3 -> V_143 ,
F_153 ) ;
V_247 |= F_152 ( & V_3 -> V_143 ,
F_154 ) ;
} else {
}
V_247 |= F_151 ( & V_3 -> V_250 , V_3 -> V_142 ) ;
if ( V_3 -> V_242 == V_243 )
V_247 |= F_152 ( & V_3 -> V_244 , 0x00ffffff ) ;
else
V_247 |= F_151 ( & V_3 -> V_244 , 0 ) ;
if ( V_247 )
return 3 ;
if ( V_3 -> V_137 == V_144 ) {
V_248 = V_3 -> V_138 ;
F_144 ( & V_248 , V_3 -> V_170 & V_241 ) ;
V_247 |= F_151 ( & V_3 -> V_138 , V_248 ) ;
}
if ( V_3 -> V_140 == V_144 ) {
V_248 = V_3 -> V_143 ;
F_144 ( & V_248 , V_3 -> V_170 & V_241 ) ;
V_247 |= F_151 ( & V_3 -> V_143 , V_248 ) ;
if ( V_3 -> V_137 == V_144 ) {
V_248 = V_3 -> V_143 * V_3 -> V_250 ;
V_247 |= F_155 ( & V_3 -> V_138 ,
V_248 ) ;
}
}
if ( V_247 )
return 4 ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_2 , V_136 , V_41 ) ;
F_3 ( 0 , V_6 -> V_9 + V_176 ) ;
V_6 -> V_132 = 0 ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_122 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
int V_32 ;
T_1 V_61 = F_140 ( V_26 -> V_214 ) ;
T_4 V_62 ;
for ( V_11 = 0 ; V_11 < V_26 -> V_183 ; V_11 ++ ) {
V_62 = ( T_4 ) V_122 [ V_11 ] ;
V_6 -> V_251 [ F_140 ( V_26 -> V_214 ) ] = V_122 [ V_11 ] ;
V_62 -= ( 0x1fff ) ;
V_32 = F_23 ( V_2 , V_61 , V_62 ) ;
if ( V_32 )
return V_32 ;
}
return V_11 ;
}
static int F_158 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_122 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_26 -> V_183 ; V_11 ++ )
V_122 [ V_11 ] = V_6 -> V_251 [ F_140 ( V_26 -> V_214 ) ] ;
return V_11 ;
}
static void F_159 ( struct V_1 * V_2 )
{
T_1 V_123 ;
F_11 ( V_2 , V_124 , V_126 ) ;
for ( V_123 = 0 ; V_123 < V_127 ; V_123 ++ ) {
F_11 ( V_2 , F_120 ( V_123 ) , 0 ) ;
F_11 ( V_2 , F_122 ( V_123 ) , 0xffff ) ;
F_11 ( V_2 , F_118 ( V_123 ) , 0 ) ;
F_11 ( V_2 , F_160 ( V_123 ) , 0 ) ;
}
}
static int F_161 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_122 )
{
unsigned long V_123 = ( unsigned long ) V_24 -> V_7 ;
if ( F_162 ( V_24 , V_122 ) )
F_11 ( V_2 , F_160 ( V_123 ) , V_24 -> V_252 ) ;
V_122 [ 1 ] = F_10 ( V_2 , F_163 ( V_123 ) ) ;
return V_26 -> V_183 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 ,
unsigned int * V_122 )
{
unsigned long V_123 = ( unsigned long ) V_24 -> V_7 ;
int V_32 ;
V_32 = F_165 ( V_2 , V_24 , V_26 , V_122 , 0 ) ;
if ( V_32 )
return V_32 ;
F_11 ( V_2 , F_160 ( V_123 ) , V_24 -> V_253 ) ;
return V_26 -> V_183 ;
}
static int F_166 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_122 )
{
T_1 V_85 =
F_37 ( V_232 ) |
F_43 ( V_99 ) |
F_52 ( V_94 ) |
F_54 ( V_254 ) |
F_53 ( V_93 ) |
F_47 ( V_156 ) ;
T_1 V_234 = V_255 ;
T_1 V_105 = V_147 ;
const struct V_76 * V_77 =
& V_145 [ F_140 ( V_26 -> V_214 ) ] ;
V_77 -> V_113 ( V_2 , V_77 , V_85 , true ) ;
F_30 ( V_2 , V_77 , V_122 [ 0 ] ) ;
V_77 -> V_237 ( V_2 , V_77 ) ;
F_28 ( V_2 , V_77 , V_234 ) ;
V_77 -> V_146 ( V_2 , V_77 , ( V_105 != 0 ) ) ;
return V_26 -> V_183 ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_122 )
{
int V_183 ;
const struct V_76 * V_77 =
& V_145 [ F_140 ( V_26 -> V_214 ) ] ;
for ( V_183 = 0 ; V_183 < V_26 -> V_183 ; V_183 ++ )
V_122 [ V_183 ] = F_27 ( V_2 , V_77 ) ;
return V_183 ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 , unsigned int * V_122 )
{
const struct V_76 * V_77 =
& V_145 [ F_140 ( V_26 -> V_214 ) ] ;
F_30 ( V_2 , V_77 , V_122 [ 0 ] ) ;
V_77 -> V_236 ( V_2 , V_77 , 0 ) ;
V_77 -> V_237 ( V_2 , V_77 ) ;
V_77 -> V_236 ( V_2 , V_77 , 2 ) ;
return 1 ;
}
static void F_169 ( struct V_1 * V_2 , T_1 V_256 )
{
F_11 ( V_2 , V_124 , V_257 ) ;
F_11 ( V_2 , V_258 , V_256 ) ;
F_11 ( V_2 , V_124 , V_259 ) ;
}
static void F_170 ( struct V_1 * V_2 ,
struct V_260 * V_261 , T_7 V_262 )
{
struct V_263 * V_264 = F_171 ( V_2 ) ;
void * V_265 ;
T_8 V_266 ;
if ( V_261 == NULL )
return;
V_265 = V_261 -> V_160 ;
V_266 = V_261 -> V_186 ;
if ( V_265 ) {
F_172 ( V_264 , V_262 , V_265 , V_266 ) ;
V_261 -> V_160 = NULL ;
V_261 -> V_186 = 0 ;
}
}
static void F_173 ( struct V_1 * V_2 )
{
int V_61 ;
const struct V_76 * V_77 ;
T_1 V_85 =
F_37 ( V_232 ) |
F_43 ( V_99 ) |
F_52 ( V_94 ) |
F_54 ( V_254 ) |
F_53 ( V_93 ) |
F_47 ( V_156 ) ;
for ( V_61 = 0 ; V_61 < V_267 ; V_61 ++ ) {
V_77 = & V_145 [ V_61 ] ;
V_77 -> V_113 ( V_2 , V_77 , V_85 , true ) ;
V_77 -> V_238 ( V_2 , V_77 , 0 ) ;
V_77 -> V_151 ( V_2 , V_77 ) ;
V_77 -> V_146 ( V_2 , V_77 , V_147 ) ;
}
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_263 * V_264 = F_171 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
void * V_16 ;
T_8 V_268 ;
V_16 = F_175 ( V_264 , V_269 , & V_268 ) ;
if ( ! V_16 )
return - V_270 ;
V_6 -> V_159 . V_160 = V_16 ;
V_6 -> V_159 . V_186 = V_268 ;
V_16 = F_175 ( V_264 , V_269 , & V_268 ) ;
if ( ! V_16 )
return - V_270 ;
V_6 -> V_185 . V_160 = V_16 ;
V_6 -> V_185 . V_186 = V_268 ;
return 0 ;
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_8 V_271 ;
T_1 V_61 ;
int V_11 ;
int V_32 ;
F_1 ( V_2 , V_272 | V_273 | V_274 ,
V_41 ) ;
F_3 ( V_275 |
( V_276 << V_277 ) | V_278 |
V_279 , V_6 -> V_9 + V_280 ) ;
F_3 ( V_281 , V_6 -> V_9 + V_282 ) ;
F_3 ( V_204 | V_207 , V_6 -> V_9 + V_203 ) ;
V_6 -> V_37 = 0xA0 ;
F_3 ( V_283 | V_284 ,
V_6 -> V_9 + V_285 ) ;
F_1 ( V_2 , V_29 , V_13 ) ;
V_32 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_32 )
return V_32 ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
F_3 ( V_283 , V_6 -> V_9 + V_285 ) ;
F_1 ( V_2 , V_29 , V_13 ) ;
V_32 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_32 )
return V_32 ;
}
F_3 ( V_286 , V_6 -> V_9 + V_287 ) ;
F_3 ( V_288 | V_289 , V_6 -> V_9 + V_290 ) ;
F_3 ( V_288 | V_289 | V_60 ,
V_6 -> V_9 + V_290 + 4 ) ;
F_3 ( V_291 , V_6 -> V_9 + V_292 ) ;
F_3 ( ( T_2 ) V_6 -> V_185 . V_186 ,
V_6 -> V_9 + V_187 ) ;
F_3 ( 0 , V_6 -> V_9 + V_293 ) ;
F_3 ( 0 , V_6 -> V_9 + V_294 ) ;
#if 0
{
struct comedi_subdevice *s = dev->read_subdev;
uint8_t poll_list;
uint16_t adc_data;
uint16_t start_val;
uint16_t index;
unsigned int data[16];
poll_list = S626_EOPL;
s626_reset_adc(dev, &poll_list);
s626_ai_rinsn(dev, s, NULL, data);
start_val = data[0];
for (index = 0; index < 500; index++) {
s626_ai_rinsn(dev, s, NULL, data);
adc_data = data[0];
if (adc_data != start_val)
break;
}
}
#endif
F_3 ( 0 , V_6 -> V_9 + V_295 ) ;
V_271 = V_6 -> V_159 . V_186 +
( V_296 * sizeof( T_2 ) ) ;
F_3 ( ( T_2 ) V_271 , V_6 -> V_9 + V_297 ) ;
F_3 ( ( T_2 ) ( V_271 + sizeof( T_2 ) ) ,
V_6 -> V_9 + V_298 ) ;
V_6 -> V_52 = ( T_2 * ) V_6 -> V_159 . V_160 +
V_296 ;
F_3 ( 8 , V_6 -> V_9 + V_299 ) ;
F_3 ( V_55 | V_56 | V_57 | V_60 ,
V_6 -> V_9 + F_22 ( 0 ) ) ;
F_3 ( V_300 , V_6 -> V_9 + F_22 ( 1 ) ) ;
F_3 ( V_301 , V_6 -> V_9 + V_292 ) ;
F_25 ( V_2 ) ;
V_32 = F_25 ( V_2 ) ;
if ( V_32 )
return V_32 ;
for ( V_61 = 0 ; V_61 < V_302 ; V_61 ++ ) {
V_32 = F_23 ( V_2 , V_61 , 0 ) ;
if ( V_32 )
return V_32 ;
}
F_173 ( V_2 ) ;
F_169 ( V_2 , ( F_10 ( V_2 , V_149 ) &
V_303 ) ) ;
F_159 ( V_2 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 ,
unsigned long V_304 )
{
struct V_263 * V_264 = F_171 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_23 * V_24 ;
int V_32 ;
V_6 = F_178 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_270 ;
V_32 = F_179 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_6 -> V_9 = F_180 ( V_264 , 0 ) ;
if ( ! V_6 -> V_9 )
return - V_270 ;
F_3 ( 0 , V_6 -> V_9 + V_176 ) ;
F_3 ( V_305 , V_6 -> V_9 + V_41 ) ;
V_32 = F_174 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( V_264 -> V_168 ) {
V_32 = F_181 ( V_264 -> V_168 , F_132 , V_306 ,
V_2 -> V_307 , V_2 ) ;
if ( V_32 == 0 )
V_2 -> V_168 = V_264 -> V_168 ;
}
V_32 = F_182 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
V_24 = & V_2 -> V_308 [ 0 ] ;
V_24 -> type = V_309 ;
V_24 -> V_310 = V_311 | V_312 ;
V_24 -> V_313 = V_314 ;
V_24 -> V_315 = 0x3fff ;
V_24 -> V_316 = & V_317 ;
V_24 -> V_318 = V_314 ;
V_24 -> V_319 = F_139 ;
if ( V_2 -> V_168 ) {
V_2 -> V_129 = V_24 ;
V_24 -> V_310 |= V_320 ;
V_24 -> V_321 = F_146 ;
V_24 -> V_322 = F_148 ;
V_24 -> V_323 = F_156 ;
}
V_24 = & V_2 -> V_308 [ 1 ] ;
V_24 -> type = V_324 ;
V_24 -> V_310 = V_325 | V_311 ;
V_24 -> V_313 = V_302 ;
V_24 -> V_315 = 0x3fff ;
V_24 -> V_316 = & V_326 ;
V_24 -> V_327 = F_157 ;
V_24 -> V_319 = F_158 ;
V_24 = & V_2 -> V_308 [ 2 ] ;
V_24 -> type = V_328 ;
V_24 -> V_310 = V_325 | V_311 ;
V_24 -> V_313 = 16 ;
V_24 -> V_315 = 1 ;
V_24 -> V_253 = 0xffff ;
V_24 -> V_7 = ( void * ) 0 ;
V_24 -> V_316 = & V_329 ;
V_24 -> V_330 = F_164 ;
V_24 -> V_331 = F_161 ;
V_24 = & V_2 -> V_308 [ 3 ] ;
V_24 -> type = V_328 ;
V_24 -> V_310 = V_325 | V_311 ;
V_24 -> V_313 = 16 ;
V_24 -> V_315 = 1 ;
V_24 -> V_253 = 0xffff ;
V_24 -> V_7 = ( void * ) 1 ;
V_24 -> V_316 = & V_329 ;
V_24 -> V_330 = F_164 ;
V_24 -> V_331 = F_161 ;
V_24 = & V_2 -> V_308 [ 4 ] ;
V_24 -> type = V_328 ;
V_24 -> V_310 = V_325 | V_311 ;
V_24 -> V_313 = 16 ;
V_24 -> V_315 = 1 ;
V_24 -> V_253 = 0xffff ;
V_24 -> V_7 = ( void * ) 2 ;
V_24 -> V_316 = & V_329 ;
V_24 -> V_330 = F_164 ;
V_24 -> V_331 = F_161 ;
V_24 = & V_2 -> V_308 [ 5 ] ;
V_24 -> type = V_332 ;
V_24 -> V_310 = V_325 | V_311 | V_333 ;
V_24 -> V_313 = V_267 ;
V_24 -> V_315 = 0xffffff ;
V_24 -> V_316 = & V_334 ;
V_24 -> V_330 = F_166 ;
V_24 -> V_319 = F_167 ;
V_24 -> V_327 = F_168 ;
V_32 = F_176 ( V_2 ) ;
if ( V_32 )
return V_32 ;
return 0 ;
}
static void F_183 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
V_6 -> V_132 = 0 ;
if ( V_6 -> V_9 ) {
F_3 ( 0 , V_6 -> V_9 + V_176 ) ;
F_3 ( V_178 | V_177 ,
V_6 -> V_9 + V_54 ) ;
F_169 ( V_2 , 0 ) ;
F_3 ( V_335 , V_6 -> V_9 + V_41 ) ;
F_3 ( V_336 , V_6 -> V_9 + V_292 ) ;
F_170 ( V_2 , & V_6 -> V_185 ,
V_269 ) ;
F_170 ( V_2 , & V_6 -> V_159 ,
V_269 ) ;
}
if ( V_2 -> V_168 )
F_184 ( V_2 -> V_168 , V_2 ) ;
if ( V_6 -> V_9 )
F_185 ( V_6 -> V_9 ) ;
}
F_186 ( V_2 ) ;
}
static int F_187 ( struct V_263 * V_2 ,
const struct V_337 * V_338 )
{
return F_188 ( V_2 , & V_339 , V_338 -> V_340 ) ;
}
