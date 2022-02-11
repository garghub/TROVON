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
F_8 ( V_10 -> V_23 ) ||
( V_14 -> V_21 != V_24 &&
! F_9 ( V_19 , F_5 ( V_14 ) ) ) ) ) {
if ( ! V_14 -> V_25 || ! V_10 -> V_25 ||
V_14 -> V_25 == V_10 -> V_25 )
break;
}
if ( ! V_13 && V_15 && V_14 -> V_16 &&
V_14 -> V_21 != V_22 ) {
if ( ! V_14 -> V_25 || ! V_10 -> V_25 ||
V_14 -> V_25 == V_10 -> V_25 )
break;
}
}
}
return V_14 != NULL ;
}
int F_10 ( struct V_9 * V_10 , unsigned short V_26 )
{
bool V_15 = V_10 -> V_16 && V_10 -> V_21 != V_22 ;
struct V_27 * V_28 = V_10 -> V_29 -> V_30 . V_31 ;
int V_32 = 1 , V_33 = 5 , V_34 = V_26 ;
int V_35 = - 1 , V_36 ;
struct V_37 * V_38 ;
struct V_1 * V_1 = F_11 ( V_10 ) ;
int V_39 , V_2 , V_3 , V_40 ;
struct V_11 * V_12 ;
T_1 V_19 = F_5 ( V_10 ) ;
T_2 V_41 , V_42 ;
if ( V_34 ) {
V_43:
V_38 = & V_28 -> V_44 [ F_12 ( V_1 , V_34 ,
V_28 -> V_45 ) ] ;
F_13 ( & V_38 -> V_7 ) ;
F_14 (tb, &head->chain)
if ( F_15 ( F_16 ( V_12 ) , V_1 ) && V_12 -> V_34 == V_34 )
goto V_46;
goto V_47;
}
V_48:
V_40 = ( V_10 -> V_16 == V_49 ) ? 1 : 0 ;
V_50:
F_1 ( V_1 , & V_2 , & V_3 ) ;
V_3 ++ ;
if ( V_3 - V_2 < 4 )
V_40 = 0 ;
if ( V_40 ) {
int V_51 = V_2 + ( ( ( V_3 - V_2 ) >> 2 ) << 1 ) ;
if ( V_40 == 1 )
V_3 = V_51 ;
else
V_2 = V_51 ;
}
V_41 = V_3 - V_2 ;
if ( F_17 ( V_41 > 1 ) )
V_41 &= ~ 1U ;
V_42 = F_18 () % V_41 ;
V_42 |= 1U ;
V_35 = - 1 ;
V_36 = V_2 ;
V_52:
V_34 = V_2 + V_42 ;
for ( V_39 = 0 ; V_39 < V_41 ; V_39 += 2 , V_34 += 2 ) {
if ( F_19 ( V_34 >= V_3 ) )
V_34 -= V_41 ;
if ( F_20 ( V_1 , V_34 ) )
continue;
V_38 = & V_28 -> V_44 [ F_12 ( V_1 , V_34 ,
V_28 -> V_45 ) ] ;
F_13 ( & V_38 -> V_7 ) ;
F_14 (tb, &head->chain)
if ( F_15 ( F_16 ( V_12 ) , V_1 ) && V_12 -> V_34 == V_34 ) {
if ( ( ( V_12 -> V_53 > 0 && V_15 ) ||
( V_12 -> V_54 > 0 &&
V_10 -> V_18 &&
! F_8 ( V_10 -> V_23 ) &&
F_9 ( V_12 -> V_55 , V_19 ) ) ) &&
( V_12 -> V_56 < V_35 || V_35 == - 1 ) ) {
V_35 = V_12 -> V_56 ;
V_36 = V_34 ;
}
if ( ! F_21 ( V_10 ) -> V_57 -> V_58 ( V_10 , V_12 , false ) )
goto V_46;
goto V_59;
}
goto V_47;
V_59:
F_22 ( & V_38 -> V_7 ) ;
F_23 () ;
}
if ( V_35 != - 1 ) {
V_34 = V_36 ;
goto V_43;
}
V_42 -- ;
if ( ! ( V_42 & 1 ) )
goto V_52;
if ( V_40 == 1 ) {
V_40 = 2 ;
goto V_50;
}
return V_32 ;
V_47:
V_12 = F_24 ( V_28 -> V_60 ,
V_1 , V_38 , V_34 ) ;
if ( ! V_12 )
goto V_61;
V_46:
if ( ! F_25 ( & V_12 -> V_62 ) ) {
if ( V_10 -> V_16 == V_63 )
goto V_64;
if ( ( ( V_12 -> V_53 > 0 && V_15 ) ||
( V_12 -> V_54 > 0 &&
! F_8 ( V_10 -> V_23 ) &&
V_10 -> V_18 && F_9 ( V_12 -> V_55 , V_19 ) ) ) &&
V_35 == - 1 )
goto V_64;
if ( F_21 ( V_10 ) -> V_57 -> V_58 ( V_10 , V_12 , true ) ) {
if ( ( V_15 ||
( V_12 -> V_54 > 0 &&
V_10 -> V_18 &&
! F_8 ( V_10 -> V_23 ) &&
F_9 ( V_12 -> V_55 , V_19 ) ) ) &&
V_35 != - 1 && -- V_33 >= 0 ) {
F_22 ( & V_38 -> V_7 ) ;
goto V_48;
}
goto V_61;
}
if ( ! V_15 )
V_12 -> V_53 = 0 ;
if ( ! V_10 -> V_18 || ! F_9 ( V_12 -> V_55 , V_19 ) )
V_12 -> V_54 = 0 ;
} else {
V_12 -> V_53 = V_15 ;
if ( V_10 -> V_18 ) {
V_12 -> V_54 = 1 ;
V_12 -> V_55 = V_19 ;
} else {
V_12 -> V_54 = 0 ;
}
}
V_64:
if ( ! F_21 ( V_10 ) -> V_65 )
F_26 ( V_10 , V_12 , V_34 ) ;
F_27 ( F_21 ( V_10 ) -> V_65 != V_12 ) ;
V_32 = 0 ;
V_61:
F_22 ( & V_38 -> V_7 ) ;
return V_32 ;
}
static int F_28 ( struct V_9 * V_10 , long V_66 )
{
struct V_67 * V_68 = F_21 ( V_10 ) ;
F_29 ( V_69 ) ;
int V_70 ;
for (; ; ) {
F_30 ( F_31 ( V_10 ) , & V_69 ,
V_71 ) ;
F_32 ( V_10 ) ;
if ( F_33 ( & V_68 -> V_72 ) )
V_66 = F_34 ( V_66 ) ;
F_35 () ;
F_36 ( V_10 ) ;
V_70 = 0 ;
if ( ! F_33 ( & V_68 -> V_72 ) )
break;
V_70 = - V_73 ;
if ( V_10 -> V_21 != V_22 )
break;
V_70 = F_37 ( V_66 ) ;
if ( F_38 ( V_74 ) )
break;
V_70 = - V_75 ;
if ( ! V_66 )
break;
}
F_39 ( F_31 ( V_10 ) , & V_69 ) ;
return V_70 ;
}
struct V_9 * F_40 ( struct V_9 * V_10 , int V_76 , int * V_70 )
{
struct V_67 * V_68 = F_21 ( V_10 ) ;
struct V_77 * V_78 = & V_68 -> V_72 ;
struct V_79 * V_80 ;
struct V_9 * V_81 ;
int error ;
F_36 ( V_10 ) ;
error = - V_73 ;
if ( V_10 -> V_21 != V_22 )
goto V_82;
if ( F_33 ( V_78 ) ) {
long V_66 = F_41 ( V_10 , V_76 & V_83 ) ;
error = - V_75 ;
if ( ! V_66 )
goto V_82;
error = F_28 ( V_10 , V_66 ) ;
if ( error )
goto V_82;
}
V_80 = F_42 ( V_78 , V_10 ) ;
V_81 = V_80 -> V_10 ;
if ( V_10 -> V_84 == V_85 &&
F_43 ( V_80 ) -> V_86 ) {
F_13 ( & V_78 -> V_87 . V_7 ) ;
if ( F_43 ( V_80 ) -> V_86 ) {
V_80 -> V_10 = NULL ;
V_80 = NULL ;
}
F_22 ( & V_78 -> V_87 . V_7 ) ;
}
V_88:
F_32 ( V_10 ) ;
if ( V_80 )
F_44 ( V_80 ) ;
return V_81 ;
V_82:
V_81 = NULL ;
V_80 = NULL ;
* V_70 = error ;
goto V_88;
}
void F_45 ( struct V_9 * V_10 ,
void (* F_46)( unsigned long ) ,
void (* F_47)( unsigned long ) ,
void (* F_48)( unsigned long ) )
{
struct V_67 * V_68 = F_21 ( V_10 ) ;
F_49 ( & V_68 -> V_89 , F_46 ,
( unsigned long ) V_10 ) ;
F_49 ( & V_68 -> V_90 , F_47 ,
( unsigned long ) V_10 ) ;
F_49 ( & V_10 -> V_91 , F_48 , ( unsigned long ) V_10 ) ;
V_68 -> V_92 = V_68 -> V_93 . V_94 = 0 ;
}
void F_50 ( struct V_9 * V_10 )
{
struct V_67 * V_68 = F_21 ( V_10 ) ;
V_68 -> V_92 = V_68 -> V_93 . V_94 = V_68 -> V_93 . V_95 = 0 ;
F_51 ( V_10 , & V_68 -> V_89 ) ;
F_51 ( V_10 , & V_68 -> V_90 ) ;
F_51 ( V_10 , & V_10 -> V_91 ) ;
}
void F_52 ( struct V_9 * V_10 )
{
F_51 ( V_10 , & V_10 -> V_91 ) ;
}
void F_53 ( struct V_9 * V_10 , unsigned long V_96 )
{
F_54 ( V_10 , & V_10 -> V_91 , V_97 + V_96 ) ;
}
struct V_98 * F_55 ( const struct V_9 * V_10 ,
struct V_99 * V_100 ,
const struct V_79 * V_80 )
{
const struct V_101 * V_102 = F_56 ( V_80 ) ;
struct V_1 * V_1 = F_57 ( & V_102 -> V_103 ) ;
struct V_104 * V_105 = V_102 -> V_105 ;
struct V_106 * V_107 ;
F_58 ( V_100 , V_102 -> V_108 , V_102 -> V_109 ,
F_59 ( V_10 ) , V_110 ,
V_10 -> V_84 , F_60 ( V_10 ) ,
( V_105 && V_105 -> V_105 . V_111 ) ? V_105 -> V_105 . V_112 : V_102 -> V_113 ,
V_102 -> V_114 , V_102 -> V_115 ,
F_61 ( V_102 -> V_116 ) ) ;
F_62 ( V_80 , F_63 ( V_100 ) ) ;
V_107 = F_64 ( V_1 , V_100 , V_10 ) ;
if ( F_65 ( V_107 ) )
goto V_117;
if ( V_105 && V_105 -> V_105 . V_118 && V_107 -> V_119 )
goto V_120;
return & V_107 -> V_121 ;
V_120:
F_66 ( V_107 ) ;
V_117:
F_67 ( V_1 , V_122 ) ;
return NULL ;
}
struct V_98 * F_68 ( const struct V_9 * V_10 ,
struct V_9 * V_81 ,
const struct V_79 * V_80 )
{
const struct V_101 * V_102 = F_56 ( V_80 ) ;
struct V_1 * V_1 = F_57 ( & V_102 -> V_103 ) ;
struct V_123 * V_124 = F_69 ( V_81 ) ;
struct V_104 * V_105 ;
struct V_99 * V_100 ;
struct V_106 * V_107 ;
V_100 = & V_124 -> V_125 . V_126 . V_127 . V_128 ;
F_70 () ;
V_105 = F_71 ( V_124 -> V_129 ) ;
F_58 ( V_100 , V_102 -> V_108 , V_102 -> V_109 ,
F_59 ( V_10 ) , V_110 ,
V_10 -> V_84 , F_60 ( V_10 ) ,
( V_105 && V_105 -> V_105 . V_111 ) ? V_105 -> V_105 . V_112 : V_102 -> V_113 ,
V_102 -> V_114 , V_102 -> V_115 ,
F_61 ( V_102 -> V_116 ) ) ;
F_62 ( V_80 , F_63 ( V_100 ) ) ;
V_107 = F_64 ( V_1 , V_100 , V_10 ) ;
if ( F_65 ( V_107 ) )
goto V_117;
if ( V_105 && V_105 -> V_105 . V_118 && V_107 -> V_119 )
goto V_120;
F_72 () ;
return & V_107 -> V_121 ;
V_120:
F_66 ( V_107 ) ;
V_117:
F_72 () ;
F_67 ( V_1 , V_122 ) ;
return NULL ;
}
static inline void F_73 ( struct V_79 * V_80 , const int V_130 ,
const int V_131 ,
const T_3 V_132 ,
int * V_133 , int * V_134 )
{
if ( ! V_132 ) {
* V_133 = V_80 -> V_135 >= V_130 ;
* V_134 = 1 ;
return;
}
* V_133 = V_80 -> V_135 >= V_130 &&
( ! F_56 ( V_80 ) -> V_136 || V_80 -> V_135 >= V_131 ) ;
* V_134 = ! F_56 ( V_80 ) -> V_136 ||
V_80 -> V_135 >= V_132 - 1 ;
}
int F_74 ( const struct V_9 * V_137 , struct V_79 * V_80 )
{
int V_70 = V_80 -> V_138 -> V_139 ( V_137 , V_80 ) ;
if ( ! V_70 )
V_80 -> V_140 ++ ;
return V_70 ;
}
static bool F_75 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
struct V_27 * V_31 = F_76 ( V_80 ) -> V_29 -> V_30 . V_31 ;
bool V_141 = false ;
if ( F_77 ( F_76 ( V_80 ) ) ) {
T_4 * V_7 = F_78 ( V_31 , V_80 -> V_142 ) ;
F_79 ( V_7 ) ;
V_141 = F_80 ( F_76 ( V_80 ) ) ;
F_81 ( V_7 ) ;
}
if ( F_82 ( & V_80 -> V_143 ) && F_83 ( & V_80 -> V_143 ) )
F_44 ( V_80 ) ;
return V_141 ;
}
void F_84 ( struct V_9 * V_10 , struct V_79 * V_80 )
{
if ( F_75 ( & F_21 ( V_10 ) -> V_72 , V_80 ) ) {
F_85 ( & F_21 ( V_10 ) -> V_72 , V_80 ) ;
F_44 ( V_80 ) ;
}
}
void F_86 ( struct V_9 * V_10 , struct V_79 * V_80 )
{
F_84 ( V_10 , V_80 ) ;
F_44 ( V_80 ) ;
}
static void F_87 ( unsigned long V_144 )
{
struct V_79 * V_80 = (struct V_79 * ) V_144 ;
struct V_9 * V_145 = V_80 -> V_146 ;
struct V_1 * V_1 = F_11 ( V_145 ) ;
struct V_67 * V_68 = F_21 ( V_145 ) ;
struct V_77 * V_78 = & V_68 -> V_72 ;
int V_147 , V_133 = 0 , V_134 = 0 ;
int V_131 , V_130 ;
T_3 V_148 ;
if ( F_88 ( V_145 ) != V_22 )
goto V_149;
V_131 = V_68 -> V_150 ? : V_1 -> V_5 . V_151 ;
V_130 = V_131 ;
V_147 = F_89 ( V_78 ) ;
if ( ( V_147 << 1 ) > F_90 ( 8U , V_145 -> V_152 ) ) {
int V_153 = F_91 ( V_78 ) << 1 ;
while ( V_130 > 2 ) {
if ( V_147 < V_153 )
break;
V_130 -- ;
V_153 <<= 1 ;
}
}
V_148 = F_92 ( V_78 -> V_132 ) ;
if ( V_148 )
V_131 = V_148 ;
F_73 ( V_80 , V_130 , V_131 , V_148 ,
& V_133 , & V_134 ) ;
V_80 -> V_138 -> V_154 ( V_80 ) ;
if ( ! V_133 &&
( ! V_134 ||
! F_74 ( V_145 , V_80 ) ||
F_56 ( V_80 ) -> V_136 ) ) {
unsigned long V_66 ;
if ( V_80 -> V_135 ++ == 0 )
F_93 ( & V_78 -> V_153 ) ;
V_66 = F_94 ( V_155 << V_80 -> V_135 , V_156 ) ;
F_95 ( & V_80 -> V_143 , V_97 + V_66 ) ;
return;
}
V_149:
F_86 ( V_145 , V_80 ) ;
}
static void F_96 ( struct V_79 * V_80 ,
unsigned long V_157 )
{
V_80 -> V_140 = 0 ;
V_80 -> V_135 = 0 ;
V_80 -> V_10 = NULL ;
F_49 ( & V_80 -> V_143 , F_87 , ( unsigned long ) V_80 ) ;
F_95 ( & V_80 -> V_143 , V_97 + V_157 ) ;
F_97 ( F_76 ( V_80 ) , NULL ) ;
F_98 () ;
F_99 ( & V_80 -> V_158 , 2 + 1 ) ;
}
void F_100 ( struct V_9 * V_10 , struct V_79 * V_80 ,
unsigned long V_157 )
{
F_96 ( V_80 , V_157 ) ;
F_101 ( V_10 ) ;
}
struct V_9 * F_102 ( const struct V_9 * V_10 ,
const struct V_79 * V_80 ,
const T_5 V_159 )
{
struct V_9 * V_81 = F_103 ( V_10 , V_159 ) ;
if ( V_81 ) {
struct V_67 * V_160 = F_21 ( V_81 ) ;
V_81 -> V_21 = V_161 ;
V_160 -> V_65 = NULL ;
F_69 ( V_81 ) -> V_162 = F_56 ( V_80 ) -> V_115 ;
F_69 ( V_81 ) -> V_163 = F_56 ( V_80 ) -> V_116 ;
F_69 ( V_81 ) -> V_164 = F_61 ( F_56 ( V_80 ) -> V_116 ) ;
V_81 -> V_165 = V_166 ;
F_104 ( V_81 , V_167 ) ;
V_81 -> V_168 = F_56 ( V_80 ) -> V_109 ;
F_105 ( & V_81 -> V_169 ,
F_106 ( & F_56 ( V_80 ) -> V_170 ) ) ;
V_160 -> V_171 = 0 ;
V_160 -> V_172 = 0 ;
V_160 -> V_173 = 0 ;
memset ( & V_160 -> V_72 , 0 , sizeof( V_160 -> V_72 ) ) ;
F_107 ( V_81 , V_80 ) ;
}
return V_81 ;
}
void F_108 ( struct V_9 * V_10 )
{
F_27 ( V_10 -> V_21 != V_174 ) ;
F_27 ( ! F_109 ( V_10 , V_175 ) ) ;
F_27 ( ! F_110 ( V_10 ) ) ;
F_27 ( F_69 ( V_10 ) -> V_163 && ! F_21 ( V_10 ) -> V_65 ) ;
V_10 -> V_29 -> V_176 ( V_10 ) ;
F_111 ( V_10 ) ;
F_112 ( V_10 ) ;
F_113 ( V_10 ) ;
F_114 () ;
F_115 ( V_10 -> V_29 -> V_177 ) ;
F_116 () ;
F_117 ( V_10 ) ;
}
void F_118 ( struct V_9 * V_10 )
__releases( &sk->sk_lock.slock
int F_119 ( struct V_9 * V_10 , int V_178 )
{
struct V_67 * V_68 = F_21 ( V_10 ) ;
struct V_123 * V_179 = F_69 ( V_10 ) ;
int V_70 = - V_180 ;
F_120 ( & V_68 -> V_72 ) ;
V_10 -> V_152 = V_178 ;
V_10 -> V_181 = 0 ;
F_121 ( V_10 ) ;
F_122 ( V_10 , V_22 ) ;
if ( ! V_10 -> V_29 -> V_182 ( V_10 , V_179 -> V_163 ) ) {
V_179 -> V_164 = F_61 ( V_179 -> V_163 ) ;
F_123 ( V_10 ) ;
V_70 = V_10 -> V_29 -> V_183 ( V_10 ) ;
if ( F_17 ( ! V_70 ) )
return 0 ;
}
V_10 -> V_21 = V_174 ;
return V_70 ;
}
static void F_124 ( struct V_9 * V_10 , struct V_79 * V_80 ,
struct V_9 * V_184 )
{
V_10 -> V_29 -> V_185 ( V_184 , V_83 ) ;
F_125 ( V_184 ) ;
F_126 ( V_10 -> V_29 -> V_177 ) ;
if ( V_10 -> V_84 == V_85 && F_43 ( V_80 ) -> V_86 ) {
F_127 ( F_128 ( V_184 ) -> V_186 != V_80 ) ;
F_127 ( V_10 != V_80 -> V_146 ) ;
F_128 ( V_184 ) -> V_186 = NULL ;
}
F_108 ( V_184 ) ;
F_44 ( V_80 ) ;
}
struct V_9 * F_129 ( struct V_9 * V_10 ,
struct V_79 * V_80 ,
struct V_9 * V_184 )
{
struct V_77 * V_78 = & F_21 ( V_10 ) -> V_72 ;
F_79 ( & V_78 -> V_187 ) ;
if ( F_19 ( V_10 -> V_21 != V_22 ) ) {
F_124 ( V_10 , V_80 , V_184 ) ;
V_184 = NULL ;
} else {
V_80 -> V_10 = V_184 ;
V_80 -> V_188 = NULL ;
if ( V_78 -> V_189 == NULL )
V_78 -> V_189 = V_80 ;
else
V_78 -> V_190 -> V_188 = V_80 ;
V_78 -> V_190 = V_80 ;
F_130 ( V_10 ) ;
}
F_81 ( & V_78 -> V_187 ) ;
return V_184 ;
}
struct V_9 * F_131 ( struct V_9 * V_10 , struct V_9 * V_184 ,
struct V_79 * V_80 , bool V_191 )
{
if ( V_191 ) {
F_84 ( V_10 , V_80 ) ;
F_85 ( & F_21 ( V_10 ) -> V_72 , V_80 ) ;
if ( F_129 ( V_10 , V_80 , V_184 ) )
return V_184 ;
}
F_132 ( V_184 ) ;
F_117 ( V_184 ) ;
return NULL ;
}
void F_133 ( struct V_9 * V_10 )
{
struct V_67 * V_68 = F_21 ( V_10 ) ;
struct V_77 * V_78 = & V_68 -> V_72 ;
struct V_79 * V_192 , * V_80 ;
while ( ( V_80 = F_42 ( V_78 , V_10 ) ) != NULL ) {
struct V_9 * V_184 = V_80 -> V_10 ;
F_114 () ;
F_134 ( V_184 ) ;
F_27 ( F_135 ( V_184 ) ) ;
F_136 ( V_184 ) ;
F_124 ( V_10 , V_80 , V_184 ) ;
F_132 ( V_184 ) ;
F_116 () ;
F_117 ( V_184 ) ;
F_23 () ;
}
if ( V_78 -> V_87 . V_193 ) {
F_13 ( & V_78 -> V_87 . V_7 ) ;
V_80 = V_78 -> V_87 . V_193 ;
V_78 -> V_87 . V_193 = NULL ;
F_22 ( & V_78 -> V_87 . V_7 ) ;
while ( V_80 != NULL ) {
V_192 = V_80 -> V_188 ;
F_44 ( V_80 ) ;
V_80 = V_192 ;
}
}
F_137 ( V_10 -> V_181 ) ;
}
void F_138 ( struct V_9 * V_10 , struct V_194 * V_195 )
{
struct V_196 * sin = (struct V_196 * ) V_195 ;
const struct V_123 * V_179 = F_69 ( V_10 ) ;
sin -> V_197 = V_198 ;
sin -> V_199 . V_200 = V_179 -> V_201 ;
sin -> V_202 = V_179 -> V_162 ;
}
int F_139 ( struct V_9 * V_10 , int V_203 , int V_204 ,
char T_6 * V_205 , int T_6 * V_206 )
{
const struct V_67 * V_68 = F_21 ( V_10 ) ;
if ( V_68 -> V_57 -> V_207 )
return V_68 -> V_57 -> V_207 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
return V_68 -> V_57 -> V_208 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
}
int F_140 ( struct V_9 * V_10 , int V_203 , int V_204 ,
char T_6 * V_205 , unsigned int V_206 )
{
const struct V_67 * V_68 = F_21 ( V_10 ) ;
if ( V_68 -> V_57 -> V_209 )
return V_68 -> V_57 -> V_209 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
return V_68 -> V_57 -> V_210 ( V_10 , V_203 , V_204 ,
V_205 , V_206 ) ;
}
static struct V_98 * F_141 ( struct V_9 * V_10 , struct V_211 * V_126 )
{
const struct V_123 * V_179 = F_69 ( V_10 ) ;
const struct V_104 * V_129 ;
T_7 V_212 = V_179 -> V_201 ;
struct V_99 * V_100 ;
struct V_106 * V_107 ;
F_70 () ;
V_129 = F_71 ( V_179 -> V_129 ) ;
if ( V_129 && V_129 -> V_105 . V_111 )
V_212 = V_129 -> V_105 . V_112 ;
V_100 = & V_126 -> V_127 . V_128 ;
V_107 = F_142 ( F_11 ( V_10 ) , V_100 , V_10 , V_212 ,
V_179 -> V_213 , V_179 -> V_162 ,
V_179 -> V_164 , V_10 -> V_84 ,
F_59 ( V_10 ) , V_10 -> V_20 ) ;
if ( F_65 ( V_107 ) )
V_107 = NULL ;
if ( V_107 )
F_143 ( V_10 , & V_107 -> V_121 ) ;
F_72 () ;
return & V_107 -> V_121 ;
}
struct V_98 * F_144 ( struct V_9 * V_10 , T_2 V_214 )
{
struct V_98 * V_121 = F_145 ( V_10 , 0 ) ;
struct V_123 * V_179 = F_69 ( V_10 ) ;
if ( ! V_121 ) {
V_121 = F_141 ( V_10 , & V_179 -> V_125 . V_126 ) ;
if ( ! V_121 )
goto V_88;
}
V_121 -> V_215 -> V_216 ( V_121 , V_10 , NULL , V_214 ) ;
V_121 = F_145 ( V_10 , 0 ) ;
if ( ! V_121 )
V_121 = F_141 ( V_10 , & V_179 -> V_125 . V_126 ) ;
V_88:
return V_121 ;
}
