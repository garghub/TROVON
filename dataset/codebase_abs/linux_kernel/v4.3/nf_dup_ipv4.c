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
struct V_13 * V_14 ;
struct V_15 V_16 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( V_10 != - 1 )
V_16 . V_17 = V_10 ;
V_16 . V_18 = V_9 -> V_19 ;
V_16 . V_20 = F_7 ( V_12 -> V_21 ) ;
V_16 . V_22 = V_23 ;
V_16 . V_24 = V_25 ;
V_14 = F_8 ( V_1 , & V_16 ) ;
if ( F_9 ( V_14 ) )
return false ;
F_10 ( V_3 ) ;
F_11 ( V_3 , & V_14 -> V_5 ) ;
V_3 -> V_6 = V_14 -> V_5 . V_6 ;
V_3 -> V_26 = F_12 ( V_27 ) ;
return true ;
}
void F_13 ( struct V_2 * V_3 , unsigned int V_28 ,
const struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 ;
if ( F_14 ( V_29 ) )
return;
V_3 = F_15 ( V_3 , V_30 ) ;
if ( V_3 == NULL )
return;
#if F_16 ( V_31 )
F_17 ( V_3 -> V_32 ) ;
V_3 -> V_32 = & F_18 () -> V_33 ;
V_3 -> V_34 = V_35 ;
F_19 ( V_3 -> V_32 ) ;
#endif
V_12 = F_6 ( V_3 ) ;
V_12 -> V_36 |= F_12 ( V_37 ) ;
if ( V_28 == V_38 ||
V_28 == V_39 )
-- V_12 -> V_40 ;
F_20 ( V_12 ) ;
if ( F_5 ( V_3 , V_9 , V_10 ) ) {
F_21 ( V_29 , true ) ;
F_22 ( V_3 ) ;
F_21 ( V_29 , false ) ;
} else {
F_23 ( V_3 ) ;
}
}
