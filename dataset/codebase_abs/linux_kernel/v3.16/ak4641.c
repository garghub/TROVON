static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 = 0 ;
for ( V_5 = 0 ; V_5 < F_3 ( V_7 ) ; V_5 ++ ) {
if ( V_4 -> V_8 && V_7 [ V_5 ] != 0 &&
abs ( V_7 [ V_5 ] - V_4 -> V_9 ) <
abs ( V_7 [ V_6 ] - V_4 -> V_9 ) )
V_6 = V_5 ;
if ( ! V_4 -> V_8 && V_7 [ V_5 ] == 0 )
V_6 = V_5 ;
}
F_4 ( V_2 -> V_10 , L_1 , V_6 ) ;
return F_5 ( V_2 , V_11 , 0x3 , V_6 ) ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 = V_15 -> V_16 . V_17 . V_18 [ 0 ] ;
if ( V_8 > 1 )
return - V_19 ;
V_4 -> V_8 = V_8 ;
return F_1 ( V_2 ) ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 -> V_16 . V_17 . V_18 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 ,
int V_22 , unsigned int V_23 , int V_24 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_25 = V_23 ;
return 0 ;
}
static int F_10 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_20 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_31 = F_11 ( V_29 ) , V_32 = 256 ;
T_1 V_33 ;
if ( V_31 )
V_32 = V_4 -> V_25 / V_31 ;
else
return - V_19 ;
switch ( V_32 ) {
case 1024 :
V_33 = ( 0x2 << 5 ) ;
break;
case 512 :
V_33 = ( 0x1 << 5 ) ;
break;
case 256 :
V_33 = ( 0x0 << 5 ) ;
break;
default:
F_12 ( V_2 -> V_10 , L_2 , V_32 ) ;
return - V_19 ;
}
F_5 ( V_2 , V_34 , ( 0x3 << 5 ) , V_33 ) ;
if ( V_27 -> V_35 == V_36 ) {
V_4 -> V_9 = V_31 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_13 ( struct V_20 * V_21 ,
unsigned int V_37 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_1 V_38 ;
int V_39 ;
switch ( V_37 & V_40 ) {
case V_41 :
V_38 = ( 0x3 << 5 ) ;
break;
case V_42 :
V_38 = ( 0x2 << 5 ) ;
break;
case V_43 :
V_38 = ( 0x0 << 5 ) ;
break;
case V_44 :
V_38 = ( 0x1 << 5 ) ;
break;
default:
return - V_19 ;
}
V_39 = F_5 ( V_2 , V_45 , ( 0x3 << 5 ) , V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 ,
unsigned int V_37 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_1 V_46 = 0 ;
switch ( V_37 & V_40 ) {
case V_41 :
V_46 = 0x02 ;
break;
case V_42 :
V_46 = 0x01 ;
break;
default:
return - V_19 ;
}
return F_15 ( V_2 , V_47 , V_46 ) ;
}
static int F_16 ( struct V_20 * V_30 , int V_48 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
return F_5 ( V_2 , V_11 , 0x20 , V_48 ? 0x20 : 0 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_49 V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_51 * V_52 = V_2 -> V_10 -> V_53 ;
int V_39 ;
switch ( V_50 ) {
case V_54 :
F_5 ( V_2 , V_11 , 0x20 , 0 ) ;
break;
case V_55 :
F_5 ( V_2 , V_11 , 0x20 , 0x20 ) ;
break;
case V_56 :
if ( V_2 -> V_57 . V_58 == V_59 ) {
if ( V_52 && F_18 ( V_52 -> V_60 ) )
F_19 ( V_52 -> V_60 , 1 ) ;
F_20 ( 1 ) ;
if ( V_52 && F_18 ( V_52 -> V_61 ) )
F_19 ( V_52 -> V_61 , 1 ) ;
F_20 ( 1 ) ;
V_39 = F_21 ( V_4 -> V_62 ) ;
if ( V_39 ) {
F_12 ( V_2 -> V_10 ,
L_3 , V_39 ) ;
return V_39 ;
}
}
F_5 ( V_2 , V_63 , 0x80 , 0x80 ) ;
F_5 ( V_2 , V_64 , 0x80 , 0 ) ;
break;
case V_59 :
F_5 ( V_2 , V_63 , 0x80 , 0 ) ;
if ( V_52 && F_18 ( V_52 -> V_61 ) )
F_19 ( V_52 -> V_61 , 0 ) ;
if ( V_52 && F_18 ( V_52 -> V_60 ) )
F_19 ( V_52 -> V_60 , 0 ) ;
F_22 ( V_4 -> V_62 ) ;
break;
}
V_2 -> V_57 . V_58 = V_50 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_59 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_59 ) ;
return 0 ;
}
static int F_27 ( struct V_65 * V_66 ,
const struct V_67 * V_68 )
{
struct V_51 * V_52 = V_66 -> V_10 . V_53 ;
struct V_3 * V_4 ;
int V_39 ;
V_4 = F_28 ( & V_66 -> V_10 , sizeof( struct V_3 ) ,
V_69 ) ;
if ( ! V_4 )
return - V_70 ;
V_4 -> V_62 = F_29 ( V_66 , & V_71 ) ;
if ( F_30 ( V_4 -> V_62 ) )
return F_31 ( V_4 -> V_62 ) ;
if ( V_52 ) {
if ( F_18 ( V_52 -> V_60 ) ) {
V_39 = F_32 ( V_52 -> V_60 ,
V_72 , L_4 ) ;
if ( V_39 )
goto V_73;
}
if ( F_18 ( V_52 -> V_61 ) ) {
V_39 = F_32 ( V_52 -> V_61 ,
V_72 , L_5 ) ;
if ( V_39 )
goto V_74;
F_33 ( 1 ) ;
F_19 ( V_52 -> V_61 , 1 ) ;
}
}
F_34 ( V_66 , V_4 ) ;
V_39 = F_35 ( & V_66 -> V_10 , & V_75 ,
V_76 , F_3 ( V_76 ) ) ;
if ( V_39 != 0 )
goto V_77;
return 0 ;
V_77:
if ( V_52 ) {
if ( F_18 ( V_52 -> V_60 ) )
F_19 ( V_52 -> V_60 , 0 ) ;
if ( F_18 ( V_52 -> V_61 ) )
F_36 ( V_52 -> V_61 ) ;
}
V_74:
if ( V_52 && F_18 ( V_52 -> V_60 ) )
F_36 ( V_52 -> V_60 ) ;
V_73:
return V_39 ;
}
static int F_37 ( struct V_65 * V_66 )
{
struct V_51 * V_52 = V_66 -> V_10 . V_53 ;
F_38 ( & V_66 -> V_10 ) ;
if ( V_52 ) {
if ( F_18 ( V_52 -> V_60 ) ) {
F_19 ( V_52 -> V_60 , 0 ) ;
F_36 ( V_52 -> V_60 ) ;
}
if ( F_18 ( V_52 -> V_61 ) )
F_36 ( V_52 -> V_61 ) ;
}
return 0 ;
}
