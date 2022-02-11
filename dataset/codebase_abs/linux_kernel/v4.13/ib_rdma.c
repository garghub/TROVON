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
if ( V_12 )
F_13 ( V_12 , V_13 ) ;
}
int F_14 ( struct V_1 * V_3 , T_1 V_2 )
{
struct V_1 * V_14 ;
V_14 = F_1 ( V_2 ) ;
if ( ! V_14 )
return F_6 ( V_3 , V_2 ) ;
if ( V_14 != V_3 ) {
F_11 ( V_14 , V_2 ) ;
F_15 ( V_14 ) ;
return F_6 ( V_3 , V_2 ) ;
}
F_15 ( V_14 ) ;
return 0 ;
}
void F_16 ( struct V_1 * V_3 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
F_8 ( & V_20 ) ;
F_17 ( F_18 ( & V_21 ) ) ;
F_17 ( F_18 ( & V_18 -> V_22 ) ) ;
F_19 ( & V_18 -> V_22 ) ;
F_20 ( & V_3 -> V_9 ) ;
F_21 ( & V_18 -> V_22 , & V_3 -> V_23 ) ;
F_22 ( & V_3 -> V_9 ) ;
F_10 ( & V_20 ) ;
V_18 -> V_3 = V_3 ;
F_4 ( & V_3 -> V_6 ) ;
}
void F_23 ( struct V_1 * V_3 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
F_20 ( & V_20 ) ;
F_8 ( & V_3 -> V_9 ) ;
F_17 ( F_18 ( & V_18 -> V_22 ) ) ;
F_19 ( & V_18 -> V_22 ) ;
F_10 ( & V_3 -> V_9 ) ;
F_21 ( & V_18 -> V_22 , & V_21 ) ;
F_22 ( & V_20 ) ;
V_18 -> V_3 = NULL ;
F_15 ( V_3 ) ;
}
void F_24 ( void )
{
struct V_17 * V_18 , * V_24 ;
F_25 ( V_25 ) ;
F_8 ( & V_20 ) ;
F_26 ( & V_21 , & V_25 ) ;
F_10 ( & V_20 ) ;
F_27 (ic, _ic, &tmp_list, ib_node)
F_28 ( V_18 -> V_16 ) ;
}
void F_29 ( struct V_1 * V_3 , struct V_26 * V_27 )
{
struct V_28 * V_29 = V_3 -> V_30 ;
V_27 -> V_31 = V_29 -> V_32 ;
V_27 -> V_33 = V_29 -> V_34 . V_35 ;
}
struct V_36 * F_30 ( struct V_28 * V_37 )
{
struct V_36 * V_38 = NULL ;
struct V_39 * V_40 ;
unsigned long * V_41 ;
F_31 () ;
V_41 = F_32 ( & V_42 ) ;
F_33 ( V_43 , V_41 ) ;
V_40 = F_34 ( & V_37 -> V_44 ) ;
if ( V_40 ) {
V_38 = F_35 ( V_40 , struct V_36 , V_45 ) ;
if ( V_37 -> V_46 == V_47 )
F_36 ( V_48 ) ;
else
F_36 ( V_49 ) ;
}
F_37 ( V_43 , V_41 ) ;
F_38 () ;
return V_38 ;
}
static inline void F_39 ( void )
{
int V_50 ;
unsigned long * V_41 ;
F_40 (cpu) {
V_41 = & F_41 ( V_42 , V_50 ) ;
while ( F_42 ( V_43 , V_41 ) )
F_43 () ;
}
}
void F_44 ( void * V_51 , int V_52 )
{
struct V_36 * V_38 = V_51 ;
struct V_1 * V_3 = V_38 -> V_53 ;
switch ( V_52 ) {
case V_54 :
F_45 ( V_3 -> V_55 , V_38 -> V_56 ,
V_38 -> V_57 , V_58 ) ;
break;
case V_59 :
F_46 ( V_3 -> V_55 , V_38 -> V_56 ,
V_38 -> V_57 , V_58 ) ;
break;
}
}
void F_47 ( struct V_36 * V_38 )
{
struct V_1 * V_3 = V_38 -> V_53 ;
if ( V_38 -> V_57 ) {
F_48 ( V_3 -> V_55 ,
V_38 -> V_56 , V_38 -> V_60 ,
V_58 ) ;
V_38 -> V_57 = 0 ;
}
if ( V_38 -> V_60 ) {
unsigned int V_61 ;
for ( V_61 = 0 ; V_61 < V_38 -> V_60 ; ++ V_61 ) {
struct V_62 * V_62 = F_49 ( & V_38 -> V_56 [ V_61 ] ) ;
F_50 ( ! V_62 -> V_63 && F_51 () ) ;
F_52 ( V_62 ) ;
F_53 ( V_62 ) ;
}
F_54 ( V_38 -> V_56 ) ;
V_38 -> V_56 = NULL ;
V_38 -> V_60 = 0 ;
}
}
void F_55 ( struct V_36 * V_38 )
{
unsigned int V_64 = V_38 -> V_60 ;
F_47 ( V_38 ) ;
if ( V_64 ) {
struct V_28 * V_37 = V_38 -> V_37 ;
F_56 ( V_64 , & V_37 -> V_65 ) ;
}
}
static inline unsigned int F_57 ( struct V_28 * V_37 , int V_66 )
{
unsigned int V_67 ;
V_67 = F_58 ( & V_37 -> V_67 ) ;
if ( V_66 )
return V_67 ;
return 0 ;
}
static unsigned int F_59 ( struct V_68 * V_69 ,
struct V_70 * V_10 )
{
struct V_36 * V_38 ;
struct V_39 * V_71 ;
struct V_39 * V_72 ;
unsigned int V_73 = 0 ;
V_71 = F_60 ( V_69 ) ;
while ( V_71 ) {
V_72 = V_71 -> V_72 ;
V_38 = F_35 ( V_71 , struct V_36 , V_45 ) ;
F_21 ( & V_38 -> V_74 , V_10 ) ;
V_71 = V_72 ;
V_73 ++ ;
}
return V_73 ;
}
static void F_61 ( struct V_28 * V_37 ,
struct V_70 * V_10 ,
struct V_39 * * V_75 ,
struct V_39 * * V_76 )
{
struct V_36 * V_38 ;
struct V_39 * V_77 = NULL ;
struct V_39 * * V_72 = V_75 ;
F_62 (ibmr, list, unmap_list) {
V_77 = & V_38 -> V_45 ;
* V_72 = V_77 ;
V_72 = & V_77 -> V_72 ;
}
* V_72 = NULL ;
* V_76 = V_77 ;
}
int F_63 ( struct V_28 * V_37 ,
int V_66 , struct V_36 * * V_78 )
{
struct V_36 * V_38 ;
struct V_39 * V_79 ;
struct V_39 * V_80 ;
F_25 ( V_74 ) ;
unsigned long V_81 = 0 ;
unsigned int V_82 = 0 , V_83 = 0 , V_84 ;
if ( V_37 -> V_46 == V_47 )
F_36 ( V_85 ) ;
else
F_36 ( V_86 ) ;
if ( V_78 ) {
F_64 ( V_87 ) ;
while ( ! F_65 ( & V_37 -> V_88 ) ) {
V_38 = F_30 ( V_37 ) ;
if ( V_38 ) {
* V_78 = V_38 ;
F_66 ( & V_37 -> V_89 , & V_87 ) ;
goto V_90;
}
F_67 ( & V_37 -> V_89 , & V_87 ,
V_91 ) ;
if ( F_68 ( & V_37 -> V_44 ) )
F_69 () ;
V_38 = F_30 ( V_37 ) ;
if ( V_38 ) {
* V_78 = V_38 ;
F_66 ( & V_37 -> V_89 , & V_87 ) ;
goto V_90;
}
}
F_66 ( & V_37 -> V_89 , & V_87 ) ;
} else
F_70 ( & V_37 -> V_88 ) ;
if ( V_78 ) {
V_38 = F_30 ( V_37 ) ;
if ( V_38 ) {
* V_78 = V_38 ;
goto V_92;
}
}
V_83 = F_59 ( & V_37 -> V_93 , & V_74 ) ;
V_83 += F_59 ( & V_37 -> V_94 , & V_74 ) ;
if ( V_66 )
F_59 ( & V_37 -> V_44 , & V_74 ) ;
V_84 = F_57 ( V_37 , V_66 ) ;
if ( F_18 ( & V_74 ) )
goto V_92;
if ( V_37 -> V_95 )
F_71 ( & V_74 , & V_82 , & V_81 , V_84 ) ;
else
F_72 ( & V_74 , & V_82 , & V_81 , V_84 ) ;
if ( ! F_18 ( & V_74 ) ) {
F_39 () ;
F_61 ( V_37 , & V_74 , & V_79 , & V_80 ) ;
if ( V_78 )
* V_78 = F_35 ( V_79 , struct V_36 , V_45 ) ;
if ( V_79 -> V_72 )
F_73 ( V_79 -> V_72 , V_80 , & V_37 -> V_44 ) ;
}
F_56 ( V_81 , & V_37 -> V_65 ) ;
F_56 ( V_83 , & V_37 -> V_96 ) ;
F_56 ( V_82 , & V_37 -> V_67 ) ;
V_92:
F_74 ( & V_37 -> V_88 ) ;
if ( F_75 ( & V_37 -> V_89 ) )
F_76 ( & V_37 -> V_89 ) ;
V_90:
return 0 ;
}
struct V_36 * F_77 ( struct V_28 * V_37 )
{
struct V_36 * V_38 = NULL ;
int V_97 = 0 ;
if ( F_58 ( & V_37 -> V_96 ) >= V_37 -> V_98 / 10 )
F_78 ( V_99 , & V_37 -> V_100 , 10 ) ;
while ( 1 ) {
V_38 = F_30 ( V_37 ) ;
if ( V_38 )
return V_38 ;
if ( F_79 ( & V_37 -> V_67 ) <= V_37 -> V_32 )
break;
F_80 ( & V_37 -> V_67 ) ;
if ( ++ V_97 > 2 ) {
if ( V_37 -> V_46 == V_47 )
F_36 ( V_101 ) ;
else
F_36 ( V_102 ) ;
return F_81 ( - V_103 ) ;
}
if ( V_37 -> V_46 == V_47 )
F_36 ( V_104 ) ;
else
F_36 ( V_105 ) ;
F_63 ( V_37 , 0 , & V_38 ) ;
if ( V_38 )
return V_38 ;
}
return V_38 ;
}
static void F_82 ( struct V_106 * V_107 )
{
struct V_28 * V_37 = F_83 ( V_107 , struct V_28 , V_100 . V_107 ) ;
F_63 ( V_37 , 0 , NULL ) ;
}
void F_84 ( void * V_51 , int V_108 )
{
struct V_36 * V_38 = V_51 ;
struct V_28 * V_37 = V_38 -> V_37 ;
struct V_1 * V_3 = V_38 -> V_53 ;
F_85 ( L_1 , V_38 -> V_60 ) ;
if ( V_3 -> V_95 )
F_86 ( V_38 ) ;
else
F_87 ( V_38 ) ;
F_88 ( V_38 -> V_60 , & V_37 -> V_65 ) ;
F_89 ( & V_37 -> V_96 ) ;
if ( F_58 ( & V_37 -> V_65 ) >= V_37 -> V_109 ||
F_58 ( & V_37 -> V_96 ) >= V_37 -> V_32 / 5 )
F_78 ( V_99 , & V_37 -> V_100 , 10 ) ;
if ( V_108 ) {
if ( F_90 ( ! F_91 () ) ) {
F_63 ( V_37 , 0 , NULL ) ;
} else {
F_78 ( V_99 ,
& V_37 -> V_100 , 10 ) ;
}
}
F_15 ( V_3 ) ;
}
void F_92 ( void )
{
struct V_1 * V_3 ;
F_93 ( & V_110 ) ;
F_62 (rds_ibdev, &rds_ib_devices, list) {
if ( V_3 -> V_111 )
F_63 ( V_3 -> V_111 , 0 , NULL ) ;
if ( V_3 -> V_30 )
F_63 ( V_3 -> V_30 , 0 , NULL ) ;
}
F_94 ( & V_110 ) ;
}
void * F_95 ( struct V_112 * V_56 , unsigned long V_113 ,
struct V_114 * V_115 , T_2 * V_116 )
{
struct V_1 * V_3 ;
struct V_36 * V_38 = NULL ;
struct V_17 * V_18 = V_115 -> V_117 -> V_19 ;
int V_40 ;
V_3 = F_1 ( V_115 -> V_118 ) ;
if ( ! V_3 ) {
V_40 = - V_119 ;
goto V_92;
}
if ( ! V_3 -> V_111 || ! V_3 -> V_30 ) {
V_40 = - V_119 ;
goto V_92;
}
if ( V_3 -> V_95 )
V_38 = F_96 ( V_3 , V_18 , V_56 , V_113 , V_116 ) ;
else
V_38 = F_97 ( V_3 , V_56 , V_113 , V_116 ) ;
if ( V_38 )
V_3 = NULL ;
V_92:
if ( ! V_38 )
F_98 ( L_2 , V_40 ) ;
if ( V_3 )
F_15 ( V_3 ) ;
return V_38 ;
}
void F_99 ( struct V_28 * V_37 )
{
F_100 ( & V_37 -> V_100 ) ;
F_63 ( V_37 , 1 , NULL ) ;
F_50 ( F_58 ( & V_37 -> V_67 ) ) ;
F_50 ( F_58 ( & V_37 -> V_65 ) ) ;
F_54 ( V_37 ) ;
}
struct V_28 * F_101 ( struct V_1 * V_3 ,
int V_46 )
{
struct V_28 * V_37 ;
V_37 = F_102 ( sizeof( * V_37 ) , V_7 ) ;
if ( ! V_37 )
return F_81 ( - V_8 ) ;
V_37 -> V_46 = V_46 ;
F_103 ( & V_37 -> V_94 ) ;
F_103 ( & V_37 -> V_93 ) ;
F_103 ( & V_37 -> V_44 ) ;
F_104 ( & V_37 -> V_88 ) ;
F_105 ( & V_37 -> V_89 ) ;
F_106 ( & V_37 -> V_100 , F_82 ) ;
if ( V_46 == V_120 ) {
V_37 -> V_34 . V_35 = V_121 + 1 ;
V_37 -> V_32 = V_122 ;
} else {
V_37 -> V_34 . V_35 = V_123 + 1 ;
V_37 -> V_32 = V_124 ;
}
V_37 -> V_109 = V_37 -> V_32 * V_37 -> V_34 . V_35 / 4 ;
V_37 -> V_34 . V_125 = V_3 -> V_126 ;
V_37 -> V_34 . V_127 = V_128 ;
V_37 -> V_98 = V_3 -> V_129 * 3 / 4 ;
V_37 -> V_95 = V_3 -> V_95 ;
return V_37 ;
}
int F_107 ( void )
{
V_99 = F_108 ( L_3 , V_130 , 0 ) ;
if ( ! V_99 )
return - V_8 ;
return 0 ;
}
void F_109 ( void )
{
F_110 ( V_99 ) ;
}
