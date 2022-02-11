int F_1 ( struct V_1 * V_1 , bool V_2 )
{
if ( ! F_2 ( V_1 , V_3 ) )
return - V_4 ;
if ( V_2 ) {
V_1 -> V_5 = L_1 ;
V_1 -> V_6 = L_2 ;
}
return 0 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 ;
struct V_12 * V_13 = V_1 -> V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
struct V_16 * V_17 = & V_11 -> V_18 [ V_14 ] ;
bool V_19 = V_17 -> V_19 && V_17 -> V_20 ;
F_4 ( V_13 , V_14 ) ;
F_5 ( V_13 , V_21 , V_19 ) ;
if ( V_19 ) {
unsigned int V_22 , V_23 ;
V_22 = F_6 ( V_17 -> V_24 , 0U , V_8 -> V_25 ) ;
V_23 = F_6 ( V_17 -> V_26 , 0U , V_8 -> V_27 ) ;
F_7 ( V_13 , V_28 , V_22 ) ;
F_7 ( V_13 , V_29 ,
V_8 -> V_27 - V_23 ) ;
F_7 ( V_13 , V_30 , V_11 -> V_31 ) ;
}
}
F_8 ( V_13 , true ) ;
F_9 ( V_13 , V_32 , V_11 -> V_33 ) ;
F_10 ( V_13 ) ;
}
static void F_11 ( struct V_1 * V_1 ,
unsigned char * V_34 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 ;
unsigned char V_18 = V_34 [ 1 ] ;
int V_14 ;
V_11 -> V_33 = ( V_34 [ 0 ] >> 4 ) & 1 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_11 -> V_18 [ V_14 ] . V_19 = V_18 & 0x1 ;
if ( ! V_11 -> V_18 [ V_14 ] . V_19 ) {
V_11 -> V_18 [ V_14 ] . V_20 = false ;
}
V_18 >>= 1 ;
}
}
static void F_12 ( struct V_1 * V_1 ,
unsigned char * V_34 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 ;
unsigned int V_17 ;
V_17 = ( V_34 [ 1 ] >> 4 ) - 1 ;
if ( V_17 >= V_15 ) {
F_13 ( V_1 , L_3 ,
V_17 ) ;
return;
}
V_11 -> V_33 = ( V_34 [ 0 ] >> 4 ) & 1 ;
V_11 -> V_18 [ V_17 ] . V_24 = ( ( V_34 [ 1 ] & 0xf ) << 8 ) | V_34 [ 2 ] ;
V_11 -> V_18 [ V_17 ] . V_26 = ( V_34 [ 3 ] << 8 ) | V_34 [ 4 ] ;
V_11 -> V_31 = V_34 [ 5 ] >> 4 ;
V_11 -> V_18 [ V_17 ] . V_20 = true ;
}
static void F_14 ( struct V_1 * V_1 ,
unsigned char * V_34 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
struct V_10 * V_11 = & V_8 -> V_11 ;
int V_35 , V_36 ;
V_11 -> V_33 = V_34 [ 0 ] >> 7 ;
V_35 = ( ( V_34 [ 0 ] >> 4 ) & 0x7 ) - 1 ;
if ( V_35 < V_15 ) {
V_11 -> V_18 [ V_35 ] . V_24 += ( char ) V_34 [ 1 ] ;
V_11 -> V_18 [ V_35 ] . V_26 += ( char ) V_34 [ 2 ] ;
} else {
F_13 ( V_1 , L_4 ,
V_35 ) ;
}
V_36 = ( ( V_34 [ 3 ] >> 4 ) & 0x7 ) - 1 ;
if ( V_36 < V_15 ) {
V_11 -> V_18 [ V_36 ] . V_24 += ( char ) V_34 [ 4 ] ;
V_11 -> V_18 [ V_36 ] . V_26 += ( char ) V_34 [ 5 ] ;
}
}
static void F_15 ( struct V_1 * V_1 )
{
unsigned char * V_34 = V_1 -> V_34 ;
switch ( V_34 [ 0 ] & 0xf ) {
case V_37 :
F_11 ( V_1 , V_34 ) ;
break;
case V_38 :
F_12 ( V_1 , V_34 ) ;
break;
case V_39 :
F_14 ( V_1 , V_34 ) ;
break;
default:
F_13 ( V_1 , L_5 , V_34 [ 0 ] ) ;
break;
}
F_3 ( V_1 ) ;
}
static T_1 F_16 ( struct V_1 * V_1 )
{
if ( V_1 -> V_40 >= 6 ) {
F_15 ( V_1 ) ;
return V_41 ;
}
return V_42 ;
}
static int F_17 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = & V_1 -> V_43 ;
unsigned char V_44 [ 3 ] ;
V_44 [ 0 ] = 0 ;
if ( F_18 ( V_43 , V_44 , 0x10f8 ) )
return - V_45 ;
if ( F_18 ( V_43 , V_44 , 0x10f8 ) )
return - V_45 ;
if ( F_18 ( V_43 , V_44 , 0x10f8 ) )
return - V_45 ;
V_44 [ 0 ] = 1 ;
if ( F_18 ( V_43 , V_44 , 0x10f8 ) )
return - V_45 ;
if ( F_18 ( V_43 , V_44 , V_46 ) )
return - V_45 ;
if ( F_18 ( V_43 , V_44 , V_47 ) )
return - V_45 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
F_18 ( & V_1 -> V_43 , NULL , V_48 ) ;
F_20 ( V_1 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
F_19 ( V_1 ) ;
F_22 ( V_1 -> V_9 ) ;
V_1 -> V_9 = NULL ;
}
static int F_23 ( struct V_1 * V_1 )
{
int error ;
F_19 ( V_1 ) ;
error = F_17 ( V_1 ) ;
if ( error ) {
F_13 ( V_1 , L_6 ) ;
return error ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = V_1 -> V_13 ;
struct V_7 * V_8 = V_1 -> V_9 ;
F_25 ( V_49 , V_13 -> V_50 ) ;
F_25 ( V_51 , V_13 -> V_52 ) ;
F_25 ( V_53 , V_13 -> V_52 ) ;
F_25 ( V_54 , V_13 -> V_55 ) ;
F_25 ( V_56 , V_13 -> V_55 ) ;
F_26 ( V_57 , V_13 -> V_50 ) ;
F_27 ( V_13 , V_28 , 0 , V_8 -> V_25 , 0 , 0 ) ;
F_27 ( V_13 , V_29 , 0 , V_8 -> V_27 , 0 , 0 ) ;
F_27 ( V_13 , V_30 , 0 , 15 , 0 , 0 ) ;
F_28 ( V_13 , 5 , V_58 ) ;
F_26 ( V_59 , V_13 -> V_60 ) ;
}
static int F_29 ( struct V_43 * V_43 , int V_61 ,
unsigned char * V_44 )
{
if ( F_18 ( V_43 , V_44 , V_46 ) )
return - V_45 ;
V_44 [ 0 ] = 0 ;
if ( F_18 ( V_43 , V_44 , V_62 ) )
return - V_45 ;
if ( F_18 ( V_43 , V_44 , V_62 ) )
return - V_45 ;
if ( F_18 ( V_43 , V_44 , V_62 ) )
return - V_45 ;
V_44 [ 0 ] = V_61 ;
if ( F_18 ( V_43 , V_44 , V_62 ) )
return - V_45 ;
if ( F_18 ( V_43 , V_44 , V_63 ) )
return - V_45 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_43 * V_43 = & V_1 -> V_43 ;
struct V_7 * V_8 = V_1 -> V_9 ;
char V_44 [ 3 ] ;
if ( F_29 ( V_43 , 2 , V_44 ) )
return - V_45 ;
V_8 -> V_25 = ( unsigned char ) V_44 [ 1 ] * 128 ;
V_8 -> V_27 = ( unsigned char ) V_44 [ 2 ] * 128 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_1 ,
unsigned int V_64 )
{
}
static void F_32 ( struct V_1 * V_1 , unsigned int V_65 )
{
}
static void F_33 ( struct V_1 * V_1 ,
enum V_66 V_67 )
{
}
int F_34 ( struct V_1 * V_1 )
{
struct V_7 * V_8 ;
int error ;
V_1 -> V_9 = V_8 = F_35 ( sizeof( struct V_7 ) ,
V_68 ) ;
if ( ! V_8 )
return - V_69 ;
F_19 ( V_1 ) ;
error = F_30 ( V_1 ) ;
if ( error ) {
F_13 ( V_1 ,
L_7 ) ;
goto V_70;
}
error = F_17 ( V_1 ) ;
if ( error ) {
F_13 ( V_1 , L_6 ) ;
goto V_70;
}
F_24 ( V_1 ) ;
V_1 -> V_71 = F_16 ;
V_1 -> V_72 = 6 ;
V_1 -> V_73 = F_21 ;
V_1 -> V_74 = F_23 ;
V_1 -> V_75 = F_19 ;
V_1 -> V_76 = 0 ;
V_1 -> V_77 = F_31 ;
V_1 -> V_78 = F_32 ;
V_1 -> V_79 = F_33 ;
return 0 ;
V_70:
F_19 ( V_1 ) ;
F_22 ( V_8 ) ;
return error ;
}
