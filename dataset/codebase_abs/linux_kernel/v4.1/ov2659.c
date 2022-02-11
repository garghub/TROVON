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
struct V_50 * V_77 ;
F_5 ( & V_5 -> V_16 , L_8 ) ;
if ( V_76 -> V_78 == V_79 ) {
V_77 = F_19 ( V_3 , V_65 , 0 ) ;
F_20 ( & V_1 -> V_80 ) ;
V_76 -> V_51 = * V_77 ;
F_21 ( & V_1 -> V_80 ) ;
return 0 ;
}
F_20 ( & V_1 -> V_80 ) ;
V_76 -> V_51 = V_1 -> V_51 ;
F_21 ( & V_1 -> V_80 ) ;
F_5 ( & V_5 -> V_16 , L_9 ,
V_1 -> V_51 . V_57 , V_1 -> V_51 . V_52 ,
V_1 -> V_51 . V_54 ) ;
return 0 ;
}
static void F_22 ( struct V_50 * V_77 ,
const struct V_81 * * V_82 )
{
const struct V_81 * V_83 = & V_53 [ 0 ] ;
const struct V_81 * V_84 = NULL ;
int V_20 = F_16 ( V_53 ) ;
unsigned int V_85 = V_86 ;
while ( V_20 -- ) {
int V_87 = abs ( V_83 -> V_52 - V_77 -> V_52 )
+ abs ( V_83 -> V_54 - V_77 -> V_54 ) ;
if ( ( V_87 < V_85 ) && ( V_83 -> V_19 [ 0 ] . V_12 ) ) {
V_85 = V_87 ;
V_84 = V_83 ;
}
V_83 ++ ;
}
if ( ! V_84 )
V_84 = & V_53 [ 2 ] ;
V_77 -> V_52 = V_84 -> V_52 ;
V_77 -> V_54 = V_84 -> V_54 ;
if ( V_82 )
* V_82 = V_84 ;
}
static int F_23 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_75 * V_76 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
unsigned int V_67 = F_16 ( V_58 ) ;
struct V_50 * V_77 = & V_76 -> V_51 ;
const struct V_81 * V_82 = NULL ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = 0 ;
F_5 ( & V_5 -> V_16 , L_10 ) ;
F_22 ( V_77 , & V_82 ) ;
while ( -- V_67 >= 0 )
if ( V_58 [ V_67 ] . V_57 == V_77 -> V_57 )
break;
if ( V_67 < 0 )
return - V_68 ;
V_77 -> V_55 = V_56 ;
V_77 -> V_57 = V_58 [ V_67 ] . V_57 ;
V_77 -> V_59 = V_60 ;
F_20 ( & V_1 -> V_80 ) ;
if ( V_76 -> V_78 == V_79 ) {
V_77 = F_19 ( V_3 , V_65 , V_76 -> V_88 ) ;
* V_77 = V_76 -> V_51 ;
} else {
T_4 V_7 ;
if ( V_1 -> V_89 ) {
F_21 ( & V_1 -> V_80 ) ;
return - V_90 ;
}
V_1 -> V_91 = V_82 ;
V_1 -> V_51 = V_76 -> V_51 ;
V_1 -> V_92 =
V_58 [ V_67 ] . V_92 ;
if ( V_1 -> V_51 . V_57 != V_93 )
V_7 = V_1 -> V_23 -> V_28 / 2 ;
else
V_7 = V_1 -> V_23 -> V_28 ;
V_11 = F_24 ( V_1 -> V_28 , V_7 ) ;
if ( V_11 < 0 )
F_25 ( & V_5 -> V_16 ,
L_11 ,
V_11 ) ;
}
F_21 ( & V_1 -> V_80 ) ;
return V_11 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
F_5 ( & V_5 -> V_16 , L_4 , V_49 ) ;
return F_7 ( V_1 -> V_5 , V_1 -> V_91 -> V_19 ) ;
}
static int F_27 ( struct V_1 * V_1 )
{
struct V_4 * V_5 = V_1 -> V_5 ;
F_5 ( & V_5 -> V_16 , L_4 , V_49 ) ;
return F_7 ( V_1 -> V_5 , V_1 -> V_92 ) ;
}
static int F_28 ( struct V_2 * V_3 , int V_61 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_11 = 0 ;
F_5 ( & V_5 -> V_16 , L_5 , V_49 , V_61 ) ;
F_20 ( & V_1 -> V_80 ) ;
V_61 = ! ! V_61 ;
if ( V_1 -> V_89 == V_61 )
goto V_94;
if ( ! V_61 ) {
F_11 ( V_1 , 0 ) ;
V_1 -> V_89 = V_61 ;
goto V_94;
}
F_9 ( V_1 ) ;
F_26 ( V_1 ) ;
F_27 ( V_1 ) ;
F_11 ( V_1 , 1 ) ;
V_1 -> V_89 = V_61 ;
V_94:
F_21 ( & V_1 -> V_80 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_1 , int V_21 )
{
struct V_4 * V_5 = F_14 ( & V_1 -> V_3 ) ;
int V_11 ;
T_2 V_7 ;
V_11 = F_6 ( V_5 , V_95 , & V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_21 ) {
case 0 :
V_7 &= ~ V_96 ;
break;
case 1 :
V_7 &= V_97 ;
V_7 |= V_96 ;
break;
}
return F_3 ( V_5 , V_95 , V_7 ) ;
}
static int F_30 ( struct V_98 * V_99 )
{
struct V_1 * V_1 =
F_2 ( V_99 -> V_100 , struct V_1 , V_101 ) ;
switch ( V_99 -> V_102 ) {
case V_103 :
return F_29 ( V_1 , V_99 -> V_7 ) ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_104 * V_105 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
struct V_50 * V_51 =
F_19 ( V_3 , V_105 -> V_88 , 0 ) ;
F_5 ( & V_5 -> V_16 , L_7 , V_49 ) ;
F_10 ( V_51 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_14 ( V_3 ) ;
T_2 V_106 , V_107 ;
int V_11 ;
F_5 ( & V_5 -> V_16 , L_7 , V_49 ) ;
V_11 = F_3 ( V_5 , V_108 , 0x01 ) ;
if ( V_11 != 0 ) {
F_12 ( & V_5 -> V_16 , L_12 ) ;
return - V_109 ;
}
F_33 ( 1000 , 2000 ) ;
V_11 = F_13 ( V_3 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_6 ( V_5 , V_110 , & V_106 ) ;
if ( ! V_11 )
V_11 = F_6 ( V_5 , V_111 , & V_107 ) ;
if ( ! V_11 ) {
unsigned short V_102 ;
V_102 = F_34 ( V_106 , V_107 ) ;
if ( V_102 != V_112 )
F_12 ( & V_5 -> V_16 ,
L_13 ,
V_102 , V_11 ) ;
else
F_35 ( & V_5 -> V_16 , L_14 , V_102 ) ;
}
return V_11 ;
}
static struct V_22 *
F_36 ( struct V_4 * V_5 )
{
struct V_22 * V_23 ;
struct V_113 * V_114 ;
int V_11 ;
if ( ! F_37 ( V_115 ) || ! V_5 -> V_16 . V_116 )
return V_5 -> V_16 . V_117 ;
V_114 = F_38 ( V_5 -> V_16 . V_116 , NULL ) ;
if ( ! V_114 )
return NULL ;
V_23 = F_39 ( & V_5 -> V_16 , sizeof( * V_23 ) , V_118 ) ;
if ( ! V_23 )
goto V_119;
V_11 = F_40 ( V_114 , L_15 ,
& V_23 -> V_28 ) ;
if ( V_11 ) {
F_12 ( & V_5 -> V_16 , L_16 ) ;
V_23 = NULL ;
}
V_119:
F_41 ( V_114 ) ;
return V_23 ;
}
static int F_42 ( struct V_4 * V_5 ,
const struct V_120 * V_102 )
{
const struct V_22 * V_23 = F_36 ( V_5 ) ;
struct V_2 * V_3 ;
struct V_1 * V_1 ;
struct V_121 * V_121 ;
int V_11 ;
if ( ! V_23 ) {
F_12 ( & V_5 -> V_16 , L_17 ) ;
return - V_68 ;
}
V_1 = F_39 ( & V_5 -> V_16 , sizeof( * V_1 ) , V_118 ) ;
if ( ! V_1 )
return - V_122 ;
V_1 -> V_23 = V_23 ;
V_1 -> V_5 = V_5 ;
V_121 = F_43 ( & V_5 -> V_16 , L_18 ) ;
if ( F_44 ( V_121 ) )
return F_45 ( V_121 ) ;
V_1 -> V_41 = F_46 ( V_121 ) ;
if ( V_1 -> V_41 < 6000000 ||
V_1 -> V_41 > 27000000 )
return - V_68 ;
F_47 ( & V_1 -> V_101 , 2 ) ;
V_1 -> V_28 =
F_48 ( & V_1 -> V_101 , & V_123 ,
V_124 ,
V_23 -> V_28 / 2 ,
V_23 -> V_28 , 1 ,
V_23 -> V_28 ) ;
F_49 ( & V_1 -> V_101 , & V_123 ,
V_103 ,
F_16 ( V_125 ) - 1 ,
0 , 0 , V_125 ) ;
V_1 -> V_3 . V_126 = & V_1 -> V_101 ;
if ( V_1 -> V_101 . error ) {
F_12 ( & V_5 -> V_16 , L_19 ,
V_49 , V_1 -> V_101 . error ) ;
return V_1 -> V_101 . error ;
}
V_3 = & V_1 -> V_3 ;
V_5 -> V_13 |= V_127 ;
F_50 ( V_3 , V_5 , & V_128 ) ;
V_3 -> V_129 = & V_130 ;
V_3 -> V_13 |= V_131 |
V_132 ;
#if F_51 ( V_133 )
V_1 -> V_88 . V_13 = V_134 ;
V_3 -> V_135 . type = V_136 ;
V_11 = F_52 ( & V_3 -> V_135 , 1 , & V_1 -> V_88 , 0 ) ;
if ( V_11 < 0 ) {
F_53 ( & V_1 -> V_101 ) ;
return V_11 ;
}
#endif
F_54 ( & V_1 -> V_80 ) ;
F_10 ( & V_1 -> V_51 ) ;
V_1 -> V_91 = & V_53 [ 2 ] ;
V_1 -> V_92 = V_58 [ 0 ] . V_92 ;
V_11 = F_32 ( V_3 ) ;
if ( V_11 < 0 )
goto error;
F_8 ( V_1 ) ;
V_11 = F_55 ( & V_1 -> V_3 ) ;
if ( V_11 )
goto error;
F_35 ( & V_5 -> V_16 , L_20 , V_3 -> V_137 ) ;
return 0 ;
error:
F_53 ( & V_1 -> V_101 ) ;
#if F_51 ( V_133 )
F_56 ( & V_3 -> V_135 ) ;
#endif
F_57 ( & V_1 -> V_80 ) ;
return V_11 ;
}
static int F_58 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_59 ( V_5 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_53 ( & V_1 -> V_101 ) ;
F_60 ( V_3 ) ;
#if F_51 ( V_133 )
F_56 ( & V_3 -> V_135 ) ;
#endif
F_57 ( & V_1 -> V_80 ) ;
return 0 ;
}
