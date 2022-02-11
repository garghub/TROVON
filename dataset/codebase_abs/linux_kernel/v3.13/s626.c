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
F_1 ( V_2 , V_10 , V_11 ) ;
while ( ! F_5 ( V_2 , V_10 , V_11 ) )
;
while ( F_6 ( V_6 -> V_9 + V_12 ) & V_13 )
;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_15 | V_14 , V_6 -> V_9 + V_16 ) ;
F_7 ( V_2 ) ;
return F_6 ( V_6 -> V_9 + V_17 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_3 ( V_19 | V_14 , V_6 -> V_9 + V_16 ) ;
F_3 ( V_18 , V_6 -> V_9 + V_17 ) ;
F_7 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_20 , unsigned int V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_8 ;
V_14 &= 0xffff ;
F_3 ( V_15 | V_14 , V_6 -> V_9 + V_16 ) ;
F_7 ( V_2 ) ;
F_3 ( V_19 | V_14 , V_6 -> V_9 + V_16 ) ;
V_8 = F_6 ( V_6 -> V_9 + V_17 ) ;
V_8 &= V_20 ;
V_8 |= V_18 ;
F_3 ( V_8 & 0xffff , V_6 -> V_9 + V_17 ) ;
F_7 ( V_2 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_21 ;
F_3 ( V_8 , V_6 -> V_9 + V_22 ) ;
F_1 ( V_2 , V_23 , V_11 ) ;
while ( ! F_5 ( V_2 , V_23 , V_11 ) )
;
do {
V_21 = F_6 ( V_6 -> V_9 + V_22 ) ;
} while ( ( V_21 & ( V_24 | V_25 ) ) == V_24 );
return V_21 & V_25 ;
}
static T_3 F_12 ( struct V_1 * V_2 , T_3 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_11 ( V_2 , F_13 ( V_26 ,
V_6 -> V_27 ) |
F_14 ( V_28 , V_14 ) |
F_15 ( V_29 , 0 ) ) )
return 0 ;
if ( F_11 ( V_2 , F_13 ( V_26 ,
( V_6 -> V_27 | 1 ) ) |
F_14 ( V_28 , 0 ) |
F_15 ( V_29 , 0 ) ) )
return 0 ;
return ( F_6 ( V_6 -> V_9 + V_22 ) >> 16 ) & 0xff ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_9 ( V_2 , V_30 , V_6 -> V_31 ) ;
* V_6 -> V_32 = V_8 ;
F_1 ( V_2 , V_33 , V_34 ) ;
F_3 ( V_35 , V_6 -> V_9 + V_36 ) ;
while ( F_6 ( V_6 -> V_9 + V_34 ) & V_33 )
;
F_3 ( V_37 | V_38 | V_39 ,
V_6 -> V_9 + F_17 ( 0 ) ) ;
while ( ! ( F_6 ( V_6 -> V_9 + V_40 ) & V_41 ) )
;
F_3 ( V_37 | V_42 | V_43 | V_39 | V_44 ,
V_6 -> V_9 + F_17 ( 0 ) ) ;
if ( F_6 ( V_6 -> V_9 + V_45 ) & 0xff000000 ) {
while ( F_6 ( V_6 -> V_9 + V_45 ) & 0xff000000 )
;
}
F_3 ( V_38 | V_39 | V_44 ,
V_6 -> V_9 + F_17 ( 0 ) ) ;
while ( ! ( F_6 ( V_6 -> V_9 + V_45 ) & 0xff000000 ) )
;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_46 ,
T_4 V_47 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_48 ;
T_2 V_49 ;
T_2 V_8 ;
V_48 = 1 << V_46 ;
if ( V_47 < 0 ) {
V_47 = - V_47 ;
V_6 -> V_31 |= V_48 ;
} else {
V_6 -> V_31 &= ~ V_48 ;
}
if ( ( T_1 ) V_47 > 0x1FFF )
V_47 = 0x1FFF ;
V_49 = ( V_46 & 2 ) ? V_50 : V_51 ;
F_3 ( V_37 | V_52 | V_49 ,
V_6 -> V_9 + F_17 ( 2 ) ) ;
F_3 ( V_37 | V_53 | V_49 ,
V_6 -> V_9 + F_17 ( 3 ) ) ;
F_3 ( V_37 | V_54 | V_55 ,
V_6 -> V_9 + F_17 ( 4 ) ) ;
F_3 ( V_37 | V_42 | V_55 | V_44 ,
V_6 -> V_9 + F_17 ( 5 ) ) ;
V_8 = 0x0F000000 ;
V_8 |= 0x00004000 ;
V_8 |= ( ( T_2 ) ( V_46 & 1 ) << 15 ) ;
V_8 |= ( T_2 ) V_47 ;
F_16 ( V_2 , V_8 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_3 V_56 ,
T_3 V_57 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_46 ;
V_6 -> V_58 [ V_56 ] = ( T_3 ) V_57 ;
V_46 = V_59 [ V_56 ] ;
F_3 ( V_37 | V_52 | V_55 ,
V_6 -> V_9 + F_17 ( 2 ) ) ;
F_3 ( V_37 | V_53 | V_55 ,
V_6 -> V_9 + F_17 ( 3 ) ) ;
F_3 ( V_37 | V_54 | V_50 ,
V_6 -> V_9 + F_17 ( 4 ) ) ;
F_3 ( V_37 | V_42 | V_50 | V_44 ,
V_6 -> V_9 + F_17 ( 5 ) ) ;
F_16 ( V_2 , ( V_46 << 8 ) | V_57 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_3 V_60 ;
for ( V_60 = 0 ; V_60 < F_21 ( V_59 ) ; V_60 ++ )
F_19 ( V_2 , V_60 ,
F_12 ( V_2 , V_61 [ V_60 ] ) ) ;
}
static T_2 F_22 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
T_2 V_64 ;
V_64 = F_8 ( V_2 , V_63 -> V_65 ) ;
V_64 |= ( ( T_2 ) F_8 ( V_2 , V_63 -> V_65 + 2 ) << 16 ) ;
return V_64 ;
}
static void F_23 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_64 )
{
F_10 ( V_2 , V_63 -> V_66 ,
~ ( V_67 | V_68 ) ,
F_24 ( V_64 ) ) ;
}
static void F_25 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_2 V_64 )
{
F_9 ( V_2 , V_63 -> V_65 , V_64 ) ;
F_9 ( V_2 , V_63 -> V_65 + 2 , V_64 >> 16 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
F_10 ( V_2 , V_63 -> V_66 , ~ V_67 ,
( F_27 ( 1 ) |
F_28 ( 1 ) ) ) ;
}
static void F_29 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
F_10 ( V_2 , V_63 -> V_66 , ~ V_67 ,
( F_27 ( 1 ) |
F_30 ( 1 ) ) ) ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
T_1 V_69 ;
T_1 V_70 ;
T_1 V_71 ;
unsigned V_72 , V_73 , V_74 , V_75 ;
V_69 = F_8 ( V_2 , V_63 -> V_76 ) ;
V_70 = F_8 ( V_2 , V_63 -> V_66 ) ;
V_71 =
F_32 ( F_33 ( V_69 ) ) |
F_34 ( F_35 ( V_70 ) ) |
F_36 ( F_37 ( V_69 ) ) |
F_38 ( F_39 ( V_69 ) ) |
F_40 ( F_41 ( V_69 ) ) |
F_42 ( F_43 ( V_70 ) ) ;
V_72 = F_44 ( V_69 ) ;
if ( V_72 & V_77 ) {
V_75 = V_78 ;
V_74 = V_72 & 1 ;
V_73 = V_79 ;
} else {
V_75 = V_80 ;
V_74 = F_45 ( V_69 ) ;
V_73 = F_46 ( V_69 ) ;
if ( V_73 == V_81 )
V_73 = V_79 ;
}
V_71 |= F_47 ( V_75 ) | F_48 ( V_73 ) |
F_49 ( V_74 ) ;
return V_71 ;
}
static T_1 F_50 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
T_1 V_69 ;
T_1 V_70 ;
T_1 V_71 ;
unsigned V_72 , V_73 , V_74 , V_75 ;
V_69 = F_8 ( V_2 , V_63 -> V_76 ) ;
V_70 = F_8 ( V_2 , V_63 -> V_66 ) ;
V_71 =
F_36 ( F_51 ( V_70 ) ) |
F_34 ( F_35 ( V_70 ) ) |
F_32 ( F_52 ( V_70 ) ) |
F_40 ( F_53 ( V_70 ) ) |
F_42 ( F_54 ( V_70 ) ) |
F_38 ( F_55 ( V_69 ) ) ;
V_72 = F_56 ( V_69 ) ;
V_73 = F_57 ( V_70 ) ;
if ( V_73 == V_81 ) {
V_75 = V_82 ;
V_73 = V_79 ;
V_74 = V_72 & 1 ;
} else if ( V_72 & V_77 ) {
V_75 = V_78 ;
V_73 = V_79 ;
V_74 = V_72 & 1 ;
} else {
V_75 = V_80 ;
V_74 = F_58 ( V_70 ) ;
}
V_71 |= F_47 ( V_75 ) | F_48 ( V_73 ) |
F_49 ( V_74 ) ;
return V_71 ;
}
static void F_59 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_71 ,
T_1 V_83 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_69 ;
T_1 V_70 ;
unsigned V_72 , V_73 , V_74 ;
V_69 = F_60 ( F_61 ( V_71 ) ) ;
V_69 |= F_62 ( F_63 ( V_71 ) ) ;
V_70 = F_27 ( 1 ) | F_28 ( 1 ) ;
V_70 |= F_64 ( F_65 ( V_71 ) ) ;
if ( ! V_83 )
V_69 |= F_66 ( F_67 ( V_71 ) ) ;
V_74 = F_68 ( V_71 ) ;
switch ( F_69 ( V_71 ) ) {
case V_82 :
case V_78 :
V_72 = V_77 ;
V_72 |= V_74 ;
V_74 = 1 ;
V_73 = V_79 ;
break;
default:
V_72 = V_84 ;
V_73 = F_70 ( V_71 ) ;
if ( V_73 == V_81 )
V_73 = V_79 ;
break;
}
V_69 |= F_71 ( V_72 ) | F_72 ( V_74 ) |
F_73 ( V_73 ) ;
if ( F_63 ( V_71 ) != V_85 )
V_69 |= F_74 ( F_75 ( V_71 ) ) ;
if ( V_83 )
V_6 -> V_86 &= ~ V_63 -> V_87 [ 3 ] ;
F_10 ( V_2 , V_63 -> V_76 ,
V_88 | V_89 , V_69 ) ;
F_10 ( V_2 , V_63 -> V_66 ,
~ ( V_67 | V_90 ) , V_70 ) ;
}
static void F_76 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_71 ,
T_1 V_83 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_69 ;
T_1 V_70 ;
unsigned V_72 , V_73 , V_74 ;
V_69 = F_77 ( F_63 ( V_71 ) ) ;
V_70 = F_27 ( 1 ) | F_30 ( 1 ) ;
V_70 |= F_78 ( F_65 ( V_71 ) ) ;
V_70 |= F_79 ( F_61 ( V_71 ) ) ;
if ( ! V_83 )
V_70 |= F_80 ( F_67 ( V_71 ) ) ;
V_74 = F_68 ( V_71 ) ;
switch ( F_69 ( V_71 ) ) {
case V_78 :
V_72 = V_77 ;
V_72 |= V_74 ;
V_74 = 1 ;
V_73 = V_79 ;
break;
case V_82 :
V_72 = V_77 ;
V_72 |= V_74 ;
V_74 = 1 ;
V_73 = V_81 ;
break;
default:
V_72 = V_84 ;
V_73 = F_70 ( V_71 ) ;
if ( V_73 == V_81 )
V_73 = V_79 ;
break;
}
V_69 |= F_81 ( V_72 ) ;
V_70 |= F_82 ( V_74 ) | F_83 ( V_73 ) ;
if ( F_63 ( V_71 ) != V_85 )
V_70 |= F_84 ( F_75 ( V_71 ) ) ;
if ( V_83 )
V_6 -> V_86 &= ~ V_63 -> V_87 [ 3 ] ;
F_10 ( V_2 , V_63 -> V_76 ,
~ ( V_88 | V_89 ) , V_69 ) ;
F_10 ( V_2 , V_63 -> V_66 ,
V_90 | V_68 , V_70 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_91 )
{
F_10 ( V_2 , V_63 -> V_66 ,
~ ( V_67 | V_90 ) ,
F_64 ( V_91 ) ) ;
}
static void F_86 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_91 )
{
F_10 ( V_2 , V_63 -> V_66 ,
~ ( V_67 | V_92 ) ,
F_78 ( V_91 ) ) ;
}
static T_1 F_87 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_43 ( F_8 ( V_2 , V_63 -> V_66 ) ) ;
}
static T_1 F_88 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_54 ( F_8 ( V_2 , V_63 -> V_66 ) ) ;
}
static T_1 F_89 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_35 ( F_8 ( V_2 , V_63 -> V_66 ) ) ;
}
static void F_90 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_93 )
{
F_10 ( V_2 , V_63 -> V_76 , ~ V_94 ,
F_60 ( V_93 ) ) ;
}
static void F_91 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_93 )
{
F_10 ( V_2 , V_63 -> V_66 ,
~ ( V_95 | V_67 ) ,
F_79 ( V_93 ) ) ;
}
static T_1 F_92 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_33 ( F_8 ( V_2 , V_63 -> V_76 ) ) ;
}
static T_1 F_93 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_52 ( F_8 ( V_2 , V_63 -> V_66 ) ) ;
}
static void F_94 ( struct V_1 * V_2 ,
const struct V_62 * V_63 ,
T_1 V_96 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_10 ( V_2 , V_63 -> V_66 , ~ V_67 ,
( F_27 ( 1 ) |
F_28 ( 1 ) ) ) ;
F_10 ( V_2 , V_63 -> V_76 , ~ V_97 ,
F_66 ( V_96 ) ) ;
V_6 -> V_86 =
( V_6 -> V_86 & ~ V_63 -> V_87 [ 3 ] ) |
V_63 -> V_87 [ V_96 ] ;
}
static void F_95 ( struct V_1 * V_2 ,
const struct V_62 * V_63 ,
T_1 V_96 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_70 ;
V_70 = F_8 ( V_2 , V_63 -> V_66 ) & ~ V_67 ;
F_9 ( V_2 , V_63 -> V_66 , ( V_70 | F_27 ( 1 ) |
F_30 ( 1 ) ) ) ;
F_9 ( V_2 , V_63 -> V_66 , ( ( V_70 & ~ V_98 ) |
F_80 ( V_96 ) ) ) ;
V_6 -> V_86 =
( V_6 -> V_86 & ~ V_63 -> V_87 [ 3 ] ) |
V_63 -> V_87 [ V_96 ] ;
}
static T_1 F_96 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_37 ( F_8 ( V_2 , V_63 -> V_76 ) ) ;
}
static T_1 F_97 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_51 ( F_8 ( V_2 , V_63 -> V_66 ) ) ;
}
static void F_98 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_64 )
{
V_63 -> V_99 ( V_2 , V_63 , ( ( V_63 -> V_100 ( V_2 , V_63 ) & ~ V_101 ) |
F_48 ( V_64 ) ) , false ) ;
}
static T_1 F_99 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_70 ( V_63 -> V_100 ( V_2 , V_63 ) ) ;
}
static void F_100 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_64 )
{
V_63 -> V_99 ( V_2 , V_63 , ( ( V_63 -> V_100 ( V_2 , V_63 ) & ~ V_102 ) |
F_49 ( V_64 ) ) , false ) ;
}
static T_1 F_101 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_68 ( V_63 -> V_100 ( V_2 , V_63 ) ) ;
}
static void F_102 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_64 )
{
V_63 -> V_99 ( V_2 , V_63 , ( ( V_63 -> V_100 ( V_2 , V_63 ) & ~ V_103 ) |
F_47 ( V_64 ) ) , false ) ;
}
static T_1 F_103 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_69 ( V_63 -> V_100 ( V_2 , V_63 ) ) ;
}
static void F_104 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_64 )
{
V_63 -> V_99 ( V_2 , V_63 , ( ( V_63 -> V_100 ( V_2 , V_63 ) & ~ V_104 ) |
F_40 ( V_64 != 0 ) ) , false ) ;
}
static T_1 F_105 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_75 ( V_63 -> V_100 ( V_2 , V_63 ) ) ;
}
static void F_106 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , T_1 V_64 )
{
V_63 -> V_99 ( V_2 , V_63 , ( ( V_63 -> V_100 ( V_2 , V_63 ) & ~ V_105 ) |
F_38 ( V_64 != 0 ) ) , false ) ;
}
static T_1 F_107 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return F_63 ( V_63 -> V_100 ( V_2 , V_63 ) ) ;
}
static void F_108 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
T_1 V_69 ;
V_69 = F_8 ( V_2 , V_63 -> V_76 ) ;
F_9 ( V_2 , V_63 -> V_76 , ( V_69 ^ V_106 ) ) ;
F_9 ( V_2 , V_63 -> V_76 , V_69 ) ;
}
static void F_109 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
T_1 V_70 ;
V_70 = F_8 ( V_2 , V_63 -> V_66 ) & ~ V_67 ;
F_9 ( V_2 , V_63 -> V_66 , ( V_70 ^ V_107 ) ) ;
F_9 ( V_2 , V_63 -> V_66 , V_70 ) ;
}
static unsigned int F_110 ( unsigned int V_108 )
{
return ( ( V_108 >> 18 ) & 0x3fff ) ^ 0x2000 ;
}
static int F_111 ( struct V_1 * V_2 , unsigned int V_46 )
{
unsigned int V_109 = V_46 / 16 ;
unsigned int V_20 = 1 << ( V_46 - ( 16 * V_109 ) ) ;
unsigned int V_110 ;
V_110 = F_8 ( V_2 , F_112 ( V_109 ) ) ;
F_9 ( V_2 , F_113 ( V_109 ) , V_20 | V_110 ) ;
V_110 = F_8 ( V_2 , F_114 ( V_109 ) ) ;
F_9 ( V_2 , F_115 ( V_109 ) , V_20 | V_110 ) ;
F_9 ( V_2 , V_111 , V_112 ) ;
V_110 = F_8 ( V_2 , F_116 ( V_109 ) ) ;
F_9 ( V_2 , F_117 ( V_109 ) , V_20 | V_110 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 , unsigned int V_109 ,
unsigned int V_20 )
{
F_9 ( V_2 , V_111 , V_113 ) ;
F_9 ( V_2 , F_117 ( V_109 ) , V_20 ) ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 )
{
unsigned int V_109 ;
F_9 ( V_2 , V_111 , V_113 ) ;
for ( V_109 = 0 ; V_109 < V_114 ; V_109 ++ )
F_9 ( V_2 , F_117 ( V_109 ) , 0xffff ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 ,
T_1 V_115 , T_3 V_109 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_116 * V_117 = V_2 -> V_118 ;
struct V_119 * V_3 = & V_117 -> V_120 -> V_3 ;
F_118 ( V_2 , V_109 , V_115 ) ;
if ( V_6 -> V_121 ) {
if ( ( V_115 >> ( V_3 -> V_122 - ( 16 * V_109 ) ) ) == 1 &&
V_3 -> V_123 == V_124 ) {
F_1 ( V_2 , V_125 , V_34 ) ;
if ( V_3 -> V_126 == V_124 )
F_111 ( V_2 , V_3 -> V_127 ) ;
}
if ( ( V_115 >> ( V_3 -> V_127 - ( 16 * V_109 ) ) ) == 1 &&
V_3 -> V_126 == V_124 ) {
F_1 ( V_2 , V_128 , V_11 ) ;
if ( V_3 -> V_129 == V_124 ) {
V_6 -> V_130 = V_3 -> V_131 ;
F_111 ( V_2 , V_3 -> V_132 ) ;
}
if ( V_3 -> V_129 == V_133 ) {
const struct V_62 * V_63 =
& V_134 [ 5 ] ;
V_6 -> V_130 = V_3 -> V_131 ;
V_63 -> V_135 ( V_2 , V_63 , V_136 ) ;
}
}
if ( ( V_115 >> ( V_3 -> V_132 - ( 16 * V_109 ) ) ) == 1 &&
V_3 -> V_129 == V_124 ) {
F_1 ( V_2 , V_128 , V_11 ) ;
V_6 -> V_130 -- ;
if ( V_6 -> V_130 > 0 )
F_111 ( V_2 , V_3 -> V_132 ) ;
}
}
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_115 ;
T_3 V_109 ;
for ( V_109 = 0 ; V_109 < V_114 ; V_109 ++ ) {
V_115 = 0 ;
V_115 = F_8 ( V_2 , F_122 ( V_109 ) ) ;
if ( V_115 ) {
F_120 ( V_2 , V_115 , V_109 ) ;
return;
}
}
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_116 * V_117 = V_2 -> V_118 ;
struct V_137 * V_120 = V_117 -> V_120 ;
struct V_119 * V_3 = & V_120 -> V_3 ;
const struct V_62 * V_63 ;
T_1 V_115 ;
V_115 = F_8 ( V_2 , V_138 ) ;
if ( V_115 & V_139 ) {
V_63 = & V_134 [ 0 ] ;
V_63 -> V_140 ( V_2 , V_63 ) ;
}
if ( V_115 & V_141 ) {
V_63 = & V_134 [ 1 ] ;
V_63 -> V_140 ( V_2 , V_63 ) ;
}
if ( V_115 & V_142 ) {
V_63 = & V_134 [ 2 ] ;
V_63 -> V_140 ( V_2 , V_63 ) ;
}
if ( V_115 & V_143 ) {
V_63 = & V_134 [ 3 ] ;
V_63 -> V_140 ( V_2 , V_63 ) ;
}
if ( V_115 & V_144 ) {
V_63 = & V_134 [ 4 ] ;
V_63 -> V_140 ( V_2 , V_63 ) ;
if ( V_6 -> V_130 > 0 ) {
V_6 -> V_130 -- ;
if ( V_6 -> V_130 == 0 )
V_63 -> V_135 ( V_2 , V_63 , V_145 ) ;
if ( V_3 -> V_129 == V_133 ) {
F_1 ( V_2 , V_128 ,
V_11 ) ;
}
}
}
if ( V_115 & V_146 ) {
V_63 = & V_134 [ 5 ] ;
V_63 -> V_140 ( V_2 , V_63 ) ;
if ( V_3 -> V_126 == V_133 ) {
F_1 ( V_2 , V_128 , V_11 ) ;
}
if ( V_3 -> V_129 == V_133 ) {
V_63 = & V_134 [ 4 ] ;
V_6 -> V_130 = V_3 -> V_131 ;
V_63 -> V_135 ( V_2 , V_63 , V_136 ) ;
}
}
}
static bool F_124 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_116 * V_117 = V_2 -> V_118 ;
struct V_137 * V_120 = V_117 -> V_120 ;
struct V_119 * V_3 = & V_120 -> V_3 ;
T_2 * V_147 = ( T_2 * ) V_6 -> V_148 . V_149 + 1 ;
bool V_150 = false ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_3 -> V_131 ; V_60 ++ ) {
unsigned short V_151 ;
V_151 = F_110 ( * V_147 ) ;
V_147 ++ ;
F_125 ( V_117 , V_151 ) ;
}
V_120 -> V_152 |= V_153 ;
if ( ! V_6 -> V_154 )
V_6 -> V_155 -- ;
if ( V_6 -> V_155 <= 0 ) {
V_6 -> V_121 = 0 ;
F_4 ( V_2 , V_125 , V_34 ) ;
V_120 -> V_152 |= V_156 ;
V_150 = true ;
}
if ( V_6 -> V_121 && V_3 -> V_126 == V_124 )
F_111 ( V_2 , V_3 -> V_127 ) ;
F_126 ( V_2 , V_117 ) ;
return V_150 ;
}
static T_5 F_127 ( int V_157 , void * V_158 )
{
struct V_1 * V_2 = V_158 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_159 ;
T_2 V_160 , V_161 ;
if ( ! V_2 -> V_162 )
return V_163 ;
F_128 ( & V_2 -> V_164 , V_159 ) ;
V_161 = F_6 ( V_6 -> V_9 + V_165 ) ;
V_160 = F_6 ( V_6 -> V_9 + V_36 ) ;
F_3 ( 0 , V_6 -> V_9 + V_165 ) ;
F_3 ( V_160 , V_6 -> V_9 + V_36 ) ;
switch ( V_160 ) {
case V_166 :
if ( F_124 ( V_2 ) )
V_161 = 0 ;
break;
case V_167 :
F_121 ( V_2 ) ;
F_123 ( V_2 ) ;
break;
}
F_3 ( V_161 , V_6 -> V_9 + V_165 ) ;
F_129 ( & V_2 -> V_164 , V_159 ) ;
return V_168 ;
}
static void F_130 ( struct V_1 * V_2 , T_3 * V_169 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 * V_170 ;
T_2 V_171 ;
T_1 V_60 ;
T_1 V_172 ;
T_2 V_173 ;
struct V_119 * V_3 = & V_2 -> V_174 -> V_120 -> V_3 ;
F_4 ( V_2 , V_125 , V_34 ) ;
V_170 = ( T_2 * ) V_6 -> V_175 . V_149 ;
F_3 ( ( T_2 ) V_6 -> V_175 . V_176 ,
V_6 -> V_9 + V_177 ) ;
if ( V_3 != NULL && V_3 -> V_126 != V_178 ) {
* V_170 ++ = V_179 | V_180 ;
* V_170 ++ = V_181 | V_180 ;
}
* V_170 ++ = V_182 | ( V_16 >> 2 ) ;
* V_170 ++ = V_19 | V_183 ;
* V_170 ++ = V_182 | ( V_17 >> 2 ) ;
* V_170 ++ = V_184 ;
* V_170 ++ = V_181 | V_185 ;
* V_170 ++ = V_186 | V_185 ;
* V_170 ++ = V_179 | V_185 ;
for ( V_6 -> V_187 = 0 ; V_6 -> V_187 < 16 ;
V_6 -> V_187 ++ ) {
V_173 = ( * V_169 << 8 ) | ( * V_169 & 0x10 ? V_184 :
V_188 ) ;
* V_170 ++ = V_182 | ( V_16 >> 2 ) ;
* V_170 ++ = V_19 | V_183 ;
* V_170 ++ = V_182 | ( V_17 >> 2 ) ;
* V_170 ++ = V_173 ;
* V_170 ++ = V_181 | V_185 ;
* V_170 ++ = V_186 | V_185 ;
* V_170 ++ = V_179 | V_185 ;
* V_170 ++ = V_182 | ( V_16 >> 2 ) ;
* V_170 ++ = V_19 | V_189 ;
* V_170 ++ = V_182 | ( V_17 >> 2 ) ;
* V_170 ++ = V_173 ;
* V_170 ++ = V_181 | V_185 ;
* V_170 ++ = V_186 | V_185 ;
* V_170 ++ = V_179 | V_185 ;
V_171 =
( T_2 ) V_6 -> V_175 . V_176 +
( T_2 ) ( ( unsigned long ) V_170 -
( unsigned long ) V_6 ->
V_175 . V_149 ) ;
for ( V_60 = 0 ; V_60 < ( 10 * V_190 / 2 ) ; V_60 ++ ) {
V_171 += 8 ;
* V_170 ++ = V_191 ;
* V_170 ++ = V_171 ;
}
if ( V_3 != NULL && V_3 -> V_129 != V_192 ) {
* V_170 ++ = V_179 | V_180 ;
* V_170 ++ = V_181 | V_180 ;
}
* V_170 ++ = V_182 | ( V_193 >> 2 ) ;
* V_170 ++ = V_194 | V_195 ;
* V_170 ++ = V_196 ;
* V_170 ++ = V_182 | ( V_193 >> 2 ) ;
* V_170 ++ = V_194 | V_197 ;
* V_170 ++ = V_179 | V_198 ;
* V_170 ++ = V_199 |
( F_131 ( V_200 ) >> 2 ) ;
* V_170 ++ = ( T_2 ) V_6 -> V_148 . V_176 +
( V_6 -> V_187 << 2 ) ;
if ( * V_169 ++ & V_201 ) {
V_6 -> V_187 ++ ;
break;
}
}
for ( V_172 = 0 ; V_172 < ( 2 * V_190 ) ; V_172 ++ )
* V_170 ++ = V_196 ;
* V_170 ++ = V_182 | ( V_193 >> 2 ) ;
* V_170 ++ = V_194 | V_195 ;
* V_170 ++ = V_196 ;
* V_170 ++ = V_182 | ( V_193 >> 2 ) ;
* V_170 ++ = V_194 | V_197 ;
* V_170 ++ = V_179 | V_198 ;
* V_170 ++ = V_199 | ( F_131 ( V_200 ) >> 2 ) ;
* V_170 ++ = ( T_2 ) V_6 -> V_148 . V_176 +
( V_6 -> V_187 << 2 ) ;
if ( V_6 -> V_121 == 1 )
* V_170 ++ = V_202 ;
* V_170 ++ = V_191 ;
* V_170 ++ = ( T_2 ) V_6 -> V_175 . V_176 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
struct V_203 * V_204 ,
unsigned int * V_108 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_60 ;
T_6 * V_147 ;
F_1 ( V_2 , V_128 , V_11 ) ;
while ( F_5 ( V_2 , V_128 , V_11 ) )
;
V_147 = ( T_2 * ) V_6 -> V_148 . V_149 + 1 ;
for ( V_60 = 0 ; V_60 < V_6 -> V_187 ; V_60 ++ ) {
* V_108 = F_110 ( * V_147 ++ ) ;
V_108 ++ ;
}
return V_60 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
struct V_203 * V_204 , unsigned int * V_108 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_46 = F_134 ( V_204 -> V_205 ) ;
T_1 V_206 = F_135 ( V_204 -> V_205 ) ;
T_1 V_207 = 0 ;
T_2 V_208 ;
T_2 V_209 ;
int V_172 ;
if ( V_206 == 0 )
V_207 = ( V_46 << 8 ) | ( V_184 ) ;
else
V_207 = ( V_46 << 8 ) | ( V_188 ) ;
F_9 ( V_2 , V_183 , V_207 ) ;
F_9 ( V_2 , V_189 , V_207 ) ;
for ( V_172 = 0 ; V_172 < V_204 -> V_172 ; V_172 ++ ) {
F_136 ( 10 ) ;
V_208 = F_6 ( V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 & ~ V_197 ,
V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 & ~ V_197 ,
V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 & ~ V_197 ,
V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 | V_197 , V_6 -> V_9 + V_193 ) ;
while ( ! ( F_6 ( V_6 -> V_9 + V_12 ) & V_210 ) )
;
if ( V_172 != 0 ) {
V_209 = F_6 ( V_6 -> V_9 + V_200 ) ;
V_108 [ V_172 - 1 ] = F_110 ( V_209 ) ;
}
F_136 ( 4 ) ;
}
V_208 = F_6 ( V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 & ~ V_197 , V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 & ~ V_197 , V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 & ~ V_197 , V_6 -> V_9 + V_193 ) ;
F_3 ( V_208 | V_197 , V_6 -> V_9 + V_193 ) ;
while ( ! ( F_6 ( V_6 -> V_9 + V_12 ) & V_210 ) )
;
if ( V_172 != 0 ) {
V_209 = F_6 ( V_6 -> V_9 + V_200 ) ;
V_108 [ V_172 - 1 ] = F_110 ( V_209 ) ;
}
return V_172 ;
}
static int F_137 ( T_3 * V_169 , struct V_119 * V_3 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < V_3 -> V_131 ; V_172 ++ ) {
if ( F_135 ( V_3 -> V_211 [ V_172 ] ) == 0 )
V_169 [ V_172 ] = F_134 ( V_3 -> V_211 [ V_172 ] ) | V_212 ;
else
V_169 [ V_172 ] = F_134 ( V_3 -> V_211 [ V_172 ] ) | V_213 ;
}
if ( V_172 != 0 )
V_169 [ V_172 - 1 ] |= V_201 ;
return V_172 ;
}
static int F_138 ( struct V_1 * V_2 ,
struct V_116 * V_117 , unsigned int V_214 )
{
if ( V_214 != 0 )
return - V_215 ;
F_1 ( V_2 , V_125 , V_34 ) ;
V_117 -> V_120 -> V_216 = NULL ;
return 1 ;
}
static int F_139 ( int * V_217 , int V_218 )
{
int V_219 , V_220 ;
V_220 = 500 ;
switch ( V_218 ) {
case V_221 :
default:
V_219 = ( * V_217 + V_220 / 2 ) / V_220 ;
break;
case V_222 :
V_219 = ( * V_217 ) / V_220 ;
break;
case V_223 :
V_219 = ( * V_217 + V_220 - 1 ) / V_220 ;
break;
}
* V_217 = V_220 * V_219 ;
return V_219 - 1 ;
}
static void F_140 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , int V_224 )
{
T_1 V_71 =
F_32 ( V_225 ) |
F_38 ( V_85 ) |
F_47 ( V_78 ) |
F_49 ( V_226 ) |
F_48 ( V_79 ) |
F_42 ( V_145 ) ;
T_1 V_227 = V_228 ;
V_63 -> V_99 ( V_2 , V_63 , V_71 , false ) ;
F_25 ( V_2 , V_63 , V_224 ) ;
V_63 -> V_229 ( V_2 , V_63 , 0 ) ;
V_63 -> V_230 ( V_2 , V_63 ) ;
V_63 -> V_229 ( V_2 , V_63 , 1 ) ;
V_63 -> V_231 ( V_2 , V_63 , V_232 ) ;
F_23 ( V_2 , V_63 , V_227 ) ;
}
static int F_141 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_169 [ 16 ] ;
struct V_119 * V_3 = & V_117 -> V_120 -> V_3 ;
const struct V_62 * V_63 ;
int V_224 ;
if ( V_6 -> V_121 ) {
F_142 ( V_2 -> V_233 ,
L_1 ) ;
return - V_234 ;
}
F_3 ( 0 , V_6 -> V_9 + V_165 ) ;
F_3 ( V_166 | V_167 , V_6 -> V_9 + V_36 ) ;
F_119 ( V_2 ) ;
V_6 -> V_121 = 0 ;
if ( V_3 == NULL )
return - V_215 ;
if ( V_2 -> V_157 == 0 ) {
F_143 ( V_2 ,
L_2 ) ;
return - V_235 ;
}
F_137 ( V_169 , V_3 ) ;
V_6 -> V_121 = 1 ;
V_6 -> V_130 = 0 ;
switch ( V_3 -> V_126 ) {
case V_178 :
break;
case V_133 :
V_63 = & V_134 [ 5 ] ;
V_224 = F_139 ( ( int * ) & V_3 -> V_127 ,
V_3 -> V_159 & V_236 ) ;
F_140 ( V_2 , V_63 , V_224 ) ;
V_63 -> V_135 ( V_2 , V_63 , V_136 ) ;
break;
case V_124 :
if ( V_3 -> V_123 != V_124 )
F_111 ( V_2 , V_3 -> V_127 ) ;
break;
}
switch ( V_3 -> V_129 ) {
case V_192 :
break;
case V_133 :
V_63 = & V_134 [ 4 ] ;
V_224 = F_139 ( ( int * ) & V_3 -> V_132 ,
V_3 -> V_159 & V_236 ) ;
F_140 ( V_2 , V_63 , V_224 ) ;
V_63 -> V_135 ( V_2 , V_63 , V_145 ) ;
break;
case V_124 :
if ( V_3 -> V_126 != V_124 &&
V_3 -> V_123 == V_124 )
F_111 ( V_2 , V_3 -> V_132 ) ;
break;
}
switch ( V_3 -> V_237 ) {
case V_238 :
V_6 -> V_155 = V_3 -> V_239 ;
V_6 -> V_154 = 0 ;
break;
case V_240 :
V_6 -> V_154 = 1 ;
V_6 -> V_155 = 1 ;
break;
}
F_130 ( V_2 , V_169 ) ;
switch ( V_3 -> V_123 ) {
case V_192 :
F_1 ( V_2 , V_125 , V_34 ) ;
V_117 -> V_120 -> V_216 = NULL ;
break;
case V_124 :
F_111 ( V_2 , V_3 -> V_122 ) ;
V_117 -> V_120 -> V_216 = NULL ;
break;
case V_241 :
V_117 -> V_120 -> V_216 = F_138 ;
break;
}
F_3 ( V_167 | V_166 , V_6 -> V_9 + V_165 ) ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_116 * V_117 , struct V_119 * V_3 )
{
int V_242 = 0 ;
int V_209 ;
V_242 |= F_145 ( & V_3 -> V_123 ,
V_192 | V_241 | V_124 ) ;
V_242 |= F_145 ( & V_3 -> V_126 ,
V_133 | V_124 | V_178 ) ;
V_242 |= F_145 ( & V_3 -> V_129 ,
V_133 | V_124 | V_192 ) ;
V_242 |= F_145 ( & V_3 -> V_243 , V_238 ) ;
V_242 |= F_145 ( & V_3 -> V_237 , V_238 | V_240 ) ;
if ( V_242 )
return 1 ;
V_242 |= F_146 ( V_3 -> V_123 ) ;
V_242 |= F_146 ( V_3 -> V_126 ) ;
V_242 |= F_146 ( V_3 -> V_129 ) ;
V_242 |= F_146 ( V_3 -> V_237 ) ;
if ( V_242 )
return 2 ;
if ( V_3 -> V_123 != V_124 )
V_242 |= F_147 ( & V_3 -> V_122 , 0 ) ;
if ( V_3 -> V_123 == V_124 )
V_242 |= F_148 ( & V_3 -> V_122 , 39 ) ;
if ( V_3 -> V_126 == V_124 )
V_242 |= F_148 ( & V_3 -> V_127 , 39 ) ;
if ( V_3 -> V_129 == V_124 )
V_242 |= F_148 ( & V_3 -> V_132 , 39 ) ;
#define F_149 200000
#define F_150 2000000000
if ( V_3 -> V_126 == V_133 ) {
V_242 |= F_151 ( & V_3 -> V_127 ,
F_149 ) ;
V_242 |= F_148 ( & V_3 -> V_127 ,
F_150 ) ;
} else {
}
if ( V_3 -> V_129 == V_133 ) {
V_242 |= F_151 ( & V_3 -> V_132 ,
F_149 ) ;
V_242 |= F_148 ( & V_3 -> V_132 ,
F_150 ) ;
} else {
}
V_242 |= F_147 ( & V_3 -> V_244 , V_3 -> V_131 ) ;
if ( V_3 -> V_237 == V_238 )
V_242 |= F_148 ( & V_3 -> V_239 , 0x00ffffff ) ;
else
V_242 |= F_147 ( & V_3 -> V_239 , 0 ) ;
if ( V_242 )
return 3 ;
if ( V_3 -> V_126 == V_133 ) {
V_209 = V_3 -> V_127 ;
F_139 ( ( int * ) & V_3 -> V_127 ,
V_3 -> V_159 & V_236 ) ;
if ( V_209 != V_3 -> V_127 )
V_242 ++ ;
}
if ( V_3 -> V_129 == V_133 ) {
V_209 = V_3 -> V_132 ;
F_139 ( ( int * ) & V_3 -> V_132 ,
V_3 -> V_159 & V_236 ) ;
if ( V_209 != V_3 -> V_132 )
V_242 ++ ;
if ( V_3 -> V_126 == V_133 &&
V_3 -> V_127 < V_3 -> V_132 *
V_3 -> V_244 ) {
V_3 -> V_127 = V_3 -> V_132 *
V_3 -> V_244 ;
V_242 ++ ;
}
}
if ( V_242 )
return 4 ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( V_2 , V_125 , V_34 ) ;
F_3 ( 0 , V_6 -> V_9 + V_165 ) ;
V_6 -> V_121 = 0 ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 , struct V_116 * V_117 ,
struct V_203 * V_204 , unsigned int * V_108 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_60 ;
T_1 V_46 = F_134 ( V_204 -> V_205 ) ;
T_4 V_47 ;
for ( V_60 = 0 ; V_60 < V_204 -> V_172 ; V_60 ++ ) {
V_47 = ( T_4 ) V_108 [ V_60 ] ;
V_6 -> V_245 [ F_134 ( V_204 -> V_205 ) ] = V_108 [ V_60 ] ;
V_47 -= ( 0x1fff ) ;
F_18 ( V_2 , V_46 , V_47 ) ;
}
return V_60 ;
}
static int F_154 ( struct V_1 * V_2 , struct V_116 * V_117 ,
struct V_203 * V_204 , unsigned int * V_108 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_204 -> V_172 ; V_60 ++ )
V_108 [ V_60 ] = V_6 -> V_245 [ F_134 ( V_204 -> V_205 ) ] ;
return V_60 ;
}
static void F_155 ( struct V_1 * V_2 )
{
T_1 V_109 ;
F_9 ( V_2 , V_111 , V_113 ) ;
for ( V_109 = 0 ; V_109 < V_114 ; V_109 ++ ) {
F_9 ( V_2 , F_115 ( V_109 ) , 0 ) ;
F_9 ( V_2 , F_117 ( V_109 ) , 0xffff ) ;
F_9 ( V_2 , F_113 ( V_109 ) , 0 ) ;
F_9 ( V_2 , F_156 ( V_109 ) , 0 ) ;
}
}
static int F_157 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
struct V_203 * V_204 ,
unsigned int * V_108 )
{
unsigned long V_109 = ( unsigned long ) V_117 -> V_7 ;
if ( F_158 ( V_117 , V_108 ) )
F_9 ( V_2 , F_156 ( V_109 ) , V_117 -> V_246 ) ;
V_108 [ 1 ] = F_8 ( V_2 , F_159 ( V_109 ) ) ;
return V_204 -> V_172 ;
}
static int F_160 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
struct V_203 * V_204 ,
unsigned int * V_108 )
{
unsigned long V_109 = ( unsigned long ) V_117 -> V_7 ;
int V_247 ;
V_247 = F_161 ( V_2 , V_117 , V_204 , V_108 , 0 ) ;
if ( V_247 )
return V_247 ;
F_9 ( V_2 , F_156 ( V_109 ) , V_117 -> V_248 ) ;
return V_204 -> V_172 ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
struct V_203 * V_204 , unsigned int * V_108 )
{
T_1 V_71 =
F_32 ( V_225 ) |
F_38 ( V_85 ) |
F_47 ( V_80 ) |
F_49 ( V_249 ) |
F_48 ( V_79 ) |
F_42 ( V_145 ) ;
T_1 V_227 = V_250 ;
T_1 V_91 = V_136 ;
const struct V_62 * V_63 =
& V_134 [ F_134 ( V_204 -> V_205 ) ] ;
V_63 -> V_99 ( V_2 , V_63 , V_71 , true ) ;
F_25 ( V_2 , V_63 , V_108 [ 0 ] ) ;
V_63 -> V_230 ( V_2 , V_63 ) ;
F_23 ( V_2 , V_63 , V_227 ) ;
V_63 -> V_135 ( V_2 , V_63 , ( V_91 != 0 ) ) ;
return V_204 -> V_172 ;
}
static int F_163 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
struct V_203 * V_204 , unsigned int * V_108 )
{
int V_172 ;
const struct V_62 * V_63 =
& V_134 [ F_134 ( V_204 -> V_205 ) ] ;
for ( V_172 = 0 ; V_172 < V_204 -> V_172 ; V_172 ++ )
V_108 [ V_172 ] = F_22 ( V_2 , V_63 ) ;
return V_172 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_116 * V_117 ,
struct V_203 * V_204 , unsigned int * V_108 )
{
const struct V_62 * V_63 =
& V_134 [ F_134 ( V_204 -> V_205 ) ] ;
F_25 ( V_2 , V_63 , V_108 [ 0 ] ) ;
V_63 -> V_229 ( V_2 , V_63 , 0 ) ;
V_63 -> V_230 ( V_2 , V_63 ) ;
V_63 -> V_229 ( V_2 , V_63 , 2 ) ;
return 1 ;
}
static void F_165 ( struct V_1 * V_2 , T_1 V_251 )
{
F_9 ( V_2 , V_111 , V_252 ) ;
F_9 ( V_2 , V_253 , V_251 ) ;
F_9 ( V_2 , V_111 , V_254 ) ;
}
static void F_166 ( struct V_1 * V_2 ,
struct V_255 * V_256 , T_7 V_257 )
{
struct V_258 * V_259 = F_167 ( V_2 ) ;
void * V_260 ;
T_8 V_261 ;
if ( V_256 == NULL )
return;
V_260 = V_256 -> V_149 ;
V_261 = V_256 -> V_176 ;
if ( V_260 ) {
F_168 ( V_259 , V_257 , V_260 , V_261 ) ;
V_256 -> V_149 = NULL ;
V_256 -> V_176 = 0 ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
int V_46 ;
const struct V_62 * V_63 ;
T_1 V_71 =
F_32 ( V_225 ) |
F_38 ( V_85 ) |
F_47 ( V_80 ) |
F_49 ( V_249 ) |
F_48 ( V_79 ) |
F_42 ( V_145 ) ;
for ( V_46 = 0 ; V_46 < V_262 ; V_46 ++ ) {
V_63 = & V_134 [ V_46 ] ;
V_63 -> V_99 ( V_2 , V_63 , V_71 , true ) ;
V_63 -> V_231 ( V_2 , V_63 , 0 ) ;
V_63 -> V_140 ( V_2 , V_63 ) ;
V_63 -> V_135 ( V_2 , V_63 , V_136 ) ;
}
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_258 * V_259 = F_167 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
void * V_14 ;
T_8 V_263 ;
V_14 = F_171 ( V_259 , V_264 , & V_263 ) ;
if ( ! V_14 )
return - V_265 ;
V_6 -> V_148 . V_149 = V_14 ;
V_6 -> V_148 . V_176 = V_263 ;
V_14 = F_171 ( V_259 , V_264 , & V_263 ) ;
if ( ! V_14 )
return - V_265 ;
V_6 -> V_175 . V_149 = V_14 ;
V_6 -> V_175 . V_176 = V_263 ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_8 V_266 ;
T_1 V_46 ;
int V_60 ;
F_1 ( V_2 , V_267 | V_268 | V_269 ,
V_34 ) ;
F_3 ( V_270 |
( V_271 << V_272 ) | V_273 |
V_274 , V_6 -> V_9 + V_275 ) ;
F_3 ( V_276 , V_6 -> V_9 + V_277 ) ;
F_3 ( V_194 | V_197 , V_6 -> V_9 + V_193 ) ;
V_6 -> V_27 = 0xA0 ;
F_3 ( V_278 | V_279 ,
V_6 -> V_9 + V_280 ) ;
F_1 ( V_2 , V_23 , V_11 ) ;
while ( ! ( F_6 ( V_6 -> V_9 + V_11 ) & V_23 ) )
;
for ( V_60 = 0 ; V_60 < 2 ; V_60 ++ ) {
F_3 ( V_278 , V_6 -> V_9 + V_280 ) ;
F_1 ( V_2 , V_23 , V_11 ) ;
while ( ! F_5 ( V_2 , V_23 , V_11 ) )
;
}
F_3 ( V_281 , V_6 -> V_9 + V_282 ) ;
F_3 ( V_283 | V_284 , V_6 -> V_9 + V_285 ) ;
F_3 ( V_283 | V_284 | V_44 ,
V_6 -> V_9 + V_285 + 4 ) ;
F_3 ( V_286 , V_6 -> V_9 + V_287 ) ;
F_3 ( ( T_2 ) V_6 -> V_175 . V_176 ,
V_6 -> V_9 + V_177 ) ;
F_3 ( 0 , V_6 -> V_9 + V_288 ) ;
F_3 ( 0 , V_6 -> V_9 + V_289 ) ;
#if 0
{
uint8_t poll_list;
uint16_t adc_data;
uint16_t start_val;
uint16_t index;
unsigned int data[16];
poll_list = S626_EOPL;
s626_reset_adc(dev, &poll_list);
s626_ai_rinsn(dev, dev->subdevices, NULL, data);
start_val = data[0];
for (index = 0; index < 500; index++) {
s626_ai_rinsn(dev, dev->subdevices, NULL, data);
adc_data = data[0];
if (adc_data != start_val)
break;
}
}
#endif
F_3 ( 0 , V_6 -> V_9 + V_290 ) ;
V_266 = V_6 -> V_148 . V_176 +
( V_291 * sizeof( T_2 ) ) ;
F_3 ( ( T_2 ) V_266 , V_6 -> V_9 + V_292 ) ;
F_3 ( ( T_2 ) ( V_266 + sizeof( T_2 ) ) ,
V_6 -> V_9 + V_293 ) ;
V_6 -> V_32 = ( T_2 * ) V_6 -> V_148 . V_149 +
V_291 ;
F_3 ( 8 , V_6 -> V_9 + V_294 ) ;
F_3 ( V_37 | V_38 | V_39 | V_44 ,
V_6 -> V_9 + F_17 ( 0 ) ) ;
F_3 ( V_295 , V_6 -> V_9 + F_17 ( 1 ) ) ;
F_3 ( V_296 , V_6 -> V_9 + V_287 ) ;
F_20 ( V_2 ) ;
F_20 ( V_2 ) ;
for ( V_46 = 0 ; V_46 < V_297 ; V_46 ++ )
F_18 ( V_2 , V_46 , 0 ) ;
F_169 ( V_2 ) ;
F_165 ( V_2 , ( F_8 ( V_2 , V_138 ) &
V_298 ) ) ;
F_155 ( V_2 ) ;
}
static int F_173 ( struct V_1 * V_2 ,
unsigned long V_299 )
{
struct V_258 * V_259 = F_167 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_116 * V_117 ;
int V_247 ;
V_6 = F_174 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_265 ;
V_247 = F_175 ( V_2 ) ;
if ( V_247 )
return V_247 ;
V_6 -> V_9 = F_176 ( V_259 , 0 ) ;
if ( ! V_6 -> V_9 )
return - V_265 ;
F_3 ( 0 , V_6 -> V_9 + V_165 ) ;
F_3 ( V_300 , V_6 -> V_9 + V_34 ) ;
V_247 = F_170 ( V_2 ) ;
if ( V_247 )
return V_247 ;
if ( V_259 -> V_157 ) {
V_247 = F_177 ( V_259 -> V_157 , F_127 , V_301 ,
V_2 -> V_302 , V_2 ) ;
if ( V_247 == 0 )
V_2 -> V_157 = V_259 -> V_157 ;
}
V_247 = F_178 ( V_2 , 6 ) ;
if ( V_247 )
return V_247 ;
V_117 = & V_2 -> V_174 [ 0 ] ;
V_117 -> type = V_303 ;
V_117 -> V_304 = V_305 | V_306 | V_307 ;
V_117 -> V_308 = V_309 ;
V_117 -> V_310 = 0x3fff ;
V_117 -> V_311 = & V_312 ;
V_117 -> V_313 = V_309 ;
V_117 -> V_314 = F_133 ;
if ( V_2 -> V_157 ) {
V_2 -> V_118 = V_117 ;
V_117 -> V_315 = F_141 ;
V_117 -> V_316 = F_144 ;
V_117 -> V_317 = F_152 ;
}
V_117 = & V_2 -> V_174 [ 1 ] ;
V_117 -> type = V_318 ;
V_117 -> V_304 = V_319 | V_305 ;
V_117 -> V_308 = V_297 ;
V_117 -> V_310 = 0x3fff ;
V_117 -> V_311 = & V_320 ;
V_117 -> V_321 = F_153 ;
V_117 -> V_314 = F_154 ;
V_117 = & V_2 -> V_174 [ 2 ] ;
V_117 -> type = V_322 ;
V_117 -> V_304 = V_319 | V_305 ;
V_117 -> V_308 = 16 ;
V_117 -> V_310 = 1 ;
V_117 -> V_248 = 0xffff ;
V_117 -> V_7 = ( void * ) 0 ;
V_117 -> V_311 = & V_323 ;
V_117 -> V_324 = F_160 ;
V_117 -> V_325 = F_157 ;
V_117 = & V_2 -> V_174 [ 3 ] ;
V_117 -> type = V_322 ;
V_117 -> V_304 = V_319 | V_305 ;
V_117 -> V_308 = 16 ;
V_117 -> V_310 = 1 ;
V_117 -> V_248 = 0xffff ;
V_117 -> V_7 = ( void * ) 1 ;
V_117 -> V_311 = & V_323 ;
V_117 -> V_324 = F_160 ;
V_117 -> V_325 = F_157 ;
V_117 = & V_2 -> V_174 [ 4 ] ;
V_117 -> type = V_322 ;
V_117 -> V_304 = V_319 | V_305 ;
V_117 -> V_308 = 16 ;
V_117 -> V_310 = 1 ;
V_117 -> V_248 = 0xffff ;
V_117 -> V_7 = ( void * ) 2 ;
V_117 -> V_311 = & V_323 ;
V_117 -> V_324 = F_160 ;
V_117 -> V_325 = F_157 ;
V_117 = & V_2 -> V_174 [ 5 ] ;
V_117 -> type = V_326 ;
V_117 -> V_304 = V_319 | V_305 | V_327 ;
V_117 -> V_308 = V_262 ;
V_117 -> V_310 = 0xffffff ;
V_117 -> V_311 = & V_328 ;
V_117 -> V_324 = F_162 ;
V_117 -> V_314 = F_163 ;
V_117 -> V_321 = F_164 ;
F_172 ( V_2 ) ;
F_179 ( V_2 -> V_233 , L_3 , V_2 -> V_302 ) ;
return 0 ;
}
static void F_180 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 ) {
V_6 -> V_121 = 0 ;
if ( V_6 -> V_9 ) {
F_3 ( 0 , V_6 -> V_9 + V_165 ) ;
F_3 ( V_167 | V_166 ,
V_6 -> V_9 + V_36 ) ;
F_165 ( V_2 , 0 ) ;
F_3 ( V_329 , V_6 -> V_9 + V_34 ) ;
F_3 ( V_330 , V_6 -> V_9 + V_287 ) ;
F_166 ( V_2 , & V_6 -> V_175 ,
V_264 ) ;
F_166 ( V_2 , & V_6 -> V_148 ,
V_264 ) ;
}
if ( V_2 -> V_157 )
F_181 ( V_2 -> V_157 , V_2 ) ;
if ( V_6 -> V_9 )
F_182 ( V_6 -> V_9 ) ;
}
F_183 ( V_2 ) ;
}
static int F_184 ( struct V_258 * V_2 ,
const struct V_331 * V_332 )
{
return F_185 ( V_2 , & V_333 , V_332 -> V_334 ) ;
}
