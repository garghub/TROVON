static T_1 F_1 ( T_1 V_1 )
{
return sizeof( struct V_2 ) +
V_1 * sizeof( struct V_3 ) ;
}
struct V_2 * F_2 ( T_1 V_1 )
{
struct V_2 * V_4 ;
if ( V_1 == 0 )
V_1 = V_5 ;
V_4 = F_3 ( F_1 ( V_1 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_1 = V_1 ;
V_4 -> V_7 = 0 ;
return V_4 ;
}
void F_4 ( struct V_2 * V_4 )
{
F_5 ( V_4 ) ;
}
void F_6 ( struct V_2 * * V_8 ,
struct V_3 V_9 )
{
struct V_2 * V_4 = * V_8 ;
if ( F_7 ( V_4 -> V_7 >= V_4 -> V_1 ) ) {
struct V_2 * V_10 ;
T_1 V_11 = V_4 -> V_1 * V_12 ;
T_1 V_13 = F_1 ( V_11 ) ;
V_10 = F_8 ( V_4 , V_13 , V_6 ) ;
if ( ! V_10 )
return;
V_10 -> V_1 = V_11 ;
* V_8 = V_4 = V_10 ;
}
V_4 -> V_14 [ V_4 -> V_7 ] = V_9 ;
V_4 -> V_7 ++ ;
}
struct V_3 F_9 ( struct V_2 * V_4 ,
struct V_3 V_15 )
{
struct V_3 V_9 = V_16 ;
T_1 V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_7 ; V_17 ++ ) {
if ( F_10 ( V_4 -> V_14 [ V_17 ] , V_15 ) ) {
V_9 = V_4 -> V_14 [ V_17 ] ;
V_4 -> V_7 -- ;
V_4 -> V_14 [ V_17 ] = V_4 -> V_14 [ V_4 -> V_7 ] ;
V_4 -> V_14 [ V_4 -> V_7 ] = V_16 ;
break;
}
}
return V_9 ;
}
struct V_3 F_11 ( struct V_2 * V_4 )
{
struct V_3 V_9 = V_16 ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 -- ;
V_9 = V_4 -> V_14 [ V_4 -> V_7 ] ;
V_4 -> V_14 [ V_4 -> V_7 ] = V_16 ;
}
return V_9 ;
}
struct V_3
F_12 ( const struct V_2 * V_4 , T_1 V_18 )
{
if ( F_7 ( V_18 >= V_4 -> V_7 ) )
return V_16 ;
return V_4 -> V_14 [ V_18 ] ;
}
bool F_13 ( const struct V_2 * V_4 ,
struct V_3 V_15 )
{
T_1 V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_7 ; V_17 ++ )
if ( F_10 ( V_4 -> V_14 [ V_17 ] , V_15 ) )
return true ;
return false ;
}
struct V_3 * F_14 ( struct V_2 * V_4 )
{
if ( V_4 -> V_7 )
return V_4 -> V_14 ;
return NULL ;
}
