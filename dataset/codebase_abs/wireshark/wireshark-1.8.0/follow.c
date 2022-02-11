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
F_6 ( V_8 -> V_14 . V_30 ) ,
F_6 ( V_8 -> V_16 . V_30 ) ,
V_8 -> V_25 , V_8 -> V_26 ) ;
V_10 = 4 ;
V_7 = FALSE ;
}
else if( V_8 -> V_14 . type == V_17 && V_8 -> V_16 . type == V_17
&& V_8 -> V_18 == V_29 ) {
V_9 = F_5 (
L_3 ,
F_7 ( ( const struct V_31 * ) V_8 -> V_14 . V_30 ) ,
F_7 ( ( const struct V_31 * ) V_8 -> V_16 . V_30 ) ,
V_8 -> V_25 , V_8 -> V_26 ) ;
V_10 = 16 ;
V_7 = TRUE ;
}
else {
return NULL ;
}
memcpy ( V_3 [ 0 ] , V_8 -> V_14 . V_30 , V_10 ) ;
memcpy ( V_3 [ 1 ] , V_8 -> V_16 . V_30 , V_10 ) ;
V_5 [ 0 ] = V_8 -> V_25 ;
V_5 [ 1 ] = V_8 -> V_26 ;
return V_9 ;
}
T_4
F_8 ( const T_5 * V_32 , T_6 V_33 ,
const T_5 * V_34 , T_6 V_35 )
{
if ( V_32 == NULL || V_34 == NULL || V_32 -> type != V_34 -> type ||
V_33 > V_36 || V_35 > V_36 ) {
return FALSE ;
}
if ( V_37 || V_38 ) {
return FALSE ;
}
switch ( V_32 -> type ) {
default:
return FALSE ;
case V_15 :
case V_17 :
V_7 = V_32 -> type == V_17 ;
break;
}
V_37 = TRUE ;
memcpy ( V_3 [ 0 ] , V_32 -> V_30 , V_32 -> V_10 ) ;
F_9 ( & V_39 [ 0 ] , V_32 -> type , V_32 -> V_10 , V_3 [ 0 ] ) ;
V_5 [ 0 ] = V_33 ;
memcpy ( V_3 [ 1 ] , V_34 -> V_30 , V_34 -> V_10 ) ;
F_9 ( & V_39 [ 1 ] , V_34 -> type , V_34 -> V_10 , V_3 [ 1 ] ) ;
V_5 [ 1 ] = V_35 ;
return TRUE ;
}
T_4
F_10 ( T_7 V_40 )
{
if ( V_37 || V_38 ) {
return FALSE ;
}
V_38 = TRUE ;
V_28 = V_40 ;
memset ( V_3 , 0 , sizeof V_3 ) ;
V_5 [ 0 ] = V_5 [ 1 ] = 0 ;
return TRUE ;
}
void
F_11 ( T_7 V_41 , T_8 V_42 , T_8 V_43 ,
T_8 V_44 , const char * V_30 , T_8 V_45 ,
int V_46 , T_5 * V_14 , T_5 * V_16 ,
T_6 V_25 , T_6 V_47 ) {
T_9 V_48 [ V_4 ] , V_49 [ V_4 ] ;
int V_50 , V_51 , V_52 = 0 , V_10 ;
T_8 V_53 ;
T_10 * V_54 ;
T_11 V_55 ;
V_50 = - 1 ;
if ( V_37 ) {
if ( ( V_5 [ 0 ] == V_25 && V_5 [ 1 ] == V_47 &&
F_12 ( & V_39 [ 0 ] , V_14 ) &&
F_12 ( & V_39 [ 1 ] , V_16 ) )
||
( V_5 [ 1 ] == V_25 && V_5 [ 0 ] == V_47 &&
F_12 ( & V_39 [ 1 ] , V_14 ) &&
F_12 ( & V_39 [ 0 ] , V_16 ) ) ) {
V_37 = FALSE ;
V_28 = V_41 ;
}
else {
return;
}
}
else if ( V_41 != V_28 )
return;
if ( ( V_14 -> type != V_15 && V_14 -> type != V_17 ) ||
( V_16 -> type != V_15 && V_16 -> type != V_17 ) )
return;
if ( V_14 -> type == V_15 )
V_10 = 4 ;
else
V_10 = 16 ;
memcpy ( V_48 , V_14 -> V_30 , V_10 ) ;
memcpy ( V_49 , V_16 -> V_30 , V_10 ) ;
if ( V_38 ) {
V_38 = FALSE ;
memcpy ( V_3 [ 0 ] , V_14 -> V_30 , V_14 -> V_10 ) ;
V_5 [ 0 ] = V_25 ;
memcpy ( V_3 [ 1 ] , V_16 -> V_30 , V_16 -> V_10 ) ;
V_5 [ 1 ] = V_47 ;
}
for( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if ( memcmp ( V_56 [ V_51 ] , V_48 , V_10 ) == 0 && V_57 [ V_51 ] == V_25 ) {
V_50 = V_51 ;
}
}
if( V_50 < 0 ) {
for( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
if( V_57 [ V_51 ] == 0 ) {
memcpy ( V_56 [ V_51 ] , V_48 , V_10 ) ;
V_57 [ V_51 ] = V_25 ;
V_50 = V_51 ;
V_52 = 1 ;
break;
}
}
}
if( V_50 < 0 ) {
fprintf ( V_58 , L_4 ) ;
return;
}
if( V_45 < V_44 ) {
V_59 = TRUE ;
}
if( V_60 [ 1 - V_50 ] ) {
memcpy ( V_55 . V_56 , V_49 , V_10 ) ;
V_55 . V_57 = V_47 ;
V_55 . V_61 = 0 ;
while ( F_13 ( 1 - V_50 , & V_55 , V_43 ) )
;
}
memcpy ( V_55 . V_56 , V_48 , V_10 ) ;
V_55 . V_57 = V_25 ;
V_55 . V_61 = V_45 ;
if( V_52 ) {
V_62 [ V_50 ] = V_42 + V_44 ;
if( V_46 ) {
V_62 [ V_50 ] ++ ;
}
F_14 ( V_50 , & V_55 , V_30 ) ;
return;
}
if( V_42 < V_62 [ V_50 ] ) {
V_53 = V_42 + V_44 ;
if( V_53 > V_62 [ V_50 ] ) {
T_8 V_63 ;
V_63 = V_62 [ V_50 ] - V_42 ;
if ( V_45 <= V_63 ) {
V_30 = NULL ;
V_45 = 0 ;
V_59 = TRUE ;
} else {
V_30 += V_63 ;
V_45 -= V_63 ;
}
V_55 . V_61 = V_45 ;
V_42 = V_62 [ V_50 ] ;
V_44 = V_53 - V_62 [ V_50 ] ;
}
}
if ( V_42 == V_62 [ V_50 ] ) {
V_62 [ V_50 ] += V_44 ;
if( V_46 ) V_62 [ V_50 ] ++ ;
if( V_30 ) {
F_14 ( V_50 , & V_55 , V_30 ) ;
}
while( F_13 ( V_50 , & V_55 , 0 ) )
;
}
else {
if( V_45 > 0 && ( ( V_64 ) ( V_42 - V_62 [ V_50 ] ) > 0 ) ) {
V_54 = ( T_10 * ) F_15 ( sizeof( T_10 ) ) ;
V_54 -> V_30 = ( V_65 * ) F_15 ( V_45 ) ;
V_54 -> V_62 = V_42 ;
V_54 -> V_10 = V_44 ;
V_54 -> V_66 = V_45 ;
memcpy ( V_54 -> V_30 , V_30 , V_45 ) ;
if( V_60 [ V_50 ] ) {
V_54 -> V_67 = V_60 [ V_50 ] ;
} else {
V_54 -> V_67 = NULL ;
}
V_60 [ V_50 ] = V_54 ;
}
}
}
static int
F_13 ( int V_68 , T_11 * V_55 , T_8 V_69 ) {
T_10 * V_70 = NULL ;
T_10 * V_71 ;
T_8 V_72 ;
V_65 * V_73 ;
V_71 = V_60 [ V_68 ] ;
if( V_71 ) {
V_72 = V_71 -> V_62 ;
while( V_71 ) {
if( ( V_64 ) ( V_72 - V_71 -> V_62 ) > 0 ) {
V_72 = V_71 -> V_62 ;
}
if( V_71 -> V_62 < V_62 [ V_68 ] ) {
T_8 V_53 ;
V_53 = V_71 -> V_62 + V_71 -> V_10 ;
if( V_53 > V_62 [ V_68 ] ) {
T_8 V_74 ;
V_74 = V_62 [ V_68 ] - V_71 -> V_62 ;
if ( V_71 -> V_66 > V_74 ) {
V_55 -> V_61 = V_71 -> V_66 - V_74 ;
F_14 ( V_68 , V_55 , V_71 -> V_30 + V_74 ) ;
}
V_62 [ V_68 ] += ( V_71 -> V_10 - V_74 ) ;
}
if( V_70 ) {
V_70 -> V_67 = V_71 -> V_67 ;
} else {
V_60 [ V_68 ] = V_71 -> V_67 ;
}
F_16 ( V_71 -> V_30 ) ;
F_16 ( V_71 ) ;
return 1 ;
}
if( V_71 -> V_62 == V_62 [ V_68 ] ) {
if( V_71 -> V_30 ) {
V_55 -> V_61 = V_71 -> V_66 ;
F_14 ( V_68 , V_55 , V_71 -> V_30 ) ;
}
V_62 [ V_68 ] += V_71 -> V_10 ;
if( V_70 ) {
V_70 -> V_67 = V_71 -> V_67 ;
} else {
V_60 [ V_68 ] = V_71 -> V_67 ;
}
F_16 ( V_71 -> V_30 ) ;
F_16 ( V_71 ) ;
return 1 ;
}
V_70 = V_71 ;
V_71 = V_71 -> V_67 ;
}
if( ( V_64 ) ( V_69 - V_72 ) > 0 ) {
V_73 = F_5 ( L_5 ,
( int ) ( V_72 - V_62 [ V_68 ] ) ) ;
V_55 -> V_61 = ( T_7 ) strlen ( V_73 ) ;
F_14 ( V_68 , V_55 , V_73 ) ;
F_16 ( V_73 ) ;
V_62 [ V_68 ] = V_72 ;
return 1 ;
}
}
return 0 ;
}
void
F_17 ( void )
{
T_10 * V_71 , * V_67 ;
int V_2 ;
V_75 = TRUE ;
V_59 = FALSE ;
V_38 = FALSE ;
V_37 = FALSE ;
for( V_2 = 0 ; V_2 < 2 ; V_2 ++ ) {
V_62 [ V_2 ] = 0 ;
memset ( V_56 [ V_2 ] , '\0' , V_4 ) ;
V_57 [ V_2 ] = 0 ;
memset ( V_3 [ V_2 ] , '\0' , V_4 ) ;
V_5 [ V_2 ] = 0 ;
V_6 [ V_2 ] = 0 ;
V_71 = V_60 [ V_2 ] ;
while( V_71 ) {
V_67 = V_71 -> V_67 ;
F_16 ( V_71 -> V_30 ) ;
F_16 ( V_71 ) ;
V_71 = V_67 ;
}
V_60 [ V_2 ] = NULL ;
}
}
static void
F_14 ( int V_68 , T_11 * V_55 , const char * V_30 )
{
T_12 V_76 ;
V_76 = fwrite ( V_55 , 1 , sizeof( T_11 ) , V_77 ) ;
F_18 ( sizeof( T_11 ) == V_76 ) ;
V_76 = fwrite ( V_30 , 1 , V_55 -> V_61 , V_77 ) ;
F_18 ( V_55 -> V_61 == V_76 ) ;
V_6 [ V_68 ] += V_55 -> V_61 ;
V_75 = FALSE ;
}
