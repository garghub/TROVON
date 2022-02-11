static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 |= V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
int V_9 ;
if ( F_3 ( V_8 , V_10 ) ||
F_3 ( V_8 , V_11 ) ) {
V_9 = F_4 ( V_8 ) ;
if ( V_9 )
return V_9 ;
}
return F_5 ( V_8 , F_1 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
if ( F_3 ( V_8 , V_10 ) ||
F_3 ( V_8 , V_11 ) )
F_7 ( V_8 ) ;
return F_8 ( V_8 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_2 . V_16 ;
struct V_17 * V_18 = F_10 ( & V_13 -> V_2 ) ;
const struct V_19 * V_20 ;
const struct V_21 * V_22 ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
struct V_7 * V_8 ;
struct V_25 * V_25 ;
int V_9 ;
int V_26 ;
if ( F_11 () )
return - V_27 ;
V_22 = & V_28 ;
V_26 = F_12 ( V_13 , 0 ) ;
if ( V_26 < 0 )
return - V_27 ;
if ( F_13 ( ! V_13 -> V_2 . V_29 ) )
V_9 = F_14 ( & V_13 -> V_2 ,
F_15 ( 64 ) ) ;
else
V_9 = F_16 ( & V_13 -> V_2 , F_15 ( 64 ) ) ;
if ( V_9 ) {
V_9 = F_16 ( & V_13 -> V_2 , F_15 ( 32 ) ) ;
if ( V_9 )
return V_9 ;
}
V_8 = F_17 ( V_22 , & V_13 -> V_2 , F_18 ( & V_13 -> V_2 ) ) ;
if ( ! V_8 )
return - V_30 ;
V_24 = F_19 ( V_13 , V_31 , 0 ) ;
V_8 -> V_32 = F_20 ( & V_13 -> V_2 , V_24 ) ;
if ( F_21 ( V_8 -> V_32 ) ) {
V_9 = F_22 ( V_8 -> V_32 ) ;
goto V_33;
}
V_8 -> V_34 = V_24 -> V_35 ;
V_8 -> V_36 = F_23 ( V_24 ) ;
V_25 = F_24 ( & V_13 -> V_2 , NULL ) ;
if ( ! F_21 ( V_25 ) ) {
V_9 = F_25 ( V_25 ) ;
if ( V_9 )
goto V_33;
}
V_4 = F_26 ( V_8 ) ;
V_20 = F_27 ( V_37 , V_15 ) ;
if ( V_20 ) {
const struct V_38 * V_39 = V_20 -> V_40 ;
struct V_38 * V_41 = F_28 ( V_8 ) ;
if ( V_39 )
* V_41 = * V_39 ;
}
if ( F_3 ( V_8 , V_42 ) ) {
V_9 = F_29 ( V_13 ) ;
if ( V_9 )
goto V_43;
}
F_30 ( V_8 -> V_44 . V_45 ) ;
V_4 -> V_25 = V_25 ;
V_4 -> V_46 = V_8 ;
V_4 -> V_47 = F_31 ( V_22 , & V_13 -> V_2 ,
F_18 ( & V_13 -> V_2 ) , V_8 ) ;
if ( ! V_4 -> V_47 ) {
V_9 = - V_30 ;
goto V_43;
}
if ( ( V_15 && F_32 ( V_15 , L_1 ) ) ||
( V_18 && V_18 -> V_48 ) )
V_4 -> V_5 |= V_49 ;
if ( F_33 ( V_4 -> V_50 ) >= 4 )
V_4 -> V_47 -> V_51 = 1 ;
V_8 -> V_52 = F_34 ( & V_13 -> V_2 , L_2 , 0 ) ;
if ( F_21 ( V_8 -> V_52 ) ) {
V_9 = F_22 ( V_8 -> V_52 ) ;
if ( V_9 == - V_53 )
goto V_54;
V_8 -> V_52 = NULL ;
} else {
V_9 = F_35 ( V_8 -> V_52 ) ;
if ( V_9 )
goto V_54;
}
V_9 = F_36 ( V_8 , V_26 , V_55 ) ;
if ( V_9 )
goto V_56;
V_9 = F_36 ( V_4 -> V_47 , V_26 , V_55 ) ;
if ( V_9 )
goto V_57;
return 0 ;
V_57:
F_37 ( V_8 ) ;
V_56:
F_38 ( V_8 -> V_52 ) ;
V_54:
F_39 ( V_4 -> V_47 ) ;
V_43:
if ( ! F_21 ( V_25 ) )
F_40 ( V_25 ) ;
V_33:
F_39 ( V_8 ) ;
return V_9 ;
}
static int F_41 ( struct V_12 * V_2 )
{
struct V_7 * V_8 = F_42 ( V_2 ) ;
struct V_3 * V_4 = F_26 ( V_8 ) ;
struct V_25 * V_25 = V_4 -> V_25 ;
F_37 ( V_4 -> V_47 ) ;
F_38 ( V_8 -> V_52 ) ;
F_37 ( V_8 ) ;
F_39 ( V_4 -> V_47 ) ;
if ( ! F_21 ( V_25 ) )
F_40 ( V_25 ) ;
F_39 ( V_8 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_44 ( V_2 ) ;
struct V_3 * V_4 = F_26 ( V_8 ) ;
return F_45 ( V_4 , F_46 ( V_2 ) ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_44 ( V_2 ) ;
struct V_3 * V_4 = F_26 ( V_8 ) ;
return F_48 ( V_4 , 0 ) ;
}
static int T_1 F_49 ( void )
{
F_50 ( & V_28 , & V_58 ) ;
return F_51 ( & V_59 ) ;
}
static void T_2 F_52 ( void )
{
F_53 ( & V_59 ) ;
}
