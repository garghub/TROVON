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
F_2 ( T_1 * V_2 , T_1 * V_3 , char * V_4 )
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
static int
F_3 ( int * V_8 , const char * V_9 , const char * V_10 )
{
const char * V_11 ;
char * V_12 , * V_13 ;
char V_14 [ 32 ] ;
V_11 = strstr ( V_9 , V_10 ) ;
if ( V_11 == NULL )
return - 1 ;
V_12 = strchr ( V_11 , '"' ) ;
if ( V_12 == NULL )
return - 2 ;
V_12 ++ ;
V_13 = strchr ( V_12 , '"' ) ;
if ( V_13 == NULL )
return - 3 ;
if ( V_13 - V_12 > 31 )
return - 4 ;
memcpy ( V_14 , V_12 , V_13 - V_12 ) ;
V_14 [ V_13 - V_12 ] = '\0' ;
* V_8 = atoi ( V_14 ) ;
return 0 ;
}
int F_4 ( T_2 * V_15 , int * V_16 , T_3 * * V_17 )
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
static T_4 F_7 ( T_5 V_20 , struct V_35 * V_36 ,
T_6 * V_14 , int * V_16 , T_3 * * V_17 )
{
char line [ 1024 ] ;
T_1 V_37 [ V_38 ] , * V_39 ;
T_4 V_40 = FALSE ;
int V_41 = 0 ;
V_39 = & V_37 [ 0 ] ;
while ( F_5 ( line , sizeof( line ) , V_20 ) != NULL )
{
if( memcmp ( V_42 , line , strlen ( V_42 ) ) == 0 )
{
* V_16 = 0 ;
return FALSE ;
}
else if( memcmp ( V_43 , line , strlen ( V_43 ) ) == 0 )
{
if( V_40 )
{
V_36 -> V_44 = 0 ;
V_36 -> V_45 . V_46 = 0 ;
V_36 -> V_45 . V_47 = 0 ;
V_36 -> V_48 = V_41 ;
V_36 -> V_41 = V_41 ;
* V_16 = 0 ;
F_8 ( V_14 , V_36 -> V_48 ) ;
memcpy ( F_9 ( V_14 ) , V_37 , V_36 -> V_48 ) ;
return TRUE ;
}
else
{
* V_16 = V_49 ;
* V_17 = F_10 ( L_1 ) ;
return FALSE ;
}
}
else if( memcmp ( V_50 , line , strlen ( V_50 ) ) == 0 )
{
int V_51 , V_52 ;
char * V_11 ;
V_36 -> V_53 . V_54 . V_55 = ! strstr ( line , L_2 ) ;
if ( F_3 ( & V_51 , line , L_3 ) != 0 )
goto V_56;
if( ! V_36 -> V_53 . V_54 . V_55 )
{
if ( F_3 ( & V_52 , line , L_4 ) != 0 )
goto V_56;
V_36 -> V_53 . V_54 . V_57 = V_52 ;
if ( F_3 ( & V_52 , line , L_5 ) != 0 )
goto V_56;
V_36 -> V_53 . V_54 . V_58 = V_52 ;
if ( F_3 ( & V_52 , line , L_6 ) != 0 )
goto V_56;
V_36 -> V_53 . V_54 . V_59 = V_52 ;
if ( F_3 ( & V_52 , line , L_7 ) != 0 )
goto V_56;
V_36 -> V_53 . V_54 . error = V_52 ;
if ( F_3 ( & V_52 , line , L_8 ) != 0 )
goto V_56;
V_36 -> V_53 . V_54 . V_60 = V_52 ;
}
switch( V_51 )
{
case 128 : V_36 -> V_53 . V_54 . V_51 = V_61 ; break;
case 112 : V_36 -> V_53 . V_54 . V_51 = V_62 ; break;
case 176 : V_36 -> V_53 . V_54 . V_51 = V_63 ; break;
case 96 : V_36 -> V_53 . V_54 . V_51 = V_64 ; break;
case 80 : V_36 -> V_53 . V_54 . V_51 = V_65 ; break;
default: V_36 -> V_53 . V_54 . V_51 = V_66 ; break;
}
V_11 = strstr ( line , L_9 ) ;
if( V_11 )
{
V_40 = TRUE ;
V_41 = F_2 ( V_39 , & V_37 [ V_38 ] , V_11 + 6 ) ;
if ( V_41 == - 1 )
{
* V_16 = V_49 ;
* V_17 = F_10 ( L_10 , V_36 -> V_48 ) ;
return FALSE ;
}
}
}
else if( ! V_40 && memcmp ( V_67 , line , strlen ( V_67 ) ) == 0 )
{
int V_68 ;
char * V_11 = strstr ( line , L_9 ) ;
if( ! V_11 )
{
continue;
}
V_40 = TRUE ;
if( V_36 -> V_53 . V_54 . V_51 == V_62 || V_36 -> V_53 . V_54 . V_51 == V_63 || V_36 -> V_53 . V_54 . V_51 == V_61 )
{
memset ( V_39 , 0x1 , 2 ) ;
V_41 = 3 ;
}
else
{
V_41 = 1 ;
}
V_39 += V_41 ;
V_68 = F_2 ( V_39 , & V_37 [ V_38 ] , V_11 + 6 ) ;
if ( V_68 == - 1 )
{
* V_16 = V_49 ;
* V_17 = F_10 ( L_10 , V_36 -> V_48 ) ;
return FALSE ;
}
V_41 += V_68 ;
* ( V_39 - 1 ) = V_68 << 2 | 0x1 ;
}
}
* V_16 = F_6 ( V_20 , V_17 ) ;
if ( * V_16 == 0 )
{
* V_16 = V_21 ;
}
return FALSE ;
V_56:
* V_16 = V_49 ;
* V_17 = F_10 ( L_11 ) ;
return FALSE ;
}
static T_4 V_30 ( T_2 * V_15 , int * V_16 , T_3 * * V_17 ,
T_7 * V_69 )
{
* V_69 = F_11 ( V_15 -> V_20 ) ;
return F_7 ( V_15 -> V_20 , & V_15 -> V_36 , V_15 -> V_70 ,
V_16 , V_17 ) ;
}
static T_4 V_32 ( T_2 * V_15 , T_7 V_71 ,
struct V_35 * V_36 , T_6 * V_14 , int V_41 V_72 ,
int * V_16 , T_3 * * V_17 )
{
if ( F_12 ( V_15 -> V_73 , V_71 , V_74 , V_16 ) == - 1 )
{
return FALSE ;
}
return F_7 ( V_15 -> V_73 , V_36 , V_14 , V_16 , V_17 ) ;
}
