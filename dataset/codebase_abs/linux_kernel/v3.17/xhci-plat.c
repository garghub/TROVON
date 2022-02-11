static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 |= V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 -> V_10 ;
int V_13 ;
if ( F_3 ( V_10 , L_1 ) ||
F_3 ( V_10 , L_2 ) ) {
V_13 = F_4 ( V_8 ) ;
if ( V_13 )
return V_13 ;
}
return F_5 ( V_8 , F_1 ) ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 -> V_10 ;
if ( F_3 ( V_10 , L_1 ) ||
F_3 ( V_10 , L_2 ) )
F_7 ( V_8 ) ;
return F_8 ( V_8 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_9 * V_16 = V_15 -> V_2 . V_10 ;
struct V_17 * V_18 = F_10 ( & V_15 -> V_2 ) ;
const struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_21 * V_22 ;
struct V_7 * V_8 ;
struct V_23 * V_23 ;
int V_13 ;
int V_24 ;
if ( F_11 () )
return - V_25 ;
V_20 = & V_26 ;
V_24 = F_12 ( V_15 , 0 ) ;
if ( V_24 < 0 )
return - V_25 ;
V_22 = F_13 ( V_15 , V_27 , 0 ) ;
if ( ! V_22 )
return - V_25 ;
if ( F_3 ( V_15 -> V_2 . V_10 ,
L_3 ) ||
F_3 ( V_15 -> V_2 . V_10 ,
L_4 ) ) {
V_13 = F_14 ( V_15 ) ;
if ( V_13 )
return V_13 ;
}
V_13 = F_15 ( & V_15 -> V_2 , F_16 ( 32 ) ) ;
if ( V_13 )
return V_13 ;
if ( ! V_15 -> V_2 . V_28 )
V_15 -> V_2 . V_28 = & V_15 -> V_2 . V_29 ;
else
F_17 ( & V_15 -> V_2 , F_16 ( 32 ) ) ;
V_8 = F_18 ( V_20 , & V_15 -> V_2 , F_19 ( & V_15 -> V_2 ) ) ;
if ( ! V_8 )
return - V_30 ;
V_8 -> V_31 = V_22 -> V_32 ;
V_8 -> V_33 = F_20 ( V_22 ) ;
V_8 -> V_34 = F_21 ( & V_15 -> V_2 , V_22 ) ;
if ( F_22 ( V_8 -> V_34 ) ) {
V_13 = F_23 ( V_8 -> V_34 ) ;
goto V_35;
}
V_23 = F_24 ( & V_15 -> V_2 , NULL ) ;
if ( ! F_22 ( V_23 ) ) {
V_13 = F_25 ( V_23 ) ;
if ( V_13 )
goto V_35;
}
V_13 = F_26 ( V_8 , V_24 , V_36 ) ;
if ( V_13 )
goto V_37;
F_27 ( V_8 -> V_11 . V_12 ) ;
V_8 = F_28 ( V_15 ) ;
V_4 = F_29 ( V_8 ) ;
V_4 -> V_23 = V_23 ;
V_4 -> V_38 = F_30 ( V_20 , & V_15 -> V_2 ,
F_19 ( & V_15 -> V_2 ) , V_8 ) ;
if ( ! V_4 -> V_38 ) {
V_13 = - V_30 ;
goto V_39;
}
if ( ( V_16 && F_31 ( V_16 , L_5 ) ) ||
( V_18 && V_18 -> V_40 ) )
V_4 -> V_5 |= V_41 ;
* ( (struct V_3 * * ) V_4 -> V_38 -> V_42 ) = V_4 ;
if ( F_32 ( V_4 -> V_43 ) >= 4 )
V_4 -> V_38 -> V_44 = 1 ;
V_13 = F_26 ( V_4 -> V_38 , V_24 , V_36 ) ;
if ( V_13 )
goto V_45;
return 0 ;
V_45:
F_33 ( V_4 -> V_38 ) ;
V_39:
F_34 ( V_8 ) ;
V_37:
if ( ! F_22 ( V_23 ) )
F_35 ( V_23 ) ;
V_35:
F_33 ( V_8 ) ;
return V_13 ;
}
static int F_36 ( struct V_14 * V_2 )
{
struct V_7 * V_8 = F_28 ( V_2 ) ;
struct V_3 * V_4 = F_29 ( V_8 ) ;
struct V_23 * V_23 = V_4 -> V_23 ;
F_34 ( V_4 -> V_38 ) ;
F_33 ( V_4 -> V_38 ) ;
F_34 ( V_8 ) ;
if ( ! F_22 ( V_23 ) )
F_35 ( V_23 ) ;
F_33 ( V_8 ) ;
F_37 ( V_4 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_39 ( V_2 ) ;
struct V_3 * V_4 = F_29 ( V_8 ) ;
return F_40 ( V_4 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_39 ( V_2 ) ;
struct V_3 * V_4 = F_29 ( V_8 ) ;
return F_42 ( V_4 , 0 ) ;
}
int F_43 ( void )
{
return F_44 ( & V_46 ) ;
}
void F_45 ( void )
{
F_46 ( & V_46 ) ;
}
