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
int V_15 ;
unsigned long V_16 = V_17 + F_5 ( V_18 ) ;
V_13 = F_6 ( V_19 , V_20 ) ;
if ( ! V_13 )
return - V_21 ;
do {
V_14 = F_2 ( V_2 -> V_6 ,
F_7 ( V_2 -> V_6 ,
V_2 -> V_22 -> V_8 ) ,
V_13 , V_19 , & V_5 ,
V_18 ) ;
if ( V_14 < 0 )
goto V_23;
V_15 = 0 ;
while ( V_15 <= V_5 - V_24 ) {
V_12 = V_13 + V_15 ;
if ( ! V_12 -> V_9 )
break;
if ( V_15 + V_12 -> V_9 > V_5 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 ,
L_1 ) ;
break;
}
if ( V_12 -> V_11 == V_11 ) {
memcpy ( V_4 , V_12 , V_12 -> V_9 ) ;
goto V_23;
}
V_15 += V_12 -> V_9 ;
}
} while ( F_9 ( V_17 , V_16 ) );
V_14 = - V_26 ;
V_23:
F_10 ( V_13 ) ;
return V_14 ;
}
static int F_11 ( const struct V_1 * V_2 ,
T_1 V_27 , int V_28 )
{
struct V_3 * V_4 ;
int V_29 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_4 -> V_11 = V_27 ;
V_4 -> V_9 = V_24 + sizeof( struct V_30 ) ;
V_4 -> V_31 . V_32 . V_28 = V_28 ;
V_4 -> V_31 . V_32 . V_33 = 0xff ;
V_29 = F_1 ( V_2 , V_4 ) ;
F_10 ( V_4 ) ;
return V_29 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_14 ;
V_14 = F_11 ( V_2 , V_34 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_2 , V_35 , & V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_36 = F_14 ( V_4 . V_31 . V_37 . V_36 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
int V_14 ;
V_14 = F_11 ( V_2 , V_38 , 0 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_2 , V_39 , & V_4 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_40 = V_4 . V_31 . V_41 . V_40 ;
if ( V_2 -> V_40 > V_42 )
return - V_26 ;
return 0 ;
}
static void F_16 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_1 V_28 = V_4 -> V_31 . V_53 . V_28 ;
T_1 V_33 = V_4 -> V_31 . V_53 . V_33 ;
if ( V_28 >= V_2 -> V_40 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 ,
L_2 , V_28 ) ;
return;
}
V_48 = V_2 -> V_54 [ V_28 ] ;
if ( ! F_17 ( V_48 -> V_55 ) )
return;
V_44 = & V_48 -> V_55 -> V_44 ;
V_46 = & V_48 -> V_56 [ V_33 % V_57 ] ;
if ( V_48 -> V_58 . V_59 &&
( V_48 -> V_58 . V_60 >= V_61 ) ) {
V_50 = F_18 ( V_48 -> V_55 , & V_52 ) ;
if ( V_50 ) {
V_52 -> V_62 |= V_63 ;
F_19 ( V_50 ) ;
V_44 -> V_64 ++ ;
V_44 -> V_65 += V_52 -> V_66 ;
} else {
F_20 ( V_48 -> V_55 ,
L_3 ) ;
}
V_48 -> V_58 . V_67 . V_68 ++ ;
F_21 ( V_48 -> V_55 ) ;
V_48 -> V_58 . V_60 = V_69 ;
}
V_44 -> V_70 ++ ;
V_44 -> V_71 += V_46 -> V_72 ;
F_22 ( V_48 -> V_55 , V_46 -> V_73 ) ;
V_46 -> V_73 = V_57 ;
F_23 ( & V_48 -> V_74 ) ;
F_24 ( V_48 -> V_55 ) ;
}
static void F_25 ( struct V_75 * V_75 )
{
struct V_76 * V_55 = V_75 -> V_46 ;
F_10 ( V_75 -> V_77 ) ;
if ( V_75 -> V_78 )
F_26 ( V_55 , L_4 ,
V_75 -> V_78 ) ;
}
static int F_27 ( struct V_47 * V_48 ,
T_1 V_27 )
{
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_76 * V_55 = V_48 -> V_55 ;
struct V_3 * V_4 ;
struct V_75 * V_75 ;
void * V_13 ;
int V_14 ;
V_75 = F_28 ( 0 , V_79 ) ;
if ( ! V_75 ) {
F_20 ( V_55 , L_5 ) ;
return - V_21 ;
}
V_13 = F_12 ( sizeof( struct V_3 ) , V_79 ) ;
if ( ! V_13 ) {
F_29 ( V_75 ) ;
return - V_21 ;
}
V_4 = (struct V_3 * ) V_13 ;
V_4 -> V_9 = V_24 + sizeof( struct V_30 ) ;
V_4 -> V_11 = V_27 ;
V_4 -> V_31 . V_32 . V_28 = V_48 -> V_28 ;
F_30 ( V_75 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 ,
V_2 -> V_7 -> V_8 ) ,
V_13 , V_4 -> V_9 ,
F_25 , V_48 ) ;
F_31 ( V_75 , & V_48 -> V_80 ) ;
V_14 = F_32 ( V_75 , V_79 ) ;
if ( V_14 ) {
F_20 ( V_55 , L_6 ) ;
F_33 ( V_75 ) ;
F_29 ( V_75 ) ;
F_10 ( V_13 ) ;
return V_14 ;
}
F_29 ( V_75 ) ;
return 0 ;
}
static void F_34 ( struct V_47 * V_48 )
{
int V_81 ;
F_35 ( & V_48 -> V_80 ) ;
F_36 ( & V_48 -> V_74 , 0 ) ;
for ( V_81 = 0 ; V_81 < V_57 ; V_81 ++ )
V_48 -> V_56 [ V_81 ] . V_73 = V_57 ;
}
static void F_37 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_51 * V_52 ;
struct V_49 * V_50 ;
struct V_43 * V_44 ;
struct V_47 * V_48 ;
unsigned int V_82 ;
T_1 V_28 , V_78 , V_83 , V_84 , V_85 ;
switch ( V_4 -> V_11 ) {
case V_86 :
V_28 = V_4 -> V_31 . V_87 . V_28 ;
V_78 = V_4 -> V_31 . V_87 . V_78 ;
V_83 = V_4 -> V_31 . V_87 . V_88 ;
V_84 = V_4 -> V_31 . V_87 . V_89 ;
V_85 = V_4 -> V_31 . V_87 . V_85 ;
break;
case V_90 :
V_28 = V_4 -> V_31 . V_91 . V_28 ;
V_78 = V_4 -> V_31 . V_91 . V_92 [ 0 ] ;
V_83 = V_4 -> V_31 . V_91 . V_92 [ 2 ] ;
V_84 = V_4 -> V_31 . V_91 . V_92 [ 3 ] ;
V_85 = V_4 -> V_31 . V_91 . V_92 [ 1 ] ;
break;
case V_93 :
V_28 = V_4 -> V_31 . V_94 . V_28 ;
V_78 = V_4 -> V_31 . V_94 . V_78 ;
V_83 = V_4 -> V_31 . V_94 . V_88 ;
V_84 = V_4 -> V_31 . V_94 . V_89 ;
V_85 = 0 ;
break;
default:
F_8 ( V_2 -> V_6 -> V_2 . V_25 , L_7 ,
V_4 -> V_11 ) ;
return;
}
if ( V_28 >= V_2 -> V_40 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 ,
L_2 , V_28 ) ;
return;
}
V_48 = V_2 -> V_54 [ V_28 ] ;
V_44 = & V_48 -> V_55 -> V_44 ;
if ( V_78 & V_95 ) {
F_34 ( V_48 ) ;
return;
}
V_50 = F_18 ( V_48 -> V_55 , & V_52 ) ;
if ( ! V_50 ) {
V_44 -> V_96 ++ ;
return;
}
V_82 = V_48 -> V_58 . V_60 ;
F_38 ( V_48 -> V_55 , L_8 , V_78 ) ;
if ( V_78 & V_97 ) {
V_52 -> V_62 |= V_98 ;
V_48 -> V_58 . V_67 . V_99 ++ ;
if ( ! V_48 -> V_58 . V_59 )
F_27 ( V_48 , V_100 ) ;
F_39 ( V_48 -> V_55 ) ;
V_82 = V_61 ;
} else if ( V_78 & V_101 ) {
if ( V_48 -> V_58 . V_60 != V_102 ) {
V_52 -> V_62 |= V_103 ;
if ( V_83 || V_84 )
V_52 -> V_92 [ 1 ] = ( V_83 > V_84 )
? V_104
: V_105 ;
else
V_52 -> V_92 [ 1 ] = V_104 |
V_105 ;
V_48 -> V_58 . V_67 . V_106 ++ ;
}
V_82 = V_102 ;
}
if ( V_78 == V_107 ) {
if ( ( V_48 -> V_58 . V_60 < V_108 ) &&
( ( V_83 >= 96 ) || ( V_84 >= 96 ) ) ) {
V_52 -> V_62 |= V_103 ;
V_52 -> V_92 [ 1 ] = ( V_83 > V_84 )
? V_109
: V_110 ;
V_48 -> V_58 . V_67 . V_111 ++ ;
V_82 = V_108 ;
} else if ( V_48 -> V_58 . V_60 > V_69 ) {
V_52 -> V_62 |= V_112 ;
V_52 -> V_92 [ 2 ] = V_113 ;
V_82 = V_69 ;
}
}
if ( ! V_78 ) {
V_52 -> V_62 |= V_112 ;
V_52 -> V_92 [ 2 ] = V_113 ;
V_82 = V_69 ;
}
if ( V_48 -> V_58 . V_59 &&
( V_48 -> V_58 . V_60 >= V_61 ) &&
( V_82 < V_61 ) ) {
V_52 -> V_62 |= V_63 ;
F_21 ( V_48 -> V_55 ) ;
V_48 -> V_58 . V_67 . V_68 ++ ;
}
if ( V_85 ) {
V_48 -> V_58 . V_67 . V_114 ++ ;
V_44 -> V_115 ++ ;
V_52 -> V_62 |= V_116 | V_112 ;
if ( V_85 & V_117 )
V_52 -> V_92 [ 3 ] |= ( V_118 ) ;
if ( V_85 & V_119 )
V_52 -> V_92 [ 3 ] |= ( V_120 |
V_121 ) ;
if ( V_85 & V_122 )
V_52 -> V_92 [ 2 ] |= V_123 ;
if ( V_85 & V_124 )
V_52 -> V_92 [ 2 ] |= V_125 ;
if ( V_85 & V_126 )
V_52 -> V_92 [ 2 ] |= V_127 ;
if ( V_85 & V_128 )
V_52 -> V_92 [ 2 ] |= V_129 ;
if ( V_85 & V_130 )
V_52 -> V_92 [ 2 ] |= V_131 ;
}
V_52 -> V_92 [ 6 ] = V_83 ;
V_52 -> V_92 [ 7 ] = V_84 ;
V_48 -> V_132 . V_83 = V_83 ;
V_48 -> V_132 . V_84 = V_84 ;
V_48 -> V_58 . V_60 = V_82 ;
F_19 ( V_50 ) ;
V_44 -> V_64 ++ ;
V_44 -> V_65 += V_52 -> V_66 ;
}
static void F_40 ( const struct V_47 * V_48 ,
const struct V_3 * V_4 )
{
struct V_51 * V_52 ;
struct V_49 * V_50 ;
struct V_43 * V_44 = & V_48 -> V_55 -> V_44 ;
if ( V_4 -> V_31 . V_133 . V_134 & ( V_135 |
V_136 ) ) {
F_20 ( V_48 -> V_55 , L_9 ,
V_4 -> V_31 . V_133 . V_134 ) ;
V_44 -> V_115 ++ ;
return;
}
if ( V_4 -> V_31 . V_133 . V_134 & V_137 ) {
V_50 = F_18 ( V_48 -> V_55 , & V_52 ) ;
if ( ! V_50 ) {
V_44 -> V_96 ++ ;
return;
}
V_52 -> V_62 |= V_103 ;
V_52 -> V_92 [ 1 ] = V_138 ;
V_44 -> V_139 ++ ;
V_44 -> V_115 ++ ;
F_19 ( V_50 ) ;
V_44 -> V_64 ++ ;
V_44 -> V_65 += V_52 -> V_66 ;
}
}
static void F_41 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_47 * V_48 ;
struct V_51 * V_52 ;
struct V_49 * V_50 ;
struct V_43 * V_44 ;
T_1 V_28 = V_4 -> V_31 . V_133 . V_28 ;
if ( V_28 >= V_2 -> V_40 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 ,
L_2 , V_28 ) ;
return;
}
V_48 = V_2 -> V_54 [ V_28 ] ;
V_44 = & V_48 -> V_55 -> V_44 ;
if ( ( V_4 -> V_31 . V_133 . V_134 & V_135 ) &&
( V_4 -> V_11 == V_90 ) ) {
F_37 ( V_2 , V_4 ) ;
return;
} else if ( V_4 -> V_31 . V_133 . V_134 & ( V_135 |
V_136 |
V_137 ) ) {
F_40 ( V_48 , V_4 ) ;
return;
} else if ( V_4 -> V_31 . V_133 . V_134 & ~ V_140 ) {
F_26 ( V_48 -> V_55 ,
L_10 ,
V_4 -> V_31 . V_133 . V_134 ) ;
return;
}
V_50 = F_42 ( V_48 -> V_55 , & V_52 ) ;
if ( ! V_50 ) {
V_44 -> V_141 ++ ;
return;
}
if ( V_4 -> V_11 == V_90 ) {
V_52 -> V_62 = F_14 ( V_4 -> V_31 . V_91 . V_11 ) ;
if ( V_52 -> V_62 & V_142 )
V_52 -> V_62 &= V_143 | V_144 ;
else
V_52 -> V_62 &= V_145 ;
V_52 -> V_66 = F_43 ( V_4 -> V_31 . V_91 . V_72 ) ;
if ( V_4 -> V_31 . V_91 . V_146 & V_140 )
V_52 -> V_62 |= V_147 ;
else
memcpy ( V_52 -> V_92 , & V_4 -> V_31 . V_91 . V_92 ,
V_52 -> V_66 ) ;
} else {
V_52 -> V_62 = ( ( V_4 -> V_31 . V_133 . V_4 [ 0 ] & 0x1f ) << 6 ) |
( V_4 -> V_31 . V_133 . V_4 [ 1 ] & 0x3f ) ;
if ( V_4 -> V_11 == V_148 ) {
V_52 -> V_62 <<= 18 ;
V_52 -> V_62 |= ( ( V_4 -> V_31 . V_133 . V_4 [ 2 ] & 0x0f ) << 14 ) |
( ( V_4 -> V_31 . V_133 . V_4 [ 3 ] & 0xff ) << 6 ) |
( V_4 -> V_31 . V_133 . V_4 [ 4 ] & 0x3f ) ;
V_52 -> V_62 |= V_144 ;
}
V_52 -> V_66 = F_43 ( V_4 -> V_31 . V_133 . V_4 [ 5 ] ) ;
if ( V_4 -> V_31 . V_133 . V_134 & V_140 )
V_52 -> V_62 |= V_147 ;
else
memcpy ( V_52 -> V_92 , & V_4 -> V_31 . V_133 . V_4 [ 6 ] ,
V_52 -> V_66 ) ;
}
F_19 ( V_50 ) ;
V_44 -> V_64 ++ ;
V_44 -> V_65 += V_52 -> V_66 ;
}
static void F_44 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_47 * V_48 ;
T_1 V_28 = V_4 -> V_31 . V_32 . V_28 ;
if ( V_28 >= V_2 -> V_40 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 ,
L_2 , V_28 ) ;
return;
}
V_48 = V_2 -> V_54 [ V_28 ] ;
if ( F_45 ( & V_48 -> V_149 ) &&
F_46 ( V_48 -> V_55 ) ) {
F_24 ( V_48 -> V_55 ) ;
} else {
F_47 ( V_48 -> V_55 ) ;
F_48 ( & V_48 -> V_149 ) ;
}
}
static void F_49 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_47 * V_48 ;
T_1 V_28 = V_4 -> V_31 . V_32 . V_28 ;
if ( V_28 >= V_2 -> V_40 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 ,
L_2 , V_28 ) ;
return;
}
V_48 = V_2 -> V_54 [ V_28 ] ;
F_48 ( & V_48 -> V_150 ) ;
}
static void F_50 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
switch ( V_4 -> V_11 ) {
case V_151 :
F_44 ( V_2 , V_4 ) ;
break;
case V_152 :
F_49 ( V_2 , V_4 ) ;
break;
case V_153 :
case V_148 :
case V_90 :
F_41 ( V_2 , V_4 ) ;
break;
case V_93 :
case V_86 :
F_37 ( V_2 , V_4 ) ;
break;
case V_154 :
F_16 ( V_2 , V_4 ) ;
break;
default:
F_51 ( V_2 -> V_6 -> V_2 . V_25 ,
L_11 , V_4 -> V_11 ) ;
break;
}
}
static void F_52 ( struct V_75 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_46 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
int V_14 , V_81 ;
switch ( V_75 -> V_78 ) {
case 0 :
break;
case - V_155 :
case - V_156 :
return;
default:
F_53 ( V_2 -> V_6 -> V_2 . V_25 , L_12 ,
V_75 -> V_78 ) ;
goto V_157;
}
while ( V_15 <= V_75 -> V_158 - V_24 ) {
V_4 = V_75 -> V_77 + V_15 ;
if ( ! V_4 -> V_9 )
break;
if ( V_15 + V_4 -> V_9 > V_75 -> V_158 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 , L_1 ) ;
break;
}
F_50 ( V_2 , V_4 ) ;
V_15 += V_4 -> V_9 ;
}
V_157:
F_30 ( V_75 , V_2 -> V_6 ,
F_7 ( V_2 -> V_6 ,
V_2 -> V_22 -> V_8 ) ,
V_75 -> V_77 , V_19 ,
F_52 , V_2 ) ;
V_14 = F_32 ( V_75 , V_79 ) ;
if ( V_14 == - V_159 ) {
for ( V_81 = 0 ; V_81 < V_2 -> V_40 ; V_81 ++ ) {
if ( ! V_2 -> V_54 [ V_81 ] )
continue;
F_54 ( V_2 -> V_54 [ V_81 ] -> V_55 ) ;
}
} else if ( V_14 ) {
F_8 ( V_2 -> V_6 -> V_2 . V_25 ,
L_13 , V_14 ) ;
}
return;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_81 , V_14 = 0 ;
if ( V_2 -> V_160 )
return 0 ;
for ( V_81 = 0 ; V_81 < V_161 ; V_81 ++ ) {
struct V_75 * V_75 = NULL ;
T_1 * V_13 = NULL ;
T_2 V_162 ;
V_75 = F_28 ( 0 , V_20 ) ;
if ( ! V_75 ) {
F_51 ( V_2 -> V_6 -> V_2 . V_25 ,
L_5 ) ;
V_14 = - V_21 ;
break;
}
V_13 = F_56 ( V_2 -> V_6 , V_19 ,
V_20 , & V_162 ) ;
if ( ! V_13 ) {
F_51 ( V_2 -> V_6 -> V_2 . V_25 ,
L_14 ) ;
F_29 ( V_75 ) ;
V_14 = - V_21 ;
break;
}
F_30 ( V_75 , V_2 -> V_6 ,
F_7 ( V_2 -> V_6 ,
V_2 -> V_22 -> V_8 ) ,
V_13 , V_19 ,
F_52 ,
V_2 ) ;
V_75 -> V_163 = V_162 ;
V_75 -> V_164 |= V_165 ;
F_31 ( V_75 , & V_2 -> V_166 ) ;
V_14 = F_32 ( V_75 , V_20 ) ;
if ( V_14 ) {
F_33 ( V_75 ) ;
F_57 ( V_2 -> V_6 , V_19 , V_13 ,
V_162 ) ;
F_29 ( V_75 ) ;
break;
}
V_2 -> V_167 [ V_81 ] = V_13 ;
V_2 -> V_168 [ V_81 ] = V_162 ;
F_29 ( V_75 ) ;
}
if ( V_81 == 0 ) {
F_51 ( V_2 -> V_6 -> V_2 . V_25 ,
L_15 , V_14 ) ;
return V_14 ;
} else if ( V_81 < V_161 ) {
F_51 ( V_2 -> V_6 -> V_2 . V_25 ,
L_16 ) ;
}
V_2 -> V_160 = true ;
return 0 ;
}
static int F_58 ( const struct V_47 * V_48 )
{
struct V_3 * V_4 ;
int V_29 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_4 -> V_11 = V_169 ;
V_4 -> V_9 = V_24 + sizeof( struct V_170 ) ;
V_4 -> V_31 . V_171 . V_33 = 0xff ;
V_4 -> V_31 . V_171 . V_28 = V_48 -> V_28 ;
if ( V_48 -> V_58 . V_172 & V_173 )
V_4 -> V_31 . V_171 . V_171 = V_174 ;
else
V_4 -> V_31 . V_171 . V_171 = V_175 ;
V_29 = F_1 ( V_48 -> V_2 , V_4 ) ;
F_10 ( V_4 ) ;
return V_29 ;
}
static int F_59 ( struct V_47 * V_48 )
{
int V_14 ;
F_60 ( & V_48 -> V_149 ) ;
V_14 = F_11 ( V_48 -> V_2 , V_176 ,
V_48 -> V_28 ) ;
if ( V_14 )
return V_14 ;
if ( ! F_61 ( & V_48 -> V_149 ,
F_5 ( V_177 ) ) )
return - V_178 ;
return 0 ;
}
static int F_62 ( struct V_76 * V_55 )
{
struct V_47 * V_48 = F_63 ( V_55 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
int V_14 ;
V_14 = F_64 ( V_55 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_55 ( V_2 ) ;
if ( V_14 )
goto error;
V_14 = F_58 ( V_48 ) ;
if ( V_14 )
goto error;
V_14 = F_59 ( V_48 ) ;
if ( V_14 ) {
F_26 ( V_55 , L_17 , V_14 ) ;
goto error;
}
V_48 -> V_58 . V_60 = V_69 ;
return 0 ;
error:
F_65 ( V_55 ) ;
return V_14 ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_81 ;
F_35 ( & V_2 -> V_166 ) ;
for ( V_81 = 0 ; V_81 < V_161 ; V_81 ++ )
F_57 ( V_2 -> V_6 , V_19 ,
V_2 -> V_167 [ V_81 ] ,
V_2 -> V_168 [ V_81 ] ) ;
for ( V_81 = 0 ; V_81 < V_42 ; V_81 ++ ) {
struct V_47 * V_48 = V_2 -> V_54 [ V_81 ] ;
if ( V_48 )
F_34 ( V_48 ) ;
}
}
static int F_67 ( struct V_47 * V_48 )
{
int V_14 ;
F_60 ( & V_48 -> V_150 ) ;
V_14 = F_11 ( V_48 -> V_2 , V_100 ,
V_48 -> V_28 ) ;
if ( V_14 )
return V_14 ;
if ( ! F_61 ( & V_48 -> V_150 ,
F_5 ( V_179 ) ) )
return - V_178 ;
return 0 ;
}
static int F_68 ( struct V_47 * V_48 )
{
struct V_3 * V_4 ;
int V_29 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_4 -> V_11 = V_180 ;
V_4 -> V_9 = V_24 + sizeof( struct V_181 ) ;
V_4 -> V_31 . V_182 . V_28 = V_48 -> V_28 ;
V_4 -> V_31 . V_182 . V_146 = 0x00 ;
V_29 = F_1 ( V_48 -> V_2 , V_4 ) ;
F_10 ( V_4 ) ;
return V_29 ;
}
static int F_69 ( struct V_76 * V_55 )
{
struct V_47 * V_48 = F_63 ( V_55 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
int V_14 ;
F_70 ( V_55 ) ;
V_14 = F_68 ( V_48 ) ;
if ( V_14 )
F_26 ( V_55 , L_18 , V_14 ) ;
if ( F_11 ( V_2 , V_183 , V_48 -> V_28 ) )
F_26 ( V_55 , L_19 , V_14 ) ;
V_14 = F_67 ( V_48 ) ;
if ( V_14 )
F_26 ( V_55 , L_20 , V_14 ) ;
V_48 -> V_58 . V_60 = V_184 ;
F_65 ( V_48 -> V_55 ) ;
return 0 ;
}
static void F_71 ( struct V_75 * V_75 )
{
struct V_45 * V_46 = V_75 -> V_46 ;
struct V_47 * V_48 ;
struct V_76 * V_55 ;
if ( F_72 ( ! V_46 ) )
return;
V_48 = V_46 -> V_48 ;
V_55 = V_48 -> V_55 ;
F_10 ( V_75 -> V_77 ) ;
if ( ! F_17 ( V_55 ) )
return;
if ( V_75 -> V_78 )
F_73 ( V_55 , L_21 , V_75 -> V_78 ) ;
}
static T_3 F_74 ( struct V_49 * V_50 ,
struct V_76 * V_55 )
{
struct V_47 * V_48 = F_63 ( V_55 ) ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_43 * V_44 = & V_55 -> V_44 ;
struct V_51 * V_52 = (struct V_51 * ) V_50 -> V_92 ;
struct V_45 * V_46 = NULL ;
struct V_75 * V_75 ;
void * V_13 ;
struct V_3 * V_4 ;
int V_81 , V_14 ;
int V_185 = V_186 ;
if ( F_75 ( V_55 , V_50 ) )
return V_186 ;
V_75 = F_28 ( 0 , V_79 ) ;
if ( ! V_75 ) {
F_20 ( V_55 , L_5 ) ;
V_44 -> V_141 ++ ;
goto V_187;
}
V_13 = F_12 ( sizeof( struct V_3 ) , V_79 ) ;
if ( ! V_13 ) {
V_44 -> V_141 ++ ;
goto V_188;
}
V_4 = V_13 ;
V_4 -> V_9 = V_24 + sizeof( struct V_189 ) ;
V_4 -> V_31 . V_190 . V_146 = 0 ;
V_4 -> V_31 . V_190 . V_28 = V_48 -> V_28 ;
if ( V_52 -> V_62 & V_144 ) {
V_4 -> V_11 = V_191 ;
V_4 -> V_31 . V_190 . V_4 [ 0 ] = ( V_52 -> V_62 >> 24 ) & 0x1f ;
V_4 -> V_31 . V_190 . V_4 [ 1 ] = ( V_52 -> V_62 >> 18 ) & 0x3f ;
V_4 -> V_31 . V_190 . V_4 [ 2 ] = ( V_52 -> V_62 >> 14 ) & 0x0f ;
V_4 -> V_31 . V_190 . V_4 [ 3 ] = ( V_52 -> V_62 >> 6 ) & 0xff ;
V_4 -> V_31 . V_190 . V_4 [ 4 ] = V_52 -> V_62 & 0x3f ;
} else {
V_4 -> V_11 = V_192 ;
V_4 -> V_31 . V_190 . V_4 [ 0 ] = ( V_52 -> V_62 >> 6 ) & 0x1f ;
V_4 -> V_31 . V_190 . V_4 [ 1 ] = V_52 -> V_62 & 0x3f ;
}
V_4 -> V_31 . V_190 . V_4 [ 5 ] = V_52 -> V_66 ;
memcpy ( & V_4 -> V_31 . V_190 . V_4 [ 6 ] , V_52 -> V_92 , V_52 -> V_66 ) ;
if ( V_52 -> V_62 & V_147 )
V_4 -> V_31 . V_190 . V_146 |= V_140 ;
for ( V_81 = 0 ; V_81 < F_76 ( V_48 -> V_56 ) ; V_81 ++ ) {
if ( V_48 -> V_56 [ V_81 ] . V_73 == V_57 ) {
V_46 = & V_48 -> V_56 [ V_81 ] ;
break;
}
}
if ( ! V_46 ) {
F_26 ( V_55 , L_22 ) ;
V_185 = V_193 ;
goto V_194;
}
V_46 -> V_48 = V_48 ;
V_46 -> V_73 = V_81 ;
V_46 -> V_72 = V_52 -> V_66 ;
V_4 -> V_31 . V_190 . V_33 = V_46 -> V_73 ;
F_30 ( V_75 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 ,
V_2 -> V_7 -> V_8 ) ,
V_13 , V_4 -> V_9 ,
F_71 , V_46 ) ;
F_31 ( V_75 , & V_48 -> V_80 ) ;
F_77 ( V_50 , V_55 , V_46 -> V_73 ) ;
F_78 ( & V_48 -> V_74 ) ;
if ( F_79 ( & V_48 -> V_74 ) >= V_57 )
F_70 ( V_55 ) ;
V_14 = F_32 ( V_75 , V_79 ) ;
if ( F_80 ( V_14 ) ) {
F_81 ( V_55 , V_46 -> V_73 ) ;
V_50 = NULL ;
F_23 ( & V_48 -> V_74 ) ;
F_33 ( V_75 ) ;
V_44 -> V_141 ++ ;
if ( V_14 == - V_159 )
F_54 ( V_55 ) ;
else
F_26 ( V_55 , L_23 , V_14 ) ;
goto V_194;
}
F_29 ( V_75 ) ;
return V_186 ;
V_194:
F_10 ( V_13 ) ;
V_188:
F_29 ( V_75 ) ;
V_187:
F_82 ( V_50 ) ;
return V_185 ;
}
static int F_83 ( struct V_76 * V_55 )
{
struct V_47 * V_48 = F_63 ( V_55 ) ;
struct V_195 * V_196 = & V_48 -> V_58 . V_197 ;
struct V_1 * V_2 = V_48 -> V_2 ;
struct V_3 * V_4 ;
int V_29 ;
V_4 = F_12 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_4 -> V_11 = V_198 ;
V_4 -> V_9 = V_24 + sizeof( struct V_199 ) ;
V_4 -> V_31 . V_200 . V_28 = V_48 -> V_28 ;
V_4 -> V_31 . V_200 . V_33 = 0xff ;
V_4 -> V_31 . V_200 . V_201 = F_84 ( V_196 -> V_201 ) ;
V_4 -> V_31 . V_200 . V_202 = V_196 -> V_202 ;
V_4 -> V_31 . V_200 . V_203 = V_196 -> V_204 + V_196 -> V_205 ;
V_4 -> V_31 . V_200 . V_206 = V_196 -> V_207 ;
if ( V_48 -> V_58 . V_172 & V_208 )
V_4 -> V_31 . V_200 . V_209 = 3 ;
else
V_4 -> V_31 . V_200 . V_209 = 1 ;
V_29 = F_1 ( V_2 , V_4 ) ;
F_10 ( V_4 ) ;
return V_29 ;
}
static int F_85 ( struct V_76 * V_55 ,
enum V_210 V_211 )
{
struct V_47 * V_48 = F_63 ( V_55 ) ;
int V_14 ;
switch ( V_211 ) {
case V_212 :
V_14 = F_27 ( V_48 , V_176 ) ;
if ( V_14 )
return V_14 ;
break;
default:
return - V_213 ;
}
return 0 ;
}
static int F_86 ( const struct V_76 * V_55 ,
struct V_214 * V_132 )
{
struct V_47 * V_48 = F_63 ( V_55 ) ;
* V_132 = V_48 -> V_132 ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < V_2 -> V_40 ; V_81 ++ ) {
if ( ! V_2 -> V_54 [ V_81 ] )
continue;
F_88 ( V_2 -> V_54 [ V_81 ] -> V_55 ) ;
}
F_66 ( V_2 ) ;
for ( V_81 = 0 ; V_81 < V_2 -> V_40 ; V_81 ++ ) {
if ( ! V_2 -> V_54 [ V_81 ] )
continue;
F_89 ( V_2 -> V_54 [ V_81 ] -> V_55 ) ;
}
}
static int F_90 ( struct V_215 * V_216 ,
const struct V_217 * V_11 , int V_28 )
{
struct V_1 * V_2 = F_91 ( V_216 ) ;
struct V_76 * V_55 ;
struct V_47 * V_48 ;
int V_81 , V_14 ;
V_55 = F_92 ( sizeof( * V_48 ) , V_57 ) ;
if ( ! V_55 ) {
F_8 ( & V_216 -> V_2 , L_24 ) ;
return - V_21 ;
}
V_48 = F_63 ( V_55 ) ;
F_60 ( & V_48 -> V_149 ) ;
F_60 ( & V_48 -> V_150 ) ;
F_93 ( & V_48 -> V_80 ) ;
F_36 ( & V_48 -> V_74 , 0 ) ;
for ( V_81 = 0 ; V_81 < F_76 ( V_48 -> V_56 ) ; V_81 ++ )
V_48 -> V_56 [ V_81 ] . V_73 = V_57 ;
V_48 -> V_2 = V_2 ;
V_48 -> V_55 = V_55 ;
V_48 -> V_28 = V_28 ;
V_48 -> V_58 . V_60 = V_184 ;
V_48 -> V_58 . clock . V_218 = V_219 ;
V_48 -> V_58 . V_220 = & V_221 ;
V_48 -> V_58 . V_222 = F_83 ;
V_48 -> V_58 . V_223 = F_85 ;
if ( V_11 -> V_224 & V_225 )
V_48 -> V_58 . V_226 = F_86 ;
V_48 -> V_58 . V_227 = V_208 ;
if ( V_11 -> V_224 & V_228 )
V_48 -> V_58 . V_227 |= V_173 ;
V_55 -> V_146 |= V_229 ;
V_55 -> V_230 = & V_231 ;
F_94 ( V_55 , & V_216 -> V_2 ) ;
V_55 -> V_232 = V_28 ;
V_2 -> V_54 [ V_28 ] = V_48 ;
V_14 = F_95 ( V_55 ) ;
if ( V_14 ) {
F_8 ( & V_216 -> V_2 , L_25 ) ;
F_89 ( V_55 ) ;
V_2 -> V_54 [ V_28 ] = NULL ;
return V_14 ;
}
F_38 ( V_55 , L_26 ) ;
return 0 ;
}
static int F_96 ( const struct V_215 * V_216 ,
struct V_233 * * V_234 ,
struct V_233 * * V_235 )
{
const struct V_236 * V_237 ;
struct V_233 * V_238 ;
int V_81 ;
V_237 = & V_216 -> V_239 [ 0 ] ;
for ( V_81 = 0 ; V_81 < V_237 -> V_240 . V_241 ; ++ V_81 ) {
V_238 = & V_237 -> V_238 [ V_81 ] . V_240 ;
if ( ! * V_234 && F_97 ( V_238 ) )
* V_234 = V_238 ;
if ( ! * V_235 && F_98 ( V_238 ) )
* V_235 = V_238 ;
if ( * V_234 && * V_235 )
return 0 ;
}
return - V_159 ;
}
static int F_99 ( struct V_215 * V_216 ,
const struct V_217 * V_11 )
{
struct V_1 * V_2 ;
int V_14 = - V_21 ;
int V_81 ;
V_2 = F_100 ( & V_216 -> V_2 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_14 = F_96 ( V_216 , & V_2 -> V_22 , & V_2 -> V_7 ) ;
if ( V_14 ) {
F_8 ( & V_216 -> V_2 , L_27 ) ;
return V_14 ;
}
V_2 -> V_6 = F_101 ( V_216 ) ;
F_93 ( & V_2 -> V_166 ) ;
F_102 ( V_216 , V_2 ) ;
for ( V_81 = 0 ; V_81 < V_42 ; V_81 ++ )
F_11 ( V_2 , V_183 , V_81 ) ;
V_14 = F_13 ( V_2 ) ;
if ( V_14 ) {
F_8 ( & V_216 -> V_2 ,
L_28 , V_14 ) ;
return V_14 ;
}
V_14 = F_15 ( V_2 ) ;
if ( V_14 ) {
F_8 ( & V_216 -> V_2 ,
L_29 , V_14 ) ;
return V_14 ;
}
F_103 ( & V_216 -> V_2 , L_30 ,
( ( V_2 -> V_36 >> 24 ) & 0xff ) ,
( ( V_2 -> V_36 >> 16 ) & 0xff ) ,
( V_2 -> V_36 & 0xffff ) ) ;
for ( V_81 = 0 ; V_81 < V_2 -> V_40 ; V_81 ++ ) {
V_14 = F_90 ( V_216 , V_11 , V_81 ) ;
if ( V_14 ) {
F_87 ( V_2 ) ;
return V_14 ;
}
}
return 0 ;
}
static void F_104 ( struct V_215 * V_216 )
{
struct V_1 * V_2 = F_91 ( V_216 ) ;
F_102 ( V_216 , NULL ) ;
if ( ! V_2 )
return;
F_87 ( V_2 ) ;
}
