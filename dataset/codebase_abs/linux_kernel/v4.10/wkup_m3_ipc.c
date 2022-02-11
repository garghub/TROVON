static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_6 ,
V_2 -> V_4 + V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_7 , int V_8 )
{
if ( F_5 ( V_8 < 0 || V_8 > V_9 ,
L_1 ) )
return;
F_2 ( V_7 , V_2 -> V_4 +
F_6 ( V_8 ) ) ;
}
static unsigned int F_7 ( struct V_1 * V_2 ,
int V_8 )
{
if ( F_5 ( V_8 < 0 || V_8 > V_9 ,
L_1 ) )
return 0 ;
return F_8 ( V_2 -> V_4 +
F_6 ( V_8 ) ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_7 ( V_2 , 2 ) ;
return V_7 & V_10 ;
}
static T_2 F_10 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_15 = 0 ;
F_1 ( V_2 ) ;
switch ( V_2 -> V_16 ) {
case V_17 :
V_15 = F_9 ( V_2 ) ;
if ( V_15 == V_18 ||
V_15 < V_19 ) {
F_11 ( V_14 , L_2 ,
V_15 ) ;
} else {
F_12 ( V_14 , L_3 , V_15 ) ;
}
V_2 -> V_16 = V_20 ;
F_13 ( & V_2 -> V_21 ) ;
break;
case V_22 :
V_2 -> V_16 = V_20 ;
F_13 ( & V_2 -> V_21 ) ;
break;
case V_23 :
F_13 ( & V_2 -> V_21 ) ;
break;
case V_24 :
F_11 ( V_14 , L_4 ) ;
}
F_3 ( V_2 ) ;
return V_25 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_3 V_26 = 0 ;
int V_27 ;
if ( ! V_2 -> V_28 ) {
F_15 ( V_14 ,
L_5 ) ;
return - V_29 ;
}
V_27 = F_16 ( V_2 -> V_28 , & V_26 ) ;
if ( V_27 < 0 ) {
F_15 ( V_14 , L_6 ,
V_30 , V_27 ) ;
return V_27 ;
}
V_27 = F_17 ( & V_2 -> V_21 ,
F_18 ( 500 ) ) ;
if ( ! V_27 ) {
F_15 ( V_14 , L_7 ) ;
V_2 -> V_16 = V_24 ;
return - V_29 ;
}
F_19 ( V_2 -> V_28 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_3 V_26 = 0 ;
int V_27 ;
if ( ! V_2 -> V_28 ) {
F_15 ( V_14 ,
L_5 ) ;
return - V_29 ;
}
V_27 = F_16 ( V_2 -> V_28 , & V_26 ) ;
if ( V_27 < 0 ) {
F_15 ( V_14 , L_6 ,
V_30 , V_27 ) ;
return V_27 ;
}
F_19 ( V_2 -> V_28 , 0 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_16 != V_17 ) &&
( V_2 -> V_16 != V_24 ) ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_31 )
{
V_2 -> V_31 = V_31 ;
}
static void F_23 ( struct V_1 * V_2 , void * V_32 )
{
V_2 -> V_33 = ( unsigned long ) V_32 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned int V_34 ;
int V_7 ;
V_7 = F_7 ( V_2 , 1 ) ;
V_34 = V_35 & V_7 ;
V_34 >>= F_25 ( V_35 ) ;
return V_34 ;
}
static int F_26 ( struct V_1 * V_2 , int V_16 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_36 ;
int V_27 = 0 ;
if ( ! F_21 ( V_2 ) )
return - V_37 ;
switch ( V_16 ) {
case V_38 :
V_36 = V_39 ;
break;
case V_40 :
V_36 = V_41 ;
break;
case V_42 :
V_36 = V_43 ;
break;
default:
return 1 ;
}
F_4 ( V_2 , V_2 -> V_33 , 0 ) ;
F_4 ( V_2 , V_36 , 1 ) ;
F_4 ( V_2 , V_2 -> V_31 , 4 ) ;
F_4 ( V_2 , V_44 , 2 ) ;
F_4 ( V_2 , V_44 , 3 ) ;
F_4 ( V_2 , V_44 , 5 ) ;
F_4 ( V_2 , V_44 , 6 ) ;
F_4 ( V_2 , V_44 , 7 ) ;
V_2 -> V_16 = V_23 ;
if ( V_16 == V_42 )
V_27 = F_20 ( V_2 ) ;
else
V_27 = F_14 ( V_2 ) ;
if ( V_27 ) {
F_15 ( V_14 , L_8 ) ;
return V_27 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_27 = 0 ;
if ( ! F_21 ( V_2 ) )
return - V_37 ;
F_4 ( V_2 , V_45 , 1 ) ;
F_4 ( V_2 , V_44 , 2 ) ;
V_2 -> V_16 = V_22 ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 ) {
F_15 ( V_14 , L_8 ) ;
return V_27 ;
}
return 0 ;
}
struct V_1 * F_28 ( void )
{
if ( V_46 )
F_29 ( V_46 -> V_14 ) ;
else
return NULL ;
return V_46 ;
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_46 )
F_31 ( V_46 -> V_14 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_27 ;
F_33 ( & V_2 -> V_47 -> V_48 ) ;
F_34 ( & V_2 -> V_21 ) ;
V_27 = F_35 ( V_2 -> V_47 ) ;
if ( V_27 )
F_15 ( V_14 , L_9 ) ;
F_36 ( 0 ) ;
}
static int F_37 ( struct V_49 * V_50 )
{
struct V_13 * V_14 = & V_50 -> V_14 ;
int V_11 , V_27 ;
T_4 V_51 ;
struct V_47 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_1 * V_2 ;
V_2 = F_38 ( V_14 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return - V_58 ;
V_54 = F_39 ( V_50 , V_59 , 0 ) ;
V_2 -> V_4 = F_40 ( V_14 , V_54 ) ;
if ( F_41 ( V_2 -> V_4 ) ) {
F_15 ( V_14 , L_10 ) ;
return F_42 ( V_2 -> V_4 ) ;
}
V_11 = F_43 ( V_50 , 0 ) ;
if ( ! V_11 ) {
F_15 ( & V_50 -> V_14 , L_11 ) ;
return - V_60 ;
}
V_27 = F_44 ( V_14 , V_11 , F_10 ,
0 , L_12 , V_2 ) ;
if ( V_27 ) {
F_15 ( V_14 , L_13 ) ;
return V_27 ;
}
V_2 -> V_61 . V_14 = V_14 ;
V_2 -> V_61 . V_62 = NULL ;
V_2 -> V_61 . V_63 = NULL ;
V_2 -> V_61 . V_64 = NULL ;
V_2 -> V_61 . V_65 = false ;
V_2 -> V_61 . V_66 = false ;
V_2 -> V_28 = F_45 ( & V_2 -> V_61 , 0 ) ;
if ( F_41 ( V_2 -> V_28 ) ) {
F_15 ( V_14 , L_14 ,
F_42 ( V_2 -> V_28 ) ) ;
return F_42 ( V_2 -> V_28 ) ;
}
if ( F_46 ( V_14 -> V_67 , L_15 , & V_51 ) ) {
F_15 ( & V_50 -> V_14 , L_16 ) ;
V_27 = - V_37 ;
goto V_68;
}
V_52 = F_47 ( V_51 ) ;
if ( ! V_52 ) {
F_15 ( & V_50 -> V_14 , L_17 ) ;
V_27 = - V_69 ;
goto V_68;
}
V_2 -> V_47 = V_52 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_16 = V_17 ;
V_2 -> V_70 = & V_71 ;
V_56 = F_48 ( ( void * ) F_32 , V_2 ,
L_18 ) ;
if ( F_41 ( V_56 ) ) {
F_15 ( V_14 , L_19 ) ;
V_27 = F_42 ( V_56 ) ;
goto V_72;
}
V_46 = V_2 ;
return 0 ;
V_72:
F_49 ( V_52 ) ;
V_68:
F_50 ( V_2 -> V_28 ) ;
return V_27 ;
}
static int F_51 ( struct V_49 * V_50 )
{
F_50 ( V_46 -> V_28 ) ;
F_52 ( V_46 -> V_47 ) ;
F_49 ( V_46 -> V_47 ) ;
V_46 = NULL ;
return 0 ;
}
