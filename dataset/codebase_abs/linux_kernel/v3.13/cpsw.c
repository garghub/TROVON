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
static void F_6 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_11 -> V_12 & V_13 ) {
F_8 ( V_7 -> V_14 , L_1 ) ;
return;
}
F_9 ( V_7 -> V_15 , V_16 << V_7 -> V_9 ) ;
if ( ! F_10 ( V_11 ) ) {
struct V_17 * V_18 ;
F_11 (ha, ndev) {
F_12 ( V_7 , ( V_19 * ) V_18 -> V_20 ) ;
}
}
}
static void F_13 ( struct V_6 * V_7 )
{
F_4 ( 0xFF , & V_7 -> V_21 -> V_22 ) ;
F_4 ( 0xFF , & V_7 -> V_21 -> V_23 ) ;
F_14 ( V_7 -> V_24 , true ) ;
return;
}
static void F_15 ( struct V_6 * V_7 )
{
F_4 ( 0 , & V_7 -> V_21 -> V_22 ) ;
F_4 ( 0 , & V_7 -> V_21 -> V_23 ) ;
F_14 ( V_7 -> V_24 , false ) ;
return;
}
void F_16 ( void * V_25 , int V_26 , int V_27 )
{
struct V_28 * V_29 = V_25 ;
struct V_10 * V_11 = V_29 -> V_14 ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( F_17 ( F_18 ( V_11 ) ) )
F_19 ( V_11 ) ;
F_20 ( V_7 -> V_30 , V_29 ) ;
V_7 -> V_31 . V_32 ++ ;
V_7 -> V_31 . V_33 += V_26 ;
F_21 ( V_29 ) ;
}
void F_22 ( void * V_25 , int V_26 , int V_27 )
{
struct V_28 * V_29 = V_25 ;
struct V_28 * V_34 ;
struct V_10 * V_11 = V_29 -> V_14 ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_35 = 0 ;
F_23 ( V_27 , V_7 , V_11 , V_29 ) ;
if ( F_17 ( V_27 < 0 ) ) {
F_21 ( V_29 ) ;
return;
}
V_34 = F_24 ( V_11 , V_7 -> V_36 ) ;
if ( V_34 ) {
F_25 ( V_29 , V_26 ) ;
F_26 ( V_7 -> V_30 , V_29 ) ;
V_29 -> V_37 = F_27 ( V_29 , V_11 ) ;
F_28 ( V_29 ) ;
V_7 -> V_31 . V_38 += V_26 ;
V_7 -> V_31 . V_39 ++ ;
} else {
V_7 -> V_31 . V_40 ++ ;
V_34 = V_29 ;
}
V_35 = F_29 ( V_7 -> V_41 , V_34 , V_34 -> V_42 ,
F_30 ( V_34 ) , 0 ) ;
if ( F_31 ( V_35 < 0 ) )
F_21 ( V_34 ) ;
}
static T_2 F_32 ( int V_43 , void * V_44 )
{
struct V_6 * V_7 = V_44 ;
F_15 ( V_7 ) ;
if ( V_7 -> V_45 == true ) {
F_33 ( V_7 ) ;
V_7 -> V_45 = false ;
}
if ( F_34 ( V_7 -> V_11 ) ) {
F_35 ( & V_7 -> V_46 ) ;
return V_47 ;
}
V_7 = F_36 ( V_7 , 1 ) ;
if ( ! V_7 )
return V_48 ;
if ( F_34 ( V_7 -> V_11 ) ) {
F_35 ( & V_7 -> V_46 ) ;
return V_47 ;
}
return V_48 ;
}
static int F_37 ( struct V_49 * V_46 , int V_50 )
{
struct V_6 * V_7 = F_38 ( V_46 ) ;
int V_51 , V_52 ;
V_51 = F_39 ( V_7 -> V_53 , 128 ) ;
if ( V_51 )
F_40 ( V_7 -> V_24 , V_54 ) ;
V_52 = F_39 ( V_7 -> V_41 , V_50 ) ;
if ( V_52 < V_50 ) {
struct V_6 * V_55 ;
F_41 ( V_46 ) ;
F_13 ( V_7 ) ;
F_40 ( V_7 -> V_24 , V_56 ) ;
V_55 = F_36 ( V_7 , 0 ) ;
if ( V_55 -> V_45 == false ) {
V_55 -> V_45 = true ;
F_42 ( V_7 ) ;
}
}
if ( V_52 || V_51 )
F_43 ( V_7 , V_57 , L_2 ,
V_52 , V_51 ) ;
return V_52 ;
}
static inline void F_44 ( const char * V_58 , void T_3 * V_59 )
{
unsigned long V_60 = V_61 + V_62 ;
F_4 ( 1 , V_59 ) ;
do {
F_45 () ;
} while ( ( F_2 ( V_59 ) & 1 ) && F_46 ( V_60 , V_61 ) );
F_47 ( F_2 ( V_59 ) & 1 , L_3 , V_58 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
F_3 ( V_2 , F_49 ( V_7 -> V_63 ) , V_64 ) ;
F_3 ( V_2 , F_50 ( V_7 -> V_63 ) , V_65 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_6 * V_7 , bool * V_66 )
{
struct V_67 * V_68 = V_2 -> V_68 ;
T_1 V_69 = 0 ;
T_1 V_70 ;
if ( ! V_68 )
return;
V_70 = F_5 ( V_7 , V_2 -> V_8 ) ;
if ( V_68 -> V_66 ) {
V_69 = V_7 -> V_42 . V_69 ;
F_52 ( V_7 -> V_15 , V_70 ,
V_71 , V_72 ) ;
if ( V_68 -> V_73 == 1000 )
V_69 |= F_53 ( 7 ) ;
if ( V_68 -> V_74 )
V_69 |= F_53 ( 0 ) ;
if ( V_68 -> V_73 == 100 )
V_69 |= F_53 ( 15 ) ;
else if ( V_68 -> V_73 == 10 )
V_69 |= F_53 ( 18 ) ;
* V_66 = true ;
} else {
V_69 = 0 ;
F_52 ( V_7 -> V_15 , V_70 ,
V_71 , V_75 ) ;
}
if ( V_69 != V_2 -> V_69 ) {
F_54 ( V_68 ) ;
F_4 ( V_69 , & V_2 -> V_76 -> V_69 ) ;
}
V_2 -> V_69 = V_69 ;
}
static void F_55 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
bool V_66 = false ;
F_56 ( V_7 , F_51 , V_7 , & V_66 ) ;
if ( V_66 ) {
F_57 ( V_11 ) ;
if ( F_34 ( V_11 ) )
F_19 ( V_11 ) ;
} else {
F_58 ( V_11 ) ;
F_59 ( V_11 ) ;
}
}
static int F_60 ( struct V_10 * V_11 ,
struct V_77 * V_78 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_78 -> V_79 = V_7 -> V_80 ;
return 0 ;
}
static int F_61 ( struct V_10 * V_11 ,
struct V_77 * V_78 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
T_1 V_81 ;
T_1 V_82 = 0 ;
T_1 V_83 = 0 ;
T_1 V_84 = 1 ;
T_1 V_80 = 0 ;
if ( ! V_78 -> V_79 )
return - V_85 ;
V_80 = V_78 -> V_79 ;
V_81 = F_62 ( & V_7 -> V_21 -> V_86 ) ;
V_83 = V_7 -> V_87 * 4 ;
if ( V_80 < V_88 )
V_80 = V_88 ;
if ( V_80 > V_89 ) {
V_84 = V_90 / V_83 ;
if ( V_84 > 1 ) {
V_83 *= V_84 ;
if ( V_80 > ( V_89 * V_84 ) )
V_80 = ( V_89
* V_84 ) ;
} else {
V_84 = 1 ;
V_80 = V_89 ;
}
}
V_82 = ( 1000 * V_84 ) / V_80 ;
F_63 ( V_82 , & V_7 -> V_21 -> V_91 ) ;
F_63 ( V_82 , & V_7 -> V_21 -> V_92 ) ;
V_81 |= V_93 ;
V_81 &= ( ~ V_90 ) ;
V_81 |= ( V_83 & V_90 ) ;
F_63 ( V_81 , & V_7 -> V_21 -> V_86 ) ;
F_64 ( V_7 , V_94 , L_4 , V_80 ) ;
if ( V_7 -> V_42 . V_95 ) {
int V_96 ;
for ( V_96 = 0 ; V_96 < V_7 -> V_42 . V_97 ; V_96 ++ ) {
V_7 = F_7 ( V_7 -> V_97 [ V_96 ] . V_11 ) ;
V_7 -> V_80 = V_80 ;
}
} else {
V_7 -> V_80 = V_80 ;
}
return 0 ;
}
static int F_65 ( struct V_10 * V_11 , int V_98 )
{
switch ( V_98 ) {
case V_99 :
return V_100 ;
default:
return - V_101 ;
}
}
static void F_66 ( struct V_10 * V_11 , T_1 V_102 , V_19 * V_42 )
{
V_19 * V_103 = V_42 ;
int V_96 ;
switch ( V_102 ) {
case V_99 :
for ( V_96 = 0 ; V_96 < V_100 ; V_96 ++ ) {
memcpy ( V_103 , V_104 [ V_96 ] . V_105 ,
V_106 ) ;
V_103 += V_106 ;
}
break;
}
}
static void F_67 ( struct V_10 * V_11 ,
struct V_107 * V_31 , T_4 * V_42 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
struct V_108 V_109 ;
struct V_108 V_110 ;
T_1 V_5 ;
V_19 * V_103 ;
int V_96 ;
F_68 ( V_7 -> V_41 , & V_109 ) ;
F_68 ( V_7 -> V_53 , & V_110 ) ;
for ( V_96 = 0 ; V_96 < V_100 ; V_96 ++ ) {
switch ( V_104 [ V_96 ] . type ) {
case V_111 :
V_5 = F_62 ( V_7 -> V_112 +
V_104 [ V_96 ] . V_113 ) ;
V_42 [ V_96 ] = V_5 ;
break;
case V_114 :
V_103 = ( V_19 * ) & V_109 +
V_104 [ V_96 ] . V_113 ;
V_42 [ V_96 ] = * ( T_1 * ) V_103 ;
break;
case V_115 :
V_103 = ( V_19 * ) & V_110 +
V_104 [ V_96 ] . V_113 ;
V_42 [ V_96 ] = * ( T_1 * ) V_103 ;
break;
}
}
}
static inline int F_69 ( char * V_116 , int V_117 , const char * V_118 , T_1 V_5 )
{
static char * V_119 = L_5 ;
if ( ! V_5 )
return 0 ;
else
return snprintf ( V_116 , V_117 , L_6 , V_118 ,
V_119 + strlen ( V_118 ) , V_5 ) ;
}
static int F_70 ( struct V_6 * V_7 )
{
T_1 V_96 ;
T_1 V_120 = 0 ;
if ( ! V_7 -> V_42 . V_95 )
return 0 ;
for ( V_96 = 0 ; V_96 < V_7 -> V_42 . V_97 ; V_96 ++ )
if ( V_7 -> V_97 [ V_96 ] . V_121 )
V_120 ++ ;
return V_120 ;
}
static inline int F_71 ( struct V_10 * V_11 ,
struct V_6 * V_7 , struct V_28 * V_29 )
{
if ( ! V_7 -> V_42 . V_95 )
return F_29 ( V_7 -> V_53 , V_29 , V_29 -> V_42 ,
V_29 -> V_26 , 0 ) ;
if ( V_11 == F_72 ( V_7 , 0 ) )
return F_29 ( V_7 -> V_53 , V_29 , V_29 -> V_42 ,
V_29 -> V_26 , 1 ) ;
else
return F_29 ( V_7 -> V_53 , V_29 , V_29 -> V_42 ,
V_29 -> V_26 , 2 ) ;
}
static inline void F_73 (
struct V_6 * V_7 , struct V_1 * V_2 ,
T_1 V_70 )
{
T_1 V_122 = 1 << V_70 | 1 << V_7 -> V_9 ;
if ( V_7 -> V_123 == V_124 )
F_3 ( V_2 , V_2 -> V_125 , V_126 ) ;
else
F_3 ( V_2 , V_2 -> V_125 , V_127 ) ;
F_74 ( V_7 -> V_15 , V_2 -> V_125 , V_122 ,
V_122 , V_122 , 0 ) ;
F_75 ( V_7 -> V_15 , V_7 -> V_11 -> V_128 ,
V_122 , V_129 , V_2 -> V_125 , 0 ) ;
F_76 ( V_7 -> V_15 , V_7 -> V_63 ,
V_7 -> V_9 , V_129 , V_2 -> V_125 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
char V_118 [ 32 ] ;
snprintf ( V_118 , sizeof( V_118 ) , L_7 , V_2 -> V_8 ) ;
F_44 ( V_118 , & V_2 -> V_76 -> F_44 ) ;
}
static void F_78 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
T_1 V_70 ;
F_77 ( V_2 ) ;
F_4 ( V_130 , & V_2 -> V_76 -> V_131 ) ;
switch ( V_7 -> V_123 ) {
case V_124 :
F_3 ( V_2 , V_132 , V_133 ) ;
break;
case V_134 :
case V_135 :
case V_136 :
F_3 ( V_2 , V_132 , V_137 ) ;
break;
}
F_4 ( V_7 -> V_36 , & V_2 -> V_76 -> V_138 ) ;
F_48 ( V_2 , V_7 ) ;
V_2 -> V_69 = 0 ;
V_70 = F_5 ( V_7 , V_2 -> V_8 ) ;
if ( V_7 -> V_42 . V_95 )
F_73 ( V_7 , V_2 , V_70 ) ;
else
F_75 ( V_7 -> V_15 , V_7 -> V_11 -> V_128 ,
1 << V_70 , 0 , 0 , V_139 ) ;
V_2 -> V_68 = F_79 ( V_7 -> V_11 , V_2 -> V_42 -> V_140 ,
& F_55 , V_2 -> V_42 -> V_141 ) ;
if ( F_80 ( V_2 -> V_68 ) ) {
F_8 ( V_7 -> V_14 , L_8 ,
V_2 -> V_42 -> V_140 , V_2 -> V_8 ) ;
V_2 -> V_68 = NULL ;
} else {
F_81 ( V_7 -> V_14 , L_9 ,
V_2 -> V_68 -> V_140 ) ;
F_82 ( V_2 -> V_68 ) ;
F_83 ( & V_7 -> V_142 -> V_14 , V_2 -> V_68 -> V_143 ,
V_2 -> V_8 ) ;
}
}
static inline void F_84 ( struct V_6 * V_7 )
{
const int V_144 = V_7 -> V_42 . V_145 ;
const int V_146 = V_7 -> V_9 ;
T_1 V_59 ;
int V_96 ;
V_59 = ( V_7 -> V_123 == V_124 ) ? V_126 :
V_127 ;
F_63 ( V_144 , & V_7 -> V_147 -> V_125 ) ;
for ( V_96 = 0 ; V_96 < V_7 -> V_42 . V_97 ; V_96 ++ )
F_3 ( V_7 -> V_97 + V_96 , V_144 , V_59 ) ;
F_74 ( V_7 -> V_15 , V_144 , V_16 << V_146 ,
V_16 << V_146 , V_16 << V_146 ,
( V_148 | V_149 ) << V_146 ) ;
}
static void F_85 ( struct V_6 * V_7 )
{
T_1 V_150 ;
T_1 V_151 ;
F_44 ( L_10 , & V_7 -> V_4 -> F_44 ) ;
F_86 ( V_7 -> V_15 ) ;
F_52 ( V_7 -> V_15 , V_7 -> V_9 , V_152 ,
V_153 ) ;
V_150 = F_62 ( & V_7 -> V_4 -> V_154 ) ;
V_150 |= V_155 ;
F_63 ( V_150 , & V_7 -> V_4 -> V_154 ) ;
V_151 = ( V_7 -> V_42 . V_95 ) ? V_156 :
V_157 ;
F_63 ( V_151 , & V_7 -> V_147 -> V_158 ) ;
F_4 ( V_159 ,
& V_7 -> V_147 -> V_160 ) ;
F_4 ( 0 , & V_7 -> V_147 -> V_161 ) ;
F_52 ( V_7 -> V_15 , V_7 -> V_9 ,
V_71 , V_72 ) ;
if ( ! V_7 -> V_42 . V_95 ) {
F_76 ( V_7 -> V_15 , V_7 -> V_63 , V_7 -> V_9 ,
0 , 0 ) ;
F_75 ( V_7 -> V_15 , V_7 -> V_11 -> V_128 ,
1 << V_7 -> V_9 , 0 , 0 , V_139 ) ;
}
}
static void F_87 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( ! V_2 -> V_68 )
return;
F_88 ( V_2 -> V_68 ) ;
F_89 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
}
static int F_90 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
struct V_6 * V_55 ;
int V_96 , V_35 ;
T_1 V_59 ;
if ( ! F_70 ( V_7 ) )
F_15 ( V_7 ) ;
F_58 ( V_11 ) ;
F_91 ( & V_7 -> V_142 -> V_14 ) ;
V_59 = V_7 -> V_123 ;
F_81 ( V_7 -> V_14 , L_11 ,
F_92 ( V_59 ) , F_93 ( V_59 ) ,
F_94 ( V_59 ) ) ;
if ( ! F_70 ( V_7 ) )
F_85 ( V_7 ) ;
F_56 ( V_7 , F_78 , V_7 ) ;
if ( ! V_7 -> V_42 . V_95 )
F_84 ( V_7 ) ;
if ( ! F_70 ( V_7 ) ) {
F_95 ( V_7 -> V_24 , V_162 , 1 ) ;
F_95 ( V_7 -> V_24 , V_163 , 0 ) ;
F_4 ( 0 , & V_7 -> V_4 -> V_164 ) ;
F_4 ( 0x7 , & V_7 -> V_4 -> V_165 ) ;
if ( F_31 ( ! V_7 -> V_42 . V_166 ) )
V_7 -> V_42 . V_166 = 128 ;
for ( V_96 = 0 ; V_96 < V_7 -> V_42 . V_166 ; V_96 ++ ) {
struct V_28 * V_29 ;
V_35 = - V_167 ;
V_29 = F_96 ( V_7 -> V_11 ,
V_7 -> V_36 , V_168 ) ;
if ( ! V_29 )
goto V_169;
V_35 = F_29 ( V_7 -> V_41 , V_29 , V_29 -> V_42 ,
F_30 ( V_29 ) , 0 ) ;
if ( V_35 < 0 ) {
F_97 ( V_29 ) ;
goto V_169;
}
}
F_98 ( V_7 , V_170 , L_12 , V_96 ) ;
if ( F_99 ( & V_7 -> V_142 -> V_14 , V_7 -> V_30 ,
V_7 -> V_42 . V_171 ,
V_7 -> V_42 . V_172 ) )
F_8 ( V_7 -> V_14 , L_13 ) ;
}
if ( V_7 -> V_80 != 0 ) {
struct V_77 V_78 ;
V_78 . V_79 = ( V_7 -> V_80 << 4 ) ;
F_61 ( V_11 , & V_78 ) ;
}
V_55 = F_36 ( V_7 , 0 ) ;
if ( V_55 -> V_45 == false ) {
if ( ( V_7 == V_55 ) || ! F_34 ( V_55 -> V_11 ) ) {
V_55 -> V_45 = true ;
F_42 ( V_55 ) ;
}
}
F_100 ( & V_7 -> V_46 ) ;
F_101 ( V_7 -> V_24 ) ;
F_13 ( V_7 ) ;
F_40 ( V_7 -> V_24 , V_56 ) ;
F_40 ( V_7 -> V_24 , V_54 ) ;
if ( V_7 -> V_42 . V_95 )
V_7 -> V_97 [ V_7 -> V_173 ] . V_121 = true ;
return 0 ;
V_169:
F_102 ( V_7 -> V_24 ) ;
F_56 ( V_7 , F_87 , V_7 ) ;
F_103 ( & V_7 -> V_142 -> V_14 ) ;
F_58 ( V_7 -> V_11 ) ;
return V_35 ;
}
static int F_104 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_98 ( V_7 , V_174 , L_14 ) ;
F_59 ( V_7 -> V_11 ) ;
F_105 ( & V_7 -> V_46 ) ;
F_58 ( V_7 -> V_11 ) ;
if ( F_70 ( V_7 ) <= 1 ) {
F_106 ( V_7 -> V_30 ) ;
F_15 ( V_7 ) ;
F_14 ( V_7 -> V_24 , false ) ;
F_102 ( V_7 -> V_24 ) ;
F_107 ( V_7 -> V_15 ) ;
}
F_56 ( V_7 , F_87 , V_7 ) ;
F_103 ( & V_7 -> V_142 -> V_14 ) ;
if ( V_7 -> V_42 . V_95 )
V_7 -> V_97 [ V_7 -> V_173 ] . V_121 = false ;
return 0 ;
}
static T_5 F_108 ( struct V_28 * V_29 ,
struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_35 ;
V_11 -> V_175 = V_61 ;
if ( F_109 ( V_29 , V_176 ) ) {
F_110 ( V_7 , V_177 , L_15 ) ;
V_7 -> V_31 . V_178 ++ ;
return V_179 ;
}
if ( F_111 ( V_29 ) -> V_180 & V_181 &&
V_7 -> V_30 -> V_182 )
F_111 ( V_29 ) -> V_180 |= V_183 ;
F_112 ( V_29 ) ;
V_35 = F_71 ( V_11 , V_7 , V_29 ) ;
if ( F_17 ( V_35 != 0 ) ) {
F_110 ( V_7 , V_177 , L_16 ) ;
goto V_184;
}
if ( F_17 ( ! F_113 ( V_7 -> V_53 ) ) )
F_59 ( V_11 ) ;
return V_179 ;
V_184:
V_7 -> V_31 . V_178 ++ ;
F_59 ( V_11 ) ;
return V_185 ;
}
static void F_114 ( struct V_10 * V_11 , int V_12 )
{
if ( ( V_12 & V_13 ) && ( V_11 -> V_12 & V_13 ) )
F_8 ( & V_11 -> V_14 , L_17 ) ;
if ( ( V_12 & V_186 ) && ! ( V_11 -> V_12 & V_186 ) )
F_8 ( & V_11 -> V_14 , L_18 ) ;
}
static void F_115 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_97 [ V_7 -> V_42 . V_187 ] ;
T_1 V_188 , V_189 ;
if ( ! V_7 -> V_30 -> V_182 && ! V_7 -> V_30 -> V_190 ) {
F_3 ( V_2 , 0 , V_191 ) ;
return;
}
V_189 = ( 30 << V_192 ) | V_193 ;
V_188 = V_194 << V_195 ;
if ( V_7 -> V_30 -> V_182 )
V_188 |= V_196 ;
if ( V_7 -> V_30 -> V_190 )
V_188 |= V_197 ;
F_3 ( V_2 , V_188 , V_191 ) ;
F_3 ( V_2 , V_189 , V_198 ) ;
}
static void F_116 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
T_1 V_199 , V_200 ;
if ( V_7 -> V_42 . V_95 )
V_2 = & V_7 -> V_97 [ V_7 -> V_173 ] ;
else
V_2 = & V_7 -> V_97 [ V_7 -> V_42 . V_187 ] ;
V_199 = F_1 ( V_2 , V_201 ) ;
V_199 &= ~ V_202 ;
if ( V_7 -> V_30 -> V_182 )
V_199 |= V_203 ;
if ( V_7 -> V_30 -> V_190 )
V_199 |= V_204 ;
V_200 = ( 30 << V_205 ) | V_194 ;
F_3 ( V_2 , V_200 , V_206 ) ;
F_3 ( V_2 , V_199 , V_201 ) ;
F_4 ( V_193 , & V_7 -> V_4 -> V_207 ) ;
}
static int F_117 ( struct V_10 * V_14 , struct V_208 * V_209 )
{
struct V_6 * V_7 = F_7 ( V_14 ) ;
struct V_30 * V_30 = V_7 -> V_30 ;
struct V_210 V_211 ;
if ( V_7 -> V_123 != V_124 &&
V_7 -> V_123 != V_134 )
return - V_101 ;
if ( F_118 ( & V_211 , V_209 -> V_212 , sizeof( V_211 ) ) )
return - V_213 ;
if ( V_211 . V_12 )
return - V_85 ;
if ( V_211 . V_214 != V_215 && V_211 . V_214 != V_216 )
return - V_217 ;
switch ( V_211 . V_218 ) {
case V_219 :
V_30 -> V_190 = 0 ;
break;
case V_220 :
case V_221 :
case V_222 :
case V_223 :
return - V_217 ;
case V_224 :
case V_225 :
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
V_30 -> V_190 = 1 ;
V_211 . V_218 = V_230 ;
break;
default:
return - V_217 ;
}
V_30 -> V_182 = V_211 . V_214 == V_216 ;
switch ( V_7 -> V_123 ) {
case V_124 :
F_115 ( V_7 ) ;
break;
case V_134 :
F_116 ( V_7 ) ;
break;
default:
F_31 ( 1 ) ;
}
return F_119 ( V_209 -> V_212 , & V_211 , sizeof( V_211 ) ) ? - V_213 : 0 ;
}
static int F_120 ( struct V_10 * V_14 , struct V_208 * V_233 , int V_234 )
{
struct V_6 * V_7 = F_7 ( V_14 ) ;
struct V_235 * V_42 = F_121 ( V_233 ) ;
int V_236 = F_122 ( V_7 ) ;
if ( ! F_34 ( V_14 ) )
return - V_85 ;
switch ( V_234 ) {
#ifdef F_123
case V_237 :
return F_117 ( V_14 , V_233 ) ;
#endif
case V_238 :
V_42 -> V_140 = V_7 -> V_97 [ V_236 ] . V_68 -> V_20 ;
break;
default:
return - V_239 ;
}
return 0 ;
}
static void F_124 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_110 ( V_7 , V_177 , L_19 ) ;
V_7 -> V_31 . V_240 ++ ;
F_15 ( V_7 ) ;
F_14 ( V_7 -> V_24 , false ) ;
F_125 ( V_7 -> V_53 ) ;
F_126 ( V_7 -> V_53 ) ;
F_14 ( V_7 -> V_24 , true ) ;
F_13 ( V_7 ) ;
F_40 ( V_7 -> V_24 , V_56 ) ;
F_40 ( V_7 -> V_24 , V_54 ) ;
}
static int F_127 ( struct V_10 * V_11 , void * V_103 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
struct V_241 * V_20 = (struct V_241 * ) V_103 ;
int V_12 = 0 ;
T_6 V_242 = 0 ;
if ( ! F_128 ( V_20 -> V_243 ) )
return - V_244 ;
if ( V_7 -> V_42 . V_95 ) {
V_242 = V_7 -> V_97 [ V_7 -> V_173 ] . V_125 ;
V_12 = V_129 ;
}
F_129 ( V_7 -> V_15 , V_7 -> V_63 , V_7 -> V_9 ,
V_12 , V_242 ) ;
F_76 ( V_7 -> V_15 , V_20 -> V_243 , V_7 -> V_9 ,
V_12 , V_242 ) ;
memcpy ( V_7 -> V_63 , V_20 -> V_243 , V_245 ) ;
memcpy ( V_11 -> V_246 , V_7 -> V_63 , V_245 ) ;
F_56 ( V_7 , F_48 , V_7 ) ;
return 0 ;
}
static struct V_247 * F_130 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
return & V_7 -> V_31 ;
}
static void F_131 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_15 ( V_7 ) ;
F_14 ( V_7 -> V_24 , false ) ;
F_32 ( V_11 -> V_43 , V_7 ) ;
F_14 ( V_7 -> V_24 , true ) ;
F_13 ( V_7 ) ;
F_40 ( V_7 -> V_24 , V_56 ) ;
F_40 ( V_7 -> V_24 , V_54 ) ;
}
static inline int F_132 ( struct V_6 * V_7 ,
unsigned short V_242 )
{
int V_35 ;
V_35 = F_74 ( V_7 -> V_15 , V_242 ,
V_16 << V_7 -> V_9 ,
0 , V_16 << V_7 -> V_9 ,
( V_148 | V_149 ) << V_7 -> V_9 ) ;
if ( V_35 != 0 )
return V_35 ;
V_35 = F_76 ( V_7 -> V_15 , V_7 -> V_63 ,
V_7 -> V_9 , V_129 , V_242 ) ;
if ( V_35 != 0 )
goto V_248;
V_35 = F_75 ( V_7 -> V_15 , V_7 -> V_11 -> V_128 ,
V_16 << V_7 -> V_9 ,
V_129 , V_242 , 0 ) ;
if ( V_35 != 0 )
goto V_249;
return 0 ;
V_249:
F_129 ( V_7 -> V_15 , V_7 -> V_63 ,
V_7 -> V_9 , V_129 , V_242 ) ;
V_248:
F_133 ( V_7 -> V_15 , V_242 , 0 ) ;
return V_35 ;
}
static int F_134 ( struct V_10 * V_11 ,
T_7 V_250 , T_6 V_242 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_242 == V_7 -> V_42 . V_145 )
return 0 ;
F_81 ( V_7 -> V_14 , L_20 , V_242 ) ;
return F_132 ( V_7 , V_242 ) ;
}
static int F_135 ( struct V_10 * V_11 ,
T_7 V_250 , T_6 V_242 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_35 ;
if ( V_242 == V_7 -> V_42 . V_145 )
return 0 ;
F_81 ( V_7 -> V_14 , L_21 , V_242 ) ;
V_35 = F_133 ( V_7 -> V_15 , V_242 , 0 ) ;
if ( V_35 != 0 )
return V_35 ;
V_35 = F_129 ( V_7 -> V_15 , V_7 -> V_63 ,
V_7 -> V_9 , V_129 , V_242 ) ;
if ( V_35 != 0 )
return V_35 ;
return F_136 ( V_7 -> V_15 , V_7 -> V_11 -> V_128 ,
0 , V_129 , V_242 ) ;
}
static void F_137 ( struct V_10 * V_11 ,
struct V_251 * V_252 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
F_138 ( V_252 -> V_253 , L_22 , sizeof( V_252 -> V_253 ) ) ;
F_138 ( V_252 -> V_123 , L_23 , sizeof( V_252 -> V_123 ) ) ;
F_138 ( V_252 -> V_254 , V_7 -> V_142 -> V_118 , sizeof( V_252 -> V_254 ) ) ;
}
static T_1 F_139 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
return V_7 -> V_255 ;
}
static void F_140 ( struct V_10 * V_11 , T_1 V_256 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_7 -> V_255 = V_256 ;
}
static int F_141 ( struct V_10 * V_11 ,
struct V_257 * V_252 )
{
#ifdef F_123
struct V_6 * V_7 = F_7 ( V_11 ) ;
V_252 -> V_258 =
V_259 |
V_260 |
V_261 |
V_262 |
V_263 |
V_264 ;
V_252 -> V_265 = V_7 -> V_30 -> V_265 ;
V_252 -> V_266 =
( 1 << V_215 ) |
( 1 << V_216 ) ;
V_252 -> V_267 =
( 1 << V_219 ) |
( 1 << V_230 ) ;
#else
V_252 -> V_258 =
V_260 |
V_262 |
V_263 ;
V_252 -> V_265 = - 1 ;
V_252 -> V_266 = 0 ;
V_252 -> V_267 = 0 ;
#endif
return 0 ;
}
static int F_142 ( struct V_10 * V_11 ,
struct V_268 * V_269 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_236 = F_122 ( V_7 ) ;
if ( V_7 -> V_97 [ V_236 ] . V_68 )
return F_143 ( V_7 -> V_97 [ V_236 ] . V_68 , V_269 ) ;
else
return - V_101 ;
}
static int F_144 ( struct V_10 * V_11 , struct V_268 * V_269 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_236 = F_122 ( V_7 ) ;
if ( V_7 -> V_97 [ V_236 ] . V_68 )
return F_145 ( V_7 -> V_97 [ V_236 ] . V_68 , V_269 ) ;
else
return - V_101 ;
}
static void F_146 ( struct V_10 * V_11 , struct V_270 * V_271 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_236 = F_122 ( V_7 ) ;
V_271 -> V_272 = 0 ;
V_271 -> V_273 = 0 ;
if ( V_7 -> V_97 [ V_236 ] . V_68 )
F_147 ( V_7 -> V_97 [ V_236 ] . V_68 , V_271 ) ;
}
static int F_148 ( struct V_10 * V_11 , struct V_270 * V_271 )
{
struct V_6 * V_7 = F_7 ( V_11 ) ;
int V_236 = F_122 ( V_7 ) ;
if ( V_7 -> V_97 [ V_236 ] . V_68 )
return F_149 ( V_7 -> V_97 [ V_236 ] . V_68 , V_271 ) ;
else
return - V_101 ;
}
static void F_150 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_274 , T_1 V_275 )
{
void T_3 * V_4 = V_7 -> V_4 ;
int V_8 = V_2 -> V_8 ;
struct V_276 * V_42 = V_7 -> V_42 . V_277 + V_8 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_4 = V_4 + V_274 ;
V_2 -> V_76 = V_4 + V_275 ;
V_2 -> V_125 = V_42 -> V_278 ;
}
static int F_151 ( struct V_279 * V_42 ,
struct V_280 * V_142 )
{
struct V_281 * V_282 = V_142 -> V_14 . V_283 ;
struct V_281 * V_284 ;
int V_96 = 0 , V_35 ;
T_1 V_285 ;
if ( ! V_282 )
return - V_85 ;
if ( F_152 ( V_282 , L_24 , & V_285 ) ) {
F_153 ( L_25 ) ;
return - V_85 ;
}
V_42 -> V_97 = V_285 ;
if ( F_152 ( V_282 , L_26 , & V_285 ) ) {
F_153 ( L_27 ) ;
return - V_85 ;
}
V_42 -> V_187 = V_285 ;
if ( F_152 ( V_282 , L_28 , & V_285 ) ) {
F_153 ( L_29 ) ;
return - V_85 ;
}
V_42 -> V_171 = V_285 ;
if ( F_152 ( V_282 , L_30 , & V_285 ) ) {
F_153 ( L_31 ) ;
return - V_85 ;
}
V_42 -> V_172 = V_285 ;
V_42 -> V_277 = F_154 ( & V_142 -> V_14 , V_42 -> V_97
* sizeof( struct V_276 ) ,
V_168 ) ;
if ( ! V_42 -> V_277 )
return - V_167 ;
if ( F_152 ( V_282 , L_32 , & V_285 ) ) {
F_153 ( L_33 ) ;
return - V_85 ;
}
V_42 -> V_286 = V_285 ;
if ( F_152 ( V_282 , L_34 , & V_285 ) ) {
F_153 ( L_35 ) ;
return - V_85 ;
}
V_42 -> V_287 = V_285 ;
if ( F_152 ( V_282 , L_36 , & V_285 ) ) {
F_153 ( L_37 ) ;
return - V_85 ;
}
V_42 -> V_288 = V_285 ;
if ( F_152 ( V_282 , L_38 , & V_285 ) ) {
F_153 ( L_39 ) ;
return - V_85 ;
}
V_42 -> V_166 = V_285 ;
if ( F_152 ( V_282 , L_40 , & V_285 ) ) {
F_153 ( L_41 ) ;
return - V_85 ;
}
V_42 -> V_69 = V_285 ;
if ( F_155 ( V_282 , L_42 ) )
V_42 -> V_95 = 1 ;
V_35 = F_156 ( V_282 , NULL , NULL , & V_142 -> V_14 ) ;
if ( V_35 )
F_157 ( L_43 ) ;
F_158 (node, slave_node) {
struct V_276 * V_277 = V_42 -> V_277 + V_96 ;
const void * V_63 = NULL ;
T_1 V_289 ;
int V_290 ;
const T_8 * V_291 ;
struct V_281 * V_292 ;
struct V_280 * V_293 ;
if ( strcmp ( V_284 -> V_118 , L_44 ) )
continue;
V_291 = F_159 ( V_284 , L_45 , & V_290 ) ;
if ( ( V_291 == NULL ) || ( V_290 != ( sizeof( void * ) * 2 ) ) ) {
F_153 ( L_46 , V_96 ) ;
return - V_85 ;
}
V_292 = F_160 ( F_161 ( V_291 ) ) ;
V_289 = F_161 ( V_291 + 1 ) ;
V_293 = F_162 ( V_292 ) ;
snprintf ( V_277 -> V_140 , sizeof( V_277 -> V_140 ) ,
V_294 , V_293 -> V_118 , V_289 ) ;
V_63 = F_163 ( V_284 ) ;
if ( V_63 )
memcpy ( V_277 -> V_63 , V_63 , V_245 ) ;
V_277 -> V_141 = F_164 ( V_284 ) ;
if ( V_42 -> V_95 ) {
if ( F_152 ( V_284 , L_47 ,
& V_285 ) ) {
F_153 ( L_48 ) ;
V_277 -> V_278 = V_96 + 1 ;
F_153 ( L_49 ,
V_277 -> V_278 , V_96 ) ;
} else {
V_277 -> V_278 = V_285 ;
}
}
V_96 ++ ;
if ( V_96 == V_42 -> V_97 )
break;
}
return 0 ;
}
static int F_165 ( struct V_280 * V_142 ,
struct V_6 * V_7 )
{
struct V_279 * V_42 = & V_7 -> V_42 ;
struct V_10 * V_11 ;
struct V_6 * V_295 ;
int V_35 = 0 , V_96 ;
V_11 = F_166 ( sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
F_153 ( L_50 ) ;
return - V_167 ;
}
V_295 = F_7 ( V_11 ) ;
F_167 ( & V_295 -> V_296 ) ;
V_295 -> V_42 = * V_42 ;
V_295 -> V_142 = V_142 ;
V_295 -> V_11 = V_11 ;
V_295 -> V_14 = & V_11 -> V_14 ;
V_295 -> V_255 = F_168 ( V_297 , V_298 ) ;
V_295 -> V_36 = F_169 ( V_36 , 128 ) ;
if ( F_128 ( V_42 -> V_277 [ 1 ] . V_63 ) ) {
memcpy ( V_295 -> V_63 , V_42 -> V_277 [ 1 ] . V_63 ,
V_245 ) ;
F_170 ( L_51 , V_295 -> V_63 ) ;
} else {
F_171 ( V_295 -> V_63 ) ;
F_170 ( L_52 , V_295 -> V_63 ) ;
}
memcpy ( V_11 -> V_246 , V_295 -> V_63 , V_245 ) ;
V_295 -> V_97 = V_7 -> V_97 ;
V_295 -> V_299 = V_7 -> V_299 ;
V_295 -> V_80 = 0 ;
V_295 -> V_87 = V_7 -> V_87 ;
V_295 -> V_4 = V_7 -> V_4 ;
V_295 -> V_9 = V_7 -> V_9 ;
V_295 -> V_147 = V_7 -> V_147 ;
V_295 -> V_21 = V_7 -> V_21 ;
V_295 -> V_112 = V_7 -> V_112 ;
V_295 -> V_24 = V_7 -> V_24 ;
V_295 -> V_53 = V_7 -> V_53 ;
V_295 -> V_41 = V_7 -> V_41 ;
V_295 -> V_15 = V_7 -> V_15 ;
V_295 -> V_173 = 1 ;
V_7 -> V_97 [ 1 ] . V_11 = V_11 ;
V_295 -> V_30 = V_7 -> V_30 ;
V_295 -> V_123 = V_7 -> V_123 ;
for ( V_96 = 0 ; V_96 < V_7 -> V_300 ; V_96 ++ ) {
V_295 -> V_301 [ V_96 ] = V_7 -> V_301 [ V_96 ] ;
V_295 -> V_300 = V_7 -> V_300 ;
}
V_11 -> V_302 |= V_303 ;
V_11 -> V_304 = & V_305 ;
F_172 ( V_11 , & V_306 ) ;
F_173 ( V_11 , & V_295 -> V_46 , F_37 , V_307 ) ;
F_174 ( V_11 , & V_142 -> V_14 ) ;
V_35 = F_175 ( V_11 ) ;
if ( V_35 ) {
F_153 ( L_53 ) ;
F_176 ( V_11 ) ;
V_35 = - V_308 ;
}
return V_35 ;
}
static int F_177 ( struct V_280 * V_142 )
{
struct V_279 * V_42 ;
struct V_10 * V_11 ;
struct V_6 * V_7 ;
struct V_309 V_310 ;
struct V_311 V_312 ;
void T_3 * V_313 ;
struct V_314 * V_315 , * V_316 ;
T_1 V_317 , V_318 , V_319 ;
int V_35 = 0 , V_96 , V_320 = 0 ;
V_11 = F_166 ( sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
F_153 ( L_54 ) ;
return - V_167 ;
}
F_178 ( V_142 , V_11 ) ;
V_7 = F_7 ( V_11 ) ;
F_167 ( & V_7 -> V_296 ) ;
V_7 -> V_142 = V_142 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_14 = & V_11 -> V_14 ;
V_7 -> V_255 = F_168 ( V_297 , V_298 ) ;
V_7 -> V_36 = F_169 ( V_36 , 128 ) ;
V_7 -> V_30 = F_154 ( & V_142 -> V_14 , sizeof( struct V_30 ) , V_168 ) ;
V_7 -> V_45 = true ;
if ( ! V_7 -> V_30 ) {
F_153 ( L_55 ) ;
goto V_321;
}
F_179 ( & V_142 -> V_14 ) ;
F_180 ( & V_142 -> V_14 ) ;
if ( F_151 ( & V_7 -> V_42 , V_142 ) ) {
F_153 ( L_56 ) ;
V_35 = - V_308 ;
goto V_322;
}
V_42 = & V_7 -> V_42 ;
if ( F_128 ( V_42 -> V_277 [ 0 ] . V_63 ) ) {
memcpy ( V_7 -> V_63 , V_42 -> V_277 [ 0 ] . V_63 , V_245 ) ;
F_170 ( L_57 , V_7 -> V_63 ) ;
} else {
F_181 ( V_7 -> V_63 ) ;
F_170 ( L_58 , V_7 -> V_63 ) ;
}
memcpy ( V_11 -> V_246 , V_7 -> V_63 , V_245 ) ;
V_7 -> V_97 = F_154 ( & V_142 -> V_14 ,
sizeof( struct V_1 ) * V_42 -> V_97 ,
V_168 ) ;
if ( ! V_7 -> V_97 ) {
V_35 = - V_167 ;
goto V_322;
}
for ( V_96 = 0 ; V_96 < V_42 -> V_97 ; V_96 ++ )
V_7 -> V_97 [ V_96 ] . V_8 = V_96 ;
V_7 -> V_97 [ 0 ] . V_11 = V_11 ;
V_7 -> V_173 = 0 ;
V_7 -> V_299 = F_182 ( & V_142 -> V_14 , L_59 ) ;
if ( F_80 ( V_7 -> V_299 ) ) {
F_8 ( V_7 -> V_14 , L_60 ) ;
V_35 = - V_308 ;
goto V_322;
}
V_7 -> V_80 = 0 ;
V_7 -> V_87 = F_183 ( V_7 -> V_299 ) / 1000000 ;
V_316 = F_184 ( V_142 , V_323 , 0 ) ;
V_313 = F_185 ( & V_142 -> V_14 , V_316 ) ;
if ( F_80 ( V_313 ) ) {
V_35 = F_186 ( V_313 ) ;
goto V_322;
}
V_7 -> V_4 = V_313 ;
V_7 -> V_9 = V_324 ;
F_91 ( & V_142 -> V_14 ) ;
V_7 -> V_123 = F_62 ( & V_7 -> V_4 -> V_325 ) ;
F_103 ( & V_142 -> V_14 ) ;
V_315 = F_184 ( V_142 , V_323 , 1 ) ;
V_7 -> V_21 = F_185 ( & V_142 -> V_14 , V_315 ) ;
if ( F_80 ( V_7 -> V_21 ) ) {
V_35 = F_186 ( V_7 -> V_21 ) ;
goto V_322;
}
memset ( & V_310 , 0 , sizeof( V_310 ) ) ;
memset ( & V_312 , 0 , sizeof( V_312 ) ) ;
switch ( V_7 -> V_123 ) {
case V_124 :
V_7 -> V_147 = V_313 + V_326 ;
V_7 -> V_30 -> V_59 = V_313 + V_327 ;
V_7 -> V_112 = V_313 + V_328 ;
V_310 . V_329 = V_313 + V_330 ;
V_310 . V_331 = V_313 + V_332 ;
V_312 . V_333 = V_313 + V_334 ;
V_317 = V_335 ;
V_319 = V_336 ;
V_318 = V_337 ;
V_310 . V_338 = 0 ;
break;
case V_134 :
case V_135 :
case V_136 :
V_7 -> V_147 = V_313 + V_339 ;
V_7 -> V_30 -> V_59 = V_313 + V_340 ;
V_7 -> V_112 = V_313 + V_341 ;
V_310 . V_329 = V_313 + V_342 ;
V_310 . V_331 = V_313 + V_343 ;
V_312 . V_333 = V_313 + V_344 ;
V_317 = V_345 ;
V_319 = V_346 ;
V_318 = V_347 ;
V_310 . V_338 =
( T_1 V_348 ) V_316 -> V_349 + V_350 ;
break;
default:
F_8 ( V_7 -> V_14 , L_61 , V_7 -> V_123 ) ;
V_35 = - V_308 ;
goto V_322;
}
for ( V_96 = 0 ; V_96 < V_7 -> V_42 . V_97 ; V_96 ++ ) {
struct V_1 * V_2 = & V_7 -> V_97 [ V_96 ] ;
F_150 ( V_2 , V_7 , V_317 , V_318 ) ;
V_317 += V_319 ;
V_318 += V_351 ;
}
V_310 . V_14 = & V_142 -> V_14 ;
V_310 . V_352 = V_310 . V_329 + V_353 ;
V_310 . V_354 = V_310 . V_329 + V_355 ;
V_310 . V_356 = V_310 . V_331 + V_357 ;
V_310 . V_358 = V_310 . V_331 + V_359 ;
V_310 . V_360 = V_310 . V_331 + V_361 ;
V_310 . V_362 = V_42 -> V_286 ;
V_310 . V_363 = true ;
V_310 . V_364 = V_176 ;
V_310 . V_365 = V_42 -> V_288 ;
V_310 . V_366 = 16 ;
V_310 . V_367 = true ;
V_310 . V_368 = V_310 . V_338 ;
V_7 -> V_24 = F_187 ( & V_310 ) ;
if ( ! V_7 -> V_24 ) {
F_8 ( V_7 -> V_14 , L_62 ) ;
V_35 = - V_167 ;
goto V_322;
}
V_7 -> V_53 = F_188 ( V_7 -> V_24 , F_189 ( 0 ) ,
F_16 ) ;
V_7 -> V_41 = F_188 ( V_7 -> V_24 , F_190 ( 0 ) ,
F_22 ) ;
if ( F_31 ( ! V_7 -> V_53 || ! V_7 -> V_41 ) ) {
F_8 ( V_7 -> V_14 , L_63 ) ;
V_35 = - V_167 ;
goto V_369;
}
V_312 . V_14 = & V_11 -> V_14 ;
V_312 . V_370 = V_370 ;
V_312 . V_287 = V_42 -> V_287 ;
V_312 . V_371 = V_42 -> V_97 ;
V_7 -> V_15 = F_191 ( & V_312 ) ;
if ( ! V_7 -> V_15 ) {
F_8 ( V_7 -> V_14 , L_64 ) ;
V_35 = - V_308 ;
goto V_369;
}
V_11 -> V_43 = F_192 ( V_142 , 0 ) ;
if ( V_11 -> V_43 < 0 ) {
F_8 ( V_7 -> V_14 , L_65 ) ;
V_35 = - V_372 ;
goto V_373;
}
while ( ( V_315 = F_184 ( V_7 -> V_142 , V_374 , V_320 ) ) ) {
for ( V_96 = V_315 -> V_349 ; V_96 <= V_315 -> V_375 ; V_96 ++ ) {
if ( F_193 ( & V_142 -> V_14 , V_96 , F_32 , 0 ,
F_194 ( & V_142 -> V_14 ) , V_7 ) ) {
F_8 ( V_7 -> V_14 , L_66 ) ;
goto V_373;
}
V_7 -> V_301 [ V_320 ] = V_96 ;
V_7 -> V_300 = V_320 + 1 ;
}
V_320 ++ ;
}
V_11 -> V_302 |= V_303 ;
V_11 -> V_304 = & V_305 ;
F_172 ( V_11 , & V_306 ) ;
F_173 ( V_11 , & V_7 -> V_46 , F_37 , V_307 ) ;
F_174 ( V_11 , & V_142 -> V_14 ) ;
V_35 = F_175 ( V_11 ) ;
if ( V_35 ) {
F_8 ( V_7 -> V_14 , L_67 ) ;
V_35 = - V_308 ;
goto V_373;
}
if ( F_99 ( & V_142 -> V_14 , V_7 -> V_30 ,
V_42 -> V_171 , V_42 -> V_172 ) )
F_8 ( V_7 -> V_14 , L_13 ) ;
F_64 ( V_7 , V_376 , L_68 ,
V_316 -> V_349 , V_11 -> V_43 ) ;
if ( V_7 -> V_42 . V_95 ) {
V_35 = F_165 ( V_142 , V_7 ) ;
if ( V_35 ) {
F_110 ( V_7 , V_376 , L_69 ) ;
goto V_373;
}
}
return 0 ;
V_373:
F_195 ( V_7 -> V_15 ) ;
V_369:
F_196 ( V_7 -> V_53 ) ;
F_196 ( V_7 -> V_41 ) ;
F_197 ( V_7 -> V_24 ) ;
V_322:
F_198 ( & V_142 -> V_14 ) ;
V_321:
F_176 ( V_7 -> V_11 ) ;
return V_35 ;
}
static int F_199 ( struct V_280 * V_142 )
{
struct V_10 * V_11 = F_200 ( V_142 ) ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( V_7 -> V_42 . V_95 )
F_201 ( F_72 ( V_7 , 1 ) ) ;
F_201 ( V_11 ) ;
F_195 ( V_7 -> V_15 ) ;
F_196 ( V_7 -> V_53 ) ;
F_196 ( V_7 -> V_41 ) ;
F_197 ( V_7 -> V_24 ) ;
F_198 ( & V_142 -> V_14 ) ;
if ( V_7 -> V_42 . V_95 )
F_176 ( F_72 ( V_7 , 1 ) ) ;
F_176 ( V_11 ) ;
return 0 ;
}
static int F_202 ( struct V_377 * V_14 )
{
struct V_280 * V_142 = F_203 ( V_14 ) ;
struct V_10 * V_11 = F_200 ( V_142 ) ;
struct V_6 * V_7 = F_7 ( V_11 ) ;
if ( F_34 ( V_11 ) )
F_104 ( V_11 ) ;
F_56 ( V_7 , F_77 ) ;
F_103 ( & V_142 -> V_14 ) ;
F_204 ( & V_142 -> V_14 ) ;
return 0 ;
}
static int F_205 ( struct V_377 * V_14 )
{
struct V_280 * V_142 = F_203 ( V_14 ) ;
struct V_10 * V_11 = F_200 ( V_142 ) ;
F_91 ( & V_142 -> V_14 ) ;
F_180 ( & V_142 -> V_14 ) ;
if ( F_34 ( V_11 ) )
F_90 ( V_11 ) ;
return 0 ;
}
static int T_9 F_206 ( void )
{
return F_207 ( & V_378 ) ;
}
static void T_10 F_208 ( void )
{
F_209 ( & V_378 ) ;
}
