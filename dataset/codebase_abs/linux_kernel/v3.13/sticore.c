static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = & V_2 -> V_5 -> V_9 ;
struct V_10 * V_11 = & V_2 -> V_5 -> V_12 ;
unsigned long V_13 ;
int V_14 , V_15 ;
F_2 ( & V_2 -> V_16 , V_13 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_17 = 3 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_4 -> V_18 = F_3 ( V_8 ) ;
V_11 -> V_19 = 0 ;
V_14 = F_4 ( V_2 , V_2 -> V_20 , & V_21 , V_4 ,
V_11 , V_2 -> V_22 ) ;
if ( V_14 >= 0 )
V_2 -> V_17 = V_11 -> V_17 ;
V_15 = V_11 -> V_19 ;
F_5 ( & V_2 -> V_16 , V_13 ) ;
if ( V_14 < 0 ) {
F_6 ( L_1 , V_14 , V_15 ) ;
return - 1 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_23 * V_4 = & V_2 -> V_5 -> V_24 ;
struct V_25 * V_11 = & V_2 -> V_5 -> V_26 ;
unsigned long V_13 ;
T_1 V_14 ;
V_11 -> V_18 = F_3 ( & V_2 -> V_5 -> V_27 ) ;
do {
F_2 ( & V_2 -> V_16 , V_13 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_14 = F_4 ( V_2 , V_2 -> V_28 , & V_29 ,
V_4 , V_11 , V_2 -> V_22 ) ;
F_5 ( & V_2 -> V_16 , V_13 ) ;
} while ( V_14 == 1 );
}
void
F_8 ( struct V_1 * V_2 , int V_30 , int V_31 , int V_32 )
{
struct V_33 * V_4 = & V_2 -> V_5 -> V_34 ;
struct V_33 V_35 = {
. V_36 = F_3 ( V_2 -> V_37 -> V_38 ) ,
. V_39 = F_9 ( V_2 , V_30 ) ,
. V_40 = F_10 ( V_2 , V_30 ) ,
. V_41 = F_11 ( V_2 , V_30 ) ,
. V_42 = V_32 * V_2 -> V_43 ,
. V_44 = V_31 * V_2 -> V_45 ,
} ;
struct V_46 * V_11 = & V_2 -> V_5 -> V_47 ;
T_1 V_14 ;
unsigned long V_13 ;
do {
F_2 ( & V_2 -> V_16 , V_13 ) ;
* V_4 = V_35 ;
V_14 = F_4 ( V_2 , V_2 -> V_48 , & V_49 ,
V_4 , V_11 , V_2 -> V_22 ) ;
F_5 ( & V_2 -> V_16 , V_13 ) ;
} while ( V_14 == 1 );
}
void
F_12 ( struct V_1 * V_2 , int V_50 , int V_51 ,
int V_52 , int V_53 , T_2 V_54 )
{
struct V_55 * V_4 = & V_2 -> V_5 -> V_56 ;
struct V_55 V_35 = {
. V_40 = V_54 ,
. V_41 = V_54 ,
. V_51 = V_51 ,
. V_50 = V_50 ,
. V_42 = V_51 ,
. V_44 = V_50 ,
. V_53 = V_53 ,
. V_52 = V_52 ,
} ;
struct V_57 * V_11 = & V_2 -> V_5 -> V_58 ;
T_1 V_14 ;
unsigned long V_13 ;
do {
F_2 ( & V_2 -> V_16 , V_13 ) ;
* V_4 = V_35 ;
V_14 = F_4 ( V_2 , V_2 -> V_59 , & V_60 ,
V_4 , V_11 , V_2 -> V_22 ) ;
F_5 ( & V_2 -> V_16 , V_13 ) ;
} while ( V_14 == 1 );
}
void
F_13 ( struct V_1 * V_2 , int V_50 , int V_51 ,
int V_52 , int V_53 , int V_30 )
{
struct V_55 * V_4 = & V_2 -> V_5 -> V_56 ;
struct V_55 V_35 = {
. V_40 = F_10 ( V_2 , V_30 ) ,
. V_41 = F_11 ( V_2 , V_30 ) ,
. V_51 = V_51 * V_2 -> V_43 ,
. V_50 = V_50 * V_2 -> V_45 ,
. V_42 = V_51 * V_2 -> V_43 ,
. V_44 = V_50 * V_2 -> V_45 ,
. V_53 = V_53 * V_2 -> V_43 ,
. V_52 = V_52 * V_2 -> V_45 ,
} ;
struct V_57 * V_11 = & V_2 -> V_5 -> V_58 ;
T_1 V_14 ;
unsigned long V_13 ;
do {
F_2 ( & V_2 -> V_16 , V_13 ) ;
* V_4 = V_35 ;
V_14 = F_4 ( V_2 , V_2 -> V_59 , & V_60 ,
V_4 , V_11 , V_2 -> V_22 ) ;
F_5 ( & V_2 -> V_16 , V_13 ) ;
} while ( V_14 == 1 );
}
void
F_14 ( struct V_1 * V_2 , int V_50 , int V_51 ,
int V_61 , int V_62 , int V_52 , int V_53 )
{
struct V_55 * V_4 = & V_2 -> V_5 -> V_56 ;
struct V_55 V_35 = {
. V_51 = V_51 * V_2 -> V_43 ,
. V_50 = V_50 * V_2 -> V_45 ,
. V_42 = V_62 * V_2 -> V_43 ,
. V_44 = V_61 * V_2 -> V_45 ,
. V_53 = V_53 * V_2 -> V_43 ,
. V_52 = V_52 * V_2 -> V_45 ,
} ;
struct V_57 * V_11 = & V_2 -> V_5 -> V_58 ;
T_1 V_14 ;
unsigned long V_13 ;
do {
F_2 ( & V_2 -> V_16 , V_13 ) ;
* V_4 = V_35 ;
V_14 = F_4 ( V_2 , V_2 -> V_59 , & V_63 ,
V_4 , V_11 , V_2 -> V_22 ) ;
F_5 ( & V_2 -> V_16 , V_13 ) ;
} while ( V_14 == 1 );
}
static void F_15 ( unsigned long V_64 , unsigned long V_65 )
{
F_16 ( V_64 , V_65 ) ;
}
static void F_17 ( unsigned long V_66 , unsigned long V_67 , void * V_68 )
{
unsigned long V_69 = ( unsigned long ) V_68 ;
while ( V_67 >= 4 ) {
V_67 -= 4 ;
* ( V_70 * ) V_68 = F_18 ( V_66 ) ;
V_66 += 4 ;
V_68 += 4 ;
}
while ( V_67 ) {
V_67 -- ;
* ( T_2 * ) V_68 = F_19 ( V_66 ) ;
V_66 ++ ;
V_68 ++ ;
}
F_15 ( V_69 , ( unsigned long ) V_68 ) ;
}
static int F_20 ( char * V_71 )
{
if ( V_71 )
F_21 ( V_72 , V_71 , sizeof ( V_72 ) ) ;
return 1 ;
}
static int F_22 ( char * V_71 )
{
char * V_32 ;
int V_73 = 0 ;
while ( V_73 < V_74 && V_71 && * V_71 ) {
if ( * V_71 >= '0' && * V_71 <= '9' ) {
if ( ( V_32 = strchr ( V_71 , 'x' ) ) || ( V_32 = strchr ( V_71 , '*' ) ) ) {
V_45 [ V_73 ] = F_23 ( V_71 , NULL , 0 ) ;
V_43 [ V_73 ] = F_23 ( V_32 + 1 , NULL , 0 ) ;
} else {
V_75 [ V_73 ] = F_23 ( V_71 , NULL , 0 ) ;
}
} else {
V_76 [ V_73 ] = V_71 ;
}
if ( ( V_32 = strchr ( V_71 , ',' ) ) )
* V_32 ++ = 0 ;
V_71 = V_32 ;
V_73 ++ ;
}
return 1 ;
}
static void F_24 ( struct V_77 * V_22 ,
unsigned int V_78 )
{
struct V_79 * V_80 ;
F_25 ( ( V_81
L_2
L_3
L_4
L_5
L_6
L_6
L_7
L_8 ,
V_22 -> V_17 ,
V_22 -> V_82 , V_22 -> V_83 ,
V_22 -> V_84 , V_22 -> V_85 ,
V_22 -> V_86 , V_22 -> V_87 ,
V_22 -> V_88 [ 0 ] , V_22 -> V_88 [ 1 ] ,
V_22 -> V_88 [ 2 ] , V_22 -> V_88 [ 3 ] ,
V_22 -> V_88 [ 4 ] , V_22 -> V_88 [ 5 ] ,
V_22 -> V_88 [ 6 ] , V_22 -> V_88 [ 7 ] ,
V_22 -> V_89 ,
V_22 -> V_90 ) ) ;
V_80 = F_26 ( ( unsigned long ) V_22 -> V_18 ) ;
F_25 ( ( V_81
L_9
L_10
L_11
L_12
L_13 ,
V_80 -> V_91 ,
V_80 -> V_92 ,
V_80 -> V_93 ,
V_80 -> V_94 ,
V_80 -> V_95 , V_78 ) ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_25 ( ( V_81
L_14
L_15
L_16
L_17 ,
V_2 -> V_5 -> V_26 . V_96 ,
V_2 -> V_5 -> V_26 . V_97 ,
V_2 -> V_5 -> V_26 . V_98 ,
V_2 -> V_5 -> V_26 . V_99 ) ) ;
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_100 ,
unsigned long V_101 )
{
struct V_77 * V_22 ;
struct V_79 * V_102 ;
void * V_90 ;
void * V_95 ;
int V_73 , V_103 ;
if ( V_2 -> V_78 < 256 )
V_2 -> V_78 = 256 ;
V_103 = sizeof( struct V_104 ) + V_2 -> V_78 - 256 ;
V_2 -> V_5 = F_29 ( V_103 , V_105 ) ;
if ( ! V_2 -> V_5 )
return - V_106 ;
V_22 = & V_2 -> V_5 -> V_22 ;
V_102 = & V_2 -> V_5 -> V_102 ;
V_90 = & V_2 -> V_5 -> V_90 ;
V_95 = & V_2 -> V_5 -> V_95 ;
V_22 -> V_18 = F_3 ( V_102 ) ;
V_22 -> V_90 = F_3 ( V_90 ) ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
unsigned long V_107 , V_108 ;
if ( V_2 -> V_109 ) {
unsigned char V_110 = V_2 -> V_111 [ V_73 ] ;
if ( V_110 == 0 )
continue;
if ( V_110 != V_112 &&
( V_110 < V_113 ||
V_110 > V_114 ) ) {
F_30 ( V_115
L_18 ,
V_73 , V_2 -> V_111 [ V_73 ] ) ;
continue;
}
V_107 = F_31 ( V_2 -> V_109 , ( V_110 - V_113 ) / 4 ) ;
} else
V_107 = ( V_73 == 0 ) ? V_100 : V_101 ;
V_2 -> V_116 [ V_73 ] =
F_32 ( V_2 -> V_117 [ V_73 ] , V_107 ) ;
V_108 = V_2 -> V_117 [ V_73 ] . V_118 . V_119 * 4096 ;
if ( V_108 )
V_22 -> V_88 [ V_73 ] = V_2 -> V_116 [ V_73 ] ;
F_25 ( ( L_19
L_20 ,
V_73 , V_2 -> V_116 [ V_73 ] , V_22 -> V_88 [ V_73 ] ,
V_108 / 1024 ,
V_2 -> V_117 [ V_73 ] . V_118 . V_120 ,
V_2 -> V_117 [ V_73 ] . V_118 . V_121 ,
V_2 -> V_117 [ V_73 ] . V_118 . V_122 ,
V_2 -> V_117 [ V_73 ] . V_118 . V_123 ) ) ;
if ( V_2 -> V_117 [ V_73 ] . V_118 . V_123 )
break;
}
if ( ++ V_73 < 8 && V_2 -> V_117 [ V_73 ] . V_124 )
F_30 ( V_115 L_21 ,
__FILE__ , V_2 -> V_117 [ V_73 ] . V_124 ) ;
V_102 -> V_95 = F_3 ( V_95 ) ;
V_2 -> V_22 = V_22 ;
return 0 ;
}
static struct V_125 *
F_33 ( struct V_126 * V_127 , const char * V_128 )
{
const struct V_129 * V_130 = NULL ;
unsigned int V_103 , V_131 ;
void * V_68 ;
struct V_132 * V_133 ;
struct V_125 * V_134 ;
if ( V_128 && strlen ( V_128 ) )
V_130 = F_34 ( V_128 ) ;
if ( ! V_130 )
V_130 = F_35 ( 1024 , 768 , ~ ( V_70 ) 0 , ~ ( V_70 ) 0 ) ;
if ( ! V_130 )
return NULL ;
F_36 ( L_22 ,
V_130 -> V_53 , V_130 -> V_52 , V_130 -> V_135 ) ;
V_131 = ( ( V_130 -> V_53 + 7 ) / 8 ) * V_130 -> V_52 ;
V_103 = V_131 * 256 ;
V_103 += sizeof( struct V_132 ) ;
V_133 = F_29 ( V_103 , V_105 ) ;
if ( ! V_133 )
return NULL ;
V_133 -> V_136 = 0 ;
V_133 -> V_137 = 255 ;
V_133 -> V_53 = V_130 -> V_53 ;
V_133 -> V_52 = V_130 -> V_52 ;
V_133 -> V_138 = V_139 ;
V_133 -> V_140 = V_131 ;
V_133 -> V_141 = 0 ;
V_133 -> V_142 = 1 ;
V_133 -> V_143 = V_130 -> V_52 - V_133 -> V_142 ;
V_68 = V_133 ;
V_68 += sizeof( struct V_132 ) ;
memcpy ( V_68 , V_130 -> V_144 , V_131 * 256 ) ;
V_134 = F_29 ( sizeof( * V_134 ) , V_145 ) ;
if ( ! V_134 ) {
F_37 ( V_133 ) ;
return NULL ;
}
V_134 -> V_38 = V_133 ;
V_134 -> V_141 = NULL ;
V_127 -> V_146 = V_134 ;
return V_134 ;
}
static struct V_125 *
F_33 ( struct V_126 * V_127 , const char * V_128 )
{
return NULL ;
}
static struct V_125 * F_38 ( struct V_126 * V_147 ,
int (* F_39)( struct V_126 * , int , int ) )
{
struct V_125 * V_37 ;
int V_73 ;
int V_39 = V_148 ;
if ( ( V_37 = F_33 ( V_147 , V_76 [ V_39 ] ) ) )
return V_37 ;
if ( V_43 [ V_39 ] && V_45 [ V_39 ] )
V_75 [ V_39 ] = F_39 ( V_147 ,
V_45 [ V_39 ] , V_43 [ V_39 ] ) ;
for ( V_37 = V_147 -> V_146 , V_73 = V_75 [ V_39 ] ;
V_37 && ( V_73 > 0 ) ;
V_37 = V_37 -> V_141 , V_73 -- ) ;
if ( V_37 )
return V_37 ;
else
return V_147 -> V_146 ;
}
static void F_40 ( struct V_149 * V_147 )
{
F_30 ( V_81 L_23 ,
V_147 -> V_150 [ 0 ] ,
V_147 -> V_150 [ 1 ] ,
V_147 -> V_151 [ 0 ] >> 4 ,
V_147 -> V_151 [ 0 ] & 0x0f ) ;
F_25 ( ( L_24 , V_147 -> V_152 ) ) ;
F_25 ( ( L_25 , V_147 -> V_146 ) ) ;
F_25 ( ( L_26 , V_147 -> V_153 ) ) ;
F_25 ( ( L_27 , V_147 -> V_20 ) ) ;
F_25 ( ( L_28 , V_147 -> V_154 ) ) ;
F_25 ( ( L_29 , V_147 -> V_155 ) ) ;
F_25 ( ( L_30 , V_147 -> V_156 ) ) ;
}
static int F_41 ( struct V_126 * V_127 ,
struct V_149 * V_157 )
{
struct V_132 * V_158 , * V_146 ;
struct V_125 * V_134 ;
V_134 = F_29 ( sizeof( * V_134 ) , V_145 ) ;
if ( ! V_134 )
return 0 ;
V_127 -> V_146 = V_134 ;
V_158 = ( ( void * ) V_157 ) + ( V_157 -> V_146 ) ;
V_146 = V_158 ;
V_134 -> V_38 = V_158 ;
while ( V_158 -> V_141 ) {
V_158 = ( ( void * ) V_146 ) + ( V_158 -> V_141 ) ;
V_134 -> V_141 = F_29 ( sizeof( * V_134 ) , V_145 ) ;
if ( ! V_134 -> V_141 )
return 1 ;
V_134 = V_134 -> V_141 ;
V_134 -> V_38 = V_158 ;
}
V_134 -> V_141 = NULL ;
return 1 ;
}
static int F_42 ( struct V_126 * V_147 , int V_52 , int V_53 )
{
struct V_125 * V_37 ;
int V_73 = 0 ;
for ( V_37 = V_147 -> V_146 ; V_37 ; V_37 = V_37 -> V_141 , V_73 ++ ) {
if ( ( V_37 -> V_38 -> V_53 == V_53 ) &&
( V_37 -> V_38 -> V_52 == V_52 ) )
return V_73 ;
}
return 0 ;
}
static void * F_43 ( struct V_125 * V_159 )
{
unsigned char * V_160 , * V_161 , * V_162 ;
int V_103 = V_159 -> V_38 -> V_140 * 256 + sizeof( struct V_132 ) ;
V_160 = F_29 ( 4 * V_103 , V_105 ) ;
if ( ! V_160 )
return NULL ;
V_161 = V_160 + 3 ;
V_162 = ( unsigned char * ) V_159 -> V_38 ;
while ( V_103 -- ) {
* V_161 = * V_162 ++ ;
V_161 += 4 ;
}
return V_160 + 3 ;
}
static void F_44 ( unsigned long V_66 , unsigned long V_67 ,
void * V_68 )
{
unsigned long V_69 = ( unsigned long ) V_68 ;
while ( V_67 ) {
V_67 -- ;
* ( T_2 * ) V_68 = F_18 ( V_66 ) ;
V_66 += 4 ;
V_68 ++ ;
}
F_15 ( V_69 , ( unsigned long ) V_68 ) ;
}
static struct V_149 * F_45 ( unsigned long V_163 )
{
struct V_149 * V_38 ;
V_70 V_103 ;
struct V_132 * V_158 , * V_146 ;
F_44 ( V_163 + V_164 , sizeof( V_103 ) , & V_103 ) ;
V_103 = ( V_103 + 3 ) / 4 ;
V_38 = F_46 ( V_103 , V_105 ) ;
if ( V_38 ) {
F_44 ( V_163 , V_103 , V_38 ) ;
memmove ( & V_38 -> V_165 , & V_38 -> type [ 0 ] , 0x3c ) ;
V_38 -> type [ 3 ] = V_38 -> V_165 ;
F_47 ( V_38 -> V_153 ) ;
F_47 ( V_38 -> V_146 ) ;
F_47 ( V_38 -> V_20 ) ;
F_47 ( V_38 -> V_166 ) ;
F_47 ( V_38 -> V_48 ) ;
F_47 ( V_38 -> V_59 ) ;
F_47 ( V_38 -> V_28 ) ;
V_158 = ( ( void * ) V_38 ) + V_38 -> V_146 ;
V_146 = V_158 ;
while ( V_158 -> V_141 ) {
F_47 ( V_158 -> V_141 ) ;
V_158 = ( ( void * ) V_146 ) + V_158 -> V_141 ;
}
}
return V_38 ;
}
static struct V_149 * F_48 ( unsigned long V_163 )
{
struct V_149 * V_38 ;
unsigned long V_103 ;
V_103 = F_18 ( V_163 + F_49 ( struct V_149 , V_167 ) ) ;
V_38 = F_46 ( V_103 , V_105 ) ;
if ( V_38 )
F_17 ( V_163 , V_103 , V_38 ) ;
return V_38 ;
}
static int F_50 ( int V_168 , struct V_1 * V_2 ,
unsigned long V_163 )
{
struct V_126 * V_169 ;
struct V_149 * V_38 = NULL ;
unsigned long V_151 ;
V_169 = F_46 ( sizeof *V_169 , V_145 ) ;
if ( ! V_169 )
goto V_170;
if ( V_168 )
V_38 = F_48 ( V_163 ) ;
else
V_38 = F_45 ( V_163 ) ;
if ( ! V_38 )
goto V_170;
if ( ! F_41 ( V_169 , V_38 ) ) {
F_30 ( V_171 L_31 , V_163 ) ;
goto V_170;
}
if ( V_38 -> V_153 )
memcpy ( V_2 -> V_117 , ( ( void * ) V_38 ) + V_38 -> V_153 , sizeof( V_2 -> V_117 ) ) ;
V_163 = ( unsigned long ) F_3 ( V_38 ) ;
F_36 ( L_32 ,
V_38 -> V_156 == V_172
? L_33 : L_34 ) ;
V_2 -> V_48 = V_163 + ( V_38 -> V_48 & 0x03ffffff ) ;
V_2 -> V_59 = V_163 + ( V_38 -> V_59 & 0x03ffffff ) ;
V_2 -> V_20 = V_163 + ( V_38 -> V_20 & 0x03ffffff ) ;
V_2 -> V_28 = V_163 + ( V_38 -> V_28 & 0x03ffffff ) ;
V_2 -> V_147 = V_169 ;
V_2 -> V_147 -> V_38 = V_38 ;
V_2 -> V_37 = F_38 ( V_2 -> V_147 , F_42 ) ;
V_2 -> V_43 = V_2 -> V_37 -> V_38 -> V_53 ;
V_2 -> V_45 = V_2 -> V_37 -> V_38 -> V_52 ;
if ( ! V_168 )
V_2 -> V_37 -> V_38 = F_43 ( V_2 -> V_37 ) ;
V_2 -> V_78 = V_38 -> V_173 ;
V_2 -> V_150 [ 0 ] = V_38 -> V_150 [ 0 ] ;
V_2 -> V_150 [ 1 ] = V_38 -> V_150 [ 1 ] ;
F_40 ( V_38 ) ;
if ( V_168 || V_2 -> V_150 [ 1 ] != 0x09A02587 )
goto V_174;
V_151 = ( V_38 -> V_151 [ 0 ] << 8 ) | V_38 -> V_151 [ 1 ] ;
switch ( V_2 -> V_150 [ 0 ] ) {
case V_175 :
if ( V_151 == 0x8408 || V_151 == 0x840b )
goto V_176;
break;
case V_177 :
if ( V_151 == 0x8509 )
goto V_176;
break;
case V_178 :
if ( V_151 == 0x850c )
goto V_176;
}
V_174:
return 1 ;
V_176:
F_30 ( V_171 L_35 ) ;
F_30 ( V_171 L_36
L_37 ) ;
V_170:
F_37 ( V_38 ) ;
F_37 ( V_169 ) ;
return 0 ;
}
static struct V_1 * F_51 ( unsigned long V_163 ,
unsigned long V_101 ,
struct V_179 * V_109 )
{
struct V_1 * V_2 ;
int V_174 ;
V_70 V_180 ;
if ( V_148 >= V_74 ) {
F_30 ( V_115 L_38 ) ;
return NULL ;
}
V_2 = F_29 ( sizeof( * V_2 ) , V_145 ) ;
if ( ! V_2 ) {
F_30 ( V_171 L_39 ) ;
return NULL ;
}
F_52 ( & V_2 -> V_16 ) ;
V_181:
if ( F_53 ( V_163 ) )
goto V_170;
V_180 = F_18 ( V_163 ) ;
if ( ( F_54 ( V_180 ) == 0xaa55 ) ) {
unsigned int V_73 , V_182 ;
V_70 * V_183 ;
V_73 = F_18 ( V_163 + 0x04 ) ;
if ( V_73 != 1 ) {
F_30 ( V_115
L_40 , V_73 ) ;
goto V_170;
}
V_2 -> V_109 = V_109 ;
V_73 = F_18 ( V_163 + 0x0c ) ;
F_25 ( ( L_41 ,
F_55 ( V_73 >> 16 ) * 512 / 1024 ) ) ;
V_182 = F_55 ( V_73 & 0xffff ) ;
if ( V_182 ) {
V_183 = ( V_70 * ) & V_2 -> V_111 ;
* V_183 ++ = F_18 ( V_163 + V_182 + 0x00 ) ;
* V_183 ++ = F_18 ( V_163 + V_182 + 0x04 ) ;
* V_183 ++ = F_18 ( V_163 + V_182 + 0x08 ) ;
* V_183 ++ = F_18 ( V_163 + V_182 + 0x0c ) ;
F_25 ( ( L_42 ,
V_182 ) ) ;
for ( V_73 = 0 ; V_73 < 16 ; V_73 ++ )
F_25 ( ( L_43 , V_2 -> V_111 [ V_73 ] ) ) ;
F_25 ( ( L_44 ) ) ;
}
V_163 += F_54 ( F_18 ( V_163 + 8 ) ) ;
F_25 ( ( L_45 , V_180 , V_163 ) ) ;
goto V_181;
}
V_174 = 0 ;
if ( ( V_180 & 0xff ) == 0x01 ) {
F_25 ( ( L_46 ,
V_163 , V_101 ) ) ;
V_174 = F_50 ( 0 , V_2 , V_163 ) ;
}
if ( ( V_180 & 0xffff ) == 0x0303 ) {
F_25 ( ( L_47 ,
V_163 , V_101 ) ) ;
V_174 = F_50 ( 1 , V_2 , V_163 ) ;
}
if ( ! V_174 )
goto V_170;
if ( F_28 ( V_2 , V_163 , V_101 ) )
goto V_170;
if ( V_2 -> V_109 ) {
unsigned long V_184 ;
V_184 = F_31 ( V_2 -> V_109 , V_185 ) ;
F_56 ( V_2 -> V_109 , V_112 , V_184 & ~ V_186 ) ;
F_25 ( ( V_187 L_48 ) ) ;
}
if ( F_1 ( V_2 ) )
goto V_170;
F_7 ( V_2 ) ;
F_24 ( V_2 -> V_22 , V_2 -> V_78 ) ;
F_27 ( V_2 ) ;
F_36 ( L_49 ,
V_2 -> V_5 -> V_26 . V_188 ) ;
V_189 [ V_148 ] = V_2 ;
V_148 ++ ;
return V_2 ;
V_170:
F_37 ( V_2 ) ;
return NULL ;
}
static void F_57 ( struct V_1 * V_2 , char * V_190 )
{
if ( strcmp ( V_190 , V_72 ) == 0 )
V_191 = V_2 ;
}
static int F_58 ( struct V_192 * V_193 )
{
char V_194 [ 21 ] ;
struct V_1 * V_2 = NULL ;
int V_101 = V_193 -> V_101 . V_64 ;
if ( V_193 -> V_195 && V_193 -> V_196 [ 0 ] )
V_2 = F_51 ( V_193 -> V_196 [ 0 ] , V_101 , NULL ) ;
if ( ! V_2 )
V_2 = F_51 ( V_101 , V_101 , NULL ) ;
if ( ! V_2 )
V_2 = F_51 ( V_197 -> V_198 , V_101 , NULL ) ;
if ( ! V_2 )
return 1 ;
F_59 ( V_193 , V_194 ) ;
F_57 ( V_2 , V_194 ) ;
return 0 ;
}
static int F_60 ( struct V_179 * V_109 , const struct V_199 * V_200 )
{
#ifdef F_61
unsigned long V_201 , V_184 ;
unsigned int V_202 , V_203 ;
int V_15 ;
struct V_1 * V_2 ;
V_15 = F_62 ( V_109 ) ;
if ( V_15 < 0 ) {
F_63 ( & V_109 -> V_193 , L_50 ) ;
return V_15 ;
}
V_201 = F_31 ( V_109 , 0 ) ;
V_202 = F_64 ( V_109 , 0 ) ;
V_184 = F_31 ( V_109 , V_185 ) ;
V_203 = F_64 ( V_109 , V_185 ) ;
if ( V_184 ) {
F_56 ( V_109 , V_112 , V_184 | V_186 ) ;
F_25 ( ( V_187 L_51 , V_184 ) ) ;
}
F_30 ( V_81 L_52 ,
V_184 , V_203 / 1024 , V_201 , V_202 / 1024 / 1024 ) ;
F_25 ( ( V_187 L_53 ,
V_184 , V_201 ) ) ;
V_2 = F_51 ( V_184 , V_201 , V_109 ) ;
if ( V_2 ) {
char V_194 [ 30 ] ;
F_65 ( V_109 , V_194 ) ;
F_57 ( V_2 , V_194 ) ;
}
if ( ! V_2 ) {
F_30 ( V_115 L_54 ,
F_66 ( V_109 ) ) ;
return - V_204 ;
}
#endif
return 0 ;
}
static void F_67 ( struct V_179 * V_109 )
{
F_68 () ;
}
static void F_69 ( void )
{
if ( V_205 )
return;
V_205 = 1 ;
F_30 ( V_81 L_55
V_206 L_44 ) ;
F_70 ( & V_207 ) ;
F_71 ( F_72 ( & V_208 ) ) ;
if ( ! V_191 )
V_191 = V_189 [ 0 ] ;
}
struct V_1 * F_73 ( unsigned int V_39 )
{
if ( ! V_205 )
F_69 () ;
if ( V_39 == 0 )
return V_191 ;
if ( V_39 > V_148 )
return NULL ;
return V_189 [ V_39 - 1 ] ;
}
int F_4 ( const struct V_1 * V_2 , unsigned long V_209 ,
const void * V_13 , void * V_4 , void * V_11 ,
struct V_77 * V_22 )
{
unsigned long V_210 = F_3 ( V_13 ) ;
unsigned long V_211 = F_3 ( V_4 ) ;
unsigned long V_212 = F_3 ( V_11 ) ;
unsigned long V_213 = F_3 ( V_22 ) ;
int V_14 ;
#ifdef F_74
if ( F_75 ( V_210 >> 32 || V_211 >> 32 || V_212 >> 32 || V_213 >> 32 ,
L_56 ) )
return - 1 ;
#endif
V_14 = F_76 ( V_209 , V_210 , V_211 , V_212 , V_213 ) ;
return V_14 ;
}
