char * F_1 ( const char * V_1 )
{
int V_2 = 0 ;
const char * V_3 = V_1 ;
char * V_4 ;
char * V_5 ;
if ( ! V_3 )
return NULL ;
while ( * V_3 ) {
const unsigned char V_6 = * V_3 ++ ;
if ( V_6 == '\\' )
V_2 += 2 ;
else if ( V_6 > ' ' && V_6 < 127 )
V_2 ++ ;
else
V_2 += 4 ;
}
V_2 ++ ;
V_4 = F_2 ( V_2 + 10 , V_7 ) ;
if ( ! V_4 )
return NULL ;
V_5 = V_4 ;
V_3 = V_1 ;
while ( * V_3 ) {
const unsigned char V_6 = * V_3 ++ ;
if ( V_6 == '\\' ) {
* V_4 ++ = '\\' ;
* V_4 ++ = '\\' ;
} else if ( V_6 > ' ' && V_6 < 127 ) {
* V_4 ++ = V_6 ;
} else {
* V_4 ++ = '\\' ;
* V_4 ++ = ( V_6 >> 6 ) + '0' ;
* V_4 ++ = ( ( V_6 >> 3 ) & 7 ) + '0' ;
* V_4 ++ = ( V_6 & 7 ) + '0' ;
}
}
return V_5 ;
}
static char * F_3 ( struct V_8 * V_8 , char * const V_9 ,
const int V_10 )
{
char * V_11 = F_4 ( - V_12 ) ;
if ( V_10 >= 256 ) {
struct V_8 V_13 = { } ;
V_11 = F_5 ( V_8 , & V_13 , V_9 , V_10 - 1 ) ;
if ( ! F_6 ( V_11 ) && * V_11 == '/' && V_11 [ 1 ] ) {
struct V_14 * V_14 = V_8 -> V_15 -> V_16 ;
if ( V_14 && F_7 ( V_14 -> V_17 ) ) {
V_9 [ V_10 - 2 ] = '/' ;
V_9 [ V_10 - 1 ] = '\0' ;
}
}
}
return V_11 ;
}
static char * F_8 ( struct V_15 * V_15 , char * const V_9 ,
const int V_10 )
{
char * V_11 = F_4 ( - V_12 ) ;
if ( V_10 >= 256 ) {
V_11 = F_9 ( V_15 , V_9 , V_10 - 1 ) ;
if ( ! F_6 ( V_11 ) && * V_11 == '/' && V_11 [ 1 ] ) {
struct V_14 * V_14 = V_15 -> V_16 ;
if ( V_14 && F_7 ( V_14 -> V_17 ) ) {
V_9 [ V_10 - 2 ] = '/' ;
V_9 [ V_10 - 1 ] = '\0' ;
}
}
}
return V_11 ;
}
static char * F_10 ( struct V_15 * V_15 , char * const V_9 ,
const int V_10 )
{
struct V_18 * V_19 = V_15 -> V_20 ;
char * V_11 = F_8 ( V_15 , V_9 , V_10 ) ;
if ( F_6 ( V_11 ) )
return V_11 ;
if ( V_19 -> V_21 == V_22 && * V_11 == '/' ) {
char * V_23 ;
const T_1 V_24 = ( T_1 ) F_11 ( V_11 + 1 , & V_23 , 10 ) ;
if ( * V_23 == '/' && V_24 && V_24 ==
F_12 ( V_25 , V_19 -> V_26 ) ) {
V_11 = V_23 - 5 ;
if ( V_11 < V_9 )
goto V_27;
memmove ( V_11 , L_1 , 5 ) ;
}
goto V_28;
}
if ( ! F_13 ( V_19 -> V_29 ) )
goto V_28;
{
struct V_14 * V_14 = V_19 -> V_30 -> V_16 ;
if ( V_14 -> V_31 && ! V_14 -> V_31 -> rename )
goto V_28;
}
{
char V_32 [ 64 ] ;
int V_33 ;
const T_2 V_34 = V_19 -> V_29 ;
V_32 [ sizeof( V_32 ) - 1 ] = '\0' ;
snprintf ( V_32 , sizeof( V_32 ) - 1 , L_2 , F_13 ( V_34 ) ,
F_14 ( V_34 ) ) ;
V_33 = strlen ( V_32 ) ;
V_11 -= V_33 ;
if ( V_11 < V_9 )
goto V_27;
memmove ( V_11 , V_32 , V_33 ) ;
return V_11 ;
}
V_28:
{
const char * V_32 = V_19 -> V_35 -> V_32 ;
const int V_33 = strlen ( V_32 ) ;
V_11 -= V_33 + 1 ;
if ( V_11 < V_9 )
goto V_27;
memmove ( V_11 , V_32 , V_33 ) ;
V_11 [ V_33 ] = ':' ;
}
return V_11 ;
V_27:
return F_4 ( - V_12 ) ;
}
static char * F_15 ( struct V_8 * V_8 , char * const V_9 ,
const int V_10 )
{
struct V_14 * V_14 = V_8 -> V_15 -> V_16 ;
struct V_36 * V_37 = V_14 ? F_16 ( V_14 ) : NULL ;
struct V_37 * V_38 = V_37 ? V_37 -> V_38 : NULL ;
if ( V_38 ) {
snprintf ( V_9 , V_10 , L_3
L_4 , V_38 -> V_39 , V_38 -> V_40 ,
V_38 -> V_41 ) ;
} else {
snprintf ( V_9 , V_10 , L_5 ) ;
}
return V_9 ;
}
char * F_17 ( struct V_8 * V_8 )
{
char * V_42 = NULL ;
char * V_32 = NULL ;
unsigned int V_43 = V_44 / 2 ;
struct V_15 * V_15 = V_8 -> V_15 ;
struct V_18 * V_19 ;
if ( ! V_15 )
return NULL ;
V_19 = V_15 -> V_20 ;
while ( 1 ) {
char * V_11 ;
struct V_14 * V_14 ;
V_43 <<= 1 ;
F_18 ( V_42 ) ;
V_42 = F_19 ( V_43 , V_7 ) ;
if ( ! V_42 )
break;
V_42 [ V_43 - 1 ] = '\0' ;
if ( V_19 -> V_21 == V_45 ) {
V_11 = F_15 ( V_8 , V_42 , V_43 - 1 ) ;
goto V_46;
}
if ( V_15 -> V_47 && V_15 -> V_47 -> V_48 ) {
V_11 = V_15 -> V_47 -> V_48 ( V_15 , V_42 , V_43 - 1 ) ;
goto V_46;
}
V_14 = V_19 -> V_30 -> V_16 ;
if ( ! V_8 -> V_49 || ( V_14 -> V_31 && ! V_14 -> V_31 -> rename ) )
V_11 = F_10 ( V_8 -> V_15 , V_42 ,
V_43 - 1 ) ;
else
V_11 = F_3 ( V_8 , V_42 , V_43 - 1 ) ;
V_46:
if ( F_6 ( V_11 ) )
continue;
V_32 = F_1 ( V_11 ) ;
break;
}
F_18 ( V_42 ) ;
if ( ! V_32 )
F_20 ( V_50 ) ;
return V_32 ;
}
char * F_21 ( const char * V_51 )
{
struct V_8 V_8 ;
if ( V_51 && F_22 ( V_51 , 0 , & V_8 ) == 0 ) {
char * V_42 = F_17 ( & V_8 ) ;
F_23 ( & V_8 ) ;
return V_42 ;
}
return NULL ;
}
