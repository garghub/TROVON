static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
memset ( ( char * ) V_2 -> V_5 + V_4 -> V_6 , 0xff , V_4 -> V_7 ) ;
V_4 -> V_8 = V_9 ;
F_2 ( V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_10 , T_2 V_7 ,
T_2 * V_11 , void * * V_12 , T_3 * V_13 )
{
* V_12 = V_2 -> V_5 + V_10 ;
* V_11 = V_7 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_10 , T_2 V_7 )
{
return 0 ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_7 ,
unsigned long V_14 ,
unsigned long V_15 )
{
return ( unsigned long ) V_2 -> V_5 + V_14 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_10 , T_2 V_7 ,
T_2 * V_11 , T_4 * V_16 )
{
memcpy ( V_16 , V_2 -> V_5 + V_10 , V_7 ) ;
* V_11 = V_7 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_17 , T_2 V_7 ,
T_2 * V_11 , const T_4 * V_16 )
{
memcpy ( ( char * ) V_2 -> V_5 + V_17 , V_16 , V_7 ) ;
* V_11 = V_7 ;
return 0 ;
}
static void T_5 F_8 ( void )
{
if ( V_1 ) {
F_9 ( V_1 ) ;
F_10 ( V_1 -> V_5 ) ;
F_11 ( V_1 ) ;
}
}
int F_12 ( struct V_1 * V_2 , void * V_18 ,
unsigned long V_19 , char * V_20 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_20 = V_20 ;
V_2 -> type = V_21 ;
V_2 -> V_15 = V_22 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_23 = 1 ;
V_2 -> V_24 = 64 ;
V_2 -> V_25 = V_26 ;
V_2 -> V_5 = V_18 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 = F_1 ;
V_2 -> V_30 = F_3 ;
V_2 -> V_31 = F_4 ;
V_2 -> V_32 = F_5 ;
V_2 -> V_33 = F_6 ;
V_2 -> V_34 = F_7 ;
if ( F_13 ( V_2 , NULL , 0 ) )
return - V_35 ;
return 0 ;
}
static int T_6 F_14 ( void )
{
void * V_6 ;
int V_36 ;
if ( ! V_37 )
return - V_38 ;
V_1 = F_15 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_1 )
return - V_40 ;
V_6 = F_16 ( V_41 ) ;
if ( ! V_6 ) {
F_11 ( V_1 ) ;
V_1 = NULL ;
return - V_40 ;
}
V_36 = F_12 ( V_1 , V_6 , V_41 , L_1 ) ;
if ( V_36 ) {
F_10 ( V_6 ) ;
F_11 ( V_1 ) ;
V_1 = NULL ;
return V_36 ;
}
memset ( V_1 -> V_5 , 0xff , V_41 ) ;
return V_36 ;
}
