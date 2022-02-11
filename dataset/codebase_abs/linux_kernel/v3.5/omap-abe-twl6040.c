static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_16 , V_17 ;
int V_18 ;
V_16 = F_3 ( V_6 -> V_11 ) ;
if ( V_16 == V_19 )
V_17 = V_15 -> V_20 ;
else if ( V_16 == V_21 )
V_17 = 32768 ;
else
return - V_22 ;
V_18 = F_4 ( V_9 , V_16 , V_17 ,
V_23 ) ;
if ( V_18 ) {
F_5 ( V_24 L_1 ) ;
return V_18 ;
}
return V_18 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_25 = V_6 -> V_25 ;
int V_18 = 0 ;
V_18 = F_4 ( V_25 , V_26 ,
19200000 , V_23 ) ;
if ( V_18 < 0 ) {
F_5 ( V_24 L_2 ) ;
return V_18 ;
}
V_18 = F_4 ( V_25 , V_27 , 2400000 ,
V_28 ) ;
if ( V_18 < 0 ) {
F_5 ( V_24 L_3 ) ;
return V_18 ;
}
return 0 ;
}
static inline void F_7 ( struct V_29 * V_30 ,
int V_31 , char * V_32 )
{
if ( ! V_31 )
F_8 ( V_30 , V_32 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_29 * V_30 = & V_11 -> V_30 ;
struct V_33 * V_34 = F_10 ( V_13 -> V_35 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_36 ;
int V_18 = 0 ;
F_7 ( V_30 , V_34 -> V_37 , L_4 ) ;
F_7 ( V_30 , V_34 -> V_38 , L_5 ) ;
F_7 ( V_30 , V_34 -> V_39 , L_6 ) ;
F_7 ( V_30 , V_34 -> V_40 , L_7 ) ;
F_7 ( V_30 , V_34 -> V_41 , L_8 ) ;
F_7 ( V_30 , V_34 -> V_42 , L_9 ) ;
F_7 ( V_30 , V_34 -> V_43 , L_10 ) ;
F_7 ( V_30 , V_34 -> V_44 , L_11 ) ;
F_7 ( V_30 , V_34 -> V_45 , L_12 ) ;
V_36 = F_11 ( V_11 , V_46 ) ;
F_12 ( V_6 , F_13 ( V_36 ) ,
F_14 ( V_36 ) ) ;
if ( V_15 -> V_47 ) {
V_18 = F_15 ( V_11 , L_13 ,
V_48 , & V_49 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_16 ( & V_49 , F_17 ( V_50 ) ,
V_50 ) ;
F_18 ( V_11 , & V_49 , V_48 ) ;
}
return V_18 ;
}
static int F_19 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_29 * V_30 = & V_11 -> V_30 ;
return F_20 ( V_30 , V_51 ,
F_17 ( V_51 ) ) ;
}
static T_1 int F_21 ( struct V_52 * V_53 )
{
struct V_33 * V_34 = F_10 ( & V_53 -> V_35 ) ;
struct V_12 * V_13 = & V_54 ;
struct V_14 * V_15 ;
int V_55 = 0 ;
int V_18 ;
V_13 -> V_35 = & V_53 -> V_35 ;
if ( ! V_34 ) {
F_22 ( & V_53 -> V_35 , L_14 ) ;
return - V_56 ;
}
V_15 = F_23 ( & V_53 -> V_35 , sizeof( struct V_14 ) , V_57 ) ;
if ( V_15 == NULL )
return - V_58 ;
if ( V_34 -> V_59 ) {
V_13 -> V_60 = V_34 -> V_59 ;
} else {
F_22 ( & V_53 -> V_35 , L_15 ) ;
return - V_56 ;
}
V_15 -> V_47 = V_34 -> V_47 ;
V_15 -> V_20 = V_34 -> V_20 ;
if ( ! V_15 -> V_20 ) {
F_22 ( & V_53 -> V_35 , L_16 ) ;
return - V_56 ;
}
if ( V_34 -> V_61 )
V_55 = 2 ;
else
V_55 = 1 ;
V_13 -> V_62 = V_63 ;
V_13 -> V_55 = V_55 ;
F_24 ( V_13 , V_15 ) ;
V_18 = F_25 ( V_13 ) ;
if ( V_18 )
F_22 ( & V_53 -> V_35 , L_17 ,
V_18 ) ;
return V_18 ;
}
static int T_2 F_26 ( struct V_52 * V_53 )
{
struct V_12 * V_13 = F_27 ( V_53 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
