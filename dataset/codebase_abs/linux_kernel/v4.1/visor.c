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
V_12 = F_9 ( 0x12 , V_10 ) ;
if ( ! V_12 )
return;
F_10 ( V_4 -> V_13 -> V_7 ,
F_11 ( V_4 -> V_13 -> V_7 , 0 ) ,
V_14 , 0xc2 ,
0x0000 , 0x0000 ,
V_12 , 0x12 , 300 ) ;
F_12 ( V_12 ) ;
}
static void F_13 ( struct V_15 * V_15 )
{
struct V_3 * V_4 = V_15 -> V_16 ;
int V_17 = V_15 -> V_17 ;
int V_5 ;
switch ( V_17 ) {
case 0 :
break;
case - V_18 :
case - V_19 :
case - V_20 :
F_4 ( & V_4 -> V_7 , L_4 ,
V_11 , V_17 ) ;
return;
default:
F_4 ( & V_4 -> V_7 , L_5 ,
V_11 , V_17 ) ;
goto exit;
}
F_14 ( & V_4 -> V_7 , V_11 , V_15 -> V_21 ,
V_15 -> V_12 ) ;
exit:
V_5 = F_5 ( V_15 , V_22 ) ;
if ( V_5 )
F_2 ( & V_15 -> V_7 -> V_7 ,
L_6 ,
V_11 , V_5 ) ;
}
static int F_15 ( struct V_23 * V_13 ,
const struct V_24 * V_25 )
{
struct V_26 * V_7 = & V_13 -> V_7 -> V_7 ;
struct V_27 * V_28 ;
unsigned char * V_12 ;
char * string ;
int V_29 = 0 ;
int V_30 ;
int V_31 = 0 ;
V_12 = F_9 ( sizeof( * V_28 ) , V_10 ) ;
if ( ! V_12 )
return - V_32 ;
V_29 = F_10 ( V_13 -> V_7 ,
F_11 ( V_13 -> V_7 , 0 ) ,
V_33 ,
0xc2 , 0x0000 , 0x0000 , V_12 ,
sizeof( * V_28 ) , 300 ) ;
if ( V_29 < 0 ) {
F_2 ( V_7 , L_7 ,
V_11 , V_29 ) ;
goto exit;
}
if ( V_29 == sizeof( * V_28 ) ) {
V_28 = (struct V_27 * )
V_12 ;
V_31 = F_16 ( V_28 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; ++ V_30 ) {
switch (
V_28 -> V_34 [ V_30 ] . V_35 ) {
case V_36 :
string = L_8 ;
break;
case V_37 :
string = L_9 ;
break;
case V_38 :
string = L_10 ;
break;
case V_39 :
string = L_11 ;
break;
case V_40 :
string = L_12 ;
break;
default:
string = L_13 ;
break;
}
F_17 ( V_7 , L_14 ,
V_13 -> type -> V_41 ,
V_28 -> V_34 [ V_30 ] . V_4 , string ) ;
}
}
if ( V_31 == 0 || V_31 > 2 ) {
F_18 ( V_7 , L_15 ,
V_13 -> type -> V_41 ) ;
V_31 = 2 ;
}
F_17 ( V_7 , L_16 , V_13 -> type -> V_41 ,
V_31 ) ;
F_19 ( V_13 , ( void * ) ( long ) V_31 ) ;
V_29 = F_10 ( V_13 -> V_7 ,
F_11 ( V_13 -> V_7 , 0 ) ,
V_42 ,
0xc2 , 0x0000 , 0x0005 , V_12 ,
0x02 , 300 ) ;
if ( V_29 < 0 )
F_2 ( V_7 , L_17 ,
V_11 , V_29 ) ;
V_29 = 0 ;
exit:
F_12 ( V_12 ) ;
return V_29 ;
}
static int F_20 ( struct V_23 * V_13 ,
const struct V_24 * V_25 )
{
struct V_26 * V_7 = & V_13 -> V_7 -> V_7 ;
struct V_43 * V_28 ;
unsigned char * V_12 ;
int V_29 ;
V_12 = F_9 ( sizeof( * V_28 ) , V_10 ) ;
if ( ! V_12 )
return - V_32 ;
V_29 = F_10 ( V_13 -> V_7 ,
F_11 ( V_13 -> V_7 , 0 ) ,
V_44 ,
0xc2 , 0x0000 , 0x0000 , V_12 ,
sizeof( * V_28 ) , 300 ) ;
if ( V_29 < 0 )
F_2 ( V_7 , L_18 ,
V_11 , V_29 ) ;
else
F_14 ( V_7 , V_11 , V_29 , V_12 ) ;
F_12 ( V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_23 * V_13 ,
const struct V_24 * V_25 )
{
int V_29 = 0 ;
int (* F_22)( struct V_23 * V_13 ,
const struct V_24 * V_25 );
if ( V_25 -> V_45 == V_46 &&
V_25 -> V_47 == V_48 &&
V_13 -> V_7 -> V_49 . V_50 == V_51 &&
V_13 -> V_7 -> V_49 . V_52 ==
V_53 )
return - V_8 ;
if ( V_13 -> V_7 -> V_54 -> V_55 . V_56 != 1 ) {
F_2 ( & V_13 -> V_7 -> V_7 , L_19 ,
V_13 -> V_7 -> V_54 -> V_55 . V_56 ) ;
return - V_8 ;
}
if ( V_25 -> V_57 ) {
F_22 = ( void * ) V_25 -> V_57 ;
V_29 = F_22 ( V_13 , V_25 ) ;
}
return V_29 ;
}
static int F_23 ( struct V_23 * V_13 )
{
int V_31 = ( int ) ( long ) ( F_24 ( V_13 ) ) ;
if ( V_31 )
F_19 ( V_13 , NULL ) ;
return V_31 ;
}
static int F_25 ( struct V_23 * V_13 )
{
struct V_26 * V_7 = & V_13 -> V_7 -> V_7 ;
int V_5 ;
T_1 * V_58 ;
V_58 = F_9 ( 1 , V_10 ) ;
if ( ! V_58 )
return - V_32 ;
V_5 = F_10 ( V_13 -> V_7 , F_11 ( V_13 -> V_7 , 0 ) ,
V_59 , V_60 ,
0 , 0 , V_58 , 1 , 3000 ) ;
if ( V_5 < 0 ) {
F_2 ( V_7 , L_20 ,
V_11 , V_5 ) ;
goto V_61;
}
if ( V_5 != 1 ) {
F_2 ( V_7 , L_21 ,
V_11 , V_5 ) ;
V_5 = - V_62 ;
goto V_61;
}
V_5 = F_10 ( V_13 -> V_7 , F_11 ( V_13 -> V_7 , 0 ) ,
V_63 ,
V_60 | V_64 ,
0 , 0 , V_58 , 1 , 3000 ) ;
if ( V_5 < 0 ) {
F_2 ( V_7 , L_22 ,
V_11 , V_5 ) ;
goto V_61;
}
if ( V_5 != 1 ) {
F_2 ( V_7 ,
L_23 ,
V_11 , V_5 ) ;
V_5 = - V_62 ;
goto V_61;
}
V_5 = 0 ;
V_61:
F_12 ( V_58 ) ;
return V_5 ;
}
static int F_26 ( struct V_23 * V_13 )
{
struct V_3 * V_65 ;
if ( ! ( ( F_16 ( V_13 -> V_7 -> V_49 . V_45 )
== V_66 ) ||
( F_16 ( V_13 -> V_7 -> V_49 . V_45 )
== V_67 ) ) ||
( V_13 -> V_68 == 0 ) )
return 0 ;
#define F_27 ( T_2 , T_3 ) \
do { \
int i; \
\
for (i = 0; i < ARRAY_SIZE(src->read_urbs); ++i) { \
dest->read_urbs[i] = src->read_urbs[i]; \
dest->read_urbs[i]->context = dest; \
dest->bulk_in_buffers[i] = src->bulk_in_buffers[i]; \
} \
dest->read_urb = src->read_urb; \
dest->bulk_in_endpointAddress = src->bulk_in_endpointAddress;\
dest->bulk_in_buffer = src->bulk_in_buffer; \
dest->bulk_in_size = src->bulk_in_size; \
dest->interrupt_in_urb = src->interrupt_in_urb; \
dest->interrupt_in_urb->context = dest; \
dest->interrupt_in_endpointAddress = \
src->interrupt_in_endpointAddress;\
dest->interrupt_in_buffer = src->interrupt_in_buffer; \
} while (0);
V_65 = F_9 ( sizeof( * V_65 ) , V_10 ) ;
if ( ! V_65 )
return - V_32 ;
F_27 ( V_65 , V_13 -> V_4 [ 0 ] ) ;
F_27 ( V_13 -> V_4 [ 0 ] , V_13 -> V_4 [ 1 ] ) ;
F_27 ( V_13 -> V_4 [ 1 ] , V_65 ) ;
F_12 ( V_65 ) ;
return 0 ;
}
static int F_28 ( struct V_23 * V_13 )
{
struct V_3 * V_4 ;
unsigned int V_69 ;
int V_70 ;
if ( V_13 -> V_31 < 2 )
return - 1 ;
V_4 = V_13 -> V_4 [ 0 ] ;
V_4 -> V_71 =
V_13 -> V_4 [ 1 ] -> V_71 ;
V_69 = F_29 ( V_13 -> V_7 , V_4 -> V_71 ) ;
for ( V_70 = 0 ; V_70 < F_30 ( V_4 -> V_72 ) ; ++ V_70 )
V_4 -> V_72 [ V_70 ] -> V_69 = V_69 ;
return 0 ;
}
