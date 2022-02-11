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
if ( V_32 > 0 ) {
if ( V_29 -> V_30 & V_31 )
goto V_34;
if ( ! ( V_29 -> V_30 & V_35 ) ) {
F_5 ( V_36 , L_1 ) ;
V_33 = 1 ;
goto V_34;
}
if ( F_6 ( V_27 ) )
V_27 -> V_37 -> V_38 ( V_27 ) ;
F_7 ( V_29 ) ;
switch ( V_29 -> V_39 . V_40 . type ) {
case V_41 :
V_29 -> V_42 = V_29 -> V_39 . V_43 . V_44 ;
V_29 -> V_39 . V_43 . V_45 = V_46 ;
break;
case V_47 :
case V_48 :
V_29 -> V_30 &= ~ V_49 ;
V_29 -> V_30 &= ~ V_50 ;
break;
default:
break;
}
V_29 -> V_30 |= V_31 ;
if ( ! F_8 ( V_27 ) )
F_9 ( V_27 , V_51 ) ;
F_10 ( V_29 ) ;
if ( F_6 ( V_27 ) )
V_27 -> V_37 -> V_52 ( V_27 ) ;
} else {
if ( V_29 -> V_30 & V_31 ) {
if ( F_6 ( V_27 ) )
V_27 -> V_37 -> V_38 ( V_27 ) ;
F_7 ( V_29 ) ;
V_29 -> V_39 . V_43 . V_45 = V_29 -> V_42 ;
V_29 -> V_53 . V_25 = false ;
V_29 -> V_54 . V_25 = false ;
V_29 -> V_30 &= ~ V_31 ;
switch ( V_29 -> V_39 . V_40 . type ) {
case V_47 :
case V_48 :
V_29 -> V_30 |= V_49 ;
break;
default:
break;
}
F_9 ( V_27 , 0 ) ;
F_10 ( V_29 ) ;
if ( F_6 ( V_27 ) )
V_27 -> V_37 -> V_52 ( V_27 ) ;
}
}
V_34:
return V_33 ;
}
static void F_11 ( struct V_26 * V_27 ,
T_1 * V_55 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
int V_8 , V_56 ;
memset ( V_55 , 0xff , V_57 ) ;
for ( V_8 = 0 ; V_8 < V_27 -> V_58 ; V_8 ++ )
V_55 [ V_8 ] = V_29 -> V_39 . V_40 . V_55 [ V_8 ] ;
switch ( V_29 -> V_39 . V_40 . type ) {
case V_47 :
case V_48 :
for ( V_56 = 0 ; V_56 < V_27 -> V_58 ; V_56 ++ , V_8 ++ )
V_55 [ V_8 ] = V_29 -> V_39 . V_40 . V_59 [ V_56 ] ;
break;
default:
break;
}
}
static void F_12 ( struct V_26 * V_27 , int V_60 ,
T_1 V_61 , T_1 V_15 , T_1 V_62 ,
T_1 V_63 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( V_61 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_14 = V_61 ;
if ( V_15 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_15 = V_15 ;
if ( V_62 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_16 =
V_62 ;
if ( V_63 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_17 =
V_63 ;
if ( ( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_14 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_14 ) ||
( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_15 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_15 ) ||
( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_16 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_16 ) ||
( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 0 ] . V_17 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_17 ) )
V_29 -> V_65 |= V_66 ;
}
static void F_13 ( struct V_26 * V_27 , int V_15 ,
T_1 V_62 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_21 [ 0 ] [ V_15 ] = V_62 ;
if ( V_29 -> V_53 . V_21 [ 0 ] [ V_15 ] !=
V_29 -> V_54 . V_21 [ 0 ] [ V_15 ] )
V_29 -> V_65 |= V_66 ;
}
static void F_14 ( struct V_26 * V_27 , int V_60 ,
T_1 V_61 , T_1 V_15 , T_1 V_62 ,
T_1 V_63 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
if ( V_61 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_14 = V_61 ;
if ( V_15 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_15 = V_15 ;
if ( V_62 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_16 =
V_62 ;
if ( V_63 != V_64 )
V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_17 =
V_63 ;
if ( ( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_14 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_14 ) ||
( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_15 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_15 ) ||
( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_16 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_16 ) ||
( V_29 -> V_53 . V_11 [ V_60 ] . V_12 [ 1 ] . V_17 !=
V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_17 ) )
V_29 -> V_65 |= V_67 ;
}
static void F_15 ( struct V_26 * V_27 , int V_15 ,
T_1 V_62 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_21 [ 1 ] [ V_15 ] = V_62 ;
if ( V_29 -> V_53 . V_21 [ 1 ] [ V_15 ] !=
V_29 -> V_54 . V_21 [ 1 ] [ V_15 ] )
V_29 -> V_65 |= V_67 ;
}
static void F_16 ( struct V_26 * V_27 , int V_60 ,
T_1 * V_61 , T_1 * V_15 , T_1 * V_62 ,
T_1 * V_63 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_61 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_14 ;
* V_15 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_15 ;
* V_62 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_16 ;
* V_63 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 0 ] . V_17 ;
}
static void F_17 ( struct V_26 * V_27 , int V_15 ,
T_1 * V_62 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_62 = V_29 -> V_54 . V_21 [ 0 ] [ V_15 ] ;
}
static void F_18 ( struct V_26 * V_27 , int V_60 ,
T_1 * V_61 , T_1 * V_15 , T_1 * V_62 ,
T_1 * V_63 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_61 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_14 ;
* V_15 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_15 ;
* V_62 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_16 ;
* V_63 = V_29 -> V_54 . V_11 [ V_60 ] . V_12 [ 1 ] . V_17 ;
}
static void F_19 ( struct V_26 * V_27 , int V_15 ,
T_1 * V_62 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_62 = V_29 -> V_54 . V_21 [ 1 ] [ V_15 ] ;
}
static void F_20 ( struct V_26 * V_27 , int V_68 ,
T_1 V_69 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_11 [ V_68 ] . V_24 = V_69 ;
if ( V_29 -> V_53 . V_11 [ V_68 ] . V_24 !=
V_29 -> V_54 . V_11 [ V_68 ] . V_24 ) {
V_29 -> V_65 |= V_70 ;
V_29 -> V_53 . V_25 = true ;
}
}
static void F_21 ( struct V_26 * V_27 , int V_68 ,
T_1 * V_69 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
* V_69 = V_29 -> V_54 . V_11 [ V_68 ] . V_24 ;
}
static T_1 F_22 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
struct V_71 V_72 = {
. V_73 = V_74 ,
. V_75 = V_76 ,
} ;
T_1 V_77 = F_23 ( V_27 , & V_72 ) ;
int V_78 ;
V_78 = F_1 ( & V_29 -> V_53 , & V_29 -> V_54 ,
V_51 ) ;
if ( V_78 )
return V_79 ;
if ( V_29 -> V_80 & V_81 )
V_77 = ( 1 << V_77 ) ;
#ifdef F_24
if ( V_77 && ( V_77 != ( 1 << V_29 -> V_82 . V_77 ) ) )
V_29 -> V_65 |= V_83 ;
if ( V_29 -> V_65 & V_83 ) {
while ( F_25 ( V_84 , & V_29 -> V_32 ) )
F_26 ( 1000 , 2000 ) ;
F_27 ( V_29 , V_77 ) ;
if ( F_6 ( V_27 ) )
V_27 -> V_37 -> V_38 ( V_27 ) ;
F_7 ( V_29 ) ;
}
#endif
if ( V_29 -> V_54 . V_25 ) {
switch ( V_29 -> V_39 . V_40 . type ) {
case V_47 :
case V_48 :
if ( V_29 -> V_39 . V_43 . V_44 != V_85 )
V_29 -> V_42 =
V_29 -> V_39 . V_43 . V_44 ;
break;
default:
break;
}
V_29 -> V_39 . V_43 . V_45 = V_85 ;
} else {
switch ( V_29 -> V_39 . V_40 . type ) {
case V_41 :
V_29 -> V_39 . V_43 . V_45 = V_46 ;
break;
case V_47 :
case V_48 :
V_29 -> V_39 . V_43 . V_45 = V_29 -> V_42 ;
break;
default:
break;
}
}
#ifdef F_24
if ( V_29 -> V_65 & V_83 ) {
F_10 ( V_29 ) ;
if ( F_6 ( V_27 ) )
V_27 -> V_37 -> V_52 ( V_27 ) ;
V_78 = V_86 ;
}
#endif
if ( V_29 -> V_65 & V_70 ) {
T_1 V_87 ;
F_28 ( & V_29 -> V_54 , & V_87 ) ;
F_29 ( & V_29 -> V_39 , V_87 ) ;
V_78 = V_88 ;
}
if ( V_29 -> V_65 & ( V_66 | V_67 ) ) {
T_2 V_89 [ V_51 ] , V_90 [ V_51 ] ;
T_1 V_15 [ V_51 ] , V_14 [ V_51 ] ;
T_1 V_91 [ V_51 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
int V_92 = V_29 -> V_27 -> V_93 + V_94 + V_95 ;
#ifdef F_30
if ( V_29 -> V_27 -> V_96 & V_97 )
V_92 = V_90 ( V_92 , V_98 ) ;
#endif
F_31 ( & V_29 -> V_39 , & V_29 -> V_54 ,
V_92 , V_13 ) ;
F_31 ( & V_29 -> V_39 , & V_29 -> V_54 ,
V_92 , V_18 ) ;
F_32 ( & V_29 -> V_54 ,
V_13 , V_89 ) ;
F_33 ( & V_29 -> V_54 , V_90 ) ;
F_34 ( & V_29 -> V_54 ,
V_13 , V_15 ) ;
F_35 ( & V_29 -> V_54 ,
V_13 , V_14 ) ;
F_36 ( & V_29 -> V_39 , V_89 , V_90 ,
V_15 , V_14 , V_91 ) ;
}
if ( V_29 -> V_54 . V_25 )
V_29 -> V_39 . V_43 . V_44 = V_85 ;
if ( V_29 -> V_65 & V_83 )
F_37 ( V_84 , & V_29 -> V_32 ) ;
V_29 -> V_65 = 0x00 ;
return V_78 ;
}
static T_1 F_38 ( struct V_26 * V_27 , int V_99 , T_1 * V_100 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
switch ( V_99 ) {
case V_101 :
* V_100 = true ;
break;
case V_102 :
* V_100 = true ;
break;
case V_103 :
* V_100 = false ;
break;
case V_104 :
* V_100 = 0x80 ;
break;
case V_105 :
* V_100 = 0x80 ;
break;
case V_106 :
* V_100 = true ;
break;
case V_107 :
* V_100 = false ;
break;
case V_108 :
* V_100 = V_29 -> V_80 ;
break;
default:
* V_100 = false ;
break;
}
return 0 ;
}
static T_1 F_39 ( struct V_26 * V_27 , int V_109 , T_1 * V_110 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
T_1 V_111 = 0 ;
if ( V_29 -> V_30 & V_31 ) {
switch ( V_109 ) {
case V_112 :
* V_110 = V_51 ;
break;
case V_113 :
* V_110 = V_51 ;
break;
default:
V_111 = - V_9 ;
break;
}
} else {
V_111 = - V_9 ;
}
return V_111 ;
}
static T_1 F_40 ( struct V_26 * V_27 , int V_109 , T_1 V_110 )
{
return - V_9 ;
}
static T_1 F_41 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
return V_29 -> V_54 . V_25 ;
}
static void F_42 ( struct V_26 * V_27 , T_1 V_32 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
V_29 -> V_53 . V_25 = V_32 ;
if ( V_29 -> V_53 . V_25 !=
V_29 -> V_54 . V_25 )
V_29 -> V_65 |= V_70 ;
}
static T_1 F_43 ( struct V_26 * V_27 , T_1 V_114 , T_2 V_115 )
{
struct V_28 * V_29 = F_3 ( V_27 ) ;
struct V_71 V_72 = {
. V_73 = V_114 ,
. V_75 = V_115 ,
} ;
if ( ! ( V_29 -> V_80 & V_116 ) )
return 0 ;
return F_23 ( V_27 , & V_72 ) ;
}
static int F_44 ( struct V_26 * V_117 ,
struct V_118 * V_119 )
{
struct V_28 * V_29 = F_3 ( V_117 ) ;
struct V_118 * V_120 = V_29 -> V_121 ;
if ( ! V_120 )
return - V_9 ;
V_119 -> V_122 = V_51 ;
V_119 -> V_123 = V_120 -> V_123 ;
memcpy ( V_119 -> V_124 , V_120 -> V_124 , sizeof( V_119 -> V_124 ) ) ;
memcpy ( V_119 -> V_125 , V_120 -> V_125 , sizeof( V_119 -> V_125 ) ) ;
memcpy ( V_119 -> V_126 , V_120 -> V_126 , sizeof( V_119 -> V_126 ) ) ;
memcpy ( V_119 -> V_91 , V_120 -> V_91 , sizeof( V_119 -> V_91 ) ) ;
return 0 ;
}
static int F_45 ( struct V_26 * V_117 ,
struct V_118 * V_119 )
{
struct V_28 * V_29 = F_3 ( V_117 ) ;
T_3 V_89 [ V_127 ] , V_90 [ V_127 ] ;
T_4 V_14 [ V_127 ] ;
int V_92 = V_117 -> V_93 + V_94 + V_95 ;
int V_8 , V_33 ;
T_5 * V_128 = ( T_5 * ) V_119 -> V_91 ;
T_4 V_15 [ V_127 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 } ;
if ( ! ( V_29 -> V_80 & V_81 ) )
return - V_9 ;
if ( ! V_29 -> V_121 ) {
V_29 -> V_121 = F_46 ( sizeof( struct V_118 ) ,
V_129 ) ;
if ( ! V_29 -> V_121 )
return - V_130 ;
}
memcpy ( V_29 -> V_121 , V_119 , sizeof( * V_29 -> V_121 ) ) ;
for ( V_8 = 0 ; V_8 < V_127 ; V_8 ++ ) {
switch ( V_119 -> V_126 [ V_8 ] ) {
case V_131 :
V_14 [ V_8 ] = 2 ;
break;
case V_132 :
V_14 [ V_8 ] = 0 ;
break;
default:
return - V_9 ;
}
}
if ( * V_128 )
F_4 ( V_117 , 1 ) ;
else
F_4 ( V_117 , 0 ) ;
F_47 ( V_119 -> V_124 , V_89 , V_90 , V_92 ) ;
V_33 = F_36 ( & V_29 -> V_39 , V_89 , V_90 ,
V_15 , V_14 , V_119 -> V_91 ) ;
return V_33 ;
}
static int F_48 ( struct V_26 * V_117 ,
struct V_133 * V_134 )
{
struct V_28 * V_29 = F_3 ( V_117 ) ;
struct V_133 * V_135 = V_29 -> V_136 ;
int V_8 ;
if ( ! V_135 )
return - V_9 ;
V_134 -> V_137 = V_51 ;
V_134 -> V_87 = V_135 -> V_87 ;
V_134 -> V_138 = V_135 -> V_138 ;
V_134 -> V_139 = V_135 -> V_139 ;
for ( V_8 = 0 ; V_8 < V_51 ; V_8 ++ ) {
V_134 -> V_140 [ V_8 ] = V_29 -> V_141 . V_142 [ V_8 ] ;
V_134 -> V_143 [ V_8 ] = V_29 -> V_141 . V_144 [ V_8 ] ;
}
return 0 ;
}
static int F_49 ( struct V_26 * V_117 ,
struct V_133 * V_134 )
{
struct V_28 * V_29 = F_3 ( V_117 ) ;
int V_33 ;
if ( ! ( V_29 -> V_80 & V_81 ) )
return - V_9 ;
if ( ! V_29 -> V_136 ) {
V_29 -> V_136 = F_46 ( sizeof( struct V_133 ) ,
V_129 ) ;
if ( ! V_29 -> V_136 )
return - V_130 ;
}
memcpy ( V_29 -> V_136 , V_134 , sizeof( * V_29 -> V_136 ) ) ;
V_33 = F_29 ( & V_29 -> V_39 , V_134 -> V_87 ) ;
return V_33 ;
}
static int F_50 ( struct V_26 * V_117 ,
struct V_71 * V_72 )
{
struct V_28 * V_29 = F_3 ( V_117 ) ;
if ( ! ( V_29 -> V_80 & V_81 ) )
return - V_9 ;
F_51 ( V_117 , V_72 ) ;
#ifdef F_24
if ( V_72 -> V_73 == 1 && V_72 -> V_75 == V_76 &&
V_29 -> V_82 . V_60 == V_72 -> V_68 )
F_22 ( V_117 ) ;
#endif
return 0 ;
}
static T_1 F_52 ( struct V_26 * V_117 )
{
struct V_28 * V_29 = F_3 ( V_117 ) ;
return V_29 -> V_80 ;
}
static T_1 F_53 ( struct V_26 * V_117 , T_1 V_145 )
{
struct V_28 * V_29 = F_3 ( V_117 ) ;
struct V_118 V_119 = { 0 } ;
struct V_133 V_134 = { 0 } ;
if ( ( V_145 & V_146 ) ||
( ( V_145 & V_81 ) && ( V_145 & V_116 ) ) ||
! ( V_145 & V_147 ) )
return 1 ;
if ( V_145 == V_29 -> V_80 )
return 0 ;
V_29 -> V_80 = V_145 ;
V_119 . V_122 = 8 ;
V_134 . V_137 = 8 ;
if ( V_145 & V_81 ) {
F_45 ( V_117 , & V_119 ) ;
F_49 ( V_117 , & V_134 ) ;
} else if ( V_145 & V_116 ) {
V_29 -> V_65 |= ( V_70 & V_66 & V_67 ) ;
F_22 ( V_117 ) ;
} else {
F_45 ( V_117 , & V_119 ) ;
F_49 ( V_117 , & V_134 ) ;
F_4 ( V_117 , 0 ) ;
}
return 0 ;
}
