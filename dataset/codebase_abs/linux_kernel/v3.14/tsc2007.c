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
return V_22 -> V_23 ( & V_22 -> V_6 -> V_7 ) ;
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
if ( ! V_19 && ! V_22 -> V_23 ) {
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
if ( F_9 ( V_22 ) )
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
static int F_25 ( struct V_40 * V_7 )
{
struct V_41 * V_6 = F_26 ( V_7 ) ;
struct V_1 * V_22 = F_27 ( V_6 ) ;
return ! F_28 ( V_22 -> V_42 ) ;
}
static int F_29 ( struct V_41 * V_6 , struct V_1 * V_22 )
{
struct V_43 * V_44 = V_6 -> V_7 . V_45 ;
T_4 V_46 ;
T_6 V_47 ;
if ( ! V_44 ) {
F_3 ( & V_6 -> V_7 , L_6 ) ;
return - V_48 ;
}
if ( ! F_30 ( V_44 , L_7 , & V_46 ) )
V_22 -> V_29 = V_46 ;
else
V_22 -> V_29 = V_20 ;
if ( ! F_30 ( V_44 , L_8 , & V_46 ) )
V_22 -> V_49 = V_46 ;
if ( ! F_30 ( V_44 , L_9 , & V_46 ) )
V_22 -> V_50 = V_46 ;
if ( ! F_30 ( V_44 , L_10 , & V_46 ) )
V_22 -> V_51 = V_46 ;
if ( ! F_31 ( V_44 , L_11 , & V_47 ) )
V_22 -> V_35 = V_47 ;
else
V_22 -> V_35 = 1 ;
if ( ! F_30 ( V_44 , L_12 , & V_46 ) ) {
V_22 -> V_21 = V_46 ;
} else {
F_3 ( & V_6 -> V_7 , L_13 ) ;
return - V_48 ;
}
V_22 -> V_42 = F_32 ( V_44 , 0 ) ;
if ( F_33 ( V_22 -> V_42 ) )
V_22 -> V_23 = F_25 ;
else
F_34 ( & V_6 -> V_7 ,
L_14 ,
V_22 -> V_42 ) ;
return 0 ;
}
static int F_29 ( struct V_41 * V_6 , struct V_1 * V_22 )
{
F_3 ( & V_6 -> V_7 , L_15 ) ;
return - V_48 ;
}
static int F_35 ( struct V_41 * V_6 , struct V_1 * V_22 ,
const struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
V_22 -> V_56 = V_53 -> V_56 ;
V_22 -> V_21 = V_53 -> V_21 ;
V_22 -> V_29 = V_53 -> V_29 ? : V_20 ;
V_22 -> V_35 = V_53 -> V_35 ? : 1 ;
V_22 -> V_23 = V_53 -> V_23 ;
V_22 -> V_36 = V_53 -> V_36 ;
V_22 -> V_49 = V_53 -> V_49 ;
V_22 -> V_50 = V_53 -> V_50 ;
V_22 -> V_51 = V_53 -> V_51 ;
if ( V_53 -> V_21 == 0 ) {
F_3 ( & V_6 -> V_7 , L_16 ) ;
return - V_48 ;
}
return 0 ;
}
static void F_36 ( void * V_4 )
{
struct V_40 * V_7 = V_4 ;
const struct V_52 * V_53 = F_37 ( V_7 ) ;
V_53 -> V_57 () ;
}
static int F_38 ( struct V_41 * V_6 ,
const struct V_54 * V_55 )
{
const struct V_52 * V_53 = F_37 ( & V_6 -> V_7 ) ;
struct V_1 * V_22 ;
struct V_26 * V_26 ;
int V_39 ;
if ( ! F_39 ( V_6 -> V_58 ,
V_59 ) )
return - V_60 ;
V_22 = F_40 ( & V_6 -> V_7 , sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_22 )
return - V_62 ;
if ( V_53 )
V_39 = F_35 ( V_6 , V_22 , V_53 , V_55 ) ;
else
V_39 = F_29 ( V_6 , V_22 ) ;
if ( V_39 )
return V_39 ;
V_26 = F_41 ( & V_6 -> V_7 ) ;
if ( ! V_26 )
return - V_62 ;
F_42 ( V_6 , V_22 ) ;
V_22 -> V_6 = V_6 ;
V_22 -> V_24 = V_6 -> V_24 ;
V_22 -> V_27 = V_26 ;
F_43 ( & V_22 -> V_34 ) ;
snprintf ( V_22 -> V_63 , sizeof( V_22 -> V_63 ) ,
L_17 , F_44 ( & V_6 -> V_7 ) ) ;
V_26 -> V_64 = L_18 ;
V_26 -> V_63 = V_22 -> V_63 ;
V_26 -> V_55 . V_65 = V_66 ;
V_26 -> V_67 = F_21 ;
V_26 -> V_68 = F_24 ;
F_45 ( V_26 , V_22 ) ;
V_26 -> V_69 [ 0 ] = F_46 ( V_70 ) | F_46 ( V_71 ) ;
V_26 -> V_72 [ F_47 ( V_30 ) ] = F_46 ( V_30 ) ;
F_48 ( V_26 , V_31 , 0 , V_20 , V_22 -> V_49 , 0 ) ;
F_48 ( V_26 , V_32 , 0 , V_20 , V_22 -> V_50 , 0 ) ;
F_48 ( V_26 , V_33 , 0 , V_20 ,
V_22 -> V_51 , 0 ) ;
if ( V_53 ) {
if ( V_53 -> V_57 ) {
V_39 = F_49 ( & V_6 -> V_7 ,
F_36 ,
& V_6 -> V_7 ) ;
if ( V_39 ) {
F_3 ( & V_6 -> V_7 ,
L_19 ,
V_39 ) ;
return V_39 ;
}
}
if ( V_53 -> V_73 )
V_53 -> V_73 () ;
}
V_39 = F_50 ( & V_6 -> V_7 , V_22 -> V_24 ,
F_16 , F_10 ,
V_74 ,
V_6 -> V_7 . V_75 -> V_64 , V_22 ) ;
if ( V_39 ) {
F_3 ( & V_6 -> V_7 , L_20 ,
V_22 -> V_24 , V_39 ) ;
return V_39 ;
}
F_17 ( V_22 ) ;
V_39 = F_51 ( V_26 ) ;
if ( V_39 ) {
F_3 ( & V_6 -> V_7 ,
L_21 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
