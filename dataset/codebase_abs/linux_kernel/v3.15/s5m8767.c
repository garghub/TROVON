static int F_1 ( struct V_1 * V_2 , int V_3 ,
int * V_4 , int * V_5 )
{
int V_6 ;
unsigned int V_7 ;
switch ( V_3 ) {
case V_8 ... V_9 :
* V_4 = V_10 + ( V_3 - V_8 ) ;
break;
case V_11 ... V_12 :
* V_4 = V_13 + ( V_3 - V_11 ) ;
break;
case V_14 :
* V_4 = V_15 ;
break;
case V_16 ... V_17 :
* V_4 = V_18 + ( V_3 - V_16 ) * 9 ;
break;
case V_19 :
* V_4 = V_20 ;
break;
case V_21 ... V_22 :
* V_4 = V_23 + ( V_3 - V_21 ) * 2 ;
break;
default:
return - V_24 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_25 ; V_6 ++ ) {
if ( V_2 -> V_26 [ V_6 ] . V_27 == V_3 ) {
V_7 = V_2 -> V_26 [ V_6 ] . V_7 ;
break;
}
}
if ( V_6 < V_2 -> V_25 )
* V_5 =
V_28 [ V_3 ] [ V_7 ] << V_29 ;
return 0 ;
}
static int F_2 ( int V_3 , struct V_1 * V_2 )
{
int V_4 ;
switch ( V_3 ) {
case V_8 ... V_9 :
V_4 = V_10 + ( V_3 - V_8 ) ;
break;
case V_11 ... V_12 :
V_4 = V_13 + ( V_3 - V_11 ) ;
break;
case V_14 :
V_4 = V_30 ;
break;
case V_16 :
V_4 = V_31 ;
if ( V_2 -> V_32 )
V_4 += V_2 -> V_33 ;
break;
case V_34 :
V_4 = V_35 ;
if ( V_2 -> V_36 )
V_4 += V_2 -> V_33 ;
break;
case V_17 :
V_4 = V_37 ;
if ( V_2 -> V_38 )
V_4 += V_2 -> V_33 ;
break;
case V_19 :
V_4 = V_39 ;
break;
case V_21 ... V_22 :
V_4 = V_40 + ( V_3 - V_21 ) * 2 ;
break;
default:
return - V_24 ;
}
return V_4 ;
}
static int F_3 ( const struct V_41 * V_42 ,
int V_43 )
{
int V_44 = 0 ;
if ( V_42 == NULL )
return - V_24 ;
if ( V_43 > V_42 -> V_45 )
return - V_24 ;
if ( V_43 < V_42 -> V_46 )
V_43 = V_42 -> V_46 ;
V_44 = F_4 ( V_43 - V_42 -> V_46 , V_42 -> V_47 ) ;
if ( V_42 -> V_46 + V_42 -> V_47 * V_44 > V_42 -> V_45 )
return - V_24 ;
return V_44 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_33 ;
F_6 ( V_2 -> V_49 [ 0 ] , ( V_48 >> 2 ) & 0x1 ) ;
F_6 ( V_2 -> V_49 [ 1 ] , ( V_48 >> 1 ) & 0x1 ) ;
F_6 ( V_2 -> V_49 [ 2 ] , V_48 & 0x1 ) ;
return 0 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
int V_48 = V_2 -> V_33 ;
F_6 ( V_2 -> V_49 [ 2 ] , V_48 & 0x1 ) ;
F_6 ( V_2 -> V_49 [ 1 ] , ( V_48 >> 1 ) & 0x1 ) ;
F_6 ( V_2 -> V_49 [ 0 ] , ( V_48 >> 2 ) & 0x1 ) ;
return 0 ;
}
static int F_8 ( struct V_50 * V_51 ,
unsigned V_44 )
{
struct V_1 * V_2 = F_9 ( V_51 ) ;
int V_3 = F_10 ( V_51 ) ;
int V_52 , V_53 = 0 ;
T_1 * V_54 = NULL ;
switch ( V_3 ) {
case V_8 ... V_12 :
break;
case V_14 ... V_21 :
if ( V_3 == V_16 && V_2 -> V_32 )
V_54 = & V_2 -> V_55 [ 0 ] ;
else if ( V_3 == V_34 && V_2 -> V_36 )
V_54 = & V_2 -> V_56 [ 0 ] ;
else if ( V_3 == V_17 && V_2 -> V_38 )
V_54 = & V_2 -> V_57 [ 0 ] ;
break;
case V_58 ... V_59 :
return - V_24 ;
case V_22 :
break;
default:
return - V_24 ;
}
if ( V_54 ) {
while ( * V_54 != V_44 ) {
V_54 ++ ;
V_53 ++ ;
}
V_52 = V_2 -> V_33 ;
V_2 -> V_33 = V_53 ;
if ( V_53 > V_52 )
return F_5 ( V_2 ) ;
else
return F_7 ( V_2 ) ;
} else {
return F_11 ( V_51 , V_44 ) ;
}
}
static int F_12 ( struct V_50 * V_51 ,
unsigned int V_60 ,
unsigned int V_61 )
{
struct V_1 * V_2 = F_9 ( V_51 ) ;
const struct V_41 * V_42 ;
int V_3 = F_10 ( V_51 ) ;
V_42 = V_62 [ V_3 ] ;
if ( ( V_60 < V_61 ) && V_2 -> V_63 )
return F_4 ( V_42 -> V_47 * ( V_61 - V_60 ) ,
V_2 -> V_63 * 1000 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_64 * V_65 ,
struct V_66 * V_67 )
{
int V_6 , V_7 = 0 ;
if ( V_65 -> V_27 != V_22 )
return;
for ( V_6 = 0 ; V_6 < V_2 -> V_25 ; V_6 ++ ) {
const struct V_68 * V_26 = & V_2 -> V_26 [ V_6 ] ;
if ( V_26 -> V_27 == V_65 -> V_27 ) {
V_7 = V_28 [ V_65 -> V_27 ] [ V_26 -> V_7 ] ;
break;
}
}
if ( V_7 != V_69 ) {
F_14 ( V_2 -> V_70 ,
L_1 ,
V_65 -> V_71 -> V_72 , V_7 ) ;
return;
}
if ( ! F_15 ( V_65 -> V_73 ) ) {
F_14 ( V_2 -> V_70 ,
L_2 ,
V_65 -> V_71 -> V_72 ) ;
return;
}
V_67 -> V_74 = V_65 -> V_73 ;
V_67 -> V_75 = V_76 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_27 = F_10 ( V_51 ) ;
int V_77 , V_4 , V_5 ;
if ( V_27 != V_22 )
return - V_24 ;
V_77 = F_1 ( V_2 , V_27 , & V_4 , & V_5 ) ;
if ( V_77 )
return V_77 ;
return F_17 ( V_2 -> V_78 -> V_79 ,
V_4 , V_80 ,
V_69 << V_29 ) ;
}
static int F_18 ( struct V_81 * V_78 ,
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
int V_6 , V_86 ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
V_86 = F_19 ( V_85 ,
L_3 , V_6 ) ;
if ( ! F_15 ( V_86 ) ) {
F_20 ( V_78 -> V_70 , L_4 , V_6 , V_86 ) ;
return - V_24 ;
}
V_83 -> V_49 [ V_6 ] = V_86 ;
}
return 0 ;
}
static int F_21 ( struct V_81 * V_78 ,
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
int V_6 , V_86 ;
for ( V_6 = 0 ; V_6 < 3 ; V_6 ++ ) {
V_86 = F_19 ( V_85 ,
L_5 , V_6 ) ;
if ( ! F_15 ( V_86 ) ) {
F_20 ( V_78 -> V_70 , L_4 , V_6 , V_86 ) ;
return - V_24 ;
}
V_83 -> V_87 [ V_6 ] = V_86 ;
}
return 0 ;
}
static void F_22 ( struct V_81 * V_78 ,
struct V_64 * V_65 ,
struct V_84 * V_88 )
{
V_65 -> V_73 = F_19 ( V_88 ,
L_6 , 0 ) ;
if ( ! F_15 ( V_65 -> V_73 ) )
V_65 -> V_73 = 0 ;
}
static int F_23 ( struct V_89 * V_90 ,
struct V_82 * V_83 )
{
struct V_81 * V_78 = F_24 ( V_90 -> V_70 . V_91 ) ;
struct V_84 * V_85 , * V_92 , * V_88 ;
struct V_64 * V_65 ;
struct V_68 * V_93 ;
unsigned int V_6 , V_94 = 8 , V_77 ;
V_85 = V_78 -> V_70 -> V_95 ;
if ( ! V_85 ) {
F_20 ( V_78 -> V_70 , L_7 ) ;
return - V_96 ;
}
V_92 = F_25 ( V_85 , L_8 ) ;
if ( ! V_92 ) {
F_20 ( V_78 -> V_70 , L_9 ) ;
return - V_24 ;
}
V_83 -> V_25 = F_26 ( V_92 ) ;
V_65 = F_27 ( & V_90 -> V_70 , sizeof( * V_65 ) *
V_83 -> V_25 , V_97 ) ;
if ( ! V_65 )
return - V_98 ;
V_93 = F_27 ( & V_90 -> V_70 , sizeof( * V_93 ) *
V_83 -> V_25 , V_97 ) ;
if ( ! V_93 )
return - V_98 ;
V_83 -> V_99 = V_65 ;
V_83 -> V_26 = V_93 ;
F_28 (regulators_np, reg_np) {
for ( V_6 = 0 ; V_6 < F_29 ( V_99 ) ; V_6 ++ )
if ( ! F_30 ( V_88 -> V_72 , V_99 [ V_6 ] . V_72 ) )
break;
if ( V_6 == F_29 ( V_99 ) ) {
F_14 ( V_78 -> V_70 ,
L_10 ,
V_88 -> V_72 ) ;
continue;
}
F_22 ( V_78 , V_65 , V_88 ) ;
V_65 -> V_27 = V_6 ;
V_65 -> V_100 = F_31 (
& V_90 -> V_70 , V_88 ) ;
V_65 -> V_71 = V_88 ;
V_65 ++ ;
V_93 -> V_27 = V_6 ;
if ( F_32 ( V_88 , L_11 ,
& V_93 -> V_7 ) ) {
F_14 ( V_78 -> V_70 ,
L_12 ,
V_88 -> V_101 ) ;
V_93 -> V_7 = V_102 ;
}
V_93 ++ ;
}
F_33 ( V_92 ) ;
if ( F_34 ( V_85 , L_13 , NULL ) ) {
V_83 -> V_32 = true ;
if ( F_35 ( V_85 ,
L_14 ,
V_83 -> V_103 , V_94 ) ) {
F_20 ( V_78 -> V_70 , L_15 ) ;
return - V_24 ;
}
}
if ( F_34 ( V_85 , L_16 , NULL ) ) {
V_83 -> V_36 = true ;
if ( F_35 ( V_85 ,
L_17 ,
V_83 -> V_104 , V_94 ) ) {
F_20 ( V_78 -> V_70 , L_18 ) ;
return - V_24 ;
}
}
if ( F_34 ( V_85 , L_19 , NULL ) ) {
V_83 -> V_38 = true ;
if ( F_35 ( V_85 ,
L_20 ,
V_83 -> V_105 , V_94 ) ) {
F_20 ( V_78 -> V_70 , L_21 ) ;
return - V_24 ;
}
}
if ( V_83 -> V_32 || V_83 -> V_36 ||
V_83 -> V_38 ) {
V_77 = F_18 ( V_78 , V_83 , V_85 ) ;
if ( V_77 )
return - V_24 ;
if ( F_32 ( V_85 ,
L_22 ,
& V_83 -> V_106 ) ) {
V_83 -> V_106 = 0 ;
} else {
if ( V_83 -> V_106 >= 8 ) {
V_83 -> V_106 = 0 ;
F_36 ( V_78 -> V_70 ,
L_23 ) ;
}
}
}
V_77 = F_21 ( V_78 , V_83 , V_85 ) ;
if ( V_77 )
return - V_24 ;
if ( F_34 ( V_85 , L_24 , NULL ) )
V_83 -> V_107 = true ;
if ( F_34 ( V_85 , L_25 , NULL ) )
V_83 -> V_108 = true ;
if ( F_34 ( V_85 , L_26 , NULL ) )
V_83 -> V_109 = true ;
if ( V_83 -> V_107 || V_83 -> V_108
|| V_83 -> V_109 ) {
if ( F_32 ( V_85 , L_27 ,
& V_83 -> V_110 ) )
V_83 -> V_110 = 0 ;
}
return 0 ;
}
static int F_23 ( struct V_89 * V_90 ,
struct V_82 * V_83 )
{
return 0 ;
}
static int F_37 ( struct V_89 * V_90 )
{
struct V_81 * V_78 = F_24 ( V_90 -> V_70 . V_91 ) ;
struct V_82 * V_83 = V_78 -> V_83 ;
struct V_66 V_67 = { } ;
struct V_50 * * V_51 ;
struct V_1 * V_2 ;
int V_6 , V_77 , V_111 , V_112 ;
if ( ! V_83 ) {
F_20 ( V_90 -> V_70 . V_91 , L_28 ) ;
return - V_96 ;
}
if ( V_78 -> V_70 -> V_95 ) {
V_77 = F_23 ( V_90 , V_83 ) ;
if ( V_77 )
return V_77 ;
}
if ( V_83 -> V_32 ) {
if ( V_83 -> V_36 || V_83 -> V_38 ) {
F_20 ( & V_90 -> V_70 , L_29 ) ;
return - V_24 ;
}
}
if ( V_83 -> V_36 ) {
if ( V_83 -> V_32 || V_83 -> V_38 ) {
F_20 ( & V_90 -> V_70 , L_29 ) ;
return - V_24 ;
}
}
if ( V_83 -> V_38 ) {
if ( V_83 -> V_32 || V_83 -> V_36 ) {
F_20 ( & V_90 -> V_70 , L_29 ) ;
return - V_24 ;
}
}
V_2 = F_27 ( & V_90 -> V_70 , sizeof( struct V_1 ) ,
V_97 ) ;
if ( ! V_2 )
return - V_98 ;
V_111 = sizeof( struct V_50 * ) * ( V_113 - 2 ) ;
V_2 -> V_51 = F_27 ( & V_90 -> V_70 , V_111 , V_97 ) ;
if ( ! V_2 -> V_51 )
return - V_98 ;
V_51 = V_2 -> V_51 ;
V_2 -> V_70 = & V_90 -> V_70 ;
V_2 -> V_78 = V_78 ;
V_2 -> V_25 = V_83 -> V_25 ;
F_38 ( V_90 , V_2 ) ;
V_2 -> V_33 = V_83 -> V_106 ;
V_2 -> V_32 = V_83 -> V_32 ;
V_2 -> V_36 = V_83 -> V_36 ;
V_2 -> V_38 = V_83 -> V_38 ;
V_2 -> V_49 [ 0 ] = V_83 -> V_49 [ 0 ] ;
V_2 -> V_49 [ 1 ] = V_83 -> V_49 [ 1 ] ;
V_2 -> V_49 [ 2 ] = V_83 -> V_49 [ 2 ] ;
V_2 -> V_87 [ 0 ] = V_83 -> V_87 [ 0 ] ;
V_2 -> V_87 [ 1 ] = V_83 -> V_87 [ 1 ] ;
V_2 -> V_87 [ 2 ] = V_83 -> V_87 [ 2 ] ;
V_2 -> V_63 = V_83 -> V_110 ;
V_2 -> V_114 = V_83 -> V_107 ;
V_2 -> V_115 = V_83 -> V_108 ;
V_2 -> V_116 = V_83 -> V_109 ;
V_2 -> V_26 = V_83 -> V_26 ;
V_112 = F_3 ( & V_117 ,
V_83 -> V_118 ) ;
F_39 ( V_2 -> V_78 -> V_79 , V_119 ,
V_112 ) ;
V_112 = F_3 ( & V_117 ,
V_83 -> V_120 ) ;
F_39 ( V_2 -> V_78 -> V_79 , V_121 ,
V_112 ) ;
V_112 = F_3 ( & V_117 ,
V_83 -> V_122 ) ;
F_39 ( V_2 -> V_78 -> V_79 , V_123 ,
V_112 ) ;
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
if ( V_2 -> V_32 ) {
V_2 -> V_55 [ V_6 ] =
F_3 (
& V_117 ,
V_83 -> V_103 [ V_6 ] ) ;
}
if ( V_2 -> V_36 ) {
V_2 -> V_56 [ V_6 ] =
F_3 (
& V_117 ,
V_83 -> V_104 [ V_6 ] ) ;
}
if ( V_2 -> V_38 ) {
V_2 -> V_57 [ V_6 ] =
F_3 (
& V_117 ,
V_83 -> V_105 [ V_6 ] ) ;
}
}
if ( V_83 -> V_32 || V_83 -> V_36 ||
V_83 -> V_38 ) {
if ( ! F_15 ( V_83 -> V_49 [ 0 ] ) ||
! F_15 ( V_83 -> V_49 [ 1 ] ) ||
! F_15 ( V_83 -> V_49 [ 2 ] ) ) {
F_20 ( & V_90 -> V_70 , L_30 ) ;
return - V_24 ;
}
V_77 = F_40 ( & V_90 -> V_70 , V_83 -> V_49 [ 0 ] ,
L_31 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_40 ( & V_90 -> V_70 , V_83 -> V_49 [ 1 ] ,
L_32 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_40 ( & V_90 -> V_70 , V_83 -> V_49 [ 2 ] ,
L_33 ) ;
if ( V_77 )
return V_77 ;
F_41 ( V_83 -> V_49 [ 0 ] ,
( V_2 -> V_33 >> 2 ) & 0x1 ) ;
F_41 ( V_83 -> V_49 [ 1 ] ,
( V_2 -> V_33 >> 1 ) & 0x1 ) ;
F_41 ( V_83 -> V_49 [ 2 ] ,
( V_2 -> V_33 >> 0 ) & 0x1 ) ;
}
V_77 = F_40 ( & V_90 -> V_70 , V_83 -> V_87 [ 0 ] , L_34 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_40 ( & V_90 -> V_70 , V_83 -> V_87 [ 1 ] , L_35 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_40 ( & V_90 -> V_70 , V_83 -> V_87 [ 2 ] , L_36 ) ;
if ( V_77 )
return V_77 ;
F_41 ( V_83 -> V_87 [ 0 ] , 0x0 ) ;
F_41 ( V_83 -> V_87 [ 1 ] , 0x0 ) ;
F_41 ( V_83 -> V_87 [ 2 ] , 0x0 ) ;
if ( V_83 -> V_32 || V_83 -> V_36 ||
V_83 -> V_38 ) {
F_17 ( V_2 -> V_78 -> V_79 ,
V_18 , 1 << 1 ,
( V_83 -> V_32 ) ? ( 1 << 1 ) : ( 0 << 1 ) ) ;
F_17 ( V_2 -> V_78 -> V_79 ,
V_124 , 1 << 1 ,
( V_83 -> V_36 ) ? ( 1 << 1 ) : ( 0 << 1 ) ) ;
F_17 ( V_2 -> V_78 -> V_79 ,
V_125 , 1 << 1 ,
( V_83 -> V_38 ) ? ( 1 << 1 ) : ( 0 << 1 ) ) ;
}
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ ) {
if ( V_2 -> V_32 ) {
F_39 ( V_2 -> V_78 -> V_79 ,
V_31 + V_6 ,
V_2 -> V_55 [ V_6 ] ) ;
}
if ( V_2 -> V_36 ) {
F_39 ( V_2 -> V_78 -> V_79 ,
V_35 + V_6 ,
V_2 -> V_56 [ V_6 ] ) ;
}
if ( V_2 -> V_38 ) {
F_39 ( V_2 -> V_78 -> V_79 ,
V_37 + V_6 ,
V_2 -> V_57 [ V_6 ] ) ;
}
}
if ( V_2 -> V_114 )
F_17 ( V_2 -> V_78 -> V_79 ,
V_126 , 0x08 , 0x08 ) ;
if ( V_2 -> V_115 )
F_17 ( V_2 -> V_78 -> V_79 ,
V_126 , 0x04 , 0x04 ) ;
if ( V_2 -> V_116 )
F_17 ( V_2 -> V_78 -> V_79 ,
V_126 , 0x02 , 0x02 ) ;
if ( V_2 -> V_114 || V_2 -> V_115
|| V_2 -> V_116 ) {
unsigned int V_127 ;
switch ( V_2 -> V_63 ) {
case 5 :
V_127 = V_128 ;
break;
case 10 :
V_127 = V_129 ;
break;
case 25 :
V_127 = V_130 ;
break;
case 50 :
V_127 = V_131 ;
break;
case 100 :
V_127 = V_132 ;
break;
default:
V_127 = V_129 ;
}
F_17 ( V_2 -> V_78 -> V_79 ,
V_126 ,
V_133 ,
V_127 << V_134 ) ;
}
for ( V_6 = 0 ; V_6 < V_83 -> V_25 ; V_6 ++ ) {
const struct V_41 * V_42 ;
int V_27 = V_83 -> V_99 [ V_6 ] . V_27 ;
int V_135 , V_136 ;
V_42 = V_62 [ V_27 ] ;
if ( V_42 ) {
V_99 [ V_27 ] . V_137 =
( V_42 -> V_45 - V_42 -> V_46 ) / V_42 -> V_47 + 1 ;
V_99 [ V_27 ] . V_138 = V_42 -> V_46 ;
V_99 [ V_27 ] . V_139 = V_42 -> V_47 ;
V_99 [ V_27 ] . V_140 =
F_2 ( V_27 , V_2 ) ;
if ( V_27 < V_14 )
V_99 [ V_27 ] . V_141 = 0x3f ;
else
V_99 [ V_27 ] . V_141 = 0xff ;
F_1 ( V_2 , V_27 , & V_135 ,
& V_136 ) ;
V_99 [ V_27 ] . V_135 = V_135 ;
V_99 [ V_27 ] . V_142 = V_80 ;
V_99 [ V_27 ] . V_136 = V_136 ;
}
V_67 . V_70 = V_2 -> V_70 ;
V_67 . V_143 = V_83 -> V_99 [ V_6 ] . V_100 ;
V_67 . V_144 = V_2 ;
V_67 . V_145 = V_78 -> V_79 ;
V_67 . V_95 = V_83 -> V_99 [ V_6 ] . V_71 ;
V_67 . V_74 = V_67 . V_75 = 0 ;
if ( V_83 -> V_99 [ V_6 ] . V_73 )
F_13 ( V_2 ,
& V_83 -> V_99 [ V_6 ] , & V_67 ) ;
V_51 [ V_6 ] = F_42 ( & V_90 -> V_70 , & V_99 [ V_27 ] ,
& V_67 ) ;
if ( F_43 ( V_51 [ V_6 ] ) ) {
V_77 = F_44 ( V_51 [ V_6 ] ) ;
F_20 ( V_2 -> V_70 , L_37 ,
V_27 ) ;
return V_77 ;
}
if ( V_83 -> V_99 [ V_6 ] . V_73 ) {
V_77 = F_16 ( V_2 , V_51 [ V_6 ] ) ;
if ( V_77 < 0 ) {
F_20 ( V_2 -> V_70 ,
L_38 ,
V_51 [ V_6 ] -> V_42 -> V_72 , V_77 ) ;
return V_77 ;
}
}
}
return 0 ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_146 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_146 ) ;
}
