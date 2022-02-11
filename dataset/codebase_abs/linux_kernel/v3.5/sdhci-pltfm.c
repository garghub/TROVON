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
if ( F_10 ( V_2 , L_6 ) )
V_10 -> V_16 |= V_20 ;
if ( F_10 ( V_2 , L_7 ) ||
F_10 ( V_2 , L_8 ) ||
F_10 ( V_2 , L_9 ) )
V_10 -> V_16 |= V_21 ;
V_13 = F_2 ( V_2 , L_10 , & V_15 ) ;
if ( V_13 && V_15 == sizeof( * V_13 ) && * V_13 )
V_12 -> clock = F_11 ( V_13 ) ;
}
}
void F_5 ( struct V_5 * V_6 ) {}
struct V_9 * F_12 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_6 -> V_7 . V_8 ;
struct V_24 * V_25 ;
int V_26 ;
V_25 = F_13 ( V_6 , V_27 , 0 ) ;
if ( ! V_25 ) {
V_26 = - V_28 ;
goto V_29;
}
if ( F_14 ( V_25 ) < 0x100 )
F_15 ( & V_6 -> V_7 , L_11 ) ;
if ( V_6 -> V_7 . V_30 != & V_31 && ! V_2 )
V_10 = F_16 ( V_6 -> V_7 . V_30 , sizeof( * V_12 ) ) ;
else
V_10 = F_16 ( & V_6 -> V_7 , sizeof( * V_12 ) ) ;
if ( F_17 ( V_10 ) ) {
V_26 = F_18 ( V_10 ) ;
goto V_29;
}
V_12 = F_7 ( V_10 ) ;
V_10 -> V_32 = F_19 ( & V_6 -> V_7 ) ;
if ( V_23 && V_23 -> V_33 )
V_10 -> V_33 = V_23 -> V_33 ;
else
V_10 -> V_33 = & V_34 ;
if ( V_23 )
V_10 -> V_16 = V_23 -> V_16 ;
V_10 -> V_35 = F_20 ( V_6 , 0 ) ;
if ( ! F_21 ( V_25 -> V_36 , F_14 ( V_25 ) ,
F_22 ( V_10 -> V_37 ) ) ) {
F_15 ( & V_6 -> V_7 , L_12 ) ;
V_26 = - V_38 ;
goto V_39;
}
V_10 -> V_40 = F_23 ( V_25 -> V_36 , F_14 ( V_25 ) ) ;
if ( ! V_10 -> V_40 ) {
F_15 ( & V_6 -> V_7 , L_13 ) ;
V_26 = - V_28 ;
goto V_41;
}
F_24 ( V_6 , V_10 ) ;
return V_10 ;
V_41:
F_25 ( V_25 -> V_36 , F_14 ( V_25 ) ) ;
V_39:
F_26 ( V_10 ) ;
V_29:
F_15 ( & V_6 -> V_7 , L_14 , V_42 , V_26 ) ;
return F_27 ( V_26 ) ;
}
void F_28 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
struct V_24 * V_25 = F_13 ( V_6 , V_27 , 0 ) ;
F_29 ( V_10 -> V_40 ) ;
F_25 ( V_25 -> V_36 , F_14 ( V_25 ) ) ;
F_26 ( V_10 ) ;
F_24 ( V_6 , NULL ) ;
}
int F_30 ( struct V_5 * V_6 ,
struct V_22 * V_23 )
{
struct V_9 * V_10 ;
int V_26 = 0 ;
V_10 = F_12 ( V_6 , V_23 ) ;
if ( F_17 ( V_10 ) )
return F_18 ( V_10 ) ;
F_5 ( V_6 ) ;
V_26 = F_31 ( V_10 ) ;
if ( V_26 )
F_28 ( V_6 ) ;
return V_26 ;
}
int F_32 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
int V_43 = ( F_33 ( V_10 -> V_40 + V_44 ) == 0xffffffff ) ;
F_34 ( V_10 , V_43 ) ;
F_28 ( V_6 ) ;
return 0 ;
}
static int F_35 ( struct V_45 * V_7 )
{
struct V_9 * V_10 = F_36 ( V_7 ) ;
return F_37 ( V_10 ) ;
}
static int F_38 ( struct V_45 * V_7 )
{
struct V_9 * V_10 = F_36 ( V_7 ) ;
return F_39 ( V_10 ) ;
}
static int T_3 F_40 ( void )
{
F_41 ( L_15 ) ;
return 0 ;
}
static void T_4 F_42 ( void )
{
}
