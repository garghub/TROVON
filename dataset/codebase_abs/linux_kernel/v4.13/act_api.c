static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 = V_2 -> V_6 & V_7 ;
if ( ! V_4 )
return - V_8 ;
V_2 -> V_9 = F_2 ( V_4 -> V_10 -> V_11 , V_5 , true ) ;
if ( ! V_2 -> V_9 )
return - V_12 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_9 ) ;
}
static void F_5 ( const struct V_1 * V_2 ,
struct V_13 * V_14 )
{
const struct V_15 * V_10 = V_2 -> V_9 ;
V_14 -> V_16 = F_6 ( V_10 -> V_17 ) ;
}
static void F_7 ( struct V_18 * V_19 )
{
struct V_1 * V_20 = F_8 ( V_19 , struct V_1 , V_21 ) ;
F_9 ( V_20 -> V_22 ) ;
F_9 ( V_20 -> V_23 ) ;
if ( V_20 -> V_24 ) {
F_10 ( V_20 -> V_24 -> V_25 ) ;
F_10 ( V_20 -> V_24 ) ;
}
if ( V_20 -> V_9 )
F_3 ( V_20 ) ;
F_10 ( V_20 ) ;
}
static void F_11 ( struct V_26 * V_27 , struct V_1 * V_20 )
{
F_12 ( & V_27 -> V_28 ) ;
F_13 ( & V_20 -> V_29 ) ;
F_14 ( & V_27 -> V_28 ) ;
F_15 ( & V_20 -> V_30 ) ;
F_16 ( & V_20 -> V_21 , F_7 ) ;
}
int F_17 ( struct V_1 * V_20 , bool V_31 , bool V_32 )
{
int V_33 = 0 ;
if ( V_20 ) {
if ( V_31 )
V_20 -> V_34 -- ;
else if ( V_32 && V_20 -> V_34 > 0 )
return - V_35 ;
V_20 -> V_36 -- ;
if ( V_20 -> V_34 <= 0 && V_20 -> V_36 <= 0 ) {
if ( V_20 -> V_37 -> V_38 )
V_20 -> V_37 -> V_38 ( V_20 , V_31 ) ;
F_11 ( V_20 -> V_27 , V_20 ) ;
V_33 = V_39 ;
}
}
return V_33 ;
}
static int F_18 ( struct V_26 * V_27 , struct V_40 * V_41 ,
struct V_42 * V_43 )
{
int V_44 = 0 , V_45 = - 1 , V_46 = 0 , V_47 = 0 , V_48 = 0 ;
struct V_49 * V_50 ;
F_12 ( & V_27 -> V_28 ) ;
V_47 = V_43 -> args [ 0 ] ;
for ( V_46 = 0 ; V_46 < ( V_27 -> V_51 + 1 ) ; V_46 ++ ) {
struct V_52 * V_19 ;
struct V_1 * V_20 ;
V_19 = & V_27 -> V_53 [ F_19 ( V_46 , V_27 -> V_51 ) ] ;
F_20 (p, head, tcfa_head) {
V_45 ++ ;
if ( V_45 < V_47 )
continue;
V_50 = F_21 ( V_41 , V_48 ) ;
if ( V_50 == NULL )
goto V_54;
V_44 = F_22 ( V_41 , V_20 , 0 , 0 ) ;
if ( V_44 < 0 ) {
V_45 -- ;
F_23 ( V_41 , V_50 ) ;
goto V_55;
}
F_24 ( V_41 , V_50 ) ;
V_48 ++ ;
if ( V_48 >= V_56 )
goto V_55;
}
}
V_55:
F_14 ( & V_27 -> V_28 ) ;
if ( V_48 )
V_43 -> args [ 0 ] += V_48 ;
return V_48 ;
V_54:
F_25 ( V_41 , V_50 ) ;
goto V_55;
}
static int F_26 ( struct V_26 * V_27 , struct V_40 * V_41 ,
const struct V_57 * V_37 )
{
struct V_49 * V_50 ;
int V_46 = 0 , V_48 = 0 ;
int V_33 = - V_8 ;
V_50 = F_21 ( V_41 , 0 ) ;
if ( V_50 == NULL )
goto V_54;
if ( F_27 ( V_41 , V_58 , V_37 -> V_59 ) )
goto V_54;
for ( V_46 = 0 ; V_46 < ( V_27 -> V_51 + 1 ) ; V_46 ++ ) {
struct V_52 * V_19 ;
struct V_60 * V_61 ;
struct V_1 * V_20 ;
V_19 = & V_27 -> V_53 [ F_19 ( V_46 , V_27 -> V_51 ) ] ;
F_28 (p, n, head, tcfa_head) {
V_33 = F_17 ( V_20 , false , true ) ;
if ( V_33 == V_39 ) {
F_29 ( V_20 -> V_37 -> V_62 ) ;
V_48 ++ ;
} else if ( V_33 < 0 )
goto V_54;
}
}
if ( F_30 ( V_41 , V_63 , V_48 ) )
goto V_54;
F_24 ( V_41 , V_50 ) ;
return V_48 ;
V_54:
F_25 ( V_41 , V_50 ) ;
return V_33 ;
}
int F_31 ( struct V_64 * V_65 , struct V_40 * V_41 ,
struct V_42 * V_43 , int type ,
const struct V_57 * V_37 )
{
struct V_26 * V_27 = V_65 -> V_27 ;
if ( type == V_66 ) {
return F_26 ( V_27 , V_41 , V_37 ) ;
} else if ( type == V_67 ) {
return F_18 ( V_27 , V_41 , V_43 ) ;
} else {
F_32 ( 1 , L_1 , type ) ;
return - V_8 ;
}
}
static struct V_1 * F_33 ( T_1 V_45 , struct V_26 * V_27 )
{
struct V_1 * V_20 = NULL ;
struct V_52 * V_19 ;
F_12 ( & V_27 -> V_28 ) ;
V_19 = & V_27 -> V_53 [ F_19 ( V_45 , V_27 -> V_51 ) ] ;
F_20 (p, head, tcfa_head)
if ( V_20 -> V_68 == V_45 )
break;
F_14 ( & V_27 -> V_28 ) ;
return V_20 ;
}
T_1 F_34 ( struct V_64 * V_65 )
{
struct V_26 * V_27 = V_65 -> V_27 ;
T_1 V_69 = V_27 -> V_45 ;
do {
if ( ++ V_69 == 0 )
V_69 = 1 ;
} while ( F_33 ( V_69 , V_27 ) );
V_27 -> V_45 = V_69 ;
return V_69 ;
}
int F_35 ( struct V_64 * V_65 , struct V_1 * * V_2 , T_1 V_45 )
{
struct V_26 * V_27 = V_65 -> V_27 ;
struct V_1 * V_20 = F_33 ( V_45 , V_27 ) ;
if ( V_20 ) {
* V_2 = V_20 ;
return 1 ;
}
return 0 ;
}
bool F_36 ( struct V_64 * V_65 , T_1 V_45 , struct V_1 * * V_2 ,
int V_31 )
{
struct V_26 * V_27 = V_65 -> V_27 ;
struct V_1 * V_20 = NULL ;
if ( V_45 && ( V_20 = F_33 ( V_45 , V_27 ) ) != NULL ) {
if ( V_31 )
V_20 -> V_34 ++ ;
V_20 -> V_36 ++ ;
* V_2 = V_20 ;
return true ;
}
return false ;
}
void F_37 ( struct V_1 * V_2 , struct V_49 * V_70 )
{
if ( V_70 )
F_15 ( & V_2 -> V_30 ) ;
F_16 ( & V_2 -> V_21 , F_7 ) ;
}
int F_38 ( struct V_64 * V_65 , T_1 V_45 , struct V_49 * V_70 ,
struct V_1 * * V_2 , const struct V_57 * V_37 ,
int V_31 , bool V_71 )
{
struct V_1 * V_20 = F_39 ( V_37 -> V_72 , V_73 ) ;
struct V_26 * V_27 = V_65 -> V_27 ;
int V_44 = - V_12 ;
if ( F_40 ( ! V_20 ) )
return - V_12 ;
V_20 -> V_36 = 1 ;
if ( V_31 )
V_20 -> V_34 = 1 ;
if ( V_71 ) {
V_20 -> V_22 = F_41 ( struct V_74 ) ;
if ( ! V_20 -> V_22 ) {
V_75:
F_10 ( V_20 ) ;
return V_44 ;
}
V_20 -> V_23 = F_42 ( struct V_76 ) ;
if ( ! V_20 -> V_23 ) {
V_77:
F_9 ( V_20 -> V_22 ) ;
goto V_75;
}
}
F_43 ( & V_20 -> V_78 ) ;
F_44 ( & V_20 -> V_29 ) ;
V_20 -> V_68 = V_45 ? V_45 : F_34 ( V_65 ) ;
V_20 -> V_79 . V_80 = V_81 ;
V_20 -> V_79 . V_82 = V_81 ;
V_20 -> V_79 . V_83 = 0 ;
if ( V_70 ) {
V_44 = F_45 ( & V_20 -> V_84 , V_20 -> V_22 ,
& V_20 -> V_30 ,
& V_20 -> V_78 , NULL , V_70 ) ;
if ( V_44 ) {
F_9 ( V_20 -> V_23 ) ;
goto V_77;
}
}
V_20 -> V_27 = V_27 ;
V_20 -> V_37 = V_37 ;
F_46 ( & V_20 -> V_85 ) ;
* V_2 = V_20 ;
return 0 ;
}
void F_47 ( struct V_64 * V_65 , struct V_1 * V_2 )
{
struct V_26 * V_27 = V_65 -> V_27 ;
unsigned int V_86 = F_19 ( V_2 -> V_68 , V_27 -> V_51 ) ;
F_12 ( & V_27 -> V_28 ) ;
F_48 ( & V_2 -> V_29 , & V_27 -> V_53 [ V_86 ] ) ;
F_14 ( & V_27 -> V_28 ) ;
}
void F_49 ( const struct V_57 * V_37 ,
struct V_26 * V_27 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_27 -> V_51 + 1 ; V_46 ++ ) {
struct V_1 * V_20 ;
struct V_60 * V_61 ;
F_28 (p, n, &hinfo->htab[i], tcfa_head) {
int V_33 ;
V_33 = F_17 ( V_20 , false , true ) ;
if ( V_33 == V_39 )
F_29 ( V_37 -> V_62 ) ;
else if ( V_33 < 0 )
return;
}
}
F_10 ( V_27 -> V_53 ) ;
}
int F_50 ( struct V_57 * V_87 ,
struct V_88 * V_37 )
{
struct V_57 * V_2 ;
int V_33 ;
if ( ! V_87 -> V_87 || ! V_87 -> V_89 || ! V_87 -> V_90 || ! V_87 -> V_91 || ! V_87 -> V_92 )
return - V_8 ;
V_33 = F_51 ( V_37 ) ;
if ( V_33 )
return V_33 ;
F_52 ( & V_93 ) ;
F_53 (a, &act_base, head) {
if ( V_87 -> type == V_2 -> type || ( strcmp ( V_87 -> V_59 , V_2 -> V_59 ) == 0 ) ) {
F_54 ( & V_93 ) ;
F_55 ( V_37 ) ;
return - V_94 ;
}
}
F_56 ( & V_87 -> V_19 , & V_95 ) ;
F_54 ( & V_93 ) ;
return 0 ;
}
int F_57 ( struct V_57 * V_87 ,
struct V_88 * V_37 )
{
struct V_57 * V_2 ;
int V_44 = - V_96 ;
F_52 ( & V_93 ) ;
F_53 (a, &act_base, head) {
if ( V_2 == V_87 ) {
F_58 ( & V_87 -> V_19 ) ;
V_44 = 0 ;
break;
}
}
F_54 ( & V_93 ) ;
if ( ! V_44 )
F_55 ( V_37 ) ;
return V_44 ;
}
static struct V_57 * F_59 ( char * V_59 )
{
struct V_57 * V_2 , * V_14 = NULL ;
if ( V_59 ) {
F_60 ( & V_93 ) ;
F_53 (a, &act_base, head) {
if ( strcmp ( V_59 , V_2 -> V_59 ) == 0 ) {
if ( F_61 ( V_2 -> V_62 ) )
V_14 = V_2 ;
break;
}
}
F_62 ( & V_93 ) ;
}
return V_14 ;
}
static struct V_57 * F_63 ( struct V_49 * V_59 )
{
struct V_57 * V_2 , * V_14 = NULL ;
if ( V_59 ) {
F_60 ( & V_93 ) ;
F_53 (a, &act_base, head) {
if ( F_64 ( V_59 , V_2 -> V_59 ) == 0 ) {
if ( F_61 ( V_2 -> V_62 ) )
V_14 = V_2 ;
break;
}
}
F_62 ( & V_93 ) ;
}
return V_14 ;
}
int F_65 ( struct V_40 * V_41 , struct V_1 * * V_97 ,
int V_98 , struct V_13 * V_14 )
{
int V_33 = - 1 , V_46 ;
T_1 V_99 = 0 ;
T_1 V_100 = V_56 ;
if ( F_66 ( V_41 ) )
return V_101 ;
V_102:
for ( V_46 = 0 ; V_46 < V_98 ; V_46 ++ ) {
const struct V_1 * V_2 = V_97 [ V_46 ] ;
if ( V_99 > 0 ) {
V_99 -= 1 ;
continue;
}
V_103:
V_33 = V_2 -> V_37 -> V_87 ( V_41 , V_2 , V_14 ) ;
if ( V_33 == V_104 )
goto V_103;
if ( F_67 ( V_33 , V_105 ) ) {
V_99 = V_33 & V_106 ;
if ( ! V_99 || ( V_99 > V_98 ) ) {
return V_101 ;
} else {
V_100 -= 1 ;
if ( V_100 > 0 )
goto V_102;
else
return V_101 ;
}
} else if ( F_67 ( V_33 , V_107 ) ) {
F_5 ( V_2 , V_14 ) ;
}
if ( V_33 != V_108 )
break;
}
return V_33 ;
}
int F_68 ( struct V_109 * V_97 , int V_31 )
{
struct V_1 * V_2 , * V_110 ;
int V_33 = 0 ;
F_69 (a, tmp, actions, list) {
V_33 = F_17 ( V_2 , V_31 , true ) ;
if ( V_33 == V_39 )
F_29 ( V_2 -> V_37 -> V_62 ) ;
else if ( V_33 < 0 )
return V_33 ;
}
return V_33 ;
}
int
F_70 ( struct V_40 * V_41 , struct V_1 * V_2 , int V_31 , int V_111 )
{
return V_2 -> V_37 -> V_89 ( V_41 , V_2 , V_31 , V_111 ) ;
}
int
F_22 ( struct V_40 * V_41 , struct V_1 * V_2 , int V_31 , int V_111 )
{
int V_44 = - V_8 ;
unsigned char * V_112 = F_71 ( V_41 ) ;
struct V_49 * V_50 ;
if ( F_27 ( V_41 , V_58 , V_2 -> V_37 -> V_59 ) )
goto V_54;
if ( F_72 ( V_41 , V_2 , 0 ) )
goto V_54;
if ( V_2 -> V_24 ) {
if ( F_73 ( V_41 , V_113 , V_2 -> V_24 -> V_114 ,
V_2 -> V_24 -> V_25 ) )
goto V_54;
}
V_50 = F_21 ( V_41 , V_115 ) ;
if ( V_50 == NULL )
goto V_54;
V_44 = F_70 ( V_41 , V_2 , V_31 , V_111 ) ;
if ( V_44 > 0 ) {
F_24 ( V_41 , V_50 ) ;
return V_44 ;
}
V_54:
F_23 ( V_41 , V_112 ) ;
return - 1 ;
}
int F_74 ( struct V_40 * V_41 , struct V_109 * V_97 ,
int V_31 , int V_111 )
{
struct V_1 * V_2 ;
int V_44 = - V_8 ;
struct V_49 * V_50 ;
F_53 (a, actions, list) {
V_50 = F_21 ( V_41 , V_2 -> V_116 ) ;
if ( V_50 == NULL )
goto V_54;
V_44 = F_22 ( V_41 , V_2 , V_31 , V_111 ) ;
if ( V_44 < 0 )
goto V_117;
F_24 ( V_41 , V_50 ) ;
}
return 0 ;
V_54:
V_44 = - V_8 ;
V_117:
F_25 ( V_41 , V_50 ) ;
return V_44 ;
}
static struct V_118 * F_75 ( struct V_49 * * V_119 )
{
struct V_118 * V_120 = F_39 ( sizeof( * V_120 ) , V_73 ) ;
if ( ! V_120 )
return NULL ;
V_120 -> V_25 = F_76 ( V_119 [ V_113 ] , V_73 ) ;
if ( ! V_120 -> V_25 ) {
F_10 ( V_120 ) ;
return NULL ;
}
V_120 -> V_114 = F_77 ( V_119 [ V_113 ] ) ;
return V_120 ;
}
struct V_1 * F_78 ( struct V_121 * V_121 , struct V_3 * V_4 ,
struct V_49 * V_122 , struct V_49 * V_70 ,
char * V_123 , int V_124 , int V_31 )
{
struct V_1 * V_2 ;
struct V_57 * V_125 ;
struct V_118 * V_126 = NULL ;
char V_127 [ V_128 ] ;
struct V_49 * V_119 [ V_129 + 1 ] ;
struct V_49 * V_59 ;
int V_44 ;
if ( V_123 == NULL ) {
V_44 = F_79 ( V_119 , V_129 , V_122 , NULL , NULL ) ;
if ( V_44 < 0 )
goto V_130;
V_44 = - V_8 ;
V_59 = V_119 [ V_131 ] ;
if ( V_59 == NULL )
goto V_130;
if ( F_80 ( V_127 , V_59 , V_128 ) >= V_128 )
goto V_130;
if ( V_119 [ V_113 ] ) {
int V_132 = F_77 ( V_119 [ V_113 ] ) ;
if ( V_132 > V_133 )
goto V_130;
V_126 = F_75 ( V_119 ) ;
if ( ! V_126 ) {
V_44 = - V_12 ;
goto V_130;
}
}
} else {
V_44 = - V_8 ;
if ( F_81 ( V_127 , V_123 , V_128 ) >= V_128 )
goto V_130;
}
V_125 = F_59 ( V_127 ) ;
if ( V_125 == NULL ) {
#ifdef F_82
F_83 () ;
F_84 ( L_2 , V_127 ) ;
F_85 () ;
V_125 = F_59 ( V_127 ) ;
if ( V_125 != NULL ) {
V_44 = - V_134 ;
goto V_135;
}
#endif
V_44 = - V_96 ;
goto V_130;
}
if ( V_123 == NULL )
V_44 = V_125 -> V_90 ( V_121 , V_119 [ V_136 ] , V_70 , & V_2 , V_124 , V_31 ) ;
else
V_44 = V_125 -> V_90 ( V_121 , V_122 , V_70 , & V_2 , V_124 , V_31 ) ;
if ( V_44 < 0 )
goto V_135;
if ( V_123 == NULL && V_119 [ V_113 ] ) {
if ( V_2 -> V_24 ) {
F_10 ( V_2 -> V_24 -> V_25 ) ;
F_10 ( V_2 -> V_24 ) ;
}
V_2 -> V_24 = V_126 ;
}
if ( V_44 != V_137 )
F_29 ( V_125 -> V_62 ) ;
if ( F_67 ( V_2 -> V_6 , V_107 ) ) {
V_44 = F_1 ( V_2 , V_4 ) ;
if ( V_44 ) {
F_86 ( V_97 ) ;
F_56 ( & V_2 -> V_85 , & V_97 ) ;
F_68 ( & V_97 , V_31 ) ;
return F_87 ( V_44 ) ;
}
}
return V_2 ;
V_135:
F_29 ( V_125 -> V_62 ) ;
V_130:
if ( V_126 ) {
F_10 ( V_126 -> V_25 ) ;
F_10 ( V_126 ) ;
}
return F_87 ( V_44 ) ;
}
static void F_88 ( struct V_109 * V_97 , int V_124 )
{
struct V_1 * V_2 ;
if ( ! V_124 )
return;
F_53 (a, actions, list)
V_2 -> V_36 -- ;
}
int F_89 ( struct V_121 * V_121 , struct V_3 * V_4 , struct V_49 * V_122 ,
struct V_49 * V_70 , char * V_123 , int V_124 , int V_31 ,
struct V_109 * V_97 )
{
struct V_49 * V_119 [ V_56 + 1 ] ;
struct V_1 * V_87 ;
int V_44 ;
int V_46 ;
V_44 = F_79 ( V_119 , V_56 , V_122 , NULL , NULL ) ;
if ( V_44 < 0 )
return V_44 ;
for ( V_46 = 1 ; V_46 <= V_56 && V_119 [ V_46 ] ; V_46 ++ ) {
V_87 = F_78 ( V_121 , V_4 , V_119 [ V_46 ] , V_70 , V_123 , V_124 , V_31 ) ;
if ( F_90 ( V_87 ) ) {
V_44 = F_91 ( V_87 ) ;
goto V_44;
}
V_87 -> V_116 = V_46 ;
if ( V_124 )
V_87 -> V_36 ++ ;
F_56 ( & V_87 -> V_85 , V_97 ) ;
}
F_88 ( V_97 , V_124 ) ;
return 0 ;
V_44:
F_68 ( V_97 , V_31 ) ;
return V_44 ;
}
int F_72 ( struct V_40 * V_41 , struct V_1 * V_20 ,
int V_138 )
{
int V_44 = 0 ;
struct V_139 V_140 ;
if ( V_20 == NULL )
goto V_117;
if ( V_138 ) {
if ( V_20 -> type == V_141 )
V_44 = F_92 ( V_41 , 0 ,
V_142 ,
V_143 ,
& V_20 -> V_78 , & V_140 ,
V_144 ) ;
else
return 0 ;
} else
V_44 = F_93 ( V_41 , V_145 ,
& V_20 -> V_78 , & V_140 , V_146 ) ;
if ( V_44 < 0 )
goto V_117;
if ( F_94 ( NULL , & V_140 , V_20 -> V_22 , & V_20 -> V_84 ) < 0 ||
F_95 ( & V_140 , & V_20 -> V_30 ) < 0 ||
F_96 ( & V_140 , V_20 -> V_23 ,
& V_20 -> V_147 ,
V_20 -> V_147 . V_148 ) < 0 )
goto V_117;
if ( F_97 ( & V_140 ) < 0 )
goto V_117;
return 0 ;
V_117:
return - 1 ;
}
static int F_98 ( struct V_40 * V_41 , struct V_109 * V_97 ,
T_1 V_149 , T_1 V_150 , T_2 V_151 , int V_152 , int V_31 ,
int V_111 )
{
struct V_153 * V_154 ;
struct V_155 * V_156 ;
unsigned char * V_112 = F_71 ( V_41 ) ;
struct V_49 * V_50 ;
V_156 = F_99 ( V_41 , V_149 , V_150 , V_152 , sizeof( * V_154 ) , V_151 ) ;
if ( ! V_156 )
goto V_157;
V_154 = F_100 ( V_156 ) ;
V_154 -> V_158 = V_159 ;
V_154 -> V_160 = 0 ;
V_154 -> V_161 = 0 ;
V_50 = F_21 ( V_41 , V_162 ) ;
if ( V_50 == NULL )
goto V_157;
if ( F_74 ( V_41 , V_97 , V_31 , V_111 ) < 0 )
goto V_157;
F_24 ( V_41 , V_50 ) ;
V_156 -> V_163 = F_71 ( V_41 ) - V_112 ;
return V_41 -> V_114 ;
V_157:
F_23 ( V_41 , V_112 ) ;
return - 1 ;
}
static int
F_101 ( struct V_121 * V_121 , T_1 V_149 , struct V_155 * V_61 ,
struct V_109 * V_97 , int V_152 )
{
struct V_40 * V_41 ;
V_41 = F_102 ( V_164 , V_73 ) ;
if ( ! V_41 )
return - V_165 ;
if ( F_98 ( V_41 , V_97 , V_149 , V_61 -> V_166 , 0 , V_152 ,
0 , 0 ) <= 0 ) {
F_103 ( V_41 ) ;
return - V_8 ;
}
return F_104 ( V_41 , V_121 , V_149 ) ;
}
static struct V_1 * F_105 ( struct V_121 * V_121 , struct V_49 * V_122 ,
struct V_155 * V_61 , T_1 V_149 )
{
struct V_49 * V_119 [ V_129 + 1 ] ;
const struct V_57 * V_37 ;
struct V_1 * V_2 ;
int V_45 ;
int V_44 ;
V_44 = F_79 ( V_119 , V_129 , V_122 , NULL , NULL ) ;
if ( V_44 < 0 )
goto V_130;
V_44 = - V_8 ;
if ( V_119 [ V_167 ] == NULL ||
F_77 ( V_119 [ V_167 ] ) < sizeof( V_45 ) )
goto V_130;
V_45 = F_106 ( V_119 [ V_167 ] ) ;
V_44 = - V_8 ;
V_37 = F_63 ( V_119 [ V_131 ] ) ;
if ( ! V_37 )
goto V_130;
V_44 = - V_96 ;
if ( V_37 -> V_92 ( V_121 , & V_2 , V_45 ) == 0 )
goto V_135;
F_29 ( V_37 -> V_62 ) ;
return V_2 ;
V_135:
F_29 ( V_37 -> V_62 ) ;
V_130:
return F_87 ( V_44 ) ;
}
static int F_107 ( struct V_121 * V_121 , struct V_49 * V_122 ,
struct V_155 * V_61 , T_1 V_149 )
{
struct V_40 * V_41 ;
unsigned char * V_112 ;
struct V_155 * V_156 ;
struct V_153 * V_154 ;
struct V_42 V_168 ;
struct V_49 * V_50 ;
struct V_49 * V_119 [ V_129 + 1 ] ;
const struct V_57 * V_37 ;
struct V_49 * V_59 ;
int V_44 = - V_12 ;
V_41 = F_102 ( V_164 , V_73 ) ;
if ( ! V_41 ) {
F_108 ( L_3 ) ;
return V_44 ;
}
V_112 = F_71 ( V_41 ) ;
V_44 = F_79 ( V_119 , V_129 , V_122 , NULL , NULL ) ;
if ( V_44 < 0 )
goto V_130;
V_44 = - V_8 ;
V_59 = V_119 [ V_131 ] ;
V_37 = F_63 ( V_59 ) ;
if ( ! V_37 )
goto V_130;
V_156 = F_99 ( V_41 , V_149 , V_61 -> V_166 , V_66 ,
sizeof( * V_154 ) , 0 ) ;
if ( ! V_156 )
goto V_169;
V_154 = F_100 ( V_156 ) ;
V_154 -> V_158 = V_159 ;
V_154 -> V_160 = 0 ;
V_154 -> V_161 = 0 ;
V_50 = F_21 ( V_41 , V_162 ) ;
if ( V_50 == NULL )
goto V_169;
V_44 = V_37 -> V_91 ( V_121 , V_41 , & V_168 , V_66 , V_37 ) ;
if ( V_44 <= 0 )
goto V_169;
F_24 ( V_41 , V_50 ) ;
V_156 -> V_163 = F_71 ( V_41 ) - V_112 ;
V_156 -> V_170 |= V_171 ;
F_29 ( V_37 -> V_62 ) ;
V_44 = F_109 ( V_41 , V_121 , V_149 , V_172 ,
V_61 -> V_170 & V_173 ) ;
if ( V_44 > 0 )
return 0 ;
return V_44 ;
V_169:
F_29 ( V_37 -> V_62 ) ;
V_130:
F_103 ( V_41 ) ;
return V_44 ;
}
static int
F_110 ( struct V_121 * V_121 , struct V_155 * V_61 , struct V_109 * V_97 ,
T_1 V_149 )
{
int V_33 ;
struct V_40 * V_41 ;
V_41 = F_102 ( V_164 , V_73 ) ;
if ( ! V_41 )
return - V_165 ;
if ( F_98 ( V_41 , V_97 , V_149 , V_61 -> V_166 , 0 , V_66 ,
0 , 1 ) <= 0 ) {
F_103 ( V_41 ) ;
return - V_8 ;
}
V_33 = F_68 ( V_97 , 0 ) ;
if ( V_33 < 0 ) {
F_103 ( V_41 ) ;
return V_33 ;
}
V_33 = F_109 ( V_41 , V_121 , V_149 , V_172 ,
V_61 -> V_170 & V_173 ) ;
if ( V_33 > 0 )
return 0 ;
return V_33 ;
}
static int
F_111 ( struct V_121 * V_121 , struct V_49 * V_122 , struct V_155 * V_61 ,
T_1 V_149 , int V_152 )
{
int V_46 , V_33 ;
struct V_49 * V_119 [ V_56 + 1 ] ;
struct V_1 * V_87 ;
F_86 ( V_97 ) ;
V_33 = F_79 ( V_119 , V_56 , V_122 , NULL , NULL ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_152 == V_66 && V_61 -> V_170 & V_171 ) {
if ( V_119 [ 1 ] != NULL )
return F_107 ( V_121 , V_119 [ 1 ] , V_61 , V_149 ) ;
else
return - V_8 ;
}
for ( V_46 = 1 ; V_46 <= V_56 && V_119 [ V_46 ] ; V_46 ++ ) {
V_87 = F_105 ( V_121 , V_119 [ V_46 ] , V_61 , V_149 ) ;
if ( F_90 ( V_87 ) ) {
V_33 = F_91 ( V_87 ) ;
goto V_44;
}
V_87 -> V_116 = V_46 ;
F_56 ( & V_87 -> V_85 , & V_97 ) ;
}
if ( V_152 == V_67 )
V_33 = F_101 ( V_121 , V_149 , V_61 , & V_97 , V_152 ) ;
else {
V_33 = F_110 ( V_121 , V_61 , & V_97 , V_149 ) ;
if ( V_33 )
goto V_44;
return V_33 ;
}
V_44:
if ( V_152 != V_67 )
F_68 ( & V_97 , 0 ) ;
return V_33 ;
}
static int
F_112 ( struct V_121 * V_121 , struct V_155 * V_61 , struct V_109 * V_97 ,
T_1 V_149 )
{
struct V_40 * V_41 ;
int V_44 = 0 ;
V_41 = F_102 ( V_164 , V_73 ) ;
if ( ! V_41 )
return - V_165 ;
if ( F_98 ( V_41 , V_97 , V_149 , V_61 -> V_166 , V_61 -> V_170 ,
V_174 , 0 , 0 ) <= 0 ) {
F_103 ( V_41 ) ;
return - V_8 ;
}
V_44 = F_109 ( V_41 , V_121 , V_149 , V_172 ,
V_61 -> V_170 & V_173 ) ;
if ( V_44 > 0 )
V_44 = 0 ;
return V_44 ;
}
static int F_113 ( struct V_121 * V_121 , struct V_49 * V_122 ,
struct V_155 * V_61 , T_1 V_149 , int V_124 )
{
int V_33 = 0 ;
F_86 ( V_97 ) ;
V_33 = F_89 ( V_121 , NULL , V_122 , NULL , NULL , V_124 , 0 , & V_97 ) ;
if ( V_33 )
return V_33 ;
return F_112 ( V_121 , V_61 , & V_97 , V_149 ) ;
}
static int F_114 ( struct V_40 * V_41 , struct V_155 * V_61 ,
struct V_175 * V_176 )
{
struct V_121 * V_121 = F_115 ( V_41 -> V_177 ) ;
struct V_49 * V_178 [ V_129 + 1 ] ;
T_1 V_149 = V_41 ? F_116 ( V_41 ) . V_149 : 0 ;
int V_33 = 0 , V_124 = 0 ;
if ( ( V_61 -> V_179 != V_67 ) &&
! F_117 ( V_41 , V_180 ) )
return - V_35 ;
V_33 = F_118 ( V_61 , sizeof( struct V_153 ) , V_178 , V_129 , NULL ,
V_176 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_178 [ V_162 ] == NULL ) {
F_119 ( L_4 ) ;
return - V_8 ;
}
switch ( V_61 -> V_179 ) {
case V_174 :
if ( V_61 -> V_170 & V_181 )
V_124 = 1 ;
V_182:
V_33 = F_113 ( V_121 , V_178 [ V_162 ] , V_61 , V_149 , V_124 ) ;
if ( V_33 == - V_134 )
goto V_182;
break;
case V_66 :
V_33 = F_111 ( V_121 , V_178 [ V_162 ] , V_61 ,
V_149 , V_66 ) ;
break;
case V_67 :
V_33 = F_111 ( V_121 , V_178 [ V_162 ] , V_61 ,
V_149 , V_67 ) ;
break;
default:
F_120 () ;
}
return V_33 ;
}
static struct V_49 * F_121 ( const struct V_155 * V_61 )
{
struct V_49 * V_183 , * V_184 [ V_129 + 1 ] ;
struct V_49 * V_119 [ V_56 + 1 ] ;
struct V_49 * V_122 [ V_185 + 1 ] ;
struct V_49 * V_59 ;
if ( F_118 ( V_61 , sizeof( struct V_153 ) , V_122 , V_185 ,
NULL , NULL ) < 0 )
return NULL ;
V_183 = V_122 [ V_162 ] ;
if ( V_183 == NULL )
return NULL ;
if ( F_122 ( V_119 , V_56 , F_123 ( V_183 ) ,
F_124 ( F_77 ( V_183 ) ) , NULL , NULL ) < 0 )
return NULL ;
if ( V_119 [ 1 ] == NULL )
return NULL ;
if ( F_79 ( V_184 , V_129 , V_119 [ 1 ] , NULL , NULL ) < 0 )
return NULL ;
V_59 = V_184 [ V_131 ] ;
return V_59 ;
}
static int F_125 ( struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_121 * V_121 = F_115 ( V_41 -> V_177 ) ;
struct V_155 * V_156 ;
unsigned char * V_112 = F_71 ( V_41 ) ;
struct V_49 * V_50 ;
struct V_57 * V_125 ;
int V_33 = 0 ;
struct V_153 * V_154 = (struct V_153 * ) F_100 ( V_43 -> V_156 ) ;
struct V_49 * V_59 = F_121 ( V_43 -> V_156 ) ;
if ( V_59 == NULL ) {
F_126 ( L_5 ) ;
return 0 ;
}
V_125 = F_63 ( V_59 ) ;
if ( V_125 == NULL )
return 0 ;
V_156 = F_99 ( V_41 , F_116 ( V_43 -> V_41 ) . V_149 , V_43 -> V_156 -> V_166 ,
V_43 -> V_156 -> V_179 , sizeof( * V_154 ) , 0 ) ;
if ( ! V_156 )
goto V_169;
V_154 = F_100 ( V_156 ) ;
V_154 -> V_158 = V_159 ;
V_154 -> V_160 = 0 ;
V_154 -> V_161 = 0 ;
V_50 = F_21 ( V_41 , V_162 ) ;
if ( V_50 == NULL )
goto V_169;
V_33 = V_125 -> V_91 ( V_121 , V_41 , V_43 , V_67 , V_125 ) ;
if ( V_33 < 0 )
goto V_169;
if ( V_33 > 0 ) {
F_24 ( V_41 , V_50 ) ;
V_33 = V_41 -> V_114 ;
} else
F_23 ( V_41 , V_112 ) ;
V_156 -> V_163 = F_71 ( V_41 ) - V_112 ;
if ( F_116 ( V_43 -> V_41 ) . V_149 && V_33 )
V_156 -> V_170 |= V_186 ;
F_29 ( V_125 -> V_62 ) ;
return V_41 -> V_114 ;
V_169:
F_29 ( V_125 -> V_62 ) ;
F_23 ( V_41 , V_112 ) ;
return V_41 -> V_114 ;
}
static int T_3 F_127 ( void )
{
F_128 ( V_187 , V_174 , F_114 , NULL , NULL ) ;
F_128 ( V_187 , V_66 , F_114 , NULL , NULL ) ;
F_128 ( V_187 , V_67 , F_114 , F_125 ,
NULL ) ;
return 0 ;
}
