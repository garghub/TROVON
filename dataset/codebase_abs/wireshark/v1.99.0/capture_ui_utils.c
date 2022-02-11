char *
F_1 ( const T_1 * V_1 )
{
T_1 * * V_2 ;
T_1 * V_3 = NULL ;
int V_4 ;
if ( V_1 == NULL || strlen ( V_1 ) < 1 ) {
return NULL ;
}
if ( V_5 . V_6 == NULL ||
strlen ( V_5 . V_6 ) < 1 ) {
return NULL ;
}
V_2 = F_2 ( V_5 . V_6 , L_1 , - 1 ) ;
for ( V_4 = 0 ; V_2 [ V_4 ] != NULL ; V_4 ++ ) {
T_1 * * V_7 ;
V_7 = F_3 ( V_2 [ V_4 ] , L_2 , - 1 ) ;
if ( F_4 ( V_7 ) == 3 ) {
if ( strcmp ( V_7 [ 0 ] , V_1 ) == 0 && strlen ( V_7 [ 1 ] ) > 0 ) {
V_3 = F_5 ( V_7 [ 1 ] ) ;
F_6 ( V_7 ) ;
break;
}
}
F_6 ( V_7 ) ;
}
F_6 ( V_2 ) ;
return V_3 ;
}
T_2
F_7 ( const T_1 * V_1 )
{
T_1 * V_8 , * V_9 , * V_10 ;
long V_11 ;
if ( ( V_5 . V_12 == NULL ) ||
( * V_5 . V_12 == '\0' ) ) {
return - 1 ;
}
V_10 = F_8 ( L_3 , V_1 ) ;
if ( ( V_8 = strstr ( V_5 . V_12 , V_10 ) ) == NULL ) {
return - 1 ;
}
V_8 += strlen ( V_1 ) + 2 ;
V_11 = strtol ( V_8 , & V_9 , 10 ) ;
if ( V_9 == V_8 || * V_9 != ')' || V_11 < 0 ) {
return - 1 ;
}
if ( V_11 > V_13 ) {
return - 1 ;
}
return ( T_2 ) V_11 ;
}
T_2
F_9 ( const T_1 * V_1 )
{
T_1 * V_8 , * V_9 , * V_10 ;
T_2 V_14 ;
if ( ( V_5 . V_15 == NULL ) ||
( * V_5 . V_15 == '\0' ) ) {
return - 1 ;
}
V_10 = F_8 ( L_3 , V_1 ) ;
if ( ( V_8 = strstr ( V_5 . V_15 , V_10 ) ) == NULL ) {
return - 1 ;
}
V_8 += strlen ( V_1 ) + 2 ;
V_14 = ( T_2 ) strtol ( V_8 , & V_9 , 10 ) ;
if ( V_9 == V_8 || * V_9 != ')' || V_14 < 0 ) {
return - 1 ;
}
if ( V_14 > V_13 ) {
return - 1 ;
}
return ( T_2 ) V_14 ;
}
T_2
F_10 ( const T_1 * V_1 )
{
T_1 * V_8 , * V_9 , * V_10 ;
T_2 V_16 ;
if ( ( V_5 . V_17 == NULL ) ||
( * V_5 . V_17 == '\0' ) ) {
return - 1 ;
}
V_10 = F_8 ( L_4 , V_1 ) ;
if ( ( V_8 = strstr ( V_5 . V_17 , V_10 ) ) == NULL ) {
return - 1 ;
}
V_8 += strlen ( V_1 ) + 4 ;
V_16 = ( T_2 ) strtol ( V_8 , & V_9 , 10 ) ;
if ( V_9 == V_8 || * V_9 != ')' || V_16 < 0 ) {
return - 1 ;
}
if ( V_16 > V_18 ) {
return - 1 ;
}
return ( T_2 ) V_16 ;
}
T_3
F_11 ( const T_1 * V_1 )
{
T_1 * V_8 , * V_9 , * V_10 ;
T_3 V_19 ;
if ( ( V_5 . V_17 == NULL ) ||
( * V_5 . V_17 == '\0' ) ) {
return - 1 ;
}
V_10 = F_8 ( L_4 , V_1 ) ;
if ( ( V_8 = strstr ( V_5 . V_17 , V_10 ) ) == NULL ) {
return - 1 ;
}
V_8 += strlen ( V_1 ) + 2 ;
V_19 = ( T_3 ) strtol ( V_8 , & V_9 , 10 ) ;
if ( V_9 == V_8 || * V_9 != '(' ) {
return - 1 ;
}
return ( T_3 ) V_19 ;
}
T_3
F_12 ( const T_1 * V_1 )
{
T_1 * V_8 , * V_9 , * V_10 ;
T_3 V_20 ;
if ( ( V_5 . V_21 == NULL ) ||
( * V_5 . V_21 == '\0' ) ) {
return - 1 ;
}
V_10 = F_8 ( L_3 , V_1 ) ;
if ( ( V_8 = strstr ( V_5 . V_21 , V_10 ) ) == NULL ) {
return - 1 ;
}
V_8 += strlen ( V_1 ) + 2 ;
V_20 = ( T_3 ) strtol ( V_8 , & V_9 , 10 ) ;
if ( V_9 == V_8 || * V_9 != ')' ) {
return - 1 ;
}
return ( T_3 ) V_20 ;
}
T_1 *
F_13 ( const T_1 * V_1 )
{
T_1 * V_8 , V_22 [ V_23 ] , * V_10 ;
int V_4 = 0 ;
if ( ( V_5 . V_24 == NULL ) ||
( * V_5 . V_24 == '\0' ) ) {
return NULL ;
}
V_10 = F_8 ( L_3 , V_1 ) ;
if ( ( V_8 = strstr ( V_5 . V_24 , V_10 ) ) == NULL ) {
return NULL ;
}
V_8 += strlen ( V_1 ) + 2 ;
while ( V_8 [ V_4 + 1 ] != ',' && V_8 [ V_4 + 1 ] != '\0' ) {
V_22 [ V_4 ] = V_8 [ V_4 ] ;
V_4 ++ ;
}
V_22 [ V_4 ] = '\0' ;
return F_5 ( V_22 ) ;
}
char *
F_14 ( const char * V_1 )
{
char * V_3 ;
T_4 * V_25 ;
T_4 * V_26 ;
T_5 * V_27 ;
int V_28 ;
V_3 = F_1 ( V_1 ) ;
if ( V_3 != NULL ) {
V_3 = F_5 ( V_3 ) ;
} else if ( strcmp ( V_1 , L_5 ) == 0 ) {
V_3 = F_5 ( F_15 ( L_6 , 0 ) ) ;
if ( ! V_3 ) {
V_3 = F_5 ( L_7 ) ;
}
} else {
V_3 = NULL ;
V_25 = F_16 ( & V_28 , NULL , NULL ) ;
if ( V_25 != NULL ) {
V_26 = V_25 ;
do {
V_27 = ( T_5 * ) V_26 -> V_29 ;
if ( strcmp ( V_27 -> V_30 , V_1 ) == 0 ) {
if ( V_27 -> V_31 != NULL ) {
V_3 = F_5 ( V_27 -> V_31 ) ;
} else if ( V_27 -> V_32 != NULL ) {
V_3 = F_5 ( V_27 -> V_32 ) ;
}
break;
}
} while ( ( V_26 = F_17 ( V_26 ) ) != NULL );
}
F_18 ( V_25 ) ;
if ( V_3 == NULL ) {
V_3 = F_5 ( V_1 ) ;
}
}
return V_3 ;
}
T_4 *
F_19 ( T_4 * V_25 , T_3 V_33 )
{
T_4 * V_34 ;
T_4 * V_26 ;
T_5 * V_27 ;
char * V_35 ;
T_1 * V_3 ;
V_34 = NULL ;
if ( V_25 != NULL ) {
for ( V_26 = V_25 ; V_26 != NULL ;
V_26 = F_17 ( V_26 ) ) {
V_27 = ( T_5 * ) V_26 -> V_29 ;
if ( ! F_20 ( V_27 -> V_30 ) || ! V_33 ) {
V_3 = F_1 ( V_27 -> V_30 ) ;
if ( V_3 != NULL ) {
V_35 = F_8 ( L_8 , V_3 , V_27 -> V_30 ) ;
F_21 ( V_3 ) ;
} else {
if ( V_27 -> V_32 != NULL ) {
V_35 = F_8 ( L_8 ,
V_27 -> V_32 ,
V_27 -> V_30 ) ;
} else {
V_35 = F_5 ( V_27 -> V_30 ) ;
}
}
V_34 = F_22 ( V_34 , V_35 ) ;
}
}
}
return V_34 ;
}
static void
F_23 ( T_6 V_29 , T_6 T_7 V_36 )
{
F_21 ( V_29 ) ;
}
void
F_24 ( T_4 * V_34 )
{
if ( V_34 != NULL ) {
F_25 ( V_34 , F_23 , NULL ) ;
F_26 ( V_34 ) ;
}
}
const char *
F_27 ( const char * V_37 )
{
const char * V_1 ;
#ifdef F_28
V_1 = V_37 + strlen ( V_37 ) ;
for (; ; ) {
if ( V_1 == V_37 ) {
break;
}
V_1 -- ;
if ( * V_1 == ':' ) {
if ( ( strncmp ( V_1 , L_9 , 3 ) != 0 ) && ! isdigit ( V_1 [ 1 ] ) ) {
V_1 ++ ;
while ( * V_1 == ' ' )
V_1 ++ ;
break;
}
}
}
#else
V_1 = strrchr ( V_37 , ' ' ) ;
if ( V_1 == NULL ) {
V_1 = V_37 ;
} else {
V_1 ++ ;
}
#endif
return V_1 ;
}
const char *
F_29 ( T_8 * V_38 , T_9 V_4 )
{
T_10 V_39 ;
if ( V_4 < V_38 -> V_40 -> V_41 ) {
V_39 = F_30 ( V_38 -> V_40 , T_10 , V_4 ) ;
if ( ! V_39 . V_3 && V_39 . V_30 ) {
V_39 . V_3 = F_14 ( V_39 . V_30 ) ;
V_38 -> V_40 = F_31 ( V_38 -> V_40 , V_4 ) ;
F_32 ( V_38 -> V_40 , V_4 , V_39 ) ;
}
return ( V_39 . V_3 ) ;
} else {
return ( NULL ) ;
}
}
