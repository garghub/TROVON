int F_1 ( T_1 V_1 , void * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
if ( V_4 -> V_1 )
V_5 = * ( T_1 * ) V_4 -> V_1 ;
else if ( V_1 )
V_5 = V_1 ;
if ( ! V_5 )
return 0 ;
V_5 = F_2 ( V_5 ) ;
return F_3 ( V_2 , V_4 -> V_6 , 2 , & V_5 ) ;
}
int F_4 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
if ( V_4 -> V_1 )
return F_5 ( V_8 , V_4 -> V_6 , * ( V_9 * ) V_4 -> V_1 ) ;
else
return F_6 ( V_8 , V_4 -> V_6 , 0 , NULL ) ;
}
int F_7 ( V_9 V_1 , struct V_3 * V_4 )
{
if ( V_1 || V_4 -> V_1 )
return 8 ;
return 0 ;
}
int F_8 ( T_1 V_1 , struct V_3 * V_4 )
{
if ( V_1 || V_4 -> V_1 )
return 8 ;
return 0 ;
}
int F_9 ( V_9 V_1 , void * V_2 , struct V_3 * V_4 )
{
V_9 V_5 = V_1 ;
if ( V_4 -> V_1 )
V_5 = * ( V_9 * ) V_4 -> V_1 ;
else if ( V_1 )
V_5 = V_1 ;
if ( ! V_5 )
return 0 ;
V_5 = F_10 ( V_5 ) ;
return F_3 ( V_2 , V_4 -> V_6 , 4 , & V_5 ) ;
}
int F_11 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
if ( V_4 -> V_1 )
return F_12 ( V_8 , V_4 -> V_6 , * ( T_1 * ) V_4 -> V_1 ) ;
else
return F_6 ( V_8 , V_4 -> V_6 , 0 , NULL ) ;
}
int F_13 ( struct V_3 * V_4 , void * V_1 , T_2 V_10 )
{
V_4 -> V_1 = F_14 ( V_1 , sizeof( V_9 ) , V_10 ) ;
if ( ! V_4 -> V_1 )
return - V_11 ;
return 0 ;
}
int F_15 ( struct V_3 * V_4 , void * V_1 , T_2 V_10 )
{
V_4 -> V_1 = F_14 ( V_1 , sizeof( T_1 ) , V_10 ) ;
if ( ! V_4 -> V_1 )
return - V_11 ;
return 0 ;
}
void F_16 ( struct V_3 * V_4 )
{
F_17 ( V_4 -> V_1 ) ;
}
int F_18 ( void * V_12 , int V_13 )
{
if ( V_13 == sizeof( V_9 ) )
return 0 ;
return - V_14 ;
}
int F_19 ( void * V_12 , int V_13 )
{
if ( V_13 == sizeof( T_1 ) )
return 0 ;
return - V_14 ;
}
static struct V_15 * F_20 ( T_1 V_6 )
{
struct V_15 * V_16 ;
F_21 ( & V_17 ) ;
F_22 (o, &ifeoplist, list) {
if ( V_16 -> V_6 == V_6 ) {
if ( ! F_23 ( V_16 -> V_18 ) )
V_16 = NULL ;
F_24 ( & V_17 ) ;
return V_16 ;
}
}
F_24 ( & V_17 ) ;
return NULL ;
}
int F_25 ( struct V_15 * V_19 )
{
struct V_15 * V_20 ;
if ( ! V_19 -> V_6 || ! V_19 -> V_21 || ! V_19 -> V_22 ||
! V_19 -> V_23 || ! V_19 -> V_24 || ! V_19 -> V_25 ||
! V_19 -> V_26 || ! V_19 -> V_27 )
return - V_14 ;
F_26 ( & V_17 ) ;
F_22 (m, &ifeoplist, list) {
if ( V_20 -> V_6 == V_19 -> V_6 ||
( strcmp ( V_19 -> V_22 , V_20 -> V_22 ) == 0 ) ) {
F_27 ( & V_17 ) ;
return - V_28 ;
}
}
if ( ! V_19 -> V_29 )
V_19 -> V_29 = F_16 ;
F_28 ( & V_19 -> V_30 , & V_31 ) ;
F_27 ( & V_17 ) ;
return 0 ;
}
int F_29 ( struct V_15 * V_19 )
{
struct V_15 * V_20 ;
int V_32 = - V_33 ;
F_26 ( & V_17 ) ;
F_22 (m, &ifeoplist, list) {
if ( V_20 -> V_6 == V_19 -> V_6 ) {
F_30 ( & V_19 -> V_30 ) ;
V_32 = 0 ;
break;
}
}
F_27 ( & V_17 ) ;
return V_32 ;
}
static int F_31 ( struct V_15 * V_34 , void * V_12 , int V_13 )
{
int V_35 = 0 ;
if ( V_34 -> V_36 )
return V_34 -> V_36 ( V_12 , V_13 ) ;
if ( V_34 -> V_21 == V_37 )
V_35 = F_18 ( V_12 , V_13 ) ;
else if ( V_34 -> V_21 == V_38 )
V_35 = F_19 ( V_12 , V_13 ) ;
return V_35 ;
}
static int F_32 ( struct V_39 * V_40 , V_9 V_6 ,
void * V_12 , int V_13 , bool V_41 )
{
struct V_15 * V_34 = F_20 ( V_6 ) ;
int V_35 = 0 ;
if ( ! V_34 ) {
V_35 = - V_33 ;
#ifdef F_33
if ( V_41 )
F_34 ( & V_40 -> V_42 ) ;
F_35 () ;
F_36 ( L_1 , V_6 ) ;
F_37 () ;
if ( V_41 )
F_38 ( & V_40 -> V_42 ) ;
V_34 = F_20 ( V_6 ) ;
#endif
}
if ( V_34 ) {
V_35 = 0 ;
if ( V_13 )
V_35 = F_31 ( V_34 , V_12 , V_13 ) ;
F_39 ( V_34 -> V_18 ) ;
}
return V_35 ;
}
static int F_40 ( struct V_39 * V_40 , V_9 V_6 , void * V_1 ,
int V_13 , bool V_43 )
{
struct V_3 * V_4 = NULL ;
struct V_15 * V_34 = F_20 ( V_6 ) ;
int V_35 = 0 ;
if ( ! V_34 )
return - V_33 ;
V_4 = F_41 ( sizeof( * V_4 ) , V_43 ? V_44 : V_45 ) ;
if ( ! V_4 ) {
F_39 ( V_34 -> V_18 ) ;
return - V_11 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_34 = V_34 ;
if ( V_13 > 0 ) {
V_35 = V_34 -> V_27 ( V_4 , V_1 , V_43 ? V_44 : V_45 ) ;
if ( V_35 != 0 ) {
F_17 ( V_4 ) ;
F_39 ( V_34 -> V_18 ) ;
return V_35 ;
}
}
F_28 ( & V_4 -> V_46 , & V_40 -> V_46 ) ;
return V_35 ;
}
static int F_42 ( struct V_39 * V_40 )
{
struct V_15 * V_16 ;
int V_47 = 0 ;
int V_48 = 0 ;
F_21 ( & V_17 ) ;
F_22 (o, &ifeoplist, list) {
V_47 = F_40 ( V_40 , V_16 -> V_6 , NULL , 0 , true ) ;
if ( V_47 == 0 )
V_48 += 1 ;
}
F_24 ( & V_17 ) ;
if ( V_48 )
return 0 ;
else
return - V_14 ;
}
static int F_43 ( struct V_7 * V_8 , struct V_39 * V_40 )
{
struct V_3 * V_49 ;
struct V_50 * V_51 ;
unsigned char * V_52 = F_44 ( V_8 ) ;
int V_53 = 0 ;
if ( F_45 ( & V_40 -> V_46 ) )
return 0 ;
V_51 = F_46 ( V_8 , V_54 ) ;
if ( ! V_51 )
goto V_55;
F_22 (e, &ife->metalist, metalist) {
if ( ! V_49 -> V_34 -> V_26 ( V_8 , V_49 ) )
V_53 += 1 ;
}
if ( ! V_53 )
goto V_55;
F_47 ( V_8 , V_51 ) ;
return 0 ;
V_55:
F_48 ( V_8 , V_52 ) ;
return - 1 ;
}
static void F_49 ( struct V_56 * V_57 , int V_58 )
{
struct V_39 * V_40 = F_50 ( V_57 ) ;
struct V_3 * V_49 , * V_59 ;
F_51 (e, n, &ife->metalist, metalist) {
F_39 ( V_49 -> V_34 -> V_18 ) ;
F_30 ( & V_49 -> V_46 ) ;
if ( V_49 -> V_1 ) {
if ( V_49 -> V_34 -> V_29 )
V_49 -> V_34 -> V_29 ( V_49 ) ;
else
F_17 ( V_49 -> V_1 ) ;
}
F_17 ( V_49 ) ;
}
}
static void F_52 ( struct V_56 * V_57 , int V_58 )
{
struct V_39 * V_40 = F_50 ( V_57 ) ;
F_38 ( & V_40 -> V_42 ) ;
F_49 ( V_57 , V_58 ) ;
F_34 ( & V_40 -> V_42 ) ;
}
static int F_53 ( struct V_39 * V_40 , struct V_50 * * V_60 ,
bool V_41 )
{
int V_13 = 0 ;
int V_47 = 0 ;
int V_61 = 0 ;
void * V_12 ;
for ( V_61 = 1 ; V_61 < V_62 ; V_61 ++ ) {
if ( V_60 [ V_61 ] ) {
V_12 = F_54 ( V_60 [ V_61 ] ) ;
V_13 = F_55 ( V_60 [ V_61 ] ) ;
V_47 = F_32 ( V_40 , V_61 , V_12 , V_13 , V_41 ) ;
if ( V_47 != 0 )
return V_47 ;
V_47 = F_40 ( V_40 , V_61 , V_12 , V_13 , V_41 ) ;
if ( V_47 )
return V_47 ;
}
}
return V_47 ;
}
static int F_56 ( struct V_63 * V_63 , struct V_50 * V_64 ,
struct V_50 * V_65 , struct V_56 * * V_57 ,
int V_66 , int V_58 )
{
struct V_67 * V_68 = F_57 ( V_63 , V_69 ) ;
struct V_50 * V_60 [ V_70 + 1 ] ;
struct V_50 * V_71 [ V_72 + 1 ] ;
struct V_39 * V_40 ;
T_1 V_73 = V_74 ;
struct V_75 * V_76 ;
T_3 * V_77 = NULL ;
T_3 * V_78 = NULL ;
bool V_41 = false ;
int V_35 = 0 ;
int V_32 ;
V_32 = F_58 ( V_60 , V_70 , V_64 , V_79 , NULL ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_60 [ V_80 ] )
return - V_14 ;
V_76 = F_54 ( V_60 [ V_80 ] ) ;
V_41 = F_59 ( V_68 , V_76 -> V_81 , V_57 , V_58 ) ;
if ( V_41 && V_58 )
return 0 ;
if ( ! V_41 ) {
V_35 = F_60 ( V_68 , V_76 -> V_81 , V_65 , V_57 , & V_82 ,
V_58 , false ) ;
if ( V_35 )
return V_35 ;
V_35 = V_83 ;
} else {
F_61 ( * V_57 , V_58 ) ;
if ( ! V_66 )
return - V_28 ;
}
V_40 = F_50 ( * V_57 ) ;
V_40 -> V_84 = V_76 -> V_84 ;
if ( V_76 -> V_84 & V_85 ) {
if ( V_60 [ V_86 ] )
V_73 = F_62 ( V_60 [ V_86 ] ) ;
if ( V_60 [ V_87 ] )
V_77 = F_54 ( V_60 [ V_87 ] ) ;
if ( V_60 [ V_88 ] )
V_78 = F_54 ( V_60 [ V_88 ] ) ;
}
if ( V_41 )
F_38 ( & V_40 -> V_42 ) ;
V_40 -> V_89 = V_76 -> V_90 ;
if ( V_76 -> V_84 & V_85 ) {
if ( V_77 )
F_63 ( V_40 -> V_91 , V_77 ) ;
else
F_64 ( V_40 -> V_91 ) ;
if ( V_78 )
F_63 ( V_40 -> V_92 , V_78 ) ;
else
F_64 ( V_40 -> V_92 ) ;
V_40 -> V_93 = V_73 ;
}
if ( V_35 == V_83 )
F_65 ( & V_40 -> V_46 ) ;
if ( V_60 [ V_54 ] ) {
V_32 = F_58 ( V_71 , V_72 , V_60 [ V_54 ] ,
NULL , NULL ) ;
if ( V_32 ) {
V_94:
if ( V_41 )
F_61 ( * V_57 , V_58 ) ;
if ( V_35 == V_83 )
F_49 ( * V_57 , V_58 ) ;
if ( V_41 )
F_34 ( & V_40 -> V_42 ) ;
return V_32 ;
}
V_32 = F_53 ( V_40 , V_71 , V_41 ) ;
if ( V_32 )
goto V_94;
} else {
V_32 = F_42 ( V_40 ) ;
if ( V_32 ) {
if ( V_35 == V_83 )
F_49 ( * V_57 , V_58 ) ;
if ( V_41 )
F_34 ( & V_40 -> V_42 ) ;
return V_32 ;
}
}
if ( V_41 )
F_34 ( & V_40 -> V_42 ) ;
if ( V_35 == V_83 )
F_66 ( V_68 , * V_57 ) ;
return V_35 ;
}
static int F_67 ( struct V_7 * V_8 , struct V_56 * V_57 , int V_58 ,
int V_95 )
{
unsigned char * V_52 = F_44 ( V_8 ) ;
struct V_39 * V_40 = F_50 ( V_57 ) ;
struct V_75 V_96 = {
. V_81 = V_40 -> V_97 ,
. V_98 = V_40 -> V_99 - V_95 ,
. V_100 = V_40 -> V_101 - V_58 ,
. V_90 = V_40 -> V_89 ,
. V_84 = V_40 -> V_84 ,
} ;
struct V_102 V_103 ;
if ( F_6 ( V_8 , V_80 , sizeof( V_96 ) , & V_96 ) )
goto V_104;
F_68 ( & V_103 , & V_40 -> V_105 ) ;
if ( F_69 ( V_8 , V_106 , sizeof( V_103 ) , & V_103 , V_107 ) )
goto V_104;
if ( ! F_70 ( V_40 -> V_91 ) ) {
if ( F_6 ( V_8 , V_87 , V_108 , V_40 -> V_91 ) )
goto V_104;
}
if ( ! F_70 ( V_40 -> V_92 ) ) {
if ( F_6 ( V_8 , V_88 , V_108 , V_40 -> V_92 ) )
goto V_104;
}
if ( F_6 ( V_8 , V_86 , 2 , & V_40 -> V_93 ) )
goto V_104;
if ( F_43 ( V_8 , V_40 ) ) {
F_71 ( L_2 ) ;
}
return V_8 -> V_13 ;
V_104:
F_48 ( V_8 , V_52 ) ;
return - 1 ;
}
static int F_72 ( struct V_7 * V_8 , struct V_39 * V_40 ,
T_1 V_6 , T_1 V_109 , void * V_110 )
{
struct V_3 * V_49 ;
F_22 (e, &ife->metalist, metalist) {
if ( V_6 == V_49 -> V_6 ) {
if ( V_49 -> V_34 ) {
return V_49 -> V_34 -> V_25 ( V_8 , V_110 , V_109 ) ;
}
}
}
return 0 ;
}
static int F_73 ( struct V_7 * V_8 , const struct V_56 * V_57 ,
struct V_111 * V_112 )
{
struct V_39 * V_40 = F_50 ( V_57 ) ;
int V_90 = V_40 -> V_89 ;
T_3 * V_113 ;
T_3 * V_114 ;
T_1 V_115 ;
F_74 ( & V_40 -> V_42 ) ;
F_75 ( & V_40 -> V_116 , V_8 ) ;
F_76 ( & V_40 -> V_105 ) ;
F_77 ( & V_40 -> V_42 ) ;
if ( F_78 ( V_8 ) )
F_79 ( V_8 , V_8 -> V_117 -> V_118 ) ;
V_114 = F_80 ( V_8 , & V_115 ) ;
if ( F_81 ( ! V_114 ) ) {
F_74 ( & V_40 -> V_42 ) ;
V_40 -> V_119 . V_120 ++ ;
F_77 ( & V_40 -> V_42 ) ;
return V_121 ;
}
V_113 = V_114 + V_115 ;
for (; V_114 < V_113 ; V_114 = F_82 ( V_114 ) ) {
T_3 * V_122 ;
T_1 V_123 ;
T_1 V_124 ;
V_122 = F_83 ( V_114 , & V_123 , & V_124 , NULL ) ;
if ( F_72 ( V_8 , V_40 , V_123 , V_124 , V_122 ) ) {
F_84 ( L_3 ,
V_123 , V_124 ) ;
V_40 -> V_119 . V_125 ++ ;
}
}
if ( F_85 ( V_114 != V_113 ) ) {
F_74 ( & V_40 -> V_42 ) ;
V_40 -> V_119 . V_120 ++ ;
F_77 ( & V_40 -> V_42 ) ;
return V_121 ;
}
V_8 -> V_126 = F_86 ( V_8 , V_8 -> V_117 ) ;
F_87 ( V_8 ) ;
return V_90 ;
}
static int F_88 ( struct V_7 * V_8 , struct V_39 * V_40 )
{
struct V_3 * V_49 , * V_59 ;
int V_127 = 0 , V_128 = 0 ;
F_51 (e, n, &ife->metalist, metalist) {
if ( V_49 -> V_34 -> V_23 ) {
V_128 = V_49 -> V_34 -> V_23 ( V_8 , V_49 ) ;
V_127 += V_128 ;
}
}
return V_127 ;
}
static int F_89 ( struct V_7 * V_8 , const struct V_56 * V_57 ,
struct V_111 * V_112 )
{
struct V_39 * V_40 = F_50 ( V_57 ) ;
int V_90 = V_40 -> V_89 ;
struct V_129 * V_130 ;
struct V_3 * V_49 ;
T_1 V_115 = F_88 ( V_8 , V_40 ) ;
int V_131 = V_115 + V_8 -> V_117 -> V_118 + V_132 ;
unsigned int V_133 = 0 ;
int V_134 = V_8 -> V_13 + V_131 ;
bool V_135 = false ;
void * V_136 ;
int V_32 = 0 ;
if ( ! F_78 ( V_8 ) ) {
if ( V_134 > V_8 -> V_117 -> V_137 )
V_135 = true ;
}
F_74 ( & V_40 -> V_42 ) ;
F_75 ( & V_40 -> V_116 , V_8 ) ;
F_76 ( & V_40 -> V_105 ) ;
if ( ! V_115 ) {
V_40 -> V_119 . V_125 ++ ;
F_77 ( & V_40 -> V_42 ) ;
return V_90 ;
}
if ( ( V_90 == V_121 ) || V_135 ) {
V_40 -> V_119 . V_120 ++ ;
F_77 ( & V_40 -> V_42 ) ;
return V_121 ;
}
if ( F_78 ( V_8 ) )
F_79 ( V_8 , V_8 -> V_117 -> V_118 ) ;
V_136 = F_90 ( V_8 , V_115 ) ;
F_22 (e, &ife->metalist, metalist) {
if ( V_49 -> V_34 -> V_24 ) {
V_32 = V_49 -> V_34 -> V_24 ( V_8 , ( void * ) ( V_136 + V_133 ) ,
V_49 ) ;
}
if ( V_32 < 0 ) {
V_40 -> V_119 . V_120 ++ ;
F_77 ( & V_40 -> V_42 ) ;
return V_121 ;
}
V_133 += V_32 ;
}
V_130 = (struct V_129 * ) V_8 -> V_138 ;
if ( ! F_70 ( V_40 -> V_92 ) )
F_63 ( V_130 -> V_139 , V_40 -> V_92 ) ;
if ( ! F_70 ( V_40 -> V_91 ) )
F_63 ( V_130 -> V_140 , V_40 -> V_91 ) ;
V_130 -> V_141 = F_2 ( V_40 -> V_93 ) ;
if ( F_78 ( V_8 ) )
F_91 ( V_8 , V_8 -> V_117 -> V_118 ) ;
F_77 ( & V_40 -> V_42 ) ;
return V_90 ;
}
static int F_92 ( struct V_7 * V_8 , const struct V_56 * V_57 ,
struct V_111 * V_112 )
{
struct V_39 * V_40 = F_50 ( V_57 ) ;
if ( V_40 -> V_84 & V_85 )
return F_89 ( V_8 , V_57 , V_112 ) ;
if ( ! ( V_40 -> V_84 & V_85 ) )
return F_73 ( V_8 , V_57 , V_112 ) ;
F_84 ( L_4 ) ;
F_74 ( & V_40 -> V_42 ) ;
F_75 ( & V_40 -> V_116 , V_8 ) ;
F_76 ( & V_40 -> V_105 ) ;
V_40 -> V_119 . V_120 ++ ;
F_77 ( & V_40 -> V_42 ) ;
return V_121 ;
}
static int F_93 ( struct V_63 * V_63 , struct V_7 * V_8 ,
struct V_142 * V_143 , int type ,
const struct V_144 * V_34 )
{
struct V_67 * V_68 = F_57 ( V_63 , V_69 ) ;
return F_94 ( V_68 , V_8 , V_143 , type , V_34 ) ;
}
static int F_95 ( struct V_63 * V_63 , struct V_56 * * V_57 , V_9 V_81 )
{
struct V_67 * V_68 = F_57 ( V_63 , V_69 ) ;
return F_96 ( V_68 , V_57 , V_81 ) ;
}
static T_4 int F_97 ( struct V_63 * V_63 )
{
struct V_67 * V_68 = F_57 ( V_63 , V_69 ) ;
return F_98 ( V_68 , & V_82 ) ;
}
static void T_5 F_99 ( struct V_63 * V_63 )
{
struct V_67 * V_68 = F_57 ( V_63 , V_69 ) ;
F_100 ( V_68 ) ;
}
static int T_6 F_101 ( void )
{
return F_102 ( & V_82 , & V_145 ) ;
}
static void T_7 F_103 ( void )
{
F_104 ( & V_82 , & V_145 ) ;
}
