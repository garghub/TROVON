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
static void F_103 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_113 ;
V_111 |= F_55 ( V_77 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static void F_104 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_114 ;
V_111 |= F_53 ( V_77 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static T_1 F_105 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_82 ( F_65 ( V_2 , V_62 ) ) ;
}
static void F_106 ( struct V_1 * V_2 ,
unsigned int V_62 , T_1 V_77 )
{
T_1 V_111 ;
V_111 = F_65 ( V_2 , V_62 ) ;
V_111 &= ~ V_115 ;
V_111 |= F_44 ( V_77 != 0 ) ;
F_94 ( V_2 , V_62 , V_111 , false ) ;
}
static T_1 F_107 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return F_70 ( F_65 ( V_2 , V_62 ) ) ;
}
static void F_108 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
if ( V_62 < 3 ) {
T_1 V_81 ;
V_81 = F_10 ( V_2 , F_37 ( V_62 ) ) ;
F_11 ( V_2 , F_37 ( V_62 ) ,
( V_81 ^ V_116 ) ) ;
F_11 ( V_2 , F_37 ( V_62 ) , V_81 ) ;
} else {
T_1 V_82 ;
V_82 = F_10 ( V_2 , F_28 ( V_62 ) ) ;
V_82 &= ~ V_78 ;
F_11 ( V_2 , F_28 ( V_62 ) ,
( V_82 ^ V_117 ) ) ;
F_11 ( V_2 , F_28 ( V_62 ) , V_82 ) ;
}
}
static unsigned int F_109 ( unsigned int V_118 )
{
return ( ( V_118 >> 18 ) & 0x3fff ) ^ 0x2000 ;
}
static int F_110 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned int V_119 = V_62 / 16 ;
unsigned int V_20 = 1 << ( V_62 - ( 16 * V_119 ) ) ;
unsigned int V_26 ;
V_26 = F_10 ( V_2 , F_111 ( V_119 ) ) ;
F_11 ( V_2 , F_112 ( V_119 ) , V_20 | V_26 ) ;
V_26 = F_10 ( V_2 , F_113 ( V_119 ) ) ;
F_11 ( V_2 , F_114 ( V_119 ) , V_20 | V_26 ) ;
F_11 ( V_2 , V_120 , V_121 ) ;
V_26 = F_10 ( V_2 , F_115 ( V_119 ) ) ;
F_11 ( V_2 , F_116 ( V_119 ) , V_20 | V_26 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 , unsigned int V_119 ,
unsigned int V_20 )
{
F_11 ( V_2 , V_120 , V_122 ) ;
F_11 ( V_2 , F_116 ( V_119 ) , V_20 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
F_11 ( V_2 , V_120 , V_122 ) ;
for ( V_119 = 0 ; V_119 < V_123 ; V_119 ++ )
F_11 ( V_2 , F_116 ( V_119 ) , 0xffff ) ;
return 0 ;
}
static void F_119 ( struct V_1 * V_2 ,
T_1 V_124 , T_3 V_119 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_125 ;
struct V_126 * V_3 = & V_22 -> V_127 -> V_3 ;
F_117 ( V_2 , V_119 , V_124 ) ;
if ( V_35 -> V_128 ) {
if ( ( V_124 >> ( V_3 -> V_129 - ( 16 * V_119 ) ) ) == 1 &&
V_3 -> V_130 == V_131 ) {
F_1 ( V_2 , V_132 , V_42 ) ;
if ( V_3 -> V_133 == V_131 )
F_110 ( V_2 , V_3 -> V_134 ) ;
}
if ( ( V_124 >> ( V_3 -> V_134 - ( 16 * V_119 ) ) ) == 1 &&
V_3 -> V_133 == V_131 ) {
F_1 ( V_2 , V_135 , V_10 ) ;
if ( V_3 -> V_136 == V_131 ) {
V_35 -> V_137 = V_3 -> V_138 ;
F_110 ( V_2 , V_3 -> V_139 ) ;
}
if ( V_3 -> V_136 == V_140 ) {
V_35 -> V_137 = V_3 -> V_138 ;
F_95 ( V_2 , 5 , V_141 ) ;
}
}
if ( ( V_124 >> ( V_3 -> V_139 - ( 16 * V_119 ) ) ) == 1 &&
V_3 -> V_136 == V_131 ) {
F_1 ( V_2 , V_135 , V_10 ) ;
V_35 -> V_137 -- ;
if ( V_35 -> V_137 > 0 )
F_110 ( V_2 , V_3 -> V_139 ) ;
}
}
}
static void F_120 ( struct V_1 * V_2 )
{
T_1 V_124 ;
T_3 V_119 ;
for ( V_119 = 0 ; V_119 < V_123 ; V_119 ++ ) {
V_124 = F_10 ( V_2 , F_121 ( V_119 ) ) ;
if ( V_124 ) {
F_119 ( V_2 , V_124 , V_119 ) ;
return;
}
}
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_125 ;
struct V_142 * V_127 = V_22 -> V_127 ;
struct V_126 * V_3 = & V_127 -> V_3 ;
T_1 V_124 ;
V_124 = F_10 ( V_2 , V_143 ) ;
if ( V_124 & V_144 ) {
F_32 ( V_2 , 0 ) ;
}
if ( V_124 & V_145 ) {
F_32 ( V_2 , 1 ) ;
}
if ( V_124 & V_146 ) {
F_32 ( V_2 , 2 ) ;
}
if ( V_124 & V_147 ) {
F_32 ( V_2 , 3 ) ;
}
if ( V_124 & V_148 ) {
F_32 ( V_2 , 4 ) ;
if ( V_35 -> V_137 > 0 ) {
V_35 -> V_137 -- ;
if ( V_35 -> V_137 == 0 )
F_95 ( V_2 , 4 , V_149 ) ;
if ( V_3 -> V_136 == V_140 ) {
F_1 ( V_2 , V_135 ,
V_10 ) ;
}
}
}
if ( V_124 & V_150 ) {
F_32 ( V_2 , 5 ) ;
if ( V_3 -> V_133 == V_140 ) {
F_1 ( V_2 , V_135 , V_10 ) ;
}
if ( V_3 -> V_136 == V_140 ) {
V_35 -> V_137 = V_3 -> V_138 ;
F_95 ( V_2 , 4 , V_141 ) ;
}
}
}
static bool F_123 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_125 ;
struct V_142 * V_127 = V_22 -> V_127 ;
struct V_126 * V_3 = & V_127 -> V_3 ;
T_2 * V_151 = ( T_2 * ) V_35 -> V_152 . V_153 + 1 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 -> V_138 ; V_8 ++ ) {
unsigned short V_154 ;
V_154 = F_109 ( * V_151 ) ;
V_151 ++ ;
F_124 ( V_22 , & V_154 , 1 ) ;
}
if ( V_3 -> V_155 == V_156 && V_127 -> V_157 >= V_3 -> V_158 )
V_127 -> V_159 |= V_160 ;
if ( V_127 -> V_159 & V_161 )
V_35 -> V_128 = 0 ;
if ( V_35 -> V_128 && V_3 -> V_133 == V_131 )
F_110 ( V_2 , V_3 -> V_134 ) ;
F_125 ( V_2 , V_22 ) ;
return ! V_35 -> V_128 ;
}
static T_5 F_126 ( int V_162 , void * V_163 )
{
struct V_1 * V_2 = V_163 ;
unsigned long V_164 ;
T_2 V_165 , V_166 ;
if ( ! V_2 -> V_167 )
return V_168 ;
F_127 ( & V_2 -> V_169 , V_164 ) ;
V_166 = F_6 ( V_2 -> V_6 + V_170 ) ;
V_165 = F_6 ( V_2 -> V_6 + V_55 ) ;
F_3 ( 0 , V_2 -> V_6 + V_170 ) ;
F_3 ( V_165 , V_2 -> V_6 + V_55 ) ;
switch ( V_165 ) {
case V_171 :
if ( F_123 ( V_2 ) )
V_166 = 0 ;
break;
case V_172 :
F_120 ( V_2 ) ;
F_122 ( V_2 ) ;
break;
}
F_3 ( V_166 , V_2 -> V_6 + V_170 ) ;
F_128 ( & V_2 -> V_169 , V_164 ) ;
return V_173 ;
}
static void F_129 ( struct V_1 * V_2 , T_3 * V_174 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
struct V_21 * V_22 = V_2 -> V_125 ;
struct V_126 * V_3 = & V_22 -> V_127 -> V_3 ;
T_2 * V_175 ;
T_2 V_176 ;
T_1 V_8 ;
T_1 V_177 ;
T_2 V_178 ;
F_4 ( V_2 , V_132 , V_42 ) ;
V_175 = ( T_2 * ) V_35 -> V_179 . V_153 ;
F_3 ( ( T_2 ) V_35 -> V_179 . V_180 ,
V_2 -> V_6 + V_181 ) ;
if ( V_3 -> V_133 != V_182 ) {
* V_175 ++ = V_183 | V_184 ;
* V_175 ++ = V_185 | V_184 ;
}
* V_175 ++ = V_186 | ( V_16 >> 2 ) ;
* V_175 ++ = V_19 | V_187 ;
* V_175 ++ = V_186 | ( V_17 >> 2 ) ;
* V_175 ++ = V_188 ;
* V_175 ++ = V_185 | V_189 ;
* V_175 ++ = V_190 | V_189 ;
* V_175 ++ = V_183 | V_189 ;
for ( V_35 -> V_191 = 0 ; V_35 -> V_191 < 16 ;
V_35 -> V_191 ++ ) {
V_178 = ( * V_174 << 8 ) | ( * V_174 & 0x10 ? V_188 :
V_192 ) ;
* V_175 ++ = V_186 | ( V_16 >> 2 ) ;
* V_175 ++ = V_19 | V_187 ;
* V_175 ++ = V_186 | ( V_17 >> 2 ) ;
* V_175 ++ = V_178 ;
* V_175 ++ = V_185 | V_189 ;
* V_175 ++ = V_190 | V_189 ;
* V_175 ++ = V_183 | V_189 ;
* V_175 ++ = V_186 | ( V_16 >> 2 ) ;
* V_175 ++ = V_19 | V_193 ;
* V_175 ++ = V_186 | ( V_17 >> 2 ) ;
* V_175 ++ = V_178 ;
* V_175 ++ = V_185 | V_189 ;
* V_175 ++ = V_190 | V_189 ;
* V_175 ++ = V_183 | V_189 ;
V_176 =
( T_2 ) V_35 -> V_179 . V_180 +
( T_2 ) ( ( unsigned long ) V_175 -
( unsigned long ) V_35 ->
V_179 . V_153 ) ;
for ( V_8 = 0 ; V_8 < ( 10 * V_194 / 2 ) ; V_8 ++ ) {
V_176 += 8 ;
* V_175 ++ = V_195 ;
* V_175 ++ = V_176 ;
}
if ( V_3 -> V_136 != V_196 ) {
* V_175 ++ = V_183 | V_184 ;
* V_175 ++ = V_185 | V_184 ;
}
* V_175 ++ = V_186 | ( V_197 >> 2 ) ;
* V_175 ++ = V_198 | V_199 ;
* V_175 ++ = V_200 ;
* V_175 ++ = V_186 | ( V_197 >> 2 ) ;
* V_175 ++ = V_198 | V_201 ;
* V_175 ++ = V_183 | V_202 ;
* V_175 ++ = V_203 |
( F_130 ( V_204 ) >> 2 ) ;
* V_175 ++ = ( T_2 ) V_35 -> V_152 . V_180 +
( V_35 -> V_191 << 2 ) ;
if ( * V_174 ++ & V_205 ) {
V_35 -> V_191 ++ ;
break;
}
}
for ( V_177 = 0 ; V_177 < ( 2 * V_194 ) ; V_177 ++ )
* V_175 ++ = V_200 ;
* V_175 ++ = V_186 | ( V_197 >> 2 ) ;
* V_175 ++ = V_198 | V_199 ;
* V_175 ++ = V_200 ;
* V_175 ++ = V_186 | ( V_197 >> 2 ) ;
* V_175 ++ = V_198 | V_201 ;
* V_175 ++ = V_183 | V_202 ;
* V_175 ++ = V_203 | ( F_130 ( V_204 ) >> 2 ) ;
* V_175 ++ = ( T_2 ) V_35 -> V_152 . V_180 +
( V_35 -> V_191 << 2 ) ;
if ( V_35 -> V_128 == 1 )
* V_175 ++ = V_206 ;
* V_175 ++ = V_195 ;
* V_175 ++ = ( T_2 ) V_35 -> V_179 . V_180 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_118 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_3 V_8 ;
T_6 * V_151 ;
F_1 ( V_2 , V_135 , V_10 ) ;
while ( F_5 ( V_2 , V_135 , V_10 ) )
;
V_151 = ( T_2 * ) V_35 -> V_152 . V_153 + 1 ;
for ( V_8 = 0 ; V_8 < V_35 -> V_191 ; V_8 ++ ) {
* V_118 = F_109 ( * V_151 ++ ) ;
V_118 ++ ;
}
return V_8 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_26 ;
V_26 = F_6 ( V_2 -> V_6 + V_12 ) ;
if ( V_26 & V_207 )
return 0 ;
return - V_28 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_118 )
{
T_1 V_62 = F_134 ( V_24 -> V_208 ) ;
T_1 V_209 = F_135 ( V_24 -> V_208 ) ;
T_1 V_210 = 0 ;
T_2 V_211 ;
T_2 V_212 ;
int V_30 ;
int V_177 ;
if ( V_209 == 0 )
V_210 = ( V_62 << 8 ) | ( V_188 ) ;
else
V_210 = ( V_62 << 8 ) | ( V_192 ) ;
F_11 ( V_2 , V_187 , V_210 ) ;
F_11 ( V_2 , V_193 , V_210 ) ;
for ( V_177 = 0 ; V_177 < V_24 -> V_177 ; V_177 ++ ) {
F_8 ( 10 ) ;
V_211 = F_6 ( V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 & ~ V_201 , V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 & ~ V_201 , V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 & ~ V_201 , V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 | V_201 , V_2 -> V_6 + V_197 ) ;
V_30 = F_15 ( V_2 , V_22 , V_24 , F_132 , 0 ) ;
if ( V_30 )
return V_30 ;
if ( V_177 != 0 ) {
V_212 = F_6 ( V_2 -> V_6 + V_204 ) ;
V_118 [ V_177 - 1 ] = F_109 ( V_212 ) ;
}
F_8 ( 4 ) ;
}
V_211 = F_6 ( V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 & ~ V_201 , V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 & ~ V_201 , V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 & ~ V_201 , V_2 -> V_6 + V_197 ) ;
F_3 ( V_211 | V_201 , V_2 -> V_6 + V_197 ) ;
V_30 = F_15 ( V_2 , V_22 , V_24 , F_132 , 0 ) ;
if ( V_30 )
return V_30 ;
if ( V_177 != 0 ) {
V_212 = F_6 ( V_2 -> V_6 + V_204 ) ;
V_118 [ V_177 - 1 ] = F_109 ( V_212 ) ;
}
return V_177 ;
}
static int F_136 ( T_3 * V_174 , struct V_126 * V_3 )
{
int V_177 ;
for ( V_177 = 0 ; V_177 < V_3 -> V_138 ; V_177 ++ ) {
if ( F_135 ( V_3 -> V_213 [ V_177 ] ) == 0 )
V_174 [ V_177 ] = F_134 ( V_3 -> V_213 [ V_177 ] ) | V_214 ;
else
V_174 [ V_177 ] = F_134 ( V_3 -> V_213 [ V_177 ] ) | V_215 ;
}
if ( V_177 != 0 )
V_174 [ V_177 - 1 ] |= V_205 ;
return V_177 ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
unsigned int V_216 )
{
struct V_126 * V_3 = & V_22 -> V_127 -> V_3 ;
if ( V_216 != V_3 -> V_129 )
return - V_50 ;
F_1 ( V_2 , V_132 , V_42 ) ;
V_22 -> V_127 -> V_217 = NULL ;
return 1 ;
}
static int F_138 ( unsigned int * V_218 , unsigned int V_164 )
{
int V_219 , V_220 ;
V_220 = 500 ;
switch ( V_164 & V_221 ) {
case V_222 :
default:
V_219 = F_139 ( * V_218 , V_220 ) ;
break;
case V_223 :
V_219 = ( * V_218 ) / V_220 ;
break;
case V_224 :
V_219 = F_140 ( * V_218 , V_220 ) ;
break;
}
* V_218 = V_220 * V_219 ;
return V_219 - 1 ;
}
static void F_141 ( struct V_1 * V_2 ,
unsigned int V_62 , int V_225 )
{
T_1 V_83 =
F_38 ( V_226 ) |
F_44 ( V_96 ) |
F_53 ( V_89 ) |
F_55 ( V_227 ) |
F_54 ( V_90 ) |
F_48 ( V_149 ) ;
T_1 V_228 = V_229 ;
F_94 ( V_2 , V_62 , V_83 , false ) ;
F_30 ( V_2 , V_62 , V_225 ) ;
F_98 ( V_2 , V_62 , 0 ) ;
F_108 ( V_2 , V_62 ) ;
F_98 ( V_2 , V_62 , 1 ) ;
F_100 ( V_2 , V_62 , V_230 ) ;
F_27 ( V_2 , V_62 , V_228 ) ;
}
static int F_142 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_3 V_174 [ 16 ] ;
struct V_126 * V_3 = & V_22 -> V_127 -> V_3 ;
int V_225 ;
if ( V_35 -> V_128 ) {
F_9 ( V_2 -> V_11 ,
L_6 ) ;
return - V_28 ;
}
F_3 ( 0 , V_2 -> V_6 + V_170 ) ;
F_3 ( V_171 | V_172 , V_2 -> V_6 + V_55 ) ;
F_118 ( V_2 ) ;
V_35 -> V_128 = 0 ;
F_136 ( V_174 , V_3 ) ;
V_35 -> V_128 = 1 ;
V_35 -> V_137 = 0 ;
switch ( V_3 -> V_133 ) {
case V_182 :
break;
case V_140 :
V_225 = F_138 ( & V_3 -> V_134 , V_3 -> V_164 ) ;
F_141 ( V_2 , 5 , V_225 ) ;
F_95 ( V_2 , 5 , V_141 ) ;
break;
case V_131 :
if ( V_3 -> V_130 != V_131 )
F_110 ( V_2 , V_3 -> V_134 ) ;
break;
}
switch ( V_3 -> V_136 ) {
case V_196 :
break;
case V_140 :
V_225 = F_138 ( & V_3 -> V_139 , V_3 -> V_164 ) ;
F_141 ( V_2 , 4 , V_225 ) ;
F_95 ( V_2 , 4 , V_149 ) ;
break;
case V_131 :
if ( V_3 -> V_133 != V_131 &&
V_3 -> V_130 == V_131 )
F_110 ( V_2 , V_3 -> V_139 ) ;
break;
}
F_129 ( V_2 , V_174 ) ;
switch ( V_3 -> V_130 ) {
case V_196 :
F_1 ( V_2 , V_132 , V_42 ) ;
V_22 -> V_127 -> V_217 = NULL ;
break;
case V_131 :
F_110 ( V_2 , V_3 -> V_129 ) ;
V_22 -> V_127 -> V_217 = NULL ;
break;
case V_231 :
V_22 -> V_127 -> V_217 = F_137 ;
break;
}
F_3 ( V_172 | V_171 , V_2 -> V_6 + V_170 ) ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_21 * V_22 , struct V_126 * V_3 )
{
int V_232 = 0 ;
unsigned int V_233 ;
V_232 |= F_144 ( & V_3 -> V_130 ,
V_196 | V_231 | V_131 ) ;
V_232 |= F_144 ( & V_3 -> V_133 ,
V_140 | V_131 | V_182 ) ;
V_232 |= F_144 ( & V_3 -> V_136 ,
V_140 | V_131 | V_196 ) ;
V_232 |= F_144 ( & V_3 -> V_234 , V_156 ) ;
V_232 |= F_144 ( & V_3 -> V_155 , V_156 | V_235 ) ;
if ( V_232 )
return 1 ;
V_232 |= F_145 ( V_3 -> V_130 ) ;
V_232 |= F_145 ( V_3 -> V_133 ) ;
V_232 |= F_145 ( V_3 -> V_136 ) ;
V_232 |= F_145 ( V_3 -> V_155 ) ;
if ( V_232 )
return 2 ;
switch ( V_3 -> V_130 ) {
case V_196 :
case V_231 :
V_232 |= F_146 ( & V_3 -> V_129 , 0 ) ;
break;
case V_131 :
V_232 |= F_147 ( & V_3 -> V_129 , 39 ) ;
break;
}
if ( V_3 -> V_133 == V_131 )
V_232 |= F_147 ( & V_3 -> V_134 , 39 ) ;
if ( V_3 -> V_136 == V_131 )
V_232 |= F_147 ( & V_3 -> V_139 , 39 ) ;
#define F_148 200000
#define F_149 2000000000
if ( V_3 -> V_133 == V_140 ) {
V_232 |= F_150 ( & V_3 -> V_134 ,
F_148 ) ;
V_232 |= F_147 ( & V_3 -> V_134 ,
F_149 ) ;
} else {
}
if ( V_3 -> V_136 == V_140 ) {
V_232 |= F_150 ( & V_3 -> V_139 ,
F_148 ) ;
V_232 |= F_147 ( & V_3 -> V_139 ,
F_149 ) ;
} else {
}
V_232 |= F_146 ( & V_3 -> V_236 ,
V_3 -> V_138 ) ;
if ( V_3 -> V_155 == V_156 )
V_232 |= F_150 ( & V_3 -> V_158 , 1 ) ;
else
V_232 |= F_146 ( & V_3 -> V_158 , 0 ) ;
if ( V_232 )
return 3 ;
if ( V_3 -> V_133 == V_140 ) {
V_233 = V_3 -> V_134 ;
F_138 ( & V_233 , V_3 -> V_164 ) ;
V_232 |= F_146 ( & V_3 -> V_134 , V_233 ) ;
}
if ( V_3 -> V_136 == V_140 ) {
V_233 = V_3 -> V_139 ;
F_138 ( & V_233 , V_3 -> V_164 ) ;
V_232 |= F_146 ( & V_3 -> V_139 , V_233 ) ;
if ( V_3 -> V_133 == V_140 ) {
V_233 = V_3 -> V_139 * V_3 -> V_236 ;
V_232 |= F_150 ( & V_3 ->
V_134 ,
V_233 ) ;
}
}
if ( V_232 )
return 4 ;
return 0 ;
}
static int F_151 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
F_4 ( V_2 , V_132 , V_42 ) ;
F_3 ( 0 , V_2 -> V_6 + V_170 ) ;
V_35 -> V_128 = 0 ;
return 0 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_118 )
{
unsigned int V_62 = F_134 ( V_24 -> V_208 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 -> V_177 ; V_8 ++ ) {
T_4 V_63 = ( T_4 ) V_118 [ V_8 ] ;
int V_30 ;
V_63 -= ( 0x1fff ) ;
V_30 = F_23 ( V_2 , V_62 , V_63 ) ;
if ( V_30 )
return V_30 ;
V_22 -> V_237 [ V_62 ] = V_118 [ V_8 ] ;
}
return V_24 -> V_177 ;
}
static void F_153 ( struct V_1 * V_2 )
{
T_1 V_119 ;
F_11 ( V_2 , V_120 , V_122 ) ;
for ( V_119 = 0 ; V_119 < V_123 ; V_119 ++ ) {
F_11 ( V_2 , F_114 ( V_119 ) , 0 ) ;
F_11 ( V_2 , F_116 ( V_119 ) , 0xffff ) ;
F_11 ( V_2 , F_112 ( V_119 ) , 0 ) ;
F_11 ( V_2 , F_154 ( V_119 ) , 0 ) ;
}
}
static int F_155 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_118 )
{
unsigned long V_119 = ( unsigned long ) V_22 -> V_36 ;
if ( F_156 ( V_22 , V_118 ) )
F_11 ( V_2 , F_154 ( V_119 ) , V_22 -> V_238 ) ;
V_118 [ 1 ] = F_10 ( V_2 , F_157 ( V_119 ) ) ;
return V_24 -> V_177 ;
}
static int F_158 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_118 )
{
unsigned long V_119 = ( unsigned long ) V_22 -> V_36 ;
int V_30 ;
V_30 = F_159 ( V_2 , V_22 , V_24 , V_118 , 0 ) ;
if ( V_30 )
return V_30 ;
F_11 ( V_2 , F_154 ( V_119 ) , V_22 -> V_239 ) ;
return V_24 -> V_177 ;
}
static int F_160 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_118 )
{
unsigned int V_62 = F_134 ( V_24 -> V_208 ) ;
T_1 V_83 =
F_38 ( V_226 ) |
F_44 ( V_96 ) |
F_53 ( V_91 ) |
F_55 ( V_240 ) |
F_54 ( V_90 ) |
F_48 ( V_149 ) ;
T_1 V_228 = V_241 ;
T_1 V_101 = V_141 ;
F_94 ( V_2 , V_62 , V_83 , true ) ;
F_30 ( V_2 , V_62 , V_118 [ 0 ] ) ;
F_108 ( V_2 , V_62 ) ;
F_27 ( V_2 , V_62 , V_228 ) ;
F_95 ( V_2 , V_62 , ( V_101 != 0 ) ) ;
return V_24 -> V_177 ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
unsigned int * V_118 )
{
unsigned int V_62 = F_134 ( V_24 -> V_208 ) ;
T_1 V_242 = F_31 ( V_62 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 -> V_177 ; V_8 ++ ) {
unsigned int V_5 ;
V_5 = F_10 ( V_2 , V_242 ) ;
V_5 |= ( F_10 ( V_2 , V_242 + 2 ) << 16 ) ;
V_118 [ V_8 ] = V_5 ;
}
return V_24 -> V_177 ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 , unsigned int * V_118 )
{
unsigned int V_62 = F_134 ( V_24 -> V_208 ) ;
F_30 ( V_2 , V_62 , V_118 [ 0 ] ) ;
F_98 ( V_2 , V_62 , 0 ) ;
F_108 ( V_2 , V_62 ) ;
F_98 ( V_2 , V_62 , 2 ) ;
return 1 ;
}
static void F_163 ( struct V_1 * V_2 , T_1 V_243 )
{
F_11 ( V_2 , V_120 , V_244 ) ;
F_11 ( V_2 , V_245 , V_243 ) ;
F_11 ( V_2 , V_120 , V_246 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
int V_62 ;
T_1 V_83 =
F_38 ( V_226 ) |
F_44 ( V_96 ) |
F_53 ( V_91 ) |
F_55 ( V_240 ) |
F_54 ( V_90 ) |
F_48 ( V_149 ) ;
for ( V_62 = 0 ; V_62 < V_247 ; V_62 ++ ) {
F_94 ( V_2 , V_62 , V_83 , true ) ;
F_100 ( V_2 , V_62 , 0 ) ;
F_32 ( V_2 , V_62 ) ;
F_95 ( V_2 , V_62 , V_141 ) ;
}
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_248 * V_249 = F_166 ( V_2 ) ;
struct V_34 * V_35 = V_2 -> V_36 ;
void * V_14 ;
T_7 V_250 ;
V_14 = F_167 ( V_249 , V_251 , & V_250 ) ;
if ( ! V_14 )
return - V_252 ;
V_35 -> V_152 . V_153 = V_14 ;
V_35 -> V_152 . V_180 = V_250 ;
V_14 = F_167 ( V_249 , V_251 , & V_250 ) ;
if ( ! V_14 )
return - V_252 ;
V_35 -> V_179 . V_153 = V_14 ;
V_35 -> V_179 . V_180 = V_250 ;
return 0 ;
}
static void F_168 ( struct V_1 * V_2 )
{
struct V_248 * V_249 = F_166 ( V_2 ) ;
struct V_34 * V_35 = V_2 -> V_36 ;
if ( ! V_35 )
return;
if ( V_35 -> V_179 . V_153 )
F_169 ( V_249 , V_251 ,
V_35 -> V_179 . V_153 ,
V_35 -> V_179 . V_180 ) ;
if ( V_35 -> V_152 . V_153 )
F_169 ( V_249 , V_251 ,
V_35 -> V_152 . V_153 ,
V_35 -> V_152 . V_180 ) ;
}
static int F_170 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
T_7 V_253 ;
T_1 V_62 ;
int V_8 ;
int V_30 ;
F_1 ( V_2 , V_254 | V_255 | V_256 ,
V_42 ) ;
F_3 ( V_257 |
( V_258 << V_259 ) | V_260 |
V_261 , V_2 -> V_6 + V_262 ) ;
F_3 ( V_263 , V_2 -> V_6 + V_264 ) ;
F_3 ( V_198 | V_201 , V_2 -> V_6 + V_197 ) ;
V_35 -> V_38 = 0xA0 ;
F_3 ( V_265 | V_266 ,
V_2 -> V_6 + V_267 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
F_3 ( V_265 , V_2 -> V_6 + V_267 ) ;
F_1 ( V_2 , V_27 , V_10 ) ;
V_30 = F_15 ( V_2 , NULL , NULL , F_13 , 0 ) ;
if ( V_30 )
return V_30 ;
}
F_3 ( V_268 , V_2 -> V_6 + V_269 ) ;
F_3 ( V_270 | V_271 , V_2 -> V_6 + V_272 ) ;
F_3 ( V_270 | V_271 | V_61 ,
V_2 -> V_6 + V_272 + 4 ) ;
F_3 ( V_273 , V_2 -> V_6 + V_274 ) ;
F_3 ( ( T_2 ) V_35 -> V_179 . V_180 ,
V_2 -> V_6 + V_181 ) ;
F_3 ( 0 , V_2 -> V_6 + V_275 ) ;
F_3 ( 0 , V_2 -> V_6 + V_276 ) ;
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
F_3 ( 0 , V_2 -> V_6 + V_277 ) ;
V_253 = V_35 -> V_152 . V_180 +
( V_278 * sizeof( T_2 ) ) ;
F_3 ( ( T_2 ) V_253 , V_2 -> V_6 + V_279 ) ;
F_3 ( ( T_2 ) ( V_253 + sizeof( T_2 ) ) ,
V_2 -> V_6 + V_280 ) ;
V_35 -> V_53 = ( T_2 * ) V_35 -> V_152 . V_153 +
V_278 ;
F_3 ( 8 , V_2 -> V_6 + V_281 ) ;
F_3 ( V_56 | V_57 | V_58 | V_61 ,
V_2 -> V_6 + F_22 ( 0 ) ) ;
F_3 ( V_282 , V_2 -> V_6 + F_22 ( 1 ) ) ;
F_3 ( V_283 , V_2 -> V_6 + V_274 ) ;
F_25 ( V_2 ) ;
V_30 = F_25 ( V_2 ) ;
if ( V_30 )
return V_30 ;
for ( V_62 = 0 ; V_62 < V_284 ; V_62 ++ ) {
V_30 = F_23 ( V_2 , V_62 , 0 ) ;
if ( V_30 )
return V_30 ;
}
F_164 ( V_2 ) ;
F_163 ( V_2 , ( F_10 ( V_2 , V_143 ) &
V_285 ) ) ;
F_153 ( V_2 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
unsigned long V_286 )
{
struct V_248 * V_249 = F_166 ( V_2 ) ;
struct V_34 * V_35 ;
struct V_21 * V_22 ;
int V_30 ;
V_35 = F_172 ( V_2 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_252 ;
V_30 = F_173 ( V_2 ) ;
if ( V_30 )
return V_30 ;
V_2 -> V_6 = F_174 ( V_249 , 0 ) ;
if ( ! V_2 -> V_6 )
return - V_252 ;
F_3 ( 0 , V_2 -> V_6 + V_170 ) ;
F_3 ( V_287 , V_2 -> V_6 + V_42 ) ;
V_30 = F_165 ( V_2 ) ;
if ( V_30 )
return V_30 ;
if ( V_249 -> V_162 ) {
V_30 = F_175 ( V_249 -> V_162 , F_126 , V_288 ,
V_2 -> V_289 , V_2 ) ;
if ( V_30 == 0 )
V_2 -> V_162 = V_249 -> V_162 ;
}
V_30 = F_176 ( V_2 , 6 ) ;
if ( V_30 )
return V_30 ;
V_22 = & V_2 -> V_290 [ 0 ] ;
V_22 -> type = V_291 ;
V_22 -> V_292 = V_293 | V_294 ;
V_22 -> V_295 = V_296 ;
V_22 -> V_297 = 0x3fff ;
V_22 -> V_298 = & V_299 ;
V_22 -> V_300 = V_296 ;
V_22 -> V_301 = F_133 ;
if ( V_2 -> V_162 ) {
V_2 -> V_125 = V_22 ;
V_22 -> V_292 |= V_302 ;
V_22 -> V_303 = F_142 ;
V_22 -> V_304 = F_143 ;
V_22 -> V_305 = F_151 ;
}
V_22 = & V_2 -> V_290 [ 1 ] ;
V_22 -> type = V_306 ;
V_22 -> V_292 = V_307 | V_293 ;
V_22 -> V_295 = V_284 ;
V_22 -> V_297 = 0x3fff ;
V_22 -> V_298 = & V_308 ;
V_22 -> V_309 = F_152 ;
V_30 = F_177 ( V_22 ) ;
if ( V_30 )
return V_30 ;
V_22 = & V_2 -> V_290 [ 2 ] ;
V_22 -> type = V_310 ;
V_22 -> V_292 = V_307 | V_293 ;
V_22 -> V_295 = 16 ;
V_22 -> V_297 = 1 ;
V_22 -> V_239 = 0xffff ;
V_22 -> V_36 = ( void * ) 0 ;
V_22 -> V_298 = & V_311 ;
V_22 -> V_312 = F_158 ;
V_22 -> V_313 = F_155 ;
V_22 = & V_2 -> V_290 [ 3 ] ;
V_22 -> type = V_310 ;
V_22 -> V_292 = V_307 | V_293 ;
V_22 -> V_295 = 16 ;
V_22 -> V_297 = 1 ;
V_22 -> V_239 = 0xffff ;
V_22 -> V_36 = ( void * ) 1 ;
V_22 -> V_298 = & V_311 ;
V_22 -> V_312 = F_158 ;
V_22 -> V_313 = F_155 ;
V_22 = & V_2 -> V_290 [ 4 ] ;
V_22 -> type = V_310 ;
V_22 -> V_292 = V_307 | V_293 ;
V_22 -> V_295 = 16 ;
V_22 -> V_297 = 1 ;
V_22 -> V_239 = 0xffff ;
V_22 -> V_36 = ( void * ) 2 ;
V_22 -> V_298 = & V_311 ;
V_22 -> V_312 = F_158 ;
V_22 -> V_313 = F_155 ;
V_22 = & V_2 -> V_290 [ 5 ] ;
V_22 -> type = V_314 ;
V_22 -> V_292 = V_307 | V_293 | V_315 ;
V_22 -> V_295 = V_247 ;
V_22 -> V_297 = 0xffffff ;
V_22 -> V_298 = & V_316 ;
V_22 -> V_312 = F_160 ;
V_22 -> V_301 = F_161 ;
V_22 -> V_309 = F_162 ;
return F_170 ( V_2 ) ;
}
static void F_178 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = V_2 -> V_36 ;
if ( V_35 ) {
V_35 -> V_128 = 0 ;
if ( V_2 -> V_6 ) {
F_3 ( 0 , V_2 -> V_6 + V_170 ) ;
F_3 ( V_172 | V_171 ,
V_2 -> V_6 + V_55 ) ;
F_163 ( V_2 , 0 ) ;
F_3 ( V_317 , V_2 -> V_6 + V_42 ) ;
F_3 ( V_318 , V_2 -> V_6 + V_274 ) ;
}
}
F_179 ( V_2 ) ;
F_168 ( V_2 ) ;
}
static int F_180 ( struct V_248 * V_2 ,
const struct V_319 * V_320 )
{
return F_181 ( V_2 , & V_321 , V_320 -> V_322 ) ;
}
