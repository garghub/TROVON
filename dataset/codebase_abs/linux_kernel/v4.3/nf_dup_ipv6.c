static struct V_1 * F_1 ( struct V_2 * V_3 )
{
#ifdef F_2
const struct V_4 * V_5 ;
if ( V_3 -> V_6 != NULL )
return F_3 ( V_3 -> V_6 ) ;
V_5 = F_4 ( V_3 ) ;
if ( V_5 != NULL && V_5 -> V_6 != NULL )
return F_3 ( V_5 -> V_6 ) ;
#endif
return & V_7 ;
}
static bool F_5 ( struct V_2 * V_3 , const struct V_8 * V_9 ,
int V_10 )
{
const struct V_11 * V_12 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_4 * V_5 ;
struct V_13 V_14 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
if ( V_10 != - 1 )
V_14 . V_15 = V_10 ;
V_14 . V_16 = * V_9 ;
V_14 . V_17 = ( V_18 V_19 ) ( ( ( V_12 -> V_20 [ 0 ] & 0xF ) << 16 ) |
( V_12 -> V_20 [ 1 ] << 8 ) | V_12 -> V_20 [ 2 ] ) ;
V_5 = F_7 ( V_1 , NULL , & V_14 ) ;
if ( V_5 -> error ) {
F_8 ( V_5 ) ;
return false ;
}
F_9 ( V_3 ) ;
F_10 ( V_3 , V_5 ) ;
V_3 -> V_6 = V_5 -> V_6 ;
V_3 -> V_21 = F_11 ( V_22 ) ;
return true ;
}
void F_12 ( struct V_2 * V_3 , unsigned int V_23 ,
const struct V_8 * V_9 , int V_10 )
{
if ( F_13 ( V_24 ) )
return;
V_3 = F_14 ( V_3 , V_25 ) ;
if ( V_3 == NULL )
return;
#if F_15 ( V_26 )
F_16 ( V_3 -> V_27 ) ;
V_3 -> V_27 = & F_17 () -> V_28 ;
V_3 -> V_29 = V_30 ;
F_18 ( V_3 -> V_27 ) ;
#endif
if ( V_23 == V_31 ||
V_23 == V_32 ) {
struct V_11 * V_12 = F_6 ( V_3 ) ;
-- V_12 -> V_33 ;
}
if ( F_5 ( V_3 , V_9 , V_10 ) ) {
F_19 ( V_24 , true ) ;
F_20 ( V_3 ) ;
F_19 ( V_24 , false ) ;
} else {
F_21 ( V_3 ) ;
}
}
