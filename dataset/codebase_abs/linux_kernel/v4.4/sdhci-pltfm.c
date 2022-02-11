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
T_1 V_14 ;
if ( F_5 ( V_7 , L_3 , NULL ) )
V_2 -> V_15 |= V_16 ;
if ( F_5 ( V_7 , L_4 , NULL ) ||
( F_10 ( V_7 , L_5 , & V_14 ) == 0 &&
V_14 == 1 ) )
V_2 -> V_15 |= V_17 ;
if ( F_4 ( V_7 ) )
V_2 -> V_15 |= V_18 ;
if ( F_5 ( V_7 , L_6 , NULL ) )
V_2 -> V_15 |= V_19 ;
if ( F_5 ( V_7 , L_7 , NULL ) )
V_2 -> V_20 |= V_21 ;
if ( F_11 ( V_7 , L_8 ) )
V_2 -> V_15 |= V_22 ;
if ( F_11 ( V_7 , L_9 ) ||
F_11 ( V_7 , L_10 ) ||
F_11 ( V_7 , L_11 ) ||
F_11 ( V_7 , L_12 ) )
V_2 -> V_15 |= V_23 ;
F_10 ( V_7 , L_13 , & V_4 -> clock ) ;
if ( F_12 ( V_7 , L_14 , NULL ) )
V_2 -> V_24 -> V_25 |= V_26 ;
if ( F_12 ( V_7 , L_15 , NULL ) )
V_2 -> V_24 -> V_25 |= V_27 ;
}
void F_8 ( struct V_10 * V_11 ) {}
struct V_1 * F_13 ( struct V_10 * V_11 ,
const struct V_28 * V_29 ,
T_2 V_30 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
int V_33 ;
V_32 = F_14 ( V_11 , V_34 , 0 ) ;
if ( ! V_32 ) {
V_33 = - V_35 ;
goto V_36;
}
if ( F_15 ( V_32 ) < 0x100 )
F_16 ( & V_11 -> V_12 , L_16 ) ;
V_2 = F_17 ( & V_11 -> V_12 ,
sizeof( struct V_3 ) + V_30 ) ;
if ( F_18 ( V_2 ) ) {
V_33 = F_19 ( V_2 ) ;
goto V_36;
}
V_2 -> V_37 = F_20 ( & V_11 -> V_12 ) ;
if ( V_29 && V_29 -> V_38 )
V_2 -> V_38 = V_29 -> V_38 ;
else
V_2 -> V_38 = & V_39 ;
if ( V_29 ) {
V_2 -> V_15 = V_29 -> V_15 ;
V_2 -> V_20 = V_29 -> V_20 ;
}
V_2 -> V_40 = F_21 ( V_11 , 0 ) ;
if ( ! F_22 ( V_32 -> V_41 , F_15 ( V_32 ) ,
F_23 ( V_2 -> V_24 ) ) ) {
F_16 ( & V_11 -> V_12 , L_17 ) ;
V_33 = - V_42 ;
goto V_43;
}
V_2 -> V_44 = F_24 ( V_32 -> V_41 , F_15 ( V_32 ) ) ;
if ( ! V_2 -> V_44 ) {
F_16 ( & V_11 -> V_12 , L_18 ) ;
V_33 = - V_35 ;
goto V_45;
}
if ( V_2 -> V_38 && V_2 -> V_38 -> V_46 )
V_2 -> V_38 -> V_46 ( V_2 ) ;
F_25 ( V_11 , V_2 ) ;
return V_2 ;
V_45:
F_26 ( V_32 -> V_41 , F_15 ( V_32 ) ) ;
V_43:
F_27 ( V_2 ) ;
V_36:
F_16 ( & V_11 -> V_12 , L_19 , V_47 , V_33 ) ;
return F_28 ( V_33 ) ;
}
void F_29 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_31 * V_32 = F_14 ( V_11 , V_34 , 0 ) ;
F_30 ( V_2 -> V_44 ) ;
F_26 ( V_32 -> V_41 , F_15 ( V_32 ) ) ;
F_27 ( V_2 ) ;
}
int F_31 ( struct V_10 * V_11 ,
const struct V_28 * V_29 ,
T_2 V_30 )
{
struct V_1 * V_2 ;
int V_33 = 0 ;
V_2 = F_13 ( V_11 , V_29 , V_30 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
F_8 ( V_11 ) ;
V_33 = F_32 ( V_2 ) ;
if ( V_33 )
F_29 ( V_11 ) ;
return V_33 ;
}
int F_33 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_48 = ( F_34 ( V_2 -> V_44 + V_49 ) == 0xffffffff ) ;
F_35 ( V_2 , V_48 ) ;
F_36 ( V_4 -> V_5 ) ;
F_29 ( V_11 ) ;
return 0 ;
}
int F_37 ( struct V_50 * V_12 )
{
struct V_1 * V_2 = F_38 ( V_12 ) ;
return F_39 ( V_2 ) ;
}
int F_40 ( struct V_50 * V_12 )
{
struct V_1 * V_2 = F_38 ( V_12 ) ;
return F_41 ( V_2 ) ;
}
static int T_3 F_42 ( void )
{
F_43 ( L_20 ) ;
return 0 ;
}
static void T_4 F_44 ( void )
{
}
