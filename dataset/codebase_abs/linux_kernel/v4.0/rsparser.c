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
struct V_59 V_60 = { { 0 } , 0 } ;
struct V_35 * V_36 = & V_60 . V_55 ;
int V_61 , V_3 ;
if ( F_11 ( V_55 , & V_60 )
|| F_12 ( V_55 , & V_60 ) ) {
F_6 ( V_2 , & V_60 . V_55 ) ;
return V_62 ;
}
V_36 -> V_3 = 0 ;
if ( F_13 ( V_55 , 0 , V_36 ) ) {
F_4 ( V_2 , V_36 ) ;
for ( V_61 = 1 ; F_13 ( V_55 , V_61 , V_36 ) ; V_61 ++ )
F_4 ( V_2 , V_36 ) ;
if ( V_61 > 1 ) {
if ( F_14 ( V_2 ) ) {
F_15 ( & V_2 -> V_2 , L_6
L_7
L_8 ) ;
V_2 -> V_63 &= ~ V_64 ;
}
}
return V_62 ;
} else if ( V_36 -> V_3 & V_37 ) {
F_16 ( V_2 , 0 , V_37 ) ;
return V_62 ;
}
switch ( V_55 -> type ) {
case V_65 :
case V_66 :
case V_67 :
if ( F_17 ( V_55 , V_36 ) )
F_6 ( V_2 , V_36 ) ;
break;
case V_68 :
case V_69 :
if ( F_18 ( V_55 , V_36 ) )
F_6 ( V_2 , V_36 ) ;
break;
case V_70 :
V_57 = & V_55 -> V_50 . V_57 ;
if ( V_57 -> V_71 > 0 && V_57 -> V_72 [ 0 ] != ( T_1 ) - 1 )
V_3 = F_3 ( V_2 , V_57 -> type , V_57 -> V_18 ,
V_57 -> V_19 ) ;
else
V_3 = V_37 ;
F_19 ( V_2 , V_57 -> V_72 [ 0 ] , V_3 ) ;
break;
case V_73 :
case V_74 :
break;
case V_75 :
V_58 = & V_55 -> V_50 . V_58 ;
F_8 ( V_2 , V_58 ) ;
break;
case V_76 :
break;
case V_77 :
break;
default:
F_15 ( & V_2 -> V_2 , L_9 ,
V_55 -> type ) ;
return V_78 ;
}
return V_62 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_50 ;
T_4 V_81 = V_80 -> V_81 ;
T_3 V_82 ;
F_21 ( & V_2 -> V_2 , L_10 ) ;
F_22 ( V_2 ) ;
V_82 = F_23 ( V_81 , V_83 ,
F_10 , V_2 ) ;
if ( F_24 ( V_82 ) ) {
if ( V_82 != V_84 )
F_2 ( & V_2 -> V_2 , L_11 , V_82 ) ;
return - V_85 ;
}
return 0 ;
}
static T_5 void F_25 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_56 * V_87 )
{
int V_61 ;
unsigned char V_88 = 0 , V_3 ;
for ( V_61 = 0 ; V_61 < V_87 -> V_71 ; V_61 ++ )
V_88 |= 1 << V_87 -> V_72 [ V_61 ] ;
V_3 = F_3 ( V_2 , V_87 -> type , V_87 -> V_18 , V_87 -> V_19 ) ;
F_26 ( V_2 , V_86 , V_88 , V_3 ) ;
}
static T_5 void F_27 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_89 * V_87 )
{
int V_61 ;
T_6 V_88 ;
unsigned char V_3 ;
F_28 ( V_88 . V_90 , V_91 ) ;
for ( V_61 = 0 ; V_61 < V_87 -> V_92 ; V_61 ++ )
if ( V_87 -> V_93 [ V_61 ] )
F_29 ( V_87 -> V_93 [ V_61 ] , V_88 . V_90 ) ;
V_3 = F_30 ( V_87 -> V_4 , V_87 -> V_5 , V_87 -> V_94 ) ;
F_31 ( V_2 , V_86 , & V_88 , V_3 ) ;
}
static T_5 void F_32 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_95 * V_87 )
{
int V_61 ;
T_6 V_88 ;
unsigned char V_3 ;
F_28 ( V_88 . V_90 , V_91 ) ;
for ( V_61 = 0 ; V_61 < V_87 -> V_92 ; V_61 ++ ) {
if ( V_87 -> V_93 [ V_61 ] ) {
if ( V_87 -> V_93 [ V_61 ] < V_91 )
F_29 ( V_87 -> V_93 [ V_61 ] , V_88 . V_90 ) ;
else
F_2 ( & V_2 -> V_2 , L_12
L_13 ,
V_87 -> V_93 [ V_61 ] , V_91 ) ;
}
}
V_3 = F_30 ( V_87 -> V_4 , V_87 -> V_5 , V_87 -> V_94 ) ;
F_31 ( V_2 , V_86 , & V_88 , V_3 ) ;
}
static T_5 void F_33 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_96 * V_97 )
{
unsigned char V_3 = 0 ;
if ( V_97 -> V_98 == V_99 )
V_3 = V_100 ;
F_34 ( V_2 , V_86 , V_97 -> V_101 , V_97 -> V_102 ,
V_97 -> V_103 , V_97 -> V_104 , V_3 ) ;
}
static T_5 void F_35 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_105 * V_97 )
{
F_34 ( V_2 , V_86 , V_97 -> V_106 , V_97 -> V_106 ,
0 , V_97 -> V_104 , V_107 ) ;
}
static T_5 void F_36 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_108 * V_87 )
{
unsigned char V_3 = 0 ;
if ( V_87 -> V_109 == V_110 )
V_3 = V_111 ;
F_37 ( V_2 , V_86 , V_87 -> V_101 , V_87 -> V_102 ,
V_87 -> V_103 , V_87 -> V_104 , V_3 ) ;
}
static T_5 void F_38 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_112 * V_87 )
{
unsigned char V_3 = 0 ;
if ( V_87 -> V_109 == V_110 )
V_3 = V_111 ;
F_37 ( V_2 , V_86 , V_87 -> V_101 , V_87 -> V_102 ,
V_87 -> V_103 , V_87 -> V_104 , V_3 ) ;
}
static T_5 void F_39 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_113 * V_87 )
{
unsigned char V_3 = 0 ;
if ( V_87 -> V_109 == V_110 )
V_3 = V_111 ;
F_37 ( V_2 , V_86 , V_87 -> V_106 , V_87 -> V_106 ,
0 , V_87 -> V_104 , V_3 ) ;
}
static T_5 void F_40 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_54 * V_36 )
{
struct V_114 V_115 , * V_87 = & V_115 ;
T_3 V_82 ;
unsigned char V_3 = 0 ;
V_82 = F_41 ( V_36 , V_87 ) ;
if ( F_24 ( V_82 ) ) {
F_15 ( & V_2 -> V_2 , L_14 ,
V_36 -> type ) ;
return;
}
if ( V_87 -> V_116 == V_117 ) {
if ( V_87 -> V_118 . V_119 . V_109 == V_110 )
V_3 = V_111 ;
F_37 ( V_2 , V_86 , V_87 -> V_106 . V_101 ,
V_87 -> V_106 . V_101 , 0 , V_87 -> V_106 . V_104 ,
V_3 ) ;
} else if ( V_87 -> V_116 == V_120 )
F_34 ( V_2 , V_86 , V_87 -> V_106 . V_101 ,
V_87 -> V_106 . V_101 , 0 , V_87 -> V_106 . V_104 ,
V_107 ) ;
}
static T_5 void F_42 ( struct V_1 * V_2 ,
unsigned int V_86 ,
struct V_54 * V_36 )
{
struct V_121 * V_87 = & V_36 -> V_50 . V_122 ;
unsigned char V_3 = 0 ;
if ( V_87 -> V_116 == V_117 ) {
if ( V_87 -> V_118 . V_119 . V_109 == V_110 )
V_3 = V_111 ;
F_37 ( V_2 , V_86 , V_87 -> V_106 . V_101 ,
V_87 -> V_106 . V_101 , 0 , V_87 -> V_106 . V_104 ,
V_3 ) ;
} else if ( V_87 -> V_116 == V_120 )
F_34 ( V_2 , V_86 , V_87 -> V_106 . V_101 ,
V_87 -> V_106 . V_101 , 0 , V_87 -> V_106 . V_104 ,
V_107 ) ;
}
static T_5 T_3 F_43 ( struct V_54 * V_55 ,
void * V_50 )
{
int V_123 ;
struct V_124 * V_125 = V_50 ;
struct V_1 * V_2 = V_125 -> V_2 ;
unsigned int V_86 = V_125 -> V_86 ;
switch ( V_55 -> type ) {
case V_126 :
F_27 ( V_2 , V_86 , & V_55 -> V_50 . V_127 ) ;
break;
case V_70 :
F_25 ( V_2 , V_86 , & V_55 -> V_50 . V_57 ) ;
break;
case V_73 :
switch ( V_55 -> V_50 . V_128 . V_129 ) {
case V_130 :
V_123 = V_131 ;
break;
case V_132 :
V_123 = V_133 ;
break;
case V_134 :
V_123 = V_135 ;
break;
default:
V_123 = V_136 ;
break;
}
V_125 -> V_86 = F_44 ( V_2 , V_123 ) ;
break;
case V_74 :
V_125 -> V_86 = 0 ;
break;
case V_68 :
F_33 ( V_2 , V_86 , & V_55 -> V_50 . V_97 ) ;
break;
case V_69 :
F_35 ( V_2 , V_86 ,
& V_55 -> V_50 . V_137 ) ;
break;
case V_75 :
case V_76 :
break;
case V_65 :
F_36 ( V_2 , V_86 ,
& V_55 -> V_50 . V_138 ) ;
break;
case V_66 :
F_38 ( V_2 , V_86 ,
& V_55 -> V_50 . V_139 ) ;
break;
case V_67 :
F_39 ( V_2 , V_86 ,
& V_55 -> V_50 . V_140 ) ;
break;
case V_141 :
case V_142 :
case V_143 :
F_40 ( V_2 , V_86 , V_55 ) ;
break;
case V_144 :
F_42 ( V_2 , V_86 , V_55 ) ;
break;
case V_145 :
F_32 ( V_2 , V_86 ,
& V_55 -> V_50 . V_146 ) ;
break;
case V_77 :
break;
default:
F_15 ( & V_2 -> V_2 , L_15 ,
V_55 -> type ) ;
return V_78 ;
}
return V_62 ;
}
int T_5 F_45 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_50 ;
T_4 V_81 = V_80 -> V_81 ;
T_3 V_82 ;
struct V_124 V_125 ;
F_21 ( & V_2 -> V_2 , L_16 ) ;
V_125 . V_2 = V_2 ;
V_125 . V_86 = 0 ;
V_82 = F_23 ( V_81 , V_147 ,
F_43 , & V_125 ) ;
if ( F_24 ( V_82 ) ) {
if ( V_82 != V_84 )
F_2 ( & V_2 -> V_2 , L_17 , V_82 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_46 ( struct V_54 * V_55 )
{
switch ( V_55 -> type ) {
case V_126 :
case V_70 :
case V_68 :
case V_69 :
case V_65 :
case V_66 :
case V_67 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
return 1 ;
}
return 0 ;
}
static T_3 F_47 ( struct V_54 * V_55 ,
void * V_50 )
{
int * V_148 = V_50 ;
if ( F_46 ( V_55 ) )
( * V_148 ) ++ ;
return V_62 ;
}
static T_3 F_48 ( struct V_54 * V_55 , void * V_50 )
{
struct V_54 * * V_35 = V_50 ;
if ( F_46 ( V_55 ) ) {
( * V_35 ) -> type = V_55 -> type ;
( * V_35 ) -> V_52 = sizeof( struct V_54 ) ;
if ( V_55 -> type == V_126 )
( * V_35 ) -> V_50 . V_127 . V_149 =
V_55 -> V_50 . V_127 . V_149 ;
( * V_35 ) ++ ;
}
return V_62 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_79 * V_80 = V_2 -> V_50 ;
T_4 V_81 = V_80 -> V_81 ;
struct V_54 * V_35 ;
int V_148 = 0 ;
T_3 V_82 ;
V_82 = F_23 ( V_81 , V_83 ,
F_47 , & V_148 ) ;
if ( F_24 ( V_82 ) ) {
F_2 ( & V_2 -> V_2 , L_18 , V_82 ) ;
return - V_152 ;
}
if ( ! V_148 )
return - V_152 ;
V_151 -> V_52 = sizeof( struct V_54 ) * ( V_148 + 1 ) + 1 ;
V_151 -> V_153 = F_50 ( V_151 -> V_52 - 1 , V_154 ) ;
if ( ! V_151 -> V_153 )
return - V_155 ;
V_35 = (struct V_54 * ) V_151 -> V_153 ;
V_82 = F_23 ( V_81 , V_83 ,
F_48 , & V_35 ) ;
if ( F_24 ( V_82 ) ) {
F_51 ( V_151 -> V_153 ) ;
F_2 ( & V_2 -> V_2 , L_18 , V_82 ) ;
return - V_152 ;
}
V_35 -> type = V_76 ;
V_35 -> V_52 = sizeof( struct V_54 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_89 * V_127 = & V_35 -> V_50 . V_127 ;
int V_4 , V_5 , V_6 ;
if ( ! F_53 ( V_87 ) ) {
V_127 -> V_92 = 0 ;
F_21 ( & V_2 -> V_2 , L_19 ,
V_87 ? L_20 : L_21 ) ;
return;
}
F_1 ( V_2 , V_87 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_127 -> V_4 = V_4 ;
V_127 -> V_5 = V_5 ;
V_127 -> V_94 = V_6 ;
V_127 -> V_92 = 1 ;
V_127 -> V_93 [ 0 ] = V_87 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_22 ,
( int ) V_87 -> V_38 ,
V_4 == V_11 ? L_23 : L_24 ,
V_5 == V_12 ? L_25 : L_26 ,
V_127 -> V_94 == V_16 ? L_27 : L_28 ,
V_127 -> V_149 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_95 * V_146 = & V_35 -> V_50 . V_146 ;
int V_4 , V_5 , V_6 ;
if ( ! F_53 ( V_87 ) ) {
V_146 -> V_92 = 0 ;
F_21 ( & V_2 -> V_2 , L_29 ,
V_87 ? L_20 : L_21 ) ;
return;
}
F_1 ( V_2 , V_87 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_146 -> V_156 = V_157 ;
V_146 -> V_4 = V_4 ;
V_146 -> V_5 = V_5 ;
V_146 -> V_94 = V_6 ;
V_146 -> V_92 = 1 ;
V_146 -> V_93 [ 0 ] = V_87 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_30 , ( int ) V_87 -> V_38 ,
V_4 == V_11 ? L_23 : L_24 ,
V_5 == V_12 ? L_25 : L_26 ,
V_146 -> V_94 == V_16 ? L_27 : L_28 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_56 * V_57 = & V_35 -> V_50 . V_57 ;
if ( ! F_53 ( V_87 ) ) {
V_57 -> V_71 = 0 ;
F_21 ( & V_2 -> V_2 , L_31 ,
V_87 ? L_20 : L_21 ) ;
return;
}
switch ( V_87 -> V_3 & V_158 ) {
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
switch ( V_87 -> V_3 & V_159 ) {
case V_30 :
V_57 -> V_19 = V_29 ;
break;
case V_32 :
V_57 -> V_19 = V_31 ;
break;
default:
V_57 -> V_19 = V_33 ;
}
V_57 -> V_18 = ! ! ( V_87 -> V_3 & V_20 ) ;
V_57 -> V_71 = 1 ;
V_57 -> V_72 [ 0 ] = V_87 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_32
L_33 ,
( int ) V_87 -> V_38 , V_57 -> type , V_57 -> V_19 , V_57 -> V_18 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_96 * V_97 = & V_35 -> V_50 . V_97 ;
if ( F_53 ( V_87 ) ) {
V_97 -> V_98 = ( V_87 -> V_3 & V_100 ) ?
V_99 : V_160 ;
V_97 -> V_101 = V_87 -> V_38 ;
V_97 -> V_102 = V_87 -> V_161 ;
V_97 -> V_103 = 0 ;
V_97 -> V_104 = F_57 ( V_87 ) ;
} else {
V_97 -> V_101 = 0 ;
V_97 -> V_104 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_34 , V_97 -> V_101 ,
V_97 -> V_101 + V_97 -> V_104 - 1 , V_97 -> V_98 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_105 * V_137 = & V_35 -> V_50 . V_137 ;
if ( F_53 ( V_87 ) ) {
V_137 -> V_106 = V_87 -> V_38 ;
V_137 -> V_104 = F_57 ( V_87 ) ;
} else {
V_137 -> V_106 = 0 ;
V_137 -> V_104 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_35 , V_137 -> V_106 ,
V_137 -> V_106 + V_137 -> V_104 - 1 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_108 * V_138 = & V_35 -> V_50 . V_138 ;
if ( F_53 ( V_87 ) ) {
V_138 -> V_109 = V_87 -> V_3 & V_111 ?
V_110 : V_162 ;
V_138 -> V_101 = V_87 -> V_38 ;
V_138 -> V_102 = V_87 -> V_161 ;
V_138 -> V_103 = 0 ;
V_138 -> V_104 = F_57 ( V_87 ) ;
} else {
V_138 -> V_101 = 0 ;
V_138 -> V_104 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_36 ,
V_138 -> V_101 ,
V_138 -> V_101 + V_138 -> V_104 - 1 ,
V_138 -> V_109 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_112 * V_139 = & V_35 -> V_50 . V_139 ;
if ( F_53 ( V_87 ) ) {
V_139 -> V_109 = V_87 -> V_3 & V_111 ?
V_110 : V_162 ;
V_139 -> V_101 = V_87 -> V_38 ;
V_139 -> V_102 = V_87 -> V_161 ;
V_139 -> V_103 = 0 ;
V_139 -> V_104 = F_57 ( V_87 ) ;
} else {
V_139 -> V_101 = 0 ;
V_139 -> V_103 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_37 ,
V_139 -> V_101 ,
V_139 -> V_101 + V_139 -> V_104 - 1 ,
V_139 -> V_109 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_87 )
{
struct V_113 * V_140 = & V_35 -> V_50 . V_140 ;
if ( F_53 ( V_87 ) ) {
V_140 -> V_109 =
V_87 -> V_3 & V_111 ?
V_110 : V_162 ;
V_140 -> V_106 = V_87 -> V_38 ;
V_140 -> V_104 = F_57 ( V_87 ) ;
} else {
V_140 -> V_106 = 0 ;
V_140 -> V_104 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_38 ,
V_140 -> V_106 ,
V_140 -> V_106 + V_140 -> V_104 - 1 ,
V_140 -> V_109 ) ;
}
int F_62 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
int V_61 = 0 ;
int V_148 = ( V_151 -> V_52 - 1 ) / sizeof( struct V_54 ) - 1 ;
struct V_54 * V_35 = V_151 -> V_153 ;
int V_163 = 0 , V_127 = 0 , V_57 = 0 , V_119 = 0 ;
F_21 ( & V_2 -> V_2 , L_39 , V_148 ) ;
while ( V_61 < V_148 ) {
switch ( V_35 -> type ) {
case V_126 :
F_52 ( V_2 , V_35 ,
F_63 ( V_2 , V_164 , V_127 ) ) ;
V_127 ++ ;
break;
case V_70 :
F_55 ( V_2 , V_35 ,
F_63 ( V_2 , V_165 , V_57 ) ) ;
V_57 ++ ;
break;
case V_68 :
F_56 ( V_2 , V_35 ,
F_63 ( V_2 , V_166 , V_163 ) ) ;
V_163 ++ ;
break;
case V_69 :
F_58 ( V_2 , V_35 ,
F_63 ( V_2 , V_166 , V_163 ) ) ;
V_163 ++ ;
break;
case V_65 :
F_59 ( V_2 , V_35 ,
F_63 ( V_2 , V_167 , V_119 ) ) ;
V_119 ++ ;
break;
case V_66 :
F_60 ( V_2 , V_35 ,
F_63 ( V_2 , V_167 , V_119 ) ) ;
V_119 ++ ;
break;
case V_67 :
F_61 ( V_2 , V_35 ,
F_63 ( V_2 , V_167 , V_119 ) ) ;
V_119 ++ ;
break;
case V_145 :
F_54 ( V_2 , V_35 ,
F_63 ( V_2 , V_164 , V_127 ) ) ;
V_127 ++ ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_77 :
default:
F_15 ( & V_2 -> V_2 , L_40
L_41 , V_35 -> type ) ;
return - V_152 ;
}
V_35 ++ ;
V_61 ++ ;
}
return 0 ;
}
