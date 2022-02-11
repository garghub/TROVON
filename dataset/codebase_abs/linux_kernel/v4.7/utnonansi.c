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
T_3
F_9 ( char * string ,
T_4 V_11 , T_4 V_12 , T_5 * V_13 )
{
T_4 V_14 = 0 ;
T_5 V_15 = 0 ;
T_5 V_16 ;
T_5 V_17 ;
T_1 V_18 = 0 ;
T_1 V_19 = 0 ;
T_1 V_20 = 0 ;
F_10 ( V_21 , string ) ;
switch ( V_11 ) {
case V_22 :
case 10 :
case 16 :
break;
default:
F_11 ( V_23 ) ;
}
if ( ! string ) {
goto V_24;
}
while ( ( * string ) && ( isspace ( ( int ) * string ) || * string == '\t' ) ) {
string ++ ;
}
if ( V_11 == V_22 ) {
if ( ( * string == '0' ) && ( tolower ( ( int ) * ( string + 1 ) ) == 'x' ) ) {
V_19 = 1 ;
V_11 = 16 ;
string += 2 ;
} else {
V_11 = 10 ;
}
}
if ( ! ( * string ) || isspace ( ( int ) * string ) || * string == '\t' ) {
if ( V_11 == V_22 ) {
goto V_24;
} else {
goto V_25;
}
}
V_17 = ( V_12 <= V_26 ) ?
V_27 : V_28 ;
while ( * string ) {
if ( isdigit ( ( int ) * string ) ) {
V_14 = ( ( T_1 ) * string ) - '0' ;
} else if ( V_11 == 10 ) {
V_20 = 1 ;
} else {
V_14 = ( T_1 ) toupper ( ( int ) * string ) ;
if ( isxdigit ( ( int ) V_14 ) ) {
V_14 = V_14 - 'A' + 10 ;
} else {
V_20 = 1 ;
}
}
if ( V_20 ) {
if ( V_11 == V_22 ) {
goto V_24;
} else {
break;
}
} else if ( ( V_18 == 0 ) && ( V_14 == 0 )
&& ! V_19 ) {
string ++ ;
continue;
}
V_18 ++ ;
if ( V_19 && ( ( V_18 > 16 ) ||
( ( V_18 > 8 )
&& ( V_12 <=
V_26 ) ) ) ) {
goto V_24;
}
( void ) F_12 ( ( V_17 - ( T_5 ) V_14 ) , V_11 ,
& V_16 , NULL ) ;
if ( V_15 > V_16 ) {
if ( V_11 == V_22 ) {
goto V_24;
} else {
break;
}
}
V_15 *= V_11 ;
V_15 += V_14 ;
string ++ ;
}
V_25:
F_13 ( ( V_29 , L_1 ,
F_14 ( V_15 ) ) ) ;
* V_13 = V_15 ;
F_11 ( V_30 ) ;
V_24:
if ( V_11 == 10 ) {
F_11 ( V_31 ) ;
} else {
F_11 ( V_32 ) ;
}
}
T_3 F_15 ( char * string , T_4 V_11 , T_5 * V_13 )
{
T_4 V_33 ;
T_4 V_34 ;
T_5 V_15 = 0 ;
T_3 V_35 = V_30 ;
* V_13 = 0 ;
switch ( V_11 ) {
case 0 :
case 8 :
case 10 :
case 16 :
break;
default:
return ( V_23 ) ;
}
while ( isspace ( ( int ) * string ) || * string == '\t' ) {
++ string ;
}
if ( * string == '-' ) {
V_34 = V_36 ;
++ string ;
} else if ( * string == '+' ) {
++ string ;
V_34 = V_37 ;
} else {
V_34 = V_37 ;
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
V_33 = ( ( T_1 ) * string ) - '0' ;
} else {
V_33 = ( T_1 ) toupper ( ( int ) * string ) ;
if ( isupper ( ( int ) V_33 ) ) {
V_33 = V_33 - 'A' + 10 ;
} else {
goto V_24;
}
}
if ( V_33 >= V_11 ) {
goto V_24;
}
if ( V_15 > ( ( V_28 - ( T_5 ) V_33 ) / ( T_5 ) V_11 ) ) {
goto V_24;
} else {
V_15 *= V_11 ;
V_15 += V_33 ;
}
++ string ;
}
if ( V_34 == V_36 ) {
V_15 = ( V_27 - V_15 ) + 1 ;
}
* V_13 = V_15 ;
return ( V_35 ) ;
V_24:
switch ( V_11 ) {
case 8 :
V_35 = V_38 ;
break;
case 10 :
V_35 = V_31 ;
break;
case 16 :
V_35 = V_32 ;
break;
default:
break;
}
return ( V_35 ) ;
}
