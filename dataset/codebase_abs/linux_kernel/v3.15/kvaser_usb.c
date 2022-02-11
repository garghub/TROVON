static inline int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
return F_2 ( V_2 -> V_6 ,
F_3 ( V_2 -> V_6 ,
V_2 -> V_7 -> V_8 ) ,
V_4 , V_4 -> V_9 , & V_5 ,
V_10 ) ;
}
static int F_4 ( const struct V_1 * V_2 , T_1 V_11 ,
struct V_3 * V_4 )
{
struct V_3 * V_12 ;
void * V_13 ;
int V_5 ;
int V_14 ;
int V_15 = 0 ;
V_13 = F_5 ( V_16 , V_17 ) ;
if ( ! V_13 )
return - V_18 ;
V_14 = F_2 ( V_2 -> V_6 ,
F_6 ( V_2 -> V_6 ,
V_2 -> V_19 -> V_8 ) ,
V_13 , V_16 , & V_5 ,
V_20 ) ;
if ( V_14 < 0 )
goto V_21;
while ( V_15 <= V_5 - V_22 ) {
V_12 = V_13 + V_15 ;
if ( ! V_12 -> V_9 )
break;
if ( V_15 + V_12 -> V_9 > V_5 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 , L_1 ) ;
break;
}
if ( V_12 -> V_11 == V_11 ) {
memcpy ( V_4 , V_12 , V_12 -> V_9 ) ;
goto V_21;
}
V_15 += V_12 -> V_9 ;
}
V_14 = - V_24 ;
V_21:
F_8 ( V_13 ) ;
return V_14 ;
}
static int F_9 ( const struct V_1 * V_2 ,
T_1 V_25 , int V_26 )
{
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_11 = V_25 ;
V_4 -> V_9 = V_22 + sizeof( struct V_28 ) ;
V_4 -> V_29 . V_30 . V_26 = V_26 ;
V_4 -> V_29 . V_30 . V_31 = 0xff ;
V_27 = F_1 ( V_2 , V_4 ) ;
F_8 ( V_4 ) ;
return V_27 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_14 ;
V_14 = F_9 ( V_2 , V_32 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_2 , V_33 , & V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_34 = F_12 ( V_4 . V_29 . V_35 . V_34 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_14 ;
V_14 = F_9 ( V_2 , V_36 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_2 , V_37 , & V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_38 = V_4 . V_29 . V_39 . V_38 ;
if ( V_2 -> V_38 > V_40 )
return - V_24 ;
return 0 ;
}
static void F_14 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
T_1 V_26 = V_4 -> V_29 . V_51 . V_26 ;
T_1 V_31 = V_4 -> V_29 . V_51 . V_31 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_46 = V_2 -> V_52 [ V_26 ] ;
if ( ! F_15 ( V_46 -> V_53 ) )
return;
V_42 = & V_46 -> V_53 -> V_42 ;
V_44 = & V_46 -> V_54 [ V_31 % V_55 ] ;
if ( V_46 -> V_56 . V_57 &&
( V_46 -> V_56 . V_58 >= V_59 ) ) {
V_48 = F_16 ( V_46 -> V_53 , & V_50 ) ;
if ( V_48 ) {
V_50 -> V_60 |= V_61 ;
F_17 ( V_48 ) ;
V_42 -> V_62 ++ ;
V_42 -> V_63 += V_50 -> V_64 ;
} else {
F_18 ( V_46 -> V_53 ,
L_3 ) ;
}
V_46 -> V_56 . V_65 . V_66 ++ ;
F_19 ( V_46 -> V_53 ) ;
V_46 -> V_56 . V_58 = V_67 ;
}
V_42 -> V_68 ++ ;
V_42 -> V_69 += V_44 -> V_70 ;
F_20 ( V_46 -> V_53 , V_44 -> V_71 ) ;
V_44 -> V_71 = V_55 ;
F_21 ( & V_46 -> V_72 ) ;
F_22 ( V_46 -> V_53 ) ;
}
static void F_23 ( struct V_73 * V_73 )
{
struct V_74 * V_53 = V_73 -> V_44 ;
F_8 ( V_73 -> V_75 ) ;
if ( V_73 -> V_76 )
F_24 ( V_53 , L_4 ,
V_73 -> V_76 ) ;
}
static int F_25 ( struct V_45 * V_46 ,
T_1 V_25 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_74 * V_53 = V_46 -> V_53 ;
struct V_3 * V_4 ;
struct V_73 * V_73 ;
void * V_13 ;
int V_14 ;
V_73 = F_26 ( 0 , V_77 ) ;
if ( ! V_73 ) {
F_18 ( V_53 , L_5 ) ;
return - V_18 ;
}
V_13 = F_10 ( sizeof( struct V_3 ) , V_77 ) ;
if ( ! V_13 ) {
F_27 ( V_73 ) ;
return - V_18 ;
}
V_4 = (struct V_3 * ) V_13 ;
V_4 -> V_9 = V_22 + sizeof( struct V_28 ) ;
V_4 -> V_11 = V_25 ;
V_4 -> V_29 . V_30 . V_26 = V_46 -> V_26 ;
F_28 ( V_73 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 ,
V_2 -> V_7 -> V_8 ) ,
V_13 , V_4 -> V_9 ,
F_23 , V_46 ) ;
F_29 ( V_73 , & V_46 -> V_78 ) ;
V_14 = F_30 ( V_73 , V_77 ) ;
if ( V_14 ) {
F_18 ( V_53 , L_6 ) ;
F_31 ( V_73 ) ;
F_27 ( V_73 ) ;
F_8 ( V_13 ) ;
return V_14 ;
}
F_27 ( V_73 ) ;
return 0 ;
}
static void F_32 ( struct V_45 * V_46 )
{
int V_79 ;
F_33 ( & V_46 -> V_78 ) ;
F_34 ( & V_46 -> V_72 , 0 ) ;
for ( V_79 = 0 ; V_79 < V_55 ; V_79 ++ )
V_46 -> V_54 [ V_79 ] . V_71 = V_55 ;
}
static void F_35 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_49 * V_50 ;
struct V_47 * V_48 ;
struct V_41 * V_42 ;
struct V_45 * V_46 ;
unsigned int V_80 ;
T_1 V_26 , V_76 , V_81 , V_82 , V_83 ;
switch ( V_4 -> V_11 ) {
case V_84 :
V_26 = V_4 -> V_29 . V_85 . V_26 ;
V_76 = V_4 -> V_29 . V_85 . V_76 ;
V_81 = V_4 -> V_29 . V_85 . V_86 ;
V_82 = V_4 -> V_29 . V_85 . V_87 ;
V_83 = V_4 -> V_29 . V_85 . V_83 ;
break;
case V_88 :
V_26 = V_4 -> V_29 . V_89 . V_26 ;
V_76 = V_4 -> V_29 . V_89 . V_90 [ 0 ] ;
V_81 = V_4 -> V_29 . V_89 . V_90 [ 2 ] ;
V_82 = V_4 -> V_29 . V_89 . V_90 [ 3 ] ;
V_83 = V_4 -> V_29 . V_89 . V_90 [ 1 ] ;
break;
case V_91 :
V_26 = V_4 -> V_29 . V_92 . V_26 ;
V_76 = V_4 -> V_29 . V_92 . V_76 ;
V_81 = V_4 -> V_29 . V_92 . V_86 ;
V_82 = V_4 -> V_29 . V_92 . V_87 ;
V_83 = 0 ;
break;
default:
F_7 ( V_2 -> V_6 -> V_2 . V_23 , L_7 ,
V_4 -> V_11 ) ;
return;
}
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_46 = V_2 -> V_52 [ V_26 ] ;
V_42 = & V_46 -> V_53 -> V_42 ;
if ( V_76 & V_93 ) {
F_32 ( V_46 ) ;
return;
}
V_48 = F_16 ( V_46 -> V_53 , & V_50 ) ;
if ( ! V_48 ) {
V_42 -> V_94 ++ ;
return;
}
V_80 = V_46 -> V_56 . V_58 ;
F_36 ( V_46 -> V_53 , L_8 , V_76 ) ;
if ( V_76 & V_95 ) {
V_50 -> V_60 |= V_96 ;
V_46 -> V_56 . V_65 . V_97 ++ ;
if ( ! V_46 -> V_56 . V_57 )
F_25 ( V_46 , V_98 ) ;
F_37 ( V_46 -> V_53 ) ;
V_80 = V_59 ;
} else if ( V_76 & V_99 ) {
if ( V_46 -> V_56 . V_58 != V_100 ) {
V_50 -> V_60 |= V_101 ;
if ( V_81 || V_82 )
V_50 -> V_90 [ 1 ] = ( V_81 > V_82 )
? V_102
: V_103 ;
else
V_50 -> V_90 [ 1 ] = V_102 |
V_103 ;
V_46 -> V_56 . V_65 . V_104 ++ ;
}
V_80 = V_100 ;
}
if ( V_76 == V_105 ) {
if ( ( V_46 -> V_56 . V_58 < V_106 ) &&
( ( V_81 >= 96 ) || ( V_82 >= 96 ) ) ) {
V_50 -> V_60 |= V_101 ;
V_50 -> V_90 [ 1 ] = ( V_81 > V_82 )
? V_107
: V_108 ;
V_46 -> V_56 . V_65 . V_109 ++ ;
V_80 = V_106 ;
} else if ( V_46 -> V_56 . V_58 > V_67 ) {
V_50 -> V_60 |= V_110 ;
V_50 -> V_90 [ 2 ] = V_111 ;
V_80 = V_67 ;
}
}
if ( ! V_76 ) {
V_50 -> V_60 |= V_110 ;
V_50 -> V_90 [ 2 ] = V_111 ;
V_80 = V_67 ;
}
if ( V_46 -> V_56 . V_57 &&
( V_46 -> V_56 . V_58 >= V_59 ) &&
( V_80 < V_59 ) ) {
V_50 -> V_60 |= V_61 ;
F_19 ( V_46 -> V_53 ) ;
V_46 -> V_56 . V_65 . V_66 ++ ;
}
if ( V_83 ) {
V_46 -> V_56 . V_65 . V_112 ++ ;
V_42 -> V_113 ++ ;
V_50 -> V_60 |= V_114 | V_110 ;
if ( V_83 & V_115 )
V_50 -> V_90 [ 3 ] |= ( V_116 ) ;
if ( V_83 & V_117 )
V_50 -> V_90 [ 3 ] |= ( V_118 |
V_119 ) ;
if ( V_83 & V_120 )
V_50 -> V_90 [ 2 ] |= V_121 ;
if ( V_83 & V_122 )
V_50 -> V_90 [ 2 ] |= V_123 ;
if ( V_83 & V_124 )
V_50 -> V_90 [ 2 ] |= V_125 ;
if ( V_83 & V_126 )
V_50 -> V_90 [ 2 ] |= V_127 ;
if ( V_83 & V_128 )
V_50 -> V_90 [ 2 ] |= V_129 ;
}
V_50 -> V_90 [ 6 ] = V_81 ;
V_50 -> V_90 [ 7 ] = V_82 ;
V_46 -> V_130 . V_81 = V_81 ;
V_46 -> V_130 . V_82 = V_82 ;
V_46 -> V_56 . V_58 = V_80 ;
F_17 ( V_48 ) ;
V_42 -> V_62 ++ ;
V_42 -> V_63 += V_50 -> V_64 ;
}
static void F_38 ( const struct V_45 * V_46 ,
const struct V_3 * V_4 )
{
struct V_49 * V_50 ;
struct V_47 * V_48 ;
struct V_41 * V_42 = & V_46 -> V_53 -> V_42 ;
if ( V_4 -> V_29 . V_131 . V_132 & ( V_133 |
V_134 ) ) {
F_18 ( V_46 -> V_53 , L_9 ,
V_4 -> V_29 . V_131 . V_132 ) ;
V_42 -> V_113 ++ ;
return;
}
if ( V_4 -> V_29 . V_131 . V_132 & V_135 ) {
V_48 = F_16 ( V_46 -> V_53 , & V_50 ) ;
if ( ! V_48 ) {
V_42 -> V_94 ++ ;
return;
}
V_50 -> V_60 |= V_101 ;
V_50 -> V_90 [ 1 ] = V_136 ;
V_42 -> V_137 ++ ;
V_42 -> V_113 ++ ;
F_17 ( V_48 ) ;
V_42 -> V_62 ++ ;
V_42 -> V_63 += V_50 -> V_64 ;
}
}
static void F_39 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_45 * V_46 ;
struct V_49 * V_50 ;
struct V_47 * V_48 ;
struct V_41 * V_42 ;
T_1 V_26 = V_4 -> V_29 . V_131 . V_26 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_46 = V_2 -> V_52 [ V_26 ] ;
V_42 = & V_46 -> V_53 -> V_42 ;
if ( ( V_4 -> V_29 . V_131 . V_132 & V_133 ) &&
( V_4 -> V_11 == V_88 ) ) {
F_35 ( V_2 , V_4 ) ;
return;
} else if ( V_4 -> V_29 . V_131 . V_132 & ( V_133 |
V_134 |
V_135 ) ) {
F_38 ( V_46 , V_4 ) ;
return;
} else if ( V_4 -> V_29 . V_131 . V_132 & ~ V_138 ) {
F_24 ( V_46 -> V_53 ,
L_10 ,
V_4 -> V_29 . V_131 . V_132 ) ;
return;
}
V_48 = F_40 ( V_46 -> V_53 , & V_50 ) ;
if ( ! V_48 ) {
V_42 -> V_139 ++ ;
return;
}
if ( V_4 -> V_11 == V_88 ) {
V_50 -> V_60 = F_12 ( V_4 -> V_29 . V_89 . V_11 ) ;
if ( V_50 -> V_60 & V_140 )
V_50 -> V_60 &= V_141 | V_142 ;
else
V_50 -> V_60 &= V_143 ;
V_50 -> V_64 = F_41 ( V_4 -> V_29 . V_89 . V_70 ) ;
if ( V_4 -> V_29 . V_89 . V_144 & V_138 )
V_50 -> V_60 |= V_145 ;
else
memcpy ( V_50 -> V_90 , & V_4 -> V_29 . V_89 . V_90 ,
V_50 -> V_64 ) ;
} else {
V_50 -> V_60 = ( ( V_4 -> V_29 . V_131 . V_4 [ 0 ] & 0x1f ) << 6 ) |
( V_4 -> V_29 . V_131 . V_4 [ 1 ] & 0x3f ) ;
if ( V_4 -> V_11 == V_146 ) {
V_50 -> V_60 <<= 18 ;
V_50 -> V_60 |= ( ( V_4 -> V_29 . V_131 . V_4 [ 2 ] & 0x0f ) << 14 ) |
( ( V_4 -> V_29 . V_131 . V_4 [ 3 ] & 0xff ) << 6 ) |
( V_4 -> V_29 . V_131 . V_4 [ 4 ] & 0x3f ) ;
V_50 -> V_60 |= V_142 ;
}
V_50 -> V_64 = F_41 ( V_4 -> V_29 . V_131 . V_4 [ 5 ] ) ;
if ( V_4 -> V_29 . V_131 . V_132 & V_138 )
V_50 -> V_60 |= V_145 ;
else
memcpy ( V_50 -> V_90 , & V_4 -> V_29 . V_131 . V_4 [ 6 ] ,
V_50 -> V_64 ) ;
}
F_17 ( V_48 ) ;
V_42 -> V_62 ++ ;
V_42 -> V_63 += V_50 -> V_64 ;
}
static void F_42 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_45 * V_46 ;
T_1 V_26 = V_4 -> V_29 . V_30 . V_26 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_46 = V_2 -> V_52 [ V_26 ] ;
if ( F_43 ( & V_46 -> V_147 ) &&
F_44 ( V_46 -> V_53 ) ) {
F_22 ( V_46 -> V_53 ) ;
} else {
F_45 ( V_46 -> V_53 ) ;
F_46 ( & V_46 -> V_147 ) ;
}
}
static void F_47 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_45 * V_46 ;
T_1 V_26 = V_4 -> V_29 . V_30 . V_26 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_46 = V_2 -> V_52 [ V_26 ] ;
F_46 ( & V_46 -> V_148 ) ;
}
static void F_48 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
switch ( V_4 -> V_11 ) {
case V_149 :
F_42 ( V_2 , V_4 ) ;
break;
case V_150 :
F_47 ( V_2 , V_4 ) ;
break;
case V_151 :
case V_146 :
case V_88 :
F_39 ( V_2 , V_4 ) ;
break;
case V_91 :
case V_84 :
F_35 ( V_2 , V_4 ) ;
break;
case V_152 :
F_14 ( V_2 , V_4 ) ;
break;
default:
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_11 , V_4 -> V_11 ) ;
break;
}
}
static void F_50 ( struct V_73 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_44 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
int V_14 , V_79 ;
switch ( V_73 -> V_76 ) {
case 0 :
break;
case - V_153 :
case - V_154 :
return;
default:
F_51 ( V_2 -> V_6 -> V_2 . V_23 , L_12 ,
V_73 -> V_76 ) ;
goto V_155;
}
while ( V_15 <= V_73 -> V_156 - V_22 ) {
V_4 = V_73 -> V_75 + V_15 ;
if ( ! V_4 -> V_9 )
break;
if ( V_15 + V_4 -> V_9 > V_73 -> V_156 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 , L_1 ) ;
break;
}
F_48 ( V_2 , V_4 ) ;
V_15 += V_4 -> V_9 ;
}
V_155:
F_28 ( V_73 , V_2 -> V_6 ,
F_6 ( V_2 -> V_6 ,
V_2 -> V_19 -> V_8 ) ,
V_73 -> V_75 , V_16 ,
F_50 , V_2 ) ;
V_14 = F_30 ( V_73 , V_77 ) ;
if ( V_14 == - V_157 ) {
for ( V_79 = 0 ; V_79 < V_2 -> V_38 ; V_79 ++ ) {
if ( ! V_2 -> V_52 [ V_79 ] )
continue;
F_52 ( V_2 -> V_52 [ V_79 ] -> V_53 ) ;
}
} else if ( V_14 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_13 , V_14 ) ;
}
return;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_79 , V_14 = 0 ;
if ( V_2 -> V_158 )
return 0 ;
for ( V_79 = 0 ; V_79 < V_159 ; V_79 ++ ) {
struct V_73 * V_73 = NULL ;
T_1 * V_13 = NULL ;
T_2 V_160 ;
V_73 = F_26 ( 0 , V_17 ) ;
if ( ! V_73 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_5 ) ;
V_14 = - V_18 ;
break;
}
V_13 = F_54 ( V_2 -> V_6 , V_16 ,
V_17 , & V_160 ) ;
if ( ! V_13 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_14 ) ;
F_27 ( V_73 ) ;
V_14 = - V_18 ;
break;
}
F_28 ( V_73 , V_2 -> V_6 ,
F_6 ( V_2 -> V_6 ,
V_2 -> V_19 -> V_8 ) ,
V_13 , V_16 ,
F_50 ,
V_2 ) ;
V_73 -> V_161 = V_160 ;
V_73 -> V_162 |= V_163 ;
F_29 ( V_73 , & V_2 -> V_164 ) ;
V_14 = F_30 ( V_73 , V_17 ) ;
if ( V_14 ) {
F_31 ( V_73 ) ;
F_55 ( V_2 -> V_6 , V_16 , V_13 ,
V_160 ) ;
F_27 ( V_73 ) ;
break;
}
V_2 -> V_165 [ V_79 ] = V_13 ;
V_2 -> V_166 [ V_79 ] = V_160 ;
F_27 ( V_73 ) ;
}
if ( V_79 == 0 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_15 , V_14 ) ;
return V_14 ;
} else if ( V_79 < V_159 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_16 ) ;
}
V_2 -> V_158 = true ;
return 0 ;
}
static int F_56 ( const struct V_45 * V_46 )
{
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_11 = V_167 ;
V_4 -> V_9 = V_22 + sizeof( struct V_168 ) ;
V_4 -> V_29 . V_169 . V_31 = 0xff ;
V_4 -> V_29 . V_169 . V_26 = V_46 -> V_26 ;
if ( V_46 -> V_56 . V_170 & V_171 )
V_4 -> V_29 . V_169 . V_169 = V_172 ;
else
V_4 -> V_29 . V_169 . V_169 = V_173 ;
V_27 = F_1 ( V_46 -> V_2 , V_4 ) ;
F_8 ( V_4 ) ;
return V_27 ;
}
static int F_57 ( struct V_45 * V_46 )
{
int V_14 ;
F_58 ( & V_46 -> V_147 ) ;
V_14 = F_9 ( V_46 -> V_2 , V_174 ,
V_46 -> V_26 ) ;
if ( V_14 )
return V_14 ;
if ( ! F_59 ( & V_46 -> V_147 ,
F_60 ( V_175 ) ) )
return - V_176 ;
return 0 ;
}
static int F_61 ( struct V_74 * V_53 )
{
struct V_45 * V_46 = F_62 ( V_53 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
int V_14 ;
V_14 = F_63 ( V_53 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_53 ( V_2 ) ;
if ( V_14 )
goto error;
V_14 = F_56 ( V_46 ) ;
if ( V_14 )
goto error;
V_14 = F_57 ( V_46 ) ;
if ( V_14 ) {
F_24 ( V_53 , L_17 , V_14 ) ;
goto error;
}
V_46 -> V_56 . V_58 = V_67 ;
return 0 ;
error:
F_64 ( V_53 ) ;
return V_14 ;
}
static void F_65 ( struct V_1 * V_2 )
{
int V_79 ;
F_33 ( & V_2 -> V_164 ) ;
for ( V_79 = 0 ; V_79 < V_159 ; V_79 ++ )
F_55 ( V_2 -> V_6 , V_16 ,
V_2 -> V_165 [ V_79 ] ,
V_2 -> V_166 [ V_79 ] ) ;
for ( V_79 = 0 ; V_79 < V_40 ; V_79 ++ ) {
struct V_45 * V_46 = V_2 -> V_52 [ V_79 ] ;
if ( V_46 )
F_32 ( V_46 ) ;
}
}
static int F_66 ( struct V_45 * V_46 )
{
int V_14 ;
F_58 ( & V_46 -> V_148 ) ;
V_14 = F_9 ( V_46 -> V_2 , V_98 ,
V_46 -> V_26 ) ;
if ( V_14 )
return V_14 ;
if ( ! F_59 ( & V_46 -> V_148 ,
F_60 ( V_177 ) ) )
return - V_176 ;
return 0 ;
}
static int F_67 ( struct V_45 * V_46 )
{
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_11 = V_178 ;
V_4 -> V_9 = V_22 + sizeof( struct V_179 ) ;
V_4 -> V_29 . V_180 . V_26 = V_46 -> V_26 ;
V_4 -> V_29 . V_180 . V_144 = 0x00 ;
V_27 = F_1 ( V_46 -> V_2 , V_4 ) ;
F_8 ( V_4 ) ;
return V_27 ;
}
static int F_68 ( struct V_74 * V_53 )
{
struct V_45 * V_46 = F_62 ( V_53 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
int V_14 ;
F_69 ( V_53 ) ;
V_14 = F_67 ( V_46 ) ;
if ( V_14 )
F_24 ( V_53 , L_18 , V_14 ) ;
if ( F_9 ( V_2 , V_181 , V_46 -> V_26 ) )
F_24 ( V_53 , L_19 , V_14 ) ;
V_14 = F_66 ( V_46 ) ;
if ( V_14 )
F_24 ( V_53 , L_20 , V_14 ) ;
V_46 -> V_56 . V_58 = V_182 ;
F_64 ( V_46 -> V_53 ) ;
return 0 ;
}
static void F_70 ( struct V_73 * V_73 )
{
struct V_43 * V_44 = V_73 -> V_44 ;
struct V_45 * V_46 ;
struct V_74 * V_53 ;
if ( F_71 ( ! V_44 ) )
return;
V_46 = V_44 -> V_46 ;
V_53 = V_46 -> V_53 ;
F_8 ( V_73 -> V_75 ) ;
if ( ! F_15 ( V_53 ) )
return;
if ( V_73 -> V_76 )
F_72 ( V_53 , L_21 , V_73 -> V_76 ) ;
}
static T_3 F_73 ( struct V_47 * V_48 ,
struct V_74 * V_53 )
{
struct V_45 * V_46 = F_62 ( V_53 ) ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_41 * V_42 = & V_53 -> V_42 ;
struct V_49 * V_50 = (struct V_49 * ) V_48 -> V_90 ;
struct V_43 * V_44 = NULL ;
struct V_73 * V_73 ;
void * V_13 ;
struct V_3 * V_4 ;
int V_79 , V_14 ;
int V_183 = V_184 ;
if ( F_74 ( V_53 , V_48 ) )
return V_184 ;
V_73 = F_26 ( 0 , V_77 ) ;
if ( ! V_73 ) {
F_18 ( V_53 , L_5 ) ;
V_42 -> V_139 ++ ;
goto V_185;
}
V_13 = F_10 ( sizeof( struct V_3 ) , V_77 ) ;
if ( ! V_13 ) {
V_42 -> V_139 ++ ;
goto V_186;
}
V_4 = V_13 ;
V_4 -> V_9 = V_22 + sizeof( struct V_187 ) ;
V_4 -> V_29 . V_188 . V_144 = 0 ;
V_4 -> V_29 . V_188 . V_26 = V_46 -> V_26 ;
if ( V_50 -> V_60 & V_142 ) {
V_4 -> V_11 = V_189 ;
V_4 -> V_29 . V_188 . V_4 [ 0 ] = ( V_50 -> V_60 >> 24 ) & 0x1f ;
V_4 -> V_29 . V_188 . V_4 [ 1 ] = ( V_50 -> V_60 >> 18 ) & 0x3f ;
V_4 -> V_29 . V_188 . V_4 [ 2 ] = ( V_50 -> V_60 >> 14 ) & 0x0f ;
V_4 -> V_29 . V_188 . V_4 [ 3 ] = ( V_50 -> V_60 >> 6 ) & 0xff ;
V_4 -> V_29 . V_188 . V_4 [ 4 ] = V_50 -> V_60 & 0x3f ;
} else {
V_4 -> V_11 = V_190 ;
V_4 -> V_29 . V_188 . V_4 [ 0 ] = ( V_50 -> V_60 >> 6 ) & 0x1f ;
V_4 -> V_29 . V_188 . V_4 [ 1 ] = V_50 -> V_60 & 0x3f ;
}
V_4 -> V_29 . V_188 . V_4 [ 5 ] = V_50 -> V_64 ;
memcpy ( & V_4 -> V_29 . V_188 . V_4 [ 6 ] , V_50 -> V_90 , V_50 -> V_64 ) ;
if ( V_50 -> V_60 & V_145 )
V_4 -> V_29 . V_188 . V_144 |= V_138 ;
for ( V_79 = 0 ; V_79 < F_75 ( V_46 -> V_54 ) ; V_79 ++ ) {
if ( V_46 -> V_54 [ V_79 ] . V_71 == V_55 ) {
V_44 = & V_46 -> V_54 [ V_79 ] ;
break;
}
}
if ( ! V_44 ) {
F_24 ( V_53 , L_22 ) ;
V_183 = V_191 ;
goto V_192;
}
V_44 -> V_46 = V_46 ;
V_44 -> V_71 = V_79 ;
V_44 -> V_70 = V_50 -> V_64 ;
V_4 -> V_29 . V_188 . V_31 = V_44 -> V_71 ;
F_28 ( V_73 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 ,
V_2 -> V_7 -> V_8 ) ,
V_13 , V_4 -> V_9 ,
F_70 , V_44 ) ;
F_29 ( V_73 , & V_46 -> V_78 ) ;
F_76 ( V_48 , V_53 , V_44 -> V_71 ) ;
F_77 ( & V_46 -> V_72 ) ;
if ( F_78 ( & V_46 -> V_72 ) >= V_55 )
F_69 ( V_53 ) ;
V_14 = F_30 ( V_73 , V_77 ) ;
if ( F_79 ( V_14 ) ) {
F_80 ( V_53 , V_44 -> V_71 ) ;
V_48 = NULL ;
F_21 ( & V_46 -> V_72 ) ;
F_31 ( V_73 ) ;
V_42 -> V_139 ++ ;
if ( V_14 == - V_157 )
F_52 ( V_53 ) ;
else
F_24 ( V_53 , L_23 , V_14 ) ;
goto V_192;
}
F_27 ( V_73 ) ;
return V_184 ;
V_192:
F_8 ( V_13 ) ;
V_186:
F_27 ( V_73 ) ;
V_185:
F_81 ( V_48 ) ;
return V_183 ;
}
static int F_82 ( struct V_74 * V_53 )
{
struct V_45 * V_46 = F_62 ( V_53 ) ;
struct V_193 * V_194 = & V_46 -> V_56 . V_195 ;
struct V_1 * V_2 = V_46 -> V_2 ;
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_11 = V_196 ;
V_4 -> V_9 = V_22 + sizeof( struct V_197 ) ;
V_4 -> V_29 . V_198 . V_26 = V_46 -> V_26 ;
V_4 -> V_29 . V_198 . V_31 = 0xff ;
V_4 -> V_29 . V_198 . V_199 = F_83 ( V_194 -> V_199 ) ;
V_4 -> V_29 . V_198 . V_200 = V_194 -> V_200 ;
V_4 -> V_29 . V_198 . V_201 = V_194 -> V_202 + V_194 -> V_203 ;
V_4 -> V_29 . V_198 . V_204 = V_194 -> V_205 ;
if ( V_46 -> V_56 . V_170 & V_206 )
V_4 -> V_29 . V_198 . V_207 = 3 ;
else
V_4 -> V_29 . V_198 . V_207 = 1 ;
V_27 = F_1 ( V_2 , V_4 ) ;
F_8 ( V_4 ) ;
return V_27 ;
}
static int F_84 ( struct V_74 * V_53 ,
enum V_208 V_209 )
{
struct V_45 * V_46 = F_62 ( V_53 ) ;
int V_14 ;
switch ( V_209 ) {
case V_210 :
V_14 = F_25 ( V_46 , V_174 ) ;
if ( V_14 )
return V_14 ;
break;
default:
return - V_211 ;
}
return 0 ;
}
static int F_85 ( const struct V_74 * V_53 ,
struct V_212 * V_130 )
{
struct V_45 * V_46 = F_62 ( V_53 ) ;
* V_130 = V_46 -> V_130 ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
int V_79 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_38 ; V_79 ++ ) {
if ( ! V_2 -> V_52 [ V_79 ] )
continue;
F_87 ( V_2 -> V_52 [ V_79 ] -> V_53 ) ;
}
F_65 ( V_2 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_38 ; V_79 ++ ) {
if ( ! V_2 -> V_52 [ V_79 ] )
continue;
F_88 ( V_2 -> V_52 [ V_79 ] -> V_53 ) ;
}
}
static int F_89 ( struct V_213 * V_214 ,
const struct V_215 * V_11 , int V_26 )
{
struct V_1 * V_2 = F_90 ( V_214 ) ;
struct V_74 * V_53 ;
struct V_45 * V_46 ;
int V_79 , V_14 ;
V_53 = F_91 ( sizeof( * V_46 ) , V_55 ) ;
if ( ! V_53 ) {
F_7 ( & V_214 -> V_2 , L_24 ) ;
return - V_18 ;
}
V_46 = F_62 ( V_53 ) ;
F_58 ( & V_46 -> V_147 ) ;
F_58 ( & V_46 -> V_148 ) ;
F_92 ( & V_46 -> V_78 ) ;
F_34 ( & V_46 -> V_72 , 0 ) ;
for ( V_79 = 0 ; V_79 < F_75 ( V_46 -> V_54 ) ; V_79 ++ )
V_46 -> V_54 [ V_79 ] . V_71 = V_55 ;
V_46 -> V_2 = V_2 ;
V_46 -> V_53 = V_53 ;
V_46 -> V_26 = V_26 ;
V_46 -> V_56 . V_58 = V_182 ;
V_46 -> V_56 . clock . V_216 = V_217 ;
V_46 -> V_56 . V_218 = & V_219 ;
V_46 -> V_56 . V_220 = F_82 ;
V_46 -> V_56 . V_221 = F_84 ;
if ( V_11 -> V_222 & V_223 )
V_46 -> V_56 . V_224 = F_85 ;
V_46 -> V_56 . V_225 = V_206 ;
if ( V_11 -> V_222 & V_226 )
V_46 -> V_56 . V_225 |= V_171 ;
V_53 -> V_144 |= V_227 ;
V_53 -> V_228 = & V_229 ;
F_93 ( V_53 , & V_214 -> V_2 ) ;
V_53 -> V_230 = V_26 ;
V_2 -> V_52 [ V_26 ] = V_46 ;
V_14 = F_94 ( V_53 ) ;
if ( V_14 ) {
F_7 ( & V_214 -> V_2 , L_25 ) ;
F_88 ( V_53 ) ;
V_2 -> V_52 [ V_26 ] = NULL ;
return V_14 ;
}
F_36 ( V_53 , L_26 ) ;
return 0 ;
}
static int F_95 ( const struct V_213 * V_214 ,
struct V_231 * * V_232 ,
struct V_231 * * V_233 )
{
const struct V_234 * V_235 ;
struct V_231 * V_236 ;
int V_79 ;
V_235 = & V_214 -> V_237 [ 0 ] ;
for ( V_79 = 0 ; V_79 < V_235 -> V_238 . V_239 ; ++ V_79 ) {
V_236 = & V_235 -> V_236 [ V_79 ] . V_238 ;
if ( ! * V_232 && F_96 ( V_236 ) )
* V_232 = V_236 ;
if ( ! * V_233 && F_97 ( V_236 ) )
* V_233 = V_236 ;
if ( * V_232 && * V_233 )
return 0 ;
}
return - V_157 ;
}
static int F_98 ( struct V_213 * V_214 ,
const struct V_215 * V_11 )
{
struct V_1 * V_2 ;
int V_14 = - V_18 ;
int V_79 ;
V_2 = F_99 ( & V_214 -> V_2 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
V_14 = F_95 ( V_214 , & V_2 -> V_19 , & V_2 -> V_7 ) ;
if ( V_14 ) {
F_7 ( & V_214 -> V_2 , L_27 ) ;
return V_14 ;
}
V_2 -> V_6 = F_100 ( V_214 ) ;
F_92 ( & V_2 -> V_164 ) ;
F_101 ( V_214 , V_2 ) ;
for ( V_79 = 0 ; V_79 < V_40 ; V_79 ++ )
F_9 ( V_2 , V_181 , V_79 ) ;
V_14 = F_11 ( V_2 ) ;
if ( V_14 ) {
F_7 ( & V_214 -> V_2 ,
L_28 , V_14 ) ;
return V_14 ;
}
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_7 ( & V_214 -> V_2 ,
L_29 , V_14 ) ;
return V_14 ;
}
F_102 ( & V_214 -> V_2 , L_30 ,
( ( V_2 -> V_34 >> 24 ) & 0xff ) ,
( ( V_2 -> V_34 >> 16 ) & 0xff ) ,
( V_2 -> V_34 & 0xffff ) ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_38 ; V_79 ++ ) {
V_14 = F_89 ( V_214 , V_11 , V_79 ) ;
if ( V_14 ) {
F_86 ( V_2 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_103 ( struct V_213 * V_214 )
{
struct V_1 * V_2 = F_90 ( V_214 ) ;
F_101 ( V_214 , NULL ) ;
if ( ! V_2 )
return;
F_86 ( V_2 ) ;
}
