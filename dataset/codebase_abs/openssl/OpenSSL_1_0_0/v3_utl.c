void F_1 ( T_1 * V_1 )
{
if( ! V_1 ) return;
if( V_1 -> V_2 ) F_2 ( V_1 -> V_2 ) ;
if( V_1 -> V_3 ) F_2 ( V_1 -> V_3 ) ;
if( V_1 -> V_4 ) F_2 ( V_1 -> V_4 ) ;
F_2 ( V_1 ) ;
}
char * F_3 ( T_2 * V_5 , T_3 * V_6 )
{
T_4 * V_7 = NULL ;
char * V_8 = NULL ;
if( ! V_6 ) return NULL ;
if( ! ( V_7 = F_4 ( V_6 , NULL ) ) ||
! ( V_8 = F_5 ( V_7 ) ) )
F_6 ( V_9 , V_10 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
char * F_8 ( T_2 * V_5 , T_5 * V_6 )
{
T_4 * V_7 = NULL ;
char * V_8 = NULL ;
if( ! V_6 ) return NULL ;
if( ! ( V_7 = F_9 ( V_6 , NULL ) ) ||
! ( V_8 = F_5 ( V_7 ) ) )
F_6 ( V_11 , V_10 ) ;
F_7 ( V_7 ) ;
return V_8 ;
}
T_5 * F_10 ( T_2 * V_5 , char * V_3 )
{
T_4 * V_12 = NULL ;
T_5 * V_13 ;
int V_14 , V_15 ;
int V_16 ;
if ( ! V_3 ) {
F_6 ( V_17 , V_18 ) ;
return 0 ;
}
V_12 = F_11 () ;
if ( V_3 [ 0 ] == '-' ) {
V_3 ++ ;
V_14 = 1 ;
} else V_14 = 0 ;
if ( V_3 [ 0 ] == '0' && ( ( V_3 [ 1 ] == 'x' ) || ( V_3 [ 1 ] == 'X' ) ) ) {
V_3 += 2 ;
V_15 = 1 ;
} else V_15 = 0 ;
if ( V_15 ) V_16 = F_12 ( & V_12 , V_3 ) ;
else V_16 = F_13 ( & V_12 , V_3 ) ;
if ( ! V_16 || V_3 [ V_16 ] ) {
F_7 ( V_12 ) ;
F_6 ( V_17 , V_19 ) ;
return 0 ;
}
if ( V_14 && F_14 ( V_12 ) ) V_14 = 0 ;
V_13 = F_15 ( V_12 , NULL ) ;
F_7 ( V_12 ) ;
if ( ! V_13 ) {
F_6 ( V_17 , V_20 ) ;
return 0 ;
}
if ( V_14 ) V_13 -> type |= V_21 ;
return V_13 ;
}
int F_16 ( T_1 * V_3 , int * V_22 )
{
char * V_23 ;
if( ! ( V_23 = V_3 -> V_3 ) ) goto V_24;
if( ! strcmp ( V_23 , L_1 ) || ! strcmp ( V_23 , L_2 )
|| ! strcmp ( V_23 , L_3 ) || ! strcmp ( V_23 , L_4 )
|| ! strcmp ( V_23 , L_5 ) || ! strcmp ( V_23 , L_6 ) ) {
* V_22 = 0xff ;
return 1 ;
} else if( ! strcmp ( V_23 , L_7 ) || ! strcmp ( V_23 , L_8 )
|| ! strcmp ( V_23 , L_9 ) || ! strcmp ( V_23 , L_10 )
|| ! strcmp ( V_23 , L_11 ) || ! strcmp ( V_23 , L_12 ) ) {
* V_22 = 0 ;
return 1 ;
}
V_24:
F_6 ( V_25 , V_26 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
int F_18 ( T_1 * V_3 , T_5 * * V_13 )
{
T_5 * V_27 ;
if( ! ( V_27 = F_10 ( NULL , V_3 -> V_3 ) ) ) {
F_17 ( V_3 ) ;
return 0 ;
}
* V_13 = V_27 ;
return 1 ;
}
char * F_19 ( char * V_2 )
{
char * V_28 , * V_29 ;
V_28 = V_2 ;
while( * V_28 && isspace ( ( unsigned char ) * V_28 ) ) V_28 ++ ;
if( ! * V_28 ) return NULL ;
V_29 = V_28 + strlen ( V_28 ) - 1 ;
while( ( V_29 != V_28 ) && isspace ( ( unsigned char ) * V_29 ) ) V_29 -- ;
if( V_28 != V_29 ) V_29 [ 1 ] = 0 ;
if( ! * V_28 ) return NULL ;
return V_28 ;
}
char * F_20 ( const unsigned char * V_30 , long V_31 )
{
char * V_32 , * V_29 ;
const unsigned char * V_28 ;
int V_33 ;
const static char V_34 [] = L_13 ;
if( ! V_30 || ! V_31 ) return NULL ;
if( ! ( V_32 = F_21 ( V_31 * 3 + 1 ) ) ) {
F_6 ( V_35 , V_10 ) ;
return NULL ;
}
V_29 = V_32 ;
for( V_33 = 0 , V_28 = V_30 ; V_33 < V_31 ; V_33 ++ , V_28 ++ ) {
* V_29 ++ = V_34 [ ( * V_28 >> 4 ) & 0xf ] ;
* V_29 ++ = V_34 [ * V_28 & 0xf ] ;
* V_29 ++ = ':' ;
}
V_29 [ - 1 ] = 0 ;
#ifdef F_22
F_23 ( V_32 , V_32 , V_29 - V_32 - 1 ) ;
#endif
return V_32 ;
}
unsigned char * F_24 ( const char * V_36 , long * V_31 )
{
unsigned char * V_37 , * V_29 ;
unsigned char V_38 , V_39 , * V_28 ;
if( ! V_36 ) {
F_6 ( V_40 , V_41 ) ;
return NULL ;
}
if( ! ( V_37 = F_21 ( strlen ( V_36 ) >> 1 ) ) ) goto V_24;
for( V_28 = ( unsigned char * ) V_36 , V_29 = V_37 ; * V_28 ; ) {
V_38 = * V_28 ++ ;
#ifdef F_22
V_38 = V_42 [ V_38 ] ;
#endif
if( V_38 == ':' ) continue;
V_39 = * V_28 ++ ;
#ifdef F_22
V_39 = V_42 [ V_39 ] ;
#endif
if( ! V_39 ) {
F_6 ( V_40 , V_43 ) ;
F_2 ( V_37 ) ;
return NULL ;
}
if( isupper ( V_38 ) ) V_38 = tolower ( V_38 ) ;
if( isupper ( V_39 ) ) V_39 = tolower ( V_39 ) ;
if( ( V_38 >= '0' ) && ( V_38 <= '9' ) ) V_38 -= '0' ;
else if ( ( V_38 >= 'a' ) && ( V_38 <= 'f' ) ) V_38 -= 'a' - 10 ;
else goto V_44;
if( ( V_39 >= '0' ) && ( V_39 <= '9' ) ) V_39 -= '0' ;
else if ( ( V_39 >= 'a' ) && ( V_39 <= 'f' ) ) V_39 -= 'a' - 10 ;
else goto V_44;
* V_29 ++ = ( V_38 << 4 ) | V_39 ;
}
if( V_31 ) * V_31 = V_29 - V_37 ;
return V_37 ;
V_24:
if( V_37 ) F_2 ( V_37 ) ;
F_6 ( V_40 , V_10 ) ;
return NULL ;
V_44:
F_2 ( V_37 ) ;
F_6 ( V_40 , V_45 ) ;
return NULL ;
}
int F_25 ( const char * V_2 , const char * V_46 )
{
int V_31 , V_16 ;
char V_47 ;
V_31 = strlen ( V_46 ) ;
if( ( V_16 = strncmp ( V_2 , V_46 , V_31 ) ) ) return V_16 ;
V_47 = V_2 [ V_31 ] ;
if( ! V_47 || ( V_47 == '.' ) ) return 0 ;
return 1 ;
}
static int F_26 ( const char * const * V_6 , const char * const * V_48 )
{
return strcmp ( * V_6 , * V_48 ) ;
}
void F_27 ( T_6 V_36 )
{
F_2 ( V_36 ) ;
}
T_7 * F_28 ( const char * V_49 )
{
unsigned char V_50 [ 16 ] ;
T_7 * V_16 ;
int V_51 ;
V_51 = F_29 ( V_50 , V_49 ) ;
if ( ! V_51 )
return NULL ;
V_16 = F_30 () ;
if ( ! V_16 )
return NULL ;
if ( ! F_31 ( V_16 , V_50 , V_51 ) )
{
F_32 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
T_7 * F_33 ( const char * V_49 )
{
T_7 * V_16 = NULL ;
unsigned char V_50 [ 32 ] ;
char * V_52 = NULL , * V_28 ;
int V_53 , V_54 ;
V_28 = strchr ( V_49 , '/' ) ;
if ( ! V_28 )
return NULL ;
V_52 = F_34 ( V_49 ) ;
if ( ! V_52 )
return NULL ;
V_28 = V_52 + ( V_28 - V_49 ) ;
* V_28 ++ = 0 ;
V_53 = F_29 ( V_50 , V_52 ) ;
if ( ! V_53 )
goto V_24;
V_54 = F_29 ( V_50 + V_53 , V_28 ) ;
F_2 ( V_52 ) ;
V_52 = NULL ;
if ( ! V_54 || ( V_53 != V_54 ) )
goto V_24;
V_16 = F_30 () ;
if ( ! V_16 )
goto V_24;
if ( ! F_31 ( V_16 , V_50 , V_53 + V_54 ) )
goto V_24;
return V_16 ;
V_24:
if ( V_52 )
F_2 ( V_52 ) ;
if ( V_16 )
F_32 ( V_16 ) ;
return NULL ;
}
int F_29 ( unsigned char * V_50 , const char * V_49 )
{
if ( strchr ( V_49 , ':' ) )
{
if ( ! F_35 ( V_50 , V_49 ) )
return 0 ;
return 16 ;
}
else
{
if ( ! F_36 ( V_50 , V_49 ) )
return 0 ;
return 4 ;
}
}
static int F_36 ( unsigned char * V_55 , const char * V_56 )
{
int V_57 , V_58 , V_59 , V_60 ;
if ( sscanf ( V_56 , L_14 , & V_57 , & V_58 , & V_59 , & V_60 ) != 4 )
return 0 ;
if ( ( V_57 < 0 ) || ( V_57 > 255 ) || ( V_58 < 0 ) || ( V_58 > 255 )
|| ( V_59 < 0 ) || ( V_59 > 255 ) || ( V_60 < 0 ) || ( V_60 > 255 ) )
return 0 ;
V_55 [ 0 ] = V_57 ;
V_55 [ 1 ] = V_58 ;
V_55 [ 2 ] = V_59 ;
V_55 [ 3 ] = V_60 ;
return 1 ;
}
static int F_35 ( unsigned char * V_61 , const char * V_56 )
{
T_8 V_62 ;
V_62 . V_63 = 0 ;
V_62 . V_64 = - 1 ;
V_62 . V_65 = 0 ;
if ( ! F_37 ( V_56 , ':' , 0 , V_66 , & V_62 ) )
return 0 ;
if ( V_62 . V_64 == - 1 )
{
if ( V_62 . V_63 != 16 )
return 0 ;
}
else
{
if ( V_62 . V_63 == 16 )
return 0 ;
if ( V_62 . V_65 > 3 )
return 0 ;
else if ( V_62 . V_65 == 3 )
{
if ( V_62 . V_63 > 0 )
return 0 ;
}
else if ( V_62 . V_65 == 2 )
{
if ( ( V_62 . V_64 != 0 )
&& ( V_62 . V_64 != V_62 . V_63 ) )
return 0 ;
}
else
{
if ( ( V_62 . V_64 == 0 )
|| ( V_62 . V_64 == V_62 . V_63 ) )
return 0 ;
}
}
if ( V_62 . V_64 >= 0 )
{
memcpy ( V_61 , V_62 . V_32 , V_62 . V_64 ) ;
memset ( V_61 + V_62 . V_64 , 0 , 16 - V_62 . V_63 ) ;
if ( V_62 . V_63 != V_62 . V_64 )
memcpy ( V_61 + V_62 . V_64 + 16 - V_62 . V_63 ,
V_62 . V_32 + V_62 . V_64 ,
V_62 . V_63 - V_62 . V_64 ) ;
}
else
memcpy ( V_61 , V_62 . V_32 , 16 ) ;
return 1 ;
}
static int V_66 ( const char * V_67 , int V_31 , void * V_68 )
{
T_8 * V_69 = V_68 ;
if ( V_69 -> V_63 == 16 )
return 0 ;
if ( V_31 == 0 )
{
if ( V_69 -> V_64 == - 1 )
V_69 -> V_64 = V_69 -> V_63 ;
else if ( V_69 -> V_64 != V_69 -> V_63 )
return 0 ;
V_69 -> V_65 ++ ;
}
else
{
if ( V_31 > 4 )
{
if ( V_69 -> V_63 > 12 )
return 0 ;
if ( V_67 [ V_31 ] )
return 0 ;
if ( ! F_36 ( V_69 -> V_32 + V_69 -> V_63 , V_67 ) )
return 0 ;
V_69 -> V_63 += 4 ;
}
else
{
if ( ! F_38 ( V_69 -> V_32 + V_69 -> V_63 , V_67 , V_31 ) )
return 0 ;
V_69 -> V_63 += 2 ;
}
}
return 1 ;
}
static int F_38 ( unsigned char * V_70 , const char * V_56 , int V_71 )
{
unsigned char V_47 ;
unsigned int V_72 = 0 ;
if ( V_71 > 4 )
return 0 ;
while( V_71 -- )
{
V_47 = * V_56 ++ ;
V_72 <<= 4 ;
if ( ( V_47 >= '0' ) && ( V_47 <= '9' ) )
V_72 |= V_47 - '0' ;
else if ( ( V_47 >= 'A' ) && ( V_47 <= 'F' ) )
V_72 |= V_47 - 'A' + 10 ;
else if ( ( V_47 >= 'a' ) && ( V_47 <= 'f' ) )
V_72 |= V_47 - 'a' + 10 ;
else
return 0 ;
}
V_70 [ 0 ] = V_72 >> 8 ;
V_70 [ 1 ] = V_72 & 0xff ;
return 1 ;
}
