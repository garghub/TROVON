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
F_11 ( & V_3 -> V_28 ) ;
F_40 ( V_3 -> V_44 ) ;
F_40 ( V_3 -> V_45 ) ;
F_40 ( V_3 -> V_47 ) ;
F_41 ( V_31 ) ;
F_2 ( & V_31 -> V_5 , L_33 ) ;
}
static int F_42 ( struct V_1 * V_31 )
{
struct V_4 * V_5 = V_31 -> V_15 ;
if ( V_31 -> V_127 )
F_43 ( V_5 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_31 )
{
struct V_4 * V_5 = V_31 -> V_15 ;
if ( V_31 -> V_127 ) {
F_45 ( V_5 ) ;
F_46 ( V_5 ) ;
}
return 0 ;
}
static int F_47 ( struct V_4 * V_5 )
{
#ifdef F_48
int V_33 ;
#endif
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_34 , V_5 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_35 ) ;
return - 1 ;
}
#ifdef F_48
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
memset ( V_5 -> V_128 , 0xff , V_129 ) ;
F_2 ( & V_31 -> V_5 , L_39 ) ;
return 0 ;
}
static int F_49 ( struct V_4 * V_5 , struct V_130 * V_131 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_40 , V_5 , V_131 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
static T_5 F_50 ( struct V_132 * V_133 ,
struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
short V_134 = V_133 -> V_135 ;
if ( ! F_26 ( V_31 ) ) {
F_2 ( & V_31 -> V_5 , L_42 ) ;
F_51 ( V_133 ) ;
return V_136 ;
}
F_2 ( & V_31 -> V_5 , L_43 , V_133 , V_5 ) ;
if ( V_3 -> V_18 == V_137 ) {
F_2 ( & V_31 -> V_5 , L_44 ) ;
if ( ! F_52 ( V_3 , V_3 -> V_138 , V_139 ) ) {
V_3 -> V_18 = V_140 ;
F_6 ( V_5 ) ;
return V_141 ;
}
}
if ( V_134 < V_142 ) {
if ( F_53 ( V_133 , V_142 ) )
return V_136 ;
V_134 = V_142 ;
}
switch ( F_54 ( V_133 -> V_92 , V_134 , V_5 , V_143 ) ) {
case V_144 :
case V_145 :
F_6 ( V_5 ) ;
return V_141 ;
case V_146 :
case V_147 :
case V_148 :
default:
F_51 ( V_133 ) ;
}
return V_136 ;
}
static int F_54 ( unsigned char * V_92 , int V_135 , struct V_4 * V_5 ,
T_3 V_149 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_51 T_2 * V_55 ;
int V_79 ;
int V_150 ;
struct V_151 T_2 * V_152 ;
short int V_153 ;
F_55 ( L_45 , V_92 , V_135 , V_5 ) ;
if ( V_135 + V_154 > V_155 ) {
F_14 ( V_34 L_46 ,
V_135 ) ;
return V_147 ;
}
switch ( V_79 = F_56 ( V_3 ) ) {
case V_156 :
F_55 ( L_47 ) ;
case V_157 :
F_55 ( L_48 ) ;
case V_158 :
F_6 ( V_5 ) ;
return V_144 ;
default:
break;
}
V_153 = V_159 + ( V_79 << 11 ) ;
if ( V_149 == V_143 ) {
V_3 -> V_160 . V_161 += V_135 ;
V_3 -> V_160 . V_162 ++ ;
}
V_152 = V_3 -> V_44 + V_153 ;
F_57 ( V_3 , V_152 , V_149 , V_92 ) ;
if ( V_163 ) {
V_150 = F_58 ( V_3 , V_152 , V_92 , V_135 ) ;
} else {
F_33 ( & V_152 -> V_120 , V_92 , V_135 ) ;
V_150 = 0 ;
}
V_55 = F_24 ( V_3 ) + V_79 ;
V_135 += V_154 + V_150 ;
F_28 ( V_164 , & V_55 -> V_86 ) ;
F_28 ( V_153 >> 8 , & V_55 -> V_120 . V_165 . V_166 [ 0 ] ) ;
F_28 ( V_3 -> V_68 , & V_55 -> V_120 . V_165 . V_166 [ 1 ] ) ;
F_28 ( V_135 >> 8 , & V_55 -> V_120 . V_165 . V_167 [ 0 ] ) ;
F_28 ( V_135 & 0xff , & V_55 -> V_120 . V_165 . V_167 [ 1 ] ) ;
F_28 ( V_168 , & V_55 -> V_120 . V_165 . V_169 ) ;
F_28 ( V_3 -> V_170 , & V_55 -> V_120 . V_165 . V_171 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_165 . V_172 ) ;
F_55 ( L_49 ,
V_3 -> V_170 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_55 ( L_50 ) ;
F_28 ( V_70 , & V_55 -> V_71 ) ;
return V_146 ;
}
return V_148 ;
}
static int F_58 ( T_1 * V_3 , struct V_151 T_2 * V_152 ,
unsigned char * V_92 , int V_135 )
{
T_6 V_173 = ( (struct V_174 * ) V_92 ) -> V_175 ;
if ( F_59 ( V_173 ) >= 1536 ) {
F_55 ( L_51 ) ;
F_33 ( & V_152 -> V_120 , V_176 , sizeof( V_176 ) ) ;
F_33 ( ( ( void T_2 * ) & V_152 -> V_120 ) + sizeof( V_176 ) ,
( T_3 * ) & V_173 , 2 ) ;
if ( V_173 == F_60 ( V_177 ) || V_173 == F_60 ( V_178 ) ) {
F_28 ( 0xf8 ,
& ( (struct V_179 T_2 * ) V_152 -> V_120 ) -> V_180 [ 3 ] ) ;
}
F_33 ( ( void T_2 * ) & V_152 -> V_120 +
sizeof( struct V_179 ) , V_92 + V_181 ,
V_135 - V_181 ) ;
return ( int ) sizeof( struct V_179 ) - V_181 ;
} else {
F_55 ( L_52 ) ;
if ( V_173 == F_60 ( 0xffff ) ) {
F_55 ( L_53 ) ;
F_33 ( & V_152 -> V_120 , V_92 + V_181 , V_135 - V_181 ) ;
return 0 - V_181 ;
}
F_33 ( & V_152 -> V_120 , V_92 + V_181 , V_135 - V_181 ) ;
return 0 - V_181 ;
}
}
static void F_57 ( T_1 * V_3 , struct V_151 T_2 * V_152 ,
T_3 V_149 , unsigned char * V_92 )
{
F_28 ( V_182 | V_149 , & V_152 -> V_183 . V_184 ) ;
if ( V_3 -> V_56 == V_118 ) {
F_28 ( 0 , & V_152 -> V_183 . V_185 ) ;
F_33 ( V_152 -> V_183 . V_186 , ( (struct V_174 * ) V_92 ) -> V_187 ,
2 * V_77 ) ;
F_33 ( V_152 -> V_183 . V_188 , V_3 -> V_189 , V_77 ) ;
} else {
if ( V_3 -> V_73 . V_74 . V_113 ) {
F_28 ( V_190 , & V_152 -> V_183 . V_185 ) ;
F_33 ( V_152 -> V_183 . V_186 ,
( (struct V_174 * ) V_92 ) -> V_187 , V_77 ) ;
F_33 ( V_152 -> V_183 . V_191 , V_3 -> V_189 , 6 ) ;
F_33 ( V_152 -> V_183 . V_188 ,
( (struct V_174 * ) V_92 ) -> V_192 , V_77 ) ;
} else {
F_28 ( V_193 , & V_152 -> V_183 . V_185 ) ;
F_33 ( V_152 -> V_183 . V_186 , V_3 -> V_189 , V_77 ) ;
F_33 ( V_152 -> V_183 . V_191 ,
( (struct V_174 * ) V_92 ) -> V_192 , V_77 ) ;
F_33 ( V_152 -> V_183 . V_188 ,
( (struct V_174 * ) V_92 ) -> V_187 , V_77 ) ;
}
}
}
static int F_61 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
strcpy ( V_197 -> V_49 , L_54 ) ;
return 0 ;
}
static int F_62 ( struct V_4 * V_5 , struct V_194 * V_195 ,
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
static int F_63 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_202 . V_203 = V_3 -> V_73 . V_82 . V_207 ;
V_197 -> V_202 . V_205 = 0 ;
return 0 ;
}
static int F_64 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_114 . V_10 == 0 )
return - V_206 ;
if ( V_197 -> V_114 . V_134 > V_208 )
return - V_209 ;
memset ( V_3 -> V_73 . V_82 . V_115 , 0 , V_208 ) ;
memcpy ( V_3 -> V_73 . V_82 . V_115 , V_198 , V_197 -> V_114 . V_134 ) ;
return - V_200 ;
}
static int F_65 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
memcpy ( V_198 , V_3 -> V_73 . V_82 . V_115 , V_208 ) ;
V_197 -> V_114 . V_134 = strlen ( V_198 ) ;
V_197 -> V_114 . V_10 = 1 ;
return 0 ;
}
static int F_66 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
memcpy ( V_197 -> V_210 . V_211 , V_3 -> V_189 , V_129 ) ;
V_197 -> V_210 . V_212 = V_213 ;
return 0 ;
}
static int F_67 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( ( V_197 -> V_214 . V_215 != 1000000 ) && ( V_197 -> V_214 . V_215 != 2000000 ) )
return - V_216 ;
if ( ( V_3 -> V_64 == 0x55 ) &&
( V_197 -> V_214 . V_215 == 2000000 ) )
V_3 -> V_170 = 3 ;
else
V_3 -> V_170 = V_197 -> V_214 . V_215 / 500000 ;
return 0 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_170 == 3 )
V_197 -> V_214 . V_215 = 2000000 ;
else
V_197 -> V_214 . V_215 = V_3 -> V_170 * 500000 ;
V_197 -> V_214 . V_217 = 0 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_218 = V_197 -> V_219 . V_215 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_219 . V_220 )
V_218 = 32767 ;
else {
if ( ( V_218 < 0 ) || ( V_218 > 2347 ) )
return - V_216 ;
}
V_3 -> V_73 . V_82 . V_221 [ 0 ] = ( V_218 >> 8 ) & 0xFF ;
V_3 -> V_73 . V_82 . V_221 [ 1 ] = V_218 & 0xFF ;
return - V_200 ;
}
static int F_70 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_219 . V_215 = ( V_3 -> V_73 . V_82 . V_221 [ 0 ] << 8 )
+ V_3 -> V_73 . V_82 . V_221 [ 1 ] ;
V_197 -> V_219 . V_220 = ( V_197 -> V_219 . V_215 == 32767 ) ;
V_197 -> V_219 . V_217 = 1 ;
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_222 = V_197 -> V_223 . V_215 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_223 . V_220 )
V_222 = 32767 ;
else {
if ( ( V_222 < 256 ) || ( V_222 > 2347 ) )
return - V_216 ;
}
V_3 -> V_73 . V_82 . V_224 [ 0 ] = ( V_222 >> 8 ) & 0xFF ;
V_3 -> V_73 . V_82 . V_224 [ 1 ] = V_222 & 0xFF ;
return - V_200 ;
}
static int F_72 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_223 . V_215 = ( V_3 -> V_73 . V_82 . V_224 [ 0 ] << 8 )
+ V_3 -> V_73 . V_82 . V_224 [ 1 ] ;
V_197 -> V_223 . V_220 = ( V_197 -> V_223 . V_215 == 32767 ) ;
V_197 -> V_223 . V_217 = 1 ;
return 0 ;
}
static int F_73 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_199 = - V_200 ;
char V_225 = 1 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
switch ( V_197 -> V_226 ) {
case V_227 :
V_225 = 0 ;
case V_228 :
V_3 -> V_73 . V_82 . V_112 = V_225 ;
break;
default:
V_199 = - V_216 ;
}
return V_199 ;
}
static int F_74 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_73 . V_82 . V_112 )
V_197 -> V_226 = V_228 ;
else
V_197 -> V_226 = V_227 ;
return 0 ;
}
static int F_75 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
struct V_229 * V_230 = (struct V_229 * ) V_198 ;
memset ( V_230 , 0 , sizeof( struct V_229 ) ) ;
V_197 -> V_92 . V_134 = sizeof( struct V_229 ) ;
V_230 -> V_231 = V_232 ;
V_230 -> V_233 = 9 ;
V_230 -> V_234 = 1.1 * 1000 * 1000 ;
V_230 -> V_235 = V_105 [ ( int ) V_95 ] ;
V_230 -> V_236 = 0 ;
V_230 -> V_237 . V_238 = 0 ;
V_230 -> V_237 . V_239 = 255 ;
V_230 -> V_237 . V_240 = 255 ;
V_230 -> V_241 = 2 ;
V_230 -> V_214 [ 0 ] = 1000000 ;
V_230 -> V_214 [ 1 ] = 2000000 ;
return 0 ;
}
static int F_76 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
V_163 = * ( V_198 ) ;
return 0 ;
}
static int F_77 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
* ( V_198 ) = V_163 ;
return 0 ;
}
static int F_78 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
* ( V_198 ) = V_95 ;
return 0 ;
}
static int F_79 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
return 0 ;
}
static T_7 * F_80 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
struct V_117 T_2 * V_54 = V_3 -> V_44 + V_242 ;
V_3 -> V_243 . V_117 = V_3 -> V_16 ;
#ifdef F_5
if ( ( V_3 -> V_27 . V_244 > 0 )
&& ( V_3 -> V_73 . V_82 . V_112 == 0 ) ) {
V_3 -> V_243 . V_238 . V_238 = V_3 -> V_27 . V_245 [ 0 ] . V_238 ;
V_3 -> V_243 . V_238 . V_239 = V_3 -> V_27 . V_245 [ 0 ] . V_239 ;
V_3 -> V_243 . V_238 . V_240 = V_3 -> V_27 . V_245 [ 0 ] . V_240 ;
V_3 -> V_243 . V_238 . V_246 =
V_3 -> V_27 . V_245 [ 0 ] . V_246 ;
}
#endif
if ( F_26 ( V_31 ) ) {
V_3 -> V_243 . V_238 . V_240 = F_37 ( & V_54 -> V_247 ) ;
V_3 -> V_243 . V_238 . V_246 |= 4 ;
}
return & V_3 -> V_243 ;
}
static int F_81 ( struct V_4 * V_5 )
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
if ( V_248 )
F_6 ( V_5 ) ;
else
F_82 ( V_5 ) ;
F_2 ( & V_31 -> V_5 , L_57 ) ;
return 0 ;
}
static int F_83 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 ;
V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_58 , V_5 -> V_49 ) ;
V_31 -> V_127 -- ;
F_6 ( V_5 ) ;
return 0 ;
}
static void F_45 ( struct V_4 * V_5 )
{
F_55 ( L_59 ) ;
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
( F_37 ( V_3 -> V_47 + V_249 + V_250 ) &
V_251 ) )
V_33 -- ;
if ( V_33 == 0 ) {
F_2 ( & V_31 -> V_5 , L_62 ) ;
return - 1 ;
}
F_28 ( V_51 , V_3 -> V_44 + V_252 ) ;
F_28 ( V_251 , V_3 -> V_47 + V_249 + V_250 ) ;
return 0 ;
}
static int F_56 ( T_1 * V_3 )
{
int V_33 ;
struct V_51 T_2 * V_55 = F_24 ( V_3 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_63 ) ;
return V_158 ;
}
if ( F_84 ( 0 , & V_3 -> V_253 ) ) {
F_2 ( & V_31 -> V_5 , L_64 ) ;
return V_156 ;
}
for ( V_33 = 0 ; V_33 < V_254 ; V_33 ++ ) {
if ( F_37 ( & ( V_55 + V_33 ) -> V_71 ) == V_70 ) {
F_28 ( V_255 , & ( V_55 + V_33 ) -> V_71 ) ;
F_28 ( V_256 , & ( V_55 + V_33 ) -> V_31 ) ;
V_3 -> V_253 = 0 ;
return V_33 ;
}
}
V_3 -> V_253 = 0 ;
F_2 ( & V_31 -> V_5 , L_65 ) ;
return V_157 ;
}
static int F_34 ( T_1 * V_3 )
{
int V_33 ;
struct V_51 T_2 * V_55 = F_24 ( V_3 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_66 ) ;
return V_158 ;
}
if ( F_84 ( 0 , & V_3 -> V_257 ) ) {
F_2 ( & V_31 -> V_5 , L_67 ) ;
return V_156 ;
}
for ( V_33 = V_254 ; V_33 < V_69 ; V_33 ++ ) {
if ( F_37 ( & ( V_55 + V_33 ) -> V_71 ) == V_70 ) {
F_28 ( V_255 , & ( V_55 + V_33 ) -> V_71 ) ;
F_28 ( V_256 , & ( V_55 + V_33 ) -> V_31 ) ;
V_3 -> V_257 = 0 ;
return V_33 ;
}
}
V_3 -> V_257 = 0 ;
F_2 ( & V_31 -> V_5 , L_68 ) ;
return V_157 ;
}
static void F_85 ( T_4 V_92 )
{
T_1 * V_3 = ( T_1 * ) V_92 ;
F_11 ( & V_3 -> V_28 ) ;
F_14 ( V_34 L_69
L_70 ) ;
F_39 ( ( T_4 ) V_3 ) ;
}
static int F_30 ( char * V_258 , T_3 * V_259 )
{
int V_135 ;
int V_33 , V_260 , V_261 ;
int V_117 ;
if ( V_258 == NULL )
return 0 ;
if ( ( V_135 = strlen ( V_258 ) ) < 2 )
return 0 ;
memset ( V_259 , 0 , V_77 ) ;
V_117 = 1 ;
V_260 = V_135 - 1 ;
if ( V_260 > 12 )
V_260 = 12 ;
V_33 = 5 ;
while ( V_260 > 0 ) {
if ( ( V_261 = F_86 ( V_258 [ V_260 -- ] ) ) != - 1 )
V_259 [ V_33 ] = V_261 ;
else
return 0 ;
if ( V_260 == 0 )
break;
if ( ( V_261 = F_86 ( V_258 [ V_260 -- ] ) ) != - 1 )
V_259 [ V_33 ] += V_261 << 4 ;
else
return 0 ;
if ( ! V_33 -- )
break;
}
return V_117 ;
}
static struct V_262 * F_87 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
struct V_117 T_2 * V_54 = V_3 -> V_44 + V_242 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_71 ) ;
return & V_3 -> V_160 ;
}
if ( F_37 ( & V_54 -> V_263 ) ) {
V_3 -> V_160 . V_264 += F_88 ( F_89 ( & V_54 -> V_265 ) ) ;
F_28 ( 0 , & V_54 -> V_265 ) ;
F_28 ( 0 , & V_54 -> V_263 ) ;
}
if ( F_37 ( & V_54 -> V_266 ) ) {
V_3 -> V_160 . V_267 +=
F_88 ( F_89 ( & V_54 -> V_268 ) ) ;
F_28 ( 0 , & V_54 -> V_268 ) ;
F_28 ( 0 , & V_54 -> V_266 ) ;
}
if ( F_37 ( & V_54 -> V_269 ) ) {
V_3 -> V_160 . V_270 += F_88 ( F_89 ( & V_54 -> V_271 ) ) ;
F_28 ( 0 , & V_54 -> V_271 ) ;
F_28 ( 0 , & V_54 -> V_269 ) ;
}
return & V_3 -> V_160 ;
}
static void F_90 ( struct V_4 * V_5 , T_3 V_272 , T_3 * V_215 ,
int V_135 )
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
F_28 ( V_273 , & V_55 -> V_86 ) ;
F_28 ( V_272 , & V_55 -> V_120 . V_122 . V_274 ) ;
F_28 ( 1 , & V_55 -> V_120 . V_122 . V_275 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_122 . V_276 ) ;
for ( V_33 = 0 ; V_33 < V_135 ; V_33 ++ ) {
F_28 ( V_215 [ V_33 ] , V_3 -> V_44 + V_80 ) ;
}
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_74 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
}
}
static void F_91 ( struct V_4 * V_5 , int V_277 )
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
F_28 ( V_278 , & V_55 -> V_86 ) ;
if ( V_277 ) {
F_28 ( 0xff , & V_55 -> V_120 ) ;
V_3 -> V_20 = 0xff ;
} else {
struct V_279 * V_280 ;
int V_33 = 0 ;
F_92 (ha, dev) {
F_33 ( V_54 , V_280 -> V_153 , V_129 ) ;
F_2 ( & V_31 -> V_5 , L_78 ,
V_280 -> V_153 ) ;
V_54 += V_129 ;
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
static void F_93 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
T_3 V_281 ;
F_55 ( L_81 , V_5 ) ;
if ( V_5 -> V_10 & V_282 ) {
if ( V_3 -> V_73 . V_82 . V_283 == 0 ) {
F_55 ( L_82 ) ;
V_3 -> V_73 . V_82 . V_283 = 1 ;
V_281 = 1 ;
F_90 ( V_5 , V_284 ,
& V_281 , sizeof( V_281 ) ) ;
}
} else {
if ( V_3 -> V_73 . V_82 . V_283 == 1 ) {
F_55 ( L_83 ) ;
V_3 -> V_73 . V_82 . V_283 = 0 ;
V_281 = 0 ;
F_90 ( V_5 , V_284 ,
& V_281 , sizeof( V_281 ) ) ;
}
}
if ( V_5 -> V_10 & V_285 )
F_91 ( V_5 , 1 ) ;
else {
if ( V_3 -> V_20 != F_94 ( V_5 ) )
F_91 ( V_5 , 0 ) ;
}
}
static T_8 V_21 ( int V_37 , void * V_286 )
{
struct V_4 * V_5 = (struct V_4 * ) V_286 ;
struct V_1 * V_31 ;
T_1 * V_3 ;
struct V_51 T_2 * V_55 ;
struct V_53 T_2 * V_287 ;
T_3 V_288 ;
T_3 V_289 ;
T_3 V_86 ;
T_3 V_117 ;
if ( V_5 == NULL )
return V_290 ;
F_55 ( L_84 , V_5 ) ;
V_3 = F_4 ( V_5 ) ;
V_31 = (struct V_1 * ) V_3 -> V_7 ;
if ( ! F_26 ( V_31 ) ) {
F_55 (
L_85 ) ;
return V_290 ;
}
V_288 = F_37 ( & ( (struct V_291 T_2 * ) ( V_3 -> V_44 ) ) -> V_292 ) ;
if ( V_288 >= ( V_69 + V_293 ) ) {
F_2 ( & V_31 -> V_5 , L_86 , V_288 ) ;
F_31 ( V_3 ) ;
return V_294 ;
}
if ( V_288 < V_69 ) {
V_55 = F_24 ( V_3 ) + V_288 ;
V_86 = F_37 ( & V_55 -> V_86 ) ;
V_117 = F_37 ( & V_55 -> V_71 ) ;
switch ( V_86 ) {
case V_85 :
F_11 ( & V_3 -> V_28 ) ;
if ( V_117 == V_295 ) {
F_2 ( & V_31 -> V_5 ,
L_87 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_88 ) ;
}
break;
case V_273 :
F_2 ( & V_31 -> V_5 , L_89 ) ;
if ( V_117 != V_295 ) {
V_289 =
F_37 ( & V_55 -> V_120 . V_122 .
V_276 ) ;
F_2 ( & V_31 -> V_5 ,
L_90 ,
V_289 ) ;
}
break;
case V_296 :
F_2 ( & V_31 -> V_5 , L_91 ) ;
break;
case V_278 :
F_2 ( & V_31 -> V_5 ,
L_92 ) ;
break;
case V_297 :
F_2 ( & V_31 -> V_5 ,
L_93 ) ;
break;
case V_119 :
case V_124 :
if ( V_117 == V_295 ) {
if ( F_37
( & V_55 -> V_120 . V_121 . V_126 ) ==
1 ) {
F_2 ( & V_31 -> V_5 ,
L_94 ,
V_3 -> V_73 . V_74 . V_115 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_95 ,
V_3 -> V_73 . V_74 . V_115 ) ;
}
F_27 ( & V_3 -> V_189 ,
V_55 -> V_120 . V_121 . V_298 ,
V_77 ) ;
if ( V_3 -> V_64 == 0x55 )
V_3 -> V_170 = 3 ;
else
V_3 -> V_170 =
F_37 ( & V_55 -> V_120 . V_121 .
V_170 ) ;
V_3 -> V_299 =
F_37 ( & V_55 -> V_120 . V_121 . V_299 ) ;
if ( ! V_248 && ( V_3 -> V_56 == V_300 )
&& ! ( V_3 -> V_73 . V_74 . V_113 ) ) {
F_95 ( V_3 ) ;
}
V_3 -> V_16 = V_301 ;
} else {
V_3 -> V_16 = V_302 ;
F_11 ( & V_3 -> V_28 ) ;
V_3 -> V_28 . V_89 = V_90 + V_91 * 5 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
if ( V_117 == V_119 ) {
F_2 ( & V_31 -> V_5 ,
L_96 ,
V_3 -> V_73 . V_74 . V_115 ) ;
V_3 -> V_28 . V_93 = F_38 ;
} else {
F_2 ( & V_31 -> V_5 ,
L_97 ,
V_3 -> V_73 . V_74 . V_115 ) ;
V_3 -> V_28 . V_93 = F_39 ;
}
F_36 ( & V_3 -> V_28 ) ;
}
break;
case V_303 :
if ( V_117 == V_295 ) {
V_3 -> V_16 = V_304 ;
F_2 ( & V_31 -> V_5 , L_98 ) ;
} else {
F_2 ( & V_31 -> V_5 , L_99 ) ;
V_3 -> V_16 = V_305 ;
F_39 ( ( T_4 ) V_3 ) ;
}
break;
case V_164 :
if ( V_117 == V_295 ) {
F_2 ( & V_31 -> V_5 ,
L_100 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_101 ) ;
}
if ( ! V_248 )
F_82 ( V_5 ) ;
F_96 ( V_5 ) ;
break;
case V_306 :
F_2 ( & V_31 -> V_5 , L_102 ) ;
break;
case V_307 :
F_2 ( & V_31 -> V_5 ,
L_103 ) ;
break;
case V_308 :
F_2 ( & V_31 -> V_5 , L_104 ) ;
break;
case V_309 :
F_2 ( & V_31 -> V_5 ,
L_105 ) ;
break;
default:
F_2 ( & V_31 -> V_5 ,
L_106 ,
V_288 , V_86 ) ;
}
F_28 ( V_70 , & V_55 -> V_71 ) ;
} else {
V_287 = F_25 ( V_3 ) + V_288 ;
switch ( F_37 ( & V_287 -> V_310 ) ) {
case V_311 :
F_97 ( V_5 , V_3 , V_287 ) ;
break;
case V_312 :
F_2 ( & V_31 -> V_5 , L_107 ) ;
V_3 -> V_16 = V_301 ;
if ( V_3 -> V_73 . V_74 . V_112 == V_118 ) {
if ( ! V_248 )
F_82 ( V_5 ) ;
} else {
F_27 ( & V_3 -> V_189 ,
V_287 -> V_120 . V_313 .
V_298 , V_77 ) ;
F_2 ( & V_31 -> V_5 , L_108 ,
V_3 -> V_189 ) ;
if ( ! V_248 )
F_95 ( V_3 ) ;
}
break;
case V_314 :
F_2 ( & V_31 -> V_5 , L_109 ) ;
F_6 ( V_5 ) ;
V_3 -> V_16 = V_123 ;
break;
case V_315 :
F_2 ( & V_31 -> V_5 , L_110 ) ;
break;
default:
F_2 ( & V_31 -> V_5 ,
L_111 ,
V_288 ,
( unsigned int ) F_37 ( & V_287 -> V_310 ) ) ;
break;
}
F_28 ( V_70 , & V_287 -> V_71 ) ;
}
F_31 ( V_3 ) ;
return V_294 ;
}
static void F_97 ( struct V_4 * V_5 , T_1 * V_3 ,
struct V_53 T_2 * V_287 )
{
int V_316 ;
unsigned int V_317 ;
void T_2 * V_318 ;
F_55 ( L_112 ) ;
V_317 = ( ( F_37 ( & V_287 -> V_120 . V_319 . V_320 [ 0 ] ) << 8 )
+ F_37 ( & V_287 -> V_120 . V_319 . V_320 [ 1 ] ) ) & V_321 ;
V_316 = ( F_37 ( & V_287 -> V_120 . V_319 . V_322 [ 0 ] ) << 8 )
+ F_37 ( & V_287 -> V_120 . V_319 . V_322 [ 1 ] ) ;
V_3 -> V_323 = F_37 ( & V_287 -> V_120 . V_319 . V_324 ) ;
V_318 = V_3 -> V_45 + V_317 ;
switch ( F_37 ( V_318 ) ) {
case V_143 :
F_55 ( L_113 ) ;
F_98 ( V_5 , V_287 , V_317 , V_316 ) ;
break;
case V_325 :
F_55 ( L_114 ) ;
if ( V_248 )
F_98 ( V_5 , V_287 , V_317 , V_316 ) ;
else
F_99 ( V_3 , V_287 , V_317 , V_316 ) ;
break;
case V_326 :
F_55 ( L_115 ) ;
if ( V_248 )
F_98 ( V_5 , V_287 , V_317 , V_316 ) ;
else
F_100 ( V_3 , V_287 , V_317 , V_316 ) ;
break;
case V_327 :
F_55 ( L_116 ) ;
break;
case V_328 :
F_55 ( L_117 ) ;
if ( V_248 )
F_98 ( V_5 , V_287 , V_317 , V_316 ) ;
F_101 ( V_3 , ( T_3 * ) & V_3 -> V_329 , V_317 ,
V_316 < sizeof( struct V_330 ) ?
V_316 : sizeof( struct V_330 ) ) ;
V_3 -> V_331 = 1 ;
F_87 ( V_5 ) ;
break;
default:
F_55 ( L_118 ,
( unsigned int ) F_37 ( V_318 ) ) ;
break;
}
}
static void F_98 ( struct V_4 * V_5 , struct V_53 T_2 * V_287 ,
unsigned int V_317 , int V_316 )
{
struct V_132 * V_133 = NULL ;
struct V_53 T_2 * V_332 = V_287 ;
T_1 * V_3 = F_4 ( V_5 ) ;
T_3 * V_333 ;
int V_334 ;
int V_289 ;
#ifdef F_5
int V_335 = V_3 -> V_323 ;
T_9 V_336 [ V_129 ] ;
#endif
if ( ! V_248 ) {
if ( V_163 ) {
if ( V_316 < ( V_181 + V_337 ) ||
V_316 >
( V_5 -> V_338 + V_337 + V_181 +
V_339 ) ) {
F_55 (
L_119 ,
V_316 ) ;
return;
}
} else {
if ( V_316 < ( V_181 + V_337 ) ||
V_316 >
( V_5 -> V_338 + V_337 + V_181 +
V_339 ) ) {
F_55 (
L_119 ,
V_316 ) ;
return;
}
}
}
F_55 ( L_120 ) ;
if ( F_37 ( & V_287 -> V_120 . V_319 . V_340 ) != 0xFF ) {
F_55 ( L_121 ) ;
V_289 = ( F_37 ( & V_287 -> V_120 . V_319 . V_341 [ 0 ] ) << 8 )
+ F_37 ( & V_287 -> V_120 . V_319 . V_341 [ 1 ] ) ;
V_334 = V_289 ;
V_332 = V_287 ;
do {
V_289 -=
( F_37 ( & V_332 -> V_120 . V_319 . V_322 [ 0 ] )
<< 8 )
+ F_37 ( & V_332 -> V_120 . V_319 . V_322 [ 1 ] ) ;
if ( F_37 ( & V_332 -> V_120 . V_319 . V_340 )
== 0xFF || V_289 < 0 )
break;
V_332 = F_25 ( V_3 )
+ F_37 ( & V_332 -> V_342 ) ;
} while ( 1 );
if ( V_289 < 0 ) {
F_55 (
L_122 ) ;
V_3 -> V_160 . V_343 ++ ;
F_102 ( V_3 , V_287 ) ;
return;
}
} else {
V_334 = V_316 ;
}
V_133 = F_103 ( V_334 + 5 ) ;
if ( V_133 == NULL ) {
F_55 ( L_123 ) ;
V_3 -> V_160 . V_343 ++ ;
if ( F_37 ( & V_287 -> V_120 . V_319 . V_340 ) != 0xFF )
F_102 ( V_3 , V_287 ) ;
return;
}
F_104 ( V_133 , 2 ) ;
F_55 ( L_124 , V_334 ,
V_316 ) ;
V_333 = F_105 ( V_133 , V_334 ) ;
V_333 +=
F_101 ( V_3 , V_333 , V_317 & V_321 , V_316 ) ;
#ifdef F_5
F_106 ( V_133 ,
F_107 ( struct V_344 , V_191 ) ,
V_336 , V_129 ) ;
#endif
if ( ! V_248 ) {
if ( ! V_163 ) {
F_108 ( V_133 , V_337 ) ;
} else {
F_109 ( V_3 , V_133 , V_334 ) ;
}
} else {
} ;
V_289 = 17 ;
if ( F_37 ( & V_287 -> V_120 . V_319 . V_340 ) != 0xFF ) {
V_332 = V_287 ;
F_55 ( L_125 ) ;
do {
V_332 = F_25 ( V_3 )
+
F_37 ( & V_332 -> V_120 . V_319 . V_340 ) ;
V_316 =
( ( F_37 ( & V_332 -> V_120 . V_319 . V_322 [ 0 ] )
<< 8 )
+
F_37 ( & V_332 -> V_120 . V_319 . V_322 [ 1 ] ) )
& V_321 ;
V_317 =
( ( F_37 ( & V_332 -> V_120 . V_319 . V_320 [ 0 ] ) <<
8 )
+ F_37 ( & V_332 -> V_120 . V_319 . V_320 [ 1 ] ) )
& V_321 ;
V_333 +=
F_101 ( V_3 , V_333 , V_317 , V_316 ) ;
} while ( V_289 -- &&
F_37 ( & V_332 -> V_120 . V_319 . V_340 ) !=
0xFF );
F_102 ( V_3 , V_287 ) ;
}
V_133 -> V_345 = F_110 ( V_133 , V_5 ) ;
F_111 ( V_133 ) ;
V_3 -> V_160 . V_346 ++ ;
V_3 -> V_160 . V_347 += V_334 ;
#ifdef F_5
if ( ! memcmp ( V_336 , V_3 -> V_189 , V_129 ) ) {
V_3 -> V_243 . V_238 . V_239 = V_335 ;
V_3 -> V_243 . V_238 . V_246 = 0x2 ;
}
{
struct V_348 V_243 ;
V_243 . V_239 = V_335 ;
V_243 . V_246 = 0x2 ;
F_112 ( V_5 , V_336 , & V_243 ) ;
}
#endif
}
static void F_109 ( T_1 * V_3 , struct V_132 * V_133 , int V_135 )
{
V_179 * V_349 = ( V_179 * ) ( V_133 -> V_92 + V_337 ) ;
struct V_350 * V_351 = (struct V_350 * ) V_133 -> V_92 ;
T_6 type = * ( T_6 * ) V_349 -> V_352 ;
int V_353 ;
struct V_174 * V_354 ;
T_3 V_355 [ V_77 ] ;
T_3 V_356 [ V_77 ] ;
static const T_3 V_357 [ 3 ] = { 0 , 0 , 0xf8 } ;
static const T_3 V_358 [ 3 ] = { 0 , 0 , 0 } ;
memcpy ( V_356 , F_113 ( V_351 ) , V_77 ) ;
memcpy ( V_355 , F_114 ( V_351 ) , V_77 ) ;
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
if ( V_349 -> V_359 != 0xaa || V_349 -> V_360 != 0xaa || V_349 -> V_361 != 3 ) {
F_55 ( L_126 ,
V_349 -> V_359 , V_349 -> V_360 , V_349 -> V_361 ) ;
V_353 = V_337 - V_181 ;
V_354 = (struct V_174 * ) ( V_133 -> V_92 + V_353 ) ;
V_354 -> V_175 = F_60 ( V_135 - V_337 ) ;
} else {
if ( memcmp ( V_349 -> V_180 , V_357 , 3 ) == 0 ) {
F_55 ( L_127 ) ;
V_353 = V_337
+ sizeof( struct V_179 ) - V_181 ;
V_354 = (struct V_174 * ) ( V_133 -> V_92 + V_353 ) ;
V_354 -> V_175 = type ;
} else if ( memcmp ( V_349 -> V_180 , V_358 , 3 ) == 0 ) {
switch ( F_59 ( type ) ) {
case V_178 :
case V_177 :
F_55 ( L_128 ) ;
V_353 = V_337 - V_181 ;
V_354 = (struct V_174 * ) ( V_133 -> V_92 + V_353 ) ;
V_354 -> V_175 =
F_60 ( V_135 - V_337 ) ;
break;
default:
F_55 ( L_129 ) ;
V_353 = V_337 +
sizeof( struct V_179 ) - V_181 ;
V_354 = (struct V_174 * ) ( V_133 -> V_92 + V_353 ) ;
V_354 -> V_175 = type ;
break;
}
} else {
F_14 ( L_130 ) ;
V_353 = V_337 - V_181 ;
V_354 = (struct V_174 * ) ( V_133 -> V_92 + V_353 ) ;
V_354 -> V_175 = type ;
}
}
F_108 ( V_133 , V_353 ) ;
F_55 ( L_131 , V_353 ,
V_133 -> V_92 ) ;
memcpy ( V_354 -> V_187 , V_356 , V_77 ) ;
memcpy ( V_354 -> V_192 , V_355 , V_77 ) ;
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
static int F_101 ( T_1 * V_3 , T_3 * V_362 , int V_317 ,
int V_134 )
{
int V_363 = ( V_317 + V_134 ) - ( V_321 + 1 ) ;
if ( V_363 <= 0 ) {
F_27 ( V_362 , V_3 -> V_45 + V_317 , V_134 ) ;
} else {
F_27 ( V_362 , V_3 -> V_45 + V_317 ,
V_134 - V_363 ) ;
F_27 ( V_362 + V_134 - V_363 , V_3 -> V_45 ,
V_363 ) ;
}
return V_134 ;
}
static void F_102 ( T_1 * V_3 , struct V_53 T_2 * V_287 )
{
struct V_53 T_2 * V_332 = V_287 ;
int V_289 = 17 ;
unsigned V_288 = F_37 ( & V_287 -> V_120 . V_319 . V_340 ) ;
while ( V_289 -- ) {
F_28 ( V_70 , & V_332 -> V_71 ) ;
if ( V_288 >= ( V_69 + V_293 ) ) {
F_55 ( L_86 ,
V_288 ) ;
break;
}
V_332 = F_25 ( V_3 ) + V_288 ;
V_288 = F_37 ( & V_332 -> V_120 . V_319 . V_340 ) ;
}
F_28 ( V_70 , & V_332 -> V_71 ) ;
}
static void F_95 ( T_1 * V_3 )
{
struct V_1 * V_31 = V_3 -> V_7 ;
F_2 ( & V_31 -> V_5 , L_132 ) ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_133 ) ;
return;
}
F_11 ( & V_3 -> V_28 ) ;
if ( F_52 ( V_3 , V_3 -> V_189 , V_139 ) ) {
V_3 -> V_28 . V_93 = F_39 ;
} else {
V_3 -> V_28 . V_93 = F_85 ;
}
V_3 -> V_28 . V_89 = V_90 + V_91 * 2 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
F_36 ( & V_3 -> V_28 ) ;
V_3 -> V_18 = V_364 ;
}
static void F_99 ( T_1 * V_3 , struct V_53 T_2 * V_287 ,
unsigned int V_317 , int V_316 )
{
T_3 V_365 [ 256 ] ;
struct V_366 * V_367 = (struct V_366 * ) V_365 ;
F_11 ( & V_3 -> V_28 ) ;
F_101 ( V_3 , V_365 , V_317 , V_316 & 0xff ) ;
if ( V_3 -> V_73 . V_74 . V_112 == V_118 ) {
F_55 ( L_134 ,
V_367 -> V_120 [ 0 ] , V_367 -> V_120 [ 1 ] , V_367 -> V_120 [ 2 ] , V_367 -> V_120 [ 3 ] ,
V_367 -> V_120 [ 4 ] , V_367 -> V_120 [ 5 ] ) ;
if ( V_367 -> V_120 [ 2 ] == 1 ) {
F_55 ( L_135 ) ;
if ( ! F_52
( V_3 , V_367 -> V_183 . V_191 , V_368 ) ) {
V_3 -> V_18 = V_137 ;
memcpy ( V_3 -> V_138 , V_367 -> V_183 . V_191 ,
V_77 ) ;
}
}
} else {
if ( V_3 -> V_18 == V_364 ) {
if ( V_367 -> V_120 [ 2 ] == 2 ) {
if ( ( V_367 -> V_120 [ 3 ] | V_367 -> V_120 [ 4 ] ) == 0 ) {
F_55 ( L_136 ) ;
V_3 -> V_16 = V_369 ;
F_115 ( V_3 ) ;
V_3 -> V_18 =
V_140 ;
} else {
F_55 ( L_137 ) ;
V_3 -> V_16 = V_370 ;
F_39 ( ( T_4 ) V_3 ) ;
V_3 -> V_18 =
V_19 ;
}
}
}
}
}
static void F_115 ( T_1 * V_3 )
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
F_28 ( V_303 , & V_55 -> V_86 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_74 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
F_11 ( & V_3 -> V_28 ) ;
V_3 -> V_28 . V_89 = V_90 + V_91 * 2 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
V_3 -> V_28 . V_93 = F_39 ;
F_36 ( & V_3 -> V_28 ) ;
V_3 -> V_16 = V_305 ;
return;
}
if ( ! V_248 )
F_82 ( V_5 ) ;
}
static void F_100 ( T_1 * V_3 , struct V_53 T_2 * V_287 ,
unsigned int V_317 , int V_316 )
{
F_55 ( L_141 ) ;
V_3 -> V_18 = V_19 ;
}
static void F_31 ( T_1 * V_3 )
{
F_28 ( 0 , V_3 -> V_47 + V_249 + V_371 ) ;
}
static int F_116 ( struct V_372 * V_203 , void * V_373 )
{
int V_33 ;
struct V_1 * V_31 ;
struct V_4 * V_5 ;
T_1 * V_3 ;
T_3 * V_54 ;
struct V_374 * V_375 ;
T_3 V_376 [ 33 ] ;
V_31 = V_29 ;
if ( ! V_31 )
return 0 ;
V_5 = (struct V_4 * ) V_31 -> V_15 ;
if ( ! V_5 )
return 0 ;
V_3 = F_4 ( V_5 ) ;
if ( ! V_3 )
return 0 ;
F_117 ( V_203 , L_142 ) ;
F_118 ( V_203 , L_143 , V_377 ) ;
F_117 ( V_203 , L_144 ) ;
if ( V_3 -> V_64 == 0x55 )
F_117 ( V_203 , L_145 ) ;
else
F_118 ( V_203 , L_146 ,
V_3 -> V_64 , V_3 -> V_66 , V_3 -> V_67 ) ;
for ( V_33 = 0 ; V_33 < 32 ; V_33 ++ )
V_376 [ V_33 ] = V_3 -> V_73 . V_82 . V_115 [ V_33 ] ;
V_376 [ 32 ] = 0 ;
F_118 ( V_203 , L_147 ,
V_378 [ V_3 -> V_73 . V_82 . V_112 ] , V_376 ) ;
V_54 = V_3 -> V_189 ;
F_118 ( V_203 , L_148 , V_54 ) ;
F_118 ( V_203 , L_149 ,
V_3 -> V_73 . V_82 . V_103 ) ;
V_33 = V_3 -> V_16 ;
if ( V_33 < 0 )
V_33 = 10 ;
if ( V_33 > 16 )
V_33 = 10 ;
F_118 ( V_203 , L_150 , V_16 [ V_33 ] ) ;
F_118 ( V_203 , L_151 , V_379 [ V_163 ] ) ;
F_118 ( V_203 , L_152 , V_3 -> V_323 ) ;
if ( V_3 -> V_331 ) {
F_118 ( V_203 , L_153 ,
V_3 -> V_329 . V_380 [ 0 ]
+ 256 * V_3 -> V_329 . V_380 [ 1 ] ) ;
V_54 = V_3 -> V_329 . V_381 ;
if ( V_54 [ 0 ] == V_382 )
V_54 += V_54 [ 1 ] + 2 ;
else {
F_118 ( V_203 ,
L_154 ,
V_54 [ 0 ] ) ;
return 0 ;
}
if ( V_54 [ 0 ] == V_383 ) {
F_117 ( V_203 , L_155 ) ;
for ( V_33 = 2 ; V_33 < V_54 [ 1 ] + 2 ; V_33 ++ )
F_118 ( V_203 , L_156 , V_54 [ V_33 ] ) ;
F_119 ( V_203 , '\n' ) ;
V_54 += V_54 [ 1 ] + 2 ;
} else {
F_117 ( V_203 , L_157 ) ;
return 0 ;
}
if ( V_54 [ 0 ] == V_384 ) {
V_375 = (struct V_374 * ) V_54 ;
F_118 ( V_203 , L_158 ,
V_375 -> V_385 [ 0 ] +
256 * V_375 -> V_385 [ 1 ] ) ;
F_118 ( V_203 , L_159 ,
V_375 -> V_386 ) ;
F_118 ( V_203 , L_160 ,
V_375 -> V_387 ) ;
F_118 ( V_203 , L_161 ,
V_375 -> V_388 ) ;
V_54 += V_54 [ 1 ] + 2 ;
} else {
F_117 ( V_203 ,
L_162 ) ;
return 0 ;
}
} else {
F_117 ( V_203 , L_163 ) ;
}
return 0 ;
}
static int F_120 ( struct V_389 * V_389 , struct V_390 * V_390 )
{
return F_121 ( V_390 , F_116 , NULL ) ;
}
static int F_52 ( T_1 * V_3 , T_3 * V_362 , int V_391 )
{
int V_153 ;
struct V_51 T_2 * V_55 ;
struct V_151 T_2 * V_152 ;
int V_79 ;
if ( ( V_79 = F_56 ( V_3 ) ) < 0 ) {
F_55 ( L_164 ) ;
return - 1 ;
}
V_55 = F_24 ( V_3 ) + V_79 ;
V_153 = V_159 + ( V_79 << 11 ) ;
F_28 ( V_164 , & V_55 -> V_86 ) ;
F_28 ( V_153 >> 8 , V_55 -> V_120 . V_165 . V_166 ) ;
F_28 ( 0x20 , V_55 -> V_120 . V_165 . V_166 + 1 ) ;
F_28 ( V_392 , V_55 -> V_120 . V_165 . V_167 ) ;
F_28 ( V_393 ,
V_55 -> V_120 . V_165 . V_167 + 1 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_165 . V_169 ) ;
V_152 = V_3 -> V_44 + V_153 ;
F_28 ( V_182 | V_325 , & V_152 -> V_183 . V_184 ) ;
F_28 ( 0 , & V_152 -> V_183 . V_185 ) ;
F_33 ( V_152 -> V_183 . V_186 , V_362 , V_77 ) ;
F_33 ( V_152 -> V_183 . V_191 , V_3 -> V_73 . V_74 . V_75 , V_77 ) ;
F_33 ( V_152 -> V_183 . V_188 , V_3 -> V_189 , V_77 ) ;
F_122 ( V_152 -> V_120 , 0 , 6 ) ;
F_28 ( V_391 & 0xff , V_152 -> V_120 + 2 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_55 (
L_165 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
return - 1 ;
}
return 0 ;
}
static T_10 F_123 ( struct V_390 * V_390 ,
const char T_11 * V_394 , T_12 V_395 , T_13 * V_396 )
{
static char V_397 [ 33 ] ;
unsigned int V_135 = V_395 ;
if ( V_135 > 32 )
V_135 = 32 ;
memset ( V_397 , 0 , 33 ) ;
if ( F_124 ( V_397 , V_394 , V_135 ) )
return - V_398 ;
V_114 = V_397 ;
return V_395 ;
}
static T_10 F_125 ( struct V_390 * V_390 , const char T_11 * V_394 ,
T_12 V_395 , T_13 * V_396 )
{
static char V_399 [ 10 ] ;
char * V_54 ;
int V_400 , V_135 ;
if ( ! V_395 )
return 0 ;
if ( V_395 > 9 )
return - V_216 ;
if ( F_124 ( V_399 , V_394 , V_395 ) )
return - V_398 ;
V_54 = V_399 ;
V_400 = 0 ;
V_135 = V_395 ;
do {
unsigned int V_376 = * V_54 - '0' ;
if ( V_376 > 9 )
return - V_216 ;
V_400 = V_400 * 10 + V_376 ;
V_54 ++ ;
} while ( -- V_135 );
* ( int * ) F_126 ( V_390 -> V_401 . V_402 -> V_403 ) -> V_92 = V_400 ;
return V_395 ;
}
static int T_14 F_127 ( void )
{
int V_404 ;
F_55 ( L_143 , V_377 ) ;
V_404 = F_128 ( & V_405 ) ;
F_55 ( L_166 ,
V_404 ) ;
#ifdef F_129
F_130 ( L_167 , NULL ) ;
F_131 ( L_168 , 0 , NULL , & V_406 ) ;
F_131 ( L_169 , V_407 , NULL , & V_408 ) ;
F_132 ( L_170 , V_407 , NULL , & V_409 , & V_56 ) ;
F_132 ( L_171 , V_407 , NULL , & V_409 , & V_163 ) ;
#endif
if ( V_163 != 0 )
V_163 = 1 ;
return 0 ;
}
static void T_15 F_133 ( void )
{
F_55 ( L_172 ) ;
#ifdef F_129
F_134 ( L_168 , NULL ) ;
F_134 ( L_169 , NULL ) ;
F_134 ( L_170 , NULL ) ;
F_134 ( L_171 , NULL ) ;
F_134 ( L_167 , NULL ) ;
#endif
F_135 ( & V_405 ) ;
}
