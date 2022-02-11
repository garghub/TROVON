int F_1 ( struct V_1 * V_2 ,
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
const struct V_19 * V_20 = V_2 -> V_16 ;
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
const struct V_19 * V_20 = V_2 -> V_16 ;
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
V_2 -> V_85 = V_86 ;
if ( V_87 == 1 && F_21 ( V_71 ) )
V_2 -> V_85 |= ( int ) V_88 ;
if ( V_89 == 1 && F_21 ( V_72 ) )
V_2 -> V_85 |= ( int ) V_90 ;
if ( V_91 == 1 )
V_2 -> V_85 |= ( int ) V_92 ;
if ( V_93 == 1 )
V_2 -> V_85 |= ( int ) V_94 ;
if ( F_21 ( V_95 ) )
V_2 -> exit = F_12 ;
if ( V_2 -> V_96 )
V_2 -> V_97 = V_98 ;
else
V_2 -> V_97 = V_99 ;
F_22 ( ! V_20 -> V_17 ) ;
F_18 ( V_100 , L_10 , V_2 -> V_54 ) ;
F_23 ( & V_101 ) ;
F_24 ( & V_2 -> V_102 , & V_103 ) ;
F_25 ( & V_101 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
F_18 ( V_59 , L_11 ) ;
F_23 ( & V_101 ) ;
F_27 ( & V_2 -> V_102 ) ;
F_25 ( & V_101 ) ;
if ( V_2 -> exit )
V_2 -> exit ( V_2 ) ;
F_18 ( V_100 , L_12 , V_2 -> V_54 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_3 V_4 ;
unsigned char V_27 [ 8 ] ;
struct V_106 * V_107 = (struct V_106 * ) V_27 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_108 ;
V_4 . V_12 [ 1 ] = 1 ;
V_4 . V_12 [ 4 ] = 1 << 4 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) )
return 1 ;
if ( F_5 ( V_107 -> V_109 ) < sizeof( * V_105 ) )
return 1 ;
if ( V_107 -> V_110 || V_107 -> V_111 != 0x4 )
return 1 ;
memcpy ( V_105 , & V_27 [ sizeof( * V_107 ) ] , sizeof( * V_105 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_3 V_4 ;
char V_27 [ 24 ] ;
int V_21 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_34 ;
V_4 . V_12 [ 3 ] = V_114 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( ( V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
memcpy ( V_113 , & V_27 [ sizeof( struct V_36 ) ] , sizeof ( * V_113 ) ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_27 [ 16 ] ;
T_2 * V_37 ;
int V_21 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_34 ;
V_4 . V_12 [ 3 ] = V_115 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( ( V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_37 = ( T_2 * ) & V_27 [ sizeof( struct V_36 ) ] ;
if ( F_5 ( * V_37 ) == V_115 )
return 0 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 , int * V_31 )
{
struct V_112 V_113 ;
int V_21 ;
* V_31 = 0 ;
if ( ( V_21 = F_29 ( V_2 , & V_113 ) ) )
return V_21 ;
if ( V_114 == F_5 ( V_113 . V_37 ) )
* V_31 = 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_18 ;
int V_21 ;
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < 0 || V_21 < F_13 ( F_14 ( V_18 ) , V_116 ) )
return - 1 ;
return V_18 . V_117 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_21 = F_32 ( V_2 ) ;
if ( ! V_21 )
return 1 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 V_18 ;
int V_21 ;
if ( F_15 ( V_2 , V_118 ) ) {
F_35 ( L_13 ) ;
return 1 ;
}
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < 0 || V_21 < F_13 ( F_14 ( V_18 ) , V_43 ) )
return 1 ;
if ( ! V_18 . V_117 )
return 1 ;
V_21 = 0 ;
F_10 ( L_14 , V_119 [ V_18 . V_44 ] ) ;
if ( ! V_18 . V_44 )
V_21 = 1 ;
else if ( V_18 . V_44 == V_120 &&
V_121 )
V_21 = F_9 ( V_2 , 1 ) ;
return V_21 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_27 [ 255 ] ;
int V_21 ;
F_3 ( & V_4 , & V_27 , 4 , V_23 ) ;
V_4 . V_25 = 1 ;
V_21 = F_7 ( V_2 , & V_4 , V_122 , 0 ) ;
if ( V_21 )
V_21 = F_7 ( V_2 , & V_4 , V_123 , 0 ) ;
if ( V_21 ) {
V_4 . V_22 = 255 ;
V_21 = F_7 ( V_2 , & V_4 , V_122 , 0 ) ;
}
if ( V_21 )
return 0 ;
return V_27 [ 3 ] & 0x80 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_112 V_113 ;
int V_21 ;
if ( ( V_21 = F_30 ( V_2 ) ) )
return V_21 ;
if ( ( V_21 = F_29 ( V_2 , & V_113 ) ) )
return V_21 ;
else if ( V_114 == F_5 ( V_113 . V_37 ) )
V_21 = ! V_113 . V_124 ;
F_18 ( V_59 , L_15 ) ;
return V_21 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_27 [ 32 ] ;
int V_21 , V_125 ;
F_3 ( & V_4 , V_27 , sizeof( V_27 ) , V_23 ) ;
V_4 . V_12 [ 0 ] = V_34 ;
V_4 . V_12 [ 1 ] = 0 ;
V_4 . V_12 [ 2 ] = V_4 . V_12 [ 3 ] = 0 ;
V_4 . V_12 [ 8 ] = sizeof( V_27 ) ;
V_4 . V_25 = 1 ;
if ( ( V_21 = V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ) )
V_125 = 0xffff ;
else
V_125 = ( V_27 [ 6 ] << 8 ) | V_27 [ 7 ] ;
V_2 -> V_125 = V_125 ;
}
static int F_39 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_125 ) {
case 0x12 :
case 0x1A :
case 0x43 :
return 0 ;
default:
return 1 ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
int V_126 , V_127 , V_128 ;
int V_21 = 1 ;
V_126 = 0 ;
if ( ! F_8 ( V_2 , & V_127 ) )
V_126 = 1 ;
if ( F_21 ( V_129 ) )
V_128 = 1 ;
else
( void ) F_31 ( V_2 , & V_128 ) ;
if ( V_126 )
V_2 -> V_130 &= ~ V_131 ;
else
V_2 -> V_130 |= V_131 ;
if ( V_127 )
V_2 -> V_130 &= ~ V_95 ;
else
V_2 -> V_130 |= V_95 ;
if ( V_128 )
V_2 -> V_130 &= ~ V_132 ;
else
V_2 -> V_130 |= V_132 ;
if ( F_21 ( V_95 ) )
V_21 = F_34 ( V_2 ) ;
else if ( F_21 ( V_133 ) )
V_21 = F_33 ( V_2 ) ;
else if ( F_21 ( V_132 ) &&
! F_21 ( V_134 | V_135 | V_136 | V_137 | V_131 | V_129 ) )
V_21 = F_37 ( V_2 ) ;
else if ( F_21 ( V_129 ) )
V_21 = F_36 ( V_2 ) ;
else if ( ! F_39 ( V_2 ) )
V_21 = 0 ;
return V_21 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( V_2 -> V_125 != 0x1a ) {
F_18 ( V_138 , L_16 , V_2 -> V_54 ) ;
return;
}
if ( ! V_2 -> V_46 ) {
F_18 ( V_138 , L_17 , V_2 -> V_54 ) ;
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
static int F_42 ( struct V_1 * V_2 )
{
#if 0
return cdrom_flush_cache(cdi);
#else
return 0 ;
#endif
}
static void F_43 ( struct V_1 * V_2 , T_3 * V_139 )
{
struct V_140 V_141 ;
struct V_142 V_143 ;
int V_21 , V_144 ;
V_139 -> V_145 = 0 ;
V_139 -> V_146 = 0 ;
V_139 -> V_2 = 0 ;
V_139 -> V_147 = 0 ;
V_139 -> error = 0 ;
F_18 ( V_148 , L_19 ) ;
V_21 = V_2 -> V_16 -> V_149 ( V_2 , V_150 , & V_141 ) ;
if ( V_21 ) {
if ( V_21 == - V_151 )
V_139 -> error = V_152 ;
else
V_139 -> error = V_153 ;
return;
}
V_143 . V_154 = V_155 ;
for ( V_144 = V_141 . V_156 ; V_144 <= V_141 . V_157 ; V_144 ++ ) {
V_143 . V_158 = V_144 ;
if ( V_2 -> V_16 -> V_149 ( V_2 , V_159 , & V_143 ) ) {
V_139 -> error = V_153 ;
return;
}
if ( V_143 . V_160 & V_161 ) {
if ( V_143 . V_154 == 0x10 )
V_139 -> V_2 ++ ;
else if ( V_143 . V_154 == 0x20 )
V_139 -> V_147 ++ ;
else
V_139 -> V_145 ++ ;
} else {
V_139 -> V_146 ++ ;
}
F_18 ( V_148 , L_20 ,
V_144 , V_143 . V_154 , V_143 . V_160 ) ;
}
F_18 ( V_148 , L_21 ,
V_141 . V_157 , V_139 -> V_146 , V_139 -> V_145 ,
V_139 -> V_2 , V_139 -> V_147 ) ;
}
static
int F_44 ( struct V_1 * V_2 )
{
int V_21 ;
const struct V_19 * V_20 = V_2 -> V_16 ;
T_3 V_139 ;
F_18 ( V_59 , L_22 ) ;
if ( V_20 -> V_64 != NULL ) {
V_21 = V_20 -> V_64 ( V_2 , V_162 ) ;
F_18 ( V_59 , L_23 , V_21 ) ;
if ( V_21 == V_163 ) {
F_18 ( V_59 , L_24 ) ;
if ( F_21 ( V_71 ) &&
V_2 -> V_85 & V_88 ) {
F_18 ( V_59 , L_25 ) ;
V_21 = V_20 -> V_70 ( V_2 , 0 ) ;
if ( V_21 ) {
F_18 ( V_59 , L_26 ) ;
V_21 = - V_151 ;
goto V_164;
}
} else {
F_18 ( V_59 , L_27 ) ;
V_21 = - V_151 ;
goto V_164;
}
V_21 = V_20 -> V_64 ( V_2 , V_162 ) ;
if ( ( V_21 == V_152 ) || ( V_21 == V_163 ) ) {
F_18 ( V_59 , L_28 ) ;
F_18 ( V_59 , L_29 ) ;
V_21 = - V_151 ;
goto V_164;
}
F_18 ( V_59 , L_30 ) ;
}
V_21 = V_20 -> V_64 ( V_2 , V_162 ) ;
if ( V_21 != V_165 ) {
V_21 = - V_151 ;
goto V_164;
}
}
F_43 ( V_2 , & V_139 ) ;
if ( V_139 . error == V_152 ) {
F_18 ( V_59 , L_31 ) ;
V_21 = - V_151 ;
goto V_164;
}
if ( V_139 . V_145 == 0 ) {
if ( V_2 -> V_85 & V_94 ) {
F_18 ( V_59 , L_32 ) ;
F_18 ( V_166 , L_33 ,
( unsigned int ) F_45 ( V_167 ) ) ;
V_21 = - V_168 ;
goto V_164;
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
goto V_164;
}
if ( F_21 ( V_74 ) && ( V_2 -> V_85 & V_92 ) ) {
V_20 -> V_73 ( V_2 , 1 ) ;
F_18 ( V_59 , L_38 ) ;
}
F_18 ( V_59 , L_39 ) ;
return V_21 ;
V_164:
F_18 ( V_59 , L_40 ) ;
if ( F_21 ( V_74 ) && V_2 -> V_85 & V_92 ) {
V_20 -> V_73 ( V_2 , 0 ) ;
F_18 ( V_59 , L_41 ) ;
}
return V_21 ;
}
int F_46 ( struct V_1 * V_2 , struct V_169 * V_170 ,
T_4 V_171 )
{
int V_21 ;
F_18 ( V_59 , L_42 ) ;
F_47 ( V_170 ) ;
V_2 -> V_172 ++ ;
if ( ( V_171 & V_173 ) && ( V_2 -> V_85 & V_86 ) ) {
V_21 = V_2 -> V_16 -> V_60 ( V_2 , 1 ) ;
} else {
V_21 = F_44 ( V_2 ) ;
if ( V_21 )
goto V_174;
F_38 ( V_2 ) ;
if ( V_171 & V_175 ) {
V_21 = - V_176 ;
if ( F_40 ( V_2 ) )
goto V_177;
if ( ! F_21 ( V_132 ) )
goto V_177;
V_21 = 0 ;
V_2 -> V_46 = 0 ;
}
}
if ( V_21 )
goto V_174;
F_18 ( V_59 , L_43 ,
V_2 -> V_54 , V_2 -> V_172 ) ;
return 0 ;
V_177:
if ( F_21 ( V_74 ) && V_2 -> V_85 & V_92 ) {
V_2 -> V_16 -> V_73 ( V_2 , 0 ) ;
F_18 ( V_59 , L_41 ) ;
}
V_2 -> V_16 -> V_61 ( V_2 ) ;
V_174:
V_2 -> V_172 -- ;
return V_21 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
int V_21 ;
T_3 V_139 ;
F_18 ( V_59 , L_44 ) ;
if ( ! ( V_2 -> V_85 & V_94 ) )
return 0 ;
if ( V_20 -> V_64 != NULL ) {
V_21 = V_20 -> V_64 ( V_2 , V_162 ) ;
F_18 ( V_59 , L_23 , V_21 ) ;
if ( V_21 == V_163 ) {
F_18 ( V_59 , L_24 ) ;
if ( F_21 ( V_71 ) &&
V_2 -> V_85 & V_88 ) {
F_18 ( V_59 , L_25 ) ;
V_21 = V_20 -> V_70 ( V_2 , 0 ) ;
if ( V_21 ) {
F_18 ( V_59 , L_45 ) ;
return - V_151 ;
}
} else {
F_18 ( V_59 , L_46 ) ;
return - V_151 ;
}
V_21 = V_20 -> V_64 ( V_2 , V_162 ) ;
if ( ( V_21 == V_152 ) || ( V_21 == V_163 ) ) {
F_18 ( V_59 , L_28 ) ;
return - V_151 ;
}
if ( V_21 != V_165 ) {
F_18 ( V_59 , L_47 ) ;
return - V_10 ;
}
F_18 ( V_59 , L_30 ) ;
}
}
F_43 ( V_2 , & V_139 ) ;
if ( V_139 . error )
return ( V_139 . error ) ;
if ( V_139 . V_146 == 0 )
return - V_168 ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 , T_4 V_171 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
int V_178 ;
F_18 ( V_138 , L_48 ) ;
if ( V_2 -> V_172 > 0 )
V_2 -> V_172 -- ;
if ( V_2 -> V_172 == 0 ) {
F_18 ( V_138 , L_49 ,
V_2 -> V_54 ) ;
F_41 ( V_2 ) ;
if ( ( V_20 -> V_58 & V_74 ) && ! V_2 -> V_179 ) {
F_18 ( V_138 , L_50 ) ;
V_20 -> V_73 ( V_2 , 0 ) ;
}
}
V_178 = ! ( V_2 -> V_85 & V_86 ) ||
! ( V_171 & V_173 ) ;
if ( F_21 ( V_132 ) && ! V_2 -> V_172 && V_2 -> V_180 )
F_42 ( V_2 ) ;
V_20 -> V_61 ( V_2 ) ;
if ( V_2 -> V_172 == 0 ) {
if ( V_178 &&
V_2 -> V_85 & V_90 && F_21 ( V_72 ) )
V_20 -> V_70 ( V_2 , 1 ) ;
}
}
static int F_50 ( struct V_1 * V_2 ,
struct V_181 * V_182 )
{
struct V_3 V_4 ;
const struct V_19 * V_20 = V_2 -> V_16 ;
int V_183 ;
if ( V_2 -> V_184 ) {
V_182 -> V_185 . V_186 = 3 ;
V_182 -> V_185 . V_187 = V_2 -> V_184 == 3 ? 0 : V_2 -> V_184 ;
for ( V_183 = 0 ; V_183 < 3 ; V_183 ++ ) {
V_182 -> V_188 [ V_183 ] . V_189 = 1 ;
V_182 -> V_188 [ V_183 ] . V_190 = 0 ;
}
return 0 ;
}
V_183 = sizeof( struct V_191 ) +
V_2 -> V_192 * sizeof( struct V_193 ) ;
F_3 ( & V_4 , V_182 , V_183 , V_23 ) ;
V_4 . V_12 [ 0 ] = V_194 ;
V_4 . V_12 [ 8 ] = ( V_183 >> 8 ) & 0xff ;
V_4 . V_12 [ 9 ] = V_183 & 0xff ;
return V_20 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_51 ( struct V_1 * V_2 , int V_195 )
{
struct V_181 * V_196 ;
int V_21 ;
F_18 ( V_197 , L_51 ) ;
if ( V_2 -> V_184 )
return V_153 ;
V_196 = F_52 ( sizeof( * V_196 ) , V_198 ) ;
if ( ! V_196 )
return - V_199 ;
if ( ( V_21 = F_50 ( V_2 , V_196 ) ) )
goto V_200;
if ( V_196 -> V_188 [ V_195 ] . V_189 )
V_21 = V_165 ;
else
V_21 = V_152 ;
V_200:
F_53 ( V_196 ) ;
return V_21 ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_201 ;
int V_186 = 1 ;
struct V_181 * V_196 ;
F_18 ( V_197 , L_52 ) ;
V_2 -> V_192 = 0 ;
V_196 = F_52 ( sizeof( * V_196 ) , V_198 ) ;
if ( ! V_196 )
return - V_199 ;
if ( ( V_201 = F_50 ( V_2 , V_196 ) ) == 0 )
V_186 = V_196 -> V_185 . V_186 ;
F_53 ( V_196 ) ;
return V_186 ;
}
static int F_55 ( struct V_1 * V_2 , int V_195 )
{
struct V_3 V_4 ;
F_18 ( V_197 , L_53 ) ;
if ( V_2 -> V_184 && V_195 < 0 )
return 0 ;
F_3 ( & V_4 , NULL , 0 , V_11 ) ;
V_4 . V_12 [ 0 ] = V_202 ;
V_4 . V_12 [ 4 ] = 2 + ( V_195 >= 0 ) ;
V_4 . V_12 [ 8 ] = V_195 ;
V_4 . V_14 = 60 * V_15 ;
if ( V_2 -> V_184 && - 1 < V_195 ) {
V_4 . V_12 [ 0 ] = V_203 ;
V_4 . V_12 [ 7 ] = V_195 ;
V_4 . V_12 [ 4 ] = V_4 . V_12 [ 8 ] = 0 ;
V_2 -> V_184 = V_195 ? V_195 : 3 ;
}
return V_2 -> V_16 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_56 ( struct V_1 * V_2 , int V_195 )
{
struct V_181 * V_196 ;
int V_187 ;
int V_21 ;
F_18 ( V_197 , L_54 ) ;
if ( ! F_21 ( V_69 ) )
return - V_204 ;
if ( V_2 -> V_16 -> V_66 )
V_2 -> V_16 -> V_66 ( V_2 , 0 , V_195 ) ;
else
V_2 -> V_16 -> V_67 ( V_2 , V_195 ) ;
if ( V_195 == V_205 ) {
V_2 -> V_84 = 0x3 ;
return F_55 ( V_2 , - 1 ) ;
}
V_196 = F_52 ( sizeof( * V_196 ) , V_198 ) ;
if ( ! V_196 )
return - V_199 ;
if ( ( V_21 = F_50 ( V_2 , V_196 ) ) ) {
F_53 ( V_196 ) ;
return V_21 ;
}
V_187 = V_196 -> V_185 . V_187 ;
F_53 ( V_196 ) ;
if ( V_2 -> V_172 > 1 || V_2 -> V_179 ) {
if ( V_195 == V_162 ) {
return V_187 ;
} else {
return - V_206 ;
}
}
if ( V_195 == V_162 )
V_195 = V_187 ;
V_2 -> V_84 = 0x3 ;
if ( ( V_21 = F_55 ( V_2 , V_195 ) ) )
return V_21 ;
return V_195 ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_207 )
{
unsigned int V_208 ;
V_208 = V_2 -> V_16 -> V_66 ( V_2 , V_207 , V_162 ) ;
V_2 -> V_209 |= V_208 ;
V_2 -> V_210 |= V_208 ;
}
unsigned int F_58 ( struct V_1 * V_2 ,
unsigned int V_207 )
{
unsigned int V_208 ;
F_57 ( V_2 , V_207 ) ;
V_208 = V_2 -> V_209 ;
V_2 -> V_209 = 0 ;
return V_208 ;
}
static
int V_67 ( struct V_1 * V_2 , int V_211 )
{
unsigned int V_130 = ( 1 << ( V_211 & 1 ) ) ;
int V_21 = ! ! ( V_2 -> V_84 & V_130 ) ;
bool V_212 ;
if ( ! F_21 ( V_68 ) )
return V_21 ;
if ( V_2 -> V_16 -> V_66 ) {
F_59 ( ! V_211 ) ;
F_57 ( V_2 , V_213 ) ;
V_212 = V_2 -> V_210 & V_213 ;
V_2 -> V_210 = 0 ;
} else
V_212 = V_2 -> V_16 -> V_67 ( V_2 , V_162 ) ;
if ( V_212 ) {
V_2 -> V_84 = 0x3 ;
V_21 |= 1 ;
V_2 -> V_46 = 0 ;
}
V_2 -> V_84 &= ~ V_130 ;
return V_21 ;
}
int F_60 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_16 -> V_67 == NULL )
return 0 ;
if ( ! F_21 ( V_68 ) )
return 0 ;
return V_67 ( V_2 , 0 ) ;
}
static
void F_61 ( union V_214 * V_215 ,
T_5 * V_124 , T_5 V_216 )
{
if ( * V_124 == V_216 )
return;
if ( V_216 == V_217 ) {
V_215 -> V_218 = ( int ) V_215 -> V_219 . V_220 +
75 * ( V_215 -> V_219 . V_221 - 2 + 60 * V_215 -> V_219 . V_222 ) ;
} else {
int V_218 = V_215 -> V_218 ;
V_215 -> V_219 . V_220 = V_218 % 75 ;
V_218 /= 75 ;
V_218 += 2 ;
V_215 -> V_219 . V_221 = V_218 % 60 ;
V_215 -> V_219 . V_222 = V_218 / 60 ;
}
* V_124 = V_216 ;
}
void F_3 ( struct V_3 * V_4 , void * V_182 , int V_223 ,
int type )
{
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
if ( V_182 )
memset ( V_182 , 0 , V_223 ) ;
V_4 -> V_27 = ( char * ) V_182 ;
V_4 -> V_22 = V_223 ;
V_4 -> V_224 = type ;
V_4 -> V_14 = V_225 ;
}
static void F_62 ( struct V_3 * V_4 , unsigned V_226 , unsigned type )
{
V_4 -> V_12 [ 0 ] = V_227 ;
V_4 -> V_12 [ 10 ] = type | ( V_226 << 6 ) ;
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
V_4 -> V_224 = V_23 ;
}
static void F_63 ( struct V_3 * V_4 , unsigned V_226 , unsigned type )
{
V_4 -> V_12 [ 0 ] = V_228 ;
V_4 -> V_12 [ 10 ] = type | ( V_226 << 6 ) ;
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
V_4 -> V_224 = V_39 ;
}
static int F_64 ( struct V_1 * V_2 , T_6 * V_229 )
{
int V_21 ;
T_5 V_182 [ 20 ] ;
struct V_3 V_4 ;
const struct V_19 * V_20 = V_2 -> V_16 ;
T_7 V_230 ;
memset ( V_182 , 0 , sizeof( V_182 ) ) ;
F_3 ( & V_4 , V_182 , 0 , V_23 ) ;
switch ( V_229 -> type ) {
case V_231 :
F_18 ( V_232 , L_55 ) ;
V_4 . V_25 = 1 ;
F_62 ( & V_4 , V_229 -> V_233 . V_226 , 0 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_229 -> V_233 . V_226 = V_182 [ 7 ] >> 6 ;
break;
case V_234 :
F_18 ( V_232 , L_56 ) ;
F_62 ( & V_4 , V_229 -> V_235 . V_226 , 2 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
F_65 ( V_229 -> V_235 . V_236 , & V_182 [ 4 ] ) ;
break;
case V_237 :
F_18 ( V_232 , L_57 ) ;
F_62 ( & V_4 , V_229 -> V_238 . V_226 , 1 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
F_66 ( V_229 -> V_238 . V_239 , & V_182 [ 4 ] ) ;
break;
case V_240 :
F_18 ( V_232 , L_58 ) ;
V_4 . V_25 = 1 ;
F_62 ( & V_4 , V_229 -> V_241 . V_226 , 4 ) ;
V_4 . V_12 [ 5 ] = V_229 -> V_241 . V_218 ;
V_4 . V_12 [ 4 ] = V_229 -> V_241 . V_218 >> 8 ;
V_4 . V_12 [ 3 ] = V_229 -> V_241 . V_218 >> 16 ;
V_4 . V_12 [ 2 ] = V_229 -> V_241 . V_218 >> 24 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_229 -> V_241 . V_242 = ( V_182 [ 4 ] >> 7 ) & 1 ;
V_229 -> V_241 . V_243 = ( V_182 [ 4 ] >> 6 ) & 1 ;
V_229 -> V_241 . V_244 = ( V_182 [ 4 ] >> 4 ) & 3 ;
F_65 ( V_229 -> V_241 . V_245 , & V_182 [ 5 ] ) ;
break;
case V_246 :
F_18 ( V_232 , L_59 ) ;
F_62 ( & V_4 , V_229 -> V_247 . V_226 , 5 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_229 -> V_247 . V_248 = V_182 [ 7 ] & 1 ;
break;
case V_249 :
F_18 ( V_232 , L_60 ) ;
F_63 ( & V_4 , V_229 -> V_250 . V_226 , 1 ) ;
V_182 [ 1 ] = 0xe ;
F_66 ( & V_182 [ 4 ] , V_229 -> V_250 . V_239 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_229 -> type = V_234 ;
break;
case V_251 :
F_18 ( V_232 , L_61 ) ;
F_63 ( & V_4 , V_229 -> V_252 . V_226 , 3 ) ;
V_182 [ 1 ] = 0xa ;
F_65 ( & V_182 [ 4 ] , V_229 -> V_252 . V_236 ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) ) {
V_229 -> type = V_253 ;
return V_21 ;
}
V_229 -> type = V_254 ;
break;
case V_255 :
V_4 . V_25 = 1 ;
F_18 ( V_232 , L_62 ) ;
F_62 ( & V_4 , V_229 -> V_233 . V_226 , 0x3f ) ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
break;
case V_256 :
F_18 ( V_232 , L_63 ) ;
F_62 ( & V_4 , 0 , 8 ) ;
memset ( & V_230 , 0 , sizeof( T_7 ) ) ;
V_4 . V_27 = ( char * ) & V_230 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_229 -> V_257 . type = V_230 . V_258 ;
V_229 -> V_257 . V_259 = V_230 . V_259 ;
V_229 -> V_257 . V_260 = V_230 . V_260 ;
V_229 -> V_257 . V_261 = V_230 . V_261 ;
V_229 -> V_257 . V_262 = V_230 . V_262 ;
break;
case V_263 :
F_18 ( V_232 , L_64 ) ;
F_63 ( & V_4 , 0 , 6 ) ;
V_182 [ 1 ] = 6 ;
V_182 [ 4 ] = V_229 -> V_264 . V_265 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
break;
default:
F_18 ( V_166 , L_65 , V_229 -> type ) ;
return - V_266 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
unsigned char V_182 [ 21 ] , * V_268 ;
struct V_269 * V_270 ;
const struct V_19 * V_20 = V_2 -> V_16 ;
int V_21 , V_271 = V_267 -> V_272 . V_271 ;
if ( V_271 >= V_273 )
return - V_62 ;
F_3 ( V_4 , V_182 , sizeof( V_182 ) , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_274 ;
V_4 -> V_12 [ 6 ] = V_271 ;
V_4 -> V_12 [ 7 ] = V_267 -> type ;
V_4 -> V_12 [ 9 ] = V_4 -> V_22 & 0xff ;
V_4 -> V_25 = 1 ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
return V_21 ;
V_268 = & V_182 [ 4 ] ;
V_270 = & V_267 -> V_272 . V_270 [ V_271 ] ;
memset ( V_270 , 0 , sizeof( * V_270 ) ) ;
V_270 -> V_275 = V_268 [ 0 ] & 0xf ;
V_270 -> V_276 = V_268 [ 0 ] >> 4 ;
V_270 -> V_277 = V_268 [ 1 ] & 0xf ;
V_270 -> V_278 = V_268 [ 1 ] >> 4 ;
V_270 -> V_279 = V_268 [ 2 ] & 0xf ;
V_270 -> V_280 = ( V_268 [ 2 ] >> 4 ) & 1 ;
V_270 -> V_281 = ( V_268 [ 2 ] >> 5 ) & 3 ;
V_270 -> V_282 = V_268 [ 3 ] & 0xf ;
V_270 -> V_283 = V_268 [ 3 ] >> 4 ;
V_270 -> V_284 = V_268 [ 5 ] << 16 | V_268 [ 6 ] << 8 | V_268 [ 7 ] ;
V_270 -> V_285 = V_268 [ 9 ] << 16 | V_268 [ 10 ] << 8 | V_268 [ 11 ] ;
V_270 -> V_286 = V_268 [ 13 ] << 16 | V_268 [ 14 ] << 8 | V_268 [ 15 ] ;
V_270 -> V_287 = V_268 [ 16 ] >> 7 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_21 ;
T_5 V_182 [ 8 ] ;
const struct V_19 * V_20 = V_2 -> V_16 ;
F_3 ( V_4 , V_182 , sizeof( V_182 ) , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_274 ;
V_4 -> V_12 [ 6 ] = V_267 -> V_288 . V_271 ;
V_4 -> V_12 [ 7 ] = V_267 -> type ;
V_4 -> V_12 [ 8 ] = V_4 -> V_22 >> 8 ;
V_4 -> V_12 [ 9 ] = V_4 -> V_22 & 0xff ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
return V_21 ;
V_267 -> V_288 . V_289 = V_182 [ 4 ] ;
V_267 -> V_288 . V_290 = V_182 [ 5 ] ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_21 , V_51 ;
T_5 * V_182 ;
const struct V_19 * V_20 = V_2 -> V_16 ;
V_51 = sizeof( V_267 -> V_291 . V_292 ) + 4 ;
V_182 = F_52 ( V_51 , V_198 ) ;
if ( ! V_182 )
return - V_199 ;
F_3 ( V_4 , V_182 , V_51 , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_274 ;
V_4 -> V_12 [ 7 ] = V_267 -> type ;
V_4 -> V_12 [ 8 ] = V_51 >> 8 ;
V_4 -> V_12 [ 9 ] = V_51 & 0xff ;
V_4 -> V_12 [ 10 ] = V_267 -> V_291 . V_226 << 6 ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( ! V_21 )
memcpy ( V_267 -> V_291 . V_292 , & V_182 [ 4 ] , sizeof( V_267 -> V_291 . V_292 ) ) ;
F_53 ( V_182 ) ;
return V_21 ;
}
static int F_70 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_21 , V_51 = 4 + 188 ;
T_5 * V_182 ;
const struct V_19 * V_20 = V_2 -> V_16 ;
V_182 = F_52 ( V_51 , V_198 ) ;
if ( ! V_182 )
return - V_199 ;
F_3 ( V_4 , V_182 , V_51 , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_274 ;
V_4 -> V_12 [ 7 ] = V_267 -> type ;
V_4 -> V_12 [ 9 ] = V_4 -> V_22 & 0xff ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
goto V_293;
V_267 -> V_287 . V_223 = V_182 [ 0 ] << 8 | V_182 [ 1 ] ;
if ( V_267 -> V_287 . V_223 < 12 || V_267 -> V_287 . V_223 > 188 ) {
F_18 ( V_166 , L_66 ,
V_267 -> V_287 . V_223 ) ;
V_21 = - V_10 ;
goto V_293;
}
memcpy ( V_267 -> V_287 . V_292 , & V_182 [ 4 ] , V_267 -> V_287 . V_223 ) ;
V_21 = 0 ;
V_293:
F_53 ( V_182 ) ;
return V_21 ;
}
static int F_71 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_21 = 0 , V_51 ;
T_5 * V_182 ;
const struct V_19 * V_20 = V_2 -> V_16 ;
V_51 = sizeof( V_267 -> V_294 . V_292 ) + 4 ;
V_182 = F_52 ( V_51 , V_198 ) ;
if ( ! V_182 )
return - V_199 ;
F_3 ( V_4 , V_182 , V_51 , V_23 ) ;
V_4 -> V_12 [ 0 ] = V_274 ;
V_4 -> V_12 [ 7 ] = V_267 -> type ;
V_4 -> V_12 [ 8 ] = V_51 >> 8 ;
V_4 -> V_12 [ 9 ] = V_51 & 0xff ;
V_21 = V_20 -> V_17 ( V_2 , V_4 ) ;
if ( V_21 )
goto V_293;
V_267 -> V_294 . V_223 = V_182 [ 0 ] << 8 | V_182 [ 1 ] ;
if ( V_267 -> V_294 . V_223 < 0 ) {
F_18 ( V_166 , L_67 ,
V_267 -> V_294 . V_223 ) ;
V_21 = - V_10 ;
} else {
if ( V_267 -> V_294 . V_223 > 2048 ) {
F_18 ( V_166 , L_68 ,
V_267 -> V_294 . V_223 ) ;
V_267 -> V_294 . V_223 = 2048 ;
}
memcpy ( V_267 -> V_294 . V_292 , & V_182 [ 4 ] , V_267 -> V_294 . V_223 ) ;
}
V_293:
F_53 ( V_182 ) ;
return V_21 ;
}
static int F_72 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
switch ( V_267 -> type ) {
case V_295 :
return F_67 ( V_2 , V_267 , V_4 ) ;
case V_296 :
return F_68 ( V_2 , V_267 , V_4 ) ;
case V_297 :
return F_69 ( V_2 , V_267 , V_4 ) ;
case V_298 :
return F_70 ( V_2 , V_267 , V_4 ) ;
case V_299 :
return F_71 ( V_2 , V_267 , V_4 ) ;
default:
F_18 ( V_166 , L_69 ,
V_267 -> type ) ;
return - V_62 ;
}
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_300 , int V_301 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
memset ( V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_12 [ 0 ] = V_302 ;
V_4 -> V_12 [ 2 ] = V_300 | ( V_301 << 6 ) ;
V_4 -> V_12 [ 7 ] = V_4 -> V_22 >> 8 ;
V_4 -> V_12 [ 8 ] = V_4 -> V_22 & 0xff ;
V_4 -> V_224 = V_23 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
memset ( V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
memset ( V_4 -> V_27 , 0 , 2 ) ;
V_4 -> V_12 [ 0 ] = V_303 ;
V_4 -> V_12 [ 1 ] = 0x10 ;
V_4 -> V_12 [ 7 ] = V_4 -> V_22 >> 8 ;
V_4 -> V_12 [ 8 ] = V_4 -> V_22 & 0xff ;
V_4 -> V_224 = V_39 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_304 * V_305 , int V_306 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
struct V_3 V_4 ;
char V_27 [ 32 ] ;
int V_21 ;
F_3 ( & V_4 , V_27 , 16 , V_23 ) ;
V_4 . V_12 [ 0 ] = V_307 ;
V_4 . V_12 [ 1 ] = V_305 -> V_308 ;
V_4 . V_12 [ 2 ] = 0x40 ;
V_4 . V_12 [ 3 ] = V_306 ? 2 : 1 ;
V_4 . V_12 [ 8 ] = 16 ;
if ( ( V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ) )
return V_21 ;
V_305 -> V_309 = V_4 . V_27 [ 1 ] ;
V_305 -> V_310 = V_4 . V_27 [ 5 ] & 0xf ;
V_305 -> V_311 = V_4 . V_27 [ 6 ] ;
V_305 -> V_312 = V_4 . V_27 [ 7 ] ;
if ( V_305 -> V_308 == V_217 ) {
V_305 -> V_313 . V_218 = ( ( V_4 . V_27 [ 8 ] << 24 ) |
( V_4 . V_27 [ 9 ] << 16 ) |
( V_4 . V_27 [ 10 ] << 8 ) |
( V_4 . V_27 [ 11 ] ) ) ;
V_305 -> V_314 . V_218 = ( ( V_4 . V_27 [ 12 ] << 24 ) |
( V_4 . V_27 [ 13 ] << 16 ) |
( V_4 . V_27 [ 14 ] << 8 ) |
( V_4 . V_27 [ 15 ] ) ) ;
} else {
V_305 -> V_314 . V_219 . V_222 = V_4 . V_27 [ 13 ] ;
V_305 -> V_314 . V_219 . V_221 = V_4 . V_27 [ 14 ] ;
V_305 -> V_314 . V_219 . V_220 = V_4 . V_27 [ 15 ] ;
V_305 -> V_313 . V_219 . V_222 = V_4 . V_27 [ 9 ] ;
V_305 -> V_313 . V_219 . V_221 = V_4 . V_27 [ 10 ] ;
V_305 -> V_313 . V_219 . V_220 = V_4 . V_27 [ 11 ] ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_218 ,
int V_315 , int V_316 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
memset ( & V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_12 [ 0 ] = V_317 ;
V_4 -> V_12 [ 2 ] = ( V_218 >> 24 ) & 0xff ;
V_4 -> V_12 [ 3 ] = ( V_218 >> 16 ) & 0xff ;
V_4 -> V_12 [ 4 ] = ( V_218 >> 8 ) & 0xff ;
V_4 -> V_12 [ 5 ] = V_218 & 0xff ;
V_4 -> V_12 [ 6 ] = ( V_316 >> 16 ) & 0xff ;
V_4 -> V_12 [ 7 ] = ( V_316 >> 8 ) & 0xff ;
V_4 -> V_12 [ 8 ] = V_316 & 0xff ;
V_4 -> V_22 = V_315 * V_316 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_218 , int V_316 , int V_318 , int V_319 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
memset ( & V_4 -> V_12 , 0 , sizeof( V_4 -> V_12 ) ) ;
V_4 -> V_12 [ 0 ] = V_320 ;
V_4 -> V_12 [ 1 ] = V_318 << 2 ;
V_4 -> V_12 [ 2 ] = ( V_218 >> 24 ) & 0xff ;
V_4 -> V_12 [ 3 ] = ( V_218 >> 16 ) & 0xff ;
V_4 -> V_12 [ 4 ] = ( V_218 >> 8 ) & 0xff ;
V_4 -> V_12 [ 5 ] = V_218 & 0xff ;
V_4 -> V_12 [ 6 ] = ( V_316 >> 16 ) & 0xff ;
V_4 -> V_12 [ 7 ] = ( V_316 >> 8 ) & 0xff ;
V_4 -> V_12 [ 8 ] = V_316 & 0xff ;
V_4 -> V_22 = V_319 * V_316 ;
switch ( V_319 ) {
case V_321 : V_4 -> V_12 [ 9 ] = 0x58 ; break;
case V_322 : V_4 -> V_12 [ 9 ] = 0x78 ; break;
case V_323 : V_4 -> V_12 [ 9 ] = 0xf8 ; break;
default : V_4 -> V_12 [ 9 ] = 0x10 ;
}
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static int F_76 ( struct V_1 * V_2 , T_9 T_10 * V_324 ,
int V_218 , int V_325 )
{
struct V_3 V_4 ;
int V_21 = 0 ;
int V_326 ;
V_2 -> V_327 = 0 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_326 = V_325 ;
do {
V_4 . V_27 = F_52 ( V_323 * V_326 , V_198 ) ;
if ( V_4 . V_27 )
break;
V_326 >>= 1 ;
} while ( V_326 );
if ( ! V_326 )
return - V_199 ;
V_4 . V_224 = V_23 ;
while ( V_325 > 0 ) {
if ( V_326 > V_325 )
V_326 = V_325 ;
V_21 = F_75 ( V_2 , & V_4 , V_218 , V_326 , 1 , V_323 ) ;
if ( V_21 )
break;
if ( F_77 ( V_324 , V_4 . V_27 , V_323 * V_326 ) ) {
V_21 = - V_328 ;
break;
}
V_324 += V_323 * V_326 ;
V_325 -= V_326 ;
V_218 += V_326 ;
}
F_53 ( V_4 . V_27 ) ;
return V_21 ;
}
static int F_78 ( struct V_1 * V_2 , T_9 T_10 * V_324 ,
int V_218 , int V_325 )
{
struct V_329 * V_330 = V_2 -> V_96 -> V_211 ;
struct V_331 * V_332 ;
struct V_333 * V_334 ;
struct V_335 * V_335 ;
unsigned int V_223 ;
int V_326 , V_21 = 0 ;
if ( ! V_330 )
return - V_336 ;
if ( ! F_79 ( V_330 ) ) {
F_80 ( true ,
L_70 ) ;
return - V_62 ;
}
V_2 -> V_327 = 0 ;
while ( V_325 ) {
V_326 = V_325 ;
if ( V_2 -> V_97 == V_337 )
V_326 = 1 ;
if ( V_326 * V_323 > ( F_81 ( V_330 ) << 9 ) )
V_326 = ( F_81 ( V_330 ) << 9 ) / V_323 ;
V_223 = V_326 * V_323 ;
V_332 = F_82 ( V_330 , V_338 , V_198 ) ;
if ( F_83 ( V_332 ) ) {
V_21 = F_84 ( V_332 ) ;
break;
}
V_334 = F_85 ( V_332 ) ;
V_21 = F_86 ( V_330 , V_332 , NULL , V_324 , V_223 , V_198 ) ;
if ( V_21 ) {
F_87 ( V_332 ) ;
break;
}
V_334 -> V_12 [ 0 ] = V_320 ;
V_334 -> V_12 [ 1 ] = 1 << 2 ;
V_334 -> V_12 [ 2 ] = ( V_218 >> 24 ) & 0xff ;
V_334 -> V_12 [ 3 ] = ( V_218 >> 16 ) & 0xff ;
V_334 -> V_12 [ 4 ] = ( V_218 >> 8 ) & 0xff ;
V_334 -> V_12 [ 5 ] = V_218 & 0xff ;
V_334 -> V_12 [ 6 ] = ( V_326 >> 16 ) & 0xff ;
V_334 -> V_12 [ 7 ] = ( V_326 >> 8 ) & 0xff ;
V_334 -> V_12 [ 8 ] = V_326 & 0xff ;
V_334 -> V_12 [ 9 ] = 0xf8 ;
V_334 -> V_339 = 12 ;
V_332 -> V_14 = 60 * V_15 ;
V_335 = V_332 -> V_335 ;
F_88 ( V_330 , V_2 -> V_96 , V_332 , 0 ) ;
if ( F_85 ( V_332 ) -> V_340 ) {
struct V_341 * V_267 = V_334 -> V_5 ;
V_21 = - V_10 ;
V_2 -> V_327 = V_267 -> V_6 ;
}
if ( F_89 ( V_335 ) )
V_21 = - V_328 ;
F_87 ( V_332 ) ;
if ( V_21 )
break;
V_325 -= V_326 ;
V_218 += V_326 ;
V_324 += V_223 ;
}
return V_21 ;
}
static int F_90 ( struct V_1 * V_2 , T_9 T_10 * V_324 ,
int V_218 , int V_325 )
{
int V_21 ;
if ( V_2 -> V_97 == V_99 )
return F_76 ( V_2 , V_324 , V_218 , V_325 ) ;
V_342:
V_21 = F_78 ( V_2 , V_324 , V_218 , V_325 ) ;
if ( ! V_21 || V_21 != - V_10 )
return V_21 ;
if ( V_2 -> V_97 == V_98 && V_325 > 1 ) {
F_10 ( L_71 ) ;
V_2 -> V_97 = V_337 ;
goto V_342;
}
if ( V_2 -> V_327 != 0x04 && V_2 -> V_327 != 0x0b )
return V_21 ;
F_10 ( L_72 , V_2 -> V_327 ) ;
V_2 -> V_97 = V_99 ;
return F_76 ( V_2 , V_324 , V_218 , V_325 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_344 V_345 ;
T_11 V_346 ;
int V_21 ;
F_18 ( V_347 , L_73 ) ;
if ( ! ( V_2 -> V_16 -> V_58 & V_78 ) )
return - V_348 ;
if ( F_92 ( & V_345 , V_343 , sizeof( V_345 ) ) )
return - V_328 ;
V_346 = V_345 . V_349 ;
if ( V_346 != V_155 && V_346 != V_217 )
return - V_62 ;
V_345 . V_349 = V_217 ;
V_21 = V_2 -> V_16 -> V_77 ( V_2 , & V_345 ) ;
if ( V_21 )
return V_21 ;
F_61 ( & V_345 . V_215 , & V_345 . V_349 , V_346 ) ;
if ( F_77 ( V_343 , & V_345 , sizeof( V_345 ) ) )
return - V_328 ;
F_18 ( V_347 , L_74 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
F_18 ( V_347 , L_75 ) ;
if ( ! F_21 ( V_72 ) )
return - V_348 ;
if ( V_2 -> V_172 != 1 || V_2 -> V_179 )
return - V_206 ;
if ( F_21 ( V_74 ) ) {
int V_21 = V_2 -> V_16 -> V_73 ( V_2 , 0 ) ;
if ( V_21 )
return V_21 ;
}
return V_2 -> V_16 -> V_70 ( V_2 , 1 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
F_18 ( V_347 , L_76 ) ;
if ( ! F_21 ( V_71 ) )
return - V_348 ;
return V_2 -> V_16 -> V_70 ( V_2 , 0 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_77 ) ;
if ( ! F_21 ( V_72 ) )
return - V_348 ;
if ( V_2 -> V_179 )
return - V_206 ;
V_2 -> V_85 &= ~ ( V_88 | V_90 ) ;
if ( V_350 )
V_2 -> V_85 |= V_88 | V_90 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
struct V_181 * V_196 ;
int V_21 ;
F_18 ( V_347 , L_78 ) ;
if ( ! F_21 ( V_68 ) )
return - V_348 ;
if ( ! F_21 ( V_69 ) || V_350 == V_162 )
return V_67 ( V_2 , 1 ) ;
if ( ( unsigned int ) V_350 >= V_2 -> V_192 )
return - V_62 ;
V_196 = F_52 ( sizeof( * V_196 ) , V_198 ) ;
if ( ! V_196 )
return - V_199 ;
V_21 = F_50 ( V_2 , V_196 ) ;
if ( ! V_21 )
V_21 = V_196 -> V_188 [ V_350 ] . V_190 ;
F_53 ( V_196 ) ;
return V_21 ;
}
static int F_97 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_79 ) ;
switch ( V_350 ) {
case V_86 :
case V_94 :
break;
case V_92 :
if ( ! F_21 ( V_74 ) )
return - V_348 ;
break;
case 0 :
return V_2 -> V_85 ;
default:
if ( ! F_21 ( V_350 ) )
return - V_348 ;
}
V_2 -> V_85 |= ( int ) V_350 ;
return V_2 -> V_85 ;
}
static int F_98 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_80 ) ;
V_2 -> V_85 &= ~ ( int ) V_350 ;
return V_2 -> V_85 ;
}
static int F_99 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_81 ) ;
if ( ! F_21 ( V_76 ) )
return - V_348 ;
return V_2 -> V_16 -> V_75 ( V_2 , V_350 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_82 ) ;
if ( ! F_21 ( V_69 ) )
return - V_348 ;
if ( V_350 != V_162 && V_350 != V_205 ) {
if ( ( int ) V_350 >= V_2 -> V_192 )
return - V_62 ;
}
if ( V_2 -> V_16 -> V_351 )
return V_2 -> V_16 -> V_351 ( V_2 , V_350 ) ;
F_18 ( V_197 , L_83 ) ;
return F_56 ( V_2 , V_350 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
F_18 ( V_347 , L_84 ) ;
if ( ! F_102 ( V_352 ) )
return - V_353 ;
if ( ! F_21 ( V_82 ) )
return - V_348 ;
F_103 ( V_170 ) ;
return V_2 -> V_16 -> V_81 ( V_2 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_85 , V_350 ? L_86 : L_87 ) ;
if ( ! F_21 ( V_74 ) )
return - V_204 ;
V_2 -> V_179 = V_350 ? 1 : 0 ;
if ( V_2 -> V_172 != 1 && ! V_350 && ! F_102 ( V_352 ) )
return - V_206 ;
return V_2 -> V_16 -> V_73 ( V_2 , V_350 ) ;
}
static int F_105 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_88 , V_350 ? L_89 : L_90 ) ;
if ( ! F_102 ( V_352 ) )
return - V_353 ;
V_354 = V_350 ? 1 : 0 ;
return V_354 ;
}
static int F_106 ( struct V_1 * V_2 )
{
F_18 ( V_347 , L_91 ) ;
return ( V_2 -> V_16 -> V_58 & ~ V_2 -> V_130 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_355 V_306 ;
int V_21 ;
F_18 ( V_347 , L_92 ) ;
if ( ! ( V_2 -> V_16 -> V_58 & V_80 ) )
return - V_348 ;
V_21 = V_2 -> V_16 -> V_79 ( V_2 , & V_306 ) ;
if ( V_21 )
return V_21 ;
if ( F_77 ( V_343 , & V_306 , sizeof( V_306 ) ) )
return - V_328 ;
F_18 ( V_347 , L_93 ) ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
unsigned long V_350 )
{
F_18 ( V_347 , L_94 ) ;
if ( ! ( V_2 -> V_16 -> V_58 & V_65 ) )
return - V_348 ;
if ( ! F_21 ( V_69 ) ||
( V_350 == V_162 || V_350 == V_205 ) )
return V_2 -> V_16 -> V_64 ( V_2 , V_162 ) ;
if ( ( ( int ) V_350 >= V_2 -> V_192 ) )
return - V_62 ;
return F_51 ( V_2 , V_350 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
T_3 V_139 ;
F_18 ( V_347 , L_95 ) ;
F_43 ( V_2 , & V_139 ) ;
if ( V_139 . error )
return V_139 . error ;
if ( V_139 . V_146 > 0 ) {
if ( ! V_139 . V_145 && ! V_139 . V_2 && ! V_139 . V_147 )
return V_356 ;
else
return V_357 ;
}
if ( V_139 . V_2 > 0 )
return V_358 ;
if ( V_139 . V_147 > 0 )
return V_359 ;
if ( V_139 . V_145 > 0 )
return V_360 ;
F_18 ( V_166 , L_96 ) ;
return V_153 ;
}
static int F_110 ( struct V_1 * V_2 )
{
F_18 ( V_347 , L_97 ) ;
return V_2 -> V_192 ;
}
static int F_111 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_304 V_330 ;
T_11 V_216 , V_361 ;
int V_21 ;
if ( F_92 ( & V_330 , V_343 , sizeof( V_330 ) ) )
return - V_328 ;
V_216 = V_330 . V_308 ;
if ( V_216 != V_155 && V_216 != V_217 )
return - V_62 ;
V_330 . V_308 = V_155 ;
V_21 = V_2 -> V_16 -> V_149 ( V_2 , V_362 , & V_330 ) ;
if ( V_21 )
return V_21 ;
V_361 = V_330 . V_308 ;
F_61 ( & V_330 . V_313 , & V_361 , V_216 ) ;
F_61 ( & V_330 . V_314 , & V_330 . V_308 , V_216 ) ;
if ( F_77 ( V_343 , & V_330 , sizeof( V_330 ) ) )
return - V_328 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_140 V_141 ;
int V_21 ;
if ( F_92 ( & V_141 , V_343 , sizeof( V_141 ) ) )
return - V_328 ;
V_21 = V_2 -> V_16 -> V_149 ( V_2 , V_150 , & V_141 ) ;
if ( V_21 )
return V_21 ;
if ( F_77 ( V_343 , & V_141 , sizeof( V_141 ) ) )
return - V_328 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_142 V_143 ;
T_11 V_346 ;
int V_21 ;
if ( F_92 ( & V_143 , V_343 , sizeof( V_143 ) ) )
return - V_328 ;
V_346 = V_143 . V_154 ;
if ( V_346 != V_155 && V_346 != V_217 )
return - V_62 ;
V_143 . V_154 = V_155 ;
V_21 = V_2 -> V_16 -> V_149 ( V_2 , V_159 , & V_143 ) ;
if ( V_21 )
return V_21 ;
F_61 ( & V_143 . V_363 , & V_143 . V_154 , V_346 ) ;
if ( F_77 ( V_343 , & V_143 , sizeof( V_143 ) ) )
return - V_328 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_364 V_219 ;
F_18 ( V_347 , L_98 ) ;
if ( ! F_21 ( V_365 ) )
return - V_348 ;
if ( F_92 ( & V_219 , V_343 , sizeof( V_219 ) ) )
return - V_328 ;
return V_2 -> V_16 -> V_149 ( V_2 , V_366 , & V_219 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_367 V_368 ;
int V_21 ;
F_18 ( V_347 , L_99 ) ;
if ( ! F_21 ( V_365 ) )
return - V_348 ;
if ( F_92 ( & V_368 , V_343 , sizeof( V_368 ) ) )
return - V_328 ;
V_21 = F_48 ( V_2 , V_2 -> V_16 ) ;
if ( V_21 )
return V_21 ;
return V_2 -> V_16 -> V_149 ( V_2 , V_369 , & V_368 ) ;
}
static int F_116 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_370 V_371 ;
F_18 ( V_347 , L_100 ) ;
if ( ! F_21 ( V_365 ) )
return - V_348 ;
if ( F_92 ( & V_371 , V_343 , sizeof( V_371 ) ) )
return - V_328 ;
return V_2 -> V_16 -> V_149 ( V_2 , V_372 , & V_371 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
void T_10 * V_343 )
{
struct V_370 V_371 ;
int V_21 ;
F_18 ( V_347 , L_101 ) ;
if ( ! F_21 ( V_365 ) )
return - V_348 ;
V_21 = V_2 -> V_16 -> V_149 ( V_2 , V_373 , & V_371 ) ;
if ( V_21 )
return V_21 ;
if ( F_77 ( V_343 , & V_371 , sizeof( V_371 ) ) )
return - V_328 ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
int V_21 ;
F_18 ( V_347 , L_102 ) ;
if ( ! F_21 ( V_365 ) )
return - V_348 ;
V_21 = F_48 ( V_2 , V_2 -> V_16 ) ;
if ( V_21 )
return V_21 ;
return V_2 -> V_16 -> V_149 ( V_2 , V_12 , NULL ) ;
}
static int F_119 ( struct V_1 * V_2 , int V_51 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
struct V_3 V_4 ;
struct V_374 V_375 ;
memset ( & V_375 , 0 , sizeof( V_375 ) ) ;
V_375 . V_376 = 0x08 ;
V_375 . V_377 = ( V_51 >> 8 ) & 0xff ;
V_375 . V_378 = V_51 & 0xff ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_12 [ 0 ] = 0x15 ;
V_4 . V_12 [ 1 ] = 1 << 4 ;
V_4 . V_12 [ 4 ] = 12 ;
V_4 . V_22 = sizeof( V_375 ) ;
V_4 . V_27 = ( char * ) & V_375 ;
V_4 . V_224 = V_39 ;
V_375 . V_376 = 0x08 ;
V_375 . V_377 = ( V_51 >> 8 ) & 0xff ;
V_375 . V_378 = V_51 & 0xff ;
return V_20 -> V_17 ( V_2 , & V_4 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
T_12 V_379 , T_9 type , T_13 * V_368 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
struct V_3 V_4 ;
int V_21 , V_22 ;
F_3 ( & V_4 , V_368 , 8 , V_23 ) ;
V_4 . V_12 [ 0 ] = V_380 ;
V_4 . V_12 [ 1 ] = type & 3 ;
V_4 . V_12 [ 4 ] = ( V_379 & 0xff00 ) >> 8 ;
V_4 . V_12 [ 5 ] = V_379 & 0xff ;
V_4 . V_12 [ 8 ] = 8 ;
V_4 . V_25 = 1 ;
V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ;
if ( V_21 )
return V_21 ;
V_22 = F_5 ( V_368 -> V_381 ) +
sizeof( V_368 -> V_381 ) ;
if ( V_22 > sizeof( T_13 ) )
V_22 = sizeof( T_13 ) ;
V_4 . V_12 [ 8 ] = V_4 . V_22 = V_22 ;
V_21 = V_20 -> V_17 ( V_2 , & V_4 ) ;
if ( V_21 )
return V_21 ;
return V_22 ;
}
int F_121 ( struct V_1 * V_2 , long * V_382 )
{
struct V_142 V_383 ;
T_1 V_18 ;
T_13 V_368 ;
T_14 V_384 ;
int V_21 = - 1 , V_385 ;
if ( ! F_21 ( V_83 ) )
goto V_386;
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < ( int ) ( F_13 ( F_14 ( V_18 ) , V_387 )
+ sizeof( V_18 . V_387 ) ) )
goto V_386;
V_384 = ( V_18 . V_388 << 8 ) | V_18 . V_387 ;
V_385 = F_120 ( V_2 , V_384 , 1 , & V_368 ) ;
if ( V_385 < ( int ) F_13 ( F_14 ( V_368 ) , V_389 ) )
goto V_386;
if ( V_368 . V_390 ) {
if ( V_384 == 1 )
goto V_386;
V_384 -- ;
V_385 = F_120 ( V_2 , V_384 , 1 , & V_368 ) ;
}
if ( V_385 < ( int ) ( F_13 ( F_14 ( V_368 ) , V_391 )
+ sizeof( V_368 . V_391 ) ) )
goto V_386;
if ( V_368 . V_392 && V_385 >= ( int ) ( F_13 ( F_14 ( V_368 ) , V_393 )
+ sizeof( V_368 . V_393 ) ) ) {
* V_382 = F_122 ( V_368 . V_393 ) ;
} else {
* V_382 = F_122 ( V_368 . V_389 ) +
F_122 ( V_368 . V_391 ) ;
if ( V_368 . V_394 )
* V_382 -= ( F_122 ( V_368 . V_394 ) + 7 ) ;
}
return 0 ;
V_386:
V_383 . V_154 = V_155 ;
V_383 . V_158 = V_395 ;
if ( ( V_21 = V_2 -> V_16 -> V_149 ( V_2 , V_159 , & V_383 ) ) )
return V_21 ;
F_61 ( & V_383 . V_363 , & V_383 . V_154 , V_217 ) ;
* V_382 = V_383 . V_363 . V_218 ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
long * V_396 )
{
T_1 V_18 ;
T_13 V_368 ;
T_12 V_384 ;
int V_21 , V_385 ;
if ( ! F_21 ( V_83 ) )
goto V_397;
V_21 = F_4 ( V_2 , & V_18 ) ;
if ( V_21 < 0 || V_21 < F_13 ( F_14 ( V_18 ) , V_387 )
+ sizeof( V_18 . V_387 ) )
goto V_397;
V_384 = ( V_18 . V_388 << 8 ) | V_18 . V_387 ;
V_385 = F_120 ( V_2 , V_384 , 1 , & V_368 ) ;
if ( V_385 < 0 || V_385 < F_13 ( F_14 ( V_368 ) , V_389 ) )
goto V_397;
if ( V_368 . V_390 ) {
if ( V_384 == 1 )
goto V_397;
V_384 -- ;
V_385 = F_120 ( V_2 , V_384 , 1 , & V_368 ) ;
if ( V_385 < 0 )
goto V_397;
}
if ( V_368 . V_398 && V_385 >= F_13 ( F_14 ( V_368 ) , V_396 )
+ sizeof( V_368 . V_396 ) ) {
* V_396 = F_122 ( V_368 . V_396 ) ;
return 0 ;
}
V_397:
V_21 = F_121 ( V_2 , V_396 ) ;
if ( V_21 ) {
* V_396 = 0 ;
return V_21 ;
} else {
* V_396 += 7 ;
return 0 ;
}
}
static T_15 int F_124 ( struct V_1 * V_2 ,
void T_10 * V_350 ,
struct V_3 * V_4 ,
int V_12 )
{
struct V_341 V_5 ;
struct V_364 V_219 ;
int V_315 = 0 , V_318 = 0 , V_218 ;
int V_21 ;
switch ( V_12 ) {
case V_399 :
V_315 = V_323 ;
break;
case V_400 :
V_315 = V_401 ;
V_318 = 2 ;
break;
case V_402 :
V_315 = V_321 ;
break;
}
if ( F_92 ( & V_219 , (struct V_364 T_10 * ) V_350 , sizeof( V_219 ) ) )
return - V_328 ;
V_218 = F_125 ( V_219 . V_403 , V_219 . V_404 , V_219 . V_405 ) ;
if ( V_218 < 0 )
return - V_62 ;
V_4 -> V_27 = F_126 ( V_315 , V_198 ) ;
if ( V_4 -> V_27 == NULL )
return - V_199 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_4 -> V_5 = & V_5 ;
V_4 -> V_224 = V_23 ;
V_21 = F_75 ( V_2 , V_4 , V_218 , 1 , V_318 , V_315 ) ;
if ( V_21 && V_5 . V_6 == 0x05 &&
V_5 . V_7 == 0x20 &&
V_5 . V_8 == 0x00 ) {
V_21 = F_119 ( V_2 , V_315 ) ;
if ( V_21 )
goto V_293;
V_4 -> V_5 = NULL ;
V_21 = F_74 ( V_2 , V_4 , V_218 , V_315 , 1 ) ;
V_21 |= F_119 ( V_2 , V_315 ) ;
}
if ( ! V_21 && F_77 ( V_350 , V_4 -> V_27 , V_315 ) )
V_21 = - V_328 ;
V_293:
F_53 ( V_4 -> V_27 ) ;
return V_21 ;
}
static T_15 int F_127 ( struct V_1 * V_2 ,
void T_10 * V_350 )
{
struct V_406 V_407 ;
int V_218 ;
if ( F_92 ( & V_407 , (struct V_406 T_10 * ) V_350 ,
sizeof( V_407 ) ) )
return - V_328 ;
if ( V_407 . V_349 == V_155 )
V_218 = F_125 ( V_407 . V_215 . V_219 . V_222 ,
V_407 . V_215 . V_219 . V_221 ,
V_407 . V_215 . V_219 . V_220 ) ;
else if ( V_407 . V_349 == V_217 )
V_218 = V_407 . V_215 . V_218 ;
else
return - V_62 ;
if ( V_218 < 0 || V_407 . V_325 <= 0 || V_407 . V_325 > V_408 )
return - V_62 ;
return F_90 ( V_2 , V_407 . V_182 , V_218 , V_407 . V_325 ) ;
}
static T_15 int F_128 ( struct V_1 * V_2 ,
void T_10 * V_350 )
{
int V_21 ;
struct V_304 V_330 ;
T_5 V_216 , V_361 ;
if ( F_92 ( & V_330 , (struct V_304 T_10 * ) V_350 , sizeof( V_330 ) ) )
return - V_328 ;
V_216 = V_330 . V_308 ;
if ( ! ( ( V_216 == V_155 ) ||
( V_216 == V_217 ) ) )
return - V_62 ;
V_21 = F_73 ( V_2 , & V_330 , 0 ) ;
if ( V_21 )
return V_21 ;
V_361 = V_330 . V_308 ;
F_61 ( & V_330 . V_313 , & V_361 , V_216 ) ;
F_61 ( & V_330 . V_314 , & V_330 . V_308 , V_216 ) ;
if ( F_77 ( (struct V_304 T_10 * ) V_350 , & V_330 , sizeof( V_330 ) ) )
return - V_328 ;
return 0 ;
}
static T_15 int F_129 ( struct V_1 * V_2 ,
void T_10 * V_350 ,
struct V_3 * V_4 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
struct V_364 V_219 ;
F_18 ( V_347 , L_98 ) ;
if ( F_92 ( & V_219 , (struct V_364 T_10 * ) V_350 , sizeof( V_219 ) ) )
return - V_328 ;
V_4 -> V_12 [ 0 ] = V_409 ;
V_4 -> V_12 [ 3 ] = V_219 . V_403 ;
V_4 -> V_12 [ 4 ] = V_219 . V_404 ;
V_4 -> V_12 [ 5 ] = V_219 . V_405 ;
V_4 -> V_12 [ 6 ] = V_219 . V_410 ;
V_4 -> V_12 [ 7 ] = V_219 . V_411 ;
V_4 -> V_12 [ 8 ] = V_219 . V_412 ;
V_4 -> V_224 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_130 ( struct V_1 * V_2 ,
void T_10 * V_350 ,
struct V_3 * V_4 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
struct V_413 V_414 ;
F_18 ( V_347 , L_103 ) ;
if ( F_92 ( & V_414 , (struct V_413 T_10 * ) V_350 , sizeof( V_414 ) ) )
return - V_328 ;
V_4 -> V_12 [ 0 ] = V_415 ;
V_4 -> V_12 [ 2 ] = ( V_414 . V_416 >> 24 ) & 0xff ;
V_4 -> V_12 [ 3 ] = ( V_414 . V_416 >> 16 ) & 0xff ;
V_4 -> V_12 [ 4 ] = ( V_414 . V_416 >> 8 ) & 0xff ;
V_4 -> V_12 [ 5 ] = V_414 . V_416 & 0xff ;
V_4 -> V_12 [ 7 ] = ( V_414 . V_223 >> 8 ) & 0xff ;
V_4 -> V_12 [ 8 ] = V_414 . V_223 & 0xff ;
V_4 -> V_224 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_131 ( struct V_1 * V_2 ,
void T_10 * V_350 ,
struct V_3 * V_4 ,
unsigned int V_12 )
{
struct V_370 V_417 ;
unsigned char V_27 [ 32 ] ;
char V_130 [ sizeof( V_27 ) ] ;
unsigned short V_50 ;
int V_21 ;
F_18 ( V_347 , L_104 ) ;
if ( F_92 ( & V_417 , (struct V_370 T_10 * ) V_350 ,
sizeof( V_417 ) ) )
return - V_328 ;
V_4 -> V_27 = V_27 ;
V_4 -> V_22 = 24 ;
V_21 = F_7 ( V_2 , V_4 , V_418 , 0 ) ;
if ( V_21 )
return V_21 ;
V_50 = 8 + F_5 ( * ( T_2 * ) ( V_27 + 6 ) ) ;
if ( V_50 + 16 > sizeof( V_27 ) )
return - V_419 ;
if ( V_50 + 16 > V_4 -> V_22 ) {
V_4 -> V_22 = V_50 + 16 ;
V_21 = F_7 ( V_2 , V_4 ,
V_418 , 0 ) ;
if ( V_21 )
return V_21 ;
}
if ( ( V_27 [ V_50 ] & 0x3f ) != V_418 ||
V_27 [ V_50 + 1 ] < 14 )
return - V_62 ;
if ( V_12 == V_373 ) {
V_417 . V_420 = V_27 [ V_50 + 9 ] ;
V_417 . V_421 = V_27 [ V_50 + 11 ] ;
V_417 . V_422 = V_27 [ V_50 + 13 ] ;
V_417 . V_423 = V_27 [ V_50 + 15 ] ;
if ( F_77 ( (struct V_370 T_10 * ) V_350 , & V_417 ,
sizeof( V_417 ) ) )
return - V_328 ;
return 0 ;
}
V_4 -> V_27 = V_130 ;
V_21 = F_7 ( V_2 , V_4 , V_418 , 1 ) ;
if ( V_21 )
return V_21 ;
V_27 [ V_50 + 9 ] = V_417 . V_420 & V_130 [ V_50 + 9 ] ;
V_27 [ V_50 + 11 ] = V_417 . V_421 & V_130 [ V_50 + 11 ] ;
V_27 [ V_50 + 13 ] = V_417 . V_422 & V_130 [ V_50 + 13 ] ;
V_27 [ V_50 + 15 ] = V_417 . V_423 & V_130 [ V_50 + 15 ] ;
V_4 -> V_27 = V_27 + V_50 - 8 ;
memset ( V_4 -> V_27 , 0 , 8 ) ;
return F_16 ( V_2 , V_4 ) ;
}
static T_15 int F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
F_18 ( V_347 , L_105 ) ;
V_4 -> V_12 [ 0 ] = V_424 ;
V_4 -> V_12 [ 1 ] = 1 ;
V_4 -> V_12 [ 4 ] = ( V_12 == V_425 ) ? 1 : 0 ;
V_4 -> V_224 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_133 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_12 )
{
const struct V_19 * V_20 = V_2 -> V_16 ;
F_18 ( V_347 , L_106 ) ;
V_4 -> V_12 [ 0 ] = V_426 ;
V_4 -> V_12 [ 8 ] = ( V_12 == V_427 ) ? 1 : 0 ;
V_4 -> V_224 = V_11 ;
return V_20 -> V_17 ( V_2 , V_4 ) ;
}
static T_15 int F_134 ( struct V_1 * V_2 ,
void T_10 * V_350 ,
struct V_3 * V_4 )
{
int V_21 ;
T_8 * V_267 ;
int V_51 = sizeof( T_8 ) ;
if ( ! F_21 ( V_136 ) )
return - V_348 ;
V_267 = F_135 ( V_350 , V_51 ) ;
if ( F_83 ( V_267 ) )
return F_84 ( V_267 ) ;
F_18 ( V_347 , L_107 ) ;
V_21 = F_72 ( V_2 , V_267 , V_4 ) ;
if ( V_21 )
goto V_293;
if ( F_77 ( V_350 , V_267 , V_51 ) )
V_21 = - V_328 ;
V_293:
F_53 ( V_267 ) ;
return V_21 ;
}
static T_15 int F_136 ( struct V_1 * V_2 ,
void T_10 * V_350 )
{
int V_21 ;
T_6 V_229 ;
if ( ! F_21 ( V_136 ) )
return - V_348 ;
F_18 ( V_347 , L_108 ) ;
if ( F_92 ( & V_229 , ( T_6 T_10 * ) V_350 , sizeof( V_229 ) ) )
return - V_328 ;
V_21 = F_64 ( V_2 , & V_229 ) ;
if ( V_21 )
return V_21 ;
if ( F_77 ( ( T_6 T_10 * ) V_350 , & V_229 , sizeof( V_229 ) ) )
return - V_328 ;
return 0 ;
}
static T_15 int F_137 ( struct V_1 * V_2 ,
void T_10 * V_350 )
{
int V_21 ;
long V_428 = 0 ;
F_18 ( V_347 , L_109 ) ;
V_21 = F_123 ( V_2 , & V_428 ) ;
if ( V_21 )
return V_21 ;
if ( F_77 ( ( long T_10 * ) V_350 , & V_428 , sizeof( V_428 ) ) )
return - V_328 ;
return 0 ;
}
static T_15 int F_138 ( struct V_1 * V_2 ,
void T_10 * V_350 )
{
int V_21 ;
long V_429 = 0 ;
F_18 ( V_347 , L_110 ) ;
V_21 = F_121 ( V_2 , & V_429 ) ;
if ( V_21 )
return V_21 ;
if ( F_77 ( ( long T_10 * ) V_350 , & V_429 , sizeof( V_429 ) ) )
return - V_328 ;
return 0 ;
}
static int F_139 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned long V_350 )
{
struct V_3 V_4 ;
void T_10 * V_430 = ( void T_10 * ) V_350 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
switch ( V_12 ) {
case V_399 :
case V_400 :
case V_402 :
return F_124 ( V_2 , V_430 , & V_4 , V_12 ) ;
case V_431 :
return F_127 ( V_2 , V_430 ) ;
case V_362 :
return F_128 ( V_2 , V_430 ) ;
case V_366 :
return F_129 ( V_2 , V_430 , & V_4 ) ;
case V_432 :
return F_130 ( V_2 , V_430 , & V_4 ) ;
case V_372 :
case V_373 :
return F_131 ( V_2 , V_430 , & V_4 , V_12 ) ;
case V_425 :
case V_433 :
return F_132 ( V_2 , & V_4 , V_12 ) ;
case V_434 :
case V_427 :
return F_133 ( V_2 , & V_4 , V_12 ) ;
case V_435 :
return F_134 ( V_2 , V_430 , & V_4 ) ;
case V_436 :
return F_136 ( V_2 , V_430 ) ;
case V_437 :
return F_137 ( V_2 , V_430 ) ;
case V_438 :
return F_138 ( V_2 , V_430 ) ;
}
return - V_266 ;
}
int F_140 ( struct V_1 * V_2 , struct V_169 * V_170 ,
T_4 V_171 , unsigned int V_12 , unsigned long V_350 )
{
void T_10 * V_343 = ( void T_10 * ) V_350 ;
int V_21 ;
V_21 = F_141 ( V_170 , V_171 , V_12 , V_343 ) ;
if ( V_21 != - V_266 )
return V_21 ;
switch ( V_12 ) {
case V_439 :
return F_91 ( V_2 , V_343 ) ;
case V_440 :
return F_93 ( V_2 ) ;
case V_441 :
return F_94 ( V_2 ) ;
case V_442 :
return F_95 ( V_2 , V_350 ) ;
case V_443 :
return F_96 ( V_2 , V_350 ) ;
case V_444 :
return F_97 ( V_2 , V_350 ) ;
case V_445 :
return F_98 ( V_2 , V_350 ) ;
case V_446 :
return F_99 ( V_2 , V_350 ) ;
case V_447 :
return F_100 ( V_2 , V_350 ) ;
case V_448 :
return F_101 ( V_2 , V_170 ) ;
case V_449 :
return F_104 ( V_2 , V_350 ) ;
case V_450 :
return F_105 ( V_2 , V_350 ) ;
case V_451 :
return F_106 ( V_2 ) ;
case V_452 :
return F_107 ( V_2 , V_343 ) ;
case V_453 :
return F_108 ( V_2 , V_350 ) ;
case V_454 :
return F_109 ( V_2 ) ;
case V_455 :
return F_110 ( V_2 ) ;
}
if ( F_21 ( V_83 ) ) {
V_21 = F_139 ( V_2 , V_12 , V_350 ) ;
if ( V_21 != - V_266 )
return V_21 ;
}
switch ( V_12 ) {
case V_362 :
return F_111 ( V_2 , V_343 ) ;
case V_150 :
return F_112 ( V_2 , V_343 ) ;
case V_159 :
return F_113 ( V_2 , V_343 ) ;
case V_366 :
return F_114 ( V_2 , V_343 ) ;
case V_369 :
return F_115 ( V_2 , V_343 ) ;
case V_372 :
return F_116 ( V_2 , V_343 ) ;
case V_373 :
return F_117 ( V_2 , V_343 ) ;
case V_425 :
case V_433 :
case V_434 :
case V_427 :
return F_118 ( V_2 , V_12 ) ;
}
return - V_348 ;
}
static int F_142 ( const char * V_141 , int V_456 , char * V_196 ,
int * V_457 , enum V_458 V_459 )
{
const int V_460 = sizeof( V_461 . V_196 ) ;
struct V_1 * V_2 ;
int V_21 ;
V_21 = F_143 ( V_196 + * V_457 , V_460 - * V_457 , V_141 ) ;
if ( ! V_21 )
return 1 ;
* V_457 += V_21 ;
F_144 (cdi, &cdrom_list, list) {
switch ( V_459 ) {
case V_462 :
V_21 = F_143 ( V_196 + * V_457 , V_460 - * V_457 ,
L_111 , V_2 -> V_54 ) ;
break;
case V_463 :
V_21 = F_143 ( V_196 + * V_457 , V_460 - * V_457 ,
L_112 , V_2 -> V_464 ) ;
break;
case V_465 :
V_21 = F_143 ( V_196 + * V_457 , V_460 - * V_457 ,
L_112 , V_2 -> V_192 ) ;
break;
case V_466 :
V_21 = F_143 ( V_196 + * V_457 , V_460 - * V_457 ,
L_112 , F_21 ( V_456 ) != 0 ) ;
break;
default:
F_10 ( L_113 , V_459 ) ;
return 1 ;
}
if ( ! V_21 )
return 1 ;
* V_457 += V_21 ;
}
return 0 ;
}
static int F_145 ( struct V_467 * V_468 , int V_31 ,
void T_10 * V_27 , T_16 * V_469 , T_17 * V_470 )
{
int V_457 ;
char * V_196 = V_461 . V_196 ;
const int V_460 = sizeof( V_461 . V_196 ) ;
if ( ! * V_469 || ( * V_470 && ! V_31 ) ) {
* V_469 = 0 ;
return 0 ;
}
F_23 ( & V_101 ) ;
V_457 = sprintf ( V_196 , L_114 V_471 L_9 ) ;
if ( F_142 ( L_115 , 0 , V_196 , & V_457 , V_462 ) )
goto V_472;
if ( F_142 ( L_116 , 0 , V_196 , & V_457 , V_463 ) )
goto V_472;
if ( F_142 ( L_117 , 0 , V_196 , & V_457 , V_465 ) )
goto V_472;
if ( F_142 ( L_118 ,
V_71 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_119 ,
V_72 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_120 ,
V_74 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_121 ,
V_76 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_122 ,
V_69 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_123 ,
V_78 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_124 ,
V_80 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_125 ,
V_68 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_126 ,
V_365 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_127 ,
V_134 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_128 ,
V_135 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_129 ,
V_136 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_130 ,
V_137 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_131 ,
V_133 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_132 ,
V_131 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_133 ,
V_95 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( F_142 ( L_134 ,
V_132 , V_196 , & V_457 , V_466 ) )
goto V_472;
if ( ! F_143 ( V_196 + V_457 , V_460 - V_457 , L_135 ) )
goto V_472;
V_473:
F_25 ( & V_101 ) ;
return F_146 ( V_468 , V_31 , V_27 , V_469 , V_470 ) ;
V_472:
F_10 ( L_136 ) ;
goto V_473;
}
static void F_147 ( void )
{
struct V_1 * V_2 ;
F_23 ( & V_101 ) ;
F_144 (cdi, &cdrom_list, list) {
if ( V_87 && F_21 ( V_71 ) )
V_2 -> V_85 |= V_88 ;
else if ( ! V_87 )
V_2 -> V_85 &= ~ V_88 ;
if ( V_89 && F_21 ( V_72 ) )
V_2 -> V_85 |= V_90 ;
else if ( ! V_89 )
V_2 -> V_85 &= ~ V_90 ;
if ( V_91 && F_21 ( V_74 ) )
V_2 -> V_85 |= V_92 ;
else if ( ! V_91 )
V_2 -> V_85 &= ~ V_92 ;
if ( V_93 )
V_2 -> V_85 |= V_94 ;
else
V_2 -> V_85 &= ~ V_94 ;
}
F_25 ( & V_101 ) ;
}
static int F_148 ( struct V_467 * V_468 , int V_31 ,
void T_10 * V_27 , T_16 * V_469 , T_17 * V_470 )
{
int V_21 ;
V_21 = F_149 ( V_468 , V_31 , V_27 , V_469 , V_470 ) ;
if ( V_31 ) {
V_87 = ! ! V_461 . V_87 ;
V_89 = ! ! V_461 . V_89 ;
V_354 = ! ! V_461 . V_354 ;
V_91 = ! ! V_461 . V_474 ;
V_93 = ! ! V_461 . V_475 ;
F_147 () ;
}
return V_21 ;
}
static void F_19 ( void )
{
static int V_476 ;
if ( V_476 == 1 )
return;
V_477 = F_150 ( V_478 ) ;
V_461 . V_87 = V_87 ;
V_461 . V_89 = V_89 ;
V_461 . V_354 = V_354 ;
V_461 . V_474 = V_91 ;
V_461 . V_475 = V_93 ;
V_476 = 1 ;
}
static void F_151 ( void )
{
if ( V_477 )
F_152 ( V_477 ) ;
}
static void F_19 ( void )
{
}
static void F_151 ( void )
{
}
static int T_18 F_153 ( void )
{
F_19 () ;
return 0 ;
}
static void T_19 F_154 ( void )
{
F_10 ( L_137 ) ;
F_151 () ;
}
