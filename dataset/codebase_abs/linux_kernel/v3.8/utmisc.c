void F_1 ( char * V_1 )
{
if ( ! V_1 ) {
return;
}
while ( * V_1 ) {
if ( * V_1 == '\\' ) {
* V_1 = '/' ;
}
V_1 ++ ;
}
}
T_1 F_2 ( char * V_2 )
{
if ( ! ( F_3 ( V_2 ,
V_3 ) ) ||
! ( F_3 ( V_2 , V_4 ) ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_1 F_4 ( struct V_5 * V_6 )
{
if ( F_5 ( V_6 -> V_7 , V_8 ) ||
F_5 ( V_6 -> V_7 , V_9 ) ||
F_5 ( V_6 -> V_7 , V_10 ) ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
T_2 F_6 ( T_3 * V_11 )
{
T_4 V_12 ;
T_4 V_13 ;
T_4 V_14 ;
T_2 V_15 ;
F_7 ( V_16 ) ;
if ( * V_11 ) {
F_8 ( ( V_17 , L_1 ,
* V_11 ) ) ;
F_9 ( V_18 ) ;
}
V_15 = F_10 ( V_19 ) ;
if ( F_11 ( V_15 ) ) {
F_9 ( V_15 ) ;
}
for ( V_12 = 0 , V_13 = V_20 ;
V_12 < ( V_21 + 1 ) ; V_12 ++ , V_13 ++ ) {
if ( V_13 >= V_21 ) {
V_13 = 0 ;
}
for ( V_14 = V_22 ; V_14 < 32 ; V_14 ++ ) {
if ( V_23 [ V_13 ] == V_24 ) {
break;
}
if ( ! ( V_23 [ V_13 ] & ( 1 << V_14 ) ) ) {
V_23 [ V_13 ] |= ( 1 << V_14 ) ;
V_20 = ( T_1 ) V_13 ;
V_22 = ( T_1 ) ( V_14 + 1 ) ;
* V_11 =
( T_3 ) ( ( V_14 + 1 ) + F_12 ( V_13 ) ) ;
F_13 ( ( V_25 ,
L_2 ,
( unsigned int ) * V_11 ) ) ;
goto exit;
}
}
V_22 = 0 ;
}
V_15 = V_26 ;
F_8 ( ( V_17 ,
L_3 ) ) ;
exit:
( void ) F_14 ( V_19 ) ;
F_9 ( V_15 ) ;
}
void F_15 ( T_3 * V_27 )
{
T_3 V_11 = * V_27 ;
T_2 V_15 ;
T_4 V_28 ;
T_4 V_29 ;
F_16 ( V_30 , V_11 ) ;
* V_27 = 0 ;
if ( V_11 == 0 ) {
F_8 ( ( V_17 , L_4 , V_11 ) ) ;
V_31 ;
}
V_15 = F_10 ( V_19 ) ;
if ( F_11 ( V_15 ) ) {
V_31 ;
}
V_11 -- ;
V_28 = F_17 ( V_11 ) ;
V_29 = 1 << F_18 ( V_11 ) ;
if ( V_23 [ V_28 ] & V_29 ) {
V_23 [ V_28 ] ^= V_29 ;
} else {
F_8 ( ( V_17 ,
L_5 ,
V_11 + 1 ) ) ;
}
( void ) F_14 ( V_19 ) ;
V_31 ;
}
void F_19 ( char * V_32 )
{
char * string ;
F_20 () ;
if ( ! V_32 ) {
return;
}
for ( string = V_32 ; * string ; string ++ ) {
* string = ( char ) F_21 ( * string ) ;
}
return;
}
void F_22 ( char * V_32 )
{
char * string ;
F_20 () ;
if ( ! V_32 ) {
return;
}
for ( string = V_32 ; * string ; string ++ ) {
* string = ( char ) F_23 ( * string ) ;
}
return;
}
int F_24 ( char * V_33 , char * V_34 )
{
int V_35 ;
int V_36 ;
do {
V_35 = tolower ( ( int ) * V_33 ) ;
V_36 = tolower ( ( int ) * V_34 ) ;
V_33 ++ ;
V_34 ++ ;
}
while ( ( V_35 == V_36 ) && ( V_35 ) );
return ( V_35 - V_36 ) ;
}
void F_25 ( char * string , T_1 V_37 )
{
T_4 V_12 ;
if ( ! string ) {
F_26 ( L_6 ) ;
return;
}
F_26 ( L_7 ) ;
for ( V_12 = 0 ; string [ V_12 ] && ( V_12 < V_37 ) ; V_12 ++ ) {
switch ( string [ V_12 ] ) {
case 0x07 :
F_26 ( L_8 ) ;
break;
case 0x08 :
F_26 ( L_9 ) ;
break;
case 0x0C :
F_26 ( L_10 ) ;
break;
case 0x0A :
F_26 ( L_11 ) ;
break;
case 0x0D :
F_26 ( L_12 ) ;
break;
case 0x09 :
F_26 ( L_13 ) ;
break;
case 0x0B :
F_26 ( L_14 ) ;
break;
case '\'' :
case '\"' :
case '\\' :
F_26 ( L_15 , ( int ) string [ V_12 ] ) ;
break;
default:
if ( F_27 ( string [ V_12 ] ) ) {
F_26 ( L_16 , ( int ) string [ V_12 ] ) ;
} else {
F_26 ( L_17 , ( V_38 ) string [ V_12 ] ) ;
}
break;
}
}
F_26 ( L_7 ) ;
if ( V_12 == V_37 && string [ V_12 ] ) {
F_26 ( L_18 ) ;
}
}
T_4 F_28 ( T_4 V_39 )
{
union {
T_4 V_39 ;
T_1 V_40 [ 4 ] ;
} V_41 ;
union {
T_4 V_39 ;
T_1 V_40 [ 4 ] ;
} V_42 ;
F_20 () ;
V_42 . V_39 = V_39 ;
V_41 . V_40 [ 0 ] = V_42 . V_40 [ 3 ] ;
V_41 . V_40 [ 1 ] = V_42 . V_40 [ 2 ] ;
V_41 . V_40 [ 2 ] = V_42 . V_40 [ 1 ] ;
V_41 . V_40 [ 3 ] = V_42 . V_40 [ 0 ] ;
return ( V_41 . V_39 ) ;
}
void F_29 ( T_1 V_43 )
{
if ( V_43 < 2 ) {
V_44 = 32 ;
V_45 = 8 ;
V_46 = 4 ;
} else {
V_44 = 64 ;
V_45 = 16 ;
V_46 = 8 ;
}
}
void
F_30 ( T_1 type ,
struct V_47 * V_48 ,
char * V_49 )
{
T_2 V_15 ;
struct V_50 V_51 ;
F_20 () ;
if ( ! ( V_52 & V_53 ) ) {
return;
}
V_51 . V_54 = V_55 ;
V_15 = F_31 ( V_48 , & V_51 ) ;
if ( F_11 ( V_15 ) ) {
return;
}
switch ( type ) {
case V_56 :
F_26 ( L_19 ) ;
break;
default:
F_26 ( L_20 ) ;
break;
}
F_26 ( L_21 ,
F_32 ( type ) , ( char * ) V_51 . V_57 ) ;
if ( V_49 ) {
F_26 ( L_22 , V_49 ) ;
}
F_26 ( L_23 ) ;
F_33 ( V_51 . V_57 ) ;
}
T_1 F_34 ( char V_58 , T_4 V_59 )
{
if ( ! ( ( V_58 >= 'A' && V_58 <= 'Z' ) ||
( V_58 >= '0' && V_58 <= '9' ) || ( V_58 == '_' ) ) ) {
if ( V_58 == '!' && V_59 == 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
return ( TRUE ) ;
}
T_1 F_35 ( T_4 V_60 )
{
T_4 V_12 ;
F_20 () ;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 ++ ) {
if ( ! F_34
( ( F_36 ( char , & V_60 ) ) [ V_12 ] , V_12 ) ) {
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
void F_37 ( char * V_60 )
{
T_4 V_12 ;
T_1 V_62 = FALSE ;
T_4 V_63 ;
F_38 ( V_64 ) ;
F_39 ( & V_63 , V_60 ) ;
for ( V_12 = 0 ; V_12 < V_61 ; V_12 ++ ) {
if ( F_34 ( V_60 [ V_12 ] , V_12 ) ) {
continue;
}
V_60 [ V_12 ] = '*' ;
V_62 = TRUE ;
}
if ( V_62 ) {
if ( ! V_65 ) {
F_40 ( ( V_17 ,
L_24 ,
V_60 ) ) ;
} else {
F_13 ( ( V_66 ,
L_24 ,
V_60 ) ) ;
}
}
}
T_2 F_41 ( char * string , T_4 V_67 , T_5 * V_68 )
{
T_4 V_69 = 0 ;
T_5 V_70 = 0 ;
T_5 V_71 ;
T_5 V_72 ;
T_4 V_73 = ( V_67 == V_74 ) ;
T_4 V_75 = ( V_46 == 4 ) ;
T_1 V_76 = 0 ;
T_1 V_77 = 0 ;
T_1 V_78 = 0 ;
F_42 ( V_79 , string ) ;
switch ( V_67 ) {
case V_74 :
case 16 :
break;
default:
F_9 ( V_80 ) ;
}
if ( ! string ) {
goto V_81;
}
while ( ( * string ) && ( F_43 ( * string ) || * string == '\t' ) ) {
string ++ ;
}
if ( V_73 ) {
if ( ( * string == '0' ) && ( F_23 ( * ( string + 1 ) ) == 'x' ) ) {
V_77 = 1 ;
V_67 = 16 ;
string += 2 ;
} else {
V_67 = 10 ;
}
}
if ( ! ( * string ) || F_43 ( * string ) || * string == '\t' ) {
if ( V_73 ) {
goto V_81;
} else {
goto V_82;
}
}
V_72 = ( V_75 ) ? V_24 : V_83 ;
while ( * string ) {
if ( F_44 ( * string ) ) {
V_69 = ( ( T_1 ) * string ) - '0' ;
} else if ( V_67 == 10 ) {
V_78 = 1 ;
} else {
V_69 = ( T_1 ) F_21 ( * string ) ;
if ( F_45 ( ( char ) V_69 ) ) {
V_69 = V_69 - 'A' + 10 ;
} else {
V_78 = 1 ;
}
}
if ( V_78 ) {
if ( V_73 ) {
goto V_81;
} else {
break;
}
} else if ( ( V_76 == 0 ) && ( V_69 == 0 )
&& ! V_77 ) {
string ++ ;
continue;
}
V_76 ++ ;
if ( V_77
&& ( ( V_76 > 16 )
|| ( ( V_76 > 8 ) && V_75 ) ) ) {
goto V_81;
}
( void ) F_46 ( ( V_72 - ( T_5 ) V_69 ) ,
V_67 , & V_71 , NULL ) ;
if ( V_70 > V_71 ) {
if ( V_73 ) {
goto V_81;
} else {
break;
}
}
V_70 *= V_67 ;
V_70 += V_69 ;
string ++ ;
}
V_82:
F_13 ( ( V_84 , L_25 ,
F_47 ( V_70 ) ) ) ;
* V_68 = V_70 ;
F_9 ( V_85 ) ;
V_81:
if ( V_67 == 10 ) {
F_9 ( V_86 ) ;
} else {
F_9 ( V_87 ) ;
}
}
T_2
F_48 ( union V_88 * V_89 ,
T_6 V_90 ,
union V_91 * * V_92 )
{
union V_91 * V_93 ;
F_20 () ;
if ( ! V_89 ) {
return ( V_85 ) ;
}
V_93 = F_49 ( V_89 , V_90 ) ;
if ( ! V_93 ) {
return ( V_94 ) ;
}
F_50 ( V_92 , V_93 ) ;
return ( V_85 ) ;
}
T_2
F_51 ( union V_88 * V_95 ,
void * V_96 ,
T_7 V_97 , void * V_98 )
{
T_2 V_15 = V_85 ;
union V_91 * V_92 = NULL ;
union V_91 * V_93 ;
T_4 V_99 ;
union V_88 * V_100 ;
F_7 ( V_101 ) ;
V_93 = F_52 ( V_95 , V_96 , 0 ) ;
if ( ! V_93 ) {
F_9 ( V_94 ) ;
}
while ( V_93 ) {
V_99 = V_93 -> V_102 . V_28 ;
V_100 = (union V_88 * )
V_93 -> V_102 . V_95 -> V_103 . V_104 [ V_99 ] ;
if ( ( ! V_100 ) ||
( F_53 ( V_100 ) !=
V_105 )
|| ( V_100 -> V_106 . type != V_107 ) ) {
V_15 =
V_97 ( V_108 ,
V_100 , V_93 , V_98 ) ;
if ( F_11 ( V_15 ) ) {
F_9 ( V_15 ) ;
}
V_93 -> V_102 . V_28 ++ ;
while ( V_93 -> V_102 . V_28 >=
V_93 -> V_102 . V_95 -> V_103 . V_109 ) {
F_54 ( V_93 ) ;
V_93 = F_55 ( & V_92 ) ;
if ( ! V_93 ) {
F_9 ( V_85 ) ;
}
V_93 -> V_102 . V_28 ++ ;
}
} else {
V_15 =
V_97 ( V_110 ,
V_100 , V_93 , V_98 ) ;
if ( F_11 ( V_15 ) ) {
F_9 ( V_15 ) ;
}
F_50 ( & V_92 , V_93 ) ;
V_93 = F_52 ( V_100 ,
V_93 -> V_102 .
V_111 , 0 ) ;
if ( ! V_93 ) {
while ( V_92 ) {
V_93 =
F_55
( & V_92 ) ;
F_54 ( V_93 ) ;
}
F_9 ( V_94 ) ;
}
}
}
F_9 ( V_112 ) ;
}
