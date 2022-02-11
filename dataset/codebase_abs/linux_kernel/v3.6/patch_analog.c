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
V_8 -> V_42 : V_43 ) ,
L_2 ,
! V_8 -> V_44 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
}
if ( ! F_18 ( V_6 , L_3 ) ) {
V_23 = F_21 ( V_6 , L_3 ,
NULL ,
( V_8 -> V_45 ?
V_8 -> V_45 : V_43 ) ,
L_4 ) ;
if ( V_23 < 0 )
return V_23 ;
}
F_22 ( V_6 ) ;
V_22 = F_18 ( V_6 , L_5 ) ;
if ( ! V_22 )
V_22 = F_18 ( V_6 , L_6 ) ;
for ( V_19 = 0 ; V_22 && V_19 < V_22 -> V_46 ; V_19 ++ ) {
V_23 = F_23 ( V_6 , V_22 , V_19 , V_8 -> V_18 [ V_19 ] ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_22 = F_18 ( V_6 ,
F_24 ( L_7 , V_47 , V_48 ) L_8 ) ;
if ( V_22 ) {
V_23 = F_23 ( V_6 , V_22 , 0 ,
V_8 -> V_26 . V_27 ) ;
if ( V_23 < 0 )
return V_23 ;
}
return 0 ;
}
static int F_25 ( struct V_5 * V_6 , T_1 V_49 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_26 ( V_6 , & V_8 -> V_50 , V_49 ) ;
}
static void F_27 ( struct V_5 * V_6 , const char * V_36 , int V_51 )
{
struct V_1 * V_52 = F_18 ( V_6 , V_36 ) ;
if ( V_52 ) {
V_52 -> V_53 [ 0 ] . V_54 &= ~ V_55 ;
V_52 -> V_53 [ 0 ] . V_54 |= V_51 ? 0 :
V_55 ;
V_52 -> V_53 [ 0 ] . V_54 &= ~ V_56 ;
V_52 -> V_53 [ 0 ] . V_54 |= V_51 ?
V_56 : 0 ;
F_28 ( V_6 -> V_57 -> V_58 ,
V_59 , & V_52 -> V_13 ) ;
}
}
static void F_29 ( struct V_5 * V_6 , bool V_51 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_51 )
V_8 -> V_60 ++ ;
else
V_8 -> V_60 -- ;
F_27 ( V_6 , L_9 , V_8 -> V_60 == 0 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_61 [] = { L_10 , L_11 , NULL } ;
int V_62 ;
V_4 -> type = V_63 ;
V_4 -> V_46 = 1 ;
V_4 -> V_14 . V_15 . V_64 = 2 ;
V_62 = V_4 -> V_14 . V_15 . V_16 ;
if ( V_62 >= 2 )
V_62 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_36 , V_61 [ V_62 ] ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_65 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_66 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
if ( V_8 -> V_65 != V_66 ) {
V_8 -> V_65 = V_66 ;
if ( V_8 -> V_65 )
V_8 -> V_26 . V_67 = 0 ;
else
V_8 -> V_26 . V_67 = V_8 -> V_68 [ 0 ] ;
return 1 ;
}
return 0 ;
}
static int F_33 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_23 ;
F_29 ( V_6 , true ) ;
V_23 = F_34 ( V_6 , & V_8 -> V_26 , V_72 ,
V_70 ) ;
if ( V_23 < 0 ) {
F_29 ( V_6 , false ) ;
return V_23 ;
}
return 0 ;
}
static int F_35 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
unsigned int V_73 ,
unsigned int V_74 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_36 ( V_6 , & V_8 -> V_26 , V_73 ,
V_74 , V_72 ) ;
}
static int F_37 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_38 ( V_6 , & V_8 -> V_26 ) ;
}
static int F_39 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
F_29 ( V_6 , false ) ;
return 0 ;
}
static int F_40 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 -> V_65 )
return - V_75 ;
F_29 ( V_6 , true ) ;
return 0 ;
}
static int F_41 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
F_29 ( V_6 , false ) ;
return 0 ;
}
static int F_42 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_43 ( V_6 , & V_8 -> V_26 ) ;
}
static int F_44 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_45 ( V_6 , & V_8 -> V_26 ) ;
}
static int F_46 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
unsigned int V_73 ,
unsigned int V_74 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_47 ( V_6 , & V_8 -> V_26 , V_73 ,
V_74 , V_72 ) ;
}
static int F_48 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_49 ( V_6 , & V_8 -> V_26 ) ;
}
static int F_50 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
unsigned int V_73 ,
unsigned int V_74 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_51 ( V_6 , V_8 -> V_76 [ V_72 -> V_77 ] ,
V_73 , 0 , V_74 ) ;
return 0 ;
}
static int F_52 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_53 ( V_6 , V_8 -> V_76 [ V_72 -> V_77 ] ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_78 * V_79 = V_8 -> V_80 ;
V_6 -> V_81 = 1 ;
V_6 -> V_82 = V_79 ;
V_79 -> V_36 = L_12 ;
V_79 -> V_83 [ V_84 ] = V_85 ;
V_79 -> V_83 [ V_84 ] . V_86 = V_8 -> V_26 . V_87 ;
V_79 -> V_83 [ V_84 ] . V_49 = V_8 -> V_26 . V_88 [ 0 ] ;
V_79 -> V_83 [ V_89 ] = V_90 ;
V_79 -> V_83 [ V_89 ] . V_91 = V_8 -> V_92 ;
V_79 -> V_83 [ V_89 ] . V_49 = V_8 -> V_76 [ 0 ] ;
if ( V_8 -> V_26 . V_27 ) {
V_79 ++ ;
V_6 -> V_81 ++ ;
V_79 -> V_36 = L_13 ;
V_79 -> V_93 = V_94 ;
V_79 -> V_83 [ V_84 ] = V_95 ;
V_79 -> V_83 [ V_84 ] . V_49 = V_8 -> V_26 . V_27 ;
if ( V_8 -> V_29 ) {
V_79 -> V_83 [ V_89 ] = V_96 ;
V_79 -> V_83 [ V_89 ] . V_49 = V_8 -> V_29 ;
}
}
if ( V_8 -> V_68 && V_8 -> V_97 ) {
V_6 -> V_81 ++ ;
V_79 = V_8 -> V_80 + 2 ;
V_79 -> V_36 = L_14 ;
V_79 -> V_93 = V_98 ;
V_79 -> V_83 [ V_84 ] =
* V_8 -> V_97 ;
V_79 -> V_83 [ V_84 ] . V_49 =
V_8 -> V_68 [ 0 ] ;
}
return 0 ;
}
static void F_22 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_99 . V_100 ) {
struct V_31 * V_22 = V_8 -> V_99 . V_100 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_99 . V_101 ; V_19 ++ )
F_55 ( V_22 [ V_19 ] . V_36 ) ;
}
F_56 ( & V_8 -> V_99 ) ;
}
static void F_57 ( struct V_5 * V_6 , T_1 V_102 ,
T_1 V_103 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( F_58 ( V_6 , V_102 ) & V_104 )
F_59 ( V_6 , V_102 , 0 , V_105 ,
! V_8 -> V_106 ? 0x00 : 0x02 ) ;
if ( F_58 ( V_6 , V_103 ) & V_104 )
F_59 ( V_6 , V_103 , 0 , V_105 ,
! V_8 -> V_106 ? 0x00 : 0x02 ) ;
}
static void F_60 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_107 ) {
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
F_57 ( V_6 , 0x12 , 0x11 ) ;
break;
case 0x11d41981 :
case 0x11d41983 :
F_57 ( V_6 , 0x05 , 0x06 ) ;
break;
case 0x11d41986 :
F_57 ( V_6 , 0x1b , 0x1a ) ;
break;
}
}
static void F_61 ( struct V_5 * V_6 )
{
F_62 ( V_6 ) ;
F_60 ( V_6 ) ;
}
static void F_63 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_61 ( V_6 ) ;
F_22 ( V_6 ) ;
F_55 ( V_8 ) ;
F_64 ( V_6 ) ;
}
static int F_65 ( struct V_5 * V_6 )
{
F_61 ( V_6 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_106 )
V_11 -> V_14 . integer . V_14 [ 0 ] = ! V_8 -> V_108 ;
else
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_108 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_49 = V_2 -> V_38 & 0xff ;
unsigned int V_109 ;
V_109 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_106 )
V_109 = ! V_109 ;
if ( V_109 == V_8 -> V_108 )
return 0 ;
V_8 -> V_108 = V_109 ;
F_68 ( V_6 , V_49 ,
0 , V_105 ,
V_109 ? 0x02 : 0x00 ) ;
return 1 ;
}
static void F_69 ( struct V_5 * V_6 )
{
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x1f ) ;
F_59 ( V_6 , 0x0f , 0 , V_111 ,
V_110 ? 0 : 2 ) ;
}
static void F_71 ( struct V_5 * V_6 ,
unsigned int V_112 )
{
if ( ( V_112 >> 26 ) != V_113 )
return;
F_69 ( V_6 ) ;
}
static int F_72 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_69 ( V_6 ) ;
return 0 ;
}
static void F_73 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_114 ;
if ( V_8 -> V_115 )
V_114 = V_116 ;
else
V_114 = F_74 ( V_6 , 0x1a , 0 , V_41 , 0 ) ;
F_75 ( V_6 , 0x1b , V_41 , 0 ,
V_116 , V_114 ) ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_115 = F_70 ( V_6 , 0x1a ) ;
if ( V_8 -> V_117 )
V_8 -> V_115 = ! V_8 -> V_115 ;
F_73 ( V_6 ) ;
}
static void F_77 ( struct V_5 * V_6 , unsigned int V_112 )
{
if ( ( V_112 >> 26 ) != V_118 )
return;
F_76 ( V_6 ) ;
}
static int F_78 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_76 ( V_6 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
long * V_119 = V_11 -> V_14 . integer . V_14 ;
int V_120 ;
V_120 = F_80 ( V_6 , 0x1a , 0 , V_41 , 0 ,
V_116 ,
V_119 [ 0 ] ? 0 : V_116 ) ;
V_120 |= F_80 ( V_6 , 0x1a , 1 , V_41 , 0 ,
V_116 ,
V_119 [ 1 ] ? 0 : V_116 ) ;
if ( V_120 )
F_73 ( V_6 ) ;
return V_120 ;
}
static void F_81 ( struct V_5 * V_6 ,
unsigned int V_112 )
{
switch ( V_112 >> 26 ) {
case V_118 :
F_76 ( V_6 ) ;
break;
case V_113 :
F_69 ( V_6 ) ;
break;
}
}
static int F_82 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_76 ( V_6 ) ;
F_69 ( V_6 ) ;
return 0 ;
}
static int F_83 ( struct V_5 * V_6 , T_1 V_49 )
{
unsigned int V_121 = F_84 ( V_6 , V_49 ) ;
return F_85 ( V_121 ) != V_122 ;
}
static int F_86 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_123 ;
V_8 = F_87 ( sizeof( * V_8 ) , V_124 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_88 ( V_6 , 0x19 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
}
F_89 ( V_8 , 0x18 , 0 , V_41 ) ;
V_8 -> V_26 . V_87 = 6 ;
V_8 -> V_26 . V_125 = F_90 ( V_126 ) ;
V_8 -> V_26 . V_88 = V_126 ;
V_8 -> V_26 . V_27 = V_127 ;
V_8 -> V_92 = 1 ;
V_8 -> V_76 = V_128 ;
V_8 -> V_18 = V_129 ;
V_8 -> V_9 = & V_130 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_131 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_132 ;
#ifdef F_91
V_8 -> V_50 . V_133 = V_134 ;
#endif
V_8 -> V_40 = 0x1b ;
V_8 -> V_106 = 1 ;
V_6 -> V_135 = V_136 ;
V_123 = F_92 ( V_6 , V_137 ,
V_138 ,
V_139 ) ;
switch ( V_123 ) {
case V_140 :
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 1 ] = V_141 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_142 ;
V_8 -> V_143 = V_144 ;
V_8 -> V_145 = F_90 ( V_144 ) ;
V_8 -> V_146 = 1 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
break;
case V_147 :
V_8 -> V_25 [ 0 ] = V_148 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
V_8 -> V_26 . V_88 = V_149 ;
break;
case V_150 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 0 ] = V_151 ;
V_8 -> V_25 [ 1 ] = V_152 ;
V_8 -> V_25 [ 2 ] = V_153 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_154 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
V_8 -> V_26 . V_88 = V_149 ;
if ( ! F_83 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_155 ;
break;
case V_156 :
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 0 ] = V_151 ;
V_8 -> V_25 [ 1 ] = V_152 ;
V_8 -> V_20 = 3 ;
V_8 -> V_21 [ 1 ] = V_154 ;
V_8 -> V_21 [ 2 ] = V_157 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
V_8 -> V_26 . V_88 = V_149 ;
if ( ! F_83 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_158 ;
V_6 -> V_135 . V_159 = F_71 ;
V_6 -> V_135 . V_160 = F_72 ;
break;
case V_161 :
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 0 ] = V_162 ;
V_8 -> V_25 [ 1 ] = V_152 ;
V_8 -> V_20 = 4 ;
V_8 -> V_21 [ 1 ] = V_154 ;
V_8 -> V_21 [ 2 ] = V_157 ;
V_8 -> V_21 [ 3 ] = V_163 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
V_8 -> V_26 . V_88 = V_149 ;
if ( ! F_83 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_158 ;
V_6 -> V_135 . V_159 = F_81 ;
V_6 -> V_135 . V_160 = F_82 ;
break;
case V_164 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 0 ] = V_162 ;
V_8 -> V_25 [ 1 ] = V_152 ;
V_8 -> V_25 [ 2 ] = V_153 ;
V_8 -> V_20 = 3 ;
V_8 -> V_21 [ 1 ] = V_154 ;
V_8 -> V_21 [ 2 ] = V_163 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
V_8 -> V_26 . V_88 = V_149 ;
if ( ! F_83 ( V_6 , 0x25 ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_155 ;
V_6 -> V_135 . V_159 = F_77 ;
V_6 -> V_135 . V_160 = F_78 ;
V_8 -> V_117 = 1 ;
break;
case V_165 :
V_8 -> V_25 [ 0 ] = V_152 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_166 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
V_8 -> V_26 . V_88 = V_149 ;
V_8 -> V_26 . V_27 = 0 ;
break;
}
V_8 -> V_26 . V_167 = 1 ;
V_6 -> V_168 = 1 ;
V_6 -> V_169 = 1 ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static const char * const V_61 [] = { L_15 , L_16 } ;
V_4 -> type = V_63 ;
V_4 -> V_46 = 1 ;
V_4 -> V_14 . V_15 . V_64 = 2 ;
if ( V_4 -> V_14 . V_15 . V_16 > 1 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_36 , V_61 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_170 ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] > 1 )
return - V_171 ;
if ( V_8 -> V_170 != V_11 -> V_14 . V_15 . V_16 [ 0 ] ) {
V_8 -> V_170 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
F_68 ( V_6 , V_8 -> V_26 . V_27 , 0 ,
V_111 ,
V_8 -> V_170 ) ;
return 1 ;
}
return 0 ;
}
static int F_96 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_87 ( sizeof( * V_8 ) , V_124 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_88 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
}
F_89 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = F_90 ( V_172 ) ;
V_8 -> V_26 . V_88 = V_172 ;
V_8 -> V_26 . V_27 = V_173 ;
V_8 -> V_92 = 1 ;
V_8 -> V_76 = V_174 ;
V_8 -> V_18 = V_175 ;
V_8 -> V_9 = & V_176 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_177 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_178 ;
V_8 -> V_170 = 0 ;
#ifdef F_91
V_8 -> V_50 . V_133 = V_179 ;
#endif
V_8 -> V_40 = 0x05 ;
V_6 -> V_135 = V_136 ;
V_6 -> V_168 = 1 ;
V_6 -> V_169 = 1 ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_67 ( V_2 , V_11 ) )
return 0 ;
F_98 ( V_6 , 0x05 , V_8 -> V_108 ? V_180 : 0 ) ;
F_75 ( V_6 , 0x06 , V_41 , 0 ,
V_116 ,
V_8 -> V_108 ? 0 : V_116 ) ;
return 1 ;
}
static void F_99 ( struct V_5 * V_6 )
{
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x06 ) ;
F_75 ( V_6 , 0x05 , V_41 , 0 ,
V_116 , V_110 ? V_116 : 0 ) ;
}
static void F_100 ( struct V_5 * V_6 )
{
static const struct V_181 V_182 [] = {
{ 0x1f , V_183 , 0xb080 } ,
{ 0x1e , V_183 , 0xb000 } ,
{}
} ;
static const struct V_181 V_184 [] = {
{ 0x1e , V_183 , 0xb080 } ,
{ 0x1f , V_183 , 0xb000 } ,
{}
} ;
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x08 ) ;
if ( V_110 )
F_9 ( V_6 , V_182 ) ;
else
F_9 ( V_6 , V_184 ) ;
}
static void F_101 ( struct V_5 * V_6 ,
unsigned int V_112 )
{
V_112 >>= 26 ;
switch ( V_112 ) {
case V_185 :
F_99 ( V_6 ) ;
break;
case V_186 :
F_100 ( V_6 ) ;
break;
}
}
static int F_102 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_99 ( V_6 ) ;
F_100 ( V_6 ) ;
return 0 ;
}
static int F_103 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_123 ;
V_8 = F_87 ( sizeof( * V_8 ) , V_124 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_88 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
}
F_89 ( V_8 , 0x0d , 0 , V_41 ) ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = F_90 ( V_187 ) ;
V_8 -> V_26 . V_88 = V_187 ;
V_8 -> V_26 . V_27 = V_188 ;
V_8 -> V_92 = 1 ;
V_8 -> V_76 = V_189 ;
V_8 -> V_18 = V_190 ;
V_8 -> V_9 = & V_191 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_192 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_193 ;
V_8 -> V_170 = 0 ;
#ifdef F_91
V_8 -> V_50 . V_133 = V_194 ;
#endif
V_8 -> V_40 = 0x05 ;
V_6 -> V_135 = V_136 ;
V_123 = F_92 ( V_6 , V_195 ,
V_196 ,
V_197 ) ;
switch ( V_123 ) {
case V_198 :
V_8 -> V_25 [ 0 ] = V_199 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_200 ;
if ( ! F_83 ( V_6 , 0x0a ) )
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_201 ;
V_6 -> V_135 . V_160 = F_102 ;
V_6 -> V_135 . V_159 = F_101 ;
F_104 ( V_6 , 0x11 , V_202 ,
( 0x17 << V_203 ) |
( 0x17 << V_204 ) |
( 0x05 << V_205 ) |
( 1 << V_206 ) ) ;
break;
case V_207 :
V_8 -> V_25 [ 0 ] = V_208 ;
V_8 -> V_9 = & V_209 ;
F_104 ( V_6 , 0x11 , V_202 ,
( 0x17 << V_203 ) |
( 0x17 << V_204 ) |
( 0x05 << V_205 ) |
( 1 << V_206 ) ) ;
break;
case V_210 :
V_8 -> V_25 [ 0 ] = V_199 ;
V_8 -> V_25 [ 1 ] = V_211 ;
V_8 -> V_20 = 2 ;
V_8 -> V_21 [ 1 ] = V_212 ;
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_201 ;
V_6 -> V_135 . V_160 = F_102 ;
V_6 -> V_135 . V_159 = F_101 ;
break;
}
V_6 -> V_168 = 1 ;
V_6 -> V_169 = 1 ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_106 ( V_6 , V_4 , V_8 -> V_143 ,
V_8 -> V_145 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_108 ( V_6 , V_11 , V_8 -> V_143 ,
V_8 -> V_145 , V_8 -> V_26 . V_87 ) ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_23 = F_110 ( V_6 , V_11 , V_8 -> V_143 ,
V_8 -> V_145 ,
& V_8 -> V_26 . V_87 ) ;
if ( V_23 >= 0 && V_8 -> V_146 )
V_8 -> V_26 . V_125 = V_8 -> V_26 . V_87 / 2 ;
return V_23 ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_61 [] = {
L_15 , L_17 , L_18 , L_19
} ;
V_4 -> type = V_63 ;
V_4 -> V_46 = 1 ;
V_4 -> V_14 . V_15 . V_64 = 4 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 4 )
V_4 -> V_14 . V_15 . V_16 = 3 ;
strcpy ( V_4 -> V_14 . V_15 . V_36 , V_61 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_213 ;
V_213 = F_113 ( V_6 , 0x1d , 0 , V_214 ,
V_215 ) ;
if ( ! ( V_213 & 0x80 ) )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
else {
V_213 = F_113 ( V_6 , 0x0b , 0 ,
V_216 , 0 ) ;
if ( V_213 < 3 )
V_213 ++ ;
else
V_213 = 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_213 ;
}
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_217 , V_213 ;
int V_120 ;
V_217 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
if ( V_217 > 3 )
return - V_171 ;
if ( ! V_217 ) {
V_213 = F_113 ( V_6 , 0x1d , 0 ,
V_214 ,
V_215 ) ;
V_120 = V_213 & 0x80 ;
if ( V_120 ) {
F_68 ( V_6 , 0x1d , 0 ,
V_183 ,
F_115 ( 0 ) ) ;
F_68 ( V_6 , 0x1d , 0 ,
V_183 ,
F_116 ( 1 ) ) ;
}
} else {
V_213 = F_113 ( V_6 , 0x1d , 0 ,
V_214 ,
V_215 | 0x01 ) ;
V_120 = V_213 & 0x80 ;
if ( V_120 ) {
F_68 ( V_6 , 0x1d , 0 ,
V_183 ,
F_116 ( 0 ) ) ;
F_68 ( V_6 , 0x1d , 0 ,
V_183 ,
F_115 ( 1 ) ) ;
}
V_213 = F_113 ( V_6 , 0x0b , 0 ,
V_216 , 0 ) + 1 ;
V_120 |= V_213 != V_217 ;
if ( V_120 )
F_68 ( V_6 , 0x0b , 0 ,
V_111 ,
V_217 - 1 ) ;
}
return V_120 ;
}
static void F_117 ( struct V_5 * V_6 , unsigned int V_112 )
{
if ( ( V_112 >> 26 ) != V_218 )
return;
if ( F_70 ( V_6 , 0x11 ) )
F_9 ( V_6 , V_219 ) ;
else
F_9 ( V_6 , V_220 ) ;
}
static int F_118 ( struct V_7 * V_8 , int type , const char * V_36 ,
unsigned long V_217 )
{
struct V_31 * V_32 ;
F_119 ( & V_8 -> V_99 , sizeof( * V_32 ) , 32 ) ;
V_32 = F_120 ( & V_8 -> V_99 ) ;
if ( ! V_32 )
return - V_37 ;
* V_32 = V_221 [ type ] ;
V_32 -> V_36 = F_121 ( V_36 , V_124 ) ;
if ( ! V_32 -> V_36 )
return - V_37 ;
if ( F_122 ( V_217 ) )
V_32 -> V_222 = V_223 ;
V_32 -> V_38 = V_217 ;
return 0 ;
}
static inline T_1 F_123 ( struct V_5 * V_6 , int V_224 )
{
static const T_1 V_225 [ 8 ] = {
0x03 , 0x06 , 0x05 , 0x04 , 0x0a , 0x06 , 0x05 , 0x0a
} ;
static const T_1 V_226 [ 8 ] = {
0x03 , 0x05 , 0x0a , 0x04 , 0x06 , 0x05 , 0x0a , 0x06
} ;
if ( F_124 ( V_6 ) )
return V_226 [ V_224 ] ;
else
return V_225 [ V_224 ] ;
}
static int F_125 ( T_1 V_49 )
{
static const T_1 V_227 [ 8 ] = {
0x11 , 0x14 , 0x15 , 0x12 , 0x17 , 0x16 , 0x24 , 0x25
} ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_90 ( V_227 ) ; V_19 ++ )
if ( V_227 [ V_19 ] == V_49 )
return V_19 ;
return 0 ;
}
static int F_126 ( T_1 V_49 )
{
static const int V_228 [ 8 ] = {
2 , 0 , 1 , 3 , 4 , 5 , 1 , 4
} ;
switch ( V_49 ) {
case V_229 :
return 6 ;
default:
return V_228 [ F_125 ( V_49 ) ] ;
}
}
static int F_127 ( T_1 V_49 )
{
static const int V_12 [ 8 ] = {
0 , 1 , 2 , 8 , 4 , 3 , 6 , 7
} ;
switch ( V_49 ) {
case V_229 :
return 5 ;
default:
return V_12 [ F_125 ( V_49 ) ] ;
}
}
static int F_128 ( struct V_5 * V_6 ,
const struct V_230 * V_231 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 , V_224 ;
V_8 -> V_26 . V_88 = V_8 -> V_232 ;
for ( V_19 = 0 ; V_19 < V_231 -> V_233 ; V_19 ++ ) {
V_224 = F_125 ( V_231 -> V_234 [ V_19 ] ) ;
V_8 -> V_232 [ V_19 ] = F_123 ( V_6 , V_224 ) ;
}
V_8 -> V_26 . V_125 = V_231 -> V_233 ;
return 0 ;
}
static int F_129 ( struct V_7 * V_8 ,
const struct V_230 * V_231 )
{
char V_36 [ 32 ] ;
static const char * const V_235 [ 4 ] = {
L_20 , L_21 , NULL , L_22
} ;
T_1 V_49 ;
int V_19 , V_23 ;
for ( V_19 = 0 ; V_19 < V_231 -> V_233 ; V_19 ++ ) {
T_1 V_236 = V_8 -> V_26 . V_88 [ V_19 ] ;
if ( ! V_236 )
continue;
V_49 = V_237 [ F_125 ( V_231 -> V_234 [ V_19 ] ) ] ;
if ( V_19 == 2 ) {
V_23 = F_118 ( V_8 , V_238 ,
L_23 ,
F_130 ( V_236 , 1 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_118 ( V_8 , V_238 ,
L_24 ,
F_130 ( V_236 , 2 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_118 ( V_8 , V_239 ,
L_25 ,
F_130 ( V_49 , 1 , 2 , V_202 ) ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_118 ( V_8 , V_239 ,
L_26 ,
F_130 ( V_49 , 2 , 2 , V_202 ) ) ;
if ( V_23 < 0 )
return V_23 ;
} else {
sprintf ( V_36 , L_27 , V_235 [ V_19 ] ) ;
V_23 = F_118 ( V_8 , V_238 , V_36 ,
F_130 ( V_236 , 3 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
sprintf ( V_36 , L_28 , V_235 [ V_19 ] ) ;
V_23 = F_118 ( V_8 , V_239 , V_36 ,
F_130 ( V_49 , 3 , 2 , V_202 ) ) ;
if ( V_23 < 0 )
return V_23 ;
}
}
return 0 ;
}
static int F_131 ( struct V_5 * V_6 , T_1 V_240 ,
const char * V_241 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_49 ;
int V_19 , V_224 , V_23 ;
char V_36 [ 32 ] ;
if ( ! V_240 )
return 0 ;
V_224 = F_125 ( V_240 ) ;
V_49 = F_123 ( V_6 , V_224 ) ;
for ( V_19 = 0 ; V_19 < V_8 -> V_242 . V_233 ; V_19 ++ ) {
T_1 V_240 = V_8 -> V_242 . V_234 [ V_19 ] ;
T_1 V_236 = F_123 ( V_6 , F_125 ( V_240 ) ) ;
if ( V_236 == V_49 )
break;
}
if ( V_19 >= V_8 -> V_242 . V_233 ) {
if ( ! V_8 -> V_26 . V_67 )
V_8 -> V_26 . V_67 = V_49 ;
else
V_8 -> V_26 . V_243 [ 0 ] = V_49 ;
sprintf ( V_36 , L_27 , V_241 ) ;
V_23 = F_118 ( V_8 , V_238 , V_36 ,
F_130 ( V_49 , 3 , 0 , V_41 ) ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_49 = V_237 [ V_224 ] ;
sprintf ( V_36 , L_28 , V_241 ) ;
if ( ( V_23 = F_118 ( V_8 , V_239 , V_36 ,
F_130 ( V_49 , 3 , 2 , V_202 ) ) ) < 0 )
return V_23 ;
return 0 ;
}
static int F_132 ( struct V_7 * V_8 , T_1 V_240 ,
const char * V_244 , int V_245 , int V_246 )
{
char V_36 [ 32 ] ;
int V_23 , V_224 ;
sprintf ( V_36 , L_27 , V_244 ) ;
V_224 = F_126 ( V_240 ) ;
if ( ( V_23 = F_118 ( V_8 , V_238 , V_36 ,
F_130 ( 0x20 , 3 , V_224 , V_202 ) ) ) < 0 )
return V_23 ;
sprintf ( V_36 , L_28 , V_244 ) ;
if ( ( V_23 = F_118 ( V_8 , V_247 , V_36 ,
F_130 ( 0x20 , 3 , V_224 , V_202 ) ) ) < 0 )
return V_23 ;
if ( V_246 ) {
T_1 V_248 ;
V_224 = F_125 ( V_240 ) ;
V_248 = V_249 [ V_224 ] ;
if ( V_248 ) {
sprintf ( V_36 , L_29 , V_244 ) ;
return F_118 ( V_8 , V_238 , V_36 ,
F_130 ( V_248 , 3 , V_224 , V_41 ) ) ;
}
}
return 0 ;
}
static int F_133 ( struct V_5 * V_6 ,
const struct V_230 * V_231 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_250 * V_251 = & V_8 -> V_252 ;
int V_19 , V_23 , type , V_253 ;
for ( V_19 = 0 ; V_19 < V_231 -> V_254 ; V_19 ++ ) {
const char * V_255 ;
type = V_231 -> V_256 [ V_19 ] . type ;
V_255 = F_134 ( V_6 , V_231 , V_19 ) ;
F_135 ( V_251 , V_255 ,
F_127 ( V_231 -> V_256 [ V_19 ] . V_240 ) ,
& V_253 ) ;
V_23 = F_132 ( V_8 , V_231 -> V_256 [ V_19 ] . V_240 ,
V_255 , V_253 ,
type == V_257 ) ;
if ( V_23 < 0 )
return V_23 ;
}
F_135 ( V_251 , L_30 , 9 , NULL ) ;
if ( ( V_23 = F_118 ( V_8 , V_238 ,
L_31 ,
F_130 ( 0x21 , 3 , 0x0 , V_41 ) ) ) < 0 )
return V_23 ;
if ( ( V_23 = F_118 ( V_8 , V_247 ,
L_32 ,
F_130 ( 0x21 , 3 , 0x0 , V_41 ) ) ) < 0 )
return V_23 ;
return 0 ;
}
static void F_136 ( struct V_5 * V_6 ,
T_1 V_49 , int V_258 ,
int V_259 )
{
F_98 ( V_6 , V_49 , V_258 ) ;
F_59 ( V_6 , V_49 , 0 , V_183 , V_260 ) ;
switch ( V_49 ) {
case 0x11 :
F_59 ( V_6 , 0x37 , 0 , V_111 , 0x00 ) ;
break;
case 0x14 :
F_59 ( V_6 , 0x30 , 0 , V_111 , 0x02 ) ;
break;
case 0x15 :
F_59 ( V_6 , 0x31 , 0 , V_111 , 0x00 ) ;
break;
case 0x17 :
F_59 ( V_6 , 0x32 , 0 , V_111 , 0x01 ) ;
break;
case 0x13 :
F_59 ( V_6 , 0x36 , 0 , V_111 , 0x01 ) ;
break;
}
}
static void F_137 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_8 -> V_242 . V_233 ; V_19 ++ ) {
T_1 V_49 = V_8 -> V_242 . V_234 [ V_19 ] ;
F_136 ( V_6 , V_49 , V_180 , V_19 ) ;
}
}
static void F_138 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_240 ;
V_240 = V_8 -> V_242 . V_261 [ 0 ] ;
if ( V_240 )
F_136 ( V_6 , V_240 , V_180 , 0 ) ;
V_240 = V_8 -> V_242 . V_262 [ 0 ] ;
if ( V_240 )
F_136 ( V_6 , V_240 , V_263 , 0 ) ;
}
static void F_139 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_230 * V_231 = & V_8 -> V_242 ;
int V_19 , V_224 ;
for ( V_19 = 0 ; V_19 < V_231 -> V_254 ; V_19 ++ ) {
T_1 V_49 = V_231 -> V_256 [ V_19 ] . V_240 ;
int type = V_231 -> V_256 [ V_19 ] . type ;
int V_217 ;
switch ( V_49 ) {
case 0x15 :
F_59 ( V_6 , 0x33 , 0 , V_111 , 0x0 ) ;
break;
case 0x17 :
F_59 ( V_6 , 0x34 , 0 , V_111 , 0x0 ) ;
break;
}
V_217 = V_264 ;
if ( type == V_257 )
V_217 |= F_140 ( V_6 , V_49 ) ;
F_98 ( V_6 , V_49 , V_217 ) ;
if ( V_49 != V_229 )
F_59 ( V_6 , V_49 , 0 , V_183 ,
V_265 ) ;
V_224 = F_125 ( V_49 ) ;
if ( V_249 [ V_224 ] )
F_59 ( V_6 , V_249 [ V_224 ] , 0 ,
V_183 ,
V_266 ) ;
}
}
static int F_141 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_23 ;
if ( ( V_23 = F_142 ( V_6 , & V_8 -> V_242 , NULL ) ) < 0 )
return V_23 ;
if ( ( V_23 = F_128 ( V_6 , & V_8 -> V_242 ) ) < 0 )
return V_23 ;
if ( ! V_8 -> V_242 . V_233 )
return 0 ;
if ( ( V_23 = F_129 ( V_8 , & V_8 -> V_242 ) ) < 0 ||
( V_23 = F_131 ( V_6 ,
V_8 -> V_242 . V_261 [ 0 ] ,
L_33 ) ) < 0 ||
( V_23 = F_131 ( V_6 , V_8 -> V_242 . V_262 [ 0 ] ,
L_34 ) ) < 0 ||
( V_23 = F_133 ( V_6 , & V_8 -> V_242 ) ) < 0 )
return V_23 ;
V_8 -> V_26 . V_87 = V_8 -> V_26 . V_125 * 2 ;
if ( V_8 -> V_242 . V_267 )
V_8 -> V_26 . V_27 = V_268 ;
if ( V_8 -> V_242 . V_269 )
V_8 -> V_29 = V_270 ;
if ( V_8 -> V_99 . V_100 )
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_8 -> V_99 . V_100 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_271 ;
V_8 -> V_9 = & V_8 -> V_252 ;
return 1 ;
}
static int F_143 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_137 ( V_6 ) ;
F_138 ( V_6 ) ;
F_139 ( V_6 ) ;
return 0 ;
}
static int F_144 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_123 ;
V_8 = F_87 ( sizeof( * V_8 ) , V_124 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
if ( F_124 ( V_6 ) )
F_145 ( V_272 L_35 ) ;
V_123 = F_92 ( V_6 , V_273 ,
V_274 , V_275 ) ;
if ( V_123 < 0 ) {
F_146 ( V_272 L_36 ,
V_6 -> V_276 ) ;
V_123 = V_277 ;
}
if ( V_123 == V_277 ) {
V_23 = F_141 ( V_6 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
} else if ( ! V_23 ) {
F_146 ( V_272 L_37 ) ;
V_123 = V_278 ;
}
}
V_23 = F_88 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
}
F_89 ( V_8 , 0x10 , 0 , V_41 ) ;
if ( ! V_8 -> V_26 . V_67 )
V_8 -> V_26 . V_67 = V_279 [ 0 ] ;
switch ( V_123 ) {
case V_278 :
case V_280 :
V_8 -> V_26 . V_87 = 8 ;
V_8 -> V_26 . V_125 = 4 ;
if ( F_124 ( V_6 ) )
V_8 -> V_26 . V_88 = V_281 ;
else
V_8 -> V_26 . V_88 = V_282 ;
V_8 -> V_9 = & V_283 ;
V_8 -> V_24 = 2 ;
if ( F_124 ( V_6 ) )
V_8 -> V_25 [ 0 ] = V_284 ;
else
V_8 -> V_25 [ 0 ] = V_285 ;
V_8 -> V_25 [ 1 ] = V_286 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_271 ;
if ( V_123 == V_280 ) {
V_8 -> V_26 . V_27 = V_268 ;
V_8 -> V_29 = V_270 ;
}
break;
case V_287 :
case V_288 :
V_8 -> V_26 . V_87 = 6 ;
V_8 -> V_26 . V_125 = 3 ;
if ( F_124 ( V_6 ) )
V_8 -> V_26 . V_88 = V_289 ;
else
V_8 -> V_26 . V_88 = V_290 ;
V_8 -> V_9 = & V_283 ;
V_8 -> V_143 = V_291 ;
V_8 -> V_145 = F_90 ( V_291 ) ;
V_8 -> V_24 = 2 ;
if ( F_124 ( V_6 ) )
V_8 -> V_25 [ 0 ] = V_292 ;
else
V_8 -> V_25 [ 0 ] = V_293 ;
V_8 -> V_25 [ 1 ] = V_294 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_295 ;
if ( V_123 == V_288 )
V_8 -> V_26 . V_27 = V_268 ;
break;
case V_296 :
case V_297 :
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
V_8 -> V_26 . V_88 = V_290 ;
V_8 -> V_9 = & V_298 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_299 ;
V_8 -> V_106 = 1 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_300 ;
if ( V_123 == V_297 )
V_8 -> V_26 . V_27 = V_268 ;
break;
}
if ( V_8 -> V_242 . V_262 [ 0 ] ) {
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_301 ;
V_8 -> V_42 = V_302 ;
V_8 -> V_45 = V_302 ;
V_8 -> V_68 = V_279 ;
V_8 -> V_97 =
& V_303 ;
}
V_8 -> V_92 = F_90 ( V_304 ) ;
V_8 -> V_76 = V_304 ;
V_8 -> V_18 = V_305 ;
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_306 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_307 ;
if ( V_8 -> V_26 . V_27 ) {
if ( V_6 -> V_107 >= 0x11d4989a ) {
V_8 -> V_25 [ V_8 -> V_24 ++ ] =
V_308 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_309 ;
V_6 -> V_310 = V_311 ;
} else {
V_8 -> V_25 [ V_8 -> V_24 ++ ] =
V_312 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_313 ;
}
}
if ( V_8 -> V_29 && V_6 -> V_107 < 0x11d4989a ) {
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_314 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_315 ;
}
V_6 -> V_135 = V_136 ;
switch ( V_123 ) {
case V_277 :
V_6 -> V_135 . V_160 = F_143 ;
break;
case V_296 :
case V_297 :
V_6 -> V_135 . V_159 = F_117 ;
break;
}
#ifdef F_91
V_8 -> V_50 . V_133 = V_316 ;
#endif
V_8 -> V_40 = 0x04 ;
V_6 -> V_168 = 1 ;
V_6 -> V_169 = 1 ;
return 0 ;
}
static int F_147 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 ;
V_8 = F_87 ( sizeof( * V_8 ) , V_124 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_88 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
}
F_89 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = F_90 ( V_317 ) ;
V_8 -> V_26 . V_88 = V_317 ;
V_8 -> V_26 . V_27 = V_318 ;
V_8 -> V_92 = F_90 ( V_319 ) ;
V_8 -> V_76 = V_319 ;
V_8 -> V_18 = V_320 ;
V_8 -> V_9 = & V_321 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_322 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_323 ;
V_8 -> V_170 = 0 ;
#ifdef F_91
V_8 -> V_50 . V_133 = V_324 ;
#endif
V_8 -> V_40 = 0x04 ;
V_8 -> V_42 = V_325 ;
V_8 -> V_44 = 1 ;
V_6 -> V_135 = V_136 ;
V_6 -> V_168 = 1 ;
V_6 -> V_169 = 1 ;
return 0 ;
}
static int F_148 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
unsigned int V_73 ,
unsigned int V_74 ,
struct V_71 * V_72 )
{
F_51 ( V_6 , 0x05 + V_72 -> V_77 ,
V_73 , 0 , V_74 ) ;
return 0 ;
}
static int F_149 ( struct V_69 * V_70 ,
struct V_5 * V_6 ,
struct V_71 * V_72 )
{
F_53 ( V_6 , 0x05 + V_72 -> V_77 ) ;
return 0 ;
}
static int F_150 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_78 * V_79 ;
int V_23 ;
V_23 = F_54 ( V_6 ) ;
if ( V_23 < 0 )
return V_23 ;
V_79 = V_8 -> V_80 + V_6 -> V_81 ;
V_6 -> V_81 ++ ;
V_79 -> V_36 = L_38 ;
V_79 -> V_83 [ V_89 ] = V_326 ;
return 0 ;
}
static int F_151 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_123 , V_23 ;
V_23 = F_147 ( V_6 ) ;
if ( V_23 < 0 )
return V_23 ;
V_8 = V_6 -> V_8 ;
V_123 = F_92 ( V_6 , V_327 ,
V_328 , V_329 ) ;
switch ( V_123 ) {
case V_330 :
V_8 -> V_25 [ V_8 -> V_24 ++ ] = V_331 ;
V_6 -> V_135 . V_332 = F_150 ;
break;
case V_333 :
if ( V_6 -> V_334 == 0x17aa20fb ) {
V_8 -> V_26 . V_27 = 0 ;
} else
V_8 -> V_26 . V_27 = V_318 ;
V_8 -> V_9 = & V_335 ;
V_8 -> V_25 [ 0 ] = V_336 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_337 ;
V_8 -> V_33 = 1 ;
break;
case V_338 :
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_339 ;
V_8 -> V_25 [ 0 ] = V_340 ;
break;
}
return 0 ;
}
static int F_152 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_341 = F_153 ( V_2 , V_11 ) ;
int V_114 = ( ! V_11 -> V_14 . integer . V_14 [ 0 ] &&
! V_11 -> V_14 . integer . V_14 [ 1 ] ) ;
F_68 ( V_6 , 0x01 , 0 , V_342 ,
V_114 ? 0x02 : 0x0 ) ;
return V_341 ;
}
static void F_154 ( struct V_5 * V_6 )
{
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x11 ) ;
F_75 ( V_6 , 0x16 , V_41 , 0 ,
V_116 , V_110 ? V_116 : 0 ) ;
F_59 ( V_6 , 0x16 , 0 , V_105 ,
V_110 ? 0x00 : 0x02 ) ;
}
static void F_155 ( struct V_5 * V_6 )
{
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x14 ) ;
F_59 ( V_6 , 0x0c , 0 , V_111 ,
V_110 ? 0 : 1 ) ;
}
static void F_156 ( struct V_5 * V_6 , unsigned int V_112 )
{
switch ( V_112 >> 26 ) {
case V_343 :
F_154 ( V_6 ) ;
break;
case V_344 :
F_155 ( V_6 ) ;
break;
}
}
static int F_157 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_154 ( V_6 ) ;
F_155 ( V_6 ) ;
return 0 ;
}
static void F_158 ( struct V_5 * V_6 )
{
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x11 ) ;
if ( ! V_110 )
V_110 = F_70 ( V_6 , 0x12 ) ;
F_75 ( V_6 , 0x16 , V_41 , 0 ,
V_116 , V_110 ? V_116 : 0 ) ;
F_59 ( V_6 , 0x16 , 0 , V_105 ,
V_110 ? 0x00 : 0x02 ) ;
}
static void F_159 ( struct V_5 * V_6 )
{
unsigned int V_224 ;
if ( F_70 ( V_6 , 0x14 ) )
V_224 = 0 ;
else if ( F_70 ( V_6 , 0x1c ) )
V_224 = 4 ;
else
V_224 = 1 ;
F_59 ( V_6 , 0x0c , 0 , V_111 , V_224 ) ;
}
static void F_160 ( struct V_5 * V_6 ,
unsigned int V_112 )
{
switch ( V_112 >> 26 ) {
case V_343 :
F_158 ( V_6 ) ;
break;
case V_344 :
F_159 ( V_6 ) ;
break;
}
}
static int F_161 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_158 ( V_6 ) ;
F_159 ( V_6 ) ;
return 0 ;
}
static void F_162 ( struct V_5 * V_6 )
{
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x11 ) ;
F_75 ( V_6 , 0x12 , V_41 , 0 ,
V_116 , V_110 ? V_116 : 0 ) ;
}
static void F_163 ( struct V_5 * V_6 ,
unsigned int V_112 )
{
if ( ( V_112 >> 26 ) != V_343 )
return;
F_162 ( V_6 ) ;
}
static int F_164 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_162 ( V_6 ) ;
return 0 ;
}
static void F_165 ( struct V_5 * V_6 )
{
unsigned int V_110 ;
V_110 = F_70 ( V_6 , 0x12 ) ;
F_75 ( V_6 , 0x13 , V_41 , 0 ,
V_116 , V_110 ? V_116 : 0 ) ;
}
static void F_166 ( struct V_5 * V_6 ,
unsigned int V_112 )
{
if ( ( V_112 >> 26 ) != V_343 )
return;
F_165 ( V_6 ) ;
}
static int F_167 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_165 ( V_6 ) ;
return 0 ;
}
static void F_168 ( struct V_5 * V_6 )
{
if ( F_70 ( V_6 , 0x1c ) )
F_59 ( V_6 , 0x0c , 0 ,
V_111 , 0x4 ) ;
else
F_59 ( V_6 , 0x0c , 0 ,
V_111 , 0x5 ) ;
}
static void F_169 ( struct V_5 * V_6 ,
unsigned int V_112 )
{
switch ( V_112 >> 26 ) {
case V_343 :
F_154 ( V_6 ) ;
break;
case V_344 :
F_168 ( V_6 ) ;
break;
}
}
static int F_170 ( struct V_5 * V_6 )
{
F_8 ( V_6 ) ;
F_154 ( V_6 ) ;
F_168 ( V_6 ) ;
return 0 ;
}
static int F_171 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_123 ;
V_8 = F_87 ( sizeof( * V_8 ) , V_124 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_88 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
}
F_89 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = F_90 ( V_345 ) ;
V_8 -> V_26 . V_88 = V_345 ;
V_8 -> V_26 . V_27 = V_346 ;
V_8 -> V_92 = F_90 ( V_347 ) ;
V_8 -> V_76 = V_347 ;
V_8 -> V_18 = V_348 ;
V_8 -> V_9 = & V_349 ;
V_8 -> V_24 = 1 ;
V_8 -> V_25 [ 0 ] = V_350 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_351 ;
V_8 -> V_170 = 0 ;
#ifdef F_91
V_8 -> V_50 . V_133 = V_352 ;
#endif
V_6 -> V_135 = V_136 ;
V_123 = F_92 ( V_6 , V_353 ,
V_354 ,
V_355 ) ;
switch ( V_123 ) {
case V_356 :
V_8 -> V_25 [ 0 ] = V_357 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] = V_358 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_135 . V_159 = F_160 ;
V_6 -> V_135 . V_160 = F_161 ;
F_104 ( V_6 , 0x20 , V_202 ,
( 0x17 << V_203 ) |
( 0x17 << V_204 ) |
( 0x05 << V_205 ) |
( 1 << V_206 ) ) ;
break;
case V_359 :
V_8 -> V_25 [ 0 ] = V_360 ;
V_8 -> V_21 [ 0 ] = V_361 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_135 . V_159 = F_156 ;
V_6 -> V_135 . V_160 = F_157 ;
F_104 ( V_6 , 0x20 , V_202 ,
( 0x17 << V_203 ) |
( 0x17 << V_204 ) |
( 0x05 << V_205 ) |
( 1 << V_206 ) ) ;
break;
case V_362 :
V_8 -> V_25 [ 0 ] = V_363 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_364 ;
V_8 -> V_26 . V_27 = 0 ;
V_8 -> V_9 = & V_365 ;
V_6 -> V_135 . V_159 = F_163 ;
V_6 -> V_135 . V_160 = F_164 ;
break;
case V_366 :
V_8 -> V_25 [ 0 ] = V_367 ;
V_8 -> V_21 [ V_8 -> V_20 ++ ] =
V_368 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_135 . V_159 = F_166 ;
V_6 -> V_135 . V_160 = F_167 ;
break;
case V_369 :
V_8 -> V_25 [ 0 ] = V_370 ;
V_8 -> V_21 [ 0 ] = V_371 ;
V_8 -> V_26 . V_27 = 0 ;
V_6 -> V_135 . V_159 = F_169 ;
V_6 -> V_135 . V_160 = F_170 ;
F_104 ( V_6 , 0x20 , V_202 ,
( 0x17 << V_203 ) |
( 0x17 << V_204 ) |
( 0x05 << V_205 ) |
( 1 << V_206 ) ) ;
break;
}
V_6 -> V_168 = 1 ;
V_6 -> V_169 = 1 ;
return 0 ;
}
static int F_172 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_23 , V_123 ;
V_8 = F_87 ( sizeof( * V_8 ) , V_124 ) ;
if ( V_8 == NULL )
return - V_37 ;
V_6 -> V_8 = V_8 ;
V_23 = F_88 ( V_6 , 0x10 ) ;
if ( V_23 < 0 ) {
F_63 ( V_6 ) ;
return V_23 ;
}
F_89 ( V_8 , 0x10 , 0 , V_41 ) ;
V_8 -> V_26 . V_87 = 6 ;
V_8 -> V_26 . V_125 = 3 ;
V_8 -> V_26 . V_88 = V_372 ;
V_8 -> V_26 . V_27 = V_373 ;
V_8 -> V_92 = F_90 ( V_374 ) ;
V_8 -> V_76 = V_374 ;
V_8 -> V_18 = V_375 ;
if ( V_6 -> V_107 == 0x11d41882 )
V_8 -> V_9 = & V_376 ;
else
V_8 -> V_9 = & V_377 ;
V_8 -> V_24 = 2 ;
V_8 -> V_25 [ 0 ] = V_378 ;
if ( V_6 -> V_107 == 0x11d41882 )
V_8 -> V_25 [ 1 ] = V_379 ;
else
V_8 -> V_25 [ 1 ] = V_380 ;
V_8 -> V_20 = 1 ;
V_8 -> V_21 [ 0 ] = V_381 ;
V_8 -> V_170 = 0 ;
#ifdef F_91
V_8 -> V_50 . V_133 = V_382 ;
#endif
V_8 -> V_40 = 0x04 ;
V_6 -> V_135 = V_136 ;
V_123 = F_92 ( V_6 , V_383 ,
V_384 , NULL ) ;
switch ( V_123 ) {
default:
case V_385 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 2 ] = V_386 ;
V_8 -> V_143 = V_387 ;
V_8 -> V_145 = F_90 ( V_387 ) ;
V_8 -> V_146 = 1 ;
V_8 -> V_26 . V_87 = 2 ;
V_8 -> V_26 . V_125 = 1 ;
break;
case V_388 :
V_8 -> V_24 = 3 ;
V_8 -> V_25 [ 2 ] = V_389 ;
break;
}
V_6 -> V_168 = 1 ;
V_6 -> V_169 = 1 ;
return 0 ;
}
static int T_2 F_173 ( void )
{
return F_174 ( & V_390 ) ;
}
static void T_3 F_175 ( void )
{
F_176 ( & V_390 ) ;
}
