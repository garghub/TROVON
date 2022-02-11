static T_1
F_1 ( char * V_1 ,
const struct V_2 * V_3 )
{
char * V_4 = V_3 -> V_4 ;
T_2 V_5 ;
if ( * V_4 != ' ' ) {
return ( FALSE ) ;
}
while ( * V_4 == ' ' ) {
V_4 ++ ;
}
while ( ( * V_1 ) && ( * V_4 ) && ( * V_4 != ' ' ) ) {
if ( tolower ( ( int ) * V_1 ) != tolower ( ( int ) * V_4 ) ) {
return ( FALSE ) ;
}
V_4 ++ ;
V_1 ++ ;
}
V_5 = V_3 -> V_5 ;
while ( V_5 ) {
F_2 ( L_1 , V_3 -> V_4 ,
V_3 -> V_6 ) ;
V_3 ++ ;
V_5 -- ;
}
return ( TRUE ) ;
}
static void F_3 ( char * V_1 , T_1 V_7 )
{
const struct V_2 * V_8 ;
T_1 V_9 ;
V_8 = V_10 ;
while ( V_8 -> V_4 ) {
V_9 = F_1 ( V_1 , V_8 ) ;
if ( ! V_7 && V_9 ) {
return;
}
V_8 ++ ;
}
}
static void F_4 ( char * V_1 )
{
const struct V_2 * V_8 = V_10 ;
if ( ! V_1 ) {
while ( V_8 -> V_4 ) {
F_2 ( L_2 , V_8 -> V_4 ,
V_8 -> V_6 ) ;
V_8 ++ ;
}
} else {
F_3 ( V_1 , TRUE ) ;
}
}
char * F_5 ( char * string ,
char * * V_8 , T_3 * V_11 )
{
char * V_12 ;
T_2 V_13 ;
T_3 type = V_14 ;
if ( ! string || ! ( * string ) ) {
return ( NULL ) ;
}
if ( * string == ' ' ) {
while ( * string && ( * string == ' ' ) ) {
string ++ ;
}
if ( ! ( * string ) ) {
return ( NULL ) ;
}
}
switch ( * string ) {
case '"' :
string ++ ;
V_12 = string ;
type = V_15 ;
while ( * string && ( * string != '"' ) ) {
string ++ ;
}
break;
case '(' :
string ++ ;
V_12 = string ;
type = V_16 ;
while ( * string && ( * string != ')' ) ) {
string ++ ;
}
break;
case '[' :
string ++ ;
V_13 = 1 ;
V_12 = string ;
type = V_17 ;
while ( * string ) {
if ( * string == '"' ) {
string ++ ;
while ( * string && ( * string != '"' ) ) {
string ++ ;
}
if ( ! ( * string ) ) {
break;
}
} else if ( * string == '[' ) {
V_13 ++ ;
} else if ( * string == ']' ) {
V_13 -- ;
if ( V_13 == 0 ) {
break;
}
}
string ++ ;
}
break;
default:
V_12 = string ;
while ( * string && ( * string != ' ' ) ) {
string ++ ;
}
break;
}
if ( ! ( * string ) ) {
* V_8 = NULL ;
} else {
* string = 0 ;
* V_8 = string + 1 ;
}
* V_11 = type ;
return ( V_12 ) ;
}
static T_2 F_6 ( char * V_18 )
{
T_2 V_19 ;
T_2 V_20 ;
char * V_8 ;
char * V_21 ;
if ( F_7
( V_22 , sizeof( V_22 ) ,
V_18 ) ) {
F_2
( L_3 ,
sizeof( V_22 ) ) ;
return ( 0 ) ;
}
V_21 = V_22 ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
V_24 [ V_19 ] = F_5 ( V_21 , & V_8 ,
& V_25
[ V_19 ] ) ;
if ( ! V_24 [ V_19 ] ) {
break;
}
V_21 = V_8 ;
}
if ( V_24 [ 0 ] ) {
F_8 ( V_24 [ 0 ] ) ;
}
V_20 = V_19 ;
if ( V_20 ) {
V_20 -- ;
}
return ( V_20 ) ;
}
static T_2 F_9 ( char * V_26 )
{
T_2 V_19 ;
if ( ! V_26 || V_26 [ 0 ] == 0 ) {
return ( V_27 ) ;
}
for ( V_19 = V_28 ; V_29 [ V_19 ] . V_30 ; V_19 ++ ) {
if ( strstr ( V_29 [ V_19 ] . V_30 , V_26 ) ==
V_29 [ V_19 ] . V_30 ) {
return ( V_19 ) ;
}
}
return ( V_31 ) ;
}
T_4
F_10 ( char * V_18 ,
struct V_32 * V_33 ,
union V_34 * V_35 )
{
T_2 V_36 ;
T_2 V_37 ;
T_2 V_38 ;
char * V_39 ;
T_4 V_40 = V_41 ;
if ( V_42 ) {
return ( V_43 ) ;
}
V_38 = F_6 ( V_18 ) ;
V_37 = F_9 ( V_24 [ 0 ] ) ;
V_36 = 0 ;
if ( V_37 != V_44 ) {
F_11 ( V_18 ) ;
}
if ( V_38 < V_29 [ V_37 ] . V_45 ) {
F_2
( L_4 ,
V_38 , V_29 [ V_37 ] . V_30 ,
V_29 [ V_37 ] . V_45 ) ;
F_3 ( V_29
[ V_37 ] . V_30 , FALSE ) ;
return ( V_41 ) ;
}
switch ( V_37 ) {
case V_27 :
if ( V_35 ) {
return ( V_46 ) ;
}
break;
case V_47 :
#ifdef F_12
F_13 ( ( T_2 ) - 1 , NULL ) ;
#endif
break;
case V_48 :
case V_49 :
F_14 () ;
break;
case V_50 :
F_15 ( V_24 [ 1 ] , V_33 ,
V_35 ) ;
break;
case V_51 :
F_16 () ;
break;
case V_52 :
F_17 ( V_35 ) ;
V_40 = V_46 ;
break;
case V_53 :
F_18 ( V_24 [ 1 ] ,
& V_24 [ 2 ] , & V_25 [ 2 ] ,
V_54 ) ;
break;
case V_55 :
case V_56 :
( void ) F_19 ( V_24 [ 1 ] ) ;
break;
case V_57 :
F_20 ( V_24 [ 1 ] ,
V_24 [ 2 ] ) ;
break;
case V_58 :
case V_59 :
F_18 ( V_24 [ 1 ] ,
& V_24 [ 2 ] , & V_25 [ 2 ] ,
V_60 ) ;
break;
case V_61 :
V_40 = F_21 ( V_24 [ 1 ] ) ;
break;
case V_62 :
V_63 = FALSE ;
return ( V_46 ) ;
case V_64 :
F_22 () ;
break;
case V_65 :
case V_66 :
F_4 ( V_24 [ 1 ] ) ;
break;
case V_67 :
F_23 () ;
break;
case V_68 :
V_39 = F_24 ( V_24 [ 1 ] ) ;
if ( ! V_39 ) {
return ( V_41 ) ;
}
V_40 = F_10 ( V_39 , V_33 , V_35 ) ;
return ( V_40 ) ;
case V_44 :
V_39 = F_24 ( NULL ) ;
if ( ! V_39 ) {
return ( V_41 ) ;
}
V_40 = F_10 ( V_39 , V_33 , V_35 ) ;
return ( V_40 ) ;
case V_69 :
F_25 ( V_35 ) ;
break;
case V_70 :
F_26 () ;
break;
case V_71 :
if ( V_35 ) {
V_63 = TRUE ;
return ( V_46 ) ;
}
break;
case V_72 :
if ( V_38 == 0 ) {
F_2
( L_5 ,
V_73 ) ;
F_2
( L_6 ,
V_74 ) ;
} else if ( V_38 == 2 ) {
V_36 = V_74 ;
V_74 =
strtoul ( V_24 [ 1 ] , NULL , 16 ) ;
F_2
( L_7 ,
V_36 , V_74 ) ;
} else {
V_36 = V_73 ;
V_73 =
strtoul ( V_24 [ 1 ] , NULL , 16 ) ;
F_2
( L_8 ,
V_36 , V_73 ) ;
}
break;
case V_75 :
F_27 ( V_24 [ 1 ] , V_35 ) ;
break;
case V_76 :
F_28 () ;
break;
case V_77 :
F_29 () ;
break;
case V_78 :
V_40 = F_30 ( L_9 , V_24 [ 1 ] ) ;
break;
case V_79 :
F_31 ( V_24 [ 1 ] ,
V_24 [ 2 ] ) ;
break;
case V_80 :
V_36 = strtoul ( V_24 [ 2 ] , NULL , 0 ) ;
F_32 ( V_24 [ 1 ] , V_36 ) ;
break;
case V_81 :
F_8 ( V_24 [ 1 ] ) ;
V_40 =
F_30 ( V_24 [ 1 ] ,
V_24 [ 2 ] ) ;
break;
case V_82 :
F_33 ( V_24 [ 1 ] ,
V_24 [ 2 ] ) ;
break;
case V_83 :
F_34 ( V_24 [ 1 ] ,
V_24 [ 2 ] ) ;
break;
case V_84 :
F_35 () ;
break;
case V_85 :
F_36 ( V_24 [ 1 ] ) ;
break;
case V_86 :
F_37 ( V_24 [ 1 ] ) ;
break;
case V_87 :
F_38 ( V_24 [ 1 ] ) ;
break;
case V_88 :
F_39 () ;
break;
case V_89 :
F_40 ( V_24 [ 1 ] ,
V_24 [ 2 ] ,
V_24 [ 3 ] ) ;
break;
case V_90 :
V_40 = F_41 ( V_24 [ 1 ] ) ;
break;
case V_91 :
return ( V_92 ) ;
case V_93 :
F_42 ( V_24 [ 1 ] ) ;
break;
case V_94 :
F_43 ( V_24 [ 1 ] ) ;
break;
case V_95 :
F_44 ( V_24 [ 1 ] , V_24 [ 2 ] ,
V_24 [ 3 ] ) ;
break;
case V_96 :
F_45 () ;
break;
case V_97 :
F_46 ( V_24 [ 1 ] ) ;
break;
#ifdef F_47
case V_98 :
#if ( ! V_99 )
V_40 = F_48 () ;
if ( F_49 ( V_40 ) ) {
F_2 ( L_10 ,
V_40 ) ;
return ( V_40 ) ;
}
#endif
break;
case V_100 :
F_2 ( L_11 ) ;
break;
case V_101 :
F_50 ( V_24 [ 1 ] , V_24 [ 2 ] ) ;
break;
case V_102 :
F_51 () ;
break;
case V_103 :
F_52 () ;
break;
case V_104 :
V_40 = F_53 ( V_24 [ 1 ] ) ;
break;
case V_105 :
F_54 () ;
break;
case V_106 :
V_40 =
F_55 ( V_24 [ 1 ] , NULL ,
FALSE ) ;
break;
case V_107 :
F_56 ( V_24 [ 1 ] ) ;
break;
case V_108 :
F_57 ( V_109 ) ;
F_58 () ;
V_42 = TRUE ;
break;
case V_110 :
F_59 ( V_24 [ 1 ] ,
V_24 [ 2 ] ,
V_24 [ 3 ] ) ;
break;
case V_111 :
F_60 () ;
break;
case V_112 :
F_61 ( V_24 [ 1 ] ) ;
break;
case V_113 :
F_62 ( V_24 [ 1 ] ) ;
break;
#endif
case V_114 :
case V_115 :
if ( V_35 ) {
F_2 ( L_12 ) ;
return ( V_43 ) ;
}
if ( ! V_116 ) {
V_117 = V_118 ;
}
#ifdef F_47
F_54 () ;
#endif
V_42 = TRUE ;
return ( V_43 ) ;
case V_31 :
default:
F_2 ( L_13 , V_24 [ 0 ] ) ;
return ( V_41 ) ;
}
if ( F_63 ( V_40 ) ) {
V_40 = V_41 ;
}
return ( V_40 ) ;
}
void T_5 F_64 ( void * V_119 )
{
T_4 V_40 = V_46 ;
T_4 V_120 ;
while ( V_40 != V_43 && ! V_42 ) {
V_121 = FALSE ;
V_122 = FALSE ;
V_120 = F_65 ( V_123 ,
V_124 ) ;
if ( F_49 ( V_120 ) ) {
return;
}
V_40 =
F_10 ( V_125 , NULL , NULL ) ;
F_66 ( V_126 ) ;
}
V_127 = TRUE ;
}
static void F_67 ( void )
{
V_121 = FALSE ;
V_122 = FALSE ;
( void ) F_10 ( V_125 , NULL , NULL ) ;
}
T_4 F_68 ( char V_128 , union V_34 * V_35 )
{
T_4 V_40 = V_46 ;
F_2 ( L_14 ) ;
while ( ! V_42 ) {
F_57 ( V_129 ) ;
if ( ! V_121 ) {
F_2 ( L_15 , V_130 ) ;
} else {
F_2 ( L_15 , V_131 ) ;
}
V_40 = F_69 ( V_125 ,
V_132 , NULL ) ;
if ( F_49 ( V_40 ) ) {
F_70 ( ( V_133 , V_40 ,
L_16 ) ) ;
return ( V_40 ) ;
}
if ( V_134 & V_135 ) {
F_66 ( V_123 ) ;
if ( F_49 ( V_40 ) ) {
return ( V_40 ) ;
}
V_40 =
F_65 ( V_126 ,
V_124 ) ;
if ( F_49 ( V_40 ) ) {
return ( V_40 ) ;
}
} else {
F_67 () ;
}
}
return ( V_40 ) ;
}
