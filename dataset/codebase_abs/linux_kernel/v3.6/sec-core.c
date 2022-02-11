int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_6 , T_1 * V_7 )
{
return F_4 ( V_2 -> V_5 , V_3 , V_7 , V_6 ) ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
return F_6 ( V_2 -> V_5 , V_3 , V_8 ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_6 , T_1 * V_7 )
{
return F_8 ( V_2 -> V_5 , V_3 , V_7 , V_6 ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 , T_1 V_10 )
{
return F_10 ( V_2 -> V_5 , V_3 , V_10 , V_9 ) ;
}
static int F_11 ( struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = V_12 -> V_17 . V_18 ;
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_12 ( & V_12 -> V_17 , sizeof( struct V_1 ) ,
V_20 ) ;
if ( V_2 == NULL )
return - V_21 ;
F_13 ( V_12 , V_2 ) ;
V_2 -> V_17 = & V_12 -> V_17 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_22 = V_12 -> V_22 ;
V_2 -> type = V_14 -> V_23 ;
if ( V_16 ) {
V_2 -> V_24 = V_16 -> V_24 ;
V_2 -> V_25 = V_16 -> V_25 ;
V_2 -> V_26 = V_16 -> V_26 ;
V_2 -> V_27 = V_16 -> V_27 ;
}
V_2 -> V_5 = F_14 ( V_12 , & V_28 ) ;
if ( F_15 ( V_2 -> V_5 ) ) {
V_19 = F_16 ( V_2 -> V_5 ) ;
F_17 ( & V_12 -> V_17 , L_1 ,
V_19 ) ;
return V_19 ;
}
V_2 -> V_29 = F_18 ( V_12 -> V_30 , V_31 ) ;
F_13 ( V_2 -> V_29 , V_2 ) ;
if ( V_16 && V_16 -> V_32 )
V_16 -> V_32 () ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_17 ) ;
switch ( V_2 -> V_24 ) {
case V_33 :
V_19 = F_21 ( V_2 -> V_17 , - 1 , V_34 ,
F_22 ( V_34 ) , NULL , 0 , NULL ) ;
break;
case V_35 :
V_19 = F_21 ( V_2 -> V_17 , - 1 , V_36 ,
F_22 ( V_36 ) , NULL , 0 , NULL ) ;
break;
case V_37 :
V_19 = F_21 ( V_2 -> V_17 , - 1 , V_38 ,
F_22 ( V_38 ) , NULL , 0 , NULL ) ;
break;
case V_39 :
V_19 = F_21 ( V_2 -> V_17 , - 1 , V_40 ,
F_22 ( V_40 ) , NULL , 0 , NULL ) ;
break;
default:
F_23 () ;
}
if ( V_19 < 0 )
goto V_41;
return V_19 ;
V_41:
F_24 ( V_2 -> V_17 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_29 ) ;
return V_19 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_28 ( V_12 ) ;
F_24 ( V_2 -> V_17 ) ;
F_25 ( V_2 ) ;
F_26 ( V_2 -> V_29 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_42 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_42 ) ;
}
