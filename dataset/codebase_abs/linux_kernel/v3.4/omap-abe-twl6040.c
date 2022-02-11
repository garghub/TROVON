static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 -> V_16 ) ;
int V_17 , V_18 ;
int V_19 ;
V_17 = F_3 ( V_6 -> V_11 ) ;
if ( V_17 == V_20 )
V_18 = V_15 -> V_21 ;
else if ( V_17 == V_22 )
V_18 = 32768 ;
else
return - V_23 ;
V_19 = F_4 ( V_9 , V_17 , V_18 ,
V_24 ) ;
if ( V_19 ) {
F_5 ( V_25 L_1 ) ;
return V_19 ;
}
return V_19 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_26 = V_6 -> V_26 ;
int V_19 = 0 ;
V_19 = F_4 ( V_26 , V_27 ,
19200000 , V_24 ) ;
if ( V_19 < 0 ) {
F_5 ( V_25 L_2 ) ;
return V_19 ;
}
V_19 = F_4 ( V_26 , V_28 , 2400000 ,
V_29 ) ;
if ( V_19 < 0 ) {
F_5 ( V_25 L_3 ) ;
return V_19 ;
}
return 0 ;
}
static inline void F_7 ( struct V_30 * V_31 ,
int V_32 , char * V_33 )
{
if ( ! V_32 )
F_8 ( V_31 , V_33 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_30 * V_31 = & V_11 -> V_31 ;
struct V_14 * V_15 = F_2 ( V_13 -> V_16 ) ;
int V_34 ;
int V_19 = 0 ;
F_7 ( V_31 , V_15 -> V_35 , L_4 ) ;
F_7 ( V_31 , V_15 -> V_36 , L_5 ) ;
F_7 ( V_31 , V_15 -> V_37 , L_6 ) ;
F_7 ( V_31 , V_15 -> V_38 , L_7 ) ;
F_7 ( V_31 , V_15 -> V_39 , L_8 ) ;
F_7 ( V_31 , V_15 -> V_40 , L_9 ) ;
F_7 ( V_31 , V_15 -> V_41 , L_10 ) ;
F_7 ( V_31 , V_15 -> V_42 , L_11 ) ;
F_7 ( V_31 , V_15 -> V_43 , L_12 ) ;
V_34 = F_10 ( V_11 , V_44 ) ;
F_11 ( V_6 , F_12 ( V_34 ) ,
F_13 ( V_34 ) ) ;
if ( V_15 -> V_45 ) {
V_19 = F_14 ( V_11 , L_13 ,
V_46 , & V_47 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_15 ( & V_47 , F_16 ( V_48 ) ,
V_48 ) ;
F_17 ( V_11 , & V_47 , V_46 ) ;
}
return V_19 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_30 * V_31 = & V_11 -> V_31 ;
int V_19 ;
V_19 = F_19 ( V_31 , V_49 ,
F_16 ( V_49 ) ) ;
if ( V_19 )
return V_19 ;
return F_20 ( V_31 , V_50 ,
F_16 ( V_50 ) ) ;
}
static T_1 int F_21 ( struct V_51 * V_52 )
{
struct V_14 * V_15 = F_2 ( & V_52 -> V_16 ) ;
struct V_12 * V_13 = & V_53 ;
int V_19 ;
V_13 -> V_16 = & V_52 -> V_16 ;
if ( ! V_15 ) {
F_22 ( & V_52 -> V_16 , L_14 ) ;
return - V_54 ;
}
if ( V_15 -> V_55 ) {
V_13 -> V_56 = V_15 -> V_55 ;
} else {
F_22 ( & V_52 -> V_16 , L_15 ) ;
return - V_54 ;
}
if ( ! V_15 -> V_21 ) {
F_22 ( & V_52 -> V_16 , L_16 ) ;
return - V_54 ;
}
if ( V_15 -> V_57 ) {
V_13 -> V_58 = V_59 ;
V_13 -> V_60 = F_16 ( V_59 ) ;
} else {
V_13 -> V_58 = V_61 ;
V_13 -> V_60 = F_16 ( V_61 ) ;
}
V_19 = F_23 ( V_13 ) ;
if ( V_19 )
F_22 ( & V_52 -> V_16 , L_17 ,
V_19 ) ;
return V_19 ;
}
static int T_2 F_24 ( struct V_51 * V_52 )
{
struct V_12 * V_13 = F_25 ( V_52 ) ;
F_26 ( V_13 ) ;
return 0 ;
}
