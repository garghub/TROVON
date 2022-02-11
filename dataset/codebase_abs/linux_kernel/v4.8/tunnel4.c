static inline struct V_1 T_1 * * F_1 ( unsigned short V_2 )
{
return ( V_2 == V_3 ) ? & V_4 :
( V_2 == V_5 ) ? & V_6 :
& V_7 ;
}
int F_2 ( struct V_1 * V_8 , unsigned short V_2 )
{
struct V_1 T_1 * * V_9 ;
struct V_1 * V_10 ;
int V_11 = - V_12 ;
int V_13 = V_8 -> V_13 ;
F_3 ( & V_14 ) ;
for ( V_9 = F_1 ( V_2 ) ;
( V_10 = F_4 ( * V_9 ,
F_5 ( & V_14 ) ) ) != NULL ;
V_9 = & V_10 -> V_15 ) {
if ( V_10 -> V_13 > V_13 )
break;
if ( V_10 -> V_13 == V_13 )
goto V_16;
}
V_8 -> V_15 = * V_9 ;
F_6 ( * V_9 , V_8 ) ;
V_11 = 0 ;
V_16:
F_7 ( & V_14 ) ;
return V_11 ;
}
int F_8 ( struct V_1 * V_8 , unsigned short V_2 )
{
struct V_1 T_1 * * V_9 ;
struct V_1 * V_10 ;
int V_11 = - V_17 ;
F_3 ( & V_14 ) ;
for ( V_9 = F_1 ( V_2 ) ;
( V_10 = F_4 ( * V_9 ,
F_5 ( & V_14 ) ) ) != NULL ;
V_9 = & V_10 -> V_15 ) {
if ( V_10 == V_8 ) {
* V_9 = V_8 -> V_15 ;
V_11 = 0 ;
break;
}
}
F_7 ( & V_14 ) ;
F_9 () ;
return V_11 ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_8 ;
if ( ! F_11 ( V_19 , sizeof( struct V_20 ) ) )
goto V_21;
F_12 (tunnel4_handlers, handler)
if ( ! V_8 -> V_8 ( V_19 ) )
return 0 ;
F_13 ( V_19 , V_22 , V_23 , 0 ) ;
V_21:
F_14 ( V_19 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 )
{
struct V_1 * V_8 ;
if ( ! F_11 ( V_19 , sizeof( struct V_24 ) ) )
goto V_21;
F_12 (tunnel64_handlers, handler)
if ( ! V_8 -> V_8 ( V_19 ) )
return 0 ;
F_13 ( V_19 , V_22 , V_23 , 0 ) ;
V_21:
F_14 ( V_19 ) ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_1 * V_8 ;
if ( ! F_11 ( V_19 , sizeof( struct V_25 ) ) )
goto V_21;
F_12 (tunnelmpls4_handlers, handler)
if ( ! V_8 -> V_8 ( V_19 ) )
return 0 ;
F_13 ( V_19 , V_22 , V_23 , 0 ) ;
V_21:
F_14 ( V_19 ) ;
return 0 ;
}
static void F_17 ( struct V_18 * V_19 , T_2 V_26 )
{
struct V_1 * V_8 ;
F_12 (tunnel4_handlers, handler)
if ( ! V_8 -> V_27 ( V_19 , V_26 ) )
break;
}
static void F_18 ( struct V_18 * V_19 , T_2 V_26 )
{
struct V_1 * V_8 ;
F_12 (tunnel64_handlers, handler)
if ( ! V_8 -> V_27 ( V_19 , V_26 ) )
break;
}
static void F_19 ( struct V_18 * V_19 , T_2 V_26 )
{
struct V_1 * V_8 ;
F_12 (tunnelmpls4_handlers, handler)
if ( ! V_8 -> V_27 ( V_19 , V_26 ) )
break;
}
static int T_3 F_20 ( void )
{
if ( F_21 ( & V_28 , V_29 ) )
goto V_16;
#if F_22 ( V_30 )
if ( F_21 ( & V_31 , V_32 ) ) {
F_23 ( & V_28 , V_29 ) ;
goto V_16;
}
#endif
#if F_22 ( V_33 )
if ( F_21 ( & V_34 , V_35 ) ) {
F_23 ( & V_28 , V_29 ) ;
#if F_22 ( V_30 )
F_23 ( & V_31 , V_32 ) ;
#endif
goto V_16;
}
#endif
return 0 ;
V_16:
F_24 ( L_1 , V_36 ) ;
return - V_37 ;
}
static void T_4 F_25 ( void )
{
#if F_22 ( V_33 )
if ( F_23 ( & V_34 , V_35 ) )
F_24 ( L_2 ) ;
#endif
#if F_22 ( V_30 )
if ( F_23 ( & V_31 , V_32 ) )
F_24 ( L_3 ) ;
#endif
if ( F_23 ( & V_28 , V_29 ) )
F_24 ( L_4 ) ;
}
