static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
T_1 V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ;
T_2 V_14 = 0 , V_15 = 0 ;
if ( ( V_2 -> V_16 & V_17 ) &&
( V_4 -> V_18 . type == V_19 ) ) {
F_2 ( V_4 , V_20 , 0x0 ) ;
F_3 ( V_4 ) ;
V_7 = F_4 ( V_4 , V_21 ) ;
V_7 |= ( V_22 |
V_23 ) ;
V_8 = ( V_24 |
V_25 |
V_26 ) ;
V_9 = ( T_1 ) ( V_27 << V_5 ) ;
V_10 = ( T_1 ) ( ( V_27 << V_5 ) >> 32 ) ;
V_15 |= ( T_2 ) F_4 ( V_4 , V_28 ) ;
V_15 |= ( T_2 ) F_4 ( V_4 , V_29 ) << 32 ;
V_14 = F_5 ( & V_2 -> V_30 , V_15 ) ;
F_6 ( V_14 , V_27 , & V_13 ) ;
V_15 += ( ( V_27 - ( T_2 ) V_13 ) << V_5 ) ;
V_11 = ( T_1 ) V_15 ;
V_12 = ( T_1 ) ( V_15 >> 32 ) ;
F_2 ( V_4 , V_31 , V_9 ) ;
F_2 ( V_4 , V_32 , V_10 ) ;
F_2 ( V_4 , V_33 , V_11 ) ;
F_2 ( V_4 , V_34 , V_12 ) ;
F_2 ( V_4 , V_21 , V_7 ) ;
F_2 ( V_4 , V_20 , V_8 ) ;
} else {
F_2 ( V_4 , V_20 , 0x0 ) ;
}
F_3 ( V_4 ) ;
}
static T_3 F_7 ( const struct V_35 * V_6 )
{
struct V_1 * V_2 =
F_8 ( V_6 , struct V_1 , V_6 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_36 = 0 ;
V_36 |= ( T_2 ) F_4 ( V_4 , V_28 ) ;
V_36 |= ( T_2 ) F_4 ( V_4 , V_29 ) << 32 ;
return V_36 ;
}
static int F_9 ( struct V_37 * V_38 , T_4 V_39 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_41 ;
T_1 V_42 , V_43 ;
int V_44 = 0 ;
if ( V_39 < 0 ) {
V_44 = 1 ;
V_39 = - V_39 ;
}
F_10 () ;
V_43 = F_11 ( V_2 -> V_45 ) ;
V_41 = V_43 ;
V_41 *= V_39 ;
V_42 = F_12 ( V_41 , 1000000000ULL ) ;
V_43 = V_44 ? ( V_43 - V_42 ) : ( V_43 + V_42 ) ;
switch ( V_4 -> V_18 . type ) {
case V_19 :
F_2 ( V_4 , V_46 , V_43 ) ;
break;
case V_47 :
F_2 ( V_4 , V_46 ,
( 1 << V_48 ) |
V_43 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_13 ( struct V_37 * V_38 , T_5 V_49 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
unsigned long V_50 ;
T_2 V_51 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_51 = F_15 ( & V_2 -> V_30 ) ;
V_51 += V_49 ;
F_16 ( & V_2 -> V_30 ,
& V_2 -> V_6 ,
V_51 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 , struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
T_2 V_14 ;
T_1 V_55 ;
unsigned long V_50 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_15 ( & V_2 -> V_30 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
V_54 -> V_56 = F_6 ( V_14 , 1000000000ULL , & V_55 ) ;
V_54 -> V_57 = V_55 ;
return 0 ;
}
static int F_19 ( struct V_37 * V_38 ,
const struct V_53 * V_54 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
T_2 V_14 ;
unsigned long V_50 ;
V_14 = V_54 -> V_56 * 1000000000ULL ;
V_14 += V_54 -> V_57 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
F_16 ( & V_2 -> V_30 , & V_2 -> V_6 , V_14 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_37 * V_38 ,
struct V_58 * V_59 , int V_60 )
{
struct V_1 * V_2 =
F_8 ( V_38 , struct V_1 , V_40 ) ;
if ( V_59 -> type == V_61 ) {
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
if ( V_60 )
V_2 -> V_16 |= V_17 ;
else
V_2 -> V_16 &= ~ V_17 ;
F_1 ( V_2 ) ;
return 0 ;
default:
break;
}
}
return - V_62 ;
}
void F_21 ( struct V_1 * V_2 , T_1 V_63 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_64 V_65 ;
V_65 . type = V_66 ;
if ( ! V_2 -> V_67 )
return;
switch ( V_4 -> V_18 . type ) {
case V_19 :
V_64 ( V_2 -> V_67 , & V_65 ) ;
break;
default:
break;
}
}
void F_22 ( struct V_1 * V_2 )
{
bool V_68 = F_23 ( V_2 -> V_69 +
V_70 ) ;
struct V_53 V_54 ;
if ( V_68 ) {
F_18 ( & V_2 -> V_40 , & V_54 ) ;
V_2 -> V_69 = V_71 ;
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_72 * V_73 ;
T_1 V_74 = F_4 ( V_4 , V_75 ) ;
unsigned long V_76 ;
int V_77 ;
if ( ! ( V_74 & V_78 ) ) {
V_2 -> V_79 = V_71 ;
return;
}
V_76 = V_2 -> V_79 ;
for ( V_77 = 0 ; V_77 < V_2 -> V_80 ; V_77 ++ ) {
V_73 = V_2 -> V_73 [ V_77 ] ;
if ( F_25 ( V_73 -> V_81 , V_76 ) )
V_76 = V_73 -> V_81 ;
}
if ( F_23 ( V_76 + 5 * V_82 ) ) {
F_4 ( V_4 , V_83 ) ;
V_2 -> V_79 = V_71 ;
F_26 ( V_84 , L_1 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_85 V_86 ;
T_2 V_87 = 0 , V_14 ;
unsigned long V_50 ;
V_87 |= ( T_2 ) F_4 ( V_4 , V_88 ) ;
V_87 |= ( T_2 ) F_4 ( V_4 , V_89 ) << 32 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_87 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_90 = F_28 ( V_14 ) ;
F_29 ( V_2 -> V_91 , & V_86 ) ;
F_30 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
}
static void F_31 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_8 ( V_93 , struct V_1 ,
V_94 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
bool V_68 = F_23 ( V_2 -> V_95 +
V_96 ) ;
T_1 V_97 ;
if ( ! V_2 -> V_91 )
return;
if ( V_68 ) {
F_30 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
F_26 ( V_84 , L_2 ) ;
return;
}
V_97 = F_4 ( V_4 , V_98 ) ;
if ( V_97 & V_99 )
F_27 ( V_2 ) ;
else
F_32 ( & V_2 -> V_94 ) ;
}
void F_33 ( struct V_100 * V_101 ,
struct V_102 * V_103 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_85 * V_86 ;
T_2 V_87 = 0 , V_14 ;
T_1 V_74 ;
unsigned long V_50 ;
if ( ! V_101 || ! V_101 -> V_2 )
return;
V_2 = V_101 -> V_2 ;
V_4 = & V_2 -> V_4 ;
V_74 = F_4 ( V_4 , V_75 ) ;
if ( ! ( V_74 & V_78 ) )
return;
V_87 |= ( T_2 ) F_4 ( V_4 , V_104 ) ;
V_87 |= ( T_2 ) F_4 ( V_4 , V_83 ) << 32 ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
V_14 = F_5 ( & V_2 -> V_30 , V_87 ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
V_86 = F_34 ( V_103 ) ;
V_86 -> V_90 = F_28 ( V_14 ) ;
}
int F_35 ( struct V_1 * V_2 ,
struct V_105 * V_106 , int V_107 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_108 V_109 ;
T_1 V_110 = V_111 ;
T_1 V_112 = V_113 ;
T_1 V_114 = V_115 << 16 ;
bool V_116 = false ;
T_1 V_87 ;
if ( F_36 ( & V_109 , V_106 -> V_117 , sizeof( V_109 ) ) )
return - V_118 ;
if ( V_109 . V_50 )
return - V_119 ;
switch ( V_109 . V_120 ) {
case V_121 :
V_110 = 0 ;
case V_122 :
break;
default:
return - V_123 ;
}
switch ( V_109 . V_124 ) {
case V_125 :
V_112 = 0 ;
V_114 = 0 ;
break;
case V_126 :
V_112 |= V_127 ;
V_114 |= V_128 ;
break;
case V_129 :
V_112 |= V_127 ;
V_114 |= V_130 ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_112 |= V_140 ;
V_116 = true ;
V_109 . V_124 = V_131 ;
break;
case V_141 :
case V_142 :
default:
V_109 . V_124 = V_125 ;
return - V_123 ;
}
if ( V_4 -> V_18 . type == V_143 ) {
if ( V_112 | V_110 )
return - V_123 ;
return 0 ;
}
if ( V_116 )
F_2 ( V_4 , F_37 ( V_144 ) ,
( V_145 |
V_146 |
V_147 ) ) ;
else
F_2 ( V_4 , F_37 ( V_144 ) , 0 ) ;
V_87 = F_4 ( V_4 , V_98 ) ;
V_87 &= ~ V_111 ;
V_87 |= V_110 ;
F_2 ( V_4 , V_98 , V_87 ) ;
V_87 = F_4 ( V_4 , V_75 ) ;
V_87 &= ~ ( V_113 | V_148 ) ;
V_87 |= V_112 ;
F_2 ( V_4 , V_75 , V_87 ) ;
F_2 ( V_4 , V_149 , V_114 ) ;
F_3 ( V_4 ) ;
V_87 = F_4 ( V_4 , V_89 ) ;
V_87 = F_4 ( V_4 , V_83 ) ;
return F_38 ( V_106 -> V_117 , & V_109 , sizeof( V_109 ) ) ?
- V_118 : 0 ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_43 = 0 ;
T_1 V_5 = 0 ;
unsigned long V_50 ;
switch ( V_2 -> V_150 ) {
case V_151 :
V_43 = V_152 ;
V_5 = V_153 ;
break;
case V_154 :
V_43 = V_155 ;
V_5 = V_156 ;
break;
case V_157 :
default:
V_43 = V_158 ;
V_5 = V_159 ;
break;
}
switch ( V_4 -> V_18 . type ) {
case V_19 :
F_2 ( V_4 , V_46 , V_43 ) ;
break;
case V_47 :
V_43 >>= V_160 ;
V_5 -= V_160 ;
F_2 ( V_4 , V_46 ,
( 1 << V_48 ) |
V_43 ) ;
break;
default:
return;
}
F_11 ( V_2 -> V_45 ) = V_43 ;
F_10 () ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
memset ( & V_2 -> V_6 , 0 , sizeof( V_2 -> V_6 ) ) ;
V_2 -> V_6 . V_161 = F_7 ;
V_2 -> V_6 . V_162 = F_40 ( 64 ) ;
V_2 -> V_6 . V_5 = V_5 ;
V_2 -> V_6 . V_163 = 1 ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_50 ;
F_2 ( V_4 , V_28 , 0x00000000 ) ;
F_2 ( V_4 , V_29 , 0x00000000 ) ;
F_3 ( V_4 ) ;
F_39 ( V_2 ) ;
F_14 ( & V_2 -> V_52 , V_50 ) ;
F_16 ( & V_2 -> V_30 , & V_2 -> V_6 ,
F_42 ( F_43 () ) ) ;
F_17 ( & V_2 -> V_52 , V_50 ) ;
F_1 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_164 * V_165 = V_2 -> V_165 ;
switch ( V_2 -> V_4 . V_18 . type ) {
case V_19 :
snprintf ( V_2 -> V_40 . V_166 , 16 , L_3 , V_165 -> V_166 ) ;
V_2 -> V_40 . V_167 = V_168 ;
V_2 -> V_40 . V_169 = 250000000 ;
V_2 -> V_40 . V_170 = 0 ;
V_2 -> V_40 . V_171 = 0 ;
V_2 -> V_40 . V_172 = 0 ;
V_2 -> V_40 . V_173 = 1 ;
V_2 -> V_40 . V_174 = F_9 ;
V_2 -> V_40 . V_175 = F_13 ;
V_2 -> V_40 . V_176 = F_18 ;
V_2 -> V_40 . V_177 = F_19 ;
V_2 -> V_40 . V_178 = F_20 ;
break;
case V_47 :
snprintf ( V_2 -> V_40 . V_166 , 16 , L_3 , V_165 -> V_166 ) ;
V_2 -> V_40 . V_167 = V_168 ;
V_2 -> V_40 . V_169 = 250000000 ;
V_2 -> V_40 . V_170 = 0 ;
V_2 -> V_40 . V_171 = 0 ;
V_2 -> V_40 . V_172 = 0 ;
V_2 -> V_40 . V_173 = 0 ;
V_2 -> V_40 . V_174 = F_9 ;
V_2 -> V_40 . V_175 = F_13 ;
V_2 -> V_40 . V_176 = F_18 ;
V_2 -> V_40 . V_177 = F_19 ;
V_2 -> V_40 . V_178 = F_20 ;
break;
default:
V_2 -> V_67 = NULL ;
return;
}
F_45 ( & V_2 -> V_52 ) ;
F_46 ( & V_2 -> V_94 , F_31 ) ;
V_2 -> V_67 = F_47 ( & V_2 -> V_40 ,
& V_2 -> V_179 -> V_180 ) ;
if ( F_48 ( V_2 -> V_67 ) ) {
V_2 -> V_67 = NULL ;
F_49 ( L_4 ) ;
} else
F_50 ( L_5 , V_165 -> V_166 ) ;
F_41 ( V_2 ) ;
V_2 -> V_16 |= V_181 ;
return;
}
void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_16 &= ~ ( V_181 |
V_17 ) ;
F_1 ( V_2 ) ;
F_52 ( & V_2 -> V_94 ) ;
if ( V_2 -> V_91 ) {
F_30 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
}
if ( V_2 -> V_67 ) {
F_53 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
F_50 ( L_6 ,
V_2 -> V_165 -> V_166 ) ;
}
}
