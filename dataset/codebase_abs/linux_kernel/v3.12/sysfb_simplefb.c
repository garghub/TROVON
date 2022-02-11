T_1 bool F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
T_2 type ;
unsigned int V_7 ;
type = V_2 -> V_8 ;
if ( type != V_9 && type != V_10 )
return false ;
for ( V_7 = 0 ; V_7 < F_2 ( V_11 ) ; ++ V_7 ) {
V_6 = & V_11 [ V_7 ] ;
if ( V_2 -> V_12 == V_6 -> V_13 &&
V_2 -> V_14 == V_6 -> V_15 . V_16 &&
V_2 -> V_17 == V_6 -> V_15 . V_18 &&
V_2 -> V_19 == V_6 -> V_20 . V_16 &&
V_2 -> V_21 == V_6 -> V_20 . V_18 &&
V_2 -> V_22 == V_6 -> V_23 . V_16 &&
V_2 -> V_24 == V_6 -> V_23 . V_18 &&
V_2 -> V_25 == V_6 -> V_26 . V_16 &&
V_2 -> V_27 == V_6 -> V_26 . V_18 ) {
V_4 -> V_28 = V_6 -> V_29 ;
V_4 -> V_30 = V_2 -> V_31 ;
V_4 -> V_32 = V_2 -> V_33 ;
V_4 -> V_34 = V_2 -> V_35 ;
return true ;
}
}
return false ;
}
T_1 int F_3 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_36 * V_37 ;
struct V_38 V_39 ;
unsigned long V_40 ;
V_40 = V_4 -> V_32 * V_4 -> V_34 ;
V_40 = F_4 ( V_40 ) ;
if ( V_40 > ( V_41 ) V_2 -> V_42 << 16 ) {
F_5 ( V_43 L_1 ) ;
return - V_44 ;
}
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_45 = V_46 | V_47 ;
V_39 . V_29 = V_48 ;
V_39 . V_49 = V_2 -> V_50 ;
V_39 . V_51 = V_2 -> V_50 + V_40 - 1 ;
if ( V_39 . V_51 <= V_39 . V_49 )
return - V_44 ;
V_37 = F_6 ( NULL , L_2 , 0 ,
& V_39 , 1 , V_4 , sizeof( * V_4 ) ) ;
if ( F_7 ( V_37 ) )
return F_8 ( V_37 ) ;
return 0 ;
}
