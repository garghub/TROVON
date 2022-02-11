static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . type == V_5 ;
}
static struct V_6 * F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . V_4 . V_7 ;
}
static struct V_1 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_4 ) ;
}
int
F_7 ( struct V_1 * V_1 )
{
int V_10 = V_1 -> V_11 [ V_12 ] ;
struct V_6 * V_7 = V_1 -> V_13 -> V_4 . V_7 ;
switch ( V_10 ) {
case V_14 :
case V_15 :
break;
case V_16 :
if ( ( ( F_8 ( V_7 ) && ! F_9 ( V_7 ) ) ||
F_10 ( V_7 ) -> V_17 >= 8 ) &&
V_1 -> V_11 [ V_18 ] >= 0x12 )
V_10 = V_16 ;
else
V_10 = V_15 ;
break;
default:
F_11 ( 1 , L_1 ,
V_10 ) ;
V_10 = V_14 ;
break;
}
return V_10 ;
}
static T_1 F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_19 , V_20 ;
V_19 = 4 ;
if ( F_13 ( V_7 ) && V_3 -> V_21 == V_22 &&
( V_3 -> V_23 & V_24 ) == 0 )
V_19 = 2 ;
V_20 = F_14 ( V_1 -> V_11 ) ;
return F_15 ( V_19 , V_20 ) ;
}
static int
F_16 ( int V_25 , int V_26 )
{
return ( V_25 * V_26 + 9 ) / 10 ;
}
static int
F_17 ( int V_27 , int V_28 )
{
return ( V_27 * V_28 * 8 ) / 10 ;
}
static enum V_29
F_18 ( struct V_8 * V_9 ,
struct V_30 * V_31 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_30 * V_33 = V_32 -> V_34 . V_33 ;
int V_35 = V_31 -> clock ;
int V_36 , V_37 , V_28 , V_27 ;
if ( F_1 ( V_1 ) && V_33 ) {
if ( V_31 -> V_38 > V_33 -> V_38 )
return V_39 ;
if ( V_31 -> V_40 > V_33 -> V_40 )
return V_39 ;
V_35 = V_33 -> clock ;
}
V_27 = F_20 ( F_7 ( V_1 ) ) ;
V_28 = F_12 ( V_1 ) ;
V_36 = F_17 ( V_27 , V_28 ) ;
V_37 = F_16 ( V_35 , 18 ) ;
if ( V_37 > V_36 )
return V_41 ;
if ( V_31 -> clock < 10000 )
return V_42 ;
if ( V_31 -> V_43 & V_44 )
return V_45 ;
return V_46 ;
}
static T_2
F_21 ( T_3 * V_47 , int V_48 )
{
int V_49 ;
T_2 V_50 = 0 ;
if ( V_48 > 4 )
V_48 = 4 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ )
V_50 |= ( ( T_2 ) V_47 [ V_49 ] ) << ( ( 3 - V_49 ) * 8 ) ;
return V_50 ;
}
static void
F_22 ( T_2 V_47 , T_3 * V_51 , int V_52 )
{
int V_49 ;
if ( V_52 > 4 )
V_52 = 4 ;
for ( V_49 = 0 ; V_49 < V_52 ; V_49 ++ )
V_51 [ V_49 ] = V_47 >> ( ( 3 - V_49 ) * 8 ) ;
}
static int
F_23 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_56 ;
if ( F_24 ( V_7 ) )
return 200 ;
V_56 = F_25 ( V_57 ) ;
switch ( V_56 & V_58 ) {
case V_59 :
return 100 ;
case V_60 :
return 133 ;
case V_61 :
return 166 ;
case V_62 :
return 200 ;
case V_63 :
return 266 ;
case V_64 :
return 333 ;
case V_65 :
case V_66 :
return 400 ;
default:
return 133 ;
}
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_68 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
V_70 = F_27 ( V_68 ) ;
F_28 ( V_54 , V_70 ) ;
F_29 ( & V_54 -> V_71 ) ;
}
static void F_30 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_68 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
F_31 ( & V_54 -> V_71 ) ;
V_70 = F_27 ( V_68 ) ;
F_32 ( V_54 , V_70 ) ;
}
static enum V_72
F_33 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_67 * V_68 ;
unsigned int V_73 = ( 1 << V_74 ) | ( 1 << V_75 ) ;
struct V_76 V_77 ;
F_34 ( & V_54 -> V_71 ) ;
if ( V_1 -> V_78 != V_79 )
return V_1 -> V_78 ;
F_35 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_80 ;
if ( V_68 -> type != V_5 )
continue;
V_80 = F_5 ( & V_68 -> V_4 ) ;
if ( V_80 -> V_78 != V_79 )
V_73 &= ~ ( 1 << V_80 -> V_78 ) ;
}
if ( F_36 ( V_73 == 0 ) )
return V_74 ;
V_1 -> V_78 = F_37 ( V_73 ) - 1 ;
F_38 ( L_2 ,
F_39 ( V_1 -> V_78 ) ,
F_40 ( V_3 -> V_21 ) ) ;
F_41 ( V_7 , V_1 , & V_77 ) ;
F_42 ( V_7 , V_1 ,
& V_77 ) ;
return V_1 -> V_78 ;
}
static bool F_43 ( struct V_53 * V_54 ,
enum V_72 V_72 )
{
return F_25 ( F_44 ( V_72 ) ) & V_81 ;
}
static bool F_45 ( struct V_53 * V_54 ,
enum V_72 V_72 )
{
return F_25 ( F_46 ( V_72 ) ) & V_82 ;
}
static bool F_47 ( struct V_53 * V_54 ,
enum V_72 V_72 )
{
return true ;
}
static enum V_72
F_48 ( struct V_53 * V_54 ,
enum V_21 V_21 ,
T_4 V_83 )
{
enum V_72 V_72 ;
for ( V_72 = V_74 ; V_72 <= V_75 ; V_72 ++ ) {
T_5 V_84 = F_25 ( F_49 ( V_72 ) ) &
V_85 ;
if ( V_84 != F_50 ( V_21 ) )
continue;
if ( ! V_83 ( V_54 , V_72 ) )
continue;
return V_72 ;
}
return V_79 ;
}
static void
F_51 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_76 V_77 ;
enum V_21 V_21 = V_3 -> V_21 ;
F_34 ( & V_54 -> V_71 ) ;
V_1 -> V_78 = F_48 ( V_54 , V_21 ,
F_43 ) ;
if ( V_1 -> V_78 == V_79 )
V_1 -> V_78 = F_48 ( V_54 , V_21 ,
F_45 ) ;
if ( V_1 -> V_78 == V_79 )
V_1 -> V_78 = F_48 ( V_54 , V_21 ,
F_47 ) ;
if ( V_1 -> V_78 == V_79 ) {
F_38 ( L_3 ,
F_40 ( V_21 ) ) ;
return;
}
F_38 ( L_4 ,
F_40 ( V_21 ) , F_39 ( V_1 -> V_78 ) ) ;
F_41 ( V_7 , V_1 , & V_77 ) ;
F_42 ( V_7 , V_1 ,
& V_77 ) ;
}
void F_52 ( struct V_53 * V_54 )
{
struct V_6 * V_7 = V_54 -> V_7 ;
struct V_67 * V_68 ;
if ( F_36 ( ! F_24 ( V_7 ) ) )
return;
F_35 (encoder, &dev->mode_config.encoder_list, base.head) {
struct V_1 * V_1 ;
if ( V_68 -> type != V_5 )
continue;
V_1 = F_5 ( & V_68 -> V_4 ) ;
V_1 -> V_78 = V_79 ;
}
}
static T_5 F_53 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_54 ( V_7 ) )
return V_86 ;
else
return F_46 ( F_33 ( V_1 ) ) ;
}
static T_5 F_55 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_54 ( V_7 ) )
return V_87 ;
else
return F_44 ( F_33 ( V_1 ) ) ;
}
static int F_56 ( struct V_88 * V_89 , unsigned long V_90 ,
void * V_91 )
{
struct V_1 * V_1 = F_57 ( V_89 , F_58 ( * V_1 ) ,
V_92 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_93 ;
T_5 V_94 , V_95 ;
if ( ! F_1 ( V_1 ) || V_90 != V_96 )
return 0 ;
F_26 ( V_1 ) ;
if ( F_24 ( V_7 ) ) {
enum V_72 V_72 = F_33 ( V_1 ) ;
V_94 = F_46 ( V_72 ) ;
V_95 = F_59 ( V_72 ) ;
V_93 = F_25 ( V_95 ) ;
V_93 &= V_97 ;
F_60 ( V_95 , V_93 | 0x1F ) ;
F_60 ( V_94 , V_98 | V_99 ) ;
F_61 ( V_1 -> V_100 ) ;
}
F_30 ( V_1 ) ;
return 0 ;
}
static bool F_62 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_34 ( & V_54 -> V_71 ) ;
return ( F_25 ( F_55 ( V_1 ) ) & V_81 ) != 0 ;
}
static bool F_63 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_34 ( & V_54 -> V_71 ) ;
return F_25 ( F_53 ( V_1 ) ) & V_82 ;
}
static void
F_64 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_62 ( V_1 ) && ! F_63 ( V_1 ) ) {
F_11 ( 1 , L_5 ) ;
F_38 ( L_6 ,
F_25 ( F_55 ( V_1 ) ) ,
F_25 ( F_53 ( V_1 ) ) ) ;
}
}
static T_2
F_65 ( struct V_1 * V_1 , bool V_101 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_102 = V_1 -> V_103 ;
T_2 V_104 ;
bool V_105 ;
#define F_66 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_101 )
V_105 = F_67 ( V_54 -> V_106 , F_66 ,
F_68 ( 10 ) ) ;
else
V_105 = F_69 ( F_66 , 10 ) == 0 ;
if ( ! V_105 )
F_70 ( L_7 ,
V_101 ) ;
#undef F_66
return V_104 ;
}
static T_2 F_71 ( struct V_1 * V_1 , int V_107 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
return V_107 ? 0 : F_23 ( V_7 ) / 2 ;
}
static T_2 F_72 ( struct V_1 * V_1 , int V_107 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
if ( V_107 )
return 0 ;
if ( V_3 -> V_21 == V_22 ) {
if ( F_73 ( V_7 ) || F_74 ( V_7 ) )
return 200 ;
else
return 225 ;
} else {
return F_75 ( F_76 ( V_7 ) , 2 ) ;
}
}
static T_2 F_77 ( struct V_1 * V_1 , int V_107 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_3 -> V_21 == V_22 ) {
if ( V_107 )
return 0 ;
return F_78 ( F_79 ( V_54 ) , 2000 ) ;
} else if ( V_54 -> V_108 == V_109 ) {
switch ( V_107 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else {
return V_107 ? 0 : F_75 ( F_76 ( V_7 ) , 2 ) ;
}
}
static T_2 F_80 ( struct V_1 * V_1 , int V_107 )
{
return V_107 ? 0 : 100 ;
}
static T_2 F_81 ( struct V_1 * V_1 ,
bool V_101 ,
int V_110 ,
T_2 V_111 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_112 , V_113 ;
if ( F_73 ( V_7 ) )
V_112 = 3 ;
else
V_112 = 5 ;
if ( F_82 ( V_7 ) && V_1 -> V_103 == V_114 )
V_113 = V_115 ;
else
V_113 = V_116 ;
return V_117 |
V_118 |
( V_101 ? V_119 : 0 ) |
V_120 |
V_113 |
V_121 |
( V_110 << V_122 ) |
( V_112 << V_123 ) |
( V_111 << V_124 ) ;
}
static int
F_83 ( struct V_1 * V_1 ,
T_3 * V_125 , int V_110 ,
T_3 * V_126 , int V_127 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_102 = V_1 -> V_103 ;
T_2 V_128 = V_102 + 4 ;
T_2 V_111 ;
int V_49 , V_129 , V_130 ;
T_2 V_104 ;
int V_131 , clock = 0 ;
bool V_101 = F_84 ( V_7 ) ;
bool V_132 ;
F_26 ( V_1 ) ;
V_132 = F_85 ( V_1 ) ;
F_86 ( & V_54 -> V_133 , 0 ) ;
F_64 ( V_1 ) ;
F_87 ( V_54 ) ;
for ( V_131 = 0 ; V_131 < 3 ; V_131 ++ ) {
V_104 = F_88 ( V_102 ) ;
if ( ( V_104 & V_117 ) == 0 )
break;
F_61 ( 1 ) ;
}
if ( V_131 == 3 ) {
F_11 ( 1 , L_8 ,
F_25 ( V_102 ) ) ;
V_129 = - V_134 ;
goto V_135;
}
if ( F_36 ( V_110 > 20 || V_127 > 20 ) ) {
V_129 = - V_136 ;
goto V_135;
}
while ( ( V_111 = V_1 -> V_137 ( V_1 , clock ++ ) ) ) {
T_5 V_138 = V_1 -> V_139 ( V_1 ,
V_101 ,
V_110 ,
V_111 ) ;
for ( V_131 = 0 ; V_131 < 5 ; V_131 ++ ) {
for ( V_49 = 0 ; V_49 < V_110 ; V_49 += 4 )
F_60 ( V_128 + V_49 ,
F_21 ( V_125 + V_49 , V_110 - V_49 ) ) ;
F_60 ( V_102 , V_138 ) ;
V_104 = F_65 ( V_1 , V_101 ) ;
F_60 ( V_102 ,
V_104 |
V_118 |
V_120 |
V_121 ) ;
if ( V_104 & ( V_120 |
V_121 ) )
continue;
if ( V_104 & V_118 )
break;
}
if ( V_104 & V_118 )
break;
}
if ( ( V_104 & V_118 ) == 0 ) {
F_70 ( L_9 , V_104 ) ;
V_129 = - V_134 ;
goto V_135;
}
if ( V_104 & V_121 ) {
F_70 ( L_10 , V_104 ) ;
V_129 = - V_140 ;
goto V_135;
}
if ( V_104 & V_120 ) {
F_38 ( L_11 , V_104 ) ;
V_129 = - V_141 ;
goto V_135;
}
V_130 = ( ( V_104 & V_142 ) >>
V_122 ) ;
if ( V_130 > V_127 )
V_130 = V_127 ;
for ( V_49 = 0 ; V_49 < V_130 ; V_49 += 4 )
F_22 ( F_25 ( V_128 + V_49 ) ,
V_126 + V_49 , V_130 - V_49 ) ;
V_129 = V_130 ;
V_135:
F_86 ( & V_54 -> V_133 , V_143 ) ;
F_89 ( V_54 ) ;
if ( V_132 )
F_90 ( V_1 , false ) ;
F_30 ( V_1 ) ;
return V_129 ;
}
static T_6
F_91 ( struct V_144 * V_145 , struct V_146 * V_147 )
{
struct V_1 * V_1 = F_57 ( V_145 , struct V_1 , V_145 ) ;
T_3 V_148 [ 20 ] , V_149 [ 20 ] ;
T_7 V_150 , V_151 ;
int V_129 ;
V_148 [ 0 ] = V_147 -> V_152 << 4 ;
V_148 [ 1 ] = V_147 -> V_153 >> 8 ;
V_148 [ 2 ] = V_147 -> V_153 & 0xff ;
V_148 [ 3 ] = V_147 -> V_154 - 1 ;
switch ( V_147 -> V_152 & ~ V_155 ) {
case V_156 :
case V_157 :
V_150 = V_147 -> V_154 ? V_158 + V_147 -> V_154 : V_159 ;
V_151 = 1 ;
if ( F_36 ( V_150 > 20 ) )
return - V_136 ;
memcpy ( V_148 + V_158 , V_147 -> V_160 , V_147 -> V_154 ) ;
V_129 = F_83 ( V_1 , V_148 , V_150 , V_149 , V_151 ) ;
if ( V_129 > 0 ) {
V_147 -> V_161 = V_149 [ 0 ] >> 4 ;
V_129 = V_147 -> V_154 ;
}
break;
case V_162 :
case V_163 :
V_150 = V_147 -> V_154 ? V_158 : V_159 ;
V_151 = V_147 -> V_154 + 1 ;
if ( F_36 ( V_151 > 20 ) )
return - V_136 ;
V_129 = F_83 ( V_1 , V_148 , V_150 , V_149 , V_151 ) ;
if ( V_129 > 0 ) {
V_147 -> V_161 = V_149 [ 0 ] >> 4 ;
V_129 -- ;
memcpy ( V_147 -> V_160 , V_149 + 1 , V_129 ) ;
}
break;
default:
V_129 = - V_164 ;
break;
}
return V_129 ;
}
static void
F_92 ( struct V_1 * V_1 , struct V_32 * V_9 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
const char * V_165 = NULL ;
int V_129 ;
switch ( V_21 ) {
case V_22 :
V_1 -> V_103 = V_114 ;
V_165 = L_12 ;
break;
case V_166 :
V_1 -> V_103 = V_167 ;
V_165 = L_13 ;
break;
case V_168 :
V_1 -> V_103 = V_169 ;
V_165 = L_14 ;
break;
case V_170 :
V_1 -> V_103 = V_171 ;
V_165 = L_15 ;
break;
default:
F_93 () ;
}
if ( ! F_13 ( V_7 ) )
V_1 -> V_103 = V_1 -> V_172 + 0x10 ;
V_1 -> V_145 . V_165 = V_165 ;
V_1 -> V_145 . V_7 = V_7 -> V_7 ;
V_1 -> V_145 . V_173 = F_91 ;
F_38 ( L_16 , V_165 ,
V_9 -> V_4 . V_174 -> V_175 . V_165 ) ;
V_129 = F_94 ( & V_1 -> V_145 ) ;
if ( V_129 < 0 ) {
F_70 ( L_17 ,
V_165 , V_129 ) ;
return;
}
V_129 = F_95 ( & V_9 -> V_4 . V_174 -> V_175 ,
& V_1 -> V_145 . V_176 . V_7 . V_175 ,
V_1 -> V_145 . V_176 . V_7 . V_175 . V_165 ) ;
if ( V_129 < 0 ) {
F_70 ( L_18 , V_165 , V_129 ) ;
F_96 ( & V_1 -> V_145 ) ;
}
}
static void
F_97 ( struct V_32 * V_32 )
{
struct V_1 * V_1 = F_4 ( & V_32 -> V_4 ) ;
if ( ! V_32 -> V_177 )
F_98 ( & V_32 -> V_4 . V_174 -> V_175 ,
V_1 -> V_145 . V_176 . V_7 . V_175 . V_165 ) ;
F_99 ( V_32 ) ;
}
static void
F_100 ( struct V_178 * V_179 , int V_180 )
{
switch ( V_180 ) {
case V_14 :
V_179 -> V_181 = V_182 ;
break;
case V_15 :
V_179 -> V_181 = V_183 ;
break;
case V_16 :
V_179 -> V_181 = V_184 ;
break;
}
}
static void
F_101 ( struct V_67 * V_68 ,
struct V_178 * V_179 , int V_180 )
{
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
const struct V_185 * V_186 = NULL ;
int V_49 , V_187 = 0 ;
if ( F_102 ( V_7 ) ) {
V_186 = V_188 ;
V_187 = F_103 ( V_188 ) ;
} else if ( F_54 ( V_7 ) ) {
V_186 = V_189 ;
V_187 = F_103 ( V_189 ) ;
} else if ( F_104 ( V_7 ) ) {
V_186 = V_190 ;
V_187 = F_103 ( V_190 ) ;
} else if ( F_24 ( V_7 ) ) {
V_186 = V_191 ;
V_187 = F_103 ( V_191 ) ;
}
if ( V_186 && V_187 ) {
for ( V_49 = 0 ; V_49 < V_187 ; V_49 ++ ) {
if ( V_180 == V_186 [ V_49 ] . V_180 ) {
V_179 -> V_192 = V_186 [ V_49 ] . V_192 ;
V_179 -> V_193 = true ;
break;
}
}
}
}
bool
F_105 ( struct V_67 * V_68 ,
struct V_178 * V_179 )
{
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_194 = & V_179 -> V_194 ;
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_195 * V_195 = V_68 -> V_196 ;
struct V_32 * V_32 = V_1 -> V_13 ;
int V_197 , clock ;
int V_198 = 1 ;
int V_199 = F_12 ( V_1 ) ;
int V_200 = 0 ;
int V_201 = F_7 ( V_1 ) >> 3 ;
int V_26 , V_37 ;
static int V_202 [] = { V_14 , V_15 , V_16 } ;
int V_203 , V_204 ;
if ( F_54 ( V_7 ) && ! F_13 ( V_7 ) && V_21 != V_22 )
V_179 -> V_205 = true ;
V_179 -> V_206 = true ;
V_179 -> V_207 = false ;
V_179 -> V_208 = V_1 -> V_208 ;
if ( F_1 ( V_1 ) && V_32 -> V_34 . V_33 ) {
F_106 ( V_32 -> V_34 . V_33 ,
V_194 ) ;
if ( ! F_54 ( V_7 ) )
F_107 ( V_195 , V_179 ,
V_32 -> V_34 . V_209 ) ;
else
F_108 ( V_195 , V_179 ,
V_32 -> V_34 . V_209 ) ;
}
if ( V_194 -> V_43 & V_44 )
return false ;
F_38 ( L_19
L_20 ,
V_199 , V_202 [ V_201 ] ,
V_194 -> V_210 ) ;
V_26 = V_179 -> V_211 ;
if ( F_1 ( V_1 ) ) {
if ( V_54 -> V_212 . V_213 && V_54 -> V_212 . V_213 < V_26 ) {
F_38 ( L_21 ,
V_54 -> V_212 . V_213 ) ;
V_26 = V_54 -> V_212 . V_213 ;
}
V_198 = V_199 ;
V_200 = V_201 ;
}
for (; V_26 >= 6 * 3 ; V_26 -= 2 * 3 ) {
V_37 = F_16 ( V_194 -> V_210 ,
V_26 ) ;
for ( clock = V_200 ; clock <= V_201 ; clock ++ ) {
for ( V_197 = V_198 ; V_197 <= V_199 ; V_197 <<= 1 ) {
V_204 = F_20 ( V_202 [ clock ] ) ;
V_203 = F_17 ( V_204 ,
V_197 ) ;
if ( V_37 <= V_203 ) {
goto V_214;
}
}
}
}
return false ;
V_214:
if ( V_1 -> V_215 ) {
if ( V_26 != 18 && F_109 ( V_194 ) > 1 )
V_1 -> V_216 = V_217 ;
else
V_1 -> V_216 = 0 ;
}
if ( V_1 -> V_216 )
V_179 -> V_218 = true ;
V_1 -> V_180 = V_202 [ clock ] ;
V_1 -> V_197 = V_197 ;
V_179 -> V_211 = V_26 ;
V_179 -> V_219 = F_20 ( V_1 -> V_180 ) ;
F_38 ( L_22 ,
V_1 -> V_180 , V_1 -> V_197 ,
V_179 -> V_219 , V_26 ) ;
F_38 ( L_23 ,
V_37 , V_203 ) ;
F_110 ( V_26 , V_197 ,
V_194 -> V_210 ,
V_179 -> V_219 ,
& V_179 -> V_220 ) ;
if ( V_32 -> V_34 . V_221 != NULL &&
V_1 -> V_222 . type == V_223 ) {
V_179 -> V_207 = true ;
F_110 ( V_26 , V_197 ,
V_32 -> V_34 . V_221 -> clock ,
V_179 -> V_219 ,
& V_179 -> V_224 ) ;
}
if ( F_8 ( V_7 ) || F_82 ( V_7 ) )
F_100 ( V_179 , V_1 -> V_180 ) ;
else
F_101 ( V_68 , V_179 , V_1 -> V_180 ) ;
return true ;
}
static void F_111 ( struct V_1 * V_1 )
{
struct V_2 * V_225 = F_2 ( V_1 ) ;
struct V_195 * V_226 = F_112 ( V_225 -> V_4 . V_4 . V_226 ) ;
struct V_6 * V_7 = V_226 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_227 ;
F_38 ( L_24 , V_226 -> V_228 . V_219 ) ;
V_227 = F_25 ( V_229 ) ;
V_227 &= ~ V_230 ;
if ( V_226 -> V_228 . V_219 == 162000 ) {
F_38 ( L_25 ) ;
V_227 |= V_231 ;
V_1 -> V_232 |= V_231 ;
} else {
V_227 |= V_233 ;
V_1 -> V_232 |= V_233 ;
}
F_60 ( V_229 , V_227 ) ;
F_113 ( V_229 ) ;
F_114 ( 500 ) ;
}
static void F_115 ( struct V_67 * V_68 )
{
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_195 * V_226 = F_112 ( V_68 -> V_4 . V_226 ) ;
struct V_30 * V_194 = & V_226 -> V_228 . V_194 ;
V_1 -> V_232 = F_25 ( V_1 -> V_172 ) & V_234 ;
V_1 -> V_232 |= V_235 | V_236 ;
V_1 -> V_232 |= F_116 ( V_1 -> V_197 ) ;
if ( V_226 -> V_228 . V_208 ) {
F_117 ( L_26 ,
F_39 ( V_226 -> V_72 ) ) ;
V_1 -> V_232 |= V_237 ;
F_118 ( & V_68 -> V_4 , V_194 ) ;
}
if ( V_21 == V_22 && F_74 ( V_7 ) && ! F_24 ( V_7 ) ) {
if ( V_194 -> V_43 & V_238 )
V_1 -> V_232 |= V_239 ;
if ( V_194 -> V_43 & V_240 )
V_1 -> V_232 |= V_241 ;
V_1 -> V_232 |= V_242 ;
if ( F_119 ( V_1 -> V_11 ) )
V_1 -> V_232 |= V_243 ;
V_1 -> V_232 |= V_226 -> V_72 << 29 ;
} else if ( ! F_120 ( V_7 ) || V_21 == V_22 ) {
if ( ! F_54 ( V_7 ) && ! F_24 ( V_7 ) )
V_1 -> V_232 |= V_1 -> V_216 ;
if ( V_194 -> V_43 & V_238 )
V_1 -> V_232 |= V_239 ;
if ( V_194 -> V_43 & V_240 )
V_1 -> V_232 |= V_241 ;
V_1 -> V_232 |= V_244 ;
if ( F_119 ( V_1 -> V_11 ) )
V_1 -> V_232 |= V_243 ;
if ( ! F_104 ( V_7 ) ) {
if ( V_226 -> V_72 == 1 )
V_1 -> V_232 |= V_245 ;
} else {
V_1 -> V_232 |= F_121 ( V_226 -> V_72 ) ;
}
} else {
V_1 -> V_232 |= V_242 ;
}
}
static void F_122 ( struct V_1 * V_1 ,
T_5 V_246 ,
T_5 V_247 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_248 , V_94 ;
F_34 ( & V_54 -> V_71 ) ;
V_248 = F_55 ( V_1 ) ;
V_94 = F_53 ( V_1 ) ;
F_38 ( L_27 ,
V_246 , V_247 ,
F_25 ( V_248 ) ,
F_25 ( V_94 ) ) ;
if ( F_123 ( ( F_25 ( V_248 ) & V_246 ) == V_247 , 5000 , 10 ) ) {
F_70 ( L_28 ,
F_25 ( V_248 ) ,
F_25 ( V_94 ) ) ;
}
F_38 ( L_29 ) ;
}
static void F_124 ( struct V_1 * V_1 )
{
F_38 ( L_30 ) ;
F_122 ( V_1 , V_249 , V_250 ) ;
}
static void F_125 ( struct V_1 * V_1 )
{
F_38 ( L_31 ) ;
F_122 ( V_1 , V_251 , V_252 ) ;
}
static void F_126 ( struct V_1 * V_1 )
{
F_38 ( L_32 ) ;
F_127 ( V_1 -> V_253 ,
V_1 -> V_100 ) ;
F_122 ( V_1 , V_254 , V_255 ) ;
}
static void F_128 ( struct V_1 * V_1 )
{
F_127 ( V_1 -> V_256 ,
V_1 -> V_257 ) ;
}
static void F_129 ( struct V_1 * V_1 )
{
F_127 ( V_1 -> V_258 ,
V_1 -> V_259 ) ;
}
static T_5 F_130 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_260 ;
F_34 ( & V_54 -> V_71 ) ;
V_260 = F_25 ( F_53 ( V_1 ) ) ;
V_260 &= ~ V_261 ;
V_260 |= V_98 ;
return V_260 ;
}
static bool F_85 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
T_5 V_262 ;
T_5 V_248 , V_94 ;
bool V_263 = ! V_1 -> V_264 ;
F_34 ( & V_54 -> V_71 ) ;
if ( ! F_1 ( V_1 ) )
return false ;
V_1 -> V_264 = true ;
if ( F_63 ( V_1 ) )
return V_263 ;
V_70 = F_27 ( V_67 ) ;
F_28 ( V_54 , V_70 ) ;
F_38 ( L_33 ) ;
if ( ! F_62 ( V_1 ) )
F_126 ( V_1 ) ;
V_262 = F_130 ( V_1 ) ;
V_262 |= V_82 ;
V_248 = F_55 ( V_1 ) ;
V_94 = F_53 ( V_1 ) ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
F_38 ( L_34 ,
F_25 ( V_248 ) , F_25 ( V_94 ) ) ;
if ( ! F_62 ( V_1 ) ) {
F_38 ( L_35 ) ;
F_61 ( V_1 -> V_265 ) ;
}
return V_263 ;
}
void F_131 ( struct V_1 * V_1 )
{
bool V_132 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( V_1 ) ;
V_132 = F_85 ( V_1 ) ;
F_30 ( V_1 ) ;
F_11 ( ! V_132 , L_36 ) ;
}
static void F_132 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 =
F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
enum V_69 V_70 ;
T_5 V_262 ;
T_5 V_248 , V_94 ;
F_34 ( & V_54 -> V_71 ) ;
F_36 ( V_1 -> V_264 ) ;
if ( ! F_63 ( V_1 ) )
return;
F_38 ( L_37 ) ;
V_262 = F_130 ( V_1 ) ;
V_262 &= ~ V_82 ;
V_94 = F_53 ( V_1 ) ;
V_248 = F_55 ( V_1 ) ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
F_38 ( L_34 ,
F_25 ( V_248 ) , F_25 ( V_94 ) ) ;
if ( ( V_262 & V_266 ) == 0 )
V_1 -> V_253 = V_267 ;
V_70 = F_27 ( V_67 ) ;
F_32 ( V_54 , V_70 ) ;
}
static void F_133 ( struct V_268 * V_269 )
{
struct V_1 * V_1 = F_57 ( F_134 ( V_269 ) ,
struct V_1 , V_270 ) ;
F_26 ( V_1 ) ;
if ( ! V_1 -> V_264 )
F_132 ( V_1 ) ;
F_30 ( V_1 ) ;
}
static void F_135 ( struct V_1 * V_1 )
{
unsigned long V_271 ;
V_271 = F_136 ( V_1 -> V_100 * 5 ) ;
F_137 ( & V_1 -> V_270 , V_271 ) ;
}
static void F_90 ( struct V_1 * V_1 , bool V_272 )
{
struct V_53 * V_54 =
F_3 ( V_1 ) -> V_55 ;
F_34 ( & V_54 -> V_71 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_11 ( ! V_1 -> V_264 , L_38 ) ;
V_1 -> V_264 = false ;
if ( V_272 )
F_132 ( V_1 ) ;
else
F_135 ( V_1 ) ;
}
static void F_138 ( struct V_1 * V_1 , bool V_272 )
{
if ( ! F_1 ( V_1 ) )
return;
F_26 ( V_1 ) ;
F_90 ( V_1 , V_272 ) ;
F_30 ( V_1 ) ;
}
void F_139 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_262 ;
T_5 V_94 ;
if ( ! F_1 ( V_1 ) )
return;
F_38 ( L_39 ) ;
F_26 ( V_1 ) ;
if ( F_62 ( V_1 ) ) {
F_38 ( L_40 ) ;
goto V_135;
}
F_126 ( V_1 ) ;
V_94 = F_53 ( V_1 ) ;
V_262 = F_130 ( V_1 ) ;
if ( F_140 ( V_7 ) ) {
V_262 &= ~ V_273 ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
}
V_262 |= V_266 ;
if ( ! F_140 ( V_7 ) )
V_262 |= V_273 ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
F_124 ( V_1 ) ;
V_1 -> V_256 = V_267 ;
if ( F_140 ( V_7 ) ) {
V_262 |= V_273 ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
}
V_135:
F_30 ( V_1 ) ;
}
void F_141 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
T_5 V_262 ;
T_5 V_94 ;
if ( ! F_1 ( V_1 ) )
return;
F_38 ( L_41 ) ;
F_26 ( V_1 ) ;
F_11 ( ! V_1 -> V_264 , L_42 ) ;
V_262 = F_130 ( V_1 ) ;
V_262 &= ~ ( V_266 | V_273 | V_82 |
V_274 ) ;
V_94 = F_53 ( V_1 ) ;
V_1 -> V_264 = false ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
V_1 -> V_253 = V_267 ;
F_125 ( V_1 ) ;
V_70 = F_27 ( V_67 ) ;
F_32 ( V_54 , V_70 ) ;
F_30 ( V_1 ) ;
}
static void F_142 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_262 ;
T_5 V_94 ;
F_128 ( V_1 ) ;
F_26 ( V_1 ) ;
V_262 = F_130 ( V_1 ) ;
V_262 |= V_274 ;
V_94 = F_53 ( V_1 ) ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
F_30 ( V_1 ) ;
}
void F_143 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_38 ( L_43 ) ;
F_144 ( V_1 -> V_13 ) ;
F_142 ( V_1 ) ;
}
static void F_145 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_262 ;
T_5 V_94 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( V_1 ) ;
V_262 = F_130 ( V_1 ) ;
V_262 &= ~ V_274 ;
V_94 = F_53 ( V_1 ) ;
F_60 ( V_94 , V_262 ) ;
F_113 ( V_94 ) ;
F_30 ( V_1 ) ;
V_1 -> V_258 = V_267 ;
F_129 ( V_1 ) ;
}
void F_146 ( struct V_1 * V_1 )
{
if ( ! F_1 ( V_1 ) )
return;
F_38 ( L_43 ) ;
F_145 ( V_1 ) ;
F_147 ( V_1 -> V_13 ) ;
}
static void F_148 ( struct V_32 * V_9 ,
bool V_275 )
{
struct V_1 * V_1 = F_4 ( & V_9 -> V_4 ) ;
bool V_276 ;
F_26 ( V_1 ) ;
V_276 = F_130 ( V_1 ) & V_274 ;
F_30 ( V_1 ) ;
if ( V_276 == V_275 )
return;
F_38 ( L_44 ,
V_275 ? L_45 : L_46 ) ;
if ( V_275 )
F_142 ( V_1 ) ;
else
F_145 ( V_1 ) ;
}
static void F_149 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_277 * V_226 = V_3 -> V_4 . V_4 . V_226 ;
struct V_6 * V_7 = V_226 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_227 ;
F_150 ( V_54 ,
F_112 ( V_226 ) -> V_72 ) ;
F_38 ( L_43 ) ;
V_227 = F_25 ( V_229 ) ;
F_11 ( V_227 & V_278 , L_47 ) ;
F_11 ( V_227 & V_279 , L_48 ) ;
V_1 -> V_232 &= ~ ( V_279 | V_237 ) ;
V_1 -> V_232 |= V_278 ;
F_60 ( V_229 , V_1 -> V_232 ) ;
F_113 ( V_229 ) ;
F_114 ( 200 ) ;
}
static void F_151 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_277 * V_226 = V_3 -> V_4 . V_4 . V_226 ;
struct V_6 * V_7 = V_226 -> V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_227 ;
F_150 ( V_54 ,
F_112 ( V_226 ) -> V_72 ) ;
V_227 = F_25 ( V_229 ) ;
F_11 ( ( V_227 & V_278 ) == 0 ,
L_49 ) ;
F_11 ( V_227 & V_279 , L_48 ) ;
V_227 &= ~ V_278 ;
F_60 ( V_229 , V_227 ) ;
F_113 ( V_229 ) ;
F_114 ( 200 ) ;
}
void F_152 ( struct V_1 * V_1 , int V_31 )
{
int V_129 , V_49 ;
if ( V_1 -> V_11 [ V_18 ] < 0x11 )
return;
if ( V_31 != V_280 ) {
V_129 = F_153 ( & V_1 -> V_145 , V_281 ,
V_282 ) ;
} else {
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_129 = F_153 ( & V_1 -> V_145 , V_281 ,
V_283 ) ;
if ( V_129 == 1 )
break;
F_61 ( 1 ) ;
}
}
if ( V_129 != 1 )
F_38 ( L_50 ,
V_31 == V_280 ? L_45 : L_46 ) ;
}
static bool F_154 ( struct V_67 * V_68 ,
enum V_72 * V_72 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
T_5 V_80 ;
V_70 = F_27 ( V_68 ) ;
if ( ! F_155 ( V_54 , V_70 ) )
return false ;
V_80 = F_25 ( V_1 -> V_172 ) ;
if ( ! ( V_80 & V_279 ) )
return false ;
if ( V_21 == V_22 && F_74 ( V_7 ) && ! F_24 ( V_7 ) ) {
* V_72 = F_156 ( V_80 ) ;
} else if ( F_104 ( V_7 ) ) {
* V_72 = F_157 ( V_80 ) ;
} else if ( ! F_120 ( V_7 ) || V_21 == V_22 ) {
* V_72 = F_158 ( V_80 ) ;
} else {
T_5 V_284 ;
T_5 V_285 ;
int V_49 ;
switch ( V_1 -> V_172 ) {
case V_286 :
V_284 = V_287 ;
break;
case V_288 :
V_284 = V_289 ;
break;
case V_290 :
V_284 = V_291 ;
break;
default:
return true ;
}
F_159 (dev_priv, i) {
V_285 = F_25 ( F_160 ( V_49 ) ) ;
if ( ( V_285 & V_292 ) == V_284 ) {
* V_72 = V_49 ;
return true ;
}
}
F_38 ( L_51 ,
V_1 -> V_172 ) ;
}
return true ;
}
static void F_161 ( struct V_67 * V_68 ,
struct V_178 * V_179 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
T_5 V_80 , V_43 = 0 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
struct V_195 * V_226 = F_112 ( V_68 -> V_4 . V_226 ) ;
int V_293 ;
V_80 = F_25 ( V_1 -> V_172 ) ;
if ( V_80 & V_237 )
V_179 -> V_208 = true ;
if ( ( V_21 == V_22 ) || ! F_120 ( V_7 ) ) {
if ( V_80 & V_239 )
V_43 |= V_238 ;
else
V_43 |= V_294 ;
if ( V_80 & V_241 )
V_43 |= V_240 ;
else
V_43 |= V_295 ;
} else {
V_80 = F_25 ( F_160 ( V_226 -> V_72 ) ) ;
if ( V_80 & V_296 )
V_43 |= V_238 ;
else
V_43 |= V_294 ;
if ( V_80 & V_297 )
V_43 |= V_240 ;
else
V_43 |= V_295 ;
}
V_179 -> V_194 . V_43 |= V_43 ;
if ( ! F_54 ( V_7 ) && ! F_24 ( V_7 ) &&
V_80 & V_217 )
V_179 -> V_218 = true ;
V_179 -> V_206 = true ;
F_162 ( V_226 , V_179 ) ;
if ( V_21 == V_22 ) {
if ( ( F_25 ( V_229 ) & V_230 ) == V_231 )
V_179 -> V_219 = 162000 ;
else
V_179 -> V_219 = 270000 ;
}
V_293 = F_163 ( V_179 -> V_219 ,
& V_179 -> V_220 ) ;
if ( F_54 ( V_54 -> V_7 ) && V_21 != V_22 )
F_164 ( V_179 , V_293 ) ;
V_179 -> V_194 . V_210 = V_293 ;
if ( F_1 ( V_1 ) && V_54 -> V_212 . V_213 &&
V_179 -> V_211 > V_54 -> V_212 . V_213 ) {
F_38 ( L_52 ,
V_179 -> V_211 , V_54 -> V_212 . V_213 ) ;
V_54 -> V_212 . V_213 = V_179 -> V_211 ;
}
}
static bool F_165 ( struct V_1 * V_1 )
{
return V_1 -> V_298 [ 0 ] & V_299 ;
}
static bool F_166 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_167 ( V_7 ) )
return false ;
return F_25 ( F_168 ( V_7 ) ) & V_300 ;
}
static void F_169 ( struct V_1 * V_1 ,
struct V_301 * V_302 )
{
struct V_2 * V_225 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_225 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_226 = F_112 ( V_225 -> V_4 . V_4 . V_226 ) ;
T_5 V_303 = F_170 ( V_226 -> V_228 . V_304 ) ;
T_5 V_305 = F_171 ( V_226 -> V_228 . V_304 ) ;
T_2 * V_306 = ( T_2 * ) V_302 ;
unsigned int V_49 ;
F_60 ( V_303 , 0 ) ;
F_113 ( V_303 ) ;
for ( V_49 = 0 ; V_49 < V_307 ; V_49 += 4 ) {
if ( V_49 < sizeof( struct V_301 ) )
F_60 ( V_305 + V_49 , * V_306 ++ ) ;
else
F_60 ( V_305 + V_49 , 0 ) ;
}
F_60 ( V_303 , V_308 ) ;
F_113 ( V_303 ) ;
}
static void F_172 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_301 V_309 ;
memset ( & V_309 , 0 , sizeof( V_309 ) ) ;
V_309 . V_310 . V_311 = 0 ;
V_309 . V_310 . V_312 = 0x7 ;
V_309 . V_310 . V_313 = 0x2 ;
V_309 . V_310 . V_314 = 0x8 ;
F_169 ( V_1 , & V_309 ) ;
F_60 ( F_173 ( V_7 ) , V_315 |
V_316 | V_317 ) ;
}
static void F_174 ( struct V_1 * V_1 )
{
struct V_2 * V_225 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_225 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_111 ;
int V_112 = 0x3 ;
int V_318 = 5 ;
bool V_319 = false ;
V_111 = V_1 -> V_137 ( V_1 , 0 ) ;
if ( F_82 ( V_7 ) && V_225 -> V_21 != V_22 )
V_319 = true ;
if ( V_1 -> V_298 [ 1 ] & V_320 || V_319 )
F_153 ( & V_1 -> V_145 , V_321 ,
V_322 & ~ V_323 ) ;
else
F_153 ( & V_1 -> V_145 , V_321 ,
V_322 | V_323 ) ;
F_60 ( F_175 ( V_7 ) , V_324 ) ;
F_60 ( F_176 ( V_7 ) , V_325 ) ;
F_60 ( F_177 ( V_7 ) ,
V_116 |
( V_318 << V_122 ) |
( V_112 << V_123 ) |
( V_111 << V_124 ) ) ;
}
static void F_178 ( struct V_1 * V_1 )
{
struct V_2 * V_225 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_225 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_326 = 0x1f ;
T_2 V_327 = 1 ;
T_2 V_328 = 0x0 ;
const T_2 V_329 = V_330 ;
bool V_319 = false ;
if ( F_82 ( V_7 ) && V_225 -> V_21 != V_22 )
V_319 = true ;
if ( V_1 -> V_298 [ 1 ] & V_320 || V_319 ) {
V_328 |= V_331 ;
V_328 |= V_332 ;
V_328 |= V_333 ;
V_328 |= V_334 ;
V_328 |= F_82 ( V_7 ) ? V_335 : 0 ;
} else
V_328 |= V_336 ;
F_60 ( F_168 ( V_7 ) , V_328 |
( F_82 ( V_7 ) ? 0 : V_329 ) |
V_326 << V_337 |
V_327 << V_338 |
V_300 ) ;
}
static bool F_179 ( struct V_1 * V_1 )
{
struct V_2 * V_225 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_225 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_277 * V_226 = V_225 -> V_4 . V_4 . V_226 ;
struct V_195 * V_195 = F_112 ( V_226 ) ;
F_34 ( & V_54 -> V_339 . V_340 ) ;
F_36 ( ! F_180 ( & V_7 -> V_341 . V_342 ) ) ;
F_36 ( ! F_180 ( & V_226 -> V_343 ) ) ;
V_54 -> V_339 . V_344 = false ;
if ( F_8 ( V_7 ) && V_225 -> V_21 != V_22 ) {
F_38 ( L_53 ) ;
return false ;
}
if ( ! V_345 . V_346 ) {
F_38 ( L_54 ) ;
return false ;
}
if ( F_82 ( V_7 ) )
goto V_135;
if ( F_25 ( F_181 ( V_195 -> V_228 . V_304 ) ) &
V_347 ) {
F_38 ( L_55 ) ;
return false ;
}
if ( V_195 -> V_228 . V_194 . V_43 & V_348 ) {
F_38 ( L_56 ) ;
return false ;
}
V_135:
V_54 -> V_339 . V_344 = true ;
return true ;
}
static void F_182 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_36 ( F_25 ( F_168 ( V_7 ) ) & V_300 ) ;
F_36 ( V_54 -> V_339 . V_349 ) ;
F_34 ( & V_54 -> V_339 . V_340 ) ;
F_174 ( V_1 ) ;
F_178 ( V_1 ) ;
V_54 -> V_339 . V_349 = true ;
}
void F_183 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( ! F_167 ( V_7 ) ) {
F_38 ( L_57 ) ;
return;
}
if ( ! F_165 ( V_1 ) ) {
F_38 ( L_58 ) ;
return;
}
F_29 ( & V_54 -> V_339 . V_340 ) ;
if ( V_54 -> V_339 . V_350 ) {
F_38 ( L_59 ) ;
F_31 ( & V_54 -> V_339 . V_340 ) ;
return;
}
V_54 -> V_339 . V_351 = 0 ;
F_172 ( V_1 ) ;
if ( F_179 ( V_1 ) )
V_54 -> V_339 . V_350 = V_1 ;
F_31 ( & V_54 -> V_339 . V_340 ) ;
}
void F_184 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
F_29 ( & V_54 -> V_339 . V_340 ) ;
if ( ! V_54 -> V_339 . V_350 ) {
F_31 ( & V_54 -> V_339 . V_340 ) ;
return;
}
if ( V_54 -> V_339 . V_349 ) {
F_60 ( F_168 ( V_7 ) ,
F_25 ( F_168 ( V_7 ) ) & ~ V_300 ) ;
if ( F_123 ( ( F_25 ( F_185 ( V_7 ) ) &
V_352 ) == 0 , 2000 , 10 ) )
F_70 ( L_60 ) ;
V_54 -> V_339 . V_349 = false ;
} else {
F_36 ( F_25 ( F_168 ( V_7 ) ) & V_300 ) ;
}
V_54 -> V_339 . V_350 = NULL ;
F_31 ( & V_54 -> V_339 . V_340 ) ;
F_186 ( & V_54 -> V_339 . V_353 ) ;
}
static void F_187 ( struct V_268 * V_353 )
{
struct V_53 * V_54 =
F_57 ( V_353 , F_58 ( * V_54 ) , V_339 . V_353 . V_353 ) ;
struct V_1 * V_1 = V_54 -> V_339 . V_350 ;
F_29 ( & V_54 -> V_339 . V_340 ) ;
V_1 = V_54 -> V_339 . V_350 ;
if ( ! V_1 )
goto V_354;
if ( V_54 -> V_339 . V_351 )
goto V_354;
F_182 ( V_1 ) ;
V_354:
F_31 ( & V_54 -> V_339 . V_340 ) ;
}
static void F_188 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
if ( V_54 -> V_339 . V_349 ) {
T_5 V_328 = F_25 ( F_168 ( V_7 ) ) ;
F_36 ( ! ( V_328 & V_300 ) ) ;
F_60 ( F_168 ( V_7 ) , V_328 & ~ V_300 ) ;
V_54 -> V_339 . V_349 = false ;
}
}
void F_189 ( struct V_6 * V_7 ,
unsigned V_355 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_277 * V_226 ;
enum V_72 V_72 ;
F_29 ( & V_54 -> V_339 . V_340 ) ;
if ( ! V_54 -> V_339 . V_350 ) {
F_31 ( & V_54 -> V_339 . V_340 ) ;
return;
}
V_226 = F_2 ( V_54 -> V_339 . V_350 ) -> V_4 . V_4 . V_226 ;
V_72 = F_112 ( V_226 ) -> V_72 ;
F_188 ( V_7 ) ;
V_355 &= F_190 ( V_72 ) ;
V_54 -> V_339 . V_351 |= V_355 ;
F_31 ( & V_54 -> V_339 . V_340 ) ;
}
void F_191 ( struct V_6 * V_7 ,
unsigned V_355 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_277 * V_226 ;
enum V_72 V_72 ;
F_29 ( & V_54 -> V_339 . V_340 ) ;
if ( ! V_54 -> V_339 . V_350 ) {
F_31 ( & V_54 -> V_339 . V_340 ) ;
return;
}
V_226 = F_2 ( V_54 -> V_339 . V_350 ) -> V_4 . V_4 . V_226 ;
V_72 = F_112 ( V_226 ) -> V_72 ;
V_54 -> V_339 . V_351 &= ~ V_355 ;
if ( F_8 ( V_7 ) &&
( V_355 & F_192 ( V_72 ) ) )
F_188 ( V_7 ) ;
if ( ! V_54 -> V_339 . V_349 && ! V_54 -> V_339 . V_351 )
F_137 ( & V_54 -> V_339 . V_353 ,
F_136 ( 100 ) ) ;
F_31 ( & V_54 -> V_339 . V_340 ) ;
}
void F_193 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
F_194 ( & V_54 -> V_339 . V_353 , F_187 ) ;
F_195 ( & V_54 -> V_339 . V_340 ) ;
}
static void F_196 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
F_131 ( V_1 ) ;
F_146 ( V_1 ) ;
F_152 ( V_1 , V_356 ) ;
F_141 ( V_1 ) ;
if ( F_10 ( V_7 ) -> V_17 < 5 )
F_197 ( V_1 ) ;
}
static void F_198 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
F_197 ( V_1 ) ;
if ( V_21 == V_22 )
F_151 ( V_1 ) ;
}
static void F_199 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
F_197 ( V_1 ) ;
}
static void F_200 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_357 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_195 =
F_112 ( V_68 -> V_4 . V_226 ) ;
enum V_358 V_359 = F_201 ( V_357 ) ;
enum V_72 V_72 = V_195 -> V_72 ;
T_5 V_328 ;
F_197 ( V_1 ) ;
F_29 ( & V_54 -> V_360 ) ;
V_328 = F_202 ( V_54 , V_72 , F_203 ( V_359 ) ) ;
V_328 |= V_361 ;
F_204 ( V_54 , V_72 , F_203 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_205 ( V_359 ) ) ;
V_328 |= V_361 ;
F_204 ( V_54 , V_72 , F_205 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_206 ( V_359 ) ) ;
V_328 &= ~ ( V_362 | V_363 ) ;
F_204 ( V_54 , V_72 , F_206 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_207 ( V_359 ) ) ;
V_328 &= ~ ( V_362 | V_363 ) ;
F_204 ( V_54 , V_72 , F_207 ( V_359 ) , V_328 ) ;
F_31 ( & V_54 -> V_360 ) ;
}
static void
F_208 ( struct V_1 * V_1 ,
T_2 * V_232 ,
T_3 V_364 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
if ( F_13 ( V_7 ) ) {
T_2 V_365 = F_25 ( F_209 ( V_21 ) ) ;
if ( V_364 & V_366 )
V_365 |= V_367 ;
else
V_365 &= ~ V_367 ;
V_365 &= ~ V_368 ;
switch ( V_364 & V_369 ) {
case V_370 :
V_365 |= V_371 ;
break;
case V_372 :
V_365 |= V_373 ;
break;
case V_374 :
V_365 |= V_375 ;
break;
case V_376 :
V_365 |= V_377 ;
break;
}
F_60 ( F_209 ( V_21 ) , V_365 ) ;
} else if ( F_120 ( V_7 ) && ( F_74 ( V_7 ) || V_21 != V_22 ) ) {
* V_232 &= ~ V_378 ;
switch ( V_364 & V_369 ) {
case V_370 :
* V_232 |= V_242 ;
break;
case V_372 :
* V_232 |= V_379 ;
break;
case V_374 :
* V_232 |= V_380 ;
break;
case V_376 :
F_70 ( L_61 ) ;
* V_232 |= V_380 ;
break;
}
} else {
if ( F_104 ( V_7 ) )
* V_232 &= ~ V_381 ;
else
* V_232 &= ~ V_382 ;
switch ( V_364 & V_369 ) {
case V_370 :
* V_232 |= V_244 ;
break;
case V_372 :
* V_232 |= V_383 ;
break;
case V_374 :
* V_232 |= V_384 ;
break;
case V_376 :
if ( F_104 ( V_7 ) ) {
* V_232 |= V_385 ;
} else {
F_70 ( L_61 ) ;
* V_232 |= V_384 ;
}
break;
}
}
}
static void F_210 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
V_1 -> V_232 |= V_279 ;
F_208 ( V_1 , & V_1 -> V_232 ,
V_372 ) ;
F_60 ( V_1 -> V_172 , V_1 -> V_232 ) ;
F_113 ( V_1 -> V_172 ) ;
}
static void F_211 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_386 = F_25 ( V_1 -> V_172 ) ;
if ( F_36 ( V_386 & V_279 ) )
return;
F_210 ( V_1 ) ;
F_131 ( V_1 ) ;
F_139 ( V_1 ) ;
F_138 ( V_1 , true ) ;
F_152 ( V_1 , V_280 ) ;
F_212 ( V_1 ) ;
F_213 ( V_1 ) ;
F_214 ( V_1 ) ;
}
static void F_215 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
F_211 ( V_68 ) ;
F_143 ( V_1 ) ;
}
static void F_216 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
F_143 ( V_1 ) ;
}
static void F_217 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_357 = F_2 ( V_1 ) ;
F_115 ( V_68 ) ;
if ( V_357 -> V_21 == V_22 ) {
F_111 ( V_1 ) ;
F_149 ( V_1 ) ;
}
}
static void F_218 ( struct V_6 * V_7 ,
enum V_72 V_72 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_67 * V_68 ;
F_34 ( & V_54 -> V_71 ) ;
F_35 (encoder, &dev->mode_config.encoder_list,
base.head) {
struct V_1 * V_1 ;
enum V_21 V_21 ;
if ( V_68 -> type != V_5 )
continue;
V_1 = F_5 ( & V_68 -> V_4 ) ;
V_21 = F_2 ( V_1 ) -> V_21 ;
if ( V_1 -> V_78 != V_72 )
continue;
F_38 ( L_62 ,
F_39 ( V_72 ) , F_40 ( V_21 ) ) ;
F_132 ( V_1 ) ;
V_1 -> V_78 = V_79 ;
}
}
static void F_219 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_68 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_226 = F_112 ( V_68 -> V_4 . V_226 ) ;
struct V_76 V_77 ;
F_34 ( & V_54 -> V_71 ) ;
if ( V_1 -> V_78 == V_226 -> V_72 )
return;
if ( V_1 -> V_78 != V_79 )
F_132 ( V_1 ) ;
F_218 ( V_7 , V_226 -> V_72 ) ;
V_1 -> V_78 = V_226 -> V_72 ;
F_38 ( L_63 ,
F_39 ( V_1 -> V_78 ) , F_40 ( V_3 -> V_21 ) ) ;
F_41 ( V_7 , V_1 , & V_77 ) ;
F_42 ( V_7 , V_1 ,
& V_77 ) ;
}
static void F_220 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_357 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_195 = F_112 ( V_68 -> V_4 . V_226 ) ;
enum V_358 V_21 = F_201 ( V_357 ) ;
int V_72 = V_195 -> V_72 ;
T_5 V_328 ;
F_29 ( & V_54 -> V_360 ) ;
V_328 = F_202 ( V_54 , V_72 , F_221 ( V_21 ) ) ;
V_328 = 0 ;
if ( V_72 )
V_328 |= ( 1 << 21 ) ;
else
V_328 &= ~ ( 1 << 21 ) ;
V_328 |= 0x001000c4 ;
F_204 ( V_54 , V_72 , F_222 ( V_21 ) , V_328 ) ;
F_204 ( V_54 , V_72 , F_223 ( V_21 ) , 0x00760018 ) ;
F_204 ( V_54 , V_72 , F_224 ( V_21 ) , 0x00400888 ) ;
F_31 ( & V_54 -> V_360 ) ;
if ( F_1 ( V_1 ) ) {
F_26 ( V_1 ) ;
F_219 ( V_1 ) ;
F_30 ( V_1 ) ;
}
F_211 ( V_68 ) ;
F_225 ( V_54 , V_357 ) ;
}
static void F_226 ( struct V_67 * V_68 )
{
struct V_2 * V_357 = F_227 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_195 =
F_112 ( V_68 -> V_4 . V_226 ) ;
enum V_358 V_21 = F_201 ( V_357 ) ;
int V_72 = V_195 -> V_72 ;
F_115 ( V_68 ) ;
F_29 ( & V_54 -> V_360 ) ;
F_204 ( V_54 , V_72 , F_228 ( V_21 ) ,
V_362 |
V_363 ) ;
F_204 ( V_54 , V_72 , F_229 ( V_21 ) ,
V_387 |
V_388 |
( 1 << V_389 ) |
V_390 ) ;
F_204 ( V_54 , V_72 , F_230 ( V_21 ) , 0x00750f00 ) ;
F_204 ( V_54 , V_72 , F_231 ( V_21 ) , 0x00001500 ) ;
F_204 ( V_54 , V_72 , F_232 ( V_21 ) , 0x40400000 ) ;
F_31 ( & V_54 -> V_360 ) ;
}
static void F_233 ( struct V_67 * V_68 )
{
struct V_1 * V_1 = F_5 ( & V_68 -> V_4 ) ;
struct V_2 * V_357 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_195 =
F_112 ( V_68 -> V_4 . V_226 ) ;
enum V_358 V_359 = F_201 ( V_357 ) ;
int V_72 = V_195 -> V_72 ;
int V_306 , V_49 ;
T_5 V_328 ;
F_29 ( & V_54 -> V_360 ) ;
V_328 = F_202 ( V_54 , V_72 , F_203 ( V_359 ) ) ;
V_328 |= V_361 ;
F_204 ( V_54 , V_72 , F_203 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_205 ( V_359 ) ) ;
V_328 |= V_361 ;
F_204 ( V_54 , V_72 , F_205 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_206 ( V_359 ) ) ;
V_328 |= ( V_362 | V_363 ) ;
F_204 ( V_54 , V_72 , F_206 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_207 ( V_359 ) ) ;
V_328 |= ( V_362 | V_363 ) ;
F_204 ( V_54 , V_72 , F_207 ( V_359 ) , V_328 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_306 = ( V_49 == 1 ) ? 0x0 : 0x6 ;
F_204 ( V_54 , V_72 , F_234 ( V_359 , V_49 ) ,
V_306 << V_391 ) ;
V_306 = ( V_49 == 1 ) ? 0x0 : 0x1 ;
F_204 ( V_54 , V_72 , F_235 ( V_359 , V_49 ) ,
V_306 << V_392 ) ;
}
F_31 ( & V_54 -> V_360 ) ;
if ( F_1 ( V_1 ) ) {
F_26 ( V_1 ) ;
F_219 ( V_1 ) ;
F_30 ( V_1 ) ;
}
F_211 ( V_68 ) ;
F_225 ( V_54 , V_357 ) ;
}
static void F_236 ( struct V_67 * V_68 )
{
struct V_2 * V_357 = F_227 ( & V_68 -> V_4 ) ;
struct V_6 * V_7 = V_68 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_195 =
F_112 ( V_68 -> V_4 . V_226 ) ;
enum V_358 V_359 = F_201 ( V_357 ) ;
enum V_72 V_72 = V_195 -> V_72 ;
T_5 V_328 ;
F_115 ( V_68 ) ;
F_29 ( & V_54 -> V_360 ) ;
if ( V_72 != V_75 ) {
V_328 = F_202 ( V_54 , V_72 , V_393 ) ;
V_328 &= ~ ( V_394 | V_395 ) ;
if ( V_359 == V_396 )
V_328 |= V_397 ;
if ( V_359 == V_398 )
V_328 |= V_399 ;
F_204 ( V_54 , V_72 , V_393 , V_328 ) ;
} else {
V_328 = F_202 ( V_54 , V_72 , V_400 ) ;
V_328 &= ~ ( V_401 | V_402 ) ;
if ( V_359 == V_396 )
V_328 |= V_403 ;
if ( V_359 == V_398 )
V_328 |= V_404 ;
F_204 ( V_54 , V_72 , V_400 , V_328 ) ;
}
V_328 = F_202 ( V_54 , V_72 , F_221 ( V_359 ) ) ;
V_328 |= V_405 ;
if ( V_72 != V_75 )
V_328 &= ~ V_406 ;
else
V_328 |= V_406 ;
F_204 ( V_54 , V_72 , F_221 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_237 ( V_359 ) ) ;
V_328 |= V_405 ;
if ( V_72 != V_75 )
V_328 &= ~ V_406 ;
else
V_328 |= V_406 ;
F_204 ( V_54 , V_72 , F_237 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_238 ( V_359 ) ) ;
if ( V_72 != V_75 )
V_328 &= ~ V_407 ;
else
V_328 |= V_407 ;
F_204 ( V_54 , V_72 , F_238 ( V_359 ) , V_328 ) ;
F_31 ( & V_54 -> V_360 ) ;
}
static T_6
F_239 ( struct V_144 * V_145 , unsigned int V_408 ,
void * V_160 , T_7 V_154 )
{
T_6 V_129 ;
int V_49 ;
F_240 ( V_145 , V_18 , V_160 , 1 ) ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_129 = F_240 ( V_145 , V_408 , V_160 , V_154 ) ;
if ( V_129 == V_154 )
return V_129 ;
F_61 ( 1 ) ;
}
return V_129 ;
}
static bool
F_241 ( struct V_1 * V_1 , T_3 V_409 [ V_410 ] )
{
return F_239 ( & V_1 -> V_145 ,
V_411 ,
V_409 ,
V_410 ) == V_410 ;
}
static T_3
F_242 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_24 ( V_7 ) )
return V_412 ;
else if ( F_74 ( V_7 ) && V_21 == V_22 )
return V_413 ;
else if ( F_120 ( V_7 ) && V_21 != V_22 )
return V_412 ;
else
return V_413 ;
}
static T_3
F_243 ( struct V_1 * V_1 , T_3 V_414 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
if ( F_8 ( V_7 ) || F_82 ( V_7 ) ) {
switch ( V_414 & V_415 ) {
case V_416 :
return V_417 ;
case V_418 :
return V_419 ;
case V_413 :
return V_420 ;
case V_412 :
default:
return V_421 ;
}
} else if ( F_24 ( V_7 ) ) {
switch ( V_414 & V_415 ) {
case V_416 :
return V_417 ;
case V_418 :
return V_419 ;
case V_413 :
return V_420 ;
case V_412 :
default:
return V_421 ;
}
} else if ( F_74 ( V_7 ) && V_21 == V_22 ) {
switch ( V_414 & V_415 ) {
case V_416 :
return V_419 ;
case V_418 :
case V_413 :
return V_420 ;
default:
return V_421 ;
}
} else {
switch ( V_414 & V_415 ) {
case V_416 :
return V_419 ;
case V_418 :
return V_419 ;
case V_413 :
return V_420 ;
case V_412 :
default:
return V_421 ;
}
}
}
static T_2 F_244 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_357 = F_2 ( V_1 ) ;
struct V_195 * V_195 =
F_112 ( V_357 -> V_4 . V_4 . V_226 ) ;
unsigned long V_422 , V_423 ,
V_424 ;
T_3 V_425 = V_1 -> V_425 [ 0 ] ;
enum V_358 V_21 = F_201 ( V_357 ) ;
int V_72 = V_195 -> V_72 ;
switch ( V_425 & V_426 ) {
case V_421 :
V_423 = 0x0004000 ;
switch ( V_425 & V_415 ) {
case V_416 :
V_422 = 0x2B405555 ;
V_424 = 0x552AB83A ;
break;
case V_418 :
V_422 = 0x2B404040 ;
V_424 = 0x5548B83A ;
break;
case V_413 :
V_422 = 0x2B245555 ;
V_424 = 0x5560B83A ;
break;
case V_412 :
V_422 = 0x2B405555 ;
V_424 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_420 :
V_423 = 0x0002000 ;
switch ( V_425 & V_415 ) {
case V_416 :
V_422 = 0x2B404040 ;
V_424 = 0x5552B83A ;
break;
case V_418 :
V_422 = 0x2B404848 ;
V_424 = 0x5580B83A ;
break;
case V_413 :
V_422 = 0x2B404040 ;
V_424 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_419 :
V_423 = 0x0000000 ;
switch ( V_425 & V_415 ) {
case V_416 :
V_422 = 0x2B305555 ;
V_424 = 0x5570B83A ;
break;
case V_418 :
V_422 = 0x2B2B4040 ;
V_424 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_417 :
V_423 = 0x0006000 ;
switch ( V_425 & V_415 ) {
case V_416 :
V_422 = 0x1B405555 ;
V_424 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_29 ( & V_54 -> V_360 ) ;
F_204 ( V_54 , V_72 , F_245 ( V_21 ) , 0x00000000 ) ;
F_204 ( V_54 , V_72 , F_246 ( V_21 ) , V_422 ) ;
F_204 ( V_54 , V_72 , F_247 ( V_21 ) ,
V_424 ) ;
F_204 ( V_54 , V_72 , F_248 ( V_21 ) , 0x0C782040 ) ;
F_204 ( V_54 , V_72 , F_249 ( V_21 ) , 0x00030000 ) ;
F_204 ( V_54 , V_72 , F_250 ( V_21 ) , V_423 ) ;
F_204 ( V_54 , V_72 , F_245 ( V_21 ) , 0x80000000 ) ;
F_31 ( & V_54 -> V_360 ) ;
return 0 ;
}
static T_2 F_251 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_357 = F_2 ( V_1 ) ;
struct V_195 * V_195 = F_112 ( V_357 -> V_4 . V_4 . V_226 ) ;
T_5 V_427 , V_428 , V_328 ;
T_3 V_425 = V_1 -> V_425 [ 0 ] ;
enum V_358 V_359 = F_201 ( V_357 ) ;
enum V_72 V_72 = V_195 -> V_72 ;
int V_49 ;
switch ( V_425 & V_426 ) {
case V_421 :
switch ( V_425 & V_415 ) {
case V_416 :
V_427 = 128 ;
V_428 = 52 ;
break;
case V_418 :
V_427 = 128 ;
V_428 = 77 ;
break;
case V_413 :
V_427 = 128 ;
V_428 = 102 ;
break;
case V_412 :
V_427 = 128 ;
V_428 = 154 ;
break;
default:
return 0 ;
}
break;
case V_420 :
switch ( V_425 & V_415 ) {
case V_416 :
V_427 = 85 ;
V_428 = 78 ;
break;
case V_418 :
V_427 = 85 ;
V_428 = 116 ;
break;
case V_413 :
V_427 = 85 ;
V_428 = 154 ;
break;
default:
return 0 ;
}
break;
case V_419 :
switch ( V_425 & V_415 ) {
case V_416 :
V_427 = 64 ;
V_428 = 104 ;
break;
case V_418 :
V_427 = 64 ;
V_428 = 154 ;
break;
default:
return 0 ;
}
break;
case V_417 :
switch ( V_425 & V_415 ) {
case V_416 :
V_427 = 43 ;
V_428 = 154 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_29 ( & V_54 -> V_360 ) ;
V_328 = F_202 ( V_54 , V_72 , F_252 ( V_359 ) ) ;
V_328 &= ~ ( V_429 | V_430 ) ;
F_204 ( V_54 , V_72 , F_252 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_253 ( V_359 ) ) ;
V_328 &= ~ ( V_429 | V_430 ) ;
F_204 ( V_54 , V_72 , F_253 ( V_359 ) , V_328 ) ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_328 = F_202 ( V_54 , V_72 , F_254 ( V_359 , V_49 ) ) ;
V_328 &= ~ V_431 ;
V_328 |= V_427 << V_432 ;
F_204 ( V_54 , V_72 , F_254 ( V_359 , V_49 ) , V_328 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_328 = F_202 ( V_54 , V_72 , F_255 ( V_359 , V_49 ) ) ;
V_328 &= ~ V_433 ;
V_328 |= V_428 << V_434 ;
F_204 ( V_54 , V_72 , F_255 ( V_359 , V_49 ) , V_328 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_328 = F_202 ( V_54 , V_72 , F_256 ( V_359 , V_49 ) ) ;
V_328 &= ~ V_435 ;
F_204 ( V_54 , V_72 , F_256 ( V_359 , V_49 ) , V_328 ) ;
}
if ( ( ( V_425 & V_426 )
== V_421 ) &&
( ( V_425 & V_415 )
== V_412 ) ) {
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_328 = F_202 ( V_54 , V_72 , F_256 ( V_359 , V_49 ) ) ;
V_328 |= V_435 ;
F_204 ( V_54 , V_72 , F_256 ( V_359 , V_49 ) , V_328 ) ;
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
V_328 = F_202 ( V_54 , V_72 , F_255 ( V_359 , V_49 ) ) ;
V_328 &= ~ ( 0xff << V_436 ) ;
V_328 |= ( 0x9a << V_436 ) ;
F_204 ( V_54 , V_72 , F_255 ( V_359 , V_49 ) , V_328 ) ;
}
}
V_328 = F_202 ( V_54 , V_72 , F_252 ( V_359 ) ) ;
V_328 |= V_429 | V_430 ;
F_204 ( V_54 , V_72 , F_252 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , F_253 ( V_359 ) ) ;
V_328 |= V_429 | V_430 ;
F_204 ( V_54 , V_72 , F_253 ( V_359 ) , V_328 ) ;
V_328 = F_202 ( V_54 , V_72 , V_437 ) ;
V_328 |= V_438 ;
F_204 ( V_54 , V_72 , V_437 , V_328 ) ;
F_31 ( & V_54 -> V_360 ) ;
return 0 ;
}
static void
F_257 ( struct V_1 * V_1 ,
const T_3 V_409 [ V_410 ] )
{
T_3 V_50 = 0 ;
T_3 V_439 = 0 ;
int V_440 ;
T_3 V_441 ;
T_3 V_442 ;
for ( V_440 = 0 ; V_440 < V_1 -> V_197 ; V_440 ++ ) {
T_3 V_443 = F_258 ( V_409 , V_440 ) ;
T_3 V_444 = F_259 ( V_409 , V_440 ) ;
if ( V_443 > V_50 )
V_50 = V_443 ;
if ( V_444 > V_439 )
V_439 = V_444 ;
}
V_441 = F_242 ( V_1 ) ;
if ( V_50 >= V_441 )
V_50 = V_441 | V_445 ;
V_442 = F_243 ( V_1 , V_50 ) ;
if ( V_439 >= V_442 )
V_439 = V_442 | V_446 ;
for ( V_440 = 0 ; V_440 < 4 ; V_440 ++ )
V_1 -> V_425 [ V_440 ] = V_50 | V_439 ;
}
static T_2
F_260 ( T_3 V_425 )
{
T_2 V_447 = 0 ;
switch ( V_425 & V_415 ) {
case V_416 :
default:
V_447 |= V_235 ;
break;
case V_418 :
V_447 |= V_448 ;
break;
case V_413 :
V_447 |= V_449 ;
break;
case V_412 :
V_447 |= V_450 ;
break;
}
switch ( V_425 & V_426 ) {
case V_421 :
default:
V_447 |= V_236 ;
break;
case V_420 :
V_447 |= V_451 ;
break;
case V_419 :
V_447 |= V_452 ;
break;
case V_417 :
V_447 |= V_453 ;
break;
}
return V_447 ;
}
static T_2
F_261 ( T_3 V_425 )
{
int V_447 = V_425 & ( V_415 |
V_426 ) ;
switch ( V_447 ) {
case V_416 | V_421 :
case V_418 | V_421 :
return V_454 ;
case V_416 | V_420 :
return V_455 ;
case V_416 | V_419 :
case V_418 | V_419 :
return V_456 ;
case V_418 | V_420 :
case V_413 | V_420 :
return V_457 ;
case V_413 | V_421 :
case V_412 | V_421 :
return V_458 ;
default:
F_38 ( L_64
L_65 , V_447 ) ;
return V_454 ;
}
}
static T_2
F_262 ( T_3 V_425 )
{
int V_447 = V_425 & ( V_415 |
V_426 ) ;
switch ( V_447 ) {
case V_416 | V_421 :
return V_459 ;
case V_416 | V_420 :
return V_460 ;
case V_416 | V_419 :
return V_461 ;
case V_418 | V_421 :
return V_462 ;
case V_418 | V_420 :
return V_463 ;
case V_413 | V_421 :
return V_464 ;
case V_413 | V_420 :
return V_465 ;
default:
F_38 ( L_64
L_65 , V_447 ) ;
return V_466 ;
}
}
static T_2
F_263 ( T_3 V_425 )
{
int V_447 = V_425 & ( V_415 |
V_426 ) ;
switch ( V_447 ) {
case V_416 | V_421 :
return F_264 ( 0 ) ;
case V_416 | V_420 :
return F_264 ( 1 ) ;
case V_416 | V_419 :
return F_264 ( 2 ) ;
case V_416 | V_417 :
return F_264 ( 3 ) ;
case V_418 | V_421 :
return F_264 ( 4 ) ;
case V_418 | V_420 :
return F_264 ( 5 ) ;
case V_418 | V_419 :
return F_264 ( 6 ) ;
case V_413 | V_421 :
return F_264 ( 7 ) ;
case V_413 | V_420 :
return F_264 ( 8 ) ;
default:
F_38 ( L_64
L_65 , V_447 ) ;
return F_264 ( 0 ) ;
}
}
static void
F_265 ( struct V_1 * V_1 , T_2 * V_232 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_2 V_447 , V_246 ;
T_3 V_425 = V_1 -> V_425 [ 0 ] ;
if ( F_8 ( V_7 ) || F_82 ( V_7 ) ) {
V_447 = F_263 ( V_425 ) ;
V_246 = V_467 ;
} else if ( F_104 ( V_7 ) ) {
V_447 = F_251 ( V_1 ) ;
V_246 = 0 ;
} else if ( F_24 ( V_7 ) ) {
V_447 = F_244 ( V_1 ) ;
V_246 = 0 ;
} else if ( F_74 ( V_7 ) && V_21 == V_22 ) {
V_447 = F_262 ( V_425 ) ;
V_246 = V_468 ;
} else if ( F_73 ( V_7 ) && V_21 == V_22 ) {
V_447 = F_261 ( V_425 ) ;
V_246 = V_469 ;
} else {
V_447 = F_260 ( V_425 ) ;
V_246 = V_470 | V_471 ;
}
F_38 ( L_66 , V_447 ) ;
* V_232 = ( * V_232 & ~ V_246 ) | V_447 ;
}
static bool
F_266 ( struct V_1 * V_1 ,
T_2 * V_232 ,
T_3 V_364 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
T_3 V_472 [ sizeof( V_1 -> V_425 ) + 1 ] ;
int V_129 , V_473 ;
F_208 ( V_1 , V_232 , V_364 ) ;
F_60 ( V_1 -> V_172 , * V_232 ) ;
F_113 ( V_1 -> V_172 ) ;
V_472 [ 0 ] = V_364 ;
if ( ( V_364 & V_369 ) ==
V_370 ) {
V_473 = 1 ;
} else {
memcpy ( V_472 + 1 , V_1 -> V_425 , V_1 -> V_197 ) ;
V_473 = V_1 -> V_197 + 1 ;
}
V_129 = F_267 ( & V_1 -> V_145 , V_474 ,
V_472 , V_473 ) ;
return V_129 == V_473 ;
}
static bool
F_268 ( struct V_1 * V_1 , T_2 * V_232 ,
T_3 V_364 )
{
memset ( V_1 -> V_425 , 0 , sizeof( V_1 -> V_425 ) ) ;
F_265 ( V_1 , V_232 ) ;
return F_266 ( V_1 , V_232 , V_364 ) ;
}
static bool
F_269 ( struct V_1 * V_1 , T_2 * V_232 ,
const T_3 V_409 [ V_410 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
int V_129 ;
F_257 ( V_1 , V_409 ) ;
F_265 ( V_1 , V_232 ) ;
F_60 ( V_1 -> V_172 , * V_232 ) ;
F_113 ( V_1 -> V_172 ) ;
V_129 = F_267 ( & V_1 -> V_145 , V_475 ,
V_1 -> V_425 , V_1 -> V_197 ) ;
return V_129 == V_1 -> V_197 ;
}
static void F_270 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
T_2 V_328 ;
if ( ! F_13 ( V_7 ) )
return;
V_328 = F_25 ( F_209 ( V_21 ) ) ;
V_328 &= ~ V_368 ;
V_328 |= V_476 ;
F_60 ( F_209 ( V_21 ) , V_328 ) ;
if ( V_21 == V_22 )
return;
if ( F_271 ( ( F_25 ( F_272 ( V_21 ) ) & V_477 ) ,
1 ) )
F_70 ( L_67 ) ;
}
void
F_212 ( struct V_1 * V_1 )
{
struct V_478 * V_68 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_68 -> V_7 ;
int V_49 ;
T_3 V_479 ;
int V_480 , V_481 ;
T_2 V_232 = V_1 -> V_232 ;
T_3 V_482 [ 2 ] ;
if ( F_13 ( V_7 ) )
F_273 ( V_68 ) ;
V_482 [ 0 ] = V_1 -> V_180 ;
V_482 [ 1 ] = V_1 -> V_197 ;
if ( F_119 ( V_1 -> V_11 ) )
V_482 [ 1 ] |= V_483 ;
F_267 ( & V_1 -> V_145 , V_484 , V_482 , 2 ) ;
V_482 [ 0 ] = 0 ;
V_482 [ 1 ] = V_485 ;
F_267 ( & V_1 -> V_145 , V_486 , V_482 , 2 ) ;
V_232 |= V_279 ;
if ( ! F_268 ( V_1 , & V_232 ,
V_372 |
V_366 ) ) {
F_70 ( L_68 ) ;
return;
}
V_479 = 0xff ;
V_480 = 0 ;
V_481 = 0 ;
for (; ; ) {
T_3 V_409 [ V_410 ] ;
F_274 ( V_1 -> V_11 ) ;
if ( ! F_241 ( V_1 , V_409 ) ) {
F_70 ( L_69 ) ;
break;
}
if ( F_275 ( V_409 , V_1 -> V_197 ) ) {
F_38 ( L_70 ) ;
break;
}
for ( V_49 = 0 ; V_49 < V_1 -> V_197 ; V_49 ++ )
if ( ( V_1 -> V_425 [ V_49 ] & V_445 ) == 0 )
break;
if ( V_49 == V_1 -> V_197 ) {
++ V_481 ;
if ( V_481 == 5 ) {
F_70 ( L_71 ) ;
break;
}
F_268 ( V_1 , & V_232 ,
V_372 |
V_366 ) ;
V_480 = 0 ;
continue;
}
if ( ( V_1 -> V_425 [ 0 ] & V_415 ) == V_479 ) {
++ V_480 ;
if ( V_480 == 5 ) {
F_70 ( L_72 ) ;
break;
}
} else
V_480 = 0 ;
V_479 = V_1 -> V_425 [ 0 ] & V_415 ;
if ( ! F_269 ( V_1 , & V_232 , V_409 ) ) {
F_70 ( L_73 ) ;
break;
}
}
V_1 -> V_232 = V_232 ;
}
void
F_213 ( struct V_1 * V_1 )
{
bool V_487 = false ;
int V_488 , V_489 ;
T_2 V_232 = V_1 -> V_232 ;
T_2 V_490 = V_374 ;
if ( V_1 -> V_180 == V_16 || V_1 -> V_491 )
V_490 = V_376 ;
if ( ! F_266 ( V_1 , & V_232 ,
V_490 |
V_366 ) ) {
F_70 ( L_74 ) ;
return;
}
V_488 = 0 ;
V_489 = 0 ;
V_487 = false ;
for (; ; ) {
T_3 V_409 [ V_410 ] ;
if ( V_489 > 5 ) {
F_70 ( L_75 ) ;
break;
}
F_276 ( V_1 -> V_11 ) ;
if ( ! F_241 ( V_1 , V_409 ) ) {
F_70 ( L_69 ) ;
break;
}
if ( ! F_275 ( V_409 , V_1 -> V_197 ) ) {
F_212 ( V_1 ) ;
F_266 ( V_1 , & V_232 ,
V_490 |
V_366 ) ;
V_489 ++ ;
continue;
}
if ( F_277 ( V_409 , V_1 -> V_197 ) ) {
V_487 = true ;
break;
}
if ( V_488 > 5 ) {
F_197 ( V_1 ) ;
F_212 ( V_1 ) ;
F_266 ( V_1 , & V_232 ,
V_490 |
V_366 ) ;
V_488 = 0 ;
V_489 ++ ;
continue;
}
if ( ! F_269 ( V_1 , & V_232 , V_409 ) ) {
F_70 ( L_73 ) ;
break;
}
++ V_488 ;
}
F_270 ( V_1 ) ;
V_1 -> V_232 = V_232 ;
if ( V_487 )
F_38 ( L_76 ) ;
}
void F_214 ( struct V_1 * V_1 )
{
F_266 ( V_1 , & V_1 -> V_232 ,
V_370 ) ;
}
static void
F_197 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_195 * V_195 =
F_112 ( V_3 -> V_4 . V_4 . V_226 ) ;
T_2 V_232 = V_1 -> V_232 ;
if ( F_36 ( F_13 ( V_7 ) ) )
return;
if ( F_36 ( ( F_25 ( V_1 -> V_172 ) & V_279 ) == 0 ) )
return;
F_38 ( L_43 ) ;
if ( F_120 ( V_7 ) && ( F_74 ( V_7 ) || V_21 != V_22 ) ) {
V_232 &= ~ V_378 ;
F_60 ( V_1 -> V_172 , V_232 | V_492 ) ;
} else {
if ( F_104 ( V_7 ) )
V_232 &= ~ V_381 ;
else
V_232 &= ~ V_382 ;
F_60 ( V_1 -> V_172 , V_232 | V_493 ) ;
}
F_113 ( V_1 -> V_172 ) ;
if ( F_278 ( V_7 ) &&
F_25 ( V_1 -> V_172 ) & V_245 ) {
struct V_277 * V_226 = V_3 -> V_4 . V_4 . V_226 ;
V_232 &= ~ V_245 ;
F_60 ( V_1 -> V_172 , V_232 ) ;
if ( F_36 ( V_226 == NULL ) ) {
F_113 ( V_1 -> V_172 ) ;
F_61 ( 50 ) ;
} else
F_279 ( V_7 , V_195 -> V_72 ) ;
}
V_232 &= ~ V_237 ;
F_60 ( V_1 -> V_172 , V_232 & ~ V_279 ) ;
F_113 ( V_1 -> V_172 ) ;
F_61 ( V_1 -> V_494 ) ;
}
static bool
F_280 ( struct V_1 * V_1 )
{
struct V_2 * V_225 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_225 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
if ( F_239 ( & V_1 -> V_145 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) < 0 )
return false ;
F_38 ( L_77 , ( int ) sizeof( V_1 -> V_11 ) , V_1 -> V_11 ) ;
if ( V_1 -> V_11 [ V_18 ] == 0 )
return false ;
memset ( V_1 -> V_298 , 0 , sizeof( V_1 -> V_298 ) ) ;
if ( F_1 ( V_1 ) ) {
F_239 ( & V_1 -> V_145 , V_495 ,
V_1 -> V_298 ,
sizeof( V_1 -> V_298 ) ) ;
if ( V_1 -> V_298 [ 0 ] & V_299 ) {
V_54 -> V_339 . V_496 = true ;
F_38 ( L_78 ) ;
}
}
if ( V_1 -> V_11 [ V_18 ] >= 0x12 &&
V_1 -> V_11 [ V_497 ] & V_498 &&
( F_8 ( V_54 ) || F_10 ( V_54 ) -> V_17 >= 8 ) ) {
V_1 -> V_491 = true ;
F_38 ( L_79 ) ;
} else
V_1 -> V_491 = false ;
if ( ! ( V_1 -> V_11 [ V_499 ] &
V_500 ) )
return true ;
if ( V_1 -> V_11 [ V_18 ] == 0x10 )
return true ;
if ( F_239 ( & V_1 -> V_145 , V_501 ,
V_1 -> V_502 ,
V_503 ) < 0 )
return false ;
return true ;
}
static void
F_281 ( struct V_1 * V_1 )
{
T_1 V_472 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_504 ] & V_505 ) )
return;
F_131 ( V_1 ) ;
if ( F_239 ( & V_1 -> V_145 , V_506 , V_472 , 3 ) == 3 )
F_38 ( L_80 ,
V_472 [ 0 ] , V_472 [ 1 ] , V_472 [ 2 ] ) ;
if ( F_239 ( & V_1 -> V_145 , V_507 , V_472 , 3 ) == 3 )
F_38 ( L_81 ,
V_472 [ 0 ] , V_472 [ 1 ] , V_472 [ 2 ] ) ;
F_138 ( V_1 , false ) ;
}
static bool
F_282 ( struct V_1 * V_1 )
{
T_1 V_472 [ 1 ] ;
if ( ! V_1 -> V_508 )
return false ;
if ( V_1 -> V_11 [ V_18 ] < 0x12 )
return false ;
F_131 ( V_1 ) ;
if ( F_239 ( & V_1 -> V_145 , V_509 , V_472 , 1 ) ) {
if ( V_472 [ 0 ] & V_510 ) {
F_38 ( L_82 ) ;
V_1 -> V_511 = true ;
} else {
F_38 ( L_83 ) ;
V_1 -> V_511 = false ;
}
}
F_138 ( V_1 , false ) ;
F_283 ( & V_1 -> V_512 , V_1 -> V_511 ) ;
return V_1 -> V_511 ;
}
int F_284 ( struct V_1 * V_1 , T_1 * V_513 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_195 * V_195 =
F_112 ( V_3 -> V_4 . V_4 . V_226 ) ;
T_1 V_472 [ 1 ] ;
if ( F_285 ( & V_1 -> V_145 , V_514 , V_472 ) < 0 )
return - V_140 ;
if ( ! ( V_472 [ 0 ] & V_515 ) )
return - V_516 ;
if ( F_153 ( & V_1 -> V_145 , V_517 ,
V_518 ) < 0 )
return - V_140 ;
F_279 ( V_7 , V_195 -> V_72 ) ;
F_279 ( V_7 , V_195 -> V_72 ) ;
if ( F_240 ( & V_1 -> V_145 , V_519 , V_513 , 6 ) < 0 )
return - V_140 ;
F_153 ( & V_1 -> V_145 , V_517 , 0 ) ;
return 0 ;
}
static bool
F_286 ( struct V_1 * V_1 , T_1 * V_520 )
{
return F_239 ( & V_1 -> V_145 ,
V_521 ,
V_520 , 1 ) == 1 ;
}
static bool
F_287 ( struct V_1 * V_1 , T_1 * V_520 )
{
int V_129 ;
V_129 = F_239 ( & V_1 -> V_145 ,
V_522 ,
V_520 , 14 ) ;
if ( V_129 != 14 )
return false ;
return true ;
}
static void
F_288 ( struct V_1 * V_1 )
{
F_153 ( & V_1 -> V_145 , V_523 , V_524 ) ;
}
static int
F_289 ( struct V_1 * V_1 )
{
bool V_525 ;
if ( V_1 -> V_511 ) {
T_1 V_526 [ 16 ] = { 0 } ;
int V_129 = 0 ;
int V_527 ;
bool V_528 ;
V_525 = F_287 ( V_1 , V_526 ) ;
V_529:
if ( V_525 == true ) {
if ( V_1 -> V_530 && ! F_277 ( & V_526 [ 10 ] , V_1 -> V_197 ) ) {
F_38 ( L_84 ) ;
F_212 ( V_1 ) ;
F_213 ( V_1 ) ;
F_214 ( V_1 ) ;
}
F_38 ( L_85 , V_526 [ 0 ] , V_526 [ 1 ] , V_526 [ 2 ] ) ;
V_129 = F_290 ( & V_1 -> V_512 , V_526 , & V_528 ) ;
if ( V_528 ) {
for ( V_527 = 0 ; V_527 < 3 ; V_527 ++ ) {
int V_531 ;
V_531 = F_267 ( & V_1 -> V_145 ,
V_522 + 1 ,
& V_526 [ 1 ] , 3 ) ;
if ( V_531 == 3 ) {
break;
}
}
V_525 = F_287 ( V_1 , V_526 ) ;
if ( V_525 == true ) {
F_38 ( L_86 , V_526 [ 0 ] , V_526 [ 1 ] , V_526 [ 2 ] ) ;
goto V_529;
}
} else
V_129 = 0 ;
return V_129 ;
} else {
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_38 ( L_87 ) ;
V_1 -> V_511 = false ;
F_283 ( & V_1 -> V_512 , V_1 -> V_511 ) ;
F_291 ( V_3 -> V_4 . V_4 . V_7 ) ;
}
}
return - V_164 ;
}
void
F_292 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_67 * V_67 = & F_2 ( V_1 ) -> V_4 ;
T_1 V_520 ;
T_1 V_409 [ V_410 ] ;
F_36 ( ! F_180 ( & V_7 -> V_341 . V_342 ) ) ;
if ( ! V_67 -> V_532 )
return;
if ( F_36 ( ! V_67 -> V_4 . V_226 ) )
return;
if ( ! F_112 ( V_67 -> V_4 . V_226 ) -> V_349 )
return;
if ( ! F_241 ( V_1 , V_409 ) ) {
return;
}
if ( ! F_280 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
F_286 ( V_1 , & V_520 ) ) {
F_153 ( & V_1 -> V_145 ,
V_521 ,
V_520 ) ;
if ( V_520 & V_533 )
F_288 ( V_1 ) ;
if ( V_520 & ( V_534 | V_535 ) )
F_117 ( L_88 ) ;
}
if ( ! F_277 ( V_409 , V_1 -> V_197 ) ) {
F_38 ( L_89 ,
V_67 -> V_4 . V_165 ) ;
F_212 ( V_1 ) ;
F_213 ( V_1 ) ;
F_214 ( V_1 ) ;
}
}
static enum V_536
F_293 ( struct V_1 * V_1 )
{
T_3 * V_11 = V_1 -> V_11 ;
T_3 type ;
if ( ! F_280 ( V_1 ) )
return V_537 ;
if ( ! ( V_11 [ V_499 ] & V_500 ) )
return V_538 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 &&
V_1 -> V_502 [ 0 ] & V_539 ) {
T_3 V_540 ;
if ( F_239 ( & V_1 -> V_145 , V_541 ,
& V_540 , 1 ) < 0 )
return V_542 ;
return F_294 ( V_540 ) ? V_538
: V_537 ;
}
if ( F_295 ( & V_1 -> V_145 . V_176 ) )
return V_538 ;
if ( V_1 -> V_11 [ V_18 ] >= 0x11 ) {
type = V_1 -> V_502 [ 0 ] & V_543 ;
if ( type == V_544 ||
type == V_545 )
return V_542 ;
} else {
type = V_1 -> V_11 [ V_499 ] &
V_546 ;
if ( type == V_547 ||
type == V_548 )
return V_542 ;
}
F_38 ( L_90 ) ;
return V_537 ;
}
static enum V_536
F_296 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_536 V_104 ;
V_104 = F_297 ( V_7 ) ;
if ( V_104 == V_542 )
V_104 = V_538 ;
return V_104 ;
}
static enum V_536
F_298 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( ! F_299 ( V_54 , V_3 ) )
return V_537 ;
return F_293 ( V_1 ) ;
}
static int F_300 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_2 V_549 ;
if ( F_24 ( V_7 ) ) {
switch ( V_3 -> V_21 ) {
case V_166 :
V_549 = V_550 ;
break;
case V_168 :
V_549 = V_551 ;
break;
case V_170 :
V_549 = V_552 ;
break;
default:
return - V_164 ;
}
} else {
switch ( V_3 -> V_21 ) {
case V_166 :
V_549 = V_553 ;
break;
case V_168 :
V_549 = V_554 ;
break;
case V_170 :
V_549 = V_555 ;
break;
default:
return - V_164 ;
}
}
if ( ( F_25 ( V_556 ) & V_549 ) == 0 )
return 0 ;
return 1 ;
}
static enum V_536
F_301 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_129 ;
if ( F_1 ( V_1 ) ) {
enum V_536 V_104 ;
V_104 = F_297 ( V_7 ) ;
if ( V_104 == V_542 )
V_104 = V_538 ;
return V_104 ;
}
V_129 = F_300 ( V_7 , V_3 ) ;
if ( V_129 == - V_164 )
return V_542 ;
else if ( V_129 == 0 )
return V_537 ;
return F_293 ( V_1 ) ;
}
static struct V_557 *
F_302 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = V_1 -> V_13 ;
if ( V_32 -> V_557 ) {
if ( F_303 ( V_32 -> V_557 ) )
return NULL ;
return F_304 ( V_32 -> V_557 ) ;
} else
return F_305 ( & V_32 -> V_4 ,
& V_1 -> V_145 . V_176 ) ;
}
static void
F_306 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = V_1 -> V_13 ;
struct V_557 * V_557 ;
V_557 = F_302 ( V_1 ) ;
V_32 -> V_558 = V_557 ;
if ( V_1 -> V_559 != V_560 )
V_1 -> V_208 = V_1 -> V_559 == V_561 ;
else
V_1 -> V_208 = F_307 ( V_557 ) ;
}
static void
F_308 ( struct V_1 * V_1 )
{
struct V_32 * V_32 = V_1 -> V_13 ;
F_309 ( V_32 -> V_558 ) ;
V_32 -> V_558 = NULL ;
V_1 -> V_208 = false ;
}
static enum V_69
F_310 ( struct V_1 * V_562 )
{
struct V_67 * V_68 = & F_2 ( V_562 ) -> V_4 ;
enum V_69 V_70 ;
V_70 = F_27 ( V_68 ) ;
F_28 ( F_311 ( V_68 -> V_4 . V_7 ) , V_70 ) ;
return V_70 ;
}
static void
F_312 ( struct V_1 * V_562 ,
enum V_69 V_70 )
{
struct V_67 * V_68 = & F_2 ( V_562 ) -> V_4 ;
F_32 ( F_311 ( V_68 -> V_4 . V_7 ) , V_70 ) ;
}
static enum V_536
F_313 ( struct V_8 * V_9 , bool V_563 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_536 V_104 ;
enum V_69 V_70 ;
bool V_129 ;
F_38 ( L_91 ,
V_9 -> V_4 . V_564 , V_9 -> V_165 ) ;
F_308 ( V_1 ) ;
if ( V_1 -> V_511 ) {
if ( V_67 -> type != V_5 )
V_67 -> type = V_565 ;
return V_537 ;
}
V_70 = F_310 ( V_1 ) ;
if ( F_1 ( V_1 ) )
V_104 = F_296 ( V_1 ) ;
else if ( F_54 ( V_7 ) )
V_104 = F_298 ( V_1 ) ;
else
V_104 = F_301 ( V_1 ) ;
if ( V_104 != V_538 )
goto V_135;
F_281 ( V_1 ) ;
V_129 = F_282 ( V_1 ) ;
if ( V_129 ) {
if ( V_67 -> type != V_5 )
V_67 -> type = V_565 ;
V_104 = V_537 ;
goto V_135;
}
F_306 ( V_1 ) ;
if ( V_67 -> type != V_5 )
V_67 -> type = V_565 ;
V_104 = V_538 ;
V_135:
F_312 ( V_1 , V_70 ) ;
return V_104 ;
}
static void
F_314 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_67 * V_67 = & F_2 ( V_1 ) -> V_4 ;
enum V_69 V_70 ;
F_38 ( L_91 ,
V_9 -> V_4 . V_564 , V_9 -> V_165 ) ;
F_308 ( V_1 ) ;
if ( V_9 -> V_104 != V_538 )
return;
V_70 = F_310 ( V_1 ) ;
F_306 ( V_1 ) ;
F_312 ( V_1 , V_70 ) ;
if ( V_67 -> type != V_5 )
V_67 -> type = V_565 ;
}
static int F_315 ( struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_557 * V_557 ;
V_557 = V_32 -> V_558 ;
if ( V_557 ) {
int V_129 = F_316 ( V_9 , V_557 ) ;
if ( V_129 )
return V_129 ;
}
if ( F_1 ( F_4 ( V_9 ) ) &&
V_32 -> V_34 . V_33 ) {
struct V_30 * V_31 ;
V_31 = F_317 ( V_9 -> V_7 ,
V_32 -> V_34 . V_33 ) ;
if ( V_31 ) {
F_318 ( V_9 , V_31 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_319 ( struct V_8 * V_9 )
{
bool V_208 = false ;
struct V_557 * V_557 ;
V_557 = F_19 ( V_9 ) -> V_558 ;
if ( V_557 )
V_208 = F_307 ( V_557 ) ;
return V_208 ;
}
static int
F_320 ( struct V_8 * V_9 ,
struct V_566 * V_567 ,
T_8 V_328 )
{
struct V_53 * V_54 = V_9 -> V_7 -> V_55 ;
struct V_32 * V_32 = F_19 ( V_9 ) ;
struct V_67 * V_67 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_67 -> V_4 ) ;
int V_129 ;
V_129 = F_321 ( & V_9 -> V_4 , V_567 , V_328 ) ;
if ( V_129 )
return V_129 ;
if ( V_567 == V_54 -> V_568 ) {
int V_49 = V_328 ;
bool V_208 ;
if ( V_49 == V_1 -> V_559 )
return 0 ;
V_1 -> V_559 = V_49 ;
if ( V_49 == V_560 )
V_208 = F_319 ( V_9 ) ;
else
V_208 = ( V_49 == V_561 ) ;
if ( V_208 == V_1 -> V_208 )
return 0 ;
V_1 -> V_208 = V_208 ;
goto V_105;
}
if ( V_567 == V_54 -> V_569 ) {
bool V_570 = V_1 -> V_215 ;
T_2 V_571 = V_1 -> V_216 ;
switch ( V_328 ) {
case V_572 :
V_1 -> V_215 = true ;
break;
case V_573 :
V_1 -> V_215 = false ;
V_1 -> V_216 = 0 ;
break;
case V_574 :
V_1 -> V_215 = false ;
V_1 -> V_216 = V_217 ;
break;
default:
return - V_164 ;
}
if ( V_570 == V_1 -> V_215 &&
V_571 == V_1 -> V_216 )
return 0 ;
goto V_105;
}
if ( F_1 ( V_1 ) &&
V_567 == V_9 -> V_7 -> V_341 . V_575 ) {
if ( V_328 == V_576 ) {
F_38 ( L_92 ) ;
return - V_164 ;
}
if ( V_32 -> V_34 . V_209 == V_328 ) {
return 0 ;
}
V_32 -> V_34 . V_209 = V_328 ;
goto V_105;
}
return - V_164 ;
V_105:
if ( V_67 -> V_4 . V_226 )
F_322 ( V_67 -> V_4 . V_226 ) ;
return 0 ;
}
static void
F_323 ( struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
F_309 ( V_32 -> V_558 ) ;
if ( ! F_324 ( V_32 -> V_557 ) )
F_309 ( V_32 -> V_557 ) ;
if ( V_9 -> V_577 == V_578 )
F_325 ( & V_32 -> V_34 ) ;
F_326 ( V_9 ) ;
F_309 ( V_9 ) ;
}
void F_327 ( struct V_478 * V_68 )
{
struct V_2 * V_3 = F_227 ( V_68 ) ;
struct V_1 * V_1 = & V_3 -> V_562 ;
F_96 ( & V_1 -> V_145 ) ;
F_328 ( V_3 ) ;
F_329 ( V_68 ) ;
if ( F_1 ( V_1 ) ) {
F_186 ( & V_1 -> V_270 ) ;
F_26 ( V_1 ) ;
F_132 ( V_1 ) ;
F_30 ( V_1 ) ;
if ( V_1 -> V_92 . V_579 ) {
F_330 ( & V_1 -> V_92 ) ;
V_1 -> V_92 . V_579 = NULL ;
}
}
F_309 ( V_3 ) ;
}
static void F_331 ( struct V_67 * V_67 )
{
struct V_1 * V_1 = F_5 ( & V_67 -> V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
F_186 ( & V_1 -> V_270 ) ;
F_26 ( V_1 ) ;
F_132 ( V_1 ) ;
F_30 ( V_1 ) ;
}
static void F_332 ( struct V_478 * V_68 )
{
F_333 ( F_334 ( V_68 ) ) ;
}
void
F_335 ( struct V_67 * V_67 )
{
return;
}
bool
F_336 ( struct V_2 * V_3 , bool V_580 )
{
struct V_1 * V_1 = & V_3 -> V_562 ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_69 V_70 ;
bool V_129 = true ;
if ( V_3 -> V_4 . type != V_5 )
V_3 -> V_4 . type = V_565 ;
if ( V_580 && V_3 -> V_4 . type == V_5 ) {
F_38 ( L_93 ,
F_40 ( V_3 -> V_21 ) ) ;
return false ;
}
F_38 ( L_94 ,
F_40 ( V_3 -> V_21 ) ,
V_580 ? L_95 : L_96 ) ;
V_70 = F_27 ( V_67 ) ;
F_28 ( V_54 , V_70 ) ;
if ( V_580 ) {
if ( F_54 ( V_7 ) ) {
if ( ! F_299 ( V_54 , V_3 ) )
goto V_581;
} else {
if ( F_300 ( V_7 , V_3 ) != 1 )
goto V_581;
}
if ( ! F_280 ( V_1 ) ) {
goto V_581;
}
F_281 ( V_1 ) ;
if ( ! F_282 ( V_1 ) )
goto V_581;
} else {
if ( V_1 -> V_511 ) {
if ( F_289 ( V_1 ) == - V_164 )
goto V_581;
}
if ( ! V_1 -> V_511 ) {
F_337 ( & V_7 -> V_341 . V_342 , NULL ) ;
F_292 ( V_1 ) ;
F_338 ( & V_7 -> V_341 . V_342 ) ;
}
}
V_129 = false ;
goto V_582;
V_581:
if ( V_1 -> V_511 ) {
F_38 ( L_97 , V_1 -> V_511 , V_1 -> V_512 . V_583 ) ;
V_1 -> V_511 = false ;
F_283 ( & V_1 -> V_512 , V_1 -> V_511 ) ;
}
V_582:
F_32 ( V_54 , V_70 ) ;
return V_129 ;
}
int
F_339 ( struct V_277 * V_226 )
{
struct V_6 * V_7 = V_226 -> V_7 ;
struct V_67 * V_67 ;
struct V_1 * V_1 ;
F_340 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_67 -> V_4 ) ;
if ( V_67 -> type == V_565 ||
V_67 -> type == V_5 )
return V_1 -> V_172 ;
}
return - 1 ;
}
bool F_341 ( struct V_6 * V_7 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
union V_584 * V_585 ;
int V_49 ;
static const short V_586 [] = {
[ V_166 ] = V_587 ,
[ V_168 ] = V_588 ,
[ V_170 ] = V_589 ,
} ;
if ( V_21 == V_22 )
return true ;
if ( ! V_54 -> V_212 . V_590 )
return false ;
for ( V_49 = 0 ; V_49 < V_54 -> V_212 . V_590 ; V_49 ++ ) {
V_585 = V_54 -> V_212 . V_591 + V_49 ;
if ( V_585 -> V_592 . V_593 == V_586 [ V_21 ] &&
( V_585 -> V_592 . V_594 & V_595 ) ==
( V_596 & V_595 ) )
return true ;
}
return false ;
}
void
F_342 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_32 * V_32 = F_19 ( V_9 ) ;
F_343 ( V_9 ) ;
F_344 ( V_9 ) ;
V_1 -> V_215 = true ;
if ( F_1 ( V_1 ) ) {
F_345 ( V_9 -> V_7 ) ;
F_346 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_341 . V_575 ,
V_597 ) ;
V_32 -> V_34 . V_209 = V_597 ;
}
}
static void F_347 ( struct V_1 * V_1 )
{
V_1 -> V_253 = V_267 ;
V_1 -> V_256 = V_267 ;
V_1 -> V_258 = V_267 ;
}
static void
F_41 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_76 * V_135 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_76 V_598 , V_212 , V_599 , V_600 ;
T_5 V_601 , V_602 , V_93 , V_262 ;
int V_94 , V_603 , V_604 , V_95 ;
F_34 ( & V_54 -> V_71 ) ;
if ( F_54 ( V_7 ) ) {
V_94 = V_86 ;
V_603 = V_605 ;
V_604 = V_606 ;
V_95 = V_607 ;
} else {
enum V_72 V_72 = F_33 ( V_1 ) ;
V_94 = F_46 ( V_72 ) ;
V_603 = F_49 ( V_72 ) ;
V_604 = F_348 ( V_72 ) ;
V_95 = F_59 ( V_72 ) ;
}
V_262 = F_130 ( V_1 ) ;
F_60 ( V_94 , V_262 ) ;
V_601 = F_25 ( V_603 ) ;
V_602 = F_25 ( V_604 ) ;
V_93 = F_25 ( V_95 ) ;
V_598 . V_608 = ( V_601 & V_609 ) >>
V_610 ;
V_598 . V_611 = ( V_601 & V_612 ) >>
V_613 ;
V_598 . V_614 = ( V_602 & V_615 ) >>
V_616 ;
V_598 . V_617 = ( V_602 & V_618 ) >>
V_619 ;
V_598 . V_620 = ( ( V_93 & V_621 ) >>
V_622 ) * 1000 ;
F_38 ( L_98 ,
V_598 . V_608 , V_598 . V_611 , V_598 . V_614 , V_598 . V_617 , V_598 . V_620 ) ;
V_212 = V_54 -> V_212 . V_623 ;
V_599 . V_608 = 210 * 10 ;
V_599 . V_611 = 50 * 10 ;
V_599 . V_614 = 50 * 10 ;
V_599 . V_617 = 500 * 10 ;
V_599 . V_620 = ( 510 + 100 ) * 10 ;
F_38 ( L_99 ,
V_212 . V_608 , V_212 . V_611 , V_212 . V_614 , V_212 . V_617 , V_212 . V_620 ) ;
#define F_349 ( T_9 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_349 ( V_608 ) ;
F_349 ( V_611 ) ;
F_349 ( V_614 ) ;
F_349 ( V_617 ) ;
F_349 ( V_620 ) ;
#undef F_349
#define F_350 ( T_9 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_265 = F_350 ( V_608 ) ;
V_1 -> V_257 = F_350 ( V_611 ) ;
V_1 -> V_259 = F_350 ( V_614 ) ;
V_1 -> V_494 = F_350 ( V_617 ) ;
V_1 -> V_100 = F_350 ( V_620 ) ;
#undef F_350
F_38 ( L_100 ,
V_1 -> V_265 , V_1 -> V_494 ,
V_1 -> V_100 ) ;
F_38 ( L_101 ,
V_1 -> V_257 , V_1 -> V_259 ) ;
if ( V_135 )
* V_135 = V_600 ;
}
static void
F_42 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_76 * V_624 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
T_5 V_601 , V_602 , V_93 , V_84 = 0 ;
int div = F_54 ( V_7 ) ? F_76 ( V_7 ) : F_23 ( V_7 ) ;
int V_603 , V_604 , V_95 ;
enum V_21 V_21 = F_2 ( V_1 ) -> V_21 ;
F_34 ( & V_54 -> V_71 ) ;
if ( F_54 ( V_7 ) ) {
V_603 = V_605 ;
V_604 = V_606 ;
V_95 = V_607 ;
} else {
enum V_72 V_72 = F_33 ( V_1 ) ;
V_603 = F_49 ( V_72 ) ;
V_604 = F_348 ( V_72 ) ;
V_95 = F_59 ( V_72 ) ;
}
V_601 = ( V_624 -> V_608 << V_610 ) |
( 1 << V_613 ) ;
V_602 = ( 1 << V_616 ) |
( V_624 -> V_617 << V_619 ) ;
V_93 = ( ( 100 * div ) / 2 - 1 ) << V_625 ;
V_93 |= ( F_75 ( V_624 -> V_620 , 1000 )
<< V_622 ) ;
if ( F_24 ( V_7 ) ) {
V_84 = F_50 ( V_21 ) ;
} else if ( F_278 ( V_7 ) || F_120 ( V_7 ) ) {
if ( V_21 == V_22 )
V_84 = V_626 ;
else
V_84 = V_627 ;
}
V_601 |= V_84 ;
F_60 ( V_603 , V_601 ) ;
F_60 ( V_604 , V_602 ) ;
F_60 ( V_95 , V_93 ) ;
F_38 ( L_102 ,
F_25 ( V_603 ) ,
F_25 ( V_604 ) ,
F_25 ( V_95 ) ) ;
}
void F_351 ( struct V_6 * V_7 , int V_628 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_67 * V_68 ;
struct V_1 * V_1 = NULL ;
struct V_178 * V_228 = NULL ;
struct V_195 * V_195 = NULL ;
struct V_32 * V_32 = V_54 -> V_629 . V_9 ;
T_5 V_540 , V_328 ;
enum V_630 V_107 = V_631 ;
if ( V_628 <= 0 ) {
F_38 ( L_103 ) ;
return;
}
if ( V_32 == NULL ) {
F_38 ( L_104 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 < 8 && F_166 ( V_7 ) ) {
F_38 ( L_105 ) ;
return;
}
V_68 = F_6 ( & V_32 -> V_4 ) ;
V_1 = F_5 ( & V_68 -> V_4 ) ;
V_195 = V_68 -> V_196 ;
if ( ! V_195 ) {
F_38 ( L_106 ) ;
return;
}
V_228 = & V_195 -> V_228 ;
if ( V_1 -> V_222 . type < V_223 ) {
F_38 ( L_107 ) ;
return;
}
if ( V_32 -> V_34 . V_221 -> V_632 == V_628 )
V_107 = V_633 ;
if ( V_107 == V_1 -> V_222 . V_634 ) {
F_38 (
L_108 ) ;
return;
}
if ( ! V_195 -> V_349 ) {
F_38 ( L_109 ) ;
return;
}
if ( F_10 ( V_7 ) -> V_17 > 6 && F_10 ( V_7 ) -> V_17 < 8 ) {
V_540 = F_352 ( V_195 -> V_228 . V_304 ) ;
V_328 = F_25 ( V_540 ) ;
if ( V_107 > V_631 ) {
V_328 |= V_635 ;
F_353 ( V_195 ) ;
} else {
V_328 &= ~ V_635 ;
}
F_60 ( V_540 , V_328 ) ;
}
F_29 ( & V_1 -> V_222 . V_343 ) ;
V_1 -> V_222 . V_634 = V_107 ;
F_31 ( & V_1 -> V_222 . V_343 ) ;
F_38 ( L_110 , V_628 ) ;
}
static struct V_30 *
F_354 ( struct V_2 * V_3 ,
struct V_32 * V_32 ,
struct V_30 * V_33 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_562 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_221 = NULL ;
if ( F_10 ( V_7 ) -> V_17 <= 6 ) {
F_38 ( L_111 ) ;
return NULL ;
}
if ( V_54 -> V_212 . V_636 != V_223 ) {
F_38 ( L_112 ) ;
return NULL ;
}
V_221 = F_355
( V_7 , V_33 , V_9 ) ;
if ( ! V_221 ) {
F_38 ( L_113 ) ;
return NULL ;
}
V_54 -> V_629 . V_9 = V_32 ;
F_195 ( & V_1 -> V_222 . V_343 ) ;
V_1 -> V_222 . type = V_54 -> V_212 . V_636 ;
V_1 -> V_222 . V_634 = V_631 ;
F_38 ( L_114 ) ;
return V_221 ;
}
void F_333 ( struct V_67 * V_67 )
{
struct V_6 * V_7 = V_67 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_1 * V_1 ;
enum V_69 V_70 ;
if ( V_67 -> type != V_5 )
return;
V_1 = F_5 ( & V_67 -> V_4 ) ;
F_26 ( V_1 ) ;
if ( ! F_63 ( V_1 ) )
goto V_135;
F_38 ( L_115 ) ;
V_70 = F_27 ( V_67 ) ;
F_28 ( V_54 , V_70 ) ;
F_135 ( V_1 ) ;
V_135:
F_30 ( V_1 ) ;
}
static bool F_356 ( struct V_1 * V_1 ,
struct V_32 * V_32 ,
struct V_76 * V_77 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_67 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_30 * V_33 = NULL ;
struct V_30 * V_221 = NULL ;
bool V_637 ;
struct V_30 * V_638 ;
struct V_557 * V_557 ;
V_1 -> V_222 . type = V_639 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_333 ( V_67 ) ;
F_131 ( V_1 ) ;
V_637 = F_280 ( V_1 ) ;
F_138 ( V_1 , false ) ;
if ( V_637 ) {
if ( V_1 -> V_11 [ V_18 ] >= 0x11 )
V_54 -> V_640 =
V_1 -> V_11 [ V_641 ] &
V_642 ;
} else {
F_357 ( L_116 ) ;
return false ;
}
F_26 ( V_1 ) ;
F_42 ( V_7 , V_1 , V_77 ) ;
F_30 ( V_1 ) ;
F_29 ( & V_7 -> V_341 . V_343 ) ;
V_557 = F_305 ( V_9 , & V_1 -> V_145 . V_176 ) ;
if ( V_557 ) {
if ( F_358 ( V_9 , V_557 ) ) {
F_359 ( V_9 ,
V_557 ) ;
F_360 ( V_9 , V_557 ) ;
} else {
F_309 ( V_557 ) ;
V_557 = F_361 ( - V_164 ) ;
}
} else {
V_557 = F_361 ( - V_643 ) ;
}
V_32 -> V_557 = V_557 ;
F_35 (scan, &connector->probed_modes, head) {
if ( ( V_638 -> type & V_644 ) ) {
V_33 = F_317 ( V_7 , V_638 ) ;
V_221 = F_354 (
V_3 ,
V_32 , V_33 ) ;
break;
}
}
if ( ! V_33 && V_54 -> V_212 . V_645 ) {
V_33 = F_317 ( V_7 ,
V_54 -> V_212 . V_645 ) ;
if ( V_33 )
V_33 -> type |= V_644 ;
}
F_31 ( & V_7 -> V_341 . V_343 ) ;
if ( F_24 ( V_7 ) ) {
V_1 -> V_92 . V_579 = F_56 ;
F_362 ( & V_1 -> V_92 ) ;
}
F_363 ( & V_32 -> V_34 , V_33 , V_221 ) ;
V_32 -> V_34 . V_646 = F_148 ;
F_364 ( V_9 ) ;
return true ;
}
bool
F_365 ( struct V_2 * V_3 ,
struct V_32 * V_32 )
{
struct V_8 * V_9 = & V_32 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_562 ;
struct V_67 * V_67 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_67 -> V_4 . V_7 ;
struct V_53 * V_54 = V_7 -> V_55 ;
enum V_21 V_21 = V_3 -> V_21 ;
struct V_76 V_77 = { 0 } ;
int type ;
V_1 -> V_78 = V_79 ;
if ( F_24 ( V_7 ) )
V_1 -> V_137 = F_80 ;
else if ( F_8 ( V_7 ) || F_82 ( V_7 ) )
V_1 -> V_137 = F_77 ;
else if ( F_54 ( V_7 ) )
V_1 -> V_137 = F_72 ;
else
V_1 -> V_137 = F_71 ;
V_1 -> V_139 = F_81 ;
V_1 -> V_232 = F_25 ( V_1 -> V_172 ) ;
V_1 -> V_13 = V_32 ;
if ( F_341 ( V_7 , V_21 ) )
type = V_578 ;
else
type = V_647 ;
if ( type == V_578 )
V_67 -> type = V_5 ;
F_38 ( L_117 ,
type == V_578 ? L_118 : L_119 ,
F_40 ( V_21 ) ) ;
F_366 ( V_7 , V_9 , & V_648 , type ) ;
F_367 ( V_9 , & V_649 ) ;
V_9 -> V_650 = true ;
V_9 -> V_651 = 0 ;
F_194 ( & V_1 -> V_270 ,
F_133 ) ;
F_368 ( V_32 , V_67 ) ;
F_369 ( V_9 ) ;
if ( F_13 ( V_7 ) )
V_32 -> V_652 = V_653 ;
else
V_32 -> V_652 = V_654 ;
V_32 -> V_655 = F_97 ;
switch ( V_21 ) {
case V_22 :
V_67 -> V_656 = V_657 ;
break;
case V_166 :
V_67 -> V_656 = V_658 ;
break;
case V_168 :
V_67 -> V_656 = V_659 ;
break;
case V_170 :
V_67 -> V_656 = V_660 ;
break;
default:
F_93 () ;
}
if ( F_1 ( V_1 ) ) {
F_26 ( V_1 ) ;
if ( F_24 ( V_7 ) ) {
F_51 ( V_1 ) ;
} else {
F_347 ( V_1 ) ;
F_41 ( V_7 , V_1 ,
& V_77 ) ;
}
F_30 ( V_1 ) ;
}
F_92 ( V_1 , V_32 ) ;
if ( F_8 ( V_7 ) || F_82 ( V_7 ) ) {
if ( V_21 == V_166 || V_21 == V_168 || V_21 == V_170 ) {
F_370 ( V_3 ,
V_32 -> V_4 . V_4 . V_564 ) ;
}
}
if ( ! F_356 ( V_1 , V_32 , & V_77 ) ) {
F_96 ( & V_1 -> V_145 ) ;
if ( F_1 ( V_1 ) ) {
F_186 ( & V_1 -> V_270 ) ;
F_26 ( V_1 ) ;
F_132 ( V_1 ) ;
F_30 ( V_1 ) ;
}
F_371 ( V_9 ) ;
F_326 ( V_9 ) ;
return false ;
}
F_342 ( V_1 , V_9 ) ;
if ( F_102 ( V_7 ) && ! F_372 ( V_7 ) ) {
T_5 V_365 = F_25 ( V_661 ) ;
F_60 ( V_661 , ( V_365 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_373 ( struct V_6 * V_7 , int V_172 , enum V_21 V_21 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
struct V_2 * V_3 ;
struct V_67 * V_67 ;
struct V_478 * V_68 ;
struct V_32 * V_32 ;
V_3 = F_374 ( sizeof( * V_3 ) , V_662 ) ;
if ( ! V_3 )
return;
V_32 = F_374 ( sizeof( * V_32 ) , V_662 ) ;
if ( ! V_32 ) {
F_309 ( V_3 ) ;
return;
}
V_67 = & V_3 -> V_4 ;
V_68 = & V_67 -> V_4 ;
F_375 ( V_7 , & V_67 -> V_4 , & V_663 ,
V_664 ) ;
V_67 -> V_665 = F_105 ;
V_67 -> V_666 = F_196 ;
V_67 -> V_652 = F_154 ;
V_67 -> V_667 = F_161 ;
V_67 -> V_668 = F_331 ;
if ( F_104 ( V_7 ) ) {
V_67 -> V_669 = F_236 ;
V_67 -> V_670 = F_233 ;
V_67 -> V_275 = F_216 ;
V_67 -> V_671 = F_200 ;
} else if ( F_24 ( V_7 ) ) {
V_67 -> V_669 = F_226 ;
V_67 -> V_670 = F_220 ;
V_67 -> V_275 = F_216 ;
V_67 -> V_671 = F_199 ;
} else {
V_67 -> V_670 = F_217 ;
V_67 -> V_275 = F_215 ;
if ( F_10 ( V_7 ) -> V_17 >= 5 )
V_67 -> V_671 = F_198 ;
}
V_3 -> V_21 = V_21 ;
V_3 -> V_562 . V_172 = V_172 ;
V_67 -> type = V_565 ;
if ( F_104 ( V_7 ) ) {
if ( V_21 == V_170 )
V_67 -> V_672 = 1 << 2 ;
else
V_67 -> V_672 = ( 1 << 0 ) | ( 1 << 1 ) ;
} else {
V_67 -> V_672 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
}
V_67 -> V_673 = 0 ;
V_67 -> V_674 = F_335 ;
V_3 -> V_675 = F_336 ;
V_54 -> V_676 [ V_21 ] = V_3 ;
if ( ! F_365 ( V_3 , V_32 ) ) {
F_329 ( V_68 ) ;
F_309 ( V_3 ) ;
F_309 ( V_32 ) ;
}
}
void F_376 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_677 ; V_49 ++ ) {
struct V_2 * V_3 = V_54 -> V_676 [ V_49 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_565 ) {
if ( ! V_3 -> V_562 . V_508 )
continue;
if ( V_3 -> V_562 . V_511 )
F_377 ( & V_3 -> V_562 . V_512 ) ;
}
}
}
void F_378 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = V_7 -> V_55 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_677 ; V_49 ++ ) {
struct V_2 * V_3 = V_54 -> V_676 [ V_49 ] ;
if ( ! V_3 )
continue;
if ( V_3 -> V_4 . type == V_565 ) {
int V_129 ;
if ( ! V_3 -> V_562 . V_508 )
continue;
V_129 = F_379 ( & V_3 -> V_562 . V_512 ) ;
if ( V_129 != 0 ) {
F_289 ( & V_3 -> V_562 ) ;
}
}
}
}
