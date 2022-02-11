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
int V_8 = V_15 -> V_16 . integer . V_16 [ 0 ] ;
if ( V_8 > 1 )
return - V_17 ;
V_4 -> V_8 = V_8 ;
return F_1 ( V_2 ) ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 -> V_16 . integer . V_16 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_9 ( struct V_18 * V_19 ,
int V_20 , unsigned int V_21 , int V_22 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_23 = V_21 ;
return 0 ;
}
static int F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
struct V_18 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_29 = F_11 ( V_27 ) , V_30 = 256 ;
T_1 V_31 ;
if ( V_29 )
V_30 = V_4 -> V_23 / V_29 ;
else
return - V_17 ;
switch ( V_30 ) {
case 1024 :
V_31 = ( 0x2 << 5 ) ;
break;
case 512 :
V_31 = ( 0x1 << 5 ) ;
break;
case 256 :
V_31 = ( 0x0 << 5 ) ;
break;
default:
F_12 ( V_2 -> V_10 , L_2 , V_30 ) ;
return - V_17 ;
}
F_5 ( V_2 , V_32 , ( 0x3 << 5 ) , V_31 ) ;
if ( V_25 -> V_33 == V_34 ) {
V_4 -> V_9 = V_29 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_13 ( struct V_18 * V_19 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_36 ;
int V_37 ;
switch ( V_35 & V_38 ) {
case V_39 :
V_36 = ( 0x3 << 5 ) ;
break;
case V_40 :
V_36 = ( 0x2 << 5 ) ;
break;
case V_41 :
V_36 = ( 0x0 << 5 ) ;
break;
case V_42 :
V_36 = ( 0x1 << 5 ) ;
break;
default:
return - V_17 ;
}
V_37 = F_5 ( V_2 , V_43 , ( 0x3 << 5 ) , V_36 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static int F_14 ( struct V_18 * V_19 ,
unsigned int V_35 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_44 = 0 ;
switch ( V_35 & V_38 ) {
case V_39 :
V_44 = 0x02 ;
break;
case V_40 :
V_44 = 0x01 ;
break;
default:
return - V_17 ;
}
return F_15 ( V_2 , V_45 , V_44 ) ;
}
static int F_16 ( struct V_18 * V_28 , int V_46 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
return F_5 ( V_2 , V_11 , 0x20 , V_46 ? 0x20 : 0 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_47 V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_49 * V_50 = V_2 -> V_10 -> V_51 ;
int V_37 ;
switch ( V_48 ) {
case V_52 :
F_5 ( V_2 , V_11 , 0x20 , 0 ) ;
break;
case V_53 :
F_5 ( V_2 , V_11 , 0x20 , 0x20 ) ;
break;
case V_54 :
if ( F_18 ( V_2 ) == V_55 ) {
if ( V_50 && F_19 ( V_50 -> V_56 ) )
F_20 ( V_50 -> V_56 , 1 ) ;
F_21 ( 1 ) ;
if ( V_50 && F_19 ( V_50 -> V_57 ) )
F_20 ( V_50 -> V_57 , 1 ) ;
F_21 ( 1 ) ;
V_37 = F_22 ( V_4 -> V_58 ) ;
if ( V_37 ) {
F_12 ( V_2 -> V_10 ,
L_3 , V_37 ) ;
return V_37 ;
}
}
F_5 ( V_2 , V_59 , 0x80 , 0x80 ) ;
F_5 ( V_2 , V_60 , 0x80 , 0 ) ;
break;
case V_55 :
F_5 ( V_2 , V_59 , 0x80 , 0 ) ;
if ( V_50 && F_19 ( V_50 -> V_57 ) )
F_20 ( V_50 -> V_57 , 0 ) ;
if ( V_50 && F_19 ( V_50 -> V_56 ) )
F_20 ( V_50 -> V_56 , 0 ) ;
F_23 ( V_4 -> V_58 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_61 * V_62 ,
const struct V_63 * V_64 )
{
struct V_49 * V_50 = V_62 -> V_10 . V_51 ;
struct V_3 * V_4 ;
int V_37 ;
V_4 = F_25 ( & V_62 -> V_10 , sizeof( struct V_3 ) ,
V_65 ) ;
if ( ! V_4 )
return - V_66 ;
V_4 -> V_58 = F_26 ( V_62 , & V_67 ) ;
if ( F_27 ( V_4 -> V_58 ) )
return F_28 ( V_4 -> V_58 ) ;
if ( V_50 ) {
if ( F_19 ( V_50 -> V_56 ) ) {
V_37 = F_29 ( V_50 -> V_56 ,
V_68 , L_4 ) ;
if ( V_37 )
goto V_69;
}
if ( F_19 ( V_50 -> V_57 ) ) {
V_37 = F_29 ( V_50 -> V_57 ,
V_68 , L_5 ) ;
if ( V_37 )
goto V_70;
F_30 ( 1 ) ;
F_20 ( V_50 -> V_57 , 1 ) ;
}
}
F_31 ( V_62 , V_4 ) ;
V_37 = F_32 ( & V_62 -> V_10 , & V_71 ,
V_72 , F_3 ( V_72 ) ) ;
if ( V_37 != 0 )
goto V_73;
return 0 ;
V_73:
if ( V_50 ) {
if ( F_19 ( V_50 -> V_56 ) )
F_20 ( V_50 -> V_56 , 0 ) ;
if ( F_19 ( V_50 -> V_57 ) )
F_33 ( V_50 -> V_57 ) ;
}
V_70:
if ( V_50 && F_19 ( V_50 -> V_56 ) )
F_33 ( V_50 -> V_56 ) ;
V_69:
return V_37 ;
}
static int F_34 ( struct V_61 * V_62 )
{
struct V_49 * V_50 = V_62 -> V_10 . V_51 ;
F_35 ( & V_62 -> V_10 ) ;
if ( V_50 ) {
if ( F_19 ( V_50 -> V_56 ) ) {
F_20 ( V_50 -> V_56 , 0 ) ;
F_33 ( V_50 -> V_56 ) ;
}
if ( F_19 ( V_50 -> V_57 ) )
F_33 ( V_50 -> V_57 ) ;
}
return 0 ;
}
