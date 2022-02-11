void F_1 ( char * string , T_1 V_1 )
{
T_2 V_2 ;
if ( ! string ) {
F_2 ( L_1 ) ;
return;
}
F_2 ( L_2 ) ;
for ( V_2 = 0 ; ( V_2 < V_1 ) && string [ V_2 ] ; V_2 ++ ) {
switch ( string [ V_2 ] ) {
case 0x07 :
F_2 ( L_3 ) ;
break;
case 0x08 :
F_2 ( L_4 ) ;
break;
case 0x0C :
F_2 ( L_5 ) ;
break;
case 0x0A :
F_2 ( L_6 ) ;
break;
case 0x0D :
F_2 ( L_7 ) ;
break;
case 0x09 :
F_2 ( L_8 ) ;
break;
case 0x0B :
F_2 ( L_9 ) ;
break;
case '\'' :
case '\"' :
case '\\' :
F_2 ( L_10 , ( int ) string [ V_2 ] ) ;
break;
default:
if ( isprint ( ( int ) string [ V_2 ] ) ) {
F_2 ( L_11 , ( int ) string [ V_2 ] ) ;
} else {
F_2 ( L_12 , ( V_3 ) string [ V_2 ] ) ;
}
break;
}
}
F_2 ( L_2 ) ;
if ( V_2 == V_1 && string [ V_2 ] ) {
F_2 ( L_13 ) ;
}
}
T_3 F_3 ( char V_4 , T_2 V_5 )
{
if ( ! ( ( V_4 >= 'A' && V_4 <= 'Z' ) ||
( V_4 >= '0' && V_4 <= '9' ) || ( V_4 == '_' ) ) ) {
if ( V_4 == '!' && V_5 == 3 ) {
return ( TRUE ) ;
}
return ( FALSE ) ;
}
return ( TRUE ) ;
}
T_3 F_4 ( char * V_6 )
{
T_2 V_2 ;
F_5 () ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
if ( ! F_3 ( V_6 [ V_2 ] , V_2 ) ) {
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
void F_6 ( char * V_6 )
{
T_2 V_2 ;
T_3 V_8 = FALSE ;
T_2 V_9 ;
F_7 ( V_10 ) ;
if ( F_8 ( V_6 , L_14 ) ) {
return;
}
F_9 ( & V_9 , V_6 ) ;
for ( V_2 = 0 ; V_2 < V_7 ; V_2 ++ ) {
if ( F_3 ( V_6 [ V_2 ] , V_2 ) ) {
continue;
}
V_6 [ V_2 ] = '*' ;
V_8 = TRUE ;
}
if ( V_8 ) {
if ( ! V_11 ) {
F_10 ( ( V_12 ,
L_15 ,
V_9 , V_6 ) ) ;
} else {
F_11 ( ( V_13 ,
L_15 ,
V_9 , V_6 ) ) ;
}
}
}
void F_12 ( char * V_14 )
{
if ( ! V_14 ) {
return;
}
while ( * V_14 ) {
if ( * V_14 == '\\' ) {
* V_14 = '/' ;
}
V_14 ++ ;
}
}
