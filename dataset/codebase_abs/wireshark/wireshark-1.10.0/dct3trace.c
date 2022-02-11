static int
F_1 ( unsigned char V_1 )
{
V_1 = tolower ( V_1 ) ;
if ( ( V_1 >= '0' ) && ( V_1 <= '9' ) )
return V_1 - '0' ;
if ( ( V_1 >= 'a' ) && ( V_1 <= 'f' ) )
return V_1 - 'a' + 10 ;
return - 1 ;
}
static int
F_2 ( unsigned char * V_2 , unsigned char * V_3 )
{
unsigned char * V_4 = V_2 ;
unsigned char * V_5 = V_3 + strlen ( ( char * ) V_3 ) ;
int V_6 = 0 ;
int V_7 ;
if ( V_5 - V_3 > V_8 * 2 )
V_5 = V_3 + V_8 * 2 ;
while ( V_3 < V_5 )
{
V_7 = F_1 ( V_3 [ 0 ] ) ;
if ( V_7 < 0 )
{
V_3 ++ ;
continue;
}
if ( V_6 == 0 )
{
V_2 [ 0 ] = V_7 << 4 ;
V_6 = 1 ;
} else {
V_2 [ 0 ] |= ( V_7 & 0x0f ) ;
V_6 = 0 ;
V_2 ++ ;
}
V_3 ++ ;
}
return ( int ) ( V_2 - V_4 ) ;
}
static int
F_3 ( int * V_9 , const unsigned char * V_10 , const unsigned char * V_11 )
{
const char * V_12 ;
char * V_13 , * V_5 ;
char V_14 [ 32 ] ;
V_12 = strstr ( ( const char * ) V_10 , ( const char * ) V_11 ) ;
if ( V_12 == NULL )
return - 1 ;
V_13 = strchr ( V_12 , '"' ) ;
if ( V_13 == NULL )
return - 2 ;
V_13 ++ ;
V_5 = strchr ( V_13 , '"' ) ;
if ( V_5 == NULL )
return - 3 ;
if ( V_5 - V_13 > 31 )
return - 4 ;
memcpy ( V_14 , V_13 , V_5 - V_13 ) ;
V_14 [ V_5 - V_13 ] = '\0' ;
* V_9 = atoi ( V_14 ) ;
return 0 ;
}
int F_4 ( T_1 * V_15 , int * V_16 , T_2 * * V_17 )
{
char V_18 [ 64 ] , V_19 [ 64 ] ;
if ( F_5 ( V_18 , sizeof( V_18 ) , V_15 -> V_20 ) == NULL ||
F_5 ( V_19 , sizeof( V_19 ) , V_15 -> V_20 ) == NULL )
{
* V_16 = F_6 ( V_15 -> V_20 , V_17 ) ;
if ( * V_16 != 0 && * V_16 != V_21 )
return - 1 ;
return 0 ;
}
if( strncmp ( V_22 , V_18 , strlen ( V_22 ) ) != 0 ||
strncmp ( V_23 , V_19 , strlen ( V_23 ) ) != 0 )
{
return 0 ;
}
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = V_27 ;
V_15 -> V_28 = 0 ;
V_15 -> V_29 = V_30 ;
V_15 -> V_31 = V_32 ;
V_15 -> V_33 = V_34 ;
return 1 ;
}
static T_3 F_7 ( T_4 V_20 , union V_35 * V_36 ,
unsigned char * V_14 , int * V_37 , int * V_16 , T_2 * * V_17 )
{
unsigned char line [ 1024 ] ;
T_3 V_38 = FALSE ;
while ( F_5 ( line , sizeof( line ) , V_20 ) != NULL )
{
if( memcmp ( V_39 , line , strlen ( V_39 ) ) == 0 )
{
* V_16 = 0 ;
return FALSE ;
}
else if( memcmp ( V_40 , line , strlen ( V_40 ) ) == 0 )
{
if( V_38 )
{
* V_16 = 0 ;
return TRUE ;
}
else
{
* V_16 = V_41 ;
* V_17 = F_8 ( L_1 ) ;
return FALSE ;
}
}
else if( memcmp ( V_42 , line , strlen ( V_42 ) ) == 0 )
{
int V_43 , V_44 ;
char * V_12 ;
V_36 -> V_45 . V_46 = ! strstr ( line , L_2 ) ;
if ( F_3 ( & V_43 , line , L_3 ) != 0 )
goto V_47;
if( ! V_36 -> V_45 . V_46 )
{
if ( F_3 ( & V_44 , line , L_4 ) != 0 )
goto V_47;
V_36 -> V_45 . V_48 = V_44 ;
if ( F_3 ( & V_44 , line , L_5 ) != 0 )
goto V_47;
V_36 -> V_45 . V_49 = V_44 ;
if ( F_3 ( & V_44 , line , L_6 ) != 0 )
goto V_47;
V_36 -> V_45 . V_50 = V_44 ;
if ( F_3 ( & V_44 , line , L_7 ) != 0 )
goto V_47;
V_36 -> V_45 . error = V_44 ;
if ( F_3 ( & V_44 , line , L_8 ) != 0 )
goto V_47;
V_36 -> V_45 . V_51 = V_44 ;
}
switch( V_43 )
{
case 128 : V_36 -> V_45 . V_43 = V_52 ; break;
case 112 : V_36 -> V_45 . V_43 = V_53 ; break;
case 176 : V_36 -> V_45 . V_43 = V_54 ; break;
case 96 : V_36 -> V_45 . V_43 = V_55 ; break;
case 80 : V_36 -> V_45 . V_43 = V_56 ; break;
default: V_36 -> V_45 . V_43 = V_57 ; break;
}
V_12 = strstr ( line , L_9 ) ;
if( V_12 )
{
V_38 = TRUE ;
* V_37 = F_2 ( V_14 , V_12 + 6 ) ;
}
}
else if( ! V_38 && memcmp ( V_58 , line , strlen ( V_58 ) ) == 0 )
{
int V_59 = 0 ;
char * V_12 = strstr ( line , L_9 ) ;
if( ! V_12 )
{
continue;
}
V_38 = TRUE ;
if( V_36 -> V_45 . V_43 == V_53 || V_36 -> V_45 . V_43 == V_54 || V_36 -> V_45 . V_43 == V_52 )
{
memset ( V_14 , 0x1 , 2 ) ;
* V_37 = 3 ;
}
else
{
* V_37 = 1 ;
}
V_14 += * V_37 ;
V_59 = F_2 ( V_14 , V_12 + 6 ) ;
* V_37 += V_59 ;
* ( V_14 - 1 ) = V_59 << 2 | 0x1 ;
}
}
* V_16 = F_6 ( V_20 , V_17 ) ;
if ( * V_16 == 0 )
{
* V_16 = V_21 ;
}
return FALSE ;
V_47:
* V_16 = V_41 ;
* V_17 = F_8 ( L_10 ) ;
return FALSE ;
}
static T_3 V_30 ( T_1 * V_15 , int * V_16 , T_2 * * V_17 ,
T_5 * V_60 )
{
T_6 V_61 = F_9 ( V_15 -> V_20 ) ;
int V_62 ;
unsigned char V_14 [ V_8 ] ;
if( ! F_7 ( V_15 -> V_20 , & V_15 -> V_63 . V_36 , V_14 , & V_62 , V_16 , V_17 ) )
{
return FALSE ;
}
V_15 -> V_63 . V_64 = 0 ;
V_15 -> V_63 . V_65 . V_66 = 0 ;
V_15 -> V_63 . V_65 . V_67 = 0 ;
V_15 -> V_63 . V_68 = V_62 ;
V_15 -> V_63 . V_37 = V_62 ;
F_10 ( V_15 -> V_69 , V_62 ) ;
memcpy ( F_11 ( V_15 -> V_69 ) , V_14 , V_62 ) ;
* V_60 = V_61 ;
return TRUE ;
}
static T_3 V_32 ( T_1 * V_15 , T_5 V_70 ,
struct V_71 * V_63 , T_7 * V_72 , int V_37 ,
int * V_16 , T_2 * * V_17 )
{
union V_35 * V_36 = & V_63 -> V_36 ;
int V_62 ;
unsigned char V_14 [ V_8 ] ;
if ( F_12 ( V_15 -> V_73 , V_70 , V_74 , V_16 ) == - 1 )
{
return FALSE ;
}
if( ! F_7 ( V_15 -> V_73 , V_36 , V_14 , & V_62 , V_16 , V_17 ) )
{
return FALSE ;
}
if( V_37 != V_62 && V_37 != - 1 )
{
* V_16 = V_41 ;
* V_17 = F_8 ( L_11 ,
V_37 , V_62 ) ;
return FALSE ;
}
if( V_62 > V_8 )
{
* V_16 = V_41 ;
* V_17 = F_8 ( L_12 , V_62 ) ;
return FALSE ;
}
memcpy ( V_72 , V_14 , V_62 ) ;
return TRUE ;
}
