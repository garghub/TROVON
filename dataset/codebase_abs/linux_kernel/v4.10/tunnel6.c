int F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
struct V_1 T_1 * * V_4 ;
struct V_1 * V_5 ;
int V_6 = - V_7 ;
int V_8 = V_2 -> V_8 ;
F_2 ( & V_9 ) ;
for ( V_4 = ( V_3 == V_10 ) ? & V_11 : & V_12 ;
( V_5 = F_3 ( * V_4 ,
F_4 ( & V_9 ) ) ) != NULL ;
V_4 = & V_5 -> V_13 ) {
if ( V_5 -> V_8 > V_8 )
break;
if ( V_5 -> V_8 == V_8 )
goto V_14;
}
V_2 -> V_13 = * V_4 ;
F_5 ( * V_4 , V_2 ) ;
V_6 = 0 ;
V_14:
F_6 ( & V_9 ) ;
return V_6 ;
}
int F_7 ( struct V_1 * V_2 , unsigned short V_3 )
{
struct V_1 T_1 * * V_4 ;
struct V_1 * V_5 ;
int V_6 = - V_15 ;
F_2 ( & V_9 ) ;
for ( V_4 = ( V_3 == V_10 ) ? & V_11 : & V_12 ;
( V_5 = F_3 ( * V_4 ,
F_4 ( & V_9 ) ) ) != NULL ;
V_4 = & V_5 -> V_13 ) {
if ( V_5 == V_2 ) {
* V_4 = V_2 -> V_13 ;
V_6 = 0 ;
break;
}
}
F_6 ( & V_9 ) ;
F_8 () ;
return V_6 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
if ( ! F_10 ( V_17 , sizeof( struct V_18 ) ) )
goto V_19;
F_11 (tunnel46_handlers, handler)
if ( ! V_2 -> V_2 ( V_17 ) )
return 0 ;
F_12 ( V_17 , V_20 , V_21 , 0 ) ;
V_19:
F_13 ( V_17 ) ;
return 0 ;
}
static void F_14 ( struct V_16 * V_17 , struct V_22 * V_23 ,
T_2 type , T_2 V_24 , int V_25 , T_3 V_26 )
{
struct V_1 * V_2 ;
F_11 (tunnel6_handlers, handler)
if ( ! V_2 -> V_27 ( V_17 , V_23 , type , V_24 , V_25 , V_26 ) )
break;
}
static void F_15 ( struct V_16 * V_17 , struct V_22 * V_23 ,
T_2 type , T_2 V_24 , int V_25 , T_3 V_26 )
{
struct V_1 * V_2 ;
F_11 (tunnel46_handlers, handler)
if ( ! V_2 -> V_27 ( V_17 , V_23 , type , V_24 , V_25 , V_26 ) )
break;
}
static int T_4 F_16 ( void )
{
if ( F_17 ( & V_28 , V_29 ) ) {
F_18 ( L_1 , V_30 ) ;
return - V_31 ;
}
if ( F_17 ( & V_32 , V_33 ) ) {
F_18 ( L_1 , V_30 ) ;
F_19 ( & V_28 , V_29 ) ;
return - V_31 ;
}
return 0 ;
}
static void T_5 F_20 ( void )
{
if ( F_19 ( & V_32 , V_33 ) )
F_18 ( L_2 , V_30 ) ;
if ( F_19 ( & V_28 , V_29 ) )
F_18 ( L_2 , V_30 ) ;
}
