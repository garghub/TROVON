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
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
struct V_139 * V_140 = & V_17 -> V_17 . V_141 ;
if ( ! ( V_54 -> V_142 & V_143 ) )
return - V_65 ;
if ( ! V_23 -> V_144 )
return - V_65 ;
V_140 -> V_145 = V_23 -> V_30 ;
V_140 -> V_146 = V_23 -> V_26 ;
V_140 -> V_9 = V_105 ;
V_140 -> V_147 = NULL ;
V_140 -> V_148 = 0 ;
V_140 -> V_149 = NULL ;
V_140 -> V_150 . V_151 = V_140 -> V_150 . V_152 = 0 ;
V_140 -> V_150 . V_101 = V_23 -> V_153 . V_101 ;
V_140 -> V_150 . V_102 = V_23 -> V_153 . V_102 ;
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
int V_150 = V_17 -> V_17 . V_100 . V_101 ;
int V_154 = V_17 -> V_17 . V_100 . V_102 ;
int V_155 = 2 ;
V_150 = F_39 ( V_150 , 720 ) ;
V_150 = F_40 ( V_150 , 2 ) ;
if ( V_56 -> type == V_106 ) {
V_154 &= ~ 0x1f ;
V_155 = 32 ;
}
V_154 = F_39 ( V_154 , V_23 -> V_122 ? 576 : 480 ) ;
V_154 = F_40 ( V_154 , V_155 ) ;
F_31 ( V_88 , V_89 , V_17 ) ;
V_17 -> V_17 . V_100 . V_101 = V_150 ;
V_17 -> V_17 . V_100 . V_102 = V_154 ;
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
T_3 V_150 = V_17 -> V_17 . V_100 . V_101 ;
T_3 V_154 = V_17 -> V_17 . V_100 . V_102 ;
int V_9 = V_17 -> V_17 . V_100 . V_9 ;
int V_156 = F_35 ( V_88 , V_89 , V_17 ) ;
V_150 = F_39 ( V_150 , 720 ) ;
V_150 = F_40 ( V_150 , 2 ) ;
V_154 = F_39 ( V_154 , 576 ) ;
V_154 = F_40 ( V_154 , 2 ) ;
if ( V_56 -> type == V_126 )
V_17 -> V_17 . V_100 . V_9 = V_9 ;
V_17 -> V_17 . V_100 . V_101 = V_150 ;
V_17 -> V_17 . V_100 . V_102 = V_154 ;
return V_156 ;
}
static int F_44 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
T_2 V_145 = V_17 -> V_17 . V_141 . V_145 ;
T_4 V_146 = V_17 -> V_17 . V_141 . V_146 ;
if ( ! ( V_54 -> V_142 & V_143 ) )
return - V_65 ;
if ( ! V_23 -> V_144 )
return - V_65 ;
F_36 ( V_88 , V_89 , V_17 ) ;
V_17 -> V_17 . V_141 . V_145 = V_145 ;
V_17 -> V_17 . V_141 . V_146 = V_146 ;
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
struct V_157 V_158 ;
int V_156 = F_38 ( V_88 , V_89 , V_17 ) ;
int V_150 = V_17 -> V_17 . V_100 . V_101 ;
int V_154 = V_17 -> V_17 . V_100 . V_102 ;
if ( V_156 )
return V_156 ;
if ( V_23 -> V_37 . V_101 == V_150 && V_23 -> V_37 . V_102 == V_154 )
return 0 ;
if ( F_12 ( & V_23 -> V_159 ) > 0 )
return - V_75 ;
V_23 -> V_37 . V_101 = V_150 ;
V_23 -> V_37 . V_102 = V_154 ;
if ( F_11 ( V_23 -> V_37 . V_160 ) == V_161 )
V_17 -> V_17 . V_100 . V_101 /= 2 ;
V_158 . V_101 = V_17 -> V_17 . V_100 . V_101 ;
V_158 . V_102 = V_154 ;
V_158 . V_162 = V_163 ;
F_34 ( V_23 -> V_123 , V_164 , V_165 , & V_158 ) ;
return F_31 ( V_88 , V_89 , V_17 ) ;
}
static int F_47 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! F_48 ( V_23 ) && F_12 ( & V_23 -> V_159 ) > 0 )
return - V_75 ;
V_23 -> V_113 . V_166 -> V_18 = 0 ;
V_23 -> V_113 . V_167 . type = V_168 ;
F_34 ( V_23 -> V_123 , V_113 , V_169 , & V_17 -> V_17 . V_113 ) ;
return F_32 ( V_88 , V_89 , V_17 ) ;
}
static int F_49 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_16 * V_91 = & V_17 -> V_17 . V_92 ;
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
int V_156 = F_42 ( V_88 , V_89 , V_17 ) ;
if ( V_156 || V_56 -> type == V_121 )
return V_156 ;
F_5 ( V_91 , V_23 -> V_122 ) ;
if ( F_48 ( V_23 ) && F_12 ( & V_23 -> V_159 ) > 0 )
return - V_75 ;
V_23 -> V_113 . V_167 . type = V_170 ;
F_34 ( V_23 -> V_123 , V_113 , V_171 , V_91 ) ;
memcpy ( V_23 -> V_113 . V_166 , V_91 , sizeof( * V_23 -> V_113 . V_166 ) ) ;
return 0 ;
}
static int F_50 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_172 * V_173 = & V_23 -> V_127 ;
int V_156 = F_43 ( V_88 , V_89 , V_17 ) ;
if ( V_156 )
return V_156 ;
if ( V_56 -> type != V_126 )
return 0 ;
if ( V_173 -> V_174 )
return - V_75 ;
V_173 -> V_137 = V_17 -> V_17 . V_100 . V_101 ;
V_173 -> V_138 = V_17 -> V_17 . V_100 . V_102 ;
switch ( V_17 -> V_17 . V_100 . V_9 ) {
case V_135 :
V_173 -> V_128 = V_134 ;
break;
case V_136 :
V_173 -> V_128 = V_175 ;
break;
case V_132 :
V_173 -> V_128 =
V_130 | V_176 ;
break;
case V_133 :
default:
V_173 -> V_128 = V_130 ;
break;
}
V_173 -> V_177 = ( V_173 -> V_128 & V_131 ) == V_178 ? 0 : 1 ;
if ( F_15 ( V_179 , & V_23 -> V_47 ) )
V_23 -> V_180 =
1080 * ( ( V_173 -> V_138 + 31 ) & ~ 31 ) ;
return 0 ;
}
static int F_51 ( struct V_88 * V_88 , void * V_89 , struct V_90 * V_17 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
int V_156 = F_44 ( V_88 , V_89 , V_17 ) ;
if ( V_156 == 0 ) {
V_23 -> V_30 = V_17 -> V_17 . V_141 . V_145 ;
V_23 -> V_26 = V_17 -> V_17 . V_141 . V_146 ;
F_7 ( V_23 ) ;
}
return V_156 ;
}
static int F_52 ( struct V_22 * V_23 , bool V_181 , T_5 V_182 , T_5 * V_183 )
{
volatile T_4 T_6 * V_184 ;
if ( V_182 & 0x3 )
return - V_65 ;
if ( V_182 >= V_185 && V_182 < V_185 + V_186 )
V_184 = V_23 -> V_187 - V_185 ;
else if ( V_23 -> V_188 && V_182 >= V_189 &&
V_182 < V_189 + V_190 )
V_184 = V_23 -> V_191 - V_189 ;
else if ( V_182 < V_192 )
V_184 = V_23 -> V_193 ;
else
return - V_65 ;
if ( V_181 )
* V_183 = F_53 ( V_182 + V_184 ) ;
else
F_54 ( * V_183 , V_182 + V_184 ) ;
return 0 ;
}
static int F_55 ( struct V_88 * V_88 , void * V_89 , struct V_194 * V_182 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_182 -> V_195 = 4 ;
return F_52 ( V_23 , true , V_182 -> V_182 , & V_182 -> V_183 ) ;
}
static int F_56 ( struct V_88 * V_88 , void * V_89 , const struct V_194 * V_182 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_5 V_183 = V_182 -> V_183 ;
return F_52 ( V_23 , false , V_182 -> V_182 , & V_183 ) ;
}
static int F_57 ( struct V_88 * V_88 , void * V_89 , struct V_196 * V_197 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_198 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ V_56 -> type ] ;
F_58 ( V_197 -> V_199 , V_200 , sizeof( V_197 -> V_199 ) ) ;
F_58 ( V_197 -> V_201 , V_23 -> V_202 , sizeof( V_197 -> V_201 ) ) ;
snprintf ( V_197 -> V_203 , sizeof( V_197 -> V_203 ) , L_2 , F_59 ( V_23 -> V_204 ) ) ;
V_197 -> V_205 = V_23 -> V_63 | V_206 ;
V_197 -> V_207 = V_54 -> V_142 ;
if ( ( V_54 -> V_142 & V_143 ) &&
! V_23 -> V_144 ) {
V_197 -> V_205 &= ~ V_143 ;
V_197 -> V_207 &= ~ V_143 ;
}
return 0 ;
}
static int F_60 ( struct V_88 * V_88 , void * V_89 , struct V_208 * V_209 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_61 ( V_23 , V_209 -> V_210 , V_209 ) ;
}
static int F_62 ( struct V_88 * V_88 , void * V_89 , struct V_208 * V_209 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_209 -> V_210 = V_23 -> V_211 ;
return F_61 ( V_23 , V_209 -> V_210 , V_209 ) ;
}
static int F_63 ( struct V_88 * V_88 , void * V_89 , const struct V_208 * V_212 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_212 -> V_210 >= V_23 -> V_213 )
return - V_65 ;
V_23 -> V_211 = V_212 -> V_210 ;
F_64 ( V_23 ) ;
return 0 ;
}
static int F_65 ( struct V_88 * V_88 , void * V_89 , struct V_214 * V_209 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_66 ( V_23 , V_209 -> V_210 , V_209 ) ;
}
static int F_67 ( struct V_88 * V_88 , void * V_89 , struct V_214 * V_209 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
V_209 -> V_210 = 0 ;
return F_66 ( V_23 , V_209 -> V_210 , V_209 ) ;
}
static int F_68 ( struct V_88 * V_88 , void * V_89 , const struct V_214 * V_212 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_23 -> V_201 -> V_215 == NULL || V_212 -> V_210 != 0 )
return - V_65 ;
return 0 ;
}
static int F_69 ( struct V_88 * V_88 , void * V_89 , struct V_216 * V_209 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_70 ( V_23 , V_209 -> V_210 , V_209 ) ;
}
static int F_71 ( struct V_88 * V_88 , void * V_89 , struct V_217 * V_212 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
return F_72 ( V_23 , V_212 -> V_210 , V_212 ) ;
}
static int F_73 ( struct V_88 * V_88 , void * V_89 , struct V_218 * V_219 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
if ( V_219 -> type == V_220 ) {
V_219 -> V_221 . V_222 = V_23 -> V_122 ? 59 : 10 ;
V_219 -> V_221 . V_223 = V_23 -> V_122 ? 54 : 11 ;
} else if ( V_219 -> type == V_224 ) {
V_219 -> V_221 . V_222 = V_23 -> V_225 ? 59 : 10 ;
V_219 -> V_221 . V_223 = V_23 -> V_225 ? 54 : 11 ;
} else {
return - V_65 ;
}
return 0 ;
}
static int F_74 ( struct V_88 * V_88 , void * V_89 ,
struct V_226 * V_227 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_172 * V_173 = & V_23 -> V_127 ;
struct V_228 V_229 = { 0 , 0 , 720 , 0 } ;
int V_230 = V_56 -> type ;
if ( V_227 -> type != V_224 ||
! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( V_227 -> V_231 != V_232 )
return - V_65 ;
if ( V_227 -> type != V_224 ||
! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
V_229 . V_102 = V_23 -> V_225 ? 576 : 480 ;
if ( V_230 == V_126 && V_173 -> V_233 ) {
V_229 . V_101 = V_173 -> V_234 ;
V_229 . V_102 = V_173 -> V_235 ;
}
V_227 -> V_229 . V_101 = F_75 ( V_227 -> V_229 . V_101 , 16U , V_229 . V_101 ) ;
V_227 -> V_229 . V_102 = F_75 ( V_227 -> V_229 . V_102 , 16U , V_229 . V_102 ) ;
V_227 -> V_229 . V_152 = F_76 ( unsigned , V_227 -> V_229 . V_152 , 0 , V_229 . V_101 - V_227 -> V_229 . V_101 ) ;
V_227 -> V_229 . V_151 = F_76 ( unsigned , V_227 -> V_229 . V_151 , 0 , V_229 . V_102 - V_227 -> V_229 . V_102 ) ;
if ( V_230 == V_126 ) {
V_173 -> V_125 = V_227 -> V_229 ;
return 0 ;
}
if ( ! F_8 ( V_23 , V_236 , 4 ,
V_227 -> V_229 . V_101 , V_227 -> V_229 . V_102 , V_227 -> V_229 . V_152 , V_227 -> V_229 . V_151 ) ) {
V_23 -> V_125 = V_227 -> V_229 ;
return 0 ;
}
return - V_65 ;
}
static int F_77 ( struct V_88 * V_88 , void * V_89 ,
struct V_226 * V_227 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_172 * V_173 = & V_23 -> V_127 ;
struct V_228 V_229 = { 0 , 0 , 720 , 0 } ;
int V_230 = V_56 -> type ;
if ( V_227 -> type == V_220 ) {
switch ( V_227 -> V_231 ) {
case V_237 :
case V_238 :
V_227 -> V_229 . V_151 = V_227 -> V_229 . V_152 = 0 ;
V_227 -> V_229 . V_101 = 720 ;
V_227 -> V_229 . V_102 = V_23 -> V_122 ? 576 : 480 ;
return 0 ;
default:
return - V_65 ;
}
}
if ( V_227 -> type != V_224 ||
! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
switch ( V_227 -> V_231 ) {
case V_232 :
if ( V_230 == V_126 )
V_227 -> V_229 = V_173 -> V_125 ;
else
V_227 -> V_229 = V_23 -> V_125 ;
return 0 ;
case V_239 :
case V_240 :
V_229 . V_102 = V_23 -> V_225 ? 576 : 480 ;
if ( V_230 == V_126 && V_173 -> V_233 ) {
V_229 . V_101 = V_173 -> V_234 ;
V_229 . V_102 = V_173 -> V_235 ;
}
V_227 -> V_229 = V_229 ;
return 0 ;
}
return - V_65 ;
}
static int F_78 ( struct V_88 * V_88 , void * V_89 , struct V_241 * V_17 )
{
static const struct V_241 V_242 = {
0 , V_220 , 0 ,
L_3 , V_108 ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_241 V_243 = {
0 , V_220 , V_244 ,
L_4 , V_111 ,
{ 0 , 0 , 0 , 0 }
} ;
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_17 -> V_210 )
return - V_65 ;
if ( V_54 -> type == V_245 )
* V_17 = V_243 ;
else if ( V_54 -> type == V_106 )
* V_17 = V_242 ;
else
return - V_65 ;
return 0 ;
}
static int F_79 ( struct V_88 * V_88 , void * V_89 , struct V_241 * V_17 )
{
static const struct V_241 V_242 = {
0 , V_224 , 0 ,
L_3 , V_108 ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_241 V_243 = {
0 , V_224 , V_244 ,
L_4 , V_111 ,
{ 0 , 0 , 0 , 0 }
} ;
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_17 -> V_210 )
return - V_65 ;
if ( V_54 -> type == V_62 )
* V_17 = V_243 ;
else if ( V_54 -> type == V_126 )
* V_17 = V_242 ;
else
return - V_65 ;
return 0 ;
}
static int F_80 ( struct V_88 * V_88 , void * V_89 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
* V_15 = V_23 -> V_246 ;
return 0 ;
}
int F_81 ( struct V_88 * V_88 , void * V_89 , unsigned int V_247 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_7 V_248 ;
int V_15 ;
if ( V_247 >= V_23 -> V_249 )
return - V_65 ;
if ( V_247 == V_23 -> V_246 ) {
F_21 ( L_5 ) ;
return 0 ;
}
if ( F_12 ( & V_23 -> V_159 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_6 ,
V_23 -> V_246 , V_247 ) ;
V_23 -> V_246 = V_247 ;
V_23 -> V_211 = V_23 -> V_201 -> V_250 [ V_247 ] . V_251 ;
if ( V_23 -> V_201 -> V_250 [ V_247 ] . V_252 == V_253 )
V_248 = V_23 -> V_254 ;
else
V_248 = V_255 ;
for ( V_15 = 0 ; V_15 <= V_256 ; V_15 ++ )
V_23 -> V_61 [ V_15 ] . V_257 . V_258 = V_248 ;
F_82 ( V_23 ) ;
F_83 ( V_23 ) ;
F_64 ( V_23 ) ;
F_84 ( V_23 ) ;
return 0 ;
}
static int F_85 ( struct V_88 * V_88 , void * V_89 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
* V_15 = V_23 -> V_259 ;
return 0 ;
}
static int F_86 ( struct V_88 * V_88 , void * V_89 , unsigned int V_260 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_260 >= V_23 -> V_201 -> V_261 )
return - V_65 ;
if ( V_260 == V_23 -> V_259 ) {
F_21 ( L_7 ) ;
return 0 ;
}
F_21 ( L_8 ,
V_23 -> V_259 , V_260 ) ;
V_23 -> V_259 = V_260 ;
F_87 ( V_23 , V_262 , V_164 , V_263 ,
V_264 ,
V_23 -> V_201 -> V_215 [ V_260 ] . V_265 , 0 ) ;
return 0 ;
}
static int F_88 ( struct V_88 * V_88 , void * V_89 , struct V_266 * V_267 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_54 -> V_257 . V_268 )
return - V_269 ;
if ( V_267 -> V_270 != 0 )
return - V_65 ;
F_89 ( V_23 , V_270 , V_271 , V_267 ) ;
return 0 ;
}
int F_90 ( struct V_88 * V_88 , void * V_89 , const struct V_266 * V_267 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( V_54 -> V_257 . V_268 )
return - V_269 ;
if ( V_267 -> V_270 != 0 )
return - V_65 ;
F_82 ( V_23 ) ;
F_21 ( L_9 , V_267 -> V_272 ) ;
F_89 ( V_23 , V_270 , V_273 , V_267 ) ;
F_84 ( V_23 ) ;
return 0 ;
}
static int F_91 ( struct V_88 * V_88 , void * V_89 , T_7 * V_248 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
* V_248 = V_23 -> V_248 ;
return 0 ;
}
void F_92 ( struct V_22 * V_23 , T_7 V_248 )
{
V_23 -> V_248 = V_248 ;
V_23 -> V_97 = ( V_248 & V_274 ) ? 1 : 0 ;
V_23 -> V_122 = ! V_23 -> V_97 ;
F_93 ( & V_23 -> V_37 , V_23 -> V_122 ) ;
V_23 -> V_37 . V_101 = 720 ;
V_23 -> V_37 . V_102 = V_23 -> V_122 ? 576 : 480 ;
V_23 -> V_113 . V_120 = V_23 -> V_122 ? 18 : 12 ;
V_23 -> V_113 . V_70 [ 0 ] = V_23 -> V_122 ? 6 : 10 ;
V_23 -> V_113 . V_70 [ 1 ] = V_23 -> V_122 ? 318 : 273 ;
if ( V_23 -> V_275 & V_276 )
V_23 -> V_113 . V_277 = V_23 -> V_97 ? 272 : 284 ;
F_89 ( V_23 , V_164 , V_278 , V_23 -> V_248 ) ;
}
void F_94 ( struct V_22 * V_23 , T_7 V_248 )
{
struct V_172 * V_173 = & V_23 -> V_127 ;
F_10 ( V_35 ) ;
int V_19 ;
V_23 -> V_279 = V_248 ;
V_23 -> V_280 = ( V_248 & V_274 ) ? 1 : 0 ;
V_23 -> V_225 = ! V_23 -> V_280 ;
F_89 ( V_23 , V_164 , V_281 , V_23 -> V_279 ) ;
F_13 ( & V_23 -> V_43 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_14 ( & V_23 -> V_282 , & V_35 ,
V_283 ) ;
if ( ( F_95 ( V_284 ) >> 16 ) < 100 )
break;
F_96 ( F_97 ( 25 ) ) ;
}
F_18 ( & V_23 -> V_282 , & V_35 ) ;
F_19 ( & V_23 -> V_43 ) ;
if ( V_19 == 4 )
F_98 ( L_10 ) ;
F_8 ( V_23 , V_285 , 1 , V_23 -> V_225 ) ;
V_23 -> V_125 . V_152 = 0 ;
V_23 -> V_125 . V_151 = 0 ;
V_23 -> V_125 . V_101 = 720 ;
V_23 -> V_125 . V_102 = V_23 -> V_225 ? 576 : 480 ;
F_8 ( V_23 , V_236 , 4 ,
720 , V_23 -> V_125 . V_102 , 0 , 0 ) ;
V_173 -> V_125 = V_23 -> V_125 ;
if ( ! V_23 -> V_286 ) {
V_173 -> V_234 = 720 ;
V_173 -> V_235 = V_23 -> V_225 ? 576 : 480 ;
}
}
static int F_99 ( struct V_88 * V_88 , void * V_89 , T_7 V_248 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ( V_248 & V_255 ) == 0 )
return - V_65 ;
if ( V_248 == V_23 -> V_248 )
return 0 ;
if ( F_15 ( V_287 , & V_23 -> V_47 ) ||
F_12 ( & V_23 -> V_159 ) > 0 ||
F_12 ( & V_23 -> V_40 ) > 0 ) {
return - V_75 ;
}
F_21 ( L_11 ,
( unsigned long long ) V_23 -> V_248 ) ;
F_92 ( V_23 , V_248 ) ;
if ( V_23 -> V_63 & V_64 )
F_94 ( V_23 , V_248 ) ;
return 0 ;
}
static int F_100 ( struct V_88 * V_88 , void * V_89 , const struct V_288 * V_289 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
if ( V_289 -> V_210 != 0 )
return - V_65 ;
F_89 ( V_23 , V_270 , V_290 , V_289 ) ;
return 0 ;
}
static int F_101 ( struct V_88 * V_88 , void * V_89 , struct V_288 * V_289 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( V_289 -> V_210 != 0 )
return - V_65 ;
F_89 ( V_23 , V_270 , V_291 , V_289 ) ;
if ( V_289 -> type == V_292 )
F_58 ( V_289 -> V_293 , L_12 , sizeof( V_289 -> V_293 ) ) ;
else
F_58 ( V_289 -> V_293 , L_13 , sizeof( V_289 -> V_293 ) ) ;
return 0 ;
}
static int F_102 ( struct V_88 * V_88 , void * V_89 , struct V_294 * V_295 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
int V_11 = V_23 -> V_122 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_295 -> type == V_170 ) {
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_23 -> V_122 ) )
V_295 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
}
}
} else if ( V_295 -> type == V_296 ) {
if ( ! ( V_23 -> V_63 & V_94 ) )
return - V_65 ;
if ( V_23 -> V_97 ) {
V_295 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_295 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_295 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_295 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
} else {
return - V_65 ;
}
V_11 = 0 ;
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ )
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ )
V_11 |= V_295 -> V_21 [ V_19 ] [ V_20 ] ;
V_295 -> V_18 = V_11 ;
return 0 ;
}
static int F_103 ( struct V_88 * V_88 , void * V_89 , struct V_297 * V_298 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_299 * V_300 = V_298 -> V_301 ;
int V_302 ;
int V_15 ;
V_302 = ( V_23 -> V_303 + V_304 - V_23 -> V_305 ) %
V_304 ;
if ( V_302 > V_306 )
V_302 = V_306 ;
V_298 -> V_302 = 0 ;
V_298 -> V_307 = V_304 ;
if ( ! F_12 ( & V_23 -> V_159 ) )
return 0 ;
for ( V_15 = 0 ; V_15 < V_302 ; V_15 ++ ) {
* V_300 = V_23 -> V_308 [ ( V_23 -> V_305 + V_15 ) % V_304 ] ;
if ( ( V_300 -> V_68 & V_309 ) <= V_310 ) {
V_298 -> V_302 ++ ;
V_300 ++ ;
}
}
V_23 -> V_305 = ( V_23 -> V_305 + V_298 -> V_302 ) % V_304 ;
return 0 ;
}
static int F_104 ( struct V_88 * V_88 , void * V_89 , struct V_311 * V_312 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
switch ( V_312 -> V_66 ) {
case V_313 :
F_105 ( L_14 ) ;
V_312 -> V_68 = 0 ;
return F_106 ( V_56 ) ;
case V_314 :
F_105 ( L_15 ) ;
V_312 -> V_68 &= V_315 ;
F_107 ( V_56 , V_312 -> V_68 & V_315 ) ;
return 0 ;
case V_316 :
F_105 ( L_16 ) ;
V_312 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_159 ) )
return - V_86 ;
if ( F_108 ( V_317 , & V_23 -> V_47 ) )
return 0 ;
F_82 ( V_23 ) ;
F_8 ( V_23 , V_318 , 1 , 0 ) ;
break;
case V_319 :
F_105 ( L_17 ) ;
V_312 -> V_68 = 0 ;
if ( ! F_12 ( & V_23 -> V_159 ) )
return - V_86 ;
if ( ! F_25 ( V_317 , & V_23 -> V_47 ) )
return 0 ;
F_8 ( V_23 , V_318 , 1 , 1 ) ;
F_84 ( V_23 ) ;
break;
default:
F_105 ( L_18 , V_312 -> V_66 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_109 ( struct V_88 * V_88 , void * V_89 , struct V_311 * V_312 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
switch ( V_312 -> V_66 ) {
case V_313 :
F_105 ( L_14 ) ;
V_312 -> V_68 = 0 ;
return 0 ;
case V_314 :
F_105 ( L_15 ) ;
V_312 -> V_68 &= V_315 ;
return 0 ;
case V_316 :
F_105 ( L_16 ) ;
V_312 -> V_68 = 0 ;
return 0 ;
case V_319 :
F_105 ( L_17 ) ;
V_312 -> V_68 = 0 ;
return 0 ;
default:
F_105 ( L_18 , V_312 -> V_66 ) ;
return - V_65 ;
}
}
static int F_110 ( struct V_88 * V_88 , void * V_89 , struct V_320 * V_321 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
T_2 V_32 [ V_33 ] ;
struct V_172 * V_173 = & V_23 -> V_127 ;
int V_99 ;
static T_2 V_322 [ 16 ] = {
V_323 ,
V_324 ,
V_325 ,
V_326 ,
V_327 ,
0 ,
0 ,
0 ,
V_323 ,
V_328 ,
V_329 ,
V_330 ,
V_331 ,
0 ,
0 ,
0 ,
} ;
if ( ! ( V_54 -> V_142 & V_143 ) )
return - V_269 ;
if ( ! V_23 -> V_144 )
return - V_269 ;
V_321 -> V_332 = V_333 | V_334 |
V_335 ;
F_111 ( V_23 , V_32 , V_336 , 0 ) ;
V_32 [ 0 ] |= ( F_95 ( 0x2a00 ) >> 7 ) & 0x40 ;
V_99 = ( V_32 [ 0 ] >> 3 ) & 0xf ;
V_321 -> V_17 . V_107 = V_322 [ V_99 ] ;
V_321 -> V_17 . V_101 = V_23 -> V_153 . V_101 ;
V_321 -> V_17 . V_102 = V_23 -> V_153 . V_102 ;
V_321 -> V_17 . V_9 = V_105 ;
V_321 -> V_17 . V_110 = V_321 -> V_17 . V_101 ;
V_321 -> V_17 . V_103 = V_104 ;
V_321 -> V_17 . V_9 = V_105 ;
if ( V_321 -> V_17 . V_107 != V_323 )
V_321 -> V_17 . V_110 *= 2 ;
if ( V_321 -> V_17 . V_107 == V_327 ||
V_321 -> V_17 . V_107 == V_331 )
V_321 -> V_17 . V_110 *= 2 ;
V_321 -> V_17 . V_109 = V_321 -> V_17 . V_110 * V_321 -> V_17 . V_102 ;
V_321 -> V_337 = ( void * ) V_23 -> V_144 ;
V_321 -> V_68 = 0 ;
if ( V_23 -> V_29 )
V_321 -> V_68 |= V_338 ;
if ( V_23 -> V_25 )
V_321 -> V_68 |= V_339 ;
if ( V_173 -> V_233 )
V_321 -> V_68 |= V_340 ;
V_99 &= 7 ;
if ( V_99 == 1 || V_99 > 4 )
return 0 ;
if ( V_99 == 2 || V_99 == 3 )
V_321 -> V_332 |= V_341 ;
else
V_321 -> V_332 |= V_342 ;
if ( V_23 -> V_27 ) {
if ( V_99 == 2 || V_99 == 3 )
V_321 -> V_68 |= V_343 ;
else
V_321 -> V_68 |= V_344 ;
}
return 0 ;
}
static int F_112 ( struct V_88 * V_88 , void * V_89 , const struct V_320 * V_321 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
struct V_172 * V_173 = & V_23 -> V_127 ;
if ( ! ( V_54 -> V_142 & V_143 ) )
return - V_269 ;
if ( ! V_23 -> V_144 )
return - V_269 ;
V_23 -> V_25 = ( V_321 -> V_68 & V_339 ) != 0 ;
V_23 -> V_27 =
( V_321 -> V_68 & ( V_344 | V_343 ) ) != 0 ;
V_23 -> V_29 = ( V_321 -> V_68 & V_338 ) != 0 ;
F_7 ( V_23 ) ;
V_173 -> V_233 = ( V_321 -> V_68 & V_340 ) != 0 ;
return 0 ;
}
static int F_113 ( struct V_88 * V_88 , void * V_89 , unsigned int V_345 )
{
struct V_55 * V_56 = F_30 ( V_89 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
struct V_60 * V_54 = & V_23 -> V_61 [ F_30 ( V_89 ) -> type ] ;
if ( ! ( V_54 -> V_142 & V_143 ) )
return - V_269 ;
if ( ! V_23 -> V_144 )
return - V_269 ;
F_8 ( V_23 , V_346 , 1 , V_345 != 0 ) ;
return 0 ;
}
static int F_114 ( struct V_347 * V_89 , const struct V_348 * V_349 )
{
switch ( V_349 -> type ) {
case V_350 :
case V_351 :
return F_115 ( V_89 , V_349 , 0 , NULL ) ;
case V_352 :
return F_115 ( V_89 , V_349 , 0 , & V_353 ) ;
default:
return - V_65 ;
}
}
static int F_116 ( struct V_88 * V_88 , void * V_89 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
int V_354 = V_23 -> V_63 & V_64 ;
struct V_216 V_355 ;
struct V_208 V_356 ;
int V_15 ;
F_117 ( L_19 , V_357 , V_23 -> V_202 ) ;
if ( V_23 -> V_275 & V_358 ) {
struct V_359 V_360 ;
F_118 ( V_23 , & V_360 ) ;
}
F_89 ( V_23 , V_361 , V_362 ) ;
F_70 ( V_23 , V_23 -> V_246 , & V_355 ) ;
F_61 ( V_23 , V_23 -> V_211 , & V_356 ) ;
F_117 ( L_20 , V_355 . V_293 ) ;
F_117 ( L_21 , V_356 . V_293 ,
( V_23 -> V_363 & ~ 0x300 ) == 0x200 ? L_22 : L_23 ) ;
if ( V_354 ) {
struct V_217 V_364 ;
struct V_214 V_365 ;
int V_366 = V_23 -> V_82 ;
static const char * const V_367 [ 5 ] = {
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
} ;
static const char * const V_368 [ 4 ] = {
L_24 ,
L_29 ,
L_30 ,
L_31
} ;
static const char * const V_322 [ 16 ] = {
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
F_72 ( V_23 , V_23 -> V_259 , & V_364 ) ;
F_66 ( V_23 , 0 , & V_365 ) ;
F_117 ( L_48 , V_364 . V_293 ) ;
if ( V_366 < 0 || V_366 > V_369 )
V_366 = V_83 ;
F_117 ( L_49 , V_367 [ V_366 ] ) ;
F_111 ( V_23 , V_32 , V_336 , 0 ) ;
V_32 [ 0 ] |= ( F_95 ( 0x2a00 ) >> 7 ) & 0x40 ;
F_117 ( L_50 ,
V_32 [ 0 ] & 1 ? L_51 : L_52 ,
V_368 [ ( V_32 [ 0 ] >> 1 ) & 0x3 ] ,
V_322 [ ( V_32 [ 0 ] >> 3 ) & 0xf ] ) ;
}
F_117 ( L_53 ,
F_15 ( V_287 , & V_23 -> V_47 ) ? L_54 : L_55 ) ;
F_119 ( & V_23 -> V_37 . V_370 , V_23 -> V_371 . V_293 ) ;
F_117 ( L_56 , V_23 -> V_47 ) ;
for ( V_15 = 0 ; V_15 < V_372 ; V_15 ++ ) {
struct V_60 * V_54 = & V_23 -> V_61 [ V_15 ] ;
if ( V_54 -> V_257 . V_371 == NULL || V_54 -> V_373 == 0 )
continue;
F_117 ( L_57 , V_54 -> V_293 , V_54 -> V_374 ,
( V_54 -> V_373 - V_54 -> V_375 . V_373 ) * 100 / V_54 -> V_373 ,
( V_54 -> V_373 * V_54 -> V_376 ) / 1024 , V_54 -> V_373 ) ;
}
F_117 ( L_58 ,
( long long ) V_23 -> V_377 ,
( long long ) V_23 -> V_378 ) ;
return 0 ;
}
static int F_120 ( struct V_88 * V_88 , void * V_89 , struct V_57 * V_379 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_198 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
F_105 ( L_59 , V_379 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_379 , false ) ;
}
static int F_121 ( struct V_88 * V_88 , void * V_89 , struct V_57 * V_379 )
{
struct V_55 * V_56 = F_30 ( V_88 -> V_198 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
F_105 ( L_60 , V_379 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_379 , true ) ;
}
static int F_122 ( struct V_88 * V_380 , unsigned int V_66 , void * V_381 )
{
struct V_55 * V_56 = F_30 ( V_380 -> V_198 ) ;
struct V_22 * V_23 = V_56 -> V_23 ;
int V_382 = V_380 -> V_383 & V_384 ;
struct V_60 * V_54 = & V_23 -> V_61 [ V_56 -> type ] ;
unsigned long V_385 = ( unsigned long ) V_381 ;
switch ( V_66 ) {
case V_386 : {
struct V_387 * args = V_381 ;
F_105 ( L_61 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
if ( args -> type != V_224 )
return - V_65 ;
if ( V_23 -> V_82 == V_388 && args -> V_389 == NULL )
return 0 ;
if ( F_26 ( V_56 , V_56 -> type ) ) {
return - V_75 ;
}
if ( F_24 ( V_23 , V_388 ) != V_388 ) {
F_123 ( V_54 ) ;
return - V_75 ;
}
V_56 -> V_390 = 1 ;
if ( args -> V_389 == NULL )
return 0 ;
return F_124 ( V_23 , args ) ;
}
case V_391 :
F_105 ( L_62 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_125 ( V_23 , * ( int * ) V_381 != 0 ) ;
case V_392 : {
T_8 * V_81 = V_381 ;
T_8 V_393 ;
F_105 ( L_63 ) ;
if ( V_54 -> type < V_62 ) {
* V_81 = V_54 -> V_394 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_126 ( V_23 , V_81 , & V_393 ) ;
}
case V_395 : {
T_8 * V_393 = V_381 ;
T_8 V_81 ;
F_105 ( L_64 ) ;
if ( V_54 -> type < V_62 ) {
* V_393 = 0 ;
break;
}
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_126 ( V_23 , & V_81 , V_393 ) ;
}
case V_396 : {
struct V_57 V_58 ;
F_105 ( L_65 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_67 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_397 : {
struct V_57 V_58 ;
F_105 ( L_66 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_77 ;
V_58 . V_68 = V_79 | V_78 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_398 : {
struct V_57 V_58 ;
F_105 ( L_67 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_84 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_399 : {
struct V_57 V_58 ;
F_105 ( L_68 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_66 = V_87 ;
return F_23 ( V_23 , V_56 , & V_58 , 0 ) ;
}
case V_400 :
case V_401 : {
struct V_57 * V_58 = V_381 ;
int V_59 = ( V_66 == V_401 ) ;
if ( V_59 )
F_105 ( L_69 , V_58 -> V_66 ) ;
else
F_105 ( L_70 , V_58 -> V_66 ) ;
return F_23 ( V_23 , V_56 , V_58 , V_59 ) ;
}
case V_402 : {
struct V_403 * V_404 = V_381 ;
F_10 ( V_35 ) ;
F_105 ( L_71 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
memset ( V_404 , 0 , sizeof( * V_404 ) ) ;
F_28 ( V_405 , & V_23 -> V_47 ) ;
while ( 1 ) {
if ( F_25 ( V_406 , & V_23 -> V_47 ) )
V_404 -> type = V_407 ;
else if ( F_25 ( V_408 , & V_23 -> V_47 ) ) {
V_404 -> type = V_409 ;
V_404 -> V_410 . V_411 = F_15 ( V_412 , & V_23 -> V_47 ) ?
V_413 : V_414 ;
if ( V_23 -> V_82 == V_388 &&
( V_23 -> V_127 . V_128 & V_129 ) ==
V_134 ) {
V_404 -> V_410 . V_411 = V_415 ;
}
}
if ( V_404 -> type )
return 0 ;
if ( V_382 )
return - V_416 ;
F_13 ( & V_23 -> V_43 ) ;
F_14 ( & V_23 -> V_417 , & V_35 , V_45 ) ;
if ( ! F_15 ( V_406 , & V_23 -> V_47 ) &&
! F_15 ( V_408 , & V_23 -> V_47 ) )
F_17 () ;
F_18 ( & V_23 -> V_417 , & V_35 ) ;
F_19 ( & V_23 -> V_43 ) ;
if ( F_16 ( V_48 ) ) {
F_21 ( L_72 ) ;
return - V_49 ;
}
}
break;
}
case V_418 :
F_105 ( L_73 ) ;
if ( ! ( V_23 -> V_63 & V_64 ) )
return - V_65 ;
return F_125 ( V_23 , V_385 == V_419 ) ;
case V_420 :
F_105 ( L_74 ) ;
V_23 -> V_39 = V_385 ;
return 0 ;
case V_421 :
F_105 ( L_75 ) ;
if ( V_385 > V_422 )
return - V_65 ;
return F_127 ( V_23 -> V_423 , V_385 + 1 ) ;
case V_424 :
F_105 ( L_76 ) ;
if ( V_385 > V_422 )
return - V_65 ;
return F_127 ( V_23 -> V_425 , V_385 + 1 ) ;
default:
return - V_65 ;
}
return 0 ;
}
static long F_128 ( struct V_88 * V_88 , void * V_89 , bool V_426 ,
unsigned int V_66 , void * V_381 )
{
struct V_22 * V_23 = F_30 ( V_89 ) -> V_23 ;
if ( ! V_426 ) {
switch ( V_66 ) {
case V_391 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_418 :
case V_420 :
case V_421 :
case V_424 :
return - V_75 ;
}
}
switch ( V_66 ) {
case V_427 : {
T_2 V_183 = * ( T_2 * ) V_381 ;
if ( ( V_183 == 0 && V_23 -> V_428 . V_429 ) || ( V_183 & 0x01 ) )
F_129 ( V_23 ) ;
if ( V_183 & 0x02 )
F_34 ( V_23 -> V_123 , V_361 , V_430 , 0 ) ;
break;
}
case V_386 :
case V_391 :
case V_392 :
case V_395 :
case V_402 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
case V_418 :
case V_420 :
case V_421 :
case V_424 :
return F_122 ( V_88 , V_66 , ( void * ) V_381 ) ;
default:
return - V_269 ;
}
return 0 ;
}
void F_130 ( struct V_431 * V_257 )
{
V_257 -> V_432 = & V_433 ;
}
