static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = V_13 ;
switch ( V_6 -> V_14 ) {
case V_15 :
F_3 ( V_4 , V_16 ) ;
break;
case V_17 :
F_3 ( V_4 , V_18 ) ;
break;
case V_19 :
F_3 ( V_4 , V_20 ) ;
break;
case V_21 :
F_3 ( V_4 , V_22 ) ;
break;
case V_23 :
F_3 ( V_4 , V_24 ) ;
break;
default:
break;
}
V_4 -> V_25 = V_26 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_27 )
{
if ( V_27 == V_28 )
return F_5 ( V_2 ) ;
else
return - V_29 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_30 * V_31 , T_1 * V_32 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_33 , V_34 ;
char * V_35 ;
for ( V_33 = 0 ; V_33 < V_36 ; V_33 ++ ) {
V_35 = ( char * ) V_6 + V_37 [ V_33 ] . V_38 ;
V_32 [ V_33 ] = * ( T_1 * ) V_35 ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_39 ; V_34 ++ ) {
V_32 [ V_33 ++ ] = V_6 -> V_40 [ V_34 ] . V_31 . V_41 ;
V_32 [ V_33 ++ ] = V_6 -> V_40 [ V_34 ] . V_31 . V_42 ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_39 ; V_34 ++ ) {
V_32 [ V_33 ++ ] = V_6 -> V_43 [ V_34 ] . V_31 . V_41 ;
V_32 [ V_33 ++ ] = V_6 -> V_43 [ V_34 ] . V_31 . V_42 ;
}
}
static void F_7 ( struct V_1 * V_2 , T_2 V_27 , T_3 * V_32 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 * V_35 = V_32 ;
int V_33 ;
if ( V_27 == V_28 ) {
for ( V_33 = 0 ; V_33 < V_36 ; V_33 ++ ) {
memcpy ( V_35 , V_37 [ V_33 ] . V_44 ,
V_45 ) ;
V_35 += V_45 ;
}
for ( V_33 = 0 ; V_33 < V_6 -> V_39 ; V_33 ++ ) {
snprintf ( V_35 , V_45 , L_1 , V_33 ) ;
V_35 += V_45 ;
snprintf ( V_35 , V_45 , L_2 , V_33 ) ;
V_35 += V_45 ;
}
for ( V_33 = 0 ; V_33 < V_6 -> V_39 ; V_33 ++ ) {
snprintf ( V_35 , V_45 , L_3 , V_33 ) ;
V_35 += V_45 ;
snprintf ( V_35 , V_45 , L_4 , V_33 ) ;
V_35 += V_45 ;
}
}
}
static T_2 F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_46 ;
}
static void F_9 ( struct V_1 * V_2 , T_2 V_32 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_47 & V_32 )
V_6 -> V_48 . V_49 = V_32 ;
V_6 -> V_46 = V_32 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_11 ( V_51 -> V_52 , V_53 , 32 ) ;
F_11 ( V_51 -> V_54 , V_55 , 32 ) ;
F_11 ( V_51 -> V_56 , L_5 , 4 ) ;
F_11 ( V_51 -> V_57 , F_12 ( V_6 -> V_58 ) , 32 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_60 -> V_61 = V_62 ;
V_60 -> V_63 = V_64 ;
V_60 -> V_65 = V_6 -> V_66 ;
V_60 -> V_67 = V_6 -> V_68 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_69 , V_70 ;
if ( ( V_60 -> V_71 ) || ( V_60 -> V_72 ) )
return - V_29 ;
V_70 = F_15 ( T_2 , V_60 -> V_67 ,
V_73 ,
V_64 ) ;
V_70 = F_16 ( V_70 , V_74 ) ;
V_69 = F_15 ( T_2 , V_60 -> V_65 ,
V_75 ,
V_62 ) ;
V_69 = F_16 ( V_69 , V_74 ) ;
if ( ( V_70 == V_6 -> V_68 ) &&
( V_69 == V_6 -> V_66 ) )
return 0 ;
V_6 -> V_68 = V_70 ;
V_6 -> V_66 = V_69 ;
if ( F_17 ( V_2 ) ) {
V_6 -> V_76 |= V_77 ;
F_18 ( & V_6 -> V_78 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
int V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_82 * V_83 = & V_6 -> V_83 ;
struct V_84 * V_85 , * V_86 ;
V_80 -> V_87 = V_83 -> V_88 ;
V_80 -> V_89 = V_83 -> V_88 ;
if ( V_81 < 0 )
V_81 = 0 ;
else if ( V_81 >= V_6 -> V_39 )
return - V_29 ;
V_85 = & V_6 -> V_43 [ V_81 ] ;
V_86 = & V_6 -> V_40 [ V_81 ] ;
if ( F_20 ( V_85 -> V_90 ) )
V_80 -> V_91 = 1 ;
if ( F_20 ( V_86 -> V_92 ) )
V_80 -> V_93 = 1 ;
V_80 -> V_94 = V_85 -> V_90 & ~ V_95 ;
V_80 -> V_96 = V_86 -> V_92 & ~ V_95 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
return F_19 ( V_2 , V_80 , - 1 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
T_2 V_81 ,
struct V_79 * V_80 )
{
return F_19 ( V_2 , V_80 , V_81 ) ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_79 * V_80 ,
int V_81 )
{
struct V_82 * V_83 = & V_6 -> V_83 ;
struct V_97 * V_48 = & V_6 -> V_48 ;
struct V_98 * V_99 ;
T_4 V_100 ;
V_6 -> V_43 [ V_81 ] . V_90 = V_80 -> V_94 ;
V_6 -> V_40 [ V_81 ] . V_92 = V_80 -> V_96 ;
if ( V_80 -> V_91 )
V_6 -> V_43 [ V_81 ] . V_90 |= V_95 ;
else
V_6 -> V_43 [ V_81 ] . V_90 &= ~ V_95 ;
if ( V_80 -> V_93 )
V_6 -> V_40 [ V_81 ] . V_92 |= V_95 ;
else
V_6 -> V_40 [ V_81 ] . V_92 &= ~ V_95 ;
V_99 = V_6 -> V_43 [ V_81 ] . V_99 ;
V_99 -> V_101 . V_102 = F_24 ( V_6 -> V_43 [ V_81 ] . V_90 ) ;
V_100 = V_83 -> V_103 + V_99 -> V_104 ;
F_25 ( V_48 , F_26 ( V_105 , V_100 - 1 ) , V_99 -> V_101 . V_102 ) ;
V_99 = V_6 -> V_40 [ V_81 ] . V_99 ;
V_99 -> V_106 . V_102 = F_24 ( V_6 -> V_40 [ V_81 ] . V_92 ) ;
V_100 = V_83 -> V_103 + V_99 -> V_104 ;
F_25 ( V_48 , F_26 ( V_107 , V_100 - 1 ) , V_99 -> V_106 . V_102 ) ;
F_27 ( V_48 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
int V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_82 * V_83 = & V_6 -> V_83 ;
int V_33 ;
if ( V_80 -> V_108 || V_80 -> V_109 )
V_83 -> V_88 = V_80 -> V_108 ;
if ( V_80 -> V_94 == 0 ) {
if ( V_80 -> V_91 )
F_29 ( V_6 , V_110 , V_2 , L_6 ) ;
} else if ( ( V_80 -> V_94 < ( V_111 << 1 ) ) ||
( V_80 -> V_94 > ( V_112 << 1 ) ) ) {
F_29 ( V_6 , V_110 , V_2 , L_7 ) ;
return - V_29 ;
}
else
if ( V_80 -> V_96 == 0 ) {
if ( V_80 -> V_93 )
F_29 ( V_6 , V_110 , V_2 , L_8 ) ;
} else if ( ( V_80 -> V_96 < ( V_111 << 1 ) ) ||
( V_80 -> V_96 > ( V_112 << 1 ) ) ) {
F_29 ( V_6 , V_110 , V_2 , L_9 ) ;
return - V_29 ;
}
if ( V_81 < 0 ) {
for ( V_33 = 0 ; V_33 < V_6 -> V_39 ; V_33 ++ )
F_23 ( V_6 , V_80 , V_33 ) ;
} else if ( V_81 < V_6 -> V_39 ) {
F_23 ( V_6 , V_80 , V_81 ) ;
} else {
F_29 ( V_6 , V_110 , V_2 , L_10 ,
V_6 -> V_39 - 1 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
return F_28 ( V_2 , V_80 , - 1 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
T_2 V_81 ,
struct V_79 * V_80 )
{
return F_28 ( V_2 , V_80 , V_81 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_113 * V_114 ,
T_2 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_116 = - V_117 ;
switch ( V_114 -> V_114 ) {
case V_118 :
V_114 -> V_32 = V_6 -> V_39 ;
V_116 = 0 ;
break;
case V_119 :
F_33 ( V_2 ,
L_11 ) ;
break;
default:
break;
}
return V_116 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_120 * V_121 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_121 -> V_122 = V_6 -> V_39 ;
V_121 -> V_123 = V_124 ;
V_121 -> V_125 = V_124 ;
V_121 -> V_126 = V_6 -> V_39 ;
}
static T_2 F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_127 ;
}
static T_2 F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_128 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 * V_129 , T_3 * V_130 ,
T_3 * V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_33 ;
if ( V_131 )
* V_131 = V_132 ;
if ( ! V_129 )
return 0 ;
memcpy ( V_130 , V_6 -> V_133 , V_6 -> V_127 ) ;
for ( V_33 = 0 ; V_33 < V_6 -> V_128 ; V_33 ++ )
V_129 [ V_33 ] = ( T_2 ) V_6 -> V_134 [ V_33 ] ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , const T_2 * V_129 ,
const T_3 * V_130 , const T_3 V_131 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_33 ;
if ( V_130 ||
( V_131 != V_135 && V_131 != V_132 ) )
return - V_117 ;
if ( ! V_129 )
return 0 ;
if ( V_130 ) {
memcpy ( V_6 -> V_133 , V_130 , V_6 -> V_127 ) ;
}
for ( V_33 = 0 ; V_33 < V_6 -> V_128 ; V_33 ++ )
V_6 -> V_134 [ V_33 ] = ( T_3 ) ( V_129 [ V_33 ] ) ;
return F_39 ( V_6 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
V_2 -> V_136 = & V_137 ;
}
