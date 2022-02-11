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
V_13 = F_2 ( V_2 , L_4 , & V_14 ) ;
if ( V_13 && V_14 == sizeof( * V_13 ) && * V_13 )
V_12 -> clock = F_9 ( V_13 ) ;
}
}
void F_5 ( struct V_5 * V_6 ) {}
struct V_9 * F_10 ( struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_2 = V_6 -> V_7 . V_8 ;
struct V_21 * V_22 ;
int V_23 ;
V_22 = F_11 ( V_6 , V_24 , 0 ) ;
if ( ! V_22 ) {
V_23 = - V_25 ;
goto V_26;
}
if ( F_12 ( V_22 ) < 0x100 )
F_13 ( & V_6 -> V_7 , L_5 ) ;
if ( V_6 -> V_7 . V_27 != & V_28 && ! V_2 )
V_10 = F_14 ( V_6 -> V_7 . V_27 , sizeof( * V_12 ) ) ;
else
V_10 = F_14 ( & V_6 -> V_7 , sizeof( * V_12 ) ) ;
if ( F_15 ( V_10 ) ) {
V_23 = F_16 ( V_10 ) ;
goto V_26;
}
V_12 = F_7 ( V_10 ) ;
V_10 -> V_29 = F_17 ( & V_6 -> V_7 ) ;
if ( V_20 && V_20 -> V_30 )
V_10 -> V_30 = V_20 -> V_30 ;
else
V_10 -> V_30 = & V_31 ;
if ( V_20 )
V_10 -> V_15 = V_20 -> V_15 ;
V_10 -> V_32 = F_18 ( V_6 , 0 ) ;
if ( ! F_19 ( V_22 -> V_33 , F_12 ( V_22 ) ,
F_20 ( V_10 -> V_34 ) ) ) {
F_13 ( & V_6 -> V_7 , L_6 ) ;
V_23 = - V_35 ;
goto V_36;
}
V_10 -> V_37 = F_21 ( V_22 -> V_33 , F_12 ( V_22 ) ) ;
if ( ! V_10 -> V_37 ) {
F_13 ( & V_6 -> V_7 , L_7 ) ;
V_23 = - V_25 ;
goto V_38;
}
F_22 ( V_6 , V_10 ) ;
return V_10 ;
V_38:
F_23 ( V_22 -> V_33 , F_12 ( V_22 ) ) ;
V_36:
F_24 ( V_10 ) ;
V_26:
F_13 ( & V_6 -> V_7 , L_8 , V_39 , V_23 ) ;
return F_25 ( V_23 ) ;
}
void F_26 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
struct V_21 * V_22 = F_11 ( V_6 , V_24 , 0 ) ;
F_27 ( V_10 -> V_37 ) ;
F_23 ( V_22 -> V_33 , F_12 ( V_22 ) ) ;
F_24 ( V_10 ) ;
F_22 ( V_6 , NULL ) ;
}
int F_28 ( struct V_5 * V_6 ,
struct V_19 * V_20 )
{
struct V_9 * V_10 ;
int V_23 = 0 ;
V_10 = F_10 ( V_6 , V_20 ) ;
if ( F_15 ( V_10 ) )
return F_16 ( V_10 ) ;
F_5 ( V_6 ) ;
V_23 = F_29 ( V_10 ) ;
if ( V_23 )
F_26 ( V_6 ) ;
return V_23 ;
}
int F_30 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_6 ( V_6 ) ;
int V_40 = ( F_31 ( V_10 -> V_37 + V_41 ) == 0xffffffff ) ;
F_32 ( V_10 , V_40 ) ;
F_26 ( V_6 ) ;
return 0 ;
}
static int F_33 ( struct V_42 * V_7 )
{
struct V_9 * V_10 = F_34 ( V_7 ) ;
return F_35 ( V_10 ) ;
}
static int F_36 ( struct V_42 * V_7 )
{
struct V_9 * V_10 = F_34 ( V_7 ) ;
return F_37 ( V_10 ) ;
}
static int T_2 F_38 ( void )
{
F_39 ( L_9 ) ;
return 0 ;
}
static void T_3 F_40 ( void )
{
}
