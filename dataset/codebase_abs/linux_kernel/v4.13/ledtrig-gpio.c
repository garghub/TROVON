static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
if ( V_6 -> V_10 )
V_8 = ! V_8 ;
if ( V_8 ) {
if ( V_6 -> V_11 )
F_3 ( V_6 -> V_4 ,
V_6 -> V_11 ) ;
else
F_3 ( V_6 -> V_4 , V_12 ) ;
} else {
F_3 ( V_6 -> V_4 , V_13 ) ;
}
return V_14 ;
}
static T_2 F_4 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_3 * V_4 = F_5 ( V_16 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return sprintf ( V_19 , L_1 , V_6 -> V_11 ) ;
}
static T_2 F_6 ( struct V_15 * V_16 ,
struct V_17 * V_18 , const char * V_19 , T_3 V_20 )
{
struct V_3 * V_4 = F_5 ( V_16 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_11 ;
int V_21 ;
V_21 = sscanf ( V_19 , L_2 , & V_11 ) ;
if ( V_21 < 1 || V_11 > 255 ) {
F_7 ( V_16 , L_3 ) ;
return - V_22 ;
}
V_6 -> V_11 = V_11 ;
return V_20 ;
}
static T_2 F_8 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_3 * V_4 = F_5 ( V_16 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return sprintf ( V_19 , L_1 , V_6 -> V_10 ) ;
}
static T_2 F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 , const char * V_19 , T_3 V_20 )
{
struct V_3 * V_4 = F_5 ( V_16 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned long V_10 ;
int V_21 ;
V_21 = F_10 ( V_19 , 10 , & V_10 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_10 > 1 )
return - V_22 ;
V_6 -> V_10 = V_10 ;
F_1 ( 0 , V_4 ) ;
return V_20 ;
}
static T_2 F_11 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
struct V_3 * V_4 = F_5 ( V_16 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return sprintf ( V_19 , L_1 , V_6 -> V_9 ) ;
}
static T_2 F_12 ( struct V_15 * V_16 ,
struct V_17 * V_18 , const char * V_19 , T_3 V_20 )
{
struct V_3 * V_4 = F_5 ( V_16 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned V_9 ;
int V_21 ;
V_21 = sscanf ( V_19 , L_2 , & V_9 ) ;
if ( V_21 < 1 ) {
F_7 ( V_16 , L_4 ) ;
return - V_22 ;
}
if ( V_6 -> V_9 == V_9 )
return V_20 ;
if ( ! V_9 ) {
if ( V_6 -> V_9 != 0 )
F_13 ( F_14 ( V_6 -> V_9 ) , V_4 ) ;
V_6 -> V_9 = 0 ;
return V_20 ;
}
V_21 = F_15 ( F_14 ( V_9 ) , NULL , F_1 ,
V_23 | V_24 | V_25
| V_26 , L_5 , V_4 ) ;
if ( V_21 ) {
F_7 ( V_16 , L_6 , V_21 ) ;
} else {
if ( V_6 -> V_9 != 0 )
F_13 ( F_14 ( V_6 -> V_9 ) , V_4 ) ;
V_6 -> V_9 = V_9 ;
F_1 ( 0 , V_4 ) ;
}
return V_21 ? V_21 : V_20 ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_21 ;
V_6 = F_17 ( sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 )
return;
V_21 = F_18 ( V_4 -> V_16 , & V_28 ) ;
if ( V_21 )
goto V_29;
V_21 = F_18 ( V_4 -> V_16 , & V_30 ) ;
if ( V_21 )
goto V_31;
V_21 = F_18 ( V_4 -> V_16 , & V_32 ) ;
if ( V_21 )
goto V_33;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 = V_6 ;
V_4 -> V_34 = true ;
return;
V_33:
F_19 ( V_4 -> V_16 , & V_30 ) ;
V_31:
F_19 ( V_4 -> V_16 , & V_28 ) ;
V_29:
F_20 ( V_6 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_4 -> V_34 ) {
F_19 ( V_4 -> V_16 , & V_28 ) ;
F_19 ( V_4 -> V_16 , & V_30 ) ;
F_19 ( V_4 -> V_16 , & V_32 ) ;
if ( V_6 -> V_9 != 0 )
F_13 ( F_14 ( V_6 -> V_9 ) , V_4 ) ;
F_20 ( V_6 ) ;
V_4 -> V_34 = false ;
}
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_35 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_35 ) ;
}
