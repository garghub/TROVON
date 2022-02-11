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
static int F_13 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
struct V_11 * V_12 = F_14 ( V_50 ,
struct V_11 , V_53 ) ;
struct V_54 * V_55 =
(struct V_54 * ) V_52 ;
struct V_56 * V_57 =
& V_12 -> V_14 -> V_57 ;
struct V_9 * V_10 =
V_57 -> V_58 [ V_55 -> V_20 -> V_59 ] ;
switch ( V_51 ) {
case V_60 :
F_15 ( V_10 -> V_12 ,
V_10 -> V_15 ) ;
F_16 ( & V_10 -> V_61 , 1 ) ;
break;
case V_62 :
F_17 ( V_10 -> V_12 ,
V_10 -> V_15 ) ;
F_16 ( & V_10 -> V_61 , 0 ) ;
break;
default:
F_18 ( 1 ) ;
return V_63 ;
}
F_19 ( & V_10 -> V_64 ) ;
return V_63 ;
}
static int F_20 ( struct V_9 * V_10 )
{
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_65 * V_30 = V_10 -> V_12 -> V_14 -> V_30 ;
struct V_54 * V_66 ;
int V_67 ;
F_3 ( L_3 ,
V_15 , V_10 ) ;
V_17 -> V_68 = V_10 -> V_28 . V_69 <<
V_70 ;
F_21 ( & V_30 -> V_71 . V_72 ) ;
V_66 = F_22 ( V_30 -> V_20 [ V_15 ] , V_17 ) ;
if ( F_23 ( V_66 ) ) {
F_7 ( L_4 ) ;
V_67 = F_24 ( V_66 ) ;
goto V_73;
}
F_3 ( L_5 , V_15 , V_66 ) ;
V_10 -> V_55 = F_25 ( V_66 ) ;
V_67 = F_26 ( V_10 ) ;
if ( V_67 )
goto V_73;
V_67 = F_27 ( & V_10 -> V_74 ) ;
if ( V_67 )
goto V_73;
V_67 = F_2 ( V_10 ) ;
if ( V_67 )
goto V_73;
if ( V_10 -> V_75 ) {
V_67 = V_10 -> V_75 ( V_10 ) ;
if ( V_67 )
goto V_73;
}
F_3 ( L_6 ,
V_15 , V_10 -> V_55 ) ;
V_67 = 0 ;
V_10 -> V_76 = true ;
V_73:
if ( V_67 )
V_10 -> V_77 = V_67 ;
if ( ! F_28 ( V_66 ) )
F_29 ( V_66 ) ;
F_30 ( & V_30 -> V_71 . V_72 ) ;
return V_67 ;
}
static struct V_9 * F_31 (
struct V_13 * V_14 , int V_15 )
{
struct V_56 * V_57 = & V_14 -> V_57 ;
struct V_9 * V_10 = NULL ;
F_21 ( & V_14 -> V_78 ) ;
if ( ! V_57 -> V_79 ) {
F_3 ( L_7 , V_15 ) ;
goto V_73;
}
if ( V_57 -> V_80 ) {
F_3 ( L_8 , V_15 ) ;
goto V_73;
}
if ( F_32 ( F_33 ( V_57 -> V_79 , V_15 ) ) ) {
F_3 ( L_9 ,
V_15 ) ;
goto V_73;
}
if ( V_57 -> V_58 [ V_15 ] ) {
V_10 = V_57 -> V_58 [ V_15 ] ;
F_3 ( L_10 ,
V_15 , V_10 ) ;
goto V_73;
}
V_57 -> V_58 [ V_15 ] = F_14 (
F_33 ( V_57 -> V_79 , V_15 ) -> V_81 ,
struct V_9 , V_82 ) ;
V_10 = V_57 -> V_58 [ V_15 ] ;
F_3 ( L_11 , V_15 , V_10 ) ;
F_34 ( & V_10 -> V_12 -> V_83 ) ;
V_73:
F_30 ( & V_14 -> V_78 ) ;
return V_10 ;
}
static void F_35 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_12 -> V_14 ;
int V_15 = V_10 -> V_15 ;
struct V_16 * V_17 = V_10 -> V_12 -> V_17 ;
struct V_18 * V_19 =
V_17 -> V_20 [ V_15 ] . V_21 -> V_22 ;
struct V_1 * V_23 ;
struct V_24 * V_24 ;
void * V_84 ;
unsigned long V_26 , V_27 ;
int V_7 ;
F_3 ( L_12 , V_15 ,
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
F_7 ( L_13 ) ;
return;
}
V_24 = F_8 ( V_19 , V_38 + V_7 ) ;
V_84 = F_9 ( V_24 ) ;
F_36 ( V_12 , V_26 , V_84 ,
V_39 ) ;
F_11 ( V_24 ) ;
V_7 ++ ;
}
F_36 ( V_12 , V_10 -> V_48 +
F_37 ( V_85 . V_8 ) , & V_10 -> V_86 , 4 ) ;
V_24 = F_8 ( V_19 , V_40 ) ;
V_23 = F_9 ( V_24 ) ;
#define F_12 ( T_2 ) \
intel_gvt_hypervisor_write_gpa(vgpu, workload->ring_context_gpa + \
RING_CTX_OFF(name.val), &shadow_ring_context->name.val, 4)
F_12 ( V_41 ) ;
F_12 ( V_42 ) ;
#undef F_12
F_36 ( V_12 ,
V_10 -> V_48 +
sizeof( * V_23 ) ,
( void * ) V_23 +
sizeof( * V_23 ) ,
V_39 - sizeof( * V_23 ) ) ;
F_11 ( V_24 ) ;
}
static void F_38 ( struct V_13 * V_14 , int V_15 )
{
struct V_56 * V_57 = & V_14 -> V_57 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_87 ;
F_21 ( & V_14 -> V_78 ) ;
V_10 = V_57 -> V_58 [ V_15 ] ;
V_12 = V_10 -> V_12 ;
if ( ! V_10 -> V_77 && ! V_12 -> V_88 ) {
F_39 ( V_10 -> V_64 ,
! F_40 ( & V_10 -> V_61 ) ) ;
F_35 ( V_10 ) ;
F_41 (event, workload->pending_events,
INTEL_GVT_EVENT_MAX)
F_42 ( V_12 , V_87 ) ;
}
F_3 ( L_14 ,
V_15 , V_10 , V_10 -> V_77 ) ;
V_57 -> V_58 [ V_15 ] = NULL ;
F_43 ( & V_10 -> V_82 ) ;
V_10 -> V_89 ( V_10 ) ;
F_44 ( & V_12 -> V_83 ) ;
F_19 ( & V_57 -> V_90 ) ;
F_30 ( & V_14 -> V_78 ) ;
}
static int F_45 ( void * V_91 )
{
struct V_92 * V_93 = (struct V_92 * ) V_91 ;
struct V_13 * V_14 = V_93 -> V_14 ;
int V_15 = V_93 -> V_15 ;
struct V_56 * V_57 = & V_14 -> V_57 ;
struct V_9 * V_10 = NULL ;
long V_94 ;
int V_67 ;
bool V_95 = F_46 ( V_14 -> V_30 ) ;
F_47 ( V_96 , V_97 ) ;
F_48 ( V_93 ) ;
F_49 ( L_15 , V_15 ) ;
while ( ! F_50 () ) {
F_51 ( & V_57 -> V_98 [ V_15 ] , & V_96 ) ;
do {
V_10 = F_31 ( V_14 , V_15 ) ;
if ( V_10 )
break;
F_52 ( & V_96 , V_99 ,
V_100 ) ;
} while ( ! F_50 () );
F_53 ( & V_57 -> V_98 [ V_15 ] , & V_96 ) ;
if ( ! V_10 )
break;
F_21 ( & V_101 ) ;
F_3 ( L_16 ,
V_10 -> V_15 , V_10 ,
V_10 -> V_12 -> V_59 ) ;
F_54 ( V_14 -> V_30 ) ;
F_3 ( L_17 ,
V_10 -> V_15 , V_10 ) ;
if ( V_95 )
F_55 ( V_14 -> V_30 ,
V_102 ) ;
F_21 ( & V_14 -> V_78 ) ;
V_67 = F_20 ( V_10 ) ;
F_30 ( & V_14 -> V_78 ) ;
if ( V_67 ) {
F_7 ( L_18 ) ;
goto V_89;
}
F_3 ( L_19 ,
V_10 -> V_15 , V_10 ) ;
V_94 = F_56 ( V_10 -> V_55 ,
0 , V_100 ) ;
if ( V_94 < 0 ) {
V_10 -> V_77 = V_94 ;
F_7 ( L_20 ) ;
} else {
V_10 -> V_77 = 0 ;
}
V_89:
F_3 ( L_21 ,
V_10 , V_10 -> V_77 ) ;
if ( V_10 -> V_55 )
F_57 ( F_58 ( & V_10 -> V_55 ) ) ;
F_38 ( V_14 , V_15 ) ;
if ( V_95 )
F_59 ( V_14 -> V_30 ,
V_102 ) ;
F_60 ( V_14 -> V_30 ) ;
F_30 ( & V_101 ) ;
}
return 0 ;
}
void F_61 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_14 ;
struct V_56 * V_57 = & V_14 -> V_57 ;
if ( F_40 ( & V_12 -> V_83 ) ) {
F_3 ( L_22 ) ;
F_39 ( V_57 -> V_90 ,
! F_40 ( & V_12 -> V_83 ) ) ;
}
}
void F_62 ( struct V_13 * V_14 )
{
struct V_56 * V_57 = & V_14 -> V_57 ;
int V_7 ;
F_49 ( L_23 ) ;
for ( V_7 = 0 ; V_7 < V_103 ; V_7 ++ ) {
if ( V_57 -> V_104 [ V_7 ] ) {
F_63 ( V_57 -> V_104 [ V_7 ] ) ;
V_57 -> V_104 [ V_7 ] = NULL ;
}
}
}
int F_64 ( struct V_13 * V_14 )
{
struct V_56 * V_57 = & V_14 -> V_57 ;
struct V_92 * V_105 = NULL ;
int V_67 ;
int V_7 ;
F_49 ( L_24 ) ;
F_65 ( & V_57 -> V_90 ) ;
for ( V_7 = 0 ; V_7 < V_103 ; V_7 ++ ) {
if ( ! F_66 ( V_14 -> V_30 , V_7 ) )
continue;
F_65 ( & V_57 -> V_98 [ V_7 ] ) ;
V_105 = F_67 ( sizeof( * V_105 ) , V_106 ) ;
if ( ! V_105 ) {
V_67 = - V_107 ;
goto V_108;
}
V_105 -> V_14 = V_14 ;
V_105 -> V_15 = V_7 ;
V_57 -> V_104 [ V_7 ] = F_68 ( F_45 , V_105 ,
L_25 , V_7 ) ;
if ( F_23 ( V_57 -> V_104 [ V_7 ] ) ) {
F_7 ( L_26 ) ;
V_67 = F_24 ( V_57 -> V_104 [ V_7 ] ) ;
goto V_108;
}
}
return 0 ;
V_108:
F_62 ( V_14 ) ;
F_48 ( V_105 ) ;
V_105 = NULL ;
return V_67 ;
}
void F_69 ( struct V_11 * V_12 )
{
struct V_65 * V_30 = V_12 -> V_14 -> V_30 ;
F_70 ( & V_12 -> V_17 -> V_109 ,
& V_12 -> V_53 ) ;
F_21 ( & V_30 -> V_71 . V_72 ) ;
V_12 -> V_17 -> V_110 = true ;
F_71 ( V_12 -> V_17 ) ;
F_30 ( & V_30 -> V_71 . V_72 ) ;
}
int F_72 ( struct V_11 * V_12 )
{
F_16 ( & V_12 -> V_83 , 0 ) ;
V_12 -> V_17 = F_73 (
& V_12 -> V_14 -> V_30 -> V_71 ) ;
if ( F_23 ( V_12 -> V_17 ) )
return F_24 ( V_12 -> V_17 ) ;
V_12 -> V_17 -> V_20 [ V_32 ] . V_111 = true ;
V_12 -> V_53 . V_112 =
F_13 ;
F_74 ( & V_12 -> V_17 -> V_109 ,
& V_12 -> V_53 ) ;
return 0 ;
}
