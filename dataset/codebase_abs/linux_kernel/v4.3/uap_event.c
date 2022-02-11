static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
T_1 * V_6 ;
T_2 V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 = NULL ;
int V_12 = V_13 ;
V_2 -> V_14 = false ;
F_2 ( V_4 , V_15 ) ;
V_5 = V_4 -> V_16 ;
V_6 = V_4 -> V_17 ;
F_3 ( V_2 -> V_18 , V_19 , L_1 ,
V_4 -> V_17 , V_4 -> V_16 ) ;
F_4 ( V_4 , V_15 ) ;
while ( ( V_5 >= sizeof( V_9 -> V_20 ) ) ) {
V_9 = (struct V_8 * ) V_6 ;
V_7 = F_5 ( V_9 -> V_20 . V_16 ) ;
if ( V_5 < V_7 + sizeof( V_9 -> V_20 ) )
break;
switch ( F_5 ( V_9 -> V_20 . type ) ) {
case V_21 :
V_2 -> V_22 = true ;
break;
case V_23 :
V_2 -> V_24 = true ;
break;
case V_25 :
V_11 = ( void * ) ( V_6 + 2 ) ;
V_11 -> V_26 . V_16 = ( T_1 ) V_7 ;
V_11 -> V_26 . V_27 =
V_25 ;
F_6 ( V_2 -> V_18 , V_28 ,
L_2
L_3 ,
V_11 -> V_29 & V_12 ) ;
F_7 ( V_2 ) ;
V_2 -> V_14 = true ;
F_8 ( V_2 , V_11 ) ;
break;
default:
break;
}
V_6 += ( V_7 + sizeof( V_9 -> V_20 ) ) ;
V_5 -= ( V_7 + sizeof( V_9 -> V_20 ) ) ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_30 * V_18 = V_2 -> V_18 ;
int V_16 , V_31 ;
T_3 V_32 = V_18 -> V_33 ;
struct V_34 V_35 ;
struct V_36 * V_4 ;
struct V_37 * V_38 ;
T_1 * V_39 ;
struct V_40 * V_41 ;
T_2 V_42 ;
switch ( V_32 ) {
case V_43 :
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_4 = (struct V_36 * )
( V_18 -> V_44 + V_45 ) ;
if ( F_5 ( V_4 -> type ) == V_46 ) {
V_16 = - 1 ;
if ( F_10 ( V_4 -> V_47 ) )
V_16 = 0 ;
else if ( F_11 ( V_4 -> V_47 ) )
V_16 = V_48 ;
if ( V_16 != - 1 ) {
V_35 . V_49 = & V_4 -> V_17 [ V_16 ] ;
V_16 = ( T_1 * ) V_35 . V_49 -
( T_1 * ) & V_4 -> V_47 ;
V_35 . V_50 =
F_5 ( V_4 -> V_16 ) - ( T_2 ) V_16 ;
}
}
F_12 ( V_2 -> V_51 , V_4 -> V_52 , & V_35 ,
V_53 ) ;
V_38 = F_13 ( V_2 , V_4 -> V_52 ) ;
if ( ! V_38 ) {
F_6 ( V_18 , ERROR ,
L_4 ) ;
return - 1 ;
}
if ( ! V_2 -> V_22 )
break;
F_14 ( V_2 , V_35 . V_49 ,
V_35 . V_50 , V_38 ) ;
for ( V_31 = 0 ; V_31 < V_54 ; V_31 ++ ) {
if ( V_38 -> V_55 )
V_38 -> V_56 [ V_31 ] =
V_2 -> V_57 [ V_31 ] . V_58 ;
else
V_38 -> V_56 [ V_31 ] = V_59 ;
}
memset ( V_38 -> V_60 , 0xff , sizeof( V_38 -> V_60 ) ) ;
break;
case V_61 :
V_39 = V_18 -> V_44 +
V_45 ;
F_15 ( V_2 -> V_51 , V_39 , V_53 ) ;
if ( V_2 -> V_22 ) {
F_16 ( V_2 , V_39 ) ;
F_17 ( V_2 , V_39 ) ;
}
F_18 ( V_2 , V_39 ) ;
F_19 ( V_2 , V_39 ) ;
break;
case V_62 :
V_2 -> V_63 = false ;
V_2 -> V_64 = false ;
if ( F_20 ( V_2 -> V_51 ) )
F_21 ( V_2 -> V_51 ) ;
F_22 ( V_2 -> V_51 , V_18 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
break;
case V_65 :
V_2 -> V_63 = true ;
V_2 -> V_64 = true ;
if ( ! F_20 ( V_2 -> V_51 ) )
F_25 ( V_2 -> V_51 ) ;
F_26 ( V_2 -> V_51 , V_18 ) ;
break;
case V_66 :
F_6 ( V_18 , V_28 ,
L_5 , V_32 ) ;
V_2 -> V_64 = false ;
memcpy ( V_2 -> V_51 -> V_67 , V_18 -> V_44 + 2 ,
V_48 ) ;
if ( V_2 -> V_68 )
F_27 ( V_2 ) ;
F_1 ( V_2 , V_18 -> V_69 ) ;
break;
case V_70 :
F_6 ( V_18 , V_28 ,
L_5 , V_32 ) ;
break;
case V_71 :
V_42 = F_5 ( * ( V_72 * ) V_18 -> V_44 ) ;
F_6 ( V_18 , V_28 ,
L_6 , V_42 ) ;
if ( V_2 -> V_63 ) {
V_18 -> V_73 =
F_28 ( T_2 , V_18 -> V_74 , V_42 ) ;
F_6 ( V_18 , V_28 ,
L_7 ,
V_18 -> V_73 ) ;
}
break;
case V_75 :
F_6 ( V_18 , V_28 , L_8 ) ;
if ( V_2 -> V_63 )
F_29 ( V_2 , V_76 ,
V_77 , 0 ,
V_18 -> V_44 , false ) ;
break;
case V_78 :
F_6 ( V_18 , V_28 , L_9 ) ;
if ( V_2 -> V_63 )
F_30 ( V_2 , V_18 -> V_44 ) ;
break;
case V_79 :
F_6 ( V_18 , V_28 , L_10 ) ;
if ( V_2 -> V_63 ) {
V_41 = ( void * ) V_18 -> V_44 ;
F_31 ( V_2 , V_41 ) ;
}
break;
case V_80 :
F_6 ( V_18 , V_28 , L_11 ) ;
if ( V_18 -> V_81 )
return F_32 ( V_2 ,
V_18 -> V_69 -> V_17 ) ;
break;
case V_82 :
F_6 ( V_18 , V_28 , L_12 ) ;
F_33 ( V_2 , V_18 -> V_44 ) ;
break;
case V_83 :
F_6 ( V_18 , V_28 , L_13 ) ;
V_18 -> V_84 = V_85 ;
F_34 ( V_18 ) ;
break;
case V_86 :
F_6 ( V_18 , V_28 , L_14 ) ;
if ( ! V_18 -> V_87 &&
V_2 -> V_63 && V_18 -> V_88 . V_89 ) {
V_18 -> V_87 = true ;
F_6 ( V_18 , V_28 ,
L_15 ) ;
}
V_18 -> V_90 = false ;
if ( V_18 -> V_87 && V_18 -> V_91 ) {
if ( F_35 ( V_2 ) ) {
if ( V_18 -> V_92 ) {
V_18 -> V_84 = V_93 ;
V_18 -> V_94 = false ;
V_18 -> V_95 = false ;
break;
}
if ( ! F_36
( V_2 ,
V_96 |
V_97 ) )
V_18 -> V_84 =
V_98 ;
return 0 ;
}
}
V_18 -> V_84 = V_93 ;
V_18 -> V_94 = false ;
V_18 -> V_95 = false ;
break;
case V_99 :
F_6 ( V_18 , V_28 , L_16 ) ;
F_37 ( V_2 , V_18 -> V_69 ) ;
break;
case V_100 :
F_6 ( V_18 , V_28 , L_17 ) ;
F_38 ( V_2 , V_18 -> V_69 ) ;
break;
case V_101 :
F_39 ( V_18 -> V_102 , L_18 ) ;
F_40 ( V_2 ,
V_18 -> V_69 ) ;
break;
case V_103 :
F_6 ( V_18 , V_28 , L_19 ) ;
F_41 ( V_2 , V_18 -> V_69 ) ;
break;
case V_104 :
F_6 ( V_18 , V_28 , L_20 ) ;
F_42 ( V_2 , V_18 -> V_69 ) ;
break;
default:
F_6 ( V_18 , V_28 ,
L_21 , V_32 ) ;
break;
}
return 0 ;
}
void F_43 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
if ( V_2 -> V_22 && V_38 -> V_55 ) {
F_16 ( V_2 , V_38 -> V_105 ) ;
F_17 ( V_2 , V_38 -> V_105 ) ;
}
F_19 ( V_2 , V_38 -> V_105 ) ;
return;
}
