void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 = 0 , V_5 = 0 , V_6 , V_7 ;
union V_8 * V_9 , * V_10 ;
unsigned long * V_11 = NULL ;
void * V_12 ;
if ( ! V_13 )
return;
V_9 = F_2 ( V_2 -> V_14 , & V_15 , 1 , 0 ,
NULL , V_16 ) ;
if ( ! V_9 )
return;
if ( ! V_9 -> V_17 . V_18 )
goto V_19;
if ( V_9 -> V_17 . V_20 [ 0 ] != 3 ) {
F_3 ( V_2 -> V_14 , V_21
L_1 ,
V_9 -> V_17 . V_18 , V_9 -> V_17 . V_20 ) ;
goto V_19;
}
F_4 ( V_9 ) ;
V_9 = F_2 ( V_2 -> V_14 , & V_15 , 1 , 1 ,
NULL , V_22 ) ;
if ( ! V_9 )
return;
V_6 = V_9 -> V_23 . V_24 / 2 ;
if ( ! V_6 )
goto V_19;
V_11 = F_5 ( F_6 ( V_6 ) , sizeof( long ) , V_25 ) ;
if ( ! V_11 )
goto V_19;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
union V_8 * V_26 = & V_9 -> V_23 . V_27 [ V_3 * 2 ] ;
union V_8 * V_28 = & V_9 -> V_23 . V_27 [ V_3 * 2 + 1 ] ;
if ( V_26 -> type != V_29 ||
( V_28 -> type != V_30 &&
V_28 -> type != V_16 ) )
continue;
F_7 ( V_3 , V_11 ) ;
V_5 += V_26 -> string . V_18 + 1 ;
if ( V_28 -> type == V_16 )
V_5 += V_28 -> V_17 . V_18 ;
}
V_7 = F_8 ( V_11 , V_6 ) ;
if ( V_6 > V_7 )
F_3 ( V_2 -> V_14 , V_21
L_2 ,
V_6 - V_7 ) ;
if ( V_7 == 0 )
goto V_19;
V_5 += ( 1 + 3 * V_7 ) * sizeof( union V_8 ) ;
V_10 = F_9 ( V_5 ) ;
if ( ! V_10 )
goto V_19;
V_10 -> type = V_22 ;
V_10 -> V_23 . V_24 = V_7 ;
V_10 -> V_23 . V_27 = & V_10 [ 1 ] ;
V_12 = & V_10 [ 1 + 3 * V_7 ] ;
F_10 (i, valid, numprops) {
union V_8 * V_26 = & V_9 -> V_23 . V_27 [ V_3 * 2 ] ;
union V_8 * V_28 = & V_9 -> V_23 . V_27 [ V_3 * 2 + 1 ] ;
unsigned int V_31 = 1 + V_7 + V_4 * 2 ;
unsigned int V_32 = V_31 + 1 ;
V_10 [ 1 + V_4 ] . type = V_22 ;
V_10 [ 1 + V_4 ] . V_23 . V_24 = 2 ;
V_10 [ 1 + V_4 ] . V_23 . V_27 = & V_10 [ V_31 ] ;
V_10 [ V_31 ] . type = V_29 ;
V_10 [ V_31 ] . string . V_18 = V_26 -> string . V_18 ;
V_10 [ V_31 ] . string . V_20 = V_12 ;
memcpy ( V_12 , V_26 -> string . V_20 , V_26 -> string . V_18 ) ;
V_12 += V_26 -> string . V_18 + 1 ;
V_10 [ V_32 ] . type = V_28 -> type ;
if ( V_28 -> type == V_30 ) {
V_10 [ V_32 ] . integer . V_33 = V_28 -> integer . V_33 ;
} else {
V_10 [ V_32 ] . V_17 . V_18 = V_28 -> V_17 . V_18 ;
V_10 [ V_32 ] . V_17 . V_20 = V_12 ;
memcpy ( V_12 , V_28 -> V_17 . V_20 ,
V_28 -> V_17 . V_18 ) ;
V_12 += V_28 -> V_17 . V_18 ;
}
V_4 ++ ;
}
F_11 ( V_12 != ( void * ) V_10 + V_5 ) ;
V_2 -> V_34 . V_35 = V_10 ;
V_2 -> V_34 . V_20 = V_10 ;
V_19:
F_4 ( V_9 ) ;
F_12 ( V_11 ) ;
}
