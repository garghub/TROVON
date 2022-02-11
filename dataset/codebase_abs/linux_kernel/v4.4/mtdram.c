static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = 0 ;
if ( F_2 ( V_3 , V_2 ) ) {
F_3 ( L_1 , V_6 ) ;
V_5 = - V_7 ;
}
if ( F_2 ( V_4 , V_2 ) ) {
F_3 ( L_2 , V_6 ) ;
V_5 = - V_7 ;
}
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( F_1 ( V_2 , V_9 -> V_10 , V_9 -> V_4 ) )
return - V_7 ;
memset ( ( char * ) V_2 -> V_11 + V_9 -> V_10 , 0xff , V_9 -> V_4 ) ;
V_9 -> V_12 = V_13 ;
F_5 ( V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_4 ,
T_3 * V_15 , void * * V_16 , T_4 * V_17 )
{
* V_16 = V_2 -> V_11 + V_14 ;
* V_15 = V_4 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_4 )
{
return 0 ;
}
static unsigned long F_8 ( struct V_1 * V_2 ,
unsigned long V_4 ,
unsigned long V_18 ,
unsigned long V_19 )
{
return ( unsigned long ) V_2 -> V_11 + V_18 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_14 , T_3 V_4 ,
T_3 * V_15 , T_5 * V_20 )
{
memcpy ( V_20 , V_2 -> V_11 + V_14 , V_4 ) ;
* V_15 = V_4 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_21 , T_3 V_4 ,
T_3 * V_15 , const T_5 * V_20 )
{
memcpy ( ( char * ) V_2 -> V_11 + V_21 , V_20 , V_4 ) ;
* V_15 = V_4 ;
return 0 ;
}
static void T_6 F_11 ( void )
{
if ( V_1 ) {
F_12 ( V_1 ) ;
F_13 ( V_1 -> V_11 ) ;
F_14 ( V_1 ) ;
}
}
int F_15 ( struct V_1 * V_2 , void * V_22 ,
unsigned long V_23 , const char * V_24 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_24 = V_24 ;
V_2 -> type = V_25 ;
V_2 -> V_19 = V_26 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_27 = 1 ;
V_2 -> V_28 = 64 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_11 = V_22 ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = F_4 ;
V_2 -> V_34 = F_6 ;
V_2 -> V_35 = F_7 ;
V_2 -> V_36 = F_8 ;
V_2 -> V_37 = F_9 ;
V_2 -> V_38 = F_10 ;
if ( F_16 ( V_2 , NULL , 0 ) )
return - V_39 ;
return 0 ;
}
static int T_7 F_17 ( void )
{
void * V_10 ;
int V_40 ;
if ( ! V_41 )
return - V_7 ;
V_1 = F_18 ( sizeof( struct V_1 ) , V_42 ) ;
if ( ! V_1 )
return - V_43 ;
V_10 = F_19 ( V_44 ) ;
if ( ! V_10 ) {
F_14 ( V_1 ) ;
V_1 = NULL ;
return - V_43 ;
}
V_40 = F_15 ( V_1 , V_10 , V_44 , L_3 ) ;
if ( V_40 ) {
F_13 ( V_10 ) ;
F_14 ( V_1 ) ;
V_1 = NULL ;
return V_40 ;
}
memset ( V_1 -> V_11 , 0xff , V_44 ) ;
return V_40 ;
}
