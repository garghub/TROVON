T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 = true ;
V_5 ;
if ( V_2 -> V_6 > 32 ) {
F_2 ( V_7 , V_8 , ( L_1 ) ) ;
V_4 = false ;
goto exit;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
if ( ! ( ( V_2 -> V_9 [ V_3 ] >= 0x20 ) && ( V_2 -> V_9 [ V_3 ] <= 0x7e ) ) ) {
F_2 ( V_7 , V_8 , ( L_2 ) ) ;
V_4 = false ;
break;
}
}
exit:
V_10 ;
return V_4 ;
}
T_1 F_3 ( struct V_11 * V_12 )
{
struct V_13 * V_14 , * V_15 ;
T_1 * V_16 = NULL ;
struct V_17 * V_18 = & ( V_12 -> V_19 ) ;
struct V_20 * V_21 = & ( V_18 -> V_22 ) ;
T_1 V_4 = V_23 ;
V_5 ;
F_4 ( & ( V_18 -> V_22 . V_24 ) ) ;
V_15 = F_5 ( V_21 ) ;
V_14 = F_6 ( V_15 ) ;
F_2 ( V_7 , V_25 , ( L_3 , V_15 , V_14 ) ) ;
V_18 -> V_26 . V_27 = - 2 ;
F_7 ( V_18 , V_28 ) ;
V_18 -> V_29 = V_14 ;
V_18 -> V_30 = true ;
if ( F_8 ( V_21 ) ) {
F_9 ( & ( V_18 -> V_22 . V_24 ) ) ;
F_10 ( V_18 , V_28 ) ;
if ( ! V_18 -> V_31 . V_32 ||
V_18 -> V_33 > 0 ) {
F_2 ( V_7 , V_25 , ( L_4 ) ) ;
V_4 = F_11 ( V_12 , & V_18 -> V_34 , 1 , NULL , 0 ) ;
if ( V_23 != V_4 ) {
V_18 -> V_30 = false ;
F_2 ( V_7 , V_8 , ( L_5 ) ) ;
}
} else {
V_18 -> V_30 = false ;
V_4 = V_35 ;
}
goto exit;
} else {
int V_36 ;
F_9 ( & ( V_18 -> V_22 . V_24 ) ) ;
V_36 = F_12 ( V_18 ) ;
if ( V_36 == V_23 ) {
V_18 -> V_30 = false ;
F_13 ( & V_18 -> V_37 , V_38 ) ;
} else {
if ( F_14 ( V_18 , V_39 ) == true ) {
struct V_40 * V_41 = & ( V_12 -> V_42 . V_43 ) ;
V_18 -> V_44 = V_45 ;
V_16 = V_12 -> V_42 . V_43 . V_46 ;
F_15 ( & V_41 -> V_9 , 0 , sizeof( struct V_1 ) ) ;
memcpy ( & V_41 -> V_9 , & V_18 -> V_34 , sizeof( struct V_1 ) ) ;
F_16 ( V_12 ) ;
F_17 ( V_16 ) ;
if ( F_18 ( V_12 ) != V_23 ) {
F_2 ( V_7 , V_8 , ( L_6 ) ) ;
V_4 = false ;
goto exit;
}
V_18 -> V_30 = false ;
F_2 ( V_7 , V_25 ,
( L_7 ) ) ;
} else {
F_10 ( V_18 , V_28 ) ;
if ( ! V_18 -> V_31 . V_32 ||
V_18 -> V_33 > 0 ) {
V_4 = F_11 ( V_12 , & V_18 -> V_34 , 1 , NULL , 0 ) ;
if ( V_23 != V_4 ) {
V_18 -> V_30 = false ;
F_2 ( V_7 , V_8 , ( L_8 ) ) ;
}
} else {
V_4 = V_35 ;
V_18 -> V_30 = false ;
}
}
}
}
exit:
V_10 ;
return V_4 ;
}
T_1 F_19 ( struct V_11 * V_12 , T_1 * V_47 )
{
T_1 V_48 = V_23 ;
T_2 V_49 = 0 ;
struct V_17 * V_18 = & V_12 -> V_19 ;
V_5 ;
F_20 ( V_25 , L_9 , V_47 ) ;
if ( ( V_47 [ 0 ] == 0x00 && V_47 [ 1 ] == 0x00 && V_47 [ 2 ] == 0x00 &&
V_47 [ 3 ] == 0x00 && V_47 [ 4 ] == 0x00 && V_47 [ 5 ] == 0x00 ) ||
( V_47 [ 0 ] == 0xFF && V_47 [ 1 ] == 0xFF && V_47 [ 2 ] == 0xFF &&
V_47 [ 3 ] == 0xFF && V_47 [ 4 ] == 0xFF && V_47 [ 5 ] == 0xFF ) ) {
V_48 = V_35 ;
goto exit;
}
F_4 ( & V_18 -> V_24 ) ;
F_21 ( L_10 , F_22 ( V_18 ) ) ;
if ( F_14 ( V_18 , V_50 ) == true )
goto V_51;
else if ( F_14 ( V_18 , V_28 ) )
goto V_52;
if ( F_14 ( V_18 , V_53 | V_45 ) ) {
F_2 ( V_7 , V_25 , ( L_11 ) ) ;
if ( F_23 ( & V_18 -> V_26 . V_54 . V_46 , V_47 , V_55 ) ) {
if ( F_14 ( V_18 , V_56 ) == false )
goto V_52;
} else {
F_2 ( V_7 , V_25 , ( L_12 ) ) ;
F_2 ( V_7 , V_25 , ( L_13 , ( V_47 ) ) ) ;
F_2 ( V_7 , V_25 , ( L_14 , ( V_18 -> V_26 . V_54 . V_46 ) ) ) ;
F_24 ( V_12 , 0 , true ) ;
if ( F_14 ( V_18 , V_53 ) == true )
F_25 ( V_12 ) ;
F_26 ( V_12 , 1 ) ;
if ( ( F_14 ( V_18 , V_45 ) == true ) ) {
F_10 ( V_18 , V_45 ) ;
F_7 ( V_18 , V_39 ) ;
}
}
}
V_51:
if ( V_12 -> V_57 . V_58 ) {
V_49 = V_59 ;
if ( ( V_49 - V_12 -> V_57 . V_60 ) > 60 * V_61 ) {
V_12 -> V_57 . V_58 = false ;
V_12 -> V_57 . V_60 = 0 ;
} else {
V_48 = V_35 ;
goto V_52;
}
}
memcpy ( & V_18 -> V_62 , V_47 , V_55 ) ;
V_18 -> V_63 = true ;
if ( F_14 ( V_18 , V_50 ) )
V_18 -> V_30 = true ;
else
V_48 = F_3 ( V_12 ) ;
V_52:
F_9 ( & V_18 -> V_24 ) ;
exit:
F_2 ( V_7 , V_8 ,
( L_15 , V_48 ) ) ;
V_10 ;
return V_48 ;
}
T_1 F_27 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
T_1 V_48 = V_23 ;
T_2 V_49 = 0 ;
struct V_17 * V_18 = & V_12 -> V_19 ;
struct V_64 * V_65 = & V_18 -> V_26 ;
V_5 ;
F_20 ( V_25 , L_16 ,
V_2 -> V_9 , F_22 ( V_18 ) ) ;
if ( ! V_12 -> V_66 ) {
F_2 ( V_7 , V_8 ,
( L_17 ) ) ;
V_48 = V_35 ;
goto exit;
}
F_4 ( & V_18 -> V_24 ) ;
F_21 ( L_18 , F_22 ( V_18 ) ) ;
if ( F_14 ( V_18 , V_50 ) == true ) {
goto V_51;
} else if ( F_14 ( V_18 , V_28 ) == true ) {
goto V_52;
}
if ( F_14 ( V_18 , V_53 | V_45 ) ) {
F_2 ( V_7 , V_25 ,
( L_19 ) ) ;
if ( ( V_18 -> V_34 . V_6 == V_2 -> V_6 ) &&
( F_23 ( & V_18 -> V_34 . V_9 , V_2 -> V_9 , V_2 -> V_6 ) ) ) {
if ( ( F_14 ( V_18 , V_56 ) == false ) ) {
F_2 ( V_7 , V_8 ,
( L_20 ,
F_22 ( V_18 ) ) ) ;
if ( ! F_28 ( V_12 , V_65 ) ) {
F_24 ( V_12 , 0 , true ) ;
if ( F_14 ( V_18 , V_53 ) == true )
F_25 ( V_12 ) ;
F_26 ( V_12 , 1 ) ;
if ( F_14 ( V_18 , V_45 ) == true ) {
F_10 ( V_18 , V_45 ) ;
F_7 ( V_18 , V_39 ) ;
}
} else {
goto V_52;
}
} else {
F_29 ( V_12 , V_67 , 1 ) ;
}
} else {
F_2 ( V_7 , V_25 , ( L_21 ) ) ;
F_2 ( V_7 , V_25 , ( L_22 , V_2 -> V_9 , ( unsigned int ) V_2 -> V_6 ) ) ;
F_2 ( V_7 , V_25 , ( L_23 , V_18 -> V_34 . V_9 , ( unsigned int ) V_18 -> V_34 . V_6 ) ) ;
F_24 ( V_12 , 0 , true ) ;
if ( F_14 ( V_18 , V_53 ) == true )
F_25 ( V_12 ) ;
F_26 ( V_12 , 1 ) ;
if ( F_14 ( V_18 , V_45 ) == true ) {
F_10 ( V_18 , V_45 ) ;
F_7 ( V_18 , V_39 ) ;
}
}
}
V_51:
if ( V_12 -> V_57 . V_58 ) {
V_49 = V_59 ;
if ( ( V_49 - V_12 -> V_57 . V_60 ) > 60 * V_61 ) {
V_12 -> V_57 . V_58 = false ;
V_12 -> V_57 . V_60 = 0 ;
} else {
V_48 = V_35 ;
goto V_52;
}
}
memcpy ( & V_18 -> V_34 , V_2 , sizeof( struct V_1 ) ) ;
V_18 -> V_63 = false ;
if ( F_14 ( V_18 , V_50 ) == true ) {
V_18 -> V_30 = true ;
} else {
V_48 = F_3 ( V_12 ) ;
}
V_52:
F_9 ( & V_18 -> V_24 ) ;
exit:
F_2 ( V_7 , V_8 ,
( L_24 , V_48 ) ) ;
V_10 ;
return V_48 ;
}
T_1 F_30 ( struct V_11 * V_12 ,
enum V_68 V_69 )
{
struct V_17 * V_18 = & V_12 -> V_19 ;
struct V_64 * V_26 = & V_18 -> V_26 ;
enum V_68 * V_70 = & ( V_26 -> V_54 . V_71 ) ;
V_5 ;
F_2 ( V_7 , V_72 ,
( L_25 ,
* V_70 , V_69 , F_22 ( V_18 ) ) ) ;
if ( * V_70 != V_69 ) {
F_4 ( & V_18 -> V_24 ) ;
F_2 ( V_7 , V_25 , ( L_26 ) ) ;
if ( * V_70 == V_73 ) {
V_26 -> V_27 = - 1 ;
#ifdef F_31
F_32 ( V_12 ) ;
#endif
}
if ( ( F_14 ( V_18 , V_53 ) ) ||
( * V_70 == V_74 ) )
F_24 ( V_12 , 0 , true ) ;
if ( ( F_14 ( V_18 , V_53 ) ) ||
( F_14 ( V_18 , V_45 ) ) )
F_26 ( V_12 , 1 ) ;
if ( ( * V_70 == V_75 ) || ( * V_70 == V_74 ) ) {
if ( F_14 ( V_18 , V_53 ) == true )
F_25 ( V_12 ) ;
}
* V_70 = V_69 ;
F_10 ( V_18 , ~ V_76 ) ;
switch ( V_69 ) {
case V_74 :
F_7 ( V_18 , V_39 ) ;
break;
case V_75 :
F_7 ( V_18 , V_56 ) ;
break;
case V_73 :
F_7 ( V_18 , V_77 ) ;
#ifdef F_31
F_33 ( V_12 ) ;
#endif
break;
case V_78 :
case V_79 :
break;
}
F_9 ( & V_18 -> V_24 ) ;
}
V_10 ;
return true ;
}
T_1 F_34 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = & V_12 -> V_19 ;
V_5 ;
F_4 ( & V_18 -> V_24 ) ;
if ( F_14 ( V_18 , V_53 ) ) {
F_2 ( V_7 , V_25 ,
( L_27 ) ) ;
F_24 ( V_12 , 0 , true ) ;
F_25 ( V_12 ) ;
F_26 ( V_12 , 1 ) ;
F_35 ( V_12 ) ;
}
F_9 ( & V_18 -> V_24 ) ;
V_10 ;
return true ;
}
T_1 F_36 ( struct V_11 * V_12 , struct V_1 * V_80 , int V_81 )
{
struct V_17 * V_18 = & V_12 -> V_19 ;
T_1 V_82 = true ;
V_5 ;
F_2 ( V_7 , V_8 , ( L_28 , F_22 ( V_18 ) ) ) ;
if ( V_12 == NULL ) {
V_82 = false ;
goto exit;
}
if ( ! V_12 -> V_66 ) {
V_82 = false ;
F_2 ( V_7 , V_8 , ( L_29 ) ) ;
goto exit;
}
if ( ( F_14 ( V_18 , V_50 | V_28 ) ) ||
( V_18 -> V_31 . V_32 ) ) {
F_2 ( V_7 , V_8 , ( L_30 , F_22 ( V_18 ) ) ) ;
V_82 = true ;
if ( F_14 ( V_18 , ( V_50 | V_28 ) ) == true ) {
F_2 ( V_7 , V_8 , ( L_31 ) ) ;
} else {
F_2 ( V_7 , V_8 , ( L_32 ) ) ;
}
} else {
if ( F_37 ( V_12 ) ) {
F_21 ( V_83 L_33 , F_38 ( V_12 ) ) ;
F_39 ( V_12 ) ;
return V_23 ;
}
F_4 ( & V_18 -> V_24 ) ;
V_82 = F_11 ( V_12 , V_80 , V_81 , NULL , 0 ) ;
F_9 ( & V_18 -> V_24 ) ;
}
exit:
V_10 ;
return V_82 ;
}
T_1 F_40 ( struct V_11 * V_12 , enum V_84 V_85 )
{
struct V_86 * V_87 = & V_12 -> V_57 ;
int V_82 ;
T_1 V_4 ;
V_5 ;
F_2 ( V_7 , V_25 , ( L_34 , V_85 ) ) ;
V_87 -> V_88 = V_85 ;
F_2 ( V_7 , V_25 ,
( L_35 ,
V_87 -> V_88 ) ) ;
if ( V_87 -> V_88 > 3 )
V_87 -> V_89 = V_90 ;
V_82 = F_41 ( V_12 , V_87 ) ;
if ( V_82 == V_23 )
V_4 = true ;
else
V_4 = false ;
V_10 ;
return V_4 ;
}
T_1 F_42 ( struct V_11 * V_12 , struct V_91 * V_92 )
{
int V_93 , V_82 ;
struct V_86 * V_87 = & ( V_12 -> V_57 ) ;
T_1 V_4 = V_23 ;
V_5 ;
V_93 = V_92 -> V_94 & 0x3fffffff ;
if ( V_93 >= 4 ) {
F_2 ( V_7 , V_8 , ( L_36 ) ) ;
V_4 = false ;
goto exit;
}
switch ( V_92 -> V_95 ) {
case 5 :
V_87 -> V_96 = V_97 ;
F_2 ( V_7 , V_25 , ( L_37 ) ) ;
break;
case 13 :
V_87 -> V_96 = V_98 ;
F_2 ( V_7 , V_25 , ( L_38 ) ) ;
break;
default:
V_87 -> V_96 = V_99 ;
F_2 ( V_7 , V_25 , ( L_39 ) ) ;
break;
}
F_2 ( V_7 , V_25 ,
( L_40 ,
V_92 -> V_95 , V_92 -> V_94 , V_93 ) ) ;
memcpy ( & ( V_87 -> V_100 [ V_93 ] . V_101 [ 0 ] ) , & ( V_92 -> V_102 ) , V_92 -> V_95 ) ;
V_87 -> V_103 [ V_93 ] = V_92 -> V_95 ;
V_87 -> V_104 = V_93 ;
F_2 ( V_7 , V_25 ,
( L_41 ,
V_87 -> V_100 [ V_93 ] . V_101 [ 0 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 1 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 2 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 3 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 4 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 5 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 6 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 7 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 8 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 9 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 10 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 11 ] ,
V_87 -> V_100 [ V_93 ] . V_101 [ 12 ] ) ) ;
V_82 = F_43 ( V_12 , V_87 , V_93 , 1 ) ;
if ( V_82 == V_35 )
V_4 = false ;
exit:
V_10 ;
return V_4 ;
}
T_1 F_44 ( struct V_11 * V_12 , T_2 V_105 )
{
T_1 V_4 = V_23 ;
V_5 ;
if ( V_105 >= 0x80000000 || V_12 == NULL ) {
V_4 = false ;
goto exit;
} else {
int V_82 ;
struct V_86 * V_87 = & ( V_12 -> V_57 ) ;
if ( V_105 < 4 ) {
F_15 ( & V_87 -> V_100 [ V_105 ] , 0 , 16 ) ;
V_82 = F_43 ( V_12 , V_87 , V_105 , 0 ) ;
V_87 -> V_103 [ V_105 ] = 0 ;
if ( V_82 == V_35 )
V_4 = V_35 ;
} else {
V_4 = V_35 ;
}
}
exit:
V_10 ;
return V_4 ;
}
T_1 F_45 ( struct V_11 * V_12 , struct V_106 * V_107 )
{
T_3 V_108 ;
T_1 * V_109 ;
struct V_110 * V_111 ;
T_1 V_112 = false ;
T_1 V_113 = false ;
T_1 V_4 = V_23 ;
V_5 ;
if ( ( ( V_107 -> V_94 & 0x80000000 ) == 0 ) && ( ( V_107 -> V_94 & 0x40000000 ) > 0 ) ) {
F_2 ( V_7 , V_25 ,
( L_42 ,
( int ) ( V_107 -> V_94 & 0x80000000 ) == 0 ) ) ;
F_2 ( V_7 , V_25 ,
( L_43 ,
( int ) ( V_107 -> V_94 & 0x40000000 ) > 0 ) ) ;
F_2 ( V_7 , V_25 ,
( L_44 ,
( int ) V_107 -> V_94 ) ) ;
V_4 = V_35 ;
goto exit;
}
if ( V_107 -> V_94 & 0x40000000 ) {
F_2 ( V_7 , V_8 , ( L_45 ) ) ;
V_109 = F_46 ( & V_12 -> V_19 ) ;
V_111 = F_47 ( & V_12 -> V_114 , V_109 ) ;
if ( ( V_111 != NULL ) && ( V_12 -> V_57 . V_89 == V_90 ) ) {
F_2 ( V_7 , V_8 ,
( L_46 ) ) ;
V_108 = V_111 -> V_115 ;
} else {
F_2 ( V_7 , V_8 , ( L_47 ) ) ;
V_108 = V_12 -> V_57 . V_96 ;
}
F_2 ( V_7 , V_8 ,
( L_48 ,
V_108 ) ) ;
F_2 ( V_7 , V_8 ,
( L_49 ,
V_12 -> V_57 . V_96 ) ) ;
F_2 ( V_7 , V_8 ,
( L_50 ,
V_12 -> V_57 . V_89 ) ) ;
if ( ( V_111 != NULL ) )
F_2 ( V_7 , V_8 ,
( L_51 ,
V_111 -> V_115 ) ) ;
if ( V_107 -> V_94 & 0x000000FF ) {
F_2 ( V_7 , V_8 , ( L_52 ) ) ;
V_4 = V_35 ;
goto exit;
}
if ( F_48 ( V_107 -> V_116 ) == true ) {
F_2 ( V_7 , V_8 , ( L_53 ) ) ;
V_4 = false ;
goto exit;
}
if ( ( V_108 == V_117 ) && ( V_107 -> V_95 != 32 ) ) {
F_2 ( V_7 , V_8 , ( L_54 , V_107 -> V_95 ) ) ;
V_4 = V_35 ;
goto exit;
}
if ( ( V_108 == V_118 ) && ( V_107 -> V_95 != 16 ) ) {
if ( V_107 -> V_95 == 32 ) {
V_107 -> V_95 = 16 ;
} else {
V_4 = V_35 ;
goto exit;
}
}
if ( ( V_108 == V_97 || V_108 == V_98 ) &&
( V_107 -> V_95 != 5 && V_107 -> V_95 != 13 ) ) {
F_2 ( V_7 , V_8 , ( L_55 , V_107 -> V_95 ) ) ;
V_4 = V_35 ;
goto exit;
}
V_112 = false ;
F_2 ( V_7 , V_8 , ( L_56 ) ) ;
F_2 ( V_7 , V_8 , ( L_57 ) ) ;
F_2 ( V_7 , V_8 , ( L_56 ) ) ;
F_2 ( V_7 , V_8 , ( L_58 , V_107 -> V_94 , ( V_107 -> V_94 & 0x3 ) ) ) ;
F_2 ( V_7 , V_8 , ( L_59 , V_107 -> V_95 ) ) ;
F_2 ( V_7 , V_8 , ( L_56 ) ) ;
} else {
F_2 ( V_7 , V_8 , ( L_60 ) ) ;
if ( ( V_12 -> V_57 . V_88 <= 3 ) &&
( V_12 -> V_57 . V_119 == 0 ) ) {
F_2 ( V_7 , V_8 ,
( L_61 ,
V_107 -> V_95 , V_12 -> V_57 . V_96 ,
V_12 -> V_57 . V_119 ) ) ;
switch ( V_107 -> V_95 ) {
case 5 :
V_12 -> V_57 . V_96 = V_97 ;
F_2 ( V_7 , V_8 ,
( L_62 ,
V_12 -> V_57 . V_96 , V_107 -> V_95 ) ) ;
break;
case 13 :
V_12 -> V_57 . V_96 = V_98 ;
F_2 ( V_7 , V_8 ,
( L_62 ,
V_12 -> V_57 . V_96 , V_107 -> V_95 ) ) ;
break;
default:
V_12 -> V_57 . V_96 = V_99 ;
F_2 ( V_7 , V_8 ,
( L_62 ,
V_12 -> V_57 . V_96 , V_107 -> V_95 ) ) ;
break;
}
V_108 = V_12 -> V_57 . V_96 ;
F_2 ( V_7 , V_8 ,
( L_63 ,
V_12 -> V_57 . V_96 ) ) ;
} else {
V_108 = V_12 -> V_57 . V_119 ;
F_2 ( V_7 , V_8 ,
( L_64 ,
V_12 -> V_57 . V_96 , V_108 ,
V_12 -> V_57 . V_119 , V_107 -> V_95 ) ) ;
}
if ( ( F_14 ( & V_12 -> V_19 , V_39 ) == true ) && ( F_48 ( V_107 -> V_116 ) == false ) ) {
F_2 ( V_7 , V_8 ,
( L_65 ) ) ;
V_4 = V_35 ;
goto exit;
}
if ( ( V_108 == V_117 ) && ( V_107 -> V_95 != 32 ) ) {
F_2 ( V_7 , V_8 ,
( L_66 , V_107 -> V_95 ) ) ;
V_4 = V_35 ;
goto exit;
} else if ( V_108 == V_118 && ( V_107 -> V_95 != 16 && V_107 -> V_95 != 32 ) ) {
F_2 ( V_7 , V_8 ,
( L_67 ,
V_107 -> V_95 ) ) ;
V_4 = V_35 ;
goto exit;
}
if ( ( V_108 == V_118 ) && ( V_107 -> V_95 == 32 ) ) {
V_107 -> V_95 = 16 ;
F_2 ( V_7 , V_8 , ( L_68 , V_107 -> V_95 ) ) ;
}
if ( V_107 -> V_94 & 0x8000000 ) {
V_113 = true ;
}
if ( ( F_14 ( & V_12 -> V_19 , V_39 ) ) &&
( F_14 ( & V_12 -> V_19 , V_53 ) ) )
V_113 = true ;
V_112 = true ;
F_2 ( V_7 , V_8 , ( L_56 ) ) ;
F_2 ( V_7 , V_8 , ( L_69 ) ) ;
F_2 ( V_7 , V_8 , ( L_56 ) ) ;
F_2 ( V_7 , V_8 , ( L_58 , V_107 -> V_94 , ( V_107 -> V_94 & 0x3 ) ) ) ;
F_2 ( V_7 , V_8 , ( L_59 , V_107 -> V_95 ) ) ;
F_2 ( V_7 , V_8 , ( L_56 ) ) ;
}
if ( ( V_12 -> V_57 . V_89 != V_90 ) &&
( V_108 == V_97 || V_108 == V_98 ) ) {
T_2 V_105 ;
T_2 V_120 = F_49 ( struct V_106 , V_102 ) + V_107 -> V_95 ;
struct V_91 * V_92 = & V_12 -> V_57 . V_121 ;
F_2 ( V_7 , V_8 , ( L_70 ) ) ;
V_92 -> V_122 = V_120 ;
V_105 = V_107 -> V_94 & 0x7fffffff ;
V_92 -> V_94 = V_105 ;
V_92 -> V_95 = V_107 -> V_95 ;
F_2 ( V_7 , V_8 , ( L_71 ) ) ;
memcpy ( V_92 -> V_102 , V_107 -> V_102 , V_107 -> V_95 ) ;
memcpy ( & ( V_12 -> V_57 . V_100 [ V_105 ] . V_101 [ 0 ] ) , V_107 -> V_102 , V_107 -> V_95 ) ;
V_12 -> V_57 . V_103 [ V_105 ] = V_107 -> V_95 ;
V_12 -> V_57 . V_104 = V_105 ;
V_4 = F_42 ( V_12 , V_92 ) ;
goto exit;
}
if ( V_107 -> V_94 & 0x20000000 ) {
F_2 ( V_7 , V_8 , ( L_72 ) ) ;
if ( V_112 ) {
unsigned long long V_123 = V_107 -> V_124 & 0x00FFFFFFFFFFFFULL ;
memcpy ( & V_12 -> V_57 . V_125 , & V_123 , 8 ) ;
} else {
unsigned long long V_123 = V_107 -> V_124 & 0x00FFFFFFFFFFFFULL ;
memcpy ( & V_12 -> V_57 . V_126 , & V_123 , 8 ) ;
}
}
if ( V_112 ) {
int V_82 ;
if ( V_113 )
V_12 -> V_57 . V_127 = ( T_1 ) V_107 -> V_94 ;
if ( ( V_107 -> V_94 & 0x3 ) == 0 ) {
V_4 = V_35 ;
goto exit;
}
F_15 ( & V_12 -> V_57 . V_128 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , 0 , 16 ) ;
F_15 ( & V_12 -> V_57 . V_129 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , 0 , 16 ) ;
F_15 ( & V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , 0 , 16 ) ;
if ( ( V_107 -> V_94 & 0x10000000 ) ) {
memcpy ( & V_12 -> V_57 . V_129 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , V_107 -> V_102 + 16 , 8 ) ;
memcpy ( & V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , V_107 -> V_102 + 24 , 8 ) ;
F_2 ( V_7 , V_8 ,
( L_73 ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 0 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 1 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 2 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 3 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 4 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 5 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 6 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 7 ] ) ) ;
F_2 ( V_7 , V_8 , ( L_74 ) ) ;
} else {
memcpy ( & V_12 -> V_57 . V_129 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , V_107 -> V_102 + 24 , 8 ) ;
memcpy ( & V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , V_107 -> V_102 + 16 , 8 ) ;
F_2 ( V_7 , V_8 ,
( L_73 ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 0 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 1 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 2 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 3 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 4 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 5 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] . V_101 [ 6 ] ,
V_12 -> V_57 . V_130 [ ( T_1 ) ( ( V_107 -> V_94 - 1 ) & 0x03 ) ] . V_101 [ 7 ] ) ) ;
F_2 ( V_7 , V_8 ,
( L_74 ) ) ;
}
memcpy ( & V_12 -> V_57 . V_128 [ ( T_1 ) ( ( V_107 -> V_94 ) & 0x03 ) ] , V_107 -> V_102 , V_107 -> V_95 ) ;
V_107 -> V_94 = V_107 -> V_94 & 0x03 ;
V_12 -> V_57 . V_131 = true ;
V_12 -> V_57 . V_132 = false ;
F_2 ( V_7 , V_8 , ( L_75 ) ) ;
V_82 = F_43 ( V_12 , & V_12 -> V_57 , V_107 -> V_94 , 1 ) ;
if ( V_82 == V_35 )
V_4 = V_35 ;
goto exit;
} else {
T_1 V_82 ;
V_109 = F_46 ( & V_12 -> V_19 ) ;
V_111 = F_47 ( & V_12 -> V_114 , V_109 ) ;
if ( V_111 != NULL ) {
F_15 ( & V_111 -> V_133 , 0 , 16 ) ;
memcpy ( & V_111 -> V_133 , V_107 -> V_102 , 16 ) ;
if ( V_108 == V_117 ) {
V_12 -> V_57 . V_134 = false ;
F_2 ( V_7 , V_8 , ( L_76 ) ) ;
if ( ( V_107 -> V_94 & 0x10000000 ) ) {
memcpy ( & V_111 -> V_135 , V_107 -> V_102 + 16 , 8 ) ;
memcpy ( & V_111 -> V_136 , V_107 -> V_102 + 24 , 8 ) ;
} else {
memcpy ( & V_111 -> V_135 , V_107 -> V_102 + 24 , 8 ) ;
memcpy ( & V_111 -> V_136 , V_107 -> V_102 + 16 , 8 ) ;
}
}
if ( V_113 ) {
V_82 = F_50 ( V_12 , ( unsigned char * ) V_111 , false ) ;
F_2 ( V_7 , V_8 , ( L_77 ) ) ;
} else {
V_82 = F_50 ( V_12 , ( unsigned char * ) V_111 , true ) ;
F_2 ( V_7 , V_8 , ( L_78 ) ) ;
}
if ( ! V_82 )
V_4 = V_35 ;
}
}
exit:
V_10 ;
return V_4 ;
}
T_1 F_51 ( struct V_11 * V_12 , struct V_137 * V_107 )
{
T_1 * V_109 ;
struct V_110 * V_111 ;
T_1 V_112 = ( V_107 -> V_94 & 0x4000000 ) > 0 ? false : true ;
T_1 V_138 = ( T_1 ) V_107 -> V_94 & 0x03 ;
T_1 V_4 = V_23 ;
V_5 ;
if ( ( V_107 -> V_94 & 0xbffffffc ) > 0 ) {
V_4 = V_35 ;
goto exit;
}
if ( V_112 ) {
F_15 ( & V_12 -> V_57 . V_128 [ V_138 ] , 0 , 16 ) ;
} else {
V_109 = F_46 ( & V_12 -> V_19 ) ;
V_111 = F_47 ( & V_12 -> V_114 , V_109 ) ;
if ( V_111 ) {
F_15 ( & V_111 -> V_133 , 0 , 16 ) ;
} else {
V_4 = V_35 ;
goto exit;
}
}
exit:
V_10 ;
return V_4 ;
}
T_4 F_52 ( struct V_11 * V_11 )
{
int V_3 = 0 ;
T_1 * V_139 ;
T_4 V_140 = 0 , V_141 = 0 ;
struct V_142 * V_143 = & V_11 -> V_144 ;
struct V_145 * V_146 = & ( V_143 -> V_147 ) ;
struct V_148 * V_149 = & V_11 -> V_42 ;
struct V_17 * V_18 = & V_11 -> V_19 ;
struct V_40 * V_150 = & V_18 -> V_26 . V_54 ;
struct V_151 * V_152 ;
T_1 V_153 = 0 ;
T_1 V_154 = 0 , V_155 = 0 , V_156 = 0 ;
T_4 V_157 = 0 ;
T_2 V_158 = 0 ;
if ( V_11 -> V_42 . V_159 == 1 ) {
if ( F_14 ( V_18 , V_160 ) )
return 0 ;
}
if ( ( ! F_14 ( V_18 , V_53 ) ) &&
( ! F_14 ( V_18 , V_45 ) ) )
return 0 ;
if ( V_143 -> V_161 & ( V_162 | V_163 ) ) {
V_139 = F_53 ( & V_150 -> V_164 [ 12 ] , V_165 , & V_158 , V_150 -> V_166 - 12 ) ;
if ( V_139 && V_158 > 0 ) {
V_152 = (struct V_151 * ) ( V_139 + 2 ) ;
memcpy ( & V_157 , V_152 -> V_167 , 2 ) ;
V_154 = ( V_143 -> V_168 && ( V_169 & V_146 -> V_170 . V_171 [ 0 ] ) ) ? 1 : 0 ;
V_155 = ( F_54 ( V_146 -> V_172 . V_173 . V_174 . V_175 ) & V_176 ) ? 1 : 0 ;
V_156 = ( F_54 ( V_146 -> V_172 . V_173 . V_174 . V_175 ) & V_177 ) ? 1 : 0 ;
F_55 ( V_11 , V_178 , ( T_1 * ) ( & V_153 ) ) ;
V_141 = F_56 (
V_153 ,
V_154 & ( V_149 -> V_179 ) ,
V_155 ,
V_156 ,
V_146 -> V_172 . V_173 . V_174 . V_180
) ;
}
} else {
while ( ( V_150 -> V_181 [ V_3 ] != 0 ) && ( V_150 -> V_181 [ V_3 ] != 0xFF ) ) {
V_140 = V_150 -> V_181 [ V_3 ] & 0x7F ;
if ( V_140 > V_141 )
V_141 = V_140 ;
V_3 ++ ;
}
V_141 = V_141 * 10 / 2 ;
}
return V_141 ;
}
int F_57 ( struct V_11 * V_11 , enum V_182 V_183 )
{
if ( V_183 != V_184 && V_183 != V_185 )
return V_35 ;
V_11 -> V_19 . V_183 = V_183 ;
return V_23 ;
}
int F_58 ( struct V_11 * V_11 , T_1 V_186 )
{
return F_59 ( V_11 , V_186 , 1 ) ;
}
int F_60 ( struct V_11 * V_11 , const char * V_187 )
{
int V_186 = V_188 ;
F_21 ( L_79 , V_189 , V_187 ) ;
if ( 0 == strcmp ( V_187 , L_80 ) )
V_186 = V_190 ;
else if ( 0 == strcmp ( V_187 , L_81 ) )
V_186 = V_191 ;
else if ( 0 == strcmp ( V_187 , L_82 ) )
V_186 = V_192 ;
else if ( 0 == strcmp ( V_187 , L_83 ) )
V_186 = V_193 ;
else
F_21 ( L_84 , V_189 , V_187 ) ;
return F_58 ( V_11 , V_186 ) ;
}
