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
} else if ( V_15 > 500 ) {
F_3 ( 1 , L_1 , V_15 ) ;
V_15 = 500 ;
}
V_13 = F_2 ( & F_1 -> V_13 ) ;
if ( V_13 & V_26 ) {
F_4 ( L_2 ) ;
return - V_27 ;
}
V_13 = V_3 | V_26 ;
F_5 ( V_4 , & F_1 -> V_4 ) ;
F_5 ( V_13 , & F_1 -> V_13 ) ;
F_6 ( V_2 -> V_28 , V_29 , & V_14 ) ;
if ( ! ( V_14 & V_30 ) || ( V_14 & V_31 ) ) {
V_14 |= V_30 ;
V_14 &= ~ V_31 ;
F_7 ( V_2 -> V_28 , V_29 , V_14 ) ;
}
V_14 |= V_31 ;
F_7 ( V_2 -> V_28 , V_29 , V_14 ) ;
#define F_8 (((scic = ioread32(&swsci->scic)) & SWSCI_SCIC_INDICATOR) == 0)
if ( F_9 ( F_8 , V_15 ) ) {
F_4 ( L_3 ) ;
return - V_32 ;
}
V_13 = ( V_13 & V_33 ) >>
V_34 ;
if ( V_13 != V_35 ) {
F_4 ( L_4 , V_13 ) ;
return - V_36 ;
}
if ( V_5 )
* V_5 = F_2 ( & F_1 -> V_4 ) ;
return 0 ;
#undef F_8
}
int F_10 ( struct V_37 * V_37 ,
bool V_38 )
{
struct V_1 * V_2 = V_37 -> V_39 . V_2 ;
T_1 V_4 = 0 ;
T_1 type = 0 ;
T_1 V_40 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
V_40 = F_12 ( V_37 ) ;
if ( V_40 == V_41 ) {
V_40 = 0 ;
} else {
V_4 |= 1 << V_40 ;
V_40 ++ ;
}
if ( ! V_38 )
V_4 |= 4 << 8 ;
switch ( V_37 -> type ) {
case V_42 :
type = V_43 ;
break;
case V_44 :
case V_45 :
case V_46 :
type = V_47 ;
break;
case V_48 :
type = V_49 ;
break;
default:
F_3 ( 1 , L_5 ,
V_37 -> type ) ;
return - V_23 ;
}
V_4 |= type << ( 16 + V_40 * 3 ) ;
return F_1 ( V_2 , V_50 , V_4 , NULL ) ;
}
int F_13 ( struct V_1 * V_2 , T_4 V_51 )
{
int V_52 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
for ( V_52 = 0 ; V_52 < F_14 ( V_53 ) ; V_52 ++ ) {
if ( V_51 == V_53 [ V_52 ] . V_54 )
return F_1 ( V_2 , V_55 ,
V_53 [ V_52 ] . V_4 , NULL ) ;
}
return - V_23 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_1 V_56 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_61 = NULL ;
struct V_62 * V_63 = V_7 -> V_64 [ 0 ] ;
struct V_65 T_2 * V_66 = V_7 -> V_10 . V_66 ;
T_1 V_67 = 0 ;
bool V_68 = false ;
F_4 ( L_6 , V_56 ) ;
if ( ! ( V_56 & V_69 ) )
return V_70 ;
V_56 &= V_71 ;
if ( V_56 > 255 )
return V_70 ;
F_16 ( & V_2 -> V_72 . V_73 ) ;
F_17 (encoder, &dev->mode_config.encoder_list, head)
if ( V_58 -> V_63 == V_63 ) {
V_68 = true ;
break;
}
if ( ! V_68 ) {
V_67 = V_70 ;
goto V_74;
}
F_17 (connector, &dev->mode_config.connector_list, head)
if ( V_60 -> V_58 == V_58 )
V_61 = F_18 ( V_60 ) ;
if ( ! V_61 ) {
V_67 = V_70 ;
goto V_74;
}
F_19 ( L_7 , V_56 ) ;
F_20 ( V_61 , V_56 , 255 ) ;
F_5 ( F_21 ( V_56 * 100 , 255 ) | V_75 , & V_66 -> V_76 ) ;
V_74:
F_22 ( & V_2 -> V_72 . V_73 ) ;
return V_67 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_77 )
{
F_4 ( L_8 ) ;
return V_78 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_79 )
{
F_4 ( L_9 ) ;
return V_80 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_81 )
{
F_4 ( L_10 ) ;
return V_82 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_83 )
{
F_4 ( L_11 ) ;
return V_84 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_1 V_85 )
{
if ( ! V_85 )
F_4 ( L_12 ) ;
if ( V_85 & V_86 )
F_4 ( L_13 ) ;
if ( V_85 & V_87 )
F_4 ( L_14 ) ;
if ( V_85 & V_88 )
F_4 ( L_15 ) ;
if ( V_85 & V_89 )
F_4 ( L_16 ) ;
if ( V_85 & V_90 )
F_4 ( L_17 ) ;
return V_91 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_85 )
{
if ( V_85 & V_92 )
F_4 ( L_18 ) ;
else
F_4 ( L_19 ) ;
return V_93 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_1 V_85 )
{
if ( V_85 & V_94 )
F_4 ( L_20 ) ;
else
F_4 ( L_21 ) ;
return V_95 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
F_4 ( L_22 ) ;
return V_96 ;
}
static void F_31 ( struct V_97 * V_98 )
{
struct V_99 * V_10 =
F_32 ( V_98 , struct V_99 , F_31 ) ;
struct V_6 * V_7 =
F_32 ( V_10 , struct V_6 , V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_65 T_2 * V_66 = V_7 -> V_10 . V_66 ;
T_1 V_100 = 0 ;
T_1 V_101 ;
if ( ! V_66 )
return;
V_101 = F_2 ( & V_66 -> V_102 ) ;
if ( ! ( V_101 & V_103 ) ) {
F_4 ( L_23 ,
V_101 ) ;
return;
}
if ( V_101 & V_104 )
V_100 |= F_23 ( V_2 , F_2 ( & V_66 -> V_77 ) ) ;
if ( V_101 & V_105 )
V_100 |= F_15 ( V_2 , F_2 ( & V_66 -> V_56 ) ) ;
if ( V_101 & V_106 )
V_100 |= F_25 ( V_2 , F_2 ( & V_66 -> V_81 ) ) ;
if ( V_101 & V_107 )
V_100 |= F_24 ( V_2 , F_2 ( & V_66 -> V_79 ) ) ;
if ( V_101 & V_108 )
V_100 |= F_26 ( V_2 ,
F_2 ( & V_66 -> V_83 ) ) ;
if ( V_101 & V_109 )
V_100 |= F_27 ( V_2 , F_2 ( & V_66 -> V_85 ) ) ;
if ( V_101 & V_110 )
V_100 |= F_28 ( V_2 , F_2 ( & V_66 -> V_85 ) ) ;
if ( V_101 & V_111 )
V_100 |= F_29 ( V_2 , F_2 ( & V_66 -> V_85 ) ) ;
if ( V_101 & V_112 )
V_100 |= F_30 ( V_2 ) ;
F_5 ( V_100 , & V_66 -> V_102 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_10 . V_66 )
F_34 ( & V_7 -> V_10 . F_31 ) ;
}
static int F_35 ( struct V_113 * V_114 ,
unsigned long V_115 , void * V_116 )
{
struct V_117 T_2 * V_118 ;
struct V_119 * V_120 = V_116 ;
int V_67 = V_121 ;
if ( strcmp ( V_120 -> V_122 , V_123 ) != 0 )
return V_124 ;
if ( ! V_125 )
return V_124 ;
V_118 = V_125 -> V_118 ;
if ( V_120 -> type == 0x80 &&
( F_2 ( & V_118 -> V_126 ) & 1 ) == 0 )
V_67 = V_127 ;
F_5 ( 0 , & V_118 -> V_128 ) ;
return V_67 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_99 * V_10 = & V_7 -> V_10 ;
struct V_59 * V_60 ;
T_5 V_129 ;
struct V_130 * V_131 , * V_132 , * V_133 = NULL ;
unsigned long long V_134 ;
T_6 V_135 ;
T_1 V_136 ;
int V_52 = 0 ;
V_129 = F_37 ( & V_2 -> V_28 -> V_2 ) ;
if ( ! V_129 || F_38 ( V_129 , & V_131 ) )
return;
if ( F_39 ( V_129 ) )
V_133 = V_131 ;
else {
F_17 (acpi_cdev, &acpi_dev->children, node) {
if ( F_39 ( V_132 -> V_129 ) ) {
V_133 = V_132 ;
break;
}
}
}
if ( ! V_133 ) {
F_40 ( L_24 ) ;
return;
}
F_17 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_52 >= 8 ) {
F_41 ( & V_2 -> V_28 -> V_2 ,
L_25 ) ;
return;
}
V_135 =
F_42 ( V_132 -> V_129 , L_26 ,
NULL , & V_134 ) ;
if ( F_43 ( V_135 ) ) {
if ( ! V_134 )
goto V_137;
F_5 ( ( T_1 ) ( V_134 & 0x0f0f ) ,
& V_10 -> V_118 -> V_138 [ V_52 ] ) ;
V_52 ++ ;
}
}
V_139:
if ( V_52 < 8 )
F_5 ( 0 , & V_10 -> V_118 -> V_138 [ V_52 ] ) ;
return;
V_137:
V_52 = 0 ;
F_17 (connector, &dev->mode_config.connector_list, head) {
int V_140 = V_141 ;
if ( V_52 >= 8 ) {
F_41 ( & V_2 -> V_28 -> V_2 ,
L_27 ) ;
return;
}
switch ( V_60 -> V_142 ) {
case V_143 :
case V_144 :
V_140 = V_145 ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
V_140 = V_150 ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
V_140 = V_156 ;
break;
case V_157 :
V_140 = V_158 ;
break;
}
V_136 = F_2 ( & V_10 -> V_118 -> V_138 [ V_52 ] ) ;
F_5 ( V_136 | ( 1 << 31 ) | V_140 | V_52 ,
& V_10 -> V_118 -> V_138 [ V_52 ] ) ;
V_52 ++ ;
}
goto V_139;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_99 * V_10 = & V_7 -> V_10 ;
int V_52 = 0 ;
T_1 V_159 ;
do {
V_159 = F_2 ( & V_10 -> V_118 -> V_138 [ V_52 ] ) ;
F_5 ( V_159 , & V_10 -> V_118 -> V_160 [ V_52 ] ) ;
} while ( ++ V_52 < 8 && V_159 != 0 );
}
void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_99 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_161 )
return;
if ( V_10 -> V_118 ) {
if ( F_46 ( V_2 , V_162 ) ) {
F_36 ( V_2 ) ;
F_44 ( V_2 ) ;
}
F_5 ( 0 , & V_10 -> V_118 -> V_128 ) ;
F_5 ( 1 , & V_10 -> V_118 -> V_163 ) ;
V_125 = V_10 ;
F_47 ( & V_164 ) ;
}
if ( V_10 -> V_66 ) {
F_5 ( V_165 , & V_10 -> V_66 -> V_166 ) ;
F_5 ( V_167 , & V_10 -> V_66 -> V_168 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_99 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_161 )
return;
if ( V_10 -> V_66 )
F_5 ( V_169 , & V_10 -> V_66 -> V_168 ) ;
F_49 ( & V_7 -> V_10 . F_31 ) ;
if ( V_10 -> V_118 ) {
F_5 ( 0 , & V_10 -> V_118 -> V_163 ) ;
V_125 = NULL ;
F_50 ( & V_164 ) ;
}
F_51 ( V_10 -> V_161 ) ;
V_10 -> V_161 = NULL ;
V_10 -> V_118 = NULL ;
V_10 -> F_1 = NULL ;
V_10 -> V_66 = NULL ;
V_10 -> V_170 = NULL ;
V_10 -> V_171 = NULL ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_99 * V_10 = & V_7 -> V_10 ;
bool V_172 = false ;
T_1 V_173 ;
V_10 -> V_25 = 1 ;
V_10 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_174 , 0 , & V_173 ) == 0 ) {
V_173 <<= 1 ;
V_10 -> V_25 |= V_173 ;
}
if ( F_1 ( V_2 , V_175 , 0 , & V_173 ) == 0 ) {
V_10 -> V_22 |= V_173 ;
V_172 = true ;
}
if ( F_1 ( V_2 , V_176 , 0 , & V_173 ) == 0 ) {
T_1 V_177 = V_173 & 0x7ff ;
T_1 V_178 = V_173 & ~ 0xfff ;
V_173 = ( V_178 << 4 ) | ( V_177 << 1 ) | 1 ;
if ( V_172 ) {
T_1 V_179 = V_10 -> V_22 ;
if ( ( V_179 & V_173 ) != V_179 )
F_4 ( L_28 , V_179 , V_173 ) ;
} else {
V_10 -> V_22 |= V_173 ;
}
}
F_4 ( L_29 ,
V_10 -> V_25 ,
V_10 -> V_22 ) ;
}
static inline void F_52 ( struct V_1 * V_2 ) {}
int F_53 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_99 * V_10 = & V_7 -> V_10 ;
void T_2 * V_39 ;
T_1 V_180 , V_181 ;
char V_182 [ sizeof( V_183 ) ] ;
int V_184 = 0 ;
F_54 ( V_2 -> V_28 , V_185 , & V_180 ) ;
F_4 ( L_30 , V_180 ) ;
if ( V_180 == 0 ) {
F_4 ( L_31 ) ;
return - V_186 ;
}
#ifdef F_55
F_56 ( & V_10 -> F_31 , F_31 ) ;
#endif
V_39 = F_57 ( V_180 , V_187 ) ;
if ( ! V_39 )
return - V_188 ;
F_58 ( V_182 , V_39 , sizeof( V_182 ) ) ;
if ( memcmp ( V_182 , V_183 , 16 ) ) {
F_4 ( L_32 ) ;
V_184 = - V_23 ;
goto V_189;
}
V_10 -> V_161 = V_39 ;
V_10 -> V_170 = V_39 + V_190 ;
V_10 -> V_171 = V_39 + V_191 ;
V_181 = F_2 ( & V_10 -> V_161 -> V_181 ) ;
if ( V_181 & V_192 ) {
F_4 ( L_33 ) ;
V_10 -> V_118 = V_39 + V_193 ;
}
if ( V_181 & V_194 ) {
F_4 ( L_34 ) ;
V_10 -> F_1 = V_39 + V_195 ;
F_52 ( V_2 ) ;
}
if ( V_181 & V_196 ) {
F_4 ( L_35 ) ;
V_10 -> V_66 = V_39 + V_197 ;
F_5 ( V_169 , & V_10 -> V_66 -> V_168 ) ;
}
return 0 ;
V_189:
F_51 ( V_39 ) ;
return V_184 ;
}
