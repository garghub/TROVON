static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( F_3 ( V_2 ) , struct V_4 ,
V_2 ) ;
V_3 = F_4 ( V_5 -> V_6 ) ;
if ( V_5 -> V_7 )
V_3 = ! V_3 ;
F_5 ( & V_5 -> V_8 , V_3 ) ;
}
static T_1 F_6 ( int V_9 , void * V_10 )
{
struct V_4 * V_11 = V_10 ;
F_7 ( V_12 , & V_11 -> V_2 ,
V_11 -> V_13 ) ;
return V_14 ;
}
static T_2 F_8 ( struct V_15 * V_8 , char * V_16 )
{
struct V_4 * V_11 =
F_2 ( V_8 , struct V_4 , V_8 ) ;
const char * V_3 ;
if ( F_9 ( V_8 ) )
V_3 = V_11 -> V_17 ;
else
V_3 = V_11 -> V_18 ;
if ( V_3 )
return sprintf ( V_16 , L_1 , V_3 ) ;
return - V_19 ;
}
static int F_10 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_11 ( & V_21 -> V_24 ) ;
struct V_4 * V_11 ;
int V_25 ;
if ( ! V_23 )
return - V_26 ;
if ( ! V_23 -> V_27 ) {
F_12 ( & V_21 -> V_24 , L_2 ) ;
return - V_19 ;
}
V_11 = F_13 ( & V_21 -> V_24 , sizeof( struct V_4 ) ,
V_28 ) ;
if ( ! V_11 )
return - V_29 ;
V_11 -> V_8 . V_30 = V_23 -> V_30 ;
V_11 -> V_8 . V_24 . V_31 = & V_21 -> V_24 ;
V_11 -> V_6 = V_23 -> V_6 ;
V_11 -> V_7 = V_23 -> V_7 ;
V_11 -> V_17 = V_23 -> V_17 ;
V_11 -> V_18 = V_23 -> V_18 ;
if ( V_23 -> V_17 && V_23 -> V_18 )
V_11 -> V_8 . V_32 = F_8 ;
if ( V_23 -> V_33 ) {
V_25 = F_14 ( V_11 -> V_6 ,
V_23 -> V_33 * 1000 ) ;
if ( V_25 < 0 )
V_11 -> V_13 =
F_15 ( V_23 -> V_33 ) ;
}
V_25 = F_16 ( & V_11 -> V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_17 ( & V_21 -> V_24 , V_11 -> V_6 , V_34 ,
V_21 -> V_30 ) ;
if ( V_25 < 0 )
goto V_35;
F_18 ( & V_11 -> V_2 , F_1 ) ;
V_11 -> V_9 = F_19 ( V_11 -> V_6 ) ;
if ( V_11 -> V_9 < 0 ) {
V_25 = V_11 -> V_9 ;
goto V_35;
}
V_25 = F_20 ( V_11 -> V_9 , F_6 ,
V_23 -> V_27 , V_21 -> V_30 ,
V_11 ) ;
if ( V_25 < 0 )
goto V_35;
F_21 ( V_21 , V_11 ) ;
F_1 ( & V_11 -> V_2 . V_2 ) ;
return 0 ;
V_35:
F_22 ( & V_11 -> V_8 ) ;
return V_25 ;
}
static int F_23 ( struct V_20 * V_21 )
{
struct V_4 * V_11 = F_24 ( V_21 ) ;
F_25 ( & V_11 -> V_2 ) ;
F_26 ( V_11 -> V_9 , V_11 ) ;
F_22 ( & V_11 -> V_8 ) ;
return 0 ;
}
