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
static void F_7 ( const struct V_1 * V_2 , T_2 V_8 ,
T_2 V_7 )
{
V_7 &= V_8 ;
while ( ( F_8 ( V_2 -> V_9 ) & V_8 ) != V_7 )
F_9 ( 1 ) ;
}
static void F_10 ( const struct V_1 * V_2 , bool V_10 )
{
T_2 V_8 = F_11 ( V_2 -> V_11 ) ;
T_2 V_12 ;
F_12 ( & V_13 ) ;
V_12 = F_8 ( V_2 -> V_9 ) ;
V_12 &= ~ F_13 ( V_2 -> V_11 ) ;
V_12 |= F_14 ( V_2 -> V_11 ) ;
F_15 ( V_12 , V_2 -> V_9 ) ;
V_12 &= ~ F_14 ( V_2 -> V_11 ) ;
F_7 ( V_2 , V_8 , V_12 ) ;
if ( V_10 ) {
V_12 |= F_13 ( V_2 -> V_11 ) ;
F_15 ( V_12 , V_2 -> V_9 ) ;
V_12 |= F_14 ( V_2 -> V_11 ) ;
F_7 ( V_2 , V_8 , V_12 ) ;
}
F_16 ( & V_13 ) ;
}
static T_2 F_17 ( const struct V_1 * V_2 , enum V_3 V_4 )
{
T_2 V_7 ;
V_7 = V_2 -> V_14 ( V_2 , V_4 ) ;
V_7 |= ( ( T_2 ) V_2 -> V_14 ( V_2 , V_4 + 1 ) ) << 16 ;
return V_7 ;
}
static void F_18 ( const struct V_1 * V_2 , enum V_3 V_4 ,
T_2 V_7 )
{
V_2 -> V_15 ( V_2 , V_4 + 1 , V_7 >> 16 ) ;
V_2 -> V_15 ( V_2 , V_4 , V_7 ) ;
}
static T_2 F_19 ( const struct V_1 * V_2 , enum V_3 V_4 )
{
return F_8 ( V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static void F_20 ( const struct V_1 * V_2 , enum V_3 V_4 ,
T_2 V_7 )
{
F_15 ( V_7 , V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static void F_21 ( const struct V_1 * V_2 , T_2 V_8 )
{
while ( V_2 -> V_16 ( V_2 , V_17 ) & V_8 )
F_9 ( 1 ) ;
}
static void F_22 ( const struct V_1 * V_2 , bool V_10 )
{
T_2 V_12 ;
V_12 = V_2 -> V_16 ( V_2 , V_17 ) ;
V_12 &= ~ V_18 ;
V_2 -> V_19 ( V_2 , V_17 , V_12 ) ;
F_21 ( V_2 , V_12 ) ;
if ( V_10 ) {
V_12 |= V_18 ;
V_2 -> V_19 ( V_2 , V_17 , V_12 ) ;
F_21 ( V_2 , V_12 ) ;
}
}
static int F_23 ( struct V_20 * V_21 )
{
int V_22 ;
void T_3 * V_23 ;
struct V_24 * V_25 ;
struct V_1 * V_2 ;
const struct V_26 * V_27 ;
const struct V_28 * V_29 ;
struct V_30 * V_31 , * V_32 ;
int V_33 ;
struct V_34 * V_34 ;
if ( V_21 -> V_25 . V_35 ) {
V_27 = F_24 ( V_36 , & V_21 -> V_25 ) ;
if ( ! V_27 ) {
F_25 ( & V_21 -> V_25 , L_1 ) ;
V_22 = - V_37 ;
goto exit;
}
V_29 = V_27 -> V_38 ;
} else {
V_29 = F_26 ( V_21 ) ;
}
V_34 = F_27 ( & V_21 -> V_25 , NULL ) ;
if ( F_28 ( V_34 ) ) {
V_22 = F_29 ( V_34 ) ;
goto exit;
}
V_33 = F_30 ( V_21 , 0 ) ;
if ( V_33 <= 0 ) {
V_22 = - V_39 ;
goto exit;
}
V_31 = F_31 ( V_21 , V_40 , 0 ) ;
V_23 = F_32 ( & V_21 -> V_25 , V_31 ) ;
if ( F_28 ( V_23 ) ) {
V_22 = F_29 ( V_23 ) ;
goto exit;
}
V_25 = F_33 () ;
if ( ! V_25 ) {
V_22 = - V_41 ;
goto exit;
}
V_2 = F_34 ( V_25 ) ;
switch ( V_29 -> V_42 ) {
case V_43 :
V_2 -> V_6 = V_44 ;
switch ( V_31 -> V_45 & V_46 ) {
case V_47 :
V_2 -> V_14 = F_5 ;
V_2 -> V_15 = F_6 ;
V_2 -> V_16 = F_17 ;
V_2 -> V_19 = F_18 ;
break;
case V_48 :
default:
V_2 -> V_14 = F_1 ;
V_2 -> V_15 = F_3 ;
V_2 -> V_16 = F_17 ;
V_2 -> V_19 = F_18 ;
break;
}
break;
case V_49 :
V_2 -> V_6 = V_50 ;
V_2 -> V_51 . V_52 |= V_53 ;
V_2 -> V_14 = F_1 ;
V_2 -> V_15 = F_3 ;
V_2 -> V_16 = F_19 ;
V_2 -> V_19 = F_20 ;
if ( V_21 -> V_25 . V_35 )
V_2 -> V_11 = F_35 ( V_21 -> V_25 . V_35 , L_2 ) ;
else
V_2 -> V_11 = V_21 -> V_29 ;
V_32 = F_31 ( V_21 , V_40 , 1 ) ;
if ( ! V_32 ) {
V_2 -> V_54 = F_22 ;
break;
}
V_2 -> V_9 = F_36 ( & V_21 -> V_25 , V_32 -> V_55 ,
F_37 ( V_32 ) ) ;
if ( ! V_2 -> V_9 || V_2 -> V_11 < 0 )
F_38 ( & V_21 -> V_25 , L_3 ) ;
else
V_2 -> V_54 = F_10 ;
break;
default:
V_22 = - V_37 ;
goto V_56;
}
V_25 -> V_33 = V_33 ;
V_2 -> V_5 = V_23 ;
V_2 -> V_57 = & V_21 -> V_25 ;
V_2 -> V_51 . clock . V_58 = F_39 ( V_34 ) ;
V_2 -> V_2 = V_34 ;
V_2 -> type = V_29 -> V_42 ;
F_40 ( V_21 , V_25 ) ;
F_41 ( V_25 , & V_21 -> V_25 ) ;
V_22 = F_42 ( V_25 ) ;
if ( V_22 ) {
F_25 ( & V_21 -> V_25 , L_4 ,
V_59 , V_22 ) ;
goto V_56;
}
F_38 ( & V_21 -> V_25 , L_5 ,
V_59 , V_2 -> V_5 , V_25 -> V_33 ) ;
return 0 ;
V_56:
F_43 ( V_25 ) ;
exit:
F_25 ( & V_21 -> V_25 , L_6 ) ;
return V_22 ;
}
static int F_44 ( struct V_20 * V_21 )
{
struct V_24 * V_25 = F_45 ( V_21 ) ;
F_46 ( V_25 ) ;
F_43 ( V_25 ) ;
return 0 ;
}
static int F_47 ( struct V_20 * V_21 , T_4 V_60 )
{
int V_22 ;
struct V_24 * V_61 = F_45 ( V_21 ) ;
struct V_1 * V_2 = F_34 ( V_61 ) ;
if ( V_2 -> type != V_49 ) {
F_48 ( & V_21 -> V_25 , L_7 ) ;
return 0 ;
}
if ( F_49 ( V_61 ) ) {
F_50 ( V_61 ) ;
F_51 ( V_61 ) ;
}
V_22 = F_52 ( V_61 ) ;
if ( V_22 ) {
F_53 ( V_61 , L_8 ) ;
return V_22 ;
}
V_2 -> V_51 . V_60 = V_62 ;
return 0 ;
}
static int F_54 ( struct V_20 * V_21 )
{
int V_22 ;
struct V_24 * V_61 = F_45 ( V_21 ) ;
struct V_1 * V_2 = F_34 ( V_61 ) ;
if ( V_2 -> type != V_49 ) {
F_48 ( & V_21 -> V_25 , L_7 ) ;
return 0 ;
}
V_22 = F_55 ( V_61 ) ;
if ( V_22 ) {
F_53 ( V_61 , L_9 ) ;
return V_22 ;
}
V_2 -> V_51 . V_60 = V_63 ;
if ( F_49 ( V_61 ) ) {
F_56 ( V_61 ) ;
F_57 ( V_61 ) ;
}
return 0 ;
}
