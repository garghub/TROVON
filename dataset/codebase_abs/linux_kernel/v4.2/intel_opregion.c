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
case V_48 :
type = V_49 ;
break;
case V_50 :
type = V_51 ;
break;
default:
F_13 ( 1 , L_6 ,
V_38 -> type ) ;
return - V_23 ;
}
V_4 |= type << ( 16 + V_41 * 3 ) ;
return F_1 ( V_2 , V_52 , V_4 , NULL ) ;
}
int F_14 ( struct V_1 * V_2 , T_4 V_53 )
{
int V_54 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
for ( V_54 = 0 ; V_54 < F_15 ( V_55 ) ; V_54 ++ ) {
if ( V_53 == V_55 [ V_54 ] . V_56 )
return F_1 ( V_2 , V_57 ,
V_55 [ V_54 ] . V_4 , NULL ) ;
}
return - V_23 ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 V_58 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_59 * V_59 ;
struct V_60 T_2 * V_61 = V_7 -> V_10 . V_61 ;
F_4 ( L_7 , V_58 ) ;
if ( F_17 () == V_62 ) {
F_18 ( L_8 ) ;
return 0 ;
}
if ( ! ( V_58 & V_63 ) )
return V_64 ;
V_58 &= V_65 ;
if ( V_58 > 255 )
return V_64 ;
F_19 ( & V_2 -> V_66 . V_67 , NULL ) ;
F_18 ( L_9 , V_58 ) ;
F_20 (intel_connector, &dev->mode_config.connector_list, base.head)
F_21 ( V_59 , V_58 , 255 ) ;
F_5 ( F_22 ( V_58 * 100 , 255 ) | V_68 , & V_61 -> V_69 ) ;
F_23 ( & V_2 -> V_66 . V_67 ) ;
return 0 ;
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
F_4 ( L_13 ) ;
return V_77 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_78 )
{
if ( ! V_78 )
F_4 ( L_14 ) ;
if ( V_78 & V_79 )
F_4 ( L_15 ) ;
if ( V_78 & V_80 )
F_4 ( L_16 ) ;
if ( V_78 & V_81 )
F_4 ( L_17 ) ;
if ( V_78 & V_82 )
F_4 ( L_18 ) ;
if ( V_78 & V_83 )
F_4 ( L_19 ) ;
return V_84 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_1 V_78 )
{
if ( V_78 & V_85 )
F_4 ( L_20 ) ;
else
F_4 ( L_21 ) ;
return V_86 ;
}
static T_1 F_30 ( struct V_1 * V_2 , T_1 V_78 )
{
if ( V_78 & V_87 )
F_4 ( L_22 ) ;
else
F_4 ( L_23 ) ;
return V_88 ;
}
static T_1 F_31 ( struct V_1 * V_2 )
{
F_4 ( L_24 ) ;
return V_89 ;
}
static void F_32 ( struct V_90 * V_91 )
{
struct V_92 * V_10 =
F_33 ( V_91 , struct V_92 , F_32 ) ;
struct V_6 * V_7 =
F_33 ( V_10 , struct V_6 , V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_60 T_2 * V_61 = V_7 -> V_10 . V_61 ;
T_1 V_93 = 0 ;
T_1 V_94 ;
if ( ! V_61 )
return;
V_94 = F_2 ( & V_61 -> V_95 ) ;
if ( ! ( V_94 & V_96 ) ) {
F_4 ( L_25 ,
V_94 ) ;
return;
}
if ( V_94 & V_97 )
V_93 |= F_24 ( V_2 , F_2 ( & V_61 -> V_70 ) ) ;
if ( V_94 & V_98 )
V_93 |= F_16 ( V_2 , F_2 ( & V_61 -> V_58 ) ) ;
if ( V_94 & V_99 )
V_93 |= F_26 ( V_2 , F_2 ( & V_61 -> V_74 ) ) ;
if ( V_94 & V_100 )
V_93 |= F_25 ( V_2 , F_2 ( & V_61 -> V_72 ) ) ;
if ( V_94 & V_101 )
V_93 |= F_27 ( V_2 ,
F_2 ( & V_61 -> V_76 ) ) ;
if ( V_94 & V_102 )
V_93 |= F_28 ( V_2 , F_2 ( & V_61 -> V_78 ) ) ;
if ( V_94 & V_103 )
V_93 |= F_29 ( V_2 , F_2 ( & V_61 -> V_78 ) ) ;
if ( V_94 & V_104 )
V_93 |= F_30 ( V_2 , F_2 ( & V_61 -> V_78 ) ) ;
if ( V_94 & V_105 )
V_93 |= F_31 ( V_2 ) ;
F_5 ( V_93 , & V_61 -> V_95 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_10 . V_61 )
F_35 ( & V_7 -> V_10 . F_32 ) ;
}
static int F_36 ( struct V_106 * V_107 ,
unsigned long V_108 , void * V_109 )
{
struct V_110 T_2 * V_111 ;
struct V_112 * V_113 = V_109 ;
int V_114 = V_115 ;
if ( strcmp ( V_113 -> V_116 , V_117 ) != 0 )
return V_118 ;
if ( ! V_119 )
return V_118 ;
V_111 = V_119 -> V_111 ;
if ( V_113 -> type == 0x80 &&
( F_2 ( & V_111 -> V_120 ) & 1 ) == 0 )
V_114 = V_121 ;
F_5 ( 0 , & V_111 -> V_122 ) ;
return V_114 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
struct V_123 * V_124 ;
T_5 V_125 ;
struct V_126 * V_127 , * V_128 , * V_129 = NULL ;
unsigned long long V_130 ;
T_6 V_131 ;
T_1 V_132 ;
int V_54 = 0 ;
V_125 = F_38 ( & V_2 -> V_29 -> V_2 ) ;
if ( ! V_125 || F_39 ( V_125 , & V_127 ) )
return;
if ( F_40 ( V_125 ) )
V_129 = V_127 ;
else {
F_20 (acpi_cdev, &acpi_dev->children, node) {
if ( F_40 ( V_128 -> V_125 ) ) {
V_129 = V_128 ;
break;
}
}
}
if ( ! V_129 ) {
F_41 ( L_26 ) ;
return;
}
F_20 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_54 >= 8 ) {
F_42 ( & V_2 -> V_29 -> V_2 ,
L_27 ) ;
return;
}
V_131 =
F_43 ( V_128 -> V_125 , L_28 ,
NULL , & V_130 ) ;
if ( F_44 ( V_131 ) ) {
if ( ! V_130 )
goto V_133;
F_5 ( ( T_1 ) ( V_130 & 0x0f0f ) ,
& V_10 -> V_111 -> V_134 [ V_54 ] ) ;
V_54 ++ ;
}
}
V_135:
if ( V_54 < 8 )
F_5 ( 0 , & V_10 -> V_111 -> V_134 [ V_54 ] ) ;
return;
V_133:
V_54 = 0 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
int V_136 = V_137 ;
if ( V_54 >= 8 ) {
F_42 ( & V_2 -> V_29 -> V_2 ,
L_29 ) ;
return;
}
switch ( V_124 -> V_138 ) {
case V_139 :
case V_140 :
V_136 = V_141 ;
break;
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_136 = V_146 ;
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
V_136 = V_152 ;
break;
case V_153 :
V_136 = V_154 ;
break;
}
V_132 = F_2 ( & V_10 -> V_111 -> V_134 [ V_54 ] ) ;
F_5 ( V_132 | ( 1 << 31 ) | V_136 | V_54 ,
& V_10 -> V_111 -> V_134 [ V_54 ] ) ;
V_54 ++ ;
}
goto V_135;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
int V_54 = 0 ;
T_1 V_155 ;
do {
V_155 = F_2 ( & V_10 -> V_111 -> V_134 [ V_54 ] ) ;
F_5 ( V_155 , & V_10 -> V_111 -> V_156 [ V_54 ] ) ;
} while ( ++ V_54 < 8 && V_155 != 0 );
}
void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_157 )
return;
if ( V_10 -> V_111 ) {
F_37 ( V_2 ) ;
F_45 ( V_2 ) ;
F_5 ( 0 , & V_10 -> V_111 -> V_122 ) ;
F_5 ( 1 , & V_10 -> V_111 -> V_158 ) ;
V_119 = V_10 ;
F_47 ( & V_159 ) ;
}
if ( V_10 -> V_61 ) {
F_5 ( V_160 , & V_10 -> V_61 -> V_161 ) ;
F_5 ( V_162 , & V_10 -> V_61 -> V_163 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_157 )
return;
if ( V_10 -> V_61 )
F_5 ( V_164 , & V_10 -> V_61 -> V_163 ) ;
F_49 ( & V_7 -> V_10 . F_32 ) ;
if ( V_10 -> V_111 ) {
F_5 ( 0 , & V_10 -> V_111 -> V_158 ) ;
V_119 = NULL ;
F_50 ( & V_159 ) ;
}
F_51 ( V_10 -> V_157 ) ;
V_10 -> V_157 = NULL ;
V_10 -> V_111 = NULL ;
V_10 -> F_1 = NULL ;
V_10 -> V_61 = NULL ;
V_10 -> V_165 = NULL ;
V_10 -> V_166 = NULL ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
bool V_167 = false ;
T_1 V_168 ;
V_10 -> V_25 = 1 ;
V_10 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_169 , 0 , & V_168 ) == 0 ) {
V_168 <<= 1 ;
V_10 -> V_25 |= V_168 ;
}
if ( F_1 ( V_2 , V_170 , 0 , & V_168 ) == 0 ) {
V_10 -> V_22 |= V_168 ;
V_167 = true ;
}
if ( F_1 ( V_2 , V_171 , 0 , & V_168 ) == 0 ) {
T_1 V_172 = V_168 & 0x7ff ;
T_1 V_173 = V_168 & ~ 0xfff ;
V_168 = ( V_173 << 4 ) | ( V_172 << 1 ) | 1 ;
if ( V_167 ) {
T_1 V_174 = V_10 -> V_22 ;
if ( ( V_174 & V_168 ) != V_174 )
F_4 ( L_30 , V_174 , V_168 ) ;
} else {
V_10 -> V_22 |= V_168 ;
}
}
F_4 ( L_31 ,
V_10 -> V_25 ,
V_10 -> V_22 ) ;
}
static inline void F_52 ( struct V_1 * V_2 ) {}
int F_53 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
void T_2 * V_40 ;
T_1 V_175 , V_176 ;
char V_177 [ sizeof( V_178 ) ] ;
int V_179 = 0 ;
F_54 ( V_2 -> V_29 , V_180 , & V_175 ) ;
F_4 ( L_32 , V_175 ) ;
if ( V_175 == 0 ) {
F_4 ( L_33 ) ;
return - V_181 ;
}
#ifdef F_55
F_56 ( & V_10 -> F_32 , F_32 ) ;
#endif
V_40 = F_57 ( V_175 , V_182 ) ;
if ( ! V_40 )
return - V_183 ;
F_58 ( V_177 , V_40 , sizeof( V_177 ) ) ;
if ( memcmp ( V_177 , V_178 , 16 ) ) {
F_4 ( L_34 ) ;
V_179 = - V_23 ;
goto V_184;
}
V_10 -> V_157 = V_40 ;
V_10 -> V_165 = V_40 + V_185 ;
V_10 -> V_166 = V_40 + V_186 ;
V_176 = F_2 ( & V_10 -> V_157 -> V_176 ) ;
if ( V_176 & V_187 ) {
F_4 ( L_35 ) ;
V_10 -> V_111 = V_40 + V_188 ;
}
if ( V_176 & V_189 ) {
F_4 ( L_36 ) ;
V_10 -> F_1 = V_40 + V_190 ;
F_52 ( V_2 ) ;
}
if ( V_176 & V_191 ) {
F_4 ( L_37 ) ;
V_10 -> V_61 = V_40 + V_192 ;
F_5 ( V_164 , & V_10 -> V_61 -> V_163 ) ;
}
return 0 ;
V_184:
F_51 ( V_40 ) ;
return V_179 ;
}
