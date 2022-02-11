int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_9 = F_3 ( V_6 ) ;
struct V_10 * V_11 = F_4 ( V_8 ) ;
int V_12 = F_5 ( V_2 ) ;
int V_13 = 0 ;
if ( V_11 -> V_14 ) {
V_13 = ! ! V_9 ;
} else {
struct V_15 * V_16 = F_6 ( V_9 ) ;
V_13 = F_7 ( V_16 ) ;
}
F_8 ( V_2 , V_17 , ( 1 << V_12 ) ,
V_13 ? 0 : ( 1 << V_12 ) ) ;
if ( F_9 ( V_2 ) ) {
int V_18 = - 1 ;
switch ( V_12 ) {
case 1 :
V_18 = 0 ;
break;
case 2 :
V_18 = 2 ;
break;
case 4 :
V_18 = 16 ;
break;
}
if ( V_18 >= 0 )
F_8 ( V_2 , V_19 ,
0x3 << V_18 ,
F_10 ( V_4 ) ?
0x2 << V_18 : 0x1 << V_18 ) ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_12 ( V_8 ) )
F_13 ( V_2 , V_20 , 0x0f000000 ) ;
return 0 ;
}
unsigned int F_14 ( struct V_7 * V_8 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_1 * V_9 = F_3 ( V_6 ) ;
struct V_15 * V_16 ;
unsigned int V_23 = 0 ;
if ( V_9 ) {
V_16 = F_6 ( V_9 ) ;
V_23 = F_15 ( V_16 ) ;
}
if ( ! V_23 )
V_23 = V_22 -> V_23 ;
return V_23 ;
}
static int F_16 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_21 * V_22 = F_17 ( V_6 ) ;
struct V_15 * V_16 = F_6 ( V_24 ) ;
T_1 V_25 = F_15 ( V_16 ) ;
T_1 V_26 = V_22 -> V_27 ;
T_1 V_28 = 0 ;
if ( V_25 )
V_28 = 0x0400000 / V_25 * V_22 -> V_23 ;
F_13 ( V_24 , V_29 , 0 ) ;
F_13 ( V_24 , V_29 , 1 ) ;
F_13 ( V_24 , V_30 , 1 ) ;
switch ( V_22 -> V_31 ) {
case 16 :
V_26 |= V_32 ;
break;
case 32 :
V_26 |= V_33 ;
break;
default:
return - V_34 ;
}
F_13 ( V_24 , V_35 , V_26 ) ;
if ( V_28 ) {
F_13 ( V_24 , V_36 , 1 ) ;
F_13 ( V_24 , V_37 , V_28 ) ;
}
F_13 ( V_24 , V_38 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_6 ( V_24 ) ;
F_19 ( V_16 -> V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_6 ( V_24 ) ;
F_21 ( V_16 -> V_39 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_6 ( V_24 ) ;
F_13 ( V_24 , V_30 , 0 ) ;
if ( F_15 ( V_16 ) )
F_13 ( V_24 , V_40 , 1 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_6 ( V_24 ) ;
if ( F_15 ( V_16 ) )
F_13 ( V_24 , V_40 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_41 {
T_1 V_42 ;
int V_18 ;
} V_43 [] = {
{ 0xF , 0 , } ,
{ 0xF , 4 , } ,
{ 0xF , 8 , } ,
{ 0x7 , 12 , } ,
{ 0x7 , 16 , } ,
{ 0x7 , 20 , } ,
{ 0x7 , 24 , } ,
{ 0x3 , 28 , } ,
{ 0x3 , 30 , } ,
} ;
T_1 V_42 ;
T_1 V_44 ;
int V_45 ;
V_45 = F_5 ( V_24 ) ;
if ( V_45 < 0 || V_45 >= F_25 ( V_43 ) )
return - V_34 ;
V_44 = F_26 ( V_4 , V_6 ) ? 0x1 : 0x2 ;
V_44 = V_44 << V_43 [ V_45 ] . V_18 ;
V_42 = V_43 [ V_45 ] . V_42 << V_43 [ V_45 ] . V_18 ;
F_8 ( V_24 , V_46 , V_42 , V_44 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_24 ) ;
struct V_15 * V_16 = F_6 ( V_24 ) ;
struct V_21 * V_22 = F_17 ( V_6 ) ;
T_1 V_25 = F_15 ( V_16 ) ;
T_1 V_42 ;
T_1 V_44 ;
int V_18 ;
int V_45 = F_5 ( V_24 ) ;
int V_47 ;
V_18 = ( V_45 % 4 ) * 8 ;
V_42 = 0x1F << V_18 ;
V_47 = 0 ;
if ( V_25 ) {
V_44 = 0 ;
V_47 = F_28 ( V_8 , V_24 ,
V_22 -> V_23 ,
V_25 ) ;
} else if ( 8 == V_45 ) {
V_44 = V_45 << V_18 ;
} else {
V_44 = ( V_45 + 1 ) << V_18 ;
}
if ( V_47 < 0 )
return V_47 ;
switch ( V_45 / 4 ) {
case 0 :
F_8 ( V_24 , V_48 , V_42 , V_44 ) ;
break;
case 1 :
F_8 ( V_24 , V_49 , V_42 , V_44 ) ;
break;
case 2 :
F_8 ( V_24 , V_50 , V_42 , V_44 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_47 ;
V_47 = F_16 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
F_13 ( V_24 , V_51 , 0x00010110 ) ;
F_13 ( V_24 , V_52 ,
F_30 ( V_24 , V_37 ) / 100 * 98 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_47 ;
V_47 = F_18 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_24 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_29 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_27 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_45 = F_5 ( V_24 ) ;
F_8 ( V_24 , V_53 , ( 1 << V_45 ) , ( 1 << V_45 ) ) ;
return F_22 ( V_24 , V_4 , V_6 ) ;
}
static int F_33 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_45 = F_5 ( V_24 ) ;
F_8 ( V_24 , V_53 , ( 1 << V_45 ) , 0 ) ;
return F_23 ( V_24 , V_4 , V_6 ) ;
}
static int F_34 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_47 ;
V_47 = F_16 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
F_13 ( V_24 , V_54 , F_30 ( V_24 , V_35 ) ) ;
F_13 ( V_24 , V_55 , F_30 ( V_24 , V_38 ) ) ;
F_13 ( V_24 , V_51 , 0x00011110 ) ;
F_13 ( V_24 , V_56 , 0x01800000 ) ;
F_13 ( V_24 , V_57 , 0x00100060 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_21 * V_22 = F_17 ( V_6 ) ;
struct V_15 * V_16 = F_6 ( V_24 ) ;
T_1 V_25 = F_15 ( V_16 ) ;
int V_47 ;
if ( V_25 )
V_47 = F_36 ( V_24 , V_4 , V_6 ,
V_22 -> V_23 ,
V_25 ) ;
else
V_47 = F_37 ( V_24 , V_4 , V_6 ) ;
return V_47 ;
}
static int F_38 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_24 ) ;
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_15 * V_16 = F_6 ( V_24 ) ;
struct V_1 * V_58 = F_39 ( V_8 , F_5 ( V_24 ) ) ;
struct V_59 * V_60 = F_40 ( V_8 ) ;
int V_47 ;
int V_61 ;
if ( V_11 -> V_14 )
V_61 = F_41 ( V_8 , V_16 ) ;
else
V_61 = F_42 ( V_58 ) ;
V_47 = F_43 ( V_8 ,
F_44 ( V_24 ) ,
V_61 ,
V_16 -> V_11 -> V_62 ) ;
if ( V_47 < 0 )
F_45 ( V_60 , L_1 ) ;
return V_47 ;
}
static int F_46 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_47 ( F_2 ( V_24 ) , F_44 ( V_24 ) ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_47 ;
V_47 = F_18 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_34 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_35 ( V_24 , V_4 , V_6 ) ;
if ( V_47 < 0 )
return V_47 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_6 ( V_24 ) ;
F_50 ( F_44 ( & V_16 -> V_24 ) ) ;
F_13 ( V_24 , V_63 , 0x1 ) ;
F_13 ( V_24 , V_64 , 0x11 ) ;
return F_22 ( V_24 , V_4 , V_6 ) ;
}
static int F_51 ( struct V_1 * V_24 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_16 = F_6 ( V_24 ) ;
F_13 ( V_24 , V_63 , 0 ) ;
F_13 ( V_24 , V_64 , 0 ) ;
F_52 ( F_44 ( & V_16 -> V_24 ) ) ;
return F_23 ( V_24 , V_4 , V_6 ) ;
}
struct V_1 * F_53 ( struct V_7 * V_8 , int V_45 )
{
if ( F_54 ( V_45 < 0 || V_45 >= F_55 ( V_8 ) ) )
V_45 = 0 ;
return & ( (struct V_15 * ) ( V_8 -> V_16 ) + V_45 ) -> V_24 ;
}
static void F_56 ( struct V_65 * V_66 ,
const struct V_67 * V_68 ,
struct V_7 * V_8 )
{
struct V_69 * V_70 ;
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_71 * V_72 ;
struct V_59 * V_60 = & V_66 -> V_60 ;
int V_73 ;
if ( ! V_68 )
return;
V_70 = F_57 ( V_60 -> V_74 , L_2 ) ;
if ( ! V_70 )
return;
V_73 = F_58 ( V_70 ) ;
if ( ! V_73 )
return;
V_72 = F_59 ( V_60 ,
sizeof( struct V_71 ) * V_73 ,
V_75 ) ;
if ( ! V_72 ) {
F_45 ( V_60 , L_3 ) ;
return;
}
V_11 -> V_72 = V_72 ;
V_11 -> V_76 = V_73 ;
}
int F_60 ( struct V_65 * V_66 ,
const struct V_67 * V_68 ,
struct V_7 * V_8 )
{
struct V_10 * V_11 = F_4 ( V_8 ) ;
struct V_59 * V_60 = F_40 ( V_8 ) ;
struct V_15 * V_16 ;
struct V_77 * V_78 ;
struct V_39 * V_39 ;
char V_79 [ V_80 ] ;
int V_81 , V_73 ;
F_56 ( V_66 , V_68 , V_8 ) ;
V_73 = V_11 -> V_76 ;
if ( ! V_73 )
return 0 ;
V_16 = F_59 ( V_60 , sizeof( * V_16 ) * V_73 , V_75 ) ;
if ( ! V_16 ) {
F_45 ( V_60 , L_4 ) ;
return - V_82 ;
}
V_8 -> V_83 = V_73 ;
V_8 -> V_16 = V_16 ;
F_61 (src, priv, i) {
snprintf ( V_79 , V_80 , L_5 , V_81 ) ;
V_39 = F_62 ( V_60 , V_79 ) ;
if ( F_63 ( V_39 ) ) {
snprintf ( V_79 , V_80 , L_6 , V_81 ) ;
V_39 = F_62 ( V_60 , V_79 ) ;
}
if ( F_63 ( V_39 ) )
return F_64 ( V_39 ) ;
V_16 -> V_11 = & V_11 -> V_72 [ V_81 ] ;
V_16 -> V_39 = V_39 ;
V_78 = & V_84 ;
if ( F_7 ( V_16 ) ) {
if ( F_65 ( V_8 ) )
V_78 = & V_85 ;
if ( F_12 ( V_8 ) )
V_78 = & V_86 ;
}
F_66 ( V_8 , & V_16 -> V_24 , V_78 , V_87 , V_81 ) ;
F_67 ( V_60 , L_7 , V_81 ) ;
}
return 0 ;
}
