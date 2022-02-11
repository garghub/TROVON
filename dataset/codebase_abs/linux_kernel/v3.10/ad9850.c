static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
struct V_7 V_8 ;
int V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_5 ;
struct V_12 * V_13 = F_2 ( V_2 ) ;
struct V_14 * V_15 = F_3 ( V_13 ) ;
V_8 . V_6 = V_6 ;
V_8 . V_16 = V_11 ;
F_4 ( & V_15 -> V_17 ) ;
V_9 = F_5 ( V_15 -> V_18 , & V_8 , 1 ) ;
if ( V_9 )
goto V_19;
V_19:
F_6 ( & V_15 -> V_17 ) ;
return V_9 ? V_9 : V_6 ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_14 * V_15 ;
struct V_12 * V_13 ;
int V_9 = 0 ;
V_13 = F_8 ( sizeof( * V_15 ) ) ;
if ( V_13 == NULL ) {
V_9 = - V_22 ;
goto V_19;
}
F_9 ( V_21 , V_13 ) ;
V_15 = F_3 ( V_13 ) ;
F_10 ( & V_15 -> V_17 ) ;
V_15 -> V_18 = V_21 ;
V_13 -> V_2 . V_23 = & V_21 -> V_2 ;
V_13 -> V_24 = & V_25 ;
V_13 -> V_26 = V_27 ;
V_9 = F_11 ( V_13 ) ;
if ( V_9 )
goto V_28;
V_21 -> V_29 = 2000000 ;
V_21 -> V_30 = V_31 ;
V_21 -> V_32 = 16 ;
F_12 ( V_21 ) ;
return 0 ;
V_28:
F_13 ( V_13 ) ;
V_19:
return V_9 ;
}
static int F_14 ( struct V_20 * V_21 )
{
F_15 ( F_16 ( V_21 ) ) ;
F_13 ( F_16 ( V_21 ) ) ;
return 0 ;
}
