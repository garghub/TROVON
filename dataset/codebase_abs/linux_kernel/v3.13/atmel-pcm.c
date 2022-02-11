static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 [ V_3 ] . V_5 ;
struct V_7 * V_8 = & V_5 -> V_9 ;
T_1 V_10 = V_11 ;
V_8 -> V_12 . type = V_13 ;
V_8 -> V_12 . V_12 = V_2 -> V_14 -> V_12 ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = F_2 ( V_2 -> V_14 -> V_12 , V_10 ,
& V_8 -> V_17 , V_18 ) ;
F_3 ( L_1 ,
( void * ) V_8 -> V_16 , ( void * ) ( long ) V_8 -> V_17 , V_10 ) ;
if ( ! V_8 -> V_16 )
return - V_19 ;
V_8 -> V_20 = V_10 ;
return 0 ;
}
int F_4 ( struct V_4 * V_5 ,
struct V_21 * V_22 )
{
return F_5 ( V_22 , V_22 -> V_23 ,
V_5 -> V_9 . V_17 >> V_24 ,
V_22 -> V_25 - V_22 -> V_23 , V_22 -> V_26 ) ;
}
int F_6 ( struct V_27 * V_28 )
{
struct V_29 * V_14 = V_28 -> V_14 -> V_29 ;
struct V_1 * V_2 = V_28 -> V_2 ;
int V_30 ;
V_30 = F_7 ( V_14 -> V_12 , F_8 ( 32 ) ) ;
if ( V_30 )
return V_30 ;
if ( V_2 -> V_6 [ V_31 ] . V_5 ) {
F_3 ( L_2 ) ;
V_30 = F_1 ( V_2 ,
V_31 ) ;
if ( V_30 )
goto V_32;
}
if ( V_2 -> V_6 [ V_33 ] . V_5 ) {
F_3 ( L_3 ) ;
V_30 = F_1 ( V_2 ,
V_33 ) ;
if ( V_30 )
goto V_32;
}
V_32:
return V_30 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_5 = V_2 -> V_6 [ V_3 ] . V_5 ;
if ( ! V_5 )
continue;
V_8 = & V_5 -> V_9 ;
if ( ! V_8 -> V_16 )
continue;
F_10 ( V_2 -> V_14 -> V_12 , V_8 -> V_20 ,
V_8 -> V_16 , V_8 -> V_17 ) ;
V_8 -> V_16 = NULL ;
}
}
