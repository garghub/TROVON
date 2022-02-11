void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
T_1 V_7 = V_2 -> V_8 [ V_5 ] . V_9 ;
V_7 -= 0x10 ;
V_4 -> V_10 [ V_5 ] = F_2 ( V_7 ) ;
}
}
int F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
bool V_15 ,
T_2 V_16 )
{
union {
struct V_17 V_18 ;
struct V_19 V_20 ;
struct V_21 V_22 ;
struct V_23 V_24 ;
} V_4 = {} ;
struct V_25 V_26 = {
. V_27 = V_28 ,
. V_29 = V_16 ,
. V_30 [ 0 ] = & V_4 ,
. V_31 [ 0 ] = V_32 ,
} ;
struct V_33 * V_34 ;
T_2 V_35 = 0 , V_36 ;
T_2 V_37 = V_12 -> V_38 -> V_39 . V_29 ;
#if F_4 ( V_40 )
struct V_41 * V_42 = F_5 ( V_14 ) ;
int V_5 ;
if ( V_37 & V_43 ||
V_37 & V_44 ) {
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_49 , V_50 ;
int V_51 ;
if ( V_37 & V_43 ) {
V_46 = V_4 . V_22 . V_52 ;
V_49 = V_53 ;
V_48 = V_4 . V_22 . V_54 ;
V_50 = V_55 ;
} else {
V_46 = V_4 . V_24 . V_52 ;
V_49 = V_56 ;
V_48 = V_4 . V_24 . V_54 ;
V_50 = V_57 ;
}
if ( V_42 -> V_58 )
V_35 |= V_59 ;
for ( V_5 = 0 , V_51 = 0 ;
V_5 < V_42 -> V_58 &&
V_5 < V_50 && V_51 < V_49 ; V_5 ++ ) {
struct V_60 V_61 ;
int V_62 ;
F_6 ( & V_42 -> V_63 [ V_5 ] ,
& V_61 ) ;
for ( V_62 = 0 ; V_62 < V_51 ; V_62 ++ )
if ( F_7 ( & V_46 [ V_62 ] . V_64 ,
& V_61 ) == 0 )
break;
if ( V_62 == V_51 )
V_51 ++ ;
V_48 [ V_5 ] . V_65 = V_42 -> V_63 [ V_5 ] ;
V_48 [ V_5 ] . V_66 = F_8 ( V_62 ) ;
V_46 [ V_62 ] . V_64 = V_61 ;
memcpy ( V_46 [ V_62 ] . V_67 , V_14 -> V_65 , V_68 ) ;
}
if ( V_37 & V_43 )
V_4 . V_22 . V_69 = F_8 ( V_5 ) ;
else
V_4 . V_24 . V_69 = F_8 ( V_5 ) ;
} else if ( V_37 & V_70 ) {
if ( V_42 -> V_58 ) {
V_35 |= V_59 ;
memcpy ( V_4 . V_20 . V_71 , V_14 -> V_65 , V_68 ) ;
}
F_9 ( sizeof( V_4 . V_20 . V_72 [ 0 ] ) !=
sizeof( V_42 -> V_63 [ 0 ] ) ) ;
for ( V_5 = 0 ; V_5 < F_10 ( V_42 -> V_58 ,
V_73 ) ; V_5 ++ )
memcpy ( V_4 . V_20 . V_72 [ V_5 ] ,
& V_42 -> V_63 [ V_5 ] ,
sizeof( V_4 . V_20 . V_72 [ V_5 ] ) ) ;
} else {
if ( V_42 -> V_58 ) {
V_35 |= V_59 ;
memcpy ( V_4 . V_18 . V_71 , V_14 -> V_65 , V_68 ) ;
}
F_9 ( sizeof( V_4 . V_18 . V_72 [ 0 ] ) !=
sizeof( V_42 -> V_63 [ 0 ] ) ) ;
for ( V_5 = 0 ; V_5 < F_10 ( V_42 -> V_58 ,
V_74 ) ; V_5 ++ )
memcpy ( V_4 . V_18 . V_72 [ V_5 ] ,
& V_42 -> V_63 [ V_5 ] ,
sizeof( V_4 . V_18 . V_72 [ V_5 ] ) ) ;
}
#endif
if ( V_37 & V_43 ) {
V_34 = & V_4 . V_22 . V_34 ;
V_36 = sizeof( V_4 . V_22 ) ;
} else if ( V_37 & V_44 ) {
V_34 = & V_4 . V_24 . V_34 ;
V_36 = sizeof( V_4 . V_24 ) ;
} else if ( V_37 & V_70 ) {
V_34 = & V_4 . V_20 . V_34 ;
V_36 = sizeof( V_4 . V_20 ) ;
} else {
V_34 = & V_4 . V_18 . V_34 ;
V_36 = sizeof( V_4 . V_18 ) ;
}
if ( V_14 -> V_75 . V_76 ) {
V_35 |= V_77 ;
V_34 -> V_78 = V_14 -> V_75 . V_79 [ 0 ] ;
memcpy ( V_34 -> V_80 , V_14 -> V_65 , V_68 ) ;
}
if ( ! V_15 )
V_34 -> V_35 = F_8 ( V_35 ) ;
V_26 . V_81 [ 0 ] = V_36 ;
return F_11 ( V_12 , & V_26 ) ;
}
