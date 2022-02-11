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
struct V_31 * V_32 = V_27 -> V_33 ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_34 = F_11 ( V_29 ) , V_35 = 256 ;
T_1 V_36 ;
if ( V_34 )
V_35 = V_4 -> V_25 / V_34 ;
else
return - V_19 ;
switch ( V_35 ) {
case 1024 :
V_36 = ( 0x2 << 5 ) ;
break;
case 512 :
V_36 = ( 0x1 << 5 ) ;
break;
case 256 :
V_36 = ( 0x0 << 5 ) ;
break;
default:
F_12 ( V_2 -> V_10 , L_2 , V_35 ) ;
return - V_19 ;
}
F_5 ( V_2 , V_37 , ( 0x3 << 5 ) , V_36 ) ;
if ( V_27 -> V_38 == V_39 ) {
V_4 -> V_9 = V_34 ;
F_1 ( V_2 ) ;
} ;
return 0 ;
}
static int F_13 ( struct V_20 * V_21 ,
unsigned int V_40 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_1 V_41 ;
int V_42 ;
switch ( V_40 & V_43 ) {
case V_44 :
V_41 = ( 0x3 << 5 ) ;
break;
case V_45 :
V_41 = ( 0x2 << 5 ) ;
break;
case V_46 :
V_41 = ( 0x0 << 5 ) ;
break;
case V_47 :
V_41 = ( 0x1 << 5 ) ;
break;
default:
return - V_19 ;
}
V_42 = F_5 ( V_2 , V_48 , ( 0x3 << 5 ) , V_41 ) ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_21 ,
unsigned int V_40 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
T_1 V_49 = 0 ;
switch ( V_40 & V_43 ) {
case V_44 :
V_49 = 0x02 ;
break;
case V_45 :
V_49 = 0x01 ;
break;
default:
return - V_19 ;
}
return F_15 ( V_2 , V_50 , V_49 ) ;
}
static int F_16 ( struct V_20 * V_30 , int V_51 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
return F_5 ( V_2 , V_11 , 0x20 , V_51 ? 0x20 : 0 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_52 V_53 )
{
struct V_54 * V_55 = V_2 -> V_10 -> V_56 ;
int V_42 ;
switch ( V_53 ) {
case V_57 :
F_5 ( V_2 , V_11 , 0x20 , 0 ) ;
break;
case V_58 :
F_5 ( V_2 , V_11 , 0x20 , 0x20 ) ;
break;
case V_59 :
if ( V_2 -> V_60 . V_61 == V_62 ) {
if ( V_55 && F_18 ( V_55 -> V_63 ) )
F_19 ( V_55 -> V_63 , 1 ) ;
F_20 ( 1 ) ;
if ( V_55 && F_18 ( V_55 -> V_64 ) )
F_19 ( V_55 -> V_64 , 1 ) ;
F_20 ( 1 ) ;
V_42 = F_21 ( V_2 ) ;
if ( V_42 ) {
F_12 ( V_2 -> V_10 ,
L_3 , V_42 ) ;
return V_42 ;
}
}
F_5 ( V_2 , V_65 , 0x80 , 0x80 ) ;
F_5 ( V_2 , V_66 , 0x80 , 0 ) ;
break;
case V_62 :
F_5 ( V_2 , V_65 , 0x80 , 0 ) ;
if ( V_55 && F_18 ( V_55 -> V_64 ) )
F_19 ( V_55 -> V_64 , 0 ) ;
if ( V_55 && F_18 ( V_55 -> V_63 ) )
F_19 ( V_55 -> V_63 , 0 ) ;
V_2 -> V_67 = 1 ;
break;
}
V_2 -> V_60 . V_61 = V_53 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_62 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_59 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_10 -> V_56 ;
int V_42 ;
if ( V_55 ) {
if ( F_18 ( V_55 -> V_63 ) ) {
V_42 = F_25 ( V_55 -> V_63 ,
V_68 , L_4 ) ;
if ( V_42 )
goto V_69;
}
if ( F_18 ( V_55 -> V_64 ) ) {
V_42 = F_25 ( V_55 -> V_64 ,
V_68 , L_5 ) ;
if ( V_42 )
goto V_70;
F_26 ( 1 ) ;
F_19 ( V_55 -> V_64 , 1 ) ;
}
}
V_42 = F_27 ( V_2 , 8 , 8 , V_71 ) ;
if ( V_42 != 0 ) {
F_12 ( V_2 -> V_10 , L_6 , V_42 ) ;
goto V_72;
}
F_17 ( V_2 , V_59 ) ;
return 0 ;
V_72:
if ( V_55 ) {
if ( F_18 ( V_55 -> V_63 ) )
F_19 ( V_55 -> V_63 , 0 ) ;
if ( F_18 ( V_55 -> V_64 ) )
F_28 ( V_55 -> V_64 ) ;
}
V_70:
if ( V_55 && F_18 ( V_55 -> V_63 ) )
F_28 ( V_55 -> V_63 ) ;
V_69:
return V_42 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_10 -> V_56 ;
F_17 ( V_2 , V_62 ) ;
if ( V_55 ) {
if ( F_18 ( V_55 -> V_63 ) ) {
F_19 ( V_55 -> V_63 , 0 ) ;
F_28 ( V_55 -> V_63 ) ;
}
if ( F_18 ( V_55 -> V_64 ) )
F_28 ( V_55 -> V_64 ) ;
}
return 0 ;
}
static int T_2 F_30 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_3 * V_4 ;
int V_42 ;
V_4 = F_31 ( & V_74 -> V_10 , sizeof( struct V_3 ) ,
V_77 ) ;
if ( ! V_4 )
return - V_78 ;
F_32 ( V_74 , V_4 ) ;
V_42 = F_33 ( & V_74 -> V_10 , & V_79 ,
V_80 , F_3 ( V_80 ) ) ;
return V_42 ;
}
static int T_3 F_34 ( struct V_73 * V_74 )
{
F_35 ( & V_74 -> V_10 ) ;
return 0 ;
}
static int T_4 F_36 ( void )
{
int V_42 ;
V_42 = F_37 ( & V_81 ) ;
if ( V_42 != 0 )
F_38 ( L_7 , V_42 ) ;
return V_42 ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_81 ) ;
}
