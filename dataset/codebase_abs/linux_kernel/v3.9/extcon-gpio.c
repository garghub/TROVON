static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( F_3 ( V_2 ) , struct V_4 ,
V_2 ) ;
V_3 = F_4 ( V_5 -> V_6 ) ;
F_5 ( & V_5 -> V_7 , V_3 ) ;
}
static T_1 F_6 ( int V_8 , void * V_9 )
{
struct V_4 * V_10 = V_9 ;
F_7 ( & V_10 -> V_2 ,
V_10 -> V_11 ) ;
return V_12 ;
}
static T_2 F_8 ( struct V_13 * V_7 , char * V_14 )
{
struct V_4 * V_10 =
F_2 ( V_7 , struct V_4 , V_7 ) ;
const char * V_3 ;
if ( F_9 ( V_7 ) )
V_3 = V_10 -> V_15 ;
else
V_3 = V_10 -> V_16 ;
if ( V_3 )
return sprintf ( V_14 , L_1 , V_3 ) ;
return - V_17 ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 . V_23 ;
struct V_4 * V_10 ;
int V_24 = 0 ;
if ( ! V_21 )
return - V_25 ;
if ( ! V_21 -> V_26 ) {
F_11 ( & V_19 -> V_22 , L_2 ) ;
return - V_17 ;
}
V_10 = F_12 ( & V_19 -> V_22 , sizeof( struct V_4 ) ,
V_27 ) ;
if ( ! V_10 )
return - V_28 ;
V_10 -> V_7 . V_29 = V_21 -> V_29 ;
V_10 -> V_6 = V_21 -> V_6 ;
V_10 -> V_15 = V_21 -> V_15 ;
V_10 -> V_16 = V_21 -> V_16 ;
if ( V_21 -> V_15 && V_21 -> V_16 )
V_10 -> V_7 . V_30 = F_8 ;
V_10 -> V_11 = F_13 ( V_21 -> V_31 ) ;
V_24 = F_14 ( & V_10 -> V_7 , & V_19 -> V_22 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_15 ( & V_19 -> V_22 , V_10 -> V_6 , V_32 ,
V_19 -> V_29 ) ;
if ( V_24 < 0 )
goto V_33;
F_16 ( & V_10 -> V_2 , F_1 ) ;
V_10 -> V_8 = F_17 ( V_10 -> V_6 ) ;
if ( V_10 -> V_8 < 0 ) {
V_24 = V_10 -> V_8 ;
goto V_33;
}
V_24 = F_18 ( V_10 -> V_8 , F_6 ,
V_21 -> V_26 , V_19 -> V_29 ,
V_10 ) ;
if ( V_24 < 0 )
goto V_33;
F_19 ( V_19 , V_10 ) ;
F_1 ( & V_10 -> V_2 . V_2 ) ;
return 0 ;
V_33:
F_20 ( & V_10 -> V_7 ) ;
return V_24 ;
}
static int F_21 ( struct V_18 * V_19 )
{
struct V_4 * V_10 = F_22 ( V_19 ) ;
F_23 ( & V_10 -> V_2 ) ;
F_24 ( V_10 -> V_8 , V_10 ) ;
F_20 ( & V_10 -> V_7 ) ;
return 0 ;
}
