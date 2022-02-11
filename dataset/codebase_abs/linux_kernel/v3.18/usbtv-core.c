int F_1 ( struct V_1 * V_1 , const T_1 V_2 [] [ 2 ] , int V_3 )
{
int V_4 ;
int V_5 = F_2 ( V_1 -> V_6 , 0 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
T_1 V_8 = V_2 [ V_7 ] [ 0 ] ;
T_1 V_9 = V_2 [ V_7 ] [ 1 ] ;
V_4 = F_3 ( V_1 -> V_6 , V_5 , V_10 ,
V_11 | V_12 | V_13 ,
V_9 , V_8 , NULL , 0 , 0 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_4 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
int V_4 ;
int V_3 ;
struct V_18 * V_19 = & V_15 -> V_19 ;
struct V_1 * V_1 ;
if ( V_15 -> V_20 != 2 )
return - V_21 ;
if ( V_15 -> V_22 [ 1 ] . V_23 . V_24 != 4 )
return - V_21 ;
V_3 = F_5 ( & V_15 -> V_22 [ 1 ] . V_25 [ 0 ] . V_23 ) ;
V_3 = ( V_3 & 0x07ff ) * ( ( ( V_3 & 0x1800 ) >> 11 ) + 1 ) ;
V_1 = F_6 ( sizeof( struct V_1 ) , V_26 ) ;
if ( V_1 == NULL )
return - V_27 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_6 = F_7 ( F_8 ( V_15 ) ) ;
V_1 -> V_28 = V_3 ;
F_9 ( V_15 , V_1 ) ;
V_4 = F_10 ( V_1 ) ;
if ( V_4 < 0 )
goto V_29;
V_4 = F_11 ( V_1 ) ;
if ( V_4 < 0 )
goto V_30;
F_12 ( & V_1 -> V_31 ) ;
F_13 ( V_19 , L_1 ) ;
return 0 ;
V_30:
F_14 ( V_1 ) ;
V_29:
F_9 ( V_15 , NULL ) ;
F_15 ( V_1 -> V_6 ) ;
F_16 ( V_1 ) ;
return V_4 ;
}
static void F_17 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_18 ( V_15 ) ;
F_9 ( V_15 , NULL ) ;
if ( ! V_1 )
return;
F_19 ( V_1 ) ;
F_14 ( V_1 ) ;
F_15 ( V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
F_20 ( & V_1 -> V_31 ) ;
}
