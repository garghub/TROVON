union V_1 * F_1 ( void )
{
union V_1 * V_2 ;
V_2 = F_2 ( V_3 ) ;
if ( ! V_2 ) {
return ( NULL ) ;
}
V_2 -> V_4 . V_5 = V_6 ;
return ( V_2 ) ;
}
void F_3 ( union V_1 * V_7 , T_1 V_8 )
{
F_4 () ;
V_7 -> V_9 . V_10 = V_11 ;
V_7 -> V_9 . V_12 = V_8 ;
F_5 ( F_6 ( V_7 -> V_9 . V_13 ,
( F_7
( V_8 ) ) -> V_5 ,
sizeof( V_7 -> V_9 . V_13 ) ) ) ;
}
union V_1 * F_2 ( T_1 V_8 )
{
union V_1 * V_7 ;
const struct V_14 * V_15 ;
T_2 V_16 = V_17 ;
F_4 () ;
V_15 = F_7 ( V_8 ) ;
if ( V_15 -> V_16 & V_18 ) {
V_16 = V_19 ;
} else if ( V_15 -> V_16 & V_20 ) {
V_16 = V_21 ;
} else if ( V_8 == V_22 ) {
V_16 = V_23 ;
}
if ( V_16 == V_17 ) {
V_7 = F_8 ( V_24 ) ;
} else {
V_7 = F_8 ( V_25 ) ;
}
if ( V_7 ) {
F_3 ( V_7 , V_8 ) ;
V_7 -> V_9 . V_16 = V_16 ;
}
return ( V_7 ) ;
}
void F_9 ( union V_1 * V_7 )
{
F_10 ( V_26 ) ;
if ( V_7 -> V_9 . V_12 == V_27 ) {
F_11 ( ( V_28 , L_1 ,
V_7 ) ) ;
}
if ( V_7 -> V_9 . V_16 & V_17 ) {
( void ) F_12 ( V_24 , V_7 ) ;
} else {
( void ) F_12 ( V_25 , V_7 ) ;
}
}
T_2 F_13 ( T_3 V_29 )
{
return ( ( T_2 ) ( V_29 == '_' || ( V_29 >= 'A' && V_29 <= 'Z' ) ) ) ;
}
T_2 F_14 ( T_3 V_29 )
{
return ( ( T_2 ) ( V_29 == '\\' || V_29 == '^' ) ) ;
}
T_3 F_15 ( union V_1 * V_7 )
{
if ( V_7 -> V_9 . V_16 & V_17 ) {
return ( 0 ) ;
}
return ( V_7 -> V_4 . V_5 ) ;
}
void F_16 ( union V_1 * V_7 , T_3 V_5 )
{
if ( V_7 -> V_9 . V_16 & V_17 ) {
return;
}
V_7 -> V_4 . V_5 = V_5 ;
}
