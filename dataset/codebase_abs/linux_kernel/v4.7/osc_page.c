static int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 V_6 , int V_7 )
{
return 1 ;
}
static void F_2 ( struct V_3 * V_4 , const char * V_8 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_12 ;
F_3 ( ! V_4 -> V_13 ) ;
F_4 ( V_10 ) ;
F_5 ( & V_10 -> V_14 , V_8 , V_10 ) ;
V_4 -> V_13 = 1 ;
}
static void F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_12 ;
if ( V_4 -> V_13 ) {
V_4 -> V_13 = 0 ;
F_7 ( & V_10 -> V_14 , L_1 , V_10 ) ;
F_8 ( V_2 , V_10 ) ;
}
}
static void F_9 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , enum V_15 V_16 )
{
struct V_17 * V_18 = F_10 ( V_4 -> V_11 . V_19 ) ;
F_11 ( F_12 ( V_18 ) , V_4 ) ;
F_13 ( & V_18 -> V_20 ) ;
F_14 ( & V_4 -> V_21 , & V_18 -> V_22 [ V_16 ] ) ;
V_4 -> V_23 = V_24 ;
F_15 ( & V_18 -> V_20 ) ;
}
int F_16 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 , struct V_27 * V_28 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
int V_29 ;
F_18 ( F_1 ( V_2 , V_4 , V_30 , 0 ) ) ;
F_2 ( V_4 , L_2 ) ;
V_29 = F_19 ( V_2 , V_28 , V_4 ) ;
if ( V_29 != 0 )
F_6 ( V_2 , V_4 ) ;
else
F_9 ( V_2 , V_4 , V_31 ) ;
return V_29 ;
}
void F_20 ( T_1 * V_32 , const struct V_33 * V_18 ,
T_2 V_34 , T_2 V_35 )
{
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_36 . V_34 = F_21 ( V_18 , V_34 ) ;
V_32 -> V_36 . V_35 = F_21 ( V_18 , V_35 + 1 ) - 1 ;
}
static int F_22 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 ,
struct V_27 * V_37 , T_2 * V_38 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_39 * V_40 ;
int V_29 = - V_41 ;
V_40 = F_23 ( V_2 , F_10 ( V_26 -> V_19 ) ,
F_24 ( V_4 ) , 1 , 0 ) ;
if ( V_40 ) {
* V_38 = F_25 ( V_26 -> V_19 ,
V_40 -> V_42 . V_36 . V_35 ) ;
F_26 ( V_40 ) ;
V_29 = 0 ;
}
return V_29 ;
}
static const char * F_27 ( struct V_43 * V_44 )
{
return F_28 ( V_44 ) ? L_3 : L_4 ;
}
static inline unsigned long F_29 ( struct V_3 * V_4 )
{
if ( V_4 -> V_45 == 0 )
return 0 ;
return ( F_30 () - V_4 -> V_45 ) ;
}
static int F_31 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 ,
void * V_46 , T_3 V_47 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_48 * V_49 = & V_4 -> V_50 ;
struct V_17 * V_18 = F_10 ( V_26 -> V_19 ) ;
struct V_51 * V_52 = & F_32 ( V_18 ) -> V_53 -> V_54 . V_52 ;
return (* V_47)( V_2 , V_46 , V_55 L_5 ,
V_4 , F_24 ( V_4 ) ,
V_49 -> V_56 , V_49 -> V_57 ,
V_49 -> V_58 ,
F_27 ( & V_49 -> V_59 ) ,
F_27 ( & V_49 -> V_60 ) ,
V_49 -> V_61 , V_49 -> V_62 , V_49 -> V_63 ,
V_49 -> V_64 , V_49 -> V_65 ,
V_49 -> V_66 , V_49 -> V_67 , V_18 ,
F_27 ( & V_4 -> V_21 ) ,
V_4 -> V_23 , V_4 -> V_13 ,
F_29 ( V_4 ) , V_4 -> V_68 ,
V_52 -> V_69 , V_52 -> V_70 ,
V_52 -> V_71 ,
V_52 -> V_72 ,
F_27 ( & V_52 -> V_73 ) ,
F_27 ( & V_52 -> V_74 ) ,
F_27 ( & V_52 -> V_75 ) ,
F_27 ( & V_52 -> V_76 ) ,
F_27 ( & V_52 -> V_77 ) ,
F_27 ( & V_18 -> V_78 ) ,
F_27 ( & V_18 -> V_79 ) ,
F_27 ( & V_18 -> V_80 ) ,
F_27 ( & V_18 -> V_81 ) ,
F_33 ( & V_18 -> V_82 ) ,
F_27 ( & V_18 -> V_83 ) ,
F_33 ( & V_18 -> V_84 ) ,
F_27 ( & V_18 -> V_85 ) ,
F_27 ( & V_18 -> V_86 ) ) ;
}
static void F_34 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_17 * V_18 = F_10 ( V_4 -> V_11 . V_19 ) ;
int V_87 ;
F_18 ( V_4 -> V_88 || F_1 ( V_2 , V_4 , V_89 , 1 ) ) ;
F_35 ( V_90 , L_6 , V_4 ) ;
F_6 ( V_2 , V_4 ) ;
V_87 = F_36 ( V_2 , V_18 , V_4 ) ;
if ( V_87 ) {
F_37 ( V_91 , V_2 , V_26 -> V_12 ,
L_7 , V_87 ) ;
F_3 ( 0 ) ;
}
F_13 ( & V_18 -> V_20 ) ;
if ( V_4 -> V_23 ) {
F_3 ( ! F_28 ( & V_4 -> V_21 ) ) ;
F_38 ( & V_4 -> V_21 ) ;
V_4 -> V_23 = NULL ;
}
F_15 ( & V_18 -> V_20 ) ;
F_39 ( F_12 ( V_18 ) , V_4 ) ;
if ( V_26 -> V_12 -> V_92 == V_93 ) {
void * V_94 ;
F_13 ( & V_18 -> V_95 ) ;
V_94 = F_40 ( & V_18 -> V_96 , F_24 ( V_4 ) ) ;
if ( V_94 )
-- V_18 -> V_97 ;
F_15 ( & V_18 -> V_95 ) ;
F_3 ( F_41 ( V_94 , V_94 == V_4 ) ) ;
}
}
static void F_42 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 , int V_98 , int V_99 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
struct V_48 * V_49 = & V_4 -> V_50 ;
F_18 ( F_1 ( V_2 , V_4 , V_89 , 0 ) ) ;
V_4 -> V_100 = V_98 ;
V_4 -> V_101 = V_99 ;
F_13 ( & V_49 -> V_102 ) ;
V_49 -> V_64 |= V_103 ;
F_15 ( & V_49 -> V_102 ) ;
}
static int F_43 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
int V_87 = 0 ;
F_18 ( F_1 ( V_2 , V_4 , V_89 , 0 ) ) ;
if ( V_4 -> V_13 )
V_87 = F_44 ( V_2 , V_4 ) ;
F_3 ( F_41 ( V_87 == 0 , V_4 -> V_13 == 0 ) ) ;
return V_87 ;
}
static int F_45 ( const struct V_1 * V_2 ,
const struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_3 * V_4 = F_17 ( V_26 ) ;
int V_87 ;
V_87 = F_46 ( V_2 , V_28 , V_4 ) ;
return V_87 ;
}
int F_47 ( const struct V_1 * V_2 , struct V_33 * V_18 ,
struct V_9 * V_10 , T_2 V_104 )
{
struct V_17 * V_105 = F_10 ( V_18 ) ;
struct V_3 * V_4 = F_48 ( V_18 , V_10 ) ;
int V_29 ;
V_4 -> V_100 = 0 ;
V_4 -> V_101 = V_106 ;
V_29 = F_49 ( V_105 , V_4 , V_10 -> V_107 ,
F_21 ( V_18 , V_104 ) ) ;
if ( V_29 == 0 ) {
struct V_108 * V_109 = F_50 ( V_2 ) ;
V_4 -> V_68 = F_51 ( V_109 ) ;
F_52 ( V_10 , & V_4 -> V_11 , V_18 , V_104 ,
& V_110 ) ;
}
F_53 ( & V_4 -> V_21 ) ;
F_53 ( & V_4 -> V_111 ) ;
if ( V_10 -> V_92 == V_93 && V_29 == 0 ) {
V_29 = F_54 ( V_2 , V_105 , V_4 ) ;
if ( V_29 == 0 ) {
F_13 ( & V_105 -> V_95 ) ;
V_29 = F_55 ( & V_105 -> V_96 , V_104 , V_4 ) ;
if ( V_29 == 0 )
++ V_105 -> V_97 ;
F_15 ( & V_105 -> V_95 ) ;
F_3 ( V_29 == 0 ) ;
}
}
return V_29 ;
}
int F_56 ( struct V_51 * V_52 )
{
long V_112 , V_113 , V_114 ;
if ( ! V_52 )
return 0 ;
V_112 = F_33 ( & V_115 ) ;
V_113 = F_33 ( & V_116 ) ;
V_114 = F_33 ( & V_52 -> V_117 ) ;
return V_114 &&
V_112 >= ( V_118 - V_113 ) / 2 ;
}
void F_57 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_15 V_16 , int V_119 )
{
struct V_48 * V_49 = & V_4 -> V_50 ;
struct V_17 * V_18 = V_49 -> V_120 ;
F_18 ( F_1 ( V_2 , V_4 ,
V_16 == V_31 ? V_30 : V_89 , 1 ) ) ;
F_58 ( V_49 -> V_56 == V_121 , L_8 ,
V_49 , V_49 -> V_56 ) ;
F_3 ( V_49 -> V_64 & V_122 ) ;
F_3 ( V_49 -> V_64 & V_103 ) ;
V_49 -> V_57 = V_16 == V_31 ? V_123 : V_124 ;
V_49 -> V_62 = V_4 -> V_100 ;
V_49 -> V_63 = V_4 -> V_101 - V_4 -> V_100 ;
V_49 -> V_65 = V_119 | V_125 ;
if ( F_56 ( V_49 -> V_67 ) )
V_49 -> V_65 |= V_126 ;
if ( ! F_59 ( F_32 ( V_18 ) ) &&
F_60 ( V_127 ) ) {
V_49 -> V_65 |= V_128 ;
V_49 -> V_57 |= V_128 ;
}
V_4 -> V_45 = F_30 () ;
F_2 ( V_4 , L_9 ) ;
F_9 ( V_2 , V_4 , V_16 ) ;
}
static int F_61 ( struct V_51 * V_52 )
{
struct V_129 * V_130 = V_52 -> V_131 ;
int V_132 = F_33 ( & V_52 -> V_133 ) ;
unsigned long V_134 ;
V_134 = V_130 -> V_135 / F_33 ( & V_130 -> V_136 ) ;
if ( F_33 ( V_52 -> V_137 ) < V_130 -> V_135 >> 4 ) {
if ( V_132 >= V_134 )
return V_138 ;
else if ( V_132 >= V_134 / 2 )
return V_139 ;
} else if ( V_132 >= V_134 * 2 ) {
return V_139 ;
}
return 0 ;
}
int F_62 ( const struct V_1 * V_2 , void * V_140 )
{
struct V_51 * V_52 = V_140 ;
F_35 ( V_141 , L_10 , V_52 ) ;
if ( F_61 ( V_52 ) )
F_63 ( V_2 , V_52 , V_138 , true ) ;
return 0 ;
}
void F_64 ( struct V_51 * V_52 , struct V_43 * V_142 )
{
F_65 ( V_143 ) ;
struct V_48 * V_49 ;
int V_144 = 0 ;
F_66 (oap, plist, oap_pending_item) {
struct V_3 * V_4 = F_67 ( V_49 ) ;
if ( ! V_4 -> V_145 )
continue;
++ V_144 ;
F_3 ( F_28 ( & V_4 -> V_111 ) ) ;
F_14 ( & V_4 -> V_111 , & V_143 ) ;
}
if ( V_144 > 0 ) {
F_13 ( & V_52 -> V_146 ) ;
F_68 ( & V_143 , & V_52 -> V_147 ) ;
F_69 ( V_144 , & V_52 -> V_148 ) ;
F_70 ( V_144 , & V_52 -> V_133 ) ;
F_15 ( & V_52 -> V_146 ) ;
if ( F_61 ( V_52 ) )
( void ) F_71 ( V_52 -> V_149 ) ;
}
}
static void F_72 ( struct V_51 * V_52 , struct V_3 * V_4 )
{
F_3 ( F_33 ( & V_52 -> V_133 ) > 0 ) ;
F_38 ( & V_4 -> V_111 ) ;
F_73 ( & V_52 -> V_133 ) ;
}
static void F_39 ( struct V_51 * V_52 , struct V_3 * V_4 )
{
if ( V_4 -> V_145 ) {
F_13 ( & V_52 -> V_146 ) ;
if ( ! F_28 ( & V_4 -> V_111 ) ) {
F_72 ( V_52 , V_4 ) ;
} else {
F_3 ( F_33 ( & V_52 -> V_148 ) > 0 ) ;
F_73 ( & V_52 -> V_148 ) ;
}
F_15 ( & V_52 -> V_146 ) ;
F_74 ( V_52 -> V_137 ) ;
if ( ! F_75 () )
( void ) F_71 ( V_52 -> V_149 ) ;
F_76 ( & V_150 ) ;
} else {
F_3 ( F_28 ( & V_4 -> V_111 ) ) ;
}
}
static void F_11 ( struct V_51 * V_52 , struct V_3 * V_4 )
{
if ( V_4 -> V_145 && ! F_28 ( & V_4 -> V_111 ) ) {
F_13 ( & V_52 -> V_146 ) ;
F_72 ( V_52 , V_4 ) ;
F_15 ( & V_52 -> V_146 ) ;
F_74 ( & V_52 -> V_148 ) ;
}
}
static void F_77 ( const struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_9 * * V_151 , int V_38 )
{
int V_152 ;
for ( V_152 = 0 ; V_152 < V_38 ; V_152 ++ ) {
struct V_9 * V_10 = V_151 [ V_152 ] ;
F_3 ( F_78 ( V_10 , V_28 ) ) ;
F_79 ( V_2 , V_28 , V_10 ) ;
F_80 ( V_2 , V_28 , V_10 ) ;
F_8 ( V_2 , V_10 ) ;
V_151 [ V_152 ] = NULL ;
}
}
int F_63 ( const struct V_1 * V_2 , struct V_51 * V_52 ,
int V_153 , bool V_154 )
{
struct V_27 * V_28 ;
struct V_33 * V_155 = NULL ;
struct V_9 * * V_151 ;
struct V_3 * V_4 ;
struct V_3 * V_156 ;
int V_157 = 0 ;
int V_158 = 0 ;
int V_104 = 0 ;
int V_87 = 0 ;
F_3 ( F_33 ( & V_52 -> V_133 ) >= 0 ) ;
if ( F_33 ( & V_52 -> V_133 ) == 0 || V_153 <= 0 )
return 0 ;
if ( ! V_154 ) {
if ( F_33 ( & V_52 -> V_159 ) > 0 )
return - V_160 ;
if ( F_81 ( & V_52 -> V_159 ) > 1 ) {
F_73 ( & V_52 -> V_159 ) ;
return - V_160 ;
}
} else {
F_74 ( & V_52 -> V_159 ) ;
}
V_151 = (struct V_9 * * ) F_82 ( V_2 ) -> V_161 ;
V_28 = & F_82 ( V_2 ) -> V_162 ;
F_13 ( & V_52 -> V_146 ) ;
V_157 = F_83 ( V_153 << 1 , F_33 ( & V_52 -> V_133 ) ) ;
F_84 (opg, temp, &cli->cl_lru_list, ops_lru) {
struct V_9 * V_10 ;
bool V_163 = false ;
if ( -- V_157 < 0 )
break;
V_10 = V_4 -> V_11 . V_12 ;
if ( F_85 ( V_10 ) ) {
F_86 ( & V_4 -> V_111 , & V_52 -> V_147 ) ;
continue;
}
F_3 ( V_10 -> V_164 ) ;
if ( V_155 != V_10 -> V_164 ) {
struct V_33 * V_165 = V_10 -> V_164 ;
F_87 ( V_165 ) ;
F_15 ( & V_52 -> V_146 ) ;
if ( V_155 ) {
F_77 ( V_2 , V_28 , V_151 , V_104 ) ;
V_104 = 0 ;
F_88 ( V_2 , V_28 ) ;
F_89 ( V_2 , V_155 ) ;
V_155 = NULL ;
}
V_155 = V_165 ;
V_28 -> V_166 = V_155 ;
V_28 -> V_167 = 1 ;
V_87 = F_90 ( V_2 , V_28 , V_168 , V_155 ) ;
F_13 ( & V_52 -> V_146 ) ;
if ( V_87 != 0 )
break;
++ V_157 ;
continue;
}
if ( F_91 ( V_2 , V_28 , V_10 ) == 0 ) {
if ( ! F_85 ( V_10 ) ) {
F_72 ( V_52 , V_4 ) ;
V_4 -> V_145 = 0 ;
F_4 ( V_10 ) ;
V_163 = true ;
} else {
F_80 ( V_2 , V_28 , V_10 ) ;
}
}
if ( ! V_163 ) {
F_86 ( & V_4 -> V_111 , & V_52 -> V_147 ) ;
continue;
}
V_151 [ V_104 ++ ] = V_10 ;
if ( F_92 ( V_104 == V_169 ) ) {
F_15 ( & V_52 -> V_146 ) ;
F_77 ( V_2 , V_28 , V_151 , V_104 ) ;
V_104 = 0 ;
F_13 ( & V_52 -> V_146 ) ;
}
if ( ++ V_158 >= V_153 )
break;
}
F_15 ( & V_52 -> V_146 ) ;
if ( V_155 ) {
F_77 ( V_2 , V_28 , V_151 , V_104 ) ;
F_88 ( V_2 , V_28 ) ;
F_89 ( V_2 , V_155 ) ;
}
F_73 ( & V_52 -> V_159 ) ;
if ( V_158 > 0 ) {
F_70 ( V_158 , V_52 -> V_137 ) ;
F_93 ( & V_150 ) ;
}
return V_158 > 0 ? V_158 : V_87 ;
}
static inline int F_94 ( struct V_51 * V_52 )
{
return F_83 ( F_33 ( & V_52 -> V_133 ) >> 1 , V_138 ) ;
}
int F_95 ( struct V_51 * V_52 )
{
struct V_170 V_171 ;
struct V_1 * V_2 ;
struct V_129 * V_130 = V_52 -> V_131 ;
int V_172 ;
int V_87 = 0 ;
F_3 ( V_130 ) ;
V_2 = F_96 ( & V_171 ) ;
if ( F_97 ( V_2 ) )
return 0 ;
V_87 = F_63 ( V_2 , V_52 , F_61 ( V_52 ) , false ) ;
if ( V_87 != 0 ) {
if ( V_87 == - V_160 )
V_87 = 0 ;
F_35 ( V_141 , L_11 ,
V_52 -> V_173 -> V_174 -> V_175 , V_87 , V_52 ) ;
goto V_176;
}
F_35 ( V_141 , L_12 ,
V_52 -> V_173 -> V_174 -> V_175 , V_52 ,
F_33 ( & V_52 -> V_133 ) ,
F_33 ( & V_52 -> V_148 ) ) ;
F_13 ( & V_130 -> V_177 ) ;
F_3 ( ! F_28 ( & V_130 -> V_178 ) ) ;
V_130 -> V_179 ++ ;
F_86 ( & V_52 -> V_180 , & V_130 -> V_178 ) ;
V_172 = F_33 ( & V_130 -> V_136 ) ;
while ( -- V_172 > 0 && ! F_28 ( & V_130 -> V_178 ) ) {
V_52 = F_98 ( V_130 -> V_178 . V_181 , struct V_51 ,
V_180 ) ;
F_35 ( V_141 , L_13 ,
V_52 -> V_173 -> V_174 -> V_175 , V_52 ,
F_33 ( & V_52 -> V_133 ) ,
F_33 ( & V_52 -> V_148 ) ) ;
F_86 ( & V_52 -> V_180 , & V_130 -> V_178 ) ;
if ( F_61 ( V_52 ) > 0 ) {
F_15 ( & V_130 -> V_177 ) ;
V_87 = F_63 ( V_2 , V_52 , F_61 ( V_52 ) ,
true ) ;
F_13 ( & V_130 -> V_177 ) ;
if ( V_87 != 0 )
break;
}
}
F_15 ( & V_130 -> V_177 ) ;
V_176:
F_99 ( & V_171 , V_2 ) ;
F_35 ( V_141 , L_14 ,
V_52 -> V_173 -> V_174 -> V_175 , V_52 , V_87 ) ;
return V_87 ;
}
static int F_54 ( const struct V_1 * V_2 , struct V_17 * V_18 ,
struct V_3 * V_4 )
{
struct V_182 V_183 = F_100 ( V_184 , NULL ) ;
struct V_108 * V_109 = F_50 ( V_2 ) ;
struct V_51 * V_52 = F_12 ( V_18 ) ;
int V_87 = 0 ;
if ( ! V_52 -> V_131 )
return 0 ;
if ( V_109 -> V_185 > 0 ) {
-- V_109 -> V_185 ;
goto V_176;
}
F_3 ( F_33 ( V_52 -> V_137 ) >= 0 ) ;
while ( ! F_101 ( V_52 -> V_137 , - 1 , 0 ) ) {
V_87 = F_95 ( V_52 ) ;
if ( V_87 < 0 )
break;
if ( V_87 > 0 )
continue;
F_102 () ;
V_87 = F_103 ( V_150 ,
F_33 ( V_52 -> V_137 ) > 0 ,
& V_183 ) ;
if ( V_87 < 0 )
break;
}
V_176:
if ( V_87 >= 0 ) {
F_74 ( & V_52 -> V_148 ) ;
V_4 -> V_145 = 1 ;
V_87 = 0 ;
}
return V_87 ;
}
