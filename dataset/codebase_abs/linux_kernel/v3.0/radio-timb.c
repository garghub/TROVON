static int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , L_1 , sizeof( V_4 -> V_7 ) ) ;
snprintf ( V_4 -> V_8 , sizeof( V_4 -> V_8 ) , L_2 V_6 ) ;
V_4 -> V_9 = F_3 ( 0 , 0 , 1 ) ;
V_4 -> V_10 = V_11 | V_12 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , void * V_2 ,
struct V_13 * V_4 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
return F_6 ( V_15 -> V_16 , V_17 , V_18 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_1 , void * V_2 ,
struct V_13 * V_4 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
return F_6 ( V_15 -> V_16 , V_17 , V_19 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_20 , void * V_2 ,
unsigned int * V_21 )
{
* V_21 = 0 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_20 , void * V_2 ,
unsigned int V_21 )
{
return V_21 ? - V_22 : 0 ;
}
static int F_10 ( struct V_1 * V_1 , void * V_2 ,
struct V_23 * V_24 )
{
V_24 -> V_25 = 0 ;
F_2 ( V_24 -> V_26 , L_3 , sizeof( V_24 -> V_26 ) ) ;
V_24 -> V_27 = V_28 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , void * V_2 ,
struct V_23 * V_24 )
{
return V_24 -> V_25 ? - V_22 : 0 ;
}
static int F_12 ( struct V_1 * V_1 , void * V_2 ,
struct V_29 * V_30 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
return F_6 ( V_15 -> V_16 , V_17 , V_31 , V_30 ) ;
}
static int F_13 ( struct V_1 * V_1 , void * V_2 ,
struct V_29 * V_30 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
return F_6 ( V_15 -> V_16 , V_17 , V_32 , V_30 ) ;
}
static int F_14 ( struct V_1 * V_1 , void * V_2 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
return F_6 ( V_15 -> V_35 , V_36 , V_37 , V_34 ) ;
}
static int F_15 ( struct V_1 * V_1 , void * V_2 ,
struct V_38 * V_39 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
return F_6 ( V_15 -> V_35 , V_36 , V_40 , V_39 ) ;
}
static int F_16 ( struct V_1 * V_1 , void * V_2 ,
struct V_38 * V_39 )
{
struct V_14 * V_15 = F_5 ( V_1 ) ;
return F_6 ( V_15 -> V_35 , V_36 , V_41 , V_39 ) ;
}
static int T_1 F_17 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 . V_47 ;
struct V_14 * V_15 ;
int V_48 ;
if ( ! V_45 ) {
F_18 ( & V_43 -> V_46 , L_4 ) ;
V_48 = - V_22 ;
goto V_48;
}
V_15 = F_19 ( sizeof( * V_15 ) , V_49 ) ;
if ( ! V_15 ) {
V_48 = - V_50 ;
goto V_48;
}
V_15 -> V_45 = * V_45 ;
F_20 ( & V_15 -> V_51 ) ;
F_2 ( V_15 -> V_52 . V_26 , L_1 ,
sizeof( V_15 -> V_52 . V_26 ) ) ;
V_15 -> V_52 . V_53 = & V_54 ;
V_15 -> V_52 . V_55 = & V_56 ;
V_15 -> V_52 . V_57 = V_58 ;
V_15 -> V_52 . V_59 = - 1 ;
V_15 -> V_52 . V_51 = & V_15 -> V_51 ;
F_2 ( V_15 -> V_60 . V_26 , V_6 , sizeof( V_15 -> V_60 . V_26 ) ) ;
V_48 = F_21 ( NULL , & V_15 -> V_60 ) ;
if ( V_48 )
goto V_61;
V_15 -> V_52 . V_60 = & V_15 -> V_60 ;
V_48 = F_22 ( & V_15 -> V_52 , V_62 , - 1 ) ;
if ( V_48 ) {
F_18 ( & V_43 -> V_46 , L_5 ) ;
goto V_63;
}
F_23 ( & V_15 -> V_52 , V_15 ) ;
F_24 ( V_43 , V_15 ) ;
return 0 ;
V_63:
V_58 ( & V_15 -> V_52 ) ;
F_25 ( & V_15 -> V_60 ) ;
V_61:
F_26 ( V_15 ) ;
V_48:
F_18 ( & V_43 -> V_46 , L_6 , V_48 ) ;
return V_48 ;
}
static int T_2 F_27 ( struct V_42 * V_43 )
{
struct V_14 * V_15 = F_28 ( V_43 ) ;
F_29 ( & V_15 -> V_52 ) ;
V_58 ( & V_15 -> V_52 ) ;
F_25 ( & V_15 -> V_60 ) ;
F_26 ( V_15 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_64 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_64 ) ;
}
