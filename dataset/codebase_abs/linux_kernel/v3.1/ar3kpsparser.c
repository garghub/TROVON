char F_1 ( T_1 * V_1 , T_2 V_2 , T_2 * V_3 )
{
char V_4 ;
if( V_1 == NULL || * V_3 >= V_2 )
{
return '\0' ;
} else {
V_4 = V_1 [ * V_3 ] ;
( * V_3 ) ++ ;
return V_4 ;
}
}
unsigned int F_2 ( char * V_5 , struct V_6 * V_7 )
{
if( V_5 [ 0 ] != '[' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
return 0 ;
}
switch( V_5 [ 1 ] ) {
case 'H' :
case 'h' :
if( V_5 [ 2 ] == ':' ) {
if( ( V_5 [ 3 ] == 'a' ) || ( V_5 [ 3 ] == 'A' ) ) {
if( V_5 [ 4 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 5 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_1 ) ) ;
return 1 ;
}
}
if( ( V_5 [ 3 ] == 'S' ) || ( V_5 [ 3 ] == 's' ) ) {
if( V_5 [ 4 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = false ;
V_5 += 5 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_1 ) ) ;
return 1 ;
}
}
else if( V_5 [ 3 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 4 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_1 ) ) ;
return 1 ;
}
}
else if( V_5 [ 2 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 3 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_1 ) ) ;
return 1 ;
}
break;
case 'A' :
case 'a' :
if( V_5 [ 2 ] == ':' ) {
if( ( V_5 [ 3 ] == 'h' ) || ( V_5 [ 3 ] == 'H' ) ) {
if( V_5 [ 4 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 5 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_2 ) ) ;
return 1 ;
}
}
else if( V_5 [ 3 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 4 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_3 ) ) ;
return 1 ;
}
}
else if( V_5 [ 2 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 3 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_4 ) ) ;
return 1 ;
}
break;
case 'S' :
case 's' :
if( V_5 [ 2 ] == ':' ) {
if( ( V_5 [ 3 ] == 'h' ) || ( V_5 [ 3 ] == 'H' ) ) {
if( V_5 [ 4 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 5 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_5 ) ) ;
return 1 ;
}
}
else if( V_5 [ 3 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 4 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_6 ) ) ;
return 1 ;
}
}
else if( V_5 [ 2 ] == ']' ) {
V_7 -> V_8 = V_9 ;
V_7 -> V_10 = true ;
V_5 += 3 ;
return 0 ;
}
else {
F_3 ( V_11 , ( L_7 ) ) ;
return 1 ;
}
break;
default:
F_3 ( V_11 , ( L_8 ) ) ;
return 1 ;
}
}
unsigned int F_4 ( char * V_5 , struct V_6 V_12 )
{
char * V_13 = V_5 ;
if( V_13 [ 0 ] == '[' ) {
while( V_13 [ 0 ] != ']' && V_13 [ 0 ] != '\0' ) {
V_13 ++ ;
}
if( V_13 [ 0 ] == '\0' ) {
return ( 0x0FFF ) ;
}
V_13 ++ ;
}
if( V_12 . V_8 == V_9 ) {
if( V_12 . V_10 == true ) {
return ( 0x0FFF ) ;
}
else {
return ( F_5 ( V_13 , NULL , 16 ) ) ;
}
}
else {
return ( 0x0FFF ) ;
}
}
int F_6 ( T_1 * V_14 , T_2 V_15 , int V_16 )
{
char * V_17 ;
char * V_5 ;
T_1 V_18 ;
T_3 V_19 ;
T_1 V_20 = V_21 ;
T_2 V_3 ;
int V_22 ;
struct V_6 V_12 ;
struct V_23 V_24 = { 0 , 0 , 0 , 0 } ;
V_3 = 0 ;
V_17 = NULL ;
if ( V_14 == NULL || V_15 == 0 )
{
F_3 ( V_11 , ( L_9 ) ) ;
return V_25 ;
}
V_18 = 0 ;
V_19 = 0 ;
V_17 = F_7 ( V_26 + 1 ) ;
if( NULL == V_17 ) {
return V_25 ;
}
if ( V_16 == V_27 )
{
int V_28 = 0 ;
while( ( V_5 = F_8 ( V_17 , V_26 , V_14 , V_15 , & V_3 ) ) != NULL )
{
F_9 ( V_5 ) ;
if ( ( V_5 [ 0 ] == '/' ) && ( V_5 [ 1 ] == '/' ) )
{
continue;
}
if ( ( V_5 [ 0 ] == '#' ) ) {
if ( V_24 . V_29 != 0 )
{
F_3 ( V_11 , ( L_10 ) ) ;
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
else {
V_24 . V_29 = 1 ;
continue;
}
}
if ( ( V_5 [ 0 ] == '/' ) && ( V_5 [ 1 ] == '*' ) )
{
V_5 += 2 ;
F_9 ( V_5 ) ;
if( ! strncmp ( V_5 , L_11 , 2 ) || ! strncmp ( V_5 , L_12 , 2 ) || ! strncmp ( V_5 , L_13 , 2 ) )
V_20 = V_30 ;
if( ! strncmp ( V_5 , L_14 , 2 ) || ! strncmp ( V_5 , L_15 , 2 ) || ! strncmp ( V_5 , L_16 , 2 ) )
V_20 = V_31 ;
if( ! strncmp ( V_5 , L_17 , 2 ) || ! strncmp ( V_5 , L_18 , 2 ) || ! strncmp ( V_5 , L_19 , 2 ) )
V_20 = V_21 ;
V_28 = 0 ;
V_24 . V_29 = 0 ;
continue;
}
switch( V_20 )
{
case V_21 :
{
if ( V_24 . V_29 == 1 )
{
F_9 ( V_5 ) ;
if( F_2 ( V_5 , & V_12 ) ) {
F_3 ( V_11 , ( L_20 ) ) ;
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
V_32 [ V_18 ] . V_33 = F_4 ( V_5 , V_12 ) ;
F_3 ( V_11 , ( L_21 , V_32 [ V_18 ] . V_33 ) ) ;
if ( V_18 == 0 )
{
V_34 = V_32 [ V_18 ] . V_33 ;
}
V_24 . V_29 = 2 ;
}
else if ( V_24 . V_29 == 2 )
{
if( F_2 ( V_5 , & V_12 ) ) {
F_3 ( V_11 , ( L_22 ) ) ;
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
V_19 = F_4 ( V_5 , V_12 ) ;
if ( V_19 > V_26 / 2 )
{
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
V_32 [ V_18 ] . V_35 = V_19 ;
V_32 [ V_18 ] . V_36 = ( T_1 * ) F_7 ( V_19 ) ;
F_3 ( V_11 , ( L_23 , V_32 [ V_18 ] . V_35 , V_18 ) ) ;
V_24 . V_29 = 3 ;
V_24 . V_37 = 0 ;
}
else if( V_24 . V_29 == 3 ) {
if( V_24 . V_37 == 0 ) {
if( F_2 ( V_5 , & V_12 ) ) {
F_3 ( V_11 , ( L_24 ) ) ;
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
}
F_9 ( V_5 ) ;
V_24 . V_38 = 0 ;
if( V_5 [ V_24 . V_38 ] == '[' ) {
while( V_5 [ V_24 . V_38 ] != ']' && V_5 [ V_24 . V_38 ] != '\0' ) {
V_24 . V_38 ++ ;
}
if( V_5 [ V_24 . V_38 ] == ']' ) {
V_24 . V_38 ++ ;
} else {
V_24 . V_38 = 0 ;
}
}
V_22 = ( V_19 > V_39 ) ? V_39 : V_19 ;
if( ( V_12 . V_8 == V_9 ) && V_12 . V_10 == true ) {
while( V_22 > 0 ) {
V_32 [ V_18 ] . V_36 [ V_24 . V_40 ] =
( T_1 ) ( F_11 ( V_5 [ V_24 . V_38 ] ) << 4 )
| ( T_1 ) ( F_11 ( V_5 [ V_24 . V_38 + 1 ] ) ) ;
V_32 [ V_18 ] . V_36 [ V_24 . V_40 + 1 ] =
( T_1 ) ( F_11 ( V_5 [ V_24 . V_38 + 3 ] ) << 4 )
| ( T_1 ) ( F_11 ( V_5 [ V_24 . V_38 + 4 ] ) ) ;
V_24 . V_38 += 6 ;
V_24 . V_40 += 2 ;
V_22 -= 2 ;
}
if( V_19 > V_39 ) {
V_19 -= V_39 ;
}
else {
V_19 = 0 ;
}
}
else {
}
V_24 . V_37 ++ ;
if( V_19 == 0 ) {
V_24 . V_29 = 0 ;
V_24 . V_38 = 0 ;
V_24 . V_37 = 0 ;
V_24 . V_40 = 0 ;
}
else {
V_24 . V_38 = 0 ;
}
if( ( V_24 . V_29 == 0 ) && ( ++ V_18 == V_41 ) )
{
F_3 ( V_11 , ( L_25 ) ) ;
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
}
}
break;
default:
{
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
break;
}
V_28 ++ ;
}
V_42 = V_18 ;
F_3 ( V_11 , ( L_26 , V_42 ) ) ;
}
if ( V_18 > V_41 )
{
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return V_25 ;
}
if( V_17 != NULL ) {
F_10 ( V_17 ) ;
}
return 0 ;
}
int F_12 ( T_1 * V_14 , T_2 V_2 , T_2 * V_3 , char * V_1 )
{
unsigned char V_43 ;
V_43 = F_1 ( V_14 , V_2 , V_3 ) ;
if( V_43 != '\0' && isxdigit ( V_43 ) ) {
V_1 [ 0 ] = V_43 ;
} else
{
return V_25 ;
}
V_43 = F_1 ( V_14 , V_2 , V_3 ) ;
if( V_43 != '\0' && isxdigit ( V_43 ) ) {
V_1 [ 1 ] = V_43 ;
} else
{
return V_25 ;
}
return 0 ;
}
int F_13 ( T_1 * V_44 , T_2 V_45 )
{
char V_46 [ 3 ] ;
char Line [ V_47 + 1 ] ;
int V_19 , V_48 ;
int V_49 ;
int V_50 , V_51 , V_52 ;
int V_53 ;
T_2 V_54 ;
V_46 [ 2 ] = '\0' ;
V_51 = 0 ;
V_54 = 0 ;
V_55 = 0 ;
while( NULL != F_8 ( Line , V_47 , V_44 , V_45 , & V_54 ) ) {
if( strlen ( Line ) <= 1 || ! isxdigit ( Line [ 0 ] ) ) {
continue;
} else {
break;
}
}
V_19 = F_5 ( Line , NULL , 16 ) ;
V_48 = V_19 ;
while( V_19 > V_47 ) {
if( V_56 == V_55 ) {
for( V_50 = 0 ; V_50 < V_55 ; V_50 ++ ) {
F_10 ( V_57 [ V_50 ] . V_58 ) ;
}
return V_25 ;
}
V_57 [ V_55 ] . V_59 = V_47 ;
V_57 [ V_55 ] . V_58 = ( T_1 * ) F_7 ( V_47 ) ;
V_55 ++ ;
V_19 = V_19 - V_47 ;
}
V_57 [ V_55 ] . V_59 = ( V_19 & 0xFF ) ;
if( V_19 != 0 ) {
V_57 [ V_55 ] . V_58 = ( T_1 * ) F_7 ( V_19 ) ;
V_55 ++ ;
}
V_49 = 0 ;
while( V_48 > V_47 ) {
F_3 ( V_11 , ( L_27 , V_51 ) ) ;
for ( V_50 = 0 , V_52 = 0 ; V_50 < V_47 * 2 ; V_50 += 2 , V_52 ++ , V_49 += 2 ) {
if( F_12 ( V_44 , V_45 , & V_54 , V_46 ) == V_25 ) {
return V_25 ;
}
V_53 = F_14 ( & V_46 [ 0 ] , NULL , 16 ) ;
V_57 [ V_51 ] . V_58 [ V_52 ] = ( V_53 & 0xFF ) ;
}
V_51 ++ ;
V_48 = V_48 - V_47 ;
}
if( V_51 == 0 ) {
V_51 ++ ;
}
F_3 ( V_11 , ( L_27 , V_51 ) ) ;
for ( V_52 = 0 ; V_52 < V_48 ; V_50 += 2 , V_52 ++ , V_49 += 2 ) {
if( F_12 ( V_44 , V_45 , & V_54 , V_46 ) == V_25 ) {
return V_25 ;
}
V_53 = F_14 ( V_46 , NULL , 16 ) ;
V_57 [ V_51 ] . V_58 [ V_52 ] = ( V_53 & 0xFF ) ;
}
return 0 ;
}
int F_15 ( T_1 * V_14 , T_2 V_15 )
{
int V_60 ;
int V_50 ;
bool V_61 = false ;
V_42 = 0 ;
V_62 = 0 ;
V_63 = false ;
V_60 = V_25 ;
if( NULL != V_14 && V_15 != 0 )
{
F_3 ( V_11 , ( L_28 ) ) ;
V_60 = F_6 ( V_14 , V_15 , V_27 ) ;
}
if( V_42 == 0 ) {
V_62 = 10 ;
}
else{
for( V_50 = 0 ; V_50 < V_42 ; V_50 ++ ) {
if( V_32 [ V_50 ] . V_33 == 1 ) {
V_61 = true ;
F_3 ( V_11 , ( L_29 ) ) ;
}
if( V_32 [ V_50 ] . V_35 % 2 == 1 ) {
V_62 = V_62 + V_32 [ V_50 ] . V_35 + 1 ;
}
else{
V_62 = V_62 + V_32 [ V_50 ] . V_35 ;
}
}
}
if( V_42 > 0 && ! V_61 ) {
F_3 ( V_11 , ( L_30 ) ) ;
V_62 = V_62 + 10 ;
}
V_62 = V_62 + 10 + ( V_42 * 4 ) ;
F_3 ( V_11 , ( L_31 , V_62 ) ) ;
return V_60 ;
}
char * F_8 ( char * V_1 , int V_64 , T_1 * V_14 , T_2 V_2 , T_2 * V_3 )
{
int V_49 ;
static short V_65 ;
char V_66 ;
V_49 = 0 ;
V_65 = V_25 ;
do
{
V_66 = F_1 ( V_14 , V_2 , V_3 ) ;
if( V_66 == '\0' ) {
V_1 [ V_49 + 1 ] = '\0' ;
if( V_49 == 0 ) {
return NULL ;
}
else {
return V_1 ;
}
}
if( V_66 == 13 ) {
} else if( V_66 == 10 ) {
V_1 [ V_49 ] = '\0' ;
V_65 = V_25 ;
return V_1 ;
} else {
V_1 [ V_49 ++ ] = V_66 ;
}
}
while( V_49 < V_64 - 1 && V_66 != '\0' );
V_1 [ V_49 ] = '\0' ;
return V_1 ;
}
static void F_16 ( T_1 * V_67 , T_1 V_68 , int V_69 , int V_70 ) {
V_67 [ 0 ] = 0x0B ;
V_67 [ 1 ] = 0xFC ;
V_67 [ 2 ] = V_69 + 4 ;
V_67 [ 3 ] = V_68 ;
V_67 [ 4 ] = ( V_70 & 0xFF ) ;
V_67 [ 5 ] = ( ( V_70 >> 8 ) & 0xFF ) ;
V_67 [ 6 ] = V_69 ;
}
int F_17 ( struct V_71 * * V_72 , T_2 * V_73 )
{
T_1 V_49 ;
T_2 V_74 = 0 ;
T_2 V_75 = 0 ;
* V_73 = 0 ;
if( V_55 > 0 )
V_75 |= V_76 ;
if( V_42 > 0 )
V_75 |= V_77 ;
F_3 ( V_11 , ( L_32 , V_75 , V_55 , V_42 ) ) ;
if( V_55 || V_42 ) {
V_74 += ( 2 + V_55 + V_42 ) ;
if( V_55 > 0 ) {
V_74 ++ ;
}
F_3 ( V_11 , ( L_33 , V_74 , ( T_2 ) sizeof( struct V_71 ) * V_74 ) ) ;
( * V_72 ) = F_7 ( sizeof( struct V_71 ) * V_74 ) ;
if( NULL == * V_72 ) {
F_3 ( V_11 , ( L_34 ) ) ;
}
F_18 ( V_78 , V_75 , * V_72 , V_73 ) ;
if( V_55 > 0 ) {
F_3 ( V_11 , ( L_35 ) ) ;
F_18 ( V_79 , V_55 , * V_72 , V_73 ) ;
F_3 ( V_11 , ( L_36 ) ) ;
F_18 ( V_80 , 0 , * V_72 , V_73 ) ;
}
F_3 ( V_11 , ( L_37 , V_81 , V_81 ) ) ;
F_18 ( V_82 , V_81 , * V_72 , V_73 ) ;
if( V_42 > 0 ) {
F_3 ( V_11 , ( L_38 ) ) ;
F_18 ( V_83 , V_42 , * V_72 , V_73 ) ;
}
}
if( ! V_63 ) {
F_3 ( V_11 , ( L_39 ) ) ;
}
for( V_49 = 0 ; V_49 < V_55 ; V_49 ++ ) {
F_3 ( V_11 , ( L_40 , V_49 ) ) ;
F_10 ( V_57 [ V_49 ] . V_58 ) ;
}
for( V_49 = 0 ; V_49 < V_42 ; V_49 ++ ) {
F_3 ( V_11 , ( L_41 , V_49 ) ) ;
F_10 ( V_32 [ V_49 ] . V_36 ) ;
}
return * V_73 ;
}
static int F_18 ( T_1 V_84 , T_2 V_85 , struct V_71 * V_86 , T_2 * V_70 )
{
T_1 * V_67 ;
T_2 V_87 ;
int V_50 , V_51 ;
switch( V_84 )
{
case V_79 :
for( V_50 = 0 ; V_50 < V_85 ; V_50 ++ ) {
V_67 = ( T_1 * ) F_7 ( V_57 [ V_50 ] . V_59 + V_88 ) ;
F_3 ( V_11 , ( L_42 , V_57 [ V_50 ] . V_59 + V_88 ) ) ;
if( V_67 == NULL ) {
F_3 ( V_11 , ( L_43 ) ) ;
return V_25 ;
}
memset ( V_67 , 0 , V_57 [ V_50 ] . V_59 + V_88 ) ;
F_16 ( V_67 , V_84 , V_57 [ V_50 ] . V_59 , V_50 ) ;
for( V_51 = 0 ; V_51 < V_57 [ V_50 ] . V_59 ; V_51 ++ ) {
V_67 [ V_88 + V_51 ] = V_57 [ V_50 ] . V_58 [ V_51 ] ;
}
V_86 [ * V_70 ] . V_89 = V_67 ;
V_86 [ * V_70 ] . V_90 = V_57 [ V_50 ] . V_59 + V_88 ;
( * V_70 ) ++ ;
}
break;
case V_80 :
V_87 = 0 ;
V_50 = 0 ;
V_67 = ( T_1 * ) F_7 ( V_87 + V_88 ) ;
if( V_67 == NULL ) {
F_3 ( V_11 , ( L_43 ) ) ;
return V_25 ;
}
memset ( V_67 , 0 , V_87 + V_88 ) ;
F_16 ( V_67 , V_84 , V_87 , V_50 ) ;
V_86 [ * V_70 ] . V_89 = V_67 ;
V_86 [ * V_70 ] . V_90 = V_87 + V_88 ;
( * V_70 ) ++ ;
break;
case V_82 :
V_87 = 0x06 ;
V_50 = 0 ;
V_67 = ( T_1 * ) F_7 ( V_87 + V_88 ) ;
if( V_67 == NULL ) {
F_3 ( V_11 , ( L_43 ) ) ;
return V_25 ;
}
memset ( V_67 , 0 , V_87 + V_88 ) ;
F_16 ( V_67 , V_84 , V_87 , V_50 ) ;
V_67 [ 7 ] = 0x00 ;
V_67 [ V_87 + V_88 - 2 ] = ( V_85 & 0xFF ) ;
V_67 [ V_87 + V_88 - 1 ] = ( ( V_85 >> 8 ) & 0xFF ) ;
V_86 [ * V_70 ] . V_89 = V_67 ;
V_86 [ * V_70 ] . V_90 = V_87 + V_88 ;
( * V_70 ) ++ ;
break;
case V_83 :
for( V_50 = 0 ; V_50 < V_85 ; V_50 ++ ) {
if( V_32 [ V_50 ] . V_33 == 1 )
V_63 = true ;
V_67 = ( T_1 * ) F_7 ( V_32 [ V_50 ] . V_35 + V_88 ) ;
if( V_67 == NULL ) {
F_3 ( V_11 , ( L_43 ) ) ;
return V_25 ;
}
memset ( V_67 , 0 , V_32 [ V_50 ] . V_35 + V_88 ) ;
F_16 ( V_67 , V_84 , V_32 [ V_50 ] . V_35 , V_32 [ V_50 ] . V_33 ) ;
for( V_51 = 0 ; V_51 < V_32 [ V_50 ] . V_35 ; V_51 ++ ) {
V_67 [ V_88 + V_51 ] = V_32 [ V_50 ] . V_36 [ V_51 ] ;
}
V_86 [ * V_70 ] . V_89 = V_67 ;
V_86 [ * V_70 ] . V_90 = V_32 [ V_50 ] . V_35 + V_88 ;
( * V_70 ) ++ ;
}
break;
case V_78 :
V_87 = 0x0 ;
F_3 ( V_11 , ( L_44 , V_85 , * V_70 ) ) ;
V_67 = ( T_1 * ) F_7 ( V_87 + V_88 ) ;
if( V_67 == NULL ) {
F_3 ( V_11 , ( L_43 ) ) ;
return V_25 ;
}
memset ( V_67 , 0 , V_87 + V_88 ) ;
F_16 ( V_67 , V_84 , V_87 , V_85 ) ;
V_86 [ * V_70 ] . V_89 = V_67 ;
V_86 [ * V_70 ] . V_90 = V_87 + V_88 ;
( * V_70 ) ++ ;
break;
case V_91 :
break;
}
return 0 ;
}
int F_19 ( struct V_71 * * V_72 , T_2 V_73 )
{
int V_50 ;
if( * V_72 == NULL ) {
return V_25 ;
}
for( V_50 = 0 ; V_50 < V_73 ; V_50 ++ ) {
F_10 ( ( * V_72 ) [ V_50 ] . V_89 ) ;
}
F_10 ( * V_72 ) ;
return 0 ;
}
