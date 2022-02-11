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
struct V_10 * V_11 =
(struct V_10 * ) V_5 -> V_12 ;
struct V_13 * V_14 =
F_6 ( V_9 ) ;
struct V_15 * V_16 = & V_14 -> V_17 [ V_11 -> V_18 ] ;
struct V_19 * V_20 = V_14 -> V_20 ;
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
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
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
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
unsigned int V_21 = 0 ;
F_15 ( V_20 , 0 , 0 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 0 ] = F_3 ( V_21 ) ;
F_15 ( V_20 , 0 , 1 , & V_21 ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] = F_3 ( V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 ,
struct V_13 * V_14 , struct V_26 * V_27 ,
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
V_38 = ( T_1 * ) ( V_14 -> V_31 [ V_17 ] [ V_23 ] . V_39 + V_34 ) ;
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
struct V_13 * V_14 =
F_6 ( V_27 -> V_9 ) ;
struct V_15 * V_16 = F_22 ( V_27 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_30 * V_31 ;
enum V_49 V_50 ;
enum V_51 V_52 ;
T_1 V_53 , V_54 , V_55 , V_32 , V_56 ;
T_3 V_57 ;
int V_58 ;
if ( V_16 -> V_59 ) {
V_58 = F_23 ( V_20 , V_16 -> V_23 ) ;
if ( V_58 < 0 )
F_19 ( V_27 -> V_33 , L_3 ,
V_58 ) ;
V_58 = F_24 ( V_20 , V_16 -> V_23 ) ;
if ( V_58 < 0 ) {
F_19 ( V_27 -> V_33 , L_4 ,
V_58 ) ;
return V_58 ;
}
V_16 -> V_59 = false ;
V_16 -> V_23 = F_25 ( V_20 , V_27 -> V_60 -> V_61 ,
V_62 , V_16 ) ;
if ( V_16 -> V_23 == NULL ) {
F_26 ( V_27 -> V_33 , L_5 ) ;
return - V_63 ;
}
}
if ( V_25 -> V_23 == V_64 )
V_52 = V_65 ;
else
V_52 = V_66 ;
switch ( V_27 -> V_60 -> V_61 ) {
case 0 :
V_50 = V_67 ;
V_56 = V_68 ;
break;
case 1 :
case 2 :
V_50 = V_69 ;
V_56 = V_70 ;
break;
case 3 :
V_50 = V_71 ;
V_52 = V_65 ;
V_56 = V_72 ;
break;
case 4 :
V_50 = V_73 ;
V_56 = V_74 ;
break;
default:
F_26 ( V_27 -> V_33 , L_6 ,
V_27 -> V_60 -> V_61 ) ;
return - V_63 ;
} ;
V_58 = F_27 ( V_20 , V_16 -> V_23 ,
V_52 , V_50 , V_75 ) ;
if ( V_58 < 0 ) {
F_26 ( V_27 -> V_33 , L_7 , V_58 ) ;
return V_58 ;
}
V_53 = F_28 ( V_41 ) ;
V_58 = F_29 ( V_20 , V_16 -> V_23 , V_53 ) ;
if ( V_58 < 0 ) {
F_26 ( V_27 -> V_33 , L_8 , V_53 ) ;
return V_58 ;
}
switch ( F_30 ( V_41 ) ) {
case V_76 :
V_54 = V_77 ;
F_31 ( V_20 , V_16 -> V_23 , 16 ) ;
break;
case V_78 :
V_54 = V_79 ;
F_31 ( V_20 , V_16 -> V_23 , 24 ) ;
break;
case V_80 :
V_54 = V_81 ;
F_31 ( V_20 , V_16 -> V_23 , 8 ) ;
break;
case V_82 :
V_54 = V_79 ;
F_31 ( V_20 , V_16 -> V_23 , 32 ) ;
break;
default:
F_26 ( V_27 -> V_33 , L_9 ,
F_30 ( V_41 ) ) ;
return - V_63 ;
}
V_58 = F_32 ( V_20 , V_16 -> V_23 , V_54 ) ;
if ( V_58 < 0 ) {
F_26 ( V_27 -> V_33 , L_10 , V_54 ) ;
return V_58 ;
}
V_57 = F_33 ( V_41 ) ;
if ( V_57 != 2 ) {
F_26 ( V_27 -> V_33 , L_11 , V_57 ) ;
return - V_63 ;
}
V_55 = F_34 ( V_83 ) ;
F_35 ( V_20 , V_16 -> V_23 ,
V_55 , V_83 ) ;
V_58 = F_36 ( V_20 , V_16 -> V_23 , V_57 ) ;
if ( V_58 < 0 ) {
F_26 ( V_27 -> V_33 , L_12 ,
V_57 ) ;
return V_58 ;
}
V_58 = F_37 ( V_25 , F_38 ( V_41 ) ) ;
if ( V_58 < 0 ) {
F_26 ( V_27 -> V_33 , L_13 ,
F_38 ( V_41 ) , V_58 ) ;
return V_58 ;
}
V_31 = F_17 ( V_25 ) ;
V_58 = F_16 ( V_25 , V_14 , V_27 , V_44 -> V_28 ,
V_44 -> V_84 , V_27 -> V_60 -> V_61 ) ;
if ( V_58 < 0 )
return V_58 ;
F_39 ( V_20 , V_16 -> V_23 ,
V_85 ) ;
if ( V_44 -> V_84 % V_36 )
V_32 = ( V_44 -> V_84 / V_36 ) + 1 ;
else
V_32 = V_44 -> V_84 / V_36 ;
V_58 = F_40 ( V_20 , V_16 -> V_23 ,
V_14 -> V_31 [ V_27 -> V_60 -> V_61 ] [ V_25 -> V_23 ] . V_86 ,
V_32 , V_44 -> V_84 , 0 ,
F_20 ( V_31 , 0 ) >> V_37 ) ;
if ( V_58 < 0 ) {
F_26 ( V_27 -> V_33 , L_14 , V_58 ) ;
return V_58 ;
}
V_48 = F_41 ( V_20 ) ;
V_46 = F_42 ( V_48 , V_56 ) ;
if ( V_46 == NULL ) {
F_26 ( V_27 -> V_33 , L_15 ) ;
return - V_63 ;
}
if ( V_50 == V_73 ) {
F_43 ( V_20 , V_16 -> V_23 ,
V_74 , V_46 -> V_87 ) ;
F_44 ( V_20 , V_16 -> V_23 ,
0x449400 , 0x4000 ) ;
F_45 ( V_20 , V_16 -> V_23 ,
0x400000 , 0 ) ;
} else {
F_43 ( V_20 , V_16 -> V_23 ,
V_68 , V_46 -> V_87 ) ;
F_44 ( V_20 , V_16 -> V_23 ,
V_46 -> V_88 , V_46 -> V_29 ) ;
F_44 ( V_20 , V_16 -> V_23 ,
0x44d400 , 0x3800 ) ;
F_45 ( V_20 , V_16 -> V_23 ,
V_46 -> V_88 , V_46 -> V_29 ) ;
F_45 ( V_20 , V_16 -> V_23 ,
0x400000 , 0 ) ;
}
V_58 = F_46 ( V_20 , V_16 -> V_23 ) ;
if ( V_58 < 0 ) {
F_26 ( V_27 -> V_33 , L_16 , V_58 ) ;
return V_58 ;
}
V_16 -> V_59 = true ;
V_58 = F_47 ( V_20 , V_16 -> V_23 , 1 ) ;
if ( V_58 < 0 )
F_26 ( V_27 -> V_33 , L_17 , V_58 ) ;
return 0 ;
}
static int F_48 ( struct V_24 * V_25 )
{
F_49 ( V_25 ) ;
return 0 ;
}
static int F_50 ( struct V_24 * V_25 , int V_89 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_13 * V_14 =
F_6 ( V_27 -> V_9 ) ;
struct V_15 * V_16 = F_22 ( V_27 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
switch ( V_89 ) {
case V_90 :
case V_91 :
case V_92 :
F_51 ( V_20 , V_16 -> V_23 , 0 ) ;
break;
case V_93 :
case V_94 :
case V_95 :
F_47 ( V_20 , V_16 -> V_23 , 0 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 V_62 ( struct V_96 * V_23 , void * V_97 )
{
struct V_15 * V_16 = V_97 ;
struct V_24 * V_25 = V_16 -> V_25 ;
struct V_43 * V_44 = V_25 -> V_44 ;
struct V_26 * V_27 = V_25 -> V_42 ;
T_1 V_98 ;
V_98 = F_52 ( V_44 ,
( V_44 -> V_99 -> V_100 % V_44 -> V_101 ) ) ;
F_19 ( V_27 -> V_33 , L_18 , V_98 ) ;
F_53 ( V_25 ) ;
return V_98 ;
}
static T_4 F_54 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_43 * V_44 = V_25 -> V_44 ;
struct V_13 * V_14 =
F_6 ( V_27 -> V_9 ) ;
struct V_15 * V_16 = F_22 ( V_27 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
T_4 V_88 ;
T_5 V_102 ;
T_1 V_103 = F_55 ( V_20 , V_16 -> V_23 ) ;
V_88 = F_56 ( V_44 , V_103 ) ;
V_102 = F_57 ( V_20 , V_16 -> V_23 ) ;
F_19 ( V_27 -> V_33 , L_19 ,
V_103 , V_102 ) ;
return V_88 ;
}
static int F_58 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_13 * V_14 =
F_6 ( V_27 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_19 * V_20 = V_14 -> V_20 ;
V_16 = & V_14 -> V_17 [ V_27 -> V_60 -> V_61 ] ;
F_7 ( & V_16 -> V_22 ) ;
F_59 ( V_27 , V_16 ) ;
V_16 -> V_25 = V_25 ;
F_60 ( V_25 , & V_104 ) ;
V_16 -> V_23 = F_25 ( V_20 , V_27 -> V_60 -> V_61 ,
V_62 , V_16 ) ;
if ( V_16 -> V_23 == NULL ) {
F_26 ( V_27 -> V_33 , L_5 ) ;
F_8 ( & V_16 -> V_22 ) ;
return - V_63 ;
}
F_9 ( V_20 , V_16 -> V_23 , 0 ,
0 , V_16 -> V_21 [ 0 ] ) ;
F_9 ( V_20 , V_16 -> V_23 , 0 ,
1 , V_16 -> V_21 [ 1 ] ) ;
F_8 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_42 ;
struct V_13 * V_14 =
F_6 ( V_27 -> V_9 ) ;
struct V_15 * V_16 = F_22 ( V_27 ) ;
struct V_19 * V_20 = V_14 -> V_20 ;
int V_58 ;
F_7 ( & V_16 -> V_22 ) ;
V_58 = F_23 ( V_20 , V_16 -> V_23 ) ;
if ( V_58 < 0 ) {
F_19 ( V_27 -> V_33 , L_3 , V_58 ) ;
goto V_105;
}
V_58 = F_24 ( V_20 , V_16 -> V_23 ) ;
if ( V_58 < 0 ) {
F_19 ( V_27 -> V_33 , L_4 , V_58 ) ;
goto V_105;
}
V_16 -> V_59 = 0 ;
V_16 -> V_23 = NULL ;
V_105:
F_8 ( & V_16 -> V_22 ) ;
return V_58 ;
}
static void F_62 ( struct V_106 * V_17 )
{
F_63 ( V_17 ) ;
}
static int F_64 ( struct V_26 * V_27 )
{
struct V_106 * V_17 = V_27 -> V_17 ;
struct V_8 * V_9 = V_27 -> V_9 ;
struct V_107 * V_14 = F_65 ( V_9 -> V_33 ) ;
struct V_108 * V_33 = V_14 -> V_109 ;
int V_58 = 0 ;
if ( V_17 -> V_110 [ V_64 ] . V_25 ||
V_17 -> V_110 [ V_111 ] . V_25 ) {
V_58 = F_66 ( V_17 ,
V_112 ,
V_33 ,
V_104 . V_113 ,
V_104 . V_113 ) ;
if ( V_58 ) {
F_26 ( V_27 -> V_33 , L_20 ,
V_58 ) ;
return V_58 ;
}
}
return V_58 ;
}
static int F_67 ( struct V_8 * V_9 )
{
struct V_107 * V_14 = F_65 ( V_9 -> V_33 ) ;
struct V_13 * V_114 ;
struct V_108 * V_109 ;
int V_3 , V_58 = 0 ;
if ( ! V_14 )
return - V_115 ;
V_109 = V_14 -> V_109 ;
V_114 = F_68 ( V_9 -> V_33 , sizeof( * V_114 ) , V_116 ) ;
V_114 -> V_20 = V_14 -> V_48 ;
F_69 ( V_9 , V_114 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_117 ) ; V_3 ++ ) {
F_70 ( & V_114 -> V_17 [ V_3 ] . V_22 ) ;
if ( V_117 [ V_3 ] . V_118 . V_119 ) {
V_58 = F_71 ( V_120 , V_109 ,
V_36 , & V_114 -> V_31 [ V_3 ] [ 0 ] ) ;
if ( V_58 < 0 )
goto V_121;
}
if ( V_117 [ V_3 ] . V_122 . V_119 ) {
V_58 = F_71 ( V_120 , V_109 ,
V_36 , & V_114 -> V_31 [ V_3 ] [ 1 ] ) ;
if ( V_58 < 0 )
goto V_121;
}
}
return 0 ;
V_121:
for (; V_3 >= 0 ; V_3 -- ) {
if ( V_117 [ V_3 ] . V_118 . V_119 )
F_72 ( & V_114 -> V_31 [ V_3 ] [ 0 ] ) ;
if ( V_117 [ V_3 ] . V_122 . V_119 )
F_72 ( & V_114 -> V_31 [ V_3 ] [ 1 ] ) ;
}
return V_58 ;
}
static int F_73 ( struct V_8 * V_9 )
{
struct V_13 * V_114 =
F_6 ( V_9 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_117 ) ; V_3 ++ ) {
if ( V_117 [ V_3 ] . V_118 . V_119 )
F_72 ( & V_114 -> V_31 [ V_3 ] [ 0 ] ) ;
if ( V_117 [ V_3 ] . V_122 . V_119 )
F_72 ( & V_114 -> V_31 [ V_3 ] [ 1 ] ) ;
}
return 0 ;
}
static int F_74 ( struct V_123 * V_124 )
{
struct V_107 * V_107 = F_65 ( & V_124 -> V_33 ) ;
int V_58 ;
V_58 = F_75 ( & V_124 -> V_33 , V_107 ) ;
if ( V_58 < 0 )
return - V_115 ;
V_58 = F_76 ( & V_124 -> V_33 , & V_125 ) ;
if ( V_58 < 0 )
goto V_126;
V_58 = F_77 ( & V_124 -> V_33 , & V_127 ,
V_117 , F_2 ( V_117 ) ) ;
if ( V_58 < 0 )
goto V_128;
return 0 ;
V_128:
F_78 ( & V_124 -> V_33 ) ;
V_126:
F_79 ( & V_124 -> V_33 , V_107 ) ;
return 0 ;
}
static int F_80 ( struct V_123 * V_124 )
{
struct V_107 * V_107 = F_65 ( & V_124 -> V_33 ) ;
F_78 ( & V_124 -> V_33 ) ;
F_81 ( & V_124 -> V_33 ) ;
F_79 ( & V_124 -> V_33 , V_107 ) ;
return 0 ;
}
