static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_7 -> V_9 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_11 V_13 ;
if ( F_4 ( V_4 ) != F_8 ( V_7 -> V_8 ) ) {
F_9 ( L_1 ,
F_8 ( V_7 -> V_8 ) , F_4 ( V_4 ) ) ;
return - V_14 ;
}
V_13 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
if ( V_13 != V_7 -> V_9 ) {
F_9 ( L_2 ,
F_10 ( V_13 ) , F_10 ( V_7 -> V_9 ) ) ;
return - V_15 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_16 * V_17 = F_2 ( V_4 ) ;
V_17 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_17 -> V_9 = F_5 ( F_6 ( & V_17 -> V_18 ,
V_5 - sizeof( V_11 ) ,
V_19 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_16 * V_17 = F_2 ( V_4 ) ;
V_11 V_13 ;
if ( F_4 ( V_4 ) != F_8 ( V_17 -> V_8 ) ) {
F_9 ( L_3 ,
F_8 ( V_17 -> V_8 ) , F_4 ( V_4 ) ) ;
return - V_14 ;
}
V_13 = F_5 ( F_6 ( & V_17 -> V_18 ,
V_5 - sizeof( V_11 ) ,
V_19 ) ) ;
if ( V_13 != V_17 -> V_9 ) {
F_9 ( L_4 ,
F_10 ( V_13 ) , F_10 ( V_17 -> V_9 ) ) ;
return - V_15 ;
}
return 0 ;
}
static void * F_13 ( struct V_3 * V_4 )
{
return F_2 ( V_4 ) + sizeof( struct V_16 ) ;
}
static unsigned F_14 ( void * V_20 , unsigned V_4 )
{
T_2 * V_21 = V_20 ;
T_2 * V_22 = V_21 + ( V_4 >> V_23 ) ;
T_3 V_24 = F_8 ( * V_22 ) ;
T_3 V_25 = ( V_24 + V_26 + 1 ) & V_26 ;
return ! ( ~ V_24 & V_25 ) ;
}
static unsigned F_15 ( void * V_20 , unsigned V_4 )
{
T_2 * V_21 = V_20 ;
T_2 * V_22 = V_21 + ( V_4 >> V_23 ) ;
unsigned V_27 , V_28 ;
V_4 = ( V_4 & ( V_29 - 1 ) ) << 1 ;
V_27 = ! ! F_16 ( V_4 , ( void * ) V_22 ) ;
V_28 = ! ! F_16 ( V_4 + 1 , ( void * ) V_22 ) ;
return ( V_27 << 1 ) | V_28 ;
}
static void F_17 ( void * V_20 , unsigned V_4 , unsigned V_30 )
{
T_2 * V_21 = V_20 ;
T_2 * V_22 = V_21 + ( V_4 >> V_23 ) ;
V_4 = ( V_4 & ( V_29 - 1 ) ) << 1 ;
if ( V_30 & 2 )
F_18 ( V_4 , ( void * ) V_22 ) ;
else
F_19 ( V_4 , ( void * ) V_22 ) ;
if ( V_30 & 1 )
F_18 ( V_4 + 1 , ( void * ) V_22 ) ;
else
F_19 ( V_4 + 1 , ( void * ) V_22 ) ;
}
static int F_20 ( void * V_20 , unsigned V_31 , unsigned V_32 ,
unsigned * V_33 )
{
while ( V_31 < V_32 ) {
if ( ! ( V_31 & ( V_29 - 1 ) ) &&
F_14 ( V_20 , V_31 ) ) {
V_31 += V_29 ;
continue;
}
if ( ! F_15 ( V_20 , V_31 ) ) {
* V_33 = V_31 ;
return 0 ;
}
V_31 ++ ;
}
return - V_34 ;
}
static int F_21 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
V_36 -> V_38 = V_38 ;
V_36 -> V_39 . V_38 = V_38 ;
V_36 -> V_39 . V_40 = 1 ;
V_36 -> V_39 . V_41 . V_42 = sizeof( struct V_43 ) ;
V_36 -> V_39 . V_41 . V_44 = NULL ;
V_36 -> V_39 . V_41 . V_45 = NULL ;
V_36 -> V_39 . V_41 . V_46 = NULL ;
V_36 -> V_47 . V_38 = V_38 ;
V_36 -> V_47 . V_40 = 1 ;
V_36 -> V_47 . V_41 . V_42 = sizeof( V_48 ) ;
V_36 -> V_47 . V_41 . V_44 = NULL ;
V_36 -> V_47 . V_41 . V_45 = NULL ;
V_36 -> V_47 . V_41 . V_46 = NULL ;
V_36 -> V_5 = F_22 ( F_23 ( V_38 ) ) ;
if ( V_36 -> V_5 > ( 1 << 30 ) ) {
F_9 ( L_5 ) ;
return - V_49 ;
}
V_36 -> V_50 = ( V_36 -> V_5 - sizeof( struct V_16 ) ) *
V_51 ;
V_36 -> V_52 = 0 ;
V_36 -> V_53 = 0 ;
V_36 -> V_54 = 0 ;
return 0 ;
}
int F_24 ( struct V_35 * V_36 , T_4 V_55 )
{
int V_56 ;
T_4 V_57 , V_52 , V_58 ;
unsigned V_59 , V_60 ;
V_52 = V_36 -> V_52 + V_55 ;
V_59 = F_25 ( V_36 -> V_52 , V_36 -> V_50 ) ;
V_60 = F_25 ( V_52 , V_36 -> V_50 ) ;
V_58 = F_25 ( V_52 , V_36 -> V_50 ) ;
if ( V_58 > V_36 -> V_61 ( V_36 ) ) {
F_9 ( L_6 ) ;
return - V_49 ;
}
for ( V_57 = V_59 ; V_57 < V_60 ; V_57 ++ ) {
struct V_3 * V_4 ;
struct V_43 V_62 ;
V_56 = F_26 ( V_36 -> V_38 , & V_63 , & V_4 ) ;
if ( V_56 < 0 )
return V_56 ;
V_62 . V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_56 = F_27 ( V_36 -> V_38 , V_4 ) ;
if ( V_56 < 0 )
return V_56 ;
V_62 . V_64 = F_5 ( V_36 -> V_50 ) ;
V_62 . V_65 = 0 ;
V_56 = V_36 -> V_66 ( V_36 , V_57 , & V_62 ) ;
if ( V_56 < 0 )
return V_56 ;
}
V_36 -> V_52 = V_52 ;
return 0 ;
}
int F_28 ( struct V_35 * V_36 , T_4 V_4 , V_48 * V_33 )
{
int V_56 ;
T_4 V_67 = V_4 ;
struct V_43 V_68 ;
struct V_3 * V_69 ;
V_4 = F_29 ( V_67 , V_36 -> V_50 ) ;
V_56 = V_36 -> V_70 ( V_36 , V_67 , & V_68 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_30 ( V_36 -> V_38 , F_8 ( V_68 . V_8 ) ,
& V_63 , & V_69 ) ;
if ( V_56 < 0 )
return V_56 ;
* V_33 = F_15 ( F_13 ( V_69 ) , V_4 ) ;
return F_27 ( V_36 -> V_38 , V_69 ) ;
}
int F_31 ( struct V_35 * V_36 , T_4 V_4 , V_48 * V_33 )
{
V_11 V_71 ;
int V_56 = F_28 ( V_36 , V_4 , V_33 ) ;
if ( V_56 )
return V_56 ;
if ( * V_33 != 3 )
return V_56 ;
V_56 = F_32 ( & V_36 -> V_47 , V_36 -> V_54 , & V_4 , & V_71 ) ;
if ( V_56 < 0 )
return V_56 ;
* V_33 = F_10 ( V_71 ) ;
return V_56 ;
}
int F_33 ( struct V_35 * V_36 , T_4 V_31 ,
T_4 V_32 , T_4 * V_33 )
{
int V_56 ;
struct V_43 V_68 ;
T_4 V_57 , V_72 = V_31 ;
T_4 V_73 = F_25 ( V_32 , V_36 -> V_50 ) ;
V_31 = F_29 ( V_72 , V_36 -> V_50 ) ;
V_32 = F_29 ( V_32 , V_36 -> V_50 ) ;
for ( V_57 = V_72 ; V_57 < V_73 ; V_57 ++ , V_31 = 0 ) {
struct V_3 * V_69 ;
unsigned V_74 ;
V_48 V_75 ;
V_56 = V_36 -> V_70 ( V_36 , V_57 , & V_68 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( F_10 ( V_68 . V_64 ) == 0 )
continue;
V_56 = F_30 ( V_36 -> V_38 , F_8 ( V_68 . V_8 ) ,
& V_63 , & V_69 ) ;
if ( V_56 < 0 )
return V_56 ;
V_75 = ( V_57 == V_73 - 1 ) ? V_32 : V_36 -> V_50 ;
V_56 = F_20 ( F_13 ( V_69 ) ,
F_34 ( unsigned , V_31 , F_10 ( V_68 . V_65 ) ) ,
V_75 , & V_74 ) ;
if ( V_56 == - V_34 ) {
F_27 ( V_36 -> V_38 , V_69 ) ;
continue;
} else if ( V_56 < 0 ) {
F_27 ( V_36 -> V_38 , V_69 ) ;
return V_56 ;
}
V_56 = F_27 ( V_36 -> V_38 , V_69 ) ;
if ( V_56 < 0 )
return V_56 ;
* V_33 = V_57 * V_36 -> V_50 + ( T_4 ) V_74 ;
return 0 ;
}
return - V_34 ;
}
int F_35 ( struct V_35 * V_36 , T_4 V_4 ,
V_48 V_76 , enum V_77 * V_78 )
{
int V_56 ;
V_48 V_79 , V_80 ;
struct V_3 * V_81 ;
T_4 V_67 = V_4 ;
struct V_43 V_68 ;
void * V_82 ;
int V_44 ;
V_79 = F_29 ( V_67 , V_36 -> V_50 ) ;
V_56 = V_36 -> V_70 ( V_36 , V_67 , & V_68 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_36 ( V_36 -> V_38 , F_8 ( V_68 . V_8 ) ,
& V_63 , & V_81 , & V_44 ) ;
if ( V_56 < 0 ) {
F_9 ( L_7 ) ;
return V_56 ;
}
V_68 . V_8 = F_3 ( F_4 ( V_81 ) ) ;
V_82 = F_13 ( V_81 ) ;
V_80 = F_15 ( V_82 , V_79 ) ;
if ( V_76 <= 2 ) {
F_17 ( V_82 , V_79 , V_76 ) ;
V_56 = F_27 ( V_36 -> V_38 , V_81 ) ;
if ( V_56 < 0 )
return V_56 ;
#if 0
if (old > 2) {
r = dm_btree_remove(&ll->ref_count_info,
ll->ref_count_root,
&b, &ll->ref_count_root);
if (r)
return r;
}
#endif
} else {
V_11 V_71 = F_5 ( V_76 ) ;
F_17 ( V_82 , V_79 , 3 ) ;
V_56 = F_27 ( V_36 -> V_38 , V_81 ) ;
if ( V_56 < 0 )
return V_56 ;
F_37 ( & V_71 ) ;
V_56 = F_38 ( & V_36 -> V_47 , V_36 -> V_54 ,
& V_4 , & V_71 , & V_36 -> V_54 ) ;
if ( V_56 < 0 ) {
F_9 ( L_8 ) ;
return V_56 ;
}
}
if ( V_76 && ! V_80 ) {
* V_78 = V_83 ;
V_36 -> V_84 ++ ;
V_68 . V_64 = F_5 ( F_10 ( V_68 . V_64 ) - 1 ) ;
if ( F_10 ( V_68 . V_65 ) == V_79 )
V_68 . V_65 = F_5 ( V_79 + 1 ) ;
} else if ( V_80 && ! V_76 ) {
* V_78 = V_85 ;
V_36 -> V_84 -- ;
V_68 . V_64 = F_5 ( F_10 ( V_68 . V_64 ) + 1 ) ;
V_68 . V_65 = F_5 ( F_39 ( F_10 ( V_68 . V_65 ) , V_79 ) ) ;
}
return V_36 -> V_66 ( V_36 , V_67 , & V_68 ) ;
}
int F_40 ( struct V_35 * V_36 , T_4 V_4 , enum V_77 * V_78 )
{
int V_56 ;
V_48 V_86 ;
V_56 = F_31 ( V_36 , V_4 , & V_86 ) ;
if ( V_56 )
return V_56 ;
return F_35 ( V_36 , V_4 , V_86 + 1 , V_78 ) ;
}
int F_41 ( struct V_35 * V_36 , T_4 V_4 , enum V_77 * V_78 )
{
int V_56 ;
V_48 V_86 ;
V_56 = F_31 ( V_36 , V_4 , & V_86 ) ;
if ( V_56 )
return V_56 ;
if ( ! V_86 )
return - V_49 ;
return F_35 ( V_36 , V_4 , V_86 - 1 , V_78 ) ;
}
int F_42 ( struct V_35 * V_36 )
{
return V_36 -> V_87 ( V_36 ) ;
}
static int F_43 ( struct V_35 * V_36 , T_4 V_67 ,
struct V_43 * V_88 )
{
memcpy ( V_88 , V_36 -> V_7 . V_67 + V_67 , sizeof( * V_88 ) ) ;
return 0 ;
}
static int F_44 ( struct V_35 * V_36 , T_4 V_67 ,
struct V_43 * V_88 )
{
memcpy ( V_36 -> V_7 . V_67 + V_67 , V_88 , sizeof( * V_88 ) ) ;
return 0 ;
}
static int F_45 ( struct V_35 * V_36 )
{
int V_56 ;
struct V_3 * V_4 ;
V_56 = F_26 ( V_36 -> V_38 , & V_89 , & V_4 ) ;
if ( V_56 < 0 )
return V_56 ;
memcpy ( F_2 ( V_4 ) , & V_36 -> V_7 , sizeof( V_36 -> V_7 ) ) ;
V_36 -> V_53 = F_4 ( V_4 ) ;
return F_27 ( V_36 -> V_38 , V_4 ) ;
}
static int F_46 ( struct V_35 * V_36 )
{
int V_56 ;
struct V_3 * V_90 ;
V_56 = F_30 ( V_36 -> V_38 , V_36 -> V_53 ,
& V_89 , & V_90 ) ;
if ( V_56 )
return V_56 ;
memcpy ( & V_36 -> V_7 , F_2 ( V_90 ) , sizeof( V_36 -> V_7 ) ) ;
return F_27 ( V_36 -> V_38 , V_90 ) ;
}
static T_4 F_47 ( struct V_35 * V_36 )
{
return V_91 ;
}
static int F_48 ( struct V_35 * V_36 )
{
int V_56 , V_44 ;
struct V_3 * V_4 ;
V_56 = F_36 ( V_36 -> V_38 , V_36 -> V_53 , & V_89 , & V_4 , & V_44 ) ;
if ( V_56 )
return V_56 ;
memcpy ( F_2 ( V_4 ) , & V_36 -> V_7 , sizeof( V_36 -> V_7 ) ) ;
V_36 -> V_53 = F_4 ( V_4 ) ;
return F_27 ( V_36 -> V_38 , V_4 ) ;
}
int F_49 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
int V_56 ;
V_56 = F_21 ( V_36 , V_38 ) ;
if ( V_56 < 0 )
return V_56 ;
V_36 -> V_70 = F_43 ;
V_36 -> V_66 = F_44 ;
V_36 -> V_92 = F_45 ;
V_36 -> V_93 = F_46 ;
V_36 -> V_61 = F_47 ;
V_36 -> V_87 = F_48 ;
V_36 -> V_52 = 0 ;
V_36 -> V_84 = 0 ;
V_56 = V_36 -> V_92 ( V_36 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_50 ( & V_36 -> V_47 , & V_36 -> V_54 ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
int F_51 ( struct V_35 * V_36 , struct V_37 * V_38 ,
void * V_94 , T_1 V_95 )
{
int V_56 ;
struct V_96 * V_97 = V_94 ;
if ( V_95 < sizeof( struct V_96 ) ) {
F_9 ( L_9 ) ;
return - V_98 ;
}
V_56 = F_21 ( V_36 , V_38 ) ;
if ( V_56 < 0 )
return V_56 ;
V_36 -> V_70 = F_43 ;
V_36 -> V_66 = F_44 ;
V_36 -> V_92 = F_45 ;
V_36 -> V_93 = F_46 ;
V_36 -> V_61 = F_47 ;
V_36 -> V_87 = F_48 ;
V_36 -> V_52 = F_8 ( V_97 -> V_52 ) ;
V_36 -> V_84 = F_8 ( V_97 -> V_84 ) ;
V_36 -> V_53 = F_8 ( V_97 -> V_53 ) ;
V_36 -> V_54 = F_8 ( V_97 -> V_54 ) ;
return V_36 -> V_93 ( V_36 ) ;
}
static int F_52 ( struct V_35 * V_36 , T_4 V_67 ,
struct V_43 * V_88 )
{
return F_32 ( & V_36 -> V_39 , V_36 -> V_53 , & V_67 , V_88 ) ;
}
static int F_53 ( struct V_35 * V_36 , T_4 V_67 ,
struct V_43 * V_88 )
{
F_37 ( V_88 ) ;
return F_38 ( & V_36 -> V_39 , V_36 -> V_53 ,
& V_67 , V_88 , & V_36 -> V_53 ) ;
}
static int F_54 ( struct V_35 * V_36 )
{
return F_50 ( & V_36 -> V_39 , & V_36 -> V_53 ) ;
}
static int F_55 ( struct V_35 * V_36 )
{
return 0 ;
}
static T_4 F_56 ( struct V_35 * V_36 )
{
return - 1ULL ;
}
static int F_57 ( struct V_35 * V_36 )
{
return 0 ;
}
int F_58 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
int V_56 ;
V_56 = F_21 ( V_36 , V_38 ) ;
if ( V_56 < 0 )
return V_56 ;
V_36 -> V_70 = F_52 ;
V_36 -> V_66 = F_53 ;
V_36 -> V_92 = F_54 ;
V_36 -> V_93 = F_55 ;
V_36 -> V_61 = F_56 ;
V_36 -> V_87 = F_57 ;
V_36 -> V_52 = 0 ;
V_36 -> V_84 = 0 ;
V_56 = V_36 -> V_92 ( V_36 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 = F_50 ( & V_36 -> V_47 , & V_36 -> V_54 ) ;
if ( V_56 < 0 )
return V_56 ;
return 0 ;
}
int F_59 ( struct V_35 * V_36 , struct V_37 * V_38 ,
void * V_94 , T_1 V_95 )
{
int V_56 ;
struct V_96 * V_97 = V_94 ;
if ( V_95 < sizeof( struct V_96 ) ) {
F_9 ( L_9 ) ;
return - V_98 ;
}
V_56 = F_21 ( V_36 , V_38 ) ;
if ( V_56 < 0 )
return V_56 ;
V_36 -> V_70 = F_52 ;
V_36 -> V_66 = F_53 ;
V_36 -> V_92 = F_54 ;
V_36 -> V_93 = F_55 ;
V_36 -> V_61 = F_56 ;
V_36 -> V_87 = F_57 ;
V_36 -> V_52 = F_8 ( V_97 -> V_52 ) ;
V_36 -> V_84 = F_8 ( V_97 -> V_84 ) ;
V_36 -> V_53 = F_8 ( V_97 -> V_53 ) ;
V_36 -> V_54 = F_8 ( V_97 -> V_54 ) ;
return V_36 -> V_93 ( V_36 ) ;
}
