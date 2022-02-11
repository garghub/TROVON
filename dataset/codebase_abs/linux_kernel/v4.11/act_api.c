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
if ( F_60 ( V_25 ) )
return V_88 ;
for ( V_30 = 0 ; V_30 < V_86 ; V_30 ++ ) {
const struct V_3 * V_55 = V_85 [ V_30 ] ;
V_89:
V_17 = V_55 -> V_21 -> V_74 ( V_25 , V_55 , V_84 ) ;
if ( V_17 == V_90 )
goto V_89;
if ( V_17 != V_91 )
break;
}
return V_17 ;
}
int F_61 ( struct V_92 * V_85 , int V_15 )
{
struct V_3 * V_55 , * V_93 ;
int V_17 = 0 ;
F_62 (a, tmp, actions, list) {
V_17 = F_11 ( V_55 , V_15 , true ) ;
if ( V_17 == V_23 )
F_23 ( V_55 -> V_21 -> V_47 ) ;
else if ( V_17 < 0 )
return V_17 ;
}
return V_17 ;
}
int
F_63 ( struct V_24 * V_25 , struct V_3 * V_55 , int V_15 , int V_94 )
{
return V_55 -> V_21 -> V_76 ( V_25 , V_55 , V_15 , V_94 ) ;
}
int
F_16 ( struct V_24 * V_25 , struct V_3 * V_55 , int V_15 , int V_94 )
{
int V_28 = - V_42 ;
unsigned char * V_95 = F_64 ( V_25 ) ;
struct V_33 * V_34 ;
if ( F_21 ( V_25 , V_43 , V_55 -> V_21 -> V_44 ) )
goto V_38;
if ( F_65 ( V_25 , V_55 , 0 ) )
goto V_38;
if ( V_55 -> V_8 ) {
if ( F_66 ( V_25 , V_96 , V_55 -> V_8 -> V_97 ,
V_55 -> V_8 -> V_9 ) )
goto V_38;
}
V_34 = F_15 ( V_25 , V_98 ) ;
if ( V_34 == NULL )
goto V_38;
V_28 = F_63 ( V_25 , V_55 , V_15 , V_94 ) ;
if ( V_28 > 0 ) {
F_18 ( V_25 , V_34 ) ;
return V_28 ;
}
V_38:
F_17 ( V_25 , V_95 ) ;
return - 1 ;
}
int F_67 ( struct V_24 * V_25 , struct V_92 * V_85 ,
int V_15 , int V_94 )
{
struct V_3 * V_55 ;
int V_28 = - V_42 ;
struct V_33 * V_34 ;
F_47 (a, actions, list) {
V_34 = F_15 ( V_25 , V_55 -> V_99 ) ;
if ( V_34 == NULL )
goto V_38;
V_28 = F_16 ( V_25 , V_55 , V_15 , V_94 ) ;
if ( V_28 < 0 )
goto V_100;
F_18 ( V_25 , V_34 ) ;
}
return 0 ;
V_38:
V_28 = - V_42 ;
V_100:
F_19 ( V_25 , V_34 ) ;
return V_28 ;
}
static struct V_101 * F_68 ( struct V_33 * * V_102 )
{
struct V_101 * V_103 = F_33 ( sizeof( * V_103 ) , V_59 ) ;
if ( ! V_103 )
return NULL ;
V_103 -> V_9 = F_69 ( V_102 [ V_96 ] , V_59 ) ;
if ( ! V_103 -> V_9 ) {
F_4 ( V_103 ) ;
return NULL ;
}
V_103 -> V_97 = F_70 ( V_102 [ V_96 ] ) ;
return V_103 ;
}
struct V_3 * F_71 ( struct V_104 * V_104 , struct V_33 * V_105 ,
struct V_33 * V_56 , char * V_106 , int V_107 ,
int V_15 )
{
struct V_3 * V_55 ;
struct V_41 * V_108 ;
struct V_101 * V_109 = NULL ;
char V_110 [ V_111 ] ;
struct V_33 * V_102 [ V_112 + 1 ] ;
struct V_33 * V_44 ;
int V_28 ;
if ( V_106 == NULL ) {
V_28 = F_72 ( V_102 , V_112 , V_105 , NULL ) ;
if ( V_28 < 0 )
goto V_113;
V_28 = - V_42 ;
V_44 = V_102 [ V_114 ] ;
if ( V_44 == NULL )
goto V_113;
if ( F_73 ( V_110 , V_44 , V_111 ) >= V_111 )
goto V_113;
if ( V_102 [ V_96 ] ) {
int V_115 = F_70 ( V_102 [ V_96 ] ) ;
if ( V_115 > V_116 )
goto V_113;
V_109 = F_68 ( V_102 ) ;
if ( ! V_109 ) {
V_28 = - V_60 ;
goto V_113;
}
}
} else {
V_28 = - V_42 ;
if ( F_74 ( V_110 , V_106 , V_111 ) >= V_111 )
goto V_113;
}
V_108 = F_53 ( V_110 ) ;
if ( V_108 == NULL ) {
#ifdef F_75
F_76 () ;
F_77 ( L_2 , V_110 ) ;
F_78 () ;
V_108 = F_53 ( V_110 ) ;
if ( V_108 != NULL ) {
V_28 = - V_117 ;
goto V_118;
}
#endif
V_28 = - V_83 ;
goto V_113;
}
if ( V_106 == NULL )
V_28 = V_108 -> V_77 ( V_104 , V_102 [ V_119 ] , V_56 , & V_55 , V_107 , V_15 ) ;
else
V_28 = V_108 -> V_77 ( V_104 , V_105 , V_56 , & V_55 , V_107 , V_15 ) ;
if ( V_28 < 0 )
goto V_118;
if ( V_106 == NULL && V_102 [ V_96 ] ) {
if ( V_55 -> V_8 ) {
F_4 ( V_55 -> V_8 -> V_9 ) ;
F_4 ( V_55 -> V_8 ) ;
}
V_55 -> V_8 = V_109 ;
}
if ( V_28 != V_120 )
F_23 ( V_108 -> V_47 ) ;
return V_55 ;
V_118:
F_23 ( V_108 -> V_47 ) ;
V_113:
if ( V_109 ) {
F_4 ( V_109 -> V_9 ) ;
F_4 ( V_109 ) ;
}
return F_79 ( V_28 ) ;
}
static void F_80 ( struct V_92 * V_85 , int V_107 )
{
struct V_3 * V_55 ;
if ( ! V_107 )
return;
F_47 (a, actions, list)
V_55 -> V_20 -- ;
}
int F_81 ( struct V_104 * V_104 , struct V_33 * V_105 , struct V_33 * V_56 ,
char * V_106 , int V_107 , int V_15 , struct V_92 * V_85 )
{
struct V_33 * V_102 [ V_40 + 1 ] ;
struct V_3 * V_74 ;
int V_28 ;
int V_30 ;
V_28 = F_72 ( V_102 , V_40 , V_105 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
for ( V_30 = 1 ; V_30 <= V_40 && V_102 [ V_30 ] ; V_30 ++ ) {
V_74 = F_71 ( V_104 , V_102 [ V_30 ] , V_56 , V_106 , V_107 , V_15 ) ;
if ( F_82 ( V_74 ) ) {
V_28 = F_83 ( V_74 ) ;
goto V_28;
}
V_74 -> V_99 = V_30 ;
if ( V_107 )
V_74 -> V_20 ++ ;
F_50 ( & V_74 -> V_72 , V_85 ) ;
}
F_80 ( V_85 , V_107 ) ;
return 0 ;
V_28:
F_61 ( V_85 , V_15 ) ;
return V_28 ;
}
int F_65 ( struct V_24 * V_25 , struct V_3 * V_4 ,
int V_121 )
{
int V_28 = 0 ;
struct V_122 V_123 ;
if ( V_4 == NULL )
goto V_100;
if ( V_121 ) {
if ( V_4 -> type == V_124 )
V_28 = F_84 ( V_25 , 0 ,
V_125 ,
V_126 ,
& V_4 -> V_65 , & V_123 ,
V_127 ) ;
else
return 0 ;
} else
V_28 = F_85 ( V_25 , V_128 ,
& V_4 -> V_65 , & V_123 , V_129 ) ;
if ( V_28 < 0 )
goto V_100;
if ( F_86 ( NULL , & V_123 , V_4 -> V_6 , & V_4 -> V_71 ) < 0 ||
F_87 ( & V_123 , & V_4 -> V_14 ) < 0 ||
F_88 ( & V_123 , V_4 -> V_7 ,
& V_4 -> V_130 ,
V_4 -> V_130 . V_131 ) < 0 )
goto V_100;
if ( F_89 ( & V_123 ) < 0 )
goto V_100;
return 0 ;
V_100:
return - 1 ;
}
static int F_90 ( struct V_24 * V_25 , struct V_92 * V_85 ,
T_1 V_132 , T_1 V_133 , T_2 V_134 , int V_135 , int V_15 ,
int V_94 )
{
struct V_136 * V_137 ;
struct V_138 * V_139 ;
unsigned char * V_95 = F_64 ( V_25 ) ;
struct V_33 * V_34 ;
V_139 = F_91 ( V_25 , V_132 , V_133 , V_135 , sizeof( * V_137 ) , V_134 ) ;
if ( ! V_139 )
goto V_140;
V_137 = F_92 ( V_139 ) ;
V_137 -> V_141 = V_142 ;
V_137 -> V_143 = 0 ;
V_137 -> V_144 = 0 ;
V_34 = F_15 ( V_25 , V_145 ) ;
if ( V_34 == NULL )
goto V_140;
if ( F_67 ( V_25 , V_85 , V_15 , V_94 ) < 0 )
goto V_140;
F_18 ( V_25 , V_34 ) ;
V_139 -> V_146 = F_64 ( V_25 ) - V_95 ;
return V_25 -> V_97 ;
V_140:
F_17 ( V_25 , V_95 ) ;
return - 1 ;
}
static int
F_93 ( struct V_104 * V_104 , T_1 V_132 , struct V_138 * V_46 ,
struct V_92 * V_85 , int V_135 )
{
struct V_24 * V_25 ;
V_25 = F_94 ( V_147 , V_59 ) ;
if ( ! V_25 )
return - V_148 ;
if ( F_90 ( V_25 , V_85 , V_132 , V_46 -> V_149 , 0 , V_135 ,
0 , 0 ) <= 0 ) {
F_95 ( V_25 ) ;
return - V_42 ;
}
return F_96 ( V_25 , V_104 , V_132 ) ;
}
static struct V_3 * F_97 ( struct V_104 * V_104 , struct V_33 * V_105 ,
struct V_138 * V_46 , T_1 V_132 )
{
struct V_33 * V_102 [ V_112 + 1 ] ;
const struct V_41 * V_21 ;
struct V_3 * V_55 ;
int V_29 ;
int V_28 ;
V_28 = F_72 ( V_102 , V_112 , V_105 , NULL ) ;
if ( V_28 < 0 )
goto V_113;
V_28 = - V_42 ;
if ( V_102 [ V_150 ] == NULL ||
F_70 ( V_102 [ V_150 ] ) < sizeof( V_29 ) )
goto V_113;
V_29 = F_98 ( V_102 [ V_150 ] ) ;
V_28 = - V_42 ;
V_21 = F_57 ( V_102 [ V_114 ] ) ;
if ( ! V_21 )
goto V_113;
V_28 = - V_83 ;
if ( V_21 -> V_79 ( V_104 , & V_55 , V_29 ) == 0 )
goto V_118;
F_23 ( V_21 -> V_47 ) ;
return V_55 ;
V_118:
F_23 ( V_21 -> V_47 ) ;
V_113:
return F_79 ( V_28 ) ;
}
static int F_99 ( struct V_104 * V_104 , struct V_33 * V_105 ,
struct V_138 * V_46 , T_1 V_132 )
{
struct V_24 * V_25 ;
unsigned char * V_95 ;
struct V_138 * V_139 ;
struct V_136 * V_137 ;
struct V_26 V_151 ;
struct V_33 * V_34 ;
struct V_33 * V_102 [ V_112 + 1 ] ;
const struct V_41 * V_21 ;
struct V_33 * V_44 ;
int V_28 = - V_60 ;
V_25 = F_94 ( V_147 , V_59 ) ;
if ( ! V_25 ) {
F_100 ( L_3 ) ;
return V_28 ;
}
V_95 = F_64 ( V_25 ) ;
V_28 = F_72 ( V_102 , V_112 , V_105 , NULL ) ;
if ( V_28 < 0 )
goto V_113;
V_28 = - V_42 ;
V_44 = V_102 [ V_114 ] ;
V_21 = F_57 ( V_44 ) ;
if ( ! V_21 )
goto V_113;
V_139 = F_91 ( V_25 , V_132 , V_46 -> V_149 , V_51 ,
sizeof( * V_137 ) , 0 ) ;
if ( ! V_139 )
goto V_152;
V_137 = F_92 ( V_139 ) ;
V_137 -> V_141 = V_142 ;
V_137 -> V_143 = 0 ;
V_137 -> V_144 = 0 ;
V_34 = F_15 ( V_25 , V_145 ) ;
if ( V_34 == NULL )
goto V_152;
V_28 = V_21 -> V_78 ( V_104 , V_25 , & V_151 , V_51 , V_21 ) ;
if ( V_28 <= 0 )
goto V_152;
F_18 ( V_25 , V_34 ) ;
V_139 -> V_146 = F_64 ( V_25 ) - V_95 ;
V_139 -> V_153 |= V_154 ;
F_23 ( V_21 -> V_47 ) ;
V_28 = F_101 ( V_25 , V_104 , V_132 , V_155 ,
V_46 -> V_153 & V_156 ) ;
if ( V_28 > 0 )
return 0 ;
return V_28 ;
V_152:
F_23 ( V_21 -> V_47 ) ;
V_113:
F_95 ( V_25 ) ;
return V_28 ;
}
static int
F_102 ( struct V_104 * V_104 , struct V_138 * V_46 , struct V_92 * V_85 ,
T_1 V_132 )
{
int V_17 ;
struct V_24 * V_25 ;
V_25 = F_94 ( V_147 , V_59 ) ;
if ( ! V_25 )
return - V_148 ;
if ( F_90 ( V_25 , V_85 , V_132 , V_46 -> V_149 , 0 , V_51 ,
0 , 1 ) <= 0 ) {
F_95 ( V_25 ) ;
return - V_42 ;
}
V_17 = F_61 ( V_85 , 0 ) ;
if ( V_17 < 0 ) {
F_95 ( V_25 ) ;
return V_17 ;
}
V_17 = F_101 ( V_25 , V_104 , V_132 , V_155 ,
V_46 -> V_153 & V_156 ) ;
if ( V_17 > 0 )
return 0 ;
return V_17 ;
}
static int
F_103 ( struct V_104 * V_104 , struct V_33 * V_105 , struct V_138 * V_46 ,
T_1 V_132 , int V_135 )
{
int V_30 , V_17 ;
struct V_33 * V_102 [ V_40 + 1 ] ;
struct V_3 * V_74 ;
F_104 ( V_85 ) ;
V_17 = F_72 ( V_102 , V_40 , V_105 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_135 == V_51 && V_46 -> V_153 & V_154 ) {
if ( V_102 [ 1 ] != NULL )
return F_99 ( V_104 , V_102 [ 1 ] , V_46 , V_132 ) ;
else
return - V_42 ;
}
for ( V_30 = 1 ; V_30 <= V_40 && V_102 [ V_30 ] ; V_30 ++ ) {
V_74 = F_97 ( V_104 , V_102 [ V_30 ] , V_46 , V_132 ) ;
if ( F_82 ( V_74 ) ) {
V_17 = F_83 ( V_74 ) ;
goto V_28;
}
V_74 -> V_99 = V_30 ;
F_50 ( & V_74 -> V_72 , & V_85 ) ;
}
if ( V_135 == V_52 )
V_17 = F_93 ( V_104 , V_132 , V_46 , & V_85 , V_135 ) ;
else {
V_17 = F_102 ( V_104 , V_46 , & V_85 , V_132 ) ;
if ( V_17 )
goto V_28;
return V_17 ;
}
V_28:
if ( V_135 != V_52 )
F_61 ( & V_85 , 0 ) ;
return V_17 ;
}
static int
F_105 ( struct V_104 * V_104 , struct V_138 * V_46 , struct V_92 * V_85 ,
T_1 V_132 )
{
struct V_24 * V_25 ;
int V_28 = 0 ;
V_25 = F_94 ( V_147 , V_59 ) ;
if ( ! V_25 )
return - V_148 ;
if ( F_90 ( V_25 , V_85 , V_132 , V_46 -> V_149 , V_46 -> V_153 ,
V_157 , 0 , 0 ) <= 0 ) {
F_95 ( V_25 ) ;
return - V_42 ;
}
V_28 = F_101 ( V_25 , V_104 , V_132 , V_155 ,
V_46 -> V_153 & V_156 ) ;
if ( V_28 > 0 )
V_28 = 0 ;
return V_28 ;
}
static int F_106 ( struct V_104 * V_104 , struct V_33 * V_105 ,
struct V_138 * V_46 , T_1 V_132 , int V_107 )
{
int V_17 = 0 ;
F_104 ( V_85 ) ;
V_17 = F_81 ( V_104 , V_105 , NULL , NULL , V_107 , 0 , & V_85 ) ;
if ( V_17 )
return V_17 ;
return F_105 ( V_104 , V_46 , & V_85 , V_132 ) ;
}
static int F_107 ( struct V_24 * V_25 , struct V_138 * V_46 )
{
struct V_104 * V_104 = F_108 ( V_25 -> V_158 ) ;
struct V_33 * V_159 [ V_112 + 1 ] ;
T_1 V_132 = V_25 ? F_109 ( V_25 ) . V_132 : 0 ;
int V_17 = 0 , V_107 = 0 ;
if ( ( V_46 -> V_160 != V_52 ) &&
! F_110 ( V_25 , V_161 ) )
return - V_19 ;
V_17 = F_111 ( V_46 , sizeof( struct V_136 ) , V_159 , V_112 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_159 [ V_145 ] == NULL ) {
F_112 ( L_4 ) ;
return - V_42 ;
}
switch ( V_46 -> V_160 ) {
case V_157 :
if ( V_46 -> V_153 & V_162 )
V_107 = 1 ;
V_163:
V_17 = F_106 ( V_104 , V_159 [ V_145 ] , V_46 , V_132 , V_107 ) ;
if ( V_17 == - V_117 )
goto V_163;
break;
case V_51 :
V_17 = F_103 ( V_104 , V_159 [ V_145 ] , V_46 ,
V_132 , V_51 ) ;
break;
case V_52 :
V_17 = F_103 ( V_104 , V_159 [ V_145 ] , V_46 ,
V_132 , V_52 ) ;
break;
default:
F_113 () ;
}
return V_17 ;
}
static struct V_33 * F_114 ( const struct V_138 * V_46 )
{
struct V_33 * V_164 , * V_165 [ V_112 + 1 ] ;
struct V_33 * V_102 [ V_40 + 1 ] ;
struct V_33 * V_105 [ V_166 + 1 ] ;
struct V_33 * V_44 ;
if ( F_111 ( V_46 , sizeof( struct V_136 ) , V_105 , V_166 , NULL ) < 0 )
return NULL ;
V_164 = V_105 [ V_145 ] ;
if ( V_164 == NULL )
return NULL ;
if ( F_115 ( V_102 , V_40 , F_116 ( V_164 ) ,
F_117 ( F_70 ( V_164 ) ) , NULL ) < 0 )
return NULL ;
if ( V_102 [ 1 ] == NULL )
return NULL ;
if ( F_72 ( V_165 , V_112 , V_102 [ 1 ] , NULL ) < 0 )
return NULL ;
V_44 = V_165 [ V_114 ] ;
return V_44 ;
}
static int F_118 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_104 * V_104 = F_108 ( V_25 -> V_158 ) ;
struct V_138 * V_139 ;
unsigned char * V_95 = F_64 ( V_25 ) ;
struct V_33 * V_34 ;
struct V_41 * V_108 ;
int V_17 = 0 ;
struct V_136 * V_137 = (struct V_136 * ) F_92 ( V_27 -> V_139 ) ;
struct V_33 * V_44 = F_114 ( V_27 -> V_139 ) ;
if ( V_44 == NULL ) {
F_119 ( L_5 ) ;
return 0 ;
}
V_108 = F_57 ( V_44 ) ;
if ( V_108 == NULL )
return 0 ;
V_139 = F_91 ( V_25 , F_109 ( V_27 -> V_25 ) . V_132 , V_27 -> V_139 -> V_149 ,
V_27 -> V_139 -> V_160 , sizeof( * V_137 ) , 0 ) ;
if ( ! V_139 )
goto V_152;
V_137 = F_92 ( V_139 ) ;
V_137 -> V_141 = V_142 ;
V_137 -> V_143 = 0 ;
V_137 -> V_144 = 0 ;
V_34 = F_15 ( V_25 , V_145 ) ;
if ( V_34 == NULL )
goto V_152;
V_17 = V_108 -> V_78 ( V_104 , V_25 , V_27 , V_52 , V_108 ) ;
if ( V_17 < 0 )
goto V_152;
if ( V_17 > 0 ) {
F_18 ( V_25 , V_34 ) ;
V_17 = V_25 -> V_97 ;
} else
F_17 ( V_25 , V_95 ) ;
V_139 -> V_146 = F_64 ( V_25 ) - V_95 ;
if ( F_109 ( V_27 -> V_25 ) . V_132 && V_17 )
V_139 -> V_153 |= V_167 ;
F_23 ( V_108 -> V_47 ) ;
return V_25 -> V_97 ;
V_152:
F_23 ( V_108 -> V_47 ) ;
F_17 ( V_25 , V_95 ) ;
return V_25 -> V_97 ;
}
static int T_3 F_120 ( void )
{
F_121 ( V_168 , V_157 , F_107 , NULL , NULL ) ;
F_121 ( V_168 , V_51 , F_107 , NULL , NULL ) ;
F_121 ( V_168 , V_52 , F_107 , F_118 ,
NULL ) ;
return 0 ;
}
