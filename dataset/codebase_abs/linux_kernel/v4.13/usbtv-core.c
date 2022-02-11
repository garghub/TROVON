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
struct V_20 * V_21 ;
if ( V_15 -> V_22 != 2 )
return - V_23 ;
if ( V_15 -> V_24 [ 1 ] . V_25 . V_26 != 4 )
return - V_23 ;
V_21 = & V_15 -> V_24 [ 1 ] . V_27 [ 0 ] ;
V_3 = F_5 ( & V_21 -> V_25 ) ;
V_3 = ( V_3 & 0x07ff ) * F_6 ( & V_21 -> V_25 ) ;
V_1 = F_7 ( sizeof( struct V_1 ) , V_28 ) ;
if ( V_1 == NULL )
return - V_29 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_6 = F_8 ( F_9 ( V_15 ) ) ;
V_1 -> V_30 = V_3 ;
F_10 ( V_15 , V_1 ) ;
V_4 = F_11 ( V_1 ) ;
if ( V_4 < 0 )
goto V_31;
V_4 = F_12 ( V_1 ) ;
if ( V_4 < 0 )
goto V_32;
F_13 ( & V_1 -> V_33 ) ;
F_14 ( V_19 , L_1 ) ;
return 0 ;
V_32:
F_15 ( V_1 ) ;
V_31:
F_10 ( V_15 , NULL ) ;
F_16 ( V_1 -> V_6 ) ;
F_17 ( V_1 ) ;
return V_4 ;
}
static void F_18 ( struct V_14 * V_15 )
{
struct V_1 * V_1 = F_19 ( V_15 ) ;
F_10 ( V_15 , NULL ) ;
if ( ! V_1 )
return;
F_20 ( V_1 ) ;
F_15 ( V_1 ) ;
F_16 ( V_1 -> V_6 ) ;
V_1 -> V_6 = NULL ;
F_21 ( & V_1 -> V_33 ) ;
}
