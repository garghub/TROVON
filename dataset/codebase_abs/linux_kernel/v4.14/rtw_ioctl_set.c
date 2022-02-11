T_1 F_1 ( T_1 * V_1 )
{
T_1 V_2 = true ;
if ( F_2 ( V_1 )
|| F_3 ( V_1 )
|| F_4 ( V_1 )
) {
V_2 = false ;
}
return V_2 ;
}
T_1 F_5 ( struct V_3 * V_4 )
{
T_1 V_2 = true ;
if ( V_4 -> V_5 > 32 ) {
F_6 ( V_6 , V_7 , ( L_1 ) ) ;
V_2 = false ;
goto exit;
}
#ifdef F_7
for ( V_8 = 0 ; V_8 < V_4 -> V_5 ; V_8 ++ ) {
if ( ! ( ( V_4 -> V_9 [ V_8 ] >= 0x20 ) && ( V_4 -> V_9 [ V_8 ] <= 0x7e ) ) ) {
F_6 ( V_6 , V_7 , ( L_2 ) ) ;
V_2 = false ;
break;
}
}
#endif
exit:
return V_2 ;
}
T_1 F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 , * V_14 ;
T_1 * V_15 = NULL ;
struct V_16 * V_17 = & ( V_11 -> V_18 ) ;
struct V_19 * V_20 = & ( V_17 -> V_21 ) ;
T_1 V_2 = V_22 ;
F_9 ( & ( V_17 -> V_21 . V_23 ) ) ;
V_14 = F_10 ( V_20 ) ;
V_13 = F_11 ( V_14 ) ;
F_6 ( V_6 , V_24 , ( L_3 , V_14 , V_13 ) ) ;
V_17 -> V_25 . V_26 = - 2 ;
F_12 ( V_17 , V_27 ) ;
V_17 -> V_28 = V_13 ;
V_17 -> V_29 = true ;
if ( F_13 ( & V_20 -> V_20 ) ) {
F_14 ( & ( V_17 -> V_21 . V_23 ) ) ;
F_15 ( V_17 , V_27 ) ;
if ( V_17 -> V_30 . V_31 == false
|| F_16 ( V_11 ) > 0
) {
F_6 ( V_6 , V_24 , ( L_4 ) ) ;
V_2 = F_17 ( V_11 , & V_17 -> V_32 , 1 , NULL , 0 ) ;
if ( V_22 != V_2 ) {
V_17 -> V_29 = false ;
F_6 ( V_6 , V_7 , ( L_5 ) ) ;
}
} else{
V_17 -> V_29 = false ;
V_2 = V_33 ;
}
goto exit;
} else{
int V_34 ;
F_14 ( & ( V_17 -> V_21 . V_23 ) ) ;
V_34 = F_18 ( V_17 ) ;
if ( V_34 == V_22 ) {
V_17 -> V_29 = false ;
F_19 ( & V_17 -> V_35 , V_36 ) ;
} else{
if ( F_20 ( V_17 , V_37 ) == true ) {
struct V_38 * V_39 = & ( V_11 -> V_40 . V_41 ) ;
V_17 -> V_42 = V_43 ;
V_15 = V_11 -> V_40 . V_41 . V_44 ;
memcpy ( & V_39 -> V_9 , & V_17 -> V_32 , sizeof( struct V_3 ) ) ;
F_21 ( V_11 ) ;
F_22 ( V_15 ) ;
if ( F_23 ( V_11 ) != V_22 ) {
F_6 ( V_6 , V_7 , ( L_6 ) ) ;
V_2 = false ;
goto exit;
}
V_17 -> V_29 = false ;
F_6 ( V_6 , V_24 , ( L_7 ) ) ;
} else{
F_15 ( V_17 , V_27 ) ;
if ( V_17 -> V_30 . V_31 == false
|| F_16 ( V_11 ) > 0
) {
V_2 = F_17 ( V_11 , & V_17 -> V_32 , 1 , NULL , 0 ) ;
if ( V_22 != V_2 ) {
V_17 -> V_29 = false ;
F_6 ( V_6 , V_7 , ( L_8 ) ) ;
}
} else{
V_2 = V_33 ;
V_17 -> V_29 = false ;
}
}
}
}
exit:
return V_2 ;
}
T_1 F_24 ( struct V_10 * V_11 , T_1 * V_1 )
{
T_1 V_45 = V_22 ;
struct V_16 * V_17 = & V_11 -> V_18 ;
F_25 ( V_46 , L_9 , V_1 ) ;
if ( ( V_1 [ 0 ] == 0x00 && V_1 [ 1 ] == 0x00 && V_1 [ 2 ] == 0x00 && V_1 [ 3 ] == 0x00 && V_1 [ 4 ] == 0x00 && V_1 [ 5 ] == 0x00 ) ||
( V_1 [ 0 ] == 0xFF && V_1 [ 1 ] == 0xFF && V_1 [ 2 ] == 0xFF && V_1 [ 3 ] == 0xFF && V_1 [ 4 ] == 0xFF && V_1 [ 5 ] == 0xFF ) ) {
V_45 = V_33 ;
goto exit;
}
F_9 ( & V_17 -> V_23 ) ;
F_26 ( L_10 , F_27 ( V_17 ) ) ;
if ( F_20 ( V_17 , V_47 ) == true ) {
goto V_48;
} else if ( F_20 ( V_17 , V_27 ) == true ) {
goto V_49;
}
if ( F_20 ( V_17 , V_50 | V_43 ) == true ) {
F_6 ( V_6 , V_24 , ( L_11 ) ) ;
if ( ! memcmp ( & V_17 -> V_25 . V_51 . V_44 , V_1 , V_52 ) ) {
if ( F_20 ( V_17 , V_53 ) == false )
goto V_49;
} else {
F_6 ( V_6 , V_24 , ( L_12 ) ) ;
F_6 ( V_6 , V_24 , ( L_13 V_54 L_14 , F_28 ( V_1 ) ) ) ;
F_6 ( V_6 , V_24 , ( L_15 V_54 L_14 , F_28 ( V_17 -> V_25 . V_51 . V_44 ) ) ) ;
F_29 ( V_11 , 0 , true ) ;
if ( F_20 ( V_17 , V_50 ) == true )
F_30 ( V_11 ) ;
F_31 ( V_11 , 1 ) ;
if ( ( F_20 ( V_17 , V_43 ) == true ) ) {
F_15 ( V_17 , V_43 ) ;
F_12 ( V_17 , V_37 ) ;
}
}
}
V_48:
if ( F_32 ( V_11 , V_55 ) == V_33 ) {
V_45 = V_33 ;
goto V_49;
}
memset ( & V_17 -> V_32 , 0 , sizeof( struct V_3 ) ) ;
memcpy ( & V_17 -> V_56 , V_1 , V_52 ) ;
V_17 -> V_57 = true ;
if ( F_20 ( V_17 , V_47 ) == true ) {
V_17 -> V_29 = true ;
} else {
V_45 = F_8 ( V_11 ) ;
}
V_49:
F_14 ( & V_17 -> V_23 ) ;
exit:
F_6 ( V_6 , V_7 ,
( L_16 , V_45 ) ) ;
return V_45 ;
}
T_1 F_33 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
T_1 V_45 = V_22 ;
struct V_16 * V_17 = & V_11 -> V_18 ;
struct V_58 * V_59 = & V_17 -> V_25 ;
F_25 ( V_46 , L_17 ,
V_4 -> V_9 , F_27 ( V_17 ) ) ;
if ( V_11 -> V_60 == false ) {
F_6 ( V_6 , V_7 ,
( L_18 ) ) ;
V_45 = V_33 ;
goto exit;
}
F_9 ( & V_17 -> V_23 ) ;
F_26 ( L_19 , F_27 ( V_17 ) ) ;
if ( F_20 ( V_17 , V_47 ) == true ) {
goto V_48;
} else if ( F_20 ( V_17 , V_27 ) == true ) {
goto V_49;
}
if ( F_20 ( V_17 , V_50 | V_43 ) == true ) {
F_6 ( V_6 , V_24 ,
( L_20 ) ) ;
if ( ( V_17 -> V_32 . V_5 == V_4 -> V_5 ) &&
( ! memcmp ( & V_17 -> V_32 . V_9 , V_4 -> V_9 , V_4 -> V_5 ) ) ) {
if ( ( F_20 ( V_17 , V_53 ) == false ) ) {
F_6 ( V_6 , V_7 ,
( L_21 ,
F_27 ( V_17 ) ) ) ;
if ( F_34 ( V_11 , V_59 ) == false ) {
F_29 ( V_11 , 0 , true ) ;
if ( F_20 ( V_17 , V_50 ) == true )
F_30 ( V_11 ) ;
F_31 ( V_11 , 1 ) ;
if ( F_20 ( V_17 , V_43 ) == true ) {
F_15 ( V_17 , V_43 ) ;
F_12 ( V_17 , V_37 ) ;
}
} else{
goto V_49;
}
} else {
F_35 ( V_11 , V_61 , 1 ) ;
}
} else{
F_6 ( V_6 , V_24 , ( L_22 ) ) ;
F_6 ( V_6 , V_24 , ( L_23 , V_4 -> V_9 , ( unsigned int ) V_4 -> V_5 ) ) ;
F_6 ( V_6 , V_24 , ( L_24 , V_17 -> V_32 . V_9 , ( unsigned int ) V_17 -> V_32 . V_5 ) ) ;
F_29 ( V_11 , 0 , true ) ;
if ( F_20 ( V_17 , V_50 ) == true )
F_30 ( V_11 ) ;
F_31 ( V_11 , 1 ) ;
if ( F_20 ( V_17 , V_43 ) == true ) {
F_15 ( V_17 , V_43 ) ;
F_12 ( V_17 , V_37 ) ;
}
}
}
V_48:
if ( F_32 ( V_11 , V_55 ) == V_33 ) {
V_45 = V_33 ;
goto V_49;
}
if ( F_5 ( V_4 ) == false ) {
V_45 = V_33 ;
goto V_49;
}
memcpy ( & V_17 -> V_32 , V_4 , sizeof( struct V_3 ) ) ;
V_17 -> V_57 = false ;
if ( F_20 ( V_17 , V_47 ) == true ) {
V_17 -> V_29 = true ;
} else {
V_45 = F_8 ( V_11 ) ;
}
V_49:
F_14 ( & V_17 -> V_23 ) ;
exit:
F_6 ( V_6 , V_7 ,
( L_25 , V_45 ) ) ;
return V_45 ;
}
T_1 F_36 ( struct V_10 * V_11 , T_1 * V_1 , struct V_3 * V_4 )
{
T_1 V_45 = V_22 ;
bool V_62 = true ;
bool V_63 = true ;
struct V_16 * V_17 = & V_11 -> V_18 ;
if ( ! V_4 || F_5 ( V_4 ) == false )
V_63 = false ;
if ( ! V_1 || F_1 ( V_1 ) == false )
V_62 = false ;
if ( V_63 == false && V_62 == false ) {
F_26 ( V_64 L_26 ,
F_37 ( V_11 ) , V_4 , V_63 , V_1 , V_62 ) ;
V_45 = V_33 ;
goto exit;
}
if ( V_11 -> V_60 == false ) {
F_6 ( V_6 , V_7 ,
( L_18 ) ) ;
V_45 = V_33 ;
goto exit;
}
F_9 ( & V_17 -> V_23 ) ;
F_25 ( V_46 , V_64 L_27 ,
F_37 ( V_11 ) , F_27 ( V_17 ) ) ;
if ( F_20 ( V_17 , V_47 ) == true ) {
goto V_48;
} else if ( F_20 ( V_17 , V_27 ) == true ) {
goto V_49;
}
V_48:
if ( F_32 ( V_11 , V_55 ) == V_33 ) {
V_45 = V_33 ;
goto V_49;
}
if ( V_4 && V_63 )
memcpy ( & V_17 -> V_32 , V_4 , sizeof( struct V_3 ) ) ;
else
memset ( & V_17 -> V_32 , 0 , sizeof( struct V_3 ) ) ;
if ( V_1 && V_62 ) {
memcpy ( & V_17 -> V_56 , V_1 , V_52 ) ;
V_17 -> V_57 = true ;
} else {
V_17 -> V_57 = false ;
}
if ( F_20 ( V_17 , V_47 ) == true ) {
V_17 -> V_29 = true ;
} else {
V_45 = F_8 ( V_11 ) ;
}
V_49:
F_14 ( & V_17 -> V_23 ) ;
exit:
return V_45 ;
}
T_1 F_38 ( struct V_10 * V_11 ,
enum V_65 V_66 )
{
struct V_16 * V_17 = & V_11 -> V_18 ;
struct V_58 * V_25 = & V_17 -> V_25 ;
enum V_65 * V_67 = & ( V_25 -> V_51 . V_68 ) ;
F_6 ( V_6 , V_69 ,
( L_28 ,
* V_67 , V_66 , F_27 ( V_17 ) ) ) ;
if ( * V_67 != V_66 ) {
F_6 ( V_6 , V_24 , ( L_29 ) ) ;
if ( * V_67 == V_70 ) {
V_25 -> V_26 = - 1 ;
F_39 ( V_11 ) ;
}
F_9 ( & V_17 -> V_23 ) ;
if ( ( F_20 ( V_17 , V_50 ) == true ) || ( * V_67 == V_71 ) )
F_29 ( V_11 , 0 , true ) ;
if ( ( F_20 ( V_17 , V_50 ) == true ) ||
( F_20 ( V_17 , V_43 ) == true ) )
F_31 ( V_11 , 1 ) ;
if ( ( * V_67 == V_72 ) || ( * V_67 == V_71 ) ) {
if ( F_20 ( V_17 , V_50 ) == true ) {
F_30 ( V_11 ) ;
}
}
* V_67 = V_66 ;
F_15 ( V_17 , ~ V_73 ) ;
switch ( V_66 ) {
case V_71 :
F_12 ( V_17 , V_37 ) ;
break;
case V_72 :
F_12 ( V_17 , V_53 ) ;
break;
case V_70 :
F_12 ( V_17 , V_74 ) ;
F_40 ( V_11 ) ;
break;
case V_75 :
case V_76 :
break;
}
F_14 ( & V_17 -> V_23 ) ;
}
return true ;
}
T_1 F_41 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = & V_11 -> V_18 ;
F_9 ( & V_17 -> V_23 ) ;
if ( F_20 ( V_17 , V_50 ) == true ) {
F_6 ( V_6 , V_24 , ( L_30 ) ) ;
F_29 ( V_11 , 0 , true ) ;
F_30 ( V_11 ) ;
F_42 ( V_11 ) ;
if ( V_33 == F_43 ( V_11 ) )
F_26 ( L_31 , V_55 ) ;
}
F_14 ( & V_17 -> V_23 ) ;
return true ;
}
T_1 F_44 ( struct V_10 * V_11 , struct V_3 * V_77 , int V_78 )
{
struct V_16 * V_17 = & V_11 -> V_18 ;
T_1 V_79 = true ;
F_6 ( V_6 , V_7 , ( L_32 , F_27 ( V_17 ) ) ) ;
if ( V_11 == NULL ) {
V_79 = false ;
goto exit;
}
if ( V_11 -> V_60 == false ) {
V_79 = false ;
F_6 ( V_6 , V_7 , ( L_33 ) ) ;
goto exit;
}
if ( ( F_20 ( V_17 , V_47 | V_27 ) == true ) ||
( V_17 -> V_30 . V_31 == true ) ) {
F_6 ( V_6 , V_7 , ( L_34 , F_27 ( V_17 ) ) ) ;
V_79 = true ;
if ( F_20 ( V_17 , ( V_47 | V_27 ) ) == true ) {
F_6 ( V_6 , V_7 , ( L_35 ) ) ;
} else {
F_6 ( V_6 , V_7 , ( L_36 ) ) ;
}
} else {
if ( F_45 ( V_11 ) ) {
F_26 ( V_64 L_37 , F_37 ( V_11 ) ) ;
F_46 ( V_11 ) ;
return V_22 ;
}
F_9 ( & V_17 -> V_23 ) ;
V_79 = F_17 ( V_11 , V_77 , V_78 , NULL , 0 ) ;
F_14 ( & V_17 -> V_23 ) ;
}
exit:
return V_79 ;
}
T_1 F_47 ( struct V_10 * V_11 , enum V_80 V_81 )
{
struct V_82 * V_83 = & V_11 -> V_84 ;
int V_79 ;
T_1 V_2 ;
F_6 ( V_6 , V_24 , ( L_38 , V_81 ) ) ;
V_83 -> V_85 = V_81 ;
F_6 ( V_6 , V_24 , ( L_39 , V_83 -> V_85 ) ) ;
if ( V_83 -> V_85 > 3 )
V_83 -> V_86 = V_87 ;
V_79 = F_48 ( V_11 , V_83 ) ;
if ( V_79 == V_22 )
V_2 = true ;
else
V_2 = false ;
return V_2 ;
}
T_1 F_49 ( struct V_10 * V_11 , struct V_88 * V_89 )
{
T_1 V_90 ;
T_1 V_91 ;
T_2 V_92 , V_79 ;
struct V_82 * V_83 = & ( V_11 -> V_84 ) ;
T_1 V_2 = V_22 ;
V_90 = ( V_89 -> V_93 & 0x40000000 ) > 0 ? false : true ;
V_91 = ( V_89 -> V_93 & 0x80000000 ) > 0 ? true : false ;
V_92 = V_89 -> V_93 & 0x3fffffff ;
if ( V_92 >= 4 ) {
F_6 ( V_6 , V_7 , ( L_40 ) ) ;
V_2 = false ;
goto exit;
}
switch ( V_89 -> V_94 ) {
case 5 :
V_83 -> V_95 = V_96 ;
F_6 ( V_6 , V_24 , ( L_41 ) ) ;
break;
case 13 :
V_83 -> V_95 = V_97 ;
F_6 ( V_6 , V_24 , ( L_42 ) ) ;
break;
default:
V_83 -> V_95 = V_98 ;
F_6 ( V_6 , V_24 , ( L_43 ) ) ;
break;
}
F_6 ( V_6 , V_24 ,
( L_44 ,
V_89 -> V_94 , V_89 -> V_93 , V_92 ) ) ;
memcpy ( & ( V_83 -> V_99 [ V_92 ] . V_100 [ 0 ] ) , & ( V_89 -> V_101 ) , V_89 -> V_94 ) ;
V_83 -> V_102 [ V_92 ] = V_89 -> V_94 ;
V_83 -> V_103 = V_92 ;
F_6 ( V_6 , V_24 , ( L_45 ,
V_83 -> V_99 [ V_92 ] . V_100 [ 0 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 1 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 2 ] ,
V_83 -> V_99 [ V_92 ] . V_100 [ 3 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 4 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 5 ] ,
V_83 -> V_99 [ V_92 ] . V_100 [ 6 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 7 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 8 ] ,
V_83 -> V_99 [ V_92 ] . V_100 [ 9 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 10 ] , V_83 -> V_99 [ V_92 ] . V_100 [ 11 ] ,
V_83 -> V_99 [ V_92 ] . V_100 [ 12 ] ) ) ;
V_79 = F_50 ( V_11 , V_83 , V_92 , 1 , true ) ;
if ( V_79 == V_33 )
V_2 = false ;
exit:
return V_2 ;
}
T_3 F_51 ( struct V_10 * V_10 )
{
int V_8 = 0 ;
T_3 V_104 = 0 , V_105 = 0 ;
struct V_16 * V_17 = & V_10 -> V_18 ;
struct V_38 * V_106 = & V_17 -> V_25 . V_51 ;
struct V_107 * V_108 = NULL ;
T_1 V_109 = 0 ;
T_1 V_110 = 0 ;
if ( ( F_20 ( V_17 , V_50 ) != true )
&& ( F_20 ( V_17 , V_43 ) != true ) )
return 0 ;
V_108 = F_52 ( & V_10 -> V_111 , F_53 ( V_17 ) ) ;
if ( V_108 == NULL )
return 0 ;
V_109 = F_54 ( V_108 ) ;
if ( F_55 ( V_108 -> V_112 ) ) {
F_56 ( V_10 , V_113 , ( T_1 * ) ( & V_110 ) ) ;
V_105 = F_57 (
V_110 ,
( ( V_108 -> V_114 == V_115 ) ? 1 : 0 ) ,
V_109 ,
V_108 -> V_116 . V_117 . V_118
) ;
} else{
while ( ( V_106 -> V_119 [ V_8 ] != 0 ) && ( V_106 -> V_119 [ V_8 ] != 0xFF ) ) {
V_104 = V_106 -> V_119 [ V_8 ] & 0x7F ;
if ( V_104 > V_105 )
V_105 = V_104 ;
V_8 ++ ;
}
V_105 = V_105 * 10 / 2 ;
}
return V_105 ;
}
