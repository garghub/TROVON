static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_7 ) ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_10 = V_4 ;
int * V_11 ;
int V_12 ;
if ( V_3 != V_13 )
return 0 ;
V_11 = V_10 -> V_4 ;
V_12 = * V_11 ? V_14 : V_15 ;
if ( V_12 == V_6 -> V_16 )
return 0 ;
if ( ( V_6 -> V_16 == V_15 ) ^ V_6 -> V_17 ) {
V_6 -> V_18 = V_9 -> V_18 ;
F_3 ( V_9 , V_19 ) ;
} else {
F_3 ( V_9 , V_6 -> V_18 ) ;
}
V_6 -> V_16 = V_12 ;
return 0 ;
}
static T_1 F_4 ( struct V_20 * V_21 ,
struct V_22 * V_23 , char * V_24 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
struct V_5 * V_6 = V_9 -> V_25 ;
return sprintf ( V_24 , L_1 , V_6 -> V_17 ) ;
}
static T_1 F_6 ( struct V_20 * V_21 ,
struct V_22 * V_23 , const char * V_24 , T_2 V_26 )
{
struct V_8 * V_9 = F_5 ( V_21 ) ;
struct V_5 * V_6 = V_9 -> V_25 ;
unsigned long V_17 ;
int V_27 ;
V_27 = F_7 ( V_24 , 10 , & V_17 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( V_17 > 1 )
return - V_28 ;
V_6 -> V_17 = V_17 ;
if ( ( V_6 -> V_16 == V_14 ) ^ V_6 -> V_17 )
F_3 ( V_9 , V_19 ) ;
else
F_3 ( V_9 , V_6 -> V_18 ) ;
return V_26 ;
}
static void F_8 ( struct V_8 * V_9 )
{
int V_27 ;
struct V_5 * V_6 ;
V_6 = F_9 ( sizeof( struct V_5 ) , V_29 ) ;
V_9 -> V_25 = V_6 ;
if ( ! V_6 ) {
F_10 ( V_9 -> V_21 , L_2 ) ;
return;
}
V_27 = F_11 ( V_9 -> V_21 , & V_30 ) ;
if ( V_27 )
goto V_31;
V_6 -> V_9 = V_9 ;
V_6 -> V_18 = V_9 -> V_18 ;
V_6 -> V_16 = V_15 ;
V_6 -> V_7 . V_32 = F_1 ;
V_27 = F_12 ( & V_6 -> V_7 ) ;
if ( V_27 )
F_10 ( V_9 -> V_21 , L_3 ) ;
V_9 -> V_33 = true ;
return;
V_31:
V_9 -> V_25 = NULL ;
F_13 ( V_6 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_9 -> V_25 ;
if ( V_9 -> V_33 ) {
F_15 ( V_9 -> V_21 , & V_30 ) ;
F_16 ( & V_6 -> V_7 ) ;
F_13 ( V_6 ) ;
V_9 -> V_33 = false ;
}
}
static int T_3 F_17 ( void )
{
return F_18 ( & V_34 ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_34 ) ;
}
