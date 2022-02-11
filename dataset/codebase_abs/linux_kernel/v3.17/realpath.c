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
static char * F_4 ( struct V_10 * V_10 , char * const V_11 ,
const int V_12 )
{
char * V_13 = F_5 ( - V_14 ) ;
if ( V_12 >= 256 ) {
V_13 = F_6 ( V_10 , V_11 , V_12 - 1 ) ;
if ( ! F_7 ( V_13 ) && * V_13 == '/' && V_13 [ 1 ] ) {
struct V_15 * V_15 = V_10 -> V_16 -> V_17 ;
if ( V_15 && F_8 ( V_15 -> V_18 ) ) {
V_11 [ V_12 - 2 ] = '/' ;
V_11 [ V_12 - 1 ] = '\0' ;
}
}
}
return V_13 ;
}
static char * F_9 ( struct V_16 * V_16 , char * const V_11 ,
const int V_12 )
{
char * V_13 = F_5 ( - V_14 ) ;
if ( V_12 >= 256 ) {
V_13 = F_10 ( V_16 , V_11 , V_12 - 1 ) ;
if ( ! F_7 ( V_13 ) && * V_13 == '/' && V_13 [ 1 ] ) {
struct V_15 * V_15 = V_16 -> V_17 ;
if ( V_15 && F_8 ( V_15 -> V_18 ) ) {
V_11 [ V_12 - 2 ] = '/' ;
V_11 [ V_12 - 1 ] = '\0' ;
}
}
}
return V_13 ;
}
static char * F_11 ( struct V_16 * V_16 , char * const V_11 ,
const int V_12 )
{
struct V_19 * V_20 = V_16 -> V_21 ;
char * V_13 = F_9 ( V_16 , V_11 , V_12 ) ;
if ( F_7 ( V_13 ) )
return V_13 ;
if ( V_20 -> V_22 == V_23 && * V_13 == '/' ) {
char * V_24 ;
const T_1 V_25 = ( T_1 ) F_12 ( V_13 + 1 , & V_24 , 10 ) ;
if ( * V_24 == '/' && V_25 && V_25 ==
F_13 ( V_26 , V_20 -> V_27 ) ) {
V_13 = V_24 - 5 ;
if ( V_13 < V_11 )
goto V_28;
memmove ( V_13 , L_1 , 5 ) ;
}
goto V_29;
}
if ( ! F_14 ( V_20 -> V_30 ) )
goto V_29;
{
struct V_15 * V_15 = V_20 -> V_31 -> V_17 ;
if ( ! V_15 -> V_32 -> rename && ! V_15 -> V_32 -> V_33 )
goto V_29;
}
{
char V_34 [ 64 ] ;
int V_35 ;
const T_2 V_36 = V_20 -> V_30 ;
V_34 [ sizeof( V_34 ) - 1 ] = '\0' ;
snprintf ( V_34 , sizeof( V_34 ) - 1 , L_2 , F_14 ( V_36 ) ,
F_15 ( V_36 ) ) ;
V_35 = strlen ( V_34 ) ;
V_13 -= V_35 ;
if ( V_13 < V_11 )
goto V_28;
memmove ( V_13 , V_34 , V_35 ) ;
return V_13 ;
}
V_29:
{
const char * V_34 = V_20 -> V_37 -> V_34 ;
const int V_35 = strlen ( V_34 ) ;
V_13 -= V_35 + 1 ;
if ( V_13 < V_11 )
goto V_28;
memmove ( V_13 , V_34 , V_35 ) ;
V_13 [ V_35 ] = ':' ;
}
return V_13 ;
V_28:
return F_5 ( - V_14 ) ;
}
static char * F_16 ( struct V_10 * V_10 , char * const V_11 ,
const int V_12 )
{
struct V_15 * V_15 = V_10 -> V_16 -> V_17 ;
struct V_38 * V_39 = V_15 ? F_17 ( V_15 ) : NULL ;
struct V_39 * V_40 = V_39 ? V_39 -> V_40 : NULL ;
if ( V_40 ) {
snprintf ( V_11 , V_12 , L_3
L_4 , V_40 -> V_41 , V_40 -> V_42 ,
V_40 -> V_43 ) ;
} else {
snprintf ( V_11 , V_12 , L_5 ) ;
}
return V_11 ;
}
char * F_18 ( struct V_10 * V_10 )
{
char * V_44 = NULL ;
char * V_34 = NULL ;
unsigned int V_45 = V_46 / 2 ;
struct V_16 * V_16 = V_10 -> V_16 ;
struct V_19 * V_20 ;
if ( ! V_16 )
return NULL ;
V_20 = V_16 -> V_21 ;
while ( 1 ) {
char * V_13 ;
struct V_15 * V_15 ;
V_45 <<= 1 ;
F_19 ( V_44 ) ;
V_44 = F_20 ( V_45 , V_9 ) ;
if ( ! V_44 )
break;
V_44 [ V_45 - 1 ] = '\0' ;
if ( V_20 -> V_22 == V_47 ) {
V_13 = F_16 ( V_10 , V_44 , V_45 - 1 ) ;
goto V_48;
}
if ( V_16 -> V_49 && V_16 -> V_49 -> V_50 ) {
V_13 = V_16 -> V_49 -> V_50 ( V_16 , V_44 , V_45 - 1 ) ;
goto V_48;
}
V_15 = V_20 -> V_31 -> V_17 ;
if ( ! V_10 -> V_51 ||
( ! V_15 -> V_32 -> rename && ! V_15 -> V_32 -> V_33 ) )
V_13 = F_11 ( V_10 -> V_16 , V_44 ,
V_45 - 1 ) ;
else {
V_13 = F_4 ( V_10 , V_44 , V_45 - 1 ) ;
if ( V_13 == F_5 ( - V_52 ) )
V_13 = F_11 ( V_10 -> V_16 , V_44 ,
V_45 - 1 ) ;
}
V_48:
if ( F_7 ( V_13 ) )
continue;
V_34 = F_3 ( V_13 ) ;
break;
}
F_19 ( V_44 ) ;
if ( ! V_34 )
F_21 ( V_53 ) ;
return V_34 ;
}
char * F_22 ( const char * V_54 )
{
struct V_10 V_10 ;
if ( V_54 && F_23 ( V_54 , 0 , & V_10 ) == 0 ) {
char * V_44 = F_18 ( & V_10 ) ;
F_24 ( & V_10 ) ;
return V_44 ;
}
return NULL ;
}
