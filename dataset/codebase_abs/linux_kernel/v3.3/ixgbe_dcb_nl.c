int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_5 * V_7 = NULL ;
int V_8 ;
if ( ! V_2 || ! V_3 )
return - V_9 ;
for ( V_8 = V_10 ; V_8 < V_4 + V_10 ; V_8 ++ ) {
V_6 = & V_2 -> V_11 [ V_8 - V_10 ] ;
V_7 = & V_3 -> V_11 [ V_8 - V_10 ] ;
V_7 -> V_12 [ V_13 ] . V_14 =
V_6 -> V_12 [ V_13 ] . V_14 ;
V_7 -> V_12 [ V_13 ] . V_15 =
V_6 -> V_12 [ V_13 ] . V_15 ;
V_7 -> V_12 [ V_13 ] . V_16 =
V_6 -> V_12 [ V_13 ] . V_16 ;
V_7 -> V_12 [ V_13 ] . V_17 =
V_6 -> V_12 [ V_13 ] . V_17 ;
V_7 -> V_12 [ V_18 ] . V_14 =
V_6 -> V_12 [ V_18 ] . V_14 ;
V_7 -> V_12 [ V_18 ] . V_15 =
V_6 -> V_12 [ V_18 ] . V_15 ;
V_7 -> V_12 [ V_18 ] . V_16 =
V_6 -> V_12 [ V_18 ] . V_16 ;
V_7 -> V_12 [ V_18 ] . V_17 =
V_6 -> V_12 [ V_18 ] . V_17 ;
}
for ( V_8 = V_19 ; V_8 < V_20 ; V_8 ++ ) {
V_3 -> V_21 [ V_13 ]
[ V_8 - V_19 ] = V_2 -> V_21
[ V_13 ] [ V_8 - V_19 ] ;
V_3 -> V_21 [ V_18 ]
[ V_8 - V_19 ] = V_2 -> V_21
[ V_18 ] [ V_8 - V_19 ] ;
}
for ( V_8 = V_22 ; V_8 < V_23 ; V_8 ++ ) {
V_3 -> V_11 [ V_8 - V_22 ] . V_24 =
V_2 -> V_11 [ V_8 - V_22 ] . V_24 ;
}
V_3 -> V_25 = V_2 -> V_25 ;
return 0 ;
}
static T_1 F_2 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
return ! ! ( V_29 -> V_30 & V_31 ) ;
}
static T_1 F_4 ( struct V_26 * V_27 , T_1 V_32 )
{
T_1 V_33 = 0 ;
T_1 V_34 [ V_35 ] = { 0 } ;
int V_8 ;
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( ! ( V_29 -> V_36 & V_37 ) )
return 1 ;
if ( ! ! V_32 != ! ( V_29 -> V_30 & V_31 ) )
return V_33 ;
if ( V_32 > 0 ) {
V_33 = F_5 ( V_27 , V_29 -> V_38 . V_39 . V_40 ) ;
F_6 ( & V_29 -> V_38 , V_13 , V_34 ) ;
} else {
V_33 = F_5 ( V_27 , 0 ) ;
}
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ )
F_7 ( V_27 , V_8 , V_34 [ V_8 ] ) ;
return V_33 ;
}
static void F_8 ( struct V_26 * V_27 ,
T_1 * V_42 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
int V_8 , V_43 ;
memset ( V_42 , 0xff , V_44 ) ;
for ( V_8 = 0 ; V_8 < V_27 -> V_45 ; V_8 ++ )
V_42 [ V_8 ] = V_29 -> V_46 . V_47 . V_42 [ V_8 ] ;
switch ( V_29 -> V_46 . V_47 . type ) {
case V_48 :
case V_49 :
for ( V_43 = 0 ; V_43 < V_27 -> V_45 ; V_43 ++ , V_8 ++ )
V_42 [ V_8 ] = V_29 -> V_46 . V_47 . V_50 [ V_43 ] ;
break;
default:
break;
}
}
static void F_9 ( struct V_26 * V_27 , int V_51 ,
T_1 V_52 , T_1 V_15 , T_1 V_53 ,
T_1 V_54 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( V_52 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_14 = V_52 ;
if ( V_15 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_15 = V_15 ;
if ( V_53 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_16 =
V_53 ;
if ( V_54 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_17 =
V_54 ;
if ( ( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_14 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_14 ) ||
( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_15 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_15 ) ||
( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_16 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_16 ) ||
( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_17 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_17 ) )
V_29 -> V_57 |= V_58 ;
if ( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 0 ] . V_17 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_17 )
V_29 -> V_57 |= V_59 | V_60 ;
}
static void F_10 ( struct V_26 * V_27 , int V_15 ,
T_1 V_53 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_56 . V_21 [ 0 ] [ V_15 ] = V_53 ;
if ( V_29 -> V_56 . V_21 [ 0 ] [ V_15 ] !=
V_29 -> V_38 . V_21 [ 0 ] [ V_15 ] )
V_29 -> V_57 |= V_58 ;
}
static void F_11 ( struct V_26 * V_27 , int V_51 ,
T_1 V_52 , T_1 V_15 , T_1 V_53 ,
T_1 V_54 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( V_52 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_14 = V_52 ;
if ( V_15 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_15 = V_15 ;
if ( V_53 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_16 =
V_53 ;
if ( V_54 != V_55 )
V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_17 =
V_54 ;
if ( ( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_14 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_14 ) ||
( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_15 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_15 ) ||
( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_16 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_16 ) ||
( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_17 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_17 ) )
V_29 -> V_57 |= V_61 ;
if ( V_29 -> V_56 . V_11 [ V_51 ] . V_12 [ 1 ] . V_17 !=
V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_17 )
V_29 -> V_57 |= V_59 ;
}
static void F_12 ( struct V_26 * V_27 , int V_15 ,
T_1 V_53 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_56 . V_21 [ 1 ] [ V_15 ] = V_53 ;
if ( V_29 -> V_56 . V_21 [ 1 ] [ V_15 ] !=
V_29 -> V_38 . V_21 [ 1 ] [ V_15 ] )
V_29 -> V_57 |= V_61 ;
}
static void F_13 ( struct V_26 * V_27 , int V_51 ,
T_1 * V_52 , T_1 * V_15 , T_1 * V_53 ,
T_1 * V_54 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_52 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_14 ;
* V_15 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_15 ;
* V_53 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_16 ;
* V_54 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 0 ] . V_17 ;
}
static void F_14 ( struct V_26 * V_27 , int V_15 ,
T_1 * V_53 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_53 = V_29 -> V_38 . V_21 [ 0 ] [ V_15 ] ;
}
static void F_15 ( struct V_26 * V_27 , int V_51 ,
T_1 * V_52 , T_1 * V_15 , T_1 * V_53 ,
T_1 * V_54 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_52 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_14 ;
* V_15 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_15 ;
* V_53 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_16 ;
* V_54 = V_29 -> V_38 . V_11 [ V_51 ] . V_12 [ 1 ] . V_17 ;
}
static void F_16 ( struct V_26 * V_27 , int V_15 ,
T_1 * V_53 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_53 = V_29 -> V_38 . V_21 [ 1 ] [ V_15 ] ;
}
static void F_17 ( struct V_26 * V_27 , int V_62 ,
T_1 V_63 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_56 . V_11 [ V_62 ] . V_24 = V_63 ;
if ( V_29 -> V_56 . V_11 [ V_62 ] . V_24 !=
V_29 -> V_38 . V_11 [ V_62 ] . V_24 ) {
V_29 -> V_57 |= V_59 ;
V_29 -> V_56 . V_25 = true ;
}
}
static void F_18 ( struct V_26 * V_27 , int V_62 ,
T_1 * V_63 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_63 = V_29 -> V_38 . V_11 [ V_62 ] . V_24 ;
}
static void F_19 ( struct V_26 * V_64 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
while ( F_20 ( V_65 , & V_29 -> V_32 ) )
F_21 ( 1000 , 2000 ) ;
if ( F_22 ( V_64 ) )
V_64 -> V_66 -> V_67 ( V_64 ) ;
F_23 ( V_29 ) ;
F_24 ( V_29 ) ;
if ( F_22 ( V_64 ) )
V_64 -> V_66 -> V_68 ( V_64 ) ;
F_25 ( V_65 , & V_29 -> V_32 ) ;
}
static T_1 F_26 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
int V_69 , V_8 ;
#ifdef F_27
struct V_70 V_71 = {
. V_72 = V_73 ,
. V_74 = V_75 ,
} ;
T_1 V_76 ;
if ( V_29 -> V_36 & V_77 ) {
V_71 . V_72 = V_78 ;
V_76 = F_28 ( V_27 , & V_71 ) ;
} else {
V_76 = F_29 ( V_27 , & V_71 ) ;
}
#endif
if ( ! ( V_29 -> V_36 & V_37 ) )
return 1 ;
V_69 = F_1 ( & V_29 -> V_56 , & V_29 -> V_38 ,
V_79 ) ;
if ( V_69 )
return V_80 ;
if ( V_29 -> V_38 . V_25 ) {
switch ( V_29 -> V_46 . V_47 . type ) {
case V_48 :
case V_49 :
if ( V_29 -> V_46 . V_81 . V_82 != V_83 )
V_29 -> V_84 =
V_29 -> V_46 . V_81 . V_82 ;
break;
default:
break;
}
V_29 -> V_46 . V_81 . V_85 = V_83 ;
} else {
switch ( V_29 -> V_46 . V_47 . type ) {
case V_86 :
V_29 -> V_46 . V_81 . V_85 = V_87 ;
break;
case V_48 :
case V_49 :
V_29 -> V_46 . V_81 . V_85 = V_29 -> V_84 ;
break;
default:
break;
}
}
if ( V_29 -> V_57 & ( V_58 | V_61 ) ) {
T_2 V_88 [ V_79 ] , V_89 [ V_79 ] ;
T_1 V_15 [ V_79 ] , V_14 [ V_79 ] ;
T_1 V_34 [ V_35 ] ;
int V_90 = V_29 -> V_27 -> V_91 + V_92 + V_93 ;
#ifdef F_27
if ( V_29 -> V_27 -> V_94 & V_95 )
V_90 = V_89 ( V_90 , V_96 ) ;
#endif
F_30 ( & V_29 -> V_46 , & V_29 -> V_38 ,
V_90 , V_13 ) ;
F_30 ( & V_29 -> V_46 , & V_29 -> V_38 ,
V_90 , V_18 ) ;
F_31 ( & V_29 -> V_38 ,
V_13 , V_88 ) ;
F_32 ( & V_29 -> V_38 , V_89 ) ;
F_33 ( & V_29 -> V_38 ,
V_13 , V_15 ) ;
F_34 ( & V_29 -> V_38 ,
V_13 , V_14 ) ;
F_6 ( & V_29 -> V_38 ,
V_13 , V_34 ) ;
F_35 ( & V_29 -> V_46 , V_88 , V_89 ,
V_15 , V_14 , V_34 ) ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ )
F_7 ( V_27 , V_8 , V_34 [ V_8 ] ) ;
}
if ( V_29 -> V_57 & V_59 ) {
T_1 V_97 ;
T_1 V_34 [ V_35 ] ;
F_6 ( & V_29 -> V_38 ,
V_13 , V_34 ) ;
F_36 ( & V_29 -> V_38 , & V_97 ) ;
F_37 ( & V_29 -> V_46 , V_97 , V_34 ) ;
V_69 = V_98 ;
}
if ( V_29 -> V_38 . V_25 )
V_29 -> V_46 . V_81 . V_82 = V_83 ;
#ifdef F_27
if ( ( V_76 && ! ( V_76 & ( 1 << V_29 -> V_99 . V_76 ) ) ) ||
( V_29 -> V_57 & V_60 ) ) {
V_29 -> V_99 . V_76 = F_38 ( V_76 ) - 1 ;
F_19 ( V_27 ) ;
V_69 = V_100 ;
}
#endif
V_29 -> V_57 = 0x00 ;
return V_69 ;
}
static T_1 F_39 ( struct V_26 * V_27 , int V_101 , T_1 * V_102 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
switch ( V_101 ) {
case V_103 :
* V_102 = true ;
break;
case V_104 :
* V_102 = true ;
break;
case V_105 :
* V_102 = false ;
break;
case V_106 :
* V_102 = 0x80 ;
break;
case V_107 :
* V_102 = 0x80 ;
break;
case V_108 :
* V_102 = true ;
break;
case V_109 :
* V_102 = false ;
break;
case V_110 :
* V_102 = V_29 -> V_36 ;
break;
default:
* V_102 = false ;
break;
}
return 0 ;
}
static T_1 F_40 ( struct V_26 * V_27 , int V_111 , T_1 * V_112 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
T_1 V_113 = 0 ;
if ( V_29 -> V_30 & V_31 ) {
switch ( V_111 ) {
case V_114 :
* V_112 = V_29 -> V_38 . V_39 . V_40 ;
break;
case V_115 :
* V_112 = V_29 -> V_38 . V_39 . V_116 ;
break;
default:
V_113 = - V_9 ;
break;
}
} else {
V_113 = - V_9 ;
}
return V_113 ;
}
static T_1 F_41 ( struct V_26 * V_27 , int V_111 , T_1 V_112 )
{
return - V_9 ;
}
static T_1 F_42 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
return V_29 -> V_38 . V_25 ;
}
static void F_43 ( struct V_26 * V_27 , T_1 V_32 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_56 . V_25 = V_32 ;
if ( V_29 -> V_56 . V_25 !=
V_29 -> V_38 . V_25 )
V_29 -> V_57 |= V_59 ;
}
static T_1 F_44 ( struct V_26 * V_27 , T_1 V_117 , T_2 V_118 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
struct V_70 V_71 = {
. V_72 = V_117 ,
. V_74 = V_118 ,
} ;
if ( ! ( V_29 -> V_36 & V_37 ) )
return 0 ;
return F_29 ( V_27 , & V_71 ) ;
}
static int F_45 ( struct V_26 * V_64 ,
struct V_119 * V_120 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
struct V_119 * V_121 = V_29 -> V_122 ;
V_120 -> V_123 = V_29 -> V_38 . V_39 . V_40 ;
if ( ! V_121 )
return 0 ;
V_120 -> V_124 = V_121 -> V_124 ;
memcpy ( V_120 -> V_125 , V_121 -> V_125 , sizeof( V_120 -> V_125 ) ) ;
memcpy ( V_120 -> V_126 , V_121 -> V_126 , sizeof( V_120 -> V_126 ) ) ;
memcpy ( V_120 -> V_127 , V_121 -> V_127 , sizeof( V_120 -> V_127 ) ) ;
memcpy ( V_120 -> V_34 , V_121 -> V_34 , sizeof( V_120 -> V_34 ) ) ;
return 0 ;
}
static int F_46 ( struct V_26 * V_64 ,
struct V_119 * V_120 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
int V_90 = V_64 -> V_91 + V_92 + V_93 ;
int V_8 ;
T_3 V_128 = 0 ;
if ( ! ( V_29 -> V_36 & V_77 ) )
return - V_9 ;
if ( ! V_29 -> V_122 ) {
V_29 -> V_122 = F_47 ( sizeof( struct V_119 ) ,
V_129 ) ;
if ( ! V_29 -> V_122 )
return - V_130 ;
}
memcpy ( V_29 -> V_122 , V_120 , sizeof( * V_29 -> V_122 ) ) ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ ) {
if ( V_120 -> V_34 [ V_8 ] > V_128 )
V_128 = V_120 -> V_34 [ V_8 ] ;
}
if ( V_128 )
V_128 ++ ;
if ( V_128 > V_29 -> V_38 . V_39 . V_40 )
return - V_9 ;
if ( V_128 != F_48 ( V_64 ) )
F_5 ( V_64 , V_128 ) ;
for ( V_8 = 0 ; V_8 < V_41 ; V_8 ++ )
F_7 ( V_64 , V_8 , V_120 -> V_34 [ V_8 ] ) ;
return F_49 ( & V_29 -> V_46 , V_120 , V_90 ) ;
}
static int F_50 ( struct V_26 * V_64 ,
struct V_131 * V_132 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
struct V_131 * V_133 = V_29 -> V_134 ;
int V_8 ;
V_132 -> V_135 = V_29 -> V_38 . V_39 . V_116 ;
if ( ! V_133 )
return 0 ;
V_132 -> V_97 = V_133 -> V_97 ;
V_132 -> V_136 = V_133 -> V_136 ;
V_132 -> V_137 = V_133 -> V_137 ;
for ( V_8 = 0 ; V_8 < V_79 ; V_8 ++ ) {
V_132 -> V_138 [ V_8 ] = V_29 -> V_139 . V_140 [ V_8 ] ;
V_132 -> V_141 [ V_8 ] = V_29 -> V_139 . V_142 [ V_8 ] ;
}
return 0 ;
}
static int F_51 ( struct V_26 * V_64 ,
struct V_131 * V_132 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
T_1 * V_34 ;
if ( ! ( V_29 -> V_36 & V_77 ) )
return - V_9 ;
if ( ! V_29 -> V_134 ) {
V_29 -> V_134 = F_47 ( sizeof( struct V_131 ) ,
V_129 ) ;
if ( ! V_29 -> V_134 )
return - V_130 ;
}
V_34 = V_29 -> V_122 -> V_34 ;
memcpy ( V_29 -> V_134 , V_132 , sizeof( * V_29 -> V_134 ) ) ;
return F_37 ( & V_29 -> V_46 , V_132 -> V_97 , V_34 ) ;
}
static int F_52 ( struct V_26 * V_64 ,
struct V_70 * V_71 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
int V_33 = - V_9 ;
if ( ! ( V_29 -> V_36 & V_77 ) )
return V_33 ;
V_33 = F_53 ( V_64 , V_71 ) ;
#ifdef F_27
if ( ! V_33 && V_71 -> V_72 == V_78 &&
V_71 -> V_74 == V_75 ) {
T_1 V_143 = F_28 ( V_64 , V_71 ) ;
if ( V_143 & ( 1 << V_29 -> V_99 . V_76 ) )
return V_33 ;
V_29 -> V_99 . V_76 = V_71 -> V_62 ;
F_19 ( V_64 ) ;
}
#endif
return 0 ;
}
static int F_54 ( struct V_26 * V_64 ,
struct V_70 * V_71 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
int V_33 ;
if ( ! ( V_29 -> V_36 & V_77 ) )
return - V_9 ;
V_33 = F_55 ( V_64 , V_71 ) ;
#ifdef F_27
if ( ! V_33 && V_71 -> V_72 == V_78 &&
V_71 -> V_74 == V_75 ) {
T_1 V_143 = F_28 ( V_64 , V_71 ) ;
if ( V_143 & ( 1 << V_29 -> V_99 . V_76 ) )
return V_33 ;
V_29 -> V_99 . V_76 = V_143 ?
F_38 ( V_143 ) - 1 : V_144 ;
F_19 ( V_64 ) ;
}
#endif
return V_33 ;
}
static T_1 F_56 ( struct V_26 * V_64 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
return V_29 -> V_36 ;
}
static T_1 F_57 ( struct V_26 * V_64 , T_1 V_145 )
{
struct V_28 * V_29 = F_3 ( V_64 ) ;
struct V_119 V_120 = { 0 } ;
struct V_131 V_132 = { 0 } ;
if ( ( V_145 & V_146 ) ||
( ( V_145 & V_77 ) && ( V_145 & V_37 ) ) ||
! ( V_145 & V_147 ) )
return 1 ;
if ( V_145 == V_29 -> V_36 )
return 0 ;
V_29 -> V_36 = V_145 ;
V_120 . V_123 = 8 ;
V_132 . V_135 = 8 ;
if ( V_145 & V_77 ) {
F_46 ( V_64 , & V_120 ) ;
F_51 ( V_64 , & V_132 ) ;
} else if ( V_145 & V_37 ) {
T_1 V_148 = V_59 | V_58 | V_61 | V_60 ;
V_29 -> V_57 |= V_148 ;
F_26 ( V_64 ) ;
} else {
F_46 ( V_64 , & V_120 ) ;
F_51 ( V_64 , & V_132 ) ;
F_5 ( V_64 , 0 ) ;
}
return 0 ;
}
