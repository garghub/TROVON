static void F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 ( & V_4 , V_2 -> V_7 , V_2 -> V_8 ) ;
V_5 = V_2 -> V_8 + 24 ;
memcpy ( V_2 -> V_9 , & V_4 . V_10 [ V_5 ] , 4 * 4 ) ;
switch ( V_2 -> V_8 ) {
case V_11 :
V_5 -= 2 ;
case V_12 :
V_5 -= 2 ;
memcpy ( & V_2 -> V_9 [ 4 ] , & V_4 . V_10 [ V_5 ] ,
4 * 4 ) ;
break;
}
V_2 -> V_6 = 0 ;
}
static int F_3 ( struct V_13 * V_14 , const T_1 * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = F_4 ( V_14 ) ;
struct V_1 * V_2 = F_5 ( V_18 ) ;
switch ( V_16 ) {
case V_19 :
case V_12 :
case V_11 :
break;
default:
F_6 ( V_14 , V_20 ) ;
return - V_21 ;
}
V_2 -> V_8 = V_16 ;
V_2 -> V_6 = 1 ;
memcpy ( V_2 -> V_7 , V_15 , V_22 ) ;
return 0 ;
}
static void F_7 ( struct V_23 * V_24 , char * V_25 , int V_16 )
{
int V_26 ;
void * V_27 ;
int V_28 ;
while ( V_16 ) {
if ( ! V_24 -> V_29 ) {
V_26 = F_8 ( & V_24 -> V_30 ) ;
F_9 ( ! V_26 ) ;
V_24 -> V_29 = V_24 -> V_30 . V_31 ;
V_24 -> V_32 = 0 ;
}
V_27 = V_24 -> V_30 . V_33 + V_24 -> V_32 ;
V_28 = F_10 ( V_24 -> V_29 , V_16 ) ;
memcpy ( V_25 , V_27 , V_28 ) ;
V_24 -> V_32 += V_28 ;
V_24 -> V_29 -= V_28 ;
V_16 -= V_28 ;
V_25 += V_28 ;
}
}
static void F_11 ( void )
{
struct V_23 * V_24 = & V_34 -> V_24 ;
int V_35 =
F_10 ( V_24 -> V_36 - V_24 -> V_37 , V_34 -> V_38 ) ;
F_7 ( V_24 , V_34 -> V_39 + V_40 + V_24 -> V_41 ,
V_35 - V_24 -> V_41 ) ;
V_24 -> V_41 = V_35 ;
}
static void F_12 ( int V_42 )
{
struct V_43 * V_44 = F_13 ( V_34 -> V_45 ) ;
struct V_1 * V_2 = F_5 ( V_44 -> V_46 . V_18 ) ;
struct V_47 * V_48 = F_14 ( V_44 ) ;
struct V_49 V_50 ;
switch ( V_48 -> V_50 ) {
case V_51 :
V_50 . V_52 = V_53 | V_54 | V_55 ;
break;
case V_56 :
default:
V_50 . V_52 = V_53 | V_54 | V_57 ;
V_50 . V_58 = F_15 ( V_59 ) |
F_16 ( V_60 ) ;
if ( V_42 )
memcpy ( V_34 -> V_39 + V_59 , V_44 -> V_61 , 16 ) ;
break;
}
if ( V_48 -> V_62 ) {
V_50 . V_52 |= V_63 ;
memcpy ( V_34 -> V_39 + V_64 , V_2 -> V_9 ,
V_22 ) ;
} else {
V_50 . V_52 |= V_65 ;
memcpy ( V_34 -> V_39 + V_64 , V_2 -> V_7 ,
V_22 ) ;
}
switch ( V_2 -> V_8 ) {
case V_19 :
V_50 . V_52 |= V_66 ;
break;
case V_12 :
V_50 . V_52 |= V_67 ;
break;
case V_11 :
V_50 . V_52 |= V_68 ;
break;
}
V_50 . V_69 = F_17 ( V_40 ) |
F_18 ( V_70 ) ;
V_50 . V_71 = V_64 ;
F_11 () ;
V_50 . V_72 = V_34 -> V_24 . V_41 ;
memcpy ( V_34 -> V_39 + V_73 , & V_50 ,
sizeof( struct V_49 ) ) ;
F_19 ( V_74 , V_34 -> V_75 + V_76 ) ;
}
static void F_20 ( void )
{
struct V_43 * V_44 = F_13 ( V_34 -> V_45 ) ;
struct V_47 * V_48 = F_14 ( V_44 ) ;
F_21 ( & V_34 -> V_24 . V_30 ) ;
F_21 ( & V_34 -> V_24 . V_77 ) ;
if ( V_48 -> V_50 != V_56 )
return ;
memcpy ( V_44 -> V_61 , V_34 -> V_39 + V_60 , 16 ) ;
}
static void F_22 ( int V_42 )
{
struct V_78 * V_44 = F_23 ( V_34 -> V_45 ) ;
const struct V_79 * V_80 = F_5 ( V_44 -> V_46 . V_18 ) ;
struct V_81 * V_48 = F_24 ( V_44 ) ;
struct V_23 * V_24 = & V_34 -> V_24 ;
struct V_49 V_50 = { 0 } ;
int V_82 ;
switch ( V_48 -> V_50 ) {
case V_83 :
default:
V_50 . V_52 = V_84 | V_85 ;
break;
case V_86 :
V_50 . V_52 = V_84 | V_87 ;
memcpy ( V_34 -> V_39 + V_88 ,
V_80 -> V_89 , sizeof( V_80 -> V_89 ) ) ;
break;
}
V_50 . V_90 =
F_25 ( V_40 ) | F_26 ( ( V_91 )
V_48 ->
V_92 ) ;
F_11 () ;
V_50 . V_93 =
F_27 ( V_94 ) | F_28 ( V_24 -> V_41 ) ;
V_50 . V_95 =
F_29 ( V_88 ) |
F_30 ( V_96 ) ;
V_82 = V_48 -> V_97
&& ( V_24 -> V_37 + V_24 -> V_41 >= V_24 -> V_36 )
&& ( V_48 -> V_92 <= V_98 ) ;
if ( V_48 -> V_99 ) {
if ( V_82 )
V_50 . V_52 |= V_100 ;
else
V_50 . V_52 |= V_101 ;
V_48 -> V_99 = 0 ;
} else {
if ( V_82 )
V_50 . V_52 |= V_102 ;
else
V_50 . V_52 |= V_103 ;
if ( V_42 ) {
F_19 ( V_48 -> V_104 [ 0 ] , V_34 -> V_75 + V_105 ) ;
F_19 ( V_48 -> V_104 [ 1 ] , V_34 -> V_75 + V_106 ) ;
F_19 ( V_48 -> V_104 [ 2 ] , V_34 -> V_75 + V_107 ) ;
F_19 ( V_48 -> V_104 [ 3 ] , V_34 -> V_75 + V_108 ) ;
F_19 ( V_48 -> V_104 [ 4 ] , V_34 -> V_75 + V_109 ) ;
}
}
memcpy ( V_34 -> V_39 + V_73 , & V_50 , sizeof( struct V_49 ) ) ;
F_19 ( V_74 , V_34 -> V_75 + V_76 ) ;
}
static inline int F_31 ( const struct V_81 * V_2 ,
struct V_110 * V_111 )
{
int V_112 ;
struct V_113 V_114 ;
V_114 . V_92 = V_2 -> V_92 + V_2 -> V_115 ;
for ( V_112 = 0 ; V_112 < 5 ; V_112 ++ )
V_114 . V_104 [ V_112 ] = V_2 -> V_104 [ V_112 ] ;
memcpy ( V_114 . V_116 , V_2 -> V_116 , sizeof( V_114 . V_116 ) ) ;
return F_32 ( V_111 , & V_114 ) ;
}
static int F_33 ( struct V_78 * V_44 )
{
const struct V_79 * V_80 = F_5 ( V_44 -> V_46 . V_18 ) ;
struct V_81 * V_48 = F_24 ( V_44 ) ;
struct {
struct V_110 V_117 ;
char V_2 [ F_34 ( V_80 -> V_118 ) ] ;
} V_111 ;
int V_119 ;
V_111 . V_117 . V_18 = V_80 -> V_118 ;
V_111 . V_117 . V_120 = V_121 ;
if ( F_35 ( V_48 -> V_99 ) ) {
F_36 ( & V_111 . V_117 ) ;
F_37 ( & V_111 . V_117 , V_48 -> V_116 ,
V_48 -> V_122 ) ;
} else {
V_119 = F_31 ( V_48 , & V_111 . V_117 ) ;
if ( V_119 )
goto V_123;
}
V_119 = F_38 ( & V_111 . V_117 , V_44 -> V_124 ) ;
V_123:
return V_119 ;
}
static void F_39 ( void )
{
struct V_78 * V_44 = F_23 ( V_34 -> V_45 ) ;
struct V_81 * V_2 = F_24 ( V_44 ) ;
if ( V_2 -> V_122 )
F_7 ( & V_34 -> V_24 , V_2 -> V_116 , V_2 -> V_122 ) ;
F_21 ( & V_34 -> V_24 . V_30 ) ;
if ( F_40 ( V_2 -> V_97 ) ) {
if ( F_40 ( V_2 -> V_92 <= V_98 ) ) {
memcpy ( V_44 -> V_124 , V_34 -> V_39 + V_94 ,
F_41 ( F_42
( V_44 ) ) ) ;
} else
F_33 ( V_44 ) ;
} else {
V_2 -> V_104 [ 0 ] = F_43 ( V_34 -> V_75 + V_105 ) ;
V_2 -> V_104 [ 1 ] = F_43 ( V_34 -> V_75 + V_106 ) ;
V_2 -> V_104 [ 2 ] = F_43 ( V_34 -> V_75 + V_107 ) ;
V_2 -> V_104 [ 3 ] = F_43 ( V_34 -> V_75 + V_108 ) ;
V_2 -> V_104 [ 4 ] = F_43 ( V_34 -> V_75 + V_109 ) ;
}
}
static void F_44 ( void )
{
struct V_125 * V_44 = V_34 -> V_45 ;
void * V_126 ;
int V_26 ;
V_34 -> V_24 . V_37 += V_34 -> V_24 . V_41 ;
if ( V_34 -> V_24 . V_127 ) {
int V_128 = V_34 -> V_24 . V_41 ;
int V_129 = 0 ;
do {
int V_130 ;
if ( ! V_34 -> V_24 . V_131 ) {
V_26 = F_8 ( & V_34 -> V_24 . V_77 ) ;
F_9 ( ! V_26 ) ;
V_34 -> V_24 . V_131 = V_34 -> V_24 . V_77 . V_31 ;
V_34 -> V_24 . V_132 = 0 ;
}
V_126 = V_34 -> V_24 . V_77 . V_33 ;
V_126 += V_34 -> V_24 . V_132 ;
V_130 = F_10 ( V_128 , V_34 -> V_24 . V_131 ) ;
memcpy ( V_126 ,
V_34 -> V_39 + V_70 + V_129 ,
V_130 ) ;
V_129 += V_130 ;
V_34 -> V_24 . V_131 -= V_130 ;
V_128 -= V_130 ;
V_34 -> V_24 . V_132 += V_130 ;
} while ( V_128 > 0 );
}
V_34 -> V_24 . V_41 = 0 ;
F_9 ( V_34 -> V_133 != V_134 ) ;
if ( V_34 -> V_24 . V_37 < V_34 -> V_24 . V_36 ) {
V_34 -> V_133 = V_135 ;
V_34 -> V_24 . V_136 ( 0 ) ;
} else {
V_34 -> V_24 . V_137 () ;
V_34 -> V_133 = V_138 ;
F_45 () ;
V_44 -> V_137 ( V_44 , 0 ) ;
F_46 () ;
}
}
static int F_47 ( struct V_139 * V_140 , unsigned int V_141 )
{
int V_112 = 0 ;
T_2 V_142 ;
while ( V_140 ) {
V_142 = V_140 [ V_112 ] . V_31 ;
++ V_112 ;
if ( V_141 > V_142 )
V_141 -= V_142 ;
else
break;
}
return V_112 ;
}
static void F_48 ( struct V_43 * V_44 )
{
struct V_23 * V_24 = & V_34 -> V_24 ;
int V_143 ;
V_34 -> V_45 = & V_44 -> V_46 ;
memset ( V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 -> V_36 = V_44 -> V_144 ;
V_24 -> V_137 = F_20 ;
V_24 -> V_136 = F_12 ;
V_24 -> V_127 = 1 ;
V_143 = F_47 ( V_44 -> V_145 , V_44 -> V_144 ) ;
F_49 ( & V_24 -> V_30 , V_44 -> V_145 , V_143 , V_146 ) ;
V_143 = F_47 ( V_44 -> V_147 , V_44 -> V_144 ) ;
F_49 ( & V_24 -> V_77 , V_44 -> V_147 , V_143 , V_148 ) ;
F_12 ( 1 ) ;
}
static void F_50 ( struct V_78 * V_44 )
{
struct V_23 * V_24 = & V_34 -> V_24 ;
struct V_81 * V_2 = F_24 ( V_44 ) ;
int V_143 , V_149 , V_150 , V_119 ;
V_34 -> V_45 = & V_44 -> V_46 ;
memset ( V_24 , 0 , sizeof( struct V_23 ) ) ;
V_149 = V_44 -> V_144 + V_2 -> V_122 ;
V_150 = V_2 -> V_122 ;
V_2 -> V_122 = V_149 % V_151 ;
if ( V_2 -> V_122 != 0
&& ( ! V_2 -> V_97 || V_2 -> V_92 > V_98 ) )
V_149 -= V_2 -> V_122 ;
else
V_2 -> V_122 = 0 ;
V_143 = F_47 ( V_44 -> V_145 , V_44 -> V_144 ) ;
F_49 ( & V_24 -> V_30 , V_44 -> V_145 , V_143 , V_146 ) ;
if ( V_149 ) {
V_24 -> V_36 = V_149 ;
V_24 -> V_137 = F_39 ;
V_24 -> V_136 = F_22 ;
if ( F_35 ( V_150 ) ) {
memcpy ( V_34 -> V_39 + V_40 , V_2 -> V_116 ,
V_150 ) ;
V_24 -> V_41 = V_150 ;
}
F_22 ( 1 ) ;
} else {
F_7 ( V_24 , V_2 -> V_116 + V_150 ,
V_2 -> V_122 - V_150 ) ;
F_21 ( & V_24 -> V_30 ) ;
if ( V_2 -> V_97 )
V_119 = F_33 ( V_44 ) ;
else
V_119 = 0 ;
V_34 -> V_133 = V_138 ;
F_45 () ;
V_44 -> V_46 . V_137 ( & V_44 -> V_46 , V_119 ) ;
F_46 () ;
}
}
static int F_51 ( void * V_152 )
{
V_34 -> V_133 = V_138 ;
do {
struct V_125 * V_153 = NULL ;
struct V_125 * V_154 ;
F_52 ( V_155 ) ;
if ( V_34 -> V_133 == V_134 )
F_44 () ;
F_53 ( & V_34 -> V_156 ) ;
if ( V_34 -> V_133 == V_138 ) {
V_154 = F_54 ( & V_34 -> V_157 ) ;
V_153 = F_55 ( & V_34 -> V_157 ) ;
if ( V_153 ) {
F_9 ( V_34 -> V_133 != V_138 ) ;
V_34 -> V_133 = V_135 ;
}
}
F_56 ( & V_34 -> V_156 ) ;
if ( V_154 ) {
V_154 -> V_137 ( V_154 , - V_158 ) ;
V_154 = NULL ;
}
if ( V_153 ) {
if ( V_153 -> V_18 -> V_159 -> V_160 !=
& V_161 ) {
struct V_43 * V_44 =
F_13 ( V_153 ) ;
F_48 ( V_44 ) ;
} else {
struct V_78 * V_44 =
F_23 ( V_153 ) ;
F_50 ( V_44 ) ;
}
V_153 = NULL ;
}
F_57 () ;
} while ( ! F_58 () );
return 0 ;
}
static int F_59 ( struct V_125 * V_44 )
{
unsigned long V_120 ;
int V_26 ;
F_60 ( & V_34 -> V_156 , V_120 ) ;
V_26 = F_61 ( & V_34 -> V_157 , V_44 ) ;
F_62 ( & V_34 -> V_156 , V_120 ) ;
F_63 ( V_34 -> V_162 ) ;
return V_26 ;
}
static int F_64 ( struct V_43 * V_44 )
{
struct V_47 * V_48 = F_14 ( V_44 ) ;
V_48 -> V_50 = V_51 ;
V_48 -> V_62 = 0 ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_65 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_5 ( V_44 -> V_46 . V_18 ) ;
struct V_47 * V_48 = F_14 ( V_44 ) ;
V_48 -> V_50 = V_51 ;
V_48 -> V_62 = 1 ;
F_1 ( V_2 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_66 ( struct V_43 * V_44 )
{
struct V_47 * V_48 = F_14 ( V_44 ) ;
V_48 -> V_50 = V_56 ;
V_48 -> V_62 = 0 ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_67 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_5 ( V_44 -> V_46 . V_18 ) ;
struct V_47 * V_48 = F_14 ( V_44 ) ;
V_48 -> V_50 = V_56 ;
V_48 -> V_62 = 1 ;
F_1 ( V_2 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_68 ( struct V_17 * V_18 )
{
V_18 -> V_163 . V_164 = sizeof( struct V_47 ) ;
return 0 ;
}
static void F_69 ( struct V_81 * V_2 , int V_50 ,
int V_82 , unsigned int V_165 ,
int V_115 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_50 = V_50 ;
V_2 -> V_92 = V_165 ;
V_2 -> V_99 = 1 ;
V_2 -> V_97 = V_82 ;
V_2 -> V_115 = V_115 ;
}
static void F_70 ( struct V_81 * V_2 , int V_82 ,
unsigned V_165 )
{
V_2 -> V_97 = V_82 ;
V_2 -> V_92 += V_165 ;
}
static int F_71 ( struct V_78 * V_44 )
{
const struct V_79 * V_80 = F_5 ( V_44 -> V_46 . V_18 ) ;
F_69 ( F_24 ( V_44 ) , V_80 -> V_50 , 0 , 0 ,
V_80 -> V_115 ) ;
return 0 ;
}
static int F_72 ( struct V_78 * V_44 )
{
if ( ! V_44 -> V_144 )
return 0 ;
F_70 ( F_24 ( V_44 ) , 0 , V_44 -> V_144 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_73 ( struct V_78 * V_44 )
{
struct V_81 * V_2 = F_24 ( V_44 ) ;
F_70 ( V_2 , 1 , 0 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_74 ( struct V_78 * V_44 )
{
F_70 ( F_24 ( V_44 ) , 1 , V_44 -> V_144 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_75 ( struct V_78 * V_44 )
{
const struct V_79 * V_80 = F_5 ( V_44 -> V_46 . V_18 ) ;
F_69 ( F_24 ( V_44 ) , V_80 -> V_50 , 1 ,
V_44 -> V_144 , V_80 -> V_115 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static void F_76 ( struct V_79 * V_2 , const void * V_166 ,
const void * V_167 )
{
const struct V_113 * V_168 = V_166 , * V_169 = V_167 ;
int V_112 ;
for ( V_112 = 0 ; V_112 < 5 ; V_112 ++ ) {
V_2 -> V_89 [ V_112 ] = F_77 ( V_168 -> V_104 [ V_112 ] ) ;
V_2 -> V_89 [ V_112 + 5 ] = F_77 ( V_169 -> V_104 [ V_112 ] ) ;
}
}
static int F_78 ( struct V_170 * V_18 , const T_1 * V_15 ,
unsigned int V_171 )
{
int V_119 ;
struct V_79 * V_2 = F_5 ( & V_18 -> V_46 ) ;
int V_172 , V_173 , V_174 ;
if ( ! V_2 -> V_175 )
return 0 ;
V_119 = F_79 ( V_2 -> V_118 , V_15 , V_171 ) ;
if ( V_119 )
return V_119 ;
V_172 = F_80 ( V_2 -> V_175 ) ;
V_173 = F_81 ( V_2 -> V_175 ) ;
V_174 = F_82 ( V_2 -> V_175 ) ;
{
struct {
struct V_110 V_117 ;
char V_2 [ F_34 ( V_2 -> V_175 ) ] ;
} V_111 ;
unsigned int V_112 ;
char V_176 [ V_174 ] ;
char V_177 [ V_174 ] ;
V_111 . V_117 . V_18 = V_2 -> V_175 ;
V_111 . V_117 . V_120 = F_83 ( V_2 -> V_175 ) &
V_121 ;
if ( V_171 > V_172 ) {
int V_178 ;
V_178 =
F_84 ( & V_111 . V_117 , V_15 , V_171 , V_176 ) ;
if ( V_178 )
return V_178 ;
V_171 = V_173 ;
} else
memcpy ( V_176 , V_15 , V_171 ) ;
memset ( V_176 + V_171 , 0 , V_172 - V_171 ) ;
memcpy ( V_177 , V_176 , V_172 ) ;
for ( V_112 = 0 ; V_112 < V_172 ; V_112 ++ ) {
V_176 [ V_112 ] ^= 0x36 ;
V_177 [ V_112 ] ^= 0x5c ;
}
V_119 = F_36 ( & V_111 . V_117 ) ? :
F_37 ( & V_111 . V_117 , V_176 , V_172 ) ? :
F_85 ( & V_111 . V_117 , V_176 ) ? :
F_36 ( & V_111 . V_117 ) ? :
F_37 ( & V_111 . V_117 , V_177 , V_172 ) ? :
F_85 ( & V_111 . V_117 , V_177 ) ;
if ( V_119 == 0 )
F_76 ( V_2 , V_176 , V_177 ) ;
return V_119 ;
}
}
static int F_86 ( struct V_17 * V_18 , const char * V_179 ,
enum V_180 V_50 , int V_115 )
{
const char * V_181 = V_18 -> V_159 -> V_182 ;
struct V_79 * V_2 = F_5 ( V_18 ) ;
struct V_183 * V_184 = NULL ;
struct V_183 * V_175 = NULL ;
int V_178 = - V_185 ;
V_2 -> V_50 = V_50 ;
V_2 -> V_115 = V_115 ;
V_184 = F_87 ( V_181 , 0 ,
V_186 ) ;
if ( F_88 ( V_184 ) ) {
F_89 (KERN_WARNING MV_CESA
L_1 ,
fallback_driver_name) ;
V_178 = F_90 ( V_184 ) ;
goto V_123;
}
V_2 -> V_118 = V_184 ;
if ( V_179 ) {
V_175 = F_87 ( V_179 , 0 ,
V_186 ) ;
if ( F_88 ( V_175 ) ) {
F_89 (KERN_WARNING MV_CESA
L_2 ,
base_hash_name) ;
V_178 = F_90 ( V_175 ) ;
goto V_187;
}
}
V_2 -> V_175 = V_175 ;
F_91 ( F_92 ( V_18 ) ,
sizeof( struct V_81 ) +
F_34 ( V_2 -> V_118 ) ) ;
return 0 ;
V_187:
F_93 ( V_184 ) ;
V_123:
return V_178 ;
}
static void F_94 ( struct V_17 * V_18 )
{
struct V_79 * V_2 = F_5 ( V_18 ) ;
F_93 ( V_2 -> V_118 ) ;
if ( V_2 -> V_175 )
F_93 ( V_2 -> V_175 ) ;
}
static int F_95 ( struct V_17 * V_18 )
{
return F_86 ( V_18 , NULL , V_83 , 0 ) ;
}
static int F_96 ( struct V_17 * V_18 )
{
return F_86 ( V_18 , L_3 , V_86 , V_151 ) ;
}
T_3 F_97 ( int V_188 , void * V_189 )
{
V_91 V_190 ;
V_190 = F_43 ( V_34 -> V_75 + V_191 ) ;
if ( ! ( V_190 & V_192 ) )
return V_193 ;
V_190 &= ~ V_192 ;
F_19 ( V_190 , V_34 -> V_75 + V_194 ) ;
F_19 ( V_190 , V_34 -> V_75 + V_191 ) ;
F_9 ( V_34 -> V_133 != V_135 ) ;
V_34 -> V_133 = V_134 ;
F_63 ( V_34 -> V_162 ) ;
return V_195 ;
}
static int F_98 ( struct V_196 * V_197 )
{
struct V_198 * V_199 ;
struct V_200 * V_201 ;
int V_188 ;
int V_26 ;
if ( V_34 ) {
F_89 (KERN_ERR MV_CESA L_4 ) ;
return - V_202 ;
}
V_201 = F_99 ( V_197 , V_203 , L_5 ) ;
if ( ! V_201 )
return - V_204 ;
V_199 = F_100 ( sizeof( * V_199 ) , V_205 ) ;
if ( ! V_199 )
return - V_185 ;
F_101 ( & V_199 -> V_156 ) ;
F_102 ( & V_199 -> V_157 , 50 ) ;
V_199 -> V_75 = F_103 ( V_201 -> V_206 , F_104 ( V_201 ) ) ;
if ( ! V_199 -> V_75 ) {
V_26 = - V_185 ;
goto V_178;
}
V_201 = F_99 ( V_197 , V_203 , L_6 ) ;
if ( ! V_201 ) {
V_26 = - V_204 ;
goto V_207;
}
V_199 -> V_208 = F_104 ( V_201 ) ;
V_199 -> V_38 = V_199 -> V_208 - V_209 ;
V_199 -> V_39 = F_103 ( V_201 -> V_206 , V_199 -> V_208 ) ;
if ( ! V_199 -> V_39 ) {
V_26 = - V_185 ;
goto V_207;
}
V_188 = F_105 ( V_197 , 0 ) ;
if ( V_188 < 0 || V_188 == V_210 ) {
V_26 = V_188 ;
goto V_211;
}
V_199 -> V_188 = V_188 ;
F_106 ( V_197 , V_199 ) ;
V_34 = V_199 ;
V_199 -> V_162 = F_107 ( F_51 , V_199 , L_7 ) ;
if ( F_88 ( V_199 -> V_162 ) ) {
V_26 = F_90 ( V_199 -> V_162 ) ;
goto V_211;
}
V_26 = F_108 ( V_188 , F_97 , V_212 , F_109 ( & V_197 -> V_213 ) ,
V_199 ) ;
if ( V_26 )
goto V_214;
F_19 ( V_192 , V_34 -> V_75 + V_215 ) ;
F_19 ( V_216 , V_34 -> V_75 + V_217 ) ;
F_19 ( V_73 , V_34 -> V_75 + V_218 ) ;
V_26 = F_110 ( & V_219 ) ;
if ( V_26 ) {
F_89 (KERN_WARNING MV_CESA
L_8 ) ;
goto V_220;
}
V_26 = F_110 ( & V_221 ) ;
if ( V_26 ) {
F_89 (KERN_WARNING MV_CESA
L_9 ) ;
goto V_222;
}
V_26 = F_111 ( & V_223 ) ;
if ( V_26 == 0 )
V_34 -> V_224 = 1 ;
else
F_89 (KERN_WARNING MV_CESA L_10 ) ;
V_26 = F_111 ( & V_225 ) ;
if ( V_26 == 0 ) {
V_34 -> V_226 = 1 ;
} else {
F_89 (KERN_WARNING MV_CESA
L_11 ) ;
}
return 0 ;
V_222:
F_112 ( & V_219 ) ;
V_220:
F_113 ( V_188 , V_199 ) ;
V_214:
F_114 ( V_199 -> V_162 ) ;
V_211:
F_115 ( V_199 -> V_39 ) ;
V_207:
F_115 ( V_199 -> V_75 ) ;
V_178:
F_116 ( V_199 ) ;
V_34 = NULL ;
F_106 ( V_197 , NULL ) ;
return V_26 ;
}
static int F_117 ( struct V_196 * V_197 )
{
struct V_198 * V_199 = F_118 ( V_197 ) ;
F_112 ( & V_219 ) ;
F_112 ( & V_221 ) ;
if ( V_199 -> V_224 )
F_119 ( & V_223 ) ;
if ( V_199 -> V_226 )
F_119 ( & V_225 ) ;
F_114 ( V_199 -> V_162 ) ;
F_113 ( V_199 -> V_188 , V_199 ) ;
memset ( V_199 -> V_39 , 0 , V_199 -> V_208 ) ;
F_115 ( V_199 -> V_39 ) ;
F_115 ( V_199 -> V_75 ) ;
F_116 ( V_199 ) ;
V_34 = NULL ;
return 0 ;
}
static int T_4 F_120 ( void )
{
return F_121 ( & V_227 ) ;
}
static void T_5 F_122 ( void )
{
F_123 ( & V_227 ) ;
}
