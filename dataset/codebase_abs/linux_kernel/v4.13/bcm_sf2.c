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
T_2 V_5 = V_3 -> V_52 -> V_53 -> V_54 ;
unsigned int V_8 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_25 ) ;
V_9 &= ~ F_9 ( V_13 ) ;
F_6 ( V_7 , V_9 , V_25 ) ;
if ( V_7 -> V_55 & F_28 ( V_13 ) )
F_7 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , F_29 ( V_13 ) ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
V_9 |= V_8 << ( V_56 * V_8 ) ;
F_6 ( V_7 , V_9 , F_29 ( V_13 ) ) ;
F_6 ( V_7 , 0 , F_30 ( V_13 ) ) ;
if ( V_7 -> V_57 & 1 << V_13 && V_7 -> V_10 . V_58 == 1 ) {
F_11 ( V_3 , true ) ;
if ( V_51 ) {
V_51 -> V_59 = V_60 ;
F_31 ( V_51 ) ;
}
}
if ( V_13 == V_7 -> V_61 )
F_17 ( V_7 , V_13 ) ;
V_9 = F_4 ( V_7 , F_5 ( V_13 ) ) ;
V_9 &= ~ V_62 ;
V_9 |= ( 1 << V_13 ) ;
V_9 |= V_7 -> V_63 -> V_64 [ V_13 ] . V_65 ;
F_6 ( V_7 , V_9 , F_5 ( V_13 ) ) ;
F_2 ( V_3 , V_5 ) ;
if ( V_7 -> V_66 [ V_13 ] . V_67 . V_68 )
F_10 ( V_3 , V_13 , true ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_51 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_46 , V_9 ;
if ( V_7 -> V_69 & ( 1 << V_13 ) )
return;
if ( V_13 == V_7 -> V_61 )
F_22 ( V_7 , V_13 ) ;
if ( V_7 -> V_57 & 1 << V_13 && V_7 -> V_10 . V_58 == 1 )
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
struct V_70 * V_71 = & V_7 -> V_66 [ V_13 ] . V_67 ;
int V_72 ;
V_71 -> V_73 = ( V_74 | V_75 ) ;
V_72 = F_35 ( V_51 , 0 ) ;
if ( V_72 )
return 0 ;
F_10 ( V_3 , V_13 , true ) ;
return 1 ;
}
static int F_36 ( struct V_2 * V_3 , int V_13 ,
struct V_70 * V_76 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_70 * V_71 = & V_7 -> V_66 [ V_13 ] . V_67 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_77 ) ;
V_76 -> V_68 = V_71 -> V_68 ;
V_76 -> V_78 = ! ! ( V_9 & ( 1 << V_13 ) ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_79 ,
struct V_70 * V_76 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_70 * V_71 = & V_7 -> V_66 [ V_13 ] . V_67 ;
V_71 -> V_68 = V_76 -> V_68 ;
if ( ! V_71 -> V_68 ) {
F_10 ( V_3 , V_13 , false ) ;
} else {
V_71 -> V_68 = F_34 ( V_3 , V_13 , V_79 ) ;
if ( ! V_71 -> V_68 )
return - V_80 ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_7 , int V_81 , int V_82 ,
int V_83 , T_3 V_14 )
{
int V_72 = 0 ;
T_1 V_9 ;
V_9 = F_12 ( V_7 , V_84 ) ;
V_9 |= V_85 ;
F_13 ( V_7 , V_9 , V_84 ) ;
V_9 = 0x70 ;
V_9 <<= 2 ;
F_6 ( V_7 , V_82 , V_9 ) ;
V_9 = 0x80 << 8 | V_83 << 1 ;
V_9 <<= 2 ;
if ( V_81 )
V_72 = F_4 ( V_7 , V_9 ) ;
else
F_6 ( V_7 , V_14 , V_9 ) ;
V_9 = F_12 ( V_7 , V_84 ) ;
V_9 &= ~ V_85 ;
F_13 ( V_7 , V_9 , V_84 ) ;
return V_72 & 0xffff ;
}
static int F_39 ( struct V_86 * V_87 , int V_82 , int V_83 )
{
struct V_6 * V_7 = V_87 -> V_7 ;
if ( V_82 == V_88 && V_7 -> V_89 & F_28 ( V_82 ) )
return F_38 ( V_7 , 1 , V_82 , V_83 , 0 ) ;
else
return F_40 ( V_7 -> V_90 , V_82 , V_83 ) ;
}
static int F_41 ( struct V_86 * V_87 , int V_82 , int V_83 ,
T_3 V_14 )
{
struct V_6 * V_7 = V_87 -> V_7 ;
if ( V_82 == V_88 && V_7 -> V_89 & F_28 ( V_82 ) )
F_38 ( V_7 , 0 , V_82 , V_83 , V_14 ) ;
else
F_42 ( V_7 -> V_90 , V_82 , V_83 , V_14 ) ;
return 0 ;
}
static T_4 F_43 ( int V_91 , void * V_92 )
{
struct V_6 * V_7 = V_92 ;
V_7 -> V_93 = F_44 ( V_7 , V_94 ) &
~ V_7 -> V_95 ;
F_24 ( V_7 , V_7 -> V_93 , V_49 ) ;
return V_96 ;
}
static T_4 F_45 ( int V_91 , void * V_92 )
{
struct V_6 * V_7 = V_92 ;
V_7 -> V_97 = F_46 ( V_7 , V_94 ) &
~ V_7 -> V_98 ;
F_26 ( V_7 , V_7 -> V_97 , V_49 ) ;
if ( V_7 -> V_97 & F_47 ( V_47 ) )
V_7 -> V_66 [ 7 ] . V_99 = 1 ;
if ( V_7 -> V_97 & F_48 ( V_47 ) )
V_7 -> V_66 [ 7 ] . V_99 = 0 ;
return V_96 ;
}
static int F_49 ( struct V_6 * V_7 )
{
unsigned int V_100 = 1000 ;
T_1 V_9 ;
V_9 = F_4 ( V_7 , V_101 ) ;
V_9 |= V_102 | V_103 | V_104 ;
F_6 ( V_7 , V_9 , V_101 ) ;
do {
V_9 = F_4 ( V_7 , V_101 ) ;
if ( ! ( V_9 & V_102 ) )
break;
F_50 ( 1000 , 2000 ) ;
} while ( V_100 -- > 0 );
if ( V_100 == 0 )
return - V_105 ;
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
struct V_106 * V_107 )
{
struct V_106 * V_13 ;
int V_108 ;
unsigned int V_109 ;
V_7 -> V_61 = - 1 ;
F_53 (dn, port) {
if ( F_54 ( V_13 , L_1 , & V_109 ) )
continue;
V_108 = F_55 ( V_13 ) ;
if ( V_108 < 0 )
continue;
if ( V_108 == V_110 )
V_7 -> V_57 |= 1 << V_109 ;
if ( V_108 == V_111 )
V_7 -> V_61 = V_109 ;
if ( F_56 ( V_13 , L_2 ) )
V_7 -> V_55 |= 1 << V_109 ;
}
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_106 * V_107 ;
static int V_54 ;
int V_112 ;
V_107 = F_58 ( NULL , NULL , L_3 ) ;
V_7 -> V_90 = F_59 ( V_107 ) ;
if ( ! V_7 -> V_90 )
return - V_113 ;
F_60 ( & V_7 -> V_90 -> V_63 ) ;
V_7 -> V_114 = V_107 ;
V_7 -> V_115 = F_61 ( V_3 -> V_63 ) ;
if ( ! V_7 -> V_115 )
return - V_116 ;
V_7 -> V_115 -> V_7 = V_7 ;
V_7 -> V_115 -> V_117 = L_4 ;
V_7 -> V_115 -> V_118 = F_39 ;
V_7 -> V_115 -> V_119 = F_41 ;
snprintf ( V_7 -> V_115 -> V_120 , V_121 , L_5 ,
V_54 ++ ) ;
V_7 -> V_115 -> V_63 . V_122 = V_107 ;
if ( F_62 ( L_6 ) )
V_7 -> V_89 |= ( 1 << V_88 ) ;
else
V_7 -> V_89 = 0 ;
V_3 -> V_123 = V_7 -> V_89 ;
V_3 -> V_115 = V_7 -> V_115 ;
V_7 -> V_115 -> V_124 = V_3 -> V_63 -> V_124 ;
V_7 -> V_115 -> V_125 = ~ V_7 -> V_89 ;
if ( V_107 )
V_112 = F_63 ( V_7 -> V_115 , V_107 ) ;
else
V_112 = F_64 ( V_7 -> V_115 ) ;
if ( V_112 )
F_65 ( V_107 ) ;
return V_112 ;
}
static void F_66 ( struct V_6 * V_7 )
{
F_67 ( V_7 -> V_115 ) ;
if ( V_7 -> V_114 )
F_65 ( V_7 -> V_114 ) ;
}
static T_1 F_68 ( struct V_2 * V_3 , int V_13 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
return V_7 -> V_10 . V_126 ;
}
static void F_69 ( struct V_2 * V_3 , int V_13 ,
struct V_50 * V_79 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_70 * V_71 = & V_7 -> V_66 [ V_13 ] . V_67 ;
T_1 V_127 = 0 , V_128 ;
const char * V_129 = NULL ;
T_1 V_9 , V_21 ;
if ( V_7 -> type == V_22 )
V_21 = F_70 ( V_13 ) ;
else
V_21 = F_71 ( V_13 ) ;
switch ( V_79 -> V_130 ) {
case V_131 :
V_129 = L_7 ;
V_127 = 1 ;
case V_132 :
if ( ! V_129 )
V_129 = L_8 ;
V_128 = V_133 ;
break;
case V_134 :
V_129 = L_9 ;
V_128 = V_135 ;
break;
case V_136 :
V_129 = L_10 ;
V_128 = V_137 ;
break;
default:
goto V_138;
}
if ( ! V_79 -> V_99 ) {
V_9 = F_12 ( V_7 , F_72 ( V_13 ) ) ;
V_9 &= ~ V_139 ;
F_13 ( V_7 , V_9 , F_72 ( V_13 ) ) ;
goto V_138;
}
V_9 = F_12 ( V_7 , F_72 ( V_13 ) ) ;
V_9 &= ~ V_140 ;
V_9 &= ~ ( V_141 << V_142 ) ;
V_9 &= ~ ( V_143 | V_144 ) ;
V_9 |= V_128 | V_139 ;
if ( V_127 )
V_9 |= V_140 ;
if ( V_79 -> V_145 ) {
if ( V_79 -> V_146 )
V_9 |= V_144 ;
V_9 |= V_143 ;
}
F_13 ( V_7 , V_9 , F_72 ( V_13 ) ) ;
F_73 ( L_11 , V_13 , V_129 ) ;
V_138:
V_9 = V_147 ;
switch ( V_79 -> V_148 ) {
case V_149 :
V_9 |= V_150 << V_151 ;
break;
case V_152 :
V_9 |= V_153 << V_151 ;
break;
}
if ( V_79 -> V_99 )
V_9 |= V_37 ;
if ( V_79 -> V_154 == V_155 )
V_9 |= V_156 ;
F_6 ( V_7 , V_9 , V_21 ) ;
if ( ! V_79 -> V_157 )
V_71 -> V_68 = F_34 ( V_3 , V_13 , V_79 ) ;
}
static void F_74 ( struct V_2 * V_3 , int V_13 ,
struct V_158 * V_159 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_154 , V_145 , V_21 ;
T_1 V_9 ;
if ( V_7 -> type == V_22 )
V_21 = F_70 ( V_13 ) ;
else
V_21 = F_71 ( V_13 ) ;
V_154 = F_4 ( V_7 , V_160 ) ;
V_145 = F_4 ( V_7 , V_161 ) ;
V_159 -> V_99 = 0 ;
if ( V_13 == V_7 -> V_61 ) {
V_159 -> V_99 = V_7 -> V_66 [ V_13 ] . V_99 ;
if ( ! V_159 -> V_99 )
F_75 ( V_3 -> V_64 [ V_13 ] . V_162 ) ;
V_159 -> V_154 = 1 ;
} else {
V_159 -> V_99 = 1 ;
V_159 -> V_154 = ! ! ( V_154 & ( 1 << V_13 ) ) ;
}
V_9 = F_4 ( V_7 , V_21 ) ;
V_9 |= V_147 ;
if ( V_159 -> V_99 )
V_9 |= V_37 ;
else
V_9 &= ~ V_37 ;
F_6 ( V_7 , V_9 , V_21 ) ;
if ( ( V_145 & ( 1 << V_13 ) ) &&
( V_145 & ( 1 << ( V_13 + V_163 ) ) ) ) {
V_159 -> V_146 = 1 ;
V_159 -> V_145 = 1 ;
}
if ( V_145 & ( 1 << V_13 ) )
V_159 -> V_145 = 1 ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_51 ( V_7 ) ;
for ( V_13 = 0 ; V_13 < V_164 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 ||
F_33 ( V_3 , V_13 ) )
F_32 ( V_3 , V_13 , NULL ) ;
}
return 0 ;
}
static int F_77 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
int V_72 ;
V_72 = F_49 ( V_7 ) ;
if ( V_72 ) {
F_78 ( L_12 , V_165 ) ;
return V_72 ;
}
if ( V_7 -> V_10 . V_58 == 1 )
F_11 ( V_3 , true ) ;
for ( V_13 = 0 ; V_13 < V_164 ; V_13 ++ ) {
if ( ( 1 << V_13 ) & V_3 -> V_12 )
F_27 ( V_3 , V_13 , NULL ) ;
else if ( F_33 ( V_3 , V_13 ) )
F_8 ( V_3 , V_13 ) ;
}
return 0 ;
}
static void F_79 ( struct V_2 * V_3 , int V_13 ,
struct V_166 * V_167 )
{
struct V_168 * V_71 = V_3 -> V_52 [ V_3 -> V_54 ] . V_53 -> V_162 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_166 V_169 ;
V_71 -> V_170 -> V_171 ( V_71 , & V_169 ) ;
V_167 -> V_73 = V_169 . V_73 ;
memset ( & V_167 -> V_172 , 0 , sizeof( V_167 -> V_172 ) ) ;
if ( V_169 . V_173 & V_174 )
memcpy ( & V_167 -> V_172 , V_169 . V_172 , sizeof( V_167 -> V_172 ) ) ;
if ( V_7 -> V_69 & ( 1 << V_13 ) )
V_167 -> V_173 = V_169 . V_173 ;
else
V_167 -> V_173 = 0 ;
}
static int F_80 ( struct V_2 * V_3 , int V_13 ,
struct V_166 * V_167 )
{
struct V_168 * V_71 = V_3 -> V_52 [ V_3 -> V_54 ] . V_53 -> V_162 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_2 V_5 = V_3 -> V_52 -> V_53 -> V_54 ;
struct V_166 V_169 ;
V_71 -> V_170 -> V_171 ( V_71 , & V_169 ) ;
if ( V_167 -> V_173 & ~ V_169 . V_73 )
return - V_175 ;
if ( V_167 -> V_173 )
V_7 -> V_69 |= ( 1 << V_13 ) ;
else
V_7 -> V_69 &= ~ ( 1 << V_13 ) ;
if ( V_7 -> V_69 && V_7 -> V_69 != ( 1 << V_5 ) )
V_7 -> V_69 |= ( 1 << V_5 ) ;
else
V_7 -> V_69 &= ~ ( 1 << V_5 ) ;
return V_71 -> V_170 -> V_176 ( V_71 , V_167 ) ;
}
static int F_81 ( struct V_6 * V_7 )
{
unsigned int V_100 = 10 ;
T_1 V_9 ;
do {
V_9 = F_4 ( V_7 , V_177 ) ;
if ( ! ( V_9 & V_178 ) )
return 0 ;
F_50 ( 1000 , 2000 ) ;
} while ( V_100 -- );
return - V_105 ;
}
static int F_82 ( struct V_6 * V_7 , T_5 V_81 )
{
F_6 ( V_7 , V_178 | V_81 , V_177 ) ;
return F_81 ( V_7 ) ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
unsigned int V_13 ;
F_82 ( V_7 , V_179 ) ;
for ( V_13 = 0 ; V_13 < V_7 -> V_10 . V_11 ; V_13 ++ ) {
if ( ! ( ( 1 << V_13 ) & V_3 -> V_12 ) )
continue;
F_6 ( V_7 , 1 , F_84 ( V_13 ) ) ;
}
}
static int F_85 ( struct V_2 * V_3 )
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
F_83 ( V_3 ) ;
return 0 ;
}
static int F_86 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_5 * V_14 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
* V_14 = F_4 ( V_7 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_88 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_3 * V_14 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
* V_14 = F_4 ( V_7 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_89 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_1 * V_14 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
* V_14 = F_4 ( V_7 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_90 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_6 * V_14 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
* V_14 = F_91 ( V_7 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_92 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_5 V_182 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
F_6 ( V_7 , V_182 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_93 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_3 V_182 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
F_6 ( V_7 , V_182 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_94 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_1 V_182 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
F_6 ( V_7 , V_182 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_95 ( struct V_180 * V_63 , T_5 V_181 , T_5 V_9 ,
T_6 V_182 )
{
struct V_6 * V_7 = V_63 -> V_7 ;
F_96 ( V_7 , V_182 , F_87 ( V_181 , V_9 ) ) ;
return 0 ;
}
static int F_97 ( struct V_183 * V_184 )
{
const char * V_185 [ V_186 ] = V_187 ;
struct V_106 * V_107 = V_184 -> V_63 . V_122 ;
const struct V_188 * V_189 = NULL ;
const struct V_190 * V_191 ;
struct V_192 * V_193 ;
struct V_194 * V_195 ;
struct V_6 * V_7 ;
struct V_180 * V_63 ;
struct V_2 * V_3 ;
void T_7 * * V_196 ;
struct V_197 * V_198 ;
unsigned int V_8 ;
T_1 V_9 , V_199 ;
int V_72 ;
V_7 = F_98 ( & V_184 -> V_63 , sizeof( * V_7 ) , V_200 ) ;
if ( ! V_7 )
return - V_116 ;
V_195 = F_98 ( & V_184 -> V_63 , sizeof( * V_195 ) , V_200 ) ;
if ( ! V_195 )
return - V_116 ;
V_63 = F_99 ( & V_184 -> V_63 , & V_201 , V_7 ) ;
if ( ! V_63 )
return - V_116 ;
V_193 = F_98 ( & V_184 -> V_63 , sizeof( * V_193 ) , V_200 ) ;
if ( ! V_193 )
return - V_116 ;
V_189 = F_100 ( V_202 , V_107 ) ;
if ( ! V_189 || ! V_189 -> V_191 )
return - V_175 ;
V_191 = V_189 -> V_191 ;
V_7 -> type = V_191 -> type ;
V_7 -> V_203 = V_191 -> V_203 ;
V_7 -> V_204 = V_191 -> V_204 ;
V_7 -> V_205 = V_191 -> V_205 ;
V_193 -> V_206 = V_7 -> type ;
V_63 -> V_193 = V_193 ;
V_7 -> V_63 = V_63 ;
V_3 = V_63 -> V_3 ;
V_3 -> V_195 = & V_207 ;
F_101 ( & V_184 -> V_63 , V_7 ) ;
F_102 ( & V_7 -> V_208 ) ;
F_103 ( & V_7 -> V_209 ) ;
F_103 ( & V_7 -> V_210 . V_211 ) ;
F_104 ( 0 , V_7 -> V_210 . V_212 ) ;
F_52 ( V_7 , V_107 -> V_213 ) ;
V_7 -> V_214 = F_105 ( V_107 , 0 ) ;
V_7 -> V_215 = F_105 ( V_107 , 1 ) ;
V_196 = & V_7 -> V_216 ;
for ( V_8 = 0 ; V_8 < V_186 ; V_8 ++ ) {
V_198 = F_106 ( V_184 , V_217 , V_8 ) ;
* V_196 = F_107 ( & V_184 -> V_63 , V_198 ) ;
if ( F_108 ( * V_196 ) ) {
F_78 ( L_13 , V_185 [ V_8 ] ) ;
return F_109 ( * V_196 ) ;
}
V_196 ++ ;
}
V_72 = F_49 ( V_7 ) ;
if ( V_72 ) {
F_78 ( L_14 , V_72 ) ;
return V_72 ;
}
V_72 = F_57 ( V_3 ) ;
if ( V_72 ) {
F_78 ( L_15 ) ;
return V_72 ;
}
V_72 = F_110 ( V_7 ) ;
if ( V_72 ) {
F_78 ( L_16 ) ;
goto V_218;
}
F_51 ( V_7 ) ;
V_72 = F_111 ( & V_184 -> V_63 , V_7 -> V_214 , F_43 , 0 ,
L_17 , V_7 ) ;
if ( V_72 < 0 ) {
F_78 ( L_18 ) ;
goto V_218;
}
V_72 = F_111 ( & V_184 -> V_63 , V_7 -> V_215 , F_45 , 0 ,
L_19 , V_7 ) ;
if ( V_72 < 0 ) {
F_78 ( L_20 ) ;
goto V_218;
}
V_9 = F_4 ( V_7 , V_219 ) ;
V_9 |= V_220 ;
F_6 ( V_7 , V_9 , V_219 ) ;
V_9 &= ~ V_220 ;
F_6 ( V_7 , V_9 , V_219 ) ;
V_7 -> V_10 . V_11 = F_4 ( V_7 , V_221 ) + 1 ;
if ( V_7 -> V_10 . V_11 > V_164 )
V_7 -> V_10 . V_11 = V_164 ;
if ( F_54 ( V_107 , L_21 ,
& V_7 -> V_10 . V_58 ) )
V_7 -> V_10 . V_58 = 1 ;
V_199 = F_12 ( V_7 , V_222 ) ;
V_7 -> V_10 . V_223 = ( V_199 >> V_224 ) &
V_225 ;
V_7 -> V_10 . V_226 = ( V_199 & V_227 ) ;
V_199 = F_12 ( V_7 , V_228 ) ;
V_7 -> V_10 . V_126 = V_199 & V_229 ;
V_72 = F_112 ( V_63 ) ;
if ( V_72 )
goto V_218;
F_73 ( L_22 ,
V_7 -> V_10 . V_223 >> 8 , V_7 -> V_10 . V_223 & 0xff ,
V_7 -> V_10 . V_226 >> 8 , V_7 -> V_10 . V_226 & 0xff ,
V_7 -> V_216 , V_7 -> V_214 , V_7 -> V_215 ) ;
return 0 ;
V_218:
F_66 ( V_7 ) ;
return V_72 ;
}
static int F_113 ( struct V_183 * V_184 )
{
struct V_6 * V_7 = F_114 ( V_184 ) ;
V_7 -> V_69 = 0 ;
F_76 ( V_7 -> V_63 -> V_3 ) ;
F_115 ( V_7 -> V_63 -> V_3 ) ;
F_66 ( V_7 ) ;
return 0 ;
}
static void F_116 ( struct V_183 * V_184 )
{
struct V_6 * V_7 = F_114 ( V_184 ) ;
if ( V_7 -> V_10 . V_58 == 1 )
F_11 ( V_7 -> V_63 -> V_3 , true ) ;
}
static int F_117 ( struct V_230 * V_63 )
{
struct V_183 * V_184 = F_118 ( V_63 ) ;
struct V_6 * V_7 = F_114 ( V_184 ) ;
return F_119 ( V_7 -> V_63 -> V_3 ) ;
}
static int F_120 ( struct V_230 * V_63 )
{
struct V_183 * V_184 = F_118 ( V_63 ) ;
struct V_6 * V_7 = F_114 ( V_184 ) ;
return F_121 ( V_7 -> V_63 -> V_3 ) ;
}
