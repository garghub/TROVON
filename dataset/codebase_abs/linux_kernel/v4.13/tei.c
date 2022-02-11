static unsigned int
F_1 ( void )
{
unsigned int V_1 ;
F_2 ( & V_1 , sizeof( V_1 ) ) ;
return ( V_1 & 0xffff ) ;
}
static struct V_2 *
F_3 ( struct V_2 * V_3 , int V_4 )
{
struct V_2 * V_5 = * ( V_3 -> V_6 . V_7 ) ;
if ( V_4 == 127 )
return ( NULL ) ;
while ( V_5 )
if ( V_5 -> V_8 . V_4 == V_4 )
return ( V_5 ) ;
else
V_5 = V_5 -> V_9 ;
return ( NULL ) ;
}
static void
F_4 ( struct V_2 * V_3 , T_1 V_10 , unsigned int V_11 , T_1 V_4 )
{
struct V_12 * V_13 ;
T_1 * V_14 ;
if ( ! ( V_13 = F_5 ( 8 , V_15 ) ) ) {
F_6 ( V_16 L_1 ) ;
return;
}
V_14 = F_7 ( V_13 , 3 ) ;
V_14 [ 0 ] = ( V_17 << 2 ) ;
V_14 [ 1 ] = ( V_18 << 1 ) | 0x1 ;
V_14 [ 2 ] = V_19 ;
V_14 = F_7 ( V_13 , 5 ) ;
V_14 [ 0 ] = V_20 ;
V_14 [ 1 ] = V_11 >> 8 ;
V_14 [ 2 ] = V_11 & 0xff ;
V_14 [ 3 ] = V_10 ;
V_14 [ 4 ] = ( V_4 << 1 ) | 1 ;
V_3 -> V_8 . V_21 ( V_3 , V_22 | V_23 , V_13 ) ;
}
static void
F_8 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_25 -> V_28 ;
if ( V_3 -> V_8 . V_4 != - 1 ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_2 ,
V_3 -> V_8 . V_4 ) ;
return;
}
V_3 -> V_29 . V_11 = F_1 () ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_3 , V_3 -> V_29 . V_11 ) ;
F_4 ( V_3 , V_33 , V_3 -> V_29 . V_11 , 127 ) ;
F_9 ( & V_3 -> V_29 . V_30 , V_34 ) ;
F_10 ( & V_3 -> V_29 . V_35 , V_3 -> V_29 . V_36 , V_37 , NULL , 1 ) ;
V_3 -> V_29 . V_38 = 3 ;
}
static void
F_11 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_39 , * V_3 = V_25 -> V_28 ;
struct V_12 * V_13 = V_27 ;
struct V_40 * V_41 ;
int V_11 , V_4 ;
V_11 = ( ( unsigned int ) V_13 -> V_42 [ 1 ] << 8 ) + V_13 -> V_42 [ 2 ] ;
V_4 = V_13 -> V_42 [ 4 ] >> 1 ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_4 , V_11 , V_4 ) ;
if ( ( V_39 = F_3 ( V_3 , V_4 ) ) ) {
if ( V_11 != V_39 -> V_29 . V_11 ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_5 , V_4 ) ;
V_39 -> V_8 . V_43 ( V_39 , V_44 | V_45 , NULL ) ;
}
} else if ( V_11 == V_3 -> V_29 . V_11 ) {
F_12 ( & V_3 -> V_29 . V_35 , 1 ) ;
F_9 ( & V_3 -> V_29 . V_30 , V_46 ) ;
V_3 -> V_47 . V_48 ( V_3 , V_49 | V_23 , ( void * ) ( long ) V_4 ) ;
V_41 = (struct V_40 * ) V_3 -> V_6 . V_50 ;
V_41 -> V_51 ( V_41 , V_49 | V_23 , NULL ) ;
}
}
static void
F_13 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_39 , * V_3 = V_25 -> V_28 ;
struct V_12 * V_13 = V_27 ;
int V_4 , V_11 ;
V_11 = ( ( unsigned int ) V_13 -> V_42 [ 1 ] << 8 ) + V_13 -> V_42 [ 2 ] ;
V_4 = V_13 -> V_42 [ 4 ] >> 1 ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_6 , V_11 , V_4 ) ;
if ( ( V_39 = F_3 ( V_3 , V_4 ) ) ) {
if ( V_11 != V_39 -> V_29 . V_11 ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_5 , V_4 ) ;
F_14 ( & V_39 -> V_29 . V_30 , V_52 , NULL ) ;
}
}
}
static void
F_15 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_25 -> V_28 ;
struct V_12 * V_13 = V_27 ;
int V_11 , V_4 ;
V_11 = ( ( unsigned int ) V_13 -> V_42 [ 1 ] << 8 ) + V_13 -> V_42 [ 2 ] ;
V_4 = V_13 -> V_42 [ 4 ] >> 1 ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_7 , V_11 , V_4 ) ;
}
static void
F_16 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_25 -> V_28 ;
struct V_12 * V_13 = V_27 ;
int V_4 ;
V_4 = V_13 -> V_42 [ 4 ] >> 1 ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_8 , V_4 ) ;
if ( ( V_3 -> V_8 . V_4 != - 1 ) && ( ( V_4 == V_18 ) || ( V_4 == V_3 -> V_8 . V_4 ) ) ) {
F_12 ( & V_3 -> V_29 . V_35 , 4 ) ;
F_9 ( & V_3 -> V_29 . V_30 , V_46 ) ;
F_4 ( V_3 , V_53 , F_1 () , V_3 -> V_8 . V_4 ) ;
}
}
static void
F_17 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_25 -> V_28 ;
struct V_12 * V_13 = V_27 ;
struct V_40 * V_41 ;
int V_4 ;
V_4 = V_13 -> V_42 [ 4 ] >> 1 ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_9 , V_4 ) ;
if ( ( V_3 -> V_8 . V_4 != - 1 ) && ( ( V_4 == V_18 ) || ( V_4 == V_3 -> V_8 . V_4 ) ) ) {
F_12 ( & V_3 -> V_29 . V_35 , 5 ) ;
F_9 ( & V_3 -> V_29 . V_30 , V_46 ) ;
V_3 -> V_47 . V_48 ( V_3 , V_54 | V_23 , NULL ) ;
V_41 = (struct V_40 * ) V_3 -> V_6 . V_50 ;
V_41 -> V_51 ( V_41 , V_54 | V_23 , NULL ) ;
}
}
static void
F_18 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_25 -> V_28 ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_10 , V_3 -> V_8 . V_4 ) ;
F_4 ( V_3 , V_55 , 0 , V_3 -> V_8 . V_4 ) ;
F_9 ( & V_3 -> V_29 . V_30 , V_56 ) ;
F_10 ( & V_3 -> V_29 . V_35 , V_3 -> V_29 . V_36 , V_37 , NULL , 2 ) ;
V_3 -> V_29 . V_38 = 2 ;
}
static void
F_19 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_25 -> V_28 ;
struct V_40 * V_41 ;
if ( -- V_3 -> V_29 . V_38 ) {
V_3 -> V_29 . V_11 = F_1 () ;
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_11 , 4 - V_3 -> V_29 . V_38 ,
V_3 -> V_29 . V_11 ) ;
F_4 ( V_3 , V_33 , V_3 -> V_29 . V_11 , 127 ) ;
F_10 ( & V_3 -> V_29 . V_35 , V_3 -> V_29 . V_36 , V_37 , NULL , 3 ) ;
} else {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 , L_12 ) ;
V_3 -> V_47 . V_48 ( V_3 , V_44 | V_45 , NULL ) ;
V_41 = (struct V_40 * ) V_3 -> V_6 . V_50 ;
V_41 -> V_51 ( V_41 , V_54 | V_23 , NULL ) ;
F_9 ( V_25 , V_46 ) ;
}
}
static void
F_20 ( struct V_24 * V_25 , int V_26 , void * V_27 )
{
struct V_2 * V_3 = V_25 -> V_28 ;
struct V_40 * V_41 ;
if ( -- V_3 -> V_29 . V_38 ) {
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_13 ,
3 - V_3 -> V_29 . V_38 , V_3 -> V_8 . V_4 ) ;
F_4 ( V_3 , V_55 , 0 , V_3 -> V_8 . V_4 ) ;
F_10 ( & V_3 -> V_29 . V_35 , V_3 -> V_29 . V_36 , V_37 , NULL , 4 ) ;
} else {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_14 , V_3 -> V_8 . V_4 ) ;
V_3 -> V_47 . V_48 ( V_3 , V_54 | V_23 , NULL ) ;
V_41 = (struct V_40 * ) V_3 -> V_6 . V_50 ;
V_41 -> V_51 ( V_41 , V_54 | V_23 , NULL ) ;
F_9 ( V_25 , V_46 ) ;
}
}
static void
F_21 ( struct V_2 * V_3 , int V_57 , void * V_27 )
{
struct V_12 * V_13 = V_27 ;
int V_58 ;
if ( F_22 ( V_59 , & V_3 -> V_8 . V_60 ) ) {
F_23 ( V_13 ) ;
return;
}
if ( V_57 == ( V_22 | V_61 ) ) {
if ( V_13 -> V_62 < 3 ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_15 , V_13 -> V_62 ) ;
} else if ( ( V_13 -> V_42 [ 0 ] != ( ( V_17 << 2 ) | 2 ) ) ||
( V_13 -> V_42 [ 1 ] != ( ( V_18 << 1 ) | 1 ) ) ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_16 ,
V_13 -> V_42 [ 0 ] , V_13 -> V_42 [ 1 ] ) ;
} else if ( ( V_13 -> V_42 [ 2 ] & 0xef ) != V_19 ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_17 , V_13 -> V_42 [ 2 ] ) ;
} else {
F_24 ( V_13 , 3 ) ;
if ( V_13 -> V_62 < 5 ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_18 , V_13 -> V_62 ) ;
} else if ( V_13 -> V_42 [ 0 ] != V_20 ) {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_19 ,
V_13 -> V_42 [ 0 ] ) ;
} else {
V_58 = V_13 -> V_42 [ 3 ] ;
if ( V_58 == V_63 )
F_14 ( & V_3 -> V_29 . V_30 , V_64 , V_13 ) ;
else if ( V_58 == V_65 )
F_14 ( & V_3 -> V_29 . V_30 , V_66 , V_13 ) ;
else if ( V_58 == V_67 )
F_14 ( & V_3 -> V_29 . V_30 , V_68 , V_13 ) ;
else if ( V_58 == V_69 )
F_14 ( & V_3 -> V_29 . V_30 , V_70 , V_13 ) ;
else {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_20 , V_58 ) ;
}
}
}
} else {
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_21 , V_57 ) ;
}
F_23 ( V_13 ) ;
}
static void
F_25 ( struct V_2 * V_3 , int V_57 , void * V_27 )
{
struct V_40 * V_41 ;
if ( F_22 ( V_59 , & V_3 -> V_8 . V_60 ) ) {
if ( V_57 == ( V_49 | V_61 ) ) {
if ( V_3 -> V_29 . V_32 )
V_3 -> V_29 . V_30 . V_31 ( & V_3 -> V_29 . V_30 ,
L_22 , V_3 -> V_8 . V_4 ) ;
V_3 -> V_47 . V_48 ( V_3 , V_49 | V_23 , ( void * ) ( long ) V_3 -> V_8 . V_4 ) ;
V_41 = (struct V_40 * ) V_3 -> V_6 . V_50 ;
V_41 -> V_51 ( V_41 , V_49 | V_23 , NULL ) ;
}
return;
}
switch ( V_57 ) {
case ( V_49 | V_61 ) :
F_14 ( & V_3 -> V_29 . V_30 , V_71 , V_27 ) ;
break;
case ( V_44 | V_23 ) :
F_14 ( & V_3 -> V_29 . V_30 , V_52 , V_27 ) ;
break;
default:
break;
}
}
static void
F_26 ( struct V_24 * V_25 , char * V_72 , ... )
{
T_2 args ;
struct V_2 * V_3 = V_25 -> V_28 ;
va_start ( args , V_72 ) ;
F_27 ( V_3 -> V_6 . V_50 , L_23 , V_72 , args ) ;
va_end ( args ) ;
}
void
F_28 ( struct V_2 * V_3 )
{
V_3 -> V_8 . V_43 = F_25 ;
V_3 -> V_29 . V_36 = 2000 ;
V_3 -> V_6 . V_73 = F_21 ;
V_3 -> V_29 . V_32 = 1 ;
V_3 -> V_29 . V_30 . V_74 = & V_75 ;
V_3 -> V_29 . V_30 . V_76 = V_46 ;
V_3 -> V_29 . V_30 . V_32 = 1 ;
V_3 -> V_29 . V_30 . V_28 = V_3 ;
V_3 -> V_29 . V_30 . V_77 = 0 ;
V_3 -> V_29 . V_30 . V_31 = F_26 ;
F_29 ( & V_3 -> V_29 . V_30 , & V_3 -> V_29 . V_35 ) ;
}
void
F_30 ( struct V_40 * V_41 , int V_78 )
{
}
void
F_31 ( struct V_40 * V_41 )
{
struct V_2 * V_3 = V_41 -> V_79 ;
while ( V_3 ) {
F_12 ( & V_3 -> V_29 . V_35 , 1 ) ;
V_3 = V_3 -> V_9 ;
}
}
int T_3
F_32 ( void )
{
V_75 . V_80 = V_81 ;
V_75 . V_82 = V_83 ;
V_75 . V_84 = V_85 ;
V_75 . V_86 = V_87 ;
return F_33 ( & V_75 , V_88 , F_34 ( V_88 ) ) ;
}
void
F_35 ( void )
{
F_36 ( & V_75 ) ;
}
