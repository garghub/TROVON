static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_4 == V_5 ) {
unsigned int V_6 = V_2 -> V_7 * V_2 -> V_8 / 100 ;
V_3 = F_2 ( V_2 -> V_9 , V_6 , V_2 -> V_7 ) ;
} else {
int V_10 ;
T_1 V_11 = 0 ;
for ( V_10 = 0 ; V_10 <= 64 ; V_10 ++ ) {
if ( V_2 -> V_8 <= V_10 * 100 / 64 ) {
V_11 = V_10 ;
break;
}
}
switch ( V_2 -> V_12 ) {
case 0 :
F_3 ( V_2 -> V_13 ,
V_14 , V_11 ) ;
break;
case 1 :
F_3 ( V_2 -> V_13 ,
V_15 , V_11 ) ;
break;
case 2 :
F_3 ( V_2 -> V_13 ,
V_16 , V_11 ) ;
break;
case 3 :
F_3 ( V_2 -> V_13 ,
V_17 , V_11 ) ;
break;
default:
break;
}
}
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = V_2 -> type << V_19 |
V_2 -> V_20 << V_21 |
V_2 -> V_4 << V_22 | V_2 -> V_23 ;
F_3 ( V_2 -> V_13 , V_24 , V_18 ) ;
if ( V_2 -> V_4 == V_25 && V_2 -> V_20 ) {
V_18 = V_2 -> V_12 << V_26 |
V_2 -> V_12 << V_27 |
V_2 -> V_12 << V_28 |
V_2 -> V_12 << V_29 ;
F_3 ( V_2 -> V_13 ,
V_30 , V_18 ) ;
switch ( V_2 -> V_12 ) {
case 0 :
V_18 = V_2 -> V_31 << 4 ;
F_3 ( V_2 -> V_13 ,
V_32 , V_18 ) ;
V_18 = V_2 -> V_33 ;
F_3 ( V_2 -> V_13 ,
V_34 , V_18 ) ;
break;
case 1 :
V_18 = V_2 -> V_31 ;
F_3 ( V_2 -> V_13 ,
V_32 , V_18 ) ;
V_18 = V_2 -> V_33 ;
F_3 ( V_2 -> V_13 ,
V_35 , V_18 ) ;
break;
case 2 :
V_18 = V_2 -> V_31 << 4 ;
F_3 ( V_2 -> V_13 ,
V_36 , V_18 ) ;
V_18 = V_2 -> V_33 ;
F_3 ( V_2 -> V_13 ,
V_37 , V_18 ) ;
break;
case 3 :
V_18 = V_2 -> V_31 ;
F_3 ( V_2 -> V_13 ,
V_36 , V_18 ) ;
V_18 = V_2 -> V_33 ;
F_3 ( V_2 -> V_13 ,
V_38 , V_18 ) ;
break;
default:
break;
}
}
}
static void F_5 ( struct V_1 * V_2 )
{
int error ;
F_6 ( & V_2 -> V_39 ) ;
error = F_1 ( V_2 ) ;
if ( error ) {
F_7 ( V_2 -> V_40 , L_1 , error ) ;
goto V_41;
}
if ( ! V_2 -> V_20 ) {
error = F_8 ( V_2 -> V_42 ) ;
if ( error ) {
F_7 ( V_2 -> V_40 , L_2 ) ;
goto V_41;
}
F_4 ( V_2 ) ;
if ( V_2 -> V_4 == V_5 ) {
error = F_9 ( V_2 -> V_9 ) ;
if ( error ) {
F_7 ( V_2 -> V_40 , L_3 ) ;
F_10 ( V_2 -> V_42 ) ;
goto V_41;
}
}
V_2 -> V_20 = true ;
}
V_41:
F_11 ( & V_2 -> V_39 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_6 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_20 ) {
V_2 -> V_20 = false ;
F_4 ( V_2 ) ;
if ( V_2 -> V_4 == V_5 )
F_13 ( V_2 -> V_9 ) ;
F_10 ( V_2 -> V_42 ) ;
}
F_11 ( & V_2 -> V_39 ) ;
}
static void F_14 ( struct V_43 * V_44 )
{
struct V_1 * V_2 =
F_15 ( V_44 , struct V_1 , V_44 ) ;
if ( V_2 -> V_8 )
F_5 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
static int F_16 ( struct V_45 * V_40 , void * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
V_2 -> V_8 = V_48 -> V_49 . V_50 . V_51 ;
if ( ! V_2 -> V_8 )
V_2 -> V_8 = V_48 -> V_49 . V_50 . V_52 ;
F_18 ( & V_2 -> V_44 ) ;
return 0 ;
}
static void F_19 ( struct V_45 * V_40 )
{
struct V_1 * V_2 = F_17 ( V_40 ) ;
F_20 ( & V_2 -> V_44 ) ;
F_12 ( V_2 ) ;
}
static int F_21 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_22 ( V_54 -> V_40 . V_57 ) ;
const struct V_58 * V_59 =
F_23 ( V_56 -> V_40 ) ;
const struct V_60 * V_61 = NULL ;
struct V_1 * V_2 ;
struct V_45 * V_45 ;
int error ;
if ( V_59 )
V_61 = V_59 -> V_61 ;
if ( ! V_61 ) {
F_7 ( & V_54 -> V_40 , L_4 ) ;
return - V_62 ;
}
V_2 = F_24 ( sizeof( struct V_1 ) , V_63 ) ;
V_45 = F_25 () ;
if ( ! V_2 || ! V_45 ) {
F_7 ( & V_54 -> V_40 , L_5 ) ;
error = - V_64 ;
goto V_65;
}
F_26 ( & V_2 -> V_44 , F_14 ) ;
F_27 ( & V_2 -> V_39 ) ;
V_2 -> V_13 = V_56 -> V_66 ;
V_2 -> V_40 = & V_54 -> V_40 ;
V_2 -> V_45 = V_45 ;
V_2 -> V_7 = V_61 -> V_7 ;
V_2 -> type = V_61 -> type ;
V_2 -> V_4 = V_61 -> V_4 ;
V_2 -> V_23 = V_61 -> V_23 ;
switch ( V_2 -> V_4 ) {
case V_25 :
V_2 -> V_12 =
V_61 -> V_12 ;
V_2 -> V_31 = V_61 -> V_31 ;
V_2 -> V_33 =
V_61 -> V_33 ;
break;
case V_5 :
V_2 -> V_9 = F_28 ( V_61 -> V_67 ,
L_6 ) ;
if ( F_29 ( V_2 -> V_9 ) ) {
error = F_30 ( V_2 -> V_9 ) ;
F_7 ( & V_54 -> V_40 ,
L_7 ,
error ) ;
goto V_65;
}
F_31 ( V_2 -> V_9 ) ;
break;
default:
F_7 ( & V_54 -> V_40 ,
L_8 , V_2 -> V_4 ) ;
error = - V_62 ;
goto V_65;
}
V_2 -> V_42 = F_32 ( & V_54 -> V_40 , L_9 ) ;
if ( F_29 ( V_2 -> V_42 ) ) {
error = F_30 ( V_2 -> V_42 ) ;
F_7 ( & V_54 -> V_40 ,
L_10 ,
error ) ;
goto V_68;
}
V_45 -> V_69 = L_6 ;
V_45 -> V_70 . V_71 = 1 ;
V_45 -> V_40 . V_57 = & V_54 -> V_40 ;
V_45 -> V_72 = F_19 ;
F_33 ( V_45 , V_2 ) ;
F_34 ( V_45 , V_73 , V_74 ) ;
error = F_35 ( V_45 , NULL ,
F_16 ) ;
if ( error ) {
F_7 ( & V_54 -> V_40 ,
L_11 ,
error ) ;
goto V_75;
}
error = F_36 ( V_45 ) ;
if ( error ) {
F_7 ( & V_54 -> V_40 ,
L_12 ,
error ) ;
goto V_76;
}
F_37 ( V_54 , V_2 ) ;
return 0 ;
V_76:
F_38 ( V_45 ) ;
V_75:
F_39 ( V_2 -> V_42 ) ;
V_68:
if ( V_2 -> V_4 == V_5 )
F_40 ( V_2 -> V_9 ) ;
V_65:
F_41 ( V_45 ) ;
F_42 ( V_2 ) ;
return error ;
}
static int F_43 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_44 ( V_54 ) ;
F_45 ( V_2 -> V_45 ) ;
F_39 ( V_2 -> V_42 ) ;
if ( V_2 -> V_4 == V_5 )
F_40 ( V_2 -> V_9 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int T_2 F_46 ( struct V_77 * V_40 )
{
struct V_53 * V_54 = F_47 ( V_40 ) ;
struct V_1 * V_2 = F_44 ( V_54 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
