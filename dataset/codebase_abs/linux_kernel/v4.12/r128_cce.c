static int F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_2 ( V_6 , V_3 & 0x1f ) ;
return F_3 ( V_7 ) ;
}
static void F_4 ( T_1 * V_4 )
{
F_5 ( L_1 ,
( unsigned int ) F_3 ( V_8 ) ) ;
F_5 ( L_2 ,
( unsigned int ) F_3 ( V_9 ) ) ;
F_5 ( L_3 ,
( unsigned int ) F_3 ( V_10 ) ) ;
F_5 ( L_4 ,
( unsigned int ) F_3 ( V_11 ) ) ;
F_5 ( L_5 ,
( unsigned int ) F_3 ( V_12 ) ) ;
F_5 ( L_6 ,
( unsigned int ) F_3 ( V_13 ) ) ;
}
static int F_6 ( T_1 * V_4 )
{
T_2 V_14 ;
int V_15 ;
V_14 = F_3 ( V_16 ) | V_17 ;
F_7 ( V_16 , V_14 ) ;
for ( V_15 = 0 ; V_15 < V_4 -> V_18 ; V_15 ++ ) {
if ( ! ( F_3 ( V_16 ) & V_19 ) )
return 0 ;
F_8 ( 1 ) ;
}
#if V_20
F_9 ( L_7 ) ;
#endif
return - V_21 ;
}
static int F_10 ( T_1 * V_4 , int V_22 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_18 ; V_15 ++ ) {
int V_23 = F_3 ( V_8 ) & V_24 ;
if ( V_23 >= V_22 )
return 0 ;
F_8 ( 1 ) ;
}
#if V_20
F_9 ( L_7 ) ;
#endif
return - V_21 ;
}
static int F_11 ( T_1 * V_4 )
{
int V_15 , V_25 ;
V_25 = F_10 ( V_4 , 64 ) ;
if ( V_25 )
return V_25 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_18 ; V_15 ++ ) {
if ( ! ( F_3 ( V_8 ) & V_26 ) ) {
F_6 ( V_4 ) ;
return 0 ;
}
F_8 ( 1 ) ;
}
#if V_20
F_9 ( L_7 ) ;
#endif
return - V_21 ;
}
static int F_12 ( T_1 * V_4 )
{
struct V_27 * V_28 ;
const struct V_29 * V_30 ;
const T_3 * V_31 ;
int V_32 , V_15 ;
F_13 ( L_8 ) ;
V_28 = F_14 ( L_9 , 0 , NULL , 0 ) ;
if ( F_15 ( V_28 ) ) {
F_16 ( L_10 ) ;
return F_17 ( V_28 ) ;
}
V_32 = F_18 ( & V_30 , V_33 , & V_28 -> V_2 ) ;
F_19 ( V_28 ) ;
if ( V_32 ) {
F_16 ( L_11 ,
V_33 ) ;
return V_32 ;
}
if ( V_30 -> V_34 != 256 * 8 ) {
F_16 ( L_12 ,
V_30 -> V_34 , V_33 ) ;
V_32 = - V_35 ;
goto V_36;
}
F_11 ( V_4 ) ;
V_31 = ( const T_3 * ) V_30 -> V_37 ;
F_7 ( V_38 , 0 ) ;
for ( V_15 = 0 ; V_15 < 256 ; V_15 ++ ) {
F_7 ( V_39 ,
F_20 ( & V_31 [ V_15 * 2 ] ) ) ;
F_7 ( V_40 ,
F_20 ( & V_31 [ V_15 * 2 + 1 ] ) ) ;
}
V_36:
F_21 ( V_30 ) ;
return V_32 ;
}
static void F_22 ( T_1 * V_4 )
{
T_2 V_14 ;
V_14 = F_3 ( V_10 ) | V_41 ;
F_7 ( V_10 , V_14 ) ;
}
int F_23 ( T_1 * V_4 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_18 ; V_15 ++ ) {
if ( F_24 ( V_4 ) == V_4 -> V_42 . V_43 ) {
int V_44 = F_3 ( V_9 ) ;
if ( ( ( V_44 & V_45 ) >=
V_4 -> V_46 ) &&
! ( V_44 & ( V_47 |
V_48 ) ) ) {
return F_6 ( V_4 ) ;
}
}
F_8 ( 1 ) ;
}
#if V_20
F_9 ( L_7 ) ;
F_4 ( V_4 ) ;
#endif
return - V_21 ;
}
static void F_25 ( T_1 * V_4 )
{
F_11 ( V_4 ) ;
F_7 ( V_13 ,
V_4 -> V_49 | V_4 -> V_42 . V_50
| V_51 ) ;
F_3 ( V_52 ) ;
F_7 ( V_12 , V_53 ) ;
V_4 -> V_54 = 1 ;
}
static void F_26 ( T_1 * V_4 )
{
F_7 ( V_10 , 0 ) ;
F_7 ( V_11 , 0 ) ;
V_4 -> V_42 . V_43 = 0 ;
}
static void F_27 ( T_1 * V_4 )
{
F_7 ( V_12 , 0 ) ;
F_7 ( V_13 ,
V_55 | V_51 ) ;
V_4 -> V_54 = 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
T_2 V_56 , V_57 , V_58 ;
F_6 ( V_4 ) ;
V_56 = F_3 ( V_6 ) ;
V_57 = F_1 ( V_2 , V_59 ) ;
F_29 ( V_59 ,
V_57 | V_60 | V_61 ) ;
V_58 = F_3 ( V_62 ) ;
F_7 ( V_62 , V_58 | V_63 ) ;
F_3 ( V_62 ) ;
F_7 ( V_62 , V_58 & ~ V_63 ) ;
F_3 ( V_62 ) ;
F_29 ( V_59 , V_57 ) ;
F_7 ( V_6 , V_56 ) ;
F_7 ( V_62 , V_58 ) ;
F_26 ( V_4 ) ;
V_4 -> V_54 = 0 ;
F_30 ( V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 ,
T_1 * V_4 )
{
T_2 V_64 ;
T_2 V_14 ;
F_13 ( L_8 ) ;
#if F_32 ( V_65 )
if ( ! V_4 -> V_66 )
V_64 = V_4 -> V_67 -> V_68 - V_2 -> V_69 -> V_70 ;
else
#endif
V_64 = V_4 -> V_67 -> V_68 -
( unsigned long ) V_2 -> V_71 -> V_72 ;
F_7 ( V_73 , V_64 | V_74 ) ;
F_7 ( V_10 , 0 ) ;
F_7 ( V_11 , 0 ) ;
F_7 ( V_75 ,
( ( V_76 / 4 ) << V_77 )
| ( ( V_78 / 4 ) << V_79 )
| ( ( V_80 / 4 ) << V_81 )
| ( ( V_82 / 64 ) << V_83 ) ) ;
F_3 ( V_52 ) ;
V_14 = F_3 ( V_84 ) & ~ V_85 ;
F_7 ( V_84 , V_14 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_4 * V_86 )
{
T_1 * V_4 ;
int V_32 ;
F_13 ( L_8 ) ;
if ( V_2 -> V_5 ) {
F_13 ( L_13 ) ;
return - V_35 ;
}
V_4 = F_34 ( sizeof( T_1 ) , V_87 ) ;
if ( V_4 == NULL )
return - V_88 ;
V_4 -> V_66 = V_86 -> V_66 ;
if ( V_4 -> V_66 && ! V_2 -> V_71 ) {
F_9 ( L_14 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
V_4 -> V_18 = V_86 -> V_18 ;
if ( V_4 -> V_18 < 1 ||
V_4 -> V_18 > V_89 ) {
F_13 ( L_15 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
V_4 -> V_49 = V_86 -> V_49 ;
F_36 ( & V_4 -> V_90 , 0 ) ;
if ( ( V_86 -> V_49 != V_91 ) &&
( V_86 -> V_49 != V_92 ) &&
( V_86 -> V_49 != V_93 ) &&
( V_86 -> V_49 != V_94 ) ) {
F_13 ( L_16 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
switch ( V_86 -> V_49 ) {
case V_55 :
V_4 -> V_46 = 0 ;
break;
case V_95 :
case V_91 :
V_4 -> V_46 = 192 ;
break;
case V_96 :
case V_92 :
V_4 -> V_46 = 128 ;
break;
case V_97 :
case V_93 :
case V_98 :
case V_94 :
case V_99 :
V_4 -> V_46 = 64 ;
break;
}
switch ( V_86 -> V_100 ) {
case 16 :
V_4 -> V_101 = V_102 ;
break;
case 32 :
default:
V_4 -> V_101 = V_103 ;
break;
}
V_4 -> V_104 = V_86 -> V_104 ;
V_4 -> V_105 = V_86 -> V_105 ;
V_4 -> V_106 = V_86 -> V_106 ;
V_4 -> V_107 = V_86 -> V_107 ;
switch ( V_86 -> V_108 ) {
case 16 :
V_4 -> V_109 = V_102 ;
break;
case 24 :
case 32 :
default:
V_4 -> V_109 = V_103 ;
break;
}
V_4 -> V_110 = V_86 -> V_110 ;
V_4 -> V_111 = V_86 -> V_111 ;
V_4 -> V_112 = V_86 -> V_112 ;
V_4 -> V_113 = ( ( ( V_4 -> V_105 / 8 ) << 21 ) |
( V_4 -> V_104 >> 5 ) ) ;
V_4 -> V_114 = ( ( ( V_4 -> V_107 / 8 ) << 21 ) |
( V_4 -> V_106 >> 5 ) ) ;
V_4 -> V_115 = ( ( ( V_4 -> V_111 / 8 ) << 21 ) |
( V_4 -> V_110 >> 5 ) |
V_116 ) ;
V_4 -> V_117 = ( ( ( V_4 -> V_111 / 8 ) << 21 ) |
( V_4 -> V_112 >> 5 ) ) ;
V_4 -> V_118 = F_37 ( V_2 ) ;
if ( ! V_4 -> V_118 ) {
F_9 ( L_17 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
V_4 -> V_119 = F_38 ( V_2 , V_86 -> V_120 ) ;
if ( ! V_4 -> V_119 ) {
F_9 ( L_18 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
V_4 -> V_67 = F_38 ( V_2 , V_86 -> V_121 ) ;
if ( ! V_4 -> V_67 ) {
F_9 ( L_19 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
V_4 -> V_122 = F_38 ( V_2 , V_86 -> V_123 ) ;
if ( ! V_4 -> V_122 ) {
F_9 ( L_20 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
V_2 -> V_124 = V_86 -> V_125 ;
V_2 -> V_126 = F_38 ( V_2 , V_86 -> V_125 ) ;
if ( ! V_2 -> V_126 ) {
F_9 ( L_21 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
if ( ! V_4 -> V_66 ) {
V_4 -> V_127 =
F_38 ( V_2 , V_86 -> V_128 ) ;
if ( ! V_4 -> V_127 ) {
F_9 ( L_22 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_35 ;
}
}
V_4 -> V_129 =
( V_130 * ) ( ( V_131 * ) V_4 -> V_118 -> V_132 +
V_86 -> V_133 ) ;
#if F_32 ( V_65 )
if ( ! V_4 -> V_66 ) {
F_39 ( V_4 -> V_67 , V_2 ) ;
F_39 ( V_4 -> V_122 , V_2 ) ;
F_39 ( V_2 -> V_126 , V_2 ) ;
if ( ! V_4 -> V_67 -> V_132 ||
! V_4 -> V_122 -> V_132 ||
! V_2 -> V_126 -> V_132 ) {
F_9 ( L_23 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_88 ;
}
} else
#endif
{
V_4 -> V_67 -> V_132 =
( void * ) ( unsigned long ) V_4 -> V_67 -> V_68 ;
V_4 -> V_122 -> V_132 =
( void * ) ( unsigned long ) V_4 -> V_122 -> V_68 ;
V_2 -> V_126 -> V_132 =
( void * ) ( unsigned long ) V_2 -> V_126 -> V_68 ;
}
#if F_32 ( V_65 )
if ( ! V_4 -> V_66 )
V_4 -> V_134 = V_2 -> V_69 -> V_70 ;
else
#endif
V_4 -> V_134 = ( unsigned long ) V_2 -> V_71 -> V_72 ;
V_4 -> V_42 . V_135 = ( T_2 * ) V_4 -> V_67 -> V_132 ;
V_4 -> V_42 . V_136 = ( ( T_2 * ) V_4 -> V_67 -> V_132
+ V_86 -> V_137 / sizeof( T_2 ) ) ;
V_4 -> V_42 . V_34 = V_86 -> V_137 ;
V_4 -> V_42 . V_50 = F_40 ( V_86 -> V_137 / 8 ) ;
V_4 -> V_42 . V_138 = ( V_4 -> V_42 . V_34 / sizeof( T_2 ) ) - 1 ;
V_4 -> V_42 . V_139 = 128 ;
V_4 -> V_129 -> V_140 = 0 ;
F_7 ( V_141 , V_4 -> V_129 -> V_140 ) ;
V_4 -> V_129 -> V_142 = 0 ;
F_7 ( V_143 , V_4 -> V_129 -> V_142 ) ;
#if F_32 ( V_65 )
if ( V_4 -> V_66 ) {
#endif
V_4 -> V_144 . V_145 = F_41 ( 32 ) ;
V_4 -> V_144 . V_146 = V_147 ;
V_4 -> V_144 . V_148 = V_149 ;
V_4 -> V_144 . V_3 = NULL ;
V_4 -> V_144 . V_150 = 0 ;
V_4 -> V_144 . V_151 = V_152 ;
if ( ! F_42 ( V_2 , & V_4 -> V_144 ) ) {
F_9 ( L_24 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_35 ( V_2 ) ;
return - V_88 ;
}
F_7 ( V_153 , V_4 -> V_144 . V_150 ) ;
#if F_32 ( V_65 )
}
#endif
F_31 ( V_2 , V_4 ) ;
V_32 = F_12 ( V_4 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_28 ( V_2 ) ;
if ( V_32 ) {
F_9 ( L_25 ) ;
F_35 ( V_2 ) ;
}
return V_32 ;
}
int F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_154 )
F_43 ( V_2 ) ;
if ( V_2 -> V_5 ) {
T_1 * V_4 = V_2 -> V_5 ;
#if F_32 ( V_65 )
if ( ! V_4 -> V_66 ) {
if ( V_4 -> V_67 != NULL )
F_44 ( V_4 -> V_67 , V_2 ) ;
if ( V_4 -> V_122 != NULL )
F_44 ( V_4 -> V_122 , V_2 ) ;
if ( V_2 -> V_126 != NULL ) {
F_44 ( V_2 -> V_126 , V_2 ) ;
V_2 -> V_126 = NULL ;
}
} else
#endif
{
if ( V_4 -> V_144 . V_150 )
if ( ! F_45 ( V_2 ,
& V_4 -> V_144 ) )
F_9
( L_26 ) ;
}
F_46 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
T_4 * V_86 = V_37 ;
F_13 ( L_8 ) ;
F_48 ( V_2 , V_156 ) ;
switch ( V_86 -> V_157 ) {
case V_158 :
return F_33 ( V_2 , V_86 ) ;
case V_159 :
return F_35 ( V_2 ) ;
}
return - V_35 ;
}
int F_49 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_13 ( L_8 ) ;
F_48 ( V_2 , V_156 ) ;
F_50 ( V_4 ) ;
if ( V_4 -> V_54 || V_4 -> V_49 == V_55 ) {
F_13 ( L_27 ) ;
return 0 ;
}
F_25 ( V_4 ) ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
T_1 * V_4 = V_2 -> V_5 ;
T_5 * V_160 = V_37 ;
int V_25 ;
F_13 ( L_8 ) ;
F_48 ( V_2 , V_156 ) ;
F_50 ( V_4 ) ;
if ( V_160 -> V_161 )
F_22 ( V_4 ) ;
if ( V_160 -> V_162 ) {
V_25 = F_23 ( V_4 ) ;
if ( V_25 )
return V_25 ;
}
F_27 ( V_4 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_13 ( L_8 ) ;
F_48 ( V_2 , V_156 ) ;
F_50 ( V_4 ) ;
F_26 ( V_4 ) ;
V_4 -> V_54 = 0 ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_13 ( L_8 ) ;
F_48 ( V_2 , V_156 ) ;
F_50 ( V_4 ) ;
if ( V_4 -> V_54 )
F_22 ( V_4 ) ;
return F_23 ( V_4 ) ;
}
int F_54 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
F_13 ( L_8 ) ;
F_48 ( V_2 , V_156 ) ;
F_50 ( V_2 -> V_5 ) ;
return F_28 ( V_2 ) ;
}
int F_55 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
return - V_35 ;
}
static struct V_163 * F_56 ( struct V_1 * V_2 )
{
struct V_164 * V_165 = V_2 -> V_165 ;
T_1 * V_4 = V_2 -> V_5 ;
T_6 * V_166 ;
struct V_163 * V_167 ;
int V_15 , V_168 ;
for ( V_15 = 0 ; V_15 < V_165 -> V_169 ; V_15 ++ ) {
V_167 = V_165 -> V_170 [ V_15 ] ;
V_166 = V_167 -> V_5 ;
if ( ! V_167 -> V_156 )
return V_167 ;
}
for ( V_168 = 0 ; V_168 < V_4 -> V_18 ; V_168 ++ ) {
T_2 V_171 = F_3 ( V_143 ) ;
for ( V_15 = 0 ; V_15 < V_165 -> V_169 ; V_15 ++ ) {
V_167 = V_165 -> V_170 [ V_15 ] ;
V_166 = V_167 -> V_5 ;
if ( V_167 -> V_172 && V_166 -> V_173 <= V_171 ) {
V_167 -> V_172 = 0 ;
return V_167 ;
}
}
F_8 ( 1 ) ;
}
F_13 ( L_28 ) ;
return NULL ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_164 * V_165 = V_2 -> V_165 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_165 -> V_169 ; V_15 ++ ) {
struct V_163 * V_167 = V_165 -> V_170 [ V_15 ] ;
T_6 * V_166 = V_167 -> V_5 ;
V_166 -> V_173 = 0 ;
}
}
int F_57 ( T_1 * V_4 , int V_174 )
{
T_7 * V_42 = & V_4 -> V_42 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_18 ; V_15 ++ ) {
F_58 ( V_4 ) ;
if ( V_42 -> V_175 >= V_174 )
return 0 ;
F_8 ( 1 ) ;
}
F_9 ( L_7 ) ;
return - V_21 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_155 * V_156 ,
struct V_176 * V_177 )
{
int V_15 ;
struct V_163 * V_167 ;
for ( V_15 = V_177 -> V_178 ; V_15 < V_177 -> V_179 ; V_15 ++ ) {
V_167 = F_56 ( V_2 ) ;
if ( ! V_167 )
return - V_180 ;
V_167 -> V_156 = V_156 ;
if ( F_60 ( & V_177 -> V_181 [ V_15 ] , & V_167 -> V_182 ,
sizeof( V_167 -> V_182 ) ) )
return - V_183 ;
if ( F_60 ( & V_177 -> V_184 [ V_15 ] , & V_167 -> V_185 ,
sizeof( V_167 -> V_185 ) ) )
return - V_183 ;
V_177 -> V_178 ++ ;
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 , void * V_37 , struct V_155 * V_156 )
{
struct V_164 * V_165 = V_2 -> V_165 ;
int V_25 = 0 ;
struct V_176 * V_177 = V_37 ;
F_48 ( V_2 , V_156 ) ;
if ( V_177 -> V_186 != 0 ) {
F_9 ( L_29 ,
V_187 , V_177 -> V_186 ) ;
return - V_35 ;
}
if ( V_177 -> V_179 < 0 || V_177 -> V_179 > V_165 -> V_169 ) {
F_9 ( L_30 ,
V_187 , V_177 -> V_179 , V_165 -> V_169 ) ;
return - V_35 ;
}
V_177 -> V_178 = 0 ;
if ( V_177 -> V_179 )
V_25 = F_59 ( V_2 , V_156 , V_177 ) ;
return V_25 ;
}
