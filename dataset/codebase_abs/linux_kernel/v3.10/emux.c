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
F_6 ( & V_3 -> V_12 ) ;
V_3 -> V_12 . V_13 = V_14 ;
V_3 -> V_12 . V_15 = ( unsigned long ) V_3 ;
V_3 -> V_16 = 0 ;
* V_2 = V_3 ;
return 0 ;
}
static int F_7 ( void * V_17 , struct V_18 * V_19 ,
struct V_20 * V_21 ,
const void T_1 * V_22 , long V_23 )
{
struct V_1 * V_3 = V_17 ;
return V_3 -> V_24 . V_25 ( V_3 , V_19 , V_21 , V_22 , V_23 ) ;
}
static int F_8 ( void * V_17 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_1 * V_3 = V_17 ;
return V_3 -> V_24 . V_26 ( V_3 , V_19 , V_21 ) ;
}
static void F_9 ( void * V_17 )
{
struct V_1 * V_3 = V_17 ;
V_3 -> V_24 . V_27 ( V_3 ) ;
}
int F_10 ( struct V_1 * V_3 , struct V_28 * V_29 , int V_30 , char * V_31 )
{
int V_32 ;
struct V_33 V_34 ;
if ( F_11 ( ! V_3 -> V_35 || V_3 -> V_10 <= 0 ) )
return - V_36 ;
if ( F_11 ( ! V_29 || ! V_31 ) )
return - V_36 ;
V_3 -> V_29 = V_29 ;
V_3 -> V_31 = F_12 ( V_31 , V_4 ) ;
V_3 -> V_37 = F_13 ( V_3 -> V_10 , sizeof( struct V_38 ) ,
V_4 ) ;
if ( V_3 -> V_37 == NULL )
return - V_5 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_17 = V_3 ;
if ( V_3 -> V_24 . V_25 )
V_34 . V_25 = F_7 ;
if ( V_3 -> V_24 . V_26 )
V_34 . V_26 = F_8 ;
if ( V_3 -> V_24 . V_27 )
V_34 . V_27 = F_9 ;
V_3 -> V_39 = F_14 ( & V_34 , V_3 -> V_40 ) ;
if ( V_3 -> V_39 == NULL )
return - V_5 ;
if ( ( V_32 = F_15 ( V_3 ) ) < 0 )
return V_32 ;
F_16 ( V_3 ) ;
F_17 ( V_3 , V_29 , V_30 ) ;
#ifdef F_5
F_18 ( V_3 ) ;
#endif
F_19 ( V_3 , V_29 ) ;
#ifdef F_20
F_21 ( V_3 , V_29 , V_30 ) ;
#endif
return 0 ;
}
int F_22 ( struct V_1 * V_3 )
{
unsigned long V_41 ;
if ( ! V_3 )
return - V_36 ;
F_23 ( & V_3 -> V_6 , V_41 ) ;
if ( V_3 -> V_16 )
F_24 ( & V_3 -> V_12 ) ;
F_25 ( & V_3 -> V_6 , V_41 ) ;
#ifdef F_20
F_26 ( V_3 ) ;
#endif
F_27 ( V_3 ) ;
#ifdef F_5
F_28 ( V_3 ) ;
#endif
F_29 ( V_3 ) ;
F_30 ( V_3 ) ;
if ( V_3 -> V_39 )
F_31 ( V_3 -> V_39 ) ;
F_32 ( V_3 -> V_37 ) ;
F_32 ( V_3 -> V_31 ) ;
F_32 ( V_3 ) ;
return 0 ;
}
static int T_2 F_33 ( void )
{
return 0 ;
}
static void T_3 F_34 ( void )
{
}
