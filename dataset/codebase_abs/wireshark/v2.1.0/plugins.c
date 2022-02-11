void
F_1 ( const char * type , T_1 V_1 )
{
T_2 * V_2 ;
static T_3 V_3 ;
if ( V_3 >= 32 ) {
F_2 ( L_1 ,
type ) ;
return;
}
V_2 = ( T_2 * ) F_3 ( sizeof ( T_2 ) ) ;
V_2 -> type = type ;
V_2 -> V_1 = V_1 ;
V_2 -> V_3 = V_3 ;
V_4 = F_4 ( V_4 , V_2 ) ;
V_3 ++ ;
}
static int
F_5 ( T_4 * V_5 )
{
T_4 * V_6 ;
V_6 = V_7 ;
if ( ! V_6 )
{
V_7 = V_5 ;
}
else
{
while ( 1 )
{
if ( strcmp ( V_6 -> V_8 , V_5 -> V_8 ) == 0 &&
strcmp ( V_6 -> V_9 , V_5 -> V_9 ) == 0 )
{
return V_10 ;
}
if ( V_6 -> V_11 == NULL )
break;
V_6 = V_6 -> V_11 ;
}
V_6 -> V_11 = V_5 ;
}
return 0 ;
}
static void
F_6 ( T_5 V_12 , T_5 V_13 )
{
T_2 * type = ( T_2 * ) V_12 ;
T_4 * V_5 = ( T_4 * ) V_13 ;
if ( (* type -> V_1 )( V_5 -> V_14 ) ) {
V_5 -> V_15 |= 1 << type -> V_3 ;
}
}
static void
F_7 ( const char * V_16 )
{
#define F_8 1024
T_6 * V_17 ;
T_7 * V_18 ;
const char * V_8 ;
T_8 V_19 [ F_8 ] ;
T_9 * V_14 ;
T_5 V_20 ;
T_4 * V_5 ;
T_8 * V_21 ;
int V_22 ;
if ( ( V_17 = F_9 ( V_16 , 0 , NULL ) ) != NULL )
{
while ( ( V_18 = F_10 ( V_17 ) ) != NULL )
{
V_8 = F_11 ( V_18 ) ;
V_21 = strrchr ( V_8 , '.' ) ;
if ( V_21 == NULL || strcmp ( V_21 + 1 , V_23 ) != 0 )
continue;
F_12 ( V_19 , F_8 , L_2 V_24 L_2 ,
V_16 , V_8 ) ;
if ( ( V_14 = F_13 ( V_19 , V_25 ) ) == NULL )
{
F_2 ( L_3 , V_19 ,
F_14 () ) ;
continue;
}
if ( ! F_15 ( V_14 , L_4 , & V_20 ) )
{
F_2 ( L_5 , V_8 ) ;
F_16 ( V_14 ) ;
continue;
}
V_5 = ( T_4 * ) F_3 ( sizeof( T_4 ) ) ;
V_5 -> V_14 = V_14 ;
V_5 -> V_8 = F_17 ( V_8 ) ;
V_5 -> V_9 = ( char * ) V_20 ;
V_5 -> V_15 = 0 ;
V_5 -> V_11 = NULL ;
F_18 ( V_4 , F_6 , V_5 ) ;
if ( V_5 -> V_15 == 0 )
{
F_2 ( L_6 ,
V_8 ) ;
F_16 ( V_14 ) ;
F_19 ( V_5 -> V_8 ) ;
F_19 ( V_5 ) ;
continue;
}
V_22 = F_5 ( V_5 ) ;
if ( V_22 != 0 )
{
F_20 ( V_22 == V_10 ) ;
fprintf ( V_26 , L_7
L_8 ,
V_5 -> V_8 , V_5 -> V_9 ) ;
F_16 ( V_14 ) ;
F_19 ( V_5 -> V_8 ) ;
F_19 ( V_5 ) ;
continue;
}
}
F_21 ( V_17 ) ;
}
}
void
F_22 ( void )
{
const char * V_27 ;
const char * V_8 ;
char * V_28 ;
char * V_29 ;
T_6 * V_17 ;
T_7 * V_18 ;
if ( V_7 == NULL )
{
V_27 = F_23 () ;
if ( F_24 () )
{
if ( ( V_17 = F_9 ( V_27 , 0 , NULL ) ) != NULL )
{
F_7 ( V_27 ) ;
while ( ( V_18 = F_10 ( V_17 ) ) != NULL )
{
V_8 = F_11 ( V_18 ) ;
if ( strcmp ( V_8 , L_9 ) == 0 || strcmp ( V_8 , L_10 ) == 0 )
continue;
V_28 = F_25 (
L_2 V_24 L_2 V_24 L_11 ,
V_27 , V_8 ) ;
if ( F_26 ( V_28 ) != V_30 ) {
F_19 ( V_28 ) ;
V_28 = F_25 ( L_2 V_24 L_2 ,
V_27 , V_8 ) ;
}
F_7 ( V_28 ) ;
F_19 ( V_28 ) ;
}
F_21 ( V_17 ) ;
}
}
else
F_7 ( V_27 ) ;
if ( ! F_27 () )
{
V_29 = F_28 () ;
F_7 ( V_29 ) ;
F_19 ( V_29 ) ;
}
}
}
static void
F_29 ( T_5 V_12 , T_5 V_13 )
{
T_2 * type = ( T_2 * ) V_12 ;
T_10 * V_31 = ( T_10 * ) V_13 ;
if ( V_31 -> V_6 -> V_15 & ( 1 << type -> V_3 ) ) {
F_30 ( V_31 -> V_15 , L_12 , V_31 -> V_32 , type -> type ) ;
V_31 -> V_32 = L_13 ;
}
}
T_11 void
F_31 ( T_12 V_1 , void * V_13 )
{
T_10 V_31 ;
V_31 . V_15 = NULL ;
for ( V_31 . V_6 = V_7 ; V_31 . V_6 != NULL ;
V_31 . V_6 = V_31 . V_6 -> V_11 )
{
V_31 . V_32 = L_14 ;
V_31 . V_15 = F_32 ( L_14 ) ;
F_18 ( V_4 , F_29 , & V_31 ) ;
V_1 ( V_31 . V_6 -> V_8 , V_31 . V_6 -> V_9 , V_31 . V_15 -> V_33 ,
F_33 ( V_31 . V_6 -> V_14 ) , V_13 ) ;
F_34 ( V_31 . V_15 , TRUE ) ;
}
}
static void
F_35 ( const char * V_8 , const char * V_9 ,
const char * V_34 , const char * V_19 ,
void * V_13 V_35 )
{
printf ( L_15 , V_8 , V_9 , V_34 , V_19 ) ;
}
void
F_36 ( void )
{
F_31 ( F_35 , NULL ) ;
}
