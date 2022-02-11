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
V_61 -> V_68 &= V_69 ;
V_61 -> V_70 . V_31 = F_22 ( V_23 -> V_31 , V_61 -> V_70 . V_31 ) ;
if ( V_61 -> V_70 . V_31 < 0 )
V_61 -> V_70 . V_71 = V_72 ;
else
V_61 -> V_70 . V_71 = V_73 ;
if ( V_61 -> V_70 . V_31 != 500 && V_61 -> V_70 . V_31 != 1500 )
V_61 -> V_68 = V_61 -> V_70 . V_31 == 1000 ? 0 :
V_69 ;
if ( V_62 ) break;
V_23 -> V_43 = V_61 -> V_68 & V_69 ;
if ( F_24 ( V_23 , V_74 ) != V_74 )
return - V_75 ;
if ( F_25 ( V_76 , & V_23 -> V_51 ) ) {
V_23 -> V_31 = 0 ;
}
return F_26 ( V_59 , V_61 -> V_70 . V_31 ) ;
}
case V_77 :
V_61 -> V_68 &= V_78 | V_79 ;
if ( V_61 -> V_68 & V_78 )
V_61 -> V_80 . V_81 = 0 ;
if ( V_62 ) break;
if ( F_12 ( & V_23 -> V_44 ) == 0 )
return 0 ;
if ( V_23 -> V_82 != V_74 )
return - V_75 ;
V_23 -> V_82 = V_83 ;
return F_27 ( V_35 , V_61 -> V_68 , V_61 -> V_80 . V_81 ) ;
case V_84 :
V_61 -> V_68 &= V_85 ;
if ( V_62 ) break;
if ( V_23 -> V_82 != V_74 )
return - V_75 ;
if ( F_12 ( & V_23 -> V_44 ) > 0 ) {
F_8 ( V_23 , V_46 , 1 ,
( V_61 -> V_68 & V_85 ) ? 1 : 0 ) ;
F_28 ( V_76 , & V_23 -> V_51 ) ;
}
break;
case V_86 :
V_61 -> V_68 = 0 ;
if ( V_62 ) break;
if ( V_23 -> V_82 != V_74 )
return - V_75 ;
if ( F_25 ( V_76 , & V_23 -> V_51 ) ) {
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
static int F_29 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
struct V_16 * V_90 = & V_17 -> V_17 . V_91 ;
V_90 -> V_92 [ 0 ] = 0 ;
V_90 -> V_92 [ 1 ] = 0 ;
if ( ! ( V_23 -> V_63 & V_93 ) )
return - V_65 ;
V_90 -> V_94 = sizeof( struct V_95 ) * 36 ;
if ( V_23 -> V_96 ) {
V_90 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_90 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_90 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_90 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
V_90 -> V_18 = F_6 ( V_90 ) ;
return 0 ;
}
static int F_31 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_97 * V_98 = & V_17 -> V_17 . V_99 ;
V_98 -> V_100 = V_23 -> V_41 . V_100 ;
V_98 -> V_101 = V_23 -> V_41 . V_101 ;
V_98 -> V_102 = V_103 ;
V_98 -> V_9 = V_104 ;
V_98 -> V_105 = 0 ;
if ( V_59 -> type == V_106 ) {
V_98 -> V_107 = V_108 ;
V_98 -> V_109 = V_98 -> V_101 * 720 * 3 / 2 ;
V_98 -> V_110 = 720 ;
} else {
V_98 -> V_107 = V_111 ;
V_98 -> V_109 = 128 * 1024 ;
V_98 -> V_110 = 0 ;
}
return 0 ;
}
static int F_32 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
struct V_112 * V_90 = & V_17 -> V_17 . V_113 ;
V_90 -> V_114 = 27000000 ;
V_90 -> V_115 = 248 ;
V_90 -> V_116 = V_23 -> V_113 . V_117 - 4 ;
V_90 -> V_118 = V_119 ;
V_90 -> V_70 [ 0 ] = V_23 -> V_113 . V_70 [ 0 ] ;
V_90 -> V_70 [ 1 ] = V_23 -> V_113 . V_70 [ 1 ] ;
V_90 -> V_120 [ 0 ] = V_90 -> V_120 [ 1 ] = V_23 -> V_113 . V_120 ;
V_90 -> V_68 = 0 ;
V_90 -> V_92 [ 0 ] = 0 ;
V_90 -> V_92 [ 1 ] = 0 ;
return 0 ;
}
static int F_33 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_16 * V_90 = & V_17 -> V_17 . V_91 ;
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
V_90 -> V_92 [ 0 ] = 0 ;
V_90 -> V_92 [ 1 ] = 0 ;
V_90 -> V_94 = sizeof( struct V_95 ) * 36 ;
if ( V_59 -> type == V_121 ) {
V_90 -> V_18 = V_23 -> V_122 ? V_13 :
V_14 ;
F_4 ( V_90 , V_23 -> V_122 ) ;
return 0 ;
}
F_34 ( V_23 -> V_123 , V_113 , V_124 , V_90 ) ;
V_90 -> V_18 = F_6 ( V_90 ) ;
return 0 ;
}
static int F_35 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_97 * V_98 = & V_17 -> V_17 . V_99 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_98 -> V_100 = V_23 -> V_125 . V_100 ;
V_98 -> V_101 = V_23 -> V_125 . V_101 ;
V_98 -> V_102 = V_103 ;
V_98 -> V_9 = V_104 ;
V_98 -> V_105 = 0 ;
if ( V_59 -> type == V_126 ) {
switch ( V_23 -> V_127 . V_128 & V_129 ) {
case V_130 :
V_98 -> V_9 = ( V_23 -> V_127 . V_128 & V_131 ) ?
V_132 : V_133 ;
break;
case V_134 :
V_98 -> V_9 = V_135 ;
break;
default:
V_98 -> V_9 = V_136 ;
break;
}
V_98 -> V_107 = V_108 ;
V_98 -> V_110 = 720 ;
V_98 -> V_100 = V_23 -> V_127 . V_137 ;
V_98 -> V_101 = V_23 -> V_127 . V_138 ;
V_98 -> V_109 =
1080 * ( ( V_98 -> V_101 + 31 ) & ~ 31 ) ;
} else {
V_98 -> V_107 = V_111 ;
V_98 -> V_109 = 128 * 1024 ;
V_98 -> V_110 = 0 ;
}
return 0 ;
}
static int F_36 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
struct V_139 * V_140 = & V_17 -> V_17 . V_141 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_140 -> V_142 = V_23 -> V_30 ;
V_140 -> V_143 = V_23 -> V_26 ;
V_140 -> V_9 = V_104 ;
V_140 -> V_144 = NULL ;
V_140 -> V_145 = 0 ;
V_140 -> V_146 = NULL ;
V_140 -> V_147 . V_148 = V_140 -> V_147 . V_149 = 0 ;
V_140 -> V_147 . V_100 = V_23 -> V_150 . V_100 ;
V_140 -> V_147 . V_101 = V_23 -> V_150 . V_101 ;
return 0 ;
}
static int F_37 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
return F_29 ( V_87 , V_88 , V_17 ) ;
}
static int F_38 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
int V_147 = V_17 -> V_17 . V_99 . V_100 ;
int V_151 = V_17 -> V_17 . V_99 . V_101 ;
int V_152 = 2 ;
V_147 = F_39 ( V_147 , 720 ) ;
V_147 = F_40 ( V_147 , 2 ) ;
if ( V_59 -> type == V_106 ) {
V_151 &= ~ 0x1f ;
V_152 = 32 ;
}
V_151 = F_39 ( V_151 , V_23 -> V_122 ? 576 : 480 ) ;
V_151 = F_40 ( V_151 , V_152 ) ;
F_31 ( V_87 , V_88 , V_17 ) ;
V_17 -> V_17 . V_99 . V_100 = V_147 ;
V_17 -> V_17 . V_99 . V_101 = V_151 ;
return 0 ;
}
static int F_41 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
return F_32 ( V_87 , V_88 , V_17 ) ;
}
static int F_42 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_16 * V_90 = & V_17 -> V_17 . V_91 ;
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
if ( V_59 -> type == V_121 )
return F_33 ( V_87 , V_88 , V_17 ) ;
V_90 -> V_94 = sizeof( struct V_95 ) * 36 ;
V_90 -> V_92 [ 0 ] = 0 ;
V_90 -> V_92 [ 1 ] = 0 ;
if ( V_90 -> V_18 )
F_4 ( V_90 , V_23 -> V_122 ) ;
F_5 ( V_90 , V_23 -> V_122 ) ;
V_90 -> V_18 = F_6 ( V_90 ) ;
return 0 ;
}
static int F_43 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
T_3 V_147 = V_17 -> V_17 . V_99 . V_100 ;
T_3 V_151 = V_17 -> V_17 . V_99 . V_101 ;
int V_9 = V_17 -> V_17 . V_99 . V_9 ;
int V_153 = F_35 ( V_87 , V_88 , V_17 ) ;
V_147 = F_39 ( V_147 , 720 ) ;
V_147 = F_40 ( V_147 , 2 ) ;
V_151 = F_39 ( V_151 , 576 ) ;
V_151 = F_40 ( V_151 , 2 ) ;
if ( V_59 -> type == V_126 )
V_17 -> V_17 . V_99 . V_9 = V_9 ;
V_17 -> V_17 . V_99 . V_100 = V_147 ;
V_17 -> V_17 . V_99 . V_101 = V_151 ;
return V_153 ;
}
static int F_44 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
T_2 V_142 = V_17 -> V_17 . V_141 . V_142 ;
T_4 V_143 = V_17 -> V_17 . V_141 . V_143 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
F_36 ( V_87 , V_88 , V_17 ) ;
V_17 -> V_17 . V_141 . V_142 = V_142 ;
V_17 -> V_17 . V_141 . V_143 = V_143 ;
return 0 ;
}
static int F_45 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
return F_29 ( V_87 , V_88 , V_17 ) ;
}
static int F_46 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_154 V_155 ;
int V_153 = F_38 ( V_87 , V_88 , V_17 ) ;
int V_147 = V_17 -> V_17 . V_99 . V_100 ;
int V_151 = V_17 -> V_17 . V_99 . V_101 ;
if ( V_153 )
return V_153 ;
if ( V_23 -> V_41 . V_100 == V_147 && V_23 -> V_41 . V_101 == V_151 )
return 0 ;
if ( F_12 ( & V_23 -> V_156 ) > 0 )
return - V_75 ;
V_23 -> V_41 . V_100 = V_147 ;
V_23 -> V_41 . V_101 = V_151 ;
if ( F_11 ( V_23 -> V_41 . V_157 ) == V_158 )
V_17 -> V_17 . V_99 . V_100 /= 2 ;
V_155 . V_100 = V_17 -> V_17 . V_99 . V_100 ;
V_155 . V_101 = V_151 ;
V_155 . V_159 = V_160 ;
F_34 ( V_23 -> V_123 , V_161 , V_162 , & V_155 ) ;
return F_31 ( V_87 , V_88 , V_17 ) ;
}
static int F_47 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( ! F_48 ( V_23 ) && F_12 ( & V_23 -> V_156 ) > 0 )
return - V_75 ;
V_23 -> V_113 . V_163 -> V_18 = 0 ;
V_23 -> V_113 . V_164 . type = V_165 ;
F_34 ( V_23 -> V_123 , V_113 , V_166 , & V_17 -> V_17 . V_113 ) ;
return F_32 ( V_87 , V_88 , V_17 ) ;
}
static int F_49 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_16 * V_90 = & V_17 -> V_17 . V_91 ;
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
int V_153 = F_42 ( V_87 , V_88 , V_17 ) ;
if ( V_153 || V_59 -> type == V_121 )
return V_153 ;
F_5 ( V_90 , V_23 -> V_122 ) ;
if ( F_48 ( V_23 ) && F_12 ( & V_23 -> V_156 ) > 0 )
return - V_75 ;
V_23 -> V_113 . V_164 . type = V_167 ;
F_34 ( V_23 -> V_123 , V_113 , V_168 , V_90 ) ;
memcpy ( V_23 -> V_113 . V_163 , V_90 , sizeof( * V_23 -> V_113 . V_163 ) ) ;
return 0 ;
}
static int F_50 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_153 = F_43 ( V_87 , V_88 , V_17 ) ;
if ( V_153 )
return V_153 ;
if ( V_59 -> type != V_126 )
return 0 ;
if ( V_170 -> V_171 )
return - V_75 ;
V_170 -> V_137 = V_17 -> V_17 . V_99 . V_100 ;
V_170 -> V_138 = V_17 -> V_17 . V_99 . V_101 ;
switch ( V_17 -> V_17 . V_99 . V_9 ) {
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
if ( F_15 ( V_176 , & V_23 -> V_51 ) )
V_23 -> V_177 =
1080 * ( ( V_170 -> V_138 + 31 ) & ~ 31 ) ;
return 0 ;
}
static int F_51 ( struct V_87 * V_87 , void * V_88 , struct V_89 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
int V_153 = F_44 ( V_87 , V_88 , V_17 ) ;
if ( V_153 == 0 ) {
V_23 -> V_30 = V_17 -> V_17 . V_141 . V_142 ;
V_23 -> V_26 = V_17 -> V_17 . V_141 . V_143 ;
F_7 ( V_23 ) ;
}
return V_153 ;
}
static int F_52 ( struct V_87 * V_87 , void * V_88 , struct V_178 * V_179 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
V_179 -> V_180 = V_181 ;
V_179 -> V_182 = 0 ;
if ( V_179 -> V_183 . type == V_184 ) {
if ( F_53 ( & V_179 -> V_183 ) )
V_179 -> V_180 = V_23 -> V_185 ? V_186 : V_187 ;
return 0 ;
}
if ( V_179 -> V_183 . type != V_188 &&
V_179 -> V_183 . type != V_189 )
return - V_65 ;
return F_54 ( V_23 , V_190 , V_191 , V_179 ) ;
}
static int F_55 ( struct V_22 * V_23 , unsigned int V_66 , void * V_192 )
{
struct V_193 * V_194 = V_192 ;
volatile T_4 T_5 * V_195 ;
if ( ! F_56 ( V_196 ) )
return - V_197 ;
if ( V_194 -> V_198 >= V_199 && V_194 -> V_198 < V_199 + V_200 )
V_195 = V_23 -> V_201 - V_199 ;
else if ( V_23 -> V_185 && V_194 -> V_198 >= V_202 &&
V_194 -> V_198 < V_202 + V_203 )
V_195 = V_23 -> V_204 - V_202 ;
else if ( V_194 -> V_198 < V_205 )
V_195 = V_23 -> V_206 ;
else
return - V_65 ;
V_194 -> V_207 = 4 ;
if ( V_66 == V_208 )
V_194 -> V_209 = F_57 ( V_194 -> V_198 + V_195 ) ;
else
F_58 ( V_194 -> V_209 , V_194 -> V_198 + V_195 ) ;
return 0 ;
}
static int F_59 ( struct V_87 * V_87 , void * V_88 , struct V_193 * V_198 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( F_53 ( & V_198 -> V_183 ) )
return F_55 ( V_23 , V_208 , V_198 ) ;
F_60 ( V_23 , V_190 , V_210 , V_198 ) ;
return 0 ;
}
static int F_61 ( struct V_87 * V_87 , void * V_88 , struct V_193 * V_198 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( F_53 ( & V_198 -> V_183 ) )
return F_55 ( V_23 , V_211 , V_198 ) ;
F_60 ( V_23 , V_190 , V_212 , V_198 ) ;
return 0 ;
}
static int F_62 ( struct V_87 * V_87 , void * V_88 , struct V_213 * V_214 )
{
struct V_58 * V_59 = F_30 ( V_87 -> V_215 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_34 * V_35 = & V_23 -> V_38 [ V_59 -> type ] ;
F_63 ( V_214 -> V_216 , V_217 , sizeof( V_214 -> V_216 ) ) ;
F_63 ( V_214 -> V_218 , V_23 -> V_219 , sizeof( V_214 -> V_218 ) ) ;
snprintf ( V_214 -> V_220 , sizeof( V_214 -> V_220 ) , L_2 , F_64 ( V_23 -> V_221 ) ) ;
V_214 -> V_222 = V_23 -> V_63 | V_223 ;
V_214 -> V_224 = V_35 -> V_225 ;
return 0 ;
}
static int F_65 ( struct V_87 * V_87 , void * V_88 , struct V_226 * V_227 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
return F_66 ( V_23 , V_227 -> V_228 , V_227 ) ;
}
static int F_67 ( struct V_87 * V_87 , void * V_88 , struct V_226 * V_227 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
V_227 -> V_228 = V_23 -> V_229 ;
return F_66 ( V_23 , V_227 -> V_228 , V_227 ) ;
}
static int F_68 ( struct V_87 * V_87 , void * V_88 , struct V_226 * V_230 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( V_230 -> V_228 >= V_23 -> V_231 )
return - V_65 ;
V_23 -> V_229 = V_230 -> V_228 ;
F_69 ( V_23 ) ;
return 0 ;
}
static int F_70 ( struct V_87 * V_87 , void * V_88 , struct V_232 * V_227 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
return F_71 ( V_23 , V_227 -> V_228 , V_227 ) ;
}
static int F_72 ( struct V_87 * V_87 , void * V_88 , struct V_232 * V_227 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
V_227 -> V_228 = 0 ;
return F_71 ( V_23 , V_227 -> V_228 , V_227 ) ;
}
static int F_73 ( struct V_87 * V_87 , void * V_88 , struct V_232 * V_230 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
return F_71 ( V_23 , V_230 -> V_228 , V_230 ) ;
}
static int F_74 ( struct V_87 * V_87 , void * V_88 , struct V_233 * V_227 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
return F_75 ( V_23 , V_227 -> V_228 , V_227 ) ;
}
static int F_76 ( struct V_87 * V_87 , void * V_88 , struct V_234 * V_230 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
return F_77 ( V_23 , V_230 -> V_228 , V_230 ) ;
}
static int F_78 ( struct V_87 * V_87 , void * V_88 , struct V_235 * V_236 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_237 ;
V_237 = V_59 -> type ;
if ( V_236 -> type != V_238 )
return - V_65 ;
V_236 -> V_239 . V_148 = V_236 -> V_239 . V_149 = 0 ;
V_236 -> V_239 . V_100 = 720 ;
if ( V_236 -> type == V_240 ) {
V_236 -> V_239 . V_101 = V_23 -> V_122 ? 576 : 480 ;
V_236 -> V_241 . V_242 = V_23 -> V_122 ? 59 : 10 ;
V_236 -> V_241 . V_243 = V_23 -> V_122 ? 54 : 11 ;
} else if ( V_237 == V_126 ) {
if ( V_170 -> V_244 ) {
V_236 -> V_239 . V_100 = V_170 -> V_245 ;
V_236 -> V_239 . V_101 = V_170 -> V_246 ;
} else {
V_236 -> V_239 . V_100 = 720 ;
V_236 -> V_239 . V_101 =
V_23 -> V_247 ? 576 : 480 ;
}
V_236 -> V_241 . V_242 = V_23 -> V_247 ? 59 : 10 ;
V_236 -> V_241 . V_243 = V_23 -> V_247 ? 54 : 11 ;
} else {
V_236 -> V_239 . V_101 = V_23 -> V_247 ? 576 : 480 ;
V_236 -> V_241 . V_242 = V_23 -> V_247 ? 59 : 10 ;
V_236 -> V_241 . V_243 = V_23 -> V_247 ? 54 : 11 ;
}
V_236 -> V_248 = V_236 -> V_239 ;
return 0 ;
}
static int F_79 ( struct V_87 * V_87 , void * V_88 , struct V_249 * V_250 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_237 ;
V_237 = V_59 -> type ;
if ( V_250 -> type == V_238 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_237 == V_126 ) {
V_170 -> V_125 = V_250 -> V_251 ;
return 0 ;
} else {
if ( ! F_8 ( V_23 , V_252 , 4 ,
V_250 -> V_251 . V_100 , V_250 -> V_251 . V_101 , V_250 -> V_251 . V_149 , V_250 -> V_251 . V_148 ) ) {
V_23 -> V_125 = V_250 -> V_251 ;
return 0 ;
}
}
return - V_65 ;
}
return - V_65 ;
}
static int F_80 ( struct V_87 * V_87 , void * V_88 , struct V_249 * V_250 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_237 ;
V_237 = V_59 -> type ;
if ( V_250 -> type == V_238 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_237 == V_126 )
V_250 -> V_251 = V_170 -> V_125 ;
else
V_250 -> V_251 = V_23 -> V_125 ;
return 0 ;
}
return - V_65 ;
}
static int F_81 ( struct V_87 * V_87 , void * V_88 , struct V_253 * V_17 )
{
static struct V_253 V_254 [] = {
{ 0 , 0 , 0 ,
L_3 , V_108 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_255 ,
L_4 , V_111 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_256 type = V_17 -> type ;
if ( V_17 -> V_228 > 1 )
return - V_65 ;
* V_17 = V_254 [ V_17 -> V_228 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_82 ( struct V_87 * V_87 , void * V_88 , struct V_253 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
static struct V_253 V_254 [] = {
{ 0 , 0 , 0 ,
L_3 , V_108 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_255 ,
L_4 , V_111 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_256 type = V_17 -> type ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( V_17 -> V_228 > 1 )
return - V_65 ;
* V_17 = V_254 [ V_17 -> V_228 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_83 ( struct V_87 * V_87 , void * V_88 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
* V_15 = V_23 -> V_257 ;
return 0 ;
}
int F_84 ( struct V_87 * V_87 , void * V_88 , unsigned int V_258 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( V_258 < 0 || V_258 >= V_23 -> V_259 )
return - V_65 ;
if ( V_258 == V_23 -> V_257 ) {
F_21 ( L_5 ) ;
return 0 ;
}
if ( F_12 ( & V_23 -> V_156 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_6 ,
V_23 -> V_257 , V_258 ) ;
V_23 -> V_257 = V_258 ;
V_23 -> V_229 = V_23 -> V_218 -> V_260 [ V_258 ] . V_261 ;
F_85 ( V_23 ) ;
F_86 ( V_23 ) ;
F_69 ( V_23 ) ;
F_87 ( V_23 ) ;
return 0 ;
}
static int F_88 ( struct V_87 * V_87 , void * V_88 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
* V_15 = V_23 -> V_262 ;
return 0 ;
}
static int F_89 ( struct V_87 * V_87 , void * V_88 , unsigned int V_263 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( V_263 >= V_23 -> V_218 -> V_264 )
return - V_65 ;
if ( V_263 == V_23 -> V_262 ) {
F_21 ( L_7 ) ;
return 0 ;
}
F_21 ( L_8 ,
V_23 -> V_262 , V_263 ) ;
V_23 -> V_262 = V_263 ;
F_90 ( V_23 , V_265 , V_161 , V_266 ,
V_267 ,
V_23 -> V_218 -> V_268 [ V_263 ] . V_269 , 0 ) ;
return 0 ;
}
static int F_91 ( struct V_87 * V_87 , void * V_88 , struct V_270 * V_271 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( V_271 -> V_272 != 0 )
return - V_65 ;
F_60 ( V_23 , V_272 , V_273 , V_271 ) ;
return 0 ;
}
int F_92 ( struct V_87 * V_87 , void * V_88 , struct V_270 * V_271 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( V_271 -> V_272 != 0 )
return - V_65 ;
F_85 ( V_23 ) ;
F_21 ( L_9 , V_271 -> V_274 ) ;
F_60 ( V_23 , V_272 , V_275 , V_271 ) ;
F_87 ( V_23 ) ;
return 0 ;
}
static int F_93 ( struct V_87 * V_87 , void * V_88 , T_6 * V_276 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
* V_276 = V_23 -> V_276 ;
return 0 ;
}
void F_94 ( struct V_22 * V_23 , T_6 * V_276 )
{
V_23 -> V_276 = * V_276 ;
V_23 -> V_96 = ( * V_276 & V_277 ) ? 1 : 0 ;
V_23 -> V_122 = ! V_23 -> V_96 ;
F_95 ( & V_23 -> V_41 , V_23 -> V_122 ) ;
V_23 -> V_41 . V_100 = 720 ;
V_23 -> V_41 . V_101 = V_23 -> V_122 ? 576 : 480 ;
V_23 -> V_113 . V_120 = V_23 -> V_122 ? 18 : 12 ;
V_23 -> V_113 . V_70 [ 0 ] = V_23 -> V_122 ? 6 : 10 ;
V_23 -> V_113 . V_70 [ 1 ] = V_23 -> V_122 ? 318 : 273 ;
if ( V_23 -> V_278 & V_279 )
V_23 -> V_113 . V_280 = V_23 -> V_96 ? 272 : 284 ;
F_60 ( V_23 , V_190 , V_281 , V_23 -> V_276 ) ;
}
void F_96 ( struct V_22 * V_23 , T_6 * V_276 )
{
struct V_169 * V_170 = & V_23 -> V_127 ;
F_10 ( V_37 ) ;
int V_19 ;
V_23 -> V_282 = * V_276 ;
V_23 -> V_283 = ( * V_276 & V_277 ) ? 1 : 0 ;
V_23 -> V_247 = ! V_23 -> V_283 ;
F_60 ( V_23 , V_161 , V_284 , V_23 -> V_282 ) ;
F_13 ( & V_23 -> V_47 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_14 ( & V_23 -> V_285 , & V_37 ,
V_286 ) ;
if ( ( F_97 ( V_287 ) >> 16 ) < 100 )
break;
F_98 ( F_99 ( 25 ) ) ;
}
F_18 ( & V_23 -> V_285 , & V_37 ) ;
F_19 ( & V_23 -> V_47 ) ;
if ( V_19 == 4 )
F_100 ( L_10 ) ;
F_8 ( V_23 , V_288 , 1 , V_23 -> V_247 ) ;
V_23 -> V_125 . V_149 = 0 ;
V_23 -> V_125 . V_148 = 0 ;
V_23 -> V_125 . V_100 = 720 ;
V_23 -> V_125 . V_101 = V_23 -> V_247 ? 576 : 480 ;
F_8 ( V_23 , V_252 , 4 ,
720 , V_23 -> V_125 . V_101 , 0 , 0 ) ;
V_170 -> V_125 = V_23 -> V_125 ;
if ( ! V_23 -> V_289 ) {
V_170 -> V_245 = 720 ;
V_170 -> V_246 = V_23 -> V_247 ? 576 : 480 ;
}
}
int F_101 ( struct V_87 * V_87 , void * V_88 , T_6 * V_276 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( ( * V_276 & V_290 ) == 0 )
return - V_65 ;
if ( * V_276 == V_23 -> V_276 )
return 0 ;
if ( F_15 ( V_291 , & V_23 -> V_51 ) ||
F_12 ( & V_23 -> V_156 ) > 0 ||
F_12 ( & V_23 -> V_44 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_11 ,
( unsigned long long ) V_23 -> V_276 ) ;
F_94 ( V_23 , V_276 ) ;
if ( V_23 -> V_63 & V_64 )
F_96 ( V_23 , V_276 ) ;
return 0 ;
}
static int F_102 ( struct V_87 * V_87 , void * V_88 , struct V_292 * V_293 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
if ( V_293 -> V_228 != 0 )
return - V_65 ;
F_60 ( V_23 , V_272 , V_294 , V_293 ) ;
return 0 ;
}
static int F_103 ( struct V_87 * V_87 , void * V_88 , struct V_292 * V_293 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( V_293 -> V_228 != 0 )
return - V_65 ;
F_60 ( V_23 , V_272 , V_295 , V_293 ) ;
if ( V_293 -> type == V_296 )
F_63 ( V_293 -> V_297 , L_12 , sizeof( V_293 -> V_297 ) ) ;
else
F_63 ( V_293 -> V_297 , L_13 , sizeof( V_293 -> V_297 ) ) ;
return 0 ;
}
static int F_104 ( struct V_87 * V_87 , void * V_88 , struct V_298 * V_299 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
int V_11 = V_23 -> V_122 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_299 -> type == V_167 ) {
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_23 -> V_122 ) )
V_299 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
}
}
} else if ( V_299 -> type == V_300 ) {
if ( ! ( V_23 -> V_63 & V_93 ) )
return - V_65 ;
if ( V_23 -> V_96 ) {
V_299 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_299 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_299 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_299 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
} else {
return - V_65 ;
}
V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ )
V_11 |= V_299 -> V_21 [ V_19 ] [ V_20 ] ;
V_299 -> V_18 = V_11 ;
return 0 ;
}
static int F_105 ( struct V_87 * V_87 , void * V_88 , struct V_301 * V_302 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
struct V_303 * V_304 = V_302 -> V_305 ;
int V_306 ;
int V_15 ;
V_306 = ( V_23 -> V_307 + V_308 - V_23 -> V_309 ) %
V_308 ;
if ( V_306 > V_310 )
V_306 = V_310 ;
V_302 -> V_306 = 0 ;
for ( V_15 = 0 ; V_15 < V_306 ; V_15 ++ ) {
* V_304 = V_23 -> V_311 [ ( V_23 -> V_309 + V_15 ) % V_308 ] ;
if ( ( V_304 -> V_68 & V_312 ) <= V_313 ) {
V_302 -> V_306 ++ ;
V_304 ++ ;
}
}
V_23 -> V_309 = ( V_23 -> V_309 + V_302 -> V_306 ) % V_308 ;
return 0 ;
}
static int F_106 ( struct V_87 * V_87 , void * V_88 , struct V_314 * V_315 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
switch ( V_315 -> V_66 ) {
case V_316 :
F_107 ( L_14 ) ;
V_315 -> V_68 = 0 ;
return F_108 ( V_59 ) ;
case V_317 :
F_107 ( L_15 ) ;
V_315 -> V_68 &= V_318 ;
F_109 ( V_59 , V_315 -> V_68 & V_318 ) ;
return 0 ;
case V_319 :
F_107 ( L_16 ) ;
V_315 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_156 ) )
return - V_197 ;
if ( F_110 ( V_320 , & V_23 -> V_51 ) )
return 0 ;
F_85 ( V_23 ) ;
F_8 ( V_23 , V_321 , 1 , 0 ) ;
break;
case V_322 :
F_107 ( L_17 ) ;
V_315 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_156 ) )
return - V_197 ;
if ( ! F_25 ( V_320 , & V_23 -> V_51 ) )
return 0 ;
F_8 ( V_23 , V_321 , 1 , 1 ) ;
F_87 ( V_23 ) ;
break;
default:
F_107 ( L_18 , V_315 -> V_66 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_111 ( struct V_87 * V_87 , void * V_88 , struct V_314 * V_315 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
switch ( V_315 -> V_66 ) {
case V_316 :
F_107 ( L_14 ) ;
V_315 -> V_68 = 0 ;
return 0 ;
case V_317 :
F_107 ( L_15 ) ;
V_315 -> V_68 &= V_318 ;
return 0 ;
case V_319 :
F_107 ( L_16 ) ;
V_315 -> V_68 = 0 ;
return 0 ;
case V_322 :
F_107 ( L_17 ) ;
V_315 -> V_68 = 0 ;
return 0 ;
default:
F_107 ( L_18 , V_315 -> V_66 ) ;
return - V_65 ;
}
}
static int F_112 ( struct V_87 * V_87 , void * V_88 , struct V_323 * V_324 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
struct V_169 * V_170 = & V_23 -> V_127 ;
int V_98 ;
static T_2 V_325 [ 16 ] = {
V_326 ,
V_327 ,
V_328 ,
V_329 ,
V_330 ,
0 ,
0 ,
0 ,
V_326 ,
V_331 ,
V_332 ,
V_333 ,
V_334 ,
0 ,
0 ,
0 ,
} ;
if ( ! ( V_23 -> V_63 & V_335 ) )
return - V_65 ;
if ( ! V_23 -> V_336 )
return - V_65 ;
V_324 -> V_337 = V_338 | V_339 |
V_340 ;
F_113 ( V_23 , V_32 , V_341 , 0 ) ;
V_32 [ 0 ] |= ( F_97 ( 0x2a00 ) >> 7 ) & 0x40 ;
V_98 = ( V_32 [ 0 ] >> 3 ) & 0xf ;
V_324 -> V_17 . V_107 = V_325 [ V_98 ] ;
V_324 -> V_17 . V_100 = V_23 -> V_150 . V_100 ;
V_324 -> V_17 . V_101 = V_23 -> V_150 . V_101 ;
V_324 -> V_17 . V_9 = V_104 ;
V_324 -> V_17 . V_110 = V_324 -> V_17 . V_100 ;
V_324 -> V_17 . V_102 = V_103 ;
V_324 -> V_17 . V_9 = V_104 ;
V_324 -> V_17 . V_105 = 0 ;
if ( V_324 -> V_17 . V_107 != V_326 )
V_324 -> V_17 . V_110 *= 2 ;
if ( V_324 -> V_17 . V_107 == V_330 ||
V_324 -> V_17 . V_107 == V_334 )
V_324 -> V_17 . V_110 *= 2 ;
V_324 -> V_17 . V_109 = V_324 -> V_17 . V_110 * V_324 -> V_17 . V_101 ;
V_324 -> V_342 = ( void * ) V_23 -> V_336 ;
V_324 -> V_68 = 0 ;
if ( V_23 -> V_29 )
V_324 -> V_68 |= V_343 ;
if ( V_23 -> V_25 )
V_324 -> V_68 |= V_344 ;
if ( V_170 -> V_244 )
V_324 -> V_68 |= V_345 ;
V_98 &= 7 ;
if ( V_98 == 1 || V_98 > 4 )
return 0 ;
if ( V_98 == 2 || V_98 == 3 )
V_324 -> V_337 |= V_346 ;
else
V_324 -> V_337 |= V_347 ;
if ( V_23 -> V_27 ) {
if ( V_98 == 2 || V_98 == 3 )
V_324 -> V_68 |= V_348 ;
else
V_324 -> V_68 |= V_349 ;
}
return 0 ;
}
static int F_114 ( struct V_87 * V_87 , void * V_88 , struct V_323 * V_324 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
struct V_169 * V_170 = & V_23 -> V_127 ;
if ( ! ( V_23 -> V_63 & V_335 ) )
return - V_65 ;
if ( ! V_23 -> V_336 )
return - V_65 ;
V_23 -> V_25 = ( V_324 -> V_68 & V_344 ) != 0 ;
V_23 -> V_27 =
( V_324 -> V_68 & ( V_349 | V_348 ) ) != 0 ;
V_23 -> V_29 = ( V_324 -> V_68 & V_343 ) != 0 ;
F_7 ( V_23 ) ;
V_170 -> V_244 = ( V_324 -> V_68 & V_345 ) != 0 ;
return F_112 ( V_87 , V_88 , V_324 ) ;
}
static int F_115 ( struct V_87 * V_87 , void * V_88 , unsigned int V_350 )
{
struct V_58 * V_59 = F_30 ( V_88 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
if ( ! ( V_23 -> V_63 & V_335 ) )
return - V_65 ;
F_8 ( V_23 , V_351 , 1 , V_350 != 0 ) ;
return 0 ;
}
static int F_116 ( struct V_352 * V_88 , struct V_353 * V_354 )
{
switch ( V_354 -> type ) {
case V_355 :
case V_356 :
case V_357 :
return F_117 ( V_88 , V_354 , 0 ) ;
default:
return - V_65 ;
}
}
static int F_118 ( struct V_87 * V_87 , void * V_88 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
int V_358 = V_23 -> V_63 & V_64 ;
struct V_233 V_359 ;
struct V_226 V_360 ;
int V_15 ;
F_119 ( L_19 , V_361 , V_23 -> V_219 ) ;
if ( V_23 -> V_278 & V_362 ) {
struct V_363 V_364 ;
F_120 ( V_23 , & V_364 ) ;
}
F_60 ( V_23 , V_190 , V_365 ) ;
F_75 ( V_23 , V_23 -> V_257 , & V_359 ) ;
F_66 ( V_23 , V_23 -> V_229 , & V_360 ) ;
F_119 ( L_20 , V_359 . V_297 ) ;
F_119 ( L_21 , V_360 . V_297 ,
( V_23 -> V_366 & ~ 0x300 ) == 0x200 ? L_22 : L_23 ) ;
if ( V_358 ) {
struct V_234 V_367 ;
struct V_232 V_368 ;
int V_369 = V_23 -> V_82 ;
static const char * const V_370 [ 5 ] = {
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
} ;
static const char * const V_371 [ 4 ] = {
L_24 ,
L_29 ,
L_30 ,
L_31
} ;
static const char * const V_325 [ 16 ] = {
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
F_77 ( V_23 , V_23 -> V_262 , & V_367 ) ;
F_71 ( V_23 , 0 , & V_368 ) ;
F_119 ( L_48 , V_367 . V_297 ) ;
if ( V_369 < 0 || V_369 > V_372 )
V_369 = V_83 ;
F_119 ( L_49 , V_370 [ V_369 ] ) ;
F_113 ( V_23 , V_32 , V_341 , 0 ) ;
V_32 [ 0 ] |= ( F_97 ( 0x2a00 ) >> 7 ) & 0x40 ;
F_119 ( L_50 ,
V_32 [ 0 ] & 1 ? L_51 : L_52 ,
V_371 [ ( V_32 [ 0 ] >> 1 ) & 0x3 ] ,
V_325 [ ( V_32 [ 0 ] >> 3 ) & 0xf ] ) ;
}
F_119 ( L_53 ,
F_15 ( V_291 , & V_23 -> V_51 ) ? L_54 : L_55 ) ;
F_121 ( & V_23 -> V_41 . V_373 , V_23 -> V_374 . V_297 ) ;
F_119 ( L_56 , V_23 -> V_51 ) ;
for ( V_15 = 0 ; V_15 < V_375 ; V_15 ++ ) {
struct V_34 * V_35 = & V_23 -> V_38 [ V_15 ] ;
if ( V_35 -> V_376 == NULL || V_35 -> V_377 == 0 )
continue;
F_119 ( L_57 , V_35 -> V_297 , V_35 -> V_378 ,
( V_35 -> V_377 - V_35 -> V_379 . V_377 ) * 100 / V_35 -> V_377 ,
( V_35 -> V_377 * V_35 -> V_380 ) / 1024 , V_35 -> V_377 ) ;
}
F_119 ( L_58 ,
( long long ) V_23 -> V_381 ,
( long long ) V_23 -> V_382 ) ;
return 0 ;
}
static int F_122 ( struct V_87 * V_87 , void * V_88 , struct V_60 * V_383 )
{
struct V_58 * V_59 = F_30 ( V_87 -> V_215 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
F_107 ( L_59 , V_383 -> V_66 ) ;
return F_23 ( V_23 , V_59 , V_383 , false ) ;
}
static int F_123 ( struct V_87 * V_87 , void * V_88 , struct V_60 * V_383 )
{
struct V_58 * V_59 = F_30 ( V_87 -> V_215 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
F_107 ( L_60 , V_383 -> V_66 ) ;
return F_23 ( V_23 , V_59 , V_383 , true ) ;
}
static int F_124 ( struct V_87 * V_384 , unsigned int V_66 , void * V_192 )
{
struct V_58 * V_59 = F_30 ( V_384 -> V_215 ) ;
struct V_22 * V_23 = V_59 -> V_23 ;
int V_385 = V_384 -> V_386 & V_387 ;
struct V_34 * V_35 = & V_23 -> V_38 [ V_59 -> type ] ;
unsigned long V_388 = ( unsigned long ) V_192 ;
switch ( V_66 ) {
case V_389 : {
struct V_390 * args = V_192 ;
F_107 ( L_61 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( args -> type != V_238 )
return - V_65 ;
if ( V_23 -> V_82 == V_391 && args -> V_392 == NULL )
return 0 ;
if ( F_26 ( V_59 , V_59 -> type ) ) {
return - V_75 ;
}
if ( F_24 ( V_23 , V_391 ) != V_391 ) {
F_125 ( V_35 ) ;
return - V_75 ;
}
V_59 -> V_393 = 1 ;
if ( args -> V_392 == NULL )
return 0 ;
return F_126 ( V_23 , args ) ;
}
case V_394 :
F_107 ( L_62 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_127 ( V_23 , * ( int * ) V_192 != 0 ) ;
case V_395 : {
T_7 * V_81 = V_192 ;
T_7 V_396 ;
F_107 ( L_63 ) ;
if ( V_35 -> type < V_39 ) {
* V_81 = V_35 -> V_397 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_128 ( V_23 , V_81 , & V_396 ) ;
}
case V_398 : {
T_7 * V_396 = V_192 ;
T_7 V_81 ;
F_107 ( L_64 ) ;
if ( V_35 -> type < V_39 ) {
* V_396 = 0 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_128 ( V_23 , & V_81 , V_396 ) ;
}
case V_399 : {
struct V_60 V_61 ;
F_107 ( L_65 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_67 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_400 : {
struct V_60 V_61 ;
F_107 ( L_66 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_77 ;
V_61 . V_68 = V_79 | V_78 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_401 : {
struct V_60 V_61 ;
F_107 ( L_67 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_84 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_402 : {
struct V_60 V_61 ;
F_107 ( L_68 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_66 = V_86 ;
return F_23 ( V_23 , V_59 , & V_61 , 0 ) ;
}
case V_403 :
case V_404 : {
struct V_60 * V_61 = V_192 ;
int V_62 = ( V_66 == V_404 ) ;
if ( V_62 )
F_107 ( L_69 , V_61 -> V_66 ) ;
else
F_107 ( L_70 , V_61 -> V_66 ) ;
return F_23 ( V_23 , V_59 , V_61 , V_62 ) ;
}
case V_405 : {
struct V_406 * V_407 = V_192 ;
F_10 ( V_37 ) ;
F_107 ( L_71 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
memset ( V_407 , 0 , sizeof( * V_407 ) ) ;
F_28 ( V_408 , & V_23 -> V_51 ) ;
while ( 1 ) {
if ( F_25 ( V_409 , & V_23 -> V_51 ) )
V_407 -> type = V_410 ;
else if ( F_25 ( V_411 , & V_23 -> V_51 ) ) {
V_407 -> type = V_412 ;
V_407 -> V_413 . V_414 = F_15 ( V_415 , & V_23 -> V_51 ) ?
V_416 : V_417 ;
if ( V_23 -> V_82 == V_391 &&
( V_23 -> V_127 . V_128 & V_129 ) ==
V_134 ) {
V_407 -> V_413 . V_414 = V_418 ;
}
}
if ( V_407 -> type )
return 0 ;
if ( V_385 )
return - V_419 ;
F_13 ( & V_23 -> V_47 ) ;
F_14 ( & V_23 -> V_420 , & V_37 , V_49 ) ;
if ( ! F_15 ( V_409 , & V_23 -> V_51 ) &&
! F_15 ( V_411 , & V_23 -> V_51 ) )
F_17 () ;
F_18 ( & V_23 -> V_420 , & V_37 ) ;
F_19 ( & V_23 -> V_47 ) ;
if ( F_16 ( V_52 ) ) {
F_21 ( L_72 ) ;
return - V_53 ;
}
}
break;
}
case V_421 :
F_107 ( L_73 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_127 ( V_23 , V_388 == V_422 ) ;
case V_423 :
F_107 ( L_74 ) ;
V_23 -> V_43 = V_388 ;
return 0 ;
case V_424 :
F_107 ( L_75 ) ;
if ( V_388 > V_425 )
return - V_65 ;
return F_129 ( V_23 -> V_426 , V_388 + 1 ) ;
case V_427 :
F_107 ( L_76 ) ;
if ( V_388 > V_425 )
return - V_65 ;
return F_129 ( V_23 -> V_428 , V_388 + 1 ) ;
default:
return - V_65 ;
}
return 0 ;
}
static long F_130 ( struct V_87 * V_87 , void * V_88 , bool V_429 ,
int V_66 , void * V_192 )
{
struct V_22 * V_23 = F_30 ( V_88 ) -> V_23 ;
if ( ! V_429 ) {
switch ( V_66 ) {
case V_394 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_421 :
case V_423 :
case V_424 :
case V_427 :
return - V_75 ;
}
}
switch ( V_66 ) {
case V_430 : {
T_2 V_209 = * ( T_2 * ) V_192 ;
if ( ( V_209 == 0 && V_23 -> V_431 . V_432 ) || ( V_209 & 0x01 ) )
F_131 ( V_23 ) ;
if ( V_209 & 0x02 )
F_34 ( V_23 -> V_123 , V_190 , V_433 , 0 ) ;
break;
}
case V_389 :
case V_394 :
case V_395 :
case V_398 :
case V_405 :
case V_399 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_421 :
case V_423 :
case V_424 :
case V_427 :
return F_124 ( V_87 , V_66 , ( void * ) V_192 ) ;
default:
return - V_65 ;
}
return 0 ;
}
long F_132 ( struct V_87 * V_384 , unsigned int V_66 , unsigned long V_192 )
{
struct V_434 * V_435 = F_133 ( V_384 ) ;
long V_153 ;
if ( V_436 & V_437 )
V_435 -> V_438 = V_439 | V_440 ;
V_153 = F_134 ( V_384 , V_66 , V_192 ) ;
V_435 -> V_438 = 0 ;
return V_153 ;
}
void F_135 ( struct V_434 * V_376 )
{
V_376 -> V_441 = & V_442 ;
}
