static bool F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 , int V_6 )
{
const struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
if ( V_6 != - 1 )
V_12 . V_13 = V_6 ;
V_12 . V_14 = * V_5 ;
V_12 . V_15 = ( V_16 V_17 ) ( ( ( V_8 -> V_18 [ 0 ] & 0xF ) << 16 ) |
( V_8 -> V_18 [ 1 ] << 8 ) | V_8 -> V_18 [ 2 ] ) ;
V_12 . V_19 = V_20 ;
V_10 = F_3 ( V_1 , NULL , & V_12 ) ;
if ( V_10 -> error ) {
F_4 ( V_10 ) ;
return false ;
}
F_5 ( V_3 ) ;
F_6 ( V_3 , V_10 ) ;
V_3 -> V_21 = V_10 -> V_21 ;
V_3 -> V_22 = F_7 ( V_23 ) ;
return true ;
}
void F_8 ( struct V_1 * V_1 , struct V_2 * V_3 , unsigned int V_24 ,
const struct V_4 * V_5 , int V_6 )
{
if ( F_9 ( V_25 ) )
return;
V_3 = F_10 ( V_3 , V_26 ) ;
if ( V_3 == NULL )
return;
#if F_11 ( V_27 )
F_12 ( V_3 ) ;
F_13 ( V_3 , NULL , V_28 ) ;
#endif
if ( V_24 == V_29 ||
V_24 == V_30 ) {
struct V_7 * V_8 = F_2 ( V_3 ) ;
-- V_8 -> V_31 ;
}
if ( F_1 ( V_1 , V_3 , V_5 , V_6 ) ) {
F_14 ( V_25 , true ) ;
F_15 ( V_1 , V_3 -> V_32 , V_3 ) ;
F_14 ( V_25 , false ) ;
} else {
F_16 ( V_3 ) ;
}
}
