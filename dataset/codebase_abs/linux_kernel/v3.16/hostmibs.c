INT F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_13 * V_14 = & V_2 -> V_15 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
T_1 V_18 = 0 ;
T_1 V_19 = 0 ;
if ( V_14 == NULL ) {
F_2 ( V_2 , V_20 , V_21 ,
V_22 , L_1 ) ;
return V_23 ;
}
for ( V_16 = 0 ; V_16 < V_24 ;
V_16 ++ ) {
if ( V_2 -> V_25 [ V_16 ] . V_26 == TRUE )
memcpy ( & V_4 -> V_25 [ V_16 ] ,
& V_2 -> V_25 [ V_16 ] ,
sizeof( struct V_27 ) ) ;
}
for ( V_18 = 0 ; V_18 < V_28 ; V_18 ++ ) {
if ( V_2 -> V_29 [ V_18 ] . V_30 ) {
memcpy ( & V_4 -> V_31 [ V_18 ] ,
& V_2 -> V_29 [ V_18 ] ,
sizeof( struct V_32 ) ) ;
} else {
continue;
}
if ( V_33 ==
F_3 ( V_14 ->
V_34 ,
V_2 -> V_29 [ V_18 ] .
V_35 , & V_6 ) )
continue;
V_10 = V_6 -> V_10 ;
for ( V_19 = 0 ; V_19 < V_36 ; V_19 ++ ) {
V_12 = & V_10 -> V_37 [ V_19 ] ;
if ( V_12 -> V_26 ) {
V_8 = V_12 -> V_8 ;
V_4 -> V_38 [ V_17 ] .
V_39 = V_2 -> V_29 [ V_18 ] . V_39 ;
memcpy ( & V_4 -> V_38 [ V_17 ] . V_40 ,
& V_8 -> V_40 ,
sizeof( struct V_7 ) ) ;
V_17 ++ ;
}
}
}
V_4 -> V_41 . V_42 = V_2 -> V_43 -> V_44 . V_45 ;
V_4 -> V_41 . V_46 = V_2 -> V_43 -> V_44 . V_47 ;
V_4 -> V_41 . V_48 =
F_4 ( & V_2 -> V_49 ) ;
V_4 -> V_41 . V_50 = V_2 -> V_50 ;
V_4 -> V_41 . V_51 = V_2 -> V_51 ;
V_4 -> V_41 . V_52 = V_2 -> V_52 ;
V_4 -> V_41 . V_53 = V_2 -> V_53 ;
memcpy ( V_4 -> V_41 . V_54 , V_2 -> V_54 ,
sizeof( V_55 ) * V_56 ) ;
memcpy ( V_4 -> V_41 . V_57 , V_2 -> V_57 ,
sizeof( V_55 ) * V_56 ) ;
return V_58 ;
}
VOID F_5 ( struct V_3 * V_4 ,
struct V_59 * V_60 )
{
memcpy ( & ( V_4 -> V_61 ) ,
& ( V_60 -> V_61 ) ,
sizeof( struct V_62 ) ) ;
}
VOID F_6 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
T_1 V_65 )
{
struct V_66 * V_67 = & V_2 -> V_29 [ V_65 ] . V_68 ;
V_67 -> V_69 = V_64 -> V_70 ;
V_67 -> V_71 = V_64 -> V_72 ;
V_67 -> V_73 = V_64 -> V_74 ;
V_67 -> V_75 = V_64 -> V_76 ;
V_67 -> V_77 = V_64 -> V_78 ;
V_67 -> V_79 = V_64 -> V_80 ;
V_67 -> V_81 = V_64 -> V_82 ;
V_67 -> V_81 = F_7 ( V_67 -> V_81 ) ;
V_67 -> V_83 = V_64 -> V_84 ;
V_67 -> V_83 = F_7 ( V_67 -> V_83 ) ;
V_67 -> V_85 = V_64 -> V_86 ;
V_67 -> V_85 = F_7 ( V_67 -> V_85 ) ;
V_67 -> V_87 = V_64 -> V_88 ;
V_67 -> V_87 = F_7 ( V_67 -> V_87 ) ;
V_67 -> V_89 = F_8 ( V_64 -> V_90 ) ;
V_67 -> V_89 = F_7 ( V_67 -> V_89 ) ;
V_67 -> V_91 = F_8 ( V_64 -> V_92 ) ;
V_67 -> V_91 = F_7 ( V_67 -> V_91 ) ;
V_67 -> V_93 = F_8 ( V_64 -> V_94 ) ;
V_67 -> V_93 = F_7 ( V_67 -> V_93 ) ;
V_67 -> V_95 = V_64 -> V_96 ;
V_67 -> V_95 = F_7 ( V_67 -> V_95 ) ;
V_67 -> V_97 = F_8 ( V_64 -> V_98 ) ;
V_67 -> V_97 = F_7 ( V_67 -> V_97 ) ;
V_67 -> V_99 = F_8 ( V_64 -> V_100 ) ;
V_67 -> V_99 = F_7 ( V_67 -> V_99 ) ;
V_67 -> V_101 = V_64 -> V_102 ;
V_67 -> V_101 = F_7 ( V_67 -> V_101 ) ;
V_67 -> V_103 = V_64 -> V_104 ;
V_67 -> V_103 = F_7 ( V_67 -> V_103 ) ;
V_67 -> V_105 = F_8 ( V_64 -> V_106 ) ;
V_67 -> V_105 = F_7 ( V_67 -> V_105 ) ;
}
