static void F_1 ( struct V_1 * V_2 , int V_3 , int * V_4 ,
int * V_5 , int * V_6 )
{
switch ( V_3 & ( V_7 | V_8 |
V_9 | V_10 ) ) {
case V_7 :
* V_4 = V_11 ;
* V_5 = V_12 ;
break;
case V_8 :
* V_4 = V_11 ;
* V_5 = V_13 ;
break;
case V_9 :
* V_4 = V_14 ;
* V_5 = V_12 ;
break;
case V_10 :
* V_4 = V_14 ;
* V_5 = V_13 ;
break;
default:
F_2 ( & V_2 -> V_2 , L_1 ,
V_3 ) ;
* V_4 = V_14 ;
* V_5 = V_13 ;
break;
}
if ( V_3 & V_15 )
* V_6 = V_16 ;
else
* V_6 = V_17 ;
}
static int F_3 ( struct V_1 * V_2 , int type , int V_18 ,
int V_19 )
{
int V_3 = 0 ;
if ( V_18 )
V_3 |= V_20 ;
switch ( type ) {
case V_21 :
V_3 |= V_22 ;
break;
case V_23 :
V_3 |= V_24 ;
break;
case V_25 :
V_3 |= V_26 ;
break;
case V_27 :
V_3 |= V_28 ;
break;
default:
V_3 |= V_22 ;
F_2 ( & V_2 -> V_2 , L_2 , type ) ;
}
switch ( V_19 ) {
case V_29 :
V_3 |= V_30 ;
break;
case V_31 :
V_3 |= V_32 ;
break;
case V_33 :
V_3 |= V_34 ;
break;
default:
V_3 |= V_32 ;
F_2 ( & V_2 -> V_2 , L_3 , V_19 ) ;
}
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
if ( ! ( V_36 -> V_3 & V_37 ) )
F_5 ( V_36 -> V_38 , 1 ) ;
F_6 ( V_2 , V_36 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_41 * V_42 ,
int V_43 )
{
int V_44 = sizeof( V_40 -> V_45 ) ;
T_1 V_46 = V_40 -> V_46 ;
T_1 * V_45 = V_40 -> V_45 ;
int V_47 ;
V_47 = V_40 -> V_48 - V_44 - 1 ;
if ( V_46 == V_42 -> V_49 &&
V_44 == sizeof( V_42 -> V_50 ) &&
memcmp ( V_45 , V_42 -> V_50 , V_44 ) == 0 ) {
if ( V_43 && V_43 != V_47 ) {
F_2 ( & V_2 -> V_2 , L_4
L_5 ,
V_43 , V_47 ) ;
return 0 ;
}
return 1 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
if ( F_7 ( V_2 , V_40 , & V_51 , 16 ) ) {
T_2 V_38 , V_52 ;
memcpy ( & V_38 , V_40 -> V_53 , sizeof( V_38 ) ) ;
memcpy ( & V_52 , V_40 -> V_53 + 8 , sizeof( V_52 ) ) ;
F_9 ( V_2 , V_38 , V_38 + V_52 - 1 , 0 ) ;
}
}
static T_3 F_10 ( struct V_54 * V_55 ,
void * V_50 )
{
struct V_1 * V_2 = V_50 ;
struct V_56 * V_57 ;
struct V_39 * V_58 ;
struct V_35 V_36 = { 0 } ;
int V_59 , V_3 ;
if ( F_11 ( V_55 , & V_36 )
|| F_12 ( V_55 , & V_36 )
|| F_13 ( V_55 , & V_36 )
|| F_14 ( V_55 , & V_36 ) ) {
F_6 ( V_2 , & V_36 ) ;
return V_60 ;
}
V_36 . V_3 = 0 ;
if ( F_15 ( V_55 , 0 , & V_36 ) ) {
F_4 ( V_2 , & V_36 ) ;
for ( V_59 = 1 ; F_15 ( V_55 , V_59 , & V_36 ) ; V_59 ++ )
F_4 ( V_2 , & V_36 ) ;
if ( V_59 > 1 ) {
if ( F_16 ( V_2 ) ) {
F_17 ( & V_2 -> V_2 , L_6
L_7
L_8 ) ;
V_2 -> V_61 &= ~ V_62 ;
}
}
return V_60 ;
} else if ( V_36 . V_3 & V_37 ) {
F_18 ( V_2 , 0 , V_37 ) ;
return V_60 ;
}
switch ( V_55 -> type ) {
case V_63 :
V_57 = & V_55 -> V_50 . V_57 ;
if ( V_57 -> V_64 > 0 && V_57 -> V_65 [ 0 ] != ( T_1 ) - 1 )
V_3 = F_3 ( V_2 , V_57 -> type , V_57 -> V_18 ,
V_57 -> V_19 ) ;
else
V_3 = V_37 ;
F_19 ( V_2 , V_57 -> V_65 [ 0 ] , V_3 ) ;
break;
case V_66 :
case V_67 :
break;
case V_68 :
V_58 = & V_55 -> V_50 . V_58 ;
F_8 ( V_2 , V_58 ) ;
break;
case V_69 :
break;
case V_70 :
break;
default:
F_17 ( & V_2 -> V_2 , L_9 ,
V_55 -> type ) ;
return V_71 ;
}
return V_60 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = V_2 -> V_50 ;
T_4 V_74 = V_73 -> V_74 ;
T_3 V_75 ;
F_21 ( & V_2 -> V_2 , L_10 ) ;
F_22 ( V_2 ) ;
V_75 = F_23 ( V_74 , V_76 ,
F_10 , V_2 ) ;
if ( F_24 ( V_75 ) ) {
if ( V_75 != V_77 )
F_2 ( & V_2 -> V_2 , L_11 , V_75 ) ;
return - V_78 ;
}
return 0 ;
}
static T_5 void F_25 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_56 * V_80 )
{
int V_59 ;
unsigned char V_81 = 0 , V_3 ;
for ( V_59 = 0 ; V_59 < V_80 -> V_64 ; V_59 ++ )
V_81 |= 1 << V_80 -> V_65 [ V_59 ] ;
V_3 = F_3 ( V_2 , V_80 -> type , V_80 -> V_18 , V_80 -> V_19 ) ;
F_26 ( V_2 , V_79 , V_81 , V_3 ) ;
}
static T_5 void F_27 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_82 * V_80 )
{
int V_59 ;
T_6 V_81 ;
unsigned char V_3 ;
F_28 ( V_81 . V_83 , V_84 ) ;
for ( V_59 = 0 ; V_59 < V_80 -> V_85 ; V_59 ++ )
if ( V_80 -> V_86 [ V_59 ] )
F_29 ( V_80 -> V_86 [ V_59 ] , V_81 . V_83 ) ;
V_3 = F_30 ( V_80 -> V_4 , V_80 -> V_5 , V_80 -> V_87 ) ;
F_31 ( V_2 , V_79 , & V_81 , V_3 ) ;
}
static T_5 void F_32 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_88 * V_80 )
{
int V_59 ;
T_6 V_81 ;
unsigned char V_3 ;
F_28 ( V_81 . V_83 , V_84 ) ;
for ( V_59 = 0 ; V_59 < V_80 -> V_85 ; V_59 ++ ) {
if ( V_80 -> V_86 [ V_59 ] ) {
if ( V_80 -> V_86 [ V_59 ] < V_84 )
F_29 ( V_80 -> V_86 [ V_59 ] , V_81 . V_83 ) ;
else
F_2 ( & V_2 -> V_2 , L_12
L_13 ,
V_80 -> V_86 [ V_59 ] , V_84 ) ;
}
}
V_3 = F_30 ( V_80 -> V_4 , V_80 -> V_5 , V_80 -> V_87 ) ;
F_31 ( V_2 , V_79 , & V_81 , V_3 ) ;
}
static T_5 void F_33 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_89 * V_90 )
{
unsigned char V_3 = 0 ;
if ( V_90 -> V_91 == V_92 )
V_3 = V_93 ;
F_34 ( V_2 , V_79 , V_90 -> V_94 , V_90 -> V_95 ,
V_90 -> V_96 , V_90 -> V_97 , V_3 ) ;
}
static T_5 void F_35 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_98 * V_90 )
{
F_34 ( V_2 , V_79 , V_90 -> V_99 , V_90 -> V_99 ,
0 , V_90 -> V_97 , V_100 ) ;
}
static T_5 void F_36 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_101 * V_80 )
{
unsigned char V_3 = 0 ;
if ( V_80 -> V_102 == V_103 )
V_3 = V_104 ;
F_37 ( V_2 , V_79 , V_80 -> V_94 , V_80 -> V_95 ,
V_80 -> V_96 , V_80 -> V_97 , V_3 ) ;
}
static T_5 void F_38 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_105 * V_80 )
{
unsigned char V_3 = 0 ;
if ( V_80 -> V_102 == V_103 )
V_3 = V_104 ;
F_37 ( V_2 , V_79 , V_80 -> V_94 , V_80 -> V_95 ,
V_80 -> V_96 , V_80 -> V_97 , V_3 ) ;
}
static T_5 void F_39 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_106 * V_80 )
{
unsigned char V_3 = 0 ;
if ( V_80 -> V_102 == V_103 )
V_3 = V_104 ;
F_37 ( V_2 , V_79 , V_80 -> V_99 , V_80 -> V_99 ,
0 , V_80 -> V_97 , V_3 ) ;
}
static T_5 void F_40 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_54 * V_36 )
{
struct V_107 V_108 , * V_80 = & V_108 ;
T_3 V_75 ;
unsigned char V_3 = 0 ;
V_75 = F_41 ( V_36 , V_80 ) ;
if ( F_24 ( V_75 ) ) {
F_17 ( & V_2 -> V_2 , L_14 ,
V_36 -> type ) ;
return;
}
if ( V_80 -> V_109 == V_110 ) {
if ( V_80 -> V_111 . V_112 . V_102 == V_103 )
V_3 = V_104 ;
F_37 ( V_2 , V_79 , V_80 -> V_94 ,
V_80 -> V_94 , 0 , V_80 -> V_97 ,
V_3 ) ;
} else if ( V_80 -> V_109 == V_113 )
F_34 ( V_2 , V_79 , V_80 -> V_94 ,
V_80 -> V_94 , 0 , V_80 -> V_97 ,
V_100 ) ;
}
static T_5 void F_42 ( struct V_1 * V_2 ,
unsigned int V_79 ,
struct V_54 * V_36 )
{
struct V_114 * V_80 = & V_36 -> V_50 . V_115 ;
unsigned char V_3 = 0 ;
if ( V_80 -> V_109 == V_110 ) {
if ( V_80 -> V_111 . V_112 . V_102 == V_103 )
V_3 = V_104 ;
F_37 ( V_2 , V_79 , V_80 -> V_94 ,
V_80 -> V_94 , 0 , V_80 -> V_97 ,
V_3 ) ;
} else if ( V_80 -> V_109 == V_113 )
F_34 ( V_2 , V_79 , V_80 -> V_94 ,
V_80 -> V_94 , 0 , V_80 -> V_97 ,
V_100 ) ;
}
static T_5 T_3 F_43 ( struct V_54 * V_55 ,
void * V_50 )
{
int V_116 ;
struct V_117 * V_118 = V_50 ;
struct V_1 * V_2 = V_118 -> V_2 ;
unsigned int V_79 = V_118 -> V_79 ;
switch ( V_55 -> type ) {
case V_119 :
F_27 ( V_2 , V_79 , & V_55 -> V_50 . V_120 ) ;
break;
case V_63 :
F_25 ( V_2 , V_79 , & V_55 -> V_50 . V_57 ) ;
break;
case V_66 :
switch ( V_55 -> V_50 . V_121 . V_122 ) {
case V_123 :
V_116 = V_124 ;
break;
case V_125 :
V_116 = V_126 ;
break;
case V_127 :
V_116 = V_128 ;
break;
default:
V_116 = V_129 ;
break;
}
V_118 -> V_79 = F_44 ( V_2 , V_116 ) ;
break;
case V_67 :
V_118 -> V_79 = 0 ;
break;
case V_130 :
F_33 ( V_2 , V_79 , & V_55 -> V_50 . V_90 ) ;
break;
case V_131 :
F_35 ( V_2 , V_79 ,
& V_55 -> V_50 . V_132 ) ;
break;
case V_68 :
case V_69 :
break;
case V_133 :
F_36 ( V_2 , V_79 ,
& V_55 -> V_50 . V_134 ) ;
break;
case V_135 :
F_38 ( V_2 , V_79 ,
& V_55 -> V_50 . V_136 ) ;
break;
case V_137 :
F_39 ( V_2 , V_79 ,
& V_55 -> V_50 . V_138 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
F_40 ( V_2 , V_79 , V_55 ) ;
break;
case V_142 :
F_42 ( V_2 , V_79 , V_55 ) ;
break;
case V_143 :
F_32 ( V_2 , V_79 ,
& V_55 -> V_50 . V_144 ) ;
break;
case V_70 :
break;
default:
F_17 ( & V_2 -> V_2 , L_15 ,
V_55 -> type ) ;
return V_71 ;
}
return V_60 ;
}
int T_5 F_45 ( struct V_1 * V_2 )
{
struct V_72 * V_73 = V_2 -> V_50 ;
T_4 V_74 = V_73 -> V_74 ;
T_3 V_75 ;
struct V_117 V_118 ;
F_21 ( & V_2 -> V_2 , L_16 ) ;
V_118 . V_2 = V_2 ;
V_118 . V_79 = 0 ;
V_75 = F_23 ( V_74 , V_145 ,
F_43 , & V_118 ) ;
if ( F_24 ( V_75 ) ) {
if ( V_75 != V_77 )
F_2 ( & V_2 -> V_2 , L_17 , V_75 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_46 ( struct V_54 * V_55 )
{
switch ( V_55 -> type ) {
case V_119 :
case V_63 :
case V_130 :
case V_131 :
case V_133 :
case V_135 :
case V_137 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
return 1 ;
}
return 0 ;
}
static T_3 F_47 ( struct V_54 * V_55 ,
void * V_50 )
{
int * V_146 = V_50 ;
if ( F_46 ( V_55 ) )
( * V_146 ) ++ ;
return V_60 ;
}
static T_3 F_48 ( struct V_54 * V_55 , void * V_50 )
{
struct V_54 * * V_35 = V_50 ;
if ( F_46 ( V_55 ) ) {
( * V_35 ) -> type = V_55 -> type ;
( * V_35 ) -> V_52 = sizeof( struct V_54 ) ;
if ( V_55 -> type == V_119 )
( * V_35 ) -> V_50 . V_120 . V_147 =
V_55 -> V_50 . V_120 . V_147 ;
( * V_35 ) ++ ;
}
return V_60 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_72 * V_73 = V_2 -> V_50 ;
T_4 V_74 = V_73 -> V_74 ;
struct V_54 * V_35 ;
int V_146 = 0 ;
T_3 V_75 ;
V_75 = F_23 ( V_74 , V_76 ,
F_47 , & V_146 ) ;
if ( F_24 ( V_75 ) ) {
F_2 ( & V_2 -> V_2 , L_18 , V_75 ) ;
return - V_150 ;
}
if ( ! V_146 )
return - V_150 ;
V_149 -> V_52 = sizeof( struct V_54 ) * ( V_146 + 1 ) + 1 ;
V_149 -> V_151 = F_50 ( V_149 -> V_52 - 1 , V_152 ) ;
if ( ! V_149 -> V_151 )
return - V_153 ;
V_35 = (struct V_54 * ) V_149 -> V_151 ;
V_75 = F_23 ( V_74 , V_76 ,
F_48 , & V_35 ) ;
if ( F_24 ( V_75 ) ) {
F_51 ( V_149 -> V_151 ) ;
F_2 ( & V_2 -> V_2 , L_18 , V_75 ) ;
return - V_150 ;
}
V_35 -> type = V_69 ;
V_35 -> V_52 = sizeof( struct V_54 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_82 * V_120 = & V_35 -> V_50 . V_120 ;
int V_4 , V_5 , V_6 ;
if ( ! F_53 ( V_80 ) ) {
V_120 -> V_85 = 0 ;
F_21 ( & V_2 -> V_2 , L_19 ,
V_80 ? L_20 : L_21 ) ;
return;
}
F_1 ( V_2 , V_80 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_120 -> V_4 = V_4 ;
V_120 -> V_5 = V_5 ;
V_120 -> V_87 = V_6 ;
V_120 -> V_85 = 1 ;
V_120 -> V_86 [ 0 ] = V_80 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_22 ,
( int ) V_80 -> V_38 ,
V_4 == V_11 ? L_23 : L_24 ,
V_5 == V_12 ? L_25 : L_26 ,
V_120 -> V_87 == V_16 ? L_27 : L_28 ,
V_120 -> V_147 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_88 * V_144 = & V_35 -> V_50 . V_144 ;
int V_4 , V_5 , V_6 ;
if ( ! F_53 ( V_80 ) ) {
V_144 -> V_85 = 0 ;
F_21 ( & V_2 -> V_2 , L_29 ,
V_80 ? L_20 : L_21 ) ;
return;
}
F_1 ( V_2 , V_80 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_144 -> V_154 = V_155 ;
V_144 -> V_4 = V_4 ;
V_144 -> V_5 = V_5 ;
V_144 -> V_87 = V_6 ;
V_144 -> V_85 = 1 ;
V_144 -> V_86 [ 0 ] = V_80 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_30 , ( int ) V_80 -> V_38 ,
V_4 == V_11 ? L_23 : L_24 ,
V_5 == V_12 ? L_25 : L_26 ,
V_144 -> V_87 == V_16 ? L_27 : L_28 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_56 * V_57 = & V_35 -> V_50 . V_57 ;
if ( ! F_53 ( V_80 ) ) {
V_57 -> V_64 = 0 ;
F_21 ( & V_2 -> V_2 , L_31 ,
V_80 ? L_20 : L_21 ) ;
return;
}
switch ( V_80 -> V_3 & V_156 ) {
case V_24 :
V_57 -> type = V_23 ;
break;
case V_26 :
V_57 -> type = V_25 ;
break;
case V_28 :
V_57 -> type = V_27 ;
break;
default:
V_57 -> type = V_21 ;
}
switch ( V_80 -> V_3 & V_157 ) {
case V_30 :
V_57 -> V_19 = V_29 ;
break;
case V_32 :
V_57 -> V_19 = V_31 ;
break;
default:
V_57 -> V_19 = V_33 ;
}
V_57 -> V_18 = ! ! ( V_80 -> V_3 & V_20 ) ;
V_57 -> V_64 = 1 ;
V_57 -> V_65 [ 0 ] = V_80 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_32
L_33 ,
( int ) V_80 -> V_38 , V_57 -> type , V_57 -> V_19 , V_57 -> V_18 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_89 * V_90 = & V_35 -> V_50 . V_90 ;
if ( F_53 ( V_80 ) ) {
V_90 -> V_91 = ( V_80 -> V_3 & V_93 ) ?
V_92 : V_158 ;
V_90 -> V_94 = V_80 -> V_38 ;
V_90 -> V_95 = V_80 -> V_159 ;
V_90 -> V_96 = 0 ;
V_90 -> V_97 = F_57 ( V_80 ) ;
} else {
V_90 -> V_94 = 0 ;
V_90 -> V_97 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_34 , V_90 -> V_94 ,
V_90 -> V_94 + V_90 -> V_97 - 1 , V_90 -> V_91 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_98 * V_132 = & V_35 -> V_50 . V_132 ;
if ( F_53 ( V_80 ) ) {
V_132 -> V_99 = V_80 -> V_38 ;
V_132 -> V_97 = F_57 ( V_80 ) ;
} else {
V_132 -> V_99 = 0 ;
V_132 -> V_97 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_35 , V_132 -> V_99 ,
V_132 -> V_99 + V_132 -> V_97 - 1 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_101 * V_134 = & V_35 -> V_50 . V_134 ;
if ( F_53 ( V_80 ) ) {
V_134 -> V_102 = V_80 -> V_3 & V_104 ?
V_103 : V_160 ;
V_134 -> V_94 = V_80 -> V_38 ;
V_134 -> V_95 = V_80 -> V_159 ;
V_134 -> V_96 = 0 ;
V_134 -> V_97 = F_57 ( V_80 ) ;
} else {
V_134 -> V_94 = 0 ;
V_134 -> V_97 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_36 ,
V_134 -> V_94 ,
V_134 -> V_94 + V_134 -> V_97 - 1 ,
V_134 -> V_102 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_105 * V_136 = & V_35 -> V_50 . V_136 ;
if ( F_53 ( V_80 ) ) {
V_136 -> V_102 = V_80 -> V_3 & V_104 ?
V_103 : V_160 ;
V_136 -> V_94 = V_80 -> V_38 ;
V_136 -> V_95 = V_80 -> V_159 ;
V_136 -> V_96 = 0 ;
V_136 -> V_97 = F_57 ( V_80 ) ;
} else {
V_136 -> V_94 = 0 ;
V_136 -> V_96 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_37 ,
V_136 -> V_94 ,
V_136 -> V_94 + V_136 -> V_97 - 1 ,
V_136 -> V_102 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_80 )
{
struct V_106 * V_138 = & V_35 -> V_50 . V_138 ;
if ( F_53 ( V_80 ) ) {
V_138 -> V_102 =
V_80 -> V_3 & V_104 ?
V_103 : V_160 ;
V_138 -> V_99 = V_80 -> V_38 ;
V_138 -> V_97 = F_57 ( V_80 ) ;
} else {
V_138 -> V_99 = 0 ;
V_138 -> V_97 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_38 ,
V_138 -> V_99 ,
V_138 -> V_99 + V_138 -> V_97 - 1 ,
V_138 -> V_102 ) ;
}
int F_62 ( struct V_1 * V_2 , struct V_148 * V_149 )
{
int V_59 = 0 ;
int V_146 = ( V_149 -> V_52 - 1 ) / sizeof( struct V_54 ) - 1 ;
struct V_54 * V_35 = V_149 -> V_151 ;
int V_161 = 0 , V_120 = 0 , V_57 = 0 , V_112 = 0 ;
F_21 ( & V_2 -> V_2 , L_39 , V_146 ) ;
while ( V_59 < V_146 ) {
switch ( V_35 -> type ) {
case V_119 :
F_52 ( V_2 , V_35 ,
F_63 ( V_2 , V_162 , V_120 ) ) ;
V_120 ++ ;
break;
case V_63 :
F_55 ( V_2 , V_35 ,
F_63 ( V_2 , V_163 , V_57 ) ) ;
V_57 ++ ;
break;
case V_130 :
F_56 ( V_2 , V_35 ,
F_63 ( V_2 , V_164 , V_161 ) ) ;
V_161 ++ ;
break;
case V_131 :
F_58 ( V_2 , V_35 ,
F_63 ( V_2 , V_164 , V_161 ) ) ;
V_161 ++ ;
break;
case V_133 :
F_59 ( V_2 , V_35 ,
F_63 ( V_2 , V_165 , V_112 ) ) ;
V_112 ++ ;
break;
case V_135 :
F_60 ( V_2 , V_35 ,
F_63 ( V_2 , V_165 , V_112 ) ) ;
V_112 ++ ;
break;
case V_137 :
F_61 ( V_2 , V_35 ,
F_63 ( V_2 , V_165 , V_112 ) ) ;
V_112 ++ ;
break;
case V_143 :
F_54 ( V_2 , V_35 ,
F_63 ( V_2 , V_162 , V_120 ) ) ;
V_120 ++ ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_70 :
default:
F_17 ( & V_2 -> V_2 , L_40
L_41 , V_35 -> type ) ;
return - V_150 ;
}
V_35 ++ ;
V_59 ++ ;
}
return 0 ;
}
