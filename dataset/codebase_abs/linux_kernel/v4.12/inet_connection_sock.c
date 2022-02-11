static int F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 ,
T_1 V_4 , T_1 V_5 ,
bool V_6 , bool V_7 ,
bool V_8 )
{
int V_9 = F_2 ( V_2 ) ;
int V_10 = V_3 ? F_2 ( V_3 ) : V_11 ;
if ( V_9 == V_11 && V_10 == V_11 ) {
if ( ! V_7 ) {
if ( V_4 == V_5 )
return 1 ;
if ( ! V_4 || ! V_5 )
return V_8 ;
}
return 0 ;
}
if ( V_9 == V_12 && V_10 == V_12 )
return 1 ;
if ( V_10 == V_12 && V_8 &&
! ( V_7 && V_9 == V_11 ) )
return 1 ;
if ( V_9 == V_12 && V_8 &&
! ( V_6 && V_10 == V_11 ) )
return 1 ;
if ( V_3 &&
F_3 ( V_2 , V_3 ) )
return 1 ;
return 0 ;
}
static int F_4 ( T_1 V_4 , T_1 V_5 ,
bool V_7 , bool V_8 )
{
if ( ! V_7 ) {
if ( V_4 == V_5 )
return 1 ;
if ( ! V_4 || ! V_5 )
return V_8 ;
}
return 0 ;
}
int F_5 ( const struct V_13 * V_14 , const struct V_13 * V_15 ,
bool V_8 )
{
#if F_6 ( V_16 )
if ( V_14 -> V_17 == V_18 )
return F_1 ( & V_14 -> V_19 ,
F_7 ( V_15 ) ,
V_14 -> V_20 ,
V_15 -> V_20 ,
F_8 ( V_14 ) ,
F_8 ( V_15 ) ,
V_8 ) ;
#endif
return F_4 ( V_14 -> V_20 , V_15 -> V_20 ,
F_8 ( V_15 ) , V_8 ) ;
}
void F_9 ( struct V_21 * V_21 , int * V_22 , int * V_23 )
{
unsigned int V_24 ;
do {
V_24 = F_10 ( & V_21 -> V_25 . V_26 . V_27 ) ;
* V_22 = V_21 -> V_25 . V_26 . V_28 [ 0 ] ;
* V_23 = V_21 -> V_25 . V_26 . V_28 [ 1 ] ;
} while ( F_11 ( & V_21 -> V_25 . V_26 . V_27 , V_24 ) );
}
static int F_12 ( const struct V_13 * V_14 ,
const struct V_29 * V_30 ,
bool V_31 , bool V_32 )
{
struct V_13 * V_15 ;
bool V_33 = V_14 -> V_34 ;
bool V_35 = ! ! V_14 -> V_36 && V_32 ;
T_2 V_37 = F_13 ( (struct V_13 * ) V_14 ) ;
F_14 (sk2, &tb->owners) {
if ( V_14 != V_15 &&
( ! V_14 -> V_38 ||
! V_15 -> V_38 ||
V_14 -> V_38 == V_15 -> V_38 ) ) {
if ( ( ! V_33 || ! V_15 -> V_34 ||
V_15 -> V_39 == V_40 ) &&
( ! V_35 || ! V_15 -> V_36 ||
F_15 ( V_14 -> V_41 ) ||
( V_15 -> V_39 != V_42 &&
! F_16 ( V_37 , F_13 ( V_15 ) ) ) ) ) {
if ( F_5 ( V_14 , V_15 , true ) )
break;
}
if ( ! V_31 && V_33 && V_15 -> V_34 &&
V_15 -> V_39 != V_40 ) {
if ( F_5 ( V_14 , V_15 , true ) )
break;
}
}
}
return V_15 != NULL ;
}
static struct V_43 *
F_17 ( struct V_13 * V_14 , struct V_29 * * V_44 , int * V_45 )
{
struct V_46 * V_47 = V_14 -> V_48 -> V_49 . V_50 ;
int V_51 = 0 ;
struct V_43 * V_52 ;
struct V_21 * V_21 = F_18 ( V_14 ) ;
int V_53 , V_22 , V_23 , V_54 ;
struct V_29 * V_30 ;
T_3 V_55 , V_56 ;
V_54 = ( V_14 -> V_34 == V_57 ) ? 1 : 0 ;
V_58:
F_9 ( V_21 , & V_22 , & V_23 ) ;
V_23 ++ ;
if ( V_23 - V_22 < 4 )
V_54 = 0 ;
if ( V_54 ) {
int V_59 = V_22 + ( ( ( V_23 - V_22 ) >> 2 ) << 1 ) ;
if ( V_54 == 1 )
V_23 = V_59 ;
else
V_22 = V_59 ;
}
V_55 = V_23 - V_22 ;
if ( F_19 ( V_55 > 1 ) )
V_55 &= ~ 1U ;
V_56 = F_20 () % V_55 ;
V_56 |= 1U ;
V_60:
V_51 = V_22 + V_56 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 += 2 , V_51 += 2 ) {
if ( F_21 ( V_51 >= V_23 ) )
V_51 -= V_55 ;
if ( F_22 ( V_21 , V_51 ) )
continue;
V_52 = & V_47 -> V_61 [ F_23 ( V_21 , V_51 ,
V_47 -> V_62 ) ] ;
F_24 ( & V_52 -> V_27 ) ;
F_25 (tb, &head->chain)
if ( F_26 ( F_27 ( V_30 ) , V_21 ) && V_30 -> V_51 == V_51 ) {
if ( ! F_12 ( V_14 , V_30 , false , false ) )
goto V_63;
goto V_64;
}
V_30 = NULL ;
goto V_63;
V_64:
F_28 ( & V_52 -> V_27 ) ;
F_29 () ;
}
V_56 -- ;
if ( ! ( V_56 & 1 ) )
goto V_60;
if ( V_54 == 1 ) {
V_54 = 2 ;
goto V_58;
}
return NULL ;
V_63:
* V_45 = V_51 ;
* V_44 = V_30 ;
return V_52 ;
}
static inline int F_30 ( struct V_29 * V_30 ,
struct V_13 * V_14 )
{
T_2 V_37 = F_13 ( V_14 ) ;
if ( V_30 -> V_65 <= 0 )
return 0 ;
if ( ! V_14 -> V_36 )
return 0 ;
if ( F_15 ( V_14 -> V_41 ) )
return 0 ;
if ( ! F_16 ( V_30 -> V_66 , V_37 ) )
return 0 ;
if ( V_30 -> V_65 == V_67 )
return 1 ;
#if F_6 ( V_16 )
if ( V_30 -> V_68 == V_18 )
return F_1 ( & V_30 -> V_69 ,
& V_14 -> V_19 ,
V_30 -> V_70 ,
V_14 -> V_20 ,
V_30 -> V_71 ,
F_8 ( V_14 ) , true ) ;
#endif
return F_4 ( V_30 -> V_70 , V_14 -> V_20 ,
F_8 ( V_14 ) , true ) ;
}
int F_31 ( struct V_13 * V_14 , unsigned short V_72 )
{
bool V_33 = V_14 -> V_34 && V_14 -> V_39 != V_40 ;
struct V_46 * V_47 = V_14 -> V_48 -> V_49 . V_50 ;
int V_73 = 1 , V_51 = V_72 ;
struct V_43 * V_52 ;
struct V_21 * V_21 = F_18 ( V_14 ) ;
struct V_29 * V_30 = NULL ;
T_2 V_37 = F_13 ( V_14 ) ;
if ( ! V_51 ) {
V_52 = F_17 ( V_14 , & V_30 , & V_51 ) ;
if ( ! V_52 )
return V_73 ;
if ( ! V_30 )
goto V_74;
goto V_63;
}
V_52 = & V_47 -> V_61 [ F_23 ( V_21 , V_51 ,
V_47 -> V_62 ) ] ;
F_24 ( & V_52 -> V_27 ) ;
F_25 (tb, &head->chain)
if ( F_26 ( F_27 ( V_30 ) , V_21 ) && V_30 -> V_51 == V_51 )
goto V_75;
V_74:
V_30 = F_32 ( V_47 -> V_76 ,
V_21 , V_52 , V_51 ) ;
if ( ! V_30 )
goto V_77;
V_75:
if ( ! F_33 ( & V_30 -> V_78 ) ) {
if ( V_14 -> V_34 == V_79 )
goto V_63;
if ( ( V_30 -> V_80 > 0 && V_33 ) ||
F_30 ( V_30 , V_14 ) )
goto V_63;
if ( F_12 ( V_14 , V_30 , true , true ) )
goto V_77;
}
V_63:
if ( ! F_33 ( & V_30 -> V_78 ) ) {
V_30 -> V_80 = V_33 ;
if ( V_14 -> V_36 ) {
V_30 -> V_65 = V_67 ;
V_30 -> V_66 = V_37 ;
V_30 -> V_70 = V_14 -> V_20 ;
V_30 -> V_71 = F_8 ( V_14 ) ;
#if F_6 ( V_16 )
V_30 -> V_69 = V_14 -> V_19 ;
#endif
} else {
V_30 -> V_65 = 0 ;
}
} else {
if ( ! V_33 )
V_30 -> V_80 = 0 ;
if ( V_14 -> V_36 ) {
if ( ! F_30 ( V_30 , V_14 ) ) {
V_30 -> V_65 = V_81 ;
V_30 -> V_66 = V_37 ;
V_30 -> V_70 = V_14 -> V_20 ;
V_30 -> V_71 = F_8 ( V_14 ) ;
#if F_6 ( V_16 )
V_30 -> V_69 = V_14 -> V_19 ;
#endif
}
} else {
V_30 -> V_65 = 0 ;
}
}
if ( ! F_34 ( V_14 ) -> V_82 )
F_35 ( V_14 , V_30 , V_51 ) ;
F_36 ( F_34 ( V_14 ) -> V_82 != V_30 ) ;
V_73 = 0 ;
V_77:
F_28 ( & V_52 -> V_27 ) ;
return V_73 ;
}
static int F_37 ( struct V_13 * V_14 , long V_83 )
{
struct V_84 * V_85 = F_34 ( V_14 ) ;
F_38 ( V_86 ) ;
int V_87 ;
for (; ; ) {
F_39 ( F_40 ( V_14 ) , & V_86 ,
V_88 ) ;
F_41 ( V_14 ) ;
if ( F_42 ( & V_85 -> V_89 ) )
V_83 = F_43 ( V_83 ) ;
F_44 () ;
F_45 ( V_14 ) ;
V_87 = 0 ;
if ( ! F_42 ( & V_85 -> V_89 ) )
break;
V_87 = - V_90 ;
if ( V_14 -> V_39 != V_40 )
break;
V_87 = F_46 ( V_83 ) ;
if ( F_47 ( V_91 ) )
break;
V_87 = - V_92 ;
if ( ! V_83 )
break;
}
F_48 ( F_40 ( V_14 ) , & V_86 ) ;
return V_87 ;
}
struct V_13 * F_49 ( struct V_13 * V_14 , int V_93 , int * V_87 , bool V_94 )
{
struct V_84 * V_85 = F_34 ( V_14 ) ;
struct V_95 * V_96 = & V_85 -> V_89 ;
struct V_97 * V_98 ;
struct V_13 * V_99 ;
int error ;
F_45 ( V_14 ) ;
error = - V_90 ;
if ( V_14 -> V_39 != V_40 )
goto V_100;
if ( F_42 ( V_96 ) ) {
long V_83 = F_50 ( V_14 , V_93 & V_101 ) ;
error = - V_92 ;
if ( ! V_83 )
goto V_100;
error = F_37 ( V_14 , V_83 ) ;
if ( error )
goto V_100;
}
V_98 = F_51 ( V_96 , V_14 ) ;
V_99 = V_98 -> V_14 ;
if ( V_14 -> V_102 == V_103 &&
F_52 ( V_98 ) -> V_104 ) {
F_24 ( & V_96 -> V_105 . V_27 ) ;
if ( F_52 ( V_98 ) -> V_104 ) {
V_98 -> V_14 = NULL ;
V_98 = NULL ;
}
F_28 ( & V_96 -> V_105 . V_27 ) ;
}
V_106:
F_41 ( V_14 ) ;
if ( V_98 )
F_53 ( V_98 ) ;
return V_99 ;
V_100:
V_99 = NULL ;
V_98 = NULL ;
* V_87 = error ;
goto V_106;
}
void F_54 ( struct V_13 * V_14 ,
void (* F_55)( unsigned long ) ,
void (* F_56)( unsigned long ) ,
void (* F_57)( unsigned long ) )
{
struct V_84 * V_85 = F_34 ( V_14 ) ;
F_58 ( & V_85 -> V_107 , F_55 ,
( unsigned long ) V_14 ) ;
F_58 ( & V_85 -> V_108 , F_56 ,
( unsigned long ) V_14 ) ;
F_58 ( & V_14 -> V_109 , F_57 , ( unsigned long ) V_14 ) ;
V_85 -> V_110 = V_85 -> V_111 . V_112 = 0 ;
}
void F_59 ( struct V_13 * V_14 )
{
struct V_84 * V_85 = F_34 ( V_14 ) ;
V_85 -> V_110 = V_85 -> V_111 . V_112 = V_85 -> V_111 . V_113 = 0 ;
F_60 ( V_14 , & V_85 -> V_107 ) ;
F_60 ( V_14 , & V_85 -> V_108 ) ;
F_60 ( V_14 , & V_14 -> V_109 ) ;
}
void F_61 ( struct V_13 * V_14 )
{
F_60 ( V_14 , & V_14 -> V_109 ) ;
}
void F_62 ( struct V_13 * V_14 , unsigned long V_114 )
{
F_63 ( V_14 , & V_14 -> V_109 , V_115 + V_114 ) ;
}
struct V_116 * F_64 ( const struct V_13 * V_14 ,
struct V_117 * V_118 ,
const struct V_97 * V_98 )
{
const struct V_119 * V_120 = F_65 ( V_98 ) ;
struct V_21 * V_21 = F_66 ( & V_120 -> V_121 ) ;
struct V_122 * V_123 = V_120 -> V_123 ;
struct V_124 * V_125 ;
F_67 ( V_118 , V_120 -> V_126 , V_120 -> V_127 ,
F_68 ( V_14 ) , V_128 ,
V_14 -> V_102 , F_69 ( V_14 ) ,
( V_123 && V_123 -> V_123 . V_129 ) ? V_123 -> V_123 . V_130 : V_120 -> V_131 ,
V_120 -> V_132 , V_120 -> V_133 ,
F_70 ( V_120 -> V_134 ) , V_14 -> V_135 ) ;
F_71 ( V_98 , F_72 ( V_118 ) ) ;
V_125 = F_73 ( V_21 , V_118 , V_14 ) ;
if ( F_74 ( V_125 ) )
goto V_136;
if ( V_123 && V_123 -> V_123 . V_137 && V_125 -> V_138 )
goto V_139;
return & V_125 -> V_140 ;
V_139:
F_75 ( V_125 ) ;
V_136:
F_76 ( V_21 , V_141 ) ;
return NULL ;
}
struct V_116 * F_77 ( const struct V_13 * V_14 ,
struct V_13 * V_99 ,
const struct V_97 * V_98 )
{
const struct V_119 * V_120 = F_65 ( V_98 ) ;
struct V_21 * V_21 = F_66 ( & V_120 -> V_121 ) ;
struct V_142 * V_143 = F_78 ( V_99 ) ;
struct V_122 * V_123 ;
struct V_117 * V_118 ;
struct V_124 * V_125 ;
V_118 = & V_143 -> V_144 . V_145 . V_146 . V_147 ;
F_79 () ;
V_123 = F_80 ( V_143 -> V_148 ) ;
F_67 ( V_118 , V_120 -> V_126 , V_120 -> V_127 ,
F_68 ( V_14 ) , V_128 ,
V_14 -> V_102 , F_69 ( V_14 ) ,
( V_123 && V_123 -> V_123 . V_129 ) ? V_123 -> V_123 . V_130 : V_120 -> V_131 ,
V_120 -> V_132 , V_120 -> V_133 ,
F_70 ( V_120 -> V_134 ) , V_14 -> V_135 ) ;
F_71 ( V_98 , F_72 ( V_118 ) ) ;
V_125 = F_73 ( V_21 , V_118 , V_14 ) ;
if ( F_74 ( V_125 ) )
goto V_136;
if ( V_123 && V_123 -> V_123 . V_137 && V_125 -> V_138 )
goto V_139;
F_81 () ;
return & V_125 -> V_140 ;
V_139:
F_75 ( V_125 ) ;
V_136:
F_81 () ;
F_76 ( V_21 , V_141 ) ;
return NULL ;
}
static inline void F_82 ( struct V_97 * V_98 , const int V_149 ,
const int V_150 ,
const T_4 V_151 ,
int * V_152 , int * V_153 )
{
if ( ! V_151 ) {
* V_152 = V_98 -> V_154 >= V_149 ;
* V_153 = 1 ;
return;
}
* V_152 = V_98 -> V_154 >= V_149 &&
( ! F_65 ( V_98 ) -> V_155 || V_98 -> V_154 >= V_150 ) ;
* V_153 = ! F_65 ( V_98 ) -> V_155 ||
V_98 -> V_154 >= V_151 - 1 ;
}
int F_83 ( const struct V_13 * V_156 , struct V_97 * V_98 )
{
int V_87 = V_98 -> V_157 -> V_158 ( V_156 , V_98 ) ;
if ( ! V_87 )
V_98 -> V_159 ++ ;
return V_87 ;
}
static bool F_84 ( struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_46 * V_50 = F_85 ( V_98 ) -> V_48 -> V_49 . V_50 ;
bool V_160 = false ;
if ( F_86 ( F_85 ( V_98 ) ) ) {
T_5 * V_27 = F_87 ( V_50 , V_98 -> V_161 ) ;
F_88 ( V_27 ) ;
V_160 = F_89 ( F_85 ( V_98 ) ) ;
F_90 ( V_27 ) ;
}
if ( F_91 ( & V_98 -> V_162 ) && F_92 ( & V_98 -> V_162 ) )
F_53 ( V_98 ) ;
return V_160 ;
}
void F_93 ( struct V_13 * V_14 , struct V_97 * V_98 )
{
if ( F_84 ( & F_34 ( V_14 ) -> V_89 , V_98 ) ) {
F_94 ( & F_34 ( V_14 ) -> V_89 , V_98 ) ;
F_53 ( V_98 ) ;
}
}
void F_95 ( struct V_13 * V_14 , struct V_97 * V_98 )
{
F_93 ( V_14 , V_98 ) ;
F_53 ( V_98 ) ;
}
static void F_96 ( unsigned long V_163 )
{
struct V_97 * V_98 = (struct V_97 * ) V_163 ;
struct V_13 * V_164 = V_98 -> V_165 ;
struct V_21 * V_21 = F_18 ( V_164 ) ;
struct V_84 * V_85 = F_34 ( V_164 ) ;
struct V_95 * V_96 = & V_85 -> V_89 ;
int V_166 , V_152 = 0 , V_153 = 0 ;
int V_150 , V_149 ;
T_4 V_167 ;
if ( F_97 ( V_164 ) != V_40 )
goto V_168;
V_150 = V_85 -> V_169 ? : V_21 -> V_25 . V_170 ;
V_149 = V_150 ;
V_166 = F_98 ( V_96 ) ;
if ( ( V_166 << 1 ) > F_99 ( 8U , V_164 -> V_171 ) ) {
int V_172 = F_100 ( V_96 ) << 1 ;
while ( V_149 > 2 ) {
if ( V_166 < V_172 )
break;
V_149 -- ;
V_172 <<= 1 ;
}
}
V_167 = F_101 ( V_96 -> V_151 ) ;
if ( V_167 )
V_150 = V_167 ;
F_82 ( V_98 , V_149 , V_150 , V_167 ,
& V_152 , & V_153 ) ;
V_98 -> V_157 -> V_173 ( V_98 ) ;
if ( ! V_152 &&
( ! V_153 ||
! F_83 ( V_164 , V_98 ) ||
F_65 ( V_98 ) -> V_155 ) ) {
unsigned long V_83 ;
if ( V_98 -> V_154 ++ == 0 )
F_102 ( & V_96 -> V_172 ) ;
V_83 = F_103 ( V_174 << V_98 -> V_154 , V_175 ) ;
F_104 ( & V_98 -> V_162 , V_115 + V_83 ) ;
return;
}
V_168:
F_95 ( V_164 , V_98 ) ;
}
static void F_105 ( struct V_97 * V_98 ,
unsigned long V_176 )
{
V_98 -> V_159 = 0 ;
V_98 -> V_154 = 0 ;
V_98 -> V_14 = NULL ;
F_106 ( & V_98 -> V_162 , F_96 ,
( unsigned long ) V_98 ) ;
F_104 ( & V_98 -> V_162 , V_115 + V_176 ) ;
F_107 ( F_85 ( V_98 ) , NULL ) ;
F_108 () ;
F_109 ( & V_98 -> V_177 , 2 + 1 ) ;
}
void F_110 ( struct V_13 * V_14 , struct V_97 * V_98 ,
unsigned long V_176 )
{
F_105 ( V_98 , V_176 ) ;
F_111 ( V_14 ) ;
}
struct V_13 * F_112 ( const struct V_13 * V_14 ,
const struct V_97 * V_98 ,
const T_6 V_178 )
{
struct V_13 * V_99 = F_113 ( V_14 , V_178 ) ;
if ( V_99 ) {
struct V_84 * V_179 = F_34 ( V_99 ) ;
V_99 -> V_39 = V_180 ;
V_179 -> V_82 = NULL ;
F_78 ( V_99 ) -> V_181 = F_65 ( V_98 ) -> V_133 ;
F_78 ( V_99 ) -> V_182 = F_65 ( V_98 ) -> V_134 ;
F_78 ( V_99 ) -> V_183 = F_70 ( F_65 ( V_98 ) -> V_134 ) ;
V_99 -> V_184 = V_185 ;
F_114 ( V_99 , V_186 ) ;
F_78 ( V_99 ) -> V_187 = NULL ;
V_99 -> V_188 = F_65 ( V_98 ) -> V_127 ;
F_115 ( & V_99 -> V_189 ,
F_116 ( & F_65 ( V_98 ) -> V_190 ) ) ;
V_179 -> V_191 = 0 ;
V_179 -> V_192 = 0 ;
V_179 -> V_193 = 0 ;
memset ( & V_179 -> V_89 , 0 , sizeof( V_179 -> V_89 ) ) ;
F_117 ( V_99 , V_98 ) ;
}
return V_99 ;
}
void F_118 ( struct V_13 * V_14 )
{
F_36 ( V_14 -> V_39 != V_194 ) ;
F_36 ( ! F_119 ( V_14 , V_195 ) ) ;
F_36 ( ! F_120 ( V_14 ) ) ;
F_36 ( F_78 ( V_14 ) -> V_182 && ! F_34 ( V_14 ) -> V_82 ) ;
V_14 -> V_48 -> V_196 ( V_14 ) ;
F_121 ( V_14 ) ;
F_122 ( V_14 ) ;
F_123 ( V_14 ) ;
F_124 ( V_14 -> V_48 -> V_197 ) ;
F_125 ( V_14 ) ;
}
void F_126 ( struct V_13 * V_14 )
__releases( &sk->sk_lock.slock
int F_127 ( struct V_13 * V_14 , int V_198 )
{
struct V_84 * V_85 = F_34 ( V_14 ) ;
struct V_142 * V_199 = F_78 ( V_14 ) ;
int V_87 = - V_200 ;
F_128 ( & V_85 -> V_89 ) ;
V_14 -> V_171 = V_198 ;
V_14 -> V_201 = 0 ;
F_129 ( V_14 ) ;
F_130 ( V_14 , V_40 ) ;
if ( ! V_14 -> V_48 -> V_202 ( V_14 , V_199 -> V_182 ) ) {
V_199 -> V_183 = F_70 ( V_199 -> V_182 ) ;
F_131 ( V_14 ) ;
V_87 = V_14 -> V_48 -> V_203 ( V_14 ) ;
if ( F_19 ( ! V_87 ) )
return 0 ;
}
V_14 -> V_39 = V_194 ;
return V_87 ;
}
static void F_132 ( struct V_13 * V_14 , struct V_97 * V_98 ,
struct V_13 * V_204 )
{
V_14 -> V_48 -> V_205 ( V_204 , V_101 ) ;
F_133 ( V_204 ) ;
F_134 ( V_14 -> V_48 -> V_197 ) ;
if ( V_14 -> V_102 == V_103 && F_52 ( V_98 ) -> V_104 ) {
F_135 ( F_136 ( V_204 ) -> V_206 != V_98 ) ;
F_135 ( V_14 != V_98 -> V_165 ) ;
F_136 ( V_204 ) -> V_206 = NULL ;
}
F_118 ( V_204 ) ;
F_53 ( V_98 ) ;
}
struct V_13 * F_137 ( struct V_13 * V_14 ,
struct V_97 * V_98 ,
struct V_13 * V_204 )
{
struct V_95 * V_96 = & F_34 ( V_14 ) -> V_89 ;
F_88 ( & V_96 -> V_207 ) ;
if ( F_21 ( V_14 -> V_39 != V_40 ) ) {
F_132 ( V_14 , V_98 , V_204 ) ;
V_204 = NULL ;
} else {
V_98 -> V_14 = V_204 ;
V_98 -> V_208 = NULL ;
if ( V_96 -> V_209 == NULL )
V_96 -> V_209 = V_98 ;
else
V_96 -> V_210 -> V_208 = V_98 ;
V_96 -> V_210 = V_98 ;
F_138 ( V_14 ) ;
}
F_90 ( & V_96 -> V_207 ) ;
return V_204 ;
}
struct V_13 * F_139 ( struct V_13 * V_14 , struct V_13 * V_204 ,
struct V_97 * V_98 , bool V_211 )
{
if ( V_211 ) {
F_93 ( V_14 , V_98 ) ;
F_94 ( & F_34 ( V_14 ) -> V_89 , V_98 ) ;
if ( F_137 ( V_14 , V_98 , V_204 ) )
return V_204 ;
}
F_140 ( V_204 ) ;
F_125 ( V_204 ) ;
return NULL ;
}
void F_141 ( struct V_13 * V_14 )
{
struct V_84 * V_85 = F_34 ( V_14 ) ;
struct V_95 * V_96 = & V_85 -> V_89 ;
struct V_97 * V_212 , * V_98 ;
while ( ( V_98 = F_51 ( V_96 , V_14 ) ) != NULL ) {
struct V_13 * V_204 = V_98 -> V_14 ;
F_142 () ;
F_143 ( V_204 ) ;
F_36 ( F_144 ( V_204 ) ) ;
F_145 ( V_204 ) ;
F_132 ( V_14 , V_98 , V_204 ) ;
F_140 ( V_204 ) ;
F_146 () ;
F_125 ( V_204 ) ;
F_29 () ;
}
if ( V_96 -> V_105 . V_213 ) {
F_24 ( & V_96 -> V_105 . V_27 ) ;
V_98 = V_96 -> V_105 . V_213 ;
V_96 -> V_105 . V_213 = NULL ;
F_28 ( & V_96 -> V_105 . V_27 ) ;
while ( V_98 != NULL ) {
V_212 = V_98 -> V_208 ;
F_53 ( V_98 ) ;
V_98 = V_212 ;
}
}
F_147 ( V_14 -> V_201 ) ;
}
void F_148 ( struct V_13 * V_14 , struct V_214 * V_215 )
{
struct V_216 * sin = (struct V_216 * ) V_215 ;
const struct V_142 * V_199 = F_78 ( V_14 ) ;
sin -> V_217 = V_218 ;
sin -> V_219 . V_220 = V_199 -> V_221 ;
sin -> V_222 = V_199 -> V_181 ;
}
int F_149 ( struct V_13 * V_14 , int V_223 , int V_224 ,
char T_7 * V_225 , int T_7 * V_226 )
{
const struct V_84 * V_85 = F_34 ( V_14 ) ;
if ( V_85 -> V_227 -> V_228 )
return V_85 -> V_227 -> V_228 ( V_14 , V_223 , V_224 ,
V_225 , V_226 ) ;
return V_85 -> V_227 -> V_229 ( V_14 , V_223 , V_224 ,
V_225 , V_226 ) ;
}
int F_150 ( struct V_13 * V_14 , int V_223 , int V_224 ,
char T_7 * V_225 , unsigned int V_226 )
{
const struct V_84 * V_85 = F_34 ( V_14 ) ;
if ( V_85 -> V_227 -> V_230 )
return V_85 -> V_227 -> V_230 ( V_14 , V_223 , V_224 ,
V_225 , V_226 ) ;
return V_85 -> V_227 -> V_231 ( V_14 , V_223 , V_224 ,
V_225 , V_226 ) ;
}
static struct V_116 * F_151 ( struct V_13 * V_14 , struct V_232 * V_145 )
{
const struct V_142 * V_199 = F_78 ( V_14 ) ;
const struct V_122 * V_148 ;
T_1 V_233 = V_199 -> V_221 ;
struct V_117 * V_118 ;
struct V_124 * V_125 ;
F_79 () ;
V_148 = F_80 ( V_199 -> V_148 ) ;
if ( V_148 && V_148 -> V_123 . V_129 )
V_233 = V_148 -> V_123 . V_130 ;
V_118 = & V_145 -> V_146 . V_147 ;
V_125 = F_152 ( F_18 ( V_14 ) , V_118 , V_14 , V_233 ,
V_199 -> V_234 , V_199 -> V_181 ,
V_199 -> V_183 , V_14 -> V_102 ,
F_68 ( V_14 ) , V_14 -> V_38 ) ;
if ( F_74 ( V_125 ) )
V_125 = NULL ;
if ( V_125 )
F_153 ( V_14 , & V_125 -> V_140 ) ;
F_81 () ;
return & V_125 -> V_140 ;
}
struct V_116 * F_154 ( struct V_13 * V_14 , T_3 V_235 )
{
struct V_116 * V_140 = F_155 ( V_14 , 0 ) ;
struct V_142 * V_199 = F_78 ( V_14 ) ;
if ( ! V_140 ) {
V_140 = F_151 ( V_14 , & V_199 -> V_144 . V_145 ) ;
if ( ! V_140 )
goto V_106;
}
V_140 -> V_236 -> V_237 ( V_140 , V_14 , NULL , V_235 ) ;
V_140 = F_155 ( V_14 , 0 ) ;
if ( ! V_140 )
V_140 = F_151 ( V_14 , & V_199 -> V_144 . V_145 ) ;
V_106:
return V_140 ;
}
