static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , unsigned char * V_6 , T_2 V_7 )
{
int V_8 ;
unsigned char * V_9 = F_2 ( V_7 , V_10 ) ;
if ( ! V_9 ) {
F_3 ( & V_2 -> V_11 , L_1 , V_7 ) ;
return - V_12 ;
}
memcpy ( V_9 , V_6 , V_7 ) ;
V_8 = F_4 ( V_2 ,
F_5 ( V_2 , 0 ) ,
V_3 ,
V_13 | V_14 |
V_15 , V_4 , V_5 ,
V_9 , V_7 , V_16 ) ;
F_6 ( V_9 ) ;
return V_8 ;
}
static int F_7 ( struct V_17 * V_18 , unsigned int * V_19 ,
unsigned int * V_7 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
* V_7 = V_21 -> V_23 * V_21 -> V_24 * ( V_21 -> V_25 -> V_26 >> 3 ) ;
if ( * V_19 == 0 )
* V_19 = V_27 ;
if ( * V_7 * * V_19 > V_27 * 1024 * 1024 )
* V_19 = ( V_27 * 1024 * 1024 ) / * V_7 ;
return 0 ;
}
static void F_8 ( struct V_17 * V_18 , struct V_28 * V_29 )
{
F_9 ( L_2 , V_30 ) ;
if ( F_10 () )
F_11 () ;
F_12 ( & V_29 -> V_31 ) ;
V_29 -> V_31 . V_32 = V_33 ;
}
static int F_13 ( struct V_17 * V_18 , struct V_34 * V_31 ,
enum V_35 V_36 )
{
struct V_20 * V_21 = V_18 -> V_22 ;
struct V_28 * V_29 = F_14 ( V_31 , struct V_28 ,
V_31 ) ;
int V_37 ;
F_15 ( L_3 , V_30 , V_36 , V_21 -> V_25 != NULL ?
V_21 -> V_25 -> V_38 : L_4 ) ;
if ( V_21 -> V_25 == NULL )
return - V_39 ;
V_29 -> V_31 . V_7 = V_21 -> V_23 * V_21 -> V_24 * ( V_21 -> V_25 -> V_26 >> 3 ) ;
if ( V_29 -> V_31 . V_40 != 0 && V_29 -> V_31 . V_41 < V_29 -> V_31 . V_7 ) {
F_15 ( L_5 ) ;
return - V_39 ;
}
V_29 -> V_25 = V_21 -> V_25 ;
V_29 -> V_31 . V_23 = V_21 -> V_23 ;
V_29 -> V_31 . V_24 = V_21 -> V_24 ;
V_29 -> V_31 . V_36 = V_36 ;
if ( V_29 -> V_31 . V_32 == V_33 ) {
V_37 = F_16 ( V_18 , & V_29 -> V_31 , NULL ) ;
if ( V_37 < 0 )
goto V_42;
}
V_29 -> V_31 . V_32 = V_43 ;
return 0 ;
V_42:
F_8 ( V_18 , V_29 ) ;
return V_37 ;
}
static void F_17 ( struct V_17 * V_18 , struct V_34 * V_31 )
{
struct V_28 * V_29 = F_14 ( V_31 , struct V_28 ,
V_31 ) ;
struct V_20 * V_21 = V_18 -> V_22 ;
F_9 ( L_2 , V_30 ) ;
V_29 -> V_31 . V_32 = V_44 ;
F_18 ( & V_29 -> V_31 . V_45 , & V_21 -> V_46 . V_47 ) ;
}
static void F_19 ( struct V_17 * V_18 ,
struct V_34 * V_31 )
{
struct V_28 * V_29 = F_14 ( V_31 , struct V_28 ,
V_31 ) ;
F_9 ( L_2 , V_30 ) ;
F_8 ( V_18 , V_29 ) ;
}
static T_3 F_20 ( struct V_48 * V_48 , char T_4 * V_29 , T_5 V_19 ,
T_6 * V_49 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_50 = 0 ;
F_9 ( L_2 , V_30 ) ;
if ( ! V_29 )
return - V_39 ;
if ( ! V_19 )
return - V_39 ;
if ( F_22 ( & V_21 -> V_51 ) )
return - V_52 ;
V_50 = F_23 ( V_48 , V_48 -> V_53 ,
V_54 ) ;
if ( V_50 == 0 ) {
F_15 ( L_6 , V_30 ,
( int ) V_19 , ( int ) * V_49 ) ;
V_50 = F_24 ( & V_21 -> V_55 , V_29 , V_19 , V_49 ,
V_48 -> V_56 & V_57 ) ;
}
F_25 ( & V_21 -> V_51 ) ;
return V_50 ;
}
static void F_26 ( struct V_20 * V_21 ,
struct V_28 * V_29 ,
int V_58 )
{
int V_59 = 0 ;
struct V_60 V_61 ;
const char * V_62 ;
char * V_63 = F_27 ( & V_29 -> V_31 ) ;
unsigned long V_64 ;
if ( ! V_63 )
return;
V_64 = V_21 -> V_64 ;
if ( V_64 != - 1 ) {
V_62 = ( const char * ) V_21 -> V_65 . V_66 [ V_64 ] . V_67 ;
switch ( V_29 -> V_25 -> V_68 ) {
case V_69 :
V_29 -> V_31 . V_7 = V_58 ;
memcpy ( V_63 , V_62 , V_29 -> V_31 . V_7 ) ;
break;
default:
F_28 (KERN_DEBUG KBUILD_MODNAME L_7 ) ;
}
V_21 -> V_64 = - 1 ;
} else {
F_28 (KERN_ERR KBUILD_MODNAME L_8 ) ;
return;
}
F_15 ( L_9 , V_30 ,
( unsigned long ) V_63 , V_59 ) ;
V_29 -> V_31 . V_70 = V_21 -> V_71 * 2 ;
F_29 ( & V_61 ) ;
V_29 -> V_31 . V_61 = V_61 ;
V_29 -> V_31 . V_32 = V_72 ;
}
static int F_30 ( struct V_20 * V_21 , int V_58 )
{
struct V_73 * V_74 = & V_21 -> V_46 ;
struct V_28 * V_29 ;
unsigned long V_75 = 0 ;
int V_37 = 0 ;
F_15 ( L_10 , & V_74 ) ;
F_31 ( & V_21 -> V_76 , V_75 ) ;
if ( F_32 ( & V_74 -> V_47 ) ) {
F_15 ( L_11 ) ;
V_37 = - 1 ;
goto V_77;
}
V_29 = F_33 ( V_74 -> V_47 . V_78 ,
struct V_28 , V_31 . V_45 ) ;
if ( ! F_34 ( & V_29 -> V_31 . V_79 ) ) {
V_37 = - 1 ;
goto V_77;
}
F_35 ( & V_29 -> V_31 . V_45 ) ;
F_29 ( & V_29 -> V_31 . V_61 ) ;
F_15 ( L_12 , V_29 , V_29 -> V_31 . V_80 ) ;
F_26 ( V_21 , V_29 , V_58 ) ;
F_36 ( & V_29 -> V_31 . V_79 ) ;
F_15 ( L_13 , V_29 , V_29 -> V_31 . V_80 ) ;
V_77:
F_37 ( & V_21 -> V_76 , V_75 ) ;
return V_37 ;
}
static int F_38 ( struct V_20 * V_21 ,
struct V_81 * V_82 ,
struct V_83 * V_84 )
{
unsigned char * V_85 ;
unsigned char * V_86 ;
T_7 V_87 = - 1 ;
struct V_88 * V_89 ;
int V_80 = 0 ;
unsigned char * V_90 = NULL ;
F_9 ( L_14 ) ;
V_87 = V_21 -> V_91 ;
V_89 = & V_21 -> V_65 . V_66 [ V_87 ] ;
if ( V_21 -> V_92 == V_93 ) {
T_2 * V_29 = ( T_2 * ) V_82 -> V_9 ;
for ( V_80 = 0 ; V_80 < V_84 -> V_94 / 2 ; V_80 ++ )
F_39 ( V_29 + V_80 ) ;
}
if ( ! V_21 -> V_95 ) {
V_89 -> V_96 = V_97 ;
return - V_39 ;
}
V_86 = ( T_1 * ) V_82 -> V_9 ;
V_90 = V_85 = V_89 -> V_67 ;
if ( V_89 -> V_96 == V_97 ) {
V_89 -> V_96 = V_98 ;
V_89 -> V_99 = 0 ;
F_9 ( L_15 ) ;
memcpy ( V_90 , V_100 , sizeof( V_100 ) ) ;
V_90 += sizeof( V_100 ) ;
V_101 = 0 ;
memcpy ( V_90 , & V_101 , 1 ) ;
V_90 ++ ;
memcpy ( V_90 , V_86 , 64 ) ;
V_90 += 64 ;
V_101 = 1 ;
memcpy ( V_90 , & V_101 , 1 ) ;
V_90 ++ ;
memcpy ( V_90 , V_86 + 64 , 64 ) ;
V_90 += 64 ;
memcpy ( V_90 , V_102 , sizeof( V_102 ) ) ;
V_90 += sizeof( V_102 ) ;
memcpy ( V_90 , V_86 + 128 ,
V_84 -> V_94 - 128 ) ;
V_90 += V_84 -> V_94 - 128 ;
F_9 ( L_16 ,
V_86 [ 0 ] , V_86 [ 1 ] , V_86 [ 2 ] ,
V_86 [ 3 ] , V_86 [ 4 ] , V_86 [ 5 ] ,
V_86 [ 6 ] , V_86 [ 7 ] , V_86 [ 8 ] ) ;
V_89 -> V_99 = V_90 - V_85 ;
} else {
if ( V_89 -> V_99 + V_84 -> V_94 > V_103 ) {
F_40 ( & V_21 -> V_2 -> V_11 ,
L_17
L_18 ,
V_30 , V_103 ) ;
} else {
V_85 += V_89 -> V_99 ;
memcpy ( V_85 , V_86 , V_84 -> V_94 ) ;
V_89 -> V_99 += V_84 -> V_94 ;
}
}
if ( V_84 -> V_94 < V_82 -> V_104 ) {
F_9 ( L_19 , V_87 ) ;
V_21 -> V_64 = V_21 -> V_91 ;
V_21 -> V_91 ++ ;
if ( V_21 -> V_91 == V_21 -> V_65 . V_105 )
V_21 -> V_91 = 0 ;
V_90 = V_85 = V_89 -> V_67 ;
V_90 += V_89 -> V_99 - 2 ;
while ( V_90 > V_85 ) {
if ( * V_90 == 0xFF && * ( V_90 + 1 ) == 0xD9
&& * ( V_90 + 2 ) == 0xFF )
break;
V_90 -- ;
}
if ( V_90 == V_85 )
F_15 ( L_20 ) ;
while ( V_90 > V_85 ) {
if ( * V_90 == 0xFF && * ( V_90 + 1 ) == 0xFF
&& * ( V_90 + 2 ) == 0xFF )
break;
V_90 -- ;
}
if ( V_90 != V_85 ) {
F_15 ( L_21 , ++ ( V_21 -> V_106 ) ) ;
} else if ( V_21 -> V_95 ) {
if ( V_21 -> V_107 )
V_21 -> V_107 -- ;
else {
F_9 ( L_22 ,
V_89 -> V_99 ,
V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] , V_85 [ 3 ] ,
V_85 [ 4 ] , V_85 [ 5 ] , V_85 [ 6 ] , V_85 [ 7 ] ) ;
F_30 ( V_21 , V_89 -> V_99 ) ;
}
}
V_21 -> V_71 ++ ;
V_89 -> V_96 = V_97 ;
V_89 -> V_99 = 0 ;
}
return 0 ;
}
static int F_41 ( struct V_48 * V_48 , void * V_108 ,
struct V_109 * V_110 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_42 ( V_110 -> V_111 , V_112 , sizeof( V_110 -> V_111 ) ) ;
F_42 ( V_110 -> V_113 , V_21 -> V_2 -> V_114 , sizeof( V_110 -> V_113 ) ) ;
F_42 ( V_110 -> V_115 , F_43 ( & V_21 -> V_2 -> V_11 ) ,
sizeof( V_110 -> V_115 ) ) ;
V_110 -> V_116 = V_117 |
V_118 |
V_119 ;
V_110 -> V_120 = V_110 -> V_116 | V_121 ;
return 0 ;
}
static int F_44 ( struct V_48 * V_48 , void * V_108 ,
struct V_122 * V_80 )
{
if ( V_80 -> V_5 != 0 )
return - V_39 ;
strcpy ( V_80 -> V_38 , V_112 L_23 ) ;
V_80 -> type = V_123 ;
return 0 ;
}
static int F_45 ( struct V_48 * V_48 , void * V_108 ,
unsigned int * V_80 )
{
* V_80 = 0 ;
return 0 ;
}
static int F_46 ( struct V_48 * V_48 , void * V_108 ,
unsigned int V_80 )
{
if ( V_80 != 0 )
return - V_39 ;
return 0 ;
}
static int F_47 ( struct V_124 * V_125 )
{
struct V_20 * V_21 =
F_14 ( V_125 -> V_126 , struct V_20 , V_127 ) ;
int V_128 ;
switch ( V_125 -> V_129 ) {
case V_130 :
F_1 ( V_21 -> V_2 , 1 , 0x2001 , 0 , NULL , 0 ) ;
V_128 = ( 0x60 << 8 ) + 127 - V_125 -> V_131 ;
F_1 ( V_21 -> V_2 , 1 , V_128 , 0 , NULL , 0 ) ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_48 ( struct V_48 * V_48 ,
void * V_108 , struct V_132 * V_133 )
{
if ( V_133 -> V_5 > 0 )
return - V_39 ;
V_133 -> V_75 = V_134 ;
strcpy ( V_133 -> V_135 , V_136 [ 0 ] . V_38 ) ;
V_133 -> V_137 = V_136 [ 0 ] . V_68 ;
return 0 ;
}
static char * F_49 ( T_8 V_137 , char * V_29 )
{
V_29 [ 0 ] = V_137 & 0xff ;
V_29 [ 1 ] = ( V_137 >> 8 ) & 0xff ;
V_29 [ 2 ] = ( V_137 >> 16 ) & 0xff ;
V_29 [ 3 ] = ( V_137 >> 24 ) & 0xff ;
V_29 [ 4 ] = '\0' ;
return V_29 ;
}
static int F_50 ( struct V_48 * V_48 , void * V_108 ,
struct V_138 * V_133 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
char V_139 [ 5 ] ;
if ( V_21 == NULL )
return - V_140 ;
if ( V_133 -> V_25 . V_141 . V_137 != V_69 ) {
F_15 ( L_24 , V_30 ,
F_49 ( V_133 -> V_25 . V_141 . V_137 , V_139 ) ) ;
return - V_39 ;
}
if ( ! ( V_133 -> V_25 . V_141 . V_23 == 160 && V_133 -> V_25 . V_141 . V_24 == 120 ) &&
! ( V_133 -> V_25 . V_141 . V_23 == 640 && V_133 -> V_25 . V_141 . V_24 == 480 ) ) {
V_133 -> V_25 . V_141 . V_23 = 320 ;
V_133 -> V_25 . V_141 . V_24 = 240 ;
}
V_133 -> V_25 . V_141 . V_36 = V_142 ;
V_133 -> V_25 . V_141 . V_143 = V_133 -> V_25 . V_141 . V_23 * 2 ;
V_133 -> V_25 . V_141 . V_144 = V_133 -> V_25 . V_141 . V_24 * V_133 -> V_25 . V_141 . V_143 ;
V_133 -> V_25 . V_141 . V_145 = V_146 ;
V_133 -> V_25 . V_141 . V_108 = 0 ;
F_15 ( L_25 , V_30 ,
F_49 ( V_133 -> V_25 . V_141 . V_137 , V_139 ) ,
V_133 -> V_25 . V_141 . V_36 ) ;
return 0 ;
}
static int F_51 ( struct V_48 * V_48 , void * V_108 ,
struct V_138 * V_133 )
{
struct V_20 * V_21 ;
if ( V_48 == NULL )
return - V_140 ;
V_21 = F_21 ( V_48 ) ;
V_133 -> V_25 . V_141 . V_137 = V_136 [ 0 ] . V_68 ;
V_133 -> V_25 . V_141 . V_36 = V_142 ;
V_133 -> V_25 . V_141 . V_23 = V_21 -> V_23 ;
V_133 -> V_25 . V_141 . V_24 = V_21 -> V_24 ;
V_133 -> V_25 . V_141 . V_143 = V_133 -> V_25 . V_141 . V_23 * 2 ;
V_133 -> V_25 . V_141 . V_144 = V_133 -> V_25 . V_141 . V_24 * V_133 -> V_25 . V_141 . V_143 ;
V_133 -> V_25 . V_141 . V_145 = V_146 ;
V_133 -> V_25 . V_141 . V_108 = 0 ;
return 0 ;
}
static int F_52 ( struct V_48 * V_48 , void * V_108 ,
struct V_138 * V_133 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
struct V_17 * V_147 = & V_21 -> V_55 ;
char V_139 [ 5 ] ;
int V_148 = F_50 ( V_48 , V_21 , V_133 ) ;
int V_80 ;
if ( V_148 < 0 )
return V_148 ;
F_53 ( & V_147 -> V_149 ) ;
if ( F_54 ( & V_21 -> V_55 ) ) {
F_15 ( L_26 , V_30 ) ;
V_148 = - V_150 ;
goto V_151;
}
if ( V_21 -> V_152 ) {
F_15 ( L_27 , V_30 ) ;
V_148 = - V_150 ;
goto V_151;
}
V_21 -> V_23 = V_133 -> V_25 . V_141 . V_23 ;
V_21 -> V_24 = V_133 -> V_25 . V_141 . V_24 ;
F_15 ( L_28 , V_30 ,
V_21 -> V_23 , V_21 -> V_24 ) ;
V_133 -> V_25 . V_141 . V_143 = V_133 -> V_25 . V_141 . V_23 * 2 ;
V_133 -> V_25 . V_141 . V_144 = V_133 -> V_25 . V_141 . V_24 * V_133 -> V_25 . V_141 . V_143 ;
V_133 -> V_25 . V_141 . V_145 = V_146 ;
V_133 -> V_25 . V_141 . V_108 = 0 ;
V_21 -> V_55 . V_36 = V_133 -> V_25 . V_141 . V_36 ;
if ( V_133 -> V_25 . V_141 . V_23 == 160 && V_133 -> V_25 . V_141 . V_24 == 120 )
V_153 = 1 ;
else if ( V_133 -> V_25 . V_141 . V_23 == 640 && V_133 -> V_25 . V_141 . V_24 == 480 )
V_153 = 2 ;
else
V_153 = 0 ;
V_154 [ 0 ] = V_153 ;
V_155 [ 2 ] . V_4 = 0xf000 + V_153 ;
V_156 [ 1 ] . V_4 = 0xf000 + V_153 ;
if ( V_21 -> V_92 == V_157 ) {
switch ( V_153 ) {
case 1 :
V_156 [ 1 ] . V_4 = 0xf000 + 4 ;
break;
case 2 :
V_156 [ 1 ] . V_4 = 0xf000 + 0 ;
break;
default:
V_156 [ 1 ] . V_4 = 0xf000 + 1 ;
break;
}
}
V_102 [ 437 ] = V_21 -> V_24 / 256 ;
V_102 [ 438 ] = V_21 -> V_24 % 256 ;
V_102 [ 439 ] = V_21 -> V_23 / 256 ;
V_102 [ 440 ] = V_21 -> V_23 % 256 ;
for ( V_80 = 0 ; V_158 [ V_21 -> V_92 ] [ V_80 ] . V_7 != - 1 ; V_80 ++ ) {
V_148 =
F_1 ( V_21 -> V_2 , 1 , V_158 [ V_21 -> V_92 ] [ V_80 ] . V_4 ,
0 , V_158 [ V_21 -> V_92 ] [ V_80 ] . V_159 ,
V_158 [ V_21 -> V_92 ] [ V_80 ] . V_7 ) ;
if ( V_148 < 0 ) {
F_3 ( & V_21 -> V_2 -> V_11 ,
L_29 , V_80 ) ;
goto V_151;
}
}
F_55 ( 100 ) ;
V_21 -> V_107 = 2 ;
V_148 = 0 ;
V_151:
F_25 ( & V_147 -> V_149 ) ;
F_15 ( L_25 , V_30 ,
F_49 ( V_133 -> V_25 . V_141 . V_137 , V_139 ) ,
V_133 -> V_25 . V_141 . V_36 ) ;
return V_148 ;
}
static int F_56 ( struct V_48 * V_48 , void * V_108 ,
struct V_160 * V_161 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
if ( V_21 -> V_152 && V_21 -> V_152 != V_108 )
return - V_150 ;
return F_57 ( & V_21 -> V_55 , V_161 ) ;
}
static int F_58 ( struct V_48 * V_48 ,
void * V_108 ,
struct V_162 * V_161 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
V_37 = F_59 ( & V_21 -> V_55 , V_161 ) ;
return V_37 ;
}
static int F_60 ( struct V_48 * V_48 ,
void * V_108 ,
struct V_162 * V_161 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_9 ( L_2 , V_30 ) ;
if ( V_21 -> V_152 && V_21 -> V_152 != V_108 )
return - V_150 ;
V_37 = F_61 ( & V_21 -> V_55 , V_161 ) ;
return V_37 ;
}
static int F_62 ( struct V_48 * V_48 ,
void * V_108 ,
struct V_162 * V_161 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_9 ( L_2 , V_30 ) ;
if ( V_21 -> V_152 && V_21 -> V_152 != V_108 )
return - V_150 ;
V_37 = F_63 ( & V_21 -> V_55 , V_161 , V_48 -> V_56 & V_57 ) ;
return V_37 ;
}
static void F_64 ( struct V_83 * V_84 )
{
struct V_81 * V_82 ;
struct V_20 * V_21 ;
int V_163 ;
V_82 = V_84 -> V_164 ;
F_9 ( L_30 , V_30 , V_84 , V_84 -> V_8 ) ;
if ( V_82 == NULL ) {
F_28 (KERN_ERR KBUILD_MODNAME L_31 ) ;
return;
}
V_21 = V_82 -> V_21 ;
if ( V_21 == NULL ) {
F_28 (KERN_ERR KBUILD_MODNAME L_31 ) ;
return;
}
if ( V_84 -> V_8 == - V_165 ) {
F_15 ( L_32 , V_30 ) ;
V_82 -> V_166 ++ ;
return;
}
if ( V_82 -> V_32 == 0 ) {
F_15 ( L_33 ) ;
return;
}
if ( V_84 -> V_94 > V_82 -> V_104 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_34 ) ;
return;
}
if ( V_84 -> V_8 == 0 )
F_38 ( V_21 , V_82 , V_84 ) ;
else {
V_82 -> V_166 ++ ;
F_15 ( L_35 , V_30 , V_84 -> V_8 ) ;
}
V_163 = F_65 ( V_21 -> V_2 , V_21 -> V_167 ) ;
F_66 ( V_82 -> V_168 , V_21 -> V_2 ,
V_163 ,
V_82 -> V_9 ,
V_82 -> V_104 ,
F_64 , V_82 ) ;
if ( V_82 -> V_32 != 0 ) {
V_84 -> V_8 = F_67 ( V_82 -> V_168 ,
V_169 ) ;
if ( V_84 -> V_8 )
F_3 ( & V_21 -> V_2 -> V_11 ,
L_36 ,
V_84 -> V_8 ) ;
} else
F_15 ( L_37 ) ;
}
static int F_68 ( struct V_20 * V_21 )
{
int V_163 ;
int V_170 ;
struct V_81 * V_82 = V_21 -> V_163 ;
V_163 = F_65 ( V_21 -> V_2 , V_21 -> V_167 ) ;
F_15 ( L_38 , V_30 , V_21 -> V_167 ) ;
V_82 -> V_32 = 1 ;
V_82 -> V_166 = 0 ;
V_82 -> V_168 = F_69 ( 0 , V_10 ) ;
if ( ! V_82 -> V_168 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_39 ) ;
return - V_12 ;
}
F_66 ( V_82 -> V_168 , V_21 -> V_2 ,
V_163 ,
V_82 -> V_9 ,
V_82 -> V_104 ,
F_64 , V_82 ) ;
F_15 ( L_40 , V_82 -> V_168 ) ;
V_170 = F_67 ( V_82 -> V_168 , V_10 ) ;
if ( V_170 ) {
F_28 (KERN_ERR KBUILD_MODNAME L_41 ) ;
return V_170 ;
}
return 0 ;
}
static void F_70 ( struct V_20 * V_21 )
{
struct V_81 * V_82 ;
if ( V_21 == NULL ) {
F_28 (KERN_ERR KBUILD_MODNAME L_42 ) ;
return;
}
F_15 ( L_43 ) ;
V_82 = V_21 -> V_163 ;
if ( V_82 ) {
if ( V_82 -> V_32 != 0 )
V_82 -> V_32 = 0 ;
if ( V_82 -> V_168 ) {
F_71 ( V_82 -> V_168 ) ;
F_72 ( V_82 -> V_168 ) ;
V_82 -> V_168 = NULL ;
}
}
return;
}
static int F_73 ( struct V_20 * V_21 )
{
int V_171 ;
F_15 ( L_44 ) ;
V_21 -> V_64 = - 1 ;
V_21 -> V_91 = 0 ;
for ( V_171 = 0 ; V_171 < V_172 ; V_171 ++ ) {
V_21 -> V_65 . V_66 [ V_171 ] . V_96 = V_97 ;
V_21 -> V_65 . V_66 [ V_171 ] . V_99 = 0 ;
}
V_21 -> V_95 = 1 ;
return 0 ;
}
static inline int F_74 ( struct V_20 * V_21 )
{
V_21 -> V_95 = 0 ;
return 0 ;
}
static int F_75 ( struct V_20 * V_21 )
{
int V_173 ;
int V_80 , V_171 ;
for ( V_80 = 0 ; V_158 [ V_21 -> V_92 ] [ V_80 ] . V_7 != - 1 ; V_80 ++ ) {
V_173 = F_1 ( V_21 -> V_2 , 1 , V_158 [ V_21 -> V_92 ] [ V_80 ] . V_4 ,
0 , V_158 [ V_21 -> V_92 ] [ V_80 ] . V_159 ,
V_158 [ V_21 -> V_92 ] [ V_80 ] . V_7 ) ;
if ( V_173 < 0 ) {
F_3 ( & V_21 -> V_2 -> V_11 ,
L_45 , V_80 ) ;
return V_173 ;
}
}
V_21 -> V_107 = 2 ;
V_21 -> V_64 = - 1 ;
V_21 -> V_91 = 0 ;
V_21 -> V_71 = 0 ;
for ( V_171 = 0 ; V_171 < V_172 ; V_171 ++ ) {
V_21 -> V_65 . V_66 [ V_171 ] . V_96 = V_97 ;
V_21 -> V_65 . V_66 [ V_171 ] . V_99 = 0 ;
}
F_76 ( & V_21 -> V_127 ) ;
return 0 ;
}
static int F_23 ( struct V_48 * V_48 , void * V_108 ,
enum V_174 type )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_173 ;
F_15 ( L_2 , V_30 ) ;
if ( type != V_54 )
return - V_39 ;
if ( V_21 -> V_152 && V_21 -> V_152 != V_108 )
return - V_150 ;
V_173 = F_75 ( V_21 ) ;
if ( V_173 )
return V_173 ;
V_173 = F_77 ( & V_21 -> V_55 ) ;
if ( V_173 == 0 ) {
F_73 ( V_21 ) ;
V_21 -> V_152 = V_48 -> V_53 ;
}
return V_173 ;
}
static int F_78 ( struct V_48 * V_48 , void * V_108 ,
enum V_174 type )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_15 ( L_2 , V_30 ) ;
if ( type != V_54 )
return - V_39 ;
if ( V_21 -> V_152 && V_21 -> V_152 != V_108 )
return - V_150 ;
F_74 ( V_21 ) ;
return F_79 ( & V_21 -> V_55 ) ;
}
static int F_80 ( struct V_48 * V_48 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_50 ;
F_15 ( L_2 , V_30 ) ;
if ( F_22 ( & V_21 -> V_51 ) )
return - V_52 ;
V_50 = F_81 ( V_48 ) ;
if ( V_50 )
goto V_151;
F_55 ( 100 ) ;
V_50 = 0 ;
V_151:
F_25 ( & V_21 -> V_51 ) ;
F_15 ( L_46 , V_30 , V_50 ) ;
return V_50 ;
}
static void F_82 ( struct V_175 * V_176 )
{
struct V_20 * V_21 =
F_14 ( V_176 , struct V_20 , V_176 ) ;
unsigned long V_80 ;
F_83 ( & V_21 -> V_176 ) ;
F_84 ( & V_21 -> V_55 ) ;
for ( V_80 = 0 ; V_80 < V_172 ; V_80 ++ ) {
if ( V_21 -> V_65 . V_66 [ V_80 ] . V_67 ) {
F_15 ( L_47 , V_21 -> V_65 . V_66 [ V_80 ] . V_67 ) ;
F_85 ( V_21 -> V_65 . V_66 [ V_80 ] . V_67 ) ;
}
V_21 -> V_65 . V_66 [ V_80 ] . V_67 = NULL ;
}
F_86 ( & V_21 -> V_127 ) ;
F_6 ( V_21 -> V_163 -> V_9 ) ;
F_6 ( V_21 ) ;
}
static int F_87 ( struct V_48 * V_48 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_80 ;
F_15 ( L_2 , V_30 ) ;
V_21 = F_21 ( V_48 ) ;
F_53 ( & V_21 -> V_51 ) ;
V_2 = V_21 -> V_2 ;
if ( V_48 -> V_53 == V_21 -> V_152 ) {
if ( V_21 -> V_95 )
F_74 ( V_21 ) ;
F_79 ( & V_21 -> V_55 ) ;
for ( V_80 = 0 ; V_80 < 2 ; V_80 ++ ) {
F_1 ( V_2 , 1 , V_158 [ V_21 -> V_92 ] [ V_80 ] . V_4 ,
0 , V_158 [ V_21 -> V_92 ] [ V_80 ] . V_159 ,
V_158 [ V_21 -> V_92 ] [ V_80 ] . V_7 ) ;
}
V_21 -> V_152 = NULL ;
}
F_55 ( 100 ) ;
F_25 ( & V_21 -> V_51 ) ;
return F_88 ( V_48 ) ;
}
static int F_89 ( struct V_48 * V_48 , struct V_177 * V_178 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_148 ;
if ( V_21 == NULL ) {
F_15 ( L_48 , V_30 ) ;
return - V_140 ;
}
F_15 ( L_49 , ( unsigned long ) V_178 ) ;
V_148 = F_90 ( & V_21 -> V_55 , V_178 ) ;
F_15 ( L_50 ,
( unsigned long ) V_178 -> V_179 ,
( unsigned long ) V_178 -> V_180 - ( unsigned long ) V_178 -> V_179 , V_148 ) ;
return V_148 ;
}
static unsigned int F_91 ( struct V_48 * V_48 ,
struct V_181 * V_182 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
struct V_17 * V_147 = & V_21 -> V_55 ;
unsigned V_173 = F_92 ( V_48 , V_182 ) ;
F_9 ( L_2 , V_30 ) ;
return V_173 | F_93 ( V_48 , V_147 , V_182 ) ;
}
static int F_94 ( struct V_20 * V_21 )
{
struct V_81 * V_163 = V_21 -> V_163 ;
unsigned long V_80 ;
F_15 ( L_51 , V_21 ) ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
V_163 -> V_21 = V_21 ;
V_163 -> V_104 = V_183 ;
V_163 -> V_9 = F_95 ( V_163 -> V_104 ,
V_10 ) ;
if ( V_163 -> V_9 == NULL ) {
F_15 ( L_52 ) ;
return - V_12 ;
}
V_21 -> V_95 = 0 ;
V_21 -> V_71 = 0 ;
for ( V_80 = 0 ; V_80 < V_172 ; V_80 ++ ) {
V_21 -> V_65 . V_66 [ V_80 ] . V_67 = F_96 ( V_103 ) ;
F_15 ( L_53 ,
& V_21 -> V_65 . V_66 [ V_80 ] , V_80 ,
V_21 -> V_65 . V_66 [ V_80 ] . V_67 ) ;
if ( V_21 -> V_65 . V_66 [ V_80 ] . V_67 == NULL ) {
F_28 (KERN_INFO KBUILD_MODNAME L_54
L_55 ) ;
break;
}
}
if ( V_80 == 0 ) {
F_28 (KERN_INFO KBUILD_MODNAME L_56 ) ;
F_6 ( V_21 -> V_163 -> V_9 ) ;
V_21 -> V_163 -> V_9 = NULL ;
return - V_12 ;
} else
V_21 -> V_65 . V_105 = V_80 ;
for ( V_80 = 0 ; V_80 < V_172 ; V_80 ++ ) {
V_21 -> V_65 . V_66 [ V_80 ] . V_96 = V_97 ;
V_21 -> V_65 . V_66 [ V_80 ] . V_99 = 0 ;
}
V_21 -> V_91 = 0 ;
V_21 -> V_64 = - 1 ;
F_68 ( V_21 ) ;
F_15 ( L_57 ) ;
return 0 ;
}
static int F_97 ( struct V_184 * V_185 ,
const struct V_186 * V_129 )
{
struct V_1 * V_2 = F_98 ( V_185 ) ;
struct V_20 * V_21 = NULL ;
struct V_187 * V_188 ;
struct V_189 * V_190 ;
struct V_191 * V_192 ;
int V_50 ;
int V_80 ;
F_15 ( L_58 ) ;
F_40 ( & V_185 -> V_11 , V_112 L_59 ) ;
F_40 ( & V_185 -> V_11 , L_60 ,
F_99 ( V_2 -> V_193 . V_194 ) ,
F_99 ( V_2 -> V_193 . V_195 ) ) ;
V_21 = F_95 ( sizeof( struct V_20 ) , V_10 ) ;
if ( V_21 == NULL ) {
F_3 ( & V_2 -> V_11 , L_61 ) ;
return - V_12 ;
}
V_21 -> V_176 . V_196 = F_82 ;
V_50 = F_100 ( & V_185 -> V_11 , & V_21 -> V_176 ) ;
if ( V_50 < 0 ) {
F_3 ( & V_2 -> V_11 , L_62 ) ;
F_6 ( V_21 ) ;
return V_50 ;
}
V_192 = & V_21 -> V_127 ;
F_101 ( V_192 , 1 ) ;
F_102 ( V_192 , & V_197 ,
V_130 , 0 , 127 , 1 , 64 ) ;
if ( V_192 -> error ) {
V_50 = V_192 -> error ;
F_3 ( & V_2 -> V_11 , L_63 ) ;
goto V_42;
}
V_21 -> V_92 = V_129 -> V_198 ;
F_103 ( & V_21 -> V_51 ) ;
V_21 -> V_199 = V_200 ;
V_21 -> V_199 . V_51 = & V_21 -> V_51 ;
V_21 -> V_199 . V_176 = & V_21 -> V_176 ;
V_21 -> V_199 . V_127 = & V_21 -> V_127 ;
F_104 ( V_201 , & V_21 -> V_199 . V_75 ) ;
F_105 ( & V_21 -> V_199 , V_21 ) ;
if ( V_202 )
V_21 -> V_199 . V_202 = V_203 | V_204 ;
V_21 -> V_2 = V_2 ;
switch ( V_153 ) {
case 1 :
F_40 ( & V_2 -> V_11 , L_64 ) ;
V_21 -> V_23 = 160 ;
V_21 -> V_24 = 120 ;
break;
case 2 :
F_40 ( & V_2 -> V_11 , L_65 ) ;
V_21 -> V_23 = 640 ;
V_21 -> V_24 = 480 ;
break;
default:
F_40 ( & V_2 -> V_11 , L_66 ) ;
V_21 -> V_23 = 320 ;
V_21 -> V_24 = 240 ;
break;
}
V_154 [ 0 ] = V_153 ;
V_155 [ 2 ] . V_4 = 0xf000 + V_153 ;
V_156 [ 1 ] . V_4 = 0xf000 + V_153 ;
if ( V_21 -> V_92 == V_157 ) {
switch ( V_153 ) {
case 1 :
V_156 [ 1 ] . V_4 = 0xf000 + 4 ;
break;
case 2 :
V_156 [ 1 ] . V_4 = 0xf000 + 0 ;
break;
default:
V_156 [ 1 ] . V_4 = 0xf000 + 1 ;
break;
}
}
V_102 [ 437 ] = V_21 -> V_24 / 256 ;
V_102 [ 438 ] = V_21 -> V_24 % 256 ;
V_102 [ 439 ] = V_21 -> V_23 / 256 ;
V_102 [ 440 ] = V_21 -> V_23 % 256 ;
V_21 -> V_106 = 0 ;
F_15 ( L_67 , V_21 , V_21 -> V_2 , V_185 ) ;
V_188 = V_185 -> V_205 ;
F_15 ( L_68 , V_188 -> V_206 . V_207 ) ;
for ( V_80 = 0 ; V_80 < V_188 -> V_206 . V_207 ; ++ V_80 ) {
V_190 = & V_188 -> V_190 [ V_80 ] . V_206 ;
if ( ! V_21 -> V_167 && F_106 ( V_190 ) ) {
V_21 -> V_167 = V_190 -> V_208 ;
}
}
if ( ! V_21 -> V_167 ) {
V_50 = - V_12 ;
F_3 ( & V_185 -> V_11 , L_69 ) ;
goto V_42;
}
F_107 ( & V_21 -> V_46 . V_47 ) ;
V_21 -> V_46 . V_21 = V_21 ;
F_108 ( V_185 , V_21 ) ;
V_50 = F_94 ( V_21 ) ;
if ( ! V_50 )
V_50 = F_76 ( V_192 ) ;
if ( V_50 )
goto V_42;
F_109 ( & V_21 -> V_76 ) ;
V_21 -> V_25 = V_136 ;
F_110 ( & V_21 -> V_55 , & V_209 ,
NULL , & V_21 -> V_76 ,
V_54 ,
V_142 ,
sizeof( struct V_28 ) , V_21 , & V_21 -> V_51 ) ;
V_50 = F_111 ( & V_21 -> V_199 , V_210 , - 1 ) ;
if ( V_50 ) {
F_3 ( & V_2 -> V_11 , L_70 ) ;
goto V_42;
}
F_40 ( & V_2 -> V_11 , V_112 L_71 ,
F_112 ( & V_21 -> V_199 ) ) ;
return 0 ;
V_42:
F_86 ( V_192 ) ;
F_83 ( & V_21 -> V_176 ) ;
F_6 ( V_21 ) ;
return V_50 ;
}
static void F_113 ( struct V_184 * V_185 )
{
struct V_20 * V_21 = F_114 ( V_185 ) ;
F_53 ( & V_21 -> V_51 ) ;
F_108 ( V_185 , NULL ) ;
F_40 ( & V_185 -> V_11 , V_112 L_72 ) ;
F_115 ( & V_21 -> V_199 ) ;
F_116 ( & V_21 -> V_176 ) ;
if ( V_21 -> V_95 )
F_74 ( V_21 ) ;
F_70 ( V_21 ) ;
F_25 ( & V_21 -> V_51 ) ;
F_117 ( & V_21 -> V_176 ) ;
}
static int F_118 ( struct V_184 * V_185 , T_9 V_211 )
{
struct V_20 * V_21 = F_114 ( V_185 ) ;
V_21 -> V_212 = V_21 -> V_95 ;
if ( ! V_21 -> V_212 )
return 0 ;
F_74 ( V_21 ) ;
F_70 ( V_21 ) ;
return 0 ;
}
static int F_119 ( struct V_184 * V_185 )
{
struct V_20 * V_21 = F_114 ( V_185 ) ;
int V_173 ;
if ( ! V_21 -> V_212 )
return 0 ;
F_68 ( V_21 ) ;
V_173 = F_75 ( V_21 ) ;
if ( ! V_173 )
F_73 ( V_21 ) ;
return V_173 ;
}
