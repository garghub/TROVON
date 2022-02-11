const char * F_1 ( T_1 * * V_1 , const char * V_2 )
{
int V_3 ;
char * V_4 , * V_5 ;
T_2 V_6 ;
unsigned long V_7 = 0 ;
#if V_8 == 64
# pragma V_9 V_10
# pragma V_9 V_11
char * V_12 ;
# pragma V_9 V_13
char V_14 [ V_15 + 1 ] ;
#endif
#ifdef F_2
V_7 |= V_16 ;
#endif
if ( V_1 == NULL || V_2 == NULL ) {
V_17 = V_18 ;
return 0 ;
}
V_17 = 0 ;
if ( * V_1 == NULL ) {
T_2 V_19 = strlen ( V_2 ) ;
char * V_20 = NULL ;
if ( V_19 == 0 ) {
V_17 = V_21 ;
return 0 ;
}
if ( V_2 [ V_19 - 1 ] != ']'
&& V_2 [ V_19 - 1 ] != '>'
&& V_2 [ V_19 - 1 ] != ':' ) {
V_17 = V_18 ;
return 0 ;
}
V_19 += 4 ;
if ( V_19 > V_15 ) {
V_17 = V_22 ;
return 0 ;
}
* V_1 = ( T_1 * ) malloc ( sizeof( T_1 ) ) ;
if ( * V_1 == NULL ) {
V_17 = V_23 ;
return 0 ;
}
memset ( * V_1 , '\0' , sizeof( T_1 ) ) ;
strcpy ( ( * V_1 ) -> V_20 , V_2 ) ;
strcat ( ( * V_1 ) -> V_20 , L_1 ) ;
#if V_8 == 64
# define F_3 ctx_filespec_32p
V_12 = V_14 ;
strcpy ( V_12 , ( * V_1 ) -> V_20 ) ;
#else
# define F_3 (*ctx)->filespec
#endif
( * V_1 ) -> V_24 . V_25 = V_19 ;
( * V_1 ) -> V_24 . V_26 = V_27 ;
( * V_1 ) -> V_24 . V_28 = V_29 ;
( * V_1 ) -> V_24 . V_30 = F_3 ;
}
( * V_1 ) -> V_31 . V_25 = 0 ;
( * V_1 ) -> V_31 . V_26 = V_27 ;
( * V_1 ) -> V_31 . V_28 = V_32 ;
( * V_1 ) -> V_31 . V_30 = 0 ;
V_3 = F_4 ( & ( * V_1 ) -> V_24 , & ( * V_1 ) -> V_31 ,
& ( * V_1 ) -> V_33 , 0 , 0 , 0 , & V_7 ) ;
if ( V_3 == V_34 ) {
V_17 = 0 ;
V_35 = V_3 ;
return NULL ;
}
if ( ! F_5 ( V_3 ) ) {
V_17 = V_36 ;
V_35 = V_3 ;
return NULL ;
}
V_6 = ( * V_1 ) -> V_31 . V_25 ;
V_4 = ( * V_1 ) -> V_31 . V_30 ;
V_5 = V_4 ;
for (; * V_4 ; V_4 ++ ) {
if ( * V_4 == '^' && V_4 [ 1 ] != '\0' ) {
V_4 ++ ;
} else if ( * V_4 == ':' || * V_4 == '>' || * V_4 == ']' ) {
V_6 -= V_4 + 1 - V_5 ;
V_5 = V_4 + 1 ;
} else if ( * V_4 == ';' ) {
V_6 = V_4 - V_5 ;
break;
}
}
strncpy ( ( * V_1 ) -> V_37 , V_5 , V_6 ) ;
( * V_1 ) -> V_37 [ V_6 ] = '\0' ;
F_6 ( & ( * V_1 ) -> V_31 ) ;
return ( * V_1 ) -> V_37 ;
}
int F_7 ( T_1 * * V_1 )
{
if ( V_1 != NULL && * V_1 != NULL ) {
int V_3 = F_8 ( & ( * V_1 ) -> V_33 ) ;
free ( * V_1 ) ;
if ( ! F_5 ( V_3 ) ) {
V_17 = V_36 ;
V_35 = V_3 ;
return 0 ;
}
return 1 ;
}
V_17 = V_18 ;
return 0 ;
}
