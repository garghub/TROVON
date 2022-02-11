static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_6 ;
V_5 -> V_7 = 0 ;
F_2 ( V_3 , V_5 -> V_8 ) ;
}
static T_1 F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_2 * V_3 = F_4 ( V_10 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
return sprintf ( V_13 , L_1 , V_5 -> V_7 ) ;
}
static T_1 F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_2 V_14 )
{
struct V_2 * V_3 = F_4 ( V_10 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_15 ;
T_1 V_16 ;
V_16 = F_6 ( V_13 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 != 1 && V_15 != 0 )
return - V_17 ;
if ( V_15 == 0 && V_5 -> V_7 == 1 ) {
F_7 ( & V_5 -> V_18 ) ;
V_5 -> V_7 = V_15 ;
F_2 ( V_3 ,
V_5 -> V_8 ) ;
return V_14 ;
}
if ( V_15 == 1 && V_5 -> V_7 == 0 &&
V_5 -> V_19 != 0 ) {
V_5 -> V_7 = V_15 ;
F_2 ( V_3 , V_5 -> V_15 ) ;
V_5 -> V_8 =
( V_5 -> V_15 == V_20 ) ? V_21 : V_20 ;
F_8 ( & V_5 -> V_18 ,
V_22 + V_5 -> V_19 ) ;
}
return V_14 ;
}
static T_1 F_9 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_2 * V_3 = F_4 ( V_10 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
return sprintf ( V_13 , L_2 , V_5 -> V_19 ) ;
}
static T_1 F_10 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_2 V_14 )
{
struct V_2 * V_3 = F_4 ( V_10 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_15 ;
T_1 V_16 ;
V_16 = F_6 ( V_13 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_5 -> V_19 = V_15 ;
return V_14 ;
}
static T_1 F_11 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_2 * V_3 = F_4 ( V_10 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
int V_15 ;
V_15 = ( V_5 -> V_15 == V_20 ) ? 1 : 0 ;
return sprintf ( V_13 , L_1 , V_15 ) ;
}
static T_1 F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_2 V_14 )
{
struct V_2 * V_3 = F_4 ( V_10 ) ;
struct V_4 * V_5 = V_3 -> V_6 ;
unsigned long V_15 ;
T_1 V_16 ;
V_16 = F_6 ( V_13 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 != 1 && V_15 != 0 )
return - V_17 ;
V_5 -> V_15 = ( V_15 == 1 ) ? V_20 : V_21 ;
return V_14 ;
}
static void F_13 ( struct V_2 * V_3 )
{
int V_23 ;
struct V_4 * V_24 ;
V_24 = F_14 ( sizeof( struct V_4 ) , V_25 ) ;
if ( ! V_24 ) {
F_15 ( V_3 -> V_10 ,
L_3 ) ;
return;
}
V_3 -> V_6 = V_24 ;
V_23 = F_16 ( V_3 -> V_10 , & V_26 ) ;
if ( V_23 )
goto V_27;
V_23 = F_16 ( V_3 -> V_10 , & V_28 ) ;
if ( V_23 )
goto V_29;
V_23 = F_16 ( V_3 -> V_10 , & V_30 ) ;
if ( V_23 )
goto V_31;
F_17 ( & V_24 -> V_18 , F_1 ,
( unsigned long ) V_3 ) ;
V_3 -> V_32 = true ;
return;
V_31:
F_18 ( V_3 -> V_10 , & V_28 ) ;
V_29:
F_18 ( V_3 -> V_10 , & V_26 ) ;
V_27:
F_15 ( V_3 -> V_10 , L_4 ) ;
V_3 -> V_6 = NULL ;
F_19 ( V_24 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 ;
if ( V_3 -> V_32 ) {
F_21 ( & V_5 -> V_18 ) ;
F_2 ( V_3 ,
V_5 -> V_8 ) ;
F_18 ( V_3 -> V_10 , & V_26 ) ;
F_18 ( V_3 -> V_10 , & V_28 ) ;
F_18 ( V_3 -> V_10 , & V_30 ) ;
V_3 -> V_6 = NULL ;
V_3 -> V_32 = false ;
F_19 ( V_5 ) ;
}
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_33 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_33 ) ;
}
