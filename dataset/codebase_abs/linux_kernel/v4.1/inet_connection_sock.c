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
struct V_74 * V_75 ;
struct V_9 * V_76 ;
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
V_75 = F_41 ( V_73 ) ;
V_76 = V_75 -> V_10 ;
F_42 ( V_10 ) ;
if ( V_10 -> V_79 == V_80 &&
F_43 ( V_75 ) -> V_81 &&
V_73 -> V_82 ) {
F_44 ( & V_73 -> V_82 -> V_7 ) ;
if ( F_43 ( V_75 ) -> V_81 ) {
V_75 -> V_10 = NULL ;
V_75 = NULL ;
}
F_45 ( & V_73 -> V_82 -> V_7 ) ;
}
V_83:
F_31 ( V_10 ) ;
if ( V_75 )
F_46 ( V_75 ) ;
return V_76 ;
V_77:
V_76 = NULL ;
V_75 = NULL ;
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
const struct V_74 * V_75 )
{
const struct V_96 * V_97 = F_58 ( V_75 ) ;
struct V_1 * V_1 = F_59 ( & V_97 -> V_98 ) ;
struct V_99 * V_100 = V_97 -> V_100 ;
struct V_101 * V_102 ;
F_60 ( V_95 , V_97 -> V_103 , V_97 -> V_104 ,
F_61 ( V_10 ) , V_105 ,
V_10 -> V_79 , F_62 ( V_10 ) ,
( V_100 && V_100 -> V_100 . V_106 ) ? V_100 -> V_100 . V_107 : V_97 -> V_108 ,
V_97 -> V_109 , V_97 -> V_110 ,
F_63 ( V_97 -> V_111 ) ) ;
F_64 ( V_75 , F_65 ( V_95 ) ) ;
V_102 = F_66 ( V_1 , V_95 , V_10 ) ;
if ( F_67 ( V_102 ) )
goto V_112;
if ( V_100 && V_100 -> V_100 . V_113 && V_102 -> V_114 )
goto V_115;
return & V_102 -> V_116 ;
V_115:
F_68 ( V_102 ) ;
V_112:
F_69 ( V_1 , V_117 ) ;
return NULL ;
}
struct V_93 * F_70 ( struct V_9 * V_10 ,
struct V_9 * V_76 ,
const struct V_74 * V_75 )
{
const struct V_96 * V_97 = F_58 ( V_75 ) ;
struct V_1 * V_1 = F_59 ( & V_97 -> V_98 ) ;
struct V_118 * V_119 = F_71 ( V_76 ) ;
struct V_99 * V_100 ;
struct V_94 * V_95 ;
struct V_101 * V_102 ;
V_95 = & V_119 -> V_120 . V_121 . V_122 . V_123 ;
F_72 () ;
V_100 = F_73 ( V_119 -> V_124 ) ;
F_60 ( V_95 , V_97 -> V_103 , V_97 -> V_104 ,
F_61 ( V_10 ) , V_105 ,
V_10 -> V_79 , F_62 ( V_10 ) ,
( V_100 && V_100 -> V_100 . V_106 ) ? V_100 -> V_100 . V_107 : V_97 -> V_108 ,
V_97 -> V_109 , V_97 -> V_110 ,
F_63 ( V_97 -> V_111 ) ) ;
F_64 ( V_75 , F_65 ( V_95 ) ) ;
V_102 = F_66 ( V_1 , V_95 , V_10 ) ;
if ( F_67 ( V_102 ) )
goto V_112;
if ( V_100 && V_100 -> V_100 . V_113 && V_102 -> V_114 )
goto V_115;
F_74 () ;
return & V_102 -> V_116 ;
V_115:
F_68 ( V_102 ) ;
V_112:
F_74 () ;
F_69 ( V_1 , V_117 ) ;
return NULL ;
}
static inline T_2 F_75 ( const T_3 V_125 , const T_4 V_126 ,
const T_2 V_127 , const T_2 V_128 )
{
return F_76 ( ( V_129 T_2 ) V_125 , ( V_129 T_2 ) V_126 , V_127 ) & ( V_128 - 1 ) ;
}
struct V_74 * F_77 ( struct V_9 * V_10 ,
const T_4 V_126 ,
const T_3 V_125 ,
const T_3 V_130 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
struct V_131 * V_132 = V_63 -> V_67 . V_133 ;
struct V_74 * V_75 ;
T_2 V_134 = F_75 ( V_125 , V_126 , V_132 -> V_135 ,
V_132 -> V_136 ) ;
F_15 ( & V_63 -> V_67 . V_137 ) ;
for ( V_75 = V_132 -> V_138 [ V_134 ] ; V_75 != NULL ; V_75 = V_75 -> V_139 ) {
const struct V_96 * V_97 = F_58 ( V_75 ) ;
if ( V_97 -> V_110 == V_126 &&
V_97 -> V_108 == V_125 &&
V_97 -> V_109 == V_130 &&
F_78 ( V_75 -> V_140 -> V_141 ) ) {
F_79 ( & V_75 -> V_142 ) ;
F_25 ( V_75 -> V_10 ) ;
break;
}
}
F_21 ( & V_63 -> V_67 . V_137 ) ;
return V_75 ;
}
void F_80 ( struct V_9 * V_10 , struct V_74 * V_75 ,
unsigned long V_143 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
struct V_131 * V_132 = V_63 -> V_67 . V_133 ;
const T_2 V_29 = F_75 ( F_58 ( V_75 ) -> V_108 ,
F_58 ( V_75 ) -> V_110 ,
V_132 -> V_135 , V_132 -> V_136 ) ;
F_81 ( & V_63 -> V_67 , V_29 , V_75 , V_143 ) ;
F_82 ( V_10 , V_143 ) ;
}
static inline void F_83 ( struct V_74 * V_75 , const int V_144 ,
const int V_145 ,
const T_5 V_146 ,
int * V_147 , int * V_148 )
{
if ( ! V_146 ) {
* V_147 = V_75 -> V_149 >= V_144 ;
* V_148 = 1 ;
return;
}
* V_147 = V_75 -> V_149 >= V_144 &&
( ! F_58 ( V_75 ) -> V_150 || V_75 -> V_149 >= V_145 ) ;
* V_148 = ! F_58 ( V_75 ) -> V_150 ||
V_75 -> V_149 >= V_146 - 1 ;
}
int F_84 ( struct V_9 * V_151 , struct V_74 * V_75 )
{
int V_65 = V_75 -> V_140 -> V_152 ( V_151 , V_75 ) ;
if ( ! V_65 )
V_75 -> V_153 ++ ;
return V_65 ;
}
static bool F_85 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_131 * V_132 = V_73 -> V_133 ;
struct V_74 * * V_154 ;
bool V_155 = false ;
F_15 ( & V_73 -> V_137 ) ;
for ( V_154 = & V_132 -> V_138 [ V_75 -> V_156 ] ; * V_154 != NULL ;
V_154 = & ( * V_154 ) -> V_139 ) {
if ( * V_154 == V_75 ) {
* V_154 = V_75 -> V_139 ;
V_155 = true ;
break;
}
}
F_21 ( & V_73 -> V_137 ) ;
if ( F_86 ( & V_75 -> V_157 ) )
F_46 ( V_75 ) ;
return V_155 ;
}
void F_87 ( struct V_9 * V_10 , struct V_74 * V_75 )
{
if ( F_85 ( & F_20 ( V_10 ) -> V_67 , V_75 ) ) {
F_88 ( & F_20 ( V_10 ) -> V_67 , V_75 ) ;
F_46 ( V_75 ) ;
}
}
static void F_89 ( unsigned long V_158 )
{
struct V_74 * V_75 = (struct V_74 * ) V_158 ;
struct V_9 * V_159 = V_75 -> V_160 ;
struct V_62 * V_63 = F_20 ( V_159 ) ;
struct V_72 * V_73 = & V_63 -> V_67 ;
struct V_131 * V_132 = V_73 -> V_133 ;
int V_161 , V_147 = 0 , V_148 = 0 ;
int V_145 , V_144 ;
T_5 V_162 ;
if ( V_159 -> V_21 != V_22 || ! V_132 ) {
F_46 ( V_75 ) ;
return;
}
V_145 = V_63 -> V_163 ? : V_164 ;
V_144 = V_145 ;
V_161 = F_90 ( V_132 ) ;
if ( V_161 >> ( V_132 -> V_165 - 1 ) ) {
int V_166 = F_91 ( V_132 ) << 1 ;
while ( V_144 > 2 ) {
if ( V_161 < V_166 )
break;
V_144 -- ;
V_166 <<= 1 ;
}
}
V_162 = F_92 ( V_73 -> V_146 ) ;
if ( V_162 )
V_145 = V_162 ;
F_83 ( V_75 , V_144 , V_145 , V_162 ,
& V_147 , & V_148 ) ;
V_75 -> V_140 -> V_167 ( V_75 ) ;
if ( ! V_147 &&
( ! V_148 ||
! F_84 ( V_159 , V_75 ) ||
F_58 ( V_75 ) -> V_150 ) ) {
unsigned long V_61 ;
if ( V_75 -> V_149 ++ == 0 )
F_79 ( & V_132 -> V_168 ) ;
V_61 = F_93 ( V_169 << V_75 -> V_149 , V_170 ) ;
F_94 ( & V_75 -> V_157 , V_92 + V_61 ) ;
return;
}
F_87 ( V_159 , V_75 ) ;
F_46 ( V_75 ) ;
}
void F_81 ( struct V_72 * V_73 ,
T_2 V_134 , struct V_74 * V_75 ,
unsigned long V_143 )
{
struct V_131 * V_132 = V_73 -> V_133 ;
V_75 -> V_153 = 0 ;
V_75 -> V_149 = 0 ;
V_75 -> V_10 = NULL ;
F_95 () ;
F_96 ( & V_75 -> V_142 , 2 ) ;
F_51 ( & V_75 -> V_157 , F_89 , ( unsigned long ) V_75 ) ;
V_75 -> V_156 = V_134 ;
F_15 ( & V_73 -> V_137 ) ;
V_75 -> V_139 = V_132 -> V_138 [ V_134 ] ;
V_132 -> V_138 [ V_134 ] = V_75 ;
F_21 ( & V_73 -> V_137 ) ;
F_94 ( & V_75 -> V_157 , V_92 + V_143 ) ;
}
struct V_9 * F_97 ( const struct V_9 * V_10 ,
const struct V_74 * V_75 ,
const T_6 V_171 )
{
struct V_9 * V_76 = F_98 ( V_10 , V_171 ) ;
if ( V_76 ) {
struct V_62 * V_172 = F_20 ( V_76 ) ;
V_76 -> V_21 = V_173 ;
V_172 -> V_60 = NULL ;
F_71 ( V_76 ) -> V_174 = F_58 ( V_75 ) -> V_110 ;
F_71 ( V_76 ) -> V_175 = F_58 ( V_75 ) -> V_111 ;
F_71 ( V_76 ) -> V_176 = F_63 ( F_58 ( V_75 ) -> V_111 ) ;
V_76 -> V_177 = V_178 ;
V_76 -> V_179 = F_58 ( V_75 ) -> V_104 ;
F_99 ( & V_76 -> V_180 ,
F_100 ( & F_58 ( V_75 ) -> V_181 ) ) ;
V_172 -> V_182 = 0 ;
V_172 -> V_183 = 0 ;
V_172 -> V_184 = 0 ;
memset ( & V_172 -> V_67 , 0 , sizeof( V_172 -> V_67 ) ) ;
F_101 ( V_76 , V_75 ) ;
}
return V_76 ;
}
void F_102 ( struct V_9 * V_10 )
{
F_25 ( V_10 -> V_21 != V_185 ) ;
F_25 ( ! F_103 ( V_10 , V_186 ) ) ;
F_25 ( ! F_104 ( V_10 ) ) ;
F_25 ( F_71 ( V_10 ) -> V_175 && ! F_20 ( V_10 ) -> V_60 ) ;
V_10 -> V_28 -> V_187 ( V_10 ) ;
F_105 ( V_10 ) ;
F_106 ( V_10 ) ;
F_107 ( V_10 ) ;
F_108 ( V_10 -> V_28 -> V_188 ) ;
F_109 ( V_10 ) ;
}
void F_110 ( struct V_9 * V_10 )
__releases( &sk->sk_lock.slock
int F_111 ( struct V_9 * V_10 , const int V_136 )
{
struct V_118 * V_189 = F_71 ( V_10 ) ;
struct V_62 * V_63 = F_20 ( V_10 ) ;
int V_190 = F_112 ( & V_63 -> V_67 , V_136 ) ;
if ( V_190 != 0 )
return V_190 ;
V_10 -> V_191 = 0 ;
V_10 -> V_192 = 0 ;
F_113 ( V_10 ) ;
V_10 -> V_21 = V_22 ;
if ( ! V_10 -> V_28 -> V_193 ( V_10 , V_189 -> V_175 ) ) {
V_189 -> V_176 = F_63 ( V_189 -> V_175 ) ;
F_114 ( V_10 ) ;
V_10 -> V_28 -> V_134 ( V_10 ) ;
return 0 ;
}
V_10 -> V_21 = V_185 ;
F_115 ( & V_63 -> V_67 ) ;
return - V_194 ;
}
void F_116 ( struct V_9 * V_10 )
{
struct V_62 * V_63 = F_20 ( V_10 ) ;
struct V_72 * V_73 = & V_63 -> V_67 ;
struct V_74 * V_195 ;
struct V_74 * V_75 ;
V_195 = F_117 ( V_73 ) ;
F_118 ( V_73 ) ;
while ( ( V_75 = V_195 ) != NULL ) {
struct V_9 * V_196 = V_75 -> V_10 ;
V_195 = V_75 -> V_139 ;
F_11 () ;
F_119 ( V_196 ) ;
F_25 ( F_120 ( V_196 ) ) ;
F_121 ( V_196 ) ;
V_10 -> V_28 -> V_197 ( V_196 , V_78 ) ;
F_122 ( V_196 ) ;
F_123 ( V_10 -> V_28 -> V_188 ) ;
if ( V_10 -> V_79 == V_80 && F_43 ( V_75 ) -> V_81 ) {
F_124 ( F_125 ( V_196 ) -> V_198 != V_75 ) ;
F_124 ( V_10 != V_75 -> V_160 ) ;
F_125 ( V_196 ) -> V_198 = NULL ;
}
F_102 ( V_196 ) ;
F_126 ( V_196 ) ;
F_26 () ;
F_109 ( V_196 ) ;
F_42 ( V_10 ) ;
F_46 ( V_75 ) ;
}
if ( V_73 -> V_82 ) {
F_44 ( & V_73 -> V_82 -> V_7 ) ;
V_195 = V_73 -> V_82 -> V_199 ;
V_73 -> V_82 -> V_199 = NULL ;
F_45 ( & V_73 -> V_82 -> V_7 ) ;
while ( ( V_75 = V_195 ) != NULL ) {
V_195 = V_75 -> V_139 ;
F_46 ( V_75 ) ;
}
}
F_25 ( V_10 -> V_192 ) ;
}
void F_127 ( struct V_9 * V_10 , struct V_200 * V_201 )
{
struct V_202 * sin = (struct V_202 * ) V_201 ;
const struct V_118 * V_189 = F_71 ( V_10 ) ;
sin -> V_203 = V_204 ;
sin -> V_205 . V_206 = V_189 -> V_207 ;
sin -> V_208 = V_189 -> V_174 ;
}
int F_128 ( struct V_9 * V_10 , int V_209 , int V_210 ,
char T_7 * V_211 , int T_7 * V_212 )
{
const struct V_62 * V_63 = F_20 ( V_10 ) ;
if ( V_63 -> V_48 -> V_213 )
return V_63 -> V_48 -> V_213 ( V_10 , V_209 , V_210 ,
V_211 , V_212 ) ;
return V_63 -> V_48 -> V_214 ( V_10 , V_209 , V_210 ,
V_211 , V_212 ) ;
}
int F_129 ( struct V_9 * V_10 , int V_209 , int V_210 ,
char T_7 * V_211 , unsigned int V_212 )
{
const struct V_62 * V_63 = F_20 ( V_10 ) ;
if ( V_63 -> V_48 -> V_215 )
return V_63 -> V_48 -> V_215 ( V_10 , V_209 , V_210 ,
V_211 , V_212 ) ;
return V_63 -> V_48 -> V_216 ( V_10 , V_209 , V_210 ,
V_211 , V_212 ) ;
}
static struct V_93 * F_130 ( struct V_9 * V_10 , struct V_217 * V_121 )
{
const struct V_118 * V_189 = F_71 ( V_10 ) ;
const struct V_99 * V_124 ;
T_3 V_218 = V_189 -> V_207 ;
struct V_94 * V_95 ;
struct V_101 * V_102 ;
F_72 () ;
V_124 = F_73 ( V_189 -> V_124 ) ;
if ( V_124 && V_124 -> V_100 . V_106 )
V_218 = V_124 -> V_100 . V_107 ;
V_95 = & V_121 -> V_122 . V_123 ;
V_102 = F_131 ( F_10 ( V_10 ) , V_95 , V_10 , V_218 ,
V_189 -> V_219 , V_189 -> V_174 ,
V_189 -> V_176 , V_10 -> V_79 ,
F_61 ( V_10 ) , V_10 -> V_20 ) ;
if ( F_67 ( V_102 ) )
V_102 = NULL ;
if ( V_102 )
F_132 ( V_10 , & V_102 -> V_116 ) ;
F_74 () ;
return & V_102 -> V_116 ;
}
struct V_93 * F_133 ( struct V_9 * V_10 , T_2 V_220 )
{
struct V_93 * V_116 = F_134 ( V_10 , 0 ) ;
struct V_118 * V_189 = F_71 ( V_10 ) ;
if ( ! V_116 ) {
V_116 = F_130 ( V_10 , & V_189 -> V_120 . V_121 ) ;
if ( ! V_116 )
goto V_83;
}
V_116 -> V_221 -> V_222 ( V_116 , V_10 , NULL , V_220 ) ;
V_116 = F_134 ( V_10 , 0 ) ;
if ( ! V_116 )
V_116 = F_130 ( V_10 , & V_189 -> V_120 . V_121 ) ;
V_83:
return V_116 ;
}
