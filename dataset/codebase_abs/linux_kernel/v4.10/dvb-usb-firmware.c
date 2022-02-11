static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , T_2 V_5 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
0xa0 , V_6 , V_3 , 0x00 , V_4 , V_5 , 5000 ) ;
}
int F_4 ( struct V_1 * V_2 , const struct V_7 * V_8 , int type )
{
struct V_9 V_10 ;
T_2 V_11 ;
int V_12 , V_13 = 0 ;
V_11 = 1 ;
if ( ( V_12 = F_1 ( V_2 , V_14 [ type ] . V_15 , & V_11 , 1 ) ) != 1 )
F_5 ( L_1 ) ;
while ( ( V_12 = F_6 ( V_8 , & V_10 , & V_13 ) ) > 0 ) {
F_7 ( L_2 , V_10 . V_3 , V_10 . V_5 , V_10 . V_16 ) ;
V_12 = F_1 ( V_2 , V_10 . V_3 , V_10 . V_4 , V_10 . V_5 ) ;
if ( V_12 != V_10 . V_5 ) {
F_5 ( L_3 ,
V_12 , V_10 . V_5 ) ;
V_12 = - V_17 ;
break;
}
}
if ( V_12 < 0 ) {
F_5 ( L_4 , V_13 , V_12 ) ;
return V_12 ;
}
if ( V_12 == 0 ) {
V_11 = 0 ;
if ( V_12 || F_1 ( V_2 , V_14 [ type ] . V_15 , & V_11 , 1 ) != 1 ) {
F_5 ( L_5 ) ;
V_12 = - V_17 ;
}
} else
V_12 = - V_18 ;
return V_12 ;
}
int F_8 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_12 ;
const struct V_7 * V_8 = NULL ;
if ( ( V_12 = F_9 ( & V_8 , V_20 -> V_7 , & V_2 -> V_21 ) ) != 0 ) {
F_5 ( L_6 ,
V_20 -> V_7 , V_12 ) ;
return V_12 ;
}
F_10 ( L_7 , V_20 -> V_7 ) ;
switch ( V_20 -> V_22 ) {
case V_23 :
case V_24 :
case V_25 :
V_12 = F_4 ( V_2 , V_8 , V_20 -> V_22 ) ;
break;
case V_26 :
if ( V_20 -> V_27 )
V_12 = V_20 -> V_27 ( V_2 , V_8 ) ;
else {
F_5 ( L_8 ) ;
V_12 = - V_17 ;
}
break;
default:
V_12 = - V_17 ;
break;
}
F_11 ( V_8 ) ;
return V_12 ;
}
int F_6 ( const struct V_7 * V_8 , struct V_9 * V_10 ,
int * V_13 )
{
T_2 * V_28 = ( T_2 * ) & V_8 -> V_4 [ * V_13 ] ;
int V_29 = 4 ;
if ( * V_13 >= V_8 -> V_30 )
return 0 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_5 = V_28 [ 0 ] ;
if ( ( * V_13 + V_10 -> V_5 + 4 ) >= V_8 -> V_30 )
return - V_17 ;
V_10 -> V_3 = V_28 [ 1 ] | ( V_28 [ 2 ] << 8 ) ;
V_10 -> type = V_28 [ 3 ] ;
if ( V_10 -> type == 0x04 ) {
V_10 -> V_3 |= ( V_28 [ 4 ] << 24 ) | ( V_28 [ 5 ] << 16 ) ;
}
memcpy ( V_10 -> V_4 , & V_28 [ V_29 ] , V_10 -> V_5 ) ;
V_10 -> V_16 = V_28 [ V_10 -> V_5 + V_29 ] ;
* V_13 += V_10 -> V_5 + 5 ;
return * V_13 ;
}
