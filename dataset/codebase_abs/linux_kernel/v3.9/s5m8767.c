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
int V_33 = 0xc0 , V_4 ;
unsigned int V_34 ;
V_32 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_32 == - V_26 )
return 1 ;
else if ( V_32 )
return V_32 ;
V_32 = F_5 ( V_9 -> V_35 , V_3 , & V_34 ) ;
if ( V_32 )
return V_32 ;
return ( V_34 & V_33 ) == V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_32 , V_3 ;
int V_33 = 0xc0 , V_4 ;
V_32 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_32 )
return V_32 ;
return F_7 ( V_9 -> V_35 , V_3 , V_4 , V_33 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_32 , V_3 ;
int V_33 = 0xc0 , V_4 ;
V_32 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_32 )
return V_32 ;
return F_7 ( V_9 -> V_35 , V_3 , ~ V_33 , V_33 ) ;
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
V_3 = V_36 ;
break;
case V_18 :
V_3 = V_37 ;
if ( V_9 -> V_38 )
V_3 += V_9 -> V_39 ;
break;
case V_40 :
V_3 = V_41 ;
if ( V_9 -> V_42 )
V_3 += V_9 -> V_39 ;
break;
case V_19 :
V_3 = V_43 ;
if ( V_9 -> V_44 )
V_3 += V_9 -> V_39 ;
break;
case V_21 :
V_3 = V_45 ;
break;
case V_23 ... V_24 :
V_3 = V_46 + ( V_6 - V_23 ) * 2 ;
break;
default:
return - V_26 ;
}
return V_3 ;
}
static int F_10 ( const struct V_47 * V_48 ,
int V_49 )
{
int V_50 = 0 ;
if ( V_48 == NULL )
return - V_26 ;
if ( V_49 > V_48 -> V_51 )
return - V_26 ;
if ( V_49 < V_48 -> V_52 )
V_49 = V_48 -> V_52 ;
V_50 = F_11 ( V_49 - V_48 -> V_52 , V_48 -> V_53 ) ;
if ( V_48 -> V_52 + V_48 -> V_53 * V_50 > V_48 -> V_51 )
return - V_26 ;
return V_50 ;
}
static inline int F_12 ( struct V_8 * V_9 )
{
int V_54 = V_9 -> V_39 ;
F_13 ( V_9 -> V_55 [ 0 ] , ( V_54 >> 2 ) & 0x1 ) ;
F_13 ( V_9 -> V_55 [ 1 ] , ( V_54 >> 1 ) & 0x1 ) ;
F_13 ( V_9 -> V_55 [ 2 ] , V_54 & 0x1 ) ;
return 0 ;
}
static inline int F_14 ( struct V_8 * V_9 )
{
int V_54 = V_9 -> V_39 ;
F_13 ( V_9 -> V_55 [ 2 ] , V_54 & 0x1 ) ;
F_13 ( V_9 -> V_55 [ 1 ] , ( V_54 >> 1 ) & 0x1 ) ;
F_13 ( V_9 -> V_55 [ 0 ] , ( V_54 >> 2 ) & 0x1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_50 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_6 = F_2 ( V_2 ) ;
int V_56 , V_57 = 0 ;
T_1 * V_58 = NULL ;
switch ( V_6 ) {
case V_10 ... V_14 :
break;
case V_16 ... V_23 :
if ( V_6 == V_18 && V_9 -> V_38 )
V_58 = & V_9 -> V_59 [ 0 ] ;
else if ( V_6 == V_40 && V_9 -> V_42 )
V_58 = & V_9 -> V_60 [ 0 ] ;
else if ( V_6 == V_19 && V_9 -> V_44 )
V_58 = & V_9 -> V_61 [ 0 ] ;
break;
case V_62 ... V_63 :
return - V_26 ;
case V_24 :
break;
default:
return - V_26 ;
}
if ( V_58 ) {
while ( * V_58 != V_50 ) {
V_58 ++ ;
V_57 ++ ;
}
V_56 = V_9 -> V_39 ;
V_9 -> V_39 = V_57 ;
if ( V_57 > V_56 )
return F_12 ( V_9 ) ;
else
return F_14 ( V_9 ) ;
} else {
return F_16 ( V_2 , V_50 ) ;
}
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_64 ,
unsigned int V_65 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
const struct V_47 * V_48 ;
int V_6 = F_2 ( V_2 ) ;
V_48 = V_66 [ V_6 ] ;
if ( ( V_64 < V_65 ) && V_9 -> V_67 )
return F_11 ( V_48 -> V_53 * ( V_65 - V_64 ) ,
V_9 -> V_67 * 1000 ) ;
return 0 ;
}
static int F_18 ( struct V_68 * V_35 ,
struct V_69 * V_70 ,
struct V_71 * V_72 )
{
int V_5 , V_73 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_73 = F_19 ( V_72 ,
L_1 , V_5 ) ;
if ( ! F_20 ( V_73 ) ) {
F_21 ( V_35 -> V_74 , L_2 , V_5 , V_73 ) ;
return - V_26 ;
}
V_70 -> V_55 [ V_5 ] = V_73 ;
}
return 0 ;
}
static int F_22 ( struct V_68 * V_35 ,
struct V_69 * V_70 ,
struct V_71 * V_72 )
{
int V_5 , V_73 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_73 = F_19 ( V_72 ,
L_3 , V_5 ) ;
if ( ! F_20 ( V_73 ) ) {
F_21 ( V_35 -> V_74 , L_2 , V_5 , V_73 ) ;
return - V_26 ;
}
V_70 -> V_75 [ V_5 ] = V_73 ;
}
return 0 ;
}
static int F_23 ( struct V_76 * V_77 ,
struct V_69 * V_70 )
{
struct V_68 * V_35 = F_24 ( V_77 -> V_74 . V_78 ) ;
struct V_71 * V_72 , * V_79 , * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
unsigned int V_5 , V_85 = 1 , V_32 ;
V_72 = V_35 -> V_74 -> V_86 ;
if ( ! V_72 ) {
F_21 ( V_35 -> V_74 , L_4 ) ;
return - V_87 ;
}
V_79 = F_25 ( V_72 , L_5 ) ;
if ( ! V_79 ) {
F_21 ( V_35 -> V_74 , L_6 ) ;
return - V_26 ;
}
V_70 -> V_27 = F_26 ( V_79 ) ;
V_82 = F_27 ( & V_77 -> V_74 , sizeof( * V_82 ) *
V_70 -> V_27 , V_88 ) ;
if ( ! V_82 ) {
F_21 ( V_35 -> V_74 ,
L_7 ) ;
return - V_89 ;
}
V_84 = F_27 ( & V_77 -> V_74 , sizeof( * V_84 ) *
V_70 -> V_27 , V_88 ) ;
if ( ! V_82 ) {
F_21 ( V_35 -> V_74 ,
L_8 ) ;
return - V_89 ;
}
V_70 -> V_90 = V_82 ;
V_70 -> V_28 = V_84 ;
F_28 (regulators_np, reg_np) {
for ( V_5 = 0 ; V_5 < F_29 ( V_90 ) ; V_5 ++ )
if ( ! F_30 ( V_80 -> V_91 , V_90 [ V_5 ] . V_91 ) )
break;
if ( V_5 == F_29 ( V_90 ) ) {
F_31 ( V_35 -> V_74 ,
L_9 ,
V_80 -> V_91 ) ;
continue;
}
V_82 -> V_29 = V_5 ;
V_82 -> V_92 = F_32 (
& V_77 -> V_74 , V_80 ) ;
V_82 -> V_93 = V_80 ;
V_82 ++ ;
V_84 -> V_29 = V_5 ;
if ( F_33 ( V_80 , L_10 ,
& V_84 -> V_7 ) ) {
F_31 ( V_35 -> V_74 ,
L_11 ,
V_80 -> V_94 ) ;
V_84 -> V_7 = V_95 ;
}
V_84 ++ ;
}
if ( F_34 ( V_72 , L_12 , NULL ) )
V_70 -> V_38 = true ;
if ( F_34 ( V_72 , L_13 , NULL ) )
V_70 -> V_42 = true ;
if ( F_34 ( V_72 , L_14 , NULL ) )
V_70 -> V_44 = true ;
if ( V_70 -> V_38 || V_70 -> V_42 ||
V_70 -> V_44 ) {
V_32 = F_18 ( V_35 , V_70 , V_72 ) ;
if ( V_32 )
return - V_26 ;
if ( F_33 ( V_72 ,
L_15 ,
& V_70 -> V_96 ) ) {
V_70 -> V_96 = 0 ;
} else {
if ( V_70 -> V_96 >= 8 ) {
V_70 -> V_96 = 0 ;
F_35 ( V_35 -> V_74 ,
L_16 ) ;
}
}
V_85 = 8 ;
}
V_32 = F_22 ( V_35 , V_70 , V_72 ) ;
if ( V_32 )
return - V_26 ;
if ( F_36 ( V_72 ,
L_17 ,
V_70 -> V_97 , V_85 ) ) {
F_21 ( V_35 -> V_74 , L_18 ) ;
return - V_26 ;
}
if ( F_36 ( V_72 ,
L_19 ,
V_70 -> V_98 , V_85 ) ) {
F_21 ( V_35 -> V_74 , L_20 ) ;
return - V_26 ;
}
if ( F_36 ( V_72 ,
L_21 ,
V_70 -> V_99 , V_85 ) ) {
F_21 ( V_35 -> V_74 , L_22 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_23 ( struct V_76 * V_77 ,
struct V_69 * V_70 )
{
return 0 ;
}
static int F_37 ( struct V_76 * V_77 )
{
struct V_68 * V_35 = F_24 ( V_77 -> V_74 . V_78 ) ;
struct V_69 * V_70 = V_35 -> V_70 ;
struct V_100 V_101 = { } ;
struct V_1 * * V_2 ;
struct V_8 * V_9 ;
int V_5 , V_32 , V_102 , V_103 ;
if ( ! V_70 ) {
F_21 ( V_77 -> V_74 . V_78 , L_23 ) ;
return - V_87 ;
}
if ( V_35 -> V_74 -> V_86 ) {
V_32 = F_23 ( V_77 , V_70 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_70 -> V_38 ) {
if ( V_70 -> V_42 || V_70 -> V_44 ) {
F_21 ( & V_77 -> V_74 , L_24 ) ;
return - V_26 ;
}
}
if ( V_70 -> V_42 ) {
if ( V_70 -> V_38 || V_70 -> V_44 ) {
F_21 ( & V_77 -> V_74 , L_24 ) ;
return - V_26 ;
}
}
if ( V_70 -> V_44 ) {
if ( V_70 -> V_38 || V_70 -> V_42 ) {
F_21 ( & V_77 -> V_74 , L_24 ) ;
return - V_26 ;
}
}
V_9 = F_27 ( & V_77 -> V_74 , sizeof( struct V_8 ) ,
V_88 ) ;
if ( ! V_9 )
return - V_89 ;
V_102 = sizeof( struct V_1 * ) * ( V_104 - 2 ) ;
V_9 -> V_2 = F_27 ( & V_77 -> V_74 , V_102 , V_88 ) ;
if ( ! V_9 -> V_2 )
return - V_89 ;
V_2 = V_9 -> V_2 ;
V_9 -> V_74 = & V_77 -> V_74 ;
V_9 -> V_35 = V_35 ;
V_9 -> V_27 = V_70 -> V_27 ;
F_38 ( V_77 , V_9 ) ;
V_9 -> V_39 = V_70 -> V_96 ;
V_9 -> V_38 = V_70 -> V_38 ;
V_9 -> V_42 = V_70 -> V_42 ;
V_9 -> V_44 = V_70 -> V_44 ;
V_9 -> V_55 [ 0 ] = V_70 -> V_55 [ 0 ] ;
V_9 -> V_55 [ 1 ] = V_70 -> V_55 [ 1 ] ;
V_9 -> V_55 [ 2 ] = V_70 -> V_55 [ 2 ] ;
V_9 -> V_75 [ 0 ] = V_70 -> V_75 [ 0 ] ;
V_9 -> V_75 [ 1 ] = V_70 -> V_75 [ 1 ] ;
V_9 -> V_75 [ 2 ] = V_70 -> V_75 [ 2 ] ;
V_9 -> V_67 = V_70 -> V_105 ;
V_9 -> V_106 = V_70 -> V_107 ;
V_9 -> V_108 = V_70 -> V_109 ;
V_9 -> V_110 = V_70 -> V_111 ;
V_9 -> V_28 = V_70 -> V_28 ;
V_103 = F_10 ( & V_112 ,
V_70 -> V_113 ) ;
F_39 ( V_9 -> V_35 , V_114 , V_103 ) ;
V_103 = F_10 ( & V_112 ,
V_70 -> V_115 ) ;
F_39 ( V_9 -> V_35 , V_116 , V_103 ) ;
V_103 = F_10 ( & V_112 ,
V_70 -> V_117 ) ;
F_39 ( V_9 -> V_35 , V_118 , V_103 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( V_9 -> V_38 ) {
V_9 -> V_59 [ V_5 ] =
F_10 (
& V_112 ,
V_70 -> V_97 [ V_5 ] ) ;
}
if ( V_9 -> V_42 ) {
V_9 -> V_60 [ V_5 ] =
F_10 (
& V_112 ,
V_70 -> V_98 [ V_5 ] ) ;
}
if ( V_9 -> V_44 ) {
V_9 -> V_61 [ V_5 ] =
F_10 (
& V_112 ,
V_70 -> V_99 [ V_5 ] ) ;
}
}
if ( V_70 -> V_38 || V_70 -> V_42 ||
V_70 -> V_44 ) {
if ( ! F_20 ( V_70 -> V_55 [ 0 ] ) ||
! F_20 ( V_70 -> V_55 [ 1 ] ) ||
! F_20 ( V_70 -> V_55 [ 2 ] ) ) {
F_21 ( & V_77 -> V_74 , L_25 ) ;
return - V_26 ;
}
V_32 = F_40 ( & V_77 -> V_74 , V_70 -> V_55 [ 0 ] ,
L_26 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_40 ( & V_77 -> V_74 , V_70 -> V_55 [ 1 ] ,
L_27 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_40 ( & V_77 -> V_74 , V_70 -> V_55 [ 2 ] ,
L_28 ) ;
if ( V_32 )
return V_32 ;
F_41 ( V_70 -> V_55 [ 0 ] ,
( V_9 -> V_39 >> 2 ) & 0x1 ) ;
F_41 ( V_70 -> V_55 [ 1 ] ,
( V_9 -> V_39 >> 1 ) & 0x1 ) ;
F_41 ( V_70 -> V_55 [ 2 ] ,
( V_9 -> V_39 >> 0 ) & 0x1 ) ;
}
V_32 = F_40 ( & V_77 -> V_74 , V_70 -> V_75 [ 0 ] , L_29 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_40 ( & V_77 -> V_74 , V_70 -> V_75 [ 1 ] , L_30 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_40 ( & V_77 -> V_74 , V_70 -> V_75 [ 2 ] , L_31 ) ;
if ( V_32 )
return V_32 ;
F_41 ( V_70 -> V_75 [ 0 ] , 0x0 ) ;
F_41 ( V_70 -> V_75 [ 1 ] , 0x0 ) ;
F_41 ( V_70 -> V_75 [ 2 ] , 0x0 ) ;
if ( V_70 -> V_38 || V_70 -> V_42 ||
V_70 -> V_44 ) {
F_7 ( V_9 -> V_35 , V_20 ,
( V_70 -> V_38 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
F_7 ( V_9 -> V_35 , V_119 ,
( V_70 -> V_42 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
F_7 ( V_9 -> V_35 , V_120 ,
( V_70 -> V_44 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
}
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( V_9 -> V_38 ) {
F_39 ( V_9 -> V_35 , V_37 + V_5 ,
V_9 -> V_59 [ V_5 ] ) ;
}
if ( V_9 -> V_42 ) {
F_39 ( V_9 -> V_35 , V_41 + V_5 ,
V_9 -> V_60 [ V_5 ] ) ;
}
if ( V_9 -> V_44 ) {
F_39 ( V_9 -> V_35 , V_43 + V_5 ,
V_9 -> V_61 [ V_5 ] ) ;
}
}
if ( V_9 -> V_106 )
F_7 ( V_9 -> V_35 , V_121 , 0x08 , 0x08 ) ;
if ( V_9 -> V_108 )
F_7 ( V_9 -> V_35 , V_121 , 0x04 , 0x04 ) ;
if ( V_9 -> V_110 )
F_7 ( V_9 -> V_35 , V_121 , 0x02 , 0x02 ) ;
if ( V_9 -> V_106 || V_9 -> V_108
|| V_9 -> V_110 ) {
switch ( V_9 -> V_67 ) {
case 5 :
F_7 ( V_9 -> V_35 , V_121 ,
0x40 , 0xf0 ) ;
break;
case 10 :
F_7 ( V_9 -> V_35 , V_121 ,
0x90 , 0xf0 ) ;
break;
case 25 :
F_7 ( V_9 -> V_35 , V_121 ,
0xd0 , 0xf0 ) ;
break;
case 50 :
F_7 ( V_9 -> V_35 , V_121 ,
0xe0 , 0xf0 ) ;
break;
case 100 :
F_7 ( V_9 -> V_35 , V_121 ,
0xf0 , 0xf0 ) ;
break;
default:
F_7 ( V_9 -> V_35 , V_121 ,
0x90 , 0xf0 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_70 -> V_27 ; V_5 ++ ) {
const struct V_47 * V_48 ;
int V_29 = V_70 -> V_90 [ V_5 ] . V_29 ;
V_48 = V_66 [ V_29 ] ;
if ( V_48 ) {
V_90 [ V_29 ] . V_122 =
( V_48 -> V_51 - V_48 -> V_52 ) / V_48 -> V_53 + 1 ;
V_90 [ V_29 ] . V_123 = V_48 -> V_52 ;
V_90 [ V_29 ] . V_124 = V_48 -> V_53 ;
V_90 [ V_29 ] . V_125 =
F_9 ( V_29 , V_9 ) ;
if ( V_29 < V_16 )
V_90 [ V_29 ] . V_126 = 0x3f ;
else
V_90 [ V_29 ] . V_126 = 0xff ;
}
V_101 . V_74 = V_9 -> V_74 ;
V_101 . V_127 = V_70 -> V_90 [ V_5 ] . V_92 ;
V_101 . V_128 = V_9 ;
V_101 . V_129 = V_35 -> V_129 ;
V_101 . V_86 = V_70 -> V_90 [ V_5 ] . V_93 ;
V_2 [ V_5 ] = F_42 ( & V_90 [ V_29 ] , & V_101 ) ;
if ( F_43 ( V_2 [ V_5 ] ) ) {
V_32 = F_44 ( V_2 [ V_5 ] ) ;
F_21 ( V_9 -> V_74 , L_32 ,
V_29 ) ;
V_2 [ V_5 ] = NULL ;
goto V_130;
}
}
return 0 ;
V_130:
for ( V_5 = 0 ; V_5 < V_9 -> V_27 ; V_5 ++ )
if ( V_2 [ V_5 ] )
F_45 ( V_2 [ V_5 ] ) ;
return V_32 ;
}
static int F_46 ( struct V_76 * V_77 )
{
struct V_8 * V_9 = F_47 ( V_77 ) ;
struct V_1 * * V_2 = V_9 -> V_2 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_9 -> V_27 ; V_5 ++ )
if ( V_2 [ V_5 ] )
F_45 ( V_2 [ V_5 ] ) ;
return 0 ;
}
static int T_2 F_48 ( void )
{
return F_49 ( & V_131 ) ;
}
static void T_3 F_50 ( void )
{
F_51 ( & V_131 ) ;
}
