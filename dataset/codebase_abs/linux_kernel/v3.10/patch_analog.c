static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_9 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_12 = F_5 ( V_2 , & V_11 -> V_13 ) ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_17 [ V_12 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_12 = F_5 ( V_2 , & V_11 -> V_13 ) ;
return F_7 ( V_6 , V_8 -> V_9 , V_11 ,
V_8 -> V_18 [ V_12 ] ,
& V_8 -> V_17 [ V_12 ] ) ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_20 ; V_19 ++ )
F_9 ( V_6 , V_8 -> V_21 [ V_19 ] ) ;
return 0 ;
}
static int F_10 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_22 * V_23 ;
if ( ! V_8 -> V_24 )
return 0 ;
V_23 = V_8 -> V_25 ? V_26 : V_27 ;
for ( ; V_23 -> V_28 ; V_23 ++ ) {
int V_29 ;
struct V_1 * V_30 ;
V_30 = F_11 ( V_23 , V_6 ) ;
if ( ! V_30 )
return - V_31 ;
V_30 -> V_32 = V_8 -> V_24 ;
V_29 = F_12 ( V_6 , 0 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_30 ;
unsigned int V_19 ;
int V_29 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_33 ; V_19 ++ ) {
V_29 = F_14 ( V_6 , V_8 -> V_34 [ V_19 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_8 -> V_35 . V_36 ) {
V_29 = F_15 ( V_6 ,
V_8 -> V_35 . V_36 ,
V_8 -> V_35 . V_36 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_16 ( V_6 ,
& V_8 -> V_35 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 -> V_35 . V_37 = 1 ;
}
if ( V_8 -> V_38 ) {
V_29 = F_17 ( V_6 , V_8 -> V_38 ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_29 = F_10 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! F_18 ( V_6 , L_1 ) ) {
unsigned int V_39 [ 4 ] ;
F_19 ( V_6 , V_8 -> V_40 ,
V_41 , V_39 ) ;
V_29 = F_20 ( V_6 , L_1 ,
V_39 ,
( V_8 -> V_42 ?
V_8 -> V_42 : V_43 ) ,
L_2 ,
! V_8 -> V_44 , NULL ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( ! F_18 ( V_6 , L_3 ) ) {
V_29 = F_21 ( V_6 , L_3 ,
NULL ,
( V_8 -> V_45 ?
V_8 -> V_45 : V_43 ) ,
L_4 ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_30 = F_18 ( V_6 , L_5 ) ;
if ( ! V_30 )
V_30 = F_18 ( V_6 , L_6 ) ;
for ( V_19 = 0 ; V_30 && V_19 < V_30 -> V_46 ; V_19 ++ ) {
V_29 = F_22 ( V_6 , V_30 , V_19 , V_8 -> V_18 [ V_19 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_30 = F_18 ( V_6 ,
F_23 ( L_7 , V_47 , V_48 ) L_8 ) ;
if ( V_30 ) {
V_29 = F_22 ( V_6 , V_30 , 0 ,
V_8 -> V_35 . V_36 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_24 ( struct V_5 * V_6 , T_1 V_49 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_25 ( V_6 , & V_8 -> V_50 , V_49 ) ;
}
static int F_26 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_27 ( V_6 , & V_8 -> V_35 , V_54 ,
V_52 ) ;
}
static int F_28 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
unsigned int V_55 ,
unsigned int V_56 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_29 ( V_6 , & V_8 -> V_35 , V_55 ,
V_56 , V_54 ) ;
}
static int F_30 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_31 ( V_6 , & V_8 -> V_35 ) ;
}
static int F_32 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_33 ( V_6 , & V_8 -> V_35 ) ;
}
static int F_34 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_35 ( V_6 , & V_8 -> V_35 ) ;
}
static int F_36 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
unsigned int V_55 ,
unsigned int V_56 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_37 ( V_6 , & V_8 -> V_35 , V_55 ,
V_56 , V_54 ) ;
}
static int F_38 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_39 ( V_6 , & V_8 -> V_35 ) ;
}
static int F_40 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
unsigned int V_55 ,
unsigned int V_56 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_41 ( V_6 , V_8 -> V_57 [ V_54 -> V_58 ] ,
V_55 , 0 , V_56 ) ;
return 0 ;
}
static int F_42 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_43 ( V_6 , V_8 -> V_57 [ V_54 -> V_58 ] ) ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_59 * V_60 = V_8 -> V_61 ;
V_6 -> V_62 = 1 ;
V_6 -> V_63 = V_60 ;
V_60 -> V_28 = L_9 ;
V_60 -> V_64 [ V_65 ] = V_66 ;
V_60 -> V_64 [ V_65 ] . V_67 = V_8 -> V_35 . V_68 ;
V_60 -> V_64 [ V_65 ] . V_49 = V_8 -> V_35 . V_69 [ 0 ] ;
V_60 -> V_64 [ V_70 ] = V_71 ;
V_60 -> V_64 [ V_70 ] . V_72 = V_8 -> V_73 ;
V_60 -> V_64 [ V_70 ] . V_49 = V_8 -> V_57 [ 0 ] ;
if ( V_8 -> V_35 . V_36 ) {
V_60 ++ ;
V_6 -> V_62 ++ ;
V_6 -> V_74 = 1 ;
V_60 -> V_28 = L_10 ;
V_60 -> V_75 = V_76 ;
V_60 -> V_64 [ V_65 ] = V_77 ;
V_60 -> V_64 [ V_65 ] . V_49 = V_8 -> V_35 . V_36 ;
if ( V_8 -> V_38 ) {
V_60 -> V_64 [ V_70 ] = V_78 ;
V_60 -> V_64 [ V_70 ] . V_49 = V_8 -> V_38 ;
}
}
return 0 ;
}
static void F_45 ( struct V_5 * V_6 , T_1 V_79 ,
T_1 V_80 )
{
if ( F_46 ( V_6 , V_79 ) & V_81 )
F_47 ( V_6 , V_79 , 0 , V_82 ,
! V_6 -> V_83 ? 0x00 : 0x02 ) ;
if ( F_46 ( V_6 , V_80 ) & V_81 )
F_47 ( V_6 , V_80 , 0 , V_82 ,
! V_6 -> V_83 ? 0x00 : 0x02 ) ;
}
static void F_48 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_84 ) {
case 0x11d41882 :
case 0x11d4882a :
case 0x11d41884 :
case 0x11d41984 :
case 0x11d41883 :
case 0x11d4184a :
case 0x11d4194a :
case 0x11d4194b :
case 0x11d41988 :
case 0x11d4198b :
case 0x11d4989a :
case 0x11d4989b :
F_45 ( V_6 , 0x12 , 0x11 ) ;
break;
case 0x11d41981 :
case 0x11d41983 :
F_45 ( V_6 , 0x05 , 0x06 ) ;
break;
case 0x11d41986 :
F_45 ( V_6 , 0x1b , 0x1a ) ;
break;
}
}
static void F_49 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
F_48 ( V_6 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_52 ( & V_8 -> V_85 ) ;
F_53 ( V_8 ) ;
F_54 ( V_6 ) ;
}
static int F_55 ( struct V_5 * V_6 )
{
F_49 ( V_6 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_6 -> V_83 )
V_11 -> V_14 . integer . V_14 [ 0 ] = ! V_8 -> V_86 ;
else
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_86 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_49 = V_2 -> V_32 & 0xff ;
unsigned int V_87 ;
V_87 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_6 -> V_83 )
V_87 = ! V_87 ;
if ( V_87 == V_8 -> V_86 )
return 0 ;
V_8 -> V_86 = V_87 ;
F_58 ( V_6 , V_49 ,
0 , V_82 ,
V_87 ? 0x02 : 0x00 ) ;
return 1 ;
}
static int F_59 ( struct V_5 * V_6 )
{
int V_29 ;
V_29 = F_60 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_10 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_88 * V_89 = & V_8 -> V_85 . V_90 ;
int V_29 ;
V_6 -> V_74 = 1 ;
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
V_8 -> V_85 . V_93 = 1 ;
V_29 = F_62 ( V_6 , V_89 , NULL , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_63 ( V_6 , V_89 ) ;
if ( V_29 < 0 )
return V_29 ;
V_6 -> V_94 = V_95 ;
return 0 ;
}
static void F_64 ( struct V_5 * V_6 )
{
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x1f ) ;
F_47 ( V_6 , 0x0f , 0 , V_97 ,
V_96 ? 0 : 2 ) ;
}
static void F_66 ( struct V_5 * V_6 ,
unsigned int V_98 )
{
if ( ( V_98 >> 26 ) != V_99 )
return;
F_64 ( V_6 ) ;
}
static int F_67 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_64 ( V_6 ) ;
return 0 ;
}
static void F_68 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_100 ;
if ( V_8 -> V_101 )
V_100 = V_102 ;
else
V_100 = F_69 ( V_6 , 0x1a , 0 , V_41 , 0 ) ;
F_70 ( V_6 , 0x1b , V_41 , 0 ,
V_102 , V_100 ) ;
}
static void F_71 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_101 = F_65 ( V_6 , 0x1a ) ;
if ( V_8 -> V_103 )
V_8 -> V_101 = ! V_8 -> V_101 ;
F_68 ( V_6 ) ;
}
static void F_72 ( struct V_5 * V_6 , unsigned int V_98 )
{
if ( ( V_98 >> 26 ) != V_104 )
return;
F_71 ( V_6 ) ;
}
static int F_73 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_71 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_105 = F_75 ( V_2 , V_11 ) ;
if ( V_105 )
F_68 ( V_6 ) ;
return V_105 ;
}
static void F_76 ( struct V_5 * V_6 ,
unsigned int V_98 )
{
switch ( V_98 >> 26 ) {
case V_104 :
F_71 ( V_6 ) ;
break;
case V_99 :
F_64 ( V_6 ) ;
break;
}
}
static int F_77 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_71 ( V_6 ) ;
F_64 ( V_6 ) ;
return 0 ;
}
static int F_78 ( struct V_5 * V_6 , T_1 V_49 )
{
unsigned int V_106 = F_79 ( V_6 , V_49 ) ;
return F_80 ( V_106 ) != V_107 ;
}
static int F_81 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
V_8 = F_82 ( sizeof( * V_8 ) , V_108 ) ;
if ( ! V_8 )
return - V_31 ;
V_6 -> V_8 = V_8 ;
F_83 ( & V_8 -> V_85 ) ;
return 0 ;
}
static void F_84 ( struct V_5 * V_6 ,
const struct V_109 * V_110 , int V_111 )
{
if ( V_111 == V_112 )
V_6 -> V_103 = 1 ;
}
static int F_85 ( struct V_5 * V_6 )
{
int V_29 ;
struct V_7 * V_8 ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_6 -> V_83 = 1 ;
V_8 -> V_85 . V_113 = 0x07 ;
V_8 -> V_85 . V_114 = 0x19 ;
F_86 ( V_8 , 0x18 , 0 , V_41 ) ;
V_8 -> V_85 . V_35 . V_115 = 1 ;
F_87 ( V_6 , NULL , V_116 , V_117 ) ;
F_88 ( V_6 , V_112 ) ;
V_29 = F_61 ( V_6 ) ;
if ( V_29 < 0 ) {
F_89 ( V_6 ) ;
return V_29 ;
}
F_88 ( V_6 , V_118 ) ;
return 0 ;
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 , V_119 ;
V_119 = F_91 ( V_6 , V_120 ,
V_121 ,
V_122 ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_125 ;
}
if ( V_119 == V_125 )
return F_85 ( V_6 ) ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_29 = F_93 ( V_6 , 0x19 ) ;
if ( V_29 < 0 ) {
F_51 ( V_6 ) ;
return V_29 ;
}
F_86 ( V_8 , 0x18 , 0 , V_41 ) ;
V_8 -> V_35 . V_68 = 6 ;
V_8 -> V_35 . V_126 = F_94 ( V_127 ) ;
V_8 -> V_35 . V_69 = V_127 ;
V_8 -> V_35 . V_36 = V_128 ;
V_8 -> V_73 = 1 ;
V_8 -> V_57 = V_129 ;
V_8 -> V_18 = V_130 ;
V_8 -> V_9 = & V_131 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 [ 0 ] = V_132 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_133 ;
#ifdef F_95
V_8 -> V_50 . V_134 = V_135 ;
#endif
V_8 -> V_40 = 0x1b ;
V_6 -> V_83 = 1 ;
V_6 -> V_94 = V_136 ;
switch ( V_119 ) {
case V_137 :
V_8 -> V_33 = 2 ;
V_8 -> V_34 [ 1 ] = V_138 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_139 ;
V_8 -> V_140 = V_141 ;
V_8 -> V_142 = F_94 ( V_141 ) ;
V_8 -> V_143 = 1 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
break;
case V_144 :
V_8 -> V_34 [ 0 ] = V_145 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
V_8 -> V_35 . V_69 = V_146 ;
break;
case V_147 :
V_8 -> V_33 = 3 ;
V_8 -> V_34 [ 0 ] = V_148 ;
V_8 -> V_34 [ 1 ] = V_149 ;
V_8 -> V_34 [ 2 ] = V_150 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_151 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
V_8 -> V_35 . V_69 = V_146 ;
if ( ! F_78 ( V_6 , 0x25 ) )
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_152 ;
break;
case V_153 :
V_8 -> V_33 = 2 ;
V_8 -> V_34 [ 0 ] = V_148 ;
V_8 -> V_34 [ 1 ] = V_149 ;
V_8 -> V_20 = 3 ;
V_8 -> V_21 [ 1 ] = V_151 ;
V_8 -> V_21 [ 2 ] = V_154 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
V_8 -> V_35 . V_69 = V_146 ;
if ( ! F_78 ( V_6 , 0x25 ) )
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_155 ;
V_6 -> V_94 . V_156 = F_66 ;
V_6 -> V_94 . V_157 = F_67 ;
break;
case V_158 :
V_8 -> V_33 = 2 ;
V_8 -> V_34 [ 0 ] = V_159 ;
V_8 -> V_34 [ 1 ] = V_149 ;
V_8 -> V_20 = 4 ;
V_8 -> V_21 [ 1 ] = V_151 ;
V_8 -> V_21 [ 2 ] = V_154 ;
V_8 -> V_21 [ 3 ] = V_160 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
V_8 -> V_35 . V_69 = V_146 ;
if ( ! F_78 ( V_6 , 0x25 ) )
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_155 ;
V_6 -> V_94 . V_156 = F_76 ;
V_6 -> V_94 . V_157 = F_77 ;
break;
case V_161 :
V_8 -> V_33 = 3 ;
V_8 -> V_34 [ 0 ] = V_159 ;
V_8 -> V_34 [ 1 ] = V_149 ;
V_8 -> V_34 [ 2 ] = V_150 ;
V_8 -> V_20 = 3 ;
V_8 -> V_21 [ 1 ] = V_151 ;
V_8 -> V_21 [ 2 ] = V_160 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
V_8 -> V_35 . V_69 = V_146 ;
if ( ! F_78 ( V_6 , 0x25 ) )
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_152 ;
V_6 -> V_94 . V_156 = F_72 ;
V_6 -> V_94 . V_157 = F_73 ;
V_8 -> V_103 = 1 ;
break;
case V_162 :
V_8 -> V_34 [ 0 ] = V_149 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_163 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
V_8 -> V_35 . V_69 = V_146 ;
V_8 -> V_35 . V_36 = 0 ;
break;
}
V_8 -> V_35 . V_115 = 1 ;
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static const char * const V_164 [] = { L_12 , L_13 } ;
V_4 -> type = V_165 ;
V_4 -> V_46 = 1 ;
V_4 -> V_14 . V_15 . V_166 = 2 ;
if ( V_4 -> V_14 . V_15 . V_16 > 1 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_28 , V_164 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_167 ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] > 1 )
return - V_168 ;
if ( V_8 -> V_167 != V_11 -> V_14 . V_15 . V_16 [ 0 ] ) {
V_8 -> V_167 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
F_58 ( V_6 , V_8 -> V_35 . V_36 , 0 ,
V_97 ,
V_8 -> V_167 ) ;
return 1 ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_169 [] = { L_12 , L_13 } ;
static const char * const V_170 [] = { L_12 , L_14 , L_15 } ;
T_1 V_171 = V_8 -> V_85 . V_35 . V_36 ;
int V_172 = F_100 ( V_6 , V_171 ) ;
if ( V_172 == 2 )
return F_101 ( V_2 , V_4 , 2 , V_169 ) ;
else if ( V_172 == 3 )
return F_101 ( V_2 , V_4 , 3 , V_170 ) ;
else
return - V_168 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_173 ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_174 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
T_1 V_171 = V_8 -> V_85 . V_35 . V_36 ;
int V_172 = F_100 ( V_6 , V_171 ) ;
if ( V_174 >= V_172 )
return - V_168 ;
if ( V_8 -> V_173 == V_174 )
return 0 ;
V_8 -> V_173 = V_174 ;
F_58 ( V_6 , V_171 , 0 ,
V_97 , V_174 ) ;
return 1 ;
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_171 = V_8 -> V_85 . V_35 . V_36 ;
int V_172 ;
if ( ! V_171 )
return 0 ;
V_172 = F_100 ( V_6 , V_171 ) ;
if ( V_172 != 2 && V_172 != 3 )
return 0 ;
if ( ! F_105 ( & V_8 -> V_85 , NULL , & V_175 ) )
return - V_31 ;
return 0 ;
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_85 . V_114 = 0x10 ;
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
V_29 = F_61 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_104 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
return 0 ;
error:
F_89 ( V_6 ) ;
return V_29 ;
}
static int F_107 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_119 ;
int V_29 ;
V_119 = F_91 ( V_6 , V_176 ,
V_177 , NULL ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_178 ;
}
if ( V_119 == V_178 )
return F_106 ( V_6 ) ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_29 = F_93 ( V_6 , 0x10 ) ;
if ( V_29 < 0 ) {
F_51 ( V_6 ) ;
return V_29 ;
}
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = F_94 ( V_179 ) ;
V_8 -> V_35 . V_69 = V_179 ;
V_8 -> V_35 . V_36 = V_180 ;
V_8 -> V_73 = 1 ;
V_8 -> V_57 = V_181 ;
V_8 -> V_18 = V_182 ;
V_8 -> V_9 = & V_183 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 [ 0 ] = V_184 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_185 ;
V_8 -> V_167 = 0 ;
#ifdef F_95
V_8 -> V_50 . V_134 = V_186 ;
#endif
V_8 -> V_40 = 0x05 ;
V_6 -> V_94 = V_136 ;
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
return 0 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_57 ( V_2 , V_11 ) )
return 0 ;
F_109 ( V_6 , 0x05 , V_8 -> V_86 ? V_187 : 0 ) ;
F_70 ( V_6 , 0x06 , V_41 , 0 ,
V_102 ,
V_8 -> V_86 ? 0 : V_102 ) ;
return 1 ;
}
static void F_110 ( struct V_5 * V_6 )
{
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x06 ) ;
F_70 ( V_6 , 0x05 , V_41 , 0 ,
V_102 , V_96 ? V_102 : 0 ) ;
}
static void F_111 ( struct V_5 * V_6 )
{
static const struct V_188 V_189 [] = {
{ 0x1f , V_190 , 0xb080 } ,
{ 0x1e , V_190 , 0xb000 } ,
{}
} ;
static const struct V_188 V_191 [] = {
{ 0x1e , V_190 , 0xb080 } ,
{ 0x1f , V_190 , 0xb000 } ,
{}
} ;
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x08 ) ;
if ( V_96 )
F_9 ( V_6 , V_189 ) ;
else
F_9 ( V_6 , V_191 ) ;
}
static void F_112 ( struct V_5 * V_6 ,
unsigned int V_98 )
{
V_98 >>= 26 ;
switch ( V_98 ) {
case V_192 :
F_110 ( V_6 ) ;
break;
case V_193 :
F_111 ( V_6 ) ;
break;
}
}
static int F_113 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_110 ( V_6 ) ;
F_111 ( V_6 ) ;
return 0 ;
}
static void F_114 ( void * V_194 , int V_195 )
{
struct V_5 * V_6 = V_194 ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_115 ( V_6 , V_8 -> V_196 , 0 ,
V_82 ,
V_195 ? 0x02 : 0x00 ) ;
}
static void F_116 ( struct V_5 * V_6 ,
const struct V_109 * V_110 , int V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_111 == V_112 ) {
V_8 -> V_85 . V_197 . V_198 = F_114 ;
V_8 -> V_196 = 0x05 ;
}
}
static void F_117 ( struct V_5 * V_6 ,
const struct V_109 * V_110 , int V_111 )
{
if ( V_111 == V_112 )
F_118 ( V_6 , 0x11 , V_199 ,
( 0x17 << V_200 ) |
( 0x17 << V_201 ) |
( 0x05 << V_202 ) |
( 1 << V_203 ) ) ;
}
static int F_119 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return - V_31 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_85 . V_113 = 0x0e ;
V_8 -> V_85 . V_114 = 0x10 ;
F_86 ( V_8 , 0x0d , 0 , V_41 ) ;
F_87 ( V_6 , NULL , V_204 , V_205 ) ;
F_88 ( V_6 , V_112 ) ;
V_29 = F_61 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_104 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
F_88 ( V_6 , V_118 ) ;
return 0 ;
error:
F_89 ( V_6 ) ;
return V_29 ;
}
static int F_120 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 , V_119 ;
V_119 = F_91 ( V_6 , V_206 ,
V_207 ,
V_208 ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_209 ;
}
if ( V_119 == V_209 )
return F_119 ( V_6 ) ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return - V_31 ;
V_8 = V_6 -> V_8 ;
V_29 = F_93 ( V_6 , 0x10 ) ;
if ( V_29 < 0 ) {
F_51 ( V_6 ) ;
return V_29 ;
}
F_86 ( V_8 , 0x0d , 0 , V_41 ) ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = F_94 ( V_210 ) ;
V_8 -> V_35 . V_69 = V_210 ;
V_8 -> V_35 . V_36 = V_211 ;
V_8 -> V_73 = 1 ;
V_8 -> V_57 = V_212 ;
V_8 -> V_18 = V_213 ;
V_8 -> V_9 = & V_214 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 [ 0 ] = V_215 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_216 ;
V_8 -> V_167 = 0 ;
#ifdef F_95
V_8 -> V_50 . V_134 = V_217 ;
#endif
V_8 -> V_40 = 0x05 ;
V_6 -> V_94 = V_136 ;
switch ( V_119 ) {
case V_218 :
V_8 -> V_34 [ 0 ] = V_219 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_220 ;
if ( ! F_78 ( V_6 , 0x0a ) )
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_221 ;
V_6 -> V_94 . V_157 = F_113 ;
V_6 -> V_94 . V_156 = F_112 ;
F_118 ( V_6 , 0x11 , V_199 ,
( 0x17 << V_200 ) |
( 0x17 << V_201 ) |
( 0x05 << V_202 ) |
( 1 << V_203 ) ) ;
break;
case V_222 :
V_8 -> V_34 [ 0 ] = V_223 ;
V_8 -> V_9 = & V_224 ;
F_118 ( V_6 , 0x11 , V_199 ,
( 0x17 << V_200 ) |
( 0x17 << V_201 ) |
( 0x05 << V_202 ) |
( 1 << V_203 ) ) ;
break;
case V_225 :
V_8 -> V_34 [ 0 ] = V_219 ;
V_8 -> V_34 [ 1 ] = V_226 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_227 ;
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_221 ;
V_6 -> V_94 . V_157 = F_113 ;
V_6 -> V_94 . V_156 = F_112 ;
break;
}
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_122 ( V_6 , V_4 , V_8 -> V_140 ,
V_8 -> V_142 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_124 ( V_6 , V_11 , V_8 -> V_140 ,
V_8 -> V_142 , V_8 -> V_35 . V_68 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_29 = F_126 ( V_6 , V_11 , V_8 -> V_140 ,
V_8 -> V_142 ,
& V_8 -> V_35 . V_68 ) ;
if ( V_29 >= 0 && V_8 -> V_143 )
V_8 -> V_35 . V_126 = V_8 -> V_35 . V_68 / 2 ;
return V_29 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_164 [] = {
L_12 , L_14 , L_15 , L_16
} ;
V_4 -> type = V_165 ;
V_4 -> V_46 = 1 ;
V_4 -> V_14 . V_15 . V_166 = 4 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 4 )
V_4 -> V_14 . V_15 . V_16 = 3 ;
strcpy ( V_4 -> V_14 . V_15 . V_28 , V_164 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_228 ;
V_228 = F_129 ( V_6 , 0x1d , 0 , V_229 ,
V_230 ) ;
if ( ! ( V_228 & 0x80 ) )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
else {
V_228 = F_129 ( V_6 , 0x0b , 0 ,
V_231 , 0 ) ;
if ( V_228 < 3 )
V_228 ++ ;
else
V_228 = 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_228 ;
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_174 , V_228 ;
int V_105 ;
V_174 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
if ( V_174 > 3 )
return - V_168 ;
if ( ! V_174 ) {
V_228 = F_129 ( V_6 , 0x1d , 0 ,
V_229 ,
V_230 ) ;
V_105 = V_228 & 0x80 ;
if ( V_105 ) {
F_58 ( V_6 , 0x1d , 0 ,
V_190 ,
F_131 ( 0 ) ) ;
F_58 ( V_6 , 0x1d , 0 ,
V_190 ,
F_132 ( 1 ) ) ;
}
} else {
V_228 = F_129 ( V_6 , 0x1d , 0 ,
V_229 ,
V_230 | 0x01 ) ;
V_105 = V_228 & 0x80 ;
if ( V_105 ) {
F_58 ( V_6 , 0x1d , 0 ,
V_190 ,
F_132 ( 0 ) ) ;
F_58 ( V_6 , 0x1d , 0 ,
V_190 ,
F_131 ( 1 ) ) ;
}
V_228 = F_129 ( V_6 , 0x0b , 0 ,
V_231 , 0 ) + 1 ;
V_105 |= V_228 != V_174 ;
if ( V_105 )
F_58 ( V_6 , 0x0b , 0 ,
V_97 ,
V_174 - 1 ) ;
}
return V_105 ;
}
static void F_133 ( struct V_5 * V_6 , unsigned int V_98 )
{
if ( ( V_98 >> 26 ) != V_232 )
return;
if ( F_65 ( V_6 , 0x11 ) )
F_9 ( V_6 , V_233 ) ;
else
F_9 ( V_6 , V_234 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
static const char * const V_164 [] = {
L_12 , L_14 , L_15 , L_16 ,
} ;
int V_172 = F_100 ( V_6 , 0x0b ) + 1 ;
if ( V_172 > 4 )
V_172 = 4 ;
return F_101 ( V_2 , V_4 , V_172 , V_164 ) ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_173 ;
return 0 ;
}
static int F_136 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_174 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
struct V_235 * V_236 ;
int V_172 = F_100 ( V_6 , 0x0b ) + 1 ;
if ( V_174 >= V_172 )
return - V_168 ;
if ( V_8 -> V_173 == V_174 )
return 0 ;
F_137 ( & V_6 -> V_237 ) ;
V_6 -> V_238 = 1 ;
V_236 = F_138 ( V_6 ,
V_8 -> V_239 [ V_8 -> V_173 ] ) ;
if ( V_236 )
F_139 ( V_6 , V_236 , false , true ) ;
V_236 = F_138 ( V_6 , V_8 -> V_239 [ V_174 ] ) ;
if ( V_236 )
F_139 ( V_6 , V_236 , true , true ) ;
V_8 -> V_173 = V_174 ;
V_6 -> V_238 = 0 ;
F_140 ( & V_6 -> V_237 ) ;
F_141 ( V_6 ) ;
return 1 ;
}
static int F_142 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 , V_29 ;
V_29 = F_143 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! V_8 -> V_85 . V_90 . V_240 )
return 0 ;
for ( V_19 = 0 ; V_19 < 4 ; V_19 ++ ) {
struct V_235 * V_236 ;
V_236 = F_138 ( V_6 , V_8 -> V_239 [ V_19 ] ) ;
if ( V_236 )
F_139 ( V_6 , V_236 , V_236 -> V_241 , false ) ;
}
return 0 ;
}
static int F_144 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 , V_172 ;
static struct V_235 V_242 [ 4 ] = {
{
. V_243 = 3 ,
. V_236 = { 0x02 , 0x1d , 0x1b } ,
. V_244 = { 0 , 0 , 0 } ,
. V_245 = { 0 , 0 , 0 } ,
} ,
{
. V_243 = 4 ,
. V_236 = { 0x08 , 0x0b , 0x1d , 0x1b } ,
. V_244 = { 0 , 0 , 1 , 0 } ,
. V_245 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_243 = 4 ,
. V_236 = { 0x09 , 0x0b , 0x1d , 0x1b } ,
. V_244 = { 0 , 1 , 1 , 0 } ,
. V_245 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_243 = 4 ,
. V_236 = { 0x0f , 0x0b , 0x1d , 0x1b } ,
. V_244 = { 0 , 2 , 1 , 0 } ,
. V_245 = { 0 , 1 , 0 , 0 } ,
} ,
} ;
if ( ! V_8 -> V_85 . V_90 . V_240 ||
F_145 ( F_146 ( V_6 , 0x1d ) ) != V_246 )
return 0 ;
V_172 = F_100 ( V_6 , 0x0b ) + 1 ;
if ( V_172 != 3 && V_172 != 4 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_172 ; V_19 ++ ) {
struct V_235 * V_236 = F_147 ( & V_8 -> V_85 . V_247 ) ;
if ( ! V_236 )
return - V_31 ;
* V_236 = V_242 [ V_19 ] ;
if ( ! V_19 )
V_236 -> V_241 = 1 ;
V_8 -> V_239 [ V_19 ] = F_148 ( V_6 , V_236 ) ;
}
if ( ! F_105 ( & V_8 -> V_85 , NULL , & V_248 ) )
return - V_31 ;
V_6 -> V_94 . V_157 = F_142 ;
return 0 ;
}
static int F_149 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_85 . V_113 = 0x20 ;
V_8 -> V_85 . V_249 = 0x21 ;
V_8 -> V_85 . V_114 = 0x10 ;
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
V_29 = F_61 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_144 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
return 0 ;
error:
F_89 ( V_6 ) ;
return V_29 ;
}
static int F_150 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 , V_119 ;
V_119 = F_91 ( V_6 , V_250 ,
V_251 , V_252 ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_253 ;
}
if ( V_119 == V_253 )
return F_149 ( V_6 ) ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
if ( F_151 ( V_6 ) )
F_152 ( V_123 L_17 ) ;
V_29 = F_93 ( V_6 , 0x10 ) ;
if ( V_29 < 0 ) {
F_51 ( V_6 ) ;
return V_29 ;
}
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
if ( ! V_8 -> V_35 . V_254 )
V_8 -> V_35 . V_254 = V_255 [ 0 ] ;
switch ( V_119 ) {
case V_256 :
case V_257 :
V_8 -> V_35 . V_68 = 8 ;
V_8 -> V_35 . V_126 = 4 ;
if ( F_151 ( V_6 ) )
V_8 -> V_35 . V_69 = V_258 ;
else
V_8 -> V_35 . V_69 = V_259 ;
V_8 -> V_9 = & V_260 ;
V_8 -> V_33 = 2 ;
if ( F_151 ( V_6 ) )
V_8 -> V_34 [ 0 ] = V_261 ;
else
V_8 -> V_34 [ 0 ] = V_262 ;
V_8 -> V_34 [ 1 ] = V_263 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_264 ;
if ( V_119 == V_257 ) {
V_8 -> V_35 . V_36 = V_265 ;
V_8 -> V_38 = V_266 ;
}
break;
case V_267 :
case V_268 :
V_8 -> V_35 . V_68 = 6 ;
V_8 -> V_35 . V_126 = 3 ;
if ( F_151 ( V_6 ) )
V_8 -> V_35 . V_69 = V_269 ;
else
V_8 -> V_35 . V_69 = V_270 ;
V_8 -> V_9 = & V_260 ;
V_8 -> V_140 = V_271 ;
V_8 -> V_142 = F_94 ( V_271 ) ;
V_8 -> V_33 = 2 ;
if ( F_151 ( V_6 ) )
V_8 -> V_34 [ 0 ] = V_272 ;
else
V_8 -> V_34 [ 0 ] = V_273 ;
V_8 -> V_34 [ 1 ] = V_274 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_275 ;
if ( V_119 == V_268 )
V_8 -> V_35 . V_36 = V_265 ;
break;
case V_276 :
case V_277 :
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
V_8 -> V_35 . V_69 = V_270 ;
V_8 -> V_9 = & V_278 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 [ 0 ] = V_279 ;
V_6 -> V_83 = 1 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_280 ;
if ( V_119 == V_277 )
V_8 -> V_35 . V_36 = V_265 ;
break;
}
V_8 -> V_73 = F_94 ( V_281 ) ;
V_8 -> V_57 = V_281 ;
V_8 -> V_18 = V_282 ;
V_8 -> V_34 [ V_8 -> V_33 ++ ] = V_283 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_284 ;
if ( V_8 -> V_35 . V_36 ) {
if ( V_6 -> V_84 >= 0x11d4989a ) {
V_8 -> V_34 [ V_8 -> V_33 ++ ] =
V_285 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_286 ;
V_6 -> V_287 = V_288 ;
} else {
V_8 -> V_34 [ V_8 -> V_33 ++ ] =
V_289 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_290 ;
}
}
if ( V_8 -> V_38 && V_6 -> V_84 < 0x11d4989a ) {
V_8 -> V_34 [ V_8 -> V_33 ++ ] = V_291 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_292 ;
}
V_6 -> V_94 = V_136 ;
switch ( V_119 ) {
case V_276 :
case V_277 :
V_6 -> V_94 . V_156 = F_133 ;
break;
}
#ifdef F_95
V_8 -> V_50 . V_134 = V_293 ;
#endif
V_8 -> V_40 = 0x04 ;
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
return 0 ;
}
static void F_153 ( struct V_5 * V_6 ,
const struct V_109 * V_110 , int V_111 )
{
if ( V_111 == V_112 )
F_118 ( V_6 , 0x20 , V_199 ,
( 0x17 << V_200 ) |
( 0x17 << V_201 ) |
( 0x05 << V_202 ) |
( 1 << V_203 ) ) ;
}
static void F_154 ( struct V_5 * V_6 ,
const struct V_109 * V_110 , int V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_111 == V_112 ) {
if ( V_8 -> V_85 . V_90 . V_294 == V_295 )
V_8 -> V_196 = V_8 -> V_85 . V_90 . V_296 [ 0 ] ;
else
V_8 -> V_196 = V_8 -> V_85 . V_90 . V_297 [ 0 ] ;
if ( V_8 -> V_196 )
V_8 -> V_85 . V_197 . V_198 = F_114 ;
}
}
static int F_155 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_85 . V_113 = 0x20 ;
V_8 -> V_85 . V_114 = 0x10 ;
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
F_87 ( V_6 , NULL , V_298 , V_299 ) ;
F_88 ( V_6 , V_112 ) ;
V_29 = F_61 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_104 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
F_88 ( V_6 , V_118 ) ;
return 0 ;
error:
F_89 ( V_6 ) ;
return V_29 ;
}
static int F_156 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_29 = F_93 ( V_6 , 0x10 ) ;
if ( V_29 < 0 ) {
F_51 ( V_6 ) ;
return V_29 ;
}
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = F_94 ( V_300 ) ;
V_8 -> V_35 . V_69 = V_300 ;
V_8 -> V_35 . V_36 = V_301 ;
V_8 -> V_73 = F_94 ( V_302 ) ;
V_8 -> V_57 = V_302 ;
V_8 -> V_18 = V_303 ;
V_8 -> V_9 = & V_304 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 [ 0 ] = V_305 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_306 ;
V_8 -> V_167 = 0 ;
#ifdef F_95
V_8 -> V_50 . V_134 = V_307 ;
#endif
V_8 -> V_40 = 0x04 ;
V_8 -> V_42 = V_308 ;
V_8 -> V_44 = 1 ;
V_6 -> V_94 = V_136 ;
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
return 0 ;
}
static int F_157 ( struct V_5 * V_6 )
{
int V_119 ;
V_119 = F_91 ( V_6 , V_309 ,
V_310 , NULL ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_311 ;
}
if ( V_119 == V_311 )
return F_155 ( V_6 ) ;
else
return F_156 ( V_6 ) ;
}
static int F_158 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
unsigned int V_55 ,
unsigned int V_56 ,
struct V_53 * V_54 )
{
F_41 ( V_6 , 0x05 + V_54 -> V_58 ,
V_55 , 0 , V_56 ) ;
return 0 ;
}
static int F_159 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
F_43 ( V_6 , 0x05 + V_54 -> V_58 ) ;
return 0 ;
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_59 * V_60 ;
int V_29 ;
V_29 = F_44 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_60 = V_8 -> V_61 + V_6 -> V_62 ;
V_6 -> V_62 ++ ;
V_60 -> V_28 = L_18 ;
V_60 -> V_64 [ V_70 ] = V_312 ;
return 0 ;
}
static int F_161 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_119 , V_29 ;
V_119 = F_91 ( V_6 , V_313 ,
V_314 , V_315 ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_316 ;
}
if ( V_119 == V_316 )
return F_155 ( V_6 ) ;
V_29 = F_156 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
switch ( V_119 ) {
case V_317 :
V_8 -> V_34 [ V_8 -> V_33 ++ ] = V_318 ;
V_6 -> V_94 . V_319 = F_160 ;
break;
case V_320 :
if ( V_6 -> V_321 == 0x17aa20fb ) {
V_8 -> V_35 . V_36 = 0 ;
} else
V_8 -> V_35 . V_36 = V_301 ;
V_8 -> V_9 = & V_322 ;
V_8 -> V_34 [ 0 ] = V_323 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_324 ;
V_8 -> V_25 = 1 ;
break;
case V_325 :
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_326 ;
V_8 -> V_34 [ 0 ] = V_327 ;
break;
}
return 0 ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_328 = F_75 ( V_2 , V_11 ) ;
int V_100 = ( ! V_11 -> V_14 . integer . V_14 [ 0 ] &&
! V_11 -> V_14 . integer . V_14 [ 1 ] ) ;
F_58 ( V_6 , 0x01 , 0 , V_329 ,
V_100 ? 0x02 : 0x0 ) ;
return V_328 ;
}
static void F_163 ( struct V_5 * V_6 )
{
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x11 ) ;
F_70 ( V_6 , 0x16 , V_41 , 0 ,
V_102 , V_96 ? V_102 : 0 ) ;
F_47 ( V_6 , 0x16 , 0 , V_82 ,
V_96 ? 0x00 : 0x02 ) ;
}
static void F_164 ( struct V_5 * V_6 )
{
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x14 ) ;
F_47 ( V_6 , 0x0c , 0 , V_97 ,
V_96 ? 0 : 1 ) ;
}
static void F_165 ( struct V_5 * V_6 , unsigned int V_98 )
{
switch ( V_98 >> 26 ) {
case V_330 :
F_163 ( V_6 ) ;
break;
case V_331 :
F_164 ( V_6 ) ;
break;
}
}
static int F_166 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_163 ( V_6 ) ;
F_164 ( V_6 ) ;
return 0 ;
}
static void F_167 ( struct V_5 * V_6 )
{
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x11 ) ;
if ( ! V_96 )
V_96 = F_65 ( V_6 , 0x12 ) ;
F_70 ( V_6 , 0x16 , V_41 , 0 ,
V_102 , V_96 ? V_102 : 0 ) ;
F_47 ( V_6 , 0x16 , 0 , V_82 ,
V_96 ? 0x00 : 0x02 ) ;
}
static void F_168 ( struct V_5 * V_6 )
{
unsigned int V_244 ;
if ( F_65 ( V_6 , 0x14 ) )
V_244 = 0 ;
else if ( F_65 ( V_6 , 0x1c ) )
V_244 = 4 ;
else
V_244 = 1 ;
F_47 ( V_6 , 0x0c , 0 , V_97 , V_244 ) ;
}
static void F_169 ( struct V_5 * V_6 ,
unsigned int V_98 )
{
switch ( V_98 >> 26 ) {
case V_330 :
F_167 ( V_6 ) ;
break;
case V_331 :
F_168 ( V_6 ) ;
break;
}
}
static int F_170 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_167 ( V_6 ) ;
F_168 ( V_6 ) ;
return 0 ;
}
static void F_171 ( struct V_5 * V_6 )
{
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x11 ) ;
F_70 ( V_6 , 0x12 , V_41 , 0 ,
V_102 , V_96 ? V_102 : 0 ) ;
}
static void F_172 ( struct V_5 * V_6 ,
unsigned int V_98 )
{
if ( ( V_98 >> 26 ) != V_330 )
return;
F_171 ( V_6 ) ;
}
static int F_173 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_171 ( V_6 ) ;
return 0 ;
}
static void F_174 ( struct V_5 * V_6 )
{
unsigned int V_96 ;
V_96 = F_65 ( V_6 , 0x12 ) ;
F_70 ( V_6 , 0x13 , V_41 , 0 ,
V_102 , V_96 ? V_102 : 0 ) ;
}
static void F_175 ( struct V_5 * V_6 ,
unsigned int V_98 )
{
if ( ( V_98 >> 26 ) != V_330 )
return;
F_174 ( V_6 ) ;
}
static int F_176 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_174 ( V_6 ) ;
return 0 ;
}
static void F_177 ( struct V_5 * V_6 )
{
if ( F_65 ( V_6 , 0x1c ) )
F_47 ( V_6 , 0x0c , 0 ,
V_97 , 0x4 ) ;
else
F_47 ( V_6 , 0x0c , 0 ,
V_97 , 0x5 ) ;
}
static void F_178 ( struct V_5 * V_6 ,
unsigned int V_98 )
{
switch ( V_98 >> 26 ) {
case V_330 :
F_163 ( V_6 ) ;
break;
case V_331 :
F_177 ( V_6 ) ;
break;
}
}
static int F_179 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_163 ( V_6 ) ;
F_177 ( V_6 ) ;
return 0 ;
}
static int F_180 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 , V_119 ;
V_119 = F_91 ( V_6 , V_332 ,
V_333 ,
V_334 ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_335 ;
}
if ( V_119 == V_335 )
return F_155 ( V_6 ) ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_29 = F_93 ( V_6 , 0x10 ) ;
if ( V_29 < 0 ) {
F_51 ( V_6 ) ;
return V_29 ;
}
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = F_94 ( V_336 ) ;
V_8 -> V_35 . V_69 = V_336 ;
V_8 -> V_35 . V_36 = V_337 ;
V_8 -> V_73 = F_94 ( V_338 ) ;
V_8 -> V_57 = V_338 ;
V_8 -> V_18 = V_339 ;
V_8 -> V_9 = & V_340 ;
V_8 -> V_33 = 1 ;
V_8 -> V_34 [ 0 ] = V_341 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_342 ;
V_8 -> V_167 = 0 ;
#ifdef F_95
V_8 -> V_50 . V_134 = V_343 ;
#endif
V_6 -> V_94 = V_136 ;
switch ( V_119 ) {
case V_344 :
V_8 -> V_34 [ 0 ] = V_345 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_346 ;
V_8 -> V_35 . V_36 = 0 ;
V_6 -> V_94 . V_156 = F_169 ;
V_6 -> V_94 . V_157 = F_170 ;
F_118 ( V_6 , 0x20 , V_199 ,
( 0x17 << V_200 ) |
( 0x17 << V_201 ) |
( 0x05 << V_202 ) |
( 1 << V_203 ) ) ;
break;
case V_347 :
V_8 -> V_34 [ 0 ] = V_348 ;
V_8 -> V_21 [ 0 ] = V_349 ;
V_8 -> V_35 . V_36 = 0 ;
V_6 -> V_94 . V_156 = F_165 ;
V_6 -> V_94 . V_157 = F_166 ;
F_118 ( V_6 , 0x20 , V_199 ,
( 0x17 << V_200 ) |
( 0x17 << V_201 ) |
( 0x05 << V_202 ) |
( 1 << V_203 ) ) ;
break;
case V_350 :
V_8 -> V_34 [ 0 ] = V_351 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_352 ;
V_8 -> V_35 . V_36 = 0 ;
V_8 -> V_9 = & V_353 ;
V_6 -> V_94 . V_156 = F_172 ;
V_6 -> V_94 . V_157 = F_173 ;
break;
case V_354 :
V_8 -> V_34 [ 0 ] = V_355 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_356 ;
V_8 -> V_35 . V_36 = 0 ;
V_6 -> V_94 . V_156 = F_175 ;
V_6 -> V_94 . V_157 = F_176 ;
break;
case V_357 :
V_8 -> V_34 [ 0 ] = V_358 ;
V_8 -> V_21 [ 0 ] = V_359 ;
V_8 -> V_35 . V_36 = 0 ;
V_6 -> V_94 . V_156 = F_178 ;
V_6 -> V_94 . V_157 = F_179 ;
F_118 ( V_6 , 0x20 , V_199 ,
( 0x17 << V_200 ) |
( 0x17 << V_201 ) |
( 0x05 << V_202 ) |
( 1 << V_203 ) ) ;
break;
}
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
return 0 ;
}
static void F_181 ( struct V_5 * V_6 )
{
bool V_100 = F_65 ( V_6 , 0x11 ) ;
F_47 ( V_6 , 0x12 , 0 , V_360 ,
V_100 ? 0 : V_187 ) ;
}
static int F_182 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_181 ( V_6 ) ;
return 0 ;
}
static void F_183 ( struct V_5 * V_6 , unsigned int V_98 )
{
switch ( V_98 >> 26 ) {
case V_361 :
F_181 ( V_6 ) ;
break;
}
}
static int F_184 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_85 . V_113 = 0x20 ;
V_8 -> V_85 . V_249 = 0x21 ;
V_8 -> V_85 . V_114 = 0x10 ;
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
V_29 = F_61 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_144 ( V_6 ) ;
if ( V_29 < 0 )
goto error;
return 0 ;
error:
F_89 ( V_6 ) ;
return V_29 ;
}
static int F_185 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_29 , V_119 ;
V_119 = F_91 ( V_6 , V_362 ,
V_363 , NULL ) ;
if ( V_119 < 0 ) {
F_92 ( V_123 L_11 ,
V_6 -> V_124 ) ;
V_119 = V_364 ;
}
if ( V_119 == V_364 )
return F_184 ( V_6 ) ;
V_29 = F_81 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 = V_6 -> V_8 ;
V_29 = F_93 ( V_6 , 0x10 ) ;
if ( V_29 < 0 ) {
F_51 ( V_6 ) ;
return V_29 ;
}
F_86 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_35 . V_68 = 6 ;
V_8 -> V_35 . V_126 = 3 ;
V_8 -> V_35 . V_69 = V_365 ;
V_8 -> V_35 . V_36 = V_366 ;
V_8 -> V_73 = F_94 ( V_367 ) ;
V_8 -> V_57 = V_367 ;
V_8 -> V_18 = V_368 ;
if ( V_6 -> V_84 == 0x11d41882 )
V_8 -> V_9 = & V_369 ;
else
V_8 -> V_9 = & V_370 ;
V_8 -> V_33 = 2 ;
V_8 -> V_34 [ 0 ] = V_371 ;
if ( V_6 -> V_84 == 0x11d41882 )
V_8 -> V_34 [ 1 ] = V_372 ;
else
V_8 -> V_34 [ 1 ] = V_373 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_374 ;
V_8 -> V_167 = 0 ;
#ifdef F_95
V_8 -> V_50 . V_134 = V_375 ;
#endif
V_8 -> V_40 = 0x04 ;
V_6 -> V_94 = V_136 ;
switch ( V_119 ) {
default:
case V_376 :
case V_377 :
V_8 -> V_33 = 3 ;
V_8 -> V_34 [ 2 ] = V_378 ;
V_8 -> V_140 = V_379 ;
V_8 -> V_142 = F_94 ( V_379 ) ;
V_8 -> V_143 = 1 ;
V_8 -> V_35 . V_68 = 2 ;
V_8 -> V_35 . V_126 = 1 ;
if ( V_119 != V_376 ) {
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_380 ;
V_6 -> V_94 . V_156 = F_183 ;
V_6 -> V_94 . V_157 = F_182 ;
}
break;
case V_381 :
V_8 -> V_33 = 3 ;
V_8 -> V_34 [ 2 ] = V_382 ;
break;
}
V_6 -> V_91 = 1 ;
V_6 -> V_92 = 1 ;
return 0 ;
}
static int T_2 F_186 ( void )
{
return F_187 ( & V_383 ) ;
}
static void T_3 F_188 ( void )
{
F_189 ( & V_383 ) ;
}
