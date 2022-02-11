static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
if ( ! V_4 -> V_6 ) {
F_2 ( & V_4 -> V_7 , L_1 ) ;
return - V_8 ;
}
V_5 = F_3 ( V_2 , V_4 ) ;
if ( V_5 )
goto exit;
if ( V_4 -> V_9 ) {
F_4 ( & V_4 -> V_7 , L_2 ) ;
V_5 = F_5 ( V_4 -> V_9 , V_10 ) ;
if ( V_5 )
F_2 ( & V_4 -> V_7 ,
L_3 ,
V_11 , V_5 ) ;
}
exit:
return V_5 ;
}
static void F_6 ( struct V_3 * V_4 )
{
unsigned char * V_12 ;
F_7 ( V_4 ) ;
F_8 ( V_4 -> V_9 ) ;
F_9 ( & V_4 -> V_13 -> V_14 ) ;
if ( ! V_4 -> V_13 -> V_15 ) {
V_12 = F_10 ( 0x12 , V_10 ) ;
if ( V_12 ) {
F_11 ( V_4 -> V_13 -> V_7 ,
F_12 ( V_4 -> V_13 -> V_7 , 0 ) ,
V_16 , 0xc2 ,
0x0000 , 0x0000 ,
V_12 , 0x12 , 300 ) ;
F_13 ( V_12 ) ;
}
}
F_14 ( & V_4 -> V_13 -> V_14 ) ;
}
static void F_15 ( struct V_17 * V_17 )
{
struct V_3 * V_4 = V_17 -> V_18 ;
int V_19 = V_17 -> V_19 ;
int V_5 ;
switch ( V_19 ) {
case 0 :
break;
case - V_20 :
case - V_21 :
case - V_22 :
F_4 ( & V_4 -> V_7 , L_4 ,
V_11 , V_19 ) ;
return;
default:
F_4 ( & V_4 -> V_7 , L_5 ,
V_11 , V_19 ) ;
goto exit;
}
F_16 ( & V_4 -> V_7 , V_11 , V_17 -> V_23 ,
V_17 -> V_12 ) ;
exit:
V_5 = F_5 ( V_17 , V_24 ) ;
if ( V_5 )
F_2 ( & V_17 -> V_7 -> V_7 ,
L_6 ,
V_11 , V_5 ) ;
}
static int F_17 ( struct V_25 * V_13 ,
const struct V_26 * V_27 )
{
struct V_28 * V_7 = & V_13 -> V_7 -> V_7 ;
struct V_29 * V_30 ;
unsigned char * V_12 ;
char * string ;
int V_31 = 0 ;
int V_32 ;
int V_33 = 0 ;
V_12 = F_10 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_12 ) {
F_2 ( V_7 , L_7 , V_11 ,
sizeof( * V_30 ) ) ;
return - V_34 ;
}
V_31 = F_11 ( V_13 -> V_7 ,
F_12 ( V_13 -> V_7 , 0 ) ,
V_35 ,
0xc2 , 0x0000 , 0x0000 , V_12 ,
sizeof( * V_30 ) , 300 ) ;
if ( V_31 < 0 ) {
F_2 ( V_7 , L_8 ,
V_11 , V_31 ) ;
goto exit;
}
if ( V_31 == sizeof( * V_30 ) ) {
V_30 = (struct V_29 * )
V_12 ;
V_33 = F_18 ( V_30 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
switch (
V_30 -> V_36 [ V_32 ] . V_37 ) {
case V_38 :
string = L_9 ;
break;
case V_39 :
string = L_10 ;
break;
case V_40 :
string = L_11 ;
break;
case V_41 :
string = L_12 ;
break;
case V_42 :
string = L_13 ;
break;
default:
string = L_14 ;
break;
}
F_19 ( V_7 , L_15 ,
V_13 -> type -> V_43 ,
V_30 -> V_36 [ V_32 ] . V_4 , string ) ;
}
}
if ( V_33 == 0 || V_33 > 2 ) {
F_20 ( V_7 , L_16 ,
V_13 -> type -> V_43 ) ;
V_33 = 2 ;
}
F_19 ( V_7 , L_17 , V_13 -> type -> V_43 ,
V_33 ) ;
F_21 ( V_13 , ( void * ) ( long ) V_33 ) ;
V_31 = F_11 ( V_13 -> V_7 ,
F_12 ( V_13 -> V_7 , 0 ) ,
V_44 ,
0xc2 , 0x0000 , 0x0005 , V_12 ,
0x02 , 300 ) ;
if ( V_31 < 0 )
F_2 ( V_7 , L_18 ,
V_11 , V_31 ) ;
V_31 = 0 ;
exit:
F_13 ( V_12 ) ;
return V_31 ;
}
static int F_22 ( struct V_25 * V_13 ,
const struct V_26 * V_27 )
{
struct V_28 * V_7 = & V_13 -> V_7 -> V_7 ;
struct V_45 * V_30 ;
unsigned char * V_12 ;
int V_31 ;
V_12 = F_10 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_12 ) {
F_2 ( V_7 , L_7 , V_11 ,
sizeof( * V_30 ) ) ;
return - V_34 ;
}
V_31 = F_11 ( V_13 -> V_7 ,
F_12 ( V_13 -> V_7 , 0 ) ,
V_46 ,
0xc2 , 0x0000 , 0x0000 , V_12 ,
sizeof( * V_30 ) , 300 ) ;
if ( V_31 < 0 )
F_2 ( V_7 , L_19 ,
V_11 , V_31 ) ;
else
F_16 ( V_7 , V_11 , V_31 , V_12 ) ;
F_13 ( V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_25 * V_13 ,
const struct V_26 * V_27 )
{
int V_31 = 0 ;
int (* F_24)( struct V_25 * V_13 ,
const struct V_26 * V_27 );
if ( V_27 -> V_47 == V_48 &&
V_27 -> V_49 == V_50 &&
V_13 -> V_7 -> V_51 . V_52 == V_53 &&
V_13 -> V_7 -> V_51 . V_54 ==
V_55 )
return - V_8 ;
if ( V_13 -> V_7 -> V_56 -> V_57 . V_58 != 1 ) {
F_2 ( & V_13 -> V_7 -> V_7 , L_20 ,
V_13 -> V_7 -> V_56 -> V_57 . V_58 ) ;
return - V_8 ;
}
if ( V_27 -> V_59 ) {
F_24 = ( void * ) V_27 -> V_59 ;
V_31 = F_24 ( V_13 , V_27 ) ;
}
return V_31 ;
}
static int F_25 ( struct V_25 * V_13 )
{
int V_33 = ( int ) ( long ) ( F_26 ( V_13 ) ) ;
if ( V_33 )
F_21 ( V_13 , NULL ) ;
return V_33 ;
}
static int F_27 ( struct V_25 * V_13 )
{
struct V_28 * V_7 = & V_13 -> V_7 -> V_7 ;
int V_5 ;
T_1 * V_60 ;
V_60 = F_10 ( 1 , V_10 ) ;
if ( ! V_60 )
return - V_34 ;
V_5 = F_11 ( V_13 -> V_7 , F_12 ( V_13 -> V_7 , 0 ) ,
V_61 , V_62 ,
0 , 0 , V_60 , 1 , 3000 ) ;
if ( V_5 < 0 ) {
F_2 ( V_7 , L_21 ,
V_11 , V_5 ) ;
goto V_63;
}
if ( V_5 != 1 ) {
F_2 ( V_7 , L_22 ,
V_11 , V_5 ) ;
V_5 = - V_64 ;
goto V_63;
}
V_5 = F_11 ( V_13 -> V_7 , F_12 ( V_13 -> V_7 , 0 ) ,
V_65 ,
V_62 | V_66 ,
0 , 0 , V_60 , 1 , 3000 ) ;
if ( V_5 < 0 ) {
F_2 ( V_7 , L_23 ,
V_11 , V_5 ) ;
goto V_63;
}
if ( V_5 != 1 ) {
F_2 ( V_7 ,
L_24 ,
V_11 , V_5 ) ;
V_5 = - V_64 ;
goto V_63;
}
V_5 = 0 ;
V_63:
F_13 ( V_60 ) ;
return V_5 ;
}
static int F_28 ( struct V_25 * V_13 )
{
struct V_3 * V_67 ;
if ( ! ( ( F_18 ( V_13 -> V_7 -> V_51 . V_47 )
== V_68 ) ||
( F_18 ( V_13 -> V_7 -> V_51 . V_47 )
== V_69 ) ) ||
( V_13 -> V_70 == 0 ) )
return 0 ;
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
V_67 = F_10 ( sizeof( * V_67 ) , V_10 ) ;
if ( ! V_67 )
return - V_34 ;
F_29 ( V_67 , V_13 -> V_4 [ 0 ] ) ;
F_29 ( V_13 -> V_4 [ 0 ] , V_13 -> V_4 [ 1 ] ) ;
F_29 ( V_13 -> V_4 [ 1 ] , V_67 ) ;
F_13 ( V_67 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_13 )
{
struct V_3 * V_4 ;
unsigned int V_71 ;
int V_72 ;
if ( V_13 -> V_33 < 2 )
return - 1 ;
V_4 = V_13 -> V_4 [ 0 ] ;
V_4 -> V_73 =
V_13 -> V_4 [ 1 ] -> V_73 ;
V_71 = F_31 ( V_13 -> V_7 , V_4 -> V_73 ) ;
for ( V_72 = 0 ; V_72 < F_32 ( V_4 -> V_74 ) ; ++ V_72 )
V_4 -> V_74 [ V_72 ] -> V_71 = V_71 ;
return 0 ;
}
