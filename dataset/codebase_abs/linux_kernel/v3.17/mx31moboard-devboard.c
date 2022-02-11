static int F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_4 ,
void * V_5 )
{
int V_6 ;
V_6 = F_4 ( V_7 , L_1 ) ;
if ( V_6 )
return V_6 ;
F_5 ( V_7 ) ;
V_6 = F_4 ( V_3 , L_2 ) ;
if ( V_6 )
goto V_8;
F_5 ( V_3 ) ;
V_6 = F_6 ( F_7 ( V_7 ) , V_4 ,
V_9 | V_10 ,
L_3 , V_5 ) ;
if ( V_6 )
goto V_11;
return 0 ;
V_11:
F_8 ( V_3 ) ;
V_8:
F_8 ( V_7 ) ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 , void * V_5 )
{
F_10 ( F_7 ( V_7 ) , V_5 ) ;
F_8 ( V_3 ) ;
F_8 ( V_7 ) ;
}
static void F_11 ( void )
{
if ( ! F_4 ( V_12 , L_4 ) ) {
F_5 ( V_12 ) ;
F_12 ( V_12 , true ) ;
}
if ( ! F_4 ( V_13 , L_5 ) ) {
F_5 ( V_13 ) ;
F_12 ( V_13 , true ) ;
}
if ( ! F_4 ( V_14 , L_6 ) ) {
F_5 ( V_14 ) ;
F_12 ( V_14 , true ) ;
}
if ( ! F_4 ( V_15 , L_7 ) ) {
F_5 ( V_15 ) ;
F_12 ( V_15 , true ) ;
}
}
static int F_13 ( struct V_16 * V_17 )
{
F_14 ( V_18 , true ) ;
F_15 ( V_19 , V_20 ) ;
F_15 ( V_21 , V_20 ) ;
F_15 ( V_22 , V_20 ) ;
F_15 ( V_23 , V_20 ) ;
F_15 ( V_24 , V_20 ) ;
F_15 ( V_25 , V_20 ) ;
F_15 ( V_26 , V_20 ) ;
F_15 ( V_27 , V_20 ) ;
F_16 ( 10 ) ;
return F_17 ( V_17 -> V_28 , V_29 |
V_30 ) ;
}
static int F_18 ( struct V_31 * V_32 )
{
int V_6 = F_4 ( V_33 , L_8 ) ;
if ( V_6 )
return V_6 ;
F_19 ( V_33 , 0 ) ;
V_6 = F_4 ( V_34 , L_9 ) ;
if ( V_6 ) {
F_8 ( V_33 ) ;
return V_6 ;
}
F_19 ( V_34 , 1 ) ;
return 0 ;
}
static int F_20 ( struct V_35 * V_32 , bool V_36 )
{
if ( V_36 )
F_21 ( V_34 , 0 ) ;
else
F_21 ( V_34 , 1 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
struct V_31 * V_37 ;
struct V_16 * V_17 ;
V_37 = F_23 ( sizeof( * V_37 ) , V_38 ) ;
if ( ! V_37 )
return - V_39 ;
V_37 -> V_32 = F_23 ( sizeof( struct V_35 ) , V_38 ) ;
if ( ! V_37 -> V_32 ) {
F_24 ( V_37 ) ;
return - V_39 ;
}
V_37 -> V_40 = L_10 ;
V_37 -> V_41 = F_18 ;
V_37 -> V_32 -> V_42 = F_20 ;
V_43 . V_32 = V_37 ;
V_17 = F_25 ( 1 , & V_43 ) ;
return F_26 ( V_17 ) ;
}
void T_2 F_27 ( void )
{
F_28 ( V_44 L_11 ) ;
F_29 ( V_45 , F_30 ( V_45 ) ,
L_12 ) ;
F_31 ( & V_46 ) ;
F_32 ( 1 , & V_47 ) ;
F_11 () ;
F_33 ( & V_48 ) ;
F_22 () ;
}
