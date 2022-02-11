int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , line , V_6 ;
void * V_7 , * V_8 ;
T_1 * V_9 ;
T_1 * V_10 , * V_11 , * V_12 ;
V_8 = F_2 ( & V_4 -> V_13 , 0 ) ;
V_7 = V_4 -> V_14 + V_2 -> V_15 ;
if ( V_2 -> V_16 != V_17 )
{
struct V_18 * V_19 = V_8 ;
V_19 -> type = F_3 ( V_2 -> type ) ;
V_19 -> V_20 = F_3 ( V_2 -> V_20 ) ;
memcpy ( V_19 -> V_21 , V_2 -> V_22 , 4 ) ;
memcpy ( V_19 + 1 , V_7 , V_2 -> V_23 ) ;
F_4 ( & V_4 -> V_13 , 0 ,
V_2 -> V_23 + sizeof( struct V_18 ) ) ;
return 0 ;
}
F_4 ( & V_4 -> V_13 , 0 ,
V_2 -> V_24 * V_2 -> V_25 * 3 / 2 ) ;
if ( V_2 -> V_20 == 0 ) {
V_9 = ( T_1 * ) V_7 ;
V_5 = V_2 -> V_24 * V_2 -> V_25 ;
V_10 = ( T_1 * ) ( V_8 ) ;
V_11 = ( T_1 * ) ( V_8 + V_5 ) ;
V_12 = ( T_1 * ) ( V_8 + V_5 + V_5 / 4 ) ;
for ( line = 0 ; line < V_2 -> V_25 ; line ++ ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_24 ; V_6 += 4 ) {
* V_10 ++ = * V_9 ++ ;
* V_10 ++ = * V_9 ++ ;
if ( line & 1 )
* V_12 ++ = * V_9 ++ ;
else
* V_11 ++ = * V_9 ++ ;
}
}
return 0 ;
}
if ( F_5 ( V_2 -> type ) ) {
F_6 ( L_1 ) ;
return - V_26 ;
} else {
F_7 ( V_2 , V_7 , V_8 ) ;
}
return 0 ;
}
