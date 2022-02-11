void T_1 F_1 ( void )
{
V_1 = V_2 * V_3 ;
}
void T_1 F_2 ( void )
{
V_4 = ( ( V_5 * 2 ) / 5 ) * V_3 ;
}
static void * F_3 ( T_2 V_6 , int V_7 )
{
void * V_8 ;
V_8 = ( void * ) F_4 ( V_6 ) ;
if ( V_7 )
while ( V_8 && F_5 ( F_6 ( V_8 ) ) ) {
F_7 ( F_6 ( V_8 ) ) ;
V_9 ++ ;
V_8 = ( void * ) F_4 ( V_6 ) ;
}
if ( V_8 ) {
F_7 ( F_6 ( V_8 ) ) ;
F_8 ( F_6 ( V_8 ) ) ;
}
return V_8 ;
}
unsigned long F_9 ( T_2 V_6 )
{
return ( unsigned long ) F_3 ( V_6 , V_10 ) ;
}
static struct V_11 * F_10 ( T_2 V_6 )
{
struct V_11 * V_11 ;
V_11 = F_11 ( V_6 ) ;
if ( V_11 ) {
F_7 ( V_11 ) ;
F_8 ( V_11 ) ;
}
return V_11 ;
}
static inline void F_12 ( void * V_12 , int V_13 )
{
struct V_11 * V_11 ;
F_13 ( ! F_14 ( V_12 ) ) ;
V_11 = F_6 ( V_12 ) ;
F_15 ( V_11 ) ;
if ( V_13 )
F_16 ( V_11 ) ;
F_17 ( V_11 ) ;
}
static inline void
F_18 ( struct V_14 * V_15 , int V_16 )
{
while ( V_15 ) {
struct V_14 * V_17 = V_15 -> V_18 ;
F_12 ( V_15 , V_16 ) ;
V_15 = V_17 ;
}
}
static void
F_19 ( struct V_19 * V_20 , T_2 V_6 , int V_7 )
{
V_20 -> V_21 = NULL ;
V_20 -> V_22 = V_23 ;
V_20 -> V_6 = V_6 ;
V_20 -> V_7 = V_7 ;
}
static void * F_20 ( struct V_19 * V_20 , unsigned int V_24 )
{
void * V_25 ;
if ( V_23 - V_20 -> V_22 < V_24 ) {
struct V_14 * V_17 ;
V_17 = F_3 ( V_20 -> V_6 , V_20 -> V_7 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_18 = V_20 -> V_21 ;
V_20 -> V_21 = V_17 ;
V_20 -> V_22 = 0 ;
}
V_25 = V_20 -> V_21 -> V_26 + V_20 -> V_22 ;
V_20 -> V_22 += V_24 ;
return V_25 ;
}
static inline unsigned long F_21 ( struct V_27 * V_28 )
{
return V_28 -> V_29 - V_28 -> V_30 ;
}
static void F_22 ( struct V_31 * V_32 )
{
V_32 -> V_33 . V_34 = F_23 ( V_32 -> V_35 . V_18 , struct V_27 , V_36 ) ;
V_32 -> V_33 . V_37 = 0 ;
}
static int F_24 ( unsigned long V_38 ,
struct V_39 * V_15 ,
struct V_19 * V_20 )
{
unsigned int V_40 = F_25 ( V_38 , V_41 ) ;
while ( V_40 -- > 0 ) {
struct V_27 * V_28 ;
V_28 = F_20 ( V_20 , sizeof( struct V_27 ) ) ;
if ( ! V_28 )
return - V_42 ;
F_26 ( & V_28 -> V_36 , V_15 ) ;
}
return 0 ;
}
static void F_27 ( struct V_39 * V_15 )
{
struct V_43 * V_44 , * V_45 ;
F_28 (ext, aux, list, hook) {
F_29 ( & V_44 -> V_36 ) ;
F_30 ( V_44 ) ;
}
}
static int F_31 ( struct V_39 * V_15 , T_2 V_6 )
{
struct V_46 * V_46 ;
F_32 ( V_15 ) ;
F_33 (zone) {
unsigned long V_47 , V_48 ;
struct V_43 * V_44 , * V_33 , * V_45 ;
V_47 = V_46 -> V_49 ;
V_48 = V_46 -> V_49 + V_46 -> V_50 ;
F_34 (ext, list, hook)
if ( V_47 <= V_44 -> V_51 )
break;
if ( & V_44 -> V_36 == V_15 || V_48 < V_44 -> V_52 ) {
struct V_43 * V_53 ;
V_53 = F_35 ( sizeof( struct V_43 ) , V_6 ) ;
if ( ! V_53 ) {
F_27 ( V_15 ) ;
return - V_42 ;
}
V_53 -> V_52 = V_47 ;
V_53 -> V_51 = V_48 ;
F_36 ( & V_53 -> V_36 , & V_44 -> V_36 ) ;
continue;
}
if ( V_47 < V_44 -> V_52 )
V_44 -> V_52 = V_47 ;
if ( V_48 > V_44 -> V_51 )
V_44 -> V_51 = V_48 ;
V_33 = V_44 ;
F_37 (cur, aux, list, hook) {
if ( V_48 < V_33 -> V_52 )
break;
if ( V_48 < V_33 -> V_51 )
V_44 -> V_51 = V_33 -> V_51 ;
F_29 ( & V_33 -> V_36 ) ;
F_30 ( V_33 ) ;
}
}
return 0 ;
}
static int
F_38 ( struct V_31 * V_32 , T_2 V_6 , int V_7 )
{
struct V_19 V_20 ;
struct V_39 V_54 ;
struct V_43 * V_44 ;
int error ;
F_19 ( & V_20 , V_6 , V_7 ) ;
F_32 ( & V_32 -> V_35 ) ;
error = F_31 ( & V_54 , V_6 ) ;
if ( error )
return error ;
F_34 (ext, &mem_extents, hook) {
struct V_27 * V_28 ;
unsigned long V_55 = V_44 -> V_52 ;
unsigned long V_38 = V_44 -> V_51 - V_44 -> V_52 ;
V_28 = F_23 ( V_32 -> V_35 . V_56 , struct V_27 , V_36 ) ;
error = F_24 ( V_38 , V_32 -> V_35 . V_56 , & V_20 ) ;
if ( error )
goto Error;
F_39 (bb, &bm->blocks, hook) {
V_28 -> V_26 = F_3 ( V_6 , V_7 ) ;
if ( ! V_28 -> V_26 ) {
error = - V_42 ;
goto Error;
}
V_28 -> V_30 = V_55 ;
if ( V_38 >= V_41 ) {
V_55 += V_41 ;
V_38 -= V_41 ;
} else {
V_55 += V_38 ;
}
V_28 -> V_29 = V_55 ;
}
}
V_32 -> V_57 = V_20 . V_21 ;
F_22 ( V_32 ) ;
Exit:
F_27 ( & V_54 ) ;
return error ;
Error:
V_32 -> V_57 = V_20 . V_21 ;
F_40 ( V_32 , V_58 ) ;
goto Exit;
}
static void F_40 ( struct V_31 * V_32 , int V_13 )
{
struct V_27 * V_28 ;
F_34 (bb, &bm->blocks, hook)
if ( V_28 -> V_26 )
F_12 ( V_28 -> V_26 , V_13 ) ;
F_18 ( V_32 -> V_57 , V_13 ) ;
F_32 ( & V_32 -> V_35 ) ;
}
static int F_41 ( struct V_31 * V_32 , unsigned long V_55 ,
void * * V_12 , unsigned int * V_59 )
{
struct V_27 * V_28 ;
V_28 = V_32 -> V_33 . V_34 ;
if ( V_55 < V_28 -> V_30 )
F_42 (bb, &bm->blocks, hook)
if ( V_55 >= V_28 -> V_30 )
break;
if ( V_55 >= V_28 -> V_29 )
F_39 (bb, &bm->blocks, hook)
if ( V_55 >= V_28 -> V_30 && V_55 < V_28 -> V_29 )
break;
if ( & V_28 -> V_36 == & V_32 -> V_35 )
return - V_60 ;
V_32 -> V_33 . V_34 = V_28 ;
V_55 -= V_28 -> V_30 ;
V_32 -> V_33 . V_37 = V_55 + 1 ;
* V_59 = V_55 ;
* V_12 = V_28 -> V_26 ;
return 0 ;
}
static void F_43 ( struct V_31 * V_32 , unsigned long V_55 )
{
void * V_12 ;
unsigned int V_37 ;
int error ;
error = F_41 ( V_32 , V_55 , & V_12 , & V_37 ) ;
F_13 ( error ) ;
F_44 ( V_37 , V_12 ) ;
}
static int F_45 ( struct V_31 * V_32 , unsigned long V_55 )
{
void * V_12 ;
unsigned int V_37 ;
int error ;
error = F_41 ( V_32 , V_55 , & V_12 , & V_37 ) ;
if ( ! error )
F_44 ( V_37 , V_12 ) ;
return error ;
}
static void F_46 ( struct V_31 * V_32 , unsigned long V_55 )
{
void * V_12 ;
unsigned int V_37 ;
int error ;
error = F_41 ( V_32 , V_55 , & V_12 , & V_37 ) ;
F_13 ( error ) ;
F_47 ( V_37 , V_12 ) ;
}
static int F_48 ( struct V_31 * V_32 , unsigned long V_55 )
{
void * V_12 ;
unsigned int V_37 ;
int error ;
error = F_41 ( V_32 , V_55 , & V_12 , & V_37 ) ;
F_13 ( error ) ;
return F_49 ( V_37 , V_12 ) ;
}
static bool F_50 ( struct V_31 * V_32 , unsigned long V_55 )
{
void * V_12 ;
unsigned int V_37 ;
return ! F_41 ( V_32 , V_55 , & V_12 , & V_37 ) ;
}
static unsigned long F_51 ( struct V_31 * V_32 )
{
struct V_27 * V_28 ;
int V_37 ;
V_28 = V_32 -> V_33 . V_34 ;
do {
V_37 = V_32 -> V_33 . V_37 ;
V_37 = F_52 ( V_28 -> V_26 , F_21 ( V_28 ) , V_37 ) ;
if ( V_37 < F_21 ( V_28 ) )
goto V_61;
V_28 = F_23 ( V_28 -> V_36 . V_18 , struct V_27 , V_36 ) ;
V_32 -> V_33 . V_34 = V_28 ;
V_32 -> V_33 . V_37 = 0 ;
} while ( & V_28 -> V_36 != & V_32 -> V_35 );
F_22 ( V_32 ) ;
return V_62 ;
V_61:
V_32 -> V_33 . V_37 = V_37 + 1 ;
return V_28 -> V_30 + V_37 ;
}
void T_1
F_53 ( unsigned long V_30 , unsigned long V_29 ,
int V_63 )
{
struct V_64 * V_65 ;
if ( V_30 >= V_29 )
return;
if ( ! F_54 ( & V_66 ) ) {
V_65 = F_23 ( V_66 . V_56 ,
struct V_64 , V_15 ) ;
if ( V_65 -> V_29 == V_30 ) {
V_65 -> V_29 = V_29 ;
goto V_67;
}
}
if ( V_63 ) {
V_65 = F_55 ( sizeof( struct V_64 ) , V_68 ) ;
F_13 ( ! V_65 ) ;
} else
V_65 = F_56 ( sizeof( struct V_64 ) ) ;
V_65 -> V_30 = V_30 ;
V_65 -> V_29 = V_29 ;
F_36 ( & V_65 -> V_15 , & V_66 ) ;
V_67:
F_57 ( V_69 L_1 ,
V_30 << V_70 , V_29 << V_70 ) ;
}
void F_8 ( struct V_11 * V_11 )
{
if ( V_71 )
F_43 ( V_71 , F_58 ( V_11 ) ) ;
}
static int F_5 ( struct V_11 * V_11 )
{
return V_71 ?
F_48 ( V_71 , F_58 ( V_11 ) ) : 0 ;
}
void F_16 ( struct V_11 * V_11 )
{
if ( V_71 )
F_46 ( V_71 , F_58 ( V_11 ) ) ;
}
static void F_7 ( struct V_11 * V_11 )
{
if ( V_72 )
F_43 ( V_72 , F_58 ( V_11 ) ) ;
}
int F_59 ( struct V_11 * V_11 )
{
return V_72 ?
F_48 ( V_72 , F_58 ( V_11 ) ) : 0 ;
}
static void F_15 ( struct V_11 * V_11 )
{
if ( V_72 )
F_46 ( V_72 , F_58 ( V_11 ) ) ;
}
static void F_60 ( struct V_31 * V_32 )
{
struct V_64 * V_65 ;
if ( F_54 ( & V_66 ) )
return;
F_34 (region, &nosave_regions, list) {
unsigned long V_55 ;
F_61 ( L_2 ,
V_65 -> V_30 << V_70 ,
V_65 -> V_29 << V_70 ) ;
for ( V_55 = V_65 -> V_30 ; V_55 < V_65 -> V_29 ; V_55 ++ )
if ( F_62 ( V_55 ) ) {
F_45 ( V_32 , V_55 ) ;
}
}
}
int F_63 ( void )
{
struct V_31 * V_73 , * V_74 ;
int error = 0 ;
F_13 ( V_72 || V_71 ) ;
V_73 = F_35 ( sizeof( struct V_31 ) , V_68 ) ;
if ( ! V_73 )
return - V_42 ;
error = F_38 ( V_73 , V_68 , V_75 ) ;
if ( error )
goto V_76;
V_74 = F_35 ( sizeof( struct V_31 ) , V_68 ) ;
if ( ! V_74 )
goto V_77;
error = F_38 ( V_74 , V_68 , V_75 ) ;
if ( error )
goto V_78;
V_72 = V_73 ;
V_71 = V_74 ;
F_60 ( V_72 ) ;
F_61 ( L_3 ) ;
return 0 ;
V_78:
F_30 ( V_74 ) ;
V_77:
F_40 ( V_73 , V_58 ) ;
V_76:
F_30 ( V_73 ) ;
return - V_42 ;
}
void F_64 ( void )
{
struct V_31 * V_73 , * V_74 ;
F_13 ( ! ( V_72 && V_71 ) ) ;
V_73 = V_72 ;
V_74 = V_71 ;
V_72 = NULL ;
V_71 = NULL ;
F_40 ( V_73 , V_58 ) ;
F_30 ( V_73 ) ;
F_40 ( V_74 , V_58 ) ;
F_30 ( V_74 ) ;
F_61 ( L_4 ) ;
}
unsigned int F_65 ( struct V_46 * V_46 )
{
unsigned int V_8 ;
V_8 = F_25 ( V_46 -> V_50 , V_41 ) ;
V_8 += F_25 ( V_8 * sizeof( struct V_27 ) ,
V_23 ) ;
return 2 * V_8 ;
}
static unsigned int F_66 ( void )
{
struct V_46 * V_46 ;
unsigned int V_79 = 0 ;
F_33 (zone)
if ( F_67 ( V_46 ) )
V_79 += F_68 ( V_46 , V_80 ) ;
return V_79 ;
}
static struct V_11 * F_69 ( struct V_46 * V_46 , unsigned long V_55 )
{
struct V_11 * V_11 ;
if ( ! F_62 ( V_55 ) )
return NULL ;
V_11 = F_70 ( V_55 ) ;
if ( F_71 ( V_11 ) != V_46 )
return NULL ;
F_13 ( ! F_72 ( V_11 ) ) ;
if ( F_59 ( V_11 ) || F_5 ( V_11 ) ||
F_73 ( V_11 ) )
return NULL ;
if ( F_74 ( V_11 ) )
return NULL ;
return V_11 ;
}
static unsigned int F_75 ( void )
{
struct V_46 * V_46 ;
unsigned int V_81 = 0 ;
F_33 (zone) {
unsigned long V_55 , V_82 ;
if ( ! F_67 ( V_46 ) )
continue;
F_76 ( V_46 ) ;
V_82 = V_46 -> V_49 + V_46 -> V_50 ;
for ( V_55 = V_46 -> V_49 ; V_55 < V_82 ; V_55 ++ )
if ( F_69 ( V_46 , V_55 ) )
V_81 ++ ;
}
return V_81 ;
}
static inline void * F_69 ( struct V_46 * V_83 , unsigned long V_84 )
{
return NULL ;
}
static struct V_11 * F_77 ( struct V_46 * V_46 , unsigned long V_55 )
{
struct V_11 * V_11 ;
if ( ! F_62 ( V_55 ) )
return NULL ;
V_11 = F_70 ( V_55 ) ;
if ( F_71 ( V_11 ) != V_46 )
return NULL ;
F_13 ( F_72 ( V_11 ) ) ;
if ( F_59 ( V_11 ) || F_5 ( V_11 ) )
return NULL ;
if ( F_73 ( V_11 )
&& ( ! F_78 ( V_11 ) || F_79 ( V_55 ) ) )
return NULL ;
if ( F_74 ( V_11 ) )
return NULL ;
return V_11 ;
}
static unsigned int F_80 ( void )
{
struct V_46 * V_46 ;
unsigned long V_55 , V_82 ;
unsigned int V_81 = 0 ;
F_33 (zone) {
if ( F_67 ( V_46 ) )
continue;
F_76 ( V_46 ) ;
V_82 = V_46 -> V_49 + V_46 -> V_50 ;
for ( V_55 = V_46 -> V_49 ; V_55 < V_82 ; V_55 ++ )
if ( F_77 ( V_46 , V_55 ) )
V_81 ++ ;
}
return V_81 ;
}
static inline void F_81 ( long * V_85 , long * V_86 )
{
int V_81 ;
for ( V_81 = V_3 / sizeof( long ) ; V_81 ; V_81 -- )
* V_85 ++ = * V_86 ++ ;
}
static void F_82 ( void * V_85 , struct V_11 * V_87 )
{
if ( F_78 ( V_87 ) ) {
F_81 ( V_85 , F_83 ( V_87 ) ) ;
} else {
F_84 ( V_87 , 1 , 1 ) ;
F_81 ( V_85 , F_83 ( V_87 ) ) ;
F_84 ( V_87 , 1 , 0 ) ;
}
}
static inline struct V_11 *
F_85 ( struct V_46 * V_46 , unsigned long V_55 )
{
return F_67 ( V_46 ) ?
F_69 ( V_46 , V_55 ) : F_77 ( V_46 , V_55 ) ;
}
static void F_86 ( unsigned long V_88 , unsigned long V_89 )
{
struct V_11 * V_87 , * V_90 ;
void * V_86 , * V_85 ;
V_87 = F_70 ( V_89 ) ;
V_90 = F_70 ( V_88 ) ;
if ( F_72 ( V_87 ) ) {
V_86 = F_87 ( V_87 , V_91 ) ;
V_85 = F_87 ( V_90 , V_92 ) ;
F_81 ( V_85 , V_86 ) ;
F_88 ( V_85 , V_92 ) ;
F_88 ( V_86 , V_91 ) ;
} else {
if ( F_72 ( V_90 ) ) {
F_82 ( V_93 , V_87 ) ;
V_85 = F_87 ( V_90 , V_91 ) ;
F_89 ( V_85 , V_93 ) ;
F_88 ( V_85 , V_91 ) ;
} else {
F_82 ( F_83 ( V_90 ) , V_87 ) ;
}
}
}
static inline void F_86 ( unsigned long V_88 , unsigned long V_89 )
{
F_82 ( F_83 ( F_70 ( V_88 ) ) ,
F_70 ( V_89 ) ) ;
}
static void
F_90 ( struct V_31 * V_94 , struct V_31 * V_95 )
{
struct V_46 * V_46 ;
unsigned long V_55 ;
F_33 (zone) {
unsigned long V_82 ;
F_76 ( V_46 ) ;
V_82 = V_46 -> V_49 + V_46 -> V_50 ;
for ( V_55 = V_46 -> V_49 ; V_55 < V_82 ; V_55 ++ )
if ( F_85 ( V_46 , V_55 ) )
F_43 ( V_95 , V_55 ) ;
}
F_22 ( V_95 ) ;
F_22 ( V_94 ) ;
for(; ; ) {
V_55 = F_51 ( V_95 ) ;
if ( F_91 ( V_55 == V_62 ) )
break;
F_86 ( F_51 ( V_94 ) , V_55 ) ;
}
}
void F_92 ( void )
{
struct V_46 * V_46 ;
unsigned long V_55 , V_82 ;
F_33 (zone) {
V_82 = V_46 -> V_49 + V_46 -> V_50 ;
for ( V_55 = V_46 -> V_49 ; V_55 < V_82 ; V_55 ++ )
if ( F_62 ( V_55 ) ) {
struct V_11 * V_11 = F_70 ( V_55 ) ;
if ( F_59 ( V_11 ) &&
F_5 ( V_11 ) ) {
F_15 ( V_11 ) ;
F_16 ( V_11 ) ;
F_17 ( V_11 ) ;
}
}
}
V_96 = 0 ;
V_97 = 0 ;
V_98 = NULL ;
V_93 = NULL ;
V_99 = 0 ;
V_100 = 0 ;
}
static unsigned long F_93 ( unsigned long V_101 , T_2 V_102 )
{
unsigned long V_103 = 0 ;
while ( V_101 > 0 ) {
struct V_11 * V_11 ;
V_11 = F_10 ( V_102 ) ;
if ( ! V_11 )
break;
F_43 ( & V_94 , F_58 ( V_11 ) ) ;
if ( F_72 ( V_11 ) )
V_100 ++ ;
else
V_99 ++ ;
V_101 -- ;
V_103 ++ ;
}
return V_103 ;
}
static unsigned long F_94 ( unsigned long V_101 ,
unsigned long V_104 )
{
unsigned long V_105 ;
if ( V_104 <= V_99 )
return 0 ;
V_105 = V_104 - V_99 ;
if ( V_101 < V_105 )
V_105 = V_101 ;
return F_93 ( V_105 , V_106 ) ;
}
static unsigned long F_95 ( unsigned long V_101 )
{
return F_93 ( V_101 , V_106 | V_107 ) ;
}
static unsigned long F_96 ( T_3 V_108 , T_3 V_109 , T_3 V_110 )
{
V_108 *= V_109 ;
F_97 ( V_108 , V_110 ) ;
return ( unsigned long ) V_108 ;
}
static unsigned long F_98 ( unsigned long V_101 ,
unsigned long V_111 ,
unsigned long V_112 )
{
unsigned long V_105 = F_96 ( V_101 , V_111 , V_112 ) ;
return F_93 ( V_105 , V_106 | V_107 ) ;
}
static inline unsigned long F_95 ( unsigned long V_101 )
{
return 0 ;
}
static inline unsigned long F_98 ( unsigned long V_101 ,
unsigned long V_111 ,
unsigned long V_112 )
{
return 0 ;
}
static void F_99 ( void )
{
unsigned long V_113 , V_114 , V_115 ;
V_113 = F_80 () ;
if ( V_99 >= V_113 ) {
V_114 = V_99 - V_113 ;
V_113 = 0 ;
} else {
V_114 = 0 ;
V_113 -= V_99 ;
}
V_113 += F_75 () ;
if ( V_100 >= V_113 ) {
V_115 = V_100 - V_113 ;
} else {
V_115 = 0 ;
V_113 -= V_100 ;
if ( V_114 > V_113 )
V_114 -= V_113 ;
else
V_114 = 0 ;
}
F_22 ( & V_94 ) ;
while ( V_114 > 0 || V_115 > 0 ) {
unsigned long V_55 = F_51 ( & V_94 ) ;
struct V_11 * V_11 = F_70 ( V_55 ) ;
if ( F_72 ( V_11 ) ) {
if ( ! V_115 )
continue;
V_115 -- ;
V_100 -- ;
} else {
if ( ! V_114 )
continue;
V_114 -- ;
V_99 -- ;
}
F_46 ( & V_94 , V_55 ) ;
F_15 ( V_11 ) ;
F_16 ( V_11 ) ;
F_17 ( V_11 ) ;
}
}
static unsigned long F_100 ( unsigned long V_116 )
{
unsigned long V_24 ;
V_24 = F_101 ( V_117 )
+ F_101 ( V_118 )
+ F_101 ( V_119 )
+ F_101 ( V_120 )
+ F_101 ( V_121 )
- F_101 ( V_122 ) ;
return V_116 <= V_24 ? 0 : V_116 - V_24 ;
}
int F_102 ( void )
{
struct V_46 * V_46 ;
unsigned long V_116 , V_24 , V_123 , V_124 , V_111 , V_38 = 0 ;
unsigned long V_105 , V_125 , V_126 , V_104 ;
struct V_127 V_52 , V_128 ;
int error ;
F_57 ( V_69 L_5 ) ;
F_103 ( & V_52 ) ;
error = F_38 ( & V_95 , V_106 , V_75 ) ;
if ( error )
goto V_129;
error = F_38 ( & V_94 , V_106 , V_75 ) ;
if ( error )
goto V_129;
V_99 = 0 ;
V_100 = 0 ;
V_125 = F_75 () ;
V_116 = F_80 () ;
V_124 = V_116 ;
V_116 += V_125 ;
V_111 = V_125 ;
V_24 = 0 ;
F_33 (zone) {
V_24 += F_65 ( V_46 ) ;
if ( F_67 ( V_46 ) )
V_111 += F_68 ( V_46 , V_80 ) ;
else
V_124 += F_68 ( V_46 , V_80 ) ;
}
V_104 = V_124 ;
V_124 += V_111 ;
V_124 -= V_130 ;
V_24 += F_104 ( V_116 ) ;
V_123 = ( V_124 - ( V_24 + V_131 ) ) / 2
- 2 * F_25 ( V_1 , V_3 ) ;
V_24 = F_25 ( V_4 , V_3 ) ;
if ( V_24 > V_123 )
V_24 = V_123 ;
if ( V_24 >= V_116 ) {
V_38 = F_95 ( V_125 ) ;
V_38 += F_94 ( V_116 - V_38 , V_104 ) ;
goto V_132;
}
V_38 = F_100 ( V_116 ) ;
if ( V_104 > V_38 )
V_104 -= V_38 ;
else
V_104 = 0 ;
if ( V_24 < V_38 )
V_24 = F_105 (unsigned long, pages, max_size) ;
F_106 ( V_116 - V_24 ) ;
V_126 = F_95 ( V_111 / 2 ) ;
V_105 = ( V_124 - V_123 ) - V_126 ;
V_38 = F_94 ( V_105 , V_104 ) ;
if ( V_38 < V_105 ) {
V_105 -= V_38 ;
V_38 += V_126 ;
V_126 = F_95 ( V_105 ) ;
if ( V_126 < V_105 )
goto V_129;
V_38 += V_126 ;
V_105 = ( V_124 - V_38 ) - V_24 ;
V_38 += F_95 ( V_105 ) ;
} else {
V_105 = V_123 - V_24 ;
V_24 = F_98 ( V_105 , V_111 , V_124 ) ;
V_126 += V_24 ;
V_105 -= V_24 ;
V_24 = F_94 ( V_105 , V_104 ) ;
V_126 += F_95 ( V_105 - V_24 ) ;
V_38 += V_126 + V_24 ;
}
F_99 () ;
V_132:
F_103 ( & V_128 ) ;
F_57 ( V_133 L_6 , V_38 ) ;
F_107 ( & V_52 , & V_128 , V_38 , L_7 ) ;
return 0 ;
V_129:
F_57 ( V_133 L_8 ) ;
F_92 () ;
return - V_42 ;
}
static unsigned int F_108 ( unsigned int V_134 )
{
unsigned int V_135 = F_66 () + V_100 ;
if ( V_135 >= V_134 )
V_134 = 0 ;
else
V_134 -= V_135 ;
return V_134 ;
}
static unsigned int
F_108 ( unsigned int V_134 ) { return 0 ; }
static int F_109 ( unsigned int V_101 , unsigned int V_134 )
{
struct V_46 * V_46 ;
unsigned int free = V_99 ;
F_33 (zone)
if ( ! F_67 ( V_46 ) )
free += F_68 ( V_46 , V_80 ) ;
V_101 += F_108 ( V_134 ) ;
F_61 ( L_9 ,
V_101 , V_131 , free ) ;
return free > V_101 + V_131 ;
}
static inline int F_110 ( int V_7 )
{
V_93 = F_3 ( V_136 | V_137 , V_7 ) ;
return V_93 ? 0 : - V_42 ;
}
static inline unsigned int
F_111 ( struct V_31 * V_32 , unsigned int V_134 )
{
unsigned int V_138 = F_66 () ;
if ( V_138 > V_134 )
V_138 = V_134 ;
V_134 -= V_138 ;
while ( V_138 -- > 0 ) {
struct V_11 * V_11 ;
V_11 = F_10 ( V_107 ) ;
F_43 ( V_32 , F_58 ( V_11 ) ) ;
}
return V_134 ;
}
static inline int F_110 ( int V_7 ) { return 0 ; }
static inline unsigned int
F_111 ( struct V_31 * V_32 , unsigned int V_81 ) { return 0 ; }
static int
F_112 ( struct V_31 * V_95 , struct V_31 * V_94 ,
unsigned int V_101 , unsigned int V_134 )
{
if ( V_134 > 0 ) {
if ( F_110 ( V_75 ) )
goto V_129;
if ( V_134 > V_100 ) {
V_134 -= V_100 ;
V_101 += F_111 ( V_94 , V_134 ) ;
}
}
if ( V_101 > V_99 ) {
V_101 -= V_99 ;
while ( V_101 -- > 0 ) {
struct V_11 * V_11 ;
V_11 = F_10 ( V_136 | V_137 ) ;
if ( ! V_11 )
goto V_129;
F_43 ( V_94 , F_58 ( V_11 ) ) ;
}
}
return 0 ;
V_129:
F_92 () ;
return - V_42 ;
}
T_4 int F_113 ( void )
{
unsigned int V_101 , V_134 ;
F_57 ( V_69 L_10 ) ;
F_114 ( NULL ) ;
V_101 = F_80 () ;
V_134 = F_75 () ;
F_57 ( V_69 L_11 , V_101 + V_134 ) ;
if ( ! F_109 ( V_101 , V_134 ) ) {
F_57 ( V_139 L_12 ) ;
return - V_42 ;
}
if ( F_112 ( & V_95 , & V_94 , V_101 , V_134 ) ) {
F_57 ( V_139 L_13 ) ;
return - V_42 ;
}
F_114 ( NULL ) ;
F_90 ( & V_94 , & V_95 ) ;
V_101 += V_134 ;
V_96 = V_101 ;
V_97 = F_25 ( V_101 * sizeof( long ) , V_3 ) ;
F_57 ( V_69 L_14 ,
V_101 ) ;
return 0 ;
}
static int F_115 ( struct V_140 * V_141 )
{
memcpy ( & V_141 -> V_142 , F_116 () , sizeof( struct V_143 ) ) ;
V_141 -> V_144 = V_145 ;
return 0 ;
}
static char * F_117 ( struct V_140 * V_141 )
{
if ( V_141 -> V_144 != V_145 )
return L_15 ;
if ( strcmp ( V_141 -> V_142 . V_146 , F_116 () -> V_146 ) )
return L_16 ;
if ( strcmp ( V_141 -> V_142 . V_147 , F_116 () -> V_147 ) )
return L_17 ;
if ( strcmp ( V_141 -> V_142 . V_148 , F_116 () -> V_148 ) )
return L_18 ;
if ( strcmp ( V_141 -> V_142 . V_149 , F_116 () -> V_149 ) )
return L_19 ;
return NULL ;
}
unsigned long F_118 ( void )
{
return V_96 + V_97 + 1 ;
}
static int F_119 ( struct V_140 * V_141 )
{
memset ( V_141 , 0 , sizeof( struct V_140 ) ) ;
V_141 -> V_150 = V_150 ;
V_141 -> V_151 = V_96 ;
V_141 -> V_38 = F_118 () ;
V_141 -> V_24 = V_141 -> V_38 ;
V_141 -> V_24 <<= V_70 ;
return F_115 ( V_141 ) ;
}
static inline void
F_120 ( unsigned long * V_152 , struct V_31 * V_32 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_3 / sizeof( long ) ; V_153 ++ ) {
V_152 [ V_153 ] = F_51 ( V_32 ) ;
if ( F_91 ( V_152 [ V_153 ] == V_62 ) )
break;
F_121 ( V_152 + V_153 ) ;
}
}
int F_122 ( struct V_154 * V_155 )
{
if ( V_155 -> V_33 > V_97 + V_96 )
return 0 ;
if ( ! V_93 ) {
V_93 = F_3 ( V_136 , V_75 ) ;
if ( ! V_93 )
return - V_42 ;
}
if ( ! V_155 -> V_33 ) {
int error ;
error = F_119 ( (struct V_140 * ) V_93 ) ;
if ( error )
return error ;
V_155 -> V_93 = V_93 ;
F_22 ( & V_95 ) ;
F_22 ( & V_94 ) ;
} else if ( V_155 -> V_33 <= V_97 ) {
F_123 ( V_93 ) ;
F_120 ( V_93 , & V_95 ) ;
} else {
struct V_11 * V_11 ;
V_11 = F_70 ( F_51 ( & V_94 ) ) ;
if ( F_72 ( V_11 ) ) {
void * V_156 ;
V_156 = F_87 ( V_11 , V_91 ) ;
F_89 ( V_93 , V_156 ) ;
F_88 ( V_156 , V_91 ) ;
V_155 -> V_93 = V_93 ;
} else {
V_155 -> V_93 = F_83 ( V_11 ) ;
}
}
V_155 -> V_33 ++ ;
return V_3 ;
}
static int F_124 ( struct V_31 * V_32 )
{
struct V_46 * V_46 ;
unsigned long V_55 , V_82 ;
F_33 (zone) {
V_82 = V_46 -> V_49 + V_46 -> V_50 ;
for ( V_55 = V_46 -> V_49 ; V_55 < V_82 ; V_55 ++ )
if ( F_62 ( V_55 ) )
F_16 ( F_70 ( V_55 ) ) ;
}
F_22 ( V_32 ) ;
do {
V_55 = F_51 ( V_32 ) ;
if ( F_125 ( V_55 != V_62 ) ) {
if ( F_125 ( F_62 ( V_55 ) ) )
F_8 ( F_70 ( V_55 ) ) ;
else
return - V_60 ;
}
} while ( V_55 != V_62 );
V_9 = 0 ;
return 0 ;
}
static void
F_126 ( struct V_31 * V_85 , struct V_31 * V_86 )
{
unsigned long V_55 ;
F_22 ( V_86 ) ;
V_55 = F_51 ( V_86 ) ;
while ( V_55 != V_62 ) {
F_43 ( V_85 , V_55 ) ;
V_55 = F_51 ( V_86 ) ;
}
}
static int F_127 ( struct V_140 * V_141 )
{
char * V_157 ;
V_157 = F_117 ( V_141 ) ;
if ( ! V_157 && V_141 -> V_150 != V_150 )
V_157 = L_20 ;
if ( V_157 ) {
F_57 ( V_139 L_21 , V_157 ) ;
return - V_158 ;
}
return 0 ;
}
static int
F_128 ( struct V_140 * V_141 )
{
int error ;
V_98 = NULL ;
error = F_127 ( V_141 ) ;
if ( ! error ) {
V_96 = V_141 -> V_151 ;
V_97 = V_141 -> V_38 - V_141 -> V_151 - 1 ;
}
return error ;
}
static int F_129 ( unsigned long * V_152 , struct V_31 * V_32 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < V_3 / sizeof( long ) ; V_153 ++ ) {
if ( F_91 ( V_152 [ V_153 ] == V_62 ) )
break;
F_130 ( V_152 + V_153 ) ;
if ( F_50 ( V_32 , V_152 [ V_153 ] ) )
F_43 ( V_32 , V_152 [ V_153 ] ) ;
else
return - V_60 ;
}
return 0 ;
}
static unsigned int F_131 ( struct V_31 * V_32 )
{
unsigned long V_55 ;
unsigned int V_79 = 0 ;
F_22 ( V_32 ) ;
V_55 = F_51 ( V_32 ) ;
while ( V_55 != V_62 ) {
if ( F_72 ( F_70 ( V_55 ) ) )
V_79 ++ ;
V_55 = F_51 ( V_32 ) ;
}
return V_79 ;
}
static int
F_132 ( struct V_31 * V_32 , unsigned int * V_159 )
{
unsigned int V_138 ;
if ( F_38 ( V_32 , V_136 , V_10 ) )
return - V_42 ;
if ( F_110 ( V_10 ) )
return - V_42 ;
V_138 = F_66 () ;
if ( V_138 > * V_159 )
V_138 = * V_159 ;
else
* V_159 = V_138 ;
V_160 = 0 ;
while ( V_138 -- > 0 ) {
struct V_11 * V_11 ;
V_11 = F_11 ( V_107 ) ;
if ( ! F_5 ( V_11 ) ) {
F_43 ( V_32 , F_58 ( V_11 ) ) ;
V_160 ++ ;
}
F_7 ( V_11 ) ;
F_8 ( V_11 ) ;
}
F_22 ( V_32 ) ;
V_161 = V_32 ;
return 0 ;
}
static void *
F_133 ( struct V_11 * V_11 , struct V_19 * V_20 )
{
struct V_162 * V_163 ;
void * V_156 ;
if ( F_59 ( V_11 ) && F_5 ( V_11 ) ) {
V_164 = V_11 ;
return V_93 ;
}
V_163 = F_20 ( V_20 , sizeof( struct V_162 ) ) ;
if ( ! V_163 ) {
F_92 () ;
return F_134 ( - V_42 ) ;
}
V_163 -> V_165 = V_11 ;
if ( V_160 > 0 ) {
struct V_11 * V_166 ;
V_156 = V_93 ;
V_166 = F_70 ( F_51 ( V_161 ) ) ;
V_160 -- ;
V_164 = V_166 ;
V_163 -> F_89 = V_166 ;
} else {
V_156 = V_167 ;
V_167 = V_167 -> V_18 ;
V_163 -> F_89 = F_6 ( V_156 ) ;
}
V_163 -> V_18 = V_168 ;
V_168 = V_163 ;
return V_156 ;
}
static void F_135 ( void )
{
if ( V_164 ) {
void * V_85 ;
V_85 = F_87 ( V_164 , V_91 ) ;
F_89 ( V_85 , V_93 ) ;
F_88 ( V_85 , V_91 ) ;
V_164 = NULL ;
}
}
static inline int F_136 ( void )
{
return ! V_164 ;
}
static inline void F_137 ( void )
{
if ( V_161 )
F_40 ( V_161 , V_58 ) ;
if ( V_93 )
F_12 ( V_93 , V_58 ) ;
}
static inline int F_138 ( void ) { return 0 ; }
static unsigned int
F_131 ( struct V_31 * V_32 ) { return 0 ; }
static inline int
F_132 ( struct V_31 * V_32 , unsigned int * V_159 )
{
return 0 ;
}
static inline void *
F_133 ( struct V_11 * V_11 , struct V_19 * V_20 )
{
return F_134 ( - V_169 ) ;
}
static inline void F_135 ( void ) {}
static inline int F_136 ( void ) { return 1 ; }
static inline void F_137 ( void ) {}
static int
F_139 ( struct V_31 * V_170 , struct V_31 * V_32 )
{
unsigned int V_101 , V_134 ;
struct V_14 * V_171 , * V_17 ;
int error ;
F_12 ( V_93 , V_58 ) ;
V_93 = NULL ;
V_134 = F_131 ( V_32 ) ;
error = F_124 ( V_32 ) ;
if ( error )
goto Free;
error = F_38 ( V_170 , V_136 , V_10 ) ;
if ( error )
goto Free;
F_126 ( V_170 , V_32 ) ;
F_40 ( V_32 , V_172 ) ;
if ( V_134 > 0 ) {
error = F_132 ( V_32 , & V_134 ) ;
if ( error )
goto Free;
}
V_171 = NULL ;
V_101 = V_96 - V_134 - V_9 ;
V_101 = F_25 ( V_101 , V_173 ) ;
while ( V_101 > 0 ) {
V_17 = F_3 ( V_136 , V_10 ) ;
if ( ! V_17 ) {
error = - V_42 ;
goto Free;
}
V_17 -> V_18 = V_171 ;
V_171 = V_17 ;
V_101 -- ;
}
V_167 = NULL ;
V_101 = V_96 - V_134 - V_9 ;
while ( V_101 > 0 ) {
V_17 = (struct V_14 * ) F_4 ( V_136 ) ;
if ( ! V_17 ) {
error = - V_42 ;
goto Free;
}
if ( ! F_5 ( F_6 ( V_17 ) ) ) {
V_17 -> V_18 = V_167 ;
V_167 = V_17 ;
}
F_7 ( F_6 ( V_17 ) ) ;
F_8 ( F_6 ( V_17 ) ) ;
V_101 -- ;
}
while ( V_171 ) {
V_17 = V_171 -> V_18 ;
F_12 ( V_171 , V_58 ) ;
V_171 = V_17 ;
}
return 0 ;
Free:
F_92 () ;
return error ;
}
static void * F_140 ( struct V_31 * V_32 , struct V_19 * V_20 )
{
struct V_163 * V_163 ;
struct V_11 * V_11 ;
unsigned long V_55 = F_51 ( V_32 ) ;
if ( V_55 == V_62 )
return F_134 ( - V_60 ) ;
V_11 = F_70 ( V_55 ) ;
if ( F_72 ( V_11 ) )
return F_133 ( V_11 , V_20 ) ;
if ( F_59 ( V_11 ) && F_5 ( V_11 ) )
return F_83 ( V_11 ) ;
V_163 = F_20 ( V_20 , sizeof( struct V_163 ) ) ;
if ( ! V_163 ) {
F_92 () ;
return F_134 ( - V_42 ) ;
}
V_163 -> V_174 = F_83 ( V_11 ) ;
V_163 -> V_175 = V_167 ;
V_167 = V_167 -> V_18 ;
V_163 -> V_18 = V_98 ;
V_98 = V_163 ;
return V_163 -> V_175 ;
}
int F_141 ( struct V_154 * V_155 )
{
static struct V_19 V_20 ;
int error = 0 ;
if ( V_155 -> V_33 > 1 && V_155 -> V_33 > V_97 + V_96 )
return 0 ;
V_155 -> V_176 = 1 ;
if ( ! V_155 -> V_33 ) {
if ( ! V_93 )
V_93 = F_3 ( V_136 , V_75 ) ;
if ( ! V_93 )
return - V_42 ;
V_155 -> V_93 = V_93 ;
} else if ( V_155 -> V_33 == 1 ) {
error = F_128 ( V_93 ) ;
if ( error )
return error ;
error = F_38 ( & V_94 , V_136 , V_75 ) ;
if ( error )
return error ;
error = F_142 ( V_96 ) ;
if ( error )
return error ;
} else if ( V_155 -> V_33 <= V_97 + 1 ) {
error = F_129 ( V_93 , & V_94 ) ;
if ( error )
return error ;
if ( V_155 -> V_33 == V_97 + 1 ) {
error = F_139 ( & V_95 , & V_94 ) ;
if ( error )
return error ;
F_19 ( & V_20 , V_136 , V_10 ) ;
F_22 ( & V_95 ) ;
V_98 = NULL ;
V_155 -> V_93 = F_140 ( & V_95 , & V_20 ) ;
V_155 -> V_176 = 0 ;
if ( F_143 ( V_155 -> V_93 ) )
return F_144 ( V_155 -> V_93 ) ;
}
} else {
F_135 () ;
F_145 ( V_155 -> V_93 ) ;
V_155 -> V_93 = F_140 ( & V_95 , & V_20 ) ;
if ( F_143 ( V_155 -> V_93 ) )
return F_144 ( V_155 -> V_93 ) ;
if ( V_155 -> V_93 != V_93 )
V_155 -> V_176 = 0 ;
}
V_155 -> V_33 ++ ;
return V_3 ;
}
void F_146 ( struct V_154 * V_155 )
{
F_135 () ;
F_145 ( V_155 -> V_93 ) ;
F_147 () ;
if ( V_155 -> V_33 > 1 && V_155 -> V_33 > V_97 + V_96 ) {
F_40 ( & V_95 , V_58 ) ;
F_137 () ;
}
}
int F_148 ( struct V_154 * V_155 )
{
return ! ( ! V_96 || ! F_136 () ||
V_155 -> V_33 <= V_97 + V_96 ) ;
}
static inline void
F_149 ( struct V_11 * V_177 , struct V_11 * V_178 , void * V_152 )
{
void * V_179 , * V_180 ;
V_179 = F_87 ( V_177 , V_91 ) ;
V_180 = F_87 ( V_178 , V_92 ) ;
F_89 ( V_152 , V_179 ) ;
F_89 ( V_179 , V_180 ) ;
F_89 ( V_180 , V_152 ) ;
F_88 ( V_180 , V_92 ) ;
F_88 ( V_179 , V_91 ) ;
}
int F_150 ( void )
{
struct V_162 * V_163 = V_168 ;
void * V_152 ;
if ( ! V_163 )
return 0 ;
V_152 = F_3 ( V_136 , V_10 ) ;
if ( ! V_152 )
return - V_42 ;
while ( V_163 ) {
F_149 ( V_163 -> F_89 , V_163 -> V_165 , V_152 ) ;
V_163 = V_163 -> V_18 ;
}
F_12 ( V_152 , V_58 ) ;
return 0 ;
}
