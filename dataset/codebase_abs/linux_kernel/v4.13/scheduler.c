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
V_27 = V_14 -> V_30 -> V_20 [ V_15 ] -> V_31 ;
V_27 = V_27 >> V_32 ;
if ( F_4 ( V_14 -> V_30 ) && V_15 == V_33 )
V_27 = 19 ;
V_7 = 2 ;
while ( V_7 < V_27 ) {
V_26 = F_5 ( V_12 -> V_34 . V_35 ,
( T_1 ) ( ( V_10 -> V_28 . V_29 + V_7 ) <<
V_36 ) ) ;
if ( V_26 == V_37 ) {
F_6 ( L_2 ) ;
return - V_38 ;
}
V_24 = F_7 ( V_19 , V_39 + V_7 ) ;
V_25 = F_8 ( V_24 ) ;
F_9 ( V_12 , V_26 , V_25 ,
V_40 ) ;
F_10 ( V_24 ) ;
V_7 ++ ;
}
V_24 = F_7 ( V_19 , V_41 ) ;
V_23 = F_8 ( V_24 ) ;
#define F_11 ( T_2 ) \
intel_gvt_hypervisor_read_gpa(vgpu, workload->ring_context_gpa \
+ RING_CTX_OFF(name.val), &shadow_ring_context->name.val, 4)
F_11 ( V_42 ) ;
F_11 ( V_43 ) ;
if ( V_15 == V_33 ) {
F_11 ( V_44 ) ;
F_11 ( V_45 ) ;
F_11 ( V_46 ) ;
}
#undef F_11
F_1 ( V_23 ,
V_10 -> V_47 -> V_48 ) ;
F_9 ( V_12 ,
V_10 -> V_49 +
sizeof( * V_23 ) ,
( void * ) V_23 +
sizeof( * V_23 ) ,
V_40 - sizeof( * V_23 ) ) ;
F_10 ( V_24 ) ;
return 0 ;
}
static inline bool F_12 ( struct V_50 * V_51 )
{
return F_13 ( V_51 -> V_52 ) ;
}
static int F_14 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
struct V_50 * V_51 = (struct V_50 * ) V_56 ;
struct V_13 * V_14 = F_15 ( V_54 , struct V_13 ,
V_57 [ V_51 -> V_20 -> V_58 ] ) ;
struct V_59 * V_60 = & V_14 -> V_60 ;
enum V_61 V_15 = V_51 -> V_20 -> V_58 ;
struct V_9 * V_10 ;
if ( ! F_12 ( V_51 ) ) {
F_16 ( & V_60 -> V_62 ) ;
if ( V_55 == V_63 &&
V_60 -> V_64 [ V_15 ] ) {
F_17 ( V_60 -> V_64 [ V_15 ] ,
NULL , V_15 ) ;
V_60 -> V_64 [ V_15 ] = NULL ;
}
F_18 ( & V_60 -> V_62 ) ;
return V_65 ;
}
V_10 = V_60 -> V_66 [ V_15 ] ;
if ( F_19 ( ! V_10 ) )
return V_65 ;
switch ( V_55 ) {
case V_63 :
F_16 ( & V_60 -> V_62 ) ;
if ( V_10 -> V_12 != V_60 -> V_64 [ V_15 ] ) {
F_17 ( V_60 -> V_64 [ V_15 ] ,
V_10 -> V_12 , V_15 ) ;
V_60 -> V_64 [ V_15 ] = V_10 -> V_12 ;
} else
F_3 ( L_3 ,
V_15 , V_10 -> V_12 -> V_58 ) ;
F_18 ( & V_60 -> V_62 ) ;
F_20 ( & V_10 -> V_67 , 1 ) ;
break;
case V_68 :
F_20 ( & V_10 -> V_67 , 0 ) ;
break;
default:
F_21 ( 1 ) ;
return V_65 ;
}
F_22 ( & V_10 -> V_69 ) ;
return V_65 ;
}
static int F_23 ( struct V_9 * V_10 )
{
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_70 * V_30 = V_10 -> V_12 -> V_14 -> V_30 ;
struct V_71 * V_20 = V_30 -> V_20 [ V_15 ] ;
struct V_50 * V_72 ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_73 * V_74 ;
int V_75 ;
F_3 ( L_4 ,
V_15 , V_10 ) ;
V_17 -> V_76 &= ~ ( 0x3 << V_77 ) ;
V_17 -> V_76 |= V_10 -> V_28 . V_78 <<
V_77 ;
F_24 ( & V_30 -> V_79 . V_80 ) ;
V_74 = V_20 -> V_81 ( V_20 , V_17 ) ;
if ( F_25 ( V_74 ) ) {
V_75 = F_26 ( V_74 ) ;
F_6 ( L_5 ) ;
V_10 -> V_82 = V_75 ;
F_27 ( & V_30 -> V_79 . V_80 ) ;
return V_75 ;
}
V_72 = F_28 ( V_30 -> V_20 [ V_15 ] , V_17 ) ;
if ( F_25 ( V_72 ) ) {
F_6 ( L_6 ) ;
V_75 = F_26 ( V_72 ) ;
goto V_83;
}
F_3 ( L_7 , V_15 , V_72 ) ;
V_10 -> V_51 = F_29 ( V_72 ) ;
V_75 = F_30 ( V_10 ) ;
if ( V_75 )
goto V_83;
if ( ( V_10 -> V_15 == V_33 ) &&
( V_10 -> V_84 . V_85 . V_86 != 0 ) ) {
V_75 = F_31 ( & V_10 -> V_84 ) ;
if ( V_75 )
goto V_83;
}
V_75 = F_2 ( V_10 ) ;
if ( V_75 )
goto V_83;
if ( V_10 -> V_87 ) {
V_75 = V_10 -> V_87 ( V_10 ) ;
if ( V_75 )
goto V_83;
}
F_3 ( L_8 ,
V_15 , V_10 -> V_51 ) ;
V_75 = 0 ;
V_10 -> V_88 = true ;
V_83:
if ( V_75 )
V_10 -> V_82 = V_75 ;
if ( ! F_32 ( V_72 ) )
F_33 ( V_72 ) ;
else
V_20 -> V_89 ( V_20 , V_17 ) ;
F_27 ( & V_30 -> V_79 . V_80 ) ;
return V_75 ;
}
static struct V_9 * F_34 (
struct V_13 * V_14 , int V_15 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_9 * V_10 = NULL ;
F_24 ( & V_14 -> V_90 ) ;
if ( ! V_60 -> V_91 ) {
F_3 ( L_9 , V_15 ) ;
goto V_83;
}
if ( V_60 -> V_92 ) {
F_3 ( L_10 , V_15 ) ;
goto V_83;
}
if ( F_35 ( F_36 ( V_60 -> V_91 , V_15 ) ) )
goto V_83;
if ( V_60 -> V_66 [ V_15 ] ) {
V_10 = V_60 -> V_66 [ V_15 ] ;
F_3 ( L_11 ,
V_15 , V_10 ) ;
goto V_83;
}
V_60 -> V_66 [ V_15 ] = F_15 (
F_36 ( V_60 -> V_91 , V_15 ) -> V_93 ,
struct V_9 , V_94 ) ;
V_10 = V_60 -> V_66 [ V_15 ] ;
F_3 ( L_12 , V_15 , V_10 ) ;
F_37 ( & V_10 -> V_12 -> V_95 ) ;
V_83:
F_27 ( & V_14 -> V_90 ) ;
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
void * V_96 ;
unsigned long V_26 , V_27 ;
int V_7 ;
F_3 ( L_13 , V_15 ,
V_10 -> V_28 . V_29 ) ;
V_27 = V_14 -> V_30 -> V_20 [ V_15 ] -> V_31 ;
V_27 = V_27 >> V_32 ;
if ( F_4 ( V_14 -> V_30 ) && V_15 == V_33 )
V_27 = 19 ;
V_7 = 2 ;
while ( V_7 < V_27 ) {
V_26 = F_5 ( V_12 -> V_34 . V_35 ,
( T_1 ) ( ( V_10 -> V_28 . V_29 + V_7 ) <<
V_36 ) ) ;
if ( V_26 == V_37 ) {
F_6 ( L_14 ) ;
return;
}
V_24 = F_7 ( V_19 , V_39 + V_7 ) ;
V_96 = F_8 ( V_24 ) ;
F_39 ( V_12 , V_26 , V_96 ,
V_40 ) ;
F_10 ( V_24 ) ;
V_7 ++ ;
}
F_39 ( V_12 , V_10 -> V_49 +
F_40 ( V_97 . V_8 ) , & V_10 -> V_98 , 4 ) ;
V_24 = F_7 ( V_19 , V_41 ) ;
V_23 = F_8 ( V_24 ) ;
#define F_11 ( T_2 ) \
intel_gvt_hypervisor_write_gpa(vgpu, workload->ring_context_gpa + \
RING_CTX_OFF(name.val), &shadow_ring_context->name.val, 4)
F_11 ( V_42 ) ;
F_11 ( V_43 ) ;
#undef F_11
F_39 ( V_12 ,
V_10 -> V_49 +
sizeof( * V_23 ) ,
( void * ) V_23 +
sizeof( * V_23 ) ,
V_40 - sizeof( * V_23 ) ) ;
F_10 ( V_24 ) ;
}
static void F_41 ( struct V_13 * V_14 , int V_15 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_99 ;
F_24 ( & V_14 -> V_90 ) ;
V_10 = V_60 -> V_66 [ V_15 ] ;
V_12 = V_10 -> V_12 ;
if ( V_10 -> V_51 ) {
struct V_70 * V_30 =
V_10 -> V_12 -> V_14 -> V_30 ;
struct V_71 * V_20 =
V_30 -> V_20 [ V_10 -> V_15 ] ;
F_42 ( V_10 -> V_69 ,
! F_43 ( & V_10 -> V_67 ) ) ;
if ( F_44 ( V_10 -> V_82 == - V_100 ) ) {
if ( V_10 -> V_51 -> V_101 . error == - V_102 )
V_10 -> V_82 = - V_102 ;
else
V_10 -> V_82 = 0 ;
}
F_45 ( F_46 ( & V_10 -> V_51 ) ) ;
if ( ! V_10 -> V_82 && ! ( V_12 -> V_103 &
F_47 ( V_15 ) ) ) {
F_38 ( V_10 ) ;
F_48 (event, workload->pending_events,
INTEL_GVT_EVENT_MAX)
F_49 ( V_12 , V_99 ) ;
}
F_24 ( & V_30 -> V_79 . V_80 ) ;
V_20 -> V_89 ( V_20 , V_10 -> V_12 -> V_17 ) ;
F_27 ( & V_30 -> V_79 . V_80 ) ;
}
F_3 ( L_15 ,
V_15 , V_10 , V_10 -> V_82 ) ;
V_60 -> V_66 [ V_15 ] = NULL ;
F_50 ( & V_10 -> V_94 ) ;
V_10 -> V_104 ( V_10 ) ;
F_51 ( & V_12 -> V_95 ) ;
F_22 ( & V_60 -> V_105 ) ;
if ( V_14 -> V_60 . V_92 )
F_52 ( V_14 , V_106 ) ;
F_27 ( & V_14 -> V_90 ) ;
}
static int F_53 ( void * V_107 )
{
struct V_108 * V_109 = (struct V_108 * ) V_107 ;
struct V_13 * V_14 = V_109 -> V_14 ;
int V_15 = V_109 -> V_15 ;
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_75 ;
bool V_110 = F_54 ( V_14 -> V_30 )
|| F_55 ( V_14 -> V_30 ) ;
F_56 ( V_111 , V_112 ) ;
F_57 ( V_109 ) ;
F_58 ( L_16 , V_15 ) ;
while ( ! F_59 () ) {
F_60 ( & V_60 -> V_113 [ V_15 ] , & V_111 ) ;
do {
V_10 = F_34 ( V_14 , V_15 ) ;
if ( V_10 )
break;
F_61 ( & V_111 , V_114 ,
V_115 ) ;
} while ( ! F_59 () );
F_62 ( & V_60 -> V_113 [ V_15 ] , & V_111 ) ;
if ( ! V_10 )
break;
F_3 ( L_17 ,
V_10 -> V_15 , V_10 ,
V_10 -> V_12 -> V_58 ) ;
F_63 ( V_14 -> V_30 ) ;
F_3 ( L_18 ,
V_10 -> V_15 , V_10 ) ;
if ( V_110 )
F_64 ( V_14 -> V_30 ,
V_116 ) ;
F_24 ( & V_14 -> V_90 ) ;
V_75 = F_23 ( V_10 ) ;
F_27 ( & V_14 -> V_90 ) ;
if ( V_75 ) {
V_12 = V_10 -> V_12 ;
F_6 ( L_19 ) ;
goto V_104;
}
F_3 ( L_20 ,
V_10 -> V_15 , V_10 ) ;
F_65 ( V_10 -> V_51 , 0 , V_115 ) ;
V_104:
F_3 ( L_21 ,
V_10 , V_10 -> V_82 ) ;
F_41 ( V_14 , V_15 ) ;
if ( V_110 )
F_66 ( V_14 -> V_30 ,
V_116 ) ;
F_67 ( V_14 -> V_30 ) ;
}
return 0 ;
}
void F_68 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_59 * V_60 = & V_14 -> V_60 ;
if ( F_43 ( & V_12 -> V_95 ) ) {
F_3 ( L_22 ) ;
F_42 ( V_60 -> V_105 ,
! F_43 ( & V_12 -> V_95 ) ) ;
}
}
void F_69 ( struct V_13 * V_14 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_71 * V_20 ;
enum V_61 V_7 ;
F_58 ( L_23 ) ;
F_70 (engine, gvt->dev_priv, i) {
F_71 (
& V_20 -> V_117 ,
& V_14 -> V_57 [ V_7 ] ) ;
F_72 ( V_60 -> V_118 [ V_7 ] ) ;
}
}
int F_73 ( struct V_13 * V_14 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_108 * V_119 = NULL ;
struct V_71 * V_20 ;
enum V_61 V_7 ;
int V_75 ;
F_58 ( L_24 ) ;
F_74 ( & V_60 -> V_105 ) ;
F_70 (engine, gvt->dev_priv, i) {
F_74 ( & V_60 -> V_113 [ V_7 ] ) ;
V_119 = F_75 ( sizeof( * V_119 ) , V_120 ) ;
if ( ! V_119 ) {
V_75 = - V_121 ;
goto V_122;
}
V_119 -> V_14 = V_14 ;
V_119 -> V_15 = V_7 ;
V_60 -> V_118 [ V_7 ] = F_76 ( F_53 , V_119 ,
L_25 , V_7 ) ;
if ( F_25 ( V_60 -> V_118 [ V_7 ] ) ) {
F_77 ( L_26 ) ;
V_75 = F_26 ( V_60 -> V_118 [ V_7 ] ) ;
goto V_122;
}
V_14 -> V_57 [ V_7 ] . V_123 =
F_14 ;
F_78 ( & V_20 -> V_117 ,
& V_14 -> V_57 [ V_7 ] ) ;
}
return 0 ;
V_122:
F_69 ( V_14 ) ;
F_57 ( V_119 ) ;
V_119 = NULL ;
return V_75 ;
}
void F_79 ( struct V_11 * V_12 )
{
F_80 ( V_12 -> V_17 ) ;
}
int F_81 ( struct V_11 * V_12 )
{
F_20 ( & V_12 -> V_95 , 0 ) ;
V_12 -> V_17 = F_82 (
& V_12 -> V_14 -> V_30 -> V_79 ) ;
if ( F_25 ( V_12 -> V_17 ) )
return F_26 ( V_12 -> V_17 ) ;
V_12 -> V_17 -> V_20 [ V_33 ] . V_124 = true ;
return 0 ;
}
