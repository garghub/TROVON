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
const char * V_60 ;
char * V_61 = F_27 ( & V_29 -> V_31 ) ;
unsigned long V_62 ;
if ( ! V_61 )
return;
V_62 = V_21 -> V_62 ;
if ( V_62 != - 1 ) {
V_60 = ( const char * ) V_21 -> V_63 . V_64 [ V_62 ] . V_65 ;
switch ( V_29 -> V_25 -> V_66 ) {
case V_67 :
V_29 -> V_31 . V_7 = V_58 ;
memcpy ( V_61 , V_60 , V_29 -> V_31 . V_7 ) ;
break;
default:
F_28 (KERN_DEBUG KBUILD_MODNAME L_7 ) ;
}
V_21 -> V_62 = - 1 ;
} else {
F_28 (KERN_ERR KBUILD_MODNAME L_8 ) ;
return;
}
F_15 ( L_9 , V_30 ,
( unsigned long ) V_61 , V_59 ) ;
V_29 -> V_31 . V_68 = V_21 -> V_69 * 2 ;
F_29 ( & V_29 -> V_31 . V_70 ) ;
V_29 -> V_31 . V_32 = V_71 ;
}
static int F_30 ( struct V_20 * V_21 , int V_58 )
{
struct V_72 * V_73 = & V_21 -> V_46 ;
struct V_28 * V_29 ;
unsigned long V_74 = 0 ;
int V_37 = 0 ;
F_15 ( L_10 , & V_73 ) ;
F_31 ( & V_21 -> V_75 , V_74 ) ;
if ( F_32 ( & V_73 -> V_47 ) ) {
F_15 ( L_11 ) ;
V_37 = - 1 ;
goto V_76;
}
V_29 = F_33 ( V_73 -> V_47 . V_77 ,
struct V_28 , V_31 . V_45 ) ;
if ( ! F_34 ( & V_29 -> V_31 . V_78 ) ) {
V_37 = - 1 ;
goto V_76;
}
F_35 ( & V_29 -> V_31 . V_45 ) ;
F_29 ( & V_29 -> V_31 . V_70 ) ;
F_15 ( L_12 , V_29 , V_29 -> V_31 . V_79 ) ;
F_26 ( V_21 , V_29 , V_58 ) ;
F_36 ( & V_29 -> V_31 . V_78 ) ;
F_15 ( L_13 , V_29 , V_29 -> V_31 . V_79 ) ;
V_76:
F_37 ( & V_21 -> V_75 , V_74 ) ;
return V_37 ;
}
static int F_38 ( struct V_20 * V_21 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
unsigned char * V_84 ;
unsigned char * V_85 ;
T_7 V_86 = - 1 ;
struct V_87 * V_88 ;
int V_79 = 0 ;
unsigned char * V_89 = NULL ;
F_9 ( L_14 ) ;
V_86 = V_21 -> V_90 ;
V_88 = & V_21 -> V_63 . V_64 [ V_86 ] ;
if ( V_21 -> V_91 == V_92 ) {
T_2 * V_29 = ( T_2 * ) V_81 -> V_9 ;
for ( V_79 = 0 ; V_79 < V_83 -> V_93 / 2 ; V_79 ++ )
F_39 ( V_29 + V_79 ) ;
}
if ( ! V_21 -> V_94 ) {
V_88 -> V_95 = V_96 ;
return - V_39 ;
}
V_85 = ( T_1 * ) V_81 -> V_9 ;
V_89 = V_84 = V_88 -> V_65 ;
if ( V_88 -> V_95 == V_96 ) {
V_88 -> V_95 = V_97 ;
V_88 -> V_98 = 0 ;
F_9 ( L_15 ) ;
memcpy ( V_89 , V_99 , sizeof( V_99 ) ) ;
V_89 += sizeof( V_99 ) ;
V_100 = 0 ;
memcpy ( V_89 , & V_100 , 1 ) ;
V_89 ++ ;
memcpy ( V_89 , V_85 , 64 ) ;
V_89 += 64 ;
V_100 = 1 ;
memcpy ( V_89 , & V_100 , 1 ) ;
V_89 ++ ;
memcpy ( V_89 , V_85 + 64 , 64 ) ;
V_89 += 64 ;
memcpy ( V_89 , V_101 , sizeof( V_101 ) ) ;
V_89 += sizeof( V_101 ) ;
memcpy ( V_89 , V_85 + 128 ,
V_83 -> V_93 - 128 ) ;
V_89 += V_83 -> V_93 - 128 ;
F_9 ( L_16 ,
V_85 [ 0 ] , V_85 [ 1 ] , V_85 [ 2 ] ,
V_85 [ 3 ] , V_85 [ 4 ] , V_85 [ 5 ] ,
V_85 [ 6 ] , V_85 [ 7 ] , V_85 [ 8 ] ) ;
V_88 -> V_98 = V_89 - V_84 ;
} else {
if ( V_88 -> V_98 + V_83 -> V_93 > V_102 ) {
F_40 ( & V_21 -> V_2 -> V_11 ,
L_17
L_18 ,
V_30 , V_102 ) ;
} else {
V_84 += V_88 -> V_98 ;
memcpy ( V_84 , V_85 , V_83 -> V_93 ) ;
V_88 -> V_98 += V_83 -> V_93 ;
}
}
if ( V_83 -> V_93 < V_81 -> V_103 ) {
F_9 ( L_19 , V_86 ) ;
V_21 -> V_62 = V_21 -> V_90 ;
V_21 -> V_90 ++ ;
if ( V_21 -> V_90 == V_21 -> V_63 . V_104 )
V_21 -> V_90 = 0 ;
V_89 = V_84 = V_88 -> V_65 ;
V_89 += V_88 -> V_98 - 2 ;
while ( V_89 > V_84 ) {
if ( * V_89 == 0xFF && * ( V_89 + 1 ) == 0xD9
&& * ( V_89 + 2 ) == 0xFF )
break;
V_89 -- ;
}
if ( V_89 == V_84 )
F_15 ( L_20 ) ;
while ( V_89 > V_84 ) {
if ( * V_89 == 0xFF && * ( V_89 + 1 ) == 0xFF
&& * ( V_89 + 2 ) == 0xFF )
break;
V_89 -- ;
}
if ( V_89 != V_84 ) {
F_15 ( L_21 , ++ ( V_21 -> V_105 ) ) ;
} else if ( V_21 -> V_94 ) {
if ( V_21 -> V_106 )
V_21 -> V_106 -- ;
else {
F_9 ( L_22 ,
V_88 -> V_98 ,
V_84 [ 0 ] , V_84 [ 1 ] , V_84 [ 2 ] , V_84 [ 3 ] ,
V_84 [ 4 ] , V_84 [ 5 ] , V_84 [ 6 ] , V_84 [ 7 ] ) ;
F_30 ( V_21 , V_88 -> V_98 ) ;
}
}
V_21 -> V_69 ++ ;
V_88 -> V_95 = V_96 ;
V_88 -> V_98 = 0 ;
}
return 0 ;
}
static int F_41 ( struct V_48 * V_48 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_42 ( V_109 -> V_110 , V_111 , sizeof( V_109 -> V_110 ) ) ;
F_42 ( V_109 -> V_112 , V_21 -> V_2 -> V_113 , sizeof( V_109 -> V_112 ) ) ;
F_42 ( V_109 -> V_114 , F_43 ( & V_21 -> V_2 -> V_11 ) ,
sizeof( V_109 -> V_114 ) ) ;
V_109 -> V_115 = V_116 |
V_117 |
V_118 ;
V_109 -> V_119 = V_109 -> V_115 | V_120 ;
return 0 ;
}
static int F_44 ( struct V_48 * V_48 , void * V_107 ,
struct V_121 * V_79 )
{
if ( V_79 -> V_5 != 0 )
return - V_39 ;
strcpy ( V_79 -> V_38 , V_111 L_23 ) ;
V_79 -> type = V_122 ;
return 0 ;
}
static int F_45 ( struct V_48 * V_48 , void * V_107 ,
unsigned int * V_79 )
{
* V_79 = 0 ;
return 0 ;
}
static int F_46 ( struct V_48 * V_48 , void * V_107 ,
unsigned int V_79 )
{
if ( V_79 != 0 )
return - V_39 ;
return 0 ;
}
static int F_47 ( struct V_123 * V_124 )
{
struct V_20 * V_21 =
F_14 ( V_124 -> V_125 , struct V_20 , V_126 ) ;
int V_127 ;
switch ( V_124 -> V_128 ) {
case V_129 :
F_1 ( V_21 -> V_2 , 1 , 0x2001 , 0 , NULL , 0 ) ;
V_127 = ( 0x60 << 8 ) + 127 - V_124 -> V_130 ;
F_1 ( V_21 -> V_2 , 1 , V_127 , 0 , NULL , 0 ) ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_48 ( struct V_48 * V_48 ,
void * V_107 , struct V_131 * V_132 )
{
if ( V_132 -> V_5 > 0 )
return - V_39 ;
V_132 -> V_74 = V_133 ;
strcpy ( V_132 -> V_134 , V_135 [ 0 ] . V_38 ) ;
V_132 -> V_136 = V_135 [ 0 ] . V_66 ;
return 0 ;
}
static char * F_49 ( T_8 V_136 , char * V_29 )
{
V_29 [ 0 ] = V_136 & 0xff ;
V_29 [ 1 ] = ( V_136 >> 8 ) & 0xff ;
V_29 [ 2 ] = ( V_136 >> 16 ) & 0xff ;
V_29 [ 3 ] = ( V_136 >> 24 ) & 0xff ;
V_29 [ 4 ] = '\0' ;
return V_29 ;
}
static int F_50 ( struct V_48 * V_48 , void * V_107 ,
struct V_137 * V_132 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
char V_138 [ 5 ] ;
if ( V_21 == NULL )
return - V_139 ;
if ( V_132 -> V_25 . V_140 . V_136 != V_67 ) {
F_15 ( L_24 , V_30 ,
F_49 ( V_132 -> V_25 . V_140 . V_136 , V_138 ) ) ;
return - V_39 ;
}
if ( ! ( V_132 -> V_25 . V_140 . V_23 == 160 && V_132 -> V_25 . V_140 . V_24 == 120 ) &&
! ( V_132 -> V_25 . V_140 . V_23 == 640 && V_132 -> V_25 . V_140 . V_24 == 480 ) ) {
V_132 -> V_25 . V_140 . V_23 = 320 ;
V_132 -> V_25 . V_140 . V_24 = 240 ;
}
V_132 -> V_25 . V_140 . V_36 = V_141 ;
V_132 -> V_25 . V_140 . V_142 = V_132 -> V_25 . V_140 . V_23 * 2 ;
V_132 -> V_25 . V_140 . V_143 = V_132 -> V_25 . V_140 . V_24 * V_132 -> V_25 . V_140 . V_142 ;
V_132 -> V_25 . V_140 . V_144 = V_145 ;
F_15 ( L_25 , V_30 ,
F_49 ( V_132 -> V_25 . V_140 . V_136 , V_138 ) ,
V_132 -> V_25 . V_140 . V_36 ) ;
return 0 ;
}
static int F_51 ( struct V_48 * V_48 , void * V_107 ,
struct V_137 * V_132 )
{
struct V_20 * V_21 ;
if ( V_48 == NULL )
return - V_139 ;
V_21 = F_21 ( V_48 ) ;
V_132 -> V_25 . V_140 . V_136 = V_135 [ 0 ] . V_66 ;
V_132 -> V_25 . V_140 . V_36 = V_141 ;
V_132 -> V_25 . V_140 . V_23 = V_21 -> V_23 ;
V_132 -> V_25 . V_140 . V_24 = V_21 -> V_24 ;
V_132 -> V_25 . V_140 . V_142 = V_132 -> V_25 . V_140 . V_23 * 2 ;
V_132 -> V_25 . V_140 . V_143 = V_132 -> V_25 . V_140 . V_24 * V_132 -> V_25 . V_140 . V_142 ;
V_132 -> V_25 . V_140 . V_144 = V_145 ;
return 0 ;
}
static int F_52 ( struct V_48 * V_48 , void * V_107 ,
struct V_137 * V_132 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
struct V_17 * V_146 = & V_21 -> V_55 ;
char V_138 [ 5 ] ;
int V_147 = F_50 ( V_48 , V_21 , V_132 ) ;
int V_79 ;
if ( V_147 < 0 )
return V_147 ;
F_53 ( & V_146 -> V_148 ) ;
if ( F_54 ( & V_21 -> V_55 ) ) {
F_15 ( L_26 , V_30 ) ;
V_147 = - V_149 ;
goto V_150;
}
if ( V_21 -> V_151 ) {
F_15 ( L_27 , V_30 ) ;
V_147 = - V_149 ;
goto V_150;
}
V_21 -> V_23 = V_132 -> V_25 . V_140 . V_23 ;
V_21 -> V_24 = V_132 -> V_25 . V_140 . V_24 ;
F_15 ( L_28 , V_30 ,
V_21 -> V_23 , V_21 -> V_24 ) ;
V_132 -> V_25 . V_140 . V_142 = V_132 -> V_25 . V_140 . V_23 * 2 ;
V_132 -> V_25 . V_140 . V_143 = V_132 -> V_25 . V_140 . V_24 * V_132 -> V_25 . V_140 . V_142 ;
V_132 -> V_25 . V_140 . V_144 = V_145 ;
V_21 -> V_55 . V_36 = V_132 -> V_25 . V_140 . V_36 ;
if ( V_132 -> V_25 . V_140 . V_23 == 160 && V_132 -> V_25 . V_140 . V_24 == 120 )
V_152 = 1 ;
else if ( V_132 -> V_25 . V_140 . V_23 == 640 && V_132 -> V_25 . V_140 . V_24 == 480 )
V_152 = 2 ;
else
V_152 = 0 ;
V_153 [ 0 ] = V_152 ;
V_154 [ 2 ] . V_4 = 0xf000 + V_152 ;
V_155 [ 1 ] . V_4 = 0xf000 + V_152 ;
if ( V_21 -> V_91 == V_156 ) {
switch ( V_152 ) {
case 1 :
V_155 [ 1 ] . V_4 = 0xf000 + 4 ;
break;
case 2 :
V_155 [ 1 ] . V_4 = 0xf000 + 0 ;
break;
default:
V_155 [ 1 ] . V_4 = 0xf000 + 1 ;
break;
}
}
V_101 [ 437 ] = V_21 -> V_24 / 256 ;
V_101 [ 438 ] = V_21 -> V_24 % 256 ;
V_101 [ 439 ] = V_21 -> V_23 / 256 ;
V_101 [ 440 ] = V_21 -> V_23 % 256 ;
for ( V_79 = 0 ; V_157 [ V_21 -> V_91 ] [ V_79 ] . V_7 != - 1 ; V_79 ++ ) {
V_147 =
F_1 ( V_21 -> V_2 , 1 , V_157 [ V_21 -> V_91 ] [ V_79 ] . V_4 ,
0 , V_157 [ V_21 -> V_91 ] [ V_79 ] . V_158 ,
V_157 [ V_21 -> V_91 ] [ V_79 ] . V_7 ) ;
if ( V_147 < 0 ) {
F_3 ( & V_21 -> V_2 -> V_11 ,
L_29 , V_79 ) ;
goto V_150;
}
}
F_55 ( 100 ) ;
V_21 -> V_106 = 2 ;
V_147 = 0 ;
V_150:
F_25 ( & V_146 -> V_148 ) ;
F_15 ( L_25 , V_30 ,
F_49 ( V_132 -> V_25 . V_140 . V_136 , V_138 ) ,
V_132 -> V_25 . V_140 . V_36 ) ;
return V_147 ;
}
static int F_56 ( struct V_48 * V_48 , void * V_107 ,
struct V_159 * V_160 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
if ( V_21 -> V_151 && V_21 -> V_151 != V_107 )
return - V_149 ;
return F_57 ( & V_21 -> V_55 , V_160 ) ;
}
static int F_58 ( struct V_48 * V_48 ,
void * V_107 ,
struct V_161 * V_160 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
V_37 = F_59 ( & V_21 -> V_55 , V_160 ) ;
return V_37 ;
}
static int F_60 ( struct V_48 * V_48 ,
void * V_107 ,
struct V_161 * V_160 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_9 ( L_2 , V_30 ) ;
if ( V_21 -> V_151 && V_21 -> V_151 != V_107 )
return - V_149 ;
V_37 = F_61 ( & V_21 -> V_55 , V_160 ) ;
return V_37 ;
}
static int F_62 ( struct V_48 * V_48 ,
void * V_107 ,
struct V_161 * V_160 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_9 ( L_2 , V_30 ) ;
if ( V_21 -> V_151 && V_21 -> V_151 != V_107 )
return - V_149 ;
V_37 = F_63 ( & V_21 -> V_55 , V_160 , V_48 -> V_56 & V_57 ) ;
return V_37 ;
}
static void F_64 ( struct V_82 * V_83 )
{
struct V_80 * V_81 ;
struct V_20 * V_21 ;
int V_162 ;
V_81 = V_83 -> V_163 ;
F_9 ( L_30 , V_30 , V_83 , V_83 -> V_8 ) ;
if ( V_81 == NULL ) {
F_28 (KERN_ERR KBUILD_MODNAME L_31 ) ;
return;
}
V_21 = V_81 -> V_21 ;
if ( V_21 == NULL ) {
F_28 (KERN_ERR KBUILD_MODNAME L_31 ) ;
return;
}
if ( V_83 -> V_8 == - V_164 ) {
F_15 ( L_32 , V_30 ) ;
V_81 -> V_165 ++ ;
return;
}
if ( V_81 -> V_32 == 0 ) {
F_15 ( L_33 ) ;
return;
}
if ( V_83 -> V_93 > V_81 -> V_103 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_34 ) ;
return;
}
if ( V_83 -> V_8 == 0 )
F_38 ( V_21 , V_81 , V_83 ) ;
else {
V_81 -> V_165 ++ ;
F_15 ( L_35 , V_30 , V_83 -> V_8 ) ;
}
V_162 = F_65 ( V_21 -> V_2 , V_21 -> V_166 ) ;
F_66 ( V_81 -> V_167 , V_21 -> V_2 ,
V_162 ,
V_81 -> V_9 ,
V_81 -> V_103 ,
F_64 , V_81 ) ;
if ( V_81 -> V_32 != 0 ) {
V_83 -> V_8 = F_67 ( V_81 -> V_167 ,
V_168 ) ;
if ( V_83 -> V_8 )
F_3 ( & V_21 -> V_2 -> V_11 ,
L_36 ,
V_83 -> V_8 ) ;
} else
F_15 ( L_37 ) ;
}
static int F_68 ( struct V_20 * V_21 )
{
int V_162 ;
int V_169 ;
struct V_80 * V_81 = V_21 -> V_162 ;
V_162 = F_65 ( V_21 -> V_2 , V_21 -> V_166 ) ;
F_15 ( L_38 , V_30 , V_21 -> V_166 ) ;
V_81 -> V_32 = 1 ;
V_81 -> V_165 = 0 ;
V_81 -> V_167 = F_69 ( 0 , V_10 ) ;
if ( ! V_81 -> V_167 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_39 ) ;
return - V_12 ;
}
F_66 ( V_81 -> V_167 , V_21 -> V_2 ,
V_162 ,
V_81 -> V_9 ,
V_81 -> V_103 ,
F_64 , V_81 ) ;
F_15 ( L_40 , V_81 -> V_167 ) ;
V_169 = F_67 ( V_81 -> V_167 , V_10 ) ;
if ( V_169 ) {
F_28 (KERN_ERR KBUILD_MODNAME L_41 ) ;
return V_169 ;
}
return 0 ;
}
static void F_70 ( struct V_20 * V_21 )
{
struct V_80 * V_81 ;
if ( V_21 == NULL ) {
F_28 (KERN_ERR KBUILD_MODNAME L_42 ) ;
return;
}
F_15 ( L_43 ) ;
V_81 = V_21 -> V_162 ;
if ( V_81 ) {
if ( V_81 -> V_32 != 0 )
V_81 -> V_32 = 0 ;
if ( V_81 -> V_167 ) {
F_71 ( V_81 -> V_167 ) ;
F_72 ( V_81 -> V_167 ) ;
V_81 -> V_167 = NULL ;
}
}
return;
}
static int F_73 ( struct V_20 * V_21 )
{
int V_170 ;
F_15 ( L_44 ) ;
V_21 -> V_62 = - 1 ;
V_21 -> V_90 = 0 ;
for ( V_170 = 0 ; V_170 < V_171 ; V_170 ++ ) {
V_21 -> V_63 . V_64 [ V_170 ] . V_95 = V_96 ;
V_21 -> V_63 . V_64 [ V_170 ] . V_98 = 0 ;
}
V_21 -> V_94 = 1 ;
return 0 ;
}
static inline int F_74 ( struct V_20 * V_21 )
{
V_21 -> V_94 = 0 ;
return 0 ;
}
static int F_75 ( struct V_20 * V_21 )
{
int V_172 ;
int V_79 , V_170 ;
for ( V_79 = 0 ; V_157 [ V_21 -> V_91 ] [ V_79 ] . V_7 != - 1 ; V_79 ++ ) {
V_172 = F_1 ( V_21 -> V_2 , 1 , V_157 [ V_21 -> V_91 ] [ V_79 ] . V_4 ,
0 , V_157 [ V_21 -> V_91 ] [ V_79 ] . V_158 ,
V_157 [ V_21 -> V_91 ] [ V_79 ] . V_7 ) ;
if ( V_172 < 0 ) {
F_3 ( & V_21 -> V_2 -> V_11 ,
L_45 , V_79 ) ;
return V_172 ;
}
}
V_21 -> V_106 = 2 ;
V_21 -> V_62 = - 1 ;
V_21 -> V_90 = 0 ;
V_21 -> V_69 = 0 ;
for ( V_170 = 0 ; V_170 < V_171 ; V_170 ++ ) {
V_21 -> V_63 . V_64 [ V_170 ] . V_95 = V_96 ;
V_21 -> V_63 . V_64 [ V_170 ] . V_98 = 0 ;
}
F_76 ( & V_21 -> V_126 ) ;
return 0 ;
}
static int F_23 ( struct V_48 * V_48 , void * V_107 ,
enum V_173 type )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_172 ;
F_15 ( L_2 , V_30 ) ;
if ( type != V_54 )
return - V_39 ;
if ( V_21 -> V_151 && V_21 -> V_151 != V_107 )
return - V_149 ;
V_172 = F_75 ( V_21 ) ;
if ( V_172 )
return V_172 ;
V_172 = F_77 ( & V_21 -> V_55 ) ;
if ( V_172 == 0 ) {
F_73 ( V_21 ) ;
V_21 -> V_151 = V_48 -> V_53 ;
}
return V_172 ;
}
static int F_78 ( struct V_48 * V_48 , void * V_107 ,
enum V_173 type )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_15 ( L_2 , V_30 ) ;
if ( type != V_54 )
return - V_39 ;
if ( V_21 -> V_151 && V_21 -> V_151 != V_107 )
return - V_149 ;
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
goto V_150;
F_55 ( 100 ) ;
V_50 = 0 ;
V_150:
F_25 ( & V_21 -> V_51 ) ;
F_15 ( L_46 , V_30 , V_50 ) ;
return V_50 ;
}
static void F_82 ( struct V_174 * V_175 )
{
struct V_20 * V_21 =
F_14 ( V_175 , struct V_20 , V_175 ) ;
unsigned long V_79 ;
F_83 ( & V_21 -> V_175 ) ;
F_84 ( & V_21 -> V_55 ) ;
for ( V_79 = 0 ; V_79 < V_171 ; V_79 ++ ) {
if ( V_21 -> V_63 . V_64 [ V_79 ] . V_65 ) {
F_15 ( L_47 , V_21 -> V_63 . V_64 [ V_79 ] . V_65 ) ;
F_85 ( V_21 -> V_63 . V_64 [ V_79 ] . V_65 ) ;
}
V_21 -> V_63 . V_64 [ V_79 ] . V_65 = NULL ;
}
F_86 ( & V_21 -> V_126 ) ;
F_6 ( V_21 -> V_162 -> V_9 ) ;
F_6 ( V_21 ) ;
}
static int F_87 ( struct V_48 * V_48 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_79 ;
F_15 ( L_2 , V_30 ) ;
V_21 = F_21 ( V_48 ) ;
F_53 ( & V_21 -> V_51 ) ;
V_2 = V_21 -> V_2 ;
if ( V_48 -> V_53 == V_21 -> V_151 ) {
if ( V_21 -> V_94 )
F_74 ( V_21 ) ;
F_79 ( & V_21 -> V_55 ) ;
for ( V_79 = 0 ; V_79 < 2 ; V_79 ++ ) {
F_1 ( V_2 , 1 , V_157 [ V_21 -> V_91 ] [ V_79 ] . V_4 ,
0 , V_157 [ V_21 -> V_91 ] [ V_79 ] . V_158 ,
V_157 [ V_21 -> V_91 ] [ V_79 ] . V_7 ) ;
}
V_21 -> V_151 = NULL ;
}
F_55 ( 100 ) ;
F_25 ( & V_21 -> V_51 ) ;
return F_88 ( V_48 ) ;
}
static int F_89 ( struct V_48 * V_48 , struct V_176 * V_177 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_147 ;
if ( V_21 == NULL ) {
F_15 ( L_48 , V_30 ) ;
return - V_139 ;
}
F_15 ( L_49 , ( unsigned long ) V_177 ) ;
V_147 = F_90 ( & V_21 -> V_55 , V_177 ) ;
F_15 ( L_50 ,
( unsigned long ) V_177 -> V_178 ,
( unsigned long ) V_177 -> V_179 - ( unsigned long ) V_177 -> V_178 , V_147 ) ;
return V_147 ;
}
static unsigned int F_91 ( struct V_48 * V_48 ,
struct V_180 * V_181 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
struct V_17 * V_146 = & V_21 -> V_55 ;
unsigned V_172 = F_92 ( V_48 , V_181 ) ;
F_9 ( L_2 , V_30 ) ;
return V_172 | F_93 ( V_48 , V_146 , V_181 ) ;
}
static int F_94 ( struct V_20 * V_21 )
{
struct V_80 * V_162 = V_21 -> V_162 ;
unsigned long V_79 ;
F_15 ( L_51 , V_21 ) ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
V_162 -> V_21 = V_21 ;
V_162 -> V_103 = V_182 ;
V_162 -> V_9 = F_95 ( V_162 -> V_103 ,
V_10 ) ;
if ( V_162 -> V_9 == NULL ) {
F_15 ( L_52 ) ;
return - V_12 ;
}
V_21 -> V_94 = 0 ;
V_21 -> V_69 = 0 ;
for ( V_79 = 0 ; V_79 < V_171 ; V_79 ++ ) {
V_21 -> V_63 . V_64 [ V_79 ] . V_65 = F_96 ( V_102 ) ;
F_15 ( L_53 ,
& V_21 -> V_63 . V_64 [ V_79 ] , V_79 ,
V_21 -> V_63 . V_64 [ V_79 ] . V_65 ) ;
if ( V_21 -> V_63 . V_64 [ V_79 ] . V_65 == NULL ) {
F_28 (KERN_INFO KBUILD_MODNAME L_54
L_55 ) ;
break;
}
}
if ( V_79 == 0 ) {
F_28 (KERN_INFO KBUILD_MODNAME L_56 ) ;
F_6 ( V_21 -> V_162 -> V_9 ) ;
V_21 -> V_162 -> V_9 = NULL ;
return - V_12 ;
} else
V_21 -> V_63 . V_104 = V_79 ;
for ( V_79 = 0 ; V_79 < V_171 ; V_79 ++ ) {
V_21 -> V_63 . V_64 [ V_79 ] . V_95 = V_96 ;
V_21 -> V_63 . V_64 [ V_79 ] . V_98 = 0 ;
}
V_21 -> V_90 = 0 ;
V_21 -> V_62 = - 1 ;
F_68 ( V_21 ) ;
F_15 ( L_57 ) ;
return 0 ;
}
static int F_97 ( struct V_183 * V_184 ,
const struct V_185 * V_128 )
{
struct V_1 * V_2 = F_98 ( V_184 ) ;
struct V_20 * V_21 = NULL ;
struct V_186 * V_187 ;
struct V_188 * V_189 ;
struct V_190 * V_191 ;
int V_50 ;
int V_79 ;
F_15 ( L_58 ) ;
F_40 ( & V_184 -> V_11 , V_111 L_59 ) ;
F_40 ( & V_184 -> V_11 , L_60 ,
F_99 ( V_2 -> V_192 . V_193 ) ,
F_99 ( V_2 -> V_192 . V_194 ) ) ;
V_21 = F_95 ( sizeof( struct V_20 ) , V_10 ) ;
if ( V_21 == NULL ) {
F_3 ( & V_2 -> V_11 , L_61 ) ;
return - V_12 ;
}
V_21 -> V_175 . V_195 = F_82 ;
V_50 = F_100 ( & V_184 -> V_11 , & V_21 -> V_175 ) ;
if ( V_50 < 0 ) {
F_3 ( & V_2 -> V_11 , L_62 ) ;
F_6 ( V_21 ) ;
return V_50 ;
}
V_191 = & V_21 -> V_126 ;
F_101 ( V_191 , 1 ) ;
F_102 ( V_191 , & V_196 ,
V_129 , 0 , 127 , 1 , 64 ) ;
if ( V_191 -> error ) {
V_50 = V_191 -> error ;
F_3 ( & V_2 -> V_11 , L_63 ) ;
goto V_42;
}
V_21 -> V_91 = V_128 -> V_197 ;
F_103 ( & V_21 -> V_51 ) ;
V_21 -> V_198 = V_199 ;
V_21 -> V_198 . V_51 = & V_21 -> V_51 ;
V_21 -> V_198 . V_175 = & V_21 -> V_175 ;
V_21 -> V_198 . V_126 = & V_21 -> V_126 ;
F_104 ( & V_21 -> V_198 , V_21 ) ;
V_21 -> V_2 = V_2 ;
switch ( V_152 ) {
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
V_153 [ 0 ] = V_152 ;
V_154 [ 2 ] . V_4 = 0xf000 + V_152 ;
V_155 [ 1 ] . V_4 = 0xf000 + V_152 ;
if ( V_21 -> V_91 == V_156 ) {
switch ( V_152 ) {
case 1 :
V_155 [ 1 ] . V_4 = 0xf000 + 4 ;
break;
case 2 :
V_155 [ 1 ] . V_4 = 0xf000 + 0 ;
break;
default:
V_155 [ 1 ] . V_4 = 0xf000 + 1 ;
break;
}
}
V_101 [ 437 ] = V_21 -> V_24 / 256 ;
V_101 [ 438 ] = V_21 -> V_24 % 256 ;
V_101 [ 439 ] = V_21 -> V_23 / 256 ;
V_101 [ 440 ] = V_21 -> V_23 % 256 ;
V_21 -> V_105 = 0 ;
F_15 ( L_67 , V_21 , V_21 -> V_2 , V_184 ) ;
V_187 = V_184 -> V_200 ;
F_15 ( L_68 , V_187 -> V_201 . V_202 ) ;
for ( V_79 = 0 ; V_79 < V_187 -> V_201 . V_202 ; ++ V_79 ) {
V_189 = & V_187 -> V_189 [ V_79 ] . V_201 ;
if ( ! V_21 -> V_166 && F_105 ( V_189 ) ) {
V_21 -> V_166 = V_189 -> V_203 ;
}
}
if ( ! V_21 -> V_166 ) {
V_50 = - V_12 ;
F_3 ( & V_184 -> V_11 , L_69 ) ;
goto V_42;
}
F_106 ( & V_21 -> V_46 . V_47 ) ;
V_21 -> V_46 . V_21 = V_21 ;
F_107 ( V_184 , V_21 ) ;
V_50 = F_94 ( V_21 ) ;
if ( ! V_50 )
V_50 = F_76 ( V_191 ) ;
if ( V_50 )
goto V_42;
F_108 ( & V_21 -> V_75 ) ;
V_21 -> V_25 = V_135 ;
F_109 ( & V_21 -> V_55 , & V_204 ,
NULL , & V_21 -> V_75 ,
V_54 ,
V_141 ,
sizeof( struct V_28 ) , V_21 , & V_21 -> V_51 ) ;
V_50 = F_110 ( & V_21 -> V_198 , V_205 , - 1 ) ;
if ( V_50 ) {
F_3 ( & V_2 -> V_11 , L_70 ) ;
goto V_42;
}
F_40 ( & V_2 -> V_11 , V_111 L_71 ,
F_111 ( & V_21 -> V_198 ) ) ;
return 0 ;
V_42:
F_86 ( V_191 ) ;
F_83 ( & V_21 -> V_175 ) ;
F_6 ( V_21 ) ;
return V_50 ;
}
static void F_112 ( struct V_183 * V_184 )
{
struct V_20 * V_21 = F_113 ( V_184 ) ;
F_53 ( & V_21 -> V_51 ) ;
F_107 ( V_184 , NULL ) ;
F_40 ( & V_184 -> V_11 , V_111 L_72 ) ;
F_114 ( & V_21 -> V_198 ) ;
F_115 ( & V_21 -> V_175 ) ;
if ( V_21 -> V_94 )
F_74 ( V_21 ) ;
F_70 ( V_21 ) ;
F_25 ( & V_21 -> V_51 ) ;
F_116 ( & V_21 -> V_175 ) ;
}
static int F_117 ( struct V_183 * V_184 , T_9 V_206 )
{
struct V_20 * V_21 = F_113 ( V_184 ) ;
V_21 -> V_207 = V_21 -> V_94 ;
if ( ! V_21 -> V_207 )
return 0 ;
F_74 ( V_21 ) ;
F_70 ( V_21 ) ;
return 0 ;
}
static int F_118 ( struct V_183 * V_184 )
{
struct V_20 * V_21 = F_113 ( V_184 ) ;
int V_172 ;
if ( ! V_21 -> V_207 )
return 0 ;
F_68 ( V_21 ) ;
V_172 = F_75 ( V_21 ) ;
if ( ! V_172 )
F_73 ( V_21 ) ;
return V_172 ;
}
