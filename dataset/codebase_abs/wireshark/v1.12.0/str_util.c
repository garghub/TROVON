int
F_1 ( char V_1 )
{
switch ( V_1 ) {
case '0' : return 0 ;
case '1' : return 1 ;
case '2' : return 2 ;
case '3' : return 3 ;
case '4' : return 4 ;
case '5' : return 5 ;
case '6' : return 6 ;
case '7' : return 7 ;
case '8' : return 8 ;
case '9' : return 9 ;
case 'a' : case 'A' : return 10 ;
case 'b' : case 'B' : return 11 ;
case 'c' : case 'C' : return 12 ;
case 'd' : case 'D' : return 13 ;
case 'e' : case 'E' : return 14 ;
case 'f' : case 'F' : return 15 ;
default: return - 1 ;
}
}
T_1 *
F_2 ( T_1 * V_2 )
{
T_1 * V_3 ;
for ( V_3 = V_2 ; * V_3 ; V_3 ++ )
* V_3 = F_3 ( * V_3 ) ? * V_3 - 'A' + 'a' : * V_3 ;
return ( V_2 ) ;
}
T_1 *
F_4 ( T_1 * V_2 )
{
T_1 * V_3 ;
for ( V_3 = V_2 ; * V_3 ; V_3 ++ )
* V_3 = F_5 ( * V_3 ) ? * V_3 - 'a' + 'A' : * V_3 ;
return ( V_2 ) ;
}
T_2
F_6 ( const T_1 * V_2 )
{
T_3 V_4 ;
for( V_4 = 0 ; V_2 [ V_4 ] != '\0' ; V_4 ++ ) {
if( ! F_7 ( V_2 [ V_4 ] ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_2
F_8 ( T_4 * V_2 )
{
T_3 V_4 ;
for( V_4 = 0 ; V_2 [ V_4 ] != '\0' ; V_4 ++ ) {
if( ! isdigit ( V_2 [ V_4 ] ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_1 * F_9 ( T_5 V_5 , T_6 V_6 ) {
T_7 * V_7 = F_10 ( L_1 ) ;
int V_8 = 1000 ;
int V_9 = 0 ;
T_2 V_10 = FALSE ;
static const T_1 * V_11 [] = { L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 } ;
T_1 * V_12 ;
if ( ( V_6 & V_13 ) == V_14 ) {
V_9 = 4 ;
V_8 = 1024 ;
}
if ( V_5 / V_8 / V_8 / V_8 / V_8 >= 10 ) {
F_11 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power / power / power / power, prefix[pfx_off]) ;
} else if ( V_5 / V_8 / V_8 / V_8 >= 10 ) {
F_11 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power / power / power, prefix[pfx_off+1]) ;
} else if ( V_5 / V_8 / V_8 >= 10 ) {
F_11 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power / power, prefix[pfx_off+2]) ;
} else if ( V_5 / V_8 >= 10 ) {
F_11 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power, prefix[pfx_off+3]) ;
} else {
F_11 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_12 , size) ;
V_10 = TRUE ;
}
switch ( V_6 & V_15 ) {
case V_16 :
break;
case V_17 :
F_12 ( V_7 , V_10 ? L_13 : L_14 ) ;
break;
case V_18 :
F_12 ( V_7 , V_10 ? L_15 : L_16 ) ;
break;
case V_19 :
F_12 ( V_7 , V_10 ? L_17 : L_18 ) ;
break;
case V_20 :
F_12 ( V_7 , V_10 ? L_19 : L_20 ) ;
break;
default:
F_13 () ;
}
V_12 = V_7 -> V_2 ;
F_14 ( V_7 , FALSE ) ;
return V_12 ;
}
