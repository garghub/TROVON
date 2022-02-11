static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = (struct V_3 * ) V_2 ;
V_8 = F_2 ( V_4 ,
struct V_5 ) ;
if ( V_8 <= 1 ) {
F_3 ( L_1 ) ;
return - V_9 ;
}
V_6 = (struct V_5 * ) V_4 -> V_6 ;
V_7 = V_8 * sizeof( * V_6 ) ;
V_10 = F_4 ( V_7 , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
memcpy ( V_10 , V_6 , V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_13 * V_14 , unsigned int V_15 )
{
unsigned int V_16 = 0 ;
T_1 V_17 , V_18 ;
V_16 = V_14 -> V_19 [ V_15 ] . V_20 ;
F_6 ( V_14 -> V_21 , V_22 , & V_17 , & V_18 ) ;
V_17 = ( V_17 & ~ V_23 ) |
( ( T_1 ) V_10 [ V_16 ] . V_24 &
V_23 ) ;
F_7 ( V_14 -> V_21 , V_22 , V_17 , V_18 ) ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 )
{
V_14 -> V_25 = V_26 ;
V_14 -> V_27 . V_28 = 100000 ;
return F_9 ( V_14 , V_19 ) ;
}
static int T_2 F_10 ( void )
{
int V_29 , V_30 ;
V_29 = F_11 ( V_31 , NULL , NULL , F_1 ) ;
if ( V_29 )
return V_29 ;
V_19 = F_4 ( sizeof( * V_19 ) *
( V_8 + 1 ) , V_11 ) ;
if ( ! V_19 ) {
V_29 = - V_12 ;
goto V_32;
}
for ( V_30 = 0 ; V_30 < V_8 ; V_30 ++ ) {
V_19 [ V_30 ] . V_20 = V_30 ;
V_19 [ V_30 ] . V_33 = V_10 [ V_30 ] . V_34 * 1000 ;
}
V_19 [ V_30 ] . V_33 = V_35 ;
V_29 = F_12 ( & V_36 ) ;
if ( V_29 )
goto V_37;
return V_29 ;
V_37:
F_13 ( V_19 ) ;
V_32:
F_13 ( V_10 ) ;
return V_29 ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_36 ) ;
F_13 ( V_19 ) ;
F_13 ( V_10 ) ;
}
