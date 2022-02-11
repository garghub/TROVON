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
static void F_7 ( const struct V_1 * V_2 ,
T_2 V_8 , T_2 V_7 )
{
const struct V_9 * V_10 = & V_2 -> V_11 ;
int V_12 = 0 ;
T_2 V_13 = 0 ;
V_7 &= V_8 ;
do {
F_8 ( 1 ) ;
V_12 ++ ;
F_9 ( V_10 -> V_14 , V_10 -> V_3 , & V_13 ) ;
if ( V_12 == 1000 ) {
F_10 ( & V_2 -> V_15 -> V_15 , L_1 , V_16 ) ;
break;
}
} while ( ( V_13 & V_8 ) != V_7 );
}
static void F_11 ( const struct V_1 * V_2 , bool V_17 )
{
const struct V_9 * V_10 = & V_2 -> V_11 ;
T_2 V_13 = 0 ;
T_2 V_8 ;
F_12 ( & V_18 ) ;
V_8 = 1 << V_10 -> V_19 . V_20 | 1 << V_10 -> V_19 . V_21 ;
F_9 ( V_10 -> V_14 , V_10 -> V_3 , & V_13 ) ;
V_13 &= ~ V_8 ;
F_13 ( V_10 -> V_14 , V_10 -> V_3 , V_8 , V_13 ) ;
F_7 ( V_2 , 1 << V_10 -> V_19 . V_20 , V_13 ) ;
if ( V_17 ) {
V_13 |= 1 << V_10 -> V_19 . V_20 ;
V_13 |= 1 << V_10 -> V_19 . V_21 ;
F_13 ( V_10 -> V_14 , V_10 -> V_3 , V_8 , V_13 ) ;
V_13 &= ~ ( 1 << V_10 -> V_19 . V_21 ) ;
if ( V_10 -> V_22 ) {
V_13 &= ~ ( 1 << V_10 -> V_19 . V_20 ) ;
F_13 ( V_10 -> V_14 , V_10 -> V_3 ,
V_8 , V_13 ) ;
}
V_13 |= 1 << V_10 -> V_19 . V_21 ;
F_7 ( V_2 , V_8 , V_13 ) ;
}
F_14 ( & V_18 ) ;
}
static T_2 F_15 ( const struct V_1 * V_2 , enum V_3 V_4 )
{
T_2 V_7 ;
V_7 = V_2 -> V_23 ( V_2 , V_4 ) ;
V_7 |= ( ( T_2 ) V_2 -> V_23 ( V_2 , V_4 + 1 ) ) << 16 ;
return V_7 ;
}
static void F_16 ( const struct V_1 * V_2 , enum V_3 V_4 ,
T_2 V_7 )
{
V_2 -> V_24 ( V_2 , V_4 + 1 , V_7 >> 16 ) ;
V_2 -> V_24 ( V_2 , V_4 , V_7 ) ;
}
static T_2 F_17 ( const struct V_1 * V_2 , enum V_3 V_4 )
{
return F_18 ( V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static void F_19 ( const struct V_1 * V_2 , enum V_3 V_4 ,
T_2 V_7 )
{
F_20 ( V_7 , V_2 -> V_5 + V_2 -> V_6 [ V_4 ] ) ;
}
static void F_21 ( const struct V_1 * V_2 , T_2 V_8 )
{
while ( V_2 -> V_25 ( V_2 , V_26 ) & V_8 )
F_8 ( 1 ) ;
}
static void F_22 ( const struct V_1 * V_2 , bool V_17 )
{
T_2 V_13 ;
V_13 = V_2 -> V_25 ( V_2 , V_26 ) ;
V_13 &= ~ V_27 ;
V_2 -> V_28 ( V_2 , V_26 , V_13 ) ;
F_21 ( V_2 , V_13 ) ;
if ( V_17 ) {
V_13 |= V_27 ;
V_2 -> V_28 ( V_2 , V_26 , V_13 ) ;
F_21 ( V_2 , V_13 ) ;
}
}
static int F_23 ( struct V_29 * V_30 )
{
int V_31 ;
void T_3 * V_32 ;
struct V_33 * V_15 ;
struct V_1 * V_2 ;
const struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_38 ;
struct V_39 * V_39 ;
const struct V_40 * V_41 ;
struct V_42 * V_43 = V_30 -> V_15 . V_44 ;
V_35 = F_24 ( V_45 , & V_30 -> V_15 ) ;
if ( V_35 ) {
V_41 = V_35 -> V_46 ;
} else if ( V_30 -> V_47 -> V_48 ) {
V_41 = (struct V_40 * )
F_25 ( V_30 ) -> V_48 ;
} else {
return - V_49 ;
}
V_39 = F_26 ( & V_30 -> V_15 , NULL ) ;
if ( F_27 ( V_39 ) ) {
V_31 = F_28 ( V_39 ) ;
goto exit;
}
V_38 = F_29 ( V_30 , 0 ) ;
if ( V_38 <= 0 ) {
V_31 = - V_49 ;
goto exit;
}
V_37 = F_30 ( V_30 , V_50 , 0 ) ;
V_32 = F_31 ( & V_30 -> V_15 , V_37 ) ;
if ( F_27 ( V_32 ) ) {
V_31 = F_28 ( V_32 ) ;
goto exit;
}
V_15 = F_32 () ;
if ( ! V_15 ) {
V_31 = - V_51 ;
goto exit;
}
V_2 = F_33 ( V_15 ) ;
switch ( V_41 -> V_52 ) {
case V_53 :
V_2 -> V_6 = V_54 ;
switch ( V_37 -> V_55 & V_56 ) {
case V_57 :
V_2 -> V_23 = F_5 ;
V_2 -> V_24 = F_6 ;
V_2 -> V_25 = F_15 ;
V_2 -> V_28 = F_16 ;
break;
case V_58 :
default:
V_2 -> V_23 = F_1 ;
V_2 -> V_24 = F_3 ;
V_2 -> V_25 = F_15 ;
V_2 -> V_28 = F_16 ;
break;
}
break;
case V_59 :
V_2 -> V_6 = V_60 ;
V_2 -> V_61 . V_62 |= V_63 ;
V_2 -> V_23 = F_1 ;
V_2 -> V_24 = F_3 ;
V_2 -> V_25 = F_17 ;
V_2 -> V_28 = F_19 ;
if ( V_43 && F_34 ( V_43 , L_2 ) ) {
T_2 V_52 ;
struct V_9 * V_10 = & V_2 -> V_11 ;
V_31 = - V_64 ;
V_10 -> V_14 = F_35 ( V_43 ,
L_2 ) ;
if ( F_27 ( V_10 -> V_14 ) ) {
V_31 = F_28 ( V_10 -> V_14 ) ;
F_36 ( V_15 ) ;
return V_31 ;
}
if ( F_37 ( V_43 , L_2 , 1 ,
& V_10 -> V_3 ) ) {
F_10 ( & V_30 -> V_15 ,
L_3 ) ;
goto V_65;
}
if ( F_37 ( V_43 , L_2 , 2 ,
& V_52 ) ) {
F_10 ( & V_30 -> V_15 ,
L_4 ) ;
goto V_65;
}
if ( V_52 >= V_41 -> V_66 ) {
F_10 ( & V_30 -> V_15 ,
L_5 ) ;
goto V_65;
}
V_10 -> V_19 = V_41 -> V_67 [ V_52 ] ;
V_10 -> V_22 = V_41 -> V_68 ;
V_2 -> V_10 = F_11 ;
} else {
V_2 -> V_10 = F_22 ;
}
break;
default:
V_31 = - V_64 ;
goto V_65;
}
V_15 -> V_38 = V_38 ;
V_2 -> V_5 = V_32 ;
V_2 -> V_69 = & V_30 -> V_15 ;
V_2 -> V_61 . clock . V_70 = F_38 ( V_39 ) ;
V_2 -> V_2 = V_39 ;
V_2 -> type = V_41 -> V_52 ;
F_39 ( V_30 , V_15 ) ;
F_40 ( V_15 , & V_30 -> V_15 ) ;
V_31 = F_41 ( V_15 ) ;
if ( V_31 ) {
F_10 ( & V_30 -> V_15 , L_6 ,
V_71 , V_31 ) ;
goto V_65;
}
F_42 ( & V_30 -> V_15 , L_7 ,
V_71 , V_2 -> V_5 , V_15 -> V_38 ) ;
return 0 ;
V_65:
F_36 ( V_15 ) ;
exit:
F_10 ( & V_30 -> V_15 , L_8 ) ;
return V_31 ;
}
static int F_43 ( struct V_29 * V_30 )
{
struct V_33 * V_15 = F_44 ( V_30 ) ;
F_45 ( V_15 ) ;
F_36 ( V_15 ) ;
return 0 ;
}
static int F_46 ( struct V_29 * V_30 , T_4 V_72 )
{
int V_31 ;
struct V_33 * V_73 = F_44 ( V_30 ) ;
struct V_1 * V_2 = F_33 ( V_73 ) ;
if ( V_2 -> type != V_59 ) {
F_47 ( & V_30 -> V_15 , L_9 ) ;
return 0 ;
}
if ( F_48 ( V_73 ) ) {
F_49 ( V_73 ) ;
F_50 ( V_73 ) ;
}
V_31 = F_51 ( V_73 ) ;
if ( V_31 ) {
F_52 ( V_73 , L_10 ) ;
return V_31 ;
}
V_2 -> V_61 . V_72 = V_74 ;
return 0 ;
}
static int F_53 ( struct V_29 * V_30 )
{
int V_31 ;
struct V_33 * V_73 = F_44 ( V_30 ) ;
struct V_1 * V_2 = F_33 ( V_73 ) ;
if ( V_2 -> type != V_59 ) {
F_47 ( & V_30 -> V_15 , L_9 ) ;
return 0 ;
}
V_31 = F_54 ( V_73 ) ;
if ( V_31 ) {
F_52 ( V_73 , L_11 ) ;
return V_31 ;
}
V_2 -> V_61 . V_72 = V_75 ;
if ( F_48 ( V_73 ) ) {
F_55 ( V_73 ) ;
F_56 ( V_73 ) ;
}
return 0 ;
}
