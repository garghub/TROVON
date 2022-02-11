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
F_5 ( V_33 L_10 ) ;
return F_16 ( V_28 ) ;
}
V_32 = F_17 ( & V_30 , V_34 , & V_28 -> V_2 ) ;
F_18 ( V_28 ) ;
if ( V_32 ) {
F_5 ( V_33 L_11 ,
V_34 ) ;
return V_32 ;
}
if ( V_30 -> V_35 != 256 * 8 ) {
F_5 ( V_33
L_12 ,
V_30 -> V_35 , V_34 ) ;
V_32 = - V_36 ;
goto V_37;
}
F_11 ( V_4 ) ;
V_31 = ( const T_3 * ) V_30 -> V_38 ;
F_7 ( V_39 , 0 ) ;
for ( V_15 = 0 ; V_15 < 256 ; V_15 ++ ) {
F_7 ( V_40 ,
F_19 ( & V_31 [ V_15 * 2 ] ) ) ;
F_7 ( V_41 ,
F_19 ( & V_31 [ V_15 * 2 + 1 ] ) ) ;
}
V_37:
F_20 ( V_30 ) ;
return V_32 ;
}
static void F_21 ( T_1 * V_4 )
{
T_2 V_14 ;
V_14 = F_3 ( V_10 ) | V_42 ;
F_7 ( V_10 , V_14 ) ;
}
int F_22 ( T_1 * V_4 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_18 ; V_15 ++ ) {
if ( F_23 ( V_4 ) == V_4 -> V_43 . V_44 ) {
int V_45 = F_3 ( V_9 ) ;
if ( ( ( V_45 & V_46 ) >=
V_4 -> V_47 ) &&
! ( V_45 & ( V_48 |
V_49 ) ) ) {
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
static void F_24 ( T_1 * V_4 )
{
F_11 ( V_4 ) ;
F_7 ( V_13 ,
V_4 -> V_50 | V_4 -> V_43 . V_51
| V_52 ) ;
F_3 ( V_53 ) ;
F_7 ( V_12 , V_54 ) ;
V_4 -> V_55 = 1 ;
}
static void F_25 ( T_1 * V_4 )
{
F_7 ( V_10 , 0 ) ;
F_7 ( V_11 , 0 ) ;
V_4 -> V_43 . V_44 = 0 ;
}
static void F_26 ( T_1 * V_4 )
{
F_7 ( V_12 , 0 ) ;
F_7 ( V_13 ,
V_56 | V_52 ) ;
V_4 -> V_55 = 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
T_2 V_57 , V_58 , V_59 ;
F_6 ( V_4 ) ;
V_57 = F_3 ( V_6 ) ;
V_58 = F_1 ( V_2 , V_60 ) ;
F_28 ( V_60 ,
V_58 | V_61 | V_62 ) ;
V_59 = F_3 ( V_63 ) ;
F_7 ( V_63 , V_59 | V_64 ) ;
F_3 ( V_63 ) ;
F_7 ( V_63 , V_59 & ~ V_64 ) ;
F_3 ( V_63 ) ;
F_28 ( V_60 , V_58 ) ;
F_7 ( V_6 , V_57 ) ;
F_7 ( V_63 , V_59 ) ;
F_25 ( V_4 ) ;
V_4 -> V_55 = 0 ;
F_29 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
T_1 * V_4 )
{
T_2 V_65 ;
T_2 V_14 ;
F_13 ( L_8 ) ;
#if V_66
if ( ! V_4 -> V_67 )
V_65 = V_4 -> V_68 -> V_69 - V_2 -> V_70 -> V_71 ;
else
#endif
V_65 = V_4 -> V_68 -> V_69 -
( unsigned long ) V_2 -> V_72 -> V_73 ;
F_7 ( V_74 , V_65 | V_75 ) ;
F_7 ( V_10 , 0 ) ;
F_7 ( V_11 , 0 ) ;
F_7 ( V_76 ,
( ( V_77 / 4 ) << V_78 )
| ( ( V_79 / 4 ) << V_80 )
| ( ( V_81 / 4 ) << V_82 )
| ( ( V_83 / 64 ) << V_84 ) ) ;
F_3 ( V_53 ) ;
V_14 = F_3 ( V_85 ) & ~ V_86 ;
F_7 ( V_85 , V_14 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_4 * V_87 )
{
T_1 * V_4 ;
int V_32 ;
F_13 ( L_8 ) ;
if ( V_2 -> V_5 ) {
F_13 ( L_13 ) ;
return - V_36 ;
}
V_4 = F_32 ( sizeof( T_1 ) , V_88 ) ;
if ( V_4 == NULL )
return - V_89 ;
V_4 -> V_67 = V_87 -> V_67 ;
if ( V_4 -> V_67 && ! V_2 -> V_72 ) {
F_9 ( L_14 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
V_4 -> V_18 = V_87 -> V_18 ;
if ( V_4 -> V_18 < 1 ||
V_4 -> V_18 > V_90 ) {
F_13 ( L_15 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
V_4 -> V_50 = V_87 -> V_50 ;
F_34 ( & V_4 -> V_91 , 0 ) ;
if ( ( V_87 -> V_50 != V_92 ) &&
( V_87 -> V_50 != V_93 ) &&
( V_87 -> V_50 != V_94 ) &&
( V_87 -> V_50 != V_95 ) ) {
F_13 ( L_16 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
switch ( V_87 -> V_50 ) {
case V_56 :
V_4 -> V_47 = 0 ;
break;
case V_96 :
case V_92 :
V_4 -> V_47 = 192 ;
break;
case V_97 :
case V_93 :
V_4 -> V_47 = 128 ;
break;
case V_98 :
case V_94 :
case V_99 :
case V_95 :
case V_100 :
V_4 -> V_47 = 64 ;
break;
}
switch ( V_87 -> V_101 ) {
case 16 :
V_4 -> V_102 = V_103 ;
break;
case 32 :
default:
V_4 -> V_102 = V_104 ;
break;
}
V_4 -> V_105 = V_87 -> V_105 ;
V_4 -> V_106 = V_87 -> V_106 ;
V_4 -> V_107 = V_87 -> V_107 ;
V_4 -> V_108 = V_87 -> V_108 ;
switch ( V_87 -> V_109 ) {
case 16 :
V_4 -> V_110 = V_103 ;
break;
case 24 :
case 32 :
default:
V_4 -> V_110 = V_104 ;
break;
}
V_4 -> V_111 = V_87 -> V_111 ;
V_4 -> V_112 = V_87 -> V_112 ;
V_4 -> V_113 = V_87 -> V_113 ;
V_4 -> V_114 = ( ( ( V_4 -> V_106 / 8 ) << 21 ) |
( V_4 -> V_105 >> 5 ) ) ;
V_4 -> V_115 = ( ( ( V_4 -> V_108 / 8 ) << 21 ) |
( V_4 -> V_107 >> 5 ) ) ;
V_4 -> V_116 = ( ( ( V_4 -> V_112 / 8 ) << 21 ) |
( V_4 -> V_111 >> 5 ) |
V_117 ) ;
V_4 -> V_118 = ( ( ( V_4 -> V_112 / 8 ) << 21 ) |
( V_4 -> V_113 >> 5 ) ) ;
V_4 -> V_119 = F_35 ( V_2 ) ;
if ( ! V_4 -> V_119 ) {
F_9 ( L_17 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
V_4 -> V_120 = F_36 ( V_2 , V_87 -> V_121 ) ;
if ( ! V_4 -> V_120 ) {
F_9 ( L_18 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
V_4 -> V_68 = F_36 ( V_2 , V_87 -> V_122 ) ;
if ( ! V_4 -> V_68 ) {
F_9 ( L_19 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
V_4 -> V_123 = F_36 ( V_2 , V_87 -> V_124 ) ;
if ( ! V_4 -> V_123 ) {
F_9 ( L_20 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
V_2 -> V_125 = V_87 -> V_126 ;
V_2 -> V_127 = F_36 ( V_2 , V_87 -> V_126 ) ;
if ( ! V_2 -> V_127 ) {
F_9 ( L_21 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
if ( ! V_4 -> V_67 ) {
V_4 -> V_128 =
F_36 ( V_2 , V_87 -> V_129 ) ;
if ( ! V_4 -> V_128 ) {
F_9 ( L_22 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_36 ;
}
}
V_4 -> V_130 =
( V_131 * ) ( ( V_132 * ) V_4 -> V_119 -> V_133 +
V_87 -> V_134 ) ;
#if V_66
if ( ! V_4 -> V_67 ) {
F_37 ( V_4 -> V_68 , V_2 ) ;
F_37 ( V_4 -> V_123 , V_2 ) ;
F_37 ( V_2 -> V_127 , V_2 ) ;
if ( ! V_4 -> V_68 -> V_133 ||
! V_4 -> V_123 -> V_133 ||
! V_2 -> V_127 -> V_133 ) {
F_9 ( L_23 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_89 ;
}
} else
#endif
{
V_4 -> V_68 -> V_133 =
( void * ) ( unsigned long ) V_4 -> V_68 -> V_69 ;
V_4 -> V_123 -> V_133 =
( void * ) ( unsigned long ) V_4 -> V_123 -> V_69 ;
V_2 -> V_127 -> V_133 =
( void * ) ( unsigned long ) V_2 -> V_127 -> V_69 ;
}
#if V_66
if ( ! V_4 -> V_67 )
V_4 -> V_135 = V_2 -> V_70 -> V_71 ;
else
#endif
V_4 -> V_135 = ( unsigned long ) V_2 -> V_72 -> V_73 ;
V_4 -> V_43 . V_136 = ( T_2 * ) V_4 -> V_68 -> V_133 ;
V_4 -> V_43 . V_137 = ( ( T_2 * ) V_4 -> V_68 -> V_133
+ V_87 -> V_138 / sizeof( T_2 ) ) ;
V_4 -> V_43 . V_35 = V_87 -> V_138 ;
V_4 -> V_43 . V_51 = F_38 ( V_87 -> V_138 / 8 ) ;
V_4 -> V_43 . V_139 = ( V_4 -> V_43 . V_35 / sizeof( T_2 ) ) - 1 ;
V_4 -> V_43 . V_140 = 128 ;
V_4 -> V_130 -> V_141 = 0 ;
F_7 ( V_142 , V_4 -> V_130 -> V_141 ) ;
V_4 -> V_130 -> V_143 = 0 ;
F_7 ( V_144 , V_4 -> V_130 -> V_143 ) ;
#if V_66
if ( V_4 -> V_67 ) {
#endif
V_4 -> V_145 . V_146 = F_39 ( 32 ) ;
V_4 -> V_145 . V_147 = V_148 ;
V_4 -> V_145 . V_149 = V_150 ;
V_4 -> V_145 . V_3 = NULL ;
V_4 -> V_145 . V_151 = 0 ;
V_4 -> V_145 . V_152 = V_153 ;
if ( ! F_40 ( V_2 , & V_4 -> V_145 ) ) {
F_9 ( L_24 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_33 ( V_2 ) ;
return - V_89 ;
}
F_7 ( V_154 , V_4 -> V_145 . V_151 ) ;
#if V_66
}
#endif
F_30 ( V_2 , V_4 ) ;
V_32 = F_12 ( V_4 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_27 ( V_2 ) ;
if ( V_32 ) {
F_9 ( L_25 ) ;
F_33 ( V_2 ) ;
}
return V_32 ;
}
int F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_155 )
F_41 ( V_2 ) ;
if ( V_2 -> V_5 ) {
T_1 * V_4 = V_2 -> V_5 ;
#if V_66
if ( ! V_4 -> V_67 ) {
if ( V_4 -> V_68 != NULL )
F_42 ( V_4 -> V_68 , V_2 ) ;
if ( V_4 -> V_123 != NULL )
F_42 ( V_4 -> V_123 , V_2 ) ;
if ( V_2 -> V_127 != NULL ) {
F_42 ( V_2 -> V_127 , V_2 ) ;
V_2 -> V_127 = NULL ;
}
} else
#endif
{
if ( V_4 -> V_145 . V_151 )
if ( ! F_43 ( V_2 ,
& V_4 -> V_145 ) )
F_9
( L_26 ) ;
}
F_44 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
return 0 ;
}
int F_45 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
T_4 * V_87 = V_38 ;
F_13 ( L_8 ) ;
F_46 ( V_2 , V_157 ) ;
switch ( V_87 -> V_158 ) {
case V_159 :
return F_31 ( V_2 , V_87 ) ;
case V_160 :
return F_33 ( V_2 ) ;
}
return - V_36 ;
}
int F_47 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_13 ( L_8 ) ;
F_46 ( V_2 , V_157 ) ;
F_48 ( V_4 ) ;
if ( V_4 -> V_55 || V_4 -> V_50 == V_56 ) {
F_13 ( L_27 ) ;
return 0 ;
}
F_24 ( V_4 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
T_1 * V_4 = V_2 -> V_5 ;
T_5 * V_161 = V_38 ;
int V_25 ;
F_13 ( L_8 ) ;
F_46 ( V_2 , V_157 ) ;
F_48 ( V_4 ) ;
if ( V_161 -> V_162 )
F_21 ( V_4 ) ;
if ( V_161 -> V_163 ) {
V_25 = F_22 ( V_4 ) ;
if ( V_25 )
return V_25 ;
}
F_26 ( V_4 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_13 ( L_8 ) ;
F_46 ( V_2 , V_157 ) ;
F_48 ( V_4 ) ;
F_25 ( V_4 ) ;
V_4 -> V_55 = 0 ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
T_1 * V_4 = V_2 -> V_5 ;
F_13 ( L_8 ) ;
F_46 ( V_2 , V_157 ) ;
F_48 ( V_4 ) ;
if ( V_4 -> V_55 )
F_21 ( V_4 ) ;
return F_22 ( V_4 ) ;
}
int F_52 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
F_13 ( L_8 ) ;
F_46 ( V_2 , V_157 ) ;
F_48 ( V_2 -> V_5 ) ;
return F_27 ( V_2 ) ;
}
int F_53 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
return - V_36 ;
}
static struct V_164 * F_54 ( struct V_1 * V_2 )
{
struct V_165 * V_166 = V_2 -> V_166 ;
T_1 * V_4 = V_2 -> V_5 ;
T_6 * V_167 ;
struct V_164 * V_168 ;
int V_15 , V_169 ;
for ( V_15 = 0 ; V_15 < V_166 -> V_170 ; V_15 ++ ) {
V_168 = V_166 -> V_171 [ V_15 ] ;
V_167 = V_168 -> V_5 ;
if ( ! V_168 -> V_157 )
return V_168 ;
}
for ( V_169 = 0 ; V_169 < V_4 -> V_18 ; V_169 ++ ) {
T_2 V_172 = F_3 ( V_144 ) ;
for ( V_15 = 0 ; V_15 < V_166 -> V_170 ; V_15 ++ ) {
V_168 = V_166 -> V_171 [ V_15 ] ;
V_167 = V_168 -> V_5 ;
if ( V_168 -> V_173 && V_167 -> V_174 <= V_172 ) {
V_168 -> V_173 = 0 ;
return V_168 ;
}
}
F_8 ( 1 ) ;
}
F_13 ( L_28 ) ;
return NULL ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_165 * V_166 = V_2 -> V_166 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_166 -> V_170 ; V_15 ++ ) {
struct V_164 * V_168 = V_166 -> V_171 [ V_15 ] ;
T_6 * V_167 = V_168 -> V_5 ;
V_167 -> V_174 = 0 ;
}
}
int F_55 ( T_1 * V_4 , int V_175 )
{
T_7 * V_43 = & V_4 -> V_43 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_4 -> V_18 ; V_15 ++ ) {
F_56 ( V_4 ) ;
if ( V_43 -> V_176 >= V_175 )
return 0 ;
F_8 ( 1 ) ;
}
F_9 ( L_7 ) ;
return - V_21 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_156 * V_157 ,
struct V_177 * V_178 )
{
int V_15 ;
struct V_164 * V_168 ;
for ( V_15 = V_178 -> V_179 ; V_15 < V_178 -> V_180 ; V_15 ++ ) {
V_168 = F_54 ( V_2 ) ;
if ( ! V_168 )
return - V_181 ;
V_168 -> V_157 = V_157 ;
if ( F_58 ( & V_178 -> V_182 [ V_15 ] , & V_168 -> V_183 ,
sizeof( V_168 -> V_183 ) ) )
return - V_184 ;
if ( F_58 ( & V_178 -> V_185 [ V_15 ] , & V_168 -> V_186 ,
sizeof( V_168 -> V_186 ) ) )
return - V_184 ;
V_178 -> V_179 ++ ;
}
return 0 ;
}
int F_59 ( struct V_1 * V_2 , void * V_38 , struct V_156 * V_157 )
{
struct V_165 * V_166 = V_2 -> V_166 ;
int V_25 = 0 ;
struct V_177 * V_178 = V_38 ;
F_46 ( V_2 , V_157 ) ;
if ( V_178 -> V_187 != 0 ) {
F_9 ( L_29 ,
V_188 , V_178 -> V_187 ) ;
return - V_36 ;
}
if ( V_178 -> V_180 < 0 || V_178 -> V_180 > V_166 -> V_170 ) {
F_9 ( L_30 ,
V_188 , V_178 -> V_180 , V_166 -> V_170 ) ;
return - V_36 ;
}
V_178 -> V_179 = 0 ;
if ( V_178 -> V_180 )
V_25 = F_57 ( V_2 , V_157 , V_178 ) ;
return V_25 ;
}
