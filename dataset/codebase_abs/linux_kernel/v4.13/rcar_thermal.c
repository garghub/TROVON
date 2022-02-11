static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_6 , T_1 V_5 )
{
T_1 V_7 ;
V_7 = F_2 ( V_2 -> V_4 + V_3 ) ;
V_7 &= ~ V_6 ;
V_7 |= ( V_5 & V_6 ) ;
F_4 ( V_7 , V_2 -> V_4 + V_3 ) ;
}
static T_1 F_6 ( struct V_8 * V_9 , T_1 V_3 )
{
return F_2 ( V_9 -> V_4 + V_3 ) ;
}
static void F_7 ( struct V_8 * V_9 ,
T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_9 -> V_4 + V_3 ) ;
}
static void F_8 ( struct V_8 * V_9 , T_1 V_3 ,
T_1 V_6 , T_1 V_5 )
{
T_1 V_7 ;
V_7 = F_2 ( V_9 -> V_4 + V_3 ) ;
V_7 &= ~ V_6 ;
V_7 |= ( V_5 & V_6 ) ;
F_4 ( V_7 , V_9 -> V_4 + V_3 ) ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
int V_12 ;
T_1 V_13 , V_14 , V_15 ;
int V_16 = - V_17 ;
F_11 ( & V_9 -> V_18 ) ;
F_12 ( V_9 , V_19 , V_20 , V_20 ) ;
V_13 = 0 ;
V_14 = ~ 0 ;
for ( V_12 = 0 ; V_12 < 128 ; V_12 ++ ) {
F_13 ( 300 ) ;
V_15 = F_14 ( V_9 , V_21 ) & V_22 ;
if ( V_15 == V_14 ) {
V_13 = V_15 ;
break;
}
V_14 = V_15 ;
}
if ( ! V_13 ) {
F_15 ( V_11 , L_1 ) ;
goto V_23;
}
if ( F_16 ( V_9 ) ) {
F_17 ( V_9 , V_24 , 0 ) ;
F_17 ( V_9 , V_25 , 0x1 ) ;
F_17 ( V_9 , V_26 , ( ( ( V_13 - 0 ) << 8 ) |
( ( V_13 - 1 ) << 0 ) ) ) ;
}
F_18 ( V_11 , L_2 , V_9 -> V_27 , V_9 -> V_13 , V_13 ) ;
V_9 -> V_13 = V_13 ;
V_16 = 0 ;
V_23:
F_19 ( & V_9 -> V_18 ) ;
return V_16 ;
}
static int F_20 ( struct V_8 * V_9 ,
int * V_28 )
{
int V_29 ;
int V_16 ;
V_16 = F_9 ( V_9 ) ;
if ( V_16 < 0 )
return V_16 ;
F_11 ( & V_9 -> V_18 ) ;
V_29 = F_21 ( ( V_9 -> V_13 * 5 ) - 65 ) ;
F_19 ( & V_9 -> V_18 ) ;
if ( ( V_29 < F_21 ( - 45 ) ) || ( V_29 > F_21 ( 125 ) ) ) {
struct V_10 * V_11 = F_10 ( V_9 ) ;
F_15 ( V_11 , L_3 ) ;
return - V_30 ;
}
* V_28 = V_29 ;
return 0 ;
}
static int F_22 ( void * V_5 , int * V_28 )
{
struct V_8 * V_9 = V_5 ;
return F_20 ( V_9 , V_28 ) ;
}
static int F_23 ( struct V_31 * V_32 , int * V_28 )
{
struct V_8 * V_9 = F_24 ( V_32 ) ;
return F_20 ( V_9 , V_28 ) ;
}
static int F_25 ( struct V_31 * V_32 ,
int V_33 , enum V_34 * type )
{
struct V_8 * V_9 = F_24 ( V_32 ) ;
struct V_10 * V_11 = F_10 ( V_9 ) ;
switch ( V_33 ) {
case 0 :
* type = V_35 ;
break;
default:
F_15 ( V_11 , L_4 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_26 ( struct V_31 * V_32 ,
int V_33 , int * V_28 )
{
struct V_8 * V_9 = F_24 ( V_32 ) ;
struct V_10 * V_11 = F_10 ( V_9 ) ;
switch ( V_33 ) {
case 0 :
* V_28 = F_21 ( 90 ) ;
break;
default:
F_15 ( V_11 , L_4 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_27 ( struct V_31 * V_32 ,
int V_33 , enum V_34 type )
{
struct V_8 * V_9 = F_24 ( V_32 ) ;
struct V_10 * V_11 = F_10 ( V_9 ) ;
switch ( type ) {
case V_35 :
F_28 ( V_11 , L_5 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_29 ( struct V_8 * V_9 , int V_36 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_37 ;
T_1 V_6 = 0x3 << F_30 ( V_9 ) ;
if ( ! F_16 ( V_9 ) )
return;
F_31 ( & V_2 -> V_18 , V_37 ) ;
F_32 ( V_2 , V_38 , V_6 , V_36 ? 0 : V_6 ) ;
F_33 ( & V_2 -> V_18 , V_37 ) ;
}
static void F_34 ( struct V_39 * V_40 )
{
struct V_8 * V_9 ;
int V_41 , V_42 ;
int V_16 ;
V_9 = F_35 ( V_40 , struct V_8 , V_40 . V_40 ) ;
V_16 = F_20 ( V_9 , & V_41 ) ;
if ( V_16 < 0 )
return;
V_16 = F_9 ( V_9 ) ;
if ( V_16 < 0 )
return;
F_36 ( V_9 ) ;
V_16 = F_20 ( V_9 , & V_42 ) ;
if ( V_16 < 0 )
return;
if ( V_42 != V_41 )
F_37 ( V_9 -> V_32 ,
V_43 ) ;
}
static T_1 F_38 ( struct V_8 * V_9 , T_1 V_44 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
V_44 = ( V_44 >> F_30 ( V_9 ) ) & 0x3 ;
if ( V_44 ) {
F_18 ( V_11 , L_6 ,
V_9 -> V_27 ,
( V_44 & 0x2 ) ? L_7 : L_8 ,
( V_44 & 0x1 ) ? L_9 : L_8 ) ;
}
return V_44 ;
}
static T_2 F_39 ( int V_45 , void * V_5 )
{
struct V_1 * V_2 = V_5 ;
struct V_8 * V_9 ;
unsigned long V_37 ;
T_1 V_44 , V_6 ;
F_31 ( & V_2 -> V_18 , V_37 ) ;
V_6 = F_40 ( V_2 , V_38 ) ;
V_44 = F_40 ( V_2 , V_46 ) ;
F_41 ( V_2 , V_46 , 0x000F0F0F & V_6 ) ;
F_33 ( & V_2 -> V_18 , V_37 ) ;
V_44 = V_44 & ~ V_6 ;
F_42 (priv, common) {
if ( F_38 ( V_9 , V_44 ) ) {
F_43 ( V_9 ) ;
F_44 ( & V_9 -> V_40 ,
F_45 ( 300 ) ) ;
}
}
return V_47 ;
}
static int F_46 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_47 ( V_49 ) ;
struct V_10 * V_11 = & V_49 -> V_11 ;
struct V_8 * V_9 ;
F_42 (priv, common) {
F_43 ( V_9 ) ;
if ( F_48 ( V_11 ) )
F_49 ( V_9 -> V_32 ) ;
else
F_50 ( V_9 -> V_32 ) ;
}
F_51 ( V_11 ) ;
F_52 ( V_11 ) ;
return 0 ;
}
static int F_53 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = & V_49 -> V_11 ;
struct V_50 * V_51 , * V_45 ;
int V_52 = 0 ;
int V_12 ;
int V_16 = - V_53 ;
int V_54 = V_55 ;
T_1 V_56 = 0 ;
V_2 = F_54 ( V_11 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return - V_58 ;
F_55 ( V_49 , V_2 ) ;
F_56 ( & V_2 -> V_59 ) ;
F_57 ( & V_2 -> V_18 ) ;
V_2 -> V_11 = V_11 ;
F_58 ( V_11 ) ;
F_59 ( V_11 ) ;
V_45 = F_60 ( V_49 , V_60 , 0 ) ;
if ( V_45 ) {
V_51 = F_60 ( V_49 , V_61 , V_52 ++ ) ;
V_2 -> V_4 = F_61 ( V_11 , V_51 ) ;
if ( F_62 ( V_2 -> V_4 ) )
return F_63 ( V_2 -> V_4 ) ;
V_54 = 0 ;
}
for ( V_12 = 0 ; ; V_12 ++ ) {
V_51 = F_60 ( V_49 , V_61 , V_52 ++ ) ;
if ( ! V_51 )
break;
V_9 = F_54 ( V_11 , sizeof( * V_9 ) , V_57 ) ;
if ( ! V_9 ) {
V_16 = - V_58 ;
goto V_62;
}
V_9 -> V_4 = F_61 ( V_11 , V_51 ) ;
if ( F_62 ( V_9 -> V_4 ) ) {
V_16 = F_63 ( V_9 -> V_4 ) ;
goto V_62;
}
V_9 -> V_2 = V_2 ;
V_9 -> V_27 = V_12 ;
F_64 ( & V_9 -> V_18 ) ;
F_56 ( & V_9 -> V_63 ) ;
F_65 ( & V_9 -> V_40 , F_34 ) ;
V_16 = F_9 ( V_9 ) ;
if ( V_16 < 0 )
goto V_62;
if ( F_48 ( V_11 ) )
V_9 -> V_32 = F_66 (
V_11 , V_12 , V_9 ,
& V_64 ) ;
else
V_9 -> V_32 = F_67 (
L_10 ,
1 , 0 , V_9 ,
& V_65 , NULL , 0 ,
V_54 ) ;
if ( F_62 ( V_9 -> V_32 ) ) {
F_15 ( V_11 , L_11 ) ;
V_16 = F_63 ( V_9 -> V_32 ) ;
V_9 -> V_32 = NULL ;
goto V_62;
}
if ( F_48 ( V_11 ) ) {
V_9 -> V_32 -> V_66 -> V_67 = false ;
V_16 = F_68 ( V_9 -> V_32 ) ;
if ( V_16 )
goto V_62;
}
F_36 ( V_9 ) ;
F_69 ( & V_9 -> V_63 , & V_2 -> V_59 ) ;
V_56 |= 3 << ( V_12 * 8 ) ;
}
if ( V_45 ) {
V_16 = F_70 ( V_11 , V_45 -> V_68 , F_39 , 0 ,
F_71 ( V_11 ) , V_2 ) ;
if ( V_16 ) {
F_15 ( V_11 , L_12 ) ;
goto V_62;
}
F_41 ( V_2 , V_69 , V_56 ) ;
}
F_72 ( V_11 , L_13 , V_12 ) ;
return 0 ;
V_62:
F_46 ( V_49 ) ;
return V_16 ;
}
