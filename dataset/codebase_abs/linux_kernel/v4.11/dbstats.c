static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
T_1 V_3 ;
#endif
F_3 ( L_1 , V_2 -> V_4 ) ;
if ( V_2 -> V_5 > 0 ) {
F_3
( L_2
L_3 , V_2 -> V_6 ,
V_2 -> V_5 , V_2 -> V_5 - V_2 -> V_6 ,
( V_2 -> V_6 * V_2 -> V_7 ) ) ;
}
#ifdef F_2
if ( V_2 -> V_5 > 0 ) {
F_3
( L_4
L_3 , V_2 -> V_8 , V_2 -> V_9 ,
V_2 -> V_8 - V_2 -> V_9 , V_2 -> V_7 ) ;
}
V_3 = F_4 ( V_2 ) ;
if ( V_2 -> V_7 ) {
F_3
( L_5
L_6 , V_2 -> V_10 ,
V_2 -> V_11 , V_2 -> V_12 ,
V_3 * V_2 -> V_7 , V_3 ) ;
} else {
F_3
( L_7
L_8 ,
V_2 -> V_10 , V_2 -> V_11 ,
V_2 -> V_12 , V_2 -> V_13 , V_3 ,
V_2 -> V_14 ) ;
}
#endif
}
static void F_5 ( union V_15 * V_16 )
{
T_1 V_17 ;
if ( ! V_16 ) {
return;
}
V_18 ++ ;
if ( V_16 -> V_19 . type > V_20 ) {
V_21 ++ ;
} else {
V_22 [ V_16 -> V_19 . type ] ++ ;
}
switch ( V_16 -> V_19 . type ) {
case V_23 :
for ( V_17 = 0 ; V_17 < V_16 -> V_24 . V_25 ; V_17 ++ ) {
F_5 ( V_16 -> V_24 . V_26 [ V_17 ] ) ;
}
break;
case V_27 :
F_5 ( V_16 -> V_28 . V_29 [ 0 ] ) ;
F_5 ( V_16 -> V_28 . V_29 [ 1 ] ) ;
F_5 ( V_16 -> V_28 . V_30 ) ;
break;
case V_31 :
if ( F_6 ( V_16 ) ) {
V_22 [ V_31 ] ++ ;
}
break;
case V_32 :
V_22 [ V_33 ] ++ ;
F_5 ( V_16 -> V_34 . V_30 ) ;
break;
case V_35 :
F_5 ( V_16 -> V_36 .
V_29 [ 0 ] ) ;
F_5 ( V_16 -> V_36 .
V_29 [ 1 ] ) ;
break;
case V_37 :
F_5 ( V_16 -> V_38 . V_29 [ 0 ] ) ;
F_5 ( V_16 -> V_38 . V_29 [ 1 ] ) ;
F_5 ( V_16 -> V_38 . V_30 ) ;
break;
case V_39 :
F_5 ( V_16 -> V_40 . V_29 [ 0 ] ) ;
F_5 ( V_16 -> V_40 . V_29 [ 1 ] ) ;
F_5 ( V_16 -> V_40 . V_30 ) ;
break;
default:
break;
}
}
static T_2
F_7 ( T_3 V_41 ,
T_1 V_42 ,
void * V_43 , void * * V_44 )
{
struct V_45 * V_46 ;
union V_15 * V_16 ;
T_1 type ;
V_47 ++ ;
V_46 = (struct V_45 * ) V_41 ;
V_16 = F_8 ( V_46 ) ;
F_5 ( V_16 ) ;
type = V_46 -> type ;
if ( type > V_20 ) {
V_48 ++ ;
} else {
V_49 [ type ] ++ ;
}
return ( V_50 ) ;
#ifdef F_9
if ( F_10 ( V_51 -> V_52 ) ) {
V_53 ++ ;
}
if ( V_54 ) {
V_55 ++ ;
}
V_56 ++ ;
V_51 = F_11 ( V_57 , V_51 ) ;
V_58 = ( V_56 - V_55 ) *
( T_1 ) sizeof( union V_59 ) ;
V_60 =
V_55 * ( T_1 ) sizeof( union V_59 ) ;
V_61 =
V_53 * ( T_1 ) sizeof( struct V_45 ) ;
V_62 =
V_53 * ( T_1 ) sizeof( union V_15 ) ;
#endif
}
static void F_12 ( void )
{
T_1 V_17 ;
V_47 = 0 ;
V_18 = 0 ;
V_21 = 0 ;
for ( V_17 = 0 ; V_17 < ( V_20 - 1 ) ; V_17 ++ ) {
V_22 [ V_17 ] = 0 ;
V_49 [ V_17 ] = 0 ;
}
( void ) F_13 ( V_63 , V_64 ,
V_65 , FALSE ,
F_7 , NULL , NULL ,
NULL ) ;
}
T_2 F_14 ( char * V_66 )
{
T_1 V_17 ;
T_1 V_67 ;
F_15 ( V_66 ) ;
V_67 = F_16 ( V_66 , V_68 ) ;
if ( V_67 == V_69 ) {
F_3 ( L_9 ) ;
return ( V_50 ) ;
}
switch ( V_67 ) {
case V_70 :
#ifdef F_2
F_17 () ;
#endif
break;
case V_71 :
F_3 ( L_10 ) ;
break;
case V_72 :
F_12 () ;
F_3
( L_11 ) ;
F_3 ( L_12 ,
L_13 , L_14 , L_15 ) ;
for ( V_17 = 0 ; V_17 < V_20 ; V_17 ++ ) {
F_3 ( L_16 ,
F_18 ( V_17 ) ,
V_49 [ V_17 ] ,
V_22 [ V_17 ] ) ;
}
F_3 ( L_16 , L_17 ,
V_48 ,
V_21 ) ;
F_3 ( L_16 , L_18 ,
V_47 , V_18 ) ;
break;
case V_73 :
#ifdef F_2
F_3
( L_19 ) ;
F_1 ( V_74 ) ;
F_1 ( V_75 ) ;
#endif
#ifdef F_19
F_3
( L_20 ) ;
F_1 ( V_76 ) ;
F_1 ( V_77 ) ;
F_1 ( V_78 ) ;
F_1 ( V_79 ) ;
#endif
break;
case V_80 :
F_3 ( L_21 ) ;
F_3 ( L_22 ,
V_81 ) ;
F_3 ( L_23 ,
V_82 ) ;
F_3 ( L_24 ) ;
F_3 ( L_25 ) ;
for ( V_17 = 0 ; V_17 < V_83 ; V_17 ++ ) {
F_3 ( L_26 ,
F_20 ( V_17 ) ,
V_84 [ V_17 ] . V_85 ) ;
}
break;
case V_86 :
F_3 ( L_27 ) ;
F_3 ( L_28 ,
sizeof( struct V_87 ) ) ;
F_3 ( L_29 ,
sizeof( struct V_88 ) ) ;
F_3 ( L_30 ,
sizeof( struct V_89 ) ) ;
F_3 ( L_31 ,
sizeof( struct V_90 ) ) ;
F_3 ( L_32 ,
sizeof( struct V_91 ) ) ;
F_3 ( L_33 ,
sizeof( struct V_92 ) ) ;
F_3 ( L_34 ,
sizeof( struct V_93 ) ) ;
F_3 ( L_35 ,
sizeof( struct V_94 ) ) ;
F_3 ( L_36 ,
sizeof( struct V_95 ) ) ;
F_3 ( L_37 ,
sizeof( struct V_96 ) ) ;
F_3 ( L_38 ,
sizeof( struct V_97 ) ) ;
F_3 ( L_39 ,
sizeof( struct V_98 ) ) ;
F_3 ( L_40 ,
sizeof( struct V_99 ) ) ;
F_3 ( L_41 ,
sizeof( struct V_100 ) ) ;
F_3 ( L_42 ,
sizeof( struct V_101 ) ) ;
F_3 ( L_43 ,
sizeof( struct V_102 ) ) ;
F_3 ( L_44 ,
sizeof( struct V_103 ) ) ;
F_3 ( L_45 ,
sizeof( struct V_104 ) ) ;
F_3 ( L_46 ,
sizeof( struct V_105 ) ) ;
F_3 ( L_47 ,
sizeof( struct V_106 ) ) ;
F_3 ( L_48 ,
sizeof( struct V_107 ) ) ;
F_3 ( L_49 ,
sizeof( struct V_108 ) ) ;
F_3 ( L_24 ) ;
F_3 ( L_50 ,
sizeof( struct V_109 ) ) ;
F_3 ( L_51 ,
sizeof( struct V_110 ) ) ;
F_3 ( L_52 ,
sizeof( struct V_111 ) ) ;
F_3 ( L_53 ,
sizeof( union V_15 ) ) ;
F_3 ( L_54 ,
sizeof( struct V_45 ) ) ;
F_3 ( L_55 ,
sizeof( union V_112 ) ) ;
F_3 ( L_24 ) ;
F_3 ( L_56 ,
sizeof( union V_113 ) ) ;
F_3 ( L_57 ,
sizeof( struct V_114 ) ) ;
F_3 ( L_58 ,
sizeof( struct V_115 ) ) ;
F_3 ( L_59 ,
sizeof( struct V_116 ) ) ;
F_3 ( L_60 ,
sizeof( struct V_117 ) ) ;
F_3 ( L_61 ,
sizeof( struct V_118 ) ) ;
F_3 ( L_62 ,
sizeof( struct V_119 ) ) ;
F_3 ( L_63 ,
sizeof( struct V_120 ) ) ;
F_3 ( L_64 ,
sizeof( struct V_121 ) ) ;
F_3 ( L_65 ,
sizeof( struct V_122 ) ) ;
break;
case V_123 :
#if F_21 ( V_124 )
V_67 =
( T_1 ) F_22 ( V_125 ,
V_126 ) ;
F_3 ( L_66 ) ;
F_3 ( L_67 ,
V_125 ) ;
F_3 ( L_68 ,
V_126 ) ;
F_3 ( L_69 , V_67 ,
V_67 ) ;
F_3 ( L_70 ,
V_127 ) ;
#endif
break;
default:
break;
}
F_3 ( L_24 ) ;
return ( V_50 ) ;
}
