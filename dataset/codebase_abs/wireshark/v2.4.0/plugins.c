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
F_7 ( const char * V_16 , T_6 V_17 )
{
#define F_8 1024
T_7 * V_18 ;
T_8 * V_19 ;
const char * V_8 ;
T_9 V_20 [ F_8 ] ;
T_10 * V_14 ;
T_5 V_21 ;
T_4 * V_5 ;
T_9 * V_22 ;
int V_23 ;
if ( ! F_9 ( V_16 , V_24 ) || ! F_9 ( V_16 , V_25 ) ) {
return;
}
if ( ( V_18 = F_10 ( V_16 , 0 , NULL ) ) != NULL )
{
while ( ( V_19 = F_11 ( V_18 ) ) != NULL )
{
V_8 = F_12 ( V_19 ) ;
V_22 = strrchr ( V_8 , '.' ) ;
if ( V_22 == NULL || strcmp ( V_22 + 1 , V_26 ) != 0 )
continue;
#if V_27
if ( strncmp ( V_8 , L_2 , 14 ) == 0 )
continue;
#endif
F_13 ( V_20 , F_8 , L_3 V_28 L_3 ,
V_16 , V_8 ) ;
if ( ( V_14 = F_14 ( V_20 , V_29 ) ) == NULL )
{
if ( V_17 == V_30 ) {
F_2 ( L_4 , V_20 ,
F_15 () ) ;
}
continue;
}
if ( ! F_16 ( V_14 , L_5 , & V_21 ) )
{
F_2 ( L_6 , V_8 ) ;
F_17 ( V_14 ) ;
continue;
}
V_5 = ( T_4 * ) F_3 ( sizeof( T_4 ) ) ;
V_5 -> V_14 = V_14 ;
V_5 -> V_8 = F_18 ( V_8 ) ;
V_5 -> V_9 = ( char * ) V_21 ;
V_5 -> V_15 = 0 ;
V_5 -> V_11 = NULL ;
F_19 ( V_4 , F_6 , V_5 ) ;
if ( V_5 -> V_15 == 0 )
{
if ( V_17 == V_30 ) {
F_2 ( L_7 ,
V_8 ) ;
}
F_17 ( V_14 ) ;
F_20 ( V_5 -> V_8 ) ;
F_20 ( V_5 ) ;
continue;
}
V_23 = F_5 ( V_5 ) ;
if ( V_23 != 0 )
{
F_21 ( V_23 == V_10 ) ;
fprintf ( V_31 , L_8
L_9 ,
V_5 -> V_8 , V_5 -> V_9 ) ;
F_17 ( V_14 ) ;
F_20 ( V_5 -> V_8 ) ;
F_20 ( V_5 ) ;
continue;
}
}
F_22 ( V_18 ) ;
}
}
void
F_23 ( T_6 V_17 )
{
const char * V_32 ;
const char * V_8 ;
char * V_33 ;
char * V_34 ;
T_7 * V_18 ;
T_8 * V_19 ;
if ( V_7 == NULL )
{
V_32 = F_24 () ;
if ( V_32 == NULL )
{
return;
}
if ( F_25 () )
{
if ( ( V_18 = F_10 ( V_32 , 0 , NULL ) ) != NULL )
{
F_7 ( V_32 , V_17 ) ;
while ( ( V_19 = F_11 ( V_18 ) ) != NULL )
{
V_8 = F_12 ( V_19 ) ;
if ( strcmp ( V_8 , L_10 ) == 0 || strcmp ( V_8 , L_11 ) == 0 )
continue;
V_33 = F_26 (
L_3 V_28 L_3 V_28 L_12 ,
V_32 , V_8 ) ;
if ( F_27 ( V_33 ) != V_35 ) {
F_20 ( V_33 ) ;
V_33 = F_26 ( L_3 V_28 L_3 ,
V_32 , V_8 ) ;
}
F_7 ( V_33 , V_17 ) ;
F_20 ( V_33 ) ;
}
F_22 ( V_18 ) ;
}
}
else
F_7 ( V_32 , V_17 ) ;
if ( ! F_28 () )
{
V_34 = F_29 () ;
F_7 ( V_34 , V_17 ) ;
F_20 ( V_34 ) ;
}
}
}
static void
F_30 ( T_5 V_12 , T_5 V_13 )
{
T_2 * type = ( T_2 * ) V_12 ;
T_11 * V_36 = ( T_11 * ) V_13 ;
if ( V_36 -> V_6 -> V_15 & ( 1 << type -> V_3 ) ) {
F_31 ( V_36 -> V_15 , L_13 , V_36 -> V_37 , type -> type ) ;
V_36 -> V_37 = L_14 ;
}
}
T_12 void
F_32 ( T_13 V_1 , void * V_13 )
{
T_11 V_36 ;
V_36 . V_15 = NULL ;
for ( V_36 . V_6 = V_7 ; V_36 . V_6 != NULL ;
V_36 . V_6 = V_36 . V_6 -> V_11 )
{
V_36 . V_37 = L_15 ;
V_36 . V_15 = F_33 ( L_15 ) ;
F_19 ( V_4 , F_30 , & V_36 ) ;
V_1 ( V_36 . V_6 -> V_8 , V_36 . V_6 -> V_9 , V_36 . V_15 -> V_38 ,
F_34 ( V_36 . V_6 -> V_14 ) , V_13 ) ;
F_35 ( V_36 . V_15 , TRUE ) ;
}
}
static void
F_36 ( const char * V_8 , const char * V_9 ,
const char * V_39 , const char * V_20 ,
void * V_13 V_40 )
{
F_37 ( L_16 , V_8 , V_9 , V_39 , V_20 ) ;
}
void
F_38 ( void )
{
F_32 ( F_36 , NULL ) ;
}
static void
F_39 ( T_5 V_41 , T_5 V_13 V_40 )
{
F_20 ( V_41 ) ;
}
void
F_40 ( void )
{
T_4 * V_42 , * V_11 ;
for ( V_42 = V_7 ; V_42 != NULL ; V_42 = V_11 ) {
V_11 = V_42 -> V_11 ;
F_20 ( V_42 -> V_8 ) ;
F_20 ( V_42 ) ;
}
F_19 ( V_4 , F_39 , NULL ) ;
F_41 ( V_4 ) ;
}
