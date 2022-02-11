static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_2 -> V_6 )
F_3 ( V_2 -> V_6 ) ;
else if ( V_2 -> V_7 && V_2 -> V_7 -> V_8 )
V_2 -> V_7 -> V_8 ( V_4 , V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_2 -> V_6 )
F_5 ( V_2 -> V_6 ) ;
else if ( V_2 -> V_7 && V_2 -> V_7 -> V_10 )
V_2 -> V_7 -> V_10 ( V_4 , V_9 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
return F_7 ( F_8 ( V_12 ) ) ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_8 ( V_12 ) ;
int V_15 ;
F_10 ( V_14 , L_1 , V_14 ) ;
V_15 = F_11 ( V_14 ) ;
if ( V_15 < 0 ) {
F_12 ( V_12 -> V_16 . V_17 , L_2 ,
V_12 -> V_16 . V_18 ) ;
F_13 ( V_12 ) ;
return V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_19 * V_7 = F_15 ( & V_4 -> V_5 ) ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_20 * V_21 ;
struct V_22 * V_6 ;
int V_23 ;
int V_24 ;
if ( ! V_4 -> V_5 . V_25 )
V_4 -> V_5 . V_25 = & V_4 -> V_5 . V_26 ;
if ( ! V_4 -> V_5 . V_26 )
V_4 -> V_5 . V_26 = F_16 ( 32 ) ;
V_2 = F_17 ( & V_4 -> V_5 , sizeof( struct V_1 ) ,
V_27 ) ;
if ( ! V_2 )
return - V_28 ;
if ( F_18 ( V_4 -> V_5 . V_29 ,
L_3 ) )
goto V_30;
V_6 = F_19 ( & V_4 -> V_5 , V_31 ) ;
if ( F_20 ( V_6 ) ) {
if ( ! V_7 ) {
F_21 ( & V_4 -> V_5 , L_4 ) ;
return - V_32 ;
} else {
V_2 -> V_7 = V_7 ;
}
} else {
V_2 -> V_6 = V_6 ;
V_2 -> V_33 = V_6 -> V_33 ;
}
V_30:
V_2 -> V_5 = & V_4 -> V_5 ;
V_12 = F_22 ( & V_34 , & V_4 -> V_5 ,
F_23 ( & V_4 -> V_5 ) ) ;
if ( ! V_12 ) {
F_12 ( & V_4 -> V_5 , L_5 ) ;
return - V_28 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_35 = F_24 ( & V_4 -> V_5 , L_6 ) ;
if ( F_20 ( V_2 -> V_35 ) ) {
F_12 ( & V_4 -> V_5 , L_7 ) ;
V_24 = F_25 ( V_2 -> V_35 ) ;
goto V_36;
}
V_24 = F_26 ( V_2 -> V_35 ) ;
if ( V_24 )
goto V_36;
V_21 = F_27 ( V_4 , V_37 , 0 ) ;
if ( ! V_21 ) {
F_12 ( & V_4 -> V_5 , L_8 ) ;
V_24 = - V_38 ;
goto V_39;
}
V_12 -> V_40 = V_21 -> V_41 ;
V_12 -> V_42 = F_28 ( V_21 ) ;
V_12 -> V_43 = F_29 ( & V_4 -> V_5 , V_21 -> V_41 , V_12 -> V_42 ) ;
if ( ! V_12 -> V_43 ) {
F_12 ( & V_4 -> V_5 , L_9 ) ;
V_24 = - V_28 ;
goto V_39;
}
V_23 = F_30 ( V_4 , 0 ) ;
if ( ! V_23 ) {
F_12 ( & V_4 -> V_5 , L_10 ) ;
V_24 = - V_44 ;
goto V_39;
}
if ( V_2 -> V_33 )
V_2 -> V_33 -> V_45 ( V_2 -> V_33 ,
& V_2 -> V_12 -> V_16 ) ;
F_1 ( V_2 ) ;
V_14 = F_8 ( V_12 ) ;
F_31 ( V_14 ) ;
V_24 = F_32 ( V_12 , V_23 , V_46 ) ;
if ( V_24 ) {
F_12 ( & V_4 -> V_5 , L_11 ) ;
goto V_47;
}
F_33 ( V_4 , V_2 ) ;
return 0 ;
V_47:
F_4 ( V_2 ) ;
V_39:
F_34 ( V_2 -> V_35 ) ;
V_36:
F_35 ( V_12 ) ;
return V_24 ;
}
static int F_36 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_37 ( V_4 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_38 ( V_12 ) ;
if ( V_2 -> V_33 )
V_2 -> V_33 -> V_45 ( V_2 -> V_33 ,
& V_2 -> V_12 -> V_16 ) ;
F_4 ( V_2 ) ;
F_34 ( V_2 -> V_35 ) ;
F_35 ( V_12 ) ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_37 ( V_4 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
if ( V_12 -> V_48 -> V_49 )
V_12 -> V_48 -> V_49 ( V_12 ) ;
}
static int F_40 ( struct V_50 * V_5 )
{
struct V_1 * V_2 = F_41 ( V_5 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
unsigned long V_51 ;
int V_52 = 0 ;
F_42 ( & V_14 -> V_53 , V_51 ) ;
if ( V_14 -> V_54 != V_55 &&
V_14 -> V_54 != V_56 ) {
V_52 = - V_57 ;
goto V_58;
}
F_43 ( V_59 , & V_12 -> V_51 ) ;
if ( V_2 -> V_33 )
V_2 -> V_33 -> V_45 ( V_2 -> V_33 ,
& V_2 -> V_12 -> V_16 ) ;
F_4 ( V_2 ) ;
F_34 ( V_2 -> V_35 ) ;
V_58:
F_44 ( & V_14 -> V_53 , V_51 ) ;
return V_52 ;
}
static int F_45 ( struct V_50 * V_5 )
{
struct V_1 * V_2 = F_41 ( V_5 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
F_26 ( V_2 -> V_35 ) ;
if ( V_2 -> V_33 )
V_2 -> V_33 -> V_45 ( V_2 -> V_33 ,
& V_2 -> V_12 -> V_16 ) ;
F_1 ( V_2 ) ;
F_46 ( V_12 , false ) ;
return 0 ;
}
