static int
F_1 ( unsigned char V_1 )
{
V_1 = F_2 ( V_1 ) ;
if ( ( V_1 >= '0' ) && ( V_1 <= '9' ) )
return V_1 - '0' ;
if ( ( V_1 >= 'a' ) && ( V_1 <= 'f' ) )
return V_1 - 'a' + 10 ;
return - 1 ;
}
static int
F_3 ( T_1 * V_2 , T_1 * V_3 , char * V_4 )
{
T_1 * V_5 = V_2 ;
int V_6 = 0 ;
int V_7 ;
while ( * V_4 != '\0' )
{
V_7 = F_1 ( * ( unsigned char * ) V_4 ) ;
if ( V_7 < 0 )
{
V_4 ++ ;
continue;
}
if ( V_2 == V_3 )
{
return - 1 ;
}
if ( V_6 == 0 )
{
* V_2 = V_7 << 4 ;
V_6 = 1 ;
} else {
* V_2 |= ( V_7 & 0x0f ) ;
V_6 = 0 ;
V_2 ++ ;
}
V_4 ++ ;
}
return ( int ) ( V_2 - V_5 ) ;
}
static T_2
F_4 ( int * V_8 , const char * V_9 , const char * V_10 , int * V_11 , T_3 * * V_12 )
{
const char * V_13 , * V_14 ;
char * V_15 , * V_16 ;
char V_17 [ 32 ] ;
V_13 = strstr ( V_9 , V_10 ) ;
if ( V_13 == NULL ) {
* V_11 = V_18 ;
* V_12 = F_5 ( L_1 , V_10 ) ;
return FALSE ;
}
V_15 = strchr ( V_13 , '"' ) ;
if ( V_15 == NULL ) {
* V_11 = V_18 ;
* V_12 = F_5 ( L_2 , V_10 ) ;
return FALSE ;
}
V_15 ++ ;
V_16 = strchr ( V_15 , '"' ) ;
if ( V_16 == NULL ) {
* V_11 = V_18 ;
* V_12 = F_5 ( L_3 , V_10 ) ;
return FALSE ;
}
if ( V_16 - V_15 > 31 ) {
* V_11 = V_18 ;
* V_12 = F_5 ( L_4 , V_10 ) ;
return FALSE ;
}
memcpy ( V_17 , V_15 , V_16 - V_15 ) ;
V_17 [ V_16 - V_15 ] = '\0' ;
if ( ! F_6 ( V_17 , & V_14 , V_8 ) ) {
* V_11 = V_18 ;
if ( V_19 == V_20 ) {
if ( * V_8 < 0 )
* V_12 = F_5 ( L_5 , V_10 , * V_8 ) ;
else
* V_12 = F_5 ( L_6 , V_10 , * V_8 ) ;
} else
* V_12 = F_5 ( L_7 , V_10 , V_17 ) ;
return FALSE ;
}
if ( * V_14 != '\0' ) {
* V_11 = V_18 ;
* V_12 = F_5 ( L_7 , V_10 , V_17 ) ;
return FALSE ;
}
return TRUE ;
}
T_4 F_7 ( T_5 * V_21 , int * V_11 , T_3 * * V_12 )
{
char V_22 [ 64 ] , V_23 [ 64 ] ;
if ( F_8 ( V_22 , sizeof( V_22 ) , V_21 -> V_24 ) == NULL ||
F_8 ( V_23 , sizeof( V_23 ) , V_21 -> V_24 ) == NULL )
{
* V_11 = F_9 ( V_21 -> V_24 , V_12 ) ;
if ( * V_11 != 0 && * V_11 != V_25 )
return V_26 ;
return V_27 ;
}
if( strncmp ( V_28 , V_22 , strlen ( V_28 ) ) != 0 ||
strncmp ( V_29 , V_23 , strlen ( V_29 ) ) != 0 )
{
return V_27 ;
}
V_21 -> V_30 = V_31 ;
V_21 -> V_32 = V_33 ;
V_21 -> V_34 = 0 ;
V_21 -> V_35 = V_36 ;
V_21 -> V_37 = V_38 ;
V_21 -> V_39 = V_40 ;
return V_41 ;
}
static T_2 F_10 ( T_6 V_24 , struct V_42 * V_43 ,
T_7 * V_17 , int * V_11 , T_3 * * V_12 )
{
char line [ 1024 ] ;
T_1 V_44 [ V_45 ] , * V_46 ;
T_2 V_47 = FALSE ;
int V_48 = 0 ;
V_46 = & V_44 [ 0 ] ;
while ( F_8 ( line , sizeof( line ) , V_24 ) != NULL )
{
if( memcmp ( V_49 , line , strlen ( V_49 ) ) == 0 )
{
* V_11 = 0 ;
return FALSE ;
}
else if( memcmp ( V_50 , line , strlen ( V_50 ) ) == 0 )
{
if( V_47 )
{
V_43 -> V_51 = V_52 ;
V_43 -> V_53 = 0 ;
V_43 -> V_54 . V_55 = 0 ;
V_43 -> V_54 . V_56 = 0 ;
V_43 -> V_57 = V_48 ;
V_43 -> V_48 = V_48 ;
* V_11 = 0 ;
F_11 ( V_17 , V_43 -> V_57 ) ;
memcpy ( F_12 ( V_17 ) , V_44 , V_43 -> V_57 ) ;
return TRUE ;
}
else
{
* V_11 = V_18 ;
* V_12 = F_13 ( L_8 ) ;
return FALSE ;
}
}
else if( memcmp ( V_58 , line , strlen ( V_58 ) ) == 0 )
{
int V_59 , V_60 ;
char * V_13 ;
V_43 -> V_61 . V_62 . V_63 = ! strstr ( line , L_9 ) ;
if ( ! F_4 ( & V_59 , line , L_10 , V_11 , V_12 ) )
return FALSE ;
if( ! V_43 -> V_61 . V_62 . V_63 )
{
if ( ! F_4 ( & V_60 , line , L_11 , V_11 , V_12 ) )
return FALSE ;
V_43 -> V_61 . V_62 . V_64 = V_60 ;
if ( ! F_4 ( & V_60 , line , L_12 , V_11 , V_12 ) )
return FALSE ;
V_43 -> V_61 . V_62 . V_65 = V_60 ;
if ( ! F_4 ( & V_60 , line , L_13 , V_11 , V_12 ) )
return FALSE ;
V_43 -> V_61 . V_62 . V_66 = V_60 ;
if ( ! F_4 ( & V_60 , line , L_14 , V_11 , V_12 ) )
return FALSE ;
V_43 -> V_61 . V_62 . error = V_60 ;
if ( ! F_4 ( & V_60 , line , L_15 , V_11 , V_12 ) )
return FALSE ;
V_43 -> V_61 . V_62 . V_67 = V_60 ;
}
switch( V_59 )
{
case 128 : V_43 -> V_61 . V_62 . V_59 = V_68 ; break;
case 112 : V_43 -> V_61 . V_62 . V_59 = V_69 ; break;
case 176 : V_43 -> V_61 . V_62 . V_59 = V_70 ; break;
case 96 : V_43 -> V_61 . V_62 . V_59 = V_71 ; break;
case 80 : V_43 -> V_61 . V_62 . V_59 = V_72 ; break;
default: V_43 -> V_61 . V_62 . V_59 = V_73 ; break;
}
V_13 = strstr ( line , L_16 ) ;
if( V_13 )
{
V_47 = TRUE ;
V_48 = F_3 ( V_46 , & V_44 [ V_45 ] , V_13 + 6 ) ;
if ( V_48 == - 1 )
{
* V_11 = V_18 ;
* V_12 = F_5 ( L_17 , V_43 -> V_57 ) ;
return FALSE ;
}
}
}
else if( ! V_47 && memcmp ( V_74 , line , strlen ( V_74 ) ) == 0 )
{
int V_75 ;
char * V_13 = strstr ( line , L_16 ) ;
if( ! V_13 )
{
continue;
}
V_47 = TRUE ;
if( V_43 -> V_61 . V_62 . V_59 == V_69 || V_43 -> V_61 . V_62 . V_59 == V_70 || V_43 -> V_61 . V_62 . V_59 == V_68 )
{
memset ( V_46 , 0x1 , 2 ) ;
V_48 = 3 ;
}
else
{
V_48 = 1 ;
}
V_46 += V_48 ;
V_75 = F_3 ( V_46 , & V_44 [ V_45 ] , V_13 + 6 ) ;
if ( V_75 == - 1 )
{
* V_11 = V_18 ;
* V_12 = F_5 ( L_17 , V_43 -> V_57 ) ;
return FALSE ;
}
V_48 += V_75 ;
* ( V_46 - 1 ) = V_75 << 2 | 0x1 ;
}
}
* V_11 = F_9 ( V_24 , V_12 ) ;
if ( * V_11 == 0 )
{
* V_11 = V_25 ;
}
return FALSE ;
}
static T_2 V_36 ( T_5 * V_21 , int * V_11 , T_3 * * V_12 ,
T_8 * V_76 )
{
* V_76 = F_14 ( V_21 -> V_24 ) ;
return F_10 ( V_21 -> V_24 , & V_21 -> V_43 , V_21 -> V_77 ,
V_11 , V_12 ) ;
}
static T_2 V_38 ( T_5 * V_21 , T_8 V_78 ,
struct V_42 * V_43 , T_7 * V_17 , int * V_11 , T_3 * * V_12 )
{
if ( F_15 ( V_21 -> V_79 , V_78 , V_80 , V_11 ) == - 1 )
{
return FALSE ;
}
return F_10 ( V_21 -> V_79 , V_43 , V_17 , V_11 , V_12 ) ;
}
