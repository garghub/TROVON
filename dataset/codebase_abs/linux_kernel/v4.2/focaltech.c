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
F_4 ( & V_1 -> V_7 , NULL , V_8 ) ;
F_5 ( V_1 ) ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
struct V_14 * V_15 = V_1 -> V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
struct V_18 * V_19 = & V_13 -> V_20 [ V_16 ] ;
bool V_21 = V_19 -> V_21 && V_19 -> V_22 ;
F_7 ( V_15 , V_16 ) ;
F_8 ( V_15 , V_23 , V_21 ) ;
if ( V_21 ) {
unsigned int V_24 , V_25 ;
V_24 = F_9 ( V_19 -> V_26 , 0U , V_10 -> V_27 ) ;
V_25 = F_9 ( V_19 -> V_28 , 0U , V_10 -> V_29 ) ;
F_10 ( V_15 , V_30 , V_24 ) ;
F_10 ( V_15 , V_31 ,
V_10 -> V_29 - V_25 ) ;
F_10 ( V_15 , V_32 , V_13 -> V_33 ) ;
}
}
F_11 ( V_15 , true ) ;
F_12 ( V_1 -> V_15 , V_34 , V_13 -> V_35 ) ;
F_13 ( V_1 -> V_15 ) ;
}
static void F_14 ( struct V_1 * V_1 ,
unsigned char * V_36 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
unsigned char V_20 = V_36 [ 1 ] ;
int V_16 ;
V_13 -> V_35 = ( V_36 [ 0 ] >> 4 ) & 1 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_13 -> V_20 [ V_16 ] . V_21 = V_20 & 0x1 ;
if ( ! V_13 -> V_20 [ V_16 ] . V_21 ) {
V_13 -> V_20 [ V_16 ] . V_22 = false ;
}
V_20 >>= 1 ;
}
}
static void F_15 ( struct V_1 * V_1 ,
unsigned char * V_36 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
unsigned int V_19 ;
V_19 = ( V_36 [ 1 ] >> 4 ) - 1 ;
if ( V_19 >= V_17 ) {
F_16 ( V_1 , L_3 ,
V_19 ) ;
return;
}
V_13 -> V_35 = ( V_36 [ 0 ] >> 4 ) & 1 ;
V_13 -> V_20 [ V_19 ] . V_26 = ( ( V_36 [ 1 ] & 0xf ) << 8 ) | V_36 [ 2 ] ;
V_13 -> V_20 [ V_19 ] . V_28 = ( V_36 [ 3 ] << 8 ) | V_36 [ 4 ] ;
V_13 -> V_33 = V_36 [ 5 ] >> 4 ;
V_13 -> V_20 [ V_19 ] . V_22 = true ;
}
static void F_17 ( struct V_1 * V_1 ,
unsigned char * V_36 )
{
struct V_9 * V_10 = V_1 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_13 ;
int V_37 , V_38 ;
V_13 -> V_35 = V_36 [ 0 ] >> 7 ;
V_37 = ( ( V_36 [ 0 ] >> 4 ) & 0x7 ) - 1 ;
if ( V_37 < V_17 ) {
V_13 -> V_20 [ V_37 ] . V_26 += ( char ) V_36 [ 1 ] ;
V_13 -> V_20 [ V_37 ] . V_28 += ( char ) V_36 [ 2 ] ;
} else {
F_16 ( V_1 , L_4 ,
V_37 ) ;
}
V_38 = ( ( V_36 [ 3 ] >> 4 ) & 0x7 ) - 1 ;
if ( V_38 < V_17 ) {
V_13 -> V_20 [ V_38 ] . V_26 += ( char ) V_36 [ 4 ] ;
V_13 -> V_20 [ V_38 ] . V_28 += ( char ) V_36 [ 5 ] ;
}
}
static void F_18 ( struct V_1 * V_1 )
{
unsigned char * V_36 = V_1 -> V_36 ;
switch ( V_36 [ 0 ] & 0xf ) {
case V_39 :
F_14 ( V_1 , V_36 ) ;
break;
case V_40 :
F_15 ( V_1 , V_36 ) ;
break;
case V_41 :
F_17 ( V_1 , V_36 ) ;
break;
default:
F_16 ( V_1 , L_5 , V_36 [ 0 ] ) ;
break;
}
F_6 ( V_1 ) ;
}
static T_1 F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_42 >= 6 ) {
F_18 ( V_1 ) ;
return V_43 ;
}
return V_44 ;
}
static int F_20 ( struct V_1 * V_1 )
{
struct V_7 * V_7 = & V_1 -> V_7 ;
unsigned char V_45 [ 3 ] ;
V_45 [ 0 ] = 0 ;
if ( F_4 ( V_7 , V_45 , 0x10f8 ) )
return - V_46 ;
if ( F_4 ( V_7 , V_45 , 0x10f8 ) )
return - V_46 ;
if ( F_4 ( V_7 , V_45 , 0x10f8 ) )
return - V_46 ;
V_45 [ 0 ] = 1 ;
if ( F_4 ( V_7 , V_45 , 0x10f8 ) )
return - V_46 ;
if ( F_4 ( V_7 , V_45 , V_47 ) )
return - V_46 ;
if ( F_4 ( V_7 , V_45 , V_48 ) )
return - V_46 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
F_3 ( V_1 ) ;
F_22 ( V_1 -> V_11 ) ;
V_1 -> V_11 = NULL ;
}
static int F_23 ( struct V_1 * V_1 )
{
int error ;
F_3 ( V_1 ) ;
error = F_20 ( V_1 ) ;
if ( error ) {
F_16 ( V_1 , L_6 ) ;
return error ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_15 ;
struct V_9 * V_10 = V_1 -> V_11 ;
F_25 ( V_49 , V_15 -> V_50 ) ;
F_25 ( V_51 , V_15 -> V_52 ) ;
F_25 ( V_53 , V_15 -> V_52 ) ;
F_25 ( V_54 , V_15 -> V_55 ) ;
F_25 ( V_56 , V_15 -> V_55 ) ;
F_26 ( V_57 , V_15 -> V_50 ) ;
F_27 ( V_15 , V_30 , 0 , V_10 -> V_27 , 0 , 0 ) ;
F_27 ( V_15 , V_31 , 0 , V_10 -> V_29 , 0 , 0 ) ;
F_27 ( V_15 , V_32 , 0 , 15 , 0 , 0 ) ;
F_28 ( V_15 , 5 , V_58 ) ;
F_26 ( V_59 , V_15 -> V_60 ) ;
}
static int F_29 ( struct V_7 * V_7 , int V_61 ,
unsigned char * V_45 )
{
if ( F_4 ( V_7 , V_45 , V_47 ) )
return - V_46 ;
V_45 [ 0 ] = 0 ;
if ( F_4 ( V_7 , V_45 , V_62 ) )
return - V_46 ;
if ( F_4 ( V_7 , V_45 , V_62 ) )
return - V_46 ;
if ( F_4 ( V_7 , V_45 , V_62 ) )
return - V_46 ;
V_45 [ 0 ] = V_61 ;
if ( F_4 ( V_7 , V_45 , V_62 ) )
return - V_46 ;
if ( F_4 ( V_7 , V_45 , V_63 ) )
return - V_46 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_7 * V_7 = & V_1 -> V_7 ;
struct V_9 * V_10 = V_1 -> V_11 ;
char V_45 [ 3 ] ;
if ( F_29 ( V_7 , 2 , V_45 ) )
return - V_46 ;
V_10 -> V_27 = ( unsigned char ) V_45 [ 1 ] * 128 ;
V_10 -> V_29 = ( unsigned char ) V_45 [ 2 ] * 128 ;
return 0 ;
}
void F_31 ( struct V_1 * V_1 , unsigned int V_64 )
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
struct V_9 * V_10 ;
int error ;
V_1 -> V_11 = V_10 = F_35 ( sizeof( struct V_9 ) ,
V_68 ) ;
if ( ! V_10 )
return - V_69 ;
F_3 ( V_1 ) ;
error = F_30 ( V_1 ) ;
if ( error ) {
F_16 ( V_1 ,
L_7 ) ;
goto V_70;
}
error = F_20 ( V_1 ) ;
if ( error ) {
F_16 ( V_1 , L_6 ) ;
goto V_70;
}
F_24 ( V_1 ) ;
V_1 -> V_71 = F_19 ;
V_1 -> V_72 = 6 ;
V_1 -> V_73 = F_21 ;
V_1 -> V_74 = F_23 ;
V_1 -> V_75 = F_3 ;
V_1 -> V_76 = 0 ;
V_1 -> V_77 = F_31 ;
V_1 -> V_78 = F_32 ;
V_1 -> V_79 = F_33 ;
return 0 ;
V_70:
F_3 ( V_1 ) ;
F_22 ( V_10 ) ;
return error ;
}
int F_34 ( struct V_1 * V_1 )
{
F_3 ( V_1 ) ;
return 0 ;
}
