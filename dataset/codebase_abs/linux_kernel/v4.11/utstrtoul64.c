T_1 F_1 ( char * string , T_2 V_1 , T_3 * V_2 )
{
T_1 V_3 = V_4 ;
T_2 V_5 ;
F_2 ( V_6 , string ) ;
if ( ! string || ! V_2 ) {
F_3 ( V_7 ) ;
}
* V_2 = 0 ;
if ( * string == 0 ) {
F_3 ( V_4 ) ;
}
while ( isspace ( ( int ) * string ) ) {
string ++ ;
}
if ( * string == 0 ) {
F_3 ( V_4 ) ;
}
if ( ( * string == V_8 ) &&
( tolower ( ( int ) * ( string + 1 ) ) == 'x' ) ) {
string += 2 ;
if ( * string == 0 ) {
F_3 ( V_4 ) ;
}
V_5 = 16 ;
}
else if ( V_1 & V_9 ) {
V_5 = 16 ;
}
else {
V_5 = 10 ;
}
while ( * string == V_8 ) {
string ++ ;
if ( * string == 0 ) {
F_3 ( V_4 ) ;
}
}
if ( V_5 == 16 ) {
* V_2 = F_4 ( string , V_1 ) ;
} else {
* V_2 = F_5 ( string , V_1 ) ;
}
F_3 ( V_3 ) ;
}
static T_3 F_5 ( char * string , T_2 V_1 )
{
int V_10 ;
T_3 V_11 ;
T_3 V_2 = 0 ;
while ( * string ) {
V_10 = * string ;
if ( ! isdigit ( V_10 ) ) {
goto exit;
}
V_11 =
( V_2 * 10 ) + ( V_10 - V_8 ) ;
if ( ( ( V_1 & V_12 ) && ( V_11 > V_13 ) ) || ( V_11 < V_2 ) ) {
goto exit;
}
V_2 = V_11 ;
string ++ ;
}
exit:
return ( V_2 ) ;
}
static T_3 F_4 ( char * string , T_2 V_1 )
{
int V_10 ;
T_2 V_14 = 1 ;
T_3 V_2 = 0 ;
while ( * string ) {
if ( ( V_14 > 16 ) ||
( ( V_14 > 8 ) && ( V_1 & V_12 ) ) ) {
goto exit;
}
V_10 = * string ;
if ( ! isxdigit ( V_10 ) ) {
goto exit;
}
V_2 =
( V_2 << 4 ) |
F_6 ( V_10 ) ;
string ++ ;
V_14 ++ ;
}
exit:
return ( V_2 ) ;
}
