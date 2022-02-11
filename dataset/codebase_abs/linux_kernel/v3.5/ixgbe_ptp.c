static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_7 = 0 ;
V_7 |= ( T_2 ) F_3 ( V_6 , V_8 ) ;
V_7 |= ( T_2 ) F_3 ( V_6 , V_9 ) << 32 ;
return V_7 ;
}
static int F_4 ( struct V_10 * V_11 , T_3 V_12 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_14 ;
T_4 V_15 , V_16 ;
int V_17 = 0 ;
if ( V_12 < 0 ) {
V_17 = 1 ;
V_12 = - V_12 ;
}
F_5 () ;
V_16 = F_6 ( V_4 -> V_18 ) ;
V_14 = V_16 ;
V_14 *= V_12 ;
V_15 = F_7 ( V_14 , 1000000000ULL ) ;
V_16 = V_17 ? ( V_16 - V_15 ) : ( V_16 + V_15 ) ;
switch ( V_6 -> V_19 . type ) {
case V_20 :
F_8 ( V_6 , V_21 , V_16 ) ;
break;
case V_22 :
F_8 ( V_6 , V_21 ,
( 1 << V_23 ) |
V_16 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_9 ( struct V_10 * V_11 , T_5 V_24 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
unsigned long V_25 ;
T_2 V_26 ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_26 = F_11 ( & V_4 -> V_28 ) ;
V_26 += V_24 ;
F_12 ( & V_4 -> V_28 ,
& V_4 -> V_2 ,
V_26 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
return 0 ;
}
static int F_14 ( struct V_10 * V_11 , struct V_29 * V_30 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
T_2 V_31 ;
T_4 V_32 ;
unsigned long V_25 ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_31 = F_11 ( & V_4 -> V_28 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
V_30 -> V_33 = F_15 ( V_31 , 1000000000ULL , & V_32 ) ;
V_30 -> V_34 = V_32 ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 ,
const struct V_29 * V_30 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
T_2 V_31 ;
unsigned long V_25 ;
V_31 = V_30 -> V_33 * 1000000000ULL ;
V_31 += V_30 -> V_34 ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
F_12 ( & V_4 -> V_28 , & V_4 -> V_2 , V_31 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 ,
struct V_35 * V_36 , int V_37 )
{
struct V_3 * V_4 =
F_2 ( V_11 , struct V_3 , V_13 ) ;
if ( V_36 -> type == V_38 ) {
switch ( V_4 -> V_6 . V_19 . type ) {
case V_20 :
if ( V_37 )
V_4 -> V_39 |= V_40 ;
else
V_4 -> V_39 &=
~ V_40 ;
return 0 ;
default:
break;
}
}
return - V_41 ;
}
void F_18 ( struct V_3 * V_4 , T_4 V_42 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_43 V_44 ;
V_44 . type = V_45 ;
if ( ! V_4 -> V_46 ||
! ( V_4 -> V_39 & V_40 ) )
return;
switch ( V_6 -> V_19 . type ) {
case V_20 :
if ( V_42 & V_47 )
V_43 ( V_4 -> V_46 , & V_44 ) ;
break;
default:
break;
}
}
static void F_19 ( struct V_5 * V_6 , int V_48 )
{
T_4 V_49 , V_50 , V_51 , V_52 , V_53 , V_54 ;
T_2 V_55 = 0 ;
T_4 V_56 ;
switch ( V_6 -> V_19 . type ) {
case V_20 :
V_49 = F_3 ( V_6 , V_57 ) ;
V_49 |= ( V_58 |
V_59 ) ;
V_50 = ( V_60 |
V_61 |
V_62 ) ;
V_51 = ( T_4 ) ( V_63 << V_48 ) ;
V_52 = ( T_4 ) ( ( V_63 << V_48 ) >> 32 ) ;
V_55 |= ( T_2 ) F_3 ( V_6 , V_8 ) ;
V_55 |= ( T_2 ) F_3 ( V_6 , V_9 ) << 32 ;
V_55 >>= V_48 ;
F_15 ( V_55 , V_63 , & V_56 ) ;
V_55 += ( V_63 - V_56 ) ;
V_55 <<= V_48 ;
V_53 = ( T_4 ) V_55 ;
V_54 = ( T_4 ) ( V_55 >> 32 ) ;
F_8 ( V_6 , V_64 , V_51 ) ;
F_8 ( V_6 , V_65 , V_52 ) ;
F_8 ( V_6 , V_66 , V_53 ) ;
F_8 ( V_6 , V_67 , V_54 ) ;
F_8 ( V_6 , V_57 , V_49 ) ;
F_8 ( V_6 , V_68 , V_50 ) ;
F_8 ( V_6 , V_69 , V_47 ) ;
break;
default:
break;
}
}
static void F_20 ( struct V_5 * V_6 )
{
F_8 ( V_6 , V_70 , V_47 ) ;
F_8 ( V_6 , V_68 , 0 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
unsigned long V_71 = V_4 -> V_72 - V_73 ;
struct V_29 V_30 ;
if ( ( V_4 -> V_39 & V_74 ) &&
( V_71 >= V_75 ) ) {
F_14 ( & V_4 -> V_13 , & V_30 ) ;
V_4 -> V_72 = V_73 ;
}
}
void F_22 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_80 V_81 ;
T_2 V_82 = 0 , V_31 ;
T_4 V_83 ;
unsigned long V_25 ;
if ( ! V_77 || ! V_77 -> V_4 )
return;
V_4 = V_77 -> V_4 ;
V_6 = & V_4 -> V_6 ;
V_83 = F_3 ( V_6 , V_84 ) ;
V_82 |= ( T_2 ) F_3 ( V_6 , V_85 ) ;
V_82 |= ( T_2 ) F_3 ( V_6 , V_86 ) << 32 ;
if ( ! ( V_83 & V_87 ) )
return;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_31 = F_23 ( & V_4 -> V_28 , V_82 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_88 = F_24 ( V_31 ) ;
F_25 ( V_79 , & V_81 ) ;
}
void F_26 ( struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_80 * V_81 ;
T_2 V_82 = 0 , V_31 ;
T_4 V_89 ;
unsigned long V_25 ;
if ( ! V_77 || ! V_77 -> V_4 )
return;
V_4 = V_77 -> V_4 ;
V_6 = & V_4 -> V_6 ;
V_89 = F_3 ( V_6 , V_90 ) ;
V_82 |= ( T_2 ) F_3 ( V_6 , V_91 ) ;
V_82 |= ( T_2 ) F_3 ( V_6 , V_92 ) << 32 ;
if ( ! ( V_89 & V_93 ) )
return;
F_10 ( & V_4 -> V_27 , V_25 ) ;
V_31 = F_23 ( & V_4 -> V_28 , V_82 ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
V_81 = F_27 ( V_79 ) ;
V_81 -> V_88 = F_24 ( V_31 ) ;
}
int F_28 ( struct V_3 * V_4 ,
struct V_94 * V_95 , int V_96 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_97 V_98 ;
T_4 V_99 = V_100 ;
T_4 V_101 = V_102 ;
T_4 V_103 = 0 ;
bool V_104 = false ;
bool V_105 = false ;
T_4 V_82 ;
if ( F_29 ( & V_98 , V_95 -> V_106 , sizeof( V_98 ) ) )
return - V_107 ;
if ( V_98 . V_25 )
return - V_108 ;
switch ( V_98 . V_109 ) {
case V_110 :
V_99 = 0 ;
case V_111 :
break;
default:
return - V_112 ;
}
switch ( V_98 . V_113 ) {
case V_114 :
V_101 = 0 ;
break;
case V_115 :
V_101 |= V_116 ;
V_103 = V_117 ;
V_104 = true ;
break;
case V_118 :
V_101 |= V_116 ;
V_103 = V_119 ;
V_104 = true ;
break;
case V_120 :
case V_121 :
case V_122 :
V_101 |= V_123 ;
V_103 = V_124 ;
V_105 = true ;
V_104 = true ;
V_98 . V_113 = V_125 ;
break;
case V_126 :
case V_127 :
case V_128 :
V_101 |= V_123 ;
V_103 = V_129 ;
V_105 = true ;
V_104 = true ;
V_98 . V_113 = V_125 ;
break;
case V_130 :
case V_131 :
case V_132 :
V_101 |= V_133 ;
V_98 . V_113 = V_132 ;
V_105 = true ;
V_104 = true ;
break;
case V_134 :
case V_135 :
default:
return - V_112 ;
}
if ( V_6 -> V_19 . type == V_136 ) {
if ( V_101 | V_99 )
return - V_112 ;
return 0 ;
}
if ( V_105 )
F_8 ( V_6 , F_30 ( 3 ) ,
( V_137 |
V_138 |
V_139 ) ) ;
else
F_8 ( V_6 , F_30 ( 3 ) , 0 ) ;
#define F_31 319
if ( V_104 ) {
T_4 V_140 = ( V_141
| V_142
| V_143 ) ;
V_140 |= ( ( V_144
& V_145
& V_146 )
<< V_147 ) ;
F_8 ( V_6 , F_32 ( 3 ) ,
( 3 << V_148 |
V_149 ) ) ;
F_8 ( V_6 , F_33 ( 3 ) ,
( F_34 ( F_31 ) |
F_34 ( F_31 ) << 16 ) ) ;
F_8 ( V_6 , F_35 ( 3 ) , V_140 ) ;
V_103 |= F_31 << 16 ;
} else {
F_8 ( V_6 , F_35 ( 3 ) , 0 ) ;
}
V_82 = F_3 ( V_6 , V_84 ) ;
V_82 &= ~ V_100 ;
V_82 |= V_99 ;
F_8 ( V_6 , V_84 , V_82 ) ;
V_82 = F_3 ( V_6 , V_90 ) ;
V_82 &= ~ ( V_102 | V_150 ) ;
V_82 |= V_101 ;
F_8 ( V_6 , V_90 , V_82 ) ;
F_8 ( V_6 , V_151 , V_103 ) ;
F_36 ( V_6 ) ;
V_82 = F_3 ( V_6 , V_86 ) ;
V_82 = F_3 ( V_6 , V_92 ) ;
return F_37 ( V_95 -> V_106 , & V_98 , sizeof( V_98 ) ) ?
- V_107 : 0 ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
T_4 V_16 = 0 ;
T_4 V_152 = 0 ;
T_4 V_48 = 0 ;
T_4 V_153 ;
unsigned long V_25 ;
switch ( V_4 -> V_154 ) {
case V_155 :
case V_156 :
case V_157 :
V_153 = V_4 -> V_154 ;
break;
default:
V_153 = V_157 ;
break;
}
V_152 = F_3 ( V_6 , V_21 ) ;
if ( V_4 -> V_153 == V_153 && V_152 )
return;
F_20 ( V_6 ) ;
switch ( V_153 ) {
case V_155 :
V_16 = V_158 ;
V_48 = V_159 ;
break;
case V_156 :
V_16 = V_160 ;
V_48 = V_161 ;
break;
case V_157 :
V_16 = V_162 ;
V_48 = V_163 ;
break;
}
switch ( V_6 -> V_19 . type ) {
case V_20 :
F_8 ( V_6 , V_21 , V_16 ) ;
break;
case V_22 :
V_16 >>= V_164 ;
V_48 -= V_164 ;
F_8 ( V_6 , V_21 ,
( 1 << V_23 ) |
V_16 ) ;
break;
default:
return;
}
F_8 ( V_6 , V_8 , 0x00000000 ) ;
F_8 ( V_6 , V_9 , 0x00000000 ) ;
F_36 ( V_6 ) ;
F_19 ( V_6 , V_48 ) ;
V_4 -> V_153 = V_153 ;
F_6 ( V_4 -> V_18 ) = V_16 ;
F_5 () ;
F_10 ( & V_4 -> V_27 , V_25 ) ;
memset ( & V_4 -> V_2 , 0 , sizeof( V_4 -> V_2 ) ) ;
V_4 -> V_2 . V_165 = F_1 ;
V_4 -> V_2 . V_166 = F_39 ( 64 ) ;
V_4 -> V_2 . V_48 = V_48 ;
V_4 -> V_2 . V_167 = 1 ;
F_12 ( & V_4 -> V_28 , & V_4 -> V_2 ,
F_40 ( F_41 () ) ) ;
F_13 ( & V_4 -> V_27 , V_25 ) ;
}
void F_42 ( struct V_3 * V_4 )
{
struct V_168 * V_169 = V_4 -> V_169 ;
switch ( V_4 -> V_6 . V_19 . type ) {
case V_20 :
snprintf ( V_4 -> V_13 . V_170 , 16 , L_1 , V_169 -> V_171 ) ;
V_4 -> V_13 . V_172 = V_173 ;
V_4 -> V_13 . V_174 = 250000000 ;
V_4 -> V_13 . V_175 = 0 ;
V_4 -> V_13 . V_176 = 0 ;
V_4 -> V_13 . V_177 = 0 ;
V_4 -> V_13 . V_178 = 1 ;
V_4 -> V_13 . V_179 = F_4 ;
V_4 -> V_13 . V_180 = F_9 ;
V_4 -> V_13 . V_181 = F_14 ;
V_4 -> V_13 . V_182 = F_16 ;
V_4 -> V_13 . V_183 = F_17 ;
break;
case V_22 :
snprintf ( V_4 -> V_13 . V_170 , 16 , L_1 , V_169 -> V_171 ) ;
V_4 -> V_13 . V_172 = V_173 ;
V_4 -> V_13 . V_174 = 250000000 ;
V_4 -> V_13 . V_175 = 0 ;
V_4 -> V_13 . V_176 = 0 ;
V_4 -> V_13 . V_177 = 0 ;
V_4 -> V_13 . V_178 = 0 ;
V_4 -> V_13 . V_179 = F_4 ;
V_4 -> V_13 . V_180 = F_9 ;
V_4 -> V_13 . V_181 = F_14 ;
V_4 -> V_13 . V_182 = F_16 ;
V_4 -> V_13 . V_183 = F_17 ;
break;
default:
V_4 -> V_46 = NULL ;
return;
}
F_43 ( & V_4 -> V_27 ) ;
F_38 ( V_4 ) ;
V_4 -> V_39 |= V_74 ;
V_4 -> V_46 = F_44 ( & V_4 -> V_13 ) ;
if ( F_45 ( V_4 -> V_46 ) ) {
V_4 -> V_46 = NULL ;
F_46 ( L_2 ) ;
} else
F_47 ( L_3 , V_169 -> V_170 ) ;
return;
}
void F_48 ( struct V_3 * V_4 )
{
F_20 ( & V_4 -> V_6 ) ;
V_4 -> V_39 &= ~ V_74 ;
if ( V_4 -> V_46 ) {
F_49 ( V_4 -> V_46 ) ;
V_4 -> V_46 = NULL ;
F_47 ( L_4 ,
V_4 -> V_169 -> V_170 ) ;
}
}
