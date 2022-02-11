static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 ) {
V_4 -> V_5 -> V_6 = 0x05 ;
V_4 -> V_5 -> V_7 = 0x20 ;
V_4 -> V_5 -> V_8 = 0x00 ;
}
V_4 -> V_9 = - V_10 ;
return - V_10 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_3 ( & V_4 , NULL , 0 , V_11 ) ;
V_4 . V_12 [ 0 ] = V_13 ;
V_4 . V_14 = 5 * 60 * V_15 ;
return V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 * V_18 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
struct V_3 V_4 ;
int V_21 , V_22 ;
F_3 ( & V_4 , V_18 , sizeof( * V_18 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_24 ;
V_4 . V_12 [ 8 ] = V_4 . V_22 = 2 ;
V_4 . V_25 = 1 ;
V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_5 ( V_18 -> V_26 ) +
sizeof( V_18 -> V_26 ) ;
if ( V_22 > sizeof( T_1 ) )
V_22 = sizeof( T_1 ) ;
V_4 . V_12 [ 8 ] = V_4 . V_22 = V_22 ;
V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ;
if ( V_21 )
return V_21 ;
return V_22 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_27 [ 16 ] ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_14 = V_15 ;
V_4 . V_25 = 1 ;
if ( ! F_7 ( V_2 , & V_4 , V_28 , 0 ) ) {
V_2 -> V_29 = V_28 ;
return 0 ;
} else if ( ! F_7 ( V_2 , & V_4 , V_30 , 0 ) ) {
V_2 -> V_29 = V_30 ;
return 0 ;
}
return 1 ;
}
static int F_8 ( struct V_1 * V_2 , int * V_31 )
{
struct V_3 V_4 ;
struct V_32 * V_33 ;
unsigned char V_27 [ 16 ] ;
int V_21 ;
* V_31 = 0 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_34 ;
V_4 . V_12 [ 3 ] = V_35 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( ( V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_33 = (struct V_32 * ) & V_27 [ sizeof( struct V_36 ) ] ;
if ( F_5 ( V_33 -> V_37 ) != V_35 )
return 1 ;
* V_31 = V_33 -> V_31 ;
if ( ( V_21 = F_6 ( V_2 ) ) ) {
* V_31 = 0 ;
return V_21 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_38 )
{
struct V_3 V_4 ;
unsigned char V_27 [ 12 ] ;
int V_21 ;
F_10 ( L_1 , V_38 ? L_2 : L_3 ) ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_39 ) ;
V_4 . V_12 [ 0 ] = V_40 ;
V_4 . V_12 [ 1 ] = ( 1 << 4 ) | 1 ;
V_4 . V_14 = 5 * 60 * V_15 ;
V_27 [ 1 ] = 1 << 1 ;
V_27 [ 3 ] = 8 ;
V_27 [ 4 ] = 0xff ;
V_27 [ 5 ] = 0xff ;
V_27 [ 6 ] = 0xff ;
V_27 [ 7 ] = 0xff ;
V_27 [ 8 ] = 0x24 << 2 ;
V_27 [ 11 ] = V_38 ;
V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
if ( V_21 )
F_10 ( L_4 ) ;
return V_21 ;
}
static int F_11 ( struct V_1 * V_2 , int V_41 )
{
struct V_3 V_4 ;
F_3 ( & V_4 , NULL , 0 , V_11 ) ;
V_4 . V_12 [ 0 ] = V_42 ;
V_4 . V_12 [ 1 ] = ! ! V_41 ;
V_4 . V_12 [ 2 ] = 1 << 1 ;
V_4 . V_14 = 5 * 60 * V_15 ;
return V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_18 ;
int V_21 ;
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < 0 || V_21 < ( int ) F_13 ( F_14 ( V_18 ) , V_43 ) )
return 1 ;
V_21 = 0 ;
if ( V_18 . V_44 == V_45 ) {
F_10 ( L_5 ) ;
V_21 = F_11 ( V_2 , 0 ) ;
}
if ( ! V_21 && V_2 -> V_46 )
V_21 = F_2 ( V_2 ) ;
return V_21 ;
}
static int F_15 ( struct V_1 * V_2 , int V_47 )
{
struct V_3 V_4 ;
struct V_48 * V_49 ;
char V_27 [ 16 ] ;
int V_21 , V_50 , V_51 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_27 = V_27 ;
V_4 . V_22 = sizeof( V_27 ) ;
V_21 = F_7 ( V_2 , & V_4 , V_2 -> V_29 , 0 ) ;
if ( V_21 )
return V_21 ;
V_49 = (struct V_48 * ) V_27 ;
V_50 = F_5 ( V_49 -> V_52 ) ;
V_51 = F_5 ( V_49 -> V_53 ) + 2 ;
V_27 [ V_50 + 3 ] = V_47 ;
V_4 . V_22 = V_51 ;
V_21 = F_16 ( V_2 , & V_4 ) ;
if ( V_21 )
return V_21 ;
F_10 ( L_6 ,
V_2 -> V_54 , V_55 [ V_47 ] ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
static char V_56 ;
struct V_19 * V_20 = V_2 -> V_16 ;
int * V_57 = ( int * ) & V_20 -> V_58 ;
F_18 ( V_59 , L_7 ) ;
if ( V_20 -> V_60 == NULL || V_20 -> V_61 == NULL )
return - V_62 ;
if ( ! V_56 ) {
F_10 ( L_8 V_63 L_9 ) ;
V_56 = 1 ;
F_19 () ;
}
F_20 ( V_64 , V_65 ) ;
if ( V_20 -> V_66 == NULL && V_20 -> V_67 == NULL )
* V_57 = ~ ( V_68 | V_69 ) ;
F_20 ( V_70 , V_71 | V_72 ) ;
F_20 ( V_73 , V_74 ) ;
F_20 ( V_75 , V_76 ) ;
F_20 ( V_77 , V_78 ) ;
F_20 ( V_79 , V_80 ) ;
F_20 ( V_81 , V_82 ) ;
F_20 ( V_17 , V_83 ) ;
V_2 -> V_84 = 0 ;
V_20 -> V_85 = 0 ;
V_2 -> V_86 = V_87 ;
if ( V_88 == 1 && F_21 ( V_71 ) )
V_2 -> V_86 |= ( int ) V_89 ;
if ( V_90 == 1 && F_21 ( V_72 ) )
V_2 -> V_86 |= ( int ) V_91 ;
if ( V_92 == 1 )
V_2 -> V_86 |= ( int ) V_93 ;
if ( V_94 == 1 )
V_2 -> V_86 |= ( int ) V_95 ;
if ( F_21 ( V_96 ) )
V_2 -> exit = F_12 ;
if ( V_2 -> V_97 )
V_2 -> V_98 = V_99 ;
else
V_2 -> V_98 = V_100 ;
if ( ! V_20 -> V_17 )
V_20 -> V_17 = F_1 ;
F_18 ( V_101 , L_10 , V_2 -> V_54 ) ;
F_22 ( & V_102 ) ;
F_23 ( & V_2 -> V_103 , & V_104 ) ;
F_24 ( & V_102 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_18 ( V_59 , L_11 ) ;
F_22 ( & V_102 ) ;
F_26 ( & V_2 -> V_103 ) ;
F_24 ( & V_102 ) ;
if ( V_2 -> exit )
V_2 -> exit ( V_2 ) ;
V_2 -> V_16 -> V_85 -- ;
F_18 ( V_101 , L_12 , V_2 -> V_54 ) ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_3 V_4 ;
unsigned char V_27 [ 8 ] ;
struct V_107 * V_108 = (struct V_107 * ) V_27 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_109 ;
V_4 . V_12 [ 1 ] = 1 ;
V_4 . V_12 [ 4 ] = 1 << 4 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) )
return 1 ;
if ( F_5 ( V_108 -> V_110 ) < sizeof( * V_106 ) )
return 1 ;
if ( V_108 -> V_111 || V_108 -> V_112 != 0x4 )
return 1 ;
memcpy ( V_106 , & V_27 [ sizeof( * V_108 ) ] , sizeof( * V_106 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_113 * V_114 )
{
struct V_3 V_4 ;
char V_27 [ 24 ] ;
int V_21 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_34 ;
V_4 . V_12 [ 3 ] = V_115 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( ( V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
memcpy ( V_114 , & V_27 [ sizeof( struct V_36 ) ] , sizeof ( * V_114 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_27 [ 16 ] ;
T_2 * V_37 ;
int V_21 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_34 ;
V_4 . V_12 [ 3 ] = V_116 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( ( V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_37 = ( T_2 * ) & V_27 [ sizeof( struct V_36 ) ] ;
if ( F_5 ( * V_37 ) == V_116 )
return 0 ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , int * V_31 )
{
struct V_113 V_114 ;
int V_21 ;
* V_31 = 0 ;
if ( ( V_21 = F_28 ( V_2 , & V_114 ) ) )
return V_21 ;
if ( V_115 == F_5 ( V_114 . V_37 ) )
* V_31 = 1 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_18 ;
int V_21 ;
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < 0 || V_21 < F_13 ( F_14 ( V_18 ) , V_117 ) )
return - 1 ;
return V_18 . V_118 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_21 = F_31 ( V_2 ) ;
if ( ! V_21 )
return 1 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
T_1 V_18 ;
int V_21 ;
if ( F_15 ( V_2 , V_119 ) ) {
F_34 ( L_13 ) ;
return 1 ;
}
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < 0 || V_21 < F_13 ( F_14 ( V_18 ) , V_43 ) )
return 1 ;
if ( ! V_18 . V_118 )
return 1 ;
V_21 = 0 ;
F_10 ( L_14 , V_120 [ V_18 . V_44 ] ) ;
if ( ! V_18 . V_44 )
V_21 = 1 ;
else if ( V_18 . V_44 == V_121 &&
V_122 )
V_21 = F_9 ( V_2 , 1 ) ;
return V_21 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_27 [ 255 ] ;
int V_21 ;
F_3 ( & V_4 , & V_27 , 4 , V_23 ) ;
V_4 . V_25 = 1 ;
V_21 = F_7 ( V_2 , & V_4 , V_123 , 0 ) ;
if ( V_21 )
V_21 = F_7 ( V_2 , & V_4 , V_124 , 0 ) ;
if ( V_21 ) {
V_4 . V_22 = 255 ;
V_21 = F_7 ( V_2 , & V_4 , V_123 , 0 ) ;
}
if ( V_21 )
return 0 ;
return V_27 [ 3 ] & 0x80 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_113 V_114 ;
int V_21 ;
if ( ( V_21 = F_29 ( V_2 ) ) )
return V_21 ;
if ( ( V_21 = F_28 ( V_2 , & V_114 ) ) )
return V_21 ;
else if ( V_115 == F_5 ( V_114 . V_37 ) )
V_21 = ! V_114 . V_125 ;
F_18 ( V_59 , L_15 ) ;
return V_21 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_27 [ 32 ] ;
int V_21 , V_126 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_34 ;
V_4 . V_12 [ 1 ] = 0 ;
V_4 . V_12 [ 2 ] = V_4 . V_12 [ 3 ] = 0 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( ( V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ) )
V_126 = 0xffff ;
else
V_126 = ( V_27 [ 6 ] << 8 ) | V_27 [ 7 ] ;
V_2 -> V_126 = V_126 ;
}
static int F_38 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_126 ) {
case 0x12 :
case 0x1A :
return 0 ;
default:
return 1 ;
}
}
static int F_39 ( struct V_1 * V_2 )
{
int V_127 , V_128 , V_129 ;
int V_21 = 1 ;
V_127 = 0 ;
if ( ! F_8 ( V_2 , & V_128 ) )
V_127 = 1 ;
if ( F_21 ( V_130 ) )
V_129 = 1 ;
else
( void ) F_30 ( V_2 , & V_129 ) ;
if ( V_127 )
V_2 -> V_131 &= ~ V_132 ;
else
V_2 -> V_131 |= V_132 ;
if ( V_128 )
V_2 -> V_131 &= ~ V_96 ;
else
V_2 -> V_131 |= V_96 ;
if ( V_129 )
V_2 -> V_131 &= ~ V_133 ;
else
V_2 -> V_131 |= V_133 ;
if ( F_21 ( V_96 ) )
V_21 = F_33 ( V_2 ) ;
else if ( F_21 ( V_134 ) )
V_21 = F_32 ( V_2 ) ;
else if ( F_21 ( V_133 ) &&
! F_21 ( V_135 | V_136 | V_137 | V_138 | V_132 | V_130 ) )
V_21 = F_36 ( V_2 ) ;
else if ( F_21 ( V_130 ) )
V_21 = F_35 ( V_2 ) ;
else if ( ! F_38 ( V_2 ) )
V_21 = 0 ;
return V_21 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( V_2 -> V_126 != 0x1a ) {
F_18 ( V_139 , L_16 , V_2 -> V_54 ) ;
return;
}
if ( ! V_2 -> V_46 ) {
F_18 ( V_139 , L_17 , V_2 -> V_54 ) ;
return;
}
F_10 ( L_18 , V_2 -> V_54 ) ;
F_3 ( & V_4 , NULL , 0 , V_11 ) ;
V_4 . V_12 [ 0 ] = V_13 ;
V_4 . V_14 = 30 * V_15 ;
V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
F_3 ( & V_4 , NULL , 0 , V_11 ) ;
V_4 . V_12 [ 0 ] = V_42 ;
V_4 . V_14 = 3000 * V_15 ;
V_4 . V_25 = 1 ;
V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
F_3 ( & V_4 , NULL , 0 , V_11 ) ;
V_4 . V_12 [ 0 ] = V_42 ;
V_4 . V_12 [ 2 ] = 2 ;
V_4 . V_25 = 1 ;
V_4 . V_14 = 3000 * V_15 ;
V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
V_2 -> V_46 = 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
#if 0
return cdrom_flush_cache(cdi);
#else
return 0 ;
#endif
}
static void F_42 ( struct V_1 * V_2 , T_3 * V_140 )
{
struct V_141 V_142 ;
struct V_143 V_144 ;
int V_21 , V_145 ;
V_140 -> V_146 = 0 ;
V_140 -> V_147 = 0 ;
V_140 -> V_2 = 0 ;
V_140 -> V_148 = 0 ;
V_140 -> error = 0 ;
F_18 ( V_149 , L_19 ) ;
V_21 = V_2 -> V_16 -> V_150 ( V_2 , V_151 , & V_142 ) ;
if ( V_21 ) {
if ( V_21 == - V_152 )
V_140 -> error = V_153 ;
else
V_140 -> error = V_154 ;
return;
}
V_144 . V_155 = V_156 ;
for ( V_145 = V_142 . V_157 ; V_145 <= V_142 . V_158 ; V_145 ++ ) {
V_144 . V_159 = V_145 ;
if ( V_2 -> V_16 -> V_150 ( V_2 , V_160 , & V_144 ) ) {
V_140 -> error = V_154 ;
return;
}
if ( V_144 . V_161 & V_162 ) {
if ( V_144 . V_155 == 0x10 )
V_140 -> V_2 ++ ;
else if ( V_144 . V_155 == 0x20 )
V_140 -> V_148 ++ ;
else
V_140 -> V_146 ++ ;
} else {
V_140 -> V_147 ++ ;
}
F_18 ( V_149 , L_20 ,
V_145 , V_144 . V_155 , V_144 . V_161 ) ;
}
F_18 ( V_149 , L_21 ,
V_142 . V_158 , V_140 -> V_147 , V_140 -> V_146 ,
V_140 -> V_2 , V_140 -> V_148 ) ;
}
static
int F_43 ( struct V_1 * V_2 )
{
int V_21 ;
struct V_19 * V_20 = V_2 -> V_16 ;
T_3 V_140 ;
F_18 ( V_59 , L_22 ) ;
if ( V_20 -> V_64 != NULL ) {
V_21 = V_20 -> V_64 ( V_2 , V_163 ) ;
F_18 ( V_59 , L_23 , V_21 ) ;
if ( V_21 == V_164 ) {
F_18 ( V_59 , L_24 ) ;
if ( F_21 ( V_71 ) &&
V_2 -> V_86 & V_89 ) {
F_18 ( V_59 , L_25 ) ;
V_21 = V_20 -> V_70 ( V_2 , 0 ) ;
if ( V_21 ) {
F_18 ( V_59 , L_26 ) ;
V_21 = - V_152 ;
goto V_165;
}
} else {
F_18 ( V_59 , L_27 ) ;
V_21 = - V_152 ;
goto V_165;
}
V_21 = V_20 -> V_64 ( V_2 , V_163 ) ;
if ( ( V_21 == V_153 ) || ( V_21 == V_164 ) ) {
F_18 ( V_59 , L_28 ) ;
F_18 ( V_59 , L_29 ) ;
V_21 = - V_152 ;
goto V_165;
}
F_18 ( V_59 , L_30 ) ;
}
V_21 = V_20 -> V_64 ( V_2 , V_163 ) ;
if ( V_21 != V_166 ) {
V_21 = - V_152 ;
goto V_165;
}
}
F_42 ( V_2 , & V_140 ) ;
if ( V_140 . error == V_153 ) {
F_18 ( V_59 , L_31 ) ;
V_21 = - V_152 ;
goto V_165;
}
if ( V_140 . V_146 == 0 ) {
if ( V_2 -> V_86 & V_95 ) {
F_18 ( V_59 , L_32 ) ;
F_18 ( V_167 , L_33 ,
( unsigned int ) F_44 ( V_168 ) ) ;
V_21 = - V_169 ;
goto V_165;
}
else {
F_18 ( V_59 , L_34 ) ;
}
}
F_18 ( V_59 , L_35 ) ;
V_21 = V_20 -> V_60 ( V_2 , 0 ) ;
F_18 ( V_59 , L_36 , V_21 ) ;
if ( V_21 ) {
F_18 ( V_59 , L_37 ) ;
goto V_165;
}
if ( F_21 ( V_74 ) && ( V_2 -> V_86 & V_93 ) ) {
V_20 -> V_73 ( V_2 , 1 ) ;
F_18 ( V_59 , L_38 ) ;
}
F_18 ( V_59 , L_39 ) ;
return V_21 ;
V_165:
F_18 ( V_59 , L_40 ) ;
if ( F_21 ( V_74 ) && V_2 -> V_86 & V_93 ) {
V_20 -> V_73 ( V_2 , 0 ) ;
F_18 ( V_59 , L_41 ) ;
}
return V_21 ;
}
int F_45 ( struct V_1 * V_2 , struct V_170 * V_171 ,
T_4 V_172 )
{
int V_21 ;
F_18 ( V_59 , L_42 ) ;
F_46 ( V_171 ) ;
V_2 -> V_173 ++ ;
if ( ( V_172 & V_174 ) && ( V_2 -> V_86 & V_87 ) ) {
V_21 = V_2 -> V_16 -> V_60 ( V_2 , 1 ) ;
} else {
V_21 = F_43 ( V_2 ) ;
if ( V_21 )
goto V_175;
F_37 ( V_2 ) ;
if ( V_172 & V_176 ) {
V_21 = - V_177 ;
if ( F_39 ( V_2 ) )
goto V_178;
if ( ! F_21 ( V_133 ) )
goto V_178;
V_21 = 0 ;
V_2 -> V_46 = 0 ;
}
}
if ( V_21 )
goto V_175;
F_18 ( V_59 , L_43 ,
V_2 -> V_54 , V_2 -> V_173 ) ;
return 0 ;
V_178:
if ( F_21 ( V_74 ) && V_2 -> V_86 & V_93 ) {
V_2 -> V_16 -> V_73 ( V_2 , 0 ) ;
F_18 ( V_59 , L_41 ) ;
}
V_2 -> V_16 -> V_61 ( V_2 ) ;
V_175:
V_2 -> V_173 -- ;
return V_21 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_21 ;
T_3 V_140 ;
F_18 ( V_59 , L_44 ) ;
if ( ! ( V_2 -> V_86 & V_95 ) )
return 0 ;
if ( V_20 -> V_64 != NULL ) {
V_21 = V_20 -> V_64 ( V_2 , V_163 ) ;
F_18 ( V_59 , L_23 , V_21 ) ;
if ( V_21 == V_164 ) {
F_18 ( V_59 , L_24 ) ;
if ( F_21 ( V_71 ) &&
V_2 -> V_86 & V_89 ) {
F_18 ( V_59 , L_25 ) ;
V_21 = V_20 -> V_70 ( V_2 , 0 ) ;
if ( V_21 ) {
F_18 ( V_59 , L_45 ) ;
return - V_152 ;
}
} else {
F_18 ( V_59 , L_46 ) ;
return - V_152 ;
}
V_21 = V_20 -> V_64 ( V_2 , V_163 ) ;
if ( ( V_21 == V_153 ) || ( V_21 == V_164 ) ) {
F_18 ( V_59 , L_28 ) ;
return - V_152 ;
}
if ( V_21 != V_166 ) {
F_18 ( V_59 , L_47 ) ;
return - V_10 ;
}
F_18 ( V_59 , L_30 ) ;
}
}
F_42 ( V_2 , & V_140 ) ;
if ( V_140 . error )
return ( V_140 . error ) ;
if ( V_140 . V_147 == 0 )
return - V_169 ;
return 0 ;
}
void F_48 ( struct V_1 * V_2 , T_4 V_172 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
int V_179 ;
F_18 ( V_139 , L_48 ) ;
if ( V_2 -> V_173 > 0 )
V_2 -> V_173 -- ;
if ( V_2 -> V_173 == 0 ) {
F_18 ( V_139 , L_49 ,
V_2 -> V_54 ) ;
F_40 ( V_2 ) ;
if ( ( V_20 -> V_58 & V_74 ) && ! V_2 -> V_180 ) {
F_18 ( V_139 , L_50 ) ;
V_20 -> V_73 ( V_2 , 0 ) ;
}
}
V_179 = ! ( V_2 -> V_86 & V_87 ) ||
! ( V_172 & V_174 ) ;
if ( F_21 ( V_133 ) && ! V_2 -> V_173 && V_2 -> V_181 )
F_41 ( V_2 ) ;
V_20 -> V_61 ( V_2 ) ;
if ( V_2 -> V_173 == 0 ) {
if ( V_179 &&
V_2 -> V_86 & V_91 && F_21 ( V_72 ) )
V_20 -> V_70 ( V_2 , 1 ) ;
}
}
static int F_49 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
struct V_3 V_4 ;
struct V_19 * V_20 = V_2 -> V_16 ;
int V_184 ;
if ( V_2 -> V_185 ) {
V_183 -> V_186 . V_187 = 3 ;
V_183 -> V_186 . V_188 = V_2 -> V_185 == 3 ? 0 : V_2 -> V_185 ;
for ( V_184 = 0 ; V_184 < 3 ; V_184 ++ ) {
V_183 -> V_189 [ V_184 ] . V_190 = 1 ;
V_183 -> V_189 [ V_184 ] . V_191 = 0 ;
}
return 0 ;
}
V_184 = sizeof( struct V_192 ) +
V_2 -> V_193 * sizeof( struct V_194 ) ;
F_3 ( & V_4 , V_183 , V_184 , V_23 ) ;
V_4 . V_12 [ 0 ] = V_195 ;
V_4 . V_12 [ 8 ] = ( V_184 >> 8 ) & 0xff ;
V_4 . V_12 [ 9 ] = V_184 & 0xff ;
return V_20 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_50 ( struct V_1 * V_2 , int V_196 )
{
struct V_182 * V_197 ;
int V_21 ;
F_18 ( V_198 , L_51 ) ;
if ( V_2 -> V_185 )
return V_154 ;
V_197 = F_51 ( sizeof( * V_197 ) , V_199 ) ;
if ( ! V_197 )
return - V_200 ;
if ( ( V_21 = F_49 ( V_2 , V_197 ) ) )
goto V_201;
if ( V_197 -> V_189 [ V_196 ] . V_190 )
V_21 = V_166 ;
else
V_21 = V_153 ;
V_201:
F_52 ( V_197 ) ;
return V_21 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_202 ;
int V_187 = 1 ;
struct V_182 * V_197 ;
F_18 ( V_198 , L_52 ) ;
V_2 -> V_193 = 0 ;
V_197 = F_51 ( sizeof( * V_197 ) , V_199 ) ;
if ( ! V_197 )
return - V_200 ;
if ( ( V_202 = F_49 ( V_2 , V_197 ) ) == 0 )
V_187 = V_197 -> V_186 . V_187 ;
F_52 ( V_197 ) ;
return V_187 ;
}
static int F_54 ( struct V_1 * V_2 , int V_196 )
{
struct V_3 V_4 ;
F_18 ( V_198 , L_53 ) ;
if ( V_2 -> V_185 && V_196 < 0 )
return 0 ;
F_3 ( & V_4 , NULL , 0 , V_11 ) ;
V_4 . V_12 [ 0 ] = V_203 ;
V_4 . V_12 [ 4 ] = 2 + ( V_196 >= 0 ) ;
V_4 . V_12 [ 8 ] = V_196 ;
V_4 . V_14 = 60 * V_15 ;
if ( V_2 -> V_185 && - 1 < V_196 ) {
V_4 . V_12 [ 0 ] = V_204 ;
V_4 . V_12 [ 7 ] = V_196 ;
V_4 . V_12 [ 4 ] = V_4 . V_12 [ 8 ] = 0 ;
V_2 -> V_185 = V_196 ? V_196 : 3 ;
}
return V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_55 ( struct V_1 * V_2 , int V_196 )
{
struct V_182 * V_197 ;
int V_188 ;
int V_21 ;
F_18 ( V_198 , L_54 ) ;
if ( ! F_21 ( V_69 ) )
return - V_205 ;
if ( V_2 -> V_16 -> V_66 )
V_2 -> V_16 -> V_66 ( V_2 , 0 , V_196 ) ;
else
V_2 -> V_16 -> V_67 ( V_2 , V_196 ) ;
if ( V_196 == V_206 ) {
V_2 -> V_84 = 0x3 ;
return F_54 ( V_2 , - 1 ) ;
}
V_197 = F_51 ( sizeof( * V_197 ) , V_199 ) ;
if ( ! V_197 )
return - V_200 ;
if ( ( V_21 = F_49 ( V_2 , V_197 ) ) ) {
F_52 ( V_197 ) ;
return V_21 ;
}
V_188 = V_197 -> V_186 . V_188 ;
F_52 ( V_197 ) ;
if ( V_2 -> V_173 > 1 || V_2 -> V_180 ) {
if ( V_196 == V_163 ) {
return V_188 ;
} else {
return - V_207 ;
}
}
if ( V_196 == V_163 )
V_196 = V_188 ;
V_2 -> V_84 = 0x3 ;
if ( ( V_21 = F_54 ( V_2 , V_196 ) ) )
return V_21 ;
return V_196 ;
}
static void F_56 ( struct V_1 * V_2 ,
unsigned int V_208 )
{
unsigned int V_209 ;
V_209 = V_2 -> V_16 -> V_66 ( V_2 , V_208 , V_163 ) ;
V_2 -> V_210 |= V_209 ;
V_2 -> V_211 |= V_209 ;
}
unsigned int F_57 ( struct V_1 * V_2 ,
unsigned int V_208 )
{
unsigned int V_209 ;
F_56 ( V_2 , V_208 ) ;
V_209 = V_2 -> V_210 ;
V_2 -> V_210 = 0 ;
return V_209 ;
}
static
int V_67 ( struct V_1 * V_2 , int V_212 )
{
unsigned int V_131 = ( 1 << ( V_212 & 1 ) ) ;
int V_21 = ! ! ( V_2 -> V_84 & V_131 ) ;
bool V_213 ;
if ( ! F_21 ( V_68 ) )
return V_21 ;
if ( V_2 -> V_16 -> V_66 ) {
F_58 ( ! V_212 ) ;
F_56 ( V_2 , V_214 ) ;
V_213 = V_2 -> V_211 & V_214 ;
V_2 -> V_211 = 0 ;
} else
V_213 = V_2 -> V_16 -> V_67 ( V_2 , V_163 ) ;
if ( V_213 ) {
V_2 -> V_84 = 0x3 ;
V_21 |= 1 ;
V_2 -> V_46 = 0 ;
}
V_2 -> V_84 &= ~ V_131 ;
return V_21 ;
}
int F_59 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_16 -> V_67 == NULL )
return 0 ;
if ( ! F_21 ( V_68 ) )
return 0 ;
return V_67 ( V_2 , 0 ) ;
}
static
void F_60 ( union V_215 * V_216 ,
T_5 * V_125 , T_5 V_217 )
{
if ( * V_125 == V_217 )
return;
if ( V_217 == V_218 ) {
V_216 -> V_219 = ( int ) V_216 -> V_220 . V_221 +
75 * ( V_216 -> V_220 . V_222 - 2 + 60 * V_216 -> V_220 . V_223 ) ;
} else {
int V_219 = V_216 -> V_219 ;
V_216 -> V_220 . V_221 = V_219 % 75 ;
V_219 /= 75 ;
V_219 += 2 ;
V_216 -> V_220 . V_222 = V_219 % 60 ;
V_216 -> V_220 . V_223 = V_219 / 60 ;
}
* V_125 = V_217 ;
}
void F_3 ( struct V_3 * V_4 , void * V_183 , int V_224 ,
int type )
{
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
if ( V_183 )
memset ( V_183 , 0 , V_224 ) ;
V_4 -> V_27 = ( char * ) V_183 ;
V_4 -> V_22 = V_224 ;
V_4 -> V_225 = type ;
V_4 -> V_14 = V_226 ;
}
static void F_61 ( struct V_3 * V_4 , unsigned V_227 , unsigned type )
{
V_4 -> V_12 [ 0 ] = V_228 ;
V_4 -> V_12 [ 10 ] = type | ( V_227 << 6 ) ;
switch ( type ) {
case 0 : case 8 : case 5 : {
V_4 -> V_22 = 8 ;
break;
}
case 1 : {
V_4 -> V_22 = 16 ;
break;
}
case 2 : case 4 : {
V_4 -> V_22 = 12 ;
break;
}
}
V_4 -> V_12 [ 9 ] = V_4 -> V_22 ;
V_4 -> V_225 = V_23 ;
}
static void F_62 ( struct V_3 * V_4 , unsigned V_227 , unsigned type )
{
V_4 -> V_12 [ 0 ] = V_229 ;
V_4 -> V_12 [ 10 ] = type | ( V_227 << 6 ) ;
switch ( type ) {
case 1 : {
V_4 -> V_22 = 16 ;
break;
}
case 3 : {
V_4 -> V_22 = 12 ;
break;
}
case 6 : {
V_4 -> V_22 = 8 ;
break;
}
}
V_4 -> V_12 [ 9 ] = V_4 -> V_22 ;
V_4 -> V_225 = V_39 ;
}
static int F_63 ( struct V_1 * V_2 , T_6 * V_230 )
{
int V_21 ;
T_5 V_183 [ 20 ] ;
struct V_3 V_4 ;
struct V_19 * V_20 = V_2 -> V_16 ;
T_7 V_231 ;
memset ( V_183 , 0 , sizeof( V_183 ) ) ;
F_3 ( & V_4 , V_183 , 0 , V_23 ) ;
switch ( V_230 -> type ) {
case V_232 :
F_18 ( V_233 , L_55 ) ;
V_4 . V_25 = 1 ;
F_61 ( & V_4 , V_230 -> V_234 . V_227 , 0 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_230 -> V_234 . V_227 = V_183 [ 7 ] >> 6 ;
break;
case V_235 :
F_18 ( V_233 , L_56 ) ;
F_61 ( & V_4 , V_230 -> V_236 . V_227 , 2 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
F_64 ( V_230 -> V_236 . V_237 , & V_183 [ 4 ] ) ;
break;
case V_238 :
F_18 ( V_233 , L_57 ) ;
F_61 ( & V_4 , V_230 -> V_239 . V_227 , 1 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
F_65 ( V_230 -> V_239 . V_240 , & V_183 [ 4 ] ) ;
break;
case V_241 :
F_18 ( V_233 , L_58 ) ;
V_4 . V_25 = 1 ;
F_61 ( & V_4 , V_230 -> V_242 . V_227 , 4 ) ;
V_4 . V_12 [ 5 ] = V_230 -> V_242 . V_219 ;
V_4 . V_12 [ 4 ] = V_230 -> V_242 . V_219 >> 8 ;
V_4 . V_12 [ 3 ] = V_230 -> V_242 . V_219 >> 16 ;
V_4 . V_12 [ 2 ] = V_230 -> V_242 . V_219 >> 24 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_230 -> V_242 . V_243 = ( V_183 [ 4 ] >> 7 ) & 1 ;
V_230 -> V_242 . V_244 = ( V_183 [ 4 ] >> 6 ) & 1 ;
V_230 -> V_242 . V_245 = ( V_183 [ 4 ] >> 4 ) & 3 ;
F_64 ( V_230 -> V_242 . V_246 , & V_183 [ 5 ] ) ;
break;
case V_247 :
F_18 ( V_233 , L_59 ) ;
F_61 ( & V_4 , V_230 -> V_248 . V_227 , 5 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_230 -> V_248 . V_249 = V_183 [ 7 ] & 1 ;
break;
case V_250 :
F_18 ( V_233 , L_60 ) ;
F_62 ( & V_4 , V_230 -> V_251 . V_227 , 1 ) ;
V_183 [ 1 ] = 0xe ;
F_65 ( & V_183 [ 4 ] , V_230 -> V_251 . V_240 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_230 -> type = V_235 ;
break;
case V_252 :
F_18 ( V_233 , L_61 ) ;
F_62 ( & V_4 , V_230 -> V_253 . V_227 , 3 ) ;
V_183 [ 1 ] = 0xa ;
F_64 ( & V_183 [ 4 ] , V_230 -> V_253 . V_237 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) ) {
V_230 -> type = V_254 ;
return V_21 ;
}
V_230 -> type = V_255 ;
break;
case V_256 :
V_4 . V_25 = 1 ;
F_18 ( V_233 , L_62 ) ;
F_61 ( & V_4 , V_230 -> V_234 . V_227 , 0x3f ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
break;
case V_257 :
F_18 ( V_233 , L_63 ) ;
F_61 ( & V_4 , 0 , 8 ) ;
memset ( & V_231 , 0 , sizeof( T_7 ) ) ;
V_4 . V_27 = ( char * ) & V_231 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_230 -> V_258 . type = V_231 . V_259 ;
V_230 -> V_258 . V_260 = V_231 . V_260 ;
V_230 -> V_258 . V_261 = V_231 . V_261 ;
V_230 -> V_258 . V_262 = V_231 . V_262 ;
V_230 -> V_258 . V_263 = V_231 . V_263 ;
break;
case V_264 :
F_18 ( V_233 , L_64 ) ;
F_62 ( & V_4 , 0 , 6 ) ;
V_183 [ 1 ] = 6 ;
V_183 [ 4 ] = V_230 -> V_265 . V_266 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
break;
default:
F_18 ( V_167 , L_65 , V_230 -> type ) ;
return - V_267 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , T_8 * V_268 ,
struct V_3 * V_4 )
{
unsigned char V_183 [ 21 ] , * V_269 ;
struct V_270 * V_271 ;
struct V_19 * V_20 = V_2 -> V_16 ;
int V_21 , V_272 = V_268 -> V_273 . V_272 ;
if ( V_272 >= V_274 )
return - V_62 ;
F_3 ( V_4 , V_183 , sizeof( V_183 ) , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_275 ;
V_4 -> V_12 [ 6 ] = V_272 ;
V_4 -> V_12 [ 7 ] = V_268 -> type ;
V_4 -> V_12 [ 9 ] = V_4 -> V_22 & 0xff ;
V_4 -> V_25 = 1 ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
return V_21 ;
V_269 = & V_183 [ 4 ] ;
V_271 = & V_268 -> V_273 . V_271 [ V_272 ] ;
memset ( V_271 , 0 , sizeof( * V_271 ) ) ;
V_271 -> V_276 = V_269 [ 0 ] & 0xf ;
V_271 -> V_277 = V_269 [ 0 ] >> 4 ;
V_271 -> V_278 = V_269 [ 1 ] & 0xf ;
V_271 -> V_279 = V_269 [ 1 ] >> 4 ;
V_271 -> V_280 = V_269 [ 2 ] & 0xf ;
V_271 -> V_281 = ( V_269 [ 2 ] >> 4 ) & 1 ;
V_271 -> V_282 = ( V_269 [ 2 ] >> 5 ) & 3 ;
V_271 -> V_283 = V_269 [ 3 ] & 0xf ;
V_271 -> V_284 = V_269 [ 3 ] >> 4 ;
V_271 -> V_285 = V_269 [ 5 ] << 16 | V_269 [ 6 ] << 8 | V_269 [ 7 ] ;
V_271 -> V_286 = V_269 [ 9 ] << 16 | V_269 [ 10 ] << 8 | V_269 [ 11 ] ;
V_271 -> V_287 = V_269 [ 13 ] << 16 | V_269 [ 14 ] << 8 | V_269 [ 15 ] ;
V_271 -> V_288 = V_269 [ 16 ] >> 7 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_8 * V_268 ,
struct V_3 * V_4 )
{
int V_21 ;
T_5 V_183 [ 8 ] ;
struct V_19 * V_20 = V_2 -> V_16 ;
F_3 ( V_4 , V_183 , sizeof( V_183 ) , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_275 ;
V_4 -> V_12 [ 6 ] = V_268 -> V_289 . V_272 ;
V_4 -> V_12 [ 7 ] = V_268 -> type ;
V_4 -> V_12 [ 8 ] = V_4 -> V_22 >> 8 ;
V_4 -> V_12 [ 9 ] = V_4 -> V_22 & 0xff ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
return V_21 ;
V_268 -> V_289 . V_290 = V_183 [ 4 ] ;
V_268 -> V_289 . V_291 = V_183 [ 5 ] ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_8 * V_268 ,
struct V_3 * V_4 )
{
int V_21 , V_51 ;
T_5 * V_183 ;
struct V_19 * V_20 = V_2 -> V_16 ;
V_51 = sizeof( V_268 -> V_292 . V_293 ) + 4 ;
V_183 = F_51 ( V_51 , V_199 ) ;
if ( ! V_183 )
return - V_200 ;
F_3 ( V_4 , V_183 , V_51 , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_275 ;
V_4 -> V_12 [ 7 ] = V_268 -> type ;
V_4 -> V_12 [ 8 ] = V_51 >> 8 ;
V_4 -> V_12 [ 9 ] = V_51 & 0xff ;
V_4 -> V_12 [ 10 ] = V_268 -> V_292 . V_227 << 6 ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( ! V_21 )
memcpy ( V_268 -> V_292 . V_293 , & V_183 [ 4 ] , sizeof( V_268 -> V_292 . V_293 ) ) ;
F_52 ( V_183 ) ;
return V_21 ;
}
static int F_69 ( struct V_1 * V_2 , T_8 * V_268 ,
struct V_3 * V_4 )
{
int V_21 , V_51 = 4 + 188 ;
T_5 * V_183 ;
struct V_19 * V_20 = V_2 -> V_16 ;
V_183 = F_51 ( V_51 , V_199 ) ;
if ( ! V_183 )
return - V_200 ;
F_3 ( V_4 , V_183 , V_51 , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_275 ;
V_4 -> V_12 [ 7 ] = V_268 -> type ;
V_4 -> V_12 [ 9 ] = V_4 -> V_22 & 0xff ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
goto V_294;
V_268 -> V_288 . V_224 = V_183 [ 0 ] << 8 | V_183 [ 1 ] ;
if ( V_268 -> V_288 . V_224 < 12 || V_268 -> V_288 . V_224 > 188 ) {
F_18 ( V_167 , L_66 ,
V_268 -> V_288 . V_224 ) ;
V_21 = - V_10 ;
goto V_294;
}
memcpy ( V_268 -> V_288 . V_293 , & V_183 [ 4 ] , V_268 -> V_288 . V_224 ) ;
V_21 = 0 ;
V_294:
F_52 ( V_183 ) ;
return V_21 ;
}
static int F_70 ( struct V_1 * V_2 , T_8 * V_268 ,
struct V_3 * V_4 )
{
int V_21 = 0 , V_51 ;
T_5 * V_183 ;
struct V_19 * V_20 = V_2 -> V_16 ;
V_51 = sizeof( V_268 -> V_295 . V_293 ) + 4 ;
V_183 = F_51 ( V_51 , V_199 ) ;
if ( ! V_183 )
return - V_200 ;
F_3 ( V_4 , V_183 , V_51 , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_275 ;
V_4 -> V_12 [ 7 ] = V_268 -> type ;
V_4 -> V_12 [ 8 ] = V_51 >> 8 ;
V_4 -> V_12 [ 9 ] = V_51 & 0xff ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
goto V_294;
V_268 -> V_295 . V_224 = V_183 [ 0 ] << 8 | V_183 [ 1 ] ;
if ( V_268 -> V_295 . V_224 < 0 ) {
F_18 ( V_167 , L_67 ,
V_268 -> V_295 . V_224 ) ;
V_21 = - V_10 ;
} else {
if ( V_268 -> V_295 . V_224 > 2048 ) {
F_18 ( V_167 , L_68 ,
V_268 -> V_295 . V_224 ) ;
V_268 -> V_295 . V_224 = 2048 ;
}
memcpy ( V_268 -> V_295 . V_293 , & V_183 [ 4 ] , V_268 -> V_295 . V_224 ) ;
}
V_294:
F_52 ( V_183 ) ;
return V_21 ;
}
static int F_71 ( struct V_1 * V_2 , T_8 * V_268 ,
struct V_3 * V_4 )
{
switch ( V_268 -> type ) {
case V_296 :
return F_66 ( V_2 , V_268 , V_4 ) ;
case V_297 :
return F_67 ( V_2 , V_268 , V_4 ) ;
case V_298 :
return F_68 ( V_2 , V_268 , V_4 ) ;
case V_299 :
return F_69 ( V_2 , V_268 , V_4 ) ;
case V_300 :
return F_70 ( V_2 , V_268 , V_4 ) ;
default:
F_18 ( V_167 , L_69 ,
V_268 -> type ) ;
return - V_62 ;
}
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_301 , int V_302 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
memset ( V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_12 [ 0 ] = V_303 ;
V_4 -> V_12 [ 2 ] = V_301 | ( V_302 << 6 ) ;
V_4 -> V_12 [ 7 ] = V_4 -> V_22 >> 8 ;
V_4 -> V_12 [ 8 ] = V_4 -> V_22 & 0xff ;
V_4 -> V_225 = V_23 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
memset ( V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
memset ( V_4 -> V_27 , 0 , 2 ) ;
V_4 -> V_12 [ 0 ] = V_304 ;
V_4 -> V_12 [ 1 ] = 0x10 ;
V_4 -> V_12 [ 7 ] = V_4 -> V_22 >> 8 ;
V_4 -> V_12 [ 8 ] = V_4 -> V_22 & 0xff ;
V_4 -> V_225 = V_39 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_305 * V_306 , int V_307 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
struct V_3 V_4 ;
char V_27 [ 32 ] ;
int V_21 ;
F_3 ( & V_4 , V_27 , 16 , V_23 ) ;
V_4 . V_12 [ 0 ] = V_308 ;
V_4 . V_12 [ 1 ] = 2 ;
V_4 . V_12 [ 2 ] = 0x40 ;
V_4 . V_12 [ 3 ] = V_307 ? 2 : 1 ;
V_4 . V_12 [ 8 ] = 16 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_306 -> V_309 = V_4 . V_27 [ 1 ] ;
V_306 -> V_310 = V_156 ;
V_306 -> V_311 = V_4 . V_27 [ 5 ] & 0xf ;
V_306 -> V_312 = V_4 . V_27 [ 6 ] ;
V_306 -> V_313 = V_4 . V_27 [ 7 ] ;
V_306 -> V_314 . V_220 . V_223 = V_4 . V_27 [ 13 ] ;
V_306 -> V_314 . V_220 . V_222 = V_4 . V_27 [ 14 ] ;
V_306 -> V_314 . V_220 . V_221 = V_4 . V_27 [ 15 ] ;
V_306 -> V_315 . V_220 . V_223 = V_4 . V_27 [ 9 ] ;
V_306 -> V_315 . V_220 . V_222 = V_4 . V_27 [ 10 ] ;
V_306 -> V_315 . V_220 . V_221 = V_4 . V_27 [ 11 ] ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_219 ,
int V_316 , int V_317 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
memset ( & V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_12 [ 0 ] = V_318 ;
V_4 -> V_12 [ 2 ] = ( V_219 >> 24 ) & 0xff ;
V_4 -> V_12 [ 3 ] = ( V_219 >> 16 ) & 0xff ;
V_4 -> V_12 [ 4 ] = ( V_219 >> 8 ) & 0xff ;
V_4 -> V_12 [ 5 ] = V_219 & 0xff ;
V_4 -> V_12 [ 6 ] = ( V_317 >> 16 ) & 0xff ;
V_4 -> V_12 [ 7 ] = ( V_317 >> 8 ) & 0xff ;
V_4 -> V_12 [ 8 ] = V_317 & 0xff ;
V_4 -> V_22 = V_316 * V_317 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_219 , int V_317 , int V_319 , int V_320 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
memset ( & V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_12 [ 0 ] = V_321 ;
V_4 -> V_12 [ 1 ] = V_319 << 2 ;
V_4 -> V_12 [ 2 ] = ( V_219 >> 24 ) & 0xff ;
V_4 -> V_12 [ 3 ] = ( V_219 >> 16 ) & 0xff ;
V_4 -> V_12 [ 4 ] = ( V_219 >> 8 ) & 0xff ;
V_4 -> V_12 [ 5 ] = V_219 & 0xff ;
V_4 -> V_12 [ 6 ] = ( V_317 >> 16 ) & 0xff ;
V_4 -> V_12 [ 7 ] = ( V_317 >> 8 ) & 0xff ;
V_4 -> V_12 [ 8 ] = V_317 & 0xff ;
V_4 -> V_22 = V_320 * V_317 ;
switch ( V_320 ) {
case V_322 : V_4 -> V_12 [ 9 ] = 0x58 ; break;
case V_323 : V_4 -> V_12 [ 9 ] = 0x78 ; break;
case V_324 : V_4 -> V_12 [ 9 ] = 0xf8 ; break;
default : V_4 -> V_12 [ 9 ] = 0x10 ;
}
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static int F_75 ( struct V_1 * V_2 , T_9 T_10 * V_325 ,
int V_219 , int V_326 )
{
struct V_3 V_4 ;
int V_21 = 0 ;
int V_327 ;
V_2 -> V_328 = 0 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_327 = V_326 ;
do {
V_4 . V_27 = F_51 ( V_324 * V_327 , V_199 ) ;
if ( V_4 . V_27 )
break;
V_327 >>= 1 ;
} while ( V_327 );
if ( ! V_327 )
return - V_200 ;
V_4 . V_225 = V_23 ;
while ( V_326 > 0 ) {
if ( V_327 > V_326 )
V_327 = V_326 ;
V_21 = F_74 ( V_2 , & V_4 , V_219 , V_327 , 1 , V_324 ) ;
if ( V_21 )
break;
if ( F_76 ( V_325 , V_4 . V_27 , V_324 * V_327 ) ) {
V_21 = - V_329 ;
break;
}
V_325 += V_324 * V_327 ;
V_326 -= V_327 ;
V_219 += V_327 ;
}
F_52 ( V_4 . V_27 ) ;
return V_21 ;
}
static int F_77 ( struct V_1 * V_2 , T_9 T_10 * V_325 ,
int V_219 , int V_326 )
{
struct V_330 * V_331 = V_2 -> V_97 -> V_212 ;
struct V_332 * V_333 ;
struct V_334 * V_334 ;
unsigned int V_224 ;
int V_327 , V_21 = 0 ;
if ( ! V_331 )
return - V_335 ;
V_2 -> V_328 = 0 ;
while ( V_326 ) {
V_327 = V_326 ;
if ( V_2 -> V_98 == V_336 )
V_327 = 1 ;
if ( V_327 * V_324 > ( F_78 ( V_331 ) << 9 ) )
V_327 = ( F_78 ( V_331 ) << 9 ) / V_324 ;
V_224 = V_327 * V_324 ;
V_333 = F_79 ( V_331 , V_337 , V_199 ) ;
if ( ! V_333 ) {
V_21 = - V_200 ;
break;
}
F_80 ( V_333 ) ;
V_21 = F_81 ( V_331 , V_333 , NULL , V_325 , V_224 , V_199 ) ;
if ( V_21 ) {
F_82 ( V_333 ) ;
break;
}
V_333 -> V_12 [ 0 ] = V_321 ;
V_333 -> V_12 [ 1 ] = 1 << 2 ;
V_333 -> V_12 [ 2 ] = ( V_219 >> 24 ) & 0xff ;
V_333 -> V_12 [ 3 ] = ( V_219 >> 16 ) & 0xff ;
V_333 -> V_12 [ 4 ] = ( V_219 >> 8 ) & 0xff ;
V_333 -> V_12 [ 5 ] = V_219 & 0xff ;
V_333 -> V_12 [ 6 ] = ( V_327 >> 16 ) & 0xff ;
V_333 -> V_12 [ 7 ] = ( V_327 >> 8 ) & 0xff ;
V_333 -> V_12 [ 8 ] = V_327 & 0xff ;
V_333 -> V_12 [ 9 ] = 0xf8 ;
V_333 -> V_338 = 12 ;
V_333 -> V_14 = 60 * V_15 ;
V_334 = V_333 -> V_334 ;
if ( F_83 ( V_331 , V_2 -> V_97 , V_333 , 0 ) ) {
struct V_339 * V_268 = V_333 -> V_5 ;
V_21 = - V_10 ;
V_2 -> V_328 = V_268 -> V_6 ;
}
if ( F_84 ( V_334 ) )
V_21 = - V_329 ;
F_82 ( V_333 ) ;
if ( V_21 )
break;
V_326 -= V_327 ;
V_219 += V_327 ;
V_325 += V_224 ;
}
return V_21 ;
}
static int F_85 ( struct V_1 * V_2 , T_9 T_10 * V_325 ,
int V_219 , int V_326 )
{
int V_21 ;
if ( V_2 -> V_98 == V_100 )
return F_75 ( V_2 , V_325 , V_219 , V_326 ) ;
V_340:
V_21 = F_77 ( V_2 , V_325 , V_219 , V_326 ) ;
if ( ! V_21 || V_21 != - V_10 )
return V_21 ;
if ( V_2 -> V_98 == V_99 && V_326 > 1 ) {
F_10 ( L_70 ) ;
V_2 -> V_98 = V_336 ;
goto V_340;
}
if ( V_2 -> V_328 != 0x04 && V_2 -> V_328 != 0x0b )
return V_21 ;
F_10 ( L_71 , V_2 -> V_328 ) ;
V_2 -> V_98 = V_100 ;
return F_75 ( V_2 , V_325 , V_219 , V_326 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_342 V_343 ;
T_11 V_344 ;
int V_21 ;
F_18 ( V_345 , L_72 ) ;
if ( ! ( V_2 -> V_16 -> V_58 & V_78 ) )
return - V_346 ;
if ( F_87 ( & V_343 , V_341 , sizeof( V_343 ) ) )
return - V_329 ;
V_344 = V_343 . V_347 ;
if ( V_344 != V_156 && V_344 != V_218 )
return - V_62 ;
V_343 . V_347 = V_218 ;
V_21 = V_2 -> V_16 -> V_77 ( V_2 , & V_343 ) ;
if ( V_21 )
return V_21 ;
F_60 ( & V_343 . V_216 , & V_343 . V_347 , V_344 ) ;
if ( F_76 ( V_341 , & V_343 , sizeof( V_343 ) ) )
return - V_329 ;
F_18 ( V_345 , L_73 ) ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 )
{
F_18 ( V_345 , L_74 ) ;
if ( ! F_21 ( V_72 ) )
return - V_346 ;
if ( V_2 -> V_173 != 1 || V_2 -> V_180 )
return - V_207 ;
if ( F_21 ( V_74 ) ) {
int V_21 = V_2 -> V_16 -> V_73 ( V_2 , 0 ) ;
if ( V_21 )
return V_21 ;
}
return V_2 -> V_16 -> V_70 ( V_2 , 1 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
F_18 ( V_345 , L_75 ) ;
if ( ! F_21 ( V_71 ) )
return - V_346 ;
return V_2 -> V_16 -> V_70 ( V_2 , 0 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_76 ) ;
if ( ! F_21 ( V_72 ) )
return - V_346 ;
if ( V_2 -> V_180 )
return - V_207 ;
V_2 -> V_86 &= ~ ( V_89 | V_91 ) ;
if ( V_348 )
V_2 -> V_86 |= V_89 | V_91 ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
struct V_182 * V_197 ;
int V_21 ;
F_18 ( V_345 , L_77 ) ;
if ( ! F_21 ( V_68 ) )
return - V_346 ;
if ( ! F_21 ( V_69 ) || V_348 == V_163 )
return V_67 ( V_2 , 1 ) ;
if ( ( unsigned int ) V_348 >= V_2 -> V_193 )
return - V_62 ;
V_197 = F_51 ( sizeof( * V_197 ) , V_199 ) ;
if ( ! V_197 )
return - V_200 ;
V_21 = F_49 ( V_2 , V_197 ) ;
if ( ! V_21 )
V_21 = V_197 -> V_189 [ V_348 ] . V_191 ;
F_52 ( V_197 ) ;
return V_21 ;
}
static int F_92 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_78 ) ;
switch ( V_348 ) {
case V_87 :
case V_95 :
break;
case V_93 :
if ( ! F_21 ( V_74 ) )
return - V_346 ;
break;
case 0 :
return V_2 -> V_86 ;
default:
if ( ! F_21 ( V_348 ) )
return - V_346 ;
}
V_2 -> V_86 |= ( int ) V_348 ;
return V_2 -> V_86 ;
}
static int F_93 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_79 ) ;
V_2 -> V_86 &= ~ ( int ) V_348 ;
return V_2 -> V_86 ;
}
static int F_94 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_80 ) ;
if ( ! F_21 ( V_76 ) )
return - V_346 ;
return V_2 -> V_16 -> V_75 ( V_2 , V_348 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_81 ) ;
if ( ! F_21 ( V_69 ) )
return - V_346 ;
if ( V_348 != V_163 && V_348 != V_206 ) {
if ( ( int ) V_348 >= V_2 -> V_193 )
return - V_62 ;
}
if ( V_2 -> V_16 -> V_349 )
return V_2 -> V_16 -> V_349 ( V_2 , V_348 ) ;
F_18 ( V_198 , L_82 ) ;
return F_55 ( V_2 , V_348 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_170 * V_171 )
{
F_18 ( V_345 , L_83 ) ;
if ( ! F_97 ( V_350 ) )
return - V_351 ;
if ( ! F_21 ( V_82 ) )
return - V_346 ;
F_98 ( V_171 ) ;
return V_2 -> V_16 -> V_81 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_84 , V_348 ? L_85 : L_86 ) ;
if ( ! F_21 ( V_74 ) )
return - V_205 ;
V_2 -> V_180 = V_348 ? 1 : 0 ;
if ( V_2 -> V_173 != 1 && ! V_348 && ! F_97 ( V_350 ) )
return - V_207 ;
return V_2 -> V_16 -> V_73 ( V_2 , V_348 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_87 , V_348 ? L_88 : L_89 ) ;
if ( ! F_97 ( V_350 ) )
return - V_351 ;
V_352 = V_348 ? 1 : 0 ;
return V_352 ;
}
static int F_101 ( struct V_1 * V_2 )
{
F_18 ( V_345 , L_90 ) ;
return ( V_2 -> V_16 -> V_58 & ~ V_2 -> V_131 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_353 V_307 ;
int V_21 ;
F_18 ( V_345 , L_91 ) ;
if ( ! ( V_2 -> V_16 -> V_58 & V_80 ) )
return - V_346 ;
V_21 = V_2 -> V_16 -> V_79 ( V_2 , & V_307 ) ;
if ( V_21 )
return V_21 ;
if ( F_76 ( V_341 , & V_307 , sizeof( V_307 ) ) )
return - V_329 ;
F_18 ( V_345 , L_92 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
unsigned long V_348 )
{
F_18 ( V_345 , L_93 ) ;
if ( ! ( V_2 -> V_16 -> V_58 & V_65 ) )
return - V_346 ;
if ( ! F_21 ( V_69 ) ||
( V_348 == V_163 || V_348 == V_206 ) )
return V_2 -> V_16 -> V_64 ( V_2 , V_163 ) ;
if ( ( ( int ) V_348 >= V_2 -> V_193 ) )
return - V_62 ;
return F_50 ( V_2 , V_348 ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
T_3 V_140 ;
F_18 ( V_345 , L_94 ) ;
F_42 ( V_2 , & V_140 ) ;
if ( V_140 . error )
return V_140 . error ;
if ( V_140 . V_147 > 0 ) {
if ( ! V_140 . V_146 && ! V_140 . V_2 && ! V_140 . V_148 )
return V_354 ;
else
return V_355 ;
}
if ( V_140 . V_2 > 0 )
return V_356 ;
if ( V_140 . V_148 > 0 )
return V_357 ;
if ( V_140 . V_146 > 0 )
return V_358 ;
F_18 ( V_167 , L_95 ) ;
return V_154 ;
}
static int F_105 ( struct V_1 * V_2 )
{
F_18 ( V_345 , L_96 ) ;
return V_2 -> V_193 ;
}
static int F_106 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_305 V_331 ;
T_11 V_217 , V_359 ;
int V_21 ;
if ( F_87 ( & V_331 , V_341 , sizeof( V_331 ) ) )
return - V_329 ;
V_217 = V_331 . V_310 ;
if ( V_217 != V_156 && V_217 != V_218 )
return - V_62 ;
V_331 . V_310 = V_156 ;
V_21 = V_2 -> V_16 -> V_150 ( V_2 , V_360 , & V_331 ) ;
if ( V_21 )
return V_21 ;
V_359 = V_331 . V_310 ;
F_60 ( & V_331 . V_315 , & V_359 , V_217 ) ;
F_60 ( & V_331 . V_314 , & V_331 . V_310 , V_217 ) ;
if ( F_76 ( V_341 , & V_331 , sizeof( V_331 ) ) )
return - V_329 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_141 V_142 ;
int V_21 ;
if ( F_87 ( & V_142 , V_341 , sizeof( V_142 ) ) )
return - V_329 ;
V_21 = V_2 -> V_16 -> V_150 ( V_2 , V_151 , & V_142 ) ;
if ( V_21 )
return V_21 ;
if ( F_76 ( V_341 , & V_142 , sizeof( V_142 ) ) )
return - V_329 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_143 V_144 ;
T_11 V_344 ;
int V_21 ;
if ( F_87 ( & V_144 , V_341 , sizeof( V_144 ) ) )
return - V_329 ;
V_344 = V_144 . V_155 ;
if ( V_344 != V_156 && V_344 != V_218 )
return - V_62 ;
V_144 . V_155 = V_156 ;
V_21 = V_2 -> V_16 -> V_150 ( V_2 , V_160 , & V_144 ) ;
if ( V_21 )
return V_21 ;
F_60 ( & V_144 . V_361 , & V_144 . V_155 , V_344 ) ;
if ( F_76 ( V_341 , & V_144 , sizeof( V_144 ) ) )
return - V_329 ;
return 0 ;
}
static int F_109 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_362 V_220 ;
F_18 ( V_345 , L_97 ) ;
if ( ! F_21 ( V_363 ) )
return - V_346 ;
if ( F_87 ( & V_220 , V_341 , sizeof( V_220 ) ) )
return - V_329 ;
return V_2 -> V_16 -> V_150 ( V_2 , V_364 , & V_220 ) ;
}
static int F_110 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_365 V_366 ;
int V_21 ;
F_18 ( V_345 , L_98 ) ;
if ( ! F_21 ( V_363 ) )
return - V_346 ;
if ( F_87 ( & V_366 , V_341 , sizeof( V_366 ) ) )
return - V_329 ;
V_21 = F_47 ( V_2 , V_2 -> V_16 ) ;
if ( V_21 )
return V_21 ;
return V_2 -> V_16 -> V_150 ( V_2 , V_367 , & V_366 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_368 V_369 ;
F_18 ( V_345 , L_99 ) ;
if ( ! F_21 ( V_363 ) )
return - V_346 ;
if ( F_87 ( & V_369 , V_341 , sizeof( V_369 ) ) )
return - V_329 ;
return V_2 -> V_16 -> V_150 ( V_2 , V_370 , & V_369 ) ;
}
static int F_112 ( struct V_1 * V_2 ,
void T_10 * V_341 )
{
struct V_368 V_369 ;
int V_21 ;
F_18 ( V_345 , L_100 ) ;
if ( ! F_21 ( V_363 ) )
return - V_346 ;
V_21 = V_2 -> V_16 -> V_150 ( V_2 , V_371 , & V_369 ) ;
if ( V_21 )
return V_21 ;
if ( F_76 ( V_341 , & V_369 , sizeof( V_369 ) ) )
return - V_329 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
int V_21 ;
F_18 ( V_345 , L_101 ) ;
if ( ! F_21 ( V_363 ) )
return - V_346 ;
V_21 = F_47 ( V_2 , V_2 -> V_16 ) ;
if ( V_21 )
return V_21 ;
return V_2 -> V_16 -> V_150 ( V_2 , V_12 , NULL ) ;
}
static int F_114 ( struct V_1 * V_2 , int V_51 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
struct V_3 V_4 ;
struct V_372 V_373 ;
memset ( & V_373 , 0 , sizeof( V_373 ) ) ;
V_373 . V_374 = 0x08 ;
V_373 . V_375 = ( V_51 >> 8 ) & 0xff ;
V_373 . V_376 = V_51 & 0xff ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 [ 0 ] = 0x15 ;
V_4 . V_12 [ 1 ] = 1 << 4 ;
V_4 . V_12 [ 4 ] = 12 ;
V_4 . V_22 = sizeof( V_373 ) ;
V_4 . V_27 = ( char * ) & V_373 ;
V_4 . V_225 = V_39 ;
V_373 . V_374 = 0x08 ;
V_373 . V_375 = ( V_51 >> 8 ) & 0xff ;
V_373 . V_376 = V_51 & 0xff ;
return V_20 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
T_12 V_377 , T_9 type , T_13 * V_366 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
struct V_3 V_4 ;
int V_21 , V_22 ;
F_3 ( & V_4 , V_366 , 8 , V_23 ) ;
V_4 . V_12 [ 0 ] = V_378 ;
V_4 . V_12 [ 1 ] = type & 3 ;
V_4 . V_12 [ 4 ] = ( V_377 & 0xff00 ) >> 8 ;
V_4 . V_12 [ 5 ] = V_377 & 0xff ;
V_4 . V_12 [ 8 ] = 8 ;
V_4 . V_25 = 1 ;
V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_5 ( V_366 -> V_379 ) +
sizeof( V_366 -> V_379 ) ;
if ( V_22 > sizeof( T_13 ) )
V_22 = sizeof( T_13 ) ;
V_4 . V_12 [ 8 ] = V_4 . V_22 = V_22 ;
V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ;
if ( V_21 )
return V_21 ;
return V_22 ;
}
int F_116 ( struct V_1 * V_2 , long * V_380 )
{
struct V_143 V_381 ;
T_1 V_18 ;
T_13 V_366 ;
T_14 V_382 ;
int V_21 = - 1 , V_383 ;
if ( ! F_21 ( V_83 ) )
goto V_384;
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < ( int ) ( F_13 ( F_14 ( V_18 ) , V_385 )
+ sizeof( V_18 . V_385 ) ) )
goto V_384;
V_382 = ( V_18 . V_386 << 8 ) | V_18 . V_385 ;
V_383 = F_115 ( V_2 , V_382 , 1 , & V_366 ) ;
if ( V_383 < ( int ) F_13 ( F_14 ( V_366 ) , V_387 ) )
goto V_384;
if ( V_366 . V_388 ) {
if ( V_382 == 1 )
goto V_384;
V_382 -- ;
V_383 = F_115 ( V_2 , V_382 , 1 , & V_366 ) ;
}
if ( V_383 < ( int ) ( F_13 ( F_14 ( V_366 ) , V_389 )
+ sizeof( V_366 . V_389 ) ) )
goto V_384;
if ( V_366 . V_390 && V_383 >= ( int ) ( F_13 ( F_14 ( V_366 ) , V_391 )
+ sizeof( V_366 . V_391 ) ) ) {
* V_380 = F_117 ( V_366 . V_391 ) ;
} else {
* V_380 = F_117 ( V_366 . V_387 ) +
F_117 ( V_366 . V_389 ) ;
if ( V_366 . V_392 )
* V_380 -= ( F_117 ( V_366 . V_392 ) + 7 ) ;
}
return 0 ;
V_384:
V_381 . V_155 = V_156 ;
V_381 . V_159 = V_393 ;
if ( ( V_21 = V_2 -> V_16 -> V_150 ( V_2 , V_160 , & V_381 ) ) )
return V_21 ;
F_60 ( & V_381 . V_361 , & V_381 . V_155 , V_218 ) ;
* V_380 = V_381 . V_361 . V_219 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
long * V_394 )
{
T_1 V_18 ;
T_13 V_366 ;
T_12 V_382 ;
int V_21 , V_383 ;
if ( ! F_21 ( V_83 ) )
goto V_395;
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < 0 || V_21 < F_13 ( F_14 ( V_18 ) , V_385 )
+ sizeof( V_18 . V_385 ) )
goto V_395;
V_382 = ( V_18 . V_386 << 8 ) | V_18 . V_385 ;
V_383 = F_115 ( V_2 , V_382 , 1 , & V_366 ) ;
if ( V_383 < 0 || V_383 < F_13 ( F_14 ( V_366 ) , V_387 ) )
goto V_395;
if ( V_366 . V_388 ) {
if ( V_382 == 1 )
goto V_395;
V_382 -- ;
V_383 = F_115 ( V_2 , V_382 , 1 , & V_366 ) ;
if ( V_383 < 0 )
goto V_395;
}
if ( V_366 . V_396 && V_383 >= F_13 ( F_14 ( V_366 ) , V_394 )
+ sizeof( V_366 . V_394 ) ) {
* V_394 = F_117 ( V_366 . V_394 ) ;
return 0 ;
}
V_395:
V_21 = F_116 ( V_2 , V_394 ) ;
if ( V_21 ) {
* V_394 = 0 ;
return V_21 ;
} else {
* V_394 += 7 ;
return 0 ;
}
}
static T_15 int F_119 ( struct V_1 * V_2 ,
void T_10 * V_348 ,
struct V_3 * V_4 ,
int V_12 )
{
struct V_339 V_5 ;
struct V_362 V_220 ;
int V_316 = 0 , V_319 = 0 , V_219 ;
int V_21 ;
switch ( V_12 ) {
case V_397 :
V_316 = V_324 ;
break;
case V_398 :
V_316 = V_399 ;
V_319 = 2 ;
break;
case V_400 :
V_316 = V_322 ;
break;
}
if ( F_87 ( & V_220 , (struct V_362 T_10 * ) V_348 , sizeof( V_220 ) ) )
return - V_329 ;
V_219 = F_120 ( V_220 . V_401 , V_220 . V_402 , V_220 . V_403 ) ;
if ( V_219 < 0 )
return - V_62 ;
V_4 -> V_27 = F_121 ( V_316 , V_199 ) ;
if ( V_4 -> V_27 == NULL )
return - V_200 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_4 -> V_5 = & V_5 ;
V_4 -> V_225 = V_23 ;
V_21 = F_74 ( V_2 , V_4 , V_219 , 1 , V_319 , V_316 ) ;
if ( V_21 && V_5 . V_6 == 0x05 &&
V_5 . V_7 == 0x20 &&
V_5 . V_8 == 0x00 ) {
V_21 = F_114 ( V_2 , V_316 ) ;
if ( V_21 )
goto V_294;
V_4 -> V_5 = NULL ;
V_21 = F_73 ( V_2 , V_4 , V_219 , V_316 , 1 ) ;
V_21 |= F_114 ( V_2 , V_316 ) ;
}
if ( ! V_21 && F_76 ( V_348 , V_4 -> V_27 , V_316 ) )
V_21 = - V_329 ;
V_294:
F_52 ( V_4 -> V_27 ) ;
return V_21 ;
}
static T_15 int F_122 ( struct V_1 * V_2 ,
void T_10 * V_348 )
{
struct V_404 V_405 ;
int V_219 ;
if ( F_87 ( & V_405 , (struct V_404 T_10 * ) V_348 ,
sizeof( V_405 ) ) )
return - V_329 ;
if ( V_405 . V_347 == V_156 )
V_219 = F_120 ( V_405 . V_216 . V_220 . V_223 ,
V_405 . V_216 . V_220 . V_222 ,
V_405 . V_216 . V_220 . V_221 ) ;
else if ( V_405 . V_347 == V_218 )
V_219 = V_405 . V_216 . V_219 ;
else
return - V_62 ;
if ( V_219 < 0 || V_405 . V_326 <= 0 || V_405 . V_326 > V_406 )
return - V_62 ;
return F_85 ( V_2 , V_405 . V_183 , V_219 , V_405 . V_326 ) ;
}
static T_15 int F_123 ( struct V_1 * V_2 ,
void T_10 * V_348 )
{
int V_21 ;
struct V_305 V_331 ;
T_5 V_217 , V_359 ;
if ( F_87 ( & V_331 , (struct V_305 T_10 * ) V_348 , sizeof( V_331 ) ) )
return - V_329 ;
V_217 = V_331 . V_310 ;
if ( ! ( ( V_217 == V_156 ) ||
( V_217 == V_218 ) ) )
return - V_62 ;
V_331 . V_310 = V_156 ;
V_21 = F_72 ( V_2 , & V_331 , 0 ) ;
if ( V_21 )
return V_21 ;
V_359 = V_331 . V_310 ;
F_60 ( & V_331 . V_315 , & V_359 , V_217 ) ;
F_60 ( & V_331 . V_314 , & V_331 . V_310 , V_217 ) ;
if ( F_76 ( (struct V_305 T_10 * ) V_348 , & V_331 , sizeof( V_331 ) ) )
return - V_329 ;
return 0 ;
}
static T_15 int F_124 ( struct V_1 * V_2 ,
void T_10 * V_348 ,
struct V_3 * V_4 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
struct V_362 V_220 ;
F_18 ( V_345 , L_97 ) ;
if ( F_87 ( & V_220 , (struct V_362 T_10 * ) V_348 , sizeof( V_220 ) ) )
return - V_329 ;
V_4 -> V_12 [ 0 ] = V_407 ;
V_4 -> V_12 [ 3 ] = V_220 . V_401 ;
V_4 -> V_12 [ 4 ] = V_220 . V_402 ;
V_4 -> V_12 [ 5 ] = V_220 . V_403 ;
V_4 -> V_12 [ 6 ] = V_220 . V_408 ;
V_4 -> V_12 [ 7 ] = V_220 . V_409 ;
V_4 -> V_12 [ 8 ] = V_220 . V_410 ;
V_4 -> V_225 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_125 ( struct V_1 * V_2 ,
void T_10 * V_348 ,
struct V_3 * V_4 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
struct V_411 V_412 ;
F_18 ( V_345 , L_102 ) ;
if ( F_87 ( & V_412 , (struct V_411 T_10 * ) V_348 , sizeof( V_412 ) ) )
return - V_329 ;
V_4 -> V_12 [ 0 ] = V_413 ;
V_4 -> V_12 [ 2 ] = ( V_412 . V_414 >> 24 ) & 0xff ;
V_4 -> V_12 [ 3 ] = ( V_412 . V_414 >> 16 ) & 0xff ;
V_4 -> V_12 [ 4 ] = ( V_412 . V_414 >> 8 ) & 0xff ;
V_4 -> V_12 [ 5 ] = V_412 . V_414 & 0xff ;
V_4 -> V_12 [ 7 ] = ( V_412 . V_224 >> 8 ) & 0xff ;
V_4 -> V_12 [ 8 ] = V_412 . V_224 & 0xff ;
V_4 -> V_225 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_126 ( struct V_1 * V_2 ,
void T_10 * V_348 ,
struct V_3 * V_4 ,
unsigned int V_12 )
{
struct V_368 V_415 ;
unsigned char V_27 [ 32 ] ;
char V_131 [ sizeof( V_27 ) ] ;
unsigned short V_50 ;
int V_21 ;
F_18 ( V_345 , L_103 ) ;
if ( F_87 ( & V_415 , (struct V_368 T_10 * ) V_348 ,
sizeof( V_415 ) ) )
return - V_329 ;
V_4 -> V_27 = V_27 ;
V_4 -> V_22 = 24 ;
V_21 = F_7 ( V_2 , V_4 , V_416 , 0 ) ;
if ( V_21 )
return V_21 ;
V_50 = 8 + F_5 ( * ( T_2 * ) ( V_27 + 6 ) ) ;
if ( V_50 + 16 > sizeof( V_27 ) )
return - V_417 ;
if ( V_50 + 16 > V_4 -> V_22 ) {
V_4 -> V_22 = V_50 + 16 ;
V_21 = F_7 ( V_2 , V_4 ,
V_416 , 0 ) ;
if ( V_21 )
return V_21 ;
}
if ( ( V_27 [ V_50 ] & 0x3f ) != V_416 ||
V_27 [ V_50 + 1 ] < 14 )
return - V_62 ;
if ( V_12 == V_371 ) {
V_415 . V_418 = V_27 [ V_50 + 9 ] ;
V_415 . V_419 = V_27 [ V_50 + 11 ] ;
V_415 . V_420 = V_27 [ V_50 + 13 ] ;
V_415 . V_421 = V_27 [ V_50 + 15 ] ;
if ( F_76 ( (struct V_368 T_10 * ) V_348 , & V_415 ,
sizeof( V_415 ) ) )
return - V_329 ;
return 0 ;
}
V_4 -> V_27 = V_131 ;
V_21 = F_7 ( V_2 , V_4 , V_416 , 1 ) ;
if ( V_21 )
return V_21 ;
V_27 [ V_50 + 9 ] = V_415 . V_418 & V_131 [ V_50 + 9 ] ;
V_27 [ V_50 + 11 ] = V_415 . V_419 & V_131 [ V_50 + 11 ] ;
V_27 [ V_50 + 13 ] = V_415 . V_420 & V_131 [ V_50 + 13 ] ;
V_27 [ V_50 + 15 ] = V_415 . V_421 & V_131 [ V_50 + 15 ] ;
V_4 -> V_27 = V_27 + V_50 - 8 ;
memset ( V_4 -> V_27 , 0 , 8 ) ;
return F_16 ( V_2 , V_4 ) ;
}
static T_15 int F_127 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
F_18 ( V_345 , L_104 ) ;
V_4 -> V_12 [ 0 ] = V_422 ;
V_4 -> V_12 [ 1 ] = 1 ;
V_4 -> V_12 [ 4 ] = ( V_12 == V_423 ) ? 1 : 0 ;
V_4 -> V_225 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_128 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 )
{
struct V_19 * V_20 = V_2 -> V_16 ;
F_18 ( V_345 , L_105 ) ;
V_4 -> V_12 [ 0 ] = V_424 ;
V_4 -> V_12 [ 8 ] = ( V_12 == V_425 ) ? 1 : 0 ;
V_4 -> V_225 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_129 ( struct V_1 * V_2 ,
void T_10 * V_348 ,
struct V_3 * V_4 )
{
int V_21 ;
T_8 * V_268 ;
int V_51 = sizeof( T_8 ) ;
if ( ! F_21 ( V_137 ) )
return - V_346 ;
V_268 = F_51 ( V_51 , V_199 ) ;
if ( ! V_268 )
return - V_200 ;
F_18 ( V_345 , L_106 ) ;
if ( F_87 ( V_268 , V_348 , V_51 ) ) {
F_52 ( V_268 ) ;
return - V_329 ;
}
V_21 = F_71 ( V_2 , V_268 , V_4 ) ;
if ( V_21 )
goto V_294;
if ( F_76 ( V_348 , V_268 , V_51 ) )
V_21 = - V_329 ;
V_294:
F_52 ( V_268 ) ;
return V_21 ;
}
static T_15 int F_130 ( struct V_1 * V_2 ,
void T_10 * V_348 )
{
int V_21 ;
T_6 V_230 ;
if ( ! F_21 ( V_137 ) )
return - V_346 ;
F_18 ( V_345 , L_107 ) ;
if ( F_87 ( & V_230 , ( T_6 T_10 * ) V_348 , sizeof( V_230 ) ) )
return - V_329 ;
V_21 = F_63 ( V_2 , & V_230 ) ;
if ( V_21 )
return V_21 ;
if ( F_76 ( ( T_6 T_10 * ) V_348 , & V_230 , sizeof( V_230 ) ) )
return - V_329 ;
return 0 ;
}
static T_15 int F_131 ( struct V_1 * V_2 ,
void T_10 * V_348 )
{
int V_21 ;
long V_426 = 0 ;
F_18 ( V_345 , L_108 ) ;
V_21 = F_118 ( V_2 , & V_426 ) ;
if ( V_21 )
return V_21 ;
if ( F_76 ( ( long T_10 * ) V_348 , & V_426 , sizeof( V_426 ) ) )
return - V_329 ;
return 0 ;
}
static T_15 int F_132 ( struct V_1 * V_2 ,
void T_10 * V_348 )
{
int V_21 ;
long V_427 = 0 ;
F_18 ( V_345 , L_109 ) ;
V_21 = F_116 ( V_2 , & V_427 ) ;
if ( V_21 )
return V_21 ;
if ( F_76 ( ( long T_10 * ) V_348 , & V_427 , sizeof( V_427 ) ) )
return - V_329 ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned long V_348 )
{
struct V_3 V_4 ;
void T_10 * V_428 = ( void T_10 * ) V_348 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
switch ( V_12 ) {
case V_397 :
case V_398 :
case V_400 :
return F_119 ( V_2 , V_428 , & V_4 , V_12 ) ;
case V_429 :
return F_122 ( V_2 , V_428 ) ;
case V_360 :
return F_123 ( V_2 , V_428 ) ;
case V_364 :
return F_124 ( V_2 , V_428 , & V_4 ) ;
case V_430 :
return F_125 ( V_2 , V_428 , & V_4 ) ;
case V_370 :
case V_371 :
return F_126 ( V_2 , V_428 , & V_4 , V_12 ) ;
case V_423 :
case V_431 :
return F_127 ( V_2 , & V_4 , V_12 ) ;
case V_432 :
case V_425 :
return F_128 ( V_2 , & V_4 , V_12 ) ;
case V_433 :
return F_129 ( V_2 , V_428 , & V_4 ) ;
case V_434 :
return F_130 ( V_2 , V_428 ) ;
case V_435 :
return F_131 ( V_2 , V_428 ) ;
case V_436 :
return F_132 ( V_2 , V_428 ) ;
}
return - V_267 ;
}
int F_134 ( struct V_1 * V_2 , struct V_170 * V_171 ,
T_4 V_172 , unsigned int V_12 , unsigned long V_348 )
{
void T_10 * V_341 = ( void T_10 * ) V_348 ;
int V_21 ;
V_21 = F_135 ( V_171 , V_172 , V_12 , V_341 ) ;
if ( V_21 != - V_267 )
return V_21 ;
switch ( V_12 ) {
case V_437 :
return F_86 ( V_2 , V_341 ) ;
case V_438 :
return F_88 ( V_2 ) ;
case V_439 :
return F_89 ( V_2 ) ;
case V_440 :
return F_90 ( V_2 , V_348 ) ;
case V_441 :
return F_91 ( V_2 , V_348 ) ;
case V_442 :
return F_92 ( V_2 , V_348 ) ;
case V_443 :
return F_93 ( V_2 , V_348 ) ;
case V_444 :
return F_94 ( V_2 , V_348 ) ;
case V_445 :
return F_95 ( V_2 , V_348 ) ;
case V_446 :
return F_96 ( V_2 , V_171 ) ;
case V_447 :
return F_99 ( V_2 , V_348 ) ;
case V_448 :
return F_100 ( V_2 , V_348 ) ;
case V_449 :
return F_101 ( V_2 ) ;
case V_450 :
return F_102 ( V_2 , V_341 ) ;
case V_451 :
return F_103 ( V_2 , V_348 ) ;
case V_452 :
return F_104 ( V_2 ) ;
case V_453 :
return F_105 ( V_2 ) ;
}
if ( F_21 ( V_83 ) ) {
V_21 = F_133 ( V_2 , V_12 , V_348 ) ;
if ( V_21 != - V_267 )
return V_21 ;
}
switch ( V_12 ) {
case V_360 :
return F_106 ( V_2 , V_341 ) ;
case V_151 :
return F_107 ( V_2 , V_341 ) ;
case V_160 :
return F_108 ( V_2 , V_341 ) ;
case V_364 :
return F_109 ( V_2 , V_341 ) ;
case V_367 :
return F_110 ( V_2 , V_341 ) ;
case V_370 :
return F_111 ( V_2 , V_341 ) ;
case V_371 :
return F_112 ( V_2 , V_341 ) ;
case V_423 :
case V_431 :
case V_432 :
case V_425 :
return F_113 ( V_2 , V_12 ) ;
}
return - V_346 ;
}
static int F_136 ( const char * V_142 , int V_454 , char * V_197 ,
int * V_455 , enum V_456 V_457 )
{
const int V_458 = sizeof( V_459 . V_197 ) ;
struct V_1 * V_2 ;
int V_21 ;
V_21 = F_137 ( V_197 + * V_455 , V_458 - * V_455 , V_142 ) ;
if ( ! V_21 )
return 1 ;
* V_455 += V_21 ;
F_138 (cdi, &cdrom_list, list) {
switch ( V_457 ) {
case V_460 :
V_21 = F_137 ( V_197 + * V_455 , V_458 - * V_455 ,
L_110 , V_2 -> V_54 ) ;
break;
case V_461 :
V_21 = F_137 ( V_197 + * V_455 , V_458 - * V_455 ,
L_111 , V_2 -> V_462 ) ;
break;
case V_463 :
V_21 = F_137 ( V_197 + * V_455 , V_458 - * V_455 ,
L_111 , V_2 -> V_193 ) ;
break;
case V_464 :
V_21 = F_137 ( V_197 + * V_455 , V_458 - * V_455 ,
L_111 , F_21 ( V_454 ) != 0 ) ;
break;
default:
F_10 ( L_112 , V_457 ) ;
return 1 ;
}
if ( ! V_21 )
return 1 ;
* V_455 += V_21 ;
}
return 0 ;
}
static int F_139 ( struct V_465 * V_466 , int V_31 ,
void T_10 * V_27 , T_16 * V_467 , T_17 * V_468 )
{
int V_455 ;
char * V_197 = V_459 . V_197 ;
const int V_458 = sizeof( V_459 . V_197 ) ;
if ( ! * V_467 || ( * V_468 && ! V_31 ) ) {
* V_467 = 0 ;
return 0 ;
}
F_22 ( & V_102 ) ;
V_455 = sprintf ( V_197 , L_113 V_469 L_9 ) ;
if ( F_136 ( L_114 , 0 , V_197 , & V_455 , V_460 ) )
goto V_470;
if ( F_136 ( L_115 , 0 , V_197 , & V_455 , V_461 ) )
goto V_470;
if ( F_136 ( L_116 , 0 , V_197 , & V_455 , V_463 ) )
goto V_470;
if ( F_136 ( L_117 ,
V_71 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_118 ,
V_72 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_119 ,
V_74 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_120 ,
V_76 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_121 ,
V_69 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_122 ,
V_78 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_123 ,
V_80 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_124 ,
V_68 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_125 ,
V_363 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_126 ,
V_135 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_127 ,
V_136 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_128 ,
V_137 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_129 ,
V_138 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_130 ,
V_134 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_131 ,
V_132 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_132 ,
V_96 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( F_136 ( L_133 ,
V_133 , V_197 , & V_455 , V_464 ) )
goto V_470;
if ( ! F_137 ( V_197 + V_455 , V_458 - V_455 , L_134 ) )
goto V_470;
V_471:
F_24 ( & V_102 ) ;
return F_140 ( V_466 , V_31 , V_27 , V_467 , V_468 ) ;
V_470:
F_10 ( L_135 ) ;
goto V_471;
}
static void F_141 ( void )
{
struct V_1 * V_2 ;
F_22 ( & V_102 ) ;
F_138 (cdi, &cdrom_list, list) {
if ( V_88 && F_21 ( V_71 ) )
V_2 -> V_86 |= V_89 ;
else if ( ! V_88 )
V_2 -> V_86 &= ~ V_89 ;
if ( V_90 && F_21 ( V_72 ) )
V_2 -> V_86 |= V_91 ;
else if ( ! V_90 )
V_2 -> V_86 &= ~ V_91 ;
if ( V_92 && F_21 ( V_74 ) )
V_2 -> V_86 |= V_93 ;
else if ( ! V_92 )
V_2 -> V_86 &= ~ V_93 ;
if ( V_94 )
V_2 -> V_86 |= V_95 ;
else
V_2 -> V_86 &= ~ V_95 ;
}
F_24 ( & V_102 ) ;
}
static int F_142 ( struct V_465 * V_466 , int V_31 ,
void T_10 * V_27 , T_16 * V_467 , T_17 * V_468 )
{
int V_21 ;
V_21 = F_143 ( V_466 , V_31 , V_27 , V_467 , V_468 ) ;
if ( V_31 ) {
V_88 = ! ! V_459 . V_88 ;
V_90 = ! ! V_459 . V_90 ;
V_352 = ! ! V_459 . V_352 ;
V_92 = ! ! V_459 . V_472 ;
V_94 = ! ! V_459 . V_473 ;
F_141 () ;
}
return V_21 ;
}
static void F_19 ( void )
{
static int V_474 ;
if ( V_474 == 1 )
return;
V_475 = F_144 ( V_476 ) ;
V_459 . V_88 = V_88 ;
V_459 . V_90 = V_90 ;
V_459 . V_352 = V_352 ;
V_459 . V_472 = V_92 ;
V_459 . V_473 = V_94 ;
V_474 = 1 ;
}
static void F_145 ( void )
{
if ( V_475 )
F_146 ( V_475 ) ;
}
static void F_19 ( void )
{
}
static void F_145 ( void )
{
}
static int T_18 F_147 ( void )
{
F_19 () ;
return 0 ;
}
static void T_19 F_148 ( void )
{
F_10 ( L_136 ) ;
F_145 () ;
}
