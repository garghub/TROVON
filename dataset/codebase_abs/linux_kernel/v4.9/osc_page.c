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
void F_54 ( const struct V_10 * V_11 , struct V_1 * V_2 ,
enum V_12 V_13 , int V_106 )
{
struct V_44 * V_45 = & V_2 -> V_46 ;
F_55 ( V_45 -> V_52 == V_107 , L_8 ,
V_45 , V_45 -> V_52 ) ;
F_2 ( V_45 -> V_60 & V_108 ) ;
F_2 ( V_45 -> V_60 & V_97 ) ;
V_45 -> V_53 = V_13 == V_27 ? V_109 : V_110 ;
V_45 -> V_58 = V_2 -> V_94 ;
V_45 -> V_59 = V_2 -> V_95 - V_2 -> V_94 ;
V_45 -> V_61 = V_106 | V_111 ;
if ( F_56 ( V_112 ) ) {
V_45 -> V_61 |= V_113 ;
V_45 -> V_53 |= V_113 ;
}
V_2 -> V_41 = F_28 () ;
F_1 ( V_2 , L_9 ) ;
F_8 ( V_11 , V_2 , V_13 ) ;
}
static int F_57 ( struct V_47 * V_48 )
{
struct V_114 * V_115 = V_48 -> V_116 ;
long V_117 = F_58 ( & V_48 -> V_118 ) ;
unsigned long V_119 ;
V_119 = V_115 -> V_120 / ( F_31 ( & V_115 -> V_121 ) - 2 ) ;
if ( F_58 ( V_48 -> V_122 ) < V_115 -> V_120 >> 4 ) {
if ( V_117 >= V_119 )
return V_123 ;
else if ( V_117 >= V_119 / 2 )
return V_124 ;
} else if ( V_117 >= V_119 * 2 ) {
return V_124 ;
}
return 0 ;
}
int F_59 ( const struct V_10 * V_11 , void * V_125 )
{
struct V_47 * V_48 = V_125 ;
F_33 ( V_126 , L_10 , V_48 ) ;
if ( F_57 ( V_48 ) )
F_60 ( V_11 , V_48 , V_123 , true ) ;
return 0 ;
}
void F_61 ( struct V_47 * V_48 , struct V_39 * V_127 )
{
F_62 ( V_128 ) ;
struct V_44 * V_45 ;
long V_129 = 0 ;
F_63 (oap, plist, oap_pending_item) {
struct V_1 * V_2 = F_64 ( V_45 ) ;
if ( ! V_2 -> V_130 )
continue;
++ V_129 ;
F_2 ( F_26 ( & V_2 -> V_105 ) ) ;
F_13 ( & V_2 -> V_105 , & V_128 ) ;
}
if ( V_129 > 0 ) {
F_12 ( & V_48 -> V_131 ) ;
F_65 ( & V_128 , & V_48 -> V_132 ) ;
F_66 ( V_129 , & V_48 -> V_133 ) ;
F_67 ( V_129 , & V_48 -> V_118 ) ;
F_14 ( & V_48 -> V_131 ) ;
if ( F_57 ( V_48 ) )
( void ) F_68 ( V_48 -> V_134 ) ;
}
}
static void F_69 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
F_2 ( F_58 ( & V_48 -> V_118 ) > 0 ) ;
F_36 ( & V_2 -> V_105 ) ;
F_70 ( & V_48 -> V_118 ) ;
}
static void F_37 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_2 -> V_130 ) {
F_12 ( & V_48 -> V_131 ) ;
if ( ! F_26 ( & V_2 -> V_105 ) ) {
F_69 ( V_48 , V_2 ) ;
} else {
F_2 ( F_58 ( & V_48 -> V_133 ) > 0 ) ;
F_70 ( & V_48 -> V_133 ) ;
}
F_14 ( & V_48 -> V_131 ) ;
F_71 ( V_48 -> V_122 ) ;
if ( ! F_72 () )
( void ) F_68 ( V_48 -> V_134 ) ;
F_73 ( & V_135 ) ;
} else {
F_2 ( F_26 ( & V_2 -> V_105 ) ) ;
}
}
static void F_10 ( struct V_47 * V_48 , struct V_1 * V_2 )
{
if ( V_2 -> V_130 && ! F_26 ( & V_2 -> V_105 ) ) {
F_12 ( & V_48 -> V_131 ) ;
F_69 ( V_48 , V_2 ) ;
F_14 ( & V_48 -> V_131 ) ;
F_71 ( & V_48 -> V_133 ) ;
}
}
static void F_74 ( const struct V_10 * V_11 , struct V_24 * V_25 ,
struct V_4 * * V_136 , int V_34 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_34 ; V_137 ++ ) {
struct V_4 * V_5 = V_136 [ V_137 ] ;
F_2 ( F_75 ( V_5 , V_25 ) ) ;
F_76 ( V_11 , V_25 , V_5 ) ;
F_77 ( V_11 , V_25 , V_5 ) ;
F_7 ( V_11 , V_5 ) ;
V_136 [ V_137 ] = NULL ;
}
}
static inline bool F_78 ( struct V_47 * V_48 , struct V_4 * V_5 )
{
if ( F_79 ( V_5 ) )
return true ;
if ( V_48 -> V_116 -> V_138 ) {
struct V_5 * V_139 = F_80 ( V_5 ) ;
if ( F_81 ( V_139 ) - F_82 ( V_139 ) > 2 )
return true ;
}
return false ;
}
long F_60 ( const struct V_10 * V_11 , struct V_47 * V_48 ,
long V_140 , bool V_141 )
{
struct V_24 * V_25 ;
struct V_29 * V_142 = NULL ;
struct V_4 * * V_136 ;
struct V_1 * V_2 ;
struct V_1 * V_143 ;
int V_144 = 0 ;
long V_145 = 0 ;
int V_98 = 0 ;
int V_83 = 0 ;
F_2 ( F_58 ( & V_48 -> V_118 ) >= 0 ) ;
if ( F_58 ( & V_48 -> V_118 ) == 0 || V_140 <= 0 )
return 0 ;
if ( ! V_141 ) {
if ( F_31 ( & V_48 -> V_146 ) > 0 )
return - V_147 ;
if ( F_83 ( & V_48 -> V_146 ) > 1 ) {
F_84 ( & V_48 -> V_146 ) ;
return - V_147 ;
}
} else {
F_85 ( & V_48 -> V_146 ) ;
}
V_136 = (struct V_4 * * ) F_86 ( V_11 ) -> V_148 ;
V_25 = & F_86 ( V_11 ) -> V_149 ;
F_12 ( & V_48 -> V_131 ) ;
V_144 = F_87 ( V_140 << 1 , F_58 ( & V_48 -> V_118 ) ) ;
F_88 (opg, temp, &cli->cl_lru_list, ops_lru) {
struct V_4 * V_5 ;
bool V_150 = false ;
if ( -- V_144 < 0 )
break;
V_5 = V_2 -> V_6 . V_7 ;
if ( F_78 ( V_48 , V_5 ) ) {
F_89 ( & V_2 -> V_105 , & V_48 -> V_132 ) ;
continue;
}
F_2 ( V_5 -> V_151 ) ;
if ( V_142 != V_5 -> V_151 ) {
struct V_29 * V_152 = V_5 -> V_151 ;
F_90 ( V_152 ) ;
F_14 ( & V_48 -> V_131 ) ;
if ( V_142 ) {
F_74 ( V_11 , V_25 , V_136 , V_98 ) ;
V_98 = 0 ;
F_91 ( V_11 , V_25 ) ;
F_92 ( V_11 , V_142 ) ;
V_142 = NULL ;
}
V_142 = V_152 ;
V_25 -> V_153 = V_142 ;
V_25 -> V_154 = 1 ;
V_83 = F_93 ( V_11 , V_25 , V_155 , V_142 ) ;
F_12 ( & V_48 -> V_131 ) ;
if ( V_83 != 0 )
break;
++ V_144 ;
continue;
}
if ( F_94 ( V_11 , V_25 , V_5 ) == 0 ) {
if ( ! F_78 ( V_48 , V_5 ) ) {
F_69 ( V_48 , V_2 ) ;
V_2 -> V_130 = 0 ;
F_3 ( V_5 ) ;
V_150 = true ;
} else {
F_77 ( V_11 , V_25 , V_5 ) ;
}
}
if ( ! V_150 ) {
F_89 ( & V_2 -> V_105 , & V_48 -> V_132 ) ;
continue;
}
V_136 [ V_98 ++ ] = V_5 ;
if ( F_95 ( V_98 == V_156 ) ) {
F_14 ( & V_48 -> V_131 ) ;
F_74 ( V_11 , V_25 , V_136 , V_98 ) ;
V_98 = 0 ;
F_12 ( & V_48 -> V_131 ) ;
}
if ( ++ V_145 >= V_140 )
break;
}
F_14 ( & V_48 -> V_131 ) ;
if ( V_142 ) {
F_74 ( V_11 , V_25 , V_136 , V_98 ) ;
F_91 ( V_11 , V_25 ) ;
F_92 ( V_11 , V_142 ) ;
}
F_84 ( & V_48 -> V_146 ) ;
if ( V_145 > 0 ) {
F_67 ( V_145 , V_48 -> V_122 ) ;
F_96 ( & V_135 ) ;
}
return V_145 > 0 ? V_145 : V_83 ;
}
long F_97 ( struct V_47 * V_48 )
{
struct V_157 V_158 ;
struct V_10 * V_11 ;
struct V_114 * V_115 = V_48 -> V_116 ;
int V_159 ;
long V_83 = 0 ;
F_2 ( V_115 ) ;
V_11 = F_98 ( & V_158 ) ;
if ( F_99 ( V_11 ) )
return 0 ;
V_83 = F_60 ( V_11 , V_48 , F_57 ( V_48 ) , false ) ;
if ( V_83 != 0 ) {
if ( V_83 == - V_147 )
V_83 = 0 ;
F_33 ( V_126 , L_11 ,
V_48 -> V_160 -> V_161 -> V_162 , V_83 , V_48 ) ;
goto V_163;
}
F_33 ( V_126 , L_12 ,
V_48 -> V_160 -> V_161 -> V_162 , V_48 ,
F_58 ( & V_48 -> V_118 ) ,
F_58 ( & V_48 -> V_133 ) ) ;
F_12 ( & V_115 -> V_164 ) ;
F_2 ( ! F_26 ( & V_115 -> V_165 ) ) ;
V_115 -> V_166 ++ ;
F_89 ( & V_48 -> V_167 , & V_115 -> V_165 ) ;
V_159 = F_31 ( & V_115 -> V_121 ) - 2 ;
while ( -- V_159 > 0 && ! F_26 ( & V_115 -> V_165 ) ) {
V_48 = F_100 ( V_115 -> V_165 . V_168 , struct V_47 ,
V_167 ) ;
F_33 ( V_126 , L_13 ,
V_48 -> V_160 -> V_161 -> V_162 , V_48 ,
F_58 ( & V_48 -> V_118 ) ,
F_58 ( & V_48 -> V_133 ) ) ;
F_89 ( & V_48 -> V_167 , & V_115 -> V_165 ) ;
if ( F_57 ( V_48 ) > 0 ) {
F_14 ( & V_115 -> V_164 ) ;
V_83 = F_60 ( V_11 , V_48 , F_57 ( V_48 ) ,
true ) ;
F_12 ( & V_115 -> V_164 ) ;
if ( V_83 != 0 )
break;
}
}
F_14 ( & V_115 -> V_164 ) ;
V_163:
F_101 ( & V_158 , V_11 ) ;
F_33 ( V_126 , L_14 ,
V_48 -> V_160 -> V_161 -> V_162 , V_48 , V_83 ) ;
return V_83 ;
}
static int F_52 ( const struct V_10 * V_11 , struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_169 V_170 = F_102 ( V_171 , NULL ) ;
struct V_102 * V_103 = F_48 ( V_11 ) ;
struct V_47 * V_48 = F_11 ( V_15 ) ;
int V_83 = 0 ;
if ( ! V_48 -> V_116 )
return 0 ;
if ( V_103 -> V_172 > 0 ) {
-- V_103 -> V_172 ;
goto V_163;
}
F_2 ( F_58 ( V_48 -> V_122 ) >= 0 ) ;
while ( ! F_103 ( V_48 -> V_122 , - 1 , 0 ) ) {
V_83 = F_97 ( V_48 ) ;
if ( V_83 < 0 )
break;
if ( V_83 > 0 )
continue;
F_104 () ;
V_83 = F_105 ( V_135 ,
F_58 ( V_48 -> V_122 ) > 0 ,
& V_170 ) ;
if ( V_83 < 0 )
break;
}
V_163:
if ( V_83 >= 0 ) {
F_71 ( & V_48 -> V_133 ) ;
V_2 -> V_130 = 1 ;
V_83 = 0 ;
}
return V_83 ;
}
static inline void F_106 ( struct V_173 * V_174 ,
int V_175 )
{
int F_81 = V_174 -> V_176 ;
T_4 * V_177 = NULL ;
int V_145 = 0 ;
int V_137 ;
for ( V_137 = 0 ; V_137 < F_81 ; V_137 ++ ) {
T_4 * V_178 = F_107 ( V_174 -> V_179 [ V_137 ] . V_180 ) ;
if ( F_108 ( V_178 == V_177 ) ) {
++ V_145 ;
continue;
}
if ( V_145 > 0 ) {
F_109 ( V_178 , V_181 ,
V_175 * V_145 ) ;
V_145 = 0 ;
}
V_177 = V_178 ;
++ V_145 ;
}
if ( V_145 > 0 )
F_109 ( V_177 , V_181 , V_175 * V_145 ) ;
}
static inline void F_110 ( struct V_173 * V_174 )
{
F_106 ( V_174 , 1 ) ;
}
static inline void F_111 ( struct V_173 * V_174 )
{
F_106 ( V_174 , - 1 ) ;
}
void F_112 ( struct V_182 * V_183 )
{
struct V_47 * V_48 = & V_183 -> V_184 -> V_161 -> V_50 . V_48 ;
struct V_173 * V_174 = V_183 -> V_185 ;
int F_81 = V_174 -> V_176 ;
long V_186 ;
F_2 ( F_81 >= 0 ) ;
F_111 ( V_174 ) ;
V_186 = F_113 ( F_81 ,
& V_48 -> V_187 ) ;
F_2 ( V_186 >= 0 ) ;
V_186 = F_113 ( F_81 ,
& V_48 -> V_116 -> V_188 ) ;
F_2 ( V_186 >= 0 ) ;
if ( ! V_186 )
F_96 ( & V_48 -> V_116 -> V_189 ) ;
if ( F_57 ( V_48 ) )
( void ) F_68 ( V_48 -> V_134 ) ;
}
void F_114 ( struct V_182 * V_183 )
{
struct V_47 * V_48 = & V_183 -> V_184 -> V_161 -> V_50 . V_48 ;
struct V_173 * V_174 = V_183 -> V_185 ;
long F_81 = V_174 -> V_176 ;
if ( ! V_48 -> V_116 || ! V_48 -> V_116 -> V_138 )
return;
F_110 ( V_174 ) ;
F_67 ( F_81 , & V_48 -> V_187 ) ;
F_67 ( F_81 , & V_48 -> V_116 -> V_188 ) ;
F_12 ( & V_183 -> V_190 ) ;
if ( F_95 ( V_183 -> V_191 ) ) {
F_14 ( & V_183 -> V_190 ) ;
F_112 ( V_183 ) ;
} else {
V_183 -> V_192 = 1 ;
F_14 ( & V_183 -> V_190 ) ;
}
}
bool F_115 ( struct V_47 * V_48 )
{
long V_193 , V_194 ;
if ( ! V_48 -> V_116 || ! V_48 -> V_116 -> V_138 )
return false ;
V_194 = F_58 ( & V_48 -> V_187 ) ;
V_193 = F_58 ( & V_48 -> V_116 -> V_188 ) ;
F_33 ( V_126 ,
L_15 ,
V_48 -> V_160 -> V_161 -> V_162 , V_48 ,
V_193 , V_194 ) ;
return V_193 > V_48 -> V_116 -> V_120 >> 2 &&
V_194 > V_48 -> V_195 *
V_48 -> V_67 ;
}
