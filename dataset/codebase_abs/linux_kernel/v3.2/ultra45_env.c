static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_3 , V_2 -> V_6 + V_7 ) ;
V_4 = F_4 ( V_2 -> V_6 + V_8 ) ;
F_5 ( & V_2 -> V_5 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
F_2 ( & V_2 -> V_5 ) ;
F_3 ( V_3 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_9 , V_2 -> V_6 + V_8 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
static T_2 F_7 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_17 , V_18 ;
T_1 V_9 ;
V_9 = F_1 ( V_2 , V_19 + V_15 ) ;
V_18 = ( int ) V_9 << 8 ;
if ( F_10 ( V_18 ) )
V_17 = F_11 ( V_18 ) ;
else
V_17 = 0 ;
return sprintf ( V_14 , L_1 , V_17 ) ;
}
static T_2 F_12 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_3 V_20 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
int V_17 = F_13 ( V_14 , NULL , 10 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
int V_18 ;
T_1 V_9 ;
if ( ! V_17 )
return - V_21 ;
V_18 = F_14 ( V_17 ) ;
V_9 = V_18 >> 8 ;
F_6 ( V_2 , V_19 + V_15 , V_9 ) ;
return V_20 ;
}
static T_2 F_15 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
int V_15 = F_8 ( V_13 ) -> V_16 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
T_1 V_9 = F_1 ( V_2 , V_22 ) ;
return sprintf ( V_14 , L_1 , ( V_9 & ( 1 << V_15 ) ) ? 1 : 0 ) ;
}
static T_2 F_16 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
int V_23 = F_8 ( V_13 ) -> V_16 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
T_4 V_9 ;
V_9 = F_1 ( V_2 , V_24 + V_23 ) ;
return sprintf ( V_14 , L_1 , ( ( int ) V_9 ) - 64 ) ;
}
static T_2 F_17 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
int V_16 = F_8 ( V_13 ) -> V_16 ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_2 -> V_6 + V_25 ) ;
return sprintf ( V_14 , L_1 , ( V_9 & ( 1 << V_16 ) ) ? 1 : 0 ) ;
}
static T_2 F_18 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
T_1 V_9 ;
V_9 = F_4 ( V_2 -> V_6 + V_25 ) ;
return sprintf ( V_14 , L_1 , V_9 >> 4 ) ;
}
static T_2 F_19 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
return sprintf ( V_14 , L_2 ) ;
}
static int T_5 F_20 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_21 ( sizeof( * V_2 ) , V_28 ) ;
int V_29 = - V_30 ;
if ( ! V_2 )
goto V_31;
F_22 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = F_23 ( & V_27 -> V_32 [ 0 ] , 0 , V_33 , L_3 ) ;
if ( ! V_2 -> V_6 )
goto V_34;
V_29 = F_24 ( & V_27 -> V_11 . V_35 , & V_36 ) ;
if ( V_29 )
goto V_37;
V_2 -> V_38 = F_25 ( & V_27 -> V_11 ) ;
if ( F_26 ( V_2 -> V_38 ) ) {
V_29 = F_27 ( V_2 -> V_38 ) ;
goto V_39;
}
F_28 ( V_27 , V_2 ) ;
V_29 = 0 ;
V_31:
return V_29 ;
V_39:
F_29 ( & V_27 -> V_11 . V_35 , & V_36 ) ;
V_37:
F_30 ( & V_27 -> V_32 [ 0 ] , V_2 -> V_6 , V_33 ) ;
V_34:
F_31 ( V_2 ) ;
goto V_31;
}
static int T_6 F_32 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_33 ( V_27 ) ;
if ( V_2 ) {
F_29 ( & V_27 -> V_11 . V_35 , & V_36 ) ;
F_34 ( V_2 -> V_38 ) ;
F_30 ( & V_27 -> V_32 [ 0 ] , V_2 -> V_6 , V_33 ) ;
F_31 ( V_2 ) ;
}
return 0 ;
}
