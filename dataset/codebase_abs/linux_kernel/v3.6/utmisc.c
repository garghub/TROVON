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
void F_22 ( char * string , T_1 V_33 )
{
T_4 V_12 ;
if ( ! string ) {
F_23 ( L_6 ) ;
return;
}
F_23 ( L_7 ) ;
for ( V_12 = 0 ; string [ V_12 ] && ( V_12 < V_33 ) ; V_12 ++ ) {
switch ( string [ V_12 ] ) {
case 0x07 :
F_23 ( L_8 ) ;
break;
case 0x08 :
F_23 ( L_9 ) ;
break;
case 0x0C :
F_23 ( L_10 ) ;
break;
case 0x0A :
F_23 ( L_11 ) ;
break;
case 0x0D :
F_23 ( L_12 ) ;
break;
case 0x09 :
F_23 ( L_13 ) ;
break;
case 0x0B :
F_23 ( L_14 ) ;
break;
case '\'' :
case '\"' :
case '\\' :
F_23 ( L_15 , ( int ) string [ V_12 ] ) ;
break;
default:
if ( F_24 ( string [ V_12 ] ) ) {
F_23 ( L_16 , ( int ) string [ V_12 ] ) ;
} else {
F_23 ( L_17 , ( V_34 ) string [ V_12 ] ) ;
}
break;
}
}
F_23 ( L_7 ) ;
if ( V_12 == V_33 && string [ V_12 ] ) {
F_23 ( L_18 ) ;
}
}
T_4 F_25 ( T_4 V_35 )
{
union {
T_4 V_35 ;
T_1 V_36 [ 4 ] ;
} V_37 ;
union {
T_4 V_35 ;
T_1 V_36 [ 4 ] ;
} V_38 ;
F_20 () ;
V_38 . V_35 = V_35 ;
V_37 . V_36 [ 0 ] = V_38 . V_36 [ 3 ] ;
V_37 . V_36 [ 1 ] = V_38 . V_36 [ 2 ] ;
V_37 . V_36 [ 2 ] = V_38 . V_36 [ 1 ] ;
V_37 . V_36 [ 3 ] = V_38 . V_36 [ 0 ] ;
return ( V_37 . V_35 ) ;
}
void F_26 ( T_1 V_39 )
{
if ( V_39 < 2 ) {
V_40 = 32 ;
V_41 = 8 ;
V_42 = 4 ;
} else {
V_40 = 64 ;
V_41 = 16 ;
V_42 = 8 ;
}
}
void
F_27 ( T_1 type ,
struct V_43 * V_44 ,
char * V_45 )
{
T_2 V_15 ;
struct V_46 V_47 ;
F_20 () ;
if ( ! ( V_48 & V_49 ) ) {
return;
}
V_47 . V_50 = V_51 ;
V_15 = F_28 ( V_44 , & V_47 ) ;
if ( F_11 ( V_15 ) ) {
return;
}
switch ( type ) {
case V_52 :
F_23 ( L_19 ) ;
break;
default:
F_23 ( L_20 ) ;
break;
}
F_23 ( L_21 ,
F_29 ( type ) , ( char * ) V_47 . V_53 ) ;
if ( V_45 ) {
F_23 ( L_22 , V_45 ) ;
}
F_23 ( L_23 ) ;
F_30 ( V_47 . V_53 ) ;
}
T_1 F_31 ( char V_54 , T_4 V_55 )
{
if ( ! ( ( V_54 >= 'A' && V_54 <= 'Z' ) ||
( V_54 >= '0' && V_54 <= '9' ) || ( V_54 == '_' ) ) ) {
if ( V_54 == '!' && V_55 == 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
return ( TRUE ) ;
}
T_1 F_32 ( T_4 V_56 )
{
T_4 V_12 ;
F_20 () ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
if ( ! F_31
( ( F_33 ( char , & V_56 ) ) [ V_12 ] , V_12 ) ) {
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
T_5 F_34 ( char * V_56 )
{
T_4 V_12 ;
char V_58 [ V_57 ] ;
for ( V_12 = 0 ; V_12 < V_57 ; V_12 ++ ) {
V_58 [ V_12 ] = V_56 [ V_12 ] ;
if ( ! F_31 ( V_56 [ V_12 ] , V_12 ) ) {
V_58 [ V_12 ] = '*' ;
}
}
return ( * ( T_4 * ) V_58 ) ;
}
T_2 F_35 ( char * string , T_4 V_59 , T_6 * V_60 )
{
T_4 V_61 = 0 ;
T_6 V_62 = 0 ;
T_6 V_63 ;
T_6 V_64 ;
T_4 V_65 = ( V_59 == V_66 ) ;
T_4 V_67 = ( V_42 == 4 ) ;
T_1 V_68 = 0 ;
T_1 V_69 = 0 ;
T_1 V_70 = 0 ;
F_36 ( V_71 , string ) ;
switch ( V_59 ) {
case V_66 :
case 16 :
break;
default:
F_9 ( V_72 ) ;
}
if ( ! string ) {
goto V_73;
}
while ( ( * string ) && ( F_37 ( * string ) || * string == '\t' ) ) {
string ++ ;
}
if ( V_65 ) {
if ( ( * string == '0' ) && ( F_38 ( * ( string + 1 ) ) == 'x' ) ) {
V_69 = 1 ;
V_59 = 16 ;
string += 2 ;
} else {
V_59 = 10 ;
}
}
if ( ! ( * string ) || F_37 ( * string ) || * string == '\t' ) {
if ( V_65 ) {
goto V_73;
} else {
goto V_74;
}
}
V_64 = ( V_67 ) ? V_24 : V_75 ;
while ( * string ) {
if ( F_39 ( * string ) ) {
V_61 = ( ( T_1 ) * string ) - '0' ;
} else if ( V_59 == 10 ) {
V_70 = 1 ;
} else {
V_61 = ( T_1 ) F_21 ( * string ) ;
if ( F_40 ( ( char ) V_61 ) ) {
V_61 = V_61 - 'A' + 10 ;
} else {
V_70 = 1 ;
}
}
if ( V_70 ) {
if ( V_65 ) {
goto V_73;
} else {
break;
}
} else if ( ( V_68 == 0 ) && ( V_61 == 0 )
&& ! V_69 ) {
string ++ ;
continue;
}
V_68 ++ ;
if ( V_69 && ( ( V_68 > 16 )
|| ( ( V_68 > 8 ) && V_67 ) ) ) {
goto V_73;
}
( void ) F_41 ( ( V_64 - ( T_6 ) V_61 ) ,
V_59 , & V_63 , NULL ) ;
if ( V_62 > V_63 ) {
if ( V_65 ) {
goto V_73;
} else {
break;
}
}
V_62 *= V_59 ;
V_62 += V_61 ;
string ++ ;
}
V_74:
F_13 ( ( V_76 , L_24 ,
F_42 ( V_62 ) ) ) ;
* V_60 = V_62 ;
F_9 ( V_77 ) ;
V_73:
if ( V_59 == 10 ) {
F_9 ( V_78 ) ;
} else {
F_9 ( V_79 ) ;
}
}
T_2
F_43 ( union V_80 * V_81 ,
T_7 V_82 ,
union V_83 * * V_84 )
{
union V_83 * V_85 ;
F_20 () ;
if ( ! V_81 ) {
return ( V_77 ) ;
}
V_85 = F_44 ( V_81 , V_82 ) ;
if ( ! V_85 ) {
return ( V_86 ) ;
}
F_45 ( V_84 , V_85 ) ;
return ( V_77 ) ;
}
T_2
F_46 ( union V_80 * V_87 ,
void * V_88 ,
T_8 V_89 , void * V_90 )
{
T_2 V_15 = V_77 ;
union V_83 * V_84 = NULL ;
union V_83 * V_85 ;
T_4 V_91 ;
union V_80 * V_92 ;
F_7 ( V_93 ) ;
V_85 = F_47 ( V_87 , V_88 , 0 ) ;
if ( ! V_85 ) {
F_9 ( V_86 ) ;
}
while ( V_85 ) {
V_91 = V_85 -> V_94 . V_28 ;
V_92 = (union V_80 * )
V_85 -> V_94 . V_87 -> V_95 . V_96 [ V_91 ] ;
if ( ( ! V_92 ) ||
( F_48 ( V_92 ) !=
V_97 )
|| ( V_92 -> V_98 . type != V_99 ) ) {
V_15 =
V_89 ( V_100 ,
V_92 , V_85 , V_90 ) ;
if ( F_11 ( V_15 ) ) {
F_9 ( V_15 ) ;
}
V_85 -> V_94 . V_28 ++ ;
while ( V_85 -> V_94 . V_28 >=
V_85 -> V_94 . V_87 -> V_95 . V_101 ) {
F_49 ( V_85 ) ;
V_85 = F_50 ( & V_84 ) ;
if ( ! V_85 ) {
F_9 ( V_77 ) ;
}
V_85 -> V_94 . V_28 ++ ;
}
} else {
V_15 =
V_89 ( V_102 ,
V_92 , V_85 , V_90 ) ;
if ( F_11 ( V_15 ) ) {
F_9 ( V_15 ) ;
}
F_45 ( & V_84 , V_85 ) ;
V_85 = F_47 ( V_92 ,
V_85 -> V_94 .
V_103 , 0 ) ;
if ( ! V_85 ) {
while ( V_84 ) {
V_85 =
F_50
( & V_84 ) ;
F_49 ( V_85 ) ;
}
F_9 ( V_86 ) ;
}
}
}
F_9 ( V_104 ) ;
}
