unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) ;
}
static bool F_4 ( struct V_6 * V_7 )
{
if ( F_5 ( V_7 , L_1 , NULL ) ||
F_5 ( V_7 , L_2 , NULL ) )
return true ;
#ifdef F_6
return F_7 ( V_8 ) || F_7 ( V_9 ) ;
#else
return false ;
#endif
}
void F_8 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_12 . V_13 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const T_1 * V_5 ;
T_2 V_14 ;
int V_15 ;
if ( F_10 ( V_7 ) ) {
if ( F_5 ( V_7 , L_3 , NULL ) )
V_2 -> V_16 |= V_17 ;
if ( F_5 ( V_7 , L_4 , NULL ) ||
( F_11 ( V_7 , L_5 , & V_14 ) == 0 &&
V_14 == 1 ) )
V_2 -> V_16 |= V_18 ;
if ( F_4 ( V_7 ) )
V_2 -> V_16 |= V_19 ;
if ( F_5 ( V_7 , L_6 , NULL ) )
V_2 -> V_16 |= V_20 ;
if ( F_5 ( V_7 , L_7 , NULL ) )
V_2 -> V_21 |= V_22 ;
if ( F_12 ( V_7 , L_8 ) )
V_2 -> V_16 |= V_23 ;
if ( F_12 ( V_7 , L_9 ) ||
F_12 ( V_7 , L_10 ) ||
F_12 ( V_7 , L_11 ) )
V_2 -> V_16 |= V_24 ;
V_5 = F_5 ( V_7 , L_12 , & V_15 ) ;
if ( V_5 && V_15 == sizeof( * V_5 ) && * V_5 )
V_4 -> clock = F_13 ( V_5 ) ;
if ( F_14 ( V_7 , L_13 , NULL ) )
V_2 -> V_25 -> V_26 |= V_27 ;
if ( F_14 ( V_7 , L_14 , NULL ) )
V_2 -> V_25 -> V_26 |= V_28 ;
}
}
void F_8 ( struct V_10 * V_11 ) {}
struct V_1 * F_15 ( struct V_10 * V_11 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_6 * V_7 = V_11 -> V_12 . V_13 ;
struct V_31 * V_32 ;
int V_33 ;
V_32 = F_16 ( V_11 , V_34 , 0 ) ;
if ( ! V_32 ) {
V_33 = - V_35 ;
goto V_36;
}
if ( F_17 ( V_32 ) < 0x100 )
F_18 ( & V_11 -> V_12 , L_15 ) ;
if ( V_11 -> V_12 . V_37 != & V_38 && ! V_7 )
V_2 = F_19 ( V_11 -> V_12 . V_37 , sizeof( * V_4 ) ) ;
else
V_2 = F_19 ( & V_11 -> V_12 , sizeof( * V_4 ) ) ;
if ( F_20 ( V_2 ) ) {
V_33 = F_21 ( V_2 ) ;
goto V_36;
}
V_4 = F_2 ( V_2 ) ;
V_2 -> V_39 = F_22 ( & V_11 -> V_12 ) ;
if ( V_30 && V_30 -> V_40 )
V_2 -> V_40 = V_30 -> V_40 ;
else
V_2 -> V_40 = & V_41 ;
if ( V_30 )
V_2 -> V_16 = V_30 -> V_16 ;
V_2 -> V_42 = F_23 ( V_11 , 0 ) ;
if ( ! F_24 ( V_32 -> V_43 , F_17 ( V_32 ) ,
F_25 ( V_2 -> V_25 ) ) ) {
F_18 ( & V_11 -> V_12 , L_16 ) ;
V_33 = - V_44 ;
goto V_45;
}
V_2 -> V_46 = F_26 ( V_32 -> V_43 , F_17 ( V_32 ) ) ;
if ( ! V_2 -> V_46 ) {
F_18 ( & V_11 -> V_12 , L_17 ) ;
V_33 = - V_35 ;
goto V_47;
}
if ( V_2 -> V_40 && V_2 -> V_40 -> V_48 )
V_2 -> V_40 -> V_48 ( V_2 ) ;
F_27 ( V_11 , V_2 ) ;
return V_2 ;
V_47:
F_28 ( V_32 -> V_43 , F_17 ( V_32 ) ) ;
V_45:
F_29 ( V_2 ) ;
V_36:
F_18 ( & V_11 -> V_12 , L_18 , V_49 , V_33 ) ;
return F_30 ( V_33 ) ;
}
void F_31 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_31 * V_32 = F_16 ( V_11 , V_34 , 0 ) ;
F_32 ( V_2 -> V_46 ) ;
F_28 ( V_32 -> V_43 , F_17 ( V_32 ) ) ;
F_29 ( V_2 ) ;
F_27 ( V_11 , NULL ) ;
}
int F_33 ( struct V_10 * V_11 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 ;
int V_33 = 0 ;
V_2 = F_15 ( V_11 , V_30 ) ;
if ( F_20 ( V_2 ) )
return F_21 ( V_2 ) ;
F_8 ( V_11 ) ;
V_33 = F_34 ( V_2 ) ;
if ( V_33 )
F_31 ( V_11 ) ;
return V_33 ;
}
int F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_50 = ( F_36 ( V_2 -> V_46 + V_51 ) == 0xffffffff ) ;
F_37 ( V_2 , V_50 ) ;
F_31 ( V_11 ) ;
return 0 ;
}
static int F_38 ( struct V_52 * V_12 )
{
struct V_1 * V_2 = F_39 ( V_12 ) ;
return F_40 ( V_2 ) ;
}
static int F_41 ( struct V_52 * V_12 )
{
struct V_1 * V_2 = F_39 ( V_12 ) ;
return F_42 ( V_2 ) ;
}
static int T_3 F_43 ( void )
{
F_44 ( L_19 ) ;
return 0 ;
}
static void T_4 F_45 ( void )
{
}
