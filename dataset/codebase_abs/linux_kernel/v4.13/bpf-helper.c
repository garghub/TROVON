int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_1 V_6 ;
if ( V_5 < 1 || V_5 > V_7 )
return - 1 ;
for ( V_6 = 0 ; V_6 < V_5 ; ++ V_6 ) {
T_1 V_8 = V_5 - V_6 - 1 ;
struct V_3 * V_9 = & V_4 [ V_8 ] ;
if ( V_9 -> V_10 != ( V_11 + V_12 ) )
continue;
switch ( ( V_9 -> V_13 << 8 ) | V_9 -> V_14 ) {
case ( V_15 << 8 ) | V_16 :
if ( V_2 -> V_2 [ V_9 -> V_17 ] . V_18 == 0xffffffff ) {
fprintf ( V_19 , L_1 ,
V_2 -> V_2 [ V_9 -> V_17 ] . V_20 ) ;
return 1 ;
}
V_9 -> V_17 = V_2 -> V_2 [ V_9 -> V_17 ] . V_18 -
( V_8 + 1 ) ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
continue;
case ( V_21 << 8 ) | V_22 :
if ( V_2 -> V_2 [ V_9 -> V_17 ] . V_18 != 0xffffffff ) {
fprintf ( V_19 , L_2 ,
V_2 -> V_2 [ V_9 -> V_17 ] . V_20 ) ;
return 1 ;
}
V_2 -> V_2 [ V_9 -> V_17 ] . V_18 = V_8 ;
V_9 -> V_17 = 0 ;
V_9 -> V_13 = 0 ;
V_9 -> V_14 = 0 ;
continue;
}
}
return 0 ;
}
T_2 F_2 ( struct V_1 * V_2 , const char * V_20 )
{
struct V_23 * V_24 = V_2 -> V_2 , * V_25 ;
int V_26 ;
if ( V_2 -> V_5 == V_27 ) {
fprintf ( V_19 , L_3 ) ;
exit ( 1 ) ;
}
if ( V_2 -> V_5 == 0 ) {
V_24 -> V_20 = V_20 ;
V_24 -> V_18 = 0xffffffff ;
V_2 -> V_5 ++ ;
return 0 ;
}
V_25 = V_24 + V_2 -> V_5 ;
for ( V_26 = 0 ; V_24 < V_25 ; ++ V_24 , ++ V_26 ) {
if ( ! strcmp ( V_20 , V_24 -> V_20 ) )
return V_26 ;
}
V_24 -> V_20 = V_20 ;
V_24 -> V_18 = 0xffffffff ;
V_2 -> V_5 ++ ;
return V_26 ;
}
void F_3 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_3 * V_25 = V_4 + V_5 ;
for ( ; V_4 < V_25 ; ++ V_4 )
printf ( L_4 ,
V_4 -> V_10 , V_4 -> V_13 , V_4 -> V_14 , V_4 -> V_17 ) ;
}
