int
F_1 ( struct V_1 * V_2 , T_1 V_3 , struct V_4 * * V_5 )
{
int V_6 = F_2 ( & V_2 -> V_7 , 0 , 1 , V_3 , V_3 , 1 , V_5 ) ;
if ( V_6 )
* V_5 = NULL ;
return V_6 ;
}
void
F_3 ( struct V_1 * V_2 , struct V_4 * * V_5 )
{
F_4 ( & V_2 -> V_7 , V_5 ) ;
}
void
F_5 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_9 )
{
const T_1 V_10 = V_8 + V_9 - 1 ;
F_6 ( ( V_8 > V_10 ) || ( V_10 >= V_2 -> V_11 ) ) ;
V_2 -> V_12 -> V_13 ( V_2 , V_8 , V_10 ) ;
V_2 -> V_12 -> V_14 ( V_2 ) ;
}
int
F_7 ( struct V_1 * V_2 , int V_15 , const T_1 V_16 [ 4 ] )
{
memcpy ( V_2 -> V_17 [ V_15 ] , V_16 , sizeof( V_2 -> V_17 [ V_15 ] ) ) ;
V_2 -> V_12 -> V_18 ( V_2 , V_15 , V_16 ) ;
return V_15 ;
}
int
F_8 ( struct V_1 * V_2 , int V_15 , const T_1 V_19 )
{
V_2 -> V_20 [ V_15 ] = V_19 ;
V_2 -> V_12 -> V_21 ( V_2 , V_15 , V_19 ) ;
return V_15 ;
}
static void
F_9 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_1 ( V_23 ) ;
V_2 -> V_12 -> V_24 ( V_2 ) ;
}
static int
F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_1 ( V_23 ) ;
return V_2 -> V_12 -> V_25 ( V_2 ) ;
}
static int
F_11 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_1 ( V_23 ) ;
int V_26 ;
for ( V_26 = V_2 -> V_27 ; V_26 <= V_2 -> V_28 ; V_26 ++ ) {
V_2 -> V_12 -> V_18 ( V_2 , V_26 , V_2 -> V_17 [ V_26 ] ) ;
V_2 -> V_12 -> V_21 ( V_2 , V_26 , V_2 -> V_20 [ V_26 ] ) ;
}
V_2 -> V_12 -> V_29 ( V_2 ) ;
return 0 ;
}
static void *
F_12 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_1 ( V_23 ) ;
struct V_30 * V_31 = V_2 -> V_23 . V_32 -> V_33 -> V_31 ;
F_13 ( & V_2 -> V_7 ) ;
if ( V_31 )
F_4 ( & V_31 -> V_34 , & V_2 -> V_35 ) ;
return V_2 ;
}
int
F_14 ( const struct V_36 * V_12 , struct V_37 * V_32 ,
int V_15 , struct V_1 * * V_38 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_38 = F_15 ( sizeof( * V_2 ) , V_39 ) ) )
return - V_40 ;
F_16 ( & V_1 , V_32 , V_15 , 0 , & V_2 -> V_23 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_27 = 1 ;
V_2 -> V_28 = F_17 ( V_12 -> V_41 , V_42 ) - 1 ;
return 0 ;
}
