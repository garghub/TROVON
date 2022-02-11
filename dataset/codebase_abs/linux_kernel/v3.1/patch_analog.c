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
struct V_1 * V_22 ;
unsigned int V_19 ;
int V_23 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_24 ; V_19 ++ ) {
V_23 = F_11 ( V_6 , V_8 -> V_25 [ V_19 ] ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( V_8 -> V_26 . V_27 ) {
V_23 = F_12 ( V_6 ,
V_8 -> V_26 . V_27 ,
V_8 -> V_26 . V_27 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_13 ( V_6 ,
& V_8 -> V_26 ) ;
if ( V_23 < 0 )
return V_23 ;
V_8 -> V_26 . V_28 = 1 ;
}
if ( V_8 -> V_29 ) {
V_23 = F_14 ( V_6 , V_8 -> V_29 ) ;
if ( V_23 < 0 )
return V_23 ;
}
#ifdef F_15
if ( V_8 -> V_30 ) {
const struct V_31 * V_32 ;
V_32 = V_8 -> V_33 ? V_34 : V_35 ;
for ( ; V_32 -> V_36 ; V_32 ++ ) {
struct V_1 * V_22 ;
V_22 = F_16 ( V_32 , V_6 ) ;
if ( ! V_22 )
return - V_37 ;
V_22 -> V_38 = V_8 -> V_30 ;
V_23 = F_17 ( V_6 , 0 , V_22 ) ;
if ( V_23 < 0 )
return V_23 ;
}
}
#endif
if ( ! F_18 ( V_6 , L_1 ) ) {
unsigned int V_39 [ 4 ] ;
F_19 ( V_6 , V_8 -> V_40 ,
V_41 , V_39 ) ;
V_23 = F_20 ( V_6 , L_1 ,
V_39 ,
( V_8 -> V_42 ?
V_8 -> V_42 : V_43 ) ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( ! F_18 ( V_6 , L_2 ) ) {
V_23 = F_20 ( V_6 , L_2 ,
NULL ,
( V_8 -> V_44 ?
V_8 -> V_44 : V_45 ) ) ;
if ( V_23 < 0 )
return V_23 ;
}
F_21 ( V_6 ) ;
V_22 = F_18 ( V_6 , L_3 ) ;
if ( ! V_22 )
V_22 = F_18 ( V_6 , L_4 ) ;
for ( V_19 = 0 ; V_22 && V_19 < V_22 -> V_46 ; V_19 ++ ) {
V_23 = F_22 ( V_6 , V_22 , V_19 , V_8 -> V_18 [ V_19 ] ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_22 = F_18 ( V_6 ,
F_23 ( L_5 , V_47 , V_48 ) L_6 ) ;
if ( V_22 ) {
V_23 = F_22 ( V_6 , V_22 , 0 ,
V_8 -> V_26 . V_27 ) ;
if ( V_23 < 0 )
return V_23 ;
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
return F_27 ( V_6 , & V_8 -> V_26 , V_54 ,
V_52 ) ;
}
static int F_28 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
unsigned int V_55 ,
unsigned int V_56 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_29 ( V_6 , & V_8 -> V_26 , V_55 ,
V_56 , V_54 ) ;
}
static int F_30 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_31 ( V_6 , & V_8 -> V_26 ) ;
}
static int F_32 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_33 ( V_6 , & V_8 -> V_26 ) ;
}
static int F_34 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_35 ( V_6 , & V_8 -> V_26 ) ;
}
static int F_36 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
unsigned int V_55 ,
unsigned int V_56 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_37 ( V_6 , & V_8 -> V_26 , V_55 ,
V_56 , V_54 ) ;
}
static int F_38 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_39 ( V_6 , & V_8 -> V_26 ) ;
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
V_60 -> V_36 = L_7 ;
V_60 -> V_64 [ V_65 ] = V_66 ;
V_60 -> V_64 [ V_65 ] . V_67 = V_8 -> V_26 . V_68 ;
V_60 -> V_64 [ V_65 ] . V_49 = V_8 -> V_26 . V_69 [ 0 ] ;
V_60 -> V_64 [ V_70 ] = V_71 ;
V_60 -> V_64 [ V_70 ] . V_72 = V_8 -> V_73 ;
V_60 -> V_64 [ V_70 ] . V_49 = V_8 -> V_57 [ 0 ] ;
if ( V_8 -> V_26 . V_27 ) {
V_60 ++ ;
V_6 -> V_62 ++ ;
V_60 -> V_36 = L_8 ;
V_60 -> V_74 = V_75 ;
V_60 -> V_64 [ V_65 ] = V_76 ;
V_60 -> V_64 [ V_65 ] . V_49 = V_8 -> V_26 . V_27 ;
if ( V_8 -> V_29 ) {
V_60 -> V_64 [ V_70 ] = V_77 ;
V_60 -> V_64 [ V_70 ] . V_49 = V_8 -> V_29 ;
}
}
if ( V_8 -> V_78 && V_8 -> V_79 ) {
V_6 -> V_62 ++ ;
V_60 = V_8 -> V_61 + 2 ;
V_60 -> V_36 = L_9 ;
V_60 -> V_74 = V_80 ;
V_60 -> V_64 [ V_65 ] =
* V_8 -> V_79 ;
V_60 -> V_64 [ V_65 ] . V_49 =
V_8 -> V_78 [ 0 ] ;
}
return 0 ;
}
static void F_21 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_81 . V_82 ) {
struct V_31 * V_22 = V_8 -> V_81 . V_82 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_81 . V_83 ; V_19 ++ )
F_45 ( V_22 [ V_19 ] . V_36 ) ;
}
F_46 ( & V_8 -> V_81 ) ;
}
static void F_47 ( struct V_5 * V_6 , T_1 V_84 ,
T_1 V_85 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( F_48 ( V_6 , V_84 ) & V_86 )
F_49 ( V_6 , V_84 , 0 , V_87 ,
! V_8 -> V_88 ? 0x00 : 0x02 ) ;
if ( F_48 ( V_6 , V_85 ) & V_86 )
F_49 ( V_6 , V_85 , 0 , V_87 ,
! V_8 -> V_88 ? 0x00 : 0x02 ) ;
}
static void F_50 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_89 ) {
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
F_47 ( V_6 , 0x12 , 0x11 ) ;
break;
case 0x11d41981 :
case 0x11d41983 :
F_47 ( V_6 , 0x05 , 0x06 ) ;
break;
case 0x11d41986 :
F_47 ( V_6 , 0x1b , 0x1a ) ;
break;
}
}
static void F_51 ( struct V_5 * V_6 )
{
F_52 ( V_6 ) ;
F_50 ( V_6 ) ;
}
static void F_53 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_51 ( V_6 ) ;
F_21 ( V_6 ) ;
F_45 ( V_8 ) ;
F_54 ( V_6 ) ;
}
static int F_55 ( struct V_5 * V_6 , T_2 V_90 )
{
F_51 ( V_6 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_88 )
V_11 -> V_14 . integer . V_14 [ 0 ] = ! V_8 -> V_91 ;
else
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_91 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_49 = V_2 -> V_38 & 0xff ;
unsigned int V_92 ;
V_92 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_88 )
V_92 = ! V_92 ;
if ( V_92 == V_8 -> V_91 )
return 0 ;
V_8 -> V_91 = V_92 ;
F_58 ( V_6 , V_49 ,
0 , V_87 ,
V_92 ? 0x02 : 0x00 ) ;
return 1 ;
}
static void F_59 ( struct V_5 * V_6 )
{
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x1f ) ;
F_49 ( V_6 , 0x0f , 0 , V_94 ,
V_93 ? 0 : 2 ) ;
}
static void F_61 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
if ( ( V_95 >> 26 ) != V_96 )
return;
F_59 ( V_6 ) ;
}
static int F_62 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_59 ( V_6 ) ;
return 0 ;
}
static void F_63 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_97 ;
if ( V_8 -> V_98 )
V_97 = V_99 ;
else
V_97 = F_64 ( V_6 , 0x1a , 0 , V_41 , 0 ) ;
F_65 ( V_6 , 0x1b , V_41 , 0 ,
V_99 , V_97 ) ;
}
static void F_66 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_98 = F_60 ( V_6 , 0x1a ) ;
if ( V_8 -> V_100 )
V_8 -> V_98 = ! V_8 -> V_98 ;
F_63 ( V_6 ) ;
}
static void F_67 ( struct V_5 * V_6 , unsigned int V_95 )
{
if ( ( V_95 >> 26 ) != V_101 )
return;
F_66 ( V_6 ) ;
}
static int F_68 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_66 ( V_6 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
long * V_102 = V_11 -> V_14 . integer . V_14 ;
int V_103 ;
V_103 = F_70 ( V_6 , 0x1a , 0 , V_41 , 0 ,
V_99 ,
V_102 [ 0 ] ? 0 : V_99 ) ;
V_103 |= F_70 ( V_6 , 0x1a , 1 , V_41 , 0 ,
V_99 ,
V_102 [ 1 ] ? 0 : V_99 ) ;
if ( V_103 )
F_63 ( V_6 ) ;
return V_103 ;
}
static void F_71 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
switch ( V_95 >> 26 ) {
case V_101 :
F_66 ( V_6 ) ;
break;
case V_96 :
F_59 ( V_6 ) ;
break;
}
}
static int F_72 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_66 ( V_6 ) ;
F_59 ( V_6 ) ;
return 0 ;
}
static int F_73 ( struct V_5 * V_6 , T_1 V_49 )
{
unsigned int V_104 = F_74 ( V_6 , V_49 ) ;
return F_75 ( V_104 ) != V_105 ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_106 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_78 ( V_6 , 0x19 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
}
F_79 ( V_8 , 0x18 , 0 , V_41 ) ;
V_8 -> V_26 . V_68 = 6 ;
V_8 -> V_26 . V_108 = F_80 ( V_109 ) ;
V_8 -> V_26 . V_69 = V_109 ;
V_8 -> V_26 . V_27 = V_110 ;
V_8 -> V_73 = 1 ;
V_8 -> V_57 = V_111 ;
V_8 -> V_18 = V_112 ;
V_8 -> V_9 = & V_113 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_114 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_115 ;
#ifdef F_81
V_8 -> V_50 . V_116 = V_117 ;
#endif
V_8 -> V_40 = 0x1b ;
V_8 -> V_88 = 1 ;
V_6 -> V_118 = V_119 ;
V_106 = F_82 ( V_6 , V_120 ,
V_121 ,
V_122 ) ;
switch ( V_106 ) {
case V_123 :
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 1 ] = V_124 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_125 ;
V_8 -> V_126 = V_127 ;
V_8 -> V_128 = F_80 ( V_127 ) ;
V_8 -> V_129 = 1 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
break;
case V_130 :
V_8 -> V_25 [ 0 ] = V_131 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
V_8 -> V_26 . V_69 = V_132 ;
break;
case V_133 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 0 ] = V_134 ;
V_8 -> V_25 [ 1 ] = V_135 ;
V_8 -> V_25 [ 2 ] = V_136 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_137 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
V_8 -> V_26 . V_69 = V_132 ;
if ( ! F_73 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_138 ;
break;
case V_139 :
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 0 ] = V_134 ;
V_8 -> V_25 [ 1 ] = V_135 ;
V_8 -> V_20 = 3 ;
V_8 -> V_21 [ 1 ] = V_137 ;
V_8 -> V_21 [ 2 ] = V_140 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
V_8 -> V_26 . V_69 = V_132 ;
if ( ! F_73 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_141 ;
V_6 -> V_118 . V_142 = F_61 ;
V_6 -> V_118 . V_143 = F_62 ;
break;
case V_144 :
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 0 ] = V_145 ;
V_8 -> V_25 [ 1 ] = V_135 ;
V_8 -> V_20 = 4 ;
V_8 -> V_21 [ 1 ] = V_137 ;
V_8 -> V_21 [ 2 ] = V_140 ;
V_8 -> V_21 [ 3 ] = V_146 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
V_8 -> V_26 . V_69 = V_132 ;
if ( ! F_73 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_141 ;
V_6 -> V_118 . V_142 = F_71 ;
V_6 -> V_118 . V_143 = F_72 ;
break;
case V_147 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 0 ] = V_145 ;
V_8 -> V_25 [ 1 ] = V_135 ;
V_8 -> V_25 [ 2 ] = V_136 ;
V_8 -> V_20 = 3 ;
V_8 -> V_21 [ 1 ] = V_137 ;
V_8 -> V_21 [ 2 ] = V_146 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
V_8 -> V_26 . V_69 = V_132 ;
if ( ! F_73 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_138 ;
V_6 -> V_118 . V_142 = F_67 ;
V_6 -> V_118 . V_143 = F_68 ;
V_8 -> V_100 = 1 ;
break;
case V_148 :
V_8 -> V_25 [ 0 ] = V_135 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_149 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
V_8 -> V_26 . V_69 = V_132 ;
V_8 -> V_26 . V_27 = 0 ;
break;
}
V_8 -> V_26 . V_150 = 1 ;
V_6 -> V_151 = 1 ;
V_6 -> V_152 = 1 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static const char * const V_153 [] = { L_10 , L_11 } ;
V_4 -> type = V_154 ;
V_4 -> V_46 = 1 ;
V_4 -> V_14 . V_15 . V_155 = 2 ;
if ( V_4 -> V_14 . V_15 . V_16 > 1 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_36 , V_153 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_156 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] > 1 )
return - V_157 ;
if ( V_8 -> V_156 != V_11 -> V_14 . V_15 . V_16 [ 0 ] ) {
V_8 -> V_156 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
F_58 ( V_6 , V_8 -> V_26 . V_27 , 0 ,
V_94 ,
V_8 -> V_156 ) ;
return 1 ;
}
return 0 ;
}
static int F_86 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_78 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
}
F_79 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = F_80 ( V_158 ) ;
V_8 -> V_26 . V_69 = V_158 ;
V_8 -> V_26 . V_27 = V_159 ;
V_8 -> V_73 = 1 ;
V_8 -> V_57 = V_160 ;
V_8 -> V_18 = V_161 ;
V_8 -> V_9 = & V_162 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_163 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_164 ;
V_8 -> V_156 = 0 ;
#ifdef F_81
V_8 -> V_50 . V_116 = V_165 ;
#endif
V_8 -> V_40 = 0x05 ;
V_6 -> V_118 = V_119 ;
V_6 -> V_151 = 1 ;
V_6 -> V_152 = 1 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_57 ( V_2 , V_11 ) )
return 0 ;
F_49 ( V_6 , 0x05 , 0 ,
V_166 ,
V_8 -> V_91 ? V_167 : 0 ) ;
F_65 ( V_6 , 0x06 , V_41 , 0 ,
V_99 ,
V_8 -> V_91 ? 0 : V_99 ) ;
return 1 ;
}
static void F_88 ( struct V_5 * V_6 )
{
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x06 ) ;
F_65 ( V_6 , 0x05 , V_41 , 0 ,
V_99 , V_93 ? V_99 : 0 ) ;
}
static void F_89 ( struct V_5 * V_6 )
{
static const struct V_168 V_169 [] = {
{ 0x1f , V_170 , 0xb080 } ,
{ 0x1e , V_170 , 0xb000 } ,
{}
} ;
static const struct V_168 V_171 [] = {
{ 0x1e , V_170 , 0xb080 } ,
{ 0x1f , V_170 , 0xb000 } ,
{}
} ;
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x08 ) ;
if ( V_93 )
F_9 ( V_6 , V_169 ) ;
else
F_9 ( V_6 , V_171 ) ;
}
static void F_90 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
V_95 >>= 26 ;
switch ( V_95 ) {
case V_172 :
F_88 ( V_6 ) ;
break;
case V_173 :
F_89 ( V_6 ) ;
break;
}
}
static int F_91 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_88 ( V_6 ) ;
F_89 ( V_6 ) ;
return 0 ;
}
static int F_92 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_106 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_78 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
}
F_79 ( V_8 , 0x0d , 0 , V_41 ) ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = F_80 ( V_174 ) ;
V_8 -> V_26 . V_69 = V_174 ;
V_8 -> V_26 . V_27 = V_175 ;
V_8 -> V_73 = 1 ;
V_8 -> V_57 = V_176 ;
V_8 -> V_18 = V_177 ;
V_8 -> V_9 = & V_178 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_179 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_180 ;
V_8 -> V_156 = 0 ;
#ifdef F_81
V_8 -> V_50 . V_116 = V_181 ;
#endif
V_8 -> V_40 = 0x05 ;
V_6 -> V_118 = V_119 ;
V_106 = F_82 ( V_6 , V_182 ,
V_183 ,
V_184 ) ;
switch ( V_106 ) {
case V_185 :
V_8 -> V_25 [ 0 ] = V_186 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_187 ;
if ( ! F_73 ( V_6 , 0x0a ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_188 ;
V_6 -> V_118 . V_143 = F_91 ;
V_6 -> V_118 . V_142 = F_90 ;
F_93 ( V_6 , 0x11 , V_189 ,
( 0x17 << V_190 ) |
( 0x17 << V_191 ) |
( 0x05 << V_192 ) |
( 1 << V_193 ) ) ;
break;
case V_194 :
V_8 -> V_25 [ 0 ] = V_195 ;
V_8 -> V_9 = & V_196 ;
F_93 ( V_6 , 0x11 , V_189 ,
( 0x17 << V_190 ) |
( 0x17 << V_191 ) |
( 0x05 << V_192 ) |
( 1 << V_193 ) ) ;
break;
case V_197 :
V_8 -> V_25 [ 0 ] = V_186 ;
V_8 -> V_25 [ 1 ] = V_198 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_199 ;
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_188 ;
V_6 -> V_118 . V_143 = F_91 ;
V_6 -> V_118 . V_142 = F_90 ;
break;
}
V_6 -> V_151 = 1 ;
V_6 -> V_152 = 1 ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_95 ( V_6 , V_4 , V_8 -> V_126 ,
V_8 -> V_128 ) ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_97 ( V_6 , V_11 , V_8 -> V_126 ,
V_8 -> V_128 , V_8 -> V_26 . V_68 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_23 = F_99 ( V_6 , V_11 , V_8 -> V_126 ,
V_8 -> V_128 ,
& V_8 -> V_26 . V_68 ) ;
if ( V_23 >= 0 && V_8 -> V_129 )
V_8 -> V_26 . V_108 = V_8 -> V_26 . V_68 / 2 ;
return V_23 ;
}
static int F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_153 [] = {
L_10 , L_12 , L_13 , L_14
} ;
V_4 -> type = V_154 ;
V_4 -> V_46 = 1 ;
V_4 -> V_14 . V_15 . V_155 = 4 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 4 )
V_4 -> V_14 . V_15 . V_16 = 3 ;
strcpy ( V_4 -> V_14 . V_15 . V_36 , V_153 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_200 ;
V_200 = F_102 ( V_6 , 0x1d , 0 , V_201 ,
V_202 ) ;
if ( ! ( V_200 & 0x80 ) )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
else {
V_200 = F_102 ( V_6 , 0x0b , 0 ,
V_203 , 0 ) ;
if ( V_200 < 3 )
V_200 ++ ;
else
V_200 = 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_200 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_204 , V_200 ;
int V_103 ;
V_204 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
if ( V_204 > 3 )
return - V_157 ;
if ( ! V_204 ) {
V_200 = F_102 ( V_6 , 0x1d , 0 ,
V_201 ,
V_202 ) ;
V_103 = V_200 & 0x80 ;
if ( V_103 ) {
F_58 ( V_6 , 0x1d , 0 ,
V_170 ,
F_104 ( 0 ) ) ;
F_58 ( V_6 , 0x1d , 0 ,
V_170 ,
F_105 ( 1 ) ) ;
}
} else {
V_200 = F_102 ( V_6 , 0x1d , 0 ,
V_201 ,
V_202 | 0x01 ) ;
V_103 = V_200 & 0x80 ;
if ( V_103 ) {
F_58 ( V_6 , 0x1d , 0 ,
V_170 ,
F_105 ( 0 ) ) ;
F_58 ( V_6 , 0x1d , 0 ,
V_170 ,
F_104 ( 1 ) ) ;
}
V_200 = F_102 ( V_6 , 0x0b , 0 ,
V_203 , 0 ) + 1 ;
V_103 |= V_200 != V_204 ;
if ( V_103 )
F_58 ( V_6 , 0x0b , 0 ,
V_94 ,
V_204 - 1 ) ;
}
return V_103 ;
}
static void F_106 ( struct V_5 * V_6 , unsigned int V_95 )
{
if ( ( V_95 >> 26 ) != V_205 )
return;
if ( F_60 ( V_6 , 0x11 ) )
F_9 ( V_6 , V_206 ) ;
else
F_9 ( V_6 , V_207 ) ;
}
static int F_107 ( struct V_7 * V_8 , int type , const char * V_36 ,
unsigned long V_204 )
{
struct V_31 * V_32 ;
F_108 ( & V_8 -> V_81 , sizeof( * V_32 ) , 32 ) ;
V_32 = F_109 ( & V_8 -> V_81 ) ;
if ( ! V_32 )
return - V_37 ;
* V_32 = V_208 [ type ] ;
V_32 -> V_36 = F_110 ( V_36 , V_107 ) ;
if ( ! V_32 -> V_36 )
return - V_37 ;
if ( F_111 ( V_204 ) )
V_32 -> V_209 = V_210 ;
V_32 -> V_38 = V_204 ;
return 0 ;
}
static inline T_1 F_112 ( struct V_5 * V_6 , int V_211 )
{
static const T_1 V_212 [ 8 ] = {
0x04 , 0x06 , 0x05 , 0x04 , 0x0a , 0x06 , 0x05 , 0x0a
} ;
static const T_1 V_213 [ 8 ] = {
0x04 , 0x05 , 0x0a , 0x04 , 0x06 , 0x05 , 0x0a , 0x06
} ;
if ( F_113 ( V_6 ) )
return V_213 [ V_211 ] ;
else
return V_212 [ V_211 ] ;
}
static int F_114 ( T_1 V_49 )
{
static const T_1 V_214 [ 8 ] = {
0x11 , 0x14 , 0x15 , 0x12 , 0x17 , 0x16 , 0x24 , 0x25
} ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_80 ( V_214 ) ; V_19 ++ )
if ( V_214 [ V_19 ] == V_49 )
return V_19 ;
return 0 ;
}
static int F_115 ( T_1 V_49 )
{
static const int V_215 [ 8 ] = {
2 , 0 , 1 , 3 , 4 , 5 , 1 , 4
} ;
switch ( V_49 ) {
case V_216 :
return 6 ;
default:
return V_215 [ F_114 ( V_49 ) ] ;
}
}
static int F_116 ( T_1 V_49 )
{
static const int V_12 [ 8 ] = {
0 , 1 , 2 , 8 , 4 , 3 , 6 , 7
} ;
switch ( V_49 ) {
case V_216 :
return 5 ;
default:
return V_12 [ F_114 ( V_49 ) ] ;
}
}
static int F_117 ( struct V_5 * V_6 ,
const struct V_217 * V_218 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 , V_211 ;
V_8 -> V_26 . V_69 = V_8 -> V_219 ;
for ( V_19 = 0 ; V_19 < V_218 -> V_220 ; V_19 ++ ) {
V_211 = F_114 ( V_218 -> V_221 [ V_19 ] ) ;
V_8 -> V_219 [ V_19 ] = F_112 ( V_6 , V_211 ) ;
}
V_8 -> V_26 . V_108 = V_218 -> V_220 ;
return 0 ;
}
static int F_118 ( struct V_7 * V_8 ,
const struct V_217 * V_218 )
{
char V_36 [ 32 ] ;
static const char * const V_222 [ 4 ] = {
L_15 , L_16 , NULL , L_17
} ;
T_1 V_49 ;
int V_19 , V_23 ;
for ( V_19 = 0 ; V_19 < V_218 -> V_220 ; V_19 ++ ) {
T_1 V_223 = V_8 -> V_26 . V_69 [ V_19 ] ;
if ( ! V_223 )
continue;
V_49 = V_224 [ F_114 ( V_218 -> V_221 [ V_19 ] ) ] ;
if ( V_19 == 2 ) {
V_23 = F_107 ( V_8 , V_225 ,
L_18 ,
F_119 ( V_223 , 1 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_107 ( V_8 , V_225 ,
L_19 ,
F_119 ( V_223 , 2 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_107 ( V_8 , V_226 ,
L_20 ,
F_119 ( V_49 , 1 , 2 , V_189 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_107 ( V_8 , V_226 ,
L_21 ,
F_119 ( V_49 , 2 , 2 , V_189 ) ) ;
if ( V_23 < 0 )
return V_23 ;
} else {
sprintf ( V_36 , L_22 , V_222 [ V_19 ] ) ;
V_23 = F_107 ( V_8 , V_225 , V_36 ,
F_119 ( V_223 , 3 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
sprintf ( V_36 , L_23 , V_222 [ V_19 ] ) ;
V_23 = F_107 ( V_8 , V_226 , V_36 ,
F_119 ( V_49 , 3 , 2 , V_189 ) ) ;
if ( V_23 < 0 )
return V_23 ;
}
}
return 0 ;
}
static int F_120 ( struct V_5 * V_6 , T_1 V_227 ,
const char * V_228 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_49 ;
int V_19 , V_211 , V_23 ;
char V_36 [ 32 ] ;
if ( ! V_227 )
return 0 ;
V_211 = F_114 ( V_227 ) ;
V_49 = F_112 ( V_6 , V_211 ) ;
for ( V_19 = 0 ; V_19 < V_8 -> V_229 . V_220 ; V_19 ++ ) {
T_1 V_227 = V_8 -> V_229 . V_221 [ V_19 ] ;
T_1 V_223 = F_112 ( V_6 , F_114 ( V_227 ) ) ;
if ( V_223 == V_49 )
break;
}
if ( V_19 >= V_8 -> V_229 . V_220 ) {
if ( ! V_8 -> V_26 . V_230 )
V_8 -> V_26 . V_230 = V_49 ;
else
V_8 -> V_26 . V_231 [ 0 ] = V_49 ;
sprintf ( V_36 , L_22 , V_228 ) ;
V_23 = F_107 ( V_8 , V_225 , V_36 ,
F_119 ( V_49 , 3 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_49 = V_224 [ V_211 ] ;
sprintf ( V_36 , L_23 , V_228 ) ;
if ( ( V_23 = F_107 ( V_8 , V_226 , V_36 ,
F_119 ( V_49 , 3 , 2 , V_189 ) ) ) < 0 )
return V_23 ;
return 0 ;
}
static int F_121 ( struct V_7 * V_8 , T_1 V_227 ,
const char * V_232 , int V_233 , int V_234 )
{
char V_36 [ 32 ] ;
int V_23 , V_211 ;
sprintf ( V_36 , L_22 , V_232 ) ;
V_211 = F_115 ( V_227 ) ;
if ( ( V_23 = F_107 ( V_8 , V_225 , V_36 ,
F_119 ( 0x20 , 3 , V_211 , V_189 ) ) ) < 0 )
return V_23 ;
sprintf ( V_36 , L_23 , V_232 ) ;
if ( ( V_23 = F_107 ( V_8 , V_235 , V_36 ,
F_119 ( 0x20 , 3 , V_211 , V_189 ) ) ) < 0 )
return V_23 ;
if ( V_234 ) {
T_1 V_236 ;
V_211 = F_114 ( V_227 ) ;
V_236 = V_237 [ V_211 ] ;
if ( V_236 ) {
sprintf ( V_36 , L_24 , V_232 ) ;
return F_107 ( V_8 , V_225 , V_36 ,
F_119 ( V_236 , 3 , V_211 , V_41 ) ) ;
}
}
return 0 ;
}
static int F_122 ( struct V_5 * V_6 ,
const struct V_217 * V_218 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_238 * V_239 = & V_8 -> V_240 ;
int V_19 , V_23 , type , V_241 ;
for ( V_19 = 0 ; V_19 < V_218 -> V_242 ; V_19 ++ ) {
const char * V_243 ;
type = V_218 -> V_244 [ V_19 ] . type ;
V_243 = F_123 ( V_6 , V_218 , V_19 ) ;
F_124 ( V_239 , V_243 ,
F_116 ( V_218 -> V_244 [ V_19 ] . V_227 ) ,
& V_241 ) ;
V_23 = F_121 ( V_8 , V_218 -> V_244 [ V_19 ] . V_227 ,
V_243 , V_241 ,
type == V_245 ) ;
if ( V_23 < 0 )
return V_23 ;
}
F_124 ( V_239 , L_25 , 9 , NULL ) ;
if ( ( V_23 = F_107 ( V_8 , V_225 ,
L_26 ,
F_119 ( 0x21 , 3 , 0x0 , V_41 ) ) ) < 0 )
return V_23 ;
if ( ( V_23 = F_107 ( V_8 , V_235 ,
L_27 ,
F_119 ( 0x21 , 3 , 0x0 , V_41 ) ) ) < 0 )
return V_23 ;
return 0 ;
}
static void F_125 ( struct V_5 * V_6 ,
T_1 V_49 , int V_246 ,
int V_247 )
{
F_49 ( V_6 , V_49 , 0 , V_166 , V_246 ) ;
F_49 ( V_6 , V_49 , 0 , V_170 , V_248 ) ;
switch ( V_49 ) {
case 0x11 :
F_49 ( V_6 , 0x37 , 0 , V_94 , 0x01 ) ;
break;
case 0x14 :
F_49 ( V_6 , 0x30 , 0 , V_94 , 0x02 ) ;
break;
case 0x15 :
F_49 ( V_6 , 0x31 , 0 , V_94 , 0x00 ) ;
break;
case 0x17 :
F_49 ( V_6 , 0x32 , 0 , V_94 , 0x01 ) ;
break;
case 0x13 :
F_49 ( V_6 , 0x36 , 0 , V_94 , 0x01 ) ;
break;
}
}
static void F_126 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_229 . V_220 ; V_19 ++ ) {
T_1 V_49 = V_8 -> V_229 . V_221 [ V_19 ] ;
F_125 ( V_6 , V_49 , V_167 , V_19 ) ;
}
}
static void F_127 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_227 ;
V_227 = V_8 -> V_229 . V_249 [ 0 ] ;
if ( V_227 )
F_125 ( V_6 , V_227 , V_167 , 0 ) ;
V_227 = V_8 -> V_229 . V_250 [ 0 ] ;
if ( V_227 )
F_125 ( V_6 , V_227 , V_251 , 0 ) ;
}
static void F_128 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_217 * V_218 = & V_8 -> V_229 ;
int V_19 , V_211 ;
for ( V_19 = 0 ; V_19 < V_218 -> V_242 ; V_19 ++ ) {
T_1 V_49 = V_218 -> V_244 [ V_19 ] . V_227 ;
int type = V_218 -> V_244 [ V_19 ] . type ;
switch ( V_49 ) {
case 0x15 :
F_49 ( V_6 , 0x33 , 0 , V_94 , 0x0 ) ;
break;
case 0x17 :
F_49 ( V_6 , 0x34 , 0 , V_94 , 0x0 ) ;
break;
}
F_49 ( V_6 , V_49 , 0 , V_166 ,
type == V_245 ? V_252 : V_253 ) ;
if ( V_49 != V_216 )
F_49 ( V_6 , V_49 , 0 , V_170 ,
V_254 ) ;
V_211 = F_114 ( V_49 ) ;
if ( V_237 [ V_211 ] )
F_49 ( V_6 , V_237 [ V_211 ] , 0 ,
V_170 ,
V_255 ) ;
}
}
static int F_129 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_23 ;
if ( ( V_23 = F_130 ( V_6 , & V_8 -> V_229 , NULL ) ) < 0 )
return V_23 ;
if ( ( V_23 = F_117 ( V_6 , & V_8 -> V_229 ) ) < 0 )
return V_23 ;
if ( ! V_8 -> V_229 . V_220 )
return 0 ;
if ( ( V_23 = F_118 ( V_8 , & V_8 -> V_229 ) ) < 0 ||
( V_23 = F_120 ( V_6 ,
V_8 -> V_229 . V_249 [ 0 ] ,
L_28 ) ) < 0 ||
( V_23 = F_120 ( V_6 , V_8 -> V_229 . V_250 [ 0 ] ,
L_29 ) ) < 0 ||
( V_23 = F_122 ( V_6 , & V_8 -> V_229 ) ) < 0 )
return V_23 ;
V_8 -> V_26 . V_68 = V_8 -> V_26 . V_108 * 2 ;
if ( V_8 -> V_229 . V_256 )
V_8 -> V_26 . V_27 = V_257 ;
if ( V_8 -> V_229 . V_258 )
V_8 -> V_29 = V_259 ;
if ( V_8 -> V_81 . V_82 )
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_8 -> V_81 . V_82 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_260 ;
V_8 -> V_9 = & V_8 -> V_240 ;
return 1 ;
}
static int F_131 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_126 ( V_6 ) ;
F_127 ( V_6 ) ;
F_128 ( V_6 ) ;
return 0 ;
}
static int F_132 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_106 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
if ( F_113 ( V_6 ) )
F_133 ( V_261 L_30 ) ;
V_106 = F_82 ( V_6 , V_262 ,
V_263 , V_264 ) ;
if ( V_106 < 0 ) {
F_134 ( V_261 L_31 ,
V_6 -> V_265 ) ;
V_106 = V_266 ;
}
if ( V_106 == V_266 ) {
V_23 = F_129 ( V_6 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
} else if ( ! V_23 ) {
F_134 ( V_261 L_32 ) ;
V_106 = V_267 ;
}
}
V_23 = F_78 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
}
F_79 ( V_8 , 0x10 , 0 , V_41 ) ;
switch ( V_106 ) {
case V_267 :
case V_268 :
case V_269 :
V_8 -> V_26 . V_68 = 8 ;
V_8 -> V_26 . V_108 = 4 ;
if ( F_113 ( V_6 ) )
V_8 -> V_26 . V_69 = V_270 ;
else
V_8 -> V_26 . V_69 = V_271 ;
V_8 -> V_9 = & V_272 ;
V_8 -> V_24 = 2 ;
if ( F_113 ( V_6 ) )
V_8 -> V_25 [ 0 ] = V_273 ;
else
V_8 -> V_25 [ 0 ] = V_274 ;
V_8 -> V_25 [ 1 ] = V_275 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_260 ;
if ( V_106 == V_269 ) {
V_8 -> V_24 ++ ;
V_8 -> V_25 [ 2 ] = V_276 ;
V_8 -> V_20 ++ ;
V_8 -> V_21 [ 1 ] = V_277 ;
V_8 -> V_42 = V_278 ;
V_8 -> V_44 = V_279 ;
V_8 -> V_78 = V_280 ;
V_8 -> V_79 =
& V_281 ;
}
if ( ( V_106 == V_268 ) ||
( V_106 == V_269 ) ) {
V_8 -> V_26 . V_27 = V_257 ;
V_8 -> V_29 = V_259 ;
}
break;
case V_282 :
case V_283 :
V_8 -> V_26 . V_68 = 6 ;
V_8 -> V_26 . V_108 = 3 ;
if ( F_113 ( V_6 ) )
V_8 -> V_26 . V_69 = V_284 ;
else
V_8 -> V_26 . V_69 = V_285 ;
V_8 -> V_9 = & V_272 ;
V_8 -> V_126 = V_286 ;
V_8 -> V_128 = F_80 ( V_286 ) ;
V_8 -> V_24 = 2 ;
if ( F_113 ( V_6 ) )
V_8 -> V_25 [ 0 ] = V_287 ;
else
V_8 -> V_25 [ 0 ] = V_288 ;
V_8 -> V_25 [ 1 ] = V_289 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_290 ;
if ( V_106 == V_283 )
V_8 -> V_26 . V_27 = V_257 ;
break;
case V_291 :
case V_292 :
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
V_8 -> V_26 . V_69 = V_285 ;
V_8 -> V_9 = & V_293 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_294 ;
V_8 -> V_88 = 1 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_295 ;
if ( V_106 == V_292 )
V_8 -> V_26 . V_27 = V_257 ;
break;
}
V_8 -> V_73 = F_80 ( V_296 ) ;
V_8 -> V_57 = V_296 ;
V_8 -> V_18 = V_297 ;
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_298 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_299 ;
if ( V_8 -> V_26 . V_27 ) {
if ( V_6 -> V_89 >= 0x11d4989a ) {
V_8 -> V_25 [ V_8 -> V_24 ++ ] =
V_300 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_301 ;
V_6 -> V_302 = V_303 ;
} else {
V_8 -> V_25 [ V_8 -> V_24 ++ ] =
V_304 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_305 ;
}
}
if ( V_8 -> V_29 && V_6 -> V_89 < 0x11d4989a ) {
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_306 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_307 ;
}
V_6 -> V_118 = V_119 ;
switch ( V_106 ) {
case V_266 :
V_6 -> V_118 . V_143 = F_131 ;
break;
case V_291 :
case V_292 :
V_6 -> V_118 . V_142 = F_106 ;
break;
}
#ifdef F_81
V_8 -> V_50 . V_116 = V_308 ;
#endif
V_8 -> V_40 = 0x04 ;
V_6 -> V_151 = 1 ;
V_6 -> V_152 = 1 ;
return 0 ;
}
static int F_135 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_78 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
}
F_79 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = F_80 ( V_309 ) ;
V_8 -> V_26 . V_69 = V_309 ;
V_8 -> V_26 . V_27 = V_310 ;
V_8 -> V_73 = F_80 ( V_311 ) ;
V_8 -> V_57 = V_311 ;
V_8 -> V_18 = V_312 ;
V_8 -> V_9 = & V_313 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_314 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_315 ;
V_8 -> V_156 = 0 ;
#ifdef F_81
V_8 -> V_50 . V_116 = V_316 ;
#endif
V_8 -> V_40 = 0x04 ;
V_8 -> V_42 = V_317 ;
V_6 -> V_118 = V_119 ;
V_6 -> V_151 = 1 ;
V_6 -> V_152 = 1 ;
return 0 ;
}
static int F_136 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
unsigned int V_55 ,
unsigned int V_56 ,
struct V_53 * V_54 )
{
F_41 ( V_6 , 0x05 + V_54 -> V_58 ,
V_55 , 0 , V_56 ) ;
return 0 ;
}
static int F_137 ( struct V_51 * V_52 ,
struct V_5 * V_6 ,
struct V_53 * V_54 )
{
F_43 ( V_6 , 0x05 + V_54 -> V_58 ) ;
return 0 ;
}
static int F_138 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_59 * V_60 ;
int V_23 ;
V_23 = F_44 ( V_6 ) ;
if ( V_23 < 0 )
return V_23 ;
V_60 = V_8 -> V_61 + V_6 -> V_62 ;
V_6 -> V_62 ++ ;
V_60 -> V_36 = L_33 ;
V_60 -> V_64 [ V_70 ] = V_318 ;
return 0 ;
}
static int F_139 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_106 , V_23 ;
V_23 = F_135 ( V_6 ) ;
if ( V_23 < 0 )
return V_23 ;
V_8 = V_6 -> V_8 ;
V_106 = F_82 ( V_6 , V_319 ,
V_320 , V_321 ) ;
switch ( V_106 ) {
case V_322 :
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_323 ;
V_6 -> V_118 . V_324 = F_138 ;
break;
case V_325 :
if ( V_6 -> V_326 == 0x17aa20fb ) {
V_8 -> V_26 . V_27 = 0 ;
} else
V_8 -> V_26 . V_27 = V_310 ;
V_8 -> V_9 = & V_327 ;
V_8 -> V_25 [ 0 ] = V_328 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_329 ;
V_8 -> V_33 = 1 ;
break;
case V_330 :
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_331 ;
V_8 -> V_25 [ 0 ] = V_332 ;
break;
}
return 0 ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_333 = F_141 ( V_2 , V_11 ) ;
int V_97 = ( ! V_11 -> V_14 . integer . V_14 [ 0 ] &&
! V_11 -> V_14 . integer . V_14 [ 1 ] ) ;
F_58 ( V_6 , 0x01 , 0 , V_334 ,
V_97 ? 0x02 : 0x0 ) ;
return V_333 ;
}
static void F_142 ( struct V_5 * V_6 )
{
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x11 ) ;
F_65 ( V_6 , 0x16 , V_41 , 0 ,
V_99 , V_93 ? V_99 : 0 ) ;
F_49 ( V_6 , 0x16 , 0 , V_87 ,
V_93 ? 0x00 : 0x02 ) ;
}
static void F_143 ( struct V_5 * V_6 )
{
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x14 ) ;
F_49 ( V_6 , 0x0c , 0 , V_94 ,
V_93 ? 0 : 1 ) ;
}
static void F_144 ( struct V_5 * V_6 , unsigned int V_95 )
{
switch ( V_95 >> 26 ) {
case V_335 :
F_142 ( V_6 ) ;
break;
case V_336 :
F_143 ( V_6 ) ;
break;
}
}
static int F_145 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_142 ( V_6 ) ;
F_143 ( V_6 ) ;
return 0 ;
}
static void F_146 ( struct V_5 * V_6 )
{
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x11 ) ;
if ( ! V_93 )
V_93 = F_60 ( V_6 , 0x12 ) ;
F_65 ( V_6 , 0x16 , V_41 , 0 ,
V_99 , V_93 ? V_99 : 0 ) ;
F_49 ( V_6 , 0x16 , 0 , V_87 ,
V_93 ? 0x00 : 0x02 ) ;
}
static void F_147 ( struct V_5 * V_6 )
{
unsigned int V_211 ;
if ( F_60 ( V_6 , 0x14 ) )
V_211 = 0 ;
else if ( F_60 ( V_6 , 0x1c ) )
V_211 = 4 ;
else
V_211 = 1 ;
F_49 ( V_6 , 0x0c , 0 , V_94 , V_211 ) ;
}
static void F_148 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
switch ( V_95 >> 26 ) {
case V_335 :
F_146 ( V_6 ) ;
break;
case V_336 :
F_147 ( V_6 ) ;
break;
}
}
static int F_149 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_146 ( V_6 ) ;
F_147 ( V_6 ) ;
return 0 ;
}
static void F_150 ( struct V_5 * V_6 )
{
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x11 ) ;
F_65 ( V_6 , 0x12 , V_41 , 0 ,
V_99 , V_93 ? V_99 : 0 ) ;
}
static void F_151 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
if ( ( V_95 >> 26 ) != V_335 )
return;
F_150 ( V_6 ) ;
}
static int F_152 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_150 ( V_6 ) ;
return 0 ;
}
static void F_153 ( struct V_5 * V_6 )
{
unsigned int V_93 ;
V_93 = F_60 ( V_6 , 0x12 ) ;
F_65 ( V_6 , 0x13 , V_41 , 0 ,
V_99 , V_93 ? V_99 : 0 ) ;
}
static void F_154 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
if ( ( V_95 >> 26 ) != V_335 )
return;
F_153 ( V_6 ) ;
}
static int F_155 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_153 ( V_6 ) ;
return 0 ;
}
static void F_156 ( struct V_5 * V_6 )
{
if ( F_60 ( V_6 , 0x1c ) )
F_49 ( V_6 , 0x0c , 0 ,
V_94 , 0x4 ) ;
else
F_49 ( V_6 , 0x0c , 0 ,
V_94 , 0x5 ) ;
}
static void F_157 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
switch ( V_95 >> 26 ) {
case V_335 :
F_142 ( V_6 ) ;
break;
case V_336 :
F_156 ( V_6 ) ;
break;
}
}
static int F_158 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_142 ( V_6 ) ;
F_156 ( V_6 ) ;
return 0 ;
}
static int F_159 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_106 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_78 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
}
F_79 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = F_80 ( V_337 ) ;
V_8 -> V_26 . V_69 = V_337 ;
V_8 -> V_26 . V_27 = V_338 ;
V_8 -> V_73 = F_80 ( V_339 ) ;
V_8 -> V_57 = V_339 ;
V_8 -> V_18 = V_340 ;
V_8 -> V_9 = & V_341 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_342 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_343 ;
V_8 -> V_156 = 0 ;
#ifdef F_81
V_8 -> V_50 . V_116 = V_344 ;
#endif
V_6 -> V_118 = V_119 ;
V_106 = F_82 ( V_6 , V_345 ,
V_346 ,
V_347 ) ;
switch ( V_106 ) {
case V_348 :
V_8 -> V_25 [ 0 ] = V_349 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_350 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_118 . V_142 = F_148 ;
V_6 -> V_118 . V_143 = F_149 ;
F_93 ( V_6 , 0x20 , V_189 ,
( 0x17 << V_190 ) |
( 0x17 << V_191 ) |
( 0x05 << V_192 ) |
( 1 << V_193 ) ) ;
break;
case V_351 :
V_8 -> V_25 [ 0 ] = V_352 ;
V_8 -> V_21 [ 0 ] = V_353 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_118 . V_142 = F_144 ;
V_6 -> V_118 . V_143 = F_145 ;
F_93 ( V_6 , 0x20 , V_189 ,
( 0x17 << V_190 ) |
( 0x17 << V_191 ) |
( 0x05 << V_192 ) |
( 1 << V_193 ) ) ;
break;
case V_354 :
V_8 -> V_25 [ 0 ] = V_355 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_356 ;
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_357 ;
V_6 -> V_118 . V_142 = F_151 ;
V_6 -> V_118 . V_143 = F_152 ;
break;
case V_358 :
V_8 -> V_25 [ 0 ] = V_359 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_360 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_118 . V_142 = F_154 ;
V_6 -> V_118 . V_143 = F_155 ;
break;
case V_361 :
V_8 -> V_25 [ 0 ] = V_362 ;
V_8 -> V_21 [ 0 ] = V_363 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_118 . V_142 = F_157 ;
V_6 -> V_118 . V_143 = F_158 ;
F_93 ( V_6 , 0x20 , V_189 ,
( 0x17 << V_190 ) |
( 0x17 << V_191 ) |
( 0x05 << V_192 ) |
( 1 << V_193 ) ) ;
break;
}
V_6 -> V_151 = 1 ;
V_6 -> V_152 = 1 ;
return 0 ;
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_106 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_78 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_53 ( V_6 ) ;
return V_23 ;
}
F_79 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_68 = 6 ;
V_8 -> V_26 . V_108 = 3 ;
V_8 -> V_26 . V_69 = V_364 ;
V_8 -> V_26 . V_27 = V_365 ;
V_8 -> V_73 = F_80 ( V_366 ) ;
V_8 -> V_57 = V_366 ;
V_8 -> V_18 = V_367 ;
if ( V_6 -> V_89 == 0x11d41882 )
V_8 -> V_9 = & V_368 ;
else
V_8 -> V_9 = & V_369 ;
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 0 ] = V_370 ;
if ( V_6 -> V_89 == 0x11d41882 )
V_8 -> V_25 [ 1 ] = V_371 ;
else
V_8 -> V_25 [ 1 ] = V_372 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_373 ;
V_8 -> V_156 = 0 ;
#ifdef F_81
V_8 -> V_50 . V_116 = V_374 ;
#endif
V_8 -> V_40 = 0x04 ;
V_6 -> V_118 = V_119 ;
V_106 = F_82 ( V_6 , V_375 ,
V_376 , NULL ) ;
switch ( V_106 ) {
default:
case V_377 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 2 ] = V_378 ;
V_8 -> V_126 = V_379 ;
V_8 -> V_128 = F_80 ( V_379 ) ;
V_8 -> V_129 = 1 ;
V_8 -> V_26 . V_68 = 2 ;
V_8 -> V_26 . V_108 = 1 ;
break;
case V_380 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 2 ] = V_381 ;
break;
}
V_6 -> V_151 = 1 ;
V_6 -> V_152 = 1 ;
return 0 ;
}
static int T_3 F_161 ( void )
{
return F_162 ( & V_382 ) ;
}
static void T_4 F_163 ( void )
{
F_164 ( & V_382 ) ;
}
