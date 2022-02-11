static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
unsigned long V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
T_1 V_10 = F_2 ( V_5 , 1 << V_8 -> V_11 ) ;
V_6 = F_3 ( V_8 , V_10 ) ;
if ( ! V_6 )
return - V_12 ;
memset ( ( void * ) V_6 , 0 , V_10 ) ;
V_4 -> V_13 = ( void * ) V_6 ;
V_4 -> V_14 = F_4 ( V_8 , V_6 ) ;
V_4 -> V_5 = V_10 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_6 ( V_2 -> V_9 , ( unsigned long ) V_4 -> V_13 ,
V_4 -> V_5 ) ;
V_4 -> V_13 = NULL ;
}
static void F_7 ( struct V_15 * V_16 )
{
F_8 ( V_16 -> V_17 . V_9 ) ;
F_8 ( V_16 -> V_18 . V_9 ) ;
}
static int F_9 ( struct V_1 * V_19 ,
struct V_20 * V_21 ,
int V_11 )
{
T_1 V_22 = V_23 - 1 ;
struct V_7 * V_8 = NULL ;
int V_24 ;
if ( ( V_21 -> V_25 & V_22 ) || ( V_21 -> V_14 & V_22 ) ||
( V_21 -> V_5 & V_22 ) )
return - V_26 ;
V_8 = F_10 ( V_11 , - 1 ) ;
if ( ! V_8 )
return - V_12 ;
F_11 ( V_8 , V_27 , NULL ) ;
V_24 = F_12 ( V_8 , V_21 -> V_25 , V_21 -> V_14 , V_21 -> V_5 ,
- 1 ) ;
if ( V_24 ) {
F_8 ( V_8 ) ;
return V_24 ;
}
V_19 -> V_9 = V_8 ;
V_19 -> V_28 = & V_29 ;
return 0 ;
}
struct V_15 *
F_13 ( struct V_20 * V_30 ,
struct V_20 * V_31 )
{
struct V_15 * V_16 = NULL ;
int V_32 ;
V_16 = F_14 ( sizeof( * V_16 ) , V_33 ) ;
if ( ! V_16 ) {
V_32 = - V_12 ;
goto V_34;
}
V_32 = F_9 ( & V_16 -> V_17 , V_30 ,
3 ) ;
if ( V_32 )
goto V_34;
V_32 = F_9 ( & V_16 -> V_18 , V_31 ,
V_35 ) ;
if ( V_32 )
goto V_34;
V_16 -> V_36 = F_7 ;
return V_16 ;
V_34:
if ( V_32 == - V_12 )
F_15 ( L_1 , V_37 ) ;
if ( V_16 && V_16 -> V_17 . V_9 )
F_8 ( V_16 -> V_17 . V_9 ) ;
F_16 ( V_16 ) ;
return F_17 ( V_32 ) ;
}
void F_18 ( struct V_15 * V_16 )
{
V_16 -> V_36 ( V_16 ) ;
F_16 ( V_16 ) ;
}
