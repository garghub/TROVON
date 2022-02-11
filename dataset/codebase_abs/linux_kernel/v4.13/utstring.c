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
void F_3 ( char * V_4 )
{
T_2 V_2 ;
T_3 V_5 = FALSE ;
T_2 V_6 ;
F_4 ( V_7 ) ;
if ( F_5 ( V_4 , L_14 ) ) {
return;
}
F_6 ( & V_6 , V_4 ) ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ ) {
if ( F_7 ( V_4 [ V_2 ] , V_2 ) ) {
continue;
}
V_4 [ V_2 ] = '*' ;
V_5 = TRUE ;
}
if ( V_5 ) {
if ( ! V_9 ) {
F_8 ( ( V_10 ,
L_15 ,
V_6 , V_4 ) ) ;
} else {
F_9 ( ( V_11 ,
L_15 ,
V_6 , V_4 ) ) ;
}
}
}
void F_10 ( char * V_12 )
{
if ( ! V_12 ) {
return;
}
while ( * V_12 ) {
if ( * V_12 == '\\' ) {
* V_12 = '/' ;
}
V_12 ++ ;
}
}
