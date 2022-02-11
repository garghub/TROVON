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
bool V_61 = false ;
struct V_1 * V_2 = V_11 -> V_18 ;
int V_62 ;
if ( V_11 -> V_15 . V_16 ) {
for ( V_62 = V_11 -> V_15 . V_18 ; V_62 ; V_62 -- , V_2 ++ )
if ( F_34 ( V_2 -> V_8 ) )
V_61 = true ;
}
if ( V_61 && ( V_48 >= 0 ) ) {
V_59 = V_52 ;
goto V_63;
}
F_31 ( V_52 ) ;
return;
}
V_59 = F_35 ( V_8 , V_11 -> V_64 ) ;
if ( V_59 ) {
F_36 ( V_59 , V_52 ) ;
F_37 ( V_52 , V_47 ) ;
F_38 ( V_11 -> V_53 , V_52 ) ;
V_52 -> V_65 = F_39 ( V_52 , V_8 ) ;
F_40 ( V_52 ) ;
V_8 -> V_54 . V_66 += V_47 ;
V_8 -> V_54 . V_67 ++ ;
F_41 ( V_59 ) ;
} else {
V_8 -> V_54 . V_68 ++ ;
V_59 = V_52 ;
}
V_63:
if ( F_42 ( V_8 ) ) {
F_31 ( V_59 ) ;
return;
}
V_58 = V_11 -> V_69 [ F_26 ( V_59 ) ] . V_58 ;
V_60 = F_43 ( V_58 , V_59 , V_59 -> V_15 ,
F_44 ( V_59 ) , 0 ) ;
if ( F_45 ( V_60 < 0 ) )
F_31 ( V_59 ) ;
}
static void F_46 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
T_1 V_70 = 0 , V_71 = 0 ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_72 * V_73 = V_11 -> V_73 ;
int V_14 , V_74 , V_75 = 0 ;
int V_76 , V_77 = 0 ;
T_1 V_78 , V_79 ;
int V_80 = 0 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_81 ; V_14 ++ ) {
V_78 = F_47 ( V_73 [ V_14 ] . V_58 ) ;
if ( ! V_78 )
continue;
V_75 ++ ;
V_70 += V_78 ;
}
if ( V_11 -> V_81 == V_75 ) {
V_79 = V_70 ;
} else if ( ! V_75 ) {
V_80 = V_82 / V_11 -> V_81 ;
V_71 = 0 ;
V_79 = V_70 ;
} else {
V_79 = V_11 -> V_83 * 1000 ;
if ( V_79 < V_70 )
V_79 *= 10 ;
if ( V_79 < V_70 )
V_79 *= 10 ;
V_80 = ( V_70 * V_82 ) / V_79 ;
V_80 = ( V_82 - V_80 ) /
( V_11 -> V_81 - V_75 ) ;
V_71 = ( V_79 - V_70 ) /
( V_11 -> V_81 - V_75 ) ;
}
V_76 = V_82 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_81 ; V_14 ++ ) {
V_78 = F_47 ( V_73 [ V_14 ] . V_58 ) ;
if ( V_78 ) {
V_73 [ V_14 ] . V_76 = ( V_78 * V_82 ) / V_79 ;
if ( ! V_73 [ V_14 ] . V_76 )
V_73 [ V_14 ] . V_76 ++ ;
if ( V_78 > V_71 ) {
V_77 = V_14 ;
V_71 = V_78 ;
}
V_74 = ( V_78 * 100 ) / V_79 ;
if ( ! V_74 )
V_74 ++ ;
F_48 ( V_11 -> V_73 [ V_14 ] . V_58 , V_74 ) ;
} else {
V_73 [ V_14 ] . V_76 = V_80 ;
if ( ! V_77 )
V_77 = V_14 ;
F_48 ( V_11 -> V_73 [ V_14 ] . V_58 , 0 ) ;
}
V_76 -= V_73 [ V_14 ] . V_76 ;
}
if ( V_76 )
V_73 [ V_77 ] . V_76 += V_76 ;
V_76 = V_82 ;
V_80 = V_76 / V_11 -> V_84 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_84 ; V_14 ++ ) {
V_11 -> V_69 [ V_14 ] . V_76 = V_80 ;
V_76 -= V_80 ;
}
if ( V_76 )
V_11 -> V_69 [ 0 ] . V_76 += V_76 ;
}
static T_2 F_49 ( int V_85 , void * V_86 )
{
struct V_10 * V_11 = V_86 ;
F_50 ( 0 , & V_11 -> V_42 -> V_43 ) ;
F_51 ( V_11 -> V_45 , V_87 ) ;
if ( V_11 -> V_88 ) {
F_52 ( V_11 -> V_89 [ 1 ] ) ;
V_11 -> V_90 = true ;
}
F_53 ( & V_11 -> V_91 ) ;
return V_92 ;
}
static T_2 F_54 ( int V_85 , void * V_86 )
{
struct V_10 * V_11 = V_86 ;
F_51 ( V_11 -> V_45 , V_93 ) ;
F_50 ( 0 , & V_11 -> V_42 -> V_44 ) ;
if ( V_11 -> V_88 ) {
F_52 ( V_11 -> V_89 [ 0 ] ) ;
V_11 -> V_94 = true ;
}
F_53 ( & V_11 -> V_95 ) ;
return V_92 ;
}
static int F_55 ( struct V_96 * V_91 , int V_76 )
{
T_1 V_97 ;
int V_98 , V_99 , V_58 ;
struct V_10 * V_11 = F_56 ( V_91 ) ;
struct V_72 * V_73 ;
V_97 = F_57 ( V_11 -> V_45 ) ;
for ( V_58 = 0 , V_98 = 0 ; V_97 ; V_97 >>= 1 , V_58 ++ ) {
if ( ! ( V_97 & 0x01 ) )
continue;
V_73 = & V_11 -> V_73 [ V_58 ] ;
if ( F_27 ( V_73 -> V_76 > V_76 - V_98 ) )
V_99 = V_76 - V_98 ;
else
V_99 = V_73 -> V_76 ;
V_98 += F_58 ( V_73 -> V_58 , V_99 ) ;
if ( V_98 >= V_76 )
break;
}
if ( V_98 < V_76 ) {
F_59 ( V_91 ) ;
F_50 ( 0xff , & V_11 -> V_42 -> V_43 ) ;
if ( V_11 -> V_88 && V_11 -> V_90 ) {
V_11 -> V_90 = false ;
F_60 ( V_11 -> V_89 [ 1 ] ) ;
}
}
return V_98 ;
}
static int F_61 ( struct V_96 * V_95 , int V_76 )
{
T_1 V_97 ;
int V_100 , V_99 , V_58 ;
struct V_10 * V_11 = F_56 ( V_95 ) ;
struct V_72 * V_69 ;
V_97 = F_62 ( V_11 -> V_45 ) ;
for ( V_58 = 0 , V_100 = 0 ; V_97 ; V_97 >>= 1 , V_58 ++ ) {
if ( ! ( V_97 & 0x01 ) )
continue;
V_69 = & V_11 -> V_69 [ V_58 ] ;
if ( F_27 ( V_69 -> V_76 > V_76 - V_100 ) )
V_99 = V_76 - V_100 ;
else
V_99 = V_69 -> V_76 ;
V_100 += F_58 ( V_69 -> V_58 , V_99 ) ;
if ( V_100 >= V_76 )
break;
}
if ( V_100 < V_76 ) {
F_59 ( V_95 ) ;
F_50 ( 0xff , & V_11 -> V_42 -> V_44 ) ;
if ( V_11 -> V_88 && V_11 -> V_94 ) {
V_11 -> V_94 = false ;
F_60 ( V_11 -> V_89 [ 0 ] ) ;
}
}
return V_100 ;
}
static inline void F_63 ( const char * V_101 , void T_3 * V_102 )
{
unsigned long V_23 = V_24 + V_25 ;
F_4 ( 1 , V_102 ) ;
do {
F_11 () ;
} while ( ( F_2 ( V_102 ) & 1 ) && F_13 ( V_23 , V_24 ) );
F_64 ( F_2 ( V_102 ) & 1 , L_4 , V_101 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
F_3 ( V_2 , F_66 ( V_32 -> V_103 ) , V_104 ) ;
F_3 ( V_2 , F_67 ( V_32 -> V_103 ) , V_105 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_31 * V_32 , bool * V_106 )
{
struct V_107 * V_108 = V_2 -> V_108 ;
T_1 V_109 = 0 ;
T_1 V_110 ;
struct V_10 * V_11 = V_32 -> V_11 ;
if ( ! V_108 )
return;
V_110 = F_5 ( V_2 -> V_6 ) ;
if ( V_108 -> V_106 ) {
V_109 = V_11 -> V_15 . V_109 ;
F_9 ( V_11 -> V_13 , V_110 ,
V_111 , V_112 ) ;
if ( V_108 -> V_83 == 1000 )
V_109 |= F_69 ( 7 ) ;
if ( V_108 -> V_113 )
V_109 |= F_69 ( 0 ) ;
if ( V_108 -> V_83 == 100 )
V_109 |= F_69 ( 15 ) ;
else if ( V_108 -> V_83 == 10 )
V_109 |= F_69 ( 18 ) ;
if ( V_32 -> V_114 )
V_109 |= F_69 ( 3 ) ;
if ( V_32 -> V_115 )
V_109 |= F_69 ( 4 ) ;
* V_106 = true ;
} else {
V_109 = 0 ;
F_9 ( V_11 -> V_13 , V_110 ,
V_111 , V_116 ) ;
}
if ( V_109 != V_2 -> V_109 ) {
F_70 ( V_108 ) ;
F_4 ( V_109 , & V_2 -> V_117 -> V_109 ) ;
}
V_2 -> V_109 = V_109 ;
}
static int F_71 ( struct V_10 * V_11 )
{
int V_14 , V_83 ;
for ( V_14 = 0 , V_83 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ )
if ( V_11 -> V_18 [ V_14 ] . V_108 && V_11 -> V_18 [ V_14 ] . V_108 -> V_106 )
V_83 += V_11 -> V_18 [ V_14 ] . V_108 -> V_83 ;
return V_83 ;
}
static int F_72 ( struct V_10 * V_11 )
{
int V_14 , V_75 ;
int V_83 , V_78 ;
V_83 = F_71 ( V_11 ) ;
if ( V_83 == V_11 -> V_83 || ! V_83 )
return 0 ;
V_11 -> V_83 = V_83 ;
for ( V_14 = 0 , V_75 = 0 ; V_14 < V_11 -> V_81 ; V_14 ++ ) {
V_78 = F_47 ( V_11 -> V_73 [ V_14 ] . V_58 ) ;
if ( ! V_78 )
break;
V_75 ++ ;
}
if ( ! V_75 || V_75 == V_11 -> V_81 )
return 0 ;
return 1 ;
}
static void F_73 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
bool V_106 = false ;
F_74 ( V_32 , F_68 , V_32 , & V_106 ) ;
if ( V_106 ) {
if ( F_72 ( V_11 ) )
F_46 ( V_8 ) ;
F_75 ( V_8 ) ;
if ( F_34 ( V_8 ) )
F_76 ( V_8 ) ;
} else {
F_77 ( V_8 ) ;
F_78 ( V_8 ) ;
}
}
static int F_79 ( struct V_7 * V_8 ,
struct V_118 * V_119 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_119 -> V_120 = V_11 -> V_121 ;
return 0 ;
}
static int F_80 ( struct V_7 * V_8 ,
struct V_118 * V_119 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
T_1 V_122 ;
T_1 V_123 = 0 ;
T_1 V_124 = 0 ;
T_1 V_125 = 1 ;
T_1 V_121 = 0 ;
struct V_10 * V_11 = V_32 -> V_11 ;
V_121 = V_119 -> V_120 ;
V_122 = F_81 ( & V_11 -> V_42 -> V_126 ) ;
V_124 = V_11 -> V_127 * 4 ;
if ( ! V_119 -> V_120 ) {
V_122 &= ~ ( V_128 | V_129 ) ;
goto V_130;
}
if ( V_121 < V_131 )
V_121 = V_131 ;
if ( V_121 > V_132 ) {
V_125 = V_128 / V_124 ;
if ( V_125 > 1 ) {
V_124 *= V_125 ;
if ( V_121 > ( V_132 * V_125 ) )
V_121 = ( V_132
* V_125 ) ;
} else {
V_125 = 1 ;
V_121 = V_132 ;
}
}
V_123 = ( 1000 * V_125 ) / V_121 ;
F_50 ( V_123 , & V_11 -> V_42 -> V_133 ) ;
F_50 ( V_123 , & V_11 -> V_42 -> V_134 ) ;
V_122 |= V_129 ;
V_122 &= ( ~ V_128 ) ;
V_122 |= ( V_124 & V_128 ) ;
V_130:
F_50 ( V_122 , & V_11 -> V_42 -> V_126 ) ;
F_82 ( V_32 , V_135 , L_5 , V_121 ) ;
V_11 -> V_121 = V_121 ;
return 0 ;
}
static int F_83 ( struct V_7 * V_8 , int V_136 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
switch ( V_136 ) {
case V_137 :
return ( V_138 +
( V_11 -> V_84 + V_11 -> V_81 ) *
V_139 ) ;
default:
return - V_140 ;
}
}
static void F_84 ( V_40 * * V_141 , int V_142 , int V_143 )
{
int V_144 ;
int line ;
int V_14 ;
V_144 = V_139 * V_142 ;
for ( V_14 = 0 ; V_14 < V_144 ; V_14 ++ ) {
line = V_14 % V_139 ;
snprintf ( * V_141 , V_145 ,
L_6 , V_143 ? L_7 : L_8 ,
V_14 / V_139 ,
V_146 [ line ] . V_147 ) ;
* V_141 += V_145 ;
}
}
static void F_85 ( struct V_7 * V_8 , T_1 V_148 , V_40 * V_15 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_40 * V_141 = V_15 ;
int V_14 ;
switch ( V_148 ) {
case V_137 :
for ( V_14 = 0 ; V_14 < V_138 ; V_14 ++ ) {
memcpy ( V_141 , V_149 [ V_14 ] . V_147 ,
V_145 ) ;
V_141 += V_145 ;
}
F_84 ( & V_141 , V_11 -> V_84 , 1 ) ;
F_84 ( & V_141 , V_11 -> V_81 , 0 ) ;
break;
}
}
static void F_86 ( struct V_7 * V_8 ,
struct V_150 * V_54 , T_4 * V_15 )
{
V_40 * V_141 ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_151 V_152 ;
int V_14 , V_153 , V_58 ;
for ( V_153 = 0 ; V_153 < V_138 ; V_153 ++ )
V_15 [ V_153 ] = F_81 ( V_11 -> V_154 +
V_149 [ V_153 ] . V_155 ) ;
for ( V_58 = 0 ; V_58 < V_11 -> V_84 ; V_58 ++ ) {
F_87 ( V_11 -> V_69 [ V_58 ] . V_58 , & V_152 ) ;
for ( V_14 = 0 ; V_14 < V_139 ; V_14 ++ , V_153 ++ ) {
V_141 = ( V_40 * ) & V_152 +
V_146 [ V_14 ] . V_155 ;
V_15 [ V_153 ] = * ( T_1 * ) V_141 ;
}
}
for ( V_58 = 0 ; V_58 < V_11 -> V_81 ; V_58 ++ ) {
F_87 ( V_11 -> V_73 [ V_58 ] . V_58 , & V_152 ) ;
for ( V_14 = 0 ; V_14 < V_139 ; V_14 ++ , V_153 ++ ) {
V_141 = ( V_40 * ) & V_152 +
V_146 [ V_14 ] . V_155 ;
V_15 [ V_153 ] = * ( T_1 * ) V_141 ;
}
}
}
static int F_88 ( struct V_10 * V_11 )
{
T_1 V_14 ;
T_1 V_156 = 0 ;
if ( ! V_11 -> V_15 . V_16 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ )
if ( V_11 -> V_18 [ V_14 ] . V_157 )
V_156 ++ ;
return V_156 ;
}
static inline int F_89 ( struct V_31 * V_32 ,
struct V_51 * V_52 ,
struct V_57 * V_158 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
return F_43 ( V_158 , V_52 , V_52 -> V_15 , V_52 -> V_47 ,
V_32 -> V_34 + V_11 -> V_15 . V_16 ) ;
}
static inline void F_90 (
struct V_31 * V_32 , struct V_1 * V_2 ,
T_1 V_110 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
T_1 V_159 = 1 << V_110 | V_160 ;
if ( V_11 -> V_161 == V_162 )
F_3 ( V_2 , V_2 -> V_35 , V_163 ) ;
else
F_3 ( V_2 , V_2 -> V_35 , V_164 ) ;
F_91 ( V_11 -> V_13 , V_2 -> V_35 , V_159 ,
V_159 , V_159 , 0 ) ;
F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_165 ,
V_159 , V_166 , V_2 -> V_35 , 0 ) ;
F_93 ( V_11 -> V_13 , V_32 -> V_103 ,
V_167 , V_166 |
V_168 , V_2 -> V_35 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
char V_169 [ 32 ] ;
snprintf ( V_169 , sizeof( V_169 ) , L_9 , V_2 -> V_6 ) ;
F_63 ( V_169 , & V_2 -> V_117 -> F_63 ) ;
}
static void F_95 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
T_1 V_110 ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_94 ( V_2 ) ;
F_4 ( V_170 , & V_2 -> V_117 -> V_171 ) ;
switch ( V_11 -> V_161 ) {
case V_162 :
F_3 ( V_2 , V_172 , V_173 ) ;
break;
case V_174 :
case V_175 :
case V_176 :
F_3 ( V_2 , V_172 , V_177 ) ;
break;
}
F_4 ( V_11 -> V_64 , & V_2 -> V_117 -> V_178 ) ;
F_65 ( V_2 , V_32 ) ;
V_2 -> V_109 = 0 ;
V_110 = F_5 ( V_2 -> V_6 ) ;
if ( V_11 -> V_15 . V_16 )
F_90 ( V_32 , V_2 , V_110 ) ;
else
F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_165 ,
1 << V_110 , 0 , 0 , V_179 ) ;
if ( V_2 -> V_15 -> V_180 ) {
V_2 -> V_108 = F_96 ( V_32 -> V_8 , V_2 -> V_15 -> V_180 ,
& F_73 , 0 , V_2 -> V_15 -> V_181 ) ;
if ( ! V_2 -> V_108 ) {
F_8 ( V_32 -> V_21 , L_10 ,
V_2 -> V_15 -> V_180 -> V_182 ,
V_2 -> V_6 ) ;
return;
}
} else {
V_2 -> V_108 = F_97 ( V_32 -> V_8 , V_2 -> V_15 -> V_183 ,
& F_73 , V_2 -> V_15 -> V_181 ) ;
if ( F_98 ( V_2 -> V_108 ) ) {
F_8 ( V_32 -> V_21 ,
L_11 ,
V_2 -> V_15 -> V_183 , V_2 -> V_6 ,
F_99 ( V_2 -> V_108 ) ) ;
V_2 -> V_108 = NULL ;
return;
}
}
F_100 ( V_2 -> V_108 ) ;
F_101 ( V_2 -> V_108 ) ;
F_102 ( V_11 -> V_21 , V_2 -> V_108 -> V_184 , V_2 -> V_6 ) ;
}
static inline void F_103 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
const int V_185 = V_11 -> V_15 . V_36 ;
T_1 V_102 ;
int V_14 ;
int V_186 ;
V_102 = ( V_11 -> V_161 == V_162 ) ? V_163 :
V_164 ;
F_50 ( V_185 , & V_11 -> V_187 -> V_35 ) ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ )
F_3 ( V_11 -> V_18 + V_14 , V_185 , V_102 ) ;
if ( V_32 -> V_8 -> V_19 & V_37 )
V_186 = V_29 ;
else
V_186 = V_188 | V_189 ;
F_91 ( V_11 -> V_13 , V_185 , V_29 ,
V_29 , V_29 ,
V_186 ) ;
}
static void F_104 ( struct V_31 * V_32 )
{
T_1 V_190 ;
T_1 V_191 ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_63 ( L_12 , & V_11 -> V_4 -> F_63 ) ;
F_105 ( V_11 -> V_13 ) ;
F_9 ( V_11 -> V_13 , V_167 , V_192 ,
V_193 ) ;
V_191 = F_81 ( & V_11 -> V_4 -> V_194 ) ;
V_191 |= V_195 ;
F_50 ( V_191 , & V_11 -> V_4 -> V_194 ) ;
V_190 = ( V_11 -> V_15 . V_16 ) ? V_196 :
V_197 ;
F_50 ( V_190 , & V_11 -> V_187 -> V_198 ) ;
F_4 ( V_199 ,
& V_11 -> V_187 -> V_200 ) ;
F_4 ( 0 , & V_11 -> V_187 -> V_201 ) ;
F_9 ( V_11 -> V_13 , V_167 ,
V_111 , V_112 ) ;
if ( ! V_11 -> V_15 . V_16 ) {
F_93 ( V_11 -> V_13 , V_32 -> V_103 , V_167 ,
0 , 0 ) ;
F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_165 ,
V_160 , 0 , 0 , V_179 ) ;
}
}
static int F_106 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_51 * V_52 ;
int V_202 ;
int V_58 , V_14 , V_60 ;
for ( V_58 = 0 ; V_58 < V_11 -> V_84 ; V_58 ++ ) {
V_202 = F_107 ( V_11 -> V_69 [ V_58 ] . V_58 ) ;
for ( V_14 = 0 ; V_14 < V_202 ; V_14 ++ ) {
V_52 = F_108 ( V_32 -> V_8 ,
V_11 -> V_64 ,
V_203 ) ;
if ( ! V_52 ) {
F_109 ( V_32 , V_204 , L_13 ) ;
return - V_205 ;
}
F_110 ( V_52 , V_58 ) ;
V_60 = F_43 ( V_11 -> V_69 [ V_58 ] . V_58 , V_52 ,
V_52 -> V_15 , F_44 ( V_52 ) ,
0 ) ;
if ( V_60 < 0 ) {
F_109 ( V_32 , V_204 ,
L_14 ,
V_58 , V_60 ) ;
F_111 ( V_52 ) ;
return V_60 ;
}
F_41 ( V_52 ) ;
}
F_112 ( V_32 , V_204 , L_15 ,
V_58 , V_202 ) ;
}
return 0 ;
}
static void F_113 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
T_1 V_110 ;
V_110 = F_5 ( V_2 -> V_6 ) ;
if ( ! V_2 -> V_108 )
return;
F_114 ( V_2 -> V_108 ) ;
F_115 ( V_2 -> V_108 ) ;
V_2 -> V_108 = NULL ;
F_9 ( V_11 -> V_13 , V_110 ,
V_111 , V_116 ) ;
F_94 ( V_2 ) ;
}
static int F_116 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
T_1 V_102 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( ! F_88 ( V_11 ) )
F_23 ( V_11 ) ;
F_77 ( V_8 ) ;
V_60 = F_119 ( V_8 , V_11 -> V_81 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_16 ) ;
goto V_206;
}
V_60 = F_120 ( V_8 , V_11 -> V_84 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_17 ) ;
goto V_206;
}
V_102 = V_11 -> V_161 ;
F_121 ( V_32 -> V_21 , L_18 ,
F_122 ( V_102 ) , F_123 ( V_102 ) ,
F_124 ( V_102 ) ) ;
if ( ! F_88 ( V_11 ) )
F_104 ( V_32 ) ;
F_74 ( V_32 , F_95 , V_32 ) ;
if ( ! V_11 -> V_15 . V_16 )
F_103 ( V_32 ) ;
else
F_91 ( V_11 -> V_13 , V_11 -> V_15 . V_36 ,
V_29 , V_29 , 0 , 0 ) ;
if ( ! F_88 ( V_11 ) ) {
F_4 ( 0 , & V_11 -> V_4 -> V_207 ) ;
F_4 ( 0x7 , & V_11 -> V_4 -> V_208 ) ;
F_50 ( 0x7 , & V_11 -> V_4 -> V_209 ) ;
F_125 ( & V_11 -> V_95 ) ;
F_125 ( & V_11 -> V_91 ) ;
if ( V_11 -> V_90 ) {
V_11 -> V_90 = false ;
F_60 ( V_11 -> V_89 [ 1 ] ) ;
}
if ( V_11 -> V_94 ) {
V_11 -> V_94 = false ;
F_60 ( V_11 -> V_89 [ 0 ] ) ;
}
V_60 = F_106 ( V_32 ) ;
if ( V_60 < 0 )
goto V_206;
if ( F_126 ( V_11 -> V_53 ) )
F_8 ( V_32 -> V_21 , L_19 ) ;
}
if ( V_11 -> V_121 != 0 ) {
struct V_118 V_119 ;
V_119 . V_120 = V_11 -> V_121 ;
F_80 ( V_8 , & V_119 ) ;
}
F_127 ( V_11 -> V_45 ) ;
F_21 ( V_11 ) ;
if ( V_11 -> V_15 . V_16 )
V_11 -> V_18 [ V_32 -> V_34 ] . V_157 = true ;
return 0 ;
V_206:
F_128 ( V_11 -> V_45 ) ;
F_74 ( V_32 , F_113 , V_11 ) ;
F_129 ( V_11 -> V_21 ) ;
F_77 ( V_32 -> V_8 ) ;
return V_60 ;
}
static int F_130 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
F_112 ( V_32 , V_210 , L_20 ) ;
F_78 ( V_32 -> V_8 ) ;
F_77 ( V_32 -> V_8 ) ;
if ( F_88 ( V_11 ) <= 1 ) {
F_131 ( & V_11 -> V_95 ) ;
F_131 ( & V_11 -> V_91 ) ;
F_132 ( V_11 -> V_53 ) ;
F_23 ( V_11 ) ;
F_128 ( V_11 -> V_45 ) ;
F_133 ( V_11 -> V_13 ) ;
}
F_74 ( V_32 , F_113 , V_11 ) ;
if ( F_72 ( V_11 ) )
F_46 ( V_8 ) ;
F_129 ( V_11 -> V_21 ) ;
if ( V_11 -> V_15 . V_16 )
V_11 -> V_18 [ V_32 -> V_34 ] . V_157 = false ;
return 0 ;
}
static T_5 F_134 ( struct V_51 * V_52 ,
struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_49 * V_50 ;
struct V_57 * V_158 ;
int V_60 , V_211 ;
F_135 ( V_8 ) ;
if ( F_136 ( V_52 , V_212 ) ) {
F_109 ( V_32 , V_213 , L_21 ) ;
V_8 -> V_54 . V_214 ++ ;
return V_215 ;
}
if ( F_137 ( V_52 ) -> V_216 & V_217 &&
F_138 ( V_11 -> V_53 ) )
F_137 ( V_52 ) -> V_216 |= V_218 ;
F_139 ( V_52 ) ;
V_211 = F_26 ( V_52 ) ;
if ( V_211 >= V_11 -> V_81 )
V_211 = V_211 % V_11 -> V_81 ;
V_158 = V_11 -> V_73 [ V_211 ] . V_58 ;
V_60 = F_89 ( V_32 , V_52 , V_158 ) ;
if ( F_27 ( V_60 != 0 ) ) {
F_109 ( V_32 , V_213 , L_22 ) ;
goto V_219;
}
if ( F_27 ( ! F_140 ( V_158 ) ) ) {
V_50 = F_25 ( V_8 , V_211 ) ;
F_141 ( V_50 ) ;
}
return V_215 ;
V_219:
V_8 -> V_54 . V_214 ++ ;
V_50 = F_25 ( V_8 , F_26 ( V_52 ) ) ;
F_141 ( V_50 ) ;
return V_220 ;
}
static void F_142 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = & V_11 -> V_18 [ V_11 -> V_15 . V_221 ] ;
T_1 V_222 , V_223 ;
if ( ! F_138 ( V_11 -> V_53 ) &&
! F_143 ( V_11 -> V_53 ) ) {
F_3 ( V_2 , 0 , V_224 ) ;
return;
}
V_223 = ( 30 << V_225 ) | V_226 ;
V_222 = V_227 << V_228 ;
if ( F_138 ( V_11 -> V_53 ) )
V_222 |= V_229 ;
if ( F_143 ( V_11 -> V_53 ) )
V_222 |= V_230 ;
F_3 ( V_2 , V_222 , V_224 ) ;
F_3 ( V_2 , V_223 , V_231 ) ;
}
static void F_144 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = V_32 -> V_11 ;
T_1 V_232 , V_233 ;
V_2 = & V_11 -> V_18 [ F_145 ( V_11 , V_32 ) ] ;
V_232 = F_1 ( V_2 , V_234 ) ;
switch ( V_11 -> V_161 ) {
case V_174 :
V_232 &= ~ V_235 ;
if ( F_138 ( V_11 -> V_53 ) )
V_232 |= V_236 ;
if ( F_143 ( V_11 -> V_53 ) )
V_232 |= V_237 ;
break;
case V_175 :
default:
V_232 &= ~ V_238 ;
if ( F_138 ( V_11 -> V_53 ) )
V_232 |= V_239 ;
if ( F_143 ( V_11 -> V_53 ) )
V_232 |= V_240 ;
break;
}
V_233 = ( 30 << V_241 ) | V_227 ;
F_3 ( V_2 , V_233 , V_242 ) ;
F_3 ( V_2 , V_232 , V_234 ) ;
F_4 ( V_226 , & V_11 -> V_4 -> V_243 ) ;
}
static int F_146 ( struct V_7 * V_21 , struct V_244 * V_245 )
{
struct V_31 * V_32 = F_16 ( V_21 ) ;
struct V_246 V_247 ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_53 * V_53 = V_11 -> V_53 ;
if ( V_11 -> V_161 != V_162 &&
V_11 -> V_161 != V_174 &&
V_11 -> V_161 != V_175 )
return - V_140 ;
if ( F_147 ( & V_247 , V_245 -> V_248 , sizeof( V_247 ) ) )
return - V_249 ;
if ( V_247 . V_19 )
return - V_250 ;
if ( V_247 . V_251 != V_252 && V_247 . V_251 != V_253 )
return - V_254 ;
switch ( V_247 . V_255 ) {
case V_256 :
F_148 ( V_53 , 0 ) ;
break;
case V_257 :
case V_258 :
case V_259 :
case V_260 :
return - V_254 ;
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
F_148 ( V_53 , 1 ) ;
V_247 . V_255 = V_267 ;
break;
default:
return - V_254 ;
}
F_149 ( V_53 , V_247 . V_251 == V_253 ) ;
switch ( V_11 -> V_161 ) {
case V_162 :
F_142 ( V_11 ) ;
break;
case V_174 :
case V_175 :
F_144 ( V_32 ) ;
break;
default:
F_45 ( 1 ) ;
}
return F_150 ( V_245 -> V_248 , & V_247 , sizeof( V_247 ) ) ? - V_249 : 0 ;
}
static int F_151 ( struct V_7 * V_21 , struct V_244 * V_245 )
{
struct V_10 * V_11 = F_7 ( V_21 ) ;
struct V_53 * V_53 = V_11 -> V_53 ;
struct V_246 V_247 ;
if ( V_11 -> V_161 != V_162 &&
V_11 -> V_161 != V_174 &&
V_11 -> V_161 != V_175 )
return - V_140 ;
V_247 . V_19 = 0 ;
V_247 . V_251 = F_138 ( V_53 ) ?
V_253 : V_252 ;
V_247 . V_255 = ( F_143 ( V_53 ) ?
V_267 : V_256 ) ;
return F_150 ( V_245 -> V_248 , & V_247 , sizeof( V_247 ) ) ? - V_249 : 0 ;
}
static int F_151 ( struct V_7 * V_21 , struct V_244 * V_245 )
{
return - V_140 ;
}
static int F_146 ( struct V_7 * V_21 , struct V_244 * V_245 )
{
return - V_140 ;
}
static int F_152 ( struct V_7 * V_21 , struct V_244 * V_270 , int V_271 )
{
struct V_31 * V_32 = F_16 ( V_21 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
if ( ! F_34 ( V_21 ) )
return - V_250 ;
switch ( V_271 ) {
case V_273 :
return F_146 ( V_21 , V_270 ) ;
case V_274 :
return F_151 ( V_21 , V_270 ) ;
}
if ( ! V_11 -> V_18 [ V_272 ] . V_108 )
return - V_140 ;
return F_153 ( V_11 -> V_18 [ V_272 ] . V_108 , V_270 , V_271 ) ;
}
static void F_154 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_58 ;
F_109 ( V_32 , V_213 , L_23 ) ;
V_8 -> V_54 . V_275 ++ ;
F_23 ( V_11 ) ;
for ( V_58 = 0 ; V_58 < V_11 -> V_81 ; V_58 ++ ) {
F_155 ( V_11 -> V_73 [ V_58 ] . V_58 ) ;
F_156 ( V_11 -> V_73 [ V_58 ] . V_58 ) ;
}
F_21 ( V_11 ) ;
}
static int F_157 ( struct V_7 * V_8 , void * V_141 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_276 * V_41 = (struct V_276 * ) V_141 ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_19 = 0 ;
T_6 V_33 = 0 ;
int V_60 ;
if ( ! F_158 ( V_41 -> V_277 ) )
return - V_278 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 ) {
V_33 = V_11 -> V_18 [ V_32 -> V_34 ] . V_35 ;
V_19 = V_166 ;
}
F_159 ( V_11 -> V_13 , V_32 -> V_103 , V_167 ,
V_19 , V_33 ) ;
F_93 ( V_11 -> V_13 , V_41 -> V_277 , V_167 ,
V_19 , V_33 ) ;
memcpy ( V_32 -> V_103 , V_41 -> V_277 , V_279 ) ;
memcpy ( V_8 -> V_280 , V_32 -> V_103 , V_279 ) ;
F_74 ( V_32 , F_65 , V_32 ) ;
F_160 ( V_11 -> V_21 ) ;
return 0 ;
}
static void F_161 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
F_23 ( V_11 ) ;
F_54 ( V_11 -> V_89 [ 0 ] , V_11 ) ;
F_49 ( V_11 -> V_89 [ 1 ] , V_11 ) ;
F_21 ( V_11 ) ;
}
static inline int F_162 ( struct V_31 * V_32 ,
unsigned short V_33 )
{
int V_60 ;
int V_186 = 0 ;
T_1 V_159 ;
struct V_10 * V_11 = V_32 -> V_11 ;
if ( V_11 -> V_15 . V_16 ) {
V_159 = ( 1 << ( V_32 -> V_34 + 1 ) ) | V_160 ;
if ( V_32 -> V_8 -> V_19 & V_37 )
V_186 = V_159 ;
} else {
V_159 = V_29 ;
if ( V_32 -> V_8 -> V_19 & V_37 )
V_186 = V_29 ;
else
V_186 = V_188 | V_189 ;
}
V_60 = F_91 ( V_11 -> V_13 , V_33 , V_159 , 0 , V_159 ,
V_186 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_93 ( V_11 -> V_13 , V_32 -> V_103 ,
V_167 , V_166 , V_33 ) ;
if ( V_60 != 0 )
goto V_281;
V_60 = F_92 ( V_11 -> V_13 , V_32 -> V_8 -> V_165 ,
V_159 , V_166 , V_33 , 0 ) ;
if ( V_60 != 0 )
goto V_282;
return 0 ;
V_282:
F_159 ( V_11 -> V_13 , V_32 -> V_103 ,
V_167 , V_166 , V_33 ) ;
V_281:
F_163 ( V_11 -> V_13 , V_33 , 0 ) ;
return V_60 ;
}
static int F_164 ( struct V_7 * V_8 ,
T_7 V_283 , T_6 V_33 )
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
return - V_250 ;
}
}
F_121 ( V_32 -> V_21 , L_24 , V_33 ) ;
V_60 = F_162 ( V_32 , V_33 ) ;
F_160 ( V_11 -> V_21 ) ;
return V_60 ;
}
static int F_165 ( struct V_7 * V_8 ,
T_7 V_283 , T_6 V_33 )
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
return - V_250 ;
}
}
F_121 ( V_32 -> V_21 , L_25 , V_33 ) ;
V_60 = F_163 ( V_11 -> V_13 , V_33 , 0 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_159 ( V_11 -> V_13 , V_32 -> V_103 ,
V_167 , V_166 , V_33 ) ;
if ( V_60 != 0 )
return V_60 ;
V_60 = F_166 ( V_11 -> V_13 , V_32 -> V_8 -> V_165 ,
0 , V_166 , V_33 ) ;
F_160 ( V_11 -> V_21 ) ;
return V_60 ;
}
static int F_167 ( struct V_7 * V_8 , int V_284 , T_1 V_285 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
T_1 V_286 ;
T_1 V_78 ;
int V_14 , V_60 ;
V_78 = F_25 ( V_8 , V_284 ) -> V_287 ;
if ( V_78 == V_285 )
return 0 ;
V_78 = V_285 * 1000 ;
V_286 = F_168 ( V_11 -> V_45 ) ;
if ( ( V_78 < V_286 && V_78 ) ) {
F_8 ( V_32 -> V_21 , L_26 ,
V_286 ) ;
return - V_250 ;
}
if ( V_285 > V_11 -> V_83 ) {
F_8 ( V_32 -> V_21 , L_27 ) ;
return - V_250 ;
}
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( V_11 -> V_21 ) ;
return V_60 ;
}
V_60 = F_169 ( V_11 -> V_73 [ V_284 ] . V_58 , V_78 ) ;
F_160 ( V_11 -> V_21 ) ;
if ( V_60 )
return V_60 ;
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
V_2 = & V_11 -> V_18 [ V_14 ] ;
if ( ! V_2 -> V_8 )
continue;
F_25 ( V_2 -> V_8 , V_284 ) -> V_287 = V_285 ;
}
F_46 ( V_8 ) ;
return V_60 ;
}
static int F_170 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
return V_11 -> V_15 . V_288 * V_289 * sizeof( T_1 ) ;
}
static void F_171 ( struct V_7 * V_8 ,
struct V_290 * V_4 , void * V_141 )
{
T_1 * V_102 = V_141 ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_4 -> V_161 = V_11 -> V_161 ;
F_172 ( V_11 -> V_13 , V_102 ) ;
}
static void F_173 ( struct V_7 * V_8 ,
struct V_291 * V_292 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_293 * V_294 = F_174 ( V_11 -> V_21 ) ;
F_175 ( V_292 -> V_295 , L_12 , sizeof( V_292 -> V_295 ) ) ;
F_175 ( V_292 -> V_161 , L_28 , sizeof( V_292 -> V_161 ) ) ;
F_175 ( V_292 -> V_296 , V_294 -> V_169 , sizeof( V_292 -> V_296 ) ) ;
}
static T_1 F_176 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
return V_32 -> V_297 ;
}
static void F_177 ( struct V_7 * V_8 , T_1 V_298 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
V_32 -> V_297 = V_298 ;
}
static int F_178 ( struct V_7 * V_8 ,
struct V_299 * V_292 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_292 -> V_300 =
V_301 |
V_302 |
V_303 |
V_304 |
V_305 |
V_306 ;
V_292 -> V_307 = V_11 -> V_53 -> V_307 ;
V_292 -> V_308 =
( 1 << V_252 ) |
( 1 << V_253 ) ;
V_292 -> V_309 =
( 1 << V_256 ) |
( 1 << V_267 ) ;
return 0 ;
}
static int F_178 ( struct V_7 * V_8 ,
struct V_299 * V_292 )
{
V_292 -> V_300 =
V_302 |
V_304 |
V_305 ;
V_292 -> V_307 = - 1 ;
V_292 -> V_308 = 0 ;
V_292 -> V_309 = 0 ;
return 0 ;
}
static int F_179 ( struct V_7 * V_8 ,
struct V_310 * V_311 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_272 ] . V_108 )
return F_180 ( V_11 -> V_18 [ V_272 ] . V_108 ,
V_311 ) ;
else
return - V_140 ;
}
static int F_181 ( struct V_7 * V_8 ,
const struct V_310 * V_311 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_272 ] . V_108 )
return F_182 ( V_11 -> V_18 [ V_272 ] . V_108 ,
V_311 ) ;
else
return - V_140 ;
}
static void F_183 ( struct V_7 * V_8 , struct V_312 * V_313 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
V_313 -> V_314 = 0 ;
V_313 -> V_315 = 0 ;
if ( V_11 -> V_18 [ V_272 ] . V_108 )
F_184 ( V_11 -> V_18 [ V_272 ] . V_108 , V_313 ) ;
}
static int F_185 ( struct V_7 * V_8 , struct V_312 * V_313 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_272 ] . V_108 )
return F_186 ( V_11 -> V_18 [ V_272 ] . V_108 , V_313 ) ;
else
return - V_140 ;
}
static void F_187 ( struct V_7 * V_8 ,
struct V_316 * V_317 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
V_317 -> V_318 = V_319 ;
V_317 -> V_114 = V_32 -> V_114 ? true : false ;
V_317 -> V_115 = V_32 -> V_115 ? true : false ;
}
static int F_188 ( struct V_7 * V_8 ,
struct V_316 * V_317 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
bool V_106 ;
V_32 -> V_114 = V_317 -> V_114 ? true : false ;
V_32 -> V_115 = V_317 -> V_115 ? true : false ;
F_74 ( V_32 , F_68 , V_32 , & V_106 ) ;
return 0 ;
}
static int F_189 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_60 ;
V_60 = F_117 ( V_11 -> V_21 ) ;
if ( V_60 < 0 ) {
F_109 ( V_32 , V_320 , L_29 , V_60 ) ;
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
F_109 ( V_32 , V_320 , L_30 , V_60 ) ;
}
static void F_191 ( struct V_7 * V_8 ,
struct V_321 * V_58 )
{
struct V_10 * V_11 = F_7 ( V_8 ) ;
V_58 -> V_322 = 0 ;
V_58 -> V_323 = V_324 ;
V_58 -> V_325 = V_324 ;
V_58 -> V_326 = 0 ;
V_58 -> V_327 = 0 ;
V_58 -> V_328 = V_11 -> V_84 ;
V_58 -> V_329 = V_11 -> V_81 ;
V_58 -> V_330 = 0 ;
}
static int F_192 ( struct V_10 * V_11 ,
struct V_321 * V_58 )
{
if ( V_58 -> V_330 )
return - V_250 ;
if ( ! V_58 -> V_328 || ! V_58 -> V_329 )
return - V_250 ;
if ( V_58 -> V_328 > V_11 -> V_15 . V_331 ||
V_58 -> V_329 > V_11 -> V_15 . V_331 )
return - V_250 ;
return 0 ;
}
static int F_193 ( struct V_31 * V_32 , int V_142 , int V_332 )
{
int (* F_194)( struct V_96 * , int );
struct V_10 * V_11 = V_32 -> V_11 ;
void (* F_195)( void * , int , int );
struct V_49 * V_284 ;
struct V_72 * V_333 ;
int V_60 , * V_58 ;
if ( V_332 ) {
V_58 = & V_11 -> V_84 ;
V_333 = V_11 -> V_69 ;
F_195 = F_32 ;
F_194 = F_61 ;
} else {
V_58 = & V_11 -> V_81 ;
V_333 = V_11 -> V_73 ;
F_195 = F_24 ;
F_194 = F_55 ;
}
while ( * V_58 < V_142 ) {
V_333 [ * V_58 ] . V_58 = F_196 ( V_11 -> V_45 , * V_58 , F_195 , V_332 ) ;
V_284 = F_25 ( V_32 -> V_8 , * V_58 ) ;
V_284 -> V_287 = 0 ;
if ( F_98 ( V_333 [ * V_58 ] . V_58 ) )
return F_99 ( V_333 [ * V_58 ] . V_58 ) ;
if ( ! V_333 [ * V_58 ] . V_58 )
return - V_250 ;
F_112 ( V_32 , V_204 , L_31 , * V_58 ,
( V_332 ? L_32 : L_33 ) ) ;
( * V_58 ) ++ ;
}
while ( * V_58 > V_142 ) {
( * V_58 ) -- ;
V_60 = F_197 ( V_333 [ * V_58 ] . V_58 ) ;
if ( V_60 )
return V_60 ;
F_112 ( V_32 , V_204 , L_34 , * V_58 ,
( V_332 ? L_32 : L_33 ) ) ;
}
return 0 ;
}
static int F_198 ( struct V_31 * V_32 ,
struct V_321 * V_58 )
{
int V_60 ;
V_60 = F_193 ( V_32 , V_58 -> V_328 , 1 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_193 ( V_32 , V_58 -> V_329 , 0 ) ;
if ( V_60 )
return V_60 ;
return 0 ;
}
static int F_199 ( struct V_7 * V_8 ,
struct V_321 * V_334 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_1 * V_2 ;
int V_14 , V_60 ;
V_60 = F_192 ( V_11 , V_334 ) ;
if ( V_60 < 0 )
return V_60 ;
F_23 ( V_11 ) ;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ ) {
if ( ! ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) ) )
continue;
F_78 ( V_2 -> V_8 ) ;
F_200 ( V_2 -> V_8 ) ;
}
F_128 ( V_11 -> V_45 ) ;
V_60 = F_198 ( V_32 , V_334 ) ;
if ( V_60 )
goto V_335;
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ ) {
if ( ! ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) ) )
continue;
V_60 = F_119 ( V_2 -> V_8 ,
V_11 -> V_81 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_16 ) ;
goto V_335;
}
V_60 = F_120 ( V_2 -> V_8 ,
V_11 -> V_84 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_17 ) ;
goto V_335;
}
F_201 ( V_2 -> V_8 ) ;
}
if ( F_88 ( V_11 ) ) {
V_60 = F_106 ( V_32 ) ;
if ( V_60 )
goto V_335;
F_46 ( V_8 ) ;
F_127 ( V_11 -> V_45 ) ;
F_21 ( V_11 ) ;
}
for ( V_14 = V_11 -> V_15 . V_18 , V_2 = V_11 -> V_18 ; V_14 ; V_14 -- , V_2 ++ ) {
if ( ! ( V_2 -> V_8 && F_34 ( V_2 -> V_8 ) ) )
continue;
F_202 ( V_2 -> V_8 ) ;
}
return 0 ;
V_335:
F_8 ( V_32 -> V_21 , L_35 ) ;
F_203 ( V_8 ) ;
return V_60 ;
}
static int F_204 ( struct V_7 * V_8 , struct V_336 * V_337 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_272 ] . V_108 )
return F_205 ( V_11 -> V_18 [ V_272 ] . V_108 , V_337 ) ;
else
return - V_140 ;
}
static int F_206 ( struct V_7 * V_8 , struct V_336 * V_337 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_272 ] . V_108 )
return F_207 ( V_11 -> V_18 [ V_272 ] . V_108 , V_337 ) ;
else
return - V_140 ;
}
static int F_208 ( struct V_7 * V_8 )
{
struct V_31 * V_32 = F_16 ( V_8 ) ;
struct V_10 * V_11 = V_32 -> V_11 ;
int V_272 = F_145 ( V_11 , V_32 ) ;
if ( V_11 -> V_18 [ V_272 ] . V_108 )
return F_209 ( V_11 -> V_18 [ V_272 ] . V_108 ) ;
else
return - V_140 ;
}
static void F_210 ( struct V_1 * V_2 , struct V_10 * V_11 ,
T_1 V_338 , T_1 V_339 )
{
void T_3 * V_4 = V_11 -> V_4 ;
int V_6 = V_2 -> V_6 ;
struct V_340 * V_15 = V_11 -> V_15 . V_341 + V_6 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_4 = V_4 + V_338 ;
V_2 -> V_117 = V_4 + V_339 ;
V_2 -> V_35 = V_15 -> V_342 ;
}
static int F_211 ( struct V_343 * V_15 ,
struct V_293 * V_294 )
{
struct V_344 * V_345 = V_294 -> V_21 . V_346 ;
struct V_344 * V_347 ;
int V_14 = 0 , V_60 ;
T_1 V_348 ;
if ( ! V_345 )
return - V_250 ;
if ( F_212 ( V_345 , L_36 , & V_348 ) ) {
F_8 ( & V_294 -> V_21 , L_37 ) ;
return - V_250 ;
}
V_15 -> V_18 = V_348 ;
if ( F_212 ( V_345 , L_38 , & V_348 ) ) {
F_8 ( & V_294 -> V_21 , L_39 ) ;
return - V_250 ;
}
V_15 -> V_221 = V_348 ;
V_15 -> V_341 = F_213 ( & V_294 -> V_21 , V_15 -> V_18
* sizeof( struct V_340 ) ,
V_203 ) ;
if ( ! V_15 -> V_341 )
return - V_205 ;
if ( F_212 ( V_345 , L_40 , & V_348 ) ) {
F_8 ( & V_294 -> V_21 , L_41 ) ;
return - V_250 ;
}
V_15 -> V_331 = V_348 ;
if ( F_212 ( V_345 , L_42 , & V_348 ) ) {
F_8 ( & V_294 -> V_21 , L_43 ) ;
return - V_250 ;
}
V_15 -> V_288 = V_348 ;
if ( F_212 ( V_345 , L_44 , & V_348 ) ) {
F_8 ( & V_294 -> V_21 , L_45 ) ;
return - V_250 ;
}
V_15 -> V_349 = V_348 ;
if ( F_212 ( V_345 , L_46 , & V_348 ) ) {
F_8 ( & V_294 -> V_21 , L_47 ) ;
return - V_250 ;
}
V_15 -> V_109 = V_348 ;
if ( F_214 ( V_345 , L_48 ) )
V_15 -> V_16 = 1 ;
V_60 = F_215 ( V_345 , NULL , NULL , & V_294 -> V_21 ) ;
if ( V_60 )
F_216 ( & V_294 -> V_21 , L_49 ) ;
F_217 (node, slave_node) {
struct V_340 * V_341 = V_15 -> V_341 + V_14 ;
const void * V_103 = NULL ;
int V_350 ;
const T_8 * V_351 ;
if ( strcmp ( V_347 -> V_169 , L_50 ) )
continue;
V_341 -> V_180 = F_218 ( V_347 ,
L_51 , 0 ) ;
V_351 = F_219 ( V_347 , L_52 , & V_350 ) ;
if ( V_341 -> V_180 ) {
F_10 ( & V_294 -> V_21 ,
L_53 ,
V_14 , V_341 -> V_180 -> V_182 ) ;
} else if ( F_220 ( V_347 ) ) {
V_60 = F_221 ( V_347 ) ;
if ( V_60 ) {
if ( V_60 != - V_352 )
F_8 ( & V_294 -> V_21 , L_54 , V_60 ) ;
return V_60 ;
}
V_341 -> V_180 = F_222 ( V_347 ) ;
} else if ( V_351 ) {
T_1 V_353 ;
struct V_344 * V_354 ;
struct V_293 * V_355 ;
if ( V_350 != ( sizeof( T_8 ) * 2 ) ) {
F_8 ( & V_294 -> V_21 , L_55 , V_14 ) ;
goto V_356;
}
V_354 = F_223 ( F_224 ( V_351 ) ) ;
V_353 = F_224 ( V_351 + 1 ) ;
V_355 = F_225 ( V_354 ) ;
F_226 ( V_354 ) ;
if ( ! V_355 ) {
F_8 ( & V_294 -> V_21 , L_56 ) ;
return - V_250 ;
}
snprintf ( V_341 -> V_183 , sizeof( V_341 -> V_183 ) ,
V_357 , V_355 -> V_169 , V_353 ) ;
F_227 ( & V_355 -> V_21 ) ;
} else {
F_8 ( & V_294 -> V_21 ,
L_57 ,
V_14 ) ;
goto V_356;
}
V_341 -> V_181 = F_228 ( V_347 ) ;
if ( V_341 -> V_181 < 0 ) {
F_8 ( & V_294 -> V_21 , L_58 ,
V_14 ) ;
return V_341 -> V_181 ;
}
V_356:
V_103 = F_229 ( V_347 ) ;
if ( V_103 ) {
memcpy ( V_341 -> V_103 , V_103 , V_279 ) ;
} else {
V_60 = F_230 ( & V_294 -> V_21 , V_14 ,
V_341 -> V_103 ) ;
if ( V_60 )
return V_60 ;
}
if ( V_15 -> V_16 ) {
if ( F_212 ( V_347 , L_59 ,
& V_348 ) ) {
F_8 ( & V_294 -> V_21 , L_60 ) ;
V_341 -> V_342 = V_14 + 1 ;
F_8 ( & V_294 -> V_21 , L_61 ,
V_341 -> V_342 , V_14 ) ;
} else {
V_341 -> V_342 = V_348 ;
}
}
V_14 ++ ;
if ( V_14 == V_15 -> V_18 )
break;
}
return 0 ;
}
static void F_231 ( struct V_293 * V_294 )
{
struct V_7 * V_8 = F_232 ( V_294 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
struct V_343 * V_15 = & V_11 -> V_15 ;
struct V_344 * V_345 = V_294 -> V_21 . V_346 ;
struct V_344 * V_347 ;
int V_14 = 0 ;
F_217 (node, slave_node) {
struct V_340 * V_341 = & V_15 -> V_341 [ V_14 ] ;
if ( strcmp ( V_347 -> V_169 , L_50 ) )
continue;
if ( F_220 ( V_347 ) )
F_233 ( V_347 ) ;
F_226 ( V_341 -> V_180 ) ;
V_14 ++ ;
if ( V_14 == V_15 -> V_18 )
break;
}
F_234 ( & V_294 -> V_21 ) ;
}
static int F_235 ( struct V_31 * V_32 )
{
struct V_10 * V_11 = V_32 -> V_11 ;
struct V_343 * V_15 = & V_11 -> V_15 ;
struct V_7 * V_8 ;
struct V_31 * V_358 ;
int V_60 = 0 ;
V_8 = F_236 ( sizeof( struct V_31 ) , V_324 ) ;
if ( ! V_8 ) {
F_8 ( V_11 -> V_21 , L_62 ) ;
return - V_205 ;
}
V_358 = F_16 ( V_8 ) ;
V_358 -> V_11 = V_11 ;
V_358 -> V_8 = V_8 ;
V_358 -> V_21 = & V_8 -> V_21 ;
V_358 -> V_297 = F_237 ( V_359 , V_360 ) ;
if ( F_158 ( V_15 -> V_341 [ 1 ] . V_103 ) ) {
memcpy ( V_358 -> V_103 , V_15 -> V_341 [ 1 ] . V_103 ,
V_279 ) ;
F_121 ( V_11 -> V_21 , L_63 ,
V_358 -> V_103 ) ;
} else {
F_238 ( V_358 -> V_103 ) ;
F_121 ( V_11 -> V_21 , L_64 ,
V_358 -> V_103 ) ;
}
memcpy ( V_8 -> V_280 , V_358 -> V_103 , V_279 ) ;
V_358 -> V_34 = 1 ;
V_11 -> V_18 [ 1 ] . V_8 = V_8 ;
V_8 -> V_361 |= V_362 ;
V_8 -> V_363 = & V_364 ;
V_8 -> V_365 = & V_366 ;
F_239 ( V_8 , V_11 -> V_21 ) ;
V_60 = F_240 ( V_8 ) ;
if ( V_60 ) {
F_8 ( V_11 -> V_21 , L_65 ) ;
F_241 ( V_8 ) ;
V_60 = - V_367 ;
}
return V_60 ;
}
static int F_242 ( struct V_293 * V_294 )
{
struct V_368 * V_368 ;
struct V_343 * V_15 ;
struct V_7 * V_8 ;
struct V_31 * V_32 ;
struct V_369 V_370 ;
struct V_371 V_372 ;
void T_3 * V_373 ;
void T_3 * V_374 ;
struct V_375 * V_376 , * V_377 ;
const struct V_378 * V_379 ;
struct V_380 * V_381 ;
T_1 V_382 , V_383 , V_384 ;
struct V_10 * V_11 ;
int V_60 = 0 , V_14 ;
int V_85 ;
V_11 = F_213 ( & V_294 -> V_21 , sizeof( struct V_10 ) , V_203 ) ;
if ( ! V_11 )
return - V_205 ;
V_11 -> V_21 = & V_294 -> V_21 ;
V_8 = F_236 ( sizeof( struct V_31 ) , V_324 ) ;
if ( ! V_8 ) {
F_8 ( & V_294 -> V_21 , L_66 ) ;
return - V_205 ;
}
F_243 ( V_294 , V_8 ) ;
V_32 = F_16 ( V_8 ) ;
V_32 -> V_11 = V_11 ;
V_32 -> V_8 = V_8 ;
V_32 -> V_21 = & V_8 -> V_21 ;
V_32 -> V_297 = F_237 ( V_359 , V_360 ) ;
V_11 -> V_64 = F_244 ( V_64 , 128 ) ;
V_381 = F_245 ( & V_294 -> V_21 , L_67 , V_385 ) ;
if ( F_98 ( V_381 ) ) {
V_60 = F_99 ( V_381 ) ;
F_8 ( & V_294 -> V_21 , L_68 , V_60 ) ;
goto V_386;
}
F_246 ( & V_294 -> V_21 ) ;
F_247 ( & V_294 -> V_21 ) ;
V_60 = F_117 ( & V_294 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( & V_294 -> V_21 ) ;
goto V_387;
}
V_60 = F_211 ( & V_11 -> V_15 , V_294 ) ;
if ( V_60 )
goto V_388;
V_15 = & V_11 -> V_15 ;
V_11 -> V_84 = 1 ;
V_11 -> V_81 = 1 ;
if ( F_158 ( V_15 -> V_341 [ 0 ] . V_103 ) ) {
memcpy ( V_32 -> V_103 , V_15 -> V_341 [ 0 ] . V_103 , V_279 ) ;
F_121 ( & V_294 -> V_21 , L_69 , V_32 -> V_103 ) ;
} else {
F_248 ( V_32 -> V_103 ) ;
F_121 ( & V_294 -> V_21 , L_70 , V_32 -> V_103 ) ;
}
memcpy ( V_8 -> V_280 , V_32 -> V_103 , V_279 ) ;
V_11 -> V_18 = F_213 ( & V_294 -> V_21 ,
sizeof( struct V_1 ) * V_15 -> V_18 ,
V_203 ) ;
if ( ! V_11 -> V_18 ) {
V_60 = - V_205 ;
goto V_388;
}
for ( V_14 = 0 ; V_14 < V_15 -> V_18 ; V_14 ++ )
V_11 -> V_18 [ V_14 ] . V_6 = V_14 ;
V_11 -> V_18 [ 0 ] . V_8 = V_8 ;
V_32 -> V_34 = 0 ;
V_368 = F_249 ( & V_294 -> V_21 , L_71 ) ;
if ( F_98 ( V_368 ) ) {
F_8 ( V_32 -> V_21 , L_72 ) ;
V_60 = - V_367 ;
goto V_388;
}
V_11 -> V_127 = F_250 ( V_368 ) / 1000000 ;
V_377 = F_251 ( V_294 , V_389 , 0 ) ;
V_373 = F_252 ( & V_294 -> V_21 , V_377 ) ;
if ( F_98 ( V_373 ) ) {
V_60 = F_99 ( V_373 ) ;
goto V_388;
}
V_11 -> V_4 = V_373 ;
V_11 -> V_161 = F_81 ( & V_11 -> V_4 -> V_390 ) ;
V_376 = F_251 ( V_294 , V_389 , 1 ) ;
V_11 -> V_42 = F_252 ( & V_294 -> V_21 , V_376 ) ;
if ( F_98 ( V_11 -> V_42 ) ) {
V_60 = F_99 ( V_11 -> V_42 ) ;
goto V_388;
}
memset ( & V_370 , 0 , sizeof( V_370 ) ) ;
memset ( & V_372 , 0 , sizeof( V_372 ) ) ;
switch ( V_11 -> V_161 ) {
case V_162 :
V_11 -> V_187 = V_373 + V_391 ;
V_374 = V_373 + V_392 ;
V_11 -> V_154 = V_373 + V_393 ;
V_370 . V_394 = V_373 + V_395 ;
V_370 . V_396 = V_373 + V_397 ;
V_372 . V_398 = V_373 + V_399 ;
V_382 = V_400 ;
V_384 = V_401 ;
V_383 = V_402 ;
V_370 . V_403 = 0 ;
break;
case V_174 :
case V_175 :
case V_176 :
V_11 -> V_187 = V_373 + V_404 ;
V_374 = V_373 + V_405 ;
V_11 -> V_154 = V_373 + V_406 ;
V_370 . V_394 = V_373 + V_407 ;
V_370 . V_396 = V_373 + V_408 ;
V_372 . V_398 = V_373 + V_409 ;
V_382 = V_410 ;
V_384 = V_411 ;
V_383 = V_412 ;
V_370 . V_403 =
( T_1 V_413 ) V_377 -> V_414 + V_415 ;
break;
default:
F_8 ( V_32 -> V_21 , L_73 , V_11 -> V_161 ) ;
V_60 = - V_367 ;
goto V_388;
}
for ( V_14 = 0 ; V_14 < V_11 -> V_15 . V_18 ; V_14 ++ ) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_14 ] ;
F_210 ( V_2 , V_11 , V_382 , V_383 ) ;
V_382 += V_384 ;
V_383 += V_416 ;
}
V_370 . V_21 = & V_294 -> V_21 ;
V_370 . V_417 = V_370 . V_394 + V_418 ;
V_370 . V_419 = V_370 . V_394 + V_420 ;
V_370 . V_421 = V_370 . V_396 + V_422 ;
V_370 . V_423 = V_370 . V_396 + V_424 ;
V_370 . V_425 = V_370 . V_396 + V_426 ;
V_370 . V_427 = V_15 -> V_331 ;
V_370 . V_428 = true ;
V_370 . V_429 = V_212 ;
V_370 . V_430 = V_15 -> V_349 ;
V_370 . V_431 = 16 ;
V_370 . V_432 = true ;
V_370 . V_433 = V_370 . V_403 ;
V_370 . V_127 = V_11 -> V_127 ;
V_11 -> V_45 = F_253 ( & V_370 ) ;
if ( ! V_11 -> V_45 ) {
F_8 ( V_32 -> V_21 , L_74 ) ;
V_60 = - V_205 ;
goto V_388;
}
V_11 -> V_73 [ 0 ] . V_58 = F_196 ( V_11 -> V_45 , 0 , F_24 , 0 ) ;
V_11 -> V_69 [ 0 ] . V_58 = F_196 ( V_11 -> V_45 , 0 , F_32 , 1 ) ;
if ( F_45 ( ! V_11 -> V_69 [ 0 ] . V_58 || ! V_11 -> V_73 [ 0 ] . V_58 ) ) {
F_8 ( V_32 -> V_21 , L_75 ) ;
V_60 = - V_205 ;
goto V_434;
}
V_372 . V_21 = & V_8 -> V_21 ;
V_372 . V_435 = V_435 ;
V_372 . V_288 = V_15 -> V_288 ;
V_372 . V_436 = V_15 -> V_18 ;
V_11 -> V_13 = F_254 ( & V_372 ) ;
if ( ! V_11 -> V_13 ) {
F_8 ( V_32 -> V_21 , L_76 ) ;
V_60 = - V_367 ;
goto V_434;
}
V_11 -> V_53 = F_255 ( V_11 -> V_21 , V_374 , V_11 -> V_21 -> V_346 ) ;
if ( F_98 ( V_11 -> V_53 ) ) {
V_60 = F_99 ( V_11 -> V_53 ) ;
goto V_437;
}
V_8 -> V_85 = F_256 ( V_294 , 1 ) ;
if ( V_8 -> V_85 < 0 ) {
F_8 ( V_32 -> V_21 , L_77 ) ;
V_60 = V_8 -> V_85 ;
goto V_437;
}
V_379 = F_257 ( V_438 , & V_294 -> V_21 ) ;
if ( V_379 ) {
V_294 -> V_439 = V_379 -> V_15 ;
if ( V_294 -> V_439 -> V_440 )
V_11 -> V_88 = true ;
}
V_85 = F_256 ( V_294 , 1 ) ;
if ( V_85 < 0 ) {
V_60 = V_85 ;
goto V_437;
}
V_11 -> V_89 [ 0 ] = V_85 ;
V_60 = F_258 ( & V_294 -> V_21 , V_85 , F_54 ,
0 , F_259 ( & V_294 -> V_21 ) , V_11 ) ;
if ( V_60 < 0 ) {
F_8 ( V_32 -> V_21 , L_78 , V_60 ) ;
goto V_437;
}
V_85 = F_256 ( V_294 , 2 ) ;
if ( V_85 < 0 ) {
V_60 = V_85 ;
goto V_437;
}
V_11 -> V_89 [ 1 ] = V_85 ;
V_60 = F_258 ( & V_294 -> V_21 , V_85 , F_49 ,
0 , F_259 ( & V_294 -> V_21 ) , V_11 ) ;
if ( V_60 < 0 ) {
F_8 ( V_32 -> V_21 , L_78 , V_60 ) ;
goto V_437;
}
V_8 -> V_361 |= V_362 ;
V_8 -> V_363 = & V_364 ;
V_8 -> V_365 = & V_366 ;
F_260 ( V_8 , & V_11 -> V_95 , F_61 , V_82 ) ;
F_261 ( V_8 , & V_11 -> V_91 , F_55 , V_82 ) ;
F_46 ( V_8 ) ;
F_239 ( V_8 , & V_294 -> V_21 ) ;
V_60 = F_240 ( V_8 ) ;
if ( V_60 ) {
F_8 ( V_32 -> V_21 , L_79 ) ;
V_60 = - V_367 ;
goto V_437;
}
F_82 ( V_32 , V_441 , L_80 ,
& V_377 -> V_414 , V_8 -> V_85 ) ;
if ( V_11 -> V_15 . V_16 ) {
V_60 = F_235 ( V_32 ) ;
if ( V_60 ) {
F_109 ( V_32 , V_441 , L_81 ) ;
goto V_442;
}
}
F_160 ( & V_294 -> V_21 ) ;
return 0 ;
V_442:
F_262 ( V_8 ) ;
V_437:
F_263 ( V_11 -> V_13 ) ;
V_434:
F_264 ( V_11 -> V_45 ) ;
V_388:
F_231 ( V_294 ) ;
F_129 ( & V_294 -> V_21 ) ;
V_387:
F_265 ( & V_294 -> V_21 ) ;
V_386:
F_241 ( V_32 -> V_8 ) ;
return V_60 ;
}
static int F_266 ( struct V_293 * V_294 )
{
struct V_7 * V_8 = F_232 ( V_294 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
int V_60 ;
V_60 = F_117 ( & V_294 -> V_21 ) ;
if ( V_60 < 0 ) {
F_118 ( & V_294 -> V_21 ) ;
return V_60 ;
}
if ( V_11 -> V_15 . V_16 )
F_262 ( V_11 -> V_18 [ 1 ] . V_8 ) ;
F_262 ( V_8 ) ;
F_267 ( V_11 -> V_53 ) ;
F_263 ( V_11 -> V_13 ) ;
F_264 ( V_11 -> V_45 ) ;
F_231 ( V_294 ) ;
F_129 ( & V_294 -> V_21 ) ;
F_265 ( & V_294 -> V_21 ) ;
if ( V_11 -> V_15 . V_16 )
F_241 ( V_11 -> V_18 [ 1 ] . V_8 ) ;
F_241 ( V_8 ) ;
return 0 ;
}
static int F_268 ( struct V_443 * V_21 )
{
struct V_293 * V_294 = F_174 ( V_21 ) ;
struct V_7 * V_8 = F_232 ( V_294 ) ;
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
F_269 ( V_21 ) ;
return 0 ;
}
static int F_270 ( struct V_443 * V_21 )
{
struct V_293 * V_294 = F_174 ( V_21 ) ;
struct V_7 * V_8 = F_232 ( V_294 ) ;
struct V_10 * V_11 = F_7 ( V_8 ) ;
F_247 ( V_21 ) ;
F_271 () ;
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
F_272 () ;
return 0 ;
}
