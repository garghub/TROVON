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
const struct V_11 * V_12 , bool V_13 ,
bool V_14 )
{
struct V_9 * V_15 ;
bool V_16 = V_10 -> V_17 ;
bool V_18 = ! ! V_10 -> V_19 && V_14 ;
T_1 V_20 = F_5 ( (struct V_9 * ) V_10 ) ;
F_6 (sk2, &tb->owners) {
if ( V_10 != V_15 &&
! F_7 ( V_15 ) &&
( ! V_10 -> V_21 ||
! V_15 -> V_21 ||
V_10 -> V_21 == V_15 -> V_21 ) ) {
if ( ( ! V_16 || ! V_15 -> V_17 ||
V_15 -> V_22 == V_23 ) &&
( ! V_18 || ! V_15 -> V_19 ||
F_8 ( V_10 -> V_24 ) ||
( V_15 -> V_22 != V_25 &&
! F_9 ( V_20 , F_5 ( V_15 ) ) ) ) ) {
if ( ! V_15 -> V_26 || ! V_10 -> V_26 ||
V_15 -> V_26 == V_10 -> V_26 )
break;
}
if ( ! V_13 && V_16 && V_15 -> V_17 &&
V_15 -> V_22 != V_23 ) {
if ( ! V_15 -> V_26 || ! V_10 -> V_26 ||
V_15 -> V_26 == V_10 -> V_26 )
break;
}
}
}
return V_15 != NULL ;
}
int F_10 ( struct V_9 * V_10 , unsigned short V_27 )
{
bool V_16 = V_10 -> V_17 && V_10 -> V_22 != V_23 ;
struct V_28 * V_29 = V_10 -> V_30 -> V_31 . V_32 ;
int V_33 = 1 , V_34 = 5 , V_35 = V_27 ;
int V_36 = - 1 , V_37 ;
struct V_38 * V_39 ;
struct V_1 * V_1 = F_11 ( V_10 ) ;
int V_40 , V_2 , V_3 , V_41 ;
struct V_11 * V_12 ;
T_1 V_20 = F_5 ( V_10 ) ;
T_2 V_42 , V_43 ;
bool V_14 = ! ! V_27 ;
if ( V_35 ) {
V_44:
V_39 = & V_29 -> V_45 [ F_12 ( V_1 , V_35 ,
V_29 -> V_46 ) ] ;
F_13 ( & V_39 -> V_7 ) ;
F_14 (tb, &head->chain)
if ( F_15 ( F_16 ( V_12 ) , V_1 ) && V_12 -> V_35 == V_35 )
goto V_47;
goto V_48;
}
V_49:
V_41 = ( V_10 -> V_17 == V_50 ) ? 1 : 0 ;
V_51:
F_1 ( V_1 , & V_2 , & V_3 ) ;
V_3 ++ ;
if ( V_3 - V_2 < 4 )
V_41 = 0 ;
if ( V_41 ) {
int V_52 = V_2 + ( ( ( V_3 - V_2 ) >> 2 ) << 1 ) ;
if ( V_41 == 1 )
V_3 = V_52 ;
else
V_2 = V_52 ;
}
V_42 = V_3 - V_2 ;
if ( F_17 ( V_42 > 1 ) )
V_42 &= ~ 1U ;
V_43 = F_18 () % V_42 ;
V_43 |= 1U ;
V_36 = - 1 ;
V_37 = V_2 ;
V_53:
V_35 = V_2 + V_43 ;
for ( V_40 = 0 ; V_40 < V_42 ; V_40 += 2 , V_35 += 2 ) {
if ( F_19 ( V_35 >= V_3 ) )
V_35 -= V_42 ;
if ( F_20 ( V_1 , V_35 ) )
continue;
V_39 = & V_29 -> V_45 [ F_12 ( V_1 , V_35 ,
V_29 -> V_46 ) ] ;
F_13 ( & V_39 -> V_7 ) ;
F_14 (tb, &head->chain)
if ( F_15 ( F_16 ( V_12 ) , V_1 ) && V_12 -> V_35 == V_35 ) {
if ( ( ( V_12 -> V_54 > 0 && V_16 ) ||
( V_12 -> V_55 > 0 &&
V_10 -> V_19 &&
! F_8 ( V_10 -> V_24 ) &&
F_9 ( V_12 -> V_56 , V_20 ) ) ) &&
( V_12 -> V_57 < V_36 || V_36 == - 1 ) ) {
V_36 = V_12 -> V_57 ;
V_37 = V_35 ;
}
if ( ! F_21 ( V_10 ) -> V_58 -> V_59 ( V_10 , V_12 , false ,
V_14 ) )
goto V_47;
goto V_60;
}
goto V_48;
V_60:
F_22 ( & V_39 -> V_7 ) ;
F_23 () ;
}
if ( V_36 != - 1 ) {
V_35 = V_37 ;
goto V_44;
}
V_43 -- ;
if ( ! ( V_43 & 1 ) )
goto V_53;
if ( V_41 == 1 ) {
V_41 = 2 ;
goto V_51;
}
return V_33 ;
V_48:
V_12 = F_24 ( V_29 -> V_61 ,
V_1 , V_39 , V_35 ) ;
if ( ! V_12 )
goto V_62;
V_47:
if ( ! F_25 ( & V_12 -> V_63 ) ) {
if ( V_10 -> V_17 == V_64 )
goto V_65;
if ( ( ( V_12 -> V_54 > 0 && V_16 ) ||
( V_12 -> V_55 > 0 &&
! F_8 ( V_10 -> V_24 ) &&
V_10 -> V_19 && F_9 ( V_12 -> V_56 , V_20 ) ) ) &&
V_36 == - 1 )
goto V_65;
if ( F_21 ( V_10 ) -> V_58 -> V_59 ( V_10 , V_12 , true ,
V_14 ) ) {
if ( ( V_16 ||
( V_12 -> V_55 > 0 &&
V_10 -> V_19 &&
! F_8 ( V_10 -> V_24 ) &&
F_9 ( V_12 -> V_56 , V_20 ) ) ) &&
! V_27 && V_36 != - 1 && -- V_34 >= 0 ) {
F_22 ( & V_39 -> V_7 ) ;
goto V_49;
}
goto V_62;
}
if ( ! V_16 )
V_12 -> V_54 = 0 ;
if ( ! V_10 -> V_19 || ! F_9 ( V_12 -> V_56 , V_20 ) )
V_12 -> V_55 = 0 ;
} else {
V_12 -> V_54 = V_16 ;
if ( V_10 -> V_19 ) {
V_12 -> V_55 = 1 ;
V_12 -> V_56 = V_20 ;
} else {
V_12 -> V_55 = 0 ;
}
}
V_65:
if ( ! F_21 ( V_10 ) -> V_66 )
F_26 ( V_10 , V_12 , V_35 ) ;
F_27 ( F_21 ( V_10 ) -> V_66 != V_12 ) ;
V_33 = 0 ;
V_62:
F_22 ( & V_39 -> V_7 ) ;
return V_33 ;
}
static int F_28 ( struct V_9 * V_10 , long V_67 )
{
struct V_68 * V_69 = F_21 ( V_10 ) ;
F_29 ( V_70 ) ;
int V_71 ;
for (; ; ) {
F_30 ( F_31 ( V_10 ) , & V_70 ,
V_72 ) ;
F_32 ( V_10 ) ;
if ( F_33 ( & V_69 -> V_73 ) )
V_67 = F_34 ( V_67 ) ;
F_35 () ;
F_36 ( V_10 ) ;
V_71 = 0 ;
if ( ! F_33 ( & V_69 -> V_73 ) )
break;
V_71 = - V_74 ;
if ( V_10 -> V_22 != V_23 )
break;
V_71 = F_37 ( V_67 ) ;
if ( F_38 ( V_75 ) )
break;
V_71 = - V_76 ;
if ( ! V_67 )
break;
}
F_39 ( F_31 ( V_10 ) , & V_70 ) ;
return V_71 ;
}
struct V_9 * F_40 ( struct V_9 * V_10 , int V_77 , int * V_71 )
{
struct V_68 * V_69 = F_21 ( V_10 ) ;
struct V_78 * V_79 = & V_69 -> V_73 ;
struct V_80 * V_81 ;
struct V_9 * V_82 ;
int error ;
F_36 ( V_10 ) ;
error = - V_74 ;
if ( V_10 -> V_22 != V_23 )
goto V_83;
if ( F_33 ( V_79 ) ) {
long V_67 = F_41 ( V_10 , V_77 & V_84 ) ;
error = - V_76 ;
if ( ! V_67 )
goto V_83;
error = F_28 ( V_10 , V_67 ) ;
if ( error )
goto V_83;
}
V_81 = F_42 ( V_79 , V_10 ) ;
V_82 = V_81 -> V_10 ;
if ( V_10 -> V_85 == V_86 &&
F_43 ( V_81 ) -> V_87 ) {
F_13 ( & V_79 -> V_88 . V_7 ) ;
if ( F_43 ( V_81 ) -> V_87 ) {
V_81 -> V_10 = NULL ;
V_81 = NULL ;
}
F_22 ( & V_79 -> V_88 . V_7 ) ;
}
V_89:
F_32 ( V_10 ) ;
if ( V_81 )
F_44 ( V_81 ) ;
return V_82 ;
V_83:
V_82 = NULL ;
V_81 = NULL ;
* V_71 = error ;
goto V_89;
}
void F_45 ( struct V_9 * V_10 ,
void (* F_46)( unsigned long ) ,
void (* F_47)( unsigned long ) ,
void (* F_48)( unsigned long ) )
{
struct V_68 * V_69 = F_21 ( V_10 ) ;
F_49 ( & V_69 -> V_90 , F_46 ,
( unsigned long ) V_10 ) ;
F_49 ( & V_69 -> V_91 , F_47 ,
( unsigned long ) V_10 ) ;
F_49 ( & V_10 -> V_92 , F_48 , ( unsigned long ) V_10 ) ;
V_69 -> V_93 = V_69 -> V_94 . V_95 = 0 ;
}
void F_50 ( struct V_9 * V_10 )
{
struct V_68 * V_69 = F_21 ( V_10 ) ;
V_69 -> V_93 = V_69 -> V_94 . V_95 = V_69 -> V_94 . V_96 = 0 ;
F_51 ( V_10 , & V_69 -> V_90 ) ;
F_51 ( V_10 , & V_69 -> V_91 ) ;
F_51 ( V_10 , & V_10 -> V_92 ) ;
}
void F_52 ( struct V_9 * V_10 )
{
F_51 ( V_10 , & V_10 -> V_92 ) ;
}
void F_53 ( struct V_9 * V_10 , unsigned long V_97 )
{
F_54 ( V_10 , & V_10 -> V_92 , V_98 + V_97 ) ;
}
struct V_99 * F_55 ( const struct V_9 * V_10 ,
struct V_100 * V_101 ,
const struct V_80 * V_81 )
{
const struct V_102 * V_103 = F_56 ( V_81 ) ;
struct V_1 * V_1 = F_57 ( & V_103 -> V_104 ) ;
struct V_105 * V_106 = V_103 -> V_106 ;
struct V_107 * V_108 ;
F_58 ( V_101 , V_103 -> V_109 , V_103 -> V_110 ,
F_59 ( V_10 ) , V_111 ,
V_10 -> V_85 , F_60 ( V_10 ) ,
( V_106 && V_106 -> V_106 . V_112 ) ? V_106 -> V_106 . V_113 : V_103 -> V_114 ,
V_103 -> V_115 , V_103 -> V_116 ,
F_61 ( V_103 -> V_117 ) , V_10 -> V_118 ) ;
F_62 ( V_81 , F_63 ( V_101 ) ) ;
V_108 = F_64 ( V_1 , V_101 , V_10 ) ;
if ( F_65 ( V_108 ) )
goto V_119;
if ( V_106 && V_106 -> V_106 . V_120 && V_108 -> V_121 )
goto V_122;
return & V_108 -> V_123 ;
V_122:
F_66 ( V_108 ) ;
V_119:
F_67 ( V_1 , V_124 ) ;
return NULL ;
}
struct V_99 * F_68 ( const struct V_9 * V_10 ,
struct V_9 * V_82 ,
const struct V_80 * V_81 )
{
const struct V_102 * V_103 = F_56 ( V_81 ) ;
struct V_1 * V_1 = F_57 ( & V_103 -> V_104 ) ;
struct V_125 * V_126 = F_69 ( V_82 ) ;
struct V_105 * V_106 ;
struct V_100 * V_101 ;
struct V_107 * V_108 ;
V_101 = & V_126 -> V_127 . V_128 . V_129 . V_130 ;
F_70 () ;
V_106 = F_71 ( V_126 -> V_131 ) ;
F_58 ( V_101 , V_103 -> V_109 , V_103 -> V_110 ,
F_59 ( V_10 ) , V_111 ,
V_10 -> V_85 , F_60 ( V_10 ) ,
( V_106 && V_106 -> V_106 . V_112 ) ? V_106 -> V_106 . V_113 : V_103 -> V_114 ,
V_103 -> V_115 , V_103 -> V_116 ,
F_61 ( V_103 -> V_117 ) , V_10 -> V_118 ) ;
F_62 ( V_81 , F_63 ( V_101 ) ) ;
V_108 = F_64 ( V_1 , V_101 , V_10 ) ;
if ( F_65 ( V_108 ) )
goto V_119;
if ( V_106 && V_106 -> V_106 . V_120 && V_108 -> V_121 )
goto V_122;
F_72 () ;
return & V_108 -> V_123 ;
V_122:
F_66 ( V_108 ) ;
V_119:
F_72 () ;
F_67 ( V_1 , V_124 ) ;
return NULL ;
}
static inline void F_73 ( struct V_80 * V_81 , const int V_132 ,
const int V_133 ,
const T_3 V_134 ,
int * V_135 , int * V_136 )
{
if ( ! V_134 ) {
* V_135 = V_81 -> V_137 >= V_132 ;
* V_136 = 1 ;
return;
}
* V_135 = V_81 -> V_137 >= V_132 &&
( ! F_56 ( V_81 ) -> V_138 || V_81 -> V_137 >= V_133 ) ;
* V_136 = ! F_56 ( V_81 ) -> V_138 ||
V_81 -> V_137 >= V_134 - 1 ;
}
int F_74 ( const struct V_9 * V_139 , struct V_80 * V_81 )
{
int V_71 = V_81 -> V_140 -> V_141 ( V_139 , V_81 ) ;
if ( ! V_71 )
V_81 -> V_142 ++ ;
return V_71 ;
}
static bool F_75 ( struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_28 * V_32 = F_76 ( V_81 ) -> V_30 -> V_31 . V_32 ;
bool V_143 = false ;
if ( F_77 ( F_76 ( V_81 ) ) ) {
T_4 * V_7 = F_78 ( V_32 , V_81 -> V_144 ) ;
F_79 ( V_7 ) ;
V_143 = F_80 ( F_76 ( V_81 ) ) ;
F_81 ( V_7 ) ;
}
if ( F_82 ( & V_81 -> V_145 ) && F_83 ( & V_81 -> V_145 ) )
F_44 ( V_81 ) ;
return V_143 ;
}
void F_84 ( struct V_9 * V_10 , struct V_80 * V_81 )
{
if ( F_75 ( & F_21 ( V_10 ) -> V_73 , V_81 ) ) {
F_85 ( & F_21 ( V_10 ) -> V_73 , V_81 ) ;
F_44 ( V_81 ) ;
}
}
void F_86 ( struct V_9 * V_10 , struct V_80 * V_81 )
{
F_84 ( V_10 , V_81 ) ;
F_44 ( V_81 ) ;
}
static void F_87 ( unsigned long V_146 )
{
struct V_80 * V_81 = (struct V_80 * ) V_146 ;
struct V_9 * V_147 = V_81 -> V_148 ;
struct V_1 * V_1 = F_11 ( V_147 ) ;
struct V_68 * V_69 = F_21 ( V_147 ) ;
struct V_78 * V_79 = & V_69 -> V_73 ;
int V_149 , V_135 = 0 , V_136 = 0 ;
int V_133 , V_132 ;
T_3 V_150 ;
if ( F_88 ( V_147 ) != V_23 )
goto V_151;
V_133 = V_69 -> V_152 ? : V_1 -> V_5 . V_153 ;
V_132 = V_133 ;
V_149 = F_89 ( V_79 ) ;
if ( ( V_149 << 1 ) > F_90 ( 8U , V_147 -> V_154 ) ) {
int V_155 = F_91 ( V_79 ) << 1 ;
while ( V_132 > 2 ) {
if ( V_149 < V_155 )
break;
V_132 -- ;
V_155 <<= 1 ;
}
}
V_150 = F_92 ( V_79 -> V_134 ) ;
if ( V_150 )
V_133 = V_150 ;
F_73 ( V_81 , V_132 , V_133 , V_150 ,
& V_135 , & V_136 ) ;
V_81 -> V_140 -> V_156 ( V_81 ) ;
if ( ! V_135 &&
( ! V_136 ||
! F_74 ( V_147 , V_81 ) ||
F_56 ( V_81 ) -> V_138 ) ) {
unsigned long V_67 ;
if ( V_81 -> V_137 ++ == 0 )
F_93 ( & V_79 -> V_155 ) ;
V_67 = F_94 ( V_157 << V_81 -> V_137 , V_158 ) ;
F_95 ( & V_81 -> V_145 , V_98 + V_67 ) ;
return;
}
V_151:
F_86 ( V_147 , V_81 ) ;
}
static void F_96 ( struct V_80 * V_81 ,
unsigned long V_159 )
{
V_81 -> V_142 = 0 ;
V_81 -> V_137 = 0 ;
V_81 -> V_10 = NULL ;
F_97 ( & V_81 -> V_145 , F_87 ,
( unsigned long ) V_81 ) ;
F_95 ( & V_81 -> V_145 , V_98 + V_159 ) ;
F_98 ( F_76 ( V_81 ) , NULL ) ;
F_99 () ;
F_100 ( & V_81 -> V_160 , 2 + 1 ) ;
}
void F_101 ( struct V_9 * V_10 , struct V_80 * V_81 ,
unsigned long V_159 )
{
F_96 ( V_81 , V_159 ) ;
F_102 ( V_10 ) ;
}
struct V_9 * F_103 ( const struct V_9 * V_10 ,
const struct V_80 * V_81 ,
const T_5 V_161 )
{
struct V_9 * V_82 = F_104 ( V_10 , V_161 ) ;
if ( V_82 ) {
struct V_68 * V_162 = F_21 ( V_82 ) ;
V_82 -> V_22 = V_163 ;
V_162 -> V_66 = NULL ;
F_69 ( V_82 ) -> V_164 = F_56 ( V_81 ) -> V_116 ;
F_69 ( V_82 ) -> V_165 = F_56 ( V_81 ) -> V_117 ;
F_69 ( V_82 ) -> V_166 = F_61 ( F_56 ( V_81 ) -> V_117 ) ;
V_82 -> V_167 = V_168 ;
F_105 ( V_82 , V_169 ) ;
V_82 -> V_170 = F_56 ( V_81 ) -> V_110 ;
F_106 ( & V_82 -> V_171 ,
F_107 ( & F_56 ( V_81 ) -> V_172 ) ) ;
V_162 -> V_173 = 0 ;
V_162 -> V_174 = 0 ;
V_162 -> V_175 = 0 ;
memset ( & V_162 -> V_73 , 0 , sizeof( V_162 -> V_73 ) ) ;
F_108 ( V_82 , V_81 ) ;
}
return V_82 ;
}
void F_109 ( struct V_9 * V_10 )
{
F_27 ( V_10 -> V_22 != V_176 ) ;
F_27 ( ! F_110 ( V_10 , V_177 ) ) ;
F_27 ( ! F_111 ( V_10 ) ) ;
F_27 ( F_69 ( V_10 ) -> V_165 && ! F_21 ( V_10 ) -> V_66 ) ;
V_10 -> V_30 -> V_178 ( V_10 ) ;
F_112 ( V_10 ) ;
F_113 ( V_10 ) ;
F_114 ( V_10 ) ;
F_115 () ;
F_116 ( V_10 -> V_30 -> V_179 ) ;
F_117 () ;
F_118 ( V_10 ) ;
}
void F_119 ( struct V_9 * V_10 )
__releases( &sk->sk_lock.slock
int F_120 ( struct V_9 * V_10 , int V_180 )
{
struct V_68 * V_69 = F_21 ( V_10 ) ;
struct V_125 * V_181 = F_69 ( V_10 ) ;
int V_71 = - V_182 ;
F_121 ( & V_69 -> V_73 ) ;
V_10 -> V_154 = V_180 ;
V_10 -> V_183 = 0 ;
F_122 ( V_10 ) ;
F_123 ( V_10 , V_23 ) ;
if ( ! V_10 -> V_30 -> V_184 ( V_10 , V_181 -> V_165 ) ) {
V_181 -> V_166 = F_61 ( V_181 -> V_165 ) ;
F_124 ( V_10 ) ;
V_71 = V_10 -> V_30 -> V_185 ( V_10 ) ;
if ( F_17 ( ! V_71 ) )
return 0 ;
}
V_10 -> V_22 = V_176 ;
return V_71 ;
}
static void F_125 ( struct V_9 * V_10 , struct V_80 * V_81 ,
struct V_9 * V_186 )
{
V_10 -> V_30 -> V_187 ( V_186 , V_84 ) ;
F_126 ( V_186 ) ;
F_127 ( V_10 -> V_30 -> V_179 ) ;
if ( V_10 -> V_85 == V_86 && F_43 ( V_81 ) -> V_87 ) {
F_128 ( F_129 ( V_186 ) -> V_188 != V_81 ) ;
F_128 ( V_10 != V_81 -> V_148 ) ;
F_129 ( V_186 ) -> V_188 = NULL ;
}
F_109 ( V_186 ) ;
F_44 ( V_81 ) ;
}
struct V_9 * F_130 ( struct V_9 * V_10 ,
struct V_80 * V_81 ,
struct V_9 * V_186 )
{
struct V_78 * V_79 = & F_21 ( V_10 ) -> V_73 ;
F_79 ( & V_79 -> V_189 ) ;
if ( F_19 ( V_10 -> V_22 != V_23 ) ) {
F_125 ( V_10 , V_81 , V_186 ) ;
V_186 = NULL ;
} else {
V_81 -> V_10 = V_186 ;
V_81 -> V_190 = NULL ;
if ( V_79 -> V_191 == NULL )
V_79 -> V_191 = V_81 ;
else
V_79 -> V_192 -> V_190 = V_81 ;
V_79 -> V_192 = V_81 ;
F_131 ( V_10 ) ;
}
F_81 ( & V_79 -> V_189 ) ;
return V_186 ;
}
struct V_9 * F_132 ( struct V_9 * V_10 , struct V_9 * V_186 ,
struct V_80 * V_81 , bool V_193 )
{
if ( V_193 ) {
F_84 ( V_10 , V_81 ) ;
F_85 ( & F_21 ( V_10 ) -> V_73 , V_81 ) ;
if ( F_130 ( V_10 , V_81 , V_186 ) )
return V_186 ;
}
F_133 ( V_186 ) ;
F_118 ( V_186 ) ;
return NULL ;
}
void F_134 ( struct V_9 * V_10 )
{
struct V_68 * V_69 = F_21 ( V_10 ) ;
struct V_78 * V_79 = & V_69 -> V_73 ;
struct V_80 * V_194 , * V_81 ;
while ( ( V_81 = F_42 ( V_79 , V_10 ) ) != NULL ) {
struct V_9 * V_186 = V_81 -> V_10 ;
F_115 () ;
F_135 ( V_186 ) ;
F_27 ( F_136 ( V_186 ) ) ;
F_137 ( V_186 ) ;
F_125 ( V_10 , V_81 , V_186 ) ;
F_133 ( V_186 ) ;
F_117 () ;
F_118 ( V_186 ) ;
F_23 () ;
}
if ( V_79 -> V_88 . V_195 ) {
F_13 ( & V_79 -> V_88 . V_7 ) ;
V_81 = V_79 -> V_88 . V_195 ;
V_79 -> V_88 . V_195 = NULL ;
F_22 ( & V_79 -> V_88 . V_7 ) ;
while ( V_81 != NULL ) {
V_194 = V_81 -> V_190 ;
F_44 ( V_81 ) ;
V_81 = V_194 ;
}
}
F_138 ( V_10 -> V_183 ) ;
}
void F_139 ( struct V_9 * V_10 , struct V_196 * V_197 )
{
struct V_198 * sin = (struct V_198 * ) V_197 ;
const struct V_125 * V_181 = F_69 ( V_10 ) ;
sin -> V_199 = V_200 ;
sin -> V_201 . V_202 = V_181 -> V_203 ;
sin -> V_204 = V_181 -> V_164 ;
}
int F_140 ( struct V_9 * V_10 , int V_205 , int V_206 ,
char T_6 * V_207 , int T_6 * V_208 )
{
const struct V_68 * V_69 = F_21 ( V_10 ) ;
if ( V_69 -> V_58 -> V_209 )
return V_69 -> V_58 -> V_209 ( V_10 , V_205 , V_206 ,
V_207 , V_208 ) ;
return V_69 -> V_58 -> V_210 ( V_10 , V_205 , V_206 ,
V_207 , V_208 ) ;
}
int F_141 ( struct V_9 * V_10 , int V_205 , int V_206 ,
char T_6 * V_207 , unsigned int V_208 )
{
const struct V_68 * V_69 = F_21 ( V_10 ) ;
if ( V_69 -> V_58 -> V_211 )
return V_69 -> V_58 -> V_211 ( V_10 , V_205 , V_206 ,
V_207 , V_208 ) ;
return V_69 -> V_58 -> V_212 ( V_10 , V_205 , V_206 ,
V_207 , V_208 ) ;
}
static struct V_99 * F_142 ( struct V_9 * V_10 , struct V_213 * V_128 )
{
const struct V_125 * V_181 = F_69 ( V_10 ) ;
const struct V_105 * V_131 ;
T_7 V_214 = V_181 -> V_203 ;
struct V_100 * V_101 ;
struct V_107 * V_108 ;
F_70 () ;
V_131 = F_71 ( V_181 -> V_131 ) ;
if ( V_131 && V_131 -> V_106 . V_112 )
V_214 = V_131 -> V_106 . V_113 ;
V_101 = & V_128 -> V_129 . V_130 ;
V_108 = F_143 ( F_11 ( V_10 ) , V_101 , V_10 , V_214 ,
V_181 -> V_215 , V_181 -> V_164 ,
V_181 -> V_166 , V_10 -> V_85 ,
F_59 ( V_10 ) , V_10 -> V_21 ) ;
if ( F_65 ( V_108 ) )
V_108 = NULL ;
if ( V_108 )
F_144 ( V_10 , & V_108 -> V_123 ) ;
F_72 () ;
return & V_108 -> V_123 ;
}
struct V_99 * F_145 ( struct V_9 * V_10 , T_2 V_216 )
{
struct V_99 * V_123 = F_146 ( V_10 , 0 ) ;
struct V_125 * V_181 = F_69 ( V_10 ) ;
if ( ! V_123 ) {
V_123 = F_142 ( V_10 , & V_181 -> V_127 . V_128 ) ;
if ( ! V_123 )
goto V_89;
}
V_123 -> V_217 -> V_218 ( V_123 , V_10 , NULL , V_216 ) ;
V_123 = F_146 ( V_10 , 0 ) ;
if ( ! V_123 )
V_123 = F_142 ( V_10 , & V_181 -> V_127 . V_128 ) ;
V_89:
return V_123 ;
}
