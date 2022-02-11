static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
V_4 -> V_5 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_6 )
return 0 ;
return V_4 -> V_6 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_7 )
return 0 ;
return V_4 -> V_7 ( V_2 ) ;
}
static void F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
V_11 -> V_12 |= V_13 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_3 ( V_2 ) ;
if ( V_14 )
return V_14 ;
return F_7 ( V_2 , F_5 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
const struct V_19 * V_20 ;
struct V_8 * V_21 ;
struct V_10 * V_11 ;
struct V_22 * V_23 ;
struct V_1 * V_2 ;
struct V_24 * V_24 ;
int V_14 ;
int V_25 ;
if ( F_11 () )
return - V_26 ;
V_20 = & V_27 ;
V_25 = F_12 ( V_16 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_21 = & V_16 -> V_9 ;
if ( V_21 -> V_28 && ! V_21 -> V_29 && V_21 -> V_28 -> V_29 )
V_21 = V_21 -> V_28 ;
#ifdef F_13
else if ( V_21 -> V_28 && V_21 -> V_28 -> V_28 &&
V_21 -> V_28 -> V_28 -> V_30 == & V_31 )
V_21 = V_21 -> V_28 -> V_28 ;
#endif
if ( F_14 ( ! V_21 -> V_32 ) )
V_14 = F_15 ( V_21 ,
F_16 ( 64 ) ) ;
else
V_14 = F_17 ( V_21 , F_16 ( 64 ) ) ;
if ( V_14 ) {
V_14 = F_17 ( V_21 , F_16 ( 32 ) ) ;
if ( V_14 )
return V_14 ;
}
F_18 ( & V_16 -> V_9 ) ;
F_19 ( & V_16 -> V_9 ) ;
F_20 ( & V_16 -> V_9 ) ;
V_2 = F_21 ( V_20 , V_21 , & V_16 -> V_9 ,
F_22 ( & V_16 -> V_9 ) , NULL ) ;
if ( ! V_2 ) {
V_14 = - V_33 ;
goto V_34;
}
V_23 = F_23 ( V_16 , V_35 , 0 ) ;
V_2 -> V_36 = F_24 ( & V_16 -> V_9 , V_23 ) ;
if ( F_25 ( V_2 -> V_36 ) ) {
V_14 = F_26 ( V_2 -> V_36 ) ;
goto V_37;
}
V_2 -> V_38 = V_23 -> V_39 ;
V_2 -> V_40 = F_27 ( V_23 ) ;
V_24 = F_28 ( & V_16 -> V_9 , NULL ) ;
if ( ! F_25 ( V_24 ) ) {
V_14 = F_29 ( V_24 ) ;
if ( V_14 )
goto V_37;
} else if ( F_26 ( V_24 ) == - V_41 ) {
V_14 = - V_41 ;
goto V_37;
}
V_11 = F_30 ( V_2 ) ;
V_18 = F_31 ( V_42 , V_16 -> V_9 . V_29 ) ;
if ( V_18 ) {
const struct V_3 * V_43 = V_18 -> V_44 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_43 )
* V_4 = * V_43 ;
}
F_32 ( V_2 -> V_45 . V_46 ) ;
V_11 -> V_24 = V_24 ;
V_11 -> V_47 = V_2 ;
V_11 -> V_48 = F_21 ( V_20 , V_21 , & V_16 -> V_9 ,
F_22 ( & V_16 -> V_9 ) , V_2 ) ;
if ( ! V_11 -> V_48 ) {
V_14 = - V_33 ;
goto V_49;
}
if ( F_33 ( V_21 , L_1 ) )
V_11 -> V_12 |= V_50 ;
if ( F_33 ( & V_16 -> V_9 , L_2 ) )
V_11 -> V_12 |= V_51 ;
V_2 -> V_52 = F_34 ( V_21 , L_3 , 0 ) ;
if ( F_25 ( V_2 -> V_52 ) ) {
V_14 = F_26 ( V_2 -> V_52 ) ;
if ( V_14 == - V_41 )
goto V_53;
V_2 -> V_52 = NULL ;
} else {
V_14 = F_35 ( V_2 -> V_52 ) ;
if ( V_14 )
goto V_53;
}
V_14 = F_36 ( V_2 , V_25 , V_54 ) ;
if ( V_14 )
goto V_55;
if ( F_37 ( V_11 -> V_56 ) >= 4 )
V_11 -> V_48 -> V_57 = 1 ;
V_14 = F_36 ( V_11 -> V_48 , V_25 , V_54 ) ;
if ( V_14 )
goto V_58;
F_38 ( & V_16 -> V_9 ) ;
F_39 ( & V_16 -> V_9 ) ;
F_40 ( & V_16 -> V_9 ) ;
return 0 ;
V_58:
F_41 ( V_2 ) ;
V_55:
F_42 ( V_2 -> V_52 ) ;
V_53:
F_43 ( V_11 -> V_48 ) ;
V_49:
if ( ! F_25 ( V_24 ) )
F_44 ( V_24 ) ;
V_37:
F_43 ( V_2 ) ;
V_34:
F_39 ( & V_16 -> V_9 ) ;
F_45 ( & V_16 -> V_9 ) ;
return V_14 ;
}
static int F_46 ( struct V_15 * V_9 )
{
struct V_1 * V_2 = F_47 ( V_9 ) ;
struct V_10 * V_11 = F_30 ( V_2 ) ;
struct V_24 * V_24 = V_11 -> V_24 ;
V_11 -> V_59 |= V_60 ;
F_41 ( V_11 -> V_48 ) ;
F_42 ( V_2 -> V_52 ) ;
F_41 ( V_2 ) ;
F_43 ( V_11 -> V_48 ) ;
if ( ! F_25 ( V_24 ) )
F_44 ( V_24 ) ;
F_43 ( V_2 ) ;
F_48 ( & V_9 -> V_9 ) ;
F_45 ( & V_9 -> V_9 ) ;
return 0 ;
}
static int T_1 F_49 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_50 ( V_9 ) ;
struct V_10 * V_11 = F_30 ( V_2 ) ;
int V_14 ;
V_14 = F_51 ( V_11 , F_52 ( V_9 ) ) ;
if ( ! F_52 ( V_9 ) && ! F_25 ( V_11 -> V_24 ) )
F_44 ( V_11 -> V_24 ) ;
return V_14 ;
}
static int T_1 F_53 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_50 ( V_9 ) ;
struct V_10 * V_11 = F_30 ( V_2 ) ;
int V_14 ;
if ( ! F_52 ( V_9 ) && ! F_25 ( V_11 -> V_24 ) )
F_29 ( V_11 -> V_24 ) ;
V_14 = F_4 ( V_2 ) ;
if ( V_14 )
return V_14 ;
return F_54 ( V_11 , 0 ) ;
}
static int T_1 F_55 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_50 ( V_9 ) ;
struct V_10 * V_11 = F_30 ( V_2 ) ;
return F_51 ( V_11 , true ) ;
}
static int T_1 F_56 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_50 ( V_9 ) ;
struct V_10 * V_11 = F_30 ( V_2 ) ;
return F_54 ( V_11 , 0 ) ;
}
static int T_2 F_57 ( void )
{
F_58 ( & V_27 , & V_61 ) ;
return F_59 ( & V_62 ) ;
}
static void T_3 F_60 ( void )
{
F_61 ( & V_62 ) ;
}
