static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( & V_3 -> V_4 ) ;
}
static void F_3 ( struct V_5 * V_4 )
{
struct V_2 * V_3 = F_4 ( V_4 , struct V_2 , V_4 ) ;
F_5 ( & V_3 -> V_6 ) ;
F_6 ( & V_3 -> V_7 , 0 ) ;
memset ( V_3 -> V_8 , 0 , sizeof( V_3 -> V_8 ) ) ;
F_7 ( & V_3 -> V_6 ) ;
}
static int F_8 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_11 * V_12 =
F_4 ( V_9 -> V_13 , struct V_11 , V_14 ) ;
struct V_2 * V_3 ;
if ( F_9 ( 0 , & V_12 -> V_15 ) ) {
F_10 ( V_12 -> V_16 , L_1 ) ;
return - V_17 ;
}
V_3 = F_11 ( sizeof( * V_3 ) , V_18 ) ;
if ( V_3 == NULL ) {
F_12 ( 0 , & V_12 -> V_15 ) ;
return - V_19 ;
}
V_3 -> V_12 = V_12 ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_13 ( & V_3 -> V_6 ) ;
F_14 ( & V_3 -> V_20 , F_1 ,
( unsigned long ) V_3 ) ;
F_15 ( & V_3 -> V_4 , F_3 ) ;
V_10 -> V_21 = V_3 ;
F_16 ( V_12 -> V_16 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_10 * V_10 , char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
struct V_2 * V_3 = V_10 -> V_21 ;
T_1 V_25 ;
int V_26 ;
F_18 ( & V_3 -> V_20 ) ;
F_19 ( & V_3 -> V_4 ) ;
V_25 = F_20 ( & V_3 -> V_7 ) ;
if ( V_25 > 0 ) {
T_1 V_27 = V_25 ;
if ( V_23 < V_25 )
V_25 = V_23 ;
F_5 ( & V_3 -> V_6 ) ;
V_26 = F_21 ( V_22 , V_3 -> V_8 , V_25 ) ;
memset ( V_3 -> V_8 , 0 , V_27 ) ;
if ( V_26 )
V_25 = - V_28 ;
F_7 ( & V_3 -> V_6 ) ;
}
F_6 ( & V_3 -> V_7 , 0 ) ;
return V_25 ;
}
static T_1 F_22 ( struct V_10 * V_10 , const char T_2 * V_22 ,
T_3 V_23 , T_4 * V_24 )
{
struct V_2 * V_3 = V_10 -> V_21 ;
T_3 V_29 = V_23 ;
T_1 V_30 ;
if ( F_20 ( & V_3 -> V_7 ) != 0 )
return - V_17 ;
if ( V_29 > V_31 )
return - V_32 ;
F_5 ( & V_3 -> V_6 ) ;
if ( F_23
( V_3 -> V_8 , ( void T_2 * ) V_22 , V_29 ) ) {
F_7 ( & V_3 -> V_6 ) ;
return - V_28 ;
}
V_30 = F_24 ( V_3 -> V_12 , V_3 -> V_8 ,
sizeof( V_3 -> V_8 ) ) ;
if ( V_30 < 0 ) {
F_7 ( & V_3 -> V_6 ) ;
return V_30 ;
}
F_6 ( & V_3 -> V_7 , V_30 ) ;
F_7 ( & V_3 -> V_6 ) ;
F_25 ( & V_3 -> V_20 , V_33 + ( 60 * V_34 ) ) ;
return V_29 ;
}
static int F_26 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
struct V_2 * V_3 = V_10 -> V_21 ;
F_18 ( & V_3 -> V_20 ) ;
F_19 ( & V_3 -> V_4 ) ;
V_10 -> V_21 = NULL ;
F_6 ( & V_3 -> V_7 , 0 ) ;
F_12 ( 0 , & V_3 -> V_12 -> V_15 ) ;
F_27 ( V_3 -> V_12 -> V_16 ) ;
F_28 ( V_3 ) ;
return 0 ;
}
