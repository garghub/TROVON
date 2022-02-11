int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_3 , & V_5 ) ;
* V_4 = V_5 ;
return V_6 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_7 , T_1 * V_8 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_3 , V_8 , V_7 ) ;
return V_6 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
int V_6 ;
V_6 = F_6 ( V_2 , V_3 , V_9 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_7 , T_1 * V_8 )
{
int V_6 ;
V_6 = F_8 ( V_2 , V_3 , V_8 , V_7 ) ;
return V_6 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 , T_1 V_10 )
{
int V_6 ;
V_6 = F_10 ( V_2 , V_3 , V_10 , V_5 ) ;
return V_6 ;
}
static int F_11 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = V_12 -> V_19 . V_20 ;
T_1 V_21 ;
int V_6 = 0 ;
V_16 = F_12 ( & V_12 -> V_19 ,
sizeof( struct V_15 ) , V_22 ) ;
if ( V_16 == NULL )
return - V_23 ;
V_16 -> V_1 = F_13 ( V_12 , & V_24 ) ;
if ( F_14 ( V_16 -> V_1 ) ) {
V_6 = F_15 ( V_16 -> V_1 ) ;
F_16 ( V_16 -> V_19 , L_1 ,
V_6 ) ;
goto V_25;
}
F_17 ( V_12 , V_16 ) ;
V_16 -> V_19 = & V_12 -> V_19 ;
V_16 -> V_12 = V_12 ;
V_16 -> V_26 = V_12 -> V_26 ;
V_16 -> type = V_14 -> V_27 ;
if ( ! V_18 )
goto V_25;
V_16 -> V_28 = V_18 -> V_28 ;
F_18 ( & V_16 -> V_29 ) ;
if ( F_1 ( V_16 -> V_1 ,
V_30 , & V_21 ) < 0 ) {
F_16 ( V_16 -> V_19 , L_2 ) ;
V_6 = - V_31 ;
goto V_25;
} else
F_19 ( V_16 -> V_19 , L_3 , V_21 ) ;
V_16 -> V_32 = F_20 ( V_12 -> V_33 , V_34 ) ;
F_17 ( V_16 -> V_32 , V_16 ) ;
V_16 -> V_35 = F_20 ( V_12 -> V_33 , V_36 ) ;
F_17 ( V_16 -> V_35 , V_16 ) ;
V_6 = F_21 ( V_16 ) ;
if ( V_6 < 0 )
goto V_37;
F_22 ( V_16 -> V_19 ) ;
V_6 = F_23 ( V_16 -> V_19 , - 1 , V_38 ,
F_24 ( V_38 ) , NULL , 0 ) ;
if ( V_6 < 0 )
goto V_37;
F_25 ( V_16 -> V_19 , V_18 -> V_28 ) ;
return V_6 ;
V_37:
F_26 ( V_16 -> V_32 ) ;
F_26 ( V_16 -> V_35 ) ;
V_25:
F_27 ( V_16 ) ;
return V_6 ;
}
static int F_28 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = F_29 ( V_12 ) ;
F_30 ( V_16 -> V_19 ) ;
F_26 ( V_16 -> V_32 ) ;
F_26 ( V_16 -> V_35 ) ;
return 0 ;
}
static int F_31 ( struct V_39 * V_19 )
{
struct V_11 * V_12 = F_32 ( V_19 , struct V_11 , V_19 ) ;
struct V_15 * V_16 = F_29 ( V_12 ) ;
if ( F_33 ( V_19 ) )
F_34 ( V_16 -> V_26 , 1 ) ;
return 0 ;
}
static int F_35 ( struct V_39 * V_19 )
{
struct V_11 * V_12 = F_32 ( V_19 , struct V_11 , V_19 ) ;
struct V_15 * V_16 = F_29 ( V_12 ) ;
if ( F_33 ( V_19 ) )
F_34 ( V_16 -> V_26 , 0 ) ;
return F_36 ( V_16 ) ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_40 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_40 ) ;
}
