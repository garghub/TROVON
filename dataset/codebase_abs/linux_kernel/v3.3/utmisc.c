const char * F_1 ( T_1 V_1 )
{
T_2 V_2 ;
const char * V_3 = NULL ;
F_2 () ;
V_2 = ( V_1 & ~ V_4 ) ;
switch ( V_1 & V_4 ) {
case V_5 :
if ( V_2 <= V_6 ) {
V_3 = V_7 [ V_2 ] ;
}
break;
case V_8 :
if ( V_2 <= V_9 ) {
V_3 = V_10 [ V_2 ] ;
}
break;
case V_11 :
if ( V_2 <= V_12 ) {
V_3 = V_13 [ V_2 ] ;
}
break;
case V_14 :
if ( V_2 <= V_15 ) {
V_3 = V_16 [ V_2 ] ;
}
break;
case V_17 :
if ( V_2 <= V_18 ) {
V_3 = V_19 [ V_2 ] ;
}
break;
default:
break;
}
return ( F_3 ( const char , V_3 ) ) ;
}
T_3 F_4 ( char * V_20 )
{
if ( ! ( F_5 ( V_20 ,
V_21 ) ) ||
! ( F_5 ( V_20 , V_22 ) ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_3 F_6 ( struct V_23 * V_24 )
{
if ( F_7 ( V_24 -> V_25 , V_26 ) ||
F_7 ( V_24 -> V_25 , V_27 ) ||
F_7 ( V_24 -> V_25 , V_28 ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_1 F_8 ( T_4 * V_29 )
{
T_2 V_30 ;
T_2 V_31 ;
T_2 V_32 ;
T_1 V_1 ;
F_9 ( V_33 ) ;
if ( * V_29 ) {
F_10 ( ( V_34 , L_1 ,
* V_29 ) ) ;
F_11 ( V_35 ) ;
}
V_1 = F_12 ( V_36 ) ;
if ( F_13 ( V_1 ) ) {
F_11 ( V_1 ) ;
}
for ( V_30 = 0 , V_31 = V_37 ;
V_30 < ( V_38 + 1 ) ; V_30 ++ , V_31 ++ ) {
if ( V_31 >= V_38 ) {
V_31 = 0 ;
}
for ( V_32 = V_39 ; V_32 < 32 ; V_32 ++ ) {
if ( V_40 [ V_31 ] == V_41 ) {
break;
}
if ( ! ( V_40 [ V_31 ] & ( 1 << V_32 ) ) ) {
V_40 [ V_31 ] |= ( 1 << V_32 ) ;
V_37 = ( T_3 ) V_31 ;
V_39 = ( T_3 ) ( V_32 + 1 ) ;
* V_29 =
( T_4 ) ( ( V_32 + 1 ) + F_14 ( V_31 ) ) ;
F_15 ( ( V_42 ,
L_2 ,
( unsigned int ) * V_29 ) ) ;
goto exit;
}
}
V_39 = 0 ;
}
V_1 = V_43 ;
F_10 ( ( V_34 ,
L_3 ) ) ;
exit:
( void ) F_16 ( V_36 ) ;
F_11 ( V_1 ) ;
}
void F_17 ( T_4 * V_44 )
{
T_4 V_29 = * V_44 ;
T_1 V_1 ;
T_2 V_45 ;
T_2 V_46 ;
F_18 ( V_47 , V_29 ) ;
* V_44 = 0 ;
if ( V_29 == 0 ) {
F_10 ( ( V_34 , L_4 , V_29 ) ) ;
V_48 ;
}
V_1 = F_12 ( V_36 ) ;
if ( F_13 ( V_1 ) ) {
V_48 ;
}
V_29 -- ;
V_45 = F_19 ( V_29 ) ;
V_46 = 1 << F_20 ( V_29 ) ;
if ( V_40 [ V_45 ] & V_46 ) {
V_40 [ V_45 ] ^= V_46 ;
} else {
F_10 ( ( V_34 ,
L_5 ,
V_29 + 1 ) ) ;
}
( void ) F_16 ( V_36 ) ;
V_48 ;
}
void F_21 ( char * V_49 )
{
char * string ;
F_2 () ;
if ( ! V_49 ) {
return;
}
for ( string = V_49 ; * string ; string ++ ) {
* string = ( char ) F_22 ( * string ) ;
}
return;
}
void F_23 ( char * string , T_3 V_50 )
{
T_2 V_30 ;
if ( ! string ) {
F_24 ( L_6 ) ;
return;
}
F_24 ( L_7 ) ;
for ( V_30 = 0 ; string [ V_30 ] && ( V_30 < V_50 ) ; V_30 ++ ) {
switch ( string [ V_30 ] ) {
case 0x07 :
F_24 ( L_8 ) ;
break;
case 0x08 :
F_24 ( L_9 ) ;
break;
case 0x0C :
F_24 ( L_10 ) ;
break;
case 0x0A :
F_24 ( L_11 ) ;
break;
case 0x0D :
F_24 ( L_12 ) ;
break;
case 0x09 :
F_24 ( L_13 ) ;
break;
case 0x0B :
F_24 ( L_14 ) ;
break;
case '\'' :
case '\"' :
case '\\' :
F_24 ( L_15 , ( int ) string [ V_30 ] ) ;
break;
default:
if ( F_25 ( string [ V_30 ] ) ) {
F_24 ( L_16 , ( int ) string [ V_30 ] ) ;
} else {
F_24 ( L_17 , ( V_51 ) string [ V_30 ] ) ;
}
break;
}
}
F_24 ( L_7 ) ;
if ( V_30 == V_50 && string [ V_30 ] ) {
F_24 ( L_18 ) ;
}
}
T_2 F_26 ( T_2 V_52 )
{
union {
T_2 V_52 ;
T_3 V_53 [ 4 ] ;
} V_54 ;
union {
T_2 V_52 ;
T_3 V_53 [ 4 ] ;
} V_55 ;
F_2 () ;
V_55 . V_52 = V_52 ;
V_54 . V_53 [ 0 ] = V_55 . V_53 [ 3 ] ;
V_54 . V_53 [ 1 ] = V_55 . V_53 [ 2 ] ;
V_54 . V_53 [ 2 ] = V_55 . V_53 [ 1 ] ;
V_54 . V_53 [ 3 ] = V_55 . V_53 [ 0 ] ;
return ( V_54 . V_52 ) ;
}
void F_27 ( T_3 V_56 )
{
if ( V_56 < 2 ) {
V_57 = 32 ;
V_58 = 8 ;
V_59 = 4 ;
} else {
V_57 = 64 ;
V_58 = 16 ;
V_59 = 8 ;
}
}
void
F_28 ( T_3 type ,
struct V_60 * V_61 ,
char * V_62 )
{
T_1 V_1 ;
struct V_63 V_64 ;
F_2 () ;
if ( ! ( V_65 & V_66 ) ) {
return;
}
V_64 . V_67 = V_68 ;
V_1 = F_29 ( V_61 , & V_64 ) ;
if ( F_13 ( V_1 ) ) {
return;
}
switch ( type ) {
case V_69 :
F_24 ( L_19 ) ;
break;
default:
F_24 ( L_20 ) ;
break;
}
F_24 ( L_21 ,
F_30 ( type ) , ( char * ) V_64 . V_70 ) ;
if ( V_62 ) {
F_24 ( L_22 , V_62 ) ;
}
F_24 ( L_23 ) ;
F_31 ( V_64 . V_70 ) ;
}
T_3 F_32 ( char V_71 , T_2 V_72 )
{
if ( ! ( ( V_71 >= 'A' && V_71 <= 'Z' ) ||
( V_71 >= '0' && V_71 <= '9' ) || ( V_71 == '_' ) ) ) {
if ( V_71 == '!' && V_72 == 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
return ( TRUE ) ;
}
T_3 F_33 ( T_2 V_73 )
{
T_2 V_30 ;
F_2 () ;
for ( V_30 = 0 ; V_30 < V_74 ; V_30 ++ ) {
if ( ! F_32
( ( F_3 ( char , & V_73 ) ) [ V_30 ] , V_30 ) ) {
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
T_5 F_34 ( char * V_73 )
{
T_2 V_30 ;
char V_75 [ V_74 ] ;
for ( V_30 = 0 ; V_30 < V_74 ; V_30 ++ ) {
V_75 [ V_30 ] = V_73 [ V_30 ] ;
if ( ! F_32 ( V_73 [ V_30 ] , V_30 ) ) {
V_75 [ V_30 ] = '*' ;
}
}
return ( * ( T_2 * ) V_75 ) ;
}
T_1 F_35 ( char * string , T_2 V_76 , T_6 * V_77 )
{
T_2 V_78 = 0 ;
T_6 V_79 = 0 ;
T_6 V_80 ;
T_6 V_81 ;
T_2 V_82 = ( V_76 == V_83 ) ;
T_2 V_84 = ( V_59 == 4 ) ;
T_3 V_85 = 0 ;
T_3 V_86 = 0 ;
T_3 V_87 = 0 ;
F_36 ( V_88 , string ) ;
switch ( V_76 ) {
case V_83 :
case 16 :
break;
default:
F_11 ( V_89 ) ;
}
if ( ! string ) {
goto V_90;
}
while ( ( * string ) && ( F_37 ( * string ) || * string == '\t' ) ) {
string ++ ;
}
if ( V_82 ) {
if ( ( * string == '0' ) && ( F_38 ( * ( string + 1 ) ) == 'x' ) ) {
V_86 = 1 ;
V_76 = 16 ;
string += 2 ;
} else {
V_76 = 10 ;
}
}
if ( ! ( * string ) || F_37 ( * string ) || * string == '\t' ) {
if ( V_82 ) {
goto V_90;
} else {
goto V_91;
}
}
V_81 = ( V_84 ) ? V_41 : V_92 ;
while ( * string ) {
if ( F_39 ( * string ) ) {
V_78 = ( ( T_3 ) * string ) - '0' ;
} else if ( V_76 == 10 ) {
V_87 = 1 ;
} else {
V_78 = ( T_3 ) F_22 ( * string ) ;
if ( F_40 ( ( char ) V_78 ) ) {
V_78 = V_78 - 'A' + 10 ;
} else {
V_87 = 1 ;
}
}
if ( V_87 ) {
if ( V_82 ) {
goto V_90;
} else {
break;
}
} else if ( ( V_85 == 0 ) && ( V_78 == 0 )
&& ! V_86 ) {
string ++ ;
continue;
}
V_85 ++ ;
if ( V_86 && ( ( V_85 > 16 )
|| ( ( V_85 > 8 ) && V_84 ) ) ) {
goto V_90;
}
( void ) F_41 ( ( V_81 - ( T_6 ) V_78 ) ,
V_76 , & V_80 , NULL ) ;
if ( V_79 > V_80 ) {
if ( V_82 ) {
goto V_90;
} else {
break;
}
}
V_79 *= V_76 ;
V_79 += V_78 ;
string ++ ;
}
V_91:
F_15 ( ( V_93 , L_24 ,
F_42 ( V_79 ) ) ) ;
* V_77 = V_79 ;
F_11 ( V_94 ) ;
V_90:
if ( V_76 == 10 ) {
F_11 ( V_95 ) ;
} else {
F_11 ( V_96 ) ;
}
}
T_1
F_43 ( union V_97 * V_98 ,
T_7 V_99 ,
union V_100 * * V_101 )
{
union V_100 * V_102 ;
F_2 () ;
if ( ! V_98 ) {
return ( V_94 ) ;
}
V_102 = F_44 ( V_98 , V_99 ) ;
if ( ! V_102 ) {
return ( V_103 ) ;
}
F_45 ( V_101 , V_102 ) ;
return ( V_94 ) ;
}
T_1
F_46 ( union V_97 * V_104 ,
void * V_105 ,
T_8 V_106 , void * V_107 )
{
T_1 V_1 = V_94 ;
union V_100 * V_101 = NULL ;
union V_100 * V_102 ;
T_2 V_108 ;
union V_97 * V_109 ;
F_9 ( V_110 ) ;
V_102 = F_47 ( V_104 , V_105 , 0 ) ;
if ( ! V_102 ) {
F_11 ( V_103 ) ;
}
while ( V_102 ) {
V_108 = V_102 -> V_111 . V_45 ;
V_109 = (union V_97 * )
V_102 -> V_111 . V_104 -> V_112 . V_113 [ V_108 ] ;
if ( ( ! V_109 ) ||
( F_48 ( V_109 ) !=
V_114 )
|| ( V_109 -> V_115 . type != V_116 ) ) {
V_1 =
V_106 ( V_117 ,
V_109 , V_102 , V_107 ) ;
if ( F_13 ( V_1 ) ) {
F_11 ( V_1 ) ;
}
V_102 -> V_111 . V_45 ++ ;
while ( V_102 -> V_111 . V_45 >=
V_102 -> V_111 . V_104 -> V_112 . V_118 ) {
F_49 ( V_102 ) ;
V_102 = F_50 ( & V_101 ) ;
if ( ! V_102 ) {
F_11 ( V_94 ) ;
}
V_102 -> V_111 . V_45 ++ ;
}
} else {
V_1 =
V_106 ( V_119 ,
V_109 , V_102 , V_107 ) ;
if ( F_13 ( V_1 ) ) {
F_11 ( V_1 ) ;
}
F_45 ( & V_101 , V_102 ) ;
V_102 = F_47 ( V_109 ,
V_102 -> V_111 .
V_120 , 0 ) ;
if ( ! V_102 ) {
while ( V_101 ) {
V_102 =
F_50
( & V_101 ) ;
F_49 ( V_102 ) ;
}
F_11 ( V_103 ) ;
}
}
}
F_11 ( V_121 ) ;
}
