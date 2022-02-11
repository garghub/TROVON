int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_3 * V_6 = V_4 ;
T_2 V_7 = V_5 - 1 ;
if ( V_5 < 1 )
return - 1 ;
V_4 += V_7 ;
for (; V_4 >= V_6 ; -- V_7 , -- V_4 ) {
if ( V_4 -> V_8 != ( V_9 + V_10 ) )
continue;
switch ( ( V_4 -> V_11 << 8 ) | V_4 -> V_12 ) {
case ( V_13 << 8 ) | V_14 :
if ( V_2 -> V_2 [ V_4 -> V_15 ] . V_16 == 0xffffffff ) {
fprintf ( V_17 , L_1 ,
V_2 -> V_2 [ V_4 -> V_15 ] . V_18 ) ;
return 1 ;
}
V_4 -> V_15 = V_2 -> V_2 [ V_4 -> V_15 ] . V_16 -
( V_7 + 1 ) ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
continue;
case ( V_19 << 8 ) | V_20 :
if ( V_2 -> V_2 [ V_4 -> V_15 ] . V_16 != 0xffffffff ) {
fprintf ( V_17 , L_2 ,
V_2 -> V_2 [ V_4 -> V_15 ] . V_18 ) ;
return 1 ;
}
V_2 -> V_2 [ V_4 -> V_15 ] . V_16 = V_7 ;
V_4 -> V_15 = 0 ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = 0 ;
continue;
}
}
return 0 ;
}
T_3 F_2 ( struct V_1 * V_2 , const char * V_18 )
{
struct V_21 * V_6 = V_2 -> V_2 , * V_22 ;
int V_23 ;
if ( V_2 -> V_5 == 0 ) {
V_6 -> V_18 = V_18 ;
V_6 -> V_16 = 0xffffffff ;
V_2 -> V_5 ++ ;
return 0 ;
}
V_22 = V_6 + V_2 -> V_5 ;
for ( V_23 = 0 ; V_6 < V_22 ; ++ V_6 , ++ V_23 ) {
if ( ! strcmp ( V_18 , V_6 -> V_18 ) )
return V_23 ;
}
V_6 -> V_18 = V_18 ;
V_6 -> V_16 = 0xffffffff ;
V_2 -> V_5 ++ ;
return V_23 ;
}
void F_3 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_3 * V_22 = V_4 + V_5 ;
for ( ; V_4 < V_22 ; ++ V_4 )
printf ( L_3 ,
V_4 -> V_8 , V_4 -> V_11 , V_4 -> V_12 , V_4 -> V_15 ) ;
}
