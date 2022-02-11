static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , T_1 V_6 , T_2 V_7 )
{
struct V_8 V_9 ;
T_2 V_10 [ 3 ] ;
int V_11 ;
V_10 [ 0 ] = V_6 >> 8 ;
V_10 [ 1 ] = V_6 & 0xFF ;
V_10 [ 2 ] = V_7 ;
V_9 . V_12 = V_5 -> V_12 ;
V_9 . V_13 = V_5 -> V_13 ;
V_9 . V_10 = V_10 ;
V_9 . V_14 = sizeof( V_10 ) ;
V_11 = F_4 ( V_5 -> V_15 , & V_9 , 1 ) ;
if ( V_11 >= 0 )
return 0 ;
F_5 ( & V_5 -> V_16 ,
L_1 , V_6 , V_7 ) ;
return V_11 ;
}
static int F_6 ( struct V_4 * V_5 , T_1 V_6 , T_2 * V_7 )
{
struct V_8 V_9 [ 2 ] ;
T_2 V_10 [ 2 ] ;
int V_11 ;
V_10 [ 0 ] = V_6 >> 8 ;
V_10 [ 1 ] = V_6 & 0xFF ;
V_9 [ 0 ] . V_12 = V_5 -> V_12 ;
V_9 [ 0 ] . V_13 = V_5 -> V_13 ;
V_9 [ 0 ] . V_10 = V_10 ;
V_9 [ 0 ] . V_14 = sizeof( V_10 ) ;
V_9 [ 1 ] . V_12 = V_5 -> V_12 ;
V_9 [ 1 ] . V_13 = V_5 -> V_13 | V_17 ;
V_9 [ 1 ] . V_10 = V_10 ;
V_9 [ 1 ] . V_14 = 1 ;
V_11 = F_4 ( V_5 -> V_15 , V_9 , 2 ) ;
if ( V_11 >= 0 ) {
* V_7 = V_10 [ 0 ] ;
return 0 ;
}
F_5 ( & V_5 -> V_16 ,
L_2 , V_6 , * V_7 ) ;
return V_11 ;
}
static int F_7 ( struct V_4 * V_5 ,
const struct V_18 * V_19 )
{
int V_20 , V_11 = 0 ;
for ( V_20 = 0 ; V_11 == 0 && V_19 [ V_20 ] . V_12 ; V_20 ++ )
V_11 = F_3 ( V_5 , V_19 [ V_20 ] . V_12 , V_19 [ V_20 ] . V_21 ) ;
return V_11 ;
}
static void F_8 ( struct V_1 * V_1 )
{
const struct V_22 * V_23 = V_1 -> V_23 ;
T_2 V_24 = 0 , V_25 = 0 , V_26 = 0 ;
struct V_4 * V_5 = V_1 -> V_5 ;
unsigned int V_27 = V_23 -> V_28 ;
T_3 V_29 = 1 , V_30 = 1 , V_31 = 1 ;
T_3 V_32 , V_33 , V_34 ;
T_3 V_35 = - 1 ;
T_3 V_36 , V_37 ;
int V_20 , V_38 ;
for ( V_20 = 0 ; V_39 [ V_20 ] . div != 0 ; V_20 ++ ) {
V_33 = V_39 [ V_20 ] . div ;
for ( V_38 = 0 ; V_40 [ V_38 ] . div != 0 ; V_38 ++ ) {
V_32 = V_40 [ V_38 ] . div ;
for ( V_34 = 1 ; V_34 <= 63 ; V_34 ++ ) {
V_37 = V_1 -> V_41 ;
V_37 *= V_34 ;
V_37 /= V_32 ;
V_37 /= V_33 ;
V_36 = V_37 - V_27 ;
V_36 = abs ( V_36 ) ;
if ( ( V_36 < V_35 ) || ( V_35 == - 1 ) ) {
V_35 = V_36 ;
V_31 = V_34 ;
V_29 = V_32 ;
V_30 = V_33 ;
V_24 = V_39 [ V_20 ] . V_6 ;
V_25 = V_34 ;
V_26 = V_40 [ V_38 ] . V_6 ;
}
}
}
}
V_1 -> V_42 . V_39 = V_24 ;
V_1 -> V_42 . V_43 = V_25 ;
V_1 -> V_42 . V_40 = V_26 ;
F_5 ( & V_5 -> V_16 ,
L_3 ,
V_24 , V_25 , V_26 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_18 V_44 [] = {
{ V_45 , V_1 -> V_42 . V_39 } ,
{ V_46 , V_1 -> V_42 . V_43 } ,
{ V_47 , V_1 -> V_42 . V_40 } ,
{ V_48 , 0x00 } ,
} ;
F_5 ( & V_5 -> V_16 , L_4 , V_49 ) ;
return F_7 ( V_5 , V_44 ) ;
}
static void F_10 ( struct V_50 * V_51 )
{
V_51 -> V_52 = V_53 [ 2 ] . V_52 ;
V_51 -> V_54 = V_53 [ 2 ] . V_54 ;
V_51 -> V_55 = V_56 ;
V_51 -> V_57 = V_58 [ 0 ] . V_57 ;
V_51 -> V_59 = V_60 ;
}
static void F_11 ( struct V_1 * V_1 , int V_61 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_11 ;
V_61 = ! ! V_61 ;
F_5 ( & V_5 -> V_16 , L_5 , V_49 , V_61 ) ;
V_11 = F_3 ( V_5 , V_62 , V_61 ) ;
if ( V_11 )
F_12 ( & V_5 -> V_16 , L_6 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_3 V_7 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
return F_7 ( V_5 , V_63 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_66 * V_57 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
F_5 ( & V_5 -> V_16 , L_7 , V_49 ) ;
if ( V_57 -> V_67 >= F_16 ( V_58 ) )
return - V_68 ;
V_57 -> V_57 = V_58 [ V_57 -> V_67 ] . V_57 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_69 * V_70 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
int V_20 = F_16 ( V_58 ) ;
F_5 ( & V_5 -> V_16 , L_7 , V_49 ) ;
if ( V_70 -> V_67 >= F_16 ( V_53 ) )
return - V_68 ;
while ( -- V_20 )
if ( V_70 -> V_57 == V_58 [ V_20 ] . V_57 )
break;
V_70 -> V_57 = V_58 [ V_20 ] . V_57 ;
V_70 -> V_71 = V_53 [ V_70 -> V_67 ] . V_52 ;
V_70 -> V_72 = V_70 -> V_71 ;
V_70 -> V_73 = V_53 [ V_70 -> V_67 ] . V_54 ;
V_70 -> V_74 = V_70 -> V_73 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_75 * V_76 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_5 ( & V_5 -> V_16 , L_8 ) ;
if ( V_76 -> V_77 == V_78 ) {
#ifdef F_19
struct V_50 * V_79 ;
V_79 = F_20 ( V_3 , V_65 , 0 ) ;
F_21 ( & V_1 -> V_80 ) ;
V_76 -> V_51 = * V_79 ;
F_22 ( & V_1 -> V_80 ) ;
return 0 ;
#else
return - V_81 ;
#endif
}
F_21 ( & V_1 -> V_80 ) ;
V_76 -> V_51 = V_1 -> V_51 ;
F_22 ( & V_1 -> V_80 ) ;
F_5 ( & V_5 -> V_16 , L_9 ,
V_1 -> V_51 . V_57 , V_1 -> V_51 . V_52 ,
V_1 -> V_51 . V_54 ) ;
return 0 ;
}
static void F_23 ( struct V_50 * V_79 ,
const struct V_82 * * V_83 )
{
const struct V_82 * V_84 = & V_53 [ 0 ] ;
const struct V_82 * V_85 = NULL ;
int V_20 = F_16 ( V_53 ) ;
unsigned int V_86 = V_87 ;
while ( V_20 -- ) {
int V_88 = abs ( V_84 -> V_52 - V_79 -> V_52 )
+ abs ( V_84 -> V_54 - V_79 -> V_54 ) ;
if ( ( V_88 < V_86 ) && ( V_84 -> V_19 [ 0 ] . V_12 ) ) {
V_86 = V_88 ;
V_85 = V_84 ;
}
V_84 ++ ;
}
if ( ! V_85 )
V_85 = & V_53 [ 2 ] ;
V_79 -> V_52 = V_85 -> V_52 ;
V_79 -> V_54 = V_85 -> V_54 ;
if ( V_83 )
* V_83 = V_85 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_75 * V_76 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
int V_67 = F_16 ( V_58 ) ;
struct V_50 * V_79 = & V_76 -> V_51 ;
const struct V_82 * V_83 = NULL ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = 0 ;
F_5 ( & V_5 -> V_16 , L_10 ) ;
F_23 ( V_79 , & V_83 ) ;
while ( -- V_67 >= 0 )
if ( V_58 [ V_67 ] . V_57 == V_79 -> V_57 )
break;
if ( V_67 < 0 )
return - V_68 ;
V_79 -> V_55 = V_56 ;
V_79 -> V_57 = V_58 [ V_67 ] . V_57 ;
V_79 -> V_59 = V_60 ;
F_21 ( & V_1 -> V_80 ) ;
if ( V_76 -> V_77 == V_78 ) {
#ifdef F_19
V_79 = F_20 ( V_3 , V_65 , V_76 -> V_89 ) ;
* V_79 = V_76 -> V_51 ;
#else
return - V_81 ;
#endif
} else {
T_4 V_7 ;
if ( V_1 -> V_90 ) {
F_22 ( & V_1 -> V_80 ) ;
return - V_91 ;
}
V_1 -> V_92 = V_83 ;
V_1 -> V_51 = V_76 -> V_51 ;
V_1 -> V_93 =
V_58 [ V_67 ] . V_93 ;
if ( V_1 -> V_51 . V_57 != V_94 )
V_7 = V_1 -> V_23 -> V_28 / 2 ;
else
V_7 = V_1 -> V_23 -> V_28 ;
V_11 = F_25 ( V_1 -> V_28 , V_7 ) ;
if ( V_11 < 0 )
F_26 ( & V_5 -> V_16 ,
L_11 ,
V_11 ) ;
}
F_22 ( & V_1 -> V_80 ) ;
return V_11 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
F_5 ( & V_5 -> V_16 , L_4 , V_49 ) ;
return F_7 ( V_1 -> V_5 , V_1 -> V_92 -> V_19 ) ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
F_5 ( & V_5 -> V_16 , L_4 , V_49 ) ;
return F_7 ( V_1 -> V_5 , V_1 -> V_93 ) ;
}
static int F_29 ( struct V_2 * V_3 , int V_61 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = 0 ;
F_5 ( & V_5 -> V_16 , L_5 , V_49 , V_61 ) ;
F_21 ( & V_1 -> V_80 ) ;
V_61 = ! ! V_61 ;
if ( V_1 -> V_90 == V_61 )
goto V_95;
if ( ! V_61 ) {
F_11 ( V_1 , 0 ) ;
V_1 -> V_90 = V_61 ;
goto V_95;
}
F_9 ( V_1 ) ;
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
F_11 ( V_1 , 1 ) ;
V_1 -> V_90 = V_61 ;
V_95:
F_22 ( & V_1 -> V_80 ) ;
return V_11 ;
}
static int F_30 ( struct V_1 * V_1 , int V_21 )
{
struct V_4 * V_5 = F_14 ( & V_1 -> V_3 ) ;
int V_11 ;
T_2 V_7 ;
V_11 = F_6 ( V_5 , V_96 , & V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_21 ) {
case 0 :
V_7 &= ~ V_97 ;
break;
case 1 :
V_7 &= V_98 ;
V_7 |= V_97 ;
break;
}
return F_3 ( V_5 , V_96 , V_7 ) ;
}
static int F_31 ( struct V_99 * V_100 )
{
struct V_1 * V_1 =
F_2 ( V_100 -> V_101 , struct V_1 , V_102 ) ;
switch ( V_100 -> V_103 ) {
case V_104 :
return F_30 ( V_1 , V_100 -> V_7 ) ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_105 * V_106 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_50 * V_51 =
F_20 ( V_3 , V_106 -> V_89 , 0 ) ;
F_5 ( & V_5 -> V_16 , L_7 , V_49 ) ;
F_10 ( V_51 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
T_2 V_107 , V_108 ;
int V_11 ;
F_5 ( & V_5 -> V_16 , L_7 , V_49 ) ;
V_11 = F_3 ( V_5 , V_109 , 0x01 ) ;
if ( V_11 != 0 ) {
F_12 ( & V_5 -> V_16 , L_12 ) ;
return - V_110 ;
}
F_34 ( 1000 , 2000 ) ;
V_11 = F_13 ( V_3 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_5 , V_111 , & V_107 ) ;
if ( ! V_11 )
V_11 = F_6 ( V_5 , V_112 , & V_108 ) ;
if ( ! V_11 ) {
unsigned short V_103 ;
V_103 = F_35 ( V_107 , V_108 ) ;
if ( V_103 != V_113 )
F_12 ( & V_5 -> V_16 ,
L_13 ,
V_103 , V_11 ) ;
else
F_36 ( & V_5 -> V_16 , L_14 , V_103 ) ;
}
return V_11 ;
}
static struct V_22 *
F_37 ( struct V_4 * V_5 )
{
struct V_22 * V_23 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
if ( ! F_38 ( V_118 ) || ! V_5 -> V_16 . V_119 )
return V_5 -> V_16 . V_120 ;
V_117 = F_39 ( V_5 -> V_16 . V_119 , NULL ) ;
if ( ! V_117 )
return NULL ;
V_115 = F_40 ( V_117 ) ;
if ( F_41 ( V_115 ) ) {
V_23 = NULL ;
goto V_121;
}
V_23 = F_42 ( & V_5 -> V_16 , sizeof( * V_23 ) , V_122 ) ;
if ( ! V_23 )
goto V_121;
if ( ! V_115 -> V_123 ) {
F_12 ( & V_5 -> V_16 ,
L_15 ) ;
V_23 = NULL ;
goto V_121;
}
V_23 -> V_28 = V_115 -> V_124 [ 0 ] ;
V_121:
F_43 ( V_115 ) ;
F_44 ( V_117 ) ;
return V_23 ;
}
static int F_45 ( struct V_4 * V_5 ,
const struct V_125 * V_103 )
{
const struct V_22 * V_23 = F_37 ( V_5 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
struct V_126 * V_126 ;
int V_11 ;
if ( ! V_23 ) {
F_12 ( & V_5 -> V_16 , L_16 ) ;
return - V_68 ;
}
V_1 = F_42 ( & V_5 -> V_16 , sizeof( * V_1 ) , V_122 ) ;
if ( ! V_1 )
return - V_127 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_5 = V_5 ;
V_126 = F_46 ( & V_5 -> V_16 , L_17 ) ;
if ( F_41 ( V_126 ) )
return F_47 ( V_126 ) ;
V_1 -> V_41 = F_48 ( V_126 ) ;
if ( V_1 -> V_41 < 6000000 ||
V_1 -> V_41 > 27000000 )
return - V_68 ;
F_49 ( & V_1 -> V_102 , 2 ) ;
V_1 -> V_28 =
F_50 ( & V_1 -> V_102 , & V_128 ,
V_129 ,
V_23 -> V_28 / 2 ,
V_23 -> V_28 , 1 ,
V_23 -> V_28 ) ;
F_51 ( & V_1 -> V_102 , & V_128 ,
V_104 ,
F_16 ( V_130 ) - 1 ,
0 , 0 , V_130 ) ;
V_1 -> V_3 . V_131 = & V_1 -> V_102 ;
if ( V_1 -> V_102 . error ) {
F_12 ( & V_5 -> V_16 , L_18 ,
V_49 , V_1 -> V_102 . error ) ;
return V_1 -> V_102 . error ;
}
V_3 = & V_1 -> V_3 ;
V_5 -> V_13 |= V_132 ;
#ifdef F_19
F_52 ( V_3 , V_5 , & V_133 ) ;
V_3 -> V_134 = & V_135 ;
V_3 -> V_13 |= V_136 |
V_137 ;
#endif
#if F_53 ( V_138 )
V_1 -> V_89 . V_13 = V_139 ;
V_3 -> V_140 . type = V_141 ;
V_11 = F_54 ( & V_3 -> V_140 , 1 , & V_1 -> V_89 , 0 ) ;
if ( V_11 < 0 ) {
F_55 ( & V_1 -> V_102 ) ;
return V_11 ;
}
#endif
F_56 ( & V_1 -> V_80 ) ;
F_10 ( & V_1 -> V_51 ) ;
V_1 -> V_92 = & V_53 [ 2 ] ;
V_1 -> V_93 = V_58 [ 0 ] . V_93 ;
V_11 = F_33 ( V_3 ) ;
if ( V_11 < 0 )
goto error;
F_8 ( V_1 ) ;
V_11 = F_57 ( & V_1 -> V_3 ) ;
if ( V_11 )
goto error;
F_36 ( & V_5 -> V_16 , L_19 , V_3 -> V_142 ) ;
return 0 ;
error:
F_55 ( & V_1 -> V_102 ) ;
#if F_53 ( V_138 )
F_58 ( & V_3 -> V_140 ) ;
#endif
F_59 ( & V_1 -> V_80 ) ;
return V_11 ;
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_61 ( V_5 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_55 ( & V_1 -> V_102 ) ;
F_62 ( V_3 ) ;
#if F_53 ( V_138 )
F_58 ( & V_3 -> V_140 ) ;
#endif
F_59 ( & V_1 -> V_80 ) ;
return 0 ;
}
