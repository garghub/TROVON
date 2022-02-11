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
return 0 ;
}
static void F_14 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
T_1 V_26 = V_4 -> V_29 . V_50 . V_26 ;
T_1 V_31 = V_4 -> V_29 . V_50 . V_31 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_45 = V_2 -> V_51 [ V_26 ] ;
if ( ! F_15 ( V_45 -> V_52 ) )
return;
V_41 = & V_45 -> V_52 -> V_41 ;
V_43 = & V_45 -> V_53 [ V_31 % V_54 ] ;
if ( V_45 -> V_55 . V_56 &&
( V_45 -> V_55 . V_57 >= V_58 ) ) {
V_47 = F_16 ( V_45 -> V_52 , & V_49 ) ;
if ( V_47 ) {
V_49 -> V_59 |= V_60 ;
F_17 ( V_47 ) ;
V_41 -> V_61 ++ ;
V_41 -> V_62 += V_49 -> V_63 ;
} else {
F_18 ( V_45 -> V_52 ,
L_3 ) ;
}
V_45 -> V_55 . V_64 . V_65 ++ ;
F_19 ( V_45 -> V_52 ) ;
V_45 -> V_55 . V_57 = V_66 ;
}
V_41 -> V_67 ++ ;
V_41 -> V_68 += V_43 -> V_69 ;
F_20 ( V_45 -> V_52 , V_43 -> V_70 ) ;
V_43 -> V_70 = V_54 ;
F_21 ( & V_45 -> V_71 ) ;
F_22 ( V_45 -> V_52 ) ;
}
static void F_23 ( struct V_72 * V_72 )
{
struct V_73 * V_52 = V_72 -> V_43 ;
F_8 ( V_72 -> V_74 ) ;
if ( V_72 -> V_75 )
F_24 ( V_52 , L_4 ,
V_72 -> V_75 ) ;
}
static int F_25 ( struct V_44 * V_45 ,
T_1 V_25 )
{
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_73 * V_52 = V_45 -> V_52 ;
struct V_3 * V_4 ;
struct V_72 * V_72 ;
void * V_13 ;
int V_14 ;
V_72 = F_26 ( 0 , V_76 ) ;
if ( ! V_72 ) {
F_18 ( V_52 , L_5 ) ;
return - V_18 ;
}
V_13 = F_10 ( sizeof( struct V_3 ) , V_76 ) ;
if ( ! V_13 ) {
F_18 ( V_52 , L_6 ) ;
F_27 ( V_72 ) ;
return - V_18 ;
}
V_4 = (struct V_3 * ) V_13 ;
V_4 -> V_9 = V_22 + sizeof( struct V_28 ) ;
V_4 -> V_11 = V_25 ;
V_4 -> V_29 . V_30 . V_26 = V_45 -> V_26 ;
F_28 ( V_72 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 ,
V_2 -> V_7 -> V_8 ) ,
V_13 , V_4 -> V_9 ,
F_23 , V_45 ) ;
F_29 ( V_72 , & V_45 -> V_77 ) ;
V_14 = F_30 ( V_72 , V_76 ) ;
if ( V_14 ) {
F_18 ( V_52 , L_7 ) ;
F_31 ( V_72 ) ;
F_27 ( V_72 ) ;
F_8 ( V_13 ) ;
return V_14 ;
}
F_27 ( V_72 ) ;
return 0 ;
}
static void F_32 ( struct V_44 * V_45 )
{
int V_78 ;
F_33 ( & V_45 -> V_77 ) ;
F_34 ( & V_45 -> V_71 , 0 ) ;
for ( V_78 = 0 ; V_78 < V_54 ; V_78 ++ )
V_45 -> V_53 [ V_78 ] . V_70 = V_54 ;
}
static void F_35 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_48 * V_49 ;
struct V_46 * V_47 ;
struct V_40 * V_41 ;
struct V_44 * V_45 ;
unsigned int V_79 ;
T_1 V_26 , V_75 , V_80 , V_81 , V_82 ;
switch ( V_4 -> V_11 ) {
case V_83 :
V_26 = V_4 -> V_29 . V_84 . V_26 ;
V_75 = V_4 -> V_29 . V_84 . V_75 ;
V_80 = V_4 -> V_29 . V_84 . V_85 ;
V_81 = V_4 -> V_29 . V_84 . V_86 ;
V_82 = V_4 -> V_29 . V_84 . V_82 ;
break;
case V_87 :
V_26 = V_4 -> V_29 . V_88 . V_26 ;
V_75 = V_4 -> V_29 . V_88 . V_89 [ 0 ] ;
V_80 = V_4 -> V_29 . V_88 . V_89 [ 2 ] ;
V_81 = V_4 -> V_29 . V_88 . V_89 [ 3 ] ;
V_82 = V_4 -> V_29 . V_88 . V_89 [ 1 ] ;
break;
case V_90 :
V_26 = V_4 -> V_29 . V_91 . V_26 ;
V_75 = V_4 -> V_29 . V_91 . V_75 ;
V_80 = V_4 -> V_29 . V_91 . V_85 ;
V_81 = V_4 -> V_29 . V_91 . V_86 ;
V_82 = 0 ;
break;
default:
F_7 ( V_2 -> V_6 -> V_2 . V_23 , L_8 ,
V_4 -> V_11 ) ;
return;
}
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_45 = V_2 -> V_51 [ V_26 ] ;
V_41 = & V_45 -> V_52 -> V_41 ;
if ( V_75 & V_92 ) {
F_32 ( V_45 ) ;
return;
}
V_47 = F_16 ( V_45 -> V_52 , & V_49 ) ;
if ( ! V_47 ) {
V_41 -> V_93 ++ ;
return;
}
V_79 = V_45 -> V_55 . V_57 ;
F_36 ( V_45 -> V_52 , L_9 , V_75 ) ;
if ( V_75 & V_94 ) {
V_49 -> V_59 |= V_95 ;
V_45 -> V_55 . V_64 . V_96 ++ ;
if ( ! V_45 -> V_55 . V_56 )
F_25 ( V_45 , V_97 ) ;
F_37 ( V_45 -> V_52 ) ;
V_79 = V_58 ;
} else if ( V_75 & V_98 ) {
if ( V_45 -> V_55 . V_57 != V_99 ) {
V_49 -> V_59 |= V_100 ;
if ( V_80 || V_81 )
V_49 -> V_89 [ 1 ] = ( V_80 > V_81 )
? V_101
: V_102 ;
else
V_49 -> V_89 [ 1 ] = V_101 |
V_102 ;
V_45 -> V_55 . V_64 . V_103 ++ ;
}
V_79 = V_99 ;
}
if ( V_75 == V_104 ) {
if ( ( V_45 -> V_55 . V_57 < V_105 ) &&
( ( V_80 >= 96 ) || ( V_81 >= 96 ) ) ) {
V_49 -> V_59 |= V_100 ;
V_49 -> V_89 [ 1 ] = ( V_80 > V_81 )
? V_106
: V_107 ;
V_45 -> V_55 . V_64 . V_108 ++ ;
V_79 = V_105 ;
} else if ( V_45 -> V_55 . V_57 > V_66 ) {
V_49 -> V_59 |= V_109 ;
V_49 -> V_89 [ 2 ] = V_110 ;
V_79 = V_66 ;
}
}
if ( ! V_75 ) {
V_49 -> V_59 |= V_109 ;
V_49 -> V_89 [ 2 ] = V_110 ;
V_79 = V_66 ;
}
if ( V_45 -> V_55 . V_56 &&
( V_45 -> V_55 . V_57 >= V_58 ) &&
( V_79 < V_58 ) ) {
V_49 -> V_59 |= V_60 ;
F_19 ( V_45 -> V_52 ) ;
V_45 -> V_55 . V_64 . V_65 ++ ;
}
if ( V_82 ) {
V_45 -> V_55 . V_64 . V_111 ++ ;
V_41 -> V_112 ++ ;
V_49 -> V_59 |= V_113 | V_109 ;
if ( V_82 & V_114 )
V_49 -> V_89 [ 3 ] |= ( V_115 ) ;
if ( V_82 & V_116 )
V_49 -> V_89 [ 3 ] |= ( V_117 |
V_118 ) ;
if ( V_82 & V_119 )
V_49 -> V_89 [ 2 ] |= V_120 ;
if ( V_82 & V_121 )
V_49 -> V_89 [ 2 ] |= V_122 ;
if ( V_82 & V_123 )
V_49 -> V_89 [ 2 ] |= V_124 ;
if ( V_82 & V_125 )
V_49 -> V_89 [ 2 ] |= V_126 ;
if ( V_82 & V_127 )
V_49 -> V_89 [ 2 ] |= V_128 ;
}
V_49 -> V_89 [ 6 ] = V_80 ;
V_49 -> V_89 [ 7 ] = V_81 ;
V_45 -> V_129 . V_80 = V_80 ;
V_45 -> V_129 . V_81 = V_81 ;
V_45 -> V_55 . V_57 = V_79 ;
F_17 ( V_47 ) ;
V_41 -> V_61 ++ ;
V_41 -> V_62 += V_49 -> V_63 ;
}
static void F_38 ( const struct V_44 * V_45 ,
const struct V_3 * V_4 )
{
struct V_48 * V_49 ;
struct V_46 * V_47 ;
struct V_40 * V_41 = & V_45 -> V_52 -> V_41 ;
if ( V_4 -> V_29 . V_130 . V_131 & ( V_132 |
V_133 ) ) {
F_18 ( V_45 -> V_52 , L_10 ,
V_4 -> V_29 . V_130 . V_131 ) ;
V_41 -> V_112 ++ ;
return;
}
if ( V_4 -> V_29 . V_130 . V_131 & V_134 ) {
V_47 = F_16 ( V_45 -> V_52 , & V_49 ) ;
if ( ! V_47 ) {
V_41 -> V_93 ++ ;
return;
}
V_49 -> V_59 |= V_100 ;
V_49 -> V_89 [ 1 ] = V_135 ;
V_41 -> V_136 ++ ;
V_41 -> V_112 ++ ;
F_17 ( V_47 ) ;
V_41 -> V_61 ++ ;
V_41 -> V_62 += V_49 -> V_63 ;
}
}
static void F_39 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_44 * V_45 ;
struct V_48 * V_49 ;
struct V_46 * V_47 ;
struct V_40 * V_41 ;
T_1 V_26 = V_4 -> V_29 . V_130 . V_26 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_45 = V_2 -> V_51 [ V_26 ] ;
V_41 = & V_45 -> V_52 -> V_41 ;
if ( V_4 -> V_29 . V_130 . V_131 & ( V_132 | V_133 |
V_134 ) ) {
F_38 ( V_45 , V_4 ) ;
return;
} else if ( V_4 -> V_29 . V_130 . V_131 & ~ V_137 ) {
F_24 ( V_45 -> V_52 ,
L_11 ,
V_4 -> V_29 . V_130 . V_131 ) ;
return;
}
V_47 = F_40 ( V_45 -> V_52 , & V_49 ) ;
if ( ! V_47 ) {
V_41 -> V_138 ++ ;
return;
}
V_49 -> V_59 = ( ( V_4 -> V_29 . V_130 . V_4 [ 0 ] & 0x1f ) << 6 ) |
( V_4 -> V_29 . V_130 . V_4 [ 1 ] & 0x3f ) ;
V_49 -> V_63 = F_41 ( V_4 -> V_29 . V_130 . V_4 [ 5 ] ) ;
if ( V_4 -> V_11 == V_139 ) {
V_49 -> V_59 <<= 18 ;
V_49 -> V_59 |= ( ( V_4 -> V_29 . V_130 . V_4 [ 2 ] & 0x0f ) << 14 ) |
( ( V_4 -> V_29 . V_130 . V_4 [ 3 ] & 0xff ) << 6 ) |
( V_4 -> V_29 . V_130 . V_4 [ 4 ] & 0x3f ) ;
V_49 -> V_59 |= V_140 ;
}
if ( V_4 -> V_29 . V_130 . V_131 & V_137 )
V_49 -> V_59 |= V_141 ;
else
memcpy ( V_49 -> V_89 , & V_4 -> V_29 . V_130 . V_4 [ 6 ] , V_49 -> V_63 ) ;
F_17 ( V_47 ) ;
V_41 -> V_61 ++ ;
V_41 -> V_62 += V_49 -> V_63 ;
}
static void F_42 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_44 * V_45 ;
T_1 V_26 = V_4 -> V_29 . V_30 . V_26 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_45 = V_2 -> V_51 [ V_26 ] ;
if ( F_43 ( & V_45 -> V_142 ) &&
F_44 ( V_45 -> V_52 ) ) {
F_22 ( V_45 -> V_52 ) ;
} else {
F_45 ( V_45 -> V_52 ) ;
F_46 ( & V_45 -> V_142 ) ;
}
}
static void F_47 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_44 * V_45 ;
T_1 V_26 = V_4 -> V_29 . V_30 . V_26 ;
if ( V_26 >= V_2 -> V_38 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_2 , V_26 ) ;
return;
}
V_45 = V_2 -> V_51 [ V_26 ] ;
F_46 ( & V_45 -> V_143 ) ;
}
static void F_48 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
switch ( V_4 -> V_11 ) {
case V_144 :
F_42 ( V_2 , V_4 ) ;
break;
case V_145 :
F_47 ( V_2 , V_4 ) ;
break;
case V_146 :
case V_139 :
F_39 ( V_2 , V_4 ) ;
break;
case V_90 :
case V_83 :
F_35 ( V_2 , V_4 ) ;
break;
case V_87 :
if ( V_4 -> V_29 . V_88 . V_147 & V_132 )
F_35 ( V_2 , V_4 ) ;
break;
case V_148 :
F_14 ( V_2 , V_4 ) ;
break;
default:
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_12 , V_4 -> V_11 ) ;
break;
}
}
static void F_50 ( struct V_72 * V_72 )
{
struct V_1 * V_2 = V_72 -> V_43 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
int V_14 , V_78 ;
switch ( V_72 -> V_75 ) {
case 0 :
break;
case - V_149 :
case - V_150 :
return;
default:
F_51 ( V_2 -> V_6 -> V_2 . V_23 , L_13 ,
V_72 -> V_75 ) ;
goto V_151;
}
while ( V_15 <= V_72 -> V_152 - V_22 ) {
V_4 = V_72 -> V_74 + V_15 ;
if ( ! V_4 -> V_9 )
break;
if ( V_15 + V_4 -> V_9 > V_72 -> V_152 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 , L_1 ) ;
break;
}
F_48 ( V_2 , V_4 ) ;
V_15 += V_4 -> V_9 ;
}
V_151:
F_28 ( V_72 , V_2 -> V_6 ,
F_6 ( V_2 -> V_6 ,
V_2 -> V_19 -> V_8 ) ,
V_72 -> V_74 , V_16 ,
F_50 , V_2 ) ;
V_14 = F_30 ( V_72 , V_76 ) ;
if ( V_14 == - V_153 ) {
for ( V_78 = 0 ; V_78 < V_2 -> V_38 ; V_78 ++ ) {
if ( ! V_2 -> V_51 [ V_78 ] )
continue;
F_52 ( V_2 -> V_51 [ V_78 ] -> V_52 ) ;
}
} else if ( V_14 ) {
F_7 ( V_2 -> V_6 -> V_2 . V_23 ,
L_14 , V_14 ) ;
}
return;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_78 , V_14 = 0 ;
if ( V_2 -> V_154 )
return 0 ;
for ( V_78 = 0 ; V_78 < V_155 ; V_78 ++ ) {
struct V_72 * V_72 = NULL ;
T_1 * V_13 = NULL ;
T_2 V_156 ;
V_72 = F_26 ( 0 , V_17 ) ;
if ( ! V_72 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_5 ) ;
V_14 = - V_18 ;
break;
}
V_13 = F_54 ( V_2 -> V_6 , V_16 ,
V_17 , & V_156 ) ;
if ( ! V_13 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_6 ) ;
F_27 ( V_72 ) ;
V_14 = - V_18 ;
break;
}
F_28 ( V_72 , V_2 -> V_6 ,
F_6 ( V_2 -> V_6 ,
V_2 -> V_19 -> V_8 ) ,
V_13 , V_16 ,
F_50 ,
V_2 ) ;
V_72 -> V_157 = V_156 ;
V_72 -> V_158 |= V_159 ;
F_29 ( V_72 , & V_2 -> V_160 ) ;
V_14 = F_30 ( V_72 , V_17 ) ;
if ( V_14 ) {
F_31 ( V_72 ) ;
F_55 ( V_2 -> V_6 , V_16 , V_13 ,
V_156 ) ;
F_27 ( V_72 ) ;
break;
}
V_2 -> V_161 [ V_78 ] = V_13 ;
V_2 -> V_162 [ V_78 ] = V_156 ;
F_27 ( V_72 ) ;
}
if ( V_78 == 0 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_15 , V_14 ) ;
return V_14 ;
} else if ( V_78 < V_155 ) {
F_49 ( V_2 -> V_6 -> V_2 . V_23 ,
L_16 ) ;
}
V_2 -> V_154 = true ;
return 0 ;
}
static int F_56 ( const struct V_44 * V_45 )
{
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_11 = V_163 ;
V_4 -> V_9 = V_22 + sizeof( struct V_164 ) ;
V_4 -> V_29 . V_165 . V_31 = 0xff ;
V_4 -> V_29 . V_165 . V_26 = V_45 -> V_26 ;
if ( V_45 -> V_55 . V_166 & V_167 )
V_4 -> V_29 . V_165 . V_165 = V_168 ;
else
V_4 -> V_29 . V_165 . V_165 = V_169 ;
V_27 = F_1 ( V_45 -> V_2 , V_4 ) ;
F_8 ( V_4 ) ;
return V_27 ;
}
static int F_57 ( struct V_44 * V_45 )
{
int V_14 ;
F_58 ( & V_45 -> V_142 ) ;
V_14 = F_9 ( V_45 -> V_2 , V_170 ,
V_45 -> V_26 ) ;
if ( V_14 )
return V_14 ;
if ( ! F_59 ( & V_45 -> V_142 ,
F_60 ( V_171 ) ) )
return - V_172 ;
return 0 ;
}
static int F_61 ( struct V_73 * V_52 )
{
struct V_44 * V_45 = F_62 ( V_52 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
int V_14 ;
V_14 = F_63 ( V_52 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_53 ( V_2 ) ;
if ( V_14 )
goto error;
V_14 = F_56 ( V_45 ) ;
if ( V_14 )
goto error;
V_14 = F_57 ( V_45 ) ;
if ( V_14 ) {
F_24 ( V_52 , L_17 , V_14 ) ;
goto error;
}
V_45 -> V_55 . V_57 = V_66 ;
return 0 ;
error:
F_64 ( V_52 ) ;
return V_14 ;
}
static void F_65 ( struct V_1 * V_2 )
{
int V_78 ;
F_33 ( & V_2 -> V_160 ) ;
for ( V_78 = 0 ; V_78 < V_155 ; V_78 ++ )
F_55 ( V_2 -> V_6 , V_16 ,
V_2 -> V_161 [ V_78 ] ,
V_2 -> V_162 [ V_78 ] ) ;
for ( V_78 = 0 ; V_78 < V_173 ; V_78 ++ ) {
struct V_44 * V_45 = V_2 -> V_51 [ V_78 ] ;
if ( V_45 )
F_32 ( V_45 ) ;
}
}
static int F_66 ( struct V_44 * V_45 )
{
int V_14 ;
F_58 ( & V_45 -> V_143 ) ;
V_14 = F_9 ( V_45 -> V_2 , V_97 ,
V_45 -> V_26 ) ;
if ( V_14 )
return V_14 ;
if ( ! F_59 ( & V_45 -> V_143 ,
F_60 ( V_174 ) ) )
return - V_172 ;
return 0 ;
}
static int F_67 ( struct V_44 * V_45 )
{
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_11 = V_175 ;
V_4 -> V_9 = V_22 + sizeof( struct V_176 ) ;
V_4 -> V_29 . V_177 . V_26 = V_45 -> V_26 ;
V_4 -> V_29 . V_177 . V_147 = 0x00 ;
V_27 = F_1 ( V_45 -> V_2 , V_4 ) ;
F_8 ( V_4 ) ;
return V_27 ;
}
static int F_68 ( struct V_73 * V_52 )
{
struct V_44 * V_45 = F_62 ( V_52 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
int V_14 ;
F_69 ( V_52 ) ;
V_14 = F_67 ( V_45 ) ;
if ( V_14 )
F_24 ( V_52 , L_18 , V_14 ) ;
if ( F_9 ( V_2 , V_178 , V_45 -> V_26 ) )
F_24 ( V_52 , L_19 , V_14 ) ;
V_14 = F_66 ( V_45 ) ;
if ( V_14 )
F_24 ( V_52 , L_20 , V_14 ) ;
V_45 -> V_55 . V_57 = V_179 ;
F_64 ( V_45 -> V_52 ) ;
return 0 ;
}
static void F_70 ( struct V_72 * V_72 )
{
struct V_42 * V_43 = V_72 -> V_43 ;
struct V_44 * V_45 ;
struct V_73 * V_52 ;
if ( F_71 ( ! V_43 ) )
return;
V_45 = V_43 -> V_45 ;
V_52 = V_45 -> V_52 ;
F_8 ( V_72 -> V_74 ) ;
if ( ! F_15 ( V_52 ) )
return;
if ( V_72 -> V_75 )
F_72 ( V_52 , L_21 , V_72 -> V_75 ) ;
}
static T_3 F_73 ( struct V_46 * V_47 ,
struct V_73 * V_52 )
{
struct V_44 * V_45 = F_62 ( V_52 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_40 * V_41 = & V_52 -> V_41 ;
struct V_48 * V_49 = (struct V_48 * ) V_47 -> V_89 ;
struct V_42 * V_43 = NULL ;
struct V_72 * V_72 ;
void * V_13 ;
struct V_3 * V_4 ;
int V_78 , V_14 ;
int V_180 = V_181 ;
if ( F_74 ( V_52 , V_47 ) )
return V_181 ;
V_72 = F_26 ( 0 , V_76 ) ;
if ( ! V_72 ) {
F_18 ( V_52 , L_5 ) ;
V_41 -> V_138 ++ ;
goto V_182;
}
V_13 = F_10 ( sizeof( struct V_3 ) , V_76 ) ;
if ( ! V_13 ) {
F_18 ( V_52 , L_6 ) ;
V_41 -> V_138 ++ ;
goto V_183;
}
V_4 = V_13 ;
V_4 -> V_9 = V_22 + sizeof( struct V_184 ) ;
V_4 -> V_29 . V_185 . V_147 = 0 ;
V_4 -> V_29 . V_185 . V_26 = V_45 -> V_26 ;
if ( V_49 -> V_59 & V_140 ) {
V_4 -> V_11 = V_186 ;
V_4 -> V_29 . V_185 . V_4 [ 0 ] = ( V_49 -> V_59 >> 24 ) & 0x1f ;
V_4 -> V_29 . V_185 . V_4 [ 1 ] = ( V_49 -> V_59 >> 18 ) & 0x3f ;
V_4 -> V_29 . V_185 . V_4 [ 2 ] = ( V_49 -> V_59 >> 14 ) & 0x0f ;
V_4 -> V_29 . V_185 . V_4 [ 3 ] = ( V_49 -> V_59 >> 6 ) & 0xff ;
V_4 -> V_29 . V_185 . V_4 [ 4 ] = V_49 -> V_59 & 0x3f ;
} else {
V_4 -> V_11 = V_187 ;
V_4 -> V_29 . V_185 . V_4 [ 0 ] = ( V_49 -> V_59 >> 6 ) & 0x1f ;
V_4 -> V_29 . V_185 . V_4 [ 1 ] = V_49 -> V_59 & 0x3f ;
}
V_4 -> V_29 . V_185 . V_4 [ 5 ] = V_49 -> V_63 ;
memcpy ( & V_4 -> V_29 . V_185 . V_4 [ 6 ] , V_49 -> V_89 , V_49 -> V_63 ) ;
if ( V_49 -> V_59 & V_141 )
V_4 -> V_29 . V_185 . V_147 |= V_137 ;
for ( V_78 = 0 ; V_78 < F_75 ( V_45 -> V_53 ) ; V_78 ++ ) {
if ( V_45 -> V_53 [ V_78 ] . V_70 == V_54 ) {
V_43 = & V_45 -> V_53 [ V_78 ] ;
break;
}
}
if ( ! V_43 ) {
F_24 ( V_52 , L_22 ) ;
V_180 = V_188 ;
goto V_189;
}
V_43 -> V_45 = V_45 ;
V_43 -> V_70 = V_78 ;
V_43 -> V_69 = V_49 -> V_63 ;
V_4 -> V_29 . V_185 . V_31 = V_43 -> V_70 ;
F_28 ( V_72 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 ,
V_2 -> V_7 -> V_8 ) ,
V_13 , V_4 -> V_9 ,
F_70 , V_43 ) ;
F_29 ( V_72 , & V_45 -> V_77 ) ;
F_76 ( V_47 , V_52 , V_43 -> V_70 ) ;
F_77 ( & V_45 -> V_71 ) ;
if ( F_78 ( & V_45 -> V_71 ) >= V_54 )
F_69 ( V_52 ) ;
V_14 = F_30 ( V_72 , V_76 ) ;
if ( F_79 ( V_14 ) ) {
F_80 ( V_52 , V_43 -> V_70 ) ;
V_47 = NULL ;
F_21 ( & V_45 -> V_71 ) ;
F_31 ( V_72 ) ;
V_41 -> V_138 ++ ;
if ( V_14 == - V_153 )
F_52 ( V_52 ) ;
else
F_24 ( V_52 , L_23 , V_14 ) ;
goto V_189;
}
F_27 ( V_72 ) ;
return V_181 ;
V_189:
F_8 ( V_13 ) ;
V_183:
F_27 ( V_72 ) ;
V_182:
F_81 ( V_47 ) ;
return V_180 ;
}
static int F_82 ( struct V_73 * V_52 )
{
struct V_44 * V_45 = F_62 ( V_52 ) ;
struct V_190 * V_191 = & V_45 -> V_55 . V_192 ;
struct V_1 * V_2 = V_45 -> V_2 ;
struct V_3 * V_4 ;
int V_27 ;
V_4 = F_10 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_11 = V_193 ;
V_4 -> V_9 = V_22 + sizeof( struct V_194 ) ;
V_4 -> V_29 . V_195 . V_26 = V_45 -> V_26 ;
V_4 -> V_29 . V_195 . V_31 = 0xff ;
V_4 -> V_29 . V_195 . V_196 = F_83 ( V_191 -> V_196 ) ;
V_4 -> V_29 . V_195 . V_197 = V_191 -> V_197 ;
V_4 -> V_29 . V_195 . V_198 = V_191 -> V_199 + V_191 -> V_200 ;
V_4 -> V_29 . V_195 . V_201 = V_191 -> V_202 ;
if ( V_45 -> V_55 . V_166 & V_203 )
V_4 -> V_29 . V_195 . V_204 = 3 ;
else
V_4 -> V_29 . V_195 . V_204 = 1 ;
V_27 = F_1 ( V_2 , V_4 ) ;
F_8 ( V_4 ) ;
return V_27 ;
}
static int F_84 ( struct V_73 * V_52 ,
enum V_205 V_206 )
{
struct V_44 * V_45 = F_62 ( V_52 ) ;
int V_14 ;
switch ( V_206 ) {
case V_207 :
V_14 = F_25 ( V_45 , V_170 ) ;
if ( V_14 )
return V_14 ;
break;
default:
return - V_208 ;
}
return 0 ;
}
static int F_85 ( const struct V_73 * V_52 ,
struct V_209 * V_129 )
{
struct V_44 * V_45 = F_62 ( V_52 ) ;
* V_129 = V_45 -> V_129 ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_38 ; V_78 ++ ) {
if ( ! V_2 -> V_51 [ V_78 ] )
continue;
F_87 ( V_2 -> V_51 [ V_78 ] -> V_52 ) ;
}
F_65 ( V_2 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_38 ; V_78 ++ ) {
if ( ! V_2 -> V_51 [ V_78 ] )
continue;
F_88 ( V_2 -> V_51 [ V_78 ] -> V_52 ) ;
}
}
static int F_89 ( struct V_210 * V_211 ,
const struct V_212 * V_11 , int V_26 )
{
struct V_1 * V_2 = F_90 ( V_211 ) ;
struct V_73 * V_52 ;
struct V_44 * V_45 ;
int V_78 , V_14 ;
V_52 = F_91 ( sizeof( * V_45 ) , V_54 ) ;
if ( ! V_52 ) {
F_7 ( & V_211 -> V_2 , L_24 ) ;
return - V_18 ;
}
V_45 = F_62 ( V_52 ) ;
F_58 ( & V_45 -> V_142 ) ;
F_58 ( & V_45 -> V_143 ) ;
F_92 ( & V_45 -> V_77 ) ;
F_34 ( & V_45 -> V_71 , 0 ) ;
for ( V_78 = 0 ; V_78 < F_75 ( V_45 -> V_53 ) ; V_78 ++ )
V_45 -> V_53 [ V_78 ] . V_70 = V_54 ;
V_45 -> V_2 = V_2 ;
V_45 -> V_52 = V_52 ;
V_45 -> V_26 = V_26 ;
V_45 -> V_55 . V_57 = V_179 ;
V_45 -> V_55 . clock . V_213 = V_214 ;
V_45 -> V_55 . V_215 = & V_216 ;
V_45 -> V_55 . V_217 = F_82 ;
V_45 -> V_55 . V_218 = F_84 ;
if ( V_11 -> V_219 & V_220 )
V_45 -> V_55 . V_221 = F_85 ;
V_45 -> V_55 . V_222 = V_203 ;
if ( V_11 -> V_219 & V_223 )
V_45 -> V_55 . V_222 |= V_167 ;
V_52 -> V_147 |= V_224 ;
V_52 -> V_225 = & V_226 ;
F_93 ( V_52 , & V_211 -> V_2 ) ;
V_2 -> V_51 [ V_26 ] = V_45 ;
V_14 = F_94 ( V_52 ) ;
if ( V_14 ) {
F_7 ( & V_211 -> V_2 , L_25 ) ;
F_88 ( V_52 ) ;
V_2 -> V_51 [ V_26 ] = NULL ;
return V_14 ;
}
F_36 ( V_52 , L_26 ) ;
return 0 ;
}
static void F_95 ( const struct V_210 * V_211 ,
struct V_227 * * V_228 ,
struct V_227 * * V_229 )
{
const struct V_230 * V_231 ;
struct V_227 * V_232 ;
int V_78 ;
V_231 = & V_211 -> V_233 [ 0 ] ;
for ( V_78 = 0 ; V_78 < V_231 -> V_234 . V_235 ; ++ V_78 ) {
V_232 = & V_231 -> V_232 [ V_78 ] . V_234 ;
if ( F_96 ( V_232 ) )
* V_228 = V_232 ;
if ( F_97 ( V_232 ) )
* V_229 = V_232 ;
}
}
static int F_98 ( struct V_210 * V_211 ,
const struct V_212 * V_11 )
{
struct V_1 * V_2 ;
int V_14 = - V_18 ;
int V_78 ;
V_2 = F_99 ( & V_211 -> V_2 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
F_95 ( V_211 , & V_2 -> V_19 , & V_2 -> V_7 ) ;
if ( ! V_2 -> V_19 || ! V_2 -> V_7 ) {
F_7 ( & V_211 -> V_2 , L_27 ) ;
return V_14 ;
}
V_2 -> V_6 = F_100 ( V_211 ) ;
F_92 ( & V_2 -> V_160 ) ;
F_101 ( V_211 , V_2 ) ;
for ( V_78 = 0 ; V_78 < V_173 ; V_78 ++ )
F_9 ( V_2 , V_178 , V_78 ) ;
V_14 = F_11 ( V_2 ) ;
if ( V_14 ) {
F_7 ( & V_211 -> V_2 ,
L_28 , V_14 ) ;
return V_14 ;
}
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_7 ( & V_211 -> V_2 ,
L_29 , V_14 ) ;
return V_14 ;
}
F_102 ( & V_211 -> V_2 , L_30 ,
( ( V_2 -> V_34 >> 24 ) & 0xff ) ,
( ( V_2 -> V_34 >> 16 ) & 0xff ) ,
( V_2 -> V_34 & 0xffff ) ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_38 ; V_78 ++ ) {
V_14 = F_89 ( V_211 , V_11 , V_78 ) ;
if ( V_14 ) {
F_86 ( V_2 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_103 ( struct V_210 * V_211 )
{
struct V_1 * V_2 = F_90 ( V_211 ) ;
F_101 ( V_211 , NULL ) ;
if ( ! V_2 )
return;
F_86 ( V_2 ) ;
}
