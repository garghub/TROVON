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
static int F_9 ( struct V_1 * V_2 , int * V_36 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_6 = F_2 ( V_2 ) ;
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
* V_36 = V_3 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_3 , V_33 , V_32 ;
int V_6 = F_2 ( V_2 ) ;
unsigned int V_34 ;
V_32 = F_9 ( V_2 , & V_3 ) ;
if ( V_32 )
return V_32 ;
V_33 = ( V_6 < V_16 ) ? 0x3f : 0xff ;
V_32 = F_5 ( V_9 -> V_35 , V_3 , & V_34 ) ;
if ( V_32 )
return V_32 ;
V_34 &= V_33 ;
return V_34 ;
}
static int F_11 (
const struct V_48 * V_49 ,
int V_50 , int V_51 )
{
int V_52 = 0 ;
if ( V_49 == NULL )
return - V_26 ;
if ( V_51 < V_49 -> V_53 || V_50 > V_49 -> V_54 )
return - V_26 ;
if ( V_50 < V_49 -> V_53 )
V_50 = V_49 -> V_53 ;
V_52 = F_12 ( V_50 - V_49 -> V_53 , V_49 -> V_55 ) ;
if ( V_49 -> V_53 + V_49 -> V_55 * V_52 > V_51 )
return - V_26 ;
return V_52 ;
}
static inline int F_13 ( struct V_8 * V_9 )
{
int V_56 = V_9 -> V_40 ;
F_14 ( V_9 -> V_57 [ 0 ] , ( V_56 >> 2 ) & 0x1 ) ;
F_14 ( V_9 -> V_57 [ 1 ] , ( V_56 >> 1 ) & 0x1 ) ;
F_14 ( V_9 -> V_57 [ 2 ] , V_56 & 0x1 ) ;
return 0 ;
}
static inline int F_15 ( struct V_8 * V_9 )
{
int V_56 = V_9 -> V_40 ;
F_14 ( V_9 -> V_57 [ 2 ] , V_56 & 0x1 ) ;
F_14 ( V_9 -> V_57 [ 1 ] , ( V_56 >> 1 ) & 0x1 ) ;
F_14 ( V_9 -> V_57 [ 0 ] , ( V_56 >> 2 ) & 0x1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_52 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_6 = F_2 ( V_2 ) ;
int V_3 , V_33 , V_32 = 0 , V_58 , V_59 = 0 ;
T_1 * V_60 = NULL ;
switch ( V_6 ) {
case V_10 ... V_14 :
V_33 = 0x3f ;
break;
case V_16 ... V_23 :
V_33 = 0xff ;
if ( V_6 == V_18 && V_9 -> V_39 )
V_60 = & V_9 -> V_61 [ 0 ] ;
else if ( V_6 == V_41 && V_9 -> V_43 )
V_60 = & V_9 -> V_62 [ 0 ] ;
else if ( V_6 == V_19 && V_9 -> V_45 )
V_60 = & V_9 -> V_63 [ 0 ] ;
break;
case V_64 ... V_65 :
return - V_26 ;
case V_24 :
V_33 = 0xff ;
break;
default:
return - V_26 ;
}
if ( V_60 ) {
while ( * V_60 != V_52 ) {
V_60 ++ ;
V_59 ++ ;
}
V_58 = V_9 -> V_40 ;
V_9 -> V_40 = V_59 ;
if ( V_59 > V_58 )
return F_13 ( V_9 ) ;
else
return F_15 ( V_9 ) ;
} else {
V_32 = F_9 ( V_2 , & V_3 ) ;
if ( V_32 )
return V_32 ;
return F_7 ( V_9 -> V_35 , V_3 , V_52 , V_33 ) ;
}
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_66 ,
unsigned int V_67 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
const struct V_48 * V_49 ;
int V_6 = F_2 ( V_2 ) ;
V_49 = V_68 [ V_6 ] ;
if ( ( V_66 < V_67 ) && V_9 -> V_69 )
return F_12 ( V_49 -> V_55 * ( V_67 - V_66 ) ,
V_9 -> V_69 * 1000 ) ;
return 0 ;
}
static int F_18 ( struct V_70 * V_71 )
{
struct V_72 * V_35 = F_19 ( V_71 -> V_73 . V_74 ) ;
struct V_75 * V_76 = F_20 ( V_35 -> V_73 ) ;
struct V_77 V_78 = { } ;
struct V_1 * * V_2 ;
struct V_8 * V_9 ;
int V_5 , V_32 , V_79 , V_80 ;
if ( ! V_76 ) {
F_21 ( V_71 -> V_73 . V_74 , L_1 ) ;
return - V_81 ;
}
if ( V_76 -> V_39 ) {
if ( V_76 -> V_43 || V_76 -> V_45 ) {
F_21 ( & V_71 -> V_73 , L_2 ) ;
return - V_26 ;
}
}
if ( V_76 -> V_43 ) {
if ( V_76 -> V_39 || V_76 -> V_45 ) {
F_21 ( & V_71 -> V_73 , L_2 ) ;
return - V_26 ;
}
}
if ( V_76 -> V_45 ) {
if ( V_76 -> V_39 || V_76 -> V_43 ) {
F_21 ( & V_71 -> V_73 , L_2 ) ;
return - V_26 ;
}
}
V_9 = F_22 ( & V_71 -> V_73 , sizeof( struct V_8 ) ,
V_82 ) ;
if ( ! V_9 )
return - V_83 ;
V_79 = sizeof( struct V_1 * ) * ( V_84 - 2 ) ;
V_9 -> V_2 = F_22 ( & V_71 -> V_73 , V_79 , V_82 ) ;
if ( ! V_9 -> V_2 )
return - V_83 ;
V_2 = V_9 -> V_2 ;
V_9 -> V_73 = & V_71 -> V_73 ;
V_9 -> V_35 = V_35 ;
V_9 -> V_27 = V_76 -> V_27 ;
F_23 ( V_71 , V_9 ) ;
V_9 -> V_40 = V_76 -> V_85 ;
V_9 -> V_39 = V_76 -> V_39 ;
V_9 -> V_43 = V_76 -> V_43 ;
V_9 -> V_45 = V_76 -> V_45 ;
V_9 -> V_57 [ 0 ] = V_76 -> V_57 [ 0 ] ;
V_9 -> V_57 [ 1 ] = V_76 -> V_57 [ 1 ] ;
V_9 -> V_57 [ 2 ] = V_76 -> V_57 [ 2 ] ;
V_9 -> V_86 [ 0 ] = V_76 -> V_86 [ 0 ] ;
V_9 -> V_86 [ 1 ] = V_76 -> V_86 [ 1 ] ;
V_9 -> V_86 [ 2 ] = V_76 -> V_86 [ 2 ] ;
V_9 -> V_69 = V_76 -> V_87 ;
V_9 -> V_88 = V_76 -> V_89 ;
V_9 -> V_90 = V_76 -> V_91 ;
V_9 -> V_92 = V_76 -> V_93 ;
V_9 -> V_28 = V_76 -> V_28 ;
V_80 = F_11 ( & V_94 ,
V_76 -> V_95 ,
V_76 -> V_95 +
V_94 . V_55 ) ;
F_24 ( V_9 -> V_35 , V_96 , V_80 ) ;
V_80 = F_11 ( & V_94 ,
V_76 -> V_97 ,
V_76 -> V_97 +
V_94 . V_55 ) ;
F_24 ( V_9 -> V_35 , V_98 , V_80 ) ;
V_80 = F_11 ( & V_94 ,
V_76 -> V_99 ,
V_76 -> V_99 +
V_94 . V_55 ) ;
F_24 ( V_9 -> V_35 , V_100 , V_80 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( V_9 -> V_39 ) {
V_9 -> V_61 [ V_5 ] =
F_11 (
& V_94 ,
V_76 -> V_101 [ V_5 ] ,
V_76 -> V_101 [ V_5 ] +
V_94 . V_55 ) ;
}
if ( V_9 -> V_43 ) {
V_9 -> V_62 [ V_5 ] =
F_11 (
& V_94 ,
V_76 -> V_102 [ V_5 ] ,
V_76 -> V_102 [ V_5 ] +
V_94 . V_55 ) ;
}
if ( V_9 -> V_45 ) {
V_9 -> V_63 [ V_5 ] =
F_11 (
& V_94 ,
V_76 -> V_103 [ V_5 ] ,
V_76 -> V_103 [ V_5 ] +
V_94 . V_55 ) ;
}
}
if ( V_76 -> V_39 || V_76 -> V_43 ||
V_76 -> V_45 ) {
if ( ! F_25 ( V_76 -> V_57 [ 0 ] ) ||
! F_25 ( V_76 -> V_57 [ 1 ] ) ||
! F_25 ( V_76 -> V_57 [ 2 ] ) ) {
F_21 ( & V_71 -> V_73 , L_3 ) ;
return - V_26 ;
}
V_32 = F_26 ( & V_71 -> V_73 , V_76 -> V_57 [ 0 ] ,
L_4 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_26 ( & V_71 -> V_73 , V_76 -> V_57 [ 1 ] ,
L_5 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_26 ( & V_71 -> V_73 , V_76 -> V_57 [ 2 ] ,
L_6 ) ;
if ( V_32 )
return V_32 ;
F_27 ( V_76 -> V_57 [ 0 ] ,
( V_9 -> V_40 >> 2 ) & 0x1 ) ;
F_27 ( V_76 -> V_57 [ 1 ] ,
( V_9 -> V_40 >> 1 ) & 0x1 ) ;
F_27 ( V_76 -> V_57 [ 2 ] ,
( V_9 -> V_40 >> 0 ) & 0x1 ) ;
}
V_32 = F_26 ( & V_71 -> V_73 , V_76 -> V_86 [ 0 ] , L_7 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_26 ( & V_71 -> V_73 , V_76 -> V_86 [ 1 ] , L_8 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_26 ( & V_71 -> V_73 , V_76 -> V_86 [ 2 ] , L_9 ) ;
if ( V_32 )
return V_32 ;
F_27 ( V_76 -> V_86 [ 0 ] , 0x0 ) ;
F_27 ( V_76 -> V_86 [ 1 ] , 0x0 ) ;
F_27 ( V_76 -> V_86 [ 2 ] , 0x0 ) ;
if ( V_76 -> V_39 || V_76 -> V_43 ||
V_76 -> V_45 ) {
F_7 ( V_9 -> V_35 , V_20 ,
( V_76 -> V_39 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
F_7 ( V_9 -> V_35 , V_104 ,
( V_76 -> V_43 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
F_7 ( V_9 -> V_35 , V_105 ,
( V_76 -> V_45 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
}
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
if ( V_9 -> V_39 ) {
F_24 ( V_9 -> V_35 , V_38 + V_5 ,
V_9 -> V_61 [ V_5 ] ) ;
}
if ( V_9 -> V_43 ) {
F_24 ( V_9 -> V_35 , V_42 + V_5 ,
V_9 -> V_62 [ V_5 ] ) ;
}
if ( V_9 -> V_45 ) {
F_24 ( V_9 -> V_35 , V_44 + V_5 ,
V_9 -> V_63 [ V_5 ] ) ;
}
}
if ( V_9 -> V_88 )
F_7 ( V_9 -> V_35 , V_106 , 0x08 , 0x08 ) ;
if ( V_9 -> V_90 )
F_7 ( V_9 -> V_35 , V_106 , 0x04 , 0x04 ) ;
if ( V_9 -> V_92 )
F_7 ( V_9 -> V_35 , V_106 , 0x02 , 0x02 ) ;
if ( V_9 -> V_88 || V_9 -> V_90
|| V_9 -> V_92 ) {
switch ( V_9 -> V_69 ) {
case 5 :
F_7 ( V_9 -> V_35 , V_106 ,
0x40 , 0xf0 ) ;
break;
case 10 :
F_7 ( V_9 -> V_35 , V_106 ,
0x90 , 0xf0 ) ;
break;
case 25 :
F_7 ( V_9 -> V_35 , V_106 ,
0xd0 , 0xf0 ) ;
break;
case 50 :
F_7 ( V_9 -> V_35 , V_106 ,
0xe0 , 0xf0 ) ;
break;
case 100 :
F_7 ( V_9 -> V_35 , V_106 ,
0xf0 , 0xf0 ) ;
break;
default:
F_7 ( V_9 -> V_35 , V_106 ,
0x90 , 0xf0 ) ;
}
}
for ( V_5 = 0 ; V_5 < V_76 -> V_27 ; V_5 ++ ) {
const struct V_48 * V_49 ;
int V_29 = V_76 -> V_107 [ V_5 ] . V_29 ;
V_49 = V_68 [ V_29 ] ;
if ( V_49 ) {
V_107 [ V_29 ] . V_108 =
( V_49 -> V_54 - V_49 -> V_53 ) / V_49 -> V_55 + 1 ;
V_107 [ V_29 ] . V_109 = V_49 -> V_53 ;
V_107 [ V_29 ] . V_110 = V_49 -> V_55 ;
}
V_78 . V_73 = V_9 -> V_73 ;
V_78 . V_111 = V_76 -> V_107 [ V_5 ] . V_112 ;
V_78 . V_113 = V_9 ;
V_2 [ V_5 ] = F_28 ( & V_107 [ V_29 ] , & V_78 ) ;
if ( F_29 ( V_2 [ V_5 ] ) ) {
V_32 = F_30 ( V_2 [ V_5 ] ) ;
F_21 ( V_9 -> V_73 , L_10 ,
V_29 ) ;
V_2 [ V_5 ] = NULL ;
goto V_114;
}
}
return 0 ;
V_114:
for ( V_5 = 0 ; V_5 < V_9 -> V_27 ; V_5 ++ )
if ( V_2 [ V_5 ] )
F_31 ( V_2 [ V_5 ] ) ;
return V_32 ;
}
static int F_32 ( struct V_70 * V_71 )
{
struct V_8 * V_9 = F_33 ( V_71 ) ;
struct V_1 * * V_2 = V_9 -> V_2 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_9 -> V_27 ; V_5 ++ )
if ( V_2 [ V_5 ] )
F_31 ( V_2 [ V_5 ] ) ;
return 0 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_115 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_115 ) ;
}
