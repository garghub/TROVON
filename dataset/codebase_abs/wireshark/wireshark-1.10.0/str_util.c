T_1 *
F_1 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; * V_2 ; V_2 ++ )
* V_2 = F_2 ( * V_2 ) ;
return ( V_1 ) ;
}
T_1 *
F_3 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; * V_2 ; V_2 ++ )
* V_2 = F_4 ( * V_2 ) ;
return ( V_1 ) ;
}
T_2
F_5 ( const T_1 * V_1 )
{
T_3 V_3 ;
for( V_3 = 0 ; V_1 [ V_3 ] != '\0' ; V_3 ++ ) {
if( ! isprint ( V_1 [ V_3 ] ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_2
F_6 ( T_4 * V_1 )
{
T_3 V_3 ;
for( V_3 = 0 ; V_1 [ V_3 ] != '\0' ; V_3 ++ ) {
if( ! isdigit ( V_1 [ V_3 ] ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_1 * F_7 ( T_5 V_4 , T_6 V_5 ) {
T_7 * V_6 = F_8 ( L_1 ) ;
int V_7 = 1000 ;
int V_8 = 0 ;
T_2 V_9 = FALSE ;
const T_1 * V_10 [] = { L_2 , L_3 , L_4 , L_5 , L_6 , L_7 , L_8 , L_9 } ;
T_1 * V_11 ;
if ( ( V_5 & V_12 ) == V_13 ) {
V_8 = 4 ;
V_7 = 1024 ;
}
if ( V_4 / V_7 / V_7 / V_7 / V_7 >= 10 ) {
F_9 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power / power / power / power, prefix[pfx_off]) ;
} else if ( V_4 / V_7 / V_7 / V_7 >= 10 ) {
F_9 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power / power / power, prefix[pfx_off+1]) ;
} else if ( V_4 / V_7 / V_7 >= 10 ) {
F_9 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power / power, prefix[pfx_off+2]) ;
} else if ( V_4 / V_7 >= 10 ) {
F_9 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_11 , size / power, prefix[pfx_off+3]) ;
} else {
F_9 (human_str, L_10 GROUP_FLAG G_GINT64_MODIFIER L_12 , size) ;
V_9 = TRUE ;
}
switch ( V_5 & V_14 ) {
case V_15 :
break;
case V_16 :
F_10 ( V_6 , V_9 ? L_13 : L_14 ) ;
break;
case V_17 :
F_10 ( V_6 , V_9 ? L_15 : L_16 ) ;
break;
case V_18 :
F_10 ( V_6 , V_9 ? L_17 : L_18 ) ;
break;
case V_19 :
F_10 ( V_6 , V_9 ? L_19 : L_20 ) ;
break;
default:
F_11 () ;
}
V_11 = V_6 -> V_1 ;
F_12 ( V_6 , FALSE ) ;
return V_11 ;
}
