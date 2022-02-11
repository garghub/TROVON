static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 0x200 ; V_5 += 4 )
F_3 ( 0 , V_4 -> V_6 + V_5 ) ;
F_3 ( V_4 -> V_7 . V_8 . V_9 , V_4 -> V_6 + V_10 ) ;
F_3 ( V_4 -> V_7 . V_8 . V_9 , V_4 -> V_6 + V_11 ) ;
F_3 ( 0x1c , V_4 -> V_6 + V_12 ) ;
F_3 ( 1 , V_4 -> V_6 + V_13 ) ;
F_3 ( V_2 -> V_14 . V_15 , V_4 -> V_6 + V_16 ) ;
F_3 ( V_2 -> V_14 . V_17 , V_4 -> V_6 + V_18 ) ;
F_3 ( 0xf , V_4 -> V_6 + V_19 ) ;
F_3 ( 4 , V_4 -> V_6 + V_20 ) ;
F_3 ( 1 , V_4 -> V_6 + V_21 ) ;
F_3 ( 1 , V_4 -> V_6 + V_22 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_23 = V_2 -> V_14 . V_24 ;
int V_25 = V_23 + V_2 -> V_14 . V_15 ;
int V_26 = V_25 + V_2 -> V_14 . V_27 ;
int V_28 = V_2 -> V_14 . V_29 ;
int V_30 = V_2 -> V_14 . V_31 ;
int V_32 = V_30 + V_2 -> V_14 . V_33 ;
int V_34 = V_32 + V_2 -> V_14 . V_35 ;
int V_36 = V_2 -> V_14 . V_37 ;
F_3 ( 0 , V_4 -> V_6 + V_38 ) ;
F_3 ( V_23 , V_4 -> V_6 + V_39 ) ;
F_3 ( V_25 , V_4 -> V_6 + V_40 ) ;
F_3 ( V_26 , V_4 -> V_6 + V_41 ) ;
F_3 ( V_28 , V_4 -> V_6 + V_42 ) ;
F_3 ( V_30 , V_4 -> V_6 + V_43 ) ;
F_3 ( V_32 , V_4 -> V_6 + V_44 ) ;
F_3 ( V_34 , V_4 -> V_6 + V_45 ) ;
F_3 ( V_36 , V_4 -> V_6 + V_46 ) ;
F_3 ( 1 , V_4 -> V_6 + V_38 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 )
return - V_47 ;
if ( V_2 -> V_14 . V_48 == 32 ) {
V_2 -> V_14 . V_49 . V_50 = 16 ;
V_2 -> V_14 . V_49 . V_51 = 8 ;
V_2 -> V_14 . V_49 . V_52 = 0 ;
V_2 -> V_14 . V_53 . V_50 = 8 ;
V_2 -> V_14 . V_53 . V_51 = 8 ;
V_2 -> V_14 . V_53 . V_52 = 0 ;
V_2 -> V_14 . V_54 . V_50 = 0 ;
V_2 -> V_14 . V_54 . V_51 = 8 ;
V_2 -> V_14 . V_54 . V_52 = 0 ;
V_2 -> V_8 . V_55 = V_56 ;
V_2 -> V_8 . V_57 = V_2 -> V_14 . V_17 << 2 ;
}
F_4 ( V_2 ) ;
F_3 ( V_4 -> V_58 << 16 | V_4 -> V_58 << 8 | V_4 -> V_58 ,
V_4 -> V_6 + V_59 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_60 * V_61 ,
struct V_62 * V_63 , char * V_64 )
{
struct V_1 * V_2 = F_7 ( V_61 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
return sprintf ( V_64 , L_1 , V_4 -> V_58 ) ;
}
static T_1 F_8 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
const char * V_64 , T_2 V_65 )
{
struct V_1 * V_2 = F_7 ( V_61 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_66 ;
if ( F_9 ( V_64 , 10 , & V_66 ) || ( V_66 > 0xff ) )
return - V_47 ;
V_4 -> V_58 = V_66 ;
F_5 ( V_2 ) ;
return V_65 ;
}
static inline T_3 F_10 ( T_3 V_67 , struct V_68 * V_69 )
{
V_67 &= 0xffff ;
V_67 >>= 16 - V_69 -> V_51 ;
return V_67 << V_69 -> V_50 ;
}
static int F_11 ( unsigned V_70 , unsigned V_49 , unsigned V_53 ,
unsigned V_54 , unsigned V_71 ,
struct V_1 * V_2 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_72 = 1 ;
unsigned int V_73 ;
if ( V_70 >= 256 )
return - V_47 ;
if ( V_2 -> V_14 . V_74 )
V_49 = V_53 = V_54 =
( 19595 * V_49 + 38470 * V_53 + 7471 * V_54 ) >> 16 ;
switch ( V_4 -> V_7 . V_8 . V_55 ) {
case V_56 :
if ( V_70 < 16 ) {
T_4 * V_75 = V_2 -> V_76 ;
V_73 = F_10 ( V_49 , & V_4 -> V_7 . V_14 . V_49 ) ;
V_73 |= F_10 ( V_53 , & V_4 -> V_7 . V_14 . V_53 ) ;
V_73 |= F_10 ( V_54 , & V_4 -> V_7 . V_14 . V_54 ) ;
V_75 [ V_70 ] = V_73 ;
V_72 = 0 ;
}
break;
}
return V_72 ;
}
static int F_12 ( struct V_77 * V_14 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_14 -> V_78 , V_4 -> V_6 + V_79 ) ;
F_3 ( V_14 -> V_80 , V_4 -> V_6 + V_81 ) ;
return 0 ;
}
static int F_13 ( int V_82 , struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_82 ) {
case V_83 :
F_4 ( V_2 ) ;
break;
default:
F_3 ( 0 , V_4 -> V_6 + V_46 ) ;
break;
}
return 0 ;
}
static int T_5 F_14 ( struct V_84 * V_85 )
{
struct V_3 * V_4 ;
struct V_86 * V_87 ;
void * V_88 ;
struct V_89 * V_90 ;
int V_72 ;
V_90 = V_85 -> V_61 . V_91 ;
V_72 = - V_92 ;
V_4 = NULL ;
V_4 = F_15 ( sizeof( struct V_3 ) + sizeof( T_4 ) * 16 ,
V_93 ) ;
if ( ! V_4 ) {
F_16 ( & V_85 -> V_61 , L_2 ) ;
V_72 = - V_92 ;
goto V_94;
}
strcpy ( V_4 -> V_7 . V_8 . V_95 , V_96 ) ;
V_4 -> V_7 . V_8 . type = V_97 ;
V_4 -> V_7 . V_8 . V_98 = 1 ;
V_4 -> V_7 . V_8 . V_99 = 1 ;
V_4 -> V_7 . V_8 . V_100 = 0 ;
V_4 -> V_7 . V_8 . V_101 = V_102 ;
V_4 -> V_7 . V_103 = & V_104 ;
V_4 -> V_7 . V_105 = V_106
| V_107
| V_108
| V_109
| V_110
| V_111
| V_112 ;
V_4 -> V_7 . V_113 = - 1 ;
V_88 = V_4 ;
V_88 = V_88 + sizeof( struct V_3 ) ;
V_4 -> V_7 . V_76 = V_88 ;
V_87 = F_17 ( V_85 , V_114 , 0 ) ;
if ( V_87 == NULL ) {
F_16 ( & V_85 -> V_61 , L_3 ) ;
V_72 = - V_115 ;
goto V_116;
}
V_87 = F_18 ( V_87 -> V_117 , F_19 ( V_87 ) , V_96 ) ;
if ( V_87 == NULL ) {
F_16 ( & V_85 -> V_61 , L_4 ) ;
V_72 = - V_118 ;
goto V_116;
}
V_4 -> V_6 = F_20 ( V_87 -> V_117 , F_19 ( V_87 ) ) ;
if ( V_4 -> V_6 == NULL ) {
F_16 ( & V_85 -> V_61 , L_5 ) ;
V_72 = - V_118 ;
goto V_119;
}
F_21 ( & V_4 -> V_7 . V_14 , & V_90 -> V_120 ) ;
V_4 -> V_7 . V_14 . V_121 = 0 ;
V_4 -> V_7 . V_14 . V_122 = V_123 ;
V_4 -> V_7 . V_14 . V_124 = - 1 ;
V_4 -> V_7 . V_14 . V_125 = - 1 ;
V_4 -> V_7 . V_14 . V_17 = V_90 -> V_17 ;
V_4 -> V_7 . V_14 . V_126 = V_90 -> V_126 ;
V_4 -> V_7 . V_14 . V_48 = V_90 -> V_127 ;
V_4 -> V_7 . V_8 . V_9 = V_90 -> V_128 ;
V_4 -> V_7 . V_8 . V_129 = V_90 -> V_130 ;
V_4 -> V_7 . V_131 = V_90 -> V_132 ;
V_4 -> V_7 . V_133 = V_90 -> V_130 ;
if ( F_22 ( & V_4 -> V_7 . V_134 , 256 , 0 ) < 0 ) {
F_16 ( & V_85 -> V_61 , L_6 ) ;
V_72 = - V_92 ;
goto V_135;
}
F_1 ( & V_4 -> V_7 ) ;
V_4 -> V_58 = 0x80 ;
V_72 = F_5 ( & V_4 -> V_7 ) ;
if ( V_72 ) {
F_16 ( & V_85 -> V_61 , L_7 ) ;
goto V_136;
}
F_23 ( V_85 , V_4 ) ;
V_72 = F_24 ( & V_4 -> V_7 ) ;
if ( V_72 < 0 ) {
F_16 ( & V_85 -> V_61 ,
L_8 , V_72 ) ;
goto V_136;
}
V_72 = F_25 ( & V_85 -> V_61 , & V_137 ) ;
if ( V_72 < 0 ) {
F_26 ( V_138 L_9 ,
V_4 -> V_7 . V_113 , V_72 ) ;
}
F_26 ( V_139 L_10 ,
V_4 -> V_7 . V_113 , V_4 -> V_7 . V_8 . V_95 , V_4 -> V_7 . V_8 . V_9 ,
V_4 -> V_7 . V_8 . V_9 + V_4 -> V_7 . V_8 . V_129 - 1 ) ;
return 0 ;
V_136:
if ( V_4 -> V_7 . V_134 . V_140 )
F_27 ( & V_4 -> V_7 . V_134 ) ;
V_135:
F_28 ( V_4 -> V_6 ) ;
V_119:
F_29 ( V_87 -> V_117 , F_19 ( V_87 ) ) ;
V_116:
F_23 ( V_85 , NULL ) ;
F_30 ( V_4 ) ;
V_94:
return V_72 ;
}
static int T_6 F_31 ( struct V_84 * V_85 )
{
struct V_3 * V_4 = F_32 ( V_85 ) ;
struct V_86 * V_87 ;
F_33 ( & V_85 -> V_61 , & V_137 ) ;
F_34 ( & V_4 -> V_7 ) ;
F_3 ( 0 , V_4 -> V_6 ) ;
if ( V_4 -> V_7 . V_134 . V_140 )
F_27 ( & V_4 -> V_7 . V_134 ) ;
F_28 ( V_4 -> V_6 ) ;
V_87 = F_17 ( V_85 , V_114 , 0 ) ;
F_29 ( V_87 -> V_117 , F_19 ( V_87 ) ) ;
F_30 ( V_4 ) ;
return 0 ;
}
