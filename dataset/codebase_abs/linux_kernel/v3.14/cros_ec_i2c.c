static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static int F_4 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 = V_6 -> V_9 ;
int V_10 = - V_11 ;
int V_12 ;
int V_13 ;
T_1 * V_14 = NULL ;
T_1 * V_15 = NULL ;
T_1 V_16 ;
struct V_17 V_17 [ 2 ] ;
V_17 [ 0 ] . V_18 = V_5 -> V_18 ;
V_17 [ 0 ] . V_19 = 0 ;
V_17 [ 1 ] . V_18 = V_5 -> V_18 ;
V_17 [ 1 ] . V_19 = V_20 ;
V_13 = V_8 -> V_21 + 3 ;
V_15 = F_5 ( V_13 , V_22 ) ;
if ( ! V_15 )
goto V_23;
V_17 [ 1 ] . V_24 = V_13 ;
V_17 [ 1 ] . V_25 = ( char * ) V_15 ;
V_13 = V_8 -> V_26 + 4 ;
V_14 = F_5 ( V_13 , V_22 ) ;
if ( ! V_14 )
goto V_23;
V_17 [ 0 ] . V_24 = V_13 ;
V_17 [ 0 ] . V_25 = ( char * ) V_14 ;
V_14 [ 0 ] = V_27 + V_8 -> V_28 ;
V_14 [ 1 ] = V_8 -> V_29 ;
V_14 [ 2 ] = V_8 -> V_26 ;
V_16 = V_14 [ 0 ] + V_14 [ 1 ] + V_14 [ 2 ] ;
for ( V_12 = 0 ; V_12 < V_8 -> V_26 ; V_12 ++ ) {
V_14 [ 3 + V_12 ] = V_8 -> V_14 [ V_12 ] ;
V_16 += V_14 [ 3 + V_12 ] ;
}
V_14 [ 3 + V_8 -> V_26 ] = V_16 ;
V_10 = F_6 ( V_5 -> V_30 , V_17 , 2 ) ;
if ( V_10 < 0 ) {
F_7 ( V_6 -> V_3 , L_1 , V_10 ) ;
goto V_23;
} else if ( V_10 != 2 ) {
F_7 ( V_6 -> V_3 , L_2 , V_10 ) ;
V_10 = - V_31 ;
goto V_23;
}
if ( V_17 [ 1 ] . V_25 [ 0 ] ) {
F_8 ( V_6 -> V_3 , L_3 ,
V_8 -> V_29 , V_17 [ 1 ] . V_25 [ 0 ] ) ;
V_10 = - V_32 ;
goto V_23;
}
V_16 = V_15 [ 0 ] + V_15 [ 1 ] ;
for ( V_12 = 0 ; V_12 < V_8 -> V_21 ; V_12 ++ ) {
V_8 -> V_15 [ V_12 ] = V_15 [ 2 + V_12 ] ;
V_16 += V_15 [ 2 + V_12 ] ;
}
F_9 ( V_6 -> V_3 , L_4 ,
V_17 [ 1 ] . V_24 , V_15 , V_16 ) ;
if ( V_16 != V_15 [ 2 + V_8 -> V_21 ] ) {
F_7 ( V_6 -> V_3 , L_5 ) ;
V_10 = - V_33 ;
goto V_23;
}
V_10 = 0 ;
V_23:
F_10 ( V_15 ) ;
F_10 ( V_14 ) ;
return V_10 ;
}
static int F_11 ( struct V_4 * V_5 ,
const struct V_34 * V_35 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_1 * V_6 = NULL ;
int V_36 ;
V_6 = F_12 ( V_3 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return - V_11 ;
F_13 ( V_5 , V_6 ) ;
V_6 -> V_37 = L_6 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_9 = V_5 ;
V_6 -> V_38 = V_5 -> V_38 ;
V_6 -> V_39 = F_4 ;
V_6 -> V_40 = V_5 -> V_37 ;
V_6 -> V_41 = V_5 -> V_30 -> V_37 ;
V_6 -> V_42 = & V_5 -> V_3 ;
V_36 = F_14 ( V_6 ) ;
if ( V_36 ) {
F_7 ( V_3 , L_7 ) ;
return V_36 ;
}
return 0 ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_18 ( V_6 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_20 ( V_6 ) ;
}
