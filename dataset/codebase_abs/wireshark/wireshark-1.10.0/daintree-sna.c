int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ V_5 ] ;
T_3 V_6 ;
if ( F_2 ( V_4 , V_5 , V_1 -> V_7 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_8 )
return - 1 ;
return 0 ;
}
V_6 = 0 ;
while ( V_6 < V_9 ) {
if ( V_4 [ V_6 ] != V_10 [ V_6 ] ) return 0 ;
V_6 ++ ;
}
if ( F_2 ( V_4 , V_5 , V_1 -> V_7 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_8 )
return - 1 ;
return 0 ;
}
if ( V_4 [ 0 ] != V_11 ) return 0 ;
V_1 -> V_12 = V_13 ;
V_1 -> V_14 = V_15 ;
V_1 -> V_16 = V_17 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = 0 ;
return 1 ;
}
static T_4
V_13 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_5 * V_23 )
{
char V_4 [ V_5 ] ;
T_6 V_24 ;
char V_25 [ V_26 ] ;
* V_23 = F_4 ( V_1 -> V_7 ) ;
do {
if ( F_2 ( V_4 , V_5 , V_1 -> V_7 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
} while ( V_4 [ 0 ] == V_11 );
V_1 -> V_27 . V_28 = V_29 | V_30 ;
if ( sscanf ( V_4 , L_1 V_31 L_2 V_32 L_3 ,
& V_24 , & V_1 -> V_27 . V_33 . V_34 , & V_1 -> V_27 . V_35 , V_25 ) != 4 ) {
* V_2 = V_36 ;
* V_3 = F_5 ( L_4 ) ;
return FALSE ;
}
if ( V_1 -> V_27 . V_35 <= V_37 ) {
* V_2 = V_36 ;
* V_3 = F_6 ( L_5 ,
V_37 ) ;
return FALSE ;
}
V_1 -> V_27 . V_35 -= V_37 ;
V_1 -> V_27 . V_33 . V_38 = ( V_39 ) V_24 ;
V_1 -> V_27 . V_33 . V_34 *= 1000 ;
if ( ( V_1 -> V_27 . V_40 = F_7 ( V_25 , V_2 ) ) > V_37 ) {
V_1 -> V_27 . V_40 -= V_37 ;
if ( V_1 -> V_27 . V_40 <= V_1 -> V_27 . V_35 ) {
F_8 ( V_1 -> V_41 , V_1 -> V_27 . V_40 ) ;
memcpy ( F_9 ( V_1 -> V_41 ) , V_25 , V_1 -> V_27 . V_40 ) ;
} else {
* V_2 = V_36 ;
* V_3 = F_6 ( L_6 ,
V_1 -> V_27 . V_40 , V_1 -> V_27 . V_35 ) ;
return FALSE ;
}
} else {
* V_2 = V_36 ;
* V_3 = F_5 ( L_7 ) ;
return FALSE ;
}
return TRUE ;
}
static T_4
V_15 ( T_1 * V_1 , T_5 V_42 , struct V_43 * V_27 V_44 ,
T_7 * V_45 , int V_35 , int * V_2 ,
T_2 * * V_3 )
{
char V_4 [ V_5 ] ;
T_3 V_46 ;
char V_25 [ V_26 ] ;
if( F_10 ( V_1 -> V_47 , V_42 , V_48 , V_2 ) == - 1 )
return FALSE ;
do {
if ( F_2 ( V_4 , V_5 , V_1 -> V_47 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_47 , V_3 ) ;
return FALSE ;
}
} while ( V_4 [ 0 ] == V_11 );
if ( sscanf ( V_4 , L_8 V_32 L_3 , V_25 ) != 1 ) {
* V_2 = V_36 ;
* V_3 = F_5 ( L_9 ) ;
return FALSE ;
}
if ( ( V_46 = F_7 ( V_25 , V_2 ) ) <= V_37 ) {
* V_2 = V_36 ;
* V_3 = F_5 ( L_10 ) ;
return FALSE ;
}
V_46 -= V_37 ;
if ( V_46 == ( T_3 ) V_35 ) {
memcpy ( V_45 , V_25 , V_46 ) ;
} else {
* V_2 = V_36 ;
* V_3 = F_5 ( L_11 ) ;
return FALSE ;
}
return TRUE ;
}
static T_3
F_7 ( T_8 * V_49 , int * V_2 V_44 ) {
T_3 V_50 ;
T_7 * V_51 ;
V_51 = V_49 ;
V_50 = 0 ;
while( * V_49 ) {
if ( ! isxdigit ( ( T_8 ) * V_49 ) ) return 0 ;
if( isdigit ( ( T_8 ) * V_49 ) ) {
* V_51 = ( * V_49 - '0' ) << 4 ;
} else {
* V_51 = ( ( tolower ( * V_49 ) - 'a' ) + 10 ) << 4 ;
}
V_49 ++ ;
if ( ! isxdigit ( ( T_8 ) * V_49 ) ) return 0 ;
if( isdigit ( ( T_8 ) * V_49 ) ) {
* V_51 += * V_49 - '0' ;
} else {
* V_51 += ( tolower ( * V_49 ) - 'a' ) + 10 ;
}
V_49 ++ ;
V_51 ++ ;
V_50 ++ ;
}
return V_50 ;
}
