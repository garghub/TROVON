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
static void F_19 ( struct V_20 * V_21 )
{
struct V_1 * V_22 = V_21 -> V_23 ;
F_17 ( V_24 , V_22 -> V_25 ) ;
}
static struct V_20 * F_20 ( struct V_7 * V_8 ,
unsigned V_26 ,
void (* F_21)( struct V_20 * V_21 ) ,
const char * V_27 )
{
struct V_28 * V_29 = F_6 ( V_8 ) ;
struct V_1 * V_22 ;
struct V_20 * V_21 ;
int V_30 ;
if ( V_26 >= V_29 -> V_3 -> V_4 )
return F_22 ( - V_31 ) ;
V_22 = F_1 ( V_29 -> V_3 ) + V_26 ;
V_30 = F_23 ( V_22 -> V_25 ,
F_24 ( V_22 -> V_32 ,
V_33 ) ) ;
if ( V_30 )
goto V_34;
V_21 = F_25 ( V_22 -> V_32 , V_33 ,
V_8 , true , ( void * ) V_22 -> V_25 ,
F_19 , F_21 , V_27 ) ;
if ( ! V_21 ) {
V_30 = - V_35 ;
goto V_36;
}
V_22 -> V_37 = ( V_38 ) V_21 ;
V_21 -> V_23 = V_22 ;
return V_21 ;
V_36:
F_26 ( V_22 -> V_25 ,
F_24 ( V_22 -> V_32 ,
V_33 ) ) ;
V_34:
return F_22 ( V_30 ) ;
}
static void F_27 ( struct V_20 * V_21 )
{
struct V_1 * V_22 = V_21 -> V_23 ;
F_28 ( V_21 ) ;
F_26 ( V_22 -> V_25 ,
F_24 ( V_22 -> V_32 ,
V_33 ) ) ;
}
static void F_29 ( struct V_7 * V_8 )
{
struct V_20 * V_21 , * V_39 ;
F_30 (vq, n, &vdev->vqs, list)
F_27 ( V_21 ) ;
}
static int F_31 ( struct V_7 * V_8 , unsigned V_40 ,
struct V_20 * V_41 [] ,
T_3 * V_42 [] ,
const char * V_43 [] )
{
struct V_28 * V_29 = F_6 ( V_8 ) ;
int V_9 ;
if ( V_40 > V_29 -> V_3 -> V_4 )
return - V_31 ;
for ( V_9 = 0 ; V_9 < V_40 ; ++ V_9 ) {
V_41 [ V_9 ] = F_20 ( V_8 , V_9 , V_42 [ V_9 ] , V_43 [ V_9 ] ) ;
if ( F_32 ( V_41 [ V_9 ] ) )
goto error;
}
return 0 ;
error:
F_29 ( V_8 ) ;
return F_33 ( V_41 [ V_9 ] ) ;
}
static const char * F_34 ( struct V_7 * V_8 )
{
return L_1 ;
}
static void F_35 ( struct V_2 * V_44 , unsigned int V_14 )
{
struct V_28 * V_29 ;
V_29 = F_36 ( sizeof( * V_29 ) , V_45 ) ;
if ( ! V_29 ) {
F_37 ( V_46 L_2 ,
V_14 , V_44 -> type ) ;
return;
}
V_29 -> V_8 . V_47 . V_48 = V_49 ;
V_29 -> V_8 . V_50 . V_51 = V_44 -> type ;
V_29 -> V_8 . V_22 = & V_52 ;
V_29 -> V_3 = V_44 ;
if ( F_38 ( & V_29 -> V_8 ) != 0 ) {
F_37 ( V_53 L_3 ,
V_14 , V_44 -> type ) ;
F_39 ( V_29 ) ;
}
}
static void F_40 ( void )
{
unsigned int V_9 ;
struct V_2 * V_44 ;
for ( V_9 = 0 ; V_9 < V_54 ; V_9 += F_4 ( V_44 ) ) {
V_44 = V_55 + V_9 ;
if ( V_44 -> type == 0 )
break;
F_35 ( V_44 , V_9 ) ;
}
}
static int F_41 ( struct V_51 * V_47 , void * V_56 )
{
struct V_7 * V_8 = F_42 ( V_47 ) ;
struct V_28 * V_29 = F_6 ( V_8 ) ;
return V_29 -> V_3 == V_56 ;
}
static void F_43 ( struct V_57 * V_58 )
{
unsigned int V_9 ;
struct V_2 * V_44 ;
struct V_51 * V_47 ;
for ( V_9 = 0 ; V_9 < V_54 ; V_9 += F_4 ( V_44 ) ) {
V_44 = V_55 + V_9 ;
if ( V_44 -> type == 0 )
break;
V_47 = F_44 ( V_49 , V_44 , F_41 ) ;
if ( V_47 ) {
F_45 ( V_47 ) ;
continue;
}
F_37 ( V_59 L_4 , V_44 ) ;
F_35 ( V_44 , V_9 ) ;
}
}
static void F_46 ( struct V_60 V_60 ,
unsigned int V_61 , unsigned long V_62 )
{
struct V_20 * V_21 ;
T_2 V_63 ;
if ( ( V_60 . V_64 & 0xff00 ) != V_65 )
return;
F_47 ( F_48 () ) . V_66 [ V_67 ] ++ ;
V_21 = (struct V_20 * ) ( V_62 & ~ 1UL ) ;
V_63 = V_61 & V_68 ;
switch ( V_63 ) {
case V_69 :
{
struct V_70 * V_71 ;
V_71 = F_49 ( V_21 -> V_8 -> V_47 . V_72 ,
struct V_70 , V_72 ) ;
if ( V_71 -> V_73 )
V_71 -> V_73 ( V_21 -> V_8 ) ;
break;
}
case V_74 :
F_50 ( & V_75 ) ;
break;
case V_76 :
default:
F_51 ( 0 , V_21 ) ;
break;
}
}
static int T_4 F_52 ( void )
{
int V_77 ;
if ( ! V_78 )
return - V_79 ;
V_49 = F_53 ( L_5 ) ;
if ( F_32 ( V_49 ) ) {
V_77 = F_33 ( V_49 ) ;
F_37 ( V_53 L_6 ) ;
return V_77 ;
}
V_77 = F_23 ( V_80 , V_54 ) ;
if ( V_77 ) {
F_54 ( V_49 ) ;
return V_77 ;
}
V_55 = ( void * ) V_80 ;
F_55 ( & V_75 , F_43 ) ;
F_56 () ;
F_57 ( 0x2603 , F_46 ) ;
F_40 () ;
return 0 ;
}
static T_4 int F_58 ( T_2 V_81 , const char * V_15 , int V_82 )
{
char V_83 [ 17 ] ;
unsigned int V_16 = V_82 ;
if ( V_16 > sizeof( V_83 ) - 1 )
V_16 = sizeof( V_83 ) - 1 ;
V_83 [ V_16 ] = '\0' ;
memcpy ( V_83 , V_15 , V_16 ) ;
F_17 ( V_24 , F_59 ( V_83 ) ) ;
return V_16 ;
}
static int T_4 F_60 ( void )
{
if ( F_61 () || F_62 () )
return - V_79 ;
return F_63 ( F_58 ) ;
}
