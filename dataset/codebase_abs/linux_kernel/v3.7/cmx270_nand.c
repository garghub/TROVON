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
static inline void F_6 ( void )
{
F_7 ( V_11 , 0 ) ;
}
static void F_8 ( void )
{
F_9 () ;
F_7 ( V_11 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_12 ,
unsigned int V_13 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_14 = ( unsigned int ) V_4 -> V_10 ;
F_9 () ;
if ( V_13 & V_15 ) {
if ( V_13 & V_16 )
V_14 |= ( 1 << 3 ) ;
else
V_14 &= ~ ( 1 << 3 ) ;
if ( V_13 & V_17 )
V_14 |= ( 1 << 2 ) ;
else
V_14 &= ~ ( 1 << 2 ) ;
if ( V_13 & V_18 )
F_6 () ;
else
F_8 () ;
}
F_9 () ;
V_4 -> V_10 = ( void V_19 * ) V_14 ;
if ( V_12 != V_20 )
F_4 ( ( V_12 << 16 ) , V_4 -> V_10 ) ;
F_9 () ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_9 () ;
return ( F_12 ( V_21 ) ) ;
}
static int T_2 F_13 ( void )
{
struct V_3 * V_4 ;
int V_22 ;
if ( ! ( F_14 () && F_15 () ) )
return - V_23 ;
V_22 = F_16 ( V_11 , L_1 ) ;
if ( V_22 ) {
F_17 ( L_2 ) ;
return V_22 ;
}
F_18 ( V_11 , 1 ) ;
V_22 = F_16 ( V_21 , L_3 ) ;
if ( V_22 ) {
F_17 ( L_4 ) ;
goto V_24;
}
F_19 ( V_21 ) ;
V_25 = F_20 ( sizeof( struct V_1 ) +
sizeof( struct V_3 ) ,
V_26 ) ;
if ( ! V_25 ) {
F_21 ( L_5 ) ;
V_22 = - V_27 ;
goto V_28;
}
V_29 = F_22 ( V_30 , 12 ) ;
if ( ! V_29 ) {
F_21 ( L_6 ) ;
V_22 = - V_31 ;
goto V_32;
}
V_4 = (struct V_3 * ) ( & V_25 [ 1 ] ) ;
V_25 -> V_33 = V_34 ;
V_25 -> V_5 = V_4 ;
V_4 -> V_6 = V_29 ;
V_4 -> V_10 = V_29 ;
V_4 -> V_35 = F_10 ;
V_4 -> V_36 = F_11 ;
V_4 -> V_37 = 20 ;
V_4 -> V_38 . V_39 = V_40 ;
V_4 -> V_41 = F_1 ;
V_4 -> V_42 = F_5 ;
V_4 -> V_43 = F_3 ;
if ( F_23 ( V_25 , 1 ) ) {
F_24 ( L_7 ) ;
V_22 = - V_44 ;
goto V_45;
}
V_22 = F_25 ( V_25 , NULL , NULL ,
V_46 , V_47 ) ;
if ( V_22 )
goto V_45;
return 0 ;
V_45:
F_26 ( V_29 ) ;
V_32:
F_27 ( V_25 ) ;
V_28:
F_28 ( V_21 ) ;
V_24:
F_28 ( V_11 ) ;
return V_22 ;
}
static void T_3 F_29 ( void )
{
F_30 ( V_25 ) ;
F_28 ( V_21 ) ;
F_28 ( V_11 ) ;
F_26 ( V_29 ) ;
F_27 ( V_25 ) ;
}
