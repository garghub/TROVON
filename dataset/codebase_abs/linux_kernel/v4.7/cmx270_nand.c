static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ( F_3 ( V_4 -> V_5 ) >> 16 ) ;
}
static void F_4 ( struct V_1 * V_2 , const T_1 * V_6 , int V_7 )
{
int V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_5 ( ( * V_6 ++ << 16 ) , V_4 -> V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 * V_6 , int V_7 )
{
int V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
* V_6 ++ = F_3 ( V_4 -> V_5 ) >> 16 ;
}
static inline void F_7 ( void )
{
F_8 ( V_10 , 0 ) ;
}
static void F_9 ( void )
{
F_10 () ;
F_8 ( V_10 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_11 ,
unsigned int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_13 = ( unsigned int ) V_4 -> V_9 ;
F_10 () ;
if ( V_12 & V_14 ) {
if ( V_12 & V_15 )
V_13 |= ( 1 << 3 ) ;
else
V_13 &= ~ ( 1 << 3 ) ;
if ( V_12 & V_16 )
V_13 |= ( 1 << 2 ) ;
else
V_13 &= ~ ( 1 << 2 ) ;
if ( V_12 & V_17 )
F_7 () ;
else
F_9 () ;
}
F_10 () ;
V_4 -> V_9 = ( void V_18 * ) V_13 ;
if ( V_11 != V_19 )
F_5 ( ( V_11 << 16 ) , V_4 -> V_9 ) ;
F_10 () ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_10 () ;
return ( F_13 ( V_20 ) ) ;
}
static int T_2 F_14 ( void )
{
struct V_3 * V_4 ;
int V_21 ;
if ( ! ( F_15 () && F_16 () ) )
return - V_22 ;
V_21 = F_17 ( V_10 , L_1 ) ;
if ( V_21 ) {
F_18 ( L_2 ) ;
return V_21 ;
}
F_19 ( V_10 , 1 ) ;
V_21 = F_17 ( V_20 , L_3 ) ;
if ( V_21 ) {
F_18 ( L_4 ) ;
goto V_23;
}
F_20 ( V_20 ) ;
V_4 = F_21 ( sizeof( struct V_3 ) , V_24 ) ;
if ( ! V_4 ) {
V_21 = - V_25 ;
goto V_26;
}
V_27 = F_22 ( V_28 , 12 ) ;
if ( ! V_27 ) {
F_23 ( L_5 ) ;
V_21 = - V_29 ;
goto V_30;
}
V_31 = F_24 ( V_4 ) ;
V_31 -> V_32 = V_33 ;
V_4 -> V_5 = V_27 ;
V_4 -> V_9 = V_27 ;
V_4 -> V_34 = F_11 ;
V_4 -> V_35 = F_12 ;
V_4 -> V_36 = 20 ;
V_4 -> V_37 . V_38 = V_39 ;
V_4 -> V_37 . V_40 = V_41 ;
V_4 -> V_42 = F_1 ;
V_4 -> V_43 = F_6 ;
V_4 -> V_44 = F_4 ;
if ( F_25 ( V_31 , 1 ) ) {
F_26 ( L_6 ) ;
V_21 = - V_45 ;
goto V_46;
}
V_21 = F_27 ( V_31 , NULL , NULL ,
V_47 , V_48 ) ;
if ( V_21 )
goto V_46;
return 0 ;
V_46:
F_28 ( V_27 ) ;
V_30:
F_29 ( V_4 ) ;
V_26:
F_30 ( V_20 ) ;
V_23:
F_30 ( V_10 ) ;
return V_21 ;
}
static void T_3 F_31 ( void )
{
F_32 ( V_31 ) ;
F_30 ( V_20 ) ;
F_30 ( V_10 ) ;
F_28 ( V_27 ) ;
F_29 ( F_2 ( V_31 ) ) ;
}
