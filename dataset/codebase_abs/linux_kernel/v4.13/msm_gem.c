static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return ( ( ( T_1 ) V_4 -> V_9 -> V_10 ) << V_11 ) +
V_6 -> V_12 . V_13 ;
}
static bool F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! V_4 -> V_9 ;
}
static struct V_14 * * F_4 ( struct V_1 * V_2 , int V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
T_1 V_13 ;
struct V_14 * * V_16 ;
int V_17 , V_18 ;
V_16 = F_5 ( V_15 , sizeof( struct V_14 * ) , V_19 ) ;
if ( ! V_16 )
return F_6 ( - V_20 ) ;
F_7 ( & V_6 -> V_12 . V_21 ) ;
V_17 = F_8 ( & V_6 -> V_12 . V_22 , V_4 -> V_9 , V_15 ) ;
F_9 ( & V_6 -> V_12 . V_21 ) ;
if ( V_17 ) {
F_10 ( V_16 ) ;
return F_6 ( V_17 ) ;
}
V_13 = F_1 ( V_2 ) ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ ) {
V_16 [ V_18 ] = F_11 ( V_13 ) ;
V_13 += V_23 ;
}
return V_16 ;
}
static struct V_14 * * F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_24 ) {
struct V_25 * V_7 = V_2 -> V_7 ;
struct V_14 * * V_16 ;
int V_15 = V_2 -> V_26 >> V_11 ;
if ( F_3 ( V_2 ) )
V_16 = F_13 ( V_2 ) ;
else
V_16 = F_4 ( V_2 , V_15 ) ;
if ( F_14 ( V_16 ) ) {
F_15 ( V_7 -> V_7 , L_1 ,
F_16 ( V_16 ) ) ;
return V_16 ;
}
V_4 -> V_27 = F_17 ( V_16 , V_15 ) ;
if ( F_14 ( V_4 -> V_27 ) ) {
F_15 ( V_7 -> V_7 , L_2 ) ;
return F_18 ( V_4 -> V_27 ) ;
}
V_4 -> V_24 = V_16 ;
if ( V_4 -> V_28 & ( V_29 | V_30 ) )
F_19 ( V_7 -> V_7 , V_4 -> V_27 -> V_31 ,
V_4 -> V_27 -> V_32 , V_33 ) ;
}
return V_4 -> V_24 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
F_7 ( & V_6 -> V_12 . V_21 ) ;
F_21 ( V_4 -> V_9 ) ;
F_9 ( & V_6 -> V_12 . V_21 ) ;
F_10 ( V_4 -> V_24 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_24 ) {
if ( V_4 -> V_28 & ( V_29 | V_30 ) )
F_23 ( V_2 -> V_7 -> V_7 , V_4 -> V_27 -> V_31 ,
V_4 -> V_27 -> V_32 , V_33 ) ;
F_24 ( V_4 -> V_27 ) ;
F_25 ( V_4 -> V_27 ) ;
if ( F_3 ( V_2 ) )
F_26 ( V_2 , V_4 -> V_24 , true , false ) ;
else
F_20 ( V_2 ) ;
V_4 -> V_24 = NULL ;
}
}
struct V_14 * * F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * * V_16 ;
F_28 ( & V_4 -> V_21 ) ;
if ( F_29 ( V_4 -> V_34 != V_35 ) ) {
F_30 ( & V_4 -> V_21 ) ;
return F_6 ( - V_36 ) ;
}
V_16 = F_12 ( V_2 ) ;
F_30 ( & V_4 -> V_21 ) ;
return V_16 ;
}
void F_31 ( struct V_1 * V_2 )
{
}
int F_32 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_38 -> V_39 &= ~ V_40 ;
V_38 -> V_39 |= V_41 ;
if ( V_4 -> V_28 & V_29 ) {
V_38 -> V_42 = F_33 ( F_34 ( V_38 -> V_39 ) ) ;
} else if ( V_4 -> V_28 & V_30 ) {
V_38 -> V_42 = F_35 ( F_34 ( V_38 -> V_39 ) ) ;
} else {
F_36 ( V_38 -> V_43 ) ;
F_37 ( V_2 -> V_44 ) ;
V_38 -> V_45 = 0 ;
V_38 -> V_43 = V_2 -> V_44 ;
V_38 -> V_42 = F_34 ( V_38 -> V_39 ) ;
}
return 0 ;
}
int F_38 ( struct V_46 * V_44 , struct V_37 * V_38 )
{
int V_17 ;
V_17 = F_39 ( V_44 , V_38 ) ;
if ( V_17 ) {
F_40 ( L_3 , V_17 ) ;
return V_17 ;
}
return F_32 ( V_38 -> V_47 , V_38 ) ;
}
int F_41 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_38 ;
struct V_1 * V_2 = V_38 -> V_47 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * * V_24 ;
unsigned long V_50 ;
T_2 V_51 ;
int V_17 ;
V_17 = F_42 ( & V_4 -> V_21 ) ;
if ( V_17 )
goto V_52;
if ( F_29 ( V_4 -> V_34 != V_35 ) ) {
F_30 ( & V_4 -> V_21 ) ;
return V_53 ;
}
V_24 = F_12 ( V_2 ) ;
if ( F_14 ( V_24 ) ) {
V_17 = F_16 ( V_24 ) ;
goto V_54;
}
V_51 = ( V_49 -> V_55 - V_38 -> V_56 ) >> V_11 ;
V_50 = F_43 ( V_24 [ V_51 ] ) ;
F_44 ( L_4 , ( void * ) V_49 -> V_55 ,
V_50 , V_50 << V_11 ) ;
V_17 = F_45 ( V_38 , V_49 -> V_55 , F_46 ( V_50 , V_57 ) ) ;
V_54:
F_30 ( & V_4 -> V_21 ) ;
V_52:
switch ( V_17 ) {
case - V_58 :
case 0 :
case - V_59 :
case - V_60 :
case - V_36 :
return V_61 ;
case - V_20 :
return V_62 ;
default:
return V_53 ;
}
}
static T_3 F_47 ( struct V_1 * V_2 )
{
struct V_25 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 ;
F_29 ( ! F_48 ( & V_4 -> V_21 ) ) ;
V_17 = F_49 ( V_2 ) ;
if ( V_17 ) {
F_15 ( V_7 -> V_7 , L_5 ) ;
return 0 ;
}
return F_50 ( & V_2 -> V_63 ) ;
}
T_3 F_51 ( struct V_1 * V_2 )
{
T_3 V_64 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_28 ( & V_4 -> V_21 ) ;
V_64 = F_47 ( V_2 ) ;
F_30 ( & V_4 -> V_21 ) ;
return V_64 ;
}
static struct V_65 * F_52 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_65 * V_38 ;
F_29 ( ! F_48 ( & V_4 -> V_21 ) ) ;
V_38 = F_53 ( sizeof( * V_38 ) , V_19 ) ;
if ( ! V_38 )
return F_6 ( - V_20 ) ;
V_38 -> V_67 = V_67 ;
F_54 ( & V_38 -> V_68 , & V_4 -> V_69 ) ;
return V_38 ;
}
static struct V_65 * F_55 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_65 * V_38 ;
F_29 ( ! F_48 ( & V_4 -> V_21 ) ) ;
F_56 (vma, &msm_obj->vmas, list) {
if ( V_38 -> V_67 == V_67 )
return V_38 ;
}
return NULL ;
}
static void F_57 ( struct V_65 * V_38 )
{
if ( ! V_38 )
return;
F_58 ( & V_38 -> V_68 ) ;
F_25 ( V_38 ) ;
}
static void
F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_65 * V_38 , * V_70 ;
F_29 ( ! F_48 ( & V_4 -> V_21 ) ) ;
F_60 (vma, tmp, &msm_obj->vmas, list) {
F_61 ( V_38 -> V_67 , V_38 , V_4 -> V_27 ) ;
F_57 ( V_38 ) ;
}
}
int F_62 ( struct V_1 * V_2 ,
struct V_66 * V_67 , T_3 * V_71 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_65 * V_38 ;
int V_17 = 0 ;
F_28 ( & V_4 -> V_21 ) ;
if ( F_29 ( V_4 -> V_34 != V_35 ) ) {
F_30 ( & V_4 -> V_21 ) ;
return - V_36 ;
}
V_38 = F_55 ( V_2 , V_67 ) ;
if ( ! V_38 ) {
struct V_14 * * V_24 ;
V_38 = F_52 ( V_2 , V_67 ) ;
if ( F_14 ( V_38 ) ) {
V_17 = F_16 ( V_38 ) ;
goto V_72;
}
V_24 = F_12 ( V_2 ) ;
if ( F_14 ( V_24 ) ) {
V_17 = F_16 ( V_24 ) ;
goto V_73;
}
V_17 = F_63 ( V_67 , V_38 , V_4 -> V_27 ,
V_2 -> V_26 >> V_11 ) ;
if ( V_17 )
goto V_73;
}
* V_71 = V_38 -> V_71 ;
F_30 ( & V_4 -> V_21 ) ;
return 0 ;
V_73:
F_57 ( V_38 ) ;
V_72:
F_30 ( & V_4 -> V_21 ) ;
return V_17 ;
}
T_3 F_64 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_65 * V_38 ;
F_28 ( & V_4 -> V_21 ) ;
V_38 = F_55 ( V_2 , V_67 ) ;
F_30 ( & V_4 -> V_21 ) ;
F_29 ( ! V_38 ) ;
return V_38 ? V_38 -> V_71 : 0 ;
}
void F_65 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
}
int F_66 ( struct V_74 * V_46 , struct V_25 * V_7 ,
struct V_75 * args )
{
args -> V_76 = F_67 ( args -> V_77 , args -> V_78 ) ;
args -> V_26 = F_68 ( args -> V_76 * args -> V_79 ) ;
return F_69 ( V_7 , V_46 , args -> V_26 ,
V_80 | V_29 , & args -> V_81 ) ;
}
int F_70 ( struct V_74 * V_46 , struct V_25 * V_7 ,
T_4 V_81 , T_3 * V_64 )
{
struct V_1 * V_2 ;
int V_17 = 0 ;
V_2 = F_71 ( V_46 , V_81 ) ;
if ( V_2 == NULL ) {
V_17 = - V_82 ;
goto V_73;
}
* V_64 = F_51 ( V_2 ) ;
F_72 ( V_2 ) ;
V_73:
return V_17 ;
}
void * F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_17 = 0 ;
F_28 ( & V_4 -> V_21 ) ;
if ( F_29 ( V_4 -> V_34 != V_35 ) ) {
F_30 ( & V_4 -> V_21 ) ;
return F_6 ( - V_36 ) ;
}
V_4 -> V_83 ++ ;
if ( ! V_4 -> V_84 ) {
struct V_14 * * V_24 = F_12 ( V_2 ) ;
if ( F_14 ( V_24 ) ) {
V_17 = F_16 ( V_24 ) ;
goto V_73;
}
V_4 -> V_84 = F_74 ( V_24 , V_2 -> V_26 >> V_11 ,
V_85 , F_33 ( V_86 ) ) ;
if ( V_4 -> V_84 == NULL ) {
V_17 = - V_20 ;
goto V_73;
}
}
F_30 ( & V_4 -> V_21 ) ;
return V_4 -> V_84 ;
V_73:
V_4 -> V_83 -- ;
F_30 ( & V_4 -> V_21 ) ;
return F_6 ( V_17 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_28 ( & V_4 -> V_21 ) ;
F_29 ( V_4 -> V_83 < 1 ) ;
V_4 -> V_83 -- ;
F_30 ( & V_4 -> V_21 ) ;
}
int F_76 ( struct V_1 * V_2 , unsigned V_34 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_28 ( & V_4 -> V_21 ) ;
F_29 ( ! F_48 ( & V_2 -> V_7 -> V_87 ) ) ;
if ( V_4 -> V_34 != V_88 )
V_4 -> V_34 = V_34 ;
V_34 = V_4 -> V_34 ;
F_30 ( & V_4 -> V_21 ) ;
return ( V_34 != V_88 ) ;
}
void F_77 ( struct V_1 * V_2 , enum V_89 V_90 )
{
struct V_25 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( ! F_48 ( & V_7 -> V_87 ) ) ;
F_29 ( ! F_78 ( V_4 ) ) ;
F_29 ( V_2 -> V_91 ) ;
F_79 ( & V_4 -> V_21 , V_90 ) ;
F_59 ( V_2 ) ;
F_80 ( V_2 ) ;
F_22 ( V_2 ) ;
V_4 -> V_34 = V_88 ;
F_81 ( & V_2 -> V_63 , V_7 -> V_92 -> V_93 ) ;
F_82 ( V_2 ) ;
F_83 ( F_84 ( V_2 -> V_44 ) , 0 , ( V_94 ) - 1 ) ;
F_85 ( F_84 ( V_2 -> V_44 ) -> V_93 ,
0 , ( V_94 ) - 1 ) ;
F_30 ( & V_4 -> V_21 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( ! F_48 ( & V_4 -> V_21 ) ) ;
if ( ! V_4 -> V_84 || F_29 ( ! F_86 ( V_4 ) ) )
return;
F_87 ( V_4 -> V_84 ) ;
V_4 -> V_84 = NULL ;
}
void F_88 ( struct V_1 * V_2 , enum V_89 V_90 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_79 ( & V_4 -> V_21 , V_90 ) ;
F_80 ( V_2 ) ;
F_30 ( & V_4 -> V_21 ) ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_95 * V_96 , bool V_97 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
int V_18 , V_17 ;
if ( ! V_97 ) {
V_17 = F_90 ( V_4 -> V_102 ) ;
if ( V_17 )
return V_17 ;
}
V_99 = F_91 ( V_4 -> V_102 ) ;
if ( ! V_99 || ( V_99 -> V_103 == 0 ) ) {
V_101 = F_92 ( V_4 -> V_102 ) ;
if ( V_101 && ( V_101 -> V_104 != V_96 -> V_104 ) ) {
V_17 = F_93 ( V_101 , true ) ;
if ( V_17 )
return V_17 ;
}
}
if ( ! V_97 || ! V_99 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_99 -> V_103 ; V_18 ++ ) {
V_101 = F_94 ( V_99 -> V_105 [ V_18 ] ,
F_95 ( V_4 -> V_102 ) ) ;
if ( V_101 -> V_104 != V_96 -> V_104 ) {
V_17 = F_93 ( V_101 , true ) ;
if ( V_17 )
return V_17 ;
}
}
return 0 ;
}
void F_96 ( struct V_1 * V_2 ,
struct V_106 * V_107 , bool V_97 , struct V_100 * V_101 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( V_4 -> V_34 != V_35 ) ;
V_4 -> V_107 = V_107 ;
if ( V_97 )
F_97 ( V_4 -> V_102 , V_101 ) ;
else
F_98 ( V_4 -> V_102 , V_101 ) ;
F_99 ( & V_4 -> V_108 ) ;
F_54 ( & V_4 -> V_108 , & V_107 -> V_109 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_25 * V_7 = V_2 -> V_7 ;
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( ! F_48 ( & V_7 -> V_87 ) ) ;
V_4 -> V_107 = NULL ;
F_99 ( & V_4 -> V_108 ) ;
F_54 ( & V_4 -> V_108 , & V_6 -> V_110 ) ;
}
int F_101 ( struct V_1 * V_2 , T_4 V_111 , T_5 * V_112 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
bool V_113 = ! ! ( V_111 & V_114 ) ;
unsigned long V_115 =
V_111 & V_116 ? 0 : F_102 ( V_112 ) ;
long V_17 ;
V_17 = F_103 ( V_4 -> V_102 , V_113 ,
true , V_115 ) ;
if ( V_17 == 0 )
return V_115 == 0 ? - V_36 : - V_117 ;
else if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_105 ( struct V_100 * V_101 , const char * type ,
struct V_118 * V_119 )
{
if ( ! F_106 ( V_101 ) )
F_107 ( V_119 , L_6 , type ,
V_101 -> V_120 -> V_121 ( V_101 ) ,
V_101 -> V_120 -> V_122 ( V_101 ) ,
V_101 -> V_123 ) ;
}
void F_108 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_124 * V_125 = V_4 -> V_102 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_65 * V_38 ;
T_3 V_126 = F_109 ( & V_2 -> V_63 ) ;
const char * V_34 ;
F_28 ( & V_4 -> V_21 ) ;
switch ( V_4 -> V_34 ) {
case V_88 :
V_34 = L_7 ;
break;
case V_127 :
V_34 = L_8 ;
break;
case V_35 :
default:
V_34 = L_9 ;
break;
}
F_107 ( V_119 , L_10 ,
V_4 -> V_28 , F_110 ( V_4 ) ? 'A' : 'I' ,
V_2 -> V_128 , F_111 ( & V_2 -> V_129 ) ,
V_126 , V_4 -> V_84 ) ;
F_56 (vma, &msm_obj->vmas, list)
F_107 ( V_119 , L_11 , V_38 -> V_71 ) ;
F_107 ( V_119 , L_12 , V_2 -> V_26 , V_34 ) ;
F_112 () ;
V_99 = F_113 ( V_125 -> V_101 ) ;
if ( V_99 ) {
unsigned int V_18 , V_103 = V_99 -> V_103 ;
for ( V_18 = 0 ; V_18 < V_103 ; V_18 ++ ) {
V_101 = F_113 ( V_99 -> V_105 [ V_18 ] ) ;
F_105 ( V_101 , L_13 , V_119 ) ;
}
}
V_101 = F_113 ( V_125 -> V_130 ) ;
if ( V_101 )
F_105 ( V_101 , L_14 , V_119 ) ;
F_114 () ;
F_30 ( & V_4 -> V_21 ) ;
}
void F_115 ( struct V_131 * V_68 , struct V_118 * V_119 )
{
struct V_3 * V_4 ;
int V_132 = 0 ;
T_6 V_26 = 0 ;
F_56 (msm_obj, list, mm_list) {
struct V_1 * V_2 = & V_4 -> V_133 ;
F_107 ( V_119 , L_15 ) ;
F_108 ( V_2 , V_119 ) ;
V_132 ++ ;
V_26 += V_2 -> V_26 ;
}
F_107 ( V_119 , L_16 , V_132 , V_26 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
struct V_25 * V_7 = V_2 -> V_7 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( ! F_48 ( & V_7 -> V_87 ) ) ;
F_29 ( F_110 ( V_4 ) ) ;
F_58 ( & V_4 -> V_108 ) ;
F_28 ( & V_4 -> V_21 ) ;
F_59 ( V_2 ) ;
if ( V_2 -> V_91 ) {
if ( V_4 -> V_84 )
F_117 ( V_2 -> V_91 -> V_134 , V_4 -> V_84 ) ;
if ( V_4 -> V_24 )
F_10 ( V_4 -> V_24 ) ;
F_118 ( V_2 , V_4 -> V_27 ) ;
} else {
F_80 ( V_2 ) ;
F_22 ( V_2 ) ;
}
if ( V_4 -> V_102 == & V_4 -> V_135 )
F_119 ( V_4 -> V_102 ) ;
F_120 ( V_2 ) ;
F_30 ( & V_4 -> V_21 ) ;
F_25 ( V_4 ) ;
}
int F_69 ( struct V_25 * V_7 , struct V_74 * V_46 ,
T_4 V_26 , T_4 V_28 , T_4 * V_81 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_121 ( V_7 , V_26 , V_28 ) ;
if ( F_14 ( V_2 ) )
return F_16 ( V_2 ) ;
V_17 = F_122 ( V_46 , V_2 , V_81 ) ;
F_72 ( V_2 ) ;
return V_17 ;
}
static int F_123 ( struct V_25 * V_7 ,
T_4 V_26 , T_4 V_28 ,
struct V_124 * V_102 ,
struct V_1 * * V_2 ,
bool V_136 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_3 * V_4 ;
switch ( V_28 & V_137 ) {
case V_30 :
case V_138 :
case V_29 :
break;
default:
F_15 ( V_7 -> V_7 , L_17 ,
( V_28 & V_137 ) ) ;
return - V_139 ;
}
V_4 = F_53 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
F_124 ( & V_4 -> V_21 ) ;
V_4 -> V_28 = V_28 ;
V_4 -> V_34 = V_35 ;
if ( V_102 ) {
V_4 -> V_102 = V_102 ;
} else {
V_4 -> V_102 = & V_4 -> V_135 ;
F_125 ( V_4 -> V_102 ) ;
}
F_126 ( & V_4 -> V_140 ) ;
F_126 ( & V_4 -> V_69 ) ;
if ( V_136 ) {
F_29 ( ! F_48 ( & V_7 -> V_87 ) ) ;
F_54 ( & V_4 -> V_108 , & V_6 -> V_110 ) ;
} else {
F_28 ( & V_7 -> V_87 ) ;
F_54 ( & V_4 -> V_108 , & V_6 -> V_110 ) ;
F_30 ( & V_7 -> V_87 ) ;
}
* V_2 = & V_4 -> V_133 ;
return 0 ;
}
static struct V_1 * F_127 ( struct V_25 * V_7 ,
T_4 V_26 , T_4 V_28 , bool V_136 )
{
struct V_5 * V_6 = V_7 -> V_8 ;
struct V_1 * V_2 = NULL ;
bool V_141 = false ;
int V_17 ;
V_26 = F_68 ( V_26 ) ;
if ( ! F_128 ( & V_142 ) )
V_141 = true ;
else if ( ( V_28 & V_143 ) && V_6 -> V_12 . V_26 )
V_141 = true ;
if ( F_29 ( V_141 && ! V_6 -> V_12 . V_26 ) )
return F_6 ( - V_139 ) ;
if ( V_26 == 0 )
return F_6 ( - V_139 ) ;
V_17 = F_123 ( V_7 , V_26 , V_28 , NULL , & V_2 , V_136 ) ;
if ( V_17 )
goto V_73;
if ( V_141 ) {
struct V_65 * V_38 ;
struct V_14 * * V_24 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_28 ( & V_4 -> V_21 ) ;
V_38 = F_52 ( V_2 , NULL ) ;
F_30 ( & V_4 -> V_21 ) ;
if ( F_14 ( V_38 ) ) {
V_17 = F_16 ( V_38 ) ;
goto V_73;
}
F_2 ( V_2 ) -> V_9 = & V_38 -> V_144 ;
F_129 ( V_7 , V_2 , V_26 ) ;
V_24 = F_12 ( V_2 ) ;
if ( F_14 ( V_24 ) ) {
V_17 = F_16 ( V_24 ) ;
goto V_73;
}
V_38 -> V_71 = F_1 ( V_2 ) ;
} else {
V_17 = F_130 ( V_7 , V_2 , V_26 ) ;
if ( V_17 )
goto V_73;
}
return V_2 ;
V_73:
F_72 ( V_2 ) ;
return F_6 ( V_17 ) ;
}
struct V_1 * F_131 ( struct V_25 * V_7 ,
T_4 V_26 , T_4 V_28 )
{
return F_127 ( V_7 , V_26 , V_28 , true ) ;
}
struct V_1 * F_121 ( struct V_25 * V_7 ,
T_4 V_26 , T_4 V_28 )
{
return F_127 ( V_7 , V_26 , V_28 , false ) ;
}
struct V_1 * F_132 ( struct V_25 * V_7 ,
struct V_145 * V_134 , struct V_146 * V_27 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_4 V_26 ;
int V_17 , V_15 ;
if ( ! F_128 ( & V_142 ) ) {
F_15 ( V_7 -> V_7 , L_18 ) ;
return F_6 ( - V_139 ) ;
}
V_26 = F_68 ( V_134 -> V_26 ) ;
V_17 = F_123 ( V_7 , V_26 , V_29 , V_134 -> V_102 , & V_2 , false ) ;
if ( V_17 )
goto V_73;
F_129 ( V_7 , V_2 , V_26 ) ;
V_15 = V_26 / V_23 ;
V_4 = F_2 ( V_2 ) ;
F_28 ( & V_4 -> V_21 ) ;
V_4 -> V_27 = V_27 ;
V_4 -> V_24 = F_5 ( V_15 , sizeof( struct V_14 * ) , V_19 ) ;
if ( ! V_4 -> V_24 ) {
F_30 ( & V_4 -> V_21 ) ;
V_17 = - V_20 ;
goto V_73;
}
V_17 = F_133 ( V_27 , V_4 -> V_24 , NULL , V_15 ) ;
if ( V_17 ) {
F_30 ( & V_4 -> V_21 ) ;
goto V_73;
}
F_30 ( & V_4 -> V_21 ) ;
return V_2 ;
V_73:
F_72 ( V_2 ) ;
return F_6 ( V_17 ) ;
}
