void F_1 ( char * V_1 )
{
char * string ;
F_2 () ;
if ( ! V_1 ) {
return;
}
for ( string = V_1 ; * string ; string ++ ) {
* string = ( char ) F_3 ( * string ) ;
}
return;
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
void F_5 ( char * V_1 )
{
char * string ;
F_2 () ;
if ( ! V_1 ) {
return;
}
for ( string = V_1 ; * string ; string ++ ) {
* string = ( char ) F_6 ( * string ) ;
}
return;
}
T_1 F_7 ( char * string , T_2 V_6 , T_3 * V_7 )
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
F_8 ( V_19 , string ) ;
switch ( V_6 ) {
case V_13 :
case 16 :
break;
default:
F_9 ( V_20 ) ;
}
if ( ! string ) {
goto V_21;
}
while ( ( * string ) && ( F_10 ( * string ) || * string == '\t' ) ) {
string ++ ;
}
if ( V_12 ) {
if ( ( * string == '0' ) && ( F_3 ( * ( string + 1 ) ) == 'x' ) ) {
V_17 = 1 ;
V_6 = 16 ;
string += 2 ;
} else {
V_6 = 10 ;
}
}
if ( ! ( * string ) || F_10 ( * string ) || * string == '\t' ) {
if ( V_12 ) {
goto V_21;
} else {
goto V_22;
}
}
V_11 = ( V_14 ) ? V_23 : V_24 ;
while ( * string ) {
if ( F_11 ( * string ) ) {
V_8 = ( ( T_4 ) * string ) - '0' ;
} else if ( V_6 == 10 ) {
V_18 = 1 ;
} else {
V_8 = ( T_4 ) F_6 ( * string ) ;
if ( F_12 ( ( char ) V_8 ) ) {
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
( void ) F_13 ( ( V_11 - ( T_3 ) V_8 ) ,
V_6 , & V_10 , NULL ) ;
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
F_14 ( ( V_25 , L_1 ,
F_15 ( V_9 ) ) ) ;
* V_7 = V_9 ;
F_9 ( V_26 ) ;
V_21:
if ( V_6 == 10 ) {
F_9 ( V_27 ) ;
} else {
F_9 ( V_28 ) ;
}
}
void F_16 ( char * string , T_4 V_29 )
{
T_2 V_30 ;
if ( ! string ) {
F_17 ( L_2 ) ;
return;
}
F_17 ( L_3 ) ;
for ( V_30 = 0 ; string [ V_30 ] && ( V_30 < V_29 ) ; V_30 ++ ) {
switch ( string [ V_30 ] ) {
case 0x07 :
F_17 ( L_4 ) ;
break;
case 0x08 :
F_17 ( L_5 ) ;
break;
case 0x0C :
F_17 ( L_6 ) ;
break;
case 0x0A :
F_17 ( L_7 ) ;
break;
case 0x0D :
F_17 ( L_8 ) ;
break;
case 0x09 :
F_17 ( L_9 ) ;
break;
case 0x0B :
F_17 ( L_10 ) ;
break;
case '\'' :
case '\"' :
case '\\' :
F_17 ( L_11 , ( int ) string [ V_30 ] ) ;
break;
default:
if ( F_18 ( string [ V_30 ] ) ) {
F_17 ( L_12 , ( int ) string [ V_30 ] ) ;
} else {
F_17 ( L_13 , ( V_31 ) string [ V_30 ] ) ;
}
break;
}
}
F_17 ( L_3 ) ;
if ( V_30 == V_29 && string [ V_30 ] ) {
F_17 ( L_14 ) ;
}
}
T_4 F_19 ( char V_32 , T_2 V_33 )
{
if ( ! ( ( V_32 >= 'A' && V_32 <= 'Z' ) ||
( V_32 >= '0' && V_32 <= '9' ) || ( V_32 == '_' ) ) ) {
if ( V_32 == '!' && V_33 == 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
return ( TRUE ) ;
}
T_4 F_20 ( T_2 V_34 )
{
T_2 V_30 ;
F_2 () ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
if ( ! F_19
( ( F_21 ( char , & V_34 ) ) [ V_30 ] , V_30 ) ) {
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
void F_22 ( char * V_34 )
{
T_2 V_30 ;
T_4 V_36 = FALSE ;
T_2 V_37 ;
F_23 ( V_38 ) ;
F_24 ( & V_37 , V_34 ) ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
if ( F_19 ( V_34 [ V_30 ] , V_30 ) ) {
continue;
}
V_34 [ V_30 ] = '*' ;
V_36 = TRUE ;
}
if ( V_36 ) {
if ( ! V_39 ) {
F_25 ( ( V_40 ,
L_15 ,
V_37 , V_34 ) ) ;
} else {
F_14 ( ( V_41 ,
L_15 ,
V_37 , V_34 ) ) ;
}
}
}
void F_26 ( char * V_42 )
{
if ( ! V_42 ) {
return;
}
while ( * V_42 ) {
if ( * V_42 == '\\' ) {
* V_42 = '/' ;
}
V_42 ++ ;
}
}
