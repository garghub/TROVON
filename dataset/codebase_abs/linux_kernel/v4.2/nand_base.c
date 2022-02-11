static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
if ( V_3 & ( ( 1ULL << V_6 -> V_9 ) - 1 ) ) {
F_2 ( L_1 , V_10 ) ;
V_8 = - V_11 ;
}
if ( V_4 & ( ( 1ULL << V_6 -> V_9 ) - 1 ) ) {
F_2 ( L_2 , V_10 ) ;
V_8 = - V_11 ;
}
return V_8 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_4 ( & V_6 -> V_12 -> V_13 ) ;
V_6 -> V_12 -> V_14 = NULL ;
V_6 -> V_15 = V_16 ;
F_5 ( & V_6 -> V_12 -> V_17 ) ;
F_6 ( & V_6 -> V_12 -> V_13 ) ;
}
static T_3 F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_8 ( V_6 -> V_18 ) ;
}
static T_3 F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return ( T_3 ) F_10 ( F_11 ( V_6 -> V_18 ) ) ;
}
static T_4 F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
return F_11 ( V_6 -> V_18 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
switch ( V_19 ) {
case - 1 :
V_6 -> V_20 ( V_2 , V_21 , 0 | V_22 ) ;
break;
case 0 :
break;
default:
F_14 () ;
}
}
static void F_15 ( struct V_1 * V_2 , T_3 V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_24 ( V_2 , & V_23 , 1 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_3 V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_5 V_25 = V_23 ;
V_6 -> V_24 ( V_2 , ( T_3 * ) & V_25 , 2 ) ;
}
static void F_17 ( struct V_1 * V_2 , const T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_18 ( V_6 -> V_27 , V_26 , V_4 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_20 ( V_6 -> V_18 , V_26 , V_4 ) ;
}
static void F_21 ( struct V_1 * V_2 , const T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_28 = ( T_4 * ) V_26 ;
F_22 ( V_6 -> V_27 , V_28 , V_4 >> 1 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_3 * V_26 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 * V_28 = ( T_4 * ) V_26 ;
F_24 ( V_6 -> V_18 , V_28 , V_4 >> 1 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_3 , int V_29 )
{
int V_30 , V_19 , V_31 = 0 , V_32 = 0 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 V_33 ;
if ( V_6 -> V_34 & V_35 )
V_3 += V_2 -> V_36 - V_2 -> V_37 ;
V_30 = ( int ) ( V_3 >> V_6 -> V_38 ) & V_6 -> V_39 ;
if ( V_29 ) {
V_19 = ( int ) ( V_3 >> V_6 -> V_40 ) ;
F_26 ( V_2 , V_41 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
do {
if ( V_6 -> V_43 & V_44 ) {
V_6 -> V_45 ( V_2 , V_46 ,
V_6 -> V_47 & 0xFE , V_30 ) ;
V_33 = F_10 ( V_6 -> V_48 ( V_2 ) ) ;
if ( V_6 -> V_47 & 0x1 )
V_33 >>= 8 ;
else
V_33 &= 0xFF ;
} else {
V_6 -> V_45 ( V_2 , V_46 , V_6 -> V_47 ,
V_30 ) ;
V_33 = V_6 -> V_49 ( V_2 ) ;
}
if ( F_27 ( V_6 -> V_50 == 8 ) )
V_31 = V_33 != 0xFF ;
else
V_31 = F_28 ( V_33 ) < V_6 -> V_50 ;
V_3 += V_2 -> V_37 ;
V_30 = ( int ) ( V_3 >> V_6 -> V_38 ) & V_6 -> V_39 ;
V_32 ++ ;
} while ( ! V_31 && V_32 < 2 && ( V_6 -> V_34 & V_51 ) );
if ( V_29 ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
}
return V_31 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_52 V_53 ;
T_3 V_26 [ 2 ] = { 0 , 0 } ;
int V_8 = 0 , V_31 , V_32 = 0 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_54 = V_26 ;
V_53 . V_55 = V_6 -> V_47 ;
if ( V_6 -> V_43 & V_44 ) {
V_53 . V_55 &= ~ 0x01 ;
V_53 . V_4 = V_53 . V_56 = 2 ;
} else {
V_53 . V_4 = V_53 . V_56 = 1 ;
}
V_53 . V_57 = V_58 ;
if ( V_6 -> V_34 & V_35 )
V_3 += V_2 -> V_36 - V_2 -> V_37 ;
do {
V_31 = F_30 ( V_2 , V_3 , & V_53 ) ;
if ( ! V_8 )
V_8 = V_31 ;
V_32 ++ ;
V_3 += V_2 -> V_37 ;
} while ( ( V_6 -> V_34 & V_51 ) && V_32 < 2 );
return V_8 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_31 , V_8 = 0 ;
if ( ! ( V_6 -> V_34 & V_59 ) ) {
struct V_60 V_61 ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_2 = V_2 ;
V_61 . V_62 = V_3 ;
V_61 . V_4 = 1ULL << V_6 -> V_9 ;
F_32 ( V_2 , & V_61 , 0 ) ;
F_26 ( V_2 , V_63 ) ;
V_8 = V_6 -> V_64 ( V_2 , V_3 ) ;
F_3 ( V_2 ) ;
}
if ( V_6 -> V_65 ) {
V_31 = F_33 ( V_2 , V_3 ) ;
if ( ! V_8 )
V_8 = V_31 ;
}
if ( ! V_8 )
V_2 -> V_66 . V_67 ++ ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_43 & V_68 )
return 0 ;
V_6 -> V_45 ( V_2 , V_69 , - 1 , - 1 ) ;
return ( V_6 -> V_49 ( V_2 ) & V_70 ) ? 0 : 1 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_65 )
return 0 ;
return F_36 ( V_2 , V_3 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_3 , int V_29 ,
int V_71 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_65 )
return V_6 -> V_72 ( V_2 , V_3 , V_29 ) ;
return F_38 ( V_2 , V_3 , V_71 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned long V_73 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( V_6 -> V_74 ( V_2 ) )
break;
F_40 () ;
F_41 ( 1 ) ;
}
}
void F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_73 = V_75 + F_43 ( 20 ) ;
if ( F_44 () || V_76 )
return F_39 ( V_2 , 400 ) ;
F_45 ( V_77 , V_78 ) ;
do {
if ( V_6 -> V_74 ( V_2 ) )
break;
F_40 () ;
} while ( F_46 ( V_75 , V_73 ) );
F_45 ( V_77 , V_79 ) ;
}
static void F_47 ( struct V_1 * V_2 , unsigned long V_73 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
V_73 = V_75 + F_43 ( V_73 ) ;
do {
if ( ( V_6 -> V_49 ( V_2 ) & V_80 ) )
break;
F_40 () ;
} while ( F_46 ( V_75 , V_73 ) );
}
static void F_48 ( struct V_1 * V_2 , unsigned int V_81 ,
int V_82 , int V_83 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
int V_84 = V_85 | V_22 ;
if ( V_81 == V_86 ) {
int V_87 ;
if ( V_82 >= V_2 -> V_37 ) {
V_82 -= V_2 -> V_37 ;
V_87 = V_46 ;
} else if ( V_82 < 256 ) {
V_87 = V_88 ;
} else {
V_82 -= 256 ;
V_87 = V_89 ;
}
V_6 -> V_20 ( V_2 , V_87 , V_84 ) ;
V_84 &= ~ V_22 ;
}
V_6 -> V_20 ( V_2 , V_81 , V_84 ) ;
V_84 = V_90 | V_22 ;
if ( V_82 != - 1 ) {
if ( V_6 -> V_43 & V_44 &&
! F_49 ( V_81 ) )
V_82 >>= 1 ;
V_6 -> V_20 ( V_2 , V_82 , V_84 ) ;
V_84 &= ~ V_22 ;
}
if ( V_83 != - 1 ) {
V_6 -> V_20 ( V_2 , V_83 , V_84 ) ;
V_84 &= ~ V_22 ;
V_6 -> V_20 ( V_2 , V_83 >> 8 , V_84 ) ;
if ( V_6 -> V_91 > ( 32 << 20 ) )
V_6 -> V_20 ( V_2 , V_83 >> 16 , V_84 ) ;
}
V_6 -> V_20 ( V_2 , V_21 , V_92 | V_22 ) ;
switch ( V_81 ) {
case V_93 :
case V_94 :
case V_95 :
case V_86 :
case V_69 :
return;
case V_96 :
if ( V_6 -> V_74 )
break;
F_50 ( V_6 -> V_97 ) ;
V_6 -> V_20 ( V_2 , V_69 ,
V_85 | V_22 ) ;
V_6 -> V_20 ( V_2 ,
V_21 , V_92 | V_22 ) ;
F_47 ( V_2 , 250 ) ;
return;
default:
if ( ! V_6 -> V_74 ) {
F_50 ( V_6 -> V_97 ) ;
return;
}
}
F_51 ( 100 ) ;
F_42 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 , unsigned int V_81 ,
int V_82 , int V_83 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_81 == V_46 ) {
V_82 += V_2 -> V_37 ;
V_81 = V_88 ;
}
V_6 -> V_20 ( V_2 , V_81 , V_92 | V_98 | V_22 ) ;
if ( V_82 != - 1 || V_83 != - 1 ) {
int V_84 = V_22 | V_92 | V_99 ;
if ( V_82 != - 1 ) {
if ( V_6 -> V_43 & V_44 &&
! F_49 ( V_81 ) )
V_82 >>= 1 ;
V_6 -> V_20 ( V_2 , V_82 , V_84 ) ;
V_84 &= ~ V_22 ;
V_6 -> V_20 ( V_2 , V_82 >> 8 , V_84 ) ;
}
if ( V_83 != - 1 ) {
V_6 -> V_20 ( V_2 , V_83 , V_84 ) ;
V_6 -> V_20 ( V_2 , V_83 >> 8 ,
V_92 | V_99 ) ;
if ( V_6 -> V_91 > ( 128 << 20 ) )
V_6 -> V_20 ( V_2 , V_83 >> 16 ,
V_92 | V_99 ) ;
}
}
V_6 -> V_20 ( V_2 , V_21 , V_92 | V_22 ) ;
switch ( V_81 ) {
case V_100 :
case V_93 :
case V_94 :
case V_95 :
case V_86 :
case V_101 :
case V_69 :
return;
case V_96 :
if ( V_6 -> V_74 )
break;
F_50 ( V_6 -> V_97 ) ;
V_6 -> V_20 ( V_2 , V_69 ,
V_92 | V_98 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_92 | V_22 ) ;
F_47 ( V_2 , 250 ) ;
return;
case V_102 :
V_6 -> V_20 ( V_2 , V_103 ,
V_92 | V_98 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_92 | V_22 ) ;
return;
case V_88 :
V_6 -> V_20 ( V_2 , V_104 ,
V_92 | V_98 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_92 | V_22 ) ;
default:
if ( ! V_6 -> V_74 ) {
F_50 ( V_6 -> V_97 ) ;
return;
}
}
F_51 ( 100 ) ;
F_42 ( V_2 ) ;
}
static void F_53 ( struct V_5 * V_6 ,
struct V_1 * V_2 , int V_105 )
{
V_6 -> V_12 -> V_14 = V_6 ;
V_6 -> V_15 = V_105 ;
}
static int
F_26 ( struct V_1 * V_2 , int V_105 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_6 * V_13 = & V_6 -> V_12 -> V_13 ;
T_7 * V_17 = & V_6 -> V_12 -> V_17 ;
F_54 ( V_106 , V_107 ) ;
V_108:
F_4 ( V_13 ) ;
if ( ! V_6 -> V_12 -> V_14 )
V_6 -> V_12 -> V_14 = V_6 ;
if ( V_6 -> V_12 -> V_14 == V_6 && V_6 -> V_15 == V_16 ) {
V_6 -> V_15 = V_105 ;
F_6 ( V_13 ) ;
return 0 ;
}
if ( V_105 == V_109 ) {
if ( V_6 -> V_12 -> V_14 -> V_15 == V_109 ) {
V_6 -> V_15 = V_109 ;
F_6 ( V_13 ) ;
return 0 ;
}
}
F_55 ( V_110 ) ;
F_56 ( V_17 , & V_106 ) ;
F_6 ( V_13 ) ;
F_57 () ;
F_58 ( V_17 , & V_106 ) ;
goto V_108;
}
static void F_59 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned long V_73 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( V_6 -> V_74 ) {
if ( V_6 -> V_74 ( V_2 ) )
break;
} else {
if ( V_6 -> V_49 ( V_2 ) & V_80 )
break;
}
F_41 ( 1 ) ;
}
}
static int F_60 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_111 , V_15 = V_6 -> V_15 ;
unsigned long V_73 = ( V_15 == V_112 ? 400 : 20 ) ;
F_45 ( V_77 , V_78 ) ;
F_51 ( 100 ) ;
V_6 -> V_45 ( V_2 , V_69 , - 1 , - 1 ) ;
if ( F_44 () || V_76 )
F_59 ( V_2 , V_6 , V_73 ) ;
else {
V_73 = V_75 + F_43 ( V_73 ) ;
while ( F_46 ( V_75 , V_73 ) ) {
if ( V_6 -> V_74 ) {
if ( V_6 -> V_74 ( V_2 ) )
break;
} else {
if ( V_6 -> V_49 ( V_2 ) & V_80 )
break;
}
F_61 () ;
}
}
F_45 ( V_77 , V_79 ) ;
V_111 = ( int ) V_6 -> V_49 ( V_2 ) ;
F_62 ( ! ( V_111 & V_80 ) ) ;
return V_111 ;
}
static int F_63 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_113 )
{
int V_8 = 0 ;
int V_111 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_30 = V_3 >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_114 , - 1 , V_30 & V_6 -> V_39 ) ;
V_30 = ( V_3 + V_4 ) >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_115 , - 1 ,
( V_30 | V_113 ) & V_6 -> V_39 ) ;
V_111 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( V_111 & V_117 ) {
F_2 ( L_3 ,
V_10 , V_111 ) ;
V_8 = - V_118 ;
}
return V_8 ;
}
int F_64 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return - V_11 ;
if ( V_3 + V_4 == V_2 -> V_119 )
V_4 -= V_2 -> V_36 ;
F_26 ( V_2 , V_120 ) ;
V_19 = V_3 >> V_6 -> V_40 ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_8 = - V_118 ;
goto V_121;
}
V_8 = F_63 ( V_2 , V_3 , V_4 , 0 ) ;
V_121:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
int F_65 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_19 , V_111 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
return - V_11 ;
F_26 ( V_2 , V_122 ) ;
V_19 = V_3 >> V_6 -> V_40 ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_111 = V_123 ;
V_8 = - V_118 ;
goto V_121;
}
V_30 = V_3 >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_124 , - 1 , V_30 & V_6 -> V_39 ) ;
V_111 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( V_111 & V_117 ) {
F_2 ( L_3 ,
V_10 , V_111 ) ;
V_8 = - V_118 ;
goto V_121;
}
V_8 = F_63 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_121:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_125 , int V_30 )
{
V_6 -> V_126 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_125 )
V_6 -> V_126 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_26 ,
int V_125 , int V_30 )
{
int V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
T_3 * V_133 = V_6 -> V_127 ;
int V_134 , V_119 ;
for ( V_134 = V_6 -> V_130 . V_134 ; V_134 > 0 ; V_134 -- ) {
V_6 -> V_126 ( V_2 , V_26 , V_129 ) ;
V_26 += V_129 ;
if ( V_6 -> V_130 . V_135 ) {
V_6 -> V_126 ( V_2 , V_133 , V_6 -> V_130 . V_135 ) ;
V_133 += V_6 -> V_130 . V_135 ;
}
V_6 -> V_126 ( V_2 , V_133 , V_131 ) ;
V_133 += V_131 ;
if ( V_6 -> V_130 . V_136 ) {
V_6 -> V_126 ( V_2 , V_133 , V_6 -> V_130 . V_136 ) ;
V_133 += V_6 -> V_130 . V_136 ;
}
}
V_119 = V_2 -> V_128 - ( V_133 - V_6 -> V_127 ) ;
if ( V_119 )
V_6 -> V_126 ( V_2 , V_133 , V_119 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_125 , int V_30 )
{
int V_32 , V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
int V_137 = V_6 -> V_130 . V_134 ;
T_3 * V_28 = V_26 ;
T_3 * V_138 = V_6 -> V_139 -> V_140 ;
T_3 * V_141 = V_6 -> V_139 -> V_142 ;
T_8 * V_143 = V_6 -> V_130 . V_144 -> V_143 ;
unsigned int V_145 = 0 ;
V_6 -> V_130 . V_146 ( V_2 , V_6 , V_26 , 1 , V_30 ) ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 )
V_6 -> V_130 . V_147 ( V_2 , V_28 , & V_138 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_130 . V_148 ; V_32 ++ )
V_141 [ V_32 ] = V_6 -> V_127 [ V_143 [ V_32 ] ] ;
V_137 = V_6 -> V_130 . V_134 ;
V_28 = V_26 ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 ) {
int V_149 ;
V_149 = V_6 -> V_130 . V_150 ( V_2 , V_28 , & V_141 [ V_32 ] , & V_138 [ V_32 ] ) ;
if ( V_149 < 0 ) {
V_2 -> V_66 . V_151 ++ ;
} else {
V_2 -> V_66 . V_152 += V_149 ;
V_145 = F_69 (unsigned int, max_bitflips, stat) ;
}
}
return V_145 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_153 , T_8 V_154 , T_3 * V_155 ,
int V_30 )
{
int V_156 , V_157 , V_158 ;
T_8 * V_143 = V_6 -> V_130 . V_144 -> V_143 ;
T_3 * V_28 ;
int V_159 , V_32 , V_160 = 0 ;
int V_161 , V_162 , V_163 , V_164 ;
int V_165 = ( V_6 -> V_43 & V_44 ) ? 2 : 1 ;
int V_166 ;
unsigned int V_145 = 0 ;
V_156 = V_153 / V_6 -> V_130 . V_119 ;
V_157 = ( V_153 + V_154 - 1 ) / V_6 -> V_130 . V_119 ;
V_158 = V_157 - V_156 + 1 ;
V_166 = V_156 * V_6 -> V_130 . V_132 ;
V_161 = V_158 * V_6 -> V_130 . V_119 ;
V_162 = V_158 * V_6 -> V_130 . V_132 ;
V_159 = V_156 * V_6 -> V_130 . V_119 ;
if ( V_159 != 0 )
V_6 -> V_45 ( V_2 , V_102 , V_159 , - 1 ) ;
V_28 = V_155 + V_159 ;
V_6 -> V_126 ( V_2 , V_28 , V_161 ) ;
for ( V_32 = 0 ; V_32 < V_162 ; V_32 += V_6 -> V_130 . V_132 , V_28 += V_6 -> V_130 . V_119 )
V_6 -> V_130 . V_147 ( V_2 , V_28 , & V_6 -> V_139 -> V_140 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_162 - 1 ; V_32 ++ ) {
if ( V_143 [ V_32 + V_166 ] + 1 != V_143 [ V_32 + V_166 + 1 ] ) {
V_160 = 1 ;
break;
}
}
if ( V_160 ) {
V_6 -> V_45 ( V_2 , V_102 , V_2 -> V_37 , - 1 ) ;
V_6 -> V_126 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
} else {
V_164 = V_143 [ V_166 ] & ~ ( V_165 - 1 ) ;
V_163 = V_162 ;
if ( V_143 [ V_166 ] & ( V_165 - 1 ) )
V_163 ++ ;
if ( V_143 [ V_166 + ( V_158 * V_6 -> V_130 . V_132 ) ] & ( V_165 - 1 ) )
V_163 ++ ;
V_6 -> V_45 ( V_2 , V_102 ,
V_2 -> V_37 + V_164 , - 1 ) ;
V_6 -> V_126 ( V_2 , & V_6 -> V_127 [ V_164 ] , V_163 ) ;
}
for ( V_32 = 0 ; V_32 < V_162 ; V_32 ++ )
V_6 -> V_139 -> V_142 [ V_32 ] = V_6 -> V_127 [ V_143 [ V_32 + V_166 ] ] ;
V_28 = V_155 + V_159 ;
for ( V_32 = 0 ; V_32 < V_162 ; V_32 += V_6 -> V_130 . V_132 , V_28 += V_6 -> V_130 . V_119 ) {
int V_149 ;
V_149 = V_6 -> V_130 . V_150 ( V_2 , V_28 ,
& V_6 -> V_139 -> V_142 [ V_32 ] , & V_6 -> V_139 -> V_140 [ V_32 ] ) ;
if ( V_149 < 0 ) {
V_2 -> V_66 . V_151 ++ ;
} else {
V_2 -> V_66 . V_152 += V_149 ;
V_145 = F_69 (unsigned int, max_bitflips, stat) ;
}
}
return V_145 ;
}
static int F_71 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_125 , int V_30 )
{
int V_32 , V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
int V_137 = V_6 -> V_130 . V_134 ;
T_3 * V_28 = V_26 ;
T_3 * V_138 = V_6 -> V_139 -> V_140 ;
T_3 * V_141 = V_6 -> V_139 -> V_142 ;
T_8 * V_143 = V_6 -> V_130 . V_144 -> V_143 ;
unsigned int V_145 = 0 ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 ) {
V_6 -> V_130 . V_167 ( V_2 , V_168 ) ;
V_6 -> V_126 ( V_2 , V_28 , V_129 ) ;
V_6 -> V_130 . V_147 ( V_2 , V_28 , & V_138 [ V_32 ] ) ;
}
V_6 -> V_126 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_130 . V_148 ; V_32 ++ )
V_141 [ V_32 ] = V_6 -> V_127 [ V_143 [ V_32 ] ] ;
V_137 = V_6 -> V_130 . V_134 ;
V_28 = V_26 ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 ) {
int V_149 ;
V_149 = V_6 -> V_130 . V_150 ( V_2 , V_28 , & V_141 [ V_32 ] , & V_138 [ V_32 ] ) ;
if ( V_149 < 0 ) {
V_2 -> V_66 . V_151 ++ ;
} else {
V_2 -> V_66 . V_152 += V_149 ;
V_145 = F_69 (unsigned int, max_bitflips, stat) ;
}
}
return V_145 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_26 , int V_125 , int V_30 )
{
int V_32 , V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
int V_137 = V_6 -> V_130 . V_134 ;
T_3 * V_28 = V_26 ;
T_3 * V_141 = V_6 -> V_139 -> V_142 ;
T_8 * V_143 = V_6 -> V_130 . V_144 -> V_143 ;
T_3 * V_138 = V_6 -> V_139 -> V_140 ;
unsigned int V_145 = 0 ;
V_6 -> V_45 ( V_2 , V_46 , 0 , V_30 ) ;
V_6 -> V_126 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
V_6 -> V_45 ( V_2 , V_88 , 0 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_130 . V_148 ; V_32 ++ )
V_141 [ V_32 ] = V_6 -> V_127 [ V_143 [ V_32 ] ] ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 ) {
int V_149 ;
V_6 -> V_130 . V_167 ( V_2 , V_168 ) ;
V_6 -> V_126 ( V_2 , V_28 , V_129 ) ;
V_6 -> V_130 . V_147 ( V_2 , V_28 , & V_138 [ V_32 ] ) ;
V_149 = V_6 -> V_130 . V_150 ( V_2 , V_28 , & V_141 [ V_32 ] , NULL ) ;
if ( V_149 < 0 ) {
V_2 -> V_66 . V_151 ++ ;
} else {
V_2 -> V_66 . V_152 += V_149 ;
V_145 = F_69 (unsigned int, max_bitflips, stat) ;
}
}
return V_145 ;
}
static int F_73 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_125 , int V_30 )
{
int V_32 , V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
int V_137 = V_6 -> V_130 . V_134 ;
T_3 * V_28 = V_26 ;
T_3 * V_133 = V_6 -> V_127 ;
unsigned int V_145 = 0 ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 ) {
int V_149 ;
V_6 -> V_130 . V_167 ( V_2 , V_168 ) ;
V_6 -> V_126 ( V_2 , V_28 , V_129 ) ;
if ( V_6 -> V_130 . V_135 ) {
V_6 -> V_126 ( V_2 , V_133 , V_6 -> V_130 . V_135 ) ;
V_133 += V_6 -> V_130 . V_135 ;
}
V_6 -> V_130 . V_167 ( V_2 , V_169 ) ;
V_6 -> V_126 ( V_2 , V_133 , V_131 ) ;
V_149 = V_6 -> V_130 . V_150 ( V_2 , V_28 , V_133 , NULL ) ;
if ( V_149 < 0 ) {
V_2 -> V_66 . V_151 ++ ;
} else {
V_2 -> V_66 . V_152 += V_149 ;
V_145 = F_69 (unsigned int, max_bitflips, stat) ;
}
V_133 += V_131 ;
if ( V_6 -> V_130 . V_136 ) {
V_6 -> V_126 ( V_2 , V_133 , V_6 -> V_130 . V_136 ) ;
V_133 += V_6 -> V_130 . V_136 ;
}
}
V_32 = V_2 -> V_128 - ( V_133 - V_6 -> V_127 ) ;
if ( V_32 )
V_6 -> V_126 ( V_2 , V_133 , V_32 ) ;
return V_145 ;
}
static T_3 * F_74 ( struct V_5 * V_6 , T_3 * V_133 ,
struct V_52 * V_53 , T_9 V_4 )
{
switch ( V_53 -> V_57 ) {
case V_58 :
case V_170 :
memcpy ( V_133 , V_6 -> V_127 + V_53 -> V_55 , V_4 ) ;
return V_133 + V_4 ;
case V_171 : {
struct V_172 * free = V_6 -> V_130 . V_144 -> V_173 ;
T_8 V_174 = 0 , V_175 = V_53 -> V_55 ;
T_9 V_132 = 0 ;
for (; free -> V_176 && V_4 ; free ++ , V_4 -= V_132 ) {
if ( F_75 ( V_175 ) ) {
if ( V_175 >= free -> V_176 ) {
V_175 -= free -> V_176 ;
continue;
}
V_174 = free -> V_177 + V_175 ;
V_132 = F_76 ( T_9 , V_4 ,
( free -> V_176 - V_175 ) ) ;
V_175 = 0 ;
} else {
V_132 = F_76 ( T_9 , V_4 , free -> V_176 ) ;
V_174 = free -> V_177 ;
}
memcpy ( V_133 , V_6 -> V_127 + V_174 , V_132 ) ;
V_133 += V_132 ;
}
return V_133 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_77 ( struct V_1 * V_2 , int V_178 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_6 , V_178 ) ;
if ( V_178 >= V_6 -> V_179 )
return - V_11 ;
if ( ! V_6 -> V_180 )
return - V_181 ;
return V_6 -> V_180 ( V_2 , V_178 ) ;
}
static int F_78 ( struct V_1 * V_2 , T_1 V_182 ,
struct V_52 * V_53 )
{
int V_19 , V_30 , V_183 , V_184 , V_132 , V_185 , V_125 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
T_8 V_154 = V_53 -> V_4 ;
T_8 V_186 = V_53 -> V_56 ;
T_8 V_187 = V_53 -> V_57 == V_171 ?
V_2 -> V_188 : V_2 -> V_128 ;
T_3 * V_155 , * V_133 , * V_26 ;
int V_189 ;
unsigned int V_145 = 0 ;
int V_178 = 0 ;
bool V_190 = false ;
V_19 = ( int ) ( V_182 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_183 = ( int ) ( V_182 >> V_6 -> V_38 ) ;
V_30 = V_183 & V_6 -> V_39 ;
V_184 = ( int ) ( V_182 & ( V_2 -> V_37 - 1 ) ) ;
V_26 = V_53 -> V_191 ;
V_133 = V_53 -> V_54 ;
V_125 = V_133 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_192 = V_2 -> V_66 . V_151 ;
V_132 = F_79 ( V_2 -> V_37 - V_184 , V_154 ) ;
V_185 = ( V_132 == V_2 -> V_37 ) ;
if ( ! V_185 )
V_189 = 1 ;
else if ( V_6 -> V_43 & V_193 )
V_189 = ! F_80 ( V_26 ) ;
else
V_189 = 0 ;
if ( V_183 != V_6 -> V_194 || V_133 ) {
V_155 = V_189 ? V_6 -> V_139 -> V_195 : V_26 ;
if ( V_189 && V_185 )
F_2 ( L_7 ,
V_10 , V_26 ) ;
V_196:
V_6 -> V_45 ( V_2 , V_88 , 0x00 , V_30 ) ;
if ( F_75 ( V_53 -> V_57 == V_170 ) )
V_8 = V_6 -> V_130 . V_146 ( V_2 , V_6 , V_155 ,
V_125 ,
V_30 ) ;
else if ( ! V_185 && F_81 ( V_6 ) &&
! V_133 )
V_8 = V_6 -> V_130 . V_197 ( V_2 , V_6 ,
V_184 , V_132 , V_155 ,
V_30 ) ;
else
V_8 = V_6 -> V_130 . V_198 ( V_2 , V_6 , V_155 ,
V_125 , V_30 ) ;
if ( V_8 < 0 ) {
if ( V_189 )
V_6 -> V_194 = - 1 ;
break;
}
V_145 = F_69 (unsigned int, max_bitflips, ret) ;
if ( V_189 ) {
if ( ! F_81 ( V_6 ) && ! V_133 &&
! ( V_2 -> V_66 . V_151 - V_192 ) &&
( V_53 -> V_57 != V_170 ) ) {
V_6 -> V_194 = V_183 ;
V_6 -> V_199 = V_8 ;
} else {
V_6 -> V_194 = - 1 ;
}
memcpy ( V_26 , V_6 -> V_139 -> V_195 + V_184 , V_132 ) ;
}
if ( F_75 ( V_133 ) ) {
int V_200 = F_79 ( V_186 , V_187 ) ;
if ( V_200 ) {
V_133 = F_74 ( V_6 ,
V_133 , V_53 , V_200 ) ;
V_186 -= V_200 ;
}
}
if ( V_6 -> V_43 & V_201 ) {
if ( ! V_6 -> V_74 )
F_50 ( V_6 -> V_97 ) ;
else
F_42 ( V_2 ) ;
}
if ( V_2 -> V_66 . V_151 - V_192 ) {
if ( V_178 + 1 < V_6 -> V_179 ) {
V_178 ++ ;
V_8 = F_77 ( V_2 ,
V_178 ) ;
if ( V_8 < 0 )
break;
V_2 -> V_66 . V_151 = V_192 ;
goto V_196;
} else {
V_190 = true ;
}
}
V_26 += V_132 ;
} else {
memcpy ( V_26 , V_6 -> V_139 -> V_195 + V_184 , V_132 ) ;
V_26 += V_132 ;
V_145 = F_69 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_154 -= V_132 ;
if ( V_178 ) {
V_8 = F_77 ( V_2 , 0 ) ;
if ( V_8 < 0 )
break;
V_178 = 0 ;
}
if ( ! V_154 )
break;
V_184 = 0 ;
V_183 ++ ;
V_30 = V_183 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_6 -> V_42 ( V_2 , - 1 ) ;
V_53 -> V_202 = V_53 -> V_4 - ( T_9 ) V_154 ;
if ( V_133 )
V_53 -> V_203 = V_53 -> V_56 - V_186 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_190 )
return - V_204 ;
return V_145 ;
}
static int F_82 ( struct V_1 * V_2 , T_1 V_182 , T_9 V_4 ,
T_9 * V_202 , T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_41 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_4 = V_4 ;
V_53 . V_191 = V_26 ;
V_53 . V_57 = V_58 ;
V_8 = F_78 ( V_2 , V_182 , & V_53 ) ;
* V_202 = V_53 . V_202 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
V_6 -> V_45 ( V_2 , V_46 , 0 , V_30 ) ;
V_6 -> V_126 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
int V_176 = V_2 -> V_128 ;
int V_205 = V_6 -> V_130 . V_132 + V_6 -> V_130 . V_135 + V_6 -> V_130 . V_136 ;
int V_129 = V_6 -> V_130 . V_119 ;
T_3 * V_155 = V_6 -> V_127 ;
int V_32 , V_200 , V_206 = 0 , V_207 ;
V_6 -> V_45 ( V_2 , V_88 , V_6 -> V_130 . V_119 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_130 . V_134 ; V_32 ++ ) {
if ( V_206 ) {
V_207 = V_129 + V_32 * ( V_129 + V_205 ) ;
if ( V_2 -> V_37 > 512 )
V_6 -> V_45 ( V_2 , V_102 , V_207 , - 1 ) ;
else
V_6 -> V_45 ( V_2 , V_88 , V_207 , V_30 ) ;
} else
V_206 = 1 ;
V_200 = F_76 ( int , V_176 , V_205 ) ;
V_6 -> V_126 ( V_2 , V_155 , V_200 ) ;
V_155 += V_200 ;
V_176 -= V_200 ;
}
if ( V_176 > 0 )
V_6 -> V_126 ( V_2 , V_155 , V_176 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
int V_111 = 0 ;
const T_3 * V_26 = V_6 -> V_127 ;
int V_176 = V_2 -> V_128 ;
V_6 -> V_45 ( V_2 , V_86 , V_2 -> V_37 , V_30 ) ;
V_6 -> V_24 ( V_2 , V_26 , V_176 ) ;
V_6 -> V_45 ( V_2 , V_93 , - 1 , - 1 ) ;
V_111 = V_6 -> V_116 ( V_2 , V_6 ) ;
return V_111 & V_117 ? - V_118 : 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_30 )
{
int V_205 = V_6 -> V_130 . V_132 + V_6 -> V_130 . V_135 + V_6 -> V_130 . V_136 ;
int V_129 = V_6 -> V_130 . V_119 , V_176 = V_2 -> V_128 ;
int V_32 , V_4 , V_207 , V_111 = 0 , V_208 = 0 , V_134 = V_6 -> V_130 . V_134 ;
const T_3 * V_155 = V_6 -> V_127 ;
if ( ! V_6 -> V_130 . V_135 && ! V_6 -> V_130 . V_136 ) {
V_207 = V_134 * ( V_129 + V_205 ) ;
V_134 = 0 ;
} else
V_207 = V_129 ;
V_6 -> V_45 ( V_2 , V_86 , V_207 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_134 ; V_32 ++ ) {
if ( V_208 ) {
if ( V_2 -> V_37 <= 512 ) {
T_8 V_209 = 0xFFFFFFFF ;
V_4 = V_129 ;
while ( V_4 > 0 ) {
int V_210 = F_76 ( int , V_4 , 4 ) ;
V_6 -> V_24 ( V_2 , ( T_3 * ) & V_209 ,
V_210 ) ;
V_4 -= V_210 ;
}
} else {
V_207 = V_129 + V_32 * ( V_129 + V_205 ) ;
V_6 -> V_45 ( V_2 , V_101 , V_207 , - 1 ) ;
}
} else
V_208 = 1 ;
V_4 = F_76 ( int , V_176 , V_205 ) ;
V_6 -> V_24 ( V_2 , V_155 , V_4 ) ;
V_155 += V_4 ;
V_176 -= V_4 ;
}
if ( V_176 > 0 )
V_6 -> V_24 ( V_2 , V_155 , V_176 ) ;
V_6 -> V_45 ( V_2 , V_93 , - 1 , - 1 ) ;
V_111 = V_6 -> V_116 ( V_2 , V_6 ) ;
return V_111 & V_117 ? - V_118 : 0 ;
}
static int F_87 ( struct V_1 * V_2 , T_1 V_182 ,
struct V_52 * V_53 )
{
int V_30 , V_183 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_211 V_212 ;
int V_154 = V_53 -> V_56 ;
int V_4 ;
T_3 * V_26 = V_53 -> V_54 ;
int V_8 = 0 ;
F_2 ( L_8 ,
V_10 , ( unsigned long long ) V_182 , V_154 ) ;
V_212 = V_2 -> V_66 ;
if ( V_53 -> V_57 == V_171 )
V_4 = V_6 -> V_130 . V_144 -> V_188 ;
else
V_4 = V_2 -> V_128 ;
if ( F_75 ( V_53 -> V_55 >= V_4 ) ) {
F_2 ( L_9 ,
V_10 ) ;
return - V_11 ;
}
if ( F_75 ( V_182 >= V_2 -> V_119 ||
V_53 -> V_55 + V_154 > ( ( V_2 -> V_119 >> V_6 -> V_38 ) -
( V_182 >> V_6 -> V_38 ) ) * V_4 ) ) {
F_2 ( L_10 ,
V_10 ) ;
return - V_11 ;
}
V_19 = ( int ) ( V_182 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_183 = ( int ) ( V_182 >> V_6 -> V_38 ) ;
V_30 = V_183 & V_6 -> V_39 ;
while ( 1 ) {
if ( V_53 -> V_57 == V_170 )
V_8 = V_6 -> V_130 . V_213 ( V_2 , V_6 , V_30 ) ;
else
V_8 = V_6 -> V_130 . V_214 ( V_2 , V_6 , V_30 ) ;
if ( V_8 < 0 )
break;
V_4 = F_79 ( V_4 , V_154 ) ;
V_26 = F_74 ( V_6 , V_26 , V_53 , V_4 ) ;
if ( V_6 -> V_43 & V_201 ) {
if ( ! V_6 -> V_74 )
F_50 ( V_6 -> V_97 ) ;
else
F_42 ( V_2 ) ;
}
V_154 -= V_4 ;
if ( ! V_154 )
break;
V_183 ++ ;
V_30 = V_183 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_6 -> V_42 ( V_2 , - 1 ) ;
V_53 -> V_203 = V_53 -> V_56 - V_154 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_66 . V_151 - V_212 . V_151 )
return - V_204 ;
return V_2 -> V_66 . V_152 - V_212 . V_152 ? - V_215 : 0 ;
}
static int F_88 ( struct V_1 * V_2 , T_1 V_182 ,
struct V_52 * V_53 )
{
int V_8 = - V_216 ;
V_53 -> V_202 = 0 ;
if ( V_53 -> V_191 && ( V_182 + V_53 -> V_4 ) > V_2 -> V_119 ) {
F_2 ( L_10 ,
V_10 ) ;
return - V_11 ;
}
F_26 ( V_2 , V_41 ) ;
switch ( V_53 -> V_57 ) {
case V_58 :
case V_171 :
case V_170 :
break;
default:
goto V_121;
}
if ( ! V_53 -> V_191 )
V_8 = F_87 ( V_2 , V_182 , V_53 ) ;
else
V_8 = F_78 ( V_2 , V_182 , V_53 ) ;
V_121:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_125 )
{
V_6 -> V_24 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_125 )
V_6 -> V_24 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_26 , int V_125 )
{
int V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
T_3 * V_133 = V_6 -> V_127 ;
int V_134 , V_119 ;
for ( V_134 = V_6 -> V_130 . V_134 ; V_134 > 0 ; V_134 -- ) {
V_6 -> V_24 ( V_2 , V_26 , V_129 ) ;
V_26 += V_129 ;
if ( V_6 -> V_130 . V_135 ) {
V_6 -> V_24 ( V_2 , V_133 , V_6 -> V_130 . V_135 ) ;
V_133 += V_6 -> V_130 . V_135 ;
}
V_6 -> V_24 ( V_2 , V_133 , V_131 ) ;
V_133 += V_131 ;
if ( V_6 -> V_130 . V_136 ) {
V_6 -> V_24 ( V_2 , V_133 , V_6 -> V_130 . V_136 ) ;
V_133 += V_6 -> V_130 . V_136 ;
}
}
V_119 = V_2 -> V_128 - ( V_133 - V_6 -> V_127 ) ;
if ( V_119 )
V_6 -> V_24 ( V_2 , V_133 , V_119 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_125 )
{
int V_32 , V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
int V_137 = V_6 -> V_130 . V_134 ;
T_3 * V_138 = V_6 -> V_139 -> V_140 ;
const T_3 * V_28 = V_26 ;
T_8 * V_143 = V_6 -> V_130 . V_144 -> V_143 ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 )
V_6 -> V_130 . V_147 ( V_2 , V_28 , & V_138 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_130 . V_148 ; V_32 ++ )
V_6 -> V_127 [ V_143 [ V_32 ] ] = V_138 [ V_32 ] ;
return V_6 -> V_130 . V_217 ( V_2 , V_6 , V_26 , 1 ) ;
}
static int F_92 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_125 )
{
int V_32 , V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
int V_137 = V_6 -> V_130 . V_134 ;
T_3 * V_138 = V_6 -> V_139 -> V_140 ;
const T_3 * V_28 = V_26 ;
T_8 * V_143 = V_6 -> V_130 . V_144 -> V_143 ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 ) {
V_6 -> V_130 . V_167 ( V_2 , V_218 ) ;
V_6 -> V_24 ( V_2 , V_28 , V_129 ) ;
V_6 -> V_130 . V_147 ( V_2 , V_28 , & V_138 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 < V_6 -> V_130 . V_148 ; V_32 ++ )
V_6 -> V_127 [ V_143 [ V_32 ] ] = V_138 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_8 V_177 ,
T_8 V_219 , const T_3 * V_26 ,
int V_125 )
{
T_3 * V_220 = V_6 -> V_127 ;
T_3 * V_138 = V_6 -> V_139 -> V_140 ;
int V_221 = V_6 -> V_130 . V_119 ;
int V_222 = V_6 -> V_130 . V_132 ;
int V_223 = V_6 -> V_130 . V_134 ;
T_8 * V_143 = V_6 -> V_130 . V_144 -> V_143 ;
T_8 V_156 = V_177 / V_221 ;
T_8 V_157 = ( V_177 + V_219 - 1 ) / V_221 ;
int V_224 = V_2 -> V_128 / V_223 ;
int V_225 , V_32 ;
for ( V_225 = 0 ; V_225 < V_223 ; V_225 ++ ) {
V_6 -> V_130 . V_167 ( V_2 , V_218 ) ;
V_6 -> V_24 ( V_2 , V_26 , V_221 ) ;
if ( ( V_225 < V_156 ) || ( V_225 > V_157 ) )
memset ( V_138 , 0xff , V_222 ) ;
else
V_6 -> V_130 . V_147 ( V_2 , V_26 , V_138 ) ;
if ( ! V_125 || ( V_225 < V_156 ) || ( V_225 > V_157 ) )
memset ( V_220 , 0xff , V_224 ) ;
V_26 += V_221 ;
V_138 += V_222 ;
V_220 += V_224 ;
}
V_138 = V_6 -> V_139 -> V_140 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_130 . V_148 ; V_32 ++ )
V_6 -> V_127 [ V_143 [ V_32 ] ] = V_138 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_127 , V_2 -> V_128 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_26 , int V_125 )
{
int V_32 , V_129 = V_6 -> V_130 . V_119 ;
int V_131 = V_6 -> V_130 . V_132 ;
int V_137 = V_6 -> V_130 . V_134 ;
const T_3 * V_28 = V_26 ;
T_3 * V_133 = V_6 -> V_127 ;
for ( V_32 = 0 ; V_137 ; V_137 -- , V_32 += V_131 , V_28 += V_129 ) {
V_6 -> V_130 . V_167 ( V_2 , V_218 ) ;
V_6 -> V_24 ( V_2 , V_28 , V_129 ) ;
if ( V_6 -> V_130 . V_135 ) {
V_6 -> V_24 ( V_2 , V_133 , V_6 -> V_130 . V_135 ) ;
V_133 += V_6 -> V_130 . V_135 ;
}
V_6 -> V_130 . V_147 ( V_2 , V_28 , V_133 ) ;
V_6 -> V_24 ( V_2 , V_133 , V_131 ) ;
V_133 += V_131 ;
if ( V_6 -> V_130 . V_136 ) {
V_6 -> V_24 ( V_2 , V_133 , V_6 -> V_130 . V_136 ) ;
V_133 += V_6 -> V_130 . V_136 ;
}
}
V_32 = V_2 -> V_128 - ( V_133 - V_6 -> V_127 ) ;
if ( V_32 )
V_6 -> V_24 ( V_2 , V_133 , V_32 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_177 , int V_219 , const T_3 * V_26 ,
int V_125 , int V_30 , int V_226 , int V_227 )
{
int V_111 , V_228 ;
if ( ! ( V_6 -> V_43 & V_229 ) &&
V_6 -> V_130 . V_230 )
V_228 = V_177 || ( V_219 < V_2 -> V_37 ) ;
else
V_228 = 0 ;
V_6 -> V_45 ( V_2 , V_86 , 0x00 , V_30 ) ;
if ( F_75 ( V_227 ) )
V_111 = V_6 -> V_130 . V_217 ( V_2 , V_6 , V_26 ,
V_125 ) ;
else if ( V_228 )
V_111 = V_6 -> V_130 . V_230 ( V_2 , V_6 , V_177 , V_219 ,
V_26 , V_125 ) ;
else
V_111 = V_6 -> V_130 . V_231 ( V_2 , V_6 , V_26 , V_125 ) ;
if ( V_111 < 0 )
return V_111 ;
V_226 = 0 ;
if ( ! V_226 || ! F_96 ( V_6 ) ) {
V_6 -> V_45 ( V_2 , V_93 , - 1 , - 1 ) ;
V_111 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( ( V_111 & V_117 ) && ( V_6 -> V_232 ) )
V_111 = V_6 -> V_232 ( V_2 , V_6 , V_63 , V_111 ,
V_30 ) ;
if ( V_111 & V_117 )
return - V_118 ;
} else {
V_6 -> V_45 ( V_2 , V_100 , - 1 , - 1 ) ;
V_111 = V_6 -> V_116 ( V_2 , V_6 ) ;
}
return 0 ;
}
static T_3 * F_97 ( struct V_1 * V_2 , T_3 * V_133 , T_9 V_4 ,
struct V_52 * V_53 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memset ( V_6 -> V_127 , 0xff , V_2 -> V_128 ) ;
switch ( V_53 -> V_57 ) {
case V_58 :
case V_170 :
memcpy ( V_6 -> V_127 + V_53 -> V_55 , V_133 , V_4 ) ;
return V_133 + V_4 ;
case V_171 : {
struct V_172 * free = V_6 -> V_130 . V_144 -> V_173 ;
T_8 V_174 = 0 , V_233 = V_53 -> V_55 ;
T_9 V_132 = 0 ;
for (; free -> V_176 && V_4 ; free ++ , V_4 -= V_132 ) {
if ( F_75 ( V_233 ) ) {
if ( V_233 >= free -> V_176 ) {
V_233 -= free -> V_176 ;
continue;
}
V_174 = free -> V_177 + V_233 ;
V_132 = F_76 ( T_9 , V_4 ,
( free -> V_176 - V_233 ) ) ;
V_233 = 0 ;
} else {
V_132 = F_76 ( T_9 , V_4 , free -> V_176 ) ;
V_174 = free -> V_177 ;
}
memcpy ( V_6 -> V_127 + V_174 , V_133 , V_132 ) ;
V_133 += V_132 ;
}
return V_133 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_98 ( struct V_1 * V_2 , T_1 V_234 ,
struct V_52 * V_53 )
{
int V_19 , V_183 , V_30 , V_235 , V_82 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_8 V_236 = V_53 -> V_4 ;
T_8 V_237 = V_53 -> V_56 ;
T_8 V_238 = V_53 -> V_57 == V_171 ?
V_2 -> V_188 : V_2 -> V_128 ;
T_3 * V_133 = V_53 -> V_54 ;
T_3 * V_26 = V_53 -> V_191 ;
int V_8 ;
int V_125 = V_133 ? 1 : 0 ;
V_53 -> V_202 = 0 ;
if ( ! V_236 )
return 0 ;
if ( F_99 ( V_234 ) || F_99 ( V_53 -> V_4 ) ) {
F_100 ( L_11 ,
V_10 ) ;
return - V_11 ;
}
V_82 = V_234 & ( V_2 -> V_37 - 1 ) ;
V_19 = ( int ) ( V_234 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
V_8 = - V_118 ;
goto V_239;
}
V_183 = ( int ) ( V_234 >> V_6 -> V_38 ) ;
V_30 = V_183 & V_6 -> V_39 ;
V_235 = ( 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ) - 1 ;
if ( V_234 <= ( ( T_1 ) V_6 -> V_194 << V_6 -> V_38 ) &&
( ( T_1 ) V_6 -> V_194 << V_6 -> V_38 ) < ( V_234 + V_53 -> V_4 ) )
V_6 -> V_194 = - 1 ;
if ( V_133 && V_53 -> V_55 && ( V_53 -> V_55 + V_53 -> V_56 > V_238 ) ) {
V_8 = - V_11 ;
goto V_239;
}
while ( 1 ) {
int V_132 = V_2 -> V_37 ;
int V_226 = V_236 > V_132 && V_30 != V_235 ;
T_3 * V_240 = V_26 ;
int V_189 ;
int V_241 = ( V_82 || V_236 < ( V_2 -> V_37 - 1 ) ) ;
if ( V_241 )
V_189 = 1 ;
else if ( V_6 -> V_43 & V_193 )
V_189 = ! F_80 ( V_26 ) ;
else
V_189 = 0 ;
if ( V_189 ) {
F_2 ( L_12 ,
V_10 , V_26 ) ;
V_226 = 0 ;
if ( V_241 )
V_132 = F_76 ( int , V_132 - V_82 , V_236 ) ;
V_6 -> V_194 = - 1 ;
memset ( V_6 -> V_139 -> V_195 , 0xff , V_2 -> V_37 ) ;
memcpy ( & V_6 -> V_139 -> V_195 [ V_82 ] , V_26 , V_132 ) ;
V_240 = V_6 -> V_139 -> V_195 ;
}
if ( F_75 ( V_133 ) ) {
T_9 V_4 = F_79 ( V_237 , V_238 ) ;
V_133 = F_97 ( V_2 , V_133 , V_4 , V_53 ) ;
V_237 -= V_4 ;
} else {
memset ( V_6 -> V_127 , 0xff , V_2 -> V_128 ) ;
}
V_8 = V_6 -> V_231 ( V_2 , V_6 , V_82 , V_132 , V_240 ,
V_125 , V_30 , V_226 ,
( V_53 -> V_57 == V_170 ) ) ;
if ( V_8 )
break;
V_236 -= V_132 ;
if ( ! V_236 )
break;
V_82 = 0 ;
V_26 += V_132 ;
V_183 ++ ;
V_30 = V_183 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_53 -> V_202 = V_53 -> V_4 - V_236 ;
if ( F_75 ( V_133 ) )
V_53 -> V_203 = V_53 -> V_56 ;
V_239:
V_6 -> V_42 ( V_2 , - 1 ) ;
return V_8 ;
}
static int F_101 ( struct V_1 * V_2 , T_1 V_234 , T_9 V_4 ,
T_9 * V_202 , const T_3 * V_26 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_52 V_53 ;
int V_8 ;
F_59 ( V_2 , V_6 , 400 ) ;
F_53 ( V_6 , V_2 , V_63 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_4 = V_4 ;
V_53 . V_191 = ( T_3 * ) V_26 ;
V_53 . V_57 = V_58 ;
V_8 = F_98 ( V_2 , V_234 , & V_53 ) ;
* V_202 = V_53 . V_202 ;
return V_8 ;
}
static int F_102 ( struct V_1 * V_2 , T_1 V_234 , T_9 V_4 ,
T_9 * V_202 , const T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_63 ) ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . V_4 = V_4 ;
V_53 . V_191 = ( T_3 * ) V_26 ;
V_53 . V_57 = V_58 ;
V_8 = F_98 ( V_2 , V_234 , & V_53 ) ;
* V_202 = V_53 . V_202 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_234 ,
struct V_52 * V_53 )
{
int V_19 , V_30 , V_111 , V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_13 ,
V_10 , ( unsigned int ) V_234 , ( int ) V_53 -> V_56 ) ;
if ( V_53 -> V_57 == V_171 )
V_4 = V_6 -> V_130 . V_144 -> V_188 ;
else
V_4 = V_2 -> V_128 ;
if ( ( V_53 -> V_55 + V_53 -> V_56 ) > V_4 ) {
F_2 ( L_14 ,
V_10 ) ;
return - V_11 ;
}
if ( F_75 ( V_53 -> V_55 >= V_4 ) ) {
F_2 ( L_15 ,
V_10 ) ;
return - V_11 ;
}
if ( F_75 ( V_234 >= V_2 -> V_119 ||
V_53 -> V_55 + V_53 -> V_56 >
( ( V_2 -> V_119 >> V_6 -> V_38 ) -
( V_234 >> V_6 -> V_38 ) ) * V_4 ) ) {
F_2 ( L_16 ,
V_10 ) ;
return - V_11 ;
}
V_19 = ( int ) ( V_234 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_30 = ( int ) ( V_234 >> V_6 -> V_38 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
if ( F_34 ( V_2 ) ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
return - V_242 ;
}
if ( V_30 == V_6 -> V_194 )
V_6 -> V_194 = - 1 ;
F_97 ( V_2 , V_53 -> V_54 , V_53 -> V_56 , V_53 ) ;
if ( V_53 -> V_57 == V_170 )
V_111 = V_6 -> V_130 . V_243 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
else
V_111 = V_6 -> V_130 . V_244 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
if ( V_111 )
return V_111 ;
V_53 -> V_203 = V_53 -> V_56 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , T_1 V_234 ,
struct V_52 * V_53 )
{
int V_8 = - V_216 ;
V_53 -> V_202 = 0 ;
if ( V_53 -> V_191 && ( V_234 + V_53 -> V_4 ) > V_2 -> V_119 ) {
F_2 ( L_16 ,
V_10 ) ;
return - V_11 ;
}
F_26 ( V_2 , V_63 ) ;
switch ( V_53 -> V_57 ) {
case V_58 :
case V_171 :
case V_170 :
break;
default:
goto V_121;
}
if ( ! V_53 -> V_191 )
V_8 = F_30 ( V_2 , V_234 , V_53 ) ;
else
V_8 = F_98 ( V_2 , V_234 , V_53 ) ;
V_121:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_104 ( struct V_1 * V_2 , int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_45 ( V_2 , V_94 , - 1 , V_30 ) ;
V_6 -> V_45 ( V_2 , V_95 , - 1 , - 1 ) ;
return V_6 -> V_116 ( V_2 , V_6 ) ;
}
static int F_105 ( struct V_1 * V_2 , struct V_60 * V_245 )
{
return F_32 ( V_2 , V_245 , 0 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_60 * V_245 ,
int V_71 )
{
int V_30 , V_111 , V_246 , V_8 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_245 -> V_62 ,
( unsigned long long ) V_245 -> V_4 ) ;
if ( F_1 ( V_2 , V_245 -> V_62 , V_245 -> V_4 ) )
return - V_11 ;
F_26 ( V_2 , V_112 ) ;
V_30 = ( int ) ( V_245 -> V_62 >> V_6 -> V_38 ) ;
V_19 = ( int ) ( V_245 -> V_62 >> V_6 -> V_40 ) ;
V_246 = 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_245 -> V_15 = V_123 ;
goto V_247;
}
V_4 = V_245 -> V_4 ;
V_245 -> V_15 = V_248 ;
while ( V_4 ) {
if ( F_37 ( V_2 , ( ( T_1 ) V_30 ) <<
V_6 -> V_38 , 0 , V_71 ) ) {
F_106 ( L_17 ,
V_10 , V_30 ) ;
V_245 -> V_15 = V_123 ;
goto V_247;
}
if ( V_30 <= V_6 -> V_194 && V_6 -> V_194 <
( V_30 + V_246 ) )
V_6 -> V_194 = - 1 ;
V_111 = V_6 -> V_249 ( V_2 , V_30 & V_6 -> V_39 ) ;
if ( ( V_111 & V_117 ) && ( V_6 -> V_232 ) )
V_111 = V_6 -> V_232 ( V_2 , V_6 , V_112 ,
V_111 , V_30 ) ;
if ( V_111 & V_117 ) {
F_2 ( L_18 ,
V_10 , V_30 ) ;
V_245 -> V_15 = V_123 ;
V_245 -> V_250 =
( ( T_1 ) V_30 << V_6 -> V_38 ) ;
goto V_247;
}
V_4 -= ( 1ULL << V_6 -> V_9 ) ;
V_30 += V_246 ;
if ( V_4 && ! ( V_30 & V_6 -> V_39 ) ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_245 -> V_15 = V_251 ;
V_247:
V_8 = V_245 -> V_15 == V_251 ? 0 : - V_118 ;
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
if ( ! V_8 )
F_107 ( V_245 ) ;
return V_8 ;
}
static void F_108 ( struct V_1 * V_2 )
{
F_2 ( L_19 , V_10 ) ;
F_26 ( V_2 , V_252 ) ;
F_3 ( V_2 ) ;
}
static int F_109 ( struct V_1 * V_2 , T_1 V_253 )
{
return F_37 ( V_2 , V_253 , 1 , 0 ) ;
}
static int F_110 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
V_8 = F_109 ( V_2 , V_3 ) ;
if ( V_8 ) {
if ( V_8 > 0 )
return 0 ;
return V_8 ;
}
return F_31 ( V_2 , V_3 ) ;
}
static int F_111 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_62 , T_3 * V_254 )
{
int V_111 ;
int V_32 ;
if ( ! V_6 -> V_255 ||
! ( F_112 ( V_6 -> V_256 . V_257 )
& V_258 ) )
return - V_11 ;
V_6 -> V_45 ( V_2 , V_259 , V_62 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_260 ; ++ V_32 )
V_6 -> V_261 ( V_2 , V_254 [ V_32 ] ) ;
V_111 = V_6 -> V_116 ( V_2 , V_6 ) ;
if ( V_111 & V_117 )
return - V_118 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_62 , T_3 * V_254 )
{
int V_32 ;
if ( ! V_6 -> V_255 ||
! ( F_112 ( V_6 -> V_256 . V_257 )
& V_258 ) )
return - V_11 ;
V_6 -> V_45 ( V_2 , V_262 , V_62 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_260 ; ++ V_32 )
* V_254 ++ = V_6 -> V_49 ( V_2 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_109 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_15 == V_109 )
F_3 ( V_2 ) ;
else
F_116 ( L_20 ,
V_10 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
F_26 ( V_2 , V_263 ) ;
}
static void F_118 ( struct V_5 * V_6 , int V_165 )
{
if ( ! V_6 -> V_97 )
V_6 -> V_97 = 20 ;
if ( V_6 -> V_45 == NULL )
V_6 -> V_45 = F_48 ;
if ( V_6 -> V_116 == NULL )
V_6 -> V_116 = F_60 ;
if ( ! V_6 -> V_42 )
V_6 -> V_42 = F_13 ;
if ( ! V_6 -> V_264 )
V_6 -> V_264 = F_111 ;
if ( ! V_6 -> V_265 )
V_6 -> V_265 = F_113 ;
if ( ! V_6 -> V_49 || V_6 -> V_49 == F_7 )
V_6 -> V_49 = V_165 ? F_9 : F_7 ;
if ( ! V_6 -> V_48 )
V_6 -> V_48 = F_12 ;
if ( ! V_6 -> V_72 )
V_6 -> V_72 = F_25 ;
if ( ! V_6 -> V_64 )
V_6 -> V_64 = F_29 ;
if ( ! V_6 -> V_24 || V_6 -> V_24 == F_17 )
V_6 -> V_24 = V_165 ? F_21 : F_17 ;
if ( ! V_6 -> V_261 || V_6 -> V_261 == F_15 )
V_6 -> V_261 = V_165 ? F_16 : F_15 ;
if ( ! V_6 -> V_126 || V_6 -> V_126 == F_19 )
V_6 -> V_126 = V_165 ? F_23 : F_19 ;
if ( ! V_6 -> V_266 )
V_6 -> V_266 = V_267 ;
if ( ! V_6 -> V_12 ) {
V_6 -> V_12 = & V_6 -> V_268 ;
F_119 ( & V_6 -> V_12 -> V_13 ) ;
F_120 ( & V_6 -> V_12 -> V_17 ) ;
}
}
static void F_121 ( T_3 * V_269 , T_9 V_4 )
{
T_10 V_32 ;
V_269 [ V_4 - 1 ] = 0 ;
for ( V_32 = 0 ; V_32 < V_4 - 1 ; V_32 ++ ) {
if ( V_269 [ V_32 ] < ' ' || V_269 [ V_32 ] > 127 )
V_269 [ V_32 ] = '?' ;
}
F_122 ( V_269 ) ;
}
static T_4 F_123 ( T_4 V_270 , T_11 const * V_28 , T_9 V_4 )
{
int V_32 ;
while ( V_4 -- ) {
V_270 ^= * V_28 ++ << 8 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_270 = ( V_270 << 1 ) ^ ( ( V_270 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_270 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_271 * V_28 )
{
struct V_272 * V_273 ;
struct V_274 * V_269 ;
struct V_275 * V_130 ;
T_3 * V_276 ;
int V_8 = - V_11 ;
int V_4 ;
int V_32 ;
V_4 = F_112 ( V_28 -> V_277 ) * 16 ;
V_273 = F_125 ( V_4 , V_278 ) ;
if ( ! V_273 )
return - V_279 ;
V_6 -> V_45 ( V_2 , V_280 , 0 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_102 ,
sizeof( * V_28 ) * V_28 -> V_281 , - 1 ) ;
V_6 -> V_126 ( V_2 , ( T_3 * ) V_273 , V_4 ) ;
if ( ( F_123 ( V_282 , ( ( T_3 * ) V_273 ) + 2 , V_4 - 2 )
!= F_112 ( V_273 -> V_270 ) ) ) {
F_2 ( L_21 ) ;
goto V_283;
}
if ( strncmp ( V_273 -> V_284 , L_22 , 4 ) ) {
F_2 ( L_23 ) ;
goto V_283;
}
V_276 = ( T_3 * ) ( V_273 + 1 ) ;
for ( V_32 = 0 ; V_32 < V_285 ; V_32 ++ ) {
V_269 = V_273 -> V_286 + V_32 ;
if ( V_269 -> type == V_287 )
break;
V_276 += V_269 -> V_176 * 16 ;
}
if ( V_32 == V_285 ) {
F_2 ( L_24 ) ;
goto V_283;
}
V_130 = (struct V_275 * ) V_276 ;
if ( ! V_130 -> V_288 ) {
F_2 ( L_25 ) ;
goto V_283;
}
V_6 -> V_289 = V_130 -> V_290 ;
V_6 -> V_291 = 1 << V_130 -> V_288 ;
V_8 = 0 ;
V_283:
F_126 ( V_273 ) ;
return V_8 ;
}
static int F_127 ( struct V_1 * V_2 , int V_178 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_292 [ V_260 ] = { V_178 } ;
return V_6 -> V_264 ( V_2 , V_6 , V_293 ,
V_292 ) ;
}
static void F_128 ( struct V_5 * V_6 ,
struct V_271 * V_28 )
{
struct V_294 * V_295 = ( void * ) V_28 -> V_296 ;
if ( F_112 ( V_28 -> V_297 ) < 1 )
return;
V_6 -> V_179 = V_295 -> V_298 ;
V_6 -> V_180 = F_127 ;
}
static int F_129 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_165 )
{
struct V_271 * V_28 = & V_6 -> V_256 ;
int V_32 , V_299 ;
int V_300 ;
V_6 -> V_45 ( V_2 , V_301 , 0x20 , - 1 ) ;
if ( V_6 -> V_49 ( V_2 ) != 'O' || V_6 -> V_49 ( V_2 ) != 'N' ||
V_6 -> V_49 ( V_2 ) != 'F' || V_6 -> V_49 ( V_2 ) != 'I' )
return 0 ;
V_6 -> V_45 ( V_2 , V_280 , 0 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
for ( V_299 = 0 ; V_299 < sizeof( * V_28 ) ; V_299 ++ )
( ( T_3 * ) V_28 ) [ V_299 ] = V_6 -> V_49 ( V_2 ) ;
if ( F_123 ( V_282 , ( T_3 * ) V_28 , 254 ) ==
F_112 ( V_28 -> V_270 ) ) {
break;
}
}
if ( V_32 == 3 ) {
F_116 ( L_26 ) ;
return 0 ;
}
V_300 = F_112 ( V_28 -> V_302 ) ;
if ( V_300 & ( 1 << 5 ) )
V_6 -> V_255 = 23 ;
else if ( V_300 & ( 1 << 4 ) )
V_6 -> V_255 = 22 ;
else if ( V_300 & ( 1 << 3 ) )
V_6 -> V_255 = 21 ;
else if ( V_300 & ( 1 << 2 ) )
V_6 -> V_255 = 20 ;
else if ( V_300 & ( 1 << 1 ) )
V_6 -> V_255 = 10 ;
if ( ! V_6 -> V_255 ) {
F_130 ( L_27 , V_300 ) ;
return 0 ;
}
F_121 ( V_28 -> V_303 , sizeof( V_28 -> V_303 ) ) ;
F_121 ( V_28 -> V_304 , sizeof( V_28 -> V_304 ) ) ;
if ( ! V_2 -> V_305 )
V_2 -> V_305 = V_28 -> V_304 ;
V_2 -> V_37 = F_131 ( V_28 -> V_306 ) ;
V_2 -> V_36 = 1 << ( F_132 ( F_131 ( V_28 -> V_246 ) ) - 1 ) ;
V_2 -> V_36 *= V_2 -> V_37 ;
V_2 -> V_128 = F_112 ( V_28 -> V_307 ) ;
V_6 -> V_91 = 1 << ( F_132 ( F_131 ( V_28 -> V_308 ) ) - 1 ) ;
V_6 -> V_91 *= ( T_2 ) V_2 -> V_36 * V_28 -> V_309 ;
V_6 -> V_310 = V_28 -> V_310 ;
if ( F_133 ( V_6 ) & V_311 )
* V_165 = V_44 ;
else
* V_165 = 0 ;
if ( V_28 -> V_290 != 0xff ) {
V_6 -> V_289 = V_28 -> V_290 ;
V_6 -> V_291 = 512 ;
} else if ( V_6 -> V_255 >= 21 &&
( F_133 ( V_6 ) & V_312 ) ) {
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_48 )
V_6 -> V_45 = F_52 ;
if ( F_124 ( V_2 , V_6 , V_28 ) )
F_106 ( L_28 ) ;
} else {
F_106 ( L_29 ) ;
}
if ( V_28 -> V_313 == V_314 )
F_128 ( V_6 , V_28 ) ;
return 1 ;
}
static int F_134 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_165 )
{
struct V_315 * V_28 = & V_6 -> V_316 ;
struct V_317 * V_130 ;
int V_300 ;
int V_32 , V_299 ;
V_6 -> V_45 ( V_2 , V_301 , 0x40 , - 1 ) ;
if ( V_6 -> V_49 ( V_2 ) != 'J' || V_6 -> V_49 ( V_2 ) != 'E' ||
V_6 -> V_49 ( V_2 ) != 'D' || V_6 -> V_49 ( V_2 ) != 'E' ||
V_6 -> V_49 ( V_2 ) != 'C' )
return 0 ;
V_6 -> V_45 ( V_2 , V_280 , 0x40 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
for ( V_299 = 0 ; V_299 < sizeof( * V_28 ) ; V_299 ++ )
( ( T_3 * ) V_28 ) [ V_299 ] = V_6 -> V_49 ( V_2 ) ;
if ( F_123 ( V_282 , ( T_3 * ) V_28 , 510 ) ==
F_112 ( V_28 -> V_270 ) )
break;
}
if ( V_32 == 3 ) {
F_116 ( L_30 ) ;
return 0 ;
}
V_300 = F_112 ( V_28 -> V_302 ) ;
if ( V_300 & ( 1 << 2 ) )
V_6 -> V_318 = 10 ;
else if ( V_300 & ( 1 << 1 ) )
V_6 -> V_318 = 1 ;
if ( ! V_6 -> V_318 ) {
F_130 ( L_31 , V_300 ) ;
return 0 ;
}
F_121 ( V_28 -> V_303 , sizeof( V_28 -> V_303 ) ) ;
F_121 ( V_28 -> V_304 , sizeof( V_28 -> V_304 ) ) ;
if ( ! V_2 -> V_305 )
V_2 -> V_305 = V_28 -> V_304 ;
V_2 -> V_37 = F_131 ( V_28 -> V_306 ) ;
V_2 -> V_36 = 1 << ( F_132 ( F_131 ( V_28 -> V_246 ) ) - 1 ) ;
V_2 -> V_36 *= V_2 -> V_37 ;
V_2 -> V_128 = F_112 ( V_28 -> V_307 ) ;
V_6 -> V_91 = 1 << ( F_132 ( F_131 ( V_28 -> V_308 ) ) - 1 ) ;
V_6 -> V_91 *= ( T_2 ) V_2 -> V_36 * V_28 -> V_309 ;
V_6 -> V_310 = V_28 -> V_310 ;
if ( F_135 ( V_6 ) & V_319 )
* V_165 = V_44 ;
else
* V_165 = 0 ;
V_130 = & V_28 -> V_320 [ 0 ] ;
if ( V_130 -> V_288 >= 9 ) {
V_6 -> V_289 = V_130 -> V_290 ;
V_6 -> V_291 = 1 << V_130 -> V_288 ;
} else {
F_106 ( L_25 ) ;
}
return 1 ;
}
static int F_136 ( T_11 * V_321 , int V_322 , int V_323 )
{
int V_32 , V_299 ;
for ( V_32 = 0 ; V_32 < V_323 ; V_32 ++ )
for ( V_299 = V_32 + V_323 ; V_299 < V_322 ; V_299 += V_323 )
if ( V_321 [ V_32 ] != V_321 [ V_299 ] )
return 0 ;
return 1 ;
}
static int F_137 ( T_11 * V_321 , int V_322 )
{
int V_324 , V_323 ;
for ( V_324 = V_322 - 1 ; V_324 >= 0 ; V_324 -- )
if ( V_321 [ V_324 ] )
break;
if ( V_324 < 0 )
return 0 ;
for ( V_323 = 1 ; V_323 < V_322 ; V_323 ++ )
if ( F_136 ( V_321 , V_322 , V_323 ) )
break;
if ( V_323 < V_322 )
return V_323 ;
if ( V_324 < V_322 - 1 )
return V_324 + 1 ;
return V_322 ;
}
static int F_138 ( T_11 V_325 )
{
int V_326 ;
V_326 = V_325 & V_327 ;
V_326 >>= V_328 ;
return V_326 + 1 ;
}
static void F_139 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_11 V_321 [ 8 ] , int * V_165 )
{
int V_329 , V_330 ;
V_6 -> V_310 = F_138 ( V_321 [ 2 ] ) ;
V_329 = V_321 [ 3 ] ;
V_330 = F_137 ( V_321 , 8 ) ;
if ( V_330 == 6 && V_321 [ 0 ] == V_331 &&
! F_140 ( V_6 ) && V_321 [ 5 ] != 0x00 ) {
V_2 -> V_37 = 2048 << ( V_329 & 0x03 ) ;
V_329 >>= 2 ;
switch ( ( ( V_329 >> 2 ) & 0x04 ) | ( V_329 & 0x03 ) ) {
case 1 :
V_2 -> V_128 = 128 ;
break;
case 2 :
V_2 -> V_128 = 218 ;
break;
case 3 :
V_2 -> V_128 = 400 ;
break;
case 4 :
V_2 -> V_128 = 436 ;
break;
case 5 :
V_2 -> V_128 = 512 ;
break;
case 6 :
V_2 -> V_128 = 640 ;
break;
case 7 :
default:
V_2 -> V_128 = 1024 ;
break;
}
V_329 >>= 2 ;
V_2 -> V_36 = ( 128 * 1024 ) <<
( ( ( V_329 >> 1 ) & 0x04 ) | ( V_329 & 0x03 ) ) ;
* V_165 = 0 ;
} else if ( V_330 == 6 && V_321 [ 0 ] == V_332 &&
! F_140 ( V_6 ) ) {
unsigned int V_333 ;
V_2 -> V_37 = 2048 << ( V_329 & 0x03 ) ;
V_329 >>= 2 ;
switch ( ( ( V_329 >> 2 ) & 0x04 ) | ( V_329 & 0x03 ) ) {
case 0 :
V_2 -> V_128 = 128 ;
break;
case 1 :
V_2 -> V_128 = 224 ;
break;
case 2 :
V_2 -> V_128 = 448 ;
break;
case 3 :
V_2 -> V_128 = 64 ;
break;
case 4 :
V_2 -> V_128 = 32 ;
break;
case 5 :
V_2 -> V_128 = 16 ;
break;
default:
V_2 -> V_128 = 640 ;
break;
}
V_329 >>= 2 ;
V_333 = ( ( V_329 >> 1 ) & 0x04 ) | ( V_329 & 0x03 ) ;
if ( V_333 < 0x03 )
V_2 -> V_36 = ( 128 * 1024 ) << V_333 ;
else if ( V_333 == 0x03 )
V_2 -> V_36 = 768 * 1024 ;
else
V_2 -> V_36 = ( 64 * 1024 ) << V_333 ;
* V_165 = 0 ;
} else {
V_2 -> V_37 = 1024 << ( V_329 & 0x03 ) ;
V_329 >>= 2 ;
V_2 -> V_128 = ( 8 << ( V_329 & 0x01 ) ) *
( V_2 -> V_37 >> 9 ) ;
V_329 >>= 2 ;
V_2 -> V_36 = ( 64 * 1024 ) << ( V_329 & 0x03 ) ;
V_329 >>= 2 ;
* V_165 = ( V_329 & 0x01 ) ? V_44 : 0 ;
if ( V_330 >= 6 && V_321 [ 0 ] == V_334 &&
F_140 ( V_6 ) &&
( V_321 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_321 [ 4 ] & 0x80 ) ) {
V_2 -> V_128 = 32 * V_2 -> V_37 >> 9 ;
}
}
}
static void F_141 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_335 * type , T_11 V_321 [ 8 ] ,
int * V_165 )
{
int V_336 = V_321 [ 0 ] ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_37 = type -> V_337 ;
V_2 -> V_128 = V_2 -> V_37 / 32 ;
* V_165 = type -> V_43 & V_44 ;
V_6 -> V_310 = 1 ;
if ( V_336 == V_338 && V_321 [ 4 ] != 0x00 && V_321 [ 5 ] == 0x00
&& V_321 [ 6 ] == 0x00 && V_321 [ 7 ] == 0x00
&& V_2 -> V_37 == 512 ) {
V_2 -> V_36 = 128 * 1024 ;
V_2 -> V_36 <<= ( ( V_321 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_142 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_11 V_321 [ 8 ] )
{
int V_336 = V_321 [ 0 ] ;
if ( V_2 -> V_37 > 512 || ( V_6 -> V_43 & V_44 ) )
V_6 -> V_47 = V_339 ;
else
V_6 -> V_47 = V_340 ;
if ( ! F_140 ( V_6 ) &&
( V_336 == V_331 ||
V_336 == V_332 ) )
V_6 -> V_34 |= V_35 ;
else if ( ( F_140 ( V_6 ) &&
( V_336 == V_331 ||
V_336 == V_332 ||
V_336 == V_334 ||
V_336 == V_338 ||
V_336 == V_341 ) ) ||
( V_2 -> V_37 == 2048 &&
V_336 == V_314 ) )
V_6 -> V_34 |= V_51 ;
}
static inline bool F_143 ( struct V_335 * type )
{
return type -> V_330 ;
}
static bool F_144 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_335 * type , T_11 * V_321 , int * V_165 )
{
if ( ! strncmp ( type -> V_342 , V_321 , type -> V_330 ) ) {
V_2 -> V_37 = type -> V_337 ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_128 = type -> V_128 ;
V_6 -> V_310 = F_138 ( V_321 [ 2 ] ) ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
V_6 -> V_43 |= type -> V_43 ;
V_6 -> V_289 = F_145 ( type ) ;
V_6 -> V_291 = F_146 ( type ) ;
V_6 -> V_343 =
type -> V_343 ;
* V_165 = type -> V_43 & V_44 ;
if ( ! V_2 -> V_305 )
V_2 -> V_305 = type -> V_305 ;
return true ;
}
return false ;
}
static struct V_335 * F_147 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int * V_336 , int * V_344 ,
struct V_335 * type )
{
int V_165 ;
int V_32 , V_345 ;
T_11 V_321 [ 8 ] ;
V_6 -> V_42 ( V_2 , 0 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_301 , 0x00 , - 1 ) ;
* V_336 = V_6 -> V_49 ( V_2 ) ;
* V_344 = V_6 -> V_49 ( V_2 ) ;
V_6 -> V_45 ( V_2 , V_301 , 0x00 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_321 [ V_32 ] = V_6 -> V_49 ( V_2 ) ;
if ( V_321 [ 0 ] != * V_336 || V_321 [ 1 ] != * V_344 ) {
F_130 ( L_32 ,
* V_336 , * V_344 , V_321 [ 0 ] , V_321 [ 1 ] ) ;
return F_148 ( - V_346 ) ;
}
if ( ! type )
type = V_347 ;
for (; type -> V_305 != NULL ; type ++ ) {
if ( F_143 ( type ) ) {
if ( F_144 ( V_2 , V_6 , type , V_321 , & V_165 ) )
goto V_348;
} else if ( * V_344 == type -> V_344 ) {
break;
}
}
V_6 -> V_255 = 0 ;
if ( ! type -> V_305 || ! type -> V_337 ) {
if ( F_129 ( V_2 , V_6 , & V_165 ) )
goto V_348;
if ( F_134 ( V_2 , V_6 , & V_165 ) )
goto V_348;
}
if ( ! type -> V_305 )
return F_148 ( - V_346 ) ;
if ( ! V_2 -> V_305 )
V_2 -> V_305 = type -> V_305 ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
if ( ! type -> V_337 && V_6 -> V_349 ) {
V_165 = V_6 -> V_349 ( V_2 , V_6 , V_321 ) ;
} else if ( ! type -> V_337 ) {
F_139 ( V_2 , V_6 , V_321 , & V_165 ) ;
} else {
F_141 ( V_2 , V_6 , type , V_321 , & V_165 ) ;
}
V_6 -> V_43 |= type -> V_43 ;
if ( * V_336 != V_331 && ! type -> V_337 )
V_6 -> V_43 &= ~ V_350 ;
V_348:
for ( V_345 = 0 ; V_351 [ V_345 ] . V_342 != 0x0 ; V_345 ++ ) {
if ( V_351 [ V_345 ] . V_342 == * V_336 )
break;
}
if ( V_6 -> V_43 & V_352 ) {
F_62 ( V_6 -> V_43 & V_44 ) ;
V_6 -> V_43 |= V_165 ;
F_118 ( V_6 , V_165 ) ;
} else if ( V_165 != ( V_6 -> V_43 & V_44 ) ) {
F_130 ( L_33 ,
* V_336 , * V_344 ) ;
F_130 ( L_34 , V_351 [ V_345 ] . V_305 , V_2 -> V_305 ) ;
F_106 ( L_35 ,
( V_6 -> V_43 & V_44 ) ? 16 : 8 ,
V_165 ? 16 : 8 ) ;
return F_148 ( - V_11 ) ;
}
F_142 ( V_2 , V_6 , V_321 ) ;
V_6 -> V_38 = F_149 ( V_2 -> V_37 ) - 1 ;
V_6 -> V_39 = ( V_6 -> V_91 >> V_6 -> V_38 ) - 1 ;
V_6 -> V_353 = V_6 -> V_9 =
F_149 ( V_2 -> V_36 ) - 1 ;
if ( V_6 -> V_91 & 0xffffffff )
V_6 -> V_40 = F_149 ( ( unsigned ) V_6 -> V_91 ) - 1 ;
else {
V_6 -> V_40 = F_149 ( ( unsigned ) ( V_6 -> V_91 >> 32 ) ) ;
V_6 -> V_40 += 32 - 1 ;
}
V_6 -> V_50 = 8 ;
V_6 -> V_249 = F_104 ;
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_48 )
V_6 -> V_45 = F_52 ;
F_130 ( L_33 ,
* V_336 , * V_344 ) ;
if ( V_6 -> V_255 )
F_130 ( L_34 , V_351 [ V_345 ] . V_305 ,
V_6 -> V_256 . V_304 ) ;
else if ( V_6 -> V_318 )
F_130 ( L_34 , V_351 [ V_345 ] . V_305 ,
V_6 -> V_316 . V_304 ) ;
else
F_130 ( L_34 , V_351 [ V_345 ] . V_305 ,
type -> V_305 ) ;
F_130 ( L_36 ,
( int ) ( V_6 -> V_91 >> 20 ) , F_140 ( V_6 ) ? L_37 : L_38 ,
V_2 -> V_36 >> 10 , V_2 -> V_37 , V_2 -> V_128 ) ;
return type ;
}
static int F_150 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_354 * V_355 )
{
int V_356 , V_357 , V_358 ;
if ( F_151 ( V_355 ) == 16 )
V_6 -> V_43 |= V_44 ;
if ( F_152 ( V_355 ) )
V_6 -> V_34 |= V_359 ;
V_356 = F_153 ( V_355 ) ;
V_357 = F_154 ( V_355 ) ;
V_358 = F_155 ( V_355 ) ;
if ( ( V_358 >= 0 && ! ( V_357 >= 0 ) ) ||
( ! ( V_358 >= 0 ) && V_357 >= 0 ) ) {
F_116 ( L_39 ) ;
return - V_11 ;
}
if ( V_356 >= 0 )
V_6 -> V_130 . V_57 = V_356 ;
if ( V_357 >= 0 )
V_6 -> V_130 . V_360 = V_357 ;
if ( V_358 > 0 )
V_6 -> V_130 . V_119 = V_358 ;
return 0 ;
}
int F_156 ( struct V_1 * V_2 , int V_361 ,
struct V_335 * V_362 )
{
int V_32 , V_363 , V_364 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_335 * type ;
int V_8 ;
if ( V_6 -> V_355 ) {
V_8 = F_150 ( V_2 , V_6 , V_6 -> V_355 ) ;
if ( V_8 )
return V_8 ;
}
F_118 ( V_6 , V_6 -> V_43 & V_44 ) ;
type = F_147 ( V_2 , V_6 , & V_363 ,
& V_364 , V_362 ) ;
if ( F_157 ( type ) ) {
if ( ! ( V_6 -> V_43 & V_365 ) )
F_106 ( L_40 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
return F_158 ( type ) ;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
for ( V_32 = 1 ; V_32 < V_361 ; V_32 ++ ) {
V_6 -> V_42 ( V_2 , V_32 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_301 , 0x00 , - 1 ) ;
if ( V_363 != V_6 -> V_49 ( V_2 ) ||
V_364 != V_6 -> V_49 ( V_2 ) ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
break;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
}
if ( V_32 > 1 )
F_130 ( L_41 , V_32 ) ;
V_6 -> V_366 = V_32 ;
V_2 -> V_119 = V_32 * V_6 -> V_91 ;
return 0 ;
}
static bool F_159 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_367 * V_130 = & V_6 -> V_130 ;
int V_368 , V_369 ;
if ( V_130 -> V_119 == 0 || V_6 -> V_291 == 0 )
return true ;
V_368 = ( V_2 -> V_37 * V_130 -> V_360 ) / V_130 -> V_119 ;
V_369 = ( V_2 -> V_37 * V_6 -> V_289 ) / V_6 -> V_291 ;
return V_368 >= V_369 && V_130 -> V_360 >= V_6 -> V_289 ;
}
int F_160 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_367 * V_130 = & V_6 -> V_130 ;
struct V_370 * V_371 ;
F_161 ( ( V_6 -> V_34 & V_59 ) &&
! ( V_6 -> V_34 & V_359 ) ) ;
if ( ! ( V_6 -> V_43 & V_372 ) ) {
V_371 = F_162 ( sizeof( * V_371 ) + V_2 -> V_37
+ V_2 -> V_128 * 3 , V_278 ) ;
if ( ! V_371 )
return - V_279 ;
V_371 -> V_140 = ( T_3 * ) ( V_371 + 1 ) ;
V_371 -> V_142 = V_371 -> V_140 + V_2 -> V_128 ;
V_371 -> V_195 = V_371 -> V_142 + V_2 -> V_128 ;
V_6 -> V_139 = V_371 ;
} else {
if ( ! V_6 -> V_139 )
return - V_279 ;
}
V_6 -> V_127 = V_6 -> V_139 -> V_195 + V_2 -> V_37 ;
if ( ! V_130 -> V_144 && ( V_130 -> V_57 != V_373 ) ) {
switch ( V_2 -> V_128 ) {
case 8 :
V_130 -> V_144 = & V_374 ;
break;
case 16 :
V_130 -> V_144 = & V_375 ;
break;
case 64 :
V_130 -> V_144 = & V_376 ;
break;
case 128 :
V_130 -> V_144 = & V_377 ;
break;
default:
F_106 ( L_42 ,
V_2 -> V_128 ) ;
F_14 () ;
}
}
if ( ! V_6 -> V_231 )
V_6 -> V_231 = F_95 ;
switch ( V_130 -> V_57 ) {
case V_378 :
if ( ! V_130 -> V_147 || ! V_130 -> V_150 || ! V_130 -> V_167 ) {
F_106 ( L_43 ) ;
F_14 () ;
}
if ( ! V_130 -> V_198 )
V_130 -> V_198 = F_72 ;
case V_379 :
if ( ! V_130 -> V_198 )
V_130 -> V_198 = F_71 ;
if ( ! V_130 -> V_231 )
V_130 -> V_231 = F_92 ;
if ( ! V_130 -> V_146 )
V_130 -> V_146 = F_66 ;
if ( ! V_130 -> V_217 )
V_130 -> V_217 = F_89 ;
if ( ! V_130 -> V_214 )
V_130 -> V_214 = F_83 ;
if ( ! V_130 -> V_244 )
V_130 -> V_244 = F_85 ;
if ( ! V_130 -> V_197 )
V_130 -> V_197 = F_70 ;
if ( ! V_130 -> V_230 )
V_130 -> V_230 = F_93 ;
case V_380 :
if ( ( ! V_130 -> V_147 || ! V_130 -> V_150 || ! V_130 -> V_167 ) &&
( ! V_130 -> V_198 ||
V_130 -> V_198 == F_71 ||
! V_130 -> V_231 ||
V_130 -> V_231 == F_92 ) ) {
F_106 ( L_43 ) ;
F_14 () ;
}
if ( ! V_130 -> V_198 )
V_130 -> V_198 = F_73 ;
if ( ! V_130 -> V_231 )
V_130 -> V_231 = F_94 ;
if ( ! V_130 -> V_146 )
V_130 -> V_146 = F_67 ;
if ( ! V_130 -> V_217 )
V_130 -> V_217 = F_90 ;
if ( ! V_130 -> V_214 )
V_130 -> V_214 = F_84 ;
if ( ! V_130 -> V_244 )
V_130 -> V_244 = F_86 ;
if ( V_2 -> V_37 >= V_130 -> V_119 ) {
if ( ! V_130 -> V_360 ) {
F_106 ( L_44 ) ;
F_14 () ;
}
break;
}
F_106 ( L_45 ,
V_130 -> V_119 , V_2 -> V_37 ) ;
V_130 -> V_57 = V_381 ;
case V_381 :
V_130 -> V_147 = V_382 ;
V_130 -> V_150 = V_383 ;
V_130 -> V_198 = F_68 ;
V_130 -> V_197 = F_70 ;
V_130 -> V_231 = F_91 ;
V_130 -> V_146 = F_66 ;
V_130 -> V_217 = F_89 ;
V_130 -> V_214 = F_83 ;
V_130 -> V_244 = F_85 ;
if ( ! V_130 -> V_119 )
V_130 -> V_119 = 256 ;
V_130 -> V_132 = 3 ;
V_130 -> V_360 = 1 ;
break;
case V_373 :
if ( ! F_163 () ) {
F_106 ( L_46 ) ;
F_14 () ;
}
V_130 -> V_147 = V_384 ;
V_130 -> V_150 = V_385 ;
V_130 -> V_198 = F_68 ;
V_130 -> V_197 = F_70 ;
V_130 -> V_231 = F_91 ;
V_130 -> V_146 = F_66 ;
V_130 -> V_217 = F_89 ;
V_130 -> V_214 = F_83 ;
V_130 -> V_244 = F_85 ;
if ( ! V_130 -> V_119 && ( V_2 -> V_128 >= 64 ) ) {
V_130 -> V_119 = 512 ;
V_130 -> V_360 = 4 ;
}
V_130 -> V_132 = F_164 (
V_130 -> V_360 * F_132 ( 8 * V_130 -> V_119 ) , 8 ) ;
V_130 -> V_7 = F_165 ( V_2 , V_130 -> V_119 , V_130 -> V_132 ,
& V_130 -> V_144 ) ;
if ( ! V_130 -> V_7 ) {
F_106 ( L_47 ) ;
F_14 () ;
}
break;
case V_386 :
F_106 ( L_48 ) ;
V_130 -> V_198 = F_66 ;
V_130 -> V_231 = F_89 ;
V_130 -> V_214 = F_83 ;
V_130 -> V_146 = F_66 ;
V_130 -> V_217 = F_89 ;
V_130 -> V_244 = F_85 ;
V_130 -> V_119 = V_2 -> V_37 ;
V_130 -> V_132 = 0 ;
V_130 -> V_360 = 0 ;
break;
default:
F_106 ( L_49 , V_130 -> V_57 ) ;
F_14 () ;
}
if ( ! V_130 -> V_213 )
V_130 -> V_213 = V_130 -> V_214 ;
if ( ! V_130 -> V_243 )
V_130 -> V_243 = V_130 -> V_244 ;
V_130 -> V_144 -> V_188 = 0 ;
for ( V_32 = 0 ; V_130 -> V_144 -> V_173 [ V_32 ] . V_176
&& V_32 < F_166 ( V_130 -> V_144 -> V_173 ) ; V_32 ++ )
V_130 -> V_144 -> V_188 += V_130 -> V_144 -> V_173 [ V_32 ] . V_176 ;
V_2 -> V_188 = V_130 -> V_144 -> V_188 ;
if ( ! F_159 ( V_2 ) )
F_106 ( L_50 ,
V_2 -> V_305 ) ;
V_130 -> V_134 = V_2 -> V_37 / V_130 -> V_119 ;
if ( V_130 -> V_134 * V_130 -> V_119 != V_2 -> V_37 ) {
F_106 ( L_51 ) ;
F_14 () ;
}
V_130 -> V_148 = V_130 -> V_134 * V_130 -> V_132 ;
if ( ! ( V_6 -> V_43 & V_229 ) && F_140 ( V_6 ) ) {
switch ( V_130 -> V_134 ) {
case 2 :
V_2 -> V_387 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_387 = 2 ;
break;
}
}
V_6 -> V_388 = V_2 -> V_37 >> V_2 -> V_387 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_194 = - 1 ;
switch ( V_130 -> V_57 ) {
case V_381 :
case V_373 :
if ( V_6 -> V_38 > 9 )
V_6 -> V_43 |= V_389 ;
break;
default:
break;
}
V_2 -> type = F_140 ( V_6 ) ? V_390 : V_391 ;
V_2 -> V_392 = ( V_6 -> V_43 & V_393 ) ? V_394 :
V_395 ;
V_2 -> V_396 = F_105 ;
V_2 -> V_397 = NULL ;
V_2 -> V_398 = NULL ;
V_2 -> V_399 = F_82 ;
V_2 -> V_400 = F_102 ;
V_2 -> V_401 = F_101 ;
V_2 -> V_402 = F_88 ;
V_2 -> V_403 = F_103 ;
V_2 -> V_404 = F_108 ;
V_2 -> V_405 = NULL ;
V_2 -> V_406 = NULL ;
V_2 -> V_407 = F_114 ;
V_2 -> V_408 = F_115 ;
V_2 -> V_409 = F_117 ;
V_2 -> V_410 = F_35 ;
V_2 -> V_411 = F_109 ;
V_2 -> V_412 = F_110 ;
V_2 -> V_413 = V_2 -> V_37 ;
V_2 -> V_414 = V_130 -> V_144 ;
V_2 -> V_357 = V_130 -> V_360 ;
V_2 -> V_415 = V_130 -> V_119 ;
if ( ! V_2 -> V_416 )
V_2 -> V_416 = F_164 ( V_2 -> V_357 * 3 , 4 ) ;
if ( V_6 -> V_43 & V_417 )
return 0 ;
return V_6 -> V_266 ( V_2 ) ;
}
int F_167 ( struct V_1 * V_2 , int V_361 )
{
int V_8 ;
if ( ! V_2 -> V_418 && F_168 () ) {
F_169 ( L_52 , V_10 ) ;
F_14 () ;
}
V_8 = F_156 ( V_2 , V_361 , NULL ) ;
if ( ! V_8 )
V_8 = F_160 ( V_2 ) ;
return V_8 ;
}
void F_170 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_130 . V_57 == V_373 )
F_171 ( (struct V_419 * ) V_6 -> V_130 . V_7 ) ;
F_172 ( V_2 ) ;
F_126 ( V_6 -> V_65 ) ;
if ( ! ( V_6 -> V_43 & V_372 ) )
F_126 ( V_6 -> V_139 ) ;
if ( V_6 -> V_420 && V_6 -> V_420 -> V_43
& V_421 )
F_126 ( V_6 -> V_420 ) ;
}
static int T_12 F_173 ( void )
{
F_174 ( L_53 , & V_77 ) ;
return 0 ;
}
static void T_13 F_175 ( void )
{
F_176 ( V_77 ) ;
}
