static void F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_1 * V_3 ;
T_3 * V_4 , * V_5 ;
T_4 * V_6 , * V_7 ;
for ( V_3 = F_2 ( V_8 , 0 ) ; V_3 != NULL ; V_3 = F_3 ( V_3 ) ) {
V_6 = ( T_4 * ) V_3 -> V_9 ;
V_7 = F_4 ( sizeof( T_4 ) ) ;
V_7 -> V_10 = F_5 ( V_6 -> V_10 ) ;
V_7 -> V_11 = F_5 ( V_6 -> V_11 ) ;
V_7 -> V_12 = F_5 ( V_6 -> V_12 ) ;
for ( V_2 = F_6 ( V_6 -> V_13 , 0 ) ; V_2 != NULL ; V_2 = F_7 ( V_2 ) ) {
V_5 = F_4 ( sizeof( T_3 ) ) ;
V_4 = ( T_3 * ) V_2 -> V_9 ;
if ( V_4 ) {
V_5 -> V_14 = V_4 -> V_14 ;
if ( V_5 -> V_14 == V_15 ) {
V_5 -> V_16 . V_17 = V_4 -> V_16 . V_17 ;
} else {
memcpy ( V_5 -> V_16 . V_18 , V_4 -> V_16 . V_18 , sizeof( V_4 -> V_16 ) ) ;
}
} else {
F_8 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 ) {
V_7 -> V_13 = F_9 ( V_7 -> V_13 , V_5 ) ;
}
}
V_7 -> V_19 = V_6 -> V_19 ;
V_1 = F_10 ( V_1 , V_7 ) ;
}
}
T_1 *
F_11 ( int * V_20 , char * * V_21 , void (* F_12)( void ) )
{
int V_22 ;
T_1 * V_23 = NULL ;
int V_24 , V_25 ;
T_5 * V_9 , * V_26 , * V_27 ;
T_5 * * V_28 , * * V_29 , * * V_30 ;
T_5 * V_10 ;
T_4 * V_6 ;
T_3 * V_4 ;
F_13 ( V_31 , V_32 , L_1 ) ;
* V_20 = 0 ;
#ifdef F_14
F_13 ( V_31 , V_32 , L_2 ) ;
V_23 = F_15 ( V_21 ) ;
#endif
V_22 = F_16 ( & V_9 , & V_26 , & V_27 , F_12 ) ;
if ( V_22 != 0 ) {
F_13 ( V_31 , V_32 , L_3 ,
* V_20 , V_26 ? V_26 : L_4 ,
V_27 ? V_27 : L_5 ) ;
if ( V_21 ) {
* V_21 = V_26 ;
} else {
F_8 ( V_26 ) ;
}
F_8 ( V_27 ) ;
* V_20 = V_33 ;
return NULL ;
}
#ifdef F_17
V_28 = F_18 ( V_9 , L_6 , 0 ) ;
#else
V_28 = F_18 ( V_9 , L_7 , 0 ) ;
#endif
F_8 ( V_9 ) ;
for ( V_24 = 0 ; V_28 [ V_24 ] != NULL ; V_24 ++ ) {
#ifdef F_14
V_29 = F_18 ( V_28 [ V_24 ] , L_8 , 7 ) ;
if ( V_29 [ 0 ] == NULL || V_29 [ 1 ] == NULL || V_29 [ 2 ] == NULL ||
V_29 [ 3 ] == NULL || V_29 [ 4 ] == NULL || V_29 [ 5 ] == NULL ||
V_29 [ 6 ] == NULL ) {
F_19 ( V_29 ) ;
continue;
}
#else
V_29 = F_18 ( V_28 [ V_24 ] , L_8 , 6 ) ;
if ( V_29 [ 0 ] == NULL || V_29 [ 1 ] == NULL || V_29 [ 2 ] == NULL ||
V_29 [ 3 ] == NULL || V_29 [ 4 ] == NULL || V_29 [ 5 ] == NULL ) {
F_19 ( V_29 ) ;
continue;
}
#endif
V_10 = strchr ( V_29 [ 0 ] , ' ' ) ;
if ( V_10 ) {
V_10 ++ ;
} else {
F_19 ( V_29 ) ;
continue;
}
V_6 = F_20 ( T_4 , 1 ) ;
V_6 -> V_10 = F_5 ( V_10 ) ;
if ( strlen ( V_29 [ 1 ] ) > 0 )
V_6 -> V_12 = F_5 ( V_29 [ 1 ] ) ;
if ( strlen ( V_29 [ 2 ] ) > 0 )
V_6 -> V_11 = F_5 ( V_29 [ 2 ] ) ;
V_6 -> type = ( V_34 ) ( int ) strtol ( V_29 [ 3 ] , NULL , 10 ) ;
V_30 = F_18 ( V_29 [ 4 ] , L_9 , 0 ) ;
for ( V_25 = 0 ; V_30 [ V_25 ] != NULL ; V_25 ++ ) {
V_4 = F_20 ( T_3 , 1 ) ;
if ( F_21 ( V_35 , V_30 [ V_25 ] , & V_4 -> V_16 . V_17 ) > 0 ) {
V_4 -> V_14 = V_15 ;
} else if ( F_21 ( V_36 , V_30 [ V_25 ] ,
& V_4 -> V_16 . V_18 ) > 0 ) {
V_4 -> V_14 = V_37 ;
} else {
F_8 ( V_4 ) ;
V_4 = NULL ;
}
if ( V_4 ) {
V_6 -> V_13 = F_9 ( V_6 -> V_13 , V_4 ) ;
}
}
if ( strcmp ( V_29 [ 5 ] , L_10 ) == 0 )
V_6 -> V_19 = TRUE ;
#ifdef F_14
V_6 -> V_38 = F_5 ( V_29 [ 6 ] ) ;
#endif
F_19 ( V_29 ) ;
F_19 ( V_30 ) ;
V_23 = F_10 ( V_23 , V_6 ) ;
}
F_19 ( V_28 ) ;
#ifdef F_22
if ( V_8 && F_23 ( V_8 ) > 0 ) {
F_1 ( V_23 ) ;
}
#endif
return V_23 ;
}
T_6 *
F_24 ( const T_5 * V_39 , T_7 V_40 ,
char * * V_21 , void (* F_12)( void ) )
{
T_6 * V_41 ;
T_1 * V_42 = NULL ;
int V_20 , V_24 ;
T_5 * V_9 , * V_26 , * V_27 ;
T_5 * * V_28 , * * V_43 ;
T_8 * V_44 ;
F_13 ( V_31 , V_32 , L_11 ) ;
#ifdef F_14
V_41 = F_25 ( V_39 , V_21 ) ;
if ( V_41 != NULL )
return V_41 ;
if ( V_21 != NULL && * V_21 != NULL )
return NULL ;
#endif
V_20 = F_26 ( V_39 , V_40 , & V_9 ,
& V_26 , & V_27 , F_12 ) ;
if ( V_20 != 0 ) {
F_13 ( V_31 , V_32 , L_12 ,
V_20 , V_26 ? V_26 : L_4 ,
V_27 ? V_27 : L_5 ) ;
if ( V_21 ) {
* V_21 = V_26 ;
} else {
F_8 ( V_26 ) ;
}
F_8 ( V_27 ) ;
return NULL ;
}
#ifdef F_17
V_28 = F_18 ( V_9 , L_6 , 0 ) ;
#else
V_28 = F_18 ( V_9 , L_7 , 0 ) ;
#endif
F_8 ( V_9 ) ;
if ( V_28 [ 0 ] == NULL || * V_28 [ 0 ] == '\0' ) {
F_13 ( V_31 , V_32 , L_13 ) ;
if ( V_21 ) {
* V_21 = F_5 ( L_14 ) ;
}
return NULL ;
}
V_41 = ( T_6 * ) F_27 ( sizeof *V_41 ) ;
switch ( * V_28 [ 0 ] ) {
case '0' :
V_41 -> V_45 = FALSE ;
break;
case '1' :
V_41 -> V_45 = TRUE ;
break;
default:
F_13 ( V_31 , V_32 , L_15 ) ;
if ( V_21 ) {
* V_21 = F_28 ( L_16 ,
V_28 [ 0 ] ) ;
}
F_8 ( V_41 ) ;
return NULL ;
}
for ( V_24 = 1 ; V_28 [ V_24 ] != NULL ; V_24 ++ ) {
V_43 = F_18 ( V_28 [ V_24 ] , L_8 , 3 ) ;
if ( V_43 [ 0 ] == NULL || V_43 [ 1 ] == NULL || V_43 [ 2 ] == NULL ) {
F_19 ( V_43 ) ;
continue;
}
V_44 = F_29 ( T_8 , 1 ) ;
V_44 -> V_46 = ( int ) strtol ( V_43 [ 0 ] , NULL , 10 ) ;
V_44 -> V_10 = F_5 ( V_43 [ 1 ] ) ;
if ( strcmp ( V_43 [ 2 ] , L_17 ) != 0 )
V_44 -> V_47 = F_5 ( V_43 [ 2 ] ) ;
else
V_44 -> V_47 = NULL ;
V_42 = F_10 ( V_42 , V_44 ) ;
}
F_19 ( V_28 ) ;
if ( V_42 == NULL ) {
if ( V_21 )
* V_21 = F_5 ( L_18 ) ;
F_8 ( V_41 ) ;
return NULL ;
}
V_41 -> V_48 = V_42 ;
return V_41 ;
}
void F_30 ( T_4 * V_6 )
{
T_2 * V_2 ;
T_3 * V_4 , * V_5 ;
T_4 * V_7 = F_4 ( sizeof( T_4 ) ) ;
V_7 -> V_10 = F_5 ( V_6 -> V_10 ) ;
V_7 -> V_11 = F_5 ( V_6 -> V_11 ) ;
V_7 -> V_12 = F_5 ( V_6 -> V_12 ) ;
for ( V_2 = F_6 ( V_6 -> V_13 , 0 ) ; V_2 != NULL ; V_2 = F_7 ( V_2 ) ) {
V_5 = F_4 ( sizeof( T_3 ) ) ;
V_4 = ( T_3 * ) V_2 -> V_9 ;
if ( V_4 ) {
V_5 -> V_14 = V_4 -> V_14 ;
if ( V_5 -> V_14 == V_15 ) {
V_5 -> V_16 . V_17 = V_4 -> V_16 . V_17 ;
} else {
memcpy ( V_5 -> V_16 . V_18 , V_4 -> V_16 . V_18 , sizeof( V_4 -> V_16 ) ) ;
}
} else {
F_8 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 ) {
V_7 -> V_13 = F_9 ( V_7 -> V_13 , V_5 ) ;
}
}
V_7 -> V_19 = V_6 -> V_19 ;
V_8 = F_10 ( V_8 , V_7 ) ;
}
