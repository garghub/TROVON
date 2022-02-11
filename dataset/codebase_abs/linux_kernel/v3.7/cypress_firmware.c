static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_2 V_5 )
{
F_2 ( V_2 ,
0xa0 , V_6 , V_3 , 0x00 , V_4 , V_5 ) ;
return F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
0xa0 , V_6 , V_3 , 0x00 , V_4 , V_5 , 5000 ) ;
}
int F_5 ( struct V_1 * V_2 ,
const struct V_7 * V_8 , int type )
{
struct V_9 * V_10 ;
int V_11 , V_12 = 0 ;
V_10 = F_6 ( sizeof( struct V_9 ) , V_13 ) ;
if ( ! V_10 ) {
F_7 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
V_10 -> V_4 [ 0 ] = 1 ;
V_11 = F_1 ( V_2 , V_17 [ type ] . V_18 , V_10 -> V_4 , 1 ) ;
if ( V_11 != 1 ) {
F_7 ( & V_2 -> V_14 , L_2 ,
V_15 , V_11 ) ;
V_11 = - V_19 ;
goto V_20;
}
for (; ; ) {
V_11 = F_8 ( V_8 , V_10 , & V_12 ) ;
if ( V_11 < 0 )
goto V_20;
else if ( V_11 == 0 )
break;
V_11 = F_1 ( V_2 , V_10 -> V_3 , V_10 -> V_4 , V_10 -> V_5 ) ;
if ( V_11 < 0 ) {
goto V_20;
} else if ( V_11 != V_10 -> V_5 ) {
F_7 ( & V_2 -> V_14 , L_3 \
L_4 \
L_5 ,
V_15 , V_11 , V_10 -> V_5 ) ;
V_11 = - V_19 ;
goto V_20;
}
}
V_10 -> V_4 [ 0 ] = 0 ;
V_11 = F_1 ( V_2 , V_17 [ type ] . V_18 , V_10 -> V_4 , 1 ) ;
if ( V_11 != 1 ) {
F_7 ( & V_2 -> V_14 , L_6 ,
V_15 , V_11 ) ;
V_11 = - V_19 ;
goto V_20;
}
V_11 = 0 ;
V_20:
F_9 ( V_10 ) ;
return V_11 ;
}
int F_8 ( const struct V_7 * V_8 , struct V_9 * V_10 ,
int * V_12 )
{
T_2 * V_21 = ( T_2 * ) & V_8 -> V_4 [ * V_12 ] ;
int V_22 = 4 ;
if ( * V_12 >= V_8 -> V_23 )
return 0 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_5 = V_21 [ 0 ] ;
if ( ( * V_12 + V_10 -> V_5 + 4 ) >= V_8 -> V_23 )
return - V_24 ;
V_10 -> V_3 = V_21 [ 1 ] | ( V_21 [ 2 ] << 8 ) ;
V_10 -> type = V_21 [ 3 ] ;
if ( V_10 -> type == 0x04 ) {
V_10 -> V_3 |= ( V_21 [ 4 ] << 24 ) | ( V_21 [ 5 ] << 16 ) ;
}
memcpy ( V_10 -> V_4 , & V_21 [ V_22 ] , V_10 -> V_5 ) ;
V_10 -> V_25 = V_21 [ V_10 -> V_5 + V_22 ] ;
* V_12 += V_10 -> V_5 + 5 ;
return * V_12 ;
}
