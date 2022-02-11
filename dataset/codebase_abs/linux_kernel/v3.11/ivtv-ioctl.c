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
V_99 -> V_106 = 0 ;
if ( V_56 -> type == V_107 ) {
V_99 -> V_108 = V_109 ;
V_99 -> V_110 = V_99 -> V_102 * 720 * 3 / 2 ;
V_99 -> V_111 = 720 ;
} else {
V_99 -> V_108 = V_112 ;
V_99 -> V_110 = 128 * 1024 ;
V_99 -> V_111 = 0 ;
}
return 0 ;
}
static int F_32 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_113 * V_91 = & V_17 -> V_17 . V_114 ;
V_91 -> V_115 = 27000000 ;
V_91 -> V_116 = 248 ;
V_91 -> V_117 = V_23 -> V_114 . V_118 - 4 ;
V_91 -> V_119 = V_120 ;
V_91 -> V_70 [ 0 ] = V_23 -> V_114 . V_70 [ 0 ] ;
V_91 -> V_70 [ 1 ] = V_23 -> V_114 . V_70 [ 1 ] ;
V_91 -> V_121 [ 0 ] = V_91 -> V_121 [ 1 ] = V_23 -> V_114 . V_121 ;
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
if ( V_56 -> type == V_122 ) {
V_91 -> V_18 = V_23 -> V_123 ? V_13 :
V_14 ;
F_4 ( V_91 , V_23 -> V_123 ) ;
V_91 -> V_18 = F_6 ( V_91 ) ;
return 0 ;
}
F_34 ( V_23 -> V_124 , V_114 , V_125 , V_91 ) ;
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
V_99 -> V_101 = V_23 -> V_126 . V_101 ;
V_99 -> V_102 = V_23 -> V_126 . V_102 ;
V_99 -> V_103 = V_104 ;
V_99 -> V_9 = V_105 ;
V_99 -> V_106 = 0 ;
if ( V_56 -> type == V_127 ) {
switch ( V_23 -> V_128 . V_129 & V_130 ) {
case V_131 :
V_99 -> V_9 = ( V_23 -> V_128 . V_129 & V_132 ) ?
V_133 : V_134 ;
break;
case V_135 :
V_99 -> V_9 = V_136 ;
break;
default:
V_99 -> V_9 = V_137 ;
break;
}
V_99 -> V_108 = V_109 ;
V_99 -> V_111 = 720 ;
V_99 -> V_101 = V_23 -> V_128 . V_138 ;
V_99 -> V_102 = V_23 -> V_128 . V_139 ;
V_99 -> V_110 =
1080 * ( ( V_99 -> V_102 + 31 ) & ~ 31 ) ;
} else {
V_99 -> V_108 = V_112 ;
V_99 -> V_110 = 128 * 1024 ;
V_99 -> V_111 = 0 ;
}
return 0 ;
}
static int F_36 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_140 * V_141 = & V_17 -> V_17 . V_142 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_141 -> V_143 = V_23 -> V_30 ;
V_141 -> V_144 = V_23 -> V_26 ;
V_141 -> V_9 = V_105 ;
V_141 -> V_145 = NULL ;
V_141 -> V_146 = 0 ;
V_141 -> V_147 = NULL ;
V_141 -> V_148 . V_149 = V_141 -> V_148 . V_150 = 0 ;
V_141 -> V_148 . V_101 = V_23 -> V_151 . V_101 ;
V_141 -> V_148 . V_102 = V_23 -> V_151 . V_102 ;
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
int V_148 = V_17 -> V_17 . V_100 . V_101 ;
int V_152 = V_17 -> V_17 . V_100 . V_102 ;
int V_153 = 2 ;
V_148 = F_39 ( V_148 , 720 ) ;
V_148 = F_40 ( V_148 , 2 ) ;
if ( V_56 -> type == V_107 ) {
V_152 &= ~ 0x1f ;
V_153 = 32 ;
}
V_152 = F_39 ( V_152 , V_23 -> V_123 ? 576 : 480 ) ;
V_152 = F_40 ( V_152 , V_153 ) ;
F_31 ( V_88 , V_89 , V_17 ) ;
V_17 -> V_17 . V_100 . V_101 = V_148 ;
V_17 -> V_17 . V_100 . V_102 = V_152 ;
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
if ( V_56 -> type == V_122 )
return F_33 ( V_88 , V_89 , V_17 ) ;
V_91 -> V_95 = sizeof( struct V_96 ) * 36 ;
V_91 -> V_93 [ 0 ] = 0 ;
V_91 -> V_93 [ 1 ] = 0 ;
if ( V_91 -> V_18 )
F_4 ( V_91 , V_23 -> V_123 ) ;
F_5 ( V_91 , V_23 -> V_123 ) ;
V_91 -> V_18 = F_6 ( V_91 ) ;
return 0 ;
}
static int F_43 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
T_3 V_148 = V_17 -> V_17 . V_100 . V_101 ;
T_3 V_152 = V_17 -> V_17 . V_100 . V_102 ;
int V_9 = V_17 -> V_17 . V_100 . V_9 ;
int V_154 = F_35 ( V_88 , V_89 , V_17 ) ;
V_148 = F_39 ( V_148 , 720 ) ;
V_148 = F_40 ( V_148 , 2 ) ;
V_152 = F_39 ( V_152 , 576 ) ;
V_152 = F_40 ( V_152 , 2 ) ;
if ( V_56 -> type == V_127 )
V_17 -> V_17 . V_100 . V_9 = V_9 ;
V_17 -> V_17 . V_100 . V_101 = V_148 ;
V_17 -> V_17 . V_100 . V_102 = V_152 ;
return V_154 ;
}
static int F_44 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_2 V_143 = V_17 -> V_17 . V_142 . V_143 ;
T_4 V_144 = V_17 -> V_17 . V_142 . V_144 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
F_36 ( V_88 , V_89 , V_17 ) ;
V_17 -> V_17 . V_142 . V_143 = V_143 ;
V_17 -> V_17 . V_142 . V_144 = V_144 ;
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
struct V_155 V_156 ;
int V_154 = F_38 ( V_88 , V_89 , V_17 ) ;
int V_148 = V_17 -> V_17 . V_100 . V_101 ;
int V_152 = V_17 -> V_17 . V_100 . V_102 ;
if ( V_154 )
return V_154 ;
if ( V_23 -> V_37 . V_101 == V_148 && V_23 -> V_37 . V_102 == V_152 )
return 0 ;
if ( F_12 ( & V_23 -> V_157 ) > 0 )
return - V_75 ;
V_23 -> V_37 . V_101 = V_148 ;
V_23 -> V_37 . V_102 = V_152 ;
if ( F_11 ( V_23 -> V_37 . V_158 ) == V_159 )
V_17 -> V_17 . V_100 . V_101 /= 2 ;
V_156 . V_101 = V_17 -> V_17 . V_100 . V_101 ;
V_156 . V_102 = V_152 ;
V_156 . V_160 = V_161 ;
F_34 ( V_23 -> V_124 , V_162 , V_163 , & V_156 ) ;
return F_31 ( V_88 , V_89 , V_17 ) ;
}
static int F_47 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! F_48 ( V_23 ) && F_12 ( & V_23 -> V_157 ) > 0 )
return - V_75 ;
V_23 -> V_114 . V_164 -> V_18 = 0 ;
V_23 -> V_114 . V_165 . type = V_166 ;
F_34 ( V_23 -> V_124 , V_114 , V_167 , & V_17 -> V_17 . V_114 ) ;
return F_32 ( V_88 , V_89 , V_17 ) ;
}
static int F_49 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_16 * V_91 = & V_17 -> V_17 . V_92 ;
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
int V_154 = F_42 ( V_88 , V_89 , V_17 ) ;
if ( V_154 || V_56 -> type == V_122 )
return V_154 ;
F_5 ( V_91 , V_23 -> V_123 ) ;
if ( F_48 ( V_23 ) && F_12 ( & V_23 -> V_157 ) > 0 )
return - V_75 ;
V_23 -> V_114 . V_165 . type = V_168 ;
F_34 ( V_23 -> V_124 , V_114 , V_169 , V_91 ) ;
memcpy ( V_23 -> V_114 . V_164 , V_91 , sizeof( * V_23 -> V_114 . V_164 ) ) ;
return 0 ;
}
static int F_50 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_170 * V_171 = & V_23 -> V_128 ;
int V_154 = F_43 ( V_88 , V_89 , V_17 ) ;
if ( V_154 )
return V_154 ;
if ( V_56 -> type != V_127 )
return 0 ;
if ( V_171 -> V_172 )
return - V_75 ;
V_171 -> V_138 = V_17 -> V_17 . V_100 . V_101 ;
V_171 -> V_139 = V_17 -> V_17 . V_100 . V_102 ;
switch ( V_17 -> V_17 . V_100 . V_9 ) {
case V_136 :
V_171 -> V_129 = V_135 ;
break;
case V_137 :
V_171 -> V_129 = V_173 ;
break;
case V_133 :
V_171 -> V_129 =
V_131 | V_174 ;
break;
case V_134 :
default:
V_171 -> V_129 = V_131 ;
break;
}
V_171 -> V_175 = ( V_171 -> V_129 & V_132 ) == V_176 ? 0 : 1 ;
if ( F_15 ( V_177 , & V_23 -> V_47 ) )
V_23 -> V_178 =
1080 * ( ( V_171 -> V_139 + 31 ) & ~ 31 ) ;
return 0 ;
}
static int F_51 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
int V_154 = F_44 ( V_88 , V_89 , V_17 ) ;
if ( V_154 == 0 ) {
V_23 -> V_30 = V_17 -> V_17 . V_142 . V_143 ;
V_23 -> V_26 = V_17 -> V_17 . V_142 . V_144 ;
F_7 ( V_23 ) ;
}
return V_154 ;
}
static int F_52 ( struct V_22 * V_23 , bool V_179 , T_5 V_180 , T_5 * V_181 )
{
volatile T_4 T_6 * V_182 ;
if ( V_180 & 0x3 )
return - V_65 ;
if ( V_180 >= V_183 && V_180 < V_183 + V_184 )
V_182 = V_23 -> V_185 - V_183 ;
else if ( V_23 -> V_186 && V_180 >= V_187 &&
V_180 < V_187 + V_188 )
V_182 = V_23 -> V_189 - V_187 ;
else if ( V_180 < V_190 )
V_182 = V_23 -> V_191 ;
else
return - V_65 ;
if ( V_179 )
* V_181 = F_53 ( V_180 + V_182 ) ;
else
F_54 ( * V_181 , V_180 + V_182 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_88 , void * V_89 , struct V_192 * V_180 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_180 -> V_193 = 4 ;
return F_52 ( V_23 , true , V_180 -> V_180 , & V_180 -> V_181 ) ;
}
static int F_56 ( struct V_88 * V_88 , void * V_89 , const struct V_192 * V_180 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_5 V_181 = V_180 -> V_181 ;
return F_52 ( V_23 , false , V_180 -> V_180 , & V_181 ) ;
}
static int F_57 ( struct V_88 * V_88 , void * V_89 , struct V_194 * V_195 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_196 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ V_56 -> type ] ;
F_58 ( V_195 -> V_197 , V_198 , sizeof( V_195 -> V_197 ) ) ;
F_58 ( V_195 -> V_199 , V_23 -> V_200 , sizeof( V_195 -> V_199 ) ) ;
snprintf ( V_195 -> V_201 , sizeof( V_195 -> V_201 ) , L_2 , F_59 ( V_23 -> V_202 ) ) ;
V_195 -> V_203 = V_23 -> V_63 | V_204 ;
V_195 -> V_205 = V_54 -> V_206 ;
return 0 ;
}
static int F_60 ( struct V_88 * V_88 , void * V_89 , struct V_207 * V_208 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_61 ( V_23 , V_208 -> V_209 , V_208 ) ;
}
static int F_62 ( struct V_88 * V_88 , void * V_89 , struct V_207 * V_208 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_208 -> V_209 = V_23 -> V_210 ;
return F_61 ( V_23 , V_208 -> V_209 , V_208 ) ;
}
static int F_63 ( struct V_88 * V_88 , void * V_89 , const struct V_207 * V_211 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_211 -> V_209 >= V_23 -> V_212 )
return - V_65 ;
V_23 -> V_210 = V_211 -> V_209 ;
F_64 ( V_23 ) ;
return 0 ;
}
static int F_65 ( struct V_88 * V_88 , void * V_89 , struct V_213 * V_208 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_66 ( V_23 , V_208 -> V_209 , V_208 ) ;
}
static int F_67 ( struct V_88 * V_88 , void * V_89 , struct V_213 * V_208 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_208 -> V_209 = 0 ;
return F_66 ( V_23 , V_208 -> V_209 , V_208 ) ;
}
static int F_68 ( struct V_88 * V_88 , void * V_89 , const struct V_213 * V_211 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_23 -> V_199 -> V_214 == NULL || V_211 -> V_209 != 0 )
return - V_65 ;
return 0 ;
}
static int F_69 ( struct V_88 * V_88 , void * V_89 , struct V_215 * V_208 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_70 ( V_23 , V_208 -> V_209 , V_208 ) ;
}
static int F_71 ( struct V_88 * V_88 , void * V_89 , struct V_216 * V_211 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_72 ( V_23 , V_211 -> V_209 , V_211 ) ;
}
static int F_73 ( struct V_88 * V_88 , void * V_89 , struct V_217 * V_218 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_170 * V_171 = & V_23 -> V_128 ;
int V_219 ;
V_219 = V_56 -> type ;
if ( V_218 -> type != V_220 )
return - V_65 ;
V_218 -> V_221 . V_149 = V_218 -> V_221 . V_150 = 0 ;
V_218 -> V_221 . V_101 = 720 ;
if ( V_218 -> type == V_222 ) {
V_218 -> V_221 . V_102 = V_23 -> V_123 ? 576 : 480 ;
V_218 -> V_223 . V_224 = V_23 -> V_123 ? 59 : 10 ;
V_218 -> V_223 . V_225 = V_23 -> V_123 ? 54 : 11 ;
} else if ( V_219 == V_127 ) {
if ( V_171 -> V_226 ) {
V_218 -> V_221 . V_101 = V_171 -> V_227 ;
V_218 -> V_221 . V_102 = V_171 -> V_228 ;
} else {
V_218 -> V_221 . V_101 = 720 ;
V_218 -> V_221 . V_102 =
V_23 -> V_229 ? 576 : 480 ;
}
V_218 -> V_223 . V_224 = V_23 -> V_229 ? 59 : 10 ;
V_218 -> V_223 . V_225 = V_23 -> V_229 ? 54 : 11 ;
} else {
V_218 -> V_221 . V_102 = V_23 -> V_229 ? 576 : 480 ;
V_218 -> V_223 . V_224 = V_23 -> V_229 ? 59 : 10 ;
V_218 -> V_223 . V_225 = V_23 -> V_229 ? 54 : 11 ;
}
V_218 -> V_230 = V_218 -> V_221 ;
return 0 ;
}
static int F_74 ( struct V_88 * V_88 , void * V_89 , const struct V_231 * V_232 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_170 * V_171 = & V_23 -> V_128 ;
int V_219 ;
V_219 = V_56 -> type ;
if ( V_232 -> type == V_220 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_219 == V_127 ) {
V_171 -> V_126 = V_232 -> V_233 ;
return 0 ;
} else {
if ( ! F_8 ( V_23 , V_234 , 4 ,
V_232 -> V_233 . V_101 , V_232 -> V_233 . V_102 , V_232 -> V_233 . V_150 , V_232 -> V_233 . V_149 ) ) {
V_23 -> V_126 = V_232 -> V_233 ;
return 0 ;
}
}
return - V_65 ;
}
return - V_65 ;
}
static int F_75 ( struct V_88 * V_88 , void * V_89 , struct V_231 * V_232 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_170 * V_171 = & V_23 -> V_128 ;
int V_219 ;
V_219 = V_56 -> type ;
if ( V_232 -> type == V_220 &&
( V_23 -> V_63 & V_64 ) ) {
if ( V_219 == V_127 )
V_232 -> V_233 = V_171 -> V_126 ;
else
V_232 -> V_233 = V_23 -> V_126 ;
return 0 ;
}
return - V_65 ;
}
static int F_76 ( struct V_88 * V_88 , void * V_89 , struct V_235 * V_17 )
{
static const struct V_235 V_236 = {
0 , V_222 , 0 ,
L_3 , V_109 ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_235 V_237 = {
0 , V_222 , V_238 ,
L_4 , V_112 ,
{ 0 , 0 , 0 , 0 }
} ;
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_17 -> V_209 )
return - V_65 ;
if ( V_54 -> type == V_239 )
* V_17 = V_237 ;
else if ( V_54 -> type == V_107 )
* V_17 = V_236 ;
else
return - V_65 ;
return 0 ;
}
static int F_77 ( struct V_88 * V_88 , void * V_89 , struct V_235 * V_17 )
{
static const struct V_235 V_236 = {
0 , V_220 , 0 ,
L_3 , V_109 ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_235 V_237 = {
0 , V_220 , V_238 ,
L_4 , V_112 ,
{ 0 , 0 , 0 , 0 }
} ;
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_17 -> V_209 )
return - V_65 ;
if ( V_54 -> type == V_62 )
* V_17 = V_237 ;
else if ( V_54 -> type == V_127 )
* V_17 = V_236 ;
else
return - V_65 ;
return 0 ;
}
static int F_78 ( struct V_88 * V_88 , void * V_89 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
* V_15 = V_23 -> V_240 ;
return 0 ;
}
int F_79 ( struct V_88 * V_88 , void * V_89 , unsigned int V_241 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_7 V_242 ;
int V_15 ;
if ( V_241 >= V_23 -> V_243 )
return - V_65 ;
if ( V_241 == V_23 -> V_240 ) {
F_21 ( L_5 ) ;
return 0 ;
}
if ( F_12 ( & V_23 -> V_157 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_6 ,
V_23 -> V_240 , V_241 ) ;
V_23 -> V_240 = V_241 ;
V_23 -> V_210 = V_23 -> V_199 -> V_244 [ V_241 ] . V_245 ;
if ( V_23 -> V_199 -> V_244 [ V_241 ] . V_246 == V_247 )
V_242 = V_23 -> V_248 ;
else
V_242 = V_249 ;
for ( V_15 = 0 ; V_15 <= V_250 ; V_15 ++ )
V_23 -> V_61 [ V_15 ] . V_251 -> V_252 = V_242 ;
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
* V_15 = V_23 -> V_253 ;
return 0 ;
}
static int F_84 ( struct V_88 * V_88 , void * V_89 , unsigned int V_254 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_254 >= V_23 -> V_199 -> V_255 )
return - V_65 ;
if ( V_254 == V_23 -> V_253 ) {
F_21 ( L_7 ) ;
return 0 ;
}
F_21 ( L_8 ,
V_23 -> V_253 , V_254 ) ;
V_23 -> V_253 = V_254 ;
F_85 ( V_23 , V_256 , V_162 , V_257 ,
V_258 ,
V_23 -> V_199 -> V_214 [ V_254 ] . V_259 , 0 ) ;
return 0 ;
}
static int F_86 ( struct V_88 * V_88 , void * V_89 , struct V_260 * V_261 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_54 -> V_251 -> V_262 )
return - V_263 ;
if ( V_261 -> V_264 != 0 )
return - V_65 ;
F_87 ( V_23 , V_264 , V_265 , V_261 ) ;
return 0 ;
}
int F_88 ( struct V_88 * V_88 , void * V_89 , const struct V_260 * V_261 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_54 -> V_251 -> V_262 )
return - V_263 ;
if ( V_261 -> V_264 != 0 )
return - V_65 ;
F_80 ( V_23 ) ;
F_21 ( L_9 , V_261 -> V_266 ) ;
F_87 ( V_23 , V_264 , V_267 , V_261 ) ;
F_82 ( V_23 ) ;
return 0 ;
}
static int F_89 ( struct V_88 * V_88 , void * V_89 , T_7 * V_242 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
* V_242 = V_23 -> V_242 ;
return 0 ;
}
void F_90 ( struct V_22 * V_23 , T_7 V_242 )
{
V_23 -> V_242 = V_242 ;
V_23 -> V_97 = ( V_242 & V_268 ) ? 1 : 0 ;
V_23 -> V_123 = ! V_23 -> V_97 ;
F_91 ( & V_23 -> V_37 , V_23 -> V_123 ) ;
V_23 -> V_37 . V_101 = 720 ;
V_23 -> V_37 . V_102 = V_23 -> V_123 ? 576 : 480 ;
V_23 -> V_114 . V_121 = V_23 -> V_123 ? 18 : 12 ;
V_23 -> V_114 . V_70 [ 0 ] = V_23 -> V_123 ? 6 : 10 ;
V_23 -> V_114 . V_70 [ 1 ] = V_23 -> V_123 ? 318 : 273 ;
if ( V_23 -> V_269 & V_270 )
V_23 -> V_114 . V_271 = V_23 -> V_97 ? 272 : 284 ;
F_87 ( V_23 , V_272 , V_273 , V_23 -> V_242 ) ;
}
void F_92 ( struct V_22 * V_23 , T_7 V_242 )
{
struct V_170 * V_171 = & V_23 -> V_128 ;
F_10 ( V_35 ) ;
int V_19 ;
V_23 -> V_274 = V_242 ;
V_23 -> V_275 = ( V_242 & V_268 ) ? 1 : 0 ;
V_23 -> V_229 = ! V_23 -> V_275 ;
F_87 ( V_23 , V_162 , V_276 , V_23 -> V_274 ) ;
F_13 ( & V_23 -> V_43 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_14 ( & V_23 -> V_277 , & V_35 ,
V_278 ) ;
if ( ( F_93 ( V_279 ) >> 16 ) < 100 )
break;
F_94 ( F_95 ( 25 ) ) ;
}
F_18 ( & V_23 -> V_277 , & V_35 ) ;
F_19 ( & V_23 -> V_43 ) ;
if ( V_19 == 4 )
F_96 ( L_10 ) ;
F_8 ( V_23 , V_280 , 1 , V_23 -> V_229 ) ;
V_23 -> V_126 . V_150 = 0 ;
V_23 -> V_126 . V_149 = 0 ;
V_23 -> V_126 . V_101 = 720 ;
V_23 -> V_126 . V_102 = V_23 -> V_229 ? 576 : 480 ;
F_8 ( V_23 , V_234 , 4 ,
720 , V_23 -> V_126 . V_102 , 0 , 0 ) ;
V_171 -> V_126 = V_23 -> V_126 ;
if ( ! V_23 -> V_281 ) {
V_171 -> V_227 = 720 ;
V_171 -> V_228 = V_23 -> V_229 ? 576 : 480 ;
}
}
static int F_97 ( struct V_88 * V_88 , void * V_89 , T_7 V_242 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ( V_242 & V_249 ) == 0 )
return - V_65 ;
if ( V_242 == V_23 -> V_242 )
return 0 ;
if ( F_15 ( V_282 , & V_23 -> V_47 ) ||
F_12 ( & V_23 -> V_157 ) > 0 ||
F_12 ( & V_23 -> V_40 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_11 ,
( unsigned long long ) V_23 -> V_242 ) ;
F_90 ( V_23 , V_242 ) ;
if ( V_23 -> V_63 & V_64 )
F_92 ( V_23 , V_242 ) ;
return 0 ;
}
static int F_98 ( struct V_88 * V_88 , void * V_89 , const struct V_283 * V_284 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
if ( V_284 -> V_209 != 0 )
return - V_65 ;
F_87 ( V_23 , V_264 , V_285 , V_284 ) ;
return 0 ;
}
static int F_99 ( struct V_88 * V_88 , void * V_89 , struct V_283 * V_284 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_284 -> V_209 != 0 )
return - V_65 ;
F_87 ( V_23 , V_264 , V_286 , V_284 ) ;
if ( V_284 -> type == V_287 )
F_58 ( V_284 -> V_288 , L_12 , sizeof( V_284 -> V_288 ) ) ;
else
F_58 ( V_284 -> V_288 , L_13 , sizeof( V_284 -> V_288 ) ) ;
return 0 ;
}
static int F_100 ( struct V_88 * V_88 , void * V_89 , struct V_289 * V_290 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
int V_11 = V_23 -> V_123 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_290 -> type == V_168 ) {
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_23 -> V_123 ) )
V_290 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
}
}
} else if ( V_290 -> type == V_291 ) {
if ( ! ( V_23 -> V_63 & V_94 ) )
return - V_65 ;
if ( V_23 -> V_97 ) {
V_290 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_290 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_290 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_290 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
} else {
return - V_65 ;
}
V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ )
V_11 |= V_290 -> V_21 [ V_19 ] [ V_20 ] ;
V_290 -> V_18 = V_11 ;
return 0 ;
}
static int F_101 ( struct V_88 * V_88 , void * V_89 , struct V_292 * V_293 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_294 * V_295 = V_293 -> V_296 ;
int V_297 ;
int V_15 ;
V_297 = ( V_23 -> V_298 + V_299 - V_23 -> V_300 ) %
V_299 ;
if ( V_297 > V_301 )
V_297 = V_301 ;
V_293 -> V_297 = 0 ;
V_293 -> V_302 = V_299 ;
if ( ! F_12 ( & V_23 -> V_157 ) )
return 0 ;
for ( V_15 = 0 ; V_15 < V_297 ; V_15 ++ ) {
* V_295 = V_23 -> V_303 [ ( V_23 -> V_300 + V_15 ) % V_299 ] ;
if ( ( V_295 -> V_68 & V_304 ) <= V_305 ) {
V_293 -> V_297 ++ ;
V_295 ++ ;
}
}
V_23 -> V_300 = ( V_23 -> V_300 + V_293 -> V_297 ) % V_299 ;
return 0 ;
}
static int F_102 ( struct V_88 * V_88 , void * V_89 , struct V_306 * V_307 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
switch ( V_307 -> V_66 ) {
case V_308 :
F_103 ( L_14 ) ;
V_307 -> V_68 = 0 ;
return F_104 ( V_56 ) ;
case V_309 :
F_103 ( L_15 ) ;
V_307 -> V_68 &= V_310 ;
F_105 ( V_56 , V_307 -> V_68 & V_310 ) ;
return 0 ;
case V_311 :
F_103 ( L_16 ) ;
V_307 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_157 ) )
return - V_86 ;
if ( F_106 ( V_312 , & V_23 -> V_47 ) )
return 0 ;
F_80 ( V_23 ) ;
F_8 ( V_23 , V_313 , 1 , 0 ) ;
break;
case V_314 :
F_103 ( L_17 ) ;
V_307 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_157 ) )
return - V_86 ;
if ( ! F_25 ( V_312 , & V_23 -> V_47 ) )
return 0 ;
F_8 ( V_23 , V_313 , 1 , 1 ) ;
F_82 ( V_23 ) ;
break;
default:
F_103 ( L_18 , V_307 -> V_66 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_107 ( struct V_88 * V_88 , void * V_89 , struct V_306 * V_307 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
switch ( V_307 -> V_66 ) {
case V_308 :
F_103 ( L_14 ) ;
V_307 -> V_68 = 0 ;
return 0 ;
case V_309 :
F_103 ( L_15 ) ;
V_307 -> V_68 &= V_310 ;
return 0 ;
case V_311 :
F_103 ( L_16 ) ;
V_307 -> V_68 = 0 ;
return 0 ;
case V_314 :
F_103 ( L_17 ) ;
V_307 -> V_68 = 0 ;
return 0 ;
default:
F_103 ( L_18 , V_307 -> V_66 ) ;
return - V_65 ;
}
}
static int F_108 ( struct V_88 * V_88 , void * V_89 , struct V_315 * V_316 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
struct V_170 * V_171 = & V_23 -> V_128 ;
int V_99 ;
static T_2 V_317 [ 16 ] = {
V_318 ,
V_319 ,
V_320 ,
V_321 ,
V_322 ,
0 ,
0 ,
0 ,
V_318 ,
V_323 ,
V_324 ,
V_325 ,
V_326 ,
0 ,
0 ,
0 ,
} ;
if ( ! ( V_23 -> V_63 & V_327 ) )
return - V_65 ;
if ( ! V_23 -> V_328 )
return - V_65 ;
V_316 -> V_329 = V_330 | V_331 |
V_332 ;
F_109 ( V_23 , V_32 , V_333 , 0 ) ;
V_32 [ 0 ] |= ( F_93 ( 0x2a00 ) >> 7 ) & 0x40 ;
V_99 = ( V_32 [ 0 ] >> 3 ) & 0xf ;
V_316 -> V_17 . V_108 = V_317 [ V_99 ] ;
V_316 -> V_17 . V_101 = V_23 -> V_151 . V_101 ;
V_316 -> V_17 . V_102 = V_23 -> V_151 . V_102 ;
V_316 -> V_17 . V_9 = V_105 ;
V_316 -> V_17 . V_111 = V_316 -> V_17 . V_101 ;
V_316 -> V_17 . V_103 = V_104 ;
V_316 -> V_17 . V_9 = V_105 ;
V_316 -> V_17 . V_106 = 0 ;
if ( V_316 -> V_17 . V_108 != V_318 )
V_316 -> V_17 . V_111 *= 2 ;
if ( V_316 -> V_17 . V_108 == V_322 ||
V_316 -> V_17 . V_108 == V_326 )
V_316 -> V_17 . V_111 *= 2 ;
V_316 -> V_17 . V_110 = V_316 -> V_17 . V_111 * V_316 -> V_17 . V_102 ;
V_316 -> V_334 = ( void * ) V_23 -> V_328 ;
V_316 -> V_68 = 0 ;
if ( V_23 -> V_29 )
V_316 -> V_68 |= V_335 ;
if ( V_23 -> V_25 )
V_316 -> V_68 |= V_336 ;
if ( V_171 -> V_226 )
V_316 -> V_68 |= V_337 ;
V_99 &= 7 ;
if ( V_99 == 1 || V_99 > 4 )
return 0 ;
if ( V_99 == 2 || V_99 == 3 )
V_316 -> V_329 |= V_338 ;
else
V_316 -> V_329 |= V_339 ;
if ( V_23 -> V_27 ) {
if ( V_99 == 2 || V_99 == 3 )
V_316 -> V_68 |= V_340 ;
else
V_316 -> V_68 |= V_341 ;
}
return 0 ;
}
static int F_110 ( struct V_88 * V_88 , void * V_89 , const struct V_315 * V_316 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_170 * V_171 = & V_23 -> V_128 ;
if ( ! ( V_23 -> V_63 & V_327 ) )
return - V_65 ;
if ( ! V_23 -> V_328 )
return - V_65 ;
V_23 -> V_25 = ( V_316 -> V_68 & V_336 ) != 0 ;
V_23 -> V_27 =
( V_316 -> V_68 & ( V_341 | V_340 ) ) != 0 ;
V_23 -> V_29 = ( V_316 -> V_68 & V_335 ) != 0 ;
F_7 ( V_23 ) ;
V_171 -> V_226 = ( V_316 -> V_68 & V_337 ) != 0 ;
return 0 ;
}
static int F_111 ( struct V_88 * V_88 , void * V_89 , unsigned int V_342 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
if ( ! ( V_23 -> V_63 & V_327 ) )
return - V_65 ;
F_8 ( V_23 , V_343 , 1 , V_342 != 0 ) ;
return 0 ;
}
static int F_112 ( struct V_344 * V_89 , const struct V_345 * V_346 )
{
switch ( V_346 -> type ) {
case V_347 :
case V_348 :
return F_113 ( V_89 , V_346 , 0 , NULL ) ;
case V_349 :
return F_113 ( V_89 , V_346 , 0 , & V_350 ) ;
default:
return - V_65 ;
}
}
static int F_114 ( struct V_88 * V_88 , void * V_89 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
int V_351 = V_23 -> V_63 & V_64 ;
struct V_215 V_352 ;
struct V_207 V_353 ;
int V_15 ;
F_115 ( L_19 , V_354 , V_23 -> V_200 ) ;
if ( V_23 -> V_269 & V_355 ) {
struct V_356 V_357 ;
F_116 ( V_23 , & V_357 ) ;
}
F_87 ( V_23 , V_272 , V_358 ) ;
F_70 ( V_23 , V_23 -> V_240 , & V_352 ) ;
F_61 ( V_23 , V_23 -> V_210 , & V_353 ) ;
F_115 ( L_20 , V_352 . V_288 ) ;
F_115 ( L_21 , V_353 . V_288 ,
( V_23 -> V_359 & ~ 0x300 ) == 0x200 ? L_22 : L_23 ) ;
if ( V_351 ) {
struct V_216 V_360 ;
struct V_213 V_361 ;
int V_362 = V_23 -> V_82 ;
static const char * const V_363 [ 5 ] = {
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
} ;
static const char * const V_364 [ 4 ] = {
L_24 ,
L_29 ,
L_30 ,
L_31
} ;
static const char * const V_317 [ 16 ] = {
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
F_72 ( V_23 , V_23 -> V_253 , & V_360 ) ;
F_66 ( V_23 , 0 , & V_361 ) ;
F_115 ( L_48 , V_360 . V_288 ) ;
if ( V_362 < 0 || V_362 > V_365 )
V_362 = V_83 ;
F_115 ( L_49 , V_363 [ V_362 ] ) ;
F_109 ( V_23 , V_32 , V_333 , 0 ) ;
V_32 [ 0 ] |= ( F_93 ( 0x2a00 ) >> 7 ) & 0x40 ;
F_115 ( L_50 ,
V_32 [ 0 ] & 1 ? L_51 : L_52 ,
V_364 [ ( V_32 [ 0 ] >> 1 ) & 0x3 ] ,
V_317 [ ( V_32 [ 0 ] >> 3 ) & 0xf ] ) ;
}
F_115 ( L_53 ,
F_15 ( V_282 , & V_23 -> V_47 ) ? L_54 : L_55 ) ;
F_117 ( & V_23 -> V_37 . V_366 , V_23 -> V_367 . V_288 ) ;
F_115 ( L_56 , V_23 -> V_47 ) ;
for ( V_15 = 0 ; V_15 < V_368 ; V_15 ++ ) {
struct V_60 * V_54 = & V_23 -> V_61 [ V_15 ] ;
if ( V_54 -> V_251 == NULL || V_54 -> V_369 == 0 )
continue;
F_115 ( L_57 , V_54 -> V_288 , V_54 -> V_370 ,
( V_54 -> V_369 - V_54 -> V_371 . V_369 ) * 100 / V_54 -> V_369 ,
( V_54 -> V_369 * V_54 -> V_372 ) / 1024 , V_54 -> V_369 ) ;
}
F_115 ( L_58 ,
( long long ) V_23 -> V_373 ,
( long long ) V_23 -> V_374 ) ;
return 0 ;
}
static int F_118 ( struct V_88 * V_88 , void * V_89 , struct V_57 * V_375 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_196 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
F_103 ( L_59 , V_375 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_375 , false ) ;
}
static int F_119 ( struct V_88 * V_88 , void * V_89 , struct V_57 * V_375 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_196 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
F_103 ( L_60 , V_375 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_375 , true ) ;
}
static int F_120 ( struct V_88 * V_376 , unsigned int V_66 , void * V_377 )
{
struct V_55 * V_56 = F_30 ( V_376 -> V_196 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
int V_378 = V_376 -> V_379 & V_380 ;
struct V_60 * V_54 = & V_23 -> V_61 [ V_56 -> type ] ;
unsigned long V_381 = ( unsigned long ) V_377 ;
switch ( V_66 ) {
case V_382 : {
struct V_383 * args = V_377 ;
F_103 ( L_61 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( args -> type != V_220 )
return - V_65 ;
if ( V_23 -> V_82 == V_384 && args -> V_385 == NULL )
return 0 ;
if ( F_26 ( V_56 , V_56 -> type ) ) {
return - V_75 ;
}
if ( F_24 ( V_23 , V_384 ) != V_384 ) {
F_121 ( V_54 ) ;
return - V_75 ;
}
V_56 -> V_386 = 1 ;
if ( args -> V_385 == NULL )
return 0 ;
return F_122 ( V_23 , args ) ;
}
case V_387 :
F_103 ( L_62 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_123 ( V_23 , * ( int * ) V_377 != 0 ) ;
case V_388 : {
T_8 * V_81 = V_377 ;
T_8 V_389 ;
F_103 ( L_63 ) ;
if ( V_54 -> type < V_62 ) {
* V_81 = V_54 -> V_390 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_124 ( V_23 , V_81 , & V_389 ) ;
}
case V_391 : {
T_8 * V_389 = V_377 ;
T_8 V_81 ;
F_103 ( L_64 ) ;
if ( V_54 -> type < V_62 ) {
* V_389 = 0 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_124 ( V_23 , & V_81 , V_389 ) ;
}
case V_392 : {
struct V_57 V_58 ;
F_103 ( L_65 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_67 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_393 : {
struct V_57 V_58 ;
F_103 ( L_66 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_77 ;
V_58 . V_68 = V_79 | V_78 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_394 : {
struct V_57 V_58 ;
F_103 ( L_67 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_84 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_395 : {
struct V_57 V_58 ;
F_103 ( L_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_87 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_396 :
case V_397 : {
struct V_57 * V_58 = V_377 ;
int V_59 = ( V_66 == V_397 ) ;
if ( V_59 )
F_103 ( L_69 , V_58 -> V_66 ) ;
else
F_103 ( L_70 , V_58 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_58 , V_59 ) ;
}
case V_398 : {
struct V_399 * V_400 = V_377 ;
F_10 ( V_35 ) ;
F_103 ( L_71 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
memset ( V_400 , 0 , sizeof( * V_400 ) ) ;
F_28 ( V_401 , & V_23 -> V_47 ) ;
while ( 1 ) {
if ( F_25 ( V_402 , & V_23 -> V_47 ) )
V_400 -> type = V_403 ;
else if ( F_25 ( V_404 , & V_23 -> V_47 ) ) {
V_400 -> type = V_405 ;
V_400 -> V_406 . V_407 = F_15 ( V_408 , & V_23 -> V_47 ) ?
V_409 : V_410 ;
if ( V_23 -> V_82 == V_384 &&
( V_23 -> V_128 . V_129 & V_130 ) ==
V_135 ) {
V_400 -> V_406 . V_407 = V_411 ;
}
}
if ( V_400 -> type )
return 0 ;
if ( V_378 )
return - V_412 ;
F_13 ( & V_23 -> V_43 ) ;
F_14 ( & V_23 -> V_413 , & V_35 , V_45 ) ;
if ( ! F_15 ( V_402 , & V_23 -> V_47 ) &&
! F_15 ( V_404 , & V_23 -> V_47 ) )
F_17 () ;
F_18 ( & V_23 -> V_413 , & V_35 ) ;
F_19 ( & V_23 -> V_43 ) ;
if ( F_16 ( V_48 ) ) {
F_21 ( L_72 ) ;
return - V_49 ;
}
}
break;
}
case V_414 :
F_103 ( L_73 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_123 ( V_23 , V_381 == V_415 ) ;
case V_416 :
F_103 ( L_74 ) ;
V_23 -> V_39 = V_381 ;
return 0 ;
case V_417 :
F_103 ( L_75 ) ;
if ( V_381 > V_418 )
return - V_65 ;
return F_125 ( V_23 -> V_419 , V_381 + 1 ) ;
case V_420 :
F_103 ( L_76 ) ;
if ( V_381 > V_418 )
return - V_65 ;
return F_125 ( V_23 -> V_421 , V_381 + 1 ) ;
default:
return - V_65 ;
}
return 0 ;
}
static long F_126 ( struct V_88 * V_88 , void * V_89 , bool V_422 ,
unsigned int V_66 , void * V_377 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! V_422 ) {
switch ( V_66 ) {
case V_387 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_414 :
case V_416 :
case V_417 :
case V_420 :
return - V_75 ;
}
}
switch ( V_66 ) {
case V_423 : {
T_2 V_181 = * ( T_2 * ) V_377 ;
if ( ( V_181 == 0 && V_23 -> V_424 . V_425 ) || ( V_181 & 0x01 ) )
F_127 ( V_23 ) ;
if ( V_181 & 0x02 )
F_34 ( V_23 -> V_124 , V_272 , V_426 , 0 ) ;
break;
}
case V_382 :
case V_387 :
case V_388 :
case V_391 :
case V_398 :
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_414 :
case V_416 :
case V_417 :
case V_420 :
return F_120 ( V_88 , V_66 , ( void * ) V_377 ) ;
default:
return - V_263 ;
}
return 0 ;
}
void F_128 ( struct V_427 * V_251 )
{
V_251 -> V_428 = & V_429 ;
}
