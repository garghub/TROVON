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
if ( V_13 )
F_17 ( V_13 , V_14 ) ;
}
int F_18 ( struct V_3 * V_5 , T_1 V_4 )
{
struct V_3 * V_15 ;
V_15 = F_5 ( V_4 ) ;
if ( ! V_15 )
return F_10 ( V_5 , V_4 ) ;
if ( V_15 != V_5 ) {
F_15 ( V_15 , V_4 ) ;
F_19 ( V_15 ) ;
return F_10 ( V_5 , V_4 ) ;
}
F_19 ( V_15 ) ;
return 0 ;
}
void F_20 ( struct V_3 * V_5 , struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_12 ( & V_21 ) ;
F_21 ( F_22 ( & V_22 ) ) ;
F_21 ( F_22 ( & V_19 -> V_23 ) ) ;
F_23 ( & V_19 -> V_23 ) ;
F_24 ( & V_5 -> V_10 ) ;
F_25 ( & V_19 -> V_23 , & V_5 -> V_24 ) ;
F_26 ( & V_5 -> V_10 ) ;
F_14 ( & V_21 ) ;
V_19 -> V_5 = V_5 ;
F_8 ( & V_5 -> V_8 ) ;
}
void F_27 ( struct V_3 * V_5 , struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
F_24 ( & V_21 ) ;
F_12 ( & V_5 -> V_10 ) ;
F_21 ( F_22 ( & V_19 -> V_23 ) ) ;
F_23 ( & V_19 -> V_23 ) ;
F_14 ( & V_5 -> V_10 ) ;
F_25 ( & V_19 -> V_23 , & V_22 ) ;
F_26 ( & V_21 ) ;
V_19 -> V_5 = NULL ;
F_19 ( V_5 ) ;
}
void F_28 ( void )
{
struct V_18 * V_19 , * V_25 ;
F_29 ( V_26 ) ;
F_12 ( & V_21 ) ;
F_30 ( & V_22 , & V_26 ) ;
F_14 ( & V_21 ) ;
F_31 (ic, _ic, &tmp_list, ib_node)
F_32 ( V_19 -> V_17 ) ;
}
struct V_27 * F_33 ( struct V_3 * V_5 ,
int V_28 )
{
struct V_27 * V_29 ;
V_29 = F_34 ( sizeof( * V_29 ) , V_9 ) ;
if ( ! V_29 )
return F_35 ( - V_2 ) ;
V_29 -> V_28 = V_28 ;
F_36 ( & V_29 -> V_30 ) ;
F_36 ( & V_29 -> V_31 ) ;
F_36 ( & V_29 -> V_32 ) ;
F_37 ( & V_29 -> V_33 ) ;
F_38 ( & V_29 -> V_34 ) ;
F_39 ( & V_29 -> V_35 , V_36 ) ;
if ( V_28 == V_37 ) {
V_29 -> V_38 . V_39 = V_40 + 1 ;
V_29 -> V_41 = V_42 ;
} else {
V_29 -> V_38 . V_39 = V_43 + 1 ;
V_29 -> V_41 = V_44 ;
}
V_29 -> V_45 = V_29 -> V_41 * V_29 -> V_38 . V_39 / 4 ;
V_29 -> V_38 . V_46 = V_5 -> V_47 ;
V_29 -> V_38 . V_48 = V_49 ;
V_29 -> V_50 = V_5 -> V_51 * 3 / 4 ;
return V_29 ;
}
void F_40 ( struct V_3 * V_5 , struct V_52 * V_53 )
{
struct V_27 * V_54 = V_5 -> V_55 ;
V_53 -> V_56 = V_54 -> V_41 ;
V_53 -> V_57 = V_54 -> V_38 . V_39 ;
}
void F_41 ( struct V_27 * V_29 )
{
F_42 ( & V_29 -> V_35 ) ;
F_43 ( V_29 , 1 , NULL ) ;
F_44 ( F_45 ( & V_29 -> V_58 ) ) ;
F_44 ( F_45 ( & V_29 -> V_59 ) ) ;
F_46 ( V_29 ) ;
}
static inline struct V_60 * F_47 ( struct V_27 * V_29 )
{
struct V_60 * V_61 = NULL ;
struct V_62 * V_63 ;
unsigned long * V_64 ;
F_48 () ;
V_64 = F_49 ( & V_65 ) ;
F_50 ( V_66 , V_64 ) ;
V_63 = F_51 ( & V_29 -> V_32 ) ;
if ( V_63 )
V_61 = F_52 ( V_63 , struct V_60 , V_67 ) ;
F_53 ( V_66 , V_64 ) ;
F_54 () ;
return V_61 ;
}
static inline void F_55 ( void )
{
int V_68 ;
unsigned long * V_64 ;
F_56 (cpu) {
V_64 = & F_57 ( V_65 , V_68 ) ;
while ( F_58 ( V_66 , V_64 ) )
F_59 () ;
}
}
static struct V_60 * F_60 ( struct V_3 * V_5 ,
int V_69 )
{
struct V_27 * V_29 ;
struct V_60 * V_61 = NULL ;
int V_70 = 0 , V_71 = 0 ;
if ( V_69 <= V_43 )
V_29 = V_5 -> V_72 ;
else
V_29 = V_5 -> V_55 ;
if ( F_45 ( & V_29 -> V_73 ) >= V_29 -> V_41 / 10 )
F_61 ( V_1 , & V_29 -> V_35 , 10 ) ;
if ( F_45 ( & V_29 -> V_73 ) >= V_29 -> V_41 * 9 / 10 ) {
if ( V_29 -> V_28 == V_74 )
V_29 = V_5 -> V_55 ;
else
V_29 = V_5 -> V_72 ;
}
while ( 1 ) {
V_61 = F_47 ( V_29 ) ;
if ( V_61 )
return V_61 ;
if ( F_62 ( & V_29 -> V_58 ) <= V_29 -> V_41 )
break;
F_63 ( & V_29 -> V_58 ) ;
if ( ++ V_71 > 2 ) {
if ( V_29 -> V_28 == V_74 )
F_64 ( V_75 ) ;
else
F_64 ( V_76 ) ;
return F_35 ( - V_77 ) ;
}
if ( V_29 -> V_28 == V_74 )
F_64 ( V_78 ) ;
else
F_64 ( V_79 ) ;
F_43 ( V_29 , 0 , & V_61 ) ;
if ( V_61 )
return V_61 ;
}
V_61 = F_65 ( sizeof( * V_61 ) , V_9 , F_66 ( V_5 ) ) ;
if ( ! V_61 ) {
V_70 = - V_2 ;
goto V_80;
}
V_61 -> V_81 = F_67 ( V_5 -> V_82 ,
( V_83 |
V_84 |
V_85 |
V_86 ) ,
& V_29 -> V_38 ) ;
if ( F_68 ( V_61 -> V_81 ) ) {
V_70 = F_69 ( V_61 -> V_81 ) ;
V_61 -> V_81 = NULL ;
F_70 ( V_87 L_2 , V_70 ) ;
goto V_80;
}
V_61 -> V_29 = V_29 ;
if ( V_29 -> V_28 == V_74 )
F_64 ( V_88 ) ;
else
F_64 ( V_89 ) ;
return V_61 ;
V_80:
if ( V_61 ) {
if ( V_61 -> V_81 )
F_71 ( V_61 -> V_81 ) ;
F_46 ( V_61 ) ;
}
F_63 ( & V_29 -> V_58 ) ;
return F_35 ( V_70 ) ;
}
static int F_72 ( struct V_3 * V_5 , struct V_60 * V_61 ,
struct V_90 * V_91 , unsigned int V_92 )
{
struct V_93 * V_94 = V_5 -> V_94 ;
struct V_90 * V_95 = V_91 ;
T_2 V_96 = 0 ;
T_2 * V_97 ;
T_3 V_98 ;
int V_99 , V_100 ;
int V_101 , V_102 ;
int V_63 ;
V_100 = F_73 ( V_94 , V_91 , V_92 ,
V_103 ) ;
if ( F_74 ( ! V_100 ) ) {
F_70 ( V_87 L_3 ) ;
return - V_104 ;
}
V_98 = 0 ;
V_99 = 0 ;
for ( V_101 = 0 ; V_101 < V_100 ; ++ V_101 ) {
unsigned int V_105 = F_75 ( V_94 , & V_95 [ V_101 ] ) ;
T_2 V_106 = F_76 ( V_94 , & V_95 [ V_101 ] ) ;
if ( V_106 & ~ V_107 ) {
if ( V_101 > 0 )
return - V_108 ;
else
++ V_99 ;
}
if ( ( V_106 + V_105 ) & ~ V_107 ) {
if ( V_101 < V_100 - 1 )
return - V_108 ;
else
++ V_99 ;
}
V_98 += V_105 ;
}
V_99 += V_98 >> V_49 ;
if ( V_99 > V_61 -> V_29 -> V_38 . V_39 )
return - V_108 ;
V_97 = F_77 ( sizeof( T_2 ) * V_99 , V_109 ,
F_66 ( V_5 ) ) ;
if ( ! V_97 )
return - V_2 ;
V_99 = 0 ;
for ( V_101 = 0 ; V_101 < V_100 ; ++ V_101 ) {
unsigned int V_105 = F_75 ( V_94 , & V_95 [ V_101 ] ) ;
T_2 V_106 = F_76 ( V_94 , & V_95 [ V_101 ] ) ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 += V_110 )
V_97 [ V_99 ++ ] =
( V_106 & V_107 ) + V_102 ;
}
V_63 = F_78 ( V_61 -> V_81 ,
V_97 , V_99 , V_96 ) ;
if ( V_63 )
goto V_111;
F_79 ( V_61 ) ;
V_61 -> V_91 = V_95 ;
V_61 -> V_112 = V_92 ;
V_61 -> V_100 = V_100 ;
V_61 -> V_113 ++ ;
if ( V_61 -> V_29 -> V_28 == V_74 )
F_64 ( V_114 ) ;
else
F_64 ( V_115 ) ;
V_63 = 0 ;
V_111:
F_46 ( V_97 ) ;
return V_63 ;
}
void F_80 ( void * V_116 , int V_117 )
{
struct V_60 * V_61 = V_116 ;
struct V_3 * V_5 = V_61 -> V_118 ;
switch ( V_117 ) {
case V_119 :
F_81 ( V_5 -> V_94 , V_61 -> V_91 ,
V_61 -> V_100 , V_103 ) ;
break;
case V_120 :
F_82 ( V_5 -> V_94 , V_61 -> V_91 ,
V_61 -> V_100 , V_103 ) ;
break;
}
}
static void F_83 ( struct V_60 * V_61 )
{
struct V_3 * V_5 = V_61 -> V_118 ;
if ( V_61 -> V_100 ) {
F_84 ( V_5 -> V_94 ,
V_61 -> V_91 , V_61 -> V_112 ,
V_103 ) ;
V_61 -> V_100 = 0 ;
}
if ( V_61 -> V_112 ) {
unsigned int V_101 ;
for ( V_101 = 0 ; V_101 < V_61 -> V_112 ; ++ V_101 ) {
struct V_121 * V_121 = F_85 ( & V_61 -> V_91 [ V_101 ] ) ;
F_44 ( ! V_121 -> V_122 && F_86 () ) ;
F_87 ( V_121 ) ;
F_88 ( V_121 ) ;
}
F_46 ( V_61 -> V_91 ) ;
V_61 -> V_91 = NULL ;
V_61 -> V_112 = 0 ;
}
}
static void F_79 ( struct V_60 * V_61 )
{
unsigned int V_123 = V_61 -> V_112 ;
F_83 ( V_61 ) ;
if ( V_123 ) {
struct V_27 * V_29 = V_61 -> V_29 ;
F_89 ( V_123 , & V_29 -> V_59 ) ;
}
}
static inline unsigned int F_90 ( struct V_27 * V_29 , int V_124 )
{
unsigned int V_58 ;
V_58 = F_45 ( & V_29 -> V_58 ) ;
if ( V_124 )
return V_58 ;
return 0 ;
}
static unsigned int F_91 ( struct V_125 * V_126 ,
struct V_127 * V_11 )
{
struct V_60 * V_61 ;
struct V_62 * V_128 ;
struct V_62 * V_129 ;
unsigned int V_130 = 0 ;
V_128 = F_92 ( V_126 ) ;
while ( V_128 ) {
V_129 = V_128 -> V_129 ;
V_61 = F_52 ( V_128 , struct V_60 , V_67 ) ;
F_25 ( & V_61 -> V_131 , V_11 ) ;
V_128 = V_129 ;
V_130 ++ ;
}
return V_130 ;
}
static void F_93 ( struct V_27 * V_29 ,
struct V_127 * V_11 ,
struct V_62 * * V_132 ,
struct V_62 * * V_133 )
{
struct V_60 * V_61 ;
struct V_62 * V_134 = NULL ;
struct V_62 * * V_129 = V_132 ;
F_94 (ibmr, list, unmap_list) {
V_134 = & V_61 -> V_67 ;
* V_129 = V_134 ;
V_129 = & V_134 -> V_129 ;
}
* V_129 = NULL ;
* V_133 = V_134 ;
}
static int F_43 ( struct V_27 * V_29 ,
int V_124 , struct V_60 * * V_135 )
{
struct V_60 * V_61 , * V_129 ;
struct V_62 * V_136 ;
struct V_62 * V_137 ;
F_29 ( V_131 ) ;
F_29 ( V_138 ) ;
unsigned long V_139 = 0 ;
unsigned int V_140 = 0 , V_141 = 0 , V_142 ;
int V_63 = 0 ;
if ( V_29 -> V_28 == V_74 )
F_64 ( V_143 ) ;
else
F_64 ( V_144 ) ;
if ( V_135 ) {
F_95 ( V_145 ) ;
while ( ! F_96 ( & V_29 -> V_33 ) ) {
V_61 = F_47 ( V_29 ) ;
if ( V_61 ) {
* V_135 = V_61 ;
F_97 ( & V_29 -> V_34 , & V_145 ) ;
goto V_146;
}
F_98 ( & V_29 -> V_34 , & V_145 ,
V_147 ) ;
if ( F_99 ( & V_29 -> V_32 ) )
F_100 () ;
V_61 = F_47 ( V_29 ) ;
if ( V_61 ) {
* V_135 = V_61 ;
F_97 ( & V_29 -> V_34 , & V_145 ) ;
goto V_146;
}
}
F_97 ( & V_29 -> V_34 , & V_145 ) ;
} else
F_101 ( & V_29 -> V_33 ) ;
if ( V_135 ) {
V_61 = F_47 ( V_29 ) ;
if ( V_61 ) {
* V_135 = V_61 ;
goto V_111;
}
}
V_141 = F_91 ( & V_29 -> V_31 , & V_131 ) ;
V_141 += F_91 ( & V_29 -> V_30 , & V_131 ) ;
if ( V_124 )
F_91 ( & V_29 -> V_32 , & V_131 ) ;
V_142 = F_90 ( V_29 , V_124 ) ;
if ( F_22 ( & V_131 ) )
goto V_111;
F_94 (ibmr, &unmap_list, unmap_list)
F_102 ( & V_61 -> V_81 -> V_11 , & V_138 ) ;
V_63 = F_103 ( & V_138 ) ;
if ( V_63 )
F_70 ( V_87 L_4 , V_63 ) ;
F_31 (ibmr, next, &unmap_list, unmap_list) {
V_139 += V_61 -> V_112 ;
F_83 ( V_61 ) ;
if ( V_140 < V_142 ||
V_61 -> V_113 >= V_29 -> V_38 . V_46 ) {
if ( V_61 -> V_29 -> V_28 == V_74 )
F_64 ( V_148 ) ;
else
F_64 ( V_149 ) ;
F_23 ( & V_61 -> V_131 ) ;
F_71 ( V_61 -> V_81 ) ;
F_46 ( V_61 ) ;
V_140 ++ ;
}
}
if ( ! F_22 ( & V_131 ) ) {
F_55 () ;
F_93 ( V_29 , & V_131 , & V_136 , & V_137 ) ;
if ( V_135 )
* V_135 = F_52 ( V_136 , struct V_60 , V_67 ) ;
if ( V_136 -> V_129 )
F_104 ( V_136 -> V_129 , V_137 , & V_29 -> V_32 ) ;
}
F_89 ( V_139 , & V_29 -> V_59 ) ;
F_89 ( V_141 , & V_29 -> V_73 ) ;
F_89 ( V_140 , & V_29 -> V_58 ) ;
V_111:
F_105 ( & V_29 -> V_33 ) ;
if ( F_106 ( & V_29 -> V_34 ) )
F_107 ( & V_29 -> V_34 ) ;
V_146:
return V_63 ;
}
static void V_36 ( struct V_150 * V_151 )
{
struct V_27 * V_29 = F_108 ( V_151 , struct V_27 , V_35 . V_151 ) ;
F_43 ( V_29 , 0 , NULL ) ;
}
void F_109 ( void * V_116 , int V_152 )
{
struct V_60 * V_61 = V_116 ;
struct V_27 * V_29 = V_61 -> V_29 ;
struct V_3 * V_5 = V_61 -> V_118 ;
F_110 ( L_5 , V_61 -> V_112 ) ;
if ( V_61 -> V_113 >= V_29 -> V_38 . V_46 )
F_111 ( & V_61 -> V_67 , & V_29 -> V_31 ) ;
else
F_111 ( & V_61 -> V_67 , & V_29 -> V_30 ) ;
F_112 ( V_61 -> V_112 , & V_29 -> V_59 ) ;
F_8 ( & V_29 -> V_73 ) ;
if ( F_45 ( & V_29 -> V_59 ) >= V_29 -> V_45 ||
F_45 ( & V_29 -> V_73 ) >= V_29 -> V_41 / 5 )
F_61 ( V_1 , & V_29 -> V_35 , 10 ) ;
if ( V_152 ) {
if ( F_113 ( ! F_114 () ) ) {
F_43 ( V_29 , 0 , NULL ) ;
} else {
F_61 ( V_1 ,
& V_29 -> V_35 , 10 ) ;
}
}
F_19 ( V_5 ) ;
}
void F_115 ( void )
{
struct V_3 * V_5 ;
F_116 ( & V_153 ) ;
F_94 (rds_ibdev, &rds_ib_devices, list) {
if ( V_5 -> V_72 )
F_43 ( V_5 -> V_72 , 0 , NULL ) ;
if ( V_5 -> V_55 )
F_43 ( V_5 -> V_55 , 0 , NULL ) ;
}
F_117 ( & V_153 ) ;
}
void * F_118 ( struct V_90 * V_91 , unsigned long V_92 ,
struct V_154 * V_155 , T_3 * V_156 )
{
struct V_3 * V_5 ;
struct V_60 * V_61 = NULL ;
int V_63 ;
V_5 = F_5 ( V_155 -> V_157 ) ;
if ( ! V_5 ) {
V_63 = - V_158 ;
goto V_111;
}
if ( ! V_5 -> V_72 || ! V_5 -> V_55 ) {
V_63 = - V_158 ;
goto V_111;
}
V_61 = F_60 ( V_5 , V_92 ) ;
if ( F_68 ( V_61 ) ) {
F_19 ( V_5 ) ;
return V_61 ;
}
V_63 = F_72 ( V_5 , V_61 , V_91 , V_92 ) ;
if ( V_63 == 0 )
* V_156 = V_61 -> V_81 -> V_159 ;
else
F_70 ( V_87 L_6 , V_63 ) ;
V_61 -> V_118 = V_5 ;
V_5 = NULL ;
V_111:
if ( V_63 ) {
if ( V_61 )
F_109 ( V_61 , 0 ) ;
V_61 = F_35 ( V_63 ) ;
}
if ( V_5 )
F_19 ( V_5 ) ;
return V_61 ;
}
