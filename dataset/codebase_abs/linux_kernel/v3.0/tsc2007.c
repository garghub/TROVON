static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
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
static T_4 F_7 ( struct V_1 * V_2 , struct V_8 * V_9 )
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
static void F_9 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_23 ;
F_5 ( & V_2 -> V_6 -> V_7 , L_3 ) ;
F_10 ( V_23 , V_24 , 0 ) ;
F_11 ( V_23 , V_25 , 0 ) ;
F_12 ( V_23 ) ;
}
static void F_13 ( struct V_26 * V_27 )
{
struct V_1 * V_28 =
F_14 ( F_15 ( V_27 ) , struct V_1 , V_27 ) ;
bool V_29 = false ;
struct V_8 V_9 ;
T_4 V_19 ;
if ( V_28 -> V_30 ) {
if ( F_16 ( ! V_28 -> V_30 () ) ) {
F_9 ( V_28 ) ;
V_28 -> V_31 = false ;
goto V_32;
}
F_5 ( & V_28 -> V_6 -> V_7 , L_4 ) ;
}
F_6 ( V_28 , & V_9 ) ;
V_19 = F_7 ( V_28 , & V_9 ) ;
if ( V_19 > V_28 -> V_33 ) {
F_5 ( & V_28 -> V_6 -> V_7 , L_5 , V_19 ) ;
V_29 = true ;
goto V_32;
}
if ( V_19 ) {
struct V_22 * V_23 = V_28 -> V_23 ;
if ( ! V_28 -> V_31 ) {
F_5 ( & V_28 -> V_6 -> V_7 , L_6 ) ;
F_10 ( V_23 , V_24 , 1 ) ;
V_28 -> V_31 = true ;
}
F_11 ( V_23 , V_34 , V_9 . V_12 ) ;
F_11 ( V_23 , V_35 , V_9 . V_10 ) ;
F_11 ( V_23 , V_25 , V_19 ) ;
F_12 ( V_23 ) ;
F_5 ( & V_28 -> V_6 -> V_7 , L_7 ,
V_9 . V_12 , V_9 . V_10 , V_19 ) ;
} else if ( ! V_28 -> V_30 && V_28 -> V_31 ) {
F_9 ( V_28 ) ;
V_28 -> V_31 = false ;
}
V_32:
if ( V_28 -> V_31 || V_29 )
F_17 ( & V_28 -> V_27 ,
F_18 ( V_28 -> V_36 ) ) ;
else
F_19 ( V_28 -> V_37 ) ;
}
static T_5 F_20 ( int V_37 , void * V_38 )
{
struct V_1 * V_28 = V_38 ;
if ( ! V_28 -> V_30 || F_8 ( V_28 -> V_30 () ) ) {
F_21 ( V_28 -> V_37 ) ;
F_17 ( & V_28 -> V_27 ,
F_18 ( V_28 -> V_39 ) ) ;
}
if ( V_28 -> V_40 )
V_28 -> V_40 () ;
return V_41 ;
}
static void F_22 ( struct V_1 * V_28 )
{
F_23 ( V_28 -> V_37 , V_28 ) ;
if ( F_24 ( & V_28 -> V_27 ) ) {
F_19 ( V_28 -> V_37 ) ;
}
}
static int T_6 F_25 ( struct V_42 * V_6 ,
const struct V_43 * V_44 )
{
struct V_1 * V_28 ;
struct V_45 * V_46 = V_6 -> V_7 . V_47 ;
struct V_22 * V_22 ;
int V_48 ;
if ( ! V_46 ) {
F_3 ( & V_6 -> V_7 , L_8 ) ;
return - V_49 ;
}
if ( ! F_26 ( V_6 -> V_50 ,
V_51 ) )
return - V_52 ;
V_28 = F_27 ( sizeof( struct V_1 ) , V_53 ) ;
V_22 = F_28 () ;
if ( ! V_28 || ! V_22 ) {
V_48 = - V_54 ;
goto V_55;
}
V_28 -> V_6 = V_6 ;
V_28 -> V_37 = V_6 -> V_37 ;
V_28 -> V_23 = V_22 ;
F_29 ( & V_28 -> V_27 , F_13 ) ;
V_28 -> V_56 = V_46 -> V_56 ;
V_28 -> V_21 = V_46 -> V_21 ;
V_28 -> V_33 = V_46 -> V_33 ? : V_20 ;
V_28 -> V_39 = V_46 -> V_39 ? : 1 ;
V_28 -> V_36 = V_46 -> V_36 ? : 1 ;
V_28 -> V_30 = V_46 -> V_30 ;
V_28 -> V_40 = V_46 -> V_40 ;
snprintf ( V_28 -> V_57 , sizeof( V_28 -> V_57 ) ,
L_9 , F_30 ( & V_6 -> V_7 ) ) ;
V_22 -> V_58 = L_10 ;
V_22 -> V_57 = V_28 -> V_57 ;
V_22 -> V_44 . V_59 = V_60 ;
V_22 -> V_61 [ 0 ] = F_31 ( V_62 ) | F_31 ( V_63 ) ;
V_22 -> V_64 [ F_32 ( V_24 ) ] = F_31 ( V_24 ) ;
F_33 ( V_22 , V_34 , 0 , V_20 , V_46 -> V_65 , 0 ) ;
F_33 ( V_22 , V_35 , 0 , V_20 , V_46 -> V_66 , 0 ) ;
F_33 ( V_22 , V_25 , 0 , V_20 ,
V_46 -> V_67 , 0 ) ;
if ( V_46 -> V_68 )
V_46 -> V_68 () ;
V_48 = F_34 ( V_28 -> V_37 , F_20 , 0 ,
V_6 -> V_7 . V_69 -> V_58 , V_28 ) ;
if ( V_48 < 0 ) {
F_3 ( & V_6 -> V_7 , L_11 , V_28 -> V_37 ) ;
goto V_55;
}
V_48 = F_1 ( V_28 , V_18 ) ;
if ( V_48 < 0 )
goto V_70;
V_48 = F_35 ( V_22 ) ;
if ( V_48 )
goto V_70;
F_36 ( V_6 , V_28 ) ;
return 0 ;
V_70:
F_22 ( V_28 ) ;
if ( V_46 -> V_71 )
V_46 -> V_71 () ;
V_55:
F_37 ( V_22 ) ;
F_38 ( V_28 ) ;
return V_48 ;
}
static int T_7 F_39 ( struct V_42 * V_6 )
{
struct V_1 * V_28 = F_40 ( V_6 ) ;
struct V_45 * V_46 = V_6 -> V_7 . V_47 ;
F_22 ( V_28 ) ;
if ( V_46 -> V_71 )
V_46 -> V_71 () ;
F_41 ( V_28 -> V_23 ) ;
F_38 ( V_28 ) ;
return 0 ;
}
static int T_8 F_42 ( void )
{
return F_43 ( & V_72 ) ;
}
static void T_9 F_44 ( void )
{
F_45 ( & V_72 ) ;
}
