int F_1 ( const char * V_1 , const char * V_2 , T_1 * * V_3 )
{
T_2 * V_4 = NULL ;
char * V_5 = NULL , * V_6 = NULL ;
if( V_1 && ! ( V_5 = F_2 ( V_1 ) ) ) goto V_7;
if( V_2 && ! ( V_6 = F_2 ( V_2 ) ) ) goto V_7; ;
if( ! ( V_4 = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ) ) goto V_7;
if( ! * V_3 && ! ( * V_3 = F_3 ( NULL ) ) ) goto V_7;
V_4 -> V_8 = NULL ;
V_4 -> V_1 = V_5 ;
V_4 -> V_2 = V_6 ;
if( ! F_4 ( * V_3 , ( char * ) V_4 ) ) goto V_7;
return 1 ;
V_7:
F_5 ( V_9 , V_10 ) ;
if( V_4 ) Free ( V_4 ) ;
if( V_5 ) Free ( V_5 ) ;
if( V_6 ) Free ( V_6 ) ;
return 0 ;
}
int F_6 ( const char * V_1 , const unsigned char * V_2 ,
T_1 * * V_3 )
{
return F_1 ( V_1 , ( const char * ) V_2 , V_3 ) ;
}
void F_7 ( T_2 * V_11 )
{
if( ! V_11 ) return;
if( V_11 -> V_1 ) Free ( V_11 -> V_1 ) ;
if( V_11 -> V_2 ) Free ( V_11 -> V_2 ) ;
if( V_11 -> V_8 ) Free ( V_11 -> V_8 ) ;
Free ( ( char * ) V_11 ) ;
}
int F_8 ( const char * V_1 , int V_12 , T_1 * * V_3 )
{
if( V_12 ) return F_1 ( V_1 , L_1 , V_3 ) ;
return F_1 ( V_1 , L_2 , V_3 ) ;
}
int F_9 ( char * V_1 , int V_12 , T_1 * * V_3 )
{
if( V_12 ) return F_1 ( V_1 , L_1 , V_3 ) ;
return 1 ;
}
char * F_10 ( T_3 * V_13 , T_4 * V_14 )
{
T_5 * V_15 = NULL ;
char * V_16 = NULL ;
if( ! V_14 ) return NULL ;
if( ! ( V_15 = F_11 ( V_14 , NULL ) ) ||
! ( V_16 = F_12 ( V_15 ) ) )
F_5 ( V_17 , V_10 ) ;
F_13 ( V_15 ) ;
return V_16 ;
}
char * F_14 ( T_3 * V_13 , T_6 * V_14 )
{
T_5 * V_15 = NULL ;
char * V_16 = NULL ;
if( ! V_14 ) return NULL ;
if( ! ( V_15 = F_15 ( V_14 , NULL ) ) ||
! ( V_16 = F_12 ( V_15 ) ) )
F_5 ( V_18 , V_10 ) ;
F_13 ( V_15 ) ;
return V_16 ;
}
T_6 * F_16 ( T_3 * V_13 , char * V_2 )
{
T_5 * V_19 = NULL ;
T_6 * V_20 ;
V_19 = F_17 () ;
if( ! V_2 ) {
F_5 ( V_21 , V_22 ) ;
return 0 ;
}
if( ! F_18 ( & V_19 , V_2 ) ) {
F_5 ( V_21 , V_23 ) ;
return 0 ;
}
if( ! ( V_20 = F_19 ( V_19 , NULL ) ) ) {
F_5 ( V_21 , V_24 ) ;
return 0 ;
}
F_13 ( V_19 ) ;
return V_20 ;
}
int F_20 ( const char * V_1 , T_6 * V_20 ,
T_1 * * V_3 )
{
char * V_16 ;
int V_25 ;
if( ! V_20 ) return 1 ;
if( ! ( V_16 = F_14 ( NULL , V_20 ) ) ) return 0 ;
V_25 = F_1 ( V_1 , V_16 , V_3 ) ;
Free ( V_16 ) ;
return V_25 ;
}
int F_21 ( T_2 * V_2 , int * V_12 )
{
char * V_26 ;
if( ! ( V_26 = V_2 -> V_2 ) ) goto V_7;
if( ! strcmp ( V_26 , L_1 ) || ! strcmp ( V_26 , L_3 )
|| ! strcmp ( V_26 , L_4 ) || ! strcmp ( V_26 , L_5 )
|| ! strcmp ( V_26 , L_6 ) || ! strcmp ( V_26 , L_7 ) ) {
* V_12 = 0xff ;
return 1 ;
} else if( ! strcmp ( V_26 , L_2 ) || ! strcmp ( V_26 , L_8 )
|| ! strcmp ( V_26 , L_9 ) || ! strcmp ( V_26 , L_10 )
|| ! strcmp ( V_26 , L_11 ) || ! strcmp ( V_26 , L_12 ) ) {
* V_12 = 0 ;
return 1 ;
}
V_7:
F_5 ( V_27 , V_28 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
int F_23 ( T_2 * V_2 , T_6 * * V_20 )
{
T_6 * V_29 ;
if( ! ( V_29 = F_16 ( NULL , V_2 -> V_2 ) ) ) {
F_22 ( V_2 ) ;
return 0 ;
}
* V_20 = V_29 ;
return 1 ;
}
T_1 * F_24 ( char * line )
{
char * V_30 , * V_31 , V_32 ;
char * V_33 , * V_4 ;
T_1 * V_34 = NULL ;
char * V_35 ;
int V_36 ;
V_35 = F_2 ( line ) ;
V_36 = V_37 ;
V_33 = NULL ;
for( V_30 = V_35 , V_31 = V_35 ; ( V_32 = * V_30 ) && ( V_32 != '\r' ) && ( V_32 != '\n' ) ; V_30 ++ ) {
switch( V_36 ) {
case V_37 :
if( V_32 == ':' ) {
V_36 = V_38 ;
* V_30 = 0 ;
V_33 = F_25 ( V_31 ) ;
if( ! V_33 ) {
F_5 ( V_39 , V_40 ) ;
goto V_7;
}
V_31 = V_30 + 1 ;
} else if( V_32 == ',' ) {
* V_30 = 0 ;
V_33 = F_25 ( V_31 ) ;
V_31 = V_30 + 1 ;
#ifdef F_26
printf ( L_13 , V_33 ) ;
#endif
if( ! V_33 ) {
F_5 ( V_39 , V_40 ) ;
goto V_7;
}
F_1 ( V_33 , NULL , & V_34 ) ;
}
break ;
case V_38 :
if( V_32 == ',' ) {
V_36 = V_37 ;
* V_30 = 0 ;
V_4 = F_25 ( V_31 ) ;
#ifdef F_26
printf ( L_13 , V_33 ) ;
#endif
if( ! V_4 ) {
F_5 ( V_39 , V_22 ) ;
goto V_7;
}
F_1 ( V_33 , V_4 , & V_34 ) ;
V_33 = NULL ;
V_31 = V_30 + 1 ;
}
}
}
if( V_36 == V_38 ) {
V_4 = F_25 ( V_31 ) ;
#ifdef F_26
printf ( L_14 , V_33 , V_4 ) ;
#endif
if( ! V_4 ) {
F_5 ( V_39 , V_22 ) ;
goto V_7;
}
F_1 ( V_33 , V_4 , & V_34 ) ;
} else {
V_33 = F_25 ( V_31 ) ;
#ifdef F_26
printf ( L_13 , V_33 ) ;
#endif
if( ! V_33 ) {
F_5 ( V_39 , V_40 ) ;
goto V_7;
}
F_1 ( V_33 , NULL , & V_34 ) ;
}
Free ( V_35 ) ;
return V_34 ;
V_7:
Free ( V_35 ) ;
F_27 ( V_34 , F_7 ) ;
return NULL ;
}
static char * F_25 ( char * V_1 )
{
char * V_30 , * V_31 ;
V_30 = V_1 ;
while( * V_30 && isspace ( ( unsigned char ) * V_30 ) ) V_30 ++ ;
if( ! * V_30 ) return NULL ;
V_31 = V_30 + strlen ( V_30 ) - 1 ;
while( ( V_31 != V_30 ) && isspace ( ( unsigned char ) * V_31 ) ) V_31 -- ;
if( V_30 != V_31 ) V_31 [ 1 ] = 0 ;
if( ! * V_30 ) return NULL ;
return V_30 ;
}
char * F_28 ( unsigned char * V_41 , long V_42 )
{
char * V_43 , * V_31 ;
unsigned char * V_30 ;
int V_44 ;
static char V_45 [] = L_15 ;
if( ! V_41 || ! V_42 ) return NULL ;
if( ! ( V_43 = Malloc ( V_42 * 3 + 1 ) ) ) {
F_5 ( V_46 , V_10 ) ;
return NULL ;
}
V_31 = V_43 ;
for( V_44 = 0 , V_30 = V_41 ; V_44 < V_42 ; V_44 ++ , V_30 ++ ) {
* V_31 ++ = V_45 [ ( * V_30 >> 4 ) & 0xf ] ;
* V_31 ++ = V_45 [ * V_30 & 0xf ] ;
* V_31 ++ = ':' ;
}
V_31 [ - 1 ] = 0 ;
return V_43 ;
}
unsigned char * F_29 ( char * V_47 , long * V_42 )
{
unsigned char * V_48 , * V_31 ;
unsigned char V_49 , V_50 , * V_30 ;
if( ! V_47 ) {
F_5 ( V_51 , V_52 ) ;
return NULL ;
}
if( ! ( V_48 = Malloc ( strlen ( V_47 ) >> 1 ) ) ) goto V_7;
for( V_30 = ( unsigned char * ) V_47 , V_31 = V_48 ; * V_30 ; ) {
V_49 = * V_30 ++ ;
if( V_49 == ':' ) continue;
V_50 = * V_30 ++ ;
if( ! V_50 ) {
F_5 ( V_51 , V_53 ) ;
Free ( V_48 ) ;
return NULL ;
}
if( isupper ( V_49 ) ) V_49 = tolower ( V_49 ) ;
if( isupper ( V_50 ) ) V_50 = tolower ( V_50 ) ;
if( ( V_49 >= '0' ) && ( V_49 <= '9' ) ) V_49 -= '0' ;
else if ( ( V_49 >= 'a' ) && ( V_49 <= 'f' ) ) V_49 -= 'a' - 10 ;
else goto V_54;
if( ( V_50 >= '0' ) && ( V_50 <= '9' ) ) V_50 -= '0' ;
else if ( ( V_50 >= 'a' ) && ( V_50 <= 'f' ) ) V_50 -= 'a' - 10 ;
else goto V_54;
* V_31 ++ = ( V_49 << 4 ) | V_50 ;
}
if( V_42 ) * V_42 = V_31 - V_48 ;
return V_48 ;
V_7:
if( V_48 ) Free ( V_48 ) ;
F_5 ( V_51 , V_10 ) ;
return NULL ;
V_54:
Free ( V_48 ) ;
F_5 ( V_51 , V_55 ) ;
return NULL ;
}
int F_30 ( const char * V_1 , const char * V_56 )
{
int V_42 , V_25 ;
char V_32 ;
V_42 = strlen ( V_56 ) ;
if( ( V_25 = strncmp ( V_1 , V_56 , V_42 ) ) ) return V_25 ;
V_32 = V_1 [ V_42 ] ;
if( ! V_32 || ( V_32 == '.' ) ) return 0 ;
return 1 ;
}
