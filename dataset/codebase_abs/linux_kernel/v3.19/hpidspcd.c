short F_1 ( T_1 V_1 , void * V_2 , struct V_3 * V_3 ,
T_1 * V_4 )
{
const struct V_5 * V_5 ;
struct V_6 * V_7 = V_2 ;
struct V_8 V_9 ;
char V_10 [ 20 ] ;
short V_11 = V_12 ;
int V_13 ;
sprintf ( V_10 , L_1 , V_1 ) ;
V_13 = F_2 ( & V_5 , V_10 , & V_7 -> V_7 ) ;
if ( V_13 || ! V_5 ) {
F_3 ( & V_7 -> V_7 , L_2 ,
V_13 , V_10 ) ;
goto V_14;
}
if ( V_5 -> V_15 < sizeof( V_9 ) ) {
F_3 ( & V_7 -> V_7 , L_3 , V_10 ) ;
goto V_16;
}
memcpy ( & V_9 , V_5 -> V_17 , sizeof( V_9 ) ) ;
if ( ( V_9 . type != 0x45444F43 ) ||
( V_9 . V_1 != V_1 )
|| ( V_9 . V_15 != V_5 -> V_15 ) ) {
F_3 ( & V_7 -> V_7 ,
L_4 ,
V_9 . V_15 , V_5 -> V_15 ) ;
goto V_16;
}
if ( F_4 ( V_9 . V_18 ) != F_4 ( V_19 ) ) {
F_3 ( & V_7 -> V_7 ,
L_5 ,
V_9 . V_18 , V_19 ) ;
goto V_16;
}
if ( V_9 . V_18 != V_19 ) {
F_5 ( & V_7 -> V_7 ,
L_6 ,
V_9 . V_18 , V_19 ) ;
}
F_6 ( V_20 , L_7 , V_10 ) ;
V_3 -> V_21 = F_7 ( sizeof( * V_3 -> V_21 ) , V_22 ) ;
if ( ! V_3 -> V_21 ) {
V_11 = V_23 ;
goto V_16;
}
V_3 -> V_21 -> V_7 = V_7 ;
V_3 -> V_21 -> V_5 = V_5 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_24 = V_9 . V_15 / sizeof( T_1 ) ;
V_3 -> V_25 = sizeof( V_9 ) / sizeof( T_1 ) ;
return 0 ;
V_16:
F_8 ( V_5 ) ;
V_14:
V_3 -> V_24 = 0 ;
return V_11 ;
}
void F_9 ( struct V_3 * V_3 )
{
F_6 ( V_20 , L_8 ) ;
F_8 ( V_3 -> V_21 -> V_5 ) ;
F_10 ( V_3 -> V_21 ) ;
}
void F_11 ( struct V_3 * V_3 )
{
V_3 -> V_25 = sizeof( struct V_8 ) / sizeof( T_1 ) ;
}
short F_12 ( struct V_3 * V_3 , T_1 * V_26 )
{
if ( V_3 -> V_25 + 1 > V_3 -> V_24 )
return V_27 ;
* V_26 = ( ( T_1 * ) ( V_3 -> V_21 -> V_5 -> V_17 ) ) [ V_3 ->
V_25 ] ;
V_3 -> V_25 ++ ;
return 0 ;
}
short F_13 ( T_2 V_28 ,
struct V_3 * V_3 , T_1 * * V_29 )
{
if ( V_3 -> V_25 + V_28 > V_3 -> V_24 )
return V_27 ;
* V_29 =
( ( T_1 * ) ( V_3 -> V_21 -> V_5 -> V_17 ) ) +
V_3 -> V_25 ;
V_3 -> V_25 += V_28 ;
return 0 ;
}
