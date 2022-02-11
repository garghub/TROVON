static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
struct V_4 * V_4 ;
void T_1 * V_5 ;
T_2 V_6 ;
int V_7 ;
struct V_8 V_9 = V_10 ;
if ( ! F_2 ( V_3 , L_1 ) )
return F_3 ( - V_11 ) ;
V_1 = F_4 ( sizeof( * V_1 ) , V_12 ) ;
if ( ! V_1 )
return F_3 ( - V_13 ) ;
V_5 = F_5 ( V_3 , 0 ) ;
if ( ! V_5 ) {
V_7 = - V_13 ;
goto V_14;
}
if ( F_6 ( V_3 , L_2 ) )
V_9 . V_15 = V_16 ;
else if ( F_6 ( V_3 , L_3 ) )
V_9 . V_15 = V_17 ;
V_7 = F_7 ( V_3 , L_4 , & V_6 ) ;
if ( V_7 )
V_6 = 4 ;
V_9 . V_18 = V_6 ;
V_9 . V_19 = V_6 * 8 ;
V_4 = F_8 ( NULL , V_5 , & V_9 ) ;
if ( F_9 ( V_4 ) ) {
F_10 ( L_5 ) ;
V_7 = F_11 ( V_4 ) ;
goto V_20;
}
V_1 -> V_4 = V_4 ;
V_1 -> V_3 = V_3 ;
F_12 ( & V_21 ) ;
F_13 ( & V_1 -> V_22 , & V_23 ) ;
F_14 ( & V_21 ) ;
return V_1 ;
V_20:
F_15 ( V_5 ) ;
V_14:
F_16 ( V_1 ) ;
return F_3 ( V_7 ) ;
}
struct V_4 * F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_24 , * V_1 = NULL ;
F_12 ( & V_21 ) ;
F_18 (entry, &syscon_list, list)
if ( V_24 -> V_3 == V_3 ) {
V_1 = V_24 ;
break;
}
F_14 ( & V_21 ) ;
if ( ! V_1 )
V_1 = F_1 ( V_3 ) ;
if ( F_9 ( V_1 ) )
return F_19 ( V_1 ) ;
return V_1 -> V_4 ;
}
struct V_4 * F_20 ( const char * V_25 )
{
struct V_2 * V_26 ;
struct V_4 * V_4 ;
V_26 = F_21 ( NULL , NULL , V_25 ) ;
if ( ! V_26 )
return F_3 ( - V_27 ) ;
V_4 = F_17 ( V_26 ) ;
F_22 ( V_26 ) ;
return V_4 ;
}
static int F_23 ( struct V_28 * V_29 , void * V_30 )
{
return ! strcmp ( F_24 ( V_29 ) , ( const char * ) V_30 ) ;
}
struct V_4 * F_25 ( const char * V_25 )
{
struct V_28 * V_29 ;
struct V_1 * V_1 ;
V_29 = F_26 ( & V_31 . V_32 , NULL , ( void * ) V_25 ,
F_23 ) ;
if ( ! V_29 )
return F_3 ( - V_33 ) ;
V_1 = F_27 ( V_29 ) ;
return V_1 -> V_4 ;
}
struct V_4 * F_28 ( struct V_2 * V_3 ,
const char * V_34 )
{
struct V_2 * V_26 ;
struct V_4 * V_4 ;
if ( V_34 )
V_26 = F_29 ( V_3 , V_34 , 0 ) ;
else
V_26 = V_3 ;
if ( ! V_26 )
return F_3 ( - V_27 ) ;
V_4 = F_17 ( V_26 ) ;
F_22 ( V_26 ) ;
return V_4 ;
}
static int F_30 ( struct V_35 * V_36 )
{
struct V_28 * V_29 = & V_36 -> V_29 ;
struct V_37 * V_38 = F_31 ( V_29 ) ;
struct V_1 * V_1 ;
struct V_39 * V_40 ;
void T_1 * V_5 ;
V_1 = F_32 ( V_29 , sizeof( * V_1 ) , V_12 ) ;
if ( ! V_1 )
return - V_13 ;
V_40 = F_33 ( V_36 , V_41 , 0 ) ;
if ( ! V_40 )
return - V_42 ;
V_5 = F_34 ( V_29 , V_40 -> V_43 , F_35 ( V_40 ) ) ;
if ( ! V_5 )
return - V_13 ;
V_10 . V_44 = V_40 -> V_45 - V_40 -> V_43 - 3 ;
if ( V_38 )
V_10 . V_46 = V_38 -> V_47 ;
V_1 -> V_4 = F_36 ( V_29 , V_5 ,
& V_10 ) ;
if ( F_9 ( V_1 -> V_4 ) ) {
F_37 ( V_29 , L_5 ) ;
return F_11 ( V_1 -> V_4 ) ;
}
F_38 ( V_36 , V_1 ) ;
F_39 ( V_29 , L_6 , V_40 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_31 ) ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_31 ) ;
}
