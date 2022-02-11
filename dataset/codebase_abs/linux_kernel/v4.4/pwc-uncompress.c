int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , line , V_6 ;
void * V_7 , * V_8 ;
T_1 * V_9 ;
T_1 * V_10 , * V_11 , * V_12 ;
V_8 = F_2 ( & V_4 -> V_13 . V_14 , 0 ) ;
V_7 = V_4 -> V_15 + V_2 -> V_16 ;
if ( V_2 -> V_17 != V_18 )
{
struct V_19 * V_20 = V_8 ;
V_20 -> type = F_3 ( V_2 -> type ) ;
V_20 -> V_21 = F_3 ( V_2 -> V_21 ) ;
memcpy ( V_20 -> V_22 , V_2 -> V_23 , 4 ) ;
memcpy ( V_20 + 1 , V_7 , V_2 -> V_24 ) ;
F_4 ( & V_4 -> V_13 . V_14 , 0 ,
V_2 -> V_24 + sizeof( struct V_19 ) ) ;
return 0 ;
}
F_4 ( & V_4 -> V_13 . V_14 , 0 ,
V_2 -> V_25 * V_2 -> V_26 * 3 / 2 ) ;
if ( V_2 -> V_21 == 0 ) {
V_9 = ( T_1 * ) V_7 ;
V_5 = V_2 -> V_25 * V_2 -> V_26 ;
V_10 = ( T_1 * ) ( V_8 ) ;
V_11 = ( T_1 * ) ( V_8 + V_5 ) ;
V_12 = ( T_1 * ) ( V_8 + V_5 + V_5 / 4 ) ;
for ( line = 0 ; line < V_2 -> V_26 ; line ++ ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_25 ; V_6 += 4 ) {
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
return - V_27 ;
} else {
F_7 ( V_2 , V_7 , V_8 ) ;
}
return 0 ;
}
