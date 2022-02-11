static T_1 * F_1 ( T_2 * V_1 ,
T_1 * V_2 , T_3 V_3 )
{
T_1 * V_4 ;
if ( ( unsigned ) V_1 -> V_5 >= V_3 )
return NULL ;
V_4 = & V_2 [ V_1 -> V_5 ++ ] ;
V_4 -> V_6 = V_4 -> V_7 = - 1 ;
V_4 -> V_8 = 0 ;
return V_4 ;
}
static void F_2 ( T_1 * V_9 , T_4 type ,
int V_6 , int V_7 )
{
V_9 -> type = type ;
V_9 -> V_6 = V_6 ;
V_9 -> V_7 = V_7 ;
V_9 -> V_8 = 0 ;
}
static T_5 F_3 ( T_2 * V_1 , const char * V_10 ,
T_3 V_11 ,
T_1 * V_2 , T_3 V_3 )
{
T_1 * V_9 ;
int V_6 ;
V_6 = V_1 -> V_12 ;
for (; V_1 -> V_12 < V_11 ; V_1 -> V_12 ++ ) {
switch ( V_10 [ V_1 -> V_12 ] ) {
#ifndef F_4
case ':' :
#endif
case '\t' :
case '\r' :
case '\n' :
case ' ' :
case ',' :
case ']' :
case '}' :
goto V_13;
default:
break;
}
if ( V_10 [ V_1 -> V_12 ] < 32 || V_10 [ V_1 -> V_12 ] >= 127 ) {
V_1 -> V_12 = V_6 ;
return V_14 ;
}
}
#ifdef F_4
V_1 -> V_12 = V_6 ;
return V_15 ;
#endif
V_13:
V_9 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_9 == NULL ) {
V_1 -> V_12 = V_6 ;
return V_16 ;
}
F_2 ( V_9 , V_17 , V_6 , V_1 -> V_12 ) ;
V_1 -> V_12 -- ;
return V_18 ;
}
static T_5 F_5 ( T_2 * V_1 , const char * V_10 ,
T_3 V_11 ,
T_1 * V_2 , T_3 V_3 )
{
T_1 * V_9 ;
int V_6 = V_1 -> V_12 ;
V_1 -> V_12 ++ ;
for (; V_1 -> V_12 < V_11 ; V_1 -> V_12 ++ ) {
char V_19 = V_10 [ V_1 -> V_12 ] ;
if ( V_19 == '\"' ) {
V_9 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_9 == NULL ) {
V_1 -> V_12 = V_6 ;
return V_16 ;
}
F_2 ( V_9 , V_20 , V_6 + 1 ,
V_1 -> V_12 ) ;
return V_18 ;
}
if ( V_19 == '\\' ) {
V_1 -> V_12 ++ ;
switch ( V_10 [ V_1 -> V_12 ] ) {
case '\"' :
case '/' :
case '\\' :
case 'b' :
case 'f' :
case 'r' :
case 'n' :
case 't' :
break;
case 'u' :
break;
default:
V_1 -> V_12 = V_6 ;
return V_14 ;
}
}
}
V_1 -> V_12 = V_6 ;
return V_15 ;
}
T_5 F_6 ( T_2 * V_1 , const char * V_10 , T_3 V_11 ,
T_1 * V_2 , unsigned int V_3 )
{
T_5 V_21 ;
int V_22 ;
T_1 * V_9 ;
for (; V_1 -> V_12 < V_11 ; V_1 -> V_12 ++ ) {
char V_19 ;
T_4 type ;
V_19 = V_10 [ V_1 -> V_12 ] ;
switch ( V_19 ) {
case '{' :
case '[' :
V_9 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_9 == NULL )
return V_16 ;
if ( V_1 -> V_23 != - 1 )
V_2 [ V_1 -> V_23 ] . V_8 ++ ;
V_9 -> type = ( V_19 == '{' ? V_24 : V_25 ) ;
V_9 -> V_6 = V_1 -> V_12 ;
V_1 -> V_23 = V_1 -> V_5 - 1 ;
break;
case '}' :
case ']' :
type = ( V_19 == '}' ? V_24 : V_25 ) ;
for ( V_22 = V_1 -> V_5 - 1 ; V_22 >= 0 ; V_22 -- ) {
V_9 = & V_2 [ V_22 ] ;
if ( V_9 -> V_6 != - 1 && V_9 -> V_7 == - 1 ) {
if ( V_9 -> type != type )
return V_14 ;
V_1 -> V_23 = - 1 ;
V_9 -> V_7 = V_1 -> V_12 + 1 ;
break;
}
}
if ( V_22 == - 1 )
return V_14 ;
for (; V_22 >= 0 ; V_22 -- ) {
V_9 = & V_2 [ V_22 ] ;
if ( V_9 -> V_6 != - 1 && V_9 -> V_7 == - 1 ) {
V_1 -> V_23 = V_22 ;
break;
}
}
break;
case '\"' :
V_21 = F_5 ( V_1 , V_10 , V_11 , V_2 ,
V_3 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_1 -> V_23 != - 1 )
V_2 [ V_1 -> V_23 ] . V_8 ++ ;
break;
case '\t' :
case '\r' :
case '\n' :
case ':' :
case ',' :
case ' ' :
break;
#ifdef F_4
case '-' :
case '0' :
case '1' :
case '2' :
case '3' :
case '4' :
case '5' :
case '6' :
case '7' :
case '8' :
case '9' :
case 't' :
case 'f' :
case 'n' :
#else
default:
#endif
V_21 = F_3 ( V_1 , V_10 , V_11 , V_2 ,
V_3 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_1 -> V_23 != - 1 )
V_2 [ V_1 -> V_23 ] . V_8 ++ ;
break;
#ifdef F_4
default:
return V_14 ;
#endif
}
}
for ( V_22 = V_1 -> V_5 - 1 ; V_22 >= 0 ; V_22 -- ) {
if ( V_2 [ V_22 ] . V_6 != - 1 && V_2 [ V_22 ] . V_7 == - 1 )
return V_15 ;
}
return V_18 ;
}
void F_7 ( T_2 * V_1 )
{
V_1 -> V_12 = 0 ;
V_1 -> V_5 = 0 ;
V_1 -> V_23 = - 1 ;
}
const char * F_8 ( T_5 V_26 )
{
switch ( V_26 ) {
case V_16 :
return L_1 ;
case V_14 :
return L_2 ;
case V_15 :
return L_3 ;
case V_18 :
return L_4 ;
default:
return L_5 ;
}
}
