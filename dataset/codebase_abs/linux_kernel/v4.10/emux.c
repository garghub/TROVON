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
#ifdef F_5
V_3 -> V_9 = NULL ;
#endif
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0 ;
F_6 ( & V_3 -> V_12 , V_13 , ( unsigned long ) V_3 ) ;
V_3 -> V_14 = 0 ;
* V_2 = V_3 ;
return 0 ;
}
static int F_7 ( void * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 ,
const void T_1 * V_20 , long V_21 )
{
struct V_1 * V_3 = V_15 ;
return V_3 -> V_22 . V_23 ( V_3 , V_17 , V_19 , V_20 , V_21 ) ;
}
static int F_8 ( void * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_3 = V_15 ;
return V_3 -> V_22 . V_24 ( V_3 , V_17 , V_19 ) ;
}
static void F_9 ( void * V_15 )
{
struct V_1 * V_3 = V_15 ;
V_3 -> V_22 . V_25 ( V_3 ) ;
}
int F_10 ( struct V_1 * V_3 , struct V_26 * V_27 , int V_28 , char * V_29 )
{
int V_30 ;
struct V_31 V_32 ;
if ( F_11 ( ! V_3 -> V_33 || V_3 -> V_10 <= 0 ) )
return - V_34 ;
if ( F_11 ( ! V_27 || ! V_29 ) )
return - V_34 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_29 = F_12 ( V_29 , V_4 ) ;
V_3 -> V_35 = F_13 ( V_3 -> V_10 , sizeof( struct V_36 ) ,
V_4 ) ;
if ( V_3 -> V_35 == NULL )
return - V_5 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_15 = V_3 ;
if ( V_3 -> V_22 . V_23 )
V_32 . V_23 = F_7 ;
if ( V_3 -> V_22 . V_24 )
V_32 . V_24 = F_8 ;
if ( V_3 -> V_22 . V_25 )
V_32 . V_25 = F_9 ;
V_3 -> V_37 = F_14 ( & V_32 , V_3 -> V_38 ) ;
if ( V_3 -> V_37 == NULL )
return - V_5 ;
if ( ( V_30 = F_15 ( V_3 ) ) < 0 )
return V_30 ;
F_16 ( V_3 ) ;
F_17 ( V_3 , V_27 , V_28 ) ;
#ifdef F_5
F_18 ( V_3 ) ;
#endif
F_19 ( V_3 , V_27 ) ;
F_20 ( V_3 , V_27 , V_28 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_3 )
{
unsigned long V_39 ;
if ( ! V_3 )
return - V_34 ;
F_22 ( & V_3 -> V_6 , V_39 ) ;
if ( V_3 -> V_14 )
F_23 ( & V_3 -> V_12 ) ;
F_24 ( & V_3 -> V_6 , V_39 ) ;
F_25 ( V_3 ) ;
F_26 ( V_3 ) ;
#ifdef F_5
F_27 ( V_3 ) ;
#endif
F_28 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( V_3 -> V_37 ) ;
F_31 ( V_3 -> V_35 ) ;
F_31 ( V_3 -> V_29 ) ;
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
