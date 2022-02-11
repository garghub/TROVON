static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
T_1 V_5 = V_4 -> V_6 ;
T_1 V_7 = V_4 -> V_8 ;
T_1 V_9 = 0 ;
if ( V_4 -> V_10 == V_11 ) {
V_5 = V_12 ;
} else if ( V_4 -> V_10 == V_13 ) {
if ( V_4 -> V_14 ) {
V_5 = V_15 ;
} else {
V_5 = V_16 ;
V_9 = V_17 ;
}
} else if ( F_2 ( V_4 -> V_10 ) ) {
if ( V_2 == V_18 ) {
V_9 = V_19 ;
} else {
V_5 = V_16 ;
if ( V_2 == V_20 )
V_9 = V_21 ;
else if ( V_2 == V_22 )
V_9 = V_23 ;
}
}
if ( V_5 == V_16 && V_4 -> V_24 && V_9 )
F_3 ( V_4 -> V_24 , V_9 ) ;
F_4 ( V_4 -> V_25 , V_7 , V_26 ,
V_27 [ V_5 ] ) ;
}
static void F_5 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
T_1 V_7 = V_4 -> V_8 ;
T_1 V_9 = 0 ;
T_1 V_28 = 0 ;
if ( V_4 -> V_10 == V_11 ) {
V_28 = V_29 ;
} else if ( V_4 -> V_10 == V_13 ) {
if ( ! V_4 -> V_14 ) {
V_28 = V_30 ;
V_9 = V_17 ;
}
} else if ( F_2 ( V_4 -> V_10 ) ) {
V_28 = V_29 ;
if ( V_2 == V_18 )
V_9 = V_19 ;
else if ( V_2 == V_20 )
V_9 = V_21 ;
else if ( V_2 == V_22 )
V_9 = V_23 ;
}
if ( V_4 -> V_24 && V_9 )
F_3 ( V_4 -> V_24 , V_9 ) ;
F_4 ( V_4 -> V_25 , V_7 , V_31 , V_28 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
struct V_25 * V_25 = V_4 -> V_25 ;
int V_32 = V_4 -> V_10 ;
struct V_33 * V_34 = V_4 -> V_34 ;
struct V_35 * V_36 = V_34 -> V_37 ;
T_1 V_7 = V_4 -> V_8 ;
T_1 V_28 ;
if ( V_4 -> V_24 )
F_7 ( V_4 -> V_24 ) ;
if ( F_8 ( V_36 , L_1 ) )
F_4 ( V_25 , V_7 , V_38 , V_39 ) ;
F_4 ( V_25 , V_7 , V_40 , V_41 [ V_32 ] ) ;
V_28 = ( V_32 == V_42 ) ? 0 : V_43 ;
F_4 ( V_25 , V_7 , V_44 , V_28 ) ;
}
static int F_9 ( struct V_45 * V_46 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
T_1 V_2 = V_4 -> V_47 ;
F_6 ( V_4 ) ;
F_1 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_10 ( struct V_45 * V_46 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
T_1 V_2 = V_4 -> V_47 ;
F_6 ( V_4 ) ;
F_5 ( V_1 , V_2 ) ;
return 0 ;
}
static void F_11 ( struct V_45 * V_46 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_24 )
F_12 ( V_4 -> V_24 ) ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_45 * V_46 )
{
struct V_48 * V_49 ;
struct V_33 * V_34 = & V_46 -> V_34 ;
struct V_35 * V_36 = V_34 -> V_37 ;
struct V_25 * V_25 ;
int V_50 ;
if ( ! V_36 )
return - V_51 ;
V_49 = F_14 ( V_46 , V_52 , L_2 ) ;
if ( ! V_49 )
return - V_53 ;
V_4 -> V_8 = V_49 -> V_54 ;
V_4 -> V_55 = - V_56 ;
V_49 = F_14 ( V_46 , V_52 , L_3 ) ;
if ( V_49 )
V_4 -> V_55 = V_49 -> V_54 ;
V_25 = F_15 ( V_36 , L_4 ) ;
if ( F_16 ( V_25 ) )
return F_17 ( V_25 ) ;
V_4 -> V_34 = V_34 ;
V_4 -> V_10 = F_18 ( V_36 ) ;
V_4 -> V_25 = V_25 ;
V_4 -> V_14 = F_8 ( V_36 , L_5 ) ;
V_4 -> V_6 = V_57 ;
V_4 -> V_47 = V_20 ;
if ( F_19 ( V_4 -> V_10 ) ) {
const char * V_58 ;
V_4 -> V_6 = V_16 ;
V_50 = F_20 ( V_36 , L_6 , & V_58 ) ;
if ( V_50 < 0 )
F_21 ( V_34 , L_7 ) ;
if ( ! strcasecmp ( V_58 , L_8 ) )
V_4 -> V_6 = V_59 ;
else if ( ! strcasecmp ( V_58 , L_9 ) )
V_4 -> V_6 = V_12 ;
V_4 -> V_47 = V_18 ;
}
V_4 -> V_24 = F_22 ( V_34 , L_10 ) ;
if ( F_16 ( V_4 -> V_24 ) ) {
F_21 ( V_34 , L_11 ) ;
V_4 -> V_24 = NULL ;
}
return 0 ;
}
static void * F_23 ( struct V_45 * V_46 )
{
struct V_3 * V_4 ;
int V_60 ;
V_4 = F_24 ( & V_46 -> V_34 , sizeof( * V_4 ) , V_61 ) ;
if ( ! V_4 )
return F_25 ( - V_62 ) ;
V_60 = F_13 ( V_4 , V_46 ) ;
if ( V_60 ) {
F_26 ( & V_46 -> V_34 , L_12 ) ;
return F_25 ( V_60 ) ;
}
return V_4 ;
}
