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
static int F_6 ( struct V_32 * V_33 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_25 * V_25 = V_4 -> V_25 ;
int V_34 = V_4 -> V_10 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_39 ;
T_1 V_7 = V_4 -> V_8 ;
T_1 V_28 ;
if ( V_4 -> V_24 )
F_7 ( V_4 -> V_24 ) ;
if ( F_8 ( V_38 , L_1 ) )
F_4 ( V_25 , V_7 , V_40 , V_41 ) ;
F_4 ( V_25 , V_7 , V_42 , V_43 [ V_34 ] ) ;
V_28 = ( V_34 == V_44 ) ? 0 : V_45 ;
F_4 ( V_25 , V_7 , V_46 , V_28 ) ;
V_4 -> V_47 ( V_1 , V_4 -> V_48 ) ;
return 0 ;
}
static void F_9 ( struct V_32 * V_33 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_24 )
F_10 ( V_4 -> V_24 ) ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_32 * V_33 )
{
struct V_49 * V_50 ;
struct V_35 * V_36 = & V_33 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_39 ;
struct V_25 * V_25 ;
int V_51 ;
if ( ! V_38 )
return - V_52 ;
V_4 -> V_53 = - V_54 ;
V_50 = F_12 ( V_33 , V_55 , L_2 ) ;
if ( V_50 )
V_4 -> V_53 = V_50 -> V_56 ;
V_25 = F_13 ( V_38 , L_3 ) ;
if ( F_14 ( V_25 ) )
return F_15 ( V_25 ) ;
V_51 = F_16 ( V_38 , L_3 , 1 , & V_4 -> V_8 ) ;
if ( V_51 ) {
F_17 ( V_36 , L_4 , V_51 ) ;
return V_51 ;
}
V_4 -> V_36 = V_36 ;
V_4 -> V_10 = F_18 ( V_38 ) ;
V_4 -> V_25 = V_25 ;
V_4 -> V_14 = F_8 ( V_38 , L_5 ) ;
V_4 -> V_6 = V_57 ;
V_4 -> V_48 = V_20 ;
if ( F_19 ( V_4 -> V_10 ) ) {
const char * V_58 ;
V_4 -> V_6 = V_16 ;
V_51 = F_20 ( V_38 , L_6 , & V_58 ) ;
if ( V_51 < 0 ) {
F_21 ( V_36 , L_7 ) ;
} else {
if ( ! strcasecmp ( V_58 , L_8 ) )
V_4 -> V_6 = V_59 ;
else if ( ! strcasecmp ( V_58 , L_9 ) )
V_4 -> V_6 = V_12 ;
}
V_4 -> V_48 = V_18 ;
}
V_4 -> V_24 = F_22 ( V_36 , L_10 ) ;
if ( F_14 ( V_4 -> V_24 ) ) {
F_21 ( V_36 , L_11 ) ;
V_4 -> V_24 = NULL ;
}
return 0 ;
}
static int F_23 ( struct V_32 * V_33 )
{
struct V_60 * V_61 ;
const struct V_62 * V_63 ;
struct V_64 V_65 ;
struct V_3 * V_4 ;
int V_66 ;
V_63 = F_24 ( & V_33 -> V_36 ) ;
if ( ! V_63 ) {
F_17 ( & V_33 -> V_36 , L_12 ) ;
return - V_52 ;
}
V_66 = F_25 ( V_33 , & V_65 ) ;
if ( V_66 )
return V_66 ;
V_61 = F_26 ( V_33 , & V_65 . V_67 ) ;
if ( F_14 ( V_61 ) )
return F_15 ( V_61 ) ;
V_4 = F_27 ( & V_33 -> V_36 , sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
return - V_69 ;
V_66 = F_11 ( V_4 , V_33 ) ;
if ( V_66 ) {
F_17 ( & V_33 -> V_36 , L_13 ) ;
return V_66 ;
}
V_4 -> V_47 = V_63 -> V_47 ;
V_61 -> V_70 = V_4 ;
V_61 -> V_71 = F_6 ;
V_61 -> exit = F_9 ;
V_61 -> V_72 = V_63 -> V_47 ;
V_66 = F_6 ( V_33 , V_61 -> V_70 ) ;
if ( V_66 )
return V_66 ;
return F_28 ( & V_33 -> V_36 , V_61 , & V_65 ) ;
}
