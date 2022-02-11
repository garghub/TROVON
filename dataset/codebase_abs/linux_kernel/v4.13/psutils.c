union V_1 * F_1 ( T_1 * V_2 )
{
union V_1 * V_3 ;
V_3 = F_2 ( V_4 , V_2 ) ;
if ( ! V_3 ) {
return ( NULL ) ;
}
V_3 -> V_5 . V_6 = V_7 ;
return ( V_3 ) ;
}
void F_3 ( union V_1 * V_8 , T_2 V_9 )
{
F_4 () ;
V_8 -> V_10 . V_11 = V_12 ;
V_8 -> V_10 . V_13 = V_9 ;
F_5 ( strncpy ( V_8 -> V_10 . V_14 ,
( F_6 ( V_9 ) ) ->
V_6 , sizeof( V_8 -> V_10 . V_14 ) ) ) ;
}
union V_1 * F_2 ( T_2 V_9 , T_1 * V_2 )
{
union V_1 * V_8 ;
const struct V_15 * V_16 ;
T_1 V_17 = V_18 ;
F_4 () ;
V_16 = F_6 ( V_9 ) ;
if ( V_16 -> V_17 & V_19 ) {
V_17 = V_20 ;
} else if ( V_16 -> V_17 & V_21 ) {
V_17 = V_22 ;
} else if ( V_9 == V_23 ) {
V_17 = V_24 ;
}
if ( V_17 == V_18 ) {
V_8 = F_7 ( V_25 ) ;
} else {
V_8 = F_7 ( V_26 ) ;
}
if ( V_8 ) {
F_3 ( V_8 , V_9 ) ;
V_8 -> V_10 . V_2 = V_2 ;
V_8 -> V_10 . V_17 = V_17 ;
F_8 ( V_8 ) ;
if ( V_9 == V_4 ) {
V_27 = V_8 ;
}
}
if ( V_28 ) {
F_9 ( V_8 ) ;
}
return ( V_8 ) ;
}
void F_10 ( union V_1 * V_8 )
{
F_11 ( V_29 ) ;
F_8 ( V_8 ) ;
if ( V_8 -> V_10 . V_13 == V_30 ) {
F_12 ( ( V_31 ,
L_1 , V_8 ) ) ;
}
if ( V_8 -> V_10 . V_17 & V_18 ) {
( void ) F_13 ( V_25 , V_8 ) ;
} else {
( void ) F_13 ( V_26 , V_8 ) ;
}
}
T_1 F_14 ( T_3 V_32 )
{
return ( ( T_1 ) ( V_32 == '_' || ( V_32 >= 'A' && V_32 <= 'Z' ) ) ) ;
}
T_3 F_15 ( union V_1 * V_8 )
{
if ( V_8 -> V_10 . V_17 & V_18 ) {
return ( 0 ) ;
}
return ( V_8 -> V_5 . V_6 ) ;
}
void F_16 ( union V_1 * V_8 , T_3 V_6 )
{
if ( V_8 -> V_10 . V_17 & V_18 ) {
return;
}
V_8 -> V_5 . V_6 = V_6 ;
}
