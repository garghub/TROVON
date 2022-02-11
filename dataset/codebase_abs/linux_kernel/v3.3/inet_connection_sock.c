void F_1 ( int * V_1 , int * V_2 )
{
unsigned V_3 ;
do {
V_3 = F_2 ( & V_4 . V_5 ) ;
* V_1 = V_4 . V_6 [ 0 ] ;
* V_2 = V_4 . V_6 [ 1 ] ;
} while ( F_3 ( & V_4 . V_5 , V_3 ) );
}
int F_4 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_7 * V_11 ;
struct V_12 * V_13 ;
int V_14 = V_8 -> V_15 ;
F_5 (sk2, node, &tb->owners) {
if ( V_8 != V_11 &&
! F_6 ( V_11 ) &&
( ! V_8 -> V_16 ||
! V_11 -> V_16 ||
V_8 -> V_16 == V_11 -> V_16 ) ) {
if ( ! V_14 || ! V_11 -> V_15 ||
V_11 -> V_17 == V_18 ) {
const T_1 V_19 = F_7 ( V_11 ) ;
if ( ! V_19 || ! F_7 ( V_8 ) ||
V_19 == F_7 ( V_8 ) )
break;
}
}
}
return V_13 != NULL ;
}
int F_8 ( struct V_7 * V_8 , unsigned short V_20 )
{
struct V_21 * V_22 = V_8 -> V_23 -> V_24 . V_22 ;
struct V_25 * V_26 ;
struct V_12 * V_13 ;
struct V_9 * V_10 ;
int V_27 , V_28 = 5 ;
struct V_29 * V_29 = F_9 ( V_8 ) ;
int V_30 = - 1 , V_31 ;
F_10 () ;
if ( ! V_20 ) {
int V_32 , V_33 , V_1 , V_2 ;
V_34:
F_1 ( & V_1 , & V_2 ) ;
V_32 = ( V_2 - V_1 ) + 1 ;
V_31 = V_33 = F_11 () % V_32 + V_1 ;
V_30 = - 1 ;
do {
if ( F_12 ( V_33 ) )
goto V_35;
V_26 = & V_22 -> V_36 [ F_13 ( V_29 , V_33 ,
V_22 -> V_37 ) ] ;
F_14 ( & V_26 -> V_5 ) ;
F_15 (tb, node, &head->chain)
if ( F_16 ( F_17 ( V_10 ) , V_29 ) && V_10 -> V_38 == V_33 ) {
if ( V_10 -> V_39 > 0 &&
V_8 -> V_15 &&
V_8 -> V_17 != V_18 &&
( V_10 -> V_40 < V_30 || V_30 == - 1 ) ) {
V_30 = V_10 -> V_40 ;
V_31 = V_33 ;
if ( F_18 ( & V_22 -> V_41 ) > ( V_2 - V_1 ) + 1 ) {
V_20 = V_31 ;
goto V_42;
}
}
if ( ! F_19 ( V_8 ) -> V_43 -> V_44 ( V_8 , V_10 ) ) {
V_20 = V_33 ;
goto V_42;
}
goto V_45;
}
break;
V_45:
F_20 ( & V_26 -> V_5 ) ;
V_35:
if ( ++ V_33 > V_2 )
V_33 = V_1 ;
} while ( -- V_32 > 0 );
V_27 = 1 ;
if ( V_32 <= 0 ) {
if ( V_30 != - 1 ) {
V_20 = V_31 ;
goto V_46;
}
goto V_47;
}
V_20 = V_33 ;
} else {
V_46:
V_26 = & V_22 -> V_36 [ F_13 ( V_29 , V_20 ,
V_22 -> V_37 ) ] ;
F_14 ( & V_26 -> V_5 ) ;
F_15 (tb, node, &head->chain)
if ( F_16 ( F_17 ( V_10 ) , V_29 ) && V_10 -> V_38 == V_20 )
goto V_42;
}
V_10 = NULL ;
goto V_48;
V_42:
if ( ! F_21 ( & V_10 -> V_49 ) ) {
if ( V_10 -> V_39 > 0 &&
V_8 -> V_15 && V_8 -> V_17 != V_18 &&
V_30 == - 1 ) {
goto V_50;
} else {
V_27 = 1 ;
if ( F_19 ( V_8 ) -> V_43 -> V_44 ( V_8 , V_10 ) ) {
if ( V_8 -> V_15 && V_8 -> V_17 != V_18 &&
V_30 != - 1 && -- V_28 >= 0 ) {
F_20 ( & V_26 -> V_5 ) ;
goto V_34;
}
goto V_51;
}
}
}
V_48:
V_27 = 1 ;
if ( ! V_10 && ( V_10 = F_22 ( V_22 -> V_52 ,
V_29 , V_26 , V_20 ) ) == NULL )
goto V_51;
if ( F_21 ( & V_10 -> V_49 ) ) {
if ( V_8 -> V_15 && V_8 -> V_17 != V_18 )
V_10 -> V_39 = 1 ;
else
V_10 -> V_39 = 0 ;
} else if ( V_10 -> V_39 &&
( ! V_8 -> V_15 || V_8 -> V_17 == V_18 ) )
V_10 -> V_39 = 0 ;
V_50:
if ( ! F_19 ( V_8 ) -> V_53 )
F_23 ( V_8 , V_10 , V_20 ) ;
F_24 ( F_19 ( V_8 ) -> V_53 != V_10 ) ;
V_27 = 0 ;
V_51:
F_20 ( & V_26 -> V_5 ) ;
V_47:
F_25 () ;
return V_27 ;
}
static int F_26 ( struct V_7 * V_8 , long V_54 )
{
struct V_55 * V_56 = F_19 ( V_8 ) ;
F_27 ( V_57 ) ;
int V_58 ;
for (; ; ) {
F_28 ( F_29 ( V_8 ) , & V_57 ,
V_59 ) ;
F_30 ( V_8 ) ;
if ( F_31 ( & V_56 -> V_60 ) )
V_54 = F_32 ( V_54 ) ;
F_33 ( V_8 ) ;
V_58 = 0 ;
if ( ! F_31 ( & V_56 -> V_60 ) )
break;
V_58 = - V_61 ;
if ( V_8 -> V_17 != V_18 )
break;
V_58 = F_34 ( V_54 ) ;
if ( F_35 ( V_62 ) )
break;
V_58 = - V_63 ;
if ( ! V_54 )
break;
}
F_36 ( F_29 ( V_8 ) , & V_57 ) ;
return V_58 ;
}
struct V_7 * F_37 ( struct V_7 * V_8 , int V_64 , int * V_58 )
{
struct V_55 * V_56 = F_19 ( V_8 ) ;
struct V_7 * V_65 ;
int error ;
F_33 ( V_8 ) ;
error = - V_61 ;
if ( V_8 -> V_17 != V_18 )
goto V_66;
if ( F_31 ( & V_56 -> V_60 ) ) {
long V_54 = F_38 ( V_8 , V_64 & V_67 ) ;
error = - V_63 ;
if ( ! V_54 )
goto V_66;
error = F_26 ( V_8 , V_54 ) ;
if ( error )
goto V_66;
}
V_65 = F_39 ( & V_56 -> V_60 , V_8 ) ;
F_24 ( V_65 -> V_17 == V_68 ) ;
V_69:
F_30 ( V_8 ) ;
return V_65 ;
V_66:
V_65 = NULL ;
* V_58 = error ;
goto V_69;
}
void F_40 ( struct V_7 * V_8 ,
void (* F_41)( unsigned long ) ,
void (* F_42)( unsigned long ) ,
void (* F_43)( unsigned long ) )
{
struct V_55 * V_56 = F_19 ( V_8 ) ;
F_44 ( & V_56 -> V_70 , F_41 ,
( unsigned long ) V_8 ) ;
F_44 ( & V_56 -> V_71 , F_42 ,
( unsigned long ) V_8 ) ;
F_44 ( & V_8 -> V_72 , F_43 , ( unsigned long ) V_8 ) ;
V_56 -> V_73 = V_56 -> V_74 . V_75 = 0 ;
}
void F_45 ( struct V_7 * V_8 )
{
struct V_55 * V_56 = F_19 ( V_8 ) ;
V_56 -> V_73 = V_56 -> V_74 . V_75 = V_56 -> V_74 . V_76 = 0 ;
F_46 ( V_8 , & V_56 -> V_70 ) ;
F_46 ( V_8 , & V_56 -> V_71 ) ;
F_46 ( V_8 , & V_8 -> V_72 ) ;
}
void F_47 ( struct V_7 * V_8 )
{
F_46 ( V_8 , & V_8 -> V_72 ) ;
}
void F_48 ( struct V_7 * V_8 , unsigned long V_77 )
{
F_49 ( V_8 , & V_8 -> V_72 , V_78 + V_77 ) ;
}
struct V_79 * F_50 ( struct V_7 * V_8 ,
struct V_80 * V_81 ,
const struct V_82 * V_83 )
{
struct V_84 * V_85 ;
const struct V_86 * V_87 = F_51 ( V_83 ) ;
struct V_88 * V_89 = F_51 ( V_83 ) -> V_89 ;
struct V_29 * V_29 = F_9 ( V_8 ) ;
F_52 ( V_81 , V_8 -> V_16 , V_8 -> V_90 ,
F_53 ( V_8 ) , V_91 ,
V_8 -> V_92 , F_54 ( V_8 ) ,
( V_89 && V_89 -> V_89 . V_93 ) ? V_89 -> V_89 . V_94 : V_87 -> V_95 ,
V_87 -> V_96 , V_87 -> V_97 , F_55 ( V_8 ) -> V_98 ) ;
F_56 ( V_83 , F_57 ( V_81 ) ) ;
V_85 = F_58 ( V_29 , V_81 , V_8 ) ;
if ( F_59 ( V_85 ) )
goto V_99;
if ( V_89 && V_89 -> V_89 . V_100 && V_81 -> V_101 != V_85 -> V_102 )
goto V_103;
return & V_85 -> V_104 ;
V_103:
F_60 ( V_85 ) ;
V_99:
F_61 ( V_29 , V_105 ) ;
return NULL ;
}
struct V_79 * F_62 ( struct V_7 * V_8 ,
struct V_7 * V_65 ,
const struct V_82 * V_83 )
{
const struct V_86 * V_87 = F_51 ( V_83 ) ;
struct V_106 * V_107 = F_55 ( V_65 ) ;
struct V_88 * V_89 = V_87 -> V_89 ;
struct V_29 * V_29 = F_9 ( V_8 ) ;
struct V_80 * V_81 ;
struct V_84 * V_85 ;
V_81 = & V_107 -> V_108 . V_109 . V_110 . V_111 ;
F_52 ( V_81 , V_8 -> V_16 , V_8 -> V_90 ,
F_53 ( V_8 ) , V_91 ,
V_8 -> V_92 , F_54 ( V_8 ) ,
( V_89 && V_89 -> V_89 . V_93 ) ? V_89 -> V_89 . V_94 : V_87 -> V_95 ,
V_87 -> V_96 , V_87 -> V_97 , F_55 ( V_8 ) -> V_98 ) ;
F_56 ( V_83 , F_57 ( V_81 ) ) ;
V_85 = F_58 ( V_29 , V_81 , V_8 ) ;
if ( F_59 ( V_85 ) )
goto V_99;
if ( V_89 && V_89 -> V_89 . V_100 && V_81 -> V_101 != V_85 -> V_102 )
goto V_103;
return & V_85 -> V_104 ;
V_103:
F_60 ( V_85 ) ;
V_99:
F_61 ( V_29 , V_105 ) ;
return NULL ;
}
static inline T_2 F_63 ( const T_1 V_112 , const T_3 V_113 ,
const T_2 V_114 , const T_2 V_115 )
{
return F_64 ( ( V_116 T_2 ) V_112 , ( V_116 T_2 ) V_113 , V_114 ) & ( V_115 - 1 ) ;
}
struct V_82 * F_65 ( const struct V_7 * V_8 ,
struct V_82 * * * V_117 ,
const T_3 V_113 , const T_1 V_112 ,
const T_1 V_118 )
{
const struct V_55 * V_56 = F_19 ( V_8 ) ;
struct V_119 * V_120 = V_56 -> V_60 . V_121 ;
struct V_82 * V_83 , * * V_122 ;
for ( V_122 = & V_120 -> V_123 [ F_63 ( V_112 , V_113 , V_120 -> V_124 ,
V_120 -> V_125 ) ] ;
( V_83 = * V_122 ) != NULL ;
V_122 = & V_83 -> V_126 ) {
const struct V_86 * V_87 = F_51 ( V_83 ) ;
if ( V_87 -> V_97 == V_113 &&
V_87 -> V_95 == V_112 &&
V_87 -> V_96 == V_118 &&
F_66 ( V_83 -> V_127 -> V_128 ) ) {
F_24 ( V_83 -> V_8 ) ;
* V_117 = V_122 ;
break;
}
}
return V_83 ;
}
void F_67 ( struct V_7 * V_8 , struct V_82 * V_83 ,
unsigned long V_129 )
{
struct V_55 * V_56 = F_19 ( V_8 ) ;
struct V_119 * V_120 = V_56 -> V_60 . V_121 ;
const T_2 V_24 = F_63 ( F_51 ( V_83 ) -> V_95 , F_51 ( V_83 ) -> V_97 ,
V_120 -> V_124 , V_120 -> V_125 ) ;
F_68 ( & V_56 -> V_60 , V_24 , V_83 , V_129 ) ;
F_69 ( V_8 , V_129 ) ;
}
static inline void F_70 ( struct V_82 * V_83 , const int V_130 ,
const int V_131 ,
const T_4 V_132 ,
int * V_133 , int * V_134 )
{
if ( ! V_132 ) {
* V_133 = V_83 -> V_135 >= V_130 ;
* V_134 = 1 ;
return;
}
* V_133 = V_83 -> V_135 >= V_130 &&
( ! F_51 ( V_83 ) -> V_136 || V_83 -> V_135 >= V_131 ) ;
* V_134 = ! F_51 ( V_83 ) -> V_136 ||
V_83 -> V_135 >= V_132 - 1 ;
}
void F_71 ( struct V_7 * V_137 ,
const unsigned long V_138 ,
const unsigned long V_129 ,
const unsigned long V_139 )
{
struct V_55 * V_56 = F_19 ( V_137 ) ;
struct V_140 * V_141 = & V_56 -> V_60 ;
struct V_119 * V_120 = V_141 -> V_121 ;
int V_131 = V_56 -> V_142 ? : V_143 ;
int V_130 = V_131 ;
unsigned long V_144 = V_78 ;
struct V_82 * * V_145 , * V_83 ;
int V_146 , V_147 ;
if ( V_120 == NULL || V_120 -> V_148 == 0 )
return;
if ( V_120 -> V_148 >> ( V_120 -> V_149 - 1 ) ) {
int V_150 = ( V_120 -> V_151 << 1 ) ;
while ( V_130 > 2 ) {
if ( V_120 -> V_148 < V_150 )
break;
V_130 -- ;
V_150 <<= 1 ;
}
}
if ( V_141 -> V_132 )
V_131 = V_141 -> V_132 ;
V_147 = 2 * ( V_120 -> V_125 / ( V_129 / V_138 ) ) ;
V_146 = V_120 -> V_152 ;
do {
V_145 = & V_120 -> V_123 [ V_146 ] ;
while ( ( V_83 = * V_145 ) != NULL ) {
if ( F_72 ( V_144 , V_83 -> V_153 ) ) {
int V_133 = 0 , V_134 = 0 ;
F_70 ( V_83 , V_130 , V_131 ,
V_141 -> V_132 ,
& V_133 , & V_134 ) ;
if ( V_83 -> V_127 -> V_154 )
V_83 -> V_127 -> V_154 ( V_137 , V_83 ) ;
if ( ! V_133 &&
( ! V_134 ||
! V_83 -> V_127 -> V_155 ( V_137 , V_83 , NULL ) ||
F_51 ( V_83 ) -> V_136 ) ) {
unsigned long V_54 ;
if ( V_83 -> V_135 ++ == 0 )
V_120 -> V_151 -- ;
V_54 = F_73 ( ( V_129 << V_83 -> V_135 ) , V_139 ) ;
V_83 -> V_153 = V_144 + V_54 ;
V_145 = & V_83 -> V_126 ;
continue;
}
F_74 ( V_137 , V_83 , V_145 ) ;
F_75 ( V_141 , V_83 ) ;
F_76 ( V_83 ) ;
continue;
}
V_145 = & V_83 -> V_126 ;
}
V_146 = ( V_146 + 1 ) & ( V_120 -> V_125 - 1 ) ;
} while ( -- V_147 > 0 );
V_120 -> V_152 = V_146 ;
if ( V_120 -> V_148 )
F_48 ( V_137 , V_138 ) ;
}
struct V_7 * F_77 ( const struct V_7 * V_8 ,
const struct V_82 * V_83 ,
const T_5 V_156 )
{
struct V_7 * V_65 = F_78 ( V_8 , V_156 ) ;
if ( V_65 != NULL ) {
struct V_55 * V_157 = F_19 ( V_65 ) ;
V_65 -> V_17 = V_68 ;
V_157 -> V_53 = NULL ;
F_55 ( V_65 ) -> V_158 = F_51 ( V_83 ) -> V_97 ;
F_55 ( V_65 ) -> V_159 = F_79 ( F_51 ( V_83 ) -> V_160 ) ;
F_55 ( V_65 ) -> V_98 = F_51 ( V_83 ) -> V_160 ;
V_65 -> V_161 = V_162 ;
V_157 -> V_163 = 0 ;
V_157 -> V_164 = 0 ;
V_157 -> V_165 = 0 ;
memset ( & V_157 -> V_60 , 0 , sizeof( V_157 -> V_60 ) ) ;
F_80 ( V_65 , V_83 ) ;
}
return V_65 ;
}
void F_81 ( struct V_7 * V_8 )
{
F_24 ( V_8 -> V_17 != V_166 ) ;
F_24 ( ! F_82 ( V_8 , V_167 ) ) ;
F_24 ( ! F_83 ( V_8 ) ) ;
F_24 ( F_55 ( V_8 ) -> V_159 && ! F_19 ( V_8 ) -> V_53 ) ;
V_8 -> V_23 -> V_168 ( V_8 ) ;
F_84 ( V_8 ) ;
F_85 ( V_8 ) ;
F_86 ( V_8 ) ;
F_87 ( V_8 -> V_23 -> V_169 ) ;
F_88 ( V_8 ) ;
}
int F_89 ( struct V_7 * V_8 , const int V_125 )
{
struct V_106 * V_170 = F_55 ( V_8 ) ;
struct V_55 * V_56 = F_19 ( V_8 ) ;
int V_171 = F_90 ( & V_56 -> V_60 , V_125 ) ;
if ( V_171 != 0 )
return V_171 ;
V_8 -> V_172 = 0 ;
V_8 -> V_173 = 0 ;
F_91 ( V_8 ) ;
V_8 -> V_17 = V_18 ;
if ( ! V_8 -> V_23 -> V_174 ( V_8 , V_170 -> V_159 ) ) {
V_170 -> V_98 = F_92 ( V_170 -> V_159 ) ;
F_93 ( V_8 ) ;
V_8 -> V_23 -> V_175 ( V_8 ) ;
return 0 ;
}
V_8 -> V_17 = V_166 ;
F_94 ( & V_56 -> V_60 ) ;
return - V_176 ;
}
void F_95 ( struct V_7 * V_8 )
{
struct V_55 * V_56 = F_19 ( V_8 ) ;
struct V_82 * V_177 ;
struct V_82 * V_83 ;
F_47 ( V_8 ) ;
V_177 = F_96 ( & V_56 -> V_60 ) ;
F_97 ( & V_56 -> V_60 ) ;
while ( ( V_83 = V_177 ) != NULL ) {
struct V_7 * V_178 = V_83 -> V_8 ;
V_177 = V_83 -> V_126 ;
F_10 () ;
F_98 ( V_178 ) ;
F_24 ( F_99 ( V_178 ) ) ;
F_100 ( V_178 ) ;
V_8 -> V_23 -> V_179 ( V_178 , V_67 ) ;
F_101 ( V_178 ) ;
F_102 ( V_8 -> V_23 -> V_169 ) ;
F_81 ( V_178 ) ;
F_103 ( V_178 ) ;
F_25 () ;
F_88 ( V_178 ) ;
F_104 ( V_8 ) ;
F_105 ( V_83 ) ;
}
F_24 ( V_8 -> V_173 ) ;
}
void F_106 ( struct V_7 * V_8 , struct V_180 * V_181 )
{
struct V_182 * sin = (struct V_182 * ) V_181 ;
const struct V_106 * V_170 = F_55 ( V_8 ) ;
sin -> V_183 = V_184 ;
sin -> V_185 . V_186 = V_170 -> V_187 ;
sin -> V_188 = V_170 -> V_158 ;
}
int F_107 ( struct V_7 * V_8 , int V_189 , int V_190 ,
char T_6 * V_191 , int T_6 * V_192 )
{
const struct V_55 * V_56 = F_19 ( V_8 ) ;
if ( V_56 -> V_43 -> V_193 != NULL )
return V_56 -> V_43 -> V_193 ( V_8 , V_189 , V_190 ,
V_191 , V_192 ) ;
return V_56 -> V_43 -> V_194 ( V_8 , V_189 , V_190 ,
V_191 , V_192 ) ;
}
int F_108 ( struct V_7 * V_8 , int V_189 , int V_190 ,
char T_6 * V_191 , unsigned int V_192 )
{
const struct V_55 * V_56 = F_19 ( V_8 ) ;
if ( V_56 -> V_43 -> V_195 != NULL )
return V_56 -> V_43 -> V_195 ( V_8 , V_189 , V_190 ,
V_191 , V_192 ) ;
return V_56 -> V_43 -> V_196 ( V_8 , V_189 , V_190 ,
V_191 , V_192 ) ;
}
