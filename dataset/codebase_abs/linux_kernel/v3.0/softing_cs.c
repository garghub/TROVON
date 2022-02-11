int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
F_3 ( & V_2 -> V_6 , L_1 , V_3 ? 0 : 0x20 ) ;
return F_4 ( V_5 , 2 , V_3 ? 0 : 0x20 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
F_3 ( & V_2 -> V_6 , L_2 , V_3 ? 0x60 : 0 ) ;
return F_4 ( V_5 , 0 , V_3 ? 0x60 : 0 ) ;
}
static T_1 int F_6 ( struct V_4 * V_5 ,
void * V_8 )
{
struct V_9 * V_10 = V_8 ;
struct V_11 * V_12 ;
int V_13 = 0 ;
F_7 ( ! V_10 ) ;
V_12 = V_5 -> V_11 [ V_14 ] ;
if ( F_8 ( V_12 ) < 0x1000 )
return - V_15 ;
V_12 -> V_16 |= V_17 | V_18 ;
if ( V_10 -> V_19 < 2 ) {
V_12 -> V_16 |= V_20 | V_21 ;
V_13 = 3 ;
} else {
V_12 -> V_16 |= V_22 ;
}
return F_9 ( V_5 , V_12 , V_13 ) ;
}
static T_2 void F_10 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_23 ;
F_11 ( V_2 ) ;
F_12 ( V_5 ) ;
}
static void F_13 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
F_15 ( V_2 ) ;
}
static T_1 int F_16 ( struct V_4 * V_5 )
{
int V_25 ;
struct V_1 * V_2 ;
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_6 {
struct V_1 V_2 ;
struct V_11 V_26 [ 2 ] ;
} * V_6 ;
V_10 = F_17 ( V_5 -> V_27 , V_5 -> V_28 ) ;
if ( ! V_10 )
return - V_29 ;
V_5 -> V_30 |= V_31 | V_32 |
V_33 | V_34 ;
V_25 = F_18 ( V_5 , F_6 , ( void * ) V_10 ) ;
if ( V_25 )
goto V_35;
V_25 = F_19 ( V_5 ) ;
if ( V_25 < 0 )
goto V_35;
V_12 = V_5 -> V_11 [ V_14 ] ;
if ( ! V_12 ) {
V_25 = - V_36 ;
goto V_37;
}
V_6 = F_20 ( sizeof( * V_6 ) , V_38 ) ;
if ( ! V_6 ) {
V_25 = - V_39 ;
goto V_40;
}
V_6 -> V_2 . V_11 = V_6 -> V_26 ;
V_6 -> V_2 . V_41 = F_21 ( V_6 -> V_26 ) ;
V_6 -> V_2 . V_6 . V_42 = F_13 ;
V_2 = & V_6 -> V_2 ;
V_2 -> V_6 . V_43 = ( void * ) V_10 ;
V_2 -> V_6 . V_7 = & V_5 -> V_6 ;
V_5 -> V_23 = V_2 ;
V_2 -> V_11 [ 0 ] . V_16 = V_44 ;
V_2 -> V_11 [ 0 ] . V_45 = V_12 -> V_45 ;
V_2 -> V_11 [ 0 ] . V_46 = V_12 -> V_46 ;
V_2 -> V_11 [ 1 ] . V_16 = V_47 ;
V_2 -> V_11 [ 1 ] . V_45 = V_5 -> V_48 ;
V_2 -> V_11 [ 1 ] . V_46 = V_2 -> V_11 [ 1 ] . V_45 ;
F_22 ( & V_49 ) ;
V_2 -> V_50 = V_51 ++ ;
F_23 ( & V_49 ) ;
V_2 -> V_52 = L_3 ;
F_24 ( & V_2 -> V_6 , L_4 , V_2 -> V_50 ) ;
V_25 = F_25 ( V_2 ) ;
if ( V_25 < 0 )
goto V_53;
F_26 ( & V_5 -> V_6 , L_5 , F_27 ( & V_2 -> V_6 ) ) ;
return 0 ;
V_53:
F_15 ( V_6 ) ;
V_40:
V_37:
V_35:
F_12 ( V_5 ) ;
V_5 -> V_23 = NULL ;
return V_25 ? : - V_54 ;
}
static int T_3 F_28 ( void )
{
F_29 ( & V_49 ) ;
return F_30 ( & V_55 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_55 ) ;
}
