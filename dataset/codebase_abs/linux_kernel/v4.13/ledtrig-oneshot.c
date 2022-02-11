static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
F_3 ( V_8 ,
& V_8 -> V_12 , & V_8 -> V_13 ,
V_10 -> V_14 ) ;
return V_6 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
return sprintf ( V_5 , L_1 , V_10 -> V_14 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_6 ( V_5 , 0 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_10 -> V_14 = ! ! V_15 ;
if ( V_10 -> V_14 )
F_7 ( V_8 , V_17 ) ;
else
F_7 ( V_8 , V_18 ) ;
return V_6 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_8 -> V_12 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_6 ( V_5 , 0 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_8 -> V_12 = V_15 ;
return V_6 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_8 -> V_13 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_6 ( V_5 , 0 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_8 -> V_13 = V_15 ;
return V_6 ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
int V_19 ;
V_10 = F_13 ( sizeof( * V_10 ) , V_20 ) ;
if ( ! V_10 )
return;
V_8 -> V_11 = V_10 ;
V_19 = F_14 ( V_8 -> V_2 , & V_21 ) ;
if ( V_19 )
goto V_22;
V_19 = F_14 ( V_8 -> V_2 , & V_23 ) ;
if ( V_19 )
goto V_24;
V_19 = F_14 ( V_8 -> V_2 , & V_25 ) ;
if ( V_19 )
goto V_26;
V_19 = F_14 ( V_8 -> V_2 , & V_27 ) ;
if ( V_19 )
goto V_28;
V_8 -> V_12 = V_29 ;
V_8 -> V_13 = V_29 ;
V_8 -> V_30 = true ;
return;
V_28:
F_15 ( V_8 -> V_2 , & V_25 ) ;
V_26:
F_15 ( V_8 -> V_2 , & V_23 ) ;
V_24:
F_15 ( V_8 -> V_2 , & V_21 ) ;
V_22:
F_16 ( V_8 -> V_11 ) ;
}
static void F_17 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
if ( V_8 -> V_30 ) {
F_15 ( V_8 -> V_2 , & V_21 ) ;
F_15 ( V_8 -> V_2 , & V_23 ) ;
F_15 ( V_8 -> V_2 , & V_25 ) ;
F_15 ( V_8 -> V_2 , & V_27 ) ;
F_16 ( V_10 ) ;
V_8 -> V_30 = false ;
}
F_18 ( V_8 , V_18 ) ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_31 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_31 ) ;
}
