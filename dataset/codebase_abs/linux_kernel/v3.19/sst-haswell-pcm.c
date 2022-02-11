static inline T_1 F_1 ( unsigned int V_1 )
{
if ( V_1 >= F_2 ( V_2 ) )
return V_2 [ 0 ] ;
else
return V_2 [ V_1 ] ;
}
static inline unsigned int F_3 ( T_1 V_1 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_2 ) ; V_3 ++ ) {
if ( V_2 [ V_3 ] >= V_1 )
return V_3 ;
}
return V_3 - 1 ;
}
static int F_4 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_5 -> V_12 ;
struct V_13 * V_14 =
F_6 ( V_9 ) ;
struct V_15 * V_16 = & V_14 -> V_17 [ V_11 -> V_18 ] ;
struct V_19 * V_20 = V_14 -> V_20 ;
T_1 V_21 ;
F_7 ( & V_16 -> V_22 ) ;
F_8 ( V_14 -> V_23 ) ;
if ( ! V_16 -> V_24 ) {
V_16 -> V_21 [ 0 ] =
F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
V_16 -> V_21 [ 1 ] =
F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
F_11 ( & V_16 -> V_22 ) ;
return 0 ;
}
if ( V_7 -> V_1 . integer . V_1 [ 0 ] ==
V_7 -> V_1 . integer . V_1 [ 1 ] ) {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_12 ( V_20 , V_16 -> V_24 , 0 , V_25 , V_21 ) ;
} else {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_12 ( V_20 , V_16 -> V_24 , 0 , 0 , V_21 ) ;
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_12 ( V_20 , V_16 -> V_24 , 0 , 1 , V_21 ) ;
}
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
F_11 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_5 -> V_12 ;
struct V_13 * V_14 =
F_6 ( V_9 ) ;
struct V_15 * V_16 = & V_14 -> V_17 [ V_11 -> V_18 ] ;
struct V_19 * V_20 = V_14 -> V_20 ;
T_1 V_21 ;
F_7 ( & V_16 -> V_22 ) ;
F_8 ( V_14 -> V_23 ) ;
if ( ! V_16 -> V_24 ) {
V_7 -> V_1 . integer . V_1 [ 0 ] =
F_3 ( V_16 -> V_21 [ 0 ] ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] =
F_3 ( V_16 -> V_21 [ 1 ] ) ;
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
F_11 ( & V_16 -> V_22 ) ;
return 0 ;
}
F_14 ( V_20 , V_16 -> V_24 , 0 , 0 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 0 ] = F_3 ( V_21 ) ;
F_14 ( V_20 , V_16 -> V_24 , 0 , 1 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] = F_3 ( V_21 ) ;
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
F_11 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
T_1 V_21 ;
F_8 ( V_14 -> V_23 ) ;
if ( V_7 -> V_1 . integer . V_1 [ 0 ] ==
V_7 -> V_1 . integer . V_1 [ 1 ] ) {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_16 ( V_20 , 0 , V_25 , V_21 ) ;
} else {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_16 ( V_20 , 0 , 0 , V_21 ) ;
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_16 ( V_20 , 0 , 1 , V_21 ) ;
}
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
unsigned int V_21 = 0 ;
F_8 ( V_14 -> V_23 ) ;
F_18 ( V_20 , 0 , 0 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 0 ] = F_3 ( V_21 ) ;
F_18 ( V_20 , 0 , 1 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] = F_3 ( V_21 ) ;
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_13 * V_14 , struct V_28 * V_29 ,
unsigned char * V_30 , T_2 V_31 , int V_17 )
{
struct V_32 * V_33 = F_20 ( V_27 ) ;
int V_3 , V_34 , V_24 = V_27 -> V_24 ;
V_34 = F_21 ( V_31 ) ;
F_22 ( V_29 -> V_23 , L_1 ,
V_30 , V_31 , V_34 ) ;
for ( V_3 = 0 ; V_3 < V_34 ; V_3 ++ ) {
T_1 V_35 = ( ( ( V_3 << 2 ) + V_3 ) ) >> 1 ;
T_1 V_36 = F_23 ( V_33 , V_3 * V_37 ) >> V_38 ;
T_1 * V_39 ;
F_22 ( V_29 -> V_23 , L_2 , V_3 , V_35 , V_36 ) ;
V_39 = ( T_1 * ) ( V_14 -> V_33 [ V_17 ] [ V_24 ] . V_40 + V_35 ) ;
if ( V_3 & 1 )
* V_39 |= ( V_36 << 4 ) ;
else
* V_39 |= V_36 ;
}
return 0 ;
}
static int F_24 ( struct V_26 * V_27 ,
struct V_41 * V_42 )
{
struct V_28 * V_29 = V_27 -> V_43 ;
struct V_44 * V_45 = V_27 -> V_45 ;
struct V_13 * V_14 =
F_6 ( V_29 -> V_9 ) ;
struct V_15 * V_16 = F_25 ( V_29 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_32 * V_33 ;
enum V_50 V_51 ;
enum V_52 V_53 ;
T_1 V_54 , V_55 , V_56 , V_34 , V_57 ;
T_3 V_58 ;
int V_59 ;
if ( V_16 -> V_60 ) {
V_59 = F_26 ( V_20 , V_16 -> V_24 ) ;
if ( V_59 < 0 )
F_22 ( V_29 -> V_23 , L_3 ,
V_59 ) ;
V_59 = F_27 ( V_20 , V_16 -> V_24 ) ;
if ( V_59 < 0 ) {
F_22 ( V_29 -> V_23 , L_4 ,
V_59 ) ;
return V_59 ;
}
V_16 -> V_60 = false ;
V_16 -> V_24 = F_28 ( V_20 , V_29 -> V_61 -> V_62 ,
V_63 , V_16 ) ;
if ( V_16 -> V_24 == NULL ) {
F_29 ( V_29 -> V_23 , L_5 ) ;
return - V_64 ;
}
}
if ( V_27 -> V_24 == V_65 )
V_53 = V_66 ;
else
V_53 = V_67 ;
switch ( V_29 -> V_61 -> V_62 ) {
case 0 :
if ( V_27 -> V_24 == V_65 ) {
V_51 = V_68 ;
V_57 = V_69 ;
}
else {
V_51 = V_70 ;
V_57 = V_71 ;
}
break;
case 1 :
case 2 :
V_51 = V_72 ;
V_57 = V_73 ;
break;
case 3 :
V_51 = V_74 ;
V_53 = V_66 ;
V_57 = V_75 ;
break;
default:
F_29 ( V_29 -> V_23 , L_6 ,
V_29 -> V_61 -> V_62 ) ;
return - V_64 ;
} ;
V_59 = F_30 ( V_20 , V_16 -> V_24 ,
V_53 , V_51 , V_76 ) ;
if ( V_59 < 0 ) {
F_29 ( V_29 -> V_23 , L_7 , V_59 ) ;
return V_59 ;
}
V_54 = F_31 ( V_42 ) ;
V_59 = F_32 ( V_20 , V_16 -> V_24 , V_54 ) ;
if ( V_59 < 0 ) {
F_29 ( V_29 -> V_23 , L_8 , V_54 ) ;
return V_59 ;
}
switch ( F_33 ( V_42 ) ) {
case V_77 :
V_55 = V_78 ;
F_34 ( V_20 , V_16 -> V_24 , 16 ) ;
break;
case V_79 :
V_55 = V_80 ;
F_34 ( V_20 , V_16 -> V_24 , 24 ) ;
break;
case V_81 :
V_55 = V_82 ;
F_34 ( V_20 , V_16 -> V_24 , 8 ) ;
break;
case V_83 :
V_55 = V_80 ;
F_34 ( V_20 , V_16 -> V_24 , 32 ) ;
break;
default:
F_29 ( V_29 -> V_23 , L_9 ,
F_33 ( V_42 ) ) ;
return - V_64 ;
}
V_59 = F_35 ( V_20 , V_16 -> V_24 , V_55 ) ;
if ( V_59 < 0 ) {
F_29 ( V_29 -> V_23 , L_10 , V_55 ) ;
return V_59 ;
}
V_58 = F_36 ( V_42 ) ;
V_56 = F_37 ( V_84 ) ;
F_38 ( V_20 , V_16 -> V_24 ,
V_56 , V_84 ) ;
V_59 = F_39 ( V_20 , V_16 -> V_24 , V_58 ) ;
if ( V_59 < 0 ) {
F_29 ( V_29 -> V_23 , L_11 ,
V_58 ) ;
return V_59 ;
}
V_59 = F_40 ( V_27 , F_41 ( V_42 ) ) ;
if ( V_59 < 0 ) {
F_29 ( V_29 -> V_23 , L_12 ,
F_41 ( V_42 ) , V_59 ) ;
return V_59 ;
}
V_33 = F_20 ( V_27 ) ;
V_59 = F_19 ( V_27 , V_14 , V_29 , V_45 -> V_30 ,
V_45 -> V_85 , V_29 -> V_61 -> V_62 ) ;
if ( V_59 < 0 )
return V_59 ;
F_42 ( V_20 , V_16 -> V_24 ,
V_86 ) ;
if ( V_45 -> V_85 % V_37 )
V_34 = ( V_45 -> V_85 / V_37 ) + 1 ;
else
V_34 = V_45 -> V_85 / V_37 ;
V_59 = F_43 ( V_20 , V_16 -> V_24 ,
V_14 -> V_33 [ V_29 -> V_61 -> V_62 ] [ V_27 -> V_24 ] . V_87 ,
V_34 , V_45 -> V_85 , 0 ,
F_23 ( V_33 , 0 ) >> V_38 ) ;
if ( V_59 < 0 ) {
F_29 ( V_29 -> V_23 , L_13 , V_59 ) ;
return V_59 ;
}
V_49 = F_44 ( V_20 ) ;
V_47 = F_45 ( V_49 , V_57 ) ;
if ( V_47 == NULL ) {
F_29 ( V_29 -> V_23 , L_14 ) ;
return - V_64 ;
}
F_46 ( V_20 , V_16 -> V_24 ,
V_16 -> V_45 ) ;
V_59 = F_47 ( V_20 , V_16 -> V_24 ) ;
if ( V_59 < 0 ) {
F_29 ( V_29 -> V_23 , L_15 , V_59 ) ;
return V_59 ;
}
if ( ! V_16 -> V_60 ) {
F_12 ( V_20 , V_16 -> V_24 , 0 ,
0 , V_16 -> V_21 [ 0 ] ) ;
F_12 ( V_20 , V_16 -> V_24 , 0 ,
1 , V_16 -> V_21 [ 1 ] ) ;
V_16 -> V_60 = true ;
}
V_59 = F_48 ( V_20 , V_16 -> V_24 , 1 ) ;
if ( V_59 < 0 )
F_29 ( V_29 -> V_23 , L_16 , V_59 ) ;
return 0 ;
}
static int F_49 ( struct V_26 * V_27 )
{
F_50 ( V_27 ) ;
return 0 ;
}
static int F_51 ( struct V_26 * V_27 , int V_88 )
{
struct V_28 * V_29 = V_27 -> V_43 ;
struct V_13 * V_14 =
F_6 ( V_29 -> V_9 ) ;
struct V_15 * V_16 = F_25 ( V_29 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
switch ( V_88 ) {
case V_89 :
case V_90 :
case V_91 :
F_52 ( V_20 , V_16 -> V_24 , 0 ) ;
break;
case V_92 :
case V_93 :
case V_94 :
F_48 ( V_20 , V_16 -> V_24 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 V_63 ( struct V_95 * V_24 , void * V_96 )
{
struct V_15 * V_16 = V_96 ;
struct V_26 * V_27 = V_16 -> V_27 ;
struct V_44 * V_45 = V_27 -> V_45 ;
struct V_28 * V_29 = V_27 -> V_43 ;
T_1 V_97 ;
V_97 = F_53 ( V_45 ,
( V_45 -> V_98 -> V_99 % V_45 -> V_100 ) ) ;
F_54 ( V_29 -> V_23 , L_17 , V_97 ) ;
F_55 ( V_27 ) ;
return V_97 ;
}
static T_4 F_56 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_43 ;
struct V_44 * V_45 = V_27 -> V_45 ;
struct V_13 * V_14 =
F_6 ( V_29 -> V_9 ) ;
struct V_15 * V_16 = F_25 ( V_29 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
T_4 V_101 ;
T_5 V_102 ;
T_1 V_103 = F_57 ( V_20 , V_16 -> V_24 ) ;
V_101 = F_58 ( V_45 , V_103 ) ;
V_102 = F_59 ( V_20 , V_16 -> V_24 ) ;
F_54 ( V_29 -> V_23 , L_18 ,
V_103 , V_102 ) ;
return V_101 ;
}
static int F_60 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_43 ;
struct V_13 * V_14 =
F_6 ( V_29 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_19 * V_20 = V_14 -> V_20 ;
V_16 = & V_14 -> V_17 [ V_29 -> V_61 -> V_62 ] ;
F_7 ( & V_16 -> V_22 ) ;
F_8 ( V_14 -> V_23 ) ;
F_61 ( V_29 , V_16 ) ;
V_16 -> V_27 = V_27 ;
F_62 ( V_27 , & V_104 ) ;
V_16 -> V_24 = F_28 ( V_20 , V_29 -> V_61 -> V_62 ,
V_63 , V_16 ) ;
if ( V_16 -> V_24 == NULL ) {
F_29 ( V_29 -> V_23 , L_5 ) ;
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
F_11 ( & V_16 -> V_22 ) ;
return - V_64 ;
}
F_11 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_63 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_43 ;
struct V_13 * V_14 =
F_6 ( V_29 -> V_9 ) ;
struct V_15 * V_16 = F_25 ( V_29 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
int V_59 ;
F_7 ( & V_16 -> V_22 ) ;
V_59 = F_26 ( V_20 , V_16 -> V_24 ) ;
if ( V_59 < 0 ) {
F_22 ( V_29 -> V_23 , L_3 , V_59 ) ;
goto V_105;
}
V_59 = F_27 ( V_20 , V_16 -> V_24 ) ;
if ( V_59 < 0 ) {
F_22 ( V_29 -> V_23 , L_4 , V_59 ) ;
goto V_105;
}
V_16 -> V_60 = 0 ;
V_16 -> V_24 = NULL ;
V_105:
F_9 ( V_14 -> V_23 ) ;
F_10 ( V_14 -> V_23 ) ;
F_11 ( & V_16 -> V_22 ) ;
return V_59 ;
}
static int F_64 ( struct V_13 * V_14 )
{
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_15 * V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_106 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_17 [ V_3 ] ;
V_16 -> V_45 = F_65 ( V_20 ,
V_106 [ V_3 ] . V_107 , V_16 -> V_108 ) ;
if ( V_16 -> V_45 == NULL )
goto V_109;
V_16 -> V_108 =
V_16 -> V_45 -> V_108 ;
}
return 0 ;
V_109:
for ( -- V_3 ; V_3 >= 0 ; V_3 -- ) {
V_16 = & V_14 -> V_17 [ V_3 ] ;
F_66 ( V_16 -> V_45 ) ;
}
return - V_110 ;
}
static void F_67 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_106 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_17 [ V_3 ] ;
F_66 ( V_16 -> V_45 ) ;
}
}
static void F_68 ( struct V_111 * V_17 )
{
F_69 ( V_17 ) ;
}
static int F_70 ( struct V_28 * V_29 )
{
struct V_111 * V_17 = V_29 -> V_17 ;
struct V_8 * V_9 = V_29 -> V_9 ;
struct V_112 * V_14 = F_71 ( V_9 -> V_23 ) ;
struct V_13 * V_113 = F_72 ( V_9 -> V_23 ) ;
struct V_114 * V_23 = V_14 -> V_115 ;
int V_59 = 0 ;
if ( V_17 -> V_116 [ V_65 ] . V_27 ||
V_17 -> V_116 [ V_117 ] . V_27 ) {
V_59 = F_73 ( V_17 ,
V_118 ,
V_23 ,
V_104 . V_119 ,
V_104 . V_119 ) ;
if ( V_59 ) {
F_29 ( V_29 -> V_23 , L_19 ,
V_59 ) ;
return V_59 ;
}
}
V_113 -> V_17 [ V_29 -> V_61 -> V_62 ] . V_120 = V_17 ;
return V_59 ;
}
static int F_74 ( struct V_8 * V_9 )
{
struct V_13 * V_113 = F_6 ( V_9 ) ;
struct V_112 * V_14 = F_71 ( V_9 -> V_23 ) ;
struct V_114 * V_115 , * V_23 ;
int V_3 , V_59 = 0 ;
if ( ! V_14 )
return - V_110 ;
V_23 = V_9 -> V_23 ;
V_115 = V_14 -> V_115 ;
V_113 -> V_20 = V_14 -> V_49 ;
V_113 -> V_23 = V_9 -> V_23 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = V_9 -> V_124 . V_125 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_126 ) ; V_3 ++ ) {
F_75 ( & V_113 -> V_17 [ V_3 ] . V_22 ) ;
if ( V_126 [ V_3 ] . V_127 . V_128 ) {
V_59 = F_76 ( V_129 , V_115 ,
V_37 , & V_113 -> V_33 [ V_3 ] [ 0 ] ) ;
if ( V_59 < 0 )
goto V_109;
}
if ( V_126 [ V_3 ] . V_130 . V_128 ) {
V_59 = F_76 ( V_129 , V_115 ,
V_37 , & V_113 -> V_33 [ V_3 ] [ 1 ] ) ;
if ( V_59 < 0 )
goto V_109;
}
}
F_64 ( V_113 ) ;
F_77 ( V_9 -> V_23 ,
V_131 ) ;
F_78 ( V_9 -> V_23 ) ;
F_79 ( V_9 -> V_23 ) ;
F_80 ( V_9 -> V_23 ) ;
return 0 ;
V_109:
for (; V_3 >= 0 ; V_3 -- ) {
if ( V_126 [ V_3 ] . V_127 . V_128 )
F_81 ( & V_113 -> V_33 [ V_3 ] [ 0 ] ) ;
if ( V_126 [ V_3 ] . V_130 . V_128 )
F_81 ( & V_113 -> V_33 [ V_3 ] [ 1 ] ) ;
}
return V_59 ;
}
static int F_82 ( struct V_8 * V_9 )
{
struct V_13 * V_113 =
F_6 ( V_9 ) ;
int V_3 ;
F_83 ( V_9 -> V_23 ) ;
F_67 ( V_113 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_126 ) ; V_3 ++ ) {
if ( V_126 [ V_3 ] . V_127 . V_128 )
F_81 ( & V_113 -> V_33 [ V_3 ] [ 0 ] ) ;
if ( V_126 [ V_3 ] . V_130 . V_128 )
F_81 ( & V_113 -> V_33 [ V_3 ] [ 1 ] ) ;
}
return 0 ;
}
static int F_84 ( struct V_132 * V_133 )
{
struct V_112 * V_112 = F_71 ( & V_133 -> V_23 ) ;
struct V_13 * V_113 ;
int V_59 ;
if ( ! V_112 )
return - V_64 ;
V_113 = F_85 ( & V_133 -> V_23 , sizeof( * V_113 ) , V_134 ) ;
if ( ! V_113 )
return - V_135 ;
V_59 = F_86 ( & V_133 -> V_23 , V_112 ) ;
if ( V_59 < 0 )
return - V_110 ;
V_113 -> V_20 = V_112 -> V_49 ;
F_87 ( V_133 , V_113 ) ;
V_59 = F_88 ( & V_133 -> V_23 , & V_136 ) ;
if ( V_59 < 0 )
goto V_137;
V_59 = F_89 ( & V_133 -> V_23 , & V_138 ,
V_126 , F_2 ( V_126 ) ) ;
if ( V_59 < 0 )
goto V_139;
return 0 ;
V_139:
F_90 ( & V_133 -> V_23 ) ;
V_137:
F_91 ( & V_133 -> V_23 , V_112 ) ;
return 0 ;
}
static int F_92 ( struct V_132 * V_133 )
{
struct V_112 * V_112 = F_71 ( & V_133 -> V_23 ) ;
F_90 ( & V_133 -> V_23 ) ;
F_93 ( & V_133 -> V_23 ) ;
F_91 ( & V_133 -> V_23 , V_112 ) ;
return 0 ;
}
static int F_94 ( struct V_114 * V_23 )
{
return 0 ;
}
static int F_95 ( struct V_114 * V_23 )
{
struct V_13 * V_14 = F_72 ( V_23 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
if ( V_14 -> V_121 == V_140 )
return 0 ;
F_96 ( V_20 ) ;
F_97 ( V_20 ) ;
V_14 -> V_121 = V_140 ;
return 0 ;
}
static int F_98 ( struct V_114 * V_23 )
{
struct V_13 * V_14 = F_72 ( V_23 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
int V_59 ;
if ( V_14 -> V_121 == V_122 )
return 0 ;
V_59 = F_99 ( V_20 ) ;
if ( V_59 < 0 ) {
F_29 ( V_23 , L_20 , V_59 ) ;
return V_59 ;
}
V_59 = F_64 ( V_14 ) ;
if ( V_59 < 0 ) {
F_29 ( V_23 , L_21 , V_59 ) ;
return V_59 ;
}
V_59 = F_100 ( V_20 ) ;
if ( V_59 < 0 )
return V_59 ;
else if ( V_59 == 1 )
return 0 ;
V_14 -> V_121 = V_122 ;
return V_59 ;
}
static void F_101 ( struct V_114 * V_23 )
{
struct V_13 * V_14 = F_72 ( V_23 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_15 * V_16 ;
int V_3 , V_109 ;
if ( V_14 -> V_121 == V_122 )
return;
V_109 = F_99 ( V_20 ) ;
if ( V_109 < 0 ) {
F_29 ( V_23 , L_20 , V_109 ) ;
return;
}
V_109 = F_64 ( V_14 ) ;
if ( V_109 < 0 ) {
F_29 ( V_23 , L_21 , V_109 ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_141 + 1 ; V_3 ++ ) {
V_16 = & V_14 -> V_17 [ V_3 ] ;
if ( ! V_16 -> V_27 )
continue;
V_109 = F_102 ( V_16 -> V_45 ,
& V_16 -> V_142 ) ;
if ( V_109 < 0 )
F_29 ( V_23 , L_22 , V_3 ) ;
}
F_103 ( V_14 -> V_123 -> V_23 ) ;
V_109 = F_100 ( V_20 ) ;
if ( V_109 < 0 )
return;
else if ( V_109 == 1 )
return;
V_14 -> V_121 = V_122 ;
return;
}
static int F_104 ( struct V_114 * V_23 )
{
struct V_13 * V_14 = F_72 ( V_23 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_15 * V_16 ;
int V_3 , V_109 ;
if ( V_14 -> V_121 == V_140 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_141 + 1 ; V_3 ++ ) {
V_16 = & V_14 -> V_17 [ V_3 ] ;
if ( ! V_16 -> V_27 )
continue;
F_22 ( V_23 , L_23 , V_3 ) ;
F_105 ( V_16 -> V_120 ) ;
F_106 ( 2 ) ;
}
F_107 ( V_14 -> V_123 -> V_23 ) ;
F_108 ( V_14 -> V_123 -> V_23 ) ;
F_96 ( V_20 ) ;
for ( V_3 = 0 ; V_3 < V_141 + 1 ; V_3 ++ ) {
V_16 = & V_14 -> V_17 [ V_3 ] ;
if ( ! V_16 -> V_27 )
continue;
F_22 ( V_23 , L_24 , V_3 ) ;
V_109 = F_109 ( V_16 -> V_45 ,
& V_16 -> V_142 ) ;
if ( V_109 < 0 )
F_29 ( V_23 , L_25 , V_3 ) ;
}
F_97 ( V_20 ) ;
V_14 -> V_121 = V_140 ;
return 0 ;
}
