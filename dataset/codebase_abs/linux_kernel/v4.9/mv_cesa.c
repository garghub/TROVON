static void F_1 ( unsigned long V_1 )
{
int V_2 = F_2 ( V_3 -> V_4 + V_5 ) & V_6 ;
F_3 (KERN_ERR MV_CESA
L_1 ,
active ? L_2 : L_3 ) ;
F_4 ( & V_3 -> V_7 ) ;
F_5 ( V_8 , V_3 -> V_4 + V_5 ) ;
while( F_2 ( V_3 -> V_4 + V_5 ) & V_8 )
F_3 (KERN_INFO MV_CESA L_4 , __func__) ;
V_3 -> V_9 = V_10 ;
F_6 ( V_3 -> V_11 ) ;
}
static void F_7 ( void )
{
F_8 ( & V_3 -> V_7 , & F_1 , 0 ) ;
F_9 ( & V_3 -> V_7 ,
V_12 + F_10 ( V_13 ) ) ;
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_16 V_17 ;
int V_18 ;
if ( ! V_15 -> V_19 )
return;
F_12 ( & V_17 , V_15 -> V_20 , V_15 -> V_21 ) ;
V_18 = V_15 -> V_21 + 24 ;
memcpy ( V_15 -> V_22 , & V_17 . V_23 [ V_18 ] , 4 * 4 ) ;
switch ( V_15 -> V_21 ) {
case V_24 :
V_18 -= 2 ;
case V_25 :
V_18 -= 2 ;
memcpy ( & V_15 -> V_22 [ 4 ] , & V_17 . V_23 [ V_18 ] ,
4 * 4 ) ;
break;
}
V_15 -> V_19 = 0 ;
}
static int F_13 ( struct V_26 * V_27 , const T_1 * V_28 ,
unsigned int V_29 )
{
struct V_30 * V_31 = F_14 ( V_27 ) ;
struct V_14 * V_15 = F_15 ( V_31 ) ;
switch ( V_29 ) {
case V_32 :
case V_25 :
case V_24 :
break;
default:
F_16 ( V_27 , V_33 ) ;
return - V_34 ;
}
V_15 -> V_21 = V_29 ;
V_15 -> V_19 = 1 ;
memcpy ( V_15 -> V_20 , V_28 , V_35 ) ;
return 0 ;
}
static void F_17 ( struct V_36 * V_37 , char * V_38 , int V_29 )
{
int V_39 ;
void * V_40 ;
int V_41 ;
while ( V_29 ) {
if ( ! V_37 -> V_42 ) {
V_39 = F_18 ( & V_37 -> V_43 ) ;
F_19 ( ! V_39 ) ;
V_37 -> V_42 = V_37 -> V_43 . V_44 ;
V_37 -> V_45 = 0 ;
}
V_40 = V_37 -> V_43 . V_46 + V_37 -> V_45 ;
V_41 = F_20 ( V_37 -> V_42 , V_29 ) ;
memcpy ( V_38 , V_40 , V_41 ) ;
V_37 -> V_45 += V_41 ;
V_37 -> V_42 -= V_41 ;
V_29 -= V_41 ;
V_38 += V_41 ;
}
}
static void F_21 ( void )
{
struct V_36 * V_37 = & V_3 -> V_37 ;
int V_47 =
F_20 ( V_37 -> V_48 - V_37 -> V_49 , V_3 -> V_50 ) ;
F_17 ( V_37 , V_3 -> V_51 + V_52 + V_37 -> V_53 ,
V_47 - V_37 -> V_53 ) ;
V_37 -> V_53 = V_47 ;
}
static void F_22 ( int V_54 )
{
struct V_55 * V_56 = F_23 ( V_3 -> V_57 ) ;
struct V_14 * V_15 = F_15 ( V_56 -> V_58 . V_31 ) ;
struct V_59 * V_60 = F_24 ( V_56 ) ;
struct V_61 V_62 ;
switch ( V_60 -> V_62 ) {
case V_63 :
V_62 . V_64 = V_65 | V_66 | V_67 ;
break;
case V_68 :
default:
V_62 . V_64 = V_65 | V_66 | V_69 ;
V_62 . V_70 = F_25 ( V_71 ) |
F_26 ( V_72 ) ;
if ( V_54 )
memcpy ( V_3 -> V_51 + V_71 , V_56 -> V_73 , 16 ) ;
break;
}
if ( V_60 -> V_74 ) {
V_62 . V_64 |= V_75 ;
memcpy ( V_3 -> V_51 + V_76 , V_15 -> V_22 ,
V_35 ) ;
} else {
V_62 . V_64 |= V_77 ;
memcpy ( V_3 -> V_51 + V_76 , V_15 -> V_20 ,
V_35 ) ;
}
switch ( V_15 -> V_21 ) {
case V_32 :
V_62 . V_64 |= V_78 ;
break;
case V_25 :
V_62 . V_64 |= V_79 ;
break;
case V_24 :
V_62 . V_64 |= V_80 ;
break;
}
V_62 . V_81 = F_27 ( V_52 ) |
F_28 ( V_82 ) ;
V_62 . V_83 = V_76 ;
F_21 () ;
V_62 . V_84 = V_3 -> V_37 . V_53 ;
memcpy ( V_3 -> V_51 + V_85 , & V_62 ,
sizeof( struct V_61 ) ) ;
F_7 () ;
F_5 ( V_6 , V_3 -> V_4 + V_5 ) ;
}
static void F_29 ( void )
{
struct V_55 * V_56 = F_23 ( V_3 -> V_57 ) ;
struct V_59 * V_60 = F_24 ( V_56 ) ;
F_30 ( & V_3 -> V_37 . V_43 ) ;
F_30 ( & V_3 -> V_37 . V_86 ) ;
if ( V_60 -> V_62 != V_68 )
return ;
memcpy ( V_56 -> V_73 , V_3 -> V_51 + V_72 , 16 ) ;
}
static void F_31 ( int V_54 )
{
struct V_87 * V_56 = F_32 ( V_3 -> V_57 ) ;
const struct V_88 * V_89 = F_15 ( V_56 -> V_58 . V_31 ) ;
struct V_90 * V_60 = F_33 ( V_56 ) ;
struct V_36 * V_37 = & V_3 -> V_37 ;
struct V_61 V_62 = { 0 } ;
int V_91 ;
switch ( V_60 -> V_62 ) {
case V_92 :
default:
V_62 . V_64 = V_93 | V_94 ;
break;
case V_95 :
V_62 . V_64 = V_93 | V_96 ;
memcpy ( V_3 -> V_51 + V_97 ,
V_89 -> V_98 , sizeof( V_89 -> V_98 ) ) ;
break;
}
V_62 . V_99 =
F_34 ( V_52 ) | F_35 ( ( V_100 )
V_60 ->
V_101 ) ;
F_21 () ;
V_62 . V_102 =
F_36 ( V_103 ) | F_37 ( V_37 -> V_53 ) ;
V_62 . V_104 =
F_38 ( V_97 ) |
F_39 ( V_105 ) ;
V_91 = V_60 -> V_106
&& ( V_37 -> V_49 + V_37 -> V_53 >= V_37 -> V_48 )
&& ( V_60 -> V_101 <= V_107 ) ;
if ( V_60 -> V_108 ) {
if ( V_91 )
V_62 . V_64 |= V_109 ;
else
V_62 . V_64 |= V_110 ;
V_60 -> V_108 = 0 ;
} else {
if ( V_91 )
V_62 . V_64 |= V_111 ;
else
V_62 . V_64 |= V_112 ;
if ( V_54 ) {
F_5 ( V_60 -> V_113 [ 0 ] , V_3 -> V_4 + V_114 ) ;
F_5 ( V_60 -> V_113 [ 1 ] , V_3 -> V_4 + V_115 ) ;
F_5 ( V_60 -> V_113 [ 2 ] , V_3 -> V_4 + V_116 ) ;
F_5 ( V_60 -> V_113 [ 3 ] , V_3 -> V_4 + V_117 ) ;
F_5 ( V_60 -> V_113 [ 4 ] , V_3 -> V_4 + V_118 ) ;
}
}
memcpy ( V_3 -> V_51 + V_85 , & V_62 , sizeof( struct V_61 ) ) ;
F_7 () ;
F_5 ( V_6 , V_3 -> V_4 + V_5 ) ;
}
static inline int F_40 ( const struct V_90 * V_15 ,
struct V_119 * V_120 )
{
int V_121 ;
struct V_122 V_123 ;
V_123 . V_101 = V_15 -> V_101 + V_15 -> V_124 ;
for ( V_121 = 0 ; V_121 < 5 ; V_121 ++ )
V_123 . V_113 [ V_121 ] = V_15 -> V_113 [ V_121 ] ;
memcpy ( V_123 . V_125 , V_15 -> V_125 , sizeof( V_123 . V_125 ) ) ;
return F_41 ( V_120 , & V_123 ) ;
}
static int F_42 ( struct V_87 * V_56 )
{
const struct V_88 * V_89 = F_15 ( V_56 -> V_58 . V_31 ) ;
struct V_90 * V_60 = F_33 ( V_56 ) ;
F_43 ( V_126 , V_89 -> V_127 ) ;
int V_128 ;
V_126 -> V_31 = V_89 -> V_127 ;
V_126 -> V_129 = V_130 ;
if ( F_44 ( V_60 -> V_108 ) ) {
F_45 ( V_126 ) ;
F_46 ( V_126 , V_60 -> V_125 ,
V_60 -> V_131 ) ;
} else {
V_128 = F_40 ( V_60 , V_126 ) ;
if ( V_128 )
goto V_132;
}
V_128 = F_47 ( V_126 , V_56 -> V_133 ) ;
V_132:
return V_128 ;
}
static void F_48 ( struct V_90 * V_15 )
{
V_15 -> V_113 [ 0 ] = F_2 ( V_3 -> V_4 + V_114 ) ;
V_15 -> V_113 [ 1 ] = F_2 ( V_3 -> V_4 + V_115 ) ;
V_15 -> V_113 [ 2 ] = F_2 ( V_3 -> V_4 + V_116 ) ;
V_15 -> V_113 [ 3 ] = F_2 ( V_3 -> V_4 + V_117 ) ;
V_15 -> V_113 [ 4 ] = F_2 ( V_3 -> V_4 + V_118 ) ;
}
static void F_49 ( void )
{
struct V_87 * V_56 = F_32 ( V_3 -> V_57 ) ;
struct V_90 * V_15 = F_33 ( V_56 ) ;
if ( V_15 -> V_131 )
F_17 ( & V_3 -> V_37 , V_15 -> V_125 , V_15 -> V_131 ) ;
F_30 ( & V_3 -> V_37 . V_43 ) ;
if ( F_50 ( V_15 -> V_106 ) ) {
if ( F_50 ( V_15 -> V_101 <= V_107 ) ) {
memcpy ( V_56 -> V_133 , V_3 -> V_51 + V_103 ,
F_51 ( F_52
( V_56 ) ) ) ;
} else {
F_48 ( V_15 ) ;
F_42 ( V_56 ) ;
}
} else {
F_48 ( V_15 ) ;
}
}
static void F_53 ( void )
{
struct V_134 * V_56 = V_3 -> V_57 ;
void * V_135 ;
int V_39 ;
V_3 -> V_37 . V_49 += V_3 -> V_37 . V_53 ;
if ( V_3 -> V_37 . V_136 ) {
int V_137 = V_3 -> V_37 . V_53 ;
int V_138 = 0 ;
do {
int V_139 ;
if ( ! V_3 -> V_37 . V_140 ) {
V_39 = F_18 ( & V_3 -> V_37 . V_86 ) ;
F_19 ( ! V_39 ) ;
V_3 -> V_37 . V_140 = V_3 -> V_37 . V_86 . V_44 ;
V_3 -> V_37 . V_141 = 0 ;
}
V_135 = V_3 -> V_37 . V_86 . V_46 ;
V_135 += V_3 -> V_37 . V_141 ;
V_139 = F_20 ( V_137 , V_3 -> V_37 . V_140 ) ;
memcpy ( V_135 ,
V_3 -> V_51 + V_82 + V_138 ,
V_139 ) ;
V_138 += V_139 ;
V_3 -> V_37 . V_140 -= V_139 ;
V_137 -= V_139 ;
V_3 -> V_37 . V_141 += V_139 ;
} while ( V_137 > 0 );
}
V_3 -> V_37 . V_53 = 0 ;
F_19 ( V_3 -> V_9 != V_10 ) ;
if ( V_3 -> V_37 . V_49 < V_3 -> V_37 . V_48 ) {
V_3 -> V_9 = V_142 ;
V_3 -> V_37 . V_143 ( 0 ) ;
} else {
V_3 -> V_37 . V_144 () ;
V_3 -> V_9 = V_145 ;
F_54 () ;
V_56 -> V_144 ( V_56 , 0 ) ;
F_55 () ;
}
}
static int F_56 ( struct V_146 * V_147 , unsigned int V_148 )
{
int V_121 = 0 ;
T_2 V_149 ;
while ( V_147 ) {
V_149 = V_147 [ V_121 ] . V_44 ;
++ V_121 ;
if ( V_148 > V_149 )
V_148 -= V_149 ;
else
break;
}
return V_121 ;
}
static void F_57 ( struct V_55 * V_56 )
{
struct V_36 * V_37 = & V_3 -> V_37 ;
int V_150 ;
V_3 -> V_57 = & V_56 -> V_58 ;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 -> V_48 = V_56 -> V_151 ;
V_37 -> V_144 = F_29 ;
V_37 -> V_143 = F_22 ;
V_37 -> V_136 = 1 ;
V_150 = F_56 ( V_56 -> V_152 , V_56 -> V_151 ) ;
F_58 ( & V_37 -> V_43 , V_56 -> V_152 , V_150 , V_153 ) ;
V_150 = F_56 ( V_56 -> V_154 , V_56 -> V_151 ) ;
F_58 ( & V_37 -> V_86 , V_56 -> V_154 , V_150 , V_155 ) ;
F_22 ( 1 ) ;
}
static void F_59 ( struct V_87 * V_56 )
{
struct V_36 * V_37 = & V_3 -> V_37 ;
struct V_90 * V_15 = F_33 ( V_56 ) ;
int V_150 , V_156 , V_157 , V_128 ;
V_3 -> V_57 = & V_56 -> V_58 ;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
V_156 = V_56 -> V_151 + V_15 -> V_131 ;
V_157 = V_15 -> V_131 ;
V_15 -> V_131 = V_156 % V_158 ;
if ( V_15 -> V_131 != 0
&& ( ! V_15 -> V_106 || V_15 -> V_101 > V_107 ) )
V_156 -= V_15 -> V_131 ;
else
V_15 -> V_131 = 0 ;
V_150 = F_56 ( V_56 -> V_152 , V_56 -> V_151 ) ;
F_58 ( & V_37 -> V_43 , V_56 -> V_152 , V_150 , V_153 ) ;
if ( V_156 ) {
V_37 -> V_48 = V_156 ;
V_37 -> V_144 = F_49 ;
V_37 -> V_143 = F_31 ;
if ( F_44 ( V_157 ) ) {
memcpy ( V_3 -> V_51 + V_52 , V_15 -> V_125 ,
V_157 ) ;
V_37 -> V_53 = V_157 ;
}
F_31 ( 1 ) ;
} else {
F_17 ( V_37 , V_15 -> V_125 + V_157 ,
V_15 -> V_131 - V_157 ) ;
F_30 ( & V_37 -> V_43 ) ;
if ( V_15 -> V_106 )
V_128 = F_42 ( V_56 ) ;
else
V_128 = 0 ;
V_3 -> V_9 = V_145 ;
F_54 () ;
V_56 -> V_58 . V_144 ( & V_56 -> V_58 , V_128 ) ;
F_55 () ;
}
}
static int F_60 ( void * V_159 )
{
V_3 -> V_9 = V_145 ;
do {
struct V_134 * V_160 = NULL ;
struct V_134 * V_161 = NULL ;
F_61 ( V_162 ) ;
if ( V_3 -> V_9 == V_10 )
F_53 () ;
F_62 ( & V_3 -> V_163 ) ;
if ( V_3 -> V_9 == V_145 ) {
V_161 = F_63 ( & V_3 -> V_164 ) ;
V_160 = F_64 ( & V_3 -> V_164 ) ;
if ( V_160 ) {
F_19 ( V_3 -> V_9 != V_145 ) ;
V_3 -> V_9 = V_142 ;
}
}
F_65 ( & V_3 -> V_163 ) ;
if ( V_161 ) {
V_161 -> V_144 ( V_161 , - V_165 ) ;
V_161 = NULL ;
}
if ( V_160 ) {
if ( F_66 ( V_160 -> V_31 ) !=
V_166 ) {
struct V_55 * V_56 =
F_23 ( V_160 ) ;
F_57 ( V_56 ) ;
} else {
struct V_87 * V_56 =
F_32 ( V_160 ) ;
F_59 ( V_56 ) ;
}
V_160 = NULL ;
}
F_67 () ;
} while ( ! F_68 () );
return 0 ;
}
static int F_69 ( struct V_134 * V_56 )
{
unsigned long V_129 ;
int V_39 ;
F_70 ( & V_3 -> V_163 , V_129 ) ;
V_39 = F_71 ( & V_3 -> V_164 , V_56 ) ;
F_72 ( & V_3 -> V_163 , V_129 ) ;
F_6 ( V_3 -> V_11 ) ;
return V_39 ;
}
static int F_73 ( struct V_55 * V_56 )
{
struct V_59 * V_60 = F_24 ( V_56 ) ;
V_60 -> V_62 = V_63 ;
V_60 -> V_74 = 0 ;
return F_69 ( & V_56 -> V_58 ) ;
}
static int F_74 ( struct V_55 * V_56 )
{
struct V_14 * V_15 = F_15 ( V_56 -> V_58 . V_31 ) ;
struct V_59 * V_60 = F_24 ( V_56 ) ;
V_60 -> V_62 = V_63 ;
V_60 -> V_74 = 1 ;
F_11 ( V_15 ) ;
return F_69 ( & V_56 -> V_58 ) ;
}
static int F_75 ( struct V_55 * V_56 )
{
struct V_59 * V_60 = F_24 ( V_56 ) ;
V_60 -> V_62 = V_68 ;
V_60 -> V_74 = 0 ;
return F_69 ( & V_56 -> V_58 ) ;
}
static int F_76 ( struct V_55 * V_56 )
{
struct V_14 * V_15 = F_15 ( V_56 -> V_58 . V_31 ) ;
struct V_59 * V_60 = F_24 ( V_56 ) ;
V_60 -> V_62 = V_68 ;
V_60 -> V_74 = 1 ;
F_11 ( V_15 ) ;
return F_69 ( & V_56 -> V_58 ) ;
}
static int F_77 ( struct V_30 * V_31 )
{
V_31 -> V_167 . V_168 = sizeof( struct V_59 ) ;
return 0 ;
}
static void F_78 ( struct V_90 * V_15 , int V_62 ,
int V_91 , unsigned int V_169 ,
int V_124 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_62 = V_62 ;
V_15 -> V_101 = V_169 ;
V_15 -> V_108 = 1 ;
V_15 -> V_106 = V_91 ;
V_15 -> V_124 = V_124 ;
}
static void F_79 ( struct V_90 * V_15 , int V_91 ,
unsigned V_169 )
{
V_15 -> V_106 = V_91 ;
V_15 -> V_101 += V_169 ;
}
static int F_80 ( struct V_87 * V_56 )
{
const struct V_88 * V_89 = F_15 ( V_56 -> V_58 . V_31 ) ;
F_78 ( F_33 ( V_56 ) , V_89 -> V_62 , 0 , 0 ,
V_89 -> V_124 ) ;
return 0 ;
}
static int F_81 ( struct V_87 * V_56 )
{
if ( ! V_56 -> V_151 )
return 0 ;
F_79 ( F_33 ( V_56 ) , 0 , V_56 -> V_151 ) ;
return F_69 ( & V_56 -> V_58 ) ;
}
static int F_82 ( struct V_87 * V_56 )
{
struct V_90 * V_15 = F_33 ( V_56 ) ;
F_83 ( V_56 , NULL , V_56 -> V_133 , 0 ) ;
F_79 ( V_15 , 1 , 0 ) ;
return F_69 ( & V_56 -> V_58 ) ;
}
static int F_84 ( struct V_87 * V_56 )
{
F_79 ( F_33 ( V_56 ) , 1 , V_56 -> V_151 ) ;
return F_69 ( & V_56 -> V_58 ) ;
}
static int F_85 ( struct V_87 * V_56 )
{
const struct V_88 * V_89 = F_15 ( V_56 -> V_58 . V_31 ) ;
F_78 ( F_33 ( V_56 ) , V_89 -> V_62 , 1 ,
V_56 -> V_151 , V_89 -> V_124 ) ;
return F_69 ( & V_56 -> V_58 ) ;
}
static void F_86 ( struct V_88 * V_15 , const void * V_170 ,
const void * V_171 )
{
const struct V_122 * V_172 = V_170 , * V_173 = V_171 ;
int V_121 ;
for ( V_121 = 0 ; V_121 < 5 ; V_121 ++ ) {
V_15 -> V_98 [ V_121 ] = F_87 ( V_172 -> V_113 [ V_121 ] ) ;
V_15 -> V_98 [ V_121 + 5 ] = F_87 ( V_173 -> V_113 [ V_121 ] ) ;
}
}
static int F_88 ( struct V_174 * V_31 , const T_1 * V_28 ,
unsigned int V_175 )
{
int V_128 ;
struct V_88 * V_15 = F_15 ( & V_31 -> V_58 ) ;
int V_176 , V_177 , V_178 ;
if ( ! V_15 -> V_179 )
return 0 ;
V_128 = F_89 ( V_15 -> V_127 , V_28 , V_175 ) ;
if ( V_128 )
return V_128 ;
V_176 = F_90 ( V_15 -> V_179 ) ;
V_177 = F_91 ( V_15 -> V_179 ) ;
V_178 = F_92 ( V_15 -> V_179 ) ;
{
F_43 ( V_126 , V_15 -> V_179 ) ;
unsigned int V_121 ;
char V_180 [ V_178 ] ;
char V_181 [ V_178 ] ;
V_126 -> V_31 = V_15 -> V_179 ;
V_126 -> V_129 = F_93 ( V_15 -> V_179 ) &
V_130 ;
if ( V_175 > V_176 ) {
int V_182 ;
V_182 =
F_94 ( V_126 , V_28 , V_175 , V_180 ) ;
if ( V_182 )
return V_182 ;
V_175 = V_177 ;
} else
memcpy ( V_180 , V_28 , V_175 ) ;
memset ( V_180 + V_175 , 0 , V_176 - V_175 ) ;
memcpy ( V_181 , V_180 , V_176 ) ;
for ( V_121 = 0 ; V_121 < V_176 ; V_121 ++ ) {
V_180 [ V_121 ] ^= 0x36 ;
V_181 [ V_121 ] ^= 0x5c ;
}
V_128 = F_45 ( V_126 ) ? :
F_46 ( V_126 , V_180 , V_176 ) ? :
F_95 ( V_126 , V_180 ) ? :
F_45 ( V_126 ) ? :
F_46 ( V_126 , V_181 , V_176 ) ? :
F_95 ( V_126 , V_181 ) ;
if ( V_128 == 0 )
F_86 ( V_15 , V_180 , V_181 ) ;
return V_128 ;
}
}
static int F_96 ( struct V_30 * V_31 , const char * V_183 ,
enum V_184 V_62 , int V_124 )
{
const char * V_185 = F_97 ( V_31 ) ;
struct V_88 * V_15 = F_15 ( V_31 ) ;
struct V_186 * V_187 = NULL ;
struct V_186 * V_179 = NULL ;
int V_182 = - V_188 ;
V_15 -> V_62 = V_62 ;
V_15 -> V_124 = V_124 ;
V_187 = F_98 ( V_185 , 0 ,
V_189 ) ;
if ( F_99 ( V_187 ) ) {
F_3 (KERN_WARNING MV_CESA
L_5 ,
fallback_driver_name) ;
V_182 = F_100 ( V_187 ) ;
goto V_132;
}
V_15 -> V_127 = V_187 ;
if ( V_183 ) {
V_179 = F_98 ( V_183 , 0 ,
V_189 ) ;
if ( F_99 ( V_179 ) ) {
F_3 (KERN_WARNING MV_CESA
L_6 ,
base_hash_name) ;
V_182 = F_100 ( V_179 ) ;
goto V_190;
}
}
V_15 -> V_179 = V_179 ;
F_101 ( F_102 ( V_31 ) ,
sizeof( struct V_90 ) +
F_103 ( V_15 -> V_127 ) ) ;
return 0 ;
V_190:
F_104 ( V_187 ) ;
V_132:
return V_182 ;
}
static void F_105 ( struct V_30 * V_31 )
{
struct V_88 * V_15 = F_15 ( V_31 ) ;
F_104 ( V_15 -> V_127 ) ;
if ( V_15 -> V_179 )
F_104 ( V_15 -> V_179 ) ;
}
static int F_106 ( struct V_30 * V_31 )
{
return F_96 ( V_31 , NULL , V_92 , 0 ) ;
}
static int F_107 ( struct V_30 * V_31 )
{
return F_96 ( V_31 , L_7 , V_95 , V_158 ) ;
}
static T_3 F_108 ( int V_191 , void * V_192 )
{
V_100 V_193 ;
V_193 = F_2 ( V_3 -> V_4 + V_194 ) ;
if ( ! ( V_193 & V_195 ) )
return V_196 ;
if ( ! F_4 ( & V_3 -> V_7 ) ) {
F_3 (KERN_WARNING MV_CESA
L_8 ) ;
}
V_193 &= ~ V_195 ;
F_5 ( V_193 , V_3 -> V_4 + V_197 ) ;
F_5 ( V_193 , V_3 -> V_4 + V_194 ) ;
F_19 ( V_3 -> V_9 != V_142 ) ;
V_3 -> V_9 = V_10 ;
F_6 ( V_3 -> V_11 ) ;
return V_198 ;
}
static int F_109 ( struct V_199 * V_200 ,
struct V_201 * V_202 )
{
struct V_203 * V_204 ;
V_100 V_205 = V_206 ;
F_110 ( V_200 -> V_207 . V_208 , L_9 ,
& V_205 ) ;
V_202 -> V_205 = V_205 ;
V_202 -> V_209 = F_111 ( V_200 -> V_207 . V_208 ,
L_10 , 0 ) ;
if ( V_202 -> V_209 ) {
V_202 -> V_51 = F_112 ( V_202 -> V_209 , V_205 ,
& V_202 -> V_210 ) ;
if ( V_202 -> V_51 )
return 0 ;
return - V_188 ;
}
V_204 = F_113 ( V_200 , V_211 ,
L_11 ) ;
if ( ! V_204 || F_114 ( V_204 ) < V_202 -> V_205 )
return - V_34 ;
V_202 -> V_51 = F_115 ( & V_200 -> V_207 , V_204 ) ;
if ( F_99 ( V_202 -> V_51 ) )
return F_100 ( V_202 -> V_51 ) ;
return 0 ;
}
static int F_116 ( struct V_199 * V_200 )
{
struct V_201 * V_202 ;
struct V_203 * V_204 ;
int V_191 ;
int V_39 ;
if ( V_3 ) {
F_3 (KERN_ERR MV_CESA L_12 ) ;
return - V_212 ;
}
V_204 = F_113 ( V_200 , V_211 , L_13 ) ;
if ( ! V_204 )
return - V_213 ;
V_202 = F_117 ( sizeof( * V_202 ) , V_214 ) ;
if ( ! V_202 )
return - V_188 ;
F_118 ( & V_202 -> V_163 ) ;
F_119 ( & V_202 -> V_164 , 50 ) ;
V_202 -> V_4 = F_115 ( & V_200 -> V_207 , V_204 ) ;
if ( F_99 ( V_202 -> V_4 ) ) {
V_39 = F_100 ( V_202 -> V_4 ) ;
goto V_182;
}
V_39 = F_109 ( V_200 , V_202 ) ;
if ( V_39 )
goto V_182;
V_202 -> V_50 = V_202 -> V_205 - V_215 ;
V_191 = F_120 ( V_200 , 0 ) ;
if ( V_191 < 0 ) {
V_39 = V_191 ;
goto V_182;
}
V_202 -> V_191 = V_191 ;
F_121 ( V_200 , V_202 ) ;
V_3 = V_202 ;
V_202 -> V_11 = F_122 ( F_60 , V_202 , L_14 ) ;
if ( F_99 ( V_202 -> V_11 ) ) {
V_39 = F_100 ( V_202 -> V_11 ) ;
goto V_182;
}
V_39 = F_123 ( V_191 , F_108 , 0 , F_124 ( & V_200 -> V_207 ) ,
V_202 ) ;
if ( V_39 )
goto V_216;
V_202 -> V_217 = F_125 ( & V_200 -> V_207 , NULL ) ;
if ( ! F_99 ( V_202 -> V_217 ) )
F_126 ( V_202 -> V_217 ) ;
F_5 ( 0 , V_3 -> V_4 + V_194 ) ;
F_5 ( V_195 , V_3 -> V_4 + V_218 ) ;
F_5 ( V_219 , V_3 -> V_4 + V_220 ) ;
F_5 ( V_85 , V_3 -> V_4 + V_221 ) ;
V_39 = F_127 ( & V_222 ) ;
if ( V_39 ) {
F_3 (KERN_WARNING MV_CESA
L_15 ) ;
goto V_223;
}
V_39 = F_127 ( & V_224 ) ;
if ( V_39 ) {
F_3 (KERN_WARNING MV_CESA
L_16 ) ;
goto V_225;
}
V_39 = F_128 ( & V_226 ) ;
if ( V_39 == 0 )
V_3 -> V_227 = 1 ;
else
F_3 (KERN_WARNING MV_CESA L_17 ) ;
V_39 = F_128 ( & V_228 ) ;
if ( V_39 == 0 ) {
V_3 -> V_229 = 1 ;
} else {
F_3 (KERN_WARNING MV_CESA
L_18 ) ;
}
return 0 ;
V_225:
F_129 ( & V_222 ) ;
V_223:
F_130 ( V_191 , V_202 ) ;
if ( ! F_99 ( V_202 -> V_217 ) ) {
F_131 ( V_202 -> V_217 ) ;
F_132 ( V_202 -> V_217 ) ;
}
V_216:
F_133 ( V_202 -> V_11 ) ;
V_182:
F_134 ( V_202 ) ;
V_3 = NULL ;
return V_39 ;
}
static int F_135 ( struct V_199 * V_200 )
{
struct V_201 * V_202 = F_136 ( V_200 ) ;
F_129 ( & V_222 ) ;
F_129 ( & V_224 ) ;
if ( V_202 -> V_227 )
F_137 ( & V_226 ) ;
if ( V_202 -> V_229 )
F_137 ( & V_228 ) ;
F_133 ( V_202 -> V_11 ) ;
F_130 ( V_202 -> V_191 , V_202 ) ;
memset ( V_202 -> V_51 , 0 , V_202 -> V_205 ) ;
if ( ! F_99 ( V_202 -> V_217 ) ) {
F_131 ( V_202 -> V_217 ) ;
F_132 ( V_202 -> V_217 ) ;
}
F_134 ( V_202 ) ;
V_3 = NULL ;
return 0 ;
}
