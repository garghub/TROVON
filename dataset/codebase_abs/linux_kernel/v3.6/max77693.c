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
if ( F_1 ( V_16 -> V_1 ,
V_29 , & V_21 ) < 0 ) {
F_16 ( V_16 -> V_19 , L_2 ) ;
V_6 = - V_30 ;
goto V_25;
} else
F_18 ( V_16 -> V_19 , L_3 , V_21 ) ;
V_16 -> V_31 = F_19 ( V_12 -> V_32 , V_33 ) ;
F_17 ( V_16 -> V_31 , V_16 ) ;
V_16 -> V_34 = F_19 ( V_12 -> V_32 , V_35 ) ;
F_17 ( V_16 -> V_34 , V_16 ) ;
V_16 -> V_36 = F_13 ( V_16 -> V_31 ,
& V_24 ) ;
if ( F_14 ( V_16 -> V_36 ) ) {
V_6 = F_15 ( V_16 -> V_36 ) ;
F_16 ( V_16 -> V_19 ,
L_1 , V_6 ) ;
goto V_25;
}
V_6 = F_20 ( V_16 ) ;
if ( V_6 < 0 )
goto V_37;
F_21 ( V_16 -> V_19 ) ;
V_6 = F_22 ( V_16 -> V_19 , - 1 , V_38 ,
F_23 ( V_38 ) , NULL , 0 , NULL ) ;
if ( V_6 < 0 )
goto V_39;
F_24 ( V_16 -> V_19 , V_18 -> V_28 ) ;
return V_6 ;
V_39:
F_25 ( V_16 ) ;
V_37:
F_26 ( V_16 -> V_31 ) ;
F_26 ( V_16 -> V_34 ) ;
V_25:
return V_6 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = F_28 ( V_12 ) ;
F_29 ( V_16 -> V_19 ) ;
F_25 ( V_16 ) ;
F_26 ( V_16 -> V_31 ) ;
F_26 ( V_16 -> V_34 ) ;
return 0 ;
}
static int F_30 ( struct V_40 * V_19 )
{
struct V_11 * V_12 = F_31 ( V_19 , struct V_11 , V_19 ) ;
struct V_15 * V_16 = F_28 ( V_12 ) ;
if ( F_32 ( V_19 ) )
F_33 ( V_16 -> V_26 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_40 * V_19 )
{
struct V_11 * V_12 = F_31 ( V_19 , struct V_11 , V_19 ) ;
struct V_15 * V_16 = F_28 ( V_12 ) ;
if ( F_32 ( V_19 ) )
F_33 ( V_16 -> V_26 , 0 ) ;
return F_35 ( V_16 ) ;
}
static int T_2 F_36 ( void )
{
return F_37 ( & V_41 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_41 ) ;
}
