int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
T_1 V_7 , V_8 , V_9 ;
T_2 V_10 ;
T_3 V_11 ;
void * V_12 ;
V_7 = V_13 * V_14 ;
V_8 = V_13 * sizeof( struct V_15 ) ;
V_11 = V_7 + V_8 + V_13 * sizeof( T_2 ) ;
V_12 = F_2 ( & V_2 -> V_16 -> V_17 , V_11 , & V_10 , V_18 ) ;
if ( ! V_12 )
return - V_19 ;
V_4 -> V_20 . V_21 = V_10 + V_7 ;
V_4 -> V_20 . V_22 = V_12 + V_7 ;
V_4 -> V_23 . V_21 = V_10 + V_7 + V_8 ;
V_4 -> V_23 . V_22 = V_12 + V_7 + V_8 ;
V_4 -> V_24 = 0 ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
V_6 = & V_4 -> V_25 . V_22 [ V_9 ] ;
V_4 -> V_23 . V_22 [ V_9 ] = V_10 ;
V_6 -> V_26 = V_12 ;
V_6 -> V_27 = & V_4 -> V_20 . V_22 [ V_9 ] ;
V_6 -> V_28 = V_29 ;
V_12 += V_14 ;
V_10 += V_14 ;
}
return 0 ;
}
enum V_30 F_3 ( struct V_3 * V_4 ,
T_1 V_31 ,
void * * V_32 )
{
if ( V_31 < V_13 ) {
* V_32 = & V_4 -> V_25 . V_22 [ V_31 ] . V_27 -> V_33 ;
return V_34 ;
}
return V_35 ;
}
enum V_30 F_4 ( struct V_3 * V_4 ,
T_1 V_31 ,
void * * V_36 )
{
if ( V_31 < V_13 ) {
* V_36 = V_4 -> V_25 . V_22 [ V_31 ] . V_26 ;
return V_34 ;
}
return V_35 ;
}
bool F_5 ( struct V_3 * V_4 ,
T_1 V_31 )
{
T_1 V_37 ;
T_1 V_38 ;
V_37 = V_4 -> V_24 & ( V_13 - 1 ) ;
V_38 = V_4 -> V_24 & V_13 ;
while ( F_6 ( V_4 -> V_23 . V_22 [ V_37 ] ) == 0 &&
F_7 ( V_4 -> V_23 . V_22 [ V_37 ] ) == 0 &&
V_37 < V_13 )
V_37 ++ ;
F_8 ( V_37 >= V_13 ) ;
if ( V_31 >= V_13 )
return false ;
V_4 -> V_25 . V_22 [ V_31 ] . V_28 = V_39 ;
if ( V_37 != V_31 ) {
return false ;
}
while ( V_4 -> V_25 . V_22 [ V_37 ] . V_28 == V_39 ) {
V_4 -> V_25 . V_22 [ V_37 ] . V_28 = V_29 ;
if ( V_37 + 1 == V_13 - 1 ) {
V_38 ^= V_13 ;
V_37 = 0 ;
} else
V_37 ++ ;
}
V_4 -> V_24 = F_9 ( V_40 ) | V_38 | V_37 ;
return true ;
}
