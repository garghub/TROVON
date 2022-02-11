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
#ifdef F_4
F_3 ( V_4 , F_4 ) ;
#else
F_5 ( V_2 ,
L_1 ) ;
#endif
break;
case V_18 :
F_3 ( V_4 , V_19 ) ;
break;
case V_20 :
F_3 ( V_4 , V_21 ) ;
break;
case V_22 :
F_3 ( V_4 , V_23 ) ;
break;
case V_24 :
F_3 ( V_4 , V_25 ) ;
break;
default:
break;
}
V_4 -> V_26 = V_27 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_28 )
{
if ( V_28 == V_29 )
return F_7 ( V_2 ) ;
else
return - V_30 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_1 * V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 , V_35 ;
char * V_36 ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 ++ ) {
V_36 = ( char * ) V_6 + V_38 [ V_34 ] . V_39 ;
V_33 [ V_34 ] = * ( T_1 * ) V_36 ;
}
for ( V_35 = 0 ; V_35 < V_6 -> V_40 ; V_35 ++ ) {
V_33 [ V_34 ++ ] = V_6 -> V_41 [ V_35 ] . V_32 . V_42 ;
V_33 [ V_34 ++ ] = V_6 -> V_41 [ V_35 ] . V_32 . V_43 ;
}
for ( V_35 = 0 ; V_35 < V_6 -> V_40 ; V_35 ++ ) {
V_33 [ V_34 ++ ] = V_6 -> V_44 [ V_35 ] . V_32 . V_42 ;
V_33 [ V_34 ++ ] = V_6 -> V_44 [ V_35 ] . V_32 . V_43 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_2 V_28 , T_3 * V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 * V_36 = V_33 ;
int V_34 ;
if ( V_28 == V_29 ) {
for ( V_34 = 0 ; V_34 < V_37 ; V_34 ++ ) {
memcpy ( V_36 , V_38 [ V_34 ] . V_45 ,
V_46 ) ;
V_36 += V_46 ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_40 ; V_34 ++ ) {
snprintf ( V_36 , V_46 , L_2 , V_34 ) ;
V_36 += V_46 ;
snprintf ( V_36 , V_46 , L_3 , V_34 ) ;
V_36 += V_46 ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_40 ; V_34 ++ ) {
snprintf ( V_36 , V_46 , L_4 , V_34 ) ;
V_36 += V_46 ;
snprintf ( V_36 , V_46 , L_5 , V_34 ) ;
V_36 += V_46 ;
}
}
}
static T_2 F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_47 ;
}
static void F_11 ( struct V_1 * V_2 , T_2 V_33 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_48 & V_33 )
V_6 -> V_49 . V_50 = V_33 ;
V_6 -> V_47 = V_33 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_13 ( V_52 -> V_53 , V_54 , 32 ) ;
F_13 ( V_52 -> V_55 , V_56 , 32 ) ;
F_13 ( V_52 -> V_57 , L_6 , 4 ) ;
F_13 ( V_52 -> V_58 , F_14 ( V_6 -> V_59 ) , 32 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_61 -> V_62 = V_63 ;
V_61 -> V_64 = V_65 ;
V_61 -> V_66 = V_6 -> V_67 ;
V_61 -> V_68 = V_6 -> V_69 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_70 , V_71 ;
if ( ( V_61 -> V_72 ) || ( V_61 -> V_73 ) )
return - V_30 ;
V_71 = F_17 ( T_2 , V_61 -> V_68 ,
V_74 ,
V_65 ) ;
V_71 = F_18 ( V_71 , V_75 ) ;
V_70 = F_17 ( T_2 , V_61 -> V_66 ,
V_76 ,
V_63 ) ;
V_70 = F_18 ( V_70 , V_75 ) ;
if ( ( V_71 == V_6 -> V_69 ) &&
( V_70 == V_6 -> V_67 ) )
return 0 ;
V_6 -> V_69 = V_71 ;
V_6 -> V_67 = V_70 ;
if ( F_19 ( V_2 ) ) {
V_6 -> V_77 |= V_78 ;
F_20 ( & V_6 -> V_79 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
int V_82 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_83 * V_84 = & V_6 -> V_84 ;
struct V_85 * V_86 , * V_87 ;
V_81 -> V_88 = V_84 -> V_89 ;
V_81 -> V_90 = V_84 -> V_89 ;
if ( V_82 < 0 )
V_82 = 0 ;
else if ( V_82 >= V_6 -> V_40 )
return - V_30 ;
V_86 = & V_6 -> V_44 [ V_82 ] ;
V_87 = & V_6 -> V_41 [ V_82 ] ;
if ( F_22 ( V_86 -> V_91 ) )
V_81 -> V_92 = 1 ;
if ( F_22 ( V_87 -> V_93 ) )
V_81 -> V_94 = 1 ;
V_81 -> V_95 = V_86 -> V_91 & ~ V_96 ;
V_81 -> V_97 = V_87 -> V_93 & ~ V_96 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
return F_21 ( V_2 , V_81 , - 1 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
T_2 V_82 ,
struct V_80 * V_81 )
{
return F_21 ( V_2 , V_81 , V_82 ) ;
}
static void F_25 ( struct V_5 * V_6 ,
struct V_80 * V_81 ,
int V_82 )
{
struct V_83 * V_84 = & V_6 -> V_84 ;
struct V_98 * V_49 = & V_6 -> V_49 ;
struct V_99 * V_100 ;
T_4 V_101 ;
V_6 -> V_44 [ V_82 ] . V_91 = V_81 -> V_95 ;
V_6 -> V_41 [ V_82 ] . V_93 = V_81 -> V_97 ;
if ( V_81 -> V_92 )
V_6 -> V_44 [ V_82 ] . V_91 |= V_96 ;
else
V_6 -> V_44 [ V_82 ] . V_91 &= ~ V_96 ;
if ( V_81 -> V_94 )
V_6 -> V_41 [ V_82 ] . V_93 |= V_96 ;
else
V_6 -> V_41 [ V_82 ] . V_93 &= ~ V_96 ;
V_100 = V_6 -> V_44 [ V_82 ] . V_100 ;
V_100 -> V_102 . V_103 = F_26 ( V_6 -> V_44 [ V_82 ] . V_91 ) ;
V_101 = V_84 -> V_104 + V_100 -> V_105 ;
F_27 ( V_49 , F_28 ( V_106 , V_101 - 1 ) , V_100 -> V_102 . V_103 ) ;
V_100 = V_6 -> V_41 [ V_82 ] . V_100 ;
V_100 -> V_107 . V_103 = F_26 ( V_6 -> V_41 [ V_82 ] . V_93 ) ;
V_101 = V_84 -> V_104 + V_100 -> V_105 ;
F_27 ( V_49 , F_28 ( V_108 , V_101 - 1 ) , V_100 -> V_107 . V_103 ) ;
F_29 ( V_49 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_80 * V_81 ,
int V_82 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_83 * V_84 = & V_6 -> V_84 ;
int V_34 ;
if ( V_81 -> V_109 || V_81 -> V_110 )
V_84 -> V_89 = V_81 -> V_109 ;
if ( V_81 -> V_95 == 0 ) {
if ( V_81 -> V_92 )
F_31 ( V_6 , V_111 , V_2 , L_7 ) ;
} else if ( ( V_81 -> V_95 < ( V_112 << 1 ) ) ||
( V_81 -> V_95 > ( V_113 << 1 ) ) ) {
F_31 ( V_6 , V_111 , V_2 , L_8 ) ;
return - V_30 ;
}
else
if ( V_81 -> V_97 == 0 ) {
if ( V_81 -> V_94 )
F_31 ( V_6 , V_111 , V_2 , L_9 ) ;
} else if ( ( V_81 -> V_97 < ( V_112 << 1 ) ) ||
( V_81 -> V_97 > ( V_113 << 1 ) ) ) {
F_31 ( V_6 , V_111 , V_2 , L_10 ) ;
return - V_30 ;
}
if ( V_82 < 0 ) {
for ( V_34 = 0 ; V_34 < V_6 -> V_40 ; V_34 ++ )
F_25 ( V_6 , V_81 , V_34 ) ;
} else if ( V_82 < V_6 -> V_40 ) {
F_25 ( V_6 , V_81 , V_82 ) ;
} else {
F_31 ( V_6 , V_111 , V_2 , L_11 ,
V_6 -> V_40 - 1 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
return F_30 ( V_2 , V_81 , - 1 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
T_2 V_82 ,
struct V_80 * V_81 )
{
return F_30 ( V_2 , V_81 , V_82 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
T_2 * V_116 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_117 = - V_118 ;
switch ( V_115 -> V_115 ) {
case V_119 :
V_115 -> V_33 = V_6 -> V_40 ;
V_117 = 0 ;
break;
case V_120 :
F_5 ( V_2 ,
L_12 ) ;
break;
default:
break;
}
return V_117 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_121 * V_122 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_122 -> V_123 = V_6 -> V_40 ;
V_122 -> V_124 = V_125 ;
V_122 -> V_126 = V_125 ;
V_122 -> V_127 = V_6 -> V_40 ;
}
static T_2 F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_128 ;
}
static T_2 F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_129 ;
}
static int F_38 ( struct V_1 * V_2 , T_2 * V_130 , T_3 * V_131 ,
T_3 * V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_34 ;
if ( V_132 )
* V_132 = V_133 ;
if ( ! V_130 )
return 0 ;
memcpy ( V_131 , V_6 -> V_134 , V_6 -> V_128 ) ;
for ( V_34 = 0 ; V_34 < V_6 -> V_129 ; V_34 ++ )
V_130 [ V_34 ] = ( T_2 ) V_6 -> V_135 [ V_34 ] ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , const T_2 * V_130 ,
const T_3 * V_131 , const T_3 V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_34 ;
if ( V_131 ||
( V_132 != V_136 && V_132 != V_133 ) )
return - V_118 ;
if ( ! V_130 )
return 0 ;
if ( V_131 ) {
memcpy ( V_6 -> V_134 , V_131 , V_6 -> V_128 ) ;
}
for ( V_34 = 0 ; V_34 < V_6 -> V_129 ; V_34 ++ )
V_6 -> V_135 [ V_34 ] = ( T_3 ) ( V_130 [ V_34 ] ) ;
return F_40 ( V_6 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
V_2 -> V_137 = & V_138 ;
}
