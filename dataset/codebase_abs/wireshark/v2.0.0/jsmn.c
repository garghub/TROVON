static T_1 * F_1 ( T_2 * V_1 ,
T_1 * V_2 , T_3 V_3 ) {
T_1 * V_4 ;
if ( V_1 -> V_5 >= V_3 ) {
return NULL ;
}
V_4 = & V_2 [ V_1 -> V_5 ++ ] ;
V_4 -> V_6 = V_4 -> V_7 = - 1 ;
V_4 -> V_8 = 0 ;
#ifdef F_2
V_4 -> V_9 = - 1 ;
#endif
return V_4 ;
}
static void F_3 ( T_1 * V_10 , T_4 type ,
int V_6 , int V_7 ) {
V_10 -> type = type ;
V_10 -> V_6 = V_6 ;
V_10 -> V_7 = V_7 ;
V_10 -> V_8 = 0 ;
}
static int F_4 ( T_2 * V_1 , const char * V_11 ,
T_3 V_12 , T_1 * V_2 , T_3 V_3 ) {
T_1 * V_10 ;
int V_6 ;
V_6 = V_1 -> V_13 ;
for (; V_1 -> V_13 < V_12 && V_11 [ V_1 -> V_13 ] != '\0' ; V_1 -> V_13 ++ ) {
switch ( V_11 [ V_1 -> V_13 ] ) {
#ifndef F_5
case ':' :
#endif
case '\t' : case '\r' : case '\n' : case ' ' :
case ',' : case ']' : case '}' :
goto V_14;
}
if ( V_11 [ V_1 -> V_13 ] < 32 || V_11 [ V_1 -> V_13 ] >= 127 ) {
V_1 -> V_13 = V_6 ;
return V_15 ;
}
}
#ifdef F_5
V_1 -> V_13 = V_6 ;
return V_16 ;
#endif
V_14:
if ( V_2 == NULL ) {
V_1 -> V_13 -- ;
return 0 ;
}
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_10 == NULL ) {
V_1 -> V_13 = V_6 ;
return V_17 ;
}
F_3 ( V_10 , V_18 , V_6 , V_1 -> V_13 ) ;
#ifdef F_2
V_10 -> V_9 = V_1 -> V_19 ;
#endif
V_1 -> V_13 -- ;
return 0 ;
}
static int F_6 ( T_2 * V_1 , const char * V_11 ,
T_3 V_12 , T_1 * V_2 , T_3 V_3 ) {
T_1 * V_10 ;
int V_6 = V_1 -> V_13 ;
V_1 -> V_13 ++ ;
for (; V_1 -> V_13 < V_12 && V_11 [ V_1 -> V_13 ] != '\0' ; V_1 -> V_13 ++ ) {
char V_20 = V_11 [ V_1 -> V_13 ] ;
if ( V_20 == '\"' ) {
if ( V_2 == NULL ) {
return 0 ;
}
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_10 == NULL ) {
V_1 -> V_13 = V_6 ;
return V_17 ;
}
F_3 ( V_10 , V_21 , V_6 + 1 , V_1 -> V_13 ) ;
#ifdef F_2
V_10 -> V_9 = V_1 -> V_19 ;
#endif
return 0 ;
}
if ( V_20 == '\\' && V_1 -> V_13 + 1 < V_12 ) {
int V_22 ;
V_1 -> V_13 ++ ;
switch ( V_11 [ V_1 -> V_13 ] ) {
case '\"' : case '/' : case '\\' : case 'b' :
case 'f' : case 'r' : case 'n' : case 't' :
break;
case 'u' :
V_1 -> V_13 ++ ;
for( V_22 = 0 ; V_22 < 4 && V_1 -> V_13 < V_12 && V_11 [ V_1 -> V_13 ] != '\0' ; V_22 ++ ) {
if( ! ( ( V_11 [ V_1 -> V_13 ] >= 48 && V_11 [ V_1 -> V_13 ] <= 57 ) ||
( V_11 [ V_1 -> V_13 ] >= 65 && V_11 [ V_1 -> V_13 ] <= 70 ) ||
( V_11 [ V_1 -> V_13 ] >= 97 && V_11 [ V_1 -> V_13 ] <= 102 ) ) ) {
V_1 -> V_13 = V_6 ;
return V_15 ;
}
V_1 -> V_13 ++ ;
}
V_1 -> V_13 -- ;
break;
default:
V_1 -> V_13 = V_6 ;
return V_15 ;
}
}
}
V_1 -> V_13 = V_6 ;
return V_16 ;
}
int F_7 ( T_2 * V_1 , const char * V_11 , T_3 V_12 ,
T_1 * V_2 , unsigned int V_3 ) {
int V_23 ;
int V_22 ;
T_1 * V_10 ;
int V_24 = 0 ;
for (; V_1 -> V_13 < V_12 && V_11 [ V_1 -> V_13 ] != '\0' ; V_1 -> V_13 ++ ) {
char V_20 ;
T_4 type ;
V_20 = V_11 [ V_1 -> V_13 ] ;
switch ( V_20 ) {
case '{' : case '[' :
V_24 ++ ;
if ( V_2 == NULL ) {
break;
}
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_10 == NULL )
return V_17 ;
if ( V_1 -> V_19 != - 1 ) {
V_2 [ V_1 -> V_19 ] . V_8 ++ ;
#ifdef F_2
V_10 -> V_9 = V_1 -> V_19 ;
#endif
}
V_10 -> type = ( V_20 == '{' ? V_25 : V_26 ) ;
V_10 -> V_6 = V_1 -> V_13 ;
V_1 -> V_19 = V_1 -> V_5 - 1 ;
break;
case '}' : case ']' :
if ( V_2 == NULL )
break;
type = ( V_20 == '}' ? V_25 : V_26 ) ;
#ifdef F_2
if ( V_1 -> V_5 < 1 ) {
return V_15 ;
}
V_10 = & V_2 [ V_1 -> V_5 - 1 ] ;
for (; ; ) {
if ( V_10 -> V_6 != - 1 && V_10 -> V_7 == - 1 ) {
if ( V_10 -> type != type ) {
return V_15 ;
}
V_10 -> V_7 = V_1 -> V_13 + 1 ;
V_1 -> V_19 = V_10 -> V_9 ;
break;
}
if ( V_10 -> V_9 == - 1 ) {
break;
}
V_10 = & V_2 [ V_10 -> V_9 ] ;
}
#else
for ( V_22 = V_1 -> V_5 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_10 = & V_2 [ V_22 ] ;
if ( V_10 -> V_6 != - 1 && V_10 -> V_7 == - 1 ) {
if ( V_10 -> type != type ) {
return V_15 ;
}
V_1 -> V_19 = - 1 ;
V_10 -> V_7 = V_1 -> V_13 + 1 ;
break;
}
}
if ( V_22 == - 1 ) return V_15 ;
for (; V_22 >= 0 ; V_22 -- ) {
V_10 = & V_2 [ V_22 ] ;
if ( V_10 -> V_6 != - 1 && V_10 -> V_7 == - 1 ) {
V_1 -> V_19 = V_22 ;
break;
}
}
#endif
break;
case '\"' :
V_23 = F_6 ( V_1 , V_11 , V_12 , V_2 , V_3 ) ;
if ( V_23 < 0 ) return V_23 ;
V_24 ++ ;
if ( V_1 -> V_19 != - 1 && V_2 != NULL )
V_2 [ V_1 -> V_19 ] . V_8 ++ ;
break;
case '\t' : case '\r' : case '\n' : case ' ' :
break;
case ':' :
V_1 -> V_19 = V_1 -> V_5 - 1 ;
break;
case ',' :
if ( V_2 != NULL && V_1 -> V_19 != - 1 &&
V_2 [ V_1 -> V_19 ] . type != V_26 &&
V_2 [ V_1 -> V_19 ] . type != V_25 ) {
#ifdef F_2
V_1 -> V_19 = V_2 [ V_1 -> V_19 ] . V_9 ;
#else
for ( V_22 = V_1 -> V_5 - 1 ; V_22 >= 0 ; V_22 -- ) {
if ( V_2 [ V_22 ] . type == V_26 || V_2 [ V_22 ] . type == V_25 ) {
if ( V_2 [ V_22 ] . V_6 != - 1 && V_2 [ V_22 ] . V_7 == - 1 ) {
V_1 -> V_19 = V_22 ;
break;
}
}
}
#endif
}
break;
#ifdef F_5
case '-' : case '0' : case '1' : case '2' : case '3' : case '4' :
case '5' : case '6' : case '7' : case '8' : case '9' :
case 't' : case 'f' : case 'n' :
if ( V_2 != NULL && V_1 -> V_19 != - 1 ) {
T_1 * V_27 = & V_2 [ V_1 -> V_19 ] ;
if ( V_27 -> type == V_25 ||
( V_27 -> type == V_21 && V_27 -> V_8 != 0 ) ) {
return V_15 ;
}
}
#else
default:
#endif
V_23 = F_4 ( V_1 , V_11 , V_12 , V_2 , V_3 ) ;
if ( V_23 < 0 ) return V_23 ;
V_24 ++ ;
if ( V_1 -> V_19 != - 1 && V_2 != NULL )
V_2 [ V_1 -> V_19 ] . V_8 ++ ;
break;
#ifdef F_5
default:
return V_15 ;
#endif
}
}
if ( V_2 != NULL ) {
for ( V_22 = V_1 -> V_5 - 1 ; V_22 >= 0 ; V_22 -- ) {
if ( V_2 [ V_22 ] . V_6 != - 1 && V_2 [ V_22 ] . V_7 == - 1 ) {
return V_16 ;
}
}
}
return V_24 ;
}
void F_8 ( T_2 * V_1 ) {
V_1 -> V_13 = 0 ;
V_1 -> V_5 = 0 ;
V_1 -> V_19 = - 1 ;
}
T_5 F_9 ( const T_6 * V_28 , const T_3 V_12 )
{
T_7 V_29 = 1024 ;
T_1 * V_27 ;
T_2 V_30 ;
T_5 V_31 = TRUE ;
int V_32 ;
V_27 = F_10 ( T_1 , V_29 ) ;
if ( ! V_27 )
return FALSE ;
F_8 ( & V_30 ) ;
V_32 = F_7 ( & V_30 , V_28 , V_12 , V_27 , V_29 ) ;
if ( V_32 < 0 ) {
switch ( V_32 ) {
case V_17 :
F_11 ( V_33 , V_34 , L_1 ) ;
break;
case V_15 :
F_11 ( V_33 , V_34 , L_2 ) ;
break;
case V_16 :
F_11 ( V_33 , V_34 , L_3
L_4 ) ;
break;
default:
F_11 ( V_33 , V_34 , L_5 ) ;
break;
}
V_31 = FALSE ;
}
F_12 ( V_27 ) ;
return V_31 ;
}
