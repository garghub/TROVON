static void F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
if ( ! F_2 ( V_2 ) )
return;
V_3 = F_3 () ;
if ( F_4 ( V_3 , V_2 -> V_4 ) )
F_5 ( & V_2 -> V_5 ,
V_3 - V_2 -> V_4 ) ;
F_6 ( V_2 ) ;
}
static void F_7 ( struct V_6 * V_7 ,
struct V_6 * V_8 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
if ( F_2 ( V_2 ) )
return;
if ( V_7 == V_8 )
return;
V_2 -> V_4 = F_3 () ;
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
if ( ! F_10 ( V_2 ) )
return;
V_3 = F_3 () ;
if ( F_4 ( V_3 , V_2 -> V_9 ) )
F_5 ( & V_2 -> V_10 ,
V_3 - V_2 -> V_9 ) ;
F_11 ( V_2 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
F_5 ( & V_7 -> V_2 . V_11 , 1 ) ;
}
void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
if ( F_14 ( & V_2 -> V_12 ) )
return;
if ( F_10 ( V_2 ) )
return;
V_2 -> V_9 = F_3 () ;
F_15 ( V_2 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
if ( F_17 ( V_2 ) ) {
unsigned long long V_3 = F_3 () ;
if ( F_4 ( V_3 , V_2 -> V_13 ) )
F_5 ( & V_2 -> V_14 ,
V_3 - V_2 -> V_13 ) ;
F_18 ( V_2 ) ;
}
}
void F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
V_2 -> V_13 = F_3 () ;
F_20 ( V_2 ) ;
}
void F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
F_5 ( & V_2 -> V_15 ,
F_14 ( & V_2 -> V_12 ) ) ;
F_5 ( & V_2 -> V_16 , 1 ) ;
F_1 ( V_2 ) ;
}
static struct V_6 * F_22 ( struct V_17 * V_18 )
{
return V_18 ? F_23 ( V_18 , struct V_6 , V_18 ) : NULL ;
}
struct V_19 * F_24 ( struct V_6 * V_7 )
{
return F_25 ( & V_7 -> V_18 ) ;
}
static struct V_6 * F_26 ( struct V_19 * V_20 )
{
return F_22 ( F_27 ( V_20 , & V_21 ) ) ;
}
static struct V_6 * F_28 ( struct V_6 * V_7 )
{
struct V_19 * V_22 = F_24 ( V_7 ) -> V_23 ;
return V_22 ? F_26 ( V_22 ) : NULL ;
}
struct V_6 * F_29 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = V_25 -> V_28 . V_23 ;
return V_27 ? F_23 ( V_27 , struct V_6 ,
V_28 ) :
V_25 -> V_29 -> V_30 ;
}
static void F_30 ( struct V_6 * V_7 )
{
V_7 -> V_31 ++ ;
}
static void F_31 ( struct V_6 * V_7 )
{
V_7 -> V_31 -- ;
if ( V_7 -> V_31 == 0 )
F_32 ( V_7 ) ;
}
static void F_33 ( struct V_6 * V_7 )
{
F_30 ( V_7 ) ;
F_34 ( F_24 ( V_7 ) ) ;
}
void F_35 ( struct V_6 * V_7 )
{
F_31 ( V_7 ) ;
F_36 ( F_24 ( V_7 ) ) ;
}
void F_37 ( struct V_6 * V_7 , struct V_24 * V_25 ,
unsigned int V_32 )
{
F_38 ( & V_7 -> V_2 . V_12 , V_32 , 1 ) ;
F_9 ( & V_7 -> V_2 ) ;
if ( ! ( V_25 == ( (struct V_33 * ) V_7 -> V_29 ) -> V_34 ) )
F_7 ( V_7 , F_29 ( V_25 ) ) ;
}
void F_39 ( struct V_6 * V_7 , unsigned int V_32 )
{
F_38 ( & V_7 -> V_2 . V_12 , V_32 , - 1 ) ;
}
void F_40 ( struct V_6 * V_7 , unsigned int V_32 )
{
F_38 ( & V_7 -> V_2 . V_35 , V_32 , 1 ) ;
}
void F_41 ( struct V_6 * V_7 , T_1 V_36 ,
T_1 V_37 , unsigned int V_32 )
{
struct V_1 * V_2 = & V_7 -> V_2 ;
unsigned long long V_3 = F_3 () ;
if ( F_4 ( V_3 , V_37 ) )
F_38 ( & V_2 -> V_38 , V_32 ,
V_3 - V_37 ) ;
if ( F_4 ( V_37 , V_36 ) )
F_38 ( & V_2 -> V_39 , V_32 ,
V_37 - V_36 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_35 ) ;
F_43 ( & V_2 -> V_38 ) ;
F_43 ( & V_2 -> V_39 ) ;
F_44 ( & V_2 -> time ) ;
F_44 ( & V_2 -> V_15 ) ;
F_44 ( & V_2 -> V_16 ) ;
F_44 ( & V_2 -> V_11 ) ;
F_44 ( & V_2 -> V_5 ) ;
F_44 ( & V_2 -> V_14 ) ;
F_44 ( & V_2 -> V_10 ) ;
}
static void F_45 ( struct V_1 * V_40 , struct V_1 * V_41 )
{
if ( ! V_40 || ! V_41 )
return;
F_46 ( & V_40 -> V_35 , & V_41 -> V_35 ) ;
F_46 ( & V_40 -> V_38 , & V_41 -> V_38 ) ;
F_46 ( & V_40 -> V_39 , & V_41 -> V_39 ) ;
F_47 ( & V_41 -> time , & V_41 -> time ) ;
F_47 ( & V_40 -> V_15 , & V_41 -> V_15 ) ;
F_47 ( & V_40 -> V_16 ,
& V_41 -> V_16 ) ;
F_47 ( & V_40 -> V_11 , & V_41 -> V_11 ) ;
F_47 ( & V_40 -> V_5 , & V_41 -> V_5 ) ;
F_47 ( & V_40 -> V_14 , & V_41 -> V_14 ) ;
F_47 ( & V_40 -> V_10 , & V_41 -> V_10 ) ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_6 * V_23 ;
if ( ! V_7 )
return;
V_23 = F_28 ( V_7 ) ;
F_49 ( F_24 ( V_7 ) -> V_42 -> V_43 ) ;
if ( F_50 ( ! V_23 ) )
return;
F_45 ( & V_23 -> V_2 , & V_7 -> V_2 ) ;
F_42 ( & V_7 -> V_2 ) ;
}
void F_51 ( struct V_26 * V_28 , struct V_6 * V_7 )
{
struct V_24 * V_25 = F_52 ( V_28 ) ;
V_28 -> V_44 = V_28 -> V_45 ;
V_28 -> V_46 = V_28 -> V_45 ;
if ( V_25 ) {
V_25 -> V_47 = V_25 -> V_48 ;
V_25 -> V_49 = V_25 -> V_50 ;
F_33 ( V_7 ) ;
}
V_28 -> V_23 = V_7 -> V_51 ;
V_28 -> V_52 = & V_7 -> V_52 ;
}
static void F_53 ( struct V_1 * V_2 )
{
F_54 ( & V_2 -> V_35 ) ;
F_54 ( & V_2 -> V_38 ) ;
F_54 ( & V_2 -> V_39 ) ;
F_54 ( & V_2 -> V_12 ) ;
F_55 ( & V_2 -> time ) ;
F_55 ( & V_2 -> V_15 ) ;
F_55 ( & V_2 -> V_16 ) ;
F_55 ( & V_2 -> V_11 ) ;
F_55 ( & V_2 -> V_5 ) ;
F_55 ( & V_2 -> V_14 ) ;
F_55 ( & V_2 -> V_10 ) ;
}
static int F_56 ( struct V_1 * V_2 , T_2 V_53 )
{
if ( F_57 ( & V_2 -> V_35 , V_53 ) ||
F_57 ( & V_2 -> V_38 , V_53 ) ||
F_57 ( & V_2 -> V_39 , V_53 ) ||
F_57 ( & V_2 -> V_12 , V_53 ) ||
F_58 ( & V_2 -> time , V_53 ) ||
F_58 ( & V_2 -> V_15 , V_53 ) ||
F_58 ( & V_2 -> V_16 , V_53 ) ||
F_58 ( & V_2 -> V_11 , V_53 ) ||
F_58 ( & V_2 -> V_5 , V_53 ) ||
F_58 ( & V_2 -> V_14 , V_53 ) ||
F_58 ( & V_2 -> V_10 , V_53 ) ) {
F_53 ( V_2 ) ;
return - V_54 ;
}
return 0 ;
}
static struct V_55 * F_59 ( struct V_56 * V_57 )
{
return V_57 ? F_23 ( V_57 , struct V_55 , V_18 ) : NULL ;
}
static struct V_55 * F_60 ( struct V_58 * V_58 )
{
return F_59 ( F_61 ( V_58 , & V_21 ) ) ;
}
static struct V_56 * F_62 ( T_2 V_53 )
{
struct V_55 * V_59 ;
V_59 = F_63 ( sizeof( * V_59 ) , V_53 ) ;
if ( ! V_59 )
return NULL ;
return & V_59 -> V_18 ;
}
static void F_64 ( struct V_56 * V_57 )
{
struct V_55 * V_60 = F_59 ( V_57 ) ;
V_60 -> V_44 = F_65 ( V_61 ) ?
V_62 : V_63 ;
}
static void F_66 ( struct V_56 * V_57 )
{
F_32 ( F_59 ( V_57 ) ) ;
}
static struct V_17 * F_67 ( T_2 V_53 , int V_64 )
{
struct V_6 * V_7 ;
V_7 = F_68 ( sizeof( * V_7 ) , V_53 , V_64 ) ;
if ( ! V_7 )
return NULL ;
if ( F_56 ( & V_7 -> V_2 , V_53 ) ) {
F_32 ( V_7 ) ;
return NULL ;
}
F_30 ( V_7 ) ;
return & V_7 -> V_18 ;
}
static void F_69 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_25 ( V_18 ) ;
struct V_6 * V_7 = F_26 ( V_20 ) ;
struct V_33 * V_29 = V_20 -> V_42 -> V_65 -> V_66 ;
struct V_26 * V_28 = & V_7 -> V_28 ;
struct V_55 * V_60 = F_60 ( V_20 -> V_58 ) ;
V_28 -> V_46 = V_28 -> V_44 = V_28 -> V_45 = V_60 -> V_44 ;
V_28 -> V_67 = & V_7 -> V_52 ;
V_7 -> V_51 = V_28 ;
V_7 -> V_29 = V_29 ;
V_7 -> V_68 = 0 ;
V_7 -> V_69 = V_70 ;
}
static void F_70 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_22 ( V_18 ) ;
F_53 ( & V_7 -> V_2 ) ;
F_31 ( V_7 ) ;
}
static void F_71 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_22 ( V_18 ) ;
F_42 ( & V_7 -> V_2 ) ;
}
static void F_72 ( struct V_6 * V_7 ,
struct V_6 * V_23 )
{
struct V_26 * V_28 ;
V_28 = & V_7 -> V_28 ;
V_28 -> V_23 = V_23 -> V_51 ;
V_28 -> V_52 = & V_23 -> V_52 ;
}
static struct V_6 * F_73 ( struct V_33 * V_29 ,
struct V_58 * V_58 )
{
struct V_19 * V_20 ;
V_20 = F_74 ( V_58 , V_29 -> V_71 ) ;
if ( F_75 ( V_20 ) )
return F_26 ( V_20 ) ;
return NULL ;
}
struct V_6 * F_76 ( struct V_33 * V_29 ,
struct V_58 * V_58 )
{
struct V_6 * V_7 , * V_23 ;
struct V_26 * V_28 ;
V_7 = F_73 ( V_29 , V_58 ) ;
if ( F_50 ( ! V_7 ) )
return NULL ;
V_28 = & V_7 -> V_28 ;
F_77 (entity) {
V_7 = F_23 ( V_28 , struct V_6 , V_28 ) ;
if ( V_7 != V_29 -> V_30 ) {
V_23 = F_28 ( V_7 ) ;
if ( ! V_23 )
V_23 = V_29 -> V_30 ;
F_72 ( V_7 , V_23 ) ;
}
}
return V_7 ;
}
void F_78 ( struct V_33 * V_29 , struct V_24 * V_25 ,
struct V_6 * V_7 )
{
struct V_26 * V_28 = & V_25 -> V_28 ;
if ( V_25 == V_29 -> V_34 )
F_79 ( V_29 , V_29 -> V_34 ,
false , V_72 ) ;
if ( F_80 ( V_25 ) )
F_81 ( V_29 , V_25 , false , false ) ;
else if ( V_28 -> V_73 )
F_82 ( F_83 ( V_28 ) , V_28 ) ;
F_35 ( F_29 ( V_25 ) ) ;
V_28 -> V_23 = V_7 -> V_51 ;
V_28 -> V_52 = & V_7 -> V_52 ;
F_33 ( V_7 ) ;
if ( F_80 ( V_25 ) ) {
F_84 ( V_29 , V_25 ) ;
F_85 ( V_29 , V_25 ) ;
}
if ( ! V_29 -> V_34 && ! V_29 -> V_74 )
F_86 ( V_29 ) ;
}
static struct V_6 * F_87 ( struct V_33 * V_29 ,
struct V_75 * V_76 ,
struct V_58 * V_58 )
{
struct V_24 * V_77 = F_88 ( V_76 , 0 ) ;
struct V_24 * V_78 = F_88 ( V_76 , 1 ) ;
struct V_6 * V_7 ;
struct V_26 * V_28 ;
V_7 = F_76 ( V_29 , V_58 ) ;
if ( F_50 ( ! V_7 ) )
V_7 = V_29 -> V_30 ;
if ( V_77 ) {
V_28 = & V_77 -> V_28 ;
if ( V_28 -> V_52 != & V_7 -> V_52 ) {
F_89 ( V_76 , NULL , 0 ) ;
F_90 ( V_29 , V_77 ,
L_1 ,
V_77 , V_77 -> V_31 ) ;
F_91 ( V_77 ) ;
}
}
if ( V_78 ) {
V_28 = & V_78 -> V_28 ;
if ( V_28 -> V_52 != & V_7 -> V_52 )
F_78 ( V_29 , V_78 , V_7 ) ;
}
return V_7 ;
}
void F_92 ( struct V_75 * V_76 , struct V_79 * V_79 )
{
struct V_33 * V_29 = F_93 ( V_76 ) ;
struct V_6 * V_7 = NULL ;
T_1 V_80 ;
F_94 () ;
V_80 = F_95 ( V_79 ) -> V_81 . V_80 ;
if ( F_50 ( ! V_29 ) || F_75 ( V_76 -> V_82 == V_80 ) )
goto V_83;
V_7 = F_87 ( V_29 , V_76 , F_95 ( V_79 ) ) ;
F_96 ( F_24 ( V_7 ) , V_7 -> F_96 , sizeof( V_7 -> F_96 ) ) ;
V_76 -> V_82 = V_80 ;
V_83:
F_97 () ;
}
static void F_98 ( struct V_84 * V_85 )
{
struct V_26 * V_28 = V_85 -> V_86 ;
for (; V_28 ; V_28 = V_85 -> V_86 )
F_99 ( V_28 , false ) ;
}
static void F_100 ( struct V_33 * V_29 ,
struct V_26 * V_28 )
{
struct V_24 * V_25 = F_52 ( V_28 ) ;
F_78 ( V_29 , V_25 , V_29 -> V_30 ) ;
}
static void F_101 ( struct V_33 * V_29 ,
struct V_6 * V_7 ,
struct V_84 * V_85 )
{
struct V_87 * V_88 = & V_85 -> V_88 ;
struct V_26 * V_28 = NULL ;
if ( ! F_102 ( & V_85 -> V_88 ) )
V_28 = F_103 ( F_104 ( V_88 ) ) ;
for (; V_28 ; V_28 = F_103 ( F_104 ( V_88 ) ) )
F_100 ( V_29 , V_28 ) ;
if ( V_7 -> V_52 . V_89 )
F_100 ( V_29 ,
V_7 -> V_52 . V_89 ) ;
}
static void F_105 ( struct V_17 * V_18 )
{
struct V_84 * V_85 ;
struct V_6 * V_7 = F_22 ( V_18 ) ;
struct V_33 * V_29 = V_7 -> V_29 ;
struct V_26 * V_28 = V_7 -> V_51 ;
unsigned long V_90 ;
int V_91 ;
if ( ! V_28 )
return;
F_106 ( & V_29 -> V_92 , V_90 ) ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ ) {
V_85 = V_7 -> V_52 . V_94 + V_91 ;
F_98 ( V_85 ) ;
F_101 ( V_29 , V_7 , V_85 ) ;
}
F_99 ( V_28 , false ) ;
F_107 ( V_29 , V_7 ) ;
F_108 ( & V_29 -> V_92 , V_90 ) ;
F_48 ( V_7 ) ;
}
void F_109 ( struct V_33 * V_29 )
{
struct V_19 * V_20 ;
F_110 (blkg, &bfqd->queue->blkg_list, q_node) {
struct V_6 * V_7 = F_26 ( V_20 ) ;
F_111 ( V_29 , V_7 ) ;
}
F_111 ( V_29 , V_29 -> V_30 ) ;
}
static int F_112 ( struct V_95 * V_96 , void * V_97 )
{
struct V_58 * V_58 = F_113 ( F_114 ( V_96 ) ) ;
struct V_55 * V_98 = F_60 ( V_58 ) ;
unsigned int V_99 = 0 ;
if ( V_98 )
V_99 = V_98 -> V_44 ;
F_115 ( V_96 , L_2 , V_99 ) ;
return 0 ;
}
static int F_116 ( struct V_100 * V_81 ,
struct V_101 * V_101 ,
T_3 V_99 )
{
struct V_58 * V_58 = F_113 ( V_81 ) ;
struct V_55 * V_98 = F_60 ( V_58 ) ;
struct V_19 * V_20 ;
int V_102 = - V_103 ;
if ( V_99 < V_104 || V_99 > V_105 )
return V_102 ;
V_102 = 0 ;
F_117 ( & V_58 -> V_92 ) ;
V_98 -> V_44 = ( unsigned short ) V_99 ;
F_118 (blkg, &blkcg->blkg_list, blkcg_node) {
struct V_6 * V_7 = F_26 ( V_20 ) ;
if ( ! V_7 )
continue;
if ( ( unsigned short ) V_99 != V_7 -> V_28 . V_45 ) {
V_7 -> V_28 . V_45 = ( unsigned short ) V_99 ;
F_119 () ;
V_7 -> V_28 . V_106 = 1 ;
}
}
F_120 ( & V_58 -> V_92 ) ;
return V_102 ;
}
static T_4 F_121 ( struct V_107 * V_108 ,
char * V_109 , T_5 V_110 ,
T_6 V_111 )
{
T_3 V_44 ;
int V_102 = F_122 ( F_123 ( V_109 ) , 0 , & V_44 ) ;
if ( V_102 )
return V_102 ;
return F_116 ( F_124 ( V_108 ) , NULL , V_44 ) ;
}
static int F_125 ( struct V_95 * V_96 , void * V_97 )
{
F_126 ( V_96 , F_113 ( F_114 ( V_96 ) ) , V_112 ,
& V_21 , F_127 ( V_96 ) -> V_113 , false ) ;
return 0 ;
}
static int F_128 ( struct V_95 * V_96 , void * V_97 )
{
F_126 ( V_96 , F_113 ( F_114 ( V_96 ) ) , V_114 ,
& V_21 , F_127 ( V_96 ) -> V_113 , true ) ;
return 0 ;
}
static T_3 F_129 ( struct V_95 * V_96 ,
struct V_17 * V_18 , int V_111 )
{
T_3 V_115 = F_130 ( F_25 ( V_18 ) ,
& V_21 , V_111 ) ;
return F_131 ( V_96 , V_18 , V_115 ) ;
}
static T_3 F_132 ( struct V_95 * V_96 ,
struct V_17 * V_18 , int V_111 )
{
struct V_116 V_115 = F_133 ( F_25 ( V_18 ) ,
& V_21 ,
V_111 ) ;
return F_134 ( V_96 , V_18 , & V_115 ) ;
}
static int F_135 ( struct V_95 * V_96 , void * V_97 )
{
F_126 ( V_96 , F_113 ( F_114 ( V_96 ) ) ,
F_129 , & V_21 ,
F_127 ( V_96 ) -> V_113 , false ) ;
return 0 ;
}
static int F_136 ( struct V_95 * V_96 , void * V_97 )
{
F_126 ( V_96 , F_113 ( F_114 ( V_96 ) ) ,
F_132 , & V_21 ,
F_127 ( V_96 ) -> V_113 , true ) ;
return 0 ;
}
static T_3 F_137 ( struct V_95 * V_96 , struct V_17 * V_18 ,
int V_111 )
{
T_3 V_115 = F_14 ( & V_18 -> V_20 -> V_117 ) ;
return F_131 ( V_96 , V_18 , V_115 >> 9 ) ;
}
static int F_138 ( struct V_95 * V_96 , void * V_97 )
{
F_126 ( V_96 , F_113 ( F_114 ( V_96 ) ) ,
F_137 , & V_21 , 0 , false ) ;
return 0 ;
}
static T_3 F_139 ( struct V_95 * V_96 ,
struct V_17 * V_18 , int V_111 )
{
struct V_116 V_118 = F_133 ( V_18 -> V_20 , NULL ,
F_140 ( struct V_19 , V_117 ) ) ;
T_3 V_115 = F_141 ( & V_118 . V_119 [ V_120 ] ) +
F_141 ( & V_118 . V_119 [ V_121 ] ) ;
return F_131 ( V_96 , V_18 , V_115 >> 9 ) ;
}
static int F_142 ( struct V_95 * V_96 , void * V_97 )
{
F_126 ( V_96 , F_113 ( F_114 ( V_96 ) ) ,
F_139 , & V_21 , 0 ,
false ) ;
return 0 ;
}
static T_3 F_143 ( struct V_95 * V_96 ,
struct V_17 * V_18 , int V_111 )
{
struct V_6 * V_7 = F_22 ( V_18 ) ;
T_3 V_122 = F_144 ( & V_7 -> V_2 . V_16 ) ;
T_3 V_97 = 0 ;
if ( V_122 ) {
V_97 = F_144 ( & V_7 -> V_2 . V_15 ) ;
V_97 = F_145 ( V_97 , V_122 ) ;
}
F_131 ( V_96 , V_18 , V_97 ) ;
return 0 ;
}
static int F_146 ( struct V_95 * V_96 , void * V_97 )
{
F_126 ( V_96 , F_113 ( F_114 ( V_96 ) ) ,
F_143 , & V_21 ,
0 , false ) ;
return 0 ;
}
struct V_6 * F_147 ( struct V_33 * V_29 , int V_64 )
{
int V_102 ;
V_102 = F_148 ( V_29 -> V_71 , & V_21 ) ;
if ( V_102 )
return NULL ;
return F_26 ( V_29 -> V_71 -> V_123 ) ;
}
void F_37 ( struct V_6 * V_7 , struct V_24 * V_25 ,
unsigned int V_32 ) { }
void F_39 ( struct V_6 * V_7 , unsigned int V_32 ) { }
void F_40 ( struct V_6 * V_7 , unsigned int V_32 ) { }
void F_41 ( struct V_6 * V_7 , T_1 V_36 ,
T_1 V_37 , unsigned int V_32 ) { }
void F_12 ( struct V_6 * V_7 ) { }
void F_13 ( struct V_6 * V_7 ) { }
void F_16 ( struct V_6 * V_7 ) { }
void F_19 ( struct V_6 * V_7 ) { }
void F_21 ( struct V_6 * V_7 ) { }
void F_78 ( struct V_33 * V_29 , struct V_24 * V_25 ,
struct V_6 * V_7 ) {}
void F_51 ( struct V_26 * V_28 , struct V_6 * V_7 )
{
struct V_24 * V_25 = F_52 ( V_28 ) ;
V_28 -> V_44 = V_28 -> V_45 ;
V_28 -> V_46 = V_28 -> V_45 ;
if ( V_25 ) {
V_25 -> V_47 = V_25 -> V_48 ;
V_25 -> V_49 = V_25 -> V_50 ;
}
V_28 -> V_52 = & V_7 -> V_52 ;
}
void F_92 ( struct V_75 * V_76 , struct V_79 * V_79 ) {}
void F_109 ( struct V_33 * V_29 )
{
F_111 ( V_29 , V_29 -> V_30 ) ;
}
struct V_6 * F_76 ( struct V_33 * V_29 , struct V_58 * V_58 )
{
return V_29 -> V_30 ;
}
struct V_6 * F_29 ( struct V_24 * V_25 )
{
return V_25 -> V_29 -> V_30 ;
}
struct V_6 * F_147 ( struct V_33 * V_29 , int V_64 )
{
struct V_6 * V_7 ;
int V_91 ;
V_7 = F_149 ( sizeof( * V_7 ) , V_124 | V_125 , V_64 ) ;
if ( ! V_7 )
return NULL ;
for ( V_91 = 0 ; V_91 < V_93 ; V_91 ++ )
V_7 -> V_52 . V_94 [ V_91 ] = V_126 ;
return V_7 ;
}
