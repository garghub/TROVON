T_1
F_1 ( void * V_1 , T_2 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
T_3 * V_6 = ( T_3 * ) V_1 ;
int V_7 ;
if ( V_6 -> V_8 . V_9 == 0 ) {
F_2 ( V_6 , L_1 ) ;
return V_10 ;
}
V_7 = ( V_3 + V_6 -> V_8 . V_9 - 1 ) & ~ ( V_6 -> V_8 . V_9 - 1 ) ;
V_5 = F_3 ( V_7 + 2 + V_11 + V_12 ) ;
if ( ! V_5 ) {
F_2 ( V_1 , L_2 ) ;
V_2 -> V_13 = NULL ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = 0 ;
return V_10 ;
}
V_2 -> V_13 = ( const unsigned char * ) V_5 ;
V_2 -> V_14 = V_7 + 2 + V_11 + V_12 ;
V_2 -> V_15 = ( const void * ) V_5 -> V_17 ;
V_2 -> V_16 = V_3 ;
return V_18 ;
}
void
F_4 ( void * V_1 , T_2 * V_2 )
{
struct V_4 * V_5 ;
F_5 ( V_1 ) ;
V_5 = (struct V_4 * ) V_2 -> V_13 ;
F_6 ( V_5 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_15 = V_2 -> V_13 = NULL ;
}
T_1
F_7 ( void * V_1 , T_2 * V_2 )
{
struct V_4 * V_5 ;
unsigned long V_19 ;
int V_20 ;
T_3 * V_6 = ( T_3 * ) V_1 ;
if ( ( V_2 == NULL ) || ( V_12 == 0 ) ) {
return V_18 ;
}
if ( ( V_2 -> V_15 == NULL ) || ( V_2 -> V_16 == 0 ) ) {
return V_18 ;
}
V_19 = ( unsigned long ) ( V_2 -> V_15 ) & ( V_12 - 1 ) ;
F_8 ( V_6 , V_21 ,
L_3 ,
V_2 -> V_15 , V_19 ) ;
V_20 = V_12 - V_19 ;
if ( V_20 < 0 ) {
F_2 ( V_6 , L_4 , V_20 ) ;
return V_10 ;
}
V_5 = (struct V_4 * ) ( V_2 -> V_13 ) ;
F_9 ( V_5 , V_20 ) ;
V_2 -> V_13 = ( const unsigned char * ) V_5 ;
V_2 -> V_15 = ( const void * ) ( V_5 -> V_17 ) ;
return V_18 ;
}
char * F_10 ( void )
{
unsigned long long V_22 ;
unsigned long V_23 ;
V_22 = F_11 ( V_24 ) ;
V_23 = F_12 ( V_22 , 1000000000 ) ;
sprintf ( V_25 , L_5 ,
( unsigned long ) V_22 ,
V_23 / 1000 ) ;
return V_25 ;
}
void
F_2 ( void * V_1 , const char * V_26 , ... )
{
T_3 * V_6 = ( T_3 * ) V_1 ;
char V_27 [ V_28 ] ;
T_4 args ;
unsigned int V_29 ;
#ifdef F_13
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_30 L_6 , F_10 () , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_30 L_7 , F_10 () ) ;
}
#else
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_30 L_8 , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_30 L_9 ) ;
}
#endif
F_14 ( V_27 , V_29 , args , V_26 ) ;
F_15 ( L_10 , V_27 ) ;
}
void
F_16 ( void * V_1 , const char * V_26 , ... )
{
T_3 * V_6 = ( T_3 * ) V_1 ;
char V_27 [ V_28 ] ;
T_4 args ;
unsigned int V_29 ;
#ifdef F_13
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_32 L_6 , F_10 () , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_32 L_7 , F_10 () ) ;
}
#else
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_32 L_8 , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_32 L_9 ) ;
}
#endif
F_14 ( V_27 , V_29 , args , V_26 ) ;
F_15 ( L_10 , V_27 ) ;
}
void
F_17 ( void * V_1 , const char * V_26 , ... )
{
T_3 * V_6 = ( T_3 * ) V_1 ;
char V_27 [ V_28 ] ;
T_4 args ;
unsigned int V_29 ;
#ifdef F_13
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_33 L_6 , F_10 () , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_33 L_7 , F_10 () ) ;
}
#else
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_33 L_8 , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_33 L_9 ) ;
}
#endif
F_14 ( V_27 , V_29 , args , V_26 ) ;
F_15 ( L_10 , V_27 ) ;
}
void
F_18 ( void * V_1 , const char * V_26 , ... )
{
T_3 * V_6 = ( T_3 * ) V_1 ;
char V_27 [ V_28 ] ;
T_4 args ;
unsigned int V_29 ;
#ifdef F_13
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_34 L_6 , F_10 () , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_34 L_7 , F_10 () ) ;
}
#else
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_34 L_8 , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_34 L_9 ) ;
}
#endif
F_14 ( V_27 , V_29 , args , V_26 ) ;
F_15 ( L_10 , V_27 ) ;
}
void
F_8 ( void * V_1 , int V_35 , const char * V_26 , ... )
{
T_3 * V_6 = ( T_3 * ) V_1 ;
char V_27 [ V_28 ] ;
T_4 args ;
unsigned int V_29 ;
if ( V_36 >= V_35 ) {
#ifdef F_13
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_30 L_6 , F_10 () , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_30 L_7 , F_10 () ) ;
}
#else
if ( V_6 != NULL ) {
V_29 = snprintf ( V_27 , V_28 , V_30 L_8 , V_6 -> V_31 ) ;
} else {
V_29 = snprintf ( V_27 , V_28 , V_30 L_9 ) ;
}
#endif
F_14 ( V_27 , V_29 , args , V_26 ) ;
F_15 ( L_10 , V_27 ) ;
}
}
void
F_19 ( void * V_1 , const char * V_26 , ... )
{
}
void
F_20 ( void * V_1 , int V_35 , const char * V_26 , ... )
{
}
void
F_21 ( void * V_1 , int V_35 , const char * V_37 , void * V_38 , T_5 V_29 )
{
T_3 * V_6 = ( T_3 * ) V_1 ;
if ( V_36 >= V_35 ) {
#ifdef F_13
if ( V_6 != NULL ) {
F_15 ( V_30 L_11 , F_10 () , V_6 -> V_31 , V_37 ? V_37 : L_12 ) ;
} else {
F_15 ( V_30 L_13 , F_10 () , V_37 ? V_37 : L_12 ) ;
}
#else
if ( V_6 != NULL ) {
F_15 ( V_30 L_14 , V_6 -> V_31 , V_37 ? V_37 : L_12 ) ;
} else {
F_15 ( V_30 L_15 , V_37 ? V_37 : L_12 ) ;
}
#endif
F_22 ( V_38 , V_29 ) ;
if ( V_6 != NULL ) {
F_15 ( V_30 L_16 , V_6 -> V_31 ) ;
} else {
F_15 ( V_30 L_17 ) ;
}
}
}
void
F_22 ( void * V_38 , T_5 V_29 )
{
int V_39 , V_40 = 0 ;
unsigned char * V_41 = ( unsigned char * ) V_38 ;
#ifdef F_13
F_15 ( L_18 , F_10 () ) ;
#endif
if ( V_38 == NULL ) {
F_15 ( L_19 ) ;
return;
}
for ( V_39 = 0 ; V_39 < V_29 ; V_39 ++ ) {
if ( V_40 == 0 ) {
F_15 ( L_20 , V_39 ) ;
}
F_15 ( L_21 , V_41 [ V_39 ] ) ;
if ( ++ V_40 == 16 ) {
F_15 ( L_22 ) ;
V_40 = 0 ;
}
}
if ( V_40 ) {
F_15 ( L_22 ) ;
}
}
void
F_23 ( void * V_38 , T_5 V_29 )
{
int V_39 , V_40 = 0 ;
unsigned short * V_42 = ( unsigned short * ) V_38 ;
#ifdef F_13
F_15 ( L_18 , F_10 () ) ;
#endif
for ( V_39 = 0 ; V_39 < V_29 ; V_39 += 2 ) {
if ( V_40 == 0 ) {
F_15 ( L_20 , V_39 ) ;
}
F_15 ( L_23 , * V_42 ++ ) ;
if ( ++ V_40 == 8 ) {
F_15 ( L_22 ) ;
V_40 = 0 ;
}
}
if ( V_40 ) {
F_15 ( L_22 ) ;
}
}
void
F_24 ( void * V_38 , T_5 V_29 )
{
int V_39 , V_40 = 0 ;
unsigned char * V_41 = ( unsigned char * ) V_38 ;
#ifdef F_13
F_15 ( L_18 , F_10 () ) ;
#endif
for ( V_39 = 0 ; V_39 < V_29 ; V_39 ++ ) {
F_15 ( L_24 , V_41 [ V_39 ] ) ;
}
if ( V_40 ) {
F_15 ( L_22 ) ;
}
}
