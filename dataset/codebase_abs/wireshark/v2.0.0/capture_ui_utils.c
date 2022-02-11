static char *
F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
T_1 * * V_3 ;
T_1 * V_4 = NULL ;
int V_5 ;
if ( V_2 == NULL || strlen ( V_2 ) < 1 ) {
return NULL ;
}
if ( V_1 == NULL || strlen ( V_1 ) < 1 ) {
return NULL ;
}
V_3 = F_2 ( V_1 , L_1 , - 1 ) ;
for ( V_5 = 0 ; V_3 [ V_5 ] != NULL ; V_5 ++ ) {
T_1 * V_6 , * V_7 ;
V_6 = strchr ( V_3 [ V_5 ] , '(' ) ;
if ( V_6 == NULL ) {
break;
}
V_7 = strrchr ( V_3 [ V_5 ] , ')' ) ;
if ( V_7 == NULL || V_7 <= V_6 ) {
break;
}
* V_6 = '\0' ;
* V_7 = '\0' ;
if ( strcmp ( V_3 [ V_5 ] , V_2 ) == 0 ) {
if ( strlen ( V_6 + 1 ) > 0 ) {
V_4 = F_3 ( V_6 + 1 ) ;
}
break;
}
}
F_4 ( V_3 ) ;
return V_4 ;
}
static T_2
F_5 ( const T_1 * V_1 , const T_1 * V_2 )
{
T_1 * V_8 , * V_9 ;
long V_4 ;
V_8 = F_1 ( V_1 , V_2 ) ;
if ( V_8 == NULL ) {
return - 1 ;
}
V_4 = strtol ( V_8 , & V_9 , 10 ) ;
if ( V_9 == V_8 || * V_9 != '\0' || V_4 < 0 ) {
F_6 ( V_8 ) ;
return - 1 ;
}
if ( V_4 > V_10 ) {
F_6 ( V_8 ) ;
return - 1 ;
}
F_6 ( V_8 ) ;
return ( T_2 ) V_4 ;
}
char *
F_7 ( const T_1 * V_2 )
{
return F_1 ( V_11 . V_12 , V_2 ) ;
}
T_2
F_8 ( const T_1 * V_2 )
{
return F_5 ( V_11 . V_13 , V_2 ) ;
}
T_2
F_9 ( const T_1 * V_2 )
{
return F_5 ( V_11 . V_14 , V_2 ) ;
}
T_3
F_10 ( const T_1 * V_2 , T_3 * V_15 , int * V_16 )
{
T_3 V_17 = FALSE ;
T_1 * * V_3 ;
int V_5 ;
if ( V_2 == NULL || strlen ( V_2 ) < 1 ) {
return FALSE ;
}
if ( ( V_11 . V_18 == NULL ) ||
( * V_11 . V_18 == '\0' ) ) {
return FALSE ;
}
V_3 = F_2 ( V_11 . V_18 , L_1 , - 1 ) ;
for ( V_5 = 0 ; V_3 [ V_5 ] != NULL ; V_5 ++ ) {
T_1 * V_19 , * V_9 ;
long V_20 ;
V_19 = strrchr ( V_3 [ V_5 ] , ':' ) ;
if ( V_19 == NULL ) {
break;
}
* V_19 = '\0' ;
if ( strcmp ( V_3 [ V_5 ] , V_2 ) == 0 ) {
if ( * ( V_19 + 1 ) == '0' ) {
V_17 = TRUE ;
* V_15 = FALSE ;
* V_16 = V_21 ;
} else if ( * ( V_19 + 1 ) == '1' ) {
if ( * ( V_19 + 2 ) != '(' ) {
break;
}
V_20 = strtol ( V_19 + 3 , & V_9 , 10 ) ;
if ( V_9 == V_19 + 3 || * V_9 != ')' || V_20 < 0 ) {
break;
}
if ( V_20 > V_10 ) {
break;
}
V_17 = TRUE ;
* V_15 = TRUE ;
* V_16 = ( T_2 ) V_20 ;
} else {
break;
}
break;
}
}
F_4 ( V_3 ) ;
return V_17 ;
}
T_3
F_11 ( const T_1 * V_2 , T_3 * V_22 )
{
int V_20 ;
V_20 = F_5 ( V_11 . V_23 , V_2 ) ;
if ( V_20 == - 1 ) {
return FALSE ;
}
* V_22 = ( V_20 != 0 ) ;
return TRUE ;
}
T_1 *
F_12 ( const T_1 * V_2 )
{
return F_1 ( V_11 . V_24 , V_2 ) ;
}
char *
F_13 ( const char * V_2 )
{
char * V_25 ;
T_4 * V_26 ;
T_4 * V_27 ;
T_5 * V_28 ;
int V_29 ;
V_25 = F_7 ( V_2 ) ;
if ( V_25 == NULL ) {
if ( strcmp ( V_2 , L_2 ) == 0 ) {
V_25 = F_3 ( F_14 ( L_3 , 0 ) ) ;
if ( ! V_25 ) {
V_25 = F_3 ( L_4 ) ;
}
} else {
V_25 = NULL ;
V_26 = F_15 ( & V_29 , NULL , NULL ) ;
if ( V_26 != NULL ) {
V_27 = V_26 ;
do {
V_28 = ( T_5 * ) V_27 -> V_30 ;
if ( strcmp ( V_28 -> V_31 , V_2 ) == 0 ) {
if ( V_28 -> V_32 != NULL ) {
V_25 = F_3 ( V_28 -> V_32 ) ;
} else if ( V_28 -> V_33 != NULL ) {
V_25 = F_3 ( V_28 -> V_33 ) ;
}
break;
}
} while ( ( V_27 = F_16 ( V_27 ) ) != NULL );
}
F_17 ( V_26 ) ;
if ( V_25 == NULL ) {
V_25 = F_3 ( V_2 ) ;
}
}
}
return V_25 ;
}
T_4 *
F_18 ( T_4 * V_26 , T_3 V_34 )
{
T_4 * V_35 ;
T_4 * V_27 ;
T_5 * V_28 ;
char * V_36 ;
T_1 * V_25 ;
V_35 = NULL ;
if ( V_26 != NULL ) {
for ( V_27 = V_26 ; V_27 != NULL ;
V_27 = F_16 ( V_27 ) ) {
V_28 = ( T_5 * ) V_27 -> V_30 ;
if ( ! F_19 ( V_28 -> V_31 ) || ! V_34 ) {
V_25 = F_7 ( V_28 -> V_31 ) ;
if ( V_25 != NULL ) {
V_36 = F_20 ( L_5 , V_25 , V_28 -> V_31 ) ;
F_6 ( V_25 ) ;
} else {
if ( V_28 -> V_33 != NULL ) {
V_36 = F_20 ( L_5 ,
V_28 -> V_33 ,
V_28 -> V_31 ) ;
} else {
V_36 = F_3 ( V_28 -> V_31 ) ;
}
}
V_35 = F_21 ( V_35 , V_36 ) ;
}
}
}
return V_35 ;
}
static void
F_22 ( T_6 V_30 , T_6 T_7 V_37 )
{
F_6 ( V_30 ) ;
}
void
F_23 ( T_4 * V_35 )
{
if ( V_35 != NULL ) {
F_24 ( V_35 , F_22 , NULL ) ;
F_25 ( V_35 ) ;
}
}
const char *
F_26 ( const char * V_38 )
{
const char * V_2 ;
#ifdef F_27
V_2 = V_38 + strlen ( V_38 ) ;
for (; ; ) {
if ( V_2 == V_38 ) {
break;
}
V_2 -- ;
if ( * V_2 == ':' ) {
if ( ( strncmp ( V_2 , L_6 , 3 ) != 0 ) && ! F_28 ( V_2 [ 1 ] ) ) {
V_2 ++ ;
while ( * V_2 == ' ' )
V_2 ++ ;
break;
}
}
}
#else
V_2 = strrchr ( V_38 , ' ' ) ;
if ( V_2 == NULL ) {
V_2 = V_38 ;
} else {
V_2 ++ ;
}
#endif
return V_2 ;
}
const char *
F_29 ( T_8 * V_39 , T_9 V_5 )
{
T_10 V_40 ;
if ( V_5 < V_39 -> V_41 -> V_42 ) {
V_40 = F_30 ( V_39 -> V_41 , T_10 , V_5 ) ;
if ( ! V_40 . V_25 && V_40 . V_31 ) {
V_40 . V_25 = F_13 ( V_40 . V_31 ) ;
V_39 -> V_41 = F_31 ( V_39 -> V_41 , V_5 ) ;
F_32 ( V_39 -> V_41 , V_5 , V_40 ) ;
}
return ( V_40 . V_25 ) ;
} else {
return ( NULL ) ;
}
}
void
F_33 ( T_11 * V_43 , int V_44 )
{
T_4 * V_45 ;
T_3 V_46 ;
T_12 * V_47 ;
if ( ( V_43 -> V_48 = F_8 ( V_43 -> V_31 ) ) == - 1 ) {
V_43 -> V_48 = V_44 ;
}
V_46 = FALSE ;
for ( V_45 = V_43 -> V_49 ; V_45 != NULL ; V_45 = F_16 ( V_45 ) ) {
V_47 = ( T_12 * ) ( V_45 -> V_30 ) ;
if ( V_47 -> V_50 != - 1 && V_47 -> V_50 == V_43 -> V_48 ) {
V_46 = TRUE ;
break;
}
}
if ( ! V_46 ) {
V_43 -> V_48 = - 1 ;
}
if ( V_43 -> V_48 == - 1 ) {
for ( V_45 = V_43 -> V_49 ; V_45 != NULL ; V_45 = F_16 ( V_45 ) ) {
V_47 = ( T_12 * ) ( V_45 -> V_30 ) ;
if ( V_47 -> V_50 != - 1 ) {
V_43 -> V_48 = V_47 -> V_50 ;
break;
}
}
}
}
T_13 *
F_34 ( T_8 * V_39 , T_14 V_51 )
{
T_13 * V_52 = F_35 ( L_7 ) ;
T_9 V_5 ;
#ifdef F_27
if ( V_39 -> V_41 -> V_42 < 2 ) {
#else
if ( V_39 -> V_41 -> V_42 < 4 ) {
#endif
for ( V_5 = 0 ; V_5 < V_39 -> V_41 -> V_42 ; V_5 ++ ) {
if ( V_5 > 0 ) {
if ( V_39 -> V_41 -> V_42 > 2 ) {
F_36 ( V_52 , L_1 ) ;
}
F_36 ( V_52 , L_8 ) ;
if ( V_5 == V_39 -> V_41 -> V_42 - 1 ) {
F_36 ( V_52 , L_9 ) ;
}
}
if ( V_51 & V_53 )
F_36 ( V_52 , L_10 ) ;
F_36 ( V_52 , L_11 , F_29 ( V_39 , V_5 ) ) ;
if ( V_51 & V_53 )
F_36 ( V_52 , L_10 ) ;
if ( V_51 & V_54 ) {
T_10 V_40 ;
V_40 = F_30 ( V_39 -> V_41 , T_10 , V_5 ) ;
if ( V_40 . V_55 != NULL &&
strlen ( V_40 . V_55 ) > 0 ) {
F_36 ( V_52 , L_12 , V_40 . V_55 ) ;
}
}
}
} else {
F_36 ( V_52 , L_13 , V_39 -> V_41 -> V_42 ) ;
}
return V_52 ;
}
