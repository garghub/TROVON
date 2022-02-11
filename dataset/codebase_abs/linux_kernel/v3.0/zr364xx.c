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
if ( V_8 < 0 )
F_3 ( & V_2 -> V_11 ,
L_2 , V_8 ) ;
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
F_9 ( L_3 , V_30 ) ;
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
F_15 ( L_4 , V_30 , V_36 , V_21 -> V_25 != NULL ?
V_21 -> V_25 -> V_38 : L_5 ) ;
if ( V_21 -> V_25 == NULL )
return - V_39 ;
V_29 -> V_31 . V_7 = V_21 -> V_23 * V_21 -> V_24 * ( V_21 -> V_25 -> V_26 >> 3 ) ;
if ( V_29 -> V_31 . V_40 != 0 && V_29 -> V_31 . V_41 < V_29 -> V_31 . V_7 ) {
F_15 ( L_6 ) ;
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
F_9 ( L_3 , V_30 ) ;
V_29 -> V_31 . V_32 = V_44 ;
F_18 ( & V_29 -> V_31 . V_45 , & V_21 -> V_46 . V_47 ) ;
}
static void F_19 ( struct V_17 * V_18 ,
struct V_34 * V_31 )
{
struct V_28 * V_29 = F_14 ( V_31 , struct V_28 ,
V_31 ) ;
F_9 ( L_3 , V_30 ) ;
F_8 ( V_18 , V_29 ) ;
}
static T_3 F_20 ( struct V_48 * V_48 , char T_4 * V_29 , T_5 V_19 ,
T_6 * V_49 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_9 ( L_3 , V_30 ) ;
if ( ! V_29 )
return - V_39 ;
if ( ! V_19 )
return - V_39 ;
if ( V_21 -> type == V_50 &&
F_22 ( V_48 , V_21 , V_21 -> type ) == 0 ) {
F_15 ( L_7 , V_30 , ( int ) V_19 ,
( int ) * V_49 ) ;
return F_23 ( & V_21 -> V_51 , V_29 , V_19 , V_49 ,
V_48 -> V_52 & V_53 ) ;
}
return 0 ;
}
static void F_24 ( struct V_20 * V_21 ,
struct V_28 * V_29 ,
int V_54 )
{
int V_55 = 0 ;
struct V_56 V_57 ;
const char * V_58 ;
char * V_59 = F_25 ( & V_29 -> V_31 ) ;
unsigned long V_60 ;
struct V_61 * V_62 ;
if ( ! V_59 )
return;
V_60 = V_21 -> V_60 ;
if ( V_60 != - 1 ) {
V_62 = & V_21 -> V_63 . V_64 [ V_60 ] ;
V_58 = ( const char * ) V_21 -> V_63 . V_64 [ V_60 ] . V_65 ;
switch ( V_29 -> V_25 -> V_66 ) {
case V_67 :
V_29 -> V_31 . V_7 = V_54 ;
memcpy ( V_59 , V_58 , V_29 -> V_31 . V_7 ) ;
break;
default:
F_26 (KERN_DEBUG KBUILD_MODNAME L_8 ) ;
}
V_21 -> V_60 = - 1 ;
} else {
F_26 (KERN_ERR KBUILD_MODNAME L_9 ) ;
return;
}
F_15 ( L_10 , V_30 ,
( unsigned long ) V_59 , V_55 ) ;
V_29 -> V_31 . V_68 = V_21 -> V_69 * 2 ;
F_27 ( & V_57 ) ;
V_29 -> V_31 . V_57 = V_57 ;
V_29 -> V_31 . V_32 = V_70 ;
}
static int F_28 ( struct V_20 * V_21 , int V_54 )
{
struct V_71 * V_72 = & V_21 -> V_46 ;
struct V_28 * V_29 ;
unsigned long V_73 = 0 ;
int V_37 = 0 ;
F_15 ( L_11 , & V_72 ) ;
F_29 ( & V_21 -> V_74 , V_73 ) ;
if ( F_30 ( & V_72 -> V_47 ) ) {
F_15 ( L_12 ) ;
V_37 = - 1 ;
goto V_75;
}
V_29 = F_31 ( V_72 -> V_47 . V_76 ,
struct V_28 , V_31 . V_45 ) ;
if ( ! F_32 ( & V_29 -> V_31 . V_77 ) ) {
V_37 = - 1 ;
goto V_75;
}
F_33 ( & V_29 -> V_31 . V_45 ) ;
F_27 ( & V_29 -> V_31 . V_57 ) ;
F_15 ( L_13 , V_29 , V_29 -> V_31 . V_78 ) ;
F_24 ( V_21 , V_29 , V_54 ) ;
F_34 ( & V_29 -> V_31 . V_77 ) ;
F_15 ( L_14 , V_29 , V_29 -> V_31 . V_78 ) ;
V_75:
F_35 ( & V_21 -> V_74 , V_73 ) ;
return V_37 ;
}
static int F_36 ( struct V_20 * V_21 ,
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
unsigned char * V_83 ;
unsigned char * V_84 ;
T_7 V_85 = - 1 ;
struct V_61 * V_62 ;
int V_78 = 0 ;
unsigned char * V_86 = NULL ;
F_9 ( L_15 ) ;
V_85 = V_21 -> V_87 ;
V_62 = & V_21 -> V_63 . V_64 [ V_85 ] ;
if ( V_21 -> V_88 == V_89 ) {
T_2 * V_29 = ( T_2 * ) V_80 -> V_9 ;
for ( V_78 = 0 ; V_78 < V_82 -> V_90 / 2 ; V_78 ++ )
F_37 ( V_29 + V_78 ) ;
}
if ( ! V_21 -> V_91 ) {
V_62 -> V_92 = V_93 ;
return - V_39 ;
}
V_84 = ( T_1 * ) V_80 -> V_9 ;
V_86 = V_83 = V_62 -> V_65 ;
if ( V_62 -> V_92 == V_93 ) {
V_62 -> V_92 = V_94 ;
V_62 -> V_95 = 0 ;
F_9 ( L_16 ) ;
memcpy ( V_86 , V_96 , sizeof( V_96 ) ) ;
V_86 += sizeof( V_96 ) ;
V_97 = 0 ;
memcpy ( V_86 , & V_97 , 1 ) ;
V_86 ++ ;
memcpy ( V_86 , V_84 , 64 ) ;
V_86 += 64 ;
V_97 = 1 ;
memcpy ( V_86 , & V_97 , 1 ) ;
V_86 ++ ;
memcpy ( V_86 , V_84 + 64 , 64 ) ;
V_86 += 64 ;
memcpy ( V_86 , V_98 , sizeof( V_98 ) ) ;
V_86 += sizeof( V_98 ) ;
memcpy ( V_86 , V_84 + 128 ,
V_82 -> V_90 - 128 ) ;
V_86 += V_82 -> V_90 - 128 ;
F_9 ( L_17 ,
V_84 [ 0 ] , V_84 [ 1 ] , V_84 [ 2 ] ,
V_84 [ 3 ] , V_84 [ 4 ] , V_84 [ 5 ] ,
V_84 [ 6 ] , V_84 [ 7 ] , V_84 [ 8 ] ) ;
V_62 -> V_95 = V_86 - V_83 ;
} else {
if ( V_62 -> V_95 + V_82 -> V_90 > V_99 ) {
F_38 ( & V_21 -> V_2 -> V_11 ,
L_18
L_19 ,
V_30 , V_99 ) ;
} else {
V_83 += V_62 -> V_95 ;
memcpy ( V_83 , V_84 , V_82 -> V_90 ) ;
V_62 -> V_95 += V_82 -> V_90 ;
}
}
if ( V_82 -> V_90 < V_80 -> V_100 ) {
F_9 ( L_20 , V_85 ) ;
V_21 -> V_60 = V_21 -> V_87 ;
V_21 -> V_87 ++ ;
if ( V_21 -> V_87 == V_21 -> V_63 . V_101 )
V_21 -> V_87 = 0 ;
V_86 = V_83 = V_62 -> V_65 ;
V_86 += V_62 -> V_95 - 2 ;
while ( V_86 > V_83 ) {
if ( * V_86 == 0xFF && * ( V_86 + 1 ) == 0xD9
&& * ( V_86 + 2 ) == 0xFF )
break;
V_86 -- ;
}
if ( V_86 == V_83 )
F_15 ( L_21 ) ;
while ( V_86 > V_83 ) {
if ( * V_86 == 0xFF && * ( V_86 + 1 ) == 0xFF
&& * ( V_86 + 2 ) == 0xFF )
break;
V_86 -- ;
}
if ( V_86 != V_83 ) {
F_15 ( L_22 , ++ ( V_21 -> V_102 ) ) ;
} else if ( V_21 -> V_91 ) {
if ( V_21 -> V_103 )
V_21 -> V_103 -- ;
else {
F_9 ( L_23 ,
V_62 -> V_95 ,
V_83 [ 0 ] , V_83 [ 1 ] , V_83 [ 2 ] , V_83 [ 3 ] ,
V_83 [ 4 ] , V_83 [ 5 ] , V_83 [ 6 ] , V_83 [ 7 ] ) ;
F_28 ( V_21 , V_62 -> V_95 ) ;
}
}
V_21 -> V_69 ++ ;
V_62 -> V_92 = V_93 ;
V_62 -> V_95 = 0 ;
}
return 0 ;
}
static int F_39 ( struct V_20 * V_21 )
{
F_40 ( & V_21 -> V_104 ) ;
if ( V_21 -> V_105 ) {
F_41 ( & V_21 -> V_104 ) ;
return 0 ;
}
V_21 -> V_105 = 1 ;
F_9 ( L_24 ) ;
F_41 ( & V_21 -> V_104 ) ;
return 1 ;
}
static inline int F_42 ( struct V_20 * V_21 )
{
return V_21 -> V_105 ;
}
static void F_43 ( struct V_20 * V_21 )
{
F_40 ( & V_21 -> V_104 ) ;
V_21 -> V_105 = 0 ;
F_41 ( & V_21 -> V_104 ) ;
F_9 ( L_25 ) ;
}
static int F_44 ( struct V_48 * V_48 , void * V_106 ,
struct V_107 * V_108 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_45 ( V_108 -> V_109 , V_110 , sizeof( V_108 -> V_109 ) ) ;
F_45 ( V_108 -> V_111 , V_21 -> V_2 -> V_112 , sizeof( V_108 -> V_111 ) ) ;
F_45 ( V_108 -> V_113 , F_46 ( & V_21 -> V_2 -> V_11 ) ,
sizeof( V_108 -> V_113 ) ) ;
V_108 -> V_114 = V_115 ;
V_108 -> V_116 = V_117 |
V_118 |
V_119 ;
return 0 ;
}
static int F_47 ( struct V_48 * V_48 , void * V_106 ,
struct V_120 * V_78 )
{
if ( V_78 -> V_5 != 0 )
return - V_39 ;
strcpy ( V_78 -> V_38 , V_110 L_26 ) ;
V_78 -> type = V_121 ;
return 0 ;
}
static int F_48 ( struct V_48 * V_48 , void * V_106 ,
unsigned int * V_78 )
{
* V_78 = 0 ;
return 0 ;
}
static int F_49 ( struct V_48 * V_48 , void * V_106 ,
unsigned int V_78 )
{
if ( V_78 != 0 )
return - V_39 ;
return 0 ;
}
static int F_50 ( struct V_48 * V_48 , void * V_106 ,
struct V_122 * V_123 )
{
struct V_20 * V_21 ;
if ( V_48 == NULL )
return - V_124 ;
V_21 = F_21 ( V_48 ) ;
switch ( V_123 -> V_125 ) {
case V_126 :
V_123 -> type = V_127 ;
strcpy ( V_123 -> V_38 , L_27 ) ;
V_123 -> V_128 = 0 ;
V_123 -> V_129 = 127 ;
V_123 -> V_130 = 1 ;
V_123 -> V_131 = V_21 -> V_132 . V_133 ;
V_123 -> V_73 = 0 ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_51 ( struct V_48 * V_48 , void * V_106 ,
struct V_134 * V_123 )
{
struct V_20 * V_21 ;
int V_135 ;
if ( V_48 == NULL )
return - V_124 ;
V_21 = F_21 ( V_48 ) ;
switch ( V_123 -> V_125 ) {
case V_126 :
V_21 -> V_132 . V_133 = V_123 -> V_4 ;
F_40 ( & V_21 -> V_104 ) ;
F_1 ( V_21 -> V_2 , 1 , 0x2001 , 0 , NULL , 0 ) ;
V_135 = ( 0x60 << 8 ) + 127 - V_21 -> V_132 . V_133 ;
F_1 ( V_21 -> V_2 , 1 , V_135 , 0 , NULL , 0 ) ;
F_41 ( & V_21 -> V_104 ) ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_52 ( struct V_48 * V_48 , void * V_106 ,
struct V_134 * V_123 )
{
struct V_20 * V_21 ;
if ( V_48 == NULL )
return - V_124 ;
V_21 = F_21 ( V_48 ) ;
switch ( V_123 -> V_125 ) {
case V_126 :
V_123 -> V_4 = V_21 -> V_132 . V_133 ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_53 ( struct V_48 * V_48 ,
void * V_106 , struct V_136 * V_137 )
{
if ( V_137 -> V_5 > 0 )
return - V_39 ;
V_137 -> V_73 = V_138 ;
strcpy ( V_137 -> V_139 , V_140 [ 0 ] . V_38 ) ;
V_137 -> V_141 = V_140 [ 0 ] . V_66 ;
return 0 ;
}
static char * F_54 ( T_8 V_141 , char * V_29 )
{
V_29 [ 0 ] = V_141 & 0xff ;
V_29 [ 1 ] = ( V_141 >> 8 ) & 0xff ;
V_29 [ 2 ] = ( V_141 >> 16 ) & 0xff ;
V_29 [ 3 ] = ( V_141 >> 24 ) & 0xff ;
V_29 [ 4 ] = '\0' ;
return V_29 ;
}
static int F_55 ( struct V_48 * V_48 , void * V_106 ,
struct V_142 * V_137 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
char V_143 [ 5 ] ;
if ( V_21 == NULL )
return - V_124 ;
if ( V_137 -> V_25 . V_144 . V_141 != V_67 ) {
F_15 ( L_28 , V_30 ,
F_54 ( V_137 -> V_25 . V_144 . V_141 , V_143 ) ) ;
return - V_39 ;
}
if ( ! ( V_137 -> V_25 . V_144 . V_23 == 160 && V_137 -> V_25 . V_144 . V_24 == 120 ) &&
! ( V_137 -> V_25 . V_144 . V_23 == 640 && V_137 -> V_25 . V_144 . V_24 == 480 ) ) {
V_137 -> V_25 . V_144 . V_23 = 320 ;
V_137 -> V_25 . V_144 . V_24 = 240 ;
}
V_137 -> V_25 . V_144 . V_36 = V_145 ;
V_137 -> V_25 . V_144 . V_146 = V_137 -> V_25 . V_144 . V_23 * 2 ;
V_137 -> V_25 . V_144 . V_147 = V_137 -> V_25 . V_144 . V_24 * V_137 -> V_25 . V_144 . V_146 ;
V_137 -> V_25 . V_144 . V_148 = 0 ;
V_137 -> V_25 . V_144 . V_106 = 0 ;
F_15 ( L_29 , V_30 ,
F_54 ( V_137 -> V_25 . V_144 . V_141 , V_143 ) ,
V_137 -> V_25 . V_144 . V_36 ) ;
return 0 ;
}
static int F_56 ( struct V_48 * V_48 , void * V_106 ,
struct V_142 * V_137 )
{
struct V_20 * V_21 ;
if ( V_48 == NULL )
return - V_124 ;
V_21 = F_21 ( V_48 ) ;
V_137 -> V_25 . V_144 . V_141 = V_140 [ 0 ] . V_66 ;
V_137 -> V_25 . V_144 . V_36 = V_145 ;
V_137 -> V_25 . V_144 . V_23 = V_21 -> V_23 ;
V_137 -> V_25 . V_144 . V_24 = V_21 -> V_24 ;
V_137 -> V_25 . V_144 . V_146 = V_137 -> V_25 . V_144 . V_23 * 2 ;
V_137 -> V_25 . V_144 . V_147 = V_137 -> V_25 . V_144 . V_24 * V_137 -> V_25 . V_144 . V_146 ;
V_137 -> V_25 . V_144 . V_148 = 0 ;
V_137 -> V_25 . V_144 . V_106 = 0 ;
return 0 ;
}
static int F_57 ( struct V_48 * V_48 , void * V_106 ,
struct V_142 * V_137 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
struct V_17 * V_149 = & V_21 -> V_51 ;
char V_143 [ 5 ] ;
int V_150 = F_55 ( V_48 , V_21 , V_137 ) ;
int V_78 ;
if ( V_150 < 0 )
return V_150 ;
F_40 ( & V_149 -> V_151 ) ;
if ( F_58 ( & V_21 -> V_51 ) ) {
F_15 ( L_30 , V_30 ) ;
V_150 = - V_152 ;
goto V_153;
}
if ( F_42 ( V_21 ) ) {
F_15 ( L_31 , V_30 ) ;
V_150 = - V_152 ;
goto V_153;
}
V_21 -> V_23 = V_137 -> V_25 . V_144 . V_23 ;
V_21 -> V_24 = V_137 -> V_25 . V_144 . V_24 ;
F_38 ( & V_21 -> V_2 -> V_11 , L_32 , V_30 ,
V_21 -> V_23 , V_21 -> V_24 ) ;
V_137 -> V_25 . V_144 . V_146 = V_137 -> V_25 . V_144 . V_23 * 2 ;
V_137 -> V_25 . V_144 . V_147 = V_137 -> V_25 . V_144 . V_24 * V_137 -> V_25 . V_144 . V_146 ;
V_137 -> V_25 . V_144 . V_148 = 0 ;
V_137 -> V_25 . V_144 . V_106 = 0 ;
V_21 -> V_51 . V_36 = V_137 -> V_25 . V_144 . V_36 ;
V_21 -> V_132 . V_154 = V_67 ;
if ( V_137 -> V_25 . V_144 . V_23 == 160 && V_137 -> V_25 . V_144 . V_24 == 120 )
V_132 = 1 ;
else if ( V_137 -> V_25 . V_144 . V_23 == 640 && V_137 -> V_25 . V_144 . V_24 == 480 )
V_132 = 2 ;
else
V_132 = 0 ;
V_155 [ 0 ] = V_132 ;
V_156 [ 2 ] . V_4 = 0xf000 + V_132 ;
V_157 [ 1 ] . V_4 = 0xf000 + V_132 ;
if ( V_21 -> V_88 == V_158 ) {
switch ( V_132 ) {
case 1 :
V_157 [ 1 ] . V_4 = 0xf000 + 4 ;
break;
case 2 :
V_157 [ 1 ] . V_4 = 0xf000 + 0 ;
break;
default:
V_157 [ 1 ] . V_4 = 0xf000 + 1 ;
break;
}
}
V_98 [ 437 ] = V_21 -> V_24 / 256 ;
V_98 [ 438 ] = V_21 -> V_24 % 256 ;
V_98 [ 439 ] = V_21 -> V_23 / 256 ;
V_98 [ 440 ] = V_21 -> V_23 % 256 ;
for ( V_78 = 0 ; V_159 [ V_21 -> V_88 ] [ V_78 ] . V_7 != - 1 ; V_78 ++ ) {
V_150 =
F_1 ( V_21 -> V_2 , 1 , V_159 [ V_21 -> V_88 ] [ V_78 ] . V_4 ,
0 , V_159 [ V_21 -> V_88 ] [ V_78 ] . V_160 ,
V_159 [ V_21 -> V_88 ] [ V_78 ] . V_7 ) ;
if ( V_150 < 0 ) {
F_3 ( & V_21 -> V_2 -> V_11 ,
L_33 , V_78 ) ;
goto V_153;
}
}
F_59 ( 100 ) ;
V_21 -> V_103 = 2 ;
V_150 = 0 ;
V_153:
F_41 ( & V_149 -> V_151 ) ;
F_15 ( L_29 , V_30 ,
F_54 ( V_137 -> V_25 . V_144 . V_141 , V_143 ) ,
V_137 -> V_25 . V_144 . V_36 ) ;
return V_150 ;
}
static int F_60 ( struct V_48 * V_48 , void * V_106 ,
struct V_161 * V_162 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
V_37 = F_61 ( & V_21 -> V_51 , V_162 ) ;
return V_37 ;
}
static int F_62 ( struct V_48 * V_48 ,
void * V_106 ,
struct V_163 * V_162 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
V_37 = F_63 ( & V_21 -> V_51 , V_162 ) ;
return V_37 ;
}
static int F_64 ( struct V_48 * V_48 ,
void * V_106 ,
struct V_163 * V_162 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_9 ( L_3 , V_30 ) ;
V_37 = F_65 ( & V_21 -> V_51 , V_162 ) ;
return V_37 ;
}
static int F_66 ( struct V_48 * V_48 ,
void * V_106 ,
struct V_163 * V_162 )
{
int V_37 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_9 ( L_3 , V_30 ) ;
V_37 = F_67 ( & V_21 -> V_51 , V_162 , V_48 -> V_52 & V_53 ) ;
return V_37 ;
}
static void F_68 ( struct V_81 * V_82 )
{
struct V_79 * V_80 ;
struct V_20 * V_21 ;
int V_164 ;
V_80 = V_82 -> V_165 ;
F_9 ( L_34 , V_30 , V_82 , V_82 -> V_8 ) ;
if ( V_80 == NULL ) {
F_26 (KERN_ERR KBUILD_MODNAME L_35 ) ;
return;
}
V_21 = V_80 -> V_21 ;
if ( V_21 == NULL ) {
F_26 (KERN_ERR KBUILD_MODNAME L_35 ) ;
return;
}
if ( V_82 -> V_8 == - V_166 ) {
F_15 ( L_36 , V_30 ) ;
V_80 -> V_167 ++ ;
return;
}
if ( V_80 -> V_32 == 0 ) {
F_15 ( L_37 ) ;
return;
}
if ( V_82 -> V_90 < 0 ||
V_82 -> V_90 > V_80 -> V_100 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_38 ) ;
return;
}
if ( V_82 -> V_8 == 0 )
F_36 ( V_21 , V_80 , V_82 ) ;
else {
V_80 -> V_167 ++ ;
F_15 ( L_39 , V_30 , V_82 -> V_8 ) ;
}
V_164 = F_69 ( V_21 -> V_2 , V_21 -> V_168 ) ;
F_70 ( V_80 -> V_169 , V_21 -> V_2 ,
V_164 ,
V_80 -> V_9 ,
V_80 -> V_100 ,
F_68 , V_80 ) ;
if ( V_80 -> V_32 != 0 ) {
V_82 -> V_8 = F_71 ( V_80 -> V_169 ,
V_170 ) ;
if ( V_82 -> V_8 )
F_3 ( & V_21 -> V_2 -> V_11 ,
L_40 ,
V_82 -> V_8 ) ;
} else
F_15 ( L_41 ) ;
}
static int F_72 ( struct V_20 * V_21 )
{
int V_164 ;
int V_171 ;
struct V_79 * V_80 = V_21 -> V_164 ;
V_164 = F_69 ( V_21 -> V_2 , V_21 -> V_168 ) ;
F_15 ( L_42 , V_30 , V_21 -> V_168 ) ;
V_80 -> V_32 = 1 ;
V_80 -> V_167 = 0 ;
V_80 -> V_169 = F_73 ( 0 , V_10 ) ;
if ( ! V_80 -> V_169 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_43 ) ;
return - V_12 ;
}
F_70 ( V_80 -> V_169 , V_21 -> V_2 ,
V_164 ,
V_80 -> V_9 ,
V_80 -> V_100 ,
F_68 , V_80 ) ;
F_15 ( L_44 , V_80 -> V_169 ) ;
V_171 = F_71 ( V_80 -> V_169 , V_10 ) ;
if ( V_171 ) {
F_26 (KERN_ERR KBUILD_MODNAME L_45 ) ;
return V_171 ;
}
return 0 ;
}
static void F_74 ( struct V_20 * V_21 )
{
struct V_79 * V_80 ;
if ( V_21 == NULL ) {
F_26 (KERN_ERR KBUILD_MODNAME L_46 ) ;
return;
}
F_15 ( L_47 ) ;
V_80 = V_21 -> V_164 ;
if ( V_80 ) {
if ( V_80 -> V_32 != 0 )
V_80 -> V_32 = 0 ;
if ( V_80 -> V_169 ) {
F_75 ( V_80 -> V_169 ) ;
F_76 ( V_80 -> V_169 ) ;
V_80 -> V_169 = NULL ;
}
}
return;
}
static int F_77 ( struct V_20 * V_21 )
{
int V_172 ;
F_15 ( L_48 ) ;
V_21 -> V_60 = - 1 ;
V_21 -> V_87 = 0 ;
for ( V_172 = 0 ; V_172 < V_173 ; V_172 ++ ) {
V_21 -> V_63 . V_64 [ V_172 ] . V_92 = V_93 ;
V_21 -> V_63 . V_64 [ V_172 ] . V_95 = 0 ;
}
V_21 -> V_91 = 1 ;
return 0 ;
}
static inline int F_78 ( struct V_20 * V_21 )
{
V_21 -> V_91 = 0 ;
return 0 ;
}
static int F_22 ( struct V_48 * V_48 , void * V_106 ,
enum V_174 type )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_172 ;
int V_175 ;
F_15 ( L_3 , V_30 ) ;
if ( V_21 -> type != V_50 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_49 ) ;
return - V_39 ;
}
if ( V_21 -> type != type ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_50 ) ;
return - V_39 ;
}
if ( ! F_39 ( V_21 ) ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_51 ) ;
return - V_152 ;
}
V_21 -> V_60 = - 1 ;
V_21 -> V_87 = 0 ;
V_21 -> V_69 = 0 ;
for ( V_172 = 0 ; V_172 < V_173 ; V_172 ++ ) {
V_21 -> V_63 . V_64 [ V_172 ] . V_92 = V_93 ;
V_21 -> V_63 . V_64 [ V_172 ] . V_95 = 0 ;
}
V_175 = F_79 ( & V_21 -> V_51 ) ;
if ( V_175 == 0 ) {
F_77 ( V_21 ) ;
} else {
F_43 ( V_21 ) ;
}
return V_175 ;
}
static int F_80 ( struct V_48 * V_48 , void * V_106 ,
enum V_174 type )
{
int V_175 ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
F_15 ( L_3 , V_30 ) ;
if ( V_21 -> type != V_50 ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_49 ) ;
return - V_39 ;
}
if ( V_21 -> type != type ) {
F_3 ( & V_21 -> V_2 -> V_11 , L_50 ) ;
return - V_39 ;
}
F_78 ( V_21 ) ;
V_175 = F_81 ( & V_21 -> V_51 ) ;
if ( V_175 < 0 )
return V_175 ;
F_43 ( V_21 ) ;
return 0 ;
}
static int F_82 ( struct V_48 * V_48 )
{
struct V_176 * V_177 = F_83 ( V_48 ) ;
struct V_20 * V_21 = F_21 ( V_48 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_78 , V_178 ;
F_15 ( L_3 , V_30 ) ;
F_40 ( & V_21 -> V_179 ) ;
if ( V_21 -> V_180 ) {
V_178 = - V_152 ;
goto V_153;
}
for ( V_78 = 0 ; V_159 [ V_21 -> V_88 ] [ V_78 ] . V_7 != - 1 ; V_78 ++ ) {
V_178 =
F_1 ( V_2 , 1 , V_159 [ V_21 -> V_88 ] [ V_78 ] . V_4 ,
0 , V_159 [ V_21 -> V_88 ] [ V_78 ] . V_160 ,
V_159 [ V_21 -> V_88 ] [ V_78 ] . V_7 ) ;
if ( V_178 < 0 ) {
F_3 ( & V_21 -> V_2 -> V_11 ,
L_52 , V_78 ) ;
goto V_153;
}
}
V_21 -> V_103 = 2 ;
V_21 -> V_180 ++ ;
V_48 -> V_181 = V_177 ;
V_21 -> type = V_50 ;
V_21 -> V_25 = V_140 ;
F_84 ( & V_21 -> V_51 , & V_182 ,
NULL , & V_21 -> V_74 ,
V_21 -> type ,
V_145 ,
sizeof( struct V_28 ) , V_21 , NULL ) ;
F_59 ( 100 ) ;
V_178 = 0 ;
V_153:
F_41 ( & V_21 -> V_179 ) ;
F_15 ( L_53 , V_30 , V_178 ) ;
return V_178 ;
}
static void F_85 ( struct V_20 * V_21 )
{
unsigned long V_78 ;
if ( ! V_21 ) {
F_26 (KERN_ERR KBUILD_MODNAME L_54 , __func__) ;
return;
}
F_40 ( & V_21 -> V_179 ) ;
if ( V_21 -> V_177 )
F_86 ( V_21 -> V_177 ) ;
V_21 -> V_177 = NULL ;
if ( V_21 -> V_91 )
F_78 ( V_21 ) ;
F_74 ( V_21 ) ;
for ( V_78 = 0 ; V_78 < V_173 ; V_78 ++ ) {
if ( V_21 -> V_63 . V_64 [ V_78 ] . V_65 ) {
F_15 ( L_55 , V_21 -> V_63 . V_64 [ V_78 ] . V_65 ) ;
F_87 ( V_21 -> V_63 . V_64 [ V_78 ] . V_65 ) ;
}
V_21 -> V_63 . V_64 [ V_78 ] . V_65 = NULL ;
}
F_6 ( V_21 -> V_164 -> V_9 ) ;
V_21 -> V_164 -> V_9 = NULL ;
F_41 ( & V_21 -> V_179 ) ;
F_6 ( V_21 ) ;
V_21 = NULL ;
}
static int F_88 ( struct V_48 * V_48 )
{
struct V_20 * V_21 ;
struct V_1 * V_2 ;
int V_78 , V_178 ;
F_15 ( L_3 , V_30 ) ;
V_21 = F_21 ( V_48 ) ;
if ( ! V_21 )
return - V_124 ;
F_40 ( & V_21 -> V_179 ) ;
V_2 = V_21 -> V_2 ;
if ( F_42 ( V_21 ) ) {
if ( V_21 -> V_91 )
F_78 ( V_21 ) ;
F_81 ( & V_21 -> V_51 ) ;
F_43 ( V_21 ) ;
}
V_21 -> V_180 -- ;
V_48 -> V_181 = NULL ;
for ( V_78 = 0 ; V_78 < 2 ; V_78 ++ ) {
V_178 =
F_1 ( V_2 , 1 , V_159 [ V_21 -> V_88 ] [ V_78 ] . V_4 ,
0 , V_159 [ V_21 -> V_88 ] [ V_78 ] . V_160 ,
V_159 [ V_21 -> V_88 ] [ V_78 ] . V_7 ) ;
if ( V_178 < 0 ) {
F_3 ( & V_2 -> V_11 , L_56 ) ;
goto V_153;
}
}
F_59 ( 100 ) ;
V_178 = 0 ;
V_153:
F_41 ( & V_21 -> V_179 ) ;
return V_178 ;
}
static int F_89 ( struct V_48 * V_48 , struct V_183 * V_184 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
int V_150 ;
if ( V_21 == NULL ) {
F_15 ( L_57 , V_30 ) ;
return - V_124 ;
}
F_15 ( L_58 , ( unsigned long ) V_184 ) ;
V_150 = F_90 ( & V_21 -> V_51 , V_184 ) ;
F_15 ( L_59 ,
( unsigned long ) V_184 -> V_185 ,
( unsigned long ) V_184 -> V_186 - ( unsigned long ) V_184 -> V_185 , V_150 ) ;
return V_150 ;
}
static unsigned int F_91 ( struct V_48 * V_48 ,
struct V_187 * V_188 )
{
struct V_20 * V_21 = F_21 ( V_48 ) ;
struct V_17 * V_149 = & V_21 -> V_51 ;
F_9 ( L_3 , V_30 ) ;
if ( V_21 -> type != V_50 )
return V_189 ;
return F_92 ( V_48 , V_149 , V_188 ) ;
}
static int F_93 ( struct V_20 * V_21 )
{
struct V_79 * V_164 = V_21 -> V_164 ;
unsigned long V_78 ;
F_15 ( L_60 , V_21 ) ;
memset ( V_164 , 0 , sizeof( * V_164 ) ) ;
V_164 -> V_21 = V_21 ;
V_164 -> V_100 = V_190 ;
V_164 -> V_9 = F_94 ( V_164 -> V_100 ,
V_10 ) ;
if ( V_164 -> V_9 == NULL ) {
F_15 ( L_61 ) ;
return - V_12 ;
}
V_21 -> V_91 = 0 ;
V_21 -> V_69 = 0 ;
for ( V_78 = 0 ; V_78 < V_173 ; V_78 ++ ) {
V_21 -> V_63 . V_64 [ V_78 ] . V_65 = F_95 ( V_99 ) ;
F_15 ( L_62 ,
& V_21 -> V_63 . V_64 [ V_78 ] , V_78 ,
V_21 -> V_63 . V_64 [ V_78 ] . V_65 ) ;
if ( V_21 -> V_63 . V_64 [ V_78 ] . V_65 == NULL ) {
F_26 (KERN_INFO KBUILD_MODNAME L_63
L_64 ) ;
break;
}
}
if ( V_78 == 0 ) {
F_26 (KERN_INFO KBUILD_MODNAME L_65 ) ;
F_6 ( V_21 -> V_164 -> V_9 ) ;
V_21 -> V_164 -> V_9 = NULL ;
return - V_12 ;
} else
V_21 -> V_63 . V_101 = V_78 ;
for ( V_78 = 0 ; V_78 < V_173 ; V_78 ++ ) {
V_21 -> V_63 . V_64 [ V_78 ] . V_92 = V_93 ;
V_21 -> V_63 . V_64 [ V_78 ] . V_95 = 0 ;
}
V_21 -> V_87 = 0 ;
V_21 -> V_60 = - 1 ;
F_72 ( V_21 ) ;
F_15 ( L_66 ) ;
return 0 ;
}
static int F_96 ( struct V_191 * V_192 ,
const struct V_193 * V_125 )
{
struct V_1 * V_2 = F_97 ( V_192 ) ;
struct V_20 * V_21 = NULL ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
int V_178 ;
int V_78 ;
F_15 ( L_67 ) ;
F_38 ( & V_192 -> V_11 , V_110 L_68 ) ;
F_38 ( & V_192 -> V_11 , L_69 ,
F_98 ( V_2 -> V_198 . V_199 ) ,
F_98 ( V_2 -> V_198 . V_200 ) ) ;
V_21 = F_94 ( sizeof( struct V_20 ) , V_10 ) ;
if ( V_21 == NULL ) {
F_3 ( & V_2 -> V_11 , L_70 ) ;
return - V_12 ;
}
V_21 -> V_88 = V_125 -> V_201 ;
V_21 -> V_177 = F_99 () ;
if ( V_21 -> V_177 == NULL ) {
F_3 ( & V_2 -> V_11 , L_71 ) ;
F_6 ( V_21 ) ;
V_21 = NULL ;
return - V_12 ;
}
memcpy ( V_21 -> V_177 , & V_202 , sizeof( V_202 ) ) ;
V_21 -> V_177 -> V_203 = & V_192 -> V_11 ;
F_100 ( V_21 -> V_177 , V_21 ) ;
if ( V_204 )
V_21 -> V_177 -> V_204 = V_205 | V_206 ;
V_21 -> V_2 = V_2 ;
switch ( V_132 ) {
case 1 :
F_38 ( & V_2 -> V_11 , L_72 ) ;
V_21 -> V_23 = 160 ;
V_21 -> V_24 = 120 ;
break;
case 2 :
F_38 ( & V_2 -> V_11 , L_73 ) ;
V_21 -> V_23 = 640 ;
V_21 -> V_24 = 480 ;
break;
default:
F_38 ( & V_2 -> V_11 , L_74 ) ;
V_21 -> V_23 = 320 ;
V_21 -> V_24 = 240 ;
break;
}
V_155 [ 0 ] = V_132 ;
V_156 [ 2 ] . V_4 = 0xf000 + V_132 ;
V_157 [ 1 ] . V_4 = 0xf000 + V_132 ;
if ( V_21 -> V_88 == V_158 ) {
switch ( V_132 ) {
case 1 :
V_157 [ 1 ] . V_4 = 0xf000 + 4 ;
break;
case 2 :
V_157 [ 1 ] . V_4 = 0xf000 + 0 ;
break;
default:
V_157 [ 1 ] . V_4 = 0xf000 + 1 ;
break;
}
}
V_98 [ 437 ] = V_21 -> V_24 / 256 ;
V_98 [ 438 ] = V_21 -> V_24 % 256 ;
V_98 [ 439 ] = V_21 -> V_23 / 256 ;
V_98 [ 440 ] = V_21 -> V_23 % 256 ;
V_21 -> V_180 = 0 ;
V_21 -> V_102 = 0 ;
V_21 -> V_132 . V_133 = 64 ;
F_101 ( & V_21 -> V_104 ) ;
F_101 ( & V_21 -> V_179 ) ;
F_15 ( L_75 , V_21 , V_21 -> V_2 , V_192 ) ;
V_195 = V_192 -> V_207 ;
F_15 ( L_76 , V_195 -> V_208 . V_209 ) ;
for ( V_78 = 0 ; V_78 < V_195 -> V_208 . V_209 ; ++ V_78 ) {
V_197 = & V_195 -> V_197 [ V_78 ] . V_208 ;
if ( ! V_21 -> V_168 && F_102 ( V_197 ) ) {
V_21 -> V_168 = V_197 -> V_210 ;
}
}
if ( ! V_21 -> V_168 ) {
F_3 ( & V_192 -> V_11 , L_77 ) ;
return - V_12 ;
}
F_103 ( & V_21 -> V_46 . V_47 ) ;
V_21 -> V_46 . V_21 = V_21 ;
V_178 = F_104 ( V_21 -> V_177 , V_211 , - 1 ) ;
if ( V_178 ) {
F_3 ( & V_2 -> V_11 , L_78 ) ;
F_105 ( V_21 -> V_177 ) ;
F_6 ( V_21 ) ;
V_21 = NULL ;
return V_178 ;
}
F_106 ( V_192 , V_21 ) ;
V_178 = F_93 ( V_21 ) ;
if ( V_178 ) {
F_107 ( & V_21 -> V_74 ) ;
return V_178 ;
}
F_107 ( & V_21 -> V_74 ) ;
F_38 ( & V_2 -> V_11 , V_110 L_79 ,
F_108 ( V_21 -> V_177 ) ) ;
return 0 ;
}
static void F_109 ( struct V_191 * V_192 )
{
struct V_20 * V_21 = F_110 ( V_192 ) ;
F_111 ( & V_21 -> V_51 ) ;
F_106 ( V_192 , NULL ) ;
F_38 ( & V_192 -> V_11 , V_110 L_80 ) ;
F_85 ( V_21 ) ;
}
static int T_9 F_112 ( void )
{
int V_171 ;
V_171 = F_113 ( & V_212 ) ;
if ( V_171 )
F_26 (KERN_ERR KBUILD_MODNAME L_81 ) ;
else
F_26 (KERN_INFO KBUILD_MODNAME L_82 DRIVER_DESC L_83 ) ;
return V_171 ;
}
static void T_10 F_114 ( void )
{
F_26 (KERN_INFO KBUILD_MODNAME L_82 DRIVER_DESC L_84 ) ;
F_115 ( & V_212 ) ;
}
