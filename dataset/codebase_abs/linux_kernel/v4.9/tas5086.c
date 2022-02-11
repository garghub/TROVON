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
if ( V_32 -> V_34 ) {
for ( V_14 = 0 ; V_14 < F_10 ( V_35 ) ; V_14 ++ ) {
if ( V_35 [ V_14 ] == V_32 -> V_36 ) {
V_33 = V_14 ;
break;
}
}
}
return F_13 ( V_32 -> V_37 , V_38 ,
V_39 , V_33 ) ;
}
static int F_14 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_29 * V_30 = F_15 ( V_41 ) ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
V_43 -> V_11 . integer . V_11 [ 0 ] = V_32 -> V_34 ;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_29 * V_30 = F_15 ( V_41 ) ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
V_32 -> V_34 = V_43 -> V_11 . integer . V_11 [ 0 ] ;
return F_11 ( V_30 ) ;
}
static int F_17 ( struct V_44 * V_45 ,
int V_46 , unsigned int V_47 , int V_48 )
{
struct V_29 * V_30 = V_45 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
switch ( V_46 ) {
case V_49 :
V_32 -> V_50 = V_47 ;
break;
case V_51 :
V_32 -> V_52 = V_47 ;
break;
}
return 0 ;
}
static int F_18 ( struct V_44 * V_45 ,
unsigned int V_53 )
{
struct V_29 * V_30 = V_45 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
if ( ( V_53 & V_54 ) != V_55 ) {
F_2 ( V_30 -> V_2 , L_2 ) ;
return - V_18 ;
}
V_32 -> V_53 = V_53 ;
return 0 ;
}
static int F_19 ( const int * V_56 , int V_25 , int V_57 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_25 ; V_14 ++ )
if ( V_56 [ V_14 ] == V_57 )
return V_14 ;
return - V_58 ;
}
static int F_20 ( struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_44 * V_63 )
{
struct V_29 * V_30 = V_63 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
int V_33 ;
int V_17 ;
V_32 -> V_36 = F_21 ( V_62 ) ;
V_33 = F_19 ( V_64 ,
F_10 ( V_64 ) , V_32 -> V_36 ) ;
if ( V_33 < 0 ) {
F_2 ( V_30 -> V_2 , L_3 ) ;
return - V_18 ;
}
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_65 ,
F_22 ( V_33 ) ) ;
if ( V_17 < 0 )
return V_17 ;
V_33 = F_19 ( V_66 , F_10 ( V_66 ) ,
V_32 -> V_50 / V_32 -> V_36 ) ;
if ( V_33 < 0 ) {
F_2 ( V_30 -> V_2 , L_4 ) ;
return - V_18 ;
}
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_67 ,
F_23 ( V_33 ) ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_68 ,
( V_32 -> V_52 == 48 * V_32 -> V_36 ) ?
V_68 : 0 ) ;
if ( V_17 < 0 )
return V_17 ;
switch ( V_32 -> V_53 & V_69 ) {
case V_70 :
V_33 = 0x00 ;
break;
case V_71 :
V_33 = 0x03 ;
break;
case V_72 :
V_33 = 0x06 ;
break;
default:
F_2 ( V_30 -> V_2 , L_5 ) ;
return - V_18 ;
}
switch ( F_24 ( V_62 ) ) {
case 16 :
V_33 += 0 ;
break;
case 20 :
V_33 += 1 ;
break;
case 24 :
V_33 += 2 ;
break;
default:
F_2 ( V_30 -> V_2 , L_6 ) ;
return - V_18 ;
}
V_17 = F_25 ( V_32 -> V_37 , V_73 , V_33 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_13 ( V_32 -> V_37 , V_4 ,
V_74 , V_74 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_11 ( V_30 ) ;
}
static int F_26 ( struct V_44 * V_63 , int V_75 , int V_76 )
{
struct V_29 * V_30 = V_63 -> V_30 ;
struct V_31 * V_32 = F_12 ( V_30 ) ;
unsigned int V_33 = 0 ;
if ( V_75 )
V_33 = V_77 ;
return F_25 ( V_32 -> V_37 , V_78 , V_33 ) ;
}
static void F_27 ( struct V_31 * V_32 )
{
if ( F_28 ( V_32 -> V_79 ) ) {
F_29 ( V_32 -> V_79 , 0 ) ;
F_30 ( 1 ) ;
F_31 ( V_32 -> V_79 , 1 ) ;
F_32 ( 15 ) ;
}
}
static int F_33 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
int V_17 , V_14 ;
if ( V_32 -> V_80 )
F_25 ( V_32 -> V_37 , V_81 ,
V_82 |
V_32 -> V_80 ) ;
if ( V_32 -> V_83 == 0 ) {
F_25 ( V_32 -> V_37 , V_84 , 0 ) ;
} else {
V_14 = F_19 ( V_85 ,
F_10 ( V_85 ) ,
V_32 -> V_83 ) ;
if ( V_14 >= 0 )
F_25 ( V_32 -> V_37 , V_84 ,
V_14 + 0x08 ) ;
else
F_34 ( V_2 ,
L_7 ,
V_32 -> V_83 ) ;
}
V_17 = F_25 ( V_32 -> V_37 , V_86 , 0x00 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_25 ( V_32 -> V_37 , V_87 , 0x20 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_25 ( V_32 -> V_37 , V_78 ,
V_77 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
int V_17 ;
V_17 = F_25 ( V_32 -> V_37 , V_87 , 0x60 ) ;
if ( V_17 < 0 )
return V_17 ;
F_36 ( F_10 ( V_32 -> V_88 ) , V_32 -> V_88 ) ;
return 0 ;
}
static int F_37 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
int V_17 ;
V_17 = F_38 ( F_10 ( V_32 -> V_88 ) , V_32 -> V_88 ) ;
if ( V_17 < 0 )
return V_17 ;
F_27 ( V_32 ) ;
F_39 ( V_32 -> V_37 ) ;
V_17 = F_33 ( V_30 -> V_2 , V_32 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_40 ( V_32 -> V_37 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_41 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
int V_14 , V_17 ;
V_17 = F_38 ( F_10 ( V_32 -> V_88 ) , V_32 -> V_88 ) ;
if ( V_17 < 0 ) {
F_2 ( V_30 -> V_2 , L_8 , V_17 ) ;
return V_17 ;
}
V_32 -> V_80 = 0 ;
V_32 -> V_83 = 1300000 ;
if ( F_42 ( F_43 ( V_89 ) , V_30 -> V_2 ) ) {
struct V_90 * V_91 = V_30 -> V_2 -> V_91 ;
F_44 ( V_91 , L_9 ,
& V_32 -> V_83 ) ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ ) {
char V_92 [ 25 ] ;
snprintf ( V_92 , sizeof( V_92 ) ,
L_10 , V_14 + 1 ) ;
if ( F_45 ( V_91 , V_92 , NULL ) != NULL )
V_32 -> V_80 |= 1 << V_14 ;
}
}
F_27 ( V_32 ) ;
V_17 = F_33 ( V_30 -> V_2 , V_32 ) ;
if ( V_17 < 0 )
goto V_93;
V_17 = F_25 ( V_32 -> V_37 , V_94 , 0x30 ) ;
if ( V_17 < 0 )
goto V_93;
return 0 ;
V_93:
F_36 ( F_10 ( V_32 -> V_88 ) , V_32 -> V_88 ) ;
return V_17 ;
}
static int F_46 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = F_12 ( V_30 ) ;
if ( F_28 ( V_32 -> V_79 ) )
F_31 ( V_32 -> V_79 , 0 ) ;
F_36 ( F_10 ( V_32 -> V_88 ) , V_32 -> V_88 ) ;
return 0 ;
}
static int F_47 ( struct V_12 * V_95 ,
const struct V_96 * V_97 )
{
struct V_31 * V_32 ;
struct V_1 * V_2 = & V_95 -> V_2 ;
int V_79 = - V_18 ;
int V_14 , V_17 ;
V_32 = F_48 ( V_2 , sizeof( * V_32 ) , V_98 ) ;
if ( ! V_32 )
return - V_99 ;
for ( V_14 = 0 ; V_14 < F_10 ( V_100 ) ; V_14 ++ )
V_32 -> V_88 [ V_14 ] . V_101 = V_100 [ V_14 ] ;
V_17 = F_49 ( V_2 , F_10 ( V_32 -> V_88 ) ,
V_32 -> V_88 ) ;
if ( V_17 < 0 ) {
F_2 ( V_2 , L_11 , V_17 ) ;
return V_17 ;
}
V_32 -> V_37 = F_50 ( V_2 , NULL , V_95 , & V_102 ) ;
if ( F_51 ( V_32 -> V_37 ) ) {
V_17 = F_52 ( V_32 -> V_37 ) ;
F_2 ( & V_95 -> V_2 , L_12 , V_17 ) ;
return V_17 ;
}
F_53 ( V_95 , V_32 ) ;
if ( F_42 ( F_43 ( V_89 ) , V_2 ) ) {
struct V_90 * V_91 = V_2 -> V_91 ;
V_79 = F_54 ( V_91 , L_13 , 0 ) ;
}
if ( F_28 ( V_79 ) )
if ( F_55 ( V_2 , V_79 , L_14 ) )
V_79 = - V_18 ;
V_32 -> V_79 = V_79 ;
V_17 = F_38 ( F_10 ( V_32 -> V_88 ) , V_32 -> V_88 ) ;
if ( V_17 < 0 ) {
F_2 ( V_2 , L_8 , V_17 ) ;
return V_17 ;
}
F_27 ( V_32 ) ;
V_17 = F_56 ( V_32 -> V_37 , V_8 , & V_14 ) ;
if ( V_17 == 0 && V_14 != 0x3 ) {
F_2 ( V_2 ,
L_15 , V_14 ) ;
V_17 = - V_103 ;
}
F_36 ( F_10 ( V_32 -> V_88 ) , V_32 -> V_88 ) ;
if ( V_17 == 0 )
V_17 = F_57 ( & V_95 -> V_2 , & V_104 ,
& V_105 , 1 ) ;
return V_17 ;
}
static int F_58 ( struct V_12 * V_95 )
{
F_59 ( & V_95 -> V_2 ) ;
return 0 ;
}
