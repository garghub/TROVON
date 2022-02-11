void
F_1 ( T_1 * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 2 ; V_2 ++ ) {
memcpy ( V_1 -> V_3 [ V_2 ] , V_3 [ V_2 ] , V_4 ) ;
V_1 -> V_5 [ V_2 ] = V_5 [ V_2 ] ;
V_1 -> V_6 [ V_2 ] = V_6 [ V_2 ] ;
V_1 -> V_7 = V_7 ;
}
}
char *
F_2 ( T_2 * V_8 ) {
char * V_9 ;
int V_10 ;
T_3 * V_11 = NULL ;
struct V_12 * V_13 ;
if( ( ( V_8 -> V_14 . type == V_15 && V_8 -> V_16 . type == V_15 ) ||
( V_8 -> V_14 . type == V_17 && V_8 -> V_16 . type == V_17 ) )
&& V_8 -> V_18 == V_19
&& ( V_11 = F_3 ( V_8 -> V_20 -> V_21 , & V_8 -> V_22 , & V_8 -> V_23 , V_8 -> V_24 ,
V_8 -> V_25 , V_8 -> V_26 , 0 ) ) != NULL ) {
V_13 = F_4 ( V_11 , V_8 ) ;
if ( V_13 ) {
V_9 = F_5 ( L_1 , V_13 -> V_27 ) ;
V_28 = V_13 -> V_27 ;
if ( V_8 -> V_14 . type == V_15 ) {
V_10 = 4 ;
V_7 = FALSE ;
} else {
V_10 = 16 ;
V_7 = TRUE ;
}
} else {
return NULL ;
}
}
else if( V_8 -> V_14 . type == V_15 && V_8 -> V_16 . type == V_15
&& V_8 -> V_18 == V_29 ) {
V_9 = F_5 (
L_2 ,
F_6 ( ( V_30 * ) V_8 -> V_14 . V_31 ) ,
F_6 ( ( V_30 * ) V_8 -> V_16 . V_31 ) ,
V_8 -> V_25 , V_8 -> V_26 ) ;
V_10 = 4 ;
V_7 = FALSE ;
}
else if( V_8 -> V_14 . type == V_17 && V_8 -> V_16 . type == V_17
&& V_8 -> V_18 == V_29 ) {
V_9 = F_5 (
L_3 ,
F_7 ( ( const struct V_32 * ) V_8 -> V_14 . V_31 ) ,
F_7 ( ( const struct V_32 * ) V_8 -> V_16 . V_31 ) ,
V_8 -> V_25 , V_8 -> V_26 ) ;
V_10 = 16 ;
V_7 = TRUE ;
}
else {
return NULL ;
}
memcpy ( V_3 [ 0 ] , V_8 -> V_14 . V_31 , V_10 ) ;
memcpy ( V_3 [ 1 ] , V_8 -> V_16 . V_31 , V_10 ) ;
V_5 [ 0 ] = V_8 -> V_25 ;
V_5 [ 1 ] = V_8 -> V_26 ;
return V_9 ;
}
T_4
F_8 ( const T_5 * V_33 , T_6 V_34 ,
const T_5 * V_35 , T_6 V_36 )
{
if ( V_33 == NULL || V_35 == NULL || V_33 -> type != V_35 -> type ||
V_34 > V_37 || V_36 > V_37 ) {
return FALSE ;
}
if ( V_38 || V_39 ) {
return FALSE ;
}
switch ( V_33 -> type ) {
default:
return FALSE ;
case V_15 :
case V_17 :
V_7 = V_33 -> type == V_17 ;
break;
}
V_38 = TRUE ;
memcpy ( V_3 [ 0 ] , V_33 -> V_31 , V_33 -> V_10 ) ;
F_9 ( & V_40 [ 0 ] , V_33 -> type , V_33 -> V_10 , V_3 [ 0 ] ) ;
V_5 [ 0 ] = V_34 ;
memcpy ( V_3 [ 1 ] , V_35 -> V_31 , V_35 -> V_10 ) ;
F_9 ( & V_40 [ 1 ] , V_35 -> type , V_35 -> V_10 , V_3 [ 1 ] ) ;
V_5 [ 1 ] = V_36 ;
return TRUE ;
}
T_4
F_10 ( T_7 V_41 )
{
if ( V_38 || V_39 ) {
return FALSE ;
}
V_39 = TRUE ;
V_28 = V_41 ;
memset ( V_3 , 0 , sizeof V_3 ) ;
V_5 [ 0 ] = V_5 [ 1 ] = 0 ;
return TRUE ;
}
void
F_11 ( T_7 V_42 , T_7 V_43 , T_7 V_44 ,
T_7 V_45 , const char * V_31 , T_7 V_46 ,
int V_47 , T_5 * V_14 , T_5 * V_16 ,
T_6 V_25 , T_6 V_48 ) {
V_30 V_49 [ V_4 ] , V_50 [ V_4 ] ;
int V_51 , V_52 , V_53 = 0 , V_10 ;
T_7 V_54 ;
T_8 * V_55 ;
T_9 V_56 ;
V_51 = - 1 ;
if ( V_38 ) {
if ( ( V_5 [ 0 ] == V_25 && V_5 [ 1 ] == V_48 &&
F_12 ( & V_40 [ 0 ] , V_14 ) &&
F_12 ( & V_40 [ 1 ] , V_16 ) )
||
( V_5 [ 1 ] == V_25 && V_5 [ 0 ] == V_48 &&
F_12 ( & V_40 [ 1 ] , V_14 ) &&
F_12 ( & V_40 [ 0 ] , V_16 ) ) ) {
V_38 = FALSE ;
V_28 = V_42 ;
}
else {
return;
}
}
else if ( V_42 != V_28 )
return;
if ( ( V_14 -> type != V_15 && V_14 -> type != V_17 ) ||
( V_16 -> type != V_15 && V_16 -> type != V_17 ) )
return;
if ( V_14 -> type == V_15 )
V_10 = 4 ;
else
V_10 = 16 ;
memcpy ( V_49 , V_14 -> V_31 , V_10 ) ;
memcpy ( V_50 , V_16 -> V_31 , V_10 ) ;
if ( V_39 ) {
V_39 = FALSE ;
memcpy ( V_3 [ 0 ] , V_14 -> V_31 , V_14 -> V_10 ) ;
V_5 [ 0 ] = V_25 ;
memcpy ( V_3 [ 1 ] , V_16 -> V_31 , V_16 -> V_10 ) ;
V_5 [ 1 ] = V_48 ;
}
for( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
if ( memcmp ( V_57 [ V_52 ] , V_49 , V_10 ) == 0 && V_58 [ V_52 ] == V_25 ) {
V_51 = V_52 ;
}
}
if( V_51 < 0 ) {
for( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
if( V_58 [ V_52 ] == 0 ) {
memcpy ( V_57 [ V_52 ] , V_49 , V_10 ) ;
V_58 [ V_52 ] = V_25 ;
V_51 = V_52 ;
V_53 = 1 ;
break;
}
}
}
if( V_51 < 0 ) {
fprintf ( V_59 , L_4 ) ;
return;
}
if( V_46 < V_45 ) {
V_60 = TRUE ;
}
if( V_61 [ 1 - V_51 ] ) {
memcpy ( V_56 . V_57 , V_50 , V_10 ) ;
V_56 . V_58 = V_48 ;
V_56 . V_62 = 0 ;
while ( F_13 ( 1 - V_51 , & V_56 , V_44 ) )
;
}
memcpy ( V_56 . V_57 , V_49 , V_10 ) ;
V_56 . V_58 = V_25 ;
V_56 . V_62 = V_46 ;
if( V_53 ) {
V_63 [ V_51 ] = V_43 + V_45 ;
if( V_47 ) {
V_63 [ V_51 ] ++ ;
}
F_14 ( V_51 , & V_56 , V_31 ) ;
return;
}
if( V_43 < V_63 [ V_51 ] ) {
V_54 = V_43 + V_45 ;
if( V_54 > V_63 [ V_51 ] ) {
T_7 V_64 ;
V_64 = V_63 [ V_51 ] - V_43 ;
if ( V_46 <= V_64 ) {
V_31 = NULL ;
V_46 = 0 ;
V_60 = TRUE ;
} else {
V_31 += V_64 ;
V_46 -= V_64 ;
}
V_56 . V_62 = V_46 ;
V_43 = V_63 [ V_51 ] ;
V_45 = V_54 - V_63 [ V_51 ] ;
}
}
if ( V_43 == V_63 [ V_51 ] ) {
V_63 [ V_51 ] += V_45 ;
if( V_47 ) V_63 [ V_51 ] ++ ;
if( V_31 ) {
F_14 ( V_51 , & V_56 , V_31 ) ;
}
while( F_13 ( V_51 , & V_56 , 0 ) )
;
}
else {
if( V_46 > 0 && ( ( V_65 ) ( V_43 - V_63 [ V_51 ] ) > 0 ) ) {
V_55 = ( T_8 * ) F_15 ( sizeof( T_8 ) ) ;
V_55 -> V_31 = ( V_66 * ) F_15 ( V_46 ) ;
V_55 -> V_63 = V_43 ;
V_55 -> V_10 = V_45 ;
V_55 -> V_67 = V_46 ;
memcpy ( V_55 -> V_31 , V_31 , V_46 ) ;
if( V_61 [ V_51 ] ) {
V_55 -> V_68 = V_61 [ V_51 ] ;
} else {
V_55 -> V_68 = NULL ;
}
V_61 [ V_51 ] = V_55 ;
}
}
}
static int
F_13 ( int V_69 , T_9 * V_56 , T_7 V_70 ) {
T_8 * V_71 = NULL ;
T_8 * V_72 ;
T_7 V_73 ;
V_66 * V_74 ;
V_72 = V_61 [ V_69 ] ;
if( V_72 ) {
V_73 = V_72 -> V_63 ;
while( V_72 ) {
if( ( V_65 ) ( V_73 - V_72 -> V_63 ) > 0 ) {
V_73 = V_72 -> V_63 ;
}
if( V_72 -> V_63 < V_63 [ V_69 ] ) {
T_7 V_54 ;
V_54 = V_72 -> V_63 + V_72 -> V_10 ;
if( V_54 > V_63 [ V_69 ] ) {
T_7 V_75 ;
V_75 = V_63 [ V_69 ] - V_72 -> V_63 ;
if ( V_72 -> V_67 > V_75 ) {
V_56 -> V_62 = V_72 -> V_67 - V_75 ;
F_14 ( V_69 , V_56 , V_72 -> V_31 + V_75 ) ;
}
V_63 [ V_69 ] += ( V_72 -> V_10 - V_75 ) ;
}
if( V_71 ) {
V_71 -> V_68 = V_72 -> V_68 ;
} else {
V_61 [ V_69 ] = V_72 -> V_68 ;
}
F_16 ( V_72 -> V_31 ) ;
F_16 ( V_72 ) ;
return 1 ;
}
if( V_72 -> V_63 == V_63 [ V_69 ] ) {
if( V_72 -> V_31 ) {
V_56 -> V_62 = V_72 -> V_67 ;
F_14 ( V_69 , V_56 , V_72 -> V_31 ) ;
}
V_63 [ V_69 ] += V_72 -> V_10 ;
if( V_71 ) {
V_71 -> V_68 = V_72 -> V_68 ;
} else {
V_61 [ V_69 ] = V_72 -> V_68 ;
}
F_16 ( V_72 -> V_31 ) ;
F_16 ( V_72 ) ;
return 1 ;
}
V_71 = V_72 ;
V_72 = V_72 -> V_68 ;
}
if( ( V_65 ) ( V_70 - V_73 ) > 0 ) {
V_74 = F_5 ( L_5 ,
( int ) ( V_73 - V_63 [ V_69 ] ) ) ;
V_56 -> V_62 = ( T_7 ) strlen ( V_74 ) ;
F_14 ( V_69 , V_56 , V_74 ) ;
F_16 ( V_74 ) ;
V_63 [ V_69 ] = V_73 ;
return 1 ;
}
}
return 0 ;
}
void
F_17 ( void )
{
T_8 * V_72 , * V_68 ;
int V_2 ;
V_76 = TRUE ;
V_60 = FALSE ;
V_39 = FALSE ;
V_38 = FALSE ;
for( V_2 = 0 ; V_2 < 2 ; V_2 ++ ) {
V_63 [ V_2 ] = 0 ;
memset ( V_57 [ V_2 ] , '\0' , V_4 ) ;
V_58 [ V_2 ] = 0 ;
memset ( V_3 [ V_2 ] , '\0' , V_4 ) ;
V_5 [ V_2 ] = 0 ;
V_6 [ V_2 ] = 0 ;
V_72 = V_61 [ V_2 ] ;
while( V_72 ) {
V_68 = V_72 -> V_68 ;
F_16 ( V_72 -> V_31 ) ;
F_16 ( V_72 ) ;
V_72 = V_68 ;
}
V_61 [ V_2 ] = NULL ;
}
}
static void
F_14 ( int V_69 , T_9 * V_56 , const char * V_31 )
{
T_10 V_77 ;
V_77 = fwrite ( V_56 , 1 , sizeof( T_9 ) , V_78 ) ;
F_18 ( sizeof( T_9 ) == V_77 ) ;
V_77 = fwrite ( V_31 , 1 , V_56 -> V_62 , V_78 ) ;
F_18 ( V_56 -> V_62 == V_77 ) ;
V_6 [ V_69 ] += V_56 -> V_62 ;
V_76 = FALSE ;
}
