static void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
memcpy ( V_4 + V_5 * V_7 ,
V_8 [ V_5 ] . string , V_7 ) ;
}
static void F_2 ( struct V_1 * V_2 ,
int V_3 , T_2 * V_4 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
const struct V_11 * V_12 ;
unsigned int V_5 ;
T_3 V_13 = 0 ;
T_4 V_14 ;
F_4 ( & V_10 -> V_15 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_12 = & V_8 [ V_5 ] ;
V_14 = V_12 -> V_16 + F_5 ( V_3 ) ;
if ( V_12 -> V_17 == 8 )
V_13 = F_6 ( V_10 , V_14 ) ;
else
V_13 = F_7 ( V_10 , V_14 ) ;
V_4 [ V_5 ] = ( T_3 ) V_13 ;
}
F_8 ( & V_10 -> V_15 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return V_6 ;
}
static char * F_10 ( struct V_18 * V_19 , int V_20 )
{
return L_1 ;
}
static void F_11 ( struct V_1 * V_2 , int V_21 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 ;
for ( V_5 = 0 ; V_5 < V_10 -> V_22 . V_23 ; V_5 ++ ) {
if ( ! ( ( 1 << V_5 ) & V_2 -> V_24 ) )
continue;
V_16 = F_7 ( V_10 , F_12 ( V_5 ) ) ;
V_16 |= ( 1 << V_21 ) ;
F_13 ( V_10 , V_16 , F_12 ( V_5 ) ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 , V_13 ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 &= ~ F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
V_16 = F_7 ( V_10 , V_26 ) ;
V_16 |= ( V_27 | V_28 | V_29 ) ;
V_16 &= ~ ( V_30 | V_31 ) ;
F_13 ( V_10 , V_16 , V_26 ) ;
F_13 ( V_10 , V_32 , V_33 ) ;
V_16 = F_7 ( V_10 , V_34 ) ;
V_16 |= V_35 ;
F_13 ( V_10 , V_16 , V_34 ) ;
switch ( V_3 ) {
case 8 :
V_13 = V_36 ;
break;
case 7 :
V_13 = V_37 ;
break;
case 5 :
V_13 = V_38 ;
break;
default:
V_13 = 0 ;
break;
}
V_16 = F_7 ( V_10 , V_39 ) ;
V_16 |= V_13 ;
F_13 ( V_10 , V_16 , V_39 ) ;
V_16 = F_7 ( V_10 , V_40 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_40 ) ;
V_16 = F_7 ( V_10 , V_41 ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_41 ) ;
V_16 = F_7 ( V_10 , V_42 ) ;
V_16 |= ( V_43 | V_44 ) ;
F_13 ( V_10 , V_16 , V_42 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 , bool V_45 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_46 ) ;
if ( V_45 )
V_16 |= 1 << V_3 ;
else
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , V_46 ) ;
}
static void F_17 ( struct V_1 * V_2 , bool V_45 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_16 ;
V_16 = F_18 ( V_10 , V_47 ) ;
if ( V_45 ) {
V_16 |= V_48 ;
V_16 &= ~ ( V_49 | V_50 | V_51 ) ;
F_19 ( V_10 , V_16 , V_47 ) ;
F_20 ( 21 ) ;
V_16 = F_18 ( V_10 , V_47 ) ;
V_16 &= ~ V_48 ;
} else {
V_16 |= V_49 | V_50 | V_48 ;
F_19 ( V_10 , V_16 , V_47 ) ;
F_21 ( 1 ) ;
V_16 |= V_51 ;
}
F_19 ( V_10 , V_16 , V_47 ) ;
if ( ! V_45 ) {
V_16 = F_18 ( V_10 , F_22 ( 0 ) ) ;
V_16 |= V_52 ;
F_19 ( V_10 , V_16 , F_22 ( 0 ) ) ;
}
}
static int F_23 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_54 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_55 [ V_2 -> V_56 ] . V_21 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 &= ~ F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
F_13 ( V_10 , 0 , F_24 ( V_3 ) ) ;
if ( V_3 == 0 && V_10 -> V_22 . V_57 == 1 ) {
F_17 ( V_2 , true ) ;
if ( V_54 ) {
V_54 -> V_58 = V_59 ;
F_25 ( V_54 ) ;
}
}
if ( V_3 == 7 )
F_26 ( V_10 , F_27 ( V_60 ) ) ;
V_16 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
V_16 &= ~ V_61 ;
V_16 |= ( 1 << V_3 ) ;
V_16 |= V_10 -> V_62 [ V_3 ] . V_63 ;
F_13 ( V_10 , V_16 , F_12 ( V_3 ) ) ;
F_11 ( V_2 , V_21 ) ;
if ( V_10 -> V_62 [ V_3 ] . V_64 . V_65 )
F_16 ( V_2 , V_3 , true ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_54 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_66 , V_16 ;
if ( V_10 -> V_67 & ( 1 << V_3 ) )
return;
if ( V_3 == 7 ) {
F_29 ( V_10 , F_27 ( V_60 ) ) ;
F_30 ( V_10 , F_27 ( V_60 ) , V_68 ) ;
}
if ( V_3 == 0 && V_10 -> V_22 . V_57 == 1 )
F_17 ( V_2 , false ) ;
if ( F_31 ( V_2 , V_3 ) )
V_66 = V_26 ;
else
V_66 = F_24 ( V_3 ) ;
V_16 = F_7 ( V_10 , V_66 ) ;
V_16 |= V_30 | V_31 ;
F_13 ( V_10 , V_16 , V_66 ) ;
V_16 = F_7 ( V_10 , V_25 ) ;
V_16 |= F_15 ( V_3 ) ;
F_13 ( V_10 , V_16 , V_25 ) ;
}
static int F_32 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_54 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_69 * V_70 = & V_10 -> V_62 [ V_3 ] . V_64 ;
int V_71 ;
V_70 -> V_72 = ( V_73 | V_74 ) ;
V_71 = F_33 ( V_54 , 0 ) ;
if ( V_71 )
return 0 ;
F_16 ( V_2 , V_3 , true ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 , int V_3 ,
struct V_69 * V_75 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_69 * V_70 = & V_10 -> V_62 [ V_3 ] . V_64 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_76 ) ;
V_75 -> V_65 = V_70 -> V_65 ;
V_75 -> V_77 = ! ! ( V_16 & ( 1 << V_3 ) ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_78 ,
struct V_69 * V_75 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_69 * V_70 = & V_10 -> V_62 [ V_3 ] . V_64 ;
V_70 -> V_65 = V_75 -> V_65 ;
if ( ! V_70 -> V_65 ) {
F_16 ( V_2 , V_3 , false ) ;
} else {
V_70 -> V_65 = F_32 ( V_2 , V_3 , V_78 ) ;
if ( ! V_70 -> V_65 )
return - V_79 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_80 = 1000 ;
T_4 V_16 ;
F_13 ( V_10 , V_3 , V_81 ) ;
V_16 = F_7 ( V_10 , V_82 ) ;
V_16 |= V_83 | V_84 | V_85 ;
F_13 ( V_10 , V_16 , V_82 ) ;
do {
V_16 = F_7 ( V_10 , V_82 ) ;
if ( ! ( V_16 & V_85 ) )
break;
F_37 () ;
} while ( V_80 -- );
if ( ! V_80 )
return - V_86 ;
F_13 ( V_10 , 0 , V_82 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_3 ,
T_4 V_87 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 , V_88 ;
V_88 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_22 . V_23 ; V_5 ++ ) {
if ( ! ( ( 1 << V_5 ) & V_87 ) )
continue;
V_16 = F_7 ( V_10 , F_12 ( V_5 ) ) ;
V_16 |= 1 << V_3 ;
F_13 ( V_10 , V_16 , F_12 ( V_5 ) ) ;
V_10 -> V_62 [ V_5 ] . V_63 = V_16 ;
V_88 |= 1 << V_5 ;
}
F_13 ( V_10 , V_88 , F_12 ( V_3 ) ) ;
V_10 -> V_62 [ V_3 ] . V_63 = V_88 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_3 ,
T_4 V_87 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_5 ;
T_4 V_16 , V_88 ;
V_88 = F_7 ( V_10 , F_12 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_10 -> V_22 . V_23 ; V_5 ++ ) {
if ( ! ( ( 1 << V_5 ) & V_87 ) )
continue;
V_16 = F_7 ( V_10 , F_12 ( V_5 ) ) ;
V_16 &= ~ ( 1 << V_3 ) ;
F_13 ( V_10 , V_16 , F_12 ( V_5 ) ) ;
V_10 -> V_62 [ V_3 ] . V_63 = V_16 ;
if ( V_3 != V_5 )
V_88 &= ~ ( 1 << V_5 ) ;
}
F_13 ( V_10 , V_88 , F_12 ( V_3 ) ) ;
V_10 -> V_62 [ V_3 ] . V_63 = V_88 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , int V_3 ,
T_6 V_58 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_6 V_89 , V_90 ;
int V_71 = 0 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , F_24 ( V_3 ) ) ;
V_90 = V_16 & ( V_91 << V_92 ) ;
switch ( V_58 ) {
case V_93 :
V_89 = V_94 ;
break;
case V_95 :
V_89 = V_96 ;
break;
case V_97 :
V_89 = V_98 ;
break;
case V_99 :
V_89 = V_100 ;
break;
case V_101 :
V_89 = V_102 ;
break;
default:
F_41 ( L_2 , V_103 , V_58 ) ;
return - V_104 ;
}
if ( V_90 != V_89 ) {
if ( V_90 >= V_98 &&
V_89 <= V_96 ) {
V_71 = F_36 ( V_2 , V_3 ) ;
if ( V_71 ) {
F_41 ( L_3 , V_103 ) ;
return V_71 ;
}
}
}
V_16 = F_7 ( V_10 , F_24 ( V_3 ) ) ;
V_16 &= ~ ( V_91 << V_92 ) ;
V_16 |= V_89 ;
F_13 ( V_10 , V_16 , F_24 ( V_3 ) ) ;
return 0 ;
}
static T_7 F_42 ( int V_105 , void * V_106 )
{
struct V_9 * V_10 = V_106 ;
V_10 -> V_107 = F_43 ( V_10 , V_108 ) &
~ V_10 -> V_109 ;
F_44 ( V_10 , V_10 -> V_107 , V_68 ) ;
return V_110 ;
}
static T_7 F_45 ( int V_105 , void * V_106 )
{
struct V_9 * V_10 = V_106 ;
V_10 -> V_111 = F_46 ( V_10 , V_108 ) &
~ V_10 -> V_112 ;
F_30 ( V_10 , V_10 -> V_111 , V_68 ) ;
if ( V_10 -> V_111 & F_47 ( V_60 ) )
V_10 -> V_62 [ 7 ] . V_113 = 1 ;
if ( V_10 -> V_111 & F_48 ( V_60 ) )
V_10 -> V_62 [ 7 ] . V_113 = 0 ;
return V_110 ;
}
static int F_49 ( struct V_9 * V_10 )
{
unsigned int V_80 = 1000 ;
T_4 V_16 ;
V_16 = F_7 ( V_10 , V_114 ) ;
V_16 |= V_115 | V_116 | V_117 ;
F_13 ( V_10 , V_16 , V_114 ) ;
do {
V_16 = F_7 ( V_10 , V_114 ) ;
if ( ! ( V_16 & V_115 ) )
break;
F_50 ( 1000 , 2000 ) ;
} while ( V_80 -- > 0 );
if ( V_80 == 0 )
return - V_86 ;
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
F_44 ( V_10 , 0xffffffff , V_118 ) ;
F_44 ( V_10 , 0xffffffff , V_68 ) ;
F_44 ( V_10 , 0 , V_119 ) ;
F_30 ( V_10 , 0xffffffff , V_118 ) ;
F_30 ( V_10 , 0xffffffff , V_68 ) ;
F_30 ( V_10 , 0 , V_119 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
const char * V_120 [ V_121 ] = V_122 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_123 * V_124 ;
void T_8 * * V_125 ;
unsigned int V_3 ;
unsigned int V_5 ;
T_4 V_16 , V_126 ;
int V_71 ;
F_53 ( & V_10 -> V_127 ) ;
F_54 ( & V_10 -> V_15 ) ;
V_124 = V_2 -> V_128 -> V_129 -> V_130 ;
V_10 -> V_131 = F_55 ( V_124 , 0 ) ;
V_10 -> V_132 = F_55 ( V_124 , 1 ) ;
V_125 = & V_10 -> V_133 ;
for ( V_5 = 0 ; V_5 < V_121 ; V_5 ++ ) {
* V_125 = F_56 ( V_124 , V_5 ) ;
if ( * V_125 == NULL ) {
F_41 ( L_4 , V_120 [ V_5 ] ) ;
V_71 = - V_134 ;
goto V_135;
}
V_125 ++ ;
}
V_71 = F_49 ( V_10 ) ;
if ( V_71 ) {
F_41 ( L_5 , V_71 ) ;
goto V_135;
}
F_51 ( V_10 ) ;
V_71 = F_57 ( V_10 -> V_131 , F_42 , 0 ,
L_6 , V_10 ) ;
if ( V_71 < 0 ) {
F_41 ( L_7 ) ;
goto V_135;
}
V_71 = F_57 ( V_10 -> V_132 , F_45 , 0 ,
L_8 , V_10 ) ;
if ( V_71 < 0 ) {
F_41 ( L_9 ) ;
goto V_136;
}
V_16 = F_7 ( V_10 , V_137 ) ;
V_16 |= V_138 ;
F_13 ( V_10 , V_16 , V_137 ) ;
V_16 &= ~ V_138 ;
F_13 ( V_10 , V_16 , V_137 ) ;
V_10 -> V_22 . V_23 = F_7 ( V_10 , V_139 ) + 1 ;
if ( V_10 -> V_22 . V_23 > V_140 )
V_10 -> V_22 . V_23 = V_140 ;
if ( F_58 ( V_124 , L_10 ,
& V_10 -> V_22 . V_57 ) )
V_10 -> V_22 . V_57 = 1 ;
for ( V_3 = 0 ; V_3 < V_10 -> V_22 . V_23 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_23 ( V_2 , V_3 , NULL ) ;
else if ( F_31 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
else
F_28 ( V_2 , V_3 , NULL ) ;
}
if ( F_59 ( L_11 ) )
V_2 -> V_141 |= ( ( 1 << V_142 ) | ( 1 << 0 ) ) ;
else
V_2 -> V_141 = 0 ;
V_126 = F_18 ( V_10 , V_143 ) ;
V_10 -> V_22 . V_144 = ( V_126 >> V_145 ) &
V_146 ;
V_10 -> V_22 . V_147 = ( V_126 & V_148 ) ;
V_126 = F_18 ( V_10 , V_149 ) ;
V_10 -> V_22 . V_150 = V_126 & V_151 ;
F_60 ( L_12 ,
V_10 -> V_22 . V_144 >> 8 , V_10 -> V_22 . V_144 & 0xff ,
V_10 -> V_22 . V_147 >> 8 , V_10 -> V_22 . V_147 & 0xff ,
V_10 -> V_133 , V_10 -> V_131 , V_10 -> V_132 ) ;
return 0 ;
V_136:
F_61 ( V_10 -> V_131 , V_10 ) ;
V_135:
V_125 = & V_10 -> V_133 ;
for ( V_5 = 0 ; V_5 < V_121 ; V_5 ++ ) {
if ( * V_125 )
F_62 ( * V_125 ) ;
V_125 ++ ;
}
return V_71 ;
}
static int F_63 ( struct V_1 * V_2 , T_6 * V_152 )
{
return 0 ;
}
static T_4 F_64 ( struct V_1 * V_2 , int V_3 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
return V_10 -> V_22 . V_150 ;
}
static int F_65 ( struct V_1 * V_2 , int V_153 , int V_152 ,
int V_154 , T_9 V_13 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
int V_71 = 0 ;
T_4 V_16 ;
V_16 = F_18 ( V_10 , V_155 ) ;
V_16 |= V_156 ;
F_19 ( V_10 , V_16 , V_155 ) ;
V_16 = 0x70 ;
V_16 <<= 2 ;
F_13 ( V_10 , V_152 , V_16 ) ;
V_16 = 0x80 << 8 | V_154 << 1 ;
V_16 <<= 2 ;
if ( V_153 )
V_71 = F_7 ( V_10 , V_16 ) ;
else
F_13 ( V_10 , V_13 , V_16 ) ;
V_16 = F_18 ( V_10 , V_155 ) ;
V_16 &= ~ V_156 ;
F_19 ( V_10 , V_16 , V_155 ) ;
return V_71 & 0xffff ;
}
static int F_66 ( struct V_1 * V_2 , int V_152 , int V_154 )
{
switch ( V_152 ) {
case 0 :
case V_142 :
return F_65 ( V_2 , 1 , V_152 , V_154 , 0 ) ;
default:
return 0xffff ;
}
}
static int F_67 ( struct V_1 * V_2 , int V_152 , int V_154 ,
T_9 V_13 )
{
switch ( V_152 ) {
case 0 :
case V_142 :
F_65 ( V_2 , 0 , V_152 , V_154 , V_13 ) ;
break;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , int V_3 ,
struct V_53 * V_78 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_157 = 0 , V_158 ;
const char * V_159 = NULL ;
T_4 V_16 ;
switch ( V_78 -> V_160 ) {
case V_161 :
V_159 = L_13 ;
V_157 = 1 ;
case V_162 :
if ( ! V_159 )
V_159 = L_14 ;
V_158 = V_163 ;
break;
case V_164 :
V_159 = L_15 ;
V_158 = V_165 ;
break;
case V_166 :
V_159 = L_16 ;
V_158 = V_167 ;
break;
default:
goto V_168;
}
if ( ! V_78 -> V_113 ) {
V_16 = F_18 ( V_10 , F_69 ( V_3 ) ) ;
V_16 &= ~ V_169 ;
F_19 ( V_10 , V_16 , F_69 ( V_3 ) ) ;
goto V_168;
}
V_16 = F_18 ( V_10 , F_69 ( V_3 ) ) ;
V_16 &= ~ V_170 ;
V_16 &= ~ ( V_171 << V_172 ) ;
V_16 &= ~ ( V_173 | V_174 ) ;
V_16 |= V_158 | V_169 ;
if ( V_157 )
V_16 |= V_170 ;
if ( V_78 -> V_175 ) {
if ( V_78 -> V_176 )
V_16 |= V_174 ;
V_16 |= V_173 ;
}
F_19 ( V_10 , V_16 , F_69 ( V_3 ) ) ;
F_60 ( L_17 , V_3 , V_159 ) ;
V_168:
V_16 = V_177 ;
switch ( V_78 -> V_178 ) {
case V_179 :
V_16 |= V_180 << V_181 ;
break;
case V_182 :
V_16 |= V_183 << V_181 ;
break;
}
if ( V_78 -> V_113 )
V_16 |= V_44 ;
if ( V_78 -> V_184 == V_185 )
V_16 |= V_186 ;
F_13 ( V_10 , V_16 , F_70 ( V_3 ) ) ;
}
static void F_71 ( struct V_1 * V_2 , int V_3 ,
struct V_187 * V_188 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_4 V_184 , V_175 ;
T_4 V_16 ;
V_184 = F_7 ( V_10 , V_189 ) ;
V_175 = F_7 ( V_10 , V_190 ) ;
V_188 -> V_113 = 0 ;
if ( V_3 == 7 ) {
V_188 -> V_113 = V_10 -> V_62 [ V_3 ] . V_113 ;
if ( ! V_188 -> V_113 )
F_72 ( V_2 -> V_191 [ V_3 ] ) ;
V_188 -> V_184 = 1 ;
} else {
V_188 -> V_113 = 1 ;
V_188 -> V_184 = ! ! ( V_184 & ( 1 << V_3 ) ) ;
}
V_16 = F_7 ( V_10 , F_70 ( V_3 ) ) ;
V_16 |= V_177 ;
if ( V_188 -> V_113 )
V_16 |= V_44 ;
else
V_16 &= ~ V_44 ;
F_13 ( V_10 , V_16 , F_70 ( V_3 ) ) ;
if ( ( V_175 & ( 1 << V_3 ) ) &&
( V_175 & ( 1 << ( V_3 + V_192 ) ) ) ) {
V_188 -> V_176 = 1 ;
V_188 -> V_175 = 1 ;
}
if ( V_175 & ( 1 << V_3 ) )
V_188 -> V_175 = 1 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
F_51 ( V_10 ) ;
for ( V_3 = 0 ; V_3 < V_140 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 ||
F_31 ( V_2 , V_3 ) )
F_28 ( V_2 , V_3 , NULL ) ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_3 ( V_2 ) ;
unsigned int V_3 ;
int V_71 ;
V_71 = F_49 ( V_10 ) ;
if ( V_71 ) {
F_41 ( L_18 , V_103 ) ;
return V_71 ;
}
if ( V_10 -> V_22 . V_57 == 1 )
F_17 ( V_2 , true ) ;
for ( V_3 = 0 ; V_3 < V_140 ; V_3 ++ ) {
if ( ( 1 << V_3 ) & V_2 -> V_24 )
F_23 ( V_2 , V_3 , NULL ) ;
else if ( F_31 ( V_2 , V_3 ) )
F_14 ( V_2 , V_3 ) ;
}
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , int V_3 ,
struct V_193 * V_194 )
{
struct V_195 * V_70 = V_2 -> V_55 [ V_2 -> V_56 ] . V_196 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
struct V_193 V_197 ;
V_70 -> V_198 -> V_199 ( V_70 , & V_197 ) ;
V_194 -> V_72 = V_197 . V_72 ;
memset ( & V_194 -> V_200 , 0 , sizeof( V_194 -> V_200 ) ) ;
if ( V_197 . V_201 & V_202 )
memcpy ( & V_194 -> V_200 , V_197 . V_200 , sizeof( V_194 -> V_200 ) ) ;
if ( V_10 -> V_67 & ( 1 << V_3 ) )
V_194 -> V_201 = V_197 . V_201 ;
else
V_194 -> V_201 = 0 ;
}
static int F_76 ( struct V_1 * V_2 , int V_3 ,
struct V_193 * V_194 )
{
struct V_195 * V_70 = V_2 -> V_55 [ V_2 -> V_56 ] . V_196 ;
struct V_9 * V_10 = F_3 ( V_2 ) ;
T_5 V_21 = V_2 -> V_55 [ V_2 -> V_56 ] . V_21 ;
struct V_193 V_197 ;
V_70 -> V_198 -> V_199 ( V_70 , & V_197 ) ;
if ( V_194 -> V_201 & ~ V_197 . V_72 )
return - V_104 ;
if ( V_194 -> V_201 )
V_10 -> V_67 |= ( 1 << V_3 ) ;
else
V_10 -> V_67 &= ~ ( 1 << V_3 ) ;
if ( V_10 -> V_67 && V_10 -> V_67 != ( 1 << V_21 ) )
V_10 -> V_67 |= ( 1 << V_21 ) ;
else
V_10 -> V_67 &= ~ ( 1 << V_21 ) ;
return V_70 -> V_198 -> V_203 ( V_70 , V_194 ) ;
}
static int T_10 F_77 ( void )
{
F_78 ( & V_204 ) ;
return 0 ;
}
static void T_11 F_79 ( void )
{
F_80 ( & V_204 ) ;
}
