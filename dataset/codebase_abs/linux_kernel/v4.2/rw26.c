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
* V_26 = F_23 ( * V_27 * sizeof( * * V_26 ) , V_32 ) ;
if ( * V_26 ) {
V_22 = F_24 ( V_24 , * V_27 ,
( V_23 == V_33 ) , * V_26 ) ;
if ( F_25 ( V_22 <= 0 ) )
F_26 ( * V_26 ) ;
}
return V_22 ;
}
static void F_27 ( struct V_1 * * V_26 , int V_34 , int V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_34 ; V_36 ++ ) {
if ( V_35 )
F_28 ( V_26 [ V_36 ] ) ;
F_29 ( V_26 [ V_36 ] ) ;
}
F_26 ( V_26 ) ;
}
T_3 F_30 ( const struct V_6 * V_7 , struct V_37 * V_38 ,
int V_23 , struct V_5 * V_5 ,
struct V_39 * V_40 )
{
struct V_8 * V_41 ;
struct V_42 * V_43 ;
struct V_9 * V_10 = V_38 -> V_44 ;
int V_36 ;
T_3 V_45 = 0 ;
T_4 V_46 = V_40 -> V_47 ;
long V_25 = V_40 -> V_48 ;
int F_16 = V_40 -> V_49 ;
struct V_1 * * V_26 = V_40 -> V_50 ;
long V_51 = F_31 ( V_10 ) ;
bool V_52 ;
int V_53 = 0 ;
V_43 = & V_38 -> V_54 ;
F_32 ( V_43 ) ;
for ( V_36 = 0 ; V_36 < F_16 ; V_36 ++ ) {
if ( V_40 -> V_55 )
V_46 = V_40 -> V_55 [ V_36 ] ;
F_2 ( ! ( V_46 & ( V_51 - 1 ) ) ) ;
V_41 = F_33 ( V_7 , V_10 , F_34 ( V_10 , V_46 ) ,
V_40 -> V_50 [ V_36 ] , V_56 ) ;
if ( F_6 ( V_41 ) ) {
V_45 = F_35 ( V_41 ) ;
break;
}
V_45 = F_36 ( V_7 , V_38 , V_41 ) ;
if ( V_45 ) {
F_2 ( V_41 -> V_57 == V_58 ) ;
F_12 ( V_7 , V_41 ) ;
break;
}
V_52 = true ;
if ( V_41 -> V_59 == V_60 ) {
struct V_1 * V_2 = F_37 ( V_7 , V_41 ) ;
struct V_1 * V_61 ;
struct V_1 * V_62 ;
void * V_63 ;
void * V_64 ;
V_61 = ( V_23 == V_65 ) ? V_26 [ V_36 ] : V_2 ;
V_62 = ( V_23 == V_65 ) ? V_2 : V_26 [ V_36 ] ;
V_63 = F_38 ( V_61 ) ;
V_64 = F_38 ( V_62 ) ;
memcpy ( V_64 , V_63 , F_39 ( V_51 , V_25 ) ) ;
F_40 ( V_64 ) ;
F_40 ( V_63 ) ;
if ( V_23 == V_65 )
F_41 ( V_2 ) ;
if ( V_23 == V_33 ) {
F_42 ( V_7 , V_38 , V_41 ) ;
V_52 = false ;
}
}
if ( F_43 ( V_52 ) ) {
F_44 ( V_43 , V_41 ) ;
F_45 ( V_7 , V_41 , 0 , F_39 ( V_25 , V_51 ) ) ;
++ V_53 ;
}
F_12 ( V_7 , V_41 ) ;
V_25 -= V_51 ;
V_46 += V_51 ;
}
if ( V_45 == 0 && V_53 ) {
V_45 = F_46 ( V_7 , V_38 ,
V_23 == V_33 ? V_66 : V_67 ,
V_43 , 0 ) ;
}
if ( V_45 == 0 )
V_45 = V_40 -> V_48 ;
F_47 ( V_7 , V_38 , V_43 ) ;
F_48 ( V_7 , V_38 , V_43 ) ;
F_49 ( V_7 , V_43 ) ;
return V_45 ;
}
static T_3 F_50 ( const struct V_6 * V_7 , struct V_37 * V_38 ,
int V_23 , struct V_5 * V_5 ,
struct V_21 * V_13 ,
T_2 V_25 , T_4 V_46 ,
struct V_1 * * V_26 , int F_16 )
{
struct V_39 V_68 = { . V_50 = V_26 ,
. V_49 = F_16 ,
. V_48 = V_25 ,
. V_55 = NULL ,
. V_47 = V_46
} ;
return F_30 ( V_7 , V_38 , V_23 , V_5 , & V_68 ) ;
}
static T_3 F_51 ( struct V_69 * V_70 , struct V_71 * V_72 ,
T_4 V_46 )
{
struct V_6 * V_7 ;
struct V_37 * V_38 ;
struct V_73 * V_73 = V_70 -> V_74 ;
struct V_5 * V_5 = V_73 -> V_75 -> V_14 ;
struct V_76 * V_10 = F_52 ( V_5 ) ;
T_3 V_77 = F_53 ( V_72 ) ;
T_3 V_78 = 0 , V_22 = 0 ;
struct V_79 * V_80 = F_7 ( V_5 ) ;
long V_25 = V_81 ;
int V_11 ;
if ( ! V_80 -> V_82 )
return - V_83 ;
if ( ( V_46 & ~ V_84 ) || ( V_77 & ~ V_84 ) )
return - V_85 ;
F_54 ( V_86 ,
L_2 ,
V_5 -> V_87 , V_5 -> V_88 , V_5 , V_77 , V_81 ,
V_46 , V_46 , V_77 >> V_31 ,
V_81 >> V_31 ) ;
if ( F_55 ( V_72 ) & ~ V_84 )
return - V_85 ;
V_7 = F_5 ( & V_11 ) ;
F_2 ( ! F_6 ( V_7 ) ) ;
V_38 = F_56 ( V_7 ) -> V_89 . V_90 ;
F_2 ( V_38 != NULL ) ;
if ( F_57 ( V_72 ) == V_33 )
F_58 ( & V_5 -> V_91 ) ;
F_2 ( V_10 -> V_92 == 0 ) ;
while ( F_53 ( V_72 ) ) {
struct V_1 * * V_26 ;
T_2 V_93 ;
V_77 = F_59 ( T_2 , F_53 ( V_72 ) , V_25 ) ;
if ( F_57 ( V_72 ) == V_33 ) {
if ( V_46 >= F_60 ( V_5 ) )
break;
if ( V_46 + V_77 > F_60 ( V_5 ) )
V_77 = F_60 ( V_5 ) - V_46 ;
}
V_22 = F_61 ( V_72 , & V_26 , V_77 , & V_93 ) ;
if ( F_43 ( V_22 > 0 ) ) {
int V_94 = F_62 ( V_22 + V_93 , V_95 ) ;
V_22 = F_50 ( V_7 , V_38 , F_57 ( V_72 ) ,
V_5 , V_73 -> V_75 ,
V_22 , V_46 , V_26 ,
V_94 ) ;
F_27 ( V_26 , V_94 , F_57 ( V_72 ) == V_33 ) ;
}
if ( F_25 ( V_22 <= 0 ) ) {
if ( V_22 == - V_28 &&
V_25 > ( V_12 / sizeof( * V_26 ) ) *
V_12 ) {
V_25 = ( ( ( ( V_25 / 2 ) - 1 ) |
~ V_84 ) + 1 ) &
V_84 ;
F_54 ( V_86 , L_3 ,
V_25 ) ;
continue;
}
goto V_96;
}
F_63 ( V_72 , V_22 ) ;
V_78 += V_22 ;
V_46 += V_22 ;
}
V_96:
F_2 ( V_10 -> V_92 == 0 ) ;
if ( F_57 ( V_72 ) == V_33 )
F_64 ( & V_5 -> V_91 ) ;
if ( V_78 > 0 ) {
if ( F_57 ( V_72 ) == V_65 ) {
struct V_97 * V_98 ;
V_98 = F_65 ( V_5 ) ;
F_2 ( V_98 != NULL ) ;
F_66 ( V_98 ) ;
F_67 ( F_68 ( V_5 ) , V_98 , V_46 , 0 ) ;
F_69 ( V_98 ) ;
F_70 ( V_5 , V_98 ) ;
}
}
F_13 ( V_7 , & V_11 ) ;
return V_78 ? : V_22 ;
}
static int F_71 ( struct V_73 * V_73 , struct V_21 * V_13 ,
T_4 V_99 , unsigned V_100 , unsigned V_101 ,
struct V_1 * * V_102 , void * * V_103 )
{
T_5 V_104 = V_99 >> V_31 ;
struct V_1 * V_1 ;
int V_45 ;
unsigned V_105 = V_99 & ( V_12 - 1 ) ;
V_1 = F_72 ( V_13 , V_104 , V_101 ) ;
if ( ! V_1 )
return - V_28 ;
* V_102 = V_1 ;
V_45 = F_73 ( V_73 , V_1 , V_105 , V_105 + V_100 ) ;
if ( V_45 ) {
F_74 ( V_1 ) ;
F_29 ( V_1 ) ;
}
return V_45 ;
}
static int F_75 ( struct V_73 * V_73 , struct V_21 * V_13 ,
T_4 V_99 , unsigned V_100 , unsigned V_106 ,
struct V_1 * V_1 , void * V_103 )
{
unsigned V_105 = V_99 & ( V_12 - 1 ) ;
int V_45 ;
V_45 = F_76 ( V_73 , V_1 , V_105 , V_105 + V_106 ) ;
F_74 ( V_1 ) ;
F_29 ( V_1 ) ;
return V_45 ? : V_106 ;
}
static int F_77 ( struct V_21 * V_13 ,
struct V_1 * V_107 , struct V_1 * V_1 ,
enum V_108 V_109
)
{
return - V_110 ;
}
