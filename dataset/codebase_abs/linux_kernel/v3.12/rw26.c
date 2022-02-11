static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_1 ;
struct V_9 * V_10 ;
int V_11 ;
F_2 ( F_3 ( V_2 ) ) ;
F_2 ( ! F_4 ( V_2 ) ) ;
if ( V_3 == 0 && V_4 == V_12 ) {
V_7 = F_5 ( & V_11 ) ;
if ( ! F_6 ( V_7 ) ) {
V_5 = V_2 -> V_13 -> V_14 ;
V_10 = F_7 ( V_5 ) -> V_15 ;
if ( V_10 != NULL ) {
V_1 = F_8 ( V_2 , V_10 ) ;
if ( V_1 != NULL ) {
F_9 ( & V_1 -> V_16 ,
L_1 , V_2 ) ;
F_10 ( V_7 , V_1 ) ;
F_11 ( & V_1 -> V_16 ,
L_1 , V_2 ) ;
F_12 ( V_7 , V_1 ) ;
}
} else
F_2 ( V_2 -> V_17 == 0 ) ;
F_13 ( V_7 , & V_11 ) ;
}
}
}
static int F_14 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_19 V_20 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_8 * V_1 ;
struct V_21 * V_13 ;
int V_22 ;
F_2 ( F_3 ( V_2 ) ) ;
if ( F_4 ( V_2 ) || F_15 ( V_2 ) )
return 0 ;
V_13 = V_2 -> V_13 ;
if ( V_13 == NULL )
return 1 ;
V_10 = F_7 ( V_13 -> V_14 ) -> V_15 ;
if ( V_10 == NULL )
return 1 ;
if ( F_16 ( V_2 ) > 3 )
return 0 ;
V_7 = F_17 ( & V_20 ) ;
if ( F_6 ( V_7 ) )
return 0 ;
V_1 = F_8 ( V_2 , V_10 ) ;
V_22 = V_1 == NULL ;
if ( V_1 != NULL ) {
if ( ! F_18 ( V_1 ) ) {
V_22 = 1 ;
F_10 ( V_7 , V_1 ) ;
}
F_12 ( V_7 , V_1 ) ;
}
F_19 ( & V_20 , V_7 ) ;
return V_22 ;
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
return F_21 ( V_2 ) ;
}
static inline int F_22 ( int V_23 , unsigned long V_24 ,
T_2 V_25 , struct V_1 * * * V_26 ,
int * V_27 )
{
int V_22 = - V_28 ;
if ( V_25 > V_29 ) {
* V_26 = NULL ;
return - V_30 ;
}
* V_27 = ( V_24 + V_25 + V_12 - 1 ) >> V_31 ;
* V_27 -= V_24 >> V_31 ;
F_23 ( * V_26 , * V_27 * sizeof( * * V_26 ) ) ;
if ( * V_26 ) {
F_24 ( & V_32 -> V_33 -> V_34 ) ;
V_22 = F_25 ( V_32 , V_32 -> V_33 , V_24 ,
* V_27 , ( V_23 == V_35 ) , 0 , * V_26 ,
NULL ) ;
F_26 ( & V_32 -> V_33 -> V_34 ) ;
if ( F_27 ( V_22 <= 0 ) )
F_28 ( * V_26 , * V_27 * sizeof( * * V_26 ) ) ;
}
return V_22 ;
}
static void F_29 ( struct V_1 * * V_26 , int V_36 , int V_37 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_36 ; V_38 ++ ) {
if ( V_26 [ V_38 ] == NULL )
break;
if ( V_37 )
F_30 ( V_26 [ V_38 ] ) ;
F_31 ( V_26 [ V_38 ] ) ;
}
F_28 ( V_26 , V_36 * sizeof( * V_26 ) ) ;
}
T_3 F_32 ( const struct V_6 * V_7 , struct V_39 * V_40 ,
int V_23 , struct V_5 * V_5 ,
struct V_41 * V_42 )
{
struct V_8 * V_43 ;
struct V_44 * V_45 ;
struct V_9 * V_10 = V_40 -> V_46 ;
int V_38 ;
T_3 V_47 = 0 ;
T_4 V_48 = V_42 -> V_49 ;
long V_25 = V_42 -> V_50 ;
int F_16 = V_42 -> V_51 ;
struct V_1 * * V_26 = V_42 -> V_52 ;
long V_53 = F_33 ( V_10 ) ;
bool V_54 ;
int V_55 = 0 ;
V_45 = & V_40 -> V_56 ;
F_34 ( V_45 ) ;
for ( V_38 = 0 ; V_38 < F_16 ; V_38 ++ ) {
if ( V_42 -> V_57 )
V_48 = V_42 -> V_57 [ V_38 ] ;
F_2 ( ! ( V_48 & ( V_53 - 1 ) ) ) ;
V_43 = F_35 ( V_7 , V_10 , F_36 ( V_10 , V_48 ) ,
V_42 -> V_52 [ V_38 ] , V_58 ) ;
if ( F_6 ( V_43 ) ) {
V_47 = F_37 ( V_43 ) ;
break;
}
V_47 = F_38 ( V_7 , V_40 , V_43 ) ;
if ( V_47 ) {
F_2 ( V_43 -> V_59 == V_60 ) ;
F_12 ( V_7 , V_43 ) ;
break;
}
V_54 = true ;
if ( V_43 -> V_61 == V_62 ) {
struct V_1 * V_2 = F_39 ( V_7 , V_43 ) ;
struct V_1 * V_63 ;
struct V_1 * V_64 ;
void * V_65 ;
void * V_66 ;
V_63 = ( V_23 == V_67 ) ? V_26 [ V_38 ] : V_2 ;
V_64 = ( V_23 == V_67 ) ? V_2 : V_26 [ V_38 ] ;
V_65 = F_40 ( V_63 ) ;
V_66 = F_40 ( V_64 ) ;
memcpy ( V_66 , V_65 , F_41 ( V_53 , V_25 ) ) ;
F_42 ( V_66 ) ;
F_42 ( V_65 ) ;
if ( V_23 == V_67 )
F_43 ( V_2 ) ;
if ( V_23 == V_35 ) {
F_44 ( V_7 , V_40 , V_43 ) ;
V_54 = false ;
}
}
if ( F_45 ( V_54 ) ) {
F_46 ( V_45 , V_43 ) ;
F_47 ( V_7 , V_43 , 0 , F_41 ( V_25 , V_53 ) ) ;
++ V_55 ;
}
F_12 ( V_7 , V_43 ) ;
V_25 -= V_53 ;
V_48 += V_53 ;
}
if ( V_47 == 0 && V_55 ) {
V_47 = F_48 ( V_7 , V_40 ,
V_23 == V_35 ? V_68 : V_69 ,
V_45 , 0 ) ;
}
if ( V_47 == 0 )
V_47 = V_42 -> V_50 ;
F_49 ( V_7 , V_40 , V_45 ) ;
F_50 ( V_7 , V_40 , V_45 ) ;
F_51 ( V_7 , V_45 ) ;
return V_47 ;
}
static T_3 F_52 ( const struct V_6 * V_7 , struct V_39 * V_40 ,
int V_23 , struct V_5 * V_5 ,
struct V_21 * V_13 ,
T_2 V_25 , T_4 V_48 ,
struct V_1 * * V_26 , int F_16 )
{
struct V_41 V_70 = { . V_52 = V_26 ,
. V_51 = F_16 ,
. V_50 = V_25 ,
. V_57 = NULL ,
. V_49 = V_48
} ;
return F_32 ( V_7 , V_40 , V_23 , V_5 , & V_70 ) ;
}
static T_3 F_53 ( int V_23 , struct V_71 * V_72 ,
const struct V_73 * V_74 , T_4 V_48 ,
unsigned long V_75 )
{
struct V_6 * V_7 ;
struct V_39 * V_40 ;
struct V_76 * V_76 = V_72 -> V_77 ;
struct V_5 * V_5 = V_76 -> V_78 -> V_14 ;
struct V_79 * V_10 = F_54 ( V_5 ) ;
long V_80 = F_55 ( V_74 , V_75 ) ;
long V_81 = 0 , V_22 = 0 ;
struct V_82 * V_83 = F_7 ( V_5 ) ;
unsigned long V_84 = 0 ;
long V_25 = V_85 ;
int V_11 ;
if ( ! V_83 -> V_86 )
return - V_87 ;
if ( ( V_48 & ~ V_88 ) || ( V_80 & ~ V_88 ) )
return - V_89 ;
F_56 ( V_90 , L_2
L_3 ,
V_5 -> V_91 , V_5 -> V_92 , V_5 , V_80 , V_85 ,
V_48 , V_48 , V_80 >> V_31 ,
V_85 >> V_31 ) ;
for ( V_84 = 0 ; V_84 < V_75 ; V_84 ++ ) {
if ( ( ( unsigned long ) V_74 [ V_84 ] . V_93 & ~ V_88 ) ||
( V_74 [ V_84 ] . V_94 & ~ V_88 ) )
return - V_89 ;
}
V_7 = F_5 ( & V_11 ) ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_40 = F_57 ( V_7 ) -> V_95 . V_96 ;
F_2 ( V_40 != NULL ) ;
if ( V_23 == V_35 )
F_58 ( & V_5 -> V_97 ) ;
F_2 ( V_10 -> V_98 == 0 ) ;
for ( V_84 = 0 ; V_84 < V_75 ; V_84 ++ ) {
long V_99 = V_74 [ V_84 ] . V_94 ;
unsigned long V_24 = ( unsigned long ) V_74 [ V_84 ] . V_93 ;
if ( V_23 == V_35 ) {
if ( V_48 >= F_59 ( V_5 ) )
break;
if ( V_48 + V_99 > F_59 ( V_5 ) )
V_99 = F_59 ( V_5 ) - V_48 ;
}
while ( V_99 > 0 ) {
struct V_1 * * V_26 ;
int F_16 , V_27 = 0 ;
long V_100 ;
V_100 = F_41 ( V_25 , V_99 ) ;
F_16 = F_22 ( V_23 , V_24 , V_100 ,
& V_26 , & V_27 ) ;
if ( F_45 ( F_16 > 0 ) ) {
if ( F_27 ( F_16 < V_27 ) )
V_100 = F_16 << V_31 ;
V_22 = F_52 ( V_7 , V_40 , V_23 , V_5 ,
V_76 -> V_78 ,
V_100 , V_48 ,
V_26 , F_16 ) ;
F_29 ( V_26 , V_27 , V_23 == V_35 ) ;
} else if ( F_16 == 0 ) {
GOTO ( V_101 , V_22 = - V_102 ) ;
} else {
V_22 = F_16 ;
}
if ( F_27 ( V_22 <= 0 ) ) {
if ( V_22 == - V_28 &&
V_25 > ( V_12 / sizeof( * V_26 ) ) *
V_12 ) {
V_25 = ( ( ( ( V_25 / 2 ) - 1 ) |
~ V_88 ) + 1 ) &
V_88 ;
F_56 ( V_90 , L_4 ,
V_25 ) ;
continue;
}
GOTO ( V_101 , V_22 ) ;
}
V_81 += V_22 ;
V_48 += V_22 ;
V_99 -= V_22 ;
V_24 += V_22 ;
}
}
V_101:
F_2 ( V_10 -> V_98 == 0 ) ;
if ( V_23 == V_35 )
F_60 ( & V_5 -> V_97 ) ;
if ( V_81 > 0 ) {
if ( V_23 == V_67 ) {
struct V_103 * V_104 ;
V_104 = F_61 ( V_5 ) ;
F_2 ( V_104 != NULL ) ;
F_62 ( V_104 ) ;
F_63 ( F_64 ( V_5 ) , V_104 , V_48 , 0 ) ;
F_65 ( V_104 ) ;
F_66 ( V_5 , V_104 ) ;
}
}
F_13 ( V_7 , & V_11 ) ;
return V_81 ? : V_22 ;
}
static int F_67 ( struct V_76 * V_76 , struct V_21 * V_13 ,
T_4 V_105 , unsigned V_106 , unsigned V_107 ,
struct V_1 * * V_108 , void * * V_109 )
{
T_5 V_110 = V_105 >> V_31 ;
struct V_1 * V_1 ;
int V_47 ;
unsigned V_111 = V_105 & ( V_12 - 1 ) ;
V_1 = F_68 ( V_13 , V_110 , V_107 ) ;
if ( ! V_1 )
return - V_28 ;
* V_108 = V_1 ;
V_47 = F_69 ( V_76 , V_1 , V_111 , V_111 + V_106 ) ;
if ( V_47 ) {
F_70 ( V_1 ) ;
F_31 ( V_1 ) ;
}
return V_47 ;
}
static int F_71 ( struct V_76 * V_76 , struct V_21 * V_13 ,
T_4 V_105 , unsigned V_106 , unsigned V_112 ,
struct V_1 * V_1 , void * V_109 )
{
unsigned V_111 = V_105 & ( V_12 - 1 ) ;
int V_47 ;
V_47 = F_72 ( V_76 , V_1 , V_111 , V_111 + V_112 ) ;
F_70 ( V_1 ) ;
F_31 ( V_1 ) ;
return V_47 ? : V_112 ;
}
int F_73 ( struct V_21 * V_13 ,
struct V_1 * V_113 , struct V_1 * V_1
, enum V_114 V_115
)
{
return - V_116 ;
}
