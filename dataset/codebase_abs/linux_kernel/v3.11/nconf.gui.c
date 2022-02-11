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
V_37 = ( F_25 ( V_39 ) - ( V_55 + 4 ) ) / 2 ;
V_36 = ( F_26 ( V_39 ) - ( V_57 + 4 ) ) / 2 ;
if ( V_51 > 0 )
V_58 = V_55 + 4 ;
else
V_58 = V_55 + 2 ;
V_30 = F_27 ( V_58 , V_57 + 4 , V_37 , V_36 ) ;
F_28 ( V_30 , TRUE ) ;
V_60 = F_29 ( V_30 , 1 , V_54 , V_58 - 2 ,
1 + ( V_57 + 2 - V_54 ) / 2 ) ;
V_61 = F_30 ( V_62 ) ;
V_59 = F_29 ( V_30 , V_58 - 2 , V_56 , 1 ,
1 + ( V_57 + 2 - V_56 ) / 2 ) ;
F_31 ( V_61 , V_63 [ V_17 ] ) ;
F_32 ( V_61 , V_63 [ V_16 ] ) ;
( void ) F_13 ( V_30 , V_63 [ V_15 ] ) ;
F_33 ( V_30 , 0 , 0 ) ;
( void ) F_13 ( V_59 , V_63 [ V_14 ] ) ;
F_19 ( V_59 , V_50 ) ;
F_34 ( V_61 , V_30 ) ;
F_35 ( V_61 , V_60 ) ;
F_36 ( V_61 , 1 , V_51 ) ;
F_37 ( V_61 , V_64 ) ;
F_37 ( V_61 , V_65 ) ;
F_38 ( V_61 , V_66 ) ;
F_38 ( V_61 , V_67 ) ;
F_39 ( V_61 , L_2 ) ;
F_40 ( V_61 ) ;
F_41 ( V_30 ) ;
F_42 ( V_49 ) ;
while ( ( V_45 = F_43 ( V_30 ) ) ) {
switch ( V_45 ) {
case V_68 :
F_44 ( V_61 , V_69 ) ;
break;
case V_70 :
F_44 ( V_61 , V_71 ) ;
break;
case 10 :
case 27 :
case ' ' :
case F_45 ( V_72 ) :
case F_45 ( V_73 ) :
break;
}
F_41 ( V_30 ) ;
F_42 ( V_49 ) ;
if ( V_45 == 10 || V_45 == ' ' ) {
V_45 = F_46 ( F_47 ( V_61 ) ) ;
break;
} else if ( V_45 == 27 || V_45 == F_45 ( V_72 ) ||
V_45 == F_45 ( V_73 ) ) {
V_45 = V_74 ;
break;
}
}
F_48 ( V_61 ) ;
F_49 ( V_61 ) ;
for ( V_41 = 0 ; V_41 < V_51 ; V_41 ++ )
F_50 ( V_62 [ V_41 ] ) ;
F_51 ( V_30 ) ;
return V_45 ;
}
int F_52 ( T_3 * V_49 ,
const char * V_75 , const char * V_76 ,
const char * V_77 , char * * V_78 , int * V_79 )
{
int V_80 = 0 ;
int V_81 = 0 ;
T_3 * V_30 ;
T_3 * V_82 ;
T_3 * V_83 ;
T_8 * V_84 ;
int V_41 , V_36 , V_37 ;
int V_45 = - 1 ;
int V_85 = strlen ( V_77 ) ;
int V_86 ;
char * V_87 = * V_78 ;
if ( strlen ( V_77 ) + 1 > * V_79 ) {
* V_79 = strlen ( V_77 ) + 1 ;
* V_78 = V_87 = realloc ( V_87 , * V_79 ) ;
}
V_80 = F_16 ( V_76 ) ;
for ( V_41 = 0 ; V_41 < V_80 ; V_41 ++ ) {
const char * line = F_17 ( V_76 , V_41 ) ;
int V_48 = F_18 ( line ) ;
V_81 = F_24 ( V_81 , V_48 ) ;
}
if ( V_75 )
V_81 = F_24 ( V_81 , strlen ( V_75 ) ) ;
V_37 = ( F_25 ( V_39 ) - ( V_80 + 4 ) ) / 2 ;
V_36 = ( F_26 ( V_39 ) - ( V_81 + 4 ) ) / 2 ;
strncpy ( V_87 , V_77 , * V_79 ) ;
V_30 = F_27 ( V_80 + 6 , V_81 + 7 , V_37 , V_36 ) ;
V_82 = F_29 ( V_30 , V_80 + 1 , V_81 , 2 , 2 ) ;
V_83 = F_29 ( V_30 , 1 , V_81 , V_80 + 3 , 2 ) ;
F_28 ( V_83 , TRUE ) ;
( void ) F_13 ( V_83 , V_63 [ V_22 ] ) ;
( void ) F_13 ( V_30 , V_63 [ V_19 ] ) ;
F_33 ( V_30 , 0 , 0 ) ;
( void ) F_13 ( V_30 , V_63 [ V_20 ] ) ;
if ( V_75 )
F_14 ( V_30 , 0 , 3 , L_1 , V_75 ) ;
( void ) F_13 ( V_82 , V_63 [ V_21 ] ) ;
F_19 ( V_82 , V_76 ) ;
F_14 ( V_83 , 0 , 0 , L_3 , V_81 , L_4 ) ;
V_86 = F_21 ( V_85 , V_81 - 1 ) ;
F_14 ( V_83 , 0 , 0 , L_1 ,
V_87 + V_85 - V_86 ) ;
V_84 = F_53 ( V_30 ) ;
F_54 ( 1 ) ;
F_41 ( V_30 ) ;
F_42 ( V_49 ) ;
while ( ( V_45 = F_43 ( V_83 ) ) ) {
int V_48 = strlen ( V_87 ) ;
switch ( V_45 ) {
case 10 :
case 27 :
case F_45 ( V_88 ) :
case F_45 ( V_73 ) :
case F_45 ( V_72 ) :
break;
case 127 :
case V_89 :
if ( V_85 > 0 ) {
memmove ( & V_87 [ V_85 - 1 ] ,
& V_87 [ V_85 ] ,
V_48 - V_85 + 1 ) ;
V_85 -- ;
V_86 -- ;
V_48 -- ;
}
break;
case V_90 :
if ( V_85 >= 0 && V_85 < V_48 ) {
memmove ( & V_87 [ V_85 ] ,
& V_87 [ V_85 + 1 ] ,
V_48 - V_85 + 1 ) ;
V_48 -- ;
}
break;
case V_91 :
case V_70 :
if ( V_85 < V_48 ) {
V_85 ++ ;
V_86 ++ ;
}
break;
case V_92 :
case V_68 :
if ( V_85 > 0 ) {
V_85 -- ;
V_86 -- ;
}
break;
case V_93 :
V_85 = 0 ;
V_86 = 0 ;
break;
case V_94 :
V_85 = V_48 ;
V_86 = F_21 ( V_85 , V_81 - 1 ) ;
break;
default:
if ( ( isgraph ( V_45 ) || isspace ( V_45 ) ) ) {
if ( V_48 + 2 > * V_79 ) {
* V_79 = V_48 + 2 ;
* V_78 = V_87 = realloc ( V_87 ,
* V_79 ) ;
}
memmove ( & V_87 [ V_85 + 1 ] ,
& V_87 [ V_85 ] ,
V_48 - V_85 + 1 ) ;
V_87 [ V_85 ] = V_45 ;
V_85 ++ ;
V_86 ++ ;
V_48 ++ ;
} else {
F_55 ( 0 , 0 , L_5 , V_45 ) ;
}
break;
}
if ( V_86 < 0 )
V_86 = 0 ;
else if ( V_86 > V_81 - 1 )
V_86 = V_81 - 1 ;
F_56 ( V_83 , 0 , 0 ) ;
F_57 ( V_83 ) ;
F_14 ( V_83 , 0 , 0 , L_3 , V_81 , L_4 ) ;
F_14 ( V_83 , 0 , 0 , L_1 ,
V_87 + V_85 - V_86 ) ;
F_56 ( V_83 , 0 , V_86 ) ;
F_41 ( V_30 ) ;
F_42 ( V_49 ) ;
if ( V_45 == 10 ) {
V_45 = 0 ;
break;
} else if ( V_45 == 27 || V_45 == F_45 ( V_72 ) ||
V_45 == F_45 ( V_73 ) ) {
V_45 = V_74 ;
break;
} else if ( V_45 == F_45 ( V_88 ) ) {
V_45 = 1 ;
break;
}
}
F_54 ( 0 ) ;
F_58 ( V_84 ) ;
F_51 ( V_82 ) ;
F_51 ( V_83 ) ;
F_51 ( V_30 ) ;
return V_45 ;
}
void F_42 ( T_3 * V_49 )
{
F_59 () ;
F_41 ( V_49 ) ;
F_15 () ;
}
void F_60 ( T_3 * V_49 ,
const char * V_75 ,
const char * V_40 )
{
int V_45 ;
int V_46 = F_16 ( V_40 ) ;
int V_36 , V_37 , V_44 , V_95 ;
int V_96 = 0 , V_97 = 0 ;
int V_98 = 0 , V_99 = 0 ;
int V_100 = 0 ;
int V_101 = 0 ;
int V_102 = 0 ;
int V_41 = 0 ;
T_3 * V_30 ;
T_3 * V_103 ;
T_8 * V_84 ;
F_20 ( V_39 , V_44 , V_95 ) ;
V_46 = F_16 ( V_40 ) ;
for ( V_41 = 0 ; V_41 < V_46 ; V_41 ++ ) {
const char * line = F_17 ( V_40 , V_41 ) ;
int V_48 = F_18 ( line ) ;
V_100 = F_24 ( V_100 , V_48 + 2 ) ;
}
V_103 = F_61 ( V_46 + 10 , V_100 + 10 ) ;
( void ) F_13 ( V_103 , V_63 [ V_11 ] ) ;
F_19 ( V_103 , V_40 ) ;
V_102 = F_21 ( V_46 + 4 , V_44 - 2 ) ;
V_101 = F_21 ( V_100 + 2 , V_95 - 2 ) ;
V_98 = F_24 ( V_102 - 4 , 0 ) ;
V_99 = F_24 ( V_101 - 2 , 0 ) ;
V_37 = ( V_44 - V_102 ) / 2 ;
V_36 = ( V_95 - V_101 ) / 2 ;
V_30 = F_27 ( V_102 , V_101 , V_37 , V_36 ) ;
F_28 ( V_30 , TRUE ) ;
( void ) F_13 ( V_30 , V_63 [ V_13 ] ) ;
F_33 ( V_30 , 0 , 0 ) ;
( void ) F_13 ( V_30 , V_63 [ V_12 ] ) ;
F_14 ( V_30 , 0 , 3 , L_6 , V_75 ) ;
V_84 = F_53 ( V_30 ) ;
do {
F_62 ( V_103 , V_30 , V_97 , V_96 , 2 , 2 , V_98 ,
V_99 , 0 ) ;
F_11 ( V_30 ,
V_98 + 2 ,
0 ,
V_99 ,
L_7 ,
V_63 [ V_17 ] ) ;
F_63 ( V_30 ) ;
V_45 = F_43 ( V_30 ) ;
switch ( V_45 ) {
case V_104 :
case ' ' :
case 'd' :
V_97 += V_98 - 2 ;
break;
case V_105 :
case 'u' :
V_97 -= V_98 + 2 ;
break;
case V_93 :
V_97 = 0 ;
break;
case V_94 :
V_97 = V_46 - V_98 ;
break;
case V_92 :
case 'j' :
V_97 ++ ;
break;
case V_91 :
case 'k' :
V_97 -- ;
break;
case V_68 :
case 'h' :
V_96 -- ;
break;
case V_70 :
case 'l' :
V_96 ++ ;
break;
}
if ( V_45 == 10 || V_45 == 27 || V_45 == 'q' ||
V_45 == F_45 ( V_88 ) || V_45 == F_45 ( V_72 ) ||
V_45 == F_45 ( V_73 ) )
break;
if ( V_97 < 0 )
V_97 = 0 ;
if ( V_97 >= V_46 - V_98 )
V_97 = V_46 - V_98 ;
if ( V_96 < 0 )
V_96 = 0 ;
if ( V_96 >= V_100 - V_99 )
V_96 = V_100 - V_99 ;
} while ( V_45 );
F_58 ( V_84 ) ;
F_51 ( V_30 ) ;
F_42 ( V_49 ) ;
}
