static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_7 ) ;
V_4 -> V_8 . V_9 = V_10 ;
V_4 -> V_8 . V_11 = V_12 ;
switch ( V_6 -> V_13 ) {
case V_14 :
V_4 -> V_8 . V_15 = V_16 ;
break;
case V_17 :
#ifdef F_4
V_4 -> V_8 . V_15 = F_4 ;
#else
F_5 ( V_2 ,
L_1 ) ;
#endif
break;
case V_18 :
V_4 -> V_8 . V_15 = V_19 ;
break;
case V_20 :
V_4 -> V_8 . V_15 = V_21 ;
break;
case V_22 :
V_4 -> V_8 . V_15 = V_23 ;
break;
case V_24 :
V_4 -> V_8 . V_15 = V_25 ;
break;
default:
break;
}
V_4 -> V_8 . V_26 = V_27 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_28 )
{
if ( V_28 == V_29 )
return F_7 ( V_2 ) ;
else if ( V_28 == V_30 )
return V_31 ;
else
return - V_32 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 * V_35 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_36 , V_37 ;
char * V_38 ;
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
V_38 = ( char * ) V_6 + V_40 [ V_36 ] . V_41 ;
V_35 [ V_36 ] = * ( T_1 * ) V_38 ;
}
for ( V_37 = 0 ; V_37 < V_6 -> V_42 ; V_37 ++ ) {
V_35 [ V_36 ++ ] = V_6 -> V_43 [ V_37 ] . V_34 . V_44 ;
V_35 [ V_36 ++ ] = V_6 -> V_43 [ V_37 ] . V_34 . V_45 ;
}
for ( V_37 = 0 ; V_37 < V_6 -> V_42 ; V_37 ++ ) {
V_35 [ V_36 ++ ] = V_6 -> V_46 [ V_37 ] . V_34 . V_44 ;
V_35 [ V_36 ++ ] = V_6 -> V_46 [ V_37 ] . V_34 . V_45 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_2 V_28 , T_3 * V_35 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 * V_38 = V_35 ;
int V_36 ;
if ( V_28 == V_29 ) {
for ( V_36 = 0 ; V_36 < ( int ) V_39 ; V_36 ++ ) {
memcpy ( V_38 , V_40 [ V_36 ] . V_47 ,
V_48 ) ;
V_38 += V_48 ;
}
for ( V_36 = 0 ; V_36 < V_6 -> V_42 ; V_36 ++ ) {
snprintf ( V_38 , V_48 , L_2 , V_36 ) ;
V_38 += V_48 ;
snprintf ( V_38 , V_48 , L_3 , V_36 ) ;
V_38 += V_48 ;
}
for ( V_36 = 0 ; V_36 < V_6 -> V_42 ; V_36 ++ ) {
snprintf ( V_38 , V_48 , L_4 , V_36 ) ;
V_38 += V_48 ;
snprintf ( V_38 , V_48 , L_5 , V_36 ) ;
V_38 += V_48 ;
}
} else if ( V_28 == V_30 ) {
for ( V_36 = 0 ; V_36 < V_31 ; V_36 ++ ) {
snprintf ( V_38 , V_48 , L_6 ,
V_49 [ V_36 ] . V_50 ) ;
V_38 += V_48 ;
}
}
}
static T_2 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_36 , V_51 = 0 ;
for ( V_36 = 0 ; V_36 < V_31 ; V_36 ++ ) {
const struct V_52 * V_53 ;
V_53 = & V_49 [ V_36 ] ;
if ( V_53 -> V_54 & V_6 -> V_55 )
V_51 |= F_11 ( V_36 ) ;
}
return V_51 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_56 , V_57 , V_58 ;
T_2 V_36 ;
V_56 = F_13 ( V_6 -> V_55 ) ;
V_57 = V_56 ;
for ( V_36 = 0 ; V_36 < V_31 ; V_36 ++ ) {
const struct V_52 * V_53 ;
V_53 = & V_49 [ V_36 ] ;
if ( V_55 & F_11 ( V_36 ) )
V_57 |= V_53 -> V_54 ;
else
V_57 &= ~ ( V_53 -> V_54 ) ;
if ( V_53 -> V_59 &&
( ( V_56 ^ V_57 ) & ~ F_11 ( V_36 ) ) )
return - V_60 ;
}
if ( F_14 ( & V_6 -> V_55 , V_56 , V_57 ) != V_56 ) {
F_15 ( & V_6 -> V_61 -> V_62 ,
L_7 ) ;
return - V_63 ;
}
V_58 = V_56 ^ V_57 ;
if ( V_58 & V_64 ) {
if ( F_16 ( V_2 ) ) {
V_6 -> V_55 |= V_65 ;
F_17 ( & V_6 -> V_66 ) ;
}
}
return 0 ;
}
static T_2 F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_67 ;
}
static void F_19 ( struct V_1 * V_2 , T_2 V_35 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_68 & V_35 )
V_6 -> V_69 . V_70 = V_35 ;
V_6 -> V_67 = V_35 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_21 ( V_72 -> V_73 , V_74 , 32 ) ;
F_21 ( V_72 -> V_75 , V_76 , 32 ) ;
F_21 ( V_72 -> V_77 , L_8 , 4 ) ;
F_21 ( V_72 -> V_78 , F_22 ( V_6 -> V_61 ) , 32 ) ;
V_72 -> V_79 = V_31 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_81 -> V_82 = V_83 ;
V_81 -> V_84 = V_85 ;
V_81 -> V_86 = V_6 -> V_87 ;
V_81 -> V_88 = V_6 -> V_89 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_90 , V_91 ;
if ( ( V_81 -> V_92 ) || ( V_81 -> V_93 ) )
return - V_32 ;
V_91 = F_25 ( T_2 , V_81 -> V_88 ,
V_94 ,
V_85 ) ;
V_91 = F_26 ( V_91 , V_95 ) ;
V_90 = F_25 ( T_2 , V_81 -> V_86 ,
V_96 ,
V_83 ) ;
V_90 = F_26 ( V_90 , V_95 ) ;
if ( ( V_91 == V_6 -> V_89 ) &&
( V_90 == V_6 -> V_87 ) )
return 0 ;
V_6 -> V_89 = V_91 ;
V_6 -> V_87 = V_90 ;
if ( F_16 ( V_2 ) ) {
V_6 -> V_55 |= V_65 ;
F_17 ( & V_6 -> V_66 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
int V_99 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_100 * V_101 = & V_6 -> V_101 ;
struct V_102 * V_103 , * V_104 ;
V_98 -> V_105 = V_101 -> V_106 ;
V_98 -> V_107 = V_101 -> V_106 ;
if ( V_99 < 0 )
V_99 = 0 ;
else if ( V_99 >= V_6 -> V_42 )
return - V_32 ;
V_103 = & V_6 -> V_46 [ V_99 ] ;
V_104 = & V_6 -> V_43 [ V_99 ] ;
if ( F_28 ( V_103 -> V_108 ) )
V_98 -> V_109 = 1 ;
if ( F_28 ( V_104 -> V_110 ) )
V_98 -> V_111 = 1 ;
V_98 -> V_112 = V_103 -> V_108 & ~ V_113 ;
V_98 -> V_114 = V_104 -> V_110 & ~ V_113 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
return F_27 ( V_2 , V_98 , - 1 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
T_2 V_99 ,
struct V_97 * V_98 )
{
return F_27 ( V_2 , V_98 , V_99 ) ;
}
static void F_31 ( struct V_5 * V_6 ,
struct V_97 * V_98 ,
int V_99 )
{
struct V_100 * V_101 = & V_6 -> V_101 ;
struct V_115 * V_69 = & V_6 -> V_69 ;
struct V_116 * V_117 ;
T_4 V_118 ;
V_6 -> V_46 [ V_99 ] . V_108 = V_98 -> V_112 ;
V_6 -> V_43 [ V_99 ] . V_110 = V_98 -> V_114 ;
if ( V_98 -> V_109 )
V_6 -> V_46 [ V_99 ] . V_108 |= V_113 ;
else
V_6 -> V_46 [ V_99 ] . V_108 &= ~ V_113 ;
if ( V_98 -> V_111 )
V_6 -> V_43 [ V_99 ] . V_110 |= V_113 ;
else
V_6 -> V_43 [ V_99 ] . V_110 &= ~ V_113 ;
V_117 = V_6 -> V_46 [ V_99 ] . V_117 ;
V_117 -> V_119 . V_120 = F_32 ( V_6 -> V_46 [ V_99 ] . V_108 ) ;
V_118 = V_101 -> V_121 + V_117 -> V_122 ;
F_33 ( V_69 , F_34 ( V_123 , V_118 - 1 ) , V_117 -> V_119 . V_120 ) ;
V_117 = V_6 -> V_43 [ V_99 ] . V_117 ;
V_117 -> V_124 . V_120 = F_32 ( V_6 -> V_43 [ V_99 ] . V_110 ) ;
V_118 = V_101 -> V_121 + V_117 -> V_122 ;
F_33 ( V_69 , F_34 ( V_125 , V_118 - 1 ) , V_117 -> V_124 . V_120 ) ;
F_35 ( V_69 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
int V_99 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_100 * V_101 = & V_6 -> V_101 ;
int V_36 ;
if ( V_98 -> V_126 || V_98 -> V_127 )
V_101 -> V_106 = V_98 -> V_126 ;
if ( V_98 -> V_112 == 0 ) {
if ( V_98 -> V_109 )
F_37 ( V_6 , V_128 , V_2 , L_9 ) ;
} else if ( ( V_98 -> V_112 < ( V_129 << 1 ) ) ||
( V_98 -> V_112 > ( V_130 << 1 ) ) ) {
F_37 ( V_6 , V_128 , V_2 , L_10 ) ;
return - V_32 ;
}
else
if ( V_98 -> V_114 == 0 ) {
if ( V_98 -> V_111 )
F_37 ( V_6 , V_128 , V_2 , L_11 ) ;
} else if ( ( V_98 -> V_114 < ( V_129 << 1 ) ) ||
( V_98 -> V_114 > ( V_130 << 1 ) ) ) {
F_37 ( V_6 , V_128 , V_2 , L_12 ) ;
return - V_32 ;
}
if ( V_99 < 0 ) {
for ( V_36 = 0 ; V_36 < V_6 -> V_42 ; V_36 ++ )
F_31 ( V_6 , V_98 , V_36 ) ;
} else if ( V_99 < V_6 -> V_42 ) {
F_31 ( V_6 , V_98 , V_99 ) ;
} else {
F_37 ( V_6 , V_128 , V_2 , L_13 ,
V_6 -> V_42 - 1 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
return F_36 ( V_2 , V_98 , - 1 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
T_2 V_99 ,
struct V_97 * V_98 )
{
return F_36 ( V_2 , V_98 , V_99 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_131 * V_4 ,
T_2 * V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_133 = - V_60 ;
switch ( V_4 -> V_4 ) {
case V_134 :
V_4 -> V_35 = V_6 -> V_42 ;
V_133 = 0 ;
break;
case V_135 :
F_5 ( V_2 ,
L_14 ) ;
break;
default:
break;
}
return V_133 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_136 * V_137 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_137 -> V_138 = V_6 -> V_42 ;
V_137 -> V_139 = V_140 ;
V_137 -> V_141 = V_140 ;
V_137 -> V_142 = V_6 -> V_42 ;
}
static T_2 F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_143 ;
}
static T_2 F_43 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_144 ;
}
static int F_44 ( struct V_1 * V_2 , T_2 * V_145 , T_3 * V_146 ,
T_3 * V_147 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_36 ;
if ( V_147 )
* V_147 = V_148 ;
if ( ! V_145 )
return 0 ;
memcpy ( V_146 , V_6 -> V_149 , V_6 -> V_143 ) ;
for ( V_36 = 0 ; V_36 < V_6 -> V_144 ; V_36 ++ )
V_145 [ V_36 ] = ( T_2 ) V_6 -> V_150 [ V_36 ] ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , const T_2 * V_145 ,
const T_3 * V_146 , const T_3 V_147 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_36 ;
if ( V_146 ||
( V_147 != V_151 && V_147 != V_148 ) )
return - V_60 ;
if ( ! V_145 )
return 0 ;
if ( V_146 ) {
memcpy ( V_6 -> V_149 , V_146 , V_6 -> V_143 ) ;
}
for ( V_36 = 0 ; V_36 < V_6 -> V_144 ; V_36 ++ )
V_6 -> V_150 [ V_36 ] = ( T_3 ) ( V_145 [ V_36 ] ) ;
return F_46 ( V_6 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
V_2 -> V_152 = & V_153 ;
}
