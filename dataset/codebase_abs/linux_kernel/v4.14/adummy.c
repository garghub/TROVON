static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_7 = F_2 ( V_2 , struct V_7 , V_8 ) ;
int signal ;
if ( sscanf ( V_5 , L_1 , & signal ) == 1 ) {
if ( signal < V_9 || signal > V_10 )
signal = V_11 ;
F_3 ( V_7 , signal ) ;
return 1 ;
}
return - V_12 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_7 = F_2 ( V_2 , struct V_7 , V_8 ) ;
return sprintf ( V_5 , L_2 , V_7 -> signal ) ;
}
static int T_3
F_5 ( struct V_7 * V_2 )
{
V_2 -> V_13 . V_14 = 4 ;
V_2 -> V_13 . V_15 = 12 ;
return 0 ;
}
static int
F_6 ( struct V_16 * V_17 )
{
short V_18 = V_17 -> V_18 ;
int V_19 = V_17 -> V_19 ;
if ( V_19 == V_20 || V_18 == V_21 )
return 0 ;
F_7 ( V_22 , & V_17 -> V_23 ) ;
F_7 ( V_24 , & V_17 -> V_23 ) ;
return 0 ;
}
static void
F_8 ( struct V_16 * V_17 )
{
F_9 ( V_24 , & V_17 -> V_23 ) ;
F_9 ( V_22 , & V_17 -> V_23 ) ;
}
static int
F_10 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
if ( V_17 -> V_27 )
V_17 -> V_27 ( V_17 , V_26 ) ;
else
F_11 ( V_26 ) ;
F_12 ( & V_17 -> V_28 -> V_29 ) ;
return 0 ;
}
static int
F_13 ( struct V_7 * V_2 , T_4 * V_30 , char * V_31 )
{
int V_32 = * V_30 ;
if ( ! V_32 -- )
return sprintf ( V_31 , L_3 , V_33 ) ;
return 0 ;
}
static int T_3 F_14 ( void )
{
struct V_7 * V_7 ;
struct V_34 * V_34 ;
int V_35 = 0 ;
F_15 ( V_36 L_4 , V_33 ) ;
V_34 = F_16 ( sizeof( struct V_34 ) ,
V_37 ) ;
if ( ! V_34 ) {
F_15 (KERN_ERR DEV_LABEL L_5 ) ;
V_35 = - V_38 ;
goto V_39;
}
V_7 = F_17 ( V_40 , NULL , & V_41 , - 1 , NULL ) ;
if ( ! V_7 ) {
F_15 (KERN_ERR DEV_LABEL L_6 ) ;
V_35 = - V_42 ;
goto V_43;
}
V_34 -> V_7 = V_7 ;
V_7 -> V_44 = V_34 ;
if ( F_18 ( & V_7 -> V_8 . V_45 , & V_46 ) )
F_19 ( & V_7 -> V_8 , L_7 ) ;
if ( F_5 ( V_7 ) ) {
F_15 (KERN_ERR DEV_LABEL L_8 ) ;
V_35 = - V_42 ;
goto V_47;
}
F_20 ( & V_34 -> V_48 , & V_49 ) ;
V_39:
return V_35 ;
V_47:
F_21 ( V_7 ) ;
V_43:
F_22 ( V_34 ) ;
goto V_39;
}
static void T_5 F_23 ( void )
{
struct V_34 * V_34 , * V_50 ;
F_24 (adummy_dev, next, &adummy_devs, entry) {
F_21 ( V_34 -> V_7 ) ;
F_22 ( V_34 ) ;
}
}
