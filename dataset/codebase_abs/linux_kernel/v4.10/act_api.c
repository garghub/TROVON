static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_8 * V_9 , struct V_3 * V_4 )
{
F_6 ( & V_9 -> V_10 ) ;
F_7 ( & V_4 -> V_11 ) ;
F_8 ( & V_9 -> V_10 ) ;
F_9 ( & V_4 -> V_12 ) ;
F_10 ( & V_4 -> V_5 , F_1 ) ;
}
int F_11 ( struct V_3 * V_4 , bool V_13 , bool V_14 )
{
int V_15 = 0 ;
if ( V_4 ) {
if ( V_13 )
V_4 -> V_16 -- ;
else if ( V_14 && V_4 -> V_16 > 0 )
return - V_17 ;
V_4 -> V_18 -- ;
if ( V_4 -> V_16 <= 0 && V_4 -> V_18 <= 0 ) {
if ( V_4 -> V_19 -> V_20 )
V_4 -> V_19 -> V_20 ( V_4 , V_13 ) ;
F_5 ( V_4 -> V_9 , V_4 ) ;
V_15 = V_21 ;
}
}
return V_15 ;
}
static int F_12 ( struct V_8 * V_9 , struct V_22 * V_23 ,
struct V_24 * V_25 )
{
int V_26 = 0 , V_27 = - 1 , V_28 = 0 , V_29 = 0 , V_30 = 0 ;
struct V_31 * V_32 ;
F_6 ( & V_9 -> V_10 ) ;
V_29 = V_25 -> args [ 0 ] ;
for ( V_28 = 0 ; V_28 < ( V_9 -> V_33 + 1 ) ; V_28 ++ ) {
struct V_34 * V_2 ;
struct V_3 * V_4 ;
V_2 = & V_9 -> V_35 [ F_13 ( V_28 , V_9 -> V_33 ) ] ;
F_14 (p, head, tcfa_head) {
V_27 ++ ;
if ( V_27 < V_29 )
continue;
V_32 = F_15 ( V_23 , V_30 ) ;
if ( V_32 == NULL )
goto V_36;
V_26 = F_16 ( V_23 , V_4 , 0 , 0 ) ;
if ( V_26 < 0 ) {
V_27 -- ;
F_17 ( V_23 , V_32 ) ;
goto V_37;
}
F_18 ( V_23 , V_32 ) ;
V_30 ++ ;
if ( V_30 >= V_38 )
goto V_37;
}
}
V_37:
F_8 ( & V_9 -> V_10 ) ;
if ( V_30 )
V_25 -> args [ 0 ] += V_30 ;
return V_30 ;
V_36:
F_19 ( V_23 , V_32 ) ;
goto V_37;
}
static int F_20 ( struct V_8 * V_9 , struct V_22 * V_23 ,
const struct V_39 * V_19 )
{
struct V_31 * V_32 ;
int V_28 = 0 , V_30 = 0 ;
int V_15 = - V_40 ;
V_32 = F_15 ( V_23 , 0 ) ;
if ( V_32 == NULL )
goto V_36;
if ( F_21 ( V_23 , V_41 , V_19 -> V_42 ) )
goto V_36;
for ( V_28 = 0 ; V_28 < ( V_9 -> V_33 + 1 ) ; V_28 ++ ) {
struct V_34 * V_2 ;
struct V_43 * V_44 ;
struct V_3 * V_4 ;
V_2 = & V_9 -> V_35 [ F_13 ( V_28 , V_9 -> V_33 ) ] ;
F_22 (p, n, head, tcfa_head) {
V_15 = F_11 ( V_4 , false , true ) ;
if ( V_15 == V_21 ) {
F_23 ( V_4 -> V_19 -> V_45 ) ;
V_30 ++ ;
} else if ( V_15 < 0 )
goto V_36;
}
}
if ( F_24 ( V_23 , V_46 , V_30 ) )
goto V_36;
F_18 ( V_23 , V_32 ) ;
return V_30 ;
V_36:
F_19 ( V_23 , V_32 ) ;
return V_15 ;
}
int F_25 ( struct V_47 * V_48 , struct V_22 * V_23 ,
struct V_24 * V_25 , int type ,
const struct V_39 * V_19 )
{
struct V_8 * V_9 = V_48 -> V_9 ;
if ( type == V_49 ) {
return F_20 ( V_9 , V_23 , V_19 ) ;
} else if ( type == V_50 ) {
return F_12 ( V_9 , V_23 , V_25 ) ;
} else {
F_26 ( 1 , L_1 , type ) ;
return - V_40 ;
}
}
static struct V_3 * F_27 ( T_1 V_27 , struct V_8 * V_9 )
{
struct V_3 * V_4 = NULL ;
struct V_34 * V_2 ;
F_6 ( & V_9 -> V_10 ) ;
V_2 = & V_9 -> V_35 [ F_13 ( V_27 , V_9 -> V_33 ) ] ;
F_14 (p, head, tcfa_head)
if ( V_4 -> V_51 == V_27 )
break;
F_8 ( & V_9 -> V_10 ) ;
return V_4 ;
}
T_1 F_28 ( struct V_47 * V_48 )
{
struct V_8 * V_9 = V_48 -> V_9 ;
T_1 V_52 = V_9 -> V_27 ;
do {
if ( ++ V_52 == 0 )
V_52 = 1 ;
} while ( F_27 ( V_52 , V_9 ) );
V_9 -> V_27 = V_52 ;
return V_52 ;
}
int F_29 ( struct V_47 * V_48 , struct V_3 * * V_53 , T_1 V_27 )
{
struct V_8 * V_9 = V_48 -> V_9 ;
struct V_3 * V_4 = F_27 ( V_27 , V_9 ) ;
if ( V_4 ) {
* V_53 = V_4 ;
return 1 ;
}
return 0 ;
}
bool F_30 ( struct V_47 * V_48 , T_1 V_27 , struct V_3 * * V_53 ,
int V_13 )
{
struct V_8 * V_9 = V_48 -> V_9 ;
struct V_3 * V_4 = NULL ;
if ( V_27 && ( V_4 = F_27 ( V_27 , V_9 ) ) != NULL ) {
if ( V_13 )
V_4 -> V_16 ++ ;
V_4 -> V_18 ++ ;
* V_53 = V_4 ;
return true ;
}
return false ;
}
void F_31 ( struct V_3 * V_53 , struct V_31 * V_54 )
{
if ( V_54 )
F_9 ( & V_53 -> V_12 ) ;
F_10 ( & V_53 -> V_5 , F_1 ) ;
}
int F_32 ( struct V_47 * V_48 , T_1 V_27 , struct V_31 * V_54 ,
struct V_3 * * V_53 , const struct V_39 * V_19 ,
int V_13 , bool V_55 )
{
struct V_3 * V_4 = F_33 ( V_19 -> V_56 , V_57 ) ;
struct V_8 * V_9 = V_48 -> V_9 ;
int V_26 = - V_58 ;
if ( F_34 ( ! V_4 ) )
return - V_58 ;
V_4 -> V_18 = 1 ;
if ( V_13 )
V_4 -> V_16 = 1 ;
if ( V_55 ) {
V_4 -> V_6 = F_35 ( struct V_59 ) ;
if ( ! V_4 -> V_6 ) {
V_60:
F_4 ( V_4 ) ;
return V_26 ;
}
V_4 -> V_7 = F_36 ( struct V_61 ) ;
if ( ! V_4 -> V_7 ) {
V_62:
F_3 ( V_4 -> V_6 ) ;
goto V_60;
}
}
F_37 ( & V_4 -> V_63 ) ;
F_38 ( & V_4 -> V_11 ) ;
V_4 -> V_51 = V_27 ? V_27 : F_28 ( V_48 ) ;
V_4 -> V_64 . V_65 = V_66 ;
V_4 -> V_64 . V_67 = V_66 ;
V_4 -> V_64 . V_68 = 0 ;
if ( V_54 ) {
V_26 = F_39 ( & V_4 -> V_69 , V_4 -> V_6 ,
& V_4 -> V_12 ,
& V_4 -> V_63 , NULL , V_54 ) ;
if ( V_26 ) {
F_3 ( V_4 -> V_7 ) ;
goto V_62;
}
}
V_4 -> V_9 = V_9 ;
V_4 -> V_19 = V_19 ;
F_40 ( & V_4 -> V_70 ) ;
* V_53 = V_4 ;
return 0 ;
}
void F_41 ( struct V_47 * V_48 , struct V_3 * V_53 )
{
struct V_8 * V_9 = V_48 -> V_9 ;
unsigned int V_71 = F_13 ( V_53 -> V_51 , V_9 -> V_33 ) ;
F_6 ( & V_9 -> V_10 ) ;
F_42 ( & V_53 -> V_11 , & V_9 -> V_35 [ V_71 ] ) ;
F_8 ( & V_9 -> V_10 ) ;
}
void F_43 ( const struct V_39 * V_19 ,
struct V_8 * V_9 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_9 -> V_33 + 1 ; V_28 ++ ) {
struct V_3 * V_4 ;
struct V_43 * V_44 ;
F_22 (p, n, &hinfo->htab[i], tcfa_head) {
int V_15 ;
V_15 = F_11 ( V_4 , false , true ) ;
if ( V_15 == V_21 )
F_23 ( V_19 -> V_45 ) ;
else if ( V_15 < 0 )
return;
}
}
F_4 ( V_9 -> V_35 ) ;
}
int F_44 ( struct V_39 * V_72 ,
struct V_73 * V_19 )
{
struct V_39 * V_53 ;
int V_15 ;
if ( ! V_72 -> V_72 || ! V_72 -> V_74 || ! V_72 -> V_75 || ! V_72 -> V_76 || ! V_72 -> V_77 )
return - V_40 ;
V_15 = F_45 ( V_19 ) ;
if ( V_15 )
return V_15 ;
F_46 ( & V_78 ) ;
F_47 (a, &act_base, head) {
if ( V_72 -> type == V_53 -> type || ( strcmp ( V_72 -> V_42 , V_53 -> V_42 ) == 0 ) ) {
F_48 ( & V_78 ) ;
F_49 ( V_19 ) ;
return - V_79 ;
}
}
F_50 ( & V_72 -> V_2 , & V_80 ) ;
F_48 ( & V_78 ) ;
return 0 ;
}
int F_51 ( struct V_39 * V_72 ,
struct V_73 * V_19 )
{
struct V_39 * V_53 ;
int V_26 = - V_81 ;
F_46 ( & V_78 ) ;
F_47 (a, &act_base, head) {
if ( V_53 == V_72 ) {
F_52 ( & V_72 -> V_2 ) ;
V_26 = 0 ;
break;
}
}
F_48 ( & V_78 ) ;
if ( ! V_26 )
F_49 ( V_19 ) ;
return V_26 ;
}
static struct V_39 * F_53 ( char * V_42 )
{
struct V_39 * V_53 , * V_82 = NULL ;
if ( V_42 ) {
F_54 ( & V_78 ) ;
F_47 (a, &act_base, head) {
if ( strcmp ( V_42 , V_53 -> V_42 ) == 0 ) {
if ( F_55 ( V_53 -> V_45 ) )
V_82 = V_53 ;
break;
}
}
F_56 ( & V_78 ) ;
}
return V_82 ;
}
static struct V_39 * F_57 ( struct V_31 * V_42 )
{
struct V_39 * V_53 , * V_82 = NULL ;
if ( V_42 ) {
F_54 ( & V_78 ) ;
F_47 (a, &act_base, head) {
if ( F_58 ( V_42 , V_53 -> V_42 ) == 0 ) {
if ( F_55 ( V_53 -> V_45 ) )
V_82 = V_53 ;
break;
}
}
F_56 ( & V_78 ) ;
}
return V_82 ;
}
int F_59 ( struct V_22 * V_23 , struct V_3 * * V_83 ,
int V_84 , struct V_85 * V_82 )
{
int V_15 = - 1 , V_28 ;
if ( V_23 -> V_86 & V_87 ) {
V_23 -> V_86 = F_60 ( V_23 -> V_86 ) ;
V_15 = V_88 ;
goto V_89;
}
for ( V_28 = 0 ; V_28 < V_84 ; V_28 ++ ) {
const struct V_3 * V_53 = V_83 [ V_28 ] ;
V_90:
V_15 = V_53 -> V_19 -> V_72 ( V_23 , V_53 , V_82 ) ;
if ( V_15 == V_91 )
goto V_90;
if ( V_15 != V_92 )
goto V_89;
}
V_89:
return V_15 ;
}
int F_61 ( struct V_93 * V_83 , int V_13 )
{
struct V_3 * V_53 , * V_94 ;
int V_15 = 0 ;
F_62 (a, tmp, actions, list) {
V_15 = F_11 ( V_53 , V_13 , true ) ;
if ( V_15 == V_21 )
F_23 ( V_53 -> V_19 -> V_45 ) ;
else if ( V_15 < 0 )
return V_15 ;
}
return V_15 ;
}
int
F_63 ( struct V_22 * V_23 , struct V_3 * V_53 , int V_13 , int V_95 )
{
return V_53 -> V_19 -> V_74 ( V_23 , V_53 , V_13 , V_95 ) ;
}
int
F_16 ( struct V_22 * V_23 , struct V_3 * V_53 , int V_13 , int V_95 )
{
int V_26 = - V_40 ;
unsigned char * V_96 = F_64 ( V_23 ) ;
struct V_31 * V_32 ;
if ( F_21 ( V_23 , V_41 , V_53 -> V_19 -> V_42 ) )
goto V_36;
if ( F_65 ( V_23 , V_53 , 0 ) )
goto V_36;
V_32 = F_15 ( V_23 , V_97 ) ;
if ( V_32 == NULL )
goto V_36;
V_26 = F_63 ( V_23 , V_53 , V_13 , V_95 ) ;
if ( V_26 > 0 ) {
F_18 ( V_23 , V_32 ) ;
return V_26 ;
}
V_36:
F_17 ( V_23 , V_96 ) ;
return - 1 ;
}
int F_66 ( struct V_22 * V_23 , struct V_93 * V_83 ,
int V_13 , int V_95 )
{
struct V_3 * V_53 ;
int V_26 = - V_40 ;
struct V_31 * V_32 ;
F_47 (a, actions, list) {
V_32 = F_15 ( V_23 , V_53 -> V_98 ) ;
if ( V_32 == NULL )
goto V_36;
V_26 = F_16 ( V_23 , V_53 , V_13 , V_95 ) ;
if ( V_26 < 0 )
goto V_99;
F_18 ( V_23 , V_32 ) ;
}
return 0 ;
V_36:
V_26 = - V_40 ;
V_99:
F_19 ( V_23 , V_32 ) ;
return V_26 ;
}
struct V_3 * F_67 ( struct V_100 * V_100 , struct V_31 * V_101 ,
struct V_31 * V_54 , char * V_102 , int V_103 ,
int V_13 )
{
struct V_3 * V_53 ;
struct V_39 * V_104 ;
char V_105 [ V_106 ] ;
struct V_31 * V_107 [ V_108 + 1 ] ;
struct V_31 * V_42 ;
int V_26 ;
if ( V_102 == NULL ) {
V_26 = F_68 ( V_107 , V_108 , V_101 , NULL ) ;
if ( V_26 < 0 )
goto V_109;
V_26 = - V_40 ;
V_42 = V_107 [ V_110 ] ;
if ( V_42 == NULL )
goto V_109;
if ( F_69 ( V_105 , V_42 , V_106 ) >= V_106 )
goto V_109;
} else {
V_26 = - V_40 ;
if ( F_70 ( V_105 , V_102 , V_106 ) >= V_106 )
goto V_109;
}
V_104 = F_53 ( V_105 ) ;
if ( V_104 == NULL ) {
#ifdef F_71
F_72 () ;
F_73 ( L_2 , V_105 ) ;
F_74 () ;
V_104 = F_53 ( V_105 ) ;
if ( V_104 != NULL ) {
V_26 = - V_111 ;
goto V_112;
}
#endif
V_26 = - V_81 ;
goto V_109;
}
if ( V_102 == NULL )
V_26 = V_104 -> V_75 ( V_100 , V_107 [ V_113 ] , V_54 , & V_53 , V_103 , V_13 ) ;
else
V_26 = V_104 -> V_75 ( V_100 , V_101 , V_54 , & V_53 , V_103 , V_13 ) ;
if ( V_26 < 0 )
goto V_112;
if ( V_26 != V_114 )
F_23 ( V_104 -> V_45 ) ;
return V_53 ;
V_112:
F_23 ( V_104 -> V_45 ) ;
V_109:
return F_75 ( V_26 ) ;
}
static void F_76 ( struct V_93 * V_83 , int V_103 )
{
struct V_3 * V_53 ;
if ( ! V_103 )
return;
F_47 (a, actions, list)
V_53 -> V_18 -- ;
}
int F_77 ( struct V_100 * V_100 , struct V_31 * V_101 , struct V_31 * V_54 ,
char * V_102 , int V_103 , int V_13 , struct V_93 * V_83 )
{
struct V_31 * V_107 [ V_38 + 1 ] ;
struct V_3 * V_72 ;
int V_26 ;
int V_28 ;
V_26 = F_68 ( V_107 , V_38 , V_101 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_28 = 1 ; V_28 <= V_38 && V_107 [ V_28 ] ; V_28 ++ ) {
V_72 = F_67 ( V_100 , V_107 [ V_28 ] , V_54 , V_102 , V_103 , V_13 ) ;
if ( F_78 ( V_72 ) ) {
V_26 = F_79 ( V_72 ) ;
goto V_26;
}
V_72 -> V_98 = V_28 ;
if ( V_103 )
V_72 -> V_18 ++ ;
F_50 ( & V_72 -> V_70 , V_83 ) ;
}
F_76 ( V_83 , V_103 ) ;
return 0 ;
V_26:
F_61 ( V_83 , V_13 ) ;
return V_26 ;
}
int F_65 ( struct V_22 * V_23 , struct V_3 * V_4 ,
int V_115 )
{
int V_26 = 0 ;
struct V_116 V_117 ;
if ( V_4 == NULL )
goto V_99;
if ( V_115 ) {
if ( V_4 -> type == V_118 )
V_26 = F_80 ( V_23 , 0 ,
V_119 ,
V_120 ,
& V_4 -> V_63 , & V_117 ,
V_121 ) ;
else
return 0 ;
} else
V_26 = F_81 ( V_23 , V_122 ,
& V_4 -> V_63 , & V_117 , V_123 ) ;
if ( V_26 < 0 )
goto V_99;
if ( F_82 ( NULL , & V_117 , V_4 -> V_6 , & V_4 -> V_69 ) < 0 ||
F_83 ( & V_117 , & V_4 -> V_12 ) < 0 ||
F_84 ( & V_117 , V_4 -> V_7 ,
& V_4 -> V_124 ,
V_4 -> V_124 . V_125 ) < 0 )
goto V_99;
if ( F_85 ( & V_117 ) < 0 )
goto V_99;
return 0 ;
V_99:
return - 1 ;
}
static int F_86 ( struct V_22 * V_23 , struct V_93 * V_83 ,
T_1 V_126 , T_1 V_127 , T_2 V_128 , int V_129 , int V_13 ,
int V_95 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
unsigned char * V_96 = F_64 ( V_23 ) ;
struct V_31 * V_32 ;
V_133 = F_87 ( V_23 , V_126 , V_127 , V_129 , sizeof( * V_131 ) , V_128 ) ;
if ( ! V_133 )
goto V_134;
V_131 = F_88 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_32 = F_15 ( V_23 , V_139 ) ;
if ( V_32 == NULL )
goto V_134;
if ( F_66 ( V_23 , V_83 , V_13 , V_95 ) < 0 )
goto V_134;
F_18 ( V_23 , V_32 ) ;
V_133 -> V_140 = F_64 ( V_23 ) - V_96 ;
return V_23 -> V_141 ;
V_134:
F_17 ( V_23 , V_96 ) ;
return - 1 ;
}
static int
F_89 ( struct V_100 * V_100 , T_1 V_126 , struct V_132 * V_44 ,
struct V_93 * V_83 , int V_129 )
{
struct V_22 * V_23 ;
V_23 = F_90 ( V_142 , V_57 ) ;
if ( ! V_23 )
return - V_143 ;
if ( F_86 ( V_23 , V_83 , V_126 , V_44 -> V_144 , 0 , V_129 ,
0 , 0 ) <= 0 ) {
F_91 ( V_23 ) ;
return - V_40 ;
}
return F_92 ( V_23 , V_100 , V_126 ) ;
}
static struct V_3 * F_93 ( struct V_100 * V_100 , struct V_31 * V_101 ,
struct V_132 * V_44 , T_1 V_126 )
{
struct V_31 * V_107 [ V_108 + 1 ] ;
const struct V_39 * V_19 ;
struct V_3 * V_53 ;
int V_27 ;
int V_26 ;
V_26 = F_68 ( V_107 , V_108 , V_101 , NULL ) ;
if ( V_26 < 0 )
goto V_109;
V_26 = - V_40 ;
if ( V_107 [ V_145 ] == NULL ||
F_94 ( V_107 [ V_145 ] ) < sizeof( V_27 ) )
goto V_109;
V_27 = F_95 ( V_107 [ V_145 ] ) ;
V_26 = - V_40 ;
V_19 = F_57 ( V_107 [ V_110 ] ) ;
if ( ! V_19 )
goto V_109;
V_26 = - V_81 ;
if ( V_19 -> V_77 ( V_100 , & V_53 , V_27 ) == 0 )
goto V_112;
F_23 ( V_19 -> V_45 ) ;
return V_53 ;
V_112:
F_23 ( V_19 -> V_45 ) ;
V_109:
return F_75 ( V_26 ) ;
}
static int F_96 ( struct V_100 * V_100 , struct V_31 * V_101 ,
struct V_132 * V_44 , T_1 V_126 )
{
struct V_22 * V_23 ;
unsigned char * V_96 ;
struct V_132 * V_133 ;
struct V_130 * V_131 ;
struct V_24 V_146 ;
struct V_31 * V_32 ;
struct V_31 * V_107 [ V_108 + 1 ] ;
const struct V_39 * V_19 ;
struct V_31 * V_42 ;
int V_26 = - V_58 ;
V_23 = F_90 ( V_142 , V_57 ) ;
if ( ! V_23 ) {
F_97 ( L_3 ) ;
return V_26 ;
}
V_96 = F_64 ( V_23 ) ;
V_26 = F_68 ( V_107 , V_108 , V_101 , NULL ) ;
if ( V_26 < 0 )
goto V_109;
V_26 = - V_40 ;
V_42 = V_107 [ V_110 ] ;
V_19 = F_57 ( V_42 ) ;
if ( ! V_19 )
goto V_109;
V_133 = F_87 ( V_23 , V_126 , V_44 -> V_144 , V_49 ,
sizeof( * V_131 ) , 0 ) ;
if ( ! V_133 )
goto V_147;
V_131 = F_88 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_32 = F_15 ( V_23 , V_139 ) ;
if ( V_32 == NULL )
goto V_147;
V_26 = V_19 -> V_76 ( V_100 , V_23 , & V_146 , V_49 , V_19 ) ;
if ( V_26 < 0 )
goto V_147;
if ( V_26 == 0 )
goto V_148;
F_18 ( V_23 , V_32 ) ;
V_133 -> V_140 = F_64 ( V_23 ) - V_96 ;
V_133 -> V_149 |= V_150 ;
F_23 ( V_19 -> V_45 ) ;
V_26 = F_98 ( V_23 , V_100 , V_126 , V_151 ,
V_44 -> V_149 & V_152 ) ;
if ( V_26 > 0 )
return 0 ;
return V_26 ;
V_147:
F_23 ( V_19 -> V_45 ) ;
V_109:
V_148:
F_91 ( V_23 ) ;
return V_26 ;
}
static int
F_99 ( struct V_100 * V_100 , struct V_132 * V_44 , struct V_93 * V_83 ,
T_1 V_126 )
{
int V_15 ;
struct V_22 * V_23 ;
V_23 = F_90 ( V_142 , V_57 ) ;
if ( ! V_23 )
return - V_143 ;
if ( F_86 ( V_23 , V_83 , V_126 , V_44 -> V_144 , 0 , V_49 ,
0 , 1 ) <= 0 ) {
F_91 ( V_23 ) ;
return - V_40 ;
}
V_15 = F_61 ( V_83 , 0 ) ;
if ( V_15 < 0 ) {
F_91 ( V_23 ) ;
return V_15 ;
}
V_15 = F_98 ( V_23 , V_100 , V_126 , V_151 ,
V_44 -> V_149 & V_152 ) ;
if ( V_15 > 0 )
return 0 ;
return V_15 ;
}
static int
F_100 ( struct V_100 * V_100 , struct V_31 * V_101 , struct V_132 * V_44 ,
T_1 V_126 , int V_129 )
{
int V_28 , V_15 ;
struct V_31 * V_107 [ V_38 + 1 ] ;
struct V_3 * V_72 ;
F_101 ( V_83 ) ;
V_15 = F_68 ( V_107 , V_38 , V_101 , NULL ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_129 == V_49 && V_44 -> V_149 & V_150 ) {
if ( V_107 [ 1 ] != NULL )
return F_96 ( V_100 , V_107 [ 1 ] , V_44 , V_126 ) ;
else
return - V_40 ;
}
for ( V_28 = 1 ; V_28 <= V_38 && V_107 [ V_28 ] ; V_28 ++ ) {
V_72 = F_93 ( V_100 , V_107 [ V_28 ] , V_44 , V_126 ) ;
if ( F_78 ( V_72 ) ) {
V_15 = F_79 ( V_72 ) ;
goto V_26;
}
V_72 -> V_98 = V_28 ;
F_50 ( & V_72 -> V_70 , & V_83 ) ;
}
if ( V_129 == V_50 )
V_15 = F_89 ( V_100 , V_126 , V_44 , & V_83 , V_129 ) ;
else {
V_15 = F_99 ( V_100 , V_44 , & V_83 , V_126 ) ;
if ( V_15 )
goto V_26;
return V_15 ;
}
V_26:
if ( V_129 != V_50 )
F_61 ( & V_83 , 0 ) ;
return V_15 ;
}
static int
F_102 ( struct V_100 * V_100 , struct V_132 * V_44 , struct V_93 * V_83 ,
T_1 V_126 )
{
struct V_22 * V_23 ;
int V_26 = 0 ;
V_23 = F_90 ( V_142 , V_57 ) ;
if ( ! V_23 )
return - V_143 ;
if ( F_86 ( V_23 , V_83 , V_126 , V_44 -> V_144 , V_44 -> V_149 ,
V_153 , 0 , 0 ) <= 0 ) {
F_91 ( V_23 ) ;
return - V_40 ;
}
V_26 = F_98 ( V_23 , V_100 , V_126 , V_151 ,
V_44 -> V_149 & V_152 ) ;
if ( V_26 > 0 )
V_26 = 0 ;
return V_26 ;
}
static int F_103 ( struct V_100 * V_100 , struct V_31 * V_101 ,
struct V_132 * V_44 , T_1 V_126 , int V_103 )
{
int V_15 = 0 ;
F_101 ( V_83 ) ;
V_15 = F_77 ( V_100 , V_101 , NULL , NULL , V_103 , 0 , & V_83 ) ;
if ( V_15 )
return V_15 ;
return F_102 ( V_100 , V_44 , & V_83 , V_126 ) ;
}
static int F_104 ( struct V_22 * V_23 , struct V_132 * V_44 )
{
struct V_100 * V_100 = F_105 ( V_23 -> V_154 ) ;
struct V_31 * V_155 [ V_108 + 1 ] ;
T_1 V_126 = V_23 ? F_106 ( V_23 ) . V_126 : 0 ;
int V_15 = 0 , V_103 = 0 ;
if ( ( V_44 -> V_156 != V_50 ) &&
! F_107 ( V_23 , V_157 ) )
return - V_17 ;
V_15 = F_108 ( V_44 , sizeof( struct V_130 ) , V_155 , V_108 , NULL ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_155 [ V_139 ] == NULL ) {
F_109 ( L_4 ) ;
return - V_40 ;
}
switch ( V_44 -> V_156 ) {
case V_153 :
if ( V_44 -> V_149 & V_158 )
V_103 = 1 ;
V_159:
V_15 = F_103 ( V_100 , V_155 [ V_139 ] , V_44 , V_126 , V_103 ) ;
if ( V_15 == - V_111 )
goto V_159;
break;
case V_49 :
V_15 = F_100 ( V_100 , V_155 [ V_139 ] , V_44 ,
V_126 , V_49 ) ;
break;
case V_50 :
V_15 = F_100 ( V_100 , V_155 [ V_139 ] , V_44 ,
V_126 , V_50 ) ;
break;
default:
F_110 () ;
}
return V_15 ;
}
static struct V_31 * F_111 ( const struct V_132 * V_44 )
{
struct V_31 * V_160 , * V_161 [ V_108 + 1 ] ;
struct V_31 * V_107 [ V_38 + 1 ] ;
struct V_31 * V_101 [ V_162 + 1 ] ;
struct V_31 * V_42 ;
if ( F_108 ( V_44 , sizeof( struct V_130 ) , V_101 , V_162 , NULL ) < 0 )
return NULL ;
V_160 = V_101 [ V_139 ] ;
if ( V_160 == NULL )
return NULL ;
if ( F_112 ( V_107 , V_38 , F_113 ( V_160 ) ,
F_114 ( F_94 ( V_160 ) ) , NULL ) < 0 )
return NULL ;
if ( V_107 [ 1 ] == NULL )
return NULL ;
if ( F_68 ( V_161 , V_108 , V_107 [ 1 ] , NULL ) < 0 )
return NULL ;
V_42 = V_161 [ V_110 ] ;
return V_42 ;
}
static int F_115 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_100 * V_100 = F_105 ( V_23 -> V_154 ) ;
struct V_132 * V_133 ;
unsigned char * V_96 = F_64 ( V_23 ) ;
struct V_31 * V_32 ;
struct V_39 * V_104 ;
int V_15 = 0 ;
struct V_130 * V_131 = (struct V_130 * ) F_88 ( V_25 -> V_133 ) ;
struct V_31 * V_42 = F_111 ( V_25 -> V_133 ) ;
if ( V_42 == NULL ) {
F_116 ( L_5 ) ;
return 0 ;
}
V_104 = F_57 ( V_42 ) ;
if ( V_104 == NULL )
return 0 ;
V_133 = F_87 ( V_23 , F_106 ( V_25 -> V_23 ) . V_126 , V_25 -> V_133 -> V_144 ,
V_25 -> V_133 -> V_156 , sizeof( * V_131 ) , 0 ) ;
if ( ! V_133 )
goto V_147;
V_131 = F_88 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_32 = F_15 ( V_23 , V_139 ) ;
if ( V_32 == NULL )
goto V_147;
V_15 = V_104 -> V_76 ( V_100 , V_23 , V_25 , V_50 , V_104 ) ;
if ( V_15 < 0 )
goto V_147;
if ( V_15 > 0 ) {
F_18 ( V_23 , V_32 ) ;
V_15 = V_23 -> V_141 ;
} else
F_17 ( V_23 , V_96 ) ;
V_133 -> V_140 = F_64 ( V_23 ) - V_96 ;
if ( F_106 ( V_25 -> V_23 ) . V_126 && V_15 )
V_133 -> V_149 |= V_163 ;
F_23 ( V_104 -> V_45 ) ;
return V_23 -> V_141 ;
V_147:
F_23 ( V_104 -> V_45 ) ;
F_17 ( V_23 , V_96 ) ;
return V_23 -> V_141 ;
}
static int T_3 F_117 ( void )
{
F_118 ( V_164 , V_153 , F_104 , NULL , NULL ) ;
F_118 ( V_164 , V_49 , F_104 , NULL , NULL ) ;
F_118 ( V_164 , V_50 , F_104 , F_115 ,
NULL ) ;
return 0 ;
}
