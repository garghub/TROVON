static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = V_11 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_12 )
{
if ( V_12 == V_13 )
return F_3 ( V_2 ) ;
else if ( V_12 == V_14 )
return V_15 ;
else
return - V_16 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_17 * V_18 , T_1 * V_19 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
int V_22 , V_23 ;
char * V_24 ;
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
V_24 = ( char * ) V_21 + V_26 [ V_22 ] . V_27 ;
V_19 [ V_22 ] = * ( T_1 * ) V_24 ;
}
for ( V_23 = 0 ; V_23 < V_21 -> V_28 ; V_23 ++ ) {
V_19 [ V_22 ++ ] = V_21 -> V_29 [ V_23 ] . V_18 . V_30 ;
V_19 [ V_22 ++ ] = V_21 -> V_29 [ V_23 ] . V_18 . V_31 ;
}
for ( V_23 = 0 ; V_23 < V_21 -> V_28 ; V_23 ++ ) {
V_19 [ V_22 ++ ] = V_21 -> V_32 [ V_23 ] . V_18 . V_30 ;
V_19 [ V_22 ++ ] = V_21 -> V_32 [ V_23 ] . V_18 . V_31 ;
}
}
static void F_6 ( struct V_1 * V_2 , T_2 V_12 , T_3 * V_19 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
T_3 * V_24 = V_19 ;
int V_22 ;
if ( V_12 == V_13 ) {
for ( V_22 = 0 ; V_22 < V_25 ; V_22 ++ ) {
memcpy ( V_24 , V_26 [ V_22 ] . V_33 ,
V_34 ) ;
V_24 += V_34 ;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_28 ; V_22 ++ ) {
snprintf ( V_24 , V_34 , L_1 , V_22 ) ;
V_24 += V_34 ;
snprintf ( V_24 , V_34 , L_2 , V_22 ) ;
V_24 += V_34 ;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_28 ; V_22 ++ ) {
snprintf ( V_24 , V_34 , L_3 , V_22 ) ;
V_24 += V_34 ;
snprintf ( V_24 , V_34 , L_4 , V_22 ) ;
V_24 += V_34 ;
}
} else if ( V_12 == V_14 ) {
for ( V_22 = 0 ; V_22 < V_15 ; V_22 ++ ) {
memcpy ( V_19 , V_35 [ V_22 ] ,
V_34 ) ;
V_19 += V_34 ;
}
}
}
static T_2 F_7 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
return V_21 -> V_36 ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_19 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
if ( V_37 & V_19 )
V_21 -> V_38 . V_39 = V_19 ;
V_21 -> V_36 = V_19 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_40 * V_41 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
F_10 ( V_41 -> V_42 , V_43 , 32 ) ;
F_10 ( V_41 -> V_44 , V_45 , 32 ) ;
F_10 ( V_41 -> V_46 , L_5 , 4 ) ;
F_10 ( V_41 -> V_47 , F_11 ( V_21 -> V_48 ) , 32 ) ;
V_41 -> V_49 = V_15 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
V_51 -> V_52 = V_53 ;
V_51 -> V_54 = V_55 ;
V_51 -> V_56 = V_21 -> V_57 ;
V_51 -> V_58 = V_21 -> V_59 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
T_2 V_60 , V_61 ;
if ( ( V_51 -> V_62 ) || ( V_51 -> V_63 ) )
return - V_16 ;
V_61 = F_14 ( T_2 , V_51 -> V_58 ,
V_64 ,
V_55 ) ;
V_61 = F_15 ( V_61 , V_65 ) ;
V_60 = F_14 ( T_2 , V_51 -> V_56 ,
V_66 ,
V_53 ) ;
V_60 = F_15 ( V_60 , V_65 ) ;
if ( ( V_61 == V_21 -> V_59 ) &&
( V_60 == V_21 -> V_57 ) )
return 0 ;
V_21 -> V_59 = V_61 ;
V_21 -> V_57 = V_60 ;
if ( F_16 ( V_2 ) ) {
V_21 -> V_67 |= V_68 ;
F_17 ( & V_21 -> V_69 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
struct V_72 * V_73 = & V_21 -> V_73 ;
V_71 -> V_74 = V_73 -> V_75 ;
V_71 -> V_76 = V_73 -> V_75 ;
if ( F_19 ( V_73 -> V_77 ) )
V_71 -> V_78 = 1 ;
if ( F_19 ( V_73 -> V_79 ) )
V_71 -> V_80 = 1 ;
V_71 -> V_81 = V_73 -> V_77 & ~ V_82 ;
V_71 -> V_83 = V_73 -> V_79 & ~ V_82 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
struct V_84 * V_38 = & V_21 -> V_38 ;
struct V_72 * V_73 = & V_21 -> V_73 ;
struct V_85 * V_86 ;
int V_22 ;
if ( V_71 -> V_87 || V_71 -> V_88 )
V_73 -> V_75 = V_71 -> V_87 ;
if ( ( V_71 -> V_81 >= ( V_89 << 1 ) ) &&
( V_71 -> V_81 <= ( V_90 << 1 ) ) )
V_73 -> V_77 = V_71 -> V_81 ;
else
return - V_16 ;
if ( ( V_71 -> V_83 >= ( V_89 << 1 ) ) &&
( V_71 -> V_83 <= ( V_90 << 1 ) ) )
V_73 -> V_79 = V_71 -> V_83 ;
else if ( V_71 -> V_80 )
V_73 -> V_79 = ( V_82 |
F_21 ( V_91 ) ) ;
else
return - V_16 ;
if ( V_71 -> V_78 )
V_73 -> V_77 |= V_82 ;
else
V_73 -> V_77 &= ~ V_82 ;
if ( V_71 -> V_80 )
V_73 -> V_79 |= V_82 ;
else
V_73 -> V_79 &= ~ V_82 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_92 - V_93 ; V_22 ++ ) {
V_86 = & V_21 -> V_94 [ V_22 ] ;
V_86 -> V_95 . V_96 = F_22 ( V_73 -> V_77 ) ;
F_23 ( V_38 , F_24 ( 0 , V_22 ) , V_86 -> V_95 . V_96 ) ;
V_86 -> V_97 . V_96 = F_22 ( V_73 -> V_79 ) ;
F_23 ( V_38 , F_24 ( 1 , V_22 ) , V_86 -> V_97 . V_96 ) ;
F_25 ( V_38 ) ;
}
return 0 ;
}
static int F_26 ( struct V_20 * V_21 ,
struct V_98 * V_99 )
{
struct V_84 * V_38 = & V_21 -> V_38 ;
T_1 V_100 = ( T_1 ) F_27 ( V_38 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_38 , F_28 ( 1 ) ) << 32 ) ;
V_99 -> V_19 = V_101 | V_102 ;
switch ( V_99 -> V_103 ) {
case V_104 :
if ( V_100 & F_29 ( V_105 ) )
V_99 -> V_19 |= V_106 | V_107 ;
break;
case V_108 :
if ( V_100 & F_29 ( V_109 ) )
V_99 -> V_19 |= V_106 | V_107 ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
break;
case V_115 :
if ( V_100 & F_29 ( V_116 ) )
V_99 -> V_19 |= V_106 | V_107 ;
break;
case V_117 :
if ( V_100 & F_29 ( V_118 ) )
V_99 -> V_19 |= V_106 | V_107 ;
break;
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
break;
default:
V_99 -> V_19 = 0 ;
return - V_16 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
T_2 * V_124 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
int V_125 = - V_126 ;
switch ( V_99 -> V_99 ) {
case V_127 :
V_99 -> V_19 = V_21 -> V_28 ;
V_125 = 0 ;
break;
case V_128 :
V_125 = F_26 ( V_21 , V_99 ) ;
break;
default:
break;
}
return V_125 ;
}
static int F_31 ( struct V_20 * V_21 ,
struct V_98 * V_129 )
{
struct V_84 * V_38 = & V_21 -> V_38 ;
T_2 V_67 = V_21 -> V_130 -> V_131 ;
T_1 V_100 = ( T_1 ) F_27 ( V_38 , F_28 ( 0 ) ) |
( ( T_1 ) F_27 ( V_38 , F_28 ( 1 ) ) << 32 ) ;
if ( V_129 -> V_19 & ~ ( V_101 | V_102 |
V_106 | V_107 ) )
return - V_16 ;
if ( ! ( V_129 -> V_19 & V_101 ) ||
! ( V_129 -> V_19 & V_102 ) )
return - V_16 ;
switch ( V_129 -> V_103 ) {
case V_104 :
if ( V_129 -> V_19 & ( V_106 | V_107 ) ) {
if ( V_67 & V_132 )
V_100 |=
F_29 ( V_133 ) ;
V_100 |= F_29 ( V_105 ) ;
} else {
return - V_16 ;
}
break;
case V_115 :
if ( V_129 -> V_19 & ( V_106 | V_107 ) ) {
if ( V_67 & V_132 )
V_100 |=
F_29 ( V_134 ) ;
V_100 |= F_29 ( V_116 ) ;
} else {
return - V_16 ;
}
break;
case V_108 :
if ( V_129 -> V_19 & ( V_106 | V_107 ) ) {
if ( V_67 & V_132 )
V_100 |=
F_29 ( V_135 ) |
F_29 ( V_136 ) ;
V_100 |= ( F_29 ( V_109 ) |
F_29 ( V_137 ) ) ;
} else {
return - V_16 ;
}
break;
case V_117 :
if ( V_129 -> V_19 & ( V_106 | V_107 ) ) {
if ( V_67 & V_132 )
V_100 |=
F_29 ( V_138 ) |
F_29 ( V_139 ) ;
V_100 |= ( F_29 ( V_118 ) |
F_29 ( V_140 ) ) ;
} else {
return - V_16 ;
}
break;
case V_111 :
case V_112 :
case V_113 :
case V_110 :
if ( ( V_129 -> V_19 & V_106 ) ||
( V_129 -> V_19 & V_107 ) )
return - V_16 ;
V_100 |= F_29 ( V_141 ) ;
break;
case V_120 :
case V_121 :
case V_122 :
case V_119 :
if ( ( V_129 -> V_19 & V_106 ) ||
( V_129 -> V_19 & V_107 ) )
return - V_16 ;
V_100 |= F_29 ( V_142 ) ;
break;
case V_114 :
V_100 |= ( F_29 ( V_141 ) |
F_29 ( V_137 ) ) ;
break;
case V_123 :
V_100 |= ( F_29 ( V_142 ) |
F_29 ( V_140 ) ) ;
break;
default:
return - V_16 ;
}
F_23 ( V_38 , F_28 ( 0 ) , ( T_2 ) V_100 ) ;
F_23 ( V_38 , F_28 ( 1 ) , ( T_2 ) ( V_100 >> 32 ) ) ;
F_25 ( V_38 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
int V_125 = - V_126 ;
switch ( V_99 -> V_99 ) {
case V_143 :
V_125 = F_31 ( V_21 , V_99 ) ;
break;
default:
break;
}
return V_125 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
V_145 -> V_146 = V_21 -> V_28 ;
V_145 -> V_147 = V_93 ;
V_145 -> V_148 = V_93 ;
V_145 -> V_149 = V_21 -> V_28 ;
}
static T_2 F_34 ( struct V_1 * V_2 )
{
return ( V_150 + 1 ) * 4 ;
}
static int F_35 ( struct V_1 * V_2 , T_2 * V_151 , T_3 * V_152 ,
T_3 * V_153 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
struct V_72 * V_73 = & V_21 -> V_73 ;
T_3 * V_154 = NULL , * V_155 ;
int V_125 ;
T_4 V_22 ;
if ( V_153 )
* V_153 = V_156 ;
if ( ! V_151 )
return 0 ;
V_154 = V_152 ;
V_155 = F_36 ( V_157 , V_158 ) ;
if ( ! V_155 )
return - V_159 ;
V_125 = F_37 ( V_73 , V_154 , V_155 , V_157 ) ;
if ( V_125 )
goto V_160;
for ( V_22 = 0 ; V_22 < V_157 ; V_22 ++ )
V_151 [ V_22 ] = ( T_2 ) V_155 [ V_22 ] ;
V_160:
F_38 ( V_155 ) ;
return V_125 ;
}
static int F_39 ( struct V_1 * V_2 , const T_2 * V_151 ,
const T_3 * V_152 , const T_3 V_153 )
{
struct V_20 * V_21 = F_5 ( V_2 ) ;
struct V_72 * V_73 = & V_21 -> V_73 ;
T_3 * V_154 = NULL ;
T_4 V_22 ;
if ( V_152 ||
( V_153 != V_161 && V_153 != V_156 ) )
return - V_126 ;
if ( ! V_151 )
return 0 ;
if ( V_152 ) {
if ( ! V_73 -> V_162 ) {
V_73 -> V_162 = F_36 ( V_163 ,
V_158 ) ;
if ( ! V_73 -> V_162 )
return - V_159 ;
}
memcpy ( V_73 -> V_162 , V_152 , V_163 ) ;
V_154 = V_73 -> V_162 ;
}
if ( ! V_73 -> V_164 ) {
V_73 -> V_164 = F_36 ( V_157 ,
V_158 ) ;
if ( ! V_73 -> V_164 )
return - V_159 ;
}
for ( V_22 = 0 ; V_22 < V_157 ; V_22 ++ )
V_73 -> V_164 [ V_22 ] = ( T_3 ) ( V_151 [ V_22 ] ) ;
return F_40 ( V_73 , V_154 , V_73 -> V_164 ,
V_157 ) ;
}
static T_2 F_41 ( struct V_1 * V_165 )
{
struct V_20 * V_21 = F_5 ( V_165 ) ;
T_2 V_166 = 0 ;
V_166 |= V_21 -> V_67 & V_167 ?
V_168 : 0 ;
return V_166 ;
}
static int F_42 ( struct V_1 * V_165 , T_2 V_67 )
{
struct V_20 * V_21 = F_5 ( V_165 ) ;
bool V_169 = false ;
if ( ( V_67 & V_168 ) &&
! ( V_21 -> V_67 & V_167 ) ) {
V_21 -> V_67 |= V_167 ;
V_169 = true ;
} else if ( ! ( V_67 & V_168 ) &&
( V_21 -> V_67 & V_167 ) ) {
V_21 -> V_67 &= ~ V_167 ;
V_169 = true ;
}
if ( V_169 )
F_43 ( V_21 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_170 = & V_171 ;
}
