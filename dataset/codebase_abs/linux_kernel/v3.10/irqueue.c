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
F_3 ( 4 , L_1 , V_6 ) ;
if ( * V_4 == NULL ) {
V_5 -> V_7 = V_5 -> V_8 = * V_4 = V_5 ;
} else {
V_5 -> V_7 = ( * V_4 ) ;
( * V_4 ) -> V_8 -> V_7 = V_5 ;
V_5 -> V_8 = ( * V_4 ) -> V_8 ;
( * V_4 ) -> V_8 = V_5 ;
( * V_4 ) = V_5 ;
}
}
static T_2 * F_4 ( T_2 * * V_4 )
{
T_2 * V_9 ;
F_3 ( 4 , L_2 ) ;
V_9 = * V_4 ;
if ( * V_4 == NULL ) {
} else if ( ( * V_4 ) -> V_7 == * V_4 ) {
* V_4 = NULL ;
} else {
( * V_4 ) -> V_8 -> V_7 = ( * V_4 ) -> V_7 ;
( * V_4 ) -> V_7 -> V_8 = ( * V_4 ) -> V_8 ;
* V_4 = ( * V_4 ) -> V_7 ;
}
return V_9 ;
}
static T_2 * F_5 ( T_2 * * V_4 , T_2 * V_5 )
{
T_2 * V_9 ;
F_3 ( 4 , L_3 ) ;
V_9 = * V_4 ;
if ( * V_4 == NULL ) {
} else if ( ( * V_4 ) -> V_7 == * V_4 ) {
* V_4 = NULL ;
} else {
V_5 -> V_8 -> V_7 = V_5 -> V_7 ;
V_5 -> V_7 -> V_8 = V_5 -> V_8 ;
if ( ( * V_4 ) == V_5 )
( * V_4 ) = V_5 -> V_7 ;
}
return V_9 ;
}
T_3 * F_6 ( int type )
{
T_3 * V_10 ;
V_10 = F_7 ( sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_12 = type ;
V_10 -> V_13 = V_14 ;
if ( V_10 -> V_12 & V_15 ) {
F_8 ( & V_10 -> V_16 ) ;
}
return V_10 ;
}
int F_9 ( T_3 * V_10 , T_4 V_17 )
{
T_2 * V_4 ;
unsigned long V_18 = 0 ;
int V_19 ;
F_10 (hashbin != NULL, return -1;) ;
F_10 (hashbin->magic == HB_MAGIC, return -1;) ;
if ( V_10 -> V_12 & V_15 ) {
F_11 ( & V_10 -> V_16 , V_18 ,
V_20 ++ ) ;
}
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_4 = F_4 ( ( T_2 * * ) & V_10 -> V_22 [ V_19 ] ) ;
while ( V_4 ) {
if ( V_17 )
(* V_17)( V_4 ) ;
V_4 = F_4 (
( T_2 * * ) & V_10 -> V_22 [ V_19 ] ) ;
}
}
V_10 -> V_23 = NULL ;
V_10 -> V_13 = ~ V_14 ;
if ( V_10 -> V_12 & V_15 ) {
F_12 ( & V_10 -> V_16 , V_18 ) ;
#ifdef F_13
V_20 -- ;
#endif
}
F_14 ( V_10 ) ;
return 0 ;
}
void F_15 ( T_3 * V_10 , T_2 * V_24 , long V_25 ,
const char * V_1 )
{
unsigned long V_18 = 0 ;
int V_26 ;
F_3 ( 4 , L_1 , V_6 ) ;
F_10 ( hashbin != NULL, return;) ;
F_10 ( hashbin->magic == HB_MAGIC, return;) ;
if ( V_1 )
V_25 = F_1 ( V_1 ) ;
V_26 = F_16 ( V_25 ) ;
if ( V_10 -> V_12 & V_15 ) {
F_17 ( & V_10 -> V_16 , V_18 ) ;
}
V_24 -> V_27 = V_25 ;
if ( V_1 )
F_18 ( V_24 -> V_28 , V_1 , sizeof( V_24 -> V_28 ) ) ;
F_2 ( ( T_2 * * ) & V_10 -> V_22 [ V_26 ] ,
V_24 ) ;
V_10 -> V_29 ++ ;
if ( V_10 -> V_12 & V_15 ) {
F_12 ( & V_10 -> V_16 , V_18 ) ;
}
}
void * F_19 ( T_3 * V_10 )
{
unsigned long V_18 = 0 ;
T_2 * V_24 = NULL ;
if ( V_10 -> V_12 & V_15 ) {
F_17 ( & V_10 -> V_16 , V_18 ) ;
}
V_24 = F_20 ( V_10 ) ;
if ( V_24 != NULL ) {
int V_26 ;
long V_25 ;
V_25 = V_24 -> V_27 ;
V_26 = F_16 ( V_25 ) ;
F_5 ( ( T_2 * * ) & V_10 -> V_22 [ V_26 ] ,
V_24 ) ;
V_10 -> V_29 -- ;
V_24 -> V_7 = NULL ;
V_24 -> V_8 = NULL ;
if ( V_24 == V_10 -> V_23 )
V_10 -> V_23 = NULL ;
}
if ( V_10 -> V_12 & V_15 ) {
F_12 ( & V_10 -> V_16 , V_18 ) ;
}
return V_24 ;
}
void * F_21 ( T_3 * V_10 , long V_25 , const char * V_1 )
{
int V_26 , V_30 = FALSE ;
unsigned long V_18 = 0 ;
T_2 * V_24 ;
F_3 ( 4 , L_1 , V_6 ) ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_1 )
V_25 = F_1 ( V_1 ) ;
V_26 = F_16 ( V_25 ) ;
if ( V_10 -> V_12 & V_15 ) {
F_17 ( & V_10 -> V_16 , V_18 ) ;
}
V_24 = V_10 -> V_22 [ V_26 ] ;
if ( V_24 ) {
do {
if ( V_24 -> V_27 == V_25 ) {
if ( V_1 ) {
if ( strcmp ( V_24 -> V_28 , V_1 ) == 0 )
{
V_30 = TRUE ;
break;
}
} else {
V_30 = TRUE ;
break;
}
}
V_24 = V_24 -> V_7 ;
} while ( V_24 != V_10 -> V_22 [ V_26 ] );
}
if ( V_30 ) {
F_5 ( ( T_2 * * ) & V_10 -> V_22 [ V_26 ] ,
V_24 ) ;
V_10 -> V_29 -- ;
if ( V_24 == V_10 -> V_23 )
V_10 -> V_23 = NULL ;
}
if ( V_10 -> V_12 & V_15 ) {
F_12 ( & V_10 -> V_16 , V_18 ) ;
}
if ( V_30 )
return V_24 ;
else
return NULL ;
}
void * F_22 ( T_3 * V_10 , T_2 * V_24 )
{
unsigned long V_18 = 0 ;
int V_26 ;
long V_25 ;
F_3 ( 4 , L_1 , V_6 ) ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
F_10 ( entry != NULL, return NULL;) ;
if ( V_10 -> V_12 & V_15 ) {
F_17 ( & V_10 -> V_16 , V_18 ) ;
}
if( ( V_24 -> V_7 == NULL ) || ( V_24 -> V_8 == NULL ) ) {
V_24 = NULL ;
goto V_31;
}
V_25 = V_24 -> V_27 ;
V_26 = F_16 ( V_25 ) ;
F_5 ( ( T_2 * * ) & V_10 -> V_22 [ V_26 ] ,
V_24 ) ;
V_10 -> V_29 -- ;
V_24 -> V_7 = NULL ;
V_24 -> V_8 = NULL ;
if ( V_24 == V_10 -> V_23 )
V_10 -> V_23 = NULL ;
V_31:
if ( V_10 -> V_12 & V_15 ) {
F_12 ( & V_10 -> V_16 , V_18 ) ;
}
return V_24 ;
}
void * F_23 ( T_3 * V_10 , long V_25 , const char * V_1 )
{
int V_26 ;
T_2 * V_24 ;
F_3 ( 4 , L_4 ) ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_1 )
V_25 = F_1 ( V_1 ) ;
V_26 = F_16 ( V_25 ) ;
V_24 = V_10 -> V_22 [ V_26 ] ;
if ( V_24 ) {
do {
if ( V_24 -> V_27 == V_25 ) {
if ( V_1 ) {
if ( strcmp ( V_24 -> V_28 , V_1 ) == 0 ) {
return V_24 ;
}
} else {
return V_24 ;
}
}
V_24 = V_24 -> V_7 ;
} while ( V_24 != V_10 -> V_22 [ V_26 ] );
}
return NULL ;
}
void * F_24 ( T_3 * V_10 , long V_25 , const char * V_1 )
{
unsigned long V_18 = 0 ;
T_2 * V_24 ;
F_17 ( & V_10 -> V_16 , V_18 ) ;
V_24 = F_23 ( V_10 , V_25 , V_1 ) ;
F_12 ( & V_10 -> V_16 , V_18 ) ;
return V_24 ;
}
void * F_25 ( T_3 * V_10 , long V_25 , const char * V_1 ,
void * * V_32 )
{
unsigned long V_18 = 0 ;
T_2 * V_24 ;
F_17 ( & V_10 -> V_16 , V_18 ) ;
V_24 = F_23 ( V_10 , V_25 , V_1 ) ;
if( V_24 ) {
V_10 -> V_23 = V_24 ;
* V_32 = F_26 ( V_10 ) ;
} else
* V_32 = NULL ;
F_12 ( & V_10 -> V_16 , V_18 ) ;
return V_24 ;
}
T_2 * F_20 ( T_3 * V_10 )
{
T_2 * V_24 ;
int V_19 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_10 == NULL )
return NULL ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
V_24 = V_10 -> V_22 [ V_19 ] ;
if ( V_24 ) {
V_10 -> V_23 = V_24 ;
return V_24 ;
}
}
return NULL ;
}
T_2 * F_26 ( T_3 * V_10 )
{
T_2 * V_24 ;
int V_26 ;
int V_19 ;
F_10 ( hashbin != NULL, return NULL;) ;
F_10 ( hashbin->magic == HB_MAGIC, return NULL;) ;
if ( V_10 -> V_23 == NULL ) {
F_10 ( hashbin->hb_current != NULL, return NULL;) ;
return NULL ;
}
V_24 = V_10 -> V_23 -> V_7 ;
V_26 = F_16 ( V_24 -> V_27 ) ;
if ( V_24 != V_10 -> V_22 [ V_26 ] ) {
V_10 -> V_23 = V_24 ;
return V_24 ;
}
if ( V_26 >= V_21 )
return NULL ;
V_26 ++ ;
for ( V_19 = V_26 ; V_19 < V_21 ; V_19 ++ ) {
V_24 = V_10 -> V_22 [ V_19 ] ;
if ( V_24 ) {
V_10 -> V_23 = V_24 ;
return V_24 ;
}
}
return NULL ;
}
