static T_1 F_1 ( const struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static void F_3 ( const struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static T_1 F_5 ( const struct V_1 * V_2 ,
enum V_3 V_4 )
{
return F_2 ( V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static void F_6 ( const struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_7 )
{
F_4 ( V_7 , V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 ,
enum V_3 V_4 )
{
return ( T_1 ) F_8 ( V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static void F_9 ( const struct V_1 * V_2 ,
enum V_3 V_4 , T_1 V_7 )
{
F_10 ( ( V_8 ) V_7 , V_2 -> V_5 + 2 * V_2 -> V_6 [ V_4 ] ) ;
}
static V_8 F_11 ( const struct V_1 * V_2 , enum V_3 V_4 )
{
V_8 V_7 ;
V_7 = V_2 -> V_9 ( V_2 , V_4 ) ;
V_7 |= ( ( V_8 ) V_2 -> V_9 ( V_2 , V_4 + 1 ) ) << 16 ;
return V_7 ;
}
static void F_12 ( const struct V_1 * V_2 , enum V_3 V_4 ,
V_8 V_7 )
{
V_2 -> V_10 ( V_2 , V_4 + 1 , V_7 >> 16 ) ;
V_2 -> V_10 ( V_2 , V_4 , V_7 ) ;
}
static void F_13 ( const struct V_1 * V_2 , bool V_11 )
{
if ( V_11 ) {
V_8 T_2 * V_12 = V_2 -> V_5 + V_13 ;
F_10 ( 1 , V_12 ) ;
F_10 ( 0 , V_12 ) ;
}
}
static int F_14 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
struct V_18 * V_18 = ( void * ) V_17 -> V_19 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
void T_2 * V_12 ;
int V_22 ;
V_22 = F_15 ( V_15 ) ;
if ( V_22 ) {
F_16 ( & V_15 -> V_21 , L_1 ) ;
goto V_23;
}
V_22 = F_17 ( V_15 , V_24 ) ;
if ( V_22 ) {
F_16 ( & V_15 -> V_21 , L_2 ) ;
goto V_25;
}
V_22 = F_18 ( V_15 ) ;
if ( ! V_22 ) {
F_19 ( & V_15 -> V_21 , L_3 ) ;
F_20 ( V_15 ) ;
}
V_12 = F_21 ( V_15 , V_18 -> V_26 ,
F_22 ( V_15 , V_18 -> V_26 ) ) ;
if ( ! V_12 ) {
F_16 ( & V_15 -> V_21 ,
L_4
L_5 ) ;
V_22 = - V_27 ;
goto V_28;
}
V_21 = F_23 () ;
if ( ! V_21 ) {
V_22 = - V_27 ;
goto V_29;
}
V_2 = F_24 ( V_21 ) ;
F_25 ( V_15 , V_21 ) ;
F_26 ( V_21 , & V_15 -> V_21 ) ;
V_21 -> V_30 = V_15 -> V_30 ;
V_2 -> V_5 = V_12 ;
if ( ! V_18 -> V_31 ) {
F_16 ( & V_15 -> V_21 , L_6 ) ;
V_22 = - V_32 ;
goto V_33;
} else {
V_2 -> V_34 . clock . V_31 = V_18 -> V_31 ;
}
switch ( V_18 -> type ) {
case V_35 :
V_2 -> V_6 = V_36 ;
break;
case V_37 :
V_2 -> V_6 = V_38 ;
V_2 -> V_34 . V_39 |= V_40 ;
break;
default:
V_22 = - V_41 ;
goto V_33;
}
V_2 -> type = V_18 -> type ;
switch ( V_18 -> V_42 ) {
case V_43 :
V_2 -> V_9 = F_5 ;
V_2 -> V_10 = F_6 ;
break;
case V_44 :
V_2 -> V_9 = F_1 ;
V_2 -> V_10 = F_3 ;
break;
case V_45 :
V_2 -> V_9 = F_7 ;
V_2 -> V_10 = F_9 ;
break;
default:
V_22 = - V_41 ;
goto V_33;
}
V_2 -> V_46 = F_11 ;
V_2 -> V_47 = F_12 ;
V_2 -> V_48 = V_18 -> V_49 ;
V_22 = F_27 ( V_21 ) ;
if ( V_22 ) {
F_16 ( & V_15 -> V_21 , L_7 ,
V_24 , V_22 ) ;
goto V_33;
}
F_28 ( & V_15 -> V_21 , L_8 ,
V_24 , V_2 -> V_6 , V_21 -> V_30 ) ;
return 0 ;
V_33:
F_29 ( V_21 ) ;
V_29:
F_30 ( V_15 , V_12 ) ;
V_28:
F_31 ( V_15 ) ;
F_32 ( V_15 ) ;
F_33 ( V_15 ) ;
V_25:
F_34 ( V_15 ) ;
V_23:
return V_22 ;
}
static void F_35 ( struct V_14 * V_15 )
{
struct V_20 * V_21 = F_36 ( V_15 ) ;
struct V_1 * V_2 = F_24 ( V_21 ) ;
F_37 ( V_21 ) ;
F_29 ( V_21 ) ;
F_30 ( V_15 , V_2 -> V_5 ) ;
F_31 ( V_15 ) ;
F_32 ( V_15 ) ;
F_33 ( V_15 ) ;
F_34 ( V_15 ) ;
}
