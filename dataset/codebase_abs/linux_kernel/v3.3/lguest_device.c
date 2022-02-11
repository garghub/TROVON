static inline void * F_1 ( unsigned long V_1 , unsigned long V_2 )
{
return ( V_3 void * ) F_2 ( V_1 , V_4 * V_2 ) ;
}
static inline void F_3 ( void * V_5 )
{
F_4 ( ( V_3 void V_6 * ) V_5 ) ;
}
static struct V_7 * F_5 ( const struct V_8 * V_9 )
{
return ( void * ) ( V_9 + 1 ) ;
}
static T_1 * F_6 ( const struct V_8 * V_9 )
{
return ( void * ) ( F_5 ( V_9 ) + V_9 -> V_10 ) ;
}
static T_1 * F_7 ( const struct V_8 * V_9 )
{
return F_6 ( V_9 ) + V_9 -> V_11 * 2 ;
}
static unsigned F_8 ( const struct V_8 * V_9 )
{
return sizeof( * V_9 )
+ V_9 -> V_10 * sizeof( struct V_7 )
+ V_9 -> V_11 * 2
+ V_9 -> V_12 ;
}
static T_2 F_9 ( struct V_13 * V_14 )
{
unsigned int V_15 ;
T_2 V_16 = 0 ;
struct V_8 * V_9 = F_10 ( V_14 ) -> V_9 ;
T_1 * V_17 = F_6 ( V_9 ) ;
for ( V_15 = 0 ; V_15 < F_11 ( V_9 -> V_11 * 8 , 32 ) ; V_15 ++ )
if ( V_17 [ V_15 / 8 ] & ( 1 << ( V_15 % 8 ) ) )
V_16 |= ( 1 << V_15 ) ;
return V_16 ;
}
static void F_12 ( struct V_13 * V_14 )
{
unsigned long V_18 = ( void * ) F_10 ( V_14 ) -> V_9 - V_19 ;
F_13 ( V_20 , ( V_21 << V_22 ) + V_18 , 0 , 0 , 0 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
unsigned int V_15 , V_23 ;
struct V_8 * V_9 = F_10 ( V_14 ) -> V_9 ;
T_1 * V_24 = F_6 ( V_9 ) + V_9 -> V_11 ;
F_15 ( V_14 ) ;
memset ( V_24 , 0 , V_9 -> V_11 ) ;
V_23 = F_16 ( unsigned , V_9 -> V_11 , sizeof( V_14 -> V_16 ) ) * 8 ;
for ( V_15 = 0 ; V_15 < V_23 ; V_15 ++ ) {
if ( F_17 ( V_15 , V_14 -> V_16 ) )
V_24 [ V_15 / 8 ] |= ( 1 << ( V_15 % 8 ) ) ;
}
F_12 ( V_14 ) ;
}
static void F_18 ( struct V_13 * V_14 , unsigned int V_18 ,
void * V_25 , unsigned V_26 )
{
struct V_8 * V_9 = F_10 ( V_14 ) -> V_9 ;
F_19 ( V_18 + V_26 > V_9 -> V_12 ) ;
memcpy ( V_25 , F_7 ( V_9 ) + V_18 , V_26 ) ;
}
static void F_20 ( struct V_13 * V_14 , unsigned int V_18 ,
const void * V_25 , unsigned V_26 )
{
struct V_8 * V_9 = F_10 ( V_14 ) -> V_9 ;
F_19 ( V_18 + V_26 > V_9 -> V_12 ) ;
memcpy ( F_7 ( V_9 ) + V_18 , V_25 , V_26 ) ;
}
static T_1 F_21 ( struct V_13 * V_14 )
{
return F_10 ( V_14 ) -> V_9 -> V_27 ;
}
static void F_22 ( struct V_13 * V_14 , T_1 V_27 )
{
F_19 ( ! V_27 ) ;
F_10 ( V_14 ) -> V_9 -> V_27 = V_27 ;
if ( V_27 & V_28 )
F_12 ( V_14 ) ;
}
static void F_23 ( struct V_13 * V_14 )
{
F_10 ( V_14 ) -> V_9 -> V_27 = 0 ;
F_12 ( V_14 ) ;
}
static void F_24 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
F_13 ( V_20 , V_32 -> V_34 . V_35 << V_22 , 0 , 0 , 0 ) ;
}
static struct V_29 * F_25 ( struct V_13 * V_14 ,
unsigned V_36 ,
void (* F_26)( struct V_29 * V_30 ) ,
const char * V_37 )
{
struct V_38 * V_39 = F_10 ( V_14 ) ;
struct V_31 * V_32 ;
struct V_29 * V_30 ;
int V_40 ;
if ( V_36 >= V_39 -> V_9 -> V_10 )
return F_27 ( - V_41 ) ;
V_32 = F_28 ( sizeof( * V_32 ) , V_42 ) ;
if ( ! V_32 )
return F_27 ( - V_43 ) ;
memcpy ( & V_32 -> V_34 , F_5 ( V_39 -> V_9 ) + V_36 , sizeof( V_32 -> V_34 ) ) ;
F_29 ( L_1 , V_36 ,
( unsigned long ) V_32 -> V_34 . V_35 << V_22 ) ;
V_32 -> V_2 = F_1 ( ( unsigned long ) V_32 -> V_34 . V_35 << V_22 ,
F_30 ( F_31 ( V_32 -> V_34 . V_44 ,
V_45 ) ,
V_4 ) ) ;
if ( ! V_32 -> V_2 ) {
V_40 = - V_43 ;
goto V_46;
}
V_30 = F_32 ( V_32 -> V_34 . V_44 , V_45 , V_14 ,
true , V_32 -> V_2 , F_24 , F_26 , V_37 ) ;
if ( ! V_30 ) {
V_40 = - V_43 ;
goto V_47;
}
V_40 = F_33 ( V_32 -> V_34 . V_48 ) ;
if ( V_40 )
goto V_49;
V_40 = F_34 ( V_32 -> V_34 . V_48 , V_50 , V_51 ,
F_35 ( & V_14 -> V_52 ) , V_30 ) ;
if ( V_40 )
goto V_53;
V_30 -> V_33 = V_32 ;
return V_30 ;
V_53:
F_36 ( V_32 -> V_34 . V_48 ) ;
V_49:
F_37 ( V_30 ) ;
V_47:
F_3 ( V_32 -> V_2 ) ;
V_46:
F_38 ( V_32 ) ;
return F_27 ( V_40 ) ;
}
static void F_39 ( struct V_29 * V_30 )
{
struct V_31 * V_32 = V_30 -> V_33 ;
F_40 ( V_32 -> V_34 . V_48 , V_30 ) ;
F_37 ( V_30 ) ;
F_3 ( V_32 -> V_2 ) ;
F_38 ( V_32 ) ;
}
static void F_41 ( struct V_13 * V_14 )
{
struct V_29 * V_30 , * V_54 ;
F_42 (vq, n, &vdev->vqs, list)
F_39 ( V_30 ) ;
}
static int F_43 ( struct V_13 * V_14 , unsigned V_55 ,
struct V_29 * V_56 [] ,
T_3 * V_57 [] ,
const char * V_58 [] )
{
struct V_38 * V_39 = F_10 ( V_14 ) ;
int V_15 ;
if ( V_55 > V_39 -> V_9 -> V_10 )
return - V_41 ;
for ( V_15 = 0 ; V_15 < V_55 ; ++ V_15 ) {
V_56 [ V_15 ] = F_25 ( V_14 , V_15 , V_57 [ V_15 ] , V_58 [ V_15 ] ) ;
if ( F_44 ( V_56 [ V_15 ] ) )
goto error;
}
return 0 ;
error:
F_41 ( V_14 ) ;
return F_45 ( V_56 [ V_15 ] ) ;
}
static const char * F_46 ( struct V_13 * V_14 )
{
return L_2 ;
}
static void F_47 ( struct V_8 * V_59 ,
unsigned int V_18 )
{
struct V_38 * V_39 ;
V_39 = F_48 ( sizeof( * V_39 ) , V_42 ) ;
if ( ! V_39 ) {
F_29 ( V_60 L_3 ,
V_18 , V_59 -> type ) ;
return;
}
V_39 -> V_14 . V_52 . V_61 = V_62 ;
V_39 -> V_14 . V_63 . V_64 = V_59 -> type ;
V_39 -> V_14 . V_34 = & V_65 ;
V_39 -> V_9 = V_59 ;
if ( F_49 ( & V_39 -> V_14 ) != 0 ) {
F_29 ( V_66 L_4 ,
V_18 , V_59 -> type ) ;
F_38 ( V_39 ) ;
}
}
static void F_50 ( void )
{
unsigned int V_15 ;
struct V_8 * V_59 ;
for ( V_15 = 0 ; V_15 < V_4 ; V_15 += F_8 ( V_59 ) ) {
V_59 = V_19 + V_15 ;
if ( V_59 -> type == 0 )
break;
F_29 ( L_5 , V_15 , F_8 ( V_59 ) ) ;
F_47 ( V_59 , V_15 ) ;
}
}
static int T_4 F_51 ( void )
{
if ( strcmp ( V_67 . V_37 , L_6 ) != 0 )
return 0 ;
V_62 = F_52 ( L_6 ) ;
if ( F_44 ( V_62 ) )
F_53 ( L_7 ) ;
V_19 = F_1 ( V_21 << V_22 , 1 ) ;
F_50 () ;
return 0 ;
}
