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
for ( V_2 = F_6 ( V_6 -> V_12 , 0 ) ; V_2 != NULL ; V_2 = F_7 ( V_2 ) ) {
V_5 = F_4 ( sizeof( T_3 ) ) ;
V_4 = ( T_3 * ) V_2 -> V_9 ;
if ( V_4 ) {
V_5 -> V_13 = V_4 -> V_13 ;
if ( V_5 -> V_13 == V_14 ) {
V_5 -> V_15 . V_16 = V_4 -> V_15 . V_16 ;
} else {
memcpy ( V_5 -> V_15 . V_17 , V_4 -> V_15 . V_17 , sizeof( V_4 -> V_15 ) ) ;
}
} else {
F_8 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 ) {
V_7 -> V_12 = F_9 ( V_7 -> V_12 , V_5 ) ;
}
}
V_7 -> V_18 = V_6 -> V_18 ;
V_1 = F_10 ( V_1 , V_7 ) ;
}
}
T_1 *
F_11 ( int * V_19 , char * * V_20 )
{
int V_21 ;
T_1 * V_22 = NULL ;
int V_23 , V_24 ;
T_5 * V_9 , * V_25 , * V_26 ;
T_5 * * V_27 , * * V_28 , * * V_29 ;
T_5 * V_10 ;
T_4 * V_6 ;
T_3 * V_4 ;
F_12 ( V_30 , V_31 , L_1 ) ;
V_21 = F_13 ( & V_9 , & V_25 , & V_26 ) ;
if ( V_21 != 0 ) {
F_12 ( V_30 , V_31 , L_2 ) ;
if ( V_20 ) {
* V_20 = V_25 ;
} else {
F_8 ( V_25 ) ;
}
F_8 ( V_26 ) ;
* V_19 = V_32 ;
return NULL ;
}
#ifdef F_14
V_27 = F_15 ( V_9 , L_3 , 0 ) ;
#else
V_27 = F_15 ( V_9 , L_4 , 0 ) ;
#endif
F_8 ( V_9 ) ;
for ( V_23 = 0 ; V_27 [ V_23 ] != NULL ; V_23 ++ ) {
V_28 = F_15 ( V_27 [ V_23 ] , L_5 , 4 ) ;
if ( V_28 [ 0 ] == NULL || V_28 [ 1 ] == NULL || V_28 [ 2 ] == NULL ||
V_28 [ 3 ] == NULL ) {
F_16 ( V_28 ) ;
continue;
}
V_10 = strchr ( V_28 [ 0 ] , ' ' ) ;
if ( V_10 ) {
V_10 ++ ;
} else {
F_16 ( V_28 ) ;
continue;
}
V_6 = F_4 ( sizeof( T_4 ) ) ;
V_6 -> V_10 = F_5 ( V_10 ) ;
if ( strlen ( V_28 [ 1 ] ) > 0 )
V_6 -> V_11 = F_5 ( V_28 [ 1 ] ) ;
V_29 = F_15 ( V_28 [ 2 ] , L_6 , 0 ) ;
for ( V_24 = 0 ; V_29 [ V_24 ] != NULL ; V_24 ++ ) {
V_4 = F_4 ( sizeof( T_3 ) ) ;
if ( F_17 ( V_33 , V_29 [ V_24 ] , & V_4 -> V_15 . V_16 ) ) {
V_4 -> V_13 = V_14 ;
} else if ( F_17 ( V_34 , V_29 [ V_24 ] ,
& V_4 -> V_15 . V_17 ) ) {
V_4 -> V_13 = V_35 ;
} else {
F_8 ( V_4 ) ;
V_4 = NULL ;
}
if ( V_4 ) {
V_6 -> V_12 = F_9 ( V_6 -> V_12 , V_4 ) ;
}
}
if ( strcmp ( V_28 [ 3 ] , L_7 ) == 0 )
V_6 -> V_18 = TRUE ;
F_16 ( V_28 ) ;
F_16 ( V_29 ) ;
V_22 = F_10 ( V_22 , V_6 ) ;
}
F_16 ( V_27 ) ;
if ( V_22 == NULL ) {
* V_19 = V_36 ;
if ( V_20 )
* V_20 = F_5 ( L_8 ) ;
}
#ifdef F_18
if ( V_8 && F_19 ( V_8 ) > 0 ) {
F_1 ( V_22 ) ;
}
#endif
return V_22 ;
}
T_6 *
F_20 ( const T_5 * V_37 , T_7 V_38 ,
char * * V_20 )
{
T_6 * V_39 ;
T_1 * V_40 = NULL ;
int V_19 , V_23 ;
T_5 * V_9 , * V_25 , * V_26 ;
T_5 * * V_27 , * * V_41 ;
T_8 * V_42 ;
F_12 ( V_30 , V_31 , L_9 ) ;
V_19 = F_21 ( V_37 , V_38 , & V_9 ,
& V_25 , & V_26 ) ;
if ( V_19 != 0 ) {
F_12 ( V_30 , V_31 , L_10 ) ;
if ( V_20 ) {
* V_20 = V_25 ;
} else {
F_8 ( V_25 ) ;
}
F_8 ( V_26 ) ;
return NULL ;
}
#ifdef F_14
V_27 = F_15 ( V_9 , L_3 , 0 ) ;
#else
V_27 = F_15 ( V_9 , L_4 , 0 ) ;
#endif
F_8 ( V_9 ) ;
if ( V_27 [ 0 ] == NULL || * V_27 [ 0 ] == '\0' ) {
F_12 ( V_30 , V_31 , L_11 ) ;
if ( V_20 ) {
* V_20 = F_5 ( L_12 ) ;
}
return NULL ;
}
V_39 = F_22 ( sizeof *V_39 ) ;
switch ( * V_27 [ 0 ] ) {
case '0' :
V_39 -> V_43 = FALSE ;
break;
case '1' :
V_39 -> V_43 = TRUE ;
break;
default:
F_12 ( V_30 , V_31 , L_13 ) ;
if ( V_20 ) {
* V_20 = F_23 ( L_14 ,
V_27 [ 0 ] ) ;
}
F_8 ( V_39 ) ;
return NULL ;
}
for ( V_23 = 1 ; V_27 [ V_23 ] != NULL ; V_23 ++ ) {
V_41 = F_15 ( V_27 [ V_23 ] , L_5 , 3 ) ;
if ( V_41 [ 0 ] == NULL || V_41 [ 1 ] == NULL || V_41 [ 2 ] == NULL ) {
F_16 ( V_41 ) ;
continue;
}
V_42 = F_22 ( sizeof ( T_8 ) ) ;
V_42 -> V_44 = ( int ) strtol ( V_41 [ 0 ] , NULL , 10 ) ;
V_42 -> V_10 = F_5 ( V_41 [ 1 ] ) ;
if ( strcmp ( V_41 [ 2 ] , L_15 ) != 0 )
V_42 -> V_11 = F_5 ( V_41 [ 2 ] ) ;
else
V_42 -> V_11 = NULL ;
V_40 = F_10 ( V_40 , V_42 ) ;
}
F_16 ( V_27 ) ;
if ( V_40 == NULL ) {
if ( V_20 )
* V_20 = F_5 ( L_16 ) ;
F_8 ( V_39 ) ;
return NULL ;
}
V_39 -> V_45 = V_40 ;
return V_39 ;
}
void F_24 ( T_4 * V_6 )
{
T_2 * V_2 ;
T_3 * V_4 , * V_5 ;
T_4 * V_7 = F_4 ( sizeof( T_4 ) ) ;
V_7 -> V_10 = F_5 ( V_6 -> V_10 ) ;
V_7 -> V_11 = F_5 ( V_6 -> V_11 ) ;
for ( V_2 = F_6 ( V_6 -> V_12 , 0 ) ; V_2 != NULL ; V_2 = F_7 ( V_2 ) ) {
V_5 = F_4 ( sizeof( T_3 ) ) ;
V_4 = ( T_3 * ) V_2 -> V_9 ;
if ( V_4 ) {
V_5 -> V_13 = V_4 -> V_13 ;
if ( V_5 -> V_13 == V_14 ) {
V_5 -> V_15 . V_16 = V_4 -> V_15 . V_16 ;
} else {
memcpy ( V_5 -> V_15 . V_17 , V_4 -> V_15 . V_17 , sizeof( V_4 -> V_15 ) ) ;
}
} else {
F_8 ( V_5 ) ;
V_5 = NULL ;
}
if ( V_5 ) {
V_7 -> V_12 = F_9 ( V_7 -> V_12 , V_5 ) ;
}
}
V_7 -> V_18 = V_6 -> V_18 ;
V_8 = F_10 ( V_8 , V_7 ) ;
}
