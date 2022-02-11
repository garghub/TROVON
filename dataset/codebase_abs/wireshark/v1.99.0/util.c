char *
F_1 ( int V_1 , char * * V_2 , int V_3 )
{
int V_4 ;
int V_5 ;
char * V_6 ;
V_4 = 0 ;
for ( V_5 = V_3 ; V_5 < V_1 ; V_5 ++ ) {
V_4 += ( int ) strlen ( V_2 [ V_5 ] ) ;
V_4 ++ ;
}
V_6 = ( char * ) F_2 ( V_4 ) ;
V_6 [ 0 ] = '\0' ;
V_5 = V_3 ;
for (; ; ) {
F_3 ( V_6 , V_2 [ V_5 ] , V_4 ) ;
V_5 ++ ;
if ( V_5 == V_1 )
break;
F_3 ( V_6 , L_1 , V_4 ) ;
}
return V_6 ;
}
void
F_4 ( T_1 * V_7 , T_1 * V_8 ,
T_2 V_9 , T_2 V_10 , T_2 V_11 , T_2 V_12 )
{
if ( V_9 == V_11 ) {
* V_7 = V_9 - V_11 ;
* V_8 = V_10 - V_12 ;
} else if ( V_9 <= V_11 ) {
* V_7 = V_9 - V_11 ;
if ( V_12 >= V_10 ) {
* V_8 = V_10 - V_12 ;
} else {
* V_8 = ( V_10 - 1000000 ) - V_12 ;
( * V_7 ) ++ ;
}
} else {
* V_7 = V_9 - V_11 ;
if ( V_12 <= V_10 ) {
* V_8 = V_10 - V_12 ;
} else {
* V_8 = ( V_10 + 1000000 ) - V_12 ;
( * V_7 ) -- ;
}
}
}
static char * F_5 ( char * V_13 ) {
T_3 * V_14 ;
T_3 * V_15 ;
V_15 = F_6 ( V_13 ) ;
if ( ! V_15 )
return NULL ;
V_14 = strchr ( V_15 , '%' ) ;
if ( V_14 )
* V_14 = '\0' ;
return V_15 ;
}
const T_3 * F_7 ( void ) {
static T_4 * V_16 = NULL ;
T_3 * V_17 , * * V_18 ;
char * V_19 , * V_20 , * V_21 ;
char * V_22 = NULL ;
char * V_23 = NULL ;
T_5 V_24 ;
char * V_25 , * V_26 ;
if ( V_16 == NULL ) {
V_16 = F_8 ( L_2 ) ;
}
if ( ( V_17 = getenv ( L_3 ) ) != NULL ) {
V_18 = F_9 ( V_17 , L_1 , 4 ) ;
if ( F_10 ( V_18 ) == 4 ) {
V_25 = F_5 ( V_18 [ 0 ] ) ;
V_26 = F_5 ( V_18 [ 2 ] ) ;
F_11 ( V_16 , L_4
L_5 , V_18 [ 1 ] , F_12 ( V_25 ) , V_25 ,
V_18 [ 3 ] , F_12 ( V_26 ) , V_26 ) ;
F_13 ( V_25 ) ;
F_13 ( V_26 ) ;
}
F_14 ( V_18 ) ;
} else if ( ( V_17 = getenv ( L_6 ) ) != NULL ) {
V_18 = F_9 ( V_17 , L_1 , 3 ) ;
if ( F_10 ( V_18 ) == 3 ) {
V_25 = F_5 ( V_18 [ 2 ] ) ;
F_11 ( V_16 , L_4
L_7 , V_18 [ 1 ] , F_12 ( V_25 ) , V_18 [ 0 ] , V_25 ) ;
F_13 ( V_25 ) ;
}
F_14 ( V_18 ) ;
} else if ( ( V_17 = getenv ( L_8 ) ) != NULL ) {
if ( F_15 ( V_17 , L_9 ) == 0 ||
strcmp ( V_17 , L_10 ) == 0 ||
strcmp ( V_17 , L_2 ) == 0 ) {
return L_2 ;
}
V_25 = F_5 ( V_17 ) ;
F_11 ( V_16 , L_11 , F_12 ( V_25 ) , V_25 ) ;
F_13 ( V_25 ) ;
} else if ( ( V_17 = getenv ( L_12 ) ) != NULL ) {
V_21 = V_17 ;
for ( V_19 = V_21 ; * V_21 != '\0' && * V_21 != ':' && * V_21 != '/' ; V_21 ++ )
;
if ( * V_21 == '\0' )
return L_2 ;
if ( V_21 != V_19 && * V_21 != ':' ) {
V_22 = V_21 ;
if ( V_21 - V_19 != 3 || F_16 ( V_19 , L_13 , 3 ) != 0 )
return L_2 ;
V_21 ++ ;
} else
V_21 = V_17 ;
V_19 = V_21 ;
V_20 = NULL ;
for (; * V_21 != '\0' ; V_21 ++ )
if ( * V_21 == ':' )
V_20 = V_21 ;
if ( V_20 == NULL )
return L_2 ;
if ( ( V_19 != V_20 ) && ( * ( V_20 - 1 ) == ':' )
&& ( ( ( V_20 - 1 ) == V_19 ) || ( * ( V_20 - 2 ) != ':' ) ) ) {
return L_2 ;
} else
V_24 = V_20 - V_19 ;
if ( V_24 == 0 )
return L_2 ;
V_23 = ( char * ) F_2 ( V_24 + 1 ) ;
memcpy ( V_23 , V_19 , V_24 ) ;
V_23 [ V_24 ] = '\0' ;
if ( V_22 == NULL ) {
if ( F_15 ( V_23 , L_9 ) == 0 ||
strcmp ( V_23 , L_10 ) == 0 ) {
F_13 ( V_23 ) ;
return L_2 ;
}
if ( strcmp ( V_23 , L_14 ) == 0 ) {
F_13 ( V_23 ) ;
return L_2 ;
}
if ( V_23 [ 0 ] == '/' ) {
F_13 ( V_23 ) ;
return L_2 ;
}
}
F_11 ( V_16 , L_11 ,
F_12 ( V_23 ) , V_23 ) ;
F_13 ( V_23 ) ;
#ifdef F_17
} else if ( F_18 ( V_27 ) ) {
F_11 ( V_16 , L_15 ) ;
#endif
} else {
return L_2 ;
}
return V_16 -> V_28 ;
}
