char *
F_1 ( const T_1 * V_1 )
{
char * V_2 ;
char * V_3 = NULL ;
char * V_4 = NULL ;
int V_5 = 0 ;
int V_6 = 0 ;
if ( V_7 . V_8 == NULL ) {
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
V_4 = F_2 ( V_2 - V_3 + 1 ) ;
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
if ( V_7 . V_11 == NULL ) {
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
char *
F_4 ( const char * V_1 )
{
char * V_4 ;
T_3 * V_13 ;
T_3 * V_14 ;
T_4 * V_15 ;
int V_16 ;
V_4 = F_1 ( V_1 ) ;
if ( V_4 != NULL ) {
V_4 = F_5 ( V_4 ) ;
} else if ( strcmp ( V_1 , L_1 ) == 0 ) {
V_4 = F_5 ( F_6 ( L_2 , 0 ) ) ;
if ( ! V_4 ) {
V_4 = F_5 ( L_3 ) ;
}
} else {
V_4 = NULL ;
V_13 = F_7 ( & V_16 , NULL ) ;
if ( V_13 != NULL ) {
V_14 = V_13 ;
do {
V_15 = V_14 -> V_17 ;
if ( strcmp ( V_15 -> V_18 , V_1 ) == 0 ) {
if ( V_15 -> V_19 != NULL ) {
V_4 = F_5 ( V_15 -> V_19 ) ;
}
break;
}
} while ( ( V_14 = F_8 ( V_14 ) ) != NULL );
}
F_9 ( V_13 ) ;
if ( V_4 == NULL ) {
V_4 = F_5 ( V_1 ) ;
}
}
return V_4 ;
}
static T_4 *
F_10 ( T_3 * V_13 , T_1 * V_1 )
{
T_3 * V_14 ;
T_4 * V_15 ;
for ( V_14 = V_13 ; V_14 != NULL ; V_14 = F_8 ( V_14 ) ) {
V_15 = V_14 -> V_17 ;
if( strcmp ( V_1 , V_15 -> V_18 ) == 0 ) {
return V_15 ;
}
}
return NULL ;
}
char *
F_11 ( T_3 * V_13 , T_1 * V_1 )
{
T_1 * V_4 ;
char * V_20 ;
T_4 * V_15 ;
V_4 = F_1 ( V_1 ) ;
if ( V_4 != NULL ) {
V_20 = F_12 ( L_4 , V_4 , V_1 ) ;
F_13 ( V_4 ) ;
} else {
V_15 = F_10 ( V_13 , V_1 ) ;
if ( V_15 != NULL && V_15 -> V_19 != NULL ) {
V_20 = F_12 ( L_4 , V_15 -> V_19 ,
V_15 -> V_18 ) ;
} else {
V_20 = F_5 ( V_1 ) ;
}
}
return V_20 ;
}
T_3 *
F_14 ( T_3 * V_13 , T_5 V_21 )
{
T_3 * V_22 ;
T_3 * V_14 ;
T_4 * V_15 ;
char * V_20 ;
T_1 * V_4 ;
V_22 = NULL ;
if ( V_13 != NULL ) {
for ( V_14 = V_13 ; V_14 != NULL ;
V_14 = F_8 ( V_14 ) ) {
V_15 = V_14 -> V_17 ;
if ( ! F_15 ( V_15 -> V_18 ) || ! V_21 ) {
V_4 = F_1 ( V_15 -> V_18 ) ;
if ( V_4 != NULL ) {
V_20 = F_12 ( L_4 , V_4 , V_15 -> V_18 ) ;
F_13 ( V_4 ) ;
} else {
if ( V_15 -> V_19 != NULL ) {
V_20 = F_12 ( L_4 , V_15 -> V_19 ,
V_15 -> V_18 ) ;
} else {
V_20 = F_5 ( V_15 -> V_18 ) ;
}
}
V_22 = F_16 ( V_22 , V_20 ) ;
}
}
}
return V_22 ;
}
static void
F_17 ( T_6 V_17 , T_6 T_7 V_23 )
{
F_13 ( V_17 ) ;
}
void
F_18 ( T_3 * V_22 )
{
if ( V_22 != NULL ) {
F_19 ( V_22 , F_17 , NULL ) ;
F_20 ( V_22 ) ;
}
}
const char *
F_21 ( const char * V_24 )
{
const char * V_1 ;
#ifdef F_22
V_1 = V_24 + strlen ( V_24 ) ;
for (; ; ) {
if ( V_1 == V_24 ) {
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
V_1 = strrchr ( V_24 , ' ' ) ;
if ( V_1 == NULL ) {
V_1 = V_24 ;
} else {
V_1 ++ ;
}
#endif
return V_1 ;
}
const char *
F_23 ( T_8 * V_25 , T_9 V_26 )
{
T_10 V_27 ;
if ( V_26 < V_25 -> V_28 -> V_29 ) {
V_27 = F_24 ( V_25 -> V_28 , T_10 , V_26 ) ;
if ( ! V_27 . V_4 && V_27 . V_18 ) {
V_27 . V_4 = F_4 ( V_27 . V_18 ) ;
V_25 -> V_28 = F_25 ( V_25 -> V_28 , V_26 ) ;
F_26 ( V_25 -> V_28 , V_26 , V_27 ) ;
}
return ( V_27 . V_4 ) ;
} else {
return ( NULL ) ;
}
}
