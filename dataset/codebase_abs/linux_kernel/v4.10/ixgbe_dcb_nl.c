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
if ( V_25 && ! ( V_25 & F_4 ( V_2 -> V_27 . V_25 ) ) )
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
static T_1 F_5 ( struct V_46 * V_26 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
return ! ! ( V_2 -> V_47 & V_48 ) ;
}
static T_1 F_7 ( struct V_46 * V_26 , T_1 V_49 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
if ( ! ( V_2 -> V_50 & V_51 ) )
return 1 ;
if ( ! V_49 == ! ( V_2 -> V_47 & V_48 ) )
return 0 ;
return ! ! F_8 ( V_26 ,
V_49 ? V_2 -> V_8 . V_52 . V_53 : 0 ) ;
}
static void F_9 ( struct V_46 * V_26 ,
T_1 * V_54 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
int V_12 , V_13 ;
memset ( V_54 , 0xff , V_55 ) ;
for ( V_12 = 0 ; V_12 < V_26 -> V_56 ; V_12 ++ )
V_54 [ V_12 ] = V_2 -> V_57 . V_58 . V_54 [ V_12 ] ;
switch ( V_2 -> V_57 . V_58 . type ) {
case V_59 :
case V_60 :
case V_61 :
for ( V_13 = 0 ; V_13 < V_26 -> V_56 ; V_13 ++ , V_12 ++ )
V_54 [ V_12 ] = V_2 -> V_57 . V_58 . V_62 [ V_13 ] ;
break;
default:
break;
}
}
static void F_10 ( struct V_46 * V_26 , int V_63 ,
T_1 V_64 , T_1 V_34 , T_1 V_65 ,
T_1 V_66 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
if ( V_64 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 0 ] . V_32 = V_64 ;
if ( V_34 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 0 ] . V_34 = V_34 ;
if ( V_65 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 0 ] . V_35 =
V_65 ;
if ( V_66 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 0 ] . V_36 =
V_66 ;
}
static void F_11 ( struct V_46 * V_26 , int V_34 ,
T_1 V_65 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
V_2 -> V_6 . V_41 [ 0 ] [ V_34 ] = V_65 ;
}
static void F_12 ( struct V_46 * V_26 , int V_63 ,
T_1 V_64 , T_1 V_34 , T_1 V_65 ,
T_1 V_66 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
if ( V_64 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 1 ] . V_32 = V_64 ;
if ( V_34 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 1 ] . V_34 = V_34 ;
if ( V_65 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 1 ] . V_35 =
V_65 ;
if ( V_66 != V_67 )
V_2 -> V_6 . V_30 [ V_63 ] . V_31 [ 1 ] . V_36 =
V_66 ;
}
static void F_13 ( struct V_46 * V_26 , int V_34 ,
T_1 V_65 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
V_2 -> V_6 . V_41 [ 1 ] [ V_34 ] = V_65 ;
}
static void F_14 ( struct V_46 * V_26 , int V_63 ,
T_1 * V_64 , T_1 * V_34 , T_1 * V_65 ,
T_1 * V_66 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
* V_64 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 0 ] . V_32 ;
* V_34 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 0 ] . V_34 ;
* V_65 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 0 ] . V_35 ;
* V_66 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 0 ] . V_36 ;
}
static void F_15 ( struct V_46 * V_26 , int V_34 ,
T_1 * V_65 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
* V_65 = V_2 -> V_8 . V_41 [ 0 ] [ V_34 ] ;
}
static void F_16 ( struct V_46 * V_26 , int V_63 ,
T_1 * V_64 , T_1 * V_34 , T_1 * V_65 ,
T_1 * V_66 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
* V_64 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 1 ] . V_32 ;
* V_34 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 1 ] . V_34 ;
* V_65 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 1 ] . V_35 ;
* V_66 = V_2 -> V_8 . V_30 [ V_63 ] . V_31 [ 1 ] . V_36 ;
}
static void F_17 ( struct V_46 * V_26 , int V_34 ,
T_1 * V_65 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
* V_65 = V_2 -> V_8 . V_41 [ 1 ] [ V_34 ] ;
}
static void F_18 ( struct V_46 * V_26 , int V_68 ,
T_1 V_69 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
V_2 -> V_6 . V_30 [ V_68 ] . V_44 = V_69 ;
if ( V_2 -> V_6 . V_30 [ V_68 ] . V_44 !=
V_2 -> V_8 . V_30 [ V_68 ] . V_44 )
V_2 -> V_6 . V_45 = true ;
}
static void F_19 ( struct V_46 * V_26 , int V_68 ,
T_1 * V_69 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
* V_69 = V_2 -> V_8 . V_30 [ V_68 ] . V_44 ;
}
static void F_20 ( struct V_46 * V_70 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
while ( F_21 ( V_71 , & V_2 -> V_49 ) )
F_22 ( 1000 , 2000 ) ;
if ( F_23 ( V_70 ) )
V_70 -> V_72 -> V_73 ( V_70 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
if ( F_23 ( V_70 ) )
V_70 -> V_72 -> V_74 ( V_70 ) ;
F_26 ( V_71 , & V_2 -> V_49 ) ;
}
static T_1 F_27 ( struct V_46 * V_26 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
struct V_4 * V_8 = & V_2 -> V_8 ;
struct V_75 * V_57 = & V_2 -> V_57 ;
int V_76 = V_77 ;
int V_12 ;
if ( ! ( V_2 -> V_50 & V_51 ) )
return V_77 ;
V_2 -> V_78 |= F_1 ( V_2 ,
V_79 ) ;
if ( ! V_2 -> V_78 )
return V_77 ;
if ( V_2 -> V_78 & ( V_33 | V_38 ) ) {
T_2 V_80 [ V_79 ] , V_81 [ V_79 ] ;
T_1 V_34 [ V_79 ] , V_32 [ V_79 ] ;
T_1 V_82 [ V_83 ] ;
int V_84 = V_2 -> V_26 -> V_85 + V_86 + V_87 ;
#ifdef F_2
if ( V_2 -> V_26 -> V_88 & V_89 )
V_84 = V_81 ( V_84 , V_90 ) ;
#endif
F_28 ( V_57 , V_8 , V_84 ,
V_15 ) ;
F_28 ( V_57 , V_8 , V_84 ,
V_17 ) ;
F_29 ( V_8 , V_15 , V_80 ) ;
F_30 ( V_8 , V_81 ) ;
F_31 ( V_8 , V_15 , V_34 ) ;
F_32 ( V_8 , V_15 , V_32 ) ;
F_33 ( V_8 , V_15 , V_82 ) ;
F_34 ( V_57 , V_80 , V_81 , V_34 ,
V_32 , V_82 ) ;
for ( V_12 = 0 ; V_12 < V_91 ; V_12 ++ )
F_35 ( V_26 , V_12 , V_82 [ V_12 ] ) ;
V_76 = V_92 ;
}
if ( V_2 -> V_78 & V_37 ) {
if ( V_8 -> V_45 ) {
T_1 V_93 ;
T_1 V_82 [ V_83 ] ;
F_33 ( V_8 , V_15 , V_82 ) ;
F_36 ( V_8 , & V_93 ) ;
F_37 ( V_57 , V_93 , V_82 ) ;
} else {
V_57 -> V_58 . V_94 . V_95 ( V_57 ) ;
}
F_38 ( V_2 ) ;
V_76 = V_96 ;
}
#ifdef F_2
if ( V_2 -> V_78 & V_28 ) {
struct V_19 V_20 = {
. V_21 = V_22 ,
. V_23 = V_24 ,
} ;
T_1 V_25 = F_3 ( V_26 , & V_20 ) ;
V_2 -> V_27 . V_25 = F_39 ( V_25 ) - 1 ;
F_20 ( V_26 ) ;
V_76 = V_92 ;
}
#endif
V_2 -> V_78 = 0x00 ;
return V_76 ;
}
static T_1 F_40 ( struct V_46 * V_26 , int V_97 , T_1 * V_98 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
switch ( V_97 ) {
case V_99 :
* V_98 = true ;
break;
case V_100 :
* V_98 = true ;
break;
case V_101 :
* V_98 = false ;
break;
case V_102 :
* V_98 = 0x80 ;
break;
case V_103 :
* V_98 = 0x80 ;
break;
case V_104 :
* V_98 = true ;
break;
case V_105 :
* V_98 = false ;
break;
case V_106 :
* V_98 = V_2 -> V_50 ;
break;
default:
* V_98 = false ;
break;
}
return 0 ;
}
static int F_41 ( struct V_46 * V_26 , int V_107 , T_1 * V_108 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
if ( V_2 -> V_47 & V_48 ) {
switch ( V_107 ) {
case V_109 :
* V_108 = V_2 -> V_8 . V_52 . V_53 ;
break;
case V_110 :
* V_108 = V_2 -> V_8 . V_52 . V_111 ;
break;
default:
return - V_112 ;
}
} else {
return - V_112 ;
}
return 0 ;
}
static int F_42 ( struct V_46 * V_26 , int V_107 , T_1 V_108 )
{
return - V_112 ;
}
static T_1 F_43 ( struct V_46 * V_26 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
return V_2 -> V_8 . V_45 ;
}
static void F_44 ( struct V_46 * V_26 , T_1 V_49 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
V_2 -> V_6 . V_45 = V_49 ;
}
static int F_45 ( struct V_46 * V_26 , T_1 V_113 , T_2 V_114 )
{
struct V_1 * V_2 = F_6 ( V_26 ) ;
struct V_19 V_20 = {
. V_21 = V_113 ,
. V_23 = V_114 ,
} ;
if ( ! ( V_2 -> V_50 & V_51 ) )
return - V_112 ;
return F_3 ( V_26 , & V_20 ) ;
}
static int F_46 ( struct V_46 * V_70 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
struct V_115 * V_117 = V_2 -> V_118 ;
V_116 -> V_119 = V_2 -> V_8 . V_52 . V_53 ;
if ( ! V_117 )
return 0 ;
V_116 -> V_120 = V_117 -> V_120 ;
memcpy ( V_116 -> V_121 , V_117 -> V_121 , sizeof( V_116 -> V_121 ) ) ;
memcpy ( V_116 -> V_122 , V_117 -> V_122 , sizeof( V_116 -> V_122 ) ) ;
memcpy ( V_116 -> V_123 , V_117 -> V_123 , sizeof( V_116 -> V_123 ) ) ;
memcpy ( V_116 -> V_82 , V_117 -> V_82 , sizeof( V_116 -> V_82 ) ) ;
return 0 ;
}
static int F_47 ( struct V_46 * V_70 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
int V_84 = V_70 -> V_85 + V_86 + V_87 ;
int V_12 , V_124 ;
T_3 V_125 = 0 ;
T_3 V_126 = 0 ;
if ( ! ( V_2 -> V_50 & V_127 ) )
return - V_112 ;
if ( ! V_2 -> V_118 ) {
V_2 -> V_118 = F_48 ( sizeof( struct V_115 ) ,
V_128 ) ;
if ( ! V_2 -> V_118 )
return - V_129 ;
for ( V_12 = 0 ; V_12 < V_91 ; V_12 ++ )
V_2 -> V_118 -> V_82 [ V_12 ] =
V_91 ;
F_49 ( & V_2 -> V_57 ,
V_2 -> V_118 -> V_82 ) ;
}
for ( V_12 = 0 ; V_12 < V_91 ; V_12 ++ ) {
if ( V_116 -> V_82 [ V_12 ] > V_125 )
V_125 = V_116 -> V_82 [ V_12 ] ;
if ( V_116 -> V_82 [ V_12 ] != V_2 -> V_118 -> V_82 [ V_12 ] )
V_126 = 1 ;
}
memcpy ( V_2 -> V_118 , V_116 , sizeof( * V_2 -> V_118 ) ) ;
if ( V_125 )
V_125 ++ ;
if ( V_125 > V_2 -> V_8 . V_52 . V_53 )
return - V_112 ;
if ( V_125 != F_50 ( V_70 ) ) {
V_124 = F_8 ( V_70 , V_125 ) ;
if ( V_124 )
return V_124 ;
} else if ( V_126 ) {
F_20 ( V_70 ) ;
}
return F_51 ( & V_2 -> V_57 , V_116 , V_84 ) ;
}
static int F_52 ( struct V_46 * V_70 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
struct V_130 * V_132 = V_2 -> V_133 ;
int V_12 ;
V_131 -> V_134 = V_2 -> V_8 . V_52 . V_111 ;
if ( ! V_132 )
return 0 ;
V_131 -> V_93 = V_132 -> V_93 ;
V_131 -> V_135 = V_132 -> V_135 ;
V_131 -> V_136 = V_132 -> V_136 ;
for ( V_12 = 0 ; V_12 < V_79 ; V_12 ++ ) {
V_131 -> V_137 [ V_12 ] = V_2 -> V_138 . V_139 [ V_12 ] ;
V_131 -> V_140 [ V_12 ] = V_2 -> V_138 . V_141 [ V_12 ] ;
}
return 0 ;
}
static int F_53 ( struct V_46 * V_70 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
struct V_75 * V_57 = & V_2 -> V_57 ;
T_1 * V_82 ;
int V_124 ;
if ( ! ( V_2 -> V_50 & V_127 ) )
return - V_112 ;
if ( ! V_2 -> V_133 ) {
V_2 -> V_133 = F_48 ( sizeof( struct V_130 ) ,
V_128 ) ;
if ( ! V_2 -> V_133 )
return - V_129 ;
}
V_82 = V_2 -> V_118 -> V_82 ;
memcpy ( V_2 -> V_133 , V_131 , sizeof( * V_2 -> V_133 ) ) ;
if ( V_131 -> V_93 )
V_124 = F_37 ( V_57 , V_131 -> V_93 , V_82 ) ;
else
V_124 = V_57 -> V_58 . V_94 . V_95 ( V_57 ) ;
F_38 ( V_2 ) ;
return V_124 ;
}
static int F_54 ( struct V_46 * V_70 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
int V_124 ;
if ( ! ( V_2 -> V_50 & V_127 ) )
return - V_112 ;
V_124 = F_55 ( V_70 , V_20 ) ;
if ( V_124 )
return V_124 ;
#ifdef F_2
if ( V_20 -> V_21 == V_142 &&
V_20 -> V_23 == V_24 ) {
T_1 V_143 = F_56 ( V_70 , V_20 ) ;
if ( V_143 & F_4 ( V_2 -> V_27 . V_25 ) )
return 0 ;
V_2 -> V_27 . V_25 = V_20 -> V_68 ;
F_20 ( V_70 ) ;
}
#endif
if ( V_20 -> V_21 == V_142 &&
V_20 -> V_23 == 0 ) {
int V_144 ;
V_2 -> V_145 = V_20 -> V_68 ;
for ( V_144 = 0 ; V_144 < V_2 -> V_146 ; V_144 ++ ) {
struct V_147 * V_148 = & V_2 -> V_148 [ V_144 ] ;
if ( ! V_148 -> V_149 )
F_57 ( V_2 , V_148 -> V_150 ,
V_20 -> V_68 , V_144 ) ;
}
}
return 0 ;
}
static int F_58 ( struct V_46 * V_70 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
int V_124 ;
if ( ! ( V_2 -> V_50 & V_127 ) )
return - V_112 ;
V_124 = F_59 ( V_70 , V_20 ) ;
#ifdef F_2
if ( ! V_124 && V_20 -> V_21 == V_142 &&
V_20 -> V_23 == V_24 ) {
T_1 V_143 = F_56 ( V_70 , V_20 ) ;
if ( V_143 & F_4 ( V_2 -> V_27 . V_25 ) )
return 0 ;
V_2 -> V_27 . V_25 = V_143 ?
F_39 ( V_143 ) - 1 : V_151 ;
F_20 ( V_70 ) ;
}
#endif
if ( V_20 -> V_21 == V_142 &&
V_20 -> V_23 == 0 && V_2 -> V_145 == V_20 -> V_68 ) {
int V_144 ;
long unsigned int V_143 = F_56 ( V_70 , V_20 ) ;
int V_152 = V_143 ? F_60 ( & V_143 , 8 ) : 0 ;
V_2 -> V_145 = V_152 ;
for ( V_144 = 0 ; V_144 < V_2 -> V_146 ; V_144 ++ ) {
struct V_147 * V_148 = & V_2 -> V_148 [ V_144 ] ;
if ( ! V_148 -> V_149 )
F_57 ( V_2 , V_148 -> V_150 ,
V_152 , V_144 ) ;
}
}
return V_124 ;
}
static T_1 F_61 ( struct V_46 * V_70 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
return V_2 -> V_50 ;
}
static T_1 F_62 ( struct V_46 * V_70 , T_1 V_153 )
{
struct V_1 * V_2 = F_6 ( V_70 ) ;
struct V_115 V_116 = { 0 } ;
struct V_130 V_131 = { 0 } ;
int V_124 = 0 ;
if ( ( V_153 & V_154 ) ||
( ( V_153 & V_127 ) && ( V_153 & V_51 ) ) ||
! ( V_153 & V_155 ) )
return 1 ;
if ( V_153 == V_2 -> V_50 )
return 0 ;
V_2 -> V_50 = V_153 ;
V_116 . V_119 = 8 ;
V_131 . V_134 = 8 ;
if ( V_153 & V_127 ) {
F_47 ( V_70 , & V_116 ) ;
F_53 ( V_70 , & V_131 ) ;
} else if ( V_153 & V_51 ) {
T_1 V_156 = V_37 | V_33 | V_38 | V_28 ;
V_2 -> V_78 |= V_156 ;
F_27 ( V_70 ) ;
} else {
F_47 ( V_70 , & V_116 ) ;
F_53 ( V_70 , & V_131 ) ;
V_124 = F_8 ( V_70 , 0 ) ;
}
return V_124 ? 1 : 0 ;
}
