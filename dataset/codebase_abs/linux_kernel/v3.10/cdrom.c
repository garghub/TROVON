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
int F_2 ( struct V_1 * V_2 )
{
static char V_11 ;
struct V_12 * V_13 = V_2 -> V_14 ;
int * V_15 = ( int * ) & V_13 -> V_16 ;
F_3 ( V_17 , L_1 ) ;
if ( V_13 -> V_18 == NULL || V_13 -> V_19 == NULL )
return - V_20 ;
if ( ! V_11 ) {
F_4 ( L_2 V_21 L_3 ) ;
V_11 = 1 ;
F_5 () ;
}
F_6 ( V_22 , V_23 ) ;
if ( V_13 -> V_24 == NULL && V_13 -> V_25 == NULL )
* V_15 = ~ ( V_26 | V_27 ) ;
F_6 ( V_28 , V_29 | V_30 ) ;
F_6 ( V_31 , V_32 ) ;
F_6 ( V_33 , V_34 ) ;
F_6 ( V_35 , V_36 ) ;
F_6 ( V_37 , V_38 ) ;
F_6 ( V_39 , V_40 ) ;
F_6 ( V_41 , V_42 ) ;
V_2 -> V_43 = 0 ;
V_13 -> V_44 = 0 ;
V_2 -> V_45 = V_46 ;
if ( V_47 == 1 && F_7 ( V_29 ) )
V_2 -> V_45 |= ( int ) V_48 ;
if ( V_49 == 1 && F_7 ( V_30 ) )
V_2 -> V_45 |= ( int ) V_50 ;
if ( V_51 == 1 )
V_2 -> V_45 |= ( int ) V_52 ;
if ( V_53 == 1 )
V_2 -> V_45 |= ( int ) V_54 ;
if ( F_7 ( V_55 ) )
V_2 -> exit = V_56 ;
if ( V_2 -> V_57 )
V_2 -> V_58 = V_59 ;
else
V_2 -> V_58 = V_60 ;
if ( ! V_13 -> V_41 )
V_13 -> V_41 = F_1 ;
F_3 ( V_61 , L_4 , V_2 -> V_62 ) ;
F_8 ( & V_63 ) ;
F_9 ( & V_2 -> V_64 , & V_65 ) ;
F_10 ( & V_63 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_3 ( V_17 , L_5 ) ;
F_8 ( & V_63 ) ;
F_12 ( & V_2 -> V_64 ) ;
F_10 ( & V_63 ) ;
if ( V_2 -> exit )
V_2 -> exit ( V_2 ) ;
V_2 -> V_14 -> V_44 -- ;
F_3 ( V_61 , L_6 , V_2 -> V_62 ) ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_3 V_4 ;
unsigned char V_68 [ 8 ] ;
struct V_69 * V_70 = (struct V_69 * ) V_68 ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_71 ) ;
V_4 . V_72 [ 0 ] = V_73 ;
V_4 . V_72 [ 1 ] = 1 ;
V_4 . V_72 [ 4 ] = 1 << 4 ;
V_4 . V_72 [ 8 ] = sizeof( V_68 ) ;
V_4 . V_74 = 1 ;
if ( V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) )
return 1 ;
if ( F_15 ( V_70 -> V_75 ) < sizeof( * V_67 ) )
return 1 ;
if ( V_70 -> V_76 || V_70 -> V_77 != 0x4 )
return 1 ;
memcpy ( V_67 , & V_68 [ sizeof( * V_70 ) ] , sizeof( * V_67 ) ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_68 [ 16 ] ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_71 ) ;
V_4 . V_78 = V_79 ;
V_4 . V_74 = 1 ;
if ( ! F_17 ( V_2 , & V_4 , V_80 , 0 ) ) {
V_2 -> V_81 = V_80 ;
return 0 ;
} else if ( ! F_17 ( V_2 , & V_4 , V_82 , 0 ) ) {
V_2 -> V_81 = V_82 ;
return 0 ;
}
return 1 ;
}
static int F_18 ( struct V_1 * V_2 , int * V_83 )
{
struct V_3 V_4 ;
struct V_84 * V_85 ;
unsigned char V_68 [ 16 ] ;
int V_86 ;
* V_83 = 0 ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_71 ) ;
V_4 . V_72 [ 0 ] = V_87 ;
V_4 . V_72 [ 3 ] = V_88 ;
V_4 . V_72 [ 8 ] = sizeof( V_68 ) ;
V_4 . V_74 = 1 ;
if ( ( V_86 = V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_85 = (struct V_84 * ) & V_68 [ sizeof( struct V_89 ) ] ;
if ( F_15 ( V_85 -> V_90 ) != V_88 )
return 1 ;
* V_83 = V_85 -> V_83 ;
if ( ( V_86 = F_16 ( V_2 ) ) ) {
* V_83 = 0 ;
return V_86 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_91 )
{
struct V_3 V_4 ;
unsigned char V_68 [ 12 ] ;
int V_86 ;
F_4 ( L_7 , V_91 ? L_8 : L_9 ) ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_92 ) ;
V_4 . V_72 [ 0 ] = V_93 ;
V_4 . V_72 [ 1 ] = ( 1 << 4 ) | 1 ;
V_4 . V_78 = 5 * 60 * V_79 ;
V_68 [ 1 ] = 1 << 1 ;
V_68 [ 3 ] = 8 ;
V_68 [ 4 ] = 0xff ;
V_68 [ 5 ] = 0xff ;
V_68 [ 6 ] = 0xff ;
V_68 [ 7 ] = 0xff ;
V_68 [ 8 ] = 0x24 << 2 ;
V_68 [ 11 ] = V_91 ;
V_86 = V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ;
if ( V_86 )
F_4 ( L_10 ) ;
return V_86 ;
}
static int F_20 ( struct V_1 * V_2 , int V_94 )
{
struct V_3 V_4 ;
F_14 ( & V_4 , NULL , 0 , V_95 ) ;
V_4 . V_72 [ 0 ] = V_96 ;
V_4 . V_72 [ 1 ] = ! ! V_94 ;
V_4 . V_72 [ 2 ] = 1 << 1 ;
V_4 . V_78 = 5 * 60 * V_79 ;
return V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_14 ( & V_4 , NULL , 0 , V_95 ) ;
V_4 . V_72 [ 0 ] = V_97 ;
V_4 . V_78 = 5 * 60 * V_79 ;
return V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ;
}
static int V_56 ( struct V_1 * V_2 )
{
T_1 V_98 ;
int V_86 ;
V_86 = F_22 ( V_2 , & V_98 ) ;
if ( V_86 < 0 || V_86 < ( int ) F_23 ( F_24 ( V_98 ) , V_99 ) )
return 1 ;
V_86 = 0 ;
if ( V_98 . V_100 == V_101 ) {
F_4 ( L_11 ) ;
V_86 = F_20 ( V_2 , 0 ) ;
}
if ( ! V_86 && V_2 -> V_102 )
V_86 = F_21 ( V_2 ) ;
return V_86 ;
}
static int F_25 ( struct V_1 * V_2 , int V_103 )
{
struct V_3 V_4 ;
struct V_104 * V_105 ;
char V_68 [ 16 ] ;
int V_86 , V_106 , V_107 ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_71 ) ;
V_4 . V_68 = V_68 ;
V_4 . V_108 = sizeof( V_68 ) ;
if ( ( V_86 = F_17 ( V_2 , & V_4 , V_2 -> V_81 , 0 ) ) )
return V_86 ;
V_105 = (struct V_104 * ) V_68 ;
V_106 = F_15 ( V_105 -> V_109 ) ;
V_107 = F_15 ( V_105 -> V_110 ) + 2 ;
V_68 [ V_106 + 3 ] = V_103 ;
V_4 . V_108 = V_107 ;
if ( ( V_86 = F_26 ( V_2 , & V_4 ) ) )
return V_86 ;
F_4 ( L_12 ,
V_2 -> V_62 , V_111 [ V_103 ] ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_112 * V_113 )
{
struct V_3 V_4 ;
char V_68 [ 24 ] ;
int V_86 ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_71 ) ;
V_4 . V_72 [ 0 ] = V_87 ;
V_4 . V_72 [ 3 ] = V_114 ;
V_4 . V_72 [ 8 ] = sizeof( V_68 ) ;
V_4 . V_74 = 1 ;
if ( ( V_86 = V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
memcpy ( V_113 , & V_68 [ sizeof( struct V_89 ) ] , sizeof ( * V_113 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_68 [ 16 ] ;
T_2 * V_90 ;
int V_86 ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_71 ) ;
V_4 . V_72 [ 0 ] = V_87 ;
V_4 . V_72 [ 3 ] = V_115 ;
V_4 . V_72 [ 8 ] = sizeof( V_68 ) ;
V_4 . V_74 = 1 ;
if ( ( V_86 = V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_90 = ( T_2 * ) & V_68 [ sizeof( struct V_89 ) ] ;
if ( F_15 ( * V_90 ) == V_115 )
return 0 ;
return 1 ;
}
static int F_29 ( struct V_1 * V_2 , int * V_83 )
{
struct V_112 V_113 ;
int V_86 ;
* V_83 = 0 ;
if ( ( V_86 = F_27 ( V_2 , & V_113 ) ) )
return V_86 ;
if ( V_114 == F_15 ( V_113 . V_90 ) )
* V_83 = 1 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_98 ;
int V_86 ;
V_86 = F_22 ( V_2 , & V_98 ) ;
if ( V_86 < 0 || V_86 < F_23 ( F_24 ( V_98 ) , V_116 ) )
return - 1 ;
return V_98 . V_117 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_86 = F_30 ( V_2 ) ;
if ( ! V_86 )
return 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 V_98 ;
int V_86 ;
if ( F_25 ( V_2 , V_118 ) ) {
F_33 ( L_13 ) ;
return 1 ;
}
V_86 = F_22 ( V_2 , & V_98 ) ;
if ( V_86 < 0 || V_86 < F_23 ( F_24 ( V_98 ) , V_99 ) )
return 1 ;
if ( ! V_98 . V_117 )
return 1 ;
V_86 = 0 ;
F_4 ( L_14 , V_119 [ V_98 . V_100 ] ) ;
if ( ! V_98 . V_100 )
V_86 = 1 ;
else if ( V_98 . V_100 == V_120 &&
V_121 )
V_86 = F_19 ( V_2 , 1 ) ;
return V_86 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_68 [ 255 ] ;
int V_86 ;
F_14 ( & V_4 , & V_68 , 4 , V_71 ) ;
V_4 . V_74 = 1 ;
V_86 = F_17 ( V_2 , & V_4 , V_122 , 0 ) ;
if ( V_86 )
V_86 = F_17 ( V_2 , & V_4 , V_123 , 0 ) ;
if ( V_86 ) {
V_4 . V_108 = 255 ;
V_86 = F_17 ( V_2 , & V_4 , V_122 , 0 ) ;
}
if ( V_86 )
return 0 ;
return V_68 [ 3 ] & 0x80 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_112 V_113 ;
int V_86 ;
if ( ( V_86 = F_28 ( V_2 ) ) )
return V_86 ;
if ( ( V_86 = F_27 ( V_2 , & V_113 ) ) )
return V_86 ;
else if ( V_114 == F_15 ( V_113 . V_90 ) )
V_86 = ! V_113 . V_124 ;
F_3 ( V_17 , L_15 ) ;
return V_86 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
char V_68 [ 32 ] ;
int V_86 , V_125 ;
F_14 ( & V_4 , V_68 , sizeof( V_68 ) , V_71 ) ;
V_4 . V_72 [ 0 ] = V_87 ;
V_4 . V_72 [ 1 ] = 0 ;
V_4 . V_72 [ 2 ] = V_4 . V_72 [ 3 ] = 0 ;
V_4 . V_72 [ 8 ] = sizeof( V_68 ) ;
V_4 . V_74 = 1 ;
if ( ( V_86 = V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ) )
V_125 = 0xffff ;
else
V_125 = ( V_68 [ 6 ] << 8 ) | V_68 [ 7 ] ;
V_2 -> V_125 = V_125 ;
}
static int F_37 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_125 ) {
case 0x12 :
case 0x1A :
return 0 ;
default:
return 1 ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
int V_126 , V_127 , V_128 ;
int V_86 = 1 ;
V_126 = 0 ;
if ( ! F_18 ( V_2 , & V_127 ) )
V_126 = 1 ;
if ( F_7 ( V_129 ) )
V_128 = 1 ;
else
( void ) F_29 ( V_2 , & V_128 ) ;
if ( V_126 )
V_2 -> V_130 &= ~ V_131 ;
else
V_2 -> V_130 |= V_131 ;
if ( V_127 )
V_2 -> V_130 &= ~ V_55 ;
else
V_2 -> V_130 |= V_55 ;
if ( V_128 )
V_2 -> V_130 &= ~ V_132 ;
else
V_2 -> V_130 |= V_132 ;
if ( F_7 ( V_55 ) )
V_86 = F_32 ( V_2 ) ;
else if ( F_7 ( V_133 ) )
V_86 = F_31 ( V_2 ) ;
else if ( F_7 ( V_132 ) &&
! F_7 ( V_134 | V_135 | V_136 | V_137 | V_131 | V_129 ) )
V_86 = F_35 ( V_2 ) ;
else if ( F_7 ( V_129 ) )
V_86 = F_34 ( V_2 ) ;
else if ( ! F_37 ( V_2 ) )
V_86 = 0 ;
return V_86 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( V_2 -> V_125 != 0x1a ) {
F_3 ( V_138 , L_16 , V_2 -> V_62 ) ;
return;
}
if ( ! V_2 -> V_102 ) {
F_3 ( V_138 , L_17 , V_2 -> V_62 ) ;
return;
}
F_4 ( L_18 , V_2 -> V_62 ) ;
F_14 ( & V_4 , NULL , 0 , V_95 ) ;
V_4 . V_72 [ 0 ] = V_97 ;
V_4 . V_78 = 30 * V_79 ;
V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ;
F_14 ( & V_4 , NULL , 0 , V_95 ) ;
V_4 . V_72 [ 0 ] = V_96 ;
V_4 . V_78 = 3000 * V_79 ;
V_4 . V_74 = 1 ;
V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ;
F_14 ( & V_4 , NULL , 0 , V_95 ) ;
V_4 . V_72 [ 0 ] = V_96 ;
V_4 . V_72 [ 2 ] = 2 ;
V_4 . V_74 = 1 ;
V_4 . V_78 = 3000 * V_79 ;
V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ;
V_2 -> V_102 = 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
#if 0
return cdrom_flush_cache(cdi);
#else
return 0 ;
#endif
}
int F_41 ( struct V_1 * V_2 , struct V_139 * V_140 , T_3 V_141 )
{
int V_86 ;
F_3 ( V_17 , L_19 ) ;
F_42 ( V_140 ) ;
V_2 -> V_142 ++ ;
if ( ( V_141 & V_143 ) && ( V_2 -> V_45 & V_46 ) ) {
V_86 = V_2 -> V_14 -> V_18 ( V_2 , 1 ) ;
} else {
V_86 = F_43 ( V_2 ) ;
if ( V_86 )
goto V_144;
F_36 ( V_2 ) ;
if ( V_141 & V_145 ) {
V_86 = - V_146 ;
if ( F_38 ( V_2 ) )
goto V_147;
if ( ! F_7 ( V_132 ) )
goto V_147;
V_86 = 0 ;
V_2 -> V_102 = 0 ;
}
}
if ( V_86 )
goto V_144;
F_3 ( V_17 , L_20 ,
V_2 -> V_62 , V_2 -> V_142 ) ;
return 0 ;
V_147:
if ( F_7 ( V_32 ) && V_2 -> V_45 & V_52 ) {
V_2 -> V_14 -> V_31 ( V_2 , 0 ) ;
F_3 ( V_17 , L_21 ) ;
}
V_2 -> V_14 -> V_19 ( V_2 ) ;
V_144:
V_2 -> V_142 -- ;
return V_86 ;
}
static
int F_43 ( struct V_1 * V_2 )
{
int V_86 ;
struct V_12 * V_13 = V_2 -> V_14 ;
T_4 V_148 ;
F_3 ( V_17 , L_22 ) ;
if ( V_13 -> V_22 != NULL ) {
V_86 = V_13 -> V_22 ( V_2 , V_149 ) ;
F_3 ( V_17 , L_23 , V_86 ) ;
if ( V_86 == V_150 ) {
F_3 ( V_17 , L_24 ) ;
if ( F_7 ( V_29 ) &&
V_2 -> V_45 & V_48 ) {
F_3 ( V_17 , L_25 ) ;
V_86 = V_13 -> V_28 ( V_2 , 0 ) ;
if ( V_86 ) {
F_3 ( V_17 , L_26 ) ;
V_86 = - V_151 ;
goto V_152;
}
} else {
F_3 ( V_17 , L_27 ) ;
V_86 = - V_151 ;
goto V_152;
}
V_86 = V_13 -> V_22 ( V_2 , V_149 ) ;
if ( ( V_86 == V_153 ) || ( V_86 == V_150 ) ) {
F_3 ( V_17 , L_28 ) ;
F_3 ( V_17 , L_29 ) ;
V_86 = - V_151 ;
goto V_152;
}
F_3 ( V_17 , L_30 ) ;
}
V_86 = V_13 -> V_22 ( V_2 , V_149 ) ;
if ( V_86 != V_154 ) {
V_86 = - V_151 ;
goto V_152;
}
}
F_44 ( V_2 , & V_148 ) ;
if ( V_148 . error == V_153 ) {
F_3 ( V_17 , L_31 ) ;
V_86 = - V_151 ;
goto V_152;
}
if ( V_148 . V_155 == 0 ) {
if ( V_2 -> V_45 & V_54 ) {
F_3 ( V_17 , L_32 ) ;
F_3 ( V_156 , L_33 ,
( unsigned int ) F_45 ( V_157 ) ) ;
V_86 = - V_158 ;
goto V_152;
}
else {
F_3 ( V_17 , L_34 ) ;
}
}
F_3 ( V_17 , L_35 ) ;
V_86 = V_13 -> V_18 ( V_2 , 0 ) ;
F_3 ( V_17 , L_36 , V_86 ) ;
if ( V_86 ) {
F_3 ( V_17 , L_37 ) ;
goto V_152;
}
if ( F_7 ( V_32 ) && ( V_2 -> V_45 & V_52 ) ) {
V_13 -> V_31 ( V_2 , 1 ) ;
F_3 ( V_17 , L_38 ) ;
}
F_3 ( V_17 , L_39 ) ;
return V_86 ;
V_152:
F_3 ( V_17 , L_40 ) ;
if ( F_7 ( V_32 ) && V_2 -> V_45 & V_52 ) {
V_13 -> V_31 ( V_2 , 0 ) ;
F_3 ( V_17 , L_21 ) ;
}
return V_86 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_86 ;
T_4 V_148 ;
F_3 ( V_17 , L_41 ) ;
if ( ! ( V_2 -> V_45 & V_54 ) )
return 0 ;
if ( V_13 -> V_22 != NULL ) {
V_86 = V_13 -> V_22 ( V_2 , V_149 ) ;
F_3 ( V_17 , L_23 , V_86 ) ;
if ( V_86 == V_150 ) {
F_3 ( V_17 , L_24 ) ;
if ( F_7 ( V_29 ) &&
V_2 -> V_45 & V_48 ) {
F_3 ( V_17 , L_25 ) ;
V_86 = V_13 -> V_28 ( V_2 , 0 ) ;
if ( V_86 ) {
F_3 ( V_17 , L_42 ) ;
return - V_151 ;
}
} else {
F_3 ( V_17 , L_43 ) ;
return - V_151 ;
}
V_86 = V_13 -> V_22 ( V_2 , V_149 ) ;
if ( ( V_86 == V_153 ) || ( V_86 == V_150 ) ) {
F_3 ( V_17 , L_28 ) ;
return - V_151 ;
}
if ( V_86 != V_154 ) {
F_3 ( V_17 , L_44 ) ;
return - V_10 ;
}
F_3 ( V_17 , L_30 ) ;
}
}
F_44 ( V_2 , & V_148 ) ;
if ( V_148 . error )
return ( V_148 . error ) ;
if ( V_148 . V_159 == 0 )
return - V_158 ;
return 0 ;
}
void F_47 ( struct V_1 * V_2 , T_3 V_141 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_160 ;
F_3 ( V_138 , L_45 ) ;
if ( V_2 -> V_142 > 0 )
V_2 -> V_142 -- ;
if ( V_2 -> V_142 == 0 ) {
F_3 ( V_138 , L_46 , V_2 -> V_62 ) ;
F_39 ( V_2 ) ;
if ( ( V_13 -> V_16 & V_32 ) && ! V_2 -> V_161 ) {
F_3 ( V_138 , L_47 ) ;
V_13 -> V_31 ( V_2 , 0 ) ;
}
}
V_160 = ! ( V_2 -> V_45 & V_46 ) ||
! ( V_141 & V_143 ) ;
if ( F_7 ( V_132 ) && ! V_2 -> V_142 && V_2 -> V_162 )
F_40 ( V_2 ) ;
V_13 -> V_19 ( V_2 ) ;
if ( V_2 -> V_142 == 0 ) {
if ( V_160 &&
V_2 -> V_45 & V_50 && F_7 ( V_30 ) )
V_13 -> V_28 ( V_2 , 1 ) ;
}
}
static int F_48 ( struct V_1 * V_2 ,
struct V_163 * V_164 )
{
struct V_3 V_4 ;
struct V_12 * V_13 = V_2 -> V_14 ;
int V_165 ;
if ( V_2 -> V_166 ) {
V_164 -> V_167 . V_168 = 3 ;
V_164 -> V_167 . V_169 = V_2 -> V_166 == 3 ? 0 : V_2 -> V_166 ;
for ( V_165 = 0 ; V_165 < 3 ; V_165 ++ ) {
V_164 -> V_170 [ V_165 ] . V_171 = 1 ;
V_164 -> V_170 [ V_165 ] . V_172 = 0 ;
}
return 0 ;
}
V_165 = sizeof( struct V_173 ) +
V_2 -> V_174 * sizeof( struct V_175 ) ;
F_14 ( & V_4 , V_164 , V_165 , V_71 ) ;
V_4 . V_72 [ 0 ] = V_176 ;
V_4 . V_72 [ 8 ] = ( V_165 >> 8 ) & 0xff ;
V_4 . V_72 [ 9 ] = V_165 & 0xff ;
return V_13 -> V_41 ( V_2 , & V_4 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_177 )
{
struct V_163 * V_178 ;
int V_86 ;
F_3 ( V_179 , L_48 ) ;
if ( V_2 -> V_166 )
return V_180 ;
V_178 = F_50 ( sizeof( * V_178 ) , V_181 ) ;
if ( ! V_178 )
return - V_182 ;
if ( ( V_86 = F_48 ( V_2 , V_178 ) ) )
goto V_183;
if ( V_178 -> V_170 [ V_177 ] . V_171 )
V_86 = V_154 ;
else
V_86 = V_153 ;
V_183:
F_51 ( V_178 ) ;
return V_86 ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_184 ;
int V_168 = 1 ;
struct V_163 * V_178 ;
F_3 ( V_179 , L_49 ) ;
V_2 -> V_174 = 0 ;
V_178 = F_50 ( sizeof( * V_178 ) , V_181 ) ;
if ( ! V_178 )
return - V_182 ;
if ( ( V_184 = F_48 ( V_2 , V_178 ) ) == 0 )
V_168 = V_178 -> V_167 . V_168 ;
F_51 ( V_178 ) ;
return V_168 ;
}
static int F_53 ( struct V_1 * V_2 , int V_177 )
{
struct V_3 V_4 ;
F_3 ( V_179 , L_50 ) ;
if ( V_2 -> V_166 && V_177 < 0 )
return 0 ;
F_14 ( & V_4 , NULL , 0 , V_95 ) ;
V_4 . V_72 [ 0 ] = V_185 ;
V_4 . V_72 [ 4 ] = 2 + ( V_177 >= 0 ) ;
V_4 . V_72 [ 8 ] = V_177 ;
V_4 . V_78 = 60 * V_79 ;
if ( V_2 -> V_166 && - 1 < V_177 ) {
V_4 . V_72 [ 0 ] = V_186 ;
V_4 . V_72 [ 7 ] = V_177 ;
V_4 . V_72 [ 4 ] = V_4 . V_72 [ 8 ] = 0 ;
V_2 -> V_166 = V_177 ? V_177 : 3 ;
}
return V_2 -> V_14 -> V_41 ( V_2 , & V_4 ) ;
}
static int F_54 ( struct V_1 * V_2 , int V_177 )
{
struct V_163 * V_178 ;
int V_169 ;
int V_86 ;
F_3 ( V_179 , L_51 ) ;
if ( ! F_7 ( V_27 ) )
return - V_187 ;
if ( V_2 -> V_14 -> V_24 )
V_2 -> V_14 -> V_24 ( V_2 , 0 , V_177 ) ;
else
V_2 -> V_14 -> V_25 ( V_2 , V_177 ) ;
if ( V_177 == V_188 ) {
V_2 -> V_43 = 0x3 ;
return F_53 ( V_2 , - 1 ) ;
}
V_178 = F_50 ( sizeof( * V_178 ) , V_181 ) ;
if ( ! V_178 )
return - V_182 ;
if ( ( V_86 = F_48 ( V_2 , V_178 ) ) ) {
F_51 ( V_178 ) ;
return V_86 ;
}
V_169 = V_178 -> V_167 . V_169 ;
F_51 ( V_178 ) ;
if ( V_2 -> V_142 > 1 || V_2 -> V_161 ) {
if ( V_177 == V_149 ) {
return V_169 ;
} else {
return - V_189 ;
}
}
if ( V_177 == V_149 )
V_177 = V_169 ;
V_2 -> V_43 = 0x3 ;
if ( ( V_86 = F_53 ( V_2 , V_177 ) ) )
return V_86 ;
return V_177 ;
}
static void F_55 ( struct V_1 * V_2 ,
unsigned int V_190 )
{
unsigned int V_191 ;
V_191 = V_2 -> V_14 -> V_24 ( V_2 , V_190 , V_149 ) ;
V_2 -> V_192 |= V_191 ;
V_2 -> V_193 |= V_191 ;
}
unsigned int F_56 ( struct V_1 * V_2 ,
unsigned int V_190 )
{
unsigned int V_191 ;
F_55 ( V_2 , V_190 ) ;
V_191 = V_2 -> V_192 ;
V_2 -> V_192 = 0 ;
return V_191 ;
}
static
int V_25 ( struct V_1 * V_2 , int V_194 )
{
unsigned int V_130 = ( 1 << ( V_194 & 1 ) ) ;
int V_86 = ! ! ( V_2 -> V_43 & V_130 ) ;
bool V_195 ;
if ( ! F_7 ( V_26 ) )
return V_86 ;
if ( V_2 -> V_14 -> V_24 ) {
F_57 ( ! V_194 ) ;
F_55 ( V_2 , V_196 ) ;
V_195 = V_2 -> V_193 & V_196 ;
V_2 -> V_193 = 0 ;
} else
V_195 = V_2 -> V_14 -> V_25 ( V_2 , V_149 ) ;
if ( V_195 ) {
V_2 -> V_43 = 0x3 ;
V_86 |= 1 ;
V_2 -> V_102 = 0 ;
}
V_2 -> V_43 &= ~ V_130 ;
return V_86 ;
}
int F_58 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_14 -> V_25 == NULL )
return 0 ;
if ( ! F_7 ( V_26 ) )
return 0 ;
return V_25 ( V_2 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 , T_4 * V_148 )
{
struct V_197 V_198 ;
struct V_199 V_200 ;
int V_86 , V_201 ;
V_148 -> V_155 = 0 ;
V_148 -> V_159 = 0 ;
V_148 -> V_2 = 0 ;
V_148 -> V_202 = 0 ;
V_148 -> error = 0 ;
F_3 ( V_203 , L_52 ) ;
if ( ( V_86 = V_2 -> V_14 -> V_204 ( V_2 , V_205 , & V_198 ) ) ) {
if ( V_86 == - V_151 )
V_148 -> error = V_153 ;
else
V_148 -> error = V_180 ;
return;
}
V_200 . V_206 = V_207 ;
for ( V_201 = V_198 . V_208 ; V_201 <= V_198 . V_209 ; V_201 ++ ) {
V_200 . V_210 = V_201 ;
if ( V_2 -> V_14 -> V_204 ( V_2 , V_211 , & V_200 ) ) {
V_148 -> error = V_180 ;
return;
}
if ( V_200 . V_212 & V_213 ) {
if ( V_200 . V_206 == 0x10 )
V_148 -> V_2 ++ ;
else if ( V_200 . V_206 == 0x20 )
V_148 -> V_202 ++ ;
else
V_148 -> V_155 ++ ;
} else
V_148 -> V_159 ++ ;
F_3 ( V_203 , L_53 ,
V_201 , V_200 . V_206 , V_200 . V_212 ) ;
}
F_3 ( V_203 , L_54 ,
V_198 . V_209 , V_148 -> V_159 , V_148 -> V_155 ,
V_148 -> V_2 , V_148 -> V_202 ) ;
}
static
void F_59 ( union V_214 * V_215 ,
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
void F_14 ( struct V_3 * V_4 , void * V_164 , int V_223 ,
int type )
{
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
if ( V_164 )
memset ( V_164 , 0 , V_223 ) ;
V_4 -> V_68 = ( char * ) V_164 ;
V_4 -> V_108 = V_223 ;
V_4 -> V_224 = type ;
V_4 -> V_78 = V_225 ;
}
static void F_60 ( struct V_3 * V_4 , unsigned V_226 , unsigned type )
{
V_4 -> V_72 [ 0 ] = V_227 ;
V_4 -> V_72 [ 10 ] = type | ( V_226 << 6 ) ;
switch ( type ) {
case 0 : case 8 : case 5 : {
V_4 -> V_108 = 8 ;
break;
}
case 1 : {
V_4 -> V_108 = 16 ;
break;
}
case 2 : case 4 : {
V_4 -> V_108 = 12 ;
break;
}
}
V_4 -> V_72 [ 9 ] = V_4 -> V_108 ;
V_4 -> V_224 = V_71 ;
}
static void F_61 ( struct V_3 * V_4 , unsigned V_226 , unsigned type )
{
V_4 -> V_72 [ 0 ] = V_228 ;
V_4 -> V_72 [ 10 ] = type | ( V_226 << 6 ) ;
switch ( type ) {
case 1 : {
V_4 -> V_108 = 16 ;
break;
}
case 3 : {
V_4 -> V_108 = 12 ;
break;
}
case 6 : {
V_4 -> V_108 = 8 ;
break;
}
}
V_4 -> V_72 [ 9 ] = V_4 -> V_108 ;
V_4 -> V_224 = V_92 ;
}
static int F_62 ( struct V_1 * V_2 , T_6 * V_229 )
{
int V_86 ;
T_5 V_164 [ 20 ] ;
struct V_3 V_4 ;
struct V_12 * V_13 = V_2 -> V_14 ;
T_7 V_230 ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
F_14 ( & V_4 , V_164 , 0 , V_71 ) ;
switch ( V_229 -> type ) {
case V_231 :
F_3 ( V_232 , L_55 ) ;
V_4 . V_74 = 1 ;
F_60 ( & V_4 , V_229 -> V_233 . V_226 , 0 ) ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_229 -> V_233 . V_226 = V_164 [ 7 ] >> 6 ;
break;
case V_234 :
F_3 ( V_232 , L_56 ) ;
F_60 ( & V_4 , V_229 -> V_235 . V_226 , 2 ) ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
F_63 ( V_229 -> V_235 . V_236 , & V_164 [ 4 ] ) ;
break;
case V_237 :
F_3 ( V_232 , L_57 ) ;
F_60 ( & V_4 , V_229 -> V_238 . V_226 , 1 ) ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
F_64 ( V_229 -> V_238 . V_239 , & V_164 [ 4 ] ) ;
break;
case V_240 :
F_3 ( V_232 , L_58 ) ;
V_4 . V_74 = 1 ;
F_60 ( & V_4 , V_229 -> V_241 . V_226 , 4 ) ;
V_4 . V_72 [ 5 ] = V_229 -> V_241 . V_218 ;
V_4 . V_72 [ 4 ] = V_229 -> V_241 . V_218 >> 8 ;
V_4 . V_72 [ 3 ] = V_229 -> V_241 . V_218 >> 16 ;
V_4 . V_72 [ 2 ] = V_229 -> V_241 . V_218 >> 24 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_229 -> V_241 . V_242 = ( V_164 [ 4 ] >> 7 ) & 1 ;
V_229 -> V_241 . V_243 = ( V_164 [ 4 ] >> 6 ) & 1 ;
V_229 -> V_241 . V_244 = ( V_164 [ 4 ] >> 4 ) & 3 ;
F_63 ( V_229 -> V_241 . V_245 , & V_164 [ 5 ] ) ;
break;
case V_246 :
F_3 ( V_232 , L_59 ) ;
F_60 ( & V_4 , V_229 -> V_247 . V_226 , 5 ) ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_229 -> V_247 . V_248 = V_164 [ 7 ] & 1 ;
break;
case V_249 :
F_3 ( V_232 , L_60 ) ;
F_61 ( & V_4 , V_229 -> V_250 . V_226 , 1 ) ;
V_164 [ 1 ] = 0xe ;
F_64 ( & V_164 [ 4 ] , V_229 -> V_250 . V_239 ) ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_229 -> type = V_234 ;
break;
case V_251 :
F_3 ( V_232 , L_61 ) ;
F_61 ( & V_4 , V_229 -> V_252 . V_226 , 3 ) ;
V_164 [ 1 ] = 0xa ;
F_63 ( & V_164 [ 4 ] , V_229 -> V_252 . V_236 ) ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) ) {
V_229 -> type = V_253 ;
return V_86 ;
}
V_229 -> type = V_254 ;
break;
case V_255 :
V_4 . V_74 = 1 ;
F_3 ( V_232 , L_62 ) ;
F_60 ( & V_4 , V_229 -> V_233 . V_226 , 0x3f ) ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
break;
case V_256 :
F_3 ( V_232 , L_63 ) ;
F_60 ( & V_4 , 0 , 8 ) ;
memset ( & V_230 , 0 , sizeof( T_7 ) ) ;
V_4 . V_68 = ( char * ) & V_230 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_229 -> V_257 . type = V_230 . V_258 ;
V_229 -> V_257 . V_259 = V_230 . V_259 ;
V_229 -> V_257 . V_260 = V_230 . V_260 ;
V_229 -> V_257 . V_261 = V_230 . V_261 ;
V_229 -> V_257 . V_262 = V_230 . V_262 ;
break;
case V_263 :
F_3 ( V_232 , L_64 ) ;
F_61 ( & V_4 , 0 , 6 ) ;
V_164 [ 1 ] = 6 ;
V_164 [ 4 ] = V_229 -> V_264 . V_265 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
break;
default:
F_3 ( V_156 , L_65 , V_229 -> type ) ;
return - V_266 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
unsigned char V_164 [ 21 ] , * V_268 ;
struct V_269 * V_270 ;
struct V_12 * V_13 = V_2 -> V_14 ;
int V_86 , V_271 = V_267 -> V_272 . V_271 ;
if ( V_271 >= V_273 )
return - V_20 ;
F_14 ( V_4 , V_164 , sizeof( V_164 ) , V_71 ) ;
V_4 -> V_72 [ 0 ] = V_274 ;
V_4 -> V_72 [ 6 ] = V_271 ;
V_4 -> V_72 [ 7 ] = V_267 -> type ;
V_4 -> V_72 [ 9 ] = V_4 -> V_108 & 0xff ;
V_4 -> V_74 = 1 ;
V_86 = V_13 -> V_41 ( V_2 , V_4 ) ;
if ( V_86 )
return V_86 ;
V_268 = & V_164 [ 4 ] ;
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
static int F_66 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_86 ;
T_5 V_164 [ 8 ] ;
struct V_12 * V_13 = V_2 -> V_14 ;
F_14 ( V_4 , V_164 , sizeof( V_164 ) , V_71 ) ;
V_4 -> V_72 [ 0 ] = V_274 ;
V_4 -> V_72 [ 6 ] = V_267 -> V_288 . V_271 ;
V_4 -> V_72 [ 7 ] = V_267 -> type ;
V_4 -> V_72 [ 8 ] = V_4 -> V_108 >> 8 ;
V_4 -> V_72 [ 9 ] = V_4 -> V_108 & 0xff ;
V_86 = V_13 -> V_41 ( V_2 , V_4 ) ;
if ( V_86 )
return V_86 ;
V_267 -> V_288 . V_289 = V_164 [ 4 ] ;
V_267 -> V_288 . V_290 = V_164 [ 5 ] ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_86 , V_107 ;
T_5 * V_164 ;
struct V_12 * V_13 = V_2 -> V_14 ;
V_107 = sizeof( V_267 -> V_291 . V_292 ) + 4 ;
V_164 = F_50 ( V_107 , V_181 ) ;
if ( ! V_164 )
return - V_182 ;
F_14 ( V_4 , V_164 , V_107 , V_71 ) ;
V_4 -> V_72 [ 0 ] = V_274 ;
V_4 -> V_72 [ 7 ] = V_267 -> type ;
V_4 -> V_72 [ 8 ] = V_107 >> 8 ;
V_4 -> V_72 [ 9 ] = V_107 & 0xff ;
V_4 -> V_72 [ 10 ] = V_267 -> V_291 . V_226 << 6 ;
V_86 = V_13 -> V_41 ( V_2 , V_4 ) ;
if ( ! V_86 )
memcpy ( V_267 -> V_291 . V_292 , & V_164 [ 4 ] , sizeof( V_267 -> V_291 . V_292 ) ) ;
F_51 ( V_164 ) ;
return V_86 ;
}
static int F_68 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_86 , V_107 = 4 + 188 ;
T_5 * V_164 ;
struct V_12 * V_13 = V_2 -> V_14 ;
V_164 = F_50 ( V_107 , V_181 ) ;
if ( ! V_164 )
return - V_182 ;
F_14 ( V_4 , V_164 , V_107 , V_71 ) ;
V_4 -> V_72 [ 0 ] = V_274 ;
V_4 -> V_72 [ 7 ] = V_267 -> type ;
V_4 -> V_72 [ 9 ] = V_4 -> V_108 & 0xff ;
V_86 = V_13 -> V_41 ( V_2 , V_4 ) ;
if ( V_86 )
goto V_293;
V_267 -> V_287 . V_223 = V_164 [ 0 ] << 8 | V_164 [ 1 ] ;
if ( V_267 -> V_287 . V_223 < 12 || V_267 -> V_287 . V_223 > 188 ) {
F_3 ( V_156 , L_66 , V_267 -> V_287 . V_223 ) ;
V_86 = - V_10 ;
goto V_293;
}
memcpy ( V_267 -> V_287 . V_292 , & V_164 [ 4 ] , V_267 -> V_287 . V_223 ) ;
V_86 = 0 ;
V_293:
F_51 ( V_164 ) ;
return V_86 ;
}
static int F_69 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
int V_86 = 0 , V_107 ;
T_5 * V_164 ;
struct V_12 * V_13 = V_2 -> V_14 ;
V_107 = sizeof( V_267 -> V_294 . V_292 ) + 4 ;
V_164 = F_50 ( V_107 , V_181 ) ;
if ( ! V_164 )
return - V_182 ;
F_14 ( V_4 , V_164 , V_107 , V_71 ) ;
V_4 -> V_72 [ 0 ] = V_274 ;
V_4 -> V_72 [ 7 ] = V_267 -> type ;
V_4 -> V_72 [ 8 ] = V_107 >> 8 ;
V_4 -> V_72 [ 9 ] = V_107 & 0xff ;
V_86 = V_13 -> V_41 ( V_2 , V_4 ) ;
if ( V_86 )
goto V_293;
V_267 -> V_294 . V_223 = V_164 [ 0 ] << 8 | V_164 [ 1 ] ;
if ( V_267 -> V_294 . V_223 < 0 ) {
F_3 ( V_156 , L_67
L_68 , V_267 -> V_294 . V_223 ) ;
V_86 = - V_10 ;
} else {
if ( V_267 -> V_294 . V_223 > 2048 ) {
F_3 ( V_156 , L_69
L_70 ,
V_267 -> V_294 . V_223 ) ;
V_267 -> V_294 . V_223 = 2048 ;
}
memcpy ( V_267 -> V_294 . V_292 , & V_164 [ 4 ] , V_267 -> V_294 . V_223 ) ;
}
V_293:
F_51 ( V_164 ) ;
return V_86 ;
}
static int F_70 ( struct V_1 * V_2 , T_8 * V_267 ,
struct V_3 * V_4 )
{
switch ( V_267 -> type ) {
case V_295 :
return F_65 ( V_2 , V_267 , V_4 ) ;
case V_296 :
return F_66 ( V_2 , V_267 , V_4 ) ;
case V_297 :
return F_67 ( V_2 , V_267 , V_4 ) ;
case V_298 :
return F_68 ( V_2 , V_267 , V_4 ) ;
case V_299 :
return F_69 ( V_2 , V_267 , V_4 ) ;
default:
F_3 ( V_156 , L_71 ,
V_267 -> type ) ;
return - V_20 ;
}
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_300 , int V_301 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
memset ( V_4 -> V_72 , 0 , sizeof( V_4 -> V_72 ) ) ;
V_4 -> V_72 [ 0 ] = V_302 ;
V_4 -> V_72 [ 2 ] = V_300 | ( V_301 << 6 ) ;
V_4 -> V_72 [ 7 ] = V_4 -> V_108 >> 8 ;
V_4 -> V_72 [ 8 ] = V_4 -> V_108 & 0xff ;
V_4 -> V_224 = V_71 ;
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
memset ( V_4 -> V_72 , 0 , sizeof( V_4 -> V_72 ) ) ;
memset ( V_4 -> V_68 , 0 , 2 ) ;
V_4 -> V_72 [ 0 ] = V_303 ;
V_4 -> V_72 [ 1 ] = 0x10 ;
V_4 -> V_72 [ 7 ] = V_4 -> V_108 >> 8 ;
V_4 -> V_72 [ 8 ] = V_4 -> V_108 & 0xff ;
V_4 -> V_224 = V_92 ;
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_304 * V_305 , int V_306 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_3 V_4 ;
char V_68 [ 32 ] ;
int V_86 ;
F_14 ( & V_4 , V_68 , 16 , V_71 ) ;
V_4 . V_72 [ 0 ] = V_307 ;
V_4 . V_72 [ 1 ] = 2 ;
V_4 . V_72 [ 2 ] = 0x40 ;
V_4 . V_72 [ 3 ] = V_306 ? 2 : 1 ;
V_4 . V_72 [ 8 ] = 16 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_305 -> V_308 = V_4 . V_68 [ 1 ] ;
V_305 -> V_309 = V_207 ;
V_305 -> V_310 = V_4 . V_68 [ 5 ] & 0xf ;
V_305 -> V_311 = V_4 . V_68 [ 6 ] ;
V_305 -> V_312 = V_4 . V_68 [ 7 ] ;
V_305 -> V_313 . V_219 . V_222 = V_4 . V_68 [ 13 ] ;
V_305 -> V_313 . V_219 . V_221 = V_4 . V_68 [ 14 ] ;
V_305 -> V_313 . V_219 . V_220 = V_4 . V_68 [ 15 ] ;
V_305 -> V_314 . V_219 . V_222 = V_4 . V_68 [ 9 ] ;
V_305 -> V_314 . V_219 . V_221 = V_4 . V_68 [ 10 ] ;
V_305 -> V_314 . V_219 . V_220 = V_4 . V_68 [ 11 ] ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_218 ,
int V_315 , int V_316 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
memset ( & V_4 -> V_72 , 0 , sizeof( V_4 -> V_72 ) ) ;
V_4 -> V_72 [ 0 ] = V_317 ;
V_4 -> V_72 [ 2 ] = ( V_218 >> 24 ) & 0xff ;
V_4 -> V_72 [ 3 ] = ( V_218 >> 16 ) & 0xff ;
V_4 -> V_72 [ 4 ] = ( V_218 >> 8 ) & 0xff ;
V_4 -> V_72 [ 5 ] = V_218 & 0xff ;
V_4 -> V_72 [ 6 ] = ( V_316 >> 16 ) & 0xff ;
V_4 -> V_72 [ 7 ] = ( V_316 >> 8 ) & 0xff ;
V_4 -> V_72 [ 8 ] = V_316 & 0xff ;
V_4 -> V_108 = V_315 * V_316 ;
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_218 , int V_316 , int V_318 , int V_319 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
memset ( & V_4 -> V_72 , 0 , sizeof( V_4 -> V_72 ) ) ;
V_4 -> V_72 [ 0 ] = V_320 ;
V_4 -> V_72 [ 1 ] = V_318 << 2 ;
V_4 -> V_72 [ 2 ] = ( V_218 >> 24 ) & 0xff ;
V_4 -> V_72 [ 3 ] = ( V_218 >> 16 ) & 0xff ;
V_4 -> V_72 [ 4 ] = ( V_218 >> 8 ) & 0xff ;
V_4 -> V_72 [ 5 ] = V_218 & 0xff ;
V_4 -> V_72 [ 6 ] = ( V_316 >> 16 ) & 0xff ;
V_4 -> V_72 [ 7 ] = ( V_316 >> 8 ) & 0xff ;
V_4 -> V_72 [ 8 ] = V_316 & 0xff ;
V_4 -> V_108 = V_319 * V_316 ;
switch ( V_319 ) {
case V_321 : V_4 -> V_72 [ 9 ] = 0x58 ; break;
case V_322 : V_4 -> V_72 [ 9 ] = 0x78 ; break;
case V_323 : V_4 -> V_72 [ 9 ] = 0xf8 ; break;
default : V_4 -> V_72 [ 9 ] = 0x10 ;
}
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
static int F_74 ( struct V_1 * V_2 , T_9 T_10 * V_324 ,
int V_218 , int V_325 )
{
struct V_3 V_4 ;
int V_86 = 0 ;
int V_326 ;
V_2 -> V_327 = 0 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_326 = V_325 ;
do {
V_4 . V_68 = F_50 ( V_323 * V_326 , V_181 ) ;
if ( V_4 . V_68 )
break;
V_326 >>= 1 ;
} while ( V_326 );
if ( ! V_326 )
return - V_182 ;
V_4 . V_224 = V_71 ;
while ( V_325 > 0 ) {
if ( V_326 > V_325 )
V_326 = V_325 ;
V_86 = F_73 ( V_2 , & V_4 , V_218 , V_326 , 1 , V_323 ) ;
if ( V_86 )
break;
if ( F_75 ( V_324 , V_4 . V_68 , V_323 * V_326 ) ) {
V_86 = - V_328 ;
break;
}
V_324 += V_323 * V_326 ;
V_325 -= V_326 ;
V_218 += V_326 ;
}
F_51 ( V_4 . V_68 ) ;
return V_86 ;
}
static int F_76 ( struct V_1 * V_2 , T_9 T_10 * V_324 ,
int V_218 , int V_325 )
{
struct V_329 * V_330 = V_2 -> V_57 -> V_194 ;
struct V_331 * V_332 ;
struct V_333 * V_333 ;
unsigned int V_223 ;
int V_326 , V_86 = 0 ;
if ( ! V_330 )
return - V_334 ;
V_2 -> V_327 = 0 ;
while ( V_325 ) {
V_326 = V_325 ;
if ( V_2 -> V_58 == V_335 )
V_326 = 1 ;
if ( V_326 * V_323 > ( F_77 ( V_330 ) << 9 ) )
V_326 = ( F_77 ( V_330 ) << 9 ) / V_323 ;
V_223 = V_326 * V_323 ;
V_332 = F_78 ( V_330 , V_336 , V_181 ) ;
if ( ! V_332 ) {
V_86 = - V_182 ;
break;
}
V_86 = F_79 ( V_330 , V_332 , NULL , V_324 , V_223 , V_181 ) ;
if ( V_86 ) {
F_80 ( V_332 ) ;
break;
}
V_332 -> V_72 [ 0 ] = V_320 ;
V_332 -> V_72 [ 1 ] = 1 << 2 ;
V_332 -> V_72 [ 2 ] = ( V_218 >> 24 ) & 0xff ;
V_332 -> V_72 [ 3 ] = ( V_218 >> 16 ) & 0xff ;
V_332 -> V_72 [ 4 ] = ( V_218 >> 8 ) & 0xff ;
V_332 -> V_72 [ 5 ] = V_218 & 0xff ;
V_332 -> V_72 [ 6 ] = ( V_326 >> 16 ) & 0xff ;
V_332 -> V_72 [ 7 ] = ( V_326 >> 8 ) & 0xff ;
V_332 -> V_72 [ 8 ] = V_326 & 0xff ;
V_332 -> V_72 [ 9 ] = 0xf8 ;
V_332 -> V_337 = 12 ;
V_332 -> V_338 = V_339 ;
V_332 -> V_78 = 60 * V_79 ;
V_333 = V_332 -> V_333 ;
if ( F_81 ( V_330 , V_2 -> V_57 , V_332 , 0 ) ) {
struct V_340 * V_267 = V_332 -> V_5 ;
V_86 = - V_10 ;
V_2 -> V_327 = V_267 -> V_6 ;
}
if ( F_82 ( V_333 ) )
V_86 = - V_328 ;
F_80 ( V_332 ) ;
if ( V_86 )
break;
V_325 -= V_326 ;
V_218 += V_326 ;
V_324 += V_223 ;
}
return V_86 ;
}
static int F_83 ( struct V_1 * V_2 , T_9 T_10 * V_324 ,
int V_218 , int V_325 )
{
int V_86 ;
if ( V_2 -> V_58 == V_60 )
return F_74 ( V_2 , V_324 , V_218 , V_325 ) ;
V_341:
V_86 = F_76 ( V_2 , V_324 , V_218 , V_325 ) ;
if ( ! V_86 || V_86 != - V_10 )
return V_86 ;
if ( V_2 -> V_58 == V_59 && V_325 > 1 ) {
F_4 ( L_72 ) ;
V_2 -> V_58 = V_335 ;
goto V_341;
}
if ( V_2 -> V_327 != 0x04 && V_2 -> V_327 != 0x0b )
return V_86 ;
F_4 ( L_73 , V_2 -> V_327 ) ;
V_2 -> V_58 = V_60 ;
return F_74 ( V_2 , V_324 , V_218 , V_325 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_343 V_344 ;
T_11 V_345 ;
int V_86 ;
F_3 ( V_346 , L_74 ) ;
if ( ! ( V_2 -> V_14 -> V_16 & V_36 ) )
return - V_347 ;
if ( F_85 ( & V_344 , V_342 , sizeof( V_344 ) ) )
return - V_328 ;
V_345 = V_344 . V_348 ;
if ( V_345 != V_207 && V_345 != V_217 )
return - V_20 ;
V_344 . V_348 = V_217 ;
V_86 = V_2 -> V_14 -> V_35 ( V_2 , & V_344 ) ;
if ( V_86 )
return V_86 ;
F_59 ( & V_344 . V_215 , & V_344 . V_348 , V_345 ) ;
if ( F_75 ( V_342 , & V_344 , sizeof( V_344 ) ) )
return - V_328 ;
F_3 ( V_346 , L_75 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
F_3 ( V_346 , L_76 ) ;
if ( ! F_7 ( V_30 ) )
return - V_347 ;
if ( V_2 -> V_142 != 1 || V_2 -> V_161 )
return - V_189 ;
if ( F_7 ( V_32 ) ) {
int V_86 = V_2 -> V_14 -> V_31 ( V_2 , 0 ) ;
if ( V_86 )
return V_86 ;
}
return V_2 -> V_14 -> V_28 ( V_2 , 1 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
F_3 ( V_346 , L_77 ) ;
if ( ! F_7 ( V_29 ) )
return - V_347 ;
return V_2 -> V_14 -> V_28 ( V_2 , 0 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_78 ) ;
if ( ! F_7 ( V_30 ) )
return - V_347 ;
if ( V_2 -> V_161 )
return - V_189 ;
V_2 -> V_45 &= ~ ( V_48 | V_50 ) ;
if ( V_349 )
V_2 -> V_45 |= V_48 | V_50 ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
struct V_163 * V_178 ;
int V_86 ;
F_3 ( V_346 , L_79 ) ;
if ( ! F_7 ( V_26 ) )
return - V_347 ;
if ( ! F_7 ( V_27 ) || V_349 == V_149 )
return V_25 ( V_2 , 1 ) ;
if ( ( unsigned int ) V_349 >= V_2 -> V_174 )
return - V_20 ;
V_178 = F_50 ( sizeof( * V_178 ) , V_181 ) ;
if ( ! V_178 )
return - V_182 ;
V_86 = F_48 ( V_2 , V_178 ) ;
if ( ! V_86 )
V_86 = V_178 -> V_170 [ V_349 ] . V_172 ;
F_51 ( V_178 ) ;
return V_86 ;
}
static int F_90 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_80 ) ;
switch ( V_349 ) {
case V_46 :
case V_54 :
break;
case V_52 :
if ( ! F_7 ( V_32 ) )
return - V_347 ;
break;
case 0 :
return V_2 -> V_45 ;
default:
if ( ! F_7 ( V_349 ) )
return - V_347 ;
}
V_2 -> V_45 |= ( int ) V_349 ;
return V_2 -> V_45 ;
}
static int F_91 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_81 ) ;
V_2 -> V_45 &= ~ ( int ) V_349 ;
return V_2 -> V_45 ;
}
static int F_92 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_82 ) ;
if ( ! F_7 ( V_34 ) )
return - V_347 ;
return V_2 -> V_14 -> V_33 ( V_2 , V_349 ) ;
}
static int F_93 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_83 ) ;
if ( ! F_7 ( V_27 ) )
return - V_347 ;
if ( V_349 != V_149 && V_349 != V_188 ) {
if ( ( int ) V_349 >= V_2 -> V_174 )
return - V_20 ;
}
if ( V_2 -> V_14 -> V_350 )
return V_2 -> V_14 -> V_350 ( V_2 , V_349 ) ;
F_3 ( V_179 , L_84 ) ;
return F_54 ( V_2 , V_349 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
F_3 ( V_346 , L_85 ) ;
if ( ! F_95 ( V_351 ) )
return - V_352 ;
if ( ! F_7 ( V_40 ) )
return - V_347 ;
F_96 ( V_140 ) ;
return V_2 -> V_14 -> V_39 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_86 , V_349 ? L_87 : L_88 ) ;
if ( ! F_7 ( V_32 ) )
return - V_187 ;
V_2 -> V_161 = V_349 ? 1 : 0 ;
if ( V_2 -> V_142 != 1 && ! V_349 && ! F_95 ( V_351 ) )
return - V_189 ;
return V_2 -> V_14 -> V_31 ( V_2 , V_349 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_89 , V_349 ? L_90 : L_91 ) ;
if ( ! F_95 ( V_351 ) )
return - V_352 ;
V_353 = V_349 ? 1 : 0 ;
return V_353 ;
}
static int F_99 ( struct V_1 * V_2 )
{
F_3 ( V_346 , L_92 ) ;
return ( V_2 -> V_14 -> V_16 & ~ V_2 -> V_130 ) ;
}
static int F_100 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_354 V_306 ;
int V_86 ;
F_3 ( V_346 , L_93 ) ;
if ( ! ( V_2 -> V_14 -> V_16 & V_38 ) )
return - V_347 ;
V_86 = V_2 -> V_14 -> V_37 ( V_2 , & V_306 ) ;
if ( V_86 )
return V_86 ;
if ( F_75 ( V_342 , & V_306 , sizeof( V_306 ) ) )
return - V_328 ;
F_3 ( V_346 , L_94 ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
unsigned long V_349 )
{
F_3 ( V_346 , L_95 ) ;
if ( ! ( V_2 -> V_14 -> V_16 & V_23 ) )
return - V_347 ;
if ( ! F_7 ( V_27 ) ||
( V_349 == V_149 || V_349 == V_188 ) )
return V_2 -> V_14 -> V_22 ( V_2 , V_149 ) ;
if ( ( ( int ) V_349 >= V_2 -> V_174 ) )
return - V_20 ;
return F_49 ( V_2 , V_349 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
T_4 V_148 ;
F_3 ( V_346 , L_96 ) ;
F_44 ( V_2 , & V_148 ) ;
if ( V_148 . error )
return V_148 . error ;
if ( V_148 . V_159 > 0 ) {
if ( ! V_148 . V_155 && ! V_148 . V_2 && ! V_148 . V_202 )
return V_355 ;
else
return V_356 ;
}
if ( V_148 . V_2 > 0 )
return V_357 ;
if ( V_148 . V_202 > 0 )
return V_358 ;
if ( V_148 . V_155 > 0 )
return V_359 ;
F_3 ( V_156 , L_97 ) ;
return V_180 ;
}
static int F_103 ( struct V_1 * V_2 )
{
F_3 ( V_346 , L_98 ) ;
return V_2 -> V_174 ;
}
static int F_104 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_304 V_330 ;
T_11 V_216 , V_360 ;
int V_86 ;
if ( F_85 ( & V_330 , V_342 , sizeof( V_330 ) ) )
return - V_328 ;
V_216 = V_330 . V_309 ;
if ( V_216 != V_207 && V_216 != V_217 )
return - V_20 ;
V_330 . V_309 = V_207 ;
V_86 = V_2 -> V_14 -> V_204 ( V_2 , V_361 , & V_330 ) ;
if ( V_86 )
return V_86 ;
V_360 = V_330 . V_309 ;
F_59 ( & V_330 . V_314 , & V_360 , V_216 ) ;
F_59 ( & V_330 . V_313 , & V_330 . V_309 , V_216 ) ;
if ( F_75 ( V_342 , & V_330 , sizeof( V_330 ) ) )
return - V_328 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_197 V_198 ;
int V_86 ;
if ( F_85 ( & V_198 , V_342 , sizeof( V_198 ) ) )
return - V_328 ;
V_86 = V_2 -> V_14 -> V_204 ( V_2 , V_205 , & V_198 ) ;
if ( V_86 )
return V_86 ;
if ( F_75 ( V_342 , & V_198 , sizeof( V_198 ) ) )
return - V_328 ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_199 V_200 ;
T_11 V_345 ;
int V_86 ;
if ( F_85 ( & V_200 , V_342 , sizeof( V_200 ) ) )
return - V_328 ;
V_345 = V_200 . V_206 ;
if ( V_345 != V_207 && V_345 != V_217 )
return - V_20 ;
V_200 . V_206 = V_207 ;
V_86 = V_2 -> V_14 -> V_204 ( V_2 , V_211 , & V_200 ) ;
if ( V_86 )
return V_86 ;
F_59 ( & V_200 . V_362 , & V_200 . V_206 , V_345 ) ;
if ( F_75 ( V_342 , & V_200 , sizeof( V_200 ) ) )
return - V_328 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_363 V_219 ;
F_3 ( V_346 , L_99 ) ;
if ( ! F_7 ( V_364 ) )
return - V_347 ;
if ( F_85 ( & V_219 , V_342 , sizeof( V_219 ) ) )
return - V_328 ;
return V_2 -> V_14 -> V_204 ( V_2 , V_365 , & V_219 ) ;
}
static int F_108 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_366 V_367 ;
int V_86 ;
F_3 ( V_346 , L_100 ) ;
if ( ! F_7 ( V_364 ) )
return - V_347 ;
if ( F_85 ( & V_367 , V_342 , sizeof( V_367 ) ) )
return - V_328 ;
V_86 = F_46 ( V_2 , V_2 -> V_14 ) ;
if ( V_86 )
return V_86 ;
return V_2 -> V_14 -> V_204 ( V_2 , V_368 , & V_367 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_369 V_370 ;
F_3 ( V_346 , L_101 ) ;
if ( ! F_7 ( V_364 ) )
return - V_347 ;
if ( F_85 ( & V_370 , V_342 , sizeof( V_370 ) ) )
return - V_328 ;
return V_2 -> V_14 -> V_204 ( V_2 , V_371 , & V_370 ) ;
}
static int F_110 ( struct V_1 * V_2 ,
void T_10 * V_342 )
{
struct V_369 V_370 ;
int V_86 ;
F_3 ( V_346 , L_102 ) ;
if ( ! F_7 ( V_364 ) )
return - V_347 ;
V_86 = V_2 -> V_14 -> V_204 ( V_2 , V_372 , & V_370 ) ;
if ( V_86 )
return V_86 ;
if ( F_75 ( V_342 , & V_370 , sizeof( V_370 ) ) )
return - V_328 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 ,
unsigned int V_72 )
{
int V_86 ;
F_3 ( V_346 , L_103 ) ;
if ( ! F_7 ( V_364 ) )
return - V_347 ;
V_86 = F_46 ( V_2 , V_2 -> V_14 ) ;
if ( V_86 )
return V_86 ;
return V_2 -> V_14 -> V_204 ( V_2 , V_72 , NULL ) ;
}
int F_112 ( struct V_1 * V_2 , struct V_139 * V_140 ,
T_3 V_141 , unsigned int V_72 , unsigned long V_349 )
{
void T_10 * V_342 = ( void T_10 * ) V_349 ;
int V_86 ;
V_86 = F_113 ( V_140 , V_141 , V_72 , V_342 ) ;
if ( V_86 != - V_266 )
return V_86 ;
switch ( V_72 ) {
case V_373 :
return F_84 ( V_2 , V_342 ) ;
case V_374 :
return F_86 ( V_2 ) ;
case V_375 :
return F_87 ( V_2 ) ;
case V_376 :
return F_88 ( V_2 , V_349 ) ;
case V_377 :
return F_89 ( V_2 , V_349 ) ;
case V_378 :
return F_90 ( V_2 , V_349 ) ;
case V_379 :
return F_91 ( V_2 , V_349 ) ;
case V_380 :
return F_92 ( V_2 , V_349 ) ;
case V_381 :
return F_93 ( V_2 , V_349 ) ;
case V_382 :
return F_94 ( V_2 , V_140 ) ;
case V_383 :
return F_97 ( V_2 , V_349 ) ;
case V_384 :
return F_98 ( V_2 , V_349 ) ;
case V_385 :
return F_99 ( V_2 ) ;
case V_386 :
return F_100 ( V_2 , V_342 ) ;
case V_387 :
return F_101 ( V_2 , V_349 ) ;
case V_388 :
return F_102 ( V_2 ) ;
case V_389 :
return F_103 ( V_2 ) ;
}
if ( F_7 ( V_42 ) ) {
V_86 = F_114 ( V_2 , V_72 , V_349 ) ;
if ( V_86 != - V_266 )
return V_86 ;
}
switch ( V_72 ) {
case V_361 :
return F_104 ( V_2 , V_342 ) ;
case V_205 :
return F_105 ( V_2 , V_342 ) ;
case V_211 :
return F_106 ( V_2 , V_342 ) ;
case V_365 :
return F_107 ( V_2 , V_342 ) ;
case V_368 :
return F_108 ( V_2 , V_342 ) ;
case V_371 :
return F_109 ( V_2 , V_342 ) ;
case V_372 :
return F_110 ( V_2 , V_342 ) ;
case V_390 :
case V_391 :
case V_392 :
case V_393 :
return F_111 ( V_2 , V_72 ) ;
}
return - V_347 ;
}
static int F_115 ( struct V_1 * V_2 , int V_107 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_3 V_4 ;
struct V_394 V_395 ;
memset ( & V_395 , 0 , sizeof( V_395 ) ) ;
V_395 . V_396 = 0x08 ;
V_395 . V_397 = ( V_107 >> 8 ) & 0xff ;
V_395 . V_398 = V_107 & 0xff ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_72 [ 0 ] = 0x15 ;
V_4 . V_72 [ 1 ] = 1 << 4 ;
V_4 . V_72 [ 4 ] = 12 ;
V_4 . V_108 = sizeof( V_395 ) ;
V_4 . V_68 = ( char * ) & V_395 ;
V_4 . V_224 = V_92 ;
V_395 . V_396 = 0x08 ;
V_395 . V_397 = ( V_107 >> 8 ) & 0xff ;
V_395 . V_398 = V_107 & 0xff ;
return V_13 -> V_41 ( V_2 , & V_4 ) ;
}
static T_12 int F_116 ( struct V_1 * V_2 ,
void T_10 * V_349 ,
struct V_3 * V_4 ,
int V_72 )
{
struct V_340 V_5 ;
struct V_363 V_219 ;
int V_315 = 0 , V_318 = 0 , V_218 ;
int V_86 ;
switch ( V_72 ) {
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
F_117 ( V_349 , struct V_363 , V_219 ) ;
V_218 = F_118 ( V_219 . V_403 , V_219 . V_404 , V_219 . V_405 ) ;
if ( V_218 < 0 )
return - V_20 ;
V_4 -> V_68 = F_50 ( V_315 , V_181 ) ;
if ( V_4 -> V_68 == NULL )
return - V_182 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_4 -> V_5 = & V_5 ;
V_4 -> V_224 = V_71 ;
V_86 = F_73 ( V_2 , V_4 , V_218 , 1 , V_318 , V_315 ) ;
if ( V_86 && V_5 . V_6 == 0x05 &&
V_5 . V_7 == 0x20 &&
V_5 . V_8 == 0x00 ) {
V_86 = F_115 ( V_2 , V_315 ) ;
if ( V_86 )
goto V_293;
V_4 -> V_5 = NULL ;
V_86 = F_72 ( V_2 , V_4 , V_218 , V_315 , 1 ) ;
V_86 |= F_115 ( V_2 , V_315 ) ;
}
if ( ! V_86 && F_75 ( V_349 , V_4 -> V_68 , V_315 ) )
V_86 = - V_328 ;
V_293:
F_51 ( V_4 -> V_68 ) ;
return V_86 ;
}
static T_12 int F_119 ( struct V_1 * V_2 ,
void T_10 * V_349 )
{
struct V_406 V_407 ;
int V_218 ;
F_117 ( V_349 , struct V_406 , V_407 ) ;
if ( V_407 . V_348 == V_207 )
V_218 = F_118 ( V_407 . V_215 . V_219 . V_222 ,
V_407 . V_215 . V_219 . V_221 ,
V_407 . V_215 . V_219 . V_220 ) ;
else if ( V_407 . V_348 == V_217 )
V_218 = V_407 . V_215 . V_218 ;
else
return - V_20 ;
if ( V_218 < 0 || V_407 . V_325 <= 0 || V_407 . V_325 > V_408 )
return - V_20 ;
return F_83 ( V_2 , V_407 . V_164 , V_218 , V_407 . V_325 ) ;
}
static T_12 int F_120 ( struct V_1 * V_2 ,
void T_10 * V_349 )
{
int V_86 ;
struct V_304 V_330 ;
T_5 V_216 , V_360 ;
F_117 ( V_349 , struct V_304 , V_330 ) ;
V_216 = V_330 . V_309 ;
if ( ! ( ( V_216 == V_207 ) ||
( V_216 == V_217 ) ) )
return - V_20 ;
V_330 . V_309 = V_207 ;
V_86 = F_71 ( V_2 , & V_330 , 0 ) ;
if ( V_86 )
return V_86 ;
V_360 = V_330 . V_309 ;
F_59 ( & V_330 . V_314 , & V_360 , V_216 ) ;
F_59 ( & V_330 . V_313 , & V_330 . V_309 , V_216 ) ;
F_121 ( V_349 , struct V_304 , V_330 ) ;
return 0 ;
}
static T_12 int F_122 ( struct V_1 * V_2 ,
void T_10 * V_349 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_363 V_219 ;
F_3 ( V_346 , L_99 ) ;
F_117 ( V_349 , struct V_363 , V_219 ) ;
V_4 -> V_72 [ 0 ] = V_409 ;
V_4 -> V_72 [ 3 ] = V_219 . V_403 ;
V_4 -> V_72 [ 4 ] = V_219 . V_404 ;
V_4 -> V_72 [ 5 ] = V_219 . V_405 ;
V_4 -> V_72 [ 6 ] = V_219 . V_410 ;
V_4 -> V_72 [ 7 ] = V_219 . V_411 ;
V_4 -> V_72 [ 8 ] = V_219 . V_412 ;
V_4 -> V_224 = V_95 ;
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
static T_12 int F_123 ( struct V_1 * V_2 ,
void T_10 * V_349 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_413 V_414 ;
F_3 ( V_346 , L_104 ) ;
F_117 ( V_349 , struct V_413 , V_414 ) ;
V_4 -> V_72 [ 0 ] = V_415 ;
V_4 -> V_72 [ 2 ] = ( V_414 . V_416 >> 24 ) & 0xff ;
V_4 -> V_72 [ 3 ] = ( V_414 . V_416 >> 16 ) & 0xff ;
V_4 -> V_72 [ 4 ] = ( V_414 . V_416 >> 8 ) & 0xff ;
V_4 -> V_72 [ 5 ] = V_414 . V_416 & 0xff ;
V_4 -> V_72 [ 7 ] = ( V_414 . V_223 >> 8 ) & 0xff ;
V_4 -> V_72 [ 8 ] = V_414 . V_223 & 0xff ;
V_4 -> V_224 = V_95 ;
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
static T_12 int F_124 ( struct V_1 * V_2 ,
void T_10 * V_349 ,
struct V_3 * V_4 ,
unsigned int V_72 )
{
struct V_369 V_417 ;
unsigned char V_68 [ 32 ] ;
char V_130 [ sizeof( V_68 ) ] ;
unsigned short V_106 ;
int V_86 ;
F_3 ( V_346 , L_105 ) ;
F_117 ( V_349 , struct V_369 , V_417 ) ;
V_4 -> V_68 = V_68 ;
V_4 -> V_108 = 24 ;
V_86 = F_17 ( V_2 , V_4 , V_418 , 0 ) ;
if ( V_86 )
return V_86 ;
V_106 = 8 + F_15 ( * ( T_2 * ) ( V_68 + 6 ) ) ;
if ( V_106 + 16 > sizeof( V_68 ) )
return - V_419 ;
if ( V_106 + 16 > V_4 -> V_108 ) {
V_4 -> V_108 = V_106 + 16 ;
V_86 = F_17 ( V_2 , V_4 ,
V_418 , 0 ) ;
if ( V_86 )
return V_86 ;
}
if ( ( V_68 [ V_106 ] & 0x3f ) != V_418 ||
V_68 [ V_106 + 1 ] < 14 )
return - V_20 ;
if ( V_72 == V_372 ) {
V_417 . V_420 = V_68 [ V_106 + 9 ] ;
V_417 . V_421 = V_68 [ V_106 + 11 ] ;
V_417 . V_422 = V_68 [ V_106 + 13 ] ;
V_417 . V_423 = V_68 [ V_106 + 15 ] ;
F_121 ( V_349 , struct V_369 , V_417 ) ;
return 0 ;
}
V_4 -> V_68 = V_130 ;
V_86 = F_17 ( V_2 , V_4 , V_418 , 1 ) ;
if ( V_86 )
return V_86 ;
V_68 [ V_106 + 9 ] = V_417 . V_420 & V_130 [ V_106 + 9 ] ;
V_68 [ V_106 + 11 ] = V_417 . V_421 & V_130 [ V_106 + 11 ] ;
V_68 [ V_106 + 13 ] = V_417 . V_422 & V_130 [ V_106 + 13 ] ;
V_68 [ V_106 + 15 ] = V_417 . V_423 & V_130 [ V_106 + 15 ] ;
V_4 -> V_68 = V_68 + V_106 - 8 ;
memset ( V_4 -> V_68 , 0 , 8 ) ;
return F_26 ( V_2 , V_4 ) ;
}
static T_12 int F_125 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_72 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_3 ( V_346 , L_106 ) ;
V_4 -> V_72 [ 0 ] = V_424 ;
V_4 -> V_72 [ 1 ] = 1 ;
V_4 -> V_72 [ 4 ] = ( V_72 == V_390 ) ? 1 : 0 ;
V_4 -> V_224 = V_95 ;
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
static T_12 int F_126 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_72 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
F_3 ( V_346 , L_107 ) ;
V_4 -> V_72 [ 0 ] = V_425 ;
V_4 -> V_72 [ 8 ] = ( V_72 == V_393 ) ? 1 : 0 ;
V_4 -> V_224 = V_95 ;
return V_13 -> V_41 ( V_2 , V_4 ) ;
}
static T_12 int F_127 ( struct V_1 * V_2 ,
void T_10 * V_349 ,
struct V_3 * V_4 )
{
int V_86 ;
T_8 * V_267 ;
int V_107 = sizeof( T_8 ) ;
if ( ! F_7 ( V_136 ) )
return - V_347 ;
V_267 = F_50 ( V_107 , V_181 ) ;
if ( ! V_267 )
return - V_182 ;
F_3 ( V_346 , L_108 ) ;
if ( F_85 ( V_267 , V_349 , V_107 ) ) {
F_51 ( V_267 ) ;
return - V_328 ;
}
V_86 = F_70 ( V_2 , V_267 , V_4 ) ;
if ( V_86 )
goto V_293;
if ( F_75 ( V_349 , V_267 , V_107 ) )
V_86 = - V_328 ;
V_293:
F_51 ( V_267 ) ;
return V_86 ;
}
static T_12 int F_128 ( struct V_1 * V_2 ,
void T_10 * V_349 )
{
int V_86 ;
T_6 V_229 ;
if ( ! F_7 ( V_136 ) )
return - V_347 ;
F_3 ( V_346 , L_109 ) ;
F_117 ( V_349 , T_6 , V_229 ) ;
V_86 = F_62 ( V_2 , & V_229 ) ;
if ( V_86 )
return V_86 ;
F_121 ( V_349 , T_6 , V_229 ) ;
return 0 ;
}
static T_12 int F_129 ( struct V_1 * V_2 ,
void T_10 * V_349 )
{
int V_86 ;
long V_426 = 0 ;
F_3 ( V_346 , L_110 ) ;
V_86 = F_130 ( V_2 , & V_426 ) ;
if ( V_86 )
return V_86 ;
F_121 ( V_349 , long , V_426 ) ;
return 0 ;
}
static T_12 int F_131 ( struct V_1 * V_2 ,
void T_10 * V_349 )
{
int V_86 ;
long V_427 = 0 ;
F_3 ( V_346 , L_111 ) ;
V_86 = F_132 ( V_2 , & V_427 ) ;
if ( V_86 )
return V_86 ;
F_121 ( V_349 , long , V_427 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , unsigned int V_72 ,
unsigned long V_349 )
{
struct V_3 V_4 ;
void T_10 * V_428 = ( void T_10 * ) V_349 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
switch ( V_72 ) {
case V_399 :
case V_400 :
case V_402 :
return F_116 ( V_2 , V_428 , & V_4 , V_72 ) ;
case V_429 :
return F_119 ( V_2 , V_428 ) ;
case V_361 :
return F_120 ( V_2 , V_428 ) ;
case V_365 :
return F_122 ( V_2 , V_428 , & V_4 ) ;
case V_430 :
return F_123 ( V_2 , V_428 , & V_4 ) ;
case V_371 :
case V_372 :
return F_124 ( V_2 , V_428 , & V_4 , V_72 ) ;
case V_390 :
case V_391 :
return F_125 ( V_2 , & V_4 , V_72 ) ;
case V_392 :
case V_393 :
return F_126 ( V_2 , & V_4 , V_72 ) ;
case V_431 :
return F_127 ( V_2 , V_428 , & V_4 ) ;
case V_432 :
return F_128 ( V_2 , V_428 ) ;
case V_433 :
return F_129 ( V_2 , V_428 ) ;
case V_434 :
return F_131 ( V_2 , V_428 ) ;
}
return - V_266 ;
}
static int F_133 ( struct V_1 * V_2 , T_13 V_435 , T_9 type ,
T_14 * V_367 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_3 V_4 ;
int V_86 , V_108 ;
F_14 ( & V_4 , V_367 , 8 , V_71 ) ;
V_4 . V_72 [ 0 ] = V_436 ;
V_4 . V_72 [ 1 ] = type & 3 ;
V_4 . V_72 [ 4 ] = ( V_435 & 0xff00 ) >> 8 ;
V_4 . V_72 [ 5 ] = V_435 & 0xff ;
V_4 . V_72 [ 8 ] = 8 ;
V_4 . V_74 = 1 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_108 = F_15 ( V_367 -> V_437 ) +
sizeof( V_367 -> V_437 ) ;
if ( V_108 > sizeof( T_14 ) )
V_108 = sizeof( T_14 ) ;
V_4 . V_72 [ 8 ] = V_4 . V_108 = V_108 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
return V_108 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 * V_98 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_3 V_4 ;
int V_86 , V_108 ;
F_14 ( & V_4 , V_98 , sizeof( * V_98 ) , V_71 ) ;
V_4 . V_72 [ 0 ] = V_438 ;
V_4 . V_72 [ 8 ] = V_4 . V_108 = 2 ;
V_4 . V_74 = 1 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
V_108 = F_15 ( V_98 -> V_439 ) +
sizeof( V_98 -> V_439 ) ;
if ( V_108 > sizeof( T_1 ) )
V_108 = sizeof( T_1 ) ;
V_4 . V_72 [ 8 ] = V_4 . V_108 = V_108 ;
if ( ( V_86 = V_13 -> V_41 ( V_2 , & V_4 ) ) )
return V_86 ;
return V_108 ;
}
int F_132 ( struct V_1 * V_2 , long * V_440 )
{
struct V_199 V_441 ;
T_1 V_98 ;
T_14 V_367 ;
T_15 V_442 ;
int V_86 = - 1 , V_443 ;
if ( ! F_7 ( V_42 ) )
goto V_444;
V_86 = F_22 ( V_2 , & V_98 ) ;
if ( V_86 < ( int ) ( F_23 ( F_24 ( V_98 ) , V_445 )
+ sizeof( V_98 . V_445 ) ) )
goto V_444;
V_442 = ( V_98 . V_446 << 8 ) | V_98 . V_445 ;
V_443 = F_133 ( V_2 , V_442 , 1 , & V_367 ) ;
if ( V_443 < ( int ) F_23 ( F_24 ( V_367 ) , V_447 ) )
goto V_444;
if ( V_367 . V_448 ) {
if ( V_442 == 1 )
goto V_444;
V_442 -- ;
V_443 = F_133 ( V_2 , V_442 , 1 , & V_367 ) ;
}
if ( V_443 < ( int ) ( F_23 ( F_24 ( V_367 ) , V_449 )
+ sizeof( V_367 . V_449 ) ) )
goto V_444;
if ( V_367 . V_450 && V_443 >= ( int ) ( F_23 ( F_24 ( V_367 ) , V_451 )
+ sizeof( V_367 . V_451 ) ) ) {
* V_440 = F_134 ( V_367 . V_451 ) ;
} else {
* V_440 = F_134 ( V_367 . V_447 ) +
F_134 ( V_367 . V_449 ) ;
if ( V_367 . V_452 )
* V_440 -= ( F_134 ( V_367 . V_452 ) + 7 ) ;
}
return 0 ;
V_444:
V_441 . V_206 = V_207 ;
V_441 . V_210 = V_453 ;
if ( ( V_86 = V_2 -> V_14 -> V_204 ( V_2 , V_211 , & V_441 ) ) )
return V_86 ;
F_59 ( & V_441 . V_362 , & V_441 . V_206 , V_217 ) ;
* V_440 = V_441 . V_362 . V_218 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , long * V_454 )
{
T_1 V_98 ;
T_14 V_367 ;
T_13 V_442 ;
int V_86 , V_443 ;
if ( ! F_7 ( V_42 ) )
goto V_455;
V_86 = F_22 ( V_2 , & V_98 ) ;
if ( V_86 < 0 || V_86 < F_23 ( F_24 ( V_98 ) , V_445 )
+ sizeof( V_98 . V_445 ) )
goto V_455;
V_442 = ( V_98 . V_446 << 8 ) | V_98 . V_445 ;
V_443 = F_133 ( V_2 , V_442 , 1 , & V_367 ) ;
if ( V_443 < 0 || V_443 < F_23 ( F_24 ( V_367 ) , V_447 ) )
goto V_455;
if ( V_367 . V_448 ) {
if ( V_442 == 1 )
goto V_455;
V_442 -- ;
V_443 = F_133 ( V_2 , V_442 , 1 , & V_367 ) ;
if ( V_443 < 0 )
goto V_455;
}
if ( V_367 . V_456 && V_443 >= F_23 ( F_24 ( V_367 ) , V_454 )
+ sizeof( V_367 . V_454 ) ) {
* V_454 = F_134 ( V_367 . V_454 ) ;
return 0 ;
}
V_455:
if ( ( V_86 = F_132 ( V_2 , V_454 ) ) ) {
* V_454 = 0 ;
return V_86 ;
} else {
* V_454 += 7 ;
return 0 ;
}
}
static int F_135 ( const char * V_198 , int V_457 , char * V_178 ,
int * V_458 , enum V_459 V_460 )
{
const int V_461 = sizeof( V_462 . V_178 ) ;
struct V_1 * V_2 ;
int V_86 ;
V_86 = F_136 ( V_178 + * V_458 , V_461 - * V_458 , V_198 ) ;
if ( ! V_86 )
return 1 ;
* V_458 += V_86 ;
F_137 (cdi, &cdrom_list, list) {
switch ( V_460 ) {
case V_463 :
V_86 = F_136 ( V_178 + * V_458 , V_461 - * V_458 ,
L_112 , V_2 -> V_62 ) ;
break;
case V_464 :
V_86 = F_136 ( V_178 + * V_458 , V_461 - * V_458 ,
L_113 , V_2 -> V_465 ) ;
break;
case V_466 :
V_86 = F_136 ( V_178 + * V_458 , V_461 - * V_458 ,
L_113 , V_2 -> V_174 ) ;
break;
case V_467 :
V_86 = F_136 ( V_178 + * V_458 , V_461 - * V_458 ,
L_113 , F_7 ( V_457 ) != 0 ) ;
break;
default:
F_4 ( L_114 , V_460 ) ;
return 1 ;
}
if ( ! V_86 )
return 1 ;
* V_458 += V_86 ;
}
return 0 ;
}
static int F_138 ( T_16 * V_468 , int V_83 ,
void T_10 * V_68 , T_17 * V_469 , T_18 * V_470 )
{
int V_458 ;
char * V_178 = V_462 . V_178 ;
const int V_461 = sizeof( V_462 . V_178 ) ;
if ( ! * V_469 || ( * V_470 && ! V_83 ) ) {
* V_469 = 0 ;
return 0 ;
}
F_8 ( & V_63 ) ;
V_458 = sprintf ( V_178 , L_115 V_471 L_3 ) ;
if ( F_135 ( L_116 , 0 , V_178 , & V_458 , V_463 ) )
goto V_472;
if ( F_135 ( L_117 , 0 , V_178 , & V_458 , V_464 ) )
goto V_472;
if ( F_135 ( L_118 , 0 , V_178 , & V_458 , V_466 ) )
goto V_472;
if ( F_135 ( L_119 ,
V_29 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_120 ,
V_30 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_121 ,
V_32 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_122 ,
V_34 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_123 ,
V_27 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_124 ,
V_36 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_125 ,
V_38 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_126 ,
V_26 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_127 ,
V_364 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_128 ,
V_134 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_129 ,
V_135 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_130 ,
V_136 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_131 ,
V_137 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_132 ,
V_133 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_133 ,
V_131 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_134 ,
V_55 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( F_135 ( L_135 ,
V_132 , V_178 , & V_458 , V_467 ) )
goto V_472;
if ( ! F_136 ( V_178 + V_458 , V_461 - V_458 , L_136 ) )
goto V_472;
V_473:
F_10 ( & V_63 ) ;
return F_139 ( V_468 , V_83 , V_68 , V_469 , V_470 ) ;
V_472:
F_4 ( L_137 ) ;
goto V_473;
}
static void F_140 ( void )
{
struct V_1 * V_2 ;
F_8 ( & V_63 ) ;
F_137 (cdi, &cdrom_list, list) {
if ( V_47 && F_7 ( V_29 ) )
V_2 -> V_45 |= V_48 ;
else if ( ! V_47 )
V_2 -> V_45 &= ~ V_48 ;
if ( V_49 && F_7 ( V_30 ) )
V_2 -> V_45 |= V_50 ;
else if ( ! V_49 )
V_2 -> V_45 &= ~ V_50 ;
if ( V_51 && F_7 ( V_32 ) )
V_2 -> V_45 |= V_52 ;
else if ( ! V_51 )
V_2 -> V_45 &= ~ V_52 ;
if ( V_53 )
V_2 -> V_45 |= V_54 ;
else
V_2 -> V_45 &= ~ V_54 ;
}
F_10 ( & V_63 ) ;
}
static int F_141 ( T_16 * V_468 , int V_83 ,
void T_10 * V_68 , T_17 * V_469 , T_18 * V_470 )
{
int V_86 ;
V_86 = F_142 ( V_468 , V_83 , V_68 , V_469 , V_470 ) ;
if ( V_83 ) {
V_47 = ! ! V_462 . V_47 ;
V_49 = ! ! V_462 . V_49 ;
V_353 = ! ! V_462 . V_353 ;
V_51 = ! ! V_462 . V_474 ;
V_53 = ! ! V_462 . V_475 ;
F_140 () ;
}
return V_86 ;
}
static void F_5 ( void )
{
static int V_476 ;
if ( V_476 == 1 )
return;
V_477 = F_143 ( V_478 ) ;
V_462 . V_47 = V_47 ;
V_462 . V_49 = V_49 ;
V_462 . V_353 = V_353 ;
V_462 . V_474 = V_51 ;
V_462 . V_475 = V_53 ;
V_476 = 1 ;
}
static void F_144 ( void )
{
if ( V_477 )
F_145 ( V_477 ) ;
}
static void F_5 ( void )
{
}
static void F_144 ( void )
{
}
static int T_19 F_146 ( void )
{
F_5 () ;
return 0 ;
}
static void T_20 F_147 ( void )
{
F_4 ( L_138 ) ;
F_144 () ;
}
