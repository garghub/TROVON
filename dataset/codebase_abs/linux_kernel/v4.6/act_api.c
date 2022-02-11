static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_12 ;
F_6 ( & V_9 -> V_13 ) ;
F_7 ( & V_4 -> V_14 ) ;
F_8 ( & V_9 -> V_13 ) ;
F_9 ( & V_4 -> V_15 ,
& V_4 -> V_16 ) ;
F_10 ( & V_4 -> V_5 , F_1 ) ;
}
int F_11 ( struct V_10 * V_11 , bool V_17 , bool V_18 )
{
struct V_3 * V_4 = V_11 -> V_12 ;
int V_19 = 0 ;
if ( V_4 ) {
if ( V_17 )
V_4 -> V_20 -- ;
else if ( V_18 && V_4 -> V_20 > 0 )
return - V_21 ;
V_4 -> V_22 -- ;
if ( V_4 -> V_20 <= 0 && V_4 -> V_22 <= 0 ) {
if ( V_11 -> V_23 -> V_24 )
V_11 -> V_23 -> V_24 ( V_11 , V_17 ) ;
F_5 ( V_11 -> V_9 , V_11 ) ;
V_19 = V_25 ;
}
}
return V_19 ;
}
static int F_12 ( struct V_8 * V_9 , struct V_26 * V_27 ,
struct V_28 * V_29 , struct V_10 * V_11 )
{
struct V_30 * V_2 ;
struct V_3 * V_4 ;
int V_31 = 0 , V_32 = - 1 , V_33 = 0 , V_34 = 0 , V_35 = 0 ;
struct V_36 * V_37 ;
F_6 ( & V_9 -> V_13 ) ;
V_34 = V_29 -> args [ 0 ] ;
for ( V_33 = 0 ; V_33 < ( V_9 -> V_38 + 1 ) ; V_33 ++ ) {
V_2 = & V_9 -> V_39 [ F_13 ( V_33 , V_9 -> V_38 ) ] ;
F_14 (p, head, tcfc_head) {
V_32 ++ ;
if ( V_32 < V_34 )
continue;
V_11 -> V_12 = V_4 ;
V_11 -> V_40 = V_35 ;
V_37 = F_15 ( V_27 , V_11 -> V_40 ) ;
if ( V_37 == NULL )
goto V_41;
V_31 = F_16 ( V_27 , V_11 , 0 , 0 ) ;
if ( V_31 < 0 ) {
V_32 -- ;
F_17 ( V_27 , V_37 ) ;
goto V_42;
}
F_18 ( V_27 , V_37 ) ;
V_35 ++ ;
if ( V_35 >= V_43 )
goto V_42;
}
}
V_42:
F_8 ( & V_9 -> V_13 ) ;
if ( V_35 )
V_29 -> args [ 0 ] += V_35 ;
return V_35 ;
V_41:
F_19 ( V_27 , V_37 ) ;
goto V_42;
}
static int F_20 ( struct V_8 * V_9 , struct V_26 * V_27 ,
struct V_10 * V_11 )
{
struct V_30 * V_2 ;
struct V_44 * V_45 ;
struct V_3 * V_4 ;
struct V_36 * V_37 ;
int V_33 = 0 , V_35 = 0 ;
int V_19 = - V_46 ;
V_37 = F_15 ( V_27 , V_11 -> V_40 ) ;
if ( V_37 == NULL )
goto V_41;
if ( F_21 ( V_27 , V_47 , V_11 -> V_23 -> V_48 ) )
goto V_41;
for ( V_33 = 0 ; V_33 < ( V_9 -> V_38 + 1 ) ; V_33 ++ ) {
V_2 = & V_9 -> V_39 [ F_13 ( V_33 , V_9 -> V_38 ) ] ;
F_22 (p, n, head, tcfc_head) {
V_11 -> V_12 = V_4 ;
V_19 = F_11 ( V_11 , false , true ) ;
if ( V_19 == V_25 ) {
F_23 ( V_11 -> V_23 -> V_49 ) ;
V_35 ++ ;
} else if ( V_19 < 0 )
goto V_41;
}
}
if ( F_24 ( V_27 , V_50 , V_35 ) )
goto V_41;
F_18 ( V_27 , V_37 ) ;
return V_35 ;
V_41:
F_19 ( V_27 , V_37 ) ;
return V_19 ;
}
int F_25 ( struct V_51 * V_52 , struct V_26 * V_27 ,
struct V_28 * V_29 , int type ,
struct V_10 * V_11 )
{
struct V_8 * V_9 = V_52 -> V_9 ;
V_11 -> V_9 = V_9 ;
if ( type == V_53 ) {
return F_20 ( V_9 , V_27 , V_11 ) ;
} else if ( type == V_54 ) {
return F_12 ( V_9 , V_27 , V_29 , V_11 ) ;
} else {
F_26 ( 1 , L_1 , type ) ;
return - V_46 ;
}
}
static struct V_3 * F_27 ( T_1 V_32 , struct V_8 * V_9 )
{
struct V_3 * V_4 = NULL ;
struct V_30 * V_2 ;
F_6 ( & V_9 -> V_13 ) ;
V_2 = & V_9 -> V_39 [ F_13 ( V_32 , V_9 -> V_38 ) ] ;
F_14 (p, head, tcfc_head)
if ( V_4 -> V_55 == V_32 )
break;
F_8 ( & V_9 -> V_13 ) ;
return V_4 ;
}
T_1 F_28 ( struct V_51 * V_52 )
{
struct V_8 * V_9 = V_52 -> V_9 ;
T_1 V_56 = V_9 -> V_32 ;
do {
if ( ++ V_56 == 0 )
V_56 = 1 ;
} while ( F_27 ( V_56 , V_9 ) );
V_9 -> V_32 = V_56 ;
return V_56 ;
}
int F_29 ( struct V_51 * V_52 , struct V_10 * V_11 , T_1 V_32 )
{
struct V_8 * V_9 = V_52 -> V_9 ;
struct V_3 * V_4 = F_27 ( V_32 , V_9 ) ;
if ( V_4 ) {
V_11 -> V_12 = V_4 ;
V_11 -> V_9 = V_9 ;
return 1 ;
}
return 0 ;
}
int F_30 ( struct V_51 * V_52 , T_1 V_32 , struct V_10 * V_11 ,
int V_17 )
{
struct V_8 * V_9 = V_52 -> V_9 ;
struct V_3 * V_4 = NULL ;
if ( V_32 && ( V_4 = F_27 ( V_32 , V_9 ) ) != NULL ) {
if ( V_17 )
V_4 -> V_20 ++ ;
V_4 -> V_22 ++ ;
V_11 -> V_12 = V_4 ;
V_11 -> V_9 = V_9 ;
return 1 ;
}
return 0 ;
}
void F_31 ( struct V_10 * V_11 , struct V_36 * V_57 )
{
struct V_3 * V_58 = V_11 -> V_12 ;
if ( V_57 )
F_9 ( & V_58 -> V_15 ,
& V_58 -> V_16 ) ;
F_10 ( & V_58 -> V_5 , F_1 ) ;
}
int F_32 ( struct V_51 * V_52 , T_1 V_32 , struct V_36 * V_57 ,
struct V_10 * V_11 , int V_59 , int V_17 , bool V_60 )
{
struct V_3 * V_4 = F_33 ( V_59 , V_61 ) ;
struct V_8 * V_9 = V_52 -> V_9 ;
int V_31 = - V_62 ;
if ( F_34 ( ! V_4 ) )
return - V_62 ;
V_4 -> V_22 = 1 ;
if ( V_17 )
V_4 -> V_20 = 1 ;
if ( V_60 ) {
V_4 -> V_6 = F_35 ( struct V_63 ) ;
if ( ! V_4 -> V_6 ) {
V_64:
F_4 ( V_4 ) ;
return V_31 ;
}
V_4 -> V_7 = F_36 ( struct V_65 ) ;
if ( ! V_4 -> V_7 ) {
V_66:
F_3 ( V_4 -> V_6 ) ;
goto V_64;
}
}
F_37 ( & V_4 -> V_67 ) ;
F_38 ( & V_4 -> V_14 ) ;
V_4 -> V_55 = V_32 ? V_32 : F_28 ( V_52 ) ;
V_4 -> V_68 . V_69 = V_70 ;
V_4 -> V_68 . V_71 = V_70 ;
if ( V_57 ) {
V_31 = F_39 ( & V_4 -> V_15 , V_4 -> V_6 ,
& V_4 -> V_16 ,
& V_4 -> V_67 , V_57 ) ;
if ( V_31 ) {
F_3 ( V_4 -> V_7 ) ;
goto V_66;
}
}
V_11 -> V_12 = ( void * ) V_4 ;
V_11 -> V_9 = V_9 ;
return 0 ;
}
void F_40 ( struct V_51 * V_52 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_11 -> V_12 ;
struct V_8 * V_9 = V_52 -> V_9 ;
unsigned int V_72 = F_13 ( V_4 -> V_55 , V_9 -> V_38 ) ;
F_6 ( & V_9 -> V_13 ) ;
F_41 ( & V_4 -> V_14 , & V_9 -> V_39 [ V_72 ] ) ;
F_8 ( & V_9 -> V_13 ) ;
}
void F_42 ( const struct V_73 * V_23 ,
struct V_8 * V_9 )
{
struct V_10 V_11 = {
. V_23 = V_23 ,
. V_9 = V_9 ,
} ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_9 -> V_38 + 1 ; V_33 ++ ) {
struct V_3 * V_4 ;
struct V_44 * V_45 ;
F_22 (p, n, &hinfo->htab[i], tcfc_head) {
int V_19 ;
V_11 . V_12 = V_4 ;
V_19 = F_11 ( & V_11 , false , true ) ;
if ( V_19 == V_25 )
F_23 ( V_23 -> V_49 ) ;
else if ( V_19 < 0 )
return;
}
}
F_4 ( V_9 -> V_39 ) ;
}
int F_43 ( struct V_73 * V_74 ,
struct V_75 * V_23 )
{
struct V_73 * V_11 ;
int V_19 ;
if ( ! V_74 -> V_74 || ! V_74 -> V_76 || ! V_74 -> V_77 || ! V_74 -> V_78 || ! V_74 -> V_79 )
return - V_46 ;
F_44 ( & V_80 ) ;
F_45 (a, &act_base, head) {
if ( V_74 -> type == V_11 -> type || ( strcmp ( V_74 -> V_48 , V_11 -> V_48 ) == 0 ) ) {
F_46 ( & V_80 ) ;
return - V_81 ;
}
}
F_47 ( & V_74 -> V_2 , & V_82 ) ;
F_46 ( & V_80 ) ;
V_19 = F_48 ( V_23 ) ;
if ( V_19 ) {
F_49 ( V_74 , V_23 ) ;
return V_19 ;
}
return 0 ;
}
int F_49 ( struct V_73 * V_74 ,
struct V_75 * V_23 )
{
struct V_73 * V_11 ;
int V_31 = - V_83 ;
F_50 ( V_23 ) ;
F_44 ( & V_80 ) ;
F_45 (a, &act_base, head) {
if ( V_11 == V_74 ) {
F_51 ( & V_74 -> V_2 ) ;
V_31 = 0 ;
break;
}
}
F_46 ( & V_80 ) ;
return V_31 ;
}
static struct V_73 * F_52 ( char * V_48 )
{
struct V_73 * V_11 , * V_84 = NULL ;
if ( V_48 ) {
F_53 ( & V_80 ) ;
F_45 (a, &act_base, head) {
if ( strcmp ( V_48 , V_11 -> V_48 ) == 0 ) {
if ( F_54 ( V_11 -> V_49 ) )
V_84 = V_11 ;
break;
}
}
F_55 ( & V_80 ) ;
}
return V_84 ;
}
static struct V_73 * F_56 ( struct V_36 * V_48 )
{
struct V_73 * V_11 , * V_84 = NULL ;
if ( V_48 ) {
F_53 ( & V_80 ) ;
F_45 (a, &act_base, head) {
if ( F_57 ( V_48 , V_11 -> V_48 ) == 0 ) {
if ( F_54 ( V_11 -> V_49 ) )
V_84 = V_11 ;
break;
}
}
F_55 ( & V_80 ) ;
}
return V_84 ;
}
int F_58 ( struct V_26 * V_27 , const struct V_85 * V_86 ,
struct V_87 * V_84 )
{
const struct V_10 * V_11 ;
int V_19 = - 1 ;
if ( V_27 -> V_88 & V_89 ) {
V_27 -> V_88 = F_59 ( V_27 -> V_88 ) ;
V_19 = V_90 ;
goto V_91;
}
F_45 (a, actions, list) {
V_92:
V_19 = V_11 -> V_23 -> V_74 ( V_27 , V_11 , V_84 ) ;
if ( V_19 == V_93 )
goto V_92;
if ( V_19 != V_94 )
goto V_91;
}
V_91:
return V_19 ;
}
int F_60 ( struct V_85 * V_86 , int V_17 )
{
struct V_10 * V_11 , * V_95 ;
int V_19 = 0 ;
F_61 (a, tmp, actions, list) {
V_19 = F_11 ( V_11 , V_17 , true ) ;
if ( V_19 == V_25 )
F_23 ( V_11 -> V_23 -> V_49 ) ;
else if ( V_19 < 0 )
return V_19 ;
F_51 ( & V_11 -> V_96 ) ;
F_4 ( V_11 ) ;
}
return V_19 ;
}
int
F_62 ( struct V_26 * V_27 , struct V_10 * V_11 , int V_17 , int V_97 )
{
return V_11 -> V_23 -> V_76 ( V_27 , V_11 , V_17 , V_97 ) ;
}
int
F_16 ( struct V_26 * V_27 , struct V_10 * V_11 , int V_17 , int V_97 )
{
int V_31 = - V_46 ;
unsigned char * V_98 = F_63 ( V_27 ) ;
struct V_36 * V_37 ;
if ( F_21 ( V_27 , V_47 , V_11 -> V_23 -> V_48 ) )
goto V_41;
if ( F_64 ( V_27 , V_11 , 0 ) )
goto V_41;
V_37 = F_15 ( V_27 , V_99 ) ;
if ( V_37 == NULL )
goto V_41;
V_31 = F_62 ( V_27 , V_11 , V_17 , V_97 ) ;
if ( V_31 > 0 ) {
F_18 ( V_27 , V_37 ) ;
return V_31 ;
}
V_41:
F_17 ( V_27 , V_98 ) ;
return - 1 ;
}
int
F_65 ( struct V_26 * V_27 , struct V_85 * V_86 , int V_17 , int V_97 )
{
struct V_10 * V_11 ;
int V_31 = - V_46 ;
struct V_36 * V_37 ;
F_45 (a, actions, list) {
V_37 = F_15 ( V_27 , V_11 -> V_40 ) ;
if ( V_37 == NULL )
goto V_41;
V_31 = F_16 ( V_27 , V_11 , V_17 , V_97 ) ;
if ( V_31 < 0 )
goto V_100;
F_18 ( V_27 , V_37 ) ;
}
return 0 ;
V_41:
V_31 = - V_46 ;
V_100:
F_19 ( V_27 , V_37 ) ;
return V_31 ;
}
struct V_10 * F_66 ( struct V_101 * V_101 , struct V_36 * V_102 ,
struct V_36 * V_57 , char * V_103 , int V_104 ,
int V_17 )
{
struct V_10 * V_11 ;
struct V_73 * V_105 ;
char V_106 [ V_107 ] ;
struct V_36 * V_108 [ V_109 + 1 ] ;
struct V_36 * V_48 ;
int V_31 ;
if ( V_103 == NULL ) {
V_31 = F_67 ( V_108 , V_109 , V_102 , NULL ) ;
if ( V_31 < 0 )
goto V_110;
V_31 = - V_46 ;
V_48 = V_108 [ V_111 ] ;
if ( V_48 == NULL )
goto V_110;
if ( F_68 ( V_106 , V_48 , V_107 ) >= V_107 )
goto V_110;
} else {
V_31 = - V_46 ;
if ( F_69 ( V_106 , V_103 , V_107 ) >= V_107 )
goto V_110;
}
V_105 = F_52 ( V_106 ) ;
if ( V_105 == NULL ) {
#ifdef F_70
F_71 () ;
F_72 ( L_2 , V_106 ) ;
F_73 () ;
V_105 = F_52 ( V_106 ) ;
if ( V_105 != NULL ) {
V_31 = - V_112 ;
goto V_113;
}
#endif
V_31 = - V_83 ;
goto V_110;
}
V_31 = - V_62 ;
V_11 = F_33 ( sizeof( * V_11 ) , V_61 ) ;
if ( V_11 == NULL )
goto V_113;
V_11 -> V_23 = V_105 ;
F_74 ( & V_11 -> V_96 ) ;
if ( V_103 == NULL )
V_31 = V_105 -> V_77 ( V_101 , V_108 [ V_114 ] , V_57 , V_11 , V_104 , V_17 ) ;
else
V_31 = V_105 -> V_77 ( V_101 , V_102 , V_57 , V_11 , V_104 , V_17 ) ;
if ( V_31 < 0 )
goto V_115;
if ( V_31 != V_116 )
F_23 ( V_105 -> V_49 ) ;
return V_11 ;
V_115:
F_4 ( V_11 ) ;
V_113:
F_23 ( V_105 -> V_49 ) ;
V_110:
return F_75 ( V_31 ) ;
}
int F_76 ( struct V_101 * V_101 , struct V_36 * V_102 ,
struct V_36 * V_57 , char * V_103 , int V_104 ,
int V_17 , struct V_85 * V_86 )
{
struct V_36 * V_108 [ V_43 + 1 ] ;
struct V_10 * V_74 ;
int V_31 ;
int V_33 ;
V_31 = F_67 ( V_108 , V_43 , V_102 , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
for ( V_33 = 1 ; V_33 <= V_43 && V_108 [ V_33 ] ; V_33 ++ ) {
V_74 = F_66 ( V_101 , V_108 [ V_33 ] , V_57 , V_103 , V_104 , V_17 ) ;
if ( F_77 ( V_74 ) ) {
V_31 = F_78 ( V_74 ) ;
goto V_31;
}
V_74 -> V_40 = V_33 ;
F_47 ( & V_74 -> V_96 , V_86 ) ;
}
return 0 ;
V_31:
F_60 ( V_86 , V_17 ) ;
return V_31 ;
}
int F_64 ( struct V_26 * V_27 , struct V_10 * V_11 ,
int V_117 )
{
int V_31 = 0 ;
struct V_118 V_119 ;
struct V_3 * V_4 = V_11 -> V_12 ;
if ( V_4 == NULL )
goto V_100;
if ( V_117 ) {
if ( V_11 -> type == V_120 )
V_31 = F_79 ( V_27 , 0 ,
V_121 , V_122 , & V_4 -> V_67 , & V_119 ) ;
else
return 0 ;
} else
V_31 = F_80 ( V_27 , V_123 ,
& V_4 -> V_67 , & V_119 ) ;
if ( V_31 < 0 )
goto V_100;
if ( F_81 ( & V_119 , V_4 -> V_6 , & V_4 -> V_15 ) < 0 ||
F_82 ( & V_119 , & V_4 -> V_15 ,
& V_4 -> V_16 ) < 0 ||
F_83 ( & V_119 , V_4 -> V_7 ,
& V_4 -> V_124 ,
V_4 -> V_124 . V_125 ) < 0 )
goto V_100;
if ( F_84 ( & V_119 ) < 0 )
goto V_100;
return 0 ;
V_100:
return - 1 ;
}
static int
F_85 ( struct V_26 * V_27 , struct V_85 * V_86 , T_1 V_126 , T_1 V_127 ,
T_2 V_128 , int V_129 , int V_17 , int V_97 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 ;
unsigned char * V_98 = F_63 ( V_27 ) ;
struct V_36 * V_37 ;
V_133 = F_86 ( V_27 , V_126 , V_127 , V_129 , sizeof( * V_131 ) , V_128 ) ;
if ( ! V_133 )
goto V_134;
V_131 = F_87 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_37 = F_15 ( V_27 , V_139 ) ;
if ( V_37 == NULL )
goto V_134;
if ( F_65 ( V_27 , V_86 , V_17 , V_97 ) < 0 )
goto V_134;
F_18 ( V_27 , V_37 ) ;
V_133 -> V_140 = F_63 ( V_27 ) - V_98 ;
return V_27 -> V_141 ;
V_134:
F_17 ( V_27 , V_98 ) ;
return - 1 ;
}
static int
F_88 ( struct V_101 * V_101 , T_1 V_126 , struct V_132 * V_45 ,
struct V_85 * V_86 , int V_129 )
{
struct V_26 * V_27 ;
V_27 = F_89 ( V_142 , V_61 ) ;
if ( ! V_27 )
return - V_143 ;
if ( F_85 ( V_27 , V_86 , V_126 , V_45 -> V_144 , 0 , V_129 , 0 , 0 ) <= 0 ) {
F_90 ( V_27 ) ;
return - V_46 ;
}
return F_91 ( V_27 , V_101 , V_126 ) ;
}
static struct V_10 * F_92 ( int V_33 )
{
struct V_10 * V_74 ;
V_74 = F_33 ( sizeof( * V_74 ) , V_61 ) ;
if ( V_74 == NULL ) {
F_93 ( L_3 ) ;
return NULL ;
}
V_74 -> V_40 = V_33 ;
F_74 ( & V_74 -> V_96 ) ;
return V_74 ;
}
static struct V_10 * F_94 ( struct V_101 * V_101 , struct V_36 * V_102 ,
struct V_132 * V_45 , T_1 V_126 )
{
struct V_36 * V_108 [ V_109 + 1 ] ;
struct V_10 * V_11 ;
int V_32 ;
int V_31 ;
V_31 = F_67 ( V_108 , V_109 , V_102 , NULL ) ;
if ( V_31 < 0 )
goto V_110;
V_31 = - V_46 ;
if ( V_108 [ V_145 ] == NULL ||
F_95 ( V_108 [ V_145 ] ) < sizeof( V_32 ) )
goto V_110;
V_32 = F_96 ( V_108 [ V_145 ] ) ;
V_31 = - V_62 ;
V_11 = F_92 ( 0 ) ;
if ( V_11 == NULL )
goto V_110;
V_31 = - V_46 ;
V_11 -> V_23 = F_56 ( V_108 [ V_111 ] ) ;
if ( V_11 -> V_23 == NULL )
goto V_115;
V_31 = - V_83 ;
if ( V_11 -> V_23 -> V_79 ( V_101 , V_11 , V_32 ) == 0 )
goto V_113;
F_23 ( V_11 -> V_23 -> V_49 ) ;
return V_11 ;
V_113:
F_23 ( V_11 -> V_23 -> V_49 ) ;
V_115:
F_4 ( V_11 ) ;
V_110:
return F_75 ( V_31 ) ;
}
static void F_97 ( struct V_85 * V_86 )
{
struct V_10 * V_11 , * V_95 ;
F_61 (a, tmp, actions, list) {
F_51 ( & V_11 -> V_96 ) ;
F_4 ( V_11 ) ;
}
}
static int F_98 ( struct V_101 * V_101 , struct V_36 * V_102 ,
struct V_132 * V_45 , T_1 V_126 )
{
struct V_26 * V_27 ;
unsigned char * V_98 ;
struct V_132 * V_133 ;
struct V_130 * V_131 ;
struct V_28 V_146 ;
struct V_36 * V_37 ;
struct V_36 * V_108 [ V_109 + 1 ] ;
struct V_36 * V_48 ;
struct V_10 V_11 ;
int V_31 = - V_62 ;
V_27 = F_89 ( V_142 , V_61 ) ;
if ( ! V_27 ) {
F_93 ( L_4 ) ;
return V_31 ;
}
V_98 = F_63 ( V_27 ) ;
V_31 = F_67 ( V_108 , V_109 , V_102 , NULL ) ;
if ( V_31 < 0 )
goto V_110;
V_31 = - V_46 ;
V_48 = V_108 [ V_111 ] ;
memset ( & V_11 , 0 , sizeof( struct V_10 ) ) ;
F_74 ( & V_11 . V_96 ) ;
V_11 . V_23 = F_56 ( V_48 ) ;
if ( V_11 . V_23 == NULL )
goto V_110;
V_133 = F_86 ( V_27 , V_126 , V_45 -> V_144 , V_53 , sizeof( * V_131 ) , 0 ) ;
if ( ! V_133 )
goto V_147;
V_131 = F_87 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_37 = F_15 ( V_27 , V_139 ) ;
if ( V_37 == NULL )
goto V_147;
V_31 = V_11 . V_23 -> V_78 ( V_101 , V_27 , & V_146 , V_53 , & V_11 ) ;
if ( V_31 < 0 )
goto V_147;
if ( V_31 == 0 )
goto V_148;
F_18 ( V_27 , V_37 ) ;
V_133 -> V_140 = F_63 ( V_27 ) - V_98 ;
V_133 -> V_149 |= V_150 ;
F_23 ( V_11 . V_23 -> V_49 ) ;
V_31 = F_99 ( V_27 , V_101 , V_126 , V_151 ,
V_45 -> V_149 & V_152 ) ;
if ( V_31 > 0 )
return 0 ;
return V_31 ;
V_147:
F_23 ( V_11 . V_23 -> V_49 ) ;
V_110:
V_148:
F_90 ( V_27 ) ;
return V_31 ;
}
static int
F_100 ( struct V_101 * V_101 , struct V_132 * V_45 , struct V_85 * V_86 ,
T_1 V_126 )
{
int V_19 ;
struct V_26 * V_27 ;
V_27 = F_89 ( V_142 , V_61 ) ;
if ( ! V_27 )
return - V_143 ;
if ( F_85 ( V_27 , V_86 , V_126 , V_45 -> V_144 , 0 , V_53 ,
0 , 1 ) <= 0 ) {
F_90 ( V_27 ) ;
return - V_46 ;
}
V_19 = F_60 ( V_86 , 0 ) ;
if ( V_19 < 0 ) {
F_90 ( V_27 ) ;
return V_19 ;
}
V_19 = F_99 ( V_27 , V_101 , V_126 , V_151 ,
V_45 -> V_149 & V_152 ) ;
if ( V_19 > 0 )
return 0 ;
return V_19 ;
}
static int
F_101 ( struct V_101 * V_101 , struct V_36 * V_102 , struct V_132 * V_45 ,
T_1 V_126 , int V_129 )
{
int V_33 , V_19 ;
struct V_36 * V_108 [ V_43 + 1 ] ;
struct V_10 * V_74 ;
F_102 ( V_86 ) ;
V_19 = F_67 ( V_108 , V_43 , V_102 , NULL ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_129 == V_53 && V_45 -> V_149 & V_150 ) {
if ( V_108 [ 1 ] != NULL )
return F_98 ( V_101 , V_108 [ 1 ] , V_45 , V_126 ) ;
else
return - V_46 ;
}
for ( V_33 = 1 ; V_33 <= V_43 && V_108 [ V_33 ] ; V_33 ++ ) {
V_74 = F_94 ( V_101 , V_108 [ V_33 ] , V_45 , V_126 ) ;
if ( F_77 ( V_74 ) ) {
V_19 = F_78 ( V_74 ) ;
goto V_31;
}
V_74 -> V_40 = V_33 ;
F_47 ( & V_74 -> V_96 , & V_86 ) ;
}
if ( V_129 == V_54 )
V_19 = F_88 ( V_101 , V_126 , V_45 , & V_86 , V_129 ) ;
else {
V_19 = F_100 ( V_101 , V_45 , & V_86 , V_126 ) ;
if ( V_19 )
goto V_31;
return V_19 ;
}
V_31:
F_97 ( & V_86 ) ;
return V_19 ;
}
static int
F_103 ( struct V_101 * V_101 , struct V_132 * V_45 , struct V_85 * V_86 ,
T_1 V_126 )
{
struct V_26 * V_27 ;
int V_31 = 0 ;
V_27 = F_89 ( V_142 , V_61 ) ;
if ( ! V_27 )
return - V_143 ;
if ( F_85 ( V_27 , V_86 , V_126 , V_45 -> V_144 , V_45 -> V_149 ,
V_153 , 0 , 0 ) <= 0 ) {
F_90 ( V_27 ) ;
return - V_46 ;
}
V_31 = F_99 ( V_27 , V_101 , V_126 , V_151 ,
V_45 -> V_149 & V_152 ) ;
if ( V_31 > 0 )
V_31 = 0 ;
return V_31 ;
}
static int
F_104 ( struct V_101 * V_101 , struct V_36 * V_102 , struct V_132 * V_45 ,
T_1 V_126 , int V_104 )
{
int V_19 = 0 ;
F_102 ( V_86 ) ;
V_19 = F_76 ( V_101 , V_102 , NULL , NULL , V_104 , 0 , & V_86 ) ;
if ( V_19 )
goto V_42;
V_19 = F_103 ( V_101 , V_45 , & V_86 , V_126 ) ;
F_97 ( & V_86 ) ;
V_42:
return V_19 ;
}
static int F_105 ( struct V_26 * V_27 , struct V_132 * V_45 )
{
struct V_101 * V_101 = F_106 ( V_27 -> V_154 ) ;
struct V_36 * V_155 [ V_109 + 1 ] ;
T_1 V_126 = V_27 ? F_107 ( V_27 ) . V_126 : 0 ;
int V_19 = 0 , V_104 = 0 ;
if ( ( V_45 -> V_156 != V_54 ) && ! F_108 ( V_27 , V_157 ) )
return - V_21 ;
V_19 = F_109 ( V_45 , sizeof( struct V_130 ) , V_155 , V_109 , NULL ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_155 [ V_139 ] == NULL ) {
F_110 ( L_5 ) ;
return - V_46 ;
}
switch ( V_45 -> V_156 ) {
case V_153 :
if ( V_45 -> V_149 & V_158 )
V_104 = 1 ;
V_159:
V_19 = F_104 ( V_101 , V_155 [ V_139 ] , V_45 , V_126 , V_104 ) ;
if ( V_19 == - V_112 )
goto V_159;
break;
case V_53 :
V_19 = F_101 ( V_101 , V_155 [ V_139 ] , V_45 ,
V_126 , V_53 ) ;
break;
case V_54 :
V_19 = F_101 ( V_101 , V_155 [ V_139 ] , V_45 ,
V_126 , V_54 ) ;
break;
default:
F_111 () ;
}
return V_19 ;
}
static struct V_36 *
F_112 ( const struct V_132 * V_45 )
{
struct V_36 * V_160 , * V_161 [ V_109 + 1 ] ;
struct V_36 * V_108 [ V_43 + 1 ] ;
struct V_36 * V_102 [ V_162 + 1 ] ;
struct V_36 * V_48 ;
if ( F_109 ( V_45 , sizeof( struct V_130 ) , V_102 , V_162 , NULL ) < 0 )
return NULL ;
V_160 = V_102 [ V_139 ] ;
if ( V_160 == NULL )
return NULL ;
if ( F_113 ( V_108 , V_43 , F_114 ( V_160 ) ,
F_115 ( F_95 ( V_160 ) ) , NULL ) < 0 )
return NULL ;
if ( V_108 [ 1 ] == NULL )
return NULL ;
if ( F_113 ( V_161 , V_109 , F_114 ( V_108 [ 1 ] ) ,
F_95 ( V_108 [ 1 ] ) , NULL ) < 0 )
return NULL ;
V_48 = V_161 [ V_111 ] ;
return V_48 ;
}
static int
F_116 ( struct V_26 * V_27 , struct V_28 * V_29 )
{
struct V_101 * V_101 = F_106 ( V_27 -> V_154 ) ;
struct V_132 * V_133 ;
unsigned char * V_98 = F_63 ( V_27 ) ;
struct V_36 * V_37 ;
struct V_73 * V_105 ;
struct V_10 V_11 ;
int V_19 = 0 ;
struct V_130 * V_131 = (struct V_130 * ) F_87 ( V_29 -> V_133 ) ;
struct V_36 * V_48 = F_112 ( V_29 -> V_133 ) ;
if ( V_48 == NULL ) {
F_117 ( L_6 ) ;
return 0 ;
}
V_105 = F_56 ( V_48 ) ;
if ( V_105 == NULL )
return 0 ;
memset ( & V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 . V_23 = V_105 ;
V_133 = F_86 ( V_27 , F_107 ( V_29 -> V_27 ) . V_126 , V_29 -> V_133 -> V_144 ,
V_29 -> V_133 -> V_156 , sizeof( * V_131 ) , 0 ) ;
if ( ! V_133 )
goto V_147;
V_131 = F_87 ( V_133 ) ;
V_131 -> V_135 = V_136 ;
V_131 -> V_137 = 0 ;
V_131 -> V_138 = 0 ;
V_37 = F_15 ( V_27 , V_139 ) ;
if ( V_37 == NULL )
goto V_147;
V_19 = V_105 -> V_78 ( V_101 , V_27 , V_29 , V_54 , & V_11 ) ;
if ( V_19 < 0 )
goto V_147;
if ( V_19 > 0 ) {
F_18 ( V_27 , V_37 ) ;
V_19 = V_27 -> V_141 ;
} else
F_19 ( V_27 , V_37 ) ;
V_133 -> V_140 = F_63 ( V_27 ) - V_98 ;
if ( F_107 ( V_29 -> V_27 ) . V_126 && V_19 )
V_133 -> V_149 |= V_163 ;
F_23 ( V_105 -> V_49 ) ;
return V_27 -> V_141 ;
V_147:
F_23 ( V_105 -> V_49 ) ;
F_17 ( V_27 , V_98 ) ;
return V_27 -> V_141 ;
}
static int T_3 F_118 ( void )
{
F_119 ( V_164 , V_153 , F_105 , NULL , NULL ) ;
F_119 ( V_164 , V_53 , F_105 , NULL , NULL ) ;
F_119 ( V_164 , V_54 , F_105 , F_116 ,
NULL ) ;
return 0 ;
}
