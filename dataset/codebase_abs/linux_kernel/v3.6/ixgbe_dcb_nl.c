static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
struct V_4 * V_7 = & V_2 -> V_8 ;
struct V_9 * V_10 = NULL ;
struct V_9 * V_11 = NULL ;
int V_12 , V_13 ;
int V_14 = V_15 ;
int V_16 = V_17 ;
int V_18 = 0 ;
#ifdef F_2
struct V_19 V_20 = {
. V_21 = V_22 ,
. V_23 = V_24 ,
} ;
T_1 V_25 = F_3 ( V_2 -> V_26 , & V_20 ) ;
if ( V_25 && ! ( V_25 & ( 1 << V_2 -> V_27 . V_25 ) ) )
V_18 |= V_28 ;
#endif
for ( V_12 = V_29 ; V_12 < V_3 + V_29 ; V_12 ++ ) {
V_10 = & V_5 -> V_30 [ V_12 - V_29 ] ;
V_11 = & V_7 -> V_30 [ V_12 - V_29 ] ;
if ( V_11 -> V_31 [ V_14 ] . V_32 != V_10 -> V_31 [ V_14 ] . V_32 ) {
V_11 -> V_31 [ V_14 ] . V_32 = V_10 -> V_31 [ V_14 ] . V_32 ;
V_18 |= V_33 ;
}
if ( V_11 -> V_31 [ V_14 ] . V_34 != V_10 -> V_31 [ V_14 ] . V_34 ) {
V_11 -> V_31 [ V_14 ] . V_34 = V_10 -> V_31 [ V_14 ] . V_34 ;
V_18 |= V_33 ;
}
if ( V_11 -> V_31 [ V_14 ] . V_35 != V_10 -> V_31 [ V_14 ] . V_35 ) {
V_11 -> V_31 [ V_14 ] . V_35 = V_10 -> V_31 [ V_14 ] . V_35 ;
V_18 |= V_33 ;
}
if ( V_11 -> V_31 [ V_14 ] . V_36 !=
V_10 -> V_31 [ V_14 ] . V_36 ) {
V_11 -> V_31 [ V_14 ] . V_36 =
V_10 -> V_31 [ V_14 ] . V_36 ;
V_18 |= ( V_33 | V_37 | V_28 ) ;
}
if ( V_11 -> V_31 [ V_16 ] . V_32 != V_10 -> V_31 [ V_16 ] . V_32 ) {
V_11 -> V_31 [ V_16 ] . V_32 = V_10 -> V_31 [ V_16 ] . V_32 ;
V_18 |= V_38 ;
}
if ( V_11 -> V_31 [ V_16 ] . V_34 != V_10 -> V_31 [ V_16 ] . V_34 ) {
V_11 -> V_31 [ V_16 ] . V_34 = V_10 -> V_31 [ V_16 ] . V_34 ;
V_18 |= V_38 ;
}
if ( V_11 -> V_31 [ V_16 ] . V_35 != V_10 -> V_31 [ V_16 ] . V_35 ) {
V_11 -> V_31 [ V_16 ] . V_35 = V_10 -> V_31 [ V_16 ] . V_35 ;
V_18 |= V_38 ;
}
if ( V_11 -> V_31 [ V_16 ] . V_36 !=
V_10 -> V_31 [ V_16 ] . V_36 ) {
V_11 -> V_31 [ V_16 ] . V_36 =
V_10 -> V_31 [ V_16 ] . V_36 ;
V_18 |= ( V_38 | V_37 | V_28 ) ;
}
}
for ( V_12 = V_39 ; V_12 < V_40 ; V_12 ++ ) {
V_13 = V_12 - V_39 ;
if ( V_7 -> V_41 [ V_14 ] [ V_13 ] != V_5 -> V_41 [ V_14 ] [ V_13 ] ) {
V_7 -> V_41 [ V_14 ] [ V_13 ] = V_5 -> V_41 [ V_14 ] [ V_13 ] ;
V_18 |= V_33 ;
}
if ( V_7 -> V_41 [ V_16 ] [ V_13 ] != V_5 -> V_41 [ V_16 ] [ V_13 ] ) {
V_7 -> V_41 [ V_16 ] [ V_13 ] = V_5 -> V_41 [ V_16 ] [ V_13 ] ;
V_18 |= V_38 ;
}
}
for ( V_12 = V_42 ; V_12 < V_43 ; V_12 ++ ) {
V_13 = V_12 - V_42 ;
if ( V_7 -> V_30 [ V_13 ] . V_44 != V_5 -> V_30 [ V_13 ] . V_44 ) {
V_7 -> V_30 [ V_13 ] . V_44 = V_5 -> V_30 [ V_13 ] . V_44 ;
V_18 |= V_37 ;
}
}
if ( V_7 -> V_45 != V_5 -> V_45 ) {
V_7 -> V_45 = V_5 -> V_45 ;
V_18 |= V_37 ;
}
return V_18 ;
}
static T_1 F_4 ( struct V_46 * V_26 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
return ! ! ( V_2 -> V_47 & V_48 ) ;
}
static T_1 F_6 ( struct V_46 * V_26 , T_1 V_49 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
int V_50 = 0 ;
if ( ! ( V_2 -> V_51 & V_52 ) )
return 1 ;
if ( ! V_49 == ! ( V_2 -> V_47 & V_48 ) )
goto V_53;
V_50 = F_7 ( V_26 ,
V_49 ? V_2 -> V_8 . V_54 . V_55 : 0 ) ;
V_53:
return ! ! V_50 ;
}
static void F_8 ( struct V_46 * V_26 ,
T_1 * V_56 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
int V_12 , V_13 ;
memset ( V_56 , 0xff , V_57 ) ;
for ( V_12 = 0 ; V_12 < V_26 -> V_58 ; V_12 ++ )
V_56 [ V_12 ] = V_2 -> V_59 . V_60 . V_56 [ V_12 ] ;
switch ( V_2 -> V_59 . V_60 . type ) {
case V_61 :
case V_62 :
for ( V_13 = 0 ; V_13 < V_26 -> V_58 ; V_13 ++ , V_12 ++ )
V_56 [ V_12 ] = V_2 -> V_59 . V_60 . V_63 [ V_13 ] ;
break;
default:
break;
}
}
static void F_9 ( struct V_46 * V_26 , int V_64 ,
T_1 V_65 , T_1 V_34 , T_1 V_66 ,
T_1 V_67 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
if ( V_65 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 0 ] . V_32 = V_65 ;
if ( V_34 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 0 ] . V_34 = V_34 ;
if ( V_66 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 0 ] . V_35 =
V_66 ;
if ( V_67 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 0 ] . V_36 =
V_67 ;
}
static void F_10 ( struct V_46 * V_26 , int V_34 ,
T_1 V_66 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
V_2 -> V_6 . V_41 [ 0 ] [ V_34 ] = V_66 ;
}
static void F_11 ( struct V_46 * V_26 , int V_64 ,
T_1 V_65 , T_1 V_34 , T_1 V_66 ,
T_1 V_67 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
if ( V_65 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 1 ] . V_32 = V_65 ;
if ( V_34 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 1 ] . V_34 = V_34 ;
if ( V_66 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 1 ] . V_35 =
V_66 ;
if ( V_67 != V_68 )
V_2 -> V_6 . V_30 [ V_64 ] . V_31 [ 1 ] . V_36 =
V_67 ;
}
static void F_12 ( struct V_46 * V_26 , int V_34 ,
T_1 V_66 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
V_2 -> V_6 . V_41 [ 1 ] [ V_34 ] = V_66 ;
}
static void F_13 ( struct V_46 * V_26 , int V_64 ,
T_1 * V_65 , T_1 * V_34 , T_1 * V_66 ,
T_1 * V_67 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_65 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 0 ] . V_32 ;
* V_34 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 0 ] . V_34 ;
* V_66 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 0 ] . V_35 ;
* V_67 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 0 ] . V_36 ;
}
static void F_14 ( struct V_46 * V_26 , int V_34 ,
T_1 * V_66 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_66 = V_2 -> V_8 . V_41 [ 0 ] [ V_34 ] ;
}
static void F_15 ( struct V_46 * V_26 , int V_64 ,
T_1 * V_65 , T_1 * V_34 , T_1 * V_66 ,
T_1 * V_67 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_65 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 1 ] . V_32 ;
* V_34 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 1 ] . V_34 ;
* V_66 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 1 ] . V_35 ;
* V_67 = V_2 -> V_8 . V_30 [ V_64 ] . V_31 [ 1 ] . V_36 ;
}
static void F_16 ( struct V_46 * V_26 , int V_34 ,
T_1 * V_66 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_66 = V_2 -> V_8 . V_41 [ 1 ] [ V_34 ] ;
}
static void F_17 ( struct V_46 * V_26 , int V_69 ,
T_1 V_70 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
V_2 -> V_6 . V_30 [ V_69 ] . V_44 = V_70 ;
if ( V_2 -> V_6 . V_30 [ V_69 ] . V_44 !=
V_2 -> V_8 . V_30 [ V_69 ] . V_44 )
V_2 -> V_6 . V_45 = true ;
}
static void F_18 ( struct V_46 * V_26 , int V_69 ,
T_1 * V_70 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_70 = V_2 -> V_8 . V_30 [ V_69 ] . V_44 ;
}
static void F_19 ( struct V_46 * V_71 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
while ( F_20 ( V_72 , & V_2 -> V_49 ) )
F_21 ( 1000 , 2000 ) ;
if ( F_22 ( V_71 ) )
V_71 -> V_73 -> V_74 ( V_71 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( F_22 ( V_71 ) )
V_71 -> V_73 -> V_75 ( V_71 ) ;
F_25 ( V_72 , & V_2 -> V_49 ) ;
}
static T_1 F_26 ( struct V_46 * V_26 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
struct V_4 * V_8 = & V_2 -> V_8 ;
struct V_76 * V_59 = & V_2 -> V_59 ;
int V_77 = V_78 ;
int V_12 ;
if ( ! ( V_2 -> V_51 & V_52 ) )
return V_77 ;
V_2 -> V_79 |= F_1 ( V_2 ,
V_80 ) ;
if ( ! V_2 -> V_79 )
return V_77 ;
if ( V_2 -> V_79 & ( V_33 | V_38 ) ) {
T_2 V_81 [ V_80 ] , V_82 [ V_80 ] ;
T_1 V_34 [ V_80 ] , V_32 [ V_80 ] ;
T_1 V_83 [ V_84 ] ;
int V_85 = V_2 -> V_26 -> V_86 + V_87 + V_88 ;
#ifdef F_2
if ( V_2 -> V_26 -> V_89 & V_90 )
V_85 = V_82 ( V_85 , V_91 ) ;
#endif
F_27 ( V_59 , V_8 , V_85 ,
V_15 ) ;
F_27 ( V_59 , V_8 , V_85 ,
V_17 ) ;
F_28 ( V_8 , V_15 , V_81 ) ;
F_29 ( V_8 , V_82 ) ;
F_30 ( V_8 , V_15 , V_34 ) ;
F_31 ( V_8 , V_15 , V_32 ) ;
F_32 ( V_8 , V_15 , V_83 ) ;
F_33 ( V_59 , V_81 , V_82 , V_34 ,
V_32 , V_83 ) ;
for ( V_12 = 0 ; V_12 < V_92 ; V_12 ++ )
F_34 ( V_26 , V_12 , V_83 [ V_12 ] ) ;
V_77 = V_93 ;
}
if ( V_2 -> V_79 & V_37 ) {
if ( V_8 -> V_45 ) {
T_1 V_94 ;
T_1 V_83 [ V_84 ] ;
F_32 ( V_8 , V_15 , V_83 ) ;
F_35 ( V_8 , & V_94 ) ;
F_36 ( V_59 , V_94 , V_83 ) ;
} else {
V_59 -> V_60 . V_95 . V_96 ( V_59 ) ;
}
F_37 ( V_2 ) ;
V_77 = V_97 ;
}
#ifdef F_2
if ( V_2 -> V_79 & V_28 ) {
struct V_19 V_20 = {
. V_21 = V_22 ,
. V_23 = V_24 ,
} ;
T_1 V_25 = F_3 ( V_26 , & V_20 ) ;
V_2 -> V_27 . V_25 = F_38 ( V_25 ) - 1 ;
F_19 ( V_26 ) ;
V_77 = V_93 ;
}
#endif
V_2 -> V_79 = 0x00 ;
return V_77 ;
}
static T_1 F_39 ( struct V_46 * V_26 , int V_98 , T_1 * V_99 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
switch ( V_98 ) {
case V_100 :
* V_99 = true ;
break;
case V_101 :
* V_99 = true ;
break;
case V_102 :
* V_99 = false ;
break;
case V_103 :
* V_99 = 0x80 ;
break;
case V_104 :
* V_99 = 0x80 ;
break;
case V_105 :
* V_99 = true ;
break;
case V_106 :
* V_99 = false ;
break;
case V_107 :
* V_99 = V_2 -> V_51 ;
break;
default:
* V_99 = false ;
break;
}
return 0 ;
}
static int F_40 ( struct V_46 * V_26 , int V_108 , T_1 * V_109 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
T_1 V_110 = 0 ;
if ( V_2 -> V_47 & V_48 ) {
switch ( V_108 ) {
case V_111 :
* V_109 = V_2 -> V_8 . V_54 . V_55 ;
break;
case V_112 :
* V_109 = V_2 -> V_8 . V_54 . V_113 ;
break;
default:
V_110 = - V_114 ;
break;
}
} else {
V_110 = - V_114 ;
}
return V_110 ;
}
static int F_41 ( struct V_46 * V_26 , int V_108 , T_1 V_109 )
{
return - V_114 ;
}
static T_1 F_42 ( struct V_46 * V_26 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
return V_2 -> V_8 . V_45 ;
}
static void F_43 ( struct V_46 * V_26 , T_1 V_49 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
V_2 -> V_6 . V_45 = V_49 ;
}
static T_1 F_44 ( struct V_46 * V_26 , T_1 V_115 , T_2 V_116 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
struct V_19 V_20 = {
. V_21 = V_115 ,
. V_23 = V_116 ,
} ;
if ( ! ( V_2 -> V_51 & V_52 ) )
return 0 ;
return F_3 ( V_26 , & V_20 ) ;
}
static int F_45 ( struct V_46 * V_71 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
struct V_117 * V_119 = V_2 -> V_120 ;
V_118 -> V_121 = V_2 -> V_8 . V_54 . V_55 ;
if ( ! V_119 )
return 0 ;
V_118 -> V_122 = V_119 -> V_122 ;
memcpy ( V_118 -> V_123 , V_119 -> V_123 , sizeof( V_118 -> V_123 ) ) ;
memcpy ( V_118 -> V_124 , V_119 -> V_124 , sizeof( V_118 -> V_124 ) ) ;
memcpy ( V_118 -> V_125 , V_119 -> V_125 , sizeof( V_118 -> V_125 ) ) ;
memcpy ( V_118 -> V_83 , V_119 -> V_83 , sizeof( V_118 -> V_83 ) ) ;
return 0 ;
}
static int F_46 ( struct V_46 * V_71 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
int V_85 = V_71 -> V_86 + V_87 + V_88 ;
int V_12 , V_50 = 0 ;
T_3 V_126 = 0 ;
if ( ! ( V_2 -> V_51 & V_127 ) )
return - V_114 ;
if ( ! V_2 -> V_120 ) {
V_2 -> V_120 = F_47 ( sizeof( struct V_117 ) ,
V_128 ) ;
if ( ! V_2 -> V_120 )
return - V_129 ;
}
memcpy ( V_2 -> V_120 , V_118 , sizeof( * V_2 -> V_120 ) ) ;
for ( V_12 = 0 ; V_12 < V_92 ; V_12 ++ ) {
if ( V_118 -> V_83 [ V_12 ] > V_126 )
V_126 = V_118 -> V_83 [ V_12 ] ;
}
if ( V_126 )
V_126 ++ ;
if ( V_126 > V_2 -> V_8 . V_54 . V_55 )
return - V_114 ;
if ( V_126 != F_48 ( V_71 ) )
V_50 = F_7 ( V_71 , V_126 ) ;
if ( V_50 )
goto V_130;
V_50 = F_49 ( & V_2 -> V_59 , V_118 , V_85 ) ;
V_130:
return V_50 ;
}
static int F_50 ( struct V_46 * V_71 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
struct V_131 * V_133 = V_2 -> V_134 ;
int V_12 ;
V_132 -> V_135 = V_2 -> V_8 . V_54 . V_113 ;
if ( ! V_133 )
return 0 ;
V_132 -> V_94 = V_133 -> V_94 ;
V_132 -> V_136 = V_133 -> V_136 ;
V_132 -> V_137 = V_133 -> V_137 ;
for ( V_12 = 0 ; V_12 < V_80 ; V_12 ++ ) {
V_132 -> V_138 [ V_12 ] = V_2 -> V_139 . V_140 [ V_12 ] ;
V_132 -> V_141 [ V_12 ] = V_2 -> V_139 . V_142 [ V_12 ] ;
}
return 0 ;
}
static int F_51 ( struct V_46 * V_71 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
struct V_76 * V_59 = & V_2 -> V_59 ;
T_1 * V_83 ;
int V_50 ;
if ( ! ( V_2 -> V_51 & V_127 ) )
return - V_114 ;
if ( ! V_2 -> V_134 ) {
V_2 -> V_134 = F_47 ( sizeof( struct V_131 ) ,
V_128 ) ;
if ( ! V_2 -> V_134 )
return - V_129 ;
}
V_83 = V_2 -> V_120 -> V_83 ;
memcpy ( V_2 -> V_134 , V_132 , sizeof( * V_2 -> V_134 ) ) ;
if ( V_132 -> V_94 )
V_50 = F_36 ( V_59 , V_132 -> V_94 , V_83 ) ;
else
V_50 = V_59 -> V_60 . V_95 . V_96 ( V_59 ) ;
F_37 ( V_2 ) ;
return V_50 ;
}
static int F_52 ( struct V_46 * V_71 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
int V_50 = - V_114 ;
if ( ! ( V_2 -> V_51 & V_127 ) )
return V_50 ;
V_50 = F_53 ( V_71 , V_20 ) ;
#ifdef F_2
if ( ! V_50 && V_20 -> V_21 == V_143 &&
V_20 -> V_23 == V_24 ) {
T_1 V_144 = F_54 ( V_71 , V_20 ) ;
if ( V_144 & ( 1 << V_2 -> V_27 . V_25 ) )
return V_50 ;
V_2 -> V_27 . V_25 = V_20 -> V_69 ;
F_19 ( V_71 ) ;
}
#endif
return 0 ;
}
static int F_55 ( struct V_46 * V_71 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
int V_50 ;
if ( ! ( V_2 -> V_51 & V_127 ) )
return - V_114 ;
V_50 = F_56 ( V_71 , V_20 ) ;
#ifdef F_2
if ( ! V_50 && V_20 -> V_21 == V_143 &&
V_20 -> V_23 == V_24 ) {
T_1 V_144 = F_54 ( V_71 , V_20 ) ;
if ( V_144 & ( 1 << V_2 -> V_27 . V_25 ) )
return V_50 ;
V_2 -> V_27 . V_25 = V_144 ?
F_38 ( V_144 ) - 1 : V_145 ;
F_19 ( V_71 ) ;
}
#endif
return V_50 ;
}
static T_1 F_57 ( struct V_46 * V_71 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
return V_2 -> V_51 ;
}
static T_1 F_58 ( struct V_46 * V_71 , T_1 V_146 )
{
struct V_1 * V_2 = F_5 ( V_71 ) ;
struct V_117 V_118 = { 0 } ;
struct V_131 V_132 = { 0 } ;
int V_50 = 0 ;
if ( ( V_146 & V_147 ) ||
( ( V_146 & V_127 ) && ( V_146 & V_52 ) ) ||
! ( V_146 & V_148 ) )
return 1 ;
if ( V_146 == V_2 -> V_51 )
return 0 ;
V_2 -> V_51 = V_146 ;
V_118 . V_121 = 8 ;
V_132 . V_135 = 8 ;
if ( V_146 & V_127 ) {
F_46 ( V_71 , & V_118 ) ;
F_51 ( V_71 , & V_132 ) ;
} else if ( V_146 & V_52 ) {
T_1 V_149 = V_37 | V_33 | V_38 | V_28 ;
V_2 -> V_79 |= V_149 ;
F_26 ( V_71 ) ;
} else {
F_46 ( V_71 , & V_118 ) ;
F_51 ( V_71 , & V_132 ) ;
V_50 = F_7 ( V_71 , 0 ) ;
}
return V_50 ? 1 : 0 ;
}
