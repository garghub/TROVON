static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_2 V_5 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
0xa0 , V_6 , V_3 , 0x00 , V_4 , V_5 , 5000 ) ;
}
int F_4 ( struct V_1 * V_2 , const struct V_7 * V_8 , int type )
{
struct V_9 * V_10 ;
T_2 * V_11 ;
int V_12 , V_13 = 0 ;
T_1 V_14 = V_15 [ type ] . V_14 ;
V_11 = F_5 ( sizeof( * V_10 ) , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
V_10 = (struct V_9 * ) V_11 ;
V_11 [ 0 ] = 1 ;
if ( F_1 ( V_2 , V_14 , V_11 , 1 ) != 1 )
F_6 ( L_1 ) ;
while ( ( V_12 = F_7 ( V_8 , V_10 , & V_13 ) ) > 0 ) {
F_8 ( L_2 , V_10 -> V_3 , V_10 -> V_5 , V_10 -> V_18 ) ;
V_12 = F_1 ( V_2 , V_10 -> V_3 , V_10 -> V_4 , V_10 -> V_5 ) ;
if ( V_12 != V_10 -> V_5 ) {
F_6 ( L_3 ,
V_12 , V_10 -> V_5 ) ;
V_12 = - V_19 ;
break;
}
}
if ( V_12 < 0 ) {
F_6 ( L_4 , V_13 , V_12 ) ;
F_9 ( V_11 ) ;
return V_12 ;
}
if ( V_12 == 0 ) {
V_11 [ 0 ] = 0 ;
if ( F_1 ( V_2 , V_14 , V_11 , 1 ) != 1 ) {
F_6 ( L_5 ) ;
V_12 = - V_19 ;
}
} else
V_12 = - V_20 ;
F_9 ( V_11 ) ;
return V_12 ;
}
int F_10 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
int V_12 ;
const struct V_7 * V_8 = NULL ;
if ( ( V_12 = F_11 ( & V_8 , V_22 -> V_7 , & V_2 -> V_23 ) ) != 0 ) {
F_6 ( L_6 ,
V_22 -> V_7 , V_12 ) ;
return V_12 ;
}
F_12 ( L_7 , V_22 -> V_7 ) ;
switch ( V_22 -> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
V_12 = F_4 ( V_2 , V_8 , V_22 -> V_24 ) ;
break;
case V_28 :
if ( V_22 -> V_29 )
V_12 = V_22 -> V_29 ( V_2 , V_8 ) ;
else {
F_6 ( L_8 ) ;
V_12 = - V_19 ;
}
break;
default:
V_12 = - V_19 ;
break;
}
F_13 ( V_8 ) ;
return V_12 ;
}
int F_7 ( const struct V_7 * V_8 , struct V_9 * V_10 ,
int * V_13 )
{
T_2 * V_30 = ( T_2 * ) & V_8 -> V_4 [ * V_13 ] ;
int V_31 = 4 ;
if ( * V_13 >= V_8 -> V_32 )
return 0 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_5 = V_30 [ 0 ] ;
if ( ( * V_13 + V_10 -> V_5 + 4 ) >= V_8 -> V_32 )
return - V_19 ;
V_10 -> V_3 = V_30 [ 1 ] | ( V_30 [ 2 ] << 8 ) ;
V_10 -> type = V_30 [ 3 ] ;
if ( V_10 -> type == 0x04 ) {
V_10 -> V_3 |= ( V_30 [ 4 ] << 24 ) | ( V_30 [ 5 ] << 16 ) ;
}
memcpy ( V_10 -> V_4 , & V_30 [ V_31 ] , V_10 -> V_5 ) ;
V_10 -> V_18 = V_30 [ V_10 -> V_5 + V_31 ] ;
* V_13 += V_10 -> V_5 + 5 ;
return * V_13 ;
}
