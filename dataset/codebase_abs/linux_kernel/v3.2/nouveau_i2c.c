static void
F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = ( F_2 ( V_6 , 0 , V_4 -> V_8 ) & 0xd0 ) | ( V_2 ? 0x20 : 0 ) ;
F_3 ( V_6 , 0 , V_4 -> V_8 , V_7 | 0x01 ) ;
}
static void
F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = ( F_2 ( V_6 , 0 , V_4 -> V_8 ) & 0xe0 ) | ( V_2 ? 0x10 : 0 ) ;
F_3 ( V_6 , 0 , V_4 -> V_8 , V_7 | 0x01 ) ;
}
static int
F_5 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! ! ( F_2 ( V_6 , 0 , V_4 -> V_9 ) & 4 ) ;
}
static int
F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! ! ( F_2 ( V_6 , 0 , V_4 -> V_9 ) & 8 ) ;
}
static void
F_7 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = ( F_8 ( V_6 , V_4 -> V_8 ) & 0xd0 ) | ( V_2 ? 0x20 : 0 ) ;
F_9 ( V_6 , V_4 -> V_8 , V_7 | 0x01 ) ;
}
static void
F_10 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 ;
V_7 = ( F_8 ( V_6 , V_4 -> V_8 ) & 0xe0 ) | ( V_2 ? 0x10 : 0 ) ;
F_9 ( V_6 , V_4 -> V_8 , V_7 | 0x01 ) ;
}
static int
F_11 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! ! ( ( F_8 ( V_6 , V_4 -> V_9 ) >> 16 ) & 4 ) ;
}
static int
F_12 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! ! ( ( F_8 ( V_6 , V_4 -> V_9 ) >> 16 ) & 8 ) ;
}
static int
F_13 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! ! ( F_8 ( V_6 , V_4 -> V_9 ) & 1 ) ;
}
static int
F_14 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
return ! ! ( F_8 ( V_6 , V_4 -> V_9 ) & 2 ) ;
}
static void
F_15 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_9 ( V_4 -> V_6 , V_4 -> V_8 , 4 | ( V_4 -> V_1 ? 2 : 0 ) | ( V_2 ? 1 : 0 ) ) ;
}
static void
F_16 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
F_17 ( V_4 -> V_6 , V_4 -> V_8 , 0x00000006 , 4 | ( V_2 ? 2 : 0 ) ) ;
V_4 -> V_1 = V_2 ;
}
static int
F_18 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_9 ) & 0x10 ) ;
}
static int
F_19 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return ! ! ( F_8 ( V_4 -> V_6 , V_4 -> V_9 ) & 0x20 ) ;
}
int
F_20 ( struct V_5 * V_6 , struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 = V_6 -> V_15 ;
struct V_3 * V_4 ;
int V_16 ;
if ( V_11 -> V_17 )
return - V_18 ;
if ( V_14 -> V_19 >= V_20 &&
V_14 -> V_19 <= V_21 && V_11 -> V_22 >= V_23 ) {
F_21 ( V_6 , L_1 , V_11 -> V_22 ) ;
return - V_24 ;
}
V_4 = F_22 ( sizeof( * V_4 ) , V_25 ) ;
if ( V_4 == NULL )
return - V_26 ;
switch ( V_11 -> V_27 ) {
case 0 :
V_4 -> V_28 . V_29 = F_4 ;
V_4 -> V_28 . V_30 = F_1 ;
V_4 -> V_28 . V_31 = F_6 ;
V_4 -> V_28 . V_32 = F_5 ;
V_4 -> V_9 = V_11 -> V_22 ;
V_4 -> V_8 = V_11 -> V_33 ;
break;
case 4 :
V_4 -> V_28 . V_29 = F_10 ;
V_4 -> V_28 . V_30 = F_7 ;
V_4 -> V_28 . V_31 = F_12 ;
V_4 -> V_28 . V_32 = F_11 ;
V_4 -> V_9 = 0x600800 + V_11 -> V_22 ;
V_4 -> V_8 = 0x600800 + V_11 -> V_33 ;
break;
case 5 :
V_4 -> V_28 . V_29 = F_16 ;
V_4 -> V_28 . V_30 = F_15 ;
if ( V_14 -> V_19 < V_34 ) {
V_4 -> V_28 . V_31 = F_14 ;
V_4 -> V_28 . V_32 = F_13 ;
V_4 -> V_9 = V_35 [ V_11 -> V_22 ] ;
V_4 -> V_8 = V_4 -> V_9 ;
} else {
V_4 -> V_28 . V_31 = F_19 ;
V_4 -> V_28 . V_32 = F_18 ;
V_4 -> V_9 = 0x00d014 + ( V_11 -> V_22 * 0x20 ) ;
V_4 -> V_8 = V_4 -> V_9 ;
}
break;
case 6 :
V_4 -> V_9 = V_11 -> V_22 ;
V_4 -> V_8 = V_11 -> V_33 ;
break;
default:
F_21 ( V_6 , L_2 ,
V_11 -> V_27 ) ;
F_23 ( V_4 ) ;
return - V_24 ;
}
snprintf ( V_4 -> V_36 . V_37 , sizeof( V_4 -> V_36 . V_37 ) ,
L_3 , F_24 ( V_6 -> V_38 ) , V_12 ) ;
V_4 -> V_36 . V_39 = V_40 ;
V_4 -> V_36 . V_6 . V_41 = & V_6 -> V_38 -> V_6 ;
V_4 -> V_6 = V_6 ;
F_25 ( & V_4 -> V_36 , V_4 ) ;
if ( V_11 -> V_27 < 6 ) {
V_4 -> V_36 . V_42 = & V_4 -> V_28 ;
V_4 -> V_28 . V_43 = 40 ;
V_4 -> V_28 . V_44 = F_26 ( 5000 ) ;
V_4 -> V_28 . V_1 = V_4 ;
V_16 = F_27 ( & V_4 -> V_36 ) ;
} else {
V_4 -> V_36 . V_45 = & V_46 ;
V_16 = F_28 ( & V_4 -> V_36 ) ;
}
if ( V_16 ) {
F_21 ( V_6 , L_4 , V_12 ) ;
F_23 ( V_4 ) ;
return V_16 ;
}
V_11 -> V_17 = V_4 ;
return 0 ;
}
void
F_29 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
if ( ! V_11 -> V_17 )
return;
F_30 ( & V_11 -> V_17 -> V_36 ) ;
F_23 ( V_11 -> V_17 ) ;
V_11 -> V_17 = NULL ;
}
struct V_3 *
F_31 ( struct V_5 * V_6 , int V_12 )
{
struct V_13 * V_14 = V_6 -> V_15 ;
struct V_10 * V_4 = & V_14 -> V_47 . V_48 . V_4 [ V_12 ] ;
if ( V_12 >= V_49 )
return NULL ;
if ( V_14 -> V_19 >= V_20 && ( V_4 -> V_11 & 0x00000100 ) ) {
T_2 V_50 = 0xe500 , V_7 ;
if ( V_4 -> V_27 == 6 ) {
V_50 += V_4 -> V_22 * 0x50 ;
V_7 = 0x2002 ;
} else {
V_50 += ( ( V_4 -> V_11 & 0x1e00 ) >> 9 ) * 0x50 ;
V_7 = 0xe001 ;
}
F_17 ( V_6 , V_50 + 0x0c , 0x00000001 , 0x00000000 ) ;
F_17 ( V_6 , V_50 + 0x00 , 0x0000f003 , V_7 ) ;
}
if ( ! V_4 -> V_17 && F_20 ( V_6 , V_4 , V_12 ) )
return NULL ;
return V_4 -> V_17 ;
}
bool
F_32 ( struct V_3 * V_4 , int V_51 )
{
T_1 V_52 [] = { 0 } ;
struct V_53 V_54 [] = {
{
. V_51 = V_51 ,
. V_55 = 0 ,
. V_56 = 1 ,
. V_52 = V_52 ,
} ,
{
. V_51 = V_51 ,
. V_55 = V_57 ,
. V_56 = 1 ,
. V_52 = V_52 ,
}
} ;
return F_33 ( & V_4 -> V_36 , V_54 , 2 ) == 2 ;
}
int
F_34 ( struct V_5 * V_6 , const char * V_58 ,
struct V_59 * V_60 ,
bool (* F_35)( struct V_3 * ,
struct V_59 * ) ,
int V_12 )
{
struct V_3 * V_4 = F_31 ( V_6 , V_12 ) ;
int V_61 ;
F_36 ( V_6 , L_5 , V_58 , V_12 ) ;
for ( V_61 = 0 ; V_4 && V_60 [ V_61 ] . V_51 ; V_61 ++ ) {
if ( F_32 ( V_4 , V_60 [ V_61 ] . V_51 ) &&
( ! F_35 || F_35 ( V_4 , & V_60 [ V_61 ] ) ) ) {
F_37 ( V_6 , L_6 , V_58 , V_60 [ V_61 ] . type ) ;
return V_61 ;
}
}
F_36 ( V_6 , L_7 ) ;
return - V_62 ;
}
