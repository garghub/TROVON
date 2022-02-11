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
static int F_4 ( struct V_1 * V_2 , int * V_13 ,
int * V_14 )
{
int V_6 = F_2 ( V_2 ) ;
unsigned int V_15 ;
struct V_16 * V_17 = F_5 ( V_2 ) ;
switch ( V_6 ) {
case V_18 ... V_19 :
* V_13 = V_20 + ( V_6 - V_18 ) ;
break;
case V_21 ... V_22 :
* V_13 = V_23 + ( V_6 - V_21 ) ;
break;
case V_24 :
* V_13 = V_25 ;
break;
case V_26 ... V_27 :
* V_13 = V_28 + ( V_6 - V_26 ) * 9 ;
break;
case V_29 :
* V_13 = V_30 ;
break;
case V_31 ... V_32 :
* V_13 = V_33 + ( V_6 - V_31 ) * 2 ;
break;
default:
return - V_9 ;
}
V_15 = V_17 -> V_34 [ V_6 ] . V_15 ;
* V_14 = V_35 [ V_6 ] [ V_15 ] << V_36 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_37 , V_13 ;
int V_38 = 0xc0 , V_14 ;
T_1 V_7 ;
V_37 = F_4 ( V_2 , & V_13 , & V_14 ) ;
if ( V_37 == - V_9 )
return 1 ;
else if ( V_37 )
return V_37 ;
V_37 = F_7 ( V_17 -> V_39 , V_13 , & V_7 ) ;
if ( V_37 )
return V_37 ;
return ( V_7 & V_38 ) == V_14 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_37 , V_13 ;
int V_38 = 0xc0 , V_14 ;
V_37 = F_4 ( V_2 , & V_13 , & V_14 ) ;
if ( V_37 )
return V_37 ;
return F_9 ( V_17 -> V_39 , V_13 , V_14 , V_38 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_37 , V_13 ;
int V_38 = 0xc0 , V_14 ;
V_37 = F_4 ( V_2 , & V_13 , & V_14 ) ;
if ( V_37 )
return V_37 ;
return F_9 ( V_17 -> V_39 , V_13 , ~ V_38 , V_38 ) ;
}
static int F_11 ( struct V_1 * V_2 , int * V_40 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_6 = F_2 ( V_2 ) ;
int V_13 ;
switch ( V_6 ) {
case V_18 ... V_19 :
V_13 = V_20 + ( V_6 - V_18 ) ;
break;
case V_21 ... V_22 :
V_13 = V_23 + ( V_6 - V_21 ) ;
break;
case V_24 :
V_13 = V_41 ;
break;
case V_26 :
V_13 = V_42 ;
if ( V_17 -> V_43 )
V_13 += V_17 -> V_44 ;
break;
case V_45 :
V_13 = V_46 ;
if ( V_17 -> V_47 )
V_13 += V_17 -> V_44 ;
break;
case V_27 :
V_13 = V_48 ;
if ( V_17 -> V_49 )
V_13 += V_17 -> V_44 ;
break;
case V_29 :
V_13 = V_50 ;
break;
case V_31 ... V_32 :
V_13 = V_51 + ( V_6 - V_31 ) * 2 ;
break;
default:
return - V_9 ;
}
* V_40 = V_13 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
int V_13 , V_38 , V_37 ;
int V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_37 = F_11 ( V_2 , & V_13 ) ;
if ( V_37 )
return V_37 ;
V_38 = ( V_6 < V_24 ) ? 0x3f : 0xff ;
V_37 = F_7 ( V_17 -> V_39 , V_13 , & V_7 ) ;
if ( V_37 )
return V_37 ;
V_7 &= V_38 ;
return V_7 ;
}
static int F_13 (
const struct V_4 * V_5 ,
int V_52 , int V_53 )
{
int V_3 = 0 ;
if ( V_5 == NULL )
return - V_9 ;
if ( V_53 < V_5 -> V_10 || V_52 > V_5 -> V_12 )
return - V_9 ;
if ( V_52 < V_5 -> V_10 )
V_52 = V_5 -> V_10 ;
V_3 = F_14 ( V_52 - V_5 -> V_10 , V_5 -> V_11 ) ;
if ( V_5 -> V_10 + V_5 -> V_11 * V_3 > V_53 )
return - V_9 ;
return V_3 ;
}
static inline void F_15 ( struct V_16 * V_17 )
{
int V_54 = V_17 -> V_44 ;
F_16 ( V_17 -> V_55 [ 0 ] , ( V_54 >> 2 ) & 0x1 ) ;
F_16 ( V_17 -> V_55 [ 1 ] , ( V_54 >> 1 ) & 0x1 ) ;
F_16 ( V_17 -> V_55 [ 2 ] , V_54 & 0x1 ) ;
}
static inline void F_17 ( struct V_16 * V_17 )
{
int V_54 = V_17 -> V_44 ;
F_16 ( V_17 -> V_55 [ 2 ] , V_54 & 0x1 ) ;
F_16 ( V_17 -> V_55 [ 1 ] , ( V_54 >> 1 ) & 0x1 ) ;
F_16 ( V_17 -> V_55 [ 0 ] , ( V_54 >> 2 ) & 0x1 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_56 , int V_57 , unsigned * V_3 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
const struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
int V_58 , V_13 , V_38 , V_37 = 0 , V_59 , V_60 = 0 ;
T_1 V_7 ;
T_1 * V_61 = NULL ;
switch ( V_6 ) {
case V_18 ... V_22 :
V_38 = 0x3f ;
break;
case V_24 ... V_31 :
V_38 = 0xff ;
if ( V_6 == V_26 && V_17 -> V_43 )
V_61 = & V_17 -> V_62 [ 0 ] ;
else if ( V_6 == V_45 && V_17 -> V_47 )
V_61 = & V_17 -> V_63 [ 0 ] ;
else if ( V_6 == V_27 && V_17 -> V_49 )
V_61 = & V_17 -> V_64 [ 0 ] ;
break;
case V_65 ... V_66 :
return - V_9 ;
case V_32 :
V_38 = 0xff ;
break;
default:
return - V_9 ;
}
V_5 = V_8 [ V_6 ] ;
V_58 = F_13 ( V_5 , V_56 , V_57 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_61 ) {
while ( * V_61 != V_58 ) {
V_61 ++ ;
V_60 ++ ;
}
V_59 = V_17 -> V_44 ;
V_17 -> V_44 = V_60 ;
if ( V_60 > V_59 )
F_15 ( V_17 ) ;
else
F_17 ( V_17 ) ;
} else {
V_37 = F_11 ( V_2 , & V_13 ) ;
if ( V_37 )
return V_37 ;
F_7 ( V_17 -> V_39 , V_13 , & V_7 ) ;
V_7 = ( V_7 & ~ V_38 ) | V_58 ;
V_37 = F_19 ( V_17 -> V_39 , V_13 , V_7 ) ;
}
* V_3 = V_58 ;
return V_37 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned int V_67 ,
unsigned int V_68 )
{
struct V_16 * V_17 = F_5 ( V_2 ) ;
const struct V_4 * V_5 ;
int V_6 = F_2 ( V_2 ) ;
V_5 = V_8 [ V_6 ] ;
if ( ( V_67 < V_68 ) && V_17 -> V_69 )
return F_14 ( V_5 -> V_11 * ( V_68 - V_67 ) ,
V_17 -> V_69 * 1000 ) ;
return 0 ;
}
static T_2 int F_21 ( struct V_70 * V_71 )
{
struct V_72 * V_39 = F_22 ( V_71 -> V_73 . V_74 ) ;
struct V_75 * V_76 = F_23 ( V_39 -> V_73 ) ;
struct V_77 V_78 = { } ;
struct V_1 * * V_2 ;
struct V_16 * V_17 ;
int V_79 , V_37 , V_80 ;
if ( ! V_76 ) {
F_24 ( V_71 -> V_73 . V_74 , L_1 ) ;
return - V_81 ;
}
if ( V_76 -> V_43 ) {
if ( V_76 -> V_47 || V_76 -> V_49 ) {
F_24 ( & V_71 -> V_73 , L_2 ) ;
return - V_9 ;
}
}
if ( V_76 -> V_47 ) {
if ( V_76 -> V_43 || V_76 -> V_49 ) {
F_24 ( & V_71 -> V_73 , L_2 ) ;
return - V_9 ;
}
}
if ( V_76 -> V_49 ) {
if ( V_76 -> V_43 || V_76 -> V_47 ) {
F_24 ( & V_71 -> V_73 , L_2 ) ;
return - V_9 ;
}
}
V_17 = F_25 ( & V_71 -> V_73 , sizeof( struct V_16 ) ,
V_82 ) ;
if ( ! V_17 )
return - V_83 ;
V_80 = sizeof( struct V_1 * ) * ( V_84 - 2 ) ;
V_17 -> V_2 = F_25 ( & V_71 -> V_73 , V_80 , V_82 ) ;
if ( ! V_17 -> V_2 )
return - V_83 ;
V_2 = V_17 -> V_2 ;
V_17 -> V_73 = & V_71 -> V_73 ;
V_17 -> V_39 = V_39 ;
V_17 -> V_85 = V_84 - 2 ;
F_26 ( V_71 , V_17 ) ;
V_17 -> V_44 = V_76 -> V_86 ;
V_17 -> V_43 = V_76 -> V_43 ;
V_17 -> V_47 = V_76 -> V_47 ;
V_17 -> V_49 = V_76 -> V_49 ;
V_17 -> V_55 [ 0 ] = V_76 -> V_55 [ 0 ] ;
V_17 -> V_55 [ 1 ] = V_76 -> V_55 [ 1 ] ;
V_17 -> V_55 [ 2 ] = V_76 -> V_55 [ 2 ] ;
V_17 -> V_69 = V_76 -> V_87 ;
V_17 -> V_88 = V_76 -> V_89 ;
V_17 -> V_90 = V_76 -> V_91 ;
V_17 -> V_92 = V_76 -> V_93 ;
V_17 -> V_34 = V_76 -> V_34 ;
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ ) {
if ( V_17 -> V_43 ) {
V_17 -> V_62 [ V_79 ] =
F_13 (
& V_94 ,
V_76 -> V_95 [ V_79 ] ,
V_76 -> V_95 [ V_79 ] +
V_94 . V_11 ) ;
}
if ( V_17 -> V_47 ) {
V_17 -> V_63 [ V_79 ] =
F_13 (
& V_94 ,
V_76 -> V_96 [ V_79 ] ,
V_76 -> V_96 [ V_79 ] +
V_94 . V_11 ) ;
}
if ( V_17 -> V_49 ) {
V_17 -> V_64 [ V_79 ] =
F_13 (
& V_94 ,
V_76 -> V_97 [ V_79 ] ,
V_76 -> V_97 [ V_79 ] +
V_94 . V_11 ) ;
}
}
if ( V_76 -> V_43 || V_76 -> V_47 ||
V_76 -> V_49 ) {
if ( F_27 ( V_76 -> V_55 [ 0 ] ) &&
F_27 ( V_76 -> V_55 [ 1 ] ) &&
F_27 ( V_76 -> V_55 [ 2 ] ) ) {
V_37 = F_28 ( V_76 -> V_55 [ 0 ] ,
L_3 ) ;
if ( V_37 == - V_98 )
F_29 ( & V_71 -> V_73 , L_4 ) ;
V_37 = F_28 ( V_76 -> V_55 [ 1 ] ,
L_5 ) ;
if ( V_37 == - V_98 )
F_29 ( & V_71 -> V_73 , L_6 ) ;
V_37 = F_28 ( V_76 -> V_55 [ 2 ] ,
L_7 ) ;
if ( V_37 == - V_98 )
F_29 ( & V_71 -> V_73 , L_8 ) ;
F_30 ( V_76 -> V_55 [ 0 ] ,
( V_17 -> V_44 >> 2 ) & 0x1 ) ;
F_30 ( V_76 -> V_55 [ 1 ] ,
( V_17 -> V_44 >> 1 ) & 0x1 ) ;
F_30 ( V_76 -> V_55 [ 2 ] ,
( V_17 -> V_44 >> 0 ) & 0x1 ) ;
V_37 = 0 ;
} else {
F_24 ( & V_71 -> V_73 , L_9 ) ;
V_37 = - V_9 ;
return V_37 ;
}
}
F_9 ( V_17 -> V_39 , V_28 ,
( V_76 -> V_43 ) ? ( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
F_9 ( V_17 -> V_39 , V_99 ,
( V_76 -> V_47 ) ? ( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
F_9 ( V_17 -> V_39 , V_100 ,
( V_76 -> V_49 ) ? ( 1 << 1 ) : ( 0 << 1 ) , 1 << 1 ) ;
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ ) {
if ( V_17 -> V_43 ) {
F_19 ( V_17 -> V_39 , V_42 + V_79 ,
V_17 -> V_62 [ V_79 ] ) ;
}
if ( V_17 -> V_47 ) {
F_19 ( V_17 -> V_39 , V_46 + V_79 ,
V_17 -> V_63 [ V_79 ] ) ;
}
if ( V_17 -> V_49 ) {
F_19 ( V_17 -> V_39 , V_48 + V_79 ,
V_17 -> V_64 [ V_79 ] ) ;
}
}
F_9 ( V_17 -> V_39 , V_28 , 0x78 , 0xff ) ;
F_9 ( V_17 -> V_39 , V_99 , 0x58 , 0xff ) ;
F_9 ( V_17 -> V_39 , V_100 , 0x78 , 0xff ) ;
if ( V_17 -> V_88 )
F_9 ( V_17 -> V_39 , V_101 , 0x08 , 0x08 ) ;
if ( V_17 -> V_90 )
F_9 ( V_17 -> V_39 , V_101 , 0x04 , 0x04 ) ;
if ( V_17 -> V_92 )
F_9 ( V_17 -> V_39 , V_101 , 0x02 , 0x02 ) ;
if ( V_17 -> V_88 || V_17 -> V_90
|| V_17 -> V_92 ) {
switch ( V_17 -> V_69 ) {
case 15 :
F_9 ( V_17 -> V_39 , V_101 ,
0xc0 , 0xf0 ) ;
break;
case 25 :
F_9 ( V_17 -> V_39 , V_101 ,
0xd0 , 0xf0 ) ;
break;
case 50 :
F_9 ( V_17 -> V_39 , V_101 ,
0xe0 , 0xf0 ) ;
break;
case 100 :
F_9 ( V_17 -> V_39 , V_101 ,
0xf0 , 0xf0 ) ;
break;
default:
F_9 ( V_17 -> V_39 , V_101 ,
0x90 , 0xf0 ) ;
}
}
for ( V_79 = 0 ; V_79 < V_76 -> V_85 ; V_79 ++ ) {
const struct V_4 * V_5 ;
int V_102 = V_76 -> V_103 [ V_79 ] . V_102 ;
V_5 = V_8 [ V_102 ] ;
if ( V_5 )
V_103 [ V_102 ] . V_104 =
( V_5 -> V_12 - V_5 -> V_10 ) / V_5 -> V_11 + 1 ;
V_78 . V_73 = V_17 -> V_73 ;
V_78 . V_105 = V_76 -> V_103 [ V_79 ] . V_106 ;
V_78 . V_107 = V_17 ;
V_2 [ V_79 ] = F_31 ( & V_103 [ V_102 ] , & V_78 ) ;
if ( F_32 ( V_2 [ V_79 ] ) ) {
V_37 = F_33 ( V_2 [ V_79 ] ) ;
F_24 ( V_17 -> V_73 , L_10 ,
V_102 ) ;
V_2 [ V_79 ] = NULL ;
goto V_108;
}
}
return 0 ;
V_108:
for ( V_79 = 0 ; V_79 < V_17 -> V_85 ; V_79 ++ )
if ( V_2 [ V_79 ] )
F_34 ( V_2 [ V_79 ] ) ;
return V_37 ;
}
static int T_3 F_35 ( struct V_70 * V_71 )
{
struct V_16 * V_17 = F_36 ( V_71 ) ;
struct V_1 * * V_2 = V_17 -> V_2 ;
int V_79 ;
for ( V_79 = 0 ; V_79 < V_17 -> V_85 ; V_79 ++ )
if ( V_2 [ V_79 ] )
F_34 ( V_2 [ V_79 ] ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
return F_38 ( & V_109 ) ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_109 ) ;
}
