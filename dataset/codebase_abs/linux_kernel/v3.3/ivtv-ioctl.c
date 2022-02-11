T_1 F_1 ( int type )
{
switch ( type ) {
case V_1 :
return V_2 ;
case V_3 :
return V_4 ;
case V_5 :
return V_6 ;
case V_7 :
return V_8 ;
default:
return 0 ;
}
}
static int F_2 ( int V_9 , int line , int V_10 )
{
return ( V_10 && line >= 6 && ( line != 23 || V_9 == 0 ) ) ||
( ! V_10 && line >= 10 && line < 22 ) ;
}
static T_1 F_3 ( int V_9 , int line , T_1 V_11 , int V_10 )
{
T_1 V_12 = ( V_10 ? V_13 : V_14 ) ;
int V_15 ;
V_11 = V_11 & V_12 ;
if ( V_11 == 0 || ! F_2 ( V_9 , line , V_10 ) ) {
return 0 ;
}
if ( ! V_10 ) {
if ( line == 21 && ( V_11 & V_3 ) )
return V_3 ;
}
else {
if ( line == 16 && V_9 == 0 && ( V_11 & V_7 ) )
return V_7 ;
if ( line == 23 && V_9 == 0 && ( V_11 & V_5 ) )
return V_5 ;
if ( line == 23 )
return 0 ;
}
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
if ( ( 1 << V_15 ) & V_11 )
return 1 << V_15 ;
}
return 0 ;
}
void F_4 ( struct V_16 * V_17 , int V_10 )
{
T_1 V_11 = V_17 -> V_18 ;
int V_19 , V_20 ;
V_17 -> V_18 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
V_17 -> V_21 [ V_19 ] [ V_20 ] = F_3 ( V_19 , V_20 , V_11 , V_10 ) ;
}
}
}
static void F_5 ( struct V_16 * V_17 , int V_10 )
{
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
V_17 -> V_21 [ V_19 ] [ V_20 ] = F_3 ( V_19 , V_20 , V_17 -> V_21 [ V_19 ] [ V_20 ] , V_10 ) ;
}
}
}
T_1 F_6 ( struct V_16 * V_17 )
{
int V_19 , V_20 ;
T_1 V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
V_11 |= V_17 -> V_21 [ V_19 ] [ V_20 ] ;
}
}
return V_11 ;
}
void F_7 ( struct V_22 * V_23 )
{
F_8 ( V_23 , V_24 , 3 ,
V_23 -> V_25 , V_23 -> V_26 , ! V_23 -> V_27 ) ;
F_8 ( V_23 , V_28 , 2 , V_23 -> V_29 , V_23 -> V_30 ) ;
}
int F_9 ( struct V_22 * V_23 , int V_31 )
{
T_2 V_32 [ V_33 ] ;
struct V_34 * V_35 ;
int V_36 = ( V_31 == 1 || V_31 == - 1 ) ;
F_10 ( V_37 ) ;
if ( V_31 == 0 ) V_31 = 1000 ;
if ( V_31 == V_23 -> V_31 && ! V_36 )
return 0 ;
V_35 = & V_23 -> V_38 [ V_39 ] ;
if ( V_36 && ( V_31 < 0 ) == ( V_23 -> V_31 < 0 ) ) {
F_8 ( V_23 , V_40 , 1 , 0 ) ;
V_23 -> V_31 = V_31 ;
return 0 ;
}
if ( V_36 )
V_31 = V_31 < 0 ? - 1000 : 1000 ;
V_32 [ 0 ] = ( V_31 > 1000 || V_31 < - 1000 ) ? 0x80000000 : 0 ;
V_32 [ 0 ] |= ( V_31 > 1000 || V_31 < - 1500 ) ? 0x40000000 : 0 ;
V_32 [ 1 ] = ( V_31 < 0 ) ;
V_32 [ 2 ] = V_31 < 0 ? 3 : 7 ;
V_32 [ 3 ] = F_11 ( V_23 -> V_41 . V_42 ) ;
V_32 [ 4 ] = ( V_31 == 1500 || V_31 == 500 ) ? V_23 -> V_43 : 0 ;
V_32 [ 5 ] = 0 ;
V_32 [ 6 ] = 0 ;
if ( V_31 == 1500 || V_31 == - 1500 ) V_32 [ 0 ] |= 1 ;
else if ( V_31 == 2000 || V_31 == - 2000 ) V_32 [ 0 ] |= 2 ;
else if ( V_31 > - 1000 && V_31 < 0 ) V_32 [ 0 ] |= ( - 1000 / V_31 ) ;
else if ( V_31 < 1000 && V_31 > 0 ) V_32 [ 0 ] |= ( 1000 / V_31 ) ;
if ( F_12 ( & V_23 -> V_44 ) > 0 ) {
int V_45 = 0 ;
F_8 ( V_23 , V_46 , 1 , 0 ) ;
F_13 ( & V_23 -> V_47 ) ;
F_14 ( & V_23 -> V_48 , & V_37 , V_49 ) ;
while ( F_15 ( V_50 , & V_23 -> V_51 ) ) {
V_45 = F_16 ( V_52 ) ;
if ( V_45 )
break;
V_45 = 0 ;
F_17 () ;
}
F_18 ( & V_23 -> V_48 , & V_37 ) ;
F_19 ( & V_23 -> V_47 ) ;
if ( V_45 )
return - V_53 ;
F_20 ( V_23 , V_54 , 7 , V_32 ) ;
F_21 ( L_1 ,
V_32 [ 0 ] , V_32 [ 1 ] , V_32 [ 2 ] , V_32 [ 3 ] , V_32 [ 4 ] , V_32 [ 5 ] , V_32 [ 6 ] ) ;
}
if ( V_36 ) {
V_31 = ( V_31 < 0 ) ? - 1 : 1 ;
F_8 ( V_23 , V_40 , 1 , 0 ) ;
}
V_23 -> V_31 = V_31 ;
return 0 ;
}
static int F_22 ( int V_55 , int V_56 )
{
int V_57 = V_56 < 0 ? - 1 : 1 ;
int V_35 ;
if ( V_55 == 0 )
V_55 = 1000 ;
if ( V_56 < 0 )
V_56 = - V_56 ;
if ( V_55 < 0 )
V_55 = - V_55 ;
if ( V_55 <= V_56 ) {
if ( V_56 > 1500 )
return V_57 * 2000 ;
if ( V_56 > 1000 )
return V_57 * 1500 ;
}
else {
if ( V_56 >= 2000 )
return V_57 * 2000 ;
if ( V_56 >= 1500 )
return V_57 * 1500 ;
if ( V_56 >= 1000 )
return V_57 * 1000 ;
}
if ( V_56 == 0 )
return 1000 ;
if ( V_56 == 1 || V_56 == 1000 )
return V_57 * V_56 ;
V_35 = V_56 ;
V_56 = 1000 / V_56 ;
if ( 1000 / V_55 == V_56 )
V_56 += ( V_55 < V_35 ) ? - 1 : 1 ;
if ( V_56 > 60 ) return 1000 / ( V_57 * 60 ) ;
return 1000 / ( V_57 * V_56 ) ;
}
static int F_23 ( struct V_22 * V_23 , struct V_58 * V_59 ,
struct V_60 * V_61 , int V_62 )
{
struct V_34 * V_35 = & V_23 -> V_38 [ V_39 ] ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
switch ( V_61 -> V_66 ) {
case V_67 : {
V_61 -> V_68 = 0 ;
V_61 -> V_69 . V_31 = F_22 ( V_23 -> V_31 , V_61 -> V_69 . V_31 ) ;
if ( V_61 -> V_69 . V_31 < 0 )
V_61 -> V_69 . V_70 = V_71 ;
if ( V_62 ) break;
if ( F_24 ( V_23 , V_72 ) != V_72 )
return - V_73 ;
if ( F_25 ( V_74 , & V_23 -> V_51 ) ) {
V_23 -> V_31 = 0 ;
}
return F_26 ( V_59 , V_61 -> V_69 . V_31 ) ;
}
case V_75 :
V_61 -> V_68 &= V_76 | V_77 ;
if ( V_61 -> V_68 & V_76 )
V_61 -> V_78 . V_79 = 0 ;
if ( V_62 ) break;
if ( F_12 ( & V_23 -> V_44 ) == 0 )
return 0 ;
if ( V_23 -> V_80 != V_72 )
return - V_73 ;
V_23 -> V_80 = V_81 ;
return F_27 ( V_35 , V_61 -> V_68 , V_61 -> V_78 . V_79 ) ;
case V_82 :
V_61 -> V_68 &= V_83 ;
if ( V_62 ) break;
if ( V_23 -> V_80 != V_72 )
return - V_73 ;
if ( F_12 ( & V_23 -> V_44 ) > 0 ) {
F_8 ( V_23 , V_46 , 1 ,
( V_61 -> V_68 & V_83 ) ? 1 : 0 ) ;
F_28 ( V_74 , & V_23 -> V_51 ) ;
}
break;
case V_84 :
V_61 -> V_68 = 0 ;
if ( V_62 ) break;
if ( V_23 -> V_80 != V_72 )
return - V_73 ;
if ( F_25 ( V_74 , & V_23 -> V_51 ) ) {
int V_31 = V_23 -> V_31 ;
V_23 -> V_31 = 0 ;
return F_26 ( V_59 , V_31 ) ;
}
break;
default:
return - V_65 ;
}
return 0 ;
}
static int F_29 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
struct V_16 * V_88 = & V_17 -> V_17 . V_89 ;
V_88 -> V_90 [ 0 ] = 0 ;
V_88 -> V_90 [ 1 ] = 0 ;
if ( ! ( V_23 -> V_63 & V_91 ) )
return - V_65 ;
V_88 -> V_92 = sizeof( struct V_93 ) * 36 ;
if ( V_23 -> V_94 ) {
V_88 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_88 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_88 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_88 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
V_88 -> V_18 = F_6 ( V_88 ) ;
return 0 ;
}
static int F_31 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_95 * V_96 = & V_17 -> V_17 . V_97 ;
V_96 -> V_98 = V_23 -> V_41 . V_98 ;
V_96 -> V_99 = V_23 -> V_41 . V_99 ;
V_96 -> V_100 = V_101 ;
V_96 -> V_9 = V_102 ;
V_96 -> V_103 = 0 ;
if ( V_59 -> type == V_104 ) {
V_96 -> V_105 = V_106 ;
V_96 -> V_107 = V_96 -> V_99 * 720 * 3 / 2 ;
V_96 -> V_108 = 720 ;
} else {
V_96 -> V_105 = V_109 ;
V_96 -> V_107 = 128 * 1024 ;
V_96 -> V_108 = 0 ;
}
return 0 ;
}
static int F_32 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
struct V_110 * V_88 = & V_17 -> V_17 . V_111 ;
V_88 -> V_112 = 27000000 ;
V_88 -> V_113 = 248 ;
V_88 -> V_114 = V_23 -> V_111 . V_115 - 4 ;
V_88 -> V_116 = V_117 ;
V_88 -> V_118 [ 0 ] = V_23 -> V_111 . V_118 [ 0 ] ;
V_88 -> V_118 [ 1 ] = V_23 -> V_111 . V_118 [ 1 ] ;
V_88 -> V_119 [ 0 ] = V_88 -> V_119 [ 1 ] = V_23 -> V_111 . V_119 ;
V_88 -> V_68 = 0 ;
V_88 -> V_90 [ 0 ] = 0 ;
V_88 -> V_90 [ 1 ] = 0 ;
return 0 ;
}
static int F_33 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_16 * V_88 = & V_17 -> V_17 . V_89 ;
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
V_88 -> V_90 [ 0 ] = 0 ;
V_88 -> V_90 [ 1 ] = 0 ;
V_88 -> V_92 = sizeof( struct V_93 ) * 36 ;
if ( V_59 -> type == V_120 ) {
V_88 -> V_18 = V_23 -> V_121 ? V_13 :
V_14 ;
F_4 ( V_88 , V_23 -> V_121 ) ;
return 0 ;
}
F_34 ( V_23 -> V_122 , V_111 , V_123 , V_88 ) ;
V_88 -> V_18 = F_6 ( V_88 ) ;
return 0 ;
}
static int F_35 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_95 * V_96 = & V_17 -> V_17 . V_97 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_96 -> V_98 = V_23 -> V_124 . V_98 ;
V_96 -> V_99 = V_23 -> V_124 . V_99 ;
V_96 -> V_100 = V_101 ;
V_96 -> V_9 = V_102 ;
V_96 -> V_103 = 0 ;
if ( V_59 -> type == V_125 ) {
switch ( V_23 -> V_126 . V_127 & V_128 ) {
case V_129 :
V_96 -> V_9 = ( V_23 -> V_126 . V_127 & V_130 ) ?
V_131 : V_132 ;
break;
case V_133 :
V_96 -> V_9 = V_134 ;
break;
default:
V_96 -> V_9 = V_135 ;
break;
}
V_96 -> V_105 = V_106 ;
V_96 -> V_108 = 720 ;
V_96 -> V_98 = V_23 -> V_126 . V_136 ;
V_96 -> V_99 = V_23 -> V_126 . V_137 ;
V_96 -> V_107 =
1080 * ( ( V_96 -> V_99 + 31 ) & ~ 31 ) ;
} else {
V_96 -> V_105 = V_109 ;
V_96 -> V_107 = 128 * 1024 ;
V_96 -> V_108 = 0 ;
}
return 0 ;
}
static int F_36 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
struct V_138 * V_139 = & V_17 -> V_17 . V_140 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_139 -> V_141 = V_23 -> V_30 ;
V_139 -> V_142 = V_23 -> V_26 ;
V_139 -> V_9 = V_102 ;
V_139 -> V_143 = NULL ;
V_139 -> V_144 = 0 ;
V_139 -> V_145 = NULL ;
V_139 -> V_146 . V_147 = V_139 -> V_146 . V_148 = 0 ;
V_139 -> V_146 . V_98 = V_23 -> V_149 . V_98 ;
V_139 -> V_146 . V_99 = V_23 -> V_149 . V_99 ;
return 0 ;
}
static int F_37 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
return F_29 ( V_85 , V_86 , V_17 ) ;
}
static int F_38 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
int V_146 = V_17 -> V_17 . V_97 . V_98 ;
int V_150 = V_17 -> V_17 . V_97 . V_99 ;
int V_151 = 2 ;
V_146 = F_39 ( V_146 , 720 ) ;
V_146 = F_40 ( V_146 , 2 ) ;
if ( V_59 -> type == V_104 ) {
V_150 &= ~ 0x1f ;
V_151 = 32 ;
}
V_150 = F_39 ( V_150 , V_23 -> V_121 ? 576 : 480 ) ;
V_150 = F_40 ( V_150 , V_151 ) ;
F_31 ( V_85 , V_86 , V_17 ) ;
V_17 -> V_17 . V_97 . V_98 = V_146 ;
V_17 -> V_17 . V_97 . V_99 = V_150 ;
return 0 ;
}
static int F_41 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
return F_32 ( V_85 , V_86 , V_17 ) ;
}
static int F_42 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_16 * V_88 = & V_17 -> V_17 . V_89 ;
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
if ( V_59 -> type == V_120 )
return F_33 ( V_85 , V_86 , V_17 ) ;
V_88 -> V_92 = sizeof( struct V_93 ) * 36 ;
V_88 -> V_90 [ 0 ] = 0 ;
V_88 -> V_90 [ 1 ] = 0 ;
if ( V_88 -> V_18 )
F_4 ( V_88 , V_23 -> V_121 ) ;
F_5 ( V_88 , V_23 -> V_121 ) ;
V_88 -> V_18 = F_6 ( V_88 ) ;
return 0 ;
}
static int F_43 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
T_3 V_146 = V_17 -> V_17 . V_97 . V_98 ;
T_3 V_150 = V_17 -> V_17 . V_97 . V_99 ;
int V_9 = V_17 -> V_17 . V_97 . V_9 ;
int V_152 = F_35 ( V_85 , V_86 , V_17 ) ;
V_146 = F_39 ( V_146 , 720 ) ;
V_146 = F_40 ( V_146 , 2 ) ;
V_150 = F_39 ( V_150 , 576 ) ;
V_150 = F_40 ( V_150 , 2 ) ;
if ( V_59 -> type == V_125 )
V_17 -> V_17 . V_97 . V_9 = V_9 ;
V_17 -> V_17 . V_97 . V_98 = V_146 ;
V_17 -> V_17 . V_97 . V_99 = V_150 ;
return V_152 ;
}
static int F_44 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
T_2 V_141 = V_17 -> V_17 . V_140 . V_141 ;
T_4 V_142 = V_17 -> V_17 . V_140 . V_142 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
F_36 ( V_85 , V_86 , V_17 ) ;
V_17 -> V_17 . V_140 . V_141 = V_141 ;
V_17 -> V_17 . V_140 . V_142 = V_142 ;
return 0 ;
}
static int F_45 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
return F_29 ( V_85 , V_86 , V_17 ) ;
}
static int F_46 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_153 V_154 ;
int V_152 = F_38 ( V_85 , V_86 , V_17 ) ;
int V_146 = V_17 -> V_17 . V_97 . V_98 ;
int V_150 = V_17 -> V_17 . V_97 . V_99 ;
if ( V_152 )
return V_152 ;
if ( V_23 -> V_41 . V_98 == V_146 && V_23 -> V_41 . V_99 == V_150 )
return 0 ;
if ( F_12 ( & V_23 -> V_155 ) > 0 )
return - V_73 ;
V_23 -> V_41 . V_98 = V_146 ;
V_23 -> V_41 . V_99 = V_150 ;
if ( F_11 ( V_23 -> V_41 . V_156 ) == V_157 )
V_17 -> V_17 . V_97 . V_98 /= 2 ;
V_154 . V_98 = V_17 -> V_17 . V_97 . V_98 ;
V_154 . V_99 = V_150 ;
V_154 . V_158 = V_159 ;
F_34 ( V_23 -> V_122 , V_160 , V_161 , & V_154 ) ;
return F_31 ( V_85 , V_86 , V_17 ) ;
}
static int F_47 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( ! F_48 ( V_23 ) && F_12 ( & V_23 -> V_155 ) > 0 )
return - V_73 ;
V_23 -> V_111 . V_162 -> V_18 = 0 ;
V_23 -> V_111 . V_163 . type = V_164 ;
F_34 ( V_23 -> V_122 , V_111 , V_165 , & V_17 -> V_17 . V_111 ) ;
return F_32 ( V_85 , V_86 , V_17 ) ;
}
static int F_49 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_16 * V_88 = & V_17 -> V_17 . V_89 ;
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
int V_152 = F_42 ( V_85 , V_86 , V_17 ) ;
if ( V_152 || V_59 -> type == V_120 )
return V_152 ;
F_5 ( V_88 , V_23 -> V_121 ) ;
if ( F_48 ( V_23 ) && F_12 ( & V_23 -> V_155 ) > 0 )
return - V_73 ;
V_23 -> V_111 . V_163 . type = V_166 ;
F_34 ( V_23 -> V_122 , V_111 , V_167 , V_88 ) ;
memcpy ( V_23 -> V_111 . V_162 , V_88 , sizeof( * V_23 -> V_111 . V_162 ) ) ;
return 0 ;
}
static int F_50 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_168 * V_169 = & V_23 -> V_126 ;
int V_152 = F_43 ( V_85 , V_86 , V_17 ) ;
if ( V_152 )
return V_152 ;
if ( V_59 -> type != V_125 )
return 0 ;
if ( V_169 -> V_170 )
return - V_73 ;
V_169 -> V_136 = V_17 -> V_17 . V_97 . V_98 ;
V_169 -> V_137 = V_17 -> V_17 . V_97 . V_99 ;
switch ( V_17 -> V_17 . V_97 . V_9 ) {
case V_134 :
V_169 -> V_127 = V_133 ;
break;
case V_135 :
V_169 -> V_127 = V_171 ;
break;
case V_131 :
V_169 -> V_127 =
V_129 | V_172 ;
break;
case V_132 :
default:
V_169 -> V_127 = V_129 ;
break;
}
V_169 -> V_173 = ( V_169 -> V_127 & V_130 ) == V_174 ? 0 : 1 ;
if ( F_15 ( V_175 , & V_23 -> V_51 ) )
V_23 -> V_176 =
1080 * ( ( V_169 -> V_137 + 31 ) & ~ 31 ) ;
return 0 ;
}
static int F_51 ( struct V_85 * V_85 , void * V_86 , struct V_87 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
int V_152 = F_44 ( V_85 , V_86 , V_17 ) ;
if ( V_152 == 0 ) {
V_23 -> V_30 = V_17 -> V_17 . V_140 . V_141 ;
V_23 -> V_26 = V_17 -> V_17 . V_140 . V_142 ;
F_7 ( V_23 ) ;
}
return V_152 ;
}
static int F_52 ( struct V_85 * V_85 , void * V_86 , struct V_177 * V_178 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
V_178 -> V_179 = V_180 ;
V_178 -> V_181 = 0 ;
if ( V_178 -> V_182 . type == V_183 ) {
if ( F_53 ( & V_178 -> V_182 ) )
V_178 -> V_179 = V_23 -> V_184 ? V_185 : V_186 ;
return 0 ;
}
if ( V_178 -> V_182 . type != V_187 &&
V_178 -> V_182 . type != V_188 )
return - V_65 ;
return F_54 ( V_23 , V_189 , V_190 , V_178 ) ;
}
static int F_55 ( struct V_22 * V_23 , unsigned int V_66 , void * V_191 )
{
struct V_192 * V_193 = V_191 ;
volatile T_4 T_5 * V_194 ;
if ( ! F_56 ( V_195 ) )
return - V_196 ;
if ( V_193 -> V_197 >= V_198 && V_193 -> V_197 < V_198 + V_199 )
V_194 = V_23 -> V_200 - V_198 ;
else if ( V_23 -> V_184 && V_193 -> V_197 >= V_201 &&
V_193 -> V_197 < V_201 + V_202 )
V_194 = V_23 -> V_203 - V_201 ;
else if ( V_193 -> V_197 < V_204 )
V_194 = V_23 -> V_205 ;
else
return - V_65 ;
V_193 -> V_206 = 4 ;
if ( V_66 == V_207 )
V_193 -> V_208 = F_57 ( V_193 -> V_197 + V_194 ) ;
else
F_58 ( V_193 -> V_208 , V_193 -> V_197 + V_194 ) ;
return 0 ;
}
static int F_59 ( struct V_85 * V_85 , void * V_86 , struct V_192 * V_197 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( F_53 ( & V_197 -> V_182 ) )
return F_55 ( V_23 , V_207 , V_197 ) ;
F_60 ( V_23 , V_189 , V_209 , V_197 ) ;
return 0 ;
}
static int F_61 ( struct V_85 * V_85 , void * V_86 , struct V_192 * V_197 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( F_53 ( & V_197 -> V_182 ) )
return F_55 ( V_23 , V_210 , V_197 ) ;
F_60 ( V_23 , V_189 , V_211 , V_197 ) ;
return 0 ;
}
static int F_62 ( struct V_85 * V_85 , void * V_86 , struct V_212 * V_213 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
F_63 ( V_213 -> V_214 , V_215 , sizeof( V_213 -> V_214 ) ) ;
F_63 ( V_213 -> V_216 , V_23 -> V_217 , sizeof( V_213 -> V_216 ) ) ;
snprintf ( V_213 -> V_218 , sizeof( V_213 -> V_218 ) , L_2 , F_64 ( V_23 -> V_219 ) ) ;
V_213 -> V_220 = V_23 -> V_63 ;
return 0 ;
}
static int F_65 ( struct V_85 * V_85 , void * V_86 , struct V_221 * V_222 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
return F_66 ( V_23 , V_222 -> V_223 , V_222 ) ;
}
static int F_67 ( struct V_85 * V_85 , void * V_86 , struct V_221 * V_222 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
V_222 -> V_223 = V_23 -> V_224 ;
return F_66 ( V_23 , V_222 -> V_223 , V_222 ) ;
}
static int F_68 ( struct V_85 * V_85 , void * V_86 , struct V_221 * V_225 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( V_225 -> V_223 >= V_23 -> V_226 )
return - V_65 ;
V_23 -> V_224 = V_225 -> V_223 ;
F_69 ( V_23 ) ;
return 0 ;
}
static int F_70 ( struct V_85 * V_85 , void * V_86 , struct V_227 * V_222 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
return F_71 ( V_23 , V_222 -> V_223 , V_222 ) ;
}
static int F_72 ( struct V_85 * V_85 , void * V_86 , struct V_227 * V_222 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
V_222 -> V_223 = 0 ;
return F_71 ( V_23 , V_222 -> V_223 , V_222 ) ;
}
static int F_73 ( struct V_85 * V_85 , void * V_86 , struct V_227 * V_225 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
return F_71 ( V_23 , V_225 -> V_223 , V_225 ) ;
}
static int F_74 ( struct V_85 * V_85 , void * V_86 , struct V_228 * V_222 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
return F_75 ( V_23 , V_222 -> V_223 , V_222 ) ;
}
static int F_76 ( struct V_85 * V_85 , void * V_86 , struct V_229 * V_225 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
return F_77 ( V_23 , V_225 -> V_223 , V_225 ) ;
}
static int F_78 ( struct V_85 * V_85 , void * V_86 , struct V_230 * V_231 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_168 * V_169 = & V_23 -> V_126 ;
int V_232 ;
V_232 = V_59 -> type ;
if ( V_231 -> type != V_233 )
return - V_65 ;
V_231 -> V_234 . V_147 = V_231 -> V_234 . V_148 = 0 ;
V_231 -> V_234 . V_98 = 720 ;
if ( V_231 -> type == V_235 ) {
V_231 -> V_234 . V_99 = V_23 -> V_121 ? 576 : 480 ;
V_231 -> V_236 . V_237 = V_23 -> V_121 ? 59 : 10 ;
V_231 -> V_236 . V_238 = V_23 -> V_121 ? 54 : 11 ;
} else if ( V_232 == V_125 ) {
if ( V_169 -> V_239 ) {
V_231 -> V_234 . V_98 = V_169 -> V_240 ;
V_231 -> V_234 . V_99 = V_169 -> V_241 ;
} else {
V_231 -> V_234 . V_98 = 720 ;
V_231 -> V_234 . V_99 =
V_23 -> V_242 ? 576 : 480 ;
}
V_231 -> V_236 . V_237 = V_23 -> V_242 ? 59 : 10 ;
V_231 -> V_236 . V_238 = V_23 -> V_242 ? 54 : 11 ;
} else {
V_231 -> V_234 . V_99 = V_23 -> V_242 ? 576 : 480 ;
V_231 -> V_236 . V_237 = V_23 -> V_242 ? 59 : 10 ;
V_231 -> V_236 . V_238 = V_23 -> V_242 ? 54 : 11 ;
}
V_231 -> V_243 = V_231 -> V_234 ;
return 0 ;
}
static int F_79 ( struct V_85 * V_85 , void * V_86 , struct V_244 * V_245 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_168 * V_169 = & V_23 -> V_126 ;
int V_232 ;
V_232 = V_59 -> type ;
if ( V_245 -> type == V_233 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_232 == V_125 ) {
V_169 -> V_124 = V_245 -> V_246 ;
return 0 ;
} else {
if ( ! F_8 ( V_23 , V_247 , 4 ,
V_245 -> V_246 . V_98 , V_245 -> V_246 . V_99 , V_245 -> V_246 . V_148 , V_245 -> V_246 . V_147 ) ) {
V_23 -> V_124 = V_245 -> V_246 ;
return 0 ;
}
}
return - V_65 ;
}
return - V_65 ;
}
static int F_80 ( struct V_85 * V_85 , void * V_86 , struct V_244 * V_245 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_168 * V_169 = & V_23 -> V_126 ;
int V_232 ;
V_232 = V_59 -> type ;
if ( V_245 -> type == V_233 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_232 == V_125 )
V_245 -> V_246 = V_169 -> V_124 ;
else
V_245 -> V_246 = V_23 -> V_124 ;
return 0 ;
}
return - V_65 ;
}
static int F_81 ( struct V_85 * V_85 , void * V_86 , struct V_248 * V_17 )
{
static struct V_248 V_249 [] = {
{ 0 , 0 , 0 ,
L_3 , V_106 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_250 ,
L_4 , V_109 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_251 type = V_17 -> type ;
if ( V_17 -> V_223 > 1 )
return - V_65 ;
* V_17 = V_249 [ V_17 -> V_223 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_82 ( struct V_85 * V_85 , void * V_86 , struct V_248 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
static struct V_248 V_249 [] = {
{ 0 , 0 , 0 ,
L_3 , V_106 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_250 ,
L_4 , V_109 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_251 type = V_17 -> type ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( V_17 -> V_223 > 1 )
return - V_65 ;
* V_17 = V_249 [ V_17 -> V_223 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_83 ( struct V_85 * V_85 , void * V_86 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
* V_15 = V_23 -> V_252 ;
return 0 ;
}
int F_84 ( struct V_85 * V_85 , void * V_86 , unsigned int V_253 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( V_253 < 0 || V_253 >= V_23 -> V_254 )
return - V_65 ;
if ( V_253 == V_23 -> V_252 ) {
F_21 ( L_5 ) ;
return 0 ;
}
if ( F_12 ( & V_23 -> V_155 ) > 0 ) {
return - V_73 ;
}
F_21 ( L_6 ,
V_23 -> V_252 , V_253 ) ;
V_23 -> V_252 = V_253 ;
V_23 -> V_224 = V_23 -> V_216 -> V_255 [ V_253 ] . V_256 ;
F_85 ( V_23 ) ;
F_86 ( V_23 ) ;
F_69 ( V_23 ) ;
F_87 ( V_23 ) ;
return 0 ;
}
static int F_88 ( struct V_85 * V_85 , void * V_86 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
* V_15 = V_23 -> V_257 ;
return 0 ;
}
static int F_89 ( struct V_85 * V_85 , void * V_86 , unsigned int V_258 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( V_258 >= V_23 -> V_216 -> V_259 )
return - V_65 ;
if ( V_258 == V_23 -> V_257 ) {
F_21 ( L_7 ) ;
return 0 ;
}
F_21 ( L_8 ,
V_23 -> V_257 , V_258 ) ;
V_23 -> V_257 = V_258 ;
F_90 ( V_23 , V_260 , V_160 , V_261 ,
V_262 ,
V_23 -> V_216 -> V_263 [ V_258 ] . V_264 , 0 ) ;
return 0 ;
}
static int F_91 ( struct V_85 * V_85 , void * V_86 , struct V_265 * V_266 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( V_266 -> V_267 != 0 )
return - V_65 ;
F_60 ( V_23 , V_267 , V_268 , V_266 ) ;
return 0 ;
}
int F_92 ( struct V_85 * V_85 , void * V_86 , struct V_265 * V_266 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( V_266 -> V_267 != 0 )
return - V_65 ;
F_85 ( V_23 ) ;
F_21 ( L_9 , V_266 -> V_269 ) ;
F_60 ( V_23 , V_267 , V_270 , V_266 ) ;
F_87 ( V_23 ) ;
return 0 ;
}
static int F_93 ( struct V_85 * V_85 , void * V_86 , T_6 * V_271 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
* V_271 = V_23 -> V_271 ;
return 0 ;
}
void F_94 ( struct V_22 * V_23 , T_6 * V_271 )
{
V_23 -> V_271 = * V_271 ;
V_23 -> V_94 = ( * V_271 & V_272 ) ? 1 : 0 ;
V_23 -> V_121 = ! V_23 -> V_94 ;
F_95 ( & V_23 -> V_41 , V_23 -> V_121 ) ;
V_23 -> V_41 . V_98 = 720 ;
V_23 -> V_41 . V_99 = V_23 -> V_121 ? 576 : 480 ;
V_23 -> V_111 . V_119 = V_23 -> V_121 ? 18 : 12 ;
V_23 -> V_111 . V_118 [ 0 ] = V_23 -> V_121 ? 6 : 10 ;
V_23 -> V_111 . V_118 [ 1 ] = V_23 -> V_121 ? 318 : 273 ;
if ( V_23 -> V_273 & V_274 )
V_23 -> V_111 . V_275 = V_23 -> V_94 ? 272 : 284 ;
F_60 ( V_23 , V_189 , V_276 , V_23 -> V_271 ) ;
}
void F_96 ( struct V_22 * V_23 , T_6 * V_271 )
{
struct V_168 * V_169 = & V_23 -> V_126 ;
F_10 ( V_37 ) ;
int V_19 ;
V_23 -> V_277 = * V_271 ;
V_23 -> V_278 = ( * V_271 & V_272 ) ? 1 : 0 ;
V_23 -> V_242 = ! V_23 -> V_278 ;
F_60 ( V_23 , V_160 , V_279 , V_23 -> V_277 ) ;
F_13 ( & V_23 -> V_47 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_14 ( & V_23 -> V_280 , & V_37 ,
V_281 ) ;
if ( ( F_97 ( V_282 ) >> 16 ) < 100 )
break;
F_98 ( F_99 ( 25 ) ) ;
}
F_18 ( & V_23 -> V_280 , & V_37 ) ;
F_19 ( & V_23 -> V_47 ) ;
if ( V_19 == 4 )
F_100 ( L_10 ) ;
F_8 ( V_23 , V_283 , 1 , V_23 -> V_242 ) ;
V_23 -> V_124 . V_148 = 0 ;
V_23 -> V_124 . V_147 = 0 ;
V_23 -> V_124 . V_98 = 720 ;
V_23 -> V_124 . V_99 = V_23 -> V_242 ? 576 : 480 ;
F_8 ( V_23 , V_247 , 4 ,
720 , V_23 -> V_124 . V_99 , 0 , 0 ) ;
V_169 -> V_124 = V_23 -> V_124 ;
if ( ! V_23 -> V_284 ) {
V_169 -> V_240 = 720 ;
V_169 -> V_241 = V_23 -> V_242 ? 576 : 480 ;
}
}
int F_101 ( struct V_85 * V_85 , void * V_86 , T_6 * V_271 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( ( * V_271 & V_285 ) == 0 )
return - V_65 ;
if ( * V_271 == V_23 -> V_271 )
return 0 ;
if ( F_15 ( V_286 , & V_23 -> V_51 ) ||
F_12 ( & V_23 -> V_155 ) > 0 ||
F_12 ( & V_23 -> V_44 ) > 0 ) {
return - V_73 ;
}
F_21 ( L_11 ,
( unsigned long long ) V_23 -> V_271 ) ;
F_94 ( V_23 , V_271 ) ;
if ( V_23 -> V_63 & V_64 )
F_96 ( V_23 , V_271 ) ;
return 0 ;
}
static int F_102 ( struct V_85 * V_85 , void * V_86 , struct V_287 * V_288 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
if ( V_288 -> V_223 != 0 )
return - V_65 ;
F_60 ( V_23 , V_267 , V_289 , V_288 ) ;
return 0 ;
}
static int F_103 ( struct V_85 * V_85 , void * V_86 , struct V_287 * V_288 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( V_288 -> V_223 != 0 )
return - V_65 ;
F_60 ( V_23 , V_267 , V_290 , V_288 ) ;
if ( V_288 -> type == V_291 )
F_63 ( V_288 -> V_292 , L_12 , sizeof( V_288 -> V_292 ) ) ;
else
F_63 ( V_288 -> V_292 , L_13 , sizeof( V_288 -> V_292 ) ) ;
return 0 ;
}
static int F_104 ( struct V_85 * V_85 , void * V_86 , struct V_293 * V_294 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
int V_11 = V_23 -> V_121 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_294 -> type == V_166 ) {
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_23 -> V_121 ) )
V_294 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
}
}
} else if ( V_294 -> type == V_295 ) {
if ( ! ( V_23 -> V_63 & V_91 ) )
return - V_65 ;
if ( V_23 -> V_94 ) {
V_294 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_294 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_294 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_294 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
} else {
return - V_65 ;
}
V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ )
V_11 |= V_294 -> V_21 [ V_19 ] [ V_20 ] ;
V_294 -> V_18 = V_11 ;
return 0 ;
}
static int F_105 ( struct V_85 * V_85 , void * V_86 , struct V_296 * V_297 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
struct V_298 * V_299 = V_297 -> V_300 ;
int V_301 ;
int V_15 ;
V_301 = ( V_23 -> V_302 + V_303 - V_23 -> V_304 ) %
V_303 ;
if ( V_301 > V_305 )
V_301 = V_305 ;
V_297 -> V_301 = 0 ;
for ( V_15 = 0 ; V_15 < V_301 ; V_15 ++ ) {
* V_299 = V_23 -> V_306 [ ( V_23 -> V_304 + V_15 ) % V_303 ] ;
if ( ( V_299 -> V_68 & V_307 ) <= V_308 ) {
V_297 -> V_301 ++ ;
V_299 ++ ;
}
}
V_23 -> V_304 = ( V_23 -> V_304 + V_297 -> V_301 ) % V_303 ;
return 0 ;
}
static int F_106 ( struct V_85 * V_85 , void * V_86 , struct V_309 * V_310 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
switch ( V_310 -> V_66 ) {
case V_311 :
F_107 ( L_14 ) ;
V_310 -> V_68 = 0 ;
return F_108 ( V_59 ) ;
case V_312 :
F_107 ( L_15 ) ;
V_310 -> V_68 &= V_313 ;
F_109 ( V_59 , V_310 -> V_68 & V_313 ) ;
return 0 ;
case V_314 :
F_107 ( L_16 ) ;
V_310 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_155 ) )
return - V_196 ;
if ( F_110 ( V_315 , & V_23 -> V_51 ) )
return 0 ;
F_85 ( V_23 ) ;
F_8 ( V_23 , V_316 , 1 , 0 ) ;
break;
case V_317 :
F_107 ( L_17 ) ;
V_310 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_155 ) )
return - V_196 ;
if ( ! F_25 ( V_315 , & V_23 -> V_51 ) )
return 0 ;
F_8 ( V_23 , V_316 , 1 , 1 ) ;
F_87 ( V_23 ) ;
break;
default:
F_107 ( L_18 , V_310 -> V_66 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_111 ( struct V_85 * V_85 , void * V_86 , struct V_309 * V_310 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
switch ( V_310 -> V_66 ) {
case V_311 :
F_107 ( L_14 ) ;
V_310 -> V_68 = 0 ;
return 0 ;
case V_312 :
F_107 ( L_15 ) ;
V_310 -> V_68 &= V_313 ;
return 0 ;
case V_314 :
F_107 ( L_16 ) ;
V_310 -> V_68 = 0 ;
return 0 ;
case V_317 :
F_107 ( L_17 ) ;
V_310 -> V_68 = 0 ;
return 0 ;
default:
F_107 ( L_18 , V_310 -> V_66 ) ;
return - V_65 ;
}
}
static int F_112 ( struct V_85 * V_85 , void * V_86 , struct V_318 * V_319 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
struct V_168 * V_169 = & V_23 -> V_126 ;
int V_96 ;
static T_2 V_320 [ 16 ] = {
V_321 ,
V_322 ,
V_323 ,
V_324 ,
V_325 ,
0 ,
0 ,
0 ,
V_321 ,
V_326 ,
V_327 ,
V_328 ,
V_329 ,
0 ,
0 ,
0 ,
} ;
if ( ! ( V_23 -> V_63 & V_330 ) )
return - V_65 ;
if ( ! V_23 -> V_331 )
return - V_65 ;
V_319 -> V_332 = V_333 | V_334 |
V_335 ;
F_113 ( V_23 , V_32 , V_336 , 0 ) ;
V_32 [ 0 ] |= ( F_97 ( 0x2a00 ) >> 7 ) & 0x40 ;
V_96 = ( V_32 [ 0 ] >> 3 ) & 0xf ;
V_319 -> V_17 . V_105 = V_320 [ V_96 ] ;
V_319 -> V_17 . V_98 = V_23 -> V_149 . V_98 ;
V_319 -> V_17 . V_99 = V_23 -> V_149 . V_99 ;
V_319 -> V_17 . V_9 = V_102 ;
V_319 -> V_17 . V_108 = V_319 -> V_17 . V_98 ;
V_319 -> V_17 . V_100 = V_101 ;
V_319 -> V_17 . V_9 = V_102 ;
V_319 -> V_17 . V_103 = 0 ;
if ( V_319 -> V_17 . V_105 != V_321 )
V_319 -> V_17 . V_108 *= 2 ;
if ( V_319 -> V_17 . V_105 == V_325 ||
V_319 -> V_17 . V_105 == V_329 )
V_319 -> V_17 . V_108 *= 2 ;
V_319 -> V_17 . V_107 = V_319 -> V_17 . V_108 * V_319 -> V_17 . V_99 ;
V_319 -> V_337 = ( void * ) V_23 -> V_331 ;
V_319 -> V_68 = 0 ;
if ( V_23 -> V_29 )
V_319 -> V_68 |= V_338 ;
if ( V_23 -> V_25 )
V_319 -> V_68 |= V_339 ;
if ( V_169 -> V_239 )
V_319 -> V_68 |= V_340 ;
V_96 &= 7 ;
if ( V_96 == 1 || V_96 > 4 )
return 0 ;
if ( V_96 == 2 || V_96 == 3 )
V_319 -> V_332 |= V_341 ;
else
V_319 -> V_332 |= V_342 ;
if ( V_23 -> V_27 ) {
if ( V_96 == 2 || V_96 == 3 )
V_319 -> V_68 |= V_343 ;
else
V_319 -> V_68 |= V_344 ;
}
return 0 ;
}
static int F_114 ( struct V_85 * V_85 , void * V_86 , struct V_318 * V_319 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_168 * V_169 = & V_23 -> V_126 ;
if ( ! ( V_23 -> V_63 & V_330 ) )
return - V_65 ;
if ( ! V_23 -> V_331 )
return - V_65 ;
V_23 -> V_25 = ( V_319 -> V_68 & V_339 ) != 0 ;
V_23 -> V_27 =
( V_319 -> V_68 & ( V_344 | V_343 ) ) != 0 ;
V_23 -> V_29 = ( V_319 -> V_68 & V_338 ) != 0 ;
F_7 ( V_23 ) ;
V_169 -> V_239 = ( V_319 -> V_68 & V_340 ) != 0 ;
return F_112 ( V_85 , V_86 , V_319 ) ;
}
static int F_115 ( struct V_85 * V_85 , void * V_86 , unsigned int V_345 )
{
struct V_58 * V_59 = F_30 ( V_86 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
if ( ! ( V_23 -> V_63 & V_330 ) )
return - V_65 ;
F_8 ( V_23 , V_346 , 1 , V_345 != 0 ) ;
return 0 ;
}
static int F_116 ( struct V_347 * V_86 , struct V_348 * V_349 )
{
switch ( V_349 -> type ) {
case V_350 :
case V_351 :
case V_352 :
return F_117 ( V_86 , V_349 , 0 ) ;
default:
return - V_65 ;
}
}
static int F_118 ( struct V_85 * V_85 , void * V_86 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
int V_353 = V_23 -> V_63 & V_64 ;
struct V_228 V_354 ;
struct V_221 V_355 ;
int V_15 ;
F_119 ( L_19 ,
V_23 -> V_356 ) ;
F_119 ( L_20 , V_357 , V_23 -> V_217 ) ;
if ( V_23 -> V_273 & V_358 ) {
struct V_359 V_360 ;
F_120 ( V_23 , & V_360 ) ;
}
F_60 ( V_23 , V_189 , V_361 ) ;
F_75 ( V_23 , V_23 -> V_252 , & V_354 ) ;
F_66 ( V_23 , V_23 -> V_224 , & V_355 ) ;
F_119 ( L_21 , V_354 . V_292 ) ;
F_119 ( L_22 , V_355 . V_292 ,
( V_23 -> V_362 & ~ 0x300 ) == 0x200 ? L_23 : L_24 ) ;
if ( V_353 ) {
struct V_229 V_363 ;
struct V_227 V_364 ;
int V_365 = V_23 -> V_80 ;
static const char * const V_366 [ 5 ] = {
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
} ;
static const char * const V_367 [ 5 ] = {
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34
} ;
static const char * const V_368 [ 4 ] = {
L_25 ,
L_35 ,
L_36 ,
L_37
} ;
static const char * const V_320 [ 16 ] = {
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
} ;
F_77 ( V_23 , V_23 -> V_257 , & V_363 ) ;
F_71 ( V_23 , 0 , & V_364 ) ;
F_119 ( L_54 , V_363 . V_292 ) ;
F_119 ( L_55 , V_364 . V_292 ,
V_367 [ V_23 -> V_369 ] ,
V_367 [ V_23 -> V_370 ] ) ;
if ( V_365 < 0 || V_365 > V_371 )
V_365 = V_81 ;
F_119 ( L_56 , V_366 [ V_365 ] ) ;
F_113 ( V_23 , V_32 , V_336 , 0 ) ;
V_32 [ 0 ] |= ( F_97 ( 0x2a00 ) >> 7 ) & 0x40 ;
F_119 ( L_57 ,
V_32 [ 0 ] & 1 ? L_58 : L_59 ,
V_368 [ ( V_32 [ 0 ] >> 1 ) & 0x3 ] ,
V_320 [ ( V_32 [ 0 ] >> 3 ) & 0xf ] ) ;
}
F_119 ( L_60 ,
F_15 ( V_286 , & V_23 -> V_51 ) ? L_61 : L_62 ) ;
F_121 ( & V_23 -> V_41 . V_372 , V_23 -> V_373 . V_292 ) ;
F_119 ( L_63 , V_23 -> V_51 ) ;
for ( V_15 = 0 ; V_15 < V_374 ; V_15 ++ ) {
struct V_34 * V_35 = & V_23 -> V_38 [ V_15 ] ;
if ( V_35 -> V_375 == NULL || V_35 -> V_376 == 0 )
continue;
F_119 ( L_64 , V_35 -> V_292 , V_35 -> V_377 ,
( V_35 -> V_376 - V_35 -> V_378 . V_376 ) * 100 / V_35 -> V_376 ,
( V_35 -> V_376 * V_35 -> V_379 ) / 1024 , V_35 -> V_376 ) ;
}
F_119 ( L_65 ,
( long long ) V_23 -> V_380 ,
( long long ) V_23 -> V_381 ) ;
F_119 ( L_66 ,
V_23 -> V_356 ) ;
return 0 ;
}
static int F_122 ( struct V_85 * V_382 , unsigned int V_66 , void * V_191 )
{
struct V_58 * V_59 = F_30 ( V_382 -> V_383 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
int V_384 = V_382 -> V_385 & V_386 ;
struct V_34 * V_35 = & V_23 -> V_38 [ V_59 -> type ] ;
unsigned long V_387 = ( unsigned long ) V_191 ;
switch ( V_66 ) {
case V_388 : {
struct V_389 * args = V_191 ;
F_107 ( L_67 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( args -> type != V_233 )
return - V_65 ;
if ( V_23 -> V_80 == V_390 && args -> V_391 == NULL )
return 0 ;
if ( F_26 ( V_59 , V_59 -> type ) ) {
return - V_73 ;
}
if ( F_24 ( V_23 , V_390 ) != V_390 ) {
F_123 ( V_35 ) ;
return - V_73 ;
}
V_59 -> V_392 = 1 ;
if ( args -> V_391 == NULL )
return 0 ;
return F_124 ( V_23 , args ) ;
}
case V_393 : {
T_2 V_32 [ V_33 ] ;
T_7 * V_79 = V_191 ;
F_107 ( L_68 ) ;
if ( V_35 -> type < V_39 ) {
* V_79 = V_35 -> V_394 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( F_15 ( V_395 , & V_23 -> V_51 ) ) {
* V_79 = ( T_7 ) ( ( T_7 ) V_23 -> V_396 [ 2 ] << 32 ) |
( T_7 ) V_23 -> V_396 [ 1 ] ;
break;
}
* V_79 = 0 ;
if ( F_12 ( & V_23 -> V_44 ) ) {
if ( F_20 ( V_23 , V_397 , 5 , V_32 ) ) {
F_125 ( L_69 ) ;
return - V_398 ;
}
memcpy ( V_23 -> V_396 , V_32 , sizeof( V_23 -> V_396 ) ) ;
F_28 ( V_395 , & V_23 -> V_51 ) ;
* V_79 = ( T_7 ) ( ( T_7 ) V_32 [ 2 ] << 32 ) | ( T_7 ) V_32 [ 1 ] ;
}
break;
}
case V_399 : {
T_2 V_32 [ V_33 ] ;
T_7 * V_400 = V_191 ;
F_107 ( L_70 ) ;
if ( V_35 -> type < V_39 ) {
* V_400 = 0 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( F_15 ( V_395 , & V_23 -> V_51 ) ) {
* V_400 = V_23 -> V_396 [ 0 ] ;
break;
}
* V_400 = 0 ;
if ( F_12 ( & V_23 -> V_44 ) ) {
if ( F_20 ( V_23 , V_397 , 5 , V_32 ) ) {
F_125 ( L_69 ) ;
return - V_398 ;
}
memcpy ( V_23 -> V_396 , V_32 , sizeof( V_23 -> V_396 ) ) ;
F_28 ( V_395 , & V_23 -> V_51 ) ;
* V_400 = V_32 [ 0 ] ;
}
break;
}
case V_401 : {
struct V_60 V_61 ;
F_107 ( L_71 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_67 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_402 : {
struct V_60 V_61 ;
F_107 ( L_72 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_75 ;
V_61 . V_68 = V_77 | V_76 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_403 : {
struct V_60 V_61 ;
F_107 ( L_73 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_82 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_404 : {
struct V_60 V_61 ;
F_107 ( L_74 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_84 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_405 :
case V_406 : {
struct V_60 * V_61 = V_191 ;
int V_62 = ( V_66 == V_406 ) ;
if ( V_62 )
F_107 ( L_75 , V_61 -> V_66 ) ;
else
F_107 ( L_76 , V_61 -> V_66 ) ;
return F_23 ( V_23 , V_59 , V_61 , V_62 ) ;
}
case V_407 : {
struct V_408 * V_409 = V_191 ;
F_10 ( V_37 ) ;
F_107 ( L_77 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
memset ( V_409 , 0 , sizeof( * V_409 ) ) ;
F_28 ( V_410 , & V_23 -> V_51 ) ;
while ( 1 ) {
if ( F_25 ( V_411 , & V_23 -> V_51 ) )
V_409 -> type = V_412 ;
else if ( F_25 ( V_413 , & V_23 -> V_51 ) ) {
V_409 -> type = V_414 ;
V_409 -> V_415 . V_416 = F_15 ( V_417 , & V_23 -> V_51 ) ?
V_418 : V_419 ;
if ( V_23 -> V_80 == V_390 &&
( V_23 -> V_126 . V_127 & V_128 ) ==
V_133 ) {
V_409 -> V_415 . V_416 = V_420 ;
}
}
if ( V_409 -> type )
return 0 ;
if ( V_384 )
return - V_421 ;
F_13 ( & V_23 -> V_47 ) ;
F_14 ( & V_23 -> V_422 , & V_37 , V_49 ) ;
if ( ! F_15 ( V_411 , & V_23 -> V_51 ) &&
! F_15 ( V_413 , & V_23 -> V_51 ) )
F_17 () ;
F_18 ( & V_23 -> V_422 , & V_37 ) ;
F_19 ( & V_23 -> V_47 ) ;
if ( F_16 ( V_52 ) ) {
F_21 ( L_78 ) ;
return - V_53 ;
}
}
break;
}
case V_423 :
F_107 ( L_79 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_126 ( V_23 , V_387 == V_424 ) ;
case V_425 :
F_107 ( L_80 ) ;
V_23 -> V_43 = V_387 ;
return 0 ;
case V_426 :
F_107 ( L_81 ) ;
if ( V_387 > V_427 )
return - V_65 ;
V_23 -> V_369 = V_387 ;
F_8 ( V_23 , V_428 , 2 , V_23 -> V_370 , V_23 -> V_369 ) ;
return 0 ;
case V_429 :
F_107 ( L_82 ) ;
if ( V_387 > V_427 )
return - V_65 ;
V_23 -> V_370 = V_387 ;
F_8 ( V_23 , V_428 , 2 , V_23 -> V_370 , V_23 -> V_369 ) ;
return 0 ;
default:
return - V_65 ;
}
return 0 ;
}
static long F_127 ( struct V_85 * V_85 , void * V_86 , bool V_430 ,
int V_66 , void * V_191 )
{
struct V_22 * V_23 = F_30 ( V_86 ) -> V_23 ;
if ( ! V_430 ) {
switch ( V_66 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_423 :
case V_425 :
case V_426 :
case V_429 :
return - V_73 ;
}
}
switch ( V_66 ) {
case V_431 : {
T_2 V_208 = * ( T_2 * ) V_191 ;
if ( ( V_208 == 0 && V_23 -> V_432 . V_433 ) || ( V_208 & 0x01 ) )
F_128 ( V_23 ) ;
if ( V_208 & 0x02 )
F_34 ( V_23 -> V_122 , V_189 , V_434 , 0 ) ;
break;
}
case V_388 :
case V_393 :
case V_399 :
case V_407 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_423 :
case V_425 :
case V_426 :
case V_429 :
return F_122 ( V_85 , V_66 , ( void * ) V_191 ) ;
default:
return - V_65 ;
}
return 0 ;
}
long F_129 ( struct V_85 * V_382 , unsigned int V_66 , unsigned long V_191 )
{
struct V_435 * V_436 = F_130 ( V_382 ) ;
long V_152 ;
if ( V_437 & V_438 )
V_436 -> V_439 = V_440 | V_441 ;
V_152 = F_131 ( V_382 , V_66 , V_191 ) ;
V_436 -> V_439 = 0 ;
return V_152 ;
}
void F_132 ( struct V_435 * V_375 )
{
V_375 -> V_442 = & V_443 ;
}
