int F_1 ( T_1 * V_1 , int * T_2 V_2 , T_3 * * T_4 V_2 )
{
char V_3 [ V_4 ] ;
T_5 V_5 ;
if ( F_2 ( V_3 , V_4 , V_1 -> V_6 ) == NULL ) return 0 ;
V_5 = 0 ;
while ( V_5 < V_7 ) {
if ( V_3 [ V_5 ] != V_8 [ V_5 ] ) return 0 ;
V_5 ++ ;
}
if ( F_2 ( V_3 , V_4 , V_1 -> V_6 ) == NULL ) return 0 ;
if ( V_3 [ 0 ] != V_9 ) return 0 ;
V_1 -> V_10 = V_11 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = 0 ;
return 1 ;
}
static T_6
V_11 ( T_1 * V_1 , int * T_2 , T_3 * * T_4 , T_7 * V_21 )
{
char V_3 [ V_4 ] ;
T_8 V_22 ;
char V_23 [ V_24 ] ;
* V_21 = F_3 ( V_1 -> V_6 ) ;
do {
if ( F_2 ( V_3 , V_4 , V_1 -> V_6 ) == NULL ) {
* T_2 = F_4 ( V_1 -> V_6 , T_4 ) ;
return FALSE ;
}
} while ( V_3 [ 0 ] == V_9 );
V_1 -> V_25 . V_26 = V_27 | V_28 ;
if ( sscanf ( V_3 , L_1 V_29 L_2 V_30 L_3 ,
& V_22 , & V_1 -> V_25 . V_31 . V_32 , & V_1 -> V_25 . V_33 , V_23 ) != 4 ) {
* T_2 = V_34 ;
* T_4 = F_5 ( L_4 ) ;
return FALSE ;
}
if ( V_1 -> V_25 . V_33 <= V_35 ) {
* T_2 = V_34 ;
* T_4 = F_6 ( L_5 ,
V_35 ) ;
return FALSE ;
}
V_1 -> V_25 . V_33 -= V_35 ;
V_1 -> V_25 . V_31 . V_36 = ( V_37 ) V_22 ;
V_1 -> V_25 . V_31 . V_32 *= 1000 ;
if ( ( V_1 -> V_25 . V_38 = F_7 ( V_23 , T_2 ) ) > V_35 ) {
V_1 -> V_25 . V_38 -= V_35 ;
if ( V_1 -> V_25 . V_38 <= V_1 -> V_25 . V_33 ) {
F_8 ( V_1 -> V_39 , V_1 -> V_25 . V_38 ) ;
memcpy ( F_9 ( V_1 -> V_39 ) , V_23 , V_1 -> V_25 . V_38 ) ;
} else {
* T_2 = V_34 ;
* T_4 = F_6 ( L_6 ,
V_1 -> V_25 . V_38 , V_1 -> V_25 . V_33 ) ;
return FALSE ;
}
} else {
* T_2 = V_34 ;
* T_4 = F_5 ( L_7 ) ;
return FALSE ;
}
return TRUE ;
}
static T_6
V_13 ( T_1 * V_1 , T_7 V_40 , union V_41
* T_9 V_2 , T_10 * V_42 , int V_33 , int * T_2 ,
T_3 * * T_4 )
{
char V_3 [ V_4 ] ;
T_5 V_43 ;
char V_23 [ V_24 ] ;
if( F_10 ( V_1 -> V_44 , V_40 , V_45 , T_2 ) == - 1 )
return FALSE ;
do {
if ( F_2 ( V_3 , V_4 , V_1 -> V_44 ) == NULL ) {
* T_2 = F_4 ( V_1 -> V_44 , T_4 ) ;
return FALSE ;
}
} while ( V_3 [ 0 ] == V_9 );
if ( sscanf ( V_3 , L_8 V_30 L_3 , V_23 ) != 1 ) {
* T_2 = V_34 ;
* T_4 = F_5 ( L_9 ) ;
return FALSE ;
}
if ( ( V_43 = F_7 ( V_23 , T_2 ) ) <= V_35 ) {
* T_2 = V_34 ;
* T_4 = F_5 ( L_10 ) ;
return FALSE ;
}
V_43 -= V_35 ;
if ( V_43 == ( T_5 ) V_33 ) {
memcpy ( V_42 , V_23 , V_43 ) ;
} else {
* T_2 = V_34 ;
* T_4 = F_5 ( L_11 ) ;
return FALSE ;
}
return TRUE ;
}
static T_5
F_7 ( T_11 * V_46 , int * T_2 V_2 ) {
T_5 V_47 ;
T_10 * V_48 ;
V_48 = V_46 ;
V_47 = 0 ;
while( * V_46 ) {
if ( ! isxdigit ( ( T_11 ) * V_46 ) ) return 0 ;
if( isdigit ( ( T_11 ) * V_46 ) ) {
* V_48 = ( * V_46 - '0' ) << 4 ;
} else {
* V_48 = ( ( tolower ( * V_46 ) - 'a' ) + 10 ) << 4 ;
}
V_46 ++ ;
if ( ! isxdigit ( ( T_11 ) * V_46 ) ) return 0 ;
if( isdigit ( ( T_11 ) * V_46 ) ) {
* V_48 += * V_46 - '0' ;
} else {
* V_48 += ( tolower ( * V_46 ) - 'a' ) + 10 ;
}
V_46 ++ ;
V_48 ++ ;
V_47 ++ ;
}
return V_47 ;
}
