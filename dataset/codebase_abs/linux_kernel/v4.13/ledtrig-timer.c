static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_9 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_10 ;
T_1 V_11 = - V_12 ;
V_11 = F_4 ( V_5 , 10 , & V_10 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_7 , & V_10 , & V_7 -> V_13 ) ;
V_7 -> V_8 = V_10 ;
return V_9 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_13 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_9 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned long V_10 ;
T_1 V_11 = - V_12 ;
V_11 = F_4 ( V_5 , 10 , & V_10 ) ;
if ( V_11 )
return V_11 ;
F_5 ( V_7 , & V_7 -> V_8 , & V_10 ) ;
V_7 -> V_13 = V_10 ;
return V_9 ;
}
static void F_8 ( struct V_6 * V_7 )
{
int V_14 ;
V_7 -> V_15 = NULL ;
V_14 = F_9 ( V_7 -> V_2 , & V_16 ) ;
if ( V_14 )
return;
V_14 = F_9 ( V_7 -> V_2 , & V_17 ) ;
if ( V_14 )
goto V_18;
F_5 ( V_7 , & V_7 -> V_8 ,
& V_7 -> V_13 ) ;
V_7 -> V_19 = true ;
return;
V_18:
F_10 ( V_7 -> V_2 , & V_16 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 ) {
F_10 ( V_7 -> V_2 , & V_16 ) ;
F_10 ( V_7 -> V_2 , & V_17 ) ;
V_7 -> V_19 = false ;
}
F_12 ( V_7 , V_20 ) ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_21 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_21 ) ;
}
