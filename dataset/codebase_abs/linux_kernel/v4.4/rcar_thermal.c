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
static int F_20 ( struct V_28 * V_29 , int * V_30 )
{
struct V_8 * V_9 = F_21 ( V_29 ) ;
if ( ! F_16 ( V_9 ) || F_22 ( V_9 ) )
F_9 ( V_9 ) ;
F_11 ( & V_9 -> V_18 ) ;
* V_30 = F_23 ( ( V_9 -> V_13 * 5 ) - 65 ) ;
F_19 ( & V_9 -> V_18 ) ;
return 0 ;
}
static int F_24 ( struct V_28 * V_29 ,
int V_31 , enum V_32 * type )
{
struct V_8 * V_9 = F_21 ( V_29 ) ;
struct V_10 * V_11 = F_10 ( V_9 ) ;
switch ( V_31 ) {
case 0 :
* type = V_33 ;
break;
default:
F_15 ( V_11 , L_3 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_25 ( struct V_28 * V_29 ,
int V_31 , int * V_30 )
{
struct V_8 * V_9 = F_21 ( V_29 ) ;
struct V_10 * V_11 = F_10 ( V_9 ) ;
switch ( V_31 ) {
case 0 :
* V_30 = F_23 ( 90 ) ;
break;
default:
F_15 ( V_11 , L_3 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_26 ( struct V_28 * V_29 ,
int V_31 , enum V_32 type )
{
struct V_8 * V_9 = F_21 ( V_29 ) ;
struct V_10 * V_11 = F_10 ( V_9 ) ;
switch ( type ) {
case V_33 :
F_27 ( V_11 , L_4 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_28 ( struct V_8 * V_9 , int V_34 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_35 ;
T_1 V_6 = 0x3 << F_29 ( V_9 ) ;
F_30 ( & V_2 -> V_18 , V_35 ) ;
F_31 ( V_2 , V_36 , V_6 , V_34 ? 0 : V_6 ) ;
F_32 ( & V_2 -> V_18 , V_35 ) ;
}
static void F_33 ( struct V_37 * V_38 )
{
struct V_8 * V_9 ;
int V_39 , V_40 ;
V_9 = F_34 ( V_38 , struct V_8 , V_38 . V_38 ) ;
F_20 ( V_9 -> V_29 , & V_39 ) ;
F_9 ( V_9 ) ;
F_35 ( V_9 ) ;
F_20 ( V_9 -> V_29 , & V_40 ) ;
if ( V_40 != V_39 )
F_36 ( V_9 -> V_29 ) ;
}
static T_1 F_37 ( struct V_8 * V_9 , T_1 V_41 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
V_41 = ( V_41 >> F_29 ( V_9 ) ) & 0x3 ;
if ( V_41 ) {
F_18 ( V_11 , L_5 ,
V_9 -> V_27 ,
( V_41 & 0x2 ) ? L_6 : L_7 ,
( V_41 & 0x1 ) ? L_8 : L_7 ) ;
}
return V_41 ;
}
static T_2 F_38 ( int V_42 , void * V_5 )
{
struct V_1 * V_2 = V_5 ;
struct V_8 * V_9 ;
unsigned long V_35 ;
T_1 V_41 , V_6 ;
F_30 ( & V_2 -> V_18 , V_35 ) ;
V_6 = F_39 ( V_2 , V_36 ) ;
V_41 = F_39 ( V_2 , V_43 ) ;
F_40 ( V_2 , V_43 , 0x000F0F0F & V_6 ) ;
F_32 ( & V_2 -> V_18 , V_35 ) ;
V_41 = V_41 & ~ V_6 ;
F_41 (priv, common) {
if ( F_37 ( V_9 , V_41 ) ) {
F_42 ( V_9 ) ;
F_43 ( & V_9 -> V_38 ,
F_44 ( 300 ) ) ;
}
}
return V_44 ;
}
static int F_45 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_46 ( V_46 ) ;
struct V_10 * V_11 = & V_46 -> V_11 ;
struct V_8 * V_9 ;
F_41 (priv, common) {
if ( F_16 ( V_9 ) )
F_42 ( V_9 ) ;
F_47 ( V_9 -> V_29 ) ;
}
F_48 ( V_11 ) ;
F_49 ( V_11 ) ;
return 0 ;
}
static int F_50 ( struct V_45 * V_46 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = & V_46 -> V_11 ;
struct V_47 * V_48 , * V_42 ;
int V_49 = 0 ;
int V_12 ;
int V_16 = - V_50 ;
int V_51 = V_52 ;
T_1 V_53 = 0 ;
V_2 = F_51 ( V_11 , sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_55 ;
F_52 ( V_46 , V_2 ) ;
F_53 ( & V_2 -> V_56 ) ;
F_54 ( & V_2 -> V_18 ) ;
V_2 -> V_11 = V_11 ;
F_55 ( V_11 ) ;
F_56 ( V_11 ) ;
V_42 = F_57 ( V_46 , V_57 , 0 ) ;
if ( V_42 ) {
V_48 = F_57 ( V_46 , V_58 , V_49 ++ ) ;
V_2 -> V_4 = F_58 ( V_11 , V_48 ) ;
if ( F_59 ( V_2 -> V_4 ) )
return F_60 ( V_2 -> V_4 ) ;
V_51 = 0 ;
}
for ( V_12 = 0 ; ; V_12 ++ ) {
V_48 = F_57 ( V_46 , V_58 , V_49 ++ ) ;
if ( ! V_48 )
break;
V_9 = F_51 ( V_11 , sizeof( * V_9 ) , V_54 ) ;
if ( ! V_9 ) {
V_16 = - V_55 ;
goto V_59;
}
V_9 -> V_4 = F_58 ( V_11 , V_48 ) ;
if ( F_59 ( V_9 -> V_4 ) ) {
V_16 = F_60 ( V_9 -> V_4 ) ;
goto V_59;
}
V_9 -> V_2 = V_2 ;
V_9 -> V_27 = V_12 ;
F_61 ( & V_9 -> V_18 ) ;
F_53 ( & V_9 -> V_60 ) ;
F_62 ( & V_9 -> V_38 , F_33 ) ;
F_9 ( V_9 ) ;
V_9 -> V_29 = F_63 ( L_9 ,
1 , 0 , V_9 ,
& V_61 , NULL , 0 ,
V_51 ) ;
if ( F_59 ( V_9 -> V_29 ) ) {
F_15 ( V_11 , L_10 ) ;
V_16 = F_60 ( V_9 -> V_29 ) ;
goto V_59;
}
if ( F_16 ( V_9 ) )
F_35 ( V_9 ) ;
F_64 ( & V_9 -> V_60 , & V_2 -> V_56 ) ;
V_53 |= 3 << ( V_12 * 8 ) ;
}
if ( V_42 ) {
V_16 = F_65 ( V_11 , V_42 -> V_62 , F_38 , 0 ,
F_66 ( V_11 ) , V_2 ) ;
if ( V_16 ) {
F_15 ( V_11 , L_11 ) ;
goto V_59;
}
F_40 ( V_2 , V_63 , V_53 ) ;
}
F_67 ( V_11 , L_12 , V_12 ) ;
return 0 ;
V_59:
F_45 ( V_46 ) ;
return V_16 ;
}
