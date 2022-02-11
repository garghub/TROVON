static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return ( F_2 ( V_4 -> V_6 ) >> 16 ) ;
}
static void F_3 ( struct V_1 * V_2 , const T_1 * V_7 , int V_8 )
{
int V_9 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_4 ( ( * V_7 ++ << 16 ) , V_4 -> V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_7 , int V_8 )
{
int V_9 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
* V_7 ++ = F_2 ( V_4 -> V_6 ) >> 16 ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_7 , int V_8 )
{
int V_9 ;
struct V_3 * V_4 = V_2 -> V_5 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
if ( V_7 [ V_9 ] != ( T_1 ) ( F_2 ( V_4 -> V_6 ) >> 16 ) )
return - V_11 ;
return 0 ;
}
static inline void F_7 ( void )
{
F_8 ( V_12 , 0 ) ;
}
static void F_9 ( void )
{
F_10 () ;
F_8 ( V_12 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_13 ,
unsigned int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_15 = ( unsigned int ) V_4 -> V_10 ;
F_10 () ;
if ( V_14 & V_16 ) {
if ( V_14 & V_17 )
V_15 |= ( 1 << 3 ) ;
else
V_15 &= ~ ( 1 << 3 ) ;
if ( V_14 & V_18 )
V_15 |= ( 1 << 2 ) ;
else
V_15 &= ~ ( 1 << 2 ) ;
if ( V_14 & V_19 )
F_7 () ;
else
F_9 () ;
}
F_10 () ;
V_4 -> V_10 = ( void V_20 * ) V_15 ;
if ( V_13 != V_21 )
F_4 ( ( V_13 << 16 ) , V_4 -> V_10 ) ;
F_10 () ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_10 () ;
return ( F_13 ( V_22 ) ) ;
}
static int T_2 F_14 ( void )
{
struct V_3 * V_4 ;
int V_23 ;
if ( ! ( F_15 () && F_16 () ) )
return - V_24 ;
V_23 = F_17 ( V_12 , L_1 ) ;
if ( V_23 ) {
F_18 ( L_2 ) ;
return V_23 ;
}
F_19 ( V_12 , 1 ) ;
V_23 = F_17 ( V_22 , L_3 ) ;
if ( V_23 ) {
F_18 ( L_4 ) ;
goto V_25;
}
F_20 ( V_22 ) ;
V_26 = F_21 ( sizeof( struct V_1 ) +
sizeof( struct V_3 ) ,
V_27 ) ;
if ( ! V_26 ) {
F_22 ( L_5 ) ;
V_23 = - V_28 ;
goto V_29;
}
V_30 = F_23 ( V_31 , 12 ) ;
if ( ! V_30 ) {
F_22 ( L_6 ) ;
V_23 = - V_32 ;
goto V_33;
}
V_4 = (struct V_3 * ) ( & V_26 [ 1 ] ) ;
V_26 -> V_34 = V_35 ;
V_26 -> V_5 = V_4 ;
V_4 -> V_6 = V_30 ;
V_4 -> V_10 = V_30 ;
V_4 -> V_36 = F_11 ;
V_4 -> V_37 = F_12 ;
V_4 -> V_38 = 20 ;
V_4 -> V_39 . V_40 = V_41 ;
V_4 -> V_42 = F_1 ;
V_4 -> V_43 = F_5 ;
V_4 -> V_44 = F_3 ;
V_4 -> V_45 = F_6 ;
if ( F_24 ( V_26 , 1 ) ) {
F_25 ( L_7 ) ;
V_23 = - V_46 ;
goto V_47;
}
V_23 = F_26 ( V_26 , NULL , NULL ,
V_48 , V_49 ) ;
if ( V_23 )
goto V_47;
return 0 ;
V_47:
F_27 ( V_30 ) ;
V_33:
F_28 ( V_26 ) ;
V_29:
F_29 ( V_22 ) ;
V_25:
F_29 ( V_12 ) ;
return V_23 ;
}
static void T_3 F_30 ( void )
{
F_31 ( V_26 ) ;
F_29 ( V_22 ) ;
F_29 ( V_12 ) ;
F_27 ( V_30 ) ;
F_28 ( V_26 ) ;
}
