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
F_90 ( V_52 ) ;
return F_43 ( V_155 , V_52 , V_52 -> V_15 , V_52 -> V_47 ,
V_32 -> V_34 + V_11 -> V_15 . V_16 ) ;
}
static inline void F_91 (
struct V_31 * V_32 , struct V_1 * V_2 ,
T_1 V_109 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
T_1 V_156 = 1 << V_109 | V_157 ;
if ( V_11 -> V_158 == V_159 )
F_3 ( V_2 , V_2 -> V_35 , V_160 ) ;
else
F_3 ( V_2 , V_2 -> V_35 , V_161 ) ;
F_92 ( V_11 -> V_13 , V_2 -> V_35 , V_156 ,
V_156 , V_156 , 0 ) ;
F_93 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
V_156 , V_163 , V_2 -> V_35 , 0 ) ;
F_94 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 |
V_165 , V_2 -> V_35 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
char V_166 [ 32 ] ;
snprintf ( V_166 , sizeof( V_166 ) , L_9 , V_2 -> V_6 ) ;
F_64 ( V_166 , & V_2 -> V_116 -> F_64 ) ;
}
static void F_96 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
T_1 V_109 ;
struct V_106 * V_107 ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_95 ( V_2 ) ;
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
F_91 ( V_32 , V_2 , V_109 ) ;
else
F_93 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
1 << V_109 , 0 , 0 , V_181 ) ;
if ( V_2 -> V_15 -> V_182 ) {
V_107 = F_97 ( V_32 -> V_8 , V_2 -> V_15 -> V_182 ,
& F_74 , 0 , V_2 -> V_15 -> V_183 ) ;
if ( ! V_107 ) {
F_8 ( V_32 -> V_21 , L_10 ,
V_2 -> V_15 -> V_182 -> V_184 ,
V_2 -> V_6 ) ;
return;
}
} else {
V_107 = F_98 ( V_32 -> V_8 , V_2 -> V_15 -> V_185 ,
& F_74 , V_2 -> V_15 -> V_183 ) ;
if ( F_99 ( V_107 ) ) {
F_8 ( V_32 -> V_21 ,
L_11 ,
V_2 -> V_15 -> V_185 , V_2 -> V_6 ,
F_100 ( V_107 ) ) ;
return;
}
}
V_2 -> V_107 = V_107 ;
F_101 ( V_2 -> V_107 ) ;
F_102 ( V_2 -> V_107 ) ;
F_103 ( V_11 -> V_21 , V_2 -> V_107 -> V_186 , V_2 -> V_6 ) ;
}
static inline void F_104 ( struct V_31 * V_32 )
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
F_92 ( V_11 -> V_13 , V_187 , V_29 ,
V_29 , V_29 ,
V_188 ) ;
}
static void F_105 ( struct V_31 * V_32 )
{
T_1 V_192 ;
T_1 V_193 ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_64 ( L_12 , & V_11 -> V_4 -> F_64 ) ;
F_106 ( V_11 -> V_13 ) ;
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
F_94 ( V_11 -> V_13 , V_32 -> V_102 , V_164 ,
0 , 0 ) ;
F_93 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
V_157 , 0 , 0 , V_181 ) ;
}
}
static int F_107 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_51 * V_52 ;
int V_204 ;
int V_58 , V_14 , V_60 ;
for ( V_58 = 0 ; V_58 < V_11 -> V_83 ; V_58 ++ ) {
V_204 = F_108 ( V_11 -> V_68 [ V_58 ] . V_58 ) ;
for ( V_14 = 0 ; V_14 < V_204 ; V_14 ++ ) {
V_52 = F_109 ( V_32 -> V_8 ,
V_11 -> V_63 ,
V_205 ) ;
if ( ! V_52 ) {
F_110 ( V_32 , V_206 , L_13 ) ;
return - V_207 ;
}
F_111 ( V_52 , V_58 ) ;
V_60 = F_43 ( V_11 -> V_68 [ V_58 ] . V_58 , V_52 ,
V_52 -> V_15 , F_44 ( V_52 ) ,
0 ) ;
if ( V_60 < 0 ) {
F_110 ( V_32 , V_206 ,
L_14 ,
V_58 , V_60 ) ;
F_112 ( V_52 ) ;
return V_60 ;
}
F_41 ( V_52 ) ;
}
F_113 ( V_32 , V_206 , L_15 ,
V_58 , V_204 ) ;
}
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
T_1 V_109 ;
V_109 = F_5 ( V_2 -> V_6 ) ;
if ( ! V_2 -> V_107 )
return;
F_115 ( V_2 -> V_107 ) ;
F_116 ( V_2 -> V_107 ) ;
V_2 -> V_107 = NULL ;
F_9 ( V_11 -> V_13 , V_109 ,
V_110 , V_115 ) ;
F_95 ( V_2 ) ;
}
static int F_117 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
T_1 V_101 ;
V_60 = F_118 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_119 ( V_11 -> V_21 ) ;
return V_60 ;
}
F_78 ( V_8 ) ;
V_60 = F_120 ( V_8 , V_11 -> V_80 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_16 ) ;
goto V_208;
}
V_60 = F_121 ( V_8 , V_11 -> V_83 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_17 ) ;
goto V_208;
}
V_101 = V_11 -> V_158 ;
F_122 ( V_32 -> V_21 , L_18 ,
F_123 ( V_101 ) , F_124 ( V_101 ) ,
F_125 ( V_101 ) ) ;
if ( ! V_11 -> V_61 )
F_105 ( V_32 ) ;
F_75 ( V_32 , F_96 , V_32 ) ;
if ( ! V_11 -> V_15 . V_16 )
F_104 ( V_32 ) ;
else
F_92 ( V_11 -> V_13 , V_11 -> V_15 . V_36 ,
V_29 , V_29 , 0 , 0 ) ;
if ( ! V_11 -> V_61 ) {
F_4 ( 0 , & V_11 -> V_4 -> V_209 ) ;
F_4 ( 0x7 , & V_11 -> V_4 -> V_210 ) ;
F_50 ( 0x7 , & V_11 -> V_4 -> V_211 ) ;
F_126 ( & V_11 -> V_94 ) ;
F_126 ( & V_11 -> V_90 ) ;
if ( V_11 -> V_89 ) {
V_11 -> V_89 = false ;
F_60 ( V_11 -> V_88 [ 1 ] ) ;
}
if ( V_11 -> V_93 ) {
V_11 -> V_93 = false ;
F_60 ( V_11 -> V_88 [ 0 ] ) ;
}
V_60 = F_107 ( V_32 ) ;
if ( V_60 < 0 )
goto V_208;
if ( F_127 ( V_11 -> V_53 ) )
F_8 ( V_32 -> V_21 , L_19 ) ;
}
if ( V_11 -> V_120 != 0 ) {
struct V_117 V_118 ;
V_118 . V_119 = V_11 -> V_120 ;
F_81 ( V_8 , & V_118 ) ;
}
F_128 ( V_11 -> V_45 ) ;
F_21 ( V_11 ) ;
V_11 -> V_61 ++ ;
return 0 ;
V_208:
F_129 ( V_11 -> V_45 ) ;
F_75 ( V_32 , F_114 , V_11 ) ;
F_130 ( V_11 -> V_21 ) ;
F_78 ( V_32 -> V_8 ) ;
return V_60 ;
}
static int F_131 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_113 ( V_32 , V_212 , L_20 ) ;
F_79 ( V_32 -> V_8 ) ;
F_78 ( V_32 -> V_8 ) ;
if ( V_11 -> V_61 <= 1 ) {
F_132 ( & V_11 -> V_94 ) ;
F_132 ( & V_11 -> V_90 ) ;
F_133 ( V_11 -> V_53 ) ;
F_23 ( V_11 ) ;
F_129 ( V_11 -> V_45 ) ;
F_134 ( V_11 -> V_13 ) ;
}
F_75 ( V_32 , F_114 , V_11 ) ;
if ( F_73 ( V_11 ) )
F_46 ( V_8 ) ;
V_11 -> V_61 -- ;
F_130 ( V_11 -> V_21 ) ;
return 0 ;
}
static T_5 F_135 ( struct V_51 * V_52 ,
struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_53 * V_53 = V_11 -> V_53 ;
struct V_49 * V_50 ;
struct V_57 * V_155 ;
int V_60 , V_213 ;
if ( F_136 ( V_52 , V_214 ) ) {
F_110 ( V_32 , V_215 , L_21 ) ;
V_8 -> V_54 . V_216 ++ ;
return V_217 ;
}
if ( F_137 ( V_52 ) -> V_218 & V_219 &&
F_138 ( V_53 ) && F_139 ( V_53 , V_52 ) )
F_137 ( V_52 ) -> V_218 |= V_220 ;
V_213 = F_26 ( V_52 ) ;
if ( V_213 >= V_11 -> V_80 )
V_213 = V_213 % V_11 -> V_80 ;
V_155 = V_11 -> V_72 [ V_213 ] . V_58 ;
V_60 = F_89 ( V_32 , V_52 , V_155 ) ;
if ( F_27 ( V_60 != 0 ) ) {
F_110 ( V_32 , V_215 , L_22 ) ;
goto V_221;
}
if ( F_27 ( ! F_140 ( V_155 ) ) ) {
V_50 = F_25 ( V_8 , V_213 ) ;
F_141 ( V_50 ) ;
}
return V_222 ;
V_221:
V_8 -> V_54 . V_216 ++ ;
V_50 = F_25 ( V_8 , F_26 ( V_52 ) ) ;
F_141 ( V_50 ) ;
return V_223 ;
}
static void F_142 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_18 [ V_11 -> V_15 . V_224 ] ;
T_1 V_225 , V_226 ;
if ( ! F_138 ( V_11 -> V_53 ) &&
! F_143 ( V_11 -> V_53 ) ) {
F_3 ( V_2 , 0 , V_227 ) ;
return;
}
V_226 = ( 30 << V_228 ) | V_229 ;
V_225 = V_230 << V_231 ;
if ( F_138 ( V_11 -> V_53 ) )
V_225 |= V_232 ;
if ( F_143 ( V_11 -> V_53 ) )
V_225 |= V_233 ;
F_3 ( V_2 , V_225 , V_227 ) ;
F_3 ( V_2 , V_226 , V_234 ) ;
}
static void F_144 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = V_32 -> V_11 ;
T_1 V_235 , V_236 ;
V_2 = & V_11 -> V_18 [ F_145 ( V_11 , V_32 ) ] ;
V_235 = F_1 ( V_2 , V_237 ) ;
switch ( V_11 -> V_158 ) {
case V_175 :
V_235 &= ~ V_238 ;
if ( F_138 ( V_11 -> V_53 ) )
V_235 |= V_239 ;
if ( F_143 ( V_11 -> V_53 ) )
V_235 |= V_240 ;
break;
case V_176 :
default:
V_235 &= ~ V_241 ;
if ( F_138 ( V_11 -> V_53 ) )
V_235 |= V_242 ;
if ( F_143 ( V_11 -> V_53 ) )
V_235 |= V_243 ;
break;
}
V_236 = ( 30 << V_244 ) | V_230 ;
F_3 ( V_2 , V_236 , V_245 ) ;
F_3 ( V_2 , V_235 , V_237 ) ;
F_4 ( V_229 , & V_11 -> V_4 -> V_246 ) ;
}
static int F_146 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
struct V_31 * V_32 = F_16 ( V_21 ) ;
struct V_249 V_250 ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_53 * V_53 = V_11 -> V_53 ;
if ( V_11 -> V_158 != V_159 &&
V_11 -> V_158 != V_175 &&
V_11 -> V_158 != V_176 )
return - V_139 ;
if ( F_147 ( & V_250 , V_248 -> V_251 , sizeof( V_250 ) ) )
return - V_252 ;
if ( V_250 . V_19 )
return - V_253 ;
if ( V_250 . V_254 != V_255 && V_250 . V_254 != V_256 )
return - V_257 ;
switch ( V_250 . V_258 ) {
case V_259 :
F_148 ( V_53 , 0 ) ;
break;
case V_260 :
case V_261 :
return - V_257 ;
case V_262 :
case V_263 :
case V_264 :
F_148 ( V_53 , V_262 ) ;
V_250 . V_258 = V_262 ;
break;
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
F_148 ( V_53 , V_271 ) ;
V_250 . V_258 = V_271 ;
break;
default:
return - V_257 ;
}
F_149 ( V_53 , V_250 . V_254 == V_256 ) ;
switch ( V_11 -> V_158 ) {
case V_159 :
F_142 ( V_11 ) ;
break;
case V_175 :
case V_176 :
F_144 ( V_32 ) ;
break;
default:
F_45 ( 1 ) ;
}
return F_150 ( V_248 -> V_251 , & V_250 , sizeof( V_250 ) ) ? - V_252 : 0 ;
}
static int F_151 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
struct V_53 * V_53 = V_11 -> V_53 ;
struct V_249 V_250 ;
if ( V_11 -> V_158 != V_159 &&
V_11 -> V_158 != V_175 &&
V_11 -> V_158 != V_176 )
return - V_139 ;
V_250 . V_19 = 0 ;
V_250 . V_254 = F_138 ( V_53 ) ?
V_256 : V_255 ;
V_250 . V_258 = ( F_143 ( V_53 ) ?
V_53 -> V_274 : V_259 ) ;
return F_150 ( V_248 -> V_251 , & V_250 , sizeof( V_250 ) ) ? - V_252 : 0 ;
}
static int F_151 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
return - V_139 ;
}
static int F_146 ( struct V_7 * V_21 , struct V_247 * V_248 )
{
return - V_139 ;
}
static int F_152 ( struct V_7 * V_21 , struct V_247 * V_275 , int V_276 )
{
struct V_31 * V_32 = F_16 ( V_21 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
if ( ! F_34 ( V_21 ) )
return - V_253 ;
switch ( V_276 ) {
case V_278 :
return F_146 ( V_21 , V_275 ) ;
case V_279 :
return F_151 ( V_21 , V_275 ) ;
}
if ( ! V_11 -> V_18 [ V_277 ] . V_107 )
return - V_139 ;
return F_153 ( V_11 -> V_18 [ V_277 ] . V_107 , V_275 , V_276 ) ;
}
static void F_154 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_58 ;
F_110 ( V_32 , V_215 , L_23 ) ;
V_8 -> V_54 . V_280 ++ ;
F_23 ( V_11 ) ;
for ( V_58 = 0 ; V_58 < V_11 -> V_80 ; V_58 ++ ) {
F_155 ( V_11 -> V_72 [ V_58 ] . V_58 ) ;
F_156 ( V_11 -> V_72 [ V_58 ] . V_58 ) ;
}
F_21 ( V_11 ) ;
F_157 ( V_8 ) ;
F_77 ( V_8 ) ;
}
static int F_158 ( struct V_7 * V_8 , void * V_140 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_281 * V_41 = (struct V_281 * ) V_140 ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_19 = 0 ;
T_6 V_33 = 0 ;
int V_60 ;
if ( ! F_159 ( V_41 -> V_282 ) )
return - V_283 ;
V_60 = F_118 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_119 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 ) {
V_33 = V_11 -> V_18 [ V_32 -> V_34 ] . V_35 ;
V_19 = V_163 ;
}
F_160 ( V_11 -> V_13 , V_32 -> V_102 , V_164 ,
V_19 , V_33 ) ;
F_94 ( V_11 -> V_13 , V_41 -> V_282 , V_164 ,
V_19 , V_33 ) ;
memcpy ( V_32 -> V_102 , V_41 -> V_282 , V_284 ) ;
memcpy ( V_8 -> V_285 , V_32 -> V_102 , V_284 ) ;
F_75 ( V_32 , F_66 , V_32 ) ;
F_161 ( V_11 -> V_21 ) ;
return 0 ;
}
static void F_162 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
F_23 ( V_11 ) ;
F_54 ( V_11 -> V_88 [ 0 ] , V_11 ) ;
F_49 ( V_11 -> V_88 [ 1 ] , V_11 ) ;
F_21 ( V_11 ) ;
}
static inline int F_163 ( struct V_31 * V_32 ,
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
V_60 = F_92 ( V_11 -> V_13 , V_33 , V_156 , 0 , V_156 ,
V_188 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_94 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 , V_33 ) ;
if ( V_60 != 0 )
goto V_286;
V_60 = F_93 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
V_156 , V_163 , V_33 , 0 ) ;
if ( V_60 != 0 )
goto V_287;
return 0 ;
V_287:
F_160 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 , V_33 ) ;
V_286:
F_164 ( V_11 -> V_13 , V_33 , 0 ) ;
return V_60 ;
}
static int F_165 ( struct V_7 * V_8 ,
T_7 V_288 , T_6 V_33 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
if ( V_33 == V_11 -> V_15 . V_36 )
return 0 ;
V_60 = F_118 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_119 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( V_33 == V_11 -> V_18 [ V_14 ] . V_35 )
return - V_253 ;
}
}
F_122 ( V_32 -> V_21 , L_24 , V_33 ) ;
V_60 = F_163 ( V_32 , V_33 ) ;
F_161 ( V_11 -> V_21 ) ;
return V_60 ;
}
static int F_166 ( struct V_7 * V_8 ,
T_7 V_288 , T_6 V_33 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
if ( V_33 == V_11 -> V_15 . V_36 )
return 0 ;
V_60 = F_118 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_119 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( V_33 == V_11 -> V_18 [ V_14 ] . V_35 )
return - V_253 ;
}
}
F_122 ( V_32 -> V_21 , L_25 , V_33 ) ;
V_60 = F_164 ( V_11 -> V_13 , V_33 , 0 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_160 ( V_11 -> V_13 , V_32 -> V_102 ,
V_164 , V_163 , V_33 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_167 ( V_11 -> V_13 , V_32 -> V_8 -> V_162 ,
0 , V_163 , V_33 ) ;
F_161 ( V_11 -> V_21 ) ;
return V_60 ;
}
static int F_168 ( struct V_7 * V_8 , int V_289 , T_1 V_290 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
T_1 V_291 ;
T_1 V_77 ;
int V_14 , V_60 ;
V_77 = F_25 ( V_8 , V_289 ) -> V_292 ;
if ( V_77 == V_290 )
return 0 ;
V_77 = V_290 * 1000 ;
V_291 = F_169 ( V_11 -> V_45 ) ;
if ( ( V_77 < V_291 && V_77 ) ) {
F_8 ( V_32 -> V_21 , L_26 ,
V_291 ) ;
return - V_253 ;
}
if ( V_290 > V_11 -> V_82 ) {
F_8 ( V_32 -> V_21 , L_27 ) ;
return - V_253 ;
}
V_60 = F_118 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_119 ( V_11 -> V_21 ) ;
return V_60 ;
}
V_60 = F_170 ( V_11 -> V_72 [ V_289 ] . V_58 , V_77 ) ;
F_161 ( V_11 -> V_21 ) ;
if ( V_60 )
return V_60 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
V_2 = & V_11 -> V_18 [ V_14 ] ;
if ( ! V_2 -> V_8 )
continue;
F_25 ( V_2 -> V_8 , V_289 ) -> V_292 = V_290 ;
}
F_46 ( V_8 ) ;
return V_60 ;
}
static int F_171 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
return V_11 -> V_15 . V_293 * V_294 * sizeof( T_1 ) ;
}
static void F_172 ( struct V_7 * V_8 ,
struct V_295 * V_4 , void * V_140 )
{
T_1 * V_101 = V_140 ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_4 -> V_158 = V_11 -> V_158 ;
F_173 ( V_11 -> V_13 , V_101 ) ;
}
static void F_174 ( struct V_7 * V_8 ,
struct V_296 * V_297 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_298 * V_299 = F_175 ( V_11 -> V_21 ) ;
F_176 ( V_297 -> V_300 , L_12 , sizeof( V_297 -> V_300 ) ) ;
F_176 ( V_297 -> V_158 , L_28 , sizeof( V_297 -> V_158 ) ) ;
F_176 ( V_297 -> V_301 , V_299 -> V_166 , sizeof( V_297 -> V_301 ) ) ;
}
static T_1 F_177 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
return V_32 -> V_302 ;
}
static void F_178 ( struct V_7 * V_8 , T_1 V_303 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
V_32 -> V_302 = V_303 ;
}
static int F_179 ( struct V_7 * V_8 ,
struct V_304 * V_297 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_297 -> V_305 =
V_306 |
V_307 |
V_308 |
V_309 |
V_310 |
V_311 ;
V_297 -> V_312 = V_11 -> V_53 -> V_312 ;
V_297 -> V_313 =
( 1 << V_255 ) |
( 1 << V_256 ) ;
V_297 -> V_314 =
( 1 << V_259 ) |
( 1 << V_262 ) |
( 1 << V_271 ) ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 ,
struct V_304 * V_297 )
{
V_297 -> V_305 =
V_307 |
V_309 |
V_310 ;
V_297 -> V_312 = - 1 ;
V_297 -> V_313 = 0 ;
V_297 -> V_314 = 0 ;
return 0 ;
}
static int F_180 ( struct V_7 * V_8 ,
struct V_315 * V_316 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
if ( ! V_11 -> V_18 [ V_277 ] . V_107 )
return - V_139 ;
F_181 ( V_11 -> V_18 [ V_277 ] . V_107 , V_316 ) ;
return 0 ;
}
static int F_182 ( struct V_7 * V_8 ,
const struct V_315 * V_316 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_277 ] . V_107 )
return F_183 ( V_11 -> V_18 [ V_277 ] . V_107 ,
V_316 ) ;
else
return - V_139 ;
}
static void F_184 ( struct V_7 * V_8 , struct V_317 * V_318 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
V_318 -> V_319 = 0 ;
V_318 -> V_320 = 0 ;
if ( V_11 -> V_18 [ V_277 ] . V_107 )
F_185 ( V_11 -> V_18 [ V_277 ] . V_107 , V_318 ) ;
}
static int F_186 ( struct V_7 * V_8 , struct V_317 * V_318 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_277 ] . V_107 )
return F_187 ( V_11 -> V_18 [ V_277 ] . V_107 , V_318 ) ;
else
return - V_139 ;
}
static void F_188 ( struct V_7 * V_8 ,
struct V_321 * V_322 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
V_322 -> V_323 = V_324 ;
V_322 -> V_113 = V_32 -> V_113 ? true : false ;
V_322 -> V_114 = V_32 -> V_114 ? true : false ;
}
static int F_189 ( struct V_7 * V_8 ,
struct V_321 * V_322 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
bool V_105 ;
V_32 -> V_113 = V_322 -> V_113 ? true : false ;
V_32 -> V_114 = V_322 -> V_114 ? true : false ;
F_75 ( V_32 , F_69 , V_32 , & V_105 ) ;
return 0 ;
}
static int F_190 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
V_60 = F_118 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_110 ( V_32 , V_325 , L_29 , V_60 ) ;
F_119 ( V_11 -> V_21 ) ;
}
return V_60 ;
}
static void F_191 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
int V_60 ;
V_60 = F_161 ( V_32 -> V_11 -> V_21 ) ;
if ( V_60 < 0 )
F_110 ( V_32 , V_325 , L_30 , V_60 ) ;
}
static void F_192 ( struct V_7 * V_8 ,
struct V_326 * V_58 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_58 -> V_327 = 0 ;
V_58 -> V_328 = V_329 ;
V_58 -> V_330 = V_329 ;
V_58 -> V_331 = 0 ;
V_58 -> V_332 = 0 ;
V_58 -> V_333 = V_11 -> V_83 ;
V_58 -> V_334 = V_11 -> V_80 ;
V_58 -> V_335 = 0 ;
}
static int F_193 ( struct V_10 * V_11 ,
struct V_326 * V_58 )
{
if ( V_58 -> V_335 )
return - V_253 ;
if ( ! V_58 -> V_333 || ! V_58 -> V_334 )
return - V_253 ;
if ( V_58 -> V_333 > V_11 -> V_15 . V_336 ||
V_58 -> V_334 > V_11 -> V_15 . V_336 )
return - V_253 ;
return 0 ;
}
static int F_194 ( struct V_31 * V_32 , int V_141 , int V_337 )
{
int (* F_195)( struct V_95 * , int );
struct V_10 * V_11 = V_32 -> V_11 ;
void (* F_196)( void * , int , int );
struct V_49 * V_289 ;
struct V_71 * V_338 ;
int V_60 , * V_58 ;
if ( V_337 ) {
V_58 = & V_11 -> V_83 ;
V_338 = V_11 -> V_68 ;
F_196 = F_32 ;
F_195 = F_61 ;
} else {
V_58 = & V_11 -> V_80 ;
V_338 = V_11 -> V_72 ;
F_196 = F_24 ;
F_195 = F_55 ;
}
while ( * V_58 < V_141 ) {
V_338 [ * V_58 ] . V_58 = F_197 ( V_11 -> V_45 , * V_58 , F_196 , V_337 ) ;
V_289 = F_25 ( V_32 -> V_8 , * V_58 ) ;
V_289 -> V_292 = 0 ;
if ( F_99 ( V_338 [ * V_58 ] . V_58 ) )
return F_100 ( V_338 [ * V_58 ] . V_58 ) ;
if ( ! V_338 [ * V_58 ] . V_58 )
return - V_253 ;
F_113 ( V_32 , V_206 , L_31 , * V_58 ,
( V_337 ? L_32 : L_33 ) ) ;
( * V_58 ) ++ ;
}
while ( * V_58 > V_141 ) {
( * V_58 ) -- ;
V_60 = F_198 ( V_338 [ * V_58 ] . V_58 ) ;
if ( V_60 )
return V_60 ;
F_113 ( V_32 , V_206 , L_34 , * V_58 ,
( V_337 ? L_32 : L_33 ) ) ;
}
return 0 ;
}
static int F_199 ( struct V_31 * V_32 ,
struct V_326 * V_58 )
{
int V_60 ;
V_60 = F_194 ( V_32 , V_58 -> V_333 , 1 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_194 ( V_32 , V_58 -> V_334 , 0 ) ;
if ( V_60 )
return V_60 ;
return 0 ;
}
static void F_200 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_1 * V_2 ;
int V_14 ;
F_23 ( V_11 ) ;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ ) {
if ( ! ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) ) )
continue;
F_79 ( V_2 -> V_8 ) ;
F_201 ( V_2 -> V_8 ) ;
}
F_129 ( V_11 -> V_45 ) ;
}
static int F_202 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
int V_14 , V_60 ;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ )
if ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) )
F_203 ( V_2 -> V_8 ) ;
if ( V_11 -> V_61 ) {
V_60 = F_107 ( V_32 ) ;
if ( V_60 )
return V_60 ;
F_128 ( V_11 -> V_45 ) ;
F_21 ( V_11 ) ;
}
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ )
if ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) )
F_204 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_205 ( struct V_7 * V_8 ,
struct V_326 * V_339 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
int V_14 , V_60 ;
V_60 = F_193 ( V_11 , V_339 ) ;
if ( V_60 < 0 )
return V_60 ;
F_200 ( V_8 ) ;
V_60 = F_199 ( V_32 , V_339 ) ;
if ( V_60 )
goto V_340;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ ) {
if ( ! ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) ) )
continue;
V_60 = F_120 ( V_2 -> V_8 ,
V_11 -> V_80 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_16 ) ;
goto V_340;
}
V_60 = F_121 ( V_2 -> V_8 ,
V_11 -> V_83 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_17 ) ;
goto V_340;
}
}
if ( V_11 -> V_61 )
F_46 ( V_8 ) ;
V_60 = F_202 ( V_8 ) ;
if ( ! V_60 )
return 0 ;
V_340:
F_8 ( V_32 -> V_21 , L_35 ) ;
F_206 ( V_8 ) ;
return V_60 ;
}
static int F_207 ( struct V_7 * V_8 , struct V_341 * V_342 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_277 ] . V_107 )
return F_208 ( V_11 -> V_18 [ V_277 ] . V_107 , V_342 ) ;
else
return - V_139 ;
}
static int F_209 ( struct V_7 * V_8 , struct V_341 * V_342 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_277 ] . V_107 )
return F_210 ( V_11 -> V_18 [ V_277 ] . V_107 , V_342 ) ;
else
return - V_139 ;
}
static int F_211 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_277 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_277 ] . V_107 )
return F_212 ( V_11 -> V_18 [ V_277 ] . V_107 ) ;
else
return - V_139 ;
}
static void F_213 ( struct V_7 * V_8 ,
struct V_343 * V_344 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
V_344 -> V_345 = 0 ;
V_344 -> V_346 = F_214 ( V_11 -> V_45 ) ;
V_344 -> V_347 = V_348 - V_329 ;
V_344 -> V_349 = F_215 ( V_11 -> V_45 ) ;
}
static int F_216 ( struct V_7 * V_8 ,
struct V_343 * V_344 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
if ( V_344 -> V_350 || V_344 -> V_351 ||
V_344 -> V_349 < V_329 ||
V_344 -> V_349 > ( V_348 - V_329 ) )
return - V_253 ;
if ( V_344 -> V_349 == F_215 ( V_11 -> V_45 ) )
return 0 ;
F_200 ( V_8 ) ;
F_217 ( V_11 -> V_45 , V_344 -> V_349 ) ;
if ( V_11 -> V_61 )
F_218 ( V_11 -> V_45 ) ;
V_60 = F_202 ( V_8 ) ;
if ( ! V_60 )
return 0 ;
F_8 ( & V_8 -> V_21 , L_36 ) ;
F_206 ( V_8 ) ;
return V_60 ;
}
static void F_219 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 V_352 , T_1 V_353 )
{
void T_3 * V_4 = V_11 -> V_4 ;
int V_6 = V_2 -> V_6 ;
struct V_354 * V_15 = V_11 -> V_15 . V_355 + V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_4 = V_4 + V_352 ;
V_2 -> V_116 = V_4 + V_353 ;
V_2 -> V_35 = V_15 -> V_356 ;
}
static int F_220 ( struct V_357 * V_15 ,
struct V_298 * V_299 )
{
struct V_358 * V_359 = V_299 -> V_21 . V_360 ;
struct V_358 * V_361 ;
int V_14 = 0 , V_60 ;
T_1 V_362 ;
if ( ! V_359 )
return - V_253 ;
if ( F_221 ( V_359 , L_37 , & V_362 ) ) {
F_8 ( & V_299 -> V_21 , L_38 ) ;
return - V_253 ;
}
V_15 -> V_18 = V_362 ;
if ( F_221 ( V_359 , L_39 , & V_362 ) ) {
F_8 ( & V_299 -> V_21 , L_40 ) ;
return - V_253 ;
}
V_15 -> V_224 = V_362 ;
V_15 -> V_355 = F_222 ( & V_299 -> V_21 , V_15 -> V_18
* sizeof( struct V_354 ) ,
V_205 ) ;
if ( ! V_15 -> V_355 )
return - V_207 ;
if ( F_221 ( V_359 , L_41 , & V_362 ) ) {
F_8 ( & V_299 -> V_21 , L_42 ) ;
return - V_253 ;
}
V_15 -> V_336 = V_362 ;
if ( F_221 ( V_359 , L_43 , & V_362 ) ) {
F_8 ( & V_299 -> V_21 , L_44 ) ;
return - V_253 ;
}
V_15 -> V_293 = V_362 ;
if ( F_221 ( V_359 , L_45 , & V_362 ) ) {
F_8 ( & V_299 -> V_21 , L_46 ) ;
return - V_253 ;
}
V_15 -> V_363 = V_362 ;
if ( F_221 ( V_359 , L_47 , & V_362 ) ) {
F_8 ( & V_299 -> V_21 , L_48 ) ;
return - V_253 ;
}
V_15 -> V_108 = V_362 ;
if ( F_223 ( V_359 , L_49 ) )
V_15 -> V_16 = 1 ;
V_60 = F_224 ( V_359 , NULL , NULL , & V_299 -> V_21 ) ;
if ( V_60 )
F_225 ( & V_299 -> V_21 , L_50 ) ;
F_226 (node, slave_node) {
struct V_354 * V_355 = V_15 -> V_355 + V_14 ;
const void * V_102 = NULL ;
int V_364 ;
const T_8 * V_365 ;
if ( strcmp ( V_361 -> V_166 , L_51 ) )
continue;
V_355 -> V_182 = F_227 ( V_361 ,
L_52 , 0 ) ;
V_365 = F_228 ( V_361 , L_53 , & V_364 ) ;
if ( V_355 -> V_182 ) {
F_10 ( & V_299 -> V_21 ,
L_54 ,
V_14 , V_355 -> V_182 -> V_184 ) ;
} else if ( F_229 ( V_361 ) ) {
V_60 = F_230 ( V_361 ) ;
if ( V_60 ) {
if ( V_60 != - V_366 )
F_8 ( & V_299 -> V_21 , L_55 , V_60 ) ;
return V_60 ;
}
V_355 -> V_182 = F_231 ( V_361 ) ;
} else if ( V_365 ) {
T_1 V_367 ;
struct V_358 * V_368 ;
struct V_298 * V_369 ;
if ( V_364 != ( sizeof( T_8 ) * 2 ) ) {
F_8 ( & V_299 -> V_21 , L_56 , V_14 ) ;
goto V_370;
}
V_368 = F_232 ( F_233 ( V_365 ) ) ;
V_367 = F_233 ( V_365 + 1 ) ;
V_369 = F_234 ( V_368 ) ;
F_235 ( V_368 ) ;
if ( ! V_369 ) {
F_8 ( & V_299 -> V_21 , L_57 ) ;
return - V_253 ;
}
snprintf ( V_355 -> V_185 , sizeof( V_355 -> V_185 ) ,
V_371 , V_369 -> V_166 , V_367 ) ;
F_236 ( & V_369 -> V_21 ) ;
} else {
F_8 ( & V_299 -> V_21 ,
L_58 ,
V_14 ) ;
goto V_370;
}
V_355 -> V_183 = F_237 ( V_361 ) ;
if ( V_355 -> V_183 < 0 ) {
F_8 ( & V_299 -> V_21 , L_59 ,
V_14 ) ;
return V_355 -> V_183 ;
}
V_370:
V_102 = F_238 ( V_361 ) ;
if ( V_102 ) {
memcpy ( V_355 -> V_102 , V_102 , V_284 ) ;
} else {
V_60 = F_239 ( & V_299 -> V_21 , V_14 ,
V_355 -> V_102 ) ;
if ( V_60 )
return V_60 ;
}
if ( V_15 -> V_16 ) {
if ( F_221 ( V_361 , L_60 ,
& V_362 ) ) {
F_8 ( & V_299 -> V_21 , L_61 ) ;
V_355 -> V_356 = V_14 + 1 ;
F_8 ( & V_299 -> V_21 , L_62 ,
V_355 -> V_356 , V_14 ) ;
} else {
V_355 -> V_356 = V_362 ;
}
}
V_14 ++ ;
if ( V_14 == V_15 -> V_18 )
break;
}
return 0 ;
}
static void F_240 ( struct V_298 * V_299 )
{
struct V_7 * V_8 = F_241 ( V_299 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_357 * V_15 = & V_11 -> V_15 ;
struct V_358 * V_359 = V_299 -> V_21 . V_360 ;
struct V_358 * V_361 ;
int V_14 = 0 ;
F_226 (node, slave_node) {
struct V_354 * V_355 = & V_15 -> V_355 [ V_14 ] ;
if ( strcmp ( V_361 -> V_166 , L_51 ) )
continue;
if ( F_229 ( V_361 ) )
F_242 ( V_361 ) ;
F_235 ( V_355 -> V_182 ) ;
V_14 ++ ;
if ( V_14 == V_15 -> V_18 )
break;
}
F_243 ( & V_299 -> V_21 ) ;
}
static int F_244 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_357 * V_15 = & V_11 -> V_15 ;
struct V_7 * V_8 ;
struct V_31 * V_372 ;
int V_60 = 0 ;
V_8 = F_245 ( sizeof( struct V_31 ) , V_329 ) ;
if ( ! V_8 ) {
F_8 ( V_11 -> V_21 , L_63 ) ;
return - V_207 ;
}
V_372 = F_16 ( V_8 ) ;
V_372 -> V_11 = V_11 ;
V_372 -> V_8 = V_8 ;
V_372 -> V_21 = & V_8 -> V_21 ;
V_372 -> V_302 = F_246 ( V_373 , V_374 ) ;
if ( F_159 ( V_15 -> V_355 [ 1 ] . V_102 ) ) {
memcpy ( V_372 -> V_102 , V_15 -> V_355 [ 1 ] . V_102 ,
V_284 ) ;
F_122 ( V_11 -> V_21 , L_64 ,
V_372 -> V_102 ) ;
} else {
F_247 ( V_372 -> V_102 ) ;
F_122 ( V_11 -> V_21 , L_65 ,
V_372 -> V_102 ) ;
}
memcpy ( V_8 -> V_285 , V_372 -> V_102 , V_284 ) ;
V_372 -> V_34 = 1 ;
V_11 -> V_18 [ 1 ] . V_8 = V_8 ;
V_8 -> V_375 |= V_376 ;
V_8 -> V_377 = & V_378 ;
V_8 -> V_379 = & V_380 ;
F_248 ( V_8 , V_11 -> V_21 ) ;
V_60 = F_249 ( V_8 ) ;
if ( V_60 ) {
F_8 ( V_11 -> V_21 , L_66 ) ;
F_250 ( V_8 ) ;
V_60 = - V_381 ;
}
return V_60 ;
}
static int F_251 ( struct V_298 * V_299 )
{
struct V_382 * V_382 ;
struct V_357 * V_15 ;
struct V_7 * V_8 ;
struct V_31 * V_32 ;
struct V_383 V_384 ;
struct V_385 V_386 ;
void T_3 * V_387 ;
void T_3 * V_388 ;
struct V_389 * V_390 , * V_391 ;
const struct V_392 * V_393 ;
struct V_394 * V_395 ;
T_1 V_396 , V_397 , V_398 ;
struct V_10 * V_11 ;
int V_60 = 0 , V_14 ;
int V_84 ;
V_11 = F_222 ( & V_299 -> V_21 , sizeof( struct V_10 ) , V_205 ) ;
if ( ! V_11 )
return - V_207 ;
V_11 -> V_21 = & V_299 -> V_21 ;
V_8 = F_245 ( sizeof( struct V_31 ) , V_329 ) ;
if ( ! V_8 ) {
F_8 ( & V_299 -> V_21 , L_67 ) ;
return - V_207 ;
}
F_252 ( V_299 , V_8 ) ;
V_32 = F_16 ( V_8 ) ;
V_32 -> V_11 = V_11 ;
V_32 -> V_8 = V_8 ;
V_32 -> V_21 = & V_8 -> V_21 ;
V_32 -> V_302 = F_246 ( V_373 , V_374 ) ;
V_11 -> V_63 = F_253 ( V_63 , 128 ) ;
V_395 = F_254 ( & V_299 -> V_21 , L_68 , V_399 ) ;
if ( F_99 ( V_395 ) ) {
V_60 = F_100 ( V_395 ) ;
F_8 ( & V_299 -> V_21 , L_69 , V_60 ) ;
goto V_400;
}
F_255 ( & V_299 -> V_21 ) ;
F_256 ( & V_299 -> V_21 ) ;
V_60 = F_118 ( & V_299 -> V_21 ) ;
if ( V_60 < 0 ) {
F_119 ( & V_299 -> V_21 ) ;
goto V_401;
}
V_60 = F_220 ( & V_11 -> V_15 , V_299 ) ;
if ( V_60 )
goto V_402;
V_15 = & V_11 -> V_15 ;
V_11 -> V_83 = 1 ;
V_11 -> V_80 = 1 ;
if ( F_159 ( V_15 -> V_355 [ 0 ] . V_102 ) ) {
memcpy ( V_32 -> V_102 , V_15 -> V_355 [ 0 ] . V_102 , V_284 ) ;
F_122 ( & V_299 -> V_21 , L_70 , V_32 -> V_102 ) ;
} else {
F_257 ( V_32 -> V_102 ) ;
F_122 ( & V_299 -> V_21 , L_71 , V_32 -> V_102 ) ;
}
memcpy ( V_8 -> V_285 , V_32 -> V_102 , V_284 ) ;
V_11 -> V_18 = F_222 ( & V_299 -> V_21 ,
sizeof( struct V_1 ) * V_15 -> V_18 ,
V_205 ) ;
if ( ! V_11 -> V_18 ) {
V_60 = - V_207 ;
goto V_402;
}
for ( V_14 = 0 ; V_14 < V_15 -> V_18 ; V_14 ++ )
V_11 -> V_18 [ V_14 ] . V_6 = V_14 ;
V_11 -> V_18 [ 0 ] . V_8 = V_8 ;
V_32 -> V_34 = 0 ;
V_382 = F_258 ( & V_299 -> V_21 , L_72 ) ;
if ( F_99 ( V_382 ) ) {
F_8 ( V_32 -> V_21 , L_73 ) ;
V_60 = - V_381 ;
goto V_402;
}
V_11 -> V_126 = F_259 ( V_382 ) / 1000000 ;
V_391 = F_260 ( V_299 , V_403 , 0 ) ;
V_387 = F_261 ( & V_299 -> V_21 , V_391 ) ;
if ( F_99 ( V_387 ) ) {
V_60 = F_100 ( V_387 ) ;
goto V_402;
}
V_11 -> V_4 = V_387 ;
V_11 -> V_158 = F_82 ( & V_11 -> V_4 -> V_404 ) ;
V_390 = F_260 ( V_299 , V_403 , 1 ) ;
V_11 -> V_42 = F_261 ( & V_299 -> V_21 , V_390 ) ;
if ( F_99 ( V_11 -> V_42 ) ) {
V_60 = F_100 ( V_11 -> V_42 ) ;
goto V_402;
}
memset ( & V_384 , 0 , sizeof( V_384 ) ) ;
memset ( & V_386 , 0 , sizeof( V_386 ) ) ;
switch ( V_11 -> V_158 ) {
case V_159 :
V_11 -> V_189 = V_387 + V_405 ;
V_388 = V_387 + V_406 ;
V_11 -> V_153 = V_387 + V_407 ;
V_384 . V_408 = V_387 + V_409 ;
V_384 . V_410 = V_387 + V_411 ;
V_386 . V_412 = V_387 + V_413 ;
V_396 = V_414 ;
V_398 = V_415 ;
V_397 = V_416 ;
V_384 . V_417 = 0 ;
break;
case V_175 :
case V_176 :
case V_177 :
V_11 -> V_189 = V_387 + V_418 ;
V_388 = V_387 + V_419 ;
V_11 -> V_153 = V_387 + V_420 ;
V_384 . V_408 = V_387 + V_421 ;
V_384 . V_410 = V_387 + V_422 ;
V_386 . V_412 = V_387 + V_423 ;
V_396 = V_424 ;
V_398 = V_425 ;
V_397 = V_426 ;
V_384 . V_417 =
( T_1 V_427 ) V_391 -> V_428 + V_429 ;
break;
default:
F_8 ( V_32 -> V_21 , L_74 , V_11 -> V_158 ) ;
V_60 = - V_381 ;
goto V_402;
}
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_14 ] ;
F_219 ( V_2 , V_11 , V_396 , V_397 ) ;
V_396 += V_398 ;
V_397 += V_430 ;
}
V_384 . V_21 = & V_299 -> V_21 ;
V_384 . V_431 = V_384 . V_408 + V_432 ;
V_384 . V_433 = V_384 . V_408 + V_434 ;
V_384 . V_435 = V_384 . V_410 + V_436 ;
V_384 . V_437 = V_384 . V_410 + V_438 ;
V_384 . V_439 = V_384 . V_410 + V_440 ;
V_384 . V_441 = V_15 -> V_336 ;
V_384 . V_442 = true ;
V_384 . V_443 = V_214 ;
V_384 . V_444 = V_15 -> V_363 ;
V_384 . V_445 = 16 ;
V_384 . V_446 = true ;
V_384 . V_447 = V_384 . V_417 ;
V_384 . V_126 = V_11 -> V_126 ;
V_384 . V_348 = V_348 ;
V_11 -> V_45 = F_262 ( & V_384 ) ;
if ( ! V_11 -> V_45 ) {
F_8 ( V_32 -> V_21 , L_75 ) ;
V_60 = - V_207 ;
goto V_402;
}
V_11 -> V_72 [ 0 ] . V_58 = F_197 ( V_11 -> V_45 , 0 , F_24 , 0 ) ;
V_11 -> V_68 [ 0 ] . V_58 = F_197 ( V_11 -> V_45 , 0 , F_32 , 1 ) ;
if ( F_45 ( ! V_11 -> V_68 [ 0 ] . V_58 || ! V_11 -> V_72 [ 0 ] . V_58 ) ) {
F_8 ( V_32 -> V_21 , L_76 ) ;
V_60 = - V_207 ;
goto V_448;
}
V_386 . V_21 = & V_299 -> V_21 ;
V_386 . V_449 = V_449 ;
V_386 . V_293 = V_15 -> V_293 ;
V_386 . V_450 = V_15 -> V_18 ;
V_11 -> V_13 = F_263 ( & V_386 ) ;
if ( ! V_11 -> V_13 ) {
F_8 ( V_32 -> V_21 , L_77 ) ;
V_60 = - V_381 ;
goto V_448;
}
V_11 -> V_53 = F_264 ( V_11 -> V_21 , V_388 , V_11 -> V_21 -> V_360 ) ;
if ( F_99 ( V_11 -> V_53 ) ) {
V_60 = F_100 ( V_11 -> V_53 ) ;
goto V_451;
}
V_8 -> V_84 = F_265 ( V_299 , 1 ) ;
if ( V_8 -> V_84 < 0 ) {
F_8 ( V_32 -> V_21 , L_78 ) ;
V_60 = V_8 -> V_84 ;
goto V_451;
}
V_393 = F_266 ( V_452 , & V_299 -> V_21 ) ;
if ( V_393 ) {
V_299 -> V_453 = V_393 -> V_15 ;
if ( V_299 -> V_453 -> V_454 )
V_11 -> V_87 = true ;
}
V_8 -> V_375 |= V_376 ;
V_8 -> V_377 = & V_378 ;
V_8 -> V_379 = & V_380 ;
F_267 ( V_8 , & V_11 -> V_94 , F_61 , V_81 ) ;
F_268 ( V_8 , & V_11 -> V_90 , F_55 , V_81 ) ;
F_46 ( V_8 ) ;
F_248 ( V_8 , & V_299 -> V_21 ) ;
V_60 = F_249 ( V_8 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_79 ) ;
V_60 = - V_381 ;
goto V_451;
}
if ( V_11 -> V_15 . V_16 ) {
V_60 = F_244 ( V_32 ) ;
if ( V_60 ) {
F_110 ( V_32 , V_455 , L_80 ) ;
goto V_456;
}
}
V_84 = F_265 ( V_299 , 1 ) ;
if ( V_84 < 0 ) {
V_60 = V_84 ;
goto V_451;
}
V_11 -> V_88 [ 0 ] = V_84 ;
V_60 = F_269 ( & V_299 -> V_21 , V_84 , F_54 ,
0 , F_270 ( & V_299 -> V_21 ) , V_11 ) ;
if ( V_60 < 0 ) {
F_8 ( V_32 -> V_21 , L_81 , V_60 ) ;
goto V_451;
}
V_84 = F_265 ( V_299 , 2 ) ;
if ( V_84 < 0 ) {
V_60 = V_84 ;
goto V_451;
}
V_11 -> V_88 [ 1 ] = V_84 ;
V_60 = F_269 ( & V_299 -> V_21 , V_84 , F_49 ,
0 , F_270 ( & V_299 -> V_21 ) , V_11 ) ;
if ( V_60 < 0 ) {
F_8 ( V_32 -> V_21 , L_81 , V_60 ) ;
goto V_451;
}
F_83 ( V_32 , V_455 ,
L_82 ,
& V_391 -> V_428 , V_8 -> V_84 , V_384 . V_348 ) ;
F_161 ( & V_299 -> V_21 ) ;
return 0 ;
V_456:
F_271 ( V_8 ) ;
V_451:
F_272 ( V_11 -> V_13 ) ;
V_448:
F_273 ( V_11 -> V_45 ) ;
V_402:
F_240 ( V_299 ) ;
F_130 ( & V_299 -> V_21 ) ;
V_401:
F_274 ( & V_299 -> V_21 ) ;
V_400:
F_250 ( V_32 -> V_8 ) ;
return V_60 ;
}
static int F_275 ( struct V_298 * V_299 )
{
struct V_7 * V_8 = F_241 ( V_299 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
int V_60 ;
V_60 = F_118 ( & V_299 -> V_21 ) ;
if ( V_60 < 0 ) {
F_119 ( & V_299 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 )
F_271 ( V_11 -> V_18 [ 1 ] . V_8 ) ;
F_271 ( V_8 ) ;
F_276 ( V_11 -> V_53 ) ;
F_272 ( V_11 -> V_13 ) ;
F_273 ( V_11 -> V_45 ) ;
F_240 ( V_299 ) ;
F_130 ( & V_299 -> V_21 ) ;
F_274 ( & V_299 -> V_21 ) ;
if ( V_11 -> V_15 . V_16 )
F_250 ( V_11 -> V_18 [ 1 ] . V_8 ) ;
F_250 ( V_8 ) ;
return 0 ;
}
static int F_277 ( struct V_457 * V_21 )
{
struct V_298 * V_299 = F_175 ( V_21 ) ;
struct V_7 * V_8 = F_241 ( V_299 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( F_34 ( V_11 -> V_18 [ V_14 ] . V_8 ) )
F_131 ( V_11 -> V_18 [ V_14 ] . V_8 ) ;
}
} else {
if ( F_34 ( V_8 ) )
F_131 ( V_8 ) ;
}
F_278 ( V_21 ) ;
return 0 ;
}
static int F_279 ( struct V_457 * V_21 )
{
struct V_298 * V_299 = F_175 ( V_21 ) ;
struct V_7 * V_8 = F_241 ( V_299 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
F_256 ( V_21 ) ;
F_280 () ;
if ( V_11 -> V_15 . V_16 ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
if ( F_34 ( V_11 -> V_18 [ V_14 ] . V_8 ) )
F_117 ( V_11 -> V_18 [ V_14 ] . V_8 ) ;
}
} else {
if ( F_34 ( V_8 ) )
F_117 ( V_8 ) ;
}
F_281 () ;
return 0 ;
}
