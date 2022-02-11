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
T_1 F_5 ( char * V_6 , T_2 V_7 , char * V_8 )
{
if ( strlen ( V_8 ) >= V_7 ) {
return ( TRUE ) ;
}
strcpy ( V_6 , V_8 ) ;
return ( FALSE ) ;
}
T_1 F_6 ( char * V_6 , T_2 V_7 , char * V_8 )
{
if ( ( strlen ( V_6 ) + strlen ( V_8 ) ) >= V_7 ) {
return ( TRUE ) ;
}
strcat ( V_6 , V_8 ) ;
return ( FALSE ) ;
}
T_1
F_7 ( char * V_6 ,
T_2 V_7 ,
char * V_8 , T_2 V_9 )
{
T_2 V_10 ;
V_10 = F_8 ( V_9 , strlen ( V_8 ) ) ;
if ( ( strlen ( V_6 ) + V_10 ) >= V_7 ) {
return ( TRUE ) ;
}
strncat ( V_6 , V_8 , V_9 ) ;
return ( FALSE ) ;
}
T_3 F_9 ( char * string , T_4 V_11 , T_5 * V_12 )
{
T_4 V_13 = 0 ;
T_5 V_14 = 0 ;
T_5 V_15 ;
T_5 V_16 ;
T_4 V_17 = ( V_11 == V_18 ) ;
T_4 V_19 = ( V_20 == 4 ) ;
T_1 V_21 = 0 ;
T_1 V_22 = 0 ;
T_1 V_23 = 0 ;
F_10 ( V_24 , string ) ;
switch ( V_11 ) {
case V_18 :
case 16 :
break;
default:
F_11 ( V_25 ) ;
}
if ( ! string ) {
goto V_26;
}
while ( ( * string ) && ( isspace ( ( int ) * string ) || * string == '\t' ) ) {
string ++ ;
}
if ( V_17 ) {
if ( ( * string == '0' ) && ( tolower ( ( int ) * ( string + 1 ) ) == 'x' ) ) {
V_22 = 1 ;
V_11 = 16 ;
string += 2 ;
} else {
V_11 = 10 ;
}
}
if ( ! ( * string ) || isspace ( ( int ) * string ) || * string == '\t' ) {
if ( V_17 ) {
goto V_26;
} else {
goto V_27;
}
}
V_16 = ( V_19 ) ? V_28 : V_29 ;
while ( * string ) {
if ( isdigit ( ( int ) * string ) ) {
V_13 = ( ( T_1 ) * string ) - '0' ;
} else if ( V_11 == 10 ) {
V_23 = 1 ;
} else {
V_13 = ( T_1 ) toupper ( ( int ) * string ) ;
if ( isxdigit ( ( int ) V_13 ) ) {
V_13 = V_13 - 'A' + 10 ;
} else {
V_23 = 1 ;
}
}
if ( V_23 ) {
if ( V_17 ) {
goto V_26;
} else {
break;
}
} else if ( ( V_21 == 0 ) && ( V_13 == 0 )
&& ! V_22 ) {
string ++ ;
continue;
}
V_21 ++ ;
if ( V_22
&& ( ( V_21 > 16 )
|| ( ( V_21 > 8 ) && V_19 ) ) ) {
goto V_26;
}
( void ) F_12 ( ( V_16 - ( T_5 ) V_13 ) , V_11 ,
& V_15 , NULL ) ;
if ( V_14 > V_15 ) {
if ( V_17 ) {
goto V_26;
} else {
break;
}
}
V_14 *= V_11 ;
V_14 += V_13 ;
string ++ ;
}
V_27:
F_13 ( ( V_30 , L_1 ,
F_14 ( V_14 ) ) ) ;
* V_12 = V_14 ;
F_11 ( V_31 ) ;
V_26:
if ( V_11 == 10 ) {
F_11 ( V_32 ) ;
} else {
F_11 ( V_33 ) ;
}
}
T_3 F_15 ( char * string , T_4 V_11 , T_5 * V_12 )
{
T_4 V_34 ;
T_4 V_35 ;
T_5 V_14 = 0 ;
T_3 V_36 = V_31 ;
* V_12 = 0 ;
switch ( V_11 ) {
case 0 :
case 8 :
case 10 :
case 16 :
break;
default:
return ( V_25 ) ;
}
while ( isspace ( ( int ) * string ) || * string == '\t' ) {
++ string ;
}
if ( * string == '-' ) {
V_35 = V_37 ;
++ string ;
} else if ( * string == '+' ) {
++ string ;
V_35 = V_38 ;
} else {
V_35 = V_38 ;
}
if ( V_11 == 0 ) {
if ( * string == '0' ) {
if ( tolower ( ( int ) * ( ++ string ) ) == 'x' ) {
V_11 = 16 ;
++ string ;
} else {
V_11 = 8 ;
}
} else {
V_11 = 10 ;
}
}
if ( V_11 == 8 && * string == '0' ) {
string ++ ;
}
if ( V_11 == 16 && * string == '0' && tolower ( ( int ) * ( ++ string ) ) == 'x' ) {
string ++ ;
}
while ( * string ) {
if ( isdigit ( ( int ) * string ) ) {
V_34 = ( ( T_1 ) * string ) - '0' ;
} else {
V_34 = ( T_1 ) toupper ( ( int ) * string ) ;
if ( isupper ( ( int ) V_34 ) ) {
V_34 = V_34 - 'A' + 10 ;
} else {
goto V_26;
}
}
if ( V_34 >= V_11 ) {
goto V_26;
}
if ( V_14 > ( ( V_29 - ( T_5 ) V_34 ) / ( T_5 ) V_11 ) ) {
goto V_26;
} else {
V_14 *= V_11 ;
V_14 += V_34 ;
}
++ string ;
}
if ( V_35 == V_37 ) {
V_14 = ( V_28 - V_14 ) + 1 ;
}
* V_12 = V_14 ;
return ( V_36 ) ;
V_26:
switch ( V_11 ) {
case 8 :
V_36 = V_39 ;
break;
case 10 :
V_36 = V_32 ;
break;
case 16 :
V_36 = V_33 ;
break;
default:
break;
}
return ( V_36 ) ;
}
