static void F_1 ( void )
{
F_2 ( V_1 , - 1 , - 1 ) ;
F_2 ( V_2 , V_3 , - 1 ) ;
F_2 ( V_4 , - 1 , - 1 ) ;
F_2 ( V_5 , - 1 , - 1 ) ;
F_2 ( V_6 , - 1 , - 1 ) ;
F_2 ( V_7 , V_8 , - 1 ) ;
F_2 ( V_9 , V_10 , - 1 ) ;
F_2 ( V_11 , - 1 , - 1 ) ;
F_2 ( V_12 , V_8 , - 1 ) ;
F_2 ( V_13 , V_10 , - 1 ) ;
F_2 ( V_14 , - 1 , - 1 ) ;
F_2 ( V_15 , V_10 , - 1 ) ;
F_2 ( V_16 , V_10 , - 1 ) ;
F_2 ( V_17 , V_18 , - 1 ) ;
F_2 ( V_19 , V_10 , - 1 ) ;
F_2 ( V_20 , V_8 , - 1 ) ;
F_2 ( V_21 , - 1 , - 1 ) ;
F_2 ( V_22 , - 1 , - 1 ) ;
F_2 ( V_23 , - 1 , - 1 ) ;
F_2 ( V_24 , V_10 , - 1 ) ;
}
static void F_3 ( void )
{
#define F_4 ( T_1 , T_2 ) do { \
attributes[name] = attr | COLOR_PAIR(name); } while (0)
F_4 ( V_1 , V_1 ) ;
F_4 ( V_2 , V_25 | V_26 ) ;
F_4 ( V_4 , V_27 ) ;
F_4 ( V_5 , V_28 ) ;
F_4 ( V_6 , V_28 ) ;
F_4 ( V_7 , V_25 ) ;
F_4 ( V_9 , V_28 ) ;
F_4 ( V_11 , V_28 ) ;
F_4 ( V_12 , V_25 ) ;
F_4 ( V_13 , V_25 ) ;
F_4 ( V_14 , V_25 ) ;
F_4 ( V_15 , V_25 ) ;
F_4 ( V_17 , V_29 ) ;
F_4 ( V_16 , V_28 ) ;
F_4 ( V_19 , V_28 ) ;
F_4 ( V_20 , V_25 ) ;
F_4 ( V_21 , V_28 ) ;
F_4 ( V_22 , V_26 ) ;
F_4 ( V_23 , V_25 ) ;
F_4 ( V_24 , V_27 ) ;
}
static void F_5 ( void )
{
#define F_6 ( T_1 , T_2 ) { attributes[name] = attr; }
F_6 ( V_1 , V_1 ) ;
F_6 ( V_2 , V_25 | V_26 ) ;
F_6 ( V_4 , V_29 ) ;
F_6 ( V_5 , V_28 ) ;
F_6 ( V_6 , V_28 ) ;
F_6 ( V_7 , V_25 ) ;
F_6 ( V_9 , V_28 ) ;
F_6 ( V_11 , V_28 ) ;
F_6 ( V_12 , V_25 ) ;
F_6 ( V_13 , V_25 ) ;
F_6 ( V_14 , V_28 ) ;
F_6 ( V_15 , V_25 ) ;
F_6 ( V_17 , V_29 ) ;
F_6 ( V_16 , V_28 ) ;
F_6 ( V_19 , V_25 ) ;
F_6 ( V_20 , V_25 ) ;
F_6 ( V_21 , V_28 ) ;
F_6 ( V_22 , V_26 ) ;
F_6 ( V_23 , V_25 ) ;
F_6 ( V_24 , V_27 ) ;
}
void F_7 ()
{
F_8 () ;
F_9 () ;
F_1 () ;
if ( F_10 () ) {
F_3 () ;
} else {
F_5 () ;
}
}
void F_11 ( T_3 * V_30 ,
int V_31 ,
int V_32 ,
int V_33 ,
const char * string ,
T_4 V_34 )
{ int V_35 , V_36 , V_37 ;
float V_38 ;
if ( V_30 == NULL )
V_30 = V_39 ;
F_12 ( V_30 , V_37 , V_36 ) ;
if ( V_32 != 0 )
V_36 = V_32 ;
if ( V_31 != 0 )
V_37 = V_31 ;
if ( V_33 == 0 )
V_33 = 80 ;
V_35 = strlen ( string ) ;
V_38 = ( V_33 - V_35 ) / 2 ;
V_36 = V_32 + ( int ) V_38 ;
( void ) F_13 ( V_30 , V_34 ) ;
F_14 ( V_30 , V_37 , V_36 , L_1 , string ) ;
F_15 () ;
}
int F_16 ( const char * V_40 )
{
int V_41 ;
int V_42 = 1 ;
if ( ! V_40 )
return 0 ;
for ( V_41 = 0 ; V_40 [ V_41 ] != '\0' ; V_41 ++ )
if ( V_40 [ V_41 ] == '\n' )
V_42 ++ ;
return V_42 ;
}
const char * F_17 ( const char * V_40 , int V_43 )
{
int V_41 ;
int V_44 = 0 ;
if ( ! V_40 )
return 0 ;
for ( V_41 = 0 ; V_40 [ V_41 ] != '\0' && V_44 < V_43 ; V_41 ++ )
if ( V_40 [ V_41 ] == '\n' )
V_44 ++ ;
return V_40 + V_41 ;
}
int F_18 ( const char * line )
{
int V_45 = 0 ;
while ( * line != '\0' && * line != '\n' ) {
line ++ ;
V_45 ++ ;
}
return V_45 ;
}
void F_19 ( T_3 * V_30 , const char * V_40 )
{
int V_36 , V_37 ;
int V_46 = F_16 ( V_40 ) ;
int V_41 ;
F_20 ( V_30 , V_37 , V_36 ) ;
V_46 = F_21 ( V_46 , V_37 ) ;
for ( V_41 = 0 ; V_41 < V_46 ; V_41 ++ ) {
char V_47 [ V_36 + 10 ] ;
const char * line = F_17 ( V_40 , V_41 ) ;
int V_48 = F_18 ( line ) ;
strncpy ( V_47 , line , F_21 ( V_48 , V_36 ) ) ;
V_47 [ V_48 ] = '\0' ;
F_14 ( V_30 , V_41 , 0 , L_1 , V_47 ) ;
}
}
int F_22 ( T_3 * V_49 , const char * V_50 , int V_51 , ... )
{
T_5 V_52 ;
char * V_53 ;
int V_54 = 0 ;
int V_55 = 0 ;
int V_56 = 0 ;
int V_57 ;
int V_58 = 0 ;
T_3 * V_30 ;
T_3 * V_59 ;
T_3 * V_60 ;
T_6 * V_61 ;
T_7 * V_62 [ V_51 + 1 ] ;
int V_41 , V_36 , V_37 ;
int V_45 = - 1 ;
va_start ( V_52 , V_51 ) ;
for ( V_41 = 0 ; V_41 < V_51 ; V_41 ++ ) {
V_53 = va_arg ( V_52 , char * ) ;
V_62 [ V_41 ] = F_23 ( V_53 , L_2 ) ;
V_54 += strlen ( V_53 ) + 1 ;
}
va_end ( V_52 ) ;
V_62 [ V_51 ] = NULL ;
V_55 = F_16 ( V_50 ) ;
for ( V_41 = 0 ; V_41 < V_55 ; V_41 ++ ) {
const char * line = F_17 ( V_50 , V_41 ) ;
int V_48 = F_18 ( line ) ;
if ( V_56 < V_48 )
V_56 = V_48 ;
}
V_57 = F_24 ( V_56 , V_54 ) ;
V_37 = ( V_63 - ( V_55 + 4 ) ) / 2 ;
V_36 = ( V_64 - ( V_57 + 4 ) ) / 2 ;
if ( V_51 > 0 )
V_58 = V_55 + 4 ;
else
V_58 = V_55 + 2 ;
V_30 = F_25 ( V_58 , V_57 + 4 , V_37 , V_36 ) ;
F_26 ( V_30 , TRUE ) ;
V_60 = F_27 ( V_30 , 1 , V_54 , V_58 - 2 ,
1 + ( V_57 + 2 - V_54 ) / 2 ) ;
V_61 = F_28 ( V_62 ) ;
V_59 = F_27 ( V_30 , V_58 - 2 , V_56 , 1 ,
1 + ( V_57 + 2 - V_56 ) / 2 ) ;
F_29 ( V_61 , V_65 [ V_17 ] ) ;
F_30 ( V_61 , V_65 [ V_16 ] ) ;
( void ) F_13 ( V_30 , V_65 [ V_15 ] ) ;
F_31 ( V_30 , 0 , 0 ) ;
( void ) F_13 ( V_59 , V_65 [ V_14 ] ) ;
F_19 ( V_59 , V_50 ) ;
F_32 ( V_61 , V_30 ) ;
F_33 ( V_61 , V_60 ) ;
F_34 ( V_61 , 1 , V_51 ) ;
F_35 ( V_61 , V_66 ) ;
F_35 ( V_61 , V_67 ) ;
F_36 ( V_61 , V_68 ) ;
F_36 ( V_61 , V_69 ) ;
F_37 ( V_61 , L_2 ) ;
F_38 ( V_61 ) ;
F_39 ( V_30 ) ;
F_40 ( V_49 ) ;
while ( ( V_45 = F_41 ( V_30 ) ) ) {
switch ( V_45 ) {
case V_70 :
F_42 ( V_61 , V_71 ) ;
break;
case V_72 :
F_42 ( V_61 , V_73 ) ;
break;
case 10 :
case 27 :
case ' ' :
case F_43 ( V_74 ) :
case F_43 ( V_75 ) :
break;
}
F_39 ( V_30 ) ;
F_40 ( V_49 ) ;
if ( V_45 == 10 || V_45 == ' ' ) {
V_45 = F_44 ( F_45 ( V_61 ) ) ;
break;
} else if ( V_45 == 27 || V_45 == F_43 ( V_74 ) ||
V_45 == F_43 ( V_75 ) ) {
V_45 = V_76 ;
break;
}
}
F_46 ( V_61 ) ;
F_47 ( V_61 ) ;
for ( V_41 = 0 ; V_41 < V_51 ; V_41 ++ )
F_48 ( V_62 [ V_41 ] ) ;
F_49 ( V_30 ) ;
return V_45 ;
}
int F_50 ( T_3 * V_49 ,
const char * V_77 , const char * V_78 ,
const char * V_79 , char * * V_80 , int * V_81 )
{
int V_82 = 0 ;
int V_83 = 0 ;
T_3 * V_30 ;
T_3 * V_84 ;
T_3 * V_85 ;
T_8 * V_86 ;
int V_41 , V_36 , V_37 ;
int V_45 = - 1 ;
int V_87 = strlen ( V_79 ) ;
int V_88 ;
char * V_89 = * V_80 ;
if ( strlen ( V_79 ) + 1 > * V_81 ) {
* V_81 = strlen ( V_79 ) + 1 ;
* V_80 = V_89 = realloc ( V_89 , * V_81 ) ;
}
V_82 = F_16 ( V_78 ) ;
for ( V_41 = 0 ; V_41 < V_82 ; V_41 ++ ) {
const char * line = F_17 ( V_78 , V_41 ) ;
int V_48 = F_18 ( line ) ;
V_83 = F_24 ( V_83 , V_48 ) ;
}
if ( V_77 )
V_83 = F_24 ( V_83 , strlen ( V_77 ) ) ;
V_37 = ( V_63 - ( V_82 + 4 ) ) / 2 ;
V_36 = ( V_64 - ( V_83 + 4 ) ) / 2 ;
strncpy ( V_89 , V_79 , * V_81 ) ;
V_30 = F_25 ( V_82 + 6 , V_83 + 7 , V_37 , V_36 ) ;
V_84 = F_27 ( V_30 , V_82 + 1 , V_83 , 2 , 2 ) ;
V_85 = F_27 ( V_30 , 1 , V_83 , V_82 + 3 , 2 ) ;
F_26 ( V_85 , TRUE ) ;
( void ) F_13 ( V_85 , V_65 [ V_22 ] ) ;
( void ) F_13 ( V_30 , V_65 [ V_19 ] ) ;
F_31 ( V_30 , 0 , 0 ) ;
( void ) F_13 ( V_30 , V_65 [ V_20 ] ) ;
if ( V_77 )
F_14 ( V_30 , 0 , 3 , L_1 , V_77 ) ;
( void ) F_13 ( V_84 , V_65 [ V_21 ] ) ;
F_19 ( V_84 , V_78 ) ;
F_14 ( V_85 , 0 , 0 , L_3 , V_83 , L_4 ) ;
V_88 = F_21 ( V_87 , V_83 - 1 ) ;
F_14 ( V_85 , 0 , 0 , L_1 ,
V_89 + V_87 - V_88 ) ;
V_86 = F_51 ( V_30 ) ;
F_52 ( 1 ) ;
F_39 ( V_30 ) ;
F_40 ( V_49 ) ;
while ( ( V_45 = F_41 ( V_85 ) ) ) {
int V_48 = strlen ( V_89 ) ;
switch ( V_45 ) {
case 10 :
case 27 :
case F_43 ( V_90 ) :
case F_43 ( V_75 ) :
case F_43 ( V_74 ) :
break;
case 127 :
case V_91 :
if ( V_87 > 0 ) {
memmove ( & V_89 [ V_87 - 1 ] ,
& V_89 [ V_87 ] ,
V_48 - V_87 + 1 ) ;
V_87 -- ;
V_88 -- ;
V_48 -- ;
}
break;
case V_92 :
if ( V_87 >= 0 && V_87 < V_48 ) {
memmove ( & V_89 [ V_87 ] ,
& V_89 [ V_87 + 1 ] ,
V_48 - V_87 + 1 ) ;
V_48 -- ;
}
break;
case V_93 :
case V_72 :
if ( V_87 < V_48 ) {
V_87 ++ ;
V_88 ++ ;
}
break;
case V_94 :
case V_70 :
if ( V_87 > 0 ) {
V_87 -- ;
V_88 -- ;
}
break;
case V_95 :
V_87 = 0 ;
V_88 = 0 ;
break;
case V_96 :
V_87 = V_48 ;
V_88 = F_21 ( V_87 , V_83 - 1 ) ;
break;
default:
if ( ( isgraph ( V_45 ) || isspace ( V_45 ) ) ) {
if ( V_48 + 2 > * V_81 ) {
* V_81 = V_48 + 2 ;
* V_80 = V_89 = realloc ( V_89 ,
* V_81 ) ;
}
memmove ( & V_89 [ V_87 + 1 ] ,
& V_89 [ V_87 ] ,
V_48 - V_87 + 1 ) ;
V_89 [ V_87 ] = V_45 ;
V_87 ++ ;
V_88 ++ ;
V_48 ++ ;
} else {
F_53 ( 0 , 0 , L_5 , V_45 ) ;
}
break;
}
if ( V_88 < 0 )
V_88 = 0 ;
else if ( V_88 > V_83 - 1 )
V_88 = V_83 - 1 ;
F_54 ( V_85 , 0 , 0 ) ;
F_55 ( V_85 ) ;
F_14 ( V_85 , 0 , 0 , L_3 , V_83 , L_4 ) ;
F_14 ( V_85 , 0 , 0 , L_1 ,
V_89 + V_87 - V_88 ) ;
F_54 ( V_85 , 0 , V_88 ) ;
F_39 ( V_30 ) ;
F_40 ( V_49 ) ;
if ( V_45 == 10 ) {
V_45 = 0 ;
break;
} else if ( V_45 == 27 || V_45 == F_43 ( V_74 ) ||
V_45 == F_43 ( V_75 ) ) {
V_45 = V_76 ;
break;
} else if ( V_45 == F_43 ( V_90 ) ) {
V_45 = 1 ;
break;
}
}
F_52 ( 0 ) ;
F_56 ( V_86 ) ;
F_49 ( V_84 ) ;
F_49 ( V_85 ) ;
F_49 ( V_30 ) ;
return V_45 ;
}
void F_40 ( T_3 * V_49 )
{
F_57 () ;
F_39 ( V_49 ) ;
F_15 () ;
}
void F_58 ( T_3 * V_49 ,
const char * V_77 ,
const char * V_40 )
{
int V_45 ;
int V_46 = F_16 ( V_40 ) ;
int V_36 , V_37 ;
int V_97 = 0 , V_98 = 0 ;
int V_99 = 0 , V_100 = 0 ;
int V_101 = 0 ;
int V_102 = 0 ;
int V_103 = 0 ;
int V_41 = 0 ;
T_3 * V_30 ;
T_3 * V_104 ;
T_8 * V_86 ;
V_46 = F_16 ( V_40 ) ;
for ( V_41 = 0 ; V_41 < V_46 ; V_41 ++ ) {
const char * line = F_17 ( V_40 , V_41 ) ;
int V_48 = F_18 ( line ) ;
V_101 = F_24 ( V_101 , V_48 + 2 ) ;
}
V_104 = F_59 ( V_46 + 10 , V_101 + 10 ) ;
( void ) F_13 ( V_104 , V_65 [ V_11 ] ) ;
F_19 ( V_104 , V_40 ) ;
V_103 = F_21 ( V_46 + 4 , V_63 - 2 ) ;
V_102 = F_21 ( V_101 + 2 , V_64 - 2 ) ;
V_99 = F_24 ( V_103 - 4 , 0 ) ;
V_100 = F_24 ( V_102 - 2 , 0 ) ;
V_37 = ( V_63 - V_103 ) / 2 ;
V_36 = ( V_64 - V_102 ) / 2 ;
V_30 = F_25 ( V_103 , V_102 , V_37 , V_36 ) ;
F_26 ( V_30 , TRUE ) ;
( void ) F_13 ( V_30 , V_65 [ V_13 ] ) ;
F_31 ( V_30 , 0 , 0 ) ;
( void ) F_13 ( V_30 , V_65 [ V_12 ] ) ;
F_14 ( V_30 , 0 , 3 , L_6 , V_77 ) ;
V_86 = F_51 ( V_30 ) ;
do {
F_60 ( V_104 , V_30 , V_98 , V_97 , 2 , 2 , V_99 ,
V_100 , 0 ) ;
F_11 ( V_30 ,
V_99 + 2 ,
0 ,
V_100 ,
L_7 ,
V_65 [ V_17 ] ) ;
F_61 ( V_30 ) ;
V_45 = F_41 ( V_30 ) ;
switch ( V_45 ) {
case V_105 :
case ' ' :
case 'd' :
V_98 += V_99 - 2 ;
break;
case V_106 :
case 'u' :
V_98 -= V_99 + 2 ;
break;
case V_95 :
V_98 = 0 ;
break;
case V_96 :
V_98 = V_46 - V_99 ;
break;
case V_94 :
case 'j' :
V_98 ++ ;
break;
case V_93 :
case 'k' :
V_98 -- ;
break;
case V_70 :
case 'h' :
V_97 -- ;
break;
case V_72 :
case 'l' :
V_97 ++ ;
break;
}
if ( V_45 == 10 || V_45 == 27 || V_45 == 'q' ||
V_45 == F_43 ( V_90 ) || V_45 == F_43 ( V_74 ) ||
V_45 == F_43 ( V_75 ) )
break;
if ( V_98 < 0 )
V_98 = 0 ;
if ( V_98 >= V_46 - V_99 )
V_98 = V_46 - V_99 ;
if ( V_97 < 0 )
V_97 = 0 ;
if ( V_97 >= V_101 - V_100 )
V_97 = V_101 - V_100 ;
} while ( V_45 );
F_56 ( V_86 ) ;
F_49 ( V_30 ) ;
F_40 ( V_49 ) ;
}
