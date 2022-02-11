static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( V_4 == NULL )
return NULL ;
V_3 -> V_4 = V_4 ;
V_4 -> V_3 = V_3 ;
V_4 -> V_6 = F_3 ( V_3 ) ;
if ( V_4 -> V_6 == V_7 )
V_4 -> V_6 = V_8 ;
return V_4 ;
}
static enum V_9 F_3 ( struct V_2 * V_3 )
{
T_1 V_10 = V_3 -> V_10 ;
T_2 V_11 = V_10 >> 16 ;
T_2 V_12 = V_10 & 0xffff ;
enum V_9 V_6 ;
if ( V_11 != 0x1106 )
V_6 = V_13 ;
else if ( V_12 >= 0x1708 && V_12 <= 0x170b )
V_6 = V_14 ;
else if ( V_12 >= 0xe710 && V_12 <= 0xe713 )
V_6 = V_15 ;
else if ( V_12 >= 0xe714 && V_12 <= 0xe717 )
V_6 = V_16 ;
else if ( V_12 >= 0xe720 && V_12 <= 0xe723 ) {
V_6 = V_17 ;
if ( F_4 ( V_3 , 0x16 , V_18 ) == 0x7 )
V_6 = V_7 ;
} else if ( V_12 >= 0xe724 && V_12 <= 0xe727 )
V_6 = V_19 ;
else if ( ( V_12 & 0xfff ) == 0x397
&& ( V_12 >> 12 ) < 8 )
V_6 = V_8 ;
else if ( ( V_12 & 0xfff ) == 0x398
&& ( V_12 >> 12 ) < 8 )
V_6 = V_20 ;
else if ( ( V_12 & 0xfff ) == 0x428
&& ( V_12 >> 12 ) < 8 )
V_6 = V_21 ;
else if ( V_12 == 0x0433 || V_12 == 0xa721 )
V_6 = V_22 ;
else if ( V_12 == 0x0441 || V_12 == 0x4441 )
V_6 = V_21 ;
else if ( V_12 == 0x0438 || V_12 == 0x4438 )
V_6 = V_23 ;
else if ( V_12 == 0x0448 )
V_6 = V_24 ;
else if ( V_12 == 0x0440 )
V_6 = V_8 ;
else if ( ( V_12 & 0xfff ) == 0x446 )
V_6 = V_25 ;
else
V_6 = V_13 ;
return V_6 ;
}
static void F_5 ( struct V_1 * V_4 )
{
if ( V_4 -> V_6 != V_14 || V_4 -> V_26 . V_27 [ 0 ] == 0 )
return;
F_6 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 ,
! V_4 -> V_28 ) ;
if ( ! F_7 ( & V_4 -> V_29 ) )
F_8 ( & V_4 -> V_29 ,
F_9 ( 100 ) ) ;
}
static void F_10 ( struct V_1 * V_4 )
{
if ( V_4 -> V_6 != V_14 || V_4 -> V_26 . V_27 [ 0 ] == 0 )
return;
if ( F_11 ( V_4 -> V_3 , L_1 ) == 1
&& ! F_12 ( V_4 -> V_3 ) )
return;
F_6 ( V_4 -> V_3 , 0x1 , 0 , 0xf81 ,
! V_4 -> V_28 ) ;
F_13 ( & V_4 -> V_29 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> F_14 )
V_4 -> F_14 ( V_3 ) ;
}
static int F_15 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
int V_34 = F_16 ( V_31 , V_33 ) ;
struct V_2 * V_3 = F_17 ( V_31 ) ;
F_14 ( V_3 ) ;
F_18 ( F_17 ( V_31 ) , - 1 ) ;
if ( F_11 ( V_3 , L_1 ) == 1 ) {
if ( F_12 ( V_3 ) )
F_5 ( V_3 -> V_4 ) ;
else
F_10 ( V_3 -> V_4 ) ;
}
return V_34 ;
}
static int F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_35 ;
int V_34 = 0 ;
long * V_36 = V_33 -> V_37 . integer . V_37 ;
int V_38 , V_39 ;
if ( strstr ( V_31 -> V_40 . V_41 , L_2 ) == NULL ) {
F_20 ( L_3 ) ;
return V_34 ;
}
V_34 = F_16 ( V_31 ,
V_33 ) ;
V_38 = * V_36 ? 0 : V_42 ;
V_36 ++ ;
V_39 = * V_36 ? 0 : V_42 ;
if ( ! V_4 -> V_43 ) {
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_44 ; V_35 ++ ) {
F_21 (
V_3 , V_4 -> V_26 . V_27 [ V_35 ] ,
0 , V_45 , 0 , V_42 ,
V_38 ) ;
F_21 (
V_3 , V_4 -> V_26 . V_27 [ V_35 ] ,
1 , V_45 , 0 , V_42 ,
V_39 ) ;
}
}
if ( ! V_38 && ! V_39 ) {
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_46 ; V_35 ++ )
F_22 (
V_3 , V_4 -> V_26 . V_47 [ V_35 ] ,
V_45 , 0 , V_42 , 0 ) ;
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_48 ; V_35 ++ )
F_22 (
V_3 , V_4 -> V_26 . V_49 [ V_35 ] ,
V_45 , 0 , V_42 , 0 ) ;
F_23 ( V_3 ) ;
} else {
if ( V_38 ) {
for ( V_35 = 1 ; V_35 < V_4 -> V_26 . V_46 ; V_35 ++ )
F_21 (
V_3 ,
V_4 -> V_26 . V_47 [ V_35 ] ,
0 , V_45 , 0 , V_42 ,
V_38 ) ;
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_48 ; V_35 ++ )
F_21 (
V_3 ,
V_4 -> V_26 . V_49 [ V_35 ] ,
0 , V_45 , 0 , V_42 ,
V_38 ) ;
}
if ( V_39 ) {
for ( V_35 = 1 ; V_35 < V_4 -> V_26 . V_46 ; V_35 ++ )
F_21 (
V_3 ,
V_4 -> V_26 . V_47 [ V_35 ] ,
1 , V_45 , 0 , V_42 ,
V_39 ) ;
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_48 ; V_35 ++ )
F_21 (
V_3 ,
V_4 -> V_26 . V_49 [ V_35 ] ,
1 , V_45 , 0 , V_42 ,
V_39 ) ;
}
}
return V_34 ;
}
static int F_24 ( struct V_1 * V_4 , int type , const char * V_41 ,
int V_50 , unsigned long V_51 )
{
struct V_52 * V_53 ;
F_25 ( & V_4 -> V_54 , sizeof( * V_53 ) , 32 ) ;
V_53 = F_26 ( & V_4 -> V_54 ) ;
if ( ! V_53 )
return - V_55 ;
* V_53 = V_56 [ type ] ;
V_53 -> V_41 = F_27 ( V_41 , V_5 ) ;
if ( ! V_53 -> V_41 )
return - V_55 ;
if ( F_28 ( V_51 ) )
V_53 -> V_57 = V_58 ;
V_53 -> V_59 = V_51 ;
return 0 ;
}
static struct V_52 * F_29 ( struct V_1 * V_4 ,
const struct V_52 * V_60 )
{
struct V_52 * V_53 ;
F_25 ( & V_4 -> V_54 , sizeof( * V_53 ) , 32 ) ;
V_53 = F_26 ( & V_4 -> V_54 ) ;
if ( ! V_53 )
return NULL ;
* V_53 = * V_60 ;
V_53 -> V_41 = F_27 ( V_60 -> V_41 , V_5 ) ;
if ( ! V_53 -> V_41 )
return NULL ;
return V_53 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_54 . V_61 ) {
struct V_52 * V_62 = V_4 -> V_54 . V_61 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 -> V_54 . V_63 ; V_35 ++ )
F_31 ( V_62 [ V_35 ] . V_41 ) ;
}
F_32 ( & V_4 -> V_54 ) ;
}
static int F_33 ( struct V_1 * V_4 , const char * V_64 ,
int V_65 , int V_50 , int V_66 )
{
char V_41 [ 32 ] ;
int V_67 ;
sprintf ( V_41 , L_4 , V_64 ) ;
V_67 = F_24 ( V_4 , V_68 , V_41 , V_65 ,
F_34 ( V_66 , 3 , V_50 , V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_64 ) ;
V_67 = F_24 ( V_4 , V_70 , V_41 , V_65 ,
F_34 ( V_66 , 3 , V_50 , V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 ,
T_3 V_71 , int V_72 ,
int V_73 )
{
F_6 ( V_3 , V_71 , 0 , V_74 ,
V_72 ) ;
F_6 ( V_3 , V_71 , 0 , V_75 ,
V_76 ) ;
if ( F_36 ( V_3 , V_71 ) & V_77 )
F_6 ( V_3 , V_71 , 0 ,
V_78 , 0x02 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_35 ;
for ( V_35 = 0 ; V_35 <= V_79 ; V_35 ++ ) {
T_3 V_71 = V_4 -> V_26 . V_47 [ V_35 ] ;
if ( V_71 )
F_35 ( V_3 , V_71 , V_80 , V_35 ) ;
}
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_81 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_44 ; V_35 ++ ) {
V_81 = V_4 -> V_26 . V_27 [ V_35 ] ;
if ( V_81 )
F_35 ( V_3 , V_81 , V_82 , 0 ) ;
}
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_83 * V_84 = & V_4 -> V_26 ;
unsigned int V_85 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_84 -> V_86 ; V_35 ++ ) {
T_3 V_71 = V_84 -> V_87 [ V_35 ] . V_81 ;
if ( V_4 -> V_88 && F_40 ( V_4 , V_71 ) )
V_85 = V_80 ;
else if ( V_84 -> V_87 [ V_35 ] . type == V_89 )
V_85 = V_90 ;
else
V_85 = V_91 ;
F_6 ( V_3 , V_71 , 0 ,
V_74 , V_85 ) ;
}
}
static void F_41 ( struct V_2 * V_3 , T_3 V_71 ,
unsigned int * V_92 )
{
unsigned V_93 ;
unsigned V_94 = F_42 ( V_3 , V_71 ) ;
unsigned V_95 = ( V_94 & V_96 )
>> V_97
& V_98 ;
unsigned V_99 = F_43 ( V_3 , V_71 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ( V_4 -> V_88 && F_40 ( V_4 , V_71 ) )
|| ( ( V_95 || V_99 )
&& F_44 ( V_94 ) != V_100 ) ) {
* V_92 = V_101 ;
V_93 = V_101 ;
} else
V_93 = V_102 ;
F_6 ( V_3 , V_71 , 0 , V_103 , V_93 ) ;
}
static int F_45 ( struct V_30 * V_31 ,
struct V_104 * V_105 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
return F_46 ( V_4 -> V_106 , V_105 ) ;
}
static int F_47 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_107 = F_48 ( V_31 , & V_33 -> V_40 ) ;
V_33 -> V_37 . V_108 . V_109 [ 0 ] = V_4 -> V_110 [ V_107 ] ;
return 0 ;
}
static int F_49 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_107 = F_48 ( V_31 , & V_33 -> V_40 ) ;
int V_111 ;
if ( ! V_4 -> V_112 [ V_107 ] )
return - V_113 ;
if ( F_50 ( V_3 , V_4 -> V_112 [ V_107 ] , 0 ,
V_114 , 0x00 ) != V_101 )
F_6 ( V_3 , V_4 -> V_112 [ V_107 ] , 0 ,
V_103 , V_101 ) ;
V_111 = F_51 ( V_3 , V_4 -> V_106 , V_33 ,
V_4 -> V_112 [ V_107 ] ,
& V_4 -> V_110 [ V_107 ] ) ;
F_14 ( V_3 ) ;
return V_111 ;
}
static int F_52 ( struct V_30 * V_31 ,
struct V_104 * V_105 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
return F_46 ( V_4 -> V_115 , V_105 ) ;
}
static int F_53 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
T_3 V_71 = V_31 -> V_59 ;
unsigned int V_116 ;
V_116 = ! ! F_50 ( V_3 , V_71 , 0 ,
V_117 ,
0x00 ) ;
V_33 -> V_37 . V_108 . V_109 [ 0 ] = V_116 ;
return 0 ;
}
static void F_54 ( struct V_2 * V_3 , const char * V_41 , int V_118 )
{
struct V_30 * V_85 = F_55 ( V_3 , V_41 ) ;
if ( V_85 ) {
V_85 -> V_119 [ 0 ] . V_120 &= ~ V_121 ;
V_85 -> V_119 [ 0 ] . V_120 |= V_118
? 0 : V_121 ;
F_56 ( V_3 -> V_122 -> V_123 ,
V_124 , & V_85 -> V_40 ) ;
}
}
static T_3 F_57 ( struct V_1 * V_4 )
{
switch ( V_4 -> V_6 ) {
case V_14 : return 0x1b ;
case V_15 : return 0x29 ;
case V_17 :
case V_8 : return 0x27 ;
case V_23 : return 0x19 ;
case V_25 : return 0x15 ;
case V_24 : return 0x15 ;
default: return 0 ;
}
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
unsigned int V_93 ;
T_3 V_125 = F_57 ( V_4 ) ;
if ( V_125 ) {
if ( F_59 ( V_4 ) )
V_93 = V_4 -> V_43 ?
F_60 ( 1 ) : F_61 ( 1 ) ;
else
V_93 = V_4 -> V_43 ?
V_126 : V_76 ;
F_6 ( V_3 , V_125 , 0 ,
V_75 , V_93 ) ;
if ( V_4 -> V_6 == V_24 )
F_6 ( V_3 , 0x1d , 0 ,
V_75 , V_93 ) ;
}
return 0 ;
}
static int F_62 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_71 = V_31 -> V_59 ;
unsigned int V_116 = V_33 -> V_37 . V_108 . V_109 [ 0 ] ;
unsigned int V_127 , V_128 ;
V_4 -> V_43 = V_4 -> V_129 == V_116
? 1 : 0 ;
if ( V_4 -> V_6 == V_21 ) {
F_6 ( V_3 , V_71 , 0 ,
V_130 , V_116 ? 2 : 0 ) ;
V_127 = V_4 -> V_43 ?
F_61 ( 0 ) : F_60 ( 0 ) ;
V_128 = V_4 -> V_43 ?
F_60 ( 1 ) : F_61 ( 1 ) ;
F_6 ( V_3 , 0x1b , 0 ,
V_75 , V_127 ) ;
F_6 ( V_3 , 0x1b , 0 ,
V_75 , V_128 ) ;
}
else
F_6 ( V_3 , V_71 , 0 ,
V_130 , V_116 ) ;
if ( V_4 -> V_6 == V_24 )
F_6 ( V_3 , 0x35 , 0 ,
V_130 , V_116 ) ;
if ( V_4 -> V_131 . V_132 && V_4 -> V_131 . V_132
!= V_4 -> V_131 . V_133 [ V_134 ] )
F_63 ( V_3 , V_4 -> V_131 . V_132 ,
0 , 0 , 0 ) ;
F_58 ( V_3 ) ;
if ( V_4 -> V_6 == V_8
|| V_4 -> V_6 == V_20
|| V_4 -> V_6 == V_21
|| V_4 -> V_6 == V_22
|| F_59 ( V_4 ) ) {
F_54 ( V_3 , L_6 ,
V_4 -> V_43 ) ;
F_54 ( V_3 , L_7 ,
V_4 -> V_43 ) ;
}
F_14 ( V_3 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_52 * V_53 ;
T_3 V_71 ;
int V_135 ;
T_3 V_136 [ V_137 ] ;
switch ( V_4 -> V_6 ) {
case V_21 :
V_71 = 0x34 ;
break;
case V_23 :
case V_25 :
V_71 = 0x35 ;
break;
case V_24 :
V_71 = 0x3d ;
break;
default:
V_71 = V_4 -> V_26 . V_27 [ 0 ] ;
break;
}
if ( V_4 -> V_6 != V_14 ) {
V_135 = F_65 ( V_3 , V_71 ,
V_136 , V_137 ) ;
if ( V_135 <= 1 )
return 0 ;
}
V_53 = F_29 ( V_4 , & V_138 [ 0 ] ) ;
if ( V_53 == NULL )
return - V_55 ;
V_53 -> V_57 = V_139 | V_71 ;
V_53 -> V_59 = V_71 ;
V_71 = F_57 ( V_4 ) ;
if ( V_71 ) {
V_53 = F_29 ( V_4 , & V_138 [ 1 ] ) ;
if ( V_53 == NULL )
return - V_55 ;
V_53 -> V_57 = V_71 ;
}
return 0 ;
}
static void F_66 ( struct V_2 * V_3 )
{
int V_35 ;
struct V_140 V_40 ;
const char * V_141 [] = { L_8 , L_9 , L_10 , L_11 } ;
struct V_30 * V_85 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_142 = V_143 ;
for ( V_35 = 0 ; V_35 < F_67 ( V_141 ) ; V_35 ++ ) {
sprintf ( V_40 . V_41 , L_4 , V_141 [ V_35 ] ) ;
V_85 = F_55 ( V_3 , V_40 . V_41 ) ;
if ( V_85 )
F_56 ( V_3 -> V_122 -> V_123 ,
V_124 ,
& V_85 -> V_40 ) ;
}
}
static void F_68 ( struct V_2 * V_3 , int V_144 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_145 ;
int V_146 ;
int V_147 ;
int V_35 ;
switch ( V_4 -> V_6 ) {
case V_14 :
V_145 = 0x17 ;
V_146 = 2 ;
V_147 = 4 ;
break;
case V_15 :
case V_16 :
V_145 = 0x18 ;
V_146 = 2 ;
V_147 = 4 ;
break;
case V_17 :
case V_19 :
case V_8 :
case V_22 :
V_145 = 0x16 ;
V_146 = 2 ;
V_147 = 4 ;
break;
case V_21 :
V_145 = 0x21 ;
V_146 = 1 ;
V_147 = 3 ;
break;
default:
return;
}
for ( V_35 = V_146 ; V_35 <= V_147 ; V_35 ++ ) {
int V_51 = V_144 ? V_42 : V_148 ;
F_22 ( V_3 , V_145 , V_69 , V_35 ,
V_42 , V_51 ) ;
}
}
static int F_40 ( struct V_1 * V_4 , T_3 V_81 )
{
const struct V_83 * V_84 = & V_4 -> V_26 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_84 -> V_86 ; V_35 ++ ) {
if ( V_81 == V_84 -> V_87 [ V_35 ] . V_81 )
return V_84 -> V_87 [ V_35 ] . type <= V_149 ;
}
return 0 ;
}
static int F_69 ( struct V_30 * V_31 ,
struct V_104 * V_105 )
{
V_105 -> type = V_150 ;
V_105 -> V_151 = 1 ;
V_105 -> V_37 . integer . V_152 = 0 ;
V_105 -> V_37 . integer . V_153 = 1 ;
return 0 ;
}
static int F_70 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_83 * V_84 = & V_4 -> V_26 ;
int V_154 = 1 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_84 -> V_86 ; V_35 ++ ) {
T_3 V_71 = V_84 -> V_87 [ V_35 ] . V_81 ;
int V_85 = F_50 ( V_3 , V_71 , 0 ,
V_155 , 0 ) ;
if ( V_84 -> V_87 [ V_35 ] . type > V_149 )
continue;
if ( V_84 -> V_87 [ V_35 ] . type == V_89 &&
V_4 -> V_43 && V_4 -> V_6 != V_21 )
continue;
if ( ( V_85 & V_156 ) && ! ( V_85 & V_157 ) )
V_154 = 0 ;
}
* V_33 -> V_37 . integer . V_37 = V_154 ;
return 0 ;
}
static int F_71 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
const struct V_83 * V_84 = & V_4 -> V_26 ;
int V_158 = * V_33 -> V_37 . integer . V_37
? V_157 : V_156 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_84 -> V_86 ; V_35 ++ ) {
T_3 V_71 = V_84 -> V_87 [ V_35 ] . V_81 ;
unsigned int V_93 ;
if ( V_84 -> V_87 [ V_35 ] . type > V_149 )
continue;
if ( V_84 -> V_87 [ V_35 ] . type == V_89 &&
V_4 -> V_43 && V_4 -> V_6 != V_21 )
continue;
V_93 = F_50 ( V_3 , V_71 , 0 ,
V_155 , 0 ) ;
V_93 &= ~ ( V_156 | V_157 ) ;
V_93 |= V_158 ;
F_6 ( V_3 , V_71 , 0 ,
V_74 ,
V_93 ) ;
if ( V_158 == V_157 ) {
F_68 ( V_3 , 1 ) ;
F_66 ( V_3 ) ;
}
if ( V_4 -> V_6 == V_21 ) {
F_22 (
V_3 , V_71 , V_45 , 0 , V_42 ,
V_148 ) ;
}
if ( V_84 -> V_87 [ V_35 ] . type == V_89 ) {
if ( V_4 -> V_6 == V_8
|| V_4 -> V_6 == V_22 ) {
F_6 (
V_3 , V_71 , 0 ,
V_130 , 1 ) ;
F_22 (
V_3 , V_71 , V_45 ,
0 , V_42 , V_148 ) ;
}
}
}
V_4 -> V_88 = * V_33 -> V_37 . integer . V_37 ;
F_14 ( V_3 ) ;
return 1 ;
}
static int F_72 ( struct V_1 * V_4 )
{
struct V_52 * V_53 ;
const struct V_83 * V_84 = & V_4 -> V_26 ;
T_3 V_71 ;
int V_35 ;
if ( ! V_84 )
return 0 ;
if ( V_84 -> V_46 > 2 )
return 0 ;
V_53 = F_29 ( V_4 , & V_159 [ 0 ] ) ;
if ( V_53 == NULL )
return - V_55 ;
for ( V_35 = 0 ; V_35 < V_84 -> V_86 ; V_35 ++ ) {
V_71 = V_84 -> V_87 [ V_35 ] . V_81 ;
if ( V_84 -> V_87 [ V_35 ] . type <= V_149 ) {
V_53 = F_29 ( V_4 , & V_159 [ 1 ] ) ;
if ( V_53 == NULL )
return - V_55 ;
V_53 -> V_57 = V_71 ;
break;
}
}
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
int V_144 = 1 ;
T_3 V_145 ;
int V_146 ;
int V_147 ;
int V_35 ;
struct V_1 * V_4 = V_3 -> V_4 ;
switch ( V_4 -> V_6 ) {
case V_17 :
case V_19 :
case V_8 :
case V_22 :
V_145 = 0x16 ;
V_146 = 2 ;
V_147 = 4 ;
break;
case V_20 :
V_145 = 0x1a ;
V_146 = 1 ;
V_147 = 3 ;
break;
case V_21 :
V_145 = 0x21 ;
V_146 = 1 ;
V_147 = 3 ;
break;
case V_23 :
case V_24 :
case V_25 :
V_145 = 0x21 ;
V_146 = 0 ;
V_147 = 2 ;
break;
default:
return 0 ;
}
for ( V_35 = V_146 ; V_35 <= V_147 ; V_35 ++ ) {
unsigned int V_160 = F_50 (
V_3 , V_145 , 0 , V_161 , V_35 / 4 * 4 ) ;
int V_162 = 8 * ( V_35 % 4 ) ;
T_3 V_163 = ( V_160 & ( 0xff << V_162 ) ) >> V_162 ;
unsigned int V_164 = F_42 ( V_3 , V_163 ) ;
if ( F_44 ( V_164 ) == V_165 ) {
int V_166 = F_73 ( V_3 , V_145 , 0 ,
V_69 , V_35 ) >> 7 ;
int V_167 = F_73 ( V_3 , V_145 , 1 ,
V_69 , V_35 ) >> 7 ;
if ( ! V_166 || ! V_167 ) {
V_144 = 0 ;
break;
}
}
}
return V_144 ;
}
static void F_18 ( struct V_2 * V_3 , int V_168 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
static int V_169 = 1 ;
int V_170 = F_12 ( V_3 ) ;
unsigned int V_171 = 0 ;
unsigned int V_93 = 0 ;
if ( V_168 == - 1 )
V_170 = V_170 && V_169 ;
else {
V_170 = V_170 && V_168 ;
V_169 = V_168 ;
}
switch ( V_4 -> V_6 ) {
case V_17 :
case V_19 :
V_171 = 0xf70 ;
V_93 = V_170 ? 0x02 : 0x00 ;
break;
case V_8 :
case V_21 :
case V_22 :
V_171 = 0xf73 ;
V_93 = V_170 ? 0x51 : 0xe1 ;
break;
case V_20 :
V_171 = 0xf73 ;
V_93 = V_170 ? 0x01 : 0x1d ;
break;
case V_23 :
case V_24 :
case V_25 :
V_171 = 0xf93 ;
V_93 = V_170 ? 0x00 : 0xe0 ;
break;
default:
return;
}
F_6 ( V_3 , V_3 -> V_172 , 0 , V_171 , V_93 ) ;
}
static int F_74 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_177 = V_176 -> V_178 -> V_179 == 1
&& V_176 -> V_180 == 0 ;
F_18 ( V_3 , V_177 ) ;
return F_75 ( V_3 , & V_4 -> V_131 , V_176 ,
V_174 ) ;
}
static void F_76 ( struct V_2 * V_3 ,
unsigned int V_181 ,
unsigned int V_182 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_183 * V_184 = & V_4 -> V_131 ;
const T_3 * V_185 = V_184 -> V_133 ;
int V_186 = V_176 -> V_187 -> V_188 ;
int V_35 ;
F_77 ( & V_3 -> V_189 ) ;
if ( V_184 -> V_190 && V_184 -> V_191 != V_192 ) {
if ( V_186 == 2 &&
F_78 ( V_3 , V_184 -> V_190 ,
V_182 ) &&
! ( V_3 -> V_193 & V_194 ) ) {
V_184 -> V_191 = V_195 ;
if ( V_3 -> V_196 & V_197 )
F_6 ( V_3 , V_184 -> V_190 , 0 ,
V_198 ,
V_3 -> V_196 &
~ V_197 & 0xff ) ;
F_63 ( V_3 , V_184 -> V_190 ,
V_181 , 0 , V_182 ) ;
if ( V_3 -> V_196 & V_197 )
F_6 ( V_3 , V_184 -> V_190 , 0 ,
V_198 ,
V_3 -> V_196 & 0xff ) ;
} else {
V_184 -> V_191 = 0 ;
F_63 ( V_3 , V_184 -> V_190 ,
0 , 0 , 0 ) ;
}
}
F_79 ( & V_3 -> V_189 ) ;
F_63 ( V_3 , V_185 [ V_134 ] , V_181 ,
0 , V_182 ) ;
if ( V_184 -> V_132 && V_184 -> V_132 != V_185 [ V_134 ]
&& ! V_4 -> V_43 )
F_63 ( V_3 , V_184 -> V_132 , V_181 ,
0 , V_182 ) ;
for ( V_35 = 0 ; V_35 < F_67 ( V_184 -> V_199 ) ; V_35 ++ )
if ( V_184 -> V_199 [ V_35 ] )
F_63 ( V_3 ,
V_184 -> V_199 [ V_35 ] ,
V_181 , 0 , V_182 ) ;
for ( V_35 = 1 ; V_35 < V_184 -> V_200 ; V_35 ++ ) {
if ( V_186 >= ( V_35 + 1 ) * 2 )
F_63 ( V_3 , V_185 [ V_35 ] , V_181 ,
V_35 * 2 , V_182 ) ;
else
F_63 ( V_3 , V_185 [ V_35 ] , V_181 ,
0 , V_182 ) ;
}
}
static int F_80 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
unsigned int V_181 ,
unsigned int V_182 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_183 * V_184 = & V_4 -> V_131 ;
const T_3 * V_185 = V_184 -> V_133 ;
if ( V_176 -> V_201 == 0 )
F_76 ( V_3 , V_181 , V_182 ,
V_176 ) ;
else {
if ( V_184 -> V_132 && V_184 -> V_132 != V_185 [ V_134 ] &&
V_4 -> V_43 )
F_63 ( V_3 , V_184 -> V_132 ,
V_181 , 0 , V_182 ) ;
}
F_5 ( V_4 ) ;
return 0 ;
}
static int F_81 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_183 * V_184 = & V_4 -> V_131 ;
const T_3 * V_185 = V_184 -> V_133 ;
int V_35 ;
if ( V_176 -> V_201 == 0 ) {
for ( V_35 = 0 ; V_35 < V_184 -> V_200 ; V_35 ++ )
F_63 ( V_3 , V_185 [ V_35 ] , 0 , 0 , 0 ) ;
if ( V_184 -> V_132 && ! V_4 -> V_43 )
F_63 ( V_3 , V_184 -> V_132 ,
0 , 0 , 0 ) ;
for ( V_35 = 0 ; V_35 < F_67 ( V_184 -> V_199 ) ; V_35 ++ )
if ( V_184 -> V_199 [ V_35 ] )
F_63 ( V_3 ,
V_184 -> V_199 [ V_35 ] ,
0 , 0 , 0 ) ;
F_77 ( & V_3 -> V_189 ) ;
if ( V_184 -> V_190 &&
V_184 -> V_191 == V_195 ) {
F_63 ( V_3 , V_184 -> V_190 ,
0 , 0 , 0 ) ;
V_184 -> V_191 = 0 ;
}
F_79 ( & V_3 -> V_189 ) ;
} else {
if ( V_184 -> V_132 && V_184 -> V_132 != V_185 [ V_134 ] &&
V_4 -> V_43 )
F_63 ( V_3 , V_184 -> V_132 ,
0 , 0 , 0 ) ;
}
F_10 ( V_4 ) ;
return 0 ;
}
static int F_82 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_83 ( V_3 , & V_4 -> V_131 ) ;
}
static int F_84 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_85 ( V_3 , & V_4 -> V_131 ) ;
}
static int F_86 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
unsigned int V_181 ,
unsigned int V_182 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_87 ( V_3 , & V_4 -> V_131 ,
V_181 , V_182 , V_176 ) ;
}
static int F_88 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_89 ( V_3 , & V_4 -> V_131 ) ;
return 0 ;
}
static int F_90 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
unsigned int V_181 ,
unsigned int V_182 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_63 ( V_3 , V_4 -> V_202 [ V_176 -> V_201 ] ,
V_181 , 0 , V_182 ) ;
return 0 ;
}
static int F_91 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_92 ( V_3 , V_4 -> V_202 [ V_176 -> V_201 ] ) ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_30 * V_62 ;
const struct V_52 * V_53 ;
int V_67 , V_35 ;
for ( V_35 = 0 ; V_35 < V_4 -> V_203 ; V_35 ++ ) {
V_67 = F_94 ( V_3 , V_4 -> V_204 [ V_35 ] ) ;
if ( V_67 < 0 )
return V_67 ;
}
if ( V_4 -> V_131 . V_190 ) {
V_67 = F_95 ( V_3 ,
V_4 -> V_131 . V_190 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_96 ( V_3 ,
& V_4 -> V_131 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_205 = 1 ;
}
if ( V_4 -> V_206 ) {
V_67 = F_97 ( V_3 , V_4 -> V_206 ) ;
if ( V_67 < 0 )
return V_67 ;
}
V_62 = F_55 ( V_3 , L_12 ) ;
for ( V_35 = 0 ; V_62 && V_35 < V_62 -> V_151 ; V_35 ++ ) {
V_67 = F_98 ( V_3 , V_62 , V_35 , V_4 -> V_112 [ V_35 ] ) ;
if ( V_67 < 0 )
return V_67 ;
}
for ( V_35 = 0 ; V_35 < V_4 -> V_203 ; V_35 ++ ) {
for ( V_53 = V_4 -> V_204 [ V_35 ] ; V_53 -> V_41 ; V_53 ++ ) {
if ( V_53 -> V_142 != V_207 )
continue;
V_62 = F_55 ( V_3 , V_53 -> V_41 ) ;
if ( V_62 == NULL )
continue;
V_67 = F_98 ( V_3 , V_62 , 0 ,
V_53 -> V_57 ) ;
}
}
F_14 ( V_3 ) ;
F_18 ( V_3 , 1 ) ;
F_30 ( V_3 ) ;
return 0 ;
}
static int F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_208 * V_209 = V_4 -> V_210 ;
V_3 -> V_211 = 1 ;
V_3 -> V_212 = V_209 ;
V_209 -> V_41 = V_4 -> V_213 ;
V_209 -> V_214 [ V_215 ] =
* ( V_4 -> V_216 ) ;
V_209 -> V_214 [ V_215 ] . V_71 =
V_4 -> V_131 . V_133 [ 0 ] ;
V_209 -> V_214 [ V_217 ] = * ( V_4 -> V_218 ) ;
V_209 -> V_214 [ V_217 ] . V_71 = V_4 -> V_202 [ 0 ] ;
V_209 -> V_214 [ V_215 ] . V_219 =
V_4 -> V_131 . V_220 ;
if ( V_4 -> V_131 . V_190 || V_4 -> V_206 ) {
V_3 -> V_211 ++ ;
V_209 ++ ;
V_209 -> V_41 = V_4 -> V_221 ;
V_209 -> V_222 = V_223 ;
if ( V_4 -> V_131 . V_190 ) {
V_209 -> V_214 [ V_215 ] =
* ( V_4 -> V_224 ) ;
V_209 -> V_214 [ V_215 ] . V_71 =
V_4 -> V_131 . V_190 ;
}
if ( V_4 -> V_206 ) {
V_209 -> V_214 [ V_217 ] =
* ( V_4 -> V_225 ) ;
V_209 -> V_214 [ V_217 ] . V_71 =
V_4 -> V_206 ;
}
}
return 0 ;
}
static void F_100 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! V_4 )
return;
F_30 ( V_3 ) ;
F_10 ( V_4 ) ;
F_31 ( V_3 -> V_4 ) ;
}
static void F_101 ( struct V_2 * V_3 )
{
unsigned int V_99 = 0 ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_99 = F_43 ( V_3 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( ! V_4 -> V_43 ) {
struct V_140 V_40 ;
F_22 (
V_3 , V_4 -> V_26 . V_47 [ 0 ] , V_45 , 0 ,
V_42 , V_99 ? V_42 : 0 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_142 = V_143 ;
strcpy ( V_40 . V_41 , L_13 ) ;
F_56 ( V_3 -> V_122 -> V_123 , V_124 ,
& V_40 ) ;
}
}
static void F_102 ( struct V_2 * V_3 )
{
unsigned int V_226 , V_227 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_6 != V_22 )
return;
V_227 = F_43 ( V_3 ,
V_4 -> V_26 . V_47 [ 0 ] ) ;
if ( V_227 ) {
F_22 (
V_3 , 0x2A , V_45 , 0 , V_42 , V_42 ) ;
return;
}
V_226 = F_43 ( V_3 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( ! V_4 -> V_43 )
F_22 (
V_3 , 0x2A , V_45 , 0 , V_42 ,
V_226 ? V_42 : 0 ) ;
}
static void F_103 ( struct V_2 * V_3 )
{
unsigned int V_228 ;
unsigned int V_229 ;
unsigned int V_230 ;
unsigned int V_231 ;
struct V_1 * V_4 = V_3 -> V_4 ;
V_228 = F_50 ( V_3 , V_3 -> V_172 , 0 ,
V_232 , 0 ) & 0x03 ;
V_229 = ( F_50 ( V_3 , V_3 -> V_172 , 0 ,
0xF84 , 0 ) & 0x3F0000 ) >> 16 ;
V_230 = V_229 & 0x1F ;
V_231 = F_50 ( V_3 , 0x1A , 0 ,
V_233 ,
V_234 ) ;
if ( V_228 == 0x02 ) {
F_22 ( V_3 , V_4 -> V_26 . V_47 [ 0 ] ,
V_45 , 0 , V_42 , 0 ) ;
if ( V_229 & 0x20 ) {
if ( V_230 > V_231 )
V_230 = V_231 ;
F_22 ( V_3 , 0x1A , V_69 ,
0 , V_235 ,
V_231 - V_230 ) ;
} else {
F_22 ( V_3 , 0x1A , V_69 , 0 ,
V_235 ,
( ( V_231 + V_230 ) > 0x2A ) ? 0x2A :
( V_231 + V_230 ) ) ;
}
} else if ( ! ( V_228 & 0x02 ) ) {
F_22 ( V_3 ,
V_4 -> V_26 . V_47 [ 0 ] ,
V_45 , 0 , V_42 ,
V_42 ) ;
}
}
static void F_104 ( struct V_2 * V_3 )
{
unsigned int V_226 ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( ! F_59 ( V_4 ) )
return;
V_226 = F_43 ( V_3 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( ! V_4 -> V_43 ) {
struct V_140 V_40 ;
F_22 (
V_3 , V_4 -> V_26 . V_49 [ 0 ] , V_45 , 0 ,
V_42 , V_226 ? V_42 : 0 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_142 = V_143 ;
strcpy ( V_40 . V_41 , L_14 ) ;
F_56 ( V_3 -> V_122 -> V_123 , V_124 ,
& V_40 ) ;
}
}
static void F_23 ( struct V_2 * V_3 )
{
unsigned long V_226 , V_99 = 0 ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_35 ;
if ( ! V_4 -> V_26 . V_27 [ 0 ] || ! V_4 -> V_26 . V_47 [ 0 ] )
return;
V_226 = F_43 ( V_3 , V_4 -> V_26 . V_27 [ 0 ] ) ;
V_99 = F_43 ( V_3 , V_4 -> V_26 . V_47 [ 0 ] ) ;
if ( ! V_4 -> V_43 ) {
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_46 ; V_35 ++ )
F_22 (
V_3 , V_4 -> V_26 . V_47 [ V_35 ] ,
V_45 , 0 ,
V_42 , V_226 ? V_42 : 0 ) ;
if ( V_226 )
V_99 = V_226 ;
}
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_48 ; V_35 ++ )
F_22 (
V_3 , V_4 -> V_26 . V_49 [ V_35 ] , V_45 , 0 ,
V_42 , V_99 ? V_42 : 0 ) ;
}
static void F_105 ( struct V_2 * V_3 ,
unsigned int V_236 )
{
V_236 >>= 26 ;
if ( V_236 & V_237 )
F_14 ( V_3 ) ;
V_236 &= ~ V_237 ;
if ( V_236 == V_238 )
F_101 ( V_3 ) ;
else if ( V_236 == V_239 )
F_103 ( V_3 ) ;
else if ( V_236 == V_240 )
F_102 ( V_3 ) ;
else if ( V_236 == V_241 )
F_104 ( V_3 ) ;
else if ( V_236 == V_242 )
F_23 ( V_3 ) ;
}
static int F_106 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 -> V_243 ; V_35 ++ )
F_107 ( V_3 , V_4 -> V_244 [ V_35 ] ) ;
if ( ! V_4 -> V_206 ) {
if ( V_4 -> V_245 ) {
F_6 ( V_3 , V_4 -> V_245 , 0 ,
V_74 ,
V_80 ) ;
F_6 ( V_3 , V_4 -> V_245 , 0 ,
V_78 , 0x02 ) ;
}
} else
F_6 ( V_3 , V_4 -> V_26 . V_245 , 0 ,
V_74 , V_91 ) ;
if ( V_4 -> V_246 [ 0 ] )
V_3 -> V_246 = V_4 -> V_246 ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 , T_4 V_247 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_109 ( struct V_2 * V_3 , T_3 V_71 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
return F_110 ( V_3 , & V_4 -> V_248 , V_71 ) ;
}
static int F_111 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_35 ;
T_3 V_71 ;
V_4 -> V_131 . V_200 = V_84 -> V_46 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( V_71 ) {
switch ( V_35 ) {
case V_250 :
V_4 -> V_249 [ V_35 ] = 0x10 ;
break;
case V_251 :
V_4 -> V_249 [ V_35 ] = 0x12 ;
break;
case V_252 :
V_4 -> V_249 [ V_35 ] = 0x11 ;
break;
case V_79 :
V_4 -> V_249 [ V_35 ] = 0x13 ;
break;
}
}
}
return 0 ;
}
static int F_112 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
char V_41 [ 32 ] ;
static const char * const V_253 [ 4 ] = {
L_15 , L_16 , L_17 , L_18
} ;
T_3 V_71 , V_254 , V_255 [] = { 0x17 , 0x19 , 0x1a , 0x1b } ;
int V_35 , V_67 ;
for ( V_35 = 0 ; V_35 <= V_79 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( ! V_71 )
continue;
V_254 = V_255 [ V_35 ] ;
if ( V_35 == V_251 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_19 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_68 ,
L_20 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_21 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_22 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_250 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_23 ,
F_34 ( V_254 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_24 ,
F_34 ( V_254 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_71 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_71 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else {
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
}
}
return 0 ;
}
static void F_114 ( struct V_1 * V_4 )
{
int V_35 ;
struct V_257 * V_258 = & V_4 -> V_259 [ 1 ] ;
static const char * const V_260 [] = { L_25 , L_26 , NULL } ;
for ( V_35 = 0 ; V_260 [ V_35 ] ; V_35 ++ )
F_115 ( V_258 , V_260 [ V_35 ] , V_35 , NULL ) ;
V_4 -> V_115 = & V_4 -> V_259 [ 1 ] ;
}
static int F_116 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = V_261 ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
F_114 ( V_4 ) ;
return 0 ;
}
static int F_117 ( struct V_2 * V_3 ,
const struct V_83 * V_84 ,
T_3 V_262 ,
const T_3 V_263 [] ,
int V_264 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_257 * V_258 = & V_4 -> V_259 [ 0 ] ;
int V_35 , V_67 , V_50 , type , V_65 = 0 ;
for ( V_50 = 0 ; V_50 < V_264 ; V_50 ++ ) {
if ( V_263 [ V_50 ] == 0xff ) {
F_115 ( V_258 , L_27 , V_50 , NULL ) ;
break;
}
}
for ( V_35 = 0 ; V_35 < V_84 -> V_86 ; V_35 ++ ) {
const char * V_265 ;
type = V_84 -> V_87 [ V_35 ] . type ;
for ( V_50 = 0 ; V_50 < V_264 ; V_50 ++ )
if ( V_263 [ V_50 ] == V_84 -> V_87 [ V_35 ] . V_81 )
break;
if ( V_50 >= V_264 )
continue;
if ( V_35 > 0 && type == V_84 -> V_87 [ V_35 - 1 ] . type )
V_65 ++ ;
else
V_65 = 0 ;
V_265 = F_118 ( V_3 , V_84 , V_35 ) ;
if ( V_4 -> V_6 == V_8 ||
V_4 -> V_6 == V_20 ||
V_4 -> V_6 == V_22 )
V_67 = F_33 ( V_4 , V_265 , V_65 ,
V_50 + 1 , V_262 ) ;
else
V_67 = F_33 ( V_4 , V_265 , V_65 ,
V_50 , V_262 ) ;
if ( V_67 < 0 )
return V_67 ;
F_115 ( V_258 , V_265 , V_50 , NULL ) ;
}
return 0 ;
}
static int F_119 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
static const T_3 V_263 [] = { 0xff , 0x24 , 0x1d , 0x1e , 0x21 } ;
return F_117 ( V_3 , V_84 , 0x17 , V_263 ,
F_67 ( V_263 ) ) ;
}
static void F_120 ( struct V_2 * V_3 , T_3 V_71 )
{
unsigned int V_94 ;
unsigned char V_266 ;
V_94 = F_42 ( V_3 , V_71 ) ;
V_266 = ( unsigned char ) F_121 ( V_94 ) ;
V_266 = ( V_266 << 4 ) | F_122 ( V_94 ) ;
if ( F_44 ( V_94 ) == V_100
&& ( V_266 == 0xf0 || V_266 == 0xff ) ) {
V_94 = V_94 & ( ~ ( V_267 << 30 ) ) ;
F_123 ( V_3 , V_71 , V_94 ) ;
}
return;
}
static int F_124 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
if ( V_4 -> V_6 != V_14 )
return 0 ;
V_4 -> V_28 =
! ( ( F_50 ( V_3 , 0x1 , 0 , 0xf84 , 0 ) >> 8 ) & 0x1 ) ;
V_33 -> V_37 . integer . V_37 [ 0 ] = V_4 -> V_28 ;
return 0 ;
}
static int F_125 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_34 ;
if ( V_4 -> V_6 != V_14 )
return 0 ;
V_4 -> V_28 = V_33 -> V_37 . integer . V_37 [ 0 ] ;
V_34 = ( 0x1 & ( F_50 ( V_3 , 0x1 , 0 , 0xf84 , 0 ) >> 8 ) )
== ! V_4 -> V_28 ;
if ( V_4 -> V_28 ) {
F_68 ( V_3 , 1 ) ;
F_66 ( V_3 ) ;
}
return V_34 ;
}
static int F_126 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
F_120 ( V_3 , V_268 ) ;
F_120 ( V_3 , V_269 ) ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_111 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_112 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_116 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_119 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_94 ( V_3 , V_28 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
if ( V_4 -> V_26 . V_270 )
V_4 -> V_131 . V_190 = V_271 ;
V_4 -> V_245 = V_272 ;
if ( V_4 -> V_26 . V_245 )
V_4 -> V_206 = V_273 ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_274 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
F_72 ( V_4 ) ;
return 1 ;
}
static int F_128 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
F_106 ( V_3 ) ;
F_37 ( V_3 ) ;
F_38 ( V_3 ) ;
F_39 ( V_3 ) ;
if ( F_59 ( V_4 ) ) {
F_23 ( V_3 ) ;
} else {
F_101 ( V_3 ) ;
F_104 ( V_3 ) ;
}
return 0 ;
}
static void F_129 ( struct V_275 * V_276 )
{
struct V_1 * V_4 = F_130 ( V_276 , struct V_1 ,
V_29 . V_276 ) ;
if ( V_4 -> V_6 != V_14 )
return;
if ( V_4 -> V_277
!= F_43 ( V_4 -> V_3 , V_4 -> V_26 . V_27 [ 0 ] ) ) {
V_4 -> V_277 ^= 1 ;
F_101 ( V_4 -> V_3 ) ;
}
F_5 ( V_4 ) ;
}
static int F_131 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
T_3 V_71 , V_136 [ 8 ] ;
unsigned int type ;
int V_35 , V_278 ;
for ( V_35 = 0 ; V_35 < V_4 -> V_279 ; V_35 ++ ) {
V_71 = V_4 -> V_202 [ V_35 ] ;
while ( V_71 ) {
type = F_132 ( F_133 ( V_3 , V_71 ) ) ;
if ( type == V_280 )
break;
V_278 = F_65 ( V_3 , V_71 , V_136 ,
F_67 ( V_136 ) ) ;
if ( V_278 <= 0 )
break;
if ( V_278 > 1 ) {
V_4 -> V_112 [ V_35 ] = V_71 ;
break;
}
V_71 = V_136 [ 0 ] ;
}
}
return 0 ;
}
static int F_134 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_126 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_213 = L_30 ;
V_4 -> V_216 = & V_282 ;
if ( V_3 -> V_10 == 0x11061708 )
V_4 -> V_216 = & V_283 ;
V_4 -> V_218 = & V_284 ;
V_4 -> V_221 = L_31 ;
V_4 -> V_224 = & V_285 ;
V_4 -> V_225 = & V_286 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_287 ;
V_4 -> V_279 = F_67 ( V_287 ) ;
F_131 ( V_3 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_288 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_293 ;
#endif
F_137 ( & V_4 -> V_29 , F_129 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_35 ;
T_3 V_71 ;
if ( V_84 -> V_46 == 4 )
V_4 -> V_131 . V_200 = V_84 -> V_46 + 1 ;
else if ( V_84 -> V_46 == 3 )
V_4 -> V_131 . V_200 = V_84 -> V_46 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
if ( V_84 -> V_46 == 4 ) {
for ( V_35 = 0 ; V_35 < V_84 -> V_46 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( V_71 ) {
switch ( V_35 ) {
case V_250 :
V_4 -> V_249 [ V_35 ] = 0x10 ;
break;
case V_251 :
V_4 -> V_249 [ V_35 ] = 0x12 ;
break;
case V_252 :
V_4 -> V_249 [ V_35 ] = 0x11 ;
break;
case V_79 :
V_4 -> V_249 [ V_35 ] = 0x27 ;
break;
default:
break;
}
}
}
V_4 -> V_249 [ V_84 -> V_46 ] = 0x28 ;
} else if ( V_84 -> V_46 == 3 ) {
for ( V_35 = 0 ; V_35 < V_84 -> V_46 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( V_71 ) {
switch ( V_35 ) {
case V_250 :
V_4 -> V_249 [ V_35 ] = 0x10 ;
break;
case V_251 :
V_4 -> V_249 [ V_35 ] = 0x12 ;
break;
case V_252 :
V_4 -> V_249 [ V_35 ] = 0x11 ;
break;
default:
break;
}
}
}
}
return 0 ;
}
static int F_139 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
char V_41 [ 32 ] ;
static const char * const V_253 [ 4 ] = {
L_15 , L_16 , L_17 , L_18
} ;
T_3 V_71 , V_254 , V_255 [] = { 0x18 , 0x1a , 0x1b , 0x29 } ;
int V_35 , V_67 ;
for ( V_35 = 0 ; V_35 <= V_79 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( ! V_71 )
continue;
V_254 = V_255 [ V_35 ] ;
if ( V_35 == V_251 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_19 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_68 ,
L_20 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_21 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_22 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_250 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_23 ,
F_34 ( V_254 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_24 ,
F_34 ( V_254 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_71 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_71 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_252 ) {
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_79 ) {
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
}
}
return 0 ;
}
static int F_140 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
if ( V_4 -> V_131 . V_200 == 5 )
V_4 -> V_131 . V_132 = V_294 ;
else if ( V_4 -> V_131 . V_200 == 3 )
V_4 -> V_131 . V_132 = 0 ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
return 0 ;
}
static int F_141 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
static const T_3 V_263 [] = { 0xff , 0x23 , 0x1d , 0x1e , 0x21 } ;
return F_117 ( V_3 , V_84 , 0x18 , V_263 ,
F_67 ( V_263 ) ) ;
}
static int F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_138 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_139 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_140 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_141 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
if ( V_4 -> V_26 . V_270 )
V_4 -> V_131 . V_190 = V_295 ;
V_4 -> V_245 = V_296 ;
if ( V_4 -> V_26 . V_245 )
V_4 -> V_206 = V_297 ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
F_72 ( V_4 ) ;
return 1 ;
}
static int F_143 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_142 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_32
L_33 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_298 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_299 ;
V_4 -> V_213 = L_34 ;
V_4 -> V_216 = & V_300 ;
V_4 -> V_218 = & V_301 ;
V_4 -> V_221 = L_35 ;
V_4 -> V_224 = & V_302 ;
V_4 -> V_225 = & V_303 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_304 ;
V_4 -> V_279 = F_67 ( V_304 ) ;
F_131 ( V_3 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_305 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_307 ;
#endif
return 0 ;
}
static int F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_142 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_32
L_33 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_308 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_299 ;
V_4 -> V_213 = L_34 ;
V_4 -> V_216 = & V_309 ;
V_4 -> V_218 = & V_301 ;
V_4 -> V_221 = L_35 ;
V_4 -> V_224 = & V_302 ;
V_4 -> V_225 = & V_303 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_304 ;
V_4 -> V_279 = F_67 ( V_304 ) ;
F_131 ( V_3 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_305 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_307 ;
#endif
return 0 ;
}
static int F_145 ( struct V_173 * V_174 ,
struct V_2 * V_3 ,
struct V_175 * V_176 )
{
int V_177 = V_176 -> V_178 -> V_179 == 1
&& V_176 -> V_180 == 0 ;
F_18 ( V_3 , V_177 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_35 ;
T_3 V_71 ;
V_4 -> V_131 . V_200 = V_84 -> V_46 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( V_71 ) {
switch ( V_35 ) {
case V_250 :
V_4 -> V_249 [ V_35 ] = 0x10 ;
break;
case V_251 :
V_4 -> V_249 [ V_35 ] = 0x24 ;
break;
case V_252 :
V_4 -> V_249 [ V_35 ] = 0x11 ;
break;
case V_79 :
V_4 -> V_249 [ V_35 ] = 0x25 ;
break;
}
}
}
return 0 ;
}
static int F_147 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
char V_41 [ 32 ] ;
static const char * const V_253 [ 4 ] = {
L_15 , L_16 , L_17 , L_18
} ;
T_3 V_255 [] = { 0x16 , 0x18 , 0x26 , 0x27 } ;
T_3 V_71 , V_254 = 0 ;
int V_35 , V_67 ;
for ( V_35 = 0 ; V_35 <= V_79 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( ! V_71 )
continue;
V_254 = V_255 [ V_35 ] ;
if ( V_35 == V_251 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_19 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_68 ,
L_20 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_21 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_22 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_250 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_23 ,
F_34 ( V_254 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_24 ,
F_34 ( V_254 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_71 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_71 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else {
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
}
}
return 0 ;
}
static int F_148 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = V_310 ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
F_114 ( V_4 ) ;
return 0 ;
}
static int F_149 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
static const T_3 V_263 [] = { 0xff , 0x1f , 0x1a , 0x1b , 0x1e } ;
return F_117 ( V_3 , V_84 , 0x16 , V_263 ,
F_67 ( V_263 ) ) ;
}
static int F_150 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_146 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_147 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_148 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_149 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
if ( V_4 -> V_26 . V_270 )
V_4 -> V_131 . V_190 = V_311 ;
V_4 -> V_245 = V_312 ;
if ( V_4 -> V_26 . V_245 )
V_4 -> V_206 = V_313 ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
F_72 ( V_4 ) ;
return 1 ;
}
static void F_151 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_314 ;
unsigned int V_93 ;
int V_315 = 0 ;
if ( ( V_4 -> V_6 != V_19 ) &&
( V_3 -> V_10 != 0x11064397 ) )
V_315 = 1 ;
V_314 =
( F_50 ( V_3 , 0x17 , 0 , V_117 , 0x00 )
== ( ( V_4 -> V_6 == V_8 ) ? 5 : 0 ) ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x1a , & V_93 ) ;
F_41 ( V_3 , 0x1b , & V_93 ) ;
F_41 ( V_3 , 0x1e , & V_93 ) ;
if ( V_314 )
V_93 = V_101 ;
F_6 ( V_3 , 0x17 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x13 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x14 , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x19 , & V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x1b , & V_93 ) ;
F_6 ( V_3 , 0x18 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x11 , 0 , V_103 , V_93 ) ;
if ( V_315 ) {
V_93 = V_102 ;
F_41 ( V_3 , 0x22 , & V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x1a , & V_93 ) ;
F_6 ( V_3 , 0x26 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x24 , 0 ,
V_103 , V_93 ) ;
} else if ( V_3 -> V_10 == 0x11064397 ) {
V_93 = V_102 ;
F_41 ( V_3 , 0x23 , & V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x1a , & V_93 ) ;
F_6 ( V_3 , 0x27 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x25 , 0 ,
V_103 , V_93 ) ;
}
V_93 = V_102 ;
F_41 ( V_3 , 0x1c , & V_93 ) ;
F_41 ( V_3 , 0x1d , & V_93 ) ;
if ( V_315 )
F_41 ( V_3 , 0x23 , & V_93 ) ;
F_6 ( V_3 , 0x16 , 0 , V_103 ,
V_314 ? V_101 : V_93 ) ;
F_6 ( V_3 , 0x10 , 0 , V_103 , V_93 ) ;
if ( V_315 ) {
F_6 ( V_3 , 0x25 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x27 , 0 ,
V_103 , V_93 ) ;
} else if ( V_3 -> V_10 == 0x11064397 && V_4 -> V_43 )
F_6 ( V_3 , 0x25 , 0 ,
V_103 , V_93 ) ;
}
static int F_152 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
if ( F_3 ( V_3 ) == V_7 )
return F_153 ( V_3 ) ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_150 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_316 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_317 ;
V_4 -> V_213 = L_36 ;
V_4 -> V_216 = & V_318 ;
V_4 -> V_218 = & V_319 ;
V_4 -> V_221 = L_37 ;
V_4 -> V_224 = & V_320 ;
V_4 -> V_225 = & V_321 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_322 ;
V_4 -> V_279 = F_67 ( V_322 ) ;
F_131 ( V_3 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_323 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_324 ;
#endif
V_4 -> F_14 = F_151 ;
return 0 ;
}
static int F_154 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_150 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_325 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_317 ;
V_4 -> V_213 = L_36 ;
V_4 -> V_216 = & V_326 ;
V_4 -> V_218 = & V_319 ;
V_4 -> V_221 = L_37 ;
V_4 -> V_224 = & V_320 ;
V_4 -> V_225 = & V_321 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_322 ;
V_4 -> V_279 = F_67 ( V_322 ) ;
F_131 ( V_3 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_323 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_324 ;
#endif
V_4 -> F_14 = F_151 ;
return 0 ;
}
static int F_155 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_35 ;
T_3 V_71 ;
V_4 -> V_131 . V_200 = V_84 -> V_46 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( V_71 ) {
switch ( V_35 ) {
case V_250 :
V_4 -> V_249 [ V_35 ] = 0x10 ;
break;
case V_251 :
if ( V_4 -> V_3 -> V_10 == 0x11064397 )
V_4 -> V_249 [ V_35 ] = 0x25 ;
else
V_4 -> V_249 [ V_35 ] = 0x24 ;
break;
case V_252 :
V_4 -> V_249 [ V_35 ] = 0x11 ;
break;
case V_79 :
V_4 -> V_249 [ V_35 ] = 0x25 ;
break;
}
}
}
if ( V_84 -> V_46 == 1 ) {
V_4 -> V_131 . V_200 = 3 ;
V_4 -> V_249 [ V_252 ] = 0x11 ;
if ( V_4 -> V_3 -> V_10 == 0x11064397 )
V_4 -> V_249 [ V_251 ] = 0x25 ;
else
V_4 -> V_249 [ V_251 ] = 0x24 ;
}
return 0 ;
}
static int F_156 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
char V_41 [ 32 ] ;
static const char * const V_253 [ 4 ] = {
L_15 , L_16 , L_17 , L_18
} ;
T_3 V_255 [ 2 ] [ 4 ] = { { 0x10 , 0x11 , 0x24 , 0x25 } ,
{ 0x10 , 0x11 , 0x25 , 0 } } ;
T_3 V_327 [ 2 ] [ 4 ] = { { 0x1C , 0x18 , 0x26 , 0x27 } ,
{ 0x1C , 0x18 , 0x27 , 0 } } ;
T_3 V_71 , V_254 , V_328 ;
int V_35 , V_67 ;
for ( V_35 = 0 ; V_35 <= V_79 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( ! V_71 && V_35 > V_251 )
continue;
if ( V_3 -> V_10 == 0x11064397 ) {
V_254 = V_255 [ 1 ] [ V_35 ] ;
V_328 = V_327 [ 1 ] [ V_35 ] ;
} else {
V_254 = V_255 [ 0 ] [ V_35 ] ;
V_328 = V_327 [ 0 ] [ V_35 ] ;
}
if ( ! V_254 && ! V_328 )
continue;
if ( V_35 == V_251 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_19 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_68 ,
L_20 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_21 ,
F_34 ( V_328 ,
1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_22 ,
F_34 ( V_328 ,
2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_250 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_23 ,
F_34 ( 0x16 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_24 ,
F_34 ( 0x16 , 3 , 0 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_328 ,
3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else {
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 ( V_4 , V_256 , V_41 ,
F_34 ( V_328 ,
3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
}
}
return 0 ;
}
static int F_157 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = V_329 ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 ( 0x25 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
F_114 ( V_4 ) ;
return 0 ;
}
static int F_158 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
static const T_3 V_263 [] = { 0x1f , 0x1a , 0x1b , 0x1e , 0 , 0xff } ;
return F_117 ( V_3 , V_84 , 0x16 , V_263 ,
F_67 ( V_263 ) ) ;
}
static void F_159 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 -> V_26 . V_270 ; V_35 ++ ) {
T_3 V_71 ;
int V_136 ;
V_71 = V_4 -> V_26 . V_330 [ V_35 ] ;
if ( ! V_71 )
continue;
V_136 = F_65 ( V_3 , V_71 , & V_71 , 1 ) ;
if ( V_136 < 1 )
continue;
if ( ! V_4 -> V_131 . V_190 )
V_4 -> V_131 . V_190 = V_71 ;
else {
V_4 -> V_246 [ 0 ] = V_71 ;
break;
}
}
}
static int F_160 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_155 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_156 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_157 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_158 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
F_159 ( V_3 ) ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
F_72 ( V_4 ) ;
return 1 ;
}
static void F_161 ( struct V_2 * V_3 , T_3 V_81 ,
int V_331 , int V_332 , int V_333 )
{
F_162 ( V_3 , V_81 , V_69 ,
( V_331 << V_334 ) |
( V_332 << V_335 ) |
( V_333 << V_336 ) |
( 0 << V_337 ) ) ;
}
static int F_153 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_160 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_338 ;
if ( V_3 -> V_10 == 0x11064397 )
V_4 -> V_244 [ V_4 -> V_243 ++ ] =
V_339 ;
else
V_4 -> V_244 [ V_4 -> V_243 ++ ] =
V_340 ;
if ( V_3 -> V_10 == 0x11060440 )
V_4 -> V_213 = L_38 ;
else if ( V_3 -> V_10 == 0x11064397 )
V_4 -> V_213 = L_39 ;
else
V_4 -> V_213 = L_40 ;
if ( V_3 -> V_10 == 0x11064397 )
V_4 -> V_216 = & V_341 ;
else
V_4 -> V_216 = & V_342 ;
V_4 -> V_218 = & V_343 ;
if ( V_3 -> V_10 == 0x11060440 )
V_4 -> V_221 = L_41 ;
else if ( V_3 -> V_10 == 0x11064397 )
V_4 -> V_221 = L_42 ;
else
V_4 -> V_221 = L_43 ;
V_4 -> V_224 = & V_344 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_345 ;
V_4 -> V_279 = F_67 ( V_345 ) ;
F_131 ( V_3 ) ;
F_161 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_161 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_346 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_347 ;
#endif
if ( F_3 ( V_3 ) == V_7 ) {
F_31 ( V_3 -> V_348 ) ;
V_3 -> V_348 = F_27 ( L_44 , V_5 ) ;
snprintf ( V_3 -> V_122 -> V_123 -> V_349 ,
sizeof( V_3 -> V_122 -> V_123 -> V_349 ) ,
L_45 , V_3 -> V_350 , V_3 -> V_348 ) ;
V_4 -> V_213 = L_46 ;
V_4 -> V_221 = L_47 ;
}
if ( V_3 -> V_10 == 0x11060440 ) {
V_4 -> V_213 = L_38 ;
V_4 -> V_221 = L_41 ;
}
if ( V_3 -> V_10 == 0x11064397 ) {
F_31 ( V_3 -> V_348 ) ;
V_3 -> V_348 = F_27 ( L_48 , V_5 ) ;
snprintf ( V_3 -> V_122 -> V_123 -> V_349 ,
sizeof( V_3 -> V_122 -> V_123 -> V_349 ) ,
L_45 , V_3 -> V_350 , V_3 -> V_348 ) ;
}
V_4 -> F_14 = F_151 ;
return 0 ;
}
static int F_163 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
V_4 -> V_131 . V_200 = 1 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
if ( V_84 -> V_47 [ 0 ] ) {
V_4 -> V_249 [ 0 ] = 0x10 ;
}
return 0 ;
}
static int F_164 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_67 ;
if ( ! V_84 -> V_47 [ 0 ] )
return - 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_23 ,
F_34 ( 0x1A , 3 , 0 , V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_24 ,
F_34 ( 0x1A , 3 , 0 , V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_68 ,
L_49 ,
F_34 ( 0x10 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_13 ,
F_34 ( 0x16 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
return 0 ;
}
static int F_165 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 , V_35 ;
struct V_257 * V_258 ;
static const char * const V_260 [] = { L_26 , L_25 , NULL } ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = 0x1D ;
V_4 -> V_129 = 0 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 ( 0x1D , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_258 = & V_4 -> V_259 [ 1 ] ;
for ( V_35 = 0 ; V_260 [ V_35 ] ; V_35 ++ )
F_115 ( V_258 , V_260 [ V_35 ] , V_35 , NULL ) ;
V_4 -> V_115 = & V_4 -> V_259 [ 1 ] ;
return 0 ;
}
static int F_166 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
static const T_3 V_263 [] = { 0x14 , 0x15 , 0x18 , 0xff } ;
return F_117 ( V_3 , V_84 , 0x1a , V_263 ,
F_67 ( V_263 ) ) ;
}
static int F_167 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_163 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_164 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_165 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
F_162 ( V_3 , 0x1A , V_69 ,
( 0x17 << V_334 ) |
( 0x17 << V_335 ) |
( 0x5 << V_336 ) |
( 1 << V_337 ) ) ;
V_67 = F_166 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
F_159 ( V_3 ) ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
return 1 ;
}
static void F_168 ( struct V_2 * V_3 )
{
int V_314 =
F_50 ( V_3 , 0x13 , 0 , V_117 , 0x00 ) == 3 ;
unsigned int V_93 ;
V_93 = V_102 ;
F_41 ( V_3 , 0x14 , & V_93 ) ;
F_41 ( V_3 , 0x15 , & V_93 ) ;
F_41 ( V_3 , 0x18 , & V_93 ) ;
if ( V_314 )
V_93 = V_101 ;
F_6 ( V_3 , 0x13 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x12 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x1f , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x20 , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x17 , & V_93 ) ;
F_41 ( V_3 , 0x16 , & V_93 ) ;
F_6 ( V_3 , 0x1a , 0 , V_103 ,
V_314 ? V_101 : V_93 ) ;
F_6 ( V_3 , 0x10 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x1d , 0 , V_103 , V_93 ) ;
}
static int F_169 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_167 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_351 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_352 ;
V_4 -> V_213 = L_50 ;
V_4 -> V_216 = & V_353 ;
V_4 -> V_218 = & V_354 ;
V_4 -> V_221 = L_51 ;
V_4 -> V_224 = & V_355 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_356 ;
V_4 -> V_279 = F_67 ( V_356 ) ;
F_131 ( V_3 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_357 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_358 ;
#endif
V_4 -> F_14 = F_168 ;
return 0 ;
}
static int F_170 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_35 ;
T_3 V_71 ;
V_4 -> V_131 . V_200 = V_84 -> V_46 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( V_71 ) {
switch ( V_35 ) {
case V_250 :
V_4 -> V_249 [ V_35 ] = 0x8 ;
break;
case V_251 :
V_4 -> V_249 [ V_35 ] = 0xa ;
break;
case V_252 :
V_4 -> V_249 [ V_35 ] = 0x9 ;
break;
case V_79 :
V_4 -> V_249 [ V_35 ] = 0xb ;
break;
}
}
}
return 0 ;
}
static int F_171 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
char V_41 [ 32 ] ;
static const char * const V_253 [ 4 ] = {
L_15 , L_16 , L_17 , L_18
} ;
T_3 V_255 [] = { 0x8 , 0x9 , 0xa , 0xb } ;
T_3 V_327 [] = { 0x24 , 0x25 , 0x26 , 0x27 } ;
T_3 V_71 , V_254 , V_328 = 0 ;
int V_35 , V_67 ;
for ( V_35 = 0 ; V_35 <= V_79 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( ! V_71 )
continue;
V_254 = V_255 [ V_35 ] ;
V_328 = V_327 [ V_35 ] ;
if ( V_35 == V_251 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_19 ,
F_34 ( V_254 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_68 ,
L_20 ,
F_34 ( V_254 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 (
V_4 , V_256 ,
L_21 ,
F_34 ( V_328 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 (
V_4 , V_256 ,
L_22 ,
F_34 ( V_328 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_250 ) {
V_67 = F_113 ( V_4 , V_68 ,
L_23 ,
F_34 ( 0x21 , 3 , 5 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_24 ,
F_34 ( 0x21 , 3 , 5 ,
V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_256 , V_41 ,
F_34 ( V_328 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else {
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_256 , V_41 ,
F_34 ( V_328 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
}
}
return 0 ;
}
static int F_172 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = 0xc ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 ( 0xc , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
F_114 ( V_4 ) ;
return 0 ;
}
static int F_173 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
static const T_3 V_263 [] = { 0x2c , 0x2b , 0x2a , 0x29 , 0 , 0xff } ;
return F_117 ( V_3 , V_84 , 0x21 , V_263 ,
F_67 ( V_263 ) ) ;
}
static int F_174 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_170 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_171 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_172 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_173 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
F_159 ( V_3 ) ;
if ( V_4 -> V_26 . V_245 && V_3 -> V_10 == 0x11060428 )
V_4 -> V_206 = 0x13 ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
F_72 ( V_4 ) ;
return 1 ;
}
static void F_175 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_314 ;
unsigned int V_93 ;
V_314 =
F_50 ( V_3 , 0x1e , 0 , V_117 , 0x00 ) == 5 ;
V_93 = V_102 ;
F_41 ( V_3 , 0x29 , & V_93 ) ;
F_41 ( V_3 , 0x2a , & V_93 ) ;
F_41 ( V_3 , 0x2b , & V_93 ) ;
if ( V_314 )
V_93 = V_101 ;
F_6 ( V_3 , 0x1e , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x1f , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x10 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x11 , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x27 , & V_93 ) ;
F_6 ( V_3 , 0x1a , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0xb , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x26 , & V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x2b , & V_93 ) ;
F_6 ( V_3 , 0xa , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x24 , & V_93 ) ;
if ( ! V_4 -> V_43 )
F_41 ( V_3 , 0x28 , & V_93 ) ;
F_6 ( V_3 , 0x8 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x21 , 0 , V_103 ,
V_314 ? V_101 : V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x25 , & V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x2a , & V_93 ) ;
F_6 ( V_3 , 0x9 , 0 , V_103 , V_93 ) ;
if ( V_4 -> V_43 ) {
V_93 = V_102 ;
F_41 ( V_3 , 0x28 , & V_93 ) ;
F_6 ( V_3 , 0x1b , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x34 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0xc , 0 ,
V_103 , V_93 ) ;
}
}
static int F_176 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_174 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_359 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_360 ;
if ( V_3 -> V_10 == 0x11060441 )
V_4 -> V_213 = L_52 ;
else if ( V_3 -> V_10 == 0x11064441 )
V_4 -> V_213 = L_53 ;
else
V_4 -> V_213 = L_54 ;
V_4 -> V_216 = & V_361 ;
V_4 -> V_218 = & V_362 ;
if ( V_3 -> V_10 == 0x11060441 )
V_4 -> V_221 = L_55 ;
else if ( V_3 -> V_10 == 0x11064441 )
V_4 -> V_221 = L_56 ;
else
V_4 -> V_221 = L_57 ;
V_4 -> V_224 = & V_363 ;
if ( V_3 -> V_10 == 0x11060428 || V_3 -> V_10 == 0x11060441 )
V_4 -> V_225 = & V_364 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_365 ;
V_4 -> V_279 = F_67 ( V_365 ) ;
F_131 ( V_3 ) ;
F_161 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_161 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_366 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_367 ;
#endif
V_4 -> F_14 = F_175 ;
return 0 ;
}
static int F_177 ( struct V_30 * V_31 ,
struct V_104 * V_105 )
{
V_105 -> type = V_150 ;
V_105 -> V_151 = 1 ;
V_105 -> V_37 . integer . V_152 = 0 ;
V_105 -> V_37 . integer . V_153 = 1 ;
return 0 ;
}
static int F_178 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
int V_368 = 0 ;
V_368 = F_50 ( V_3 , 0x26 , 0 ,
V_117 , 0 ) ;
if ( V_368 != - 1 )
* V_33 -> V_37 . integer . V_37 = V_368 ;
return 0 ;
}
static int F_179 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_4 = V_3 -> V_4 ;
int V_368 = * V_33 -> V_37 . integer . V_37 ;
F_6 ( V_3 , 0x26 , 0 ,
V_130 , V_368 ) ;
V_4 -> V_369 = V_368 ;
F_14 ( V_3 ) ;
return 1 ;
}
static int F_180 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{ int V_35 ;
T_3 V_71 ;
V_4 -> V_131 . V_200 = V_84 -> V_46 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( V_71 ) {
switch ( V_35 ) {
case V_250 :
V_4 -> V_249 [ V_35 ] = 0x10 ;
break;
case V_251 :
V_4 -> V_249 [ V_35 ] = 0x25 ;
break;
case V_252 :
V_4 -> V_249 [ V_35 ] = 0x11 ;
break;
}
}
}
return 0 ;
}
static int F_181 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
char V_41 [ 32 ] ;
static const char * const V_253 [ 3 ] = {
L_15 , L_16 , L_17
} ;
T_3 V_255 [] = { 0x10 , 0x11 , 0x25 } ;
T_3 V_327 [] = { 0x1C , 0x18 , 0x27 } ;
T_3 V_71 , V_254 , V_328 ;
int V_35 , V_67 ;
for ( V_35 = 0 ; V_35 <= V_251 ; V_35 ++ ) {
V_71 = V_84 -> V_47 [ V_35 ] ;
if ( ! V_71 )
continue;
V_254 = V_255 [ V_35 ] ;
V_328 = V_327 [ V_35 ] ;
if ( V_35 == V_251 ) {
V_67 = F_113 (
V_4 , V_68 ,
L_19 ,
F_34 ( V_254 , 1 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 (
V_4 , V_68 ,
L_20 ,
F_34 ( V_254 , 2 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 (
V_4 , V_256 ,
L_21 ,
F_34 ( V_328 , 1 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 (
V_4 , V_256 ,
L_22 ,
F_34 ( V_328 , 2 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else if ( V_35 == V_250 ) {
V_67 = F_113 (
V_4 , V_68 ,
L_23 ,
F_34 ( 0x16 , 3 , 0 , V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 (
V_4 , V_256 ,
L_24 ,
F_34 ( 0x16 , 3 , 0 , V_69 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_256 , V_41 ,
F_34 ( V_328 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
} else {
sprintf ( V_41 , L_4 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_68 , V_41 ,
F_34 ( V_254 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
sprintf ( V_41 , L_5 , V_253 [ V_35 ] ) ;
V_67 = F_113 (
V_4 , V_256 , V_41 ,
F_34 ( V_328 , 3 , 0 ,
V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
}
}
return 0 ;
}
static int F_182 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = 0x25 ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 ( 0x25 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
F_114 ( V_4 ) ;
return 0 ;
}
static int F_183 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
static const T_3 V_263 [] = { 0x1f , 0x1a , 0x1b , 0x1e , 0 , 0xff } ;
return F_117 ( V_3 , V_84 , 0x16 , V_263 ,
F_67 ( V_263 ) ) ;
}
static int F_184 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_180 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_181 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_182 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_183 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
F_159 ( V_3 ) ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
F_72 ( V_4 ) ;
return 1 ;
}
static void F_185 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_314 ;
unsigned int V_93 ;
unsigned int V_370 , V_99 ;
V_314 =
( F_50 ( V_3 , 0x17 , 0 ,
V_117 , 0x00 ) == 5 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x1a , & V_93 ) ;
F_41 ( V_3 , 0x1b , & V_93 ) ;
F_41 ( V_3 , 0x1e , & V_93 ) ;
if ( V_314 )
V_93 = V_101 ;
F_6 ( V_3 , 0x17 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x13 , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x1e , & V_93 ) ;
if ( V_4 -> V_369 )
F_41 ( V_3 , 0x22 , & V_93 ) ;
else
F_6 ( V_3 , 0x22 , 0 ,
V_103 , V_102 ) ;
F_6 ( V_3 , 0x26 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x14 , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x19 , & V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x1b , & V_93 ) ;
F_6 ( V_3 , 0x18 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x11 , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x23 , & V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x1a , & V_93 ) ;
F_6 ( V_3 , 0x27 , 0 , V_103 , V_93 ) ;
if ( V_4 -> V_88 )
F_41 ( V_3 , 0x1e , & V_93 ) ;
F_6 ( V_3 , 0x25 , 0 , V_103 , V_93 ) ;
V_99 = F_43 ( V_3 , 0x1c ) ;
if ( V_99 )
V_370 = 0 ;
else {
V_99 = F_43 ( V_3 , 0x1d ) ;
if ( ! V_4 -> V_43 && V_99 )
V_370 = 0 ;
else
V_370 = 1 ;
}
V_93 = V_370 ? V_101 : V_102 ;
F_6 ( V_3 , 0x28 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x29 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x2a , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x1c , & V_93 ) ;
F_41 ( V_3 , 0x1d , & V_93 ) ;
if ( V_4 -> V_43 )
F_6 ( V_3 , 0x25 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x16 , 0 , V_103 ,
V_314 ? V_101 : V_93 ) ;
F_6 ( V_3 , 0x10 , 0 , V_103 ,
V_370 ? V_101 : V_93 ) ;
}
static int F_186 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_184 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_371 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_372 ;
V_4 -> V_213 = L_58 ;
V_4 -> V_216 = & V_373 ;
V_4 -> V_218 = & V_374 ;
V_4 -> V_221 = L_59 ;
V_4 -> V_224 = & V_375 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_376 ;
V_4 -> V_279 = F_67 ( V_376 ) ;
F_131 ( V_3 ) ;
F_161 ( V_3 , 0x1a , 0 , 3 , 40 ) ;
F_161 ( V_3 , 0x1e , 0 , 3 , 40 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_377 ;
V_4 -> V_203 ++ ;
}
V_4 -> V_204 [ V_4 -> V_203 ] = V_378 ;
V_4 -> V_203 ++ ;
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_379 ;
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_380 ;
#endif
V_4 -> F_14 = F_185 ;
return 0 ;
}
static int F_187 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
V_4 -> V_131 . V_200 = 1 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
if ( V_84 -> V_47 [ 0 ] )
V_4 -> V_249 [ 0 ] = 0x8 ;
return 0 ;
}
static int F_188 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_67 ;
T_3 V_381 ;
if ( ! V_84 -> V_47 [ 0 ] )
return - 1 ;
if ( V_4 -> V_6 == V_25 )
V_381 = 0x28 ;
else
V_381 = 0x26 ;
V_67 = F_113 ( V_4 , V_68 ,
L_23 ,
F_34 ( 0x8 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_382 ,
L_24 ,
F_34 ( V_381 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
return 0 ;
}
static int F_189 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = 0x9 ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 (
V_4 -> V_131 . V_132 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( 0x25 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
F_114 ( V_4 ) ;
return 0 ;
}
static int F_190 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_257 * V_258 = & V_4 -> V_259 [ 0 ] ;
static const T_3 V_263 [] = { 0x2b , 0x2a , 0x29 , 0xff } ;
int V_67 ;
V_67 = F_117 ( V_3 , V_84 , 0x21 , V_263 ,
F_67 ( V_263 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_33 ( V_4 , L_27 , 0 , 3 , 0x21 ) ;
if ( V_67 < 0 )
return V_67 ;
F_115 ( V_258 , L_60 , 4 , NULL ) ;
return 0 ;
}
static int F_191 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_187 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_27 [ 0 ] )
return 0 ;
V_67 = F_188 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_189 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_190 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
F_159 ( V_3 ) ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
return 1 ;
}
static void F_192 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_314 ;
unsigned int V_93 ;
unsigned int V_99 ;
V_314 =
F_50 ( V_3 , 0x1e , 0 , V_117 , 0x00 ) == 3 ;
V_93 = V_102 ;
F_41 ( V_3 , 0x29 , & V_93 ) ;
F_41 ( V_3 , 0x2a , & V_93 ) ;
F_41 ( V_3 , 0x2b , & V_93 ) ;
V_93 = V_101 ;
F_6 ( V_3 , 0x1e , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x1f , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x10 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x11 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x8 , 0 , V_103 , V_93 ) ;
if ( V_4 -> V_6 == V_25 ) {
V_93 = V_102 ;
F_41 ( V_3 , 0x28 , & V_93 ) ;
F_6 ( V_3 , 0x18 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x38 , 0 ,
V_103 , V_93 ) ;
} else {
V_93 = V_102 ;
F_41 ( V_3 , 0x26 , & V_93 ) ;
F_6 ( V_3 , 0x1c , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x37 , 0 ,
V_103 , V_93 ) ;
}
if ( V_4 -> V_6 == V_25 ) {
V_93 = V_102 ;
F_41 ( V_3 , 0x25 , & V_93 ) ;
F_6 ( V_3 , 0x15 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x35 , 0 ,
V_103 , V_93 ) ;
} else {
V_93 = V_102 ;
F_41 ( V_3 , 0x25 , & V_93 ) ;
F_6 ( V_3 , 0x19 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x35 , 0 ,
V_103 , V_93 ) ;
}
if ( V_4 -> V_43 )
F_6 ( V_3 , 0x9 , 0 ,
V_103 , V_101 ) ;
V_99 = F_43 ( V_3 , 0x25 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x24 , & V_93 ) ;
V_93 = V_99 ? V_102 : V_101 ;
if ( V_4 -> V_6 == V_25 )
F_6 ( V_3 , 0x14 , 0 ,
V_103 , V_93 ) ;
else
F_6 ( V_3 , 0x18 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x34 , 0 , V_103 , V_93 ) ;
V_99 = F_43 ( V_3 , 0x26 ) ;
V_93 = V_99 ? V_102 : V_101 ;
if ( V_4 -> V_6 == V_25 ) {
F_6 ( V_3 , 0x33 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x1c , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x3c , 0 ,
V_103 , V_93 ) ;
} else {
F_6 ( V_3 , 0x31 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x17 , 0 ,
V_103 , V_93 ) ;
F_6 ( V_3 , 0x3b , 0 ,
V_103 , V_93 ) ;
}
if ( V_314 || ! F_12 ( V_3 ) )
F_6 ( V_3 , 0x21 , 0 ,
V_103 , V_101 ) ;
else
F_6 ( V_3 , 0x21 , 0 ,
V_103 , V_102 ) ;
}
static int F_193 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_191 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
if ( V_4 -> V_6 == V_25 )
V_4 -> V_244 [ V_4 -> V_243 ++ ] =
V_383 ;
else
V_4 -> V_244 [ V_4 -> V_243 ++ ] =
V_384 ;
if ( V_4 -> V_6 == V_25 )
V_4 -> V_244 [ V_4 -> V_243 ++ ] =
V_385 ;
else
V_4 -> V_244 [ V_4 -> V_243 ++ ] =
V_386 ;
if ( V_4 -> V_6 == V_25 )
V_4 -> V_213 = L_61 ;
else
V_4 -> V_213 = L_62 ;
V_4 -> V_216 = & V_387 ;
V_4 -> V_218 = & V_388 ;
if ( V_4 -> V_6 == V_25 )
V_4 -> V_221 = L_63 ;
else
V_4 -> V_221 = L_64 ;
V_4 -> V_224 = & V_389 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_390 ;
V_4 -> V_279 = F_67 ( V_390 ) ;
F_131 ( V_3 ) ;
F_161 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_161 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_391 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_392 ;
#endif
V_4 -> F_14 = F_192 ;
return 0 ;
}
static int F_194 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
V_4 -> V_131 . V_200 = 1 ;
V_4 -> V_131 . V_133 = V_4 -> V_249 ;
if ( V_84 -> V_47 [ 0 ] )
V_4 -> V_249 [ 0 ] = 0x8 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_4 ,
const struct V_83 * V_84 )
{
int V_67 ;
if ( ! V_84 -> V_47 [ 0 ] )
return - 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_49 ,
F_34 ( 0x8 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_382 ,
L_13 ,
F_34 ( 0x28 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
return 0 ;
}
static int F_196 ( struct V_1 * V_4 , T_3 V_81 )
{
int V_67 ;
if ( ! V_81 )
return 0 ;
V_4 -> V_131 . V_132 = 0x9 ;
V_4 -> V_129 = 1 ;
V_67 = F_113 ( V_4 , V_68 ,
L_6 ,
F_34 (
V_4 -> V_131 . V_132 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_113 ( V_4 , V_256 ,
L_7 ,
F_34 ( V_81 , 3 , 0 , V_45 ) ) ;
if ( V_67 < 0 )
return V_67 ;
F_114 ( V_4 ) ;
return 0 ;
}
static int F_197 ( struct V_2 * V_3 ,
const struct V_83 * V_84 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
struct V_257 * V_258 = & V_4 -> V_259 [ 0 ] ;
static const T_3 V_263 [] = { 0x2b , 0x2a , 0x29 , 0 , 0 , 0xff } ;
int V_67 ;
V_67 = F_117 ( V_3 , V_84 , 0x21 , V_263 ,
F_67 ( V_263 ) ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_33 ( V_4 , L_27 , 0 , 5 , 0x21 ) ;
if ( V_67 < 0 )
return V_67 ;
F_115 ( V_258 , L_60 , 6 , NULL ) ;
return 0 ;
}
static int F_198 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_67 ;
V_67 = F_127 ( V_3 , & V_4 -> V_26 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
F_159 ( V_3 ) ;
V_67 = F_194 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ! V_4 -> V_26 . V_46 && ! V_4 -> V_26 . V_44 )
return 0 ;
V_67 = F_195 ( V_4 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_196 ( V_4 , V_4 -> V_26 . V_27 [ 0 ] ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_197 ( V_3 , & V_4 -> V_26 ) ;
if ( V_67 < 0 )
return V_67 ;
V_4 -> V_131 . V_220 = V_4 -> V_131 . V_200 * 2 ;
F_159 ( V_3 ) ;
if ( V_4 -> V_54 . V_61 )
V_4 -> V_204 [ V_4 -> V_203 ++ ] = V_4 -> V_54 . V_61 ;
V_4 -> V_106 = & V_4 -> V_259 [ 0 ] ;
if ( V_4 -> V_115 )
F_64 ( V_3 ) ;
return 1 ;
}
static void F_199 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_314 =
F_50 ( V_3 , 0x13 , 0 , V_117 , 0x00 ) == 3 ;
unsigned int V_93 ;
unsigned int V_99 ;
V_314 =
F_50 ( V_3 , 0x1e , 0 , V_117 , 0x00 ) == 5 ;
V_93 = V_102 ;
F_41 ( V_3 , 0x29 , & V_93 ) ;
F_41 ( V_3 , 0x2a , & V_93 ) ;
F_41 ( V_3 , 0x2b , & V_93 ) ;
V_93 = V_101 ;
F_6 ( V_3 , 0x1e , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x1f , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x10 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x11 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x8 , 0 ,
V_103 , V_101 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x28 , & V_93 ) ;
F_6 ( V_3 , 0x18 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x38 , 0 , V_103 , V_93 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x25 , & V_93 ) ;
F_6 ( V_3 , 0x15 , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x35 , 0 , V_103 , V_93 ) ;
if ( V_4 -> V_43 )
F_6 ( V_3 , 0x9 , 0 ,
V_103 , V_101 ) ;
V_99 = F_43 ( V_3 , 0x25 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x24 , & V_93 ) ;
if ( V_99 ) {
F_6 ( V_3 , 0x14 , 0 ,
V_103 , V_102 ) ;
F_6 ( V_3 , 0x34 , 0 ,
V_103 , V_102 ) ;
} else {
F_6 ( V_3 , 0x14 , 0 ,
V_103 , V_101 ) ;
F_6 ( V_3 , 0x34 , 0 ,
V_103 , V_101 ) ;
}
V_99 = F_43 ( V_3 , 0x28 ) ;
V_93 = V_102 ;
F_41 ( V_3 , 0x31 , & V_93 ) ;
if ( V_99 ) {
F_6 ( V_3 , 0x1c , 0 ,
V_103 , V_102 ) ;
F_6 ( V_3 , 0x3c , 0 ,
V_103 , V_102 ) ;
F_6 ( V_3 , 0x3e , 0 ,
V_103 , V_102 ) ;
} else {
F_6 ( V_3 , 0x1c , 0 ,
V_103 , V_101 ) ;
F_6 ( V_3 , 0x3c , 0 ,
V_103 , V_101 ) ;
F_6 ( V_3 , 0x3e , 0 ,
V_103 , V_101 ) ;
}
V_93 = V_102 ;
F_41 ( V_3 , 0x33 , & V_93 ) ;
F_6 ( V_3 , 0x1d , 0 , V_103 , V_93 ) ;
F_6 ( V_3 , 0x3d , 0 , V_103 , V_93 ) ;
}
static int F_200 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_67 ;
V_4 = F_1 ( V_3 ) ;
if ( V_4 == NULL )
return - V_55 ;
V_67 = F_198 ( V_3 ) ;
if ( V_67 < 0 ) {
F_100 ( V_3 ) ;
return V_67 ;
} else if ( ! V_67 ) {
F_135 ( V_281 L_28
L_29 ) ;
}
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_393 ;
V_4 -> V_244 [ V_4 -> V_243 ++ ] = V_394 ;
V_4 -> V_213 = L_65 ;
V_4 -> V_216 = & V_395 ;
V_4 -> V_218 = & V_396 ;
V_4 -> V_221 = L_66 ;
V_4 -> V_224 = & V_397 ;
if ( ! V_4 -> V_202 && V_4 -> V_106 ) {
V_4 -> V_202 = V_398 ;
V_4 -> V_279 = F_67 ( V_398 ) ;
F_131 ( V_3 ) ;
F_161 ( V_3 , 0x2b , 0 , 3 , 40 ) ;
F_161 ( V_3 , 0x29 , 0 , 3 , 40 ) ;
V_4 -> V_204 [ V_4 -> V_203 ] = V_399 ;
V_4 -> V_203 ++ ;
}
V_3 -> V_289 = V_290 ;
V_3 -> V_289 . V_291 = F_128 ;
V_3 -> V_289 . V_306 = F_105 ;
#ifdef F_136
V_4 -> V_248 . V_292 = V_400 ;
#endif
V_4 -> F_14 = F_199 ;
return 0 ;
}
static int T_5 F_201 ( void )
{
return F_202 ( & V_401 ) ;
}
static void T_6 F_203 ( void )
{
F_204 ( & V_401 ) ;
}
