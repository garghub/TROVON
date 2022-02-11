int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
if ( V_2 -> V_5 . V_6 == 0 && V_2 -> V_5 . V_7 == 0 )
return 0 ;
if ( V_2 -> V_8 & V_9 )
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
if ( ( V_2 -> V_5 . V_10 [ V_4 ] . V_3 == V_3 ) &&
! ( V_2 -> V_5 . V_10 [ V_4 ] . V_11 & V_12 ) &&
( ! ( V_2 -> V_13 & V_14 ) ||
! ( V_2 -> V_5 . V_10 [ V_4 ] . V_11 & V_15 ) ) )
return V_9 ;
if ( V_2 -> V_8 & V_16 )
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_7 ; V_4 ++ )
if ( ( V_2 -> V_5 . V_17 [ V_4 ] . V_3 == V_3 ) &&
! ( V_2 -> V_5 . V_17 [ V_4 ] . V_11 & V_12 ) )
return V_16 ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
if ( V_2 -> V_5 . V_6 == 0 && V_2 -> V_5 . V_7 == 0 )
return - 1 ;
if ( V_2 -> V_8 & V_9 )
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
if ( V_2 -> V_5 . V_10 [ V_4 ] . V_3 == V_3 )
return V_4 ;
if ( V_2 -> V_8 & V_16 )
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_7 ; V_4 ++ )
if ( V_2 -> V_5 . V_17 [ V_4 ] . V_3 == V_3 )
return V_4 ;
return - 1 ;
}
T_2 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_18 * V_19 ;
if ( V_2 -> V_5 . V_6 == 0 && V_2 -> V_5 . V_7 == 0 )
return 0 ;
V_19 = F_4 ( V_2 , V_3 ) ;
if ( ! V_19 -> V_3 )
return 0 ;
return V_19 -> V_20 ;
}
T_1 F_5 ( struct V_1 * V_2 , T_2 V_20 )
{
int V_4 ;
if ( V_2 -> V_5 . V_6 == 0 && V_2 -> V_5 . V_7 == 0 )
return 0 ;
V_20 /= 100000 ;
if ( V_2 -> V_8 & V_9 )
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
if ( V_2 -> V_5 . V_10 [ V_4 ] . V_20 == V_20 )
return V_2 -> V_5 . V_10 [ V_4 ] . V_3 ;
if ( V_2 -> V_8 & V_16 )
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_7 ; V_4 ++ )
if ( V_2 -> V_5 . V_17 [ V_4 ] . V_20 == V_20 )
return V_2 -> V_5 . V_17 [ V_4 ] . V_3 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 ,
const struct V_21 * V_5 )
{
memcpy ( V_2 -> V_5 . V_22 , V_5 -> V_22 , 3 ) ;
V_2 -> V_5 . V_22 [ 3 ] = '\0' ;
V_2 -> V_5 . V_6 = V_5 -> V_6 ;
V_2 -> V_5 . V_7 = V_5 -> V_7 ;
memcpy ( V_2 -> V_5 . V_10 , V_5 -> V_10 , V_5 -> V_6 *
sizeof( struct V_18 ) ) ;
memcpy ( V_2 -> V_5 . V_17 , V_5 -> V_17 , V_2 -> V_5 . V_7 *
sizeof( struct V_18 ) ) ;
}
const struct V_21 * F_7 ( struct V_1 * V_2 )
{
return & V_2 -> V_5 ;
}
T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_23 = F_2 ( V_2 , V_3 ) ;
if ( V_23 == - 1 )
return V_12 ;
if ( V_3 <= V_24 )
return V_2 -> V_5 . V_10 [ V_23 ] . V_11 ;
return V_2 -> V_5 . V_17 [ V_23 ] . V_11 ;
}
const struct V_18 * F_4 ( struct V_1
* V_2 , T_1 V_3 )
{
int V_23 = F_2 ( V_2 , V_3 ) ;
if ( V_23 == - 1 )
return & V_25 ;
if ( V_3 <= V_24 )
return & V_2 -> V_5 . V_10 [ V_23 ] ;
return & V_2 -> V_5 . V_17 [ V_23 ] ;
}
