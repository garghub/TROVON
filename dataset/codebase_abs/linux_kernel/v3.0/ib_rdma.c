static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
F_2 () ;
F_3 (rds_ibdev, &rds_ib_devices, list) {
F_3 (i_ipaddr, &rds_ibdev->ipaddr_list, list) {
if ( V_5 -> V_2 == V_2 ) {
F_4 ( & V_3 -> V_6 ) ;
F_5 () ;
return V_3 ;
}
}
}
F_5 () ;
return NULL ;
}
static int F_6 ( struct V_1 * V_3 , T_1 V_2 )
{
struct V_4 * V_5 ;
V_5 = F_7 ( sizeof *V_5 , V_7 ) ;
if ( ! V_5 )
return - V_8 ;
V_5 -> V_2 = V_2 ;
F_8 ( & V_3 -> V_9 ) ;
F_9 ( & V_5 -> V_10 , & V_3 -> V_11 ) ;
F_10 ( & V_3 -> V_9 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_3 , T_1 V_2 )
{
struct V_4 * V_5 ;
struct V_4 * V_12 = NULL ;
F_8 ( & V_3 -> V_9 ) ;
F_3 (i_ipaddr, &rds_ibdev->ipaddr_list, list) {
if ( V_5 -> V_2 == V_2 ) {
F_12 ( & V_5 -> V_10 ) ;
V_12 = V_5 ;
break;
}
}
F_10 ( & V_3 -> V_9 ) ;
if ( V_12 ) {
F_13 () ;
F_14 ( V_12 ) ;
}
}
int F_15 ( struct V_1 * V_3 , T_1 V_2 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 ) {
F_11 ( V_13 , V_2 ) ;
F_16 ( V_13 ) ;
}
return F_6 ( V_3 , V_2 ) ;
}
void F_17 ( struct V_1 * V_3 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_8 ( & V_19 ) ;
F_18 ( F_19 ( & V_20 ) ) ;
F_18 ( F_19 ( & V_17 -> V_21 ) ) ;
F_20 ( & V_17 -> V_21 ) ;
F_21 ( & V_3 -> V_9 ) ;
F_22 ( & V_17 -> V_21 , & V_3 -> V_22 ) ;
F_23 ( & V_3 -> V_9 ) ;
F_10 ( & V_19 ) ;
V_17 -> V_3 = V_3 ;
F_4 ( & V_3 -> V_6 ) ;
}
void F_24 ( struct V_1 * V_3 , struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
F_21 ( & V_19 ) ;
F_8 ( & V_3 -> V_9 ) ;
F_18 ( F_19 ( & V_17 -> V_21 ) ) ;
F_20 ( & V_17 -> V_21 ) ;
F_10 ( & V_3 -> V_9 ) ;
F_22 ( & V_17 -> V_21 , & V_20 ) ;
F_23 ( & V_19 ) ;
V_17 -> V_3 = NULL ;
F_16 ( V_3 ) ;
}
void F_25 ( void )
{
struct V_16 * V_17 , * V_23 ;
F_26 ( V_24 ) ;
F_8 ( & V_19 ) ;
F_27 ( & V_20 , & V_24 ) ;
F_10 ( & V_19 ) ;
F_28 (ic, _ic, &tmp_list, ib_node)
F_29 ( V_17 -> V_15 ) ;
}
struct V_25 * F_30 ( struct V_1 * V_3 )
{
struct V_25 * V_26 ;
V_26 = F_31 ( sizeof( * V_26 ) , V_7 ) ;
if ( ! V_26 )
return F_32 ( - V_8 ) ;
F_33 ( & V_26 -> V_27 ) ;
F_33 ( & V_26 -> V_28 ) ;
F_33 ( & V_26 -> V_29 ) ;
F_34 ( & V_26 -> V_30 ) ;
F_35 ( & V_26 -> V_31 ) ;
F_36 ( & V_26 -> V_32 , V_33 ) ;
V_26 -> V_34 . V_35 = V_36 ;
V_26 -> V_34 . V_37 = V_3 -> V_38 ;
V_26 -> V_34 . V_39 = V_40 ;
V_26 -> V_41 = V_3 -> V_42 * V_36 / 4 ;
V_26 -> V_43 = V_3 -> V_42 * 3 / 4 ;
V_26 -> V_44 = V_3 -> V_42 ;
return V_26 ;
}
void F_37 ( struct V_1 * V_3 , struct V_45 * V_46 )
{
struct V_25 * V_26 = V_3 -> V_47 ;
V_46 -> V_48 = V_26 -> V_44 ;
V_46 -> V_49 = V_26 -> V_34 . V_35 ;
}
void F_38 ( struct V_25 * V_26 )
{
F_39 ( & V_26 -> V_32 ) ;
F_40 ( V_26 , 1 , NULL ) ;
F_41 ( F_42 ( & V_26 -> V_50 ) ) ;
F_41 ( F_42 ( & V_26 -> V_51 ) ) ;
F_14 ( V_26 ) ;
}
static void F_43 ( struct V_25 * V_26 , struct V_52 * V_53 ,
struct V_54 * * V_55 )
{
struct V_52 * V_56 ;
V_56 = F_44 ( V_53 ) ;
* V_55 = F_45 ( V_56 , struct V_54 , V_57 ) ;
}
static inline struct V_54 * F_46 ( struct V_25 * V_26 )
{
struct V_54 * V_58 = NULL ;
struct V_52 * V_59 ;
unsigned long * V_60 ;
F_47 () ;
V_60 = & F_48 ( V_61 ) ;
F_49 ( V_62 , V_60 ) ;
V_59 = F_50 ( & V_26 -> V_29 ) ;
if ( V_59 )
V_58 = F_45 ( V_59 , struct V_54 , V_57 ) ;
F_51 ( V_62 , V_60 ) ;
F_52 () ;
return V_58 ;
}
static inline void F_53 ( void )
{
int V_63 ;
unsigned long * V_60 ;
F_54 (cpu) {
V_60 = & F_55 ( V_61 , V_63 ) ;
while ( F_56 ( V_62 , V_60 ) )
F_57 () ;
}
}
static struct V_54 * F_58 ( struct V_1 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_47 ;
struct V_54 * V_58 = NULL ;
int V_64 = 0 , V_65 = 0 ;
if ( F_42 ( & V_26 -> V_66 ) >= V_26 -> V_44 / 10 )
F_59 ( & V_26 -> V_32 , 10 ) ;
while ( 1 ) {
V_58 = F_46 ( V_26 ) ;
if ( V_58 )
return V_58 ;
if ( F_60 ( & V_26 -> V_50 ) <= V_26 -> V_44 )
break;
F_61 ( & V_26 -> V_50 ) ;
if ( ++ V_65 > 2 ) {
F_62 ( V_67 ) ;
return F_32 ( - V_68 ) ;
}
F_62 ( V_69 ) ;
F_40 ( V_26 , 0 , & V_58 ) ;
if ( V_58 )
return V_58 ;
}
V_58 = F_63 ( sizeof( * V_58 ) , V_7 , F_64 ( V_3 ) ) ;
if ( ! V_58 ) {
V_64 = - V_8 ;
goto V_70;
}
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
V_58 -> V_71 = F_65 ( V_3 -> V_72 ,
( V_73 |
V_74 |
V_75 |
V_76 ) ,
& V_26 -> V_34 ) ;
if ( F_66 ( V_58 -> V_71 ) ) {
V_64 = F_67 ( V_58 -> V_71 ) ;
V_58 -> V_71 = NULL ;
F_68 ( V_77 L_1 , V_64 ) ;
goto V_70;
}
F_62 ( V_78 ) ;
return V_58 ;
V_70:
if ( V_58 ) {
if ( V_58 -> V_71 )
F_69 ( V_58 -> V_71 ) ;
F_14 ( V_58 ) ;
}
F_61 ( & V_26 -> V_50 ) ;
return F_32 ( V_64 ) ;
}
static int F_70 ( struct V_1 * V_3 , struct V_54 * V_58 ,
struct V_79 * V_80 , unsigned int V_81 )
{
struct V_82 * V_83 = V_3 -> V_83 ;
struct V_79 * V_84 = V_80 ;
T_2 V_85 = 0 ;
T_2 * V_86 ;
T_3 V_87 ;
int V_88 , V_89 ;
int V_90 , V_91 ;
int V_59 ;
V_89 = F_71 ( V_83 , V_80 , V_81 ,
V_92 ) ;
if ( F_72 ( ! V_89 ) ) {
F_68 ( V_77 L_2 ) ;
return - V_93 ;
}
V_87 = 0 ;
V_88 = 0 ;
for ( V_90 = 0 ; V_90 < V_89 ; ++ V_90 ) {
unsigned int V_94 = F_73 ( V_83 , & V_84 [ V_90 ] ) ;
T_2 V_95 = F_74 ( V_83 , & V_84 [ V_90 ] ) ;
if ( V_95 & ~ V_96 ) {
if ( V_90 > 0 )
return - V_97 ;
else
++ V_88 ;
}
if ( ( V_95 + V_94 ) & ~ V_96 ) {
if ( V_90 < V_89 - 1 )
return - V_97 ;
else
++ V_88 ;
}
V_87 += V_94 ;
}
V_88 += V_87 >> V_40 ;
if ( V_88 > V_36 )
return - V_97 ;
V_86 = F_75 ( sizeof( T_2 ) * V_88 , V_98 ,
F_64 ( V_3 ) ) ;
if ( ! V_86 )
return - V_8 ;
V_88 = 0 ;
for ( V_90 = 0 ; V_90 < V_89 ; ++ V_90 ) {
unsigned int V_94 = F_73 ( V_83 , & V_84 [ V_90 ] ) ;
T_2 V_95 = F_74 ( V_83 , & V_84 [ V_90 ] ) ;
for ( V_91 = 0 ; V_91 < V_94 ; V_91 += V_99 )
V_86 [ V_88 ++ ] =
( V_95 & V_96 ) + V_91 ;
}
V_59 = F_76 ( V_58 -> V_71 ,
V_86 , V_88 , V_85 ) ;
if ( V_59 )
goto V_100;
F_77 ( V_58 ) ;
V_58 -> V_80 = V_84 ;
V_58 -> V_101 = V_81 ;
V_58 -> V_89 = V_89 ;
V_58 -> V_102 ++ ;
F_62 ( V_103 ) ;
V_59 = 0 ;
V_100:
F_14 ( V_86 ) ;
return V_59 ;
}
void F_78 ( void * V_104 , int V_105 )
{
struct V_54 * V_58 = V_104 ;
struct V_1 * V_3 = V_58 -> V_106 ;
switch ( V_105 ) {
case V_107 :
F_79 ( V_3 -> V_83 , V_58 -> V_80 ,
V_58 -> V_89 , V_92 ) ;
break;
case V_108 :
F_80 ( V_3 -> V_83 , V_58 -> V_80 ,
V_58 -> V_89 , V_92 ) ;
break;
}
}
static void F_81 ( struct V_54 * V_58 )
{
struct V_1 * V_3 = V_58 -> V_106 ;
if ( V_58 -> V_89 ) {
F_82 ( V_3 -> V_83 ,
V_58 -> V_80 , V_58 -> V_101 ,
V_92 ) ;
V_58 -> V_89 = 0 ;
}
if ( V_58 -> V_101 ) {
unsigned int V_90 ;
for ( V_90 = 0 ; V_90 < V_58 -> V_101 ; ++ V_90 ) {
struct V_109 * V_109 = F_83 ( & V_58 -> V_80 [ V_90 ] ) ;
F_18 ( F_84 () ) ;
F_85 ( V_109 ) ;
F_86 ( V_109 ) ;
}
F_14 ( V_58 -> V_80 ) ;
V_58 -> V_80 = NULL ;
V_58 -> V_101 = 0 ;
}
}
static void F_77 ( struct V_54 * V_58 )
{
unsigned int V_110 = V_58 -> V_101 ;
F_81 ( V_58 ) ;
if ( V_110 ) {
struct V_1 * V_3 = V_58 -> V_106 ;
struct V_25 * V_26 = V_3 -> V_47 ;
F_87 ( V_110 , & V_26 -> V_51 ) ;
}
}
static inline unsigned int F_88 ( struct V_25 * V_26 , int V_111 )
{
unsigned int V_50 ;
V_50 = F_42 ( & V_26 -> V_50 ) ;
if ( V_111 )
return V_50 ;
return 0 ;
}
static void F_89 ( struct V_52 * V_57 , struct V_112 * V_10 )
{
struct V_54 * V_58 ;
struct V_52 V_113 ;
struct V_52 * V_114 ;
struct V_52 * V_115 ;
V_113 . V_115 = NULL ;
F_90 ( V_57 , & V_113 ) ;
V_114 = V_113 . V_115 ;
while ( V_114 ) {
V_115 = V_114 -> V_115 ;
V_58 = F_45 ( V_114 , struct V_54 , V_57 ) ;
F_22 ( & V_58 -> V_116 , V_10 ) ;
V_114 = V_115 ;
}
}
static void F_91 ( struct V_25 * V_26 ,
struct V_112 * V_10 , struct V_52 * V_57 ,
struct V_52 * * V_117 )
{
struct V_54 * V_58 ;
struct V_52 * V_118 = V_57 ;
struct V_52 * V_119 = NULL ;
F_92 (ibmr, list, unmap_list) {
V_119 = & V_58 -> V_57 ;
V_119 -> V_115 = NULL ;
V_118 -> V_115 = V_119 ;
V_118 = V_119 ;
}
* V_117 = V_119 ;
}
static int F_40 ( struct V_25 * V_26 ,
int V_111 , struct V_54 * * V_55 )
{
struct V_54 * V_58 , * V_115 ;
struct V_52 V_120 ;
struct V_52 * V_121 ;
F_26 ( V_116 ) ;
F_26 ( V_122 ) ;
unsigned long V_123 = 0 ;
unsigned int V_124 = 0 , V_125 = 0 , V_126 ;
int V_59 = 0 ;
F_62 ( V_127 ) ;
if ( V_55 ) {
F_93 ( V_128 ) ;
while( ! F_94 ( & V_26 -> V_30 ) ) {
V_58 = F_46 ( V_26 ) ;
if ( V_58 ) {
* V_55 = V_58 ;
F_95 ( & V_26 -> V_31 , & V_128 ) ;
goto V_129;
}
F_96 ( & V_26 -> V_31 , & V_128 ,
V_130 ) ;
if ( F_97 ( & V_26 -> V_29 ) )
F_98 () ;
V_58 = F_46 ( V_26 ) ;
if ( V_58 ) {
* V_55 = V_58 ;
F_95 ( & V_26 -> V_31 , & V_128 ) ;
goto V_129;
}
}
F_95 ( & V_26 -> V_31 , & V_128 ) ;
} else
F_99 ( & V_26 -> V_30 ) ;
if ( V_55 ) {
V_58 = F_46 ( V_26 ) ;
if ( V_58 ) {
* V_55 = V_58 ;
goto V_100;
}
}
F_89 ( & V_26 -> V_28 , & V_116 ) ;
F_89 ( & V_26 -> V_27 , & V_116 ) ;
if ( V_111 )
F_89 ( & V_26 -> V_29 , & V_116 ) ;
V_126 = F_88 ( V_26 , V_111 ) ;
if ( F_19 ( & V_116 ) )
goto V_100;
F_92 (ibmr, &unmap_list, unmap_list)
F_100 ( & V_58 -> V_71 -> V_10 , & V_122 ) ;
V_59 = F_101 ( & V_122 ) ;
if ( V_59 )
F_68 ( V_77 L_3 , V_59 ) ;
F_28 (ibmr, next, &unmap_list, unmap_list) {
V_123 += V_58 -> V_101 ;
F_81 ( V_58 ) ;
if ( V_124 < V_126 || V_58 -> V_102 >= V_26 -> V_34 . V_37 ) {
F_62 ( V_131 ) ;
F_20 ( & V_58 -> V_116 ) ;
F_69 ( V_58 -> V_71 ) ;
F_14 ( V_58 ) ;
V_124 ++ ;
}
V_125 ++ ;
}
if ( ! F_19 ( & V_116 ) ) {
F_53 () ;
F_91 ( V_26 , & V_116 , & V_120 , & V_121 ) ;
if ( V_55 )
F_43 ( V_26 , & V_120 , V_55 ) ;
if ( ! F_97 ( & V_120 ) )
F_102 ( V_120 . V_115 , V_121 , & V_26 -> V_29 ) ;
}
F_87 ( V_123 , & V_26 -> V_51 ) ;
F_87 ( V_125 , & V_26 -> V_66 ) ;
F_87 ( V_124 , & V_26 -> V_50 ) ;
V_100:
F_103 ( & V_26 -> V_30 ) ;
if ( F_104 ( & V_26 -> V_31 ) )
F_105 ( & V_26 -> V_31 ) ;
V_129:
return V_59 ;
}
static void V_33 ( struct V_132 * V_133 )
{
struct V_25 * V_26 = F_106 ( V_133 , struct V_25 , V_32 . V_133 ) ;
F_40 ( V_26 , 0 , NULL ) ;
}
void F_107 ( void * V_104 , int V_134 )
{
struct V_54 * V_58 = V_104 ;
struct V_1 * V_3 = V_58 -> V_106 ;
struct V_25 * V_26 = V_3 -> V_47 ;
F_108 ( L_4 , V_58 -> V_101 ) ;
if ( V_58 -> V_102 >= V_26 -> V_34 . V_37 )
F_102 ( & V_58 -> V_57 , & V_58 -> V_57 , & V_26 -> V_28 ) ;
else
F_102 ( & V_58 -> V_57 , & V_58 -> V_57 , & V_26 -> V_27 ) ;
F_109 ( V_58 -> V_101 , & V_26 -> V_51 ) ;
F_4 ( & V_26 -> V_66 ) ;
if ( F_42 ( & V_26 -> V_51 ) >= V_26 -> V_41 ||
F_42 ( & V_26 -> V_66 ) >= V_26 -> V_44 / 10 )
F_59 ( & V_26 -> V_32 , 10 ) ;
if ( V_134 ) {
if ( F_110 ( ! F_111 () ) ) {
F_40 ( V_26 , 0 , NULL ) ;
} else {
F_59 ( & V_26 -> V_32 , 10 ) ;
}
}
F_16 ( V_3 ) ;
}
void F_112 ( void )
{
struct V_1 * V_3 ;
F_113 ( & V_135 ) ;
F_92 (rds_ibdev, &rds_ib_devices, list) {
struct V_25 * V_26 = V_3 -> V_47 ;
if ( V_26 )
F_40 ( V_26 , 0 , NULL ) ;
}
F_114 ( & V_135 ) ;
}
void * F_115 ( struct V_79 * V_80 , unsigned long V_81 ,
struct V_136 * V_137 , T_3 * V_138 )
{
struct V_1 * V_3 ;
struct V_54 * V_58 = NULL ;
int V_59 ;
V_3 = F_1 ( V_137 -> V_139 ) ;
if ( ! V_3 ) {
V_59 = - V_140 ;
goto V_100;
}
if ( ! V_3 -> V_47 ) {
V_59 = - V_140 ;
goto V_100;
}
V_58 = F_58 ( V_3 ) ;
if ( F_66 ( V_58 ) )
return V_58 ;
V_59 = F_70 ( V_3 , V_58 , V_80 , V_81 ) ;
if ( V_59 == 0 )
* V_138 = V_58 -> V_71 -> V_141 ;
else
F_68 ( V_77 L_5 , V_59 ) ;
V_58 -> V_106 = V_3 ;
V_3 = NULL ;
V_100:
if ( V_59 ) {
if ( V_58 )
F_107 ( V_58 , 0 ) ;
V_58 = F_32 ( V_59 ) ;
}
if ( V_3 )
F_16 ( V_3 ) ;
return V_58 ;
}
