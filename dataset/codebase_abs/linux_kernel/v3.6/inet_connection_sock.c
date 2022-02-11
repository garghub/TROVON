void F_1 ( int * V_1 , int * V_2 )
{
unsigned int V_3 ;
do {
V_3 = F_2 ( & V_4 . V_5 ) ;
* V_1 = V_4 . V_6 [ 0 ] ;
* V_2 = V_4 . V_6 [ 1 ] ;
} while ( F_3 ( & V_4 . V_5 , V_3 ) );
}
int F_4 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 , bool V_11 )
{
struct V_7 * V_12 ;
struct V_13 * V_14 ;
int V_15 = V_8 -> V_16 ;
F_5 (sk2, node, &tb->owners) {
if ( V_8 != V_12 &&
! F_6 ( V_12 ) &&
( ! V_8 -> V_17 ||
! V_12 -> V_17 ||
V_8 -> V_17 == V_12 -> V_17 ) ) {
if ( ! V_15 || ! V_12 -> V_16 ||
V_12 -> V_18 == V_19 ) {
const T_1 V_20 = F_7 ( V_12 ) ;
if ( ! V_20 || ! F_7 ( V_8 ) ||
V_20 == F_7 ( V_8 ) )
break;
}
if ( ! V_11 && V_15 && V_12 -> V_16 &&
V_12 -> V_18 != V_19 ) {
const T_1 V_20 = F_7 ( V_12 ) ;
if ( ! V_20 || ! F_7 ( V_8 ) ||
V_20 == F_7 ( V_8 ) )
break;
}
}
}
return V_14 != NULL ;
}
int F_8 ( struct V_7 * V_8 , unsigned short V_21 )
{
struct V_22 * V_23 = V_8 -> V_24 -> V_25 . V_23 ;
struct V_26 * V_27 ;
struct V_13 * V_14 ;
struct V_9 * V_10 ;
int V_28 , V_29 = 5 ;
struct V_30 * V_30 = F_9 ( V_8 ) ;
int V_31 = - 1 , V_32 ;
F_10 () ;
if ( ! V_21 ) {
int V_33 , V_34 , V_1 , V_2 ;
V_35:
F_1 ( & V_1 , & V_2 ) ;
V_33 = ( V_2 - V_1 ) + 1 ;
V_32 = V_34 = F_11 () % V_33 + V_1 ;
V_31 = - 1 ;
do {
if ( F_12 ( V_34 ) )
goto V_36;
V_27 = & V_23 -> V_37 [ F_13 ( V_30 , V_34 ,
V_23 -> V_38 ) ] ;
F_14 ( & V_27 -> V_5 ) ;
F_15 (tb, node, &head->chain)
if ( F_16 ( F_17 ( V_10 ) , V_30 ) && V_10 -> V_39 == V_34 ) {
if ( V_10 -> V_40 > 0 &&
V_8 -> V_16 &&
V_8 -> V_18 != V_19 &&
( V_10 -> V_41 < V_31 || V_31 == - 1 ) ) {
V_31 = V_10 -> V_41 ;
V_32 = V_34 ;
if ( F_18 ( & V_23 -> V_42 ) > ( V_2 - V_1 ) + 1 &&
! F_19 ( V_8 ) -> V_43 -> V_44 ( V_8 , V_10 , false ) ) {
V_21 = V_32 ;
goto V_45;
}
}
if ( ! F_19 ( V_8 ) -> V_43 -> V_44 ( V_8 , V_10 , false ) ) {
V_21 = V_34 ;
goto V_45;
}
goto V_46;
}
break;
V_46:
F_20 ( & V_27 -> V_5 ) ;
V_36:
if ( ++ V_34 > V_2 )
V_34 = V_1 ;
} while ( -- V_33 > 0 );
V_28 = 1 ;
if ( V_33 <= 0 ) {
if ( V_31 != - 1 ) {
V_21 = V_32 ;
goto V_47;
}
goto V_48;
}
V_21 = V_34 ;
} else {
V_47:
V_27 = & V_23 -> V_37 [ F_13 ( V_30 , V_21 ,
V_23 -> V_38 ) ] ;
F_14 ( & V_27 -> V_5 ) ;
F_15 (tb, node, &head->chain)
if ( F_16 ( F_17 ( V_10 ) , V_30 ) && V_10 -> V_39 == V_21 )
goto V_45;
}
V_10 = NULL ;
goto V_49;
V_45:
if ( ! F_21 ( & V_10 -> V_50 ) ) {
if ( V_8 -> V_16 == V_51 )
goto V_52;
if ( V_10 -> V_40 > 0 &&
V_8 -> V_16 && V_8 -> V_18 != V_19 &&
V_31 == - 1 ) {
goto V_52;
} else {
V_28 = 1 ;
if ( F_19 ( V_8 ) -> V_43 -> V_44 ( V_8 , V_10 , true ) ) {
if ( V_8 -> V_16 && V_8 -> V_18 != V_19 &&
V_31 != - 1 && -- V_29 >= 0 ) {
F_20 ( & V_27 -> V_5 ) ;
goto V_35;
}
goto V_53;
}
}
}
V_49:
V_28 = 1 ;
if ( ! V_10 && ( V_10 = F_22 ( V_23 -> V_54 ,
V_30 , V_27 , V_21 ) ) == NULL )
goto V_53;
if ( F_21 ( & V_10 -> V_50 ) ) {
if ( V_8 -> V_16 && V_8 -> V_18 != V_19 )
V_10 -> V_40 = 1 ;
else
V_10 -> V_40 = 0 ;
} else if ( V_10 -> V_40 &&
( ! V_8 -> V_16 || V_8 -> V_18 == V_19 ) )
V_10 -> V_40 = 0 ;
V_52:
if ( ! F_19 ( V_8 ) -> V_55 )
F_23 ( V_8 , V_10 , V_21 ) ;
F_24 ( F_19 ( V_8 ) -> V_55 != V_10 ) ;
V_28 = 0 ;
V_53:
F_20 ( & V_27 -> V_5 ) ;
V_48:
F_25 () ;
return V_28 ;
}
static int F_26 ( struct V_7 * V_8 , long V_56 )
{
struct V_57 * V_58 = F_19 ( V_8 ) ;
F_27 ( V_59 ) ;
int V_60 ;
for (; ; ) {
F_28 ( F_29 ( V_8 ) , & V_59 ,
V_61 ) ;
F_30 ( V_8 ) ;
if ( F_31 ( & V_58 -> V_62 ) )
V_56 = F_32 ( V_56 ) ;
F_33 ( V_8 ) ;
V_60 = 0 ;
if ( ! F_31 ( & V_58 -> V_62 ) )
break;
V_60 = - V_63 ;
if ( V_8 -> V_18 != V_19 )
break;
V_60 = F_34 ( V_56 ) ;
if ( F_35 ( V_64 ) )
break;
V_60 = - V_65 ;
if ( ! V_56 )
break;
}
F_36 ( F_29 ( V_8 ) , & V_59 ) ;
return V_60 ;
}
struct V_7 * F_37 ( struct V_7 * V_8 , int V_66 , int * V_60 )
{
struct V_57 * V_58 = F_19 ( V_8 ) ;
struct V_7 * V_67 ;
int error ;
F_33 ( V_8 ) ;
error = - V_63 ;
if ( V_8 -> V_18 != V_19 )
goto V_68;
if ( F_31 ( & V_58 -> V_62 ) ) {
long V_56 = F_38 ( V_8 , V_66 & V_69 ) ;
error = - V_65 ;
if ( ! V_56 )
goto V_68;
error = F_26 ( V_8 , V_56 ) ;
if ( error )
goto V_68;
}
V_67 = F_39 ( & V_58 -> V_62 , V_8 ) ;
F_24 ( V_67 -> V_18 == V_70 ) ;
V_71:
F_30 ( V_8 ) ;
return V_67 ;
V_68:
V_67 = NULL ;
* V_60 = error ;
goto V_71;
}
void F_40 ( struct V_7 * V_8 ,
void (* F_41)( unsigned long ) ,
void (* F_42)( unsigned long ) ,
void (* F_43)( unsigned long ) )
{
struct V_57 * V_58 = F_19 ( V_8 ) ;
F_44 ( & V_58 -> V_72 , F_41 ,
( unsigned long ) V_8 ) ;
F_44 ( & V_58 -> V_73 , F_42 ,
( unsigned long ) V_8 ) ;
F_44 ( & V_8 -> V_74 , F_43 , ( unsigned long ) V_8 ) ;
V_58 -> V_75 = V_58 -> V_76 . V_77 = 0 ;
}
void F_45 ( struct V_7 * V_8 )
{
struct V_57 * V_58 = F_19 ( V_8 ) ;
V_58 -> V_75 = V_58 -> V_76 . V_77 = V_58 -> V_76 . V_78 = 0 ;
F_46 ( V_8 , & V_58 -> V_72 ) ;
F_46 ( V_8 , & V_58 -> V_73 ) ;
F_46 ( V_8 , & V_8 -> V_74 ) ;
}
void F_47 ( struct V_7 * V_8 )
{
F_46 ( V_8 , & V_8 -> V_74 ) ;
}
void F_48 ( struct V_7 * V_8 , unsigned long V_79 )
{
F_49 ( V_8 , & V_8 -> V_74 , V_80 + V_79 ) ;
}
struct V_81 * F_50 ( struct V_7 * V_8 ,
struct V_82 * V_83 ,
const struct V_84 * V_85 )
{
struct V_86 * V_87 ;
const struct V_88 * V_89 = F_51 ( V_85 ) ;
struct V_90 * V_91 = F_51 ( V_85 ) -> V_91 ;
struct V_30 * V_30 = F_9 ( V_8 ) ;
int V_66 = F_52 ( V_8 ) ;
F_53 ( V_83 , V_8 -> V_17 , V_8 -> V_92 ,
F_54 ( V_8 ) , V_93 ,
V_8 -> V_94 ,
V_66 ,
( V_91 && V_91 -> V_91 . V_95 ) ? V_91 -> V_91 . V_96 : V_89 -> V_97 ,
V_89 -> V_98 , V_89 -> V_99 , F_55 ( V_8 ) -> V_100 ) ;
F_56 ( V_85 , F_57 ( V_83 ) ) ;
V_87 = F_58 ( V_30 , V_83 , V_8 ) ;
if ( F_59 ( V_87 ) )
goto V_101;
if ( V_91 && V_91 -> V_91 . V_102 && V_87 -> V_103 )
goto V_104;
return & V_87 -> V_105 ;
V_104:
F_60 ( V_87 ) ;
V_101:
F_61 ( V_30 , V_106 ) ;
return NULL ;
}
struct V_81 * F_62 ( struct V_7 * V_8 ,
struct V_7 * V_67 ,
const struct V_84 * V_85 )
{
const struct V_88 * V_89 = F_51 ( V_85 ) ;
struct V_107 * V_108 = F_55 ( V_67 ) ;
struct V_90 * V_91 ;
struct V_30 * V_30 = F_9 ( V_8 ) ;
struct V_82 * V_83 ;
struct V_86 * V_87 ;
V_83 = & V_108 -> V_109 . V_110 . V_111 . V_112 ;
F_63 () ;
V_91 = F_64 ( V_108 -> V_113 ) ;
F_53 ( V_83 , V_8 -> V_17 , V_8 -> V_92 ,
F_54 ( V_8 ) , V_93 ,
V_8 -> V_94 , F_52 ( V_8 ) ,
( V_91 && V_91 -> V_91 . V_95 ) ? V_91 -> V_91 . V_96 : V_89 -> V_97 ,
V_89 -> V_98 , V_89 -> V_99 , F_55 ( V_8 ) -> V_100 ) ;
F_56 ( V_85 , F_57 ( V_83 ) ) ;
V_87 = F_58 ( V_30 , V_83 , V_8 ) ;
if ( F_59 ( V_87 ) )
goto V_101;
if ( V_91 && V_91 -> V_91 . V_102 && V_87 -> V_103 )
goto V_104;
F_65 () ;
return & V_87 -> V_105 ;
V_104:
F_60 ( V_87 ) ;
V_101:
F_65 () ;
F_61 ( V_30 , V_106 ) ;
return NULL ;
}
static inline T_2 F_66 ( const T_1 V_114 , const T_3 V_115 ,
const T_2 V_116 , const T_2 V_117 )
{
return F_67 ( ( V_118 T_2 ) V_114 , ( V_118 T_2 ) V_115 , V_116 ) & ( V_117 - 1 ) ;
}
struct V_84 * F_68 ( const struct V_7 * V_8 ,
struct V_84 * * * V_119 ,
const T_3 V_115 , const T_1 V_114 ,
const T_1 V_120 )
{
const struct V_57 * V_58 = F_19 ( V_8 ) ;
struct V_121 * V_122 = V_58 -> V_62 . V_123 ;
struct V_84 * V_85 , * * V_124 ;
for ( V_124 = & V_122 -> V_125 [ F_66 ( V_114 , V_115 , V_122 -> V_126 ,
V_122 -> V_127 ) ] ;
( V_85 = * V_124 ) != NULL ;
V_124 = & V_85 -> V_128 ) {
const struct V_88 * V_89 = F_51 ( V_85 ) ;
if ( V_89 -> V_99 == V_115 &&
V_89 -> V_97 == V_114 &&
V_89 -> V_98 == V_120 &&
F_69 ( V_85 -> V_129 -> V_130 ) ) {
F_24 ( V_85 -> V_8 ) ;
* V_119 = V_124 ;
break;
}
}
return V_85 ;
}
void F_70 ( struct V_7 * V_8 , struct V_84 * V_85 ,
unsigned long V_131 )
{
struct V_57 * V_58 = F_19 ( V_8 ) ;
struct V_121 * V_122 = V_58 -> V_62 . V_123 ;
const T_2 V_25 = F_66 ( F_51 ( V_85 ) -> V_97 , F_51 ( V_85 ) -> V_99 ,
V_122 -> V_126 , V_122 -> V_127 ) ;
F_71 ( & V_58 -> V_62 , V_25 , V_85 , V_131 ) ;
F_72 ( V_8 , V_131 ) ;
}
static inline void F_73 ( struct V_84 * V_85 , const int V_132 ,
const int V_133 ,
const T_4 V_134 ,
int * V_135 , int * V_136 )
{
if ( ! V_134 ) {
* V_135 = V_85 -> V_137 >= V_132 ;
* V_136 = 1 ;
return;
}
* V_135 = V_85 -> V_137 >= V_132 &&
( ! F_51 ( V_85 ) -> V_138 || V_85 -> V_137 >= V_133 ) ;
* V_136 = ! F_51 ( V_85 ) -> V_138 ||
V_85 -> V_137 >= V_134 - 1 ;
}
void F_74 ( struct V_7 * V_139 ,
const unsigned long V_140 ,
const unsigned long V_131 ,
const unsigned long V_141 )
{
struct V_57 * V_58 = F_19 ( V_139 ) ;
struct V_142 * V_143 = & V_58 -> V_62 ;
struct V_121 * V_122 = V_143 -> V_123 ;
int V_133 = V_58 -> V_144 ? : V_145 ;
int V_132 = V_133 ;
unsigned long V_146 = V_80 ;
struct V_84 * * V_147 , * V_85 ;
int V_148 , V_149 ;
if ( V_122 == NULL || V_122 -> V_150 == 0 )
return;
if ( V_122 -> V_150 >> ( V_122 -> V_151 - 1 ) ) {
int V_152 = ( V_122 -> V_153 << 1 ) ;
while ( V_132 > 2 ) {
if ( V_122 -> V_150 < V_152 )
break;
V_132 -- ;
V_152 <<= 1 ;
}
}
if ( V_143 -> V_134 )
V_133 = V_143 -> V_134 ;
V_149 = 2 * ( V_122 -> V_127 / ( V_131 / V_140 ) ) ;
V_148 = V_122 -> V_154 ;
do {
V_147 = & V_122 -> V_125 [ V_148 ] ;
while ( ( V_85 = * V_147 ) != NULL ) {
if ( F_75 ( V_146 , V_85 -> V_155 ) ) {
int V_135 = 0 , V_136 = 0 ;
F_73 ( V_85 , V_132 , V_133 ,
V_143 -> V_134 ,
& V_135 , & V_136 ) ;
V_85 -> V_129 -> V_156 ( V_139 , V_85 ) ;
if ( ! V_135 &&
( ! V_136 ||
! V_85 -> V_129 -> V_157 ( V_139 , V_85 , NULL ) ||
F_51 ( V_85 ) -> V_138 ) ) {
unsigned long V_56 ;
if ( V_85 -> V_137 ++ == 0 )
V_122 -> V_153 -- ;
V_56 = F_76 ( ( V_131 << V_85 -> V_137 ) , V_141 ) ;
V_85 -> V_155 = V_146 + V_56 ;
V_147 = & V_85 -> V_128 ;
continue;
}
F_77 ( V_139 , V_85 , V_147 ) ;
F_78 ( V_143 , V_85 ) ;
F_79 ( V_85 ) ;
continue;
}
V_147 = & V_85 -> V_128 ;
}
V_148 = ( V_148 + 1 ) & ( V_122 -> V_127 - 1 ) ;
} while ( -- V_149 > 0 );
V_122 -> V_154 = V_148 ;
if ( V_122 -> V_150 )
F_48 ( V_139 , V_140 ) ;
}
struct V_7 * F_80 ( const struct V_7 * V_8 ,
const struct V_84 * V_85 ,
const T_5 V_158 )
{
struct V_7 * V_67 = F_81 ( V_8 , V_158 ) ;
if ( V_67 != NULL ) {
struct V_57 * V_159 = F_19 ( V_67 ) ;
V_67 -> V_18 = V_70 ;
V_159 -> V_55 = NULL ;
F_55 ( V_67 ) -> V_160 = F_51 ( V_85 ) -> V_99 ;
F_55 ( V_67 ) -> V_161 = F_82 ( F_51 ( V_85 ) -> V_162 ) ;
F_55 ( V_67 ) -> V_100 = F_51 ( V_85 ) -> V_162 ;
V_67 -> V_163 = V_164 ;
V_159 -> V_165 = 0 ;
V_159 -> V_166 = 0 ;
V_159 -> V_167 = 0 ;
memset ( & V_159 -> V_62 , 0 , sizeof( V_159 -> V_62 ) ) ;
F_83 ( V_67 , V_85 ) ;
}
return V_67 ;
}
void F_84 ( struct V_7 * V_8 )
{
F_24 ( V_8 -> V_18 != V_168 ) ;
F_24 ( ! F_85 ( V_8 , V_169 ) ) ;
F_24 ( ! F_86 ( V_8 ) ) ;
F_24 ( F_55 ( V_8 ) -> V_161 && ! F_19 ( V_8 ) -> V_55 ) ;
V_8 -> V_24 -> V_170 ( V_8 ) ;
F_87 ( V_8 ) ;
F_88 ( V_8 ) ;
F_89 ( V_8 ) ;
F_90 ( V_8 -> V_24 -> V_171 ) ;
F_91 ( V_8 ) ;
}
int F_92 ( struct V_7 * V_8 , const int V_127 )
{
struct V_107 * V_172 = F_55 ( V_8 ) ;
struct V_57 * V_58 = F_19 ( V_8 ) ;
int V_173 = F_93 ( & V_58 -> V_62 , V_127 ) ;
if ( V_173 != 0 )
return V_173 ;
V_8 -> V_174 = 0 ;
V_8 -> V_175 = 0 ;
F_94 ( V_8 ) ;
V_8 -> V_18 = V_19 ;
if ( ! V_8 -> V_24 -> V_176 ( V_8 , V_172 -> V_161 ) ) {
V_172 -> V_100 = F_95 ( V_172 -> V_161 ) ;
F_96 ( V_8 ) ;
V_8 -> V_24 -> V_177 ( V_8 ) ;
return 0 ;
}
V_8 -> V_18 = V_168 ;
F_97 ( & V_58 -> V_62 ) ;
return - V_178 ;
}
void F_98 ( struct V_7 * V_8 )
{
struct V_57 * V_58 = F_19 ( V_8 ) ;
struct V_84 * V_179 ;
struct V_84 * V_85 ;
F_47 ( V_8 ) ;
V_179 = F_99 ( & V_58 -> V_62 ) ;
F_100 ( & V_58 -> V_62 ) ;
while ( ( V_85 = V_179 ) != NULL ) {
struct V_7 * V_180 = V_85 -> V_8 ;
V_179 = V_85 -> V_128 ;
F_10 () ;
F_101 ( V_180 ) ;
F_24 ( F_102 ( V_180 ) ) ;
F_103 ( V_180 ) ;
V_8 -> V_24 -> V_181 ( V_180 , V_69 ) ;
F_104 ( V_180 ) ;
F_105 ( V_8 -> V_24 -> V_171 ) ;
F_84 ( V_180 ) ;
F_106 ( V_180 ) ;
F_25 () ;
F_91 ( V_180 ) ;
F_107 ( V_8 ) ;
F_108 ( V_85 ) ;
}
F_24 ( V_8 -> V_175 ) ;
}
void F_109 ( struct V_7 * V_8 , struct V_182 * V_183 )
{
struct V_184 * sin = (struct V_184 * ) V_183 ;
const struct V_107 * V_172 = F_55 ( V_8 ) ;
sin -> V_185 = V_186 ;
sin -> V_187 . V_188 = V_172 -> V_189 ;
sin -> V_190 = V_172 -> V_160 ;
}
int F_110 ( struct V_7 * V_8 , int V_191 , int V_192 ,
char T_6 * V_193 , int T_6 * V_194 )
{
const struct V_57 * V_58 = F_19 ( V_8 ) ;
if ( V_58 -> V_43 -> V_195 != NULL )
return V_58 -> V_43 -> V_195 ( V_8 , V_191 , V_192 ,
V_193 , V_194 ) ;
return V_58 -> V_43 -> V_196 ( V_8 , V_191 , V_192 ,
V_193 , V_194 ) ;
}
int F_111 ( struct V_7 * V_8 , int V_191 , int V_192 ,
char T_6 * V_193 , unsigned int V_194 )
{
const struct V_57 * V_58 = F_19 ( V_8 ) ;
if ( V_58 -> V_43 -> V_197 != NULL )
return V_58 -> V_43 -> V_197 ( V_8 , V_191 , V_192 ,
V_193 , V_194 ) ;
return V_58 -> V_43 -> V_198 ( V_8 , V_191 , V_192 ,
V_193 , V_194 ) ;
}
static struct V_81 * F_112 ( struct V_7 * V_8 , struct V_199 * V_110 )
{
const struct V_107 * V_172 = F_55 ( V_8 ) ;
const struct V_90 * V_113 ;
T_1 V_200 = V_172 -> V_189 ;
struct V_82 * V_83 ;
struct V_86 * V_87 ;
F_63 () ;
V_113 = F_64 ( V_172 -> V_113 ) ;
if ( V_113 && V_113 -> V_91 . V_95 )
V_200 = V_113 -> V_91 . V_96 ;
V_83 = & V_110 -> V_111 . V_112 ;
V_87 = F_113 ( F_9 ( V_8 ) , V_83 , V_8 , V_200 ,
V_172 -> V_201 , V_172 -> V_160 ,
V_172 -> V_100 , V_8 -> V_94 ,
F_54 ( V_8 ) , V_8 -> V_17 ) ;
if ( F_59 ( V_87 ) )
V_87 = NULL ;
if ( V_87 )
F_114 ( V_8 , & V_87 -> V_105 ) ;
F_65 () ;
return & V_87 -> V_105 ;
}
struct V_81 * F_115 ( struct V_7 * V_8 , T_2 V_202 )
{
struct V_81 * V_105 = F_116 ( V_8 , 0 ) ;
struct V_107 * V_172 = F_55 ( V_8 ) ;
if ( ! V_105 ) {
V_105 = F_112 ( V_8 , & V_172 -> V_109 . V_110 ) ;
if ( ! V_105 )
goto V_71;
}
V_105 -> V_203 -> V_204 ( V_105 , V_8 , NULL , V_202 ) ;
V_105 = F_116 ( V_8 , 0 ) ;
if ( ! V_105 )
V_105 = F_112 ( V_8 , & V_172 -> V_109 . V_110 ) ;
V_71:
return V_105 ;
}
