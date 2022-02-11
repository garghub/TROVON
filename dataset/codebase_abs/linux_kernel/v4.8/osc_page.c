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
F_12 ( & V_15 -> V_17 ) ;
F_13 ( & V_2 -> V_18 , & V_15 -> V_19 [ V_13 ] ) ;
V_2 -> V_20 = V_21 ;
F_14 ( & V_15 -> V_17 ) ;
}
int F_15 ( const struct V_10 * V_11 ,
const struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
int V_26 ;
F_1 ( V_2 , L_2 ) ;
V_26 = F_17 ( V_11 , V_25 , V_2 ) ;
if ( V_26 != 0 )
F_5 ( V_11 , V_2 ) ;
else
F_8 ( V_11 , V_2 , V_27 ) ;
return V_26 ;
}
void F_18 ( T_1 * V_28 , const struct V_29 * V_15 ,
T_2 V_30 , T_2 V_31 )
{
memset ( V_28 , 0 , sizeof( * V_28 ) ) ;
V_28 -> V_32 . V_30 = F_19 ( V_15 , V_30 ) ;
V_28 -> V_32 . V_31 = F_19 ( V_15 , V_31 + 1 ) - 1 ;
}
static int F_20 ( const struct V_10 * V_11 ,
const struct V_22 * V_23 ,
struct V_24 * V_33 , T_2 * V_34 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
struct V_35 * V_36 ;
int V_26 = - V_37 ;
V_36 = F_21 ( V_11 , F_9 ( V_23 -> V_16 ) ,
F_22 ( V_2 ) , 1 , 0 ) ;
if ( V_36 ) {
* V_34 = F_23 ( V_23 -> V_16 ,
V_36 -> V_38 . V_32 . V_31 ) ;
F_24 ( V_36 ) ;
V_26 = 0 ;
}
return V_26 ;
}
static const char * F_25 ( struct V_39 * V_40 )
{
return F_26 ( V_40 ) ? L_3 : L_4 ;
}
static inline unsigned long F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 == 0 )
return 0 ;
return ( F_28 () - V_2 -> V_41 ) ;
}
static int F_29 ( const struct V_10 * V_11 ,
const struct V_22 * V_23 ,
void * V_42 , T_3 V_43 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
struct V_44 * V_45 = & V_2 -> V_46 ;
struct V_14 * V_15 = F_9 ( V_23 -> V_16 ) ;
struct V_47 * V_48 = & F_30 ( V_15 ) -> V_49 -> V_50 . V_48 ;
return (* V_43)( V_11 , V_42 , V_51 L_5 ,
V_2 , F_22 ( V_2 ) ,
V_45 -> V_52 , V_45 -> V_53 ,
V_45 -> V_54 ,
F_25 ( & V_45 -> V_55 ) ,
F_25 ( & V_45 -> V_56 ) ,
V_45 -> V_57 , V_45 -> V_58 , V_45 -> V_59 ,
V_45 -> V_60 , V_45 -> V_61 ,
V_45 -> V_62 , V_45 -> V_63 , V_15 ,
F_25 ( & V_2 -> V_18 ) ,
V_2 -> V_20 , V_2 -> V_8 ,
F_27 ( V_2 ) , V_2 -> V_64 ,
V_48 -> V_65 , V_48 -> V_66 ,
V_48 -> V_67 ,
V_48 -> V_68 ,
F_25 ( & V_48 -> V_69 ) ,
F_25 ( & V_48 -> V_70 ) ,
F_25 ( & V_48 -> V_71 ) ,
F_25 ( & V_48 -> V_72 ) ,
F_25 ( & V_48 -> V_73 ) ,
F_25 ( & V_15 -> V_74 ) ,
F_25 ( & V_15 -> V_75 ) ,
F_25 ( & V_15 -> V_76 ) ,
F_25 ( & V_15 -> V_77 ) ,
F_31 ( & V_15 -> V_78 ) ,
F_25 ( & V_15 -> V_79 ) ,
F_31 ( & V_15 -> V_80 ) ,
F_25 ( & V_15 -> V_81 ) ,
F_25 ( & V_15 -> V_82 ) ) ;
}
static void F_32 ( const struct V_10 * V_11 ,
const struct V_22 * V_23 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
struct V_14 * V_15 = F_9 ( V_2 -> V_6 . V_16 ) ;
int V_83 ;
F_33 ( V_84 , L_6 , V_2 ) ;
F_5 ( V_11 , V_2 ) ;
V_83 = F_34 ( V_11 , V_15 , V_2 ) ;
if ( V_83 ) {
F_35 ( V_85 , V_11 , V_23 -> V_7 ,
L_7 , V_83 ) ;
F_2 ( 0 ) ;
}
F_12 ( & V_15 -> V_17 ) ;
if ( V_2 -> V_20 ) {
F_2 ( ! F_26 ( & V_2 -> V_18 ) ) ;
F_36 ( & V_2 -> V_18 ) ;
V_2 -> V_20 = NULL ;
}
F_14 ( & V_15 -> V_17 ) ;
F_37 ( F_11 ( V_15 ) , V_2 ) ;
if ( V_23 -> V_7 -> V_86 == V_87 ) {
void * V_88 ;
F_12 ( & V_15 -> V_89 ) ;
V_88 = F_38 ( & V_15 -> V_90 , F_22 ( V_2 ) ) ;
if ( V_88 )
-- V_15 -> V_91 ;
F_14 ( & V_15 -> V_89 ) ;
F_2 ( F_39 ( V_88 , V_88 == V_2 ) ) ;
}
}
static void F_40 ( const struct V_10 * V_11 ,
const struct V_22 * V_23 , int V_92 , int V_93 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
struct V_44 * V_45 = & V_2 -> V_46 ;
V_2 -> V_94 = V_92 ;
V_2 -> V_95 = V_93 ;
F_12 ( & V_45 -> V_96 ) ;
V_45 -> V_60 |= V_97 ;
F_14 ( & V_45 -> V_96 ) ;
}
static int F_41 ( const struct V_10 * V_11 ,
const struct V_22 * V_23 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
int V_83 = 0 ;
if ( V_2 -> V_8 )
V_83 = F_42 ( V_11 , V_2 ) ;
F_2 ( F_39 ( V_83 == 0 , V_2 -> V_8 == 0 ) ) ;
return V_83 ;
}
static int F_43 ( const struct V_10 * V_11 ,
const struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_16 ( V_23 ) ;
int V_83 ;
V_83 = F_44 ( V_11 , V_25 , V_2 ) ;
return V_83 ;
}
int F_45 ( const struct V_10 * V_11 , struct V_29 * V_15 ,
struct V_4 * V_5 , T_2 V_98 )
{
struct V_14 * V_99 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_46 ( V_15 , V_5 ) ;
int V_26 ;
V_2 -> V_94 = 0 ;
V_2 -> V_95 = V_100 ;
V_26 = F_47 ( V_99 , V_2 , V_5 -> V_101 ,
F_19 ( V_15 , V_98 ) ) ;
if ( V_26 == 0 ) {
struct V_102 * V_103 = F_48 ( V_11 ) ;
V_2 -> V_64 = F_49 ( V_103 ) ;
F_50 ( V_5 , & V_2 -> V_6 , V_15 , V_98 ,
& V_104 ) ;
}
F_51 ( & V_2 -> V_18 ) ;
F_51 ( & V_2 -> V_105 ) ;
if ( V_5 -> V_86 == V_87 && V_26 == 0 ) {
V_26 = F_52 ( V_11 , V_99 , V_2 ) ;
if ( V_26 == 0 ) {
F_12 ( & V_99 -> V_89 ) ;
V_26 = F_53 ( & V_99 -> V_90 , V_98 , V_2 ) ;
if ( V_26 == 0 )
++ V_99 -> V_91 ;
F_14 ( & V_99 -> V_89 ) ;
F_2 ( V_26 == 0 ) ;
}
}
return V_26 ;
}
int F_54 ( struct V_47 * V_48 )
{
long V_106 , V_107 , V_108 ;
if ( ! V_48 )
return 0 ;
V_106 = F_31 ( & V_109 ) ;
V_107 = F_31 ( & V_110 ) ;
V_108 = F_31 ( & V_48 -> V_111 ) ;
return V_108 &&
V_106 >= ( V_112 - V_107 ) / 2 ;
}
void F_55 ( const struct V_10 * V_11 , struct V_1 * V_2 ,
enum V_12 V_13 , int V_113 )
{
struct V_44 * V_45 = & V_2 -> V_46 ;
F_56 ( V_45 -> V_52 == V_114 , L_8 ,
V_45 , V_45 -> V_52 ) ;
F_2 ( V_45 -> V_60 & V_115 ) ;
F_2 ( V_45 -> V_60 & V_97 ) ;
V_45 -> V_53 = V_13 == V_27 ? V_116 : V_117 ;
V_45 -> V_58 = V_2 -> V_94 ;
V_45 -> V_59 = V_2 -> V_95 - V_2 -> V_94 ;
V_45 -> V_61 = V_113 | V_118 ;
if ( F_54 ( V_45 -> V_63 ) )
V_45 -> V_61 |= V_119 ;
if ( F_57 ( V_120 ) ) {
V_45 -> V_61 |= V_121 ;
V_45 -> V_53 |= V_121 ;
}
V_2 -> V_41 = F_28 () ;
F_1 ( V_2 , L_9 ) ;
F_8 ( V_11 , V_2 , V_13 ) ;
}
static int F_58 ( struct V_47 * V_48 )
{
struct V_122 * V_123 = V_48 -> V_124 ;
int V_125 = F_31 ( & V_48 -> V_126 ) ;
unsigned long V_127 ;
V_127 = V_123 -> V_128 / ( F_31 ( & V_123 -> V_129 ) - 2 ) ;
if ( F_31 ( V_48 -> V_130 ) < V_123 -> V_128 >> 4 ) {
if ( V_125 >= V_127 )
return V_131 ;
else if ( V_125 >= V_127 / 2 )
return V_132 ;
} else if ( V_125 >= V_127 * 2 ) {
return V_132 ;
}
return 0 ;
}
int F_59 ( const struct V_10 * V_11 , void * V_133 )
{
struct V_47 * V_48 = V_133 ;
F_33 ( V_134 , L_10 , V_48 ) ;
if ( F_58 ( V_48 ) )
F_60 ( V_11 , V_48 , V_131 , true ) ;
return 0 ;
}
void F_61 ( struct V_47 * V_48 , struct V_39 * V_135 )
{
F_62 ( V_136 ) ;
struct V_44 * V_45 ;
int V_137 = 0 ;
F_63 (oap, plist, oap_pending_item) {
struct V_1 * V_2 = F_64 ( V_45 ) ;
if ( ! V_2 -> V_138 )
continue;
++ V_137 ;
F_2 ( F_26 ( & V_2 -> V_105 ) ) ;
F_13 ( & V_2 -> V_105 , & V_136 ) ;
}
if ( V_137 > 0 ) {
F_12 ( & V_48 -> V_139 ) ;
F_65 ( & V_136 , & V_48 -> V_140 ) ;
F_66 ( V_137 , & V_48 -> V_141 ) ;
F_67 ( V_137 , & V_48 -> V_126 ) ;
F_14 ( & V_48 -> V_139 ) ;
if ( F_58 ( V_48 ) )
( void ) F_68 ( V_48 -> V_142 ) ;
}
}
static void F_69 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
F_2 ( F_31 ( & V_48 -> V_126 ) > 0 ) ;
F_36 ( & V_2 -> V_105 ) ;
F_70 ( & V_48 -> V_126 ) ;
}
static void F_37 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_2 -> V_138 ) {
F_12 ( & V_48 -> V_139 ) ;
if ( ! F_26 ( & V_2 -> V_105 ) ) {
F_69 ( V_48 , V_2 ) ;
} else {
F_2 ( F_31 ( & V_48 -> V_141 ) > 0 ) ;
F_70 ( & V_48 -> V_141 ) ;
}
F_14 ( & V_48 -> V_139 ) ;
F_71 ( V_48 -> V_130 ) ;
if ( ! F_72 () )
( void ) F_68 ( V_48 -> V_142 ) ;
F_73 ( & V_143 ) ;
} else {
F_2 ( F_26 ( & V_2 -> V_105 ) ) ;
}
}
static void F_10 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_2 -> V_138 && ! F_26 ( & V_2 -> V_105 ) ) {
F_12 ( & V_48 -> V_139 ) ;
F_69 ( V_48 , V_2 ) ;
F_14 ( & V_48 -> V_139 ) ;
F_71 ( & V_48 -> V_141 ) ;
}
}
static void F_74 ( const struct V_10 * V_11 , struct V_24 * V_25 ,
struct V_4 * * V_144 , int V_34 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < V_34 ; V_145 ++ ) {
struct V_4 * V_5 = V_144 [ V_145 ] ;
F_2 ( F_75 ( V_5 , V_25 ) ) ;
F_76 ( V_11 , V_25 , V_5 ) ;
F_77 ( V_11 , V_25 , V_5 ) ;
F_7 ( V_11 , V_5 ) ;
V_144 [ V_145 ] = NULL ;
}
}
int F_60 ( const struct V_10 * V_11 , struct V_47 * V_48 ,
int V_146 , bool V_147 )
{
struct V_24 * V_25 ;
struct V_29 * V_148 = NULL ;
struct V_4 * * V_144 ;
struct V_1 * V_2 ;
struct V_1 * V_149 ;
int V_150 = 0 ;
int V_151 = 0 ;
int V_98 = 0 ;
int V_83 = 0 ;
F_2 ( F_31 ( & V_48 -> V_126 ) >= 0 ) ;
if ( F_31 ( & V_48 -> V_126 ) == 0 || V_146 <= 0 )
return 0 ;
if ( ! V_147 ) {
if ( F_31 ( & V_48 -> V_152 ) > 0 )
return - V_153 ;
if ( F_78 ( & V_48 -> V_152 ) > 1 ) {
F_70 ( & V_48 -> V_152 ) ;
return - V_153 ;
}
} else {
F_71 ( & V_48 -> V_152 ) ;
}
V_144 = (struct V_4 * * ) F_79 ( V_11 ) -> V_154 ;
V_25 = & F_79 ( V_11 ) -> V_155 ;
F_12 ( & V_48 -> V_139 ) ;
V_150 = F_80 ( V_146 << 1 , F_31 ( & V_48 -> V_126 ) ) ;
F_81 (opg, temp, &cli->cl_lru_list, ops_lru) {
struct V_4 * V_5 ;
bool V_156 = false ;
if ( -- V_150 < 0 )
break;
V_5 = V_2 -> V_6 . V_7 ;
if ( F_82 ( V_5 ) ) {
F_83 ( & V_2 -> V_105 , & V_48 -> V_140 ) ;
continue;
}
F_2 ( V_5 -> V_157 ) ;
if ( V_148 != V_5 -> V_157 ) {
struct V_29 * V_158 = V_5 -> V_157 ;
F_84 ( V_158 ) ;
F_14 ( & V_48 -> V_139 ) ;
if ( V_148 ) {
F_74 ( V_11 , V_25 , V_144 , V_98 ) ;
V_98 = 0 ;
F_85 ( V_11 , V_25 ) ;
F_86 ( V_11 , V_148 ) ;
V_148 = NULL ;
}
V_148 = V_158 ;
V_25 -> V_159 = V_148 ;
V_25 -> V_160 = 1 ;
V_83 = F_87 ( V_11 , V_25 , V_161 , V_148 ) ;
F_12 ( & V_48 -> V_139 ) ;
if ( V_83 != 0 )
break;
++ V_150 ;
continue;
}
if ( F_88 ( V_11 , V_25 , V_5 ) == 0 ) {
if ( ! F_82 ( V_5 ) ) {
F_69 ( V_48 , V_2 ) ;
V_2 -> V_138 = 0 ;
F_3 ( V_5 ) ;
V_156 = true ;
} else {
F_77 ( V_11 , V_25 , V_5 ) ;
}
}
if ( ! V_156 ) {
F_83 ( & V_2 -> V_105 , & V_48 -> V_140 ) ;
continue;
}
V_144 [ V_98 ++ ] = V_5 ;
if ( F_89 ( V_98 == V_162 ) ) {
F_14 ( & V_48 -> V_139 ) ;
F_74 ( V_11 , V_25 , V_144 , V_98 ) ;
V_98 = 0 ;
F_12 ( & V_48 -> V_139 ) ;
}
if ( ++ V_151 >= V_146 )
break;
}
F_14 ( & V_48 -> V_139 ) ;
if ( V_148 ) {
F_74 ( V_11 , V_25 , V_144 , V_98 ) ;
F_85 ( V_11 , V_25 ) ;
F_86 ( V_11 , V_148 ) ;
}
F_70 ( & V_48 -> V_152 ) ;
if ( V_151 > 0 ) {
F_67 ( V_151 , V_48 -> V_130 ) ;
F_90 ( & V_143 ) ;
}
return V_151 > 0 ? V_151 : V_83 ;
}
static inline int F_91 ( struct V_47 * V_48 )
{
return F_80 ( F_31 ( & V_48 -> V_126 ) >> 1 , V_131 ) ;
}
int F_92 ( struct V_47 * V_48 )
{
struct V_163 V_164 ;
struct V_10 * V_11 ;
struct V_122 * V_123 = V_48 -> V_124 ;
int V_165 ;
int V_83 = 0 ;
F_2 ( V_123 ) ;
V_11 = F_93 ( & V_164 ) ;
if ( F_94 ( V_11 ) )
return 0 ;
V_83 = F_60 ( V_11 , V_48 , F_58 ( V_48 ) , false ) ;
if ( V_83 != 0 ) {
if ( V_83 == - V_153 )
V_83 = 0 ;
F_33 ( V_134 , L_11 ,
V_48 -> V_166 -> V_167 -> V_168 , V_83 , V_48 ) ;
goto V_169;
}
F_33 ( V_134 , L_12 ,
V_48 -> V_166 -> V_167 -> V_168 , V_48 ,
F_31 ( & V_48 -> V_126 ) ,
F_31 ( & V_48 -> V_141 ) ) ;
F_12 ( & V_123 -> V_170 ) ;
F_2 ( ! F_26 ( & V_123 -> V_171 ) ) ;
V_123 -> V_172 ++ ;
F_83 ( & V_48 -> V_173 , & V_123 -> V_171 ) ;
V_165 = F_31 ( & V_123 -> V_129 ) - 2 ;
while ( -- V_165 > 0 && ! F_26 ( & V_123 -> V_171 ) ) {
V_48 = F_95 ( V_123 -> V_171 . V_174 , struct V_47 ,
V_173 ) ;
F_33 ( V_134 , L_13 ,
V_48 -> V_166 -> V_167 -> V_168 , V_48 ,
F_31 ( & V_48 -> V_126 ) ,
F_31 ( & V_48 -> V_141 ) ) ;
F_83 ( & V_48 -> V_173 , & V_123 -> V_171 ) ;
if ( F_58 ( V_48 ) > 0 ) {
F_14 ( & V_123 -> V_170 ) ;
V_83 = F_60 ( V_11 , V_48 , F_58 ( V_48 ) ,
true ) ;
F_12 ( & V_123 -> V_170 ) ;
if ( V_83 != 0 )
break;
}
}
F_14 ( & V_123 -> V_170 ) ;
V_169:
F_96 ( & V_164 , V_11 ) ;
F_33 ( V_134 , L_14 ,
V_48 -> V_166 -> V_167 -> V_168 , V_48 , V_83 ) ;
return V_83 ;
}
static int F_52 ( const struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_175 V_176 = F_97 ( V_177 , NULL ) ;
struct V_102 * V_103 = F_48 ( V_11 ) ;
struct V_47 * V_48 = F_11 ( V_15 ) ;
int V_83 = 0 ;
if ( ! V_48 -> V_124 )
return 0 ;
if ( V_103 -> V_178 > 0 ) {
-- V_103 -> V_178 ;
goto V_169;
}
F_2 ( F_31 ( V_48 -> V_130 ) >= 0 ) ;
while ( ! F_98 ( V_48 -> V_130 , - 1 , 0 ) ) {
V_83 = F_92 ( V_48 ) ;
if ( V_83 < 0 )
break;
if ( V_83 > 0 )
continue;
F_99 () ;
V_83 = F_100 ( V_143 ,
F_31 ( V_48 -> V_130 ) > 0 ,
& V_176 ) ;
if ( V_83 < 0 )
break;
}
V_169:
if ( V_83 >= 0 ) {
F_71 ( & V_48 -> V_141 ) ;
V_2 -> V_138 = 1 ;
V_83 = 0 ;
}
return V_83 ;
}
