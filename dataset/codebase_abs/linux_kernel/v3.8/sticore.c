static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = { 0 , } ;
struct V_5 V_6 = {
. V_7 = 3 ,
. V_8 = F_2 (&inptr_ext)
} ;
struct V_9 V_10 = { 0 , } ;
unsigned long V_11 ;
int V_12 ;
F_3 ( & V_2 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_2 -> V_14 , & V_15 , & V_6 ,
& V_10 , V_2 -> V_16 ) ;
F_5 ( & V_2 -> V_13 , V_11 ) ;
if ( V_12 < 0 ) {
F_6 ( V_17 L_1 , V_12 , V_10 . V_18 ) ;
return - 1 ;
}
V_2 -> V_7 = V_10 . V_7 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_19 V_6 = { 0 , } ;
unsigned long V_11 ;
T_1 V_12 ;
V_2 -> V_10 . V_8 = F_2 ( & V_2 -> V_20 ) ;
do {
F_3 ( & V_2 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_2 -> V_21 , & V_22 ,
& V_6 , & V_2 -> V_10 , V_2 -> V_16 ) ;
F_5 ( & V_2 -> V_13 , V_11 ) ;
} while ( V_12 == 1 );
}
void
F_8 ( struct V_1 * V_2 , int V_23 , int V_24 , int V_25 )
{
struct V_26 V_6 = {
. V_27 = F_2 ( V_2 -> V_28 -> V_29 ) ,
. V_30 = F_9 ( V_2 , V_23 ) ,
. V_31 = F_10 ( V_2 , V_23 ) ,
. V_32 = F_11 ( V_2 , V_23 ) ,
. V_33 = V_25 * V_2 -> V_34 ,
. V_35 = V_24 * V_2 -> V_36 ,
} ;
struct V_37 V_10 = { 0 , } ;
T_1 V_12 ;
unsigned long V_11 ;
do {
F_3 ( & V_2 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_2 -> V_38 , & V_39 ,
& V_6 , & V_10 , V_2 -> V_16 ) ;
F_5 ( & V_2 -> V_13 , V_11 ) ;
} while ( V_12 == 1 );
}
void
F_12 ( struct V_1 * V_2 , int V_40 , int V_41 ,
int V_42 , int V_43 , T_2 V_44 )
{
struct V_45 V_6 = {
. V_31 = V_44 ,
. V_32 = V_44 ,
. V_41 = V_41 ,
. V_40 = V_40 ,
. V_33 = V_41 ,
. V_35 = V_40 ,
. V_43 = V_43 ,
. V_42 = V_42 ,
} ;
struct V_46 V_10 = { 0 , } ;
T_1 V_12 ;
unsigned long V_11 ;
do {
F_3 ( & V_2 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_2 -> V_47 , & V_48 ,
& V_6 , & V_10 , V_2 -> V_16 ) ;
F_5 ( & V_2 -> V_13 , V_11 ) ;
} while ( V_12 == 1 );
}
void
F_13 ( struct V_1 * V_2 , int V_40 , int V_41 ,
int V_42 , int V_43 , int V_23 )
{
struct V_45 V_6 = {
. V_31 = F_10 ( V_2 , V_23 ) ,
. V_32 = F_11 ( V_2 , V_23 ) ,
. V_41 = V_41 * V_2 -> V_34 ,
. V_40 = V_40 * V_2 -> V_36 ,
. V_33 = V_41 * V_2 -> V_34 ,
. V_35 = V_40 * V_2 -> V_36 ,
. V_43 = V_43 * V_2 -> V_34 ,
. V_42 = V_42 * V_2 -> V_36 ,
} ;
struct V_46 V_10 = { 0 , } ;
T_1 V_12 ;
unsigned long V_11 ;
do {
F_3 ( & V_2 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_2 -> V_47 , & V_48 ,
& V_6 , & V_10 , V_2 -> V_16 ) ;
F_5 ( & V_2 -> V_13 , V_11 ) ;
} while ( V_12 == 1 );
}
void
F_14 ( struct V_1 * V_2 , int V_40 , int V_41 ,
int V_49 , int V_50 , int V_42 , int V_43 )
{
struct V_45 V_6 = {
. V_41 = V_41 * V_2 -> V_34 ,
. V_40 = V_40 * V_2 -> V_36 ,
. V_33 = V_50 * V_2 -> V_34 ,
. V_35 = V_49 * V_2 -> V_36 ,
. V_43 = V_43 * V_2 -> V_34 ,
. V_42 = V_42 * V_2 -> V_36 ,
} ;
struct V_46 V_10 = { 0 , } ;
T_1 V_12 ;
unsigned long V_11 ;
do {
F_3 ( & V_2 -> V_13 , V_11 ) ;
V_12 = F_4 ( V_2 -> V_47 , & V_51 ,
& V_6 , & V_10 , V_2 -> V_16 ) ;
F_5 ( & V_2 -> V_13 , V_11 ) ;
} while ( V_12 == 1 );
}
static void F_15 ( unsigned long V_52 , unsigned long V_53 )
{
F_16 ( V_52 , V_53 ) ;
}
static void F_17 ( unsigned long V_54 , unsigned long V_55 , void * V_56 )
{
unsigned long V_57 = ( unsigned long ) V_56 ;
while ( V_55 >= 4 ) {
V_55 -= 4 ;
* ( V_58 * ) V_56 = F_18 ( V_54 ) ;
V_54 += 4 ;
V_56 += 4 ;
}
while ( V_55 ) {
V_55 -- ;
* ( T_2 * ) V_56 = F_19 ( V_54 ) ;
V_54 ++ ;
V_56 ++ ;
}
F_15 ( V_57 , ( unsigned long ) V_56 ) ;
}
static int F_20 ( char * V_59 )
{
if ( V_59 )
F_21 ( V_60 , V_59 , sizeof ( V_60 ) ) ;
return 1 ;
}
static int F_22 ( char * V_59 )
{
char * V_25 ;
int V_61 = 0 ;
while ( V_61 < V_62 && V_59 && * V_59 ) {
if ( * V_59 >= '0' && * V_59 <= '9' ) {
if ( ( V_25 = strchr ( V_59 , 'x' ) ) || ( V_25 = strchr ( V_59 , '*' ) ) ) {
V_36 [ V_61 ] = F_23 ( V_59 , NULL , 0 ) ;
V_34 [ V_61 ] = F_23 ( V_25 + 1 , NULL , 0 ) ;
} else {
V_63 [ V_61 ] = F_23 ( V_59 , NULL , 0 ) ;
}
} else {
V_64 [ V_61 ] = V_59 ;
}
if ( ( V_25 = strchr ( V_59 , ',' ) ) )
* V_25 ++ = 0 ;
V_59 = V_25 ;
V_61 ++ ;
}
return 1 ;
}
static void F_24 ( struct V_65 * V_16 ,
unsigned int V_66 )
{
struct V_67 * V_68 ;
F_25 ( ( V_69
L_2
L_3
L_4
L_5
L_6
L_6
L_7
L_8 ,
V_16 -> V_7 ,
V_16 -> V_70 , V_16 -> V_71 ,
V_16 -> V_72 , V_16 -> V_73 ,
V_16 -> V_74 , V_16 -> V_75 ,
V_16 -> V_76 [ 0 ] , V_16 -> V_76 [ 1 ] ,
V_16 -> V_76 [ 2 ] , V_16 -> V_76 [ 3 ] ,
V_16 -> V_76 [ 4 ] , V_16 -> V_76 [ 5 ] ,
V_16 -> V_76 [ 6 ] , V_16 -> V_76 [ 7 ] ,
V_16 -> V_77 ,
V_16 -> V_78 ) ) ;
V_68 = F_26 ( ( unsigned long ) V_16 -> V_8 ) ;
F_25 ( ( V_69
L_9
L_10
L_11
L_12
L_13 ,
V_68 -> V_79 ,
V_68 -> V_80 ,
V_68 -> V_81 ,
V_68 -> V_82 ,
V_68 -> V_83 , V_66 ) ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_25 ( ( V_69
L_14
L_15
L_16
L_17 ,
V_2 -> V_10 . V_84 ,
V_2 -> V_10 . V_85 ,
V_2 -> V_10 . V_86 ,
V_2 -> V_10 . V_87 ) ) ;
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_88 ,
unsigned long V_89 )
{
struct V_65 * V_16 ;
struct V_67 * V_90 ;
void * V_78 ;
void * V_83 ;
const int V_91 = 1024 ;
int V_61 ;
if ( ! V_2 -> V_66 )
V_2 -> V_66 = 256 ;
V_16 = F_29 ( sizeof( * V_2 -> V_16 ) , V_92 ) ;
V_90 = F_29 ( sizeof( * V_90 ) , V_92 ) ;
V_78 = F_29 ( V_91 , V_92 ) ;
V_83 = F_29 ( V_2 -> V_66 , V_92 ) ;
if ( ! ( V_16 && V_90 && V_78 && V_83 ) ) {
F_30 ( V_16 ) ;
F_30 ( V_90 ) ;
F_30 ( V_78 ) ;
F_30 ( V_83 ) ;
return - V_93 ;
}
V_16 -> V_8 = F_2 ( V_90 ) ;
V_16 -> V_78 = F_2 ( V_78 ) ;
for ( V_61 = 0 ; V_61 < 8 ; V_61 ++ ) {
unsigned long V_94 , V_95 ;
if ( V_2 -> V_96 ) {
unsigned char V_97 = V_2 -> V_98 [ V_61 ] ;
if ( V_97 == 0 )
continue;
if ( V_97 != V_99 &&
( V_97 < V_100 ||
V_97 > V_101 ) ) {
F_6 ( V_102
L_18 ,
V_61 , V_2 -> V_98 [ V_61 ] ) ;
continue;
}
V_94 = F_31 ( V_2 -> V_96 , ( V_97 - V_100 ) / 4 ) ;
} else
V_94 = ( V_61 == 0 ) ? V_88 : V_89 ;
V_2 -> V_103 [ V_61 ] =
F_32 ( V_2 -> V_104 [ V_61 ] , V_94 ) ;
V_95 = V_2 -> V_104 [ V_61 ] . V_105 . V_106 * 4096 ;
if ( V_95 )
V_16 -> V_76 [ V_61 ] = V_2 -> V_103 [ V_61 ] ;
F_25 ( ( L_19
L_20 ,
V_61 , V_2 -> V_103 [ V_61 ] , V_16 -> V_76 [ V_61 ] ,
V_95 / 1024 ,
V_2 -> V_104 [ V_61 ] . V_105 . V_107 ,
V_2 -> V_104 [ V_61 ] . V_105 . V_108 ,
V_2 -> V_104 [ V_61 ] . V_105 . V_109 ,
V_2 -> V_104 [ V_61 ] . V_105 . V_110 ) ) ;
if ( V_2 -> V_104 [ V_61 ] . V_105 . V_110 )
break;
}
if ( ++ V_61 < 8 && V_2 -> V_104 [ V_61 ] . V_111 )
F_6 ( V_102 L_21 ,
__FILE__ , V_2 -> V_104 [ V_61 ] . V_111 ) ;
V_90 -> V_83 = F_2 ( V_83 ) ;
V_2 -> V_16 = V_16 ;
return 0 ;
}
static struct V_112 *
F_33 ( struct V_113 * V_114 , const char * V_115 )
{
const struct V_116 * V_117 ;
unsigned int V_118 , V_119 ;
void * V_56 ;
struct V_120 * V_121 ;
struct V_112 * V_122 ;
if ( ! V_115 || ! strlen ( V_115 ) )
return NULL ;
V_117 = F_34 ( V_115 ) ;
if ( ! V_117 )
V_117 = F_35 ( 1024 , 768 , ~ ( V_58 ) 0 , ~ ( V_58 ) 0 ) ;
if ( ! V_117 )
return NULL ;
F_25 ( ( V_123 L_22 ,
V_117 -> V_43 , V_117 -> V_42 , V_117 -> V_124 ) ) ;
V_119 = ( ( V_117 -> V_43 + 7 ) / 8 ) * V_117 -> V_42 ;
V_118 = V_119 * 256 ;
V_118 += sizeof( struct V_120 ) ;
V_121 = F_29 ( V_118 , V_92 ) ;
if ( ! V_121 )
return NULL ;
V_121 -> V_125 = 0 ;
V_121 -> V_126 = 255 ;
V_121 -> V_43 = V_117 -> V_43 ;
V_121 -> V_42 = V_117 -> V_42 ;
V_121 -> V_127 = V_128 ;
V_121 -> V_129 = V_119 ;
V_121 -> V_130 = 0 ;
V_121 -> V_131 = 1 ;
V_121 -> V_132 = V_117 -> V_42 - V_121 -> V_131 ;
V_56 = V_121 ;
V_56 += sizeof( struct V_120 ) ;
memcpy ( V_56 , V_117 -> V_133 , V_119 * 256 ) ;
V_122 = F_29 ( sizeof( * V_122 ) , V_92 ) ;
if ( ! V_122 ) {
F_30 ( V_121 ) ;
return NULL ;
}
V_122 -> V_29 = V_121 ;
V_122 -> V_130 = NULL ;
V_114 -> V_134 = V_122 ;
return V_122 ;
}
static struct V_112 *
F_33 ( struct V_113 * V_114 , const char * V_115 )
{
return NULL ;
}
static struct V_112 * F_36 ( struct V_113 * V_135 ,
int (* F_37)( struct V_113 * , int , int ) )
{
struct V_112 * V_28 ;
int V_61 ;
int V_30 = V_136 ;
if ( ( V_28 = F_33 ( V_135 , V_64 [ V_30 ] ) ) )
return V_28 ;
if ( V_34 [ V_30 ] && V_36 [ V_30 ] )
V_63 [ V_30 ] = F_37 ( V_135 ,
V_36 [ V_30 ] , V_34 [ V_30 ] ) ;
for ( V_28 = V_135 -> V_134 , V_61 = V_63 [ V_30 ] ;
V_28 && ( V_61 > 0 ) ;
V_28 = V_28 -> V_130 , V_61 -- ) ;
if ( V_28 )
return V_28 ;
else
return V_135 -> V_134 ;
}
static void F_38 ( struct V_137 * V_135 )
{
F_6 ( V_69 L_23 ,
V_135 -> V_138 [ 0 ] ,
V_135 -> V_138 [ 1 ] ,
V_135 -> V_139 [ 0 ] >> 4 ,
V_135 -> V_139 [ 0 ] & 0x0f ) ;
F_25 ( ( L_24 , V_135 -> V_140 ) ) ;
F_25 ( ( L_25 , V_135 -> V_134 ) ) ;
F_25 ( ( L_26 , V_135 -> V_141 ) ) ;
F_25 ( ( L_27 , V_135 -> V_14 ) ) ;
F_25 ( ( L_28 , V_135 -> V_142 ) ) ;
F_25 ( ( L_29 , V_135 -> V_143 ) ) ;
F_25 ( ( L_30 , V_135 -> V_144 ) ) ;
}
static int F_39 ( struct V_113 * V_114 ,
struct V_137 * V_145 )
{
struct V_120 * V_146 , * V_134 ;
struct V_112 * V_122 ;
V_122 = F_29 ( sizeof( * V_122 ) , V_92 ) ;
if ( ! V_122 )
return 0 ;
V_114 -> V_134 = V_122 ;
V_146 = ( ( void * ) V_145 ) + ( V_145 -> V_134 ) ;
V_134 = V_146 ;
V_122 -> V_29 = V_146 ;
while ( V_146 -> V_130 ) {
V_146 = ( ( void * ) V_134 ) + ( V_146 -> V_130 ) ;
V_122 -> V_130 = F_29 ( sizeof( * V_122 ) , V_92 ) ;
if ( ! V_122 -> V_130 )
return 1 ;
V_122 = V_122 -> V_130 ;
V_122 -> V_29 = V_146 ;
}
V_122 -> V_130 = NULL ;
return 1 ;
}
static int F_40 ( struct V_113 * V_135 , int V_42 , int V_43 )
{
struct V_112 * V_28 ;
int V_61 = 0 ;
for ( V_28 = V_135 -> V_134 ; V_28 ; V_28 = V_28 -> V_130 , V_61 ++ ) {
if ( ( V_28 -> V_29 -> V_43 == V_43 ) &&
( V_28 -> V_29 -> V_42 == V_42 ) )
return V_61 ;
}
return 0 ;
}
static void * F_41 ( struct V_112 * V_147 )
{
unsigned char * V_148 , * V_149 , * V_150 ;
int V_118 = V_147 -> V_29 -> V_129 * 256 + sizeof( struct V_120 ) ;
V_148 = F_29 ( 4 * V_118 , V_92 ) ;
if ( ! V_148 )
return NULL ;
V_149 = V_148 + 3 ;
V_150 = ( unsigned char * ) V_147 -> V_29 ;
while ( V_118 -- ) {
* V_149 = * V_150 ++ ;
V_149 += 4 ;
}
return V_148 + 3 ;
}
static void F_42 ( unsigned long V_54 , unsigned long V_55 ,
void * V_56 )
{
unsigned long V_57 = ( unsigned long ) V_56 ;
while ( V_55 ) {
V_55 -- ;
* ( T_2 * ) V_56 = F_18 ( V_54 ) ;
V_54 += 4 ;
V_56 ++ ;
}
F_15 ( V_57 , ( unsigned long ) V_56 ) ;
}
static struct V_137 * F_43 ( unsigned long V_151 )
{
struct V_137 * V_29 ;
V_58 V_118 ;
struct V_120 * V_146 , * V_134 ;
F_42 ( V_151 + V_152 , sizeof( V_118 ) , & V_118 ) ;
V_118 = ( V_118 + 3 ) / 4 ;
V_29 = F_44 ( V_118 , V_92 ) ;
if ( V_29 ) {
F_42 ( V_151 , V_118 , V_29 ) ;
memmove ( & V_29 -> V_153 , & V_29 -> type [ 0 ] , 0x3c ) ;
V_29 -> type [ 3 ] = V_29 -> V_153 ;
F_45 ( V_29 -> V_141 ) ;
F_45 ( V_29 -> V_134 ) ;
F_45 ( V_29 -> V_14 ) ;
F_45 ( V_29 -> V_154 ) ;
F_45 ( V_29 -> V_38 ) ;
F_45 ( V_29 -> V_47 ) ;
F_45 ( V_29 -> V_21 ) ;
V_146 = ( ( void * ) V_29 ) + V_29 -> V_134 ;
V_134 = V_146 ;
while ( V_146 -> V_130 ) {
F_45 ( V_146 -> V_130 ) ;
V_146 = ( ( void * ) V_134 ) + V_146 -> V_130 ;
}
}
return V_29 ;
}
static struct V_137 * F_46 ( unsigned long V_151 )
{
struct V_137 * V_29 ;
unsigned long V_118 ;
V_118 = F_18 ( V_151 + F_47 ( struct V_137 , V_155 ) ) ;
V_29 = F_44 ( V_118 , V_92 ) ;
if ( V_29 )
F_17 ( V_151 , V_118 , V_29 ) ;
return V_29 ;
}
static int F_48 ( int V_156 , struct V_1 * V_2 ,
unsigned long V_151 )
{
struct V_113 * V_157 ;
struct V_137 * V_29 = NULL ;
unsigned long V_139 ;
V_157 = F_44 ( sizeof *V_157 , V_92 ) ;
if ( ! V_157 )
goto V_158;
if ( V_156 )
V_29 = F_46 ( V_151 ) ;
else
V_29 = F_43 ( V_151 ) ;
if ( ! V_29 )
goto V_158;
if ( ! F_39 ( V_157 , V_29 ) ) {
F_6 ( V_17 L_31 , V_151 ) ;
goto V_158;
}
if ( V_29 -> V_141 )
memcpy ( V_2 -> V_104 , ( ( void * ) V_29 ) + V_29 -> V_141 , sizeof( V_2 -> V_104 ) ) ;
V_151 = ( unsigned long ) F_2 ( V_29 ) ;
V_2 -> V_38 = V_151 + ( V_29 -> V_38 & 0x03ffffff ) ;
V_2 -> V_47 = V_151 + ( V_29 -> V_47 & 0x03ffffff ) ;
V_2 -> V_14 = V_151 + ( V_29 -> V_14 & 0x03ffffff ) ;
V_2 -> V_21 = V_151 + ( V_29 -> V_21 & 0x03ffffff ) ;
V_2 -> V_135 = V_157 ;
V_2 -> V_135 -> V_29 = V_29 ;
V_2 -> V_28 = F_36 ( V_2 -> V_135 , F_40 ) ;
V_2 -> V_34 = V_2 -> V_28 -> V_29 -> V_43 ;
V_2 -> V_36 = V_2 -> V_28 -> V_29 -> V_42 ;
if ( ! V_156 )
V_2 -> V_28 -> V_29 = F_41 ( V_2 -> V_28 ) ;
V_2 -> V_66 = V_29 -> V_159 ;
V_2 -> V_138 [ 0 ] = V_29 -> V_138 [ 0 ] ;
V_2 -> V_138 [ 1 ] = V_29 -> V_138 [ 1 ] ;
F_38 ( V_29 ) ;
if ( V_156 || V_2 -> V_138 [ 1 ] != 0x09A02587 )
goto V_160;
V_139 = ( V_29 -> V_139 [ 0 ] << 8 ) | V_29 -> V_139 [ 1 ] ;
switch ( V_2 -> V_138 [ 0 ] ) {
case V_161 :
if ( V_139 == 0x8408 || V_139 == 0x840b )
goto V_162;
break;
case V_163 :
if ( V_139 == 0x8509 )
goto V_162;
break;
case V_164 :
if ( V_139 == 0x850c )
goto V_162;
}
V_160:
return 1 ;
V_162:
F_6 ( V_17 L_32 ) ;
F_6 ( V_17 L_33
L_34 ) ;
V_158:
F_30 ( V_29 ) ;
F_30 ( V_157 ) ;
return 0 ;
}
static struct V_1 * F_49 ( unsigned long V_151 ,
unsigned long V_89 ,
struct V_165 * V_96 )
{
struct V_1 * V_2 ;
int V_160 ;
V_58 V_166 ;
if ( V_136 >= V_62 ) {
F_6 ( V_102 L_35 ) ;
return NULL ;
}
V_2 = F_29 ( sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 ) {
F_6 ( V_17 L_36 ) ;
return NULL ;
}
F_50 ( & V_2 -> V_13 ) ;
V_167:
if ( F_51 ( V_151 ) )
goto V_158;
V_166 = F_18 ( V_151 ) ;
if ( ( F_52 ( V_166 ) == 0xaa55 ) ) {
unsigned int V_61 , V_168 ;
V_58 * V_169 ;
V_61 = F_18 ( V_151 + 0x04 ) ;
if ( V_61 != 1 ) {
F_6 ( V_102
L_37 , V_61 ) ;
goto V_158;
}
V_2 -> V_96 = V_96 ;
V_61 = F_18 ( V_151 + 0x0c ) ;
F_25 ( ( L_38 ,
F_53 ( V_61 >> 16 ) * 512 / 1024 ) ) ;
V_168 = F_53 ( V_61 & 0xffff ) ;
if ( V_168 ) {
V_169 = ( V_58 * ) & V_2 -> V_98 ;
* V_169 ++ = F_18 ( V_151 + V_168 + 0x00 ) ;
* V_169 ++ = F_18 ( V_151 + V_168 + 0x04 ) ;
* V_169 ++ = F_18 ( V_151 + V_168 + 0x08 ) ;
* V_169 ++ = F_18 ( V_151 + V_168 + 0x0c ) ;
F_25 ( ( L_39 ,
V_168 ) ) ;
for ( V_61 = 0 ; V_61 < 16 ; V_61 ++ )
F_25 ( ( L_40 , V_2 -> V_98 [ V_61 ] ) ) ;
F_25 ( ( L_41 ) ) ;
}
V_151 += F_52 ( F_18 ( V_151 + 8 ) ) ;
F_25 ( ( L_42 , V_166 , V_151 ) ) ;
goto V_167;
}
V_160 = 0 ;
if ( ( V_166 & 0xff ) == 0x01 ) {
F_25 ( ( L_43 ,
V_151 , V_89 ) ) ;
V_160 = F_48 ( 0 , V_2 , V_151 ) ;
}
if ( ( V_166 & 0xffff ) == 0x0303 ) {
F_25 ( ( L_44 ,
V_151 , V_89 ) ) ;
V_160 = F_48 ( 1 , V_2 , V_151 ) ;
}
if ( ! V_160 )
goto V_158;
if ( F_28 ( V_2 , V_151 , V_89 ) )
goto V_158;
if ( V_2 -> V_96 ) {
unsigned long V_170 ;
V_170 = F_31 ( V_2 -> V_96 , V_171 ) ;
F_54 ( V_2 -> V_96 , V_99 , V_170 & ~ V_172 ) ;
F_25 ( ( V_123 L_45 ) ) ;
}
if ( F_1 ( V_2 ) )
goto V_158;
F_7 ( V_2 ) ;
F_24 ( V_2 -> V_16 , V_2 -> V_66 ) ;
F_27 ( V_2 ) ;
F_6 ( V_69 L_46 , V_2 -> V_10 . V_173 ) ;
V_174 [ V_136 ] = V_2 ;
V_136 ++ ;
return V_2 ;
V_158:
F_30 ( V_2 ) ;
return NULL ;
}
static void F_55 ( struct V_1 * V_2 , char * V_175 )
{
if ( strcmp ( V_175 , V_60 ) == 0 )
V_176 = V_2 ;
}
static int F_56 ( struct V_177 * V_178 )
{
char V_179 [ 21 ] ;
struct V_1 * V_2 = NULL ;
int V_89 = V_178 -> V_89 . V_52 ;
if ( V_178 -> V_180 && V_178 -> V_181 [ 0 ] )
V_2 = F_49 ( V_178 -> V_181 [ 0 ] , V_89 , NULL ) ;
if ( ! V_2 )
V_2 = F_49 ( V_89 , V_89 , NULL ) ;
if ( ! V_2 )
V_2 = F_49 ( V_182 -> V_183 , V_89 , NULL ) ;
if ( ! V_2 )
return 1 ;
F_57 ( V_178 , V_179 ) ;
F_55 ( V_2 , V_179 ) ;
return 0 ;
}
static int F_58 ( struct V_165 * V_96 , const struct V_184 * V_185 )
{
#ifdef F_59
unsigned long V_186 , V_170 ;
unsigned int V_187 , V_188 ;
int V_189 ;
struct V_1 * V_2 ;
V_189 = F_60 ( V_96 ) ;
if ( V_189 < 0 ) {
F_61 ( & V_96 -> V_178 , L_47 ) ;
return V_189 ;
}
V_186 = F_31 ( V_96 , 0 ) ;
V_187 = F_62 ( V_96 , 0 ) ;
V_170 = F_31 ( V_96 , V_171 ) ;
V_188 = F_62 ( V_96 , V_171 ) ;
if ( V_170 ) {
F_54 ( V_96 , V_99 , V_170 | V_172 ) ;
F_25 ( ( V_123 L_48 , V_170 ) ) ;
}
F_6 ( V_69 L_49 ,
V_170 , V_188 / 1024 , V_186 , V_187 / 1024 / 1024 ) ;
F_25 ( ( V_123 L_50 ,
V_170 , V_186 ) ) ;
V_2 = F_49 ( V_170 , V_186 , V_96 ) ;
if ( V_2 ) {
char V_179 [ 30 ] ;
F_63 ( V_96 , V_179 ) ;
F_55 ( V_2 , V_179 ) ;
}
if ( ! V_2 ) {
F_6 ( V_102 L_51 ,
F_64 ( V_96 ) ) ;
return - V_190 ;
}
#endif
return 0 ;
}
static void F_65 ( struct V_165 * V_96 )
{
F_66 () ;
}
static void F_67 ( void )
{
if ( V_191 )
return;
V_191 = 1 ;
F_6 ( V_69 L_52
V_192 L_41 ) ;
F_68 ( & V_193 ) ;
F_69 ( F_70 ( & V_194 ) ) ;
if ( ! V_176 )
V_176 = V_174 [ 0 ] ;
}
struct V_1 * F_71 ( unsigned int V_30 )
{
if ( ! V_191 )
F_67 () ;
if ( V_30 == 0 )
return V_176 ;
if ( V_30 > V_136 )
return NULL ;
return V_174 [ V_30 - 1 ] ;
}
