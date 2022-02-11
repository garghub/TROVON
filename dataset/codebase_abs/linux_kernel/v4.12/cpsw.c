static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline int F_5 ( T_1 V_6 )
{
return V_6 + 1 ;
}
static void F_6 ( struct V_7 * V_8 , bool V_9 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
int V_14 ;
if ( V_11 -> V_15 . V_16 ) {
bool V_17 = false ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ )
if ( V_11 -> V_18 [ V_14 ] . V_8 -> V_19 & V_20 )
V_17 = true ;
if ( ! V_9 && V_17 ) {
V_9 = true ;
F_8 ( & V_8 -> V_21 , L_1 ) ;
}
if ( V_9 ) {
F_9 ( V_13 , 0 , V_22 , 1 ) ;
F_10 ( & V_8 -> V_21 , L_2 ) ;
} else {
F_9 ( V_13 , 0 , V_22 , 0 ) ;
F_10 ( & V_8 -> V_21 , L_3 ) ;
}
} else {
if ( V_9 ) {
unsigned long V_23 = V_24 + V_25 ;
for ( V_14 = 0 ; V_14 <= V_11 -> V_15 . V_18 ; V_14 ++ ) {
F_9 ( V_13 , V_14 ,
V_26 , 1 ) ;
F_9 ( V_13 , V_14 ,
V_27 , 1 ) ;
}
F_9 ( V_13 , 0 , V_28 , 1 ) ;
do {
F_11 () ;
if ( F_12 ( V_13 , 0 , V_28 ) )
break;
} while ( F_13 ( V_23 , V_24 ) );
F_9 ( V_13 , 0 , V_28 , 1 ) ;
F_14 ( V_13 , V_29 , - 1 ) ;
F_9 ( V_13 , 0 , V_30 , 1 ) ;
F_10 ( & V_8 -> V_21 , L_2 ) ;
} else {
F_9 ( V_13 , 0 , V_30 , 0 ) ;
for ( V_14 = 0 ; V_14 <= V_11 -> V_15 . V_18 ; V_14 ++ ) {
F_9 ( V_13 , V_14 ,
V_26 , 0 ) ;
F_9 ( V_13 , V_14 ,
V_27 , 0 ) ;
}
F_10 ( & V_8 -> V_21 , L_3 ) ;
}
}
}
static void F_15 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_33 ;
if ( V_11 -> V_15 . V_16 )
V_33 = V_11 -> V_18 [ V_32 -> V_34 ] . V_35 ;
else
V_33 = V_11 -> V_15 . V_36 ;
if ( V_8 -> V_19 & V_20 ) {
F_6 ( V_8 , true ) ;
F_17 ( V_11 -> V_13 , V_37 ) ;
return;
} else {
F_6 ( V_8 , false ) ;
}
F_17 ( V_11 -> V_13 , V_32 -> V_8 -> V_19 & V_37 ) ;
F_14 ( V_11 -> V_13 , V_29 , V_33 ) ;
if ( ! F_18 ( V_8 ) ) {
struct V_38 * V_39 ;
F_19 (ha, ndev) {
F_20 ( V_11 , V_32 , ( V_40 * ) V_39 -> V_41 ) ;
}
}
}
static void F_21 ( struct V_10 * V_11 )
{
F_4 ( 0xFF , & V_11 -> V_42 -> V_43 ) ;
F_4 ( 0xFF , & V_11 -> V_42 -> V_44 ) ;
F_22 ( V_11 -> V_45 , true ) ;
return;
}
static void F_23 ( struct V_10 * V_11 )
{
F_4 ( 0 , & V_11 -> V_42 -> V_43 ) ;
F_4 ( 0 , & V_11 -> V_42 -> V_44 ) ;
F_22 ( V_11 -> V_45 , false ) ;
return;
}
static void F_24 ( void * V_46 , int V_47 , int V_48 )
{
struct V_49 * V_50 ;
struct V_51 * V_52 = V_46 ;
struct V_7 * V_8 = V_52 -> V_21 ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_50 = F_25 ( V_8 , F_26 ( V_52 ) ) ;
if ( F_27 ( F_28 ( V_50 ) ) )
F_29 ( V_50 ) ;
F_30 ( V_11 -> V_53 , V_52 ) ;
V_8 -> V_54 . V_55 ++ ;
V_8 -> V_54 . V_56 += V_47 ;
F_31 ( V_52 ) ;
}
static void F_32 ( void * V_46 , int V_47 , int V_48 )
{
struct V_57 * V_58 ;
struct V_51 * V_52 = V_46 ;
struct V_51 * V_59 ;
struct V_7 * V_8 = V_52 -> V_21 ;
int V_60 = 0 ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
F_33 ( V_11 , V_48 , V_8 , V_52 ) ;
if ( F_27 ( V_48 < 0 ) || F_27 ( ! F_34 ( V_8 ) ) ) {
if ( V_11 -> V_15 . V_16 && V_11 -> V_61 &&
( V_48 >= 0 ) ) {
V_59 = V_52 ;
goto V_62;
}
F_31 ( V_52 ) ;
return;
}
V_59 = F_35 ( V_8 , V_11 -> V_63 ) ;
if ( V_59 ) {
F_36 ( V_59 , V_52 ) ;
F_37 ( V_52 , V_47 ) ;
F_38 ( V_11 -> V_53 , V_52 ) ;
V_52 -> V_64 = F_39 ( V_52 , V_8 ) ;
F_40 ( V_52 ) ;
V_8 -> V_54 . V_65 += V_47 ;
V_8 -> V_54 . V_66 ++ ;
F_41 ( V_59 ) ;
} else {
V_8 -> V_54 . V_67 ++ ;
V_59 = V_52 ;
}
V_62:
if ( F_42 ( V_8 ) ) {
F_31 ( V_59 ) ;
return;
}
V_58 = V_11 -> V_68 [ F_26 ( V_59 ) ] . V_58 ;
V_60 = F_43 ( V_58 , V_59 , V_59 -> V_15 ,
F_44 ( V_59 ) , 0 ) ;
if ( F_45 ( V_60 < 0 ) )
F_31 ( V_59 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
T_1 V_69 = 0 , V_70 = 0 ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_71 * V_72 = V_11 -> V_72 ;
int V_14 , V_73 , V_74 = 0 ;
int V_75 , V_76 = 0 ;
T_1 V_77 , V_78 ;
int V_79 = 0 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_80 ; V_14 ++ ) {
V_77 = F_47 ( V_72 [ V_14 ] . V_58 ) ;
if ( ! V_77 )
continue;
V_74 ++ ;
V_69 += V_77 ;
}
if ( V_11 -> V_80 == V_74 ) {
V_78 = V_69 ;
} else if ( ! V_74 ) {
V_79 = V_81 / V_11 -> V_80 ;
V_70 = 0 ;
V_78 = V_69 ;
} else {
V_78 = V_11 -> V_82 * 1000 ;
if ( V_78 < V_69 )
V_78 *= 10 ;
if ( V_78 < V_69 )
V_78 *= 10 ;
V_79 = ( V_69 * V_81 ) / V_78 ;
V_79 = ( V_81 - V_79 ) /
( V_11 -> V_80 - V_74 ) ;
V_70 = ( V_78 - V_69 ) /
( V_11 -> V_80 - V_74 ) ;
}
V_75 = V_81 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_80 ; V_14 ++ ) {
V_77 = F_47 ( V_72 [ V_14 ] . V_58 ) ;
if ( V_77 ) {
V_72 [ V_14 ] . V_75 = ( V_77 * V_81 ) / V_78 ;
if ( ! V_72 [ V_14 ] . V_75 )
V_72 [ V_14 ] . V_75 ++ ;
if ( V_77 > V_70 ) {
V_76 = V_14 ;
V_70 = V_77 ;
}
V_73 = ( V_77 * 100 ) / V_78 ;
if ( ! V_73 )
V_73 ++ ;
F_48 ( V_11 -> V_72 [ V_14 ] . V_58 , V_73 ) ;
} else {
V_72 [ V_14 ] . V_75 = V_79 ;
if ( ! V_76 )
V_76 = V_14 ;
F_48 ( V_11 -> V_72 [ V_14 ] . V_58 , 0 ) ;
}
V_75 -= V_72 [ V_14 ] . V_75 ;
}
if ( V_75 )
V_72 [ V_76 ] . V_75 += V_75 ;
V_75 = V_81 ;
V_79 = V_75 / V_11 -> V_83 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_83 ; V_14 ++ ) {
V_11 -> V_68 [ V_14 ] . V_75 = V_79 ;
V_75 -= V_79 ;
}
if ( V_75 )
V_11 -> V_68 [ 0 ] . V_75 += V_75 ;
}
static T_2 F_49 ( int V_84 , void * V_85 )
{
struct V_10 * V_11 = V_85 ;
F_50 ( 0 , & V_11 -> V_42 -> V_43 ) ;
F_51 ( V_11 -> V_45 , V_86 ) ;
if ( V_11 -> V_87 ) {
F_52 ( V_11 -> V_88 [ 1 ] ) ;
V_11 -> V_89 = true ;
}
F_53 ( & V_11 -> V_90 ) ;
return V_91 ;
}
static T_2 F_54 ( int V_84 , void * V_85 )
{
struct V_10 * V_11 = V_85 ;
F_51 ( V_11 -> V_45 , V_92 ) ;
F_50 ( 0 , & V_11 -> V_42 -> V_44 ) ;
if ( V_11 -> V_87 ) {
F_52 ( V_11 -> V_88 [ 0 ] ) ;
V_11 -> V_93 = true ;
}
F_53 ( & V_11 -> V_94 ) ;
return V_91 ;
}
static int F_55 ( struct V_95 * V_90 , int V_75 )
{
T_1 V_96 ;
int V_97 , V_98 , V_58 ;
struct V_10 * V_11 = F_56 ( V_90 ) ;
struct V_71 * V_72 ;
V_96 = F_57 ( V_11 -> V_45 ) ;
for ( V_58 = 0 , V_97 = 0 ; V_96 ; V_96 >>= 1 , V_58 ++ ) {
if ( ! ( V_96 & 0x01 ) )
continue;
V_72 = & V_11 -> V_72 [ V_58 ] ;
if ( F_27 ( V_72 -> V_75 > V_75 - V_97 ) )
V_98 = V_75 - V_97 ;
else
V_98 = V_72 -> V_75 ;
V_97 += F_58 ( V_72 -> V_58 , V_98 ) ;
if ( V_97 >= V_75 )
break;
}
if ( V_97 < V_75 ) {
F_59 ( V_90 ) ;
F_50 ( 0xff , & V_11 -> V_42 -> V_43 ) ;
if ( V_11 -> V_87 && V_11 -> V_89 ) {
V_11 -> V_89 = false ;
F_60 ( V_11 -> V_88 [ 1 ] ) ;
}
}
return V_97 ;
}
static int F_61 ( struct V_95 * V_94 , int V_75 )
{
T_1 V_96 ;
int V_99 , V_98 , V_58 ;
struct V_10 * V_11 = F_56 ( V_94 ) ;
struct V_71 * V_68 ;
V_96 = F_62 ( V_11 -> V_45 ) ;
for ( V_58 = 0 , V_99 = 0 ; V_96 ; V_96 >>= 1 , V_58 ++ ) {
if ( ! ( V_96 & 0x01 ) )
continue;
V_68 = & V_11 -> V_68 [ V_58 ] ;
if ( F_27 ( V_68 -> V_75 > V_75 - V_99 ) )
V_98 = V_75 - V_99 ;
else
V_98 = V_68 -> V_75 ;
V_99 += F_58 ( V_68 -> V_58 , V_98 ) ;
if ( V_99 >= V_75 )
break;
}
if ( V_99 < V_75 ) {
F_63 ( V_94 , V_99 ) ;
F_50 ( 0xff , & V_11 -> V_42 -> V_44 ) ;
if ( V_11 -> V_87 && V_11 -> V_93 ) {
V_11 -> V_93 = false ;
F_60 ( V_11 -> V_88 [ 0 ] ) ;
}
}
return V_99 ;
}
static inline void F_64 ( const char * V_100 , void T_3 * V_101 )
{
unsigned long V_23 = V_24 + V_25 ;
F_4 ( 1 , V_101 ) ;
do {
F_11 () ;
} while ( ( F_2 ( V_101 ) & 1 ) && F_13 ( V_23 , V_24 ) );
F_65 ( F_2 ( V_101 ) & 1 , L_4 , V_100 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
F_3 ( V_2 , F_67 ( V_32 -> V_102 ) , V_103 ) ;
F_3 ( V_2 , F_68 ( V_32 -> V_102 ) , V_104 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
struct V_31 * V_32 , bool * V_105 )
{
struct V_106 * V_107 = V_2 -> V_107 ;
T_1 V_108 = 0 ;
T_1 V_109 ;
struct V_10 * V_11 = V_32 -> V_11 ;
if ( ! V_107 )
return;
V_109 = F_5 ( V_2 -> V_6 ) ;
if ( V_107 -> V_105 ) {
V_108 = V_11 -> V_15 . V_108 ;
F_9 ( V_11 -> V_13 , V_109 ,
V_110 , V_111 ) ;
if ( V_107 -> V_82 == 1000 )
V_108 |= F_70 ( 7 ) ;
if ( V_107 -> V_112 )
V_108 |= F_70 ( 0 ) ;
if ( V_107 -> V_82 == 100 )
V_108 |= F_70 ( 15 ) ;
else if ( V_107 -> V_82 == 10 )
V_108 |= F_70 ( 18 ) ;
if ( V_32 -> V_113 )
V_108 |= F_70 ( 3 ) ;
if ( V_32 -> V_114 )
V_108 |= F_70 ( 4 ) ;
* V_105 = true ;
} else {
V_108 = 0 ;
F_9 ( V_11 -> V_13 , V_109 ,
V_110 , V_115 ) ;
}
if ( V_108 != V_2 -> V_108 ) {
F_71 ( V_107 ) ;
F_4 ( V_108 , & V_2 -> V_116 -> V_108 ) ;
}
V_2 -> V_108 = V_108 ;
}
static int F_72 ( struct V_10 * V_11 )
{
int V_14 , V_82 ;
for ( V_14 = 0 , V_82 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ )
if ( V_11 -> V_18 [ V_14 ] . V_107 && V_11 -> V_18 [ V_14 ] . V_107 -> V_105 )
V_82 += V_11 -> V_18 [ V_14 ] . V_107 -> V_82 ;
return V_82 ;
}
static int F_73 ( struct V_10 * V_11 )
{
int V_14 , V_74 ;
int V_82 , V_77 ;
V_82 = F_72 ( V_11 ) ;
if ( V_82 == V_11 -> V_82 || ! V_82 )
return 0 ;
V_11 -> V_82 = V_82 ;
for ( V_14 = 0 , V_74 = 0 ; V_14 < V_11 -> V_80 ; V_14 ++ ) {
V_77 = F_47 ( V_11 -> V_72 [ V_14 ] . V_58 ) ;
if ( ! V_77 )
break;
V_74 ++ ;
}
if ( ! V_74 || V_74 == V_11 -> V_80 )
return 0 ;
return 1 ;
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
bool V_105 = false ;
F_75 ( V_32 , F_69 , V_32 , & V_105 ) ;
if ( V_105 ) {
if ( F_73 ( V_11 ) )
F_46 ( V_8 ) ;
F_76 ( V_8 ) ;
if ( F_34 ( V_8 ) )
F_77 ( V_8 ) ;
} else {
F_78 ( V_8 ) ;
F_79 ( V_8 ) ;
}
}
static int F_80 ( struct V_7 * V_8 ,
struct V_117 * V_118 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_118 -> V_119 = V_11 -> V_120 ;
return 0 ;
}
static int F_81 ( struct V_7 * V_8 ,
struct V_117 * V_118 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
T_1 V_121 ;
T_1 V_122 = 0 ;
T_1 V_123 = 0 ;
T_1 V_124 = 1 ;
T_1 V_120 = 0 ;
struct V_10 * V_11 = V_32 -> V_11 ;
V_120 = V_118 -> V_119 ;
V_121 = F_82 ( & V_11 -> V_42 -> V_125 ) ;
V_123 = V_11 -> V_126 * 4 ;
if ( ! V_118 -> V_119 ) {
V_121 &= ~ ( V_127 | V_128 ) ;
goto V_129;
}
if ( V_120 < V_130 )
V_120 = V_130 ;
if ( V_120 > V_131 ) {
V_124 = V_127 / V_123 ;
if ( V_124 > 1 ) {
V_123 *= V_124 ;
if ( V_120 > ( V_131 * V_124 ) )
V_120 = ( V_131
* V_124 ) ;
} else {
V_124 = 1 ;
V_120 = V_131 ;
}
}
V_122 = ( 1000 * V_124 ) / V_120 ;
F_50 ( V_122 , & V_11 -> V_42 -> V_132 ) ;
F_50 ( V_122 , & V_11 -> V_42 -> V_133 ) ;
V_121 |= V_128 ;
V_121 &= ( ~ V_127 ) ;
V_121 |= ( V_123 & V_127 ) ;
V_129:
F_50 ( V_121 , & V_11 -> V_42 -> V_125 ) ;
F_83 ( V_32 , V_134 , L_5 , V_120 ) ;
V_11 -> V_120 = V_120 ;
return 0 ;
}
static int F_84 ( struct V_7 * V_8 , int V_135 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
switch ( V_135 ) {
case V_136 :
return ( V_137 +
( V_11 -> V_83 + V_11 -> V_80 ) *
V_138 ) ;
default:
return - V_139 ;
}
}
static void F_85 ( V_40 * * V_140 , int V_141 , int V_142 )
{
int V_143 ;
int line ;
int V_14 ;
V_143 = V_138 * V_141 ;
for ( V_14 = 0 ; V_14 < V_143 ; V_14 ++ ) {
line = V_14 % V_138 ;
snprintf ( * V_140 , V_144 ,
L_6 , V_142 ? L_7 : L_8 ,
V_14 / V_138 ,
V_145 [ line ] . V_146 ) ;
* V_140 += V_144 ;
}
}
static void F_86 ( struct V_7 * V_8 , T_1 V_147 , V_40 * V_15 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_40 * V_140 = V_15 ;
int V_14 ;
switch ( V_147 ) {
case V_136 :
for ( V_14 = 0 ; V_14 < V_137 ; V_14 ++ ) {
memcpy ( V_140 , V_148 [ V_14 ] . V_146 ,
V_144 ) ;
V_140 += V_144 ;
}
F_85 ( & V_140 , V_11 -> V_83 , 1 ) ;
F_85 ( & V_140 , V_11 -> V_80 , 0 ) ;
break;
}
}
static void F_87 ( struct V_7 * V_8 ,
struct V_149 * V_54 , T_4 * V_15 )
{
V_40 * V_140 ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_150 V_151 ;
int V_14 , V_152 , V_58 ;
for ( V_152 = 0 ; V_152 < V_137 ; V_152 ++ )
V_15 [ V_152 ] = F_82 ( V_11 -> V_153 +
V_148 [ V_152 ] . V_154 ) ;
for ( V_58 = 0 ; V_58 < V_11 -> V_83 ; V_58 ++ ) {
F_88 ( V_11 -> V_68 [ V_58 ] . V_58 , & V_151 ) ;
for ( V_14 = 0 ; V_14 < V_138 ; V_14 ++ , V_152 ++ ) {
V_140 = ( V_40 * ) & V_151 +
V_145 [ V_14 ] . V_154 ;
V_15 [ V_152 ] = * ( T_1 * ) V_140 ;
}
}
for ( V_58 = 0 ; V_58 < V_11 -> V_80 ; V_58 ++ ) {
F_88 ( V_11 -> V_72 [ V_58 ] . V_58 , & V_151 ) ;
for ( V_14 = 0 ; V_14 < V_138 ; V_14 ++ , V_152 ++ ) {
V_140 = ( V_40 * ) & V_151 +
V_145 [ V_14 ] . V_154 ;
V_15 [ V_152 ] = * ( T_1 * ) V_140 ;
}
}
}
static inline int F_89 ( struct V_31 * V_32 ,
struct V_51 * V_52 ,
struct V_57 * V_155 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
return F_43 ( V_155 , V_52 , V_52 -> V_15 , V_52 -> V_47 ,
V_32 -> V_34 + V_11 -> V_15 . V_16 ) ;
}
static inline void F_90 (
struct V_31 * V_32 , struct V_1 * V_2 ,
T_1 V_109 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
T_1 V_156 = 1 << V_109 | V_157 ;
if ( V_11 -> V_158 == V_159 )
F_3 ( V_2 , V_2 -> V_35 , V_160 ) ;
else
F_3 ( V_2 , V_2 -> V_35 , V_161 ) ;
F_91 ( V_11 -> V_13 , V_2 -> V_35 , V_156 ,
V_156 , V_156 , 0 ) ;
F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
V_156 , V_163 , V_2 -> V_35 , 0 ) ;
F_93 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 |
V_165 , V_2 -> V_35 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
char V_166 [ 32 ] ;
snprintf ( V_166 , sizeof( V_166 ) , L_9 , V_2 -> V_6 ) ;
F_64 ( V_166 , & V_2 -> V_116 -> F_64 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
T_1 V_109 ;
struct V_106 * V_107 ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_94 ( V_2 ) ;
F_4 ( V_167 , & V_2 -> V_116 -> V_168 ) ;
switch ( V_11 -> V_158 ) {
case V_159 :
F_3 ( V_2 , V_169 , V_170 ) ;
F_3 ( V_2 ,
( V_171 << V_172 ) |
V_173 , V_174 ) ;
break;
case V_175 :
case V_176 :
case V_177 :
F_3 ( V_2 , V_169 , V_178 ) ;
F_3 ( V_2 ,
( V_171 << V_172 ) |
V_173 , V_179 ) ;
break;
}
F_4 ( V_11 -> V_63 , & V_2 -> V_116 -> V_180 ) ;
F_66 ( V_2 , V_32 ) ;
V_2 -> V_108 = 0 ;
V_109 = F_5 ( V_2 -> V_6 ) ;
if ( V_11 -> V_15 . V_16 )
F_90 ( V_32 , V_2 , V_109 ) ;
else
F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
1 << V_109 , 0 , 0 , V_181 ) ;
if ( V_2 -> V_15 -> V_182 ) {
V_107 = F_96 ( V_32 -> V_8 , V_2 -> V_15 -> V_182 ,
& F_74 , 0 , V_2 -> V_15 -> V_183 ) ;
if ( ! V_107 ) {
F_8 ( V_32 -> V_21 , L_10 ,
V_2 -> V_15 -> V_182 -> V_184 ,
V_2 -> V_6 ) ;
return;
}
} else {
V_107 = F_97 ( V_32 -> V_8 , V_2 -> V_15 -> V_185 ,
& F_74 , V_2 -> V_15 -> V_183 ) ;
if ( F_98 ( V_107 ) ) {
F_8 ( V_32 -> V_21 ,
L_11 ,
V_2 -> V_15 -> V_185 , V_2 -> V_6 ,
F_99 ( V_107 ) ) ;
return;
}
}
V_2 -> V_107 = V_107 ;
F_100 ( V_2 -> V_107 ) ;
F_101 ( V_2 -> V_107 ) ;
F_102 ( V_11 -> V_21 , V_2 -> V_107 -> V_186 , V_2 -> V_6 ) ;
}
static inline void F_103 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
const int V_187 = V_11 -> V_15 . V_36 ;
T_1 V_101 ;
int V_14 ;
int V_188 ;
V_101 = ( V_11 -> V_158 == V_159 ) ? V_160 :
V_161 ;
F_50 ( V_187 , & V_11 -> V_189 -> V_35 ) ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ )
F_3 ( V_11 -> V_18 + V_14 , V_187 , V_101 ) ;
if ( V_32 -> V_8 -> V_19 & V_37 )
V_188 = V_29 ;
else
V_188 = V_190 | V_191 ;
F_91 ( V_11 -> V_13 , V_187 , V_29 ,
V_29 , V_29 ,
V_188 ) ;
}
static void F_104 ( struct V_31 * V_32 )
{
T_1 V_192 ;
T_1 V_193 ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_64 ( L_12 , & V_11 -> V_4 -> F_64 ) ;
F_105 ( V_11 -> V_13 ) ;
F_9 ( V_11 -> V_13 , V_164 , V_194 ,
V_195 ) ;
V_193 = F_82 ( & V_11 -> V_4 -> V_196 ) ;
V_193 |= V_197 ;
F_50 ( V_193 , & V_11 -> V_4 -> V_196 ) ;
V_192 = ( V_11 -> V_15 . V_16 ) ? V_198 :
V_199 ;
F_50 ( V_192 , & V_11 -> V_189 -> V_200 ) ;
F_4 ( V_201 ,
& V_11 -> V_189 -> V_202 ) ;
F_4 ( 0 , & V_11 -> V_189 -> V_203 ) ;
F_9 ( V_11 -> V_13 , V_164 ,
V_110 , V_111 ) ;
if ( ! V_11 -> V_15 . V_16 ) {
F_93 ( V_11 -> V_13 , V_32 -> V_102 , V_164 ,
0 , 0 ) ;
F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
V_157 , 0 , 0 , V_181 ) ;
}
}
static int F_106 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_51 * V_52 ;
int V_204 ;
int V_58 , V_14 , V_60 ;
for ( V_58 = 0 ; V_58 < V_11 -> V_83 ; V_58 ++ ) {
V_204 = F_107 ( V_11 -> V_68 [ V_58 ] . V_58 ) ;
for ( V_14 = 0 ; V_14 < V_204 ; V_14 ++ ) {
V_52 = F_108 ( V_32 -> V_8 ,
V_11 -> V_63 ,
V_205 ) ;
if ( ! V_52 ) {
F_109 ( V_32 , V_206 , L_13 ) ;
return - V_207 ;
}
F_110 ( V_52 , V_58 ) ;
V_60 = F_43 ( V_11 -> V_68 [ V_58 ] . V_58 , V_52 ,
V_52 -> V_15 , F_44 ( V_52 ) ,
0 ) ;
if ( V_60 < 0 ) {
F_109 ( V_32 , V_206 ,
L_14 ,
V_58 , V_60 ) ;
F_111 ( V_52 ) ;
return V_60 ;
}
F_41 ( V_52 ) ;
}
F_112 ( V_32 , V_206 , L_15 ,
V_58 , V_204 ) ;
}
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
T_1 V_109 ;
V_109 = F_5 ( V_2 -> V_6 ) ;
if ( ! V_2 -> V_107 )
return;
F_114 ( V_2 -> V_107 ) ;
F_115 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
F_9 ( V_11 -> V_13 , V_109 ,
V_110 , V_115 ) ;
F_94 ( V_2 ) ;
}
static int F_116 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
T_1 V_101 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
F_78 ( V_8 ) ;
V_60 = F_119 ( V_8 , V_11 -> V_80 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_16 ) ;
goto V_208;
}
V_60 = F_120 ( V_8 , V_11 -> V_83 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_17 ) ;
goto V_208;
}
V_101 = V_11 -> V_158 ;
F_121 ( V_32 -> V_21 , L_18 ,
F_122 ( V_101 ) , F_123 ( V_101 ) ,
F_124 ( V_101 ) ) ;
if ( ! V_11 -> V_61 )
F_104 ( V_32 ) ;
F_75 ( V_32 , F_95 , V_32 ) ;
if ( ! V_11 -> V_15 . V_16 )
F_103 ( V_32 ) ;
else
F_91 ( V_11 -> V_13 , V_11 -> V_15 . V_36 ,
V_29 , V_29 , 0 , 0 ) ;
if ( ! V_11 -> V_61 ) {
F_4 ( 0 , & V_11 -> V_4 -> V_209 ) ;
F_4 ( 0x7 , & V_11 -> V_4 -> V_210 ) ;
F_50 ( 0x7 , & V_11 -> V_4 -> V_211 ) ;
F_125 ( & V_11 -> V_94 ) ;
F_125 ( & V_11 -> V_90 ) ;
if ( V_11 -> V_89 ) {
V_11 -> V_89 = false ;
F_60 ( V_11 -> V_88 [ 1 ] ) ;
}
if ( V_11 -> V_93 ) {
V_11 -> V_93 = false ;
F_60 ( V_11 -> V_88 [ 0 ] ) ;
}
V_60 = F_106 ( V_32 ) ;
if ( V_60 < 0 )
goto V_208;
if ( F_126 ( V_11 -> V_53 ) )
F_8 ( V_32 -> V_21 , L_19 ) ;
}
if ( V_11 -> V_120 != 0 ) {
struct V_117 V_118 ;
V_118 . V_119 = V_11 -> V_120 ;
F_81 ( V_8 , & V_118 ) ;
}
F_127 ( V_11 -> V_45 ) ;
F_21 ( V_11 ) ;
V_11 -> V_61 ++ ;
return 0 ;
V_208:
F_128 ( V_11 -> V_45 ) ;
F_75 ( V_32 , F_113 , V_11 ) ;
F_129 ( V_11 -> V_21 ) ;
F_78 ( V_32 -> V_8 ) ;
return V_60 ;
}
static int F_130 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_112 ( V_32 , V_212 , L_20 ) ;
F_79 ( V_32 -> V_8 ) ;
F_78 ( V_32 -> V_8 ) ;
if ( V_11 -> V_61 <= 1 ) {
F_131 ( & V_11 -> V_94 ) ;
F_131 ( & V_11 -> V_90 ) ;
F_132 ( V_11 -> V_53 ) ;
F_23 ( V_11 ) ;
F_128 ( V_11 -> V_45 ) ;
F_133 ( V_11 -> V_13 ) ;
}
F_75 ( V_32 , F_113 , V_11 ) ;
if ( F_73 ( V_11 ) )
F_46 ( V_8 ) ;
V_11 -> V_61 -- ;
F_129 ( V_11 -> V_21 ) ;
return 0 ;
}
static T_5 F_134 ( struct V_51 * V_52 ,
struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_49 * V_50 ;
struct V_57 * V_155 ;
int V_60 , V_213 ;
if ( F_135 ( V_52 , V_214 ) ) {
F_109 ( V_32 , V_215 , L_21 ) ;
V_8 -> V_54 . V_216 ++ ;
return V_217 ;
}
if ( F_136 ( V_52 ) -> V_218 & V_219 &&
F_137 ( V_11 -> V_53 ) )
F_136 ( V_52 ) -> V_218 |= V_220 ;
F_138 ( V_52 ) ;
V_213 = F_26 ( V_52 ) ;
if ( V_213 >= V_11 -> V_80 )
V_213 = V_213 % V_11 -> V_80 ;
V_155 = V_11 -> V_72 [ V_213 ] . V_58 ;
V_60 = F_89 ( V_32 , V_52 , V_155 ) ;
if ( F_27 ( V_60 != 0 ) ) {
F_109 ( V_32 , V_215 , L_22 ) ;
goto V_221;
}
if ( F_27 ( ! F_139 ( V_155 ) ) ) {
V_50 = F_25 ( V_8 , V_213 ) ;
F_140 ( V_50 ) ;
}
return V_222 ;
V_221:
V_8 -> V_54 . V_216 ++ ;
V_50 = F_25 ( V_8 , F_26 ( V_52 ) ) ;
F_140 ( V_50 ) ;
return V_223 ;
}
static void F_141 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_18 [ V_11 -> V_15 . V_224 ] ;
T_1 V_225 , V_226 ;
if ( ! F_137 ( V_11 -> V_53 ) &&
! F_142 ( V_11 -> V_53 ) ) {
F_3 ( V_2 , 0 , V_227 ) ;
return;
}
V_226 = ( 30 << V_228 ) | V_229 ;
V_225 = V_230 << V_231 ;
if ( F_137 ( V_11 -> V_53 ) )
V_225 |= V_232 ;
if ( F_142 ( V_11 -> V_53 ) )
V_225 |= V_233 ;
F_3 ( V_2 , V_225 , V_227 ) ;
F_3 ( V_2 , V_226 , V_234 ) ;
}
static void F_143 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = V_32 -> V_11 ;
T_1 V_235 , V_236 ;
V_2 = & V_11 -> V_18 [ F_144 ( V_11 , V_32 ) ] ;
V_235 = F_1 ( V_2 , V_237 ) ;
switch ( V_11 -> V_158 ) {
case V_175 :
V_235 &= ~ V_238 ;
if ( F_137 ( V_11 -> V_53 ) )
V_235 |= V_239 ;
if ( F_142 ( V_11 -> V_53 ) )
V_235 |= V_240 ;
break;
case V_176 :
default:
V_235 &= ~ V_241 ;
if ( F_137 ( V_11 -> V_53 ) )
V_235 |= V_242 ;
if ( F_142 ( V_11 -> V_53 ) )
V_235 |= V_243 ;
break;
}
V_236 = ( 30 << V_244 ) | V_230 ;
F_3 ( V_2 , V_236 , V_245 ) ;
F_3 ( V_2 , V_235 , V_237 ) ;
F_4 ( V_229 , & V_11 -> V_4 -> V_246 ) ;
}
static int F_145 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
struct V_31 * V_32 = F_16 ( V_21 ) ;
struct V_249 V_250 ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_53 * V_53 = V_11 -> V_53 ;
if ( V_11 -> V_158 != V_159 &&
V_11 -> V_158 != V_175 &&
V_11 -> V_158 != V_176 )
return - V_139 ;
if ( F_146 ( & V_250 , V_248 -> V_251 , sizeof( V_250 ) ) )
return - V_252 ;
if ( V_250 . V_19 )
return - V_253 ;
if ( V_250 . V_254 != V_255 && V_250 . V_254 != V_256 )
return - V_257 ;
switch ( V_250 . V_258 ) {
case V_259 :
F_147 ( V_53 , 0 ) ;
break;
case V_260 :
case V_261 :
case V_262 :
case V_263 :
return - V_257 ;
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
F_147 ( V_53 , 1 ) ;
V_250 . V_258 = V_270 ;
break;
default:
return - V_257 ;
}
F_148 ( V_53 , V_250 . V_254 == V_256 ) ;
switch ( V_11 -> V_158 ) {
case V_159 :
F_141 ( V_11 ) ;
break;
case V_175 :
case V_176 :
F_143 ( V_32 ) ;
break;
default:
F_45 ( 1 ) ;
}
return F_149 ( V_248 -> V_251 , & V_250 , sizeof( V_250 ) ) ? - V_252 : 0 ;
}
static int F_150 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
struct V_53 * V_53 = V_11 -> V_53 ;
struct V_249 V_250 ;
if ( V_11 -> V_158 != V_159 &&
V_11 -> V_158 != V_175 &&
V_11 -> V_158 != V_176 )
return - V_139 ;
V_250 . V_19 = 0 ;
V_250 . V_254 = F_137 ( V_53 ) ?
V_256 : V_255 ;
V_250 . V_258 = ( F_142 ( V_53 ) ?
V_270 : V_259 ) ;
return F_149 ( V_248 -> V_251 , & V_250 , sizeof( V_250 ) ) ? - V_252 : 0 ;
}
static int F_150 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
return - V_139 ;
}
static int F_145 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
return - V_139 ;
}
static int F_151 ( struct V_7 * V_21 , struct V_247 * V_273 , int V_274 )
{
struct V_31 * V_32 = F_16 ( V_21 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
if ( ! F_34 ( V_21 ) )
return - V_253 ;
switch ( V_274 ) {
case V_276 :
return F_145 ( V_21 , V_273 ) ;
case V_277 :
return F_150 ( V_21 , V_273 ) ;
}
if ( ! V_11 -> V_18 [ V_275 ] . V_107 )
return - V_139 ;
return F_152 ( V_11 -> V_18 [ V_275 ] . V_107 , V_273 , V_274 ) ;
}
static void F_153 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_58 ;
F_109 ( V_32 , V_215 , L_23 ) ;
V_8 -> V_54 . V_278 ++ ;
F_23 ( V_11 ) ;
for ( V_58 = 0 ; V_58 < V_11 -> V_80 ; V_58 ++ ) {
F_154 ( V_11 -> V_72 [ V_58 ] . V_58 ) ;
F_155 ( V_11 -> V_72 [ V_58 ] . V_58 ) ;
}
F_21 ( V_11 ) ;
F_156 ( V_8 ) ;
F_77 ( V_8 ) ;
}
static int F_157 ( struct V_7 * V_8 , void * V_140 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_279 * V_41 = (struct V_279 * ) V_140 ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_19 = 0 ;
T_6 V_33 = 0 ;
int V_60 ;
if ( ! F_158 ( V_41 -> V_280 ) )
return - V_281 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 ) {
V_33 = V_11 -> V_18 [ V_32 -> V_34 ] . V_35 ;
V_19 = V_163 ;
}
F_159 ( V_11 -> V_13 , V_32 -> V_102 , V_164 ,
V_19 , V_33 ) ;
F_93 ( V_11 -> V_13 , V_41 -> V_280 , V_164 ,
V_19 , V_33 ) ;
memcpy ( V_32 -> V_102 , V_41 -> V_280 , V_282 ) ;
memcpy ( V_8 -> V_283 , V_32 -> V_102 , V_282 ) ;
F_75 ( V_32 , F_66 , V_32 ) ;
F_160 ( V_11 -> V_21 ) ;
return 0 ;
}
static void F_161 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
F_23 ( V_11 ) ;
F_54 ( V_11 -> V_88 [ 0 ] , V_11 ) ;
F_49 ( V_11 -> V_88 [ 1 ] , V_11 ) ;
F_21 ( V_11 ) ;
}
static inline int F_162 ( struct V_31 * V_32 ,
unsigned short V_33 )
{
int V_60 ;
int V_188 = 0 ;
T_1 V_156 ;
struct V_10 * V_11 = V_32 -> V_11 ;
if ( V_11 -> V_15 . V_16 ) {
V_156 = ( 1 << ( V_32 -> V_34 + 1 ) ) | V_157 ;
if ( V_32 -> V_8 -> V_19 & V_37 )
V_188 = V_156 ;
} else {
V_156 = V_29 ;
if ( V_32 -> V_8 -> V_19 & V_37 )
V_188 = V_29 ;
else
V_188 = V_190 | V_191 ;
}
V_60 = F_91 ( V_11 -> V_13 , V_33 , V_156 , 0 , V_156 ,
V_188 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_93 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 , V_33 ) ;
if ( V_60 != 0 )
goto V_284;
V_60 = F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
V_156 , V_163 , V_33 , 0 ) ;
if ( V_60 != 0 )
goto V_285;
return 0 ;
V_285:
F_159 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 , V_33 ) ;
V_284:
F_163 ( V_11 -> V_13 , V_33 , 0 ) ;
return V_60 ;
}
static int F_164 ( struct V_7 * V_8 ,
T_7 V_286 , T_6 V_33 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
if ( V_33 == V_11 -> V_15 . V_36 )
return 0 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( V_33 == V_11 -> V_18 [ V_14 ] . V_35 )
return - V_253 ;
}
}
F_121 ( V_32 -> V_21 , L_24 , V_33 ) ;
V_60 = F_162 ( V_32 , V_33 ) ;
F_160 ( V_11 -> V_21 ) ;
return V_60 ;
}
static int F_165 ( struct V_7 * V_8 ,
T_7 V_286 , T_6 V_33 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
if ( V_33 == V_11 -> V_15 . V_36 )
return 0 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( V_33 == V_11 -> V_18 [ V_14 ] . V_35 )
return - V_253 ;
}
}
F_121 ( V_32 -> V_21 , L_25 , V_33 ) ;
V_60 = F_163 ( V_11 -> V_13 , V_33 , 0 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_159 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 , V_33 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_166 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
0 , V_163 , V_33 ) ;
F_160 ( V_11 -> V_21 ) ;
return V_60 ;
}
static int F_167 ( struct V_7 * V_8 , int V_287 , T_1 V_288 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
T_1 V_289 ;
T_1 V_77 ;
int V_14 , V_60 ;
V_77 = F_25 ( V_8 , V_287 ) -> V_290 ;
if ( V_77 == V_288 )
return 0 ;
V_77 = V_288 * 1000 ;
V_289 = F_168 ( V_11 -> V_45 ) ;
if ( ( V_77 < V_289 && V_77 ) ) {
F_8 ( V_32 -> V_21 , L_26 ,
V_289 ) ;
return - V_253 ;
}
if ( V_288 > V_11 -> V_82 ) {
F_8 ( V_32 -> V_21 , L_27 ) ;
return - V_253 ;
}
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
V_60 = F_169 ( V_11 -> V_72 [ V_287 ] . V_58 , V_77 ) ;
F_160 ( V_11 -> V_21 ) ;
if ( V_60 )
return V_60 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
V_2 = & V_11 -> V_18 [ V_14 ] ;
if ( ! V_2 -> V_8 )
continue;
F_25 ( V_2 -> V_8 , V_287 ) -> V_290 = V_288 ;
}
F_46 ( V_8 ) ;
return V_60 ;
}
static int F_170 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
return V_11 -> V_15 . V_291 * V_292 * sizeof( T_1 ) ;
}
static void F_171 ( struct V_7 * V_8 ,
struct V_293 * V_4 , void * V_140 )
{
T_1 * V_101 = V_140 ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_4 -> V_158 = V_11 -> V_158 ;
F_172 ( V_11 -> V_13 , V_101 ) ;
}
static void F_173 ( struct V_7 * V_8 ,
struct V_294 * V_295 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_296 * V_297 = F_174 ( V_11 -> V_21 ) ;
F_175 ( V_295 -> V_298 , L_12 , sizeof( V_295 -> V_298 ) ) ;
F_175 ( V_295 -> V_158 , L_28 , sizeof( V_295 -> V_158 ) ) ;
F_175 ( V_295 -> V_299 , V_297 -> V_166 , sizeof( V_295 -> V_299 ) ) ;
}
static T_1 F_176 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
return V_32 -> V_300 ;
}
static void F_177 ( struct V_7 * V_8 , T_1 V_301 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
V_32 -> V_300 = V_301 ;
}
static int F_178 ( struct V_7 * V_8 ,
struct V_302 * V_295 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_295 -> V_303 =
V_304 |
V_305 |
V_306 |
V_307 |
V_308 |
V_309 ;
V_295 -> V_310 = V_11 -> V_53 -> V_310 ;
V_295 -> V_311 =
( 1 << V_255 ) |
( 1 << V_256 ) ;
V_295 -> V_312 =
( 1 << V_259 ) |
( 1 << V_270 ) ;
return 0 ;
}
static int F_178 ( struct V_7 * V_8 ,
struct V_302 * V_295 )
{
V_295 -> V_303 =
V_305 |
V_307 |
V_308 ;
V_295 -> V_310 = - 1 ;
V_295 -> V_311 = 0 ;
V_295 -> V_312 = 0 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 ,
struct V_313 * V_314 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_275 ] . V_107 )
return F_180 ( V_11 -> V_18 [ V_275 ] . V_107 ,
V_314 ) ;
else
return - V_139 ;
}
static int F_181 ( struct V_7 * V_8 ,
const struct V_313 * V_314 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_275 ] . V_107 )
return F_182 ( V_11 -> V_18 [ V_275 ] . V_107 ,
V_314 ) ;
else
return - V_139 ;
}
static void F_183 ( struct V_7 * V_8 , struct V_315 * V_316 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
V_316 -> V_317 = 0 ;
V_316 -> V_318 = 0 ;
if ( V_11 -> V_18 [ V_275 ] . V_107 )
F_184 ( V_11 -> V_18 [ V_275 ] . V_107 , V_316 ) ;
}
static int F_185 ( struct V_7 * V_8 , struct V_315 * V_316 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_275 ] . V_107 )
return F_186 ( V_11 -> V_18 [ V_275 ] . V_107 , V_316 ) ;
else
return - V_139 ;
}
static void F_187 ( struct V_7 * V_8 ,
struct V_319 * V_320 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
V_320 -> V_321 = V_322 ;
V_320 -> V_113 = V_32 -> V_113 ? true : false ;
V_320 -> V_114 = V_32 -> V_114 ? true : false ;
}
static int F_188 ( struct V_7 * V_8 ,
struct V_319 * V_320 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
bool V_105 ;
V_32 -> V_113 = V_320 -> V_113 ? true : false ;
V_32 -> V_114 = V_320 -> V_114 ? true : false ;
F_75 ( V_32 , F_69 , V_32 , & V_105 ) ;
return 0 ;
}
static int F_189 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_109 ( V_32 , V_323 , L_29 , V_60 ) ;
F_118 ( V_11 -> V_21 ) ;
}
return V_60 ;
}
static void F_190 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
int V_60 ;
V_60 = F_160 ( V_32 -> V_11 -> V_21 ) ;
if ( V_60 < 0 )
F_109 ( V_32 , V_323 , L_30 , V_60 ) ;
}
static void F_191 ( struct V_7 * V_8 ,
struct V_324 * V_58 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_58 -> V_325 = 0 ;
V_58 -> V_326 = V_327 ;
V_58 -> V_328 = V_327 ;
V_58 -> V_329 = 0 ;
V_58 -> V_330 = 0 ;
V_58 -> V_331 = V_11 -> V_83 ;
V_58 -> V_332 = V_11 -> V_80 ;
V_58 -> V_333 = 0 ;
}
static int F_192 ( struct V_10 * V_11 ,
struct V_324 * V_58 )
{
if ( V_58 -> V_333 )
return - V_253 ;
if ( ! V_58 -> V_331 || ! V_58 -> V_332 )
return - V_253 ;
if ( V_58 -> V_331 > V_11 -> V_15 . V_334 ||
V_58 -> V_332 > V_11 -> V_15 . V_334 )
return - V_253 ;
return 0 ;
}
static int F_193 ( struct V_31 * V_32 , int V_141 , int V_335 )
{
int (* F_194)( struct V_95 * , int );
struct V_10 * V_11 = V_32 -> V_11 ;
void (* F_195)( void * , int , int );
struct V_49 * V_287 ;
struct V_71 * V_336 ;
int V_60 , * V_58 ;
if ( V_335 ) {
V_58 = & V_11 -> V_83 ;
V_336 = V_11 -> V_68 ;
F_195 = F_32 ;
F_194 = F_61 ;
} else {
V_58 = & V_11 -> V_80 ;
V_336 = V_11 -> V_72 ;
F_195 = F_24 ;
F_194 = F_55 ;
}
while ( * V_58 < V_141 ) {
V_336 [ * V_58 ] . V_58 = F_196 ( V_11 -> V_45 , * V_58 , F_195 , V_335 ) ;
V_287 = F_25 ( V_32 -> V_8 , * V_58 ) ;
V_287 -> V_290 = 0 ;
if ( F_98 ( V_336 [ * V_58 ] . V_58 ) )
return F_99 ( V_336 [ * V_58 ] . V_58 ) ;
if ( ! V_336 [ * V_58 ] . V_58 )
return - V_253 ;
F_112 ( V_32 , V_206 , L_31 , * V_58 ,
( V_335 ? L_32 : L_33 ) ) ;
( * V_58 ) ++ ;
}
while ( * V_58 > V_141 ) {
( * V_58 ) -- ;
V_60 = F_197 ( V_336 [ * V_58 ] . V_58 ) ;
if ( V_60 )
return V_60 ;
F_112 ( V_32 , V_206 , L_34 , * V_58 ,
( V_335 ? L_32 : L_33 ) ) ;
}
return 0 ;
}
static int F_198 ( struct V_31 * V_32 ,
struct V_324 * V_58 )
{
int V_60 ;
V_60 = F_193 ( V_32 , V_58 -> V_331 , 1 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_193 ( V_32 , V_58 -> V_332 , 0 ) ;
if ( V_60 )
return V_60 ;
return 0 ;
}
static void F_199 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_1 * V_2 ;
int V_14 ;
F_23 ( V_11 ) ;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ ) {
if ( ! ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) ) )
continue;
F_79 ( V_2 -> V_8 ) ;
F_200 ( V_2 -> V_8 ) ;
}
F_128 ( V_11 -> V_45 ) ;
}
static int F_201 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
int V_14 , V_60 ;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ )
if ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) )
F_202 ( V_2 -> V_8 ) ;
if ( V_11 -> V_61 ) {
V_60 = F_106 ( V_32 ) ;
if ( V_60 )
return V_60 ;
F_127 ( V_11 -> V_45 ) ;
F_21 ( V_11 ) ;
}
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ )
if ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) )
F_203 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_204 ( struct V_7 * V_8 ,
struct V_324 * V_337 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
int V_14 , V_60 ;
V_60 = F_192 ( V_11 , V_337 ) ;
if ( V_60 < 0 )
return V_60 ;
F_199 ( V_8 ) ;
V_60 = F_198 ( V_32 , V_337 ) ;
if ( V_60 )
goto V_338;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ ) {
if ( ! ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) ) )
continue;
V_60 = F_119 ( V_2 -> V_8 ,
V_11 -> V_80 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_16 ) ;
goto V_338;
}
V_60 = F_120 ( V_2 -> V_8 ,
V_11 -> V_83 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_17 ) ;
goto V_338;
}
}
if ( V_11 -> V_61 )
F_46 ( V_8 ) ;
V_60 = F_201 ( V_8 ) ;
if ( ! V_60 )
return 0 ;
V_338:
F_8 ( V_32 -> V_21 , L_35 ) ;
F_205 ( V_8 ) ;
return V_60 ;
}
static int F_206 ( struct V_7 * V_8 , struct V_339 * V_340 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_275 ] . V_107 )
return F_207 ( V_11 -> V_18 [ V_275 ] . V_107 , V_340 ) ;
else
return - V_139 ;
}
static int F_208 ( struct V_7 * V_8 , struct V_339 * V_340 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_275 ] . V_107 )
return F_209 ( V_11 -> V_18 [ V_275 ] . V_107 , V_340 ) ;
else
return - V_139 ;
}
static int F_210 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_275 = F_144 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_275 ] . V_107 )
return F_211 ( V_11 -> V_18 [ V_275 ] . V_107 ) ;
else
return - V_139 ;
}
static void F_212 ( struct V_7 * V_8 ,
struct V_341 * V_342 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
V_342 -> V_343 = 0 ;
V_342 -> V_344 = F_213 ( V_11 -> V_45 ) ;
V_342 -> V_345 = V_346 - V_327 ;
V_342 -> V_347 = F_214 ( V_11 -> V_45 ) ;
}
static int F_215 ( struct V_7 * V_8 ,
struct V_341 * V_342 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
if ( V_342 -> V_348 || V_342 -> V_349 ||
V_342 -> V_347 < V_327 ||
V_342 -> V_347 > ( V_346 - V_327 ) )
return - V_253 ;
if ( V_342 -> V_347 == F_214 ( V_11 -> V_45 ) )
return 0 ;
F_199 ( V_8 ) ;
F_216 ( V_11 -> V_45 , V_342 -> V_347 ) ;
if ( V_11 -> V_61 )
F_217 ( V_11 -> V_45 ) ;
V_60 = F_201 ( V_8 ) ;
if ( ! V_60 )
return 0 ;
F_8 ( & V_8 -> V_21 , L_36 ) ;
F_205 ( V_8 ) ;
return V_60 ;
}
static void F_218 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 V_350 , T_1 V_351 )
{
void T_3 * V_4 = V_11 -> V_4 ;
int V_6 = V_2 -> V_6 ;
struct V_352 * V_15 = V_11 -> V_15 . V_353 + V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_4 = V_4 + V_350 ;
V_2 -> V_116 = V_4 + V_351 ;
V_2 -> V_35 = V_15 -> V_354 ;
}
static int F_219 ( struct V_355 * V_15 ,
struct V_296 * V_297 )
{
struct V_356 * V_357 = V_297 -> V_21 . V_358 ;
struct V_356 * V_359 ;
int V_14 = 0 , V_60 ;
T_1 V_360 ;
if ( ! V_357 )
return - V_253 ;
if ( F_220 ( V_357 , L_37 , & V_360 ) ) {
F_8 ( & V_297 -> V_21 , L_38 ) ;
return - V_253 ;
}
V_15 -> V_18 = V_360 ;
if ( F_220 ( V_357 , L_39 , & V_360 ) ) {
F_8 ( & V_297 -> V_21 , L_40 ) ;
return - V_253 ;
}
V_15 -> V_224 = V_360 ;
V_15 -> V_353 = F_221 ( & V_297 -> V_21 , V_15 -> V_18
* sizeof( struct V_352 ) ,
V_205 ) ;
if ( ! V_15 -> V_353 )
return - V_207 ;
if ( F_220 ( V_357 , L_41 , & V_360 ) ) {
F_8 ( & V_297 -> V_21 , L_42 ) ;
return - V_253 ;
}
V_15 -> V_334 = V_360 ;
if ( F_220 ( V_357 , L_43 , & V_360 ) ) {
F_8 ( & V_297 -> V_21 , L_44 ) ;
return - V_253 ;
}
V_15 -> V_291 = V_360 ;
if ( F_220 ( V_357 , L_45 , & V_360 ) ) {
F_8 ( & V_297 -> V_21 , L_46 ) ;
return - V_253 ;
}
V_15 -> V_361 = V_360 ;
if ( F_220 ( V_357 , L_47 , & V_360 ) ) {
F_8 ( & V_297 -> V_21 , L_48 ) ;
return - V_253 ;
}
V_15 -> V_108 = V_360 ;
if ( F_222 ( V_357 , L_49 ) )
V_15 -> V_16 = 1 ;
V_60 = F_223 ( V_357 , NULL , NULL , & V_297 -> V_21 ) ;
if ( V_60 )
F_224 ( & V_297 -> V_21 , L_50 ) ;
F_225 (node, slave_node) {
struct V_352 * V_353 = V_15 -> V_353 + V_14 ;
const void * V_102 = NULL ;
int V_362 ;
const T_8 * V_363 ;
if ( strcmp ( V_359 -> V_166 , L_51 ) )
continue;
V_353 -> V_182 = F_226 ( V_359 ,
L_52 , 0 ) ;
V_363 = F_227 ( V_359 , L_53 , & V_362 ) ;
if ( V_353 -> V_182 ) {
F_10 ( & V_297 -> V_21 ,
L_54 ,
V_14 , V_353 -> V_182 -> V_184 ) ;
} else if ( F_228 ( V_359 ) ) {
V_60 = F_229 ( V_359 ) ;
if ( V_60 ) {
if ( V_60 != - V_364 )
F_8 ( & V_297 -> V_21 , L_55 , V_60 ) ;
return V_60 ;
}
V_353 -> V_182 = F_230 ( V_359 ) ;
} else if ( V_363 ) {
T_1 V_365 ;
struct V_356 * V_366 ;
struct V_296 * V_367 ;
if ( V_362 != ( sizeof( T_8 ) * 2 ) ) {
F_8 ( & V_297 -> V_21 , L_56 , V_14 ) ;
goto V_368;
}
V_366 = F_231 ( F_232 ( V_363 ) ) ;
V_365 = F_232 ( V_363 + 1 ) ;
V_367 = F_233 ( V_366 ) ;
F_234 ( V_366 ) ;
if ( ! V_367 ) {
F_8 ( & V_297 -> V_21 , L_57 ) ;
return - V_253 ;
}
snprintf ( V_353 -> V_185 , sizeof( V_353 -> V_185 ) ,
V_369 , V_367 -> V_166 , V_365 ) ;
F_235 ( & V_367 -> V_21 ) ;
} else {
F_8 ( & V_297 -> V_21 ,
L_58 ,
V_14 ) ;
goto V_368;
}
V_353 -> V_183 = F_236 ( V_359 ) ;
if ( V_353 -> V_183 < 0 ) {
F_8 ( & V_297 -> V_21 , L_59 ,
V_14 ) ;
return V_353 -> V_183 ;
}
V_368:
V_102 = F_237 ( V_359 ) ;
if ( V_102 ) {
memcpy ( V_353 -> V_102 , V_102 , V_282 ) ;
} else {
V_60 = F_238 ( & V_297 -> V_21 , V_14 ,
V_353 -> V_102 ) ;
if ( V_60 )
return V_60 ;
}
if ( V_15 -> V_16 ) {
if ( F_220 ( V_359 , L_60 ,
& V_360 ) ) {
F_8 ( & V_297 -> V_21 , L_61 ) ;
V_353 -> V_354 = V_14 + 1 ;
F_8 ( & V_297 -> V_21 , L_62 ,
V_353 -> V_354 , V_14 ) ;
} else {
V_353 -> V_354 = V_360 ;
}
}
V_14 ++ ;
if ( V_14 == V_15 -> V_18 )
break;
}
return 0 ;
}
static void F_239 ( struct V_296 * V_297 )
{
struct V_7 * V_8 = F_240 ( V_297 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_355 * V_15 = & V_11 -> V_15 ;
struct V_356 * V_357 = V_297 -> V_21 . V_358 ;
struct V_356 * V_359 ;
int V_14 = 0 ;
F_225 (node, slave_node) {
struct V_352 * V_353 = & V_15 -> V_353 [ V_14 ] ;
if ( strcmp ( V_359 -> V_166 , L_51 ) )
continue;
if ( F_228 ( V_359 ) )
F_241 ( V_359 ) ;
F_234 ( V_353 -> V_182 ) ;
V_14 ++ ;
if ( V_14 == V_15 -> V_18 )
break;
}
F_242 ( & V_297 -> V_21 ) ;
}
static int F_243 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_355 * V_15 = & V_11 -> V_15 ;
struct V_7 * V_8 ;
struct V_31 * V_370 ;
int V_60 = 0 ;
V_8 = F_244 ( sizeof( struct V_31 ) , V_327 ) ;
if ( ! V_8 ) {
F_8 ( V_11 -> V_21 , L_63 ) ;
return - V_207 ;
}
V_370 = F_16 ( V_8 ) ;
V_370 -> V_11 = V_11 ;
V_370 -> V_8 = V_8 ;
V_370 -> V_21 = & V_8 -> V_21 ;
V_370 -> V_300 = F_245 ( V_371 , V_372 ) ;
if ( F_158 ( V_15 -> V_353 [ 1 ] . V_102 ) ) {
memcpy ( V_370 -> V_102 , V_15 -> V_353 [ 1 ] . V_102 ,
V_282 ) ;
F_121 ( V_11 -> V_21 , L_64 ,
V_370 -> V_102 ) ;
} else {
F_246 ( V_370 -> V_102 ) ;
F_121 ( V_11 -> V_21 , L_65 ,
V_370 -> V_102 ) ;
}
memcpy ( V_8 -> V_283 , V_370 -> V_102 , V_282 ) ;
V_370 -> V_34 = 1 ;
V_11 -> V_18 [ 1 ] . V_8 = V_8 ;
V_8 -> V_373 |= V_374 ;
V_8 -> V_375 = & V_376 ;
V_8 -> V_377 = & V_378 ;
F_247 ( V_8 , V_11 -> V_21 ) ;
V_60 = F_248 ( V_8 ) ;
if ( V_60 ) {
F_8 ( V_11 -> V_21 , L_66 ) ;
F_249 ( V_8 ) ;
V_60 = - V_379 ;
}
return V_60 ;
}
static int F_250 ( struct V_296 * V_297 )
{
struct V_380 * V_380 ;
struct V_355 * V_15 ;
struct V_7 * V_8 ;
struct V_31 * V_32 ;
struct V_381 V_382 ;
struct V_383 V_384 ;
void T_3 * V_385 ;
void T_3 * V_386 ;
struct V_387 * V_388 , * V_389 ;
const struct V_390 * V_391 ;
struct V_392 * V_393 ;
T_1 V_394 , V_395 , V_396 ;
struct V_10 * V_11 ;
int V_60 = 0 , V_14 ;
int V_84 ;
V_11 = F_221 ( & V_297 -> V_21 , sizeof( struct V_10 ) , V_205 ) ;
if ( ! V_11 )
return - V_207 ;
V_11 -> V_21 = & V_297 -> V_21 ;
V_8 = F_244 ( sizeof( struct V_31 ) , V_327 ) ;
if ( ! V_8 ) {
F_8 ( & V_297 -> V_21 , L_67 ) ;
return - V_207 ;
}
F_251 ( V_297 , V_8 ) ;
V_32 = F_16 ( V_8 ) ;
V_32 -> V_11 = V_11 ;
V_32 -> V_8 = V_8 ;
V_32 -> V_21 = & V_8 -> V_21 ;
V_32 -> V_300 = F_245 ( V_371 , V_372 ) ;
V_11 -> V_63 = F_252 ( V_63 , 128 ) ;
V_393 = F_253 ( & V_297 -> V_21 , L_68 , V_397 ) ;
if ( F_98 ( V_393 ) ) {
V_60 = F_99 ( V_393 ) ;
F_8 ( & V_297 -> V_21 , L_69 , V_60 ) ;
goto V_398;
}
F_254 ( & V_297 -> V_21 ) ;
F_255 ( & V_297 -> V_21 ) ;
V_60 = F_117 ( & V_297 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( & V_297 -> V_21 ) ;
goto V_399;
}
V_60 = F_219 ( & V_11 -> V_15 , V_297 ) ;
if ( V_60 )
goto V_400;
V_15 = & V_11 -> V_15 ;
V_11 -> V_83 = 1 ;
V_11 -> V_80 = 1 ;
if ( F_158 ( V_15 -> V_353 [ 0 ] . V_102 ) ) {
memcpy ( V_32 -> V_102 , V_15 -> V_353 [ 0 ] . V_102 , V_282 ) ;
F_121 ( & V_297 -> V_21 , L_70 , V_32 -> V_102 ) ;
} else {
F_256 ( V_32 -> V_102 ) ;
F_121 ( & V_297 -> V_21 , L_71 , V_32 -> V_102 ) ;
}
memcpy ( V_8 -> V_283 , V_32 -> V_102 , V_282 ) ;
V_11 -> V_18 = F_221 ( & V_297 -> V_21 ,
sizeof( struct V_1 ) * V_15 -> V_18 ,
V_205 ) ;
if ( ! V_11 -> V_18 ) {
V_60 = - V_207 ;
goto V_400;
}
for ( V_14 = 0 ; V_14 < V_15 -> V_18 ; V_14 ++ )
V_11 -> V_18 [ V_14 ] . V_6 = V_14 ;
V_11 -> V_18 [ 0 ] . V_8 = V_8 ;
V_32 -> V_34 = 0 ;
V_380 = F_257 ( & V_297 -> V_21 , L_72 ) ;
if ( F_98 ( V_380 ) ) {
F_8 ( V_32 -> V_21 , L_73 ) ;
V_60 = - V_379 ;
goto V_400;
}
V_11 -> V_126 = F_258 ( V_380 ) / 1000000 ;
V_389 = F_259 ( V_297 , V_401 , 0 ) ;
V_385 = F_260 ( & V_297 -> V_21 , V_389 ) ;
if ( F_98 ( V_385 ) ) {
V_60 = F_99 ( V_385 ) ;
goto V_400;
}
V_11 -> V_4 = V_385 ;
V_11 -> V_158 = F_82 ( & V_11 -> V_4 -> V_402 ) ;
V_388 = F_259 ( V_297 , V_401 , 1 ) ;
V_11 -> V_42 = F_260 ( & V_297 -> V_21 , V_388 ) ;
if ( F_98 ( V_11 -> V_42 ) ) {
V_60 = F_99 ( V_11 -> V_42 ) ;
goto V_400;
}
memset ( & V_382 , 0 , sizeof( V_382 ) ) ;
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
switch ( V_11 -> V_158 ) {
case V_159 :
V_11 -> V_189 = V_385 + V_403 ;
V_386 = V_385 + V_404 ;
V_11 -> V_153 = V_385 + V_405 ;
V_382 . V_406 = V_385 + V_407 ;
V_382 . V_408 = V_385 + V_409 ;
V_384 . V_410 = V_385 + V_411 ;
V_394 = V_412 ;
V_396 = V_413 ;
V_395 = V_414 ;
V_382 . V_415 = 0 ;
break;
case V_175 :
case V_176 :
case V_177 :
V_11 -> V_189 = V_385 + V_416 ;
V_386 = V_385 + V_417 ;
V_11 -> V_153 = V_385 + V_418 ;
V_382 . V_406 = V_385 + V_419 ;
V_382 . V_408 = V_385 + V_420 ;
V_384 . V_410 = V_385 + V_421 ;
V_394 = V_422 ;
V_396 = V_423 ;
V_395 = V_424 ;
V_382 . V_415 =
( T_1 V_425 ) V_389 -> V_426 + V_427 ;
break;
default:
F_8 ( V_32 -> V_21 , L_74 , V_11 -> V_158 ) ;
V_60 = - V_379 ;
goto V_400;
}
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_14 ] ;
F_218 ( V_2 , V_11 , V_394 , V_395 ) ;
V_394 += V_396 ;
V_395 += V_428 ;
}
V_382 . V_21 = & V_297 -> V_21 ;
V_382 . V_429 = V_382 . V_406 + V_430 ;
V_382 . V_431 = V_382 . V_406 + V_432 ;
V_382 . V_433 = V_382 . V_408 + V_434 ;
V_382 . V_435 = V_382 . V_408 + V_436 ;
V_382 . V_437 = V_382 . V_408 + V_438 ;
V_382 . V_439 = V_15 -> V_334 ;
V_382 . V_440 = true ;
V_382 . V_441 = V_214 ;
V_382 . V_442 = V_15 -> V_361 ;
V_382 . V_443 = 16 ;
V_382 . V_444 = true ;
V_382 . V_445 = V_382 . V_415 ;
V_382 . V_126 = V_11 -> V_126 ;
V_382 . V_346 = V_346 ;
V_11 -> V_45 = F_261 ( & V_382 ) ;
if ( ! V_11 -> V_45 ) {
F_8 ( V_32 -> V_21 , L_75 ) ;
V_60 = - V_207 ;
goto V_400;
}
V_11 -> V_72 [ 0 ] . V_58 = F_196 ( V_11 -> V_45 , 0 , F_24 , 0 ) ;
V_11 -> V_68 [ 0 ] . V_58 = F_196 ( V_11 -> V_45 , 0 , F_32 , 1 ) ;
if ( F_45 ( ! V_11 -> V_68 [ 0 ] . V_58 || ! V_11 -> V_72 [ 0 ] . V_58 ) ) {
F_8 ( V_32 -> V_21 , L_76 ) ;
V_60 = - V_207 ;
goto V_446;
}
V_384 . V_21 = & V_297 -> V_21 ;
V_384 . V_447 = V_447 ;
V_384 . V_291 = V_15 -> V_291 ;
V_384 . V_448 = V_15 -> V_18 ;
V_11 -> V_13 = F_262 ( & V_384 ) ;
if ( ! V_11 -> V_13 ) {
F_8 ( V_32 -> V_21 , L_77 ) ;
V_60 = - V_379 ;
goto V_446;
}
V_11 -> V_53 = F_263 ( V_11 -> V_21 , V_386 , V_11 -> V_21 -> V_358 ) ;
if ( F_98 ( V_11 -> V_53 ) ) {
V_60 = F_99 ( V_11 -> V_53 ) ;
goto V_449;
}
V_8 -> V_84 = F_264 ( V_297 , 1 ) ;
if ( V_8 -> V_84 < 0 ) {
F_8 ( V_32 -> V_21 , L_78 ) ;
V_60 = V_8 -> V_84 ;
goto V_449;
}
V_391 = F_265 ( V_450 , & V_297 -> V_21 ) ;
if ( V_391 ) {
V_297 -> V_451 = V_391 -> V_15 ;
if ( V_297 -> V_451 -> V_452 )
V_11 -> V_87 = true ;
}
V_84 = F_264 ( V_297 , 1 ) ;
if ( V_84 < 0 ) {
V_60 = V_84 ;
goto V_449;
}
V_11 -> V_88 [ 0 ] = V_84 ;
V_60 = F_266 ( & V_297 -> V_21 , V_84 , F_54 ,
0 , F_267 ( & V_297 -> V_21 ) , V_11 ) ;
if ( V_60 < 0 ) {
F_8 ( V_32 -> V_21 , L_79 , V_60 ) ;
goto V_449;
}
V_84 = F_264 ( V_297 , 2 ) ;
if ( V_84 < 0 ) {
V_60 = V_84 ;
goto V_449;
}
V_11 -> V_88 [ 1 ] = V_84 ;
V_60 = F_266 ( & V_297 -> V_21 , V_84 , F_49 ,
0 , F_267 ( & V_297 -> V_21 ) , V_11 ) ;
if ( V_60 < 0 ) {
F_8 ( V_32 -> V_21 , L_79 , V_60 ) ;
goto V_449;
}
V_8 -> V_373 |= V_374 ;
V_8 -> V_375 = & V_376 ;
V_8 -> V_377 = & V_378 ;
F_268 ( V_8 , & V_11 -> V_94 , F_61 , V_81 ) ;
F_269 ( V_8 , & V_11 -> V_90 , F_55 , V_81 ) ;
F_46 ( V_8 ) ;
F_247 ( V_8 , & V_297 -> V_21 ) ;
V_60 = F_248 ( V_8 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_80 ) ;
V_60 = - V_379 ;
goto V_449;
}
F_83 ( V_32 , V_453 ,
L_81 ,
& V_389 -> V_426 , V_8 -> V_84 , V_382 . V_346 ) ;
if ( V_11 -> V_15 . V_16 ) {
V_60 = F_243 ( V_32 ) ;
if ( V_60 ) {
F_109 ( V_32 , V_453 , L_82 ) ;
goto V_454;
}
}
F_160 ( & V_297 -> V_21 ) ;
return 0 ;
V_454:
F_270 ( V_8 ) ;
V_449:
F_271 ( V_11 -> V_13 ) ;
V_446:
F_272 ( V_11 -> V_45 ) ;
V_400:
F_239 ( V_297 ) ;
F_129 ( & V_297 -> V_21 ) ;
V_399:
F_273 ( & V_297 -> V_21 ) ;
V_398:
F_249 ( V_32 -> V_8 ) ;
return V_60 ;
}
static int F_274 ( struct V_296 * V_297 )
{
struct V_7 * V_8 = F_240 ( V_297 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
int V_60 ;
V_60 = F_117 ( & V_297 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( & V_297 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 )
F_270 ( V_11 -> V_18 [ 1 ] . V_8 ) ;
F_270 ( V_8 ) ;
F_275 ( V_11 -> V_53 ) ;
F_271 ( V_11 -> V_13 ) ;
F_272 ( V_11 -> V_45 ) ;
F_239 ( V_297 ) ;
F_129 ( & V_297 -> V_21 ) ;
F_273 ( & V_297 -> V_21 ) ;
if ( V_11 -> V_15 . V_16 )
F_249 ( V_11 -> V_18 [ 1 ] . V_8 ) ;
F_249 ( V_8 ) ;
return 0 ;
}
static int F_276 ( struct V_455 * V_21 )
{
struct V_296 * V_297 = F_174 ( V_21 ) ;
struct V_7 * V_8 = F_240 ( V_297 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( F_34 ( V_11 -> V_18 [ V_14 ] . V_8 ) )
F_130 ( V_11 -> V_18 [ V_14 ] . V_8 ) ;
}
} else {
if ( F_34 ( V_8 ) )
F_130 ( V_8 ) ;
}
F_277 ( V_21 ) ;
return 0 ;
}
static int F_278 ( struct V_455 * V_21 )
{
struct V_296 * V_297 = F_174 ( V_21 ) ;
struct V_7 * V_8 = F_240 ( V_297 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
F_255 ( V_21 ) ;
F_279 () ;
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( F_34 ( V_11 -> V_18 [ V_14 ] . V_8 ) )
F_116 ( V_11 -> V_18 [ V_14 ] . V_8 ) ;
}
} else {
if ( F_34 ( V_8 ) )
F_116 ( V_8 ) ;
}
F_280 () ;
return 0 ;
}
