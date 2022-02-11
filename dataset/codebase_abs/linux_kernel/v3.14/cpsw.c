static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline int F_5 ( struct V_6 * V_7 , T_1 V_8 )
{
if ( V_7 -> V_9 == 0 )
return V_8 + 1 ;
else
return V_8 ;
}
static void F_6 ( struct V_10 * V_11 , bool V_12 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
int V_15 ;
if ( V_7 -> V_16 . V_17 ) {
bool V_18 = false ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ )
if ( V_7 -> V_19 [ V_15 ] . V_11 -> V_20 & V_21 )
V_18 = true ;
if ( ! V_12 && V_18 ) {
V_12 = true ;
F_8 ( & V_11 -> V_22 , L_1 ) ;
}
if ( V_12 ) {
F_9 ( V_14 , 0 , V_23 , 1 ) ;
F_10 ( & V_11 -> V_22 , L_2 ) ;
} else {
F_9 ( V_14 , 0 , V_23 , 0 ) ;
F_10 ( & V_11 -> V_22 , L_3 ) ;
}
} else {
if ( V_12 ) {
unsigned long V_24 = V_25 + V_26 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ ) {
F_9 ( V_14 , V_15 ,
V_27 , 1 ) ;
F_9 ( V_14 , V_15 ,
V_28 , 1 ) ;
}
F_9 ( V_14 , 0 , V_29 , 1 ) ;
do {
F_11 () ;
if ( F_12 ( V_14 , 0 , V_29 ) )
break;
} while ( F_13 ( V_24 , V_25 ) );
F_9 ( V_14 , 0 , V_29 , 1 ) ;
F_14 ( V_14 , V_30 <<
V_7 -> V_9 ) ;
F_9 ( V_14 , 0 , V_31 , 1 ) ;
F_10 ( & V_11 -> V_22 , L_2 ) ;
} else {
F_9 ( V_14 , 0 , V_31 , 0 ) ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ ) {
F_9 ( V_14 , V_15 ,
V_27 , 0 ) ;
F_9 ( V_14 , V_15 ,
V_28 , 0 ) ;
}
F_10 ( & V_11 -> V_22 , L_3 ) ;
}
}
}
static void F_15 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_11 -> V_20 & V_21 ) {
F_6 ( V_11 , true ) ;
return;
} else {
F_6 ( V_11 , false ) ;
}
F_14 ( V_7 -> V_14 , V_30 << V_7 -> V_9 ) ;
if ( ! F_16 ( V_11 ) ) {
struct V_32 * V_33 ;
F_17 (ha, ndev) {
F_18 ( V_7 , ( V_34 * ) V_33 -> V_35 ) ;
}
}
}
static void F_19 ( struct V_6 * V_7 )
{
F_4 ( 0xFF , & V_7 -> V_36 -> V_37 ) ;
F_4 ( 0xFF , & V_7 -> V_36 -> V_38 ) ;
F_20 ( V_7 -> V_39 , true ) ;
return;
}
static void F_21 ( struct V_6 * V_7 )
{
F_4 ( 0 , & V_7 -> V_36 -> V_37 ) ;
F_4 ( 0 , & V_7 -> V_36 -> V_38 ) ;
F_20 ( V_7 -> V_39 , false ) ;
return;
}
static void F_22 ( void * V_40 , int V_41 , int V_42 )
{
struct V_43 * V_44 = V_40 ;
struct V_10 * V_11 = V_44 -> V_22 ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( F_23 ( F_24 ( V_11 ) ) )
F_25 ( V_11 ) ;
F_26 ( V_7 -> V_45 , V_44 ) ;
V_7 -> V_46 . V_47 ++ ;
V_7 -> V_46 . V_48 += V_41 ;
F_27 ( V_44 ) ;
}
static void F_28 ( void * V_40 , int V_41 , int V_42 )
{
struct V_43 * V_44 = V_40 ;
struct V_43 * V_49 ;
struct V_10 * V_11 = V_44 -> V_22 ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_50 = 0 ;
F_29 ( V_42 , V_7 , V_11 , V_44 ) ;
if ( F_23 ( V_42 < 0 ) ) {
F_27 ( V_44 ) ;
return;
}
V_49 = F_30 ( V_11 , V_7 -> V_51 ) ;
if ( V_49 ) {
F_31 ( V_44 , V_41 ) ;
F_32 ( V_7 -> V_45 , V_44 ) ;
V_44 -> V_52 = F_33 ( V_44 , V_11 ) ;
F_34 ( V_44 ) ;
V_7 -> V_46 . V_53 += V_41 ;
V_7 -> V_46 . V_54 ++ ;
} else {
V_7 -> V_46 . V_55 ++ ;
V_49 = V_44 ;
}
V_50 = F_35 ( V_7 -> V_56 , V_49 , V_49 -> V_16 ,
F_36 ( V_49 ) , 0 ) ;
if ( F_37 ( V_50 < 0 ) )
F_27 ( V_49 ) ;
}
static T_2 F_38 ( int V_57 , void * V_58 )
{
struct V_6 * V_7 = V_58 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_59 == true ) {
F_39 ( V_7 ) ;
V_7 -> V_59 = false ;
}
if ( F_40 ( V_7 -> V_11 ) ) {
F_41 ( & V_7 -> V_60 ) ;
return V_61 ;
}
V_7 = F_42 ( V_7 , 1 ) ;
if ( ! V_7 )
return V_62 ;
if ( F_40 ( V_7 -> V_11 ) ) {
F_41 ( & V_7 -> V_60 ) ;
return V_61 ;
}
return V_62 ;
}
static int F_43 ( struct V_63 * V_60 , int V_64 )
{
struct V_6 * V_7 = F_44 ( V_60 ) ;
int V_65 , V_66 ;
V_65 = F_45 ( V_7 -> V_67 , 128 ) ;
if ( V_65 )
F_46 ( V_7 -> V_39 , V_68 ) ;
V_66 = F_45 ( V_7 -> V_56 , V_64 ) ;
if ( V_66 < V_64 ) {
struct V_6 * V_69 ;
F_47 ( V_60 ) ;
F_19 ( V_7 ) ;
F_46 ( V_7 -> V_39 , V_70 ) ;
V_69 = F_42 ( V_7 , 0 ) ;
if ( V_69 -> V_59 == false ) {
V_69 -> V_59 = true ;
F_48 ( V_7 ) ;
}
}
if ( V_66 || V_65 )
F_49 ( V_7 , V_71 , L_4 ,
V_66 , V_65 ) ;
return V_66 ;
}
static inline void F_50 ( const char * V_72 , void T_3 * V_73 )
{
unsigned long V_24 = V_25 + V_26 ;
F_4 ( 1 , V_73 ) ;
do {
F_11 () ;
} while ( ( F_2 ( V_73 ) & 1 ) && F_13 ( V_24 , V_25 ) );
F_51 ( F_2 ( V_73 ) & 1 , L_5 , V_72 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_3 ( V_2 , F_53 ( V_7 -> V_74 ) , V_75 ) ;
F_3 ( V_2 , F_54 ( V_7 -> V_74 ) , V_76 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_6 * V_7 , bool * V_77 )
{
struct V_78 * V_79 = V_2 -> V_79 ;
T_1 V_80 = 0 ;
T_1 V_81 ;
if ( ! V_79 )
return;
V_81 = F_5 ( V_7 , V_2 -> V_8 ) ;
if ( V_79 -> V_77 ) {
V_80 = V_7 -> V_16 . V_80 ;
F_9 ( V_7 -> V_14 , V_81 ,
V_82 , V_83 ) ;
if ( V_79 -> V_84 == 1000 )
V_80 |= F_56 ( 7 ) ;
if ( V_79 -> V_85 )
V_80 |= F_56 ( 0 ) ;
if ( V_79 -> V_84 == 100 )
V_80 |= F_56 ( 15 ) ;
else if ( V_79 -> V_84 == 10 )
V_80 |= F_56 ( 18 ) ;
* V_77 = true ;
} else {
V_80 = 0 ;
F_9 ( V_7 -> V_14 , V_81 ,
V_82 , V_86 ) ;
}
if ( V_80 != V_2 -> V_80 ) {
F_57 ( V_79 ) ;
F_4 ( V_80 , & V_2 -> V_87 -> V_80 ) ;
}
V_2 -> V_80 = V_80 ;
}
static void F_58 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
bool V_77 = false ;
F_59 ( V_7 , F_55 , V_7 , & V_77 ) ;
if ( V_77 ) {
F_60 ( V_11 ) ;
if ( F_40 ( V_11 ) )
F_25 ( V_11 ) ;
} else {
F_61 ( V_11 ) ;
F_62 ( V_11 ) ;
}
}
static int F_63 ( struct V_10 * V_11 ,
struct V_88 * V_89 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_89 -> V_90 = V_7 -> V_91 ;
return 0 ;
}
static int F_64 ( struct V_10 * V_11 ,
struct V_88 * V_89 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
T_1 V_92 ;
T_1 V_93 = 0 ;
T_1 V_94 = 0 ;
T_1 V_95 = 1 ;
T_1 V_91 = 0 ;
if ( ! V_89 -> V_90 )
return - V_96 ;
V_91 = V_89 -> V_90 ;
V_92 = F_65 ( & V_7 -> V_36 -> V_97 ) ;
V_94 = V_7 -> V_98 * 4 ;
if ( V_91 < V_99 )
V_91 = V_99 ;
if ( V_91 > V_100 ) {
V_95 = V_101 / V_94 ;
if ( V_95 > 1 ) {
V_94 *= V_95 ;
if ( V_91 > ( V_100 * V_95 ) )
V_91 = ( V_100
* V_95 ) ;
} else {
V_95 = 1 ;
V_91 = V_100 ;
}
}
V_93 = ( 1000 * V_95 ) / V_91 ;
F_66 ( V_93 , & V_7 -> V_36 -> V_102 ) ;
F_66 ( V_93 , & V_7 -> V_36 -> V_103 ) ;
V_92 |= V_104 ;
V_92 &= ( ~ V_101 ) ;
V_92 |= ( V_94 & V_101 ) ;
F_66 ( V_92 , & V_7 -> V_36 -> V_97 ) ;
F_67 ( V_7 , V_105 , L_6 , V_91 ) ;
if ( V_7 -> V_16 . V_17 ) {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ ) {
V_7 = F_7 ( V_7 -> V_19 [ V_15 ] . V_11 ) ;
V_7 -> V_91 = V_91 ;
}
} else {
V_7 -> V_91 = V_91 ;
}
return 0 ;
}
static int F_68 ( struct V_10 * V_11 , int V_106 )
{
switch ( V_106 ) {
case V_107 :
return V_108 ;
default:
return - V_109 ;
}
}
static void F_69 ( struct V_10 * V_11 , T_1 V_110 , V_34 * V_16 )
{
V_34 * V_111 = V_16 ;
int V_15 ;
switch ( V_110 ) {
case V_107 :
for ( V_15 = 0 ; V_15 < V_108 ; V_15 ++ ) {
memcpy ( V_111 , V_112 [ V_15 ] . V_113 ,
V_114 ) ;
V_111 += V_114 ;
}
break;
}
}
static void F_70 ( struct V_10 * V_11 ,
struct V_115 * V_46 , T_4 * V_16 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
struct V_116 V_117 ;
struct V_116 V_118 ;
T_1 V_5 ;
V_34 * V_111 ;
int V_15 ;
F_71 ( V_7 -> V_56 , & V_117 ) ;
F_71 ( V_7 -> V_67 , & V_118 ) ;
for ( V_15 = 0 ; V_15 < V_108 ; V_15 ++ ) {
switch ( V_112 [ V_15 ] . type ) {
case V_119 :
V_5 = F_65 ( V_7 -> V_120 +
V_112 [ V_15 ] . V_121 ) ;
V_16 [ V_15 ] = V_5 ;
break;
case V_122 :
V_111 = ( V_34 * ) & V_117 +
V_112 [ V_15 ] . V_121 ;
V_16 [ V_15 ] = * ( T_1 * ) V_111 ;
break;
case V_123 :
V_111 = ( V_34 * ) & V_118 +
V_112 [ V_15 ] . V_121 ;
V_16 [ V_15 ] = * ( T_1 * ) V_111 ;
break;
}
}
}
static inline int F_72 ( char * V_124 , int V_125 , const char * V_126 , T_1 V_5 )
{
static char * V_127 = L_7 ;
if ( ! V_5 )
return 0 ;
else
return snprintf ( V_124 , V_125 , L_8 , V_126 ,
V_127 + strlen ( V_126 ) , V_5 ) ;
}
static int F_73 ( struct V_6 * V_7 )
{
T_1 V_15 ;
T_1 V_128 = 0 ;
if ( ! V_7 -> V_16 . V_17 )
return 0 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ )
if ( V_7 -> V_19 [ V_15 ] . V_129 )
V_128 ++ ;
return V_128 ;
}
static inline int F_74 ( struct V_10 * V_11 ,
struct V_6 * V_7 , struct V_43 * V_44 )
{
if ( ! V_7 -> V_16 . V_17 )
return F_35 ( V_7 -> V_67 , V_44 , V_44 -> V_16 ,
V_44 -> V_41 , 0 ) ;
if ( V_11 == F_75 ( V_7 , 0 ) )
return F_35 ( V_7 -> V_67 , V_44 , V_44 -> V_16 ,
V_44 -> V_41 , 1 ) ;
else
return F_35 ( V_7 -> V_67 , V_44 , V_44 -> V_16 ,
V_44 -> V_41 , 2 ) ;
}
static inline void F_76 (
struct V_6 * V_7 , struct V_1 * V_2 ,
T_1 V_81 )
{
T_1 V_130 = 1 << V_81 | 1 << V_7 -> V_9 ;
if ( V_7 -> V_131 == V_132 )
F_3 ( V_2 , V_2 -> V_133 , V_134 ) ;
else
F_3 ( V_2 , V_2 -> V_133 , V_135 ) ;
F_77 ( V_7 -> V_14 , V_2 -> V_133 , V_130 ,
V_130 , V_130 , 0 ) ;
F_78 ( V_7 -> V_14 , V_7 -> V_11 -> V_136 ,
V_130 , V_137 , V_2 -> V_133 , 0 ) ;
F_79 ( V_7 -> V_14 , V_7 -> V_74 ,
V_7 -> V_9 , V_137 , V_2 -> V_133 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
char V_126 [ 32 ] ;
snprintf ( V_126 , sizeof( V_126 ) , L_9 , V_2 -> V_8 ) ;
F_50 ( V_126 , & V_2 -> V_87 -> F_50 ) ;
}
static void F_81 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
T_1 V_81 ;
F_80 ( V_2 ) ;
F_4 ( V_138 , & V_2 -> V_87 -> V_139 ) ;
switch ( V_7 -> V_131 ) {
case V_132 :
F_3 ( V_2 , V_140 , V_141 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
F_3 ( V_2 , V_140 , V_145 ) ;
break;
}
F_4 ( V_7 -> V_51 , & V_2 -> V_87 -> V_146 ) ;
F_52 ( V_2 , V_7 ) ;
V_2 -> V_80 = 0 ;
V_81 = F_5 ( V_7 , V_2 -> V_8 ) ;
if ( V_7 -> V_16 . V_17 )
F_76 ( V_7 , V_2 , V_81 ) ;
else
F_78 ( V_7 -> V_14 , V_7 -> V_11 -> V_136 ,
1 << V_81 , 0 , 0 , V_147 ) ;
V_2 -> V_79 = F_82 ( V_7 -> V_11 , V_2 -> V_16 -> V_148 ,
& F_58 , V_2 -> V_16 -> V_149 ) ;
if ( F_83 ( V_2 -> V_79 ) ) {
F_8 ( V_7 -> V_22 , L_10 ,
V_2 -> V_16 -> V_148 , V_2 -> V_8 ) ;
V_2 -> V_79 = NULL ;
} else {
F_84 ( V_7 -> V_22 , L_11 ,
V_2 -> V_79 -> V_148 ) ;
F_85 ( V_2 -> V_79 ) ;
F_86 ( & V_7 -> V_150 -> V_22 , V_2 -> V_79 -> V_151 ,
V_2 -> V_8 ) ;
}
}
static inline void F_87 ( struct V_6 * V_7 )
{
const int V_152 = V_7 -> V_16 . V_153 ;
const int V_154 = V_7 -> V_9 ;
T_1 V_73 ;
int V_15 ;
V_73 = ( V_7 -> V_131 == V_132 ) ? V_134 :
V_135 ;
F_66 ( V_152 , & V_7 -> V_155 -> V_133 ) ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ )
F_3 ( V_7 -> V_19 + V_15 , V_152 , V_73 ) ;
F_77 ( V_7 -> V_14 , V_152 , V_30 << V_154 ,
V_30 << V_154 , V_30 << V_154 ,
( V_156 | V_157 ) << V_154 ) ;
}
static void F_88 ( struct V_6 * V_7 )
{
T_1 V_158 ;
T_1 V_159 ;
F_50 ( L_12 , & V_7 -> V_4 -> F_50 ) ;
F_89 ( V_7 -> V_14 ) ;
F_9 ( V_7 -> V_14 , V_7 -> V_9 , V_160 ,
V_161 ) ;
V_158 = F_65 ( & V_7 -> V_4 -> V_162 ) ;
V_158 |= V_163 ;
F_66 ( V_158 , & V_7 -> V_4 -> V_162 ) ;
V_159 = ( V_7 -> V_16 . V_17 ) ? V_164 :
V_165 ;
F_66 ( V_159 , & V_7 -> V_155 -> V_166 ) ;
F_4 ( V_167 ,
& V_7 -> V_155 -> V_168 ) ;
F_4 ( 0 , & V_7 -> V_155 -> V_169 ) ;
F_9 ( V_7 -> V_14 , V_7 -> V_9 ,
V_82 , V_83 ) ;
if ( ! V_7 -> V_16 . V_17 ) {
F_79 ( V_7 -> V_14 , V_7 -> V_74 , V_7 -> V_9 ,
0 , 0 ) ;
F_78 ( V_7 -> V_14 , V_7 -> V_11 -> V_136 ,
1 << V_7 -> V_9 , 0 , 0 , V_147 ) ;
}
}
static void F_90 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
T_1 V_81 ;
V_81 = F_5 ( V_7 , V_2 -> V_8 ) ;
if ( ! V_2 -> V_79 )
return;
F_91 ( V_2 -> V_79 ) ;
F_92 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
F_9 ( V_7 -> V_14 , V_81 ,
V_82 , V_86 ) ;
}
static int F_93 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
struct V_6 * V_69 ;
int V_15 , V_50 ;
T_1 V_73 ;
if ( ! F_73 ( V_7 ) )
F_21 ( V_7 ) ;
F_61 ( V_11 ) ;
F_94 ( & V_7 -> V_150 -> V_22 ) ;
V_73 = V_7 -> V_131 ;
F_84 ( V_7 -> V_22 , L_13 ,
F_95 ( V_73 ) , F_96 ( V_73 ) ,
F_97 ( V_73 ) ) ;
if ( ! F_73 ( V_7 ) )
F_88 ( V_7 ) ;
F_59 ( V_7 , F_81 , V_7 ) ;
if ( ! V_7 -> V_16 . V_17 )
F_87 ( V_7 ) ;
if ( ! F_73 ( V_7 ) ) {
F_98 ( V_7 -> V_39 , V_170 , 1 ) ;
F_98 ( V_7 -> V_39 , V_171 , 0 ) ;
F_4 ( 0 , & V_7 -> V_4 -> V_172 ) ;
F_4 ( 0x7 , & V_7 -> V_4 -> V_173 ) ;
if ( F_37 ( ! V_7 -> V_16 . V_174 ) )
V_7 -> V_16 . V_174 = 128 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_174 ; V_15 ++ ) {
struct V_43 * V_44 ;
V_50 = - V_175 ;
V_44 = F_99 ( V_7 -> V_11 ,
V_7 -> V_51 , V_176 ) ;
if ( ! V_44 )
goto V_177;
V_50 = F_35 ( V_7 -> V_56 , V_44 , V_44 -> V_16 ,
F_36 ( V_44 ) , 0 ) ;
if ( V_50 < 0 ) {
F_100 ( V_44 ) ;
goto V_177;
}
}
F_101 ( V_7 , V_178 , L_14 , V_15 ) ;
if ( F_102 ( & V_7 -> V_150 -> V_22 , V_7 -> V_45 ,
V_7 -> V_16 . V_179 ,
V_7 -> V_16 . V_180 ) )
F_8 ( V_7 -> V_22 , L_15 ) ;
}
if ( V_7 -> V_91 != 0 ) {
struct V_88 V_89 ;
V_89 . V_90 = ( V_7 -> V_91 << 4 ) ;
F_64 ( V_11 , & V_89 ) ;
}
V_69 = F_42 ( V_7 , 0 ) ;
if ( V_69 -> V_59 == false ) {
if ( ( V_7 == V_69 ) || ! F_40 ( V_69 -> V_11 ) ) {
V_69 -> V_59 = true ;
F_48 ( V_69 ) ;
}
}
F_103 ( & V_7 -> V_60 ) ;
F_104 ( V_7 -> V_39 ) ;
F_19 ( V_7 ) ;
F_46 ( V_7 -> V_39 , V_70 ) ;
F_46 ( V_7 -> V_39 , V_68 ) ;
if ( V_7 -> V_16 . V_17 )
V_7 -> V_19 [ V_7 -> V_181 ] . V_129 = true ;
return 0 ;
V_177:
F_105 ( V_7 -> V_39 ) ;
F_59 ( V_7 , F_90 , V_7 ) ;
F_106 ( & V_7 -> V_150 -> V_22 ) ;
F_61 ( V_7 -> V_11 ) ;
return V_50 ;
}
static int F_107 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_101 ( V_7 , V_182 , L_16 ) ;
F_62 ( V_7 -> V_11 ) ;
F_108 ( & V_7 -> V_60 ) ;
F_61 ( V_7 -> V_11 ) ;
if ( F_73 ( V_7 ) <= 1 ) {
F_109 ( V_7 -> V_45 ) ;
F_21 ( V_7 ) ;
F_20 ( V_7 -> V_39 , false ) ;
F_105 ( V_7 -> V_39 ) ;
F_110 ( V_7 -> V_14 ) ;
}
F_59 ( V_7 , F_90 , V_7 ) ;
F_106 ( & V_7 -> V_150 -> V_22 ) ;
if ( V_7 -> V_16 . V_17 )
V_7 -> V_19 [ V_7 -> V_181 ] . V_129 = false ;
return 0 ;
}
static T_5 F_111 ( struct V_43 * V_44 ,
struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_50 ;
V_11 -> V_183 = V_25 ;
if ( F_112 ( V_44 , V_184 ) ) {
F_113 ( V_7 , V_185 , L_17 ) ;
V_7 -> V_46 . V_186 ++ ;
return V_187 ;
}
if ( F_114 ( V_44 ) -> V_188 & V_189 &&
V_7 -> V_45 -> V_190 )
F_114 ( V_44 ) -> V_188 |= V_191 ;
F_115 ( V_44 ) ;
V_50 = F_74 ( V_11 , V_7 , V_44 ) ;
if ( F_23 ( V_50 != 0 ) ) {
F_113 ( V_7 , V_185 , L_18 ) ;
goto V_192;
}
if ( F_23 ( ! F_116 ( V_7 -> V_67 ) ) )
F_62 ( V_11 ) ;
return V_187 ;
V_192:
V_7 -> V_46 . V_186 ++ ;
F_62 ( V_11 ) ;
return V_193 ;
}
static void F_117 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_19 [ V_7 -> V_16 . V_194 ] ;
T_1 V_195 , V_196 ;
if ( ! V_7 -> V_45 -> V_190 && ! V_7 -> V_45 -> V_197 ) {
F_3 ( V_2 , 0 , V_198 ) ;
return;
}
V_196 = ( 30 << V_199 ) | V_200 ;
V_195 = V_201 << V_202 ;
if ( V_7 -> V_45 -> V_190 )
V_195 |= V_203 ;
if ( V_7 -> V_45 -> V_197 )
V_195 |= V_204 ;
F_3 ( V_2 , V_195 , V_198 ) ;
F_3 ( V_2 , V_196 , V_205 ) ;
}
static void F_118 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
T_1 V_206 , V_207 ;
if ( V_7 -> V_16 . V_17 )
V_2 = & V_7 -> V_19 [ V_7 -> V_181 ] ;
else
V_2 = & V_7 -> V_19 [ V_7 -> V_16 . V_194 ] ;
V_206 = F_1 ( V_2 , V_208 ) ;
V_206 &= ~ V_209 ;
if ( V_7 -> V_45 -> V_190 )
V_206 |= V_210 ;
if ( V_7 -> V_45 -> V_197 )
V_206 |= V_211 ;
V_207 = ( 30 << V_212 ) | V_201 ;
F_3 ( V_2 , V_207 , V_213 ) ;
F_3 ( V_2 , V_206 , V_208 ) ;
F_4 ( V_200 , & V_7 -> V_4 -> V_214 ) ;
}
static int F_119 ( struct V_10 * V_22 , struct V_215 * V_216 )
{
struct V_6 * V_7 = F_7 ( V_22 ) ;
struct V_45 * V_45 = V_7 -> V_45 ;
struct V_217 V_218 ;
if ( V_7 -> V_131 != V_132 &&
V_7 -> V_131 != V_142 )
return - V_109 ;
if ( F_120 ( & V_218 , V_216 -> V_219 , sizeof( V_218 ) ) )
return - V_220 ;
if ( V_218 . V_20 )
return - V_96 ;
if ( V_218 . V_221 != V_222 && V_218 . V_221 != V_223 )
return - V_224 ;
switch ( V_218 . V_225 ) {
case V_226 :
V_45 -> V_197 = 0 ;
break;
case V_227 :
case V_228 :
case V_229 :
case V_230 :
return - V_224 ;
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
V_45 -> V_197 = 1 ;
V_218 . V_225 = V_237 ;
break;
default:
return - V_224 ;
}
V_45 -> V_190 = V_218 . V_221 == V_223 ;
switch ( V_7 -> V_131 ) {
case V_132 :
F_117 ( V_7 ) ;
break;
case V_142 :
F_118 ( V_7 ) ;
break;
default:
F_37 ( 1 ) ;
}
return F_121 ( V_216 -> V_219 , & V_218 , sizeof( V_218 ) ) ? - V_220 : 0 ;
}
static int F_122 ( struct V_10 * V_22 , struct V_215 * V_216 )
{
struct V_6 * V_7 = F_7 ( V_22 ) ;
struct V_45 * V_45 = V_7 -> V_45 ;
struct V_217 V_218 ;
if ( V_7 -> V_131 != V_132 &&
V_7 -> V_131 != V_142 )
return - V_109 ;
V_218 . V_20 = 0 ;
V_218 . V_221 = V_45 -> V_190 ? V_223 : V_222 ;
V_218 . V_225 = ( V_45 -> V_197 ?
V_237 : V_226 ) ;
return F_121 ( V_216 -> V_219 , & V_218 , sizeof( V_218 ) ) ? - V_220 : 0 ;
}
static int F_123 ( struct V_10 * V_22 , struct V_215 * V_240 , int V_241 )
{
struct V_6 * V_7 = F_7 ( V_22 ) ;
struct V_242 * V_16 = F_124 ( V_240 ) ;
int V_243 = F_125 ( V_7 ) ;
if ( ! F_40 ( V_22 ) )
return - V_96 ;
switch ( V_241 ) {
#ifdef F_126
case V_244 :
return F_119 ( V_22 , V_240 ) ;
case V_245 :
return F_122 ( V_22 , V_240 ) ;
#endif
case V_246 :
V_16 -> V_148 = V_7 -> V_19 [ V_243 ] . V_79 -> V_35 ;
break;
default:
return - V_247 ;
}
return 0 ;
}
static void F_127 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_113 ( V_7 , V_185 , L_19 ) ;
V_7 -> V_46 . V_248 ++ ;
F_21 ( V_7 ) ;
F_20 ( V_7 -> V_39 , false ) ;
F_128 ( V_7 -> V_67 ) ;
F_129 ( V_7 -> V_67 ) ;
F_20 ( V_7 -> V_39 , true ) ;
F_19 ( V_7 ) ;
F_46 ( V_7 -> V_39 , V_70 ) ;
F_46 ( V_7 -> V_39 , V_68 ) ;
}
static int F_130 ( struct V_10 * V_11 , void * V_111 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
struct V_249 * V_35 = (struct V_249 * ) V_111 ;
int V_20 = 0 ;
T_6 V_250 = 0 ;
if ( ! F_131 ( V_35 -> V_251 ) )
return - V_252 ;
if ( V_7 -> V_16 . V_17 ) {
V_250 = V_7 -> V_19 [ V_7 -> V_181 ] . V_133 ;
V_20 = V_137 ;
}
F_132 ( V_7 -> V_14 , V_7 -> V_74 , V_7 -> V_9 ,
V_20 , V_250 ) ;
F_79 ( V_7 -> V_14 , V_35 -> V_251 , V_7 -> V_9 ,
V_20 , V_250 ) ;
memcpy ( V_7 -> V_74 , V_35 -> V_251 , V_253 ) ;
memcpy ( V_11 -> V_254 , V_7 -> V_74 , V_253 ) ;
F_59 ( V_7 , F_52 , V_7 ) ;
return 0 ;
}
static struct V_255 * F_133 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
return & V_7 -> V_46 ;
}
static void F_134 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_21 ( V_7 ) ;
F_20 ( V_7 -> V_39 , false ) ;
F_38 ( V_11 -> V_57 , V_7 ) ;
F_20 ( V_7 -> V_39 , true ) ;
F_19 ( V_7 ) ;
F_46 ( V_7 -> V_39 , V_70 ) ;
F_46 ( V_7 -> V_39 , V_68 ) ;
}
static inline int F_135 ( struct V_6 * V_7 ,
unsigned short V_250 )
{
int V_50 ;
V_50 = F_77 ( V_7 -> V_14 , V_250 ,
V_30 << V_7 -> V_9 ,
0 , V_30 << V_7 -> V_9 ,
( V_156 | V_157 ) << V_7 -> V_9 ) ;
if ( V_50 != 0 )
return V_50 ;
V_50 = F_79 ( V_7 -> V_14 , V_7 -> V_74 ,
V_7 -> V_9 , V_137 , V_250 ) ;
if ( V_50 != 0 )
goto V_256;
V_50 = F_78 ( V_7 -> V_14 , V_7 -> V_11 -> V_136 ,
V_30 << V_7 -> V_9 ,
V_137 , V_250 , 0 ) ;
if ( V_50 != 0 )
goto V_257;
return 0 ;
V_257:
F_132 ( V_7 -> V_14 , V_7 -> V_74 ,
V_7 -> V_9 , V_137 , V_250 ) ;
V_256:
F_136 ( V_7 -> V_14 , V_250 , 0 ) ;
return V_50 ;
}
static int F_137 ( struct V_10 * V_11 ,
T_7 V_258 , T_6 V_250 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_250 == V_7 -> V_16 . V_153 )
return 0 ;
F_84 ( V_7 -> V_22 , L_20 , V_250 ) ;
return F_135 ( V_7 , V_250 ) ;
}
static int F_138 ( struct V_10 * V_11 ,
T_7 V_258 , T_6 V_250 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_50 ;
if ( V_250 == V_7 -> V_16 . V_153 )
return 0 ;
F_84 ( V_7 -> V_22 , L_21 , V_250 ) ;
V_50 = F_136 ( V_7 -> V_14 , V_250 , 0 ) ;
if ( V_50 != 0 )
return V_50 ;
V_50 = F_132 ( V_7 -> V_14 , V_7 -> V_74 ,
V_7 -> V_9 , V_137 , V_250 ) ;
if ( V_50 != 0 )
return V_50 ;
return F_139 ( V_7 -> V_14 , V_7 -> V_11 -> V_136 ,
0 , V_137 , V_250 ) ;
}
static void F_140 ( struct V_10 * V_11 ,
struct V_259 * V_260 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_141 ( V_260 -> V_261 , L_22 , sizeof( V_260 -> V_261 ) ) ;
F_141 ( V_260 -> V_131 , L_23 , sizeof( V_260 -> V_131 ) ) ;
F_141 ( V_260 -> V_262 , V_7 -> V_150 -> V_126 , sizeof( V_260 -> V_262 ) ) ;
}
static T_1 F_142 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
return V_7 -> V_263 ;
}
static void F_143 ( struct V_10 * V_11 , T_1 V_264 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_7 -> V_263 = V_264 ;
}
static int F_144 ( struct V_10 * V_11 ,
struct V_265 * V_260 )
{
#ifdef F_126
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_260 -> V_266 =
V_267 |
V_268 |
V_269 |
V_270 |
V_271 |
V_272 ;
V_260 -> V_273 = V_7 -> V_45 -> V_273 ;
V_260 -> V_274 =
( 1 << V_222 ) |
( 1 << V_223 ) ;
V_260 -> V_275 =
( 1 << V_226 ) |
( 1 << V_237 ) ;
#else
V_260 -> V_266 =
V_268 |
V_270 |
V_271 ;
V_260 -> V_273 = - 1 ;
V_260 -> V_274 = 0 ;
V_260 -> V_275 = 0 ;
#endif
return 0 ;
}
static int F_145 ( struct V_10 * V_11 ,
struct V_276 * V_277 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_243 = F_125 ( V_7 ) ;
if ( V_7 -> V_19 [ V_243 ] . V_79 )
return F_146 ( V_7 -> V_19 [ V_243 ] . V_79 , V_277 ) ;
else
return - V_109 ;
}
static int F_147 ( struct V_10 * V_11 , struct V_276 * V_277 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_243 = F_125 ( V_7 ) ;
if ( V_7 -> V_19 [ V_243 ] . V_79 )
return F_148 ( V_7 -> V_19 [ V_243 ] . V_79 , V_277 ) ;
else
return - V_109 ;
}
static void F_149 ( struct V_10 * V_11 , struct V_278 * V_279 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_243 = F_125 ( V_7 ) ;
V_279 -> V_280 = 0 ;
V_279 -> V_281 = 0 ;
if ( V_7 -> V_19 [ V_243 ] . V_79 )
F_150 ( V_7 -> V_19 [ V_243 ] . V_79 , V_279 ) ;
}
static int F_151 ( struct V_10 * V_11 , struct V_278 * V_279 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_243 = F_125 ( V_7 ) ;
if ( V_7 -> V_19 [ V_243 ] . V_79 )
return F_152 ( V_7 -> V_19 [ V_243 ] . V_79 , V_279 ) ;
else
return - V_109 ;
}
static void F_153 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_282 , T_1 V_283 )
{
void T_3 * V_4 = V_7 -> V_4 ;
int V_8 = V_2 -> V_8 ;
struct V_284 * V_16 = V_7 -> V_16 . V_285 + V_8 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_4 = V_4 + V_282 ;
V_2 -> V_87 = V_4 + V_283 ;
V_2 -> V_133 = V_16 -> V_286 ;
}
static int F_154 ( struct V_287 * V_16 ,
struct V_288 * V_150 )
{
struct V_289 * V_290 = V_150 -> V_22 . V_291 ;
struct V_289 * V_292 ;
int V_15 = 0 , V_50 ;
T_1 V_293 ;
if ( ! V_290 )
return - V_96 ;
if ( F_155 ( V_290 , L_24 , & V_293 ) ) {
F_156 ( L_25 ) ;
return - V_96 ;
}
V_16 -> V_19 = V_293 ;
if ( F_155 ( V_290 , L_26 , & V_293 ) ) {
F_156 ( L_27 ) ;
return - V_96 ;
}
V_16 -> V_194 = V_293 ;
if ( F_155 ( V_290 , L_28 , & V_293 ) ) {
F_156 ( L_29 ) ;
return - V_96 ;
}
V_16 -> V_179 = V_293 ;
if ( F_155 ( V_290 , L_30 , & V_293 ) ) {
F_156 ( L_31 ) ;
return - V_96 ;
}
V_16 -> V_180 = V_293 ;
V_16 -> V_285 = F_157 ( & V_150 -> V_22 , V_16 -> V_19
* sizeof( struct V_284 ) ,
V_176 ) ;
if ( ! V_16 -> V_285 )
return - V_175 ;
if ( F_155 ( V_290 , L_32 , & V_293 ) ) {
F_156 ( L_33 ) ;
return - V_96 ;
}
V_16 -> V_294 = V_293 ;
if ( F_155 ( V_290 , L_34 , & V_293 ) ) {
F_156 ( L_35 ) ;
return - V_96 ;
}
V_16 -> V_295 = V_293 ;
if ( F_155 ( V_290 , L_36 , & V_293 ) ) {
F_156 ( L_37 ) ;
return - V_96 ;
}
V_16 -> V_296 = V_293 ;
if ( F_155 ( V_290 , L_38 , & V_293 ) ) {
F_156 ( L_39 ) ;
return - V_96 ;
}
V_16 -> V_174 = V_293 ;
if ( F_155 ( V_290 , L_40 , & V_293 ) ) {
F_156 ( L_41 ) ;
return - V_96 ;
}
V_16 -> V_80 = V_293 ;
if ( F_158 ( V_290 , L_42 ) )
V_16 -> V_17 = 1 ;
V_50 = F_159 ( V_290 , NULL , NULL , & V_150 -> V_22 ) ;
if ( V_50 )
F_160 ( L_43 ) ;
F_161 (node, slave_node) {
struct V_284 * V_285 = V_16 -> V_285 + V_15 ;
const void * V_74 = NULL ;
T_1 V_297 ;
int V_298 ;
const T_8 * V_299 ;
struct V_289 * V_300 ;
struct V_288 * V_301 ;
if ( strcmp ( V_292 -> V_126 , L_44 ) )
continue;
V_299 = F_162 ( V_292 , L_45 , & V_298 ) ;
if ( ( V_299 == NULL ) || ( V_298 != ( sizeof( void * ) * 2 ) ) ) {
F_156 ( L_46 , V_15 ) ;
return - V_96 ;
}
V_300 = F_163 ( F_164 ( V_299 ) ) ;
V_297 = F_164 ( V_299 + 1 ) ;
V_301 = F_165 ( V_300 ) ;
if ( strncmp ( V_301 -> V_126 , L_47 , 4 ) == 0 ) {
struct V_302 * V_303 = F_166 ( & V_301 -> V_22 ) ;
snprintf ( V_285 -> V_148 , sizeof( V_285 -> V_148 ) ,
V_304 , V_303 -> V_305 , V_297 ) ;
} else {
snprintf ( V_285 -> V_148 , sizeof( V_285 -> V_148 ) ,
V_304 , V_301 -> V_126 , V_297 ) ;
}
V_74 = F_167 ( V_292 ) ;
if ( V_74 )
memcpy ( V_285 -> V_74 , V_74 , V_253 ) ;
V_285 -> V_149 = F_168 ( V_292 ) ;
if ( V_285 -> V_149 < 0 ) {
F_156 ( L_48 ,
V_15 ) ;
return V_285 -> V_149 ;
}
if ( V_16 -> V_17 ) {
if ( F_155 ( V_292 , L_49 ,
& V_293 ) ) {
F_156 ( L_50 ) ;
V_285 -> V_286 = V_15 + 1 ;
F_156 ( L_51 ,
V_285 -> V_286 , V_15 ) ;
} else {
V_285 -> V_286 = V_293 ;
}
}
V_15 ++ ;
if ( V_15 == V_16 -> V_19 )
break;
}
return 0 ;
}
static int F_169 ( struct V_288 * V_150 ,
struct V_6 * V_7 )
{
struct V_287 * V_16 = & V_7 -> V_16 ;
struct V_10 * V_11 ;
struct V_6 * V_306 ;
int V_50 = 0 , V_15 ;
V_11 = F_170 ( sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
F_156 ( L_52 ) ;
return - V_175 ;
}
V_306 = F_7 ( V_11 ) ;
F_171 ( & V_306 -> V_307 ) ;
V_306 -> V_16 = * V_16 ;
V_306 -> V_150 = V_150 ;
V_306 -> V_11 = V_11 ;
V_306 -> V_22 = & V_11 -> V_22 ;
V_306 -> V_263 = F_172 ( V_308 , V_309 ) ;
V_306 -> V_51 = F_173 ( V_51 , 128 ) ;
if ( F_131 ( V_16 -> V_285 [ 1 ] . V_74 ) ) {
memcpy ( V_306 -> V_74 , V_16 -> V_285 [ 1 ] . V_74 ,
V_253 ) ;
F_174 ( L_53 , V_306 -> V_74 ) ;
} else {
F_175 ( V_306 -> V_74 ) ;
F_174 ( L_54 , V_306 -> V_74 ) ;
}
memcpy ( V_11 -> V_254 , V_306 -> V_74 , V_253 ) ;
V_306 -> V_19 = V_7 -> V_19 ;
V_306 -> V_310 = V_7 -> V_310 ;
V_306 -> V_91 = 0 ;
V_306 -> V_98 = V_7 -> V_98 ;
V_306 -> V_4 = V_7 -> V_4 ;
V_306 -> V_9 = V_7 -> V_9 ;
V_306 -> V_155 = V_7 -> V_155 ;
V_306 -> V_36 = V_7 -> V_36 ;
V_306 -> V_120 = V_7 -> V_120 ;
V_306 -> V_39 = V_7 -> V_39 ;
V_306 -> V_67 = V_7 -> V_67 ;
V_306 -> V_56 = V_7 -> V_56 ;
V_306 -> V_14 = V_7 -> V_14 ;
V_306 -> V_181 = 1 ;
V_7 -> V_19 [ 1 ] . V_11 = V_11 ;
V_306 -> V_45 = V_7 -> V_45 ;
V_306 -> V_131 = V_7 -> V_131 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_311 ; V_15 ++ ) {
V_306 -> V_312 [ V_15 ] = V_7 -> V_312 [ V_15 ] ;
V_306 -> V_311 = V_7 -> V_311 ;
}
V_11 -> V_313 |= V_314 ;
V_11 -> V_315 = & V_316 ;
F_176 ( V_11 , & V_317 ) ;
F_177 ( V_11 , & V_306 -> V_60 , F_43 , V_318 ) ;
F_178 ( V_11 , & V_150 -> V_22 ) ;
V_50 = F_179 ( V_11 ) ;
if ( V_50 ) {
F_156 ( L_55 ) ;
F_180 ( V_11 ) ;
V_50 = - V_319 ;
}
return V_50 ;
}
static int F_181 ( struct V_288 * V_150 )
{
struct V_287 * V_16 ;
struct V_10 * V_11 ;
struct V_6 * V_7 ;
struct V_320 V_321 ;
struct V_322 V_323 ;
void T_3 * V_324 ;
struct V_325 * V_326 , * V_327 ;
T_1 V_328 , V_329 , V_330 ;
int V_50 = 0 , V_15 , V_331 = 0 ;
V_11 = F_170 ( sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
F_156 ( L_56 ) ;
return - V_175 ;
}
F_182 ( V_150 , V_11 ) ;
V_7 = F_7 ( V_11 ) ;
F_171 ( & V_7 -> V_307 ) ;
V_7 -> V_150 = V_150 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_22 = & V_11 -> V_22 ;
V_7 -> V_263 = F_172 ( V_308 , V_309 ) ;
V_7 -> V_51 = F_173 ( V_51 , 128 ) ;
V_7 -> V_45 = F_157 ( & V_150 -> V_22 , sizeof( struct V_45 ) , V_176 ) ;
V_7 -> V_59 = true ;
if ( ! V_7 -> V_45 ) {
F_156 ( L_57 ) ;
goto V_332;
}
F_183 ( & V_150 -> V_22 ) ;
F_184 ( & V_150 -> V_22 ) ;
if ( F_154 ( & V_7 -> V_16 , V_150 ) ) {
F_156 ( L_58 ) ;
V_50 = - V_319 ;
goto V_333;
}
V_16 = & V_7 -> V_16 ;
if ( F_131 ( V_16 -> V_285 [ 0 ] . V_74 ) ) {
memcpy ( V_7 -> V_74 , V_16 -> V_285 [ 0 ] . V_74 , V_253 ) ;
F_174 ( L_59 , V_7 -> V_74 ) ;
} else {
F_185 ( V_7 -> V_74 ) ;
F_174 ( L_60 , V_7 -> V_74 ) ;
}
memcpy ( V_11 -> V_254 , V_7 -> V_74 , V_253 ) ;
V_7 -> V_19 = F_157 ( & V_150 -> V_22 ,
sizeof( struct V_1 ) * V_16 -> V_19 ,
V_176 ) ;
if ( ! V_7 -> V_19 ) {
V_50 = - V_175 ;
goto V_333;
}
for ( V_15 = 0 ; V_15 < V_16 -> V_19 ; V_15 ++ )
V_7 -> V_19 [ V_15 ] . V_8 = V_15 ;
V_7 -> V_19 [ 0 ] . V_11 = V_11 ;
V_7 -> V_181 = 0 ;
V_7 -> V_310 = F_186 ( & V_150 -> V_22 , L_61 ) ;
if ( F_83 ( V_7 -> V_310 ) ) {
F_8 ( V_7 -> V_22 , L_62 ) ;
V_50 = - V_319 ;
goto V_333;
}
V_7 -> V_91 = 0 ;
V_7 -> V_98 = F_187 ( V_7 -> V_310 ) / 1000000 ;
V_327 = F_188 ( V_150 , V_334 , 0 ) ;
V_324 = F_189 ( & V_150 -> V_22 , V_327 ) ;
if ( F_83 ( V_324 ) ) {
V_50 = F_190 ( V_324 ) ;
goto V_333;
}
V_7 -> V_4 = V_324 ;
V_7 -> V_9 = V_335 ;
F_94 ( & V_150 -> V_22 ) ;
V_7 -> V_131 = F_65 ( & V_7 -> V_4 -> V_336 ) ;
F_106 ( & V_150 -> V_22 ) ;
V_326 = F_188 ( V_150 , V_334 , 1 ) ;
V_7 -> V_36 = F_189 ( & V_150 -> V_22 , V_326 ) ;
if ( F_83 ( V_7 -> V_36 ) ) {
V_50 = F_190 ( V_7 -> V_36 ) ;
goto V_333;
}
memset ( & V_321 , 0 , sizeof( V_321 ) ) ;
memset ( & V_323 , 0 , sizeof( V_323 ) ) ;
switch ( V_7 -> V_131 ) {
case V_132 :
V_7 -> V_155 = V_324 + V_337 ;
V_7 -> V_45 -> V_73 = V_324 + V_338 ;
V_7 -> V_120 = V_324 + V_339 ;
V_321 . V_340 = V_324 + V_341 ;
V_321 . V_342 = V_324 + V_343 ;
V_323 . V_344 = V_324 + V_345 ;
V_328 = V_346 ;
V_330 = V_347 ;
V_329 = V_348 ;
V_321 . V_349 = 0 ;
break;
case V_142 :
case V_143 :
case V_144 :
V_7 -> V_155 = V_324 + V_350 ;
V_7 -> V_45 -> V_73 = V_324 + V_351 ;
V_7 -> V_120 = V_324 + V_352 ;
V_321 . V_340 = V_324 + V_353 ;
V_321 . V_342 = V_324 + V_354 ;
V_323 . V_344 = V_324 + V_355 ;
V_328 = V_356 ;
V_330 = V_357 ;
V_329 = V_358 ;
V_321 . V_349 =
( T_1 V_359 ) V_327 -> V_360 + V_361 ;
break;
default:
F_8 ( V_7 -> V_22 , L_63 , V_7 -> V_131 ) ;
V_50 = - V_319 ;
goto V_333;
}
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ ) {
struct V_1 * V_2 = & V_7 -> V_19 [ V_15 ] ;
F_153 ( V_2 , V_7 , V_328 , V_329 ) ;
V_328 += V_330 ;
V_329 += V_362 ;
}
V_321 . V_22 = & V_150 -> V_22 ;
V_321 . V_363 = V_321 . V_340 + V_364 ;
V_321 . V_365 = V_321 . V_340 + V_366 ;
V_321 . V_367 = V_321 . V_342 + V_368 ;
V_321 . V_369 = V_321 . V_342 + V_370 ;
V_321 . V_371 = V_321 . V_342 + V_372 ;
V_321 . V_373 = V_16 -> V_294 ;
V_321 . V_374 = true ;
V_321 . V_375 = V_184 ;
V_321 . V_376 = V_16 -> V_296 ;
V_321 . V_377 = 16 ;
V_321 . V_378 = true ;
V_321 . V_379 = V_321 . V_349 ;
V_7 -> V_39 = F_191 ( & V_321 ) ;
if ( ! V_7 -> V_39 ) {
F_8 ( V_7 -> V_22 , L_64 ) ;
V_50 = - V_175 ;
goto V_333;
}
V_7 -> V_67 = F_192 ( V_7 -> V_39 , F_193 ( 0 ) ,
F_22 ) ;
V_7 -> V_56 = F_192 ( V_7 -> V_39 , F_194 ( 0 ) ,
F_28 ) ;
if ( F_37 ( ! V_7 -> V_67 || ! V_7 -> V_56 ) ) {
F_8 ( V_7 -> V_22 , L_65 ) ;
V_50 = - V_175 ;
goto V_380;
}
V_323 . V_22 = & V_11 -> V_22 ;
V_323 . V_381 = V_381 ;
V_323 . V_295 = V_16 -> V_295 ;
V_323 . V_382 = V_16 -> V_19 ;
V_7 -> V_14 = F_195 ( & V_323 ) ;
if ( ! V_7 -> V_14 ) {
F_8 ( V_7 -> V_22 , L_66 ) ;
V_50 = - V_319 ;
goto V_380;
}
V_11 -> V_57 = F_196 ( V_150 , 0 ) ;
if ( V_11 -> V_57 < 0 ) {
F_8 ( V_7 -> V_22 , L_67 ) ;
V_50 = - V_383 ;
goto V_384;
}
while ( ( V_326 = F_188 ( V_7 -> V_150 , V_385 , V_331 ) ) ) {
for ( V_15 = V_326 -> V_360 ; V_15 <= V_326 -> V_386 ; V_15 ++ ) {
if ( F_197 ( & V_150 -> V_22 , V_15 , F_38 , 0 ,
F_198 ( & V_150 -> V_22 ) , V_7 ) ) {
F_8 ( V_7 -> V_22 , L_68 ) ;
goto V_384;
}
V_7 -> V_312 [ V_331 ] = V_15 ;
V_7 -> V_311 = V_331 + 1 ;
}
V_331 ++ ;
}
V_11 -> V_313 |= V_314 ;
V_11 -> V_315 = & V_316 ;
F_176 ( V_11 , & V_317 ) ;
F_177 ( V_11 , & V_7 -> V_60 , F_43 , V_318 ) ;
F_178 ( V_11 , & V_150 -> V_22 ) ;
V_50 = F_179 ( V_11 ) ;
if ( V_50 ) {
F_8 ( V_7 -> V_22 , L_69 ) ;
V_50 = - V_319 ;
goto V_384;
}
F_67 ( V_7 , V_387 , L_70 ,
& V_327 -> V_360 , V_11 -> V_57 ) ;
if ( V_7 -> V_16 . V_17 ) {
V_50 = F_169 ( V_150 , V_7 ) ;
if ( V_50 ) {
F_113 ( V_7 , V_387 , L_71 ) ;
goto V_384;
}
}
return 0 ;
V_384:
F_199 ( V_7 -> V_14 ) ;
V_380:
F_200 ( V_7 -> V_67 ) ;
F_200 ( V_7 -> V_56 ) ;
F_201 ( V_7 -> V_39 ) ;
V_333:
F_202 ( & V_150 -> V_22 ) ;
V_332:
F_180 ( V_7 -> V_11 ) ;
return V_50 ;
}
static int F_203 ( struct V_288 * V_150 )
{
struct V_10 * V_11 = F_204 ( V_150 ) ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_7 -> V_16 . V_17 )
F_205 ( F_75 ( V_7 , 1 ) ) ;
F_205 ( V_11 ) ;
F_199 ( V_7 -> V_14 ) ;
F_200 ( V_7 -> V_67 ) ;
F_200 ( V_7 -> V_56 ) ;
F_201 ( V_7 -> V_39 ) ;
F_202 ( & V_150 -> V_22 ) ;
if ( V_7 -> V_16 . V_17 )
F_180 ( F_75 ( V_7 , 1 ) ) ;
F_180 ( V_11 ) ;
return 0 ;
}
static int F_206 ( struct V_388 * V_22 )
{
struct V_288 * V_150 = F_207 ( V_22 ) ;
struct V_10 * V_11 = F_204 ( V_150 ) ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( F_40 ( V_11 ) )
F_107 ( V_11 ) ;
F_59 ( V_7 , F_80 ) ;
F_106 ( & V_150 -> V_22 ) ;
F_208 ( & V_150 -> V_22 ) ;
return 0 ;
}
static int F_209 ( struct V_388 * V_22 )
{
struct V_288 * V_150 = F_207 ( V_22 ) ;
struct V_10 * V_11 = F_204 ( V_150 ) ;
F_94 ( & V_150 -> V_22 ) ;
F_184 ( & V_150 -> V_22 ) ;
if ( F_40 ( V_11 ) )
F_93 ( V_11 ) ;
return 0 ;
}
static int T_9 F_210 ( void )
{
return F_211 ( & V_389 ) ;
}
static void T_10 F_212 ( void )
{
F_213 ( & V_389 ) ;
}
