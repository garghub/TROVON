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
static T_1 F_37 ( struct V_92 * V_10 , int V_54 )
{
T_1 V_123 ;
if ( V_54 < F_15 ( V_10 -> V_111 -> V_124 ) ) {
V_123 = F_2 ( & V_10 -> V_111 -> V_124 [ V_54 ] ) ;
} else {
V_54 -= F_15 ( V_10 -> V_111 -> V_124 ) ;
if ( F_38 ( V_54 >= F_15 ( V_10 -> V_111 -> V_125 ) ) )
return 0 ;
V_123 = F_2 ( & V_10 -> V_111 -> V_125 [ V_54 ] ) ;
}
return V_123 ;
}
static void F_39 ( struct V_92 * V_10 , int V_54 , T_1 V_108 )
{
if ( V_54 < F_15 ( V_10 -> V_111 -> V_124 ) ) {
F_5 ( V_108 , & V_10 -> V_111 -> V_124 [ V_54 ] ) ;
} else {
V_54 -= F_15 ( V_10 -> V_111 -> V_124 ) ;
if ( F_38 ( V_54 >= F_15 ( V_10 -> V_111 -> V_125 ) ) )
return;
F_5 ( V_108 , & V_10 -> V_111 -> V_125 [ V_54 ] ) ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
struct V_126 * V_127 ;
T_5 V_128 ;
struct V_129 * V_130 , * V_131 , * V_132 = NULL ;
unsigned long long V_133 ;
T_6 V_134 ;
T_1 V_135 , V_136 ;
int V_54 = 0 ;
V_128 = F_41 ( & V_2 -> V_29 -> V_2 ) ;
if ( ! V_128 || F_42 ( V_128 , & V_130 ) )
return;
if ( F_43 ( V_128 ) )
V_132 = V_130 ;
else {
F_20 (acpi_cdev, &acpi_dev->children, node) {
if ( F_43 ( V_131 -> V_128 ) ) {
V_132 = V_131 ;
break;
}
}
}
if ( ! V_132 ) {
F_44 ( L_26 ) ;
return;
}
V_136 = F_15 ( V_10 -> V_111 -> V_124 ) +
F_15 ( V_10 -> V_111 -> V_125 ) ;
F_20 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_54 >= V_136 ) {
F_18 ( L_27 ,
V_136 ) ;
return;
}
V_134 = F_45 ( V_131 -> V_128 , L_28 ,
NULL , & V_133 ) ;
if ( F_46 ( V_134 ) ) {
if ( ! V_133 )
goto V_137;
F_39 ( V_10 , V_54 ++ , ( T_1 ) ( V_133 & 0x0f0f ) ) ;
}
}
V_138:
F_18 ( L_29 , V_54 ) ;
if ( V_54 < V_136 )
F_39 ( V_10 , V_54 , 0 ) ;
return;
V_137:
V_54 = 0 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
int V_139 = V_140 ;
if ( V_54 >= V_136 ) {
F_18 ( L_30 ,
V_136 ) ;
return;
}
switch ( V_127 -> V_141 ) {
case V_142 :
case V_143 :
V_139 = V_144 ;
break;
case V_145 :
case V_146 :
case V_147 :
case V_148 :
V_139 = V_149 ;
break;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
V_139 = V_155 ;
break;
case V_156 :
V_139 = V_157 ;
break;
}
V_135 = F_37 ( V_10 , V_54 ) ;
F_39 ( V_10 , V_54 , V_135 | ( 1 << 31 ) | V_139 | V_54 ) ;
V_54 ++ ;
}
goto V_138;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
int V_54 = 0 ;
T_1 V_158 ;
do {
V_158 = F_37 ( V_10 , V_54 ) ;
F_5 ( V_158 , & V_10 -> V_111 -> V_159 [ V_54 ] ) ;
} while ( ++ V_54 < 8 && V_158 != 0 );
}
void F_48 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_160 )
return;
if ( V_10 -> V_111 ) {
F_40 ( V_2 ) ;
F_47 ( V_2 ) ;
F_5 ( 0 , & V_10 -> V_111 -> V_122 ) ;
F_5 ( 1 , & V_10 -> V_111 -> V_161 ) ;
V_119 = V_10 ;
F_49 ( & V_162 ) ;
}
if ( V_10 -> V_61 ) {
F_5 ( V_163 , & V_10 -> V_61 -> V_164 ) ;
F_5 ( V_165 , & V_10 -> V_61 -> V_166 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_160 )
return;
if ( V_10 -> V_61 )
F_5 ( V_167 , & V_10 -> V_61 -> V_166 ) ;
F_51 ( & V_7 -> V_10 . F_32 ) ;
if ( V_10 -> V_111 ) {
F_5 ( 0 , & V_10 -> V_111 -> V_161 ) ;
V_119 = NULL ;
F_52 ( & V_162 ) ;
}
F_53 ( V_10 -> V_160 ) ;
V_10 -> V_160 = NULL ;
V_10 -> V_111 = NULL ;
V_10 -> F_1 = NULL ;
V_10 -> V_61 = NULL ;
V_10 -> V_168 = NULL ;
V_10 -> V_169 = NULL ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
bool V_170 = false ;
T_1 V_171 ;
V_10 -> V_25 = 1 ;
V_10 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_172 , 0 , & V_171 ) == 0 ) {
V_171 <<= 1 ;
V_10 -> V_25 |= V_171 ;
}
if ( F_1 ( V_2 , V_173 , 0 , & V_171 ) == 0 ) {
V_10 -> V_22 |= V_171 ;
V_170 = true ;
}
if ( F_1 ( V_2 , V_174 , 0 , & V_171 ) == 0 ) {
T_1 V_175 = V_171 & 0x7ff ;
T_1 V_176 = V_171 & ~ 0xfff ;
V_171 = ( V_176 << 4 ) | ( V_175 << 1 ) | 1 ;
if ( V_170 ) {
T_1 V_177 = V_10 -> V_22 ;
if ( ( V_177 & V_171 ) != V_177 )
F_4 ( L_31 , V_177 , V_171 ) ;
} else {
V_10 -> V_22 |= V_171 ;
}
}
F_4 ( L_32 ,
V_10 -> V_25 ,
V_10 -> V_22 ) ;
}
static inline void F_54 ( struct V_1 * V_2 ) {}
int F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_92 * V_10 = & V_7 -> V_10 ;
void T_2 * V_40 ;
T_1 V_178 , V_179 ;
char V_180 [ sizeof( V_181 ) ] ;
int V_182 = 0 ;
F_56 ( sizeof( struct V_183 ) != 0x100 ) ;
F_56 ( sizeof( struct V_110 ) != 0x100 ) ;
F_56 ( sizeof( struct V_9 ) != 0x100 ) ;
F_56 ( sizeof( struct V_60 ) != 0x100 ) ;
F_57 ( V_2 -> V_29 , V_184 , & V_178 ) ;
F_4 ( L_33 , V_178 ) ;
if ( V_178 == 0 ) {
F_4 ( L_34 ) ;
return - V_185 ;
}
#ifdef F_58
F_59 ( & V_10 -> F_32 , F_32 ) ;
#endif
V_40 = F_60 ( V_178 , V_186 ) ;
if ( ! V_40 )
return - V_187 ;
F_61 ( V_180 , V_40 , sizeof( V_180 ) ) ;
if ( memcmp ( V_180 , V_181 , 16 ) ) {
F_4 ( L_35 ) ;
V_182 = - V_23 ;
goto V_188;
}
V_10 -> V_160 = V_40 ;
V_10 -> V_168 = V_40 + V_189 ;
V_10 -> V_169 = V_40 + V_190 ;
V_179 = F_2 ( & V_10 -> V_160 -> V_179 ) ;
if ( V_179 & V_191 ) {
F_4 ( L_36 ) ;
V_10 -> V_111 = V_40 + V_192 ;
}
if ( V_179 & V_193 ) {
F_4 ( L_37 ) ;
V_10 -> F_1 = V_40 + V_194 ;
F_54 ( V_2 ) ;
}
if ( V_179 & V_195 ) {
F_4 ( L_38 ) ;
V_10 -> V_61 = V_40 + V_196 ;
F_5 ( V_167 , & V_10 -> V_61 -> V_166 ) ;
}
return 0 ;
V_188:
F_53 ( V_40 ) ;
return V_182 ;
}
