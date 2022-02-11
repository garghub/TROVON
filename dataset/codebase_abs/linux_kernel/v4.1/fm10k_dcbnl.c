static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_4 -> V_6 = V_7 ;
V_4 -> V_8 = 0 ;
memset ( V_4 -> V_9 , 0 , sizeof( V_4 -> V_9 ) ) ;
memset ( V_4 -> V_10 , 0 , sizeof( V_4 -> V_10 ) ) ;
memset ( V_4 -> V_11 , V_12 , sizeof( V_4 -> V_11 ) ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
V_4 -> V_13 [ V_5 ] = F_2 ( V_2 , V_5 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_14 = 0 ;
int V_5 , V_15 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
if ( V_4 -> V_9 [ V_5 ] || V_4 -> V_10 [ V_5 ] )
return - V_16 ;
if ( V_4 -> V_11 [ V_5 ] != V_12 )
return - V_16 ;
if ( V_4 -> V_13 [ V_5 ] > V_14 )
V_14 = V_4 -> V_13 [ V_5 ] ;
}
if ( V_14 )
V_14 ++ ;
if ( V_14 > V_7 )
return - V_16 ;
if ( V_14 != F_4 ( V_2 ) ) {
V_15 = F_5 ( V_2 , V_14 ) ;
if ( V_15 )
return V_15 ;
}
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
F_6 ( V_2 , V_5 , V_4 -> V_13 [ V_5 ] ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 * V_20 = F_8 ( V_2 ) ;
V_18 -> V_21 = V_7 ;
V_18 -> V_22 = V_20 -> V_22 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_19 * V_20 = F_8 ( V_2 ) ;
V_20 -> V_22 = V_18 -> V_22 ;
if ( F_10 ( V_2 ) )
F_11 ( V_20 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_1 T_2 * V_2 )
{
return V_23 | V_24 ;
}
static T_1 F_13 ( struct V_1 T_2 * V_2 , T_1 V_25 )
{
return ( V_25 != ( V_23 | V_24 ) ) ? 1 : 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
#ifdef F_15
struct V_19 * V_20 = F_8 ( V_2 ) ;
struct V_26 * V_27 = & V_20 -> V_27 ;
if ( V_27 -> V_28 . type == V_29 )
V_2 -> V_30 = & V_31 ;
#endif
}
