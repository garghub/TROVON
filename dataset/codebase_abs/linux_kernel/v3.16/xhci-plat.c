static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 |= V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , F_1 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
return F_5 ( V_8 ) ;
}
static int F_6 ( struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_7 * V_8 ;
struct V_15 * V_15 ;
int V_16 ;
int V_17 ;
if ( F_7 () )
return - V_18 ;
V_12 = & V_19 ;
V_17 = F_8 ( V_10 , 0 ) ;
if ( V_17 < 0 )
return - V_18 ;
V_14 = F_9 ( V_10 , V_20 , 0 ) ;
if ( ! V_14 )
return - V_18 ;
if ( F_10 ( V_10 -> V_2 . V_21 ,
L_1 ) ||
F_10 ( V_10 -> V_2 . V_21 ,
L_2 ) ) {
V_16 = F_11 ( V_10 ) ;
if ( V_16 )
return V_16 ;
}
V_16 = F_12 ( & V_10 -> V_2 , F_13 ( 32 ) ) ;
if ( V_16 )
return V_16 ;
if ( ! V_10 -> V_2 . V_22 )
V_10 -> V_2 . V_22 = & V_10 -> V_2 . V_23 ;
else
F_14 ( & V_10 -> V_2 , F_13 ( 32 ) ) ;
V_8 = F_15 ( V_12 , & V_10 -> V_2 , F_16 ( & V_10 -> V_2 ) ) ;
if ( ! V_8 )
return - V_24 ;
V_8 -> V_25 = V_14 -> V_26 ;
V_8 -> V_27 = F_17 ( V_14 ) ;
if ( ! F_18 ( V_8 -> V_25 , V_8 -> V_27 ,
V_12 -> V_28 ) ) {
F_19 ( & V_10 -> V_2 , L_3 ) ;
V_16 = - V_29 ;
goto V_30;
}
V_8 -> V_31 = F_20 ( V_8 -> V_25 , V_8 -> V_27 ) ;
if ( ! V_8 -> V_31 ) {
F_19 ( & V_10 -> V_2 , L_4 ) ;
V_16 = - V_32 ;
goto V_33;
}
V_15 = F_21 ( & V_10 -> V_2 , NULL ) ;
if ( ! F_22 ( V_15 ) ) {
V_16 = F_23 ( V_15 ) ;
if ( V_16 )
goto V_34;
}
V_16 = F_24 ( V_8 , V_17 , V_35 ) ;
if ( V_16 )
goto V_36;
F_25 ( V_8 -> V_37 . V_38 ) ;
V_8 = F_26 ( V_10 ) ;
V_4 = F_27 ( V_8 ) ;
V_4 -> V_15 = V_15 ;
V_4 -> V_39 = F_28 ( V_12 , & V_10 -> V_2 ,
F_16 ( & V_10 -> V_2 ) , V_8 ) ;
if ( ! V_4 -> V_39 ) {
V_16 = - V_24 ;
goto V_40;
}
* ( (struct V_3 * * ) V_4 -> V_39 -> V_41 ) = V_4 ;
if ( F_29 ( V_4 -> V_42 ) >= 4 )
V_4 -> V_39 -> V_43 = 1 ;
V_16 = F_24 ( V_4 -> V_39 , V_17 , V_35 ) ;
if ( V_16 )
goto V_44;
return 0 ;
V_44:
F_30 ( V_4 -> V_39 ) ;
V_40:
F_31 ( V_8 ) ;
V_36:
if ( ! F_22 ( V_15 ) )
F_32 ( V_15 ) ;
V_34:
F_33 ( V_8 -> V_31 ) ;
V_33:
V_33 ( V_8 -> V_25 , V_8 -> V_27 ) ;
V_30:
F_30 ( V_8 ) ;
return V_16 ;
}
static int F_34 ( struct V_9 * V_2 )
{
struct V_7 * V_8 = F_26 ( V_2 ) ;
struct V_3 * V_4 = F_27 ( V_8 ) ;
struct V_15 * V_15 = V_4 -> V_15 ;
F_31 ( V_4 -> V_39 ) ;
F_30 ( V_4 -> V_39 ) ;
F_31 ( V_8 ) ;
if ( ! F_22 ( V_15 ) )
F_32 ( V_15 ) ;
F_33 ( V_8 -> V_31 ) ;
V_33 ( V_8 -> V_25 , V_8 -> V_27 ) ;
F_30 ( V_8 ) ;
F_35 ( V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_37 ( V_2 ) ;
struct V_3 * V_4 = F_27 ( V_8 ) ;
return F_38 ( V_4 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_37 ( V_2 ) ;
struct V_3 * V_4 = F_27 ( V_8 ) ;
return F_40 ( V_4 , 0 ) ;
}
int F_41 ( void )
{
return F_42 ( & V_45 ) ;
}
void F_43 ( void )
{
F_44 ( & V_45 ) ;
}
