static void F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_1 ;
struct V_8 * V_9 ;
int V_10 ;
F_2 ( F_3 ( V_2 ) ) ;
F_2 ( ! F_4 ( V_2 ) ) ;
if ( V_3 == 0 ) {
V_6 = F_5 ( & V_10 ) ;
if ( ! F_6 ( V_6 ) ) {
V_4 = V_2 -> V_11 -> V_12 ;
V_9 = F_7 ( V_4 ) -> V_13 ;
if ( V_9 != NULL ) {
V_1 = F_8 ( V_2 , V_9 ) ;
if ( V_1 != NULL ) {
F_9 ( & V_1 -> V_14 ,
L_1 , V_2 ) ;
F_10 ( V_6 , V_1 ) ;
F_11 ( & V_1 -> V_14 ,
L_1 , V_2 ) ;
F_12 ( V_6 , V_1 ) ;
}
} else
F_2 ( V_2 -> V_15 == 0 ) ;
F_13 ( V_6 , & V_10 ) ;
}
}
}
static int F_14 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_17 V_18 ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_7 * V_1 ;
struct V_19 * V_11 ;
int V_20 ;
F_2 ( F_3 ( V_2 ) ) ;
if ( F_4 ( V_2 ) || F_15 ( V_2 ) )
return 0 ;
V_11 = V_2 -> V_11 ;
if ( V_11 == NULL )
return 1 ;
V_9 = F_7 ( V_11 -> V_12 ) -> V_13 ;
if ( V_9 == NULL )
return 1 ;
if ( F_16 ( V_2 ) > 3 )
return 0 ;
V_6 = F_17 ( & V_18 ) ;
if ( F_6 ( V_6 ) )
return 0 ;
V_1 = F_8 ( V_2 , V_9 ) ;
V_20 = V_1 == NULL ;
if ( V_1 != NULL ) {
if ( ! F_18 ( V_1 ) ) {
V_20 = 1 ;
F_10 ( V_6 , V_1 ) ;
}
F_12 ( V_6 , V_1 ) ;
}
F_19 ( & V_18 , V_6 ) ;
return V_20 ;
}
static int F_20 ( struct V_1 * V_2 )
{
#if 0
struct cl_page *page = vvp_vmpage_page_transient(vmpage);
struct vvp_object *obj = cl_inode2vvp(vmpage->mapping->host);
struct vvp_page *cpg;
LASSERT(&obj->co_cl == page->cp_obj);
cpg = cl2vvp_page(cl_page_at(page, &vvp_device_type));
vvp_write_pending(obj, cpg);
#endif
RETURN ( F_21 ( V_2 ) ) ;
}
static inline int F_22 ( int V_21 , unsigned long V_22 ,
T_2 V_23 , struct V_1 * * * V_24 ,
int * V_25 )
{
int V_20 = - V_26 ;
if ( V_23 > V_27 ) {
* V_24 = NULL ;
return - V_28 ;
}
* V_25 = ( V_22 + V_23 + V_29 - 1 ) >> V_30 ;
* V_25 -= V_22 >> V_30 ;
F_23 ( * V_24 , * V_25 * sizeof( * * V_24 ) ) ;
if ( * V_24 ) {
F_24 ( & V_31 -> V_32 -> V_33 ) ;
V_20 = F_25 ( V_31 , V_31 -> V_32 , V_22 ,
* V_25 , ( V_21 == V_34 ) , 0 , * V_24 ,
NULL ) ;
F_26 ( & V_31 -> V_32 -> V_33 ) ;
if ( F_27 ( V_20 <= 0 ) )
F_28 ( * V_24 , * V_25 * sizeof( * * V_24 ) ) ;
}
return V_20 ;
}
static void F_29 ( struct V_1 * * V_24 , int V_35 , int V_36 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_35 ; V_37 ++ ) {
if ( V_24 [ V_37 ] == NULL )
break;
if ( V_36 )
F_30 ( V_24 [ V_37 ] ) ;
F_31 ( V_24 [ V_37 ] ) ;
}
F_28 ( V_24 , V_35 * sizeof( * V_24 ) ) ;
}
T_3 F_32 ( const struct V_5 * V_6 , struct V_38 * V_39 ,
int V_21 , struct V_4 * V_4 ,
struct V_40 * V_41 )
{
struct V_7 * V_42 ;
struct V_43 * V_44 ;
struct V_8 * V_9 = V_39 -> V_45 ;
int V_37 ;
T_3 V_46 = 0 ;
T_4 V_47 = V_41 -> V_48 ;
long V_23 = V_41 -> V_49 ;
int F_16 = V_41 -> V_50 ;
struct V_1 * * V_24 = V_41 -> V_51 ;
long V_52 = F_33 ( V_9 ) ;
bool V_53 ;
int V_54 = 0 ;
V_55 ;
V_44 = & V_39 -> V_56 ;
F_34 ( V_44 ) ;
for ( V_37 = 0 ; V_37 < F_16 ; V_37 ++ ) {
if ( V_41 -> V_57 )
V_47 = V_41 -> V_57 [ V_37 ] ;
F_2 ( ! ( V_47 & ( V_52 - 1 ) ) ) ;
V_42 = F_35 ( V_6 , V_9 , F_36 ( V_9 , V_47 ) ,
V_41 -> V_51 [ V_37 ] , V_58 ) ;
if ( F_6 ( V_42 ) ) {
V_46 = F_37 ( V_42 ) ;
break;
}
V_46 = F_38 ( V_6 , V_39 , V_42 ) ;
if ( V_46 ) {
F_2 ( V_42 -> V_59 == V_60 ) ;
F_12 ( V_6 , V_42 ) ;
break;
}
V_53 = true ;
if ( V_42 -> V_61 == V_62 ) {
struct V_1 * V_2 = F_39 ( V_6 , V_42 ) ;
struct V_1 * V_63 ;
struct V_1 * V_64 ;
void * V_65 ;
void * V_66 ;
V_63 = ( V_21 == V_67 ) ? V_24 [ V_37 ] : V_2 ;
V_64 = ( V_21 == V_67 ) ? V_2 : V_24 [ V_37 ] ;
V_65 = F_40 ( V_63 , V_68 ) ;
V_66 = F_40 ( V_64 , V_69 ) ;
memcpy ( V_66 , V_65 , F_41 ( V_52 , V_23 ) ) ;
F_42 ( V_66 , V_69 ) ;
F_42 ( V_65 , V_68 ) ;
if ( V_21 == V_67 )
F_43 ( V_2 ) ;
if ( V_21 == V_34 ) {
F_44 ( V_6 , V_39 , V_42 ) ;
V_53 = false ;
}
}
if ( F_45 ( V_53 ) ) {
F_46 ( V_44 , V_42 ) ;
F_47 ( V_6 , V_42 , 0 , F_41 ( V_23 , V_52 ) ) ;
++ V_54 ;
}
F_12 ( V_6 , V_42 ) ;
V_23 -= V_52 ;
V_47 += V_52 ;
}
if ( V_46 == 0 && V_54 ) {
V_46 = F_48 ( V_6 , V_39 ,
V_21 == V_34 ? V_70 : V_71 ,
V_44 , 0 ) ;
}
if ( V_46 == 0 )
V_46 = V_41 -> V_49 ;
F_49 ( V_6 , V_39 , V_44 ) ;
F_50 ( V_6 , V_39 , V_44 ) ;
F_51 ( V_6 , V_44 ) ;
RETURN ( V_46 ) ;
}
static T_3 F_52 ( const struct V_5 * V_6 , struct V_38 * V_39 ,
int V_21 , struct V_4 * V_4 ,
struct V_19 * V_11 ,
T_2 V_23 , T_4 V_47 ,
struct V_1 * * V_24 , int F_16 )
{
struct V_40 V_72 = { . V_51 = V_24 ,
. V_50 = F_16 ,
. V_49 = V_23 ,
. V_57 = NULL ,
. V_48 = V_47
} ;
return F_32 ( V_6 , V_39 , V_21 , V_4 , & V_72 ) ;
}
static T_3 F_53 ( int V_21 , struct V_73 * V_74 ,
const struct V_75 * V_76 , T_4 V_47 ,
unsigned long V_77 )
{
struct V_5 * V_6 ;
struct V_38 * V_39 ;
struct V_78 * V_78 = V_74 -> V_79 ;
struct V_4 * V_4 = V_78 -> V_80 -> V_12 ;
struct V_81 * V_9 = F_54 ( V_4 ) ;
long V_82 = F_55 ( V_76 , V_77 ) ;
long V_83 = 0 , V_20 = 0 ;
struct V_84 * V_85 = F_7 ( V_4 ) ;
unsigned long V_86 = 0 ;
long V_23 = V_87 ;
int V_10 ;
V_55 ;
if ( ! V_85 -> V_88 )
RETURN ( - V_89 ) ;
if ( ( V_47 & ~ V_90 ) || ( V_82 & ~ V_90 ) )
RETURN ( - V_91 ) ;
F_56 ( V_92 , L_2
L_3 ,
V_4 -> V_93 , V_4 -> V_94 , V_4 , V_82 , V_87 ,
V_47 , V_47 , V_82 >> V_30 ,
V_87 >> V_30 ) ;
for ( V_86 = 0 ; V_86 < V_77 ; V_86 ++ ) {
if ( ( ( unsigned long ) V_76 [ V_86 ] . V_95 & ~ V_90 ) ||
( V_76 [ V_86 ] . V_96 & ~ V_90 ) )
RETURN ( - V_91 ) ;
}
V_6 = F_5 ( & V_10 ) ;
F_2 ( ! F_6 ( V_6 ) ) ;
V_39 = F_57 ( V_6 ) -> V_97 . V_98 ;
F_2 ( V_39 != NULL ) ;
if ( V_21 == V_34 )
F_58 ( & V_4 -> V_99 ) ;
F_2 ( V_9 -> V_100 == 0 ) ;
for ( V_86 = 0 ; V_86 < V_77 ; V_86 ++ ) {
long V_101 = V_76 [ V_86 ] . V_96 ;
unsigned long V_22 = ( unsigned long ) V_76 [ V_86 ] . V_95 ;
if ( V_21 == V_34 ) {
if ( V_47 >= F_59 ( V_4 ) )
break;
if ( V_47 + V_101 > F_59 ( V_4 ) )
V_101 = F_59 ( V_4 ) - V_47 ;
}
while ( V_101 > 0 ) {
struct V_1 * * V_24 ;
int F_16 , V_25 = 0 ;
long V_102 ;
V_102 = F_41 ( V_23 , V_101 ) ;
F_16 = F_22 ( V_21 , V_22 , V_102 ,
& V_24 , & V_25 ) ;
if ( F_45 ( F_16 > 0 ) ) {
if ( F_27 ( F_16 < V_25 ) )
V_102 = F_16 << V_30 ;
V_20 = F_52 ( V_6 , V_39 , V_21 , V_4 ,
V_78 -> V_80 ,
V_102 , V_47 ,
V_24 , F_16 ) ;
F_29 ( V_24 , V_25 , V_21 == V_34 ) ;
} else if ( F_16 == 0 ) {
GOTO ( V_103 , V_20 = - V_104 ) ;
} else {
V_20 = F_16 ;
}
if ( F_27 ( V_20 <= 0 ) ) {
if ( V_20 == - V_26 &&
V_23 > ( V_29 / sizeof( * V_24 ) ) *
V_29 ) {
V_23 = ( ( ( ( V_23 / 2 ) - 1 ) |
~ V_90 ) + 1 ) &
V_90 ;
F_56 ( V_92 , L_4 ,
V_23 ) ;
continue;
}
GOTO ( V_103 , V_20 ) ;
}
V_83 += V_20 ;
V_47 += V_20 ;
V_101 -= V_20 ;
V_22 += V_20 ;
}
}
V_103:
F_2 ( V_9 -> V_100 == 0 ) ;
if ( V_21 == V_34 )
F_60 ( & V_4 -> V_99 ) ;
if ( V_83 > 0 ) {
if ( V_21 == V_67 ) {
struct V_105 * V_106 ;
V_106 = F_61 ( V_4 ) ;
F_2 ( V_106 != NULL ) ;
F_62 ( V_106 ) ;
F_63 ( F_64 ( V_4 ) , V_106 , V_47 , 0 ) ;
F_65 ( V_106 ) ;
F_66 ( V_4 , V_106 ) ;
}
}
F_13 ( V_6 , & V_10 ) ;
RETURN ( V_83 ? : V_20 ) ;
}
static int F_67 ( struct V_78 * V_78 , struct V_19 * V_11 ,
T_4 V_107 , unsigned V_108 , unsigned V_109 ,
struct V_1 * * V_110 , void * * V_111 )
{
T_5 V_112 = V_107 >> V_30 ;
struct V_1 * V_1 ;
int V_46 ;
unsigned V_113 = V_107 & ( V_29 - 1 ) ;
V_55 ;
V_1 = F_68 ( V_11 , V_112 , V_109 ) ;
if ( ! V_1 )
RETURN ( - V_26 ) ;
* V_110 = V_1 ;
V_46 = F_69 ( V_78 , V_1 , V_113 , V_113 + V_108 ) ;
if ( V_46 ) {
F_70 ( V_1 ) ;
F_31 ( V_1 ) ;
}
RETURN ( V_46 ) ;
}
static int F_71 ( struct V_78 * V_78 , struct V_19 * V_11 ,
T_4 V_107 , unsigned V_108 , unsigned V_114 ,
struct V_1 * V_1 , void * V_111 )
{
unsigned V_113 = V_107 & ( V_29 - 1 ) ;
int V_46 ;
V_46 = F_72 ( V_78 , V_1 , V_113 , V_113 + V_114 ) ;
F_70 ( V_1 ) ;
F_31 ( V_1 ) ;
return V_46 ? : V_114 ;
}
int F_73 ( struct V_19 * V_11 ,
struct V_1 * V_115 , struct V_1 * V_1
, enum V_116 V_117
)
{
return - V_118 ;
}
