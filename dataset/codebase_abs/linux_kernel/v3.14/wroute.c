bool F_1 ( T_1 V_1 , unsigned char * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
T_2 V_5 = V_1 -> V_5 ;
T_3 V_6 , V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
unsigned char V_10 ;
bool V_11 = false ;
T_4 V_12 ;
T_5 V_13 = NULL ;
unsigned int V_14 ;
unsigned int V_15 ;
unsigned char * V_16 ;
if ( F_2 ( V_1 , V_17 ) <= 0 ) {
F_3 ( V_18 ,
V_19 L_1 ) ;
return false ;
}
V_6 = V_1 -> V_20 [ V_17 ] ;
V_6 -> V_21 . V_22 = ( V_23 | V_24 ) ;
memcpy ( V_1 -> V_25 . V_26 , V_2 , V_27 ) ;
V_8 = V_3 - V_27 ;
if ( F_4 ( V_1 -> V_25 . V_28 ) > V_29 )
V_8 += 8 ;
if ( V_1 -> V_30 == true ) {
V_11 = true ;
V_16 = V_1 -> V_31 ;
if ( F_5 ( & ( V_1 -> V_32 ) , V_16 ,
V_33 , & V_13 ) == false ) {
V_13 = NULL ;
F_3 ( V_18 ,
V_34 L_2 ,
V_1 -> V_5 -> V_35 ) ;
} else {
F_3 ( V_18 , V_34 L_3 ) ;
}
}
if ( V_1 -> V_36 ) {
if ( V_4 < V_37 + 1 ) {
V_13 = & V_12 ;
V_13 -> V_38 = V_5 -> V_39 [ V_4 ] . V_38 ;
V_13 -> V_40 = V_5 -> V_39 [ V_4 ] . V_40 ;
V_13 -> V_41 = V_5 -> V_39 [ V_4 ] . V_42 ;
V_13 -> V_43 = V_5 -> V_39 [ V_4 ] . V_43 ;
V_13 -> V_44 = V_5 -> V_39 [ V_4 ] . V_44 ;
memcpy ( V_13 -> V_45 ,
& V_5 -> V_39 [ V_4 ] . V_46 [ 0 ] ,
V_13 -> V_41 ) ;
}
}
V_9 = F_6 ( V_1 , V_13 ,
V_8 , & V_1 -> V_25 ) ;
if ( V_9 > F_2 ( V_1 , V_17 ) )
return false ;
V_10 = V_1 -> V_47 ;
if ( V_1 -> V_48 ) {
if ( V_1 -> V_49 == V_50 ) {
if ( V_1 -> V_51 >= V_52 )
V_1 -> V_53 = V_52 ;
else
V_1 -> V_53 = V_1 -> V_51 ;
} else {
if ( ( V_1 -> V_49 == V_54 ) &&
( V_1 -> V_51 <= V_55 ) ) {
V_1 -> V_53 = V_55 ;
} else {
if ( V_1 -> V_51 >= V_56 )
V_1 -> V_53 = V_56 ;
else
V_1 -> V_53 = V_1 -> V_51 ;
}
}
} else {
V_1 -> V_53 = V_1 -> V_5 -> V_39 [ V_4 ] . V_57 ;
}
if ( V_1 -> V_53 <= V_52 )
V_10 = V_58 ;
F_7 ( V_1 , V_10 , V_1 -> V_59 ,
V_11 , V_8 , V_17 ,
V_6 , & V_1 -> V_25 , V_2 ,
V_13 , V_4 , & V_9 ,
& V_14 ) ;
if ( F_8 ( V_1 -> V_60 , V_61 , V_62 ) ) {
F_9 ( V_1 -> V_60 ) ;
}
V_1 -> V_63 = false ;
V_7 = V_6 ;
for ( V_15 = 0 ; V_15 < V_9 ; V_15 ++ ) {
F_10 () ;
V_6 -> V_64 . V_65 = V_66 ;
F_10 () ;
if ( V_15 == ( V_9 - 1 ) )
V_7 = V_6 ;
V_6 = V_6 -> V_67 ;
}
V_7 -> V_68 -> V_69 = NULL ;
V_7 -> V_68 -> V_70 = 0 ;
V_1 -> V_20 [ V_17 ] = V_6 ;
F_11 ( V_1 -> V_60 ) ;
return true ;
}
