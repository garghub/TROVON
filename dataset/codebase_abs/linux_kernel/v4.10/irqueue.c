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
if ( V_9 -> V_11 & V_14 )
F_11 ( & V_9 -> V_15 , V_17 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
while ( 1 ) {
V_4 = F_3 ( ( T_2 * * ) & V_9 -> V_20 [ V_18 ] ) ;
if ( ! V_4 )
break;
if ( V_16 ) {
if ( V_9 -> V_11 & V_14 )
F_12 ( & V_9 -> V_15 , V_17 ) ;
V_16 ( V_4 ) ;
if ( V_9 -> V_11 & V_14 )
F_11 ( & V_9 -> V_15 , V_17 ) ;
}
}
}
V_9 -> V_21 = NULL ;
V_9 -> V_12 = ~ V_13 ;
if ( V_9 -> V_11 & V_14 )
F_12 ( & V_9 -> V_15 , V_17 ) ;
F_13 ( V_9 ) ;
return 0 ;
}
void F_14 ( T_3 * V_9 , T_2 * V_22 , long V_23 ,
const char * V_1 )
{
unsigned long V_17 = 0 ;
int V_24 ;
F_10 ( hashbin != NULL, return;) ;
F_10 ( hashbin->magic == HB_MAGIC, return;) ;
if ( V_1 )
V_23 = F_1 ( V_1 ) ;
V_24 = F_15 ( V_23 ) ;
if ( V_9 -> V_11 & V_14 ) {
F_11 ( & V_9 -> V_15 , V_17 ) ;
}
V_22 -> V_25 = V_23 ;
if ( V_1 )
F_16 ( V_22 -> V_26 , V_1 , sizeof( V_22 -> V_26 ) ) ;
F_2 ( ( T_2 * * ) & V_9 -> V_20 [ V_24 ] ,
V_22 ) ;
V_9 -> V_27 ++ ;
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
}
void * F_17 ( T_3 * V_9 )
{
unsigned long V_17 = 0 ;
T_2 * V_22 = NULL ;
if ( V_9 -> V_11 & V_14 ) {
F_11 ( & V_9 -> V_15 , V_17 ) ;
}
V_22 = F_18 ( V_9 ) ;
if ( V_22 != NULL ) {
int V_24 ;
long V_23 ;
V_23 = V_22 -> V_25 ;
V_24 = F_15 ( V_23 ) ;
F_5 ( ( T_2 * * ) & V_9 -> V_20 [ V_24 ] ,
V_22 ) ;
V_9 -> V_27 -- ;
V_22 -> V_6 = NULL ;
V_22 -> V_7 = NULL ;
if ( V_22 == V_9 -> V_21 )
V_9 -> V_21 = NULL ;
}
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
return V_22 ;
}
void * F_19 ( T_3 * V_9 , long V_23 , const char * V_1 )
{
int V_24 , V_28 = FALSE ;
unsigned long V_17 = 0 ;
T_2 * V_22 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_1 )
V_23 = F_1 ( V_1 ) ;
V_24 = F_15 ( V_23 ) ;
if ( V_9 -> V_11 & V_14 ) {
F_11 ( & V_9 -> V_15 , V_17 ) ;
}
V_22 = V_9 -> V_20 [ V_24 ] ;
if ( V_22 ) {
do {
if ( V_22 -> V_25 == V_23 ) {
if ( V_1 ) {
if ( strcmp ( V_22 -> V_26 , V_1 ) == 0 )
{
V_28 = TRUE ;
break;
}
} else {
V_28 = TRUE ;
break;
}
}
V_22 = V_22 -> V_6 ;
} while ( V_22 != V_9 -> V_20 [ V_24 ] );
}
if ( V_28 ) {
F_5 ( ( T_2 * * ) & V_9 -> V_20 [ V_24 ] ,
V_22 ) ;
V_9 -> V_27 -- ;
if ( V_22 == V_9 -> V_21 )
V_9 -> V_21 = NULL ;
}
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
if ( V_28 )
return V_22 ;
else
return NULL ;
}
void * F_20 ( T_3 * V_9 , T_2 * V_22 )
{
unsigned long V_17 = 0 ;
int V_24 ;
long V_23 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
F_10 ( entry != NULL, return NULL;) ;
if ( V_9 -> V_11 & V_14 ) {
F_11 ( & V_9 -> V_15 , V_17 ) ;
}
if( ( V_22 -> V_6 == NULL ) || ( V_22 -> V_7 == NULL ) ) {
V_22 = NULL ;
goto V_29;
}
V_23 = V_22 -> V_25 ;
V_24 = F_15 ( V_23 ) ;
F_5 ( ( T_2 * * ) & V_9 -> V_20 [ V_24 ] ,
V_22 ) ;
V_9 -> V_27 -- ;
V_22 -> V_6 = NULL ;
V_22 -> V_7 = NULL ;
if ( V_22 == V_9 -> V_21 )
V_9 -> V_21 = NULL ;
V_29:
if ( V_9 -> V_11 & V_14 ) {
F_12 ( & V_9 -> V_15 , V_17 ) ;
}
return V_22 ;
}
void * F_21 ( T_3 * V_9 , long V_23 , const char * V_1 )
{
int V_24 ;
T_2 * V_22 ;
F_4 ( L_3 ) ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_1 )
V_23 = F_1 ( V_1 ) ;
V_24 = F_15 ( V_23 ) ;
V_22 = V_9 -> V_20 [ V_24 ] ;
if ( V_22 ) {
do {
if ( V_22 -> V_25 == V_23 ) {
if ( V_1 ) {
if ( strcmp ( V_22 -> V_26 , V_1 ) == 0 ) {
return V_22 ;
}
} else {
return V_22 ;
}
}
V_22 = V_22 -> V_6 ;
} while ( V_22 != V_9 -> V_20 [ V_24 ] );
}
return NULL ;
}
void * F_22 ( T_3 * V_9 , long V_23 , const char * V_1 )
{
unsigned long V_17 = 0 ;
T_2 * V_22 ;
F_11 ( & V_9 -> V_15 , V_17 ) ;
V_22 = F_21 ( V_9 , V_23 , V_1 ) ;
F_12 ( & V_9 -> V_15 , V_17 ) ;
return V_22 ;
}
void * F_23 ( T_3 * V_9 , long V_23 , const char * V_1 ,
void * * V_30 )
{
unsigned long V_17 = 0 ;
T_2 * V_22 ;
F_11 ( & V_9 -> V_15 , V_17 ) ;
V_22 = F_21 ( V_9 , V_23 , V_1 ) ;
if( V_22 ) {
V_9 -> V_21 = V_22 ;
* V_30 = F_24 ( V_9 ) ;
} else
* V_30 = NULL ;
F_12 ( & V_9 -> V_15 , V_17 ) ;
return V_22 ;
}
T_2 * F_18 ( T_3 * V_9 )
{
T_2 * V_22 ;
int V_18 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_9 == NULL )
return NULL ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_22 = V_9 -> V_20 [ V_18 ] ;
if ( V_22 ) {
V_9 -> V_21 = V_22 ;
return V_22 ;
}
}
return NULL ;
}
T_2 * F_24 ( T_3 * V_9 )
{
T_2 * V_22 ;
int V_24 ;
int V_18 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_9 -> V_21 == NULL ) {
F_10 ( hashbin->hb_current != NULL, return NULL;) ;
return NULL ;
}
V_22 = V_9 -> V_21 -> V_6 ;
V_24 = F_15 ( V_22 -> V_25 ) ;
if ( V_22 != V_9 -> V_20 [ V_24 ] ) {
V_9 -> V_21 = V_22 ;
return V_22 ;
}
if ( V_24 >= V_19 )
return NULL ;
V_24 ++ ;
for ( V_18 = V_24 ; V_18 < V_19 ; V_18 ++ ) {
V_22 = V_9 -> V_20 [ V_18 ] ;
if ( V_22 ) {
V_9 -> V_21 = V_22 ;
return V_22 ;
}
}
return NULL ;
}
