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
if ( F_13 ( V_7 , L_15 ) ||
F_13 ( V_7 , L_16 ) )
V_2 -> V_24 -> V_25 |= V_27 ;
}
void F_8 ( struct V_10 * V_11 ) {}
struct V_1 * F_14 ( struct V_10 * V_11 ,
const struct V_28 * V_29 ,
T_2 V_30 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
void T_3 * V_33 ;
int V_34 , V_35 ;
V_32 = F_15 ( V_11 , V_36 , 0 ) ;
V_33 = F_16 ( & V_11 -> V_12 , V_32 ) ;
if ( F_17 ( V_33 ) ) {
V_35 = F_18 ( V_33 ) ;
goto V_37;
}
V_34 = F_19 ( V_11 , 0 ) ;
if ( V_34 < 0 ) {
F_20 ( & V_11 -> V_12 , L_17 ) ;
V_35 = V_34 ;
goto V_37;
}
V_2 = F_21 ( & V_11 -> V_12 ,
sizeof( struct V_3 ) + V_30 ) ;
if ( F_17 ( V_2 ) ) {
V_35 = F_18 ( V_2 ) ;
goto V_37;
}
V_2 -> V_33 = V_33 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_38 = F_22 ( & V_11 -> V_12 ) ;
if ( V_29 && V_29 -> V_39 )
V_2 -> V_39 = V_29 -> V_39 ;
else
V_2 -> V_39 = & V_40 ;
if ( V_29 ) {
V_2 -> V_15 = V_29 -> V_15 ;
V_2 -> V_20 = V_29 -> V_20 ;
}
F_23 ( V_11 , V_2 ) ;
return V_2 ;
V_37:
F_20 ( & V_11 -> V_12 , L_18 , V_41 , V_35 ) ;
return F_24 ( V_35 ) ;
}
void F_25 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_26 ( V_2 ) ;
}
int F_27 ( struct V_10 * V_11 ,
const struct V_28 * V_29 ,
T_2 V_30 )
{
struct V_1 * V_2 ;
int V_35 = 0 ;
V_2 = F_14 ( V_11 , V_29 , V_30 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
F_8 ( V_11 ) ;
V_35 = F_28 ( V_2 ) ;
if ( V_35 )
F_25 ( V_11 ) ;
return V_35 ;
}
int F_29 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_42 = ( F_30 ( V_2 -> V_33 + V_43 ) == 0xffffffff ) ;
F_31 ( V_2 , V_42 ) ;
F_32 ( V_4 -> V_5 ) ;
F_25 ( V_11 ) ;
return 0 ;
}
int F_33 ( struct V_44 * V_12 )
{
struct V_1 * V_2 = F_34 ( V_12 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_35 ;
if ( V_2 -> V_45 != V_46 )
F_35 ( V_2 -> V_24 ) ;
V_35 = F_36 ( V_2 ) ;
if ( V_35 )
return V_35 ;
F_32 ( V_4 -> V_5 ) ;
return 0 ;
}
int F_37 ( struct V_44 * V_12 )
{
struct V_1 * V_2 = F_34 ( V_12 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_35 ;
V_35 = F_38 ( V_4 -> V_5 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_39 ( V_2 ) ;
if ( V_35 )
F_32 ( V_4 -> V_5 ) ;
return V_35 ;
}
static int T_4 F_40 ( void )
{
F_41 ( L_19 ) ;
return 0 ;
}
static void T_5 F_42 ( void )
{
}
