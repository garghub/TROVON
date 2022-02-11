int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_7 = F_3 ( V_6 ) ;
int V_8 = F_4 ( V_2 ) ;
F_5 ( V_2 , V_9 , ( 1 << V_8 ) ,
V_7 ? 0 : ( 1 << V_8 ) ) ;
if ( F_6 ( V_2 ) ) {
int V_10 = - 1 ;
switch ( V_8 ) {
case 1 :
V_10 = 0 ;
break;
case 2 :
V_10 = 2 ;
break;
case 4 :
V_10 = 16 ;
break;
}
if ( V_10 >= 0 )
F_5 ( V_2 , V_11 ,
0x3 << V_10 ,
F_7 ( V_4 ) ?
0x2 << V_10 : 0x1 << V_10 ) ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = F_9 ( V_2 ) ;
if ( F_10 ( V_13 ) )
F_11 ( V_2 , V_14 , 0x0f000000 ) ;
return 0 ;
}
unsigned int F_12 ( struct V_12 * V_13 ,
struct V_5 * V_6 ,
struct V_15 * V_16 )
{
struct V_1 * V_7 = F_3 ( V_6 ) ;
struct V_17 * V_18 ;
unsigned int V_19 = 0 ;
if ( V_7 ) {
V_18 = F_13 ( V_7 ) ;
V_19 = F_14 ( V_18 ) ;
}
if ( ! V_19 )
V_19 = V_16 -> V_19 ;
return V_19 ;
}
static int F_15 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_20 ) ;
struct V_15 * V_16 = F_16 ( V_6 ) ;
struct V_17 * V_18 = F_13 ( V_20 ) ;
T_1 V_21 = F_14 ( V_18 ) ;
T_1 V_22 = 0 ;
if ( V_21 )
V_22 = 0x0400000 / V_21 * V_16 -> V_19 ;
F_11 ( V_20 , V_23 , 0 ) ;
F_11 ( V_20 , V_23 , 1 ) ;
F_11 ( V_20 , V_24 , 1 ) ;
F_11 ( V_20 , V_25 , F_17 ( V_20 ) ) ;
if ( V_22 ) {
F_11 ( V_20 , V_26 , 1 ) ;
F_11 ( V_20 , V_27 , V_22 ) ;
}
F_11 ( V_20 , V_28 , 1 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = F_13 ( V_20 ) ;
F_19 ( V_18 -> V_29 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = F_13 ( V_20 ) ;
F_21 ( V_18 -> V_29 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = F_13 ( V_20 ) ;
F_11 ( V_20 , V_24 , 0 ) ;
if ( F_14 ( V_18 ) )
F_11 ( V_20 , V_30 , 1 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = F_13 ( V_20 ) ;
if ( F_14 ( V_18 ) )
F_11 ( V_20 , V_30 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_20 ) ;
struct V_31 {
T_1 V_32 ;
int V_10 ;
} V_33 [] = {
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
T_1 V_32 ;
T_1 V_34 ;
int V_35 ;
V_35 = F_4 ( V_20 ) ;
if ( V_35 < 0 || V_35 >= F_25 ( V_33 ) )
return - V_36 ;
V_34 = F_26 ( V_4 , V_6 ) ? 0x1 : 0x2 ;
V_34 = V_34 << V_33 [ V_35 ] . V_10 ;
V_32 = V_33 [ V_35 ] . V_32 << V_33 [ V_35 ] . V_10 ;
F_5 ( V_20 , V_37 , V_32 , V_34 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_20 ) ;
struct V_12 * V_13 = F_9 ( V_20 ) ;
struct V_17 * V_18 = F_13 ( V_20 ) ;
struct V_15 * V_16 = F_16 ( V_6 ) ;
T_1 V_21 = F_14 ( V_18 ) ;
T_1 V_32 ;
T_1 V_34 ;
int V_10 ;
int V_35 = F_4 ( V_20 ) ;
int V_38 ;
V_10 = ( V_35 % 4 ) * 8 ;
V_32 = 0x1F << V_10 ;
V_38 = 0 ;
if ( V_21 ) {
V_34 = 0 ;
V_38 = F_28 ( V_13 , V_20 ,
V_16 -> V_19 ,
V_21 ) ;
} else if ( 8 == V_35 ) {
V_34 = V_35 << V_10 ;
} else {
V_34 = ( V_35 + 1 ) << V_10 ;
}
if ( V_38 < 0 )
return V_38 ;
switch ( V_35 / 4 ) {
case 0 :
F_5 ( V_20 , V_39 , V_32 , V_34 ) ;
break;
case 1 :
F_5 ( V_20 , V_40 , V_32 , V_34 ) ;
break;
case 2 :
F_5 ( V_20 , V_41 , V_32 , V_34 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_15 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
F_11 ( V_20 , V_42 , 0x00010110 ) ;
F_11 ( V_20 , V_43 ,
F_30 ( V_20 , V_27 ) / 100 * 98 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = F_9 ( V_20 ) ;
struct V_44 * V_45 = F_32 ( V_13 ) ;
F_33 ( V_45 , L_1 , F_34 ( V_20 ) ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_18 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_24 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_29 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_27 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_35 = F_4 ( V_20 ) ;
F_5 ( V_20 , V_46 , ( 1 << V_35 ) , ( 1 << V_35 ) ) ;
return F_22 ( V_20 , V_4 ) ;
}
static int F_37 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_35 = F_4 ( V_20 ) ;
F_5 ( V_20 , V_46 , ( 1 << V_35 ) , 0 ) ;
return F_23 ( V_20 , V_4 ) ;
}
static int F_38 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_15 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
F_11 ( V_20 , V_47 , F_17 ( V_20 ) ) ;
F_11 ( V_20 , V_48 , 1 ) ;
F_11 ( V_20 , V_42 , 0x00011110 ) ;
F_11 ( V_20 , V_49 , 0x01800000 ) ;
F_11 ( V_20 , V_50 , 0x00100060 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_20 ) ;
struct V_15 * V_16 = F_16 ( V_6 ) ;
struct V_17 * V_18 = F_13 ( V_20 ) ;
T_1 V_21 = F_14 ( V_18 ) ;
int V_38 ;
if ( V_21 )
V_38 = F_40 ( V_20 , V_4 , V_6 ,
V_16 -> V_19 ,
V_21 ) ;
else
V_38 = F_41 ( V_20 , V_4 , V_6 ) ;
return V_38 ;
}
static int F_42 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_12 * V_13 = F_9 ( V_20 ) ;
struct V_17 * V_18 = F_13 ( V_20 ) ;
struct V_44 * V_45 = F_32 ( V_13 ) ;
int V_38 ;
V_38 = F_43 ( V_13 ,
F_44 ( V_20 ) ,
F_45 ( V_13 , V_18 ) ,
V_18 -> V_51 -> V_52 ) ;
if ( V_38 < 0 )
F_46 ( V_45 , L_2 ) ;
F_33 ( V_45 , L_3 , F_34 ( V_20 ) ) ;
return V_38 ;
}
static int F_47 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
F_48 ( F_9 ( V_20 ) , F_44 ( V_20 ) ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_18 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_38 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_39 ( V_20 , V_4 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_20 ) ;
struct V_17 * V_18 = F_13 ( V_20 ) ;
T_1 V_34 = F_51 ( V_6 ) ? 0x01 : 0x11 ;
F_52 ( F_44 ( & V_18 -> V_20 ) ) ;
F_11 ( V_20 , V_53 , 0x1 ) ;
F_11 ( V_20 , V_54 , V_34 ) ;
return F_22 ( V_20 , V_4 ) ;
}
static int F_53 ( struct V_1 * V_20 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = F_13 ( V_20 ) ;
F_11 ( V_20 , V_53 , 0 ) ;
F_11 ( V_20 , V_54 , 0 ) ;
F_54 ( F_44 ( & V_18 -> V_20 ) ) ;
return F_23 ( V_20 , V_4 ) ;
}
struct V_1 * F_55 ( struct V_12 * V_13 , int V_35 )
{
if ( F_56 ( V_35 < 0 || V_35 >= F_57 ( V_13 ) ) )
V_35 = 0 ;
return & ( (struct V_17 * ) ( V_13 -> V_18 ) + V_35 ) -> V_20 ;
}
static void F_58 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
struct V_12 * V_13 )
{
struct V_59 * V_60 ;
struct V_61 * V_51 = F_59 ( V_13 ) ;
struct V_62 * V_63 ;
struct V_44 * V_45 = & V_56 -> V_45 ;
int V_64 ;
if ( ! V_58 )
return;
V_60 = F_60 ( V_45 -> V_65 , L_4 ) ;
if ( ! V_60 )
return;
V_64 = F_61 ( V_60 ) ;
if ( ! V_64 )
goto V_66;
V_63 = F_62 ( V_45 ,
sizeof( struct V_62 ) * V_64 ,
V_67 ) ;
if ( ! V_63 ) {
F_46 ( V_45 , L_5 ) ;
goto V_66;
}
V_51 -> V_63 = V_63 ;
V_51 -> V_68 = V_64 ;
V_66:
F_63 ( V_60 ) ;
}
int F_64 ( struct V_55 * V_56 ,
const struct V_57 * V_58 ,
struct V_12 * V_13 )
{
struct V_61 * V_51 = F_59 ( V_13 ) ;
struct V_44 * V_45 = F_32 ( V_13 ) ;
struct V_17 * V_18 ;
struct V_69 * V_70 ;
struct V_29 * V_29 ;
char V_71 [ V_72 ] ;
int V_73 , V_64 ;
V_70 = NULL ;
if ( F_65 ( V_13 ) )
V_70 = & V_74 ;
if ( F_10 ( V_13 ) )
V_70 = & V_75 ;
if ( ! V_70 ) {
F_46 ( V_45 , L_6 ) ;
return - V_36 ;
}
F_58 ( V_56 , V_58 , V_13 ) ;
V_64 = V_51 -> V_68 ;
if ( ! V_64 )
return 0 ;
V_18 = F_62 ( V_45 , sizeof( * V_18 ) * V_64 , V_67 ) ;
if ( ! V_18 ) {
F_46 ( V_45 , L_7 ) ;
return - V_76 ;
}
V_13 -> V_77 = V_64 ;
V_13 -> V_18 = V_18 ;
F_66 (src, priv, i) {
snprintf ( V_71 , V_72 , L_8 ,
V_78 , V_73 ) ;
V_29 = F_67 ( V_45 , V_71 ) ;
if ( F_68 ( V_29 ) )
return F_69 ( V_29 ) ;
V_18 -> V_51 = & V_51 -> V_63 [ V_73 ] ;
V_18 -> V_29 = V_29 ;
F_70 ( V_13 , & V_18 -> V_20 , V_70 , V_79 , V_73 ) ;
F_33 ( V_45 , L_9 , V_73 ) ;
}
return 0 ;
}
