static bool F_1 ( struct V_1 * V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 , int V_6 )
{
const struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
if ( V_6 != - 1 )
V_12 . V_13 = V_6 ;
V_12 . V_14 = V_5 -> V_15 ;
V_12 . V_16 = F_3 ( V_8 -> V_17 ) ;
V_12 . V_18 = V_19 ;
V_12 . V_20 = V_21 ;
V_10 = F_4 ( V_1 , & V_12 ) ;
if ( F_5 ( V_10 ) )
return false ;
F_6 ( V_3 ) ;
F_7 ( V_3 , & V_10 -> V_22 ) ;
V_3 -> V_23 = V_10 -> V_22 . V_23 ;
V_3 -> V_24 = F_8 ( V_25 ) ;
return true ;
}
void F_9 ( struct V_1 * V_1 , struct V_2 * V_3 , unsigned int V_26 ,
const struct V_4 * V_5 , int V_6 )
{
struct V_7 * V_8 ;
if ( F_10 ( V_27 ) )
return;
V_3 = F_11 ( V_3 , V_28 ) ;
if ( V_3 == NULL )
return;
#if F_12 ( V_29 )
F_13 ( V_3 ) ;
F_14 ( V_3 , F_15 () , V_30 ) ;
F_16 ( F_17 ( V_3 ) ) ;
#endif
V_8 = F_2 ( V_3 ) ;
V_8 -> V_31 |= F_8 ( V_32 ) ;
if ( V_26 == V_33 ||
V_26 == V_34 )
-- V_8 -> V_35 ;
if ( F_1 ( V_1 , V_3 , V_5 , V_6 ) ) {
F_18 ( V_27 , true ) ;
F_19 ( V_1 , V_3 -> V_36 , V_3 ) ;
F_18 ( V_27 , false ) ;
} else {
F_20 ( V_3 ) ;
}
}
