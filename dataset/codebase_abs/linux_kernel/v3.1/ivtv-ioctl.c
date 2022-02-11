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
V_212 -> V_219 = V_23 -> V_62 ;
return 0 ;
}
static int F_63 ( struct V_84 * V_84 , void * V_85 , struct V_220 * V_221 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_64 ( V_23 , V_221 -> V_222 , V_221 ) ;
}
static int F_65 ( struct V_84 * V_84 , void * V_85 , struct V_220 * V_221 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
V_221 -> V_222 = V_23 -> V_223 ;
return F_64 ( V_23 , V_221 -> V_222 , V_221 ) ;
}
static int F_66 ( struct V_84 * V_84 , void * V_85 , struct V_220 * V_224 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_224 -> V_222 >= V_23 -> V_225 )
return - V_64 ;
V_23 -> V_223 = V_224 -> V_222 ;
F_67 ( V_23 ) ;
return 0 ;
}
static int F_68 ( struct V_84 * V_84 , void * V_85 , struct V_226 * V_221 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_69 ( V_23 , V_221 -> V_222 , V_221 ) ;
}
static int F_70 ( struct V_84 * V_84 , void * V_85 , struct V_226 * V_221 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
V_221 -> V_222 = 0 ;
return F_69 ( V_23 , V_221 -> V_222 , V_221 ) ;
}
static int F_71 ( struct V_84 * V_84 , void * V_85 , struct V_226 * V_224 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_69 ( V_23 , V_224 -> V_222 , V_224 ) ;
}
static int F_72 ( struct V_84 * V_84 , void * V_85 , struct V_227 * V_221 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_73 ( V_23 , V_221 -> V_222 , V_221 ) ;
}
static int F_74 ( struct V_84 * V_84 , void * V_85 , struct V_228 * V_224 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
return F_75 ( V_23 , V_224 -> V_222 , V_224 ) ;
}
static int F_76 ( struct V_84 * V_84 , void * V_85 , struct V_229 * V_230 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_231 ;
V_231 = V_58 -> type ;
if ( V_230 -> type != V_232 )
return - V_64 ;
V_230 -> V_233 . V_146 = V_230 -> V_233 . V_147 = 0 ;
V_230 -> V_233 . V_97 = 720 ;
if ( V_230 -> type == V_234 ) {
V_230 -> V_233 . V_98 = V_23 -> V_120 ? 576 : 480 ;
V_230 -> V_235 . V_236 = V_23 -> V_120 ? 59 : 10 ;
V_230 -> V_235 . V_237 = V_23 -> V_120 ? 54 : 11 ;
} else if ( V_231 == V_124 ) {
if ( V_168 -> V_238 ) {
V_230 -> V_233 . V_97 = V_168 -> V_239 ;
V_230 -> V_233 . V_98 = V_168 -> V_240 ;
} else {
V_230 -> V_233 . V_97 = 720 ;
V_230 -> V_233 . V_98 =
V_23 -> V_241 ? 576 : 480 ;
}
V_230 -> V_235 . V_236 = V_23 -> V_241 ? 59 : 10 ;
V_230 -> V_235 . V_237 = V_23 -> V_241 ? 54 : 11 ;
} else {
V_230 -> V_233 . V_98 = V_23 -> V_241 ? 576 : 480 ;
V_230 -> V_235 . V_236 = V_23 -> V_241 ? 59 : 10 ;
V_230 -> V_235 . V_237 = V_23 -> V_241 ? 54 : 11 ;
}
V_230 -> V_242 = V_230 -> V_233 ;
return 0 ;
}
static int F_77 ( struct V_84 * V_84 , void * V_85 , struct V_243 * V_244 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_231 ;
V_231 = V_58 -> type ;
if ( V_244 -> type == V_232 &&
( V_23 -> V_62 & V_63 ) ) {
if ( V_231 == V_124 ) {
V_168 -> V_123 = V_244 -> V_245 ;
return 0 ;
} else {
if ( ! F_8 ( V_23 , V_246 , 4 ,
V_244 -> V_245 . V_97 , V_244 -> V_245 . V_98 , V_244 -> V_245 . V_147 , V_244 -> V_245 . V_146 ) ) {
V_23 -> V_123 = V_244 -> V_245 ;
return 0 ;
}
}
return - V_64 ;
}
return - V_64 ;
}
static int F_78 ( struct V_84 * V_84 , void * V_85 , struct V_243 * V_244 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_231 ;
V_231 = V_58 -> type ;
if ( V_244 -> type == V_232 &&
( V_23 -> V_62 & V_63 ) ) {
if ( V_231 == V_124 )
V_244 -> V_245 = V_168 -> V_123 ;
else
V_244 -> V_245 = V_23 -> V_123 ;
return 0 ;
}
return - V_64 ;
}
static int F_79 ( struct V_84 * V_84 , void * V_85 , struct V_247 * V_17 )
{
static struct V_247 V_248 [] = {
{ 0 , 0 , 0 ,
L_3 , V_105 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_249 ,
L_4 , V_108 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_250 type = V_17 -> type ;
if ( V_17 -> V_222 > 1 )
return - V_64 ;
* V_17 = V_248 [ V_17 -> V_222 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_80 ( struct V_84 * V_84 , void * V_85 , struct V_247 * V_17 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
static struct V_247 V_248 [] = {
{ 0 , 0 , 0 ,
L_3 , V_105 ,
{ 0 , 0 , 0 , 0 }
} ,
{ 1 , 0 , V_249 ,
L_4 , V_108 ,
{ 0 , 0 , 0 , 0 }
}
} ;
enum V_250 type = V_17 -> type ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( V_17 -> V_222 > 1 )
return - V_64 ;
* V_17 = V_248 [ V_17 -> V_222 ] ;
V_17 -> type = type ;
return 0 ;
}
static int F_81 ( struct V_84 * V_84 , void * V_85 , unsigned int * V_15 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
* V_15 = V_23 -> V_251 ;
return 0 ;
}
int F_82 ( struct V_84 * V_84 , void * V_85 , unsigned int V_252 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_252 < 0 || V_252 >= V_23 -> V_253 )
return - V_64 ;
if ( V_252 == V_23 -> V_251 ) {
F_19 ( L_5 ) ;
return 0 ;
}
if ( F_12 ( & V_23 -> V_154 ) > 0 ) {
return - V_72 ;
}
F_19 ( L_6 ,
V_23 -> V_251 , V_252 ) ;
V_23 -> V_251 = V_252 ;
V_23 -> V_223 = V_23 -> V_215 -> V_254 [ V_252 ] . V_255 ;
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
* V_15 = V_23 -> V_256 ;
return 0 ;
}
static int F_87 ( struct V_84 * V_84 , void * V_85 , unsigned int V_257 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_257 >= V_23 -> V_215 -> V_258 )
return - V_64 ;
if ( V_257 == V_23 -> V_256 ) {
F_19 ( L_7 ) ;
return 0 ;
}
F_19 ( L_8 ,
V_23 -> V_256 , V_257 ) ;
V_23 -> V_256 = V_257 ;
F_88 ( V_23 , V_259 , V_159 , V_260 ,
V_261 ,
V_23 -> V_215 -> V_262 [ V_257 ] . V_263 , 0 ) ;
return 0 ;
}
static int F_89 ( struct V_84 * V_84 , void * V_85 , struct V_264 * V_265 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_265 -> V_266 != 0 )
return - V_64 ;
F_58 ( V_23 , V_266 , V_267 , V_265 ) ;
return 0 ;
}
int F_90 ( struct V_84 * V_84 , void * V_85 , struct V_264 * V_265 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_265 -> V_266 != 0 )
return - V_64 ;
F_83 ( V_23 ) ;
F_19 ( L_9 , V_265 -> V_268 ) ;
F_58 ( V_23 , V_266 , V_269 , V_265 ) ;
F_85 ( V_23 ) ;
return 0 ;
}
static int F_91 ( struct V_84 * V_84 , void * V_85 , T_6 * V_270 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
* V_270 = V_23 -> V_270 ;
return 0 ;
}
void F_92 ( struct V_22 * V_23 , T_6 * V_270 )
{
V_23 -> V_270 = * V_270 ;
V_23 -> V_93 = ( * V_270 & V_271 ) ? 1 : 0 ;
V_23 -> V_120 = ! V_23 -> V_93 ;
F_93 ( & V_23 -> V_41 , V_23 -> V_120 ) ;
V_23 -> V_41 . V_97 = 720 ;
V_23 -> V_41 . V_98 = V_23 -> V_120 ? 576 : 480 ;
V_23 -> V_110 . V_118 = V_23 -> V_120 ? 18 : 12 ;
V_23 -> V_110 . V_117 [ 0 ] = V_23 -> V_120 ? 6 : 10 ;
V_23 -> V_110 . V_117 [ 1 ] = V_23 -> V_120 ? 318 : 273 ;
if ( V_23 -> V_272 & V_273 )
V_23 -> V_110 . V_274 = V_23 -> V_93 ? 272 : 284 ;
F_58 ( V_23 , V_188 , V_275 , V_23 -> V_270 ) ;
}
void F_94 ( struct V_22 * V_23 , T_6 * V_270 )
{
struct V_167 * V_168 = & V_23 -> V_125 ;
F_10 ( V_37 ) ;
int V_19 ;
V_23 -> V_276 = * V_270 ;
V_23 -> V_277 = ( * V_270 & V_271 ) ? 1 : 0 ;
V_23 -> V_241 = ! V_23 -> V_277 ;
F_58 ( V_23 , V_159 , V_278 , V_23 -> V_276 ) ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
F_13 ( & V_23 -> V_279 , & V_37 ,
V_280 ) ;
if ( ( F_95 ( V_281 ) >> 16 ) < 100 )
break;
F_96 ( F_97 ( 25 ) ) ;
}
F_17 ( & V_23 -> V_279 , & V_37 ) ;
if ( V_19 == 4 )
F_98 ( L_10 ) ;
F_8 ( V_23 , V_282 , 1 , V_23 -> V_241 ) ;
V_23 -> V_123 . V_147 = 0 ;
V_23 -> V_123 . V_146 = 0 ;
V_23 -> V_123 . V_97 = 720 ;
V_23 -> V_123 . V_98 = V_23 -> V_241 ? 576 : 480 ;
F_8 ( V_23 , V_246 , 4 ,
720 , V_23 -> V_123 . V_98 , 0 , 0 ) ;
V_168 -> V_123 = V_23 -> V_123 ;
if ( ! V_23 -> V_283 ) {
V_168 -> V_239 = 720 ;
V_168 -> V_240 = V_23 -> V_241 ? 576 : 480 ;
}
}
int F_99 ( struct V_84 * V_84 , void * V_85 , T_6 * V_270 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( ( * V_270 & V_284 ) == 0 )
return - V_64 ;
if ( * V_270 == V_23 -> V_270 )
return 0 ;
if ( F_14 ( V_285 , & V_23 -> V_50 ) ||
F_12 ( & V_23 -> V_154 ) > 0 ||
F_12 ( & V_23 -> V_44 ) > 0 ) {
return - V_72 ;
}
F_19 ( L_11 ,
( unsigned long long ) V_23 -> V_270 ) ;
F_92 ( V_23 , V_270 ) ;
if ( V_23 -> V_62 & V_63 )
F_94 ( V_23 , V_270 ) ;
return 0 ;
}
static int F_100 ( struct V_84 * V_84 , void * V_85 , struct V_286 * V_287 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
if ( V_287 -> V_222 != 0 )
return - V_64 ;
F_58 ( V_23 , V_266 , V_288 , V_287 ) ;
return 0 ;
}
static int F_101 ( struct V_84 * V_84 , void * V_85 , struct V_286 * V_287 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( V_287 -> V_222 != 0 )
return - V_64 ;
F_58 ( V_23 , V_266 , V_289 , V_287 ) ;
if ( V_287 -> type == V_290 )
F_61 ( V_287 -> V_291 , L_12 , sizeof( V_287 -> V_291 ) ) ;
else
F_61 ( V_287 -> V_291 , L_13 , sizeof( V_287 -> V_291 ) ) ;
return 0 ;
}
static int F_102 ( struct V_84 * V_84 , void * V_85 , struct V_292 * V_293 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
int V_11 = V_23 -> V_120 ? V_13 : V_14 ;
int V_19 , V_20 ;
if ( V_293 -> type == V_165 ) {
for ( V_19 = 0 ; V_19 < 2 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < 24 ; V_20 ++ ) {
if ( F_2 ( V_19 , V_20 , V_23 -> V_120 ) )
V_293 -> V_21 [ V_19 ] [ V_20 ] = V_11 ;
}
}
return 0 ;
}
if ( V_293 -> type == V_294 ) {
if ( ! ( V_23 -> V_62 & V_90 ) )
return - V_64 ;
if ( V_23 -> V_93 ) {
V_293 -> V_21 [ 0 ] [ 21 ] = V_3 ;
V_293 -> V_21 [ 1 ] [ 21 ] = V_3 ;
} else {
V_293 -> V_21 [ 0 ] [ 23 ] = V_5 ;
V_293 -> V_21 [ 0 ] [ 16 ] = V_7 ;
}
return 0 ;
}
return - V_64 ;
}
static int F_103 ( struct V_84 * V_84 , void * V_85 , struct V_295 * V_296 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
struct V_297 * V_298 = V_296 -> V_299 ;
int V_300 ;
int V_15 ;
V_300 = ( V_23 -> V_301 + V_302 - V_23 -> V_303 ) %
V_302 ;
if ( V_300 > V_304 )
V_300 = V_304 ;
V_296 -> V_300 = 0 ;
for ( V_15 = 0 ; V_15 < V_300 ; V_15 ++ ) {
* V_298 = V_23 -> V_305 [ ( V_23 -> V_303 + V_15 ) % V_302 ] ;
if ( ( V_298 -> V_67 & V_306 ) <= V_307 ) {
V_296 -> V_300 ++ ;
V_298 ++ ;
}
}
V_23 -> V_303 = ( V_23 -> V_303 + V_296 -> V_300 ) % V_302 ;
return 0 ;
}
static int F_104 ( struct V_84 * V_84 , void * V_85 , struct V_308 * V_309 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
switch ( V_309 -> V_65 ) {
case V_310 :
F_105 ( L_14 ) ;
V_309 -> V_67 = 0 ;
return F_106 ( V_58 ) ;
case V_311 :
F_105 ( L_15 ) ;
V_309 -> V_67 &= V_312 ;
F_107 ( V_58 , V_309 -> V_67 & V_312 ) ;
return 0 ;
case V_313 :
F_105 ( L_16 ) ;
V_309 -> V_67 = 0 ;
if ( ! F_12 ( & V_23 -> V_154 ) )
return - V_195 ;
if ( F_108 ( V_314 , & V_23 -> V_50 ) )
return 0 ;
F_83 ( V_23 ) ;
F_8 ( V_23 , V_315 , 1 , 0 ) ;
break;
case V_316 :
F_105 ( L_17 ) ;
V_309 -> V_67 = 0 ;
if ( ! F_12 ( & V_23 -> V_154 ) )
return - V_195 ;
if ( ! F_23 ( V_314 , & V_23 -> V_50 ) )
return 0 ;
F_8 ( V_23 , V_315 , 1 , 1 ) ;
F_85 ( V_23 ) ;
break;
default:
F_105 ( L_18 , V_309 -> V_65 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_109 ( struct V_84 * V_84 , void * V_85 , struct V_308 * V_309 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
switch ( V_309 -> V_65 ) {
case V_310 :
F_105 ( L_14 ) ;
V_309 -> V_67 = 0 ;
return 0 ;
case V_311 :
F_105 ( L_15 ) ;
V_309 -> V_67 &= V_312 ;
return 0 ;
case V_313 :
F_105 ( L_16 ) ;
V_309 -> V_67 = 0 ;
return 0 ;
case V_316 :
F_105 ( L_17 ) ;
V_309 -> V_67 = 0 ;
return 0 ;
default:
F_105 ( L_18 , V_309 -> V_65 ) ;
return - V_64 ;
}
}
static int F_110 ( struct V_84 * V_84 , void * V_85 , struct V_317 * V_318 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
struct V_167 * V_168 = & V_23 -> V_125 ;
int V_95 ;
static T_2 V_319 [ 16 ] = {
V_320 ,
V_321 ,
V_322 ,
V_323 ,
V_324 ,
0 ,
0 ,
0 ,
V_320 ,
V_325 ,
V_326 ,
V_327 ,
V_328 ,
0 ,
0 ,
0 ,
} ;
if ( ! ( V_23 -> V_62 & V_329 ) )
return - V_64 ;
if ( ! V_23 -> V_330 )
return - V_64 ;
V_318 -> V_331 = V_332 | V_333 |
V_334 ;
F_111 ( V_23 , V_32 , V_335 , 0 ) ;
V_32 [ 0 ] |= ( F_95 ( 0x2a00 ) >> 7 ) & 0x40 ;
V_95 = ( V_32 [ 0 ] >> 3 ) & 0xf ;
V_318 -> V_17 . V_104 = V_319 [ V_95 ] ;
V_318 -> V_17 . V_97 = V_23 -> V_148 . V_97 ;
V_318 -> V_17 . V_98 = V_23 -> V_148 . V_98 ;
V_318 -> V_17 . V_9 = V_101 ;
V_318 -> V_17 . V_107 = V_318 -> V_17 . V_97 ;
V_318 -> V_17 . V_99 = V_100 ;
V_318 -> V_17 . V_9 = V_101 ;
V_318 -> V_17 . V_102 = 0 ;
if ( V_318 -> V_17 . V_104 != V_320 )
V_318 -> V_17 . V_107 *= 2 ;
if ( V_318 -> V_17 . V_104 == V_324 ||
V_318 -> V_17 . V_104 == V_328 )
V_318 -> V_17 . V_107 *= 2 ;
V_318 -> V_17 . V_106 = V_318 -> V_17 . V_107 * V_318 -> V_17 . V_98 ;
V_318 -> V_336 = ( void * ) V_23 -> V_330 ;
V_318 -> V_67 = 0 ;
if ( V_23 -> V_29 )
V_318 -> V_67 |= V_337 ;
if ( V_23 -> V_25 )
V_318 -> V_67 |= V_338 ;
if ( V_168 -> V_238 )
V_318 -> V_67 |= V_339 ;
V_95 &= 7 ;
if ( V_95 == 1 || V_95 > 4 )
return 0 ;
if ( V_95 == 2 || V_95 == 3 )
V_318 -> V_331 |= V_340 ;
else
V_318 -> V_331 |= V_341 ;
if ( V_23 -> V_27 ) {
if ( V_95 == 2 || V_95 == 3 )
V_318 -> V_67 |= V_342 ;
else
V_318 -> V_67 |= V_343 ;
}
return 0 ;
}
static int F_112 ( struct V_84 * V_84 , void * V_85 , struct V_317 * V_318 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
struct V_167 * V_168 = & V_23 -> V_125 ;
if ( ! ( V_23 -> V_62 & V_329 ) )
return - V_64 ;
if ( ! V_23 -> V_330 )
return - V_64 ;
V_23 -> V_25 = ( V_318 -> V_67 & V_338 ) != 0 ;
V_23 -> V_27 =
( V_318 -> V_67 & ( V_343 | V_342 ) ) != 0 ;
V_23 -> V_29 = ( V_318 -> V_67 & V_337 ) != 0 ;
F_7 ( V_23 ) ;
V_168 -> V_238 = ( V_318 -> V_67 & V_339 ) != 0 ;
return F_110 ( V_84 , V_85 , V_318 ) ;
}
static int F_113 ( struct V_84 * V_84 , void * V_85 , unsigned int V_344 )
{
struct V_57 * V_58 = F_28 ( V_85 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
if ( ! ( V_23 -> V_62 & V_329 ) )
return - V_64 ;
F_8 ( V_23 , V_345 , 1 , V_344 != 0 ) ;
return 0 ;
}
static int F_114 ( struct V_346 * V_85 , struct V_347 * V_348 )
{
switch ( V_348 -> type ) {
case V_349 :
case V_350 :
case V_351 :
return F_115 ( V_85 , V_348 , 0 ) ;
default:
return - V_64 ;
}
}
static int F_116 ( struct V_84 * V_84 , void * V_85 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
T_2 V_32 [ V_33 ] ;
int V_352 = V_23 -> V_62 & V_63 ;
struct V_227 V_353 ;
struct V_220 V_354 ;
int V_15 ;
F_117 ( L_19 ,
V_23 -> V_355 ) ;
F_117 ( L_20 , V_356 , V_23 -> V_216 ) ;
if ( V_23 -> V_272 & V_357 ) {
struct V_358 V_359 ;
F_118 ( V_23 , & V_359 ) ;
}
F_58 ( V_23 , V_188 , V_360 ) ;
F_73 ( V_23 , V_23 -> V_251 , & V_353 ) ;
F_64 ( V_23 , V_23 -> V_223 , & V_354 ) ;
F_117 ( L_21 , V_353 . V_291 ) ;
F_117 ( L_22 , V_354 . V_291 ,
( V_23 -> V_361 & ~ 0x300 ) == 0x200 ? L_23 : L_24 ) ;
if ( V_352 ) {
struct V_228 V_362 ;
struct V_226 V_363 ;
int V_364 = V_23 -> V_79 ;
static const char * const V_365 [ 5 ] = {
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
} ;
static const char * const V_366 [ 5 ] = {
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34
} ;
static const char * const V_367 [ 4 ] = {
L_25 ,
L_35 ,
L_36 ,
L_37
} ;
static const char * const V_319 [ 16 ] = {
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
F_75 ( V_23 , V_23 -> V_256 , & V_362 ) ;
F_69 ( V_23 , 0 , & V_363 ) ;
F_117 ( L_54 , V_362 . V_291 ) ;
F_117 ( L_55 , V_363 . V_291 ,
V_366 [ V_23 -> V_368 ] ,
V_366 [ V_23 -> V_369 ] ) ;
if ( V_364 < 0 || V_364 > V_370 )
V_364 = V_80 ;
F_117 ( L_56 , V_365 [ V_364 ] ) ;
F_111 ( V_23 , V_32 , V_335 , 0 ) ;
V_32 [ 0 ] |= ( F_95 ( 0x2a00 ) >> 7 ) & 0x40 ;
F_117 ( L_57 ,
V_32 [ 0 ] & 1 ? L_58 : L_59 ,
V_367 [ ( V_32 [ 0 ] >> 1 ) & 0x3 ] ,
V_319 [ ( V_32 [ 0 ] >> 3 ) & 0xf ] ) ;
}
F_117 ( L_60 ,
F_14 ( V_285 , & V_23 -> V_50 ) ? L_61 : L_62 ) ;
F_119 ( & V_23 -> V_41 . V_371 , V_23 -> V_372 . V_291 ) ;
F_117 ( L_63 , V_23 -> V_50 ) ;
for ( V_15 = 0 ; V_15 < V_373 ; V_15 ++ ) {
struct V_34 * V_35 = & V_23 -> V_38 [ V_15 ] ;
if ( V_35 -> V_374 == NULL || V_35 -> V_375 == 0 )
continue;
F_117 ( L_64 , V_35 -> V_291 , V_35 -> V_376 ,
( V_35 -> V_375 - V_35 -> V_377 . V_375 ) * 100 / V_35 -> V_375 ,
( V_35 -> V_375 * V_35 -> V_378 ) / 1024 , V_35 -> V_375 ) ;
}
F_117 ( L_65 ,
( long long ) V_23 -> V_379 ,
( long long ) V_23 -> V_380 ) ;
F_117 ( L_66 ,
V_23 -> V_355 ) ;
return 0 ;
}
static int F_120 ( struct V_84 * V_381 , unsigned int V_65 , void * V_190 )
{
struct V_57 * V_58 = F_28 ( V_381 -> V_382 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
int V_383 = V_381 -> V_384 & V_385 ;
struct V_34 * V_35 = & V_23 -> V_38 [ V_58 -> type ] ;
unsigned long V_386 = ( unsigned long ) V_190 ;
switch ( V_65 ) {
case V_387 : {
struct V_388 * args = V_190 ;
F_105 ( L_67 ) ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( args -> type != V_232 )
return - V_64 ;
if ( V_23 -> V_79 == V_389 && args -> V_390 == NULL )
return 0 ;
if ( F_24 ( V_58 , V_58 -> type ) ) {
return - V_72 ;
}
if ( F_22 ( V_23 , V_389 ) != V_389 ) {
F_121 ( V_35 ) ;
return - V_72 ;
}
V_58 -> V_391 = 1 ;
if ( args -> V_390 == NULL )
return 0 ;
return F_122 ( V_23 , args ) ;
}
case V_392 : {
T_2 V_32 [ V_33 ] ;
T_7 * V_78 = V_190 ;
F_105 ( L_68 ) ;
if ( V_35 -> type < V_39 ) {
* V_78 = V_35 -> V_393 ;
break;
}
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( F_14 ( V_394 , & V_23 -> V_50 ) ) {
* V_78 = ( T_7 ) ( ( T_7 ) V_23 -> V_395 [ 2 ] << 32 ) |
( T_7 ) V_23 -> V_395 [ 1 ] ;
break;
}
* V_78 = 0 ;
if ( F_12 ( & V_23 -> V_44 ) ) {
if ( F_18 ( V_23 , V_396 , 5 , V_32 ) ) {
F_123 ( L_69 ) ;
return - V_397 ;
}
memcpy ( V_23 -> V_395 , V_32 , sizeof( V_23 -> V_395 ) ) ;
F_26 ( V_394 , & V_23 -> V_50 ) ;
* V_78 = ( T_7 ) ( ( T_7 ) V_32 [ 2 ] << 32 ) | ( T_7 ) V_32 [ 1 ] ;
}
break;
}
case V_398 : {
T_2 V_32 [ V_33 ] ;
T_7 * V_399 = V_190 ;
F_105 ( L_70 ) ;
if ( V_35 -> type < V_39 ) {
* V_399 = 0 ;
break;
}
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
if ( F_14 ( V_394 , & V_23 -> V_50 ) ) {
* V_399 = V_23 -> V_395 [ 0 ] ;
break;
}
* V_399 = 0 ;
if ( F_12 ( & V_23 -> V_44 ) ) {
if ( F_18 ( V_23 , V_396 , 5 , V_32 ) ) {
F_123 ( L_69 ) ;
return - V_397 ;
}
memcpy ( V_23 -> V_395 , V_32 , sizeof( V_23 -> V_395 ) ) ;
F_26 ( V_394 , & V_23 -> V_50 ) ;
* V_399 = V_32 [ 0 ] ;
}
break;
}
case V_400 : {
struct V_59 V_60 ;
F_105 ( L_71 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_66 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_401 : {
struct V_59 V_60 ;
F_105 ( L_72 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_74 ;
V_60 . V_67 = V_76 | V_75 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_402 : {
struct V_59 V_60 ;
F_105 ( L_73 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_81 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_403 : {
struct V_59 V_60 ;
F_105 ( L_74 ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_65 = V_83 ;
return F_21 ( V_23 , V_58 , & V_60 , 0 ) ;
}
case V_404 :
case V_405 : {
struct V_59 * V_60 = V_190 ;
int V_61 = ( V_65 == V_405 ) ;
if ( V_61 )
F_105 ( L_75 , V_60 -> V_65 ) ;
else
F_105 ( L_76 , V_60 -> V_65 ) ;
return F_21 ( V_23 , V_58 , V_60 , V_61 ) ;
}
case V_406 : {
struct V_407 * V_408 = V_190 ;
F_10 ( V_37 ) ;
F_105 ( L_77 ) ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
memset ( V_408 , 0 , sizeof( * V_408 ) ) ;
F_26 ( V_409 , & V_23 -> V_50 ) ;
while ( 1 ) {
if ( F_23 ( V_410 , & V_23 -> V_50 ) )
V_408 -> type = V_411 ;
else if ( F_23 ( V_412 , & V_23 -> V_50 ) ) {
V_408 -> type = V_413 ;
V_408 -> V_414 . V_415 = F_14 ( V_416 , & V_23 -> V_50 ) ?
V_417 : V_418 ;
if ( V_23 -> V_79 == V_389 &&
( V_23 -> V_125 . V_126 & V_127 ) ==
V_132 ) {
V_408 -> V_414 . V_415 = V_419 ;
}
}
if ( V_408 -> type )
return 0 ;
if ( V_383 )
return - V_420 ;
F_124 ( & V_23 -> V_421 ) ;
F_13 ( & V_23 -> V_422 , & V_37 , V_48 ) ;
if ( ! F_14 ( V_410 , & V_23 -> V_50 ) &&
! F_14 ( V_412 , & V_23 -> V_50 ) )
F_16 () ;
F_17 ( & V_23 -> V_422 , & V_37 ) ;
F_125 ( & V_23 -> V_421 ) ;
if ( F_15 ( V_51 ) ) {
F_19 ( L_78 ) ;
return - V_52 ;
}
}
break;
}
case V_423 :
F_105 ( L_79 ) ;
if ( ! ( V_23 -> V_62 & V_63 ) )
return - V_64 ;
return F_126 ( V_23 , V_386 == V_424 ) ;
case V_425 :
F_105 ( L_80 ) ;
V_23 -> V_43 = V_386 ;
return 0 ;
case V_426 :
F_105 ( L_81 ) ;
if ( V_386 > V_427 )
return - V_64 ;
V_23 -> V_368 = V_386 ;
F_8 ( V_23 , V_428 , 2 , V_23 -> V_369 , V_23 -> V_368 ) ;
return 0 ;
case V_429 :
F_105 ( L_82 ) ;
if ( V_386 > V_427 )
return - V_64 ;
V_23 -> V_369 = V_386 ;
F_8 ( V_23 , V_428 , 2 , V_23 -> V_369 , V_23 -> V_368 ) ;
return 0 ;
default:
return - V_64 ;
}
return 0 ;
}
static long F_127 ( struct V_84 * V_84 , void * V_85 , bool V_430 ,
int V_65 , void * V_190 )
{
struct V_22 * V_23 = F_28 ( V_85 ) -> V_23 ;
if ( ! V_430 ) {
switch ( V_65 ) {
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_423 :
case V_425 :
case V_426 :
case V_429 :
return - V_72 ;
}
}
switch ( V_65 ) {
case V_431 : {
T_2 V_207 = * ( T_2 * ) V_190 ;
if ( ( V_207 == 0 && V_23 -> V_432 . V_433 ) || ( V_207 & 0x01 ) )
F_128 ( V_23 ) ;
if ( V_207 & 0x02 )
F_32 ( V_23 -> V_121 , V_188 , V_434 , 0 ) ;
break;
}
case V_387 :
case V_392 :
case V_398 :
case V_406 :
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
case V_405 :
case V_423 :
case V_425 :
case V_426 :
case V_429 :
return F_120 ( V_84 , V_65 , ( void * ) V_190 ) ;
default:
return - V_64 ;
}
return 0 ;
}
static long F_129 ( struct V_22 * V_23 , struct V_84 * V_381 ,
unsigned int V_65 , unsigned long V_190 )
{
struct V_435 * V_436 = F_130 ( V_381 ) ;
long V_151 ;
if ( V_437 & V_438 )
V_436 -> V_439 = V_440 | V_441 ;
V_151 = F_131 ( V_381 , V_65 , V_190 ) ;
V_436 -> V_439 = 0 ;
return V_151 ;
}
long F_132 ( struct V_84 * V_381 , unsigned int V_65 , unsigned long V_190 )
{
struct V_57 * V_58 = F_28 ( V_381 -> V_382 ) ;
struct V_22 * V_23 = V_58 -> V_23 ;
long V_442 ;
if ( V_65 == V_443 )
return F_129 ( V_23 , V_381 , V_65 , V_190 ) ;
F_125 ( & V_23 -> V_421 ) ;
V_442 = F_129 ( V_23 , V_381 , V_65 , V_190 ) ;
F_124 ( & V_23 -> V_421 ) ;
return V_442 ;
}
void F_133 ( struct V_435 * V_374 )
{
V_374 -> V_444 = & V_445 ;
}
