static void F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
F_2 ( ! V_2 -> V_8 ) ;
F_3 ( V_5 ) ;
F_4 ( & V_5 -> V_9 , V_3 , V_5 ) ;
V_2 -> V_8 = 1 ;
}
static void F_5 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
if ( V_2 -> V_8 ) {
V_2 -> V_8 = 0 ;
F_6 ( & V_5 -> V_9 , L_1 , V_5 ) ;
F_7 ( V_11 , V_5 ) ;
}
}
static void F_8 ( const struct V_10 * V_11 ,
struct V_1 * V_2 , enum V_12 V_13 )
{
struct V_14 * V_15 = F_9 ( V_2 -> V_6 . V_16 ) ;
F_10 ( F_11 ( V_15 ) , V_2 ) ;
}
int F_12 ( const struct V_10 * V_11 ,
const struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_2 = F_13 ( V_18 ) ;
int V_21 ;
F_1 ( V_2 , L_2 ) ;
V_21 = F_14 ( V_11 , V_20 , V_2 ) ;
if ( V_21 != 0 )
F_5 ( V_11 , V_2 ) ;
else
F_8 ( V_11 , V_2 , V_22 ) ;
return V_21 ;
}
void F_15 ( union V_23 * V_24 ,
const struct V_25 * V_15 ,
T_1 V_26 , T_1 V_27 )
{
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_24 -> V_28 . V_26 = F_16 ( V_15 , V_26 ) ;
V_24 -> V_28 . V_27 = F_16 ( V_15 , V_27 + 1 ) - 1 ;
}
static const char * F_17 ( struct V_29 * V_30 )
{
return F_18 ( V_30 ) ? L_3 : L_4 ;
}
static inline unsigned long F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 == 0 )
return 0 ;
return ( F_20 () - V_2 -> V_31 ) ;
}
static int F_21 ( const struct V_10 * V_11 ,
const struct V_17 * V_18 ,
void * V_32 , T_2 V_33 )
{
struct V_1 * V_2 = F_13 ( V_18 ) ;
struct V_34 * V_35 = & V_2 -> V_36 ;
struct V_14 * V_15 = F_9 ( V_18 -> V_16 ) ;
struct V_37 * V_38 = & F_22 ( V_15 ) -> V_39 -> V_40 . V_38 ;
return (* V_33)( V_11 , V_32 , V_41 L_5 ,
V_2 , F_23 ( V_2 ) ,
V_35 -> V_42 , V_35 -> V_43 ,
V_35 -> V_44 ,
F_17 ( & V_35 -> V_45 ) ,
F_17 ( & V_35 -> V_46 ) ,
V_35 -> V_47 , V_35 -> V_48 , V_35 -> V_49 ,
V_35 -> V_50 , V_35 -> V_51 ,
V_35 -> V_52 , V_35 -> V_53 , V_15 ,
V_2 -> V_8 ,
F_19 ( V_2 ) , V_2 -> V_54 ,
V_38 -> V_55 , V_38 -> V_56 ,
V_38 -> V_57 ,
V_38 -> V_58 ,
F_17 ( & V_38 -> V_59 ) ,
F_17 ( & V_38 -> V_60 ) ,
F_17 ( & V_38 -> V_61 ) ,
F_17 ( & V_38 -> V_62 ) ,
F_17 ( & V_38 -> V_63 ) ,
F_17 ( & V_15 -> V_64 ) ,
F_17 ( & V_15 -> V_65 ) ,
F_17 ( & V_15 -> V_66 ) ,
F_17 ( & V_15 -> V_67 ) ,
F_24 ( & V_15 -> V_68 ) ,
F_17 ( & V_15 -> V_69 ) ,
F_24 ( & V_15 -> V_70 ) ,
F_17 ( & V_15 -> V_71 ) ,
F_17 ( & V_15 -> V_72 ) ) ;
}
static void F_25 ( const struct V_10 * V_11 ,
const struct V_17 * V_18 )
{
struct V_1 * V_2 = F_13 ( V_18 ) ;
struct V_14 * V_15 = F_9 ( V_2 -> V_6 . V_16 ) ;
int V_73 ;
F_26 ( V_74 , L_6 , V_2 ) ;
F_5 ( V_11 , V_2 ) ;
V_73 = F_27 ( V_11 , V_15 , V_2 ) ;
if ( V_73 ) {
F_28 ( V_75 , V_11 , V_18 -> V_7 ,
L_7 , V_73 ) ;
F_2 ( 0 ) ;
}
F_29 ( F_11 ( V_15 ) , V_2 ) ;
if ( V_18 -> V_7 -> V_76 == V_77 ) {
void * V_78 ;
F_30 ( & V_15 -> V_79 ) ;
V_78 = F_31 ( & V_15 -> V_80 , F_23 ( V_2 ) ) ;
if ( V_78 )
-- V_15 -> V_81 ;
F_32 ( & V_15 -> V_79 ) ;
F_2 ( F_33 ( V_78 , V_78 == V_2 ) ) ;
}
}
static void F_34 ( const struct V_10 * V_11 ,
const struct V_17 * V_18 , int V_82 , int V_83 )
{
struct V_1 * V_2 = F_13 ( V_18 ) ;
struct V_34 * V_35 = & V_2 -> V_36 ;
V_2 -> V_84 = V_82 ;
V_2 -> V_85 = V_83 ;
F_30 ( & V_35 -> V_86 ) ;
V_35 -> V_50 |= V_87 ;
F_32 ( & V_35 -> V_86 ) ;
}
static int F_35 ( const struct V_10 * V_11 ,
const struct V_17 * V_18 )
{
struct V_1 * V_2 = F_13 ( V_18 ) ;
int V_73 = 0 ;
if ( V_2 -> V_8 )
V_73 = F_36 ( V_11 , V_2 ) ;
F_2 ( F_33 ( V_73 == 0 , V_2 -> V_8 == 0 ) ) ;
return V_73 ;
}
static int F_37 ( const struct V_10 * V_11 ,
const struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_13 ( V_18 ) ;
int V_73 ;
V_73 = F_38 ( V_11 , V_20 , V_2 ) ;
return V_73 ;
}
int F_39 ( const struct V_10 * V_11 , struct V_25 * V_15 ,
struct V_4 * V_5 , T_1 V_88 )
{
struct V_14 * V_89 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_40 ( V_15 , V_5 ) ;
int V_21 ;
V_2 -> V_84 = 0 ;
V_2 -> V_85 = V_90 ;
V_21 = F_41 ( V_89 , V_2 , V_5 -> V_91 ,
F_16 ( V_15 , V_88 ) ) ;
if ( V_21 == 0 ) {
struct V_92 * V_93 = F_42 ( V_11 ) ;
V_2 -> V_54 = F_43 ( V_93 ) ;
F_44 ( V_5 , & V_2 -> V_6 , V_15 , V_88 ,
& V_94 ) ;
}
F_45 ( & V_2 -> V_95 ) ;
if ( V_5 -> V_76 == V_77 && V_21 == 0 ) {
V_21 = F_46 ( V_11 , V_89 , V_2 ) ;
if ( V_21 == 0 ) {
F_30 ( & V_89 -> V_79 ) ;
V_21 = F_47 ( & V_89 -> V_80 , V_88 , V_2 ) ;
if ( V_21 == 0 )
++ V_89 -> V_81 ;
F_32 ( & V_89 -> V_79 ) ;
F_2 ( V_21 == 0 ) ;
}
}
return V_21 ;
}
void F_48 ( const struct V_10 * V_11 , struct V_1 * V_2 ,
enum V_12 V_13 , int V_96 )
{
struct V_34 * V_35 = & V_2 -> V_36 ;
F_49 ( V_35 -> V_42 == V_97 , L_8 ,
V_35 , V_35 -> V_42 ) ;
F_2 ( V_35 -> V_50 & V_98 ) ;
F_2 ( V_35 -> V_50 & V_87 ) ;
V_35 -> V_43 = V_13 == V_22 ? V_99 : V_100 ;
V_35 -> V_48 = V_2 -> V_84 ;
V_35 -> V_49 = V_2 -> V_85 - V_2 -> V_84 ;
V_35 -> V_51 = V_96 | V_101 ;
if ( F_50 ( V_102 ) ) {
V_35 -> V_51 |= V_103 ;
V_35 -> V_43 |= V_103 ;
}
V_2 -> V_31 = F_20 () ;
F_1 ( V_2 , L_9 ) ;
F_8 ( V_11 , V_2 , V_13 ) ;
}
static inline int F_51 ( struct V_37 * V_38 )
{
return V_38 -> V_104 * 2 ;
}
static inline int F_52 ( struct V_37 * V_38 )
{
return V_38 -> V_104 * V_38 -> V_57 ;
}
static int F_53 ( struct V_37 * V_38 )
{
struct V_105 * V_106 = V_38 -> V_107 ;
long V_108 = F_54 ( & V_38 -> V_109 ) ;
unsigned long V_110 ;
V_110 = V_106 -> V_111 / ( F_24 ( & V_106 -> V_112 ) - 2 ) ;
if ( F_54 ( V_38 -> V_113 ) < V_106 -> V_111 >> 2 ) {
if ( V_108 >= V_110 )
return F_52 ( V_38 ) ;
else if ( V_108 >= V_110 / 2 )
return F_51 ( V_38 ) ;
} else {
T_3 V_114 = F_55 () ;
long V_115 ;
V_114 -= V_38 -> V_116 ;
V_115 = ( long ) ( V_114 >> 6 ) ;
if ( V_115 > 0 && V_108 >= V_110 / V_115 )
return F_51 ( V_38 ) ;
}
return 0 ;
}
int F_56 ( const struct V_10 * V_11 , void * V_117 )
{
struct V_37 * V_38 = V_117 ;
int V_118 ;
F_26 ( V_119 , L_10 , F_57 ( V_38 ) ) ;
V_118 = F_53 ( V_38 ) ;
if ( V_118 > 0 ) {
int V_73 = F_58 ( V_11 , V_38 , V_118 , false ) ;
F_26 ( V_119 , L_11 ,
F_57 ( V_38 ) , V_73 , V_118 ) ;
if ( V_73 >= V_118 ) {
F_26 ( V_119 , L_12 , F_57 ( V_38 ) ) ;
F_59 ( V_38 -> V_120 ) ;
}
}
return 0 ;
}
void F_60 ( struct V_37 * V_38 , struct V_29 * V_121 )
{
F_61 ( V_122 ) ;
struct V_34 * V_35 ;
long V_123 = 0 ;
F_62 (oap, plist, oap_pending_item) {
struct V_1 * V_2 = F_63 ( V_35 ) ;
if ( ! V_2 -> V_124 )
continue;
++ V_123 ;
F_2 ( F_18 ( & V_2 -> V_95 ) ) ;
F_64 ( & V_2 -> V_95 , & V_122 ) ;
}
if ( V_123 > 0 ) {
F_30 ( & V_38 -> V_125 ) ;
F_65 ( & V_122 , & V_38 -> V_126 ) ;
F_66 ( V_123 , & V_38 -> V_127 ) ;
F_67 ( V_123 , & V_38 -> V_109 ) ;
V_38 -> V_116 = F_55 () ;
F_32 ( & V_38 -> V_125 ) ;
if ( F_68 ( & V_128 ) )
( void ) F_59 ( V_38 -> V_120 ) ;
}
}
static void F_69 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
F_2 ( F_54 ( & V_38 -> V_109 ) > 0 ) ;
F_70 ( & V_2 -> V_95 ) ;
F_71 ( & V_38 -> V_109 ) ;
}
static void F_29 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
if ( V_2 -> V_124 ) {
F_30 ( & V_38 -> V_125 ) ;
if ( ! F_18 ( & V_2 -> V_95 ) ) {
F_69 ( V_38 , V_2 ) ;
} else {
F_2 ( F_54 ( & V_38 -> V_127 ) > 0 ) ;
F_71 ( & V_38 -> V_127 ) ;
}
F_32 ( & V_38 -> V_125 ) ;
F_72 ( V_38 -> V_113 ) ;
if ( F_53 ( V_38 ) ) {
F_26 ( V_119 , L_13 , F_57 ( V_38 ) ) ;
( void ) F_59 ( V_38 -> V_120 ) ;
}
F_73 ( & V_128 ) ;
} else {
F_2 ( F_18 ( & V_2 -> V_95 ) ) ;
}
}
static void F_10 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
if ( V_2 -> V_124 && ! F_18 ( & V_2 -> V_95 ) ) {
F_30 ( & V_38 -> V_125 ) ;
F_69 ( V_38 , V_2 ) ;
F_32 ( & V_38 -> V_125 ) ;
F_72 ( & V_38 -> V_127 ) ;
}
}
static void F_74 ( const struct V_10 * V_11 , struct V_19 * V_20 ,
struct V_4 * * V_129 , int V_130 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_130 ; V_131 ++ ) {
struct V_4 * V_5 = V_129 [ V_131 ] ;
F_2 ( F_75 ( V_5 , V_20 ) ) ;
F_76 ( V_11 , V_5 ) ;
F_77 ( V_11 , V_20 , V_5 ) ;
F_78 ( V_11 , V_20 , V_5 ) ;
F_7 ( V_11 , V_5 ) ;
V_129 [ V_131 ] = NULL ;
}
}
static inline bool F_79 ( struct V_37 * V_38 , struct V_4 * V_5 )
{
if ( F_80 ( V_5 ) )
return true ;
if ( V_38 -> V_107 -> V_132 ) {
struct V_5 * V_133 = F_81 ( V_5 ) ;
if ( F_82 ( V_133 ) - F_83 ( V_133 ) > 2 )
return true ;
}
return false ;
}
long F_58 ( const struct V_10 * V_11 , struct V_37 * V_38 ,
long V_134 , bool V_135 )
{
struct V_19 * V_20 ;
struct V_25 * V_136 = NULL ;
struct V_4 * * V_129 ;
struct V_1 * V_2 ;
int V_137 = 0 ;
long V_118 = 0 ;
int V_88 = 0 ;
int V_73 = 0 ;
F_2 ( F_54 ( & V_38 -> V_109 ) >= 0 ) ;
if ( F_54 ( & V_38 -> V_109 ) == 0 || V_134 <= 0 )
return 0 ;
F_26 ( V_119 , L_14 ,
F_57 ( V_38 ) , F_24 ( & V_38 -> V_138 ) , V_135 ) ;
if ( ! V_135 ) {
if ( F_24 ( & V_38 -> V_138 ) > 0 )
return - V_139 ;
if ( F_84 ( & V_38 -> V_138 ) > 1 ) {
F_85 ( & V_38 -> V_138 ) ;
return - V_139 ;
}
} else {
F_86 ( & V_38 -> V_138 ) ;
}
V_129 = (struct V_4 * * ) F_87 ( V_11 ) -> V_140 ;
V_20 = & F_87 ( V_11 ) -> V_141 ;
F_30 ( & V_38 -> V_125 ) ;
if ( V_135 )
V_38 -> V_142 ++ ;
V_137 = F_88 ( V_134 << 1 , F_54 ( & V_38 -> V_109 ) ) ;
while ( ! F_18 ( & V_38 -> V_126 ) ) {
struct V_4 * V_5 ;
bool V_143 = false ;
if ( ! V_135 && F_24 ( & V_38 -> V_138 ) > 1 )
break;
if ( -- V_137 < 0 )
break;
V_2 = F_89 ( V_38 -> V_126 . V_144 , struct V_1 ,
V_95 ) ;
V_5 = V_2 -> V_6 . V_7 ;
if ( F_79 ( V_38 , V_5 ) ) {
F_90 ( & V_2 -> V_95 , & V_38 -> V_126 ) ;
continue;
}
F_2 ( V_5 -> V_145 ) ;
if ( V_136 != V_5 -> V_145 ) {
struct V_25 * V_146 = V_5 -> V_145 ;
F_91 ( V_146 ) ;
F_32 ( & V_38 -> V_125 ) ;
if ( V_136 ) {
F_74 ( V_11 , V_20 , V_129 , V_88 ) ;
V_88 = 0 ;
F_92 ( V_11 , V_20 ) ;
F_93 ( V_11 , V_136 ) ;
V_136 = NULL ;
}
V_136 = V_146 ;
V_20 -> V_147 = V_136 ;
V_20 -> V_148 = 1 ;
V_73 = F_94 ( V_11 , V_20 , V_149 , V_136 ) ;
F_30 ( & V_38 -> V_125 ) ;
if ( V_73 != 0 )
break;
++ V_137 ;
continue;
}
if ( F_95 ( V_11 , V_20 , V_5 ) == 0 ) {
if ( ! F_79 ( V_38 , V_5 ) ) {
F_69 ( V_38 , V_2 ) ;
V_2 -> V_124 = 0 ;
F_3 ( V_5 ) ;
V_143 = true ;
} else {
F_78 ( V_11 , V_20 , V_5 ) ;
}
}
if ( ! V_143 ) {
F_90 ( & V_2 -> V_95 , & V_38 -> V_126 ) ;
continue;
}
V_129 [ V_88 ++ ] = V_5 ;
if ( F_96 ( V_88 == V_150 ) ) {
F_32 ( & V_38 -> V_125 ) ;
F_74 ( V_11 , V_20 , V_129 , V_88 ) ;
V_88 = 0 ;
F_30 ( & V_38 -> V_125 ) ;
}
if ( ++ V_118 >= V_134 )
break;
}
F_32 ( & V_38 -> V_125 ) ;
if ( V_136 ) {
F_74 ( V_11 , V_20 , V_129 , V_88 ) ;
F_92 ( V_11 , V_20 ) ;
F_93 ( V_11 , V_136 ) ;
}
F_85 ( & V_38 -> V_138 ) ;
if ( V_118 > 0 ) {
F_67 ( V_118 , V_38 -> V_113 ) ;
F_97 ( & V_128 ) ;
}
return V_118 > 0 ? V_118 : V_73 ;
}
long F_98 ( struct V_37 * V_38 , unsigned long V_123 )
{
struct V_10 * V_11 ;
struct V_105 * V_106 = V_38 -> V_107 ;
int V_151 ;
int V_152 ;
long V_73 = 0 ;
F_2 ( V_106 ) ;
V_11 = F_99 ( & V_152 ) ;
if ( F_100 ( V_11 ) )
return 0 ;
V_123 = F_101 ( int , V_123 , V_38 -> V_104 ) ;
F_26 ( V_119 , L_15 ,
F_57 ( V_38 ) , V_123 ) ;
V_73 = F_58 ( V_11 , V_38 , V_123 , true ) ;
if ( V_73 >= V_123 ) {
F_26 ( V_119 , L_16 ,
F_57 ( V_38 ) , V_73 , V_123 ) ;
if ( F_53 ( V_38 ) > 0 )
F_59 ( V_38 -> V_120 ) ;
goto V_153;
} else if ( V_73 > 0 ) {
V_123 -= V_73 ;
}
F_26 ( V_119 , L_17 ,
F_57 ( V_38 ) , V_38 , F_54 ( & V_38 -> V_109 ) ,
F_54 ( & V_38 -> V_127 ) , V_123 ) ;
F_30 ( & V_106 -> V_154 ) ;
F_2 ( ! F_18 ( & V_106 -> V_155 ) ) ;
V_106 -> V_156 ++ ;
F_90 ( & V_38 -> V_157 , & V_106 -> V_155 ) ;
V_151 = F_24 ( & V_106 -> V_112 ) - 2 ;
while ( -- V_151 > 0 && ! F_18 ( & V_106 -> V_155 ) ) {
V_38 = F_89 ( V_106 -> V_155 . V_144 , struct V_37 ,
V_157 ) ;
F_26 ( V_119 , L_18 ,
F_57 ( V_38 ) , V_38 ,
F_54 ( & V_38 -> V_109 ) ,
F_54 ( & V_38 -> V_127 ) ) ;
F_90 ( & V_38 -> V_157 , & V_106 -> V_155 ) ;
if ( F_53 ( V_38 ) > 0 ) {
F_32 ( & V_106 -> V_154 ) ;
V_73 = F_58 ( V_11 , V_38 , V_123 , true ) ;
F_30 ( & V_106 -> V_154 ) ;
if ( V_73 >= V_123 )
break;
if ( V_73 > 0 )
V_123 -= V_73 ;
}
}
F_32 ( & V_106 -> V_154 ) ;
V_153:
F_102 ( V_11 , & V_152 ) ;
F_26 ( V_119 , L_19 ,
F_57 ( V_38 ) , V_38 , V_73 ) ;
return V_73 ;
}
static int F_46 ( const struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_158 V_159 = F_103 ( V_160 , NULL ) ;
struct V_92 * V_93 = F_42 ( V_11 ) ;
struct V_37 * V_38 = F_11 ( V_15 ) ;
int V_73 = 0 ;
if ( ! V_38 -> V_107 )
return 0 ;
if ( V_93 -> V_161 > 0 ) {
-- V_93 -> V_161 ;
goto V_153;
}
F_2 ( F_54 ( V_38 -> V_113 ) >= 0 ) ;
while ( ! F_104 ( V_38 -> V_113 , - 1 , 0 ) ) {
V_73 = F_98 ( V_38 , 1 ) ;
if ( V_73 < 0 )
break;
if ( V_73 > 0 )
continue;
F_105 () ;
V_73 = F_106 ( V_128 ,
F_54 ( V_38 -> V_113 ) > 0 ,
& V_159 ) ;
if ( V_73 < 0 )
break;
}
V_153:
if ( V_73 >= 0 ) {
F_72 ( & V_38 -> V_127 ) ;
V_2 -> V_124 = 1 ;
V_73 = 0 ;
}
return V_73 ;
}
static inline void F_107 ( struct V_162 * V_163 ,
int V_164 )
{
int F_82 = V_163 -> V_165 ;
T_4 * V_166 = NULL ;
int V_118 = 0 ;
int V_131 ;
F_2 ( F_108 ( V_163 -> V_167 ) ) ;
for ( V_131 = 0 ; V_131 < F_82 ; V_131 ++ ) {
T_4 * V_168 = F_109 ( F_110 ( V_163 , V_131 ) . V_169 ) ;
if ( F_111 ( V_168 == V_166 ) ) {
++ V_118 ;
continue;
}
if ( V_118 > 0 ) {
F_112 ( V_168 , V_170 ,
V_164 * V_118 ) ;
V_118 = 0 ;
}
V_166 = V_168 ;
++ V_118 ;
}
if ( V_118 > 0 )
F_112 ( V_166 , V_170 , V_164 * V_118 ) ;
}
static inline void F_113 ( struct V_162 * V_163 )
{
F_107 ( V_163 , 1 ) ;
}
static inline void F_114 ( struct V_162 * V_163 )
{
F_107 ( V_163 , - 1 ) ;
}
void F_115 ( struct V_171 * V_172 )
{
struct V_37 * V_38 = & V_172 -> V_173 -> V_174 -> V_40 . V_38 ;
struct V_162 * V_163 = V_172 -> V_175 ;
int F_82 = V_163 -> V_165 ;
long V_176 ;
F_2 ( F_82 >= 0 ) ;
F_114 ( V_163 ) ;
V_176 = F_116 ( F_82 ,
& V_38 -> V_177 ) ;
F_2 ( V_176 >= 0 ) ;
V_176 = F_116 ( F_82 ,
& V_38 -> V_107 -> V_178 ) ;
F_2 ( V_176 >= 0 ) ;
if ( ! V_176 )
F_97 ( & V_38 -> V_107 -> V_179 ) ;
if ( F_68 ( & V_128 ) )
( void ) F_59 ( V_38 -> V_120 ) ;
}
void F_117 ( struct V_171 * V_172 )
{
struct V_37 * V_38 = & V_172 -> V_173 -> V_174 -> V_40 . V_38 ;
struct V_162 * V_163 = V_172 -> V_175 ;
long F_82 = V_163 -> V_165 ;
if ( ! V_38 -> V_107 || ! V_38 -> V_107 -> V_132 )
return;
F_113 ( V_163 ) ;
F_67 ( F_82 , & V_38 -> V_177 ) ;
F_67 ( F_82 , & V_38 -> V_107 -> V_178 ) ;
F_30 ( & V_172 -> V_180 ) ;
if ( F_96 ( V_172 -> V_181 ) ) {
F_32 ( & V_172 -> V_180 ) ;
F_115 ( V_172 ) ;
} else {
V_172 -> V_182 = 1 ;
F_32 ( & V_172 -> V_180 ) ;
}
}
bool F_118 ( struct V_37 * V_38 )
{
long V_183 , V_184 ;
if ( ! V_38 -> V_107 || ! V_38 -> V_107 -> V_132 )
return false ;
V_184 = F_54 ( & V_38 -> V_177 ) ;
V_183 = F_54 ( & V_38 -> V_107 -> V_178 ) ;
F_26 ( V_119 ,
L_20 ,
F_57 ( V_38 ) , V_38 , V_183 , V_184 ) ;
return V_183 > V_38 -> V_107 -> V_111 >> 2 &&
V_184 > V_38 -> V_104 *
V_38 -> V_57 ;
}
unsigned long F_119 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_37 * V_38 ;
unsigned long V_189 = 0 ;
F_30 ( & V_190 ) ;
F_62 (cli, &osc_shrink_list, cl_shrink_list)
V_189 += F_54 ( & V_38 -> V_109 ) ;
F_32 ( & V_190 ) ;
return ( V_189 * V_191 ) / 100 ;
}
unsigned long F_120 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_37 * V_192 = NULL ;
struct V_37 * V_38 ;
struct V_10 * V_11 ;
long V_193 = 0 ;
int V_152 ;
int V_73 ;
if ( ! V_188 -> V_194 )
return 0 ;
if ( ! ( V_188 -> V_195 & V_196 ) )
return V_197 ;
V_11 = F_99 ( & V_152 ) ;
if ( F_100 ( V_11 ) )
return V_197 ;
F_30 ( & V_190 ) ;
while ( ! F_18 ( & V_198 ) ) {
V_38 = F_89 ( V_198 . V_144 , struct V_37 ,
V_199 ) ;
if ( ! V_192 )
V_192 = V_38 ;
else if ( V_38 == V_192 )
break;
F_90 ( & V_38 -> V_199 , & V_198 ) ;
F_32 ( & V_190 ) ;
V_73 = F_58 ( V_11 , V_38 , ( V_188 -> V_194 - V_193 ) >
V_38 -> V_104 ?
V_38 -> V_104 :
V_188 -> V_194 - V_193 , true ) ;
if ( V_73 > 0 )
V_193 += V_73 ;
if ( V_193 >= V_188 -> V_194 )
goto V_153;
F_30 ( & V_190 ) ;
}
F_32 ( & V_190 ) ;
V_153:
F_102 ( V_11 , & V_152 ) ;
return V_193 ;
}
