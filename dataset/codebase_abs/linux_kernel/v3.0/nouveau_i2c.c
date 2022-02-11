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
struct V_5 * V_6 = V_4 -> V_6 ;
F_9 ( V_6 , V_4 -> V_8 , 4 | ( V_4 -> V_1 ? 2 : 0 ) | ( V_2 ? 1 : 0 ) ) ;
}
static void
F_16 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_9 ( V_6 , V_4 -> V_8 ,
( F_8 ( V_6 , V_4 -> V_9 ) & 1 ) | 4 | ( V_2 ? 2 : 0 ) ) ;
V_4 -> V_1 = V_2 ;
}
int
F_17 ( struct V_5 * V_6 , struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 = V_6 -> V_15 ;
struct V_3 * V_4 ;
int V_16 ;
if ( V_11 -> V_17 )
return - V_18 ;
if ( V_14 -> V_19 >= V_20 && V_11 -> V_21 >= V_22 ) {
F_18 ( V_6 , L_1 , V_11 -> V_21 ) ;
return - V_23 ;
}
V_4 = F_19 ( sizeof( * V_4 ) , V_24 ) ;
if ( V_4 == NULL )
return - V_25 ;
switch ( V_11 -> V_26 ) {
case 0 :
V_4 -> V_27 . V_28 = F_4 ;
V_4 -> V_27 . V_29 = F_1 ;
V_4 -> V_27 . V_30 = F_6 ;
V_4 -> V_27 . V_31 = F_5 ;
V_4 -> V_9 = V_11 -> V_21 ;
V_4 -> V_8 = V_11 -> V_32 ;
break;
case 4 :
V_4 -> V_27 . V_28 = F_10 ;
V_4 -> V_27 . V_29 = F_7 ;
V_4 -> V_27 . V_30 = F_12 ;
V_4 -> V_27 . V_31 = F_11 ;
V_4 -> V_9 = 0x600800 + V_11 -> V_21 ;
V_4 -> V_8 = 0x600800 + V_11 -> V_32 ;
break;
case 5 :
V_4 -> V_27 . V_28 = F_16 ;
V_4 -> V_27 . V_29 = F_15 ;
V_4 -> V_27 . V_30 = F_14 ;
V_4 -> V_27 . V_31 = F_13 ;
V_4 -> V_9 = V_33 [ V_11 -> V_21 ] ;
V_4 -> V_8 = V_4 -> V_9 ;
break;
case 6 :
V_4 -> V_9 = V_11 -> V_21 ;
V_4 -> V_8 = V_11 -> V_32 ;
break;
default:
F_18 ( V_6 , L_2 ,
V_11 -> V_26 ) ;
F_20 ( V_4 ) ;
return - V_23 ;
}
snprintf ( V_4 -> V_34 . V_35 , sizeof( V_4 -> V_34 . V_35 ) ,
L_3 , F_21 ( V_6 -> V_36 ) , V_12 ) ;
V_4 -> V_34 . V_37 = V_38 ;
V_4 -> V_34 . V_6 . V_39 = & V_6 -> V_36 -> V_6 ;
V_4 -> V_6 = V_6 ;
F_22 ( & V_4 -> V_34 , V_4 ) ;
if ( V_11 -> V_26 < 6 ) {
V_4 -> V_34 . V_40 = & V_4 -> V_27 ;
V_4 -> V_27 . V_41 = 40 ;
V_4 -> V_27 . V_42 = F_23 ( 5000 ) ;
V_4 -> V_27 . V_1 = V_4 ;
V_16 = F_24 ( & V_4 -> V_34 ) ;
} else {
V_4 -> V_34 . V_43 = & V_44 ;
V_16 = F_25 ( & V_4 -> V_34 ) ;
}
if ( V_16 ) {
F_18 ( V_6 , L_4 , V_12 ) ;
F_20 ( V_4 ) ;
return V_16 ;
}
V_11 -> V_17 = V_4 ;
return 0 ;
}
void
F_26 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
if ( ! V_11 -> V_17 )
return;
F_27 ( & V_11 -> V_17 -> V_34 ) ;
F_20 ( V_11 -> V_17 ) ;
V_11 -> V_17 = NULL ;
}
struct V_3 *
F_28 ( struct V_5 * V_6 , int V_12 )
{
struct V_13 * V_14 = V_6 -> V_15 ;
struct V_10 * V_4 = & V_14 -> V_45 . V_46 . V_4 [ V_12 ] ;
if ( V_12 >= V_47 )
return NULL ;
if ( V_14 -> V_19 >= V_20 && ( V_4 -> V_11 & 0x00000100 ) ) {
T_2 V_48 = 0xe500 , V_7 ;
if ( V_4 -> V_26 == 6 ) {
V_48 += V_4 -> V_21 * 0x50 ;
V_7 = 0x2002 ;
} else {
V_48 += ( ( V_4 -> V_11 & 0x1e00 ) >> 9 ) * 0x50 ;
V_7 = 0xe001 ;
}
F_9 ( V_6 , V_48 , ( F_8 ( V_6 , V_48 ) & ~ 0xf003 ) | V_7 ) ;
}
if ( ! V_4 -> V_17 && F_17 ( V_6 , V_4 , V_12 ) )
return NULL ;
return V_4 -> V_17 ;
}
bool
F_29 ( struct V_3 * V_4 , int V_49 )
{
T_1 V_50 [] = { 0 } ;
struct V_51 V_52 [] = {
{
. V_49 = V_49 ,
. V_53 = 0 ,
. V_54 = 1 ,
. V_50 = V_50 ,
} ,
{
. V_49 = V_49 ,
. V_53 = V_55 ,
. V_54 = 1 ,
. V_50 = V_50 ,
}
} ;
return F_30 ( & V_4 -> V_34 , V_52 , 2 ) == 2 ;
}
int
F_31 ( struct V_5 * V_6 , const char * V_56 ,
struct V_57 * V_58 ,
bool (* F_32)( struct V_3 * ,
struct V_57 * ) ,
int V_12 )
{
struct V_3 * V_4 = F_28 ( V_6 , V_12 ) ;
int V_59 ;
F_33 ( V_6 , L_5 , V_56 , V_12 ) ;
for ( V_59 = 0 ; V_58 [ V_59 ] . V_49 ; V_59 ++ ) {
if ( F_29 ( V_4 , V_58 [ V_59 ] . V_49 ) &&
( ! F_32 || F_32 ( V_4 , & V_58 [ V_59 ] ) ) ) {
F_34 ( V_6 , L_6 , V_56 , V_58 [ V_59 ] . type ) ;
return V_59 ;
}
}
F_33 ( V_6 , L_7 ) ;
return - V_60 ;
}
