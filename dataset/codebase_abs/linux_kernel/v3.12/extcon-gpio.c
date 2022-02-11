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
F_7 ( V_11 , & V_10 -> V_2 ,
V_10 -> V_12 ) ;
return V_13 ;
}
static T_2 F_8 ( struct V_14 * V_7 , char * V_15 )
{
struct V_4 * V_10 =
F_2 ( V_7 , struct V_4 , V_7 ) ;
const char * V_3 ;
if ( F_9 ( V_7 ) )
V_3 = V_10 -> V_16 ;
else
V_3 = V_10 -> V_17 ;
if ( V_3 )
return sprintf ( V_15 , L_1 , V_3 ) ;
return - V_18 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_24 ;
struct V_4 * V_10 ;
int V_25 = 0 ;
if ( ! V_22 )
return - V_26 ;
if ( ! V_22 -> V_27 ) {
F_11 ( & V_20 -> V_23 , L_2 ) ;
return - V_18 ;
}
V_10 = F_12 ( & V_20 -> V_23 , sizeof( struct V_4 ) ,
V_28 ) ;
if ( ! V_10 )
return - V_29 ;
V_10 -> V_7 . V_30 = V_22 -> V_30 ;
V_10 -> V_6 = V_22 -> V_6 ;
V_10 -> V_16 = V_22 -> V_16 ;
V_10 -> V_17 = V_22 -> V_17 ;
if ( V_22 -> V_16 && V_22 -> V_17 )
V_10 -> V_7 . V_31 = F_8 ;
V_10 -> V_12 = F_13 ( V_22 -> V_32 ) ;
V_25 = F_14 ( & V_10 -> V_7 , & V_20 -> V_23 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_15 ( & V_20 -> V_23 , V_10 -> V_6 , V_33 ,
V_20 -> V_30 ) ;
if ( V_25 < 0 )
goto V_34;
F_16 ( & V_10 -> V_2 , F_1 ) ;
V_10 -> V_8 = F_17 ( V_10 -> V_6 ) ;
if ( V_10 -> V_8 < 0 ) {
V_25 = V_10 -> V_8 ;
goto V_34;
}
V_25 = F_18 ( V_10 -> V_8 , F_6 ,
V_22 -> V_27 , V_20 -> V_30 ,
V_10 ) ;
if ( V_25 < 0 )
goto V_34;
F_19 ( V_20 , V_10 ) ;
F_1 ( & V_10 -> V_2 . V_2 ) ;
return 0 ;
V_34:
F_20 ( & V_10 -> V_7 ) ;
return V_25 ;
}
static int F_21 ( struct V_19 * V_20 )
{
struct V_4 * V_10 = F_22 ( V_20 ) ;
F_23 ( & V_10 -> V_2 ) ;
F_24 ( V_10 -> V_8 , V_10 ) ;
F_20 ( & V_10 -> V_7 ) ;
return 0 ;
}
