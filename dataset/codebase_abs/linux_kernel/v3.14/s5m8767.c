static int F_1 ( struct V_1 * V_2 , int * V_3 ,
int * V_4 )
{
int V_5 , V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
switch ( V_6 ) {
case V_10 ... V_11 :
* V_3 = V_12 + ( V_6 - V_10 ) ;
break;
case V_13 ... V_14 :
* V_3 = V_15 + ( V_6 - V_13 ) ;
break;
case V_16 :
* V_3 = V_17 ;
break;
case V_18 ... V_19 :
* V_3 = V_20 + ( V_6 - V_18 ) * 9 ;
break;
case V_21 :
* V_3 = V_22 ;
break;
case V_23 ... V_24 :
* V_3 = V_25 + ( V_6 - V_23 ) * 2 ;
break;
default:
return - V_26 ;
}
for ( V_5 = 0 ; V_5 < V_9 -> V_27 ; V_5 ++ ) {
if ( V_9 -> V_28 [ V_5 ] . V_29 == V_6 ) {
V_7 = V_9 -> V_28 [ V_5 ] . V_7 ;
break;
}
}
if ( V_5 < V_9 -> V_27 )
* V_4 =
V_30 [ V_6 ] [ V_7 ] << V_31 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_32 , V_3 ;
int V_4 ;
unsigned int V_33 ;
V_32 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_32 == - V_26 )
return 1 ;
else if ( V_32 )
return V_32 ;
V_32 = F_5 ( V_9 -> V_34 -> V_35 , V_3 , & V_33 ) ;
if ( V_32 )
return V_32 ;
return ( V_33 & V_36 ) == V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_32 , V_3 ;
int V_4 ;
V_32 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_32 )
return V_32 ;
return F_7 ( V_9 -> V_34 -> V_35 , V_3 ,
V_36 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_32 , V_3 , V_4 ;
V_32 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_32 )
return V_32 ;
return F_7 ( V_9 -> V_34 -> V_35 , V_3 ,
V_36 , ~ V_36 ) ;
}
static int F_9 ( int V_6 , struct V_8 * V_9 )
{
int V_3 ;
switch ( V_6 ) {
case V_10 ... V_11 :
V_3 = V_12 + ( V_6 - V_10 ) ;
break;
case V_13 ... V_14 :
V_3 = V_15 + ( V_6 - V_13 ) ;
break;
case V_16 :
V_3 = V_37 ;
break;
case V_18 :
V_3 = V_38 ;
if ( V_9 -> V_39 )
V_3 += V_9 -> V_40 ;
break;
case V_41 :
V_3 = V_42 ;
if ( V_9 -> V_43 )
V_3 += V_9 -> V_40 ;
break;
case V_19 :
V_3 = V_44 ;
if ( V_9 -> V_45 )
V_3 += V_9 -> V_40 ;
break;
case V_21 :
V_3 = V_46 ;
break;
case V_23 ... V_24 :
V_3 = V_47 + ( V_6 - V_23 ) * 2 ;
break;
default:
return - V_26 ;
}
return V_3 ;
}
static int F_10 ( const struct V_48 * V_49 ,
int V_50 )
{
int V_51 = 0 ;
if ( V_49 == NULL )
return - V_26 ;
if ( V_50 > V_49 -> V_52 )
return - V_26 ;
if ( V_50 < V_49 -> V_53 )
V_50 = V_49 -> V_53 ;
V_51 = F_11 ( V_50 - V_49 -> V_53 , V_49 -> V_54 ) ;
if ( V_49 -> V_53 + V_49 -> V_54 * V_51 > V_49 -> V_52 )
return - V_26 ;
return V_51 ;
}
static inline int F_12 ( struct V_8 * V_9 )
{
int V_55 = V_9 -> V_40 ;
F_13 ( V_9 -> V_56 [ 0 ] , ( V_55 >> 2 ) & 0x1 ) ;
F_13 ( V_9 -> V_56 [ 1 ] , ( V_55 >> 1 ) & 0x1 ) ;
F_13 ( V_9 -> V_56 [ 2 ] , V_55 & 0x1 ) ;
return 0 ;
}
static inline int F_14 ( struct V_8 * V_9 )
{
int V_55 = V_9 -> V_40 ;
F_13 ( V_9 -> V_56 [ 2 ] , V_55 & 0x1 ) ;
F_13 ( V_9 -> V_56 [ 1 ] , ( V_55 >> 1 ) & 0x1 ) ;
F_13 ( V_9 -> V_56 [ 0 ] , ( V_55 >> 2 ) & 0x1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_51 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_6 = F_2 ( V_2 ) ;
int V_57 , V_58 = 0 ;
T_1 * V_59 = NULL ;
switch ( V_6 ) {
case V_10 ... V_14 :
break;
case V_16 ... V_23 :
if ( V_6 == V_18 && V_9 -> V_39 )
V_59 = & V_9 -> V_60 [ 0 ] ;
else if ( V_6 == V_41 && V_9 -> V_43 )
V_59 = & V_9 -> V_61 [ 0 ] ;
else if ( V_6 == V_19 && V_9 -> V_45 )
V_59 = & V_9 -> V_62 [ 0 ] ;
break;
case V_63 ... V_64 :
return - V_26 ;
case V_24 :
break;
default:
return - V_26 ;
}
if ( V_59 ) {
while ( * V_59 != V_51 ) {
V_59 ++ ;
V_58 ++ ;
}
V_57 = V_9 -> V_40 ;
V_9 -> V_40 = V_58 ;
if ( V_58 > V_57 )
return F_12 ( V_9 ) ;
else
return F_14 ( V_9 ) ;
} else {
return F_16 ( V_2 , V_51 ) ;
}
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_65 ,
unsigned int V_66 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
const struct V_48 * V_49 ;
int V_6 = F_2 ( V_2 ) ;
V_49 = V_67 [ V_6 ] ;
if ( ( V_65 < V_66 ) && V_9 -> V_68 )
return F_11 ( V_49 -> V_54 * ( V_66 - V_65 ) ,
V_9 -> V_68 * 1000 ) ;
return 0 ;
}
static int F_18 ( struct V_69 * V_34 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
int V_5 , V_74 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_74 = F_19 ( V_73 ,
L_1 , V_5 ) ;
if ( ! F_20 ( V_74 ) ) {
F_21 ( V_34 -> V_75 , L_2 , V_5 , V_74 ) ;
return - V_26 ;
}
V_71 -> V_56 [ V_5 ] = V_74 ;
}
return 0 ;
}
static int F_22 ( struct V_69 * V_34 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
int V_5 , V_74 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_74 = F_19 ( V_73 ,
L_3 , V_5 ) ;
if ( ! F_20 ( V_74 ) ) {
F_21 ( V_34 -> V_75 , L_2 , V_5 , V_74 ) ;
return - V_26 ;
}
V_71 -> V_76 [ V_5 ] = V_74 ;
}
return 0 ;
}
static int F_23 ( struct V_77 * V_78 ,
struct V_70 * V_71 )
{
struct V_69 * V_34 = F_24 ( V_78 -> V_75 . V_79 ) ;
struct V_72 * V_73 , * V_80 , * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
unsigned int V_5 , V_86 = 8 , V_32 ;
V_73 = V_34 -> V_75 -> V_87 ;
if ( ! V_73 ) {
F_21 ( V_34 -> V_75 , L_4 ) ;
return - V_88 ;
}
V_80 = F_25 ( V_73 , L_5 ) ;
if ( ! V_80 ) {
F_21 ( V_34 -> V_75 , L_6 ) ;
return - V_26 ;
}
V_71 -> V_27 = F_26 ( V_80 ) ;
V_83 = F_27 ( & V_78 -> V_75 , sizeof( * V_83 ) *
V_71 -> V_27 , V_89 ) ;
if ( ! V_83 ) {
F_21 ( V_34 -> V_75 ,
L_7 ) ;
return - V_90 ;
}
V_85 = F_27 ( & V_78 -> V_75 , sizeof( * V_85 ) *
V_71 -> V_27 , V_89 ) ;
if ( ! V_85 ) {
F_21 ( V_34 -> V_75 ,
L_8 ) ;
return - V_90 ;
}
V_71 -> V_91 = V_83 ;
V_71 -> V_28 = V_85 ;
F_28 (regulators_np, reg_np) {
for ( V_5 = 0 ; V_5 < F_29 ( V_91 ) ; V_5 ++ )
if ( ! F_30 ( V_81 -> V_92 , V_91 [ V_5 ] . V_92 ) )
break;
if ( V_5 == F_29 ( V_91 ) ) {
F_31 ( V_34 -> V_75 ,
L_9 ,
V_81 -> V_92 ) ;
continue;
}
V_83 -> V_29 = V_5 ;
V_83 -> V_93 = F_32 (
& V_78 -> V_75 , V_81 ) ;
V_83 -> V_94 = V_81 ;
V_83 ++ ;
V_85 -> V_29 = V_5 ;
if ( F_33 ( V_81 , L_10 ,
& V_85 -> V_7 ) ) {
F_31 ( V_34 -> V_75 ,
L_11 ,
V_81 -> V_95 ) ;
V_85 -> V_7 = V_96 ;
}
V_85 ++ ;
}
F_34 ( V_80 ) ;
if ( F_35 ( V_73 , L_12 , NULL ) ) {
V_71 -> V_39 = true ;
if ( F_36 ( V_73 ,
L_13 ,
V_71 -> V_97 , V_86 ) ) {
F_21 ( V_34 -> V_75 , L_14 ) ;
return - V_26 ;
}
}
if ( F_35 ( V_73 , L_15 , NULL ) ) {
V_71 -> V_43 = true ;
if ( F_36 ( V_73 ,
L_16 ,
V_71 -> V_98 , V_86 ) ) {
F_21 ( V_34 -> V_75 , L_17 ) ;
return - V_26 ;
}
}
if ( F_35 ( V_73 , L_18 , NULL ) ) {
V_71 -> V_45 = true ;
if ( F_36 ( V_73 ,
L_19 ,
V_71 -> V_99 , V_86 ) ) {
F_21 ( V_34 -> V_75 , L_20 ) ;
return - V_26 ;
}
}
if ( V_71 -> V_39 || V_71 -> V_43 ||
V_71 -> V_45 ) {
V_32 = F_18 ( V_34 , V_71 , V_73 ) ;
if ( V_32 )
return - V_26 ;
if ( F_33 ( V_73 ,
L_21 ,
& V_71 -> V_100 ) ) {
V_71 -> V_100 = 0 ;
} else {
if ( V_71 -> V_100 >= 8 ) {
V_71 -> V_100 = 0 ;
F_37 ( V_34 -> V_75 ,
L_22 ) ;
}
}
}
V_32 = F_22 ( V_34 , V_71 , V_73 ) ;
if ( V_32 )
return - V_26 ;
if ( F_35 ( V_73 , L_23 , NULL ) )
V_71 -> V_101 = true ;
if ( F_35 ( V_73 , L_24 , NULL ) )
V_71 -> V_102 = true ;
if ( F_35 ( V_73 , L_25 , NULL ) )
V_71 -> V_103 = true ;
if ( V_71 -> V_101 || V_71 -> V_102
|| V_71 -> V_103 ) {
if ( F_33 ( V_73 , L_26 ,
& V_71 -> V_104 ) )
V_71 -> V_104 = 0 ;
}
return 0 ;
}
static int F_23 ( struct V_77 * V_78 ,
struct V_70 * V_71 )
{
return 0 ;
}
static int F_38 ( struct V_77 * V_78 )
{
struct V_69 * V_34 = F_24 ( V_78 -> V_75 . V_79 ) ;
struct V_70 * V_71 = V_34 -> V_71 ;
struct V_105 V_106 = { } ;
struct V_1 * * V_2 ;
struct V_8 * V_9 ;
int V_5 , V_32 , V_107 , V_108 ;
if ( ! V_71 ) {
F_21 ( V_78 -> V_75 . V_79 , L_27 ) ;
return - V_88 ;
}
if ( V_34 -> V_75 -> V_87 ) {
V_32 = F_23 ( V_78 , V_71 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_71 -> V_39 ) {
if ( V_71 -> V_43 || V_71 -> V_45 ) {
F_21 ( & V_78 -> V_75 , L_28 ) ;
return - V_26 ;
}
}
if ( V_71 -> V_43 ) {
if ( V_71 -> V_39 || V_71 -> V_45 ) {
F_21 ( & V_78 -> V_75 , L_28 ) ;
return - V_26 ;
}
}
if ( V_71 -> V_45 ) {
if ( V_71 -> V_39 || V_71 -> V_43 ) {
F_21 ( & V_78 -> V_75 , L_28 ) ;
return - V_26 ;
}
}
V_9 = F_27 ( & V_78 -> V_75 , sizeof( struct V_8 ) ,
V_89 ) ;
if ( ! V_9 )
return - V_90 ;
V_107 = sizeof( struct V_1 * ) * ( V_109 - 2 ) ;
V_9 -> V_2 = F_27 ( & V_78 -> V_75 , V_107 , V_89 ) ;
if ( ! V_9 -> V_2 )
return - V_90 ;
V_2 = V_9 -> V_2 ;
V_9 -> V_75 = & V_78 -> V_75 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_27 = V_71 -> V_27 ;
F_39 ( V_78 , V_9 ) ;
V_9 -> V_40 = V_71 -> V_100 ;
V_9 -> V_39 = V_71 -> V_39 ;
V_9 -> V_43 = V_71 -> V_43 ;
V_9 -> V_45 = V_71 -> V_45 ;
V_9 -> V_56 [ 0 ] = V_71 -> V_56 [ 0 ] ;
V_9 -> V_56 [ 1 ] = V_71 -> V_56 [ 1 ] ;
V_9 -> V_56 [ 2 ] = V_71 -> V_56 [ 2 ] ;
V_9 -> V_76 [ 0 ] = V_71 -> V_76 [ 0 ] ;
V_9 -> V_76 [ 1 ] = V_71 -> V_76 [ 1 ] ;
V_9 -> V_76 [ 2 ] = V_71 -> V_76 [ 2 ] ;
V_9 -> V_68 = V_71 -> V_104 ;
V_9 -> V_110 = V_71 -> V_101 ;
V_9 -> V_111 = V_71 -> V_102 ;
V_9 -> V_112 = V_71 -> V_103 ;
V_9 -> V_28 = V_71 -> V_28 ;
V_108 = F_10 ( & V_113 ,
V_71 -> V_114 ) ;
F_40 ( V_9 -> V_34 -> V_35 , V_115 ,
V_108 ) ;
V_108 = F_10 ( & V_113 ,
V_71 -> V_116 ) ;
F_40 ( V_9 -> V_34 -> V_35 , V_117 ,
V_108 ) ;
V_108 = F_10 ( & V_113 ,
V_71 -> V_118 ) ;
F_40 ( V_9 -> V_34 -> V_35 , V_119 ,
V_108 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( V_9 -> V_39 ) {
V_9 -> V_60 [ V_5 ] =
F_10 (
& V_113 ,
V_71 -> V_97 [ V_5 ] ) ;
}
if ( V_9 -> V_43 ) {
V_9 -> V_61 [ V_5 ] =
F_10 (
& V_113 ,
V_71 -> V_98 [ V_5 ] ) ;
}
if ( V_9 -> V_45 ) {
V_9 -> V_62 [ V_5 ] =
F_10 (
& V_113 ,
V_71 -> V_99 [ V_5 ] ) ;
}
}
if ( V_71 -> V_39 || V_71 -> V_43 ||
V_71 -> V_45 ) {
if ( ! F_20 ( V_71 -> V_56 [ 0 ] ) ||
! F_20 ( V_71 -> V_56 [ 1 ] ) ||
! F_20 ( V_71 -> V_56 [ 2 ] ) ) {
F_21 ( & V_78 -> V_75 , L_29 ) ;
return - V_26 ;
}
V_32 = F_41 ( & V_78 -> V_75 , V_71 -> V_56 [ 0 ] ,
L_30 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_41 ( & V_78 -> V_75 , V_71 -> V_56 [ 1 ] ,
L_31 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_41 ( & V_78 -> V_75 , V_71 -> V_56 [ 2 ] ,
L_32 ) ;
if ( V_32 )
return V_32 ;
F_42 ( V_71 -> V_56 [ 0 ] ,
( V_9 -> V_40 >> 2 ) & 0x1 ) ;
F_42 ( V_71 -> V_56 [ 1 ] ,
( V_9 -> V_40 >> 1 ) & 0x1 ) ;
F_42 ( V_71 -> V_56 [ 2 ] ,
( V_9 -> V_40 >> 0 ) & 0x1 ) ;
}
V_32 = F_41 ( & V_78 -> V_75 , V_71 -> V_76 [ 0 ] , L_33 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_41 ( & V_78 -> V_75 , V_71 -> V_76 [ 1 ] , L_34 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_41 ( & V_78 -> V_75 , V_71 -> V_76 [ 2 ] , L_35 ) ;
if ( V_32 )
return V_32 ;
F_42 ( V_71 -> V_76 [ 0 ] , 0x0 ) ;
F_42 ( V_71 -> V_76 [ 1 ] , 0x0 ) ;
F_42 ( V_71 -> V_76 [ 2 ] , 0x0 ) ;
if ( V_71 -> V_39 || V_71 -> V_43 ||
V_71 -> V_45 ) {
F_7 ( V_9 -> V_34 -> V_35 ,
V_20 , 1 << 1 ,
( V_71 -> V_39 ) ? ( 1 << 1 ) : ( 0 << 1 ) ) ;
F_7 ( V_9 -> V_34 -> V_35 ,
V_120 , 1 << 1 ,
( V_71 -> V_43 ) ? ( 1 << 1 ) : ( 0 << 1 ) ) ;
F_7 ( V_9 -> V_34 -> V_35 ,
V_121 , 1 << 1 ,
( V_71 -> V_45 ) ? ( 1 << 1 ) : ( 0 << 1 ) ) ;
}
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( V_9 -> V_39 ) {
F_40 ( V_9 -> V_34 -> V_35 ,
V_38 + V_5 ,
V_9 -> V_60 [ V_5 ] ) ;
}
if ( V_9 -> V_43 ) {
F_40 ( V_9 -> V_34 -> V_35 ,
V_42 + V_5 ,
V_9 -> V_61 [ V_5 ] ) ;
}
if ( V_9 -> V_45 ) {
F_40 ( V_9 -> V_34 -> V_35 ,
V_44 + V_5 ,
V_9 -> V_62 [ V_5 ] ) ;
}
}
if ( V_9 -> V_110 )
F_7 ( V_9 -> V_34 -> V_35 ,
V_122 , 0x08 , 0x08 ) ;
if ( V_9 -> V_111 )
F_7 ( V_9 -> V_34 -> V_35 ,
V_122 , 0x04 , 0x04 ) ;
if ( V_9 -> V_112 )
F_7 ( V_9 -> V_34 -> V_35 ,
V_122 , 0x02 , 0x02 ) ;
if ( V_9 -> V_110 || V_9 -> V_111
|| V_9 -> V_112 ) {
unsigned int V_33 ;
switch ( V_9 -> V_68 ) {
case 5 :
V_33 = V_123 ;
break;
case 10 :
V_33 = V_124 ;
break;
case 25 :
V_33 = V_125 ;
break;
case 50 :
V_33 = V_126 ;
break;
case 100 :
V_33 = V_127 ;
break;
default:
V_33 = V_124 ;
}
F_7 ( V_9 -> V_34 -> V_35 ,
V_122 ,
V_128 ,
V_33 << V_129 ) ;
}
for ( V_5 = 0 ; V_5 < V_71 -> V_27 ; V_5 ++ ) {
const struct V_48 * V_49 ;
int V_29 = V_71 -> V_91 [ V_5 ] . V_29 ;
V_49 = V_67 [ V_29 ] ;
if ( V_49 ) {
V_91 [ V_29 ] . V_130 =
( V_49 -> V_52 - V_49 -> V_53 ) / V_49 -> V_54 + 1 ;
V_91 [ V_29 ] . V_131 = V_49 -> V_53 ;
V_91 [ V_29 ] . V_132 = V_49 -> V_54 ;
V_91 [ V_29 ] . V_133 =
F_9 ( V_29 , V_9 ) ;
if ( V_29 < V_16 )
V_91 [ V_29 ] . V_134 = 0x3f ;
else
V_91 [ V_29 ] . V_134 = 0xff ;
}
V_106 . V_75 = V_9 -> V_75 ;
V_106 . V_135 = V_71 -> V_91 [ V_5 ] . V_93 ;
V_106 . V_136 = V_9 ;
V_106 . V_137 = V_34 -> V_35 ;
V_106 . V_87 = V_71 -> V_91 [ V_5 ] . V_94 ;
V_2 [ V_5 ] = F_43 ( & V_78 -> V_75 , & V_91 [ V_29 ] ,
& V_106 ) ;
if ( F_44 ( V_2 [ V_5 ] ) ) {
V_32 = F_45 ( V_2 [ V_5 ] ) ;
F_21 ( V_9 -> V_75 , L_36 ,
V_29 ) ;
return V_32 ;
}
}
return 0 ;
}
static int T_2 F_46 ( void )
{
return F_47 ( & V_138 ) ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_138 ) ;
}
