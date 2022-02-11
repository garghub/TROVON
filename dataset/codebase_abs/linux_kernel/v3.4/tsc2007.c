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
static bool F_9 ( struct V_1 * V_22 )
{
if ( ! V_22 -> V_23 )
return true ;
return V_22 -> V_23 () ;
}
static T_5 F_10 ( int V_24 , void * V_25 )
{
struct V_1 * V_22 = V_25 ;
struct V_26 * V_27 = V_22 -> V_27 ;
struct V_8 V_9 ;
T_4 V_19 ;
while ( ! V_22 -> V_28 && F_9 ( V_22 ) ) {
F_6 ( V_22 , & V_9 ) ;
V_19 = F_7 ( V_22 , & V_9 ) ;
if ( V_19 == 0 && ! V_22 -> V_23 ) {
break;
}
if ( V_19 <= V_22 -> V_29 ) {
F_5 ( & V_22 -> V_6 -> V_7 ,
L_3 ,
V_9 . V_12 , V_9 . V_10 , V_19 ) ;
F_11 ( V_27 , V_30 , 1 ) ;
F_12 ( V_27 , V_31 , V_9 . V_12 ) ;
F_12 ( V_27 , V_32 , V_9 . V_10 ) ;
F_12 ( V_27 , V_33 , V_19 ) ;
F_13 ( V_27 ) ;
} else {
F_5 ( & V_22 -> V_6 -> V_7 , L_4 , V_19 ) ;
}
F_14 ( V_22 -> V_34 , V_22 -> V_28 ,
F_15 ( V_22 -> V_35 ) ) ;
}
F_5 ( & V_22 -> V_6 -> V_7 , L_5 ) ;
F_11 ( V_27 , V_30 , 0 ) ;
F_12 ( V_27 , V_33 , 0 ) ;
F_13 ( V_27 ) ;
if ( V_22 -> V_36 )
V_22 -> V_36 () ;
return V_37 ;
}
static T_5 F_16 ( int V_24 , void * V_25 )
{
struct V_1 * V_22 = V_25 ;
if ( ! V_22 -> V_23 || F_8 ( V_22 -> V_23 () ) )
return V_38 ;
if ( V_22 -> V_36 )
V_22 -> V_36 () ;
return V_37 ;
}
static void F_17 ( struct V_1 * V_22 )
{
V_22 -> V_28 = true ;
F_18 () ;
F_19 ( & V_22 -> V_34 ) ;
F_20 ( V_22 -> V_24 ) ;
}
static int F_21 ( struct V_26 * V_26 )
{
struct V_1 * V_22 = F_22 ( V_26 ) ;
int V_39 ;
V_22 -> V_28 = false ;
F_18 () ;
F_23 ( V_22 -> V_24 ) ;
V_39 = F_1 ( V_22 , V_18 ) ;
if ( V_39 < 0 ) {
F_17 ( V_22 ) ;
return V_39 ;
}
return 0 ;
}
static void F_24 ( struct V_26 * V_26 )
{
struct V_1 * V_22 = F_22 ( V_26 ) ;
F_17 ( V_22 ) ;
}
static int T_6 F_25 ( struct V_40 * V_6 ,
const struct V_41 * V_42 )
{
struct V_1 * V_22 ;
struct V_43 * V_44 = V_6 -> V_7 . V_45 ;
struct V_26 * V_26 ;
int V_39 ;
if ( ! V_44 ) {
F_3 ( & V_6 -> V_7 , L_6 ) ;
return - V_46 ;
}
if ( ! F_26 ( V_6 -> V_47 ,
V_48 ) )
return - V_49 ;
V_22 = F_27 ( sizeof( struct V_1 ) , V_50 ) ;
V_26 = F_28 () ;
if ( ! V_22 || ! V_26 ) {
V_39 = - V_51 ;
goto V_52;
}
V_22 -> V_6 = V_6 ;
V_22 -> V_24 = V_6 -> V_24 ;
V_22 -> V_27 = V_26 ;
F_29 ( & V_22 -> V_34 ) ;
V_22 -> V_53 = V_44 -> V_53 ;
V_22 -> V_21 = V_44 -> V_21 ;
V_22 -> V_29 = V_44 -> V_29 ? : V_20 ;
V_22 -> V_54 = V_44 -> V_54 ? : 1 ;
V_22 -> V_35 = V_44 -> V_35 ? : 1 ;
V_22 -> V_23 = V_44 -> V_23 ;
V_22 -> V_36 = V_44 -> V_36 ;
if ( V_44 -> V_21 == 0 ) {
F_3 ( & V_6 -> V_7 , L_7 ) ;
V_39 = - V_46 ;
goto V_52;
}
snprintf ( V_22 -> V_55 , sizeof( V_22 -> V_55 ) ,
L_8 , F_30 ( & V_6 -> V_7 ) ) ;
V_26 -> V_56 = L_9 ;
V_26 -> V_55 = V_22 -> V_55 ;
V_26 -> V_42 . V_57 = V_58 ;
V_26 -> V_59 = F_21 ;
V_26 -> V_60 = F_24 ;
F_31 ( V_26 , V_22 ) ;
V_26 -> V_61 [ 0 ] = F_32 ( V_62 ) | F_32 ( V_63 ) ;
V_26 -> V_64 [ F_33 ( V_30 ) ] = F_32 ( V_30 ) ;
F_34 ( V_26 , V_31 , 0 , V_20 , V_44 -> V_65 , 0 ) ;
F_34 ( V_26 , V_32 , 0 , V_20 , V_44 -> V_66 , 0 ) ;
F_34 ( V_26 , V_33 , 0 , V_20 ,
V_44 -> V_67 , 0 ) ;
if ( V_44 -> V_68 )
V_44 -> V_68 () ;
V_39 = F_35 ( V_22 -> V_24 , F_16 , F_10 ,
V_69 , V_6 -> V_7 . V_70 -> V_56 , V_22 ) ;
if ( V_39 < 0 ) {
F_3 ( & V_6 -> V_7 , L_10 , V_22 -> V_24 ) ;
goto V_52;
}
F_17 ( V_22 ) ;
V_39 = F_36 ( V_26 ) ;
if ( V_39 )
goto V_71;
F_37 ( V_6 , V_22 ) ;
return 0 ;
V_71:
F_38 ( V_22 -> V_24 , V_22 ) ;
if ( V_44 -> V_72 )
V_44 -> V_72 () ;
V_52:
F_39 ( V_26 ) ;
F_40 ( V_22 ) ;
return V_39 ;
}
static int T_7 F_41 ( struct V_40 * V_6 )
{
struct V_1 * V_22 = F_42 ( V_6 ) ;
struct V_43 * V_44 = V_6 -> V_7 . V_45 ;
F_38 ( V_22 -> V_24 , V_22 ) ;
if ( V_44 -> V_72 )
V_44 -> V_72 () ;
F_43 ( V_22 -> V_27 ) ;
F_40 ( V_22 ) ;
return 0 ;
}
