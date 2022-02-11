static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int (* F_3)( struct V_7 * V_7 , int V_4 );
if ( ! V_6 -> V_8 )
return - V_9 ;
F_3 = V_3 ? V_10 : V_11 ;
return F_3 ( V_6 -> V_7 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_1 ( V_2 , V_3 , V_13 ) ;
F_6 ( V_6 -> V_7 ) ;
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_16 , V_17 , V_18 ;
if ( ! V_6 -> V_8 )
return - V_9 ;
do {
int V_12 ;
V_12 = F_8 ( V_6 -> V_7 , V_19 , & V_17 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_6 -> V_7 , V_20 , & V_16 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_6 -> V_7 , V_19 , & V_18 ) ;
if ( V_12 )
return V_12 ;
} while ( V_17 != V_18 );
F_9 ( ( V_21 ) V_17 * V_22 + V_16 , V_15 ) ;
return F_10 ( V_15 ) ;
}
static int F_11 ( struct V_1 * V_2 , V_21 V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_16 , V_24 ;
unsigned int V_25 ;
int V_12 ;
V_24 = F_12 ( V_23 , V_22 , & V_16 ) ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_8 ( V_6 -> V_7 , V_26 , & V_25 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
if ( V_25 < V_22 ) {
V_12 = F_14 ( V_6 -> V_7 ,
V_26 , 0x1ffff ) ;
if ( F_13 ( V_12 ) )
goto V_27;
}
V_12 = F_14 ( V_6 -> V_7 , V_20 , 0 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_12 = F_14 ( V_6 -> V_7 , V_19 , V_24 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_12 = F_14 ( V_6 -> V_7 , V_20 , V_16 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
if ( V_25 < V_22 ) {
V_12 = F_14 ( V_6 -> V_7 ,
V_26 , V_25 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
}
if ( ! V_6 -> V_8 ) {
V_12 = F_15 ( V_6 -> V_7 , V_28 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_12 = V_10 ( V_6 -> V_7 , V_28 ) ;
}
V_27:
V_6 -> V_8 = ! V_12 ;
F_6 ( V_6 -> V_7 ) ;
return V_12 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_16 , V_24 ;
V_21 V_31 ;
int V_3 , V_32 ;
int V_12 ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_8 ( V_6 -> V_7 , V_26 , & V_16 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
if ( V_16 >= V_22 ) {
V_12 = - V_9 ;
goto V_27;
}
V_12 = F_8 ( V_6 -> V_7 , V_19 , & V_24 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_12 = F_17 ( V_6 -> V_7 , V_13 ,
& V_3 , & V_32 ) ;
V_27:
F_6 ( V_6 -> V_7 ) ;
if ( V_12 )
return V_12 ;
V_30 -> V_3 = V_3 ;
V_30 -> V_32 = V_32 ;
V_31 = ( V_21 ) V_24 * V_22 + V_16 ;
F_9 ( V_31 , & V_30 -> time ) ;
F_18 ( V_2 , L_1 , V_33 , ( long long ) V_31 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_21 V_31 ;
T_1 V_16 , V_24 ;
int V_12 ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_14 ( V_6 -> V_7 , V_26 , 0x1ffff ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_12 = F_15 ( V_6 -> V_7 , V_13 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_31 = F_20 ( & V_30 -> time ) ;
F_18 ( V_2 , L_2 , V_33 , V_30 -> V_3 ? L_3 : L_4 ,
( long long ) V_31 ) ;
V_12 = F_1 ( V_2 , V_30 -> V_3 ,
V_13 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_24 = F_12 ( V_31 , V_22 , & V_16 ) ;
V_12 = F_14 ( V_6 -> V_7 , V_34 , V_24 ) ;
if ( F_13 ( V_12 ) )
goto V_27;
V_12 = F_14 ( V_6 -> V_7 , V_26 , V_16 ) ;
V_27:
F_6 ( V_6 -> V_7 ) ;
return V_12 ;
}
static T_2 F_21 ( int V_4 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
struct V_7 * V_7 = V_6 -> V_7 ;
F_22 ( V_6 -> V_35 , 1 , V_36 | V_37 ) ;
F_15 ( V_7 , V_4 ) ;
return V_38 ;
}
static T_2 F_23 ( int V_4 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
struct V_7 * V_7 = V_6 -> V_7 ;
V_6 -> V_8 = 0 ;
V_11 ( V_7 , V_4 ) ;
return V_38 ;
}
static int T_3 F_24 ( struct V_39 * V_40 )
{
int V_12 ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
V_6 = F_25 ( & V_40 -> V_2 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 )
return - V_42 ;
V_7 = F_2 ( V_40 -> V_2 . V_43 ) ;
V_6 -> V_7 = V_7 ;
V_6 -> V_8 = 1 ;
F_26 ( V_40 , V_6 ) ;
F_5 ( V_7 ) ;
F_15 ( V_7 , V_28 ) ;
V_12 = F_27 ( V_7 , V_28 ,
F_23 , V_44 , V_6 ) ;
if ( V_12 )
goto V_45;
V_12 = F_28 ( V_7 , V_13 ,
F_21 , V_44 , V_6 ) ;
if ( V_12 )
goto V_45;
F_6 ( V_7 ) ;
V_6 -> V_35 = F_29 ( & V_40 -> V_2 , V_40 -> V_46 ,
& V_47 , V_48 ) ;
return 0 ;
V_45:
F_30 ( V_7 , V_13 , V_6 ) ;
F_30 ( V_7 , V_28 , V_6 ) ;
F_6 ( V_7 ) ;
return V_12 ;
}
static int F_31 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_32 ( V_40 ) ;
F_5 ( V_6 -> V_7 ) ;
F_30 ( V_6 -> V_7 , V_13 , V_6 ) ;
F_30 ( V_6 -> V_7 , V_28 , V_6 ) ;
F_6 ( V_6 -> V_7 ) ;
return 0 ;
}
