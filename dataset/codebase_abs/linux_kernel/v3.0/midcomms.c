static void F_1 ( void * V_1 , const void * V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 )
{
unsigned V_6 = V_4 ;
if ( ( V_6 + V_3 ) > V_5 )
V_6 = V_5 - V_3 ;
memcpy ( V_1 , V_2 + V_3 , V_6 ) ;
V_4 -= V_6 ;
if ( V_4 )
memcpy ( V_1 + V_6 , V_2 , V_4 ) ;
}
int F_2 ( int V_7 , const void * V_2 ,
unsigned V_3 , unsigned V_4 , unsigned V_5 )
{
union {
unsigned char V_8 [ V_9 ] ;
union V_10 V_11 ;
} V_12 ;
union V_10 * V_11 = & V_12 . V_11 ;
int V_13 = 0 ;
int V_14 = 0 ;
T_1 V_15 ;
T_2 V_16 ;
while ( V_4 > sizeof( struct V_17 ) ) {
F_1 ( V_11 , V_2 , V_3 , sizeof( struct V_17 ) ,
V_5 ) ;
V_15 = F_3 ( V_11 -> V_18 . V_19 ) ;
V_16 = V_11 -> V_18 . V_20 ;
V_14 = - V_21 ;
if ( V_15 < sizeof( struct V_17 ) )
break;
if ( V_11 -> V_18 . V_22 == V_23 ) {
if ( V_15 < sizeof( struct V_24 ) )
break;
} else {
if ( V_15 < sizeof( struct V_25 ) )
break;
}
V_14 = - V_26 ;
if ( V_15 > V_27 . V_28 ) {
F_4 ( L_1 ,
V_15 , V_7 , V_4 ) ;
break;
}
V_14 = 0 ;
if ( V_15 > V_4 )
break;
if ( V_15 > sizeof( V_12 ) && V_11 == & V_12 . V_11 ) {
V_11 = F_5 ( V_27 . V_28 , V_29 ) ;
if ( V_11 == NULL )
return V_13 ;
}
F_1 ( V_11 , V_2 , V_3 , V_15 , V_5 ) ;
F_6 ( V_16 != V_11 -> V_18 . V_20 ) ;
V_13 += V_15 ;
V_3 += V_15 ;
V_3 &= ( V_5 - 1 ) ;
V_4 -= V_15 ;
F_7 ( V_11 , V_7 ) ;
}
if ( V_11 != & V_12 . V_11 )
F_8 ( V_11 ) ;
return V_14 ? V_14 : V_13 ;
}
