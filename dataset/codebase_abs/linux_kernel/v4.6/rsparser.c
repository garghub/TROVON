static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 ,
T_1 * V_5 , T_1 * V_6 )
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
case V_78 :
break;
default:
F_15 ( & V_2 -> V_2 , L_9 ,
V_55 -> type ) ;
return V_79 ;
}
return V_62 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = V_2 -> V_50 ;
T_4 V_82 = V_81 -> V_82 ;
T_3 V_83 ;
F_21 ( & V_2 -> V_2 , L_10 ) ;
F_22 ( V_2 ) ;
V_83 = F_23 ( V_82 , V_84 ,
F_10 , V_2 ) ;
if ( F_24 ( V_83 ) ) {
if ( V_83 != V_85 )
F_2 ( & V_2 -> V_2 , L_11 , V_83 ) ;
return - V_86 ;
}
return 0 ;
}
static T_5 void F_25 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_56 * V_88 )
{
int V_61 ;
unsigned char V_89 = 0 , V_3 ;
for ( V_61 = 0 ; V_61 < V_88 -> V_71 ; V_61 ++ )
V_89 |= 1 << V_88 -> V_72 [ V_61 ] ;
V_3 = F_3 ( V_2 , V_88 -> type , V_88 -> V_18 , V_88 -> V_19 ) ;
F_26 ( V_2 , V_87 , V_89 , V_3 ) ;
}
static T_5 void F_27 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_90 * V_88 )
{
int V_61 ;
T_6 V_89 ;
unsigned char V_3 ;
F_28 ( V_89 . V_91 , V_92 ) ;
for ( V_61 = 0 ; V_61 < V_88 -> V_93 ; V_61 ++ )
if ( V_88 -> V_94 [ V_61 ] )
F_29 ( V_88 -> V_94 [ V_61 ] , V_89 . V_91 ) ;
V_3 = F_30 ( V_88 -> V_4 , V_88 -> V_5 , V_88 -> V_95 ) ;
F_31 ( V_2 , V_87 , & V_89 , V_3 ) ;
}
static T_5 void F_32 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_96 * V_88 )
{
int V_61 ;
T_6 V_89 ;
unsigned char V_3 ;
F_28 ( V_89 . V_91 , V_92 ) ;
for ( V_61 = 0 ; V_61 < V_88 -> V_93 ; V_61 ++ ) {
if ( V_88 -> V_94 [ V_61 ] ) {
if ( V_88 -> V_94 [ V_61 ] < V_92 )
F_29 ( V_88 -> V_94 [ V_61 ] , V_89 . V_91 ) ;
else
F_2 ( & V_2 -> V_2 , L_12
L_13 ,
V_88 -> V_94 [ V_61 ] , V_92 ) ;
}
}
V_3 = F_30 ( V_88 -> V_4 , V_88 -> V_5 , V_88 -> V_95 ) ;
F_31 ( V_2 , V_87 , & V_89 , V_3 ) ;
}
static T_5 void F_33 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_97 * V_98 )
{
unsigned char V_3 = 0 ;
if ( V_98 -> V_99 == V_100 )
V_3 = V_101 ;
F_34 ( V_2 , V_87 , V_98 -> V_102 , V_98 -> V_103 ,
V_98 -> V_104 , V_98 -> V_105 , V_3 ) ;
}
static T_5 void F_35 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_106 * V_98 )
{
F_34 ( V_2 , V_87 , V_98 -> V_107 , V_98 -> V_107 ,
0 , V_98 -> V_105 , V_108 ) ;
}
static T_5 void F_36 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_109 * V_88 )
{
unsigned char V_3 = 0 ;
if ( V_88 -> V_110 == V_111 )
V_3 = V_112 ;
F_37 ( V_2 , V_87 , V_88 -> V_102 , V_88 -> V_103 ,
V_88 -> V_104 , V_88 -> V_105 , V_3 ) ;
}
static T_5 void F_38 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_113 * V_88 )
{
unsigned char V_3 = 0 ;
if ( V_88 -> V_110 == V_111 )
V_3 = V_112 ;
F_37 ( V_2 , V_87 , V_88 -> V_102 , V_88 -> V_103 ,
V_88 -> V_104 , V_88 -> V_105 , V_3 ) ;
}
static T_5 void F_39 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_114 * V_88 )
{
unsigned char V_3 = 0 ;
if ( V_88 -> V_110 == V_111 )
V_3 = V_112 ;
F_37 ( V_2 , V_87 , V_88 -> V_107 , V_88 -> V_107 ,
0 , V_88 -> V_105 , V_3 ) ;
}
static T_5 void F_40 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_54 * V_36 )
{
struct V_115 V_116 , * V_88 = & V_116 ;
T_3 V_83 ;
unsigned char V_3 = 0 ;
V_83 = F_41 ( V_36 , V_88 ) ;
if ( F_24 ( V_83 ) ) {
F_15 ( & V_2 -> V_2 , L_14 ,
V_36 -> type ) ;
return;
}
if ( V_88 -> V_117 == V_118 ) {
if ( V_88 -> V_119 . V_120 . V_110 == V_111 )
V_3 = V_112 ;
F_37 ( V_2 , V_87 , V_88 -> V_107 . V_102 ,
V_88 -> V_107 . V_102 , 0 , V_88 -> V_107 . V_105 ,
V_3 ) ;
} else if ( V_88 -> V_117 == V_121 )
F_34 ( V_2 , V_87 , V_88 -> V_107 . V_102 ,
V_88 -> V_107 . V_102 , 0 , V_88 -> V_107 . V_105 ,
V_108 ) ;
}
static T_5 void F_42 ( struct V_1 * V_2 ,
unsigned int V_87 ,
struct V_54 * V_36 )
{
struct V_122 * V_88 = & V_36 -> V_50 . V_123 ;
unsigned char V_3 = 0 ;
if ( V_88 -> V_117 == V_118 ) {
if ( V_88 -> V_119 . V_120 . V_110 == V_111 )
V_3 = V_112 ;
F_37 ( V_2 , V_87 , V_88 -> V_107 . V_102 ,
V_88 -> V_107 . V_102 , 0 , V_88 -> V_107 . V_105 ,
V_3 ) ;
} else if ( V_88 -> V_117 == V_121 )
F_34 ( V_2 , V_87 , V_88 -> V_107 . V_102 ,
V_88 -> V_107 . V_102 , 0 , V_88 -> V_107 . V_105 ,
V_108 ) ;
}
static T_5 T_3 F_43 ( struct V_54 * V_55 ,
void * V_50 )
{
int V_124 ;
struct V_125 * V_126 = V_50 ;
struct V_1 * V_2 = V_126 -> V_2 ;
unsigned int V_87 = V_126 -> V_87 ;
switch ( V_55 -> type ) {
case V_127 :
F_27 ( V_2 , V_87 , & V_55 -> V_50 . V_128 ) ;
break;
case V_70 :
F_25 ( V_2 , V_87 , & V_55 -> V_50 . V_57 ) ;
break;
case V_73 :
switch ( V_55 -> V_50 . V_129 . V_130 ) {
case V_131 :
V_124 = V_132 ;
break;
case V_133 :
V_124 = V_134 ;
break;
case V_135 :
V_124 = V_136 ;
break;
default:
V_124 = V_137 ;
break;
}
V_126 -> V_87 = F_44 ( V_2 , V_124 ) ;
break;
case V_74 :
V_126 -> V_87 = 0 ;
break;
case V_68 :
F_33 ( V_2 , V_87 , & V_55 -> V_50 . V_98 ) ;
break;
case V_69 :
F_35 ( V_2 , V_87 ,
& V_55 -> V_50 . V_138 ) ;
break;
case V_75 :
case V_76 :
break;
case V_65 :
F_36 ( V_2 , V_87 ,
& V_55 -> V_50 . V_139 ) ;
break;
case V_66 :
F_38 ( V_2 , V_87 ,
& V_55 -> V_50 . V_140 ) ;
break;
case V_67 :
F_39 ( V_2 , V_87 ,
& V_55 -> V_50 . V_141 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
F_40 ( V_2 , V_87 , V_55 ) ;
break;
case V_145 :
F_42 ( V_2 , V_87 , V_55 ) ;
break;
case V_146 :
F_32 ( V_2 , V_87 ,
& V_55 -> V_50 . V_147 ) ;
break;
case V_77 :
break;
default:
F_15 ( & V_2 -> V_2 , L_15 ,
V_55 -> type ) ;
return V_79 ;
}
return V_62 ;
}
int T_5 F_45 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = V_2 -> V_50 ;
T_4 V_82 = V_81 -> V_82 ;
T_3 V_83 ;
struct V_125 V_126 ;
F_21 ( & V_2 -> V_2 , L_16 ) ;
V_126 . V_2 = V_2 ;
V_126 . V_87 = 0 ;
V_83 = F_23 ( V_82 , V_148 ,
F_43 , & V_126 ) ;
if ( F_24 ( V_83 ) ) {
if ( V_83 != V_85 )
F_2 ( & V_2 -> V_2 , L_17 , V_83 ) ;
return - V_86 ;
}
return 0 ;
}
static int F_46 ( struct V_54 * V_55 )
{
switch ( V_55 -> type ) {
case V_127 :
case V_70 :
case V_68 :
case V_69 :
case V_65 :
case V_66 :
case V_67 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
return 1 ;
}
return 0 ;
}
static T_3 F_47 ( struct V_54 * V_55 ,
void * V_50 )
{
int * V_149 = V_50 ;
if ( F_46 ( V_55 ) )
( * V_149 ) ++ ;
return V_62 ;
}
static T_3 F_48 ( struct V_54 * V_55 , void * V_50 )
{
struct V_54 * * V_35 = V_50 ;
if ( F_46 ( V_55 ) ) {
( * V_35 ) -> type = V_55 -> type ;
( * V_35 ) -> V_52 = sizeof( struct V_54 ) ;
if ( V_55 -> type == V_127 )
( * V_35 ) -> V_50 . V_128 . V_150 =
V_55 -> V_50 . V_128 . V_150 ;
( * V_35 ) ++ ;
}
return V_62 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_151 * V_152 )
{
struct V_80 * V_81 = V_2 -> V_50 ;
T_4 V_82 = V_81 -> V_82 ;
struct V_54 * V_35 ;
int V_149 = 0 ;
T_3 V_83 ;
V_83 = F_23 ( V_82 , V_84 ,
F_47 , & V_149 ) ;
if ( F_24 ( V_83 ) ) {
F_2 ( & V_2 -> V_2 , L_18 , V_83 ) ;
return - V_153 ;
}
if ( ! V_149 )
return - V_153 ;
V_152 -> V_52 = sizeof( struct V_54 ) * ( V_149 + 1 ) + 1 ;
V_152 -> V_154 = F_50 ( V_152 -> V_52 - 1 , V_155 ) ;
if ( ! V_152 -> V_154 )
return - V_156 ;
V_35 = (struct V_54 * ) V_152 -> V_154 ;
V_83 = F_23 ( V_82 , V_84 ,
F_48 , & V_35 ) ;
if ( F_24 ( V_83 ) ) {
F_51 ( V_152 -> V_154 ) ;
F_2 ( & V_2 -> V_2 , L_18 , V_83 ) ;
return - V_153 ;
}
V_35 -> type = V_76 ;
V_35 -> V_52 = sizeof( struct V_54 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_90 * V_128 = & V_35 -> V_50 . V_128 ;
T_1 V_4 , V_5 , V_6 ;
if ( ! F_53 ( V_88 ) ) {
V_128 -> V_93 = 0 ;
F_21 ( & V_2 -> V_2 , L_19 ,
V_88 ? L_20 : L_21 ) ;
return;
}
F_1 ( V_2 , V_88 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_128 -> V_4 = V_4 ;
V_128 -> V_5 = V_5 ;
V_128 -> V_95 = V_6 ;
V_128 -> V_93 = 1 ;
V_128 -> V_94 [ 0 ] = V_88 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_22 ,
( int ) V_88 -> V_38 ,
V_4 == V_11 ? L_23 : L_24 ,
V_5 == V_12 ? L_25 : L_26 ,
V_128 -> V_95 == V_16 ? L_27 : L_28 ,
V_128 -> V_150 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_96 * V_147 = & V_35 -> V_50 . V_147 ;
T_1 V_4 , V_5 , V_6 ;
if ( ! F_53 ( V_88 ) ) {
V_147 -> V_93 = 0 ;
F_21 ( & V_2 -> V_2 , L_29 ,
V_88 ? L_20 : L_21 ) ;
return;
}
F_1 ( V_2 , V_88 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_147 -> V_157 = V_158 ;
V_147 -> V_4 = V_4 ;
V_147 -> V_5 = V_5 ;
V_147 -> V_95 = V_6 ;
V_147 -> V_93 = 1 ;
V_147 -> V_94 [ 0 ] = V_88 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_30 , ( int ) V_88 -> V_38 ,
V_4 == V_11 ? L_23 : L_24 ,
V_5 == V_12 ? L_25 : L_26 ,
V_147 -> V_95 == V_16 ? L_27 : L_28 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_56 * V_57 = & V_35 -> V_50 . V_57 ;
if ( ! F_53 ( V_88 ) ) {
V_57 -> V_71 = 0 ;
F_21 ( & V_2 -> V_2 , L_31 ,
V_88 ? L_20 : L_21 ) ;
return;
}
switch ( V_88 -> V_3 & V_159 ) {
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
switch ( V_88 -> V_3 & V_160 ) {
case V_30 :
V_57 -> V_19 = V_29 ;
break;
case V_32 :
V_57 -> V_19 = V_31 ;
break;
default:
V_57 -> V_19 = V_33 ;
}
V_57 -> V_18 = ! ! ( V_88 -> V_3 & V_20 ) ;
V_57 -> V_71 = 1 ;
V_57 -> V_72 [ 0 ] = V_88 -> V_38 ;
F_21 ( & V_2 -> V_2 , L_32
L_33 ,
( int ) V_88 -> V_38 , V_57 -> type , V_57 -> V_19 , V_57 -> V_18 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_97 * V_98 = & V_35 -> V_50 . V_98 ;
if ( F_53 ( V_88 ) ) {
V_98 -> V_99 = ( V_88 -> V_3 & V_101 ) ?
V_100 : V_161 ;
V_98 -> V_102 = V_88 -> V_38 ;
V_98 -> V_103 = V_88 -> V_162 ;
V_98 -> V_104 = 0 ;
V_98 -> V_105 = F_57 ( V_88 ) ;
} else {
V_98 -> V_102 = 0 ;
V_98 -> V_105 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_34 , V_98 -> V_102 ,
V_98 -> V_102 + V_98 -> V_105 - 1 , V_98 -> V_99 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_106 * V_138 = & V_35 -> V_50 . V_138 ;
if ( F_53 ( V_88 ) ) {
V_138 -> V_107 = V_88 -> V_38 ;
V_138 -> V_105 = F_57 ( V_88 ) ;
} else {
V_138 -> V_107 = 0 ;
V_138 -> V_105 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_35 , V_138 -> V_107 ,
V_138 -> V_107 + V_138 -> V_105 - 1 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_109 * V_139 = & V_35 -> V_50 . V_139 ;
if ( F_53 ( V_88 ) ) {
V_139 -> V_110 = V_88 -> V_3 & V_112 ?
V_111 : V_163 ;
V_139 -> V_102 = V_88 -> V_38 ;
V_139 -> V_103 = V_88 -> V_162 ;
V_139 -> V_104 = 0 ;
V_139 -> V_105 = F_57 ( V_88 ) ;
} else {
V_139 -> V_102 = 0 ;
V_139 -> V_105 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_36 ,
V_139 -> V_102 ,
V_139 -> V_102 + V_139 -> V_105 - 1 ,
V_139 -> V_110 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_113 * V_140 = & V_35 -> V_50 . V_140 ;
if ( F_53 ( V_88 ) ) {
V_140 -> V_110 = V_88 -> V_3 & V_112 ?
V_111 : V_163 ;
V_140 -> V_102 = V_88 -> V_38 ;
V_140 -> V_103 = V_88 -> V_162 ;
V_140 -> V_104 = 0 ;
V_140 -> V_105 = F_57 ( V_88 ) ;
} else {
V_140 -> V_102 = 0 ;
V_140 -> V_104 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_37 ,
V_140 -> V_102 ,
V_140 -> V_102 + V_140 -> V_105 - 1 ,
V_140 -> V_110 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_88 )
{
struct V_114 * V_141 = & V_35 -> V_50 . V_141 ;
if ( F_53 ( V_88 ) ) {
V_141 -> V_110 =
V_88 -> V_3 & V_112 ?
V_111 : V_163 ;
V_141 -> V_107 = V_88 -> V_38 ;
V_141 -> V_105 = F_57 ( V_88 ) ;
} else {
V_141 -> V_107 = 0 ;
V_141 -> V_105 = 0 ;
}
F_21 ( & V_2 -> V_2 , L_38 ,
V_141 -> V_107 ,
V_141 -> V_107 + V_141 -> V_105 - 1 ,
V_141 -> V_110 ) ;
}
int F_62 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
int V_61 = 0 ;
int V_149 = ( V_152 -> V_52 - 1 ) / sizeof( struct V_54 ) - 1 ;
struct V_54 * V_35 = V_152 -> V_154 ;
unsigned int V_164 = 0 , V_128 = 0 , V_57 = 0 , V_120 = 0 ;
F_21 ( & V_2 -> V_2 , L_39 , V_149 ) ;
while ( V_61 < V_149 ) {
switch ( V_35 -> type ) {
case V_127 :
F_52 ( V_2 , V_35 ,
F_63 ( V_2 , V_165 , V_128 ) ) ;
V_128 ++ ;
break;
case V_70 :
F_55 ( V_2 , V_35 ,
F_63 ( V_2 , V_166 , V_57 ) ) ;
V_57 ++ ;
break;
case V_68 :
F_56 ( V_2 , V_35 ,
F_63 ( V_2 , V_167 , V_164 ) ) ;
V_164 ++ ;
break;
case V_69 :
F_58 ( V_2 , V_35 ,
F_63 ( V_2 , V_167 , V_164 ) ) ;
V_164 ++ ;
break;
case V_65 :
F_59 ( V_2 , V_35 ,
F_63 ( V_2 , V_168 , V_120 ) ) ;
V_120 ++ ;
break;
case V_66 :
F_60 ( V_2 , V_35 ,
F_63 ( V_2 , V_168 , V_120 ) ) ;
V_120 ++ ;
break;
case V_67 :
F_61 ( V_2 , V_35 ,
F_63 ( V_2 , V_168 , V_120 ) ) ;
V_120 ++ ;
break;
case V_146 :
F_54 ( V_2 , V_35 ,
F_63 ( V_2 , V_165 , V_128 ) ) ;
V_128 ++ ;
break;
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_77 :
default:
F_15 ( & V_2 -> V_2 , L_40
L_41 , V_35 -> type ) ;
return - V_153 ;
}
V_35 ++ ;
V_61 ++ ;
}
return 0 ;
}
