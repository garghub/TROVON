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
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 =
(struct V_12 * ) V_5 -> V_14 ;
struct V_15 * V_16 = & V_11 -> V_17 [ V_13 -> V_18 ] ;
struct V_19 * V_20 = V_11 -> V_20 ;
T_1 V_21 ;
F_7 ( & V_16 -> V_22 ) ;
if ( ! V_16 -> V_23 ) {
V_16 -> V_21 [ 0 ] =
F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
V_16 -> V_21 [ 1 ] =
F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_8 ( & V_16 -> V_22 ) ;
return 0 ;
}
if ( V_7 -> V_1 . integer . V_1 [ 0 ] ==
V_7 -> V_1 . integer . V_1 [ 1 ] ) {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_9 ( V_20 , V_16 -> V_23 , 0 , 2 , V_21 ) ;
} else {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_9 ( V_20 , V_16 -> V_23 , 0 , 0 , V_21 ) ;
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_9 ( V_20 , V_16 -> V_23 , 0 , 1 , V_21 ) ;
}
F_8 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_12 * V_13 =
(struct V_12 * ) V_5 -> V_14 ;
struct V_15 * V_16 = & V_11 -> V_17 [ V_13 -> V_18 ] ;
struct V_19 * V_20 = V_11 -> V_20 ;
T_1 V_21 ;
F_7 ( & V_16 -> V_22 ) ;
if ( ! V_16 -> V_23 ) {
V_7 -> V_1 . integer . V_1 [ 0 ] =
F_3 ( V_16 -> V_21 [ 0 ] ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] =
F_3 ( V_16 -> V_21 [ 1 ] ) ;
F_8 ( & V_16 -> V_22 ) ;
return 0 ;
}
F_11 ( V_20 , V_16 -> V_23 , 0 , 0 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 0 ] = F_3 ( V_21 ) ;
F_11 ( V_20 , V_16 -> V_23 , 0 , 1 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] = F_3 ( V_21 ) ;
F_8 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_19 * V_20 = V_11 -> V_20 ;
T_1 V_21 ;
if ( V_7 -> V_1 . integer . V_1 [ 0 ] ==
V_7 -> V_1 . integer . V_1 [ 1 ] ) {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_13 ( V_20 , 0 , 2 , V_21 ) ;
} else {
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_13 ( V_20 , 0 , 0 , V_21 ) ;
V_21 = F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_13 ( V_20 , 0 , 1 , V_21 ) ;
}
return 0 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_19 * V_20 = V_11 -> V_20 ;
unsigned int V_21 = 0 ;
F_15 ( V_20 , 0 , 0 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 0 ] = F_3 ( V_21 ) ;
F_15 ( V_20 , 0 , 1 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] = F_3 ( V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_10 * V_11 , struct V_26 * V_27 ,
unsigned char * V_28 , T_2 V_29 , int V_17 )
{
struct V_30 * V_31 = F_17 ( V_25 ) ;
int V_3 , V_32 , V_23 = V_25 -> V_23 ;
V_32 = F_18 ( V_29 ) ;
F_19 ( V_27 -> V_33 , L_1 ,
V_28 , V_29 , V_32 ) ;
for ( V_3 = 0 ; V_3 < V_32 ; V_3 ++ ) {
T_1 V_34 = ( ( ( V_3 << 2 ) + V_3 ) ) >> 1 ;
T_1 V_35 = F_20 ( V_31 , V_3 * V_36 ) >> V_37 ;
T_1 * V_38 ;
F_19 ( V_27 -> V_33 , L_2 , V_3 , V_34 , V_35 ) ;
V_38 = ( T_1 * ) ( V_11 -> V_31 [ V_17 ] [ V_23 ] . V_39 + V_34 ) ;
if ( V_3 & 1 )
* V_38 |= ( V_35 << 4 ) ;
else
* V_38 |= V_35 ;
}
return 0 ;
}
static int F_21 ( struct V_24 * V_25 ,
struct V_40 * V_41 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_43 * V_44 = V_25 -> V_44 ;
struct V_10 * V_11 =
F_22 ( V_27 -> V_45 ) ;
struct V_15 * V_16 = F_23 ( V_27 ) ;
struct V_19 * V_20 = V_11 -> V_20 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_30 * V_31 ;
enum V_50 V_51 ;
enum V_52 V_53 ;
T_1 V_54 , V_55 , V_56 , V_32 , V_57 ;
T_3 V_58 ;
int V_59 ;
if ( V_16 -> V_60 ) {
V_59 = F_24 ( V_20 , V_16 -> V_23 ) ;
if ( V_59 < 0 )
F_19 ( V_27 -> V_33 , L_3 ,
V_59 ) ;
V_59 = F_25 ( V_20 , V_16 -> V_23 ) ;
if ( V_59 < 0 ) {
F_19 ( V_27 -> V_33 , L_4 ,
V_59 ) ;
return V_59 ;
}
V_16 -> V_60 = false ;
V_16 -> V_23 = F_26 ( V_20 , V_27 -> V_61 -> V_62 ,
V_63 , V_16 ) ;
if ( V_16 -> V_23 == NULL ) {
F_27 ( V_27 -> V_33 , L_5 ) ;
return - V_64 ;
}
}
if ( V_25 -> V_23 == V_65 )
V_53 = V_66 ;
else
V_53 = V_67 ;
switch ( V_27 -> V_61 -> V_62 ) {
case 0 :
V_51 = V_68 ;
V_57 = V_69 ;
break;
case 1 :
case 2 :
V_51 = V_70 ;
V_57 = V_71 ;
break;
case 3 :
V_51 = V_72 ;
V_53 = V_66 ;
V_57 = V_73 ;
break;
case 4 :
V_51 = V_74 ;
V_57 = V_75 ;
break;
default:
F_27 ( V_27 -> V_33 , L_6 ,
V_27 -> V_61 -> V_62 ) ;
return - V_64 ;
} ;
V_59 = F_28 ( V_20 , V_16 -> V_23 ,
V_53 , V_51 , V_76 ) ;
if ( V_59 < 0 ) {
F_27 ( V_27 -> V_33 , L_7 , V_59 ) ;
return V_59 ;
}
V_54 = F_29 ( V_41 ) ;
V_59 = F_30 ( V_20 , V_16 -> V_23 , V_54 ) ;
if ( V_59 < 0 ) {
F_27 ( V_27 -> V_33 , L_8 , V_54 ) ;
return V_59 ;
}
switch ( F_31 ( V_41 ) ) {
case V_77 :
V_55 = V_78 ;
F_32 ( V_20 , V_16 -> V_23 , 16 ) ;
break;
case V_79 :
V_55 = V_80 ;
F_32 ( V_20 , V_16 -> V_23 , 24 ) ;
break;
case V_81 :
V_55 = V_82 ;
F_32 ( V_20 , V_16 -> V_23 , 8 ) ;
break;
case V_83 :
V_55 = V_80 ;
F_32 ( V_20 , V_16 -> V_23 , 32 ) ;
break;
default:
F_27 ( V_27 -> V_33 , L_9 ,
F_31 ( V_41 ) ) ;
return - V_64 ;
}
V_59 = F_33 ( V_20 , V_16 -> V_23 , V_55 ) ;
if ( V_59 < 0 ) {
F_27 ( V_27 -> V_33 , L_10 , V_55 ) ;
return V_59 ;
}
V_58 = F_34 ( V_41 ) ;
if ( V_58 != 2 ) {
F_27 ( V_27 -> V_33 , L_11 , V_58 ) ;
return - V_64 ;
}
V_56 = F_35 ( V_84 ) ;
F_36 ( V_20 , V_16 -> V_23 ,
V_56 , V_84 ) ;
V_59 = F_37 ( V_20 , V_16 -> V_23 , V_58 ) ;
if ( V_59 < 0 ) {
F_27 ( V_27 -> V_33 , L_12 ,
V_58 ) ;
return V_59 ;
}
V_59 = F_38 ( V_25 , F_39 ( V_41 ) ) ;
if ( V_59 < 0 ) {
F_27 ( V_27 -> V_33 , L_13 ,
F_39 ( V_41 ) , V_59 ) ;
return V_59 ;
}
V_31 = F_17 ( V_25 ) ;
V_59 = F_16 ( V_25 , V_11 , V_27 , V_44 -> V_28 ,
V_44 -> V_85 , V_27 -> V_61 -> V_62 ) ;
if ( V_59 < 0 )
return V_59 ;
F_40 ( V_20 , V_16 -> V_23 ,
V_86 ) ;
if ( V_44 -> V_85 % V_36 )
V_32 = ( V_44 -> V_85 / V_36 ) + 1 ;
else
V_32 = V_44 -> V_85 / V_36 ;
V_59 = F_41 ( V_20 , V_16 -> V_23 ,
V_11 -> V_31 [ V_27 -> V_61 -> V_62 ] [ V_25 -> V_23 ] . V_87 ,
V_32 , V_44 -> V_85 , 0 ,
F_20 ( V_31 , 0 ) >> V_37 ) ;
if ( V_59 < 0 ) {
F_27 ( V_27 -> V_33 , L_14 , V_59 ) ;
return V_59 ;
}
V_49 = F_42 ( V_20 ) ;
V_47 = F_43 ( V_49 , V_57 ) ;
if ( V_47 == NULL ) {
F_27 ( V_27 -> V_33 , L_15 ) ;
return - V_64 ;
}
if ( V_51 == V_74 ) {
F_44 ( V_20 , V_16 -> V_23 ,
V_75 , V_47 -> V_88 ) ;
F_45 ( V_20 , V_16 -> V_23 ,
0x449400 , 0x4000 ) ;
F_46 ( V_20 , V_16 -> V_23 ,
0x400000 , 0 ) ;
} else {
F_44 ( V_20 , V_16 -> V_23 ,
V_69 , V_47 -> V_88 ) ;
F_45 ( V_20 , V_16 -> V_23 ,
V_47 -> V_89 , V_47 -> V_29 ) ;
F_45 ( V_20 , V_16 -> V_23 ,
0x44d400 , 0x3800 ) ;
F_46 ( V_20 , V_16 -> V_23 ,
V_47 -> V_89 , V_47 -> V_29 ) ;
F_46 ( V_20 , V_16 -> V_23 ,
0x400000 , 0 ) ;
}
V_59 = F_47 ( V_20 , V_16 -> V_23 ) ;
if ( V_59 < 0 ) {
F_27 ( V_27 -> V_33 , L_16 , V_59 ) ;
return V_59 ;
}
V_16 -> V_60 = true ;
V_59 = F_48 ( V_20 , V_16 -> V_23 , 1 ) ;
if ( V_59 < 0 )
F_27 ( V_27 -> V_33 , L_17 , V_59 ) ;
return 0 ;
}
static int F_49 ( struct V_24 * V_25 )
{
F_50 ( V_25 ) ;
return 0 ;
}
static int F_51 ( struct V_24 * V_25 , int V_90 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_10 * V_11 =
F_22 ( V_27 -> V_45 ) ;
struct V_15 * V_16 = F_23 ( V_27 ) ;
struct V_19 * V_20 = V_11 -> V_20 ;
switch ( V_90 ) {
case V_91 :
case V_92 :
case V_93 :
F_52 ( V_20 , V_16 -> V_23 , 0 ) ;
break;
case V_94 :
case V_95 :
case V_96 :
F_48 ( V_20 , V_16 -> V_23 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 V_63 ( struct V_97 * V_23 , void * V_98 )
{
struct V_15 * V_16 = V_98 ;
struct V_24 * V_25 = V_16 -> V_25 ;
struct V_43 * V_44 = V_25 -> V_44 ;
struct V_26 * V_27 = V_25 -> V_42 ;
T_1 V_99 ;
V_99 = F_53 ( V_44 ,
( V_44 -> V_100 -> V_101 % V_44 -> V_102 ) ) ;
F_19 ( V_27 -> V_33 , L_18 , V_99 ) ;
F_54 ( V_25 ) ;
return V_99 ;
}
static T_4 F_55 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_43 * V_44 = V_25 -> V_44 ;
struct V_10 * V_11 =
F_22 ( V_27 -> V_45 ) ;
struct V_15 * V_16 = F_23 ( V_27 ) ;
struct V_19 * V_20 = V_11 -> V_20 ;
T_4 V_89 ;
T_5 V_103 ;
T_1 V_104 = F_56 ( V_20 , V_16 -> V_23 ) ;
V_89 = F_57 ( V_44 , V_104 ) ;
V_103 = F_58 ( V_20 , V_16 -> V_23 ) ;
F_19 ( V_27 -> V_33 , L_19 ,
V_104 , V_103 ) ;
return V_89 ;
}
static int F_59 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_10 * V_11 =
F_22 ( V_27 -> V_45 ) ;
struct V_15 * V_16 ;
struct V_19 * V_20 = V_11 -> V_20 ;
V_16 = & V_11 -> V_17 [ V_27 -> V_61 -> V_62 ] ;
F_7 ( & V_16 -> V_22 ) ;
F_60 ( V_27 , V_16 ) ;
V_16 -> V_25 = V_25 ;
F_61 ( V_25 , & V_105 ) ;
V_16 -> V_23 = F_26 ( V_20 , V_27 -> V_61 -> V_62 ,
V_63 , V_16 ) ;
if ( V_16 -> V_23 == NULL ) {
F_27 ( V_27 -> V_33 , L_5 ) ;
F_8 ( & V_16 -> V_22 ) ;
return - V_64 ;
}
F_9 ( V_20 , V_16 -> V_23 , 0 ,
0 , V_16 -> V_21 [ 0 ] ) ;
F_9 ( V_20 , V_16 -> V_23 , 0 ,
1 , V_16 -> V_21 [ 1 ] ) ;
F_8 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_62 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_10 * V_11 =
F_22 ( V_27 -> V_45 ) ;
struct V_15 * V_16 = F_23 ( V_27 ) ;
struct V_19 * V_20 = V_11 -> V_20 ;
int V_59 ;
F_7 ( & V_16 -> V_22 ) ;
V_59 = F_24 ( V_20 , V_16 -> V_23 ) ;
if ( V_59 < 0 ) {
F_19 ( V_27 -> V_33 , L_3 , V_59 ) ;
goto V_106;
}
V_59 = F_25 ( V_20 , V_16 -> V_23 ) ;
if ( V_59 < 0 ) {
F_19 ( V_27 -> V_33 , L_4 , V_59 ) ;
goto V_106;
}
V_16 -> V_60 = 0 ;
V_16 -> V_23 = NULL ;
V_106:
F_8 ( & V_16 -> V_22 ) ;
return V_59 ;
}
static void F_63 ( struct V_107 * V_17 )
{
F_64 ( V_17 ) ;
}
static int F_65 ( struct V_26 * V_27 )
{
struct V_107 * V_17 = V_27 -> V_17 ;
struct V_108 * V_45 = V_27 -> V_45 ;
struct V_109 * V_11 = F_66 ( V_45 -> V_33 ) ;
struct V_110 * V_33 = V_11 -> V_111 ;
int V_59 = 0 ;
if ( V_17 -> V_112 [ V_65 ] . V_25 ||
V_17 -> V_112 [ V_113 ] . V_25 ) {
V_59 = F_67 ( V_17 ,
V_114 ,
V_33 ,
V_105 . V_115 ,
V_105 . V_115 ) ;
if ( V_59 ) {
F_27 ( V_27 -> V_33 , L_20 ,
V_59 ) ;
return V_59 ;
}
}
return V_59 ;
}
static int F_68 ( struct V_108 * V_45 )
{
struct V_10 * V_116 = F_22 ( V_45 ) ;
struct V_109 * V_11 = F_66 ( V_45 -> V_33 ) ;
struct V_110 * V_111 = V_11 -> V_111 ;
int V_3 , V_59 = 0 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_117 ) ; V_3 ++ ) {
F_69 ( & V_116 -> V_17 [ V_3 ] . V_22 ) ;
if ( V_117 [ V_3 ] . V_118 . V_119 ) {
V_59 = F_70 ( V_120 , V_111 ,
V_36 , & V_116 -> V_31 [ V_3 ] [ 0 ] ) ;
if ( V_59 < 0 )
goto V_121;
}
if ( V_117 [ V_3 ] . V_122 . V_119 ) {
V_59 = F_70 ( V_120 , V_111 ,
V_36 , & V_116 -> V_31 [ V_3 ] [ 1 ] ) ;
if ( V_59 < 0 )
goto V_121;
}
}
return 0 ;
V_121:
for (; V_3 >= 0 ; V_3 -- ) {
if ( V_117 [ V_3 ] . V_118 . V_119 )
F_71 ( & V_116 -> V_31 [ V_3 ] [ 0 ] ) ;
if ( V_117 [ V_3 ] . V_122 . V_119 )
F_71 ( & V_116 -> V_31 [ V_3 ] [ 1 ] ) ;
}
return V_59 ;
}
static int F_72 ( struct V_108 * V_45 )
{
struct V_10 * V_116 =
F_22 ( V_45 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_117 ) ; V_3 ++ ) {
if ( V_117 [ V_3 ] . V_118 . V_119 )
F_71 ( & V_116 -> V_31 [ V_3 ] [ 0 ] ) ;
if ( V_117 [ V_3 ] . V_122 . V_119 )
F_71 ( & V_116 -> V_31 [ V_3 ] [ 1 ] ) ;
}
return 0 ;
}
static int F_73 ( struct V_123 * V_124 )
{
struct V_109 * V_109 = F_66 ( & V_124 -> V_33 ) ;
struct V_10 * V_116 ;
int V_59 ;
if ( ! V_109 )
return - V_64 ;
V_116 = F_74 ( & V_124 -> V_33 , sizeof( * V_116 ) , V_125 ) ;
if ( ! V_116 )
return - V_126 ;
V_59 = F_75 ( & V_124 -> V_33 , V_109 ) ;
if ( V_59 < 0 )
return - V_127 ;
V_116 -> V_20 = V_109 -> V_49 ;
F_76 ( V_124 , V_116 ) ;
V_59 = F_77 ( & V_124 -> V_33 , & V_128 ) ;
if ( V_59 < 0 )
goto V_129;
V_59 = F_78 ( & V_124 -> V_33 , & V_130 ,
V_117 , F_2 ( V_117 ) ) ;
if ( V_59 < 0 )
goto V_131;
return 0 ;
V_131:
F_79 ( & V_124 -> V_33 ) ;
V_129:
F_80 ( & V_124 -> V_33 , V_109 ) ;
return 0 ;
}
static int F_81 ( struct V_123 * V_124 )
{
struct V_109 * V_109 = F_66 ( & V_124 -> V_33 ) ;
F_79 ( & V_124 -> V_33 ) ;
F_82 ( & V_124 -> V_33 ) ;
F_80 ( & V_124 -> V_33 , V_109 ) ;
return 0 ;
}
