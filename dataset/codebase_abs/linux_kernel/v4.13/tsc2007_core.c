int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
T_3 V_5 ;
V_4 = F_2 ( V_2 -> V_6 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_6 -> V_7 , L_1 , V_4 ) ;
return V_4 ;
}
V_5 = F_4 ( V_4 ) >> 4 ;
F_5 ( & V_2 -> V_6 -> V_7 , L_2 , V_4 , V_5 ) ;
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
V_9 -> V_10 = F_1 ( V_2 , V_11 ) ;
V_9 -> V_12 = F_1 ( V_2 , V_13 ) ;
V_9 -> V_14 = F_1 ( V_2 , V_15 ) ;
V_9 -> V_16 = F_1 ( V_2 , V_17 ) ;
F_1 ( V_2 , V_18 ) ;
}
T_4 F_7 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
T_4 V_19 = 0 ;
if ( V_9 -> V_12 == V_20 )
V_9 -> V_12 = 0 ;
if ( F_8 ( V_9 -> V_12 && V_9 -> V_14 ) ) {
V_19 = V_9 -> V_16 - V_9 -> V_14 ;
V_19 *= V_9 -> V_12 ;
V_19 *= V_2 -> V_21 ;
V_19 /= V_9 -> V_14 ;
V_19 = ( V_19 + 2047 ) >> 12 ;
}
return V_19 ;
}
bool F_9 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_23 )
return true ;
return V_22 -> V_23 ( & V_22 -> V_6 -> V_7 ) ;
}
static T_5 F_10 ( int V_24 , void * V_25 )
{
struct V_1 * V_22 = V_25 ;
struct V_26 * V_27 = V_22 -> V_27 ;
struct V_8 V_9 ;
T_4 V_19 ;
while ( ! V_22 -> V_28 && F_9 ( V_22 ) ) {
F_11 ( & V_22 -> V_29 ) ;
F_6 ( V_22 , & V_9 ) ;
F_12 ( & V_22 -> V_29 ) ;
V_19 = F_7 ( V_22 , & V_9 ) ;
if ( ! V_19 && ! V_22 -> V_23 ) {
break;
}
if ( V_19 <= V_22 -> V_30 ) {
F_5 ( & V_22 -> V_6 -> V_7 ,
L_3 ,
V_9 . V_12 , V_9 . V_10 , V_19 ) ;
V_19 = V_22 -> V_30 - V_19 ;
F_13 ( V_27 , V_31 , 1 ) ;
F_14 ( V_27 , V_32 , V_9 . V_12 ) ;
F_14 ( V_27 , V_33 , V_9 . V_10 ) ;
F_14 ( V_27 , V_34 , V_19 ) ;
F_15 ( V_27 ) ;
} else {
F_5 ( & V_22 -> V_6 -> V_7 , L_4 , V_19 ) ;
}
F_16 ( V_22 -> V_35 , V_22 -> V_28 , V_22 -> V_36 ) ;
}
F_5 ( & V_22 -> V_6 -> V_7 , L_5 ) ;
F_13 ( V_27 , V_31 , 0 ) ;
F_14 ( V_27 , V_34 , 0 ) ;
F_15 ( V_27 ) ;
if ( V_22 -> V_37 )
V_22 -> V_37 () ;
return V_38 ;
}
static T_5 F_17 ( int V_24 , void * V_25 )
{
struct V_1 * V_22 = V_25 ;
if ( F_9 ( V_22 ) )
return V_39 ;
if ( V_22 -> V_37 )
V_22 -> V_37 () ;
return V_38 ;
}
static void F_18 ( struct V_1 * V_22 )
{
V_22 -> V_28 = true ;
F_19 () ;
F_20 ( & V_22 -> V_35 ) ;
F_21 ( V_22 -> V_24 ) ;
}
static int F_22 ( struct V_26 * V_26 )
{
struct V_1 * V_22 = F_23 ( V_26 ) ;
int V_40 ;
V_22 -> V_28 = false ;
F_19 () ;
F_24 ( V_22 -> V_24 ) ;
V_40 = F_1 ( V_22 , V_18 ) ;
if ( V_40 < 0 ) {
F_18 ( V_22 ) ;
return V_40 ;
}
return 0 ;
}
static void F_25 ( struct V_26 * V_26 )
{
struct V_1 * V_22 = F_23 ( V_26 ) ;
F_18 ( V_22 ) ;
}
static int F_26 ( struct V_41 * V_7 )
{
struct V_42 * V_6 = F_27 ( V_7 ) ;
struct V_1 * V_22 = F_28 ( V_6 ) ;
return ! F_29 ( V_22 -> V_43 ) ;
}
static int F_30 ( struct V_42 * V_6 , struct V_1 * V_22 )
{
struct V_44 * V_45 = V_6 -> V_7 . V_46 ;
T_4 V_47 ;
T_6 V_48 ;
if ( ! V_45 ) {
F_3 ( & V_6 -> V_7 , L_6 ) ;
return - V_49 ;
}
if ( ! F_31 ( V_45 , L_7 , & V_47 ) )
V_22 -> V_30 = V_47 ;
else
V_22 -> V_30 = V_20 ;
if ( ! F_31 ( V_45 , L_8 , & V_47 ) )
V_22 -> V_50 = V_47 ;
if ( ! F_31 ( V_45 , L_9 , & V_47 ) )
V_22 -> V_51 = V_47 ;
if ( ! F_31 ( V_45 , L_10 , & V_47 ) )
V_22 -> V_52 = V_47 ;
if ( ! F_32 ( V_45 , L_11 , & V_48 ) )
V_22 -> V_36 = F_33 ( V_48 ) ;
else
V_22 -> V_36 = F_33 ( 1 ) ;
if ( ! F_31 ( V_45 , L_12 , & V_47 ) ) {
V_22 -> V_21 = V_47 ;
} else {
F_3 ( & V_6 -> V_7 , L_13 ) ;
return - V_49 ;
}
V_22 -> V_43 = F_34 ( V_45 , 0 ) ;
if ( F_35 ( V_22 -> V_43 ) )
V_22 -> V_23 = F_26 ;
else
F_36 ( & V_6 -> V_7 ,
L_14 ,
V_22 -> V_43 ) ;
return 0 ;
}
static int F_30 ( struct V_42 * V_6 , struct V_1 * V_22 )
{
F_3 ( & V_6 -> V_7 , L_15 ) ;
return - V_49 ;
}
static int F_37 ( struct V_42 * V_6 , struct V_1 * V_22 ,
const struct V_53 * V_54 ,
const struct V_55 * V_56 )
{
V_22 -> V_57 = V_54 -> V_57 ;
V_22 -> V_21 = V_54 -> V_21 ;
V_22 -> V_30 = V_54 -> V_30 ? : V_20 ;
V_22 -> V_36 = F_33 ( V_54 -> V_36 ? : 1 ) ;
V_22 -> V_23 = V_54 -> V_23 ;
V_22 -> V_37 = V_54 -> V_37 ;
V_22 -> V_50 = V_54 -> V_50 ;
V_22 -> V_51 = V_54 -> V_51 ;
V_22 -> V_52 = V_54 -> V_52 ;
if ( V_54 -> V_21 == 0 ) {
F_3 ( & V_6 -> V_7 , L_16 ) ;
return - V_49 ;
}
return 0 ;
}
static void F_38 ( void * V_4 )
{
struct V_41 * V_7 = V_4 ;
const struct V_53 * V_54 = F_39 ( V_7 ) ;
V_54 -> V_58 () ;
}
static int F_40 ( struct V_42 * V_6 ,
const struct V_55 * V_56 )
{
const struct V_53 * V_54 =
F_39 ( & V_6 -> V_7 ) ;
struct V_1 * V_22 ;
struct V_26 * V_26 ;
int V_40 ;
if ( ! F_41 ( V_6 -> V_59 ,
V_60 ) )
return - V_61 ;
V_22 = F_42 ( & V_6 -> V_7 , sizeof( struct V_1 ) , V_62 ) ;
if ( ! V_22 )
return - V_63 ;
if ( V_54 )
V_40 = F_37 ( V_6 , V_22 , V_54 , V_56 ) ;
else
V_40 = F_30 ( V_6 , V_22 ) ;
if ( V_40 )
return V_40 ;
V_26 = F_43 ( & V_6 -> V_7 ) ;
if ( ! V_26 )
return - V_63 ;
F_44 ( V_6 , V_22 ) ;
V_22 -> V_6 = V_6 ;
V_22 -> V_24 = V_6 -> V_24 ;
V_22 -> V_27 = V_26 ;
F_45 ( & V_22 -> V_35 ) ;
F_46 ( & V_22 -> V_29 ) ;
snprintf ( V_22 -> V_64 , sizeof( V_22 -> V_64 ) ,
L_17 , F_47 ( & V_6 -> V_7 ) ) ;
V_26 -> V_65 = L_18 ;
V_26 -> V_64 = V_22 -> V_64 ;
V_26 -> V_56 . V_66 = V_67 ;
V_26 -> V_68 = F_22 ;
V_26 -> V_69 = F_25 ;
F_48 ( V_26 , V_22 ) ;
F_49 ( V_26 , V_70 , V_31 ) ;
F_50 ( V_26 , V_32 , 0 , V_20 , V_22 -> V_50 , 0 ) ;
F_50 ( V_26 , V_33 , 0 , V_20 , V_22 -> V_51 , 0 ) ;
F_50 ( V_26 , V_34 , 0 , V_20 ,
V_22 -> V_52 , 0 ) ;
if ( V_54 ) {
if ( V_54 -> V_58 ) {
V_40 = F_51 ( & V_6 -> V_7 ,
F_38 ,
& V_6 -> V_7 ) ;
if ( V_40 ) {
F_3 ( & V_6 -> V_7 ,
L_19 ,
V_40 ) ;
return V_40 ;
}
}
if ( V_54 -> V_71 )
V_54 -> V_71 () ;
}
V_40 = F_52 ( & V_6 -> V_7 , V_22 -> V_24 ,
F_17 , F_10 ,
V_72 ,
V_6 -> V_7 . V_73 -> V_65 , V_22 ) ;
if ( V_40 ) {
F_3 ( & V_6 -> V_7 , L_20 ,
V_22 -> V_24 , V_40 ) ;
return V_40 ;
}
F_18 ( V_22 ) ;
V_40 = F_1 ( V_22 , V_18 ) ;
if ( V_40 < 0 ) {
F_3 ( & V_6 -> V_7 ,
L_21 , V_40 ) ;
return V_40 ;
}
V_40 = F_53 ( V_26 ) ;
if ( V_40 ) {
F_3 ( & V_6 -> V_7 ,
L_22 , V_40 ) ;
return V_40 ;
}
V_40 = F_54 ( V_22 ) ;
if ( V_40 ) {
F_3 ( & V_6 -> V_7 ,
L_23 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
