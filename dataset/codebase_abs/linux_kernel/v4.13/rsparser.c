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
F_2 ( & V_2 -> V_2 ,
L_4 ,
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
struct V_59 * V_60 ;
struct V_61 V_62 = { { 0 } , 0 } ;
struct V_35 * V_36 = & V_62 . V_55 ;
int V_63 , V_3 ;
if ( F_11 ( V_55 , & V_62 )
|| F_12 ( V_55 , & V_62 ) ) {
F_6 ( V_2 , & V_62 . V_55 ) ;
return V_64 ;
}
V_36 -> V_3 = 0 ;
if ( F_13 ( V_55 , 0 , V_36 ) ) {
F_4 ( V_2 , V_36 ) ;
for ( V_63 = 1 ; F_13 ( V_55 , V_63 , V_36 ) ; V_63 ++ )
F_4 ( V_2 , V_36 ) ;
if ( V_63 > 1 ) {
if ( F_14 ( V_2 ) ) {
F_15 ( & V_2 -> V_2 ,
L_5 ) ;
V_2 -> V_65 &= ~ V_66 ;
}
}
return V_64 ;
} else if ( F_16 ( V_55 , & V_60 ) ) {
V_63 = F_17 ( V_2 -> V_50 , 0 ) ;
if ( V_63 >= 0 ) {
V_3 = F_18 ( V_60 -> V_4 ,
V_60 -> V_5 ,
V_60 -> V_67 ) ;
} else {
V_3 = V_37 ;
}
F_19 ( V_2 , V_63 , V_3 ) ;
return V_64 ;
} else if ( V_36 -> V_3 & V_37 ) {
F_19 ( V_2 , 0 , V_37 ) ;
return V_64 ;
}
switch ( V_55 -> type ) {
case V_68 :
case V_69 :
case V_70 :
if ( F_20 ( V_55 , V_36 ) )
F_6 ( V_2 , V_36 ) ;
break;
case V_71 :
case V_72 :
if ( F_21 ( V_55 , V_36 ) )
F_6 ( V_2 , V_36 ) ;
break;
case V_73 :
V_57 = & V_55 -> V_50 . V_57 ;
if ( V_57 -> V_74 > 0 && V_57 -> V_75 [ 0 ] != ( T_1 ) - 1 )
V_3 = F_3 ( V_2 , V_57 -> type , V_57 -> V_18 ,
V_57 -> V_19 ) ;
else
V_3 = V_37 ;
F_22 ( V_2 , V_57 -> V_75 [ 0 ] , V_3 ) ;
break;
case V_76 :
case V_77 :
break;
case V_78 :
V_58 = & V_55 -> V_50 . V_58 ;
F_8 ( V_2 , V_58 ) ;
break;
case V_79 :
break;
case V_80 :
break;
case V_81 :
break;
default:
F_15 ( & V_2 -> V_2 , L_6 ,
V_55 -> type ) ;
return V_82 ;
}
return V_64 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_50 ;
T_4 V_85 = V_84 -> V_85 ;
T_3 V_86 ;
F_24 ( & V_2 -> V_2 , L_7 ) ;
F_25 ( V_2 ) ;
V_86 = F_26 ( V_85 , V_87 ,
F_10 , V_2 ) ;
if ( F_27 ( V_86 ) ) {
if ( V_86 != V_88 )
F_2 ( & V_2 -> V_2 , L_8 , V_86 ) ;
return - V_89 ;
}
return 0 ;
}
static T_5 void F_28 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_56 * V_91 )
{
int V_63 ;
unsigned char V_92 = 0 , V_3 ;
for ( V_63 = 0 ; V_63 < V_91 -> V_74 ; V_63 ++ )
V_92 |= 1 << V_91 -> V_75 [ V_63 ] ;
V_3 = F_3 ( V_2 , V_91 -> type , V_91 -> V_18 , V_91 -> V_19 ) ;
F_29 ( V_2 , V_90 , V_92 , V_3 ) ;
}
static T_5 void F_30 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_93 * V_91 )
{
int V_63 ;
T_6 V_92 ;
unsigned char V_3 ;
F_31 ( V_92 . V_94 , V_95 ) ;
for ( V_63 = 0 ; V_63 < V_91 -> V_96 ; V_63 ++ )
if ( V_91 -> V_97 [ V_63 ] )
F_32 ( V_91 -> V_97 [ V_63 ] , V_92 . V_94 ) ;
V_3 = F_18 ( V_91 -> V_4 , V_91 -> V_5 , V_91 -> V_67 ) ;
F_33 ( V_2 , V_90 , & V_92 , V_3 ) ;
}
static T_5 void F_34 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_98 * V_91 )
{
int V_63 ;
T_6 V_92 ;
unsigned char V_3 ;
F_31 ( V_92 . V_94 , V_95 ) ;
for ( V_63 = 0 ; V_63 < V_91 -> V_96 ; V_63 ++ ) {
if ( V_91 -> V_97 [ V_63 ] ) {
if ( V_91 -> V_97 [ V_63 ] < V_95 )
F_32 ( V_91 -> V_97 [ V_63 ] , V_92 . V_94 ) ;
else
F_2 ( & V_2 -> V_2 ,
L_9 ,
V_91 -> V_97 [ V_63 ] , V_95 ) ;
}
}
V_3 = F_18 ( V_91 -> V_4 , V_91 -> V_5 , V_91 -> V_67 ) ;
F_33 ( V_2 , V_90 , & V_92 , V_3 ) ;
}
static T_5 void F_35 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_99 * V_100 )
{
unsigned char V_3 = 0 ;
if ( V_100 -> V_101 == V_102 )
V_3 = V_103 ;
F_36 ( V_2 , V_90 , V_100 -> V_104 , V_100 -> V_105 ,
V_100 -> V_106 , V_100 -> V_107 , V_3 ) ;
}
static T_5 void F_37 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_108 * V_100 )
{
F_36 ( V_2 , V_90 , V_100 -> V_109 , V_100 -> V_109 ,
0 , V_100 -> V_107 , V_110 ) ;
}
static T_5 void F_38 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_111 * V_91 )
{
unsigned char V_3 = 0 ;
if ( V_91 -> V_112 == V_113 )
V_3 = V_114 ;
F_39 ( V_2 , V_90 , V_91 -> V_104 , V_91 -> V_105 ,
V_91 -> V_106 , V_91 -> V_107 , V_3 ) ;
}
static T_5 void F_40 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_115 * V_91 )
{
unsigned char V_3 = 0 ;
if ( V_91 -> V_112 == V_113 )
V_3 = V_114 ;
F_39 ( V_2 , V_90 , V_91 -> V_104 , V_91 -> V_105 ,
V_91 -> V_106 , V_91 -> V_107 , V_3 ) ;
}
static T_5 void F_41 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_116 * V_91 )
{
unsigned char V_3 = 0 ;
if ( V_91 -> V_112 == V_113 )
V_3 = V_114 ;
F_39 ( V_2 , V_90 , V_91 -> V_109 , V_91 -> V_109 ,
0 , V_91 -> V_107 , V_3 ) ;
}
static T_5 void F_42 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_54 * V_36 )
{
struct V_117 V_118 , * V_91 = & V_118 ;
T_3 V_86 ;
unsigned char V_3 = 0 ;
V_86 = F_43 ( V_36 , V_91 ) ;
if ( F_27 ( V_86 ) ) {
F_15 ( & V_2 -> V_2 , L_10 ,
V_36 -> type ) ;
return;
}
if ( V_91 -> V_119 == V_120 ) {
if ( V_91 -> V_121 . V_122 . V_112 == V_113 )
V_3 = V_114 ;
F_39 ( V_2 , V_90 , V_91 -> V_109 . V_104 ,
V_91 -> V_109 . V_104 , 0 , V_91 -> V_109 . V_107 ,
V_3 ) ;
} else if ( V_91 -> V_119 == V_123 )
F_36 ( V_2 , V_90 , V_91 -> V_109 . V_104 ,
V_91 -> V_109 . V_104 , 0 , V_91 -> V_109 . V_107 ,
V_110 ) ;
}
static T_5 void F_44 ( struct V_1 * V_2 ,
unsigned int V_90 ,
struct V_54 * V_36 )
{
struct V_124 * V_91 = & V_36 -> V_50 . V_125 ;
unsigned char V_3 = 0 ;
if ( V_91 -> V_119 == V_120 ) {
if ( V_91 -> V_121 . V_122 . V_112 == V_113 )
V_3 = V_114 ;
F_39 ( V_2 , V_90 , V_91 -> V_109 . V_104 ,
V_91 -> V_109 . V_104 , 0 , V_91 -> V_109 . V_107 ,
V_3 ) ;
} else if ( V_91 -> V_119 == V_123 )
F_36 ( V_2 , V_90 , V_91 -> V_109 . V_104 ,
V_91 -> V_109 . V_104 , 0 , V_91 -> V_109 . V_107 ,
V_110 ) ;
}
static T_5 T_3 F_45 ( struct V_54 * V_55 ,
void * V_50 )
{
int V_126 ;
struct V_127 * V_128 = V_50 ;
struct V_1 * V_2 = V_128 -> V_2 ;
unsigned int V_90 = V_128 -> V_90 ;
switch ( V_55 -> type ) {
case V_129 :
F_30 ( V_2 , V_90 , & V_55 -> V_50 . V_130 ) ;
break;
case V_73 :
F_28 ( V_2 , V_90 , & V_55 -> V_50 . V_57 ) ;
break;
case V_76 :
switch ( V_55 -> V_50 . V_131 . V_132 ) {
case V_133 :
V_126 = V_134 ;
break;
case V_135 :
V_126 = V_136 ;
break;
case V_137 :
V_126 = V_138 ;
break;
default:
V_126 = V_139 ;
break;
}
V_128 -> V_90 = F_46 ( V_2 , V_126 ) ;
break;
case V_77 :
V_128 -> V_90 = 0 ;
break;
case V_71 :
F_35 ( V_2 , V_90 , & V_55 -> V_50 . V_100 ) ;
break;
case V_72 :
F_37 ( V_2 , V_90 ,
& V_55 -> V_50 . V_140 ) ;
break;
case V_78 :
case V_79 :
break;
case V_68 :
F_38 ( V_2 , V_90 ,
& V_55 -> V_50 . V_141 ) ;
break;
case V_69 :
F_40 ( V_2 , V_90 ,
& V_55 -> V_50 . V_142 ) ;
break;
case V_70 :
F_41 ( V_2 , V_90 ,
& V_55 -> V_50 . V_143 ) ;
break;
case V_144 :
case V_145 :
case V_146 :
F_42 ( V_2 , V_90 , V_55 ) ;
break;
case V_147 :
F_44 ( V_2 , V_90 , V_55 ) ;
break;
case V_148 :
F_34 ( V_2 , V_90 ,
& V_55 -> V_50 . V_149 ) ;
break;
case V_80 :
break;
default:
F_15 ( & V_2 -> V_2 , L_11 ,
V_55 -> type ) ;
return V_82 ;
}
return V_64 ;
}
int T_5 F_47 ( struct V_1 * V_2 )
{
struct V_83 * V_84 = V_2 -> V_50 ;
T_4 V_85 = V_84 -> V_85 ;
T_3 V_86 ;
struct V_127 V_128 ;
F_24 ( & V_2 -> V_2 , L_12 ) ;
V_128 . V_2 = V_2 ;
V_128 . V_90 = 0 ;
V_86 = F_26 ( V_85 , V_150 ,
F_45 , & V_128 ) ;
if ( F_27 ( V_86 ) ) {
if ( V_86 != V_88 )
F_2 ( & V_2 -> V_2 , L_13 , V_86 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_48 ( struct V_54 * V_55 )
{
switch ( V_55 -> type ) {
case V_129 :
case V_73 :
case V_71 :
case V_72 :
case V_68 :
case V_69 :
case V_70 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
return 1 ;
}
return 0 ;
}
static T_3 F_49 ( struct V_54 * V_55 ,
void * V_50 )
{
int * V_151 = V_50 ;
if ( F_48 ( V_55 ) )
( * V_151 ) ++ ;
return V_64 ;
}
static T_3 F_50 ( struct V_54 * V_55 , void * V_50 )
{
struct V_54 * * V_35 = V_50 ;
if ( F_48 ( V_55 ) ) {
( * V_35 ) -> type = V_55 -> type ;
( * V_35 ) -> V_52 = sizeof( struct V_54 ) ;
if ( V_55 -> type == V_129 )
( * V_35 ) -> V_50 . V_130 . V_152 =
V_55 -> V_50 . V_130 . V_152 ;
( * V_35 ) ++ ;
}
return V_64 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_83 * V_84 = V_2 -> V_50 ;
T_4 V_85 = V_84 -> V_85 ;
struct V_54 * V_35 ;
int V_151 = 0 ;
T_3 V_86 ;
V_86 = F_26 ( V_85 , V_87 ,
F_49 , & V_151 ) ;
if ( F_27 ( V_86 ) ) {
F_2 ( & V_2 -> V_2 , L_14 , V_86 ) ;
return - V_155 ;
}
if ( ! V_151 )
return - V_155 ;
V_154 -> V_52 = sizeof( struct V_54 ) * ( V_151 + 1 ) + 1 ;
V_154 -> V_156 = F_52 ( V_154 -> V_52 - 1 , V_157 ) ;
if ( ! V_154 -> V_156 )
return - V_158 ;
V_35 = (struct V_54 * ) V_154 -> V_156 ;
V_86 = F_26 ( V_85 , V_87 ,
F_50 , & V_35 ) ;
if ( F_27 ( V_86 ) ) {
F_53 ( V_154 -> V_156 ) ;
F_2 ( & V_2 -> V_2 , L_14 , V_86 ) ;
return - V_155 ;
}
V_35 -> type = V_79 ;
V_35 -> V_52 = sizeof( struct V_54 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_93 * V_130 = & V_35 -> V_50 . V_130 ;
T_1 V_4 , V_5 , V_6 ;
if ( ! F_55 ( V_91 ) ) {
V_130 -> V_96 = 0 ;
F_24 ( & V_2 -> V_2 , L_15 ,
V_91 ? L_16 : L_17 ) ;
return;
}
F_1 ( V_2 , V_91 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_130 -> V_4 = V_4 ;
V_130 -> V_5 = V_5 ;
V_130 -> V_67 = V_6 ;
V_130 -> V_96 = 1 ;
V_130 -> V_97 [ 0 ] = V_91 -> V_38 ;
F_24 ( & V_2 -> V_2 , L_18 ,
( int ) V_91 -> V_38 ,
V_4 == V_11 ? L_19 : L_20 ,
V_5 == V_12 ? L_21 : L_22 ,
V_130 -> V_67 == V_16 ? L_23 : L_24 ,
V_130 -> V_152 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_98 * V_149 = & V_35 -> V_50 . V_149 ;
T_1 V_4 , V_5 , V_6 ;
if ( ! F_55 ( V_91 ) ) {
V_149 -> V_96 = 0 ;
F_24 ( & V_2 -> V_2 , L_25 ,
V_91 ? L_16 : L_17 ) ;
return;
}
F_1 ( V_2 , V_91 -> V_3 , & V_4 , & V_5 , & V_6 ) ;
V_149 -> V_159 = V_160 ;
V_149 -> V_4 = V_4 ;
V_149 -> V_5 = V_5 ;
V_149 -> V_67 = V_6 ;
V_149 -> V_96 = 1 ;
V_149 -> V_97 [ 0 ] = V_91 -> V_38 ;
F_24 ( & V_2 -> V_2 , L_26 , ( int ) V_91 -> V_38 ,
V_4 == V_11 ? L_19 : L_20 ,
V_5 == V_12 ? L_21 : L_22 ,
V_149 -> V_67 == V_16 ? L_23 : L_24 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_56 * V_57 = & V_35 -> V_50 . V_57 ;
if ( ! F_55 ( V_91 ) ) {
V_57 -> V_74 = 0 ;
F_24 ( & V_2 -> V_2 , L_27 ,
V_91 ? L_16 : L_17 ) ;
return;
}
switch ( V_91 -> V_3 & V_161 ) {
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
switch ( V_91 -> V_3 & V_162 ) {
case V_30 :
V_57 -> V_19 = V_29 ;
break;
case V_32 :
V_57 -> V_19 = V_31 ;
break;
default:
V_57 -> V_19 = V_33 ;
}
V_57 -> V_18 = ! ! ( V_91 -> V_3 & V_20 ) ;
V_57 -> V_74 = 1 ;
V_57 -> V_75 [ 0 ] = V_91 -> V_38 ;
F_24 ( & V_2 -> V_2 , L_28
L_29 ,
( int ) V_91 -> V_38 , V_57 -> type , V_57 -> V_19 , V_57 -> V_18 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_99 * V_100 = & V_35 -> V_50 . V_100 ;
if ( F_55 ( V_91 ) ) {
V_100 -> V_101 = ( V_91 -> V_3 & V_103 ) ?
V_102 : V_163 ;
V_100 -> V_104 = V_91 -> V_38 ;
V_100 -> V_105 = V_91 -> V_164 ;
V_100 -> V_106 = 0 ;
V_100 -> V_107 = F_59 ( V_91 ) ;
} else {
V_100 -> V_104 = 0 ;
V_100 -> V_107 = 0 ;
}
F_24 ( & V_2 -> V_2 , L_30 , V_100 -> V_104 ,
V_100 -> V_104 + V_100 -> V_107 - 1 , V_100 -> V_101 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_108 * V_140 = & V_35 -> V_50 . V_140 ;
if ( F_55 ( V_91 ) ) {
V_140 -> V_109 = V_91 -> V_38 ;
V_140 -> V_107 = F_59 ( V_91 ) ;
} else {
V_140 -> V_109 = 0 ;
V_140 -> V_107 = 0 ;
}
F_24 ( & V_2 -> V_2 , L_31 , V_140 -> V_109 ,
V_140 -> V_109 + V_140 -> V_107 - 1 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_111 * V_141 = & V_35 -> V_50 . V_141 ;
if ( F_55 ( V_91 ) ) {
V_141 -> V_112 = V_91 -> V_3 & V_114 ?
V_113 : V_165 ;
V_141 -> V_104 = V_91 -> V_38 ;
V_141 -> V_105 = V_91 -> V_164 ;
V_141 -> V_106 = 0 ;
V_141 -> V_107 = F_59 ( V_91 ) ;
} else {
V_141 -> V_104 = 0 ;
V_141 -> V_107 = 0 ;
}
F_24 ( & V_2 -> V_2 , L_32 ,
V_141 -> V_104 ,
V_141 -> V_104 + V_141 -> V_107 - 1 ,
V_141 -> V_112 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_115 * V_142 = & V_35 -> V_50 . V_142 ;
if ( F_55 ( V_91 ) ) {
V_142 -> V_112 = V_91 -> V_3 & V_114 ?
V_113 : V_165 ;
V_142 -> V_104 = V_91 -> V_38 ;
V_142 -> V_105 = V_91 -> V_164 ;
V_142 -> V_106 = 0 ;
V_142 -> V_107 = F_59 ( V_91 ) ;
} else {
V_142 -> V_104 = 0 ;
V_142 -> V_106 = 0 ;
}
F_24 ( & V_2 -> V_2 , L_33 ,
V_142 -> V_104 ,
V_142 -> V_104 + V_142 -> V_107 - 1 ,
V_142 -> V_112 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_54 * V_35 ,
struct V_35 * V_91 )
{
struct V_116 * V_143 = & V_35 -> V_50 . V_143 ;
if ( F_55 ( V_91 ) ) {
V_143 -> V_112 =
V_91 -> V_3 & V_114 ?
V_113 : V_165 ;
V_143 -> V_109 = V_91 -> V_38 ;
V_143 -> V_107 = F_59 ( V_91 ) ;
} else {
V_143 -> V_109 = 0 ;
V_143 -> V_107 = 0 ;
}
F_24 ( & V_2 -> V_2 , L_34 ,
V_143 -> V_109 ,
V_143 -> V_109 + V_143 -> V_107 - 1 ,
V_143 -> V_112 ) ;
}
int F_64 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
int V_63 = 0 ;
int V_151 = ( V_154 -> V_52 - 1 ) / sizeof( struct V_54 ) - 1 ;
struct V_54 * V_35 = V_154 -> V_156 ;
unsigned int V_166 = 0 , V_130 = 0 , V_57 = 0 , V_122 = 0 ;
F_24 ( & V_2 -> V_2 , L_35 , V_151 ) ;
while ( V_63 < V_151 ) {
switch ( V_35 -> type ) {
case V_129 :
F_54 ( V_2 , V_35 ,
F_65 ( V_2 , V_167 , V_130 ) ) ;
V_130 ++ ;
break;
case V_73 :
F_57 ( V_2 , V_35 ,
F_65 ( V_2 , V_168 , V_57 ) ) ;
V_57 ++ ;
break;
case V_71 :
F_58 ( V_2 , V_35 ,
F_65 ( V_2 , V_169 , V_166 ) ) ;
V_166 ++ ;
break;
case V_72 :
F_60 ( V_2 , V_35 ,
F_65 ( V_2 , V_169 , V_166 ) ) ;
V_166 ++ ;
break;
case V_68 :
F_61 ( V_2 , V_35 ,
F_65 ( V_2 , V_170 , V_122 ) ) ;
V_122 ++ ;
break;
case V_69 :
F_62 ( V_2 , V_35 ,
F_65 ( V_2 , V_170 , V_122 ) ) ;
V_122 ++ ;
break;
case V_70 :
F_63 ( V_2 , V_35 ,
F_65 ( V_2 , V_170 , V_122 ) ) ;
V_122 ++ ;
break;
case V_148 :
F_56 ( V_2 , V_35 ,
F_65 ( V_2 , V_167 , V_130 ) ) ;
V_130 ++ ;
break;
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_80 :
default:
F_15 ( & V_2 -> V_2 ,
L_36 ,
V_35 -> type ) ;
return - V_155 ;
}
V_35 ++ ;
V_63 ++ ;
}
return 0 ;
}
