T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 {
T_1 V_12 ;
T_1 V_13 ;
int type ;
int V_14 ;
int V_15 ;
};
T_1 V_16 = 0 ;
struct V_11 * V_17 ;
struct V_11 V_18 ;
struct V_19 V_20 ;
int V_21 , V_22 ;
V_17 = F_2 ( V_23 , sizeof( * V_17 ) , V_24 ) ;
if ( ! V_17 )
return - V_25 ;
F_3 ( & V_20 ) ;
V_4 -> V_26 =
F_4 ( F_5 ( unsigned , V_4 -> V_26 ,
F_6 ( 1UL << 31 ,
V_20 . V_27 >> ( V_28 - 1 ) ) ) ) ;
V_17 [ V_29 ] . V_12 = V_6 -> V_30 ;
V_17 [ V_31 ] . V_12 = V_6 -> V_32 ;
V_17 [ V_33 ] . V_12 = V_6 -> V_34 ;
V_17 [ V_35 ] . V_12 = V_6 -> V_36 ;
V_17 [ V_37 ] . V_12 = V_6 -> V_38 ;
V_17 [ V_39 ] . V_12 = V_6 -> V_40 ;
V_17 [ V_41 ] . V_12 = V_6 -> V_42 ;
V_17 [ V_43 ] . V_12 = V_6 -> V_44 ;
V_17 [ V_45 ] . V_12 = V_6 -> V_46 ;
V_17 [ V_47 ] . V_12 = V_6 -> V_48 ;
V_17 [ V_49 ] . V_12 = F_7 ( V_2 ) ;
V_17 [ V_29 ] . V_14 = V_4 -> V_50 ;
V_17 [ V_31 ] . V_14 = V_4 -> V_50 * V_4 -> V_51 ;
V_17 [ V_33 ] . V_14 = V_4 -> V_50 ;
V_17 [ V_35 ] . V_14 = V_4 -> V_50 ;
V_17 [ V_37 ] . V_14 = V_4 -> V_52 ;
V_17 [ V_39 ] . V_14 = V_4 -> V_53 ;
V_17 [ V_41 ] . V_14 = F_8 ( unsigned , V_6 -> V_54 , V_55 ) ;
V_17 [ V_43 ] . V_14 = V_4 -> V_56 ;
V_17 [ V_45 ] . V_14 = V_57 ;
V_17 [ V_47 ] . V_14 = V_4 -> V_26 * ( 1 << V_28 ) ;
V_17 [ V_49 ] . V_14 = V_4 -> V_58 ;
for ( V_21 = 0 ; V_21 < V_23 ; ++ V_21 ) {
V_17 [ V_21 ] . type = V_21 ;
V_17 [ V_21 ] . V_14 = F_4 ( V_17 [ V_21 ] . V_14 ) ;
V_17 [ V_21 ] . V_15 = F_9 ( V_17 [ V_21 ] . V_14 ) ;
V_17 [ V_21 ] . V_12 *= V_17 [ V_21 ] . V_14 ;
V_17 [ V_21 ] . V_12 = F_10 ( V_17 [ V_21 ] . V_12 , ( T_1 ) V_59 ) ;
}
for ( V_21 = V_23 ; V_21 > 0 ; -- V_21 )
for ( V_22 = 1 ; V_22 < V_21 ; ++ V_22 ) {
if ( V_17 [ V_22 ] . V_12 > V_17 [ V_22 - 1 ] . V_12 ) {
V_18 = V_17 [ V_22 ] ;
V_17 [ V_22 ] = V_17 [ V_22 - 1 ] ;
V_17 [ V_22 - 1 ] = V_18 ;
}
}
for ( V_21 = 0 ; V_21 < V_23 ; ++ V_21 ) {
if ( V_17 [ V_21 ] . V_12 ) {
V_17 [ V_21 ] . V_13 = V_16 ;
V_16 += V_17 [ V_21 ] . V_12 ;
}
if ( V_16 > V_6 -> V_60 ) {
F_11 ( V_2 , L_1
L_2 ,
( unsigned long long ) V_16 ,
( unsigned long long ) V_6 -> V_60 ) ;
F_12 ( V_17 ) ;
return - V_25 ;
}
if ( V_17 [ V_21 ] . V_12 )
F_13 ( V_2 , L_3
L_4 ,
V_21 , V_61 [ V_17 [ V_21 ] . type ] , V_17 [ V_21 ] . V_15 ,
( unsigned long long ) V_17 [ V_21 ] . V_13 ,
( unsigned long long ) V_17 [ V_21 ] . V_12 ) ;
}
F_13 ( V_2 , L_5 ,
( int ) ( V_16 >> 10 ) ) ;
for ( V_21 = 0 ; V_21 < V_23 ; ++ V_21 ) {
switch ( V_17 [ V_21 ] . type ) {
case V_29 :
V_2 -> V_62 . V_63 = V_17 [ V_21 ] . V_14 ;
V_8 -> V_64 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_65 = V_17 [ V_21 ] . V_15 ;
break;
case V_31 :
for ( V_10 -> V_66 . V_67 = 0 ;
V_4 -> V_50 << V_10 -> V_66 . V_67 < V_17 [ V_21 ] . V_14 ;
++ V_10 -> V_66 . V_67 )
;
V_2 -> V_62 . V_68 = 1 << V_10 -> V_66 . V_67 ;
V_10 -> V_66 . V_69 = ( V_70 ) V_17 [ V_21 ] . V_13 ;
V_8 -> V_69 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_71 = V_10 -> V_66 . V_67 ;
break;
case V_33 :
V_8 -> V_72 = V_17 [ V_21 ] . V_13 ;
break;
case V_35 :
V_8 -> V_73 = V_17 [ V_21 ] . V_13 ;
break;
case V_37 :
V_2 -> V_62 . V_74 = V_17 [ V_21 ] . V_14 ;
V_8 -> V_75 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_76 = V_17 [ V_21 ] . V_15 ;
break;
case V_39 :
V_2 -> V_62 . V_77 = V_17 [ V_21 ] . V_14 ;
V_8 -> V_78 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_79 = V_17 [ V_21 ] . V_15 ;
break;
case V_41 :
V_2 -> V_62 . V_80 = V_17 [ V_21 ] . V_14 ;
V_8 -> V_81 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_82 = V_17 [ V_21 ] . V_15 ;
break;
case V_43 :
V_2 -> V_62 . V_83 = V_17 [ V_21 ] . V_14 ;
V_10 -> V_84 . V_85 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_86 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_87 = V_17 [ V_21 ] . V_15 ;
break;
case V_45 :
V_8 -> V_88 = V_17 [ V_21 ] . V_13 ;
break;
case V_47 :
V_2 -> V_62 . V_89 = V_17 [ V_21 ] . V_14 ;
V_10 -> V_84 . V_90 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_90 = V_17 [ V_21 ] . V_13 ;
break;
case V_49 :
V_2 -> V_62 . V_91 = V_17 [ V_21 ] . V_14 >> 1 ;
V_2 -> V_62 . V_92 = V_17 [ V_21 ] . V_14 >> 1 ;
V_8 -> V_93 = V_17 [ V_21 ] . V_13 ;
V_8 -> V_94 =
F_9 ( F_7 ( V_2 ) ) ;
V_8 -> V_95 = V_17 [ V_21 ] . V_15 ;
V_8 -> V_96 = V_17 [ V_21 ] . V_15 - 1 ;
break;
default:
break;
}
}
V_2 -> V_62 . V_97 = V_98 ;
F_12 ( V_17 ) ;
return V_16 ;
}
