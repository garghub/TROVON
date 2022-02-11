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
static int F_19 ( struct V_29 * V_30 ,
struct V_13 * V_14 , struct V_31 * V_32 ,
unsigned char * V_33 , T_2 V_34 , int V_25 )
{
struct V_35 * V_36 = F_20 ( V_30 ) ;
int V_3 , V_37 , V_21 = V_30 -> V_21 ;
V_37 = F_21 ( V_34 ) ;
F_22 ( V_32 -> V_27 , L_1 ,
V_33 , V_34 , V_37 ) ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ ) {
T_1 V_38 = ( ( ( V_3 << 2 ) + V_3 ) ) >> 1 ;
T_1 V_39 = F_23 ( V_36 , V_3 * V_40 ) >> V_41 ;
T_1 * V_42 ;
F_22 ( V_32 -> V_27 , L_2 , V_3 , V_38 , V_39 ) ;
V_42 = ( T_1 * ) ( V_14 -> V_36 [ V_25 ] [ V_21 ] . V_43 + V_38 ) ;
if ( V_3 & 1 )
* V_42 |= ( V_39 << 4 ) ;
else
* V_42 |= V_39 ;
}
return 0 ;
}
static int F_24 ( struct V_29 * V_30 ,
struct V_44 * V_45 )
{
struct V_31 * V_32 = V_30 -> V_46 ;
struct V_47 * V_48 = V_30 -> V_48 ;
struct V_13 * V_14 =
F_6 ( V_32 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_35 * V_36 ;
enum V_53 V_54 ;
enum V_55 V_56 ;
T_1 V_57 , V_58 , V_59 , V_37 , V_60 ;
T_3 V_61 ;
int V_62 , V_20 ;
V_20 = V_22 [ V_32 -> V_63 -> V_64 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_30 -> V_21 ] ;
if ( V_16 -> V_65 ) {
V_62 = F_25 ( V_18 , V_16 -> V_21 ) ;
if ( V_62 < 0 )
F_22 ( V_32 -> V_27 , L_3 ,
V_62 ) ;
V_62 = F_26 ( V_18 , V_16 -> V_21 ) ;
if ( V_62 < 0 ) {
F_22 ( V_32 -> V_27 , L_4 ,
V_62 ) ;
return V_62 ;
}
V_16 -> V_65 = false ;
V_16 -> V_21 = F_27 ( V_18 , V_32 -> V_63 -> V_64 ,
V_66 , V_16 ) ;
if ( V_16 -> V_21 == NULL ) {
F_28 ( V_32 -> V_27 , L_5 ) ;
return - V_67 ;
}
}
if ( V_30 -> V_21 == V_68 )
V_56 = V_69 ;
else
V_56 = V_70 ;
switch ( V_32 -> V_63 -> V_64 ) {
case 0 :
if ( V_30 -> V_21 == V_68 ) {
V_54 = V_71 ;
V_60 = V_72 ;
}
else {
V_54 = V_73 ;
V_60 = V_74 ;
}
break;
case 1 :
case 2 :
V_54 = V_75 ;
V_60 = V_76 ;
break;
case 3 :
V_54 = V_77 ;
V_56 = V_69 ;
V_60 = V_78 ;
break;
default:
F_28 ( V_32 -> V_27 , L_6 ,
V_32 -> V_63 -> V_64 ) ;
return - V_67 ;
} ;
V_62 = F_29 ( V_18 , V_16 -> V_21 ,
V_56 , V_54 , V_79 ) ;
if ( V_62 < 0 ) {
F_28 ( V_32 -> V_27 , L_7 , V_62 ) ;
return V_62 ;
}
V_57 = F_30 ( V_45 ) ;
V_62 = F_31 ( V_18 , V_16 -> V_21 , V_57 ) ;
if ( V_62 < 0 ) {
F_28 ( V_32 -> V_27 , L_8 , V_57 ) ;
return V_62 ;
}
switch ( F_32 ( V_45 ) ) {
case V_80 :
V_58 = V_81 ;
F_33 ( V_18 , V_16 -> V_21 , 16 ) ;
break;
case V_82 :
V_58 = V_83 ;
F_33 ( V_18 , V_16 -> V_21 , 24 ) ;
break;
case V_84 :
V_58 = V_85 ;
F_33 ( V_18 , V_16 -> V_21 , 8 ) ;
break;
case V_86 :
V_58 = V_83 ;
F_33 ( V_18 , V_16 -> V_21 , 32 ) ;
break;
default:
F_28 ( V_32 -> V_27 , L_9 ,
F_32 ( V_45 ) ) ;
return - V_67 ;
}
V_62 = F_34 ( V_18 , V_16 -> V_21 , V_58 ) ;
if ( V_62 < 0 ) {
F_28 ( V_32 -> V_27 , L_10 , V_58 ) ;
return V_62 ;
}
V_61 = F_35 ( V_45 ) ;
V_59 = F_36 ( V_87 ) ;
F_37 ( V_18 , V_16 -> V_21 ,
V_59 , V_87 ) ;
V_62 = F_38 ( V_18 , V_16 -> V_21 , V_61 ) ;
if ( V_62 < 0 ) {
F_28 ( V_32 -> V_27 , L_11 ,
V_61 ) ;
return V_62 ;
}
V_62 = F_39 ( V_30 , F_40 ( V_45 ) ) ;
if ( V_62 < 0 ) {
F_28 ( V_32 -> V_27 , L_12 ,
F_40 ( V_45 ) , V_62 ) ;
return V_62 ;
}
V_36 = F_20 ( V_30 ) ;
V_62 = F_19 ( V_30 , V_14 , V_32 , V_48 -> V_33 ,
V_48 -> V_88 , V_32 -> V_63 -> V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
F_41 ( V_18 , V_16 -> V_21 ,
V_89 ) ;
if ( V_48 -> V_88 % V_40 )
V_37 = ( V_48 -> V_88 / V_40 ) + 1 ;
else
V_37 = V_48 -> V_88 / V_40 ;
V_62 = F_42 ( V_18 , V_16 -> V_21 ,
V_14 -> V_36 [ V_32 -> V_63 -> V_64 ] [ V_30 -> V_21 ] . V_90 ,
V_37 , V_48 -> V_88 , 0 ,
F_23 ( V_36 , 0 ) >> V_41 ) ;
if ( V_62 < 0 ) {
F_28 ( V_32 -> V_27 , L_13 , V_62 ) ;
return V_62 ;
}
V_52 = F_43 ( V_18 ) ;
V_50 = F_44 ( V_52 , V_60 ) ;
if ( V_50 == NULL ) {
F_28 ( V_32 -> V_27 , L_14 ) ;
return - V_67 ;
}
F_45 ( V_18 , V_16 -> V_21 ,
V_16 -> V_48 ) ;
V_62 = F_46 ( V_18 , V_16 -> V_21 ) ;
if ( V_62 < 0 ) {
F_28 ( V_32 -> V_27 , L_15 , V_62 ) ;
return V_62 ;
}
if ( ! V_16 -> V_65 ) {
F_12 ( V_18 , V_16 -> V_21 , 0 ,
0 , V_16 -> V_19 [ 0 ] ) ;
F_12 ( V_18 , V_16 -> V_21 , 0 ,
1 , V_16 -> V_19 [ 1 ] ) ;
V_16 -> V_65 = true ;
}
V_62 = F_47 ( V_18 , V_16 -> V_21 , 1 ) ;
if ( V_62 < 0 )
F_28 ( V_32 -> V_27 , L_16 , V_62 ) ;
return 0 ;
}
static int F_48 ( struct V_29 * V_30 )
{
F_49 ( V_30 ) ;
return 0 ;
}
static int F_50 ( struct V_29 * V_30 , int V_91 )
{
struct V_31 * V_32 = V_30 -> V_46 ;
struct V_13 * V_14 =
F_6 ( V_32 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_92 * V_93 ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_47 * V_48 = V_30 -> V_48 ;
T_4 V_94 ;
int V_20 ;
V_20 = V_22 [ V_32 -> V_63 -> V_64 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_30 -> V_21 ] ;
V_93 = V_16 -> V_21 ;
switch ( V_91 ) {
case V_95 :
case V_96 :
case V_97 :
F_51 ( V_18 , V_93 , false ) ;
F_52 ( V_18 , V_16 -> V_21 , 0 ) ;
break;
case V_98 :
case V_99 :
case V_100 :
F_51 ( V_18 , V_93 , false ) ;
F_47 ( V_18 , V_16 -> V_21 , 0 ) ;
break;
case V_101 :
V_94 = V_48 -> V_102 -> V_103 % V_48 -> V_104 ;
F_53 ( V_18 , V_16 -> V_21 , V_94 ) ;
F_51 ( V_18 , V_93 , true ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 V_66 ( struct V_92 * V_21 , void * V_105 )
{
struct V_15 * V_16 = V_105 ;
struct V_29 * V_30 = V_16 -> V_30 ;
struct V_47 * V_48 = V_30 -> V_48 ;
struct V_31 * V_32 = V_30 -> V_46 ;
struct V_13 * V_14 =
F_6 ( V_32 -> V_9 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
T_1 V_94 ;
T_4 V_106 = F_54 ( V_48 ,
F_55 ( V_18 , V_16 -> V_21 ) ) ;
unsigned char * V_33 = V_48 -> V_33 ;
T_4 V_107 =
F_54 ( V_48 , V_48 -> V_88 ) ;
T_4 V_108 ;
T_5 V_109 ;
V_94 = F_56 ( V_48 ,
( V_48 -> V_102 -> V_103 % V_48 -> V_104 ) ) ;
F_57 ( V_32 -> V_27 , L_17 , V_94 ) ;
if ( V_33 == NULL || V_107 <= 0
|| ( V_30 -> V_21 == V_110 )
|| ! F_58 ( V_18 , V_21 ) ) {
F_59 ( V_30 ) ;
return V_94 ;
}
V_108 = F_60 ( V_18 , V_21 ) ;
if ( V_106 > V_108 ) {
if ( V_106 < V_107 ) {
V_109 = F_61 ( V_48 , V_106 - V_108 ) ;
F_62 ( V_48 -> V_111 ,
F_63 ( V_33 ,
V_48 , V_108 ) ,
V_109 ) ;
} else
F_28 ( V_32 -> V_27 , L_18 ) ;
} else {
if ( V_108 < V_107 ) {
V_109 = F_61 ( V_48 ,
V_107 - V_108 ) ;
F_62 ( V_48 -> V_111 ,
F_63 ( V_33 ,
V_48 , V_108 ) ,
V_109 ) ;
} else
F_28 ( V_32 -> V_27 , L_19 ) ;
if ( V_106 < V_107 ) {
V_109 = F_61 ( V_48 , V_106 ) ;
F_62 ( V_48 -> V_111 ,
V_33 , V_109 ) ;
} else
F_28 ( V_32 -> V_27 , L_18 ) ;
}
F_53 ( V_18 , V_21 , V_106 ) ;
F_59 ( V_30 ) ;
return V_94 ;
}
static T_4 F_64 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_46 ;
struct V_47 * V_48 = V_30 -> V_48 ;
struct V_13 * V_14 =
F_6 ( V_32 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
T_4 V_112 ;
T_6 V_113 ;
T_1 V_106 ;
int V_20 ;
V_20 = V_22 [ V_32 -> V_63 -> V_64 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_30 -> V_21 ] ;
V_106 = F_55 ( V_18 , V_16 -> V_21 ) ;
V_112 = F_54 ( V_48 , V_106 ) ;
V_113 = F_65 ( V_18 , V_16 -> V_21 ) ;
F_57 ( V_32 -> V_27 , L_20 ,
V_106 , V_113 ) ;
return V_112 ;
}
static int F_66 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_46 ;
struct V_13 * V_14 =
F_6 ( V_32 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_20 ;
V_20 = V_22 [ V_32 -> V_63 -> V_64 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_30 -> V_21 ] ;
F_7 ( & V_16 -> V_26 ) ;
F_8 ( V_14 -> V_27 ) ;
F_67 ( V_32 , V_16 ) ;
V_16 -> V_30 = V_30 ;
F_68 ( V_30 , & V_114 ) ;
V_16 -> V_21 = F_27 ( V_18 , V_32 -> V_63 -> V_64 ,
V_66 , V_16 ) ;
if ( V_16 -> V_21 == NULL ) {
F_28 ( V_32 -> V_27 , L_5 ) ;
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
return - V_67 ;
}
F_11 ( & V_16 -> V_26 ) ;
return 0 ;
}
static int F_69 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_46 ;
struct V_13 * V_14 =
F_6 ( V_32 -> V_9 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_62 , V_20 ;
V_20 = V_22 [ V_32 -> V_63 -> V_64 ] . V_24 ;
V_16 = & V_14 -> V_25 [ V_20 ] [ V_30 -> V_21 ] ;
F_7 ( & V_16 -> V_26 ) ;
V_62 = F_25 ( V_18 , V_16 -> V_21 ) ;
if ( V_62 < 0 ) {
F_22 ( V_32 -> V_27 , L_3 , V_62 ) ;
goto V_115;
}
V_62 = F_26 ( V_18 , V_16 -> V_21 ) ;
if ( V_62 < 0 ) {
F_22 ( V_32 -> V_27 , L_4 , V_62 ) ;
goto V_115;
}
V_16 -> V_65 = 0 ;
V_16 -> V_21 = NULL ;
V_115:
F_9 ( V_14 -> V_27 ) ;
F_10 ( V_14 -> V_27 ) ;
F_11 ( & V_16 -> V_26 ) ;
return V_62 ;
}
static int F_70 ( struct V_13 * V_14 )
{
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_15 * V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
V_16 -> V_48 = F_71 ( V_18 ,
V_22 [ V_3 ] . V_116 , V_16 -> V_117 ) ;
if ( V_16 -> V_48 == NULL )
goto V_118;
V_16 -> V_117 =
V_16 -> V_48 -> V_117 ;
}
return 0 ;
V_118:
for ( -- V_3 ; V_3 >= 0 ; V_3 -- ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
F_72 ( V_16 -> V_48 ) ;
}
return - V_119 ;
}
static void F_73 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
F_72 ( V_16 -> V_48 ) ;
}
}
static int F_74 ( struct V_31 * V_32 )
{
struct V_120 * V_25 = V_32 -> V_25 ;
struct V_8 * V_9 = V_32 -> V_9 ;
struct V_121 * V_14 = F_75 ( V_9 -> V_27 ) ;
struct V_13 * V_122 = F_76 ( V_9 -> V_27 ) ;
struct V_123 * V_27 = V_14 -> V_124 ;
int V_62 = 0 ;
if ( V_25 -> V_125 [ V_68 ] . V_30 ||
V_25 -> V_125 [ V_110 ] . V_30 ) {
V_62 = F_77 ( V_25 ,
V_126 ,
V_27 ,
V_114 . V_127 ,
V_114 . V_127 ) ;
if ( V_62 ) {
F_28 ( V_32 -> V_27 , L_21 ,
V_62 ) ;
return V_62 ;
}
}
if ( V_25 -> V_125 [ V_68 ] . V_30 )
V_122 -> V_25 [ V_32 -> V_63 -> V_64 ] [ V_68 ] . V_128 = V_25 ;
if ( V_25 -> V_125 [ V_110 ] . V_30 )
V_122 -> V_25 [ V_32 -> V_63 -> V_64 ] [ V_110 ] . V_128 = V_25 ;
return V_62 ;
}
static int F_78 ( struct V_8 * V_9 )
{
struct V_13 * V_122 = F_6 ( V_9 ) ;
struct V_121 * V_14 = F_75 ( V_9 -> V_27 ) ;
struct V_123 * V_124 , * V_27 ;
int V_3 , V_62 = 0 ;
if ( ! V_14 )
return - V_119 ;
V_27 = V_9 -> V_27 ;
V_124 = V_14 -> V_124 ;
V_122 -> V_18 = V_14 -> V_52 ;
V_122 -> V_27 = V_9 -> V_27 ;
V_122 -> V_129 = V_130 ;
V_122 -> V_131 = V_9 -> V_132 . V_133 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_134 ) ; V_3 ++ ) {
if ( V_134 [ V_3 ] . V_135 . V_136 ) {
F_79 ( & V_122 -> V_25 [ V_3 ] [ V_68 ] . V_26 ) ;
V_62 = F_80 ( V_137 , V_124 ,
V_40 , & V_122 -> V_36 [ V_3 ] [ 0 ] ) ;
if ( V_62 < 0 )
goto V_118;
}
if ( V_134 [ V_3 ] . V_138 . V_136 ) {
F_79 ( & V_122 -> V_25 [ V_3 ] [ V_110 ] . V_26 ) ;
V_62 = F_80 ( V_137 , V_124 ,
V_40 , & V_122 -> V_36 [ V_3 ] [ 1 ] ) ;
if ( V_62 < 0 )
goto V_118;
}
}
F_70 ( V_122 ) ;
F_81 ( V_9 -> V_27 ,
V_139 ) ;
F_82 ( V_9 -> V_27 ) ;
F_83 ( V_9 -> V_27 ) ;
F_84 ( V_9 -> V_27 ) ;
return 0 ;
V_118:
for (; V_3 >= 0 ; V_3 -- ) {
if ( V_134 [ V_3 ] . V_135 . V_136 )
F_85 ( & V_122 -> V_36 [ V_3 ] [ 0 ] ) ;
if ( V_134 [ V_3 ] . V_138 . V_136 )
F_85 ( & V_122 -> V_36 [ V_3 ] [ 1 ] ) ;
}
return V_62 ;
}
static int F_86 ( struct V_8 * V_9 )
{
struct V_13 * V_122 =
F_6 ( V_9 ) ;
int V_3 ;
F_87 ( V_9 -> V_27 ) ;
F_73 ( V_122 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_134 ) ; V_3 ++ ) {
if ( V_134 [ V_3 ] . V_135 . V_136 )
F_85 ( & V_122 -> V_36 [ V_3 ] [ 0 ] ) ;
if ( V_134 [ V_3 ] . V_138 . V_136 )
F_85 ( & V_122 -> V_36 [ V_3 ] [ 1 ] ) ;
}
return 0 ;
}
static int F_88 ( struct V_140 * V_141 )
{
struct V_121 * V_121 = F_75 ( & V_141 -> V_27 ) ;
struct V_13 * V_122 ;
int V_62 ;
if ( ! V_121 )
return - V_67 ;
V_122 = F_89 ( & V_141 -> V_27 , sizeof( * V_122 ) , V_142 ) ;
if ( ! V_122 )
return - V_143 ;
V_62 = F_90 ( & V_141 -> V_27 , V_121 ) ;
if ( V_62 < 0 )
return - V_119 ;
V_122 -> V_18 = V_121 -> V_52 ;
F_91 ( V_141 , V_122 ) ;
V_62 = F_92 ( & V_141 -> V_27 , & V_144 ) ;
if ( V_62 < 0 )
goto V_145;
V_62 = F_93 ( & V_141 -> V_27 , & V_146 ,
V_134 , F_2 ( V_134 ) ) ;
if ( V_62 < 0 )
goto V_147;
return 0 ;
V_147:
F_94 ( & V_141 -> V_27 ) ;
V_145:
F_95 ( & V_141 -> V_27 , V_121 ) ;
return 0 ;
}
static int F_96 ( struct V_140 * V_141 )
{
struct V_121 * V_121 = F_75 ( & V_141 -> V_27 ) ;
F_94 ( & V_141 -> V_27 ) ;
F_97 ( & V_141 -> V_27 ) ;
F_95 ( & V_141 -> V_27 , V_121 ) ;
return 0 ;
}
static int F_98 ( struct V_123 * V_27 )
{
return 0 ;
}
static int F_99 ( struct V_123 * V_27 )
{
struct V_13 * V_14 = F_76 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
if ( V_14 -> V_129 >= V_148 )
return 0 ;
F_100 ( V_18 ) ;
F_101 ( V_18 ) ;
V_14 -> V_129 = V_148 ;
return 0 ;
}
static int F_102 ( struct V_123 * V_27 )
{
struct V_13 * V_14 = F_76 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
int V_62 ;
if ( V_14 -> V_129 != V_148 )
return 0 ;
V_62 = F_103 ( V_18 ) ;
if ( V_62 < 0 ) {
F_28 ( V_27 , L_22 , V_62 ) ;
return V_62 ;
}
V_62 = F_70 ( V_14 ) ;
if ( V_62 < 0 ) {
F_28 ( V_27 , L_23 , V_62 ) ;
return V_62 ;
}
V_62 = F_104 ( V_18 ) ;
if ( V_62 < 0 )
return V_62 ;
else if ( V_62 == 1 )
return 0 ;
V_14 -> V_129 = V_130 ;
return V_62 ;
}
static void F_105 ( struct V_123 * V_27 )
{
struct V_13 * V_14 = F_76 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_15 * V_16 ;
int V_3 , V_118 ;
if ( V_14 -> V_129 != V_149 )
return;
V_118 = F_103 ( V_18 ) ;
if ( V_118 < 0 ) {
F_28 ( V_27 , L_22 , V_118 ) ;
return;
}
V_118 = F_70 ( V_14 ) ;
if ( V_118 < 0 ) {
F_28 ( V_27 , L_23 , V_118 ) ;
return;
}
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
if ( ! V_16 -> V_30 )
continue;
V_118 = F_106 ( V_16 -> V_48 ,
& V_16 -> V_150 ) ;
if ( V_118 < 0 )
F_28 ( V_27 , L_24 , V_3 ) ;
}
F_107 ( V_14 -> V_131 -> V_27 ) ;
V_118 = F_104 ( V_18 ) ;
if ( V_118 < 0 )
return;
else if ( V_118 == 1 )
return;
V_14 -> V_129 = V_130 ;
return;
}
static int F_108 ( struct V_123 * V_27 )
{
struct V_13 * V_14 = F_76 ( V_27 ) ;
struct V_17 * V_18 = V_14 -> V_18 ;
struct V_15 * V_16 ;
int V_3 , V_118 ;
if ( V_14 -> V_129 == V_149 )
return 0 ;
else if ( V_14 -> V_129 == V_130 ) {
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
if ( ! V_16 -> V_30 )
continue;
F_22 ( V_27 , L_25 , V_3 ) ;
F_109 ( V_16 -> V_128 ) ;
F_110 ( 2 ) ;
}
for ( V_3 = 0 ; V_3 < F_2 ( V_22 ) ; V_3 ++ ) {
V_16 = & V_14 -> V_25 [ V_22 [ V_3 ] . V_24 ] [ V_22 [ V_3 ] . V_21 ] ;
if ( ! V_16 -> V_30 )
continue;
F_22 ( V_27 , L_26 , V_3 ) ;
V_118 = F_111 ( V_16 -> V_48 ,
& V_16 -> V_150 ) ;
if ( V_118 < 0 )
F_28 ( V_27 , L_27 , V_3 ) ;
}
F_100 ( V_18 ) ;
F_101 ( V_18 ) ;
}
F_112 ( V_14 -> V_131 -> V_27 ) ;
F_113 ( V_14 -> V_131 -> V_27 ) ;
V_14 -> V_129 = V_149 ;
return 0 ;
}
