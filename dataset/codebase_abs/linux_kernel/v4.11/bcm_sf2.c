static enum V_1 F_1 ( struct V_2 * V_3 )
{
return V_4 ;
}
static void F_2 ( struct V_2 * V_3 , int V_5 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_8 ;
T_1 V_9 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_10 . V_11 ; V_8 ++ ) {
if ( ! ( ( 1 << V_8 ) & V_3 -> V_12 ) )
continue;
V_9 = F_4 ( V_7 , F_5 ( V_8 ) ) ;
V_9 |= ( 1 << V_5 ) ;
F_6 ( V_7 , V_9 , F_5 ( V_8 ) ) ;
}
}
static void F_7 ( struct V_6 * V_7 , int V_13 )
{
T_1 V_9 , V_14 ;
switch ( V_13 ) {
case 8 :
V_14 = V_15 ;
break;
case 7 :
V_14 = V_16 ;
break;
case 5 :
V_14 = V_17 ;
break;
default:
V_14 = 0 ;
break;
}
V_9 = F_4 ( V_7 , V_18 ) ;
V_9 |= V_14 ;
F_6 ( V_7 , V_9 , V_18 ) ;
V_9 = F_4 ( V_7 , V_19 ) ;
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_19 ) ;
V_9 = F_4 ( V_7 , V_20 ) ;
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_20 ) ;
}
static void F_8 ( struct V_2 * V_3 , int V_13 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 , V_21 ;
if ( V_7 -> type == V_22 )
V_21 = V_23 ;
else
V_21 = V_24 ;
V_9 = F_4 ( V_7 , V_25 ) ;
V_9 &= ~ F_9 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_25 ) ;
V_9 = F_4 ( V_7 , V_26 ) ;
V_9 |= ( V_27 | V_28 | V_29 ) ;
V_9 &= ~ ( V_30 | V_31 ) ;
F_6 ( V_7 , V_9 , V_26 ) ;
F_6 ( V_7 , V_32 , V_33 ) ;
V_9 = F_4 ( V_7 , V_34 ) ;
V_9 |= V_35 ;
F_6 ( V_7 , V_9 , V_34 ) ;
F_7 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , V_21 ) ;
V_9 |= ( V_36 | V_37 ) ;
F_6 ( V_7 , V_9 , V_21 ) ;
}
static void F_10 ( struct V_2 * V_3 , int V_13 , bool V_38 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_39 ) ;
if ( V_38 )
V_9 |= 1 << V_13 ;
else
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_39 ) ;
}
static void F_11 ( struct V_2 * V_3 , bool V_38 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_12 ( V_7 , V_40 ) ;
if ( V_38 ) {
V_9 |= V_41 ;
V_9 &= ~ ( V_42 | V_43 | V_44 ) ;
F_13 ( V_7 , V_9 , V_40 ) ;
F_14 ( 21 ) ;
V_9 = F_12 ( V_7 , V_40 ) ;
V_9 &= ~ V_41 ;
} else {
V_9 |= V_42 | V_43 | V_41 ;
F_13 ( V_7 , V_9 , V_40 ) ;
F_15 ( 1 ) ;
V_9 |= V_44 ;
}
F_13 ( V_7 , V_9 , V_40 ) ;
if ( ! V_38 ) {
V_9 = F_12 ( V_7 , F_16 ( 0 ) ) ;
V_9 |= V_45 ;
F_13 ( V_7 , V_9 , F_16 ( 0 ) ) ;
}
}
static inline void F_17 ( struct V_6 * V_7 ,
int V_13 )
{
unsigned int V_46 ;
switch ( V_13 ) {
case 7 :
V_46 = V_47 ;
break;
case 0 :
F_18 ( V_7 , F_19 ( V_48 ) ) ;
return;
default:
V_46 = F_20 ( V_13 ) ;
break;
}
F_21 ( V_7 , F_19 ( V_46 ) ) ;
}
static inline void F_22 ( struct V_6 * V_7 ,
int V_13 )
{
unsigned int V_46 ;
switch ( V_13 ) {
case 7 :
V_46 = V_47 ;
break;
case 0 :
F_23 ( V_7 , F_19 ( V_48 ) ) ;
F_24 ( V_7 , F_19 ( V_48 ) , V_49 ) ;
return;
default:
V_46 = F_20 ( V_13 ) ;
break;
}
F_25 ( V_7 , F_19 ( V_46 ) ) ;
F_26 ( V_7 , F_19 ( V_46 ) , V_49 ) ;
}
static int F_27 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_51 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_2 V_5 = V_3 -> V_52 [ V_3 -> V_53 ] . V_5 ;
unsigned int V_8 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_25 ) ;
V_9 &= ~ F_9 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_25 ) ;
if ( V_7 -> V_54 & F_28 ( V_13 ) )
F_7 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , F_29 ( V_13 ) ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
V_9 |= V_8 << ( V_55 * V_8 ) ;
F_6 ( V_7 , V_9 , F_29 ( V_13 ) ) ;
F_6 ( V_7 , 0 , F_30 ( V_13 ) ) ;
if ( V_7 -> V_56 & 1 << V_13 && V_7 -> V_10 . V_57 == 1 ) {
F_11 ( V_3 , true ) ;
if ( V_51 ) {
V_51 -> V_58 = V_59 ;
F_31 ( V_51 ) ;
}
}
if ( V_13 == V_7 -> V_60 )
F_17 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , F_5 ( V_13 ) ) ;
V_9 &= ~ V_61 ;
V_9 |= ( 1 << V_13 ) ;
V_9 |= V_7 -> V_62 -> V_63 [ V_13 ] . V_64 ;
F_6 ( V_7 , V_9 , F_5 ( V_13 ) ) ;
F_2 ( V_3 , V_5 ) ;
if ( V_7 -> V_65 [ V_13 ] . V_66 . V_67 )
F_10 ( V_3 , V_13 , true ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_51 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_46 , V_9 ;
if ( V_7 -> V_68 & ( 1 << V_13 ) )
return;
if ( V_13 == V_7 -> V_60 )
F_22 ( V_7 , V_13 ) ;
if ( V_7 -> V_56 & 1 << V_13 && V_7 -> V_10 . V_57 == 1 )
F_11 ( V_3 , false ) ;
if ( F_33 ( V_3 , V_13 ) )
V_46 = V_26 ;
else
V_46 = F_30 ( V_13 ) ;
V_9 = F_4 ( V_7 , V_46 ) ;
V_9 |= V_30 | V_31 ;
F_6 ( V_7 , V_9 , V_46 ) ;
V_9 = F_4 ( V_7 , V_25 ) ;
V_9 |= F_9 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_25 ) ;
}
static int F_34 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_51 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_69 * V_70 = & V_7 -> V_65 [ V_13 ] . V_66 ;
int V_71 ;
V_70 -> V_72 = ( V_73 | V_74 ) ;
V_71 = F_35 ( V_51 , 0 ) ;
if ( V_71 )
return 0 ;
F_10 ( V_3 , V_13 , true ) ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 , int V_13 ,
struct V_69 * V_75 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_69 * V_70 = & V_7 -> V_65 [ V_13 ] . V_66 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_76 ) ;
V_75 -> V_67 = V_70 -> V_67 ;
V_75 -> V_77 = ! ! ( V_9 & ( 1 << V_13 ) ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_78 ,
struct V_69 * V_75 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_69 * V_70 = & V_7 -> V_65 [ V_13 ] . V_66 ;
V_70 -> V_67 = V_75 -> V_67 ;
if ( ! V_70 -> V_67 ) {
F_10 ( V_3 , V_13 , false ) ;
} else {
V_70 -> V_67 = F_34 ( V_3 , V_13 , V_78 ) ;
if ( ! V_70 -> V_67 )
return - V_79 ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , int V_80 , int V_81 ,
int V_82 , T_3 V_14 )
{
int V_71 = 0 ;
T_1 V_9 ;
V_9 = F_12 ( V_7 , V_83 ) ;
V_9 |= V_84 ;
F_13 ( V_7 , V_9 , V_83 ) ;
V_9 = 0x70 ;
V_9 <<= 2 ;
F_6 ( V_7 , V_81 , V_9 ) ;
V_9 = 0x80 << 8 | V_82 << 1 ;
V_9 <<= 2 ;
if ( V_80 )
V_71 = F_4 ( V_7 , V_9 ) ;
else
F_6 ( V_7 , V_14 , V_9 ) ;
V_9 = F_12 ( V_7 , V_83 ) ;
V_9 &= ~ V_84 ;
F_13 ( V_7 , V_9 , V_83 ) ;
return V_71 & 0xffff ;
}
static int F_39 ( struct V_85 * V_86 , int V_81 , int V_82 )
{
struct V_6 * V_7 = V_86 -> V_7 ;
if ( V_81 == V_87 && V_7 -> V_88 & F_28 ( V_81 ) )
return F_38 ( V_7 , 1 , V_81 , V_82 , 0 ) ;
else
return F_40 ( V_7 -> V_89 , V_81 , V_82 ) ;
}
static int F_41 ( struct V_85 * V_86 , int V_81 , int V_82 ,
T_3 V_14 )
{
struct V_6 * V_7 = V_86 -> V_7 ;
if ( V_81 == V_87 && V_7 -> V_88 & F_28 ( V_81 ) )
F_38 ( V_7 , 0 , V_81 , V_82 , V_14 ) ;
else
F_42 ( V_7 -> V_89 , V_81 , V_82 , V_14 ) ;
return 0 ;
}
static T_4 F_43 ( int V_90 , void * V_91 )
{
struct V_6 * V_7 = V_91 ;
V_7 -> V_92 = F_44 ( V_7 , V_93 ) &
~ V_7 -> V_94 ;
F_24 ( V_7 , V_7 -> V_92 , V_49 ) ;
return V_95 ;
}
static T_4 F_45 ( int V_90 , void * V_91 )
{
struct V_6 * V_7 = V_91 ;
V_7 -> V_96 = F_46 ( V_7 , V_93 ) &
~ V_7 -> V_97 ;
F_26 ( V_7 , V_7 -> V_96 , V_49 ) ;
if ( V_7 -> V_96 & F_47 ( V_47 ) )
V_7 -> V_65 [ 7 ] . V_98 = 1 ;
if ( V_7 -> V_96 & F_48 ( V_47 ) )
V_7 -> V_65 [ 7 ] . V_98 = 0 ;
return V_95 ;
}
static int F_49 ( struct V_6 * V_7 )
{
unsigned int V_99 = 1000 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_100 ) ;
V_9 |= V_101 | V_102 | V_103 ;
F_6 ( V_7 , V_9 , V_100 ) ;
do {
V_9 = F_4 ( V_7 , V_100 ) ;
if ( ! ( V_9 & V_101 ) )
break;
F_50 ( 1000 , 2000 ) ;
} while ( V_99 -- > 0 );
if ( V_99 == 0 )
return - V_104 ;
return 0 ;
}
static void F_51 ( struct V_6 * V_7 )
{
F_23 ( V_7 , 0xffffffff ) ;
F_24 ( V_7 , 0xffffffff , V_49 ) ;
F_25 ( V_7 , 0xffffffff ) ;
F_26 ( V_7 , 0xffffffff , V_49 ) ;
}
static void F_52 ( struct V_6 * V_7 ,
struct V_105 * V_106 )
{
struct V_105 * V_13 ;
const char * V_107 ;
int V_108 ;
unsigned int V_109 ;
int V_71 ;
V_7 -> V_60 = - 1 ;
F_53 (dn, port) {
if ( F_54 ( V_13 , L_1 , & V_109 ) )
continue;
V_108 = F_55 ( V_13 ) ;
if ( V_108 < 0 ) {
V_71 = F_56 ( V_13 , L_2 ,
& V_107 ) ;
if ( V_71 < 0 )
continue;
if ( ! strcasecmp ( V_107 , L_3 ) )
V_7 -> V_56 |= 1 << V_109 ;
}
if ( V_108 == V_110 )
V_7 -> V_60 = V_109 ;
if ( F_57 ( V_13 , L_4 ) )
V_7 -> V_54 |= 1 << V_109 ;
}
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_105 * V_106 ;
static int V_53 ;
int V_111 ;
V_106 = F_59 ( NULL , NULL , L_5 ) ;
V_7 -> V_89 = F_60 ( V_106 ) ;
if ( ! V_7 -> V_89 )
return - V_112 ;
F_61 ( & V_7 -> V_89 -> V_62 ) ;
V_7 -> V_113 = V_106 ;
V_7 -> V_114 = F_62 ( V_3 -> V_62 ) ;
if ( ! V_7 -> V_114 )
return - V_115 ;
V_7 -> V_114 -> V_7 = V_7 ;
V_7 -> V_114 -> V_116 = L_6 ;
V_7 -> V_114 -> V_117 = F_39 ;
V_7 -> V_114 -> V_118 = F_41 ;
snprintf ( V_7 -> V_114 -> V_119 , V_120 , L_7 ,
V_53 ++ ) ;
V_7 -> V_114 -> V_62 . V_121 = V_106 ;
if ( F_63 ( L_8 ) )
V_7 -> V_88 |= ( 1 << V_87 ) ;
else
V_7 -> V_88 = 0 ;
V_3 -> V_122 = V_7 -> V_88 ;
V_3 -> V_114 = V_7 -> V_114 ;
V_7 -> V_114 -> V_123 = V_3 -> V_62 -> V_123 ;
V_7 -> V_114 -> V_124 = ~ V_7 -> V_88 ;
if ( V_106 )
V_111 = F_64 ( V_7 -> V_114 , V_106 ) ;
else
V_111 = F_65 ( V_7 -> V_114 ) ;
if ( V_111 )
F_66 ( V_106 ) ;
return V_111 ;
}
static void F_67 ( struct V_6 * V_7 )
{
F_68 ( V_7 -> V_114 ) ;
if ( V_7 -> V_113 )
F_66 ( V_7 -> V_113 ) ;
}
static T_1 F_69 ( struct V_2 * V_3 , int V_13 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return V_7 -> V_10 . V_125 ;
}
static void F_70 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_78 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_69 * V_70 = & V_7 -> V_65 [ V_13 ] . V_66 ;
T_1 V_126 = 0 , V_127 ;
const char * V_128 = NULL ;
T_1 V_9 , V_21 ;
if ( V_7 -> type == V_22 )
V_21 = F_71 ( V_13 ) ;
else
V_21 = F_72 ( V_13 ) ;
switch ( V_78 -> V_129 ) {
case V_130 :
V_128 = L_9 ;
V_126 = 1 ;
case V_131 :
if ( ! V_128 )
V_128 = L_10 ;
V_127 = V_132 ;
break;
case V_133 :
V_128 = L_11 ;
V_127 = V_134 ;
break;
case V_135 :
V_128 = L_12 ;
V_127 = V_136 ;
break;
default:
goto V_137;
}
if ( ! V_78 -> V_98 ) {
V_9 = F_12 ( V_7 , F_73 ( V_13 ) ) ;
V_9 &= ~ V_138 ;
F_13 ( V_7 , V_9 , F_73 ( V_13 ) ) ;
goto V_137;
}
V_9 = F_12 ( V_7 , F_73 ( V_13 ) ) ;
V_9 &= ~ V_139 ;
V_9 &= ~ ( V_140 << V_141 ) ;
V_9 &= ~ ( V_142 | V_143 ) ;
V_9 |= V_127 | V_138 ;
if ( V_126 )
V_9 |= V_139 ;
if ( V_78 -> V_144 ) {
if ( V_78 -> V_145 )
V_9 |= V_143 ;
V_9 |= V_142 ;
}
F_13 ( V_7 , V_9 , F_73 ( V_13 ) ) ;
F_74 ( L_13 , V_13 , V_128 ) ;
V_137:
V_9 = V_146 ;
switch ( V_78 -> V_147 ) {
case V_148 :
V_9 |= V_149 << V_150 ;
break;
case V_151 :
V_9 |= V_152 << V_150 ;
break;
}
if ( V_78 -> V_98 )
V_9 |= V_37 ;
if ( V_78 -> V_153 == V_154 )
V_9 |= V_155 ;
F_6 ( V_7 , V_9 , V_21 ) ;
if ( ! V_78 -> V_156 )
V_70 -> V_67 = F_34 ( V_3 , V_13 , V_78 ) ;
}
static void F_75 ( struct V_2 * V_3 , int V_13 ,
struct V_157 * V_158 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_153 , V_144 , V_21 ;
T_1 V_9 ;
if ( V_7 -> type == V_22 )
V_21 = F_71 ( V_13 ) ;
else
V_21 = F_72 ( V_13 ) ;
V_153 = F_4 ( V_7 , V_159 ) ;
V_144 = F_4 ( V_7 , V_160 ) ;
V_158 -> V_98 = 0 ;
if ( V_13 == V_7 -> V_60 ) {
V_158 -> V_98 = V_7 -> V_65 [ V_13 ] . V_98 ;
if ( ! V_158 -> V_98 )
F_76 ( V_3 -> V_63 [ V_13 ] . V_161 ) ;
V_158 -> V_153 = 1 ;
} else {
V_158 -> V_98 = 1 ;
V_158 -> V_153 = ! ! ( V_153 & ( 1 << V_13 ) ) ;
}
V_9 = F_4 ( V_7 , V_21 ) ;
V_9 |= V_146 ;
if ( V_158 -> V_98 )
V_9 |= V_37 ;
else
V_9 &= ~ V_37 ;
F_6 ( V_7 , V_9 , V_21 ) ;
if ( ( V_144 & ( 1 << V_13 ) ) &&
( V_144 & ( 1 << ( V_13 + V_162 ) ) ) ) {
V_158 -> V_145 = 1 ;
V_158 -> V_144 = 1 ;
}
if ( V_144 & ( 1 << V_13 ) )
V_158 -> V_144 = 1 ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_51 ( V_7 ) ;
for ( V_13 = 0 ; V_13 < V_163 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 ||
F_33 ( V_3 , V_13 ) )
F_32 ( V_3 , V_13 , NULL ) ;
}
return 0 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
int V_71 ;
V_71 = F_49 ( V_7 ) ;
if ( V_71 ) {
F_79 ( L_14 , V_164 ) ;
return V_71 ;
}
if ( V_7 -> V_10 . V_57 == 1 )
F_11 ( V_3 , true ) ;
for ( V_13 = 0 ; V_13 < V_163 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 )
F_27 ( V_3 , V_13 , NULL ) ;
else if ( F_33 ( V_3 , V_13 ) )
F_8 ( V_3 , V_13 ) ;
}
return 0 ;
}
static void F_80 ( struct V_2 * V_3 , int V_13 ,
struct V_165 * V_166 )
{
struct V_167 * V_70 = V_3 -> V_52 [ V_3 -> V_53 ] . V_168 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_165 V_169 ;
V_70 -> V_170 -> V_171 ( V_70 , & V_169 ) ;
V_166 -> V_72 = V_169 . V_72 ;
memset ( & V_166 -> V_172 , 0 , sizeof( V_166 -> V_172 ) ) ;
if ( V_169 . V_173 & V_174 )
memcpy ( & V_166 -> V_172 , V_169 . V_172 , sizeof( V_166 -> V_172 ) ) ;
if ( V_7 -> V_68 & ( 1 << V_13 ) )
V_166 -> V_173 = V_169 . V_173 ;
else
V_166 -> V_173 = 0 ;
}
static int F_81 ( struct V_2 * V_3 , int V_13 ,
struct V_165 * V_166 )
{
struct V_167 * V_70 = V_3 -> V_52 [ V_3 -> V_53 ] . V_168 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_2 V_5 = V_3 -> V_52 [ V_3 -> V_53 ] . V_5 ;
struct V_165 V_169 ;
V_70 -> V_170 -> V_171 ( V_70 , & V_169 ) ;
if ( V_166 -> V_173 & ~ V_169 . V_72 )
return - V_175 ;
if ( V_166 -> V_173 )
V_7 -> V_68 |= ( 1 << V_13 ) ;
else
V_7 -> V_68 &= ~ ( 1 << V_13 ) ;
if ( V_7 -> V_68 && V_7 -> V_68 != ( 1 << V_5 ) )
V_7 -> V_68 |= ( 1 << V_5 ) ;
else
V_7 -> V_68 &= ~ ( 1 << V_5 ) ;
return V_70 -> V_170 -> V_176 ( V_70 , V_166 ) ;
}
static int F_82 ( struct V_6 * V_7 )
{
unsigned int V_99 = 10 ;
T_1 V_9 ;
do {
V_9 = F_4 ( V_7 , V_177 ) ;
if ( ! ( V_9 & V_178 ) )
return 0 ;
F_50 ( 1000 , 2000 ) ;
} while ( V_99 -- );
return - V_104 ;
}
static int F_83 ( struct V_6 * V_7 , T_5 V_80 )
{
F_6 ( V_7 , V_178 | V_80 , V_177 ) ;
return F_82 ( V_7 ) ;
}
static void F_84 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_83 ( V_7 , V_179 ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_10 . V_11 ; V_13 ++ ) {
if ( ! ( ( 1 << V_13 ) & V_3 -> V_12 ) )
continue;
F_6 ( V_7 , 1 , F_85 ( V_13 ) ) ;
}
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_10 . V_11 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 )
F_27 ( V_3 , V_13 , NULL ) ;
else if ( F_33 ( V_3 , V_13 ) )
F_8 ( V_3 , V_13 ) ;
else
F_32 ( V_3 , V_13 , NULL ) ;
}
F_84 ( V_3 ) ;
return 0 ;
}
static int F_87 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_5 * V_14 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
* V_14 = F_4 ( V_7 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_89 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_3 * V_14 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
* V_14 = F_4 ( V_7 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_90 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_1 * V_14 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
* V_14 = F_4 ( V_7 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_91 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_6 * V_14 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
* V_14 = F_92 ( V_7 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_93 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_5 V_182 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
F_6 ( V_7 , V_182 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_94 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_3 V_182 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
F_6 ( V_7 , V_182 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_95 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_1 V_182 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
F_6 ( V_7 , V_182 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_96 ( struct V_180 * V_62 , T_5 V_181 , T_5 V_9 ,
T_6 V_182 )
{
struct V_6 * V_7 = V_62 -> V_7 ;
F_97 ( V_7 , V_182 , F_88 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_98 ( struct V_183 * V_184 )
{
const char * V_185 [ V_186 ] = V_187 ;
struct V_105 * V_106 = V_184 -> V_62 . V_121 ;
const struct V_188 * V_189 = NULL ;
const struct V_190 * V_191 ;
struct V_192 * V_193 ;
struct V_194 * V_195 ;
struct V_6 * V_7 ;
struct V_180 * V_62 ;
struct V_2 * V_3 ;
void T_7 * * V_196 ;
struct V_197 * V_198 ;
unsigned int V_8 ;
T_1 V_9 , V_199 ;
int V_71 ;
V_7 = F_99 ( & V_184 -> V_62 , sizeof( * V_7 ) , V_200 ) ;
if ( ! V_7 )
return - V_115 ;
V_195 = F_99 ( & V_184 -> V_62 , sizeof( * V_195 ) , V_200 ) ;
if ( ! V_195 )
return - V_115 ;
V_62 = F_100 ( & V_184 -> V_62 , & V_201 , V_7 ) ;
if ( ! V_62 )
return - V_115 ;
V_193 = F_99 ( & V_184 -> V_62 , sizeof( * V_193 ) , V_200 ) ;
if ( ! V_193 )
return - V_115 ;
V_189 = F_101 ( V_202 , V_106 ) ;
if ( ! V_189 || ! V_189 -> V_191 )
return - V_175 ;
V_191 = V_189 -> V_191 ;
V_7 -> type = V_191 -> type ;
V_7 -> V_203 = V_191 -> V_203 ;
V_7 -> V_204 = V_191 -> V_204 ;
V_193 -> V_205 = V_7 -> type ;
V_62 -> V_193 = V_193 ;
V_7 -> V_62 = V_62 ;
V_3 = V_62 -> V_3 ;
V_3 -> V_195 = & V_206 ;
F_102 ( & V_184 -> V_62 , V_7 ) ;
F_103 ( & V_7 -> V_207 ) ;
F_104 ( & V_7 -> V_208 ) ;
F_104 ( & V_7 -> V_209 . V_210 ) ;
F_105 ( 0 , V_7 -> V_209 . V_211 ) ;
F_52 ( V_7 , V_106 -> V_212 ) ;
V_7 -> V_213 = F_106 ( V_106 , 0 ) ;
V_7 -> V_214 = F_106 ( V_106 , 1 ) ;
V_196 = & V_7 -> V_215 ;
for ( V_8 = 0 ; V_8 < V_186 ; V_8 ++ ) {
V_198 = F_107 ( V_184 , V_216 , V_8 ) ;
* V_196 = F_108 ( & V_184 -> V_62 , V_198 ) ;
if ( F_109 ( * V_196 ) ) {
F_79 ( L_15 , V_185 [ V_8 ] ) ;
return F_110 ( * V_196 ) ;
}
V_196 ++ ;
}
V_71 = F_49 ( V_7 ) ;
if ( V_71 ) {
F_79 ( L_16 , V_71 ) ;
return V_71 ;
}
V_71 = F_58 ( V_3 ) ;
if ( V_71 ) {
F_79 ( L_17 ) ;
return V_71 ;
}
V_71 = F_111 ( V_7 ) ;
if ( V_71 ) {
F_79 ( L_18 ) ;
goto V_217;
}
F_51 ( V_7 ) ;
V_71 = F_112 ( & V_184 -> V_62 , V_7 -> V_213 , F_43 , 0 ,
L_19 , V_7 ) ;
if ( V_71 < 0 ) {
F_79 ( L_20 ) ;
goto V_217;
}
V_71 = F_112 ( & V_184 -> V_62 , V_7 -> V_214 , F_45 , 0 ,
L_21 , V_7 ) ;
if ( V_71 < 0 ) {
F_79 ( L_22 ) ;
goto V_217;
}
V_9 = F_4 ( V_7 , V_218 ) ;
V_9 |= V_219 ;
F_6 ( V_7 , V_9 , V_218 ) ;
V_9 &= ~ V_219 ;
F_6 ( V_7 , V_9 , V_218 ) ;
V_7 -> V_10 . V_11 = F_4 ( V_7 , V_220 ) + 1 ;
if ( V_7 -> V_10 . V_11 > V_163 )
V_7 -> V_10 . V_11 = V_163 ;
if ( F_54 ( V_106 , L_23 ,
& V_7 -> V_10 . V_57 ) )
V_7 -> V_10 . V_57 = 1 ;
V_199 = F_12 ( V_7 , V_221 ) ;
V_7 -> V_10 . V_222 = ( V_199 >> V_223 ) &
V_224 ;
V_7 -> V_10 . V_225 = ( V_199 & V_226 ) ;
V_199 = F_12 ( V_7 , V_227 ) ;
V_7 -> V_10 . V_125 = V_199 & V_228 ;
V_71 = F_113 ( V_62 ) ;
if ( V_71 )
goto V_217;
F_74 ( L_24 ,
V_7 -> V_10 . V_222 >> 8 , V_7 -> V_10 . V_222 & 0xff ,
V_7 -> V_10 . V_225 >> 8 , V_7 -> V_10 . V_225 & 0xff ,
V_7 -> V_215 , V_7 -> V_213 , V_7 -> V_214 ) ;
return 0 ;
V_217:
F_67 ( V_7 ) ;
return V_71 ;
}
static int F_114 ( struct V_183 * V_184 )
{
struct V_6 * V_7 = F_115 ( V_184 ) ;
V_7 -> V_68 = 0 ;
F_77 ( V_7 -> V_62 -> V_3 ) ;
F_116 ( V_7 -> V_62 -> V_3 ) ;
F_67 ( V_7 ) ;
return 0 ;
}
static void F_117 ( struct V_183 * V_184 )
{
struct V_6 * V_7 = F_115 ( V_184 ) ;
if ( V_7 -> V_10 . V_57 == 1 )
F_11 ( V_7 -> V_62 -> V_3 , true ) ;
}
static int F_118 ( struct V_229 * V_62 )
{
struct V_183 * V_184 = F_119 ( V_62 ) ;
struct V_6 * V_7 = F_115 ( V_184 ) ;
return F_120 ( V_7 -> V_62 -> V_3 ) ;
}
static int F_121 ( struct V_229 * V_62 )
{
struct V_183 * V_184 = F_119 ( V_62 ) ;
struct V_6 * V_7 = F_115 ( V_184 ) ;
return F_122 ( V_7 -> V_62 -> V_3 ) ;
}
