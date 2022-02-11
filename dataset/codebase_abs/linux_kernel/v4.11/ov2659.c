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
T_3 V_29 , V_30 , V_31 ;
T_3 V_32 = - 1 ;
T_3 V_33 , V_34 ;
int V_20 , V_35 ;
for ( V_20 = 0 ; V_36 [ V_20 ] . div != 0 ; V_20 ++ ) {
V_30 = V_36 [ V_20 ] . div ;
for ( V_35 = 0 ; V_37 [ V_35 ] . div != 0 ; V_35 ++ ) {
V_29 = V_37 [ V_35 ] . div ;
for ( V_31 = 1 ; V_31 <= 63 ; V_31 ++ ) {
V_34 = V_1 -> V_38 ;
V_34 *= V_31 ;
V_34 /= V_29 ;
V_34 /= V_30 ;
V_33 = V_34 - V_27 ;
V_33 = abs ( V_33 ) ;
if ( ( V_33 < V_32 ) || ( V_32 == - 1 ) ) {
V_32 = V_33 ;
V_24 = V_36 [ V_20 ] . V_6 ;
V_25 = V_31 ;
V_26 = V_37 [ V_35 ] . V_6 ;
}
}
}
}
V_1 -> V_39 . V_36 = V_24 ;
V_1 -> V_39 . V_40 = V_25 ;
V_1 -> V_39 . V_37 = V_26 ;
F_5 ( & V_5 -> V_16 ,
L_3 ,
V_24 , V_25 , V_26 ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
struct V_18 V_41 [] = {
{ V_42 , V_1 -> V_39 . V_36 } ,
{ V_43 , V_1 -> V_39 . V_40 } ,
{ V_44 , V_1 -> V_39 . V_37 } ,
{ V_45 , 0x00 } ,
} ;
F_5 ( & V_5 -> V_16 , L_4 , V_46 ) ;
return F_7 ( V_5 , V_41 ) ;
}
static void F_10 ( struct V_47 * V_48 )
{
V_48 -> V_49 = V_50 [ 2 ] . V_49 ;
V_48 -> V_51 = V_50 [ 2 ] . V_51 ;
V_48 -> V_52 = V_53 ;
V_48 -> V_54 = V_55 [ 0 ] . V_54 ;
V_48 -> V_56 = V_57 ;
}
static void F_11 ( struct V_1 * V_1 , int V_58 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
int V_11 ;
V_58 = ! ! V_58 ;
F_5 ( & V_5 -> V_16 , L_5 , V_46 , V_58 ) ;
V_11 = F_3 ( V_5 , V_59 , V_58 ) ;
if ( V_11 )
F_12 ( & V_5 -> V_16 , L_6 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_3 V_7 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
return F_7 ( V_5 , V_60 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_61 * V_62 ,
struct V_63 * V_54 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
F_5 ( & V_5 -> V_16 , L_7 , V_46 ) ;
if ( V_54 -> V_64 >= F_16 ( V_55 ) )
return - V_65 ;
V_54 -> V_54 = V_55 [ V_54 -> V_64 ] . V_54 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_61 * V_62 ,
struct V_66 * V_67 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
int V_20 = F_16 ( V_55 ) ;
F_5 ( & V_5 -> V_16 , L_7 , V_46 ) ;
if ( V_67 -> V_64 >= F_16 ( V_50 ) )
return - V_65 ;
while ( -- V_20 )
if ( V_67 -> V_54 == V_55 [ V_20 ] . V_54 )
break;
V_67 -> V_54 = V_55 [ V_20 ] . V_54 ;
V_67 -> V_68 = V_50 [ V_67 -> V_64 ] . V_49 ;
V_67 -> V_69 = V_67 -> V_68 ;
V_67 -> V_70 = V_50 [ V_67 -> V_64 ] . V_51 ;
V_67 -> V_71 = V_67 -> V_70 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_61 * V_62 ,
struct V_72 * V_73 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_5 ( & V_5 -> V_16 , L_8 ) ;
if ( V_73 -> V_74 == V_75 ) {
#ifdef F_19
struct V_47 * V_76 ;
V_76 = F_20 ( V_3 , V_62 , 0 ) ;
F_21 ( & V_1 -> V_77 ) ;
V_73 -> V_48 = * V_76 ;
F_22 ( & V_1 -> V_77 ) ;
return 0 ;
#else
return - V_78 ;
#endif
}
F_21 ( & V_1 -> V_77 ) ;
V_73 -> V_48 = V_1 -> V_48 ;
F_22 ( & V_1 -> V_77 ) ;
F_5 ( & V_5 -> V_16 , L_9 ,
V_1 -> V_48 . V_54 , V_1 -> V_48 . V_49 ,
V_1 -> V_48 . V_51 ) ;
return 0 ;
}
static void F_23 ( struct V_47 * V_76 ,
const struct V_79 * * V_80 )
{
const struct V_79 * V_81 = & V_50 [ 0 ] ;
const struct V_79 * V_82 = NULL ;
int V_20 = F_16 ( V_50 ) ;
unsigned int V_83 = V_84 ;
while ( V_20 -- ) {
int V_85 = abs ( V_81 -> V_49 - V_76 -> V_49 )
+ abs ( V_81 -> V_51 - V_76 -> V_51 ) ;
if ( ( V_85 < V_83 ) && ( V_81 -> V_19 [ 0 ] . V_12 ) ) {
V_83 = V_85 ;
V_82 = V_81 ;
}
V_81 ++ ;
}
if ( ! V_82 )
V_82 = & V_50 [ 2 ] ;
V_76 -> V_49 = V_82 -> V_49 ;
V_76 -> V_51 = V_82 -> V_51 ;
if ( V_80 )
* V_80 = V_82 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_61 * V_62 ,
struct V_72 * V_73 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
int V_64 = F_16 ( V_55 ) ;
struct V_47 * V_76 = & V_73 -> V_48 ;
const struct V_79 * V_80 = NULL ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = 0 ;
F_5 ( & V_5 -> V_16 , L_10 ) ;
F_23 ( V_76 , & V_80 ) ;
while ( -- V_64 >= 0 )
if ( V_55 [ V_64 ] . V_54 == V_76 -> V_54 )
break;
if ( V_64 < 0 )
return - V_65 ;
V_76 -> V_52 = V_53 ;
V_76 -> V_56 = V_57 ;
F_21 ( & V_1 -> V_77 ) ;
if ( V_73 -> V_74 == V_75 ) {
#ifdef F_19
V_76 = F_20 ( V_3 , V_62 , V_73 -> V_86 ) ;
* V_76 = V_73 -> V_48 ;
#else
return - V_78 ;
#endif
} else {
T_4 V_7 ;
if ( V_1 -> V_87 ) {
F_22 ( & V_1 -> V_77 ) ;
return - V_88 ;
}
V_1 -> V_89 = V_80 ;
V_1 -> V_48 = V_73 -> V_48 ;
V_1 -> V_90 =
V_55 [ V_64 ] . V_90 ;
if ( V_1 -> V_48 . V_54 != V_91 )
V_7 = V_1 -> V_23 -> V_28 / 2 ;
else
V_7 = V_1 -> V_23 -> V_28 ;
V_11 = F_25 ( V_1 -> V_28 , V_7 ) ;
if ( V_11 < 0 )
F_26 ( & V_5 -> V_16 ,
L_11 ,
V_11 ) ;
}
F_22 ( & V_1 -> V_77 ) ;
return V_11 ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
F_5 ( & V_5 -> V_16 , L_4 , V_46 ) ;
return F_7 ( V_1 -> V_5 , V_1 -> V_89 -> V_19 ) ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
F_5 ( & V_5 -> V_16 , L_4 , V_46 ) ;
return F_7 ( V_1 -> V_5 , V_1 -> V_90 ) ;
}
static int F_29 ( struct V_2 * V_3 , int V_58 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = 0 ;
F_5 ( & V_5 -> V_16 , L_5 , V_46 , V_58 ) ;
F_21 ( & V_1 -> V_77 ) ;
V_58 = ! ! V_58 ;
if ( V_1 -> V_87 == V_58 )
goto V_92;
if ( ! V_58 ) {
F_11 ( V_1 , 0 ) ;
V_1 -> V_87 = V_58 ;
goto V_92;
}
F_9 ( V_1 ) ;
F_27 ( V_1 ) ;
F_28 ( V_1 ) ;
F_11 ( V_1 , 1 ) ;
V_1 -> V_87 = V_58 ;
V_92:
F_22 ( & V_1 -> V_77 ) ;
return V_11 ;
}
static int F_30 ( struct V_1 * V_1 , int V_21 )
{
struct V_4 * V_5 = F_14 ( & V_1 -> V_3 ) ;
int V_11 ;
T_2 V_7 ;
V_11 = F_6 ( V_5 , V_93 , & V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_21 ) {
case 0 :
V_7 &= ~ V_94 ;
break;
case 1 :
V_7 &= V_95 ;
V_7 |= V_94 ;
break;
}
return F_3 ( V_5 , V_93 , V_7 ) ;
}
static int F_31 ( struct V_96 * V_97 )
{
struct V_1 * V_1 =
F_2 ( V_97 -> V_98 , struct V_1 , V_99 ) ;
switch ( V_97 -> V_100 ) {
case V_101 :
return F_30 ( V_1 , V_97 -> V_7 ) ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_102 * V_103 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_47 * V_48 =
F_20 ( V_3 , V_103 -> V_86 , 0 ) ;
F_5 ( & V_5 -> V_16 , L_7 , V_46 ) ;
F_10 ( V_48 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
T_2 V_104 , V_105 ;
int V_11 ;
F_5 ( & V_5 -> V_16 , L_7 , V_46 ) ;
V_11 = F_3 ( V_5 , V_106 , 0x01 ) ;
if ( V_11 != 0 ) {
F_12 ( & V_5 -> V_16 , L_12 ) ;
return - V_107 ;
}
F_34 ( 1000 , 2000 ) ;
V_11 = F_6 ( V_5 , V_108 , & V_104 ) ;
if ( ! V_11 )
V_11 = F_6 ( V_5 , V_109 , & V_105 ) ;
if ( ! V_11 ) {
unsigned short V_100 ;
V_100 = F_35 ( V_104 , V_105 ) ;
if ( V_100 != V_110 )
F_12 ( & V_5 -> V_16 ,
L_13 ,
V_100 , V_11 ) ;
else {
F_36 ( & V_5 -> V_16 , L_14 , V_100 ) ;
V_11 = F_13 ( V_3 , 0 ) ;
}
}
return V_11 ;
}
static struct V_22 *
F_37 ( struct V_4 * V_5 )
{
struct V_22 * V_23 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
if ( ! F_38 ( V_115 ) || ! V_5 -> V_16 . V_116 )
return V_5 -> V_16 . V_117 ;
V_114 = F_39 ( V_5 -> V_16 . V_116 , NULL ) ;
if ( ! V_114 )
return NULL ;
V_112 = F_40 ( V_114 ) ;
if ( F_41 ( V_112 ) ) {
V_23 = NULL ;
goto V_118;
}
V_23 = F_42 ( & V_5 -> V_16 , sizeof( * V_23 ) , V_119 ) ;
if ( ! V_23 )
goto V_118;
if ( ! V_112 -> V_120 ) {
F_12 ( & V_5 -> V_16 ,
L_15 ) ;
V_23 = NULL ;
goto V_118;
}
V_23 -> V_28 = V_112 -> V_121 [ 0 ] ;
V_118:
F_43 ( V_112 ) ;
F_44 ( V_114 ) ;
return V_23 ;
}
static int F_45 ( struct V_4 * V_5 ,
const struct V_122 * V_100 )
{
const struct V_22 * V_23 = F_37 ( V_5 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
struct V_123 * V_123 ;
int V_11 ;
if ( ! V_23 ) {
F_12 ( & V_5 -> V_16 , L_16 ) ;
return - V_65 ;
}
V_1 = F_42 ( & V_5 -> V_16 , sizeof( * V_1 ) , V_119 ) ;
if ( ! V_1 )
return - V_124 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_5 = V_5 ;
V_123 = F_46 ( & V_5 -> V_16 , L_17 ) ;
if ( F_41 ( V_123 ) )
return F_47 ( V_123 ) ;
V_1 -> V_38 = F_48 ( V_123 ) ;
if ( V_1 -> V_38 < 6000000 ||
V_1 -> V_38 > 27000000 )
return - V_65 ;
F_49 ( & V_1 -> V_99 , 2 ) ;
V_1 -> V_28 =
F_50 ( & V_1 -> V_99 , & V_125 ,
V_126 ,
V_23 -> V_28 / 2 ,
V_23 -> V_28 , 1 ,
V_23 -> V_28 ) ;
F_51 ( & V_1 -> V_99 , & V_125 ,
V_101 ,
F_16 ( V_127 ) - 1 ,
0 , 0 , V_127 ) ;
V_1 -> V_3 . V_128 = & V_1 -> V_99 ;
if ( V_1 -> V_99 . error ) {
F_12 ( & V_5 -> V_16 , L_18 ,
V_46 , V_1 -> V_99 . error ) ;
return V_1 -> V_99 . error ;
}
V_3 = & V_1 -> V_3 ;
V_5 -> V_13 |= V_129 ;
#ifdef F_19
F_52 ( V_3 , V_5 , & V_130 ) ;
V_3 -> V_131 = & V_132 ;
V_3 -> V_13 |= V_133 |
V_134 ;
#endif
#if F_53 ( V_135 )
V_1 -> V_86 . V_13 = V_136 ;
V_3 -> V_137 . V_138 = V_139 ;
V_11 = F_54 ( & V_3 -> V_137 , 1 , & V_1 -> V_86 ) ;
if ( V_11 < 0 ) {
F_55 ( & V_1 -> V_99 ) ;
return V_11 ;
}
#endif
F_56 ( & V_1 -> V_77 ) ;
F_10 ( & V_1 -> V_48 ) ;
V_1 -> V_89 = & V_50 [ 2 ] ;
V_1 -> V_90 = V_55 [ 0 ] . V_90 ;
V_11 = F_33 ( V_3 ) ;
if ( V_11 < 0 )
goto error;
F_8 ( V_1 ) ;
V_11 = F_57 ( & V_1 -> V_3 ) ;
if ( V_11 )
goto error;
F_36 ( & V_5 -> V_16 , L_19 , V_3 -> V_140 ) ;
return 0 ;
error:
F_55 ( & V_1 -> V_99 ) ;
#if F_53 ( V_135 )
F_58 ( & V_3 -> V_137 ) ;
#endif
F_59 ( & V_1 -> V_77 ) ;
return V_11 ;
}
static int F_60 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_61 ( V_5 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_55 ( & V_1 -> V_99 ) ;
F_62 ( V_3 ) ;
#if F_53 ( V_135 )
F_58 ( & V_3 -> V_137 ) ;
#endif
F_59 ( & V_1 -> V_77 ) ;
return 0 ;
}
