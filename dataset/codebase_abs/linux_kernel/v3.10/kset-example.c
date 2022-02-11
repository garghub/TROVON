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
sscanf ( V_5 , L_2 , & V_7 -> V_8 ) ;
return V_13 ;
}
static T_1 F_9 ( struct V_7 * V_7 , struct V_6 * V_4 ,
char * V_5 )
{
int V_14 ;
if ( strcmp ( V_4 -> V_4 . V_15 , L_3 ) == 0 )
V_14 = V_7 -> V_16 ;
else
V_14 = V_7 -> V_17 ;
return sprintf ( V_5 , L_1 , V_14 ) ;
}
static T_1 F_10 ( struct V_7 * V_7 , struct V_6 * V_4 ,
const char * V_5 , T_2 V_13 )
{
int V_14 ;
sscanf ( V_5 , L_2 , & V_14 ) ;
if ( strcmp ( V_4 -> V_4 . V_15 , L_3 ) == 0 )
V_7 -> V_16 = V_14 ;
else
V_7 -> V_17 = V_14 ;
return V_13 ;
}
static struct V_7 * F_11 ( const char * V_15 )
{
struct V_7 * V_8 ;
int V_18 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_2 . V_20 = V_21 ;
V_18 = F_13 ( & V_8 -> V_2 , & V_22 , NULL , L_4 , V_15 ) ;
if ( V_18 ) {
F_14 ( & V_8 -> V_2 ) ;
return NULL ;
}
F_15 ( & V_8 -> V_2 , V_23 ) ;
return V_8 ;
}
static void F_16 ( struct V_7 * V_8 )
{
F_14 ( & V_8 -> V_2 ) ;
}
static int T_3 F_17 ( void )
{
V_21 = F_18 ( L_5 , NULL , V_24 ) ;
if ( ! V_21 )
return - V_25 ;
V_7 = F_11 ( L_6 ) ;
if ( ! V_7 )
goto V_26;
V_27 = F_11 ( L_7 ) ;
if ( ! V_27 )
goto V_28;
V_29 = F_11 ( L_3 ) ;
if ( ! V_29 )
goto V_30;
return 0 ;
V_30:
F_16 ( V_27 ) ;
V_28:
F_16 ( V_7 ) ;
V_26:
return - V_31 ;
}
static void T_4 F_19 ( void )
{
F_16 ( V_29 ) ;
F_16 ( V_27 ) ;
F_16 ( V_7 ) ;
F_20 ( V_21 ) ;
}
