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
unsigned int V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_1 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_6 -> V_7 ) ;
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_15 , V_16 , V_17 ;
unsigned long V_18 ;
int V_12 ;
F_5 ( V_6 -> V_7 ) ;
if ( ! V_6 -> V_8 ) {
V_12 = - V_9 ;
goto V_19;
}
V_12 = F_8 ( V_6 -> V_7 , V_20 , & V_16 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_8 ( V_6 -> V_7 , V_21 , & V_15 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_8 ( V_6 -> V_7 , V_20 , & V_17 ) ;
V_19:
F_6 ( V_6 -> V_7 ) ;
if ( V_12 )
return V_12 ;
if ( V_17 == V_16 + 1 ) {
if ( V_15 >= 86400 / 2 )
V_17 = V_16 ;
else
V_16 = V_17 ;
}
if ( V_16 != V_17 )
return - V_22 ;
V_18 = V_16 * 86400 + V_15 ;
F_10 ( V_18 , V_14 ) ;
return F_11 ( V_14 ) ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_15 , V_24 ;
unsigned int V_25 ;
int V_12 ;
V_15 = V_23 % 86400 ;
V_24 = V_23 / 86400 ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_8 ( V_6 -> V_7 , V_26 , & V_25 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
if ( V_25 < 86400 ) {
V_12 = F_13 ( V_6 -> V_7 ,
V_26 , 0x1ffff ) ;
if ( F_9 ( V_12 ) )
goto V_19;
}
V_12 = F_13 ( V_6 -> V_7 , V_21 , 0 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_13 ( V_6 -> V_7 , V_20 , V_24 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_13 ( V_6 -> V_7 , V_21 , V_15 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
if ( V_25 < 86400 ) {
V_12 = F_13 ( V_6 -> V_7 ,
V_26 , V_25 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
}
V_12 = F_14 ( V_6 -> V_7 , V_27 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = V_10 ( V_6 -> V_7 , V_27 ) ;
V_19:
V_6 -> V_8 = ! V_12 ;
F_6 ( V_6 -> V_7 ) ;
return V_12 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned V_15 , V_24 ;
unsigned long V_18 ;
int V_3 , V_30 ;
int V_12 ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_8 ( V_6 -> V_7 , V_26 , & V_15 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
if ( V_15 >= 86400 ) {
V_12 = - V_9 ;
goto V_19;
}
V_12 = F_8 ( V_6 -> V_7 , V_20 , & V_24 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_16 ( V_6 -> V_7 , V_31 ,
& V_3 , & V_30 ) ;
V_19:
F_6 ( V_6 -> V_7 ) ;
if ( V_12 )
return V_12 ;
V_29 -> V_3 = V_3 ;
V_29 -> V_30 = V_30 ;
V_18 = V_24 * 86400 + V_15 ;
F_10 ( V_18 , & V_29 -> time ) ;
F_17 ( V_2 , L_1 , V_32 , V_18 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_18 ;
unsigned V_15 , V_24 ;
int V_12 ;
F_5 ( V_6 -> V_7 ) ;
V_12 = F_13 ( V_6 -> V_7 , V_26 , 0x1ffff ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_14 ( V_6 -> V_7 , V_31 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_19 ( & V_29 -> time , & V_18 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
F_17 ( V_2 , L_2 , V_32 , V_29 -> V_3 ? L_3 : L_4 ,
V_18 ) ;
V_12 = F_1 ( V_2 , V_29 -> V_3 ,
V_31 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_15 = V_18 % 86400 ;
V_24 = V_18 / 86400 ;
V_12 = F_13 ( V_6 -> V_7 , V_33 , V_24 ) ;
if ( F_9 ( V_12 ) )
goto V_19;
V_12 = F_13 ( V_6 -> V_7 , V_26 , V_15 ) ;
V_19:
F_6 ( V_6 -> V_7 ) ;
return V_12 ;
}
static T_1 F_20 ( int V_4 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
struct V_7 * V_7 = V_6 -> V_7 ;
F_17 ( & V_6 -> V_34 -> V_2 , L_5 ) ;
F_21 ( V_6 -> V_34 , 1 , V_35 | V_36 ) ;
F_14 ( V_7 , V_4 ) ;
return V_37 ;
}
static T_1 F_22 ( int V_4 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
struct V_7 * V_7 = V_6 -> V_7 ;
F_17 ( & V_6 -> V_34 -> V_2 , L_6 ) ;
F_21 ( V_6 -> V_34 , 1 , V_35 | V_38 ) ;
F_14 ( V_7 , V_4 ) ;
return V_37 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_4 ( V_2 , V_3 , V_31 ) ;
}
static T_1 F_24 ( int V_4 , void * V_2 )
{
struct V_5 * V_6 = V_2 ;
struct V_7 * V_7 = V_6 -> V_7 ;
F_17 ( & V_6 -> V_34 -> V_2 , L_7 ) ;
V_6 -> V_8 = 0 ;
V_11 ( V_7 , V_4 ) ;
return V_37 ;
}
static int T_2 F_25 ( struct V_39 * V_40 )
{
int V_12 ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_41 ;
V_6 = F_26 ( & V_40 -> V_2 , sizeof( * V_6 ) , V_42 ) ;
if ( ! V_6 )
return - V_43 ;
V_7 = F_2 ( V_40 -> V_2 . V_44 ) ;
V_6 -> V_7 = V_7 ;
F_27 ( V_40 , V_6 ) ;
F_5 ( V_7 ) ;
V_12 = F_28 ( V_7 , V_27 ,
F_24 , V_45 , V_6 ) ;
if ( V_12 )
goto V_46;
V_12 = F_16 ( V_7 , V_27 ,
NULL , & V_41 ) ;
if ( V_12 )
goto V_47;
V_6 -> V_8 = ! V_41 ;
V_12 = F_29 ( V_7 , V_48 ,
F_22 , V_45 , V_6 ) ;
if ( V_12 )
goto V_49;
V_12 = F_29 ( V_7 , V_31 ,
F_20 , V_45 , V_6 ) ;
if ( V_12 )
goto V_50;
F_6 ( V_7 ) ;
V_6 -> V_34 = F_30 ( & V_40 -> V_2 , V_40 -> V_51 ,
& V_52 , V_53 ) ;
if ( F_31 ( V_6 -> V_34 ) ) {
V_12 = F_32 ( V_6 -> V_34 ) ;
F_5 ( V_7 ) ;
F_33 ( V_7 , V_31 , V_6 ) ;
V_50:
F_33 ( V_7 , V_48 , V_6 ) ;
V_49:
V_47:
F_33 ( V_7 , V_27 , V_6 ) ;
V_46:
F_6 ( V_7 ) ;
}
return V_12 ;
}
static int T_3 F_34 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_35 ( V_40 ) ;
F_5 ( V_6 -> V_7 ) ;
F_33 ( V_6 -> V_7 , V_31 , V_6 ) ;
F_33 ( V_6 -> V_7 , V_48 , V_6 ) ;
F_33 ( V_6 -> V_7 , V_27 , V_6 ) ;
F_6 ( V_6 -> V_7 ) ;
return 0 ;
}
