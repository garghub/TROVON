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
static int
F_4 ( int * V_8 , const char * V_9 , const char * V_10 )
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
T_2 F_5 ( T_3 * V_15 , int * V_16 , T_4 * * V_17 )
{
char V_18 [ 64 ] , V_19 [ 64 ] ;
if ( F_6 ( V_18 , sizeof( V_18 ) , V_15 -> V_20 ) == NULL ||
F_6 ( V_19 , sizeof( V_19 ) , V_15 -> V_20 ) == NULL )
{
* V_16 = F_7 ( V_15 -> V_20 , V_17 ) ;
if ( * V_16 != 0 && * V_16 != V_21 )
return V_22 ;
return V_23 ;
}
if( strncmp ( V_24 , V_18 , strlen ( V_24 ) ) != 0 ||
strncmp ( V_25 , V_19 , strlen ( V_25 ) ) != 0 )
{
return V_23 ;
}
V_15 -> V_26 = V_27 ;
V_15 -> V_28 = V_29 ;
V_15 -> V_30 = 0 ;
V_15 -> V_31 = V_32 ;
V_15 -> V_33 = V_34 ;
V_15 -> V_35 = V_36 ;
return V_37 ;
}
static T_5 F_8 ( T_6 V_20 , struct V_38 * V_39 ,
T_7 * V_14 , int * V_16 , T_4 * * V_17 )
{
char line [ 1024 ] ;
T_1 V_40 [ V_41 ] , * V_42 ;
T_5 V_43 = FALSE ;
int V_44 = 0 ;
V_42 = & V_40 [ 0 ] ;
while ( F_6 ( line , sizeof( line ) , V_20 ) != NULL )
{
if( memcmp ( V_45 , line , strlen ( V_45 ) ) == 0 )
{
* V_16 = 0 ;
return FALSE ;
}
else if( memcmp ( V_46 , line , strlen ( V_46 ) ) == 0 )
{
if( V_43 )
{
V_39 -> V_47 = V_48 ;
V_39 -> V_49 = 0 ;
V_39 -> V_50 . V_51 = 0 ;
V_39 -> V_50 . V_52 = 0 ;
V_39 -> V_53 = V_44 ;
V_39 -> V_44 = V_44 ;
* V_16 = 0 ;
F_9 ( V_14 , V_39 -> V_53 ) ;
memcpy ( F_10 ( V_14 ) , V_40 , V_39 -> V_53 ) ;
return TRUE ;
}
else
{
* V_16 = V_54 ;
* V_17 = F_11 ( L_1 ) ;
return FALSE ;
}
}
else if( memcmp ( V_55 , line , strlen ( V_55 ) ) == 0 )
{
int V_56 , V_57 ;
char * V_11 ;
V_39 -> V_58 . V_59 . V_60 = ! strstr ( line , L_2 ) ;
if ( F_4 ( & V_56 , line , L_3 ) != 0 )
goto V_61;
if( ! V_39 -> V_58 . V_59 . V_60 )
{
if ( F_4 ( & V_57 , line , L_4 ) != 0 )
goto V_61;
V_39 -> V_58 . V_59 . V_62 = V_57 ;
if ( F_4 ( & V_57 , line , L_5 ) != 0 )
goto V_61;
V_39 -> V_58 . V_59 . V_63 = V_57 ;
if ( F_4 ( & V_57 , line , L_6 ) != 0 )
goto V_61;
V_39 -> V_58 . V_59 . V_64 = V_57 ;
if ( F_4 ( & V_57 , line , L_7 ) != 0 )
goto V_61;
V_39 -> V_58 . V_59 . error = V_57 ;
if ( F_4 ( & V_57 , line , L_8 ) != 0 )
goto V_61;
V_39 -> V_58 . V_59 . V_65 = V_57 ;
}
switch( V_56 )
{
case 128 : V_39 -> V_58 . V_59 . V_56 = V_66 ; break;
case 112 : V_39 -> V_58 . V_59 . V_56 = V_67 ; break;
case 176 : V_39 -> V_58 . V_59 . V_56 = V_68 ; break;
case 96 : V_39 -> V_58 . V_59 . V_56 = V_69 ; break;
case 80 : V_39 -> V_58 . V_59 . V_56 = V_70 ; break;
default: V_39 -> V_58 . V_59 . V_56 = V_71 ; break;
}
V_11 = strstr ( line , L_9 ) ;
if( V_11 )
{
V_43 = TRUE ;
V_44 = F_3 ( V_42 , & V_40 [ V_41 ] , V_11 + 6 ) ;
if ( V_44 == - 1 )
{
* V_16 = V_54 ;
* V_17 = F_11 ( L_10 , V_39 -> V_53 ) ;
return FALSE ;
}
}
}
else if( ! V_43 && memcmp ( V_72 , line , strlen ( V_72 ) ) == 0 )
{
int V_73 ;
char * V_11 = strstr ( line , L_9 ) ;
if( ! V_11 )
{
continue;
}
V_43 = TRUE ;
if( V_39 -> V_58 . V_59 . V_56 == V_67 || V_39 -> V_58 . V_59 . V_56 == V_68 || V_39 -> V_58 . V_59 . V_56 == V_66 )
{
memset ( V_42 , 0x1 , 2 ) ;
V_44 = 3 ;
}
else
{
V_44 = 1 ;
}
V_42 += V_44 ;
V_73 = F_3 ( V_42 , & V_40 [ V_41 ] , V_11 + 6 ) ;
if ( V_73 == - 1 )
{
* V_16 = V_54 ;
* V_17 = F_11 ( L_10 , V_39 -> V_53 ) ;
return FALSE ;
}
V_44 += V_73 ;
* ( V_42 - 1 ) = V_73 << 2 | 0x1 ;
}
}
* V_16 = F_7 ( V_20 , V_17 ) ;
if ( * V_16 == 0 )
{
* V_16 = V_21 ;
}
return FALSE ;
V_61:
* V_16 = V_54 ;
* V_17 = F_11 ( L_11 ) ;
return FALSE ;
}
static T_5 V_32 ( T_3 * V_15 , int * V_16 , T_4 * * V_17 ,
T_8 * V_74 )
{
* V_74 = F_12 ( V_15 -> V_20 ) ;
return F_8 ( V_15 -> V_20 , & V_15 -> V_39 , V_15 -> V_75 ,
V_16 , V_17 ) ;
}
static T_5 V_34 ( T_3 * V_15 , T_8 V_76 ,
struct V_38 * V_39 , T_7 * V_14 , int * V_16 , T_4 * * V_17 )
{
if ( F_13 ( V_15 -> V_77 , V_76 , V_78 , V_16 ) == - 1 )
{
return FALSE ;
}
return F_8 ( V_15 -> V_77 , V_39 , V_14 , V_16 , V_17 ) ;
}
