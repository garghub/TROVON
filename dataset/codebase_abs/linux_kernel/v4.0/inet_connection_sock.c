void F_1 ( struct V_1 * V_1 , int * V_2 , int * V_3 )
{
unsigned int V_4 ;
do {
V_4 = F_2 ( & V_1 -> V_5 . V_6 . V_7 ) ;
* V_2 = V_1 -> V_5 . V_6 . V_8 [ 0 ] ;
* V_3 = V_1 -> V_5 . V_6 . V_8 [ 1 ] ;
} while ( F_3 ( & V_1 -> V_5 . V_6 . V_7 , V_4 ) );
}
int F_4 ( const struct V_9 * V_10 ,
const struct V_11 * V_12 , bool V_13 )
{
struct V_9 * V_14 ;
int V_15 = V_10 -> V_16 ;
int V_17 = V_10 -> V_18 ;
T_1 V_19 = F_5 ( (struct V_9 * ) V_10 ) ;
F_6 (sk2, &tb->owners) {
if ( V_10 != V_14 &&
! F_7 ( V_14 ) &&
( ! V_10 -> V_20 ||
! V_14 -> V_20 ||
V_10 -> V_20 == V_14 -> V_20 ) ) {
if ( ( ! V_15 || ! V_14 -> V_16 ||
V_14 -> V_21 == V_22 ) &&
( ! V_17 || ! V_14 -> V_18 ||
( V_14 -> V_21 != V_23 &&
! F_8 ( V_19 , F_5 ( V_14 ) ) ) ) ) {
if ( ! V_14 -> V_24 || ! V_10 -> V_24 ||
V_14 -> V_24 == V_10 -> V_24 )
break;
}
if ( ! V_13 && V_15 && V_14 -> V_16 &&
V_14 -> V_21 != V_22 ) {
if ( ! V_14 -> V_24 || ! V_10 -> V_24 ||
V_14 -> V_24 == V_10 -> V_24 )
break;
}
}
}
return V_14 != NULL ;
}
int F_9 ( struct V_9 * V_10 , unsigned short V_25 )
{
struct V_26 * V_27 = V_10 -> V_28 -> V_29 . V_27 ;
struct V_30 * V_31 ;
struct V_11 * V_12 ;
int V_32 , V_33 = 5 ;
struct V_1 * V_1 = F_10 ( V_10 ) ;
int V_34 = - 1 , V_35 ;
T_1 V_19 = F_5 ( V_10 ) ;
F_11 () ;
if ( ! V_25 ) {
int V_36 , V_37 , V_2 , V_3 ;
V_38:
F_1 ( V_1 , & V_2 , & V_3 ) ;
V_36 = ( V_3 - V_2 ) + 1 ;
V_35 = V_37 = F_12 () % V_36 + V_2 ;
V_34 = - 1 ;
do {
if ( F_13 ( V_1 , V_37 ) )
goto V_39;
V_31 = & V_27 -> V_40 [ F_14 ( V_1 , V_37 ,
V_27 -> V_41 ) ] ;
F_15 ( & V_31 -> V_7 ) ;
F_16 (tb, &head->chain)
if ( F_17 ( F_18 ( V_12 ) , V_1 ) && V_12 -> V_42 == V_37 ) {
if ( ( ( V_12 -> V_43 > 0 &&
V_10 -> V_16 &&
V_10 -> V_21 != V_22 ) ||
( V_12 -> V_44 > 0 &&
V_10 -> V_18 &&
F_8 ( V_12 -> V_45 , V_19 ) ) ) &&
( V_12 -> V_46 < V_34 || V_34 == - 1 ) ) {
V_34 = V_12 -> V_46 ;
V_35 = V_37 ;
if ( F_19 ( & V_27 -> V_47 ) > ( V_3 - V_2 ) + 1 &&
! F_20 ( V_10 ) -> V_48 -> V_49 ( V_10 , V_12 , false ) ) {
V_25 = V_35 ;
goto V_50;
}
}
if ( ! F_20 ( V_10 ) -> V_48 -> V_49 ( V_10 , V_12 , false ) ) {
V_25 = V_37 ;
goto V_50;
}
goto V_51;
}
break;
V_51:
F_21 ( & V_31 -> V_7 ) ;
V_39:
if ( ++ V_37 > V_3 )
V_37 = V_2 ;
} while ( -- V_36 > 0 );
V_32 = 1 ;
if ( V_36 <= 0 ) {
if ( V_34 != - 1 ) {
V_25 = V_35 ;
goto V_52;
}
goto V_53;
}
V_25 = V_37 ;
} else {
V_52:
V_31 = & V_27 -> V_40 [ F_14 ( V_1 , V_25 ,
V_27 -> V_41 ) ] ;
F_15 ( & V_31 -> V_7 ) ;
F_16 (tb, &head->chain)
if ( F_17 ( F_18 ( V_12 ) , V_1 ) && V_12 -> V_42 == V_25 )
goto V_50;
}
V_12 = NULL ;
goto V_54;
V_50:
if ( ! F_22 ( & V_12 -> V_55 ) ) {
if ( V_10 -> V_16 == V_56 )
goto V_57;
if ( ( ( V_12 -> V_43 > 0 &&
V_10 -> V_16 && V_10 -> V_21 != V_22 ) ||
( V_12 -> V_44 > 0 &&
V_10 -> V_18 && F_8 ( V_12 -> V_45 , V_19 ) ) ) &&
V_34 == - 1 ) {
goto V_57;
} else {
V_32 = 1 ;
if ( F_20 ( V_10 ) -> V_48 -> V_49 ( V_10 , V_12 , true ) ) {
if ( ( ( V_10 -> V_16 && V_10 -> V_21 != V_22 ) ||
( V_12 -> V_44 > 0 &&
V_10 -> V_18 && F_8 ( V_12 -> V_45 , V_19 ) ) ) &&
V_34 != - 1 && -- V_33 >= 0 ) {
F_21 ( & V_31 -> V_7 ) ;
goto V_38;
}
goto V_58;
}
}
}
V_54:
V_32 = 1 ;
if ( ! V_12 && ( V_12 = F_23 ( V_27 -> V_59 ,
V_1 , V_31 , V_25 ) ) == NULL )
goto V_58;
if ( F_22 ( & V_12 -> V_55 ) ) {
if ( V_10 -> V_16 && V_10 -> V_21 != V_22 )
V_12 -> V_43 = 1 ;
else
V_12 -> V_43 = 0 ;
if ( V_10 -> V_18 ) {
V_12 -> V_44 = 1 ;
V_12 -> V_45 = V_19 ;
} else
V_12 -> V_44 = 0 ;
} else {
if ( V_12 -> V_43 &&
( ! V_10 -> V_16 || V_10 -> V_21 == V_22 ) )
V_12 -> V_43 = 0 ;
if ( V_12 -> V_44 &&
( ! V_10 -> V_18 || ! F_8 ( V_12 -> V_45 , V_19 ) ) )
V_12 -> V_44 = 0 ;
}
V_57:
if ( ! F_20 ( V_10 ) -> V_60 )
F_24 ( V_10 , V_12 , V_25 ) ;
F_25 ( F_20 ( V_10 ) -> V_60 != V_12 ) ;
V_32 = 0 ;
V_58:
F_21 ( & V_31 -> V_7 ) ;
V_53:
F_26 () ;
return V_32 ;
}
static int F_27 ( struct V_9 * V_10 , long V_61 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
F_28 ( V_64 ) ;
int V_65 ;
for (; ; ) {
F_29 ( F_30 ( V_10 ) , & V_64 ,
V_66 ) ;
F_31 ( V_10 ) ;
if ( F_32 ( & V_63 -> V_67 ) )
V_61 = F_33 ( V_61 ) ;
F_34 () ;
F_35 ( V_10 ) ;
V_65 = 0 ;
if ( ! F_32 ( & V_63 -> V_67 ) )
break;
V_65 = - V_68 ;
if ( V_10 -> V_21 != V_22 )
break;
V_65 = F_36 ( V_61 ) ;
if ( F_37 ( V_69 ) )
break;
V_65 = - V_70 ;
if ( ! V_61 )
break;
}
F_38 ( F_30 ( V_10 ) , & V_64 ) ;
return V_65 ;
}
struct V_9 * F_39 ( struct V_9 * V_10 , int V_71 , int * V_65 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
struct V_72 * V_73 = & V_63 -> V_67 ;
struct V_9 * V_74 ;
struct V_75 * V_76 ;
int error ;
F_35 ( V_10 ) ;
error = - V_68 ;
if ( V_10 -> V_21 != V_22 )
goto V_77;
if ( F_32 ( V_73 ) ) {
long V_61 = F_40 ( V_10 , V_71 & V_78 ) ;
error = - V_70 ;
if ( ! V_61 )
goto V_77;
error = F_27 ( V_10 , V_61 ) ;
if ( error )
goto V_77;
}
V_76 = F_41 ( V_73 ) ;
V_74 = V_76 -> V_10 ;
F_42 ( V_10 ) ;
if ( V_10 -> V_79 == V_80 && V_73 -> V_81 != NULL ) {
F_43 ( & V_73 -> V_81 -> V_7 ) ;
if ( F_44 ( V_76 ) -> V_82 ) {
V_76 -> V_10 = NULL ;
V_76 = NULL ;
}
F_45 ( & V_73 -> V_81 -> V_7 ) ;
}
V_83:
F_31 ( V_10 ) ;
if ( V_76 )
F_46 ( V_76 ) ;
return V_74 ;
V_77:
V_74 = NULL ;
V_76 = NULL ;
* V_65 = error ;
goto V_83;
}
void F_47 ( struct V_9 * V_10 ,
void (* F_48)( unsigned long ) ,
void (* F_49)( unsigned long ) ,
void (* F_50)( unsigned long ) )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
F_51 ( & V_63 -> V_84 , F_48 ,
( unsigned long ) V_10 ) ;
F_51 ( & V_63 -> V_85 , F_49 ,
( unsigned long ) V_10 ) ;
F_51 ( & V_10 -> V_86 , F_50 , ( unsigned long ) V_10 ) ;
V_63 -> V_87 = V_63 -> V_88 . V_89 = 0 ;
}
void F_52 ( struct V_9 * V_10 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
V_63 -> V_87 = V_63 -> V_88 . V_89 = V_63 -> V_88 . V_90 = 0 ;
F_53 ( V_10 , & V_63 -> V_84 ) ;
F_53 ( V_10 , & V_63 -> V_85 ) ;
F_53 ( V_10 , & V_10 -> V_86 ) ;
}
void F_54 ( struct V_9 * V_10 )
{
F_53 ( V_10 , & V_10 -> V_86 ) ;
}
void F_55 ( struct V_9 * V_10 , unsigned long V_91 )
{
F_56 ( V_10 , & V_10 -> V_86 , V_92 + V_91 ) ;
}
struct V_93 * F_57 ( struct V_9 * V_10 ,
struct V_94 * V_95 ,
const struct V_75 * V_76 )
{
struct V_96 * V_97 ;
const struct V_98 * V_99 = F_58 ( V_76 ) ;
struct V_100 * V_101 = F_58 ( V_76 ) -> V_101 ;
struct V_1 * V_1 = F_10 ( V_10 ) ;
int V_71 = F_59 ( V_10 ) ;
F_60 ( V_95 , V_10 -> V_20 , V_99 -> V_102 ,
F_61 ( V_10 ) , V_103 ,
V_10 -> V_79 ,
V_71 ,
( V_101 && V_101 -> V_101 . V_104 ) ? V_101 -> V_101 . V_105 : V_99 -> V_106 ,
V_99 -> V_107 , V_99 -> V_108 , F_62 ( V_10 ) -> V_109 ) ;
F_63 ( V_76 , F_64 ( V_95 ) ) ;
V_97 = F_65 ( V_1 , V_95 , V_10 ) ;
if ( F_66 ( V_97 ) )
goto V_110;
if ( V_101 && V_101 -> V_101 . V_111 && V_97 -> V_112 )
goto V_113;
return & V_97 -> V_114 ;
V_113:
F_67 ( V_97 ) ;
V_110:
F_68 ( V_1 , V_115 ) ;
return NULL ;
}
struct V_93 * F_69 ( struct V_9 * V_10 ,
struct V_9 * V_74 ,
const struct V_75 * V_76 )
{
const struct V_98 * V_99 = F_58 ( V_76 ) ;
struct V_116 * V_117 = F_62 ( V_74 ) ;
struct V_100 * V_101 ;
struct V_1 * V_1 = F_10 ( V_10 ) ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
V_95 = & V_117 -> V_118 . V_119 . V_120 . V_121 ;
F_70 () ;
V_101 = F_71 ( V_117 -> V_122 ) ;
F_60 ( V_95 , V_10 -> V_20 , F_58 ( V_76 ) -> V_102 ,
F_61 ( V_10 ) , V_103 ,
V_10 -> V_79 , F_59 ( V_10 ) ,
( V_101 && V_101 -> V_101 . V_104 ) ? V_101 -> V_101 . V_105 : V_99 -> V_106 ,
V_99 -> V_107 , V_99 -> V_108 , F_62 ( V_10 ) -> V_109 ) ;
F_63 ( V_76 , F_64 ( V_95 ) ) ;
V_97 = F_65 ( V_1 , V_95 , V_10 ) ;
if ( F_66 ( V_97 ) )
goto V_110;
if ( V_101 && V_101 -> V_101 . V_111 && V_97 -> V_112 )
goto V_113;
F_72 () ;
return & V_97 -> V_114 ;
V_113:
F_67 ( V_97 ) ;
V_110:
F_72 () ;
F_68 ( V_1 , V_115 ) ;
return NULL ;
}
static inline T_2 F_73 ( const T_3 V_123 , const T_4 V_124 ,
const T_2 V_125 , const T_2 V_126 )
{
return F_74 ( ( V_127 T_2 ) V_123 , ( V_127 T_2 ) V_124 , V_125 ) & ( V_126 - 1 ) ;
}
struct V_75 * F_75 ( const struct V_9 * V_10 ,
struct V_75 * * * V_128 ,
const T_4 V_124 , const T_3 V_123 ,
const T_3 V_129 )
{
const struct V_62 * V_63 = F_20 ( V_10 ) ;
struct V_130 * V_131 = V_63 -> V_67 . V_132 ;
struct V_75 * V_76 , * * V_133 ;
for ( V_133 = & V_131 -> V_134 [ F_73 ( V_123 , V_124 , V_131 -> V_135 ,
V_131 -> V_136 ) ] ;
( V_76 = * V_133 ) != NULL ;
V_133 = & V_76 -> V_137 ) {
const struct V_98 * V_99 = F_58 ( V_76 ) ;
if ( V_99 -> V_108 == V_124 &&
V_99 -> V_106 == V_123 &&
V_99 -> V_107 == V_129 &&
F_76 ( V_76 -> V_138 -> V_139 ) ) {
F_25 ( V_76 -> V_10 ) ;
* V_128 = V_133 ;
break;
}
}
return V_76 ;
}
void F_77 ( struct V_9 * V_10 , struct V_75 * V_76 ,
unsigned long V_140 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
struct V_130 * V_131 = V_63 -> V_67 . V_132 ;
const T_2 V_29 = F_73 ( F_58 ( V_76 ) -> V_106 ,
F_58 ( V_76 ) -> V_108 ,
V_131 -> V_135 , V_131 -> V_136 ) ;
F_78 ( & V_63 -> V_67 , V_29 , V_76 , V_140 ) ;
F_79 ( V_10 , V_140 ) ;
}
static inline void F_80 ( struct V_75 * V_76 , const int V_141 ,
const int V_142 ,
const T_5 V_143 ,
int * V_144 , int * V_145 )
{
if ( ! V_143 ) {
* V_144 = V_76 -> V_146 >= V_141 ;
* V_145 = 1 ;
return;
}
* V_144 = V_76 -> V_146 >= V_141 &&
( ! F_58 ( V_76 ) -> V_147 || V_76 -> V_146 >= V_142 ) ;
* V_145 = ! F_58 ( V_76 ) -> V_147 ||
V_76 -> V_146 >= V_143 - 1 ;
}
int F_81 ( struct V_9 * V_148 , struct V_75 * V_76 )
{
int V_65 = V_76 -> V_138 -> V_149 ( V_148 , V_76 ) ;
if ( ! V_65 )
V_76 -> V_150 ++ ;
return V_65 ;
}
void F_82 ( struct V_9 * V_148 ,
const unsigned long V_151 ,
const unsigned long V_140 ,
const unsigned long V_152 )
{
struct V_62 * V_63 = F_20 ( V_148 ) ;
struct V_72 * V_73 = & V_63 -> V_67 ;
struct V_130 * V_131 = V_73 -> V_132 ;
int V_142 = V_63 -> V_153 ? : V_154 ;
int V_141 = V_142 ;
unsigned long V_155 = V_92 ;
struct V_75 * * V_156 , * V_76 ;
int V_157 , V_158 ;
if ( V_131 == NULL || V_131 -> V_159 == 0 )
return;
if ( V_131 -> V_159 >> ( V_131 -> V_160 - 1 ) ) {
int V_161 = ( V_131 -> V_162 << 1 ) ;
while ( V_141 > 2 ) {
if ( V_131 -> V_159 < V_161 )
break;
V_141 -- ;
V_161 <<= 1 ;
}
}
if ( V_73 -> V_143 )
V_142 = V_73 -> V_143 ;
V_158 = 2 * ( V_131 -> V_136 / ( V_140 / V_151 ) ) ;
V_157 = V_131 -> V_163 ;
do {
V_156 = & V_131 -> V_134 [ V_157 ] ;
while ( ( V_76 = * V_156 ) != NULL ) {
if ( F_83 ( V_155 , V_76 -> V_164 ) ) {
int V_144 = 0 , V_145 = 0 ;
F_80 ( V_76 , V_141 , V_142 ,
V_73 -> V_143 ,
& V_144 , & V_145 ) ;
V_76 -> V_138 -> V_165 ( V_148 , V_76 ) ;
if ( ! V_144 &&
( ! V_145 ||
! F_81 ( V_148 , V_76 ) ||
F_58 ( V_76 ) -> V_147 ) ) {
unsigned long V_61 ;
if ( V_76 -> V_146 ++ == 0 )
V_131 -> V_162 -- ;
V_61 = F_84 ( V_140 << V_76 -> V_146 ,
V_152 ) ;
V_76 -> V_164 = V_155 + V_61 ;
V_156 = & V_76 -> V_137 ;
continue;
}
F_85 ( V_148 , V_76 , V_156 ) ;
F_86 ( V_73 , V_76 ) ;
F_87 ( V_76 ) ;
continue;
}
V_156 = & V_76 -> V_137 ;
}
V_157 = ( V_157 + 1 ) & ( V_131 -> V_136 - 1 ) ;
} while ( -- V_158 > 0 );
V_131 -> V_163 = V_157 ;
if ( V_131 -> V_159 )
F_55 ( V_148 , V_151 ) ;
}
struct V_9 * F_88 ( const struct V_9 * V_10 ,
const struct V_75 * V_76 ,
const T_6 V_166 )
{
struct V_9 * V_74 = F_89 ( V_10 , V_166 ) ;
if ( V_74 != NULL ) {
struct V_62 * V_167 = F_20 ( V_74 ) ;
V_74 -> V_21 = V_168 ;
V_167 -> V_60 = NULL ;
F_62 ( V_74 ) -> V_169 = F_58 ( V_76 ) -> V_108 ;
F_62 ( V_74 ) -> V_170 = F_58 ( V_76 ) -> V_171 ;
F_62 ( V_74 ) -> V_109 = F_90 ( F_58 ( V_76 ) -> V_171 ) ;
V_74 -> V_172 = V_173 ;
V_74 -> V_174 = F_58 ( V_76 ) -> V_102 ;
V_167 -> V_175 = 0 ;
V_167 -> V_176 = 0 ;
V_167 -> V_177 = 0 ;
memset ( & V_167 -> V_67 , 0 , sizeof( V_167 -> V_67 ) ) ;
F_91 ( V_74 , V_76 ) ;
}
return V_74 ;
}
void F_92 ( struct V_9 * V_10 )
{
F_25 ( V_10 -> V_21 != V_178 ) ;
F_25 ( ! F_93 ( V_10 , V_179 ) ) ;
F_25 ( ! F_94 ( V_10 ) ) ;
F_25 ( F_62 ( V_10 ) -> V_170 && ! F_20 ( V_10 ) -> V_60 ) ;
V_10 -> V_28 -> V_180 ( V_10 ) ;
F_95 ( V_10 ) ;
F_96 ( V_10 ) ;
F_97 ( V_10 ) ;
F_98 ( V_10 -> V_28 -> V_181 ) ;
F_99 ( V_10 ) ;
}
void F_100 ( struct V_9 * V_10 )
__releases( &sk->sk_lock.slock
int F_101 ( struct V_9 * V_10 , const int V_136 )
{
struct V_116 * V_182 = F_62 ( V_10 ) ;
struct V_62 * V_63 = F_20 ( V_10 ) ;
int V_183 = F_102 ( & V_63 -> V_67 , V_136 ) ;
if ( V_183 != 0 )
return V_183 ;
V_10 -> V_184 = 0 ;
V_10 -> V_185 = 0 ;
F_103 ( V_10 ) ;
V_10 -> V_21 = V_22 ;
if ( ! V_10 -> V_28 -> V_186 ( V_10 , V_182 -> V_170 ) ) {
V_182 -> V_109 = F_90 ( V_182 -> V_170 ) ;
F_104 ( V_10 ) ;
V_10 -> V_28 -> V_187 ( V_10 ) ;
return 0 ;
}
V_10 -> V_21 = V_178 ;
F_105 ( & V_63 -> V_67 ) ;
return - V_188 ;
}
void F_106 ( struct V_9 * V_10 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
struct V_72 * V_73 = & V_63 -> V_67 ;
struct V_75 * V_189 ;
struct V_75 * V_76 ;
F_54 ( V_10 ) ;
V_189 = F_107 ( V_73 ) ;
F_108 ( V_73 ) ;
while ( ( V_76 = V_189 ) != NULL ) {
struct V_9 * V_190 = V_76 -> V_10 ;
V_189 = V_76 -> V_137 ;
F_11 () ;
F_109 ( V_190 ) ;
F_25 ( F_110 ( V_190 ) ) ;
F_111 ( V_190 ) ;
V_10 -> V_28 -> V_191 ( V_190 , V_78 ) ;
F_112 ( V_190 ) ;
F_113 ( V_10 -> V_28 -> V_181 ) ;
if ( V_10 -> V_79 == V_80 && F_44 ( V_76 ) -> V_82 ) {
F_114 ( F_115 ( V_190 ) -> V_192 != V_76 ) ;
F_114 ( V_10 != F_44 ( V_76 ) -> V_82 ) ;
F_115 ( V_190 ) -> V_192 = NULL ;
F_99 ( V_10 ) ;
}
F_92 ( V_190 ) ;
F_116 ( V_190 ) ;
F_26 () ;
F_99 ( V_190 ) ;
F_42 ( V_10 ) ;
F_46 ( V_76 ) ;
}
if ( V_73 -> V_81 != NULL ) {
F_43 ( & V_73 -> V_81 -> V_7 ) ;
V_189 = V_73 -> V_81 -> V_193 ;
V_73 -> V_81 -> V_193 = NULL ;
F_45 ( & V_73 -> V_81 -> V_7 ) ;
while ( ( V_76 = V_189 ) != NULL ) {
V_189 = V_76 -> V_137 ;
F_46 ( V_76 ) ;
}
}
F_25 ( V_10 -> V_185 ) ;
}
void F_117 ( struct V_9 * V_10 , struct V_194 * V_195 )
{
struct V_196 * sin = (struct V_196 * ) V_195 ;
const struct V_116 * V_182 = F_62 ( V_10 ) ;
sin -> V_197 = V_198 ;
sin -> V_199 . V_200 = V_182 -> V_201 ;
sin -> V_202 = V_182 -> V_169 ;
}
int F_118 ( struct V_9 * V_10 , int V_203 , int V_204 ,
char T_7 * V_205 , int T_7 * V_206 )
{
const struct V_62 * V_63 = F_20 ( V_10 ) ;
if ( V_63 -> V_48 -> V_207 != NULL )
return V_63 -> V_48 -> V_207 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
return V_63 -> V_48 -> V_208 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
}
int F_119 ( struct V_9 * V_10 , int V_203 , int V_204 ,
char T_7 * V_205 , unsigned int V_206 )
{
const struct V_62 * V_63 = F_20 ( V_10 ) ;
if ( V_63 -> V_48 -> V_209 != NULL )
return V_63 -> V_48 -> V_209 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
return V_63 -> V_48 -> V_210 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
}
static struct V_93 * F_120 ( struct V_9 * V_10 , struct V_211 * V_119 )
{
const struct V_116 * V_182 = F_62 ( V_10 ) ;
const struct V_100 * V_122 ;
T_3 V_212 = V_182 -> V_201 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
F_70 () ;
V_122 = F_71 ( V_182 -> V_122 ) ;
if ( V_122 && V_122 -> V_101 . V_104 )
V_212 = V_122 -> V_101 . V_105 ;
V_95 = & V_119 -> V_120 . V_121 ;
V_97 = F_121 ( F_10 ( V_10 ) , V_95 , V_10 , V_212 ,
V_182 -> V_213 , V_182 -> V_169 ,
V_182 -> V_109 , V_10 -> V_79 ,
F_61 ( V_10 ) , V_10 -> V_20 ) ;
if ( F_66 ( V_97 ) )
V_97 = NULL ;
if ( V_97 )
F_122 ( V_10 , & V_97 -> V_114 ) ;
F_72 () ;
return & V_97 -> V_114 ;
}
struct V_93 * F_123 ( struct V_9 * V_10 , T_2 V_214 )
{
struct V_93 * V_114 = F_124 ( V_10 , 0 ) ;
struct V_116 * V_182 = F_62 ( V_10 ) ;
if ( ! V_114 ) {
V_114 = F_120 ( V_10 , & V_182 -> V_118 . V_119 ) ;
if ( ! V_114 )
goto V_83;
}
V_114 -> V_215 -> V_216 ( V_114 , V_10 , NULL , V_214 ) ;
V_114 = F_124 ( V_10 , 0 ) ;
if ( ! V_114 )
V_114 = F_120 ( V_10 , & V_182 -> V_118 . V_119 ) ;
V_83:
return V_114 ;
}
