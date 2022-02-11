static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
const struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
int V_7 ;
if ( V_6 >= F_3 ( V_8 ) || V_6 < 0 )
return - V_9 ;
V_5 = V_8 [ V_6 ] ;
if ( V_5 == NULL )
return - V_9 ;
V_7 = V_5 -> V_10 + V_5 -> V_11 * V_3 ;
if ( V_7 > V_5 -> V_12 )
return - V_9 ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , int * V_13 )
{
int V_6 = F_2 ( V_2 ) ;
switch ( V_6 ) {
case V_14 ... V_15 :
* V_13 = V_16 + ( V_6 - V_14 ) ;
break;
case V_17 ... V_18 :
* V_13 = V_19 + ( V_6 - V_17 ) ;
break;
case V_20 :
* V_13 = V_21 ;
break;
case V_22 ... V_23 :
* V_13 = V_24 + ( V_6 - V_22 ) * 9 ;
break;
case V_25 :
* V_13 = V_26 ;
break;
case V_27 ... V_28 :
* V_13 = V_29 + ( V_6 - V_27 ) * 2 ;
break;
default:
return - V_9 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
int V_32 , V_13 ;
int V_33 = 0xc0 , V_34 = 0xc0 ;
T_1 V_7 ;
V_32 = F_4 ( V_2 , & V_13 ) ;
if ( V_32 == - V_9 )
return 1 ;
else if ( V_32 )
return V_32 ;
V_32 = F_7 ( V_31 -> V_35 , V_13 , & V_7 ) ;
if ( V_32 )
return V_32 ;
return ( V_7 & V_33 ) == V_34 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
int V_32 , V_13 ;
int V_33 = 0xc0 , V_34 = 0xc0 ;
V_32 = F_4 ( V_2 , & V_13 ) ;
if ( V_32 )
return V_32 ;
return F_9 ( V_31 -> V_35 , V_13 , V_34 , V_33 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
int V_32 , V_13 ;
int V_33 = 0xc0 , V_34 = 0xc0 ;
V_32 = F_4 ( V_2 , & V_13 ) ;
if ( V_32 )
return V_32 ;
return F_9 ( V_31 -> V_35 , V_13 , ~ V_34 , V_33 ) ;
}
static int F_11 ( struct V_1 * V_2 , int * V_36 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
int V_6 = F_2 ( V_2 ) ;
int V_13 ;
switch ( V_6 ) {
case V_14 ... V_15 :
V_13 = V_16 + ( V_6 - V_14 ) ;
break;
case V_17 ... V_18 :
V_13 = V_19 + ( V_6 - V_17 ) ;
break;
case V_20 :
V_13 = V_37 ;
break;
case V_22 :
V_13 = V_38 ;
if ( V_31 -> V_39 )
V_13 += V_31 -> V_40 ;
break;
case V_41 :
V_13 = V_42 ;
if ( V_31 -> V_43 )
V_13 += V_31 -> V_40 ;
break;
case V_23 :
V_13 = V_44 ;
if ( V_31 -> V_45 )
V_13 += V_31 -> V_40 ;
break;
case V_25 :
V_13 = V_46 ;
break;
case V_27 ... V_28 :
V_13 = V_47 + ( V_6 - V_27 ) * 2 ;
break;
default:
return - V_9 ;
}
* V_36 = V_13 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
int V_13 , V_33 , V_32 ;
int V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_32 = F_11 ( V_2 , & V_13 ) ;
if ( V_32 )
return V_32 ;
V_33 = ( V_6 < V_20 ) ? 0x3f : 0xff ;
V_32 = F_7 ( V_31 -> V_35 , V_13 , & V_7 ) ;
if ( V_32 )
return V_32 ;
V_7 &= V_33 ;
return V_7 ;
}
static int F_13 (
const struct V_4 * V_5 ,
int V_48 , int V_49 )
{
int V_3 = 0 ;
if ( V_5 == NULL )
return - V_9 ;
if ( V_49 < V_5 -> V_10 || V_48 > V_5 -> V_12 )
return - V_9 ;
V_3 = ( V_48 - V_5 -> V_10 ) / V_5 -> V_11 ;
if ( V_5 -> V_10 + V_5 -> V_11 * V_3 > V_49 )
return - V_9 ;
return V_3 ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_50 , int V_51 , unsigned * V_3 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
const struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
int V_52 , V_13 , V_33 , V_32 ;
T_1 V_7 ;
switch ( V_6 ) {
case V_14 ... V_18 :
V_33 = 0x3f ;
break;
case V_20 ... V_27 :
V_33 = 0xff ;
break;
case V_53 ... V_54 :
return - V_9 ;
case V_28 :
V_33 = 0xff ;
break;
default:
return - V_9 ;
}
V_5 = V_8 [ V_6 ] ;
V_52 = F_13 ( V_5 , V_50 , V_51 ) ;
if ( V_52 < 0 )
return V_52 ;
V_32 = F_11 ( V_2 , & V_13 ) ;
if ( V_32 )
return V_32 ;
F_7 ( V_31 -> V_35 , V_13 , & V_7 ) ;
V_7 &= ~ V_33 ;
V_7 |= V_52 ;
V_32 = F_15 ( V_31 -> V_35 , V_13 , V_7 ) ;
* V_3 = V_52 ;
return V_32 ;
}
static inline void F_16 ( struct V_30 * V_31 )
{
int V_55 = V_31 -> V_40 ;
F_17 ( V_31 -> V_56 [ 0 ] , ( V_55 >> 2 ) & 0x1 ) ;
F_17 ( V_31 -> V_56 [ 1 ] , ( V_55 >> 1 ) & 0x1 ) ;
F_17 ( V_31 -> V_56 [ 2 ] , V_55 & 0x1 ) ;
}
static inline void F_18 ( struct V_30 * V_31 )
{
int V_55 = V_31 -> V_40 ;
F_17 ( V_31 -> V_56 [ 2 ] , V_55 & 0x1 ) ;
F_17 ( V_31 -> V_56 [ 1 ] , ( V_55 >> 1 ) & 0x1 ) ;
F_17 ( V_31 -> V_56 [ 0 ] , ( V_55 >> 2 ) & 0x1 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_50 , int V_51 , unsigned * V_3 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
int V_6 = F_2 ( V_2 ) ;
const struct V_4 * V_5 ;
int V_57 , V_58 , V_59 = 0 ;
if ( V_6 < V_20 || V_6 > V_27 )
return - V_9 ;
switch ( V_6 ) {
case V_20 :
return F_14 ( V_2 , V_50 , V_51 , V_3 ) ;
case V_22 ... V_23 :
break;
case V_25 ... V_27 :
return F_14 ( V_2 , V_50 , V_51 , V_3 ) ;
case V_28 :
return F_14 ( V_2 , V_50 , V_51 , V_3 ) ;
}
V_5 = V_8 [ V_6 ] ;
V_57 = F_13 ( V_5 , V_50 , V_51 ) ;
if ( V_57 < 0 )
return V_57 ;
switch ( V_6 ) {
case V_22 :
if ( V_31 -> V_39 ) {
while ( V_31 -> V_60 [ V_59 ] != V_57 )
V_59 ++ ;
} else
return F_14 ( V_2 , V_50 ,
V_51 , V_3 ) ;
break;
case V_41 :
if ( V_31 -> V_43 ) {
while ( V_31 -> V_61 [ V_59 ] != V_57 )
V_59 ++ ;
} else
return F_14 ( V_2 , V_50 ,
V_51 , V_3 ) ;
break;
case V_23 :
if ( V_31 -> V_43 ) {
while ( V_31 -> V_62 [ V_59 ] != V_57 )
V_59 ++ ;
} else
return F_14 ( V_2 , V_50 ,
V_51 , V_3 ) ;
break;
}
V_58 = V_31 -> V_40 ;
V_31 -> V_40 = V_59 ;
if ( V_59 > V_58 )
F_16 ( V_31 ) ;
else
F_18 ( V_31 ) ;
* V_3 = V_57 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned int V_63 ,
unsigned int V_64 )
{
struct V_30 * V_31 = F_6 ( V_2 ) ;
const struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
V_5 = V_8 [ V_6 ] ;
if ( V_63 < V_64 )
return F_21 ( V_5 -> V_11 * ( V_64 - V_63 ) ,
V_31 -> V_65 * 1000 ) ;
return 0 ;
}
static T_2 int F_22 ( struct V_66 * V_67 )
{
struct V_68 * V_35 = F_23 ( V_67 -> V_69 . V_70 ) ;
struct V_71 * V_72 = F_24 ( V_35 -> V_69 ) ;
struct V_1 * * V_2 ;
struct V_30 * V_31 ;
int V_59 , V_32 , V_73 ;
if ( ! V_72 ) {
F_25 ( V_67 -> V_69 . V_70 , L_1 ) ;
return - V_74 ;
}
if ( V_72 -> V_39 ) {
if ( V_72 -> V_43 || V_72 -> V_45 ) {
F_25 ( & V_67 -> V_69 , L_2 ) ;
return - V_9 ;
}
}
if ( V_72 -> V_43 ) {
if ( V_72 -> V_39 || V_72 -> V_45 ) {
F_25 ( & V_67 -> V_69 , L_2 ) ;
return - V_9 ;
}
}
if ( V_72 -> V_45 ) {
if ( V_72 -> V_39 || V_72 -> V_43 ) {
F_25 ( & V_67 -> V_69 , L_2 ) ;
return - V_9 ;
}
}
V_31 = F_26 ( & V_67 -> V_69 , sizeof( struct V_30 ) ,
V_75 ) ;
if ( ! V_31 )
return - V_76 ;
V_73 = sizeof( struct V_1 * ) * ( V_77 - 2 ) ;
V_31 -> V_2 = F_26 ( & V_67 -> V_69 , V_73 , V_75 ) ;
if ( ! V_31 -> V_2 )
return - V_76 ;
V_2 = V_31 -> V_2 ;
V_31 -> V_69 = & V_67 -> V_69 ;
V_31 -> V_35 = V_35 ;
V_31 -> V_78 = V_77 - 2 ;
F_27 ( V_67 , V_31 ) ;
V_31 -> V_40 = V_72 -> V_79 ;
V_31 -> V_39 = V_72 -> V_39 ;
V_31 -> V_43 = V_72 -> V_43 ;
V_31 -> V_45 = V_72 -> V_45 ;
V_31 -> V_56 [ 0 ] = V_72 -> V_56 [ 0 ] ;
V_31 -> V_56 [ 1 ] = V_72 -> V_56 [ 1 ] ;
V_31 -> V_56 [ 2 ] = V_72 -> V_56 [ 2 ] ;
V_31 -> V_65 = V_72 -> V_80 ;
V_31 -> V_81 = V_72 -> V_82 ;
V_31 -> V_83 = V_72 -> V_84 ;
V_31 -> V_85 = V_72 -> V_86 ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_31 -> V_39 ) {
V_31 -> V_60 [ V_59 ] =
F_13 (
& V_87 ,
V_72 -> V_88 [ V_59 ] ,
V_72 -> V_88 [ V_59 ] +
V_87 . V_11 ) ;
}
if ( V_31 -> V_43 ) {
V_31 -> V_61 [ V_59 ] =
F_13 (
& V_87 ,
V_72 -> V_89 [ V_59 ] ,
V_72 -> V_89 [ V_59 ] +
V_87 . V_11 ) ;
}
if ( V_31 -> V_45 ) {
V_31 -> V_62 [ V_59 ] =
F_13 (
& V_87 ,
V_72 -> V_90 [ V_59 ] ,
V_72 -> V_90 [ V_59 ] +
V_87 . V_11 ) ;
}
}
if ( V_72 -> V_39 || V_72 -> V_43 ||
V_72 -> V_45 ) {
if ( F_28 ( V_72 -> V_56 [ 0 ] ) &&
F_28 ( V_72 -> V_56 [ 1 ] ) &&
F_28 ( V_72 -> V_56 [ 2 ] ) ) {
V_32 = F_29 ( V_72 -> V_56 [ 0 ] ,
L_3 ) ;
if ( V_32 == - V_91 )
F_30 ( & V_67 -> V_69 , L_4 ) ;
V_32 = F_29 ( V_72 -> V_56 [ 1 ] ,
L_5 ) ;
if ( V_32 == - V_91 )
F_30 ( & V_67 -> V_69 , L_6 ) ;
V_32 = F_29 ( V_72 -> V_56 [ 2 ] ,
L_7 ) ;
if ( V_32 == - V_91 )
F_30 ( & V_67 -> V_69 , L_8 ) ;
F_31 ( V_72 -> V_56 [ 0 ] ,
( V_31 -> V_40 >> 2 ) & 0x1 ) ;
F_31 ( V_72 -> V_56 [ 1 ] ,
( V_31 -> V_40 >> 1 ) & 0x1 ) ;
F_31 ( V_72 -> V_56 [ 2 ] ,
( V_31 -> V_40 >> 0 ) & 0x1 ) ;
V_32 = 0 ;
} else {
F_25 ( & V_67 -> V_69 , L_9 ) ;
V_32 = - V_9 ;
return V_32 ;
}
}
F_9 ( V_31 -> V_35 , V_24 ,
( V_72 -> V_39 ) ? ( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
F_9 ( V_31 -> V_35 , V_92 ,
( V_72 -> V_43 ) ? ( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
F_9 ( V_31 -> V_35 , V_93 ,
( V_72 -> V_45 ) ? ( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
for ( V_59 = 0 ; V_59 < 8 ; V_59 ++ ) {
if ( V_31 -> V_39 ) {
F_15 ( V_31 -> V_35 , V_38 + V_59 ,
V_31 -> V_60 [ V_59 ] ) ;
}
if ( V_31 -> V_43 ) {
F_15 ( V_31 -> V_35 , V_42 + V_59 ,
V_31 -> V_61 [ V_59 ] ) ;
}
if ( V_31 -> V_45 ) {
F_15 ( V_31 -> V_35 , V_44 + V_59 ,
V_31 -> V_62 [ V_59 ] ) ;
}
}
F_9 ( V_31 -> V_35 , V_24 , 0x78 , 0xff ) ;
F_9 ( V_31 -> V_35 , V_92 , 0x58 , 0xff ) ;
F_9 ( V_31 -> V_35 , V_93 , 0x78 , 0xff ) ;
if ( V_31 -> V_81 )
F_9 ( V_31 -> V_35 , V_94 , 0x08 , 0x08 ) ;
if ( V_31 -> V_83 )
F_9 ( V_31 -> V_35 , V_94 , 0x04 , 0x04 ) ;
if ( V_31 -> V_85 )
F_9 ( V_31 -> V_35 , V_94 , 0x02 , 0x02 ) ;
if ( V_31 -> V_81 || V_31 -> V_83
|| V_31 -> V_85 ) {
switch ( V_31 -> V_65 ) {
case 15 :
F_9 ( V_31 -> V_35 , V_94 ,
0xc0 , 0xf0 ) ;
break;
case 25 :
F_9 ( V_31 -> V_35 , V_94 ,
0xd0 , 0xf0 ) ;
break;
case 50 :
F_9 ( V_31 -> V_35 , V_94 ,
0xe0 , 0xf0 ) ;
break;
case 100 :
F_9 ( V_31 -> V_35 , V_94 ,
0xf0 , 0xf0 ) ;
break;
default:
F_9 ( V_31 -> V_35 , V_94 ,
0x90 , 0xf0 ) ;
}
}
for ( V_59 = 0 ; V_59 < V_72 -> V_78 ; V_59 ++ ) {
const struct V_4 * V_5 ;
int V_95 = V_72 -> V_96 [ V_59 ] . V_95 ;
V_5 = V_8 [ V_95 ] ;
if ( V_5 )
V_96 [ V_95 ] . V_97 =
( V_5 -> V_12 - V_5 -> V_10 ) / V_5 -> V_11 + 1 ;
V_2 [ V_59 ] = F_32 ( & V_96 [ V_95 ] , V_31 -> V_69 ,
V_72 -> V_96 [ V_59 ] . V_98 , V_31 , NULL ) ;
if ( F_33 ( V_2 [ V_59 ] ) ) {
V_32 = F_34 ( V_2 [ V_59 ] ) ;
F_25 ( V_31 -> V_69 , L_10 ,
V_95 ) ;
V_2 [ V_59 ] = NULL ;
goto V_99;
}
}
return 0 ;
V_99:
for ( V_59 = 0 ; V_59 < V_31 -> V_78 ; V_59 ++ )
if ( V_2 [ V_59 ] )
F_35 ( V_2 [ V_59 ] ) ;
return V_32 ;
}
static int T_3 F_36 ( struct V_66 * V_67 )
{
struct V_30 * V_31 = F_37 ( V_67 ) ;
struct V_1 * * V_2 = V_31 -> V_2 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_31 -> V_78 ; V_59 ++ )
if ( V_2 [ V_59 ] )
F_35 ( V_2 [ V_59 ] ) ;
return 0 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_100 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_100 ) ;
}
