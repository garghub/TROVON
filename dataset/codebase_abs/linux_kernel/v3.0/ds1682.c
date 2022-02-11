static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
T_2 V_10 = 0 ;
int V_11 ;
F_4 ( V_2 , L_1 , V_4 -> V_4 . V_12 ) ;
V_11 = F_5 ( V_9 , V_7 -> V_13 , V_7 -> V_14 ,
( V_15 * ) & V_10 ) ;
if ( V_11 < 0 )
return - V_16 ;
if ( V_7 -> V_14 == 4 )
return sprintf ( V_5 , L_2 ,
( ( unsigned long long ) F_6 ( V_10 ) ) * 250 ) ;
return sprintf ( V_5 , L_3 , ( long ) F_6 ( V_10 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_17 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
char * V_18 ;
T_4 V_10 ;
T_2 V_19 ;
int V_11 ;
F_4 ( V_2 , L_4 , V_4 -> V_4 . V_12 ) ;
V_10 = F_8 ( V_5 , & V_18 , 0 ) ;
if ( V_5 == V_18 ) {
F_4 ( V_2 , L_5 ) ;
return - V_20 ;
}
if ( V_7 -> V_14 == 4 )
F_9 ( V_10 , 250 ) ;
V_19 = F_10 ( V_10 ) ;
V_11 = F_11 ( V_9 , V_7 -> V_13 , V_7 -> V_14 ,
( V_15 * ) & V_19 ) ;
if ( V_11 < 0 ) {
F_12 ( V_2 , L_6 ,
V_7 -> V_13 , V_7 -> V_14 ) ;
return - V_16 ;
}
return V_17 ;
}
static T_1 F_13 ( struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_25 * V_4 ,
char * V_5 , T_5 V_26 , T_3 V_17 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
int V_11 ;
F_4 ( & V_9 -> V_2 , L_7 ,
V_5 , V_26 , V_17 ) ;
if ( V_26 >= V_27 )
return 0 ;
if ( V_26 + V_17 > V_27 )
V_17 = V_27 - V_26 ;
V_11 = F_5 ( V_9 , V_28 + V_26 ,
V_17 , V_5 ) ;
if ( V_11 < 0 )
return - V_16 ;
return V_17 ;
}
static T_1 F_15 ( struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_25 * V_4 ,
char * V_5 , T_5 V_26 , T_3 V_17 )
{
struct V_8 * V_9 = F_14 ( V_24 ) ;
F_4 ( & V_9 -> V_2 , L_8 ,
V_5 , V_26 , V_17 ) ;
if ( V_26 >= V_27 )
return - V_29 ;
if ( V_26 + V_17 > V_27 )
V_17 = V_27 - V_26 ;
if ( F_11 ( V_9 , V_28 + V_26 ,
V_17 , V_5 ) < 0 )
return - V_16 ;
return V_17 ;
}
static int F_16 ( struct V_8 * V_9 ,
const struct V_30 * V_31 )
{
int V_11 ;
if ( ! F_17 ( V_9 -> V_32 ,
V_33 ) ) {
F_12 ( & V_9 -> V_2 , L_9 ) ;
V_11 = - V_34 ;
goto exit;
}
V_11 = F_18 ( & V_9 -> V_2 . V_24 , & V_35 ) ;
if ( V_11 )
goto exit;
V_11 = F_19 ( & V_9 -> V_2 . V_24 , & V_36 ) ;
if ( V_11 )
goto V_37;
return 0 ;
V_37:
F_20 ( & V_9 -> V_2 . V_24 , & V_35 ) ;
exit:
return V_11 ;
}
static int F_21 ( struct V_8 * V_9 )
{
F_22 ( & V_9 -> V_2 . V_24 , & V_36 ) ;
F_20 ( & V_9 -> V_2 . V_24 , & V_35 ) ;
return 0 ;
}
static int T_6 F_23 ( void )
{
return F_24 ( & V_38 ) ;
}
static void T_7 F_25 ( void )
{
F_26 ( & V_38 ) ;
}
