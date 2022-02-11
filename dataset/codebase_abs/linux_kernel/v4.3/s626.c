static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 = ( V_3 << 16 ) | V_3 ;
F_2 () ;
F_3 ( V_5 , V_2 -> V_6 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
F_3 ( V_3 << 16 , V_2 -> V_6 + V_4 ) ;
F_2 () ;
}
static bool F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = F_6 ( V_2 -> V_6 + V_4 ) ;
return ( V_5 & V_3 ) ? true : false ;
}
static void F_7 ( struct V_1 * V_2 )
{
static const int V_7 = 10000 ;
int V_8 ;
F_1 ( V_2 , V_9 , V_10 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( F_5 ( V_2 , V_9 , V_10 ) )
break;
F_8 ( 1 ) ;
}
if ( V_8 == V_7 )
F_9 ( V_2 -> V_11 ,
L_1 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ ) {
if ( ! ( F_6 ( V_2 -> V_6 + V_12 ) & V_13 ) )
break;
F_8 ( 1 ) ;
}
if ( V_8 == V_7 )
F_9 ( V_2 -> V_11 , L_2 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , T_1 V_14 )
{
F_3 ( V_15 | V_14 , V_2 -> V_6 + V_16 ) ;
F_7 ( V_2 ) ;
return F_6 ( V_2 -> V_6 + V_17 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_14 ,
T_1 V_18 )
{
F_3 ( V_19 | V_14 , V_2 -> V_6 + V_16 ) ;
F_3 ( V_18 , V_2 -> V_6 + V_17 ) ;
F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_20 , unsigned int V_18 )
{
unsigned int V_5 ;
V_14 &= 0xffff ;
F_3 ( V_15 | V_14 , V_2 -> V_6 + V_16 ) ;
F_7 ( V_2 ) ;
F_3 ( V_19 | V_14 , V_2 -> V_6 + V_16 ) ;
V_5 = F_6 ( V_2 -> V_6 + V_17 ) ;
V_5 &= V_20 ;
V_5 |= V_18 ;
F_3 ( V_5 & 0xffff , V_2 -> V_6 + V_17 ) ;
F_7 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
bool V_26 ;
V_26 = F_5 ( V_2 , V_27 , V_10 ) ;
if ( V_26 )
return 0 ;
return - V_28 ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_5 )
{
unsigned int V_29 ;
int V_30 ;
F_3 ( V_5 , V_2 -> V_6 + V_31 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
do {
V_29 = F_6 ( V_2 -> V_6 + V_31 ) ;
} while ( ( V_29 & ( V_32 | V_33 ) ) == V_32 );
return V_29 & V_33 ;
}
static T_3 F_16 ( struct V_1 * V_2 , T_3 V_14 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
if ( F_14 ( V_2 , F_17 ( V_37 ,
V_35 -> V_38 ) |
F_18 ( V_39 , V_14 ) |
F_19 ( V_40 , 0 ) ) )
return 0 ;
if ( F_14 ( V_2 , F_17 ( V_37 ,
( V_35 -> V_38 | 1 ) ) |
F_18 ( V_39 , 0 ) |
F_19 ( V_40 , 0 ) ) )
return 0 ;
return ( F_6 ( V_2 -> V_6 + V_31 ) >> 16 ) & 0xff ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_26 ;
switch ( V_25 ) {
case V_41 :
V_26 = F_6 ( V_2 -> V_6 + V_42 ) ;
if ( ! ( V_26 & V_43 ) )
return 0 ;
break;
case V_44 :
V_26 = F_6 ( V_2 -> V_6 + V_45 ) ;
if ( V_26 & V_46 )
return 0 ;
break;
case V_47 :
V_26 = F_6 ( V_2 -> V_6 + V_48 ) ;
if ( ! ( V_26 & 0xff000000 ) )
return 0 ;
break;
case V_49 :
V_26 = F_6 ( V_2 -> V_6 + V_48 ) ;
if ( V_26 & 0xff000000 )
return 0 ;
break;
default:
return - V_50 ;
}
return - V_28 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_5 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
int V_30 ;
F_11 ( V_2 , V_51 , V_35 -> V_52 ) ;
* V_35 -> V_53 = V_5 ;
F_1 ( V_2 , V_43 , V_42 ) ;
F_3 ( V_54 , V_2 -> V_6 + V_55 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_41 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 , L_3 ) ;
return V_30 ;
}
F_3 ( V_56 | V_57 | V_58 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_44 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 ,
L_4 ) ;
return V_30 ;
}
F_3 ( V_56 | V_59 | V_60 | V_58 | V_61 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
if ( F_6 ( V_2 -> V_6 + V_48 ) & 0xff000000 ) {
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_47 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 ,
L_5 ) ;
return V_30 ;
}
}
F_3 ( V_57 | V_58 | V_61 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_20 ,
V_49 ) ;
if ( V_30 ) {
F_9 ( V_2 -> V_11 ,
L_5 ) ;
return V_30 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 V_62 , T_4 V_63 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_64 ;
T_2 V_65 ;
T_2 V_5 ;
V_64 = 1 << V_62 ;
if ( V_63 < 0 ) {
V_63 = - V_63 ;
V_35 -> V_52 |= V_64 ;
} else {
V_35 -> V_52 &= ~ V_64 ;
}
if ( ( T_1 ) V_63 > 0x1FFF )
V_63 = 0x1FFF ;
V_65 = ( V_62 & 2 ) ? V_66 : V_67 ;
F_3 ( V_56 | V_68 | V_65 ,
V_2 -> V_6 + F_22 ( 2 ) ) ;
F_3 ( V_56 | V_69 | V_65 ,
V_2 -> V_6 + F_22 ( 3 ) ) ;
F_3 ( V_56 | V_70 | V_71 ,
V_2 -> V_6 + F_22 ( 4 ) ) ;
F_3 ( V_56 | V_59 | V_71 | V_61 ,
V_2 -> V_6 + F_22 ( 5 ) ) ;
V_5 = 0x0F000000 ;
V_5 |= 0x00004000 ;
V_5 |= ( ( T_2 ) ( V_62 & 1 ) << 15 ) ;
V_5 |= ( T_2 ) V_63 ;
return F_21 ( V_2 , V_5 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
T_3 V_72 , T_3 V_73 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_2 V_62 ;
V_35 -> V_74 [ V_72 ] = ( T_3 ) V_73 ;
V_62 = V_75 [ V_72 ] ;
F_3 ( V_56 | V_68 | V_71 ,
V_2 -> V_6 + F_22 ( 2 ) ) ;
F_3 ( V_56 | V_69 | V_71 ,
V_2 -> V_6 + F_22 ( 3 ) ) ;
F_3 ( V_56 | V_70 | V_66 ,
V_2 -> V_6 + F_22 ( 4 ) ) ;
F_3 ( V_56 | V_59 | V_66 | V_61 ,
V_2 -> V_6 + F_22 ( 5 ) ) ;
return F_21 ( V_2 , ( V_62 << 8 ) | V_73 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_3 V_8 ;
int V_30 ;
for ( V_8 = 0 ; V_8 < F_26 ( V_75 ) ; V_8 ++ ) {
V_30 = F_24 ( V_2 , V_8 ,
F_16 ( V_2 , V_76 [ V_8 ] ) ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
F_12 ( V_2 , F_28 ( V_62 ) ,
~ ( V_78 | V_79 ) ,
F_29 ( V_77 ) ) ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned int V_62 , T_2 V_77 )
{
F_11 ( V_2 , F_31 ( V_62 ) , V_77 ) ;
F_11 ( V_2 , F_31 ( V_62 ) + 2 , V_77 >> 16 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
T_1 V_80 ;
V_80 = F_33 ( 1 ) ;
if ( V_62 < 3 )
V_80 |= F_34 ( 1 ) ;
else
V_80 |= F_35 ( 1 ) ;
F_12 ( V_2 , F_28 ( V_62 ) , ~ V_78 , V_80 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
T_1 V_81 ;
T_1 V_82 ;
T_1 V_83 ;
unsigned V_84 , V_85 , V_86 , V_87 ;
V_81 = F_10 ( V_2 , F_37 ( V_62 ) ) ;
V_82 = F_10 ( V_2 , F_28 ( V_62 ) ) ;
V_83 =
F_38 ( F_39 ( V_81 ) ) |
F_40 ( F_41 ( V_82 ) ) |
F_42 ( F_43 ( V_81 ) ) |
F_44 ( F_45 ( V_81 ) ) |
F_46 ( F_47 ( V_81 ) ) |
F_48 ( F_49 ( V_82 ) ) ;
V_84 = F_50 ( V_81 ) ;
if ( V_84 & V_88 ) {
V_87 = V_89 ;
V_86 = V_84 & 1 ;
V_85 = V_90 ;
} else {
V_87 = V_91 ;
V_86 = F_51 ( V_81 ) ;
V_85 = F_52 ( V_81 ) ;
if ( V_85 == V_92 )
V_85 = V_90 ;
}
V_83 |= F_53 ( V_87 ) | F_54 ( V_85 ) |
F_55 ( V_86 ) ;
return V_83 ;
}
static T_1 F_56 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
T_1 V_81 ;
T_1 V_82 ;
T_1 V_83 ;
unsigned V_84 , V_85 , V_86 , V_87 ;
V_81 = F_10 ( V_2 , F_37 ( V_62 ) ) ;
V_82 = F_10 ( V_2 , F_28 ( V_62 ) ) ;
V_83 =
F_42 ( F_57 ( V_82 ) ) |
F_40 ( F_41 ( V_82 ) ) |
F_38 ( F_58 ( V_82 ) ) |
F_46 ( F_59 ( V_82 ) ) |
F_48 ( F_60 ( V_82 ) ) |
F_44 ( F_61 ( V_81 ) ) ;
V_84 = F_62 ( V_81 ) ;
V_85 = F_63 ( V_82 ) ;
if ( V_85 == V_92 ) {
V_87 = V_93 ;
V_85 = V_90 ;
V_86 = V_84 & 1 ;
} else if ( V_84 & V_88 ) {
V_87 = V_89 ;
V_85 = V_90 ;
V_86 = V_84 & 1 ;
} else {
V_87 = V_91 ;
V_86 = F_64 ( V_82 ) ;
}
V_83 |= F_53 ( V_87 ) | F_54 ( V_85 ) |
F_55 ( V_86 ) ;
return V_83 ;
}
static T_1 F_65 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return ( V_62 < 3 ) ? F_36 ( V_2 , V_62 )
: F_56 ( V_2 , V_62 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_83 ,
T_1 V_94 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_81 ;
T_1 V_82 ;
unsigned V_84 , V_85 , V_86 ;
V_81 = F_67 ( F_68 ( V_83 ) ) ;
V_81 |= F_69 ( F_70 ( V_83 ) ) ;
V_82 = F_33 ( 1 ) | F_34 ( 1 ) ;
V_82 |= F_71 ( F_72 ( V_83 ) ) ;
if ( ! V_94 )
V_81 |= F_73 ( F_74 ( V_83 ) ) ;
V_86 = F_75 ( V_83 ) ;
switch ( F_76 ( V_83 ) ) {
case V_93 :
case V_89 :
V_84 = V_88 ;
V_84 |= V_86 ;
V_86 = 1 ;
V_85 = V_90 ;
break;
default:
V_84 = V_95 ;
V_85 = F_77 ( V_83 ) ;
if ( V_85 == V_92 )
V_85 = V_90 ;
break;
}
V_81 |= F_78 ( V_84 ) | F_79 ( V_86 ) |
F_80 ( V_85 ) ;
if ( F_70 ( V_83 ) != V_96 )
V_81 |= F_81 ( F_82 ( V_83 ) ) ;
if ( V_94 )
V_35 -> V_97 &= ~ ( F_83 ( V_62 ) |
F_84 ( V_62 ) ) ;
F_12 ( V_2 , F_37 ( V_62 ) ,
V_98 | V_99 , V_81 ) ;
F_12 ( V_2 , F_28 ( V_62 ) ,
~ ( V_78 | V_100 ) , V_82 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_83 ,
T_1 V_94 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_81 ;
T_1 V_82 ;
unsigned V_84 , V_85 , V_86 ;
V_81 = F_86 ( F_70 ( V_83 ) ) ;
V_82 = F_33 ( 1 ) | F_35 ( 1 ) ;
V_82 |= F_87 ( F_72 ( V_83 ) ) ;
V_82 |= F_88 ( F_68 ( V_83 ) ) ;
if ( ! V_94 )
V_82 |= F_89 ( F_74 ( V_83 ) ) ;
V_86 = F_75 ( V_83 ) ;
switch ( F_76 ( V_83 ) ) {
case V_89 :
V_84 = V_88 ;
V_84 |= V_86 ;
V_86 = 1 ;
V_85 = V_90 ;
break;
case V_93 :
V_84 = V_88 ;
V_84 |= V_86 ;
V_86 = 1 ;
V_85 = V_92 ;
break;
default:
V_84 = V_95 ;
V_85 = F_77 ( V_83 ) ;
if ( V_85 == V_92 )
V_85 = V_90 ;
break;
}
V_81 |= F_90 ( V_84 ) ;
V_82 |= F_91 ( V_86 ) | F_92 ( V_85 ) ;
if ( F_70 ( V_83 ) != V_96 )
V_82 |= F_93 ( F_82 ( V_83 ) ) ;
if ( V_94 )
V_35 -> V_97 &= ~ ( F_83 ( V_62 ) |
F_84 ( V_62 ) ) ;
F_12 ( V_2 , F_37 ( V_62 ) ,
~ ( V_98 | V_99 ) , V_81 ) ;
F_12 ( V_2 , F_28 ( V_62 ) ,
V_100 | V_79 , V_82 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
unsigned int V_62 ,
T_1 V_83 , T_1 V_94 )
{
if ( V_62 < 3 )
F_66 ( V_2 , V_62 , V_83 , V_94 ) ;
else
F_85 ( V_2 , V_62 , V_83 , V_94 ) ;
}
static void F_95 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_101 )
{
unsigned int V_20 = V_78 ;
unsigned int V_80 ;
if ( V_62 < 3 ) {
V_20 |= V_100 ;
V_80 = F_71 ( V_101 ) ;
} else {
V_20 |= V_102 ;
V_80 = F_87 ( V_101 ) ;
}
F_12 ( V_2 , F_28 ( V_62 ) , ~ V_20 , V_80 ) ;
}
static T_1 F_96 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
T_1 V_82 = F_10 ( V_2 , F_28 ( V_62 ) ) ;
return ( V_62 < 3 ) ? F_49 ( V_82 )
: F_60 ( V_82 ) ;
}
static T_1 F_97 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_41 ( F_10 ( V_2 , F_28 ( V_62 ) ) ) ;
}
static void F_98 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_103 )
{
T_1 V_4 ;
T_1 V_20 ;
T_1 V_80 ;
if ( V_62 < 3 ) {
V_4 = F_37 ( V_62 ) ;
V_20 = V_104 ;
V_80 = F_67 ( V_103 ) ;
} else {
V_4 = F_28 ( V_62 ) ;
V_20 = V_105 | V_78 ;
V_80 = F_88 ( V_103 ) ;
}
F_12 ( V_2 , V_4 , ~ V_20 , V_80 ) ;
}
static T_1 F_99 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
if ( V_62 < 3 )
return F_39 ( F_10 ( V_2 ,
F_37 ( V_62 ) ) ) ;
else
return F_58 ( F_10 ( V_2 ,
F_28 ( V_62 ) ) ) ;
}
static void F_100 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_106 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_1 V_107 = F_37 ( V_62 ) ;
T_1 V_108 = F_28 ( V_62 ) ;
if ( V_62 < 3 ) {
F_12 ( V_2 , V_108 , ~ V_78 ,
F_33 ( 1 ) |
F_34 ( 1 ) ) ;
F_12 ( V_2 , V_107 , ~ V_109 ,
F_73 ( V_106 ) ) ;
} else {
T_1 V_82 ;
V_82 = F_10 ( V_2 , V_108 ) ;
V_82 &= ~ V_78 ;
F_11 ( V_2 , V_108 ,
V_82 | F_33 ( 1 ) |
F_35 ( 1 ) ) ;
F_11 ( V_2 , V_108 ,
( V_82 & ~ V_110 ) |
F_89 ( V_106 ) ) ;
}
V_35 -> V_97 &= ~ ( F_83 ( V_62 ) |
F_84 ( V_62 ) ) ;
switch ( V_106 ) {
case 0 :
default:
break;
case 1 :
V_35 -> V_97 |= F_83 ( V_62 ) ;
break;
case 2 :
V_35 -> V_97 |= F_84 ( V_62 ) ;
break;
case 3 :
V_35 -> V_97 |= ( F_83 ( V_62 ) |
F_84 ( V_62 ) ) ;
break;
}
}
static T_1 F_101 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
if ( V_62 < 3 )
return F_43 ( F_10 ( V_2 ,
F_37 ( V_62 ) ) ) ;
else
return F_57 ( F_10 ( V_2 ,
F_28 ( V_62 ) ) ) ;
}
static void F_102 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_112 ;
V_111 |= F_54 ( V_77 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static T_1 F_103 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_77 ( F_65 ( V_2 , V_62 ) ) ;
}
static void F_104 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_113 ;
V_111 |= F_55 ( V_77 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static T_1 F_105 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_75 ( F_65 ( V_2 , V_62 ) ) ;
}
static void F_106 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_114 ;
V_111 |= F_53 ( V_77 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static T_1 F_107 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_76 ( F_65 ( V_2 , V_62 ) ) ;
}
static void F_108 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_115 ;
V_111 |= F_46 ( V_77 != 0 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static T_1 F_109 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_82 ( F_65 ( V_2 , V_62 ) ) ;
}
static void F_110 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_116 ;
V_111 |= F_44 ( V_77 != 0 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static T_1 F_111 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_70 ( F_65 ( V_2 , V_62 ) ) ;
}
static void F_112 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
if ( V_62 < 3 ) {
T_1 V_81 ;
V_81 = F_10 ( V_2 , F_37 ( V_62 ) ) ;
F_11 ( V_2 , F_37 ( V_62 ) ,
( V_81 ^ V_117 ) ) ;
F_11 ( V_2 , F_37 ( V_62 ) , V_81 ) ;
} else {
T_1 V_82 ;
V_82 = F_10 ( V_2 , F_28 ( V_62 ) ) ;
V_82 &= ~ V_78 ;
F_11 ( V_2 , F_28 ( V_62 ) ,
( V_82 ^ V_118 ) ) ;
F_11 ( V_2 , F_28 ( V_62 ) , V_82 ) ;
}
}
static unsigned int F_113 ( unsigned int V_119 )
{
return ( ( V_119 >> 18 ) & 0x3fff ) ^ 0x2000 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned int V_120 = V_62 / 16 ;
unsigned int V_20 = 1 << ( V_62 - ( 16 * V_120 ) ) ;
unsigned int V_26 ;
V_26 = F_10 ( V_2 , F_115 ( V_120 ) ) ;
F_11 ( V_2 , F_116 ( V_120 ) , V_20 | V_26 ) ;
V_26 = F_10 ( V_2 , F_117 ( V_120 ) ) ;
F_11 ( V_2 , F_118 ( V_120 ) , V_20 | V_26 ) ;
F_11 ( V_2 , V_121 , V_122 ) ;
V_26 = F_10 ( V_2 , F_119 ( V_120 ) ) ;
F_11 ( V_2 , F_120 ( V_120 ) , V_20 | V_26 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , unsigned int V_120 ,
unsigned int V_20 )
{
F_11 ( V_2 , V_121 , V_123 ) ;
F_11 ( V_2 , F_120 ( V_120 ) , V_20 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
unsigned int V_120 ;
F_11 ( V_2 , V_121 , V_123 ) ;
for ( V_120 = 0 ; V_120 < V_124 ; V_120 ++ )
F_11 ( V_2 , F_120 ( V_120 ) , 0xffff ) ;
return 0 ;
}
static void F_123 ( struct V_1 * V_2 ,
T_1 V_125 , T_3 V_120 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_126 ;
struct V_127 * V_3 = & V_22 -> V_128 -> V_3 ;
F_121 ( V_2 , V_120 , V_125 ) ;
if ( V_35 -> V_129 ) {
if ( ( V_125 >> ( V_3 -> V_130 - ( 16 * V_120 ) ) ) == 1 &&
V_3 -> V_131 == V_132 ) {
F_1 ( V_2 , V_133 , V_42 ) ;
if ( V_3 -> V_134 == V_132 )
F_114 ( V_2 , V_3 -> V_135 ) ;
}
if ( ( V_125 >> ( V_3 -> V_135 - ( 16 * V_120 ) ) ) == 1 &&
V_3 -> V_134 == V_132 ) {
F_1 ( V_2 , V_136 , V_10 ) ;
if ( V_3 -> V_137 == V_132 ) {
V_35 -> V_138 = V_3 -> V_139 ;
F_114 ( V_2 , V_3 -> V_140 ) ;
}
if ( V_3 -> V_137 == V_141 ) {
V_35 -> V_138 = V_3 -> V_139 ;
F_95 ( V_2 , 5 , V_142 ) ;
}
}
if ( ( V_125 >> ( V_3 -> V_140 - ( 16 * V_120 ) ) ) == 1 &&
V_3 -> V_137 == V_132 ) {
F_1 ( V_2 , V_136 , V_10 ) ;
V_35 -> V_138 -- ;
if ( V_35 -> V_138 > 0 )
F_114 ( V_2 , V_3 -> V_140 ) ;
}
}
}
static void F_124 ( struct V_1 * V_2 )
{
T_1 V_125 ;
T_3 V_120 ;
for ( V_120 = 0 ; V_120 < V_124 ; V_120 ++ ) {
V_125 = F_10 ( V_2 , F_125 ( V_120 ) ) ;
if ( V_125 ) {
F_123 ( V_2 , V_125 , V_120 ) ;
return;
}
}
}
static void F_126 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_126 ;
struct V_143 * V_128 = V_22 -> V_128 ;
struct V_127 * V_3 = & V_128 -> V_3 ;
T_1 V_125 ;
V_125 = F_10 ( V_2 , V_144 ) ;
if ( V_125 & V_145 ) {
F_32 ( V_2 , 0 ) ;
}
if ( V_125 & V_146 ) {
F_32 ( V_2 , 1 ) ;
}
if ( V_125 & V_147 ) {
F_32 ( V_2 , 2 ) ;
}
if ( V_125 & V_148 ) {
F_32 ( V_2 , 3 ) ;
}
if ( V_125 & V_149 ) {
F_32 ( V_2 , 4 ) ;
if ( V_35 -> V_138 > 0 ) {
V_35 -> V_138 -- ;
if ( V_35 -> V_138 == 0 )
F_95 ( V_2 , 4 , V_150 ) ;
if ( V_3 -> V_137 == V_141 ) {
F_1 ( V_2 , V_136 ,
V_10 ) ;
}
}
}
if ( V_125 & V_151 ) {
F_32 ( V_2 , 5 ) ;
if ( V_3 -> V_134 == V_141 ) {
F_1 ( V_2 , V_136 , V_10 ) ;
}
if ( V_3 -> V_137 == V_141 ) {
V_35 -> V_138 = V_3 -> V_139 ;
F_95 ( V_2 , 4 , V_142 ) ;
}
}
}
static bool F_127 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_126 ;
struct V_143 * V_128 = V_22 -> V_128 ;
struct V_127 * V_3 = & V_128 -> V_3 ;
T_2 * V_152 = ( T_2 * ) V_35 -> V_153 . V_154 + 1 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_139 ; V_8 ++ ) {
unsigned short V_155 ;
V_155 = F_113 ( * V_152 ) ;
V_152 ++ ;
F_128 ( V_22 , & V_155 , 1 ) ;
}
if ( V_3 -> V_156 == V_157 && V_128 -> V_158 >= V_3 -> V_159 )
V_128 -> V_160 |= V_161 ;
if ( V_128 -> V_160 & V_162 )
V_35 -> V_129 = 0 ;
if ( V_35 -> V_129 && V_3 -> V_134 == V_132 )
F_114 ( V_2 , V_3 -> V_135 ) ;
F_129 ( V_2 , V_22 ) ;
return ! V_35 -> V_129 ;
}
static T_5 F_130 ( int V_163 , void * V_164 )
{
struct V_1 * V_2 = V_164 ;
unsigned long V_165 ;
T_2 V_166 , V_167 ;
if ( ! V_2 -> V_168 )
return V_169 ;
F_131 ( & V_2 -> V_170 , V_165 ) ;
V_167 = F_6 ( V_2 -> V_6 + V_171 ) ;
V_166 = F_6 ( V_2 -> V_6 + V_55 ) ;
F_3 ( 0 , V_2 -> V_6 + V_171 ) ;
F_3 ( V_166 , V_2 -> V_6 + V_55 ) ;
switch ( V_166 ) {
case V_172 :
if ( F_127 ( V_2 ) )
V_167 = 0 ;
break;
case V_173 :
F_124 ( V_2 ) ;
F_126 ( V_2 ) ;
break;
}
F_3 ( V_167 , V_2 -> V_6 + V_171 ) ;
F_132 ( & V_2 -> V_170 , V_165 ) ;
return V_174 ;
}
static void F_133 ( struct V_1 * V_2 , T_3 * V_175 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_126 ;
struct V_127 * V_3 = & V_22 -> V_128 -> V_3 ;
T_2 * V_176 ;
T_2 V_177 ;
T_1 V_8 ;
T_1 V_178 ;
T_2 V_179 ;
F_4 ( V_2 , V_133 , V_42 ) ;
V_176 = ( T_2 * ) V_35 -> V_180 . V_154 ;
F_3 ( ( T_2 ) V_35 -> V_180 . V_181 ,
V_2 -> V_6 + V_182 ) ;
if ( V_3 -> V_134 != V_183 ) {
* V_176 ++ = V_184 | V_185 ;
* V_176 ++ = V_186 | V_185 ;
}
* V_176 ++ = V_187 | ( V_16 >> 2 ) ;
* V_176 ++ = V_19 | V_188 ;
* V_176 ++ = V_187 | ( V_17 >> 2 ) ;
* V_176 ++ = V_189 ;
* V_176 ++ = V_186 | V_190 ;
* V_176 ++ = V_191 | V_190 ;
* V_176 ++ = V_184 | V_190 ;
for ( V_35 -> V_192 = 0 ; V_35 -> V_192 < 16 ;
V_35 -> V_192 ++ ) {
V_179 = ( * V_175 << 8 ) | ( * V_175 & 0x10 ? V_189 :
V_193 ) ;
* V_176 ++ = V_187 | ( V_16 >> 2 ) ;
* V_176 ++ = V_19 | V_188 ;
* V_176 ++ = V_187 | ( V_17 >> 2 ) ;
* V_176 ++ = V_179 ;
* V_176 ++ = V_186 | V_190 ;
* V_176 ++ = V_191 | V_190 ;
* V_176 ++ = V_184 | V_190 ;
* V_176 ++ = V_187 | ( V_16 >> 2 ) ;
* V_176 ++ = V_19 | V_194 ;
* V_176 ++ = V_187 | ( V_17 >> 2 ) ;
* V_176 ++ = V_179 ;
* V_176 ++ = V_186 | V_190 ;
* V_176 ++ = V_191 | V_190 ;
* V_176 ++ = V_184 | V_190 ;
V_177 =
( T_2 ) V_35 -> V_180 . V_181 +
( T_2 ) ( ( unsigned long ) V_176 -
( unsigned long ) V_35 ->
V_180 . V_154 ) ;
for ( V_8 = 0 ; V_8 < ( 10 * V_195 / 2 ) ; V_8 ++ ) {
V_177 += 8 ;
* V_176 ++ = V_196 ;
* V_176 ++ = V_177 ;
}
if ( V_3 -> V_137 != V_197 ) {
* V_176 ++ = V_184 | V_185 ;
* V_176 ++ = V_186 | V_185 ;
}
* V_176 ++ = V_187 | ( V_198 >> 2 ) ;
* V_176 ++ = V_199 | V_200 ;
* V_176 ++ = V_201 ;
* V_176 ++ = V_187 | ( V_198 >> 2 ) ;
* V_176 ++ = V_199 | V_202 ;
* V_176 ++ = V_184 | V_203 ;
* V_176 ++ = V_204 |
( F_134 ( V_205 ) >> 2 ) ;
* V_176 ++ = ( T_2 ) V_35 -> V_153 . V_181 +
( V_35 -> V_192 << 2 ) ;
if ( * V_175 ++ & V_206 ) {
V_35 -> V_192 ++ ;
break;
}
}
for ( V_178 = 0 ; V_178 < ( 2 * V_195 ) ; V_178 ++ )
* V_176 ++ = V_201 ;
* V_176 ++ = V_187 | ( V_198 >> 2 ) ;
* V_176 ++ = V_199 | V_200 ;
* V_176 ++ = V_201 ;
* V_176 ++ = V_187 | ( V_198 >> 2 ) ;
* V_176 ++ = V_199 | V_202 ;
* V_176 ++ = V_184 | V_203 ;
* V_176 ++ = V_204 | ( F_134 ( V_205 ) >> 2 ) ;
* V_176 ++ = ( T_2 ) V_35 -> V_153 . V_181 +
( V_35 -> V_192 << 2 ) ;
if ( V_35 -> V_129 == 1 )
* V_176 ++ = V_207 ;
* V_176 ++ = V_196 ;
* V_176 ++ = ( T_2 ) V_35 -> V_180 . V_181 ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_119 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_3 V_8 ;
T_6 * V_152 ;
F_1 ( V_2 , V_136 , V_10 ) ;
while ( F_5 ( V_2 , V_136 , V_10 ) )
;
V_152 = ( T_2 * ) V_35 -> V_153 . V_154 + 1 ;
for ( V_8 = 0 ; V_8 < V_35 -> V_192 ; V_8 ++ ) {
* V_119 = F_113 ( * V_152 ++ ) ;
V_119 ++ ;
}
return V_8 ;
}
static int F_136 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_26 ;
V_26 = F_6 ( V_2 -> V_6 + V_12 ) ;
if ( V_26 & V_208 )
return 0 ;
return - V_28 ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_119 )
{
T_1 V_62 = F_138 ( V_24 -> V_209 ) ;
T_1 V_210 = F_139 ( V_24 -> V_209 ) ;
T_1 V_211 = 0 ;
T_2 V_212 ;
T_2 V_213 ;
int V_30 ;
int V_178 ;
if ( V_210 == 0 )
V_211 = ( V_62 << 8 ) | ( V_189 ) ;
else
V_211 = ( V_62 << 8 ) | ( V_193 ) ;
F_11 ( V_2 , V_188 , V_211 ) ;
F_11 ( V_2 , V_194 , V_211 ) ;
for ( V_178 = 0 ; V_178 < V_24 -> V_178 ; V_178 ++ ) {
F_8 ( 10 ) ;
V_212 = F_6 ( V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 & ~ V_202 , V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 & ~ V_202 , V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 & ~ V_202 , V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 | V_202 , V_2 -> V_6 + V_198 ) ;
V_30 = F_15 ( V_2 , V_22 , V_24 , F_136 , 0 ) ;
if ( V_30 )
return V_30 ;
if ( V_178 != 0 ) {
V_213 = F_6 ( V_2 -> V_6 + V_205 ) ;
V_119 [ V_178 - 1 ] = F_113 ( V_213 ) ;
}
F_8 ( 4 ) ;
}
V_212 = F_6 ( V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 & ~ V_202 , V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 & ~ V_202 , V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 & ~ V_202 , V_2 -> V_6 + V_198 ) ;
F_3 ( V_212 | V_202 , V_2 -> V_6 + V_198 ) ;
V_30 = F_15 ( V_2 , V_22 , V_24 , F_136 , 0 ) ;
if ( V_30 )
return V_30 ;
if ( V_178 != 0 ) {
V_213 = F_6 ( V_2 -> V_6 + V_205 ) ;
V_119 [ V_178 - 1 ] = F_113 ( V_213 ) ;
}
return V_178 ;
}
static int F_140 ( T_3 * V_175 , struct V_127 * V_3 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < V_3 -> V_139 ; V_178 ++ ) {
if ( F_139 ( V_3 -> V_214 [ V_178 ] ) == 0 )
V_175 [ V_178 ] = F_138 ( V_3 -> V_214 [ V_178 ] ) | V_215 ;
else
V_175 [ V_178 ] = F_138 ( V_3 -> V_214 [ V_178 ] ) | V_216 ;
}
if ( V_178 != 0 )
V_175 [ V_178 - 1 ] |= V_206 ;
return V_178 ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int V_217 )
{
struct V_127 * V_3 = & V_22 -> V_128 -> V_3 ;
if ( V_217 != V_3 -> V_130 )
return - V_50 ;
F_1 ( V_2 , V_133 , V_42 ) ;
V_22 -> V_128 -> V_218 = NULL ;
return 1 ;
}
static int F_142 ( unsigned int * V_219 , unsigned int V_165 )
{
int V_220 , V_221 ;
V_221 = 500 ;
switch ( V_165 & V_222 ) {
case V_223 :
default:
V_220 = F_143 ( * V_219 , V_221 ) ;
break;
case V_224 :
V_220 = ( * V_219 ) / V_221 ;
break;
case V_225 :
V_220 = F_144 ( * V_219 , V_221 ) ;
break;
}
* V_219 = V_221 * V_220 ;
return V_220 - 1 ;
}
static void F_145 ( struct V_1 * V_2 ,
unsigned int V_62 , int V_226 )
{
T_1 V_83 =
F_38 ( V_227 ) |
F_44 ( V_96 ) |
F_53 ( V_89 ) |
F_55 ( V_228 ) |
F_54 ( V_90 ) |
F_48 ( V_150 ) ;
T_1 V_229 = V_230 ;
F_94 ( V_2 , V_62 , V_83 , false ) ;
F_30 ( V_2 , V_62 , V_226 ) ;
F_98 ( V_2 , V_62 , 0 ) ;
F_112 ( V_2 , V_62 ) ;
F_98 ( V_2 , V_62 , 1 ) ;
F_100 ( V_2 , V_62 , V_231 ) ;
F_27 ( V_2 , V_62 , V_229 ) ;
}
static int F_146 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_3 V_175 [ 16 ] ;
struct V_127 * V_3 = & V_22 -> V_128 -> V_3 ;
int V_226 ;
if ( V_35 -> V_129 ) {
F_9 ( V_2 -> V_11 ,
L_6 ) ;
return - V_28 ;
}
F_3 ( 0 , V_2 -> V_6 + V_171 ) ;
F_3 ( V_172 | V_173 , V_2 -> V_6 + V_55 ) ;
F_122 ( V_2 ) ;
V_35 -> V_129 = 0 ;
F_140 ( V_175 , V_3 ) ;
V_35 -> V_129 = 1 ;
V_35 -> V_138 = 0 ;
switch ( V_3 -> V_134 ) {
case V_183 :
break;
case V_141 :
V_226 = F_142 ( & V_3 -> V_135 , V_3 -> V_165 ) ;
F_145 ( V_2 , 5 , V_226 ) ;
F_95 ( V_2 , 5 , V_142 ) ;
break;
case V_132 :
if ( V_3 -> V_131 != V_132 )
F_114 ( V_2 , V_3 -> V_135 ) ;
break;
}
switch ( V_3 -> V_137 ) {
case V_197 :
break;
case V_141 :
V_226 = F_142 ( & V_3 -> V_140 , V_3 -> V_165 ) ;
F_145 ( V_2 , 4 , V_226 ) ;
F_95 ( V_2 , 4 , V_150 ) ;
break;
case V_132 :
if ( V_3 -> V_134 != V_132 &&
V_3 -> V_131 == V_132 )
F_114 ( V_2 , V_3 -> V_140 ) ;
break;
}
F_133 ( V_2 , V_175 ) ;
switch ( V_3 -> V_131 ) {
case V_197 :
F_1 ( V_2 , V_133 , V_42 ) ;
V_22 -> V_128 -> V_218 = NULL ;
break;
case V_132 :
F_114 ( V_2 , V_3 -> V_130 ) ;
V_22 -> V_128 -> V_218 = NULL ;
break;
case V_232 :
V_22 -> V_128 -> V_218 = F_141 ;
break;
}
F_3 ( V_173 | V_172 , V_2 -> V_6 + V_171 ) ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 ,
struct V_21 * V_22 , struct V_127 * V_3 )
{
int V_233 = 0 ;
unsigned int V_234 ;
V_233 |= F_148 ( & V_3 -> V_131 ,
V_197 | V_232 | V_132 ) ;
V_233 |= F_148 ( & V_3 -> V_134 ,
V_141 | V_132 | V_183 ) ;
V_233 |= F_148 ( & V_3 -> V_137 ,
V_141 | V_132 | V_197 ) ;
V_233 |= F_148 ( & V_3 -> V_235 , V_157 ) ;
V_233 |= F_148 ( & V_3 -> V_156 , V_157 | V_236 ) ;
if ( V_233 )
return 1 ;
V_233 |= F_149 ( V_3 -> V_131 ) ;
V_233 |= F_149 ( V_3 -> V_134 ) ;
V_233 |= F_149 ( V_3 -> V_137 ) ;
V_233 |= F_149 ( V_3 -> V_156 ) ;
if ( V_233 )
return 2 ;
switch ( V_3 -> V_131 ) {
case V_197 :
case V_232 :
V_233 |= F_150 ( & V_3 -> V_130 , 0 ) ;
break;
case V_132 :
V_233 |= F_151 ( & V_3 -> V_130 , 39 ) ;
break;
}
if ( V_3 -> V_134 == V_132 )
V_233 |= F_151 ( & V_3 -> V_135 , 39 ) ;
if ( V_3 -> V_137 == V_132 )
V_233 |= F_151 ( & V_3 -> V_140 , 39 ) ;
#define F_152 200000
#define F_153 2000000000
if ( V_3 -> V_134 == V_141 ) {
V_233 |= F_154 ( & V_3 -> V_135 ,
F_152 ) ;
V_233 |= F_151 ( & V_3 -> V_135 ,
F_153 ) ;
} else {
}
if ( V_3 -> V_137 == V_141 ) {
V_233 |= F_154 ( & V_3 -> V_140 ,
F_152 ) ;
V_233 |= F_151 ( & V_3 -> V_140 ,
F_153 ) ;
} else {
}
V_233 |= F_150 ( & V_3 -> V_237 ,
V_3 -> V_139 ) ;
if ( V_3 -> V_156 == V_157 )
V_233 |= F_154 ( & V_3 -> V_159 , 1 ) ;
else
V_233 |= F_150 ( & V_3 -> V_159 , 0 ) ;
if ( V_233 )
return 3 ;
if ( V_3 -> V_134 == V_141 ) {
V_234 = V_3 -> V_135 ;
F_142 ( & V_234 , V_3 -> V_165 ) ;
V_233 |= F_150 ( & V_3 -> V_135 , V_234 ) ;
}
if ( V_3 -> V_137 == V_141 ) {
V_234 = V_3 -> V_140 ;
F_142 ( & V_234 , V_3 -> V_165 ) ;
V_233 |= F_150 ( & V_3 -> V_140 , V_234 ) ;
if ( V_3 -> V_134 == V_141 ) {
V_234 = V_3 -> V_140 * V_3 -> V_237 ;
V_233 |= F_154 ( & V_3 ->
V_135 ,
V_234 ) ;
}
}
if ( V_233 )
return 4 ;
return 0 ;
}
static int F_155 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
F_4 ( V_2 , V_133 , V_42 ) ;
F_3 ( 0 , V_2 -> V_6 + V_171 ) ;
V_35 -> V_129 = 0 ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_119 )
{
unsigned int V_62 = F_138 ( V_24 -> V_209 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 -> V_178 ; V_8 ++ ) {
T_4 V_63 = ( T_4 ) V_119 [ V_8 ] ;
int V_30 ;
V_63 -= ( 0x1fff ) ;
V_30 = F_23 ( V_2 , V_62 , V_63 ) ;
if ( V_30 )
return V_30 ;
V_22 -> V_238 [ V_62 ] = V_119 [ V_8 ] ;
}
return V_24 -> V_178 ;
}
static void F_157 ( struct V_1 * V_2 )
{
T_1 V_120 ;
F_11 ( V_2 , V_121 , V_123 ) ;
for ( V_120 = 0 ; V_120 < V_124 ; V_120 ++ ) {
F_11 ( V_2 , F_118 ( V_120 ) , 0 ) ;
F_11 ( V_2 , F_120 ( V_120 ) , 0xffff ) ;
F_11 ( V_2 , F_116 ( V_120 ) , 0 ) ;
F_11 ( V_2 , F_158 ( V_120 ) , 0 ) ;
}
}
static int F_159 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_119 )
{
unsigned long V_120 = ( unsigned long ) V_22 -> V_36 ;
if ( F_160 ( V_22 , V_119 ) )
F_11 ( V_2 , F_158 ( V_120 ) , V_22 -> V_239 ) ;
V_119 [ 1 ] = F_10 ( V_2 , F_161 ( V_120 ) ) ;
return V_24 -> V_178 ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_119 )
{
unsigned long V_120 = ( unsigned long ) V_22 -> V_36 ;
int V_30 ;
V_30 = F_163 ( V_2 , V_22 , V_24 , V_119 , 0 ) ;
if ( V_30 )
return V_30 ;
F_11 ( V_2 , F_158 ( V_120 ) , V_22 -> V_240 ) ;
return V_24 -> V_178 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_119 )
{
unsigned int V_62 = F_138 ( V_24 -> V_209 ) ;
T_1 V_83 =
F_38 ( V_227 ) |
F_44 ( V_96 ) |
F_53 ( V_91 ) |
F_55 ( V_241 ) |
F_54 ( V_90 ) |
F_48 ( V_150 ) ;
T_1 V_229 = V_242 ;
T_1 V_101 = V_142 ;
F_94 ( V_2 , V_62 , V_83 , true ) ;
F_30 ( V_2 , V_62 , V_119 [ 0 ] ) ;
F_112 ( V_2 , V_62 ) ;
F_27 ( V_2 , V_62 , V_229 ) ;
F_95 ( V_2 , V_62 , ( V_101 != 0 ) ) ;
return V_24 -> V_178 ;
}
static int F_165 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_119 )
{
unsigned int V_62 = F_138 ( V_24 -> V_209 ) ;
T_1 V_243 = F_31 ( V_62 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 -> V_178 ; V_8 ++ ) {
unsigned int V_5 ;
V_5 = F_10 ( V_2 , V_243 ) ;
V_5 |= ( F_10 ( V_2 , V_243 + 2 ) << 16 ) ;
V_119 [ V_8 ] = V_5 ;
}
return V_24 -> V_178 ;
}
static int F_166 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_119 )
{
unsigned int V_62 = F_138 ( V_24 -> V_209 ) ;
F_30 ( V_2 , V_62 , V_119 [ 0 ] ) ;
F_98 ( V_2 , V_62 , 0 ) ;
F_112 ( V_2 , V_62 ) ;
F_98 ( V_2 , V_62 , 2 ) ;
return 1 ;
}
static void F_167 ( struct V_1 * V_2 , T_1 V_244 )
{
F_11 ( V_2 , V_121 , V_245 ) ;
F_11 ( V_2 , V_246 , V_244 ) ;
F_11 ( V_2 , V_121 , V_247 ) ;
}
static void F_168 ( struct V_1 * V_2 )
{
int V_62 ;
T_1 V_83 =
F_38 ( V_227 ) |
F_44 ( V_96 ) |
F_53 ( V_91 ) |
F_55 ( V_241 ) |
F_54 ( V_90 ) |
F_48 ( V_150 ) ;
for ( V_62 = 0 ; V_62 < V_248 ; V_62 ++ ) {
F_94 ( V_2 , V_62 , V_83 , true ) ;
F_100 ( V_2 , V_62 , 0 ) ;
F_32 ( V_2 , V_62 ) ;
F_95 ( V_2 , V_62 , V_142 ) ;
}
}
static int F_169 ( struct V_1 * V_2 )
{
struct V_249 * V_250 = F_170 ( V_2 ) ;
struct V_34 * V_35 = V_2 -> V_36 ;
void * V_14 ;
T_7 V_251 ;
V_14 = F_171 ( V_250 , V_252 , & V_251 ) ;
if ( ! V_14 )
return - V_253 ;
V_35 -> V_153 . V_154 = V_14 ;
V_35 -> V_153 . V_181 = V_251 ;
V_14 = F_171 ( V_250 , V_252 , & V_251 ) ;
if ( ! V_14 )
return - V_253 ;
V_35 -> V_180 . V_154 = V_14 ;
V_35 -> V_180 . V_181 = V_251 ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 )
{
struct V_249 * V_250 = F_170 ( V_2 ) ;
struct V_34 * V_35 = V_2 -> V_36 ;
if ( ! V_35 )
return;
if ( V_35 -> V_180 . V_154 )
F_173 ( V_250 , V_252 ,
V_35 -> V_180 . V_154 ,
V_35 -> V_180 . V_181 ) ;
if ( V_35 -> V_153 . V_154 )
F_173 ( V_250 , V_252 ,
V_35 -> V_153 . V_154 ,
V_35 -> V_153 . V_181 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_7 V_254 ;
T_1 V_62 ;
int V_8 ;
int V_30 ;
F_1 ( V_2 , V_255 | V_256 | V_257 ,
V_42 ) ;
F_3 ( V_258 |
( V_259 << V_260 ) | V_261 |
V_262 , V_2 -> V_6 + V_263 ) ;
F_3 ( V_264 , V_2 -> V_6 + V_265 ) ;
F_3 ( V_199 | V_202 , V_2 -> V_6 + V_198 ) ;
V_35 -> V_38 = 0xA0 ;
F_3 ( V_266 | V_267 ,
V_2 -> V_6 + V_268 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
F_3 ( V_266 , V_2 -> V_6 + V_268 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
}
F_3 ( V_269 , V_2 -> V_6 + V_270 ) ;
F_3 ( V_271 | V_272 , V_2 -> V_6 + V_273 ) ;
F_3 ( V_271 | V_272 | V_61 ,
V_2 -> V_6 + V_273 + 4 ) ;
F_3 ( V_274 , V_2 -> V_6 + V_275 ) ;
F_3 ( ( T_2 ) V_35 -> V_180 . V_181 ,
V_2 -> V_6 + V_182 ) ;
F_3 ( 0 , V_2 -> V_6 + V_276 ) ;
F_3 ( 0 , V_2 -> V_6 + V_277 ) ;
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
F_3 ( 0 , V_2 -> V_6 + V_278 ) ;
V_254 = V_35 -> V_153 . V_181 +
( V_279 * sizeof( T_2 ) ) ;
F_3 ( ( T_2 ) V_254 , V_2 -> V_6 + V_280 ) ;
F_3 ( ( T_2 ) ( V_254 + sizeof( T_2 ) ) ,
V_2 -> V_6 + V_281 ) ;
V_35 -> V_53 = ( T_2 * ) V_35 -> V_153 . V_154 +
V_279 ;
F_3 ( 8 , V_2 -> V_6 + V_282 ) ;
F_3 ( V_56 | V_57 | V_58 | V_61 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
F_3 ( V_283 , V_2 -> V_6 + F_22 ( 1 ) ) ;
F_3 ( V_284 , V_2 -> V_6 + V_275 ) ;
F_25 ( V_2 ) ;
V_30 = F_25 ( V_2 ) ;
if ( V_30 )
return V_30 ;
for ( V_62 = 0 ; V_62 < V_285 ; V_62 ++ ) {
V_30 = F_23 ( V_2 , V_62 , 0 ) ;
if ( V_30 )
return V_30 ;
}
F_168 ( V_2 ) ;
F_167 ( V_2 , ( F_10 ( V_2 , V_144 ) &
V_286 ) ) ;
F_157 ( V_2 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 ,
unsigned long V_287 )
{
struct V_249 * V_250 = F_170 ( V_2 ) ;
struct V_34 * V_35 ;
struct V_21 * V_22 ;
int V_30 ;
V_35 = F_176 ( V_2 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_253 ;
V_30 = F_177 ( V_2 ) ;
if ( V_30 )
return V_30 ;
V_2 -> V_6 = F_178 ( V_250 , 0 ) ;
if ( ! V_2 -> V_6 )
return - V_253 ;
F_3 ( 0 , V_2 -> V_6 + V_171 ) ;
F_3 ( V_288 , V_2 -> V_6 + V_42 ) ;
V_30 = F_169 ( V_2 ) ;
if ( V_30 )
return V_30 ;
if ( V_250 -> V_163 ) {
V_30 = F_179 ( V_250 -> V_163 , F_130 , V_289 ,
V_2 -> V_290 , V_2 ) ;
if ( V_30 == 0 )
V_2 -> V_163 = V_250 -> V_163 ;
}
V_30 = F_180 ( V_2 , 6 ) ;
if ( V_30 )
return V_30 ;
V_22 = & V_2 -> V_291 [ 0 ] ;
V_22 -> type = V_292 ;
V_22 -> V_293 = V_294 | V_295 ;
V_22 -> V_296 = V_297 ;
V_22 -> V_298 = 0x3fff ;
V_22 -> V_299 = & V_300 ;
V_22 -> V_301 = V_297 ;
V_22 -> V_302 = F_137 ;
if ( V_2 -> V_163 ) {
V_2 -> V_126 = V_22 ;
V_22 -> V_293 |= V_303 ;
V_22 -> V_304 = F_146 ;
V_22 -> V_305 = F_147 ;
V_22 -> V_306 = F_155 ;
}
V_22 = & V_2 -> V_291 [ 1 ] ;
V_22 -> type = V_307 ;
V_22 -> V_293 = V_308 | V_294 ;
V_22 -> V_296 = V_285 ;
V_22 -> V_298 = 0x3fff ;
V_22 -> V_299 = & V_309 ;
V_22 -> V_310 = F_156 ;
V_30 = F_181 ( V_22 ) ;
if ( V_30 )
return V_30 ;
V_22 = & V_2 -> V_291 [ 2 ] ;
V_22 -> type = V_311 ;
V_22 -> V_293 = V_308 | V_294 ;
V_22 -> V_296 = 16 ;
V_22 -> V_298 = 1 ;
V_22 -> V_240 = 0xffff ;
V_22 -> V_36 = ( void * ) 0 ;
V_22 -> V_299 = & V_312 ;
V_22 -> V_313 = F_162 ;
V_22 -> V_314 = F_159 ;
V_22 = & V_2 -> V_291 [ 3 ] ;
V_22 -> type = V_311 ;
V_22 -> V_293 = V_308 | V_294 ;
V_22 -> V_296 = 16 ;
V_22 -> V_298 = 1 ;
V_22 -> V_240 = 0xffff ;
V_22 -> V_36 = ( void * ) 1 ;
V_22 -> V_299 = & V_312 ;
V_22 -> V_313 = F_162 ;
V_22 -> V_314 = F_159 ;
V_22 = & V_2 -> V_291 [ 4 ] ;
V_22 -> type = V_311 ;
V_22 -> V_293 = V_308 | V_294 ;
V_22 -> V_296 = 16 ;
V_22 -> V_298 = 1 ;
V_22 -> V_240 = 0xffff ;
V_22 -> V_36 = ( void * ) 2 ;
V_22 -> V_299 = & V_312 ;
V_22 -> V_313 = F_162 ;
V_22 -> V_314 = F_159 ;
V_22 = & V_2 -> V_291 [ 5 ] ;
V_22 -> type = V_315 ;
V_22 -> V_293 = V_308 | V_294 | V_316 ;
V_22 -> V_296 = V_248 ;
V_22 -> V_298 = 0xffffff ;
V_22 -> V_299 = & V_317 ;
V_22 -> V_313 = F_164 ;
V_22 -> V_302 = F_165 ;
V_22 -> V_310 = F_166 ;
return F_174 ( V_2 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
if ( V_35 ) {
V_35 -> V_129 = 0 ;
if ( V_2 -> V_6 ) {
F_3 ( 0 , V_2 -> V_6 + V_171 ) ;
F_3 ( V_173 | V_172 ,
V_2 -> V_6 + V_55 ) ;
F_167 ( V_2 , 0 ) ;
F_3 ( V_318 , V_2 -> V_6 + V_42 ) ;
F_3 ( V_319 , V_2 -> V_6 + V_275 ) ;
}
}
F_183 ( V_2 ) ;
F_172 ( V_2 ) ;
}
static int F_184 ( struct V_249 * V_2 ,
const struct V_320 * V_321 )
{
return F_185 ( V_2 , & V_322 , V_321 -> V_323 ) ;
}
