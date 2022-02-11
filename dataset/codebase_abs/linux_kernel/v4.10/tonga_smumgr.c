static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 1 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_4 ( V_2 -> V_4 , V_5 ,
V_8 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_9 , V_10 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_11 , V_12 , 1 ) ;
F_4 ( V_2 -> V_4 , V_5 ,
V_13 , 0 ) ;
F_5 ( V_2 , V_14 ,
V_15 , V_16 , 1 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 , V_14 ,
V_17 , V_18 , 0 ) ;
if ( 1 != F_8 ( V_2 -> V_4 ,
V_5 , V_17 , V_19 ) ) {
F_9 ( V_20 L_1 ) ;
return - V_21 ;
}
F_5 ( V_2 , V_14 ,
V_22 , V_16 , 1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_7 ( V_2 , V_14 ,
V_15 , V_23 , 0 ) ;
F_4 ( V_2 -> V_4 , V_5 ,
V_13 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 1 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 != 0 )
return V_3 ;
F_11 ( V_2 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_9 , V_10 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 0 ) ;
F_5 ( V_2 , V_14 ,
V_22 , V_16 , 1 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( F_13 ( V_2 ) ||
F_14 ( V_2 -> V_4 ) ) ) {
if ( 0 == F_8 ( V_2 -> V_4 , V_5 ,
V_24 , V_25 ) ) {
V_3 = F_10 ( V_2 ) ;
if ( V_3 )
return V_3 ;
} else {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
}
}
V_3 = F_15 ( V_2 ) ;
return V_3 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = (struct V_26 * ) ( V_2 -> V_28 ) ;
int V_29 ;
if ( F_17 ( V_2 ) )
return - V_21 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ )
V_27 -> V_31 [ V_29 ] = 30 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_26 * V_32 = NULL ;
V_32 = F_19 ( sizeof( struct V_26 ) , V_33 ) ;
if ( V_32 == NULL )
return - V_34 ;
V_2 -> V_28 = V_32 ;
V_2 -> V_35 = & V_36 ;
return 0 ;
}
