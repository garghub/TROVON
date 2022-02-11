int F_1 ( struct V_1 * V_2 , const unsigned char * V_3 ,
unsigned char * V_4 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_7 ;
unsigned int V_11 ;
memset ( V_4 , 0 , V_6 -> V_10 . V_12 ) ;
F_2 ( V_9 -> V_13 , V_3 , V_6 -> V_10 . V_14 , V_4 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_10 . V_12 ; V_11 ++ )
V_4 [ V_11 ] ^= V_9 -> V_15 [ V_11 ] ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned char * V_16 , unsigned char * V_17 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_7 ;
unsigned int * V_18 = V_9 -> V_18 ;
int V_11 , V_19 ;
V_19 = F_4 ( V_9 -> V_13 , NULL , V_6 -> V_10 . V_14 , V_16 , V_17 ,
NULL , V_18 ) ;
if ( V_19 > 0 ) {
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ ) {
if ( V_18 [ V_11 ] < ( V_6 -> V_10 . V_14 * 8 ) )
V_3 [ V_18 [ V_11 ] >> 3 ] ^= ( 1 << ( V_18 [ V_11 ] & 7 ) ) ;
F_5 ( L_1 , V_20 ,
V_18 [ V_11 ] ) ;
}
} else if ( V_19 < 0 ) {
F_6 ( V_21 L_2 ) ;
V_19 = - 1 ;
}
return V_19 ;
}
struct V_8 *
F_7 ( struct V_1 * V_2 , unsigned int V_22 , unsigned int V_23 ,
struct V_24 * * V_25 )
{
unsigned int V_26 , V_27 , V_28 , V_11 ;
struct V_24 * V_29 ;
struct V_8 * V_9 = NULL ;
unsigned char * V_30 ;
if ( ! V_22 || ! V_23 ) {
F_6 ( V_31 L_3 ) ;
goto V_32;
}
V_26 = F_8 ( 1 + 8 * V_22 ) ;
V_27 = ( V_23 * 8 ) / V_26 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_33 ) ;
if ( ! V_9 )
goto V_32;
V_9 -> V_13 = F_10 ( V_26 , V_27 , 0 ) ;
if ( ! V_9 -> V_13 )
goto V_32;
if ( V_9 -> V_13 -> V_34 != V_23 ) {
F_6 ( V_31 L_4 ,
V_23 , V_9 -> V_13 -> V_34 ) ;
goto V_32;
}
V_28 = V_2 -> V_35 / V_22 ;
if ( ! * V_25 ) {
if ( V_2 -> V_36 < 64 ) {
F_6 ( V_31 L_5
L_6 , V_2 -> V_36 ) ;
goto V_32;
}
V_29 = & V_9 -> V_25 ;
V_29 -> V_23 = V_28 * V_23 ;
if ( V_29 -> V_23 + 2 > V_2 -> V_36 ) {
F_6 ( V_31 L_7
L_8 , V_2 -> V_36 ,
V_23 ) ;
goto V_32;
}
for ( V_11 = 0 ; V_11 < V_29 -> V_23 ; V_11 ++ )
V_29 -> V_37 [ V_11 ] = V_2 -> V_36 - V_29 -> V_23 + V_11 ;
V_29 -> V_38 [ 0 ] . V_39 = 2 ;
V_29 -> V_38 [ 0 ] . V_40 = V_2 -> V_36 - 2 - V_29 -> V_23 ;
* V_25 = V_29 ;
}
if ( 8 * ( V_22 + V_23 ) >= ( 1 << V_26 ) ) {
F_6 ( V_31 L_9 , V_22 ) ;
goto V_32;
}
if ( ( * V_25 ) -> V_23 != ( V_28 * V_23 ) ) {
F_6 ( V_31 L_10 ) ;
goto V_32;
}
V_9 -> V_15 = F_11 ( V_23 , V_33 ) ;
V_9 -> V_18 = F_11 ( V_27 * sizeof( * V_9 -> V_18 ) , V_33 ) ;
if ( ! V_9 -> V_15 || ! V_9 -> V_18 )
goto V_32;
V_30 = F_11 ( V_22 , V_33 ) ;
if ( ! V_30 )
goto V_32;
memset ( V_30 , 0xff , V_22 ) ;
memset ( V_9 -> V_15 , 0 , V_23 ) ;
F_2 ( V_9 -> V_13 , V_30 , V_22 , V_9 -> V_15 ) ;
F_12 ( V_30 ) ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ )
V_9 -> V_15 [ V_11 ] ^= 0xff ;
return V_9 ;
V_32:
F_13 ( V_9 ) ;
return NULL ;
}
void F_13 ( struct V_8 * V_9 )
{
if ( V_9 ) {
F_14 ( V_9 -> V_13 ) ;
F_12 ( V_9 -> V_18 ) ;
F_12 ( V_9 -> V_15 ) ;
F_12 ( V_9 ) ;
}
}
