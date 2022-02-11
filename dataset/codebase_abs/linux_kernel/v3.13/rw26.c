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
V_22 = F_24 ( V_24 , * V_27 ,
( V_23 == V_32 ) , * V_26 ) ;
if ( F_25 ( V_22 <= 0 ) )
F_26 ( * V_26 , * V_27 * sizeof( * * V_26 ) ) ;
}
return V_22 ;
}
static void F_27 ( struct V_1 * * V_26 , int V_33 , int V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ ) {
if ( V_26 [ V_35 ] == NULL )
break;
if ( V_34 )
F_28 ( V_26 [ V_35 ] ) ;
F_29 ( V_26 [ V_35 ] ) ;
}
F_26 ( V_26 , V_33 * sizeof( * V_26 ) ) ;
}
T_3 F_30 ( const struct V_6 * V_7 , struct V_36 * V_37 ,
int V_23 , struct V_5 * V_5 ,
struct V_38 * V_39 )
{
struct V_8 * V_40 ;
struct V_41 * V_42 ;
struct V_9 * V_10 = V_37 -> V_43 ;
int V_35 ;
T_3 V_44 = 0 ;
T_4 V_45 = V_39 -> V_46 ;
long V_25 = V_39 -> V_47 ;
int F_16 = V_39 -> V_48 ;
struct V_1 * * V_26 = V_39 -> V_49 ;
long V_50 = F_31 ( V_10 ) ;
bool V_51 ;
int V_52 = 0 ;
V_42 = & V_37 -> V_53 ;
F_32 ( V_42 ) ;
for ( V_35 = 0 ; V_35 < F_16 ; V_35 ++ ) {
if ( V_39 -> V_54 )
V_45 = V_39 -> V_54 [ V_35 ] ;
F_2 ( ! ( V_45 & ( V_50 - 1 ) ) ) ;
V_40 = F_33 ( V_7 , V_10 , F_34 ( V_10 , V_45 ) ,
V_39 -> V_49 [ V_35 ] , V_55 ) ;
if ( F_6 ( V_40 ) ) {
V_44 = F_35 ( V_40 ) ;
break;
}
V_44 = F_36 ( V_7 , V_37 , V_40 ) ;
if ( V_44 ) {
F_2 ( V_40 -> V_56 == V_57 ) ;
F_12 ( V_7 , V_40 ) ;
break;
}
V_51 = true ;
if ( V_40 -> V_58 == V_59 ) {
struct V_1 * V_2 = F_37 ( V_7 , V_40 ) ;
struct V_1 * V_60 ;
struct V_1 * V_61 ;
void * V_62 ;
void * V_63 ;
V_60 = ( V_23 == V_64 ) ? V_26 [ V_35 ] : V_2 ;
V_61 = ( V_23 == V_64 ) ? V_2 : V_26 [ V_35 ] ;
V_62 = F_38 ( V_60 ) ;
V_63 = F_38 ( V_61 ) ;
memcpy ( V_63 , V_62 , F_39 ( V_50 , V_25 ) ) ;
F_40 ( V_63 ) ;
F_40 ( V_62 ) ;
if ( V_23 == V_64 )
F_41 ( V_2 ) ;
if ( V_23 == V_32 ) {
F_42 ( V_7 , V_37 , V_40 ) ;
V_51 = false ;
}
}
if ( F_43 ( V_51 ) ) {
F_44 ( V_42 , V_40 ) ;
F_45 ( V_7 , V_40 , 0 , F_39 ( V_25 , V_50 ) ) ;
++ V_52 ;
}
F_12 ( V_7 , V_40 ) ;
V_25 -= V_50 ;
V_45 += V_50 ;
}
if ( V_44 == 0 && V_52 ) {
V_44 = F_46 ( V_7 , V_37 ,
V_23 == V_32 ? V_65 : V_66 ,
V_42 , 0 ) ;
}
if ( V_44 == 0 )
V_44 = V_39 -> V_47 ;
F_47 ( V_7 , V_37 , V_42 ) ;
F_48 ( V_7 , V_37 , V_42 ) ;
F_49 ( V_7 , V_42 ) ;
return V_44 ;
}
static T_3 F_50 ( const struct V_6 * V_7 , struct V_36 * V_37 ,
int V_23 , struct V_5 * V_5 ,
struct V_21 * V_13 ,
T_2 V_25 , T_4 V_45 ,
struct V_1 * * V_26 , int F_16 )
{
struct V_38 V_67 = { . V_49 = V_26 ,
. V_48 = F_16 ,
. V_47 = V_25 ,
. V_54 = NULL ,
. V_46 = V_45
} ;
return F_30 ( V_7 , V_37 , V_23 , V_5 , & V_67 ) ;
}
static T_3 F_51 ( int V_23 , struct V_68 * V_69 ,
const struct V_70 * V_71 , T_4 V_45 ,
unsigned long V_72 )
{
struct V_6 * V_7 ;
struct V_36 * V_37 ;
struct V_73 * V_73 = V_69 -> V_74 ;
struct V_5 * V_5 = V_73 -> V_75 -> V_14 ;
struct V_76 * V_10 = F_52 ( V_5 ) ;
long V_77 = F_53 ( V_71 , V_72 ) ;
long V_78 = 0 , V_22 = 0 ;
struct V_79 * V_80 = F_7 ( V_5 ) ;
unsigned long V_81 = 0 ;
long V_25 = V_82 ;
int V_11 ;
if ( ! V_80 -> V_83 )
return - V_84 ;
if ( ( V_45 & ~ V_85 ) || ( V_77 & ~ V_85 ) )
return - V_86 ;
F_54 ( V_87 , L_2
L_3 ,
V_5 -> V_88 , V_5 -> V_89 , V_5 , V_77 , V_82 ,
V_45 , V_45 , V_77 >> V_31 ,
V_82 >> V_31 ) ;
for ( V_81 = 0 ; V_81 < V_72 ; V_81 ++ ) {
if ( ( ( unsigned long ) V_71 [ V_81 ] . V_90 & ~ V_85 ) ||
( V_71 [ V_81 ] . V_91 & ~ V_85 ) )
return - V_86 ;
}
V_7 = F_5 ( & V_11 ) ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_37 = F_55 ( V_7 ) -> V_92 . V_93 ;
F_2 ( V_37 != NULL ) ;
if ( V_23 == V_32 )
F_56 ( & V_5 -> V_94 ) ;
F_2 ( V_10 -> V_95 == 0 ) ;
for ( V_81 = 0 ; V_81 < V_72 ; V_81 ++ ) {
long V_96 = V_71 [ V_81 ] . V_91 ;
unsigned long V_24 = ( unsigned long ) V_71 [ V_81 ] . V_90 ;
if ( V_23 == V_32 ) {
if ( V_45 >= F_57 ( V_5 ) )
break;
if ( V_45 + V_96 > F_57 ( V_5 ) )
V_96 = F_57 ( V_5 ) - V_45 ;
}
while ( V_96 > 0 ) {
struct V_1 * * V_26 ;
int F_16 , V_27 = 0 ;
long V_97 ;
V_97 = F_39 ( V_25 , V_96 ) ;
F_16 = F_22 ( V_23 , V_24 , V_97 ,
& V_26 , & V_27 ) ;
if ( F_43 ( F_16 > 0 ) ) {
if ( F_25 ( F_16 < V_27 ) )
V_97 = F_16 << V_31 ;
V_22 = F_50 ( V_7 , V_37 , V_23 , V_5 ,
V_73 -> V_75 ,
V_97 , V_45 ,
V_26 , F_16 ) ;
F_27 ( V_26 , V_27 , V_23 == V_32 ) ;
} else if ( F_16 == 0 ) {
GOTO ( V_98 , V_22 = - V_99 ) ;
} else {
V_22 = F_16 ;
}
if ( F_25 ( V_22 <= 0 ) ) {
if ( V_22 == - V_28 &&
V_25 > ( V_12 / sizeof( * V_26 ) ) *
V_12 ) {
V_25 = ( ( ( ( V_25 / 2 ) - 1 ) |
~ V_85 ) + 1 ) &
V_85 ;
F_54 ( V_87 , L_4 ,
V_25 ) ;
continue;
}
GOTO ( V_98 , V_22 ) ;
}
V_78 += V_22 ;
V_45 += V_22 ;
V_96 -= V_22 ;
V_24 += V_22 ;
}
}
V_98:
F_2 ( V_10 -> V_95 == 0 ) ;
if ( V_23 == V_32 )
F_58 ( & V_5 -> V_94 ) ;
if ( V_78 > 0 ) {
if ( V_23 == V_64 ) {
struct V_100 * V_101 ;
V_101 = F_59 ( V_5 ) ;
F_2 ( V_101 != NULL ) ;
F_60 ( V_101 ) ;
F_61 ( F_62 ( V_5 ) , V_101 , V_45 , 0 ) ;
F_63 ( V_101 ) ;
F_64 ( V_5 , V_101 ) ;
}
}
F_13 ( V_7 , & V_11 ) ;
return V_78 ? : V_22 ;
}
static int F_65 ( struct V_73 * V_73 , struct V_21 * V_13 ,
T_4 V_102 , unsigned V_103 , unsigned V_104 ,
struct V_1 * * V_105 , void * * V_106 )
{
T_5 V_107 = V_102 >> V_31 ;
struct V_1 * V_1 ;
int V_44 ;
unsigned V_108 = V_102 & ( V_12 - 1 ) ;
V_1 = F_66 ( V_13 , V_107 , V_104 ) ;
if ( ! V_1 )
return - V_28 ;
* V_105 = V_1 ;
V_44 = F_67 ( V_73 , V_1 , V_108 , V_108 + V_103 ) ;
if ( V_44 ) {
F_68 ( V_1 ) ;
F_29 ( V_1 ) ;
}
return V_44 ;
}
static int F_69 ( struct V_73 * V_73 , struct V_21 * V_13 ,
T_4 V_102 , unsigned V_103 , unsigned V_109 ,
struct V_1 * V_1 , void * V_106 )
{
unsigned V_108 = V_102 & ( V_12 - 1 ) ;
int V_44 ;
V_44 = F_70 ( V_73 , V_1 , V_108 , V_108 + V_109 ) ;
F_68 ( V_1 ) ;
F_29 ( V_1 ) ;
return V_44 ? : V_109 ;
}
int F_71 ( struct V_21 * V_13 ,
struct V_1 * V_110 , struct V_1 * V_1
, enum V_111 V_112
)
{
return - V_113 ;
}
