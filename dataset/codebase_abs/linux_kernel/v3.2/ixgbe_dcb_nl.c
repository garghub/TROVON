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
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( ! ( V_29 -> V_34 & V_35 ) )
return 1 ;
if ( ! ! V_32 != ! ( V_29 -> V_30 & V_31 ) )
return V_33 ;
if ( V_32 > 0 )
V_33 = F_5 ( V_27 , V_29 -> V_36 . V_37 . V_38 ) ;
else
V_33 = F_5 ( V_27 , 0 ) ;
return V_33 ;
}
static void F_6 ( struct V_26 * V_27 ,
T_1 * V_39 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
int V_8 , V_40 ;
memset ( V_39 , 0xff , V_41 ) ;
for ( V_8 = 0 ; V_8 < V_27 -> V_42 ; V_8 ++ )
V_39 [ V_8 ] = V_29 -> V_43 . V_44 . V_39 [ V_8 ] ;
switch ( V_29 -> V_43 . V_44 . type ) {
case V_45 :
case V_46 :
for ( V_40 = 0 ; V_40 < V_27 -> V_42 ; V_40 ++ , V_8 ++ )
V_39 [ V_8 ] = V_29 -> V_43 . V_44 . V_47 [ V_40 ] ;
break;
default:
break;
}
}
static void F_7 ( struct V_26 * V_27 , int V_48 ,
T_1 V_49 , T_1 V_15 , T_1 V_50 ,
T_1 V_51 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( F_8 ( V_51 ) > V_29 -> V_36 . V_37 . V_38 )
return;
if ( V_49 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_14 = V_49 ;
if ( V_15 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_15 = V_15 ;
if ( V_50 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_16 =
V_50 ;
if ( V_51 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_17 =
V_51 ;
if ( ( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_14 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_14 ) ||
( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_15 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_15 ) ||
( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_16 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_16 ) ||
( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_17 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_17 ) )
V_29 -> V_54 |= V_55 ;
if ( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 0 ] . V_17 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_17 )
V_29 -> V_54 |= V_56 ;
}
static void F_9 ( struct V_26 * V_27 , int V_15 ,
T_1 V_50 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_21 [ 0 ] [ V_15 ] = V_50 ;
if ( V_29 -> V_53 . V_21 [ 0 ] [ V_15 ] !=
V_29 -> V_36 . V_21 [ 0 ] [ V_15 ] )
V_29 -> V_54 |= V_55 ;
}
static void F_10 ( struct V_26 * V_27 , int V_48 ,
T_1 V_49 , T_1 V_15 , T_1 V_50 ,
T_1 V_51 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( F_8 ( V_51 ) > V_29 -> V_36 . V_37 . V_38 )
return;
if ( V_49 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_14 = V_49 ;
if ( V_15 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_15 = V_15 ;
if ( V_50 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_16 =
V_50 ;
if ( V_51 != V_52 )
V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_17 =
V_51 ;
if ( ( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_14 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_14 ) ||
( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_15 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_15 ) ||
( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_16 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_16 ) ||
( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_17 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_17 ) )
V_29 -> V_54 |= V_57 ;
if ( V_29 -> V_53 . V_11 [ V_48 ] . V_12 [ 1 ] . V_17 !=
V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_17 )
V_29 -> V_54 |= V_56 ;
}
static void F_11 ( struct V_26 * V_27 , int V_15 ,
T_1 V_50 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_21 [ 1 ] [ V_15 ] = V_50 ;
if ( V_29 -> V_53 . V_21 [ 1 ] [ V_15 ] !=
V_29 -> V_36 . V_21 [ 1 ] [ V_15 ] )
V_29 -> V_54 |= V_57 ;
}
static void F_12 ( struct V_26 * V_27 , int V_48 ,
T_1 * V_49 , T_1 * V_15 , T_1 * V_50 ,
T_1 * V_51 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_49 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_14 ;
* V_15 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_15 ;
* V_50 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_16 ;
* V_51 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 0 ] . V_17 ;
}
static void F_13 ( struct V_26 * V_27 , int V_15 ,
T_1 * V_50 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_50 = V_29 -> V_36 . V_21 [ 0 ] [ V_15 ] ;
}
static void F_14 ( struct V_26 * V_27 , int V_48 ,
T_1 * V_49 , T_1 * V_15 , T_1 * V_50 ,
T_1 * V_51 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_49 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_14 ;
* V_15 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_15 ;
* V_50 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_16 ;
* V_51 = V_29 -> V_36 . V_11 [ V_48 ] . V_12 [ 1 ] . V_17 ;
}
static void F_15 ( struct V_26 * V_27 , int V_15 ,
T_1 * V_50 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_50 = V_29 -> V_36 . V_21 [ 1 ] [ V_15 ] ;
}
static void F_16 ( struct V_26 * V_27 , int V_58 ,
T_1 V_59 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_11 [ V_58 ] . V_24 = V_59 ;
if ( V_29 -> V_53 . V_11 [ V_58 ] . V_24 !=
V_29 -> V_36 . V_11 [ V_58 ] . V_24 ) {
V_29 -> V_54 |= V_56 ;
V_29 -> V_53 . V_25 = true ;
}
}
static void F_17 ( struct V_26 * V_27 , int V_58 ,
T_1 * V_59 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_59 = V_29 -> V_36 . V_11 [ V_58 ] . V_24 ;
}
static T_1 F_18 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
int V_60 , V_8 ;
#ifdef F_19
struct V_61 V_62 = {
. V_63 = V_64 ,
. V_65 = V_66 ,
} ;
T_1 V_67 ;
if ( V_29 -> V_34 & V_68 ) {
V_62 . V_63 = V_69 ;
V_67 = F_20 ( V_27 , & V_62 ) ;
} else {
V_67 = F_21 ( V_27 , & V_62 ) ;
}
#endif
if ( ! ( V_29 -> V_34 & V_35 ) )
return 1 ;
V_60 = F_1 ( & V_29 -> V_53 , & V_29 -> V_36 ,
V_70 ) ;
if ( V_60 )
return V_71 ;
#ifdef F_19
if ( V_67 && ! ( V_67 & ( 1 << V_29 -> V_72 . V_67 ) ) )
V_29 -> V_54 |= V_73 ;
if ( V_29 -> V_54 & V_73 ) {
while ( F_22 ( V_74 , & V_29 -> V_32 ) )
F_23 ( 1000 , 2000 ) ;
V_29 -> V_72 . V_67 = F_8 ( V_67 ) - 1 ;
if ( F_24 ( V_27 ) )
V_27 -> V_75 -> V_76 ( V_27 ) ;
F_25 ( V_29 ) ;
}
#endif
if ( V_29 -> V_36 . V_25 ) {
switch ( V_29 -> V_43 . V_44 . type ) {
case V_45 :
case V_46 :
if ( V_29 -> V_43 . V_77 . V_78 != V_79 )
V_29 -> V_80 =
V_29 -> V_43 . V_77 . V_78 ;
break;
default:
break;
}
V_29 -> V_43 . V_77 . V_81 = V_79 ;
} else {
switch ( V_29 -> V_43 . V_44 . type ) {
case V_82 :
V_29 -> V_43 . V_77 . V_81 = V_83 ;
break;
case V_45 :
case V_46 :
V_29 -> V_43 . V_77 . V_81 = V_29 -> V_80 ;
break;
default:
break;
}
}
#ifdef F_19
if ( V_29 -> V_54 & V_73 ) {
F_26 ( V_29 ) ;
if ( F_24 ( V_27 ) )
V_27 -> V_75 -> V_84 ( V_27 ) ;
V_60 = V_85 ;
}
#endif
if ( V_29 -> V_54 & ( V_55 | V_57 ) ) {
T_2 V_86 [ V_70 ] , V_87 [ V_70 ] ;
T_1 V_15 [ V_70 ] , V_14 [ V_70 ] ;
T_1 V_88 [ V_89 ] ;
int V_90 = V_29 -> V_27 -> V_91 + V_92 + V_93 ;
#ifdef F_19
if ( V_29 -> V_27 -> V_94 & V_95 )
V_90 = V_87 ( V_90 , V_96 ) ;
#endif
F_27 ( & V_29 -> V_43 , & V_29 -> V_36 ,
V_90 , V_13 ) ;
F_27 ( & V_29 -> V_43 , & V_29 -> V_36 ,
V_90 , V_18 ) ;
F_28 ( & V_29 -> V_36 ,
V_13 , V_86 ) ;
F_29 ( & V_29 -> V_36 , V_87 ) ;
F_30 ( & V_29 -> V_36 ,
V_13 , V_15 ) ;
F_31 ( & V_29 -> V_36 ,
V_13 , V_14 ) ;
F_32 ( & V_29 -> V_36 ,
V_13 , V_88 ) ;
F_33 ( & V_29 -> V_43 , V_86 , V_87 ,
V_15 , V_14 , V_88 ) ;
for ( V_8 = 0 ; V_8 < V_97 ; V_8 ++ )
F_34 ( V_27 , V_8 , V_88 [ V_8 ] ) ;
}
if ( V_29 -> V_54 & V_56 ) {
T_1 V_98 ;
T_1 V_88 [ V_89 ] ;
F_32 ( & V_29 -> V_36 ,
V_13 , V_88 ) ;
F_35 ( & V_29 -> V_36 , & V_98 ) ;
F_36 ( & V_29 -> V_43 , V_98 , V_88 ) ;
V_60 = V_99 ;
}
if ( V_29 -> V_36 . V_25 )
V_29 -> V_43 . V_77 . V_78 = V_79 ;
if ( V_29 -> V_54 & V_73 )
F_37 ( V_74 , & V_29 -> V_32 ) ;
V_29 -> V_54 = 0x00 ;
return V_60 ;
}
static T_1 F_38 ( struct V_26 * V_27 , int V_100 , T_1 * V_101 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
switch ( V_100 ) {
case V_102 :
* V_101 = true ;
break;
case V_103 :
* V_101 = true ;
break;
case V_104 :
* V_101 = false ;
break;
case V_105 :
* V_101 = 0x80 ;
break;
case V_106 :
* V_101 = 0x80 ;
break;
case V_107 :
* V_101 = true ;
break;
case V_108 :
* V_101 = false ;
break;
case V_109 :
* V_101 = V_29 -> V_34 ;
break;
default:
* V_101 = false ;
break;
}
return 0 ;
}
static T_1 F_39 ( struct V_26 * V_27 , int V_110 , T_1 * V_111 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
T_1 V_112 = 0 ;
if ( V_29 -> V_30 & V_31 ) {
switch ( V_110 ) {
case V_113 :
* V_111 = V_29 -> V_36 . V_37 . V_38 ;
break;
case V_114 :
* V_111 = V_29 -> V_36 . V_37 . V_115 ;
break;
default:
V_112 = - V_9 ;
break;
}
} else {
V_112 = - V_9 ;
}
return V_112 ;
}
static T_1 F_40 ( struct V_26 * V_27 , int V_110 , T_1 V_111 )
{
return - V_9 ;
}
static T_1 F_41 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
return V_29 -> V_36 . V_25 ;
}
static void F_42 ( struct V_26 * V_27 , T_1 V_32 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_25 = V_32 ;
if ( V_29 -> V_53 . V_25 !=
V_29 -> V_36 . V_25 )
V_29 -> V_54 |= V_56 ;
}
static T_1 F_43 ( struct V_26 * V_27 , T_1 V_116 , T_2 V_117 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
struct V_61 V_62 = {
. V_63 = V_116 ,
. V_65 = V_117 ,
} ;
if ( ! ( V_29 -> V_34 & V_35 ) )
return 0 ;
return F_21 ( V_27 , & V_62 ) ;
}
static int F_44 ( struct V_26 * V_118 ,
struct V_119 * V_120 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
struct V_119 * V_121 = V_29 -> V_122 ;
V_120 -> V_123 = V_29 -> V_36 . V_37 . V_38 ;
if ( ! V_121 )
return 0 ;
V_120 -> V_124 = V_121 -> V_124 ;
memcpy ( V_120 -> V_125 , V_121 -> V_125 , sizeof( V_120 -> V_125 ) ) ;
memcpy ( V_120 -> V_126 , V_121 -> V_126 , sizeof( V_120 -> V_126 ) ) ;
memcpy ( V_120 -> V_127 , V_121 -> V_127 , sizeof( V_120 -> V_127 ) ) ;
memcpy ( V_120 -> V_88 , V_121 -> V_88 , sizeof( V_120 -> V_88 ) ) ;
return 0 ;
}
static int F_45 ( struct V_26 * V_118 ,
struct V_119 * V_120 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
int V_90 = V_118 -> V_91 + V_92 + V_93 ;
int V_8 ;
T_3 V_128 = 0 ;
if ( ! ( V_29 -> V_34 & V_68 ) )
return - V_9 ;
if ( ! V_29 -> V_122 ) {
V_29 -> V_122 = F_46 ( sizeof( struct V_119 ) ,
V_129 ) ;
if ( ! V_29 -> V_122 )
return - V_130 ;
}
memcpy ( V_29 -> V_122 , V_120 , sizeof( * V_29 -> V_122 ) ) ;
for ( V_8 = 0 ; V_8 < V_97 ; V_8 ++ ) {
if ( V_120 -> V_88 [ V_8 ] > V_128 )
V_128 = V_120 -> V_88 [ V_8 ] ;
}
if ( V_128 )
V_128 ++ ;
if ( V_128 > V_29 -> V_36 . V_37 . V_38 )
return - V_9 ;
if ( V_128 != F_47 ( V_118 ) )
F_5 ( V_118 , V_128 ) ;
for ( V_8 = 0 ; V_8 < V_97 ; V_8 ++ )
F_34 ( V_118 , V_8 , V_120 -> V_88 [ V_8 ] ) ;
return F_48 ( & V_29 -> V_43 , V_120 , V_90 ) ;
}
static int F_49 ( struct V_26 * V_118 ,
struct V_131 * V_132 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
struct V_131 * V_133 = V_29 -> V_134 ;
int V_8 ;
V_132 -> V_135 = V_29 -> V_36 . V_37 . V_115 ;
if ( ! V_133 )
return 0 ;
V_132 -> V_98 = V_133 -> V_98 ;
V_132 -> V_136 = V_133 -> V_136 ;
V_132 -> V_137 = V_133 -> V_137 ;
for ( V_8 = 0 ; V_8 < V_70 ; V_8 ++ ) {
V_132 -> V_138 [ V_8 ] = V_29 -> V_139 . V_140 [ V_8 ] ;
V_132 -> V_141 [ V_8 ] = V_29 -> V_139 . V_142 [ V_8 ] ;
}
return 0 ;
}
static int F_50 ( struct V_26 * V_118 ,
struct V_131 * V_132 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
T_1 * V_88 ;
if ( ! ( V_29 -> V_34 & V_68 ) )
return - V_9 ;
if ( ! V_29 -> V_134 ) {
V_29 -> V_134 = F_46 ( sizeof( struct V_131 ) ,
V_129 ) ;
if ( ! V_29 -> V_134 )
return - V_130 ;
}
V_88 = V_29 -> V_122 -> V_88 ;
memcpy ( V_29 -> V_134 , V_132 , sizeof( * V_29 -> V_134 ) ) ;
return F_36 ( & V_29 -> V_43 , V_132 -> V_98 , V_88 ) ;
}
static void F_51 ( struct V_26 * V_118 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
if ( F_24 ( V_118 ) )
V_118 -> V_75 -> V_76 ( V_118 ) ;
F_25 ( V_29 ) ;
F_26 ( V_29 ) ;
if ( F_24 ( V_118 ) )
V_118 -> V_75 -> V_84 ( V_118 ) ;
}
static int F_52 ( struct V_26 * V_118 ,
struct V_61 * V_62 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
int V_33 = - V_9 ;
if ( ! ( V_29 -> V_34 & V_68 ) )
return V_33 ;
V_33 = F_53 ( V_118 , V_62 ) ;
#ifdef F_19
if ( ! V_33 && V_62 -> V_63 == V_69 &&
V_62 -> V_65 == V_66 ) {
T_1 V_143 = F_20 ( V_118 , V_62 ) ;
if ( V_143 & ( 1 << V_29 -> V_72 . V_67 ) )
return V_33 ;
V_29 -> V_72 . V_67 = V_62 -> V_58 ;
F_51 ( V_118 ) ;
}
#endif
return 0 ;
}
static int F_54 ( struct V_26 * V_118 ,
struct V_61 * V_62 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
int V_33 ;
if ( ! ( V_29 -> V_34 & V_68 ) )
return - V_9 ;
V_33 = F_55 ( V_118 , V_62 ) ;
#ifdef F_19
if ( ! V_33 && V_62 -> V_63 == V_69 &&
V_62 -> V_65 == V_66 ) {
T_1 V_143 = F_20 ( V_118 , V_62 ) ;
if ( V_143 & ( 1 << V_29 -> V_72 . V_67 ) )
return V_33 ;
V_29 -> V_72 . V_67 = V_143 ?
F_8 ( V_143 ) - 1 : V_144 ;
F_51 ( V_118 ) ;
}
#endif
return V_33 ;
}
static T_1 F_56 ( struct V_26 * V_118 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
return V_29 -> V_34 ;
}
static T_1 F_57 ( struct V_26 * V_118 , T_1 V_145 )
{
struct V_28 * V_29 = F_3 ( V_118 ) ;
struct V_119 V_120 = { 0 } ;
struct V_131 V_132 = { 0 } ;
if ( ( V_145 & V_146 ) ||
( ( V_145 & V_68 ) && ( V_145 & V_35 ) ) ||
! ( V_145 & V_147 ) )
return 1 ;
if ( V_145 == V_29 -> V_34 )
return 0 ;
V_29 -> V_34 = V_145 ;
V_120 . V_123 = 8 ;
V_132 . V_135 = 8 ;
if ( V_145 & V_68 ) {
F_45 ( V_118 , & V_120 ) ;
F_50 ( V_118 , & V_132 ) ;
} else if ( V_145 & V_35 ) {
V_29 -> V_54 |= ( V_56 & V_55 & V_57 ) ;
F_18 ( V_118 ) ;
} else {
F_45 ( V_118 , & V_120 ) ;
F_50 ( V_118 , & V_132 ) ;
F_5 ( V_118 , 0 ) ;
}
return 0 ;
}
