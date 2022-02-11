static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
F_2 ( L_1 , V_6 , V_4 -> V_7 ) ;
if ( ! V_4 -> V_8 ) {
F_3 ( & V_4 -> V_9 , L_2 ) ;
return - V_10 ;
}
V_5 = F_4 ( V_2 , V_4 ) ;
if ( V_5 )
goto exit;
if ( V_4 -> V_11 ) {
F_2 ( L_3 , V_6 ) ;
V_5 = F_5 ( V_4 -> V_11 , V_12 ) ;
if ( V_5 )
F_3 ( & V_4 -> V_9 ,
L_4 ,
V_6 , V_5 ) ;
}
exit:
return V_5 ;
}
static void F_6 ( struct V_3 * V_4 )
{
unsigned char * V_13 ;
F_2 ( L_1 , V_6 , V_4 -> V_7 ) ;
F_7 ( V_4 ) ;
F_8 ( V_4 -> V_11 ) ;
F_9 ( & V_4 -> V_14 -> V_15 ) ;
if ( ! V_4 -> V_14 -> V_16 ) {
V_13 = F_10 ( 0x12 , V_12 ) ;
if ( V_13 ) {
F_11 ( V_4 -> V_14 -> V_9 ,
F_12 ( V_4 -> V_14 -> V_9 , 0 ) ,
V_17 , 0xc2 ,
0x0000 , 0x0000 ,
V_13 , 0x12 , 300 ) ;
F_13 ( V_13 ) ;
}
}
F_14 ( & V_4 -> V_14 -> V_15 ) ;
}
static void F_15 ( struct V_18 * V_18 )
{
struct V_3 * V_4 = V_18 -> V_19 ;
int V_20 = V_18 -> V_20 ;
int V_5 ;
switch ( V_20 ) {
case 0 :
break;
case - V_21 :
case - V_22 :
case - V_23 :
F_2 ( L_5 ,
V_6 , V_20 ) ;
return;
default:
F_2 ( L_6 ,
V_6 , V_20 ) ;
goto exit;
}
F_16 ( V_24 , & V_4 -> V_9 , V_6 ,
V_18 -> V_25 , V_18 -> V_13 ) ;
exit:
V_5 = F_5 ( V_18 , V_26 ) ;
if ( V_5 )
F_3 ( & V_18 -> V_9 -> V_9 ,
L_7 ,
V_6 , V_5 ) ;
}
static int F_17 ( struct V_27 * V_14 ,
const struct V_28 * V_29 )
{
struct V_30 * V_9 = & V_14 -> V_9 -> V_9 ;
struct V_31 * V_32 ;
unsigned char * V_13 ;
char * string ;
int V_33 = 0 ;
int V_34 ;
int V_35 = 0 ;
F_2 ( L_8 , V_6 ) ;
V_13 = F_10 ( sizeof( * V_32 ) , V_12 ) ;
if ( ! V_13 ) {
F_3 ( V_9 , L_9 , V_6 ,
sizeof( * V_32 ) ) ;
return - V_36 ;
}
V_33 = F_11 ( V_14 -> V_9 ,
F_12 ( V_14 -> V_9 , 0 ) ,
V_37 ,
0xc2 , 0x0000 , 0x0000 , V_13 ,
sizeof( * V_32 ) , 300 ) ;
if ( V_33 < 0 ) {
F_3 ( V_9 , L_10 ,
V_6 , V_33 ) ;
goto exit;
}
if ( V_33 == sizeof( * V_32 ) ) {
V_32 = (struct V_31 * )
V_13 ;
V_35 = F_18 ( V_32 -> V_35 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; ++ V_34 ) {
switch (
V_32 -> V_38 [ V_34 ] . V_39 ) {
case V_40 :
string = L_11 ;
break;
case V_41 :
string = L_12 ;
break;
case V_42 :
string = L_13 ;
break;
case V_43 :
string = L_14 ;
break;
case V_44 :
string = L_15 ;
break;
default:
string = L_16 ;
break;
}
F_19 ( V_9 , L_17 ,
V_14 -> type -> V_45 ,
V_32 -> V_38 [ V_34 ] . V_4 , string ) ;
}
}
if ( V_35 == 0 || V_35 > 2 ) {
F_20 ( V_9 , L_18 ,
V_14 -> type -> V_45 ) ;
V_35 = 2 ;
}
F_19 ( V_9 , L_19 , V_14 -> type -> V_45 ,
V_35 ) ;
F_21 ( V_14 , ( void * ) ( long ) V_35 ) ;
V_33 = F_11 ( V_14 -> V_9 ,
F_12 ( V_14 -> V_9 , 0 ) ,
V_46 ,
0xc2 , 0x0000 , 0x0005 , V_13 ,
0x02 , 300 ) ;
if ( V_33 < 0 )
F_3 ( V_9 , L_20 ,
V_6 , V_33 ) ;
V_33 = 0 ;
exit:
F_13 ( V_13 ) ;
return V_33 ;
}
static int F_22 ( struct V_27 * V_14 ,
const struct V_28 * V_29 )
{
struct V_30 * V_9 = & V_14 -> V_9 -> V_9 ;
struct V_47 * V_32 ;
unsigned char * V_13 ;
int V_33 ;
F_2 ( L_8 , V_6 ) ;
V_13 = F_10 ( sizeof( * V_32 ) , V_12 ) ;
if ( ! V_13 ) {
F_3 ( V_9 , L_9 , V_6 ,
sizeof( * V_32 ) ) ;
return - V_36 ;
}
V_33 = F_11 ( V_14 -> V_9 ,
F_12 ( V_14 -> V_9 , 0 ) ,
V_48 ,
0xc2 , 0x0000 , 0x0000 , V_13 ,
sizeof( * V_32 ) , 300 ) ;
if ( V_33 < 0 )
F_3 ( V_9 , L_21 ,
V_6 , V_33 ) ;
else
F_16 ( V_24 , & V_14 -> V_9 -> V_9 , V_6 ,
V_33 , V_13 ) ;
F_13 ( V_13 ) ;
return 0 ;
}
static int F_23 ( struct V_27 * V_14 ,
const struct V_28 * V_29 )
{
int V_33 = 0 ;
int (* F_24)( struct V_27 * V_14 ,
const struct V_28 * V_29 );
F_2 ( L_8 , V_6 ) ;
if ( V_29 -> V_49 == V_50 &&
V_29 -> V_51 == V_52 &&
V_14 -> V_9 -> V_53 . V_54 == V_55 &&
V_14 -> V_9 -> V_53 . V_56 ==
V_57 )
return - V_10 ;
if ( V_14 -> V_9 -> V_58 -> V_59 . V_60 != 1 ) {
F_3 ( & V_14 -> V_9 -> V_9 , L_22 ,
V_14 -> V_9 -> V_58 -> V_59 . V_60 ) ;
return - V_10 ;
}
if ( V_29 -> V_61 ) {
F_24 = ( void * ) V_29 -> V_61 ;
V_33 = F_24 ( V_14 , V_29 ) ;
}
return V_33 ;
}
static int F_25 ( struct V_27 * V_14 )
{
int V_35 = ( int ) ( long ) ( F_26 ( V_14 ) ) ;
if ( V_35 )
F_21 ( V_14 , NULL ) ;
return V_35 ;
}
static int F_27 ( struct V_27 * V_14 )
{
struct V_30 * V_9 = & V_14 -> V_9 -> V_9 ;
int V_5 ;
T_1 * V_62 ;
F_2 ( L_8 , V_6 ) ;
V_62 = F_10 ( 1 , V_12 ) ;
if ( ! V_62 )
return - V_36 ;
V_5 = F_11 ( V_14 -> V_9 , F_12 ( V_14 -> V_9 , 0 ) ,
V_63 , V_64 ,
0 , 0 , V_62 , 1 , 3000 ) ;
if ( V_5 < 0 ) {
F_3 ( V_9 , L_23 ,
V_6 , V_5 ) ;
goto V_65;
}
if ( V_5 != 1 ) {
F_3 ( V_9 , L_24 ,
V_6 , V_5 ) ;
V_5 = - V_66 ;
goto V_65;
}
V_5 = F_11 ( V_14 -> V_9 , F_12 ( V_14 -> V_9 , 0 ) ,
V_67 ,
V_64 | V_68 ,
0 , 0 , V_62 , 1 , 3000 ) ;
if ( V_5 < 0 ) {
F_3 ( V_9 , L_25 ,
V_6 , V_5 ) ;
goto V_65;
}
if ( V_5 != 1 ) {
F_3 ( V_9 ,
L_26 ,
V_6 , V_5 ) ;
V_5 = - V_66 ;
goto V_65;
}
V_5 = 0 ;
V_65:
F_13 ( V_62 ) ;
return V_5 ;
}
static int F_28 ( struct V_27 * V_14 )
{
struct V_3 * V_69 ;
if ( ! ( ( F_18 ( V_14 -> V_9 -> V_53 . V_49 )
== V_70 ) ||
( F_18 ( V_14 -> V_9 -> V_53 . V_49 )
== V_71 ) ) ||
( V_14 -> V_72 == 0 ) )
return 0 ;
F_2 ( L_8 , V_6 ) ;
#define F_29 ( T_2 , T_3 ) \
do { \
dest->read_urb = src->read_urb; \
dest->bulk_in_endpointAddress = src->bulk_in_endpointAddress;\
dest->bulk_in_buffer = src->bulk_in_buffer; \
dest->interrupt_in_urb = src->interrupt_in_urb; \
dest->interrupt_in_endpointAddress = \
src->interrupt_in_endpointAddress;\
dest->interrupt_in_buffer = src->interrupt_in_buffer; \
} while (0);
V_69 = F_10 ( sizeof( * V_69 ) , V_12 ) ;
if ( ! V_69 )
return - V_36 ;
F_29 ( V_69 , V_14 -> V_4 [ 0 ] ) ;
F_29 ( V_14 -> V_4 [ 0 ] , V_14 -> V_4 [ 1 ] ) ;
F_29 ( V_14 -> V_4 [ 1 ] , V_69 ) ;
F_13 ( V_69 ) ;
return 0 ;
}
static int F_30 ( struct V_27 * V_14 )
{
struct V_3 * V_4 ;
unsigned int V_73 ;
int V_74 ;
F_2 ( L_8 , V_6 ) ;
if ( V_14 -> V_35 < 2 )
return - 1 ;
V_4 = V_14 -> V_4 [ 0 ] ;
V_4 -> V_75 =
V_14 -> V_4 [ 1 ] -> V_75 ;
V_73 = F_31 ( V_14 -> V_9 , V_4 -> V_75 ) ;
for ( V_74 = 0 ; V_74 < F_32 ( V_4 -> V_76 ) ; ++ V_74 )
V_4 -> V_76 [ V_74 ] -> V_73 = V_73 ;
return 0 ;
}
static int T_4 F_33 ( void )
{
int V_34 , V_33 ;
if ( V_77 > 0 && V_78 > 0 ) {
struct V_28 V_79 [] = {
{
F_34 ( V_77 , V_78 ) ,
. V_61 =
( V_80 ) & F_22
}
} ;
for ( V_34 = 0 ; ; V_34 ++ ) {
if ( V_81 [ V_34 ] . V_49 == 0 ) {
V_81 [ V_34 ] = V_79 [ 0 ] ;
break;
}
}
for ( V_34 = 0 ; ; V_34 ++ ) {
if ( V_82 [ V_34 ] . V_49 == 0 ) {
V_82 [ V_34 ] = V_79 [ 0 ] ;
break;
}
}
F_35 (KERN_INFO KBUILD_MODNAME
L_27 ) ;
F_35 (KERN_INFO KBUILD_MODNAME
L_28 ) ;
F_35 (KERN_INFO KBUILD_MODNAME
L_29 ) ;
F_35 (KERN_INFO KBUILD_MODNAME
L_30 ,
vendor, product) ;
}
V_33 = F_36 ( & V_83 , V_84 ) ;
if ( V_33 == 0 )
F_35 (KERN_INFO KBUILD_MODNAME L_31 DRIVER_DESC L_32 ) ;
return V_33 ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_83 , V_84 ) ;
}
