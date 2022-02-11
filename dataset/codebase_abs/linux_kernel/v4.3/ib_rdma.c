int F_1 ( void )
{
V_1 = F_2 ( L_1 ) ;
if ( ! V_1 )
return - V_2 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static struct V_3 * F_5 ( T_1 V_4 )
{
struct V_3 * V_5 ;
struct V_6 * V_7 ;
F_6 () ;
F_7 (rds_ibdev, &rds_ib_devices, list) {
F_7 (i_ipaddr, &rds_ibdev->ipaddr_list, list) {
if ( V_7 -> V_4 == V_4 ) {
F_8 ( & V_5 -> V_8 ) ;
F_9 () ;
return V_5 ;
}
}
}
F_9 () ;
return NULL ;
}
static int F_10 ( struct V_3 * V_5 , T_1 V_4 )
{
struct V_6 * V_7 ;
V_7 = F_11 ( sizeof *V_7 , V_9 ) ;
if ( ! V_7 )
return - V_2 ;
V_7 -> V_4 = V_4 ;
F_12 ( & V_5 -> V_10 ) ;
F_13 ( & V_7 -> V_11 , & V_5 -> V_12 ) ;
F_14 ( & V_5 -> V_10 ) ;
return 0 ;
}
static void F_15 ( struct V_3 * V_5 , T_1 V_4 )
{
struct V_6 * V_7 ;
struct V_6 * V_13 = NULL ;
F_12 ( & V_5 -> V_10 ) ;
F_7 (i_ipaddr, &rds_ibdev->ipaddr_list, list) {
if ( V_7 -> V_4 == V_4 ) {
F_16 ( & V_7 -> V_11 ) ;
V_13 = V_7 ;
break;
}
}
F_14 ( & V_5 -> V_10 ) ;
if ( V_13 ) {
F_17 () ;
F_18 ( V_13 ) ;
}
}
int F_19 ( struct V_3 * V_5 , T_1 V_4 )
{
struct V_3 * V_14 ;
V_14 = F_5 ( V_4 ) ;
if ( ! V_14 )
return F_10 ( V_5 , V_4 ) ;
if ( V_14 != V_5 ) {
F_15 ( V_14 , V_4 ) ;
F_20 ( V_14 ) ;
return F_10 ( V_5 , V_4 ) ;
}
F_20 ( V_14 ) ;
return 0 ;
}
void F_21 ( struct V_3 * V_5 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
F_12 ( & V_20 ) ;
F_22 ( F_23 ( & V_21 ) ) ;
F_22 ( F_23 ( & V_18 -> V_22 ) ) ;
F_24 ( & V_18 -> V_22 ) ;
F_25 ( & V_5 -> V_10 ) ;
F_26 ( & V_18 -> V_22 , & V_5 -> V_23 ) ;
F_27 ( & V_5 -> V_10 ) ;
F_14 ( & V_20 ) ;
V_18 -> V_5 = V_5 ;
F_8 ( & V_5 -> V_8 ) ;
}
void F_28 ( struct V_3 * V_5 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
F_25 ( & V_20 ) ;
F_12 ( & V_5 -> V_10 ) ;
F_22 ( F_23 ( & V_18 -> V_22 ) ) ;
F_24 ( & V_18 -> V_22 ) ;
F_14 ( & V_5 -> V_10 ) ;
F_26 ( & V_18 -> V_22 , & V_21 ) ;
F_27 ( & V_20 ) ;
V_18 -> V_5 = NULL ;
F_20 ( V_5 ) ;
}
void F_29 ( void )
{
struct V_17 * V_18 , * V_24 ;
F_30 ( V_25 ) ;
F_12 ( & V_20 ) ;
F_31 ( & V_21 , & V_25 ) ;
F_14 ( & V_20 ) ;
F_32 (ic, _ic, &tmp_list, ib_node)
F_33 ( V_18 -> V_16 ) ;
}
struct V_26 * F_34 ( struct V_3 * V_5 )
{
struct V_26 * V_27 ;
V_27 = F_35 ( sizeof( * V_27 ) , V_9 ) ;
if ( ! V_27 )
return F_36 ( - V_2 ) ;
F_37 ( & V_27 -> V_28 ) ;
F_37 ( & V_27 -> V_29 ) ;
F_37 ( & V_27 -> V_30 ) ;
F_38 ( & V_27 -> V_31 ) ;
F_39 ( & V_27 -> V_32 ) ;
F_40 ( & V_27 -> V_33 , V_34 ) ;
V_27 -> V_35 . V_36 = V_37 ;
V_27 -> V_35 . V_38 = V_5 -> V_39 ;
V_27 -> V_35 . V_40 = V_41 ;
V_27 -> V_42 = V_5 -> V_43 * V_37 / 4 ;
V_27 -> V_44 = V_5 -> V_43 * 3 / 4 ;
V_27 -> V_45 = V_5 -> V_43 ;
return V_27 ;
}
void F_41 ( struct V_3 * V_5 , struct V_46 * V_47 )
{
struct V_26 * V_27 = V_5 -> V_48 ;
V_47 -> V_49 = V_27 -> V_45 ;
V_47 -> V_50 = V_27 -> V_35 . V_36 ;
}
void F_42 ( struct V_26 * V_27 )
{
F_43 ( & V_27 -> V_33 ) ;
F_44 ( V_27 , 1 , NULL ) ;
F_45 ( F_46 ( & V_27 -> V_51 ) ) ;
F_45 ( F_46 ( & V_27 -> V_52 ) ) ;
F_18 ( V_27 ) ;
}
static inline struct V_53 * F_47 ( struct V_26 * V_27 )
{
struct V_53 * V_54 = NULL ;
struct V_55 * V_56 ;
unsigned long * V_57 ;
F_48 () ;
V_57 = F_49 ( & V_58 ) ;
F_50 ( V_59 , V_57 ) ;
V_56 = F_51 ( & V_27 -> V_30 ) ;
if ( V_56 )
V_54 = F_52 ( V_56 , struct V_53 , V_60 ) ;
F_53 ( V_59 , V_57 ) ;
F_54 () ;
return V_54 ;
}
static inline void F_55 ( void )
{
int V_61 ;
unsigned long * V_57 ;
F_56 (cpu) {
V_57 = & F_57 ( V_58 , V_61 ) ;
while ( F_58 ( V_59 , V_57 ) )
F_59 () ;
}
}
static struct V_53 * F_60 ( struct V_3 * V_5 )
{
struct V_26 * V_27 = V_5 -> V_48 ;
struct V_53 * V_54 = NULL ;
int V_62 = 0 , V_63 = 0 ;
if ( F_46 ( & V_27 -> V_64 ) >= V_27 -> V_45 / 10 )
F_61 ( & V_27 -> V_33 , 10 ) ;
while ( 1 ) {
V_54 = F_47 ( V_27 ) ;
if ( V_54 )
return V_54 ;
if ( F_62 ( & V_27 -> V_51 ) <= V_27 -> V_45 )
break;
F_63 ( & V_27 -> V_51 ) ;
if ( ++ V_63 > 2 ) {
F_64 ( V_65 ) ;
return F_36 ( - V_66 ) ;
}
F_64 ( V_67 ) ;
F_44 ( V_27 , 0 , & V_54 ) ;
if ( V_54 )
return V_54 ;
}
V_54 = F_65 ( sizeof( * V_54 ) , V_9 , F_66 ( V_5 ) ) ;
if ( ! V_54 ) {
V_62 = - V_2 ;
goto V_68;
}
V_54 -> V_69 = F_67 ( V_5 -> V_70 ,
( V_71 |
V_72 |
V_73 |
V_74 ) ,
& V_27 -> V_35 ) ;
if ( F_68 ( V_54 -> V_69 ) ) {
V_62 = F_69 ( V_54 -> V_69 ) ;
V_54 -> V_69 = NULL ;
F_70 ( V_75 L_2 , V_62 ) ;
goto V_68;
}
F_64 ( V_76 ) ;
return V_54 ;
V_68:
if ( V_54 ) {
if ( V_54 -> V_69 )
F_71 ( V_54 -> V_69 ) ;
F_18 ( V_54 ) ;
}
F_63 ( & V_27 -> V_51 ) ;
return F_36 ( V_62 ) ;
}
static int F_72 ( struct V_3 * V_5 , struct V_53 * V_54 ,
struct V_77 * V_78 , unsigned int V_79 )
{
struct V_80 * V_81 = V_5 -> V_81 ;
struct V_77 * V_82 = V_78 ;
T_2 V_83 = 0 ;
T_2 * V_84 ;
T_3 V_85 ;
int V_86 , V_87 ;
int V_88 , V_89 ;
int V_56 ;
V_87 = F_73 ( V_81 , V_78 , V_79 ,
V_90 ) ;
if ( F_74 ( ! V_87 ) ) {
F_70 ( V_75 L_3 ) ;
return - V_91 ;
}
V_85 = 0 ;
V_86 = 0 ;
for ( V_88 = 0 ; V_88 < V_87 ; ++ V_88 ) {
unsigned int V_92 = F_75 ( V_81 , & V_82 [ V_88 ] ) ;
T_2 V_93 = F_76 ( V_81 , & V_82 [ V_88 ] ) ;
if ( V_93 & ~ V_94 ) {
if ( V_88 > 0 )
return - V_95 ;
else
++ V_86 ;
}
if ( ( V_93 + V_92 ) & ~ V_94 ) {
if ( V_88 < V_87 - 1 )
return - V_95 ;
else
++ V_86 ;
}
V_85 += V_92 ;
}
V_86 += V_85 >> V_41 ;
if ( V_86 > V_37 )
return - V_95 ;
V_84 = F_77 ( sizeof( T_2 ) * V_86 , V_96 ,
F_66 ( V_5 ) ) ;
if ( ! V_84 )
return - V_2 ;
V_86 = 0 ;
for ( V_88 = 0 ; V_88 < V_87 ; ++ V_88 ) {
unsigned int V_92 = F_75 ( V_81 , & V_82 [ V_88 ] ) ;
T_2 V_93 = F_76 ( V_81 , & V_82 [ V_88 ] ) ;
for ( V_89 = 0 ; V_89 < V_92 ; V_89 += V_97 )
V_84 [ V_86 ++ ] =
( V_93 & V_94 ) + V_89 ;
}
V_56 = F_78 ( V_54 -> V_69 ,
V_84 , V_86 , V_83 ) ;
if ( V_56 )
goto V_98;
F_79 ( V_54 ) ;
V_54 -> V_78 = V_82 ;
V_54 -> V_99 = V_79 ;
V_54 -> V_87 = V_87 ;
V_54 -> V_100 ++ ;
F_64 ( V_101 ) ;
V_56 = 0 ;
V_98:
F_18 ( V_84 ) ;
return V_56 ;
}
void F_80 ( void * V_102 , int V_103 )
{
struct V_53 * V_54 = V_102 ;
struct V_3 * V_5 = V_54 -> V_104 ;
switch ( V_103 ) {
case V_105 :
F_81 ( V_5 -> V_81 , V_54 -> V_78 ,
V_54 -> V_87 , V_90 ) ;
break;
case V_106 :
F_82 ( V_5 -> V_81 , V_54 -> V_78 ,
V_54 -> V_87 , V_90 ) ;
break;
}
}
static void F_83 ( struct V_53 * V_54 )
{
struct V_3 * V_5 = V_54 -> V_104 ;
if ( V_54 -> V_87 ) {
F_84 ( V_5 -> V_81 ,
V_54 -> V_78 , V_54 -> V_99 ,
V_90 ) ;
V_54 -> V_87 = 0 ;
}
if ( V_54 -> V_99 ) {
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_54 -> V_99 ; ++ V_88 ) {
struct V_107 * V_107 = F_85 ( & V_54 -> V_78 [ V_88 ] ) ;
F_45 ( ! V_107 -> V_108 && F_86 () ) ;
F_87 ( V_107 ) ;
F_88 ( V_107 ) ;
}
F_18 ( V_54 -> V_78 ) ;
V_54 -> V_78 = NULL ;
V_54 -> V_99 = 0 ;
}
}
static void F_79 ( struct V_53 * V_54 )
{
unsigned int V_109 = V_54 -> V_99 ;
F_83 ( V_54 ) ;
if ( V_109 ) {
struct V_3 * V_5 = V_54 -> V_104 ;
struct V_26 * V_27 = V_5 -> V_48 ;
F_89 ( V_109 , & V_27 -> V_52 ) ;
}
}
static inline unsigned int F_90 ( struct V_26 * V_27 , int V_110 )
{
unsigned int V_51 ;
V_51 = F_46 ( & V_27 -> V_51 ) ;
if ( V_110 )
return V_51 ;
return 0 ;
}
static unsigned int F_91 ( struct V_111 * V_112 ,
struct V_113 * V_11 )
{
struct V_53 * V_54 ;
struct V_55 * V_114 ;
struct V_55 * V_115 ;
unsigned int V_116 = 0 ;
V_114 = F_92 ( V_112 ) ;
while ( V_114 ) {
V_115 = V_114 -> V_115 ;
V_54 = F_52 ( V_114 , struct V_53 , V_60 ) ;
F_26 ( & V_54 -> V_117 , V_11 ) ;
V_114 = V_115 ;
V_116 ++ ;
}
return V_116 ;
}
static void F_93 ( struct V_26 * V_27 ,
struct V_113 * V_11 ,
struct V_55 * * V_118 ,
struct V_55 * * V_119 )
{
struct V_53 * V_54 ;
struct V_55 * V_120 = NULL ;
struct V_55 * * V_115 = V_118 ;
F_94 (ibmr, list, unmap_list) {
V_120 = & V_54 -> V_60 ;
* V_115 = V_120 ;
V_115 = & V_120 -> V_115 ;
}
* V_115 = NULL ;
* V_119 = V_120 ;
}
static int F_44 ( struct V_26 * V_27 ,
int V_110 , struct V_53 * * V_121 )
{
struct V_53 * V_54 , * V_115 ;
struct V_55 * V_122 ;
struct V_55 * V_123 ;
F_30 ( V_117 ) ;
F_30 ( V_124 ) ;
unsigned long V_125 = 0 ;
unsigned int V_126 = 0 , V_127 = 0 , V_128 ;
int V_56 = 0 ;
F_64 ( V_129 ) ;
if ( V_121 ) {
F_95 ( V_130 ) ;
while( ! F_96 ( & V_27 -> V_31 ) ) {
V_54 = F_47 ( V_27 ) ;
if ( V_54 ) {
* V_121 = V_54 ;
F_97 ( & V_27 -> V_32 , & V_130 ) ;
goto V_131;
}
F_98 ( & V_27 -> V_32 , & V_130 ,
V_132 ) ;
if ( F_99 ( & V_27 -> V_30 ) )
F_100 () ;
V_54 = F_47 ( V_27 ) ;
if ( V_54 ) {
* V_121 = V_54 ;
F_97 ( & V_27 -> V_32 , & V_130 ) ;
goto V_131;
}
}
F_97 ( & V_27 -> V_32 , & V_130 ) ;
} else
F_101 ( & V_27 -> V_31 ) ;
if ( V_121 ) {
V_54 = F_47 ( V_27 ) ;
if ( V_54 ) {
* V_121 = V_54 ;
goto V_98;
}
}
V_127 = F_91 ( & V_27 -> V_29 , & V_117 ) ;
V_127 += F_91 ( & V_27 -> V_28 , & V_117 ) ;
if ( V_110 )
F_91 ( & V_27 -> V_30 , & V_117 ) ;
V_128 = F_90 ( V_27 , V_110 ) ;
if ( F_23 ( & V_117 ) )
goto V_98;
F_94 (ibmr, &unmap_list, unmap_list)
F_102 ( & V_54 -> V_69 -> V_11 , & V_124 ) ;
V_56 = F_103 ( & V_124 ) ;
if ( V_56 )
F_70 ( V_75 L_4 , V_56 ) ;
F_32 (ibmr, next, &unmap_list, unmap_list) {
V_125 += V_54 -> V_99 ;
F_83 ( V_54 ) ;
if ( V_126 < V_128 || V_54 -> V_100 >= V_27 -> V_35 . V_38 ) {
F_64 ( V_133 ) ;
F_24 ( & V_54 -> V_117 ) ;
F_71 ( V_54 -> V_69 ) ;
F_18 ( V_54 ) ;
V_126 ++ ;
}
}
if ( ! F_23 ( & V_117 ) ) {
F_55 () ;
F_93 ( V_27 , & V_117 , & V_122 , & V_123 ) ;
if ( V_121 )
* V_121 = F_52 ( V_122 , struct V_53 , V_60 ) ;
if ( V_122 -> V_115 )
F_104 ( V_122 -> V_115 , V_123 , & V_27 -> V_30 ) ;
}
F_89 ( V_125 , & V_27 -> V_52 ) ;
F_89 ( V_127 , & V_27 -> V_64 ) ;
F_89 ( V_126 , & V_27 -> V_51 ) ;
V_98:
F_105 ( & V_27 -> V_31 ) ;
if ( F_106 ( & V_27 -> V_32 ) )
F_107 ( & V_27 -> V_32 ) ;
V_131:
return V_56 ;
}
static void V_34 ( struct V_134 * V_135 )
{
struct V_26 * V_27 = F_108 ( V_135 , struct V_26 , V_33 . V_135 ) ;
F_44 ( V_27 , 0 , NULL ) ;
}
void F_109 ( void * V_102 , int V_136 )
{
struct V_53 * V_54 = V_102 ;
struct V_3 * V_5 = V_54 -> V_104 ;
struct V_26 * V_27 = V_5 -> V_48 ;
F_110 ( L_5 , V_54 -> V_99 ) ;
if ( V_54 -> V_100 >= V_27 -> V_35 . V_38 )
F_111 ( & V_54 -> V_60 , & V_27 -> V_29 ) ;
else
F_111 ( & V_54 -> V_60 , & V_27 -> V_28 ) ;
F_112 ( V_54 -> V_99 , & V_27 -> V_52 ) ;
F_8 ( & V_27 -> V_64 ) ;
if ( F_46 ( & V_27 -> V_52 ) >= V_27 -> V_42 ||
F_46 ( & V_27 -> V_64 ) >= V_27 -> V_45 / 5 )
F_113 ( V_1 , & V_27 -> V_33 , 10 ) ;
if ( V_136 ) {
if ( F_114 ( ! F_115 () ) ) {
F_44 ( V_27 , 0 , NULL ) ;
} else {
F_113 ( V_1 ,
& V_27 -> V_33 , 10 ) ;
}
}
F_20 ( V_5 ) ;
}
void F_116 ( void )
{
struct V_3 * V_5 ;
F_117 ( & V_137 ) ;
F_94 (rds_ibdev, &rds_ib_devices, list) {
struct V_26 * V_27 = V_5 -> V_48 ;
if ( V_27 )
F_44 ( V_27 , 0 , NULL ) ;
}
F_118 ( & V_137 ) ;
}
void * F_119 ( struct V_77 * V_78 , unsigned long V_79 ,
struct V_138 * V_139 , T_3 * V_140 )
{
struct V_3 * V_5 ;
struct V_53 * V_54 = NULL ;
int V_56 ;
V_5 = F_5 ( V_139 -> V_141 ) ;
if ( ! V_5 ) {
V_56 = - V_142 ;
goto V_98;
}
if ( ! V_5 -> V_48 ) {
V_56 = - V_142 ;
goto V_98;
}
V_54 = F_60 ( V_5 ) ;
if ( F_68 ( V_54 ) ) {
F_20 ( V_5 ) ;
return V_54 ;
}
V_56 = F_72 ( V_5 , V_54 , V_78 , V_79 ) ;
if ( V_56 == 0 )
* V_140 = V_54 -> V_69 -> V_143 ;
else
F_70 ( V_75 L_6 , V_56 ) ;
V_54 -> V_104 = V_5 ;
V_5 = NULL ;
V_98:
if ( V_56 ) {
if ( V_54 )
F_109 ( V_54 , 0 ) ;
V_54 = F_36 ( V_56 ) ;
}
if ( V_5 )
F_20 ( V_5 ) ;
return V_54 ;
}
