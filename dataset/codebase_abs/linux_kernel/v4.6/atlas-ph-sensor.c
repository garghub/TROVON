static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 , V_5 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , bool V_6 )
{
return F_4 ( V_2 -> V_4 , V_7 ,
V_8 ,
V_6 ? V_8 : 0 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_11 ;
V_11 = F_7 ( V_10 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_8 ( & V_2 -> V_12 -> V_13 ) ;
if ( V_11 < 0 ) {
F_9 ( & V_2 -> V_12 -> V_13 ) ;
return V_11 ;
}
return F_3 ( V_2 , true ) ;
}
static int F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_11 ;
V_11 = F_11 ( V_10 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_3 ( V_2 , false ) ;
if ( V_11 )
return V_11 ;
F_12 ( & V_2 -> V_12 -> V_13 ) ;
return F_13 ( & V_2 -> V_12 -> V_13 ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_15 ( V_15 , struct V_1 , V_15 ) ;
F_16 ( V_2 -> V_16 ) ;
}
static T_1 F_17 ( int V_17 , void * V_18 )
{
struct V_19 * V_20 = V_18 ;
struct V_9 * V_10 = V_20 -> V_10 ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
int V_11 ;
V_11 = F_18 ( V_2 -> V_4 , V_21 ,
( V_22 * ) & V_2 -> V_23 , sizeof( V_2 -> V_23 [ 0 ] ) ) ;
if ( ! V_11 )
F_19 ( V_10 , V_2 -> V_23 ,
F_20 () ) ;
F_21 ( V_10 -> V_16 ) ;
return V_24 ;
}
static T_1 F_22 ( int V_17 , void * V_18 )
{
struct V_9 * V_10 = V_18 ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
F_23 ( & V_2 -> V_15 ) ;
return V_24 ;
}
static int F_24 ( struct V_1 * V_2 , T_2 * V_25 )
{
struct V_26 * V_13 = & V_2 -> V_12 -> V_13 ;
int V_27 = F_25 ( V_13 ) ;
int V_11 ;
V_11 = F_8 ( V_13 ) ;
if ( V_11 < 0 ) {
F_9 ( V_13 ) ;
return V_11 ;
}
if ( V_27 )
F_26 ( V_28 ,
V_28 + 100000 ) ;
V_11 = F_18 ( V_2 -> V_4 , V_21 ,
( V_22 * ) V_25 , sizeof( * V_25 ) ) ;
F_12 ( V_13 ) ;
F_13 ( V_13 ) ;
return V_11 ;
}
static int F_27 ( struct V_9 * V_10 ,
struct V_29 const * V_30 ,
int * V_25 , int * V_31 , long V_32 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
switch ( V_32 ) {
case V_33 : {
int V_11 ;
T_2 V_34 ;
switch ( V_30 -> type ) {
case V_35 :
V_11 = F_18 ( V_2 -> V_4 , V_30 -> V_36 ,
( V_22 * ) & V_34 , sizeof( V_34 ) ) ;
break;
case V_37 :
F_28 ( & V_10 -> V_38 ) ;
if ( F_29 ( V_10 ) )
V_11 = - V_39 ;
else
V_11 = F_24 ( V_2 , & V_34 ) ;
F_30 ( & V_10 -> V_38 ) ;
break;
default:
V_11 = - V_40 ;
}
if ( ! V_11 ) {
* V_25 = F_31 ( V_34 ) ;
V_11 = V_41 ;
}
return V_11 ;
}
case V_42 :
switch ( V_30 -> type ) {
case V_35 :
* V_25 = 1 ;
* V_31 = 100 ;
break;
case V_37 :
* V_25 = 1 ;
* V_31 = 1000 ;
break;
default:
return - V_40 ;
}
return V_43 ;
}
return - V_40 ;
}
static int F_32 ( struct V_9 * V_10 ,
struct V_29 const * V_30 ,
int V_25 , int V_31 , long V_32 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
T_2 V_34 = F_33 ( V_25 ) ;
if ( V_31 != 0 || V_25 < 0 || V_25 > 20000 )
return - V_40 ;
if ( V_32 != V_33 || V_30 -> type != V_35 )
return - V_40 ;
return F_34 ( V_2 -> V_4 , V_30 -> V_36 ,
& V_34 , sizeof( V_34 ) ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_26 * V_13 = & V_2 -> V_12 -> V_13 ;
int V_11 ;
unsigned int V_25 ;
V_11 = F_36 ( V_2 -> V_4 , V_44 , & V_25 ) ;
if ( V_11 )
return V_11 ;
if ( ! ( V_25 & V_45 ) ) {
F_37 ( V_13 , L_1 ) ;
return 0 ;
}
if ( ! ( V_25 & V_46 ) )
F_37 ( V_13 , L_2 ) ;
if ( ! ( V_25 & V_47 ) )
F_37 ( V_13 , L_3 ) ;
if ( ! ( V_25 & V_48 ) )
F_37 ( V_13 , L_4 ) ;
return 0 ;
}
static int F_38 ( struct V_49 * V_12 ,
const struct V_50 * V_51 )
{
struct V_1 * V_2 ;
struct V_52 * V_16 ;
struct V_9 * V_10 ;
int V_11 ;
V_10 = F_39 ( & V_12 -> V_13 , sizeof( * V_2 ) ) ;
if ( ! V_10 )
return - V_53 ;
V_10 -> V_54 = & V_55 ;
V_10 -> V_56 = V_57 ;
V_10 -> V_58 = V_59 ;
V_10 -> V_60 = F_40 ( V_59 ) ;
V_10 -> V_61 = V_62 | V_63 ;
V_10 -> V_13 . V_64 = & V_12 -> V_13 ;
V_16 = F_41 ( & V_12 -> V_13 , L_5 ,
V_10 -> V_56 , V_10 -> V_51 ) ;
if ( ! V_16 )
return - V_53 ;
V_2 = F_6 ( V_10 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_16 = V_16 ;
V_16 -> V_13 . V_64 = V_10 -> V_13 . V_64 ;
V_16 -> V_65 = & V_66 ;
F_42 ( V_16 , V_10 ) ;
F_43 ( V_12 , V_10 ) ;
V_2 -> V_4 = F_44 ( V_12 , & V_67 ) ;
if ( F_45 ( V_2 -> V_4 ) ) {
F_46 ( & V_12 -> V_13 , L_6 ) ;
return F_47 ( V_2 -> V_4 ) ;
}
V_11 = F_48 ( & V_12 -> V_13 ) ;
if ( V_11 )
return V_11 ;
if ( V_12 -> V_17 <= 0 ) {
F_46 ( & V_12 -> V_13 , L_7 ) ;
return - V_40 ;
}
V_11 = F_35 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_49 ( V_16 ) ;
if ( V_11 ) {
F_46 ( & V_12 -> V_13 , L_8 ) ;
return V_11 ;
}
V_11 = F_50 ( V_10 , & V_68 ,
& F_17 , & V_69 ) ;
if ( V_11 ) {
F_46 ( & V_12 -> V_13 , L_9 ) ;
goto V_70;
}
F_51 ( & V_2 -> V_15 , F_14 ) ;
V_11 = F_52 ( & V_12 -> V_13 , V_12 -> V_17 ,
NULL , F_22 ,
V_71 |
V_72 | V_73 ,
L_10 ,
V_10 ) ;
if ( V_11 ) {
F_46 ( & V_12 -> V_13 , L_11 , V_12 -> V_17 ) ;
goto V_74;
}
V_11 = F_1 ( V_2 , 1 ) ;
if ( V_11 ) {
F_46 ( & V_12 -> V_13 , L_12 ) ;
goto V_74;
}
F_53 ( & V_12 -> V_13 ) ;
F_54 ( & V_12 -> V_13 , 2500 ) ;
F_55 ( & V_12 -> V_13 ) ;
V_11 = F_56 ( V_10 ) ;
if ( V_11 ) {
F_46 ( & V_12 -> V_13 , L_13 ) ;
goto V_75;
}
return 0 ;
V_75:
F_57 ( & V_12 -> V_13 ) ;
F_1 ( V_2 , 0 ) ;
V_74:
F_58 ( V_10 ) ;
V_70:
F_59 ( V_2 -> V_16 ) ;
return V_11 ;
}
static int F_60 ( struct V_49 * V_12 )
{
struct V_9 * V_10 = F_61 ( V_12 ) ;
struct V_1 * V_2 = F_6 ( V_10 ) ;
F_62 ( V_10 ) ;
F_58 ( V_10 ) ;
F_59 ( V_2 -> V_16 ) ;
F_57 ( & V_12 -> V_13 ) ;
F_63 ( & V_12 -> V_13 ) ;
F_9 ( & V_12 -> V_13 ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_64 ( struct V_26 * V_13 )
{
struct V_1 * V_2 =
F_6 ( F_61 ( F_65 ( V_13 ) ) ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_66 ( struct V_26 * V_13 )
{
struct V_1 * V_2 =
F_6 ( F_61 ( F_65 ( V_13 ) ) ) ;
return F_1 ( V_2 , 1 ) ;
}
