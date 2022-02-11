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
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
T_1 V_19 ;
int V_20 , V_21 ;
V_20 = V_22 [ V_11 -> V_23 ] . V_24 ;
V_21 = V_22 [ V_11 -> V_23 ] . V_21 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_21 ] ;
F_7 ( & V_16 -> V_26 ) ;
F_8 ( V_14 -> V_27 ) ;
if ( ! V_16 -> V_21 ) {
V_16 -> V_19 [ 0 ] =
F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
V_16 -> V_19 [ 1 ] =
F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
return 0 ;
}
if ( V_7 -> V_1 . integer . V_1 [ 0 ] ==
V_7 -> V_1 . integer . V_1 [ 1 ] ) {
V_19 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_12 ( V_18 , V_16 -> V_21 , 0 , V_28 , V_19 ) ;
} else {
V_19 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_12 ( V_18 , V_16 -> V_21 , 0 , 0 , V_19 ) ;
V_19 = F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_12 ( V_18 , V_16 -> V_21 , 0 , 1 , V_19 ) ;
}
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
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
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
T_1 V_19 ;
int V_20 , V_21 ;
V_20 = V_22 [ V_11 -> V_23 ] . V_24 ;
V_21 = V_22 [ V_11 -> V_23 ] . V_21 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_21 ] ;
F_7 ( & V_16 -> V_26 ) ;
F_8 ( V_14 -> V_27 ) ;
if ( ! V_16 -> V_21 ) {
V_7 -> V_1 . integer . V_1 [ 0 ] =
F_3 ( V_16 -> V_19 [ 0 ] ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] =
F_3 ( V_16 -> V_19 [ 1 ] ) ;
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
return 0 ;
}
F_14 ( V_18 , V_16 -> V_21 , 0 , 0 , & V_19 ) ;
V_7 -> V_1 . integer . V_1 [ 0 ] = F_3 ( V_19 ) ;
F_14 ( V_18 , V_16 -> V_21 , 0 , 1 , & V_19 ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] = F_3 ( V_19 ) ;
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
T_1 V_19 ;
F_8 ( V_14 -> V_27 ) ;
if ( V_7 -> V_1 . integer . V_1 [ 0 ] ==
V_7 -> V_1 . integer . V_1 [ 1 ] ) {
V_19 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_16 ( V_18 , 0 , V_28 , V_19 ) ;
} else {
V_19 = F_1 ( V_7 -> V_1 . integer . V_1 [ 0 ] ) ;
F_16 ( V_18 , 0 , 0 , V_19 ) ;
V_19 = F_1 ( V_7 -> V_1 . integer . V_1 [ 1 ] ) ;
F_16 ( V_18 , 0 , 1 , V_19 ) ;
}
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
unsigned int V_19 = 0 ;
F_8 ( V_14 -> V_27 ) ;
F_18 ( V_18 , 0 , 0 , & V_19 ) ;
V_7 -> V_1 . integer . V_1 [ 0 ] = F_3 ( V_19 ) ;
F_18 ( V_18 , 0 , 1 , & V_19 ) ;
V_7 -> V_1 . integer . V_1 [ 1 ] = F_3 ( V_19 ) ;
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
enum V_29 V_30 = V_31 ;
V_7 -> V_1 . integer . V_1 [ 0 ] =
( F_20 ( V_18 , V_30 ) ||
F_21 ( V_18 , V_30 ) ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_32 = 0 ;
enum V_29 V_30 = V_31 ;
bool V_33 = ( bool ) V_7 -> V_1 . integer . V_1 [ 0 ] ;
if ( F_23 ( V_18 , V_30 ) ) {
if ( V_33 == F_20 ( V_18 , V_30 ) )
return 0 ;
if ( V_33 )
V_32 = F_24 ( V_18 , V_30 , 0 ) ;
else
V_32 = F_25 ( V_18 , V_30 , 0 ) ;
} else {
if ( V_33 == F_21 ( V_18 , V_30 ) )
return 0 ;
if ( V_33 )
F_26 ( V_18 , V_30 ) ;
else
F_27 ( V_18 , V_30 ) ;
}
return V_32 ;
}
static int F_28 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
return F_29 ( V_18 , V_7 -> V_1 . V_34 . V_35 ) ;
}
static int F_30 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_5 ) ;
struct V_13 * V_14 = F_6 ( V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_32 ;
enum V_29 V_30 = V_31 ;
int V_36 = V_7 -> V_1 . V_34 . V_35 [ 0 ] ;
int V_37 = V_38 ;
if ( V_36 == 0xFF ) {
F_31 ( V_18 ) ;
return 0 ;
}
V_32 = F_32 ( V_18 , V_7 -> V_1 . V_34 . V_35 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( F_20 ( V_18 , V_30 ) )
V_32 = F_33 ( V_18 , V_30 , 0 , V_36 ,
V_37 , V_7 -> V_1 . V_34 . V_35 ) ;
return V_32 ;
}
static int F_34 ( struct V_39 * V_40 ,
struct V_13 * V_14 , struct V_41 * V_42 ,
unsigned char * V_43 , T_2 V_44 , int V_25 )
{
struct V_45 * V_46 = F_35 ( V_40 ) ;
int V_3 , V_47 , V_21 = V_40 -> V_21 ;
V_47 = F_36 ( V_44 ) ;
F_37 ( V_42 -> V_27 , L_1 ,
V_43 , V_44 , V_47 ) ;
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ ) {
T_1 V_48 = ( ( ( V_3 << 2 ) + V_3 ) ) >> 1 ;
T_1 V_49 = F_38 ( V_46 , V_3 * V_50 ) >> V_51 ;
T_1 * V_52 ;
F_37 ( V_42 -> V_27 , L_2 , V_3 , V_48 , V_49 ) ;
V_52 = ( T_1 * ) ( V_14 -> V_46 [ V_25 ] [ V_21 ] . V_53 + V_48 ) ;
if ( V_3 & 1 )
* V_52 |= ( V_49 << 4 ) ;
else
* V_52 |= V_49 ;
}
return 0 ;
}
static int F_39 ( struct V_39 * V_40 ,
struct V_54 * V_55 )
{
struct V_41 * V_42 = V_40 -> V_56 ;
struct V_57 * V_58 = V_40 -> V_58 ;
struct V_13 * V_14 =
F_6 ( V_42 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_45 * V_46 ;
enum V_63 V_64 ;
enum V_65 V_66 ;
T_1 V_67 , V_68 , V_69 , V_47 , V_70 ;
T_3 V_71 ;
int V_32 , V_20 ;
V_20 = V_22 [ V_42 -> V_72 -> V_30 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_40 -> V_21 ] ;
if ( V_16 -> V_73 ) {
V_32 = F_40 ( V_18 , V_16 -> V_21 ) ;
if ( V_32 < 0 )
F_37 ( V_42 -> V_27 , L_3 ,
V_32 ) ;
V_32 = F_41 ( V_18 , V_16 -> V_21 ) ;
if ( V_32 < 0 ) {
F_37 ( V_42 -> V_27 , L_4 ,
V_32 ) ;
return V_32 ;
}
V_16 -> V_73 = false ;
V_16 -> V_21 = F_42 ( V_18 , V_42 -> V_72 -> V_30 ,
V_74 , V_16 ) ;
if ( V_16 -> V_21 == NULL ) {
F_43 ( V_42 -> V_27 , L_5 ) ;
return - V_75 ;
}
}
if ( V_40 -> V_21 == V_76 )
V_66 = V_77 ;
else
V_66 = V_78 ;
switch ( V_42 -> V_72 -> V_30 ) {
case 0 :
if ( V_40 -> V_21 == V_76 ) {
V_64 = V_79 ;
V_70 = V_80 ;
}
else {
V_64 = V_81 ;
V_70 = V_82 ;
}
break;
case 1 :
case 2 :
V_64 = V_83 ;
V_70 = V_84 ;
break;
case 3 :
V_64 = V_85 ;
V_66 = V_77 ;
V_70 = V_86 ;
break;
default:
F_43 ( V_42 -> V_27 , L_6 ,
V_42 -> V_72 -> V_30 ) ;
return - V_75 ;
} ;
V_32 = F_44 ( V_18 , V_16 -> V_21 ,
V_66 , V_64 , V_87 ) ;
if ( V_32 < 0 ) {
F_43 ( V_42 -> V_27 , L_7 , V_32 ) ;
return V_32 ;
}
V_67 = F_45 ( V_55 ) ;
V_32 = F_46 ( V_18 , V_16 -> V_21 , V_67 ) ;
if ( V_32 < 0 ) {
F_43 ( V_42 -> V_27 , L_8 , V_67 ) ;
return V_32 ;
}
switch ( F_47 ( V_55 ) ) {
case V_88 :
V_68 = V_89 ;
F_48 ( V_18 , V_16 -> V_21 , 16 ) ;
break;
case V_90 :
V_68 = V_91 ;
F_48 ( V_18 , V_16 -> V_21 , 24 ) ;
break;
case V_92 :
V_68 = V_93 ;
F_48 ( V_18 , V_16 -> V_21 , 8 ) ;
break;
case V_94 :
V_68 = V_91 ;
F_48 ( V_18 , V_16 -> V_21 , 32 ) ;
break;
default:
F_43 ( V_42 -> V_27 , L_9 ,
F_47 ( V_55 ) ) ;
return - V_75 ;
}
V_32 = F_49 ( V_18 , V_16 -> V_21 , V_68 ) ;
if ( V_32 < 0 ) {
F_43 ( V_42 -> V_27 , L_10 , V_68 ) ;
return V_32 ;
}
V_71 = F_50 ( V_55 ) ;
V_69 = F_51 ( V_95 ) ;
F_52 ( V_18 , V_16 -> V_21 ,
V_69 , V_95 ) ;
V_32 = F_53 ( V_18 , V_16 -> V_21 , V_71 ) ;
if ( V_32 < 0 ) {
F_43 ( V_42 -> V_27 , L_11 ,
V_71 ) ;
return V_32 ;
}
V_32 = F_54 ( V_40 , F_55 ( V_55 ) ) ;
if ( V_32 < 0 ) {
F_43 ( V_42 -> V_27 , L_12 ,
F_55 ( V_55 ) , V_32 ) ;
return V_32 ;
}
V_46 = F_35 ( V_40 ) ;
V_32 = F_34 ( V_40 , V_14 , V_42 , V_58 -> V_43 ,
V_58 -> V_96 , V_42 -> V_72 -> V_30 ) ;
if ( V_32 < 0 )
return V_32 ;
F_56 ( V_18 , V_16 -> V_21 ,
V_97 ) ;
if ( V_58 -> V_96 % V_50 )
V_47 = ( V_58 -> V_96 / V_50 ) + 1 ;
else
V_47 = V_58 -> V_96 / V_50 ;
V_32 = F_57 ( V_18 , V_16 -> V_21 ,
V_14 -> V_46 [ V_42 -> V_72 -> V_30 ] [ V_40 -> V_21 ] . V_98 ,
V_47 , V_58 -> V_96 , 0 ,
F_38 ( V_46 , 0 ) >> V_51 ) ;
if ( V_32 < 0 ) {
F_43 ( V_42 -> V_27 , L_13 , V_32 ) ;
return V_32 ;
}
V_62 = F_58 ( V_18 ) ;
V_60 = F_59 ( V_62 , V_70 ) ;
if ( V_60 == NULL ) {
F_43 ( V_42 -> V_27 , L_14 ) ;
return - V_75 ;
}
F_60 ( V_18 , V_16 -> V_21 ,
V_16 -> V_58 ) ;
V_32 = F_61 ( V_18 , V_16 -> V_21 ) ;
if ( V_32 < 0 ) {
F_43 ( V_42 -> V_27 , L_15 , V_32 ) ;
return V_32 ;
}
if ( ! V_16 -> V_73 ) {
F_12 ( V_18 , V_16 -> V_21 , 0 ,
0 , V_16 -> V_19 [ 0 ] ) ;
F_12 ( V_18 , V_16 -> V_21 , 0 ,
1 , V_16 -> V_19 [ 1 ] ) ;
V_16 -> V_73 = true ;
}
V_32 = F_62 ( V_18 , V_16 -> V_21 , 1 ) ;
if ( V_32 < 0 )
F_43 ( V_42 -> V_27 , L_16 , V_32 ) ;
return 0 ;
}
static int F_63 ( struct V_39 * V_40 )
{
F_64 ( V_40 ) ;
return 0 ;
}
static int F_65 ( struct V_39 * V_40 , int V_99 )
{
struct V_41 * V_42 = V_40 -> V_56 ;
struct V_13 * V_14 =
F_6 ( V_42 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_100 * V_101 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_57 * V_58 = V_40 -> V_58 ;
T_4 V_102 ;
int V_20 ;
V_20 = V_22 [ V_42 -> V_72 -> V_30 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_40 -> V_21 ] ;
V_101 = V_16 -> V_21 ;
switch ( V_99 ) {
case V_103 :
case V_104 :
case V_105 :
F_66 ( V_18 , V_101 , false ) ;
F_67 ( V_18 , V_16 -> V_21 , 0 ) ;
break;
case V_106 :
case V_107 :
case V_108 :
F_66 ( V_18 , V_101 , false ) ;
F_62 ( V_18 , V_16 -> V_21 , 0 ) ;
break;
case V_109 :
V_102 = V_58 -> V_110 -> V_111 % V_58 -> V_112 ;
F_68 ( V_18 , V_16 -> V_21 , V_102 ) ;
F_66 ( V_18 , V_101 , true ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 V_74 ( struct V_100 * V_21 , void * V_35 )
{
struct V_15 * V_16 = V_35 ;
struct V_39 * V_40 = V_16 -> V_40 ;
struct V_57 * V_58 = V_40 -> V_58 ;
struct V_41 * V_42 = V_40 -> V_56 ;
struct V_13 * V_14 =
F_6 ( V_42 -> V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
T_1 V_102 ;
T_4 V_113 = F_69 ( V_58 ,
F_70 ( V_18 , V_16 -> V_21 ) ) ;
unsigned char * V_43 = V_58 -> V_43 ;
T_4 V_114 =
F_69 ( V_58 , V_58 -> V_96 ) ;
T_4 V_115 ;
T_5 V_116 ;
V_102 = F_71 ( V_58 ,
( V_58 -> V_110 -> V_111 % V_58 -> V_112 ) ) ;
F_72 ( V_42 -> V_27 , L_17 , V_102 ) ;
if ( V_43 == NULL || V_114 <= 0
|| ( V_40 -> V_21 == V_117 )
|| ! F_73 ( V_18 , V_21 ) ) {
F_74 ( V_40 ) ;
return V_102 ;
}
V_115 = F_75 ( V_18 , V_21 ) ;
if ( V_113 > V_115 ) {
if ( V_113 < V_114 ) {
V_116 = F_76 ( V_58 , V_113 - V_115 ) ;
F_77 ( V_58 -> V_118 ,
F_78 ( V_43 ,
V_58 , V_115 ) ,
V_116 ) ;
} else
F_43 ( V_42 -> V_27 , L_18 ) ;
} else {
if ( V_115 < V_114 ) {
V_116 = F_76 ( V_58 ,
V_114 - V_115 ) ;
F_77 ( V_58 -> V_118 ,
F_78 ( V_43 ,
V_58 , V_115 ) ,
V_116 ) ;
} else
F_43 ( V_42 -> V_27 , L_19 ) ;
if ( V_113 < V_114 ) {
V_116 = F_76 ( V_58 , V_113 ) ;
F_77 ( V_58 -> V_118 ,
V_43 , V_116 ) ;
} else
F_43 ( V_42 -> V_27 , L_18 ) ;
}
F_68 ( V_18 , V_21 , V_113 ) ;
F_74 ( V_40 ) ;
return V_102 ;
}
static T_4 F_79 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_56 ;
struct V_57 * V_58 = V_40 -> V_58 ;
struct V_13 * V_14 =
F_6 ( V_42 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
T_4 V_119 ;
T_6 V_120 ;
T_1 V_113 ;
int V_20 ;
V_20 = V_22 [ V_42 -> V_72 -> V_30 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_40 -> V_21 ] ;
V_113 = F_70 ( V_18 , V_16 -> V_21 ) ;
V_119 = F_69 ( V_58 , V_113 ) ;
V_120 = F_80 ( V_18 , V_16 -> V_21 ) ;
F_72 ( V_42 -> V_27 , L_20 ,
V_113 , V_120 ) ;
return V_119 ;
}
static int F_81 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_56 ;
struct V_13 * V_14 =
F_6 ( V_42 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_20 ;
V_20 = V_22 [ V_42 -> V_72 -> V_30 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_40 -> V_21 ] ;
F_7 ( & V_16 -> V_26 ) ;
F_8 ( V_14 -> V_27 ) ;
V_16 -> V_40 = V_40 ;
F_82 ( V_40 , & V_121 ) ;
V_16 -> V_21 = F_42 ( V_18 , V_42 -> V_72 -> V_30 ,
V_74 , V_16 ) ;
if ( V_16 -> V_21 == NULL ) {
F_43 ( V_42 -> V_27 , L_5 ) ;
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
return - V_75 ;
}
F_11 ( & V_16 -> V_26 ) ;
return 0 ;
}
static int F_83 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_56 ;
struct V_13 * V_14 =
F_6 ( V_42 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_32 , V_20 ;
V_20 = V_22 [ V_42 -> V_72 -> V_30 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_40 -> V_21 ] ;
F_7 ( & V_16 -> V_26 ) ;
V_32 = F_40 ( V_18 , V_16 -> V_21 ) ;
if ( V_32 < 0 ) {
F_37 ( V_42 -> V_27 , L_3 , V_32 ) ;
goto V_122;
}
V_32 = F_41 ( V_18 , V_16 -> V_21 ) ;
if ( V_32 < 0 ) {
F_37 ( V_42 -> V_27 , L_4 , V_32 ) ;
goto V_122;
}
V_16 -> V_73 = 0 ;
V_16 -> V_21 = NULL ;
V_122:
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
return V_32 ;
}
static int F_84 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_15 * V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
V_16 -> V_58 = F_85 ( V_18 ,
V_22 [ V_3 ] . V_123 , V_16 -> V_124 ) ;
if ( V_16 -> V_58 == NULL )
goto V_125;
V_16 -> V_124 =
V_16 -> V_58 -> V_124 ;
}
if ( F_23 ( V_18 , V_31 ) ) {
V_14 -> V_126 = F_85 ( V_18 ,
V_31 , 0 ) ;
if ( V_14 -> V_126 == NULL )
goto V_125;
}
return 0 ;
V_125:
for ( -- V_3 ; V_3 >= 0 ; V_3 -- ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
F_86 ( V_16 -> V_58 ) ;
}
return - V_127 ;
}
static void F_87 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_15 * V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
if ( V_16 -> V_58 ) {
F_86 ( V_16 -> V_58 ) ;
V_16 -> V_58 = NULL ;
}
}
if ( F_23 ( V_18 , V_31 ) &&
V_14 -> V_126 ) {
F_86 ( V_14 -> V_126 ) ;
V_14 -> V_126 = NULL ;
}
}
static int F_88 ( struct V_41 * V_42 )
{
struct V_128 * V_25 = V_42 -> V_25 ;
struct V_8 * V_9 = V_42 -> V_9 ;
struct V_129 * V_14 = F_89 ( V_9 -> V_27 ) ;
struct V_13 * V_130 = F_90 ( V_9 -> V_27 ) ;
struct V_131 * V_27 = V_14 -> V_132 ;
int V_32 = 0 ;
if ( V_25 -> V_133 [ V_76 ] . V_40 ||
V_25 -> V_133 [ V_117 ] . V_40 ) {
V_32 = F_91 ( V_25 ,
V_134 ,
V_27 ,
V_121 . V_135 ,
V_121 . V_135 ) ;
if ( V_32 ) {
F_43 ( V_42 -> V_27 , L_21 ,
V_32 ) ;
return V_32 ;
}
}
if ( V_25 -> V_133 [ V_76 ] . V_40 )
V_130 -> V_25 [ V_42 -> V_72 -> V_30 ] [ V_76 ] . V_136 = V_25 ;
if ( V_25 -> V_133 [ V_117 ] . V_40 )
V_130 -> V_25 [ V_42 -> V_72 -> V_30 ] [ V_117 ] . V_136 = V_25 ;
return V_32 ;
}
static int F_92 ( struct V_8 * V_9 )
{
struct V_13 * V_130 = F_6 ( V_9 ) ;
struct V_129 * V_14 = F_89 ( V_9 -> V_27 ) ;
struct V_131 * V_132 , * V_27 ;
int V_3 , V_32 = 0 ;
if ( ! V_14 )
return - V_127 ;
V_27 = V_9 -> V_27 ;
V_132 = V_14 -> V_132 ;
V_130 -> V_18 = V_14 -> V_62 ;
V_130 -> V_27 = V_9 -> V_27 ;
V_130 -> V_137 = V_138 ;
V_130 -> V_139 = V_9 -> V_140 . V_141 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_142 ) ; V_3 ++ ) {
if ( V_142 [ V_3 ] . V_143 . V_144 ) {
F_93 ( & V_130 -> V_25 [ V_3 ] [ V_76 ] . V_26 ) ;
V_32 = F_94 ( V_145 , V_132 ,
V_50 , & V_130 -> V_46 [ V_3 ] [ 0 ] ) ;
if ( V_32 < 0 )
goto V_125;
}
if ( V_142 [ V_3 ] . V_146 . V_144 ) {
F_93 ( & V_130 -> V_25 [ V_3 ] [ V_117 ] . V_26 ) ;
V_32 = F_94 ( V_145 , V_132 ,
V_50 , & V_130 -> V_46 [ V_3 ] [ 1 ] ) ;
if ( V_32 < 0 )
goto V_125;
}
}
V_32 = F_84 ( V_130 ) ;
if ( V_32 < 0 )
goto V_125;
F_95 ( V_9 -> V_27 ,
V_147 ) ;
F_96 ( V_9 -> V_27 ) ;
F_97 ( V_9 -> V_27 ) ;
F_98 ( V_9 -> V_27 ) ;
return 0 ;
V_125:
for ( -- V_3 ; V_3 >= 0 ; V_3 -- ) {
if ( V_142 [ V_3 ] . V_143 . V_144 )
F_99 ( & V_130 -> V_46 [ V_3 ] [ 0 ] ) ;
if ( V_142 [ V_3 ] . V_146 . V_144 )
F_99 ( & V_130 -> V_46 [ V_3 ] [ 1 ] ) ;
}
return V_32 ;
}
static int F_100 ( struct V_8 * V_9 )
{
struct V_13 * V_130 =
F_6 ( V_9 ) ;
int V_3 ;
F_101 ( V_9 -> V_27 ) ;
F_87 ( V_130 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_142 ) ; V_3 ++ ) {
if ( V_142 [ V_3 ] . V_143 . V_144 )
F_99 ( & V_130 -> V_46 [ V_3 ] [ 0 ] ) ;
if ( V_142 [ V_3 ] . V_146 . V_144 )
F_99 ( & V_130 -> V_46 [ V_3 ] [ 1 ] ) ;
}
return 0 ;
}
static int F_102 ( struct V_148 * V_149 )
{
struct V_129 * V_129 = F_89 ( & V_149 -> V_27 ) ;
struct V_13 * V_130 ;
int V_32 ;
if ( ! V_129 )
return - V_75 ;
V_130 = F_103 ( & V_149 -> V_27 , sizeof( * V_130 ) , V_150 ) ;
if ( ! V_130 )
return - V_151 ;
V_32 = F_104 ( & V_149 -> V_27 , V_129 ) ;
if ( V_32 < 0 )
return - V_127 ;
V_130 -> V_18 = V_129 -> V_62 ;
F_105 ( V_149 , V_130 ) ;
V_32 = F_106 ( & V_149 -> V_27 , & V_152 ) ;
if ( V_32 < 0 )
goto V_153;
V_32 = F_107 ( & V_149 -> V_27 , & V_154 ,
V_142 , F_2 ( V_142 ) ) ;
if ( V_32 < 0 )
goto V_155;
return 0 ;
V_155:
F_108 ( & V_149 -> V_27 ) ;
V_153:
F_109 ( & V_149 -> V_27 , V_129 ) ;
return 0 ;
}
static int F_110 ( struct V_148 * V_149 )
{
struct V_129 * V_129 = F_89 ( & V_149 -> V_27 ) ;
F_108 ( & V_149 -> V_27 ) ;
F_111 ( & V_149 -> V_27 ) ;
F_109 ( & V_149 -> V_27 , V_129 ) ;
return 0 ;
}
static int F_112 ( struct V_131 * V_27 )
{
return 0 ;
}
static int F_113 ( struct V_131 * V_27 )
{
struct V_13 * V_14 = F_90 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
F_114 ( V_18 ) ;
F_87 ( V_14 ) ;
F_115 ( V_18 ) ;
return 0 ;
}
static int F_116 ( struct V_131 * V_27 )
{
struct V_13 * V_14 = F_90 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_32 ;
if ( V_14 -> V_137 >= V_156 )
return 0 ;
if ( F_20 ( V_18 , V_31 ) ) {
V_32 = F_25 ( V_18 , V_31 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
F_26 ( V_18 , V_31 ) ;
}
F_113 ( V_27 ) ;
V_14 -> V_137 = V_156 ;
return 0 ;
}
static int F_117 ( struct V_131 * V_27 )
{
struct V_13 * V_14 = F_90 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_32 ;
if ( V_14 -> V_137 != V_156 )
return 0 ;
V_32 = F_118 ( V_18 ) ;
if ( V_32 < 0 ) {
F_43 ( V_27 , L_22 , V_32 ) ;
return V_32 ;
}
V_32 = F_84 ( V_14 ) ;
if ( V_32 < 0 ) {
F_43 ( V_27 , L_23 , V_32 ) ;
return V_32 ;
}
V_32 = F_119 ( V_18 ) ;
if ( V_32 < 0 )
return V_32 ;
else if ( V_32 == 1 )
return 0 ;
if ( F_21 ( V_18 , V_31 ) ) {
V_32 = F_24 ( V_18 , V_31 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_120 ( V_18 ) ;
if ( V_32 < 0 )
return V_32 ;
F_27 ( V_18 , V_31 ) ;
}
V_14 -> V_137 = V_138 ;
return V_32 ;
}
static void F_121 ( struct V_131 * V_27 )
{
struct V_13 * V_14 = F_90 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_15 * V_16 ;
int V_3 , V_125 ;
if ( V_14 -> V_137 != V_157 )
return;
V_125 = F_118 ( V_18 ) ;
if ( V_125 < 0 ) {
F_43 ( V_27 , L_22 , V_125 ) ;
return;
}
V_125 = F_84 ( V_14 ) ;
if ( V_125 < 0 ) {
F_43 ( V_27 , L_23 , V_125 ) ;
return;
}
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
if ( ! V_16 -> V_40 )
continue;
V_125 = F_122 ( V_16 -> V_58 ,
& V_16 -> V_158 ) ;
if ( V_125 < 0 )
F_43 ( V_27 , L_24 , V_3 ) ;
}
F_123 ( V_14 -> V_139 -> V_27 ) ;
V_125 = F_119 ( V_18 ) ;
if ( V_125 < 0 )
return;
else if ( V_125 == 1 )
return;
V_14 -> V_137 = V_138 ;
return;
}
static int F_124 ( struct V_131 * V_27 )
{
struct V_13 * V_14 = F_90 ( V_27 ) ;
struct V_15 * V_16 ;
int V_3 , V_125 ;
if ( V_14 -> V_137 == V_157 )
return 0 ;
else if ( V_14 -> V_137 == V_138 ) {
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
if ( ! V_16 -> V_40 )
continue;
F_37 ( V_27 , L_25 , V_3 ) ;
F_125 ( V_16 -> V_136 ) ;
F_126 ( 2 ) ;
}
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
if ( ! V_16 -> V_40 )
continue;
F_37 ( V_27 , L_26 , V_3 ) ;
V_125 = F_127 ( V_16 -> V_58 ,
& V_16 -> V_158 ) ;
if ( V_125 < 0 )
F_43 ( V_27 , L_27 , V_3 ) ;
}
F_113 ( V_27 ) ;
}
F_128 ( V_14 -> V_139 -> V_27 ) ;
F_129 ( V_14 -> V_139 -> V_27 ) ;
V_14 -> V_137 = V_157 ;
return 0 ;
}
