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
int V_36 , V_37 ;
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
for ( V_36 = 0 ; V_36 < V_39 ; V_36 ++ ) {
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
T_1 V_56 ;
T_2 V_36 ;
V_56 = V_6 -> V_55 ;
for ( V_36 = 0 ; V_36 < V_31 ; V_36 ++ ) {
const struct V_52 * V_53 ;
V_53 = & V_49 [ V_36 ] ;
if ( V_53 -> V_57 )
continue;
if ( V_55 & F_11 ( V_36 ) )
V_6 -> V_55 |= V_53 -> V_54 ;
else
V_6 -> V_55 &= ~ ( V_53 -> V_54 ) ;
}
V_56 ^= V_6 -> V_55 ;
if ( V_56 & V_58 ) {
if ( F_13 ( V_2 ) ) {
V_6 -> V_55 |= V_59 ;
F_14 ( & V_6 -> V_60 ) ;
}
}
return 0 ;
}
static T_2 F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_61 ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_35 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_62 & V_35 )
V_6 -> V_63 . V_64 = V_35 ;
V_6 -> V_61 = V_35 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_18 ( V_66 -> V_67 , V_68 , 32 ) ;
F_18 ( V_66 -> V_69 , V_70 , 32 ) ;
F_18 ( V_66 -> V_71 , L_7 , 4 ) ;
F_18 ( V_66 -> V_72 , F_19 ( V_6 -> V_73 ) , 32 ) ;
V_66 -> V_74 = V_31 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_76 -> V_77 = V_78 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = V_6 -> V_82 ;
V_76 -> V_83 = V_6 -> V_84 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_85 , V_86 ;
if ( ( V_76 -> V_87 ) || ( V_76 -> V_88 ) )
return - V_32 ;
V_86 = F_22 ( T_2 , V_76 -> V_83 ,
V_89 ,
V_80 ) ;
V_86 = F_23 ( V_86 , V_90 ) ;
V_85 = F_22 ( T_2 , V_76 -> V_81 ,
V_91 ,
V_78 ) ;
V_85 = F_23 ( V_85 , V_90 ) ;
if ( ( V_86 == V_6 -> V_84 ) &&
( V_85 == V_6 -> V_82 ) )
return 0 ;
V_6 -> V_84 = V_86 ;
V_6 -> V_82 = V_85 ;
if ( F_13 ( V_2 ) ) {
V_6 -> V_55 |= V_59 ;
F_14 ( & V_6 -> V_60 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
int V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_95 * V_96 = & V_6 -> V_96 ;
struct V_97 * V_98 , * V_99 ;
V_93 -> V_100 = V_96 -> V_101 ;
V_93 -> V_102 = V_96 -> V_101 ;
if ( V_94 < 0 )
V_94 = 0 ;
else if ( V_94 >= V_6 -> V_42 )
return - V_32 ;
V_98 = & V_6 -> V_46 [ V_94 ] ;
V_99 = & V_6 -> V_43 [ V_94 ] ;
if ( F_25 ( V_98 -> V_103 ) )
V_93 -> V_104 = 1 ;
if ( F_25 ( V_99 -> V_105 ) )
V_93 -> V_106 = 1 ;
V_93 -> V_107 = V_98 -> V_103 & ~ V_108 ;
V_93 -> V_109 = V_99 -> V_105 & ~ V_108 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
return F_24 ( V_2 , V_93 , - 1 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
T_2 V_94 ,
struct V_92 * V_93 )
{
return F_24 ( V_2 , V_93 , V_94 ) ;
}
static void F_28 ( struct V_5 * V_6 ,
struct V_92 * V_93 ,
int V_94 )
{
struct V_95 * V_96 = & V_6 -> V_96 ;
struct V_110 * V_63 = & V_6 -> V_63 ;
struct V_111 * V_112 ;
T_4 V_113 ;
V_6 -> V_46 [ V_94 ] . V_103 = V_93 -> V_107 ;
V_6 -> V_43 [ V_94 ] . V_105 = V_93 -> V_109 ;
if ( V_93 -> V_104 )
V_6 -> V_46 [ V_94 ] . V_103 |= V_108 ;
else
V_6 -> V_46 [ V_94 ] . V_103 &= ~ V_108 ;
if ( V_93 -> V_106 )
V_6 -> V_43 [ V_94 ] . V_105 |= V_108 ;
else
V_6 -> V_43 [ V_94 ] . V_105 &= ~ V_108 ;
V_112 = V_6 -> V_46 [ V_94 ] . V_112 ;
V_112 -> V_114 . V_115 = F_29 ( V_6 -> V_46 [ V_94 ] . V_103 ) ;
V_113 = V_96 -> V_116 + V_112 -> V_117 ;
F_30 ( V_63 , F_31 ( V_118 , V_113 - 1 ) , V_112 -> V_114 . V_115 ) ;
V_112 = V_6 -> V_43 [ V_94 ] . V_112 ;
V_112 -> V_119 . V_115 = F_29 ( V_6 -> V_43 [ V_94 ] . V_105 ) ;
V_113 = V_96 -> V_116 + V_112 -> V_117 ;
F_30 ( V_63 , F_31 ( V_120 , V_113 - 1 ) , V_112 -> V_119 . V_115 ) ;
F_32 ( V_63 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_92 * V_93 ,
int V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_95 * V_96 = & V_6 -> V_96 ;
int V_36 ;
if ( V_93 -> V_121 || V_93 -> V_122 )
V_96 -> V_101 = V_93 -> V_121 ;
if ( V_93 -> V_107 == 0 ) {
if ( V_93 -> V_104 )
F_34 ( V_6 , V_123 , V_2 , L_8 ) ;
} else if ( ( V_93 -> V_107 < ( V_124 << 1 ) ) ||
( V_93 -> V_107 > ( V_125 << 1 ) ) ) {
F_34 ( V_6 , V_123 , V_2 , L_9 ) ;
return - V_32 ;
}
else
if ( V_93 -> V_109 == 0 ) {
if ( V_93 -> V_106 )
F_34 ( V_6 , V_123 , V_2 , L_10 ) ;
} else if ( ( V_93 -> V_109 < ( V_124 << 1 ) ) ||
( V_93 -> V_109 > ( V_125 << 1 ) ) ) {
F_34 ( V_6 , V_123 , V_2 , L_11 ) ;
return - V_32 ;
}
if ( V_94 < 0 ) {
for ( V_36 = 0 ; V_36 < V_6 -> V_42 ; V_36 ++ )
F_28 ( V_6 , V_93 , V_36 ) ;
} else if ( V_94 < V_6 -> V_42 ) {
F_28 ( V_6 , V_93 , V_94 ) ;
} else {
F_34 ( V_6 , V_123 , V_2 , L_12 ,
V_6 -> V_42 - 1 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
return F_33 ( V_2 , V_93 , - 1 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
T_2 V_94 ,
struct V_92 * V_93 )
{
return F_33 ( V_2 , V_93 , V_94 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_126 * V_4 ,
T_2 * V_127 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_128 = - V_129 ;
switch ( V_4 -> V_4 ) {
case V_130 :
V_4 -> V_35 = V_6 -> V_42 ;
V_128 = 0 ;
break;
case V_131 :
F_5 ( V_2 ,
L_13 ) ;
break;
default:
break;
}
return V_128 ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_133 -> V_134 = V_6 -> V_42 ;
V_133 -> V_135 = V_136 ;
V_133 -> V_137 = V_136 ;
V_133 -> V_138 = V_6 -> V_42 ;
}
static T_2 F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_139 ;
}
static T_2 F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_140 ;
}
static int F_41 ( struct V_1 * V_2 , T_2 * V_141 , T_3 * V_142 ,
T_3 * V_143 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_36 ;
if ( V_143 )
* V_143 = V_144 ;
if ( ! V_141 )
return 0 ;
memcpy ( V_142 , V_6 -> V_145 , V_6 -> V_139 ) ;
for ( V_36 = 0 ; V_36 < V_6 -> V_140 ; V_36 ++ )
V_141 [ V_36 ] = ( T_2 ) V_6 -> V_146 [ V_36 ] ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , const T_2 * V_141 ,
const T_3 * V_142 , const T_3 V_143 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_36 ;
if ( V_142 ||
( V_143 != V_147 && V_143 != V_144 ) )
return - V_129 ;
if ( ! V_141 )
return 0 ;
if ( V_142 ) {
memcpy ( V_6 -> V_145 , V_142 , V_6 -> V_139 ) ;
}
for ( V_36 = 0 ; V_36 < V_6 -> V_140 ; V_36 ++ )
V_6 -> V_146 [ V_36 ] = ( T_3 ) ( V_141 [ V_36 ] ) ;
return F_43 ( V_6 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_148 = & V_149 ;
}
