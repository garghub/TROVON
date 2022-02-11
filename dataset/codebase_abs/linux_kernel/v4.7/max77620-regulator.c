static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_5 -> V_9 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_1 ,
V_5 -> V_9 , V_7 ) ;
return V_7 ;
}
return ( V_6 & V_11 ) >> V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_13 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
unsigned int V_6 ;
int V_7 ;
if ( ! V_5 )
return 0 ;
switch ( V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
break;
case V_18 :
V_7 = F_2 ( V_2 -> V_8 , V_5 -> V_9 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_1 ,
V_5 -> V_9 , V_7 ) ;
return V_7 ;
}
V_7 = ( V_6 & V_11 ) >> V_12 ;
V_2 -> V_19 [ V_3 ] = V_7 ;
return 0 ;
default:
F_3 ( V_2 -> V_10 , L_2 ,
V_13 , V_3 ) ;
return - V_20 ;
}
V_7 = F_5 ( V_2 -> V_8 , V_5 -> V_9 ,
V_11 ,
V_13 << V_12 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_3 ,
V_5 -> V_9 , V_7 ) ;
return V_7 ;
}
V_2 -> V_19 [ V_3 ] = V_13 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_3 , bool V_21 )
{
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] ;
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
unsigned int V_6 = 0 ;
unsigned int V_25 = 0 ;
int V_26 = V_23 -> V_27 ;
int V_28 = V_23 -> V_29 ;
int V_7 = 0 ;
if ( ! V_5 )
return 0 ;
if ( V_21 ) {
V_26 = V_23 -> V_30 ;
V_28 = V_23 -> V_31 ;
}
if ( V_26 >= 0 ) {
V_6 |= ( V_26 << V_32 ) ;
V_25 |= V_33 ;
}
if ( V_28 >= 0 ) {
V_6 |= ( V_28 << V_34 ) ;
V_25 |= V_35 ;
}
if ( V_25 ) {
V_7 = F_5 ( V_2 -> V_8 , V_5 -> V_9 ,
V_25 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_4 ,
V_5 -> V_9 , V_7 ) ;
return V_7 ;
}
}
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_36 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
T_1 V_25 = V_5 -> V_37 ;
T_1 V_38 = V_5 -> V_39 ;
T_1 V_40 ;
int V_7 ;
switch ( V_5 -> type ) {
case V_41 :
V_40 = V_5 -> V_42 ;
break;
default:
V_40 = V_5 -> V_43 ;
break;
}
V_7 = F_5 ( V_2 -> V_8 , V_40 , V_25 , V_36 << V_38 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_5 ,
V_3 , V_7 ) ;
return V_7 ;
}
V_2 -> V_44 [ V_3 ] = V_36 ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
unsigned int V_6 , V_40 ;
T_1 V_25 = V_5 -> V_37 ;
T_1 V_38 = V_5 -> V_39 ;
int V_7 ;
switch ( V_5 -> type ) {
case V_41 :
V_40 = V_5 -> V_42 ;
break;
default:
V_40 = V_5 -> V_43 ;
break;
}
V_7 = F_2 ( V_2 -> V_8 , V_40 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_6 ,
V_3 , V_40 , V_7 ) ;
return V_7 ;
}
return ( V_6 & V_25 ) >> V_38 ;
}
static int F_9 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
unsigned int V_45 ;
int V_46 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_5 -> V_42 , & V_45 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_7 ,
V_5 -> V_42 , V_7 ) ;
return V_7 ;
}
switch ( V_5 -> type ) {
case V_41 :
V_46 = ( V_45 >> V_47 ) & 0x3 ;
switch ( V_46 ) {
case 0 :
V_46 = 13750 ;
break;
case 1 :
V_46 = 27500 ;
break;
case 2 :
V_46 = 55000 ;
break;
case 3 :
V_46 = 100000 ;
break;
}
V_5 -> V_48 . V_49 = V_46 ;
break;
default:
V_46 = V_45 & 0x1 ;
switch ( V_46 ) {
case 0 :
V_46 = 100000 ;
break;
case 1 :
V_46 = 5000 ;
break;
}
V_5 -> V_48 . V_49 = V_46 ;
break;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , int V_3 ,
int V_46 )
{
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
unsigned int V_6 ;
int V_7 ;
T_1 V_25 ;
if ( V_5 -> type == V_41 ) {
if ( V_46 <= 13750 )
V_6 = 0 ;
else if ( V_46 <= 27500 )
V_6 = 1 ;
else if ( V_46 <= 55000 )
V_6 = 2 ;
else
V_6 = 3 ;
V_6 <<= V_47 ;
V_25 = V_50 ;
} else {
if ( V_46 <= 5000 )
V_6 = 1 ;
else
V_6 = 0 ;
V_25 = V_51 ;
}
V_7 = F_5 ( V_2 -> V_8 , V_5 -> V_42 , V_25 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_8 ,
V_3 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] ;
int V_7 ;
V_7 = F_8 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_44 [ V_3 ] = V_7 ;
V_2 -> V_52 [ V_3 ] = V_53 ;
if ( V_23 -> V_19 == V_18 ) {
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_19 = V_7 ;
}
if ( V_23 -> V_19 == V_17 ) {
V_7 = F_7 ( V_2 ,
V_2 -> V_52 [ V_3 ] , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
if ( V_2 -> V_44 [ V_3 ] !=
V_2 -> V_52 [ V_3 ] ) {
V_7 = F_7 ( V_2 ,
V_2 -> V_52 [ V_3 ] , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
}
}
V_7 = F_4 ( V_2 , V_23 -> V_19 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_2 , V_3 , false ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_23 -> V_54 ) {
V_7 = F_10 ( V_2 , V_3 ,
V_23 -> V_54 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_12 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_13 ( V_56 ) ;
int V_3 = F_14 ( V_56 ) ;
if ( V_2 -> V_19 [ V_3 ] != V_17 )
return 0 ;
return F_7 ( V_2 ,
V_2 -> V_52 [ V_3 ] , V_3 ) ;
}
static int F_15 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_13 ( V_56 ) ;
int V_3 = F_14 ( V_56 ) ;
if ( V_2 -> V_19 [ V_3 ] != V_17 )
return 0 ;
return F_7 ( V_2 ,
V_57 , V_3 ) ;
}
static int F_16 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_13 ( V_56 ) ;
int V_3 = F_14 ( V_56 ) ;
int V_7 = 1 ;
if ( V_2 -> V_19 [ V_3 ] != V_17 )
return 1 ;
V_7 = F_8 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 != V_57 )
return 1 ;
return 0 ;
}
static int F_17 ( struct V_55 * V_56 ,
unsigned int V_58 )
{
struct V_1 * V_2 = F_13 ( V_56 ) ;
int V_3 = F_14 ( V_56 ) ;
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] ;
bool V_59 = false ;
int V_36 ;
int V_7 ;
T_1 V_6 ;
switch ( V_58 ) {
case V_60 :
V_59 = true ;
V_36 = V_53 ;
break;
case V_61 :
V_36 = V_53 ;
break;
case V_62 :
V_36 = V_63 ;
break;
default:
F_3 ( V_2 -> V_10 , L_9 ,
V_3 , V_58 ) ;
return - V_20 ;
}
if ( V_5 -> type != V_41 )
goto V_64;
V_6 = ( V_59 ) ? V_65 : 0 ;
V_7 = F_5 ( V_2 -> V_8 , V_5 -> V_42 ,
V_65 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_4 ,
V_5 -> V_42 , V_7 ) ;
return V_7 ;
}
V_23 -> V_66 = V_58 ;
V_64:
V_7 = F_7 ( V_2 , V_36 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_52 [ V_3 ] = V_36 ;
return 0 ;
}
static unsigned int F_18 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_13 ( V_56 ) ;
int V_3 = F_14 ( V_56 ) ;
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
int V_59 = 0 ;
int V_7 ;
int V_67 , V_68 ;
unsigned int V_6 ;
V_7 = F_8 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return 0 ;
V_67 = V_7 ;
if ( V_5 -> type == V_41 ) {
V_7 = F_2 ( V_2 -> V_8 , V_5 -> V_42 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_10 ,
V_5 -> V_42 , V_7 ) ;
return V_7 ;
}
V_59 = ! ! ( V_6 & V_65 ) ;
}
switch ( V_67 ) {
case V_53 :
case V_57 :
if ( V_59 )
V_68 = V_60 ;
else
V_68 = V_61 ;
break;
case V_63 :
case V_69 :
V_68 = V_62 ;
break;
default:
return 0 ;
}
return V_68 ;
}
static int F_19 ( struct V_55 * V_56 ,
int V_49 )
{
struct V_1 * V_2 = F_13 ( V_56 ) ;
int V_3 = F_14 ( V_56 ) ;
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] ;
if ( V_23 -> V_54 )
return 0 ;
return F_10 ( V_2 , V_3 , V_49 ) ;
}
static int F_20 ( struct V_70 * V_71 ,
const struct V_72 * V_48 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_74 -> V_75 ;
struct V_22 * V_23 = & V_2 -> V_24 [ V_48 -> V_3 ] ;
T_2 V_76 ;
int V_7 ;
V_7 = F_21 ( V_71 , L_11 , & V_76 ) ;
V_23 -> V_19 = ( ! V_7 ) ? V_76 : V_18 ;
V_7 = F_21 ( V_71 , L_12 , & V_76 ) ;
V_23 -> V_27 = ( ! V_7 ) ? V_76 : - 1 ;
V_7 = F_21 (
V_71 , L_13 , & V_76 ) ;
V_23 -> V_29 = ( ! V_7 ) ? V_76 : - 1 ;
V_7 = F_21 ( V_71 , L_14 , & V_76 ) ;
V_23 -> V_77 = ( ! V_7 ) ? V_76 : - 1 ;
V_7 = F_21 (
V_71 , L_15 , & V_76 ) ;
V_23 -> V_30 = ( ! V_7 ) ? V_76 : - 1 ;
V_7 = F_21 (
V_71 , L_16 , & V_76 ) ;
V_23 -> V_31 = ( ! V_7 ) ? V_76 : - 1 ;
V_7 = F_21 ( V_71 , L_17 , & V_76 ) ;
V_23 -> V_54 = ( ! V_7 ) ? V_76 : 0 ;
return F_11 ( V_2 , V_48 -> V_3 ) ;
}
static int F_22 ( struct V_78 * V_79 )
{
struct V_80 * V_80 = F_23 ( V_79 -> V_10 . V_81 ) ;
struct V_4 * V_5 ;
struct V_82 * V_10 = & V_79 -> V_10 ;
struct V_73 V_74 = { } ;
struct V_1 * V_2 ;
int V_7 = 0 ;
int V_3 ;
V_2 = F_24 ( V_10 , sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
F_25 ( V_79 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_8 = V_80 -> V_8 ;
if ( ! V_10 -> V_85 )
V_10 -> V_85 = V_79 -> V_10 . V_81 -> V_85 ;
switch ( V_80 -> V_86 ) {
case V_87 :
V_5 = V_88 ;
break;
default:
V_5 = V_89 ;
break;
}
V_74 . V_90 = V_2 -> V_8 ;
V_74 . V_10 = V_10 ;
V_74 . V_75 = V_2 ;
for ( V_3 = 0 ; V_3 < V_91 ; V_3 ++ ) {
struct V_55 * V_56 ;
struct V_72 * V_92 ;
if ( ( V_80 -> V_86 == V_87 ) &&
( V_3 == V_93 ) )
continue;
V_92 = & V_5 [ V_3 ] . V_48 ;
V_2 -> V_5 [ V_3 ] = & V_88 [ V_3 ] ;
V_2 -> V_52 [ V_3 ] = V_53 ;
V_7 = F_9 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_56 = F_26 ( V_10 , V_92 , & V_74 ) ;
if ( F_27 ( V_56 ) ) {
V_7 = F_28 ( V_56 ) ;
F_3 ( V_10 , L_18 ,
V_92 -> V_94 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
static int F_29 ( struct V_82 * V_10 )
{
struct V_1 * V_2 = F_23 ( V_10 ) ;
struct V_22 * V_24 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_91 ; V_3 ++ ) {
V_24 = & V_2 -> V_24 [ V_3 ] ;
F_6 ( V_2 , V_3 , true ) ;
if ( V_24 -> V_77 < 0 )
continue;
F_4 ( V_2 , V_24 -> V_77 ,
V_3 ) ;
}
return 0 ;
}
static int F_30 ( struct V_82 * V_10 )
{
struct V_1 * V_2 = F_23 ( V_10 ) ;
struct V_22 * V_24 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_91 ; V_3 ++ ) {
V_24 = & V_2 -> V_24 [ V_3 ] ;
F_6 ( V_2 , V_3 , false ) ;
if ( V_24 -> V_19 < 0 )
continue;
F_4 ( V_2 , V_24 -> V_19 ,
V_3 ) ;
}
return 0 ;
}
