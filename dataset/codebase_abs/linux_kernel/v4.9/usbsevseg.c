static inline T_1 F_1 ( const char * V_1 , T_1 V_2 )
{
if ( V_2 > 0 && V_1 [ V_2 - 1 ] == '\n' )
return V_2 - 1 ;
else
return V_2 ;
}
static void F_2 ( struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 && ! V_4 -> V_7 ) {
V_5 = F_3 ( V_4 -> V_8 ) ;
if ( V_5 < 0 )
return;
V_4 -> V_7 = 1 ;
}
if ( V_4 -> V_9 != 1 )
return;
V_5 = F_4 ( V_4 -> V_10 ,
F_5 ( V_4 -> V_10 , 0 ) ,
0x12 ,
0x48 ,
( 80 * 0x100 ) + 10 ,
( 0x00 * 0x100 ) + ( V_4 -> V_6 ? 1 : 0 ) ,
NULL ,
0 ,
2000 ) ;
if ( V_5 < 0 )
F_6 ( & V_4 -> V_10 -> V_11 , L_1 , V_5 ) ;
if ( ! V_4 -> V_6 && V_4 -> V_7 ) {
F_7 ( V_4 -> V_8 ) ;
V_4 -> V_7 = 0 ;
}
}
static void F_8 ( struct V_3 * V_4 )
{
int V_5 ;
if( V_4 -> V_9 != 1 )
return;
V_5 = F_4 ( V_4 -> V_10 ,
F_5 ( V_4 -> V_10 , 0 ) ,
0x12 ,
0x48 ,
( 82 * 0x100 ) + 10 ,
( V_4 -> V_12 * 0x100 ) + V_4 -> V_13 ,
NULL ,
0 ,
2000 ) ;
if ( V_5 < 0 )
F_6 ( & V_4 -> V_10 -> V_11 , L_2 , V_5 ) ;
}
static void F_9 ( struct V_3 * V_4 , T_2 V_14 )
{
int V_5 ;
int V_15 ;
unsigned char * V_16 ;
T_3 V_17 = 0 ;
if( V_4 -> V_9 != 1 )
return;
V_16 = F_10 ( V_18 , V_14 ) ;
if ( ! V_16 )
return;
for ( V_15 = 0 ; V_15 < V_4 -> V_19 ; V_15 ++ )
V_16 [ V_15 ] = V_4 -> V_20 [ V_4 -> V_19 - 1 - V_15 ] ;
V_5 = F_4 ( V_4 -> V_10 ,
F_5 ( V_4 -> V_10 , 0 ) ,
0x12 ,
0x48 ,
( 85 * 0x100 ) + 10 ,
( 0 * 0x100 ) + V_4 -> V_21 ,
V_16 ,
V_4 -> V_19 ,
2000 ) ;
if ( V_5 < 0 )
F_6 ( & V_4 -> V_10 -> V_11 , L_3 , V_5 ) ;
F_11 ( V_16 ) ;
for ( V_15 = 0 ; V_15 < sizeof( V_4 -> V_17 ) ; V_15 ++ )
V_17 |= V_4 -> V_17 [ V_15 ] << V_15 ;
V_5 = F_4 ( V_4 -> V_10 ,
F_5 ( V_4 -> V_10 , 0 ) ,
0x12 ,
0x48 ,
( 86 * 0x100 ) + 10 ,
( 0 * 0x100 ) + V_17 ,
NULL ,
0 ,
2000 ) ;
if ( V_5 < 0 )
F_6 ( & V_4 -> V_10 -> V_11 , L_4 , V_5 ) ;
}
static T_4 F_12 ( struct V_22 * V_11 ,
struct V_23 * V_24 , char * V_1 )
{
struct V_25 * V_8 = F_13 ( V_11 ) ;
struct V_3 * V_4 = F_14 ( V_8 ) ;
return snprintf ( V_1 , V_4 -> V_19 , L_5 , V_4 -> V_20 ) ;
}
static T_4 F_15 ( struct V_22 * V_11 ,
struct V_23 * V_24 , const char * V_1 , T_1 V_2 )
{
struct V_25 * V_8 = F_13 ( V_11 ) ;
struct V_3 * V_4 = F_14 ( V_8 ) ;
T_1 V_26 = F_1 ( V_1 , V_2 ) ;
if ( V_26 > sizeof( V_4 -> V_20 ) )
return - V_27 ;
memset ( V_4 -> V_20 , 0 , sizeof( V_4 -> V_20 ) ) ;
V_4 -> V_19 = V_26 ;
if ( V_26 > 0 )
memcpy ( V_4 -> V_20 , V_1 , V_26 ) ;
F_9 ( V_4 , V_28 ) ;
return V_2 ;
}
static T_4 F_16 ( struct V_22 * V_11 ,
struct V_23 * V_24 , char * V_1 )
{
struct V_25 * V_8 = F_13 ( V_11 ) ;
struct V_3 * V_4 = F_14 ( V_8 ) ;
int V_15 ;
int V_29 ;
for ( V_15 = 0 ; V_15 < sizeof( V_4 -> V_17 ) ; V_15 ++ ) {
V_29 = sizeof( V_4 -> V_17 ) - 1 - V_15 ;
if ( V_4 -> V_17 [ V_15 ] == 0 )
V_1 [ V_29 ] = '0' ;
else if ( V_4 -> V_17 [ V_15 ] == 1 )
V_1 [ V_29 ] = '1' ;
else
V_1 [ V_29 ] = 'x' ;
}
V_1 [ sizeof( V_4 -> V_17 ) ] = '\n' ;
return sizeof( V_4 -> V_17 ) + 1 ;
}
static T_4 F_17 ( struct V_22 * V_11 ,
struct V_23 * V_24 , const char * V_1 , T_1 V_2 )
{
struct V_25 * V_8 = F_13 ( V_11 ) ;
struct V_3 * V_4 = F_14 ( V_8 ) ;
T_1 V_26 = F_1 ( V_1 , V_2 ) ;
int V_15 ;
if ( V_26 > sizeof( V_4 -> V_17 ) )
return - V_27 ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ )
if ( V_1 [ V_15 ] != '0' && V_1 [ V_15 ] != '1' )
return - V_27 ;
memset ( V_4 -> V_17 , 0 , sizeof( V_4 -> V_17 ) ) ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ )
if ( V_1 [ V_15 ] == '1' )
V_4 -> V_17 [ V_26 - 1 - V_15 ] = 1 ;
F_9 ( V_4 , V_28 ) ;
return V_2 ;
}
static T_4 F_18 ( struct V_22 * V_11 ,
struct V_23 * V_24 , char * V_1 )
{
struct V_25 * V_8 = F_13 ( V_11 ) ;
struct V_3 * V_4 = F_14 ( V_8 ) ;
int V_15 ;
V_1 [ 0 ] = 0 ;
for ( V_15 = 0 ; V_30 [ V_15 ] ; V_15 ++ ) {
if ( V_4 -> V_21 == V_15 ) {
strcat ( V_1 , L_6 ) ;
strcat ( V_1 , V_30 [ V_15 ] ) ;
strcat ( V_1 , L_7 ) ;
} else {
strcat ( V_1 , L_8 ) ;
strcat ( V_1 , V_30 [ V_15 ] ) ;
strcat ( V_1 , L_8 ) ;
}
}
strcat ( V_1 , L_9 ) ;
return strlen ( V_1 ) ;
}
static T_4 F_19 ( struct V_22 * V_11 ,
struct V_23 * V_24 , const char * V_1 , T_1 V_2 )
{
struct V_25 * V_8 = F_13 ( V_11 ) ;
struct V_3 * V_4 = F_14 ( V_8 ) ;
int V_15 ;
for ( V_15 = 0 ; V_30 [ V_15 ] ; V_15 ++ ) {
if ( F_20 ( V_30 [ V_15 ] , V_1 ) ) {
V_4 -> V_21 = V_15 ;
F_9 ( V_4 , V_28 ) ;
return V_2 ;
}
}
return - V_27 ;
}
static int F_21 ( struct V_25 * V_31 ,
const struct V_32 * V_33 )
{
struct V_34 * V_10 = F_22 ( V_31 ) ;
struct V_3 * V_4 = NULL ;
int V_5 = - V_35 ;
V_4 = F_10 ( sizeof( struct V_3 ) , V_28 ) ;
if ( ! V_4 )
goto V_36;
V_4 -> V_10 = F_23 ( V_10 ) ;
V_4 -> V_8 = V_31 ;
F_24 ( V_31 , V_4 ) ;
V_4 -> V_9 = 1 ;
V_4 -> V_7 = 0 ;
V_4 -> V_21 = 0x02 ;
V_4 -> V_12 = 0x06 ;
V_4 -> V_13 = 0x3f ;
V_5 = F_25 ( & V_31 -> V_11 . V_37 , & V_38 ) ;
if ( V_5 )
goto error;
F_26 ( & V_31 -> V_11 , L_10 ) ;
return 0 ;
error:
F_24 ( V_31 , NULL ) ;
F_27 ( V_4 -> V_10 ) ;
F_11 ( V_4 ) ;
V_36:
return V_5 ;
}
static void F_28 ( struct V_25 * V_31 )
{
struct V_3 * V_4 ;
V_4 = F_14 ( V_31 ) ;
F_29 ( & V_31 -> V_11 . V_37 , & V_38 ) ;
F_24 ( V_31 , NULL ) ;
F_27 ( V_4 -> V_10 ) ;
F_11 ( V_4 ) ;
F_26 ( & V_31 -> V_11 , L_11 ) ;
}
static int F_30 ( struct V_25 * V_8 , T_5 V_39 )
{
struct V_3 * V_4 ;
V_4 = F_14 ( V_8 ) ;
V_4 -> V_9 = 0 ;
return 0 ;
}
static int F_31 ( struct V_25 * V_8 )
{
struct V_3 * V_4 ;
V_4 = F_14 ( V_8 ) ;
V_4 -> V_9 = 1 ;
F_8 ( V_4 ) ;
F_9 ( V_4 , V_40 ) ;
return 0 ;
}
static int F_32 ( struct V_25 * V_8 )
{
struct V_3 * V_4 ;
V_4 = F_14 ( V_8 ) ;
V_4 -> V_9 = 1 ;
F_8 ( V_4 ) ;
F_9 ( V_4 , V_40 ) ;
return 0 ;
}
