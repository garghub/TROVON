void F_1 ( char * V_1 )
{
char * string ;
F_2 () ;
if ( ! V_1 ) {
return;
}
for ( string = V_1 ; * string ; string ++ ) {
* string = ( char ) tolower ( ( int ) * string ) ;
}
}
void F_3 ( char * V_1 )
{
char * string ;
F_2 () ;
if ( ! V_1 ) {
return;
}
for ( string = V_1 ; * string ; string ++ ) {
* string = ( char ) toupper ( ( int ) * string ) ;
}
}
int F_4 ( char * V_2 , char * V_3 )
{
int V_4 ;
int V_5 ;
do {
V_4 = tolower ( ( int ) * V_2 ) ;
V_5 = tolower ( ( int ) * V_3 ) ;
V_2 ++ ;
V_3 ++ ;
}
while ( ( V_4 == V_5 ) && ( V_4 ) );
return ( V_4 - V_5 ) ;
}
T_1 F_5 ( char * string , T_2 V_6 , T_3 * V_7 )
{
T_2 V_8 = 0 ;
T_3 V_9 = 0 ;
T_3 V_10 ;
T_3 V_11 ;
T_2 V_12 = ( V_6 == V_13 ) ;
T_2 V_14 = ( V_15 == 4 ) ;
T_4 V_16 = 0 ;
T_4 V_17 = 0 ;
T_4 V_18 = 0 ;
F_6 ( V_19 , string ) ;
switch ( V_6 ) {
case V_13 :
case 16 :
break;
default:
F_7 ( V_20 ) ;
}
if ( ! string ) {
goto V_21;
}
while ( ( * string ) && ( isspace ( ( int ) * string ) || * string == '\t' ) ) {
string ++ ;
}
if ( V_12 ) {
if ( ( * string == '0' ) && ( tolower ( ( int ) * ( string + 1 ) ) == 'x' ) ) {
V_17 = 1 ;
V_6 = 16 ;
string += 2 ;
} else {
V_6 = 10 ;
}
}
if ( ! ( * string ) || isspace ( ( int ) * string ) || * string == '\t' ) {
if ( V_12 ) {
goto V_21;
} else {
goto V_22;
}
}
V_11 = ( V_14 ) ? V_23 : V_24 ;
while ( * string ) {
if ( isdigit ( ( int ) * string ) ) {
V_8 = ( ( T_4 ) * string ) - '0' ;
} else if ( V_6 == 10 ) {
V_18 = 1 ;
} else {
V_8 = ( T_4 ) toupper ( ( int ) * string ) ;
if ( isxdigit ( ( int ) V_8 ) ) {
V_8 = V_8 - 'A' + 10 ;
} else {
V_18 = 1 ;
}
}
if ( V_18 ) {
if ( V_12 ) {
goto V_21;
} else {
break;
}
} else if ( ( V_16 == 0 ) && ( V_8 == 0 )
&& ! V_17 ) {
string ++ ;
continue;
}
V_16 ++ ;
if ( V_17
&& ( ( V_16 > 16 )
|| ( ( V_16 > 8 ) && V_14 ) ) ) {
goto V_21;
}
( void ) F_8 ( ( V_11 - ( T_3 ) V_8 ) , V_6 ,
& V_10 , NULL ) ;
if ( V_9 > V_10 ) {
if ( V_12 ) {
goto V_21;
} else {
break;
}
}
V_9 *= V_6 ;
V_9 += V_8 ;
string ++ ;
}
V_22:
F_9 ( ( V_25 , L_1 ,
F_10 ( V_9 ) ) ) ;
* V_7 = V_9 ;
F_7 ( V_26 ) ;
V_21:
if ( V_6 == 10 ) {
F_7 ( V_27 ) ;
} else {
F_7 ( V_28 ) ;
}
}
T_4 F_11 ( char * V_29 , T_5 V_30 , char * V_31 )
{
if ( strlen ( V_31 ) >= V_30 ) {
return ( TRUE ) ;
}
strcpy ( V_29 , V_31 ) ;
return ( FALSE ) ;
}
T_4 F_12 ( char * V_29 , T_5 V_30 , char * V_31 )
{
if ( ( strlen ( V_29 ) + strlen ( V_31 ) ) >= V_30 ) {
return ( TRUE ) ;
}
strcat ( V_29 , V_31 ) ;
return ( FALSE ) ;
}
T_4
F_13 ( char * V_29 ,
T_5 V_30 ,
char * V_31 , T_5 V_32 )
{
T_5 V_33 ;
V_33 = F_14 ( V_32 , strlen ( V_31 ) ) ;
if ( ( strlen ( V_29 ) + V_33 ) >= V_30 ) {
return ( TRUE ) ;
}
strncat ( V_29 , V_31 , V_32 ) ;
return ( FALSE ) ;
}
