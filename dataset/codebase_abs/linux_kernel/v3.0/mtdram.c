static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 + V_4 -> V_6 > V_2 -> V_7 )
return - V_8 ;
memset ( ( char * ) V_2 -> V_9 + V_4 -> V_5 , 0xff , V_4 -> V_6 ) ;
V_4 -> V_10 = V_11 ;
F_2 ( V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_6 ,
T_2 * V_13 , void * * V_14 , T_3 * V_15 )
{
if ( V_12 + V_6 > V_2 -> V_7 )
return - V_8 ;
if ( V_15 )
return - V_8 ;
* V_14 = V_2 -> V_9 + V_12 ;
* V_13 = V_6 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_6 )
{
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_6 ,
unsigned long V_16 ,
unsigned long V_17 )
{
return ( unsigned long ) V_2 -> V_9 + V_16 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_6 ,
T_2 * V_13 , T_4 * V_18 )
{
if ( V_12 + V_6 > V_2 -> V_7 )
return - V_8 ;
memcpy ( V_18 , V_2 -> V_9 + V_12 , V_6 ) ;
* V_13 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_19 , T_2 V_6 ,
T_2 * V_13 , const T_4 * V_18 )
{
if ( V_19 + V_6 > V_2 -> V_7 )
return - V_8 ;
memcpy ( ( char * ) V_2 -> V_9 + V_19 , V_18 , V_6 ) ;
* V_13 = V_6 ;
return 0 ;
}
static void T_5 F_8 ( void )
{
if ( V_1 ) {
F_9 ( V_1 ) ;
F_10 ( V_1 -> V_9 ) ;
F_11 ( V_1 ) ;
}
}
int F_12 ( struct V_1 * V_2 , void * V_20 ,
unsigned long V_7 , char * V_21 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_21 = V_21 ;
V_2 -> type = V_22 ;
V_2 -> V_17 = V_23 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_24 = 1 ;
V_2 -> V_25 = 64 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_9 = V_20 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = F_1 ;
V_2 -> V_31 = F_3 ;
V_2 -> V_32 = F_4 ;
V_2 -> V_33 = F_5 ;
V_2 -> V_34 = F_6 ;
V_2 -> V_35 = F_7 ;
if ( F_13 ( V_2 , NULL , 0 ) )
return - V_36 ;
return 0 ;
}
static int T_6 F_14 ( void )
{
void * V_5 ;
int V_37 ;
if ( ! V_38 )
return - V_8 ;
V_1 = F_15 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_1 )
return - V_40 ;
V_5 = F_16 ( V_41 ) ;
if ( ! V_5 ) {
F_11 ( V_1 ) ;
V_1 = NULL ;
return - V_40 ;
}
V_37 = F_12 ( V_1 , V_5 , V_41 , L_1 ) ;
if ( V_37 ) {
F_10 ( V_5 ) ;
F_11 ( V_1 ) ;
V_1 = NULL ;
return V_37 ;
}
memset ( V_1 -> V_9 , 0xff , V_41 ) ;
return V_37 ;
}
