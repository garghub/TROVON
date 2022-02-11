static bool F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , L_1 , NULL ) )
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
int V_14 ;
if ( F_8 ( V_2 ) ) {
if ( F_2 ( V_2 , L_2 , NULL ) )
V_10 -> V_15 |= V_16 ;
if ( F_2 ( V_2 , L_3 , NULL ) )
V_10 -> V_15 |= V_17 ;
if ( F_1 ( V_2 ) )
V_10 -> V_15 |= V_18 ;
if ( F_9 ( V_2 , L_4 ) )
V_10 -> V_15 |= V_19 ;
if ( F_9 ( V_2 , L_5 ) ||
F_9 ( V_2 , L_6 ) ||
F_9 ( V_2 , L_7 ) )
V_10 -> V_15 |= V_20 ;
V_13 = F_2 ( V_2 , L_8 , & V_14 ) ;
if ( V_13 && V_14 == sizeof( * V_13 ) && * V_13 )
V_12 -> clock = F_10 ( V_13 ) ;
}
}
void F_5 ( struct V_5 * V_6 ) {}
struct V_9 * F_11 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_6 -> V_7 . V_8 ;
struct V_23 * V_24 ;
int V_25 ;
V_24 = F_12 ( V_6 , V_26 , 0 ) ;
if ( ! V_24 ) {
V_25 = - V_27 ;
goto V_28;
}
if ( F_13 ( V_24 ) < 0x100 )
F_14 ( & V_6 -> V_7 , L_9 ) ;
if ( V_6 -> V_7 . V_29 != & V_30 && ! V_2 )
V_10 = F_15 ( V_6 -> V_7 . V_29 , sizeof( * V_12 ) ) ;
else
V_10 = F_15 ( & V_6 -> V_7 , sizeof( * V_12 ) ) ;
if ( F_16 ( V_10 ) ) {
V_25 = F_17 ( V_10 ) ;
goto V_28;
}
V_12 = F_7 ( V_10 ) ;
V_10 -> V_31 = F_18 ( & V_6 -> V_7 ) ;
if ( V_22 && V_22 -> V_32 )
V_10 -> V_32 = V_22 -> V_32 ;
else
V_10 -> V_32 = & V_33 ;
if ( V_22 )
V_10 -> V_15 = V_22 -> V_15 ;
V_10 -> V_34 = F_19 ( V_6 , 0 ) ;
if ( ! F_20 ( V_24 -> V_35 , F_13 ( V_24 ) ,
F_21 ( V_10 -> V_36 ) ) ) {
F_14 ( & V_6 -> V_7 , L_10 ) ;
V_25 = - V_37 ;
goto V_38;
}
V_10 -> V_39 = F_22 ( V_24 -> V_35 , F_13 ( V_24 ) ) ;
if ( ! V_10 -> V_39 ) {
F_14 ( & V_6 -> V_7 , L_11 ) ;
V_25 = - V_27 ;
goto V_40;
}
F_23 ( V_6 , V_10 ) ;
return V_10 ;
V_40:
F_24 ( V_24 -> V_35 , F_13 ( V_24 ) ) ;
V_38:
F_25 ( V_10 ) ;
V_28:
F_14 ( & V_6 -> V_7 , L_12 , V_41 , V_25 ) ;
return F_26 ( V_25 ) ;
}
void F_27 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
struct V_23 * V_24 = F_12 ( V_6 , V_26 , 0 ) ;
F_28 ( V_10 -> V_39 ) ;
F_24 ( V_24 -> V_35 , F_13 ( V_24 ) ) ;
F_25 ( V_10 ) ;
F_23 ( V_6 , NULL ) ;
}
int F_29 ( struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_9 * V_10 ;
int V_25 = 0 ;
V_10 = F_11 ( V_6 , V_22 ) ;
if ( F_16 ( V_10 ) )
return F_17 ( V_10 ) ;
F_5 ( V_6 ) ;
V_25 = F_30 ( V_10 ) ;
if ( V_25 )
F_27 ( V_6 ) ;
return V_25 ;
}
int F_31 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
int V_42 = ( F_32 ( V_10 -> V_39 + V_43 ) == 0xffffffff ) ;
F_33 ( V_10 , V_42 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
static int F_34 ( struct V_44 * V_7 )
{
struct V_9 * V_10 = F_35 ( V_7 ) ;
return F_36 ( V_10 ) ;
}
static int F_37 ( struct V_44 * V_7 )
{
struct V_9 * V_10 = F_35 ( V_7 ) ;
return F_38 ( V_10 ) ;
}
static int T_2 F_39 ( void )
{
F_40 ( L_13 ) ;
return 0 ;
}
static void T_3 F_41 ( void )
{
}
