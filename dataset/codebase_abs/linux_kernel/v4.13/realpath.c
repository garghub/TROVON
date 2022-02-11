char * F_1 ( const char * V_1 , int V_2 )
{
int V_3 ;
int V_4 = 0 ;
const char * V_5 = V_1 ;
char * V_6 ;
char * V_7 ;
if ( ! V_5 )
return NULL ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
const unsigned char V_8 = V_5 [ V_3 ] ;
if ( V_8 == '\\' )
V_4 += 2 ;
else if ( V_8 > ' ' && V_8 < 127 )
V_4 ++ ;
else
V_4 += 4 ;
}
V_4 ++ ;
V_6 = F_2 ( V_4 + 10 , V_9 ) ;
if ( ! V_6 )
return NULL ;
V_7 = V_6 ;
V_5 = V_1 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
const unsigned char V_8 = V_5 [ V_3 ] ;
if ( V_8 == '\\' ) {
* V_6 ++ = '\\' ;
* V_6 ++ = '\\' ;
} else if ( V_8 > ' ' && V_8 < 127 ) {
* V_6 ++ = V_8 ;
} else {
* V_6 ++ = '\\' ;
* V_6 ++ = ( V_8 >> 6 ) + '0' ;
* V_6 ++ = ( ( V_8 >> 3 ) & 7 ) + '0' ;
* V_6 ++ = ( V_8 & 7 ) + '0' ;
}
}
return V_7 ;
}
char * F_3 ( const char * V_1 )
{
return V_1 ? F_1 ( V_1 , strlen ( V_1 ) ) : NULL ;
}
static char * F_4 ( const struct V_10 * V_10 , char * const V_11 ,
const int V_12 )
{
char * V_13 = F_5 ( - V_14 ) ;
if ( V_12 >= 256 ) {
V_13 = F_6 ( V_10 , V_11 , V_12 - 1 ) ;
if ( ! F_7 ( V_13 ) && * V_13 == '/' && V_13 [ 1 ] ) {
struct V_15 * V_15 = F_8 ( V_10 -> V_16 ) ;
if ( V_15 && F_9 ( V_15 -> V_17 ) ) {
V_11 [ V_12 - 2 ] = '/' ;
V_11 [ V_12 - 1 ] = '\0' ;
}
}
}
return V_13 ;
}
static char * F_10 ( struct V_16 * V_16 , char * const V_11 ,
const int V_12 )
{
char * V_13 = F_5 ( - V_14 ) ;
if ( V_12 >= 256 ) {
V_13 = F_11 ( V_16 , V_11 , V_12 - 1 ) ;
if ( ! F_7 ( V_13 ) && * V_13 == '/' && V_13 [ 1 ] ) {
struct V_15 * V_15 = F_8 ( V_16 ) ;
if ( V_15 && F_9 ( V_15 -> V_17 ) ) {
V_11 [ V_12 - 2 ] = '/' ;
V_11 [ V_12 - 1 ] = '\0' ;
}
}
}
return V_13 ;
}
static char * F_12 ( struct V_16 * V_16 , char * const V_11 ,
const int V_12 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
char * V_13 = F_10 ( V_16 , V_11 , V_12 ) ;
if ( F_7 ( V_13 ) )
return V_13 ;
if ( V_19 -> V_21 == V_22 && * V_13 == '/' ) {
char * V_23 ;
const T_1 V_24 = ( T_1 ) F_13 ( V_13 + 1 , & V_23 , 10 ) ;
if ( * V_23 == '/' && V_24 && V_24 ==
F_14 ( V_25 , V_19 -> V_26 ) ) {
V_13 = V_23 - 5 ;
if ( V_13 < V_11 )
goto V_27;
memmove ( V_13 , L_1 , 5 ) ;
}
goto V_28;
}
if ( ! F_15 ( V_19 -> V_29 ) )
goto V_28;
{
struct V_15 * V_15 = F_8 ( V_19 -> V_30 ) ;
if ( ! V_15 -> V_31 -> rename )
goto V_28;
}
{
char V_32 [ 64 ] ;
int V_33 ;
const T_2 V_34 = V_19 -> V_29 ;
V_32 [ sizeof( V_32 ) - 1 ] = '\0' ;
snprintf ( V_32 , sizeof( V_32 ) - 1 , L_2 , F_15 ( V_34 ) ,
F_16 ( V_34 ) ) ;
V_33 = strlen ( V_32 ) ;
V_13 -= V_33 ;
if ( V_13 < V_11 )
goto V_27;
memmove ( V_13 , V_32 , V_33 ) ;
return V_13 ;
}
V_28:
{
const char * V_32 = V_19 -> V_35 -> V_32 ;
const int V_33 = strlen ( V_32 ) ;
V_13 -= V_33 + 1 ;
if ( V_13 < V_11 )
goto V_27;
memmove ( V_13 , V_32 , V_33 ) ;
V_13 [ V_33 ] = ':' ;
}
return V_13 ;
V_27:
return F_5 ( - V_14 ) ;
}
static char * F_17 ( const struct V_10 * V_10 , char * const V_11 ,
const int V_12 )
{
struct V_15 * V_15 = F_8 ( V_10 -> V_16 ) ;
struct V_36 * V_37 = V_15 ? F_18 ( V_15 ) : NULL ;
struct V_37 * V_38 = V_37 ? V_37 -> V_38 : NULL ;
if ( V_38 ) {
snprintf ( V_11 , V_12 , L_3
L_4 , V_38 -> V_39 , V_38 -> V_40 ,
V_38 -> V_41 ) ;
} else {
snprintf ( V_11 , V_12 , L_5 ) ;
}
return V_11 ;
}
char * F_19 ( const struct V_10 * V_10 )
{
char * V_42 = NULL ;
char * V_32 = NULL ;
unsigned int V_43 = V_44 / 2 ;
struct V_16 * V_16 = V_10 -> V_16 ;
struct V_18 * V_19 ;
if ( ! V_16 )
return NULL ;
V_19 = V_16 -> V_20 ;
while ( 1 ) {
char * V_13 ;
struct V_15 * V_15 ;
V_43 <<= 1 ;
F_20 ( V_42 ) ;
V_42 = F_21 ( V_43 , V_9 ) ;
if ( ! V_42 )
break;
V_42 [ V_43 - 1 ] = '\0' ;
if ( V_19 -> V_21 == V_45 ) {
V_13 = F_17 ( V_10 , V_42 , V_43 - 1 ) ;
goto V_46;
}
if ( V_16 -> V_47 && V_16 -> V_47 -> V_48 ) {
V_13 = V_16 -> V_47 -> V_48 ( V_16 , V_42 , V_43 - 1 ) ;
goto V_46;
}
V_15 = F_8 ( V_19 -> V_30 ) ;
if ( ! V_10 -> V_49 ||
( ! V_15 -> V_31 -> rename ) )
V_13 = F_12 ( V_10 -> V_16 , V_42 ,
V_43 - 1 ) ;
else {
V_13 = F_4 ( V_10 , V_42 , V_43 - 1 ) ;
if ( V_13 == F_5 ( - V_50 ) )
V_13 = F_12 ( V_10 -> V_16 , V_42 ,
V_43 - 1 ) ;
}
V_46:
if ( F_7 ( V_13 ) )
continue;
V_32 = F_3 ( V_13 ) ;
break;
}
F_20 ( V_42 ) ;
if ( ! V_32 )
F_22 ( V_51 ) ;
return V_32 ;
}
char * F_23 ( const char * V_52 )
{
struct V_10 V_10 ;
if ( V_52 && F_24 ( V_52 , 0 , & V_10 ) == 0 ) {
char * V_42 = F_19 ( & V_10 ) ;
F_25 ( & V_10 ) ;
return V_42 ;
}
return NULL ;
}
