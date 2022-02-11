static void F_1 (
struct V_1 * V_2 ,
T_1 V_3 [ 8 ] )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ )
V_5 [ V_7 ] . V_8 = V_3 [ 7 - V_7 ] ;
}
static int F_2 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_18 * V_19 =
V_17 -> V_20 [ V_15 ] . V_21 -> V_22 ;
struct V_1 * V_23 ;
struct V_24 * V_24 ;
void * V_25 ;
unsigned long V_26 , V_27 ;
int V_7 ;
F_3 ( L_1 , V_15 ,
V_10 -> V_28 . V_29 ) ;
V_27 = F_4 (
V_14 -> V_30 -> V_20 [ V_15 ] ) ;
V_27 = V_27 >> V_31 ;
if ( F_5 ( V_14 -> V_30 ) && V_15 == V_32 )
V_27 = 19 ;
V_7 = 2 ;
while ( V_7 < V_27 ) {
V_26 = F_6 ( V_12 -> V_33 . V_34 ,
( T_1 ) ( ( V_10 -> V_28 . V_29 + V_7 ) <<
V_35 ) ) ;
if ( V_26 == V_36 ) {
F_7 ( L_2 ) ;
return - V_37 ;
}
V_24 = F_8 ( V_19 , V_38 + V_7 ) ;
V_25 = F_9 ( V_24 ) ;
F_10 ( V_12 , V_26 , V_25 ,
V_39 ) ;
F_11 ( V_24 ) ;
V_7 ++ ;
}
V_24 = F_8 ( V_19 , V_40 ) ;
V_23 = F_9 ( V_24 ) ;
#define F_12 ( T_2 ) \
intel_gvt_hypervisor_read_gpa(vgpu, workload->ring_context_gpa \
+ RING_CTX_OFF(name.val), &shadow_ring_context->name.val, 4)
F_12 ( V_41 ) ;
F_12 ( V_42 ) ;
if ( V_15 == V_32 ) {
F_12 ( V_43 ) ;
F_12 ( V_44 ) ;
F_12 ( V_45 ) ;
}
#undef F_12
F_1 ( V_23 ,
V_10 -> V_46 -> V_47 ) ;
F_10 ( V_12 ,
V_10 -> V_48 +
sizeof( * V_23 ) ,
( void * ) V_23 +
sizeof( * V_23 ) ,
V_39 - sizeof( * V_23 ) ) ;
F_11 ( V_24 ) ;
return 0 ;
}
static inline bool F_13 ( struct V_49 * V_50 )
{
return F_14 ( V_50 -> V_51 ) ;
}
static int F_15 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_55 )
{
struct V_49 * V_50 = (struct V_49 * ) V_55 ;
struct V_13 * V_14 = F_16 ( V_53 , struct V_13 ,
V_56 [ V_50 -> V_20 -> V_57 ] ) ;
struct V_58 * V_59 = & V_14 -> V_59 ;
struct V_9 * V_10 =
V_59 -> V_60 [ V_50 -> V_20 -> V_57 ] ;
if ( ! F_13 ( V_50 ) || F_17 ( ! V_10 ) )
return V_61 ;
switch ( V_54 ) {
case V_62 :
F_18 ( V_10 -> V_12 ,
V_10 -> V_15 ) ;
F_19 ( & V_10 -> V_63 , 1 ) ;
break;
case V_64 :
F_20 ( V_10 -> V_12 ,
V_10 -> V_15 ) ;
if ( V_10 -> V_65 == - V_66 )
V_10 -> V_65 = 0 ;
F_19 ( & V_10 -> V_63 , 0 ) ;
break;
default:
F_21 ( 1 ) ;
return V_61 ;
}
F_22 ( & V_10 -> V_67 ) ;
return V_61 ;
}
static int F_23 ( struct V_9 * V_10 )
{
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_68 * V_30 = V_10 -> V_12 -> V_14 -> V_30 ;
struct V_69 * V_20 = V_30 -> V_20 [ V_15 ] ;
struct V_49 * V_70 ;
struct V_11 * V_12 = V_10 -> V_12 ;
int V_71 ;
F_3 ( L_3 ,
V_15 , V_10 ) ;
V_17 -> V_72 &= ~ ( 0x3 << V_73 ) ;
V_17 -> V_72 |= V_10 -> V_28 . V_74 <<
V_73 ;
F_24 ( & V_30 -> V_75 . V_76 ) ;
V_71 = V_20 -> V_77 ( V_20 , V_17 ) ;
if ( V_71 ) {
F_7 ( L_4 ) ;
V_10 -> V_65 = V_71 ;
F_25 ( & V_30 -> V_75 . V_76 ) ;
return V_71 ;
}
V_70 = F_26 ( V_30 -> V_20 [ V_15 ] , V_17 ) ;
if ( F_27 ( V_70 ) ) {
F_7 ( L_5 ) ;
V_71 = F_28 ( V_70 ) ;
goto V_78;
}
F_3 ( L_6 , V_15 , V_70 ) ;
V_10 -> V_50 = F_29 ( V_70 ) ;
V_71 = F_30 ( V_10 ) ;
if ( V_71 )
goto V_78;
if ( ( V_10 -> V_15 == V_32 ) &&
( V_10 -> V_79 . V_80 . V_81 != 0 ) ) {
V_71 = F_31 ( & V_10 -> V_79 ) ;
if ( V_71 )
goto V_78;
}
V_71 = F_2 ( V_10 ) ;
if ( V_71 )
goto V_78;
if ( V_10 -> V_82 ) {
V_71 = V_10 -> V_82 ( V_10 ) ;
if ( V_71 )
goto V_78;
}
F_3 ( L_7 ,
V_15 , V_10 -> V_50 ) ;
V_71 = 0 ;
V_10 -> V_83 = true ;
V_78:
if ( V_71 )
V_10 -> V_65 = V_71 ;
if ( ! F_32 ( V_70 ) )
F_33 ( V_70 ) ;
else
V_20 -> V_84 ( V_20 , V_17 ) ;
F_25 ( & V_30 -> V_75 . V_76 ) ;
return V_71 ;
}
static struct V_9 * F_34 (
struct V_13 * V_14 , int V_15 )
{
struct V_58 * V_59 = & V_14 -> V_59 ;
struct V_9 * V_10 = NULL ;
F_24 ( & V_14 -> V_85 ) ;
if ( ! V_59 -> V_86 ) {
F_3 ( L_8 , V_15 ) ;
goto V_78;
}
if ( V_59 -> V_87 ) {
F_3 ( L_9 , V_15 ) ;
goto V_78;
}
if ( F_35 ( F_36 ( V_59 -> V_86 , V_15 ) ) ) {
F_3 ( L_10 ,
V_15 ) ;
goto V_78;
}
if ( V_59 -> V_60 [ V_15 ] ) {
V_10 = V_59 -> V_60 [ V_15 ] ;
F_3 ( L_11 ,
V_15 , V_10 ) ;
goto V_78;
}
V_59 -> V_60 [ V_15 ] = F_16 (
F_36 ( V_59 -> V_86 , V_15 ) -> V_88 ,
struct V_9 , V_89 ) ;
V_10 = V_59 -> V_60 [ V_15 ] ;
F_3 ( L_12 , V_15 , V_10 ) ;
F_37 ( & V_10 -> V_12 -> V_90 ) ;
V_78:
F_25 ( & V_14 -> V_85 ) ;
return V_10 ;
}
static void F_38 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_18 * V_19 =
V_17 -> V_20 [ V_15 ] . V_21 -> V_22 ;
struct V_1 * V_23 ;
struct V_24 * V_24 ;
void * V_91 ;
unsigned long V_26 , V_27 ;
int V_7 ;
F_3 ( L_13 , V_15 ,
V_10 -> V_28 . V_29 ) ;
V_27 = F_4 (
V_14 -> V_30 -> V_20 [ V_15 ] ) ;
V_27 = V_27 >> V_31 ;
if ( F_5 ( V_14 -> V_30 ) && V_15 == V_32 )
V_27 = 19 ;
V_7 = 2 ;
while ( V_7 < V_27 ) {
V_26 = F_6 ( V_12 -> V_33 . V_34 ,
( T_1 ) ( ( V_10 -> V_28 . V_29 + V_7 ) <<
V_35 ) ) ;
if ( V_26 == V_36 ) {
F_7 ( L_14 ) ;
return;
}
V_24 = F_8 ( V_19 , V_38 + V_7 ) ;
V_91 = F_9 ( V_24 ) ;
F_39 ( V_12 , V_26 , V_91 ,
V_39 ) ;
F_11 ( V_24 ) ;
V_7 ++ ;
}
F_39 ( V_12 , V_10 -> V_48 +
F_40 ( V_92 . V_8 ) , & V_10 -> V_93 , 4 ) ;
V_24 = F_8 ( V_19 , V_40 ) ;
V_23 = F_9 ( V_24 ) ;
#define F_12 ( T_2 ) \
intel_gvt_hypervisor_write_gpa(vgpu, workload->ring_context_gpa + \
RING_CTX_OFF(name.val), &shadow_ring_context->name.val, 4)
F_12 ( V_41 ) ;
F_12 ( V_42 ) ;
#undef F_12
F_39 ( V_12 ,
V_10 -> V_48 +
sizeof( * V_23 ) ,
( void * ) V_23 +
sizeof( * V_23 ) ,
V_39 - sizeof( * V_23 ) ) ;
F_11 ( V_24 ) ;
}
static void F_41 ( struct V_13 * V_14 , int V_15 )
{
struct V_58 * V_59 = & V_14 -> V_59 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_94 ;
F_24 ( & V_14 -> V_85 ) ;
V_10 = V_59 -> V_60 [ V_15 ] ;
V_12 = V_10 -> V_12 ;
if ( V_10 -> V_50 ) {
struct V_68 * V_30 =
V_10 -> V_12 -> V_14 -> V_30 ;
struct V_69 * V_20 =
V_30 -> V_20 [ V_10 -> V_15 ] ;
F_42 ( V_10 -> V_67 ,
! F_43 ( & V_10 -> V_63 ) ) ;
F_44 ( F_45 ( & V_10 -> V_50 ) ) ;
if ( ! V_10 -> V_65 && ! V_12 -> V_95 ) {
F_38 ( V_10 ) ;
F_46 (event, workload->pending_events,
INTEL_GVT_EVENT_MAX)
F_47 ( V_12 , V_94 ) ;
}
F_24 ( & V_30 -> V_75 . V_76 ) ;
V_20 -> V_84 ( V_20 , V_10 -> V_12 -> V_17 ) ;
F_25 ( & V_30 -> V_75 . V_76 ) ;
}
F_3 ( L_15 ,
V_15 , V_10 , V_10 -> V_65 ) ;
V_59 -> V_60 [ V_15 ] = NULL ;
F_48 ( & V_10 -> V_89 ) ;
V_10 -> V_96 ( V_10 ) ;
F_49 ( & V_12 -> V_90 ) ;
F_22 ( & V_59 -> V_97 ) ;
F_25 ( & V_14 -> V_85 ) ;
}
static int F_50 ( void * V_98 )
{
struct V_99 * V_100 = (struct V_99 * ) V_98 ;
struct V_13 * V_14 = V_100 -> V_14 ;
int V_15 = V_100 -> V_15 ;
struct V_58 * V_59 = & V_14 -> V_59 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_71 ;
bool V_101 = F_51 ( V_14 -> V_30 ) ;
F_52 ( V_102 , V_103 ) ;
F_53 ( V_100 ) ;
F_54 ( L_16 , V_15 ) ;
while ( ! F_55 () ) {
F_56 ( & V_59 -> V_104 [ V_15 ] , & V_102 ) ;
do {
V_10 = F_34 ( V_14 , V_15 ) ;
if ( V_10 )
break;
F_57 ( & V_102 , V_105 ,
V_106 ) ;
} while ( ! F_55 () );
F_58 ( & V_59 -> V_104 [ V_15 ] , & V_102 ) ;
if ( ! V_10 )
break;
F_24 ( & V_107 ) ;
F_3 ( L_17 ,
V_10 -> V_15 , V_10 ,
V_10 -> V_12 -> V_57 ) ;
F_59 ( V_14 -> V_30 ) ;
F_3 ( L_18 ,
V_10 -> V_15 , V_10 ) ;
if ( V_101 )
F_60 ( V_14 -> V_30 ,
V_108 ) ;
F_24 ( & V_14 -> V_85 ) ;
V_71 = F_23 ( V_10 ) ;
F_25 ( & V_14 -> V_85 ) ;
if ( V_71 ) {
V_12 = V_10 -> V_12 ;
F_7 ( L_19 ) ;
goto V_96;
}
F_3 ( L_20 ,
V_10 -> V_15 , V_10 ) ;
F_61 ( V_10 -> V_50 , 0 , V_106 ) ;
V_96:
F_3 ( L_21 ,
V_10 , V_10 -> V_65 ) ;
F_41 ( V_14 , V_15 ) ;
if ( V_101 )
F_62 ( V_14 -> V_30 ,
V_108 ) ;
F_63 ( V_14 -> V_30 ) ;
F_25 ( & V_107 ) ;
}
return 0 ;
}
void F_64 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_58 * V_59 = & V_14 -> V_59 ;
if ( F_43 ( & V_12 -> V_90 ) ) {
F_3 ( L_22 ) ;
F_42 ( V_59 -> V_97 ,
! F_43 ( & V_12 -> V_90 ) ) ;
}
}
void F_65 ( struct V_13 * V_14 )
{
struct V_58 * V_59 = & V_14 -> V_59 ;
struct V_69 * V_20 ;
enum V_109 V_7 ;
F_54 ( L_23 ) ;
F_66 (engine, gvt->dev_priv, i) {
F_67 (
& V_20 -> V_110 ,
& V_14 -> V_56 [ V_7 ] ) ;
F_68 ( V_59 -> V_111 [ V_7 ] ) ;
}
}
int F_69 ( struct V_13 * V_14 )
{
struct V_58 * V_59 = & V_14 -> V_59 ;
struct V_99 * V_112 = NULL ;
struct V_69 * V_20 ;
enum V_109 V_7 ;
int V_71 ;
F_54 ( L_24 ) ;
F_70 ( & V_59 -> V_97 ) ;
F_66 (engine, gvt->dev_priv, i) {
F_70 ( & V_59 -> V_104 [ V_7 ] ) ;
V_112 = F_71 ( sizeof( * V_112 ) , V_113 ) ;
if ( ! V_112 ) {
V_71 = - V_114 ;
goto V_115;
}
V_112 -> V_14 = V_14 ;
V_112 -> V_15 = V_7 ;
V_59 -> V_111 [ V_7 ] = F_72 ( F_50 , V_112 ,
L_25 , V_7 ) ;
if ( F_27 ( V_59 -> V_111 [ V_7 ] ) ) {
F_73 ( L_26 ) ;
V_71 = F_28 ( V_59 -> V_111 [ V_7 ] ) ;
goto V_115;
}
V_14 -> V_56 [ V_7 ] . V_116 =
F_15 ;
F_74 ( & V_20 -> V_110 ,
& V_14 -> V_56 [ V_7 ] ) ;
}
return 0 ;
V_115:
F_65 ( V_14 ) ;
F_53 ( V_112 ) ;
V_112 = NULL ;
return V_71 ;
}
void F_75 ( struct V_11 * V_12 )
{
F_76 ( V_12 -> V_17 ) ;
}
int F_77 ( struct V_11 * V_12 )
{
F_19 ( & V_12 -> V_90 , 0 ) ;
V_12 -> V_17 = F_78 (
& V_12 -> V_14 -> V_30 -> V_75 ) ;
if ( F_27 ( V_12 -> V_17 ) )
return F_28 ( V_12 -> V_17 ) ;
V_12 -> V_17 -> V_20 [ V_32 ] . V_117 = true ;
return 0 ;
}
