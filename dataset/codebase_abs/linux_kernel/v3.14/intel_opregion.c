static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 T_2 * F_1 = V_7 -> V_10 . F_1 ;
T_1 V_11 , V_12 , V_13 ;
T_3 V_14 ;
T_1 V_15 ;
if ( ! F_1 )
return - V_16 ;
V_11 = ( V_3 & V_17 ) >>
V_18 ;
V_12 = ( V_3 & V_19 ) >>
V_20 ;
if ( V_11 == V_21 ) {
if ( ( V_7 -> V_10 . V_22 &
( 1 << V_12 ) ) == 0 )
return - V_23 ;
} else if ( V_11 == V_24 ) {
if ( ( V_7 -> V_10 . V_25 &
( 1 << V_12 ) ) == 0 )
return - V_23 ;
}
V_15 = F_2 ( & F_1 -> V_15 ) ;
if ( ! V_15 ) {
V_15 = 50 ;
} else if ( V_15 > V_26 ) {
F_3 ( L_1
L_2 , V_15 , V_26 ) ;
V_15 = V_26 ;
}
V_13 = F_2 ( & F_1 -> V_13 ) ;
if ( V_13 & V_27 ) {
F_4 ( L_3 ) ;
return - V_28 ;
}
V_13 = V_3 | V_27 ;
F_5 ( V_4 , & F_1 -> V_4 ) ;
F_5 ( V_13 , & F_1 -> V_13 ) ;
F_6 ( V_2 -> V_29 , V_30 , & V_14 ) ;
if ( ! ( V_14 & V_31 ) || ( V_14 & V_32 ) ) {
V_14 |= V_31 ;
V_14 &= ~ V_32 ;
F_7 ( V_2 -> V_29 , V_30 , V_14 ) ;
}
V_14 |= V_32 ;
F_7 ( V_2 -> V_29 , V_30 , V_14 ) ;
#define F_8 (((scic = ioread32(&swsci->scic)) & SWSCI_SCIC_INDICATOR) == 0)
if ( F_9 ( F_8 , V_15 ) ) {
F_4 ( L_4 ) ;
return - V_33 ;
}
V_13 = ( V_13 & V_34 ) >>
V_35 ;
if ( V_13 != V_36 ) {
F_4 ( L_5 , V_13 ) ;
return - V_37 ;
}
if ( V_5 )
* V_5 = F_2 ( & F_1 -> V_4 ) ;
return 0 ;
#undef F_8
}
int F_10 ( struct V_38 * V_38 ,
bool V_39 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_2 ;
T_1 V_4 = 0 ;
T_1 type = 0 ;
T_1 V_41 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
V_41 = F_12 ( V_38 ) ;
if ( V_41 == V_42 ) {
V_41 = 0 ;
} else {
V_4 |= 1 << V_41 ;
V_41 ++ ;
}
if ( ! V_39 )
V_4 |= 4 << 8 ;
switch ( V_38 -> type ) {
case V_43 :
type = V_44 ;
break;
case V_45 :
case V_46 :
case V_47 :
type = V_48 ;
break;
case V_49 :
type = V_50 ;
break;
default:
F_13 ( 1 , L_6 ,
V_38 -> type ) ;
return - V_23 ;
}
V_4 |= type << ( 16 + V_41 * 3 ) ;
return F_1 ( V_2 , V_51 , V_4 , NULL ) ;
}
int F_14 ( struct V_1 * V_2 , T_4 V_52 )
{
int V_53 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
for ( V_53 = 0 ; V_53 < F_15 ( V_54 ) ; V_53 ++ ) {
if ( V_52 == V_54 [ V_53 ] . V_55 )
return F_1 ( V_2 , V_56 ,
V_54 [ V_53 ] . V_4 , NULL ) ;
}
return - V_23 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 V_57 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_58 * V_58 ;
struct V_59 T_2 * V_60 = V_7 -> V_10 . V_60 ;
F_4 ( L_7 , V_57 ) ;
if ( ! ( V_57 & V_61 ) )
return V_62 ;
V_57 &= V_63 ;
if ( V_57 > 255 )
return V_62 ;
F_17 ( & V_2 -> V_64 . V_65 ) ;
F_18 ( L_8 , V_57 ) ;
F_19 (intel_connector, &dev->mode_config.connector_list, base.head)
F_20 ( V_58 , V_57 , 255 ) ;
F_5 ( F_21 ( V_57 * 100 , 255 ) | V_66 , & V_60 -> V_67 ) ;
F_22 ( & V_2 -> V_64 . V_65 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_68 )
{
F_4 ( L_9 ) ;
return V_69 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_70 )
{
F_4 ( L_10 ) ;
return V_71 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_72 )
{
F_4 ( L_11 ) ;
return V_73 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_74 )
{
F_4 ( L_12 ) ;
return V_75 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_1 V_76 )
{
if ( ! V_76 )
F_4 ( L_13 ) ;
if ( V_76 & V_77 )
F_4 ( L_14 ) ;
if ( V_76 & V_78 )
F_4 ( L_15 ) ;
if ( V_76 & V_79 )
F_4 ( L_16 ) ;
if ( V_76 & V_80 )
F_4 ( L_17 ) ;
if ( V_76 & V_81 )
F_4 ( L_18 ) ;
return V_82 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_76 )
{
if ( V_76 & V_83 )
F_4 ( L_19 ) ;
else
F_4 ( L_20 ) ;
return V_84 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_1 V_76 )
{
if ( V_76 & V_85 )
F_4 ( L_21 ) ;
else
F_4 ( L_22 ) ;
return V_86 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
F_4 ( L_23 ) ;
return V_87 ;
}
static void F_31 ( struct V_88 * V_89 )
{
struct V_90 * V_10 =
F_32 ( V_89 , struct V_90 , F_31 ) ;
struct V_6 * V_7 =
F_32 ( V_10 , struct V_6 , V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_59 T_2 * V_60 = V_7 -> V_10 . V_60 ;
T_1 V_91 = 0 ;
T_1 V_92 ;
if ( ! V_60 )
return;
V_92 = F_2 ( & V_60 -> V_93 ) ;
if ( ! ( V_92 & V_94 ) ) {
F_4 ( L_24 ,
V_92 ) ;
return;
}
if ( V_92 & V_95 )
V_91 |= F_23 ( V_2 , F_2 ( & V_60 -> V_68 ) ) ;
if ( V_92 & V_96 )
V_91 |= F_16 ( V_2 , F_2 ( & V_60 -> V_57 ) ) ;
if ( V_92 & V_97 )
V_91 |= F_25 ( V_2 , F_2 ( & V_60 -> V_72 ) ) ;
if ( V_92 & V_98 )
V_91 |= F_24 ( V_2 , F_2 ( & V_60 -> V_70 ) ) ;
if ( V_92 & V_99 )
V_91 |= F_26 ( V_2 ,
F_2 ( & V_60 -> V_74 ) ) ;
if ( V_92 & V_100 )
V_91 |= F_27 ( V_2 , F_2 ( & V_60 -> V_76 ) ) ;
if ( V_92 & V_101 )
V_91 |= F_28 ( V_2 , F_2 ( & V_60 -> V_76 ) ) ;
if ( V_92 & V_102 )
V_91 |= F_29 ( V_2 , F_2 ( & V_60 -> V_76 ) ) ;
if ( V_92 & V_103 )
V_91 |= F_30 ( V_2 ) ;
F_5 ( V_91 , & V_60 -> V_93 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_10 . V_60 )
F_34 ( & V_7 -> V_10 . F_31 ) ;
}
static int F_35 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
struct V_108 T_2 * V_109 ;
struct V_110 * V_111 = V_107 ;
int V_112 = V_113 ;
if ( strcmp ( V_111 -> V_114 , V_115 ) != 0 )
return V_116 ;
if ( ! V_117 )
return V_116 ;
V_109 = V_117 -> V_109 ;
if ( V_111 -> type == 0x80 &&
( F_2 ( & V_109 -> V_118 ) & 1 ) == 0 )
V_112 = V_119 ;
F_5 ( 0 , & V_109 -> V_120 ) ;
return V_112 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_10 = & V_7 -> V_10 ;
struct V_121 * V_122 ;
T_5 V_123 ;
struct V_124 * V_125 , * V_126 , * V_127 = NULL ;
unsigned long long V_128 ;
T_6 V_129 ;
T_1 V_130 ;
int V_53 = 0 ;
V_123 = F_37 ( & V_2 -> V_29 -> V_2 ) ;
if ( ! V_123 || F_38 ( V_123 , & V_125 ) )
return;
if ( F_39 ( V_123 ) )
V_127 = V_125 ;
else {
F_19 (acpi_cdev, &acpi_dev->children, node) {
if ( F_39 ( V_126 -> V_123 ) ) {
V_127 = V_126 ;
break;
}
}
}
if ( ! V_127 ) {
F_40 ( L_25 ) ;
return;
}
F_19 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_53 >= 8 ) {
F_41 ( & V_2 -> V_29 -> V_2 ,
L_26 ) ;
return;
}
V_129 =
F_42 ( V_126 -> V_123 , L_27 ,
NULL , & V_128 ) ;
if ( F_43 ( V_129 ) ) {
if ( ! V_128 )
goto V_131;
F_5 ( ( T_1 ) ( V_128 & 0x0f0f ) ,
& V_10 -> V_109 -> V_132 [ V_53 ] ) ;
V_53 ++ ;
}
}
V_133:
if ( V_53 < 8 )
F_5 ( 0 , & V_10 -> V_109 -> V_132 [ V_53 ] ) ;
return;
V_131:
V_53 = 0 ;
F_19 (connector, &dev->mode_config.connector_list, head) {
int V_134 = V_135 ;
if ( V_53 >= 8 ) {
F_41 ( & V_2 -> V_29 -> V_2 ,
L_28 ) ;
return;
}
switch ( V_122 -> V_136 ) {
case V_137 :
case V_138 :
V_134 = V_139 ;
break;
case V_140 :
case V_141 :
case V_142 :
case V_143 :
V_134 = V_144 ;
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
V_134 = V_150 ;
break;
case V_151 :
V_134 = V_152 ;
break;
}
V_130 = F_2 ( & V_10 -> V_109 -> V_132 [ V_53 ] ) ;
F_5 ( V_130 | ( 1 << 31 ) | V_134 | V_53 ,
& V_10 -> V_109 -> V_132 [ V_53 ] ) ;
V_53 ++ ;
}
goto V_133;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_10 = & V_7 -> V_10 ;
int V_53 = 0 ;
T_1 V_153 ;
do {
V_153 = F_2 ( & V_10 -> V_109 -> V_132 [ V_53 ] ) ;
F_5 ( V_153 , & V_10 -> V_109 -> V_154 [ V_53 ] ) ;
} while ( ++ V_53 < 8 && V_153 != 0 );
}
void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_155 )
return;
if ( V_10 -> V_109 ) {
if ( F_46 ( V_2 , V_156 ) ) {
F_36 ( V_2 ) ;
F_44 ( V_2 ) ;
}
F_5 ( 0 , & V_10 -> V_109 -> V_120 ) ;
F_5 ( 1 , & V_10 -> V_109 -> V_157 ) ;
V_117 = V_10 ;
F_47 ( & V_158 ) ;
}
if ( V_10 -> V_60 ) {
F_5 ( V_159 , & V_10 -> V_60 -> V_160 ) ;
F_5 ( V_161 , & V_10 -> V_60 -> V_162 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_155 )
return;
if ( V_10 -> V_60 )
F_5 ( V_163 , & V_10 -> V_60 -> V_162 ) ;
F_49 ( & V_7 -> V_10 . F_31 ) ;
if ( V_10 -> V_109 ) {
F_5 ( 0 , & V_10 -> V_109 -> V_157 ) ;
V_117 = NULL ;
F_50 ( & V_158 ) ;
}
F_51 ( V_10 -> V_155 ) ;
V_10 -> V_155 = NULL ;
V_10 -> V_109 = NULL ;
V_10 -> F_1 = NULL ;
V_10 -> V_60 = NULL ;
V_10 -> V_164 = NULL ;
V_10 -> V_165 = NULL ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_10 = & V_7 -> V_10 ;
bool V_166 = false ;
T_1 V_167 ;
V_10 -> V_25 = 1 ;
V_10 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_168 , 0 , & V_167 ) == 0 ) {
V_167 <<= 1 ;
V_10 -> V_25 |= V_167 ;
}
if ( F_1 ( V_2 , V_169 , 0 , & V_167 ) == 0 ) {
V_10 -> V_22 |= V_167 ;
V_166 = true ;
}
if ( F_1 ( V_2 , V_170 , 0 , & V_167 ) == 0 ) {
T_1 V_171 = V_167 & 0x7ff ;
T_1 V_172 = V_167 & ~ 0xfff ;
V_167 = ( V_172 << 4 ) | ( V_171 << 1 ) | 1 ;
if ( V_166 ) {
T_1 V_173 = V_10 -> V_22 ;
if ( ( V_173 & V_167 ) != V_173 )
F_4 ( L_29 , V_173 , V_167 ) ;
} else {
V_10 -> V_22 |= V_167 ;
}
}
F_4 ( L_30 ,
V_10 -> V_25 ,
V_10 -> V_22 ) ;
}
static inline void F_52 ( struct V_1 * V_2 ) {}
int F_53 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_90 * V_10 = & V_7 -> V_10 ;
void T_2 * V_40 ;
T_1 V_174 , V_175 ;
char V_176 [ sizeof( V_177 ) ] ;
int V_178 = 0 ;
F_54 ( V_2 -> V_29 , V_179 , & V_174 ) ;
F_4 ( L_31 , V_174 ) ;
if ( V_174 == 0 ) {
F_4 ( L_32 ) ;
return - V_180 ;
}
#ifdef F_55
F_56 ( & V_10 -> F_31 , F_31 ) ;
#endif
V_40 = F_57 ( V_174 , V_181 ) ;
if ( ! V_40 )
return - V_182 ;
F_58 ( V_176 , V_40 , sizeof( V_176 ) ) ;
if ( memcmp ( V_176 , V_177 , 16 ) ) {
F_4 ( L_33 ) ;
V_178 = - V_23 ;
goto V_183;
}
V_10 -> V_155 = V_40 ;
V_10 -> V_164 = V_40 + V_184 ;
V_10 -> V_165 = V_40 + V_185 ;
V_175 = F_2 ( & V_10 -> V_155 -> V_175 ) ;
if ( V_175 & V_186 ) {
F_4 ( L_34 ) ;
V_10 -> V_109 = V_40 + V_187 ;
}
if ( V_175 & V_188 ) {
F_4 ( L_35 ) ;
V_10 -> F_1 = V_40 + V_189 ;
F_52 ( V_2 ) ;
}
if ( V_175 & V_190 ) {
F_4 ( L_36 ) ;
V_10 -> V_60 = V_40 + V_191 ;
F_5 ( V_163 , & V_10 -> V_60 -> V_162 ) ;
}
return 0 ;
V_183:
F_51 ( V_40 ) ;
return V_178 ;
}
