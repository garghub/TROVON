static inline void F_1 ( struct V_1 * V_1 , int V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) & V_1 -> V_6 ;
F_2 ( V_7 , L_1 , V_2 ) ;
V_5 -> V_8 ( V_5 , V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_1 , unsigned int V_9 )
{
F_2 ( V_10 , L_2 , V_9 ) ;
switch ( V_1 -> type ) {
case V_11 :
V_1 -> V_12 ( V_1 , V_13 , ( V_9 << 2 ) | 3 ) ;
break;
case V_14 :
V_1 -> V_12 ( V_1 , V_15 , ( V_9 << 4 ) | ( 7 << 1 ) ) ;
break;
}
}
static void F_4 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_5 ( V_17 , V_20 ) ;
F_3 ( V_1 , V_21 ) ;
}
static void F_6 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_5 ( V_17 , V_20 ) ;
F_1 ( V_1 , V_22 | V_23 , NULL ) ;
F_3 ( V_1 , V_21 ) ;
}
static void F_7 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
F_5 ( V_17 , V_24 ) ;
}
static void F_8 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_5 ( V_17 , V_25 ) ;
F_1 ( V_1 , V_22 | V_23 , NULL ) ;
F_3 ( V_1 , V_21 ) ;
}
static void F_9 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_5 ( V_17 , V_25 ) ;
F_3 ( V_1 , V_21 ) ;
}
static void F_10 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
F_5 ( V_17 , V_26 ) ;
}
static void F_11 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
F_5 ( V_17 , V_27 ) ;
}
static void F_12 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
F_5 ( V_17 , V_28 ) ;
}
static void F_13 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_5 ( V_17 , V_28 ) ;
F_1 ( V_1 , V_22 | V_23 , NULL ) ;
}
static void F_14 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_15 ( & V_1 -> V_29 , 0 ) ;
F_5 ( V_17 , V_30 ) ;
F_3 ( V_1 , V_31 ) ;
F_1 ( V_1 , V_32 | V_23 , NULL ) ;
}
static void F_16 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
F_5 ( V_17 , V_33 ) ;
}
static void F_17 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_5 ( V_17 , V_33 ) ;
F_1 ( V_1 , V_22 | V_23 , NULL ) ;
}
static void F_18 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_19 ( & V_1 -> V_29 , V_34 , V_35 , NULL , 2 ) ;
F_3 ( V_1 , V_31 ) ;
}
static void F_20 ( struct V_16 * V_17 , int V_18 , void * V_3 )
{
struct V_1 * V_1 = V_17 -> V_19 ;
F_3 ( V_1 , V_21 ) ;
F_1 ( V_1 , V_22 | V_23 , NULL ) ;
}
static void F_21 ( struct V_16 * V_17 , char * V_36 , ... )
{
T_1 args ;
char V_37 [ 256 ] ;
va_start ( args , V_36 ) ;
vsnprintf ( V_37 , sizeof( V_37 ) , V_36 , args ) ;
F_2 ( V_10 , L_3 , V_37 ) ;
va_end ( args ) ;
}
static void F_22 ( struct V_1 * V_38 )
{
int V_39 ;
V_39 = V_38 -> V_40 ( V_38 , V_41 ) ;
F_2 ( 1 , L_4 , V_39 , V_42 [ ( V_39 >> 5 ) & 3 ] ) ;
}
static void F_23 ( struct V_1 * V_1 , int V_43 )
{
T_2 * V_44 ;
F_2 ( V_45 , L_5 , V_43 ) ;
if ( ( V_1 -> V_46 + V_43 ) >= V_47 ) {
F_2 ( V_48 , L_6 , V_1 -> V_46 + V_43 ) ;
V_1 -> V_12 ( V_1 , V_49 , V_50 ) ;
V_1 -> V_46 = 0 ;
return;
}
V_44 = V_1 -> V_51 + V_1 -> V_46 ;
V_1 -> V_46 += V_43 ;
V_1 -> V_52 ( V_1 , V_44 , V_43 ) ;
V_1 -> V_12 ( V_1 , V_49 , V_50 ) ;
F_24 ( V_53 , V_44 , V_43 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
int V_43 ;
unsigned char V_54 ;
T_2 * V_44 ;
F_26 ( ! V_1 -> V_55 ) ;
V_43 = V_1 -> V_55 -> V_56 ;
F_26 ( V_43 <= 0 ) ;
F_2 ( V_45 , L_5 , V_43 ) ;
if ( V_43 > 0x20 ) {
V_43 = 0x20 ;
V_54 = V_57 ;
} else {
V_54 = V_57 | V_58 ;
}
V_44 = V_1 -> V_55 -> V_59 ;
F_27 ( V_1 -> V_55 , V_43 ) ;
V_1 -> V_60 += V_43 ;
F_24 ( V_61 , V_44 , V_43 ) ;
V_1 -> V_62 ( V_1 , V_44 , V_43 ) ;
V_1 -> V_12 ( V_1 , V_49 , V_54 ) ;
}
static void F_28 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_55 ) {
F_2 ( V_48 , L_7 ) ;
return;
}
F_29 ( V_1 -> V_55 , V_1 -> V_60 ) ;
V_1 -> V_60 = 0 ;
}
static inline void F_30 ( struct V_1 * V_1 )
{
unsigned char V_39 ;
V_39 = V_1 -> V_40 ( V_1 , V_63 ) ;
F_2 ( V_45 , L_8 , V_39 ) ;
if ( V_39 & V_64 ) {
F_2 ( V_45 , L_9 , ( V_39 >> 2 ) & 0xf ) ;
F_31 ( & V_1 -> V_65 , ( V_39 >> 2 ) & 0xf , NULL ) ;
}
if ( V_39 & V_66 ) {
V_39 = V_1 -> V_40 ( V_1 , V_67 ) ;
F_2 ( V_48 , L_10 , V_39 ) ;
}
}
static inline void F_32 ( struct V_1 * V_1 )
{
unsigned char V_39 ;
int V_43 ;
struct V_68 * V_69 ;
V_39 = V_1 -> V_40 ( V_1 , V_70 ) ;
if ( ( V_39 & ( V_71 | V_72 | V_73 ) )
!= V_72 ) {
F_2 ( V_48 , L_11 , V_39 ) ;
V_1 -> V_12 ( V_1 , V_49 , V_50 ) ;
goto V_74;
}
V_43 = V_1 -> V_40 ( V_1 , V_75 ) & 0x1f ;
F_2 ( V_45 , L_12 , V_43 ) ;
if ( V_43 == 0 )
V_43 = 0x20 ;
F_23 ( V_1 , V_43 ) ;
V_43 = V_1 -> V_46 ;
if ( V_43 < 1 ) {
F_2 ( V_48 , L_13 , V_43 ) ;
goto V_74;
}
V_69 = F_33 ( V_43 , V_76 ) ;
if ( ! V_69 ) {
F_2 ( V_48 , L_14 ) ;
goto V_74;
}
F_34 ( V_69 , V_1 -> V_51 , V_43 ) ;
F_35 ( V_77 , V_69 ) ;
F_1 ( V_1 , V_78 | V_23 , V_69 ) ;
V_74:
V_1 -> V_46 = 0 ;
}
static inline void F_36 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_55 )
return;
if ( V_1 -> V_55 -> V_56 > 0 ) {
F_25 ( V_1 ) ;
return;
}
F_37 ( V_1 -> V_55 ) ;
V_1 -> V_60 = 0 ;
V_1 -> V_55 = NULL ;
F_1 ( V_1 , V_78 | V_79 , NULL ) ;
}
static inline void F_38 ( struct V_1 * V_1 )
{
unsigned char V_39 ;
V_39 = V_1 -> V_40 ( V_1 , V_80 ) ;
F_2 ( 2 , L_15 , V_39 ) ;
if ( V_39 & V_81 ) {
F_2 ( V_48 , L_16 ) ;
F_28 ( V_1 ) ;
}
if ( V_39 & V_82 ) {
F_2 ( V_48 , L_17 ) ;
F_28 ( V_1 ) ;
}
if ( V_39 & V_83 ) {
F_2 ( V_48 , L_18 ) ;
V_39 = V_1 -> V_40 ( V_1 , V_84 ) ;
F_2 ( 2 , L_19 , V_39 ) ;
}
}
void F_39 ( struct V_1 * V_1 )
{
unsigned char V_39 ;
V_39 = V_1 -> V_40 ( V_1 , V_85 ) ;
F_2 ( V_45 , L_20 , V_39 ) ;
if ( V_39 & V_86 ) {
F_2 ( V_45 , L_21 ) ;
F_38 ( V_1 ) ;
}
if ( V_39 & V_87 ) {
F_2 ( V_45 , L_22 ) ;
F_36 ( V_1 ) ;
}
if ( V_39 & V_88 ) {
F_2 ( V_45 , L_23 ) ;
F_32 ( V_1 ) ;
}
if ( V_39 & V_89 ) {
F_2 ( V_45 , L_24 ) ;
F_23 ( V_1 , 0x20 ) ;
}
if ( V_39 & V_90 ) {
F_2 ( V_45 , L_25 ) ;
F_30 ( V_1 ) ;
}
if ( V_39 & V_91 ) {
F_2 ( V_48 , L_26 ) ;
}
if ( V_39 & V_92 ) {
F_2 ( V_48 , L_27 ) ;
}
V_1 -> V_12 ( V_1 , V_93 , 0xff ) ;
V_1 -> V_12 ( V_1 , V_93 , 0x00 ) ;
}
static inline void F_40 ( struct V_1 * V_1 )
{
unsigned char V_39 ;
V_39 = V_1 -> V_40 ( V_1 , V_94 ) ;
F_2 ( V_45 , L_8 , V_39 ) ;
if ( V_39 & V_95 ) {
F_2 ( V_45 , L_9 , V_39 >> 4 ) ;
F_31 ( & V_1 -> V_65 , V_39 >> 4 , NULL ) ;
}
}
static inline void F_41 ( struct V_1 * V_1 )
{
int V_43 ;
struct V_68 * V_69 ;
unsigned char V_39 ;
V_39 = V_1 -> V_40 ( V_1 , V_96 ) ;
if ( ( V_39 & ( V_97 |
V_98 |
V_99 |
V_100 ) )
!= ( V_97 | V_99 ) ) {
F_2 ( V_48 , L_28 , V_39 ) ;
V_1 -> V_12 ( V_1 , V_101 , V_102 ) ;
goto V_74;
}
V_43 = V_1 -> V_40 ( V_1 , V_103 ) & 0x1f ;
F_2 ( V_45 , L_29 , V_43 ) ;
if ( V_43 == 0 )
V_43 = 0x20 ;
F_23 ( V_1 , V_43 ) ;
V_43 = V_1 -> V_46 - 1 ;
if ( V_43 < 1 ) {
F_2 ( V_48 , L_13 , V_43 ) ;
goto V_74;
}
V_69 = F_42 ( V_43 ) ;
if ( ! V_69 ) {
F_2 ( V_48 , L_30 ) ;
goto V_74;
}
F_34 ( V_69 , V_1 -> V_51 , V_43 ) ;
F_35 ( V_77 , V_69 ) ;
F_1 ( V_1 , V_78 | V_23 , V_69 ) ;
V_74:
V_1 -> V_46 = 0 ;
}
static inline void F_43 ( struct V_1 * V_1 )
{
if ( ! V_1 -> V_55 )
return;
if ( V_1 -> V_55 -> V_56 > 0 ) {
F_25 ( V_1 ) ;
return;
}
F_37 ( V_1 -> V_55 ) ;
V_1 -> V_55 = NULL ;
V_1 -> V_60 = 0 ;
F_1 ( V_1 , V_78 | V_79 , NULL ) ;
}
static inline void F_44 ( struct V_1 * V_1 )
{
unsigned char V_39 ;
V_39 = V_1 -> V_40 ( V_1 , V_104 ) ;
F_2 ( V_45 , L_31 , V_39 ) ;
if ( V_39 & V_105 ) {
F_2 ( V_48 , L_32 ) ;
F_28 ( V_1 ) ;
}
if ( V_39 & V_106 ) {
F_2 ( V_48 , L_33 ) ;
F_28 ( V_1 ) ;
}
if ( V_39 & V_107 ) {
F_2 ( V_45 , L_34 ) ;
F_43 ( V_1 ) ;
}
if ( V_39 & V_108 ) {
F_2 ( V_48 , L_35 ) ;
V_1 -> V_12 ( V_1 , V_101 , V_102 ) ;
}
if ( V_39 & V_109 ) {
F_2 ( V_45 , L_36 ) ;
F_41 ( V_1 ) ;
}
if ( V_39 & V_110 ) {
F_2 ( V_45 , L_37 ) ;
F_23 ( V_1 , 0x20 ) ;
}
}
void F_45 ( struct V_1 * V_1 )
{
unsigned char V_39 ;
V_39 = V_1 -> V_40 ( V_1 , V_111 ) ;
F_2 ( V_45 , L_20 , V_39 ) ;
if ( V_39 & V_112 )
F_44 ( V_1 ) ;
if ( V_39 & V_113 )
F_40 ( V_1 ) ;
}
void F_46 ( struct V_1 * V_1 )
{
V_1 -> V_55 = NULL ;
V_1 -> V_65 . V_114 = & V_115 ;
V_1 -> V_65 . V_116 = V_20 ;
#ifdef F_47
V_1 -> V_65 . V_117 = 1 ;
#else
V_1 -> V_65 . V_117 = 0 ;
#endif
V_1 -> V_65 . V_19 = V_1 ;
V_1 -> V_65 . V_118 = F_21 ;
F_48 ( & V_1 -> V_65 , & V_1 -> V_29 ) ;
}
void F_49 ( struct V_1 * V_1 )
{
int V_39 , V_119 ;
V_1 -> type = V_11 ;
F_22 ( V_1 ) ;
F_3 ( V_1 , V_120 ) ;
V_1 -> V_12 ( V_1 , V_93 , 0xff ) ;
V_1 -> V_121 = 0xaa ;
if ( F_50 ( V_122 , & V_1 -> V_123 ) ) {
V_1 -> V_12 ( V_1 , V_124 , 0x0 ) ;
V_1 -> V_12 ( V_1 , V_125 , 0xa ) ;
V_1 -> V_12 ( V_1 , V_126 , 0x2 ) ;
V_1 -> V_12 ( V_1 , V_127 , 0x70 ) ;
V_1 -> V_12 ( V_1 , V_128 , 0xc9 ) ;
} else {
if ( ! V_1 -> V_129 )
V_1 -> V_129 = 0x80 ;
V_1 -> V_12 ( V_1 , V_124 , V_1 -> V_129 ) ;
V_1 -> V_12 ( V_1 , V_130 , 0x2f ) ;
V_1 -> V_12 ( V_1 , V_125 , 0x00 ) ;
V_1 -> V_12 ( V_1 , V_127 , 0x70 ) ;
V_1 -> V_12 ( V_1 , V_128 , 0xc9 ) ;
V_1 -> V_12 ( V_1 , V_131 , 0x00 ) ;
V_1 -> V_12 ( V_1 , V_126 , 0x00 ) ;
}
V_39 = V_1 -> V_40 ( V_1 , V_132 ) ;
F_2 ( 2 , L_38 , V_39 ) ;
V_39 = V_1 -> V_40 ( V_1 , V_128 ) ;
F_2 ( 2 , L_39 , V_39 ) ;
V_39 = V_1 -> V_40 ( V_1 , V_124 ) ;
F_2 ( 2 , L_40 , V_39 ) ;
V_39 = V_1 -> V_40 ( V_1 , V_85 ) ;
F_2 ( 2 , L_41 , V_39 ) ;
if ( V_39 & 0x01 ) {
V_119 = V_1 -> V_40 ( V_1 , V_80 ) ;
F_2 ( 2 , L_42 , V_119 ) ;
}
V_39 = V_1 -> V_40 ( V_1 , V_63 ) ;
F_2 ( 2 , L_43 , V_39 ) ;
F_31 ( & V_1 -> V_65 , ( V_39 >> 2 ) & 0xf , NULL ) ;
V_1 -> V_12 ( V_1 , V_93 , 0x0 ) ;
V_1 -> V_12 ( V_1 , V_49 , V_133 | V_134 ) ;
}
void F_51 ( struct V_1 * V_1 )
{
V_1 -> type = V_14 ;
V_1 -> V_12 ( V_1 , V_135 , 0x00 ) ;
V_1 -> V_12 ( V_1 , V_136 , 0x00 ) ;
V_1 -> V_12 ( V_1 , V_137 , 0xc9 ) ;
V_1 -> V_12 ( V_1 , V_138 , 0x03 ) ;
V_1 -> V_12 ( V_1 , V_139 ,
~ ( V_112 | V_113 ) ) ;
}
void F_52 ( struct V_4 * V_6 , int V_2 , void * V_3 )
{
struct V_1 * V_1 = V_6 -> V_140 ;
struct V_68 * V_69 = V_3 ;
F_2 ( V_7 , L_1 , V_2 ) ;
switch ( V_2 ) {
case V_32 | V_141 :
F_31 ( & V_1 -> V_65 , V_142 , NULL ) ;
break;
case V_22 | V_141 :
F_31 ( & V_1 -> V_65 , V_143 , NULL ) ;
break;
case V_78 | V_141 :
F_2 ( V_7 , L_44 , V_69 -> V_56 ) ;
F_35 ( V_144 , V_69 ) ;
if ( V_1 -> V_65 . V_116 != V_30 ) {
F_2 ( 1 , L_45 , V_1 -> V_65 . V_116 ) ;
F_53 ( V_69 ) ;
break;
}
F_26 ( V_1 -> V_55 ) ;
V_1 -> V_55 = V_69 ;
F_25 ( V_1 ) ;
break;
}
}
static int T_3 F_54 ( void )
{
F_55 ( V_145 L_46 ) ;
V_115 . V_146 = V_147 ;
V_115 . V_148 = V_149 ;
V_115 . V_150 = V_151 ;
V_115 . V_152 = V_153 ;
return F_56 ( & V_115 , V_154 , F_57 ( V_154 ) ) ;
}
static void T_4 F_58 ( void )
{
F_59 ( & V_115 ) ;
}
