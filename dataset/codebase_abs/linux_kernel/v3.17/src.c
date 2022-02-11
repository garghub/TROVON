int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 = F_4 ( V_2 ) ;
F_5 ( V_2 , V_11 , ( 1 << V_10 ) ,
! V_5 << V_10 ) ;
if ( F_6 ( V_2 ) ) {
int V_12 = - 1 ;
switch ( V_10 ) {
case 1 :
V_12 = 0 ;
break;
case 2 :
V_12 = 2 ;
break;
case 4 :
V_12 = 16 ;
break;
}
if ( V_12 >= 0 )
F_5 ( V_2 , V_13 ,
0x3 << V_12 ,
F_7 ( V_4 ) ?
0x2 << V_12 : 0x1 << V_12 ) ;
}
if ( V_5 ) {
T_1 V_14 = 0x76543210 ;
T_1 V_15 = ~ 0 ;
F_8 ( V_2 , V_16 ,
F_9 ( V_2 ) ) ;
F_8 ( V_2 , V_17 , 1 ) ;
F_8 ( V_2 , V_18 , 0x1 ) ;
V_15 <<= V_9 -> V_19 * 4 ;
V_14 = V_14 & V_15 ;
switch ( V_9 -> V_20 ) {
case 16 :
V_14 |= 0x67452301 & ~ V_15 ;
break;
case 32 :
V_14 |= 0x76543210 & ~ V_15 ;
break;
}
F_8 ( V_2 , V_21 , V_14 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
if ( V_5 )
F_8 ( V_2 , V_18 , 0 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_2 ) ;
if ( F_13 ( V_23 ) )
F_8 ( V_2 , V_24 , 0x0f000000 ) ;
return 0 ;
}
unsigned int F_14 ( struct V_22 * V_23 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_25 = F_15 ( V_7 ) ;
struct V_26 * V_27 ;
unsigned int V_28 = 0 ;
if ( V_25 ) {
V_27 = F_16 ( V_25 ) ;
V_28 = F_17 ( V_27 ) ;
}
if ( ! V_28 )
V_28 = V_9 -> V_28 ;
return V_28 ;
}
static int F_18 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_26 * V_27 = F_16 ( V_29 ) ;
T_1 V_30 = F_17 ( V_27 ) ;
T_1 V_31 = 0 ;
if ( V_30 )
V_31 = 0x0400000 / V_30 * V_9 -> V_28 ;
F_8 ( V_29 , V_32 , 0 ) ;
F_8 ( V_29 , V_32 , 1 ) ;
F_8 ( V_29 , V_33 , 1 ) ;
F_8 ( V_29 , V_34 , F_9 ( V_29 ) ) ;
if ( V_31 ) {
F_8 ( V_29 , V_35 , 1 ) ;
F_8 ( V_29 , V_36 , V_31 ) ;
}
F_8 ( V_29 , V_37 , 1 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_16 ( V_29 ) ;
F_20 ( V_27 -> V_38 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_16 ( V_29 ) ;
F_22 ( V_27 -> V_38 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_16 ( V_29 ) ;
F_8 ( V_29 , V_33 , 0 ) ;
if ( F_17 ( V_27 ) )
F_8 ( V_29 , V_39 , 1 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_16 ( V_29 ) ;
if ( F_17 ( V_27 ) )
F_8 ( V_29 , V_39 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_40 {
T_1 V_15 ;
int V_12 ;
} V_41 [] = {
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
T_1 V_15 ;
T_1 V_14 ;
int V_42 ;
V_42 = F_4 ( V_29 ) ;
if ( V_42 < 0 || V_42 >= F_26 ( V_41 ) )
return - V_43 ;
V_14 = F_27 ( V_4 , V_7 ) ? 0x1 : 0x2 ;
V_14 = V_14 << V_41 [ V_42 ] . V_12 ;
V_15 = V_41 [ V_42 ] . V_15 << V_41 [ V_42 ] . V_12 ;
F_5 ( V_29 , V_44 , V_15 , V_14 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_26 * V_27 = F_16 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_1 V_30 = F_17 ( V_27 ) ;
T_1 V_15 ;
T_1 V_14 ;
int V_12 ;
int V_42 = F_4 ( V_29 ) ;
int V_45 ;
V_12 = ( V_42 % 4 ) * 8 ;
V_15 = 0x1F << V_12 ;
V_45 = 0 ;
if ( V_30 ) {
V_14 = 0 ;
V_45 = F_29 ( V_23 , V_29 ,
V_9 -> V_28 ,
V_30 ) ;
} else if ( 8 == V_42 ) {
V_14 = V_42 << V_12 ;
} else {
V_14 = ( V_42 + 1 ) << V_12 ;
}
if ( V_45 < 0 )
return V_45 ;
switch ( V_42 / 4 ) {
case 0 :
F_5 ( V_29 , V_46 , V_15 , V_14 ) ;
break;
case 1 :
F_5 ( V_29 , V_47 , V_15 , V_14 ) ;
break;
case 2 :
F_5 ( V_29 , V_48 , V_15 , V_14 ) ;
break;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_45 ;
V_45 = F_18 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
F_8 ( V_29 , V_49 , 0x00010110 ) ;
F_8 ( V_29 , V_50 ,
F_31 ( V_29 , V_36 ) / 100 * 98 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_51 * V_52 = F_33 ( V_23 ) ;
F_34 ( V_52 , L_1 , F_35 ( V_29 ) ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_45 ;
V_45 = F_19 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_25 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_30 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_28 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_42 = F_4 ( V_29 ) ;
F_5 ( V_29 , V_53 , ( 1 << V_42 ) , ( 1 << V_42 ) ) ;
return F_23 ( V_29 , V_4 ) ;
}
static int F_38 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_42 = F_4 ( V_29 ) ;
F_5 ( V_29 , V_53 , ( 1 << V_42 ) , 0 ) ;
return F_24 ( V_29 , V_4 ) ;
}
static int F_39 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_51 * V_52 = F_33 ( V_23 ) ;
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_26 * V_27 = F_16 ( V_29 ) ;
T_2 V_54 ;
int V_45 ;
if ( ! F_17 ( V_27 ) )
V_54 = 0 ;
else if ( F_17 ( V_27 ) > V_9 -> V_28 )
V_54 = 100 * F_17 ( V_27 ) / V_9 -> V_28 ;
else
V_54 = 100 * V_9 -> V_28 / F_17 ( V_27 ) ;
if ( V_54 > 600 ) {
F_40 ( V_52 , L_2 ) ;
return - V_55 ;
}
V_45 = F_18 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
F_8 ( V_29 , V_49 , 0x00011110 ) ;
switch ( F_4 ( V_29 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
F_8 ( V_29 , V_56 , 0x02400000 ) ;
break;
default:
F_8 ( V_29 , V_56 , 0x01800000 ) ;
break;
}
F_8 ( V_29 , V_57 , 0x00100060 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_26 * V_27 = F_16 ( V_29 ) ;
T_1 V_30 = F_17 ( V_27 ) ;
int V_45 ;
if ( V_30 )
V_45 = F_42 ( V_29 , V_4 , V_7 ,
V_9 -> V_28 ,
V_30 ) ;
else
V_45 = F_43 ( V_29 , V_4 , V_7 ) ;
return V_45 ;
}
static int F_44 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_26 * V_27 = F_16 ( V_29 ) ;
struct V_51 * V_52 = F_33 ( V_23 ) ;
int V_45 ;
V_45 = F_45 ( V_23 ,
F_46 ( V_29 ) ,
F_47 ( V_23 , V_27 ) ,
V_27 -> V_58 -> V_59 ) ;
if ( V_45 < 0 )
F_40 ( V_52 , L_3 ) ;
F_34 ( V_52 , L_4 , F_35 ( V_29 ) ) ;
return V_45 ;
}
static int F_48 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
F_49 ( F_12 ( V_29 ) , F_46 ( V_29 ) ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_45 ;
V_45 = F_19 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_39 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_41 ( V_29 , V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_26 * V_27 = F_16 ( V_29 ) ;
T_1 V_14 = F_52 ( V_7 ) ? 0x01 : 0x11 ;
F_53 ( F_46 ( & V_27 -> V_29 ) ) ;
F_8 ( V_29 , V_60 , V_14 ) ;
return F_23 ( V_29 , V_4 ) ;
}
static int F_54 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_16 ( V_29 ) ;
F_8 ( V_29 , V_60 , 0 ) ;
F_55 ( F_46 ( & V_27 -> V_29 ) ) ;
return F_24 ( V_29 , V_4 ) ;
}
struct V_1 * F_56 ( struct V_22 * V_23 , int V_42 )
{
if ( F_57 ( V_42 < 0 || V_42 >= F_58 ( V_23 ) ) )
V_42 = 0 ;
return & ( (struct V_26 * ) ( V_23 -> V_27 ) + V_42 ) -> V_29 ;
}
static void F_59 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_22 * V_23 )
{
struct V_65 * V_66 ;
struct V_67 * V_58 = F_60 ( V_23 ) ;
struct V_68 * V_69 ;
struct V_51 * V_52 = & V_62 -> V_52 ;
int V_70 ;
if ( ! V_64 )
return;
V_66 = F_61 ( V_52 -> V_71 , L_5 ) ;
if ( ! V_66 )
return;
V_70 = F_62 ( V_66 ) ;
if ( ! V_70 )
goto V_72;
V_69 = F_63 ( V_52 ,
sizeof( struct V_68 ) * V_70 ,
V_73 ) ;
if ( ! V_69 ) {
F_40 ( V_52 , L_6 ) ;
goto V_72;
}
V_58 -> V_69 = V_69 ;
V_58 -> V_74 = V_70 ;
V_72:
F_64 ( V_66 ) ;
}
int F_65 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_22 * V_23 )
{
struct V_67 * V_58 = F_60 ( V_23 ) ;
struct V_51 * V_52 = F_33 ( V_23 ) ;
struct V_26 * V_27 ;
struct V_75 * V_76 ;
struct V_38 * V_38 ;
char V_77 [ V_78 ] ;
int V_79 , V_70 ;
V_76 = NULL ;
if ( F_66 ( V_23 ) )
V_76 = & V_80 ;
if ( F_13 ( V_23 ) )
V_76 = & V_81 ;
if ( ! V_76 ) {
F_40 ( V_52 , L_7 ) ;
return - V_43 ;
}
F_59 ( V_62 , V_64 , V_23 ) ;
V_70 = V_58 -> V_74 ;
if ( ! V_70 )
return 0 ;
V_27 = F_63 ( V_52 , sizeof( * V_27 ) * V_70 , V_73 ) ;
if ( ! V_27 ) {
F_40 ( V_52 , L_8 ) ;
return - V_82 ;
}
V_23 -> V_83 = V_70 ;
V_23 -> V_27 = V_27 ;
F_67 (src, priv, i) {
snprintf ( V_77 , V_78 , L_9 ,
V_84 , V_79 ) ;
V_38 = F_68 ( V_52 , V_77 ) ;
if ( F_69 ( V_38 ) )
return F_70 ( V_38 ) ;
V_27 -> V_58 = & V_58 -> V_69 [ V_79 ] ;
V_27 -> V_38 = V_38 ;
F_71 ( V_23 , & V_27 -> V_29 , V_76 , V_85 , V_79 ) ;
F_34 ( V_52 , L_10 , V_79 ) ;
}
return 0 ;
}
