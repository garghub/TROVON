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
V_11 -> V_46 . V_47 ++ ;
V_11 -> V_46 . V_48 += V_41 ;
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
if ( F_23 ( V_42 < 0 ) || F_23 ( ! F_30 ( V_11 ) ) ) {
F_27 ( V_44 ) ;
return;
}
V_49 = F_31 ( V_11 , V_7 -> V_51 ) ;
if ( V_49 ) {
F_32 ( V_44 , V_41 ) ;
F_33 ( V_7 -> V_45 , V_44 ) ;
V_44 -> V_52 = F_34 ( V_44 , V_11 ) ;
F_35 ( V_44 ) ;
V_11 -> V_46 . V_53 += V_41 ;
V_11 -> V_46 . V_54 ++ ;
} else {
V_11 -> V_46 . V_55 ++ ;
V_49 = V_44 ;
}
V_50 = F_36 ( V_7 -> V_56 , V_49 , V_49 -> V_16 ,
F_37 ( V_49 ) , 0 ) ;
if ( F_38 ( V_50 < 0 ) )
F_27 ( V_49 ) ;
}
static T_2 F_39 ( int V_57 , void * V_58 )
{
struct V_6 * V_7 = V_58 ;
F_21 ( V_7 ) ;
if ( V_7 -> V_59 == true ) {
F_40 ( V_7 ) ;
V_7 -> V_59 = false ;
}
if ( F_30 ( V_7 -> V_11 ) ) {
F_41 ( & V_7 -> V_60 ) ;
return V_61 ;
}
V_7 = F_42 ( V_7 , 1 ) ;
if ( ! V_7 )
return V_62 ;
if ( F_30 ( V_7 -> V_11 ) ) {
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
if ( F_30 ( V_11 ) )
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
return F_36 ( V_7 -> V_67 , V_44 , V_44 -> V_16 ,
V_44 -> V_41 , 0 ) ;
if ( V_11 == F_75 ( V_7 , 0 ) )
return F_36 ( V_7 -> V_67 , V_44 , V_44 -> V_16 ,
V_44 -> V_41 , 1 ) ;
else
return F_36 ( V_7 -> V_67 , V_44 , V_44 -> V_16 ,
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
else
F_77 ( V_7 -> V_14 , V_7 -> V_16 . V_153 ,
V_30 << V_7 -> V_9 ,
V_30 << V_7 -> V_9 , 0 , 0 ) ;
if ( ! F_73 ( V_7 ) ) {
F_98 ( V_7 -> V_39 , V_170 , 1 ) ;
F_98 ( V_7 -> V_39 , V_171 , 0 ) ;
F_4 ( 0 , & V_7 -> V_4 -> V_172 ) ;
F_4 ( 0x7 , & V_7 -> V_4 -> V_173 ) ;
if ( F_38 ( ! V_7 -> V_16 . V_174 ) )
V_7 -> V_16 . V_174 = 128 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_174 ; V_15 ++ ) {
struct V_43 * V_44 ;
V_50 = - V_175 ;
V_44 = F_99 ( V_7 -> V_11 ,
V_7 -> V_51 , V_176 ) ;
if ( ! V_44 )
goto V_177;
V_50 = F_36 ( V_7 -> V_56 , V_44 , V_44 -> V_16 ,
F_37 ( V_44 ) , 0 ) ;
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
F_103 ( & V_7 -> V_60 ) ;
F_104 ( V_7 -> V_39 ) ;
F_19 ( V_7 ) ;
F_46 ( V_7 -> V_39 , V_70 ) ;
F_46 ( V_7 -> V_39 , V_68 ) ;
V_69 = F_42 ( V_7 , 0 ) ;
if ( V_69 -> V_59 == false ) {
if ( ( V_7 == V_69 ) || ! F_30 ( V_69 -> V_11 ) ) {
V_69 -> V_59 = true ;
F_48 ( V_69 ) ;
}
}
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
V_11 -> V_46 . V_186 ++ ;
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
V_11 -> V_46 . V_186 ++ ;
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
switch ( V_7 -> V_131 ) {
case V_142 :
V_206 &= ~ V_209 ;
if ( V_7 -> V_45 -> V_190 )
V_206 |= V_210 ;
if ( V_7 -> V_45 -> V_197 )
V_206 |= V_211 ;
break;
case V_143 :
default:
V_206 &= ~ V_212 ;
if ( V_7 -> V_45 -> V_190 )
V_206 |= V_213 ;
if ( V_7 -> V_45 -> V_197 )
V_206 |= V_214 ;
break;
}
V_207 = ( 30 << V_215 ) | V_201 ;
F_3 ( V_2 , V_207 , V_216 ) ;
F_3 ( V_2 , V_206 , V_208 ) ;
F_4 ( V_200 , & V_7 -> V_4 -> V_217 ) ;
}
static int F_119 ( struct V_10 * V_22 , struct V_218 * V_219 )
{
struct V_6 * V_7 = F_7 ( V_22 ) ;
struct V_45 * V_45 = V_7 -> V_45 ;
struct V_220 V_221 ;
if ( V_7 -> V_131 != V_132 &&
V_7 -> V_131 != V_142 &&
V_7 -> V_131 != V_143 )
return - V_109 ;
if ( F_120 ( & V_221 , V_219 -> V_222 , sizeof( V_221 ) ) )
return - V_223 ;
if ( V_221 . V_20 )
return - V_96 ;
if ( V_221 . V_224 != V_225 && V_221 . V_224 != V_226 )
return - V_227 ;
switch ( V_221 . V_228 ) {
case V_229 :
V_45 -> V_197 = 0 ;
break;
case V_230 :
case V_231 :
case V_232 :
case V_233 :
return - V_227 ;
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
V_45 -> V_197 = 1 ;
V_221 . V_228 = V_240 ;
break;
default:
return - V_227 ;
}
V_45 -> V_190 = V_221 . V_224 == V_226 ;
switch ( V_7 -> V_131 ) {
case V_132 :
F_117 ( V_7 ) ;
break;
case V_142 :
case V_143 :
F_118 ( V_7 ) ;
break;
default:
F_38 ( 1 ) ;
}
return F_121 ( V_219 -> V_222 , & V_221 , sizeof( V_221 ) ) ? - V_223 : 0 ;
}
static int F_122 ( struct V_10 * V_22 , struct V_218 * V_219 )
{
struct V_6 * V_7 = F_7 ( V_22 ) ;
struct V_45 * V_45 = V_7 -> V_45 ;
struct V_220 V_221 ;
if ( V_7 -> V_131 != V_132 &&
V_7 -> V_131 != V_142 &&
V_7 -> V_131 != V_143 )
return - V_109 ;
V_221 . V_20 = 0 ;
V_221 . V_224 = V_45 -> V_190 ? V_226 : V_225 ;
V_221 . V_228 = ( V_45 -> V_197 ?
V_240 : V_229 ) ;
return F_121 ( V_219 -> V_222 , & V_221 , sizeof( V_221 ) ) ? - V_223 : 0 ;
}
static int F_123 ( struct V_10 * V_22 , struct V_218 * V_243 , int V_244 )
{
struct V_6 * V_7 = F_7 ( V_22 ) ;
int V_245 = F_124 ( V_7 ) ;
if ( ! F_30 ( V_22 ) )
return - V_96 ;
switch ( V_244 ) {
#ifdef F_125
case V_246 :
return F_119 ( V_22 , V_243 ) ;
case V_247 :
return F_122 ( V_22 , V_243 ) ;
#endif
}
if ( ! V_7 -> V_19 [ V_245 ] . V_79 )
return - V_109 ;
return F_126 ( V_7 -> V_19 [ V_245 ] . V_79 , V_243 , V_244 ) ;
}
static void F_127 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_113 ( V_7 , V_185 , L_19 ) ;
V_11 -> V_46 . V_248 ++ ;
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
static void F_133 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_21 ( V_7 ) ;
F_20 ( V_7 -> V_39 , false ) ;
F_39 ( V_11 -> V_57 , V_7 ) ;
F_20 ( V_7 -> V_39 , true ) ;
F_19 ( V_7 ) ;
F_46 ( V_7 -> V_39 , V_70 ) ;
F_46 ( V_7 -> V_39 , V_68 ) ;
}
static inline int F_134 ( struct V_6 * V_7 ,
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
goto V_255;
V_50 = F_78 ( V_7 -> V_14 , V_7 -> V_11 -> V_136 ,
V_30 << V_7 -> V_9 ,
V_137 , V_250 , 0 ) ;
if ( V_50 != 0 )
goto V_256;
return 0 ;
V_256:
F_132 ( V_7 -> V_14 , V_7 -> V_74 ,
V_7 -> V_9 , V_137 , V_250 ) ;
V_255:
F_135 ( V_7 -> V_14 , V_250 , 0 ) ;
return V_50 ;
}
static int F_136 ( struct V_10 * V_11 ,
T_7 V_257 , T_6 V_250 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_250 == V_7 -> V_16 . V_153 )
return 0 ;
F_84 ( V_7 -> V_22 , L_20 , V_250 ) ;
return F_134 ( V_7 , V_250 ) ;
}
static int F_137 ( struct V_10 * V_11 ,
T_7 V_257 , T_6 V_250 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_50 ;
if ( V_250 == V_7 -> V_16 . V_153 )
return 0 ;
F_84 ( V_7 -> V_22 , L_21 , V_250 ) ;
V_50 = F_135 ( V_7 -> V_14 , V_250 , 0 ) ;
if ( V_50 != 0 )
return V_50 ;
V_50 = F_132 ( V_7 -> V_14 , V_7 -> V_74 ,
V_7 -> V_9 , V_137 , V_250 ) ;
if ( V_50 != 0 )
return V_50 ;
return F_138 ( V_7 -> V_14 , V_7 -> V_11 -> V_136 ,
0 , V_137 , V_250 ) ;
}
static void F_139 ( struct V_10 * V_11 ,
struct V_258 * V_259 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_140 ( V_259 -> V_260 , L_22 , sizeof( V_259 -> V_260 ) ) ;
F_140 ( V_259 -> V_131 , L_23 , sizeof( V_259 -> V_131 ) ) ;
F_140 ( V_259 -> V_261 , V_7 -> V_150 -> V_126 , sizeof( V_259 -> V_261 ) ) ;
}
static T_1 F_141 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
return V_7 -> V_262 ;
}
static void F_142 ( struct V_10 * V_11 , T_1 V_263 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_7 -> V_262 = V_263 ;
}
static int F_143 ( struct V_10 * V_11 ,
struct V_264 * V_259 )
{
#ifdef F_125
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_259 -> V_265 =
V_266 |
V_267 |
V_268 |
V_269 |
V_270 |
V_271 ;
V_259 -> V_272 = V_7 -> V_45 -> V_272 ;
V_259 -> V_273 =
( 1 << V_225 ) |
( 1 << V_226 ) ;
V_259 -> V_274 =
( 1 << V_229 ) |
( 1 << V_240 ) ;
#else
V_259 -> V_265 =
V_267 |
V_269 |
V_270 ;
V_259 -> V_272 = - 1 ;
V_259 -> V_273 = 0 ;
V_259 -> V_274 = 0 ;
#endif
return 0 ;
}
static int F_144 ( struct V_10 * V_11 ,
struct V_275 * V_276 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_245 = F_124 ( V_7 ) ;
if ( V_7 -> V_19 [ V_245 ] . V_79 )
return F_145 ( V_7 -> V_19 [ V_245 ] . V_79 , V_276 ) ;
else
return - V_109 ;
}
static int F_146 ( struct V_10 * V_11 , struct V_275 * V_276 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_245 = F_124 ( V_7 ) ;
if ( V_7 -> V_19 [ V_245 ] . V_79 )
return F_147 ( V_7 -> V_19 [ V_245 ] . V_79 , V_276 ) ;
else
return - V_109 ;
}
static void F_148 ( struct V_10 * V_11 , struct V_277 * V_278 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_245 = F_124 ( V_7 ) ;
V_278 -> V_279 = 0 ;
V_278 -> V_280 = 0 ;
if ( V_7 -> V_19 [ V_245 ] . V_79 )
F_149 ( V_7 -> V_19 [ V_245 ] . V_79 , V_278 ) ;
}
static int F_150 ( struct V_10 * V_11 , struct V_277 * V_278 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_245 = F_124 ( V_7 ) ;
if ( V_7 -> V_19 [ V_245 ] . V_79 )
return F_151 ( V_7 -> V_19 [ V_245 ] . V_79 , V_278 ) ;
else
return - V_109 ;
}
static void F_152 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_281 , T_1 V_282 )
{
void T_3 * V_4 = V_7 -> V_4 ;
int V_8 = V_2 -> V_8 ;
struct V_283 * V_16 = V_7 -> V_16 . V_284 + V_8 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_4 = V_4 + V_281 ;
V_2 -> V_87 = V_4 + V_282 ;
V_2 -> V_133 = V_16 -> V_285 ;
}
static int F_153 ( struct V_286 * V_16 ,
struct V_287 * V_150 )
{
struct V_288 * V_289 = V_150 -> V_22 . V_290 ;
struct V_288 * V_291 ;
int V_15 = 0 , V_50 ;
T_1 V_292 ;
if ( ! V_289 )
return - V_96 ;
if ( F_154 ( V_289 , L_24 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_25 ) ;
return - V_96 ;
}
V_16 -> V_19 = V_292 ;
if ( F_154 ( V_289 , L_26 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_27 ) ;
return - V_96 ;
}
V_16 -> V_194 = V_292 ;
if ( F_154 ( V_289 , L_28 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_29 ) ;
return - V_96 ;
}
V_16 -> V_179 = V_292 ;
if ( F_154 ( V_289 , L_30 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_31 ) ;
return - V_96 ;
}
V_16 -> V_180 = V_292 ;
V_16 -> V_284 = F_155 ( & V_150 -> V_22 , V_16 -> V_19
* sizeof( struct V_283 ) ,
V_176 ) ;
if ( ! V_16 -> V_284 )
return - V_175 ;
if ( F_154 ( V_289 , L_32 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_33 ) ;
return - V_96 ;
}
V_16 -> V_293 = V_292 ;
if ( F_154 ( V_289 , L_34 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_35 ) ;
return - V_96 ;
}
V_16 -> V_294 = V_292 ;
if ( F_154 ( V_289 , L_36 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_37 ) ;
return - V_96 ;
}
V_16 -> V_295 = V_292 ;
if ( F_154 ( V_289 , L_38 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_39 ) ;
return - V_96 ;
}
V_16 -> V_174 = V_292 ;
if ( F_154 ( V_289 , L_40 , & V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_41 ) ;
return - V_96 ;
}
V_16 -> V_80 = V_292 ;
if ( F_156 ( V_289 , L_42 ) )
V_16 -> V_17 = 1 ;
V_50 = F_157 ( V_289 , NULL , NULL , & V_150 -> V_22 ) ;
if ( V_50 )
F_158 ( & V_150 -> V_22 , L_43 ) ;
F_159 (node, slave_node) {
struct V_283 * V_284 = V_16 -> V_284 + V_15 ;
const void * V_74 = NULL ;
T_1 V_296 ;
int V_297 ;
const T_8 * V_298 ;
struct V_288 * V_299 ;
struct V_287 * V_300 ;
if ( strcmp ( V_291 -> V_126 , L_44 ) )
continue;
V_298 = F_160 ( V_291 , L_45 , & V_297 ) ;
if ( ( V_298 == NULL ) || ( V_297 != ( sizeof( void * ) * 2 ) ) ) {
F_8 ( & V_150 -> V_22 , L_46 , V_15 ) ;
return - V_96 ;
}
V_299 = F_161 ( F_162 ( V_298 ) ) ;
V_296 = F_162 ( V_298 + 1 ) ;
V_300 = F_163 ( V_299 ) ;
F_164 ( V_299 ) ;
if ( ! V_300 ) {
F_165 ( L_47 ) ;
return - V_96 ;
}
snprintf ( V_284 -> V_148 , sizeof( V_284 -> V_148 ) ,
V_301 , V_300 -> V_126 , V_296 ) ;
V_74 = F_166 ( V_291 ) ;
if ( V_74 )
memcpy ( V_284 -> V_74 , V_74 , V_253 ) ;
V_284 -> V_149 = F_167 ( V_291 ) ;
if ( V_284 -> V_149 < 0 ) {
F_8 ( & V_150 -> V_22 , L_48 ,
V_15 ) ;
return V_284 -> V_149 ;
}
if ( V_16 -> V_17 ) {
if ( F_154 ( V_291 , L_49 ,
& V_292 ) ) {
F_8 ( & V_150 -> V_22 , L_50 ) ;
V_284 -> V_285 = V_15 + 1 ;
F_8 ( & V_150 -> V_22 , L_51 ,
V_284 -> V_285 , V_15 ) ;
} else {
V_284 -> V_285 = V_292 ;
}
}
V_15 ++ ;
if ( V_15 == V_16 -> V_19 )
break;
}
return 0 ;
}
static int F_168 ( struct V_287 * V_150 ,
struct V_6 * V_7 )
{
struct V_286 * V_16 = & V_7 -> V_16 ;
struct V_10 * V_11 ;
struct V_6 * V_302 ;
int V_50 = 0 , V_15 ;
V_11 = F_169 ( sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
F_8 ( & V_150 -> V_22 , L_52 ) ;
return - V_175 ;
}
V_302 = F_7 ( V_11 ) ;
F_170 ( & V_302 -> V_303 ) ;
V_302 -> V_16 = * V_16 ;
V_302 -> V_150 = V_150 ;
V_302 -> V_11 = V_11 ;
V_302 -> V_22 = & V_11 -> V_22 ;
V_302 -> V_262 = F_171 ( V_304 , V_305 ) ;
V_302 -> V_51 = F_172 ( V_51 , 128 ) ;
if ( F_131 ( V_16 -> V_284 [ 1 ] . V_74 ) ) {
memcpy ( V_302 -> V_74 , V_16 -> V_284 [ 1 ] . V_74 ,
V_253 ) ;
F_84 ( & V_150 -> V_22 , L_53 , V_302 -> V_74 ) ;
} else {
F_173 ( V_302 -> V_74 ) ;
F_84 ( & V_150 -> V_22 , L_54 , V_302 -> V_74 ) ;
}
memcpy ( V_11 -> V_254 , V_302 -> V_74 , V_253 ) ;
V_302 -> V_19 = V_7 -> V_19 ;
V_302 -> V_306 = V_7 -> V_306 ;
V_302 -> V_91 = 0 ;
V_302 -> V_98 = V_7 -> V_98 ;
V_302 -> V_4 = V_7 -> V_4 ;
V_302 -> V_9 = V_7 -> V_9 ;
V_302 -> V_155 = V_7 -> V_155 ;
V_302 -> V_36 = V_7 -> V_36 ;
V_302 -> V_120 = V_7 -> V_120 ;
V_302 -> V_39 = V_7 -> V_39 ;
V_302 -> V_67 = V_7 -> V_67 ;
V_302 -> V_56 = V_7 -> V_56 ;
V_302 -> V_14 = V_7 -> V_14 ;
V_302 -> V_181 = 1 ;
V_7 -> V_19 [ 1 ] . V_11 = V_11 ;
V_302 -> V_45 = V_7 -> V_45 ;
V_302 -> V_131 = V_7 -> V_131 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_307 ; V_15 ++ ) {
V_302 -> V_308 [ V_15 ] = V_7 -> V_308 [ V_15 ] ;
V_302 -> V_307 = V_7 -> V_307 ;
}
V_11 -> V_309 |= V_310 ;
V_11 -> V_311 = & V_312 ;
V_11 -> V_313 = & V_314 ;
F_174 ( V_11 , & V_302 -> V_60 , F_43 , V_315 ) ;
F_175 ( V_11 , & V_150 -> V_22 ) ;
V_50 = F_176 ( V_11 ) ;
if ( V_50 ) {
F_8 ( & V_150 -> V_22 , L_55 ) ;
F_177 ( V_11 ) ;
V_50 = - V_316 ;
}
return V_50 ;
}
static int F_178 ( struct V_287 * V_150 )
{
struct V_286 * V_16 ;
struct V_10 * V_11 ;
struct V_6 * V_7 ;
struct V_317 V_318 ;
struct V_319 V_320 ;
void T_3 * V_321 ;
struct V_322 * V_323 , * V_324 ;
T_1 V_325 , V_326 , V_327 ;
int V_50 = 0 , V_15 , V_328 = 0 ;
V_11 = F_169 ( sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
F_8 ( & V_150 -> V_22 , L_56 ) ;
return - V_175 ;
}
F_179 ( V_150 , V_11 ) ;
V_7 = F_7 ( V_11 ) ;
F_170 ( & V_7 -> V_303 ) ;
V_7 -> V_150 = V_150 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_22 = & V_11 -> V_22 ;
V_7 -> V_262 = F_171 ( V_304 , V_305 ) ;
V_7 -> V_51 = F_172 ( V_51 , 128 ) ;
V_7 -> V_45 = F_155 ( & V_150 -> V_22 , sizeof( struct V_45 ) , V_176 ) ;
V_7 -> V_59 = true ;
if ( ! V_7 -> V_45 ) {
F_8 ( & V_150 -> V_22 , L_57 ) ;
goto V_329;
}
F_180 ( & V_150 -> V_22 ) ;
F_181 ( & V_150 -> V_22 ) ;
if ( F_153 ( & V_7 -> V_16 , V_150 ) ) {
F_8 ( & V_150 -> V_22 , L_58 ) ;
V_50 = - V_316 ;
goto V_330;
}
V_16 = & V_7 -> V_16 ;
if ( F_131 ( V_16 -> V_284 [ 0 ] . V_74 ) ) {
memcpy ( V_7 -> V_74 , V_16 -> V_284 [ 0 ] . V_74 , V_253 ) ;
F_84 ( & V_150 -> V_22 , L_59 , V_7 -> V_74 ) ;
} else {
F_182 ( V_7 -> V_74 ) ;
F_84 ( & V_150 -> V_22 , L_60 , V_7 -> V_74 ) ;
}
memcpy ( V_11 -> V_254 , V_7 -> V_74 , V_253 ) ;
V_7 -> V_19 = F_155 ( & V_150 -> V_22 ,
sizeof( struct V_1 ) * V_16 -> V_19 ,
V_176 ) ;
if ( ! V_7 -> V_19 ) {
V_50 = - V_175 ;
goto V_330;
}
for ( V_15 = 0 ; V_15 < V_16 -> V_19 ; V_15 ++ )
V_7 -> V_19 [ V_15 ] . V_8 = V_15 ;
V_7 -> V_19 [ 0 ] . V_11 = V_11 ;
V_7 -> V_181 = 0 ;
V_7 -> V_306 = F_183 ( & V_150 -> V_22 , L_61 ) ;
if ( F_83 ( V_7 -> V_306 ) ) {
F_8 ( V_7 -> V_22 , L_62 ) ;
V_50 = - V_316 ;
goto V_330;
}
V_7 -> V_91 = 0 ;
V_7 -> V_98 = F_184 ( V_7 -> V_306 ) / 1000000 ;
V_324 = F_185 ( V_150 , V_331 , 0 ) ;
V_321 = F_186 ( & V_150 -> V_22 , V_324 ) ;
if ( F_83 ( V_321 ) ) {
V_50 = F_187 ( V_321 ) ;
goto V_330;
}
V_7 -> V_4 = V_321 ;
V_7 -> V_9 = V_332 ;
F_94 ( & V_150 -> V_22 ) ;
V_7 -> V_131 = F_65 ( & V_7 -> V_4 -> V_333 ) ;
F_106 ( & V_150 -> V_22 ) ;
V_323 = F_185 ( V_150 , V_331 , 1 ) ;
V_7 -> V_36 = F_186 ( & V_150 -> V_22 , V_323 ) ;
if ( F_83 ( V_7 -> V_36 ) ) {
V_50 = F_187 ( V_7 -> V_36 ) ;
goto V_330;
}
memset ( & V_318 , 0 , sizeof( V_318 ) ) ;
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
switch ( V_7 -> V_131 ) {
case V_132 :
V_7 -> V_155 = V_321 + V_334 ;
V_7 -> V_45 -> V_73 = V_321 + V_335 ;
V_7 -> V_120 = V_321 + V_336 ;
V_318 . V_337 = V_321 + V_338 ;
V_318 . V_339 = V_321 + V_340 ;
V_320 . V_341 = V_321 + V_342 ;
V_325 = V_343 ;
V_327 = V_344 ;
V_326 = V_345 ;
V_318 . V_346 = 0 ;
break;
case V_142 :
case V_143 :
case V_144 :
V_7 -> V_155 = V_321 + V_347 ;
V_7 -> V_45 -> V_73 = V_321 + V_348 ;
V_7 -> V_120 = V_321 + V_349 ;
V_318 . V_337 = V_321 + V_350 ;
V_318 . V_339 = V_321 + V_351 ;
V_320 . V_341 = V_321 + V_352 ;
V_325 = V_353 ;
V_327 = V_354 ;
V_326 = V_355 ;
V_318 . V_346 =
( T_1 V_356 ) V_324 -> V_357 + V_358 ;
break;
default:
F_8 ( V_7 -> V_22 , L_63 , V_7 -> V_131 ) ;
V_50 = - V_316 ;
goto V_330;
}
for ( V_15 = 0 ; V_15 < V_7 -> V_16 . V_19 ; V_15 ++ ) {
struct V_1 * V_2 = & V_7 -> V_19 [ V_15 ] ;
F_152 ( V_2 , V_7 , V_325 , V_326 ) ;
V_325 += V_327 ;
V_326 += V_359 ;
}
V_318 . V_22 = & V_150 -> V_22 ;
V_318 . V_360 = V_318 . V_337 + V_361 ;
V_318 . V_362 = V_318 . V_337 + V_363 ;
V_318 . V_364 = V_318 . V_339 + V_365 ;
V_318 . V_366 = V_318 . V_339 + V_367 ;
V_318 . V_368 = V_318 . V_339 + V_369 ;
V_318 . V_370 = V_16 -> V_293 ;
V_318 . V_371 = true ;
V_318 . V_372 = V_184 ;
V_318 . V_373 = V_16 -> V_295 ;
V_318 . V_374 = 16 ;
V_318 . V_375 = true ;
V_318 . V_376 = V_318 . V_346 ;
V_7 -> V_39 = F_188 ( & V_318 ) ;
if ( ! V_7 -> V_39 ) {
F_8 ( V_7 -> V_22 , L_64 ) ;
V_50 = - V_175 ;
goto V_330;
}
V_7 -> V_67 = F_189 ( V_7 -> V_39 , F_190 ( 0 ) ,
F_22 ) ;
V_7 -> V_56 = F_189 ( V_7 -> V_39 , F_191 ( 0 ) ,
F_28 ) ;
if ( F_38 ( ! V_7 -> V_67 || ! V_7 -> V_56 ) ) {
F_8 ( V_7 -> V_22 , L_65 ) ;
V_50 = - V_175 ;
goto V_377;
}
V_320 . V_22 = & V_11 -> V_22 ;
V_320 . V_378 = V_378 ;
V_320 . V_294 = V_16 -> V_294 ;
V_320 . V_379 = V_16 -> V_19 ;
V_7 -> V_14 = F_192 ( & V_320 ) ;
if ( ! V_7 -> V_14 ) {
F_8 ( V_7 -> V_22 , L_66 ) ;
V_50 = - V_316 ;
goto V_377;
}
V_11 -> V_57 = F_193 ( V_150 , 0 ) ;
if ( V_11 -> V_57 < 0 ) {
F_8 ( V_7 -> V_22 , L_67 ) ;
V_50 = - V_380 ;
goto V_381;
}
while ( ( V_323 = F_185 ( V_7 -> V_150 , V_382 , V_328 ) ) ) {
for ( V_15 = V_323 -> V_357 ; V_15 <= V_323 -> V_383 ; V_15 ++ ) {
if ( F_194 ( & V_150 -> V_22 , V_15 , F_39 , 0 ,
F_195 ( & V_150 -> V_22 ) , V_7 ) ) {
F_8 ( V_7 -> V_22 , L_68 ) ;
goto V_381;
}
V_7 -> V_308 [ V_328 ] = V_15 ;
V_7 -> V_307 = V_328 + 1 ;
}
V_328 ++ ;
}
V_11 -> V_309 |= V_310 ;
V_11 -> V_311 = & V_312 ;
V_11 -> V_313 = & V_314 ;
F_174 ( V_11 , & V_7 -> V_60 , F_43 , V_315 ) ;
F_175 ( V_11 , & V_150 -> V_22 ) ;
V_50 = F_176 ( V_11 ) ;
if ( V_50 ) {
F_8 ( V_7 -> V_22 , L_69 ) ;
V_50 = - V_316 ;
goto V_381;
}
F_67 ( V_7 , V_384 , L_70 ,
& V_324 -> V_357 , V_11 -> V_57 ) ;
if ( V_7 -> V_16 . V_17 ) {
V_50 = F_168 ( V_150 , V_7 ) ;
if ( V_50 ) {
F_113 ( V_7 , V_384 , L_71 ) ;
goto V_381;
}
}
return 0 ;
V_381:
F_196 ( V_7 -> V_14 ) ;
V_377:
F_197 ( V_7 -> V_67 ) ;
F_197 ( V_7 -> V_56 ) ;
F_198 ( V_7 -> V_39 ) ;
V_330:
F_199 ( & V_150 -> V_22 ) ;
V_329:
F_177 ( V_7 -> V_11 ) ;
return V_50 ;
}
static int F_200 ( struct V_287 * V_150 )
{
struct V_10 * V_11 = F_201 ( V_150 ) ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_7 -> V_16 . V_17 )
F_202 ( F_75 ( V_7 , 1 ) ) ;
F_202 ( V_11 ) ;
F_196 ( V_7 -> V_14 ) ;
F_197 ( V_7 -> V_67 ) ;
F_197 ( V_7 -> V_56 ) ;
F_198 ( V_7 -> V_39 ) ;
F_199 ( & V_150 -> V_22 ) ;
if ( V_7 -> V_16 . V_17 )
F_177 ( F_75 ( V_7 , 1 ) ) ;
F_177 ( V_11 ) ;
return 0 ;
}
static int F_203 ( struct V_385 * V_22 )
{
struct V_287 * V_150 = F_204 ( V_22 ) ;
struct V_10 * V_11 = F_201 ( V_150 ) ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( F_30 ( V_11 ) )
F_107 ( V_11 ) ;
F_59 ( V_7 , F_80 ) ;
F_106 ( & V_150 -> V_22 ) ;
F_205 ( & V_150 -> V_22 ) ;
return 0 ;
}
static int F_206 ( struct V_385 * V_22 )
{
struct V_287 * V_150 = F_204 ( V_22 ) ;
struct V_10 * V_11 = F_201 ( V_150 ) ;
F_94 ( & V_150 -> V_22 ) ;
F_181 ( & V_150 -> V_22 ) ;
if ( F_30 ( V_11 ) )
F_93 ( V_11 ) ;
return 0 ;
}
static int T_9 F_207 ( void )
{
return F_208 ( & V_386 ) ;
}
static void T_10 F_209 ( void )
{
F_210 ( & V_386 ) ;
}
