int F_1 ( struct V_1 * V_2 , const unsigned char * V_3 ,
unsigned char * V_4 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
unsigned int V_11 ;
memset ( V_4 , 0 , V_6 -> V_9 . V_12 ) ;
F_3 ( V_8 -> V_13 , V_3 , V_6 -> V_9 . V_14 , V_4 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_9 . V_12 ; V_11 ++ )
V_4 [ V_11 ] ^= V_8 -> V_15 [ V_11 ] ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned char * V_16 , unsigned char * V_17 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 . V_10 ;
unsigned int * V_18 = V_8 -> V_18 ;
int V_11 , V_19 ;
V_19 = F_5 ( V_8 -> V_13 , NULL , V_6 -> V_9 . V_14 , V_16 , V_17 ,
NULL , V_18 ) ;
if ( V_19 > 0 ) {
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ ) {
if ( V_18 [ V_11 ] < ( V_6 -> V_9 . V_14 * 8 ) )
V_3 [ V_18 [ V_11 ] >> 3 ] ^= ( 1 << ( V_18 [ V_11 ] & 7 ) ) ;
F_6 ( L_1 , V_20 ,
V_18 [ V_11 ] ) ;
}
} else if ( V_19 < 0 ) {
F_7 ( V_21 L_2 ) ;
V_19 = - V_22 ;
}
return V_19 ;
}
struct V_7 * F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_23 = F_2 ( V_2 ) ;
unsigned int V_24 , V_25 , V_26 , V_11 ;
struct V_7 * V_8 = NULL ;
unsigned char * V_27 ;
unsigned int V_28 = V_23 -> V_9 . V_14 ;
unsigned int V_29 = V_23 -> V_9 . V_12 ;
unsigned int V_30 = V_23 -> V_9 . V_31 ;
if ( ! V_29 && V_30 ) {
V_29 = F_9 ( V_30 * F_10 ( 8 * V_28 ) , 8 ) ;
V_23 -> V_9 . V_12 = V_29 ;
}
if ( ! V_28 || ! V_29 ) {
F_7 ( V_32 L_3 ) ;
goto V_33;
}
V_24 = F_10 ( 1 + 8 * V_28 ) ;
V_25 = ( V_29 * 8 ) / V_24 ;
V_8 = F_11 ( sizeof( * V_8 ) , V_34 ) ;
if ( ! V_8 )
goto V_33;
V_8 -> V_13 = F_12 ( V_24 , V_25 , 0 ) ;
if ( ! V_8 -> V_13 )
goto V_33;
if ( V_8 -> V_13 -> V_35 != V_29 ) {
F_7 ( V_32 L_4 ,
V_29 , V_8 -> V_13 -> V_35 ) ;
goto V_33;
}
V_26 = V_2 -> V_36 / V_28 ;
if ( ! V_2 -> V_37 ) {
F_13 ( L_5 ) ;
goto V_33;
}
if ( 8 * ( V_28 + V_29 ) >= ( 1 << V_24 ) ) {
F_7 ( V_32 L_6 , V_28 ) ;
goto V_33;
}
V_23 -> V_9 . V_38 = V_26 ;
V_23 -> V_9 . V_39 = V_26 * V_29 ;
if ( F_14 ( V_2 ) != ( V_26 * V_29 ) ) {
F_7 ( V_32 L_7 ) ;
goto V_33;
}
V_8 -> V_15 = F_15 ( V_29 , V_34 ) ;
V_8 -> V_18 = F_15 ( V_25 * sizeof( * V_8 -> V_18 ) , V_34 ) ;
if ( ! V_8 -> V_15 || ! V_8 -> V_18 )
goto V_33;
V_27 = F_15 ( V_28 , V_34 ) ;
if ( ! V_27 )
goto V_33;
memset ( V_27 , 0xff , V_28 ) ;
memset ( V_8 -> V_15 , 0 , V_29 ) ;
F_3 ( V_8 -> V_13 , V_27 , V_28 , V_8 -> V_15 ) ;
F_16 ( V_27 ) ;
for ( V_11 = 0 ; V_11 < V_29 ; V_11 ++ )
V_8 -> V_15 [ V_11 ] ^= 0xff ;
if ( ! V_30 )
V_23 -> V_9 . V_31 = ( V_29 * 8 ) / F_10 ( 8 * V_28 ) ;
return V_8 ;
V_33:
F_17 ( V_8 ) ;
return NULL ;
}
void F_17 ( struct V_7 * V_8 )
{
if ( V_8 ) {
F_18 ( V_8 -> V_13 ) ;
F_16 ( V_8 -> V_18 ) ;
F_16 ( V_8 -> V_15 ) ;
F_16 ( V_8 ) ;
}
}
