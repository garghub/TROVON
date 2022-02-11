static inline struct V_1 T_1 * * F_1 ( unsigned short V_2 )
{
return ( V_2 == V_3 ) ? & V_4 : & V_5 ;
}
int F_2 ( struct V_1 * V_6 , unsigned short V_2 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_8 ;
int V_9 = - V_10 ;
int V_11 = V_6 -> V_11 ;
F_3 ( & V_12 ) ;
for ( V_7 = F_1 ( V_2 ) ;
( V_8 = F_4 ( * V_7 ,
F_5 ( & V_12 ) ) ) != NULL ;
V_7 = & V_8 -> V_13 ) {
if ( V_8 -> V_11 > V_11 )
break;
if ( V_8 -> V_11 == V_11 )
goto V_14;
}
V_6 -> V_13 = * V_7 ;
F_6 ( * V_7 , V_6 ) ;
V_9 = 0 ;
V_14:
F_7 ( & V_12 ) ;
return V_9 ;
}
int F_8 ( struct V_1 * V_6 , unsigned short V_2 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_8 ;
int V_9 = - V_15 ;
F_3 ( & V_12 ) ;
for ( V_7 = F_1 ( V_2 ) ;
( V_8 = F_4 ( * V_7 ,
F_5 ( & V_12 ) ) ) != NULL ;
V_7 = & V_8 -> V_13 ) {
if ( V_8 == V_6 ) {
* V_7 = V_6 -> V_13 ;
V_9 = 0 ;
break;
}
}
F_7 ( & V_12 ) ;
F_9 () ;
return V_9 ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_1 * V_6 ;
if ( ! F_11 ( V_17 , sizeof( struct V_18 ) ) )
goto V_19;
F_12 (tunnel4_handlers, handler)
if ( ! V_6 -> V_6 ( V_17 ) )
return 0 ;
F_13 ( V_17 , V_20 , V_21 , 0 ) ;
V_19:
F_14 ( V_17 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_6 ;
if ( ! F_11 ( V_17 , sizeof( struct V_22 ) ) )
goto V_19;
F_12 (tunnel64_handlers, handler)
if ( ! V_6 -> V_6 ( V_17 ) )
return 0 ;
F_13 ( V_17 , V_20 , V_21 , 0 ) ;
V_19:
F_14 ( V_17 ) ;
return 0 ;
}
static void F_16 ( struct V_16 * V_17 , T_2 V_23 )
{
struct V_1 * V_6 ;
F_12 (tunnel4_handlers, handler)
if ( ! V_6 -> V_24 ( V_17 , V_23 ) )
break;
}
static void F_17 ( struct V_16 * V_17 , T_2 V_23 )
{
struct V_1 * V_6 ;
F_12 (tunnel64_handlers, handler)
if ( ! V_6 -> V_24 ( V_17 , V_23 ) )
break;
}
static int T_3 F_18 ( void )
{
if ( F_19 ( & V_25 , V_26 ) ) {
F_20 ( L_1 , V_27 ) ;
return - V_28 ;
}
#if F_21 ( V_29 )
if ( F_19 ( & V_30 , V_31 ) ) {
F_20 ( L_2 ) ;
F_22 ( & V_25 , V_26 ) ;
return - V_28 ;
}
#endif
return 0 ;
}
static void T_4 F_23 ( void )
{
#if F_21 ( V_29 )
if ( F_22 ( & V_30 , V_31 ) )
F_20 ( L_3 ) ;
#endif
if ( F_22 ( & V_25 , V_26 ) )
F_20 ( L_4 ) ;
}
