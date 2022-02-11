static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 ,
const char * V_5 , void * V_6 )
{
return F_2 ( V_3 , L_1 , NULL , & V_7 ,
V_8 ) ;
}
void F_3 ( struct V_9 * V_10 )
{
if ( V_10 -> V_11 && V_10 -> V_12 )
F_4 ( & V_13 , & V_14 ) ;
}
static struct V_15 * F_5 ( const char * V_16 ,
const struct V_17 * V_18 ,
void * V_19 , int V_4 )
{
struct V_20 V_21 ;
struct V_22 V_22 ;
struct V_15 * V_15 ;
struct V_23 * V_23 = NULL ;
int V_24 ;
if ( V_18 -> V_25 && ! F_6 ( V_18 -> V_25 ) )
return F_7 ( - V_26 ) ;
V_24 = F_8 ( & V_27 , & V_13 , & V_14 ) ;
if ( V_24 < 0 ) {
F_9 ( L_2 , V_24 ) ;
V_15 = F_7 ( V_24 ) ;
goto V_28;
}
V_23 = F_10 ( V_13 -> V_29 ) ;
if ( F_11 ( V_23 ) ) {
V_15 = F_12 ( V_23 ) ;
goto V_30;
}
V_15 = F_7 ( - V_31 ) ;
V_21 . V_16 = V_16 ;
V_21 . V_32 = strlen ( V_16 ) ;
V_21 . V_33 = 0 ;
V_22 . V_1 = F_13 ( V_13 -> V_29 , & V_21 ) ;
if ( ! V_22 . V_1 )
goto V_34;
V_22 . V_35 = F_14 ( V_13 ) ;
F_15 ( V_22 . V_1 , V_23 ) ;
V_15 = F_16 ( & V_22 , F_17 ( V_4 ) , V_18 ) ;
if ( F_11 ( V_15 ) )
goto V_36;
V_15 -> V_37 = V_4 & ( V_38 | V_39 ) ;
V_15 -> V_40 = V_19 ;
return V_15 ;
V_36:
F_18 ( & V_22 ) ;
V_34:
F_19 ( V_23 ) ;
V_30:
F_4 ( & V_13 , & V_14 ) ;
V_28:
F_20 ( V_18 -> V_25 ) ;
return V_15 ;
}
struct V_9 * F_21 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_9 * V_10 ;
int V_24 ;
V_44 = F_22 ( V_42 ) ;
if ( F_11 ( V_44 ) )
return F_12 ( V_44 ) ;
V_10 = F_23 () ;
if ( ! V_10 )
return F_7 ( - V_31 ) ;
V_10 -> V_11 = true ;
V_24 = F_24 ( V_10 , V_44 , false ) ;
if ( V_24 )
goto V_45;
return V_10 ;
V_45:
F_25 ( V_10 ) ;
return F_7 ( V_24 ) ;
}
struct V_9 * F_26 ( struct V_41 * V_42 )
{
return V_42 -> V_42 . V_46 . V_47 ;
}
int F_27 ( struct V_9 * V_10 )
{
if ( V_10 -> V_48 >= V_49 )
return - V_50 ;
F_28 ( V_10 ) ;
return 0 ;
}
static T_1 F_29 ( struct V_9 * V_10 , int V_51 )
{
T_2 V_52 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
V_52 = V_10 -> V_55 . V_52 [ V_53 ] ;
if ( V_51 < V_52 ) {
return V_10 -> V_55 . V_56 [ V_53 ] + V_51 ;
}
V_51 -= V_52 ;
}
return 0 ;
}
int F_30 ( struct V_41 * V_57 , struct V_9 * * V_10 , int * V_58 )
{
if ( * V_10 == NULL || * V_58 == 0 ) {
* V_58 = 1 ;
* V_10 = F_26 ( V_57 ) ;
} else {
( * V_58 ) ++ ;
if ( * V_58 > F_31 ( V_57 ) ) {
* V_10 = F_32 ( * V_10 , V_59 ) ;
* V_58 = 1 ;
}
}
return F_29 ( * V_10 , * V_58 ) ;
}
int F_33 ( struct V_9 * V_10 , void * V_19 )
{
if ( ! V_10 )
return - V_60 ;
V_10 -> V_19 = V_19 ;
return 0 ;
}
void * F_34 ( struct V_9 * V_10 )
{
if ( ! V_10 )
return F_7 ( - V_60 ) ;
return V_10 -> V_19 ;
}
int F_35 ( struct V_9 * V_10 , int V_51 )
{
int V_61 ;
T_1 V_62 ;
if ( V_51 == 0 )
V_51 = V_10 -> V_44 -> V_63 ;
V_61 = F_36 ( V_10 , V_51 ) ;
if ( V_61 )
return V_61 ;
if ( ! F_37 ( V_64 ) ) {
V_62 = F_29 ( V_10 , 0 ) ;
if ( V_62 )
F_38 ( V_10 -> V_44 -> V_65 , V_62 , V_66 -> V_67 , V_10 , L_3 ) ;
}
if ( V_10 -> V_48 == V_49 ) {
if ( V_66 -> V_68 )
V_66 -> V_68 ( V_10 ) ;
else F_39 ( 1 , L_4 ) ;
}
return V_61 ;
}
void F_40 ( struct V_9 * V_10 )
{
T_1 V_62 ;
unsigned int V_69 ;
if ( ! F_37 ( V_64 ) ) {
V_62 = F_29 ( V_10 , 0 ) ;
if ( V_62 ) {
V_69 = F_41 ( NULL , V_62 ) ;
if ( V_69 )
F_42 ( V_69 , V_10 ) ;
}
}
F_43 ( V_10 ) ;
V_66 -> V_70 ( & V_10 -> V_55 , V_10 -> V_44 -> V_65 ) ;
}
int F_44 ( struct V_9 * V_10 , int V_51 ,
T_3 V_71 , void * V_72 , char * V_16 )
{
T_1 V_62 ;
V_62 = F_29 ( V_10 , V_51 ) ;
if ( ! V_62 )
return - V_26 ;
return F_38 ( V_10 -> V_44 -> V_65 , V_62 , V_71 , V_72 , V_16 ) ;
}
void F_45 ( struct V_9 * V_10 , int V_51 , void * V_72 )
{
T_1 V_62 ;
unsigned int V_69 ;
V_62 = F_29 ( V_10 , V_51 ) ;
if ( ! V_62 )
return;
V_69 = F_41 ( NULL , V_62 ) ;
if ( V_69 )
F_42 ( V_69 , V_72 ) ;
}
int F_46 ( struct V_9 * V_10 , T_4 V_73 ,
struct V_74 * V_75 )
{
int V_24 = 0 ;
bool V_76 = true ;
F_47 ( L_5 , V_77 , V_10 -> V_78 ) ;
F_48 ( & V_10 -> V_79 ) ;
if ( V_10 -> V_48 == V_49 )
goto V_80;
V_24 = F_49 ( V_10 -> V_44 -> V_65 ) ;
if ( V_24 )
goto V_80;
if ( V_75 ) {
V_10 -> V_81 = F_50 ( V_75 , V_82 ) ;
V_10 -> V_83 = F_50 ( V_75 -> V_84 , V_82 ) ;
V_76 = false ;
V_10 -> V_85 = false ;
}
F_51 () ;
if ( ( V_24 = V_66 -> V_86 ( V_10 , V_76 , V_73 , 0 ) ) ) {
F_52 ( V_10 -> V_83 ) ;
F_52 ( V_10 -> V_81 ) ;
V_10 -> V_83 = V_10 -> V_81 = NULL ;
F_53 ( V_10 -> V_44 -> V_65 ) ;
F_54 () ;
goto V_80;
}
V_10 -> V_48 = V_49 ;
V_80:
F_55 ( & V_10 -> V_79 ) ;
return V_24 ;
}
int F_56 ( struct V_9 * V_10 )
{
return V_10 -> V_87 ;
}
int F_57 ( struct V_9 * V_10 )
{
return F_58 ( V_10 ) ;
}
void F_59 ( struct V_9 * V_10 )
{
V_10 -> V_88 = true ;
}
int F_60 ( struct V_9 * V_10 , bool V_85 )
{
if ( V_10 -> V_48 == V_49 ) {
return - V_50 ;
}
V_10 -> V_85 = V_85 ;
return 0 ;
}
int F_61 ( struct V_23 * V_23 , struct V_15 * V_15 )
{
return F_62 ( V_23 , V_15 ) ;
}
int F_63 ( struct V_23 * V_23 , struct V_15 * V_15 )
{
return F_64 ( V_23 , V_15 ) ;
}
long F_65 ( struct V_15 * V_15 , unsigned int V_89 , unsigned long V_90 )
{
return F_66 ( V_15 , V_89 , V_90 ) ;
}
int F_67 ( struct V_15 * V_15 , struct V_91 * V_92 )
{
return F_68 ( V_15 , V_92 ) ;
}
unsigned int F_69 ( struct V_15 * V_15 , struct V_93 * V_94 )
{
return F_70 ( V_15 , V_94 ) ;
}
T_5 F_71 ( struct V_15 * V_15 , char T_6 * V_95 , T_7 V_96 ,
T_8 * V_97 )
{
return F_72 ( V_15 , V_95 , V_96 , V_97 ) ;
}
struct V_15 * F_73 ( struct V_9 * V_10 , struct V_17 * V_18 ,
int * V_98 )
{
struct V_15 * V_15 ;
int V_24 , V_4 , V_99 ;
char * V_16 = NULL ;
if ( V_10 -> V_12 )
return F_7 ( - V_100 ) ;
V_4 = V_101 | V_102 ;
V_24 = F_74 ( V_4 ) ;
if ( V_24 < 0 )
return F_7 ( V_24 ) ;
V_99 = V_24 ;
if ( V_18 ) {
F_75 ( V_103 ) ;
F_75 ( V_94 ) ;
F_75 ( V_104 ) ;
F_75 ( V_105 ) ;
F_75 ( V_106 ) ;
F_75 ( V_107 ) ;
F_75 ( V_108 ) ;
} else
V_18 = (struct V_17 * ) & V_109 ;
V_16 = F_76 ( V_110 , L_6 , V_10 -> V_78 ) ;
V_15 = F_5 ( V_16 , V_18 , V_10 , V_4 ) ;
F_25 ( V_16 ) ;
if ( F_11 ( V_15 ) )
goto V_111;
F_77 ( V_10 , V_15 -> V_112 ) ;
* V_98 = V_99 ;
return V_15 ;
V_111:
F_78 ( V_99 ) ;
return NULL ;
}
struct V_9 * F_79 ( struct V_15 * V_15 )
{
return V_15 -> V_40 ;
}
void F_80 ( struct V_9 * V_10 ,
struct V_113 * V_114 )
{
F_81 ( ! V_114 -> V_115 || ! V_114 -> V_116 ) ;
F_82 ( & V_10 -> V_117 , 0 ) ;
V_10 -> V_118 = V_114 ;
}
void F_83 ( struct V_9 * V_10 ,
unsigned int V_119 )
{
F_84 ( V_119 , & V_10 -> V_117 ) ;
F_85 ( & V_10 -> V_120 ) ;
}
int F_86 ( struct V_9 * V_10 ,
struct V_121 * V_122 )
{
int V_24 ;
if ( ! ( V_122 -> V_4 & V_123 ) )
V_122 -> V_124 = V_10 -> V_44 -> V_63 ;
else if ( ( V_122 -> V_124 < V_10 -> V_44 -> V_63 ) ||
( V_122 -> V_124 > V_10 -> V_44 -> V_125 ) ) {
return - V_60 ;
}
V_24 = F_87 ( V_10 , V_122 -> V_124 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_46 ( V_10 , V_122 -> V_126 , V_127 ) ;
if ( V_24 < 0 ) {
F_88 ( V_10 , V_10 ) ;
return V_24 ;
}
return 0 ;
}
void T_9 * F_89 ( struct V_9 * V_10 )
{
if ( V_10 -> V_48 != V_49 )
return NULL ;
F_47 ( L_7 ,
V_77 , V_10 -> V_128 , V_10 -> V_129 ) ;
return F_90 ( V_10 -> V_128 , V_10 -> V_129 ) ;
}
void F_91 ( void T_9 * V_130 )
{
F_92 ( V_130 ) ;
}
int F_93 ( struct V_9 * V_10 )
{
struct V_43 * V_44 = V_10 -> V_44 ;
int V_24 ;
V_24 = V_66 -> V_131 ( V_44 ) ;
if ( V_24 )
return V_24 ;
return V_66 -> V_132 ( V_44 ) ;
}
void F_94 ( struct V_43 * V_44 ,
bool V_133 )
{
V_44 -> V_65 -> V_134 = V_133 ;
}
T_5 F_95 ( struct V_41 * V_42 , void * V_95 , T_7 V_96 )
{
struct V_43 * V_44 = F_22 ( V_42 ) ;
if ( F_11 ( V_44 ) )
return - V_135 ;
return V_66 -> V_136 ( V_44 -> V_65 , V_95 , V_96 ) ;
}
int F_96 ( struct V_41 * V_42 , int V_55 )
{
struct V_43 * V_44 = F_22 ( V_42 ) ;
if ( F_11 ( V_44 ) )
return - V_135 ;
if ( V_55 > V_44 -> V_65 -> V_137 )
return - V_60 ;
V_44 -> V_65 -> V_137 = V_55 ;
V_44 -> V_125 = V_55 ;
return 0 ;
}
int F_31 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_22 ( V_42 ) ;
if ( F_11 ( V_44 ) )
return - V_135 ;
return V_44 -> V_125 ;
}
int F_97 ( struct V_41 * V_57 , int V_138 , int type )
{
struct V_9 * V_10 , * V_139 , * V_140 ;
int V_141 ;
int V_24 ;
V_10 = V_140 = F_26 ( V_57 ) ;
if ( F_81 ( ! V_140 ) )
return - V_135 ;
V_141 = V_138 ;
while ( V_141 > 0 ) {
V_24 = F_35 ( V_10 , F_98 ( V_141 , V_10 -> V_44 -> V_125 ) ) ;
if ( V_24 ) {
F_99 ( L_8 , F_100 ( V_57 ) ) ;
return V_24 ;
}
V_141 -= V_10 -> V_44 -> V_125 ;
if ( V_10 != V_140 && V_140 -> V_48 == V_49 ) {
F_81 ( F_46 ( V_10 ,
F_101 ( V_140 -> V_142 -> V_143 . V_73 ) ,
NULL ) ) ;
}
if ( V_141 > 0 ) {
V_139 = F_21 ( V_57 ) ;
if ( F_11 ( V_139 ) ) {
F_99 ( L_9 , F_100 ( V_57 ) ) ;
return - V_144 ;
}
F_102 ( & V_139 -> V_59 , & V_10 -> V_59 ) ;
V_10 = V_139 ;
}
}
return 0 ;
}
void F_103 ( struct V_41 * V_57 )
{
struct V_9 * V_10 , * V_145 , * V_146 ;
V_10 = F_26 ( V_57 ) ;
if ( F_81 ( ! V_10 ) )
return;
F_40 ( V_10 ) ;
F_104 (pos, tmp, &ctx->extra_irq_contexts, extra_irq_contexts) {
F_57 ( V_145 ) ;
F_40 ( V_145 ) ;
F_105 ( & V_145 -> V_59 ) ;
F_27 ( V_145 ) ;
}
}
