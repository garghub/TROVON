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
F_13 ( & V_23 -> V_47 , & V_37 , V_48 ) ;
while ( F_14 ( V_49 , & V_23 -> V_50 ) ) {
V_45 = F_15 ( V_51 ) ;
if ( V_45 )
break;
V_45 = 0 ;
F_16 () ;
}
F_17 ( & V_23 -> V_47 , & V_37 ) ;
if ( V_45 )
return - V_52 ;
F_18 ( V_23 , V_53 , 7 , V_32 ) ;
F_19 ( L_1 ,
V_32 [ 0 ] , V_32 [ 1 ] , V_32 [ 2 ] , V_32 [ 3 ] , V_32 [ 4 ] , V_32 [ 5 ] , V_32 [ 6 ] ) ;
}
if ( V_36 ) {
V_31 = ( V_31 < 0 ) ? - 1 : 1 ;
F_8 ( V_23 , V_40 , 1 , 0 ) ;
}
V_23 -> V_31 = V_31 ;
return 0 ;
}
static int F_20 ( int V_54 , int V_55 )
{
int V_56 = V_55 < 0 ? - 1 : 1 ;
int V_35 ;
if ( V_54 == 0 )
V_54 = 1000 ;
if ( V_55 < 0 )
V_55 = - V_55 ;
if ( V_54 < 0 )
V_54 = - V_54 ;
if ( V_54 <= V_55 ) {
if ( V_55 > 1500 )
return V_56 * 2000 ;
if ( V_55 > 1000 )
return V_56 * 1500 ;
}
else {
if ( V_55 >= 2000 )
return V_56 * 2000 ;
if ( V_55 >= 1500 )
return V_56 * 1500 ;
if ( V_55 >= 1000 )
return V_56 * 1000 ;
}
if ( V_55 == 0 )
return 1000 ;
if ( V_55 == 1 || V_55 == 1000 )
return V_56 * V_55 ;
V_35 = V_55 ;
V_55 = 1000 / V_55 ;
if ( 1000 / V_54 == V_55 )
V_55 += ( V_54 < V_35 ) ? - 1 : 1 ;
if ( V_55 > 60 ) return 1000 / ( V_56 * 60 ) ;
return 1000 / ( V_56 * V_55 ) ;
}
static int F_21 ( struct V_22 * V_23 , struct V_57 * V_58 ,
struct V_59 * V_60 , int V_61 )
{
struct V_34 * V_35 = & V_23 -> V_38 [ V_39 ] ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
switch ( V_60 -> V_65 ) {
case V_66 : {
V_60 -> V_67 = 0 ;
V_60 -> V_68 . V_31 = F_20 ( V_23 -> V_31 , V_60 -> V_68 . V_31 ) ;
if ( V_60 -> V_68 . V_31 < 0 )
V_60 -> V_68 . V_69 = V_70 ;
if ( V_61 ) break;
if ( F_22 ( V_23 , V_71 ) != V_71 )
return - V_72 ;
if ( F_23 ( V_73 , & V_23 -> V_50 ) ) {
V_23 -> V_31 = 0 ;
}
return F_24 ( V_58 , V_60 -> V_68 . V_31 ) ;
}
case V_74 :
V_60 -> V_67 &= V_75 | V_76 ;
if ( V_60 -> V_67 & V_75 )
V_60 -> V_77 . V_78 = 0 ;
if ( V_61 ) break;
if ( F_12 ( & V_23 -> V_44 ) == 0 )
return 0 ;
if ( V_23 -> V_79 != V_71 )
return - V_72 ;
V_23 -> V_79 = V_80 ;
return F_25 ( V_35 , V_60 -> V_67 , V_60 -> V_77 . V_78 ) ;
case V_81 :
V_60 -> V_67 &= V_82 ;
if ( V_61 ) break;
if ( V_23 -> V_79 != V_71 )
return - V_72 ;
if ( F_12 ( & V_23 -> V_44 ) > 0 ) {
F_8 ( V_23 , V_46 , 1 ,
( V_60 -> V_67 & V_82 ) ? 1 : 0 ) ;
F_26 ( V_73 , & V_23 -> V_50 ) ;
}
break;
case V_83 :
V_60 -> V_67 = 0 ;
if ( V_61 ) break;
if ( V_23 -> V_79 != V_71 )
return - V_72 ;
if ( F_23 ( V_73 , & V_23 -> V_50 ) ) {
int V_31 = V_23 -> V_31 ;
V_23 -> V_31 = 0 ;
return F_24 ( V_58 , V_31 ) ;
}
break;
default:
return - V_64 ;
}
return 0 ;
}
static int F_27 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
struct V_16 * V_87 = & V_17 -> V_17 . V_88 ;
V_87 -> V_89 [ 0 ] = 0 ;
V_87 -> V_89 [ 1 ] = 0 ;
if ( ! ( V_23 -> V_62 & V_90 ) )
return - V_64 ;
V_87 -> V_91 = sizeof( struct V_92 ) * 36 ;
if ( V_23 -> V_93 ) {
V_87 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_87 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_87 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_87 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
V_87 -> V_18 = F_6 ( V_87 ) ;
return 0 ;
}
static int F_29 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_94 * V_95 = & V_17 -> V_17 . V_96 ;
V_95 -> V_97 = V_23 -> V_41 . V_97 ;
V_95 -> V_98 = V_23 -> V_41 . V_98 ;
V_95 -> V_99 = V_100 ;
V_95 -> V_9 = V_101 ;
V_95 -> V_102 = 0 ;
if ( V_58 -> type == V_103 ) {
V_95 -> V_104 = V_105 ;
V_95 -> V_106 = V_95 -> V_98 * 720 * 3 / 2 ;
V_95 -> V_107 = 720 ;
} else {
V_95 -> V_104 = V_108 ;
V_95 -> V_106 = 128 * 1024 ;
V_95 -> V_107 = 0 ;
}
return 0 ;
}
static int F_30 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
struct V_109 * V_87 = & V_17 -> V_17 . V_110 ;
V_87 -> V_111 = 27000000 ;
V_87 -> V_112 = 248 ;
V_87 -> V_113 = V_23 -> V_110 . V_114 - 4 ;
V_87 -> V_115 = V_116 ;
V_87 -> V_117 [ 0 ] = V_23 -> V_110 . V_117 [ 0 ] ;
V_87 -> V_117 [ 1 ] = V_23 -> V_110 . V_117 [ 1 ] ;
V_87 -> V_118 [ 0 ] = V_87 -> V_118 [ 1 ] = V_23 -> V_110 . V_118 ;
V_87 -> V_67 = 0 ;
V_87 -> V_89 [ 0 ] = 0 ;
V_87 -> V_89 [ 1 ] = 0 ;
return 0 ;
}
static int F_31 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_16 * V_87 = & V_17 -> V_17 . V_88 ;
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
V_87 -> V_89 [ 0 ] = 0 ;
V_87 -> V_89 [ 1 ] = 0 ;
V_87 -> V_91 = sizeof( struct V_92 ) * 36 ;
if ( V_58 -> type == V_119 ) {
V_87 -> V_18 = V_23 -> V_120 ? V_13 :
V_14 ;
F_4 ( V_87 , V_23 -> V_120 ) ;
return 0 ;
}
F_32 ( V_23 -> V_121 , V_110 , V_122 , V_87 ) ;
V_87 -> V_18 = F_6 ( V_87 ) ;
return 0 ;
}
static int F_33 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_94 * V_95 = & V_17 -> V_17 . V_96 ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
V_95 -> V_97 = V_23 -> V_123 . V_97 ;
V_95 -> V_98 = V_23 -> V_123 . V_98 ;
V_95 -> V_99 = V_100 ;
V_95 -> V_9 = V_101 ;
V_95 -> V_102 = 0 ;
if ( V_58 -> type == V_124 ) {
switch ( V_23 -> V_125 . V_126 & V_127 ) {
case V_128 :
V_95 -> V_9 = ( V_23 -> V_125 . V_126 & V_129 ) ?
V_130 : V_131 ;
break;
case V_132 :
V_95 -> V_9 = V_133 ;
break;
default:
V_95 -> V_9 = V_134 ;
break;
}
V_95 -> V_104 = V_105 ;
V_95 -> V_107 = 720 ;
V_95 -> V_97 = V_23 -> V_125 . V_135 ;
V_95 -> V_98 = V_23 -> V_125 . V_136 ;
V_95 -> V_106 =
1080 * ( ( V_95 -> V_98 + 31 ) & ~ 31 ) ;
} else {
V_95 -> V_104 = V_108 ;
V_95 -> V_106 = 128 * 1024 ;
V_95 -> V_107 = 0 ;
}
return 0 ;
}
static int F_34 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
struct V_137 * V_138 = & V_17 -> V_17 . V_139 ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
V_138 -> V_140 = V_23 -> V_30 ;
V_138 -> V_141 = V_23 -> V_26 ;
V_138 -> V_9 = V_101 ;
V_138 -> V_142 = NULL ;
V_138 -> V_143 = 0 ;
V_138 -> V_144 = NULL ;
V_138 -> V_145 . V_146 = V_138 -> V_145 . V_147 = 0 ;
V_138 -> V_145 . V_97 = V_23 -> V_148 . V_97 ;
V_138 -> V_145 . V_98 = V_23 -> V_148 . V_98 ;
return 0 ;
}
static int F_35 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
return F_27 ( V_84 , V_85 , V_17 ) ;
}
static int F_36 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
int V_145 = V_17 -> V_17 . V_96 . V_97 ;
int V_149 = V_17 -> V_17 . V_96 . V_98 ;
int V_150 = 2 ;
V_145 = F_37 ( V_145 , 720 ) ;
V_145 = F_38 ( V_145 , 2 ) ;
if ( V_58 -> type == V_103 ) {
V_149 &= ~ 0x1f ;
V_150 = 32 ;
}
V_149 = F_37 ( V_149 , V_23 -> V_120 ? 576 : 480 ) ;
V_149 = F_38 ( V_149 , V_150 ) ;
F_29 ( V_84 , V_85 , V_17 ) ;
V_17 -> V_17 . V_96 . V_97 = V_145 ;
V_17 -> V_17 . V_96 . V_98 = V_149 ;
return 0 ;
}
static int F_39 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
return F_30 ( V_84 , V_85 , V_17 ) ;
}
static int F_40 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_16 * V_87 = & V_17 -> V_17 . V_88 ;
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
if ( V_58 -> type == V_119 )
return F_31 ( V_84 , V_85 , V_17 ) ;
V_87 -> V_91 = sizeof( struct V_92 ) * 36 ;
V_87 -> V_89 [ 0 ] = 0 ;
V_87 -> V_89 [ 1 ] = 0 ;
if ( V_87 -> V_18 )
F_4 ( V_87 , V_23 -> V_120 ) ;
F_5 ( V_87 , V_23 -> V_120 ) ;
V_87 -> V_18 = F_6 ( V_87 ) ;
return 0 ;
}
static int F_41 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
T_3 V_145 = V_17 -> V_17 . V_96 . V_97 ;
T_3 V_149 = V_17 -> V_17 . V_96 . V_98 ;
int V_9 = V_17 -> V_17 . V_96 . V_9 ;
int V_151 = F_33 ( V_84 , V_85 , V_17 ) ;
V_145 = F_37 ( V_145 , 720 ) ;
V_145 = F_38 ( V_145 , 2 ) ;
V_149 = F_37 ( V_149 , 576 ) ;
V_149 = F_38 ( V_149 , 2 ) ;
if ( V_58 -> type == V_124 )
V_17 -> V_17 . V_96 . V_9 = V_9 ;
V_17 -> V_17 . V_96 . V_97 = V_145 ;
V_17 -> V_17 . V_96 . V_98 = V_149 ;
return V_151 ;
}
static int F_42 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
T_2 V_140 = V_17 -> V_17 . V_139 . V_140 ;
T_4 V_141 = V_17 -> V_17 . V_139 . V_141 ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
F_34 ( V_84 , V_85 , V_17 ) ;
V_17 -> V_17 . V_139 . V_140 = V_140 ;
V_17 -> V_17 . V_139 . V_141 = V_141 ;
return 0 ;
}
static int F_43 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
return F_27 ( V_84 , V_85 , V_17 ) ;
}
static int F_44 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_152 V_153 ;
int V_151 = F_36 ( V_84 , V_85 , V_17 ) ;
int V_145 = V_17 -> V_17 . V_96 . V_97 ;
int V_149 = V_17 -> V_17 . V_96 . V_98 ;
if ( V_151 )
return V_151 ;
if ( V_23 -> V_41 . V_97 == V_145 && V_23 -> V_41 . V_98 == V_149 )
return 0 ;
if ( F_12 ( & V_23 -> V_154 ) > 0 )
return - V_72 ;
V_23 -> V_41 . V_97 = V_145 ;
V_23 -> V_41 . V_98 = V_149 ;
if ( F_11 ( V_23 -> V_41 . V_155 ) == V_156 )
V_17 -> V_17 . V_96 . V_97 /= 2 ;
V_153 . V_97 = V_17 -> V_17 . V_96 . V_97 ;
V_153 . V_98 = V_149 ;
V_153 . V_157 = V_158 ;
F_32 ( V_23 -> V_121 , V_159 , V_160 , & V_153 ) ;
return F_29 ( V_84 , V_85 , V_17 ) ;
}
static int F_45 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( ! F_46 ( V_23 ) && F_12 ( & V_23 -> V_154 ) > 0 )
return - V_72 ;
V_23 -> V_110 . V_161 -> V_18 = 0 ;
V_23 -> V_110 . V_162 . type = V_163 ;
F_32 ( V_23 -> V_121 , V_110 , V_164 , & V_17 -> V_17 . V_110 ) ;
return F_30 ( V_84 , V_85 , V_17 ) ;
}
static int F_47 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_16 * V_87 = & V_17 -> V_17 . V_88 ;
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
int V_151 = F_40 ( V_84 , V_85 , V_17 ) ;
if ( V_151 || V_58 -> type == V_119 )
return V_151 ;
F_5 ( V_87 , V_23 -> V_120 ) ;
if ( F_46 ( V_23 ) && F_12 ( & V_23 -> V_154 ) > 0 )
return - V_72 ;
V_23 -> V_110 . V_162 . type = V_165 ;
F_32 ( V_23 -> V_121 , V_110 , V_166 , V_87 ) ;
memcpy ( V_23 -> V_110 . V_161 , V_87 , sizeof( * V_23 -> V_110 . V_161 ) ) ;
return 0 ;
}
static int F_48 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_151 = F_41 ( V_84 , V_85 , V_17 ) ;
if ( V_151 )
return V_151 ;
if ( V_58 -> type != V_124 )
return 0 ;
if ( V_168 -> V_169 )
return - V_72 ;
V_168 -> V_135 = V_17 -> V_17 . V_96 . V_97 ;
V_168 -> V_136 = V_17 -> V_17 . V_96 . V_98 ;
switch ( V_17 -> V_17 . V_96 . V_9 ) {
case V_133 :
V_168 -> V_126 = V_132 ;
break;
case V_134 :
V_168 -> V_126 = V_170 ;
break;
case V_130 :
V_168 -> V_126 =
V_128 | V_171 ;
break;
case V_131 :
default:
V_168 -> V_126 = V_128 ;
break;
}
V_168 -> V_172 = ( V_168 -> V_126 & V_129 ) == V_173 ? 0 : 1 ;
if ( F_14 ( V_174 , & V_23 -> V_50 ) )
V_23 -> V_175 =
1080 * ( ( V_168 -> V_136 + 31 ) & ~ 31 ) ;
return 0 ;
}
static int F_49 ( struct V_84 * V_84 , void * V_85 , struct V_86 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
int V_151 = F_42 ( V_84 , V_85 , V_17 ) ;
if ( V_151 == 0 ) {
V_23 -> V_30 = V_17 -> V_17 . V_139 . V_140 ;
V_23 -> V_26 = V_17 -> V_17 . V_139 . V_141 ;
F_7 ( V_23 ) ;
}
return V_151 ;
}
static int F_50 ( struct V_84 * V_84 , void * V_85 , struct V_176 * V_177 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
V_177 -> V_178 = V_179 ;
V_177 -> V_180 = 0 ;
if ( V_177 -> V_181 . type == V_182 ) {
if ( F_51 ( & V_177 -> V_181 ) )
V_177 -> V_178 = V_23 -> V_183 ? V_184 : V_185 ;
return 0 ;
}
if ( V_177 -> V_181 . type != V_186 &&
V_177 -> V_181 . type != V_187 )
return - V_64 ;
return F_52 ( V_23 , V_188 , V_189 , V_177 ) ;
}
static int F_53 ( struct V_22 * V_23 , unsigned int V_65 , void * V_190 )
{
struct V_191 * V_192 = V_190 ;
volatile T_4 T_5 * V_193 ;
if ( ! F_54 ( V_194 ) )
return - V_195 ;
if ( V_192 -> V_196 >= V_197 && V_192 -> V_196 < V_197 + V_198 )
V_193 = V_23 -> V_199 - V_197 ;
else if ( V_23 -> V_183 && V_192 -> V_196 >= V_200 &&
V_192 -> V_196 < V_200 + V_201 )
V_193 = V_23 -> V_202 - V_200 ;
else if ( V_192 -> V_196 < V_203 )
V_193 = V_23 -> V_204 ;
else
return - V_64 ;
V_192 -> V_205 = 4 ;
if ( V_65 == V_206 )
V_192 -> V_207 = F_55 ( V_192 -> V_196 + V_193 ) ;
else
F_56 ( V_192 -> V_207 , V_192 -> V_196 + V_193 ) ;
return 0 ;
}
static int F_57 ( struct V_84 * V_84 , void * V_85 , struct V_191 * V_196 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( F_51 ( & V_196 -> V_181 ) )
return F_53 ( V_23 , V_206 , V_196 ) ;
F_58 ( V_23 , V_188 , V_208 , V_196 ) ;
return 0 ;
}
static int F_59 ( struct V_84 * V_84 , void * V_85 , struct V_191 * V_196 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( F_51 ( & V_196 -> V_181 ) )
return F_53 ( V_23 , V_209 , V_196 ) ;
F_58 ( V_23 , V_188 , V_210 , V_196 ) ;
return 0 ;
}
static int F_60 ( struct V_84 * V_84 , void * V_85 , struct V_211 * V_212 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
F_61 ( V_212 -> V_213 , V_214 , sizeof( V_212 -> V_213 ) ) ;
F_61 ( V_212 -> V_215 , V_23 -> V_216 , sizeof( V_212 -> V_215 ) ) ;
snprintf ( V_212 -> V_217 , sizeof( V_212 -> V_217 ) , L_2 , F_62 ( V_23 -> V_218 ) ) ;
V_212 -> V_219 = V_220 ;
V_212 -> V_221 = V_23 -> V_62 ;
return 0 ;
}
static int F_63 ( struct V_84 * V_84 , void * V_85 , struct V_222 * V_223 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_64 ( V_23 , V_223 -> V_224 , V_223 ) ;
}
static int F_65 ( struct V_84 * V_84 , void * V_85 , struct V_222 * V_223 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
V_223 -> V_224 = V_23 -> V_225 ;
return F_64 ( V_23 , V_223 -> V_224 , V_223 ) ;
}
static int F_66 ( struct V_84 * V_84 , void * V_85 , struct V_222 * V_226 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_226 -> V_224 >= V_23 -> V_227 )
return - V_64 ;
V_23 -> V_225 = V_226 -> V_224 ;
F_67 ( V_23 ) ;
return 0 ;
}
static int F_68 ( struct V_84 * V_84 , void * V_85 , struct V_228 * V_223 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_69 ( V_23 , V_223 -> V_224 , V_223 ) ;
}
static int F_70 ( struct V_84 * V_84 , void * V_85 , struct V_228 * V_223 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
V_223 -> V_224 = 0 ;
return F_69 ( V_23 , V_223 -> V_224 , V_223 ) ;
}
static int F_71 ( struct V_84 * V_84 , void * V_85 , struct V_228 * V_226 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_69 ( V_23 , V_226 -> V_224 , V_226 ) ;
}
static int F_72 ( struct V_84 * V_84 , void * V_85 , struct V_229 * V_223 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_73 ( V_23 , V_223 -> V_224 , V_223 ) ;
}
static int F_74 ( struct V_84 * V_84 , void * V_85 , struct V_230 * V_226 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_75 ( V_23 , V_226 -> V_224 , V_226 ) ;
}
static int F_76 ( struct V_84 * V_84 , void * V_85 , struct V_231 * V_232 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_233 ;
V_233 = V_58 -> type ;
if ( V_232 -> type != V_234 )
return - V_64 ;
V_232 -> V_235 . V_146 = V_232 -> V_235 . V_147 = 0 ;
V_232 -> V_235 . V_97 = 720 ;
if ( V_232 -> type == V_236 ) {
V_232 -> V_235 . V_98 = V_23 -> V_120 ? 576 : 480 ;
V_232 -> V_237 . V_238 = V_23 -> V_120 ? 59 : 10 ;
V_232 -> V_237 . V_239 = V_23 -> V_120 ? 54 : 11 ;
} else if ( V_233 == V_124 ) {
if ( V_168 -> V_240 ) {
V_232 -> V_235 . V_97 = V_168 -> V_241 ;
V_232 -> V_235 . V_98 = V_168 -> V_242 ;
} else {
V_232 -> V_235 . V_97 = 720 ;
V_232 -> V_235 . V_98 =
V_23 -> V_243 ? 576 : 480 ;
}
V_232 -> V_237 . V_238 = V_23 -> V_243 ? 59 : 10 ;
V_232 -> V_237 . V_239 = V_23 -> V_243 ? 54 : 11 ;
} else {
V_232 -> V_235 . V_98 = V_23 -> V_243 ? 576 : 480 ;
V_232 -> V_237 . V_238 = V_23 -> V_243 ? 59 : 10 ;
V_232 -> V_237 . V_239 = V_23 -> V_243 ? 54 : 11 ;
}
V_232 -> V_244 = V_232 -> V_235 ;
return 0 ;
}
static int F_77 ( struct V_84 * V_84 , void * V_85 , struct V_245 * V_246 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_233 ;
V_233 = V_58 -> type ;
if ( V_246 -> type == V_234 &&
( V_23 -> V_62 & V_63 ) ) {
if ( V_233 == V_124 ) {
V_168 -> V_123 = V_246 -> V_247 ;
return 0 ;
} else {
if ( ! F_8 ( V_23 , V_248 , 4 ,
V_246 -> V_247 . V_97 , V_246 -> V_247 . V_98 , V_246 -> V_247 . V_147 , V_246 -> V_247 . V_146 ) ) {
V_23 -> V_123 = V_246 -> V_247 ;
return 0 ;
}
}
return - V_64 ;
}
return - V_64 ;
}
static int F_78 ( struct V_84 * V_84 , void * V_85 , struct V_245 * V_246 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_233 ;
V_233 = V_58 -> type ;
if ( V_246 -> type == V_234 &&
( V_23 -> V_62 & V_63 ) ) {
if ( V_233 == V_124 )
V_246 -> V_247 = V_168 -> V_123 ;
else
V_246 -> V_247 = V_23 -> V_123 ;
return 0 ;
}
return - V_64 ;
}
static int F_79 ( struct V_84 * V_84 , void * V_85 , struct V_249 * V_17 )
{
static struct V_249 V_250 [] = {
{ 0 , 0 , 0 ,
L_3 , V_105 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_251 ,
L_4 , V_108 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_252 type = V_17 -> type ;
if ( V_17 -> V_224 > 1 )
return - V_64 ;
* V_17 = V_250 [ V_17 -> V_224 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_80 ( struct V_84 * V_84 , void * V_85 , struct V_249 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
static struct V_249 V_250 [] = {
{ 0 , 0 , 0 ,
L_3 , V_105 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_251 ,
L_4 , V_108 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_252 type = V_17 -> type ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( V_17 -> V_224 > 1 )
return - V_64 ;
* V_17 = V_250 [ V_17 -> V_224 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_81 ( struct V_84 * V_84 , void * V_85 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
* V_15 = V_23 -> V_253 ;
return 0 ;
}
int F_82 ( struct V_84 * V_84 , void * V_85 , unsigned int V_254 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_254 < 0 || V_254 >= V_23 -> V_255 )
return - V_64 ;
if ( V_254 == V_23 -> V_253 ) {
F_19 ( L_5 ) ;
return 0 ;
}
if ( F_12 ( & V_23 -> V_154 ) > 0 ) {
return - V_72 ;
}
F_19 ( L_6 ,
V_23 -> V_253 , V_254 ) ;
V_23 -> V_253 = V_254 ;
V_23 -> V_225 = V_23 -> V_215 -> V_256 [ V_254 ] . V_257 ;
F_83 ( V_23 ) ;
F_84 ( V_23 ) ;
F_67 ( V_23 ) ;
F_85 ( V_23 ) ;
return 0 ;
}
static int F_86 ( struct V_84 * V_84 , void * V_85 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
* V_15 = V_23 -> V_258 ;
return 0 ;
}
static int F_87 ( struct V_84 * V_84 , void * V_85 , unsigned int V_259 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_259 >= V_23 -> V_215 -> V_260 )
return - V_64 ;
if ( V_259 == V_23 -> V_258 ) {
F_19 ( L_7 ) ;
return 0 ;
}
F_19 ( L_8 ,
V_23 -> V_258 , V_259 ) ;
V_23 -> V_258 = V_259 ;
F_88 ( V_23 , V_261 , V_159 , V_262 ,
V_263 ,
V_23 -> V_215 -> V_264 [ V_259 ] . V_265 , 0 ) ;
return 0 ;
}
static int F_89 ( struct V_84 * V_84 , void * V_85 , struct V_266 * V_267 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_267 -> V_268 != 0 )
return - V_64 ;
F_58 ( V_23 , V_268 , V_269 , V_267 ) ;
return 0 ;
}
int F_90 ( struct V_84 * V_84 , void * V_85 , struct V_266 * V_267 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_267 -> V_268 != 0 )
return - V_64 ;
F_83 ( V_23 ) ;
F_19 ( L_9 , V_267 -> V_270 ) ;
F_58 ( V_23 , V_268 , V_271 , V_267 ) ;
F_85 ( V_23 ) ;
return 0 ;
}
static int F_91 ( struct V_84 * V_84 , void * V_85 , T_6 * V_272 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
* V_272 = V_23 -> V_272 ;
return 0 ;
}
void F_92 ( struct V_22 * V_23 , T_6 * V_272 )
{
V_23 -> V_272 = * V_272 ;
V_23 -> V_93 = ( * V_272 & V_273 ) ? 1 : 0 ;
V_23 -> V_120 = ! V_23 -> V_93 ;
F_93 ( & V_23 -> V_41 , V_23 -> V_120 ) ;
V_23 -> V_41 . V_97 = 720 ;
V_23 -> V_41 . V_98 = V_23 -> V_120 ? 576 : 480 ;
V_23 -> V_110 . V_118 = V_23 -> V_120 ? 18 : 12 ;
V_23 -> V_110 . V_117 [ 0 ] = V_23 -> V_120 ? 6 : 10 ;
V_23 -> V_110 . V_117 [ 1 ] = V_23 -> V_120 ? 318 : 273 ;
if ( V_23 -> V_274 & V_275 )
V_23 -> V_110 . V_276 = V_23 -> V_93 ? 272 : 284 ;
F_58 ( V_23 , V_188 , V_277 , V_23 -> V_272 ) ;
}
void F_94 ( struct V_22 * V_23 , T_6 * V_272 )
{
struct V_167 * V_168 = & V_23 -> V_125 ;
F_10 ( V_37 ) ;
int V_19 ;
V_23 -> V_278 = * V_272 ;
V_23 -> V_279 = ( * V_272 & V_273 ) ? 1 : 0 ;
V_23 -> V_243 = ! V_23 -> V_279 ;
F_58 ( V_23 , V_159 , V_280 , V_23 -> V_278 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_13 ( & V_23 -> V_281 , & V_37 ,
V_282 ) ;
if ( ( F_95 ( V_283 ) >> 16 ) < 100 )
break;
F_96 ( F_97 ( 25 ) ) ;
}
F_17 ( & V_23 -> V_281 , & V_37 ) ;
if ( V_19 == 4 )
F_98 ( L_10 ) ;
F_8 ( V_23 , V_284 , 1 , V_23 -> V_243 ) ;
V_23 -> V_123 . V_147 = 0 ;
V_23 -> V_123 . V_146 = 0 ;
V_23 -> V_123 . V_97 = 720 ;
V_23 -> V_123 . V_98 = V_23 -> V_243 ? 576 : 480 ;
F_8 ( V_23 , V_248 , 4 ,
720 , V_23 -> V_123 . V_98 , 0 , 0 ) ;
V_168 -> V_123 = V_23 -> V_123 ;
if ( ! V_23 -> V_285 ) {
V_168 -> V_241 = 720 ;
V_168 -> V_242 = V_23 -> V_243 ? 576 : 480 ;
}
}
int F_99 ( struct V_84 * V_84 , void * V_85 , T_6 * V_272 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( ( * V_272 & V_286 ) == 0 )
return - V_64 ;
if ( * V_272 == V_23 -> V_272 )
return 0 ;
if ( F_14 ( V_287 , & V_23 -> V_50 ) ||
F_12 ( & V_23 -> V_154 ) > 0 ||
F_12 ( & V_23 -> V_44 ) > 0 ) {
return - V_72 ;
}
F_19 ( L_11 ,
( unsigned long long ) V_23 -> V_272 ) ;
F_92 ( V_23 , V_272 ) ;
if ( V_23 -> V_62 & V_63 )
F_94 ( V_23 , V_272 ) ;
return 0 ;
}
static int F_100 ( struct V_84 * V_84 , void * V_85 , struct V_288 * V_289 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
if ( V_289 -> V_224 != 0 )
return - V_64 ;
F_58 ( V_23 , V_268 , V_290 , V_289 ) ;
return 0 ;
}
static int F_101 ( struct V_84 * V_84 , void * V_85 , struct V_288 * V_289 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_289 -> V_224 != 0 )
return - V_64 ;
F_58 ( V_23 , V_268 , V_291 , V_289 ) ;
if ( V_289 -> type == V_292 )
F_61 ( V_289 -> V_293 , L_12 , sizeof( V_289 -> V_293 ) ) ;
else
F_61 ( V_289 -> V_293 , L_13 , sizeof( V_289 -> V_293 ) ) ;
return 0 ;
}
static int F_102 ( struct V_84 * V_84 , void * V_85 , struct V_294 * V_295 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
int V_11 = V_23 -> V_120 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_295 -> type == V_165 ) {
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_23 -> V_120 ) )
V_295 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
}
}
return 0 ;
}
if ( V_295 -> type == V_296 ) {
if ( ! ( V_23 -> V_62 & V_90 ) )
return - V_64 ;
if ( V_23 -> V_93 ) {
V_295 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_295 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_295 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_295 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
return 0 ;
}
return - V_64 ;
}
static int F_103 ( struct V_84 * V_84 , void * V_85 , struct V_297 * V_298 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
struct V_299 * V_300 = V_298 -> V_301 ;
int V_302 ;
int V_15 ;
V_302 = ( V_23 -> V_303 + V_304 - V_23 -> V_305 ) %
V_304 ;
if ( V_302 > V_306 )
V_302 = V_306 ;
V_298 -> V_302 = 0 ;
for ( V_15 = 0 ; V_15 < V_302 ; V_15 ++ ) {
* V_300 = V_23 -> V_307 [ ( V_23 -> V_305 + V_15 ) % V_304 ] ;
if ( ( V_300 -> V_67 & V_308 ) <= V_309 ) {
V_298 -> V_302 ++ ;
V_300 ++ ;
}
}
V_23 -> V_305 = ( V_23 -> V_305 + V_298 -> V_302 ) % V_304 ;
return 0 ;
}
static int F_104 ( struct V_84 * V_84 , void * V_85 , struct V_310 * V_311 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
switch ( V_311 -> V_65 ) {
case V_312 :
F_105 ( L_14 ) ;
V_311 -> V_67 = 0 ;
return F_106 ( V_58 ) ;
case V_313 :
F_105 ( L_15 ) ;
V_311 -> V_67 &= V_314 ;
F_107 ( V_58 , V_311 -> V_67 & V_314 ) ;
return 0 ;
case V_315 :
F_105 ( L_16 ) ;
V_311 -> V_67 = 0 ;
if ( ! F_12 ( & V_23 -> V_154 ) )
return - V_195 ;
if ( F_108 ( V_316 , & V_23 -> V_50 ) )
return 0 ;
F_83 ( V_23 ) ;
F_8 ( V_23 , V_317 , 1 , 0 ) ;
break;
case V_318 :
F_105 ( L_17 ) ;
V_311 -> V_67 = 0 ;
if ( ! F_12 ( & V_23 -> V_154 ) )
return - V_195 ;
if ( ! F_23 ( V_316 , & V_23 -> V_50 ) )
return 0 ;
F_8 ( V_23 , V_317 , 1 , 1 ) ;
F_85 ( V_23 ) ;
break;
default:
F_105 ( L_18 , V_311 -> V_65 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_109 ( struct V_84 * V_84 , void * V_85 , struct V_310 * V_311 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
switch ( V_311 -> V_65 ) {
case V_312 :
F_105 ( L_14 ) ;
V_311 -> V_67 = 0 ;
return 0 ;
case V_313 :
F_105 ( L_15 ) ;
V_311 -> V_67 &= V_314 ;
return 0 ;
case V_315 :
F_105 ( L_16 ) ;
V_311 -> V_67 = 0 ;
return 0 ;
case V_318 :
F_105 ( L_17 ) ;
V_311 -> V_67 = 0 ;
return 0 ;
default:
F_105 ( L_18 , V_311 -> V_65 ) ;
return - V_64 ;
}
}
static int F_110 ( struct V_84 * V_84 , void * V_85 , struct V_319 * V_320 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_95 ;
static T_2 V_321 [ 16 ] = {
V_322 ,
V_323 ,
V_324 ,
V_325 ,
V_326 ,
0 ,
0 ,
0 ,
V_322 ,
V_327 ,
V_328 ,
V_329 ,
V_330 ,
0 ,
0 ,
0 ,
} ;
if ( ! ( V_23 -> V_62 & V_331 ) )
return - V_64 ;
if ( ! V_23 -> V_332 )
return - V_64 ;
V_320 -> V_333 = V_334 | V_335 |
V_336 ;
F_111 ( V_23 , V_32 , V_337 , 0 ) ;
V_32 [ 0 ] |= ( F_95 ( 0x2a00 ) >> 7 ) & 0x40 ;
V_95 = ( V_32 [ 0 ] >> 3 ) & 0xf ;
V_320 -> V_17 . V_104 = V_321 [ V_95 ] ;
V_320 -> V_17 . V_97 = V_23 -> V_148 . V_97 ;
V_320 -> V_17 . V_98 = V_23 -> V_148 . V_98 ;
V_320 -> V_17 . V_9 = V_101 ;
V_320 -> V_17 . V_107 = V_320 -> V_17 . V_97 ;
V_320 -> V_17 . V_99 = V_100 ;
V_320 -> V_17 . V_9 = V_101 ;
V_320 -> V_17 . V_102 = 0 ;
if ( V_320 -> V_17 . V_104 != V_322 )
V_320 -> V_17 . V_107 *= 2 ;
if ( V_320 -> V_17 . V_104 == V_326 ||
V_320 -> V_17 . V_104 == V_330 )
V_320 -> V_17 . V_107 *= 2 ;
V_320 -> V_17 . V_106 = V_320 -> V_17 . V_107 * V_320 -> V_17 . V_98 ;
V_320 -> V_338 = ( void * ) V_23 -> V_332 ;
V_320 -> V_67 = 0 ;
if ( V_23 -> V_29 )
V_320 -> V_67 |= V_339 ;
if ( V_23 -> V_25 )
V_320 -> V_67 |= V_340 ;
if ( V_168 -> V_240 )
V_320 -> V_67 |= V_341 ;
V_95 &= 7 ;
if ( V_95 == 1 || V_95 > 4 )
return 0 ;
if ( V_95 == 2 || V_95 == 3 )
V_320 -> V_333 |= V_342 ;
else
V_320 -> V_333 |= V_343 ;
if ( V_23 -> V_27 ) {
if ( V_95 == 2 || V_95 == 3 )
V_320 -> V_67 |= V_344 ;
else
V_320 -> V_67 |= V_345 ;
}
return 0 ;
}
static int F_112 ( struct V_84 * V_84 , void * V_85 , struct V_319 * V_320 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
if ( ! ( V_23 -> V_62 & V_331 ) )
return - V_64 ;
if ( ! V_23 -> V_332 )
return - V_64 ;
V_23 -> V_25 = ( V_320 -> V_67 & V_340 ) != 0 ;
V_23 -> V_27 =
( V_320 -> V_67 & ( V_345 | V_344 ) ) != 0 ;
V_23 -> V_29 = ( V_320 -> V_67 & V_339 ) != 0 ;
F_7 ( V_23 ) ;
V_168 -> V_240 = ( V_320 -> V_67 & V_341 ) != 0 ;
return F_110 ( V_84 , V_85 , V_320 ) ;
}
static int F_113 ( struct V_84 * V_84 , void * V_85 , unsigned int V_346 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
if ( ! ( V_23 -> V_62 & V_331 ) )
return - V_64 ;
F_8 ( V_23 , V_347 , 1 , V_346 != 0 ) ;
return 0 ;
}
static int F_114 ( struct V_348 * V_85 , struct V_349 * V_350 )
{
switch ( V_350 -> type ) {
case V_351 :
case V_352 :
break;
default:
return - V_64 ;
}
return F_115 ( V_85 , V_350 ) ;
}
static int F_116 ( struct V_84 * V_84 , void * V_85 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
int V_353 = V_23 -> V_62 & V_63 ;
struct V_229 V_354 ;
struct V_222 V_355 ;
int V_15 ;
F_117 ( L_19 ,
V_23 -> V_356 ) ;
F_117 ( L_20 , V_357 , V_23 -> V_216 ) ;
if ( V_23 -> V_274 & V_358 ) {
struct V_359 V_360 ;
F_118 ( V_23 , & V_360 ) ;
}
F_58 ( V_23 , V_188 , V_361 ) ;
F_73 ( V_23 , V_23 -> V_253 , & V_354 ) ;
F_64 ( V_23 , V_23 -> V_225 , & V_355 ) ;
F_117 ( L_21 , V_354 . V_293 ) ;
F_117 ( L_22 , V_355 . V_293 ,
( V_23 -> V_362 & ~ 0x300 ) == 0x200 ? L_23 : L_24 ) ;
if ( V_353 ) {
struct V_230 V_363 ;
struct V_228 V_364 ;
int V_365 = V_23 -> V_79 ;
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
static const char * const V_321 [ 16 ] = {
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
F_75 ( V_23 , V_23 -> V_258 , & V_363 ) ;
F_69 ( V_23 , 0 , & V_364 ) ;
F_117 ( L_54 , V_363 . V_293 ) ;
F_117 ( L_55 , V_364 . V_293 ,
V_367 [ V_23 -> V_369 ] ,
V_367 [ V_23 -> V_370 ] ) ;
if ( V_365 < 0 || V_365 > V_371 )
V_365 = V_80 ;
F_117 ( L_56 , V_366 [ V_365 ] ) ;
F_111 ( V_23 , V_32 , V_337 , 0 ) ;
V_32 [ 0 ] |= ( F_95 ( 0x2a00 ) >> 7 ) & 0x40 ;
F_117 ( L_57 ,
V_32 [ 0 ] & 1 ? L_58 : L_59 ,
V_368 [ ( V_32 [ 0 ] >> 1 ) & 0x3 ] ,
V_321 [ ( V_32 [ 0 ] >> 3 ) & 0xf ] ) ;
}
F_117 ( L_60 ,
F_14 ( V_287 , & V_23 -> V_50 ) ? L_61 : L_62 ) ;
F_119 ( & V_23 -> V_41 . V_372 , V_23 -> V_373 . V_293 ) ;
F_117 ( L_63 , V_23 -> V_50 ) ;
for ( V_15 = 0 ; V_15 < V_374 ; V_15 ++ ) {
struct V_34 * V_35 = & V_23 -> V_38 [ V_15 ] ;
if ( V_35 -> V_375 == NULL || V_35 -> V_376 == 0 )
continue;
F_117 ( L_64 , V_35 -> V_293 , V_35 -> V_377 ,
( V_35 -> V_376 - V_35 -> V_378 . V_376 ) * 100 / V_35 -> V_376 ,
( V_35 -> V_376 * V_35 -> V_379 ) / 1024 , V_35 -> V_376 ) ;
}
F_117 ( L_65 ,
( long long ) V_23 -> V_380 ,
( long long ) V_23 -> V_381 ) ;
F_117 ( L_66 ,
V_23 -> V_356 ) ;
return 0 ;
}
static int F_120 ( struct V_84 * V_382 , unsigned int V_65 , void * V_190 )
{
struct V_57 * V_58 = F_28 ( V_382 -> V_383 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
int V_384 = V_382 -> V_385 & V_386 ;
struct V_34 * V_35 = & V_23 -> V_38 [ V_58 -> type ] ;
unsigned long V_387 = ( unsigned long ) V_190 ;
switch ( V_65 ) {
case V_388 : {
struct V_389 * args = V_190 ;
F_105 ( L_67 ) ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( args -> type != V_234 )
return - V_64 ;
if ( V_23 -> V_79 == V_390 && args -> V_391 == NULL )
return 0 ;
if ( F_24 ( V_58 , V_58 -> type ) ) {
return - V_72 ;
}
if ( F_22 ( V_23 , V_390 ) != V_390 ) {
F_121 ( V_35 ) ;
return - V_72 ;
}
V_58 -> V_392 = 1 ;
if ( args -> V_391 == NULL )
return 0 ;
return F_122 ( V_23 , args ) ;
}
case V_393 : {
T_2 V_32 [ V_33 ] ;
T_7 * V_78 = V_190 ;
F_105 ( L_68 ) ;
if ( V_35 -> type < V_39 ) {
* V_78 = V_35 -> V_394 ;
break;
}
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( F_14 ( V_395 , & V_23 -> V_50 ) ) {
* V_78 = ( T_7 ) ( ( T_7 ) V_23 -> V_396 [ 2 ] << 32 ) |
( T_7 ) V_23 -> V_396 [ 1 ] ;
break;
}
* V_78 = 0 ;
if ( F_12 ( & V_23 -> V_44 ) ) {
if ( F_18 ( V_23 , V_397 , 5 , V_32 ) ) {
F_123 ( L_69 ) ;
return - V_398 ;
}
memcpy ( V_23 -> V_396 , V_32 , sizeof( V_23 -> V_396 ) ) ;
F_26 ( V_395 , & V_23 -> V_50 ) ;
* V_78 = ( T_7 ) ( ( T_7 ) V_32 [ 2 ] << 32 ) | ( T_7 ) V_32 [ 1 ] ;
}
break;
}
case V_399 : {
T_2 V_32 [ V_33 ] ;
T_7 * V_400 = V_190 ;
F_105 ( L_70 ) ;
if ( V_35 -> type < V_39 ) {
* V_400 = 0 ;
break;
}
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( F_14 ( V_395 , & V_23 -> V_50 ) ) {
* V_400 = V_23 -> V_396 [ 0 ] ;
break;
}
* V_400 = 0 ;
if ( F_12 ( & V_23 -> V_44 ) ) {
if ( F_18 ( V_23 , V_397 , 5 , V_32 ) ) {
F_123 ( L_69 ) ;
return - V_398 ;
}
memcpy ( V_23 -> V_396 , V_32 , sizeof( V_23 -> V_396 ) ) ;
F_26 ( V_395 , & V_23 -> V_50 ) ;
* V_400 = V_32 [ 0 ] ;
}
break;
}
case V_401 : {
struct V_59 V_60 ;
F_105 ( L_71 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_66 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_402 : {
struct V_59 V_60 ;
F_105 ( L_72 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_74 ;
V_60 . V_67 = V_76 | V_75 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_403 : {
struct V_59 V_60 ;
F_105 ( L_73 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_81 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_404 : {
struct V_59 V_60 ;
F_105 ( L_74 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_83 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_405 :
case V_406 : {
struct V_59 * V_60 = V_190 ;
int V_61 = ( V_65 == V_406 ) ;
if ( V_61 )
F_105 ( L_75 , V_60 -> V_65 ) ;
else
F_105 ( L_76 , V_60 -> V_65 ) ;
return F_21 ( V_23 , V_58 , V_60 , V_61 ) ;
}
case V_407 : {
struct V_408 * V_409 = V_190 ;
F_10 ( V_37 ) ;
F_105 ( L_77 ) ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
memset ( V_409 , 0 , sizeof( * V_409 ) ) ;
F_26 ( V_410 , & V_23 -> V_50 ) ;
while ( 1 ) {
if ( F_23 ( V_411 , & V_23 -> V_50 ) )
V_409 -> type = V_412 ;
else if ( F_23 ( V_413 , & V_23 -> V_50 ) ) {
V_409 -> type = V_414 ;
V_409 -> V_415 . V_416 = F_14 ( V_417 , & V_23 -> V_50 ) ?
V_418 : V_419 ;
if ( V_23 -> V_79 == V_390 &&
( V_23 -> V_125 . V_126 & V_127 ) ==
V_132 ) {
V_409 -> V_415 . V_416 = V_420 ;
}
}
if ( V_409 -> type )
return 0 ;
if ( V_384 )
return - V_421 ;
F_124 ( & V_23 -> V_422 ) ;
F_13 ( & V_23 -> V_423 , & V_37 , V_48 ) ;
if ( ! F_14 ( V_411 , & V_23 -> V_50 ) &&
! F_14 ( V_413 , & V_23 -> V_50 ) )
F_16 () ;
F_17 ( & V_23 -> V_423 , & V_37 ) ;
F_125 ( & V_23 -> V_422 ) ;
if ( F_15 ( V_51 ) ) {
F_19 ( L_78 ) ;
return - V_52 ;
}
}
break;
}
case V_424 :
F_105 ( L_79 ) ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
return F_126 ( V_23 , V_387 == V_425 ) ;
case V_426 :
F_105 ( L_80 ) ;
V_23 -> V_43 = V_387 ;
return 0 ;
case V_427 :
F_105 ( L_81 ) ;
if ( V_387 > V_428 )
return - V_64 ;
V_23 -> V_369 = V_387 ;
F_8 ( V_23 , V_429 , 2 , V_23 -> V_370 , V_23 -> V_369 ) ;
return 0 ;
case V_430 :
F_105 ( L_82 ) ;
if ( V_387 > V_428 )
return - V_64 ;
V_23 -> V_370 = V_387 ;
F_8 ( V_23 , V_429 , 2 , V_23 -> V_370 , V_23 -> V_369 ) ;
return 0 ;
default:
return - V_64 ;
}
return 0 ;
}
static long F_127 ( struct V_84 * V_84 , void * V_85 , bool V_431 ,
int V_65 , void * V_190 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( ! V_431 ) {
switch ( V_65 ) {
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_424 :
case V_426 :
case V_427 :
case V_430 :
return - V_72 ;
}
}
switch ( V_65 ) {
case V_432 : {
T_2 V_207 = * ( T_2 * ) V_190 ;
if ( ( V_207 == 0 && V_23 -> V_433 . V_434 ) || ( V_207 & 0x01 ) )
F_128 ( V_23 ) ;
if ( V_207 & 0x02 )
F_32 ( V_23 -> V_121 , V_188 , V_435 , 0 ) ;
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
case V_424 :
case V_426 :
case V_427 :
case V_430 :
return F_120 ( V_84 , V_65 , ( void * ) V_190 ) ;
default:
return - V_64 ;
}
return 0 ;
}
static long F_129 ( struct V_22 * V_23 , struct V_84 * V_382 ,
unsigned int V_65 , unsigned long V_190 )
{
struct V_436 * V_437 = F_130 ( V_382 ) ;
long V_151 ;
if ( V_438 & V_439 )
V_437 -> V_440 = V_441 | V_442 ;
V_151 = F_131 ( V_382 , V_65 , V_190 ) ;
V_437 -> V_440 = 0 ;
return V_151 ;
}
long F_132 ( struct V_84 * V_382 , unsigned int V_65 , unsigned long V_190 )
{
struct V_57 * V_58 = F_28 ( V_382 -> V_383 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
long V_443 ;
if ( V_65 == V_444 )
return F_129 ( V_23 , V_382 , V_65 , V_190 ) ;
F_125 ( & V_23 -> V_422 ) ;
V_443 = F_129 ( V_23 , V_382 , V_65 , V_190 ) ;
F_124 ( & V_23 -> V_422 ) ;
return V_443 ;
}
void F_133 ( struct V_436 * V_375 )
{
V_375 -> V_445 = & V_446 ;
}
