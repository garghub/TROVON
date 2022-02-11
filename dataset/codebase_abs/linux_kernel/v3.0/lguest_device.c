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
unsigned int V_15 , V_18 ;
struct V_8 * V_9 = F_10 ( V_14 ) -> V_9 ;
T_1 * V_19 = F_6 ( V_9 ) + V_9 -> V_11 ;
F_13 ( V_14 ) ;
memset ( V_19 , 0 , V_9 -> V_11 ) ;
V_18 = F_14 ( unsigned , V_9 -> V_11 , sizeof( V_14 -> V_16 ) ) * 8 ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ ) {
if ( F_15 ( V_15 , V_14 -> V_16 ) )
V_19 [ V_15 / 8 ] |= ( 1 << ( V_15 % 8 ) ) ;
}
}
static void F_16 ( struct V_13 * V_14 , unsigned int V_20 ,
void * V_21 , unsigned V_22 )
{
struct V_8 * V_9 = F_10 ( V_14 ) -> V_9 ;
F_17 ( V_20 + V_22 > V_9 -> V_12 ) ;
memcpy ( V_21 , F_7 ( V_9 ) + V_20 , V_22 ) ;
}
static void F_18 ( struct V_13 * V_14 , unsigned int V_20 ,
const void * V_21 , unsigned V_22 )
{
struct V_8 * V_9 = F_10 ( V_14 ) -> V_9 ;
F_17 ( V_20 + V_22 > V_9 -> V_12 ) ;
memcpy ( F_7 ( V_9 ) + V_20 , V_21 , V_22 ) ;
}
static T_1 F_19 ( struct V_13 * V_14 )
{
return F_10 ( V_14 ) -> V_9 -> V_23 ;
}
static void F_20 ( struct V_13 * V_14 , T_1 V_23 )
{
unsigned long V_20 = ( void * ) F_10 ( V_14 ) -> V_9 - V_24 ;
F_10 ( V_14 ) -> V_9 -> V_23 = V_23 ;
F_21 ( V_25 , ( V_26 << V_27 ) + V_20 , 0 , 0 , 0 ) ;
}
static void F_22 ( struct V_13 * V_14 , T_1 V_23 )
{
F_17 ( ! V_23 ) ;
F_20 ( V_14 , V_23 ) ;
}
static void F_23 ( struct V_13 * V_14 )
{
F_20 ( V_14 , 0 ) ;
}
static void F_24 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_32 ;
F_21 ( V_25 , V_31 -> V_33 . V_34 << V_27 , 0 , 0 , 0 ) ;
}
static struct V_28 * F_25 ( struct V_13 * V_14 ,
unsigned V_35 ,
void (* F_26)( struct V_28 * V_29 ) ,
const char * V_36 )
{
struct V_37 * V_38 = F_10 ( V_14 ) ;
struct V_30 * V_31 ;
struct V_28 * V_29 ;
int V_39 ;
if ( V_35 >= V_38 -> V_9 -> V_10 )
return F_27 ( - V_40 ) ;
V_31 = F_28 ( sizeof( * V_31 ) , V_41 ) ;
if ( ! V_31 )
return F_27 ( - V_42 ) ;
memcpy ( & V_31 -> V_33 , F_5 ( V_38 -> V_9 ) + V_35 , sizeof( V_31 -> V_33 ) ) ;
F_29 ( L_1 , V_35 ,
( unsigned long ) V_31 -> V_33 . V_34 << V_27 ) ;
V_31 -> V_2 = F_1 ( ( unsigned long ) V_31 -> V_33 . V_34 << V_27 ,
F_30 ( F_31 ( V_31 -> V_33 . V_43 ,
V_44 ) ,
V_4 ) ) ;
if ( ! V_31 -> V_2 ) {
V_39 = - V_42 ;
goto V_45;
}
V_29 = F_32 ( V_31 -> V_33 . V_43 , V_44 ,
V_14 , V_31 -> V_2 , F_24 , F_26 , V_36 ) ;
if ( ! V_29 ) {
V_39 = - V_42 ;
goto V_46;
}
F_33 ( V_31 -> V_33 . V_47 ) ;
V_39 = F_34 ( V_31 -> V_33 . V_47 , V_48 , V_49 ,
F_35 ( & V_14 -> V_50 ) , V_29 ) ;
if ( V_39 )
goto V_51;
V_29 -> V_32 = V_31 ;
return V_29 ;
V_51:
F_36 ( V_29 ) ;
V_46:
F_3 ( V_31 -> V_2 ) ;
V_45:
F_37 ( V_31 ) ;
return F_27 ( V_39 ) ;
}
static void F_38 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = V_29 -> V_32 ;
F_39 ( V_31 -> V_33 . V_47 , V_29 ) ;
F_36 ( V_29 ) ;
F_3 ( V_31 -> V_2 ) ;
F_37 ( V_31 ) ;
}
static void F_40 ( struct V_13 * V_14 )
{
struct V_28 * V_29 , * V_52 ;
F_41 (vq, n, &vdev->vqs, list)
F_38 ( V_29 ) ;
}
static int F_42 ( struct V_13 * V_14 , unsigned V_53 ,
struct V_28 * V_54 [] ,
T_3 * V_55 [] ,
const char * V_56 [] )
{
struct V_37 * V_38 = F_10 ( V_14 ) ;
int V_15 ;
if ( V_53 > V_38 -> V_9 -> V_10 )
return - V_40 ;
for ( V_15 = 0 ; V_15 < V_53 ; ++ V_15 ) {
V_54 [ V_15 ] = F_25 ( V_14 , V_15 , V_55 [ V_15 ] , V_56 [ V_15 ] ) ;
if ( F_43 ( V_54 [ V_15 ] ) )
goto error;
}
return 0 ;
error:
F_40 ( V_14 ) ;
return F_44 ( V_54 [ V_15 ] ) ;
}
static void F_45 ( struct V_8 * V_57 ,
unsigned int V_20 )
{
struct V_37 * V_38 ;
V_38 = F_46 ( sizeof( * V_38 ) , V_41 ) ;
if ( ! V_38 ) {
F_29 ( V_58 L_2 ,
V_20 , V_57 -> type ) ;
return;
}
V_38 -> V_14 . V_50 . V_59 = V_60 ;
V_38 -> V_14 . V_61 . V_62 = V_57 -> type ;
V_38 -> V_14 . V_33 = & V_63 ;
V_38 -> V_9 = V_57 ;
if ( F_47 ( & V_38 -> V_14 ) != 0 ) {
F_29 ( V_64 L_3 ,
V_20 , V_57 -> type ) ;
F_37 ( V_38 ) ;
}
}
static void F_48 ( void )
{
unsigned int V_15 ;
struct V_8 * V_57 ;
for ( V_15 = 0 ; V_15 < V_4 ; V_15 += F_8 ( V_57 ) ) {
V_57 = V_24 + V_15 ;
if ( V_57 -> type == 0 )
break;
F_29 ( L_4 , V_15 , F_8 ( V_57 ) ) ;
F_45 ( V_57 , V_15 ) ;
}
}
static int T_4 F_49 ( void )
{
if ( strcmp ( V_65 . V_36 , L_5 ) != 0 )
return 0 ;
V_60 = F_50 ( L_5 ) ;
if ( F_43 ( V_60 ) )
F_51 ( L_6 ) ;
V_24 = F_1 ( V_26 << V_27 , 1 ) ;
F_48 () ;
return 0 ;
}
