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
bool V_16 ,
T_2 V_17 )
{
union {
struct V_18 V_19 ;
struct V_20 V_21 ;
struct V_22 V_23 ;
struct V_24 V_25 ;
} V_4 = {} ;
struct V_26 V_27 = {
. V_28 = V_29 ,
. V_30 = V_17 ,
. V_31 [ 0 ] = & V_4 ,
. V_32 [ 0 ] = V_33 ,
} ;
struct V_34 * V_35 ;
T_2 V_36 = 0 , V_37 ;
T_2 V_38 = V_12 -> V_39 -> V_40 . V_30 ;
#if F_4 ( V_41 )
struct V_42 * V_43 = F_5 ( V_14 ) ;
int V_5 ;
bool V_44 = V_16 ;
if ( V_38 & V_45 ||
V_38 & V_46 ) {
struct V_47 * V_48 ;
struct V_49 * V_50 ;
int V_51 , V_52 ;
int V_53 ;
int V_54 = 0 ;
if ( V_38 & V_45 ) {
V_48 = V_4 . V_23 . V_55 ;
V_51 = V_56 ;
V_50 = V_4 . V_23 . V_57 ;
V_52 = V_58 ;
} else {
V_48 = V_4 . V_25 . V_55 ;
V_51 = V_59 ;
V_50 = V_4 . V_25 . V_57 ;
V_52 = V_60 ;
}
for ( V_5 = 0 , V_53 = 0 ;
V_5 < V_43 -> V_61 &&
V_5 < V_52 && V_53 < V_51 ; V_5 ++ ) {
struct V_62 V_63 ;
int V_64 ;
if ( V_44 &&
F_6 ( V_5 , V_43 -> V_65 ) ) {
V_54 ++ ;
continue;
}
F_7 ( & V_43 -> V_66 [ V_5 ] ,
& V_63 ) ;
for ( V_64 = 0 ; V_64 < V_53 ; V_64 ++ )
if ( F_8 ( & V_48 [ V_64 ] . V_67 ,
& V_63 ) == 0 )
break;
if ( V_64 == V_53 )
V_53 ++ ;
V_50 [ V_5 ] . V_68 = V_43 -> V_66 [ V_5 ] ;
V_50 [ V_5 ] . V_69 = F_9 ( V_64 ) ;
V_48 [ V_64 ] . V_67 = V_63 ;
memcpy ( V_48 [ V_64 ] . V_70 , V_14 -> V_68 , V_71 ) ;
}
if ( V_43 -> V_61 - V_54 )
V_36 |= V_72 ;
if ( V_38 & V_45 )
V_4 . V_23 . V_73 =
F_9 ( V_5 - V_54 ) ;
else
V_4 . V_25 . V_73 =
F_9 ( V_5 - V_54 ) ;
} else if ( V_38 & V_74 ) {
bool V_75 = false ;
F_10 ( sizeof( V_4 . V_21 . V_76 [ 0 ] ) !=
sizeof( V_43 -> V_66 [ 0 ] ) ) ;
for ( V_5 = 0 ; V_5 < F_11 ( V_43 -> V_61 ,
V_77 ) ; V_5 ++ ) {
if ( V_44 &&
F_6 ( V_5 , V_43 -> V_65 ) )
continue;
memcpy ( V_4 . V_21 . V_76 [ V_5 ] ,
& V_43 -> V_66 [ V_5 ] ,
sizeof( V_4 . V_21 . V_76 [ V_5 ] ) ) ;
V_75 = true ;
}
if ( V_75 ) {
V_36 |= V_72 ;
memcpy ( V_4 . V_21 . V_78 , V_14 -> V_68 , V_71 ) ;
}
} else {
bool V_75 = false ;
F_10 ( sizeof( V_4 . V_19 . V_76 [ 0 ] ) !=
sizeof( V_43 -> V_66 [ 0 ] ) ) ;
for ( V_5 = 0 ; V_5 < F_11 ( V_43 -> V_61 ,
V_79 ) ; V_5 ++ ) {
if ( V_44 &&
F_6 ( V_5 , V_43 -> V_65 ) )
continue;
memcpy ( V_4 . V_19 . V_76 [ V_5 ] ,
& V_43 -> V_66 [ V_5 ] ,
sizeof( V_4 . V_19 . V_76 [ V_5 ] ) ) ;
V_75 = true ;
}
if ( V_75 ) {
V_36 |= V_72 ;
memcpy ( V_4 . V_19 . V_78 , V_14 -> V_68 , V_71 ) ;
}
}
if ( V_16 && ( V_36 & V_72 ) )
V_36 |= V_80 ;
#endif
if ( V_38 & V_45 ) {
V_35 = & V_4 . V_23 . V_35 ;
V_37 = sizeof( V_4 . V_23 ) ;
} else if ( V_38 & V_46 ) {
V_35 = & V_4 . V_25 . V_35 ;
V_37 = sizeof( V_4 . V_25 ) ;
} else if ( V_38 & V_74 ) {
V_35 = & V_4 . V_21 . V_35 ;
V_37 = sizeof( V_4 . V_21 ) ;
} else {
V_35 = & V_4 . V_19 . V_35 ;
V_37 = sizeof( V_4 . V_19 ) ;
}
if ( V_14 -> V_81 . V_82 ) {
V_36 |= V_83 | V_84 ;
V_35 -> V_85 = V_14 -> V_81 . V_86 [ 0 ] ;
memcpy ( V_35 -> V_87 , V_14 -> V_68 , V_71 ) ;
}
if ( ! V_15 )
V_35 -> V_36 = F_9 ( V_36 ) ;
V_27 . V_88 [ 0 ] = V_37 ;
return F_12 ( V_12 , & V_27 ) ;
}
