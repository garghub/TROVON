T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
V_2 -> V_5 = false ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 == V_4 ) {
V_2 -> V_5 = true ;
if ( V_2 -> V_6 . V_7 == 1 )
F_3 ( V_2 , 1 ) ;
} else {
V_2 -> V_5 = false ;
F_4 ( L_1 ) ;
}
F_5 ( V_8 , V_9 ,
( L_2 , V_3 ) ) ;
return V_3 ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 == V_4 )
V_2 -> V_5 = false ;
else
F_4 ( L_3 ) ;
return V_3 ;
}
void F_8 ( struct V_1 * V_2 , T_2 V_10 , T_3 V_11 )
{
struct V_12 * V_13 = & ( V_2 -> V_14 ) ;
if ( F_9 ( V_13 , V_15 ) == true ) {
#ifdef F_10
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 = & V_2 -> V_20 ;
if ( ( V_10 - 1 ) > 0 )
V_17 = V_19 -> V_21 [ ( V_10 - 1 ) - 1 ] ;
if ( V_17 )
F_11 ( V_2 , V_17 , 0 ) ;
#endif
} else {
F_12 ( V_2 , V_10 , V_11 ) ;
}
}
