static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_4 ) ;
F_6 ( V_2 -> V_5 ) ;
}
static void F_7 ( T_1 * V_6 , int V_5 )
{
int V_7 ;
V_7 = F_8 ( V_6 ) ;
if ( V_7 >= 0 )
F_9 ( V_5 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_4 , V_2 -> V_5 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_8 ) ;
F_6 ( V_2 -> V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_8 , V_2 -> V_9 ) ;
}
static T_2 F_13 ( int V_5 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
V_2 -> V_11 ( V_2 ) ;
F_14 ( & V_2 -> V_12 ) ;
return V_13 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_14 ) ;
}
static T_3 F_16 ( struct V_15 * V_16 )
{
return V_17 | ( V_18 & ~ V_19 ) |
V_20 | V_21 ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 . V_27 ;
int V_5 , V_28 = 0 , V_9 = 0 ;
struct V_29 * V_30 ;
struct V_1 * V_2 ;
bool V_31 ;
V_31 = F_18 ( V_25 , L_1 ) ;
if ( V_31 ) {
V_9 = F_19 ( V_23 , 0 ) ;
if ( V_9 < 0 )
return V_9 ;
V_5 = F_19 ( V_23 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
} else {
V_5 = F_19 ( V_23 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
}
V_2 = F_20 ( & V_23 -> V_26 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
V_28 = - V_33 ;
goto V_34;
}
V_2 -> V_26 = & V_23 -> V_26 ;
V_2 -> V_35 . V_36 = 0x00 ;
V_2 -> V_35 . V_37 = 0x10 ;
V_2 -> V_35 . V_38 = 0x18 ;
V_30 = F_21 ( V_23 , V_39 , 0 ) ;
V_2 -> V_40 = F_22 ( & V_23 -> V_26 , V_30 ) ;
if ( F_23 ( V_2 -> V_40 ) ) {
V_28 = F_24 ( V_2 -> V_40 ) ;
goto V_34;
}
if ( F_25 ( V_25 , L_2 , & V_2 -> V_41 ) &&
F_25 ( V_25 , L_3 , & V_2 -> V_41 ) ) {
F_26 ( V_2 -> V_26 ,
L_4 ) ;
V_28 = - V_42 ;
goto V_34;
}
V_2 -> V_43 = F_27 () ;
F_28 ( & V_2 -> V_12 ) ;
V_2 -> V_5 = V_5 ;
if ( V_31 ) {
V_2 -> V_9 = V_9 ;
V_2 -> V_44 = F_4 ;
V_2 -> V_45 = F_10 ;
V_2 -> V_46 = F_11 ;
V_2 -> V_11 = F_12 ;
F_29 ( V_2 -> V_5 , V_47 ) ;
F_29 ( V_2 -> V_9 , V_47 ) ;
V_28 = F_30 ( & V_23 -> V_26 , V_2 -> V_9 ,
F_13 , 0 ,
V_48 , V_2 ) ;
if ( V_28 < 0 ) {
F_26 ( V_2 -> V_26 , L_5 ) ;
goto V_34;
}
} else {
V_2 -> V_44 = F_1 ;
V_2 -> V_45 = F_3 ;
V_2 -> V_46 = F_15 ;
V_2 -> V_11 = F_3 ;
}
V_28 = F_30 ( & V_23 -> V_26 , V_2 -> V_5 ,
V_49 , 0 , V_48 , V_2 ) ;
if ( V_28 < 0 ) {
F_26 ( V_2 -> V_26 , L_5 ) ;
goto V_34;
}
if ( F_31 ( V_50 ) )
V_2 -> V_51 = true ;
V_28 = F_32 ( V_2 ) ;
if ( V_28 ) {
F_26 ( V_2 -> V_26 , L_6 ) ;
goto V_34;
}
F_33 ( V_2 ) ;
V_2 -> V_16 = V_52 ;
V_2 -> V_16 . V_53 = F_34 ( 2 ) ;
V_2 -> V_16 . V_54 = 5 ;
V_2 -> V_16 . V_55 = & V_56 ;
V_2 -> V_16 . V_26 . V_57 = & V_23 -> V_26 ;
V_2 -> V_16 . V_26 . V_27 = V_25 ;
F_35 ( & V_2 -> V_16 , V_2 ) ;
F_36 ( V_23 , V_2 ) ;
V_28 = F_37 ( & V_2 -> V_16 ) ;
if ( V_28 < 0 )
goto V_34;
F_38 ( V_2 -> V_26 , L_7 ) ;
return 0 ;
V_34:
return V_28 ;
}
static int F_39 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_40 ( V_23 ) ;
F_41 ( & V_2 -> V_16 ) ;
return 0 ;
}
