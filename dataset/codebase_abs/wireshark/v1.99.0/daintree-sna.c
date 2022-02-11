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
char V_24 [ V_25 ] ;
* V_23 = F_4 ( V_1 -> V_7 ) ;
do {
if ( F_2 ( V_4 , V_5 , V_1 -> V_7 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_7 , V_3 ) ;
return FALSE ;
}
} while ( V_4 [ 0 ] == V_11 );
if ( ! F_5 ( & V_1 -> V_26 , V_4 , V_24 ,
V_2 , V_3 ) )
return FALSE ;
return F_6 ( & V_1 -> V_26 , V_1 -> V_27 ,
V_24 , V_2 , V_3 ) ;
}
static T_4
V_15 ( T_1 * V_1 , T_5 V_28 , struct V_29 * V_26 ,
T_6 * V_30 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ V_5 ] ;
char V_24 [ V_25 ] ;
if( F_7 ( V_1 -> V_31 , V_28 , V_32 , V_2 ) == - 1 )
return FALSE ;
do {
if ( F_2 ( V_4 , V_5 , V_1 -> V_31 ) == NULL ) {
* V_2 = F_3 ( V_1 -> V_31 , V_3 ) ;
return FALSE ;
}
} while ( V_4 [ 0 ] == V_11 );
if ( ! F_5 ( V_26 , V_4 , V_24 , V_2 , V_3 ) )
return FALSE ;
return F_6 ( V_26 , V_30 , V_24 , V_2 ,
V_3 ) ;
}
static T_4
F_5 ( struct V_29 * V_26 , char * V_4 ,
char * V_24 , int * V_2 , T_2 * * V_3 )
{
T_7 V_33 ;
int V_34 ;
V_26 -> V_35 = V_36 ;
V_26 -> V_37 = V_38 | V_39 ;
if ( sscanf ( V_4 , L_1 V_40 L_2 V_41 L_3 ,
& V_33 , & V_34 , & V_26 -> V_42 , V_24 ) != 4 ) {
* V_2 = V_43 ;
* V_3 = F_8 ( L_4 ) ;
return FALSE ;
}
if ( V_26 -> V_42 <= V_44 ) {
* V_2 = V_43 ;
* V_3 = F_9 ( L_5 ,
V_44 ) ;
return FALSE ;
}
V_26 -> V_42 -= V_44 ;
V_26 -> V_45 . V_46 = ( V_47 ) V_33 ;
V_26 -> V_45 . V_48 = V_34 * 1000 ;
return TRUE ;
}
static T_4
F_6 ( struct V_29 * V_26 , T_6 * V_30 ,
char * V_24 , int * V_2 , T_2 * * V_3 )
{
T_8 * V_49 = ( T_8 * ) V_24 ;
T_3 V_50 ;
T_9 * V_51 ;
V_51 = V_49 ;
V_50 = 0 ;
while( * V_49 ) {
if ( ! isxdigit ( ( T_8 ) * V_49 ) ) {
* V_2 = V_43 ;
* V_3 = F_8 ( L_6 ) ;
return FALSE ;
}
if( isdigit ( ( T_8 ) * V_49 ) ) {
* V_51 = ( * V_49 - '0' ) << 4 ;
} else {
* V_51 = ( ( tolower ( * V_49 ) - 'a' ) + 10 ) << 4 ;
}
V_49 ++ ;
if ( ! isxdigit ( ( T_8 ) * V_49 ) ) {
* V_2 = V_43 ;
* V_3 = F_8 ( L_6 ) ;
return FALSE ;
}
if( isdigit ( ( T_8 ) * V_49 ) ) {
* V_51 += * V_49 - '0' ;
} else {
* V_51 += ( tolower ( * V_49 ) - 'a' ) + 10 ;
}
V_49 ++ ;
V_51 ++ ;
V_50 ++ ;
}
if ( V_50 <= V_44 ) {
* V_2 = V_43 ;
* V_3 = F_9 ( L_7 ,
V_50 ) ;
return FALSE ;
}
V_50 -= V_44 ;
if ( V_50 > V_26 -> V_42 ) {
* V_2 = V_43 ;
* V_3 = F_9 ( L_8 ,
V_50 , V_26 -> V_42 ) ;
return FALSE ;
}
V_26 -> V_52 = V_50 ;
F_10 ( V_30 , V_50 ) ;
memcpy ( F_11 ( V_30 ) , V_24 , V_50 ) ;
return TRUE ;
}
