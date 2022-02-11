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
if ( V_34 )
F_28 ( V_26 [ V_35 ] ) ;
F_29 ( V_26 [ V_35 ] ) ;
}
F_30 ( V_26 ) ;
}
T_3 F_31 ( const struct V_6 * V_7 , struct V_36 * V_37 ,
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
long V_50 = F_32 ( V_10 ) ;
bool V_51 ;
int V_52 = 0 ;
V_42 = & V_37 -> V_53 ;
F_33 ( V_42 ) ;
for ( V_35 = 0 ; V_35 < F_16 ; V_35 ++ ) {
if ( V_39 -> V_54 )
V_45 = V_39 -> V_54 [ V_35 ] ;
F_2 ( ! ( V_45 & ( V_50 - 1 ) ) ) ;
V_40 = F_34 ( V_7 , V_10 , F_35 ( V_10 , V_45 ) ,
V_39 -> V_49 [ V_35 ] , V_55 ) ;
if ( F_6 ( V_40 ) ) {
V_44 = F_36 ( V_40 ) ;
break;
}
V_44 = F_37 ( V_7 , V_37 , V_40 ) ;
if ( V_44 ) {
F_2 ( V_40 -> V_56 == V_57 ) ;
F_12 ( V_7 , V_40 ) ;
break;
}
V_51 = true ;
if ( V_40 -> V_58 == V_59 ) {
struct V_1 * V_2 = F_38 ( V_7 , V_40 ) ;
struct V_1 * V_60 ;
struct V_1 * V_61 ;
void * V_62 ;
void * V_63 ;
V_60 = ( V_23 == V_64 ) ? V_26 [ V_35 ] : V_2 ;
V_61 = ( V_23 == V_64 ) ? V_2 : V_26 [ V_35 ] ;
V_62 = F_39 ( V_60 ) ;
V_63 = F_39 ( V_61 ) ;
memcpy ( V_63 , V_62 , F_40 ( V_50 , V_25 ) ) ;
F_41 ( V_63 ) ;
F_41 ( V_62 ) ;
if ( V_23 == V_64 )
F_42 ( V_2 ) ;
if ( V_23 == V_32 ) {
F_43 ( V_7 , V_37 , V_40 ) ;
V_51 = false ;
}
}
if ( F_44 ( V_51 ) ) {
F_45 ( V_42 , V_40 ) ;
F_46 ( V_7 , V_40 , 0 , F_40 ( V_25 , V_50 ) ) ;
++ V_52 ;
}
F_12 ( V_7 , V_40 ) ;
V_25 -= V_50 ;
V_45 += V_50 ;
}
if ( V_44 == 0 && V_52 ) {
V_44 = F_47 ( V_7 , V_37 ,
V_23 == V_32 ? V_65 : V_66 ,
V_42 , 0 ) ;
}
if ( V_44 == 0 )
V_44 = V_39 -> V_47 ;
F_48 ( V_7 , V_37 , V_42 ) ;
F_49 ( V_7 , V_37 , V_42 ) ;
F_50 ( V_7 , V_42 ) ;
return V_44 ;
}
static T_3 F_51 ( const struct V_6 * V_7 , struct V_36 * V_37 ,
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
return F_31 ( V_7 , V_37 , V_23 , V_5 , & V_67 ) ;
}
static T_3 F_52 ( struct V_68 * V_69 , struct V_70 * V_71 ,
T_4 V_45 )
{
struct V_6 * V_7 ;
struct V_36 * V_37 ;
struct V_72 * V_72 = V_69 -> V_73 ;
struct V_5 * V_5 = V_72 -> V_74 -> V_14 ;
struct V_75 * V_10 = F_53 ( V_5 ) ;
T_3 V_76 = F_54 ( V_71 ) ;
T_3 V_77 = 0 , V_22 = 0 ;
struct V_78 * V_79 = F_7 ( V_5 ) ;
long V_25 = V_80 ;
int V_11 ;
if ( ! V_79 -> V_81 )
return - V_82 ;
if ( ( V_45 & ~ V_83 ) || ( V_76 & ~ V_83 ) )
return - V_84 ;
F_55 ( V_85 ,
L_2 ,
V_5 -> V_86 , V_5 -> V_87 , V_5 , V_76 , V_80 ,
V_45 , V_45 , V_76 >> V_31 ,
V_80 >> V_31 ) ;
if ( F_56 ( V_71 ) & ~ V_83 )
return - V_84 ;
V_7 = F_5 ( & V_11 ) ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_37 = F_57 ( V_7 ) -> V_88 . V_89 ;
F_2 ( V_37 != NULL ) ;
if ( F_58 ( V_71 ) == V_32 )
F_59 ( & V_5 -> V_90 ) ;
F_2 ( V_10 -> V_91 == 0 ) ;
while ( F_54 ( V_71 ) ) {
struct V_1 * * V_26 ;
T_2 V_92 ;
V_76 = F_60 ( T_2 , F_54 ( V_71 ) , V_25 ) ;
if ( F_58 ( V_71 ) == V_32 ) {
if ( V_45 >= F_61 ( V_5 ) )
break;
if ( V_45 + V_76 > F_61 ( V_5 ) )
V_76 = F_61 ( V_5 ) - V_45 ;
}
V_22 = F_62 ( V_71 , & V_26 , V_76 , & V_92 ) ;
if ( F_44 ( V_22 > 0 ) ) {
int V_93 = F_63 ( V_22 + V_92 , V_94 ) ;
V_22 = F_51 ( V_7 , V_37 , F_58 ( V_71 ) ,
V_5 , V_72 -> V_74 ,
V_22 , V_45 , V_26 ,
V_93 ) ;
F_27 ( V_26 , V_93 , F_58 ( V_71 ) == V_32 ) ;
}
if ( F_25 ( V_22 <= 0 ) ) {
if ( V_22 == - V_28 &&
V_25 > ( V_12 / sizeof( * V_26 ) ) *
V_12 ) {
V_25 = ( ( ( ( V_25 / 2 ) - 1 ) |
~ V_83 ) + 1 ) &
V_83 ;
F_55 ( V_85 , L_3 ,
V_25 ) ;
continue;
}
goto V_95;
}
F_64 ( V_71 , V_22 ) ;
V_77 += V_22 ;
V_45 += V_22 ;
}
V_95:
F_2 ( V_10 -> V_91 == 0 ) ;
if ( F_58 ( V_71 ) == V_32 )
F_65 ( & V_5 -> V_90 ) ;
if ( V_77 > 0 ) {
if ( F_58 ( V_71 ) == V_64 ) {
struct V_96 * V_97 ;
V_97 = F_66 ( V_5 ) ;
F_2 ( V_97 != NULL ) ;
F_67 ( V_97 ) ;
F_68 ( F_69 ( V_5 ) , V_97 , V_45 , 0 ) ;
F_70 ( V_97 ) ;
F_71 ( V_5 , V_97 ) ;
}
}
F_13 ( V_7 , & V_11 ) ;
return V_77 ? : V_22 ;
}
static int F_72 ( struct V_72 * V_72 , struct V_21 * V_13 ,
T_4 V_98 , unsigned V_99 , unsigned V_100 ,
struct V_1 * * V_101 , void * * V_102 )
{
T_5 V_103 = V_98 >> V_31 ;
struct V_1 * V_1 ;
int V_44 ;
unsigned V_104 = V_98 & ( V_12 - 1 ) ;
V_1 = F_73 ( V_13 , V_103 , V_100 ) ;
if ( ! V_1 )
return - V_28 ;
* V_101 = V_1 ;
V_44 = F_74 ( V_72 , V_1 , V_104 , V_104 + V_99 ) ;
if ( V_44 ) {
F_75 ( V_1 ) ;
F_29 ( V_1 ) ;
}
return V_44 ;
}
static int F_76 ( struct V_72 * V_72 , struct V_21 * V_13 ,
T_4 V_98 , unsigned V_99 , unsigned V_105 ,
struct V_1 * V_1 , void * V_102 )
{
unsigned V_104 = V_98 & ( V_12 - 1 ) ;
int V_44 ;
V_44 = F_77 ( V_72 , V_1 , V_104 , V_104 + V_105 ) ;
F_75 ( V_1 ) ;
F_29 ( V_1 ) ;
return V_44 ? : V_105 ;
}
static int F_78 ( struct V_21 * V_13 ,
struct V_1 * V_106 , struct V_1 * V_1 ,
enum V_107 V_108
)
{
return - V_109 ;
}
