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
static void F_7 ( struct V_2 * V_3 , int V_13 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 , V_14 ;
V_9 = F_4 ( V_7 , V_15 ) ;
V_9 &= ~ F_8 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_15 ) ;
V_9 = F_4 ( V_7 , V_16 ) ;
V_9 |= ( V_17 | V_18 | V_19 ) ;
V_9 &= ~ ( V_20 | V_21 ) ;
F_6 ( V_7 , V_9 , V_16 ) ;
F_6 ( V_7 , V_22 , V_23 ) ;
V_9 = F_4 ( V_7 , V_24 ) ;
V_9 |= V_25 ;
F_6 ( V_7 , V_9 , V_24 ) ;
switch ( V_13 ) {
case 8 :
V_14 = V_26 ;
break;
case 7 :
V_14 = V_27 ;
break;
case 5 :
V_14 = V_28 ;
break;
default:
V_14 = 0 ;
break;
}
V_9 = F_4 ( V_7 , V_29 ) ;
V_9 |= V_14 ;
F_6 ( V_7 , V_9 , V_29 ) ;
V_9 = F_4 ( V_7 , V_30 ) ;
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_30 ) ;
V_9 = F_4 ( V_7 , V_31 ) ;
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_31 ) ;
V_9 = F_4 ( V_7 , V_32 ) ;
V_9 |= ( V_33 | V_34 ) ;
F_6 ( V_7 , V_9 , V_32 ) ;
}
static void F_9 ( struct V_2 * V_3 , int V_13 , bool V_35 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_36 ) ;
if ( V_35 )
V_9 |= 1 << V_13 ;
else
V_9 &= ~ ( 1 << V_13 ) ;
F_6 ( V_7 , V_9 , V_36 ) ;
}
static void F_10 ( struct V_2 * V_3 , bool V_35 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_9 ;
V_9 = F_11 ( V_7 , V_37 ) ;
if ( V_35 ) {
V_9 |= V_38 ;
V_9 &= ~ ( V_39 | V_40 | V_41 ) ;
F_12 ( V_7 , V_9 , V_37 ) ;
F_13 ( 21 ) ;
V_9 = F_11 ( V_7 , V_37 ) ;
V_9 &= ~ V_38 ;
} else {
V_9 |= V_39 | V_40 | V_38 ;
F_12 ( V_7 , V_9 , V_37 ) ;
F_14 ( 1 ) ;
V_9 |= V_41 ;
}
F_12 ( V_7 , V_9 , V_37 ) ;
if ( ! V_35 ) {
V_9 = F_11 ( V_7 , F_15 ( 0 ) ) ;
V_9 |= V_42 ;
F_12 ( V_7 , V_9 , F_15 ( 0 ) ) ;
}
}
static inline void F_16 ( struct V_6 * V_7 ,
int V_13 )
{
unsigned int V_43 ;
switch ( V_13 ) {
case 7 :
V_43 = V_44 ;
break;
case 0 :
F_17 ( V_7 , F_18 ( V_45 ) ) ;
return;
default:
V_43 = F_19 ( V_13 ) ;
break;
}
F_20 ( V_7 , F_18 ( V_43 ) ) ;
}
static inline void F_21 ( struct V_6 * V_7 ,
int V_13 )
{
unsigned int V_43 ;
switch ( V_13 ) {
case 7 :
V_43 = V_44 ;
break;
case 0 :
F_22 ( V_7 , F_18 ( V_45 ) ) ;
F_23 ( V_7 , F_18 ( V_45 ) , V_46 ) ;
return;
default:
V_43 = F_19 ( V_13 ) ;
break;
}
F_24 ( V_7 , F_18 ( V_43 ) ) ;
F_25 ( V_7 , F_18 ( V_43 ) , V_46 ) ;
}
static int F_26 ( struct V_2 * V_3 , int V_13 ,
struct V_47 * V_48 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_2 V_5 = V_3 -> V_49 [ V_3 -> V_50 ] . V_5 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_15 ) ;
V_9 &= ~ F_8 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_15 ) ;
F_6 ( V_7 , 0 , F_27 ( V_13 ) ) ;
if ( V_7 -> V_51 & 1 << V_13 && V_7 -> V_10 . V_52 == 1 ) {
F_10 ( V_3 , true ) ;
if ( V_48 ) {
V_48 -> V_53 = V_54 ;
F_28 ( V_48 ) ;
}
}
if ( V_13 == V_7 -> V_55 )
F_16 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , F_5 ( V_13 ) ) ;
V_9 &= ~ V_56 ;
V_9 |= ( 1 << V_13 ) ;
V_9 |= V_7 -> V_57 -> V_58 [ V_13 ] . V_59 ;
F_6 ( V_7 , V_9 , F_5 ( V_13 ) ) ;
F_2 ( V_3 , V_5 ) ;
if ( V_7 -> V_60 [ V_13 ] . V_61 . V_62 )
F_9 ( V_3 , V_13 , true ) ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 , int V_13 ,
struct V_47 * V_48 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_43 , V_9 ;
if ( V_7 -> V_63 & ( 1 << V_13 ) )
return;
if ( V_13 == V_7 -> V_55 )
F_21 ( V_7 , V_13 ) ;
if ( V_7 -> V_51 & 1 << V_13 && V_7 -> V_10 . V_52 == 1 )
F_10 ( V_3 , false ) ;
if ( F_30 ( V_3 , V_13 ) )
V_43 = V_16 ;
else
V_43 = F_27 ( V_13 ) ;
V_9 = F_4 ( V_7 , V_43 ) ;
V_9 |= V_20 | V_21 ;
F_6 ( V_7 , V_9 , V_43 ) ;
V_9 = F_4 ( V_7 , V_15 ) ;
V_9 |= F_8 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_15 ) ;
}
static int F_31 ( struct V_2 * V_3 , int V_13 ,
struct V_47 * V_48 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_64 * V_65 = & V_7 -> V_60 [ V_13 ] . V_61 ;
int V_66 ;
V_65 -> V_67 = ( V_68 | V_69 ) ;
V_66 = F_32 ( V_48 , 0 ) ;
if ( V_66 )
return 0 ;
F_9 ( V_3 , V_13 , true ) ;
return 1 ;
}
static int F_33 ( struct V_2 * V_3 , int V_13 ,
struct V_64 * V_70 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_64 * V_65 = & V_7 -> V_60 [ V_13 ] . V_61 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_71 ) ;
V_70 -> V_62 = V_65 -> V_62 ;
V_70 -> V_72 = ! ! ( V_9 & ( 1 << V_13 ) ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , int V_13 ,
struct V_47 * V_73 ,
struct V_64 * V_70 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_64 * V_65 = & V_7 -> V_60 [ V_13 ] . V_61 ;
V_65 -> V_62 = V_70 -> V_62 ;
if ( ! V_65 -> V_62 ) {
F_9 ( V_3 , V_13 , false ) ;
} else {
V_65 -> V_62 = F_31 ( V_3 , V_13 , V_73 ) ;
if ( ! V_65 -> V_62 )
return - V_74 ;
}
return 0 ;
}
static int F_35 ( struct V_6 * V_7 , int V_75 , int V_76 ,
int V_77 , T_3 V_14 )
{
int V_66 = 0 ;
T_1 V_9 ;
V_9 = F_11 ( V_7 , V_78 ) ;
V_9 |= V_79 ;
F_12 ( V_7 , V_9 , V_78 ) ;
V_9 = 0x70 ;
V_9 <<= 2 ;
F_6 ( V_7 , V_76 , V_9 ) ;
V_9 = 0x80 << 8 | V_77 << 1 ;
V_9 <<= 2 ;
if ( V_75 )
V_66 = F_4 ( V_7 , V_9 ) ;
else
F_6 ( V_7 , V_14 , V_9 ) ;
V_9 = F_11 ( V_7 , V_78 ) ;
V_9 &= ~ V_79 ;
F_12 ( V_7 , V_9 , V_78 ) ;
return V_66 & 0xffff ;
}
static int F_36 ( struct V_80 * V_81 , int V_76 , int V_77 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
if ( V_76 == V_82 && V_7 -> V_83 & F_37 ( V_76 ) )
return F_35 ( V_7 , 1 , V_76 , V_77 , 0 ) ;
else
return F_38 ( V_7 -> V_84 , V_76 , V_77 ) ;
}
static int F_39 ( struct V_80 * V_81 , int V_76 , int V_77 ,
T_3 V_14 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
if ( V_76 == V_82 && V_7 -> V_83 & F_37 ( V_76 ) )
F_35 ( V_7 , 0 , V_76 , V_77 , V_14 ) ;
else
F_40 ( V_7 -> V_84 , V_76 , V_77 , V_14 ) ;
return 0 ;
}
static T_4 F_41 ( int V_85 , void * V_86 )
{
struct V_6 * V_7 = V_86 ;
V_7 -> V_87 = F_42 ( V_7 , V_88 ) &
~ V_7 -> V_89 ;
F_23 ( V_7 , V_7 -> V_87 , V_46 ) ;
return V_90 ;
}
static T_4 F_43 ( int V_85 , void * V_86 )
{
struct V_6 * V_7 = V_86 ;
V_7 -> V_91 = F_44 ( V_7 , V_88 ) &
~ V_7 -> V_92 ;
F_25 ( V_7 , V_7 -> V_91 , V_46 ) ;
if ( V_7 -> V_91 & F_45 ( V_44 ) )
V_7 -> V_60 [ 7 ] . V_93 = 1 ;
if ( V_7 -> V_91 & F_46 ( V_44 ) )
V_7 -> V_60 [ 7 ] . V_93 = 0 ;
return V_90 ;
}
static int F_47 ( struct V_6 * V_7 )
{
unsigned int V_94 = 1000 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_95 ) ;
V_9 |= V_96 | V_97 | V_98 ;
F_6 ( V_7 , V_9 , V_95 ) ;
do {
V_9 = F_4 ( V_7 , V_95 ) ;
if ( ! ( V_9 & V_96 ) )
break;
F_48 ( 1000 , 2000 ) ;
} while ( V_94 -- > 0 );
if ( V_94 == 0 )
return - V_99 ;
return 0 ;
}
static void F_49 ( struct V_6 * V_7 )
{
F_22 ( V_7 , 0xffffffff ) ;
F_23 ( V_7 , 0xffffffff , V_46 ) ;
F_24 ( V_7 , 0xffffffff ) ;
F_25 ( V_7 , 0xffffffff , V_46 ) ;
}
static void F_50 ( struct V_6 * V_7 ,
struct V_100 * V_101 )
{
struct V_100 * V_13 ;
const char * V_102 ;
int V_103 ;
unsigned int V_104 ;
int V_66 ;
V_7 -> V_55 = - 1 ;
F_51 (dn, port) {
if ( F_52 ( V_13 , L_1 , & V_104 ) )
continue;
V_103 = F_53 ( V_13 ) ;
if ( V_103 < 0 ) {
V_66 = F_54 ( V_13 , L_2 ,
& V_102 ) ;
if ( V_66 < 0 )
continue;
if ( ! strcasecmp ( V_102 , L_3 ) )
V_7 -> V_51 |= 1 << V_104 ;
}
if ( V_103 == V_105 )
V_7 -> V_55 = V_104 ;
}
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_100 * V_101 ;
static int V_50 ;
int V_106 ;
V_101 = F_56 ( NULL , NULL , L_4 ) ;
V_7 -> V_84 = F_57 ( V_101 ) ;
if ( ! V_7 -> V_84 )
return - V_107 ;
F_58 ( & V_7 -> V_84 -> V_57 ) ;
V_7 -> V_108 = V_101 ;
V_7 -> V_109 = F_59 ( V_3 -> V_57 ) ;
if ( ! V_7 -> V_109 )
return - V_110 ;
V_7 -> V_109 -> V_7 = V_7 ;
V_7 -> V_109 -> V_111 = L_5 ;
V_7 -> V_109 -> V_112 = F_36 ;
V_7 -> V_109 -> V_113 = F_39 ;
snprintf ( V_7 -> V_109 -> V_114 , V_115 , L_6 ,
V_50 ++ ) ;
V_7 -> V_109 -> V_57 . V_116 = V_101 ;
if ( F_60 ( L_7 ) )
V_7 -> V_83 |= ( 1 << V_82 ) ;
else
V_7 -> V_83 = 0 ;
V_3 -> V_117 = V_7 -> V_83 ;
V_3 -> V_109 = V_7 -> V_109 ;
V_7 -> V_109 -> V_118 = V_3 -> V_57 -> V_118 ;
V_7 -> V_109 -> V_119 = ~ V_7 -> V_83 ;
if ( V_101 )
V_106 = F_61 ( V_7 -> V_109 , V_101 ) ;
else
V_106 = F_62 ( V_7 -> V_109 ) ;
if ( V_106 )
F_63 ( V_101 ) ;
return V_106 ;
}
static void F_64 ( struct V_6 * V_7 )
{
F_65 ( V_7 -> V_109 ) ;
if ( V_7 -> V_108 )
F_63 ( V_7 -> V_108 ) ;
}
static T_1 F_66 ( struct V_2 * V_3 , int V_13 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return V_7 -> V_10 . V_120 ;
}
static void F_67 ( struct V_2 * V_3 , int V_13 ,
struct V_47 * V_73 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_64 * V_65 = & V_7 -> V_60 [ V_13 ] . V_61 ;
T_1 V_121 = 0 , V_122 ;
const char * V_123 = NULL ;
T_1 V_9 ;
switch ( V_73 -> V_124 ) {
case V_125 :
V_123 = L_8 ;
V_121 = 1 ;
case V_126 :
if ( ! V_123 )
V_123 = L_9 ;
V_122 = V_127 ;
break;
case V_128 :
V_123 = L_10 ;
V_122 = V_129 ;
break;
case V_130 :
V_123 = L_11 ;
V_122 = V_131 ;
break;
default:
goto V_132;
}
if ( ! V_73 -> V_93 ) {
V_9 = F_11 ( V_7 , F_68 ( V_13 ) ) ;
V_9 &= ~ V_133 ;
F_12 ( V_7 , V_9 , F_68 ( V_13 ) ) ;
goto V_132;
}
V_9 = F_11 ( V_7 , F_68 ( V_13 ) ) ;
V_9 &= ~ V_134 ;
V_9 &= ~ ( V_135 << V_136 ) ;
V_9 &= ~ ( V_137 | V_138 ) ;
V_9 |= V_122 | V_133 ;
if ( V_121 )
V_9 |= V_134 ;
if ( V_73 -> V_139 ) {
if ( V_73 -> V_140 )
V_9 |= V_138 ;
V_9 |= V_137 ;
}
F_12 ( V_7 , V_9 , F_68 ( V_13 ) ) ;
F_69 ( L_12 , V_13 , V_123 ) ;
V_132:
V_9 = V_141 ;
switch ( V_73 -> V_142 ) {
case V_143 :
V_9 |= V_144 << V_145 ;
break;
case V_146 :
V_9 |= V_147 << V_145 ;
break;
}
if ( V_73 -> V_93 )
V_9 |= V_34 ;
if ( V_73 -> V_148 == V_149 )
V_9 |= V_150 ;
F_6 ( V_7 , V_9 , F_70 ( V_13 ) ) ;
if ( ! V_73 -> V_151 )
V_65 -> V_62 = F_31 ( V_3 , V_13 , V_73 ) ;
}
static void F_71 ( struct V_2 * V_3 , int V_13 ,
struct V_152 * V_153 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_148 , V_139 ;
T_1 V_9 ;
V_148 = F_4 ( V_7 , V_154 ) ;
V_139 = F_4 ( V_7 , V_155 ) ;
V_153 -> V_93 = 0 ;
if ( V_13 == V_7 -> V_55 ) {
V_153 -> V_93 = V_7 -> V_60 [ V_13 ] . V_93 ;
if ( ! V_153 -> V_93 )
F_72 ( V_3 -> V_58 [ V_13 ] . V_156 ) ;
V_153 -> V_148 = 1 ;
} else {
V_153 -> V_93 = 1 ;
V_153 -> V_148 = ! ! ( V_148 & ( 1 << V_13 ) ) ;
}
V_9 = F_4 ( V_7 , F_70 ( V_13 ) ) ;
V_9 |= V_141 ;
if ( V_153 -> V_93 )
V_9 |= V_34 ;
else
V_9 &= ~ V_34 ;
F_6 ( V_7 , V_9 , F_70 ( V_13 ) ) ;
if ( ( V_139 & ( 1 << V_13 ) ) &&
( V_139 & ( 1 << ( V_13 + V_157 ) ) ) ) {
V_153 -> V_140 = 1 ;
V_153 -> V_139 = 1 ;
}
if ( V_139 & ( 1 << V_13 ) )
V_153 -> V_139 = 1 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_49 ( V_7 ) ;
for ( V_13 = 0 ; V_13 < V_158 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 ||
F_30 ( V_3 , V_13 ) )
F_29 ( V_3 , V_13 , NULL ) ;
}
return 0 ;
}
static int F_74 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
int V_66 ;
V_66 = F_47 ( V_7 ) ;
if ( V_66 ) {
F_75 ( L_13 , V_159 ) ;
return V_66 ;
}
if ( V_7 -> V_10 . V_52 == 1 )
F_10 ( V_3 , true ) ;
for ( V_13 = 0 ; V_13 < V_158 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 )
F_26 ( V_3 , V_13 , NULL ) ;
else if ( F_30 ( V_3 , V_13 ) )
F_7 ( V_3 , V_13 ) ;
}
return 0 ;
}
static void F_76 ( struct V_2 * V_3 , int V_13 ,
struct V_160 * V_161 )
{
struct V_162 * V_65 = V_3 -> V_49 [ V_3 -> V_50 ] . V_163 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_160 V_164 ;
V_65 -> V_165 -> V_166 ( V_65 , & V_164 ) ;
V_161 -> V_67 = V_164 . V_67 ;
memset ( & V_161 -> V_167 , 0 , sizeof( V_161 -> V_167 ) ) ;
if ( V_164 . V_168 & V_169 )
memcpy ( & V_161 -> V_167 , V_164 . V_167 , sizeof( V_161 -> V_167 ) ) ;
if ( V_7 -> V_63 & ( 1 << V_13 ) )
V_161 -> V_168 = V_164 . V_168 ;
else
V_161 -> V_168 = 0 ;
}
static int F_77 ( struct V_2 * V_3 , int V_13 ,
struct V_160 * V_161 )
{
struct V_162 * V_65 = V_3 -> V_49 [ V_3 -> V_50 ] . V_163 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_2 V_5 = V_3 -> V_49 [ V_3 -> V_50 ] . V_5 ;
struct V_160 V_164 ;
V_65 -> V_165 -> V_166 ( V_65 , & V_164 ) ;
if ( V_161 -> V_168 & ~ V_164 . V_67 )
return - V_170 ;
if ( V_161 -> V_168 )
V_7 -> V_63 |= ( 1 << V_13 ) ;
else
V_7 -> V_63 &= ~ ( 1 << V_13 ) ;
if ( V_7 -> V_63 && V_7 -> V_63 != ( 1 << V_5 ) )
V_7 -> V_63 |= ( 1 << V_5 ) ;
else
V_7 -> V_63 &= ~ ( 1 << V_5 ) ;
return V_65 -> V_165 -> V_171 ( V_65 , V_161 ) ;
}
static int F_78 ( struct V_6 * V_7 )
{
unsigned int V_94 = 10 ;
T_1 V_9 ;
do {
V_9 = F_4 ( V_7 , V_172 ) ;
if ( ! ( V_9 & V_173 ) )
return 0 ;
F_48 ( 1000 , 2000 ) ;
} while ( V_94 -- );
return - V_99 ;
}
static int F_79 ( struct V_6 * V_7 , T_5 V_75 )
{
F_6 ( V_7 , V_173 | V_75 , V_172 ) ;
return F_78 ( V_7 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_79 ( V_7 , V_174 ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_10 . V_11 ; V_13 ++ ) {
if ( ! ( ( 1 << V_13 ) & V_3 -> V_12 ) )
continue;
F_6 ( V_7 , 1 , F_81 ( V_13 ) ) ;
}
}
static int F_82 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_7 -> V_10 . V_11 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 )
F_26 ( V_3 , V_13 , NULL ) ;
else if ( F_30 ( V_3 , V_13 ) )
F_7 ( V_3 , V_13 ) ;
else
F_29 ( V_3 , V_13 , NULL ) ;
}
F_80 ( V_3 ) ;
return 0 ;
}
static int F_83 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_5 * V_14 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
* V_14 = F_4 ( V_7 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_85 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_3 * V_14 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
* V_14 = F_4 ( V_7 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_86 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_1 * V_14 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
* V_14 = F_4 ( V_7 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_87 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_6 * V_14 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
* V_14 = F_88 ( V_7 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_89 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_5 V_177 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
F_6 ( V_7 , V_177 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_90 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_3 V_177 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
F_6 ( V_7 , V_177 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_91 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_1 V_177 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
F_6 ( V_7 , V_177 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_92 ( struct V_175 * V_57 , T_5 V_176 , T_5 V_9 ,
T_6 V_177 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
F_93 ( V_7 , V_177 , F_84 ( V_176 , V_9 ) ) ;
return 0 ;
}
static int F_94 ( struct V_178 * V_179 )
{
const char * V_180 [ V_181 ] = V_182 ;
struct V_100 * V_101 = V_179 -> V_57 . V_116 ;
struct V_183 * V_184 ;
struct V_6 * V_7 ;
struct V_175 * V_57 ;
struct V_2 * V_3 ;
void T_7 * * V_185 ;
struct V_186 * V_187 ;
unsigned int V_8 ;
T_1 V_9 , V_188 ;
int V_66 ;
V_7 = F_95 ( & V_179 -> V_57 , sizeof( * V_7 ) , V_189 ) ;
if ( ! V_7 )
return - V_110 ;
V_57 = F_96 ( & V_179 -> V_57 , & V_190 , V_7 ) ;
if ( ! V_57 )
return - V_110 ;
V_184 = F_95 ( & V_179 -> V_57 , sizeof( * V_184 ) , V_189 ) ;
if ( ! V_184 )
return - V_110 ;
V_184 -> V_191 = V_192 ;
V_57 -> V_184 = V_184 ;
V_7 -> V_57 = V_57 ;
V_3 = V_57 -> V_3 ;
V_3 -> V_193 -> V_194 = F_1 ;
V_3 -> V_193 -> V_195 = F_82 ;
V_3 -> V_193 -> V_196 = F_66 ;
V_3 -> V_193 -> V_197 = F_67 ;
V_3 -> V_193 -> V_198 = F_71 ;
V_3 -> V_193 -> V_199 = F_73 ;
V_3 -> V_193 -> V_200 = F_74 ;
V_3 -> V_193 -> V_166 = F_76 ;
V_3 -> V_193 -> V_171 = F_77 ;
V_3 -> V_193 -> V_201 = F_26 ;
V_3 -> V_193 -> V_202 = F_29 ;
V_3 -> V_193 -> V_203 = F_33 ;
V_3 -> V_193 -> V_204 = F_34 ;
V_3 -> V_193 -> V_205 = NULL ;
F_97 ( & V_179 -> V_57 , V_7 ) ;
F_98 ( & V_7 -> V_206 ) ;
F_99 ( & V_7 -> V_207 ) ;
F_50 ( V_7 , V_101 -> V_208 ) ;
V_7 -> V_209 = F_100 ( V_101 , 0 ) ;
V_7 -> V_210 = F_100 ( V_101 , 1 ) ;
V_185 = & V_7 -> V_211 ;
for ( V_8 = 0 ; V_8 < V_181 ; V_8 ++ ) {
V_187 = F_101 ( V_179 , V_212 , V_8 ) ;
* V_185 = F_102 ( & V_179 -> V_57 , V_187 ) ;
if ( F_103 ( * V_185 ) ) {
F_75 ( L_14 , V_180 [ V_8 ] ) ;
return F_104 ( * V_185 ) ;
}
V_185 ++ ;
}
V_66 = F_47 ( V_7 ) ;
if ( V_66 ) {
F_75 ( L_15 , V_66 ) ;
return V_66 ;
}
V_66 = F_55 ( V_3 ) ;
if ( V_66 ) {
F_75 ( L_16 ) ;
return V_66 ;
}
F_49 ( V_7 ) ;
V_66 = F_105 ( & V_179 -> V_57 , V_7 -> V_209 , F_41 , 0 ,
L_17 , V_7 ) ;
if ( V_66 < 0 ) {
F_75 ( L_18 ) ;
goto V_213;
}
V_66 = F_105 ( & V_179 -> V_57 , V_7 -> V_210 , F_43 , 0 ,
L_19 , V_7 ) ;
if ( V_66 < 0 ) {
F_75 ( L_20 ) ;
goto V_213;
}
V_9 = F_4 ( V_7 , V_214 ) ;
V_9 |= V_215 ;
F_6 ( V_7 , V_9 , V_214 ) ;
V_9 &= ~ V_215 ;
F_6 ( V_7 , V_9 , V_214 ) ;
V_7 -> V_10 . V_11 = F_4 ( V_7 , V_216 ) + 1 ;
if ( V_7 -> V_10 . V_11 > V_158 )
V_7 -> V_10 . V_11 = V_158 ;
if ( F_52 ( V_101 , L_21 ,
& V_7 -> V_10 . V_52 ) )
V_7 -> V_10 . V_52 = 1 ;
V_188 = F_11 ( V_7 , V_217 ) ;
V_7 -> V_10 . V_218 = ( V_188 >> V_219 ) &
V_220 ;
V_7 -> V_10 . V_221 = ( V_188 & V_222 ) ;
V_188 = F_11 ( V_7 , V_223 ) ;
V_7 -> V_10 . V_120 = V_188 & V_224 ;
V_66 = F_106 ( V_57 ) ;
if ( V_66 )
goto V_213;
F_69 ( L_22 ,
V_7 -> V_10 . V_218 >> 8 , V_7 -> V_10 . V_218 & 0xff ,
V_7 -> V_10 . V_221 >> 8 , V_7 -> V_10 . V_221 & 0xff ,
V_7 -> V_211 , V_7 -> V_209 , V_7 -> V_210 ) ;
return 0 ;
V_213:
F_64 ( V_7 ) ;
return V_66 ;
}
static int F_107 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_108 ( V_179 ) ;
V_7 -> V_63 = 0 ;
F_73 ( V_7 -> V_57 -> V_3 ) ;
F_109 ( V_7 -> V_57 -> V_3 ) ;
F_64 ( V_7 ) ;
return 0 ;
}
static void F_110 ( struct V_178 * V_179 )
{
struct V_6 * V_7 = F_108 ( V_179 ) ;
if ( V_7 -> V_10 . V_52 == 1 )
F_10 ( V_7 -> V_57 -> V_3 , true ) ;
}
static int F_111 ( struct V_225 * V_57 )
{
struct V_178 * V_179 = F_112 ( V_57 ) ;
struct V_6 * V_7 = F_108 ( V_179 ) ;
return F_113 ( V_7 -> V_57 -> V_3 ) ;
}
static int F_114 ( struct V_225 * V_57 )
{
struct V_178 * V_179 = F_112 ( V_57 ) ;
struct V_6 * V_7 = F_108 ( V_179 ) ;
return F_115 ( V_7 -> V_57 -> V_3 ) ;
}
