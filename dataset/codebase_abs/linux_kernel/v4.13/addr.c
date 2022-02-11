static T_1 F_1 ( const struct V_1 * V_2 ,
char * V_3 , const int V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) V_2 ;
const struct V_7 * V_8 = & V_6 -> V_9 ;
if ( F_2 ( V_8 ) )
return snprintf ( V_3 , V_4 , L_1 ) ;
if ( F_3 ( V_8 ) )
return snprintf ( V_3 , V_4 , L_2 ) ;
if ( F_4 ( V_8 ) )
return snprintf ( V_3 , V_4 , L_3 ,
& V_8 -> V_10 [ 3 ] ) ;
return snprintf ( V_3 , V_4 , L_4 , V_8 ) ;
}
static T_1 F_5 ( const struct V_1 * V_2 ,
char * V_3 , const T_1 V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) V_2 ;
char V_11 [ V_12 ] ;
T_1 V_13 ;
int V_14 ;
V_13 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( F_6 ( V_13 == 0 ) )
return V_13 ;
if ( ! ( F_7 ( & V_6 -> V_9 ) & V_15 ) )
return V_13 ;
if ( V_6 -> V_16 == 0 )
return V_13 ;
V_14 = snprintf ( V_11 , sizeof( V_11 ) , L_5 ,
V_17 , V_6 -> V_16 ) ;
if ( F_6 ( ( T_1 ) V_14 > sizeof( V_11 ) ) )
return 0 ;
V_13 += V_14 ;
if ( F_6 ( V_13 > V_4 ) )
return 0 ;
strcat ( V_3 , V_11 ) ;
return V_13 ;
}
static T_1 F_1 ( const struct V_1 * V_2 ,
char * V_3 , const int V_4 )
{
return 0 ;
}
static T_1 F_5 ( const struct V_1 * V_2 ,
char * V_3 , const T_1 V_4 )
{
return 0 ;
}
static int F_8 ( const struct V_1 * V_2 ,
char * V_3 , const T_1 V_4 )
{
const struct V_18 * sin = (struct V_18 * ) V_2 ;
return snprintf ( V_3 , V_4 , L_6 , & sin -> V_19 ) ;
}
T_1 F_9 ( const struct V_1 * V_2 , char * V_3 , const T_1 V_4 )
{
switch ( V_2 -> V_20 ) {
case V_21 :
return F_8 ( V_2 , V_3 , V_4 ) ;
case V_22 :
return F_5 ( V_2 , V_3 , V_4 ) ;
}
return 0 ;
}
static T_1 F_10 ( const char * V_3 , const T_1 V_4 ,
struct V_1 * V_2 , const T_1 V_23 )
{
struct V_18 * sin = (struct V_18 * ) V_2 ;
T_2 * V_8 = ( T_2 * ) & sin -> V_19 . V_24 ;
if ( V_4 > V_25 || V_23 < sizeof( struct V_18 ) )
return 0 ;
memset ( V_2 , 0 , sizeof( struct V_18 ) ) ;
if ( F_11 ( V_3 , V_4 , V_8 , '\0' , NULL ) == 0 )
return 0 ;
sin -> V_26 = V_21 ;
return sizeof( struct V_18 ) ;
}
static int F_12 ( struct V_27 * V_27 , const char * V_3 ,
const T_1 V_4 , const char * V_28 ,
struct V_5 * V_6 )
{
char * V_29 ;
T_1 V_13 ;
if ( ( V_3 + V_4 ) == V_28 )
return 1 ;
if ( * V_28 != V_17 )
return 0 ;
if ( ! ( F_7 ( & V_6 -> V_9 ) & V_15 ) )
return 0 ;
V_13 = ( V_3 + V_4 ) - V_28 - 1 ;
V_29 = F_13 ( V_28 + 1 , V_13 , V_30 ) ;
if ( V_29 ) {
T_3 V_31 = 0 ;
struct V_32 * V_33 ;
V_33 = F_14 ( V_27 , V_29 ) ;
if ( V_33 != NULL ) {
V_31 = V_33 -> V_34 ;
F_15 ( V_33 ) ;
} else {
if ( F_16 ( V_29 , 10 , & V_31 ) == 0 ) {
F_17 ( V_29 ) ;
return 0 ;
}
}
F_17 ( V_29 ) ;
V_6 -> V_16 = V_31 ;
return 1 ;
}
return 0 ;
}
static T_1 F_18 ( struct V_27 * V_27 , const char * V_3 , const T_1 V_4 ,
struct V_1 * V_2 , const T_1 V_23 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
T_2 * V_8 = ( T_2 * ) & V_6 -> V_9 . V_35 ;
const char * V_28 ;
if ( V_4 > ( V_36 + V_12 ) ||
V_23 < sizeof( struct V_5 ) )
return 0 ;
memset ( V_2 , 0 , sizeof( struct V_5 ) ) ;
if ( F_19 ( V_3 , V_4 , V_8 , V_17 , & V_28 ) == 0 )
return 0 ;
if ( ! F_12 ( V_27 , V_3 , V_4 , V_28 , V_6 ) )
return 0 ;
V_6 -> V_37 = V_22 ;
return sizeof( struct V_5 ) ;
}
static T_1 F_18 ( struct V_27 * V_27 , const char * V_3 , const T_1 V_4 ,
struct V_1 * V_2 , const T_1 V_23 )
{
return 0 ;
}
T_1 F_20 ( struct V_27 * V_27 , const char * V_3 , const T_1 V_4 ,
struct V_1 * V_2 , const T_1 V_23 )
{
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < V_4 ; V_38 ++ )
if ( V_3 [ V_38 ] == ':' )
return F_18 ( V_27 , V_3 , V_4 , V_2 , V_23 ) ;
return F_10 ( V_3 , V_4 , V_2 , V_23 ) ;
}
char * F_21 ( const struct V_1 * V_2 , T_4 V_39 )
{
char V_40 [ V_41 ] ;
char V_42 [ V_43 ] ;
unsigned short V_44 ;
switch ( V_2 -> V_20 ) {
case V_21 :
if ( F_8 ( V_2 , V_42 , sizeof( V_42 ) ) == 0 )
return NULL ;
V_44 = F_22 ( ( (struct V_18 * ) V_2 ) -> V_45 ) ;
break;
case V_22 :
if ( F_1 ( V_2 , V_42 , sizeof( V_42 ) ) == 0 )
return NULL ;
V_44 = F_22 ( ( (struct V_5 * ) V_2 ) -> V_46 ) ;
break;
default:
return NULL ;
}
if ( snprintf ( V_40 , sizeof( V_40 ) ,
L_7 , V_44 >> 8 , V_44 & 0xff ) > ( int ) sizeof( V_40 ) )
return NULL ;
if ( F_23 ( V_42 , V_40 , sizeof( V_42 ) ) > sizeof( V_42 ) )
return NULL ;
return F_24 ( V_42 , V_39 ) ;
}
T_1 F_25 ( struct V_27 * V_27 , const char * V_47 ,
const T_1 V_48 , struct V_1 * V_2 ,
const T_1 V_23 )
{
char * V_49 , V_3 [ V_43 + sizeof( '\0' ) ] ;
T_2 V_50 , V_51 ;
unsigned short V_44 ;
if ( V_48 > V_43 )
return 0 ;
memcpy ( V_3 , V_47 , V_48 ) ;
V_3 [ V_48 ] = '\0' ;
V_49 = strrchr ( V_3 , '.' ) ;
if ( F_6 ( V_49 == NULL ) )
return 0 ;
if ( F_6 ( F_26 ( V_49 + 1 , 10 , & V_50 ) != 0 ) )
return 0 ;
* V_49 = '\0' ;
V_49 = strrchr ( V_3 , '.' ) ;
if ( F_6 ( V_49 == NULL ) )
return 0 ;
if ( F_6 ( F_26 ( V_49 + 1 , 10 , & V_51 ) != 0 ) )
return 0 ;
V_44 = ( unsigned short ) ( ( V_51 << 8 ) | V_50 ) ;
* V_49 = '\0' ;
if ( F_20 ( V_27 , V_3 , strlen ( V_3 ) , V_2 , V_23 ) == 0 )
return 0 ;
switch ( V_2 -> V_20 ) {
case V_21 :
( (struct V_18 * ) V_2 ) -> V_45 = F_27 ( V_44 ) ;
return sizeof( struct V_18 ) ;
case V_22 :
( (struct V_5 * ) V_2 ) -> V_46 = F_27 ( V_44 ) ;
return sizeof( struct V_5 ) ;
}
return 0 ;
}
