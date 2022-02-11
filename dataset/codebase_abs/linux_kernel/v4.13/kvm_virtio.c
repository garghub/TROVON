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
T_3 V_10 = 0 ;
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
T_1 * V_11 = F_2 ( V_3 ) ;
for ( V_9 = 0 ; V_9 < F_7 ( V_3 -> V_5 * 8 , 32 ) ; V_9 ++ )
if ( V_11 [ V_9 / 8 ] & ( 1 << ( V_9 % 8 ) ) )
V_10 |= ( 1 << V_9 ) ;
return V_10 ;
}
static int F_8 ( struct V_7 * V_8 )
{
unsigned int V_9 , V_12 ;
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
T_1 * V_13 = F_2 ( V_3 ) + V_3 -> V_5 ;
F_9 ( V_8 ) ;
F_10 ( ( T_3 ) V_8 -> V_10 != V_8 -> V_10 ) ;
memset ( V_13 , 0 , V_3 -> V_5 ) ;
V_12 = F_11 ( unsigned , V_3 -> V_5 , sizeof( V_8 -> V_10 ) ) * 8 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
if ( F_12 ( V_8 , V_9 ) )
V_13 [ V_9 / 8 ] |= ( 1 << ( V_9 % 8 ) ) ;
}
return 0 ;
}
static void F_13 ( struct V_7 * V_8 , unsigned int V_14 ,
void * V_15 , unsigned V_16 )
{
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
F_10 ( V_14 + V_16 > V_3 -> V_6 ) ;
memcpy ( V_15 , F_3 ( V_3 ) + V_14 , V_16 ) ;
}
static void F_14 ( struct V_7 * V_8 , unsigned int V_14 ,
const void * V_15 , unsigned V_16 )
{
struct V_2 * V_3 = F_6 ( V_8 ) -> V_3 ;
F_10 ( V_14 + V_16 > V_3 -> V_6 ) ;
memcpy ( F_3 ( V_3 ) + V_14 , V_15 , V_16 ) ;
}
static T_1 F_15 ( struct V_7 * V_8 )
{
return F_6 ( V_8 ) -> V_3 -> V_17 ;
}
static void F_16 ( struct V_7 * V_8 , T_1 V_17 )
{
F_10 ( ! V_17 ) ;
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
const char * V_28 , bool V_29 )
{
struct V_30 * V_31 = F_6 ( V_8 ) ;
struct V_1 * V_23 ;
struct V_20 * V_21 ;
int V_32 ;
if ( V_27 >= V_31 -> V_3 -> V_4 )
return F_22 ( - V_33 ) ;
if ( ! V_28 )
return NULL ;
V_23 = F_1 ( V_31 -> V_3 ) + V_27 ;
V_32 = F_23 ( V_23 -> V_26 ,
F_24 ( V_23 -> V_34 ,
V_35 ) ) ;
if ( V_32 )
goto V_36;
V_21 = F_25 ( V_27 , V_23 -> V_34 , V_35 ,
V_8 , true , V_29 , ( void * ) V_23 -> V_26 ,
F_19 , F_21 , V_28 ) ;
if ( ! V_21 ) {
V_32 = - V_37 ;
goto V_38;
}
V_23 -> V_39 = ( T_2 ) V_21 ;
V_21 -> V_24 = V_23 ;
return V_21 ;
V_38:
F_26 ( V_23 -> V_26 ,
F_24 ( V_23 -> V_34 ,
V_35 ) ) ;
V_36:
return F_22 ( V_32 ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_23 = V_21 -> V_24 ;
F_28 ( V_21 ) ;
F_26 ( V_23 -> V_26 ,
F_24 ( V_23 -> V_34 ,
V_35 ) ) ;
}
static void F_29 ( struct V_7 * V_8 )
{
struct V_20 * V_21 , * V_40 ;
F_30 (vq, n, &vdev->vqs, list)
F_27 ( V_21 ) ;
}
static int F_31 ( struct V_7 * V_8 , unsigned V_41 ,
struct V_20 * V_42 [] ,
T_4 * V_43 [] ,
const char * const V_44 [] ,
const bool * V_29 ,
struct V_45 * V_3 )
{
struct V_30 * V_31 = F_6 ( V_8 ) ;
int V_9 ;
if ( V_41 > V_31 -> V_3 -> V_4 )
return - V_33 ;
for ( V_9 = 0 ; V_9 < V_41 ; ++ V_9 ) {
V_42 [ V_9 ] = F_20 ( V_8 , V_9 , V_43 [ V_9 ] , V_44 [ V_9 ] ,
V_29 ? V_29 [ V_9 ] : false ) ;
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
static void F_35 ( struct V_2 * V_46 , unsigned int V_14 )
{
struct V_30 * V_31 ;
V_31 = F_36 ( sizeof( * V_31 ) , V_47 ) ;
if ( ! V_31 ) {
F_37 ( V_48 L_2 ,
V_14 , V_46 -> type ) ;
return;
}
V_31 -> V_8 . V_49 . V_50 = V_51 ;
V_31 -> V_8 . V_52 . V_53 = V_46 -> type ;
V_31 -> V_8 . V_23 = & V_54 ;
V_31 -> V_3 = V_46 ;
if ( F_38 ( & V_31 -> V_8 ) != 0 ) {
F_37 ( V_55 L_3 ,
V_14 , V_46 -> type ) ;
F_39 ( V_31 ) ;
}
}
static void F_40 ( void )
{
unsigned int V_9 ;
struct V_2 * V_46 ;
for ( V_9 = 0 ; V_9 < V_56 ; V_9 += F_4 ( V_46 ) ) {
V_46 = V_57 + V_9 ;
if ( V_46 -> type == 0 )
break;
F_35 ( V_46 , V_9 ) ;
}
}
static int F_41 ( struct V_53 * V_49 , void * V_58 )
{
struct V_7 * V_8 = F_42 ( V_49 ) ;
struct V_30 * V_31 = F_6 ( V_8 ) ;
return V_31 -> V_3 == V_58 ;
}
static void F_43 ( struct V_59 * V_60 )
{
unsigned int V_9 ;
struct V_2 * V_46 ;
struct V_53 * V_49 ;
for ( V_9 = 0 ; V_9 < V_56 ; V_9 += F_4 ( V_46 ) ) {
V_46 = V_57 + V_9 ;
if ( V_46 -> type == 0 )
break;
V_49 = F_44 ( V_51 , V_46 , F_41 ) ;
if ( V_49 ) {
F_45 ( V_49 ) ;
continue;
}
F_37 ( V_61 L_4 , V_46 ) ;
F_35 ( V_46 , V_9 ) ;
}
}
static void F_46 ( struct V_62 V_62 ,
unsigned int V_63 , unsigned long V_64 )
{
struct V_20 * V_21 ;
T_3 V_65 ;
if ( ( V_62 . V_66 & 0xff00 ) != V_67 )
return;
F_47 ( V_68 ) ;
V_21 = (struct V_20 * ) ( V_64 & ~ 1UL ) ;
V_65 = V_63 & V_69 ;
switch ( V_65 ) {
case V_70 :
F_48 ( V_21 -> V_8 ) ;
break;
case V_71 :
F_49 ( & V_72 ) ;
break;
case V_73 :
default:
F_50 ( 0 , V_21 ) ;
break;
}
}
static int T_5 F_51 ( unsigned long V_74 )
{
int V_75 = - V_76 ;
asm volatile(
"0: lura 0,%1\n"
"1: xgr %0,%0\n"
"2:\n"
EX_TABLE(0b,2b)
EX_TABLE(1b,2b)
: "+d" (ret)
: "a" (addr)
: "0", "cc");
return V_75 ;
}
static int T_5 F_52 ( void )
{
int V_22 ;
unsigned long V_77 = V_78 . V_79 * V_78 . V_80 ;
if ( ! V_81 )
return - V_82 ;
if ( F_51 ( V_77 ) < 0 )
return - V_82 ;
F_53 ( L_5 ) ;
V_22 = F_23 ( V_77 , V_56 ) ;
if ( V_22 )
return V_22 ;
V_57 = ( void * ) V_77 ;
V_51 = F_54 ( L_6 ) ;
if ( F_32 ( V_51 ) ) {
V_22 = F_33 ( V_51 ) ;
F_37 ( V_55 L_7 ) ;
F_26 ( V_77 , V_56 ) ;
return V_22 ;
}
F_55 ( & V_72 , F_43 ) ;
F_56 ( V_83 ) ;
F_57 ( V_84 , F_46 ) ;
F_40 () ;
return 0 ;
}
static int F_58 ( T_3 V_85 , const char * V_15 , int V_86 )
{
char V_87 [ 17 ] ;
unsigned int V_16 = V_86 ;
if ( V_16 > sizeof( V_87 ) - 1 )
V_16 = sizeof( V_87 ) - 1 ;
V_87 [ V_16 ] = '\0' ;
memcpy ( V_87 , V_15 , V_16 ) ;
F_17 ( V_25 , F_59 ( V_87 ) ) ;
return V_16 ;
}
static int T_5 F_60 ( void )
{
if ( V_78 . V_88 || V_78 . V_89 )
return - V_82 ;
return F_61 ( F_58 ) ;
}
