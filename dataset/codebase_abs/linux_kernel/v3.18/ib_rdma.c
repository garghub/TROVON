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
static inline struct V_52 * F_43 ( struct V_25 * V_26 )
{
struct V_52 * V_53 = NULL ;
struct V_54 * V_55 ;
unsigned long * V_56 ;
F_44 () ;
V_56 = F_45 ( & V_57 ) ;
F_46 ( V_58 , V_56 ) ;
V_55 = F_47 ( & V_26 -> V_29 ) ;
if ( V_55 )
V_53 = F_48 ( V_55 , struct V_52 , V_59 ) ;
F_49 ( V_58 , V_56 ) ;
F_50 () ;
return V_53 ;
}
static inline void F_51 ( void )
{
int V_60 ;
unsigned long * V_56 ;
F_52 (cpu) {
V_56 = & F_53 ( V_57 , V_60 ) ;
while ( F_54 ( V_58 , V_56 ) )
F_55 () ;
}
}
static struct V_52 * F_56 ( struct V_1 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_47 ;
struct V_52 * V_53 = NULL ;
int V_61 = 0 , V_62 = 0 ;
if ( F_42 ( & V_26 -> V_63 ) >= V_26 -> V_44 / 10 )
F_57 ( & V_26 -> V_32 , 10 ) ;
while ( 1 ) {
V_53 = F_43 ( V_26 ) ;
if ( V_53 )
return V_53 ;
if ( F_58 ( & V_26 -> V_50 ) <= V_26 -> V_44 )
break;
F_59 ( & V_26 -> V_50 ) ;
if ( ++ V_62 > 2 ) {
F_60 ( V_64 ) ;
return F_32 ( - V_65 ) ;
}
F_60 ( V_66 ) ;
F_40 ( V_26 , 0 , & V_53 ) ;
if ( V_53 )
return V_53 ;
}
V_53 = F_61 ( sizeof( * V_53 ) , V_7 , F_62 ( V_3 ) ) ;
if ( ! V_53 ) {
V_61 = - V_8 ;
goto V_67;
}
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_68 = F_63 ( V_3 -> V_69 ,
( V_70 |
V_71 |
V_72 |
V_73 ) ,
& V_26 -> V_34 ) ;
if ( F_64 ( V_53 -> V_68 ) ) {
V_61 = F_65 ( V_53 -> V_68 ) ;
V_53 -> V_68 = NULL ;
F_66 ( V_74 L_1 , V_61 ) ;
goto V_67;
}
F_60 ( V_75 ) ;
return V_53 ;
V_67:
if ( V_53 ) {
if ( V_53 -> V_68 )
F_67 ( V_53 -> V_68 ) ;
F_14 ( V_53 ) ;
}
F_59 ( & V_26 -> V_50 ) ;
return F_32 ( V_61 ) ;
}
static int F_68 ( struct V_1 * V_3 , struct V_52 * V_53 ,
struct V_76 * V_77 , unsigned int V_78 )
{
struct V_79 * V_80 = V_3 -> V_80 ;
struct V_76 * V_81 = V_77 ;
T_2 V_82 = 0 ;
T_2 * V_83 ;
T_3 V_84 ;
int V_85 , V_86 ;
int V_87 , V_88 ;
int V_55 ;
V_86 = F_69 ( V_80 , V_77 , V_78 ,
V_89 ) ;
if ( F_70 ( ! V_86 ) ) {
F_66 ( V_74 L_2 ) ;
return - V_90 ;
}
V_84 = 0 ;
V_85 = 0 ;
for ( V_87 = 0 ; V_87 < V_86 ; ++ V_87 ) {
unsigned int V_91 = F_71 ( V_80 , & V_81 [ V_87 ] ) ;
T_2 V_92 = F_72 ( V_80 , & V_81 [ V_87 ] ) ;
if ( V_92 & ~ V_93 ) {
if ( V_87 > 0 )
return - V_94 ;
else
++ V_85 ;
}
if ( ( V_92 + V_91 ) & ~ V_93 ) {
if ( V_87 < V_86 - 1 )
return - V_94 ;
else
++ V_85 ;
}
V_84 += V_91 ;
}
V_85 += V_84 >> V_40 ;
if ( V_85 > V_36 )
return - V_94 ;
V_83 = F_73 ( sizeof( T_2 ) * V_85 , V_95 ,
F_62 ( V_3 ) ) ;
if ( ! V_83 )
return - V_8 ;
V_85 = 0 ;
for ( V_87 = 0 ; V_87 < V_86 ; ++ V_87 ) {
unsigned int V_91 = F_71 ( V_80 , & V_81 [ V_87 ] ) ;
T_2 V_92 = F_72 ( V_80 , & V_81 [ V_87 ] ) ;
for ( V_88 = 0 ; V_88 < V_91 ; V_88 += V_96 )
V_83 [ V_85 ++ ] =
( V_92 & V_93 ) + V_88 ;
}
V_55 = F_74 ( V_53 -> V_68 ,
V_83 , V_85 , V_82 ) ;
if ( V_55 )
goto V_97;
F_75 ( V_53 ) ;
V_53 -> V_77 = V_81 ;
V_53 -> V_98 = V_78 ;
V_53 -> V_86 = V_86 ;
V_53 -> V_99 ++ ;
F_60 ( V_100 ) ;
V_55 = 0 ;
V_97:
F_14 ( V_83 ) ;
return V_55 ;
}
void F_76 ( void * V_101 , int V_102 )
{
struct V_52 * V_53 = V_101 ;
struct V_1 * V_3 = V_53 -> V_103 ;
switch ( V_102 ) {
case V_104 :
F_77 ( V_3 -> V_80 , V_53 -> V_77 ,
V_53 -> V_86 , V_89 ) ;
break;
case V_105 :
F_78 ( V_3 -> V_80 , V_53 -> V_77 ,
V_53 -> V_86 , V_89 ) ;
break;
}
}
static void F_79 ( struct V_52 * V_53 )
{
struct V_1 * V_3 = V_53 -> V_103 ;
if ( V_53 -> V_86 ) {
F_80 ( V_3 -> V_80 ,
V_53 -> V_77 , V_53 -> V_98 ,
V_89 ) ;
V_53 -> V_86 = 0 ;
}
if ( V_53 -> V_98 ) {
unsigned int V_87 ;
for ( V_87 = 0 ; V_87 < V_53 -> V_98 ; ++ V_87 ) {
struct V_106 * V_106 = F_81 ( & V_53 -> V_77 [ V_87 ] ) ;
F_18 ( F_82 () ) ;
F_83 ( V_106 ) ;
F_84 ( V_106 ) ;
}
F_14 ( V_53 -> V_77 ) ;
V_53 -> V_77 = NULL ;
V_53 -> V_98 = 0 ;
}
}
static void F_75 ( struct V_52 * V_53 )
{
unsigned int V_107 = V_53 -> V_98 ;
F_79 ( V_53 ) ;
if ( V_107 ) {
struct V_1 * V_3 = V_53 -> V_103 ;
struct V_25 * V_26 = V_3 -> V_47 ;
F_85 ( V_107 , & V_26 -> V_51 ) ;
}
}
static inline unsigned int F_86 ( struct V_25 * V_26 , int V_108 )
{
unsigned int V_50 ;
V_50 = F_42 ( & V_26 -> V_50 ) ;
if ( V_108 )
return V_50 ;
return 0 ;
}
static void F_87 ( struct V_109 * V_110 , struct V_111 * V_10 )
{
struct V_52 * V_53 ;
struct V_54 * V_112 ;
struct V_54 * V_113 ;
V_112 = F_88 ( V_110 ) ;
while ( V_112 ) {
V_113 = V_112 -> V_113 ;
V_53 = F_48 ( V_112 , struct V_52 , V_59 ) ;
F_22 ( & V_53 -> V_114 , V_10 ) ;
V_112 = V_113 ;
}
}
static void F_89 ( struct V_25 * V_26 ,
struct V_111 * V_10 ,
struct V_54 * * V_115 ,
struct V_54 * * V_116 )
{
struct V_52 * V_53 ;
struct V_54 * V_117 = NULL ;
struct V_54 * * V_113 = V_115 ;
F_90 (ibmr, list, unmap_list) {
V_117 = & V_53 -> V_59 ;
* V_113 = V_117 ;
V_113 = & V_117 -> V_113 ;
}
* V_113 = NULL ;
* V_116 = V_117 ;
}
static int F_40 ( struct V_25 * V_26 ,
int V_108 , struct V_52 * * V_118 )
{
struct V_52 * V_53 , * V_113 ;
struct V_54 * V_119 ;
struct V_54 * V_120 ;
F_26 ( V_114 ) ;
F_26 ( V_121 ) ;
unsigned long V_122 = 0 ;
unsigned int V_123 = 0 , V_124 = 0 , V_125 ;
int V_55 = 0 ;
F_60 ( V_126 ) ;
if ( V_118 ) {
F_91 ( V_127 ) ;
while( ! F_92 ( & V_26 -> V_30 ) ) {
V_53 = F_43 ( V_26 ) ;
if ( V_53 ) {
* V_118 = V_53 ;
F_93 ( & V_26 -> V_31 , & V_127 ) ;
goto V_128;
}
F_94 ( & V_26 -> V_31 , & V_127 ,
V_129 ) ;
if ( F_95 ( & V_26 -> V_29 ) )
F_96 () ;
V_53 = F_43 ( V_26 ) ;
if ( V_53 ) {
* V_118 = V_53 ;
F_93 ( & V_26 -> V_31 , & V_127 ) ;
goto V_128;
}
}
F_93 ( & V_26 -> V_31 , & V_127 ) ;
} else
F_97 ( & V_26 -> V_30 ) ;
if ( V_118 ) {
V_53 = F_43 ( V_26 ) ;
if ( V_53 ) {
* V_118 = V_53 ;
goto V_97;
}
}
F_87 ( & V_26 -> V_28 , & V_114 ) ;
F_87 ( & V_26 -> V_27 , & V_114 ) ;
if ( V_108 )
F_87 ( & V_26 -> V_29 , & V_114 ) ;
V_125 = F_86 ( V_26 , V_108 ) ;
if ( F_19 ( & V_114 ) )
goto V_97;
F_90 (ibmr, &unmap_list, unmap_list)
F_98 ( & V_53 -> V_68 -> V_10 , & V_121 ) ;
V_55 = F_99 ( & V_121 ) ;
if ( V_55 )
F_66 ( V_74 L_3 , V_55 ) ;
F_28 (ibmr, next, &unmap_list, unmap_list) {
V_122 += V_53 -> V_98 ;
F_79 ( V_53 ) ;
if ( V_123 < V_125 || V_53 -> V_99 >= V_26 -> V_34 . V_37 ) {
F_60 ( V_130 ) ;
F_20 ( & V_53 -> V_114 ) ;
F_67 ( V_53 -> V_68 ) ;
F_14 ( V_53 ) ;
V_123 ++ ;
}
V_124 ++ ;
}
if ( ! F_19 ( & V_114 ) ) {
F_51 () ;
F_89 ( V_26 , & V_114 , & V_119 , & V_120 ) ;
if ( V_118 )
* V_118 = F_48 ( V_119 , struct V_52 , V_59 ) ;
if ( V_119 -> V_113 )
F_100 ( V_119 -> V_113 , V_120 , & V_26 -> V_29 ) ;
}
F_85 ( V_122 , & V_26 -> V_51 ) ;
F_85 ( V_124 , & V_26 -> V_63 ) ;
F_85 ( V_123 , & V_26 -> V_50 ) ;
V_97:
F_101 ( & V_26 -> V_30 ) ;
if ( F_102 ( & V_26 -> V_31 ) )
F_103 ( & V_26 -> V_31 ) ;
V_128:
return V_55 ;
}
static void V_33 ( struct V_131 * V_132 )
{
struct V_25 * V_26 = F_104 ( V_132 , struct V_25 , V_32 . V_132 ) ;
F_40 ( V_26 , 0 , NULL ) ;
}
void F_105 ( void * V_101 , int V_133 )
{
struct V_52 * V_53 = V_101 ;
struct V_1 * V_3 = V_53 -> V_103 ;
struct V_25 * V_26 = V_3 -> V_47 ;
F_106 ( L_4 , V_53 -> V_98 ) ;
if ( V_53 -> V_99 >= V_26 -> V_34 . V_37 )
F_107 ( & V_53 -> V_59 , & V_26 -> V_28 ) ;
else
F_107 ( & V_53 -> V_59 , & V_26 -> V_27 ) ;
F_108 ( V_53 -> V_98 , & V_26 -> V_51 ) ;
F_4 ( & V_26 -> V_63 ) ;
if ( F_42 ( & V_26 -> V_51 ) >= V_26 -> V_41 ||
F_42 ( & V_26 -> V_63 ) >= V_26 -> V_44 / 10 )
F_57 ( & V_26 -> V_32 , 10 ) ;
if ( V_133 ) {
if ( F_109 ( ! F_110 () ) ) {
F_40 ( V_26 , 0 , NULL ) ;
} else {
F_57 ( & V_26 -> V_32 , 10 ) ;
}
}
F_16 ( V_3 ) ;
}
void F_111 ( void )
{
struct V_1 * V_3 ;
F_112 ( & V_134 ) ;
F_90 (rds_ibdev, &rds_ib_devices, list) {
struct V_25 * V_26 = V_3 -> V_47 ;
if ( V_26 )
F_40 ( V_26 , 0 , NULL ) ;
}
F_113 ( & V_134 ) ;
}
void * F_114 ( struct V_76 * V_77 , unsigned long V_78 ,
struct V_135 * V_136 , T_3 * V_137 )
{
struct V_1 * V_3 ;
struct V_52 * V_53 = NULL ;
int V_55 ;
V_3 = F_1 ( V_136 -> V_138 ) ;
if ( ! V_3 ) {
V_55 = - V_139 ;
goto V_97;
}
if ( ! V_3 -> V_47 ) {
V_55 = - V_139 ;
goto V_97;
}
V_53 = F_56 ( V_3 ) ;
if ( F_64 ( V_53 ) )
return V_53 ;
V_55 = F_68 ( V_3 , V_53 , V_77 , V_78 ) ;
if ( V_55 == 0 )
* V_137 = V_53 -> V_68 -> V_140 ;
else
F_66 ( V_74 L_5 , V_55 ) ;
V_53 -> V_103 = V_3 ;
V_3 = NULL ;
V_97:
if ( V_55 ) {
if ( V_53 )
F_105 ( V_53 , 0 ) ;
V_53 = F_32 ( V_55 ) ;
}
if ( V_3 )
F_16 ( V_3 ) ;
return V_53 ;
}
