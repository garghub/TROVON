static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( V_2 ) ;
int V_5 ;
F_5 ( V_4 , L_1 , V_4 ) ;
V_5 = F_6 ( V_4 ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 -> V_6 . V_7 , L_2 ,
V_2 -> V_6 . V_8 ) ;
F_8 ( V_2 ) ;
return V_5 ;
}
return 0 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
V_12 = V_10 -> V_19 . V_20 ;
if ( ! V_12 ) {
F_7 ( & V_10 -> V_19 , L_3 ) ;
return - V_21 ;
}
if ( ! V_10 -> V_19 . V_22 )
V_10 -> V_19 . V_22 = & V_23 ;
if ( ! V_10 -> V_19 . V_24 )
V_10 -> V_19 . V_24 = F_10 ( 32 ) ;
V_14 = F_11 ( & V_10 -> V_19 , sizeof( struct V_13 ) ,
V_25 ) ;
if ( ! V_14 )
return - V_26 ;
V_14 -> V_19 = & V_10 -> V_19 ;
V_2 = F_12 ( & V_27 , & V_10 -> V_19 ,
F_13 ( & V_10 -> V_19 ) ) ;
if ( ! V_2 ) {
F_7 ( & V_10 -> V_19 , L_4 ) ;
return - V_26 ;
}
V_14 -> V_2 = V_2 ;
V_14 -> V_28 = F_14 ( & V_10 -> V_19 , L_5 ) ;
if ( F_15 ( V_14 -> V_28 ) ) {
F_7 ( & V_10 -> V_19 , L_6 ) ;
V_18 = F_16 ( V_14 -> V_28 ) ;
goto V_29;
}
V_18 = F_17 ( V_14 -> V_28 ) ;
if ( V_18 )
goto V_29;
V_16 = F_18 ( V_10 , V_30 , 0 ) ;
if ( ! V_16 ) {
F_7 ( & V_10 -> V_19 , L_7 ) ;
V_18 = - V_31 ;
goto V_32;
}
V_2 -> V_33 = V_16 -> V_34 ;
V_2 -> V_35 = F_19 ( V_16 ) ;
V_2 -> V_36 = F_20 ( & V_10 -> V_19 , V_16 -> V_34 , V_2 -> V_35 ) ;
if ( ! V_2 -> V_36 ) {
F_7 ( & V_10 -> V_19 , L_8 ) ;
V_18 = - V_26 ;
goto V_32;
}
V_17 = F_21 ( V_10 , 0 ) ;
if ( ! V_17 ) {
F_7 ( & V_10 -> V_19 , L_9 ) ;
V_18 = - V_37 ;
goto V_32;
}
if ( V_12 -> V_38 )
V_12 -> V_38 ( V_10 , V_39 ) ;
V_4 = F_3 ( V_2 ) ;
F_22 ( V_4 ) ;
V_18 = F_23 ( V_2 , V_17 , V_40 ) ;
if ( V_18 ) {
F_7 ( & V_10 -> V_19 , L_10 ) ;
goto V_32;
}
F_24 ( V_10 , V_14 ) ;
return 0 ;
V_32:
F_25 ( V_14 -> V_28 ) ;
V_29:
F_26 ( V_2 ) ;
return V_18 ;
}
static int F_27 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_19 . V_20 ;
struct V_13 * V_14 = F_28 ( V_10 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_29 ( V_2 ) ;
if ( V_12 && V_12 -> V_41 )
V_12 -> V_41 ( V_10 , V_39 ) ;
F_25 ( V_14 -> V_28 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = F_28 ( V_10 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_2 -> V_42 -> V_43 )
V_2 -> V_42 -> V_43 ( V_2 ) ;
}
static int F_31 ( struct V_44 * V_19 )
{
struct V_13 * V_14 = F_32 ( V_19 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = F_3 ( V_2 ) ;
struct V_9 * V_10 = F_33 ( V_19 ) ;
struct V_11 * V_12 = V_10 -> V_19 . V_20 ;
unsigned long V_45 ;
int V_46 = 0 ;
F_34 ( & V_4 -> V_47 , V_45 ) ;
if ( V_4 -> V_48 != V_49 &&
V_4 -> V_48 != V_50 ) {
V_46 = - V_21 ;
goto V_51;
}
F_35 ( V_52 , & V_2 -> V_45 ) ;
if ( V_12 && V_12 -> V_41 )
V_12 -> V_41 ( V_10 , V_39 ) ;
F_25 ( V_14 -> V_28 ) ;
V_51:
F_36 ( & V_4 -> V_47 , V_45 ) ;
return V_46 ;
}
static int F_37 ( struct V_44 * V_19 )
{
struct V_13 * V_14 = F_32 ( V_19 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_9 * V_10 = F_33 ( V_19 ) ;
struct V_11 * V_12 = V_10 -> V_19 . V_20 ;
F_17 ( V_14 -> V_28 ) ;
if ( V_12 && V_12 -> V_38 )
V_12 -> V_38 ( V_10 , V_39 ) ;
F_38 ( V_2 , false ) ;
return 0 ;
}
