static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
return 1 ;
case V_6 :
case V_7 :
return 4 ;
}
F_2 ( V_2 , L_1 , V_3 ) ;
return 0 ;
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0x0f :
case 0x11 ... 0x17 :
case 0x1d ... 0x1f :
return false ;
default:
return true ;
}
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_8 :
case V_9 :
return true ;
}
return false ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_3 ( V_2 , V_3 ) && ( V_3 != V_8 ) ;
}
static int F_6 ( void * V_10 , unsigned int V_3 ,
unsigned int V_11 )
{
struct V_12 * V_13 = V_10 ;
unsigned int V_14 , V_15 ;
T_1 V_16 [ 5 ] ;
int V_17 ;
V_15 = F_1 ( & V_13 -> V_2 , V_3 ) ;
if ( V_15 == 0 )
return - V_18 ;
V_16 [ 0 ] = V_3 ;
for ( V_14 = V_15 ; V_14 >= 1 ; -- V_14 ) {
V_16 [ V_14 ] = V_11 ;
V_11 >>= 8 ;
}
V_17 = F_7 ( V_13 , V_16 , V_15 + 1 ) ;
if ( V_17 == V_15 + 1 )
return 0 ;
else if ( V_17 < 0 )
return V_17 ;
else
return - V_19 ;
}
static int F_8 ( void * V_10 , unsigned int V_3 ,
unsigned int * V_11 )
{
struct V_12 * V_13 = V_10 ;
T_1 V_20 , V_21 [ 4 ] ;
struct V_22 V_23 [ 2 ] ;
unsigned int V_15 ;
unsigned int V_14 ;
int V_17 ;
V_15 = F_1 ( & V_13 -> V_2 , V_3 ) ;
if ( V_15 == 0 )
return - V_18 ;
V_20 = V_3 ;
V_23 [ 0 ] . V_24 = V_13 -> V_24 ;
V_23 [ 0 ] . V_25 = sizeof( V_20 ) ;
V_23 [ 0 ] . V_16 = & V_20 ;
V_23 [ 0 ] . V_26 = 0 ;
V_23 [ 1 ] . V_24 = V_13 -> V_24 ;
V_23 [ 1 ] . V_25 = V_15 ;
V_23 [ 1 ] . V_16 = V_21 ;
V_23 [ 1 ] . V_26 = V_27 ;
V_17 = F_9 ( V_13 -> V_28 , V_23 , F_10 ( V_23 ) ) ;
if ( V_17 < 0 )
return V_17 ;
else if ( V_17 != F_10 ( V_23 ) )
return - V_19 ;
* V_11 = 0 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
* V_11 <<= 8 ;
* V_11 |= V_21 [ V_14 ] ;
}
return 0 ;
}
static int F_11 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
int V_14 , V_33 = 0 ;
if ( V_32 -> V_34 )
for ( V_14 = 0 ; V_14 < F_10 ( V_35 ) ; V_14 ++ )
if ( V_35 [ V_14 ] == V_32 -> V_36 )
V_33 = V_14 ;
return F_13 ( V_32 -> V_37 , V_38 ,
V_39 , V_33 ) ;
}
static int F_14 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_29 * V_30 = F_15 ( V_41 ) ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
V_43 -> V_11 . V_44 . V_45 [ 0 ] = V_32 -> V_34 ;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_29 * V_30 = F_15 ( V_41 ) ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
V_32 -> V_34 = V_43 -> V_11 . V_44 . V_45 [ 0 ] ;
return F_11 ( V_30 ) ;
}
static int F_17 ( struct V_46 * V_47 ,
int V_48 , unsigned int V_49 , int V_50 )
{
struct V_29 * V_30 = V_47 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
switch ( V_48 ) {
case V_51 :
V_32 -> V_52 = V_49 ;
break;
case V_53 :
V_32 -> V_54 = V_49 ;
break;
}
return 0 ;
}
static int F_18 ( struct V_46 * V_47 ,
unsigned int V_55 )
{
struct V_29 * V_30 = V_47 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
if ( ( V_55 & V_56 ) != V_57 ) {
F_2 ( V_30 -> V_2 , L_2 ) ;
return - V_18 ;
}
V_32 -> V_55 = V_55 ;
return 0 ;
}
static int F_19 ( const int * V_58 , int V_25 , int V_59 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_25 ; V_14 ++ )
if ( V_58 [ V_14 ] == V_59 )
return V_14 ;
return - V_60 ;
}
static int F_20 ( struct V_61 * V_62 ,
struct V_63 * V_64 ,
struct V_46 * V_65 )
{
struct V_29 * V_30 = V_65 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
int V_33 ;
int V_17 ;
V_32 -> V_36 = F_21 ( V_64 ) ;
V_33 = F_19 ( V_66 ,
F_10 ( V_66 ) , V_32 -> V_36 ) ;
if ( V_33 < 0 ) {
F_2 ( V_30 -> V_2 , L_3 ) ;
return - V_18 ;
}
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_67 ,
F_22 ( V_33 ) ) ;
if ( V_17 < 0 )
return V_17 ;
V_33 = F_19 ( V_68 , F_10 ( V_68 ) ,
V_32 -> V_52 / V_32 -> V_36 ) ;
if ( V_33 < 0 ) {
F_2 ( V_30 -> V_2 , L_4 ) ;
return - V_18 ;
}
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_69 ,
F_23 ( V_33 ) ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_70 ,
( V_32 -> V_54 == 48 * V_32 -> V_36 ) ?
V_70 : 0 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_32 -> V_55 & V_71 ) {
case V_72 :
V_33 = 0x00 ;
break;
case V_73 :
V_33 = 0x03 ;
break;
case V_74 :
V_33 = 0x06 ;
break;
default:
F_2 ( V_30 -> V_2 , L_5 ) ;
return - V_18 ;
}
switch ( F_24 ( V_64 ) ) {
case V_75 :
V_33 += 0 ;
break;
case V_76 :
V_33 += 1 ;
break;
case V_77 :
V_33 += 2 ;
break;
default:
F_2 ( V_30 -> V_2 , L_6 ) ;
return - V_18 ;
} ;
V_17 = F_25 ( V_32 -> V_37 , V_78 , V_33 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_79 , V_79 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_11 ( V_30 ) ;
}
static int F_26 ( struct V_46 * V_65 , int V_80 , int V_81 )
{
struct V_29 * V_30 = V_65 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
unsigned int V_33 = 0 ;
if ( V_80 )
V_33 = V_82 ;
return F_25 ( V_32 -> V_37 , V_83 , V_33 ) ;
}
static int F_27 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
return F_28 ( V_32 -> V_37 ) ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
int V_84 = 1300000 ;
T_2 V_85 = 0 ;
int V_14 , V_17 ;
if ( F_30 ( F_31 ( V_86 ) , V_30 -> V_2 ) ) {
struct V_87 * V_88 = V_30 -> V_2 -> V_88 ;
F_32 ( V_88 , L_7 , & V_84 ) ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ ) {
char V_89 [ 25 ] ;
snprintf ( V_89 , sizeof( V_89 ) ,
L_8 , V_14 + 1 ) ;
if ( F_33 ( V_88 , V_89 , NULL ) != NULL )
V_85 |= 1 << V_14 ;
}
}
if ( V_85 )
F_25 ( V_32 -> V_37 , V_90 ,
V_91 |
V_85 ) ;
if ( V_84 == 0 ) {
F_25 ( V_32 -> V_37 , V_92 , 0 ) ;
} else {
V_14 = F_19 ( V_93 ,
F_10 ( V_93 ) ,
V_84 ) ;
if ( V_14 >= 0 )
F_25 ( V_32 -> V_37 , V_92 ,
V_14 + 0x08 ) ;
else
F_34 ( V_30 -> V_2 ,
L_9 ,
V_84 ) ;
}
V_17 = F_25 ( V_32 -> V_37 , V_94 , 0x00 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_25 ( V_32 -> V_37 , V_95 , 0x20 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_25 ( V_32 -> V_37 , V_96 , 0x30 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_25 ( V_32 -> V_37 , V_83 ,
V_82 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
if ( F_36 ( V_32 -> V_97 ) )
F_37 ( V_32 -> V_97 , 0 ) ;
return 0 ;
}
static int F_38 ( struct V_12 * V_98 ,
const struct V_99 * V_100 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = & V_98 -> V_2 ;
int V_97 = - V_18 ;
int V_14 , V_17 ;
V_32 = F_39 ( V_2 , sizeof( * V_32 ) , V_101 ) ;
if ( ! V_32 )
return - V_102 ;
V_32 -> V_37 = F_40 ( V_2 , NULL , V_98 , & V_103 ) ;
if ( F_41 ( V_32 -> V_37 ) ) {
V_17 = F_42 ( V_32 -> V_37 ) ;
F_2 ( & V_98 -> V_2 , L_10 , V_17 ) ;
return V_17 ;
}
F_43 ( V_98 , V_32 ) ;
if ( F_30 ( F_31 ( V_86 ) , V_2 ) ) {
struct V_87 * V_88 = V_2 -> V_88 ;
V_97 = F_44 ( V_88 , L_11 , 0 ) ;
}
if ( F_36 ( V_97 ) )
if ( F_45 ( V_2 , V_97 , L_12 ) )
V_97 = - V_18 ;
if ( F_36 ( V_97 ) ) {
F_46 ( V_97 , 0 ) ;
F_47 ( 1 ) ;
F_37 ( V_97 , 1 ) ;
F_48 ( 15 ) ;
}
V_32 -> V_97 = V_97 ;
V_17 = F_49 ( V_32 -> V_37 , V_8 , & V_14 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_14 != 0x3 ) {
F_2 ( V_2 ,
L_13 , V_14 ) ;
return - V_104 ;
}
return F_50 ( & V_98 -> V_2 , & V_105 ,
& V_106 , 1 ) ;
}
static int F_51 ( struct V_12 * V_98 )
{
F_52 ( & V_98 -> V_2 ) ;
return 0 ;
}
