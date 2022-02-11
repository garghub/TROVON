static bool
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_8 * V_9 = & V_7 -> V_10 ;
struct V_11 * V_12 ;
F_2 ( L_1 , V_13 , V_4 -> type ) ;
V_12 = F_3 ( & V_2 -> V_14 , V_4 ) ;
if ( ! V_12 )
return false ;
if ( ! V_12 -> V_15 . V_16 ||
F_4 ( V_12 -> V_15 . V_16 ) -> F_5 ( V_12 , V_4 ) ) {
F_6 ( V_12 ) ;
return false ;
}
F_7 ( & V_7 -> V_17 ,
L_2
L_3 ,
V_4 -> type , V_4 -> V_18 , V_9 -> V_19 ) ;
V_7 -> V_20 = V_12 ;
return true ;
}
void
F_8 ( struct V_6 * V_7 )
{
struct V_21 * V_22 = V_7 -> V_17 . V_22 ;
struct V_23 * V_24 = V_22 -> V_24 ;
struct V_25 * V_14 = V_22 -> V_14 ;
struct V_1 * V_2 ;
struct V_26 V_27 ;
V_2 = F_9 ( V_14 , V_28 ) ;
if ( ! V_2 )
return;
if ( ! F_10 ( V_24 , V_29 , & V_27 ) ) {
struct V_30 V_31 [] = {
{ { F_11 ( L_4 , extdev_entry.addr >> 1 ) } , 0 } ,
{ }
} ;
V_30 ( V_2 , L_5 , V_31 ,
F_1 , V_7 ) ;
if ( V_7 -> V_20 )
return;
}
if ( ! F_10 ( V_24 , V_32 , & V_27 ) ) {
struct V_30 V_31 [] = {
{ { F_11 ( L_6 , extdev_entry.addr >> 1 ) } , 20 } ,
{ }
} ;
V_30 ( V_2 , L_5 , V_31 ,
F_1 , V_7 ) ;
if ( V_7 -> V_20 )
return;
}
V_30 ( V_2 , L_5 , V_33 ,
F_1 , V_7 ) ;
}
