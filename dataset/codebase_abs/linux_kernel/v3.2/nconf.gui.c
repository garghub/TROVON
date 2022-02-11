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
F_2 ( V_24 , V_25 , - 1 ) ;
}
static void F_3 ( void )
{
#define F_4 ( T_1 , T_2 ) do { \
attributes[name] = attr | COLOR_PAIR(name); } while (0)
F_4 ( V_1 , V_1 ) ;
F_4 ( V_2 , V_26 | V_27 ) ;
F_4 ( V_4 , V_28 ) ;
F_4 ( V_5 , V_29 ) ;
F_4 ( V_6 , V_29 ) ;
F_4 ( V_7 , V_26 ) ;
F_4 ( V_9 , V_29 ) ;
F_4 ( V_11 , V_29 ) ;
F_4 ( V_12 , V_26 ) ;
F_4 ( V_13 , V_26 ) ;
F_4 ( V_14 , V_26 ) ;
F_4 ( V_15 , V_26 ) ;
F_4 ( V_17 , V_30 ) ;
F_4 ( V_16 , V_29 ) ;
F_4 ( V_19 , V_29 ) ;
F_4 ( V_20 , V_26 ) ;
F_4 ( V_21 , V_29 ) ;
F_4 ( V_22 , V_27 ) ;
F_4 ( V_23 , V_26 ) ;
F_4 ( V_24 , V_28 ) ;
}
static void F_5 ( void )
{
#define F_6 ( T_1 , T_2 ) { attributes[name] = attr; }
F_6 ( V_1 , V_1 ) ;
F_6 ( V_2 , V_26 | V_27 ) ;
F_6 ( V_4 , V_30 ) ;
F_6 ( V_5 , V_29 ) ;
F_6 ( V_6 , V_29 ) ;
F_6 ( V_7 , V_26 ) ;
F_6 ( V_9 , V_29 ) ;
F_6 ( V_11 , V_29 ) ;
F_6 ( V_12 , V_26 ) ;
F_6 ( V_13 , V_26 ) ;
F_6 ( V_14 , V_29 ) ;
F_6 ( V_15 , V_26 ) ;
F_6 ( V_17 , V_30 ) ;
F_6 ( V_16 , V_29 ) ;
F_6 ( V_19 , V_26 ) ;
F_6 ( V_20 , V_26 ) ;
F_6 ( V_21 , V_29 ) ;
F_6 ( V_22 , V_27 ) ;
F_6 ( V_23 , V_26 ) ;
F_6 ( V_24 , V_28 ) ;
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
void F_11 ( T_3 * V_31 ,
int V_32 ,
int V_33 ,
int V_34 ,
const char * string ,
T_4 V_35 )
{ int V_36 , V_37 , V_38 ;
float V_39 ;
if ( V_31 == NULL )
V_31 = V_40 ;
F_12 ( V_31 , V_38 , V_37 ) ;
if ( V_33 != 0 )
V_37 = V_33 ;
if ( V_32 != 0 )
V_38 = V_32 ;
if ( V_34 == 0 )
V_34 = 80 ;
V_36 = strlen ( string ) ;
V_39 = ( V_34 - V_36 ) / 2 ;
V_37 = V_33 + ( int ) V_39 ;
( void ) F_13 ( V_31 , V_35 ) ;
F_14 ( V_31 , V_38 , V_37 , L_1 , string ) ;
F_15 () ;
}
int F_16 ( const char * V_41 )
{
int V_42 ;
int V_43 = 1 ;
if ( ! V_41 )
return 0 ;
for ( V_42 = 0 ; V_41 [ V_42 ] != '\0' ; V_42 ++ )
if ( V_41 [ V_42 ] == '\n' )
V_43 ++ ;
return V_43 ;
}
const char * F_17 ( const char * V_41 , int V_44 )
{
int V_42 ;
int V_45 = 0 ;
if ( ! V_41 )
return 0 ;
for ( V_42 = 0 ; V_41 [ V_42 ] != '\0' && V_45 < V_44 ; V_42 ++ )
if ( V_41 [ V_42 ] == '\n' )
V_45 ++ ;
return V_41 + V_42 ;
}
int F_18 ( const char * line )
{
int V_46 = 0 ;
while ( * line != '\0' && * line != '\n' ) {
line ++ ;
V_46 ++ ;
}
return V_46 ;
}
void F_19 ( T_3 * V_31 , const char * V_41 )
{
int V_37 , V_38 ;
int V_47 = F_16 ( V_41 ) ;
int V_42 ;
F_20 ( V_31 , V_38 , V_37 ) ;
V_47 = F_21 ( V_47 , V_38 ) ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ ) {
char V_48 [ V_37 + 10 ] ;
const char * line = F_17 ( V_41 , V_42 ) ;
int V_49 = F_18 ( line ) ;
strncpy ( V_48 , line , F_21 ( V_49 , V_37 ) ) ;
V_48 [ V_49 ] = '\0' ;
F_14 ( V_31 , V_42 , 0 , L_1 , V_48 ) ;
}
}
int F_22 ( T_3 * V_50 , const char * V_51 , int V_52 , ... )
{
T_5 V_53 ;
char * V_54 ;
int V_55 = 0 ;
int V_56 = 0 ;
int V_57 = 0 ;
int V_58 ;
int V_59 = 0 ;
T_3 * V_31 ;
T_3 * V_60 ;
T_3 * V_61 ;
T_6 * V_62 ;
T_7 * V_63 [ V_52 + 1 ] ;
int V_42 , V_37 , V_38 ;
int V_46 = - 1 ;
va_start ( V_53 , V_52 ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ ) {
V_54 = va_arg ( V_53 , char * ) ;
V_63 [ V_42 ] = F_23 ( V_54 , L_2 ) ;
V_55 += strlen ( V_54 ) + 1 ;
}
va_end ( V_53 ) ;
V_63 [ V_52 ] = NULL ;
V_56 = F_16 ( V_51 ) ;
for ( V_42 = 0 ; V_42 < V_56 ; V_42 ++ ) {
const char * line = F_17 ( V_51 , V_42 ) ;
int V_49 = F_18 ( line ) ;
if ( V_57 < V_49 )
V_57 = V_49 ;
}
V_58 = F_24 ( V_57 , V_55 ) ;
V_38 = ( V_64 - ( V_56 + 4 ) ) / 2 ;
V_37 = ( V_65 - ( V_58 + 4 ) ) / 2 ;
if ( V_52 > 0 )
V_59 = V_56 + 4 ;
else
V_59 = V_56 + 2 ;
V_31 = F_25 ( V_59 , V_58 + 4 , V_38 , V_37 ) ;
F_26 ( V_31 , TRUE ) ;
V_61 = F_27 ( V_31 , 1 , V_55 , V_59 - 2 ,
1 + ( V_58 + 2 - V_55 ) / 2 ) ;
V_62 = F_28 ( V_63 ) ;
V_60 = F_27 ( V_31 , V_59 - 2 , V_57 , 1 ,
1 + ( V_58 + 2 - V_57 ) / 2 ) ;
F_29 ( V_62 , V_66 [ V_17 ] ) ;
F_30 ( V_62 , V_66 [ V_16 ] ) ;
( void ) F_13 ( V_31 , V_66 [ V_15 ] ) ;
F_31 ( V_31 , 0 , 0 ) ;
( void ) F_13 ( V_60 , V_66 [ V_14 ] ) ;
F_19 ( V_60 , V_51 ) ;
F_32 ( V_62 , V_31 ) ;
F_33 ( V_62 , V_61 ) ;
F_34 ( V_62 , 1 , V_52 ) ;
F_35 ( V_62 , V_67 ) ;
F_35 ( V_62 , V_68 ) ;
F_36 ( V_62 , V_69 ) ;
F_36 ( V_62 , V_70 ) ;
F_37 ( V_62 , L_2 ) ;
F_38 ( V_62 ) ;
F_39 ( V_31 ) ;
F_40 ( V_50 ) ;
while ( ( V_46 = F_41 ( V_31 ) ) ) {
switch ( V_46 ) {
case V_71 :
F_42 ( V_62 , V_72 ) ;
break;
case V_73 :
F_42 ( V_62 , V_74 ) ;
break;
case 10 :
case 27 :
case ' ' :
case F_43 ( V_75 ) :
case F_43 ( V_76 ) :
break;
}
F_39 ( V_31 ) ;
F_40 ( V_50 ) ;
if ( V_46 == 10 || V_46 == ' ' ) {
V_46 = F_44 ( F_45 ( V_62 ) ) ;
break;
} else if ( V_46 == 27 || V_46 == F_43 ( V_75 ) ||
V_46 == F_43 ( V_76 ) ) {
V_46 = V_77 ;
break;
}
}
F_46 ( V_62 ) ;
F_47 ( V_62 ) ;
for ( V_42 = 0 ; V_42 < V_52 ; V_42 ++ )
F_48 ( V_63 [ V_42 ] ) ;
F_49 ( V_31 ) ;
return V_46 ;
}
int F_50 ( T_3 * V_50 ,
const char * V_78 , const char * V_79 ,
const char * V_80 , char * * V_81 , int * V_82 )
{
int V_83 = 0 ;
int V_84 = 0 ;
T_3 * V_31 ;
T_3 * V_85 ;
T_3 * V_86 ;
T_8 * V_87 ;
int V_42 , V_37 , V_38 ;
int V_46 = - 1 ;
int V_88 = strlen ( V_80 ) ;
int V_89 ;
char * V_90 = * V_81 ;
if ( strlen ( V_80 ) + 1 > * V_82 ) {
* V_82 = strlen ( V_80 ) + 1 ;
* V_81 = V_90 = realloc ( V_90 , * V_82 ) ;
}
V_83 = F_16 ( V_79 ) ;
for ( V_42 = 0 ; V_42 < V_83 ; V_42 ++ ) {
const char * line = F_17 ( V_79 , V_42 ) ;
int V_49 = F_18 ( line ) ;
V_84 = F_24 ( V_84 , V_49 ) ;
}
if ( V_78 )
V_84 = F_24 ( V_84 , strlen ( V_78 ) ) ;
V_38 = ( V_64 - ( V_83 + 4 ) ) / 2 ;
V_37 = ( V_65 - ( V_84 + 4 ) ) / 2 ;
strncpy ( V_90 , V_80 , * V_82 ) ;
V_31 = F_25 ( V_83 + 6 , V_84 + 7 , V_38 , V_37 ) ;
V_85 = F_27 ( V_31 , V_83 + 1 , V_84 , 2 , 2 ) ;
V_86 = F_27 ( V_31 , 1 , V_84 , V_83 + 3 , 2 ) ;
F_26 ( V_86 , TRUE ) ;
( void ) F_13 ( V_86 , V_66 [ V_22 ] ) ;
( void ) F_13 ( V_31 , V_66 [ V_19 ] ) ;
F_31 ( V_31 , 0 , 0 ) ;
( void ) F_13 ( V_31 , V_66 [ V_20 ] ) ;
if ( V_78 )
F_14 ( V_31 , 0 , 3 , L_1 , V_78 ) ;
( void ) F_13 ( V_85 , V_66 [ V_21 ] ) ;
F_19 ( V_85 , V_79 ) ;
F_14 ( V_86 , 0 , 0 , L_3 , V_84 , L_4 ) ;
V_89 = F_21 ( V_88 , V_84 - 1 ) ;
F_14 ( V_86 , 0 , 0 , L_1 ,
V_90 + V_88 - V_89 ) ;
V_87 = F_51 ( V_31 ) ;
F_52 ( 1 ) ;
F_39 ( V_31 ) ;
F_40 ( V_50 ) ;
while ( ( V_46 = F_41 ( V_86 ) ) ) {
int V_49 = strlen ( V_90 ) ;
switch ( V_46 ) {
case 10 :
case 27 :
case F_43 ( V_91 ) :
case F_43 ( V_76 ) :
case F_43 ( V_75 ) :
break;
case 127 :
case V_92 :
if ( V_88 > 0 ) {
memmove ( & V_90 [ V_88 - 1 ] ,
& V_90 [ V_88 ] ,
V_49 - V_88 + 1 ) ;
V_88 -- ;
V_89 -- ;
V_49 -- ;
}
break;
case V_93 :
if ( V_88 >= 0 && V_88 < V_49 ) {
memmove ( & V_90 [ V_88 ] ,
& V_90 [ V_88 + 1 ] ,
V_49 - V_88 + 1 ) ;
V_49 -- ;
}
break;
case V_94 :
case V_73 :
if ( V_88 < V_49 ) {
V_88 ++ ;
V_89 ++ ;
}
break;
case V_95 :
case V_71 :
if ( V_88 > 0 ) {
V_88 -- ;
V_89 -- ;
}
break;
case V_96 :
V_88 = 0 ;
V_89 = 0 ;
break;
case V_97 :
V_88 = V_49 ;
V_89 = F_21 ( V_88 , V_84 - 1 ) ;
break;
default:
if ( ( isgraph ( V_46 ) || isspace ( V_46 ) ) ) {
if ( V_49 + 2 > * V_82 ) {
* V_82 = V_49 + 2 ;
* V_81 = V_90 = realloc ( V_90 ,
* V_82 ) ;
}
memmove ( & V_90 [ V_88 + 1 ] ,
& V_90 [ V_88 ] ,
V_49 - V_88 + 1 ) ;
V_90 [ V_88 ] = V_46 ;
V_88 ++ ;
V_89 ++ ;
V_49 ++ ;
} else {
F_53 ( 0 , 0 , L_5 , V_46 ) ;
}
break;
}
if ( V_89 < 0 )
V_89 = 0 ;
else if ( V_89 > V_84 - 1 )
V_89 = V_84 - 1 ;
F_54 ( V_86 , 0 , 0 ) ;
F_55 ( V_86 ) ;
F_14 ( V_86 , 0 , 0 , L_3 , V_84 , L_4 ) ;
F_14 ( V_86 , 0 , 0 , L_1 ,
V_90 + V_88 - V_89 ) ;
F_54 ( V_86 , 0 , V_89 ) ;
F_39 ( V_31 ) ;
F_40 ( V_50 ) ;
if ( V_46 == 10 ) {
V_46 = 0 ;
break;
} else if ( V_46 == 27 || V_46 == F_43 ( V_75 ) ||
V_46 == F_43 ( V_76 ) ) {
V_46 = V_77 ;
break;
} else if ( V_46 == F_43 ( V_91 ) ) {
V_46 = 1 ;
break;
}
}
F_52 ( 0 ) ;
F_56 ( V_87 ) ;
F_49 ( V_85 ) ;
F_49 ( V_86 ) ;
F_49 ( V_31 ) ;
return V_46 ;
}
void F_40 ( T_3 * V_50 )
{
F_57 () ;
F_39 ( V_50 ) ;
F_15 () ;
}
void F_58 ( T_3 * V_50 ,
const char * V_78 ,
const char * V_41 )
{
int V_46 ;
int V_47 = F_16 ( V_41 ) ;
int V_37 , V_38 ;
int V_98 = 0 , V_99 = 0 ;
int V_100 = 0 , V_101 = 0 ;
int V_102 = 0 ;
int V_103 = 0 ;
int V_104 = 0 ;
int V_42 = 0 ;
T_3 * V_31 ;
T_3 * V_105 ;
T_8 * V_87 ;
V_47 = F_16 ( V_41 ) ;
for ( V_42 = 0 ; V_42 < V_47 ; V_42 ++ ) {
const char * line = F_17 ( V_41 , V_42 ) ;
int V_49 = F_18 ( line ) ;
V_102 = F_24 ( V_102 , V_49 + 2 ) ;
}
V_105 = F_59 ( V_47 + 10 , V_102 + 10 ) ;
( void ) F_13 ( V_105 , V_66 [ V_11 ] ) ;
F_19 ( V_105 , V_41 ) ;
V_104 = F_21 ( V_47 + 4 , V_64 - 2 ) ;
V_103 = F_21 ( V_102 + 2 , V_65 - 2 ) ;
V_100 = F_24 ( V_104 - 4 , 0 ) ;
V_101 = F_24 ( V_103 - 2 , 0 ) ;
V_38 = ( V_64 - V_104 ) / 2 ;
V_37 = ( V_65 - V_103 ) / 2 ;
V_31 = F_25 ( V_104 , V_103 , V_38 , V_37 ) ;
F_26 ( V_31 , TRUE ) ;
( void ) F_13 ( V_31 , V_66 [ V_13 ] ) ;
F_31 ( V_31 , 0 , 0 ) ;
( void ) F_13 ( V_31 , V_66 [ V_12 ] ) ;
F_14 ( V_31 , 0 , 3 , L_6 , V_78 ) ;
V_87 = F_51 ( V_31 ) ;
do {
F_60 ( V_105 , V_31 , V_99 , V_98 , 2 , 2 , V_100 ,
V_101 , 0 ) ;
F_11 ( V_31 ,
V_100 + 2 ,
0 ,
V_101 ,
L_7 ,
V_66 [ V_17 ] ) ;
F_61 ( V_31 ) ;
V_46 = F_41 ( V_31 ) ;
switch ( V_46 ) {
case V_106 :
case ' ' :
V_99 += V_100 - 2 ;
break;
case V_107 :
V_99 -= V_100 + 2 ;
break;
case V_96 :
V_99 = 0 ;
break;
case V_97 :
V_99 = V_47 - V_100 ;
break;
case V_95 :
case 'j' :
V_99 ++ ;
break;
case V_94 :
case 'k' :
V_99 -- ;
break;
case V_71 :
case 'h' :
V_98 -- ;
break;
case V_73 :
case 'l' :
V_98 ++ ;
break;
}
if ( V_46 == 10 || V_46 == 27 || V_46 == 'q'
|| V_46 == F_43 ( V_75 ) || V_46 == F_43 ( V_76 ) ) {
break;
}
if ( V_99 < 0 )
V_99 = 0 ;
if ( V_99 >= V_47 - V_100 )
V_99 = V_47 - V_100 ;
if ( V_98 < 0 )
V_98 = 0 ;
if ( V_98 >= V_102 - V_101 )
V_98 = V_102 - V_101 ;
} while ( V_46 );
F_56 ( V_87 ) ;
F_49 ( V_31 ) ;
F_40 ( V_50 ) ;
}
