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
static void F_23 ( struct V_16 * V_52 ,
struct V_70 * V_20 )
{
struct V_71 * V_72 = & V_52 -> V_20 [ V_20 -> V_58 ] ;
T_3 V_73 = 0 ;
V_73 = V_72 -> V_74 ;
V_73 &= V_75 << 12 ;
V_73 |= V_52 -> V_76 & ( ( 1ULL << 12 ) - 1 ) ;
V_72 -> V_74 = V_73 ;
}
int F_24 ( struct V_9 * V_10 )
{
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_77 * V_30 = V_10 -> V_12 -> V_14 -> V_30 ;
struct V_50 * V_78 ;
struct V_11 * V_12 = V_10 -> V_12 ;
int V_79 ;
F_25 ( & V_30 -> V_80 . V_81 ) ;
if ( V_10 -> V_82 )
return 0 ;
V_17 -> V_76 &= ~ ( 0x3 << V_83 ) ;
V_17 -> V_76 |= V_10 -> V_28 . V_84 <<
V_83 ;
if ( ! F_26 ( V_15 , V_12 -> V_85 ) )
F_23 ( V_17 ,
V_30 -> V_20 [ V_15 ] ) ;
V_78 = F_27 ( V_30 -> V_20 [ V_15 ] , V_17 ) ;
if ( F_28 ( V_78 ) ) {
F_6 ( L_4 ) ;
V_79 = F_29 ( V_78 ) ;
goto V_86;
}
F_3 ( L_5 , V_15 , V_78 ) ;
V_10 -> V_51 = F_30 ( V_78 ) ;
V_79 = F_31 ( V_10 ) ;
if ( V_79 )
goto V_86;
if ( ( V_10 -> V_15 == V_33 ) &&
( V_10 -> V_87 . V_88 . V_89 != 0 ) ) {
V_79 = F_32 ( & V_10 -> V_87 ) ;
if ( V_79 )
goto V_86;
}
V_79 = F_2 ( V_10 ) ;
if ( V_79 )
goto V_86;
V_10 -> V_82 = true ;
V_86:
return V_79 ;
}
static int F_33 ( struct V_9 * V_10 )
{
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_77 * V_30 = V_10 -> V_12 -> V_14 -> V_30 ;
struct V_70 * V_20 = V_30 -> V_20 [ V_15 ] ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_90 * V_91 ;
int V_79 = 0 ;
F_3 ( L_6 ,
V_15 , V_10 ) ;
F_34 ( & V_30 -> V_80 . V_81 ) ;
V_79 = F_24 ( V_10 ) ;
if ( V_79 )
goto V_86;
if ( V_10 -> V_92 ) {
V_79 = V_10 -> V_92 ( V_10 ) ;
if ( V_79 )
goto V_86;
}
V_91 = V_20 -> V_93 ( V_20 , V_17 ) ;
if ( F_28 ( V_91 ) ) {
V_79 = F_29 ( V_91 ) ;
F_6 ( L_7 ) ;
goto V_86;
}
V_86:
if ( V_79 )
V_10 -> V_94 = V_79 ;
if ( ! F_35 ( V_10 -> V_51 ) ) {
F_3 ( L_8 ,
V_15 , V_10 -> V_51 ) ;
F_36 ( V_10 -> V_51 ) ;
V_10 -> V_95 = true ;
}
F_37 ( & V_30 -> V_80 . V_81 ) ;
return V_79 ;
}
static struct V_9 * F_38 (
struct V_13 * V_14 , int V_15 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_9 * V_10 = NULL ;
F_34 ( & V_14 -> V_96 ) ;
if ( ! V_60 -> V_97 ) {
F_3 ( L_9 , V_15 ) ;
goto V_86;
}
if ( V_60 -> V_98 ) {
F_3 ( L_10 , V_15 ) ;
goto V_86;
}
if ( F_39 ( F_40 ( V_60 -> V_97 , V_15 ) ) )
goto V_86;
if ( V_60 -> V_66 [ V_15 ] ) {
V_10 = V_60 -> V_66 [ V_15 ] ;
F_3 ( L_11 ,
V_15 , V_10 ) ;
goto V_86;
}
V_60 -> V_66 [ V_15 ] = F_15 (
F_40 ( V_60 -> V_97 , V_15 ) -> V_99 ,
struct V_9 , V_100 ) ;
V_10 = V_60 -> V_66 [ V_15 ] ;
F_3 ( L_12 , V_15 , V_10 ) ;
F_41 ( & V_10 -> V_12 -> V_101 ) ;
V_86:
F_37 ( & V_14 -> V_96 ) ;
return V_10 ;
}
static void F_42 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_18 * V_19 =
V_17 -> V_20 [ V_15 ] . V_21 -> V_22 ;
struct V_1 * V_23 ;
struct V_24 * V_24 ;
void * V_102 ;
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
V_102 = F_8 ( V_24 ) ;
F_43 ( V_12 , V_26 , V_102 ,
V_40 ) ;
F_10 ( V_24 ) ;
V_7 ++ ;
}
F_43 ( V_12 , V_10 -> V_49 +
F_44 ( V_103 . V_8 ) , & V_10 -> V_104 , 4 ) ;
V_24 = F_7 ( V_19 , V_41 ) ;
V_23 = F_8 ( V_24 ) ;
#define F_11 ( T_2 ) \
intel_gvt_hypervisor_write_gpa(vgpu, workload->ring_context_gpa + \
RING_CTX_OFF(name.val), &shadow_ring_context->name.val, 4)
F_11 ( V_42 ) ;
F_11 ( V_43 ) ;
#undef F_11
F_43 ( V_12 ,
V_10 -> V_49 +
sizeof( * V_23 ) ,
( void * ) V_23 +
sizeof( * V_23 ) ,
V_40 - sizeof( * V_23 ) ) ;
F_10 ( V_24 ) ;
}
static void F_45 ( struct V_13 * V_14 , int V_15 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_105 ;
F_34 ( & V_14 -> V_96 ) ;
V_10 = V_60 -> V_66 [ V_15 ] ;
V_12 = V_10 -> V_12 ;
if ( V_10 -> V_51 ) {
struct V_77 * V_30 =
V_10 -> V_12 -> V_14 -> V_30 ;
struct V_70 * V_20 =
V_30 -> V_20 [ V_10 -> V_15 ] ;
F_46 ( V_10 -> V_69 ,
! F_47 ( & V_10 -> V_67 ) ) ;
if ( F_48 ( V_10 -> V_94 == - V_106 ) ) {
if ( V_10 -> V_51 -> V_107 . error == - V_108 )
V_10 -> V_94 = - V_108 ;
else
V_10 -> V_94 = 0 ;
}
F_49 ( F_50 ( & V_10 -> V_51 ) ) ;
if ( ! V_10 -> V_94 && ! ( V_12 -> V_109 &
F_51 ( V_15 ) ) ) {
F_42 ( V_10 ) ;
F_52 (event, workload->pending_events,
INTEL_GVT_EVENT_MAX)
F_53 ( V_12 , V_105 ) ;
}
F_34 ( & V_30 -> V_80 . V_81 ) ;
V_20 -> V_110 ( V_20 , V_10 -> V_12 -> V_17 ) ;
F_37 ( & V_30 -> V_80 . V_81 ) ;
}
F_3 ( L_15 ,
V_15 , V_10 , V_10 -> V_94 ) ;
V_60 -> V_66 [ V_15 ] = NULL ;
F_54 ( & V_10 -> V_100 ) ;
V_10 -> V_111 ( V_10 ) ;
F_55 ( & V_12 -> V_101 ) ;
F_22 ( & V_60 -> V_112 ) ;
if ( V_14 -> V_60 . V_98 )
F_56 ( V_14 , V_113 ) ;
F_37 ( & V_14 -> V_96 ) ;
}
static int F_57 ( void * V_114 )
{
struct V_115 * V_116 = (struct V_115 * ) V_114 ;
struct V_13 * V_14 = V_116 -> V_14 ;
int V_15 = V_116 -> V_15 ;
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_79 ;
bool V_117 = F_58 ( V_14 -> V_30 )
|| F_59 ( V_14 -> V_30 ) ;
F_60 ( V_118 , V_119 ) ;
F_61 ( V_116 ) ;
F_62 ( L_16 , V_15 ) ;
while ( ! F_63 () ) {
F_64 ( & V_60 -> V_120 [ V_15 ] , & V_118 ) ;
do {
V_10 = F_38 ( V_14 , V_15 ) ;
if ( V_10 )
break;
F_65 ( & V_118 , V_121 ,
V_122 ) ;
} while ( ! F_63 () );
F_66 ( & V_60 -> V_120 [ V_15 ] , & V_118 ) ;
if ( ! V_10 )
break;
F_3 ( L_17 ,
V_10 -> V_15 , V_10 ,
V_10 -> V_12 -> V_58 ) ;
F_67 ( V_14 -> V_30 ) ;
F_3 ( L_18 ,
V_10 -> V_15 , V_10 ) ;
if ( V_117 )
F_68 ( V_14 -> V_30 ,
V_123 ) ;
F_34 ( & V_14 -> V_96 ) ;
V_79 = F_33 ( V_10 ) ;
F_37 ( & V_14 -> V_96 ) ;
if ( V_79 ) {
V_12 = V_10 -> V_12 ;
F_6 ( L_19 ) ;
goto V_111;
}
F_3 ( L_20 ,
V_10 -> V_15 , V_10 ) ;
F_69 ( V_10 -> V_51 , 0 , V_122 ) ;
V_111:
F_3 ( L_21 ,
V_10 , V_10 -> V_94 ) ;
F_45 ( V_14 , V_15 ) ;
if ( V_117 )
F_70 ( V_14 -> V_30 ,
V_123 ) ;
F_71 ( V_14 -> V_30 ) ;
}
return 0 ;
}
void F_72 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_59 * V_60 = & V_14 -> V_60 ;
if ( F_47 ( & V_12 -> V_101 ) ) {
F_3 ( L_22 ) ;
F_46 ( V_60 -> V_112 ,
! F_47 ( & V_12 -> V_101 ) ) ;
}
}
void F_73 ( struct V_13 * V_14 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_70 * V_20 ;
enum V_61 V_7 ;
F_62 ( L_23 ) ;
F_74 (engine, gvt->dev_priv, i) {
F_75 (
& V_20 -> V_124 ,
& V_14 -> V_57 [ V_7 ] ) ;
F_76 ( V_60 -> V_125 [ V_7 ] ) ;
}
}
int F_77 ( struct V_13 * V_14 )
{
struct V_59 * V_60 = & V_14 -> V_60 ;
struct V_115 * V_126 = NULL ;
struct V_70 * V_20 ;
enum V_61 V_7 ;
int V_79 ;
F_62 ( L_24 ) ;
F_78 ( & V_60 -> V_112 ) ;
F_74 (engine, gvt->dev_priv, i) {
F_78 ( & V_60 -> V_120 [ V_7 ] ) ;
V_126 = F_79 ( sizeof( * V_126 ) , V_127 ) ;
if ( ! V_126 ) {
V_79 = - V_128 ;
goto V_129;
}
V_126 -> V_14 = V_14 ;
V_126 -> V_15 = V_7 ;
V_60 -> V_125 [ V_7 ] = F_80 ( F_57 , V_126 ,
L_25 , V_7 ) ;
if ( F_28 ( V_60 -> V_125 [ V_7 ] ) ) {
F_81 ( L_26 ) ;
V_79 = F_29 ( V_60 -> V_125 [ V_7 ] ) ;
goto V_129;
}
V_14 -> V_57 [ V_7 ] . V_130 =
F_14 ;
F_82 ( & V_20 -> V_124 ,
& V_14 -> V_57 [ V_7 ] ) ;
}
return 0 ;
V_129:
F_73 ( V_14 ) ;
F_61 ( V_126 ) ;
V_126 = NULL ;
return V_79 ;
}
void F_83 ( struct V_11 * V_12 )
{
F_84 ( V_12 -> V_17 ) ;
}
int F_85 ( struct V_11 * V_12 )
{
F_20 ( & V_12 -> V_101 , 0 ) ;
V_12 -> V_17 = F_86 (
& V_12 -> V_14 -> V_30 -> V_80 ) ;
if ( F_28 ( V_12 -> V_17 ) )
return F_29 ( V_12 -> V_17 ) ;
V_12 -> V_17 -> V_20 [ V_33 ] . V_131 = true ;
F_87 ( V_12 -> V_85 , V_132 ) ;
return 0 ;
}
