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
V_53 . V_54 = NULL ;
V_53 . V_55 = V_26 ;
V_53 . V_56 = V_6 -> V_47 ;
if ( V_6 -> V_43 & V_44 ) {
V_53 . V_56 &= ~ 0x01 ;
V_53 . V_4 = V_53 . V_57 = 2 ;
} else {
V_53 . V_4 = V_53 . V_57 = 1 ;
}
V_53 . V_58 = V_59 ;
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
if ( ! ( V_6 -> V_34 & V_60 ) ) {
struct V_61 V_62 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_2 = V_2 ;
V_62 . V_63 = V_3 ;
V_62 . V_4 = 1ULL << V_6 -> V_9 ;
F_32 ( V_2 , & V_62 , 0 ) ;
F_26 ( V_2 , V_64 ) ;
V_8 = V_6 -> V_65 ( V_2 , V_3 ) ;
F_3 ( V_2 ) ;
}
if ( V_6 -> V_66 ) {
V_31 = F_33 ( V_2 , V_3 ) ;
if ( ! V_8 )
V_8 = V_31 ;
}
if ( ! V_8 )
V_2 -> V_67 . V_68 ++ ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_43 & V_69 )
return 0 ;
V_6 -> V_45 ( V_2 , V_70 , - 1 , - 1 ) ;
return ( V_6 -> V_49 ( V_2 ) & V_71 ) ? 0 : 1 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_3 , int V_29 ,
int V_72 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_66 )
return V_6 -> V_73 ( V_2 , V_3 , V_29 ) ;
return F_36 ( V_2 , V_3 , V_72 ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_74 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_74 ; V_32 ++ ) {
if ( V_6 -> V_75 ( V_2 ) )
break;
F_38 () ;
F_39 ( 1 ) ;
}
}
void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_74 = V_76 + F_41 ( 20 ) ;
if ( F_42 () || V_77 )
return F_37 ( V_2 , 400 ) ;
F_43 ( V_78 , V_79 ) ;
do {
if ( V_6 -> V_75 ( V_2 ) )
break;
F_38 () ;
} while ( F_44 ( V_76 , V_74 ) );
F_43 ( V_78 , V_80 ) ;
}
static void F_45 ( struct V_1 * V_2 , unsigned int V_81 ,
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
! F_46 ( V_81 ) )
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
case V_70 :
return;
case V_96 :
if ( V_6 -> V_75 )
break;
F_47 ( V_6 -> V_97 ) ;
V_6 -> V_20 ( V_2 , V_70 ,
V_85 | V_22 ) ;
V_6 -> V_20 ( V_2 ,
V_21 , V_92 | V_22 ) ;
while ( ! ( V_6 -> V_49 ( V_2 ) & V_98 ) )
;
return;
default:
if ( ! V_6 -> V_75 ) {
F_47 ( V_6 -> V_97 ) ;
return;
}
}
F_48 ( 100 ) ;
F_40 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 , unsigned int V_81 ,
int V_82 , int V_83 )
{
register struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_81 == V_46 ) {
V_82 += V_2 -> V_37 ;
V_81 = V_88 ;
}
V_6 -> V_20 ( V_2 , V_81 , V_92 | V_99 | V_22 ) ;
if ( V_82 != - 1 || V_83 != - 1 ) {
int V_84 = V_22 | V_92 | V_100 ;
if ( V_82 != - 1 ) {
if ( V_6 -> V_43 & V_44 &&
! F_46 ( V_81 ) )
V_82 >>= 1 ;
V_6 -> V_20 ( V_2 , V_82 , V_84 ) ;
V_84 &= ~ V_22 ;
V_6 -> V_20 ( V_2 , V_82 >> 8 , V_84 ) ;
}
if ( V_83 != - 1 ) {
V_6 -> V_20 ( V_2 , V_83 , V_84 ) ;
V_6 -> V_20 ( V_2 , V_83 >> 8 ,
V_92 | V_100 ) ;
if ( V_6 -> V_91 > ( 128 << 20 ) )
V_6 -> V_20 ( V_2 , V_83 >> 16 ,
V_92 | V_100 ) ;
}
}
V_6 -> V_20 ( V_2 , V_21 , V_92 | V_22 ) ;
switch ( V_81 ) {
case V_101 :
case V_93 :
case V_94 :
case V_95 :
case V_86 :
case V_102 :
case V_70 :
return;
case V_96 :
if ( V_6 -> V_75 )
break;
F_47 ( V_6 -> V_97 ) ;
V_6 -> V_20 ( V_2 , V_70 ,
V_92 | V_99 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_92 | V_22 ) ;
while ( ! ( V_6 -> V_49 ( V_2 ) & V_98 ) )
;
return;
case V_103 :
V_6 -> V_20 ( V_2 , V_104 ,
V_92 | V_99 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_92 | V_22 ) ;
return;
case V_88 :
V_6 -> V_20 ( V_2 , V_105 ,
V_92 | V_99 | V_22 ) ;
V_6 -> V_20 ( V_2 , V_21 ,
V_92 | V_22 ) ;
default:
if ( ! V_6 -> V_75 ) {
F_47 ( V_6 -> V_97 ) ;
return;
}
}
F_48 ( 100 ) ;
F_40 ( V_2 ) ;
}
static void F_50 ( struct V_5 * V_6 ,
struct V_1 * V_2 , int V_106 )
{
V_6 -> V_12 -> V_14 = V_6 ;
V_6 -> V_15 = V_106 ;
}
static int
F_26 ( struct V_1 * V_2 , int V_106 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_6 * V_13 = & V_6 -> V_12 -> V_13 ;
T_7 * V_17 = & V_6 -> V_12 -> V_17 ;
F_51 ( V_107 , V_108 ) ;
V_109:
F_4 ( V_13 ) ;
if ( ! V_6 -> V_12 -> V_14 )
V_6 -> V_12 -> V_14 = V_6 ;
if ( V_6 -> V_12 -> V_14 == V_6 && V_6 -> V_15 == V_16 ) {
V_6 -> V_15 = V_106 ;
F_6 ( V_13 ) ;
return 0 ;
}
if ( V_106 == V_110 ) {
if ( V_6 -> V_12 -> V_14 -> V_15 == V_110 ) {
V_6 -> V_15 = V_110 ;
F_6 ( V_13 ) ;
return 0 ;
}
}
F_52 ( V_111 ) ;
F_53 ( V_17 , & V_107 ) ;
F_6 ( V_13 ) ;
F_54 () ;
F_55 ( V_17 , & V_107 ) ;
goto V_109;
}
static void F_56 ( struct V_1 * V_2 , struct V_5 * V_6 ,
unsigned long V_74 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_74 ; V_32 ++ ) {
if ( V_6 -> V_75 ) {
if ( V_6 -> V_75 ( V_2 ) )
break;
} else {
if ( V_6 -> V_49 ( V_2 ) & V_98 )
break;
}
F_39 ( 1 ) ;
}
}
static int F_57 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_112 , V_15 = V_6 -> V_15 ;
unsigned long V_74 = ( V_15 == V_113 ? 400 : 20 ) ;
F_43 ( V_78 , V_79 ) ;
F_48 ( 100 ) ;
V_6 -> V_45 ( V_2 , V_70 , - 1 , - 1 ) ;
if ( F_42 () || V_77 )
F_56 ( V_2 , V_6 , V_74 ) ;
else {
V_74 = V_76 + F_41 ( V_74 ) ;
while ( F_44 ( V_76 , V_74 ) ) {
if ( V_6 -> V_75 ) {
if ( V_6 -> V_75 ( V_2 ) )
break;
} else {
if ( V_6 -> V_49 ( V_2 ) & V_98 )
break;
}
F_58 () ;
}
}
F_43 ( V_78 , V_80 ) ;
V_112 = ( int ) V_6 -> V_49 ( V_2 ) ;
F_59 ( ! ( V_112 & V_98 ) ) ;
return V_112 ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , int V_114 )
{
int V_8 = 0 ;
int V_112 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_30 = V_3 >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_115 , - 1 , V_30 & V_6 -> V_39 ) ;
V_30 = ( V_3 + V_4 ) >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_116 , - 1 ,
( V_30 | V_114 ) & V_6 -> V_39 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
if ( V_112 & V_118 ) {
F_2 ( L_3 ,
V_10 , V_112 ) ;
V_8 = - V_119 ;
}
return V_8 ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
V_8 = - V_11 ;
if ( V_3 + V_4 == V_2 -> V_120 )
V_4 -= V_2 -> V_36 ;
F_26 ( V_2 , V_121 ) ;
V_19 = V_3 >> V_6 -> V_40 ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_8 = - V_119 ;
goto V_122;
}
V_8 = F_60 ( V_2 , V_3 , V_4 , 0 ) ;
V_122:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
int F_62 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_8 = 0 ;
int V_19 , V_112 , V_30 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_3 , V_4 ) ;
if ( F_1 ( V_2 , V_3 , V_4 ) )
V_8 = - V_11 ;
F_26 ( V_2 , V_123 ) ;
V_19 = V_3 >> V_6 -> V_40 ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_112 = V_124 ;
V_8 = - V_119 ;
goto V_122;
}
V_30 = V_3 >> V_6 -> V_38 ;
V_6 -> V_45 ( V_2 , V_125 , - 1 , V_30 & V_6 -> V_39 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
if ( V_112 & V_118 ) {
F_2 ( L_3 ,
V_10 , V_112 ) ;
V_8 = - V_119 ;
goto V_122;
}
V_8 = F_60 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_122:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_63 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_126 , int V_30 )
{
V_6 -> V_127 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_126 )
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_26 ,
int V_126 , int V_30 )
{
int V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
T_3 * V_134 = V_6 -> V_128 ;
int V_135 , V_120 ;
for ( V_135 = V_6 -> V_131 . V_135 ; V_135 > 0 ; V_135 -- ) {
V_6 -> V_127 ( V_2 , V_26 , V_130 ) ;
V_26 += V_130 ;
if ( V_6 -> V_131 . V_136 ) {
V_6 -> V_127 ( V_2 , V_134 , V_6 -> V_131 . V_136 ) ;
V_134 += V_6 -> V_131 . V_136 ;
}
V_6 -> V_127 ( V_2 , V_134 , V_132 ) ;
V_134 += V_132 ;
if ( V_6 -> V_131 . V_137 ) {
V_6 -> V_127 ( V_2 , V_134 , V_6 -> V_131 . V_137 ) ;
V_134 += V_6 -> V_131 . V_137 ;
}
}
V_120 = V_2 -> V_129 - ( V_134 - V_6 -> V_128 ) ;
if ( V_120 )
V_6 -> V_127 ( V_2 , V_134 , V_120 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_126 , int V_30 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
T_3 * V_28 = V_26 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
T_3 * V_142 = V_6 -> V_140 -> V_143 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
unsigned int V_146 = 0 ;
V_6 -> V_131 . V_147 ( V_2 , V_6 , V_26 , 1 , V_30 ) ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 )
V_6 -> V_131 . V_148 ( V_2 , V_28 , & V_139 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_142 [ V_32 ] = V_6 -> V_128 [ V_144 [ V_32 ] ] ;
V_138 = V_6 -> V_131 . V_135 ;
V_28 = V_26 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
int V_150 ;
V_150 = V_6 -> V_131 . V_151 ( V_2 , V_28 , & V_142 [ V_32 ] , & V_139 [ V_32 ] ) ;
if ( V_150 < 0 ) {
V_2 -> V_67 . V_152 ++ ;
} else {
V_2 -> V_67 . V_153 += V_150 ;
V_146 = F_66 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_154 , T_8 V_155 , T_3 * V_156 ,
int V_30 )
{
int V_157 , V_158 , V_159 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
T_3 * V_28 ;
int V_160 , V_32 , V_161 = 0 ;
int V_162 , V_163 , V_164 , V_165 ;
int V_166 = ( V_6 -> V_43 & V_44 ) ? 2 : 1 ;
int V_167 ;
unsigned int V_146 = 0 ;
V_157 = V_154 / V_6 -> V_131 . V_120 ;
V_158 = ( V_154 + V_155 - 1 ) / V_6 -> V_131 . V_120 ;
V_159 = V_158 - V_157 + 1 ;
V_167 = V_157 * V_6 -> V_131 . V_133 ;
V_162 = V_159 * V_6 -> V_131 . V_120 ;
V_163 = V_159 * V_6 -> V_131 . V_133 ;
V_160 = V_157 * V_6 -> V_131 . V_120 ;
if ( V_160 != 0 )
V_6 -> V_45 ( V_2 , V_103 , V_160 , - 1 ) ;
V_28 = V_156 + V_160 ;
V_6 -> V_127 ( V_2 , V_28 , V_162 ) ;
for ( V_32 = 0 ; V_32 < V_163 ; V_32 += V_6 -> V_131 . V_133 , V_28 += V_6 -> V_131 . V_120 )
V_6 -> V_131 . V_148 ( V_2 , V_28 , & V_6 -> V_140 -> V_141 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_163 - 1 ; V_32 ++ ) {
if ( V_144 [ V_32 + V_167 ] + 1 != V_144 [ V_32 + V_167 + 1 ] ) {
V_161 = 1 ;
break;
}
}
if ( V_161 ) {
V_6 -> V_45 ( V_2 , V_103 , V_2 -> V_37 , - 1 ) ;
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
} else {
V_165 = V_144 [ V_167 ] & ~ ( V_166 - 1 ) ;
V_164 = V_163 ;
if ( V_144 [ V_167 ] & ( V_166 - 1 ) )
V_164 ++ ;
if ( V_144 [ V_167 + ( V_159 * V_6 -> V_131 . V_133 ) ] & ( V_166 - 1 ) )
V_164 ++ ;
V_6 -> V_45 ( V_2 , V_103 ,
V_2 -> V_37 + V_165 , - 1 ) ;
V_6 -> V_127 ( V_2 , & V_6 -> V_128 [ V_165 ] , V_164 ) ;
}
for ( V_32 = 0 ; V_32 < V_163 ; V_32 ++ )
V_6 -> V_140 -> V_143 [ V_32 ] = V_6 -> V_128 [ V_144 [ V_32 + V_167 ] ] ;
V_28 = V_156 + V_160 ;
for ( V_32 = 0 ; V_32 < V_163 ; V_32 += V_6 -> V_131 . V_133 , V_28 += V_6 -> V_131 . V_120 ) {
int V_150 ;
V_150 = V_6 -> V_131 . V_151 ( V_2 , V_28 ,
& V_6 -> V_140 -> V_143 [ V_32 ] , & V_6 -> V_140 -> V_141 [ V_32 ] ) ;
if ( V_150 < 0 ) {
V_2 -> V_67 . V_152 ++ ;
} else {
V_2 -> V_67 . V_153 += V_150 ;
V_146 = F_66 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_126 , int V_30 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
T_3 * V_28 = V_26 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
T_3 * V_142 = V_6 -> V_140 -> V_143 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
unsigned int V_146 = 0 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
V_6 -> V_131 . V_168 ( V_2 , V_169 ) ;
V_6 -> V_127 ( V_2 , V_28 , V_130 ) ;
V_6 -> V_131 . V_148 ( V_2 , V_28 , & V_139 [ V_32 ] ) ;
}
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_142 [ V_32 ] = V_6 -> V_128 [ V_144 [ V_32 ] ] ;
V_138 = V_6 -> V_131 . V_135 ;
V_28 = V_26 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
int V_150 ;
V_150 = V_6 -> V_131 . V_151 ( V_2 , V_28 , & V_142 [ V_32 ] , & V_139 [ V_32 ] ) ;
if ( V_150 < 0 ) {
V_2 -> V_67 . V_152 ++ ;
} else {
V_2 -> V_67 . V_153 += V_150 ;
V_146 = F_66 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_3 * V_26 , int V_126 , int V_30 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
T_3 * V_28 = V_26 ;
T_3 * V_142 = V_6 -> V_140 -> V_143 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
unsigned int V_146 = 0 ;
V_6 -> V_45 ( V_2 , V_46 , 0 , V_30 ) ;
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
V_6 -> V_45 ( V_2 , V_88 , 0 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_142 [ V_32 ] = V_6 -> V_128 [ V_144 [ V_32 ] ] ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
int V_150 ;
V_6 -> V_131 . V_168 ( V_2 , V_169 ) ;
V_6 -> V_127 ( V_2 , V_28 , V_130 ) ;
V_6 -> V_131 . V_148 ( V_2 , V_28 , & V_139 [ V_32 ] ) ;
V_150 = V_6 -> V_131 . V_151 ( V_2 , V_28 , & V_142 [ V_32 ] , NULL ) ;
if ( V_150 < 0 ) {
V_2 -> V_67 . V_152 ++ ;
} else {
V_2 -> V_67 . V_153 += V_150 ;
V_146 = F_66 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_126 , int V_30 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
T_3 * V_28 = V_26 ;
T_3 * V_134 = V_6 -> V_128 ;
unsigned int V_146 = 0 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
int V_150 ;
V_6 -> V_131 . V_168 ( V_2 , V_169 ) ;
V_6 -> V_127 ( V_2 , V_28 , V_130 ) ;
if ( V_6 -> V_131 . V_136 ) {
V_6 -> V_127 ( V_2 , V_134 , V_6 -> V_131 . V_136 ) ;
V_134 += V_6 -> V_131 . V_136 ;
}
V_6 -> V_131 . V_168 ( V_2 , V_170 ) ;
V_6 -> V_127 ( V_2 , V_134 , V_132 ) ;
V_150 = V_6 -> V_131 . V_151 ( V_2 , V_28 , V_134 , NULL ) ;
if ( V_150 < 0 ) {
V_2 -> V_67 . V_152 ++ ;
} else {
V_2 -> V_67 . V_153 += V_150 ;
V_146 = F_66 (unsigned int, max_bitflips, stat) ;
}
V_134 += V_132 ;
if ( V_6 -> V_131 . V_137 ) {
V_6 -> V_127 ( V_2 , V_134 , V_6 -> V_131 . V_137 ) ;
V_134 += V_6 -> V_131 . V_137 ;
}
}
V_32 = V_2 -> V_129 - ( V_134 - V_6 -> V_128 ) ;
if ( V_32 )
V_6 -> V_127 ( V_2 , V_134 , V_32 ) ;
return V_146 ;
}
static T_3 * F_71 ( struct V_5 * V_6 , T_3 * V_134 ,
struct V_52 * V_53 , T_9 V_4 )
{
switch ( V_53 -> V_58 ) {
case V_59 :
case V_171 :
memcpy ( V_134 , V_6 -> V_128 + V_53 -> V_56 , V_4 ) ;
return V_134 + V_4 ;
case V_172 : {
struct V_173 * free = V_6 -> V_131 . V_145 -> V_174 ;
T_8 V_175 = 0 , V_176 = V_53 -> V_56 ;
T_9 V_133 = 0 ;
for (; free -> V_177 && V_4 ; free ++ , V_4 -= V_133 ) {
if ( F_72 ( V_176 ) ) {
if ( V_176 >= free -> V_177 ) {
V_176 -= free -> V_177 ;
continue;
}
V_175 = free -> V_178 + V_176 ;
V_133 = F_73 ( T_9 , V_4 ,
( free -> V_177 - V_176 ) ) ;
V_176 = 0 ;
} else {
V_133 = F_73 ( T_9 , V_4 , free -> V_177 ) ;
V_175 = free -> V_178 ;
}
memcpy ( V_134 , V_6 -> V_128 + V_175 , V_133 ) ;
V_134 += V_133 ;
}
return V_134 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_74 ( struct V_1 * V_2 , int V_179 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_6 , V_179 ) ;
if ( V_179 >= V_6 -> V_180 )
return - V_11 ;
if ( ! V_6 -> V_181 )
return - V_182 ;
return V_6 -> V_181 ( V_2 , V_179 ) ;
}
static int F_75 ( struct V_1 * V_2 , T_1 V_183 ,
struct V_52 * V_53 )
{
int V_19 , V_30 , V_184 , V_185 , V_133 , V_186 , V_126 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 = 0 ;
T_8 V_155 = V_53 -> V_4 ;
T_8 V_187 = V_53 -> V_57 ;
T_8 V_188 = V_53 -> V_58 == V_172 ?
V_2 -> V_189 : V_2 -> V_129 ;
T_3 * V_156 , * V_134 , * V_26 ;
int V_190 ;
unsigned int V_146 = 0 ;
int V_179 = 0 ;
bool V_191 = false ;
V_19 = ( int ) ( V_183 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_184 = ( int ) ( V_183 >> V_6 -> V_38 ) ;
V_30 = V_184 & V_6 -> V_39 ;
V_185 = ( int ) ( V_183 & ( V_2 -> V_37 - 1 ) ) ;
V_26 = V_53 -> V_54 ;
V_134 = V_53 -> V_55 ;
V_126 = V_134 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_192 = V_2 -> V_67 . V_152 ;
V_133 = F_76 ( V_2 -> V_37 - V_185 , V_155 ) ;
V_186 = ( V_133 == V_2 -> V_37 ) ;
if ( ! V_186 )
V_190 = 1 ;
else if ( V_6 -> V_43 & V_193 )
V_190 = ! F_77 ( V_26 ) ;
else
V_190 = 0 ;
if ( V_184 != V_6 -> V_194 || V_134 ) {
V_156 = V_190 ? V_6 -> V_140 -> V_195 : V_26 ;
if ( V_190 && V_186 )
F_2 ( L_7 ,
V_10 , V_26 ) ;
V_196:
V_6 -> V_45 ( V_2 , V_88 , 0x00 , V_30 ) ;
if ( F_72 ( V_53 -> V_58 == V_171 ) )
V_8 = V_6 -> V_131 . V_147 ( V_2 , V_6 , V_156 ,
V_126 ,
V_30 ) ;
else if ( ! V_186 && F_78 ( V_6 ) &&
! V_134 )
V_8 = V_6 -> V_131 . V_197 ( V_2 , V_6 ,
V_185 , V_133 , V_156 ,
V_30 ) ;
else
V_8 = V_6 -> V_131 . V_198 ( V_2 , V_6 , V_156 ,
V_126 , V_30 ) ;
if ( V_8 < 0 ) {
if ( V_190 )
V_6 -> V_194 = - 1 ;
break;
}
V_146 = F_66 (unsigned int, max_bitflips, ret) ;
if ( V_190 ) {
if ( ! F_78 ( V_6 ) && ! V_134 &&
! ( V_2 -> V_67 . V_152 - V_192 ) &&
( V_53 -> V_58 != V_171 ) ) {
V_6 -> V_194 = V_184 ;
V_6 -> V_199 = V_8 ;
} else {
V_6 -> V_194 = - 1 ;
}
memcpy ( V_26 , V_6 -> V_140 -> V_195 + V_185 , V_133 ) ;
}
if ( F_72 ( V_134 ) ) {
int V_200 = F_76 ( V_187 , V_188 ) ;
if ( V_200 ) {
V_134 = F_71 ( V_6 ,
V_134 , V_53 , V_200 ) ;
V_187 -= V_200 ;
}
}
if ( V_6 -> V_43 & V_201 ) {
if ( ! V_6 -> V_75 )
F_47 ( V_6 -> V_97 ) ;
else
F_40 ( V_2 ) ;
}
if ( V_2 -> V_67 . V_152 - V_192 ) {
if ( V_179 + 1 < V_6 -> V_180 ) {
V_179 ++ ;
V_8 = F_74 ( V_2 ,
V_179 ) ;
if ( V_8 < 0 )
break;
V_2 -> V_67 . V_152 = V_192 ;
goto V_196;
} else {
V_191 = true ;
}
}
V_26 += V_133 ;
} else {
memcpy ( V_26 , V_6 -> V_140 -> V_195 + V_185 , V_133 ) ;
V_26 += V_133 ;
V_146 = F_66 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_155 -= V_133 ;
if ( V_179 ) {
V_8 = F_74 ( V_2 , 0 ) ;
if ( V_8 < 0 )
break;
V_179 = 0 ;
}
if ( ! V_155 )
break;
V_185 = 0 ;
V_184 ++ ;
V_30 = V_184 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_6 -> V_42 ( V_2 , - 1 ) ;
V_53 -> V_202 = V_53 -> V_4 - ( T_9 ) V_155 ;
if ( V_134 )
V_53 -> V_203 = V_53 -> V_57 - V_187 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_191 )
return - V_204 ;
return V_146 ;
}
static int F_79 ( struct V_1 * V_2 , T_1 V_183 , T_9 V_4 ,
T_9 * V_202 , T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_41 ) ;
V_53 . V_4 = V_4 ;
V_53 . V_54 = V_26 ;
V_53 . V_55 = NULL ;
V_53 . V_58 = V_59 ;
V_8 = F_75 ( V_2 , V_183 , & V_53 ) ;
* V_202 = V_53 . V_202 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
V_6 -> V_45 ( V_2 , V_46 , 0 , V_30 ) ;
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
T_3 * V_26 = V_6 -> V_128 ;
int V_177 = V_2 -> V_129 ;
int V_205 = V_6 -> V_131 . V_133 + V_6 -> V_131 . V_136 + V_6 -> V_131 . V_137 ;
int V_130 = V_6 -> V_131 . V_120 ;
T_3 * V_156 = V_26 ;
int V_32 , V_200 , V_206 = 0 , V_207 ;
V_6 -> V_45 ( V_2 , V_88 , V_6 -> V_131 . V_120 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_135 ; V_32 ++ ) {
if ( V_206 ) {
V_207 = V_130 + V_32 * ( V_130 + V_205 ) ;
if ( V_2 -> V_37 > 512 )
V_6 -> V_45 ( V_2 , V_103 , V_207 , - 1 ) ;
else
V_6 -> V_45 ( V_2 , V_88 , V_207 , V_30 ) ;
} else
V_206 = 1 ;
V_200 = F_73 ( int , V_177 , V_205 ) ;
V_6 -> V_127 ( V_2 , V_156 , V_200 ) ;
V_156 += V_200 ;
V_177 -= V_200 ;
}
if ( V_177 > 0 )
V_6 -> V_127 ( V_2 , V_156 , V_177 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
int V_112 = 0 ;
const T_3 * V_26 = V_6 -> V_128 ;
int V_177 = V_2 -> V_129 ;
V_6 -> V_45 ( V_2 , V_86 , V_2 -> V_37 , V_30 ) ;
V_6 -> V_24 ( V_2 , V_26 , V_177 ) ;
V_6 -> V_45 ( V_2 , V_93 , - 1 , - 1 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
return V_112 & V_118 ? - V_119 : 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_30 )
{
int V_205 = V_6 -> V_131 . V_133 + V_6 -> V_131 . V_136 + V_6 -> V_131 . V_137 ;
int V_130 = V_6 -> V_131 . V_120 , V_177 = V_2 -> V_129 ;
int V_32 , V_4 , V_207 , V_112 = 0 , V_208 = 0 , V_135 = V_6 -> V_131 . V_135 ;
const T_3 * V_156 = V_6 -> V_128 ;
if ( ! V_6 -> V_131 . V_136 && ! V_6 -> V_131 . V_137 ) {
V_207 = V_135 * ( V_130 + V_205 ) ;
V_135 = 0 ;
} else
V_207 = V_130 ;
V_6 -> V_45 ( V_2 , V_86 , V_207 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_135 ; V_32 ++ ) {
if ( V_208 ) {
if ( V_2 -> V_37 <= 512 ) {
T_8 V_209 = 0xFFFFFFFF ;
V_4 = V_130 ;
while ( V_4 > 0 ) {
int V_210 = F_73 ( int , V_4 , 4 ) ;
V_6 -> V_24 ( V_2 , ( T_3 * ) & V_209 ,
V_210 ) ;
V_4 -= V_210 ;
}
} else {
V_207 = V_130 + V_32 * ( V_130 + V_205 ) ;
V_6 -> V_45 ( V_2 , V_102 , V_207 , - 1 ) ;
}
} else
V_208 = 1 ;
V_4 = F_73 ( int , V_177 , V_205 ) ;
V_6 -> V_24 ( V_2 , V_156 , V_4 ) ;
V_156 += V_4 ;
V_177 -= V_4 ;
}
if ( V_177 > 0 )
V_6 -> V_24 ( V_2 , V_156 , V_177 ) ;
V_6 -> V_45 ( V_2 , V_93 , - 1 , - 1 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
return V_112 & V_118 ? - V_119 : 0 ;
}
static int F_84 ( struct V_1 * V_2 , T_1 V_183 ,
struct V_52 * V_53 )
{
int V_30 , V_184 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_211 V_212 ;
int V_155 = V_53 -> V_57 ;
int V_4 ;
T_3 * V_26 = V_53 -> V_55 ;
int V_8 = 0 ;
F_2 ( L_8 ,
V_10 , ( unsigned long long ) V_183 , V_155 ) ;
V_212 = V_2 -> V_67 ;
if ( V_53 -> V_58 == V_172 )
V_4 = V_6 -> V_131 . V_145 -> V_189 ;
else
V_4 = V_2 -> V_129 ;
if ( F_72 ( V_53 -> V_56 >= V_4 ) ) {
F_2 ( L_9 ,
V_10 ) ;
return - V_11 ;
}
if ( F_72 ( V_183 >= V_2 -> V_120 ||
V_53 -> V_56 + V_155 > ( ( V_2 -> V_120 >> V_6 -> V_38 ) -
( V_183 >> V_6 -> V_38 ) ) * V_4 ) ) {
F_2 ( L_10 ,
V_10 ) ;
return - V_11 ;
}
V_19 = ( int ) ( V_183 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_184 = ( int ) ( V_183 >> V_6 -> V_38 ) ;
V_30 = V_184 & V_6 -> V_39 ;
while ( 1 ) {
if ( V_53 -> V_58 == V_171 )
V_8 = V_6 -> V_131 . V_213 ( V_2 , V_6 , V_30 ) ;
else
V_8 = V_6 -> V_131 . V_214 ( V_2 , V_6 , V_30 ) ;
if ( V_8 < 0 )
break;
V_4 = F_76 ( V_4 , V_155 ) ;
V_26 = F_71 ( V_6 , V_26 , V_53 , V_4 ) ;
if ( V_6 -> V_43 & V_201 ) {
if ( ! V_6 -> V_75 )
F_47 ( V_6 -> V_97 ) ;
else
F_40 ( V_2 ) ;
}
V_155 -= V_4 ;
if ( ! V_155 )
break;
V_184 ++ ;
V_30 = V_184 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_6 -> V_42 ( V_2 , - 1 ) ;
V_53 -> V_203 = V_53 -> V_57 - V_155 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_67 . V_152 - V_212 . V_152 )
return - V_204 ;
return V_2 -> V_67 . V_153 - V_212 . V_153 ? - V_215 : 0 ;
}
static int F_85 ( struct V_1 * V_2 , T_1 V_183 ,
struct V_52 * V_53 )
{
int V_8 = - V_216 ;
V_53 -> V_202 = 0 ;
if ( V_53 -> V_54 && ( V_183 + V_53 -> V_4 ) > V_2 -> V_120 ) {
F_2 ( L_10 ,
V_10 ) ;
return - V_11 ;
}
F_26 ( V_2 , V_41 ) ;
switch ( V_53 -> V_58 ) {
case V_59 :
case V_172 :
case V_171 :
break;
default:
goto V_122;
}
if ( ! V_53 -> V_54 )
V_8 = F_84 ( V_2 , V_183 , V_53 ) ;
else
V_8 = F_75 ( V_2 , V_183 , V_53 ) ;
V_122:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_86 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
V_6 -> V_24 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_126 )
V_6 -> V_24 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
int V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
T_3 * V_134 = V_6 -> V_128 ;
int V_135 , V_120 ;
for ( V_135 = V_6 -> V_131 . V_135 ; V_135 > 0 ; V_135 -- ) {
V_6 -> V_24 ( V_2 , V_26 , V_130 ) ;
V_26 += V_130 ;
if ( V_6 -> V_131 . V_136 ) {
V_6 -> V_24 ( V_2 , V_134 , V_6 -> V_131 . V_136 ) ;
V_134 += V_6 -> V_131 . V_136 ;
}
V_6 -> V_24 ( V_2 , V_134 , V_132 ) ;
V_134 += V_132 ;
if ( V_6 -> V_131 . V_137 ) {
V_6 -> V_24 ( V_2 , V_134 , V_6 -> V_131 . V_137 ) ;
V_134 += V_6 -> V_131 . V_137 ;
}
}
V_120 = V_2 -> V_129 - ( V_134 - V_6 -> V_128 ) ;
if ( V_120 )
V_6 -> V_24 ( V_2 , V_134 , V_120 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
const T_3 * V_28 = V_26 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 )
V_6 -> V_131 . V_148 ( V_2 , V_28 , & V_139 [ V_32 ] ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_6 -> V_128 [ V_144 [ V_32 ] ] = V_139 [ V_32 ] ;
return V_6 -> V_131 . V_217 ( V_2 , V_6 , V_26 , 1 ) ;
}
static int F_89 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
const T_3 * V_28 = V_26 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
V_6 -> V_131 . V_168 ( V_2 , V_218 ) ;
V_6 -> V_24 ( V_2 , V_28 , V_130 ) ;
V_6 -> V_131 . V_148 ( V_2 , V_28 , & V_139 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_6 -> V_128 [ V_144 [ V_32 ] ] = V_139 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_8 V_178 ,
T_8 V_219 , const T_3 * V_26 ,
int V_126 )
{
T_3 * V_220 = V_6 -> V_128 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
int V_221 = V_6 -> V_131 . V_120 ;
int V_222 = V_6 -> V_131 . V_133 ;
int V_223 = V_6 -> V_131 . V_135 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
T_8 V_157 = V_178 / V_221 ;
T_8 V_158 = ( V_178 + V_219 - 1 ) / V_221 ;
int V_224 = V_2 -> V_129 / V_223 ;
int V_225 , V_32 ;
for ( V_225 = 0 ; V_225 < V_223 ; V_225 ++ ) {
V_6 -> V_131 . V_168 ( V_2 , V_218 ) ;
V_6 -> V_24 ( V_2 , V_26 , V_221 ) ;
if ( ( V_225 < V_157 ) || ( V_225 > V_158 ) )
memset ( V_139 , 0xff , V_222 ) ;
else
V_6 -> V_131 . V_148 ( V_2 , V_26 , V_139 ) ;
if ( ! V_126 || ( V_225 < V_157 ) || ( V_225 > V_158 ) )
memset ( V_220 , 0xff , V_224 ) ;
V_26 += V_221 ;
V_139 += V_222 ;
V_220 += V_224 ;
}
V_139 = V_6 -> V_140 -> V_141 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_6 -> V_128 [ V_144 [ V_32 ] ] = V_139 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
const T_3 * V_28 = V_26 ;
T_3 * V_134 = V_6 -> V_128 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
V_6 -> V_131 . V_168 ( V_2 , V_218 ) ;
V_6 -> V_24 ( V_2 , V_28 , V_130 ) ;
if ( V_6 -> V_131 . V_136 ) {
V_6 -> V_24 ( V_2 , V_134 , V_6 -> V_131 . V_136 ) ;
V_134 += V_6 -> V_131 . V_136 ;
}
V_6 -> V_131 . V_148 ( V_2 , V_28 , V_134 ) ;
V_6 -> V_24 ( V_2 , V_134 , V_132 ) ;
V_134 += V_132 ;
if ( V_6 -> V_131 . V_137 ) {
V_6 -> V_24 ( V_2 , V_134 , V_6 -> V_131 . V_137 ) ;
V_134 += V_6 -> V_131 . V_137 ;
}
}
V_32 = V_2 -> V_129 - ( V_134 - V_6 -> V_128 ) ;
if ( V_32 )
V_6 -> V_24 ( V_2 , V_134 , V_32 ) ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_178 , int V_219 , const T_3 * V_26 ,
int V_126 , int V_30 , int V_226 , int V_227 )
{
int V_112 , V_228 ;
if ( ! ( V_6 -> V_43 & V_229 ) &&
V_6 -> V_131 . V_230 )
V_228 = V_178 || ( V_219 < V_2 -> V_37 ) ;
else
V_228 = 0 ;
V_6 -> V_45 ( V_2 , V_86 , 0x00 , V_30 ) ;
if ( F_72 ( V_227 ) )
V_112 = V_6 -> V_131 . V_217 ( V_2 , V_6 , V_26 ,
V_126 ) ;
else if ( V_228 )
V_112 = V_6 -> V_131 . V_230 ( V_2 , V_6 , V_178 , V_219 ,
V_26 , V_126 ) ;
else
V_112 = V_6 -> V_131 . V_231 ( V_2 , V_6 , V_26 , V_126 ) ;
if ( V_112 < 0 )
return V_112 ;
V_226 = 0 ;
if ( ! V_226 || ! F_93 ( V_6 ) ) {
V_6 -> V_45 ( V_2 , V_93 , - 1 , - 1 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
if ( ( V_112 & V_118 ) && ( V_6 -> V_232 ) )
V_112 = V_6 -> V_232 ( V_2 , V_6 , V_64 , V_112 ,
V_30 ) ;
if ( V_112 & V_118 )
return - V_119 ;
} else {
V_6 -> V_45 ( V_2 , V_101 , - 1 , - 1 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
}
return 0 ;
}
static T_3 * F_94 ( struct V_1 * V_2 , T_3 * V_134 , T_9 V_4 ,
struct V_52 * V_53 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memset ( V_6 -> V_128 , 0xff , V_2 -> V_129 ) ;
switch ( V_53 -> V_58 ) {
case V_59 :
case V_171 :
memcpy ( V_6 -> V_128 + V_53 -> V_56 , V_134 , V_4 ) ;
return V_134 + V_4 ;
case V_172 : {
struct V_173 * free = V_6 -> V_131 . V_145 -> V_174 ;
T_8 V_175 = 0 , V_233 = V_53 -> V_56 ;
T_9 V_133 = 0 ;
for (; free -> V_177 && V_4 ; free ++ , V_4 -= V_133 ) {
if ( F_72 ( V_233 ) ) {
if ( V_233 >= free -> V_177 ) {
V_233 -= free -> V_177 ;
continue;
}
V_175 = free -> V_178 + V_233 ;
V_133 = F_73 ( T_9 , V_4 ,
( free -> V_177 - V_233 ) ) ;
V_233 = 0 ;
} else {
V_133 = F_73 ( T_9 , V_4 , free -> V_177 ) ;
V_175 = free -> V_178 ;
}
memcpy ( V_6 -> V_128 + V_175 , V_134 , V_133 ) ;
V_134 += V_133 ;
}
return V_134 ;
}
default:
F_14 () ;
}
return NULL ;
}
static int F_95 ( struct V_1 * V_2 , T_1 V_234 ,
struct V_52 * V_53 )
{
int V_19 , V_184 , V_30 , V_235 , V_82 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_8 V_236 = V_53 -> V_4 ;
T_8 V_237 = V_53 -> V_57 ;
T_8 V_238 = V_53 -> V_58 == V_172 ?
V_2 -> V_189 : V_2 -> V_129 ;
T_3 * V_134 = V_53 -> V_55 ;
T_3 * V_26 = V_53 -> V_54 ;
int V_8 ;
int V_126 = V_134 ? 1 : 0 ;
V_53 -> V_202 = 0 ;
if ( ! V_236 )
return 0 ;
if ( F_96 ( V_234 ) || F_96 ( V_53 -> V_4 ) ) {
F_97 ( L_11 ,
V_10 ) ;
return - V_11 ;
}
V_82 = V_234 & ( V_2 -> V_37 - 1 ) ;
V_19 = ( int ) ( V_234 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
V_8 = - V_119 ;
goto V_239;
}
V_184 = ( int ) ( V_234 >> V_6 -> V_38 ) ;
V_30 = V_184 & V_6 -> V_39 ;
V_235 = ( 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ) - 1 ;
if ( V_234 <= ( V_6 -> V_194 << V_6 -> V_38 ) &&
( V_6 -> V_194 << V_6 -> V_38 ) < ( V_234 + V_53 -> V_4 ) )
V_6 -> V_194 = - 1 ;
if ( V_134 && V_53 -> V_56 && ( V_53 -> V_56 + V_53 -> V_57 > V_238 ) ) {
V_8 = - V_11 ;
goto V_239;
}
while ( 1 ) {
int V_133 = V_2 -> V_37 ;
int V_226 = V_236 > V_133 && V_30 != V_235 ;
T_3 * V_240 = V_26 ;
int V_190 ;
int V_241 = ( V_82 || V_236 < ( V_2 -> V_37 - 1 ) ) ;
if ( V_241 )
V_190 = 1 ;
else if ( V_6 -> V_43 & V_193 )
V_190 = ! F_77 ( V_26 ) ;
else
V_190 = 0 ;
if ( V_190 ) {
F_2 ( L_12 ,
V_10 , V_26 ) ;
V_226 = 0 ;
if ( V_241 )
V_133 = F_73 ( int , V_133 - V_82 , V_236 ) ;
V_6 -> V_194 = - 1 ;
memset ( V_6 -> V_140 -> V_195 , 0xff , V_2 -> V_37 ) ;
memcpy ( & V_6 -> V_140 -> V_195 [ V_82 ] , V_26 , V_133 ) ;
V_240 = V_6 -> V_140 -> V_195 ;
}
if ( F_72 ( V_134 ) ) {
T_9 V_4 = F_76 ( V_237 , V_238 ) ;
V_134 = F_94 ( V_2 , V_134 , V_4 , V_53 ) ;
V_237 -= V_4 ;
} else {
memset ( V_6 -> V_128 , 0xff , V_2 -> V_129 ) ;
}
V_8 = V_6 -> V_231 ( V_2 , V_6 , V_82 , V_133 , V_240 ,
V_126 , V_30 , V_226 ,
( V_53 -> V_58 == V_171 ) ) ;
if ( V_8 )
break;
V_236 -= V_133 ;
if ( ! V_236 )
break;
V_82 = 0 ;
V_26 += V_133 ;
V_184 ++ ;
V_30 = V_184 & V_6 -> V_39 ;
if ( ! V_30 ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_53 -> V_202 = V_53 -> V_4 - V_236 ;
if ( F_72 ( V_134 ) )
V_53 -> V_203 = V_53 -> V_57 ;
V_239:
V_6 -> V_42 ( V_2 , - 1 ) ;
return V_8 ;
}
static int F_98 ( struct V_1 * V_2 , T_1 V_234 , T_9 V_4 ,
T_9 * V_202 , const T_3 * V_26 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_52 V_53 ;
int V_8 ;
F_56 ( V_2 , V_6 , 400 ) ;
F_50 ( V_6 , V_2 , V_64 ) ;
V_53 . V_4 = V_4 ;
V_53 . V_54 = ( T_3 * ) V_26 ;
V_53 . V_55 = NULL ;
V_53 . V_58 = V_59 ;
V_8 = F_95 ( V_2 , V_234 , & V_53 ) ;
* V_202 = V_53 . V_202 ;
return V_8 ;
}
static int F_99 ( struct V_1 * V_2 , T_1 V_234 , T_9 V_4 ,
T_9 * V_202 , const T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_64 ) ;
V_53 . V_4 = V_4 ;
V_53 . V_54 = ( T_3 * ) V_26 ;
V_53 . V_55 = NULL ;
V_53 . V_58 = V_59 ;
V_8 = F_95 ( V_2 , V_234 , & V_53 ) ;
* V_202 = V_53 . V_202 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_234 ,
struct V_52 * V_53 )
{
int V_19 , V_30 , V_112 , V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_13 ,
V_10 , ( unsigned int ) V_234 , ( int ) V_53 -> V_57 ) ;
if ( V_53 -> V_58 == V_172 )
V_4 = V_6 -> V_131 . V_145 -> V_189 ;
else
V_4 = V_2 -> V_129 ;
if ( ( V_53 -> V_56 + V_53 -> V_57 ) > V_4 ) {
F_2 ( L_14 ,
V_10 ) ;
return - V_11 ;
}
if ( F_72 ( V_53 -> V_56 >= V_4 ) ) {
F_2 ( L_15 ,
V_10 ) ;
return - V_11 ;
}
if ( F_72 ( V_234 >= V_2 -> V_120 ||
V_53 -> V_56 + V_53 -> V_57 >
( ( V_2 -> V_120 >> V_6 -> V_38 ) -
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
F_94 ( V_2 , V_53 -> V_55 , V_53 -> V_57 , V_53 ) ;
if ( V_53 -> V_58 == V_171 )
V_112 = V_6 -> V_131 . V_243 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
else
V_112 = V_6 -> V_131 . V_244 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
if ( V_112 )
return V_112 ;
V_53 -> V_203 = V_53 -> V_57 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , T_1 V_234 ,
struct V_52 * V_53 )
{
int V_8 = - V_216 ;
V_53 -> V_202 = 0 ;
if ( V_53 -> V_54 && ( V_234 + V_53 -> V_4 ) > V_2 -> V_120 ) {
F_2 ( L_16 ,
V_10 ) ;
return - V_11 ;
}
F_26 ( V_2 , V_64 ) ;
switch ( V_53 -> V_58 ) {
case V_59 :
case V_172 :
case V_171 :
break;
default:
goto V_122;
}
if ( ! V_53 -> V_54 )
V_8 = F_30 ( V_2 , V_234 , V_53 ) ;
else
V_8 = F_95 ( V_2 , V_234 , V_53 ) ;
V_122:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_101 ( struct V_1 * V_2 , int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_45 ( V_2 , V_94 , - 1 , V_30 ) ;
V_6 -> V_45 ( V_2 , V_95 , - 1 , - 1 ) ;
return V_6 -> V_117 ( V_2 , V_6 ) ;
}
static int F_102 ( struct V_1 * V_2 , struct V_61 * V_245 )
{
return F_32 ( V_2 , V_245 , 0 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_61 * V_245 ,
int V_72 )
{
int V_30 , V_112 , V_246 , V_8 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_245 -> V_63 ,
( unsigned long long ) V_245 -> V_4 ) ;
if ( F_1 ( V_2 , V_245 -> V_63 , V_245 -> V_4 ) )
return - V_11 ;
F_26 ( V_2 , V_113 ) ;
V_30 = ( int ) ( V_245 -> V_63 >> V_6 -> V_38 ) ;
V_19 = ( int ) ( V_245 -> V_63 >> V_6 -> V_40 ) ;
V_246 = 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_245 -> V_15 = V_124 ;
goto V_247;
}
V_4 = V_245 -> V_4 ;
V_245 -> V_15 = V_248 ;
while ( V_4 ) {
if ( F_35 ( V_2 , ( ( T_1 ) V_30 ) <<
V_6 -> V_38 , 0 , V_72 ) ) {
F_103 ( L_17 ,
V_10 , V_30 ) ;
V_245 -> V_15 = V_124 ;
goto V_247;
}
if ( V_30 <= V_6 -> V_194 && V_6 -> V_194 <
( V_30 + V_246 ) )
V_6 -> V_194 = - 1 ;
V_112 = V_6 -> V_249 ( V_2 , V_30 & V_6 -> V_39 ) ;
if ( ( V_112 & V_118 ) && ( V_6 -> V_232 ) )
V_112 = V_6 -> V_232 ( V_2 , V_6 , V_113 ,
V_112 , V_30 ) ;
if ( V_112 & V_118 ) {
F_2 ( L_18 ,
V_10 , V_30 ) ;
V_245 -> V_15 = V_124 ;
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
V_8 = V_245 -> V_15 == V_251 ? 0 : - V_119 ;
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
if ( ! V_8 )
F_104 ( V_245 ) ;
return V_8 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_2 ( L_19 , V_10 ) ;
F_26 ( V_2 , V_252 ) ;
F_3 ( V_2 ) ;
}
static int F_106 ( struct V_1 * V_2 , T_1 V_253 )
{
return F_35 ( V_2 , V_253 , 1 , 0 ) ;
}
static int F_107 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
V_8 = F_106 ( V_2 , V_3 ) ;
if ( V_8 ) {
if ( V_8 > 0 )
return 0 ;
return V_8 ;
}
return F_31 ( V_2 , V_3 ) ;
}
static int F_108 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_63 , T_3 * V_254 )
{
int V_112 ;
int V_32 ;
if ( ! V_6 -> V_255 ||
! ( F_109 ( V_6 -> V_256 . V_257 )
& V_258 ) )
return - V_11 ;
V_6 -> V_45 ( V_2 , V_259 , V_63 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_260 ; ++ V_32 )
V_6 -> V_261 ( V_2 , V_254 [ V_32 ] ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
if ( V_112 & V_118 )
return - V_119 ;
return 0 ;
}
static int F_110 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_63 , T_3 * V_254 )
{
int V_32 ;
if ( ! V_6 -> V_255 ||
! ( F_109 ( V_6 -> V_256 . V_257 )
& V_258 ) )
return - V_11 ;
memset ( V_254 , 0 , V_260 ) ;
V_6 -> V_45 ( V_2 , V_262 , V_63 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_260 ; ++ V_32 )
* V_254 ++ = V_6 -> V_49 ( V_2 ) ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_110 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_15 == V_110 )
F_3 ( V_2 ) ;
else
F_113 ( L_20 ,
V_10 ) ;
}
static void F_114 ( struct V_5 * V_6 , int V_166 )
{
if ( ! V_6 -> V_97 )
V_6 -> V_97 = 20 ;
if ( V_6 -> V_45 == NULL )
V_6 -> V_45 = F_45 ;
if ( V_6 -> V_117 == NULL )
V_6 -> V_117 = F_57 ;
if ( ! V_6 -> V_42 )
V_6 -> V_42 = F_13 ;
if ( ! V_6 -> V_263 )
V_6 -> V_263 = F_108 ;
if ( ! V_6 -> V_264 )
V_6 -> V_264 = F_110 ;
if ( ! V_6 -> V_49 || V_6 -> V_49 == F_7 )
V_6 -> V_49 = V_166 ? F_9 : F_7 ;
if ( ! V_6 -> V_48 )
V_6 -> V_48 = F_12 ;
if ( ! V_6 -> V_73 )
V_6 -> V_73 = F_25 ;
if ( ! V_6 -> V_65 )
V_6 -> V_65 = F_29 ;
if ( ! V_6 -> V_24 || V_6 -> V_24 == F_17 )
V_6 -> V_24 = V_166 ? F_21 : F_17 ;
if ( ! V_6 -> V_261 || V_6 -> V_261 == F_15 )
V_6 -> V_261 = V_166 ? F_16 : F_15 ;
if ( ! V_6 -> V_127 || V_6 -> V_127 == F_19 )
V_6 -> V_127 = V_166 ? F_23 : F_19 ;
if ( ! V_6 -> V_265 )
V_6 -> V_265 = V_266 ;
if ( ! V_6 -> V_12 ) {
V_6 -> V_12 = & V_6 -> V_267 ;
F_115 ( & V_6 -> V_12 -> V_13 ) ;
F_116 ( & V_6 -> V_12 -> V_17 ) ;
}
}
static void F_117 ( T_3 * V_268 , T_9 V_4 )
{
T_10 V_32 ;
V_268 [ V_4 - 1 ] = 0 ;
for ( V_32 = 0 ; V_32 < V_4 - 1 ; V_32 ++ ) {
if ( V_268 [ V_32 ] < ' ' || V_268 [ V_32 ] > 127 )
V_268 [ V_32 ] = '?' ;
}
F_118 ( V_268 ) ;
}
static T_4 F_119 ( T_4 V_269 , T_11 const * V_28 , T_9 V_4 )
{
int V_32 ;
while ( V_4 -- ) {
V_269 ^= * V_28 ++ << 8 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_269 = ( V_269 << 1 ) ^ ( ( V_269 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_269 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_270 * V_28 )
{
struct V_271 * V_272 ;
struct V_273 * V_268 ;
struct V_274 * V_131 ;
T_3 * V_275 ;
int V_8 = - V_11 ;
int V_4 ;
int V_32 ;
V_4 = F_109 ( V_28 -> V_276 ) * 16 ;
V_272 = F_121 ( V_4 , V_277 ) ;
if ( ! V_272 )
return - V_278 ;
V_6 -> V_45 ( V_2 , V_279 , 0 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_103 ,
sizeof( * V_28 ) * V_28 -> V_280 , - 1 ) ;
V_6 -> V_127 ( V_2 , ( T_3 * ) V_272 , V_4 ) ;
if ( ( F_119 ( V_281 , ( ( T_3 * ) V_272 ) + 2 , V_4 - 2 )
!= F_109 ( V_272 -> V_269 ) ) ) {
F_2 ( L_21 ) ;
goto V_282;
}
if ( strncmp ( V_272 -> V_283 , L_22 , 4 ) ) {
F_2 ( L_23 ) ;
goto V_282;
}
V_275 = ( T_3 * ) ( V_272 + 1 ) ;
for ( V_32 = 0 ; V_32 < V_284 ; V_32 ++ ) {
V_268 = V_272 -> V_285 + V_32 ;
if ( V_268 -> type == V_286 )
break;
V_275 += V_268 -> V_177 * 16 ;
}
if ( V_32 == V_284 ) {
F_2 ( L_24 ) ;
goto V_282;
}
V_131 = (struct V_274 * ) V_275 ;
if ( ! V_131 -> V_287 ) {
F_2 ( L_25 ) ;
goto V_282;
}
V_6 -> V_288 = V_131 -> V_289 ;
V_6 -> V_290 = 1 << V_131 -> V_287 ;
V_8 = 0 ;
V_282:
F_122 ( V_272 ) ;
return V_8 ;
}
static int F_123 ( struct V_1 * V_2 , int V_179 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_291 [ V_260 ] = { V_179 } ;
return V_6 -> V_263 ( V_2 , V_6 , V_292 ,
V_291 ) ;
}
static void F_124 ( struct V_5 * V_6 ,
struct V_270 * V_28 )
{
struct V_293 * V_294 = ( void * ) V_28 -> V_295 ;
if ( F_109 ( V_28 -> V_296 ) < 1 )
return;
V_6 -> V_180 = V_294 -> V_297 ;
V_6 -> V_181 = F_123 ;
}
static int F_125 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_166 )
{
struct V_270 * V_28 = & V_6 -> V_256 ;
int V_32 , V_298 ;
int V_299 ;
V_6 -> V_45 ( V_2 , V_300 , 0x20 , - 1 ) ;
if ( V_6 -> V_49 ( V_2 ) != 'O' || V_6 -> V_49 ( V_2 ) != 'N' ||
V_6 -> V_49 ( V_2 ) != 'F' || V_6 -> V_49 ( V_2 ) != 'I' )
return 0 ;
V_6 -> V_45 ( V_2 , V_279 , 0 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
for ( V_298 = 0 ; V_298 < sizeof( * V_28 ) ; V_298 ++ )
( ( T_3 * ) V_28 ) [ V_298 ] = V_6 -> V_49 ( V_2 ) ;
if ( F_119 ( V_281 , ( T_3 * ) V_28 , 254 ) ==
F_109 ( V_28 -> V_269 ) ) {
break;
}
}
if ( V_32 == 3 ) {
F_113 ( L_26 ) ;
return 0 ;
}
V_299 = F_109 ( V_28 -> V_301 ) ;
if ( V_299 & ( 1 << 5 ) )
V_6 -> V_255 = 23 ;
else if ( V_299 & ( 1 << 4 ) )
V_6 -> V_255 = 22 ;
else if ( V_299 & ( 1 << 3 ) )
V_6 -> V_255 = 21 ;
else if ( V_299 & ( 1 << 2 ) )
V_6 -> V_255 = 20 ;
else if ( V_299 & ( 1 << 1 ) )
V_6 -> V_255 = 10 ;
if ( ! V_6 -> V_255 ) {
F_126 ( L_27 , V_299 ) ;
return 0 ;
}
F_117 ( V_28 -> V_302 , sizeof( V_28 -> V_302 ) ) ;
F_117 ( V_28 -> V_303 , sizeof( V_28 -> V_303 ) ) ;
if ( ! V_2 -> V_304 )
V_2 -> V_304 = V_28 -> V_303 ;
V_2 -> V_37 = F_127 ( V_28 -> V_305 ) ;
V_2 -> V_36 = 1 << ( F_128 ( F_127 ( V_28 -> V_246 ) ) - 1 ) ;
V_2 -> V_36 *= V_2 -> V_37 ;
V_2 -> V_129 = F_109 ( V_28 -> V_306 ) ;
V_6 -> V_91 = 1 << ( F_128 ( F_127 ( V_28 -> V_307 ) ) - 1 ) ;
V_6 -> V_91 *= ( T_2 ) V_2 -> V_36 * V_28 -> V_308 ;
V_6 -> V_309 = V_28 -> V_309 ;
if ( F_129 ( V_6 ) & V_310 )
* V_166 = V_44 ;
else
* V_166 = 0 ;
if ( V_28 -> V_289 != 0xff ) {
V_6 -> V_288 = V_28 -> V_289 ;
V_6 -> V_290 = 512 ;
} else if ( V_6 -> V_255 >= 21 &&
( F_129 ( V_6 ) & V_311 ) ) {
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_45 )
V_6 -> V_45 = F_49 ;
if ( F_120 ( V_2 , V_6 , V_28 ) )
F_103 ( L_28 ) ;
} else {
F_103 ( L_29 ) ;
}
if ( V_28 -> V_312 == V_313 )
F_124 ( V_6 , V_28 ) ;
return 1 ;
}
static int F_130 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_166 )
{
struct V_314 * V_28 = & V_6 -> V_315 ;
struct V_316 * V_131 ;
int V_299 ;
int V_32 , V_298 ;
V_6 -> V_45 ( V_2 , V_300 , 0x40 , - 1 ) ;
if ( V_6 -> V_49 ( V_2 ) != 'J' || V_6 -> V_49 ( V_2 ) != 'E' ||
V_6 -> V_49 ( V_2 ) != 'D' || V_6 -> V_49 ( V_2 ) != 'E' ||
V_6 -> V_49 ( V_2 ) != 'C' )
return 0 ;
V_6 -> V_45 ( V_2 , V_279 , 0x40 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
for ( V_298 = 0 ; V_298 < sizeof( * V_28 ) ; V_298 ++ )
( ( T_3 * ) V_28 ) [ V_298 ] = V_6 -> V_49 ( V_2 ) ;
if ( F_119 ( V_281 , ( T_3 * ) V_28 , 510 ) ==
F_109 ( V_28 -> V_269 ) )
break;
}
if ( V_32 == 3 ) {
F_113 ( L_30 ) ;
return 0 ;
}
V_299 = F_109 ( V_28 -> V_301 ) ;
if ( V_299 & ( 1 << 2 ) )
V_6 -> V_317 = 10 ;
else if ( V_299 & ( 1 << 1 ) )
V_6 -> V_317 = 1 ;
if ( ! V_6 -> V_317 ) {
F_126 ( L_31 , V_299 ) ;
return 0 ;
}
F_117 ( V_28 -> V_302 , sizeof( V_28 -> V_302 ) ) ;
F_117 ( V_28 -> V_303 , sizeof( V_28 -> V_303 ) ) ;
if ( ! V_2 -> V_304 )
V_2 -> V_304 = V_28 -> V_303 ;
V_2 -> V_37 = F_127 ( V_28 -> V_305 ) ;
V_2 -> V_36 = 1 << ( F_128 ( F_127 ( V_28 -> V_246 ) ) - 1 ) ;
V_2 -> V_36 *= V_2 -> V_37 ;
V_2 -> V_129 = F_109 ( V_28 -> V_306 ) ;
V_6 -> V_91 = 1 << ( F_128 ( F_127 ( V_28 -> V_307 ) ) - 1 ) ;
V_6 -> V_91 *= ( T_2 ) V_2 -> V_36 * V_28 -> V_308 ;
V_6 -> V_309 = V_28 -> V_309 ;
if ( F_131 ( V_6 ) & V_318 )
* V_166 = V_44 ;
else
* V_166 = 0 ;
V_131 = & V_28 -> V_319 [ 0 ] ;
if ( V_131 -> V_287 >= 9 ) {
V_6 -> V_288 = V_131 -> V_289 ;
V_6 -> V_290 = 1 << V_131 -> V_287 ;
} else {
F_103 ( L_25 ) ;
}
return 1 ;
}
static int F_132 ( T_11 * V_320 , int V_321 , int V_322 )
{
int V_32 , V_298 ;
for ( V_32 = 0 ; V_32 < V_322 ; V_32 ++ )
for ( V_298 = V_32 + V_322 ; V_298 < V_321 ; V_298 += V_322 )
if ( V_320 [ V_32 ] != V_320 [ V_298 ] )
return 0 ;
return 1 ;
}
static int F_133 ( T_11 * V_320 , int V_321 )
{
int V_323 , V_322 ;
for ( V_323 = V_321 - 1 ; V_323 >= 0 ; V_323 -- )
if ( V_320 [ V_323 ] )
break;
if ( V_323 < 0 )
return 0 ;
for ( V_322 = 1 ; V_322 < V_321 ; V_322 ++ )
if ( F_132 ( V_320 , V_321 , V_322 ) )
break;
if ( V_322 < V_321 )
return V_322 ;
if ( V_323 < V_321 - 1 )
return V_323 + 1 ;
return V_321 ;
}
static int F_134 ( T_11 V_324 )
{
int V_325 ;
V_325 = V_324 & V_326 ;
V_325 >>= V_327 ;
return V_325 + 1 ;
}
static void F_135 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_11 V_320 [ 8 ] , int * V_166 )
{
int V_328 , V_329 ;
V_6 -> V_309 = F_134 ( V_320 [ 2 ] ) ;
V_328 = V_320 [ 3 ] ;
V_329 = F_133 ( V_320 , 8 ) ;
if ( V_329 == 6 && V_320 [ 0 ] == V_330 &&
! F_136 ( V_6 ) && V_320 [ 5 ] != 0x00 ) {
V_2 -> V_37 = 2048 << ( V_328 & 0x03 ) ;
V_328 >>= 2 ;
switch ( ( ( V_328 >> 2 ) & 0x04 ) | ( V_328 & 0x03 ) ) {
case 1 :
V_2 -> V_129 = 128 ;
break;
case 2 :
V_2 -> V_129 = 218 ;
break;
case 3 :
V_2 -> V_129 = 400 ;
break;
case 4 :
V_2 -> V_129 = 436 ;
break;
case 5 :
V_2 -> V_129 = 512 ;
break;
case 6 :
V_2 -> V_129 = 640 ;
break;
case 7 :
default:
V_2 -> V_129 = 1024 ;
break;
}
V_328 >>= 2 ;
V_2 -> V_36 = ( 128 * 1024 ) <<
( ( ( V_328 >> 1 ) & 0x04 ) | ( V_328 & 0x03 ) ) ;
* V_166 = 0 ;
} else if ( V_329 == 6 && V_320 [ 0 ] == V_331 &&
! F_136 ( V_6 ) ) {
unsigned int V_332 ;
V_2 -> V_37 = 2048 << ( V_328 & 0x03 ) ;
V_328 >>= 2 ;
switch ( ( ( V_328 >> 2 ) & 0x04 ) | ( V_328 & 0x03 ) ) {
case 0 :
V_2 -> V_129 = 128 ;
break;
case 1 :
V_2 -> V_129 = 224 ;
break;
case 2 :
V_2 -> V_129 = 448 ;
break;
case 3 :
V_2 -> V_129 = 64 ;
break;
case 4 :
V_2 -> V_129 = 32 ;
break;
case 5 :
V_2 -> V_129 = 16 ;
break;
default:
V_2 -> V_129 = 640 ;
break;
}
V_328 >>= 2 ;
V_332 = ( ( V_328 >> 1 ) & 0x04 ) | ( V_328 & 0x03 ) ;
if ( V_332 < 0x03 )
V_2 -> V_36 = ( 128 * 1024 ) << V_332 ;
else if ( V_332 == 0x03 )
V_2 -> V_36 = 768 * 1024 ;
else
V_2 -> V_36 = ( 64 * 1024 ) << V_332 ;
* V_166 = 0 ;
} else {
V_2 -> V_37 = 1024 << ( V_328 & 0x03 ) ;
V_328 >>= 2 ;
V_2 -> V_129 = ( 8 << ( V_328 & 0x01 ) ) *
( V_2 -> V_37 >> 9 ) ;
V_328 >>= 2 ;
V_2 -> V_36 = ( 64 * 1024 ) << ( V_328 & 0x03 ) ;
V_328 >>= 2 ;
* V_166 = ( V_328 & 0x01 ) ? V_44 : 0 ;
if ( V_329 >= 6 && V_320 [ 0 ] == V_333 &&
F_136 ( V_6 ) &&
( V_320 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_320 [ 4 ] & 0x80 ) ) {
V_2 -> V_129 = 32 * V_2 -> V_37 >> 9 ;
}
}
}
static void F_137 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_334 * type , T_11 V_320 [ 8 ] ,
int * V_166 )
{
int V_335 = V_320 [ 0 ] ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_37 = type -> V_336 ;
V_2 -> V_129 = V_2 -> V_37 / 32 ;
* V_166 = type -> V_43 & V_44 ;
V_6 -> V_309 = 1 ;
if ( V_335 == V_337 && V_320 [ 4 ] != 0x00 && V_320 [ 5 ] == 0x00
&& V_320 [ 6 ] == 0x00 && V_320 [ 7 ] == 0x00
&& V_2 -> V_37 == 512 ) {
V_2 -> V_36 = 128 * 1024 ;
V_2 -> V_36 <<= ( ( V_320 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_138 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_11 V_320 [ 8 ] )
{
int V_335 = V_320 [ 0 ] ;
if ( V_2 -> V_37 > 512 || ( V_6 -> V_43 & V_44 ) )
V_6 -> V_47 = V_338 ;
else
V_6 -> V_47 = V_339 ;
if ( ! F_136 ( V_6 ) &&
( V_335 == V_330 ||
V_335 == V_331 ) )
V_6 -> V_34 |= V_35 ;
else if ( ( F_136 ( V_6 ) &&
( V_335 == V_330 ||
V_335 == V_331 ||
V_335 == V_333 ||
V_335 == V_337 ||
V_335 == V_340 ) ) ||
( V_2 -> V_37 == 2048 &&
V_335 == V_313 ) )
V_6 -> V_34 |= V_51 ;
}
static inline bool F_139 ( struct V_334 * type )
{
return type -> V_329 ;
}
static bool F_140 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_334 * type , T_11 * V_320 , int * V_166 )
{
if ( ! strncmp ( type -> V_341 , V_320 , type -> V_329 ) ) {
V_2 -> V_37 = type -> V_336 ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_129 = type -> V_129 ;
V_6 -> V_309 = F_134 ( V_320 [ 2 ] ) ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
V_6 -> V_43 |= type -> V_43 ;
V_6 -> V_288 = F_141 ( type ) ;
V_6 -> V_290 = F_142 ( type ) ;
* V_166 = type -> V_43 & V_44 ;
if ( ! V_2 -> V_304 )
V_2 -> V_304 = type -> V_304 ;
return true ;
}
return false ;
}
static struct V_334 * F_143 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int * V_335 , int * V_342 ,
struct V_334 * type )
{
int V_166 ;
int V_32 , V_343 ;
T_11 V_320 [ 8 ] ;
V_6 -> V_42 ( V_2 , 0 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_300 , 0x00 , - 1 ) ;
* V_335 = V_6 -> V_49 ( V_2 ) ;
* V_342 = V_6 -> V_49 ( V_2 ) ;
V_6 -> V_45 ( V_2 , V_300 , 0x00 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_320 [ V_32 ] = V_6 -> V_49 ( V_2 ) ;
if ( V_320 [ 0 ] != * V_335 || V_320 [ 1 ] != * V_342 ) {
F_126 ( L_32 ,
* V_335 , * V_342 , V_320 [ 0 ] , V_320 [ 1 ] ) ;
return F_144 ( - V_344 ) ;
}
if ( ! type )
type = V_345 ;
for (; type -> V_304 != NULL ; type ++ ) {
if ( F_139 ( type ) ) {
if ( F_140 ( V_2 , V_6 , type , V_320 , & V_166 ) )
goto V_346;
} else if ( * V_342 == type -> V_342 ) {
break;
}
}
V_6 -> V_255 = 0 ;
if ( ! type -> V_304 || ! type -> V_336 ) {
if ( F_125 ( V_2 , V_6 , & V_166 ) )
goto V_346;
if ( F_130 ( V_2 , V_6 , & V_166 ) )
goto V_346;
}
if ( ! type -> V_304 )
return F_144 ( - V_344 ) ;
if ( ! V_2 -> V_304 )
V_2 -> V_304 = type -> V_304 ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
if ( ! type -> V_336 && V_6 -> V_347 ) {
V_166 = V_6 -> V_347 ( V_2 , V_6 , V_320 ) ;
} else if ( ! type -> V_336 ) {
F_135 ( V_2 , V_6 , V_320 , & V_166 ) ;
} else {
F_137 ( V_2 , V_6 , type , V_320 , & V_166 ) ;
}
V_6 -> V_43 |= type -> V_43 ;
if ( * V_335 != V_330 && ! type -> V_336 )
V_6 -> V_43 &= ~ V_348 ;
V_346:
for ( V_343 = 0 ; V_349 [ V_343 ] . V_341 != 0x0 ; V_343 ++ ) {
if ( V_349 [ V_343 ] . V_341 == * V_335 )
break;
}
if ( V_6 -> V_43 & V_350 ) {
F_59 ( V_6 -> V_43 & V_44 ) ;
V_6 -> V_43 |= V_166 ;
F_114 ( V_6 , V_166 ) ;
} else if ( V_166 != ( V_6 -> V_43 & V_44 ) ) {
F_126 ( L_33 ,
* V_335 , * V_342 ) ;
F_126 ( L_34 , V_349 [ V_343 ] . V_304 , V_2 -> V_304 ) ;
F_103 ( L_35 ,
( V_6 -> V_43 & V_44 ) ? 16 : 8 ,
V_166 ? 16 : 8 ) ;
return F_144 ( - V_11 ) ;
}
F_138 ( V_2 , V_6 , V_320 ) ;
V_6 -> V_38 = F_145 ( V_2 -> V_37 ) - 1 ;
V_6 -> V_39 = ( V_6 -> V_91 >> V_6 -> V_38 ) - 1 ;
V_6 -> V_351 = V_6 -> V_9 =
F_145 ( V_2 -> V_36 ) - 1 ;
if ( V_6 -> V_91 & 0xffffffff )
V_6 -> V_40 = F_145 ( ( unsigned ) V_6 -> V_91 ) - 1 ;
else {
V_6 -> V_40 = F_145 ( ( unsigned ) ( V_6 -> V_91 >> 32 ) ) ;
V_6 -> V_40 += 32 - 1 ;
}
V_6 -> V_50 = 8 ;
V_6 -> V_249 = F_101 ;
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_45 )
V_6 -> V_45 = F_49 ;
F_126 ( L_33 ,
* V_335 , * V_342 ) ;
if ( V_6 -> V_255 )
F_126 ( L_34 , V_349 [ V_343 ] . V_304 ,
V_6 -> V_256 . V_303 ) ;
else if ( V_6 -> V_317 )
F_126 ( L_34 , V_349 [ V_343 ] . V_304 ,
V_6 -> V_315 . V_303 ) ;
else
F_126 ( L_34 , V_349 [ V_343 ] . V_304 ,
type -> V_304 ) ;
F_126 ( L_36 ,
( int ) ( V_6 -> V_91 >> 20 ) , F_136 ( V_6 ) ? L_37 : L_38 ,
V_2 -> V_37 , V_2 -> V_129 ) ;
return type ;
}
int F_146 ( struct V_1 * V_2 , int V_352 ,
struct V_334 * V_353 )
{
int V_32 , V_354 , V_355 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_334 * type ;
F_114 ( V_6 , V_6 -> V_43 & V_44 ) ;
type = F_143 ( V_2 , V_6 , & V_354 ,
& V_355 , V_353 ) ;
if ( F_147 ( type ) ) {
if ( ! ( V_6 -> V_43 & V_356 ) )
F_103 ( L_39 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
return F_148 ( type ) ;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
for ( V_32 = 1 ; V_32 < V_352 ; V_32 ++ ) {
V_6 -> V_42 ( V_2 , V_32 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_300 , 0x00 , - 1 ) ;
if ( V_354 != V_6 -> V_49 ( V_2 ) ||
V_355 != V_6 -> V_49 ( V_2 ) ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
break;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
}
if ( V_32 > 1 )
F_126 ( L_40 , V_32 ) ;
V_6 -> V_357 = V_32 ;
V_2 -> V_120 = V_32 * V_6 -> V_91 ;
return 0 ;
}
static bool F_149 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_358 * V_131 = & V_6 -> V_131 ;
int V_359 , V_360 ;
if ( V_131 -> V_120 == 0 || V_6 -> V_290 == 0 )
return true ;
V_359 = ( V_2 -> V_37 * V_131 -> V_361 ) / V_131 -> V_120 ;
V_360 = ( V_2 -> V_37 * V_6 -> V_288 ) / V_6 -> V_290 ;
return V_359 >= V_360 && V_131 -> V_361 >= V_6 -> V_288 ;
}
int F_150 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_358 * V_131 = & V_6 -> V_131 ;
struct V_362 * V_363 ;
F_151 ( ( V_6 -> V_34 & V_60 ) &&
! ( V_6 -> V_34 & V_364 ) ) ;
if ( ! ( V_6 -> V_43 & V_365 ) ) {
V_363 = F_152 ( sizeof( * V_363 ) + V_2 -> V_37
+ V_2 -> V_129 * 3 , V_277 ) ;
if ( ! V_363 )
return - V_278 ;
V_363 -> V_141 = ( T_3 * ) ( V_363 + 1 ) ;
V_363 -> V_143 = V_363 -> V_141 + V_2 -> V_129 ;
V_363 -> V_195 = V_363 -> V_143 + V_2 -> V_129 ;
V_6 -> V_140 = V_363 ;
} else {
if ( ! V_6 -> V_140 )
return - V_278 ;
}
V_6 -> V_128 = V_6 -> V_140 -> V_195 + V_2 -> V_37 ;
if ( ! V_131 -> V_145 && ( V_131 -> V_58 != V_366 ) ) {
switch ( V_2 -> V_129 ) {
case 8 :
V_131 -> V_145 = & V_367 ;
break;
case 16 :
V_131 -> V_145 = & V_368 ;
break;
case 64 :
V_131 -> V_145 = & V_369 ;
break;
case 128 :
V_131 -> V_145 = & V_370 ;
break;
default:
F_103 ( L_41 ,
V_2 -> V_129 ) ;
F_14 () ;
}
}
if ( ! V_6 -> V_231 )
V_6 -> V_231 = F_92 ;
switch ( V_131 -> V_58 ) {
case V_371 :
if ( ! V_131 -> V_148 || ! V_131 -> V_151 || ! V_131 -> V_168 ) {
F_103 ( L_42
L_43 ) ;
F_14 () ;
}
if ( ! V_131 -> V_198 )
V_131 -> V_198 = F_69 ;
case V_372 :
if ( ! V_131 -> V_198 )
V_131 -> V_198 = F_68 ;
if ( ! V_131 -> V_231 )
V_131 -> V_231 = F_89 ;
if ( ! V_131 -> V_147 )
V_131 -> V_147 = F_63 ;
if ( ! V_131 -> V_217 )
V_131 -> V_217 = F_86 ;
if ( ! V_131 -> V_214 )
V_131 -> V_214 = F_80 ;
if ( ! V_131 -> V_244 )
V_131 -> V_244 = F_82 ;
if ( ! V_131 -> V_197 )
V_131 -> V_197 = F_67 ;
if ( ! V_131 -> V_230 )
V_131 -> V_230 = F_90 ;
case V_373 :
if ( ( ! V_131 -> V_148 || ! V_131 -> V_151 || ! V_131 -> V_168 ) &&
( ! V_131 -> V_198 ||
V_131 -> V_198 == F_68 ||
! V_131 -> V_231 ||
V_131 -> V_231 == F_89 ) ) {
F_103 ( L_42
L_43 ) ;
F_14 () ;
}
if ( ! V_131 -> V_198 )
V_131 -> V_198 = F_70 ;
if ( ! V_131 -> V_231 )
V_131 -> V_231 = F_91 ;
if ( ! V_131 -> V_147 )
V_131 -> V_147 = F_64 ;
if ( ! V_131 -> V_217 )
V_131 -> V_217 = F_87 ;
if ( ! V_131 -> V_214 )
V_131 -> V_214 = F_81 ;
if ( ! V_131 -> V_244 )
V_131 -> V_244 = F_83 ;
if ( V_2 -> V_37 >= V_131 -> V_120 ) {
if ( ! V_131 -> V_361 ) {
F_103 ( L_44 ) ;
F_14 () ;
}
break;
}
F_103 ( L_45
L_46 ,
V_131 -> V_120 , V_2 -> V_37 ) ;
V_131 -> V_58 = V_374 ;
case V_374 :
V_131 -> V_148 = V_375 ;
V_131 -> V_151 = V_376 ;
V_131 -> V_198 = F_65 ;
V_131 -> V_197 = F_67 ;
V_131 -> V_231 = F_88 ;
V_131 -> V_147 = F_63 ;
V_131 -> V_217 = F_86 ;
V_131 -> V_214 = F_80 ;
V_131 -> V_244 = F_82 ;
if ( ! V_131 -> V_120 )
V_131 -> V_120 = 256 ;
V_131 -> V_133 = 3 ;
V_131 -> V_361 = 1 ;
break;
case V_366 :
if ( ! F_153 () ) {
F_103 ( L_47 ) ;
F_14 () ;
}
V_131 -> V_148 = V_377 ;
V_131 -> V_151 = V_378 ;
V_131 -> V_198 = F_65 ;
V_131 -> V_197 = F_67 ;
V_131 -> V_231 = F_88 ;
V_131 -> V_147 = F_63 ;
V_131 -> V_217 = F_86 ;
V_131 -> V_214 = F_80 ;
V_131 -> V_244 = F_82 ;
if ( ! V_131 -> V_120 && ( V_2 -> V_129 >= 64 ) ) {
V_131 -> V_120 = 512 ;
V_131 -> V_133 = 7 ;
}
V_131 -> V_7 = F_154 ( V_2 , V_131 -> V_120 , V_131 -> V_133 ,
& V_131 -> V_145 ) ;
if ( ! V_131 -> V_7 ) {
F_103 ( L_48 ) ;
F_14 () ;
}
V_131 -> V_361 = V_131 -> V_133 * 8 / F_128 ( 8 * V_131 -> V_120 ) ;
break;
case V_379 :
F_103 ( L_49
L_50 ) ;
V_131 -> V_198 = F_63 ;
V_131 -> V_231 = F_86 ;
V_131 -> V_214 = F_80 ;
V_131 -> V_147 = F_63 ;
V_131 -> V_217 = F_86 ;
V_131 -> V_244 = F_82 ;
V_131 -> V_120 = V_2 -> V_37 ;
V_131 -> V_133 = 0 ;
V_131 -> V_361 = 0 ;
break;
default:
F_103 ( L_51 , V_131 -> V_58 ) ;
F_14 () ;
}
if ( ! V_131 -> V_213 )
V_131 -> V_213 = V_131 -> V_214 ;
if ( ! V_131 -> V_243 )
V_131 -> V_243 = V_131 -> V_244 ;
V_131 -> V_145 -> V_189 = 0 ;
for ( V_32 = 0 ; V_131 -> V_145 -> V_174 [ V_32 ] . V_177
&& V_32 < F_155 ( V_131 -> V_145 -> V_174 ) ; V_32 ++ )
V_131 -> V_145 -> V_189 += V_131 -> V_145 -> V_174 [ V_32 ] . V_177 ;
V_2 -> V_189 = V_131 -> V_145 -> V_189 ;
if ( ! F_149 ( V_2 ) )
F_103 ( L_52 ,
V_2 -> V_304 ) ;
V_131 -> V_135 = V_2 -> V_37 / V_131 -> V_120 ;
if ( V_131 -> V_135 * V_131 -> V_120 != V_2 -> V_37 ) {
F_103 ( L_53 ) ;
F_14 () ;
}
V_131 -> V_149 = V_131 -> V_135 * V_131 -> V_133 ;
if ( ! ( V_6 -> V_43 & V_229 ) && F_136 ( V_6 ) ) {
switch ( V_131 -> V_135 ) {
case 2 :
V_2 -> V_380 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_380 = 2 ;
break;
}
}
V_6 -> V_381 = V_2 -> V_37 >> V_2 -> V_380 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_194 = - 1 ;
switch ( V_131 -> V_58 ) {
case V_374 :
case V_366 :
if ( V_6 -> V_38 > 9 )
V_6 -> V_43 |= V_382 ;
break;
default:
break;
}
V_2 -> type = F_136 ( V_6 ) ? V_383 : V_384 ;
V_2 -> V_385 = ( V_6 -> V_43 & V_386 ) ? V_387 :
V_388 ;
V_2 -> V_389 = F_102 ;
V_2 -> V_390 = NULL ;
V_2 -> V_391 = NULL ;
V_2 -> V_392 = F_79 ;
V_2 -> V_393 = F_99 ;
V_2 -> V_394 = F_98 ;
V_2 -> V_395 = F_85 ;
V_2 -> V_396 = F_100 ;
V_2 -> V_397 = F_105 ;
V_2 -> V_398 = NULL ;
V_2 -> V_399 = NULL ;
V_2 -> V_400 = F_111 ;
V_2 -> V_401 = F_112 ;
V_2 -> V_402 = F_106 ;
V_2 -> V_403 = F_107 ;
V_2 -> V_404 = V_2 -> V_37 ;
V_2 -> V_405 = V_131 -> V_145 ;
V_2 -> V_406 = V_131 -> V_361 ;
V_2 -> V_407 = V_131 -> V_120 ;
if ( ! V_2 -> V_408 )
V_2 -> V_408 = V_2 -> V_406 ;
if ( V_6 -> V_43 & V_409 )
return 0 ;
return V_6 -> V_265 ( V_2 ) ;
}
int F_156 ( struct V_1 * V_2 , int V_352 )
{
int V_8 ;
if ( ! V_2 -> V_410 && F_157 () ) {
F_158 ( L_54 , V_10 ) ;
F_14 () ;
}
V_8 = F_146 ( V_2 , V_352 , NULL ) ;
if ( ! V_8 )
V_8 = F_150 ( V_2 ) ;
return V_8 ;
}
void F_159 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_131 . V_58 == V_366 )
F_160 ( (struct V_411 * ) V_6 -> V_131 . V_7 ) ;
F_161 ( V_2 ) ;
F_122 ( V_6 -> V_66 ) ;
if ( ! ( V_6 -> V_43 & V_365 ) )
F_122 ( V_6 -> V_140 ) ;
if ( V_6 -> V_412 && V_6 -> V_412 -> V_43
& V_413 )
F_122 ( V_6 -> V_412 ) ;
}
static int T_12 F_162 ( void )
{
F_163 ( L_55 , & V_78 ) ;
return 0 ;
}
static void T_13 F_164 ( void )
{
F_165 ( V_78 ) ;
}
