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
char V_4 [ V_5 ] ;
char V_26 [ V_27 ] ;
* V_25 = F_4 ( V_1 -> V_6 ) ;
do {
if ( F_2 ( V_4 , V_5 , V_1 -> V_6 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_6 , V_3 ) ;
return FALSE ;
}
} while ( V_4 [ 0 ] == V_12 );
if ( ! F_5 ( & V_1 -> V_28 , V_4 , V_26 ,
V_2 , V_3 ) )
return FALSE ;
return F_6 ( & V_1 -> V_28 , V_1 -> V_29 ,
V_26 , V_2 , V_3 ) ;
}
static T_4
V_16 ( T_2 * V_1 , T_5 V_30 , struct V_31 * V_28 ,
T_6 * V_32 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ V_5 ] ;
char V_26 [ V_27 ] ;
if( F_7 ( V_1 -> V_33 , V_30 , V_34 , V_2 ) == - 1 )
return FALSE ;
do {
if ( F_2 ( V_4 , V_5 , V_1 -> V_33 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_33 , V_3 ) ;
return FALSE ;
}
} while ( V_4 [ 0 ] == V_12 );
if ( ! F_5 ( V_28 , V_4 , V_26 , V_2 , V_3 ) )
return FALSE ;
return F_6 ( V_28 , V_32 , V_26 , V_2 ,
V_3 ) ;
}
static T_4
F_5 ( struct V_31 * V_28 , char * V_4 ,
char * V_26 , int * V_2 , T_3 * * V_3 )
{
T_7 V_35 ;
int V_36 ;
V_28 -> V_37 = V_38 ;
V_28 -> V_39 = V_40 | V_41 ;
if ( sscanf ( V_4 , L_1 V_42 L_2 V_43 L_3 ,
& V_35 , & V_36 , & V_28 -> V_44 , V_26 ) != 4 ) {
* V_2 = V_45 ;
* V_3 = F_8 ( L_4 ) ;
return FALSE ;
}
if ( V_28 -> V_44 <= V_46 ) {
* V_2 = V_45 ;
* V_3 = F_9 ( L_5 ,
V_46 ) ;
return FALSE ;
}
V_28 -> V_44 -= V_46 ;
V_28 -> V_47 . V_48 = ( V_49 ) V_35 ;
V_28 -> V_47 . V_50 = V_36 * 1000 ;
return TRUE ;
}
static T_4
F_6 ( struct V_31 * V_28 , T_6 * V_32 ,
char * V_26 , int * V_2 , T_3 * * V_3 )
{
T_8 * V_51 = ( T_8 * ) V_26 ;
T_9 V_52 ;
T_10 * V_53 ;
V_53 = V_51 ;
V_52 = 0 ;
while( * V_51 ) {
if ( ! F_10 ( * V_51 ) ) {
* V_2 = V_45 ;
* V_3 = F_8 ( L_6 ) ;
return FALSE ;
}
if( F_11 ( * V_51 ) ) {
* V_53 = ( * V_51 - '0' ) << 4 ;
} else {
* V_53 = ( ( F_12 ( * V_51 ) - 'a' ) + 10 ) << 4 ;
}
V_51 ++ ;
if ( ! F_10 ( * V_51 ) ) {
* V_2 = V_45 ;
* V_3 = F_8 ( L_6 ) ;
return FALSE ;
}
if( F_11 ( * V_51 ) ) {
* V_53 += * V_51 - '0' ;
} else {
* V_53 += ( F_12 ( * V_51 ) - 'a' ) + 10 ;
}
V_51 ++ ;
V_53 ++ ;
V_52 ++ ;
}
if ( V_52 <= V_46 ) {
* V_2 = V_45 ;
* V_3 = F_9 ( L_7 ,
V_52 ) ;
return FALSE ;
}
V_52 -= V_46 ;
if ( V_52 > V_28 -> V_44 ) {
* V_2 = V_45 ;
* V_3 = F_9 ( L_8 ,
V_52 , V_28 -> V_44 ) ;
return FALSE ;
}
V_28 -> V_54 = V_52 ;
F_13 ( V_32 , V_52 ) ;
memcpy ( F_14 ( V_32 ) , V_26 , V_52 ) ;
return TRUE ;
}
