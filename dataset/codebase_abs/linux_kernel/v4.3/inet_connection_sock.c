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
int V_36 = ( V_10 -> V_16 == V_37 ) ? 1 : 0 ;
F_11 () ;
if ( ! V_25 ) {
int V_38 , V_39 , V_2 , V_3 ;
V_40:
F_1 ( V_1 , & V_2 , & V_3 ) ;
if ( V_36 ) {
int V_41 = V_2 + ( ( V_3 - V_2 ) >> 1 ) ;
if ( V_36 == 1 )
V_3 = V_41 ;
else
V_2 = V_41 ;
}
V_38 = ( V_3 - V_2 ) + 1 ;
V_35 = V_39 = F_12 () % V_38 + V_2 ;
V_34 = - 1 ;
do {
if ( F_13 ( V_1 , V_39 ) )
goto V_42;
V_31 = & V_27 -> V_43 [ F_14 ( V_1 , V_39 ,
V_27 -> V_44 ) ] ;
F_15 ( & V_31 -> V_7 ) ;
F_16 (tb, &head->chain)
if ( F_17 ( F_18 ( V_12 ) , V_1 ) && V_12 -> V_45 == V_39 ) {
if ( ( ( V_12 -> V_46 > 0 &&
V_10 -> V_16 &&
V_10 -> V_21 != V_22 ) ||
( V_12 -> V_47 > 0 &&
V_10 -> V_18 &&
F_8 ( V_12 -> V_48 , V_19 ) ) ) &&
( V_12 -> V_49 < V_34 || V_34 == - 1 ) ) {
V_34 = V_12 -> V_49 ;
V_35 = V_39 ;
}
if ( ! F_19 ( V_10 ) -> V_50 -> V_51 ( V_10 , V_12 , false ) ) {
V_25 = V_39 ;
goto V_52;
}
goto V_53;
}
break;
V_53:
F_20 ( & V_31 -> V_7 ) ;
V_42:
if ( ++ V_39 > V_3 )
V_39 = V_2 ;
} while ( -- V_38 > 0 );
V_32 = 1 ;
if ( V_38 <= 0 ) {
if ( V_34 != - 1 ) {
V_25 = V_35 ;
goto V_54;
}
if ( V_36 == 1 ) {
V_36 = 2 ;
goto V_40;
}
goto V_55;
}
V_25 = V_39 ;
} else {
V_54:
V_31 = & V_27 -> V_43 [ F_14 ( V_1 , V_25 ,
V_27 -> V_44 ) ] ;
F_15 ( & V_31 -> V_7 ) ;
F_16 (tb, &head->chain)
if ( F_17 ( F_18 ( V_12 ) , V_1 ) && V_12 -> V_45 == V_25 )
goto V_52;
}
V_12 = NULL ;
goto V_56;
V_52:
if ( ! F_21 ( & V_12 -> V_57 ) ) {
if ( V_10 -> V_16 == V_58 )
goto V_59;
if ( ( ( V_12 -> V_46 > 0 &&
V_10 -> V_16 && V_10 -> V_21 != V_22 ) ||
( V_12 -> V_47 > 0 &&
V_10 -> V_18 && F_8 ( V_12 -> V_48 , V_19 ) ) ) &&
V_34 == - 1 ) {
goto V_59;
} else {
V_32 = 1 ;
if ( F_19 ( V_10 ) -> V_50 -> V_51 ( V_10 , V_12 , true ) ) {
if ( ( ( V_10 -> V_16 && V_10 -> V_21 != V_22 ) ||
( V_12 -> V_47 > 0 &&
V_10 -> V_18 && F_8 ( V_12 -> V_48 , V_19 ) ) ) &&
V_34 != - 1 && -- V_33 >= 0 ) {
F_20 ( & V_31 -> V_7 ) ;
goto V_40;
}
goto V_60;
}
}
}
V_56:
V_32 = 1 ;
if ( ! V_12 && ( V_12 = F_22 ( V_27 -> V_61 ,
V_1 , V_31 , V_25 ) ) == NULL )
goto V_60;
if ( F_21 ( & V_12 -> V_57 ) ) {
if ( V_10 -> V_16 && V_10 -> V_21 != V_22 )
V_12 -> V_46 = 1 ;
else
V_12 -> V_46 = 0 ;
if ( V_10 -> V_18 ) {
V_12 -> V_47 = 1 ;
V_12 -> V_48 = V_19 ;
} else
V_12 -> V_47 = 0 ;
} else {
if ( V_12 -> V_46 &&
( ! V_10 -> V_16 || V_10 -> V_21 == V_22 ) )
V_12 -> V_46 = 0 ;
if ( V_12 -> V_47 &&
( ! V_10 -> V_18 || ! F_8 ( V_12 -> V_48 , V_19 ) ) )
V_12 -> V_47 = 0 ;
}
V_59:
if ( ! F_19 ( V_10 ) -> V_62 )
F_23 ( V_10 , V_12 , V_25 ) ;
F_24 ( F_19 ( V_10 ) -> V_62 != V_12 ) ;
V_32 = 0 ;
V_60:
F_20 ( & V_31 -> V_7 ) ;
V_55:
F_25 () ;
return V_32 ;
}
static int F_26 ( struct V_9 * V_10 , long V_63 )
{
struct V_64 * V_65 = F_19 ( V_10 ) ;
F_27 ( V_66 ) ;
int V_67 ;
for (; ; ) {
F_28 ( F_29 ( V_10 ) , & V_66 ,
V_68 ) ;
F_30 ( V_10 ) ;
if ( F_31 ( & V_65 -> V_69 ) )
V_63 = F_32 ( V_63 ) ;
F_33 () ;
F_34 ( V_10 ) ;
V_67 = 0 ;
if ( ! F_31 ( & V_65 -> V_69 ) )
break;
V_67 = - V_70 ;
if ( V_10 -> V_21 != V_22 )
break;
V_67 = F_35 ( V_63 ) ;
if ( F_36 ( V_71 ) )
break;
V_67 = - V_72 ;
if ( ! V_63 )
break;
}
F_37 ( F_29 ( V_10 ) , & V_66 ) ;
return V_67 ;
}
struct V_9 * F_38 ( struct V_9 * V_10 , int V_73 , int * V_67 )
{
struct V_64 * V_65 = F_19 ( V_10 ) ;
struct V_74 * V_75 = & V_65 -> V_69 ;
struct V_76 * V_77 ;
struct V_9 * V_78 ;
int error ;
F_34 ( V_10 ) ;
error = - V_70 ;
if ( V_10 -> V_21 != V_22 )
goto V_79;
if ( F_31 ( V_75 ) ) {
long V_63 = F_39 ( V_10 , V_73 & V_80 ) ;
error = - V_72 ;
if ( ! V_63 )
goto V_79;
error = F_26 ( V_10 , V_63 ) ;
if ( error )
goto V_79;
}
V_77 = F_40 ( V_75 ) ;
V_78 = V_77 -> V_10 ;
F_41 ( V_10 ) ;
if ( V_10 -> V_81 == V_82 &&
F_42 ( V_77 ) -> V_83 &&
V_75 -> V_84 ) {
F_43 ( & V_75 -> V_84 -> V_7 ) ;
if ( F_42 ( V_77 ) -> V_83 ) {
V_77 -> V_10 = NULL ;
V_77 = NULL ;
}
F_44 ( & V_75 -> V_84 -> V_7 ) ;
}
V_85:
F_30 ( V_10 ) ;
if ( V_77 )
F_45 ( V_77 ) ;
return V_78 ;
V_79:
V_78 = NULL ;
V_77 = NULL ;
* V_67 = error ;
goto V_85;
}
void F_46 ( struct V_9 * V_10 ,
void (* F_47)( unsigned long ) ,
void (* F_48)( unsigned long ) ,
void (* F_49)( unsigned long ) )
{
struct V_64 * V_65 = F_19 ( V_10 ) ;
F_50 ( & V_65 -> V_86 , F_47 ,
( unsigned long ) V_10 ) ;
F_50 ( & V_65 -> V_87 , F_48 ,
( unsigned long ) V_10 ) ;
F_50 ( & V_10 -> V_88 , F_49 , ( unsigned long ) V_10 ) ;
V_65 -> V_89 = V_65 -> V_90 . V_91 = 0 ;
}
void F_51 ( struct V_9 * V_10 )
{
struct V_64 * V_65 = F_19 ( V_10 ) ;
V_65 -> V_89 = V_65 -> V_90 . V_91 = V_65 -> V_90 . V_92 = 0 ;
F_52 ( V_10 , & V_65 -> V_86 ) ;
F_52 ( V_10 , & V_65 -> V_87 ) ;
F_52 ( V_10 , & V_10 -> V_88 ) ;
}
void F_53 ( struct V_9 * V_10 )
{
F_52 ( V_10 , & V_10 -> V_88 ) ;
}
void F_54 ( struct V_9 * V_10 , unsigned long V_93 )
{
F_55 ( V_10 , & V_10 -> V_88 , V_94 + V_93 ) ;
}
struct V_95 * F_56 ( struct V_9 * V_10 ,
struct V_96 * V_97 ,
const struct V_76 * V_77 )
{
const struct V_98 * V_99 = F_57 ( V_77 ) ;
struct V_1 * V_1 = F_58 ( & V_99 -> V_100 ) ;
struct V_101 * V_102 = V_99 -> V_102 ;
struct V_103 * V_104 ;
F_59 ( V_97 , V_99 -> V_105 , V_99 -> V_106 ,
F_60 ( V_10 ) , V_107 ,
V_10 -> V_81 , F_61 ( V_10 ) ,
( V_102 && V_102 -> V_102 . V_108 ) ? V_102 -> V_102 . V_109 : V_99 -> V_110 ,
V_99 -> V_111 , V_99 -> V_112 ,
F_62 ( V_99 -> V_113 ) ) ;
F_63 ( V_77 , F_64 ( V_97 ) ) ;
V_104 = F_65 ( V_1 , V_97 , V_10 ) ;
if ( F_66 ( V_104 ) )
goto V_114;
if ( V_102 && V_102 -> V_102 . V_115 && V_104 -> V_116 )
goto V_117;
return & V_104 -> V_118 ;
V_117:
F_67 ( V_104 ) ;
V_114:
F_68 ( V_1 , V_119 ) ;
return NULL ;
}
struct V_95 * F_69 ( struct V_9 * V_10 ,
struct V_9 * V_78 ,
const struct V_76 * V_77 )
{
const struct V_98 * V_99 = F_57 ( V_77 ) ;
struct V_1 * V_1 = F_58 ( & V_99 -> V_100 ) ;
struct V_120 * V_121 = F_70 ( V_78 ) ;
struct V_101 * V_102 ;
struct V_96 * V_97 ;
struct V_103 * V_104 ;
V_97 = & V_121 -> V_122 . V_123 . V_124 . V_125 ;
F_71 () ;
V_102 = F_72 ( V_121 -> V_126 ) ;
F_59 ( V_97 , V_99 -> V_105 , V_99 -> V_106 ,
F_60 ( V_10 ) , V_107 ,
V_10 -> V_81 , F_61 ( V_10 ) ,
( V_102 && V_102 -> V_102 . V_108 ) ? V_102 -> V_102 . V_109 : V_99 -> V_110 ,
V_99 -> V_111 , V_99 -> V_112 ,
F_62 ( V_99 -> V_113 ) ) ;
F_63 ( V_77 , F_64 ( V_97 ) ) ;
V_104 = F_65 ( V_1 , V_97 , V_10 ) ;
if ( F_66 ( V_104 ) )
goto V_114;
if ( V_102 && V_102 -> V_102 . V_115 && V_104 -> V_116 )
goto V_117;
F_73 () ;
return & V_104 -> V_118 ;
V_117:
F_67 ( V_104 ) ;
V_114:
F_73 () ;
F_68 ( V_1 , V_119 ) ;
return NULL ;
}
static inline T_2 F_74 ( const T_3 V_127 , const T_4 V_128 ,
const T_2 V_129 , const T_2 V_130 )
{
return F_75 ( ( V_131 T_2 ) V_127 , ( V_131 T_2 ) V_128 , V_129 ) & ( V_130 - 1 ) ;
}
struct V_76 * F_76 ( struct V_9 * V_10 ,
const T_4 V_128 ,
const T_3 V_127 ,
const T_3 V_132 )
{
struct V_64 * V_65 = F_19 ( V_10 ) ;
struct V_133 * V_134 = V_65 -> V_69 . V_135 ;
struct V_76 * V_77 ;
T_2 V_136 = F_74 ( V_127 , V_128 , V_134 -> V_137 ,
V_134 -> V_138 ) ;
F_15 ( & V_65 -> V_69 . V_139 ) ;
for ( V_77 = V_134 -> V_140 [ V_136 ] ; V_77 != NULL ; V_77 = V_77 -> V_141 ) {
const struct V_98 * V_99 = F_57 ( V_77 ) ;
if ( V_99 -> V_112 == V_128 &&
V_99 -> V_110 == V_127 &&
V_99 -> V_111 == V_132 &&
F_77 ( V_77 -> V_142 -> V_143 ) ) {
F_78 ( & V_77 -> V_144 ) ;
F_24 ( V_77 -> V_10 ) ;
break;
}
}
F_20 ( & V_65 -> V_69 . V_139 ) ;
return V_77 ;
}
void F_79 ( struct V_9 * V_10 , struct V_76 * V_77 ,
unsigned long V_145 )
{
struct V_64 * V_65 = F_19 ( V_10 ) ;
struct V_133 * V_134 = V_65 -> V_69 . V_135 ;
const T_2 V_29 = F_74 ( F_57 ( V_77 ) -> V_110 ,
F_57 ( V_77 ) -> V_112 ,
V_134 -> V_137 , V_134 -> V_138 ) ;
F_80 ( & V_65 -> V_69 , V_29 , V_77 , V_145 ) ;
F_81 ( V_10 , V_145 ) ;
}
static inline void F_82 ( struct V_76 * V_77 , const int V_146 ,
const int V_147 ,
const T_5 V_148 ,
int * V_149 , int * V_150 )
{
if ( ! V_148 ) {
* V_149 = V_77 -> V_151 >= V_146 ;
* V_150 = 1 ;
return;
}
* V_149 = V_77 -> V_151 >= V_146 &&
( ! F_57 ( V_77 ) -> V_152 || V_77 -> V_151 >= V_147 ) ;
* V_150 = ! F_57 ( V_77 ) -> V_152 ||
V_77 -> V_151 >= V_148 - 1 ;
}
int F_83 ( struct V_9 * V_153 , struct V_76 * V_77 )
{
int V_67 = V_77 -> V_142 -> V_154 ( V_153 , V_77 ) ;
if ( ! V_67 )
V_77 -> V_155 ++ ;
return V_67 ;
}
static bool F_84 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_76 * * V_156 ;
struct V_133 * V_134 ;
bool V_157 = false ;
F_15 ( & V_75 -> V_139 ) ;
V_134 = V_75 -> V_135 ;
if ( V_134 ) {
for ( V_156 = & V_134 -> V_140 [ V_77 -> V_158 ] ; * V_156 != NULL ;
V_156 = & ( * V_156 ) -> V_141 ) {
if ( * V_156 == V_77 ) {
* V_156 = V_77 -> V_141 ;
V_157 = true ;
break;
}
}
}
F_20 ( & V_75 -> V_139 ) ;
if ( F_85 ( & V_77 -> V_159 ) && F_86 ( & V_77 -> V_159 ) )
F_45 ( V_77 ) ;
return V_157 ;
}
void F_87 ( struct V_9 * V_10 , struct V_76 * V_77 )
{
if ( F_84 ( & F_19 ( V_10 ) -> V_69 , V_77 ) ) {
F_88 ( & F_19 ( V_10 ) -> V_69 , V_77 ) ;
F_45 ( V_77 ) ;
}
}
static void F_89 ( unsigned long V_160 )
{
struct V_76 * V_77 = (struct V_76 * ) V_160 ;
struct V_9 * V_161 = V_77 -> V_162 ;
struct V_64 * V_65 = F_19 ( V_161 ) ;
struct V_74 * V_75 = & V_65 -> V_69 ;
struct V_133 * V_134 = V_75 -> V_135 ;
int V_163 , V_149 = 0 , V_150 = 0 ;
int V_147 , V_146 ;
T_5 V_164 ;
if ( V_161 -> V_21 != V_22 || ! V_134 ) {
F_45 ( V_77 ) ;
return;
}
V_147 = V_65 -> V_165 ? : V_166 ;
V_146 = V_147 ;
V_163 = F_90 ( V_134 ) ;
if ( V_163 >> ( V_134 -> V_167 - 1 ) ) {
int V_168 = F_91 ( V_134 ) << 1 ;
while ( V_146 > 2 ) {
if ( V_163 < V_168 )
break;
V_146 -- ;
V_168 <<= 1 ;
}
}
V_164 = F_92 ( V_75 -> V_148 ) ;
if ( V_164 )
V_147 = V_164 ;
F_82 ( V_77 , V_146 , V_147 , V_164 ,
& V_149 , & V_150 ) ;
V_77 -> V_142 -> V_169 ( V_77 ) ;
if ( ! V_149 &&
( ! V_150 ||
! F_83 ( V_161 , V_77 ) ||
F_57 ( V_77 ) -> V_152 ) ) {
unsigned long V_63 ;
if ( V_77 -> V_151 ++ == 0 )
F_78 ( & V_134 -> V_170 ) ;
V_63 = F_93 ( V_171 << V_77 -> V_151 , V_172 ) ;
F_94 ( & V_77 -> V_159 , V_94 + V_63 ) ;
return;
}
F_87 ( V_161 , V_77 ) ;
F_45 ( V_77 ) ;
}
void F_80 ( struct V_74 * V_75 ,
T_2 V_136 , struct V_76 * V_77 ,
unsigned long V_145 )
{
struct V_133 * V_134 = V_75 -> V_135 ;
V_77 -> V_155 = 0 ;
V_77 -> V_151 = 0 ;
V_77 -> V_10 = NULL ;
F_50 ( & V_77 -> V_159 , F_89 , ( unsigned long ) V_77 ) ;
F_94 ( & V_77 -> V_159 , V_94 + V_145 ) ;
V_77 -> V_158 = V_136 ;
F_95 () ;
F_96 ( & V_77 -> V_144 , 2 ) ;
F_15 ( & V_75 -> V_139 ) ;
V_77 -> V_141 = V_134 -> V_140 [ V_136 ] ;
V_134 -> V_140 [ V_136 ] = V_77 ;
F_20 ( & V_75 -> V_139 ) ;
}
struct V_9 * F_97 ( const struct V_9 * V_10 ,
const struct V_76 * V_77 ,
const T_6 V_173 )
{
struct V_9 * V_78 = F_98 ( V_10 , V_173 ) ;
if ( V_78 ) {
struct V_64 * V_174 = F_19 ( V_78 ) ;
V_78 -> V_21 = V_175 ;
V_174 -> V_62 = NULL ;
F_70 ( V_78 ) -> V_176 = F_57 ( V_77 ) -> V_112 ;
F_70 ( V_78 ) -> V_177 = F_57 ( V_77 ) -> V_113 ;
F_70 ( V_78 ) -> V_178 = F_62 ( F_57 ( V_77 ) -> V_113 ) ;
V_78 -> V_179 = V_180 ;
V_78 -> V_181 = F_57 ( V_77 ) -> V_106 ;
F_99 ( & V_78 -> V_182 ,
F_100 ( & F_57 ( V_77 ) -> V_183 ) ) ;
V_174 -> V_184 = 0 ;
V_174 -> V_185 = 0 ;
V_174 -> V_186 = 0 ;
memset ( & V_174 -> V_69 , 0 , sizeof( V_174 -> V_69 ) ) ;
F_101 ( V_78 , V_77 ) ;
}
return V_78 ;
}
void F_102 ( struct V_9 * V_10 )
{
F_24 ( V_10 -> V_21 != V_187 ) ;
F_24 ( ! F_103 ( V_10 , V_188 ) ) ;
F_24 ( ! F_104 ( V_10 ) ) ;
F_24 ( F_70 ( V_10 ) -> V_177 && ! F_19 ( V_10 ) -> V_62 ) ;
V_10 -> V_28 -> V_189 ( V_10 ) ;
F_105 ( V_10 ) ;
F_106 ( V_10 ) ;
F_107 ( V_10 ) ;
F_108 ( V_10 -> V_28 -> V_190 ) ;
F_109 ( V_10 ) ;
}
void F_110 ( struct V_9 * V_10 )
__releases( &sk->sk_lock.slock
int F_111 ( struct V_9 * V_10 , const int V_138 )
{
struct V_120 * V_191 = F_70 ( V_10 ) ;
struct V_64 * V_65 = F_19 ( V_10 ) ;
int V_192 = F_112 ( & V_65 -> V_69 , V_138 ) ;
if ( V_192 != 0 )
return V_192 ;
V_10 -> V_193 = 0 ;
V_10 -> V_194 = 0 ;
F_113 ( V_10 ) ;
V_10 -> V_21 = V_22 ;
if ( ! V_10 -> V_28 -> V_195 ( V_10 , V_191 -> V_177 ) ) {
V_191 -> V_178 = F_62 ( V_191 -> V_177 ) ;
F_114 ( V_10 ) ;
V_10 -> V_28 -> V_136 ( V_10 ) ;
return 0 ;
}
V_10 -> V_21 = V_187 ;
F_115 ( & V_65 -> V_69 ) ;
return - V_196 ;
}
void F_116 ( struct V_9 * V_10 )
{
struct V_64 * V_65 = F_19 ( V_10 ) ;
struct V_74 * V_75 = & V_65 -> V_69 ;
struct V_76 * V_197 ;
struct V_76 * V_77 ;
V_197 = F_117 ( V_75 ) ;
F_118 ( V_75 ) ;
while ( ( V_77 = V_197 ) != NULL ) {
struct V_9 * V_198 = V_77 -> V_10 ;
V_197 = V_77 -> V_141 ;
F_11 () ;
F_119 ( V_198 ) ;
F_24 ( F_120 ( V_198 ) ) ;
F_121 ( V_198 ) ;
V_10 -> V_28 -> V_199 ( V_198 , V_80 ) ;
F_122 ( V_198 ) ;
F_123 ( V_10 -> V_28 -> V_190 ) ;
if ( V_10 -> V_81 == V_82 && F_42 ( V_77 ) -> V_83 ) {
F_124 ( F_125 ( V_198 ) -> V_200 != V_77 ) ;
F_124 ( V_10 != V_77 -> V_162 ) ;
F_125 ( V_198 ) -> V_200 = NULL ;
}
F_102 ( V_198 ) ;
F_126 ( V_198 ) ;
F_25 () ;
F_109 ( V_198 ) ;
F_41 ( V_10 ) ;
F_45 ( V_77 ) ;
}
if ( V_75 -> V_84 ) {
F_43 ( & V_75 -> V_84 -> V_7 ) ;
V_197 = V_75 -> V_84 -> V_201 ;
V_75 -> V_84 -> V_201 = NULL ;
F_44 ( & V_75 -> V_84 -> V_7 ) ;
while ( ( V_77 = V_197 ) != NULL ) {
V_197 = V_77 -> V_141 ;
F_45 ( V_77 ) ;
}
}
F_24 ( V_10 -> V_194 ) ;
}
void F_127 ( struct V_9 * V_10 , struct V_202 * V_203 )
{
struct V_204 * sin = (struct V_204 * ) V_203 ;
const struct V_120 * V_191 = F_70 ( V_10 ) ;
sin -> V_205 = V_206 ;
sin -> V_207 . V_208 = V_191 -> V_209 ;
sin -> V_210 = V_191 -> V_176 ;
}
int F_128 ( struct V_9 * V_10 , int V_211 , int V_212 ,
char T_7 * V_213 , int T_7 * V_214 )
{
const struct V_64 * V_65 = F_19 ( V_10 ) ;
if ( V_65 -> V_50 -> V_215 )
return V_65 -> V_50 -> V_215 ( V_10 , V_211 , V_212 ,
V_213 , V_214 ) ;
return V_65 -> V_50 -> V_216 ( V_10 , V_211 , V_212 ,
V_213 , V_214 ) ;
}
int F_129 ( struct V_9 * V_10 , int V_211 , int V_212 ,
char T_7 * V_213 , unsigned int V_214 )
{
const struct V_64 * V_65 = F_19 ( V_10 ) ;
if ( V_65 -> V_50 -> V_217 )
return V_65 -> V_50 -> V_217 ( V_10 , V_211 , V_212 ,
V_213 , V_214 ) ;
return V_65 -> V_50 -> V_218 ( V_10 , V_211 , V_212 ,
V_213 , V_214 ) ;
}
static struct V_95 * F_130 ( struct V_9 * V_10 , struct V_219 * V_123 )
{
const struct V_120 * V_191 = F_70 ( V_10 ) ;
const struct V_101 * V_126 ;
T_3 V_220 = V_191 -> V_209 ;
struct V_96 * V_97 ;
struct V_103 * V_104 ;
F_71 () ;
V_126 = F_72 ( V_191 -> V_126 ) ;
if ( V_126 && V_126 -> V_102 . V_108 )
V_220 = V_126 -> V_102 . V_109 ;
V_97 = & V_123 -> V_124 . V_125 ;
V_104 = F_131 ( F_10 ( V_10 ) , V_97 , V_10 , V_220 ,
V_191 -> V_221 , V_191 -> V_176 ,
V_191 -> V_178 , V_10 -> V_81 ,
F_60 ( V_10 ) , V_10 -> V_20 ) ;
if ( F_66 ( V_104 ) )
V_104 = NULL ;
if ( V_104 )
F_132 ( V_10 , & V_104 -> V_118 ) ;
F_73 () ;
return & V_104 -> V_118 ;
}
struct V_95 * F_133 ( struct V_9 * V_10 , T_2 V_222 )
{
struct V_95 * V_118 = F_134 ( V_10 , 0 ) ;
struct V_120 * V_191 = F_70 ( V_10 ) ;
if ( ! V_118 ) {
V_118 = F_130 ( V_10 , & V_191 -> V_122 . V_123 ) ;
if ( ! V_118 )
goto V_85;
}
V_118 -> V_223 -> V_224 ( V_118 , V_10 , NULL , V_222 ) ;
V_118 = F_134 ( V_10 , 0 ) ;
if ( ! V_118 )
V_118 = F_130 ( V_10 , & V_191 -> V_122 . V_123 ) ;
V_85:
return V_118 ;
}
