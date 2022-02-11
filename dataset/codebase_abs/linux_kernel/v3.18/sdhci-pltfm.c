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
F_12 ( V_7 , L_11 ) ||
F_12 ( V_7 , L_12 ) )
V_2 -> V_16 |= V_24 ;
V_5 = F_5 ( V_7 , L_13 , & V_15 ) ;
if ( V_5 && V_15 == sizeof( * V_5 ) && * V_5 )
V_4 -> clock = F_13 ( V_5 ) ;
if ( F_14 ( V_7 , L_14 , NULL ) )
V_2 -> V_25 -> V_26 |= V_27 ;
if ( F_14 ( V_7 , L_15 , NULL ) )
V_2 -> V_25 -> V_26 |= V_28 ;
}
}
void F_8 ( struct V_10 * V_11 ) {}
struct V_1 * F_15 ( struct V_10 * V_11 ,
const struct V_29 * V_30 ,
T_3 V_31 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_34 ;
V_33 = F_16 ( V_11 , V_35 , 0 ) ;
if ( ! V_33 ) {
V_34 = - V_36 ;
goto V_37;
}
if ( F_17 ( V_33 ) < 0x100 )
F_18 ( & V_11 -> V_12 , L_16 ) ;
V_2 = F_19 ( & V_11 -> V_12 ,
sizeof( struct V_3 ) + V_31 ) ;
if ( F_20 ( V_2 ) ) {
V_34 = F_21 ( V_2 ) ;
goto V_37;
}
V_2 -> V_38 = F_22 ( & V_11 -> V_12 ) ;
if ( V_30 && V_30 -> V_39 )
V_2 -> V_39 = V_30 -> V_39 ;
else
V_2 -> V_39 = & V_40 ;
if ( V_30 ) {
V_2 -> V_16 = V_30 -> V_16 ;
V_2 -> V_21 = V_30 -> V_21 ;
}
V_2 -> V_41 = F_23 ( V_11 , 0 ) ;
if ( ! F_24 ( V_33 -> V_42 , F_17 ( V_33 ) ,
F_25 ( V_2 -> V_25 ) ) ) {
F_18 ( & V_11 -> V_12 , L_17 ) ;
V_34 = - V_43 ;
goto V_44;
}
V_2 -> V_45 = F_26 ( V_33 -> V_42 , F_17 ( V_33 ) ) ;
if ( ! V_2 -> V_45 ) {
F_18 ( & V_11 -> V_12 , L_18 ) ;
V_34 = - V_36 ;
goto V_46;
}
if ( V_2 -> V_39 && V_2 -> V_39 -> V_47 )
V_2 -> V_39 -> V_47 ( V_2 ) ;
F_27 ( V_11 , V_2 ) ;
return V_2 ;
V_46:
F_28 ( V_33 -> V_42 , F_17 ( V_33 ) ) ;
V_44:
F_29 ( V_2 ) ;
V_37:
F_18 ( & V_11 -> V_12 , L_19 , V_48 , V_34 ) ;
return F_30 ( V_34 ) ;
}
void F_31 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_32 * V_33 = F_16 ( V_11 , V_35 , 0 ) ;
F_32 ( V_2 -> V_45 ) ;
F_28 ( V_33 -> V_42 , F_17 ( V_33 ) ) ;
F_29 ( V_2 ) ;
}
int F_33 ( struct V_10 * V_11 ,
const struct V_29 * V_30 ,
T_3 V_31 )
{
struct V_1 * V_2 ;
int V_34 = 0 ;
V_2 = F_15 ( V_11 , V_30 , V_31 ) ;
if ( F_20 ( V_2 ) )
return F_21 ( V_2 ) ;
F_8 ( V_11 ) ;
V_34 = F_34 ( V_2 ) ;
if ( V_34 )
F_31 ( V_11 ) ;
return V_34 ;
}
int F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_49 = ( F_36 ( V_2 -> V_45 + V_50 ) == 0xffffffff ) ;
F_37 ( V_2 , V_49 ) ;
F_31 ( V_11 ) ;
return 0 ;
}
int F_38 ( struct V_51 * V_12 )
{
struct V_1 * V_2 = F_39 ( V_12 ) ;
return F_40 ( V_2 ) ;
}
int F_41 ( struct V_51 * V_12 )
{
struct V_1 * V_2 = F_39 ( V_12 ) ;
return F_42 ( V_2 ) ;
}
static int T_4 F_43 ( void )
{
F_44 ( L_20 ) ;
return 0 ;
}
static void T_5 F_45 ( void )
{
}
