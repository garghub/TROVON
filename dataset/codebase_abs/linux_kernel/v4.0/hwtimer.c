T_1 F_1 ( T_2 * V_1 )
{
F_2 ( F_1 ) ;
if ( ! V_1 ) {
F_3 ( V_2 ) ;
}
if ( ( V_3 . V_4 & V_5 ) == 0 ) {
* V_1 = 24 ;
} else {
* V_1 = 32 ;
}
F_3 ( V_6 ) ;
}
T_1 F_4 ( T_2 * V_7 )
{
T_1 V_8 ;
F_2 ( F_4 ) ;
if ( ! V_7 ) {
F_3 ( V_2 ) ;
}
if ( ! V_3 . V_9 . V_10 ) {
F_3 ( V_11 ) ;
}
V_8 = F_5 ( V_7 , & V_3 . V_9 ) ;
F_3 ( V_8 ) ;
}
T_1
F_6 ( T_2 V_12 , T_2 V_13 , T_2 * V_14 )
{
T_1 V_8 ;
T_2 V_15 ;
T_3 V_16 ;
F_2 ( F_6 ) ;
if ( ! V_14 ) {
F_3 ( V_2 ) ;
}
if ( ! V_3 . V_9 . V_10 ) {
F_3 ( V_11 ) ;
}
if ( V_12 < V_13 ) {
V_15 = V_13 - V_12 ;
} else if ( V_12 > V_13 ) {
if ( ( V_3 . V_4 & V_5 ) == 0 ) {
V_15 =
( ( ( 0x00FFFFFF - V_12 ) +
V_13 ) & 0x00FFFFFF ) ;
} else {
V_15 = ( 0xFFFFFFFF - V_12 ) + V_13 ;
}
} else {
* V_14 = 0 ;
F_3 ( V_6 ) ;
}
V_8 = F_7 ( ( ( T_3 ) V_15 ) * V_17 ,
V_18 , & V_16 , NULL ) ;
* V_14 = ( T_2 ) V_16 ;
F_3 ( V_8 ) ;
}
