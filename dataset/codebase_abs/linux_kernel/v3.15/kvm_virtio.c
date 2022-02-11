static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) ( V_3 + 1 ) ;
}
static T_1 * F_2 ( const struct V_2 * V_3 )
{
return ( T_1 * ) ( F_1 ( V_3 ) + V_3 -> V_4 ) ;
}
static T_1 * F_3 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 ) + V_3 -> V_5 * 2 ;
}
static unsigned F_4 ( const struct V_2 * V_3 )
{
return sizeof( * V_3 )
+ V_3 -> V_4 * sizeof( struct V_1 )
+ V_3 -> V_5 * 2
+ V_3 -> V_6 ;
}
static T_2 F_5 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
T_2 V_10 = 0 ;
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
T_1 * V_11 = F_2 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < F_7 ( V_3 -> V_5 * 8 , 32 ) ; V_9 ++ )
if ( V_11 [ V_9 / 8 ] & ( 1 << ( V_9 % 8 ) ) )
V_10 |= ( 1 << V_9 ) ;
return V_10 ;
}
static void F_8 ( struct V_7 * V_8 )
{
unsigned int V_9 , V_12 ;
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
T_1 * V_13 = F_2 ( V_3 ) + V_3 -> V_5 ;
F_9 ( V_8 ) ;
memset ( V_13 , 0 , V_3 -> V_5 ) ;
V_12 = F_10 ( unsigned , V_3 -> V_5 , sizeof( V_8 -> V_10 ) ) * 8 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
if ( F_11 ( V_9 , V_8 -> V_10 ) )
V_13 [ V_9 / 8 ] |= ( 1 << ( V_9 % 8 ) ) ;
}
}
static void F_12 ( struct V_7 * V_8 , unsigned int V_14 ,
void * V_15 , unsigned V_16 )
{
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
F_13 ( V_14 + V_16 > V_3 -> V_6 ) ;
memcpy ( V_15 , F_3 ( V_3 ) + V_14 , V_16 ) ;
}
static void F_14 ( struct V_7 * V_8 , unsigned int V_14 ,
const void * V_15 , unsigned V_16 )
{
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
F_13 ( V_14 + V_16 > V_3 -> V_6 ) ;
memcpy ( F_3 ( V_3 ) + V_14 , V_15 , V_16 ) ;
}
static T_1 F_15 ( struct V_7 * V_8 )
{
return F_6 ( V_8 ) -> V_3 -> V_17 ;
}
static void F_16 ( struct V_7 * V_8 , T_1 V_17 )
{
F_13 ( ! V_17 ) ;
F_6 ( V_8 ) -> V_3 -> V_17 = V_17 ;
F_17 ( V_18 ,
( unsigned long ) F_6 ( V_8 ) -> V_3 ) ;
}
static void F_18 ( struct V_7 * V_8 )
{
F_17 ( V_19 ,
( unsigned long ) F_6 ( V_8 ) -> V_3 ) ;
}
static bool F_19 ( struct V_20 * V_21 )
{
long V_22 ;
struct V_1 * V_23 = V_21 -> V_24 ;
V_22 = F_17 ( V_25 , V_23 -> V_26 ) ;
if ( V_22 < 0 )
return false ;
return true ;
}
static struct V_20 * F_20 ( struct V_7 * V_8 ,
unsigned V_27 ,
void (* F_21)( struct V_20 * V_21 ) ,
const char * V_28 )
{
struct V_29 * V_30 = F_6 ( V_8 ) ;
struct V_1 * V_23 ;
struct V_20 * V_21 ;
int V_31 ;
if ( V_27 >= V_30 -> V_3 -> V_4 )
return F_22 ( - V_32 ) ;
if ( ! V_28 )
return NULL ;
V_23 = F_1 ( V_30 -> V_3 ) + V_27 ;
V_31 = F_23 ( V_23 -> V_26 ,
F_24 ( V_23 -> V_33 ,
V_34 ) ) ;
if ( V_31 )
goto V_35;
V_21 = F_25 ( V_27 , V_23 -> V_33 , V_34 ,
V_8 , true , ( void * ) V_23 -> V_26 ,
F_19 , F_21 , V_28 ) ;
if ( ! V_21 ) {
V_31 = - V_36 ;
goto V_37;
}
V_23 -> V_38 = ( V_39 ) V_21 ;
V_21 -> V_24 = V_23 ;
return V_21 ;
V_37:
F_26 ( V_23 -> V_26 ,
F_24 ( V_23 -> V_33 ,
V_34 ) ) ;
V_35:
return F_22 ( V_31 ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_23 = V_21 -> V_24 ;
F_28 ( V_21 ) ;
F_26 ( V_23 -> V_26 ,
F_24 ( V_23 -> V_33 ,
V_34 ) ) ;
}
static void F_29 ( struct V_7 * V_8 )
{
struct V_20 * V_21 , * V_40 ;
F_30 (vq, n, &vdev->vqs, list)
F_27 ( V_21 ) ;
}
static int F_31 ( struct V_7 * V_8 , unsigned V_41 ,
struct V_20 * V_42 [] ,
T_3 * V_43 [] ,
const char * V_44 [] )
{
struct V_29 * V_30 = F_6 ( V_8 ) ;
int V_9 ;
if ( V_41 > V_30 -> V_3 -> V_4 )
return - V_32 ;
for ( V_9 = 0 ; V_9 < V_41 ; ++ V_9 ) {
V_42 [ V_9 ] = F_20 ( V_8 , V_9 , V_43 [ V_9 ] , V_44 [ V_9 ] ) ;
if ( F_32 ( V_42 [ V_9 ] ) )
goto error;
}
return 0 ;
error:
F_29 ( V_8 ) ;
return F_33 ( V_42 [ V_9 ] ) ;
}
static const char * F_34 ( struct V_7 * V_8 )
{
return L_1 ;
}
static void F_35 ( struct V_2 * V_45 , unsigned int V_14 )
{
struct V_29 * V_30 ;
V_30 = F_36 ( sizeof( * V_30 ) , V_46 ) ;
if ( ! V_30 ) {
F_37 ( V_47 L_2 ,
V_14 , V_45 -> type ) ;
return;
}
V_30 -> V_8 . V_48 . V_49 = V_50 ;
V_30 -> V_8 . V_51 . V_52 = V_45 -> type ;
V_30 -> V_8 . V_23 = & V_53 ;
V_30 -> V_3 = V_45 ;
if ( F_38 ( & V_30 -> V_8 ) != 0 ) {
F_37 ( V_54 L_3 ,
V_14 , V_45 -> type ) ;
F_39 ( V_30 ) ;
}
}
static void F_40 ( void )
{
unsigned int V_9 ;
struct V_2 * V_45 ;
for ( V_9 = 0 ; V_9 < V_55 ; V_9 += F_4 ( V_45 ) ) {
V_45 = V_56 + V_9 ;
if ( V_45 -> type == 0 )
break;
F_35 ( V_45 , V_9 ) ;
}
}
static int F_41 ( struct V_52 * V_48 , void * V_57 )
{
struct V_7 * V_8 = F_42 ( V_48 ) ;
struct V_29 * V_30 = F_6 ( V_8 ) ;
return V_30 -> V_3 == V_57 ;
}
static void F_43 ( struct V_58 * V_59 )
{
unsigned int V_9 ;
struct V_2 * V_45 ;
struct V_52 * V_48 ;
for ( V_9 = 0 ; V_9 < V_55 ; V_9 += F_4 ( V_45 ) ) {
V_45 = V_56 + V_9 ;
if ( V_45 -> type == 0 )
break;
V_48 = F_44 ( V_50 , V_45 , F_41 ) ;
if ( V_48 ) {
F_45 ( V_48 ) ;
continue;
}
F_37 ( V_60 L_4 , V_45 ) ;
F_35 ( V_45 , V_9 ) ;
}
}
static void F_46 ( struct V_61 V_61 ,
unsigned int V_62 , unsigned long V_63 )
{
struct V_20 * V_21 ;
T_2 V_64 ;
if ( ( V_61 . V_65 & 0xff00 ) != V_66 )
return;
F_47 ( V_67 ) ;
V_21 = (struct V_20 * ) ( V_63 & ~ 1UL ) ;
V_64 = V_62 & V_68 ;
switch ( V_64 ) {
case V_69 :
{
struct V_70 * V_71 ;
V_71 = F_48 ( V_21 -> V_8 -> V_48 . V_72 ,
struct V_70 , V_72 ) ;
if ( V_71 -> V_73 )
V_71 -> V_73 ( V_21 -> V_8 ) ;
break;
}
case V_74 :
F_49 ( & V_75 ) ;
break;
case V_76 :
default:
F_50 ( 0 , V_21 ) ;
break;
}
}
static int T_4 F_51 ( unsigned long V_77 )
{
int V_78 = - V_79 ;
asm volatile(
"0: lura 0,%1\n"
"1: xgr %0,%0\n"
"2:\n"
EX_TABLE(0b,2b)
EX_TABLE(1b,2b)
: "+d" (ret)
: "a" (addr)
: "0", "cc");
return V_78 ;
}
static int T_4 F_52 ( void )
{
int V_22 ;
unsigned long V_80 = F_53 () * F_54 () ;
if ( ! V_81 )
return - V_82 ;
if ( F_51 ( V_80 ) < 0 )
return - V_82 ;
V_22 = F_23 ( V_80 , V_55 ) ;
if ( V_22 )
return V_22 ;
V_56 = ( void * ) V_80 ;
V_50 = F_55 ( L_5 ) ;
if ( F_32 ( V_50 ) ) {
V_22 = F_33 ( V_50 ) ;
F_37 ( V_54 L_6 ) ;
F_26 ( V_80 , V_55 ) ;
return V_22 ;
}
F_56 ( & V_75 , F_43 ) ;
F_57 ( V_83 ) ;
F_58 ( V_84 , F_46 ) ;
F_40 () ;
return 0 ;
}
static T_4 int F_59 ( T_2 V_85 , const char * V_15 , int V_86 )
{
char V_87 [ 17 ] ;
unsigned int V_16 = V_86 ;
if ( V_16 > sizeof( V_87 ) - 1 )
V_16 = sizeof( V_87 ) - 1 ;
V_87 [ V_16 ] = '\0' ;
memcpy ( V_87 , V_15 , V_16 ) ;
F_17 ( V_25 , F_60 ( V_87 ) ) ;
return V_16 ;
}
static int T_4 F_61 ( void )
{
if ( F_62 () || F_63 () )
return - V_82 ;
return F_64 ( F_59 ) ;
}
