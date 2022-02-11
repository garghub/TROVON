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
static bool F_16 ( void )
{
return F_17 () &&
! F_18 () ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_1 V_58 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_59 * V_59 ;
struct V_60 T_2 * V_61 = V_7 -> V_10 . V_61 ;
F_4 ( L_7 , V_58 ) ;
if ( F_16 () ) {
F_20 ( L_8 ) ;
return 0 ;
}
if ( ! ( V_58 & V_62 ) )
return V_63 ;
V_58 &= V_64 ;
if ( V_58 > 255 )
return V_63 ;
F_21 ( & V_2 -> V_65 . V_66 , NULL ) ;
F_20 ( L_9 , V_58 ) ;
F_22 (intel_connector, &dev->mode_config.connector_list, base.head)
F_23 ( V_59 , V_58 , 255 ) ;
F_5 ( F_24 ( V_58 * 100 , 255 ) | V_67 , & V_61 -> V_68 ) ;
F_25 ( & V_2 -> V_65 . V_66 ) ;
return 0 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_69 )
{
F_4 ( L_10 ) ;
return V_70 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_1 V_71 )
{
F_4 ( L_11 ) ;
return V_72 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_73 )
{
F_4 ( L_12 ) ;
return V_74 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_1 V_75 )
{
F_4 ( L_13 ) ;
return V_76 ;
}
static T_1 F_30 ( struct V_1 * V_2 , T_1 V_77 )
{
if ( ! V_77 )
F_4 ( L_14 ) ;
if ( V_77 & V_78 )
F_4 ( L_15 ) ;
if ( V_77 & V_79 )
F_4 ( L_16 ) ;
if ( V_77 & V_80 )
F_4 ( L_17 ) ;
if ( V_77 & V_81 )
F_4 ( L_18 ) ;
if ( V_77 & V_82 )
F_4 ( L_19 ) ;
return V_83 ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_1 V_77 )
{
if ( V_77 & V_84 )
F_4 ( L_20 ) ;
else
F_4 ( L_21 ) ;
return V_85 ;
}
static T_1 F_32 ( struct V_1 * V_2 , T_1 V_77 )
{
if ( V_77 & V_86 )
F_4 ( L_22 ) ;
else
F_4 ( L_23 ) ;
return V_87 ;
}
static T_1 F_33 ( struct V_1 * V_2 )
{
F_4 ( L_24 ) ;
return V_88 ;
}
static void F_34 ( struct V_89 * V_90 )
{
struct V_91 * V_10 =
F_35 ( V_90 , struct V_91 , F_34 ) ;
struct V_6 * V_7 =
F_35 ( V_10 , struct V_6 , V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_60 T_2 * V_61 = V_7 -> V_10 . V_61 ;
T_1 V_92 = 0 ;
T_1 V_93 ;
if ( ! V_61 )
return;
V_93 = F_2 ( & V_61 -> V_94 ) ;
if ( ! ( V_93 & V_95 ) ) {
F_4 ( L_25 ,
V_93 ) ;
return;
}
if ( V_93 & V_96 )
V_92 |= F_26 ( V_2 , F_2 ( & V_61 -> V_69 ) ) ;
if ( V_93 & V_97 )
V_92 |= F_19 ( V_2 , F_2 ( & V_61 -> V_58 ) ) ;
if ( V_93 & V_98 )
V_92 |= F_28 ( V_2 , F_2 ( & V_61 -> V_73 ) ) ;
if ( V_93 & V_99 )
V_92 |= F_27 ( V_2 , F_2 ( & V_61 -> V_71 ) ) ;
if ( V_93 & V_100 )
V_92 |= F_29 ( V_2 ,
F_2 ( & V_61 -> V_75 ) ) ;
if ( V_93 & V_101 )
V_92 |= F_30 ( V_2 , F_2 ( & V_61 -> V_77 ) ) ;
if ( V_93 & V_102 )
V_92 |= F_31 ( V_2 , F_2 ( & V_61 -> V_77 ) ) ;
if ( V_93 & V_103 )
V_92 |= F_32 ( V_2 , F_2 ( & V_61 -> V_77 ) ) ;
if ( V_93 & V_104 )
V_92 |= F_33 ( V_2 ) ;
F_5 ( V_92 , & V_61 -> V_94 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_10 . V_61 )
F_37 ( & V_7 -> V_10 . F_34 ) ;
}
static int F_38 ( struct V_105 * V_106 ,
unsigned long V_107 , void * V_108 )
{
struct V_109 T_2 * V_110 ;
struct V_111 * V_112 = V_108 ;
int V_113 = V_114 ;
if ( strcmp ( V_112 -> V_115 , V_116 ) != 0 )
return V_117 ;
if ( ! V_118 )
return V_117 ;
V_110 = V_118 -> V_110 ;
if ( V_112 -> type == 0x80 &&
( F_2 ( & V_110 -> V_119 ) & 1 ) == 0 )
V_113 = V_120 ;
F_5 ( 0 , & V_110 -> V_121 ) ;
return V_113 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_10 = & V_7 -> V_10 ;
struct V_122 * V_123 ;
T_5 V_124 ;
struct V_125 * V_126 , * V_127 , * V_128 = NULL ;
unsigned long long V_129 ;
T_6 V_130 ;
T_1 V_131 ;
int V_54 = 0 ;
V_124 = F_40 ( & V_2 -> V_29 -> V_2 ) ;
if ( ! V_124 || F_41 ( V_124 , & V_126 ) )
return;
if ( F_42 ( V_124 ) )
V_128 = V_126 ;
else {
F_22 (acpi_cdev, &acpi_dev->children, node) {
if ( F_42 ( V_127 -> V_124 ) ) {
V_128 = V_127 ;
break;
}
}
}
if ( ! V_128 ) {
F_43 ( L_26 ) ;
return;
}
F_22 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_54 >= 8 ) {
F_44 ( & V_2 -> V_29 -> V_2 ,
L_27 ) ;
return;
}
V_130 =
F_45 ( V_127 -> V_124 , L_28 ,
NULL , & V_129 ) ;
if ( F_46 ( V_130 ) ) {
if ( ! V_129 )
goto V_132;
F_5 ( ( T_1 ) ( V_129 & 0x0f0f ) ,
& V_10 -> V_110 -> V_133 [ V_54 ] ) ;
V_54 ++ ;
}
}
V_134:
if ( V_54 < 8 )
F_5 ( 0 , & V_10 -> V_110 -> V_133 [ V_54 ] ) ;
return;
V_132:
V_54 = 0 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
int V_135 = V_136 ;
if ( V_54 >= 8 ) {
F_44 ( & V_2 -> V_29 -> V_2 ,
L_29 ) ;
return;
}
switch ( V_123 -> V_137 ) {
case V_138 :
case V_139 :
V_135 = V_140 ;
break;
case V_141 :
case V_142 :
case V_143 :
case V_144 :
V_135 = V_145 ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
V_135 = V_151 ;
break;
case V_152 :
V_135 = V_153 ;
break;
}
V_131 = F_2 ( & V_10 -> V_110 -> V_133 [ V_54 ] ) ;
F_5 ( V_131 | ( 1 << 31 ) | V_135 | V_54 ,
& V_10 -> V_110 -> V_133 [ V_54 ] ) ;
V_54 ++ ;
}
goto V_134;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_10 = & V_7 -> V_10 ;
int V_54 = 0 ;
T_1 V_154 ;
do {
V_154 = F_2 ( & V_10 -> V_110 -> V_133 [ V_54 ] ) ;
F_5 ( V_154 , & V_10 -> V_110 -> V_155 [ V_54 ] ) ;
} while ( ++ V_54 < 8 && V_154 != 0 );
}
void F_48 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_156 )
return;
if ( V_10 -> V_110 ) {
F_39 ( V_2 ) ;
F_47 ( V_2 ) ;
F_5 ( 0 , & V_10 -> V_110 -> V_121 ) ;
F_5 ( 1 , & V_10 -> V_110 -> V_157 ) ;
V_118 = V_10 ;
F_49 ( & V_158 ) ;
}
if ( V_10 -> V_61 ) {
F_5 ( V_159 , & V_10 -> V_61 -> V_160 ) ;
F_5 ( V_161 , & V_10 -> V_61 -> V_162 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_156 )
return;
if ( V_10 -> V_61 )
F_5 ( V_163 , & V_10 -> V_61 -> V_162 ) ;
F_51 ( & V_7 -> V_10 . F_34 ) ;
if ( V_10 -> V_110 ) {
F_5 ( 0 , & V_10 -> V_110 -> V_157 ) ;
V_118 = NULL ;
F_52 ( & V_158 ) ;
}
F_53 ( V_10 -> V_156 ) ;
V_10 -> V_156 = NULL ;
V_10 -> V_110 = NULL ;
V_10 -> F_1 = NULL ;
V_10 -> V_61 = NULL ;
V_10 -> V_164 = NULL ;
V_10 -> V_165 = NULL ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_10 = & V_7 -> V_10 ;
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
F_4 ( L_30 , V_173 , V_167 ) ;
} else {
V_10 -> V_22 |= V_167 ;
}
}
F_4 ( L_31 ,
V_10 -> V_25 ,
V_10 -> V_22 ) ;
}
static inline void F_54 ( struct V_1 * V_2 ) {}
int F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_91 * V_10 = & V_7 -> V_10 ;
void T_2 * V_40 ;
T_1 V_174 , V_175 ;
char V_176 [ sizeof( V_177 ) ] ;
int V_178 = 0 ;
F_56 ( V_2 -> V_29 , V_179 , & V_174 ) ;
F_4 ( L_32 , V_174 ) ;
if ( V_174 == 0 ) {
F_4 ( L_33 ) ;
return - V_180 ;
}
#ifdef F_57
F_58 ( & V_10 -> F_34 , F_34 ) ;
#endif
V_40 = F_59 ( V_174 , V_181 ) ;
if ( ! V_40 )
return - V_182 ;
F_60 ( V_176 , V_40 , sizeof( V_176 ) ) ;
if ( memcmp ( V_176 , V_177 , 16 ) ) {
F_4 ( L_34 ) ;
V_178 = - V_23 ;
goto V_183;
}
V_10 -> V_156 = V_40 ;
V_10 -> V_164 = V_40 + V_184 ;
V_10 -> V_165 = V_40 + V_185 ;
V_175 = F_2 ( & V_10 -> V_156 -> V_175 ) ;
if ( V_175 & V_186 ) {
F_4 ( L_35 ) ;
V_10 -> V_110 = V_40 + V_187 ;
}
if ( V_175 & V_188 ) {
F_4 ( L_36 ) ;
V_10 -> F_1 = V_40 + V_189 ;
F_54 ( V_2 ) ;
}
if ( V_175 & V_190 ) {
F_4 ( L_37 ) ;
V_10 -> V_61 = V_40 + V_191 ;
F_5 ( V_163 , & V_10 -> V_61 -> V_162 ) ;
}
return 0 ;
V_183:
F_53 ( V_40 ) ;
return V_178 ;
}
