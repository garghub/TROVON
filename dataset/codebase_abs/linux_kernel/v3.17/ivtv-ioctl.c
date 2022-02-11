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
int V_34 = ( V_31 == 1 || V_31 == - 1 ) ;
F_10 ( V_35 ) ;
if ( V_31 == 0 ) V_31 = 1000 ;
if ( V_31 == V_23 -> V_31 && ! V_34 )
return 0 ;
if ( V_34 && ( V_31 < 0 ) == ( V_23 -> V_31 < 0 ) ) {
F_8 ( V_23 , V_36 , 1 , 0 ) ;
V_23 -> V_31 = V_31 ;
return 0 ;
}
if ( V_34 )
V_31 = V_31 < 0 ? - 1000 : 1000 ;
V_32 [ 0 ] = ( V_31 > 1000 || V_31 < - 1000 ) ? 0x80000000 : 0 ;
V_32 [ 0 ] |= ( V_31 > 1000 || V_31 < - 1500 ) ? 0x40000000 : 0 ;
V_32 [ 1 ] = ( V_31 < 0 ) ;
V_32 [ 2 ] = V_31 < 0 ? 3 : 7 ;
V_32 [ 3 ] = F_11 ( V_23 -> V_37 . V_38 ) ;
V_32 [ 4 ] = ( V_31 == 1500 || V_31 == 500 ) ? V_23 -> V_39 : 0 ;
V_32 [ 5 ] = 0 ;
V_32 [ 6 ] = 0 ;
if ( V_31 == 1500 || V_31 == - 1500 ) V_32 [ 0 ] |= 1 ;
else if ( V_31 == 2000 || V_31 == - 2000 ) V_32 [ 0 ] |= 2 ;
else if ( V_31 > - 1000 && V_31 < 0 ) V_32 [ 0 ] |= ( - 1000 / V_31 ) ;
else if ( V_31 < 1000 && V_31 > 0 ) V_32 [ 0 ] |= ( 1000 / V_31 ) ;
if ( F_12 ( & V_23 -> V_40 ) > 0 ) {
int V_41 = 0 ;
F_8 ( V_23 , V_42 , 1 , 0 ) ;
F_13 ( & V_23 -> V_43 ) ;
F_14 ( & V_23 -> V_44 , & V_35 , V_45 ) ;
while ( F_15 ( V_46 , & V_23 -> V_47 ) ) {
V_41 = F_16 ( V_48 ) ;
if ( V_41 )
break;
V_41 = 0 ;
F_17 () ;
}
F_18 ( & V_23 -> V_44 , & V_35 ) ;
F_19 ( & V_23 -> V_43 ) ;
if ( V_41 )
return - V_49 ;
F_20 ( V_23 , V_50 , 7 , V_32 ) ;
F_21 ( L_1 ,
V_32 [ 0 ] , V_32 [ 1 ] , V_32 [ 2 ] , V_32 [ 3 ] , V_32 [ 4 ] , V_32 [ 5 ] , V_32 [ 6 ] ) ;
}
if ( V_34 ) {
V_31 = ( V_31 < 0 ) ? - 1 : 1 ;
F_8 ( V_23 , V_36 , 1 , 0 ) ;
}
V_23 -> V_31 = V_31 ;
return 0 ;
}
static int F_22 ( int V_51 , int V_52 )
{
int V_53 = V_52 < 0 ? - 1 : 1 ;
int V_54 ;
if ( V_51 == 0 )
V_51 = 1000 ;
if ( V_52 < 0 )
V_52 = - V_52 ;
if ( V_51 < 0 )
V_51 = - V_51 ;
if ( V_51 <= V_52 ) {
if ( V_52 > 1500 )
return V_53 * 2000 ;
if ( V_52 > 1000 )
return V_53 * 1500 ;
}
else {
if ( V_52 >= 2000 )
return V_53 * 2000 ;
if ( V_52 >= 1500 )
return V_53 * 1500 ;
if ( V_52 >= 1000 )
return V_53 * 1000 ;
}
if ( V_52 == 0 )
return 1000 ;
if ( V_52 == 1 || V_52 == 1000 )
return V_53 * V_52 ;
V_54 = V_52 ;
V_52 = 1000 / V_52 ;
if ( 1000 / V_51 == V_52 )
V_52 += ( V_51 < V_54 ) ? - 1 : 1 ;
if ( V_52 > 60 ) return 1000 / ( V_53 * 60 ) ;
return 1000 / ( V_53 * V_52 ) ;
}
static int F_23 ( struct V_22 * V_23 , struct V_55 * V_56 ,
struct V_57 * V_58 , int V_59 )
{
struct V_60 * V_54 = & V_23 -> V_61 [ V_62 ] ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
switch ( V_58 -> V_66 ) {
case V_67 : {
V_58 -> V_68 &= V_69 ;
V_58 -> V_70 . V_31 = F_22 ( V_23 -> V_31 , V_58 -> V_70 . V_31 ) ;
if ( V_58 -> V_70 . V_31 < 0 )
V_58 -> V_70 . V_71 = V_72 ;
else
V_58 -> V_70 . V_71 = V_73 ;
if ( V_58 -> V_70 . V_31 != 500 && V_58 -> V_70 . V_31 != 1500 )
V_58 -> V_68 = V_58 -> V_70 . V_31 == 1000 ? 0 :
V_69 ;
if ( V_59 ) break;
V_23 -> V_39 = V_58 -> V_68 & V_69 ;
if ( F_24 ( V_23 , V_74 ) != V_74 )
return - V_75 ;
if ( F_25 ( V_76 , & V_23 -> V_47 ) ) {
V_23 -> V_31 = 0 ;
}
return F_26 ( V_56 , V_58 -> V_70 . V_31 ) ;
}
case V_77 :
V_58 -> V_68 &= V_78 | V_79 ;
if ( V_58 -> V_68 & V_78 )
V_58 -> V_80 . V_81 = 0 ;
if ( V_59 ) break;
if ( F_12 ( & V_23 -> V_40 ) == 0 )
return 0 ;
if ( V_23 -> V_82 != V_74 )
return - V_75 ;
V_23 -> V_82 = V_83 ;
return F_27 ( V_54 , V_58 -> V_68 , V_58 -> V_80 . V_81 ) ;
case V_84 :
V_58 -> V_68 &= V_85 ;
if ( V_59 ) break;
if ( ! F_12 ( & V_23 -> V_40 ) )
return - V_86 ;
if ( V_23 -> V_82 != V_74 )
return - V_75 ;
if ( F_12 ( & V_23 -> V_40 ) > 0 ) {
F_8 ( V_23 , V_42 , 1 ,
( V_58 -> V_68 & V_85 ) ? 1 : 0 ) ;
F_28 ( V_76 , & V_23 -> V_47 ) ;
}
break;
case V_87 :
V_58 -> V_68 = 0 ;
if ( V_59 ) break;
if ( ! F_12 ( & V_23 -> V_40 ) )
return - V_86 ;
if ( V_23 -> V_82 != V_74 )
return - V_75 ;
if ( F_25 ( V_76 , & V_23 -> V_47 ) ) {
int V_31 = V_23 -> V_31 ;
V_23 -> V_31 = 0 ;
return F_26 ( V_56 , V_31 ) ;
}
break;
default:
return - V_65 ;
}
return 0 ;
}
static int F_29 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_16 * V_91 = & V_17 -> V_17 . V_92 ;
V_91 -> V_93 [ 0 ] = 0 ;
V_91 -> V_93 [ 1 ] = 0 ;
if ( ! ( V_23 -> V_63 & V_94 ) )
return - V_65 ;
V_91 -> V_95 = sizeof( struct V_96 ) * 36 ;
memset ( V_91 -> V_21 , 0 , sizeof( V_91 -> V_21 ) ) ;
if ( V_23 -> V_97 ) {
V_91 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_91 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_91 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_91 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
V_91 -> V_18 = F_6 ( V_91 ) ;
return 0 ;
}
static int F_31 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_98 * V_99 = & V_17 -> V_17 . V_100 ;
V_99 -> V_101 = V_23 -> V_37 . V_101 ;
V_99 -> V_102 = V_23 -> V_37 . V_102 ;
V_99 -> V_103 = V_104 ;
V_99 -> V_9 = V_105 ;
if ( V_56 -> type == V_106 ) {
V_99 -> V_107 = V_108 ;
V_99 -> V_109 = V_99 -> V_102 * 720 * 3 / 2 ;
V_99 -> V_110 = 720 ;
} else {
V_99 -> V_107 = V_111 ;
V_99 -> V_109 = 128 * 1024 ;
V_99 -> V_110 = 0 ;
}
return 0 ;
}
static int F_32 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_112 * V_91 = & V_17 -> V_17 . V_113 ;
V_91 -> V_114 = 27000000 ;
V_91 -> V_115 = 248 ;
V_91 -> V_116 = V_23 -> V_113 . V_117 - 4 ;
V_91 -> V_118 = V_119 ;
V_91 -> V_70 [ 0 ] = V_23 -> V_113 . V_70 [ 0 ] ;
V_91 -> V_70 [ 1 ] = V_23 -> V_113 . V_70 [ 1 ] ;
V_91 -> V_120 [ 0 ] = V_91 -> V_120 [ 1 ] = V_23 -> V_113 . V_120 ;
V_91 -> V_68 = 0 ;
V_91 -> V_93 [ 0 ] = 0 ;
V_91 -> V_93 [ 1 ] = 0 ;
return 0 ;
}
static int F_33 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_16 * V_91 = & V_17 -> V_17 . V_92 ;
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
V_91 -> V_93 [ 0 ] = 0 ;
V_91 -> V_93 [ 1 ] = 0 ;
V_91 -> V_95 = sizeof( struct V_96 ) * 36 ;
if ( V_56 -> type == V_121 ) {
V_91 -> V_18 = V_23 -> V_122 ? V_13 :
V_14 ;
F_4 ( V_91 , V_23 -> V_122 ) ;
V_91 -> V_18 = F_6 ( V_91 ) ;
return 0 ;
}
F_34 ( V_23 -> V_123 , V_113 , V_124 , V_91 ) ;
V_91 -> V_18 = F_6 ( V_91 ) ;
return 0 ;
}
static int F_35 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_98 * V_99 = & V_17 -> V_17 . V_100 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_99 -> V_101 = V_23 -> V_125 . V_101 ;
V_99 -> V_102 = V_23 -> V_125 . V_102 ;
V_99 -> V_103 = V_104 ;
V_99 -> V_9 = V_105 ;
if ( V_56 -> type == V_126 ) {
switch ( V_23 -> V_127 . V_128 & V_129 ) {
case V_130 :
V_99 -> V_9 = ( V_23 -> V_127 . V_128 & V_131 ) ?
V_132 : V_133 ;
break;
case V_134 :
V_99 -> V_9 = V_135 ;
break;
default:
V_99 -> V_9 = V_136 ;
break;
}
V_99 -> V_107 = V_108 ;
V_99 -> V_110 = 720 ;
V_99 -> V_101 = V_23 -> V_127 . V_137 ;
V_99 -> V_102 = V_23 -> V_127 . V_138 ;
V_99 -> V_109 =
1080 * ( ( V_99 -> V_102 + 31 ) & ~ 31 ) ;
} else {
V_99 -> V_107 = V_111 ;
V_99 -> V_109 = 128 * 1024 ;
V_99 -> V_110 = 0 ;
}
return 0 ;
}
static int F_36 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_139 * V_140 = & V_17 -> V_17 . V_141 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_140 -> V_142 = V_23 -> V_30 ;
V_140 -> V_143 = V_23 -> V_26 ;
V_140 -> V_9 = V_105 ;
V_140 -> V_144 = NULL ;
V_140 -> V_145 = 0 ;
V_140 -> V_146 = NULL ;
V_140 -> V_147 . V_148 = V_140 -> V_147 . V_149 = 0 ;
V_140 -> V_147 . V_101 = V_23 -> V_150 . V_101 ;
V_140 -> V_147 . V_102 = V_23 -> V_150 . V_102 ;
return 0 ;
}
static int F_37 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
return F_29 ( V_88 , V_89 , V_17 ) ;
}
static int F_38 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
int V_147 = V_17 -> V_17 . V_100 . V_101 ;
int V_151 = V_17 -> V_17 . V_100 . V_102 ;
int V_152 = 2 ;
V_147 = F_39 ( V_147 , 720 ) ;
V_147 = F_40 ( V_147 , 2 ) ;
if ( V_56 -> type == V_106 ) {
V_151 &= ~ 0x1f ;
V_152 = 32 ;
}
V_151 = F_39 ( V_151 , V_23 -> V_122 ? 576 : 480 ) ;
V_151 = F_40 ( V_151 , V_152 ) ;
F_31 ( V_88 , V_89 , V_17 ) ;
V_17 -> V_17 . V_100 . V_101 = V_147 ;
V_17 -> V_17 . V_100 . V_102 = V_151 ;
return 0 ;
}
static int F_41 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
return F_32 ( V_88 , V_89 , V_17 ) ;
}
static int F_42 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_16 * V_91 = & V_17 -> V_17 . V_92 ;
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
if ( V_56 -> type == V_121 )
return F_33 ( V_88 , V_89 , V_17 ) ;
V_91 -> V_95 = sizeof( struct V_96 ) * 36 ;
V_91 -> V_93 [ 0 ] = 0 ;
V_91 -> V_93 [ 1 ] = 0 ;
if ( V_91 -> V_18 )
F_4 ( V_91 , V_23 -> V_122 ) ;
F_5 ( V_91 , V_23 -> V_122 ) ;
V_91 -> V_18 = F_6 ( V_91 ) ;
return 0 ;
}
static int F_43 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
T_3 V_147 = V_17 -> V_17 . V_100 . V_101 ;
T_3 V_151 = V_17 -> V_17 . V_100 . V_102 ;
int V_9 = V_17 -> V_17 . V_100 . V_9 ;
int V_153 = F_35 ( V_88 , V_89 , V_17 ) ;
V_147 = F_39 ( V_147 , 720 ) ;
V_147 = F_40 ( V_147 , 2 ) ;
V_151 = F_39 ( V_151 , 576 ) ;
V_151 = F_40 ( V_151 , 2 ) ;
if ( V_56 -> type == V_126 )
V_17 -> V_17 . V_100 . V_9 = V_9 ;
V_17 -> V_17 . V_100 . V_101 = V_147 ;
V_17 -> V_17 . V_100 . V_102 = V_151 ;
return V_153 ;
}
static int F_44 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_2 V_142 = V_17 -> V_17 . V_141 . V_142 ;
T_4 V_143 = V_17 -> V_17 . V_141 . V_143 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
F_36 ( V_88 , V_89 , V_17 ) ;
V_17 -> V_17 . V_141 . V_142 = V_142 ;
V_17 -> V_17 . V_141 . V_143 = V_143 ;
return 0 ;
}
static int F_45 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
return F_29 ( V_88 , V_89 , V_17 ) ;
}
static int F_46 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_154 V_155 ;
int V_153 = F_38 ( V_88 , V_89 , V_17 ) ;
int V_147 = V_17 -> V_17 . V_100 . V_101 ;
int V_151 = V_17 -> V_17 . V_100 . V_102 ;
if ( V_153 )
return V_153 ;
if ( V_23 -> V_37 . V_101 == V_147 && V_23 -> V_37 . V_102 == V_151 )
return 0 ;
if ( F_12 ( & V_23 -> V_156 ) > 0 )
return - V_75 ;
V_23 -> V_37 . V_101 = V_147 ;
V_23 -> V_37 . V_102 = V_151 ;
if ( F_11 ( V_23 -> V_37 . V_157 ) == V_158 )
V_17 -> V_17 . V_100 . V_101 /= 2 ;
V_155 . V_101 = V_17 -> V_17 . V_100 . V_101 ;
V_155 . V_102 = V_151 ;
V_155 . V_159 = V_160 ;
F_34 ( V_23 -> V_123 , V_161 , V_162 , & V_155 ) ;
return F_31 ( V_88 , V_89 , V_17 ) ;
}
static int F_47 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! F_48 ( V_23 ) && F_12 ( & V_23 -> V_156 ) > 0 )
return - V_75 ;
V_23 -> V_113 . V_163 -> V_18 = 0 ;
V_23 -> V_113 . V_164 . type = V_165 ;
F_34 ( V_23 -> V_123 , V_113 , V_166 , & V_17 -> V_17 . V_113 ) ;
return F_32 ( V_88 , V_89 , V_17 ) ;
}
static int F_49 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_16 * V_91 = & V_17 -> V_17 . V_92 ;
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
int V_153 = F_42 ( V_88 , V_89 , V_17 ) ;
if ( V_153 || V_56 -> type == V_121 )
return V_153 ;
F_5 ( V_91 , V_23 -> V_122 ) ;
if ( F_48 ( V_23 ) && F_12 ( & V_23 -> V_156 ) > 0 )
return - V_75 ;
V_23 -> V_113 . V_164 . type = V_167 ;
F_34 ( V_23 -> V_123 , V_113 , V_168 , V_91 ) ;
memcpy ( V_23 -> V_113 . V_163 , V_91 , sizeof( * V_23 -> V_113 . V_163 ) ) ;
return 0 ;
}
static int F_50 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_153 = F_43 ( V_88 , V_89 , V_17 ) ;
if ( V_153 )
return V_153 ;
if ( V_56 -> type != V_126 )
return 0 ;
if ( V_170 -> V_171 )
return - V_75 ;
V_170 -> V_137 = V_17 -> V_17 . V_100 . V_101 ;
V_170 -> V_138 = V_17 -> V_17 . V_100 . V_102 ;
switch ( V_17 -> V_17 . V_100 . V_9 ) {
case V_135 :
V_170 -> V_128 = V_134 ;
break;
case V_136 :
V_170 -> V_128 = V_172 ;
break;
case V_132 :
V_170 -> V_128 =
V_130 | V_173 ;
break;
case V_133 :
default:
V_170 -> V_128 = V_130 ;
break;
}
V_170 -> V_174 = ( V_170 -> V_128 & V_131 ) == V_175 ? 0 : 1 ;
if ( F_15 ( V_176 , & V_23 -> V_47 ) )
V_23 -> V_177 =
1080 * ( ( V_170 -> V_138 + 31 ) & ~ 31 ) ;
return 0 ;
}
static int F_51 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
int V_153 = F_44 ( V_88 , V_89 , V_17 ) ;
if ( V_153 == 0 ) {
V_23 -> V_30 = V_17 -> V_17 . V_141 . V_142 ;
V_23 -> V_26 = V_17 -> V_17 . V_141 . V_143 ;
F_7 ( V_23 ) ;
}
return V_153 ;
}
static int F_52 ( struct V_22 * V_23 , bool V_178 , T_5 V_179 , T_5 * V_180 )
{
volatile T_4 T_6 * V_181 ;
if ( V_179 & 0x3 )
return - V_65 ;
if ( V_179 >= V_182 && V_179 < V_182 + V_183 )
V_181 = V_23 -> V_184 - V_182 ;
else if ( V_23 -> V_185 && V_179 >= V_186 &&
V_179 < V_186 + V_187 )
V_181 = V_23 -> V_188 - V_186 ;
else if ( V_179 < V_189 )
V_181 = V_23 -> V_190 ;
else
return - V_65 ;
if ( V_178 )
* V_180 = F_53 ( V_179 + V_181 ) ;
else
F_54 ( * V_180 , V_179 + V_181 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_88 , void * V_89 , struct V_191 * V_179 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_179 -> V_192 = 4 ;
return F_52 ( V_23 , true , V_179 -> V_179 , & V_179 -> V_180 ) ;
}
static int F_56 ( struct V_88 * V_88 , void * V_89 , const struct V_191 * V_179 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_5 V_180 = V_179 -> V_180 ;
return F_52 ( V_23 , false , V_179 -> V_179 , & V_180 ) ;
}
static int F_57 ( struct V_88 * V_88 , void * V_89 , struct V_193 * V_194 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_195 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ V_56 -> type ] ;
F_58 ( V_194 -> V_196 , V_197 , sizeof( V_194 -> V_196 ) ) ;
F_58 ( V_194 -> V_198 , V_23 -> V_199 , sizeof( V_194 -> V_198 ) ) ;
snprintf ( V_194 -> V_200 , sizeof( V_194 -> V_200 ) , L_2 , F_59 ( V_23 -> V_201 ) ) ;
V_194 -> V_202 = V_23 -> V_63 | V_203 ;
V_194 -> V_204 = V_54 -> V_205 ;
return 0 ;
}
static int F_60 ( struct V_88 * V_88 , void * V_89 , struct V_206 * V_207 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_61 ( V_23 , V_207 -> V_208 , V_207 ) ;
}
static int F_62 ( struct V_88 * V_88 , void * V_89 , struct V_206 * V_207 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_207 -> V_208 = V_23 -> V_209 ;
return F_61 ( V_23 , V_207 -> V_208 , V_207 ) ;
}
static int F_63 ( struct V_88 * V_88 , void * V_89 , const struct V_206 * V_210 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_210 -> V_208 >= V_23 -> V_211 )
return - V_65 ;
V_23 -> V_209 = V_210 -> V_208 ;
F_64 ( V_23 ) ;
return 0 ;
}
static int F_65 ( struct V_88 * V_88 , void * V_89 , struct V_212 * V_207 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_66 ( V_23 , V_207 -> V_208 , V_207 ) ;
}
static int F_67 ( struct V_88 * V_88 , void * V_89 , struct V_212 * V_207 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_207 -> V_208 = 0 ;
return F_66 ( V_23 , V_207 -> V_208 , V_207 ) ;
}
static int F_68 ( struct V_88 * V_88 , void * V_89 , const struct V_212 * V_210 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_23 -> V_198 -> V_213 == NULL || V_210 -> V_208 != 0 )
return - V_65 ;
return 0 ;
}
static int F_69 ( struct V_88 * V_88 , void * V_89 , struct V_214 * V_207 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_70 ( V_23 , V_207 -> V_208 , V_207 ) ;
}
static int F_71 ( struct V_88 * V_88 , void * V_89 , struct V_215 * V_210 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_72 ( V_23 , V_210 -> V_208 , V_210 ) ;
}
static int F_73 ( struct V_88 * V_88 , void * V_89 , struct V_216 * V_217 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_218 ;
V_218 = V_56 -> type ;
if ( V_217 -> type != V_219 )
return - V_65 ;
V_217 -> V_220 . V_148 = V_217 -> V_220 . V_149 = 0 ;
V_217 -> V_220 . V_101 = 720 ;
if ( V_217 -> type == V_221 ) {
V_217 -> V_220 . V_102 = V_23 -> V_122 ? 576 : 480 ;
V_217 -> V_222 . V_223 = V_23 -> V_122 ? 59 : 10 ;
V_217 -> V_222 . V_224 = V_23 -> V_122 ? 54 : 11 ;
} else if ( V_218 == V_126 ) {
if ( V_170 -> V_225 ) {
V_217 -> V_220 . V_101 = V_170 -> V_226 ;
V_217 -> V_220 . V_102 = V_170 -> V_227 ;
} else {
V_217 -> V_220 . V_101 = 720 ;
V_217 -> V_220 . V_102 =
V_23 -> V_228 ? 576 : 480 ;
}
V_217 -> V_222 . V_223 = V_23 -> V_228 ? 59 : 10 ;
V_217 -> V_222 . V_224 = V_23 -> V_228 ? 54 : 11 ;
} else {
V_217 -> V_220 . V_102 = V_23 -> V_228 ? 576 : 480 ;
V_217 -> V_222 . V_223 = V_23 -> V_228 ? 59 : 10 ;
V_217 -> V_222 . V_224 = V_23 -> V_228 ? 54 : 11 ;
}
V_217 -> V_229 = V_217 -> V_220 ;
return 0 ;
}
static int F_74 ( struct V_88 * V_88 , void * V_89 , const struct V_230 * V_231 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_218 ;
V_218 = V_56 -> type ;
if ( V_231 -> type == V_219 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_218 == V_126 ) {
V_170 -> V_125 = V_231 -> V_232 ;
return 0 ;
} else {
if ( ! F_8 ( V_23 , V_233 , 4 ,
V_231 -> V_232 . V_101 , V_231 -> V_232 . V_102 , V_231 -> V_232 . V_149 , V_231 -> V_232 . V_148 ) ) {
V_23 -> V_125 = V_231 -> V_232 ;
return 0 ;
}
}
return - V_65 ;
}
return - V_65 ;
}
static int F_75 ( struct V_88 * V_88 , void * V_89 , struct V_230 * V_231 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_218 ;
V_218 = V_56 -> type ;
if ( V_231 -> type == V_219 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_218 == V_126 )
V_231 -> V_232 = V_170 -> V_125 ;
else
V_231 -> V_232 = V_23 -> V_125 ;
return 0 ;
}
return - V_65 ;
}
static int F_76 ( struct V_88 * V_88 , void * V_89 , struct V_234 * V_17 )
{
static const struct V_234 V_235 = {
0 , V_221 , 0 ,
L_3 , V_108 ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_234 V_236 = {
0 , V_221 , V_237 ,
L_4 , V_111 ,
{ 0 , 0 , 0 , 0 }
} ;
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_17 -> V_208 )
return - V_65 ;
if ( V_54 -> type == V_238 )
* V_17 = V_236 ;
else if ( V_54 -> type == V_106 )
* V_17 = V_235 ;
else
return - V_65 ;
return 0 ;
}
static int F_77 ( struct V_88 * V_88 , void * V_89 , struct V_234 * V_17 )
{
static const struct V_234 V_235 = {
0 , V_219 , 0 ,
L_3 , V_108 ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_234 V_236 = {
0 , V_219 , V_237 ,
L_4 , V_111 ,
{ 0 , 0 , 0 , 0 }
} ;
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_17 -> V_208 )
return - V_65 ;
if ( V_54 -> type == V_62 )
* V_17 = V_236 ;
else if ( V_54 -> type == V_126 )
* V_17 = V_235 ;
else
return - V_65 ;
return 0 ;
}
static int F_78 ( struct V_88 * V_88 , void * V_89 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
* V_15 = V_23 -> V_239 ;
return 0 ;
}
int F_79 ( struct V_88 * V_88 , void * V_89 , unsigned int V_240 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_7 V_241 ;
int V_15 ;
if ( V_240 >= V_23 -> V_242 )
return - V_65 ;
if ( V_240 == V_23 -> V_239 ) {
F_21 ( L_5 ) ;
return 0 ;
}
if ( F_12 ( & V_23 -> V_156 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_6 ,
V_23 -> V_239 , V_240 ) ;
V_23 -> V_239 = V_240 ;
V_23 -> V_209 = V_23 -> V_198 -> V_243 [ V_240 ] . V_244 ;
if ( V_23 -> V_198 -> V_243 [ V_240 ] . V_245 == V_246 )
V_241 = V_23 -> V_247 ;
else
V_241 = V_248 ;
for ( V_15 = 0 ; V_15 <= V_249 ; V_15 ++ )
V_23 -> V_61 [ V_15 ] . V_250 -> V_251 = V_241 ;
F_80 ( V_23 ) ;
F_81 ( V_23 ) ;
F_64 ( V_23 ) ;
F_82 ( V_23 ) ;
return 0 ;
}
static int F_83 ( struct V_88 * V_88 , void * V_89 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
* V_15 = V_23 -> V_252 ;
return 0 ;
}
static int F_84 ( struct V_88 * V_88 , void * V_89 , unsigned int V_253 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_253 >= V_23 -> V_198 -> V_254 )
return - V_65 ;
if ( V_253 == V_23 -> V_252 ) {
F_21 ( L_7 ) ;
return 0 ;
}
F_21 ( L_8 ,
V_23 -> V_252 , V_253 ) ;
V_23 -> V_252 = V_253 ;
F_85 ( V_23 , V_255 , V_161 , V_256 ,
V_257 ,
V_23 -> V_198 -> V_213 [ V_253 ] . V_258 , 0 ) ;
return 0 ;
}
static int F_86 ( struct V_88 * V_88 , void * V_89 , struct V_259 * V_260 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_54 -> V_250 -> V_261 )
return - V_262 ;
if ( V_260 -> V_263 != 0 )
return - V_65 ;
F_87 ( V_23 , V_263 , V_264 , V_260 ) ;
return 0 ;
}
int F_88 ( struct V_88 * V_88 , void * V_89 , const struct V_259 * V_260 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_54 -> V_250 -> V_261 )
return - V_262 ;
if ( V_260 -> V_263 != 0 )
return - V_65 ;
F_80 ( V_23 ) ;
F_21 ( L_9 , V_260 -> V_265 ) ;
F_87 ( V_23 , V_263 , V_266 , V_260 ) ;
F_82 ( V_23 ) ;
return 0 ;
}
static int F_89 ( struct V_88 * V_88 , void * V_89 , T_7 * V_241 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
* V_241 = V_23 -> V_241 ;
return 0 ;
}
void F_90 ( struct V_22 * V_23 , T_7 V_241 )
{
V_23 -> V_241 = V_241 ;
V_23 -> V_97 = ( V_241 & V_267 ) ? 1 : 0 ;
V_23 -> V_122 = ! V_23 -> V_97 ;
F_91 ( & V_23 -> V_37 , V_23 -> V_122 ) ;
V_23 -> V_37 . V_101 = 720 ;
V_23 -> V_37 . V_102 = V_23 -> V_122 ? 576 : 480 ;
V_23 -> V_113 . V_120 = V_23 -> V_122 ? 18 : 12 ;
V_23 -> V_113 . V_70 [ 0 ] = V_23 -> V_122 ? 6 : 10 ;
V_23 -> V_113 . V_70 [ 1 ] = V_23 -> V_122 ? 318 : 273 ;
if ( V_23 -> V_268 & V_269 )
V_23 -> V_113 . V_270 = V_23 -> V_97 ? 272 : 284 ;
F_87 ( V_23 , V_161 , V_271 , V_23 -> V_241 ) ;
}
void F_92 ( struct V_22 * V_23 , T_7 V_241 )
{
struct V_169 * V_170 = & V_23 -> V_127 ;
F_10 ( V_35 ) ;
int V_19 ;
V_23 -> V_272 = V_241 ;
V_23 -> V_273 = ( V_241 & V_267 ) ? 1 : 0 ;
V_23 -> V_228 = ! V_23 -> V_273 ;
F_87 ( V_23 , V_161 , V_274 , V_23 -> V_272 ) ;
F_13 ( & V_23 -> V_43 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_14 ( & V_23 -> V_275 , & V_35 ,
V_276 ) ;
if ( ( F_93 ( V_277 ) >> 16 ) < 100 )
break;
F_94 ( F_95 ( 25 ) ) ;
}
F_18 ( & V_23 -> V_275 , & V_35 ) ;
F_19 ( & V_23 -> V_43 ) ;
if ( V_19 == 4 )
F_96 ( L_10 ) ;
F_8 ( V_23 , V_278 , 1 , V_23 -> V_228 ) ;
V_23 -> V_125 . V_149 = 0 ;
V_23 -> V_125 . V_148 = 0 ;
V_23 -> V_125 . V_101 = 720 ;
V_23 -> V_125 . V_102 = V_23 -> V_228 ? 576 : 480 ;
F_8 ( V_23 , V_233 , 4 ,
720 , V_23 -> V_125 . V_102 , 0 , 0 ) ;
V_170 -> V_125 = V_23 -> V_125 ;
if ( ! V_23 -> V_279 ) {
V_170 -> V_226 = 720 ;
V_170 -> V_227 = V_23 -> V_228 ? 576 : 480 ;
}
}
static int F_97 ( struct V_88 * V_88 , void * V_89 , T_7 V_241 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ( V_241 & V_248 ) == 0 )
return - V_65 ;
if ( V_241 == V_23 -> V_241 )
return 0 ;
if ( F_15 ( V_280 , & V_23 -> V_47 ) ||
F_12 ( & V_23 -> V_156 ) > 0 ||
F_12 ( & V_23 -> V_40 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_11 ,
( unsigned long long ) V_23 -> V_241 ) ;
F_90 ( V_23 , V_241 ) ;
if ( V_23 -> V_63 & V_64 )
F_92 ( V_23 , V_241 ) ;
return 0 ;
}
static int F_98 ( struct V_88 * V_88 , void * V_89 , const struct V_281 * V_282 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
if ( V_282 -> V_208 != 0 )
return - V_65 ;
F_87 ( V_23 , V_263 , V_283 , V_282 ) ;
return 0 ;
}
static int F_99 ( struct V_88 * V_88 , void * V_89 , struct V_281 * V_282 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_282 -> V_208 != 0 )
return - V_65 ;
F_87 ( V_23 , V_263 , V_284 , V_282 ) ;
if ( V_282 -> type == V_285 )
F_58 ( V_282 -> V_286 , L_12 , sizeof( V_282 -> V_286 ) ) ;
else
F_58 ( V_282 -> V_286 , L_13 , sizeof( V_282 -> V_286 ) ) ;
return 0 ;
}
static int F_100 ( struct V_88 * V_88 , void * V_89 , struct V_287 * V_288 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
int V_11 = V_23 -> V_122 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_288 -> type == V_167 ) {
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_23 -> V_122 ) )
V_288 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
}
}
} else if ( V_288 -> type == V_289 ) {
if ( ! ( V_23 -> V_63 & V_94 ) )
return - V_65 ;
if ( V_23 -> V_97 ) {
V_288 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_288 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_288 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_288 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
} else {
return - V_65 ;
}
V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ )
V_11 |= V_288 -> V_21 [ V_19 ] [ V_20 ] ;
V_288 -> V_18 = V_11 ;
return 0 ;
}
static int F_101 ( struct V_88 * V_88 , void * V_89 , struct V_290 * V_291 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_292 * V_293 = V_291 -> V_294 ;
int V_295 ;
int V_15 ;
V_295 = ( V_23 -> V_296 + V_297 - V_23 -> V_298 ) %
V_297 ;
if ( V_295 > V_299 )
V_295 = V_299 ;
V_291 -> V_295 = 0 ;
V_291 -> V_300 = V_297 ;
if ( ! F_12 ( & V_23 -> V_156 ) )
return 0 ;
for ( V_15 = 0 ; V_15 < V_295 ; V_15 ++ ) {
* V_293 = V_23 -> V_301 [ ( V_23 -> V_298 + V_15 ) % V_297 ] ;
if ( ( V_293 -> V_68 & V_302 ) <= V_303 ) {
V_291 -> V_295 ++ ;
V_293 ++ ;
}
}
V_23 -> V_298 = ( V_23 -> V_298 + V_291 -> V_295 ) % V_297 ;
return 0 ;
}
static int F_102 ( struct V_88 * V_88 , void * V_89 , struct V_304 * V_305 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
switch ( V_305 -> V_66 ) {
case V_306 :
F_103 ( L_14 ) ;
V_305 -> V_68 = 0 ;
return F_104 ( V_56 ) ;
case V_307 :
F_103 ( L_15 ) ;
V_305 -> V_68 &= V_308 ;
F_105 ( V_56 , V_305 -> V_68 & V_308 ) ;
return 0 ;
case V_309 :
F_103 ( L_16 ) ;
V_305 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_156 ) )
return - V_86 ;
if ( F_106 ( V_310 , & V_23 -> V_47 ) )
return 0 ;
F_80 ( V_23 ) ;
F_8 ( V_23 , V_311 , 1 , 0 ) ;
break;
case V_312 :
F_103 ( L_17 ) ;
V_305 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_156 ) )
return - V_86 ;
if ( ! F_25 ( V_310 , & V_23 -> V_47 ) )
return 0 ;
F_8 ( V_23 , V_311 , 1 , 1 ) ;
F_82 ( V_23 ) ;
break;
default:
F_103 ( L_18 , V_305 -> V_66 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_107 ( struct V_88 * V_88 , void * V_89 , struct V_304 * V_305 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
switch ( V_305 -> V_66 ) {
case V_306 :
F_103 ( L_14 ) ;
V_305 -> V_68 = 0 ;
return 0 ;
case V_307 :
F_103 ( L_15 ) ;
V_305 -> V_68 &= V_308 ;
return 0 ;
case V_309 :
F_103 ( L_16 ) ;
V_305 -> V_68 = 0 ;
return 0 ;
case V_312 :
F_103 ( L_17 ) ;
V_305 -> V_68 = 0 ;
return 0 ;
default:
F_103 ( L_18 , V_305 -> V_66 ) ;
return - V_65 ;
}
}
static int F_108 ( struct V_88 * V_88 , void * V_89 , struct V_313 * V_314 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_99 ;
static T_2 V_315 [ 16 ] = {
V_316 ,
V_317 ,
V_318 ,
V_319 ,
V_320 ,
0 ,
0 ,
0 ,
V_316 ,
V_321 ,
V_322 ,
V_323 ,
V_324 ,
0 ,
0 ,
0 ,
} ;
if ( ! ( V_23 -> V_63 & V_325 ) )
return - V_65 ;
if ( ! V_23 -> V_326 )
return - V_65 ;
V_314 -> V_327 = V_328 | V_329 |
V_330 ;
F_109 ( V_23 , V_32 , V_331 , 0 ) ;
V_32 [ 0 ] |= ( F_93 ( 0x2a00 ) >> 7 ) & 0x40 ;
V_99 = ( V_32 [ 0 ] >> 3 ) & 0xf ;
V_314 -> V_17 . V_107 = V_315 [ V_99 ] ;
V_314 -> V_17 . V_101 = V_23 -> V_150 . V_101 ;
V_314 -> V_17 . V_102 = V_23 -> V_150 . V_102 ;
V_314 -> V_17 . V_9 = V_105 ;
V_314 -> V_17 . V_110 = V_314 -> V_17 . V_101 ;
V_314 -> V_17 . V_103 = V_104 ;
V_314 -> V_17 . V_9 = V_105 ;
if ( V_314 -> V_17 . V_107 != V_316 )
V_314 -> V_17 . V_110 *= 2 ;
if ( V_314 -> V_17 . V_107 == V_320 ||
V_314 -> V_17 . V_107 == V_324 )
V_314 -> V_17 . V_110 *= 2 ;
V_314 -> V_17 . V_109 = V_314 -> V_17 . V_110 * V_314 -> V_17 . V_102 ;
V_314 -> V_332 = ( void * ) V_23 -> V_326 ;
V_314 -> V_68 = 0 ;
if ( V_23 -> V_29 )
V_314 -> V_68 |= V_333 ;
if ( V_23 -> V_25 )
V_314 -> V_68 |= V_334 ;
if ( V_170 -> V_225 )
V_314 -> V_68 |= V_335 ;
V_99 &= 7 ;
if ( V_99 == 1 || V_99 > 4 )
return 0 ;
if ( V_99 == 2 || V_99 == 3 )
V_314 -> V_327 |= V_336 ;
else
V_314 -> V_327 |= V_337 ;
if ( V_23 -> V_27 ) {
if ( V_99 == 2 || V_99 == 3 )
V_314 -> V_68 |= V_338 ;
else
V_314 -> V_68 |= V_339 ;
}
return 0 ;
}
static int F_110 ( struct V_88 * V_88 , void * V_89 , const struct V_313 * V_314 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
if ( ! ( V_23 -> V_63 & V_325 ) )
return - V_65 ;
if ( ! V_23 -> V_326 )
return - V_65 ;
V_23 -> V_25 = ( V_314 -> V_68 & V_334 ) != 0 ;
V_23 -> V_27 =
( V_314 -> V_68 & ( V_339 | V_338 ) ) != 0 ;
V_23 -> V_29 = ( V_314 -> V_68 & V_333 ) != 0 ;
F_7 ( V_23 ) ;
V_170 -> V_225 = ( V_314 -> V_68 & V_335 ) != 0 ;
return 0 ;
}
static int F_111 ( struct V_88 * V_88 , void * V_89 , unsigned int V_340 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
if ( ! ( V_23 -> V_63 & V_325 ) )
return - V_65 ;
F_8 ( V_23 , V_341 , 1 , V_340 != 0 ) ;
return 0 ;
}
static int F_112 ( struct V_342 * V_89 , const struct V_343 * V_344 )
{
switch ( V_344 -> type ) {
case V_345 :
case V_346 :
return F_113 ( V_89 , V_344 , 0 , NULL ) ;
case V_347 :
return F_113 ( V_89 , V_344 , 0 , & V_348 ) ;
default:
return - V_65 ;
}
}
static int F_114 ( struct V_88 * V_88 , void * V_89 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
int V_349 = V_23 -> V_63 & V_64 ;
struct V_214 V_350 ;
struct V_206 V_351 ;
int V_15 ;
F_115 ( L_19 , V_352 , V_23 -> V_199 ) ;
if ( V_23 -> V_268 & V_353 ) {
struct V_354 V_355 ;
F_116 ( V_23 , & V_355 ) ;
}
F_87 ( V_23 , V_356 , V_357 ) ;
F_70 ( V_23 , V_23 -> V_239 , & V_350 ) ;
F_61 ( V_23 , V_23 -> V_209 , & V_351 ) ;
F_115 ( L_20 , V_350 . V_286 ) ;
F_115 ( L_21 , V_351 . V_286 ,
( V_23 -> V_358 & ~ 0x300 ) == 0x200 ? L_22 : L_23 ) ;
if ( V_349 ) {
struct V_215 V_359 ;
struct V_212 V_360 ;
int V_361 = V_23 -> V_82 ;
static const char * const V_362 [ 5 ] = {
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
} ;
static const char * const V_363 [ 4 ] = {
L_24 ,
L_29 ,
L_30 ,
L_31
} ;
static const char * const V_315 [ 16 ] = {
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
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
} ;
F_72 ( V_23 , V_23 -> V_252 , & V_359 ) ;
F_66 ( V_23 , 0 , & V_360 ) ;
F_115 ( L_48 , V_359 . V_286 ) ;
if ( V_361 < 0 || V_361 > V_364 )
V_361 = V_83 ;
F_115 ( L_49 , V_362 [ V_361 ] ) ;
F_109 ( V_23 , V_32 , V_331 , 0 ) ;
V_32 [ 0 ] |= ( F_93 ( 0x2a00 ) >> 7 ) & 0x40 ;
F_115 ( L_50 ,
V_32 [ 0 ] & 1 ? L_51 : L_52 ,
V_363 [ ( V_32 [ 0 ] >> 1 ) & 0x3 ] ,
V_315 [ ( V_32 [ 0 ] >> 3 ) & 0xf ] ) ;
}
F_115 ( L_53 ,
F_15 ( V_280 , & V_23 -> V_47 ) ? L_54 : L_55 ) ;
F_117 ( & V_23 -> V_37 . V_365 , V_23 -> V_366 . V_286 ) ;
F_115 ( L_56 , V_23 -> V_47 ) ;
for ( V_15 = 0 ; V_15 < V_367 ; V_15 ++ ) {
struct V_60 * V_54 = & V_23 -> V_61 [ V_15 ] ;
if ( V_54 -> V_250 == NULL || V_54 -> V_368 == 0 )
continue;
F_115 ( L_57 , V_54 -> V_286 , V_54 -> V_369 ,
( V_54 -> V_368 - V_54 -> V_370 . V_368 ) * 100 / V_54 -> V_368 ,
( V_54 -> V_368 * V_54 -> V_371 ) / 1024 , V_54 -> V_368 ) ;
}
F_115 ( L_58 ,
( long long ) V_23 -> V_372 ,
( long long ) V_23 -> V_373 ) ;
return 0 ;
}
static int F_118 ( struct V_88 * V_88 , void * V_89 , struct V_57 * V_374 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_195 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
F_103 ( L_59 , V_374 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_374 , false ) ;
}
static int F_119 ( struct V_88 * V_88 , void * V_89 , struct V_57 * V_374 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_195 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
F_103 ( L_60 , V_374 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_374 , true ) ;
}
static int F_120 ( struct V_88 * V_375 , unsigned int V_66 , void * V_376 )
{
struct V_55 * V_56 = F_30 ( V_375 -> V_195 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
int V_377 = V_375 -> V_378 & V_379 ;
struct V_60 * V_54 = & V_23 -> V_61 [ V_56 -> type ] ;
unsigned long V_380 = ( unsigned long ) V_376 ;
switch ( V_66 ) {
case V_381 : {
struct V_382 * args = V_376 ;
F_103 ( L_61 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( args -> type != V_219 )
return - V_65 ;
if ( V_23 -> V_82 == V_383 && args -> V_384 == NULL )
return 0 ;
if ( F_26 ( V_56 , V_56 -> type ) ) {
return - V_75 ;
}
if ( F_24 ( V_23 , V_383 ) != V_383 ) {
F_121 ( V_54 ) ;
return - V_75 ;
}
V_56 -> V_385 = 1 ;
if ( args -> V_384 == NULL )
return 0 ;
return F_122 ( V_23 , args ) ;
}
case V_386 :
F_103 ( L_62 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_123 ( V_23 , * ( int * ) V_376 != 0 ) ;
case V_387 : {
T_8 * V_81 = V_376 ;
T_8 V_388 ;
F_103 ( L_63 ) ;
if ( V_54 -> type < V_62 ) {
* V_81 = V_54 -> V_389 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_124 ( V_23 , V_81 , & V_388 ) ;
}
case V_390 : {
T_8 * V_388 = V_376 ;
T_8 V_81 ;
F_103 ( L_64 ) ;
if ( V_54 -> type < V_62 ) {
* V_388 = 0 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_124 ( V_23 , & V_81 , V_388 ) ;
}
case V_391 : {
struct V_57 V_58 ;
F_103 ( L_65 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_67 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_392 : {
struct V_57 V_58 ;
F_103 ( L_66 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_77 ;
V_58 . V_68 = V_79 | V_78 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_393 : {
struct V_57 V_58 ;
F_103 ( L_67 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_84 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_394 : {
struct V_57 V_58 ;
F_103 ( L_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_87 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_395 :
case V_396 : {
struct V_57 * V_58 = V_376 ;
int V_59 = ( V_66 == V_396 ) ;
if ( V_59 )
F_103 ( L_69 , V_58 -> V_66 ) ;
else
F_103 ( L_70 , V_58 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_58 , V_59 ) ;
}
case V_397 : {
struct V_398 * V_399 = V_376 ;
F_10 ( V_35 ) ;
F_103 ( L_71 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
memset ( V_399 , 0 , sizeof( * V_399 ) ) ;
F_28 ( V_400 , & V_23 -> V_47 ) ;
while ( 1 ) {
if ( F_25 ( V_401 , & V_23 -> V_47 ) )
V_399 -> type = V_402 ;
else if ( F_25 ( V_403 , & V_23 -> V_47 ) ) {
V_399 -> type = V_404 ;
V_399 -> V_405 . V_406 = F_15 ( V_407 , & V_23 -> V_47 ) ?
V_408 : V_409 ;
if ( V_23 -> V_82 == V_383 &&
( V_23 -> V_127 . V_128 & V_129 ) ==
V_134 ) {
V_399 -> V_405 . V_406 = V_410 ;
}
}
if ( V_399 -> type )
return 0 ;
if ( V_377 )
return - V_411 ;
F_13 ( & V_23 -> V_43 ) ;
F_14 ( & V_23 -> V_412 , & V_35 , V_45 ) ;
if ( ! F_15 ( V_401 , & V_23 -> V_47 ) &&
! F_15 ( V_403 , & V_23 -> V_47 ) )
F_17 () ;
F_18 ( & V_23 -> V_412 , & V_35 ) ;
F_19 ( & V_23 -> V_43 ) ;
if ( F_16 ( V_48 ) ) {
F_21 ( L_72 ) ;
return - V_49 ;
}
}
break;
}
case V_413 :
F_103 ( L_73 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_123 ( V_23 , V_380 == V_414 ) ;
case V_415 :
F_103 ( L_74 ) ;
V_23 -> V_39 = V_380 ;
return 0 ;
case V_416 :
F_103 ( L_75 ) ;
if ( V_380 > V_417 )
return - V_65 ;
return F_125 ( V_23 -> V_418 , V_380 + 1 ) ;
case V_419 :
F_103 ( L_76 ) ;
if ( V_380 > V_417 )
return - V_65 ;
return F_125 ( V_23 -> V_420 , V_380 + 1 ) ;
default:
return - V_65 ;
}
return 0 ;
}
static long F_126 ( struct V_88 * V_88 , void * V_89 , bool V_421 ,
unsigned int V_66 , void * V_376 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! V_421 ) {
switch ( V_66 ) {
case V_386 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_413 :
case V_415 :
case V_416 :
case V_419 :
return - V_75 ;
}
}
switch ( V_66 ) {
case V_422 : {
T_2 V_180 = * ( T_2 * ) V_376 ;
if ( ( V_180 == 0 && V_23 -> V_423 . V_424 ) || ( V_180 & 0x01 ) )
F_127 ( V_23 ) ;
if ( V_180 & 0x02 )
F_34 ( V_23 -> V_123 , V_356 , V_425 , 0 ) ;
break;
}
case V_381 :
case V_386 :
case V_387 :
case V_390 :
case V_397 :
case V_391 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_413 :
case V_415 :
case V_416 :
case V_419 :
return F_120 ( V_88 , V_66 , ( void * ) V_376 ) ;
default:
return - V_262 ;
}
return 0 ;
}
void F_128 ( struct V_426 * V_250 )
{
V_250 -> V_427 = & V_428 ;
}
