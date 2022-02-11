char *
F_1 ( const T_1 * V_1 )
{
char * V_2 ;
char * V_3 = NULL ;
char * V_4 = NULL ;
int V_5 = 0 ;
int V_6 = 0 ;
if ( ( V_7 . V_8 == NULL ) ||
( * V_7 . V_8 == '\0' ) ) {
return NULL ;
}
if ( ( V_2 = strstr ( V_7 . V_8 , V_1 ) ) == NULL ) {
return NULL ;
}
while ( * V_2 != '\0' ) {
if ( * V_2 == ',' )
return NULL ;
else if ( * V_2 == '(' ) {
V_6 = 0 ;
V_5 ++ ;
V_2 ++ ;
V_3 = V_2 ;
continue;
}
else if ( * V_2 == ')' ) {
break;
}
else {
V_2 ++ ;
V_6 ++ ;
}
}
if ( ( V_5 == 1 ) && ( V_6 > 0 ) && ( V_3 != NULL ) ) {
V_4 = ( char * ) F_2 ( V_2 - V_3 + 1 ) ;
memcpy ( V_4 , V_3 , V_2 - V_3 ) ;
V_4 [ V_2 - V_3 ] = '\0' ;
return V_4 ;
}
else
return NULL ;
}
T_2
F_3 ( const T_1 * V_1 )
{
T_1 * V_2 , * V_9 ;
long V_10 ;
if ( ( V_7 . V_11 == NULL ) ||
( * V_7 . V_11 == '\0' ) ) {
return - 1 ;
}
if ( ( V_2 = strstr ( V_7 . V_11 , V_1 ) ) == NULL ) {
return - 1 ;
}
V_2 += strlen ( V_1 ) + 1 ;
V_10 = strtol ( V_2 , & V_9 , 10 ) ;
if ( V_9 == V_2 || * V_9 != ')' || V_10 < 0 ) {
return - 1 ;
}
if ( V_10 > V_12 ) {
return - 1 ;
}
return ( T_2 ) V_10 ;
}
T_2
F_4 ( const T_1 * V_1 )
{
T_1 * V_2 , * V_9 ;
T_2 V_13 ;
if ( ( V_7 . V_14 == NULL ) ||
( * V_7 . V_14 == '\0' ) ) {
return - 1 ;
}
if ( ( V_2 = strstr ( V_7 . V_14 , V_1 ) ) == NULL ) {
return - 1 ;
}
V_2 += strlen ( V_1 ) + 1 ;
V_13 = ( T_2 ) strtol ( V_2 , & V_9 , 10 ) ;
if ( V_9 == V_2 || * V_9 != ')' || V_13 < 0 ) {
return - 1 ;
}
if ( V_13 > V_12 ) {
return - 1 ;
}
return ( T_2 ) V_13 ;
}
T_2
F_5 ( const T_1 * V_1 )
{
T_1 * V_2 , * V_9 ;
T_2 V_15 ;
if ( ( V_7 . V_16 == NULL ) ||
( * V_7 . V_16 == '\0' ) ) {
return - 1 ;
}
if ( ( V_2 = strstr ( V_7 . V_16 , V_1 ) ) == NULL ) {
return - 1 ;
}
V_2 += strlen ( V_1 ) + 3 ;
V_15 = ( T_2 ) strtol ( V_2 , & V_9 , 10 ) ;
if ( V_9 == V_2 || * V_9 != ')' || V_15 < 0 ) {
return - 1 ;
}
if ( V_15 > V_17 ) {
return - 1 ;
}
return ( T_2 ) V_15 ;
}
T_3
F_6 ( const T_1 * V_1 )
{
T_1 * V_2 , * V_9 ;
T_3 V_18 ;
if ( ( V_7 . V_16 == NULL ) ||
( * V_7 . V_16 == '\0' ) ) {
return - 1 ;
}
if ( ( V_2 = strstr ( V_7 . V_16 , V_1 ) ) == NULL ) {
return - 1 ;
}
V_2 += strlen ( V_1 ) + 1 ;
V_18 = ( T_3 ) strtol ( V_2 , & V_9 , 10 ) ;
if ( V_9 == V_2 || * V_9 != '(' ) {
return - 1 ;
}
return ( T_3 ) V_18 ;
}
T_3
F_7 ( const T_1 * V_1 )
{
T_1 * V_2 , * V_9 ;
T_3 V_19 ;
if ( ( V_7 . V_20 == NULL ) ||
( * V_7 . V_20 == '\0' ) ) {
return - 1 ;
}
if ( ( V_2 = strstr ( V_7 . V_20 , V_1 ) ) == NULL ) {
return - 1 ;
}
V_2 += strlen ( V_1 ) + 1 ;
V_19 = ( T_3 ) strtol ( V_2 , & V_9 , 10 ) ;
if ( V_9 == V_2 || * V_9 != ')' ) {
return - 1 ;
}
return ( T_3 ) V_19 ;
}
char *
F_8 ( const char * V_1 )
{
char * V_4 ;
T_4 * V_21 ;
T_4 * V_22 ;
T_5 * V_23 ;
int V_24 ;
V_4 = F_1 ( V_1 ) ;
if ( V_4 != NULL ) {
V_4 = F_9 ( V_4 ) ;
} else if ( strcmp ( V_1 , L_1 ) == 0 ) {
V_4 = F_9 ( F_10 ( L_2 , 0 ) ) ;
if ( ! V_4 ) {
V_4 = F_9 ( L_3 ) ;
}
} else {
V_4 = NULL ;
V_21 = F_11 ( & V_24 , NULL ) ;
if ( V_21 != NULL ) {
V_22 = V_21 ;
do {
V_23 = ( T_5 * ) V_22 -> V_25 ;
if ( strcmp ( V_23 -> V_26 , V_1 ) == 0 ) {
if ( V_23 -> V_27 != NULL ) {
V_4 = F_9 ( V_23 -> V_27 ) ;
} else if ( V_23 -> V_28 != NULL ) {
V_4 = F_9 ( V_23 -> V_28 ) ;
}
break;
}
} while ( ( V_22 = F_12 ( V_22 ) ) != NULL );
}
F_13 ( V_21 ) ;
if ( V_4 == NULL ) {
V_4 = F_9 ( V_1 ) ;
}
}
return V_4 ;
}
static T_5 *
F_14 ( T_4 * V_21 , T_1 * V_1 )
{
T_4 * V_22 ;
T_5 * V_23 ;
for ( V_22 = V_21 ; V_22 != NULL ; V_22 = F_12 ( V_22 ) ) {
V_23 = ( T_5 * ) V_22 -> V_25 ;
if( strcmp ( V_1 , V_23 -> V_26 ) == 0 ) {
return V_23 ;
}
}
return NULL ;
}
char *
F_15 ( T_4 * V_21 , T_1 * V_1 )
{
T_1 * V_4 ;
char * V_29 ;
T_5 * V_23 ;
V_4 = F_1 ( V_1 ) ;
if ( V_4 != NULL ) {
V_29 = F_16 ( L_4 , V_4 , V_1 ) ;
F_17 ( V_4 ) ;
} else {
V_23 = F_14 ( V_21 , V_1 ) ;
if ( V_23 != NULL && V_23 -> V_28 != NULL ) {
V_29 = F_16 ( L_4 , V_23 -> V_28 ,
V_23 -> V_26 ) ;
} else {
V_29 = F_9 ( V_1 ) ;
}
}
return V_29 ;
}
T_4 *
F_18 ( T_4 * V_21 , T_3 V_30 )
{
T_4 * V_31 ;
T_4 * V_22 ;
T_5 * V_23 ;
char * V_29 ;
T_1 * V_4 ;
V_31 = NULL ;
if ( V_21 != NULL ) {
for ( V_22 = V_21 ; V_22 != NULL ;
V_22 = F_12 ( V_22 ) ) {
V_23 = ( T_5 * ) V_22 -> V_25 ;
if ( ! F_19 ( V_23 -> V_26 ) || ! V_30 ) {
V_4 = F_1 ( V_23 -> V_26 ) ;
if ( V_4 != NULL ) {
V_29 = F_16 ( L_4 , V_4 , V_23 -> V_26 ) ;
F_17 ( V_4 ) ;
} else {
if ( V_23 -> V_28 != NULL ) {
V_29 = F_16 ( L_4 ,
V_23 -> V_28 ,
V_23 -> V_26 ) ;
} else {
V_29 = F_9 ( V_23 -> V_26 ) ;
}
}
V_31 = F_20 ( V_31 , V_29 ) ;
}
}
}
return V_31 ;
}
static void
F_21 ( T_6 V_25 , T_6 T_7 V_32 )
{
F_17 ( V_25 ) ;
}
void
F_22 ( T_4 * V_31 )
{
if ( V_31 != NULL ) {
F_23 ( V_31 , F_21 , NULL ) ;
F_24 ( V_31 ) ;
}
}
const char *
F_25 ( const char * V_33 )
{
const char * V_1 ;
#ifdef F_26
V_1 = V_33 + strlen ( V_33 ) ;
for (; ; ) {
if ( V_1 == V_33 ) {
break;
}
V_1 -- ;
if ( * V_1 == ':' ) {
if ( ( strncmp ( V_1 , L_5 , 3 ) != 0 ) && ! isdigit ( V_1 [ 1 ] ) ) {
V_1 ++ ;
while ( * V_1 == ' ' )
V_1 ++ ;
break;
}
}
}
#else
V_1 = strrchr ( V_33 , ' ' ) ;
if ( V_1 == NULL ) {
V_1 = V_33 ;
} else {
V_1 ++ ;
}
#endif
return V_1 ;
}
const char *
F_27 ( T_8 * V_34 , T_9 V_35 )
{
T_10 V_36 ;
if ( V_35 < V_34 -> V_37 -> V_38 ) {
V_36 = F_28 ( V_34 -> V_37 , T_10 , V_35 ) ;
if ( ! V_36 . V_4 && V_36 . V_26 ) {
V_36 . V_4 = F_8 ( V_36 . V_26 ) ;
V_34 -> V_37 = F_29 ( V_34 -> V_37 , V_35 ) ;
F_30 ( V_34 -> V_37 , V_35 , V_36 ) ;
}
return ( V_36 . V_4 ) ;
} else {
return ( NULL ) ;
}
}
