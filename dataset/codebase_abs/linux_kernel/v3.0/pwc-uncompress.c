int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 , line , V_6 , V_7 ;
void * V_8 , * V_9 ;
T_1 * V_10 ;
T_1 * V_11 , * V_12 , * V_13 ;
if ( V_2 == NULL )
return - V_14 ;
V_4 = V_2 -> V_15 ;
if ( V_4 == NULL )
return - V_14 ;
V_9 = V_2 -> V_16 ;
V_9 += V_2 -> V_17 [ V_2 -> V_18 ] . V_19 ;
V_8 = V_4 -> V_20 + V_2 -> V_21 ;
if ( V_2 -> V_22 != V_23 )
{
struct V_24 * V_25 = V_9 ;
V_25 -> type = F_2 ( V_2 -> type ) ;
V_25 -> V_26 = F_2 ( V_2 -> V_26 ) ;
memcpy ( V_25 -> V_27 , V_2 -> V_28 , 4 ) ;
memcpy ( V_25 + 1 , V_8 , V_2 -> V_29 ) ;
return 0 ;
}
if ( V_2 -> V_26 == 0 ) {
V_10 = ( T_1 * ) V_8 ;
V_5 = V_2 -> V_30 . V_31 * V_2 -> V_30 . V_32 ;
V_7 = V_2 -> V_30 . V_31 * V_2 -> V_19 . V_32 + V_2 -> V_19 . V_31 ;
V_11 = ( T_1 * ) ( V_9 + V_7 ) ;
V_7 = V_2 -> V_30 . V_31 * V_2 -> V_19 . V_32 / 4 + V_2 -> V_19 . V_31 / 2 ;
V_12 = ( T_1 * ) ( V_9 + V_5 + V_7 ) ;
V_13 = ( T_1 * ) ( V_9 + V_5 + V_5 / 4 + V_7 ) ;
V_7 = ( V_2 -> V_30 . V_31 - V_2 -> V_9 . V_31 ) / 2 ;
for ( line = 0 ; line < V_2 -> V_9 . V_32 ; line ++ ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_9 . V_31 ; V_6 += 4 ) {
* V_11 ++ = * V_10 ++ ;
* V_11 ++ = * V_10 ++ ;
if ( line & 1 )
* V_13 ++ = * V_10 ++ ;
else
* V_12 ++ = * V_10 ++ ;
}
V_11 += V_7 ;
if ( line & 1 )
V_13 += ( V_7 >> 1 ) ;
else
V_12 += ( V_7 >> 1 ) ;
}
return 0 ;
}
if ( V_2 -> V_33 == V_34 && V_2 -> V_35 == 5 && V_2 -> V_36 ) {
F_3 ( L_1 ) ;
return - V_37 ;
}
if ( F_4 ( V_2 -> type ) ) {
F_3 ( L_2 ) ;
return - V_37 ;
} else {
F_5 ( V_2 , V_8 , V_9 , V_38 ) ;
}
return 0 ;
}
