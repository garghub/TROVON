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
int V_10 = - V_11 ;
char * V_12 ;
unsigned long V_13 = F_4 ( V_5 , & V_12 , 10 ) ;
T_2 V_14 = V_12 - V_5 ;
if ( isspace ( * V_12 ) )
V_14 ++ ;
if ( V_14 == V_9 ) {
F_5 ( V_7 , & V_13 , & V_7 -> V_15 ) ;
V_10 = V_14 ;
}
return V_10 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_15 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_9 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 = - V_11 ;
char * V_12 ;
unsigned long V_13 = F_4 ( V_5 , & V_12 , 10 ) ;
T_2 V_14 = V_12 - V_5 ;
if ( isspace ( * V_12 ) )
V_14 ++ ;
if ( V_14 == V_9 ) {
F_5 ( V_7 , & V_7 -> V_8 , & V_13 ) ;
V_10 = V_14 ;
}
return V_10 ;
}
static void F_8 ( struct V_6 * V_7 )
{
int V_16 ;
V_7 -> V_17 = NULL ;
V_16 = F_9 ( V_7 -> V_2 , & V_18 ) ;
if ( V_16 )
return;
V_16 = F_9 ( V_7 -> V_2 , & V_19 ) ;
if ( V_16 )
goto V_20;
F_5 ( V_7 , & V_7 -> V_8 ,
& V_7 -> V_15 ) ;
V_7 -> V_17 = ( void * ) 1 ;
return;
V_20:
F_10 ( V_7 -> V_2 , & V_18 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
if ( V_7 -> V_17 ) {
F_10 ( V_7 -> V_2 , & V_18 ) ;
F_10 ( V_7 -> V_2 , & V_19 ) ;
}
F_12 ( V_7 , V_21 ) ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_22 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_22 ) ;
}
