static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
T_2 V_5 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
0xa0 , V_6 , V_3 , 0x00 , V_4 , V_5 , 5000 ) ;
}
static int F_4 ( const struct V_7 * V_8 ,
struct V_9 * V_10 , int * V_11 )
{
T_2 * V_12 = ( T_2 * ) & V_8 -> V_4 [ * V_11 ] ;
int V_13 = 4 ;
if ( * V_11 >= V_8 -> V_14 )
return 0 ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_10 -> V_5 = V_12 [ 0 ] ;
if ( ( * V_11 + V_10 -> V_5 + 4 ) >= V_8 -> V_14 )
return - V_15 ;
V_10 -> V_3 = V_12 [ 1 ] | ( V_12 [ 2 ] << 8 ) ;
V_10 -> type = V_12 [ 3 ] ;
if ( V_10 -> type == 0x04 ) {
V_10 -> V_3 |= ( V_12 [ 4 ] << 24 ) | ( V_12 [ 5 ] << 16 ) ;
}
memcpy ( V_10 -> V_4 , & V_12 [ V_13 ] , V_10 -> V_5 ) ;
V_10 -> V_16 = V_12 [ V_10 -> V_5 + V_13 ] ;
* V_11 += V_10 -> V_5 + 5 ;
return * V_11 ;
}
int F_5 ( struct V_1 * V_2 ,
const struct V_7 * V_8 , int type )
{
struct V_9 * V_10 ;
int V_17 , V_11 = 0 ;
V_10 = F_6 ( sizeof( struct V_9 ) , V_18 ) ;
if ( ! V_10 ) {
F_7 ( & V_2 -> V_19 , L_1 , V_20 ) ;
return - V_21 ;
}
V_10 -> V_4 [ 0 ] = 1 ;
V_17 = F_1 ( V_2 , V_22 [ type ] . V_23 , V_10 -> V_4 , 1 ) ;
if ( V_17 != 1 ) {
F_7 ( & V_2 -> V_19 , L_2 ,
V_20 , V_17 ) ;
V_17 = - V_24 ;
goto V_25;
}
for (; ; ) {
V_17 = F_4 ( V_8 , V_10 , & V_11 ) ;
if ( V_17 < 0 )
goto V_25;
else if ( V_17 == 0 )
break;
V_17 = F_1 ( V_2 , V_10 -> V_3 , V_10 -> V_4 , V_10 -> V_5 ) ;
if ( V_17 < 0 ) {
goto V_25;
} else if ( V_17 != V_10 -> V_5 ) {
F_7 ( & V_2 -> V_19 ,
L_3 ,
V_20 , V_17 , V_10 -> V_5 ) ;
V_17 = - V_24 ;
goto V_25;
}
}
V_10 -> V_4 [ 0 ] = 0 ;
V_17 = F_1 ( V_2 , V_22 [ type ] . V_23 , V_10 -> V_4 , 1 ) ;
if ( V_17 != 1 ) {
F_7 ( & V_2 -> V_19 , L_4 ,
V_20 , V_17 ) ;
V_17 = - V_24 ;
goto V_25;
}
V_17 = 0 ;
V_25:
F_8 ( V_10 ) ;
return V_17 ;
}
