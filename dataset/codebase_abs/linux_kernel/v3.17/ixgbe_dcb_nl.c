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
if ( ! ( V_2 -> V_50 & V_51 ) )
return 1 ;
if ( ! V_49 == ! ( V_2 -> V_47 & V_48 ) )
return 0 ;
return ! ! F_7 ( V_26 ,
V_49 ? V_2 -> V_8 . V_52 . V_53 : 0 ) ;
}
static void F_8 ( struct V_46 * V_26 ,
T_1 * V_54 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
int V_12 , V_13 ;
memset ( V_54 , 0xff , V_55 ) ;
for ( V_12 = 0 ; V_12 < V_26 -> V_56 ; V_12 ++ )
V_54 [ V_12 ] = V_2 -> V_57 . V_58 . V_54 [ V_12 ] ;
switch ( V_2 -> V_57 . V_58 . type ) {
case V_59 :
case V_60 :
for ( V_13 = 0 ; V_13 < V_26 -> V_56 ; V_13 ++ , V_12 ++ )
V_54 [ V_12 ] = V_2 -> V_57 . V_58 . V_61 [ V_13 ] ;
break;
default:
break;
}
}
static void F_9 ( struct V_46 * V_26 , int V_62 ,
T_1 V_63 , T_1 V_34 , T_1 V_64 ,
T_1 V_65 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
if ( V_63 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 0 ] . V_32 = V_63 ;
if ( V_34 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 0 ] . V_34 = V_34 ;
if ( V_64 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 0 ] . V_35 =
V_64 ;
if ( V_65 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 0 ] . V_36 =
V_65 ;
}
static void F_10 ( struct V_46 * V_26 , int V_34 ,
T_1 V_64 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
V_2 -> V_6 . V_41 [ 0 ] [ V_34 ] = V_64 ;
}
static void F_11 ( struct V_46 * V_26 , int V_62 ,
T_1 V_63 , T_1 V_34 , T_1 V_64 ,
T_1 V_65 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
if ( V_63 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 1 ] . V_32 = V_63 ;
if ( V_34 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 1 ] . V_34 = V_34 ;
if ( V_64 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 1 ] . V_35 =
V_64 ;
if ( V_65 != V_66 )
V_2 -> V_6 . V_30 [ V_62 ] . V_31 [ 1 ] . V_36 =
V_65 ;
}
static void F_12 ( struct V_46 * V_26 , int V_34 ,
T_1 V_64 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
V_2 -> V_6 . V_41 [ 1 ] [ V_34 ] = V_64 ;
}
static void F_13 ( struct V_46 * V_26 , int V_62 ,
T_1 * V_63 , T_1 * V_34 , T_1 * V_64 ,
T_1 * V_65 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_63 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 0 ] . V_32 ;
* V_34 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 0 ] . V_34 ;
* V_64 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 0 ] . V_35 ;
* V_65 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 0 ] . V_36 ;
}
static void F_14 ( struct V_46 * V_26 , int V_34 ,
T_1 * V_64 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_64 = V_2 -> V_8 . V_41 [ 0 ] [ V_34 ] ;
}
static void F_15 ( struct V_46 * V_26 , int V_62 ,
T_1 * V_63 , T_1 * V_34 , T_1 * V_64 ,
T_1 * V_65 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_63 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 1 ] . V_32 ;
* V_34 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 1 ] . V_34 ;
* V_64 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 1 ] . V_35 ;
* V_65 = V_2 -> V_8 . V_30 [ V_62 ] . V_31 [ 1 ] . V_36 ;
}
static void F_16 ( struct V_46 * V_26 , int V_34 ,
T_1 * V_64 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_64 = V_2 -> V_8 . V_41 [ 1 ] [ V_34 ] ;
}
static void F_17 ( struct V_46 * V_26 , int V_67 ,
T_1 V_68 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
V_2 -> V_6 . V_30 [ V_67 ] . V_44 = V_68 ;
if ( V_2 -> V_6 . V_30 [ V_67 ] . V_44 !=
V_2 -> V_8 . V_30 [ V_67 ] . V_44 )
V_2 -> V_6 . V_45 = true ;
}
static void F_18 ( struct V_46 * V_26 , int V_67 ,
T_1 * V_68 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
* V_68 = V_2 -> V_8 . V_30 [ V_67 ] . V_44 ;
}
static void F_19 ( struct V_46 * V_69 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
while ( F_20 ( V_70 , & V_2 -> V_49 ) )
F_21 ( 1000 , 2000 ) ;
if ( F_22 ( V_69 ) )
V_69 -> V_71 -> V_72 ( V_69 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( F_22 ( V_69 ) )
V_69 -> V_71 -> V_73 ( V_69 ) ;
F_25 ( V_70 , & V_2 -> V_49 ) ;
}
static T_1 F_26 ( struct V_46 * V_26 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
struct V_4 * V_8 = & V_2 -> V_8 ;
struct V_74 * V_57 = & V_2 -> V_57 ;
int V_75 = V_76 ;
int V_12 ;
if ( ! ( V_2 -> V_50 & V_51 ) )
return V_76 ;
V_2 -> V_77 |= F_1 ( V_2 ,
V_78 ) ;
if ( ! V_2 -> V_77 )
return V_76 ;
if ( V_2 -> V_77 & ( V_33 | V_38 ) ) {
T_2 V_79 [ V_78 ] , V_80 [ V_78 ] ;
T_1 V_34 [ V_78 ] , V_32 [ V_78 ] ;
T_1 V_81 [ V_82 ] ;
int V_83 = V_2 -> V_26 -> V_84 + V_85 + V_86 ;
#ifdef F_2
if ( V_2 -> V_26 -> V_87 & V_88 )
V_83 = V_80 ( V_83 , V_89 ) ;
#endif
F_27 ( V_57 , V_8 , V_83 ,
V_15 ) ;
F_27 ( V_57 , V_8 , V_83 ,
V_17 ) ;
F_28 ( V_8 , V_15 , V_79 ) ;
F_29 ( V_8 , V_80 ) ;
F_30 ( V_8 , V_15 , V_34 ) ;
F_31 ( V_8 , V_15 , V_32 ) ;
F_32 ( V_8 , V_15 , V_81 ) ;
F_33 ( V_57 , V_79 , V_80 , V_34 ,
V_32 , V_81 ) ;
for ( V_12 = 0 ; V_12 < V_90 ; V_12 ++ )
F_34 ( V_26 , V_12 , V_81 [ V_12 ] ) ;
V_75 = V_91 ;
}
if ( V_2 -> V_77 & V_37 ) {
if ( V_8 -> V_45 ) {
T_1 V_92 ;
T_1 V_81 [ V_82 ] ;
F_32 ( V_8 , V_15 , V_81 ) ;
F_35 ( V_8 , & V_92 ) ;
F_36 ( V_57 , V_92 , V_81 ) ;
} else {
V_57 -> V_58 . V_93 . V_94 ( V_57 ) ;
}
F_37 ( V_2 ) ;
V_75 = V_95 ;
}
#ifdef F_2
if ( V_2 -> V_77 & V_28 ) {
struct V_19 V_20 = {
. V_21 = V_22 ,
. V_23 = V_24 ,
} ;
T_1 V_25 = F_3 ( V_26 , & V_20 ) ;
V_2 -> V_27 . V_25 = F_38 ( V_25 ) - 1 ;
F_19 ( V_26 ) ;
V_75 = V_91 ;
}
#endif
V_2 -> V_77 = 0x00 ;
return V_75 ;
}
static T_1 F_39 ( struct V_46 * V_26 , int V_96 , T_1 * V_97 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
switch ( V_96 ) {
case V_98 :
* V_97 = true ;
break;
case V_99 :
* V_97 = true ;
break;
case V_100 :
* V_97 = false ;
break;
case V_101 :
* V_97 = 0x80 ;
break;
case V_102 :
* V_97 = 0x80 ;
break;
case V_103 :
* V_97 = true ;
break;
case V_104 :
* V_97 = false ;
break;
case V_105 :
* V_97 = V_2 -> V_50 ;
break;
default:
* V_97 = false ;
break;
}
return 0 ;
}
static int F_40 ( struct V_46 * V_26 , int V_106 , T_1 * V_107 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
if ( V_2 -> V_47 & V_48 ) {
switch ( V_106 ) {
case V_108 :
* V_107 = V_2 -> V_8 . V_52 . V_53 ;
break;
case V_109 :
* V_107 = V_2 -> V_8 . V_52 . V_110 ;
break;
default:
return - V_111 ;
}
} else {
return - V_111 ;
}
return 0 ;
}
static int F_41 ( struct V_46 * V_26 , int V_106 , T_1 V_107 )
{
return - V_111 ;
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
static int F_44 ( struct V_46 * V_26 , T_1 V_112 , T_2 V_113 )
{
struct V_1 * V_2 = F_5 ( V_26 ) ;
struct V_19 V_20 = {
. V_21 = V_112 ,
. V_23 = V_113 ,
} ;
if ( ! ( V_2 -> V_50 & V_51 ) )
return - V_111 ;
return F_3 ( V_26 , & V_20 ) ;
}
static int F_45 ( struct V_46 * V_69 ,
struct V_114 * V_115 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
struct V_114 * V_116 = V_2 -> V_117 ;
V_115 -> V_118 = V_2 -> V_8 . V_52 . V_53 ;
if ( ! V_116 )
return 0 ;
V_115 -> V_119 = V_116 -> V_119 ;
memcpy ( V_115 -> V_120 , V_116 -> V_120 , sizeof( V_115 -> V_120 ) ) ;
memcpy ( V_115 -> V_121 , V_116 -> V_121 , sizeof( V_115 -> V_121 ) ) ;
memcpy ( V_115 -> V_122 , V_116 -> V_122 , sizeof( V_115 -> V_122 ) ) ;
memcpy ( V_115 -> V_81 , V_116 -> V_81 , sizeof( V_115 -> V_81 ) ) ;
return 0 ;
}
static int F_46 ( struct V_46 * V_69 ,
struct V_114 * V_115 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
int V_83 = V_69 -> V_84 + V_85 + V_86 ;
int V_12 , V_123 ;
T_3 V_124 = 0 ;
T_3 V_125 = 0 ;
if ( ! ( V_2 -> V_50 & V_126 ) )
return - V_111 ;
if ( ! V_2 -> V_117 ) {
V_2 -> V_117 = F_47 ( sizeof( struct V_114 ) ,
V_127 ) ;
if ( ! V_2 -> V_117 )
return - V_128 ;
for ( V_12 = 0 ; V_12 < V_90 ; V_12 ++ )
V_2 -> V_117 -> V_81 [ V_12 ] =
V_90 ;
F_48 ( & V_2 -> V_57 ,
V_2 -> V_117 -> V_81 ) ;
}
for ( V_12 = 0 ; V_12 < V_90 ; V_12 ++ ) {
if ( V_115 -> V_81 [ V_12 ] > V_124 )
V_124 = V_115 -> V_81 [ V_12 ] ;
if ( V_115 -> V_81 [ V_12 ] != V_2 -> V_117 -> V_81 [ V_12 ] )
V_125 = 1 ;
}
memcpy ( V_2 -> V_117 , V_115 , sizeof( * V_2 -> V_117 ) ) ;
if ( V_124 )
V_124 ++ ;
if ( V_124 > V_2 -> V_8 . V_52 . V_53 )
return - V_111 ;
if ( V_124 != F_49 ( V_69 ) ) {
V_123 = F_7 ( V_69 , V_124 ) ;
if ( V_123 )
return V_123 ;
} else if ( V_125 ) {
F_19 ( V_69 ) ;
}
return F_50 ( & V_2 -> V_57 , V_115 , V_83 ) ;
}
static int F_51 ( struct V_46 * V_69 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
struct V_129 * V_131 = V_2 -> V_132 ;
int V_12 ;
V_130 -> V_133 = V_2 -> V_8 . V_52 . V_110 ;
if ( ! V_131 )
return 0 ;
V_130 -> V_92 = V_131 -> V_92 ;
V_130 -> V_134 = V_131 -> V_134 ;
V_130 -> V_135 = V_131 -> V_135 ;
for ( V_12 = 0 ; V_12 < V_78 ; V_12 ++ ) {
V_130 -> V_136 [ V_12 ] = V_2 -> V_137 . V_138 [ V_12 ] ;
V_130 -> V_139 [ V_12 ] = V_2 -> V_137 . V_140 [ V_12 ] ;
}
return 0 ;
}
static int F_52 ( struct V_46 * V_69 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
struct V_74 * V_57 = & V_2 -> V_57 ;
T_1 * V_81 ;
int V_123 ;
if ( ! ( V_2 -> V_50 & V_126 ) )
return - V_111 ;
if ( ! V_2 -> V_132 ) {
V_2 -> V_132 = F_47 ( sizeof( struct V_129 ) ,
V_127 ) ;
if ( ! V_2 -> V_132 )
return - V_128 ;
}
V_81 = V_2 -> V_117 -> V_81 ;
memcpy ( V_2 -> V_132 , V_130 , sizeof( * V_2 -> V_132 ) ) ;
if ( V_130 -> V_92 )
V_123 = F_36 ( V_57 , V_130 -> V_92 , V_81 ) ;
else
V_123 = V_57 -> V_58 . V_93 . V_94 ( V_57 ) ;
F_37 ( V_2 ) ;
return V_123 ;
}
static int F_53 ( struct V_46 * V_69 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
int V_123 ;
if ( ! ( V_2 -> V_50 & V_126 ) )
return - V_111 ;
V_123 = F_54 ( V_69 , V_20 ) ;
if ( V_123 )
return V_123 ;
#ifdef F_2
if ( V_20 -> V_21 == V_141 &&
V_20 -> V_23 == V_24 ) {
T_1 V_142 = F_55 ( V_69 , V_20 ) ;
if ( V_142 & ( 1 << V_2 -> V_27 . V_25 ) )
return 0 ;
V_2 -> V_27 . V_25 = V_20 -> V_67 ;
F_19 ( V_69 ) ;
}
#endif
if ( V_20 -> V_21 == V_141 &&
V_20 -> V_23 == 0 ) {
int V_143 ;
V_2 -> V_144 = V_20 -> V_67 ;
for ( V_143 = 0 ; V_143 < V_2 -> V_145 ; V_143 ++ ) {
struct V_146 * V_147 = & V_2 -> V_147 [ V_143 ] ;
if ( ! V_147 -> V_148 )
F_56 ( V_2 , V_147 -> V_149 ,
V_20 -> V_67 , V_143 ) ;
}
}
return 0 ;
}
static int F_57 ( struct V_46 * V_69 ,
struct V_19 * V_20 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
int V_123 ;
if ( ! ( V_2 -> V_50 & V_126 ) )
return - V_111 ;
V_123 = F_58 ( V_69 , V_20 ) ;
#ifdef F_2
if ( ! V_123 && V_20 -> V_21 == V_141 &&
V_20 -> V_23 == V_24 ) {
T_1 V_142 = F_55 ( V_69 , V_20 ) ;
if ( V_142 & ( 1 << V_2 -> V_27 . V_25 ) )
return 0 ;
V_2 -> V_27 . V_25 = V_142 ?
F_38 ( V_142 ) - 1 : V_150 ;
F_19 ( V_69 ) ;
}
#endif
if ( V_20 -> V_21 == V_141 &&
V_20 -> V_23 == 0 && V_2 -> V_144 == V_20 -> V_67 ) {
int V_143 ;
long unsigned int V_142 = F_55 ( V_69 , V_20 ) ;
int V_151 = V_142 ? F_59 ( & V_142 , 8 ) : 0 ;
V_2 -> V_144 = V_151 ;
for ( V_143 = 0 ; V_143 < V_2 -> V_145 ; V_143 ++ ) {
struct V_146 * V_147 = & V_2 -> V_147 [ V_143 ] ;
if ( ! V_147 -> V_148 )
F_56 ( V_2 , V_147 -> V_149 ,
V_151 , V_143 ) ;
}
}
return V_123 ;
}
static T_1 F_60 ( struct V_46 * V_69 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
return V_2 -> V_50 ;
}
static T_1 F_61 ( struct V_46 * V_69 , T_1 V_152 )
{
struct V_1 * V_2 = F_5 ( V_69 ) ;
struct V_114 V_115 = { 0 } ;
struct V_129 V_130 = { 0 } ;
int V_123 = 0 ;
if ( ( V_152 & V_153 ) ||
( ( V_152 & V_126 ) && ( V_152 & V_51 ) ) ||
! ( V_152 & V_154 ) )
return 1 ;
if ( V_152 == V_2 -> V_50 )
return 0 ;
V_2 -> V_50 = V_152 ;
V_115 . V_118 = 8 ;
V_130 . V_133 = 8 ;
if ( V_152 & V_126 ) {
F_46 ( V_69 , & V_115 ) ;
F_52 ( V_69 , & V_130 ) ;
} else if ( V_152 & V_51 ) {
T_1 V_155 = V_37 | V_33 | V_38 | V_28 ;
V_2 -> V_77 |= V_155 ;
F_26 ( V_69 ) ;
} else {
F_46 ( V_69 , & V_115 ) ;
F_52 ( V_69 , & V_130 ) ;
V_123 = F_7 ( V_69 , 0 ) ;
}
return V_123 ? 1 : 0 ;
}
