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
F_5 ( V_20 , L_1 ,
V_21 , V_18 [ V_11 ] ) ;
}
} else if ( V_19 < 0 ) {
F_6 ( V_22 L_2 ) ;
V_19 = - 1 ;
}
return V_19 ;
}
struct V_8 *
F_7 ( struct V_1 * V_2 , unsigned int V_23 , unsigned int V_24 ,
struct V_25 * * V_26 )
{
unsigned int V_27 , V_28 , V_29 , V_11 ;
struct V_25 * V_30 ;
struct V_8 * V_9 = NULL ;
unsigned char * V_31 ;
if ( ! V_23 || ! V_24 ) {
F_6 ( V_32 L_3 ) ;
goto V_33;
}
V_27 = F_8 ( 1 + 8 * V_23 ) ;
V_28 = ( V_24 * 8 ) / V_27 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_34 ) ;
if ( ! V_9 )
goto V_33;
V_9 -> V_13 = F_10 ( V_27 , V_28 , 0 ) ;
if ( ! V_9 -> V_13 )
goto V_33;
if ( V_9 -> V_13 -> V_35 != V_24 ) {
F_6 ( V_32 L_4 ,
V_24 , V_9 -> V_13 -> V_35 ) ;
goto V_33;
}
V_29 = V_2 -> V_36 / V_23 ;
if ( ! * V_26 ) {
if ( V_2 -> V_37 < 64 ) {
F_6 ( V_32 L_5
L_6 , V_2 -> V_37 ) ;
goto V_33;
}
V_30 = & V_9 -> V_26 ;
V_30 -> V_24 = V_29 * V_24 ;
if ( V_30 -> V_24 + 2 > V_2 -> V_37 ) {
F_6 ( V_32 L_7
L_8 , V_2 -> V_37 ,
V_24 ) ;
goto V_33;
}
for ( V_11 = 0 ; V_11 < V_30 -> V_24 ; V_11 ++ )
V_30 -> V_38 [ V_11 ] = V_2 -> V_37 - V_30 -> V_24 + V_11 ;
V_30 -> V_39 [ 0 ] . V_40 = 2 ;
V_30 -> V_39 [ 0 ] . V_41 = V_2 -> V_37 - 2 - V_30 -> V_24 ;
* V_26 = V_30 ;
}
if ( 8 * ( V_23 + V_24 ) >= ( 1 << V_27 ) ) {
F_6 ( V_32 L_9 , V_23 ) ;
goto V_33;
}
if ( ( * V_26 ) -> V_24 != ( V_29 * V_24 ) ) {
F_6 ( V_32 L_10 ) ;
goto V_33;
}
V_9 -> V_15 = F_11 ( V_24 , V_34 ) ;
V_9 -> V_18 = F_11 ( V_28 * sizeof( * V_9 -> V_18 ) , V_34 ) ;
if ( ! V_9 -> V_15 || ! V_9 -> V_18 )
goto V_33;
V_31 = F_11 ( V_23 , V_34 ) ;
if ( ! V_31 )
goto V_33;
memset ( V_31 , 0xff , V_23 ) ;
memset ( V_9 -> V_15 , 0 , V_24 ) ;
F_2 ( V_9 -> V_13 , V_31 , V_23 , V_9 -> V_15 ) ;
F_12 ( V_31 ) ;
for ( V_11 = 0 ; V_11 < V_24 ; V_11 ++ )
V_9 -> V_15 [ V_11 ] ^= 0xff ;
return V_9 ;
V_33:
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
