static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_3 ;
struct V_7 * V_8 ;
V_3 = F_2 ( V_4 ) ;
V_8 = F_3 ( V_2 ) ;
if ( ! V_3 -> V_9 )
return - V_10 ;
return V_3 -> V_9 ( V_8 , V_3 , V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_11 )
{
struct V_6 * V_3 ;
struct V_7 * V_8 ;
V_3 = F_2 ( V_4 ) ;
V_8 = F_3 ( V_2 ) ;
if ( ! V_3 -> V_12 )
return - V_10 ;
return V_3 -> V_12 ( V_8 , V_3 , V_5 , V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = F_3 ( V_2 ) ;
F_6 ( V_8 ) ;
}
static T_1 F_7 ( struct V_7 * V_7 , struct V_6 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_8 ( struct V_7 * V_7 , struct V_6 * V_4 ,
const char * V_5 , T_2 V_13 )
{
int V_14 ;
V_14 = F_9 ( V_5 , 10 , & V_7 -> V_8 ) ;
if ( V_14 < 0 )
return V_14 ;
return V_13 ;
}
static T_1 F_10 ( struct V_7 * V_7 , struct V_6 * V_4 ,
char * V_5 )
{
int V_15 ;
if ( strcmp ( V_4 -> V_4 . V_16 , L_2 ) == 0 )
V_15 = V_7 -> V_17 ;
else
V_15 = V_7 -> V_18 ;
return sprintf ( V_5 , L_1 , V_15 ) ;
}
static T_1 F_11 ( struct V_7 * V_7 , struct V_6 * V_4 ,
const char * V_5 , T_2 V_13 )
{
int V_15 , V_14 ;
V_14 = F_9 ( V_5 , 10 , & V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( strcmp ( V_4 -> V_4 . V_16 , L_2 ) == 0 )
V_7 -> V_17 = V_15 ;
else
V_7 -> V_18 = V_15 ;
return V_13 ;
}
static struct V_7 * F_12 ( const char * V_16 )
{
struct V_7 * V_8 ;
int V_19 ;
V_8 = F_13 ( sizeof( * V_8 ) , V_20 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_2 . V_21 = V_22 ;
V_19 = F_14 ( & V_8 -> V_2 , & V_23 , NULL , L_3 , V_16 ) ;
if ( V_19 ) {
F_15 ( & V_8 -> V_2 ) ;
return NULL ;
}
F_16 ( & V_8 -> V_2 , V_24 ) ;
return V_8 ;
}
static void F_17 ( struct V_7 * V_8 )
{
F_15 ( & V_8 -> V_2 ) ;
}
static int T_3 F_18 ( void )
{
V_22 = F_19 ( L_4 , NULL , V_25 ) ;
if ( ! V_22 )
return - V_26 ;
V_7 = F_12 ( L_5 ) ;
if ( ! V_7 )
goto V_27;
V_28 = F_12 ( L_6 ) ;
if ( ! V_28 )
goto V_29;
V_30 = F_12 ( L_2 ) ;
if ( ! V_30 )
goto V_31;
return 0 ;
V_31:
F_17 ( V_28 ) ;
V_29:
F_17 ( V_7 ) ;
V_27:
F_20 ( V_22 ) ;
return - V_32 ;
}
static void T_4 F_21 ( void )
{
F_17 ( V_30 ) ;
F_17 ( V_28 ) ;
F_17 ( V_7 ) ;
F_20 ( V_22 ) ;
}
