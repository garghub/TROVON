static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
if ( V_4 -> V_8 ) {
F_4 ( V_4 -> V_8 -> V_9 ) ;
F_4 ( V_4 -> V_8 ) ;
}
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
F_6 ( & V_11 -> V_12 ) ;
F_7 ( & V_4 -> V_13 ) ;
F_8 ( & V_11 -> V_12 ) ;
F_9 ( & V_4 -> V_14 ) ;
F_10 ( & V_4 -> V_5 , F_1 ) ;
}
int F_11 ( struct V_3 * V_4 , bool V_15 , bool V_16 )
{
int V_17 = 0 ;
if ( V_4 ) {
if ( V_15 )
V_4 -> V_18 -- ;
else if ( V_16 && V_4 -> V_18 > 0 )
return - V_19 ;
V_4 -> V_20 -- ;
if ( V_4 -> V_18 <= 0 && V_4 -> V_20 <= 0 ) {
if ( V_4 -> V_21 -> V_22 )
V_4 -> V_21 -> V_22 ( V_4 , V_15 ) ;
F_5 ( V_4 -> V_11 , V_4 ) ;
V_17 = V_23 ;
}
}
return V_17 ;
}
static int F_12 ( struct V_10 * V_11 , struct V_24 * V_25 ,
struct V_26 * V_27 )
{
int V_28 = 0 , V_29 = - 1 , V_30 = 0 , V_31 = 0 , V_32 = 0 ;
struct V_33 * V_34 ;
F_6 ( & V_11 -> V_12 ) ;
V_31 = V_27 -> args [ 0 ] ;
for ( V_30 = 0 ; V_30 < ( V_11 -> V_35 + 1 ) ; V_30 ++ ) {
struct V_36 * V_2 ;
struct V_3 * V_4 ;
V_2 = & V_11 -> V_37 [ F_13 ( V_30 , V_11 -> V_35 ) ] ;
F_14 (p, head, tcfa_head) {
V_29 ++ ;
if ( V_29 < V_31 )
continue;
V_34 = F_15 ( V_25 , V_32 ) ;
if ( V_34 == NULL )
goto V_38;
V_28 = F_16 ( V_25 , V_4 , 0 , 0 ) ;
if ( V_28 < 0 ) {
V_29 -- ;
F_17 ( V_25 , V_34 ) ;
goto V_39;
}
F_18 ( V_25 , V_34 ) ;
V_32 ++ ;
if ( V_32 >= V_40 )
goto V_39;
}
}
V_39:
F_8 ( & V_11 -> V_12 ) ;
if ( V_32 )
V_27 -> args [ 0 ] += V_32 ;
return V_32 ;
V_38:
F_19 ( V_25 , V_34 ) ;
goto V_39;
}
static int F_20 ( struct V_10 * V_11 , struct V_24 * V_25 ,
const struct V_41 * V_21 )
{
struct V_33 * V_34 ;
int V_30 = 0 , V_32 = 0 ;
int V_17 = - V_42 ;
V_34 = F_15 ( V_25 , 0 ) ;
if ( V_34 == NULL )
goto V_38;
if ( F_21 ( V_25 , V_43 , V_21 -> V_44 ) )
goto V_38;
for ( V_30 = 0 ; V_30 < ( V_11 -> V_35 + 1 ) ; V_30 ++ ) {
struct V_36 * V_2 ;
struct V_45 * V_46 ;
struct V_3 * V_4 ;
V_2 = & V_11 -> V_37 [ F_13 ( V_30 , V_11 -> V_35 ) ] ;
F_22 (p, n, head, tcfa_head) {
V_17 = F_11 ( V_4 , false , true ) ;
if ( V_17 == V_23 ) {
F_23 ( V_4 -> V_21 -> V_47 ) ;
V_32 ++ ;
} else if ( V_17 < 0 )
goto V_38;
}
}
if ( F_24 ( V_25 , V_48 , V_32 ) )
goto V_38;
F_18 ( V_25 , V_34 ) ;
return V_32 ;
V_38:
F_19 ( V_25 , V_34 ) ;
return V_17 ;
}
int F_25 ( struct V_49 * V_50 , struct V_24 * V_25 ,
struct V_26 * V_27 , int type ,
const struct V_41 * V_21 )
{
struct V_10 * V_11 = V_50 -> V_11 ;
if ( type == V_51 ) {
return F_20 ( V_11 , V_25 , V_21 ) ;
} else if ( type == V_52 ) {
return F_12 ( V_11 , V_25 , V_27 ) ;
} else {
F_26 ( 1 , L_1 , type ) ;
return - V_42 ;
}
}
static struct V_3 * F_27 ( T_1 V_29 , struct V_10 * V_11 )
{
struct V_3 * V_4 = NULL ;
struct V_36 * V_2 ;
F_6 ( & V_11 -> V_12 ) ;
V_2 = & V_11 -> V_37 [ F_13 ( V_29 , V_11 -> V_35 ) ] ;
F_14 (p, head, tcfa_head)
if ( V_4 -> V_53 == V_29 )
break;
F_8 ( & V_11 -> V_12 ) ;
return V_4 ;
}
T_1 F_28 ( struct V_49 * V_50 )
{
struct V_10 * V_11 = V_50 -> V_11 ;
T_1 V_54 = V_11 -> V_29 ;
do {
if ( ++ V_54 == 0 )
V_54 = 1 ;
} while ( F_27 ( V_54 , V_11 ) );
V_11 -> V_29 = V_54 ;
return V_54 ;
}
int F_29 ( struct V_49 * V_50 , struct V_3 * * V_55 , T_1 V_29 )
{
struct V_10 * V_11 = V_50 -> V_11 ;
struct V_3 * V_4 = F_27 ( V_29 , V_11 ) ;
if ( V_4 ) {
* V_55 = V_4 ;
return 1 ;
}
return 0 ;
}
bool F_30 ( struct V_49 * V_50 , T_1 V_29 , struct V_3 * * V_55 ,
int V_15 )
{
struct V_10 * V_11 = V_50 -> V_11 ;
struct V_3 * V_4 = NULL ;
if ( V_29 && ( V_4 = F_27 ( V_29 , V_11 ) ) != NULL ) {
if ( V_15 )
V_4 -> V_18 ++ ;
V_4 -> V_20 ++ ;
* V_55 = V_4 ;
return true ;
}
return false ;
}
void F_31 ( struct V_3 * V_55 , struct V_33 * V_56 )
{
if ( V_56 )
F_9 ( & V_55 -> V_14 ) ;
F_10 ( & V_55 -> V_5 , F_1 ) ;
}
int F_32 ( struct V_49 * V_50 , T_1 V_29 , struct V_33 * V_56 ,
struct V_3 * * V_55 , const struct V_41 * V_21 ,
int V_15 , bool V_57 )
{
struct V_3 * V_4 = F_33 ( V_21 -> V_58 , V_59 ) ;
struct V_10 * V_11 = V_50 -> V_11 ;
int V_28 = - V_60 ;
if ( F_34 ( ! V_4 ) )
return - V_60 ;
V_4 -> V_20 = 1 ;
if ( V_15 )
V_4 -> V_18 = 1 ;
if ( V_57 ) {
V_4 -> V_6 = F_35 ( struct V_61 ) ;
if ( ! V_4 -> V_6 ) {
V_62:
F_4 ( V_4 ) ;
return V_28 ;
}
V_4 -> V_7 = F_36 ( struct V_63 ) ;
if ( ! V_4 -> V_7 ) {
V_64:
F_3 ( V_4 -> V_6 ) ;
goto V_62;
}
}
F_37 ( & V_4 -> V_65 ) ;
F_38 ( & V_4 -> V_13 ) ;
V_4 -> V_53 = V_29 ? V_29 : F_28 ( V_50 ) ;
V_4 -> V_66 . V_67 = V_68 ;
V_4 -> V_66 . V_69 = V_68 ;
V_4 -> V_66 . V_70 = 0 ;
if ( V_56 ) {
V_28 = F_39 ( & V_4 -> V_71 , V_4 -> V_6 ,
& V_4 -> V_14 ,
& V_4 -> V_65 , NULL , V_56 ) ;
if ( V_28 ) {
F_3 ( V_4 -> V_7 ) ;
goto V_64;
}
}
V_4 -> V_11 = V_11 ;
V_4 -> V_21 = V_21 ;
F_40 ( & V_4 -> V_72 ) ;
* V_55 = V_4 ;
return 0 ;
}
void F_41 ( struct V_49 * V_50 , struct V_3 * V_55 )
{
struct V_10 * V_11 = V_50 -> V_11 ;
unsigned int V_73 = F_13 ( V_55 -> V_53 , V_11 -> V_35 ) ;
F_6 ( & V_11 -> V_12 ) ;
F_42 ( & V_55 -> V_13 , & V_11 -> V_37 [ V_73 ] ) ;
F_8 ( & V_11 -> V_12 ) ;
}
void F_43 ( const struct V_41 * V_21 ,
struct V_10 * V_11 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_11 -> V_35 + 1 ; V_30 ++ ) {
struct V_3 * V_4 ;
struct V_45 * V_46 ;
F_22 (p, n, &hinfo->htab[i], tcfa_head) {
int V_17 ;
V_17 = F_11 ( V_4 , false , true ) ;
if ( V_17 == V_23 )
F_23 ( V_21 -> V_47 ) ;
else if ( V_17 < 0 )
return;
}
}
F_4 ( V_11 -> V_37 ) ;
}
int F_44 ( struct V_41 * V_74 ,
struct V_75 * V_21 )
{
struct V_41 * V_55 ;
int V_17 ;
if ( ! V_74 -> V_74 || ! V_74 -> V_76 || ! V_74 -> V_77 || ! V_74 -> V_78 || ! V_74 -> V_79 )
return - V_42 ;
V_17 = F_45 ( V_21 ) ;
if ( V_17 )
return V_17 ;
F_46 ( & V_80 ) ;
F_47 (a, &act_base, head) {
if ( V_74 -> type == V_55 -> type || ( strcmp ( V_74 -> V_44 , V_55 -> V_44 ) == 0 ) ) {
F_48 ( & V_80 ) ;
F_49 ( V_21 ) ;
return - V_81 ;
}
}
F_50 ( & V_74 -> V_2 , & V_82 ) ;
F_48 ( & V_80 ) ;
return 0 ;
}
int F_51 ( struct V_41 * V_74 ,
struct V_75 * V_21 )
{
struct V_41 * V_55 ;
int V_28 = - V_83 ;
F_46 ( & V_80 ) ;
F_47 (a, &act_base, head) {
if ( V_55 == V_74 ) {
F_52 ( & V_74 -> V_2 ) ;
V_28 = 0 ;
break;
}
}
F_48 ( & V_80 ) ;
if ( ! V_28 )
F_49 ( V_21 ) ;
return V_28 ;
}
static struct V_41 * F_53 ( char * V_44 )
{
struct V_41 * V_55 , * V_84 = NULL ;
if ( V_44 ) {
F_54 ( & V_80 ) ;
F_47 (a, &act_base, head) {
if ( strcmp ( V_44 , V_55 -> V_44 ) == 0 ) {
if ( F_55 ( V_55 -> V_47 ) )
V_84 = V_55 ;
break;
}
}
F_56 ( & V_80 ) ;
}
return V_84 ;
}
static struct V_41 * F_57 ( struct V_33 * V_44 )
{
struct V_41 * V_55 , * V_84 = NULL ;
if ( V_44 ) {
F_54 ( & V_80 ) ;
F_47 (a, &act_base, head) {
if ( F_58 ( V_44 , V_55 -> V_44 ) == 0 ) {
if ( F_55 ( V_55 -> V_47 ) )
V_84 = V_55 ;
break;
}
}
F_56 ( & V_80 ) ;
}
return V_84 ;
}
int F_59 ( struct V_24 * V_25 , struct V_3 * * V_85 ,
int V_86 , struct V_87 * V_84 )
{
int V_17 = - 1 , V_30 ;
T_1 V_88 = 0 ;
T_1 V_89 = V_40 ;
if ( F_60 ( V_25 ) )
return V_90 ;
V_91:
for ( V_30 = 0 ; V_30 < V_86 ; V_30 ++ ) {
const struct V_3 * V_55 = V_85 [ V_30 ] ;
if ( V_88 > 0 ) {
V_88 -= 1 ;
continue;
}
V_92:
V_17 = V_55 -> V_21 -> V_74 ( V_25 , V_55 , V_84 ) ;
if ( V_17 == V_93 )
goto V_92;
if ( F_61 ( V_17 , V_94 ) ) {
V_88 = V_17 & V_95 ;
if ( ! V_88 || ( V_88 > V_86 ) ) {
return V_90 ;
} else {
V_89 -= 1 ;
if ( V_89 > 0 )
goto V_91;
else
return V_90 ;
}
}
if ( V_17 != V_96 )
break;
}
return V_17 ;
}
int F_62 ( struct V_97 * V_85 , int V_15 )
{
struct V_3 * V_55 , * V_98 ;
int V_17 = 0 ;
F_63 (a, tmp, actions, list) {
V_17 = F_11 ( V_55 , V_15 , true ) ;
if ( V_17 == V_23 )
F_23 ( V_55 -> V_21 -> V_47 ) ;
else if ( V_17 < 0 )
return V_17 ;
}
return V_17 ;
}
int
F_64 ( struct V_24 * V_25 , struct V_3 * V_55 , int V_15 , int V_99 )
{
return V_55 -> V_21 -> V_76 ( V_25 , V_55 , V_15 , V_99 ) ;
}
int
F_16 ( struct V_24 * V_25 , struct V_3 * V_55 , int V_15 , int V_99 )
{
int V_28 = - V_42 ;
unsigned char * V_100 = F_65 ( V_25 ) ;
struct V_33 * V_34 ;
if ( F_21 ( V_25 , V_43 , V_55 -> V_21 -> V_44 ) )
goto V_38;
if ( F_66 ( V_25 , V_55 , 0 ) )
goto V_38;
if ( V_55 -> V_8 ) {
if ( F_67 ( V_25 , V_101 , V_55 -> V_8 -> V_102 ,
V_55 -> V_8 -> V_9 ) )
goto V_38;
}
V_34 = F_15 ( V_25 , V_103 ) ;
if ( V_34 == NULL )
goto V_38;
V_28 = F_64 ( V_25 , V_55 , V_15 , V_99 ) ;
if ( V_28 > 0 ) {
F_18 ( V_25 , V_34 ) ;
return V_28 ;
}
V_38:
F_17 ( V_25 , V_100 ) ;
return - 1 ;
}
int F_68 ( struct V_24 * V_25 , struct V_97 * V_85 ,
int V_15 , int V_99 )
{
struct V_3 * V_55 ;
int V_28 = - V_42 ;
struct V_33 * V_34 ;
F_47 (a, actions, list) {
V_34 = F_15 ( V_25 , V_55 -> V_104 ) ;
if ( V_34 == NULL )
goto V_38;
V_28 = F_16 ( V_25 , V_55 , V_15 , V_99 ) ;
if ( V_28 < 0 )
goto V_105;
F_18 ( V_25 , V_34 ) ;
}
return 0 ;
V_38:
V_28 = - V_42 ;
V_105:
F_19 ( V_25 , V_34 ) ;
return V_28 ;
}
static struct V_106 * F_69 ( struct V_33 * * V_107 )
{
struct V_106 * V_108 = F_33 ( sizeof( * V_108 ) , V_59 ) ;
if ( ! V_108 )
return NULL ;
V_108 -> V_9 = F_70 ( V_107 [ V_101 ] , V_59 ) ;
if ( ! V_108 -> V_9 ) {
F_4 ( V_108 ) ;
return NULL ;
}
V_108 -> V_102 = F_71 ( V_107 [ V_101 ] ) ;
return V_108 ;
}
struct V_3 * F_72 ( struct V_109 * V_109 , struct V_33 * V_110 ,
struct V_33 * V_56 , char * V_111 , int V_112 ,
int V_15 )
{
struct V_3 * V_55 ;
struct V_41 * V_113 ;
struct V_106 * V_114 = NULL ;
char V_115 [ V_116 ] ;
struct V_33 * V_107 [ V_117 + 1 ] ;
struct V_33 * V_44 ;
int V_28 ;
if ( V_111 == NULL ) {
V_28 = F_73 ( V_107 , V_117 , V_110 , NULL , NULL ) ;
if ( V_28 < 0 )
goto V_118;
V_28 = - V_42 ;
V_44 = V_107 [ V_119 ] ;
if ( V_44 == NULL )
goto V_118;
if ( F_74 ( V_115 , V_44 , V_116 ) >= V_116 )
goto V_118;
if ( V_107 [ V_101 ] ) {
int V_120 = F_71 ( V_107 [ V_101 ] ) ;
if ( V_120 > V_121 )
goto V_118;
V_114 = F_69 ( V_107 ) ;
if ( ! V_114 ) {
V_28 = - V_60 ;
goto V_118;
}
}
} else {
V_28 = - V_42 ;
if ( F_75 ( V_115 , V_111 , V_116 ) >= V_116 )
goto V_118;
}
V_113 = F_53 ( V_115 ) ;
if ( V_113 == NULL ) {
#ifdef F_76
F_77 () ;
F_78 ( L_2 , V_115 ) ;
F_79 () ;
V_113 = F_53 ( V_115 ) ;
if ( V_113 != NULL ) {
V_28 = - V_122 ;
goto V_123;
}
#endif
V_28 = - V_83 ;
goto V_118;
}
if ( V_111 == NULL )
V_28 = V_113 -> V_77 ( V_109 , V_107 [ V_124 ] , V_56 , & V_55 , V_112 , V_15 ) ;
else
V_28 = V_113 -> V_77 ( V_109 , V_110 , V_56 , & V_55 , V_112 , V_15 ) ;
if ( V_28 < 0 )
goto V_123;
if ( V_111 == NULL && V_107 [ V_101 ] ) {
if ( V_55 -> V_8 ) {
F_4 ( V_55 -> V_8 -> V_9 ) ;
F_4 ( V_55 -> V_8 ) ;
}
V_55 -> V_8 = V_114 ;
}
if ( V_28 != V_125 )
F_23 ( V_113 -> V_47 ) ;
return V_55 ;
V_123:
F_23 ( V_113 -> V_47 ) ;
V_118:
if ( V_114 ) {
F_4 ( V_114 -> V_9 ) ;
F_4 ( V_114 ) ;
}
return F_80 ( V_28 ) ;
}
static void F_81 ( struct V_97 * V_85 , int V_112 )
{
struct V_3 * V_55 ;
if ( ! V_112 )
return;
F_47 (a, actions, list)
V_55 -> V_20 -- ;
}
int F_82 ( struct V_109 * V_109 , struct V_33 * V_110 , struct V_33 * V_56 ,
char * V_111 , int V_112 , int V_15 , struct V_97 * V_85 )
{
struct V_33 * V_107 [ V_40 + 1 ] ;
struct V_3 * V_74 ;
int V_28 ;
int V_30 ;
V_28 = F_73 ( V_107 , V_40 , V_110 , NULL , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
for ( V_30 = 1 ; V_30 <= V_40 && V_107 [ V_30 ] ; V_30 ++ ) {
V_74 = F_72 ( V_109 , V_107 [ V_30 ] , V_56 , V_111 , V_112 , V_15 ) ;
if ( F_83 ( V_74 ) ) {
V_28 = F_84 ( V_74 ) ;
goto V_28;
}
V_74 -> V_104 = V_30 ;
if ( V_112 )
V_74 -> V_20 ++ ;
F_50 ( & V_74 -> V_72 , V_85 ) ;
}
F_81 ( V_85 , V_112 ) ;
return 0 ;
V_28:
F_62 ( V_85 , V_15 ) ;
return V_28 ;
}
int F_66 ( struct V_24 * V_25 , struct V_3 * V_4 ,
int V_126 )
{
int V_28 = 0 ;
struct V_127 V_128 ;
if ( V_4 == NULL )
goto V_105;
if ( V_126 ) {
if ( V_4 -> type == V_129 )
V_28 = F_85 ( V_25 , 0 ,
V_130 ,
V_131 ,
& V_4 -> V_65 , & V_128 ,
V_132 ) ;
else
return 0 ;
} else
V_28 = F_86 ( V_25 , V_133 ,
& V_4 -> V_65 , & V_128 , V_134 ) ;
if ( V_28 < 0 )
goto V_105;
if ( F_87 ( NULL , & V_128 , V_4 -> V_6 , & V_4 -> V_71 ) < 0 ||
F_88 ( & V_128 , & V_4 -> V_14 ) < 0 ||
F_89 ( & V_128 , V_4 -> V_7 ,
& V_4 -> V_135 ,
V_4 -> V_135 . V_136 ) < 0 )
goto V_105;
if ( F_90 ( & V_128 ) < 0 )
goto V_105;
return 0 ;
V_105:
return - 1 ;
}
static int F_91 ( struct V_24 * V_25 , struct V_97 * V_85 ,
T_1 V_137 , T_1 V_138 , T_2 V_139 , int V_140 , int V_15 ,
int V_99 )
{
struct V_141 * V_142 ;
struct V_143 * V_144 ;
unsigned char * V_100 = F_65 ( V_25 ) ;
struct V_33 * V_34 ;
V_144 = F_92 ( V_25 , V_137 , V_138 , V_140 , sizeof( * V_142 ) , V_139 ) ;
if ( ! V_144 )
goto V_145;
V_142 = F_93 ( V_144 ) ;
V_142 -> V_146 = V_147 ;
V_142 -> V_148 = 0 ;
V_142 -> V_149 = 0 ;
V_34 = F_15 ( V_25 , V_150 ) ;
if ( V_34 == NULL )
goto V_145;
if ( F_68 ( V_25 , V_85 , V_15 , V_99 ) < 0 )
goto V_145;
F_18 ( V_25 , V_34 ) ;
V_144 -> V_151 = F_65 ( V_25 ) - V_100 ;
return V_25 -> V_102 ;
V_145:
F_17 ( V_25 , V_100 ) ;
return - 1 ;
}
static int
F_94 ( struct V_109 * V_109 , T_1 V_137 , struct V_143 * V_46 ,
struct V_97 * V_85 , int V_140 )
{
struct V_24 * V_25 ;
V_25 = F_95 ( V_152 , V_59 ) ;
if ( ! V_25 )
return - V_153 ;
if ( F_91 ( V_25 , V_85 , V_137 , V_46 -> V_154 , 0 , V_140 ,
0 , 0 ) <= 0 ) {
F_96 ( V_25 ) ;
return - V_42 ;
}
return F_97 ( V_25 , V_109 , V_137 ) ;
}
static struct V_3 * F_98 ( struct V_109 * V_109 , struct V_33 * V_110 ,
struct V_143 * V_46 , T_1 V_137 )
{
struct V_33 * V_107 [ V_117 + 1 ] ;
const struct V_41 * V_21 ;
struct V_3 * V_55 ;
int V_29 ;
int V_28 ;
V_28 = F_73 ( V_107 , V_117 , V_110 , NULL , NULL ) ;
if ( V_28 < 0 )
goto V_118;
V_28 = - V_42 ;
if ( V_107 [ V_155 ] == NULL ||
F_71 ( V_107 [ V_155 ] ) < sizeof( V_29 ) )
goto V_118;
V_29 = F_99 ( V_107 [ V_155 ] ) ;
V_28 = - V_42 ;
V_21 = F_57 ( V_107 [ V_119 ] ) ;
if ( ! V_21 )
goto V_118;
V_28 = - V_83 ;
if ( V_21 -> V_79 ( V_109 , & V_55 , V_29 ) == 0 )
goto V_123;
F_23 ( V_21 -> V_47 ) ;
return V_55 ;
V_123:
F_23 ( V_21 -> V_47 ) ;
V_118:
return F_80 ( V_28 ) ;
}
static int F_100 ( struct V_109 * V_109 , struct V_33 * V_110 ,
struct V_143 * V_46 , T_1 V_137 )
{
struct V_24 * V_25 ;
unsigned char * V_100 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
struct V_26 V_156 ;
struct V_33 * V_34 ;
struct V_33 * V_107 [ V_117 + 1 ] ;
const struct V_41 * V_21 ;
struct V_33 * V_44 ;
int V_28 = - V_60 ;
V_25 = F_95 ( V_152 , V_59 ) ;
if ( ! V_25 ) {
F_101 ( L_3 ) ;
return V_28 ;
}
V_100 = F_65 ( V_25 ) ;
V_28 = F_73 ( V_107 , V_117 , V_110 , NULL , NULL ) ;
if ( V_28 < 0 )
goto V_118;
V_28 = - V_42 ;
V_44 = V_107 [ V_119 ] ;
V_21 = F_57 ( V_44 ) ;
if ( ! V_21 )
goto V_118;
V_144 = F_92 ( V_25 , V_137 , V_46 -> V_154 , V_51 ,
sizeof( * V_142 ) , 0 ) ;
if ( ! V_144 )
goto V_157;
V_142 = F_93 ( V_144 ) ;
V_142 -> V_146 = V_147 ;
V_142 -> V_148 = 0 ;
V_142 -> V_149 = 0 ;
V_34 = F_15 ( V_25 , V_150 ) ;
if ( V_34 == NULL )
goto V_157;
V_28 = V_21 -> V_78 ( V_109 , V_25 , & V_156 , V_51 , V_21 ) ;
if ( V_28 <= 0 )
goto V_157;
F_18 ( V_25 , V_34 ) ;
V_144 -> V_151 = F_65 ( V_25 ) - V_100 ;
V_144 -> V_158 |= V_159 ;
F_23 ( V_21 -> V_47 ) ;
V_28 = F_102 ( V_25 , V_109 , V_137 , V_160 ,
V_46 -> V_158 & V_161 ) ;
if ( V_28 > 0 )
return 0 ;
return V_28 ;
V_157:
F_23 ( V_21 -> V_47 ) ;
V_118:
F_96 ( V_25 ) ;
return V_28 ;
}
static int
F_103 ( struct V_109 * V_109 , struct V_143 * V_46 , struct V_97 * V_85 ,
T_1 V_137 )
{
int V_17 ;
struct V_24 * V_25 ;
V_25 = F_95 ( V_152 , V_59 ) ;
if ( ! V_25 )
return - V_153 ;
if ( F_91 ( V_25 , V_85 , V_137 , V_46 -> V_154 , 0 , V_51 ,
0 , 1 ) <= 0 ) {
F_96 ( V_25 ) ;
return - V_42 ;
}
V_17 = F_62 ( V_85 , 0 ) ;
if ( V_17 < 0 ) {
F_96 ( V_25 ) ;
return V_17 ;
}
V_17 = F_102 ( V_25 , V_109 , V_137 , V_160 ,
V_46 -> V_158 & V_161 ) ;
if ( V_17 > 0 )
return 0 ;
return V_17 ;
}
static int
F_104 ( struct V_109 * V_109 , struct V_33 * V_110 , struct V_143 * V_46 ,
T_1 V_137 , int V_140 )
{
int V_30 , V_17 ;
struct V_33 * V_107 [ V_40 + 1 ] ;
struct V_3 * V_74 ;
F_105 ( V_85 ) ;
V_17 = F_73 ( V_107 , V_40 , V_110 , NULL , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_140 == V_51 && V_46 -> V_158 & V_159 ) {
if ( V_107 [ 1 ] != NULL )
return F_100 ( V_109 , V_107 [ 1 ] , V_46 , V_137 ) ;
else
return - V_42 ;
}
for ( V_30 = 1 ; V_30 <= V_40 && V_107 [ V_30 ] ; V_30 ++ ) {
V_74 = F_98 ( V_109 , V_107 [ V_30 ] , V_46 , V_137 ) ;
if ( F_83 ( V_74 ) ) {
V_17 = F_84 ( V_74 ) ;
goto V_28;
}
V_74 -> V_104 = V_30 ;
F_50 ( & V_74 -> V_72 , & V_85 ) ;
}
if ( V_140 == V_52 )
V_17 = F_94 ( V_109 , V_137 , V_46 , & V_85 , V_140 ) ;
else {
V_17 = F_103 ( V_109 , V_46 , & V_85 , V_137 ) ;
if ( V_17 )
goto V_28;
return V_17 ;
}
V_28:
if ( V_140 != V_52 )
F_62 ( & V_85 , 0 ) ;
return V_17 ;
}
static int
F_106 ( struct V_109 * V_109 , struct V_143 * V_46 , struct V_97 * V_85 ,
T_1 V_137 )
{
struct V_24 * V_25 ;
int V_28 = 0 ;
V_25 = F_95 ( V_152 , V_59 ) ;
if ( ! V_25 )
return - V_153 ;
if ( F_91 ( V_25 , V_85 , V_137 , V_46 -> V_154 , V_46 -> V_158 ,
V_162 , 0 , 0 ) <= 0 ) {
F_96 ( V_25 ) ;
return - V_42 ;
}
V_28 = F_102 ( V_25 , V_109 , V_137 , V_160 ,
V_46 -> V_158 & V_161 ) ;
if ( V_28 > 0 )
V_28 = 0 ;
return V_28 ;
}
static int F_107 ( struct V_109 * V_109 , struct V_33 * V_110 ,
struct V_143 * V_46 , T_1 V_137 , int V_112 )
{
int V_17 = 0 ;
F_105 ( V_85 ) ;
V_17 = F_82 ( V_109 , V_110 , NULL , NULL , V_112 , 0 , & V_85 ) ;
if ( V_17 )
return V_17 ;
return F_106 ( V_109 , V_46 , & V_85 , V_137 ) ;
}
static int F_108 ( struct V_24 * V_25 , struct V_143 * V_46 ,
struct V_163 * V_164 )
{
struct V_109 * V_109 = F_109 ( V_25 -> V_165 ) ;
struct V_33 * V_166 [ V_117 + 1 ] ;
T_1 V_137 = V_25 ? F_110 ( V_25 ) . V_137 : 0 ;
int V_17 = 0 , V_112 = 0 ;
if ( ( V_46 -> V_167 != V_52 ) &&
! F_111 ( V_25 , V_168 ) )
return - V_19 ;
V_17 = F_112 ( V_46 , sizeof( struct V_141 ) , V_166 , V_117 , NULL ,
V_164 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_166 [ V_150 ] == NULL ) {
F_113 ( L_4 ) ;
return - V_42 ;
}
switch ( V_46 -> V_167 ) {
case V_162 :
if ( V_46 -> V_158 & V_169 )
V_112 = 1 ;
V_170:
V_17 = F_107 ( V_109 , V_166 [ V_150 ] , V_46 , V_137 , V_112 ) ;
if ( V_17 == - V_122 )
goto V_170;
break;
case V_51 :
V_17 = F_104 ( V_109 , V_166 [ V_150 ] , V_46 ,
V_137 , V_51 ) ;
break;
case V_52 :
V_17 = F_104 ( V_109 , V_166 [ V_150 ] , V_46 ,
V_137 , V_52 ) ;
break;
default:
F_114 () ;
}
return V_17 ;
}
static struct V_33 * F_115 ( const struct V_143 * V_46 )
{
struct V_33 * V_171 , * V_172 [ V_117 + 1 ] ;
struct V_33 * V_107 [ V_40 + 1 ] ;
struct V_33 * V_110 [ V_173 + 1 ] ;
struct V_33 * V_44 ;
if ( F_112 ( V_46 , sizeof( struct V_141 ) , V_110 , V_173 ,
NULL , NULL ) < 0 )
return NULL ;
V_171 = V_110 [ V_150 ] ;
if ( V_171 == NULL )
return NULL ;
if ( F_116 ( V_107 , V_40 , F_117 ( V_171 ) ,
F_118 ( F_71 ( V_171 ) ) , NULL , NULL ) < 0 )
return NULL ;
if ( V_107 [ 1 ] == NULL )
return NULL ;
if ( F_73 ( V_172 , V_117 , V_107 [ 1 ] , NULL , NULL ) < 0 )
return NULL ;
V_44 = V_172 [ V_119 ] ;
return V_44 ;
}
static int F_119 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_109 * V_109 = F_109 ( V_25 -> V_165 ) ;
struct V_143 * V_144 ;
unsigned char * V_100 = F_65 ( V_25 ) ;
struct V_33 * V_34 ;
struct V_41 * V_113 ;
int V_17 = 0 ;
struct V_141 * V_142 = (struct V_141 * ) F_93 ( V_27 -> V_144 ) ;
struct V_33 * V_44 = F_115 ( V_27 -> V_144 ) ;
if ( V_44 == NULL ) {
F_120 ( L_5 ) ;
return 0 ;
}
V_113 = F_57 ( V_44 ) ;
if ( V_113 == NULL )
return 0 ;
V_144 = F_92 ( V_25 , F_110 ( V_27 -> V_25 ) . V_137 , V_27 -> V_144 -> V_154 ,
V_27 -> V_144 -> V_167 , sizeof( * V_142 ) , 0 ) ;
if ( ! V_144 )
goto V_157;
V_142 = F_93 ( V_144 ) ;
V_142 -> V_146 = V_147 ;
V_142 -> V_148 = 0 ;
V_142 -> V_149 = 0 ;
V_34 = F_15 ( V_25 , V_150 ) ;
if ( V_34 == NULL )
goto V_157;
V_17 = V_113 -> V_78 ( V_109 , V_25 , V_27 , V_52 , V_113 ) ;
if ( V_17 < 0 )
goto V_157;
if ( V_17 > 0 ) {
F_18 ( V_25 , V_34 ) ;
V_17 = V_25 -> V_102 ;
} else
F_17 ( V_25 , V_100 ) ;
V_144 -> V_151 = F_65 ( V_25 ) - V_100 ;
if ( F_110 ( V_27 -> V_25 ) . V_137 && V_17 )
V_144 -> V_158 |= V_174 ;
F_23 ( V_113 -> V_47 ) ;
return V_25 -> V_102 ;
V_157:
F_23 ( V_113 -> V_47 ) ;
F_17 ( V_25 , V_100 ) ;
return V_25 -> V_102 ;
}
static int T_3 F_121 ( void )
{
F_122 ( V_175 , V_162 , F_108 , NULL , NULL ) ;
F_122 ( V_175 , V_51 , F_108 , NULL , NULL ) ;
F_122 ( V_175 , V_52 , F_108 , F_119 ,
NULL ) ;
return 0 ;
}
