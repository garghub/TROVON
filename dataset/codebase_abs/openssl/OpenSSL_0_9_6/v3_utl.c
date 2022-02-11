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
V_12 = F_11 () ;
if( ! V_3 ) {
F_6 ( V_14 , V_15 ) ;
return 0 ;
}
if( ! F_12 ( & V_12 , V_3 ) ) {
F_6 ( V_14 , V_16 ) ;
return 0 ;
}
if( ! ( V_13 = F_13 ( V_12 , NULL ) ) ) {
F_6 ( V_14 , V_17 ) ;
return 0 ;
}
F_7 ( V_12 ) ;
return V_13 ;
}
int F_14 ( T_1 * V_3 , int * V_18 )
{
char * V_19 ;
if( ! ( V_19 = V_3 -> V_3 ) ) goto V_20;
if( ! strcmp ( V_19 , L_1 ) || ! strcmp ( V_19 , L_2 )
|| ! strcmp ( V_19 , L_3 ) || ! strcmp ( V_19 , L_4 )
|| ! strcmp ( V_19 , L_5 ) || ! strcmp ( V_19 , L_6 ) ) {
* V_18 = 0xff ;
return 1 ;
} else if( ! strcmp ( V_19 , L_7 ) || ! strcmp ( V_19 , L_8 )
|| ! strcmp ( V_19 , L_9 ) || ! strcmp ( V_19 , L_10 )
|| ! strcmp ( V_19 , L_11 ) || ! strcmp ( V_19 , L_12 ) ) {
* V_18 = 0 ;
return 1 ;
}
V_20:
F_6 ( V_21 , V_22 ) ;
F_15 ( V_3 ) ;
return 0 ;
}
int F_16 ( T_1 * V_3 , T_5 * * V_13 )
{
T_5 * V_23 ;
if( ! ( V_23 = F_10 ( NULL , V_3 -> V_3 ) ) ) {
F_15 ( V_3 ) ;
return 0 ;
}
* V_13 = V_23 ;
return 1 ;
}
char * F_17 ( char * V_2 )
{
char * V_24 , * V_25 ;
V_24 = V_2 ;
while( * V_24 && isspace ( ( unsigned char ) * V_24 ) ) V_24 ++ ;
if( ! * V_24 ) return NULL ;
V_25 = V_24 + strlen ( V_24 ) - 1 ;
while( ( V_25 != V_24 ) && isspace ( ( unsigned char ) * V_25 ) ) V_25 -- ;
if( V_24 != V_25 ) V_25 [ 1 ] = 0 ;
if( ! * V_24 ) return NULL ;
return V_24 ;
}
char * F_18 ( unsigned char * V_26 , long V_27 )
{
char * V_28 , * V_25 ;
unsigned char * V_24 ;
int V_29 ;
static char V_30 [] = L_13 ;
if( ! V_26 || ! V_27 ) return NULL ;
if( ! ( V_28 = F_19 ( V_27 * 3 + 1 ) ) ) {
F_6 ( V_31 , V_10 ) ;
return NULL ;
}
V_25 = V_28 ;
for( V_29 = 0 , V_24 = V_26 ; V_29 < V_27 ; V_29 ++ , V_24 ++ ) {
* V_25 ++ = V_30 [ ( * V_24 >> 4 ) & 0xf ] ;
* V_25 ++ = V_30 [ * V_24 & 0xf ] ;
* V_25 ++ = ':' ;
}
V_25 [ - 1 ] = 0 ;
#ifdef F_20
F_21 ( V_28 , V_28 , V_25 - V_28 - 1 ) ;
#endif
return V_28 ;
}
unsigned char * F_22 ( char * V_32 , long * V_27 )
{
unsigned char * V_33 , * V_25 ;
unsigned char V_34 , V_35 , * V_24 ;
if( ! V_32 ) {
F_6 ( V_36 , V_37 ) ;
return NULL ;
}
if( ! ( V_33 = F_19 ( strlen ( V_32 ) >> 1 ) ) ) goto V_20;
for( V_24 = ( unsigned char * ) V_32 , V_25 = V_33 ; * V_24 ; ) {
V_34 = * V_24 ++ ;
#ifdef F_20
V_34 = V_38 [ V_34 ] ;
#endif
if( V_34 == ':' ) continue;
V_35 = * V_24 ++ ;
#ifdef F_20
V_35 = V_38 [ V_35 ] ;
#endif
if( ! V_35 ) {
F_6 ( V_36 , V_39 ) ;
F_2 ( V_33 ) ;
return NULL ;
}
if( isupper ( V_34 ) ) V_34 = tolower ( V_34 ) ;
if( isupper ( V_35 ) ) V_35 = tolower ( V_35 ) ;
if( ( V_34 >= '0' ) && ( V_34 <= '9' ) ) V_34 -= '0' ;
else if ( ( V_34 >= 'a' ) && ( V_34 <= 'f' ) ) V_34 -= 'a' - 10 ;
else goto V_40;
if( ( V_35 >= '0' ) && ( V_35 <= '9' ) ) V_35 -= '0' ;
else if ( ( V_35 >= 'a' ) && ( V_35 <= 'f' ) ) V_35 -= 'a' - 10 ;
else goto V_40;
* V_25 ++ = ( V_34 << 4 ) | V_35 ;
}
if( V_27 ) * V_27 = V_25 - V_33 ;
return V_33 ;
V_20:
if( V_33 ) F_2 ( V_33 ) ;
F_6 ( V_36 , V_10 ) ;
return NULL ;
V_40:
F_2 ( V_33 ) ;
F_6 ( V_36 , V_41 ) ;
return NULL ;
}
int F_23 ( const char * V_2 , const char * V_42 )
{
int V_27 , V_43 ;
char V_44 ;
V_27 = strlen ( V_42 ) ;
if( ( V_43 = strncmp ( V_2 , V_42 , V_27 ) ) ) return V_43 ;
V_44 = V_2 [ V_27 ] ;
if( ! V_44 || ( V_44 == '.' ) ) return 0 ;
return 1 ;
}
static int F_24 ( const char * const * V_6 , const char * const * V_45 )
{
return strcmp ( * V_6 , * V_45 ) ;
}
T_6 * F_25 ( T_7 * V_46 )
{
F_26 ( V_47 ) * V_48 ;
T_6 * V_43 ;
V_48 = F_27 ( V_46 , V_49 , NULL , NULL ) ;
V_43 = F_28 ( F_29 ( V_46 ) , V_48 ) ;
F_30 ( V_48 , V_50 ) ;
return V_43 ;
}
T_6 * F_31 ( T_8 * V_46 )
{
F_26 ( V_47 ) * V_48 ;
F_26 ( V_51 ) * V_52 ;
T_6 * V_43 ;
V_52 = F_32 ( V_46 ) ;
V_48 = F_33 ( V_52 , V_49 , NULL , NULL ) ;
V_43 = F_28 ( F_34 ( V_46 ) , V_48 ) ;
F_30 ( V_48 , V_50 ) ;
F_35 ( V_52 , V_53 ) ;
return V_43 ;
}
static void F_36 ( void * V_32 )
{
F_2 ( V_32 ) ;
}
static int F_37 ( T_6 * * V_54 , T_9 * V_55 )
{
char * V_56 ;
if( V_55 -> type != V_57 ) return 1 ;
if( ! V_55 -> V_58 || ! V_55 -> V_59 ) return 1 ;
if( ! * V_54 ) * V_54 = F_38 ( F_24 ) ;
if( ! * V_54 ) return 0 ;
if( F_39 ( * V_54 , ( char * ) V_55 -> V_58 ) != - 1 ) return 1 ;
V_56 = F_40 ( ( char * ) V_55 -> V_58 ) ;
if( ! V_56 || ! F_41 ( * V_54 , V_56 ) ) {
F_42 ( * V_54 ) ;
* V_54 = NULL ;
return 0 ;
}
return 1 ;
}
void F_42 ( T_6 * V_54 )
{
F_43 ( V_54 , F_36 ) ;
}
