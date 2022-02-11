static int F_1 ( struct V_1 * V_1 )
{
unsigned char V_2 [ 2 ] ;
int V_3 = 0 ;
do {
if ( F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_4 ) ) ||
F_2 ( V_1 , V_2 , F_3 ( 0 , 2 , V_5 ) ) )
return - 1 ;
} while ( V_2 [ 0 ] == 0xFC && V_2 [ 1 ] == 0x00 && ++ V_3 < 2 );
if ( V_2 [ 0 ] != 0xAA || V_2 [ 1 ] != 0x00 )
return - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 ,
unsigned char V_6 , unsigned char * V_2 )
{
if ( F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_4 ) ) ||
F_2 ( V_1 , V_2 , F_3 ( 0 , 1 , V_6 ) ) ) {
return - 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 ,
unsigned char V_6 , unsigned char V_7 )
{
if ( F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_4 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_8 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_6 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_7 ) ) ) {
return - 1 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_1 ,
unsigned char V_6 , unsigned char V_9 )
{
if ( V_6 < 0x20 || V_6 >= 0x2F )
return - 1 ;
if ( F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_4 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_10 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_6 ) ) ||
F_2 ( V_1 , NULL , F_3 ( 0 , 0 , V_9 ) ) ) {
return - 1 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , unsigned char V_6 ,
unsigned char V_9 , unsigned char V_11 )
{
int V_12 = 0 ;
unsigned char V_13 ;
F_4 ( V_1 , V_6 , & V_13 ) ;
if ( ( ( V_13 & V_9 ) == V_9 ) != ! ! V_11 )
V_12 = F_6 ( V_1 , V_6 , V_9 ) ;
return V_12 ;
}
static T_1 F_8 ( struct V_14 * V_14 , void * V_13 , char * V_15 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_13 ;
unsigned char V_11 = * ( unsigned char * ) ( ( char * ) V_17 + V_20 -> V_21 ) ;
if ( V_20 -> V_22 )
V_11 = ! V_11 ;
return sprintf ( V_15 , L_1 , V_11 ) ;
}
static T_1 F_9 ( struct V_14 * V_14 , void * V_13 ,
const char * V_15 , T_2 V_23 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_13 ;
unsigned char * V_24 = ( unsigned char * ) ( ( char * ) V_17 + V_20 -> V_21 ) ;
unsigned char V_11 ;
int V_25 ;
V_25 = F_10 ( V_15 , 10 , & V_11 ) ;
if ( V_25 )
return V_25 ;
* V_24 = V_11 ;
F_5 ( & V_14 -> V_1 , V_20 -> V_26 , V_11 ) ;
return V_23 ;
}
static T_1 F_11 ( struct V_14 * V_14 , void * V_13 ,
const char * V_15 , T_2 V_23 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
struct V_19 * V_20 = V_13 ;
unsigned char * V_24 = ( unsigned char * ) ( ( char * ) V_17 + V_20 -> V_21 ) ;
unsigned int V_11 ;
int V_25 ;
V_25 = F_12 ( V_15 , 10 , & V_11 ) ;
if ( V_25 )
return V_25 ;
if ( V_11 > 1 )
return - V_27 ;
if ( V_20 -> V_22 )
V_11 = ! V_11 ;
if ( * V_24 != V_11 ) {
* V_24 = V_11 ;
F_6 ( & V_14 -> V_1 , V_20 -> V_26 , V_20 -> V_9 ) ;
}
return V_23 ;
}
static int F_13 ( struct V_14 * V_14 , unsigned char * V_28 )
{
unsigned char V_29 [ 2 ] = { 0 } ;
if ( F_2 ( & V_14 -> V_1 , V_29 , F_3 ( 0 , 2 , V_30 ) ) )
return - 1 ;
if ( V_29 [ 0 ] != V_31 )
return - 1 ;
if ( V_28 )
* V_28 = V_29 [ 1 ] ;
return 0 ;
}
static int F_14 ( struct V_14 * V_14 , bool V_32 )
{
struct V_16 * V_17 = V_14 -> V_18 ;
if ( ! V_32 ) {
F_7 ( & V_14 -> V_1 , V_33 ,
V_34 , V_35 ) ;
F_7 ( & V_14 -> V_1 , V_36 ,
V_37 , V_38 ) ;
F_7 ( & V_14 -> V_1 , V_39 ,
V_40 , V_41 ) ;
}
F_15 ( V_32 , V_14 , V_17 , V_42 ) ;
F_15 ( V_32 , V_14 , V_17 , V_43 ) ;
F_15 ( V_32 , V_14 , V_17 , V_44 ) ;
F_15 ( V_32 , V_14 , V_17 , V_45 ) ;
F_15 ( V_32 , V_14 , V_17 , V_46 ) ;
F_15 ( V_32 , V_14 , V_17 , V_47 ) ;
F_15 ( V_32 , V_14 , V_17 , V_48 ) ;
F_15 ( V_32 , V_14 , V_17 , V_49 ) ;
F_15 ( V_32 , V_14 , V_17 , V_50 ) ;
F_15 ( V_32 , V_14 , V_17 , V_51 ) ;
F_15 ( V_32 , V_14 , V_17 , V_52 ) ;
F_15 ( V_32 , V_14 , V_17 , V_53 ) ;
F_15 ( V_32 , V_14 , V_17 , V_54 ) ;
return 0 ;
}
static void F_16 ( struct V_16 * V_17 )
{
F_17 ( V_17 , V_42 ) ;
F_17 ( V_17 , V_44 ) ;
F_17 ( V_17 , V_45 ) ;
F_17 ( V_17 , V_46 ) ;
F_17 ( V_17 , V_47 ) ;
F_17 ( V_17 , V_48 ) ;
F_17 ( V_17 , V_49 ) ;
F_17 ( V_17 , V_50 ) ;
F_17 ( V_17 , V_51 ) ;
F_17 ( V_17 , V_43 ) ;
F_17 ( V_17 , V_52 ) ;
F_17 ( V_17 , V_53 ) ;
F_17 ( V_17 , V_54 ) ;
}
static void F_18 ( struct V_14 * V_14 )
{
F_19 ( & V_14 -> V_1 . V_55 -> V_56 . V_57 , & V_58 ) ;
F_20 ( V_14 -> V_18 ) ;
V_14 -> V_18 = NULL ;
}
static int F_21 ( struct V_14 * V_14 )
{
int V_59 ;
if ( F_13 ( V_14 , NULL ) )
return - 1 ;
V_59 = F_1 ( & V_14 -> V_1 ) ;
if ( F_14 ( V_14 , ! V_59 ) )
return - 1 ;
return 0 ;
}
int F_22 ( struct V_14 * V_14 , bool V_60 )
{
struct V_1 * V_1 = & V_14 -> V_1 ;
unsigned char V_28 ;
unsigned char V_61 ;
int error ;
if ( F_13 ( V_14 , & V_28 ) )
return - 1 ;
if ( ! V_60 )
return 0 ;
if ( F_4 ( & V_14 -> V_1 , V_62 , & V_61 ) ) {
F_23 ( V_14 , L_2 ) ;
V_61 = 0 ;
}
V_14 -> V_18 = F_24 ( sizeof( struct V_16 ) , V_63 ) ;
if ( ! V_14 -> V_18 )
return - V_64 ;
V_14 -> V_65 = L_3 ;
V_14 -> V_66 = L_4 ;
V_14 -> V_67 = F_21 ;
V_14 -> V_68 = F_18 ;
if ( ( V_61 & 0x0f ) >= 3 )
F_25 ( V_69 , V_14 -> V_56 -> V_70 ) ;
F_16 ( V_14 -> V_18 ) ;
error = F_1 ( & V_14 -> V_1 ) ;
if ( error )
F_14 ( V_14 , false ) ;
error = F_26 ( & V_1 -> V_55 -> V_56 . V_57 , & V_58 ) ;
if ( error ) {
F_27 ( V_14 ,
L_5 ,
error ) ;
F_20 ( V_14 -> V_18 ) ;
V_14 -> V_18 = NULL ;
return - 1 ;
}
F_28 ( V_14 ,
L_6 ,
V_28 ,
( V_61 & 0xf0 ) >> 4 , V_61 & 0x0f ) ;
return 0 ;
}
