static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_1 ;
struct V_4 * V_4 ;
void T_1 * V_5 ;
T_2 V_6 ;
int V_7 ;
struct V_8 V_9 = V_10 ;
struct V_11 V_12 ;
if ( ! F_2 ( V_3 , L_1 ) )
return F_3 ( - V_13 ) ;
V_1 = F_4 ( sizeof( * V_1 ) , V_14 ) ;
if ( ! V_1 )
return F_3 ( - V_15 ) ;
if ( F_5 ( V_3 , 0 , & V_12 ) ) {
V_7 = - V_15 ;
goto V_16;
}
V_5 = F_6 ( V_12 . V_17 , F_7 ( & V_12 ) ) ;
if ( ! V_5 ) {
V_7 = - V_15 ;
goto V_16;
}
if ( F_8 ( V_3 , L_2 ) )
V_9 . V_18 = V_19 ;
else if ( F_8 ( V_3 , L_3 ) )
V_9 . V_18 = V_20 ;
V_7 = F_9 ( V_3 , L_4 , & V_6 ) ;
if ( V_7 )
V_6 = 4 ;
V_9 . V_21 = V_6 ;
V_9 . V_22 = V_6 * 8 ;
V_9 . V_23 = F_7 ( & V_12 ) - V_6 ;
V_4 = F_10 ( NULL , V_5 , & V_9 ) ;
if ( F_11 ( V_4 ) ) {
F_12 ( L_5 ) ;
V_7 = F_13 ( V_4 ) ;
goto V_24;
}
V_1 -> V_4 = V_4 ;
V_1 -> V_3 = V_3 ;
F_14 ( & V_25 ) ;
F_15 ( & V_1 -> V_26 , & V_27 ) ;
F_16 ( & V_25 ) ;
return V_1 ;
V_24:
F_17 ( V_5 ) ;
V_16:
F_18 ( V_1 ) ;
return F_3 ( V_7 ) ;
}
struct V_4 * F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_28 , * V_1 = NULL ;
F_14 ( & V_25 ) ;
F_20 (entry, &syscon_list, list)
if ( V_28 -> V_3 == V_3 ) {
V_1 = V_28 ;
break;
}
F_16 ( & V_25 ) ;
if ( ! V_1 )
V_1 = F_1 ( V_3 ) ;
if ( F_11 ( V_1 ) )
return F_21 ( V_1 ) ;
return V_1 -> V_4 ;
}
struct V_4 * F_22 ( const char * V_29 )
{
struct V_2 * V_30 ;
struct V_4 * V_4 ;
V_30 = F_23 ( NULL , NULL , V_29 ) ;
if ( ! V_30 )
return F_3 ( - V_31 ) ;
V_4 = F_19 ( V_30 ) ;
F_24 ( V_30 ) ;
return V_4 ;
}
static int F_25 ( struct V_32 * V_33 , void * V_34 )
{
return ! strcmp ( F_26 ( V_33 ) , ( const char * ) V_34 ) ;
}
struct V_4 * F_27 ( const char * V_29 )
{
struct V_32 * V_33 ;
struct V_1 * V_1 ;
V_33 = F_28 ( & V_35 . V_36 , NULL , ( void * ) V_29 ,
F_25 ) ;
if ( ! V_33 )
return F_3 ( - V_37 ) ;
V_1 = F_29 ( V_33 ) ;
return V_1 -> V_4 ;
}
struct V_4 * F_30 ( struct V_2 * V_3 ,
const char * V_38 )
{
struct V_2 * V_30 ;
struct V_4 * V_4 ;
if ( V_38 )
V_30 = F_31 ( V_3 , V_38 , 0 ) ;
else
V_30 = V_3 ;
if ( ! V_30 )
return F_3 ( - V_31 ) ;
V_4 = F_19 ( V_30 ) ;
F_24 ( V_30 ) ;
return V_4 ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_32 * V_33 = & V_40 -> V_33 ;
struct V_41 * V_42 = F_33 ( V_33 ) ;
struct V_1 * V_1 ;
struct V_8 V_9 = V_10 ;
struct V_11 * V_12 ;
void T_1 * V_5 ;
V_1 = F_34 ( V_33 , sizeof( * V_1 ) , V_14 ) ;
if ( ! V_1 )
return - V_15 ;
V_12 = F_35 ( V_40 , V_43 , 0 ) ;
if ( ! V_12 )
return - V_44 ;
V_5 = F_36 ( V_33 , V_12 -> V_17 , F_7 ( V_12 ) ) ;
if ( ! V_5 )
return - V_15 ;
V_9 . V_23 = V_12 -> V_45 - V_12 -> V_17 - 3 ;
if ( V_42 )
V_9 . V_46 = V_42 -> V_47 ;
V_1 -> V_4 = F_37 ( V_33 , V_5 , & V_9 ) ;
if ( F_11 ( V_1 -> V_4 ) ) {
F_38 ( V_33 , L_5 ) ;
return F_13 ( V_1 -> V_4 ) ;
}
F_39 ( V_40 , V_1 ) ;
F_40 ( V_33 , L_6 , V_12 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
return F_42 ( & V_35 ) ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_35 ) ;
}
