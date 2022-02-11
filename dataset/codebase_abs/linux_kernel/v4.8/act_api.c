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
F_9 ( & V_4 -> V_12 ,
& V_4 -> V_13 ) ;
F_10 ( & V_4 -> V_5 , F_1 ) ;
}
int F_11 ( struct V_3 * V_4 , bool V_14 , bool V_15 )
{
int V_16 = 0 ;
if ( V_4 ) {
if ( V_14 )
V_4 -> V_17 -- ;
else if ( V_15 && V_4 -> V_17 > 0 )
return - V_18 ;
V_4 -> V_19 -- ;
if ( V_4 -> V_17 <= 0 && V_4 -> V_19 <= 0 ) {
if ( V_4 -> V_20 -> V_21 )
V_4 -> V_20 -> V_21 ( V_4 , V_14 ) ;
F_5 ( V_4 -> V_9 , V_4 ) ;
V_16 = V_22 ;
}
}
return V_16 ;
}
static int F_12 ( struct V_8 * V_9 , struct V_23 * V_24 ,
struct V_25 * V_26 )
{
int V_27 = 0 , V_28 = - 1 , V_29 = 0 , V_30 = 0 , V_31 = 0 ;
struct V_32 * V_33 ;
F_6 ( & V_9 -> V_10 ) ;
V_30 = V_26 -> args [ 0 ] ;
for ( V_29 = 0 ; V_29 < ( V_9 -> V_34 + 1 ) ; V_29 ++ ) {
struct V_35 * V_2 ;
struct V_3 * V_4 ;
V_2 = & V_9 -> V_36 [ F_13 ( V_29 , V_9 -> V_34 ) ] ;
F_14 (p, head, tcfa_head) {
V_28 ++ ;
if ( V_28 < V_30 )
continue;
V_33 = F_15 ( V_24 , V_31 ) ;
if ( V_33 == NULL )
goto V_37;
V_27 = F_16 ( V_24 , V_4 , 0 , 0 ) ;
if ( V_27 < 0 ) {
V_28 -- ;
F_17 ( V_24 , V_33 ) ;
goto V_38;
}
F_18 ( V_24 , V_33 ) ;
V_31 ++ ;
if ( V_31 >= V_39 )
goto V_38;
}
}
V_38:
F_8 ( & V_9 -> V_10 ) ;
if ( V_31 )
V_26 -> args [ 0 ] += V_31 ;
return V_31 ;
V_37:
F_19 ( V_24 , V_33 ) ;
goto V_38;
}
static int F_20 ( struct V_8 * V_9 , struct V_23 * V_24 ,
const struct V_40 * V_20 )
{
struct V_32 * V_33 ;
int V_29 = 0 , V_31 = 0 ;
int V_16 = - V_41 ;
V_33 = F_15 ( V_24 , 0 ) ;
if ( V_33 == NULL )
goto V_37;
if ( F_21 ( V_24 , V_42 , V_20 -> V_43 ) )
goto V_37;
for ( V_29 = 0 ; V_29 < ( V_9 -> V_34 + 1 ) ; V_29 ++ ) {
struct V_35 * V_2 ;
struct V_44 * V_45 ;
struct V_3 * V_4 ;
V_2 = & V_9 -> V_36 [ F_13 ( V_29 , V_9 -> V_34 ) ] ;
F_22 (p, n, head, tcfa_head) {
V_16 = F_11 ( V_4 , false , true ) ;
if ( V_16 == V_22 ) {
F_23 ( V_4 -> V_20 -> V_46 ) ;
V_31 ++ ;
} else if ( V_16 < 0 )
goto V_37;
}
}
if ( F_24 ( V_24 , V_47 , V_31 ) )
goto V_37;
F_18 ( V_24 , V_33 ) ;
return V_31 ;
V_37:
F_19 ( V_24 , V_33 ) ;
return V_16 ;
}
int F_25 ( struct V_48 * V_49 , struct V_23 * V_24 ,
struct V_25 * V_26 , int type ,
const struct V_40 * V_20 )
{
struct V_8 * V_9 = V_49 -> V_9 ;
if ( type == V_50 ) {
return F_20 ( V_9 , V_24 , V_20 ) ;
} else if ( type == V_51 ) {
return F_12 ( V_9 , V_24 , V_26 ) ;
} else {
F_26 ( 1 , L_1 , type ) ;
return - V_41 ;
}
}
static struct V_3 * F_27 ( T_1 V_28 , struct V_8 * V_9 )
{
struct V_3 * V_4 = NULL ;
struct V_35 * V_2 ;
F_6 ( & V_9 -> V_10 ) ;
V_2 = & V_9 -> V_36 [ F_13 ( V_28 , V_9 -> V_34 ) ] ;
F_14 (p, head, tcfa_head)
if ( V_4 -> V_52 == V_28 )
break;
F_8 ( & V_9 -> V_10 ) ;
return V_4 ;
}
T_1 F_28 ( struct V_48 * V_49 )
{
struct V_8 * V_9 = V_49 -> V_9 ;
T_1 V_53 = V_9 -> V_28 ;
do {
if ( ++ V_53 == 0 )
V_53 = 1 ;
} while ( F_27 ( V_53 , V_9 ) );
V_9 -> V_28 = V_53 ;
return V_53 ;
}
int F_29 ( struct V_48 * V_49 , struct V_3 * * V_54 , T_1 V_28 )
{
struct V_8 * V_9 = V_49 -> V_9 ;
struct V_3 * V_4 = F_27 ( V_28 , V_9 ) ;
if ( V_4 ) {
* V_54 = V_4 ;
return 1 ;
}
return 0 ;
}
bool F_30 ( struct V_48 * V_49 , T_1 V_28 , struct V_3 * * V_54 ,
int V_14 )
{
struct V_8 * V_9 = V_49 -> V_9 ;
struct V_3 * V_4 = NULL ;
if ( V_28 && ( V_4 = F_27 ( V_28 , V_9 ) ) != NULL ) {
if ( V_14 )
V_4 -> V_17 ++ ;
V_4 -> V_19 ++ ;
* V_54 = V_4 ;
return true ;
}
return false ;
}
void F_31 ( struct V_3 * V_54 , struct V_32 * V_55 )
{
if ( V_55 )
F_9 ( & V_54 -> V_12 ,
& V_54 -> V_13 ) ;
F_10 ( & V_54 -> V_5 , F_1 ) ;
}
int F_32 ( struct V_48 * V_49 , T_1 V_28 , struct V_32 * V_55 ,
struct V_3 * * V_54 , const struct V_40 * V_20 ,
int V_14 , bool V_56 )
{
struct V_3 * V_4 = F_33 ( V_20 -> V_57 , V_58 ) ;
struct V_8 * V_9 = V_49 -> V_9 ;
int V_27 = - V_59 ;
if ( F_34 ( ! V_4 ) )
return - V_59 ;
V_4 -> V_19 = 1 ;
if ( V_14 )
V_4 -> V_17 = 1 ;
if ( V_56 ) {
V_4 -> V_6 = F_35 ( struct V_60 ) ;
if ( ! V_4 -> V_6 ) {
V_61:
F_4 ( V_4 ) ;
return V_27 ;
}
V_4 -> V_7 = F_36 ( struct V_62 ) ;
if ( ! V_4 -> V_7 ) {
V_63:
F_3 ( V_4 -> V_6 ) ;
goto V_61;
}
}
F_37 ( & V_4 -> V_64 ) ;
F_38 ( & V_4 -> V_11 ) ;
V_4 -> V_52 = V_28 ? V_28 : F_28 ( V_49 ) ;
V_4 -> V_65 . V_66 = V_67 ;
V_4 -> V_65 . V_68 = V_67 ;
V_4 -> V_65 . V_69 = 0 ;
if ( V_55 ) {
V_27 = F_39 ( & V_4 -> V_12 , V_4 -> V_6 ,
& V_4 -> V_13 ,
& V_4 -> V_64 , NULL , V_55 ) ;
if ( V_27 ) {
F_3 ( V_4 -> V_7 ) ;
goto V_63;
}
}
V_4 -> V_9 = V_9 ;
V_4 -> V_20 = V_20 ;
F_40 ( & V_4 -> V_70 ) ;
* V_54 = V_4 ;
return 0 ;
}
void F_41 ( struct V_48 * V_49 , struct V_3 * V_54 )
{
struct V_8 * V_9 = V_49 -> V_9 ;
unsigned int V_71 = F_13 ( V_54 -> V_52 , V_9 -> V_34 ) ;
F_6 ( & V_9 -> V_10 ) ;
F_42 ( & V_54 -> V_11 , & V_9 -> V_36 [ V_71 ] ) ;
F_8 ( & V_9 -> V_10 ) ;
}
void F_43 ( const struct V_40 * V_20 ,
struct V_8 * V_9 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_9 -> V_34 + 1 ; V_29 ++ ) {
struct V_3 * V_4 ;
struct V_44 * V_45 ;
F_22 (p, n, &hinfo->htab[i], tcfa_head) {
int V_16 ;
V_16 = F_11 ( V_4 , false , true ) ;
if ( V_16 == V_22 )
F_23 ( V_20 -> V_46 ) ;
else if ( V_16 < 0 )
return;
}
}
F_4 ( V_9 -> V_36 ) ;
}
int F_44 ( struct V_40 * V_72 ,
struct V_73 * V_20 )
{
struct V_40 * V_54 ;
int V_16 ;
if ( ! V_72 -> V_72 || ! V_72 -> V_74 || ! V_72 -> V_75 || ! V_72 -> V_76 || ! V_72 -> V_77 )
return - V_41 ;
F_45 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( V_72 -> type == V_54 -> type || ( strcmp ( V_72 -> V_43 , V_54 -> V_43 ) == 0 ) ) {
F_47 ( & V_78 ) ;
return - V_79 ;
}
}
F_48 ( & V_72 -> V_2 , & V_80 ) ;
F_47 ( & V_78 ) ;
V_16 = F_49 ( V_20 ) ;
if ( V_16 ) {
F_50 ( V_72 , V_20 ) ;
return V_16 ;
}
return 0 ;
}
int F_50 ( struct V_40 * V_72 ,
struct V_73 * V_20 )
{
struct V_40 * V_54 ;
int V_27 = - V_81 ;
F_51 ( V_20 ) ;
F_45 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( V_54 == V_72 ) {
F_52 ( & V_72 -> V_2 ) ;
V_27 = 0 ;
break;
}
}
F_47 ( & V_78 ) ;
return V_27 ;
}
static struct V_40 * F_53 ( char * V_43 )
{
struct V_40 * V_54 , * V_82 = NULL ;
if ( V_43 ) {
F_54 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( strcmp ( V_43 , V_54 -> V_43 ) == 0 ) {
if ( F_55 ( V_54 -> V_46 ) )
V_82 = V_54 ;
break;
}
}
F_56 ( & V_78 ) ;
}
return V_82 ;
}
static struct V_40 * F_57 ( struct V_32 * V_43 )
{
struct V_40 * V_54 , * V_82 = NULL ;
if ( V_43 ) {
F_54 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( F_58 ( V_43 , V_54 -> V_43 ) == 0 ) {
if ( F_55 ( V_54 -> V_46 ) )
V_82 = V_54 ;
break;
}
}
F_56 ( & V_78 ) ;
}
return V_82 ;
}
int F_59 ( struct V_23 * V_24 , struct V_3 * * V_83 ,
int V_84 , struct V_85 * V_82 )
{
int V_16 = - 1 , V_29 ;
if ( V_24 -> V_86 & V_87 ) {
V_24 -> V_86 = F_60 ( V_24 -> V_86 ) ;
V_16 = V_88 ;
goto V_89;
}
for ( V_29 = 0 ; V_29 < V_84 ; V_29 ++ ) {
const struct V_3 * V_54 = V_83 [ V_29 ] ;
V_90:
V_16 = V_54 -> V_20 -> V_72 ( V_24 , V_54 , V_82 ) ;
if ( V_16 == V_91 )
goto V_90;
if ( V_16 != V_92 )
goto V_89;
}
V_89:
return V_16 ;
}
int F_61 ( struct V_93 * V_83 , int V_14 )
{
struct V_3 * V_54 , * V_94 ;
int V_16 = 0 ;
F_62 (a, tmp, actions, list) {
V_16 = F_11 ( V_54 , V_14 , true ) ;
if ( V_16 == V_22 )
F_23 ( V_54 -> V_20 -> V_46 ) ;
else if ( V_16 < 0 )
return V_16 ;
}
return V_16 ;
}
int
F_63 ( struct V_23 * V_24 , struct V_3 * V_54 , int V_14 , int V_95 )
{
return V_54 -> V_20 -> V_74 ( V_24 , V_54 , V_14 , V_95 ) ;
}
int
F_16 ( struct V_23 * V_24 , struct V_3 * V_54 , int V_14 , int V_95 )
{
int V_27 = - V_41 ;
unsigned char * V_96 = F_64 ( V_24 ) ;
struct V_32 * V_33 ;
if ( F_21 ( V_24 , V_42 , V_54 -> V_20 -> V_43 ) )
goto V_37;
if ( F_65 ( V_24 , V_54 , 0 ) )
goto V_37;
V_33 = F_15 ( V_24 , V_97 ) ;
if ( V_33 == NULL )
goto V_37;
V_27 = F_63 ( V_24 , V_54 , V_14 , V_95 ) ;
if ( V_27 > 0 ) {
F_18 ( V_24 , V_33 ) ;
return V_27 ;
}
V_37:
F_17 ( V_24 , V_96 ) ;
return - 1 ;
}
int F_66 ( struct V_23 * V_24 , struct V_93 * V_83 ,
int V_14 , int V_95 )
{
struct V_3 * V_54 ;
int V_27 = - V_41 ;
struct V_32 * V_33 ;
F_46 (a, actions, list) {
V_33 = F_15 ( V_24 , V_54 -> V_98 ) ;
if ( V_33 == NULL )
goto V_37;
V_27 = F_16 ( V_24 , V_54 , V_14 , V_95 ) ;
if ( V_27 < 0 )
goto V_99;
F_18 ( V_24 , V_33 ) ;
}
return 0 ;
V_37:
V_27 = - V_41 ;
V_99:
F_19 ( V_24 , V_33 ) ;
return V_27 ;
}
struct V_3 * F_67 ( struct V_100 * V_100 , struct V_32 * V_101 ,
struct V_32 * V_55 , char * V_102 , int V_103 ,
int V_14 )
{
struct V_3 * V_54 ;
struct V_40 * V_104 ;
char V_105 [ V_106 ] ;
struct V_32 * V_107 [ V_108 + 1 ] ;
struct V_32 * V_43 ;
int V_27 ;
if ( V_102 == NULL ) {
V_27 = F_68 ( V_107 , V_108 , V_101 , NULL ) ;
if ( V_27 < 0 )
goto V_109;
V_27 = - V_41 ;
V_43 = V_107 [ V_110 ] ;
if ( V_43 == NULL )
goto V_109;
if ( F_69 ( V_105 , V_43 , V_106 ) >= V_106 )
goto V_109;
} else {
V_27 = - V_41 ;
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
V_27 = - V_111 ;
goto V_112;
}
#endif
V_27 = - V_81 ;
goto V_109;
}
if ( V_102 == NULL )
V_27 = V_104 -> V_75 ( V_100 , V_107 [ V_113 ] , V_55 , & V_54 , V_103 , V_14 ) ;
else
V_27 = V_104 -> V_75 ( V_100 , V_101 , V_55 , & V_54 , V_103 , V_14 ) ;
if ( V_27 < 0 )
goto V_112;
if ( V_27 != V_114 )
F_23 ( V_104 -> V_46 ) ;
return V_54 ;
V_112:
F_23 ( V_104 -> V_46 ) ;
V_109:
return F_75 ( V_27 ) ;
}
int F_76 ( struct V_100 * V_100 , struct V_32 * V_101 ,
struct V_32 * V_55 , char * V_102 , int V_103 ,
int V_14 , struct V_93 * V_83 )
{
struct V_32 * V_107 [ V_39 + 1 ] ;
struct V_3 * V_72 ;
int V_27 ;
int V_29 ;
V_27 = F_68 ( V_107 , V_39 , V_101 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
for ( V_29 = 1 ; V_29 <= V_39 && V_107 [ V_29 ] ; V_29 ++ ) {
V_72 = F_67 ( V_100 , V_107 [ V_29 ] , V_55 , V_102 , V_103 , V_14 ) ;
if ( F_77 ( V_72 ) ) {
V_27 = F_78 ( V_72 ) ;
goto V_27;
}
V_72 -> V_98 = V_29 ;
F_48 ( & V_72 -> V_70 , V_83 ) ;
}
return 0 ;
V_27:
F_61 ( V_83 , V_14 ) ;
return V_27 ;
}
int F_65 ( struct V_23 * V_24 , struct V_3 * V_4 ,
int V_115 )
{
int V_27 = 0 ;
struct V_116 V_117 ;
if ( V_4 == NULL )
goto V_99;
if ( V_115 ) {
if ( V_4 -> type == V_118 )
V_27 = F_79 ( V_24 , 0 ,
V_119 ,
V_120 ,
& V_4 -> V_64 , & V_117 ,
V_121 ) ;
else
return 0 ;
} else
V_27 = F_80 ( V_24 , V_122 ,
& V_4 -> V_64 , & V_117 , V_123 ) ;
if ( V_27 < 0 )
goto V_99;
if ( F_81 ( NULL , & V_117 , V_4 -> V_6 , & V_4 -> V_12 ) < 0 ||
F_82 ( & V_117 , & V_4 -> V_12 ,
& V_4 -> V_13 ) < 0 ||
F_83 ( & V_117 , V_4 -> V_7 ,
& V_4 -> V_124 ,
V_4 -> V_124 . V_125 ) < 0 )
goto V_99;
if ( F_84 ( & V_117 ) < 0 )
goto V_99;
return 0 ;
V_99:
return - 1 ;
}
static int F_85 ( struct V_23 * V_24 , struct V_93 * V_83 ,
T_1 V_126 , T_1 V_127 , T_2 V_128 , int V_129 , int V_14 ,
int V_95 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
unsigned char * V_96 = F_64 ( V_24 ) ;
struct V_32 * V_33 ;
V_133 = F_86 ( V_24 , V_126 , V_127 , V_129 , sizeof( * V_131 ) , V_128 ) ;
if ( ! V_133 )
goto V_134;
V_131 = F_87 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_33 = F_15 ( V_24 , V_139 ) ;
if ( V_33 == NULL )
goto V_134;
if ( F_66 ( V_24 , V_83 , V_14 , V_95 ) < 0 )
goto V_134;
F_18 ( V_24 , V_33 ) ;
V_133 -> V_140 = F_64 ( V_24 ) - V_96 ;
return V_24 -> V_141 ;
V_134:
F_17 ( V_24 , V_96 ) ;
return - 1 ;
}
static int
F_88 ( struct V_100 * V_100 , T_1 V_126 , struct V_132 * V_45 ,
struct V_93 * V_83 , int V_129 )
{
struct V_23 * V_24 ;
V_24 = F_89 ( V_142 , V_58 ) ;
if ( ! V_24 )
return - V_143 ;
if ( F_85 ( V_24 , V_83 , V_126 , V_45 -> V_144 , 0 , V_129 ,
0 , 0 ) <= 0 ) {
F_90 ( V_24 ) ;
return - V_41 ;
}
return F_91 ( V_24 , V_100 , V_126 ) ;
}
static struct V_3 * F_92 ( struct V_100 * V_100 , struct V_32 * V_101 ,
struct V_132 * V_45 , T_1 V_126 )
{
struct V_32 * V_107 [ V_108 + 1 ] ;
const struct V_40 * V_20 ;
struct V_3 * V_54 ;
int V_28 ;
int V_27 ;
V_27 = F_68 ( V_107 , V_108 , V_101 , NULL ) ;
if ( V_27 < 0 )
goto V_109;
V_27 = - V_41 ;
if ( V_107 [ V_145 ] == NULL ||
F_93 ( V_107 [ V_145 ] ) < sizeof( V_28 ) )
goto V_109;
V_28 = F_94 ( V_107 [ V_145 ] ) ;
V_27 = - V_41 ;
V_20 = F_57 ( V_107 [ V_110 ] ) ;
if ( ! V_20 )
goto V_109;
V_27 = - V_81 ;
if ( V_20 -> V_77 ( V_100 , & V_54 , V_28 ) == 0 )
goto V_112;
F_23 ( V_20 -> V_46 ) ;
return V_54 ;
V_112:
F_23 ( V_20 -> V_46 ) ;
V_109:
return F_75 ( V_27 ) ;
}
static int F_95 ( struct V_100 * V_100 , struct V_32 * V_101 ,
struct V_132 * V_45 , T_1 V_126 )
{
struct V_23 * V_24 ;
unsigned char * V_96 ;
struct V_132 * V_133 ;
struct V_130 * V_131 ;
struct V_25 V_146 ;
struct V_32 * V_33 ;
struct V_32 * V_107 [ V_108 + 1 ] ;
const struct V_40 * V_20 ;
struct V_32 * V_43 ;
int V_27 = - V_59 ;
V_24 = F_89 ( V_142 , V_58 ) ;
if ( ! V_24 ) {
F_96 ( L_3 ) ;
return V_27 ;
}
V_96 = F_64 ( V_24 ) ;
V_27 = F_68 ( V_107 , V_108 , V_101 , NULL ) ;
if ( V_27 < 0 )
goto V_109;
V_27 = - V_41 ;
V_43 = V_107 [ V_110 ] ;
V_20 = F_57 ( V_43 ) ;
if ( ! V_20 )
goto V_109;
V_133 = F_86 ( V_24 , V_126 , V_45 -> V_144 , V_50 ,
sizeof( * V_131 ) , 0 ) ;
if ( ! V_133 )
goto V_147;
V_131 = F_87 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_33 = F_15 ( V_24 , V_139 ) ;
if ( V_33 == NULL )
goto V_147;
V_27 = V_20 -> V_76 ( V_100 , V_24 , & V_146 , V_50 , V_20 ) ;
if ( V_27 < 0 )
goto V_147;
if ( V_27 == 0 )
goto V_148;
F_18 ( V_24 , V_33 ) ;
V_133 -> V_140 = F_64 ( V_24 ) - V_96 ;
V_133 -> V_149 |= V_150 ;
F_23 ( V_20 -> V_46 ) ;
V_27 = F_97 ( V_24 , V_100 , V_126 , V_151 ,
V_45 -> V_149 & V_152 ) ;
if ( V_27 > 0 )
return 0 ;
return V_27 ;
V_147:
F_23 ( V_20 -> V_46 ) ;
V_109:
V_148:
F_90 ( V_24 ) ;
return V_27 ;
}
static int
F_98 ( struct V_100 * V_100 , struct V_132 * V_45 , struct V_93 * V_83 ,
T_1 V_126 )
{
int V_16 ;
struct V_23 * V_24 ;
V_24 = F_89 ( V_142 , V_58 ) ;
if ( ! V_24 )
return - V_143 ;
if ( F_85 ( V_24 , V_83 , V_126 , V_45 -> V_144 , 0 , V_50 ,
0 , 1 ) <= 0 ) {
F_90 ( V_24 ) ;
return - V_41 ;
}
V_16 = F_61 ( V_83 , 0 ) ;
if ( V_16 < 0 ) {
F_90 ( V_24 ) ;
return V_16 ;
}
V_16 = F_97 ( V_24 , V_100 , V_126 , V_151 ,
V_45 -> V_149 & V_152 ) ;
if ( V_16 > 0 )
return 0 ;
return V_16 ;
}
static int
F_99 ( struct V_100 * V_100 , struct V_32 * V_101 , struct V_132 * V_45 ,
T_1 V_126 , int V_129 )
{
int V_29 , V_16 ;
struct V_32 * V_107 [ V_39 + 1 ] ;
struct V_3 * V_72 ;
F_100 ( V_83 ) ;
V_16 = F_68 ( V_107 , V_39 , V_101 , NULL ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_129 == V_50 && V_45 -> V_149 & V_150 ) {
if ( V_107 [ 1 ] != NULL )
return F_95 ( V_100 , V_107 [ 1 ] , V_45 , V_126 ) ;
else
return - V_41 ;
}
for ( V_29 = 1 ; V_29 <= V_39 && V_107 [ V_29 ] ; V_29 ++ ) {
V_72 = F_92 ( V_100 , V_107 [ V_29 ] , V_45 , V_126 ) ;
if ( F_77 ( V_72 ) ) {
V_16 = F_78 ( V_72 ) ;
goto V_27;
}
V_72 -> V_98 = V_29 ;
F_48 ( & V_72 -> V_70 , & V_83 ) ;
}
if ( V_129 == V_51 )
V_16 = F_88 ( V_100 , V_126 , V_45 , & V_83 , V_129 ) ;
else {
V_16 = F_98 ( V_100 , V_45 , & V_83 , V_126 ) ;
if ( V_16 )
goto V_27;
return V_16 ;
}
V_27:
F_61 ( & V_83 , 0 ) ;
return V_16 ;
}
static int
F_101 ( struct V_100 * V_100 , struct V_132 * V_45 , struct V_93 * V_83 ,
T_1 V_126 )
{
struct V_23 * V_24 ;
int V_27 = 0 ;
V_24 = F_89 ( V_142 , V_58 ) ;
if ( ! V_24 )
return - V_143 ;
if ( F_85 ( V_24 , V_83 , V_126 , V_45 -> V_144 , V_45 -> V_149 ,
V_153 , 0 , 0 ) <= 0 ) {
F_90 ( V_24 ) ;
return - V_41 ;
}
V_27 = F_97 ( V_24 , V_100 , V_126 , V_151 ,
V_45 -> V_149 & V_152 ) ;
if ( V_27 > 0 )
V_27 = 0 ;
return V_27 ;
}
static int
F_102 ( struct V_100 * V_100 , struct V_32 * V_101 , struct V_132 * V_45 ,
T_1 V_126 , int V_103 )
{
int V_16 = 0 ;
F_100 ( V_83 ) ;
V_16 = F_76 ( V_100 , V_101 , NULL , NULL , V_103 , 0 , & V_83 ) ;
if ( V_16 )
return V_16 ;
return F_101 ( V_100 , V_45 , & V_83 , V_126 ) ;
}
static int F_103 ( struct V_23 * V_24 , struct V_132 * V_45 )
{
struct V_100 * V_100 = F_104 ( V_24 -> V_154 ) ;
struct V_32 * V_155 [ V_108 + 1 ] ;
T_1 V_126 = V_24 ? F_105 ( V_24 ) . V_126 : 0 ;
int V_16 = 0 , V_103 = 0 ;
if ( ( V_45 -> V_156 != V_51 ) &&
! F_106 ( V_24 , V_157 ) )
return - V_18 ;
V_16 = F_107 ( V_45 , sizeof( struct V_130 ) , V_155 , V_108 , NULL ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_155 [ V_139 ] == NULL ) {
F_108 ( L_4 ) ;
return - V_41 ;
}
switch ( V_45 -> V_156 ) {
case V_153 :
if ( V_45 -> V_149 & V_158 )
V_103 = 1 ;
V_159:
V_16 = F_102 ( V_100 , V_155 [ V_139 ] , V_45 , V_126 , V_103 ) ;
if ( V_16 == - V_111 )
goto V_159;
break;
case V_50 :
V_16 = F_99 ( V_100 , V_155 [ V_139 ] , V_45 ,
V_126 , V_50 ) ;
break;
case V_51 :
V_16 = F_99 ( V_100 , V_155 [ V_139 ] , V_45 ,
V_126 , V_51 ) ;
break;
default:
F_109 () ;
}
return V_16 ;
}
static struct V_32 *
F_110 ( const struct V_132 * V_45 )
{
struct V_32 * V_160 , * V_161 [ V_108 + 1 ] ;
struct V_32 * V_107 [ V_39 + 1 ] ;
struct V_32 * V_101 [ V_162 + 1 ] ;
struct V_32 * V_43 ;
if ( F_107 ( V_45 , sizeof( struct V_130 ) , V_101 , V_162 , NULL ) < 0 )
return NULL ;
V_160 = V_101 [ V_139 ] ;
if ( V_160 == NULL )
return NULL ;
if ( F_111 ( V_107 , V_39 , F_112 ( V_160 ) ,
F_113 ( F_93 ( V_160 ) ) , NULL ) < 0 )
return NULL ;
if ( V_107 [ 1 ] == NULL )
return NULL ;
if ( F_111 ( V_161 , V_108 , F_112 ( V_107 [ 1 ] ) ,
F_93 ( V_107 [ 1 ] ) , NULL ) < 0 )
return NULL ;
V_43 = V_161 [ V_110 ] ;
return V_43 ;
}
static int
F_114 ( struct V_23 * V_24 , struct V_25 * V_26 )
{
struct V_100 * V_100 = F_104 ( V_24 -> V_154 ) ;
struct V_132 * V_133 ;
unsigned char * V_96 = F_64 ( V_24 ) ;
struct V_32 * V_33 ;
struct V_40 * V_104 ;
int V_16 = 0 ;
struct V_130 * V_131 = (struct V_130 * ) F_87 ( V_26 -> V_133 ) ;
struct V_32 * V_43 = F_110 ( V_26 -> V_133 ) ;
if ( V_43 == NULL ) {
F_115 ( L_5 ) ;
return 0 ;
}
V_104 = F_57 ( V_43 ) ;
if ( V_104 == NULL )
return 0 ;
V_133 = F_86 ( V_24 , F_105 ( V_26 -> V_24 ) . V_126 , V_26 -> V_133 -> V_144 ,
V_26 -> V_133 -> V_156 , sizeof( * V_131 ) , 0 ) ;
if ( ! V_133 )
goto V_147;
V_131 = F_87 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_33 = F_15 ( V_24 , V_139 ) ;
if ( V_33 == NULL )
goto V_147;
V_16 = V_104 -> V_76 ( V_100 , V_24 , V_26 , V_51 , V_104 ) ;
if ( V_16 < 0 )
goto V_147;
if ( V_16 > 0 ) {
F_18 ( V_24 , V_33 ) ;
V_16 = V_24 -> V_141 ;
} else
F_17 ( V_24 , V_96 ) ;
V_133 -> V_140 = F_64 ( V_24 ) - V_96 ;
if ( F_105 ( V_26 -> V_24 ) . V_126 && V_16 )
V_133 -> V_149 |= V_163 ;
F_23 ( V_104 -> V_46 ) ;
return V_24 -> V_141 ;
V_147:
F_23 ( V_104 -> V_46 ) ;
F_17 ( V_24 , V_96 ) ;
return V_24 -> V_141 ;
}
static int T_3 F_116 ( void )
{
F_117 ( V_164 , V_153 , F_103 , NULL , NULL ) ;
F_117 ( V_164 , V_50 , F_103 , NULL , NULL ) ;
F_117 ( V_164 , V_51 , F_103 , F_114 ,
NULL ) ;
return 0 ;
}
