static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , L_1 , NULL ) ||
F_2 ( V_2 , L_2 , NULL ) )
return true ;
#ifdef F_3
return F_4 ( V_3 ) || F_4 ( V_4 ) ;
#else
return false ;
#endif
}
void F_5 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_7 . V_8 ;
struct V_9 * V_10 = F_6 ( V_6 ) ;
struct V_11 * V_12 = F_7 ( V_10 ) ;
const T_1 * V_13 ;
T_2 V_14 ;
int V_15 ;
if ( F_8 ( V_2 ) ) {
if ( F_2 ( V_2 , L_3 , NULL ) )
V_10 -> V_16 |= V_17 ;
if ( F_2 ( V_2 , L_4 , NULL ) ||
( F_9 ( V_2 , L_5 , & V_14 ) == 0 &&
V_14 == 1 ) )
V_10 -> V_16 |= V_18 ;
if ( F_1 ( V_2 ) )
V_10 -> V_16 |= V_19 ;
if ( F_2 ( V_2 , L_6 , NULL ) )
V_10 -> V_16 |= V_20 ;
if ( F_2 ( V_2 , L_7 , NULL ) )
V_10 -> V_21 |= V_22 ;
if ( F_10 ( V_2 , L_8 ) )
V_10 -> V_16 |= V_23 ;
if ( F_10 ( V_2 , L_9 ) ||
F_10 ( V_2 , L_10 ) ||
F_10 ( V_2 , L_11 ) )
V_10 -> V_16 |= V_24 ;
V_13 = F_2 ( V_2 , L_12 , & V_15 ) ;
if ( V_13 && V_15 == sizeof( * V_13 ) && * V_13 )
V_12 -> clock = F_11 ( V_13 ) ;
if ( F_12 ( V_2 , L_13 , NULL ) )
V_10 -> V_25 -> V_26 |= V_27 ;
if ( F_12 ( V_2 , L_14 , NULL ) )
V_10 -> V_25 -> V_26 |= V_28 ;
}
}
void F_5 ( struct V_5 * V_6 ) {}
struct V_9 * F_13 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_6 -> V_7 . V_8 ;
struct V_31 * V_32 ;
int V_33 ;
V_32 = F_14 ( V_6 , V_34 , 0 ) ;
if ( ! V_32 ) {
V_33 = - V_35 ;
goto V_36;
}
if ( F_15 ( V_32 ) < 0x100 )
F_16 ( & V_6 -> V_7 , L_15 ) ;
if ( V_6 -> V_7 . V_37 != & V_38 && ! V_2 )
V_10 = F_17 ( V_6 -> V_7 . V_37 , sizeof( * V_12 ) ) ;
else
V_10 = F_17 ( & V_6 -> V_7 , sizeof( * V_12 ) ) ;
if ( F_18 ( V_10 ) ) {
V_33 = F_19 ( V_10 ) ;
goto V_36;
}
V_12 = F_7 ( V_10 ) ;
V_10 -> V_39 = F_20 ( & V_6 -> V_7 ) ;
if ( V_30 && V_30 -> V_40 )
V_10 -> V_40 = V_30 -> V_40 ;
else
V_10 -> V_40 = & V_41 ;
if ( V_30 )
V_10 -> V_16 = V_30 -> V_16 ;
V_10 -> V_42 = F_21 ( V_6 , 0 ) ;
if ( ! F_22 ( V_32 -> V_43 , F_15 ( V_32 ) ,
F_23 ( V_10 -> V_25 ) ) ) {
F_16 ( & V_6 -> V_7 , L_16 ) ;
V_33 = - V_44 ;
goto V_45;
}
V_10 -> V_46 = F_24 ( V_32 -> V_43 , F_15 ( V_32 ) ) ;
if ( ! V_10 -> V_46 ) {
F_16 ( & V_6 -> V_7 , L_17 ) ;
V_33 = - V_35 ;
goto V_47;
}
if ( V_10 -> V_40 && V_10 -> V_40 -> V_48 )
V_10 -> V_40 -> V_48 ( V_10 ) ;
F_25 ( V_6 , V_10 ) ;
return V_10 ;
V_47:
F_26 ( V_32 -> V_43 , F_15 ( V_32 ) ) ;
V_45:
F_27 ( V_10 ) ;
V_36:
F_16 ( & V_6 -> V_7 , L_18 , V_49 , V_33 ) ;
return F_28 ( V_33 ) ;
}
void F_29 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
struct V_31 * V_32 = F_14 ( V_6 , V_34 , 0 ) ;
F_30 ( V_10 -> V_46 ) ;
F_26 ( V_32 -> V_43 , F_15 ( V_32 ) ) ;
F_27 ( V_10 ) ;
F_25 ( V_6 , NULL ) ;
}
int F_31 ( struct V_5 * V_6 ,
struct V_29 * V_30 )
{
struct V_9 * V_10 ;
int V_33 = 0 ;
V_10 = F_13 ( V_6 , V_30 ) ;
if ( F_18 ( V_10 ) )
return F_19 ( V_10 ) ;
F_5 ( V_6 ) ;
V_33 = F_32 ( V_10 ) ;
if ( V_33 )
F_29 ( V_6 ) ;
return V_33 ;
}
int F_33 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
int V_50 = ( F_34 ( V_10 -> V_46 + V_51 ) == 0xffffffff ) ;
F_35 ( V_10 , V_50 ) ;
F_29 ( V_6 ) ;
return 0 ;
}
static int F_36 ( struct V_52 * V_7 )
{
struct V_9 * V_10 = F_37 ( V_7 ) ;
return F_38 ( V_10 ) ;
}
static int F_39 ( struct V_52 * V_7 )
{
struct V_9 * V_10 = F_37 ( V_7 ) ;
return F_40 ( V_10 ) ;
}
static int T_3 F_41 ( void )
{
F_42 ( L_19 ) ;
return 0 ;
}
static void T_4 F_43 ( void )
{
}
