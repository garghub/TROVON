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
T_3 V_210 [ V_208 + 1 ] ;
memcpy ( V_198 , V_3 -> V_73 . V_82 . V_115 , V_208 ) ;
memcpy ( V_210 , V_3 -> V_73 . V_82 . V_115 , V_208 ) ;
V_210 [ V_208 ] = '\0' ;
V_197 -> V_114 . V_134 = strlen ( V_210 ) ;
V_197 -> V_114 . V_10 = 1 ;
return 0 ;
}
static int F_66 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
memcpy ( V_197 -> V_211 . V_212 , V_3 -> V_189 , V_129 ) ;
V_197 -> V_211 . V_213 = V_214 ;
return 0 ;
}
static int F_67 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( ( V_197 -> V_215 . V_216 != 1000000 ) && ( V_197 -> V_215 . V_216 != 2000000 ) )
return - V_217 ;
if ( ( V_3 -> V_64 == 0x55 ) &&
( V_197 -> V_215 . V_216 == 2000000 ) )
V_3 -> V_170 = 3 ;
else
V_3 -> V_170 = V_197 -> V_215 . V_216 / 500000 ;
return 0 ;
}
static int F_68 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_170 == 3 )
V_197 -> V_215 . V_216 = 2000000 ;
else
V_197 -> V_215 . V_216 = V_3 -> V_170 * 500000 ;
V_197 -> V_215 . V_218 = 0 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_219 = V_197 -> V_220 . V_216 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_220 . V_221 )
V_219 = 32767 ;
else {
if ( ( V_219 < 0 ) || ( V_219 > 2347 ) )
return - V_217 ;
}
V_3 -> V_73 . V_82 . V_222 [ 0 ] = ( V_219 >> 8 ) & 0xFF ;
V_3 -> V_73 . V_82 . V_222 [ 1 ] = V_219 & 0xFF ;
return - V_200 ;
}
static int F_70 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_220 . V_216 = ( V_3 -> V_73 . V_82 . V_222 [ 0 ] << 8 )
+ V_3 -> V_73 . V_82 . V_222 [ 1 ] ;
V_197 -> V_220 . V_221 = ( V_197 -> V_220 . V_216 == 32767 ) ;
V_197 -> V_220 . V_218 = 1 ;
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_223 = V_197 -> V_224 . V_216 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
if ( V_197 -> V_224 . V_221 )
V_223 = 32767 ;
else {
if ( ( V_223 < 256 ) || ( V_223 > 2347 ) )
return - V_217 ;
}
V_3 -> V_73 . V_82 . V_225 [ 0 ] = ( V_223 >> 8 ) & 0xFF ;
V_3 -> V_73 . V_82 . V_225 [ 1 ] = V_223 & 0xFF ;
return - V_200 ;
}
static int F_72 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
V_197 -> V_224 . V_216 = ( V_3 -> V_73 . V_82 . V_225 [ 0 ] << 8 )
+ V_3 -> V_73 . V_82 . V_225 [ 1 ] ;
V_197 -> V_224 . V_221 = ( V_197 -> V_224 . V_216 == 32767 ) ;
V_197 -> V_224 . V_218 = 1 ;
return 0 ;
}
static int F_73 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
int V_199 = - V_200 ;
char V_226 = 1 ;
if ( V_3 -> V_16 != V_78 )
return - V_201 ;
switch ( V_197 -> V_227 ) {
case V_228 :
V_226 = 0 ;
case V_229 :
V_3 -> V_73 . V_82 . V_112 = V_226 ;
break;
default:
V_199 = - V_217 ;
}
return V_199 ;
}
static int F_74 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
if ( V_3 -> V_73 . V_82 . V_112 )
V_197 -> V_227 = V_229 ;
else
V_197 -> V_227 = V_228 ;
return 0 ;
}
static int F_75 ( struct V_4 * V_5 , struct V_194 * V_195 ,
union V_196 * V_197 , char * V_198 )
{
struct V_230 * V_231 = (struct V_230 * ) V_198 ;
memset ( V_231 , 0 , sizeof( struct V_230 ) ) ;
V_197 -> V_92 . V_134 = sizeof( struct V_230 ) ;
V_231 -> V_232 = V_233 ;
V_231 -> V_234 = 9 ;
V_231 -> V_235 = 1.1 * 1000 * 1000 ;
V_231 -> V_236 = V_105 [ ( int ) V_95 ] ;
V_231 -> V_237 = 0 ;
V_231 -> V_238 . V_239 = 0 ;
V_231 -> V_238 . V_240 = 255 ;
V_231 -> V_238 . V_241 = 255 ;
V_231 -> V_242 = 2 ;
V_231 -> V_215 [ 0 ] = 1000000 ;
V_231 -> V_215 [ 1 ] = 2000000 ;
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
struct V_117 T_2 * V_54 = V_3 -> V_44 + V_243 ;
V_3 -> V_244 . V_117 = V_3 -> V_16 ;
#ifdef F_5
if ( ( V_3 -> V_27 . V_245 > 0 )
&& ( V_3 -> V_73 . V_82 . V_112 == 0 ) ) {
V_3 -> V_244 . V_239 . V_239 = V_3 -> V_27 . V_246 [ 0 ] . V_239 ;
V_3 -> V_244 . V_239 . V_240 = V_3 -> V_27 . V_246 [ 0 ] . V_240 ;
V_3 -> V_244 . V_239 . V_241 = V_3 -> V_27 . V_246 [ 0 ] . V_241 ;
V_3 -> V_244 . V_239 . V_247 =
V_3 -> V_27 . V_246 [ 0 ] . V_247 ;
}
#endif
if ( F_26 ( V_31 ) ) {
V_3 -> V_244 . V_239 . V_241 = F_37 ( & V_54 -> V_248 ) ;
V_3 -> V_244 . V_239 . V_247 |= 4 ;
}
return & V_3 -> V_244 ;
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
if ( V_249 )
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
( F_37 ( V_3 -> V_47 + V_250 + V_251 ) &
V_252 ) )
V_33 -- ;
if ( V_33 == 0 ) {
F_2 ( & V_31 -> V_5 , L_62 ) ;
return - 1 ;
}
F_28 ( V_51 , V_3 -> V_44 + V_253 ) ;
F_28 ( V_252 , V_3 -> V_47 + V_250 + V_251 ) ;
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
if ( F_84 ( 0 , & V_3 -> V_254 ) ) {
F_2 ( & V_31 -> V_5 , L_64 ) ;
return V_156 ;
}
for ( V_33 = 0 ; V_33 < V_255 ; V_33 ++ ) {
if ( F_37 ( & ( V_55 + V_33 ) -> V_71 ) == V_70 ) {
F_28 ( V_256 , & ( V_55 + V_33 ) -> V_71 ) ;
F_28 ( V_257 , & ( V_55 + V_33 ) -> V_31 ) ;
V_3 -> V_254 = 0 ;
return V_33 ;
}
}
V_3 -> V_254 = 0 ;
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
if ( F_84 ( 0 , & V_3 -> V_258 ) ) {
F_2 ( & V_31 -> V_5 , L_67 ) ;
return V_156 ;
}
for ( V_33 = V_255 ; V_33 < V_69 ; V_33 ++ ) {
if ( F_37 ( & ( V_55 + V_33 ) -> V_71 ) == V_70 ) {
F_28 ( V_256 , & ( V_55 + V_33 ) -> V_71 ) ;
F_28 ( V_257 , & ( V_55 + V_33 ) -> V_31 ) ;
V_3 -> V_258 = 0 ;
return V_33 ;
}
}
V_3 -> V_258 = 0 ;
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
static int F_30 ( char * V_259 , T_3 * V_260 )
{
int V_135 ;
int V_33 , V_261 , V_262 ;
int V_117 ;
if ( V_259 == NULL )
return 0 ;
if ( ( V_135 = strlen ( V_259 ) ) < 2 )
return 0 ;
memset ( V_260 , 0 , V_77 ) ;
V_117 = 1 ;
V_261 = V_135 - 1 ;
if ( V_261 > 12 )
V_261 = 12 ;
V_33 = 5 ;
while ( V_261 > 0 ) {
if ( ( V_262 = F_86 ( V_259 [ V_261 -- ] ) ) != - 1 )
V_260 [ V_33 ] = V_262 ;
else
return 0 ;
if ( V_261 == 0 )
break;
if ( ( V_262 = F_86 ( V_259 [ V_261 -- ] ) ) != - 1 )
V_260 [ V_33 ] += V_262 << 4 ;
else
return 0 ;
if ( ! V_33 -- )
break;
}
return V_117 ;
}
static struct V_263 * F_87 ( struct V_4 * V_5 )
{
T_1 * V_3 = F_4 ( V_5 ) ;
struct V_1 * V_31 = V_3 -> V_7 ;
struct V_117 T_2 * V_54 = V_3 -> V_44 + V_243 ;
if ( ! ( F_26 ( V_31 ) ) ) {
F_2 ( & V_31 -> V_5 , L_71 ) ;
return & V_3 -> V_160 ;
}
if ( F_37 ( & V_54 -> V_264 ) ) {
V_3 -> V_160 . V_265 += F_88 ( F_89 ( & V_54 -> V_266 ) ) ;
F_28 ( 0 , & V_54 -> V_266 ) ;
F_28 ( 0 , & V_54 -> V_264 ) ;
}
if ( F_37 ( & V_54 -> V_267 ) ) {
V_3 -> V_160 . V_268 +=
F_88 ( F_89 ( & V_54 -> V_269 ) ) ;
F_28 ( 0 , & V_54 -> V_269 ) ;
F_28 ( 0 , & V_54 -> V_267 ) ;
}
if ( F_37 ( & V_54 -> V_270 ) ) {
V_3 -> V_160 . V_271 += F_88 ( F_89 ( & V_54 -> V_272 ) ) ;
F_28 ( 0 , & V_54 -> V_272 ) ;
F_28 ( 0 , & V_54 -> V_270 ) ;
}
return & V_3 -> V_160 ;
}
static void F_90 ( struct V_4 * V_5 , T_3 V_273 , T_3 * V_216 ,
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
F_28 ( V_274 , & V_55 -> V_86 ) ;
F_28 ( V_273 , & V_55 -> V_120 . V_122 . V_275 ) ;
F_28 ( 1 , & V_55 -> V_120 . V_122 . V_276 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_122 . V_277 ) ;
for ( V_33 = 0 ; V_33 < V_135 ; V_33 ++ ) {
F_28 ( V_216 [ V_33 ] , V_3 -> V_44 + V_80 ) ;
}
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_74 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
}
}
static void F_91 ( struct V_4 * V_5 , int V_278 )
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
F_28 ( V_279 , & V_55 -> V_86 ) ;
if ( V_278 ) {
F_28 ( 0xff , & V_55 -> V_120 ) ;
V_3 -> V_20 = 0xff ;
} else {
struct V_280 * V_281 ;
int V_33 = 0 ;
F_92 (ha, dev) {
F_33 ( V_54 , V_281 -> V_153 , V_129 ) ;
F_2 ( & V_31 -> V_5 , L_78 ,
V_281 -> V_153 ) ;
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
T_3 V_282 ;
F_55 ( L_81 , V_5 ) ;
if ( V_5 -> V_10 & V_283 ) {
if ( V_3 -> V_73 . V_82 . V_284 == 0 ) {
F_55 ( L_82 ) ;
V_3 -> V_73 . V_82 . V_284 = 1 ;
V_282 = 1 ;
F_90 ( V_5 , V_285 ,
& V_282 , sizeof( V_282 ) ) ;
}
} else {
if ( V_3 -> V_73 . V_82 . V_284 == 1 ) {
F_55 ( L_83 ) ;
V_3 -> V_73 . V_82 . V_284 = 0 ;
V_282 = 0 ;
F_90 ( V_5 , V_285 ,
& V_282 , sizeof( V_282 ) ) ;
}
}
if ( V_5 -> V_10 & V_286 )
F_91 ( V_5 , 1 ) ;
else {
if ( V_3 -> V_20 != F_94 ( V_5 ) )
F_91 ( V_5 , 0 ) ;
}
}
static T_8 V_21 ( int V_37 , void * V_287 )
{
struct V_4 * V_5 = (struct V_4 * ) V_287 ;
struct V_1 * V_31 ;
T_1 * V_3 ;
struct V_51 T_2 * V_55 ;
struct V_53 T_2 * V_288 ;
T_3 V_289 ;
T_3 V_210 ;
T_3 V_86 ;
T_3 V_117 ;
T_3 V_290 [ V_116 + 1 ] ;
if ( V_5 == NULL )
return V_291 ;
F_55 ( L_84 , V_5 ) ;
V_3 = F_4 ( V_5 ) ;
V_31 = V_3 -> V_7 ;
if ( ! F_26 ( V_31 ) ) {
F_55 (
L_85 ) ;
return V_291 ;
}
V_289 = F_37 ( & ( (struct V_292 T_2 * ) ( V_3 -> V_44 ) ) -> V_293 ) ;
if ( V_289 >= ( V_69 + V_294 ) ) {
F_2 ( & V_31 -> V_5 , L_86 , V_289 ) ;
F_31 ( V_3 ) ;
return V_295 ;
}
if ( V_289 < V_69 ) {
V_55 = F_24 ( V_3 ) + V_289 ;
V_86 = F_37 ( & V_55 -> V_86 ) ;
V_117 = F_37 ( & V_55 -> V_71 ) ;
switch ( V_86 ) {
case V_85 :
F_11 ( & V_3 -> V_28 ) ;
if ( V_117 == V_296 ) {
F_2 ( & V_31 -> V_5 ,
L_87 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_88 ) ;
}
break;
case V_274 :
F_2 ( & V_31 -> V_5 , L_89 ) ;
if ( V_117 != V_296 ) {
V_210 =
F_37 ( & V_55 -> V_120 . V_122 .
V_277 ) ;
F_2 ( & V_31 -> V_5 ,
L_90 ,
V_210 ) ;
}
break;
case V_297 :
F_2 ( & V_31 -> V_5 , L_91 ) ;
break;
case V_279 :
F_2 ( & V_31 -> V_5 ,
L_92 ) ;
break;
case V_298 :
F_2 ( & V_31 -> V_5 ,
L_93 ) ;
break;
case V_119 :
case V_124 :
memcpy ( V_290 , V_3 -> V_73 . V_74 . V_115 ,
V_116 ) ;
V_290 [ V_116 ] = '\0' ;
if ( V_117 == V_296 ) {
if ( F_37
( & V_55 -> V_120 . V_121 . V_126 ) ==
1 ) {
F_2 ( & V_31 -> V_5 ,
L_94 ,
V_290 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_95 ,
V_290 ) ;
}
F_27 ( & V_3 -> V_189 ,
V_55 -> V_120 . V_121 . V_299 ,
V_77 ) ;
if ( V_3 -> V_64 == 0x55 )
V_3 -> V_170 = 3 ;
else
V_3 -> V_170 =
F_37 ( & V_55 -> V_120 . V_121 .
V_170 ) ;
V_3 -> V_300 =
F_37 ( & V_55 -> V_120 . V_121 . V_300 ) ;
if ( ! V_249 && ( V_3 -> V_56 == V_301 )
&& ! ( V_3 -> V_73 . V_74 . V_113 ) ) {
F_95 ( V_3 ) ;
}
V_3 -> V_16 = V_302 ;
} else {
V_3 -> V_16 = V_303 ;
F_11 ( & V_3 -> V_28 ) ;
V_3 -> V_28 . V_89 = V_90 + V_91 * 5 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
if ( V_117 == V_119 ) {
F_2 ( & V_31 -> V_5 ,
L_96 ,
V_290 ) ;
V_3 -> V_28 . V_93 = F_38 ;
} else {
F_2 ( & V_31 -> V_5 ,
L_97 ,
V_290 ) ;
V_3 -> V_28 . V_93 = F_39 ;
}
F_36 ( & V_3 -> V_28 ) ;
}
break;
case V_304 :
if ( V_117 == V_296 ) {
V_3 -> V_16 = V_305 ;
F_2 ( & V_31 -> V_5 , L_98 ) ;
} else {
F_2 ( & V_31 -> V_5 , L_99 ) ;
V_3 -> V_16 = V_306 ;
F_39 ( ( T_4 ) V_3 ) ;
}
break;
case V_164 :
if ( V_117 == V_296 ) {
F_2 ( & V_31 -> V_5 ,
L_100 ) ;
} else {
F_2 ( & V_31 -> V_5 ,
L_101 ) ;
}
if ( ! V_249 )
F_82 ( V_5 ) ;
F_96 ( V_5 ) ;
break;
case V_307 :
F_2 ( & V_31 -> V_5 , L_102 ) ;
break;
case V_308 :
F_2 ( & V_31 -> V_5 ,
L_103 ) ;
break;
case V_309 :
F_2 ( & V_31 -> V_5 , L_104 ) ;
break;
case V_310 :
F_2 ( & V_31 -> V_5 ,
L_105 ) ;
break;
default:
F_2 ( & V_31 -> V_5 ,
L_106 ,
V_289 , V_86 ) ;
}
F_28 ( V_70 , & V_55 -> V_71 ) ;
} else {
V_288 = F_25 ( V_3 ) + V_289 ;
switch ( F_37 ( & V_288 -> V_311 ) ) {
case V_312 :
F_97 ( V_5 , V_3 , V_288 ) ;
break;
case V_313 :
F_2 ( & V_31 -> V_5 , L_107 ) ;
V_3 -> V_16 = V_302 ;
if ( V_3 -> V_73 . V_74 . V_112 == V_118 ) {
if ( ! V_249 )
F_82 ( V_5 ) ;
} else {
F_27 ( & V_3 -> V_189 ,
V_288 -> V_120 . V_314 .
V_299 , V_77 ) ;
F_2 ( & V_31 -> V_5 , L_108 ,
V_3 -> V_189 ) ;
if ( ! V_249 )
F_95 ( V_3 ) ;
}
break;
case V_315 :
F_2 ( & V_31 -> V_5 , L_109 ) ;
F_6 ( V_5 ) ;
V_3 -> V_16 = V_123 ;
break;
case V_316 :
F_2 ( & V_31 -> V_5 , L_110 ) ;
break;
default:
F_2 ( & V_31 -> V_5 ,
L_111 ,
V_289 ,
( unsigned int ) F_37 ( & V_288 -> V_311 ) ) ;
break;
}
F_28 ( V_70 , & V_288 -> V_71 ) ;
}
F_31 ( V_3 ) ;
return V_295 ;
}
static void F_97 ( struct V_4 * V_5 , T_1 * V_3 ,
struct V_53 T_2 * V_288 )
{
int V_317 ;
unsigned int V_318 ;
void T_2 * V_319 ;
F_55 ( L_112 ) ;
V_318 = ( ( F_37 ( & V_288 -> V_120 . V_320 . V_321 [ 0 ] ) << 8 )
+ F_37 ( & V_288 -> V_120 . V_320 . V_321 [ 1 ] ) ) & V_322 ;
V_317 = ( F_37 ( & V_288 -> V_120 . V_320 . V_323 [ 0 ] ) << 8 )
+ F_37 ( & V_288 -> V_120 . V_320 . V_323 [ 1 ] ) ;
V_3 -> V_324 = F_37 ( & V_288 -> V_120 . V_320 . V_325 ) ;
V_319 = V_3 -> V_45 + V_318 ;
switch ( F_37 ( V_319 ) ) {
case V_143 :
F_55 ( L_113 ) ;
F_98 ( V_5 , V_288 , V_318 , V_317 ) ;
break;
case V_326 :
F_55 ( L_114 ) ;
if ( V_249 )
F_98 ( V_5 , V_288 , V_318 , V_317 ) ;
else
F_99 ( V_3 , V_288 , V_318 , V_317 ) ;
break;
case V_327 :
F_55 ( L_115 ) ;
if ( V_249 )
F_98 ( V_5 , V_288 , V_318 , V_317 ) ;
else
F_100 ( V_3 , V_288 , V_318 , V_317 ) ;
break;
case V_328 :
F_55 ( L_116 ) ;
break;
case V_329 :
F_55 ( L_117 ) ;
if ( V_249 )
F_98 ( V_5 , V_288 , V_318 , V_317 ) ;
F_101 ( V_3 , ( T_3 * ) & V_3 -> V_330 , V_318 ,
V_317 < sizeof( struct V_331 ) ?
V_317 : sizeof( struct V_331 ) ) ;
V_3 -> V_332 = 1 ;
F_87 ( V_5 ) ;
break;
default:
F_55 ( L_118 ,
( unsigned int ) F_37 ( V_319 ) ) ;
break;
}
}
static void F_98 ( struct V_4 * V_5 , struct V_53 T_2 * V_288 ,
unsigned int V_318 , int V_317 )
{
struct V_132 * V_133 = NULL ;
struct V_53 T_2 * V_333 = V_288 ;
T_1 * V_3 = F_4 ( V_5 ) ;
T_3 * V_334 ;
int V_335 ;
int V_210 ;
#ifdef F_5
int V_336 = V_3 -> V_324 ;
T_9 V_337 [ V_129 ] ;
#endif
if ( ! V_249 ) {
if ( V_163 ) {
if ( V_317 < ( V_181 + V_338 ) ||
V_317 >
( V_5 -> V_339 + V_338 + V_181 +
V_340 ) ) {
F_55 (
L_119 ,
V_317 ) ;
return;
}
} else {
if ( V_317 < ( V_181 + V_338 ) ||
V_317 >
( V_5 -> V_339 + V_338 + V_181 +
V_340 ) ) {
F_55 (
L_119 ,
V_317 ) ;
return;
}
}
}
F_55 ( L_120 ) ;
if ( F_37 ( & V_288 -> V_120 . V_320 . V_341 ) != 0xFF ) {
F_55 ( L_121 ) ;
V_210 = ( F_37 ( & V_288 -> V_120 . V_320 . V_342 [ 0 ] ) << 8 )
+ F_37 ( & V_288 -> V_120 . V_320 . V_342 [ 1 ] ) ;
V_335 = V_210 ;
V_333 = V_288 ;
do {
V_210 -=
( F_37 ( & V_333 -> V_120 . V_320 . V_323 [ 0 ] )
<< 8 )
+ F_37 ( & V_333 -> V_120 . V_320 . V_323 [ 1 ] ) ;
if ( F_37 ( & V_333 -> V_120 . V_320 . V_341 )
== 0xFF || V_210 < 0 )
break;
V_333 = F_25 ( V_3 )
+ F_37 ( & V_333 -> V_343 ) ;
} while ( 1 );
if ( V_210 < 0 ) {
F_55 (
L_122 ) ;
V_3 -> V_160 . V_344 ++ ;
F_102 ( V_3 , V_288 ) ;
return;
}
} else {
V_335 = V_317 ;
}
V_133 = F_103 ( V_335 + 5 ) ;
if ( V_133 == NULL ) {
F_55 ( L_123 ) ;
V_3 -> V_160 . V_344 ++ ;
if ( F_37 ( & V_288 -> V_120 . V_320 . V_341 ) != 0xFF )
F_102 ( V_3 , V_288 ) ;
return;
}
F_104 ( V_133 , 2 ) ;
F_55 ( L_124 , V_335 ,
V_317 ) ;
V_334 = F_105 ( V_133 , V_335 ) ;
V_334 +=
F_101 ( V_3 , V_334 , V_318 & V_322 , V_317 ) ;
#ifdef F_5
F_106 ( V_133 ,
F_107 ( struct V_345 , V_191 ) ,
V_337 , V_129 ) ;
#endif
if ( ! V_249 ) {
if ( ! V_163 ) {
F_108 ( V_133 , V_338 ) ;
} else {
F_109 ( V_3 , V_133 , V_335 ) ;
}
} else {
} ;
V_210 = 17 ;
if ( F_37 ( & V_288 -> V_120 . V_320 . V_341 ) != 0xFF ) {
V_333 = V_288 ;
F_55 ( L_125 ) ;
do {
V_333 = F_25 ( V_3 )
+
F_37 ( & V_333 -> V_120 . V_320 . V_341 ) ;
V_317 =
( ( F_37 ( & V_333 -> V_120 . V_320 . V_323 [ 0 ] )
<< 8 )
+
F_37 ( & V_333 -> V_120 . V_320 . V_323 [ 1 ] ) )
& V_322 ;
V_318 =
( ( F_37 ( & V_333 -> V_120 . V_320 . V_321 [ 0 ] ) <<
8 )
+ F_37 ( & V_333 -> V_120 . V_320 . V_321 [ 1 ] ) )
& V_322 ;
V_334 +=
F_101 ( V_3 , V_334 , V_318 , V_317 ) ;
} while ( V_210 -- &&
F_37 ( & V_333 -> V_120 . V_320 . V_341 ) !=
0xFF );
F_102 ( V_3 , V_288 ) ;
}
V_133 -> V_346 = F_110 ( V_133 , V_5 ) ;
F_111 ( V_133 ) ;
V_3 -> V_160 . V_347 ++ ;
V_3 -> V_160 . V_348 += V_335 ;
#ifdef F_5
if ( ! memcmp ( V_337 , V_3 -> V_189 , V_129 ) ) {
V_3 -> V_244 . V_239 . V_240 = V_336 ;
V_3 -> V_244 . V_239 . V_247 = 0x2 ;
}
{
struct V_349 V_244 ;
V_244 . V_240 = V_336 ;
V_244 . V_247 = 0x2 ;
F_112 ( V_5 , V_337 , & V_244 ) ;
}
#endif
}
static void F_109 ( T_1 * V_3 , struct V_132 * V_133 , int V_135 )
{
V_179 * V_350 = ( V_179 * ) ( V_133 -> V_92 + V_338 ) ;
struct V_351 * V_352 = (struct V_351 * ) V_133 -> V_92 ;
T_6 type = * ( T_6 * ) V_350 -> V_353 ;
int V_354 ;
struct V_174 * V_355 ;
T_3 V_356 [ V_77 ] ;
T_3 V_357 [ V_77 ] ;
static const T_3 V_358 [ 3 ] = { 0 , 0 , 0xf8 } ;
static const T_3 V_359 [ 3 ] = { 0 , 0 , 0 } ;
memcpy ( V_357 , F_113 ( V_352 ) , V_77 ) ;
memcpy ( V_356 , F_114 ( V_352 ) , V_77 ) ;
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
if ( V_350 -> V_360 != 0xaa || V_350 -> V_361 != 0xaa || V_350 -> V_362 != 3 ) {
F_55 ( L_126 ,
V_350 -> V_360 , V_350 -> V_361 , V_350 -> V_362 ) ;
V_354 = V_338 - V_181 ;
V_355 = (struct V_174 * ) ( V_133 -> V_92 + V_354 ) ;
V_355 -> V_175 = F_60 ( V_135 - V_338 ) ;
} else {
if ( memcmp ( V_350 -> V_180 , V_358 , 3 ) == 0 ) {
F_55 ( L_127 ) ;
V_354 = V_338
+ sizeof( struct V_179 ) - V_181 ;
V_355 = (struct V_174 * ) ( V_133 -> V_92 + V_354 ) ;
V_355 -> V_175 = type ;
} else if ( memcmp ( V_350 -> V_180 , V_359 , 3 ) == 0 ) {
switch ( F_59 ( type ) ) {
case V_178 :
case V_177 :
F_55 ( L_128 ) ;
V_354 = V_338 - V_181 ;
V_355 = (struct V_174 * ) ( V_133 -> V_92 + V_354 ) ;
V_355 -> V_175 =
F_60 ( V_135 - V_338 ) ;
break;
default:
F_55 ( L_129 ) ;
V_354 = V_338 +
sizeof( struct V_179 ) - V_181 ;
V_355 = (struct V_174 * ) ( V_133 -> V_92 + V_354 ) ;
V_355 -> V_175 = type ;
break;
}
} else {
F_14 ( L_130 ) ;
V_354 = V_338 - V_181 ;
V_355 = (struct V_174 * ) ( V_133 -> V_92 + V_354 ) ;
V_355 -> V_175 = type ;
}
}
F_108 ( V_133 , V_354 ) ;
F_55 ( L_131 , V_354 ,
V_133 -> V_92 ) ;
memcpy ( V_355 -> V_187 , V_357 , V_77 ) ;
memcpy ( V_355 -> V_192 , V_356 , V_77 ) ;
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
static int F_101 ( T_1 * V_3 , T_3 * V_363 , int V_318 ,
int V_134 )
{
int V_364 = ( V_318 + V_134 ) - ( V_322 + 1 ) ;
if ( V_364 <= 0 ) {
F_27 ( V_363 , V_3 -> V_45 + V_318 , V_134 ) ;
} else {
F_27 ( V_363 , V_3 -> V_45 + V_318 ,
V_134 - V_364 ) ;
F_27 ( V_363 + V_134 - V_364 , V_3 -> V_45 ,
V_364 ) ;
}
return V_134 ;
}
static void F_102 ( T_1 * V_3 , struct V_53 T_2 * V_288 )
{
struct V_53 T_2 * V_333 = V_288 ;
int V_210 = 17 ;
unsigned V_289 = F_37 ( & V_288 -> V_120 . V_320 . V_341 ) ;
while ( V_210 -- ) {
F_28 ( V_70 , & V_333 -> V_71 ) ;
if ( V_289 >= ( V_69 + V_294 ) ) {
F_55 ( L_86 ,
V_289 ) ;
break;
}
V_333 = F_25 ( V_3 ) + V_289 ;
V_289 = F_37 ( & V_333 -> V_120 . V_320 . V_341 ) ;
}
F_28 ( V_70 , & V_333 -> V_71 ) ;
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
V_3 -> V_18 = V_365 ;
}
static void F_99 ( T_1 * V_3 , struct V_53 T_2 * V_288 ,
unsigned int V_318 , int V_317 )
{
T_3 V_366 [ 256 ] ;
struct V_367 * V_368 = (struct V_367 * ) V_366 ;
F_11 ( & V_3 -> V_28 ) ;
F_101 ( V_3 , V_366 , V_318 , V_317 & 0xff ) ;
if ( V_3 -> V_73 . V_74 . V_112 == V_118 ) {
F_55 ( L_134 ,
V_368 -> V_120 [ 0 ] , V_368 -> V_120 [ 1 ] , V_368 -> V_120 [ 2 ] , V_368 -> V_120 [ 3 ] ,
V_368 -> V_120 [ 4 ] , V_368 -> V_120 [ 5 ] ) ;
if ( V_368 -> V_120 [ 2 ] == 1 ) {
F_55 ( L_135 ) ;
if ( ! F_52
( V_3 , V_368 -> V_183 . V_191 , V_369 ) ) {
V_3 -> V_18 = V_137 ;
memcpy ( V_3 -> V_138 , V_368 -> V_183 . V_191 ,
V_77 ) ;
}
}
} else {
if ( V_3 -> V_18 == V_365 ) {
if ( V_368 -> V_120 [ 2 ] == 2 ) {
if ( ( V_368 -> V_120 [ 3 ] | V_368 -> V_120 [ 4 ] ) == 0 ) {
F_55 ( L_136 ) ;
V_3 -> V_16 = V_370 ;
F_115 ( V_3 ) ;
V_3 -> V_18 =
V_140 ;
} else {
F_55 ( L_137 ) ;
V_3 -> V_16 = V_371 ;
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
F_28 ( V_304 , & V_55 -> V_86 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_2 ( & V_31 -> V_5 , L_74 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
F_11 ( & V_3 -> V_28 ) ;
V_3 -> V_28 . V_89 = V_90 + V_91 * 2 ;
V_3 -> V_28 . V_92 = ( long ) V_3 ;
V_3 -> V_28 . V_93 = F_39 ;
F_36 ( & V_3 -> V_28 ) ;
V_3 -> V_16 = V_306 ;
return;
}
if ( ! V_249 )
F_82 ( V_5 ) ;
}
static void F_100 ( T_1 * V_3 , struct V_53 T_2 * V_288 ,
unsigned int V_318 , int V_317 )
{
F_55 ( L_141 ) ;
V_3 -> V_18 = V_19 ;
}
static void F_31 ( T_1 * V_3 )
{
F_28 ( 0 , V_3 -> V_47 + V_250 + V_372 ) ;
}
static int F_116 ( struct V_373 * V_203 , void * V_374 )
{
int V_33 ;
struct V_1 * V_31 ;
struct V_4 * V_5 ;
T_1 * V_3 ;
T_3 * V_54 ;
struct V_375 * V_376 ;
T_3 V_377 [ 33 ] ;
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
F_118 ( V_203 , L_143 , V_378 ) ;
F_117 ( V_203 , L_144 ) ;
if ( V_3 -> V_64 == 0x55 )
F_117 ( V_203 , L_145 ) ;
else
F_118 ( V_203 , L_146 ,
V_3 -> V_64 , V_3 -> V_66 , V_3 -> V_67 ) ;
for ( V_33 = 0 ; V_33 < 32 ; V_33 ++ )
V_377 [ V_33 ] = V_3 -> V_73 . V_82 . V_115 [ V_33 ] ;
V_377 [ 32 ] = 0 ;
F_118 ( V_203 , L_147 ,
V_379 [ V_3 -> V_73 . V_82 . V_112 ] , V_377 ) ;
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
F_118 ( V_203 , L_151 , V_380 [ V_163 ] ) ;
F_118 ( V_203 , L_152 , V_3 -> V_324 ) ;
if ( V_3 -> V_332 ) {
F_118 ( V_203 , L_153 ,
V_3 -> V_330 . V_381 [ 0 ]
+ 256 * V_3 -> V_330 . V_381 [ 1 ] ) ;
V_54 = V_3 -> V_330 . V_382 ;
if ( V_54 [ 0 ] == V_383 )
V_54 += V_54 [ 1 ] + 2 ;
else {
F_118 ( V_203 ,
L_154 ,
V_54 [ 0 ] ) ;
return 0 ;
}
if ( V_54 [ 0 ] == V_384 ) {
F_117 ( V_203 , L_155 ) ;
for ( V_33 = 2 ; V_33 < V_54 [ 1 ] + 2 ; V_33 ++ )
F_118 ( V_203 , L_156 , V_54 [ V_33 ] ) ;
F_119 ( V_203 , '\n' ) ;
V_54 += V_54 [ 1 ] + 2 ;
} else {
F_117 ( V_203 , L_157 ) ;
return 0 ;
}
if ( V_54 [ 0 ] == V_385 ) {
V_376 = (struct V_375 * ) V_54 ;
F_118 ( V_203 , L_158 ,
V_376 -> V_386 [ 0 ] +
256 * V_376 -> V_386 [ 1 ] ) ;
F_118 ( V_203 , L_159 ,
V_376 -> V_387 ) ;
F_118 ( V_203 , L_160 ,
V_376 -> V_388 ) ;
F_118 ( V_203 , L_161 ,
V_376 -> V_389 ) ;
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
static int F_120 ( struct V_390 * V_390 , struct V_391 * V_391 )
{
return F_121 ( V_391 , F_116 , NULL ) ;
}
static int F_52 ( T_1 * V_3 , T_3 * V_363 , int V_392 )
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
F_28 ( V_393 , V_55 -> V_120 . V_165 . V_167 ) ;
F_28 ( V_394 ,
V_55 -> V_120 . V_165 . V_167 + 1 ) ;
F_28 ( 0 , & V_55 -> V_120 . V_165 . V_169 ) ;
V_152 = V_3 -> V_44 + V_153 ;
F_28 ( V_182 | V_326 , & V_152 -> V_183 . V_184 ) ;
F_28 ( 0 , & V_152 -> V_183 . V_185 ) ;
F_33 ( V_152 -> V_183 . V_186 , V_363 , V_77 ) ;
F_33 ( V_152 -> V_183 . V_191 , V_3 -> V_73 . V_74 . V_75 , V_77 ) ;
F_33 ( V_152 -> V_183 . V_188 , V_3 -> V_189 , V_77 ) ;
F_122 ( V_152 -> V_120 , 0 , 6 ) ;
F_28 ( V_392 & 0xff , V_152 -> V_120 + 2 ) ;
if ( F_35 ( V_3 , V_79 ) ) {
F_55 (
L_165 ) ;
F_28 ( V_70 , & ( V_55 ++ ) -> V_71 ) ;
return - 1 ;
}
return 0 ;
}
static T_10 F_123 ( struct V_391 * V_391 ,
const char T_11 * V_395 , T_12 V_396 , T_13 * V_397 )
{
static char V_398 [ 33 ] ;
unsigned int V_135 = V_396 ;
if ( V_135 > 32 )
V_135 = 32 ;
memset ( V_398 , 0 , 33 ) ;
if ( F_124 ( V_398 , V_395 , V_135 ) )
return - V_399 ;
V_114 = V_398 ;
return V_396 ;
}
static T_10 F_125 ( struct V_391 * V_391 , const char T_11 * V_395 ,
T_12 V_396 , T_13 * V_397 )
{
static char V_400 [ 10 ] ;
char * V_54 ;
int V_401 , V_135 ;
if ( ! V_396 )
return 0 ;
if ( V_396 > 9 )
return - V_217 ;
if ( F_124 ( V_400 , V_395 , V_396 ) )
return - V_399 ;
V_54 = V_400 ;
V_401 = 0 ;
V_135 = V_396 ;
do {
unsigned int V_377 = * V_54 - '0' ;
if ( V_377 > 9 )
return - V_217 ;
V_401 = V_401 * 10 + V_377 ;
V_54 ++ ;
} while ( -- V_135 );
* ( int * ) F_126 ( F_127 ( V_391 ) ) -> V_92 = V_401 ;
return V_396 ;
}
static int T_14 F_128 ( void )
{
int V_402 ;
F_55 ( L_143 , V_378 ) ;
V_402 = F_129 ( & V_403 ) ;
F_55 ( L_166 ,
V_402 ) ;
#ifdef F_130
F_131 ( L_167 , NULL ) ;
F_132 ( L_168 , 0 , NULL , & V_404 ) ;
F_132 ( L_169 , V_405 , NULL , & V_406 ) ;
F_133 ( L_170 , V_405 , NULL , & V_407 , & V_56 ) ;
F_133 ( L_171 , V_405 , NULL , & V_407 , & V_163 ) ;
#endif
if ( V_163 != 0 )
V_163 = 1 ;
return 0 ;
}
static void T_15 F_134 ( void )
{
F_55 ( L_172 ) ;
#ifdef F_130
F_135 ( L_168 , NULL ) ;
F_135 ( L_169 , NULL ) ;
F_135 ( L_170 , NULL ) ;
F_135 ( L_171 , NULL ) ;
F_135 ( L_167 , NULL ) ;
#endif
F_136 ( & V_403 ) ;
}
