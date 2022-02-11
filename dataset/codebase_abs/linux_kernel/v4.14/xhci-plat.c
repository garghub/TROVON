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
for ( V_21 = & V_16 -> V_9 ; V_21 ; V_21 = V_21 -> V_28 ) {
if ( F_13 ( V_21 -> V_29 ) ||
F_14 ( V_21 -> V_29 ) )
break;
#ifdef F_15
else if ( V_21 -> V_30 == & V_31 )
break;
#endif
}
if ( ! V_21 )
V_21 = & V_16 -> V_9 ;
if ( F_16 ( ! V_21 -> V_32 ) )
V_14 = F_17 ( V_21 ,
F_18 ( 64 ) ) ;
else
V_14 = F_19 ( V_21 , F_18 ( 64 ) ) ;
if ( V_14 ) {
V_14 = F_19 ( V_21 , F_18 ( 32 ) ) ;
if ( V_14 )
return V_14 ;
}
F_20 ( & V_16 -> V_9 ) ;
F_21 ( & V_16 -> V_9 ) ;
F_22 ( & V_16 -> V_9 ) ;
V_2 = F_23 ( V_20 , V_21 , & V_16 -> V_9 ,
F_24 ( & V_16 -> V_9 ) , NULL ) ;
if ( ! V_2 ) {
V_14 = - V_33 ;
goto V_34;
}
V_23 = F_25 ( V_16 , V_35 , 0 ) ;
V_2 -> V_36 = F_26 ( & V_16 -> V_9 , V_23 ) ;
if ( F_27 ( V_2 -> V_36 ) ) {
V_14 = F_28 ( V_2 -> V_36 ) ;
goto V_37;
}
V_2 -> V_38 = V_23 -> V_39 ;
V_2 -> V_40 = F_29 ( V_23 ) ;
V_24 = F_30 ( & V_16 -> V_9 , NULL ) ;
if ( ! F_27 ( V_24 ) ) {
V_14 = F_31 ( V_24 ) ;
if ( V_14 )
goto V_37;
} else if ( F_28 ( V_24 ) == - V_41 ) {
V_14 = - V_41 ;
goto V_37;
}
V_11 = F_32 ( V_2 ) ;
V_18 = F_33 ( V_42 , V_16 -> V_9 . V_43 ) ;
if ( V_18 ) {
const struct V_3 * V_44 = V_18 -> V_45 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_44 )
* V_4 = * V_44 ;
}
F_34 ( V_2 -> V_46 . V_47 ) ;
V_11 -> V_24 = V_24 ;
V_11 -> V_48 = V_2 ;
V_11 -> V_49 = F_23 ( V_20 , V_21 , & V_16 -> V_9 ,
F_24 ( & V_16 -> V_9 ) , V_2 ) ;
if ( ! V_11 -> V_49 ) {
V_14 = - V_33 ;
goto V_50;
}
if ( F_35 ( V_21 , L_1 ) )
V_11 -> V_12 |= V_51 ;
if ( F_35 ( & V_16 -> V_9 , L_2 ) )
V_11 -> V_12 |= V_52 ;
V_2 -> V_53 = F_36 ( V_21 , L_3 , 0 ) ;
if ( F_27 ( V_2 -> V_53 ) ) {
V_14 = F_28 ( V_2 -> V_53 ) ;
if ( V_14 == - V_41 )
goto V_54;
V_2 -> V_53 = NULL ;
} else {
V_14 = F_37 ( V_2 -> V_53 ) ;
if ( V_14 )
goto V_54;
}
V_14 = F_38 ( V_2 , V_25 , V_55 ) ;
if ( V_14 )
goto V_56;
if ( F_39 ( V_11 -> V_57 ) >= 4 )
V_11 -> V_49 -> V_58 = 1 ;
V_14 = F_38 ( V_11 -> V_49 , V_25 , V_55 ) ;
if ( V_14 )
goto V_59;
F_40 ( & V_16 -> V_9 ) ;
F_41 ( & V_16 -> V_9 ) ;
F_42 ( & V_16 -> V_9 ) ;
return 0 ;
V_59:
F_43 ( V_2 ) ;
V_56:
F_44 ( V_2 -> V_53 ) ;
V_54:
F_45 ( V_11 -> V_49 ) ;
V_50:
if ( ! F_27 ( V_24 ) )
F_46 ( V_24 ) ;
V_37:
F_45 ( V_2 ) ;
V_34:
F_41 ( & V_16 -> V_9 ) ;
F_47 ( & V_16 -> V_9 ) ;
return V_14 ;
}
static int F_48 ( struct V_15 * V_9 )
{
struct V_1 * V_2 = F_49 ( V_9 ) ;
struct V_10 * V_11 = F_32 ( V_2 ) ;
struct V_24 * V_24 = V_11 -> V_24 ;
V_11 -> V_60 |= V_61 ;
F_43 ( V_11 -> V_49 ) ;
F_44 ( V_2 -> V_53 ) ;
F_43 ( V_2 ) ;
F_45 ( V_11 -> V_49 ) ;
if ( ! F_27 ( V_24 ) )
F_46 ( V_24 ) ;
F_45 ( V_2 ) ;
F_50 ( & V_9 -> V_9 ) ;
F_47 ( & V_9 -> V_9 ) ;
return 0 ;
}
static int T_1 F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_52 ( V_9 ) ;
struct V_10 * V_11 = F_32 ( V_2 ) ;
int V_14 ;
V_14 = F_53 ( V_11 , F_54 ( V_9 ) ) ;
if ( ! F_54 ( V_9 ) && ! F_27 ( V_11 -> V_24 ) )
F_46 ( V_11 -> V_24 ) ;
return V_14 ;
}
static int T_1 F_55 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_52 ( V_9 ) ;
struct V_10 * V_11 = F_32 ( V_2 ) ;
int V_14 ;
if ( ! F_54 ( V_9 ) && ! F_27 ( V_11 -> V_24 ) )
F_31 ( V_11 -> V_24 ) ;
V_14 = F_4 ( V_2 ) ;
if ( V_14 )
return V_14 ;
return F_56 ( V_11 , 0 ) ;
}
static int T_1 F_57 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_52 ( V_9 ) ;
struct V_10 * V_11 = F_32 ( V_2 ) ;
return F_53 ( V_11 , true ) ;
}
static int T_1 F_58 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_52 ( V_9 ) ;
struct V_10 * V_11 = F_32 ( V_2 ) ;
return F_56 ( V_11 , 0 ) ;
}
static int T_2 F_59 ( void )
{
F_60 ( & V_27 , & V_62 ) ;
return F_61 ( & V_63 ) ;
}
static void T_3 F_62 ( void )
{
F_63 ( & V_63 ) ;
}
