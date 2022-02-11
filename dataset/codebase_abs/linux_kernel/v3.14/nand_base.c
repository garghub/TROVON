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
if ( V_6 -> V_43 & V_44 )
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
F_46 ( V_6 -> V_97 ) ;
V_6 -> V_20 ( V_2 , V_70 ,
V_85 | V_22 ) ;
V_6 -> V_20 ( V_2 ,
V_21 , V_92 | V_22 ) ;
while ( ! ( V_6 -> V_49 ( V_2 ) & V_98 ) )
;
return;
default:
if ( ! V_6 -> V_75 ) {
F_46 ( V_6 -> V_97 ) ;
return;
}
}
F_47 ( 100 ) ;
F_40 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 , unsigned int V_81 ,
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
if ( V_6 -> V_43 & V_44 )
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
F_46 ( V_6 -> V_97 ) ;
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
F_46 ( V_6 -> V_97 ) ;
return;
}
}
F_47 ( 100 ) ;
F_40 ( V_2 ) ;
}
static void F_49 ( struct V_5 * V_6 ,
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
F_50 ( V_107 , V_108 ) ;
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
F_51 ( V_111 ) ;
F_52 ( V_17 , & V_107 ) ;
F_6 ( V_13 ) ;
F_53 () ;
F_54 ( V_17 , & V_107 ) ;
goto V_109;
}
static void F_55 ( struct V_1 * V_2 , struct V_5 * V_6 ,
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
static int F_56 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_112 , V_15 = V_6 -> V_15 ;
unsigned long V_74 = ( V_15 == V_113 ? 400 : 20 ) ;
F_43 ( V_78 , V_79 ) ;
F_47 ( 100 ) ;
V_6 -> V_45 ( V_2 , V_70 , - 1 , - 1 ) ;
if ( F_42 () || V_77 )
F_55 ( V_2 , V_6 , V_74 ) ;
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
F_57 () ;
}
}
F_43 ( V_78 , V_80 ) ;
V_112 = ( int ) V_6 -> V_49 ( V_2 ) ;
F_58 ( ! ( V_112 & V_98 ) ) ;
return V_112 ;
}
static int F_59 ( struct V_1 * V_2 , T_1 V_3 ,
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
int F_60 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
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
V_8 = F_59 ( V_2 , V_3 , V_4 , 0 ) ;
V_122:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
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
V_8 = F_59 ( V_2 , V_3 , V_4 , 0x1 ) ;
V_122:
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_62 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_3 * V_26 , int V_126 , int V_30 )
{
V_6 -> V_127 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_126 )
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
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
static int F_64 ( struct V_1 * V_2 , struct V_5 * V_6 ,
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
V_146 = F_65 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_154 , T_8 V_155 , T_3 * V_156 )
{
int V_157 , V_158 , V_159 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
T_3 * V_28 ;
int V_160 , V_32 , V_161 = 0 ;
int V_162 , V_163 , V_164 , V_165 ;
int V_166 = ( V_6 -> V_43 & V_44 ) ? 2 : 1 ;
int V_167 = 0 ;
unsigned int V_146 = 0 ;
V_157 = V_154 / V_6 -> V_131 . V_120 ;
V_158 = ( V_154 + V_155 - 1 ) / V_6 -> V_131 . V_120 ;
V_159 = V_158 - V_157 + 1 ;
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
if ( V_144 [ V_32 + V_157 * V_6 -> V_131 . V_133 ] + 1 !=
V_144 [ V_32 + V_157 * V_6 -> V_131 . V_133 + 1 ] ) {
V_161 = 1 ;
break;
}
}
if ( V_161 ) {
V_6 -> V_45 ( V_2 , V_103 , V_2 -> V_37 , - 1 ) ;
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
} else {
V_167 = V_157 * V_6 -> V_131 . V_133 ;
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
V_146 = F_65 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_5 * V_6 ,
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
V_146 = F_65 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_68 ( struct V_1 * V_2 ,
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
V_146 = F_65 (unsigned int, max_bitflips, stat) ;
}
}
return V_146 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_5 * V_6 ,
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
V_146 = F_65 (unsigned int, max_bitflips, stat) ;
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
static T_3 * F_70 ( struct V_5 * V_6 , T_3 * V_134 ,
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
if ( F_71 ( V_176 ) ) {
if ( V_176 >= free -> V_177 ) {
V_176 -= free -> V_177 ;
continue;
}
V_175 = free -> V_178 + V_176 ;
V_133 = F_72 ( T_9 , V_4 ,
( free -> V_177 - V_176 ) ) ;
V_176 = 0 ;
} else {
V_133 = F_72 ( T_9 , V_4 , free -> V_177 ) ;
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
static int F_73 ( struct V_1 * V_2 , int V_179 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_6 , V_179 ) ;
if ( V_179 >= V_6 -> V_180 )
return - V_11 ;
if ( ! V_6 -> V_181 )
return - V_182 ;
return V_6 -> V_181 ( V_2 , V_179 ) ;
}
static int F_74 ( struct V_1 * V_2 , T_1 V_183 ,
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
unsigned int V_146 = 0 ;
int V_179 = 0 ;
bool V_190 = false ;
V_19 = ( int ) ( V_183 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_184 = ( int ) ( V_183 >> V_6 -> V_38 ) ;
V_30 = V_184 & V_6 -> V_39 ;
V_185 = ( int ) ( V_183 & ( V_2 -> V_37 - 1 ) ) ;
V_26 = V_53 -> V_54 ;
V_134 = V_53 -> V_55 ;
V_126 = V_134 ? 1 : 0 ;
while ( 1 ) {
unsigned int V_191 = V_2 -> V_67 . V_152 ;
V_133 = F_75 ( V_2 -> V_37 - V_185 , V_155 ) ;
V_186 = ( V_133 == V_2 -> V_37 ) ;
if ( V_184 != V_6 -> V_192 || V_134 ) {
V_156 = V_186 ? V_26 : V_6 -> V_140 -> V_193 ;
V_194:
V_6 -> V_45 ( V_2 , V_88 , 0x00 , V_30 ) ;
if ( F_71 ( V_53 -> V_58 == V_171 ) )
V_8 = V_6 -> V_131 . V_147 ( V_2 , V_6 , V_156 ,
V_126 ,
V_30 ) ;
else if ( ! V_186 && F_76 ( V_6 ) &&
! V_134 )
V_8 = V_6 -> V_131 . V_195 ( V_2 , V_6 ,
V_185 , V_133 , V_156 ) ;
else
V_8 = V_6 -> V_131 . V_196 ( V_2 , V_6 , V_156 ,
V_126 , V_30 ) ;
if ( V_8 < 0 ) {
if ( ! V_186 )
V_6 -> V_192 = - 1 ;
break;
}
V_146 = F_65 (unsigned int, max_bitflips, ret) ;
if ( ! V_186 ) {
if ( ! F_76 ( V_6 ) && ! V_134 &&
! ( V_2 -> V_67 . V_152 - V_191 ) &&
( V_53 -> V_58 != V_171 ) ) {
V_6 -> V_192 = V_184 ;
V_6 -> V_197 = V_8 ;
} else {
V_6 -> V_192 = - 1 ;
}
memcpy ( V_26 , V_6 -> V_140 -> V_193 + V_185 , V_133 ) ;
}
if ( F_71 ( V_134 ) ) {
int V_198 = F_75 ( V_187 , V_188 ) ;
if ( V_198 ) {
V_134 = F_70 ( V_6 ,
V_134 , V_53 , V_198 ) ;
V_187 -= V_198 ;
}
}
if ( V_6 -> V_43 & V_199 ) {
if ( ! V_6 -> V_75 )
F_46 ( V_6 -> V_97 ) ;
else
F_40 ( V_2 ) ;
}
if ( V_2 -> V_67 . V_152 - V_191 ) {
if ( V_179 + 1 < V_6 -> V_180 ) {
V_179 ++ ;
V_8 = F_73 ( V_2 ,
V_179 ) ;
if ( V_8 < 0 )
break;
V_2 -> V_67 . V_152 = V_191 ;
goto V_194;
} else {
V_190 = true ;
}
}
V_26 += V_133 ;
} else {
memcpy ( V_26 , V_6 -> V_140 -> V_193 + V_185 , V_133 ) ;
V_26 += V_133 ;
V_146 = F_65 (unsigned int, max_bitflips,
chip->pagebuf_bitflips) ;
}
V_155 -= V_133 ;
if ( V_179 ) {
V_8 = F_73 ( V_2 , 0 ) ;
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
V_53 -> V_200 = V_53 -> V_4 - ( T_9 ) V_155 ;
if ( V_134 )
V_53 -> V_201 = V_53 -> V_57 - V_187 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_190 )
return - V_202 ;
return V_146 ;
}
static int F_77 ( struct V_1 * V_2 , T_1 V_183 , T_9 V_4 ,
T_9 * V_200 , T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_41 ) ;
V_53 . V_4 = V_4 ;
V_53 . V_54 = V_26 ;
V_53 . V_55 = NULL ;
V_53 . V_58 = V_59 ;
V_8 = F_74 ( V_2 , V_183 , & V_53 ) ;
* V_200 = V_53 . V_200 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_78 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
V_6 -> V_45 ( V_2 , V_46 , 0 , V_30 ) ;
V_6 -> V_127 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_30 )
{
T_3 * V_26 = V_6 -> V_128 ;
int V_177 = V_2 -> V_129 ;
int V_203 = V_6 -> V_131 . V_133 + V_6 -> V_131 . V_136 + V_6 -> V_131 . V_137 ;
int V_130 = V_6 -> V_131 . V_120 ;
T_3 * V_156 = V_26 ;
int V_32 , V_198 , V_204 = 0 , V_205 ;
V_6 -> V_45 ( V_2 , V_88 , V_6 -> V_131 . V_120 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_135 ; V_32 ++ ) {
if ( V_204 ) {
V_205 = V_130 + V_32 * ( V_130 + V_203 ) ;
if ( V_2 -> V_37 > 512 )
V_6 -> V_45 ( V_2 , V_103 , V_205 , - 1 ) ;
else
V_6 -> V_45 ( V_2 , V_88 , V_205 , V_30 ) ;
} else
V_204 = 1 ;
V_198 = F_72 ( int , V_177 , V_203 ) ;
V_6 -> V_127 ( V_2 , V_156 , V_198 ) ;
V_156 += V_198 ;
V_177 -= V_198 ;
}
if ( V_177 > 0 )
V_6 -> V_127 ( V_2 , V_156 , V_177 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_5 * V_6 ,
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
static int F_81 ( struct V_1 * V_2 ,
struct V_5 * V_6 , int V_30 )
{
int V_203 = V_6 -> V_131 . V_133 + V_6 -> V_131 . V_136 + V_6 -> V_131 . V_137 ;
int V_130 = V_6 -> V_131 . V_120 , V_177 = V_2 -> V_129 ;
int V_32 , V_4 , V_205 , V_112 = 0 , V_206 = 0 , V_135 = V_6 -> V_131 . V_135 ;
const T_3 * V_156 = V_6 -> V_128 ;
if ( ! V_6 -> V_131 . V_136 && ! V_6 -> V_131 . V_137 ) {
V_205 = V_135 * ( V_130 + V_203 ) ;
V_135 = 0 ;
} else
V_205 = V_130 ;
V_6 -> V_45 ( V_2 , V_86 , V_205 , V_30 ) ;
for ( V_32 = 0 ; V_32 < V_135 ; V_32 ++ ) {
if ( V_206 ) {
if ( V_2 -> V_37 <= 512 ) {
T_8 V_207 = 0xFFFFFFFF ;
V_4 = V_130 ;
while ( V_4 > 0 ) {
int V_208 = F_72 ( int , V_4 , 4 ) ;
V_6 -> V_24 ( V_2 , ( T_3 * ) & V_207 ,
V_208 ) ;
V_4 -= V_208 ;
}
} else {
V_205 = V_130 + V_32 * ( V_130 + V_203 ) ;
V_6 -> V_45 ( V_2 , V_102 , V_205 , - 1 ) ;
}
} else
V_206 = 1 ;
V_4 = F_72 ( int , V_177 , V_203 ) ;
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
static int F_82 ( struct V_1 * V_2 , T_1 V_183 ,
struct V_52 * V_53 )
{
int V_30 , V_184 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_209 V_210 ;
int V_155 = V_53 -> V_57 ;
int V_4 ;
T_3 * V_26 = V_53 -> V_55 ;
int V_8 = 0 ;
F_2 ( L_7 ,
V_10 , ( unsigned long long ) V_183 , V_155 ) ;
V_210 = V_2 -> V_67 ;
if ( V_53 -> V_58 == V_172 )
V_4 = V_6 -> V_131 . V_145 -> V_189 ;
else
V_4 = V_2 -> V_129 ;
if ( F_71 ( V_53 -> V_56 >= V_4 ) ) {
F_2 ( L_8 ,
V_10 ) ;
return - V_11 ;
}
if ( F_71 ( V_183 >= V_2 -> V_120 ||
V_53 -> V_56 + V_155 > ( ( V_2 -> V_120 >> V_6 -> V_38 ) -
( V_183 >> V_6 -> V_38 ) ) * V_4 ) ) {
F_2 ( L_9 ,
V_10 ) ;
return - V_11 ;
}
V_19 = ( int ) ( V_183 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_184 = ( int ) ( V_183 >> V_6 -> V_38 ) ;
V_30 = V_184 & V_6 -> V_39 ;
while ( 1 ) {
if ( V_53 -> V_58 == V_171 )
V_8 = V_6 -> V_131 . V_211 ( V_2 , V_6 , V_30 ) ;
else
V_8 = V_6 -> V_131 . V_212 ( V_2 , V_6 , V_30 ) ;
if ( V_8 < 0 )
break;
V_4 = F_75 ( V_4 , V_155 ) ;
V_26 = F_70 ( V_6 , V_26 , V_53 , V_4 ) ;
if ( V_6 -> V_43 & V_199 ) {
if ( ! V_6 -> V_75 )
F_46 ( V_6 -> V_97 ) ;
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
V_53 -> V_201 = V_53 -> V_57 - V_155 ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_67 . V_152 - V_210 . V_152 )
return - V_202 ;
return V_2 -> V_67 . V_153 - V_210 . V_153 ? - V_213 : 0 ;
}
static int F_83 ( struct V_1 * V_2 , T_1 V_183 ,
struct V_52 * V_53 )
{
int V_8 = - V_214 ;
V_53 -> V_200 = 0 ;
if ( V_53 -> V_54 && ( V_183 + V_53 -> V_4 ) > V_2 -> V_120 ) {
F_2 ( L_9 ,
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
V_8 = F_82 ( V_2 , V_183 , V_53 ) ;
else
V_8 = F_74 ( V_2 , V_183 , V_53 ) ;
V_122:
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
V_6 -> V_24 ( V_2 , V_26 , V_2 -> V_37 ) ;
if ( V_126 )
V_6 -> V_24 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
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
V_6 -> V_127 ( V_2 , V_134 , V_132 ) ;
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
static int F_86 ( struct V_1 * V_2 , struct V_5 * V_6 ,
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
return V_6 -> V_131 . V_215 ( V_2 , V_6 , V_26 , 1 ) ;
}
static int F_87 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
const T_3 * V_28 = V_26 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
V_6 -> V_131 . V_168 ( V_2 , V_216 ) ;
V_6 -> V_24 ( V_2 , V_28 , V_130 ) ;
V_6 -> V_131 . V_148 ( V_2 , V_28 , & V_139 [ V_32 ] ) ;
}
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_6 -> V_128 [ V_144 [ V_32 ] ] = V_139 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_8 V_178 ,
T_8 V_217 , const T_3 * V_26 ,
int V_126 )
{
T_3 * V_218 = V_6 -> V_128 ;
T_3 * V_139 = V_6 -> V_140 -> V_141 ;
int V_219 = V_6 -> V_131 . V_120 ;
int V_220 = V_6 -> V_131 . V_133 ;
int V_221 = V_6 -> V_131 . V_135 ;
T_8 * V_144 = V_6 -> V_131 . V_145 -> V_144 ;
T_8 V_157 = V_178 / V_219 ;
T_8 V_158 = ( V_178 + V_217 - 1 ) / V_219 ;
int V_222 = V_2 -> V_129 / V_221 ;
int V_223 , V_32 ;
for ( V_223 = 0 ; V_223 < V_221 ; V_223 ++ ) {
V_6 -> V_131 . V_168 ( V_2 , V_216 ) ;
V_6 -> V_24 ( V_2 , V_26 , V_219 ) ;
if ( ( V_223 < V_157 ) || ( V_223 > V_158 ) )
memset ( V_139 , 0xff , V_220 ) ;
else
V_6 -> V_131 . V_148 ( V_2 , V_26 , V_139 ) ;
if ( ! V_126 || ( V_223 < V_157 ) || ( V_223 > V_158 ) )
memset ( V_218 , 0xff , V_222 ) ;
V_26 += V_219 ;
V_139 += V_220 ;
V_218 += V_222 ;
}
V_139 = V_6 -> V_140 -> V_141 ;
for ( V_32 = 0 ; V_32 < V_6 -> V_131 . V_149 ; V_32 ++ )
V_6 -> V_128 [ V_144 [ V_32 ] ] = V_139 [ V_32 ] ;
V_6 -> V_24 ( V_2 , V_6 -> V_128 , V_2 -> V_129 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
const T_3 * V_26 , int V_126 )
{
int V_32 , V_130 = V_6 -> V_131 . V_120 ;
int V_132 = V_6 -> V_131 . V_133 ;
int V_138 = V_6 -> V_131 . V_135 ;
const T_3 * V_28 = V_26 ;
T_3 * V_134 = V_6 -> V_128 ;
for ( V_32 = 0 ; V_138 ; V_138 -- , V_32 += V_132 , V_28 += V_130 ) {
V_6 -> V_131 . V_168 ( V_2 , V_216 ) ;
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
static int F_90 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_8 V_178 , int V_217 , const T_3 * V_26 ,
int V_126 , int V_30 , int V_224 , int V_225 )
{
int V_112 , V_226 ;
if ( ! ( V_6 -> V_43 & V_227 ) &&
V_6 -> V_131 . V_228 )
V_226 = V_178 || ( V_217 < V_2 -> V_37 ) ;
else
V_226 = 0 ;
V_6 -> V_45 ( V_2 , V_86 , 0x00 , V_30 ) ;
if ( F_71 ( V_225 ) )
V_112 = V_6 -> V_131 . V_215 ( V_2 , V_6 , V_26 ,
V_126 ) ;
else if ( V_226 )
V_112 = V_6 -> V_131 . V_228 ( V_2 , V_6 , V_178 , V_217 ,
V_26 , V_126 ) ;
else
V_112 = V_6 -> V_131 . V_229 ( V_2 , V_6 , V_26 , V_126 ) ;
if ( V_112 < 0 )
return V_112 ;
V_224 = 0 ;
if ( ! V_224 || ! F_91 ( V_6 ) ) {
V_6 -> V_45 ( V_2 , V_93 , - 1 , - 1 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
if ( ( V_112 & V_118 ) && ( V_6 -> V_230 ) )
V_112 = V_6 -> V_230 ( V_2 , V_6 , V_64 , V_112 ,
V_30 ) ;
if ( V_112 & V_118 )
return - V_119 ;
} else {
V_6 -> V_45 ( V_2 , V_101 , - 1 , - 1 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
}
return 0 ;
}
static T_3 * F_92 ( struct V_1 * V_2 , T_3 * V_134 , T_9 V_4 ,
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
T_8 V_175 = 0 , V_231 = V_53 -> V_56 ;
T_9 V_133 = 0 ;
for (; free -> V_177 && V_4 ; free ++ , V_4 -= V_133 ) {
if ( F_71 ( V_231 ) ) {
if ( V_231 >= free -> V_177 ) {
V_231 -= free -> V_177 ;
continue;
}
V_175 = free -> V_178 + V_231 ;
V_133 = F_72 ( T_9 , V_4 ,
( free -> V_177 - V_231 ) ) ;
V_231 = 0 ;
} else {
V_133 = F_72 ( T_9 , V_4 , free -> V_177 ) ;
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
static int F_93 ( struct V_1 * V_2 , T_1 V_232 ,
struct V_52 * V_53 )
{
int V_19 , V_184 , V_30 , V_233 , V_82 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_8 V_234 = V_53 -> V_4 ;
T_8 V_235 = V_53 -> V_57 ;
T_8 V_236 = V_53 -> V_58 == V_172 ?
V_2 -> V_189 : V_2 -> V_129 ;
T_3 * V_134 = V_53 -> V_55 ;
T_3 * V_26 = V_53 -> V_54 ;
int V_8 ;
int V_126 = V_134 ? 1 : 0 ;
V_53 -> V_200 = 0 ;
if ( ! V_234 )
return 0 ;
if ( F_94 ( V_232 ) || F_94 ( V_53 -> V_4 ) ) {
F_95 ( L_10 ,
V_10 ) ;
return - V_11 ;
}
V_82 = V_232 & ( V_2 -> V_37 - 1 ) ;
V_19 = ( int ) ( V_232 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
V_8 = - V_119 ;
goto V_237;
}
V_184 = ( int ) ( V_232 >> V_6 -> V_38 ) ;
V_30 = V_184 & V_6 -> V_39 ;
V_233 = ( 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ) - 1 ;
if ( V_232 <= ( V_6 -> V_192 << V_6 -> V_38 ) &&
( V_6 -> V_192 << V_6 -> V_38 ) < ( V_232 + V_53 -> V_4 ) )
V_6 -> V_192 = - 1 ;
if ( V_134 && V_53 -> V_56 && ( V_53 -> V_56 + V_53 -> V_57 > V_236 ) ) {
V_8 = - V_11 ;
goto V_237;
}
while ( 1 ) {
int V_133 = V_2 -> V_37 ;
int V_224 = V_234 > V_133 && V_30 != V_233 ;
T_3 * V_238 = V_26 ;
if ( F_71 ( V_82 || V_234 < ( V_2 -> V_37 - 1 ) ) ) {
V_224 = 0 ;
V_133 = F_72 ( int , V_133 - V_82 , ( int ) V_234 ) ;
V_6 -> V_192 = - 1 ;
memset ( V_6 -> V_140 -> V_193 , 0xff , V_2 -> V_37 ) ;
memcpy ( & V_6 -> V_140 -> V_193 [ V_82 ] , V_26 , V_133 ) ;
V_238 = V_6 -> V_140 -> V_193 ;
}
if ( F_71 ( V_134 ) ) {
T_9 V_4 = F_75 ( V_235 , V_236 ) ;
V_134 = F_92 ( V_2 , V_134 , V_4 , V_53 ) ;
V_235 -= V_4 ;
} else {
memset ( V_6 -> V_128 , 0xff , V_2 -> V_129 ) ;
}
V_8 = V_6 -> V_229 ( V_2 , V_6 , V_82 , V_133 , V_238 ,
V_126 , V_30 , V_224 ,
( V_53 -> V_58 == V_171 ) ) ;
if ( V_8 )
break;
V_234 -= V_133 ;
if ( ! V_234 )
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
V_53 -> V_200 = V_53 -> V_4 - V_234 ;
if ( F_71 ( V_134 ) )
V_53 -> V_201 = V_53 -> V_57 ;
V_237:
V_6 -> V_42 ( V_2 , - 1 ) ;
return V_8 ;
}
static int F_96 ( struct V_1 * V_2 , T_1 V_232 , T_9 V_4 ,
T_9 * V_200 , const T_3 * V_26 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_52 V_53 ;
int V_8 ;
F_55 ( V_2 , V_6 , 400 ) ;
F_49 ( V_6 , V_2 , V_64 ) ;
V_53 . V_4 = V_4 ;
V_53 . V_54 = ( T_3 * ) V_26 ;
V_53 . V_55 = NULL ;
V_53 . V_58 = V_59 ;
V_8 = F_93 ( V_2 , V_232 , & V_53 ) ;
* V_200 = V_53 . V_200 ;
return V_8 ;
}
static int F_97 ( struct V_1 * V_2 , T_1 V_232 , T_9 V_4 ,
T_9 * V_200 , const T_3 * V_26 )
{
struct V_52 V_53 ;
int V_8 ;
F_26 ( V_2 , V_64 ) ;
V_53 . V_4 = V_4 ;
V_53 . V_54 = ( T_3 * ) V_26 ;
V_53 . V_55 = NULL ;
V_53 . V_58 = V_59 ;
V_8 = F_93 ( V_2 , V_232 , & V_53 ) ;
* V_200 = V_53 . V_200 ;
F_3 ( V_2 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_232 ,
struct V_52 * V_53 )
{
int V_19 , V_30 , V_112 , V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_11 ,
V_10 , ( unsigned int ) V_232 , ( int ) V_53 -> V_57 ) ;
if ( V_53 -> V_58 == V_172 )
V_4 = V_6 -> V_131 . V_145 -> V_189 ;
else
V_4 = V_2 -> V_129 ;
if ( ( V_53 -> V_56 + V_53 -> V_57 ) > V_4 ) {
F_2 ( L_12 ,
V_10 ) ;
return - V_11 ;
}
if ( F_71 ( V_53 -> V_56 >= V_4 ) ) {
F_2 ( L_13 ,
V_10 ) ;
return - V_11 ;
}
if ( F_71 ( V_232 >= V_2 -> V_120 ||
V_53 -> V_56 + V_53 -> V_57 >
( ( V_2 -> V_120 >> V_6 -> V_38 ) -
( V_232 >> V_6 -> V_38 ) ) * V_4 ) ) {
F_2 ( L_14 ,
V_10 ) ;
return - V_11 ;
}
V_19 = ( int ) ( V_232 >> V_6 -> V_40 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
V_30 = ( int ) ( V_232 >> V_6 -> V_38 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
if ( F_34 ( V_2 ) ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
return - V_239 ;
}
if ( V_30 == V_6 -> V_192 )
V_6 -> V_192 = - 1 ;
F_92 ( V_2 , V_53 -> V_55 , V_53 -> V_57 , V_53 ) ;
if ( V_53 -> V_58 == V_171 )
V_112 = V_6 -> V_131 . V_240 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
else
V_112 = V_6 -> V_131 . V_241 ( V_2 , V_6 , V_30 & V_6 -> V_39 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
if ( V_112 )
return V_112 ;
V_53 -> V_201 = V_53 -> V_57 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , T_1 V_232 ,
struct V_52 * V_53 )
{
int V_8 = - V_214 ;
V_53 -> V_200 = 0 ;
if ( V_53 -> V_54 && ( V_232 + V_53 -> V_4 ) > V_2 -> V_120 ) {
F_2 ( L_14 ,
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
V_8 = F_30 ( V_2 , V_232 , V_53 ) ;
else
V_8 = F_93 ( V_2 , V_232 , V_53 ) ;
V_122:
F_3 ( V_2 ) ;
return V_8 ;
}
static void F_99 ( struct V_1 * V_2 , int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_45 ( V_2 , V_94 , - 1 , V_30 ) ;
V_6 -> V_45 ( V_2 , V_95 , - 1 , - 1 ) ;
}
static int F_100 ( struct V_1 * V_2 , struct V_61 * V_242 )
{
return F_32 ( V_2 , V_242 , 0 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_61 * V_242 ,
int V_72 )
{
int V_30 , V_112 , V_243 , V_8 , V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 ;
F_2 ( L_4 ,
V_10 , ( unsigned long long ) V_242 -> V_63 ,
( unsigned long long ) V_242 -> V_4 ) ;
if ( F_1 ( V_2 , V_242 -> V_63 , V_242 -> V_4 ) )
return - V_11 ;
F_26 ( V_2 , V_113 ) ;
V_30 = ( int ) ( V_242 -> V_63 >> V_6 -> V_38 ) ;
V_19 = ( int ) ( V_242 -> V_63 >> V_6 -> V_40 ) ;
V_243 = 1 << ( V_6 -> V_9 - V_6 -> V_38 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
if ( F_34 ( V_2 ) ) {
F_2 ( L_5 ,
V_10 ) ;
V_242 -> V_15 = V_124 ;
goto V_244;
}
V_4 = V_242 -> V_4 ;
V_242 -> V_15 = V_245 ;
while ( V_4 ) {
if ( F_35 ( V_2 , ( ( T_1 ) V_30 ) <<
V_6 -> V_38 , 0 , V_72 ) ) {
F_101 ( L_15 ,
V_10 , V_30 ) ;
V_242 -> V_15 = V_124 ;
goto V_244;
}
if ( V_30 <= V_6 -> V_192 && V_6 -> V_192 <
( V_30 + V_243 ) )
V_6 -> V_192 = - 1 ;
V_6 -> V_246 ( V_2 , V_30 & V_6 -> V_39 ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
if ( ( V_112 & V_118 ) && ( V_6 -> V_230 ) )
V_112 = V_6 -> V_230 ( V_2 , V_6 , V_113 ,
V_112 , V_30 ) ;
if ( V_112 & V_118 ) {
F_2 ( L_16 ,
V_10 , V_30 ) ;
V_242 -> V_15 = V_124 ;
V_242 -> V_247 =
( ( T_1 ) V_30 << V_6 -> V_38 ) ;
goto V_244;
}
V_4 -= ( 1ULL << V_6 -> V_9 ) ;
V_30 += V_243 ;
if ( V_4 && ! ( V_30 & V_6 -> V_39 ) ) {
V_19 ++ ;
V_6 -> V_42 ( V_2 , - 1 ) ;
V_6 -> V_42 ( V_2 , V_19 ) ;
}
}
V_242 -> V_15 = V_248 ;
V_244:
V_8 = V_242 -> V_15 == V_248 ? 0 : - V_119 ;
V_6 -> V_42 ( V_2 , - 1 ) ;
F_3 ( V_2 ) ;
if ( ! V_8 )
F_102 ( V_242 ) ;
return V_8 ;
}
static void F_103 ( struct V_1 * V_2 )
{
F_2 ( L_17 , V_10 ) ;
F_26 ( V_2 , V_249 ) ;
F_3 ( V_2 ) ;
}
static int F_104 ( struct V_1 * V_2 , T_1 V_250 )
{
return F_35 ( V_2 , V_250 , 1 , 0 ) ;
}
static int F_105 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_8 ;
V_8 = F_104 ( V_2 , V_3 ) ;
if ( V_8 ) {
if ( V_8 > 0 )
return 0 ;
return V_8 ;
}
return F_31 ( V_2 , V_3 ) ;
}
static int F_106 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_63 , T_3 * V_251 )
{
int V_112 ;
int V_32 ;
if ( ! V_6 -> V_252 ||
! ( F_107 ( V_6 -> V_253 . V_254 )
& V_255 ) )
return - V_11 ;
V_6 -> V_45 ( V_2 , V_256 , V_63 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_257 ; ++ V_32 )
V_6 -> V_258 ( V_2 , V_251 [ V_32 ] ) ;
V_112 = V_6 -> V_117 ( V_2 , V_6 ) ;
if ( V_112 & V_118 )
return - V_119 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_63 , T_3 * V_251 )
{
int V_32 ;
if ( ! V_6 -> V_252 ||
! ( F_107 ( V_6 -> V_253 . V_254 )
& V_255 ) )
return - V_11 ;
memset ( V_251 , 0 , V_257 ) ;
V_6 -> V_45 ( V_2 , V_259 , V_63 , - 1 ) ;
for ( V_32 = 0 ; V_32 < V_257 ; ++ V_32 )
* V_251 ++ = V_6 -> V_49 ( V_2 ) ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 )
{
return F_26 ( V_2 , V_110 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_15 == V_110 )
F_3 ( V_2 ) ;
else
F_111 ( L_18 ,
V_10 ) ;
}
static void F_112 ( struct V_5 * V_6 , int V_166 )
{
if ( ! V_6 -> V_97 )
V_6 -> V_97 = 20 ;
if ( V_6 -> V_45 == NULL )
V_6 -> V_45 = F_45 ;
if ( V_6 -> V_117 == NULL )
V_6 -> V_117 = F_56 ;
if ( ! V_6 -> V_42 )
V_6 -> V_42 = F_13 ;
if ( ! V_6 -> V_260 )
V_6 -> V_260 = F_106 ;
if ( ! V_6 -> V_261 )
V_6 -> V_261 = F_108 ;
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
if ( ! V_6 -> V_258 || V_6 -> V_258 == F_15 )
V_6 -> V_258 = V_166 ? F_16 : F_15 ;
if ( ! V_6 -> V_127 || V_6 -> V_127 == F_19 )
V_6 -> V_127 = V_166 ? F_23 : F_19 ;
if ( ! V_6 -> V_262 )
V_6 -> V_262 = V_263 ;
if ( ! V_6 -> V_12 ) {
V_6 -> V_12 = & V_6 -> V_264 ;
F_113 ( & V_6 -> V_12 -> V_13 ) ;
F_114 ( & V_6 -> V_12 -> V_17 ) ;
}
}
static void F_115 ( T_3 * V_265 , T_9 V_4 )
{
T_10 V_32 ;
V_265 [ V_4 - 1 ] = 0 ;
for ( V_32 = 0 ; V_32 < V_4 - 1 ; V_32 ++ ) {
if ( V_265 [ V_32 ] < ' ' || V_265 [ V_32 ] > 127 )
V_265 [ V_32 ] = '?' ;
}
F_116 ( V_265 ) ;
}
static T_4 F_117 ( T_4 V_266 , T_11 const * V_28 , T_9 V_4 )
{
int V_32 ;
while ( V_4 -- ) {
V_266 ^= * V_28 ++ << 8 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_266 = ( V_266 << 1 ) ^ ( ( V_266 & 0x8000 ) ? 0x8005 : 0 ) ;
}
return V_266 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_5 * V_6 , struct V_267 * V_28 )
{
struct V_268 * V_269 ;
struct V_270 * V_265 ;
struct V_271 * V_131 ;
T_3 * V_272 ;
int V_8 = - V_11 ;
int V_4 ;
int V_32 ;
V_4 = F_107 ( V_28 -> V_273 ) * 16 ;
V_269 = F_119 ( V_4 , V_274 ) ;
if ( ! V_269 )
return - V_275 ;
V_6 -> V_45 ( V_2 , V_276 , 0 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_103 ,
sizeof( * V_28 ) * V_28 -> V_277 , - 1 ) ;
V_6 -> V_127 ( V_2 , ( T_3 * ) V_269 , V_4 ) ;
if ( ( F_117 ( V_278 , ( ( T_3 * ) V_269 ) + 2 , V_4 - 2 )
!= F_107 ( V_269 -> V_266 ) ) ) {
F_2 ( L_19 ) ;
goto V_279;
}
if ( strncmp ( V_269 -> V_280 , L_20 , 4 ) ) {
F_2 ( L_21 ) ;
goto V_279;
}
V_272 = ( T_3 * ) ( V_269 + 1 ) ;
for ( V_32 = 0 ; V_32 < V_281 ; V_32 ++ ) {
V_265 = V_269 -> V_282 + V_32 ;
if ( V_265 -> type == V_283 )
break;
V_272 += V_265 -> V_177 * 16 ;
}
if ( V_32 == V_281 ) {
F_2 ( L_22 ) ;
goto V_279;
}
V_131 = (struct V_271 * ) V_272 ;
if ( ! V_131 -> V_284 ) {
F_2 ( L_23 ) ;
goto V_279;
}
V_6 -> V_285 = V_131 -> V_286 ;
V_6 -> V_287 = 1 << V_131 -> V_284 ;
V_8 = 0 ;
V_279:
F_120 ( V_269 ) ;
return V_8 ;
}
static int F_121 ( struct V_1 * V_2 , int V_179 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_3 V_288 [ V_257 ] = { V_179 } ;
return V_6 -> V_260 ( V_2 , V_6 , V_289 ,
V_288 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
struct V_267 * V_28 )
{
struct V_290 * V_291 = ( void * ) V_28 -> V_292 ;
if ( F_107 ( V_28 -> V_293 ) < 1 )
return;
V_6 -> V_180 = V_291 -> V_294 ;
V_6 -> V_181 = F_121 ;
}
static int F_123 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_166 )
{
struct V_267 * V_28 = & V_6 -> V_253 ;
int V_32 ;
int V_295 ;
V_6 -> V_45 ( V_2 , V_296 , 0x20 , - 1 ) ;
if ( V_6 -> V_49 ( V_2 ) != 'O' || V_6 -> V_49 ( V_2 ) != 'N' ||
V_6 -> V_49 ( V_2 ) != 'F' || V_6 -> V_49 ( V_2 ) != 'I' )
return 0 ;
if ( V_6 -> V_43 & V_44 ) {
F_111 ( L_24 ) ;
return 0 ;
}
V_6 -> V_45 ( V_2 , V_276 , 0 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
V_6 -> V_127 ( V_2 , ( T_3 * ) V_28 , sizeof( * V_28 ) ) ;
if ( F_117 ( V_278 , ( T_3 * ) V_28 , 254 ) ==
F_107 ( V_28 -> V_266 ) ) {
break;
}
}
if ( V_32 == 3 ) {
F_111 ( L_25 ) ;
return 0 ;
}
V_295 = F_107 ( V_28 -> V_297 ) ;
if ( V_295 & ( 1 << 5 ) )
V_6 -> V_252 = 23 ;
else if ( V_295 & ( 1 << 4 ) )
V_6 -> V_252 = 22 ;
else if ( V_295 & ( 1 << 3 ) )
V_6 -> V_252 = 21 ;
else if ( V_295 & ( 1 << 2 ) )
V_6 -> V_252 = 20 ;
else if ( V_295 & ( 1 << 1 ) )
V_6 -> V_252 = 10 ;
if ( ! V_6 -> V_252 ) {
F_124 ( L_26 , V_295 ) ;
return 0 ;
}
F_115 ( V_28 -> V_298 , sizeof( V_28 -> V_298 ) ) ;
F_115 ( V_28 -> V_299 , sizeof( V_28 -> V_299 ) ) ;
if ( ! V_2 -> V_300 )
V_2 -> V_300 = V_28 -> V_299 ;
V_2 -> V_37 = F_125 ( V_28 -> V_301 ) ;
V_2 -> V_36 = 1 << ( F_126 ( F_125 ( V_28 -> V_243 ) ) - 1 ) ;
V_2 -> V_36 *= V_2 -> V_37 ;
V_2 -> V_129 = F_107 ( V_28 -> V_302 ) ;
V_6 -> V_91 = 1 << ( F_126 ( F_125 ( V_28 -> V_303 ) ) - 1 ) ;
V_6 -> V_91 *= ( T_2 ) V_2 -> V_36 * V_28 -> V_304 ;
V_6 -> V_305 = V_28 -> V_305 ;
if ( F_127 ( V_6 ) & V_306 )
* V_166 = V_44 ;
else
* V_166 = 0 ;
if ( V_28 -> V_286 != 0xff ) {
V_6 -> V_285 = V_28 -> V_286 ;
V_6 -> V_287 = 512 ;
} else if ( V_6 -> V_252 >= 21 &&
( F_127 ( V_6 ) & V_307 ) ) {
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_45 )
V_6 -> V_45 = F_48 ;
if ( F_118 ( V_2 , V_6 , V_28 ) )
F_101 ( L_27 ) ;
} else {
F_101 ( L_28 ) ;
}
if ( V_28 -> V_308 == V_309 )
F_122 ( V_6 , V_28 ) ;
return 1 ;
}
static int F_128 ( T_11 * V_310 , int V_311 , int V_312 )
{
int V_32 , V_313 ;
for ( V_32 = 0 ; V_32 < V_312 ; V_32 ++ )
for ( V_313 = V_32 + V_312 ; V_313 < V_311 ; V_313 += V_312 )
if ( V_310 [ V_32 ] != V_310 [ V_313 ] )
return 0 ;
return 1 ;
}
static int F_129 ( T_11 * V_310 , int V_311 )
{
int V_314 , V_312 ;
for ( V_314 = V_311 - 1 ; V_314 >= 0 ; V_314 -- )
if ( V_310 [ V_314 ] )
break;
if ( V_314 < 0 )
return 0 ;
for ( V_312 = 1 ; V_312 < V_311 ; V_312 ++ )
if ( F_128 ( V_310 , V_311 , V_312 ) )
break;
if ( V_312 < V_311 )
return V_312 ;
if ( V_314 < V_311 - 1 )
return V_314 + 1 ;
return V_311 ;
}
static int F_130 ( T_11 V_315 )
{
int V_316 ;
V_316 = V_315 & V_317 ;
V_316 >>= V_318 ;
return V_316 + 1 ;
}
static void F_131 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_11 V_310 [ 8 ] , int * V_166 )
{
int V_319 , V_320 ;
V_6 -> V_305 = F_130 ( V_310 [ 2 ] ) ;
V_319 = V_310 [ 3 ] ;
V_320 = F_129 ( V_310 , 8 ) ;
if ( V_320 == 6 && V_310 [ 0 ] == V_321 &&
! F_132 ( V_6 ) && V_310 [ 5 ] != 0x00 ) {
V_2 -> V_37 = 2048 << ( V_319 & 0x03 ) ;
V_319 >>= 2 ;
switch ( ( ( V_319 >> 2 ) & 0x04 ) | ( V_319 & 0x03 ) ) {
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
V_319 >>= 2 ;
V_2 -> V_36 = ( 128 * 1024 ) <<
( ( ( V_319 >> 1 ) & 0x04 ) | ( V_319 & 0x03 ) ) ;
* V_166 = 0 ;
} else if ( V_320 == 6 && V_310 [ 0 ] == V_322 &&
! F_132 ( V_6 ) ) {
unsigned int V_323 ;
V_2 -> V_37 = 2048 << ( V_319 & 0x03 ) ;
V_319 >>= 2 ;
switch ( ( ( V_319 >> 2 ) & 0x04 ) | ( V_319 & 0x03 ) ) {
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
V_319 >>= 2 ;
V_323 = ( ( V_319 >> 1 ) & 0x04 ) | ( V_319 & 0x03 ) ;
if ( V_323 < 0x03 )
V_2 -> V_36 = ( 128 * 1024 ) << V_323 ;
else if ( V_323 == 0x03 )
V_2 -> V_36 = 768 * 1024 ;
else
V_2 -> V_36 = ( 64 * 1024 ) << V_323 ;
* V_166 = 0 ;
} else {
V_2 -> V_37 = 1024 << ( V_319 & 0x03 ) ;
V_319 >>= 2 ;
V_2 -> V_129 = ( 8 << ( V_319 & 0x01 ) ) *
( V_2 -> V_37 >> 9 ) ;
V_319 >>= 2 ;
V_2 -> V_36 = ( 64 * 1024 ) << ( V_319 & 0x03 ) ;
V_319 >>= 2 ;
* V_166 = ( V_319 & 0x01 ) ? V_44 : 0 ;
if ( V_320 >= 6 && V_310 [ 0 ] == V_324 &&
F_132 ( V_6 ) &&
( V_310 [ 5 ] & 0x7 ) == 0x6 &&
! ( V_310 [ 4 ] & 0x80 ) ) {
V_2 -> V_129 = 32 * V_2 -> V_37 >> 9 ;
}
}
}
static void F_133 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_325 * type , T_11 V_310 [ 8 ] ,
int * V_166 )
{
int V_326 = V_310 [ 0 ] ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_37 = type -> V_327 ;
V_2 -> V_129 = V_2 -> V_37 / 32 ;
* V_166 = type -> V_43 & V_44 ;
V_6 -> V_305 = 1 ;
if ( V_326 == V_328 && V_310 [ 4 ] != 0x00 && V_310 [ 5 ] == 0x00
&& V_310 [ 6 ] == 0x00 && V_310 [ 7 ] == 0x00
&& V_2 -> V_37 == 512 ) {
V_2 -> V_36 = 128 * 1024 ;
V_2 -> V_36 <<= ( ( V_310 [ 3 ] & 0x03 ) << 1 ) ;
}
}
static void F_134 ( struct V_1 * V_2 ,
struct V_5 * V_6 , T_11 V_310 [ 8 ] )
{
int V_326 = V_310 [ 0 ] ;
if ( V_2 -> V_37 > 512 || ( V_6 -> V_43 & V_44 ) )
V_6 -> V_47 = V_329 ;
else
V_6 -> V_47 = V_330 ;
if ( ! F_132 ( V_6 ) &&
( V_326 == V_321 ||
V_326 == V_322 ) )
V_6 -> V_34 |= V_35 ;
else if ( ( F_132 ( V_6 ) &&
( V_326 == V_321 ||
V_326 == V_322 ||
V_326 == V_324 ||
V_326 == V_328 ||
V_326 == V_331 ) ) ||
( V_2 -> V_37 == 2048 &&
V_326 == V_309 ) )
V_6 -> V_34 |= V_51 ;
}
static inline bool F_135 ( struct V_325 * type )
{
return type -> V_320 ;
}
static bool F_136 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_325 * type , T_11 * V_310 , int * V_166 )
{
if ( ! strncmp ( type -> V_332 , V_310 , type -> V_320 ) ) {
V_2 -> V_37 = type -> V_327 ;
V_2 -> V_36 = type -> V_36 ;
V_2 -> V_129 = type -> V_129 ;
V_6 -> V_305 = F_130 ( V_310 [ 2 ] ) ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
V_6 -> V_43 |= type -> V_43 ;
V_6 -> V_285 = F_137 ( type ) ;
V_6 -> V_287 = F_138 ( type ) ;
* V_166 = type -> V_43 & V_44 ;
if ( ! V_2 -> V_300 )
V_2 -> V_300 = type -> V_300 ;
return true ;
}
return false ;
}
static struct V_325 * F_139 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int V_166 ,
int * V_326 , int * V_333 ,
struct V_325 * type )
{
int V_32 , V_334 ;
T_11 V_310 [ 8 ] ;
V_6 -> V_42 ( V_2 , 0 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_296 , 0x00 , - 1 ) ;
* V_326 = V_6 -> V_49 ( V_2 ) ;
* V_333 = V_6 -> V_49 ( V_2 ) ;
V_6 -> V_45 ( V_2 , V_296 , 0x00 , - 1 ) ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
V_310 [ V_32 ] = V_6 -> V_49 ( V_2 ) ;
if ( V_310 [ 0 ] != * V_326 || V_310 [ 1 ] != * V_333 ) {
F_124 ( L_29 ,
* V_326 , * V_333 , V_310 [ 0 ] , V_310 [ 1 ] ) ;
return F_140 ( - V_335 ) ;
}
if ( ! type )
type = V_336 ;
for (; type -> V_300 != NULL ; type ++ ) {
if ( F_135 ( type ) ) {
if ( F_136 ( V_2 , V_6 , type , V_310 , & V_166 ) )
goto V_337;
} else if ( * V_333 == type -> V_333 ) {
break;
}
}
V_6 -> V_252 = 0 ;
if ( ! type -> V_300 || ! type -> V_327 ) {
if ( F_123 ( V_2 , V_6 , & V_166 ) )
goto V_337;
}
if ( ! type -> V_300 )
return F_140 ( - V_335 ) ;
if ( ! V_2 -> V_300 )
V_2 -> V_300 = type -> V_300 ;
V_6 -> V_91 = ( T_2 ) type -> V_91 << 20 ;
if ( ! type -> V_327 && V_6 -> V_338 ) {
V_166 = V_6 -> V_338 ( V_2 , V_6 , V_310 ) ;
} else if ( ! type -> V_327 ) {
F_131 ( V_2 , V_6 , V_310 , & V_166 ) ;
} else {
F_133 ( V_2 , V_6 , type , V_310 , & V_166 ) ;
}
V_6 -> V_43 |= type -> V_43 ;
if ( * V_326 != V_321 && ! type -> V_327 )
V_6 -> V_43 &= ~ V_339 ;
V_337:
for ( V_334 = 0 ; V_340 [ V_334 ] . V_332 != 0x0 ; V_334 ++ ) {
if ( V_340 [ V_334 ] . V_332 == * V_326 )
break;
}
if ( V_6 -> V_43 & V_341 ) {
F_58 ( V_6 -> V_43 & V_44 ) ;
V_6 -> V_43 |= V_166 ;
F_112 ( V_6 , V_166 ) ;
} else if ( V_166 != ( V_6 -> V_43 & V_44 ) ) {
F_124 ( L_30 ,
* V_326 , * V_333 ) ;
F_124 ( L_31 , V_340 [ V_334 ] . V_300 , V_2 -> V_300 ) ;
F_101 ( L_32 ,
( V_6 -> V_43 & V_44 ) ? 16 : 8 ,
V_166 ? 16 : 8 ) ;
return F_140 ( - V_11 ) ;
}
F_134 ( V_2 , V_6 , V_310 ) ;
V_6 -> V_38 = F_141 ( V_2 -> V_37 ) - 1 ;
V_6 -> V_39 = ( V_6 -> V_91 >> V_6 -> V_38 ) - 1 ;
V_6 -> V_342 = V_6 -> V_9 =
F_141 ( V_2 -> V_36 ) - 1 ;
if ( V_6 -> V_91 & 0xffffffff )
V_6 -> V_40 = F_141 ( ( unsigned ) V_6 -> V_91 ) - 1 ;
else {
V_6 -> V_40 = F_141 ( ( unsigned ) ( V_6 -> V_91 >> 32 ) ) ;
V_6 -> V_40 += 32 - 1 ;
}
V_6 -> V_50 = 8 ;
V_6 -> V_246 = F_99 ;
if ( V_2 -> V_37 > 512 && V_6 -> V_45 == F_45 )
V_6 -> V_45 = F_48 ;
F_124 ( L_30 ,
* V_326 , * V_333 ) ;
F_124 ( L_31 , V_340 [ V_334 ] . V_300 ,
V_6 -> V_252 ? V_6 -> V_253 . V_299 : type -> V_300 ) ;
F_124 ( L_33 ,
( int ) ( V_6 -> V_91 >> 20 ) , F_132 ( V_6 ) ? L_34 : L_35 ,
V_2 -> V_37 , V_2 -> V_129 ) ;
return type ;
}
int F_142 ( struct V_1 * V_2 , int V_343 ,
struct V_325 * V_344 )
{
int V_32 , V_166 , V_345 , V_346 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_325 * type ;
V_166 = V_6 -> V_43 & V_44 ;
F_112 ( V_6 , V_166 ) ;
type = F_139 ( V_2 , V_6 , V_166 ,
& V_345 , & V_346 , V_344 ) ;
if ( F_143 ( type ) ) {
if ( ! ( V_6 -> V_43 & V_347 ) )
F_101 ( L_36 ) ;
V_6 -> V_42 ( V_2 , - 1 ) ;
return F_144 ( type ) ;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
for ( V_32 = 1 ; V_32 < V_343 ; V_32 ++ ) {
V_6 -> V_42 ( V_2 , V_32 ) ;
V_6 -> V_45 ( V_2 , V_96 , - 1 , - 1 ) ;
V_6 -> V_45 ( V_2 , V_296 , 0x00 , - 1 ) ;
if ( V_345 != V_6 -> V_49 ( V_2 ) ||
V_346 != V_6 -> V_49 ( V_2 ) ) {
V_6 -> V_42 ( V_2 , - 1 ) ;
break;
}
V_6 -> V_42 ( V_2 , - 1 ) ;
}
if ( V_32 > 1 )
F_124 ( L_37 , V_32 ) ;
V_6 -> V_348 = V_32 ;
V_2 -> V_120 = V_32 * V_6 -> V_91 ;
return 0 ;
}
int F_145 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_349 * V_131 = & V_6 -> V_131 ;
F_146 ( ( V_6 -> V_34 & V_60 ) &&
! ( V_6 -> V_34 & V_350 ) ) ;
if ( ! ( V_6 -> V_43 & V_351 ) )
V_6 -> V_140 = F_119 ( sizeof( * V_6 -> V_140 ) , V_274 ) ;
if ( ! V_6 -> V_140 )
return - V_275 ;
V_6 -> V_128 = V_6 -> V_140 -> V_193 + V_2 -> V_37 ;
if ( ! V_131 -> V_145 && ( V_131 -> V_58 != V_352 ) ) {
switch ( V_2 -> V_129 ) {
case 8 :
V_131 -> V_145 = & V_353 ;
break;
case 16 :
V_131 -> V_145 = & V_354 ;
break;
case 64 :
V_131 -> V_145 = & V_355 ;
break;
case 128 :
V_131 -> V_145 = & V_356 ;
break;
default:
F_101 ( L_38 ,
V_2 -> V_129 ) ;
F_14 () ;
}
}
if ( ! V_6 -> V_229 )
V_6 -> V_229 = F_90 ;
switch ( V_131 -> V_58 ) {
case V_357 :
if ( ! V_131 -> V_148 || ! V_131 -> V_151 || ! V_131 -> V_168 ) {
F_101 ( L_39
L_40 ) ;
F_14 () ;
}
if ( ! V_131 -> V_196 )
V_131 -> V_196 = F_68 ;
case V_358 :
if ( ! V_131 -> V_196 )
V_131 -> V_196 = F_67 ;
if ( ! V_131 -> V_229 )
V_131 -> V_229 = F_87 ;
if ( ! V_131 -> V_147 )
V_131 -> V_147 = F_62 ;
if ( ! V_131 -> V_215 )
V_131 -> V_215 = F_84 ;
if ( ! V_131 -> V_212 )
V_131 -> V_212 = F_78 ;
if ( ! V_131 -> V_241 )
V_131 -> V_241 = F_80 ;
if ( ! V_131 -> V_195 )
V_131 -> V_195 = F_66 ;
if ( ! V_131 -> V_228 )
V_131 -> V_228 = F_88 ;
case V_359 :
if ( ( ! V_131 -> V_148 || ! V_131 -> V_151 || ! V_131 -> V_168 ) &&
( ! V_131 -> V_196 ||
V_131 -> V_196 == F_67 ||
! V_131 -> V_229 ||
V_131 -> V_229 == F_87 ) ) {
F_101 ( L_39
L_40 ) ;
F_14 () ;
}
if ( ! V_131 -> V_196 )
V_131 -> V_196 = F_69 ;
if ( ! V_131 -> V_229 )
V_131 -> V_229 = F_89 ;
if ( ! V_131 -> V_147 )
V_131 -> V_147 = F_63 ;
if ( ! V_131 -> V_215 )
V_131 -> V_215 = F_85 ;
if ( ! V_131 -> V_212 )
V_131 -> V_212 = F_79 ;
if ( ! V_131 -> V_241 )
V_131 -> V_241 = F_81 ;
if ( V_2 -> V_37 >= V_131 -> V_120 ) {
if ( ! V_131 -> V_360 ) {
F_101 ( L_41 ) ;
F_14 () ;
}
break;
}
F_101 ( L_42
L_43 ,
V_131 -> V_120 , V_2 -> V_37 ) ;
V_131 -> V_58 = V_361 ;
case V_361 :
V_131 -> V_148 = V_362 ;
V_131 -> V_151 = V_363 ;
V_131 -> V_196 = F_64 ;
V_131 -> V_195 = F_66 ;
V_131 -> V_229 = F_86 ;
V_131 -> V_147 = F_62 ;
V_131 -> V_215 = F_84 ;
V_131 -> V_212 = F_78 ;
V_131 -> V_241 = F_80 ;
if ( ! V_131 -> V_120 )
V_131 -> V_120 = 256 ;
V_131 -> V_133 = 3 ;
V_131 -> V_360 = 1 ;
break;
case V_352 :
if ( ! F_147 () ) {
F_101 ( L_44 ) ;
F_14 () ;
}
V_131 -> V_148 = V_364 ;
V_131 -> V_151 = V_365 ;
V_131 -> V_196 = F_64 ;
V_131 -> V_195 = F_66 ;
V_131 -> V_229 = F_86 ;
V_131 -> V_147 = F_62 ;
V_131 -> V_215 = F_84 ;
V_131 -> V_212 = F_78 ;
V_131 -> V_241 = F_80 ;
if ( ! V_131 -> V_120 && ( V_2 -> V_129 >= 64 ) ) {
V_131 -> V_120 = 512 ;
V_131 -> V_133 = 7 ;
}
V_131 -> V_7 = F_148 ( V_2 , V_131 -> V_120 , V_131 -> V_133 ,
& V_131 -> V_145 ) ;
if ( ! V_131 -> V_7 ) {
F_101 ( L_45 ) ;
F_14 () ;
}
V_131 -> V_360 = V_131 -> V_133 * 8 / F_126 ( 8 * V_131 -> V_120 ) ;
break;
case V_366 :
F_101 ( L_46
L_47 ) ;
V_131 -> V_196 = F_62 ;
V_131 -> V_229 = F_84 ;
V_131 -> V_212 = F_78 ;
V_131 -> V_147 = F_62 ;
V_131 -> V_215 = F_84 ;
V_131 -> V_241 = F_80 ;
V_131 -> V_120 = V_2 -> V_37 ;
V_131 -> V_133 = 0 ;
V_131 -> V_360 = 0 ;
break;
default:
F_101 ( L_48 , V_131 -> V_58 ) ;
F_14 () ;
}
if ( ! V_131 -> V_211 )
V_131 -> V_211 = V_131 -> V_212 ;
if ( ! V_131 -> V_240 )
V_131 -> V_240 = V_131 -> V_241 ;
V_131 -> V_145 -> V_189 = 0 ;
for ( V_32 = 0 ; V_131 -> V_145 -> V_174 [ V_32 ] . V_177
&& V_32 < F_149 ( V_131 -> V_145 -> V_174 ) ; V_32 ++ )
V_131 -> V_145 -> V_189 += V_131 -> V_145 -> V_174 [ V_32 ] . V_177 ;
V_2 -> V_189 = V_131 -> V_145 -> V_189 ;
V_131 -> V_135 = V_2 -> V_37 / V_131 -> V_120 ;
if ( V_131 -> V_135 * V_131 -> V_120 != V_2 -> V_37 ) {
F_101 ( L_49 ) ;
F_14 () ;
}
V_131 -> V_149 = V_131 -> V_135 * V_131 -> V_133 ;
if ( ! ( V_6 -> V_43 & V_227 ) && F_132 ( V_6 ) ) {
switch ( V_131 -> V_135 ) {
case 2 :
V_2 -> V_367 = 1 ;
break;
case 4 :
case 8 :
case 16 :
V_2 -> V_367 = 2 ;
break;
}
}
V_6 -> V_368 = V_2 -> V_37 >> V_2 -> V_367 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_192 = - 1 ;
if ( ( V_131 -> V_58 == V_361 ) && ( V_6 -> V_38 > 9 ) )
V_6 -> V_43 |= V_369 ;
V_2 -> type = F_132 ( V_6 ) ? V_370 : V_371 ;
V_2 -> V_372 = ( V_6 -> V_43 & V_373 ) ? V_374 :
V_375 ;
V_2 -> V_376 = F_100 ;
V_2 -> V_377 = NULL ;
V_2 -> V_378 = NULL ;
V_2 -> V_379 = F_77 ;
V_2 -> V_380 = F_97 ;
V_2 -> V_381 = F_96 ;
V_2 -> V_382 = F_83 ;
V_2 -> V_383 = F_98 ;
V_2 -> V_384 = F_103 ;
V_2 -> V_385 = NULL ;
V_2 -> V_386 = NULL ;
V_2 -> V_387 = F_109 ;
V_2 -> V_388 = F_110 ;
V_2 -> V_389 = F_104 ;
V_2 -> V_390 = F_105 ;
V_2 -> V_391 = V_2 -> V_37 ;
V_2 -> V_392 = V_131 -> V_145 ;
V_2 -> V_393 = V_131 -> V_360 ;
V_2 -> V_394 = V_131 -> V_120 ;
if ( ! V_2 -> V_395 )
V_2 -> V_395 = V_2 -> V_393 ;
if ( V_6 -> V_43 & V_396 )
return 0 ;
return V_6 -> V_262 ( V_2 ) ;
}
int F_150 ( struct V_1 * V_2 , int V_343 )
{
int V_8 ;
if ( ! V_2 -> V_397 && F_151 () ) {
F_152 ( L_50 , V_10 ) ;
F_14 () ;
}
V_8 = F_142 ( V_2 , V_343 , NULL ) ;
if ( ! V_8 )
V_8 = F_145 ( V_2 ) ;
return V_8 ;
}
void F_153 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_131 . V_58 == V_352 )
F_154 ( (struct V_398 * ) V_6 -> V_131 . V_7 ) ;
F_155 ( V_2 ) ;
F_120 ( V_6 -> V_66 ) ;
if ( ! ( V_6 -> V_43 & V_351 ) )
F_120 ( V_6 -> V_140 ) ;
if ( V_6 -> V_399 && V_6 -> V_399 -> V_43
& V_400 )
F_120 ( V_6 -> V_399 ) ;
}
static int T_12 F_156 ( void )
{
F_157 ( L_51 , & V_78 ) ;
return 0 ;
}
static void T_13 F_158 ( void )
{
F_159 ( V_78 ) ;
}
