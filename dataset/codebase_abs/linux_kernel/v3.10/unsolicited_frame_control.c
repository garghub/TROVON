void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
T_1 V_7 = V_2 -> V_8 ;
void * V_9 = V_2 -> V_10 ;
int V_11 ;
V_4 -> V_12 . V_13 = V_7 + V_14 ;
V_4 -> V_12 . V_15 = V_9 + V_14 ;
V_4 -> V_16 . V_13 = V_7 + V_14 + V_17 ;
V_4 -> V_16 . V_15 = V_9 + V_14 + V_17 ;
V_4 -> V_18 = 0 ;
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ ) {
V_6 = & V_4 -> V_20 . V_15 [ V_11 ] ;
V_4 -> V_16 . V_15 [ V_11 ] = V_7 ;
V_6 -> V_21 = V_9 ;
V_6 -> V_22 = & V_4 -> V_12 . V_15 [ V_11 ] ;
V_6 -> V_23 = V_24 ;
V_9 += V_25 ;
V_7 += V_25 ;
}
}
enum V_26 F_2 ( struct V_3 * V_4 ,
T_2 V_27 ,
void * * V_28 )
{
if ( V_27 < V_19 ) {
* V_28 = & V_4 -> V_20 . V_15 [ V_27 ] . V_22 -> V_29 ;
return V_30 ;
}
return V_31 ;
}
enum V_26 F_3 ( struct V_3 * V_4 ,
T_2 V_27 ,
void * * V_32 )
{
if ( V_27 < V_19 ) {
* V_32 = V_4 -> V_20 . V_15 [ V_27 ] . V_21 ;
return V_30 ;
}
return V_31 ;
}
bool F_4 ( struct V_3 * V_4 ,
T_2 V_27 )
{
T_2 V_33 ;
T_2 V_34 ;
V_33 = V_4 -> V_18 & ( V_19 - 1 ) ;
V_34 = V_4 -> V_18 & V_19 ;
while ( F_5 ( V_4 -> V_16 . V_15 [ V_33 ] ) == 0 &&
F_6 ( V_4 -> V_16 . V_15 [ V_33 ] ) == 0 &&
V_33 < V_19 )
V_33 ++ ;
F_7 ( V_33 >= V_19 ) ;
if ( V_27 >= V_19 )
return false ;
V_4 -> V_20 . V_15 [ V_27 ] . V_23 = V_35 ;
if ( V_33 != V_27 ) {
return false ;
}
while ( V_4 -> V_20 . V_15 [ V_33 ] . V_23 == V_35 ) {
V_4 -> V_20 . V_15 [ V_33 ] . V_23 = V_24 ;
if ( V_33 + 1 == V_19 - 1 ) {
V_34 ^= V_19 ;
V_33 = 0 ;
} else
V_33 ++ ;
}
V_4 -> V_18 = F_8 ( V_36 ) | V_34 | V_33 ;
return true ;
}
