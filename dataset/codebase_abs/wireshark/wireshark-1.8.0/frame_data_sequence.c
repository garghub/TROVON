T_1 *
F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( sizeof *V_1 ) ;
V_1 -> V_2 = 0 ;
V_1 -> V_3 = NULL ;
return V_1 ;
}
T_2 *
F_3 ( T_1 * V_1 , T_2 * V_4 )
{
T_2 * V_5 ;
T_2 * * V_6 ;
T_2 * * * V_7 ;
T_2 * * * * V_8 ;
T_2 * V_9 ;
if ( V_1 -> V_2 == 0 ) {
V_5 = F_2 ( ( sizeof *V_5 ) * V_10 ) ;
V_9 = & V_5 [ 0 ] ;
V_1 -> V_3 = V_5 ;
} else if ( V_1 -> V_2 < V_10 ) {
V_5 = V_1 -> V_3 ;
V_9 = & V_5 [ V_1 -> V_2 ] ;
} else if ( V_1 -> V_2 == V_10 ) {
V_6 = F_2 ( ( sizeof *V_6 ) * V_10 ) ;
memset ( V_6 , 0 , ( sizeof *V_6 ) * V_10 ) ;
V_6 [ 0 ] = V_1 -> V_3 ;
V_5 = F_2 ( ( sizeof *V_5 ) * V_10 ) ;
V_6 [ 1 ] = V_5 ;
V_9 = & V_5 [ 0 ] ;
V_1 -> V_3 = V_6 ;
} else if ( V_1 -> V_2 < V_10 * V_10 ) {
V_6 = V_1 -> V_3 ;
V_5 = V_6 [ V_1 -> V_2 >> V_11 ] ;
if ( V_5 == NULL ) {
V_5 = F_2 ( ( sizeof *V_5 ) * V_10 ) ;
V_6 [ V_1 -> V_2 >> V_11 ] = V_5 ;
}
V_9 = & V_5 [ F_4 ( V_1 -> V_2 ) ] ;
} else if ( V_1 -> V_2 == V_10 * V_10 ) {
V_7 = F_2 ( ( sizeof *V_7 ) * V_10 ) ;
memset ( V_7 , 0 , ( sizeof *V_7 ) * V_10 ) ;
V_7 [ 0 ] = V_1 -> V_3 ;
V_6 = F_2 ( ( sizeof *V_6 ) * V_10 ) ;
memset ( V_6 , 0 , ( sizeof *V_6 ) * V_10 ) ;
V_7 [ 1 ] = V_6 ;
V_5 = F_2 ( ( sizeof *V_5 ) * V_10 ) ;
V_6 [ 0 ] = V_5 ;
V_9 = & V_5 [ 0 ] ;
V_1 -> V_3 = V_7 ;
} else if ( V_1 -> V_2 < V_10 * V_10 * V_10 ) {
V_7 = V_1 -> V_3 ;
V_6 = V_7 [ V_1 -> V_2 >> ( V_11 + V_11 ) ] ;
if ( V_6 == NULL ) {
V_6 = F_2 ( ( sizeof *V_6 ) * V_10 ) ;
memset ( V_6 , 0 , ( sizeof *V_6 ) * V_10 ) ;
V_7 [ V_1 -> V_2 >> ( V_11 + V_11 ) ] = V_6 ;
}
V_5 = V_6 [ F_5 ( V_1 -> V_2 ) ] ;
if ( V_5 == NULL ) {
V_5 = F_2 ( ( sizeof *V_5 ) * V_10 ) ;
V_6 [ F_5 ( V_1 -> V_2 ) ] = V_5 ;
}
V_9 = & V_5 [ F_4 ( V_1 -> V_2 ) ] ;
} else if ( V_1 -> V_2 == V_10 * V_10 * V_10 ) {
V_8 = F_2 ( ( sizeof *V_8 ) * V_10 ) ;
memset ( V_8 , 0 , ( sizeof *V_8 ) * V_10 ) ;
V_8 [ 0 ] = V_1 -> V_3 ;
V_7 = F_2 ( ( sizeof *V_7 ) * V_10 ) ;
memset ( V_7 , 0 , ( sizeof *V_7 ) * V_10 ) ;
V_8 [ 1 ] = V_7 ;
V_6 = F_2 ( ( sizeof *V_6 ) * V_10 ) ;
memset ( V_6 , 0 , ( sizeof *V_6 ) * V_10 ) ;
V_7 [ 0 ] = V_6 ;
V_5 = F_2 ( ( sizeof *V_5 ) * V_10 ) ;
V_6 [ 0 ] = V_5 ;
V_9 = & V_5 [ 0 ] ;
V_1 -> V_3 = V_8 ;
} else {
V_8 = V_1 -> V_3 ;
V_7 = V_8 [ F_6 ( V_1 -> V_2 ) ] ;
if ( V_7 == NULL ) {
V_7 = F_2 ( ( sizeof *V_7 ) * V_10 ) ;
memset ( V_7 , 0 , ( sizeof *V_7 ) * V_10 ) ;
V_8 [ F_6 ( V_1 -> V_2 ) ] = V_7 ;
}
V_6 = V_7 [ F_7 ( V_1 -> V_2 ) ] ;
if ( V_6 == NULL ) {
V_6 = F_2 ( ( sizeof *V_6 ) * V_10 ) ;
memset ( V_6 , 0 , ( sizeof *V_6 ) * V_10 ) ;
V_7 [ F_7 ( V_1 -> V_2 ) ] = V_6 ;
}
V_5 = V_6 [ F_5 ( V_1 -> V_2 ) ] ;
if ( V_5 == NULL ) {
V_5 = F_2 ( ( sizeof *V_5 ) * V_10 ) ;
V_6 [ F_5 ( V_1 -> V_2 ) ] = V_5 ;
}
V_9 = & V_5 [ F_4 ( V_1 -> V_2 ) ] ;
}
* V_9 = * V_4 ;
V_1 -> V_2 ++ ;
return V_9 ;
}
T_2 *
F_8 ( T_1 * V_1 , T_3 V_12 )
{
T_2 * V_5 ;
T_2 * * V_6 ;
T_2 * * * V_7 ;
T_2 * * * * V_8 ;
if ( V_12 == 0 ) {
return NULL ;
}
V_12 -- ;
if ( V_12 >= V_1 -> V_2 ) {
return NULL ;
}
if ( V_1 -> V_2 <= V_10 ) {
V_5 = V_1 -> V_3 ;
return & V_5 [ V_12 ] ;
}
if ( V_1 -> V_2 <= V_10 * V_10 ) {
V_6 = V_1 -> V_3 ;
V_5 = V_6 [ V_12 >> V_11 ] ;
return & V_5 [ F_4 ( V_12 ) ] ;
}
if ( V_1 -> V_2 <= V_10 * V_10 * V_10 ) {
V_7 = V_1 -> V_3 ;
V_6 = V_7 [ V_12 >> ( V_11 + V_11 ) ] ;
V_5 = V_6 [ ( V_12 >> V_11 ) & ( V_10 - 1 ) ] ;
return & V_5 [ F_4 ( V_12 ) ] ;
}
V_8 = V_1 -> V_3 ;
V_7 = V_8 [ V_12 >> ( V_11 + V_11 + V_11 ) ] ;
V_6 = V_7 [ ( V_12 >> ( V_11 + V_11 ) ) & ( V_10 - 1 ) ] ;
V_5 = V_6 [ ( V_12 >> V_11 ) & ( V_10 - 1 ) ] ;
return & V_5 [ F_4 ( V_12 ) ] ;
}
void
F_9 ( T_1 * V_1 )
{
T_2 * * V_6 ;
T_2 * * * V_7 ;
T_2 * * * * V_8 ;
T_4 V_13 , V_14 , V_15 ;
if ( V_1 -> V_2 == 0 ) {
return;
}
if ( V_1 -> V_2 <= V_10 ) {
F_10 ( V_1 -> V_3 ) ;
} else if ( V_1 -> V_2 <= V_10 * V_10 ) {
V_6 = V_1 -> V_3 ;
for ( V_13 = 0 ; V_13 < V_10 && V_6 [ V_13 ] != NULL ; V_13 ++ )
F_10 ( V_6 [ V_13 ] ) ;
F_10 ( V_6 ) ;
} else if ( V_1 -> V_2 <= V_10 * V_10 * V_10 ) {
V_7 = V_1 -> V_3 ;
for ( V_13 = 0 ; V_13 < V_10 && V_7 [ V_13 ] != NULL ; V_13 ++ ) {
V_6 = V_7 [ V_13 ] ;
for ( V_14 = 0 ; V_14 < V_10 && V_6 [ V_13 ] != NULL ; V_14 ++ )
F_10 ( V_6 [ V_14 ] ) ;
F_10 ( V_6 ) ;
}
F_10 ( V_7 ) ;
return;
} else {
V_8 = V_1 -> V_3 ;
for ( V_13 = 0 ; V_13 < V_10 && V_8 [ V_13 ] != NULL ; V_13 ++ ) {
V_7 = V_8 [ V_13 ] ;
for ( V_14 = 0 ; V_14 < V_10 && V_7 [ V_13 ] != NULL ; V_14 ++ ) {
V_6 = V_7 [ V_14 ] ;
for ( V_15 = 0 ; V_15 < V_10 && V_6 [ V_15 ] != NULL ; V_15 ++ )
F_10 ( V_6 [ V_15 ] ) ;
}
F_10 ( V_7 ) ;
}
F_10 ( V_8 ) ;
}
F_10 ( V_1 ) ;
}
