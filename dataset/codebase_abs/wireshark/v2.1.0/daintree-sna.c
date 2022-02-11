T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ V_5 ] ;
if ( F_2 ( V_4 , V_5 , V_1 -> V_6 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_6 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_7 )
return V_8 ;
return V_9 ;
}
if ( memcmp ( V_4 , V_10 , V_11 ) != 0 )
return V_9 ;
if ( F_2 ( V_4 , V_5 , V_1 -> V_6 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_6 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_7 )
return V_8 ;
return V_9 ;
}
if ( V_4 [ 0 ] != V_12 )
return V_9 ;
V_1 -> V_13 = V_14 ;
V_1 -> V_15 = V_16 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
return V_24 ;
}
static T_4
V_14 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 , T_5 * V_25 )
{
* V_25 = F_4 ( V_1 -> V_6 ) ;
return F_5 ( V_1 -> V_6 , & V_1 -> V_26 ,
V_1 -> V_27 , V_2 , V_3 ) ;
}
static T_4
V_16 ( T_2 * V_1 , T_5 V_28 , struct V_29 * V_26 ,
T_6 * V_30 , int * V_2 , T_3 * * V_3 )
{
if( F_6 ( V_1 -> V_31 , V_28 , V_32 , V_2 ) == - 1 )
return FALSE ;
return F_5 ( V_1 -> V_31 , V_26 , V_30 , V_2 ,
V_3 ) ;
}
static T_4
F_5 ( T_7 V_6 , struct V_29 * V_26 , T_6 * V_30 ,
int * V_2 , T_3 * * V_3 )
{
T_8 V_33 ;
int V_34 ;
char V_4 [ V_5 ] ;
char V_35 [ V_36 ] ;
T_9 * V_37 = ( T_9 * ) V_35 ;
T_10 V_38 ;
T_11 * V_39 ;
do {
if ( F_2 ( V_4 , V_5 , V_6 ) == NULL ) {
* V_2 = F_3 ( V_6 , V_3 ) ;
return FALSE ;
}
} while ( V_4 [ 0 ] == V_12 );
V_26 -> V_40 = V_41 ;
V_26 -> V_42 = V_43 | V_44 ;
if ( sscanf ( V_4 , L_1 V_45 L_2 V_46 L_3 ,
& V_33 , & V_34 , & V_26 -> V_47 , V_35 ) != 4 ) {
* V_2 = V_48 ;
* V_3 = F_7 ( L_4 ) ;
return FALSE ;
}
if ( V_26 -> V_47 <= V_49 ) {
* V_2 = V_48 ;
* V_3 = F_8 ( L_5 ,
V_49 ) ;
return FALSE ;
}
V_26 -> V_47 -= V_49 ;
V_26 -> V_50 . V_51 = ( V_52 ) V_33 ;
V_26 -> V_50 . V_53 = V_34 * 1000 ;
V_39 = V_37 ;
V_38 = 0 ;
while( * V_37 ) {
if ( ! F_9 ( * V_37 ) ) {
* V_2 = V_48 ;
* V_3 = F_7 ( L_6 ) ;
return FALSE ;
}
if( F_10 ( * V_37 ) ) {
* V_39 = ( * V_37 - '0' ) << 4 ;
} else {
* V_39 = ( ( F_11 ( * V_37 ) - 'a' ) + 10 ) << 4 ;
}
V_37 ++ ;
if ( ! F_9 ( * V_37 ) ) {
* V_2 = V_48 ;
* V_3 = F_7 ( L_6 ) ;
return FALSE ;
}
if( F_10 ( * V_37 ) ) {
* V_39 += * V_37 - '0' ;
} else {
* V_39 += ( F_11 ( * V_37 ) - 'a' ) + 10 ;
}
V_37 ++ ;
V_39 ++ ;
V_38 ++ ;
}
if ( V_38 <= V_49 ) {
* V_2 = V_48 ;
* V_3 = F_8 ( L_7 ,
V_38 ) ;
return FALSE ;
}
V_38 -= V_49 ;
if ( V_38 > V_26 -> V_47 ) {
* V_2 = V_48 ;
* V_3 = F_8 ( L_8 ,
V_38 , V_26 -> V_47 ) ;
return FALSE ;
}
V_26 -> V_54 = V_38 ;
F_12 ( V_30 , V_38 ) ;
memcpy ( F_13 ( V_30 ) , V_35 , V_38 ) ;
return TRUE ;
}
