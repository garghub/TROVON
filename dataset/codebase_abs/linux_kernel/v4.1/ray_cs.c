static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
struct V_4 * V_5 ;
F_2 ( & V_2 -> V_5 , L_1 ) ;
V_5 = F_3 ( sizeof( T_1 ) ) ;
if ( ! V_5 )
goto V_6;
V_3 = F_4 ( V_5 ) ;
V_3 -> V_7 = V_2 ;
V_2 -> V_8 [ 0 ] -> V_9 = 0 ;
V_2 -> V_8 [ 0 ] -> V_10 |= V_11 ;
V_2 -> V_12 |= V_13 ;
V_2 -> V_14 = 1 ;
V_2 -> V_15 = V_5 ;
V_3 -> V_7 = V_2 ;
V_3 -> V_16 = V_17 ;
V_3 -> V_18 = V_19 ;
V_3 -> V_20 = 0 ;
F_2 ( & V_2 -> V_5 , L_2 ,
V_2 , V_5 , V_3 , & V_21 ) ;
V_5 -> V_22 = & V_23 ;
V_5 -> V_24 = & V_25 ;
#ifdef F_5
V_3 -> V_26 . V_27 = & V_3 -> V_27 ;
V_5 -> V_26 = & V_3 -> V_26 ;
#endif
F_2 ( & V_2 -> V_5 , L_3 ) ;
F_6 ( V_5 ) ;
F_7 ( & V_3 -> V_28 ) ;
V_29 = V_2 ;
return F_8 ( V_2 ) ;
V_6:
return - V_30 ;
}
static void F_9 ( struct V_1 * V_31 )
{
struct V_4 * V_5 ;
T_1 * V_3 ;
F_2 ( & V_31 -> V_5 , L_4 ) ;
V_29 = NULL ;
V_5 = V_31 -> V_15 ;
F_10 ( V_31 ) ;
V_3 = F_4 ( V_5 ) ;
F_11 ( & V_3 -> V_28 ) ;
if ( V_31 -> V_15 ) {
F_12 ( V_5 ) ;
F_13 ( V_5 ) ;
}
F_2 ( & V_31 -> V_5 , L_5 ) ;
}
static int F_8 ( struct V_1 * V_31 )
{
int V_32 = 0 ;
int V_33 ;
struct V_4 * V_5 = (struct V_4 * ) V_31 -> V_15 ;
T_1 * V_3 = F_4 ( V_5 ) ;
F_2 ( & V_31 -> V_5 , L_6 ) ;
F_14 ( V_34 L_7 ,
V_31 -> V_35 [ 0 ] ? V_31 -> V_35 [ 0 ] : L_8 ,
V_31 -> V_35 [ 1 ] ? V_31 -> V_35 [ 1 ] : L_8 ,
V_31 -> V_35 [ 2 ] ? V_31 -> V_35 [ 2 ] : L_8 ,
V_31 -> V_35 [ 3 ] ? V_31 -> V_35 [ 3 ] : L_8 ) ;
V_32 = F_15 ( V_31 , V_21 ) ;
if ( V_32 )
goto V_36;
V_5 -> V_37 = V_31 -> V_37 ;
V_32 = F_16 ( V_31 ) ;
if ( V_32 )
goto V_36;
V_31 -> V_8 [ 2 ] -> V_10 |= V_38 | V_39 | V_40 | V_41 ;
V_31 -> V_8 [ 2 ] -> V_42 = 0 ;
V_31 -> V_8 [ 2 ] -> V_9 = 0x8000 ;
V_32 = F_17 ( V_31 , V_31 -> V_8 [ 2 ] , V_43 ) ;
if ( V_32 )
goto V_36;
V_32 = F_18 ( V_31 , V_31 -> V_8 [ 2 ] , 0 ) ;
if ( V_32 )
goto V_36;
V_3 -> V_44 = F_19 ( V_31 -> V_8 [ 2 ] -> V_42 ,
F_20 ( V_31 -> V_8 [ 2 ] ) ) ;
V_31 -> V_8 [ 3 ] -> V_10 |=
V_38 | V_39 | V_40 | V_41 ;
V_31 -> V_8 [ 3 ] -> V_42 = 0 ;
V_31 -> V_8 [ 3 ] -> V_9 = 0x4000 ;
V_32 = F_17 ( V_31 , V_31 -> V_8 [ 3 ] , V_43 ) ;
if ( V_32 )
goto V_36;
V_32 = F_18 ( V_31 , V_31 -> V_8 [ 3 ] , 0x8000 ) ;
if ( V_32 )
goto V_36;
V_3 -> V_45 = F_19 ( V_31 -> V_8 [ 3 ] -> V_42 ,
F_20 ( V_31 -> V_8 [ 3 ] ) ) ;
V_31 -> V_8 [ 4 ] -> V_10 |=
V_38 | V_46 | V_40 | V_41 ;
V_31 -> V_8 [ 4 ] -> V_42 = 0 ;
V_31 -> V_8 [ 4 ] -> V_9 = 0x1000 ;
V_32 = F_17 ( V_31 , V_31 -> V_8 [ 4 ] , V_43 ) ;
if ( V_32 )
goto V_36;
V_32 = F_18 ( V_31 , V_31 -> V_8 [ 4 ] , 0 ) ;
if ( V_32 )
goto V_36;
V_3 -> V_47 = F_19 ( V_31 -> V_8 [ 4 ] -> V_42 ,
F_20 ( V_31 -> V_8 [ 4 ] ) ) ;
F_2 ( & V_31 -> V_5 , L_9 , V_3 -> V_44 ) ;
F_2 ( & V_31 -> V_5 , L_10 , V_3 -> V_45 ) ;
F_2 ( & V_31 -> V_5 , L_11 , V_3 -> V_47 ) ;
if ( F_21 ( V_5 ) < 0 ) {
F_10 ( V_31 ) ;
return - V_48 ;
}
F_22 ( V_5 , & V_31 -> V_5 ) ;
V_33 = F_23 ( V_5 ) ;
if ( V_33 != 0 ) {
F_14 ( L_12 ) ;
F_10 ( V_31 ) ;
return V_33 ;
}
F_14 ( V_34 L_13 ,
V_5 -> V_49 , V_5 -> V_37 , V_5 -> V_50 ) ;
return 0 ;
V_36:
F_10 ( V_31 ) ;
return - V_48 ;
}
static inline struct V_51 T_2 * F_24 ( T_1 * V_5 )
{
return V_5 -> V_44 + V_52 ;
}
static inline struct V_53 T_2 * F_25 ( T_1 * V_5 )
{
return V_5 -> V_44 + V_52 ;
}
static int F_21 ( struct V_4 * V_5 )
{
int V_33 ;
T_3 * V_54 ;
struct V_51 T_2 * V_55 ;
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_14 , V_5 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_15 ) ;
return - 1 ;
}
V_3 -> V_56 = V_56 ;
V_3 -> V_57 = V_58 ;
F_27 ( & V_3 -> V_59 , V_3 -> V_44 + V_60 ,
sizeof( struct V_61 ) ) ;
if ( V_3 -> V_59 . V_62 != 0x80 ) {
F_14 ( V_34 L_16 ,
V_3 -> V_59 . V_62 ) ;
V_3 -> V_16 = V_63 ;
return - 1 ;
}
V_3 -> V_64 = V_3 -> V_59 . V_65 [ 0 ] ;
V_3 -> V_66 = V_3 -> V_59 . V_65 [ 1 ] ;
V_3 -> V_67 = V_3 -> V_59 . V_65 [ 2 ] ;
F_2 ( & V_31 -> V_5 , L_17 , V_3 -> V_64 ,
V_3 -> V_66 ) ;
V_3 -> V_68 = 0x20 ;
if ( ( V_3 -> V_64 == 5 ) && ( V_3 -> V_66 >= 30 ) )
V_3 -> V_68 = V_3 -> V_59 . V_68 ;
F_2 ( & V_31 -> V_5 , L_18 , V_3 -> V_68 ) ;
V_55 = F_24 ( V_3 ) ;
for ( V_33 = 0 ; V_33 < V_69 ; V_33 ++ ) {
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
}
F_29 ( V_3 ) ;
if ( F_30 ( V_72 , V_3 -> V_73 . V_74 . V_75 ) ) {
V_54 = V_3 -> V_73 . V_74 . V_75 ;
} else {
memcpy ( & V_3 -> V_73 . V_74 . V_75 ,
& V_3 -> V_59 . V_76 , V_77 ) ;
V_54 = V_3 -> V_73 . V_74 . V_75 ;
}
F_31 ( V_3 ) ;
V_3 -> V_16 = V_78 ;
F_2 ( & V_31 -> V_5 , L_19 ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 )
{
int V_79 ;
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_51 T_2 * V_55 ;
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_20 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_21 ) ;
return - 1 ;
}
if ( V_3 -> V_64 == 0x55 )
F_33 ( V_3 -> V_44 + V_80 , & V_3 -> V_73 . V_74 ,
sizeof( struct V_81 ) ) ;
else
F_33 ( V_3 -> V_44 + V_80 , & V_3 -> V_73 . V_82 ,
sizeof( struct V_83 ) ) ;
if ( ( V_79 = F_34 ( V_3 ) ) < 0 )
return - 1 ;
V_3 -> V_84 = V_79 ;
V_55 = F_24 ( V_3 ) + V_79 ;
F_28 ( V_85 , & V_55 -> V_86 ) ;
F_2 ( & V_31 -> V_5 , L_22 ,
V_3 -> V_84 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_14 ( V_34 L_23
L_24 ) ;
V_3 -> V_16 = V_87 ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
return - 2 ;
}
V_3 -> V_16 = V_88 ;
V_3 -> V_28 . V_89 = V_90 + V_91 / 2 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
V_3 -> V_28 . V_93 = V_94 ;
F_36 ( & V_3 -> V_28 ) ;
F_2 ( & V_31 -> V_5 ,
L_25 ) ;
return 0 ;
}
static void F_29 ( T_1 * V_3 )
{
int V_33 ;
if ( V_95 > V_96 )
V_95 = V_97 ;
else if ( V_95 < V_97 )
V_95 = V_97 ;
if ( V_3 -> V_64 == 0x55 ) {
memcpy ( ( T_3 * ) & V_3 -> V_73 . V_74 , V_98 ,
sizeof( struct V_81 ) ) ;
V_33 = ( V_99 * 1024 ) & 0xffffff ;
V_3 -> V_73 . V_74 . V_100 [ 0 ] = ( V_33 >> 16 ) & 0xff ;
V_3 -> V_73 . V_74 . V_100 [ 1 ] = ( V_33 >> 8 ) & 0xff ;
V_3 -> V_73 . V_74 . V_101 [ 0 ] = 0 ;
V_3 -> V_73 . V_74 . V_101 [ 1 ] =
( ( V_102 / V_99 ) - 1 ) & 0xff ;
V_3 -> V_73 . V_74 . V_103 = V_95 ;
V_3 -> V_73 . V_74 . V_104 =
V_105 [ ( int ) V_95 ] - 1 ;
if ( V_106 ) {
V_3 -> V_73 . V_74 . V_107 = 0x50 ;
V_3 -> V_73 . V_74 . V_108 = 0x3f ;
}
} else {
memcpy ( ( T_3 * ) & V_3 -> V_73 . V_82 , V_109 ,
sizeof( struct V_83 ) ) ;
V_3 -> V_73 . V_82 . V_100 [ 0 ] = ( V_99 >> 8 ) & 0xff ;
V_3 -> V_73 . V_82 . V_100 [ 1 ] = V_99 & 0xff ;
V_3 -> V_73 . V_82 . V_101 [ 0 ] =
( V_102 >> 8 ) & 0xff ;
V_3 -> V_73 . V_82 . V_101 [ 1 ] = V_102 & 0xff ;
if ( V_110 )
V_3 -> V_73 . V_82 . V_111 = 1 ;
V_3 -> V_73 . V_82 . V_103 = V_95 ;
V_3 -> V_73 . V_82 . V_104 =
V_105 [ ( int ) V_95 ] ;
}
V_3 -> V_73 . V_74 . V_112 = V_56 & 0x01 ;
V_3 -> V_73 . V_74 . V_113 = V_58 ;
if ( V_114 != NULL )
strncpy ( V_3 -> V_73 . V_74 . V_115 , V_114 , V_116 ) ;
}
static void V_94 ( T_4 V_92 )
{
T_1 * V_3 = ( T_1 * ) V_92 ;
struct V_51 T_2 * V_55 = F_24 ( V_3 ) + V_3 -> V_84 ;
T_3 V_117 ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_26 ) ;
return;
}
#if 0
{
int i;
printk(KERN_DEBUG
"verify_dl_startup parameters sent via ccs %d:\n",
local->dl_param_ccs);
for (i = 0; i < sizeof(struct b5_startup_params); i++) {
printk(" %2x",
(unsigned int)readb(local->sram +
HOST_TO_ECF_BASE + i));
}
printk("\n");
}
#endif
V_117 = F_37 ( & V_55 -> V_71 ) ;
if ( V_117 != V_70 ) {
F_14 ( V_34
L_27 ,
V_117 ) ;
V_3 -> V_16 = V_87 ;
return;
}
if ( V_3 -> V_73 . V_74 . V_112 == V_118 )
F_38 ( ( T_4 ) V_3 ) ;
else
F_39 ( ( T_4 ) V_3 ) ;
}
static void F_38 ( T_4 V_92 )
{
T_1 * V_3 = ( T_1 * ) V_92 ;
struct V_51 T_2 * V_55 ;
int V_79 ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_28 ) ;
return;
}
if ( ( V_79 = F_34 ( V_3 ) ) < 0 )
return;
V_55 = F_24 ( V_3 ) + V_79 ;
F_28 ( V_119 , & V_55 -> V_86 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_121 . V_122 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_29 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
return;
}
V_3 -> V_16 = V_123 ;
}
static void F_39 ( T_4 V_92 )
{
T_1 * V_3 = ( T_1 * ) V_92 ;
struct V_51 T_2 * V_55 ;
int V_79 ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_30 ) ;
return;
}
if ( ( V_79 = F_34 ( V_3 ) ) < 0 )
return;
V_55 = F_24 ( V_3 ) + V_79 ;
F_28 ( V_124 , & V_55 -> V_86 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_125 . V_122 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_125 . V_126 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_31 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
return;
}
V_3 -> V_16 = V_123 ;
}
static void F_10 ( struct V_1 * V_31 )
{
struct V_4 * V_5 = V_31 -> V_15 ;
T_1 * V_3 = F_4 ( V_5 ) ;
F_2 ( & V_31 -> V_5 , L_32 ) ;
F_40 ( & V_3 -> V_28 ) ;
F_41 ( V_3 -> V_44 ) ;
F_41 ( V_3 -> V_45 ) ;
F_41 ( V_3 -> V_47 ) ;
F_42 ( V_31 ) ;
F_2 ( & V_31 -> V_5 , L_33 ) ;
}
static int F_43 ( struct V_1 * V_31 )
{
struct V_4 * V_5 = V_31 -> V_15 ;
if ( V_31 -> V_127 )
F_44 ( V_5 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_31 )
{
struct V_4 * V_5 = V_31 -> V_15 ;
if ( V_31 -> V_127 ) {
F_46 ( V_5 ) ;
F_47 ( V_5 ) ;
}
return 0 ;
}
static int F_48 ( struct V_4 * V_5 )
{
#ifdef F_49
int V_33 ;
#endif
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_34 , V_5 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_35 ) ;
return - 1 ;
}
#ifdef F_49
if ( ( V_33 = F_32 ( V_5 ) ) < 0 ) {
F_14 ( V_34 L_36
L_37 , V_33 ) ;
return - 1 ;
}
#else
F_2 ( & V_31 -> V_5 ,
L_38 ,
V_3 -> V_16 ) ;
#endif
memcpy ( V_5 -> V_50 , & V_3 -> V_73 . V_74 . V_75 , V_77 ) ;
F_50 ( V_5 -> V_128 ) ;
F_2 ( & V_31 -> V_5 , L_39 ) ;
return 0 ;
}
static int F_51 ( struct V_4 * V_5 , struct V_129 * V_130 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_40 , V_5 , V_130 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
static T_5 F_52 ( struct V_131 * V_132 ,
struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
short V_133 = V_132 -> V_134 ;
if ( ! F_26 ( V_31 ) ) {
F_2 ( & V_31 -> V_5 , L_42 ) ;
F_53 ( V_132 ) ;
return V_135 ;
}
F_2 ( & V_31 -> V_5 , L_43 , V_132 , V_5 ) ;
if ( V_3 -> V_18 == V_136 ) {
F_2 ( & V_31 -> V_5 , L_44 ) ;
if ( ! F_54 ( V_3 , V_3 -> V_137 , V_138 ) ) {
V_3 -> V_18 = V_139 ;
F_6 ( V_5 ) ;
return V_140 ;
}
}
if ( V_133 < V_141 ) {
if ( F_55 ( V_132 , V_141 ) )
return V_135 ;
V_133 = V_141 ;
}
switch ( F_56 ( V_132 -> V_92 , V_133 , V_5 , V_142 ) ) {
case V_143 :
case V_144 :
F_6 ( V_5 ) ;
return V_140 ;
case V_145 :
case V_146 :
case V_147 :
default:
F_53 ( V_132 ) ;
}
return V_135 ;
}
static int F_56 ( unsigned char * V_92 , int V_134 , struct V_4 * V_5 ,
T_3 V_148 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_51 T_2 * V_55 ;
int V_79 ;
int V_149 ;
struct V_150 T_2 * V_151 ;
short int V_152 ;
F_57 ( L_45 , V_92 , V_134 , V_5 ) ;
if ( V_134 + V_153 > V_154 ) {
F_14 ( V_34 L_46 ,
V_134 ) ;
return V_146 ;
}
switch ( V_79 = F_58 ( V_3 ) ) {
case V_155 :
F_57 ( L_47 ) ;
case V_156 :
F_57 ( L_48 ) ;
case V_157 :
F_6 ( V_5 ) ;
return V_143 ;
default:
break;
}
V_152 = V_158 + ( V_79 << 11 ) ;
if ( V_148 == V_142 ) {
V_3 -> V_159 . V_160 += V_134 ;
V_3 -> V_159 . V_161 ++ ;
}
V_151 = V_3 -> V_44 + V_152 ;
F_59 ( V_3 , V_151 , V_148 , V_92 ) ;
if ( V_162 ) {
V_149 = F_60 ( V_3 , V_151 , V_92 , V_134 ) ;
} else {
F_33 ( & V_151 -> V_120 , V_92 , V_134 ) ;
V_149 = 0 ;
}
V_55 = F_24 ( V_3 ) + V_79 ;
V_134 += V_153 + V_149 ;
F_28 ( V_163 , & V_55 -> V_86 ) ;
F_28 ( V_152 >> 8 , & V_55 -> V_120 . V_164 . V_165 [ 0 ] ) ;
F_28 ( V_3 -> V_68 , & V_55 -> V_120 . V_164 . V_165 [ 1 ] ) ;
F_28 ( V_134 >> 8 , & V_55 -> V_120 . V_164 . V_166 [ 0 ] ) ;
F_28 ( V_134 & 0xff , & V_55 -> V_120 . V_164 . V_166 [ 1 ] ) ;
F_28 ( V_167 , & V_55 -> V_120 . V_164 . V_168 ) ;
F_28 ( V_3 -> V_169 , & V_55 -> V_120 . V_164 . V_170 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_164 . V_171 ) ;
F_57 ( L_49 ,
V_3 -> V_169 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_57 ( L_50 ) ;
F_28 ( V_70 , & V_55 -> V_71 ) ;
return V_145 ;
}
return V_147 ;
}
static int F_60 ( T_1 * V_3 , struct V_150 T_2 * V_151 ,
unsigned char * V_92 , int V_134 )
{
T_6 V_172 = ( (struct V_173 * ) V_92 ) -> V_174 ;
if ( F_61 ( V_172 ) >= V_175 ) {
F_57 ( L_51 ) ;
F_33 ( & V_151 -> V_120 , V_176 , sizeof( V_176 ) ) ;
F_33 ( ( ( void T_2 * ) & V_151 -> V_120 ) + sizeof( V_176 ) ,
( T_3 * ) & V_172 , 2 ) ;
if ( V_172 == F_62 ( V_177 ) || V_172 == F_62 ( V_178 ) ) {
F_28 ( 0xf8 ,
& ( (struct V_179 T_2 * ) V_151 -> V_120 ) -> V_180 [ 3 ] ) ;
}
F_33 ( ( void T_2 * ) & V_151 -> V_120 +
sizeof( struct V_179 ) , V_92 + V_181 ,
V_134 - V_181 ) ;
return ( int ) sizeof( struct V_179 ) - V_181 ;
} else {
F_57 ( L_52 ) ;
if ( V_172 == F_62 ( 0xffff ) ) {
F_57 ( L_53 ) ;
F_33 ( & V_151 -> V_120 , V_92 + V_181 , V_134 - V_181 ) ;
return 0 - V_181 ;
}
F_33 ( & V_151 -> V_120 , V_92 + V_181 , V_134 - V_181 ) ;
return 0 - V_181 ;
}
}
static void F_59 ( T_1 * V_3 , struct V_150 T_2 * V_151 ,
T_3 V_148 , unsigned char * V_92 )
{
F_28 ( V_182 | V_148 , & V_151 -> V_183 . V_184 ) ;
if ( V_3 -> V_56 == V_118 ) {
F_28 ( 0 , & V_151 -> V_183 . V_185 ) ;
F_33 ( V_151 -> V_183 . V_186 , ( (struct V_173 * ) V_92 ) -> V_187 ,
2 * V_77 ) ;
F_33 ( V_151 -> V_183 . V_188 , V_3 -> V_189 , V_77 ) ;
} else {
if ( V_3 -> V_73 . V_74 . V_113 ) {
F_28 ( V_190 , & V_151 -> V_183 . V_185 ) ;
F_33 ( V_151 -> V_183 . V_186 ,
( (struct V_173 * ) V_92 ) -> V_187 , V_77 ) ;
F_33 ( V_151 -> V_183 . V_191 , V_3 -> V_189 , 6 ) ;
F_33 ( V_151 -> V_183 . V_188 ,
( (struct V_173 * ) V_92 ) -> V_192 , V_77 ) ;
} else {
F_28 ( V_193 , & V_151 -> V_183 . V_185 ) ;
F_33 ( V_151 -> V_183 . V_186 , V_3 -> V_189 , V_77 ) ;
F_33 ( V_151 -> V_183 . V_191 ,
( (struct V_173 * ) V_92 ) -> V_192 , V_77 ) ;
F_33 ( V_151 -> V_183 . V_188 ,
( (struct V_173 * ) V_92 ) -> V_187 , V_77 ) ;
}
}
}
static int F_63 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
strcpy ( V_197 -> V_49 , L_54 ) ;
return 0 ;
}
static int F_64 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_199 = - V_200 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( ( V_197 -> V_202 . V_203 > V_204 ) || ( V_197 -> V_202 . V_205 > 0 ) )
V_199 = - V_206 ;
else
V_3 -> V_73 . V_82 . V_207 = V_197 -> V_202 . V_203 ;
return V_199 ;
}
static int F_65 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_202 . V_203 = V_3 -> V_73 . V_82 . V_207 ;
V_197 -> V_202 . V_205 = 0 ;
return 0 ;
}
static int F_66 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_114 . V_10 == 0 )
return - V_206 ;
if ( V_197 -> V_114 . V_133 > V_208 )
return - V_209 ;
memset ( V_3 -> V_73 . V_82 . V_115 , 0 , V_208 ) ;
memcpy ( V_3 -> V_73 . V_82 . V_115 , V_198 , V_197 -> V_114 . V_133 ) ;
return - V_200 ;
}
static int F_67 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
T_3 V_210 [ V_208 + 1 ] ;
memcpy ( V_198 , V_3 -> V_73 . V_82 . V_115 , V_208 ) ;
memcpy ( V_210 , V_3 -> V_73 . V_82 . V_115 , V_208 ) ;
V_210 [ V_208 ] = '\0' ;
V_197 -> V_114 . V_133 = strlen ( V_210 ) ;
V_197 -> V_114 . V_10 = 1 ;
return 0 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
memcpy ( V_197 -> V_211 . V_212 , V_3 -> V_189 , V_213 ) ;
V_197 -> V_211 . V_214 = V_215 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( ( V_197 -> V_216 . V_217 != 1000000 ) && ( V_197 -> V_216 . V_217 != 2000000 ) )
return - V_218 ;
if ( ( V_3 -> V_64 == 0x55 ) &&
( V_197 -> V_216 . V_217 == 2000000 ) )
V_3 -> V_169 = 3 ;
else
V_3 -> V_169 = V_197 -> V_216 . V_217 / 500000 ;
return 0 ;
}
static int F_70 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_169 == 3 )
V_197 -> V_216 . V_217 = 2000000 ;
else
V_197 -> V_216 . V_217 = V_3 -> V_169 * 500000 ;
V_197 -> V_216 . V_219 = 0 ;
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_220 = V_197 -> V_221 . V_217 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_221 . V_222 )
V_220 = 32767 ;
else {
if ( ( V_220 < 0 ) || ( V_220 > 2347 ) )
return - V_218 ;
}
V_3 -> V_73 . V_82 . V_223 [ 0 ] = ( V_220 >> 8 ) & 0xFF ;
V_3 -> V_73 . V_82 . V_223 [ 1 ] = V_220 & 0xFF ;
return - V_200 ;
}
static int F_72 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_221 . V_217 = ( V_3 -> V_73 . V_82 . V_223 [ 0 ] << 8 )
+ V_3 -> V_73 . V_82 . V_223 [ 1 ] ;
V_197 -> V_221 . V_222 = ( V_197 -> V_221 . V_217 == 32767 ) ;
V_197 -> V_221 . V_219 = 1 ;
return 0 ;
}
static int F_73 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_224 = V_197 -> V_225 . V_217 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_225 . V_222 )
V_224 = 32767 ;
else {
if ( ( V_224 < 256 ) || ( V_224 > 2347 ) )
return - V_218 ;
}
V_3 -> V_73 . V_82 . V_226 [ 0 ] = ( V_224 >> 8 ) & 0xFF ;
V_3 -> V_73 . V_82 . V_226 [ 1 ] = V_224 & 0xFF ;
return - V_200 ;
}
static int F_74 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_225 . V_217 = ( V_3 -> V_73 . V_82 . V_226 [ 0 ] << 8 )
+ V_3 -> V_73 . V_82 . V_226 [ 1 ] ;
V_197 -> V_225 . V_222 = ( V_197 -> V_225 . V_217 == 32767 ) ;
V_197 -> V_225 . V_219 = 1 ;
return 0 ;
}
static int F_75 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_199 = - V_200 ;
char V_227 = 1 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
switch ( V_197 -> V_228 ) {
case V_229 :
V_227 = 0 ;
case V_230 :
V_3 -> V_73 . V_82 . V_112 = V_227 ;
break;
default:
V_199 = - V_218 ;
}
return V_199 ;
}
static int F_76 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_73 . V_82 . V_112 )
V_197 -> V_228 = V_230 ;
else
V_197 -> V_228 = V_229 ;
return 0 ;
}
static int F_77 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
struct V_231 * V_232 = (struct V_231 * ) V_198 ;
memset ( V_232 , 0 , sizeof( struct V_231 ) ) ;
V_197 -> V_92 . V_133 = sizeof( struct V_231 ) ;
V_232 -> V_233 = V_234 ;
V_232 -> V_235 = 9 ;
V_232 -> V_236 = 1.1 * 1000 * 1000 ;
V_232 -> V_237 = V_105 [ ( int ) V_95 ] ;
V_232 -> V_238 = 0 ;
V_232 -> V_239 . V_240 = 0 ;
V_232 -> V_239 . V_241 = 255 ;
V_232 -> V_239 . V_242 = 255 ;
V_232 -> V_243 = 2 ;
V_232 -> V_216 [ 0 ] = 1000000 ;
V_232 -> V_216 [ 1 ] = 2000000 ;
return 0 ;
}
static int F_78 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
V_162 = ! ! * ( V_198 ) ;
return 0 ;
}
static int F_79 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
* ( V_198 ) = V_162 ;
return 0 ;
}
static int F_80 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
* ( V_198 ) = V_95 ;
return 0 ;
}
static int F_81 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
return 0 ;
}
static T_7 * F_82 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
struct V_117 T_2 * V_54 = V_3 -> V_44 + V_244 ;
V_3 -> V_245 . V_117 = V_3 -> V_16 ;
#ifdef F_5
if ( ( V_3 -> V_27 . V_246 > 0 )
&& ( V_3 -> V_73 . V_82 . V_112 == 0 ) ) {
V_3 -> V_245 . V_240 . V_240 = V_3 -> V_27 . V_247 [ 0 ] . V_240 ;
V_3 -> V_245 . V_240 . V_241 = V_3 -> V_27 . V_247 [ 0 ] . V_241 ;
V_3 -> V_245 . V_240 . V_242 = V_3 -> V_27 . V_247 [ 0 ] . V_242 ;
V_3 -> V_245 . V_240 . V_248 =
V_3 -> V_27 . V_247 [ 0 ] . V_248 ;
}
#endif
if ( F_26 ( V_31 ) ) {
V_3 -> V_245 . V_240 . V_242 = F_37 ( & V_54 -> V_249 ) ;
V_3 -> V_245 . V_240 . V_248 |= 4 ;
}
return & V_3 -> V_245 ;
}
static int F_83 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 ;
V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_55 , V_5 -> V_49 ) ;
if ( V_31 -> V_127 == 0 )
V_3 -> V_20 = 0 ;
V_31 -> V_127 ++ ;
if ( V_3 -> V_16 == V_78 ) {
int V_33 ;
F_2 ( & V_31 -> V_5 , L_56 ) ;
if ( ( V_33 = F_32 ( V_5 ) ) < 0 ) {
F_14 ( V_34
L_36
L_37 , V_33 ) ;
return - 1 ;
}
}
if ( V_250 )
F_6 ( V_5 ) ;
else
F_84 ( V_5 ) ;
F_2 ( & V_31 -> V_5 , L_57 ) ;
return 0 ;
}
static int F_85 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 ;
V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_58 , V_5 -> V_49 ) ;
V_31 -> V_127 -- ;
F_6 ( V_5 ) ;
return 0 ;
}
static void F_46 ( struct V_4 * V_5 )
{
F_57 ( L_59 ) ;
}
static int F_35 ( T_1 * V_3 , int V_51 )
{
int V_33 = 50 ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_60 ) ;
return - 1 ;
}
F_2 ( & V_31 -> V_5 , L_61 , V_3 , V_51 ) ;
while ( V_33 &&
( F_37 ( V_3 -> V_47 + V_251 + V_252 ) &
V_253 ) )
V_33 -- ;
if ( V_33 == 0 ) {
F_2 ( & V_31 -> V_5 , L_62 ) ;
return - 1 ;
}
F_28 ( V_51 , V_3 -> V_44 + V_254 ) ;
F_28 ( V_253 , V_3 -> V_47 + V_251 + V_252 ) ;
return 0 ;
}
static int F_58 ( T_1 * V_3 )
{
int V_33 ;
struct V_51 T_2 * V_55 = F_24 ( V_3 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_63 ) ;
return V_157 ;
}
if ( F_86 ( 0 , & V_3 -> V_255 ) ) {
F_2 ( & V_31 -> V_5 , L_64 ) ;
return V_155 ;
}
for ( V_33 = 0 ; V_33 < V_256 ; V_33 ++ ) {
if ( F_37 ( & ( V_55 + V_33 ) -> V_71 ) == V_70 ) {
F_28 ( V_257 , & ( V_55 + V_33 ) -> V_71 ) ;
F_28 ( V_258 , & ( V_55 + V_33 ) -> V_31 ) ;
V_3 -> V_255 = 0 ;
return V_33 ;
}
}
V_3 -> V_255 = 0 ;
F_2 ( & V_31 -> V_5 , L_65 ) ;
return V_156 ;
}
static int F_34 ( T_1 * V_3 )
{
int V_33 ;
struct V_51 T_2 * V_55 = F_24 ( V_3 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_66 ) ;
return V_157 ;
}
if ( F_86 ( 0 , & V_3 -> V_259 ) ) {
F_2 ( & V_31 -> V_5 , L_67 ) ;
return V_155 ;
}
for ( V_33 = V_256 ; V_33 < V_69 ; V_33 ++ ) {
if ( F_37 ( & ( V_55 + V_33 ) -> V_71 ) == V_70 ) {
F_28 ( V_257 , & ( V_55 + V_33 ) -> V_71 ) ;
F_28 ( V_258 , & ( V_55 + V_33 ) -> V_31 ) ;
V_3 -> V_259 = 0 ;
return V_33 ;
}
}
V_3 -> V_259 = 0 ;
F_2 ( & V_31 -> V_5 , L_68 ) ;
return V_156 ;
}
static void F_87 ( T_4 V_92 )
{
T_1 * V_3 = ( T_1 * ) V_92 ;
F_40 ( & V_3 -> V_28 ) ;
F_14 ( V_34 L_69
L_70 ) ;
F_39 ( ( T_4 ) V_3 ) ;
}
static int F_30 ( char * V_260 , T_3 * V_261 )
{
int V_134 ;
int V_33 , V_262 , V_263 ;
int V_117 ;
if ( V_260 == NULL )
return 0 ;
if ( ( V_134 = strlen ( V_260 ) ) < 2 )
return 0 ;
memset ( V_261 , 0 , V_77 ) ;
V_117 = 1 ;
V_262 = V_134 - 1 ;
if ( V_262 > 12 )
V_262 = 12 ;
V_33 = 5 ;
while ( V_262 > 0 ) {
if ( ( V_263 = F_88 ( V_260 [ V_262 -- ] ) ) != - 1 )
V_261 [ V_33 ] = V_263 ;
else
return 0 ;
if ( V_262 == 0 )
break;
if ( ( V_263 = F_88 ( V_260 [ V_262 -- ] ) ) != - 1 )
V_261 [ V_33 ] += V_263 << 4 ;
else
return 0 ;
if ( ! V_33 -- )
break;
}
return V_117 ;
}
static struct V_264 * F_89 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
struct V_117 T_2 * V_54 = V_3 -> V_44 + V_244 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_71 ) ;
return & V_3 -> V_159 ;
}
if ( F_37 ( & V_54 -> V_265 ) ) {
V_3 -> V_159 . V_266 += F_90 ( F_91 ( & V_54 -> V_267 ) ) ;
F_28 ( 0 , & V_54 -> V_267 ) ;
F_28 ( 0 , & V_54 -> V_265 ) ;
}
if ( F_37 ( & V_54 -> V_268 ) ) {
V_3 -> V_159 . V_269 +=
F_90 ( F_91 ( & V_54 -> V_270 ) ) ;
F_28 ( 0 , & V_54 -> V_270 ) ;
F_28 ( 0 , & V_54 -> V_268 ) ;
}
if ( F_37 ( & V_54 -> V_271 ) ) {
V_3 -> V_159 . V_272 += F_90 ( F_91 ( & V_54 -> V_273 ) ) ;
F_28 ( 0 , & V_54 -> V_273 ) ;
F_28 ( 0 , & V_54 -> V_271 ) ;
}
return & V_3 -> V_159 ;
}
static void F_92 ( struct V_4 * V_5 , T_3 V_274 , T_3 * V_217 ,
int V_134 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
int V_79 ;
int V_33 ;
struct V_51 T_2 * V_55 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_72 ) ;
return;
}
if ( ( V_79 = F_34 ( V_3 ) ) < 0 ) {
F_2 ( & V_31 -> V_5 , L_73 ) ;
return;
}
V_55 = F_24 ( V_3 ) + V_79 ;
F_28 ( V_275 , & V_55 -> V_86 ) ;
F_28 ( V_274 , & V_55 -> V_120 . V_122 . V_276 ) ;
F_28 ( 1 , & V_55 -> V_120 . V_122 . V_277 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_122 . V_278 ) ;
for ( V_33 = 0 ; V_33 < V_134 ; V_33 ++ ) {
F_28 ( V_217 [ V_33 ] , V_3 -> V_44 + V_80 ) ;
}
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_74 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
}
}
static void F_93 ( struct V_4 * V_5 , int V_279 )
{
int V_79 ;
struct V_51 T_2 * V_55 ;
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
void T_2 * V_54 = V_3 -> V_44 + V_80 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_75 ) ;
return;
} else
F_2 ( & V_31 -> V_5 , L_76 , V_5 ) ;
if ( ( V_79 = F_34 ( V_3 ) ) < 0 ) {
F_2 ( & V_31 -> V_5 , L_77 ) ;
return;
}
V_55 = F_24 ( V_3 ) + V_79 ;
F_28 ( V_280 , & V_55 -> V_86 ) ;
if ( V_279 ) {
F_28 ( 0xff , & V_55 -> V_120 ) ;
V_3 -> V_20 = 0xff ;
} else {
struct V_281 * V_282 ;
int V_33 = 0 ;
F_94 (ha, dev) {
F_33 ( V_54 , V_282 -> V_152 , V_213 ) ;
F_2 ( & V_31 -> V_5 , L_78 ,
V_282 -> V_152 ) ;
V_54 += V_213 ;
V_33 ++ ;
}
if ( V_33 > 256 / V_77 )
V_33 = 256 / V_77 ;
F_28 ( ( T_3 ) V_33 , & V_55 -> V_120 ) ;
F_2 ( & V_31 -> V_5 , L_79 , V_33 ) ;
V_3 -> V_20 = V_33 ;
}
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 ,
L_80 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
}
}
static void F_95 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
T_3 V_283 ;
F_57 ( L_81 , V_5 ) ;
if ( V_5 -> V_10 & V_284 ) {
if ( V_3 -> V_73 . V_82 . V_285 == 0 ) {
F_57 ( L_82 ) ;
V_3 -> V_73 . V_82 . V_285 = 1 ;
V_283 = 1 ;
F_92 ( V_5 , V_286 ,
& V_283 , sizeof( V_283 ) ) ;
}
} else {
if ( V_3 -> V_73 . V_82 . V_285 == 1 ) {
F_57 ( L_83 ) ;
V_3 -> V_73 . V_82 . V_285 = 0 ;
V_283 = 0 ;
F_92 ( V_5 , V_286 ,
& V_283 , sizeof( V_283 ) ) ;
}
}
if ( V_5 -> V_10 & V_287 )
F_93 ( V_5 , 1 ) ;
else {
if ( V_3 -> V_20 != F_96 ( V_5 ) )
F_93 ( V_5 , 0 ) ;
}
}
static T_8 V_21 ( int V_37 , void * V_288 )
{
struct V_4 * V_5 = (struct V_4 * ) V_288 ;
struct V_1 * V_31 ;
T_1 * V_3 ;
struct V_51 T_2 * V_55 ;
struct V_53 T_2 * V_289 ;
T_3 V_290 ;
T_3 V_210 ;
T_3 V_86 ;
T_3 V_117 ;
T_3 V_291 [ V_116 + 1 ] ;
if ( V_5 == NULL )
return V_292 ;
F_57 ( L_84 , V_5 ) ;
V_3 = F_4 ( V_5 ) ;
V_31 = V_3 -> V_7 ;
if ( ! F_26 ( V_31 ) ) {
F_57 (
L_85 ) ;
return V_292 ;
}
V_290 = F_37 ( & ( (struct V_293 T_2 * ) ( V_3 -> V_44 ) ) -> V_294 ) ;
if ( V_290 >= ( V_69 + V_295 ) ) {
F_2 ( & V_31 -> V_5 , L_86 , V_290 ) ;
F_31 ( V_3 ) ;
return V_296 ;
}
if ( V_290 < V_69 ) {
V_55 = F_24 ( V_3 ) + V_290 ;
V_86 = F_37 ( & V_55 -> V_86 ) ;
V_117 = F_37 ( & V_55 -> V_71 ) ;
switch ( V_86 ) {
case V_85 :
F_40 ( & V_3 -> V_28 ) ;
if ( V_117 == V_297 ) {
F_2 ( & V_31 -> V_5 ,
L_87 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_88 ) ;
}
break;
case V_275 :
F_2 ( & V_31 -> V_5 , L_89 ) ;
if ( V_117 != V_297 ) {
V_210 =
F_37 ( & V_55 -> V_120 . V_122 .
V_278 ) ;
F_2 ( & V_31 -> V_5 ,
L_90 ,
V_210 ) ;
}
break;
case V_298 :
F_2 ( & V_31 -> V_5 , L_91 ) ;
break;
case V_280 :
F_2 ( & V_31 -> V_5 ,
L_92 ) ;
break;
case V_299 :
F_2 ( & V_31 -> V_5 ,
L_93 ) ;
break;
case V_119 :
case V_124 :
memcpy ( V_291 , V_3 -> V_73 . V_74 . V_115 ,
V_116 ) ;
V_291 [ V_116 ] = '\0' ;
if ( V_117 == V_297 ) {
if ( F_37
( & V_55 -> V_120 . V_121 . V_126 ) ==
1 ) {
F_2 ( & V_31 -> V_5 ,
L_94 ,
V_291 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_95 ,
V_291 ) ;
}
F_27 ( & V_3 -> V_189 ,
V_55 -> V_120 . V_121 . V_300 ,
V_77 ) ;
if ( V_3 -> V_64 == 0x55 )
V_3 -> V_169 = 3 ;
else
V_3 -> V_169 =
F_37 ( & V_55 -> V_120 . V_121 .
V_169 ) ;
V_3 -> V_301 =
F_37 ( & V_55 -> V_120 . V_121 . V_301 ) ;
if ( ! V_250 && ( V_3 -> V_56 == V_302 )
&& ! ( V_3 -> V_73 . V_74 . V_113 ) ) {
F_97 ( V_3 ) ;
}
V_3 -> V_16 = V_303 ;
} else {
V_3 -> V_16 = V_304 ;
F_40 ( & V_3 -> V_28 ) ;
V_3 -> V_28 . V_89 = V_90 + V_91 * 5 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
if ( V_117 == V_119 ) {
F_2 ( & V_31 -> V_5 ,
L_96 ,
V_291 ) ;
V_3 -> V_28 . V_93 = F_38 ;
} else {
F_2 ( & V_31 -> V_5 ,
L_97 ,
V_291 ) ;
V_3 -> V_28 . V_93 = F_39 ;
}
F_36 ( & V_3 -> V_28 ) ;
}
break;
case V_305 :
if ( V_117 == V_297 ) {
V_3 -> V_16 = V_306 ;
F_2 ( & V_31 -> V_5 , L_98 ) ;
} else {
F_2 ( & V_31 -> V_5 , L_99 ) ;
V_3 -> V_16 = V_307 ;
F_39 ( ( T_4 ) V_3 ) ;
}
break;
case V_163 :
if ( V_117 == V_297 ) {
F_2 ( & V_31 -> V_5 ,
L_100 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_101 ) ;
}
if ( ! V_250 )
F_84 ( V_5 ) ;
F_98 ( V_5 ) ;
break;
case V_308 :
F_2 ( & V_31 -> V_5 , L_102 ) ;
break;
case V_309 :
F_2 ( & V_31 -> V_5 ,
L_103 ) ;
break;
case V_310 :
F_2 ( & V_31 -> V_5 , L_104 ) ;
break;
case V_311 :
F_2 ( & V_31 -> V_5 ,
L_105 ) ;
break;
default:
F_2 ( & V_31 -> V_5 ,
L_106 ,
V_290 , V_86 ) ;
}
F_28 ( V_70 , & V_55 -> V_71 ) ;
} else {
V_289 = F_25 ( V_3 ) + V_290 ;
switch ( F_37 ( & V_289 -> V_312 ) ) {
case V_313 :
F_99 ( V_5 , V_3 , V_289 ) ;
break;
case V_314 :
F_2 ( & V_31 -> V_5 , L_107 ) ;
V_3 -> V_16 = V_303 ;
if ( V_3 -> V_73 . V_74 . V_112 == V_118 ) {
if ( ! V_250 )
F_84 ( V_5 ) ;
} else {
F_27 ( & V_3 -> V_189 ,
V_289 -> V_120 . V_315 .
V_300 , V_77 ) ;
F_2 ( & V_31 -> V_5 , L_108 ,
V_3 -> V_189 ) ;
if ( ! V_250 )
F_97 ( V_3 ) ;
}
break;
case V_316 :
F_2 ( & V_31 -> V_5 , L_109 ) ;
F_6 ( V_5 ) ;
V_3 -> V_16 = V_123 ;
break;
case V_317 :
F_2 ( & V_31 -> V_5 , L_110 ) ;
break;
default:
F_2 ( & V_31 -> V_5 ,
L_111 ,
V_290 ,
( unsigned int ) F_37 ( & V_289 -> V_312 ) ) ;
break;
}
F_28 ( V_70 , & V_289 -> V_71 ) ;
}
F_31 ( V_3 ) ;
return V_296 ;
}
static void F_99 ( struct V_4 * V_5 , T_1 * V_3 ,
struct V_53 T_2 * V_289 )
{
int V_318 ;
unsigned int V_319 ;
void T_2 * V_320 ;
F_57 ( L_112 ) ;
V_319 = ( ( F_37 ( & V_289 -> V_120 . V_321 . V_322 [ 0 ] ) << 8 )
+ F_37 ( & V_289 -> V_120 . V_321 . V_322 [ 1 ] ) ) & V_323 ;
V_318 = ( F_37 ( & V_289 -> V_120 . V_321 . V_324 [ 0 ] ) << 8 )
+ F_37 ( & V_289 -> V_120 . V_321 . V_324 [ 1 ] ) ;
V_3 -> V_325 = F_37 ( & V_289 -> V_120 . V_321 . V_326 ) ;
V_320 = V_3 -> V_45 + V_319 ;
switch ( F_37 ( V_320 ) ) {
case V_142 :
F_57 ( L_113 ) ;
F_100 ( V_5 , V_289 , V_319 , V_318 ) ;
break;
case V_327 :
F_57 ( L_114 ) ;
if ( V_250 )
F_100 ( V_5 , V_289 , V_319 , V_318 ) ;
else
F_101 ( V_3 , V_289 , V_319 , V_318 ) ;
break;
case V_328 :
F_57 ( L_115 ) ;
if ( V_250 )
F_100 ( V_5 , V_289 , V_319 , V_318 ) ;
else
F_102 ( V_3 , V_289 , V_319 , V_318 ) ;
break;
case V_329 :
F_57 ( L_116 ) ;
break;
case V_330 :
F_57 ( L_117 ) ;
if ( V_250 )
F_100 ( V_5 , V_289 , V_319 , V_318 ) ;
F_103 ( V_3 , ( T_3 * ) & V_3 -> V_331 , V_319 ,
V_318 < sizeof( struct V_332 ) ?
V_318 : sizeof( struct V_332 ) ) ;
V_3 -> V_333 = 1 ;
F_89 ( V_5 ) ;
break;
default:
F_57 ( L_118 ,
( unsigned int ) F_37 ( V_320 ) ) ;
break;
}
}
static void F_100 ( struct V_4 * V_5 , struct V_53 T_2 * V_289 ,
unsigned int V_319 , int V_318 )
{
struct V_131 * V_132 = NULL ;
struct V_53 T_2 * V_334 = V_289 ;
T_1 * V_3 = F_4 ( V_5 ) ;
T_3 * V_335 ;
int V_336 ;
int V_210 ;
#ifdef F_5
int V_337 = V_3 -> V_325 ;
T_9 V_338 [ V_213 ] ;
#endif
if ( ! V_250 ) {
if ( V_162 ) {
if ( V_318 < ( V_181 + V_339 ) ||
V_318 >
( V_5 -> V_340 + V_339 + V_181 +
V_341 ) ) {
F_57 (
L_119 ,
V_318 ) ;
return;
}
} else {
if ( V_318 < ( V_181 + V_339 ) ||
V_318 >
( V_5 -> V_340 + V_339 + V_181 +
V_341 ) ) {
F_57 (
L_119 ,
V_318 ) ;
return;
}
}
}
F_57 ( L_120 ) ;
if ( F_37 ( & V_289 -> V_120 . V_321 . V_342 ) != 0xFF ) {
F_57 ( L_121 ) ;
V_210 = ( F_37 ( & V_289 -> V_120 . V_321 . V_343 [ 0 ] ) << 8 )
+ F_37 ( & V_289 -> V_120 . V_321 . V_343 [ 1 ] ) ;
V_336 = V_210 ;
V_334 = V_289 ;
do {
V_210 -=
( F_37 ( & V_334 -> V_120 . V_321 . V_324 [ 0 ] )
<< 8 )
+ F_37 ( & V_334 -> V_120 . V_321 . V_324 [ 1 ] ) ;
if ( F_37 ( & V_334 -> V_120 . V_321 . V_342 )
== 0xFF || V_210 < 0 )
break;
V_334 = F_25 ( V_3 )
+ F_37 ( & V_334 -> V_344 ) ;
} while ( 1 );
if ( V_210 < 0 ) {
F_57 (
L_122 ) ;
V_3 -> V_159 . V_345 ++ ;
F_104 ( V_3 , V_289 ) ;
return;
}
} else {
V_336 = V_318 ;
}
V_132 = F_105 ( V_336 + 5 ) ;
if ( V_132 == NULL ) {
F_57 ( L_123 ) ;
V_3 -> V_159 . V_345 ++ ;
if ( F_37 ( & V_289 -> V_120 . V_321 . V_342 ) != 0xFF )
F_104 ( V_3 , V_289 ) ;
return;
}
F_106 ( V_132 , 2 ) ;
F_57 ( L_124 , V_336 ,
V_318 ) ;
V_335 = F_107 ( V_132 , V_336 ) ;
V_335 +=
F_103 ( V_3 , V_335 , V_319 & V_323 , V_318 ) ;
#ifdef F_5
F_108 ( V_132 ,
F_109 ( struct V_346 , V_191 ) ,
V_338 , V_213 ) ;
#endif
if ( ! V_250 ) {
if ( ! V_162 ) {
F_110 ( V_132 , V_339 ) ;
} else {
F_111 ( V_3 , V_132 , V_336 ) ;
}
} else {
} ;
V_210 = 17 ;
if ( F_37 ( & V_289 -> V_120 . V_321 . V_342 ) != 0xFF ) {
V_334 = V_289 ;
F_57 ( L_125 ) ;
do {
V_334 = F_25 ( V_3 )
+
F_37 ( & V_334 -> V_120 . V_321 . V_342 ) ;
V_318 =
( ( F_37 ( & V_334 -> V_120 . V_321 . V_324 [ 0 ] )
<< 8 )
+
F_37 ( & V_334 -> V_120 . V_321 . V_324 [ 1 ] ) )
& V_323 ;
V_319 =
( ( F_37 ( & V_334 -> V_120 . V_321 . V_322 [ 0 ] ) <<
8 )
+ F_37 ( & V_334 -> V_120 . V_321 . V_322 [ 1 ] ) )
& V_323 ;
V_335 +=
F_103 ( V_3 , V_335 , V_319 , V_318 ) ;
} while ( V_210 -- &&
F_37 ( & V_334 -> V_120 . V_321 . V_342 ) !=
0xFF );
F_104 ( V_3 , V_289 ) ;
}
V_132 -> V_347 = F_112 ( V_132 , V_5 ) ;
F_113 ( V_132 ) ;
V_3 -> V_159 . V_348 ++ ;
V_3 -> V_159 . V_349 += V_336 ;
#ifdef F_5
if ( ! memcmp ( V_338 , V_3 -> V_189 , V_213 ) ) {
V_3 -> V_245 . V_240 . V_241 = V_337 ;
V_3 -> V_245 . V_240 . V_248 = 0x2 ;
}
{
struct V_350 V_245 ;
V_245 . V_241 = V_337 ;
V_245 . V_248 = 0x2 ;
F_114 ( V_5 , V_338 , & V_245 ) ;
}
#endif
}
static void F_111 ( T_1 * V_3 , struct V_131 * V_132 , int V_134 )
{
V_179 * V_351 = ( V_179 * ) ( V_132 -> V_92 + V_339 ) ;
struct V_352 * V_353 = (struct V_352 * ) V_132 -> V_92 ;
T_6 type = * ( T_6 * ) V_351 -> V_354 ;
int V_355 ;
struct V_173 * V_356 ;
T_3 V_357 [ V_77 ] ;
T_3 V_358 [ V_77 ] ;
static const T_3 V_359 [ 3 ] = { 0 , 0 , 0xf8 } ;
static const T_3 V_360 [ 3 ] = { 0 , 0 , 0 } ;
memcpy ( V_358 , F_115 ( V_353 ) , V_77 ) ;
memcpy ( V_357 , F_116 ( V_353 ) , V_77 ) ;
#if 0
if {
print_hex_dump(KERN_DEBUG, "skb->data before untranslate: ",
DUMP_PREFIX_NONE, 16, 1,
skb->data, 64, true);
printk(KERN_DEBUG
"type = %08x, xsap = %02x%02x%02x, org = %02x02x02x\n",
ntohs(type), psnap->dsap, psnap->ssap, psnap->ctrl,
psnap->org[0], psnap->org[1], psnap->org[2]);
printk(KERN_DEBUG "untranslate skb->data = %p\n", skb->data);
}
#endif
if ( V_351 -> V_361 != 0xaa || V_351 -> V_362 != 0xaa || V_351 -> V_363 != 3 ) {
F_57 ( L_126 ,
V_351 -> V_361 , V_351 -> V_362 , V_351 -> V_363 ) ;
V_355 = V_339 - V_181 ;
V_356 = (struct V_173 * ) ( V_132 -> V_92 + V_355 ) ;
V_356 -> V_174 = F_62 ( V_134 - V_339 ) ;
} else {
if ( memcmp ( V_351 -> V_180 , V_359 , 3 ) == 0 ) {
F_57 ( L_127 ) ;
V_355 = V_339
+ sizeof( struct V_179 ) - V_181 ;
V_356 = (struct V_173 * ) ( V_132 -> V_92 + V_355 ) ;
V_356 -> V_174 = type ;
} else if ( memcmp ( V_351 -> V_180 , V_360 , 3 ) == 0 ) {
switch ( F_61 ( type ) ) {
case V_178 :
case V_177 :
F_57 ( L_128 ) ;
V_355 = V_339 - V_181 ;
V_356 = (struct V_173 * ) ( V_132 -> V_92 + V_355 ) ;
V_356 -> V_174 =
F_62 ( V_134 - V_339 ) ;
break;
default:
F_57 ( L_129 ) ;
V_355 = V_339 +
sizeof( struct V_179 ) - V_181 ;
V_356 = (struct V_173 * ) ( V_132 -> V_92 + V_355 ) ;
V_356 -> V_174 = type ;
break;
}
} else {
F_14 ( L_130 ) ;
V_355 = V_339 - V_181 ;
V_356 = (struct V_173 * ) ( V_132 -> V_92 + V_355 ) ;
V_356 -> V_174 = type ;
}
}
F_110 ( V_132 , V_355 ) ;
F_57 ( L_131 , V_355 ,
V_132 -> V_92 ) ;
memcpy ( V_356 -> V_187 , V_358 , V_77 ) ;
memcpy ( V_356 -> V_192 , V_357 , V_77 ) ;
#if 0
{
int i;
printk(KERN_DEBUG "skb->data after untranslate:");
for (i = 0; i < 64; i++)
printk("%02x ", skb->data[i]);
printk("\n");
}
#endif
}
static int F_103 ( T_1 * V_3 , T_3 * V_364 , int V_319 ,
int V_133 )
{
int V_365 = ( V_319 + V_133 ) - ( V_323 + 1 ) ;
if ( V_365 <= 0 ) {
F_27 ( V_364 , V_3 -> V_45 + V_319 , V_133 ) ;
} else {
F_27 ( V_364 , V_3 -> V_45 + V_319 ,
V_133 - V_365 ) ;
F_27 ( V_364 + V_133 - V_365 , V_3 -> V_45 ,
V_365 ) ;
}
return V_133 ;
}
static void F_104 ( T_1 * V_3 , struct V_53 T_2 * V_289 )
{
struct V_53 T_2 * V_334 = V_289 ;
int V_210 = 17 ;
unsigned V_290 = F_37 ( & V_289 -> V_120 . V_321 . V_342 ) ;
while ( V_210 -- ) {
F_28 ( V_70 , & V_334 -> V_71 ) ;
if ( V_290 >= ( V_69 + V_295 ) ) {
F_57 ( L_86 ,
V_290 ) ;
break;
}
V_334 = F_25 ( V_3 ) + V_290 ;
V_290 = F_37 ( & V_334 -> V_120 . V_321 . V_342 ) ;
}
F_28 ( V_70 , & V_334 -> V_71 ) ;
}
static void F_97 ( T_1 * V_3 )
{
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_132 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_133 ) ;
return;
}
F_40 ( & V_3 -> V_28 ) ;
if ( F_54 ( V_3 , V_3 -> V_189 , V_138 ) ) {
V_3 -> V_28 . V_93 = F_39 ;
} else {
V_3 -> V_28 . V_93 = F_87 ;
}
V_3 -> V_28 . V_89 = V_90 + V_91 * 2 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
F_36 ( & V_3 -> V_28 ) ;
V_3 -> V_18 = V_366 ;
}
static void F_101 ( T_1 * V_3 , struct V_53 T_2 * V_289 ,
unsigned int V_319 , int V_318 )
{
T_3 V_367 [ 256 ] ;
struct V_368 * V_369 = (struct V_368 * ) V_367 ;
F_40 ( & V_3 -> V_28 ) ;
F_103 ( V_3 , V_367 , V_319 , V_318 & 0xff ) ;
if ( V_3 -> V_73 . V_74 . V_112 == V_118 ) {
F_57 ( L_134 ,
V_369 -> V_120 [ 0 ] , V_369 -> V_120 [ 1 ] , V_369 -> V_120 [ 2 ] , V_369 -> V_120 [ 3 ] ,
V_369 -> V_120 [ 4 ] , V_369 -> V_120 [ 5 ] ) ;
if ( V_369 -> V_120 [ 2 ] == 1 ) {
F_57 ( L_135 ) ;
if ( ! F_54
( V_3 , V_369 -> V_183 . V_191 , V_370 ) ) {
V_3 -> V_18 = V_136 ;
memcpy ( V_3 -> V_137 , V_369 -> V_183 . V_191 ,
V_77 ) ;
}
}
} else {
if ( V_3 -> V_18 == V_366 ) {
if ( V_369 -> V_120 [ 2 ] == 2 ) {
if ( ( V_369 -> V_120 [ 3 ] | V_369 -> V_120 [ 4 ] ) == 0 ) {
F_57 ( L_136 ) ;
V_3 -> V_16 = V_371 ;
F_117 ( V_3 ) ;
V_3 -> V_18 =
V_139 ;
} else {
F_57 ( L_137 ) ;
V_3 -> V_16 = V_372 ;
F_39 ( ( T_4 ) V_3 ) ;
V_3 -> V_18 =
V_19 ;
}
}
}
}
}
static void F_117 ( T_1 * V_3 )
{
struct V_51 T_2 * V_55 ;
struct V_1 * V_31 = V_3 -> V_7 ;
struct V_4 * V_5 = V_31 -> V_15 ;
int V_79 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_138 ) ;
return;
}
if ( ( V_79 = F_34 ( V_3 ) ) < 0 ) {
F_2 ( & V_31 -> V_5 , L_139 ) ;
return;
}
F_2 ( & V_31 -> V_5 , L_140 ) ;
V_55 = F_24 ( V_3 ) + V_79 ;
F_28 ( V_305 , & V_55 -> V_86 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_74 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
F_40 ( & V_3 -> V_28 ) ;
V_3 -> V_28 . V_89 = V_90 + V_91 * 2 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
V_3 -> V_28 . V_93 = F_39 ;
F_36 ( & V_3 -> V_28 ) ;
V_3 -> V_16 = V_307 ;
return;
}
if ( ! V_250 )
F_84 ( V_5 ) ;
}
static void F_102 ( T_1 * V_3 , struct V_53 T_2 * V_289 ,
unsigned int V_319 , int V_318 )
{
F_57 ( L_141 ) ;
V_3 -> V_18 = V_19 ;
}
static void F_31 ( T_1 * V_3 )
{
F_28 ( 0 , V_3 -> V_47 + V_251 + V_373 ) ;
}
static int F_118 ( struct V_374 * V_203 , void * V_375 )
{
int V_33 ;
struct V_1 * V_31 ;
struct V_4 * V_5 ;
T_1 * V_3 ;
T_3 * V_54 ;
struct V_376 * V_377 ;
T_3 V_378 [ 33 ] ;
V_31 = V_29 ;
if ( ! V_31 )
return 0 ;
V_5 = (struct V_4 * ) V_31 -> V_15 ;
if ( ! V_5 )
return 0 ;
V_3 = F_4 ( V_5 ) ;
if ( ! V_3 )
return 0 ;
F_119 ( V_203 , L_142 ) ;
F_120 ( V_203 , L_143 , V_379 ) ;
F_119 ( V_203 , L_144 ) ;
if ( V_3 -> V_64 == 0x55 )
F_119 ( V_203 , L_145 ) ;
else
F_120 ( V_203 , L_146 ,
V_3 -> V_64 , V_3 -> V_66 , V_3 -> V_67 ) ;
for ( V_33 = 0 ; V_33 < 32 ; V_33 ++ )
V_378 [ V_33 ] = V_3 -> V_73 . V_82 . V_115 [ V_33 ] ;
V_378 [ 32 ] = 0 ;
F_120 ( V_203 , L_147 ,
V_380 [ V_3 -> V_73 . V_82 . V_112 ] , V_378 ) ;
V_54 = V_3 -> V_189 ;
F_120 ( V_203 , L_148 , V_54 ) ;
F_120 ( V_203 , L_149 ,
V_3 -> V_73 . V_82 . V_103 ) ;
V_33 = V_3 -> V_16 ;
if ( V_33 < 0 )
V_33 = 10 ;
if ( V_33 > 16 )
V_33 = 10 ;
F_120 ( V_203 , L_150 , V_16 [ V_33 ] ) ;
F_120 ( V_203 , L_151 , V_381 [ V_162 ] ) ;
F_120 ( V_203 , L_152 , V_3 -> V_325 ) ;
if ( V_3 -> V_333 ) {
F_120 ( V_203 , L_153 ,
V_3 -> V_331 . V_382 [ 0 ]
+ 256 * V_3 -> V_331 . V_382 [ 1 ] ) ;
V_54 = V_3 -> V_331 . V_383 ;
if ( V_54 [ 0 ] == V_384 )
V_54 += V_54 [ 1 ] + 2 ;
else {
F_120 ( V_203 ,
L_154 ,
V_54 [ 0 ] ) ;
return 0 ;
}
if ( V_54 [ 0 ] == V_385 ) {
F_119 ( V_203 , L_155 ) ;
for ( V_33 = 2 ; V_33 < V_54 [ 1 ] + 2 ; V_33 ++ )
F_120 ( V_203 , L_156 , V_54 [ V_33 ] ) ;
F_121 ( V_203 , '\n' ) ;
V_54 += V_54 [ 1 ] + 2 ;
} else {
F_119 ( V_203 , L_157 ) ;
return 0 ;
}
if ( V_54 [ 0 ] == V_386 ) {
V_377 = (struct V_376 * ) V_54 ;
F_120 ( V_203 , L_158 ,
V_377 -> V_387 [ 0 ] +
256 * V_377 -> V_387 [ 1 ] ) ;
F_120 ( V_203 , L_159 ,
V_377 -> V_388 ) ;
F_120 ( V_203 , L_160 ,
V_377 -> V_389 ) ;
F_120 ( V_203 , L_161 ,
V_377 -> V_390 ) ;
V_54 += V_54 [ 1 ] + 2 ;
} else {
F_119 ( V_203 ,
L_162 ) ;
return 0 ;
}
} else {
F_119 ( V_203 , L_163 ) ;
}
return 0 ;
}
static int F_122 ( struct V_391 * V_391 , struct V_392 * V_392 )
{
return F_123 ( V_392 , F_118 , NULL ) ;
}
static int F_54 ( T_1 * V_3 , T_3 * V_364 , int V_393 )
{
int V_152 ;
struct V_51 T_2 * V_55 ;
struct V_150 T_2 * V_151 ;
int V_79 ;
if ( ( V_79 = F_58 ( V_3 ) ) < 0 ) {
F_57 ( L_164 ) ;
return - 1 ;
}
V_55 = F_24 ( V_3 ) + V_79 ;
V_152 = V_158 + ( V_79 << 11 ) ;
F_28 ( V_163 , & V_55 -> V_86 ) ;
F_28 ( V_152 >> 8 , V_55 -> V_120 . V_164 . V_165 ) ;
F_28 ( 0x20 , V_55 -> V_120 . V_164 . V_165 + 1 ) ;
F_28 ( V_394 , V_55 -> V_120 . V_164 . V_166 ) ;
F_28 ( V_395 ,
V_55 -> V_120 . V_164 . V_166 + 1 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_164 . V_168 ) ;
V_151 = V_3 -> V_44 + V_152 ;
F_28 ( V_182 | V_327 , & V_151 -> V_183 . V_184 ) ;
F_28 ( 0 , & V_151 -> V_183 . V_185 ) ;
F_33 ( V_151 -> V_183 . V_186 , V_364 , V_77 ) ;
F_33 ( V_151 -> V_183 . V_191 , V_3 -> V_73 . V_74 . V_75 , V_77 ) ;
F_33 ( V_151 -> V_183 . V_188 , V_3 -> V_189 , V_77 ) ;
F_124 ( V_151 -> V_120 , 0 , 6 ) ;
F_28 ( V_393 & 0xff , V_151 -> V_120 + 2 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_57 (
L_165 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
return - 1 ;
}
return 0 ;
}
static T_10 F_125 ( struct V_392 * V_392 ,
const char T_11 * V_396 , T_12 V_397 , T_13 * V_398 )
{
static char V_399 [ 33 ] ;
unsigned int V_134 = V_397 ;
if ( V_134 > 32 )
V_134 = 32 ;
memset ( V_399 , 0 , 33 ) ;
if ( F_126 ( V_399 , V_396 , V_134 ) )
return - V_400 ;
V_114 = V_399 ;
return V_397 ;
}
static T_10 F_127 ( struct V_392 * V_392 , const char T_11 * V_396 ,
T_12 V_397 , T_13 * V_398 )
{
static char V_401 [ 10 ] ;
char * V_54 ;
int V_402 , V_134 ;
if ( ! V_397 )
return 0 ;
if ( V_397 > 9 )
return - V_218 ;
if ( F_126 ( V_401 , V_396 , V_397 ) )
return - V_400 ;
V_54 = V_401 ;
V_402 = 0 ;
V_134 = V_397 ;
do {
unsigned int V_378 = * V_54 - '0' ;
if ( V_378 > 9 )
return - V_218 ;
V_402 = V_402 * 10 + V_378 ;
V_54 ++ ;
} while ( -- V_134 );
* ( int * ) F_128 ( F_129 ( V_392 ) ) = V_402 ;
return V_397 ;
}
static int T_14 F_130 ( void )
{
int V_403 ;
F_57 ( L_143 , V_379 ) ;
V_403 = F_131 ( & V_404 ) ;
F_57 ( L_166 ,
V_403 ) ;
#ifdef F_132
F_133 ( L_167 , NULL ) ;
F_134 ( L_168 , 0 , NULL , & V_405 ) ;
F_134 ( L_169 , V_406 , NULL , & V_407 ) ;
F_135 ( L_170 , V_406 , NULL , & V_408 , & V_56 ) ;
F_135 ( L_171 , V_406 , NULL , & V_408 , & V_162 ) ;
#endif
if ( V_162 != 0 )
V_162 = 1 ;
return 0 ;
}
static void T_15 F_136 ( void )
{
F_57 ( L_172 ) ;
#ifdef F_132
F_137 ( L_168 , NULL ) ;
F_137 ( L_169 , NULL ) ;
F_137 ( L_170 , NULL ) ;
F_137 ( L_171 , NULL ) ;
F_137 ( L_167 , NULL ) ;
#endif
F_138 ( & V_404 ) ;
}
