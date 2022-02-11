static int F_1 ( struct V_1 * V_2 , T_1 V_3 [ V_4 ] )
{
int V_5 ;
F_2 ( V_2 -> V_6 , L_1 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] ,
V_3 [ 5 ] , V_3 [ 6 ] , V_3 [ 7 ] , V_3 [ 8 ] ) ;
F_3 ( & V_2 -> V_7 ) ;
V_5 = F_4 ( V_2 -> V_6 , V_3 [ 0 ] , V_3 , V_4 ,
V_8 , V_9 ) ;
F_5 ( & V_2 -> V_7 ) ;
return V_5 < 0 ? V_5 : 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 [ V_4 ] )
{
int V_5 ;
F_3 ( & V_2 -> V_7 ) ;
V_5 = F_4 ( V_2 -> V_6 , V_3 [ 0 ] , V_3 , V_4 ,
V_8 , V_9 ) ;
if ( V_5 < 0 )
goto V_10;
V_5 = F_4 ( V_2 -> V_6 , V_3 [ 0 ] , V_3 , V_4 ,
V_8 , V_11 ) ;
if ( V_5 < 0 )
goto V_10;
V_5 = 0 ;
F_2 ( V_2 -> V_6 , L_2 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] ,
V_3 [ 5 ] , V_3 [ 6 ] , V_3 [ 7 ] , V_3 [ 8 ] ) ;
V_10:
F_5 ( & V_2 -> V_7 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_3 [ V_4 ] = { V_12 , 'v' , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_10 ;
V_10 = F_6 ( V_2 , V_3 ) ;
if ( V_10 )
return V_10 ;
V_2 -> V_13 . V_14 = V_3 [ 3 ] ;
V_2 -> V_13 . V_15 = V_3 [ 4 ] ;
return 0 ;
}
static int F_8 ( struct V_16 * V_17 )
{
T_1 V_3 [ V_4 ] = { V_12 , 'c' , 0 , 0 , 0 , 0 , 0 , V_17 -> V_18 , 0 } ;
V_3 [ 2 ] = V_17 -> V_19 . V_20 . V_21 ;
V_3 [ 3 ] = V_17 -> V_22 . V_20 . V_21 ;
V_3 [ 4 ] = V_17 -> V_23 . V_20 . V_21 ;
return F_1 ( V_17 -> V_2 , V_3 ) ;
}
static int F_9 ( struct V_24 * V_20 ,
enum V_25 V_21 )
{
struct V_26 * V_27 = F_10 ( V_20 , struct V_26 , V_20 ) ;
return F_8 ( V_27 -> V_17 ) ;
}
static int F_11 ( struct V_26 * V_27 , const char * V_28 ,
struct V_16 * V_17 , int V_15 )
{
snprintf ( V_27 -> V_29 , sizeof( V_27 -> V_29 ) , L_3 ,
V_15 , V_28 , V_17 -> V_18 ) ;
V_27 -> V_20 . V_29 = V_27 -> V_29 ;
V_27 -> V_20 . V_30 = 255 ;
V_27 -> V_20 . V_31 = F_9 ;
V_27 -> V_20 . V_32 = V_33 ;
V_27 -> V_17 = V_17 ;
return F_12 ( & V_17 -> V_2 -> V_6 -> V_34 , & V_27 -> V_20 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
const int V_15 = ( (struct V_35 * ) V_17 -> V_2 -> V_6 -> V_35 ) -> V_15 ;
int V_10 ;
V_10 = F_11 ( & V_17 -> V_19 , L_4 , V_17 , V_15 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_11 ( & V_17 -> V_22 , L_5 , V_17 , V_15 ) ;
if ( V_10 )
return V_10 ;
return F_11 ( & V_17 -> V_23 , L_6 , V_17 , V_15 ) ;
}
static int F_14 ( struct V_36 * V_6 , const struct V_37 * V_38 )
{
struct V_1 * V_2 ;
int V_39 , V_10 ;
V_2 = F_15 ( & V_6 -> V_34 , sizeof( struct V_1 ) ,
V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_2 -> V_6 = V_6 ;
F_16 ( V_6 , V_2 ) ;
V_10 = F_17 ( V_6 ) ;
if ( V_10 )
return V_10 ;
F_18 ( & V_2 -> V_7 ) ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 )
return V_10 ;
F_2 ( V_6 , L_7 ,
V_2 -> V_13 . V_14 , V_2 -> V_13 . V_15 ) ;
for ( V_39 = 0 ; V_39 < F_19 ( V_42 ) && ! V_2 -> V_43 ; ++ V_39 )
if ( V_42 [ V_39 ] . V_14 == V_2 -> V_13 . V_14 )
V_2 -> V_43 = & V_42 [ V_39 ] ;
if ( ! V_2 -> V_43 ) {
F_20 ( V_6 , L_8 , V_2 -> V_13 . V_14 ) ;
return - V_44 ;
}
V_2 -> V_17 = F_15 ( & V_6 -> V_34 ,
sizeof( struct V_16 ) * V_2 -> V_43 -> V_45 ,
V_40 ) ;
if ( ! V_2 -> V_17 )
return - V_41 ;
V_10 = F_21 ( V_6 , V_46 ) ;
if ( V_10 )
return V_10 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_43 -> V_45 ; ++ V_39 ) {
struct V_16 * V_17 = V_2 -> V_17 + V_39 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_18 = V_2 -> V_43 -> V_47 + V_39 ;
V_10 = F_13 ( V_17 ) ;
if ( V_10 ) {
F_22 ( V_6 ) ;
return V_10 ;
}
}
return 0 ;
}
