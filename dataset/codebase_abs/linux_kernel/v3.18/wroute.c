bool F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
T_1 V_6 = V_2 -> V_6 ;
T_2 V_7 , V_8 ;
unsigned int V_9 ;
unsigned int V_10 ;
unsigned char V_11 ;
bool V_12 = false ;
T_3 V_13 ;
T_4 V_14 = NULL ;
unsigned int V_15 ;
unsigned int V_16 ;
unsigned char * V_17 ;
if ( F_2 ( V_2 , V_18 ) <= 0 ) {
F_3 ( L_1 ) ;
return false ;
}
V_7 = V_2 -> V_19 [ V_18 ] ;
V_7 -> V_20 . V_21 = ( V_22 | V_23 ) ;
memcpy ( V_2 -> V_24 . V_25 , V_3 , V_26 ) ;
V_9 = V_4 - V_26 ;
if ( F_4 ( V_2 -> V_24 . V_27 ) > V_28 )
V_9 += 8 ;
if ( V_2 -> V_29 == true ) {
V_12 = true ;
V_17 = V_2 -> V_30 ;
if ( F_5 ( & ( V_2 -> V_31 ) , V_17 ,
V_32 , & V_14 ) == false ) {
V_14 = NULL ;
F_3 ( L_2 ,
V_2 -> V_6 -> V_33 ) ;
} else {
F_3 ( L_3 ) ;
}
}
if ( V_2 -> V_34 ) {
if ( V_5 < V_35 + 1 ) {
V_14 = & V_13 ;
V_14 -> V_36 = V_6 -> V_37 [ V_5 ] . V_36 ;
V_14 -> V_38 = V_6 -> V_37 [ V_5 ] . V_38 ;
V_14 -> V_39 = V_6 -> V_37 [ V_5 ] . V_40 ;
V_14 -> V_41 = V_6 -> V_37 [ V_5 ] . V_41 ;
V_14 -> V_42 = V_6 -> V_37 [ V_5 ] . V_42 ;
memcpy ( V_14 -> V_43 ,
& V_6 -> V_37 [ V_5 ] . V_44 [ 0 ] ,
V_14 -> V_39 ) ;
}
}
V_10 = F_6 ( V_2 , V_14 ,
V_9 , & V_2 -> V_24 ) ;
if ( V_10 > F_2 ( V_2 , V_18 ) )
return false ;
V_11 = V_2 -> V_45 ;
if ( V_2 -> V_46 ) {
if ( V_2 -> V_47 == V_48 ) {
if ( V_2 -> V_49 >= V_50 )
V_2 -> V_51 = V_50 ;
else
V_2 -> V_51 = V_2 -> V_49 ;
} else {
if ( ( V_2 -> V_47 == V_52 ) &&
( V_2 -> V_49 <= V_53 ) ) {
V_2 -> V_51 = V_53 ;
} else {
if ( V_2 -> V_49 >= V_54 )
V_2 -> V_51 = V_54 ;
else
V_2 -> V_51 = V_2 -> V_49 ;
}
}
} else {
V_2 -> V_51 = V_2 -> V_6 -> V_37 [ V_5 ] . V_55 ;
}
if ( V_2 -> V_51 <= V_50 )
V_11 = V_56 ;
F_7 ( V_2 , V_11 , V_2 -> V_57 ,
V_12 , V_9 , V_18 ,
V_7 , & V_2 -> V_24 , V_3 ,
V_14 , V_5 , & V_10 ,
& V_15 ) ;
if ( F_8 ( V_2 -> V_58 , V_59 , V_60 ) ) {
F_9 ( V_2 -> V_58 ) ;
}
V_2 -> V_61 = false ;
V_8 = V_7 ;
for ( V_16 = 0 ; V_16 < V_10 ; V_16 ++ ) {
F_10 () ;
V_7 -> V_62 . V_63 = V_64 ;
F_10 () ;
if ( V_16 == ( V_10 - 1 ) )
V_8 = V_7 ;
V_7 = V_7 -> V_65 ;
}
V_8 -> V_66 -> V_67 = NULL ;
V_8 -> V_66 -> V_68 = 0 ;
V_2 -> V_19 [ V_18 ] = V_7 ;
F_11 ( V_2 -> V_58 ) ;
return true ;
}
