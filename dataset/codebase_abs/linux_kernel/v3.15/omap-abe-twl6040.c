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
static int F_7 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
int V_29 ;
int V_18 = 0 ;
V_29 = F_8 ( V_11 , V_30 ) ;
F_9 ( V_6 , F_10 ( V_29 ) ,
F_11 ( V_29 ) ) ;
if ( V_15 -> V_31 ) {
V_18 = F_12 ( V_11 , L_4 ,
V_32 , & V_33 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( & V_33 , F_14 ( V_34 ) ,
V_34 ) ;
F_15 ( V_11 , & V_33 , V_32 ) ;
}
return V_18 ;
}
static int F_16 ( struct V_5 * V_6 )
{
struct V_35 * V_36 = & V_6 -> V_13 -> V_36 ;
return F_17 ( V_36 , V_37 ,
F_14 ( V_37 ) ) ;
}
static int F_18 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_42 . V_43 ;
struct V_12 * V_13 = & V_44 ;
struct V_40 * V_45 ;
struct V_14 * V_15 ;
int V_46 = 0 ;
int V_18 = 0 ;
if ( ! V_41 ) {
F_19 ( & V_39 -> V_42 , L_5 ) ;
return - V_47 ;
}
V_13 -> V_42 = & V_39 -> V_42 ;
V_15 = F_20 ( & V_39 -> V_42 , sizeof( struct V_14 ) , V_48 ) ;
if ( V_15 == NULL )
return - V_49 ;
V_15 -> V_50 = F_21 ( - V_22 ) ;
if ( F_22 ( V_13 , L_6 ) ) {
F_19 ( & V_39 -> V_42 , L_7 ) ;
return - V_47 ;
}
V_18 = F_23 ( V_13 , L_8 ) ;
if ( V_18 ) {
F_19 ( & V_39 -> V_42 , L_9 ) ;
return V_18 ;
}
V_45 = F_24 ( V_41 , L_10 , 0 ) ;
if ( ! V_45 ) {
F_19 ( & V_39 -> V_42 , L_11 ) ;
return - V_22 ;
}
V_51 [ 0 ] . V_52 = NULL ;
V_51 [ 0 ] . V_53 = V_45 ;
V_45 = F_24 ( V_41 , L_12 , 0 ) ;
if ( V_45 ) {
V_46 = 2 ;
V_51 [ 1 ] . V_52 = NULL ;
V_51 [ 1 ] . V_53 = V_45 ;
V_15 -> V_50 = F_25 (
L_13 , - 1 , NULL , 0 ) ;
if ( F_26 ( V_15 -> V_50 ) ) {
F_19 ( & V_39 -> V_42 , L_14 ) ;
return F_27 ( V_15 -> V_50 ) ;
}
} else {
V_46 = 1 ;
}
V_15 -> V_31 = F_28 ( V_41 , L_15 ) ;
F_29 ( V_41 , L_16 , & V_15 -> V_20 ) ;
if ( ! V_15 -> V_20 ) {
F_19 ( & V_39 -> V_42 , L_17 ) ;
V_18 = - V_22 ;
goto V_54;
}
V_13 -> V_55 = 1 ;
if ( ! V_15 -> V_20 ) {
F_19 ( & V_39 -> V_42 , L_18 ) ;
V_18 = - V_47 ;
goto V_54;
}
V_13 -> V_56 = V_51 ;
V_13 -> V_46 = V_46 ;
F_30 ( V_13 , V_15 ) ;
V_18 = F_31 ( V_13 ) ;
if ( V_18 ) {
F_19 ( & V_39 -> V_42 , L_19 ,
V_18 ) ;
goto V_54;
}
return 0 ;
V_54:
if ( ! F_26 ( V_15 -> V_50 ) )
F_32 ( V_15 -> V_50 ) ;
return V_18 ;
}
static int F_33 ( struct V_38 * V_39 )
{
struct V_12 * V_13 = F_34 ( V_39 ) ;
struct V_14 * V_15 = F_2 ( V_13 ) ;
F_35 ( V_13 ) ;
if ( ! F_26 ( V_15 -> V_50 ) )
F_32 ( V_15 -> V_50 ) ;
return 0 ;
}
