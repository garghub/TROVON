static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
struct V_4 * V_4 ;
void T_1 * V_5 ;
int V_6 ;
struct V_7 V_8 = V_9 ;
if ( ! F_2 ( V_3 , L_1 ) )
return F_3 ( - V_10 ) ;
V_1 = F_4 ( sizeof( * V_1 ) , V_11 ) ;
if ( ! V_1 )
return F_3 ( - V_12 ) ;
V_5 = F_5 ( V_3 , 0 ) ;
if ( ! V_5 ) {
V_6 = - V_12 ;
goto V_13;
}
if ( F_6 ( V_3 , L_2 ) )
V_8 . V_14 = V_15 ;
else if ( F_6 ( V_3 , L_3 ) )
V_8 . V_14 = V_16 ;
V_4 = F_7 ( NULL , V_5 , & V_8 ) ;
if ( F_8 ( V_4 ) ) {
F_9 ( L_4 ) ;
V_6 = F_10 ( V_4 ) ;
goto V_17;
}
V_1 -> V_4 = V_4 ;
V_1 -> V_3 = V_3 ;
F_11 ( & V_18 ) ;
F_12 ( & V_1 -> V_19 , & V_20 ) ;
F_13 ( & V_18 ) ;
return V_1 ;
V_17:
F_14 ( V_5 ) ;
V_13:
F_15 ( V_1 ) ;
return F_3 ( V_6 ) ;
}
struct V_4 * F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_21 , * V_1 = NULL ;
F_11 ( & V_18 ) ;
F_17 (entry, &syscon_list, list)
if ( V_21 -> V_3 == V_3 ) {
V_1 = V_21 ;
break;
}
F_13 ( & V_18 ) ;
if ( ! V_1 )
V_1 = F_1 ( V_3 ) ;
if ( F_8 ( V_1 ) )
return F_18 ( V_1 ) ;
return V_1 -> V_4 ;
}
struct V_4 * F_19 ( const char * V_22 )
{
struct V_2 * V_23 ;
struct V_4 * V_4 ;
V_23 = F_20 ( NULL , NULL , V_22 ) ;
if ( ! V_23 )
return F_3 ( - V_24 ) ;
V_4 = F_16 ( V_23 ) ;
F_21 ( V_23 ) ;
return V_4 ;
}
static int F_22 ( struct V_25 * V_26 , void * V_27 )
{
return ! strcmp ( F_23 ( V_26 ) , ( const char * ) V_27 ) ;
}
struct V_4 * F_24 ( const char * V_22 )
{
struct V_25 * V_26 ;
struct V_1 * V_1 ;
V_26 = F_25 ( & V_28 . V_29 , NULL , ( void * ) V_22 ,
F_22 ) ;
if ( ! V_26 )
return F_3 ( - V_30 ) ;
V_1 = F_26 ( V_26 ) ;
return V_1 -> V_4 ;
}
struct V_4 * F_27 ( struct V_2 * V_3 ,
const char * V_31 )
{
struct V_2 * V_23 ;
struct V_4 * V_4 ;
if ( V_31 )
V_23 = F_28 ( V_3 , V_31 , 0 ) ;
else
V_23 = V_3 ;
if ( ! V_23 )
return F_3 ( - V_24 ) ;
V_4 = F_16 ( V_23 ) ;
F_21 ( V_23 ) ;
return V_4 ;
}
static int F_29 ( struct V_32 * V_33 )
{
struct V_25 * V_26 = & V_33 -> V_26 ;
struct V_34 * V_35 = F_30 ( V_26 ) ;
struct V_1 * V_1 ;
struct V_36 * V_37 ;
void T_1 * V_5 ;
V_1 = F_31 ( V_26 , sizeof( * V_1 ) , V_11 ) ;
if ( ! V_1 )
return - V_12 ;
V_37 = F_32 ( V_33 , V_38 , 0 ) ;
if ( ! V_37 )
return - V_39 ;
V_5 = F_33 ( V_26 , V_37 -> V_40 , F_34 ( V_37 ) ) ;
if ( ! V_5 )
return - V_12 ;
V_9 . V_41 = V_37 -> V_42 - V_37 -> V_40 - 3 ;
if ( V_35 )
V_9 . V_43 = V_35 -> V_44 ;
V_1 -> V_4 = F_35 ( V_26 , V_5 ,
& V_9 ) ;
if ( F_8 ( V_1 -> V_4 ) ) {
F_36 ( V_26 , L_4 ) ;
return F_10 ( V_1 -> V_4 ) ;
}
F_37 ( V_33 , V_1 ) ;
F_38 ( V_26 , L_5 , V_37 ) ;
return 0 ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_28 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_28 ) ;
}
