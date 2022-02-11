static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
int V_7 ;
if ( V_3 == 0 )
V_6 = 0 ;
else
V_6 = F_3 ( V_3 , 6000 ) - 1 ;
V_7 = F_4 ( V_5 -> V_8 , V_9 , F_5 ( V_6 ) ) ;
if ( V_7 < 0 )
F_6 ( V_5 -> V_10 , L_1 , V_7 ) ;
return V_7 ;
}
static int F_7 ( struct V_4 * V_5 ,
struct V_11 * V_12 )
{
int V_7 ;
T_1 V_13 = 0 ;
int V_14 ;
if ( ! V_12 -> V_15 )
goto V_16;
V_13 |= V_17 ;
V_14 = F_8 ( V_12 -> V_18 ) ;
V_7 = F_4 ( V_5 -> V_8 , V_19 , V_14 ) ;
if ( V_7 < 0 ) {
F_6 ( V_5 -> V_10 , L_2 , V_7 ) ;
return V_7 ;
}
if ( V_12 -> V_20 )
V_13 |= V_21 ;
if ( V_12 -> V_22 ) {
unsigned int V_23 ;
V_7 = F_9 ( V_5 -> V_8 , V_24 , & V_23 ) ;
if ( V_7 < 0 ) {
F_6 ( V_5 -> V_10 , L_3 , V_7 ) ;
return V_7 ;
}
if ( ! ( V_23 & V_25 ) ) {
V_14 = F_8 ( V_12 -> V_22 ) ;
V_7 = F_4 ( V_5 -> V_8 , V_24 ,
V_14 ) ;
if ( V_7 < 0 ) {
F_6 ( V_5 -> V_10 ,
L_4 , V_7 ) ;
return V_7 ;
}
}
}
V_16:
V_7 = F_4 ( V_5 -> V_8 , V_26 , V_13 ) ;
if ( V_7 < 0 )
F_6 ( V_5 -> V_10 , L_5 , V_7 ) ;
return V_7 ;
}
static bool F_10 ( struct V_27 * V_10 , unsigned int V_28 )
{
switch ( V_28 ) {
case V_29 :
case V_30 :
case V_31 :
return true ;
default:
return false ;
}
}
static bool F_11 ( struct V_27 * V_10 , unsigned int V_28 )
{
switch ( V_28 ) {
case 0x08 ... 0x0F :
return false ;
default:
return true ;
}
}
static bool F_12 ( struct V_27 * V_10 , unsigned int V_28 )
{
switch ( V_28 ) {
case V_32 :
case V_19 :
case V_24 :
case V_26 :
case V_33 :
case V_9 :
return true ;
default:
return false ;
}
}
static struct V_11 *
F_13 ( struct V_27 * V_10 ,
const struct V_34 * V_35 )
{
struct V_11 * V_12 ;
struct V_36 * V_37 = V_10 -> V_38 ;
V_12 = F_14 ( V_10 , sizeof( * V_12 ) , V_39 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_40 = F_15 ( V_10 , V_10 -> V_38 ,
V_35 ) ;
if ( ! V_12 -> V_40 ) {
F_6 ( V_10 , L_6 ) ;
return NULL ;
}
V_12 -> V_15 =
F_16 ( V_37 , L_7 ) ;
V_12 -> V_20 = F_16 ( V_37 , L_8 ) ;
V_12 -> V_18 = V_12 -> V_40 -> V_41 . V_42 ? :
V_43 ;
V_12 -> V_22 = V_12 -> V_40 -> V_41 . V_44 ? :
V_45 ;
return V_12 ;
}
static struct V_11 *
F_13 ( struct V_27 * V_10 ,
const struct V_34 * V_35 )
{
return NULL ;
}
static int F_17 ( struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_7 ;
struct V_50 V_51 = { } ;
if ( V_47 -> V_10 . V_38 ) {
const struct V_52 * V_53 ;
V_53 = F_18 ( F_19 ( V_54 ) ,
& V_47 -> V_10 ) ;
if ( ! V_53 ) {
F_6 ( & V_47 -> V_10 , L_9 ) ;
return - V_55 ;
}
}
V_5 = F_14 ( & V_47 -> V_10 , sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return - V_56 ;
V_5 -> V_10 = & V_47 -> V_10 ;
V_5 -> V_35 . V_57 = V_47 -> V_57 ;
V_5 -> V_35 . V_49 = 0 ;
V_5 -> V_35 . V_3 = V_58 ;
V_5 -> V_35 . V_42 = V_43 ;
V_5 -> V_35 . V_59 = V_60 ;
V_5 -> V_35 . V_61 = V_62 ;
V_5 -> V_35 . V_63 = V_64 + 1 ;
V_5 -> V_35 . V_65 = & V_66 ;
V_5 -> V_35 . type = V_67 ;
V_5 -> V_35 . V_68 = V_69 ;
V_12 = F_20 ( & V_47 -> V_10 ) ;
if ( ! V_12 && V_47 -> V_10 . V_38 )
V_12 = F_13 ( & V_47 -> V_10 , & V_5 -> V_35 ) ;
if ( ! V_12 ) {
F_6 ( & V_47 -> V_10 , L_10 ) ;
return - V_70 ;
}
if ( V_12 -> V_15 ) {
if ( ( V_12 -> V_18 < V_43 ) ||
( V_12 -> V_18 > V_45 ) ) {
F_6 ( & V_47 -> V_10 , L_11 ) ;
return - V_70 ;
}
if ( ( V_12 -> V_22 ) &&
( ( V_12 -> V_22 < V_43 ) ||
( V_12 -> V_22 > V_45 ) ) ) {
F_6 ( & V_47 -> V_10 , L_12 ) ;
return - V_70 ;
}
}
if ( V_12 -> V_15 )
V_5 -> V_35 . V_71 = V_19 ;
else
V_5 -> V_35 . V_71 = V_32 ;
V_5 -> V_35 . V_72 = V_73 ;
V_5 -> V_8 = F_21 ( V_47 , & V_74 ) ;
if ( F_22 ( V_5 -> V_8 ) ) {
V_7 = F_23 ( V_5 -> V_8 ) ;
F_6 ( & V_47 -> V_10 , L_13 , V_7 ) ;
return V_7 ;
}
F_24 ( V_47 , V_5 ) ;
V_7 = F_7 ( V_5 , V_12 ) ;
if ( V_7 < 0 ) {
F_6 ( V_5 -> V_10 , L_14 , V_7 ) ;
return V_7 ;
}
V_51 . V_10 = & V_47 -> V_10 ;
V_51 . V_75 = V_12 -> V_40 ;
V_51 . V_76 = V_5 ;
V_51 . V_8 = V_5 -> V_8 ;
V_51 . V_38 = V_47 -> V_10 . V_38 ;
V_2 = F_25 ( & V_47 -> V_10 , & V_5 -> V_35 , & V_51 ) ;
if ( F_22 ( V_2 ) ) {
F_6 ( V_5 -> V_10 , L_15 ) ;
return F_23 ( V_2 ) ;
}
V_5 -> V_2 = V_2 ;
return 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_77 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_77 ) ;
}
