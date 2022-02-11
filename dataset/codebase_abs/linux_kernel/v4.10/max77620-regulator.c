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
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
struct V_52 * V_53 = F_12 ( V_2 -> V_10 -> V_54 ) ;
T_1 V_6 , V_25 ;
int V_7 ;
switch ( V_53 -> V_55 ) {
case V_56 :
if ( V_23 -> V_57 >= 0 ) {
if ( V_5 -> type == V_41 )
V_25 = V_58 ;
else
V_25 = V_59 ;
V_6 = V_23 -> V_57 ? V_25 : 0 ;
V_7 = F_5 ( V_2 -> V_8 , V_5 -> V_42 ,
V_25 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_3 ,
V_5 -> V_42 , V_7 ) ;
return V_7 ;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_3 )
{
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] ;
int V_7 ;
F_11 ( V_2 , V_3 ) ;
V_7 = F_8 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_44 [ V_3 ] = V_7 ;
V_2 -> V_60 [ V_3 ] = V_61 ;
if ( V_23 -> V_19 == V_18 ) {
V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_19 = V_7 ;
}
if ( V_23 -> V_19 == V_17 ) {
V_7 = F_7 ( V_2 ,
V_2 -> V_60 [ V_3 ] , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
} else {
if ( V_2 -> V_44 [ V_3 ] !=
V_2 -> V_60 [ V_3 ] ) {
V_7 = F_7 ( V_2 ,
V_2 -> V_60 [ V_3 ] , V_3 ) ;
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
if ( V_23 -> V_62 ) {
V_7 = F_10 ( V_2 , V_3 ,
V_23 -> V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
}
static int F_14 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_15 ( V_64 ) ;
int V_3 = F_16 ( V_64 ) ;
if ( V_2 -> V_19 [ V_3 ] != V_17 )
return 0 ;
return F_7 ( V_2 ,
V_2 -> V_60 [ V_3 ] , V_3 ) ;
}
static int F_17 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_15 ( V_64 ) ;
int V_3 = F_16 ( V_64 ) ;
if ( V_2 -> V_19 [ V_3 ] != V_17 )
return 0 ;
return F_7 ( V_2 ,
V_65 , V_3 ) ;
}
static int F_18 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_15 ( V_64 ) ;
int V_3 = F_16 ( V_64 ) ;
int V_7 = 1 ;
if ( V_2 -> V_19 [ V_3 ] != V_17 )
return 1 ;
V_7 = F_8 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 != V_65 )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_63 * V_64 ,
unsigned int V_66 )
{
struct V_1 * V_2 = F_15 ( V_64 ) ;
int V_3 = F_16 ( V_64 ) ;
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] ;
bool V_67 = false ;
int V_36 ;
int V_7 ;
T_1 V_6 ;
switch ( V_66 ) {
case V_68 :
V_67 = true ;
V_36 = V_61 ;
break;
case V_69 :
V_36 = V_61 ;
break;
case V_70 :
V_36 = V_71 ;
break;
default:
F_3 ( V_2 -> V_10 , L_9 ,
V_3 , V_66 ) ;
return - V_20 ;
}
if ( V_5 -> type != V_41 )
goto V_72;
V_6 = ( V_67 ) ? V_73 : 0 ;
V_7 = F_5 ( V_2 -> V_8 , V_5 -> V_42 ,
V_73 , V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_4 ,
V_5 -> V_42 , V_7 ) ;
return V_7 ;
}
V_23 -> V_74 = V_66 ;
V_72:
V_7 = F_7 ( V_2 , V_36 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_2 -> V_60 [ V_3 ] = V_36 ;
return 0 ;
}
static unsigned int F_20 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_15 ( V_64 ) ;
int V_3 = F_16 ( V_64 ) ;
struct V_4 * V_5 = V_2 -> V_5 [ V_3 ] ;
int V_67 = 0 ;
int V_7 ;
int V_75 , V_76 ;
unsigned int V_6 ;
V_7 = F_8 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return 0 ;
V_75 = V_7 ;
if ( V_5 -> type == V_41 ) {
V_7 = F_2 ( V_2 -> V_8 , V_5 -> V_42 , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_10 , L_10 ,
V_5 -> V_42 , V_7 ) ;
return V_7 ;
}
V_67 = ! ! ( V_6 & V_73 ) ;
}
switch ( V_75 ) {
case V_61 :
case V_65 :
if ( V_67 )
V_76 = V_68 ;
else
V_76 = V_69 ;
break;
case V_71 :
case V_77 :
V_76 = V_70 ;
break;
default:
return 0 ;
}
return V_76 ;
}
static int F_21 ( struct V_63 * V_64 ,
int V_49 )
{
struct V_1 * V_2 = F_15 ( V_64 ) ;
int V_3 = F_16 ( V_64 ) ;
struct V_22 * V_23 = & V_2 -> V_24 [ V_3 ] ;
if ( V_23 -> V_62 )
return 0 ;
return F_10 ( V_2 , V_3 , V_49 ) ;
}
static int F_22 ( struct V_78 * V_79 ,
const struct V_80 * V_48 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_83 ;
struct V_22 * V_23 = & V_2 -> V_24 [ V_48 -> V_3 ] ;
T_2 V_84 ;
int V_7 ;
V_7 = F_23 ( V_79 , L_11 , & V_84 ) ;
V_23 -> V_19 = ( ! V_7 ) ? V_84 : V_18 ;
V_7 = F_23 ( V_79 , L_12 , & V_84 ) ;
V_23 -> V_27 = ( ! V_7 ) ? V_84 : - 1 ;
V_7 = F_23 (
V_79 , L_13 , & V_84 ) ;
V_23 -> V_29 = ( ! V_7 ) ? V_84 : - 1 ;
V_7 = F_23 ( V_79 , L_14 , & V_84 ) ;
V_23 -> V_85 = ( ! V_7 ) ? V_84 : - 1 ;
V_7 = F_23 (
V_79 , L_15 , & V_84 ) ;
V_23 -> V_30 = ( ! V_7 ) ? V_84 : - 1 ;
V_7 = F_23 (
V_79 , L_16 , & V_84 ) ;
V_23 -> V_31 = ( ! V_7 ) ? V_84 : - 1 ;
V_7 = F_23 ( V_79 , L_17 , & V_84 ) ;
if ( ! V_7 )
V_23 -> V_57 = V_84 ;
else
V_23 -> V_57 = - 1 ;
V_7 = F_23 ( V_79 , L_18 , & V_84 ) ;
V_23 -> V_62 = ( ! V_7 ) ? V_84 : 0 ;
return F_13 ( V_2 , V_48 -> V_3 ) ;
}
static int F_24 ( struct V_86 * V_87 )
{
struct V_52 * V_52 = F_12 ( V_87 -> V_10 . V_54 ) ;
struct V_4 * V_5 ;
struct V_88 * V_10 = & V_87 -> V_10 ;
struct V_81 V_82 = { } ;
struct V_1 * V_2 ;
int V_7 = 0 ;
int V_3 ;
V_2 = F_25 ( V_10 , sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
F_26 ( V_87 , V_2 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_8 = V_52 -> V_8 ;
if ( ! V_10 -> V_91 )
V_10 -> V_91 = V_87 -> V_10 . V_54 -> V_91 ;
switch ( V_52 -> V_55 ) {
case V_92 :
V_5 = V_93 ;
break;
default:
V_5 = V_94 ;
break;
}
V_82 . V_95 = V_2 -> V_8 ;
V_82 . V_10 = V_10 ;
V_82 . V_83 = V_2 ;
for ( V_3 = 0 ; V_3 < V_96 ; V_3 ++ ) {
struct V_63 * V_64 ;
struct V_80 * V_97 ;
if ( ( V_52 -> V_55 == V_92 ) &&
( V_3 == V_98 ) )
continue;
V_97 = & V_5 [ V_3 ] . V_48 ;
V_2 -> V_5 [ V_3 ] = & V_93 [ V_3 ] ;
V_2 -> V_60 [ V_3 ] = V_61 ;
V_7 = F_9 ( V_2 , V_3 ) ;
if ( V_7 < 0 )
return V_7 ;
V_64 = F_27 ( V_10 , V_97 , & V_82 ) ;
if ( F_28 ( V_64 ) ) {
V_7 = F_29 ( V_64 ) ;
F_3 ( V_10 , L_19 ,
V_97 -> V_99 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
static int F_30 ( struct V_88 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_22 * V_24 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_96 ; V_3 ++ ) {
V_24 = & V_2 -> V_24 [ V_3 ] ;
F_6 ( V_2 , V_3 , true ) ;
if ( V_24 -> V_85 < 0 )
continue;
F_4 ( V_2 , V_24 -> V_85 ,
V_3 ) ;
}
return 0 ;
}
static int F_31 ( struct V_88 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_22 * V_24 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_96 ; V_3 ++ ) {
V_24 = & V_2 -> V_24 [ V_3 ] ;
F_11 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_3 , false ) ;
if ( V_24 -> V_19 < 0 )
continue;
F_4 ( V_2 , V_24 -> V_19 ,
V_3 ) ;
}
return 0 ;
}
