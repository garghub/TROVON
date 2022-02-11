static int F_1 ( struct V_1 * V_2 , int * V_3 ,
int * V_4 )
{
int V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
switch ( V_5 ) {
case V_9 ... V_10 :
* V_3 = V_11 + ( V_5 - V_9 ) ;
break;
case V_12 ... V_13 :
* V_3 = V_14 + ( V_5 - V_12 ) ;
break;
case V_15 :
* V_3 = V_16 ;
break;
case V_17 ... V_18 :
* V_3 = V_19 + ( V_5 - V_17 ) * 9 ;
break;
case V_20 :
* V_3 = V_21 ;
break;
case V_22 ... V_23 :
* V_3 = V_24 + ( V_5 - V_22 ) * 2 ;
break;
default:
return - V_25 ;
}
V_6 = V_8 -> V_26 [ V_5 ] . V_6 ;
* V_4 = V_27 [ V_5 ] [ V_6 ] << V_28 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_29 , V_3 ;
int V_30 = 0xc0 , V_4 ;
T_1 V_31 ;
V_29 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_29 == - V_25 )
return 1 ;
else if ( V_29 )
return V_29 ;
V_29 = F_5 ( V_8 -> V_32 , V_3 , & V_31 ) ;
if ( V_29 )
return V_29 ;
return ( V_31 & V_30 ) == V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_29 , V_3 ;
int V_30 = 0xc0 , V_4 ;
V_29 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_29 )
return V_29 ;
return F_7 ( V_8 -> V_32 , V_3 , V_4 , V_30 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_29 , V_3 ;
int V_30 = 0xc0 , V_4 ;
V_29 = F_1 ( V_2 , & V_3 , & V_4 ) ;
if ( V_29 )
return V_29 ;
return F_7 ( V_8 -> V_32 , V_3 , ~ V_30 , V_30 ) ;
}
static int F_9 ( struct V_1 * V_2 , int * V_33 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_5 = F_2 ( V_2 ) ;
int V_3 ;
switch ( V_5 ) {
case V_9 ... V_10 :
V_3 = V_11 + ( V_5 - V_9 ) ;
break;
case V_12 ... V_13 :
V_3 = V_14 + ( V_5 - V_12 ) ;
break;
case V_15 :
V_3 = V_34 ;
break;
case V_17 :
V_3 = V_35 ;
if ( V_8 -> V_36 )
V_3 += V_8 -> V_37 ;
break;
case V_38 :
V_3 = V_39 ;
if ( V_8 -> V_40 )
V_3 += V_8 -> V_37 ;
break;
case V_18 :
V_3 = V_41 ;
if ( V_8 -> V_42 )
V_3 += V_8 -> V_37 ;
break;
case V_20 :
V_3 = V_43 ;
break;
case V_22 ... V_23 :
V_3 = V_44 + ( V_5 - V_22 ) * 2 ;
break;
default:
return - V_25 ;
}
* V_33 = V_3 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_3 , V_30 , V_29 ;
int V_5 = F_2 ( V_2 ) ;
T_1 V_31 ;
V_29 = F_9 ( V_2 , & V_3 ) ;
if ( V_29 )
return V_29 ;
V_30 = ( V_5 < V_15 ) ? 0x3f : 0xff ;
V_29 = F_5 ( V_8 -> V_32 , V_3 , & V_31 ) ;
if ( V_29 )
return V_29 ;
V_31 &= V_30 ;
return V_31 ;
}
static int F_11 (
const struct V_45 * V_46 ,
int V_47 , int V_48 )
{
int V_49 = 0 ;
if ( V_46 == NULL )
return - V_25 ;
if ( V_48 < V_46 -> V_50 || V_47 > V_46 -> V_51 )
return - V_25 ;
if ( V_47 < V_46 -> V_50 )
V_47 = V_46 -> V_50 ;
V_49 = F_12 ( V_47 - V_46 -> V_50 , V_46 -> V_52 ) ;
if ( V_46 -> V_50 + V_46 -> V_52 * V_49 > V_48 )
return - V_25 ;
return V_49 ;
}
static inline int F_13 ( struct V_7 * V_8 )
{
int V_53 = V_8 -> V_37 ;
F_14 ( V_8 -> V_54 [ 0 ] , ( V_53 >> 2 ) & 0x1 ) ;
F_14 ( V_8 -> V_54 [ 1 ] , ( V_53 >> 1 ) & 0x1 ) ;
F_14 ( V_8 -> V_54 [ 2 ] , V_53 & 0x1 ) ;
return 0 ;
}
static inline int F_15 ( struct V_7 * V_8 )
{
int V_53 = V_8 -> V_37 ;
F_14 ( V_8 -> V_54 [ 2 ] , V_53 & 0x1 ) ;
F_14 ( V_8 -> V_54 [ 1 ] , ( V_53 >> 1 ) & 0x1 ) ;
F_14 ( V_8 -> V_54 [ 0 ] , ( V_53 >> 2 ) & 0x1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_49 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
int V_5 = F_2 ( V_2 ) ;
int V_3 , V_30 , V_29 = 0 , V_55 , V_56 = 0 ;
T_1 * V_57 = NULL ;
switch ( V_5 ) {
case V_9 ... V_13 :
V_30 = 0x3f ;
break;
case V_15 ... V_22 :
V_30 = 0xff ;
if ( V_5 == V_17 && V_8 -> V_36 )
V_57 = & V_8 -> V_58 [ 0 ] ;
else if ( V_5 == V_38 && V_8 -> V_40 )
V_57 = & V_8 -> V_59 [ 0 ] ;
else if ( V_5 == V_18 && V_8 -> V_42 )
V_57 = & V_8 -> V_60 [ 0 ] ;
break;
case V_61 ... V_62 :
return - V_25 ;
case V_23 :
V_30 = 0xff ;
break;
default:
return - V_25 ;
}
if ( V_57 ) {
while ( * V_57 != V_49 ) {
V_57 ++ ;
V_56 ++ ;
}
V_55 = V_8 -> V_37 ;
V_8 -> V_37 = V_56 ;
if ( V_56 > V_55 )
return F_13 ( V_8 ) ;
else
return F_15 ( V_8 ) ;
} else {
V_29 = F_9 ( V_2 , & V_3 ) ;
if ( V_29 )
return V_29 ;
return F_7 ( V_8 -> V_32 , V_3 , V_49 , V_30 ) ;
}
}
static int F_17 ( struct V_1 * V_2 ,
unsigned int V_63 ,
unsigned int V_64 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
const struct V_45 * V_46 ;
int V_5 = F_2 ( V_2 ) ;
V_46 = V_65 [ V_5 ] ;
if ( ( V_63 < V_64 ) && V_8 -> V_66 )
return F_12 ( V_46 -> V_52 * ( V_64 - V_63 ) ,
V_8 -> V_66 * 1000 ) ;
return 0 ;
}
static T_2 int F_18 ( struct V_67 * V_68 )
{
struct V_69 * V_32 = F_19 ( V_68 -> V_70 . V_71 ) ;
struct V_72 * V_73 = F_20 ( V_32 -> V_70 ) ;
struct V_74 V_75 = { } ;
struct V_1 * * V_2 ;
struct V_7 * V_8 ;
int V_76 , V_29 , V_77 , V_78 ;
if ( ! V_73 ) {
F_21 ( V_68 -> V_70 . V_71 , L_1 ) ;
return - V_79 ;
}
if ( V_73 -> V_36 ) {
if ( V_73 -> V_40 || V_73 -> V_42 ) {
F_21 ( & V_68 -> V_70 , L_2 ) ;
return - V_25 ;
}
}
if ( V_73 -> V_40 ) {
if ( V_73 -> V_36 || V_73 -> V_42 ) {
F_21 ( & V_68 -> V_70 , L_2 ) ;
return - V_25 ;
}
}
if ( V_73 -> V_42 ) {
if ( V_73 -> V_36 || V_73 -> V_40 ) {
F_21 ( & V_68 -> V_70 , L_2 ) ;
return - V_25 ;
}
}
V_8 = F_22 ( & V_68 -> V_70 , sizeof( struct V_7 ) ,
V_80 ) ;
if ( ! V_8 )
return - V_81 ;
V_77 = sizeof( struct V_1 * ) * ( V_82 - 2 ) ;
V_8 -> V_2 = F_22 ( & V_68 -> V_70 , V_77 , V_80 ) ;
if ( ! V_8 -> V_2 )
return - V_81 ;
V_2 = V_8 -> V_2 ;
V_8 -> V_70 = & V_68 -> V_70 ;
V_8 -> V_32 = V_32 ;
V_8 -> V_83 = V_82 - 2 ;
F_23 ( V_68 , V_8 ) ;
V_8 -> V_37 = V_73 -> V_84 ;
V_8 -> V_36 = V_73 -> V_36 ;
V_8 -> V_40 = V_73 -> V_40 ;
V_8 -> V_42 = V_73 -> V_42 ;
V_8 -> V_54 [ 0 ] = V_73 -> V_54 [ 0 ] ;
V_8 -> V_54 [ 1 ] = V_73 -> V_54 [ 1 ] ;
V_8 -> V_54 [ 2 ] = V_73 -> V_54 [ 2 ] ;
V_8 -> V_85 [ 0 ] = V_73 -> V_85 [ 0 ] ;
V_8 -> V_85 [ 1 ] = V_73 -> V_85 [ 1 ] ;
V_8 -> V_85 [ 2 ] = V_73 -> V_85 [ 2 ] ;
V_8 -> V_66 = V_73 -> V_86 ;
V_8 -> V_87 = V_73 -> V_88 ;
V_8 -> V_89 = V_73 -> V_90 ;
V_8 -> V_91 = V_73 -> V_92 ;
V_8 -> V_26 = V_73 -> V_26 ;
V_78 = F_11 ( & V_93 ,
V_73 -> V_94 ,
V_73 -> V_94 +
V_93 . V_52 ) ;
F_24 ( V_8 -> V_32 , V_35 , V_78 ) ;
V_78 = F_11 ( & V_93 ,
V_73 -> V_95 ,
V_73 -> V_95 +
V_93 . V_52 ) ;
F_24 ( V_8 -> V_32 , V_39 , V_78 ) ;
V_78 = F_11 ( & V_93 ,
V_73 -> V_96 ,
V_73 -> V_96 +
V_93 . V_52 ) ;
F_24 ( V_8 -> V_32 , V_41 , V_78 ) ;
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
if ( V_8 -> V_36 ) {
V_8 -> V_58 [ V_76 ] =
F_11 (
& V_93 ,
V_73 -> V_97 [ V_76 ] ,
V_73 -> V_97 [ V_76 ] +
V_93 . V_52 ) ;
}
if ( V_8 -> V_40 ) {
V_8 -> V_59 [ V_76 ] =
F_11 (
& V_93 ,
V_73 -> V_98 [ V_76 ] ,
V_73 -> V_98 [ V_76 ] +
V_93 . V_52 ) ;
}
if ( V_8 -> V_42 ) {
V_8 -> V_60 [ V_76 ] =
F_11 (
& V_93 ,
V_73 -> V_99 [ V_76 ] ,
V_73 -> V_99 [ V_76 ] +
V_93 . V_52 ) ;
}
}
if ( F_25 ( V_73 -> V_54 [ 0 ] ) &&
F_25 ( V_73 -> V_54 [ 1 ] ) &&
F_25 ( V_73 -> V_54 [ 2 ] ) ) {
V_29 = F_26 ( & V_68 -> V_70 , V_73 -> V_54 [ 0 ] ,
L_3 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_26 ( & V_68 -> V_70 , V_73 -> V_54 [ 1 ] ,
L_4 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_26 ( & V_68 -> V_70 , V_73 -> V_54 [ 2 ] ,
L_5 ) ;
if ( V_29 )
return V_29 ;
F_27 ( V_73 -> V_54 [ 0 ] ,
( V_8 -> V_37 >> 2 ) & 0x1 ) ;
F_27 ( V_73 -> V_54 [ 1 ] ,
( V_8 -> V_37 >> 1 ) & 0x1 ) ;
F_27 ( V_73 -> V_54 [ 2 ] ,
( V_8 -> V_37 >> 0 ) & 0x1 ) ;
} else {
F_21 ( & V_68 -> V_70 , L_6 ) ;
V_29 = - V_25 ;
return V_29 ;
}
V_29 = F_26 ( & V_68 -> V_70 , V_73 -> V_85 [ 0 ] , L_7 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_26 ( & V_68 -> V_70 , V_73 -> V_85 [ 1 ] , L_8 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_26 ( & V_68 -> V_70 , V_73 -> V_85 [ 2 ] , L_9 ) ;
if ( V_29 )
return V_29 ;
F_27 ( V_73 -> V_85 [ 0 ] , 0x0 ) ;
F_27 ( V_73 -> V_85 [ 1 ] , 0x0 ) ;
F_27 ( V_73 -> V_85 [ 2 ] , 0x0 ) ;
if ( V_73 -> V_36 || V_73 -> V_40 ||
V_73 -> V_42 ) {
F_7 ( V_8 -> V_32 , V_19 ,
( V_73 -> V_36 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
F_7 ( V_8 -> V_32 , V_100 ,
( V_73 -> V_40 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
F_7 ( V_8 -> V_32 , V_101 ,
( V_73 -> V_42 ) ? ( 1 << 1 ) : ( 0 << 1 ) ,
1 << 1 ) ;
}
for ( V_76 = 0 ; V_76 < 8 ; V_76 ++ ) {
if ( V_8 -> V_36 ) {
F_24 ( V_8 -> V_32 , V_102 + V_76 ,
V_8 -> V_58 [ V_76 ] ) ;
}
if ( V_8 -> V_40 ) {
F_24 ( V_8 -> V_32 , V_103 + V_76 ,
V_8 -> V_59 [ V_76 ] ) ;
}
if ( V_8 -> V_42 ) {
F_24 ( V_8 -> V_32 , V_104 + V_76 ,
V_8 -> V_60 [ V_76 ] ) ;
}
}
if ( V_8 -> V_87 )
F_7 ( V_8 -> V_32 , V_105 , 0x08 , 0x08 ) ;
if ( V_8 -> V_89 )
F_7 ( V_8 -> V_32 , V_105 , 0x04 , 0x04 ) ;
if ( V_8 -> V_91 )
F_7 ( V_8 -> V_32 , V_105 , 0x02 , 0x02 ) ;
if ( V_8 -> V_87 || V_8 -> V_89
|| V_8 -> V_91 ) {
switch ( V_8 -> V_66 ) {
case 5 :
F_7 ( V_8 -> V_32 , V_105 ,
0x40 , 0xf0 ) ;
break;
case 10 :
F_7 ( V_8 -> V_32 , V_105 ,
0x90 , 0xf0 ) ;
break;
case 25 :
F_7 ( V_8 -> V_32 , V_105 ,
0xd0 , 0xf0 ) ;
break;
case 50 :
F_7 ( V_8 -> V_32 , V_105 ,
0xe0 , 0xf0 ) ;
break;
case 100 :
F_7 ( V_8 -> V_32 , V_105 ,
0xf0 , 0xf0 ) ;
break;
default:
F_7 ( V_8 -> V_32 , V_105 ,
0x90 , 0xf0 ) ;
}
}
for ( V_76 = 0 ; V_76 < V_73 -> V_83 ; V_76 ++ ) {
const struct V_45 * V_46 ;
int V_106 = V_73 -> V_107 [ V_76 ] . V_106 ;
V_46 = V_65 [ V_106 ] ;
if ( V_46 ) {
V_107 [ V_106 ] . V_108 =
( V_46 -> V_51 - V_46 -> V_50 ) / V_46 -> V_52 + 1 ;
V_107 [ V_106 ] . V_109 = V_46 -> V_50 ;
V_107 [ V_106 ] . V_110 = V_46 -> V_52 ;
}
V_75 . V_70 = V_8 -> V_70 ;
V_75 . V_111 = V_73 -> V_107 [ V_76 ] . V_112 ;
V_75 . V_113 = V_8 ;
V_2 [ V_76 ] = F_28 ( & V_107 [ V_106 ] , & V_75 ) ;
if ( F_29 ( V_2 [ V_76 ] ) ) {
V_29 = F_30 ( V_2 [ V_76 ] ) ;
F_21 ( V_8 -> V_70 , L_10 ,
V_106 ) ;
V_2 [ V_76 ] = NULL ;
goto V_114;
}
}
return 0 ;
V_114:
for ( V_76 = 0 ; V_76 < V_8 -> V_83 ; V_76 ++ )
if ( V_2 [ V_76 ] )
F_31 ( V_2 [ V_76 ] ) ;
return V_29 ;
}
static int T_3 F_32 ( struct V_67 * V_68 )
{
struct V_7 * V_8 = F_33 ( V_68 ) ;
struct V_1 * * V_2 = V_8 -> V_2 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_8 -> V_83 ; V_76 ++ )
if ( V_2 [ V_76 ] )
F_31 ( V_2 [ V_76 ] ) ;
return 0 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_115 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_115 ) ;
}
