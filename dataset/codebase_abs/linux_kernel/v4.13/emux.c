int F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 ;
* V_2 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 == NULL )
return - V_5 ;
F_3 ( & V_3 -> V_6 ) ;
F_4 ( & V_3 -> V_7 ) ;
V_3 -> V_8 = - 1 ;
#if F_5 ( V_9 )
V_3 -> V_10 = NULL ;
#endif
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0 ;
F_6 ( & V_3 -> V_13 , V_14 , ( unsigned long ) V_3 ) ;
V_3 -> V_15 = 0 ;
* V_2 = V_3 ;
return 0 ;
}
static int F_7 ( void * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 ,
const void T_1 * V_21 , long V_22 )
{
struct V_1 * V_3 = V_16 ;
return V_3 -> V_23 . V_24 ( V_3 , V_18 , V_20 , V_21 , V_22 ) ;
}
static int F_8 ( void * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_1 * V_3 = V_16 ;
return V_3 -> V_23 . V_25 ( V_3 , V_18 , V_20 ) ;
}
static void F_9 ( void * V_16 )
{
struct V_1 * V_3 = V_16 ;
V_3 -> V_23 . V_26 ( V_3 ) ;
}
int F_10 ( struct V_1 * V_3 , struct V_27 * V_28 , int V_29 , char * V_30 )
{
int V_31 ;
struct V_32 V_33 ;
if ( F_11 ( ! V_3 -> V_34 || V_3 -> V_11 <= 0 ) )
return - V_35 ;
if ( F_11 ( ! V_28 || ! V_30 ) )
return - V_35 ;
V_3 -> V_28 = V_28 ;
V_3 -> V_30 = F_12 ( V_30 , V_4 ) ;
V_3 -> V_36 = F_13 ( V_3 -> V_11 , sizeof( struct V_37 ) ,
V_4 ) ;
if ( V_3 -> V_36 == NULL )
return - V_5 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_16 = V_3 ;
if ( V_3 -> V_23 . V_24 )
V_33 . V_24 = F_7 ;
if ( V_3 -> V_23 . V_25 )
V_33 . V_25 = F_8 ;
if ( V_3 -> V_23 . V_26 )
V_33 . V_26 = F_9 ;
V_3 -> V_38 = F_14 ( & V_33 , V_3 -> V_39 ) ;
if ( V_3 -> V_38 == NULL )
return - V_5 ;
if ( ( V_31 = F_15 ( V_3 ) ) < 0 )
return V_31 ;
F_16 ( V_3 ) ;
F_17 ( V_3 , V_28 , V_29 ) ;
#if F_5 ( V_9 )
F_18 ( V_3 ) ;
#endif
F_19 ( V_3 , V_28 ) ;
F_20 ( V_3 , V_28 , V_29 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_3 )
{
unsigned long V_40 ;
if ( ! V_3 )
return - V_35 ;
F_22 ( & V_3 -> V_6 , V_40 ) ;
if ( V_3 -> V_15 )
F_23 ( & V_3 -> V_13 ) ;
F_24 ( & V_3 -> V_6 , V_40 ) ;
F_25 ( V_3 ) ;
F_26 ( V_3 ) ;
#if F_5 ( V_9 )
F_27 ( V_3 ) ;
#endif
F_28 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( V_3 -> V_38 ) ;
F_31 ( V_3 -> V_36 ) ;
F_31 ( V_3 -> V_30 ) ;
F_31 ( V_3 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return 0 ;
}
static void T_3 F_33 ( void )
{
}
