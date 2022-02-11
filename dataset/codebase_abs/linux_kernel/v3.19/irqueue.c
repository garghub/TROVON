static T_1 F_1 ( const char * V_1 )
{
T_1 V_2 = 0 ;
T_1 V_3 ;
while( * V_1 ) {
V_2 = ( V_2 << 4 ) + * V_1 ++ ;
if ( ( V_3 = ( V_2 & 0xf0000000 ) ) )
V_2 ^= V_3 >> 24 ;
V_2 &= ~ V_3 ;
}
return V_2 ;
}
static void F_2 ( T_2 * * V_4 , T_2 * V_5 )
{
if ( * V_4 == NULL ) {
V_5 -> V_6 = V_5 -> V_7 = * V_4 = V_5 ;
} else {
V_5 -> V_6 = ( * V_4 ) ;
( * V_4 ) -> V_7 -> V_6 = V_5 ;
V_5 -> V_7 = ( * V_4 ) -> V_7 ;
( * V_4 ) -> V_7 = V_5 ;
( * V_4 ) = V_5 ;
}
}
static T_2 * F_3 ( T_2 * * V_4 )
{
T_2 * V_8 ;
F_4 ( L_1 ) ;
V_8 = * V_4 ;
if ( * V_4 == NULL ) {
} else if ( ( * V_4 ) -> V_6 == * V_4 ) {
* V_4 = NULL ;
} else {
( * V_4 ) -> V_7 -> V_6 = ( * V_4 ) -> V_6 ;
( * V_4 ) -> V_6 -> V_7 = ( * V_4 ) -> V_7 ;
* V_4 = ( * V_4 ) -> V_6 ;
}
return V_8 ;
}
static T_2 * F_5 ( T_2 * * V_4 , T_2 * V_5 )
{
T_2 * V_8 ;
F_4 ( L_2 ) ;
V_8 = * V_4 ;
if ( * V_4 == NULL ) {
} else if ( ( * V_4 ) -> V_6 == * V_4 ) {
* V_4 = NULL ;
} else {
V_5 -> V_7 -> V_6 = V_5 -> V_6 ;
V_5 -> V_6 -> V_7 = V_5 -> V_7 ;
if ( ( * V_4 ) == V_5 )
( * V_4 ) = V_5 -> V_6 ;
}
return V_8 ;
}
T_3 * F_6 ( int type )
{
T_3 * V_9 ;
V_9 = F_7 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_11 = type ;
V_9 -> V_12 = V_13 ;
if ( V_9 -> V_11 & V_14 ) {
F_8 ( & V_9 -> V_15 ) ;
}
return V_9 ;
}
int F_9 ( T_3 * V_9 , T_4 V_16 )
{
T_2 * V_4 ;
unsigned long V_17 = 0 ;
int V_18 ;
F_10 (hashbin != NULL, return -1;) ;
F_10 (hashbin->magic == HB_MAGIC, return -1;) ;
if ( V_9 -> V_11 & V_14 ) {
F_11 ( & V_9 -> V_15 , V_17 ,
V_19 ++ ) ;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_4 = F_3 ( ( T_2 * * ) & V_9 -> V_21 [ V_18 ] ) ;
while ( V_4 ) {
if ( V_16 )
(* V_16)( V_4 ) ;
V_4 = F_3 (
( T_2 * * ) & V_9 -> V_21 [ V_18 ] ) ;
}
}
V_9 -> V_22 = NULL ;
V_9 -> V_12 = ~ V_13 ;
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
#ifdef F_13
V_19 -- ;
#endif
}
F_14 ( V_9 ) ;
return 0 ;
}
void F_15 ( T_3 * V_9 , T_2 * V_23 , long V_24 ,
const char * V_1 )
{
unsigned long V_17 = 0 ;
int V_25 ;
F_10 ( hashbin != NULL, return;) ;
F_10 ( hashbin->magic == HB_MAGIC, return;) ;
if ( V_1 )
V_24 = F_1 ( V_1 ) ;
V_25 = F_16 ( V_24 ) ;
if ( V_9 -> V_11 & V_14 ) {
F_17 ( & V_9 -> V_15 , V_17 ) ;
}
V_23 -> V_26 = V_24 ;
if ( V_1 )
F_18 ( V_23 -> V_27 , V_1 , sizeof( V_23 -> V_27 ) ) ;
F_2 ( ( T_2 * * ) & V_9 -> V_21 [ V_25 ] ,
V_23 ) ;
V_9 -> V_28 ++ ;
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
}
void * F_19 ( T_3 * V_9 )
{
unsigned long V_17 = 0 ;
T_2 * V_23 = NULL ;
if ( V_9 -> V_11 & V_14 ) {
F_17 ( & V_9 -> V_15 , V_17 ) ;
}
V_23 = F_20 ( V_9 ) ;
if ( V_23 != NULL ) {
int V_25 ;
long V_24 ;
V_24 = V_23 -> V_26 ;
V_25 = F_16 ( V_24 ) ;
F_5 ( ( T_2 * * ) & V_9 -> V_21 [ V_25 ] ,
V_23 ) ;
V_9 -> V_28 -- ;
V_23 -> V_6 = NULL ;
V_23 -> V_7 = NULL ;
if ( V_23 == V_9 -> V_22 )
V_9 -> V_22 = NULL ;
}
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
return V_23 ;
}
void * F_21 ( T_3 * V_9 , long V_24 , const char * V_1 )
{
int V_25 , V_29 = FALSE ;
unsigned long V_17 = 0 ;
T_2 * V_23 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_1 )
V_24 = F_1 ( V_1 ) ;
V_25 = F_16 ( V_24 ) ;
if ( V_9 -> V_11 & V_14 ) {
F_17 ( & V_9 -> V_15 , V_17 ) ;
}
V_23 = V_9 -> V_21 [ V_25 ] ;
if ( V_23 ) {
do {
if ( V_23 -> V_26 == V_24 ) {
if ( V_1 ) {
if ( strcmp ( V_23 -> V_27 , V_1 ) == 0 )
{
V_29 = TRUE ;
break;
}
} else {
V_29 = TRUE ;
break;
}
}
V_23 = V_23 -> V_6 ;
} while ( V_23 != V_9 -> V_21 [ V_25 ] );
}
if ( V_29 ) {
F_5 ( ( T_2 * * ) & V_9 -> V_21 [ V_25 ] ,
V_23 ) ;
V_9 -> V_28 -- ;
if ( V_23 == V_9 -> V_22 )
V_9 -> V_22 = NULL ;
}
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
if ( V_29 )
return V_23 ;
else
return NULL ;
}
void * F_22 ( T_3 * V_9 , T_2 * V_23 )
{
unsigned long V_17 = 0 ;
int V_25 ;
long V_24 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
F_10 ( entry != NULL, return NULL;) ;
if ( V_9 -> V_11 & V_14 ) {
F_17 ( & V_9 -> V_15 , V_17 ) ;
}
if( ( V_23 -> V_6 == NULL ) || ( V_23 -> V_7 == NULL ) ) {
V_23 = NULL ;
goto V_30;
}
V_24 = V_23 -> V_26 ;
V_25 = F_16 ( V_24 ) ;
F_5 ( ( T_2 * * ) & V_9 -> V_21 [ V_25 ] ,
V_23 ) ;
V_9 -> V_28 -- ;
V_23 -> V_6 = NULL ;
V_23 -> V_7 = NULL ;
if ( V_23 == V_9 -> V_22 )
V_9 -> V_22 = NULL ;
V_30:
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
return V_23 ;
}
void * F_23 ( T_3 * V_9 , long V_24 , const char * V_1 )
{
int V_25 ;
T_2 * V_23 ;
F_4 ( L_3 ) ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_1 )
V_24 = F_1 ( V_1 ) ;
V_25 = F_16 ( V_24 ) ;
V_23 = V_9 -> V_21 [ V_25 ] ;
if ( V_23 ) {
do {
if ( V_23 -> V_26 == V_24 ) {
if ( V_1 ) {
if ( strcmp ( V_23 -> V_27 , V_1 ) == 0 ) {
return V_23 ;
}
} else {
return V_23 ;
}
}
V_23 = V_23 -> V_6 ;
} while ( V_23 != V_9 -> V_21 [ V_25 ] );
}
return NULL ;
}
void * F_24 ( T_3 * V_9 , long V_24 , const char * V_1 )
{
unsigned long V_17 = 0 ;
T_2 * V_23 ;
F_17 ( & V_9 -> V_15 , V_17 ) ;
V_23 = F_23 ( V_9 , V_24 , V_1 ) ;
F_12 ( & V_9 -> V_15 , V_17 ) ;
return V_23 ;
}
void * F_25 ( T_3 * V_9 , long V_24 , const char * V_1 ,
void * * V_31 )
{
unsigned long V_17 = 0 ;
T_2 * V_23 ;
F_17 ( & V_9 -> V_15 , V_17 ) ;
V_23 = F_23 ( V_9 , V_24 , V_1 ) ;
if( V_23 ) {
V_9 -> V_22 = V_23 ;
* V_31 = F_26 ( V_9 ) ;
} else
* V_31 = NULL ;
F_12 ( & V_9 -> V_15 , V_17 ) ;
return V_23 ;
}
T_2 * F_20 ( T_3 * V_9 )
{
T_2 * V_23 ;
int V_18 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_9 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_23 = V_9 -> V_21 [ V_18 ] ;
if ( V_23 ) {
V_9 -> V_22 = V_23 ;
return V_23 ;
}
}
return NULL ;
}
T_2 * F_26 ( T_3 * V_9 )
{
T_2 * V_23 ;
int V_25 ;
int V_18 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_9 -> V_22 == NULL ) {
F_10 ( hashbin->hb_current != NULL, return NULL;) ;
return NULL ;
}
V_23 = V_9 -> V_22 -> V_6 ;
V_25 = F_16 ( V_23 -> V_26 ) ;
if ( V_23 != V_9 -> V_21 [ V_25 ] ) {
V_9 -> V_22 = V_23 ;
return V_23 ;
}
if ( V_25 >= V_20 )
return NULL ;
V_25 ++ ;
for ( V_18 = V_25 ; V_18 < V_20 ; V_18 ++ ) {
V_23 = V_9 -> V_21 [ V_18 ] ;
if ( V_23 ) {
V_9 -> V_22 = V_23 ;
return V_23 ;
}
}
return NULL ;
}
