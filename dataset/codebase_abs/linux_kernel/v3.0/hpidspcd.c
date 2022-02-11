short F_1 ( T_1 V_1 , struct V_2 * V_3 ,
T_1 * V_4 )
{
const struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 V_8 ;
char V_9 [ 20 ] ;
int V_10 ;
sprintf ( V_9 , L_1 , V_1 ) ;
V_10 = F_2 ( & V_6 , V_9 ,
& V_3 -> V_11 -> V_12 ) ;
if ( V_10 != 0 ) {
F_3 ( V_13 , & V_3 -> V_11 -> V_12 ,
L_2 , V_10 ,
V_9 ) ;
goto V_14;
}
if ( V_6 -> V_15 < sizeof( V_8 ) ) {
F_3 ( V_13 , & V_3 -> V_11 -> V_12 ,
L_3 , V_9 ) ;
goto V_16;
}
memcpy ( & V_8 , V_6 -> V_17 , sizeof( V_8 ) ) ;
if ( V_8 . V_1 != V_1 ) {
F_3 ( V_13 , & V_3 -> V_11 -> V_12 ,
L_4 , V_8 . V_1 ,
V_1 ) ;
goto V_16;
}
if ( V_8 . V_15 != V_6 -> V_15 ) {
F_3 ( V_13 , & V_3 -> V_11 -> V_12 ,
L_5 , V_8 . V_15 ,
( unsigned long ) V_6 -> V_15 ) ;
goto V_16;
}
if ( V_8 . V_18 / 100 != V_19 / 100 ) {
F_3 ( V_13 , & V_3 -> V_11 -> V_12 ,
L_6
L_7 , V_8 . V_18 ,
V_19 ) ;
goto V_16;
}
if ( V_8 . V_18 != V_19 ) {
F_3 ( V_20 , & V_3 -> V_11 -> V_12 ,
L_8 ,
V_8 . V_18 , V_19 ) ;
}
F_4 ( V_21 , L_9 , V_9 ) ;
V_3 -> V_6 = V_6 ;
V_3 -> V_22 = V_8 . V_15 / sizeof( T_1 ) ;
V_3 -> V_23 = sizeof( V_8 ) / sizeof( T_1 ) ;
V_3 -> V_18 = V_8 . V_18 ;
V_3 -> V_24 = V_8 . V_24 ;
return 0 ;
V_16:
F_5 ( V_6 ) ;
V_14:
V_3 -> V_6 = NULL ;
V_3 -> V_22 = 0 ;
return V_25 ;
}
void F_6 ( struct V_2 * V_3 )
{
if ( V_3 -> V_6 != NULL ) {
F_4 ( V_21 , L_10 ) ;
F_5 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
}
void F_7 ( struct V_2 * V_3 )
{
V_3 -> V_23 = sizeof( struct V_7 ) / sizeof( T_1 ) ;
}
short F_8 ( struct V_2 * V_3 , T_1 * V_26 )
{
if ( V_3 -> V_23 + 1 > V_3 -> V_22 )
return V_27 ;
* V_26 = ( ( T_1 * ) ( V_3 -> V_6 -> V_17 ) ) [ V_3 ->
V_23 ] ;
V_3 -> V_23 ++ ;
return 0 ;
}
short F_9 ( T_2 V_28 ,
struct V_2 * V_3 , T_1 * * V_29 )
{
if ( V_3 -> V_23 + V_28 >
V_3 -> V_22 )
return V_27 ;
* V_29 =
( ( T_1 * ) ( V_3 -> V_6 -> V_17 ) ) +
V_3 -> V_23 ;
V_3 -> V_23 += V_28 ;
return 0 ;
}
