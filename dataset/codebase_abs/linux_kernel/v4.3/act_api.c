static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
F_6 ( & V_12 -> V_14 ) ;
F_7 ( & V_4 -> V_15 ) ;
F_8 ( & V_12 -> V_14 ) ;
F_9 ( & V_4 -> V_16 ,
& V_4 -> V_17 ) ;
F_10 ( & V_4 -> V_5 , F_1 ) ;
}
int F_11 ( struct V_8 * V_9 , bool V_18 , bool V_19 )
{
struct V_3 * V_4 = V_9 -> V_10 ;
int V_20 = 0 ;
if ( V_4 ) {
if ( V_18 )
V_4 -> V_21 -- ;
else if ( V_19 && V_4 -> V_21 > 0 )
return - V_22 ;
V_4 -> V_23 -- ;
if ( V_4 -> V_21 <= 0 && V_4 -> V_23 <= 0 ) {
if ( V_9 -> V_13 -> V_24 )
V_9 -> V_13 -> V_24 ( V_9 , V_18 ) ;
F_5 ( V_9 ) ;
V_20 = 1 ;
}
}
return V_20 ;
}
static int F_12 ( struct V_25 * V_26 , struct V_27 * V_28 ,
struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
struct V_29 * V_2 ;
struct V_3 * V_4 ;
int V_30 = 0 , V_31 = - 1 , V_32 = 0 , V_33 = 0 , V_34 = 0 ;
struct V_35 * V_36 ;
F_6 ( & V_12 -> V_14 ) ;
V_33 = V_28 -> args [ 0 ] ;
for ( V_32 = 0 ; V_32 < ( V_12 -> V_37 + 1 ) ; V_32 ++ ) {
V_2 = & V_12 -> V_38 [ F_13 ( V_32 , V_12 -> V_37 ) ] ;
F_14 (p, head, tcfc_head) {
V_31 ++ ;
if ( V_31 < V_33 )
continue;
V_9 -> V_10 = V_4 ;
V_9 -> V_39 = V_34 ;
V_36 = F_15 ( V_26 , V_9 -> V_39 ) ;
if ( V_36 == NULL )
goto V_40;
V_30 = F_16 ( V_26 , V_9 , 0 , 0 ) ;
if ( V_30 < 0 ) {
V_31 -- ;
F_17 ( V_26 , V_36 ) ;
goto V_41;
}
F_18 ( V_26 , V_36 ) ;
V_34 ++ ;
if ( V_34 >= V_42 )
goto V_41;
}
}
V_41:
F_8 ( & V_12 -> V_14 ) ;
if ( V_34 )
V_28 -> args [ 0 ] += V_34 ;
return V_34 ;
V_40:
F_19 ( V_26 , V_36 ) ;
goto V_41;
}
static int F_20 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
struct V_29 * V_2 ;
struct V_43 * V_44 ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_32 = 0 , V_34 = 0 ;
int V_20 = - V_45 ;
V_36 = F_15 ( V_26 , V_9 -> V_39 ) ;
if ( V_36 == NULL )
goto V_40;
if ( F_21 ( V_26 , V_46 , V_9 -> V_13 -> V_47 ) )
goto V_40;
for ( V_32 = 0 ; V_32 < ( V_12 -> V_37 + 1 ) ; V_32 ++ ) {
V_2 = & V_12 -> V_38 [ F_13 ( V_32 , V_12 -> V_37 ) ] ;
F_22 (p, n, head, tcfc_head) {
V_9 -> V_10 = V_4 ;
V_20 = F_11 ( V_9 , false , true ) ;
if ( V_20 == V_48 ) {
F_23 ( V_9 -> V_13 -> V_49 ) ;
V_34 ++ ;
} else if ( V_20 < 0 )
goto V_40;
}
}
if ( F_24 ( V_26 , V_50 , V_34 ) )
goto V_40;
F_18 ( V_26 , V_36 ) ;
return V_34 ;
V_40:
F_19 ( V_26 , V_36 ) ;
return V_20 ;
}
static int F_25 ( struct V_25 * V_26 , struct V_27 * V_28 ,
int type , struct V_8 * V_9 )
{
if ( type == V_51 ) {
return F_20 ( V_26 , V_9 ) ;
} else if ( type == V_52 ) {
return F_12 ( V_26 , V_28 , V_9 ) ;
} else {
F_26 ( 1 , L_1 , type ) ;
return - V_45 ;
}
}
static struct V_3 * F_27 ( T_1 V_31 , struct V_11 * V_12 )
{
struct V_3 * V_4 = NULL ;
struct V_29 * V_2 ;
F_6 ( & V_12 -> V_14 ) ;
V_2 = & V_12 -> V_38 [ F_13 ( V_31 , V_12 -> V_37 ) ] ;
F_14 (p, head, tcfc_head)
if ( V_4 -> V_53 == V_31 )
break;
F_8 ( & V_12 -> V_14 ) ;
return V_4 ;
}
T_1 F_28 ( struct V_11 * V_12 )
{
T_1 V_54 = V_12 -> V_31 ;
do {
if ( ++ V_54 == 0 )
V_54 = 1 ;
} while ( F_27 ( V_54 , V_12 ) );
V_12 -> V_31 = V_54 ;
return V_54 ;
}
int F_29 ( struct V_8 * V_9 , T_1 V_31 )
{
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
struct V_3 * V_4 = F_27 ( V_31 , V_12 ) ;
if ( V_4 ) {
V_9 -> V_10 = V_4 ;
return 1 ;
}
return 0 ;
}
int F_30 ( T_1 V_31 , struct V_8 * V_9 , int V_18 )
{
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
struct V_3 * V_4 = NULL ;
if ( V_31 && ( V_4 = F_27 ( V_31 , V_12 ) ) != NULL ) {
if ( V_18 )
V_4 -> V_21 ++ ;
V_4 -> V_23 ++ ;
V_9 -> V_10 = V_4 ;
return 1 ;
}
return 0 ;
}
void F_31 ( struct V_8 * V_9 , struct V_35 * V_55 )
{
struct V_3 * V_56 = V_9 -> V_10 ;
if ( V_55 )
F_9 ( & V_56 -> V_16 ,
& V_56 -> V_17 ) ;
F_10 ( & V_56 -> V_5 , F_1 ) ;
}
int F_32 ( T_1 V_31 , struct V_35 * V_55 , struct V_8 * V_9 ,
int V_57 , int V_18 , bool V_58 )
{
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
struct V_3 * V_4 = F_33 ( V_57 , V_59 ) ;
int V_30 = - V_60 ;
if ( F_34 ( ! V_4 ) )
return - V_60 ;
V_4 -> V_23 = 1 ;
if ( V_18 )
V_4 -> V_21 = 1 ;
if ( V_58 ) {
V_4 -> V_6 = F_35 ( struct V_61 ) ;
if ( ! V_4 -> V_6 ) {
V_62:
F_4 ( V_4 ) ;
return V_30 ;
}
V_4 -> V_7 = F_36 ( struct V_63 ) ;
if ( ! V_4 -> V_7 ) {
V_64:
F_3 ( V_4 -> V_6 ) ;
goto V_62;
}
}
F_37 ( & V_4 -> V_65 ) ;
F_38 ( & V_4 -> V_15 ) ;
V_4 -> V_53 = V_31 ? V_31 : F_28 ( V_12 ) ;
V_4 -> V_66 . V_67 = V_68 ;
V_4 -> V_66 . V_69 = V_68 ;
if ( V_55 ) {
V_30 = F_39 ( & V_4 -> V_16 , V_4 -> V_6 ,
& V_4 -> V_17 ,
& V_4 -> V_65 , V_55 ) ;
if ( V_30 ) {
F_3 ( V_4 -> V_7 ) ;
goto V_64;
}
}
V_9 -> V_10 = ( void * ) V_4 ;
return 0 ;
}
void F_40 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_10 ;
struct V_11 * V_12 = V_9 -> V_13 -> V_12 ;
unsigned int V_70 = F_13 ( V_4 -> V_53 , V_12 -> V_37 ) ;
F_6 ( & V_12 -> V_14 ) ;
F_41 ( & V_4 -> V_15 , & V_12 -> V_38 [ V_70 ] ) ;
F_8 ( & V_12 -> V_14 ) ;
}
int F_42 ( struct V_71 * V_72 , unsigned int V_73 )
{
struct V_71 * V_9 ;
int V_30 ;
if ( ! V_72 -> V_72 || ! V_72 -> V_74 || ! V_72 -> V_75 )
return - V_45 ;
if ( ! V_72 -> V_76 )
V_72 -> V_76 = F_29 ;
if ( ! V_72 -> V_77 )
V_72 -> V_77 = F_25 ;
V_72 -> V_12 = F_43 ( sizeof( struct V_11 ) , V_59 ) ;
if ( ! V_72 -> V_12 )
return - V_60 ;
V_30 = F_44 ( V_72 -> V_12 , V_73 ) ;
if ( V_30 ) {
F_4 ( V_72 -> V_12 ) ;
return V_30 ;
}
F_45 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( V_72 -> type == V_9 -> type || ( strcmp ( V_72 -> V_47 , V_9 -> V_47 ) == 0 ) ) {
F_47 ( & V_78 ) ;
F_48 ( V_72 -> V_12 ) ;
F_4 ( V_72 -> V_12 ) ;
return - V_79 ;
}
}
F_49 ( & V_72 -> V_2 , & V_80 ) ;
F_47 ( & V_78 ) ;
return 0 ;
}
int F_50 ( struct V_71 * V_72 )
{
struct V_71 * V_9 ;
int V_30 = - V_81 ;
F_45 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( V_9 == V_72 ) {
F_51 ( & V_72 -> V_2 ) ;
F_48 ( V_72 -> V_12 ) ;
F_4 ( V_72 -> V_12 ) ;
V_30 = 0 ;
break;
}
}
F_47 ( & V_78 ) ;
return V_30 ;
}
static struct V_71 * F_52 ( char * V_47 )
{
struct V_71 * V_9 , * V_82 = NULL ;
if ( V_47 ) {
F_53 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( strcmp ( V_47 , V_9 -> V_47 ) == 0 ) {
if ( F_54 ( V_9 -> V_49 ) )
V_82 = V_9 ;
break;
}
}
F_55 ( & V_78 ) ;
}
return V_82 ;
}
static struct V_71 * F_56 ( struct V_35 * V_47 )
{
struct V_71 * V_9 , * V_82 = NULL ;
if ( V_47 ) {
F_53 ( & V_78 ) ;
F_46 (a, &act_base, head) {
if ( F_57 ( V_47 , V_9 -> V_47 ) == 0 ) {
if ( F_54 ( V_9 -> V_49 ) )
V_82 = V_9 ;
break;
}
}
F_55 ( & V_78 ) ;
}
return V_82 ;
}
int F_58 ( struct V_25 * V_26 , const struct V_83 * V_84 ,
struct V_85 * V_82 )
{
const struct V_8 * V_9 ;
int V_20 = - 1 ;
if ( V_26 -> V_86 & V_87 ) {
V_26 -> V_86 = F_59 ( V_26 -> V_86 ) ;
V_20 = V_88 ;
goto V_89;
}
F_46 (a, actions, list) {
V_90:
V_20 = V_9 -> V_13 -> V_72 ( V_26 , V_9 , V_82 ) ;
if ( V_20 == V_91 )
goto V_90;
if ( V_20 != V_92 )
goto V_89;
}
V_89:
return V_20 ;
}
int F_60 ( struct V_83 * V_84 , int V_18 )
{
struct V_8 * V_9 , * V_93 ;
int V_20 = 0 ;
F_61 (a, tmp, actions, list) {
V_20 = F_11 ( V_9 , V_18 , true ) ;
if ( V_20 == V_48 )
F_23 ( V_9 -> V_13 -> V_49 ) ;
else if ( V_20 < 0 )
return V_20 ;
F_51 ( & V_9 -> V_94 ) ;
F_4 ( V_9 ) ;
}
return V_20 ;
}
int
F_62 ( struct V_25 * V_26 , struct V_8 * V_9 , int V_18 , int V_95 )
{
return V_9 -> V_13 -> V_74 ( V_26 , V_9 , V_18 , V_95 ) ;
}
int
F_16 ( struct V_25 * V_26 , struct V_8 * V_9 , int V_18 , int V_95 )
{
int V_30 = - V_45 ;
unsigned char * V_96 = F_63 ( V_26 ) ;
struct V_35 * V_36 ;
if ( F_21 ( V_26 , V_46 , V_9 -> V_13 -> V_47 ) )
goto V_40;
if ( F_64 ( V_26 , V_9 , 0 ) )
goto V_40;
V_36 = F_15 ( V_26 , V_97 ) ;
if ( V_36 == NULL )
goto V_40;
V_30 = F_62 ( V_26 , V_9 , V_18 , V_95 ) ;
if ( V_30 > 0 ) {
F_18 ( V_26 , V_36 ) ;
return V_30 ;
}
V_40:
F_17 ( V_26 , V_96 ) ;
return - 1 ;
}
int
F_65 ( struct V_25 * V_26 , struct V_83 * V_84 , int V_18 , int V_95 )
{
struct V_8 * V_9 ;
int V_30 = - V_45 ;
struct V_35 * V_36 ;
F_46 (a, actions, list) {
V_36 = F_15 ( V_26 , V_9 -> V_39 ) ;
if ( V_36 == NULL )
goto V_40;
V_30 = F_16 ( V_26 , V_9 , V_18 , V_95 ) ;
if ( V_30 < 0 )
goto V_98;
F_18 ( V_26 , V_36 ) ;
}
return 0 ;
V_40:
V_30 = - V_45 ;
V_98:
F_19 ( V_26 , V_36 ) ;
return V_30 ;
}
struct V_8 * F_66 ( struct V_99 * V_99 , struct V_35 * V_100 ,
struct V_35 * V_55 , char * V_101 , int V_102 ,
int V_18 )
{
struct V_8 * V_9 ;
struct V_71 * V_103 ;
char V_104 [ V_105 ] ;
struct V_35 * V_106 [ V_107 + 1 ] ;
struct V_35 * V_47 ;
int V_30 ;
if ( V_101 == NULL ) {
V_30 = F_67 ( V_106 , V_107 , V_100 , NULL ) ;
if ( V_30 < 0 )
goto V_108;
V_30 = - V_45 ;
V_47 = V_106 [ V_109 ] ;
if ( V_47 == NULL )
goto V_108;
if ( F_68 ( V_104 , V_47 , V_105 ) >= V_105 )
goto V_108;
} else {
V_30 = - V_45 ;
if ( F_69 ( V_104 , V_101 , V_105 ) >= V_105 )
goto V_108;
}
V_103 = F_52 ( V_104 ) ;
if ( V_103 == NULL ) {
#ifdef F_70
F_71 () ;
F_72 ( L_2 , V_104 ) ;
F_73 () ;
V_103 = F_52 ( V_104 ) ;
if ( V_103 != NULL ) {
V_30 = - V_110 ;
goto V_111;
}
#endif
V_30 = - V_81 ;
goto V_108;
}
V_30 = - V_60 ;
V_9 = F_33 ( sizeof( * V_9 ) , V_59 ) ;
if ( V_9 == NULL )
goto V_111;
V_9 -> V_13 = V_103 ;
F_74 ( & V_9 -> V_94 ) ;
if ( V_101 == NULL )
V_30 = V_103 -> V_75 ( V_99 , V_106 [ V_112 ] , V_55 , V_9 , V_102 , V_18 ) ;
else
V_30 = V_103 -> V_75 ( V_99 , V_100 , V_55 , V_9 , V_102 , V_18 ) ;
if ( V_30 < 0 )
goto V_113;
if ( V_30 != V_114 )
F_23 ( V_103 -> V_49 ) ;
return V_9 ;
V_113:
F_4 ( V_9 ) ;
V_111:
F_23 ( V_103 -> V_49 ) ;
V_108:
return F_75 ( V_30 ) ;
}
int F_76 ( struct V_99 * V_99 , struct V_35 * V_100 ,
struct V_35 * V_55 , char * V_101 , int V_102 ,
int V_18 , struct V_83 * V_84 )
{
struct V_35 * V_106 [ V_42 + 1 ] ;
struct V_8 * V_72 ;
int V_30 ;
int V_32 ;
V_30 = F_67 ( V_106 , V_42 , V_100 , NULL ) ;
if ( V_30 < 0 )
return V_30 ;
for ( V_32 = 1 ; V_32 <= V_42 && V_106 [ V_32 ] ; V_32 ++ ) {
V_72 = F_66 ( V_99 , V_106 [ V_32 ] , V_55 , V_101 , V_102 , V_18 ) ;
if ( F_77 ( V_72 ) ) {
V_30 = F_78 ( V_72 ) ;
goto V_30;
}
V_72 -> V_39 = V_32 ;
F_49 ( & V_72 -> V_94 , V_84 ) ;
}
return 0 ;
V_30:
F_60 ( V_84 , V_18 ) ;
return V_30 ;
}
int F_64 ( struct V_25 * V_26 , struct V_8 * V_9 ,
int V_115 )
{
int V_30 = 0 ;
struct V_116 V_117 ;
struct V_3 * V_4 = V_9 -> V_10 ;
if ( V_4 == NULL )
goto V_98;
if ( V_115 ) {
if ( V_9 -> type == V_118 )
V_30 = F_79 ( V_26 , 0 ,
V_119 , V_120 , & V_4 -> V_65 , & V_117 ) ;
else
return 0 ;
} else
V_30 = F_80 ( V_26 , V_121 ,
& V_4 -> V_65 , & V_117 ) ;
if ( V_30 < 0 )
goto V_98;
if ( F_81 ( & V_117 , V_4 -> V_6 , & V_4 -> V_16 ) < 0 ||
F_82 ( & V_117 , & V_4 -> V_16 ,
& V_4 -> V_17 ) < 0 ||
F_83 ( & V_117 , V_4 -> V_7 ,
& V_4 -> V_122 ,
V_4 -> V_122 . V_123 ) < 0 )
goto V_98;
if ( F_84 ( & V_117 ) < 0 )
goto V_98;
return 0 ;
V_98:
return - 1 ;
}
static int
F_85 ( struct V_25 * V_26 , struct V_83 * V_84 , T_1 V_124 , T_1 V_125 ,
T_2 V_126 , int V_127 , int V_18 , int V_95 )
{
struct V_128 * V_129 ;
struct V_130 * V_131 ;
unsigned char * V_96 = F_63 ( V_26 ) ;
struct V_35 * V_36 ;
V_131 = F_86 ( V_26 , V_124 , V_125 , V_127 , sizeof( * V_129 ) , V_126 ) ;
if ( ! V_131 )
goto V_132;
V_129 = F_87 ( V_131 ) ;
V_129 -> V_133 = V_134 ;
V_129 -> V_135 = 0 ;
V_129 -> V_136 = 0 ;
V_36 = F_15 ( V_26 , V_137 ) ;
if ( V_36 == NULL )
goto V_132;
if ( F_65 ( V_26 , V_84 , V_18 , V_95 ) < 0 )
goto V_132;
F_18 ( V_26 , V_36 ) ;
V_131 -> V_138 = F_63 ( V_26 ) - V_96 ;
return V_26 -> V_139 ;
V_132:
F_17 ( V_26 , V_96 ) ;
return - 1 ;
}
static int
F_88 ( struct V_99 * V_99 , T_1 V_124 , struct V_130 * V_44 ,
struct V_83 * V_84 , int V_127 )
{
struct V_25 * V_26 ;
V_26 = F_89 ( V_140 , V_59 ) ;
if ( ! V_26 )
return - V_141 ;
if ( F_85 ( V_26 , V_84 , V_124 , V_44 -> V_142 , 0 , V_127 , 0 , 0 ) <= 0 ) {
F_90 ( V_26 ) ;
return - V_45 ;
}
return F_91 ( V_26 , V_99 , V_124 ) ;
}
static struct V_8 * F_92 ( int V_32 )
{
struct V_8 * V_72 ;
V_72 = F_33 ( sizeof( * V_72 ) , V_59 ) ;
if ( V_72 == NULL ) {
F_93 ( L_3 ) ;
return NULL ;
}
V_72 -> V_39 = V_32 ;
F_74 ( & V_72 -> V_94 ) ;
return V_72 ;
}
static struct V_8 *
F_94 ( struct V_35 * V_100 , struct V_130 * V_44 , T_1 V_124 )
{
struct V_35 * V_106 [ V_107 + 1 ] ;
struct V_8 * V_9 ;
int V_31 ;
int V_30 ;
V_30 = F_67 ( V_106 , V_107 , V_100 , NULL ) ;
if ( V_30 < 0 )
goto V_108;
V_30 = - V_45 ;
if ( V_106 [ V_143 ] == NULL ||
F_95 ( V_106 [ V_143 ] ) < sizeof( V_31 ) )
goto V_108;
V_31 = F_96 ( V_106 [ V_143 ] ) ;
V_30 = - V_60 ;
V_9 = F_92 ( 0 ) ;
if ( V_9 == NULL )
goto V_108;
V_30 = - V_45 ;
V_9 -> V_13 = F_56 ( V_106 [ V_109 ] ) ;
if ( V_9 -> V_13 == NULL )
goto V_113;
V_30 = - V_81 ;
if ( V_9 -> V_13 -> V_76 ( V_9 , V_31 ) == 0 )
goto V_111;
F_23 ( V_9 -> V_13 -> V_49 ) ;
return V_9 ;
V_111:
F_23 ( V_9 -> V_13 -> V_49 ) ;
V_113:
F_4 ( V_9 ) ;
V_108:
return F_75 ( V_30 ) ;
}
static void F_97 ( struct V_83 * V_84 )
{
struct V_8 * V_9 , * V_93 ;
F_61 (a, tmp, actions, list) {
F_51 ( & V_9 -> V_94 ) ;
F_4 ( V_9 ) ;
}
}
static int F_98 ( struct V_99 * V_99 , struct V_35 * V_100 ,
struct V_130 * V_44 , T_1 V_124 )
{
struct V_25 * V_26 ;
unsigned char * V_96 ;
struct V_130 * V_131 ;
struct V_128 * V_129 ;
struct V_27 V_144 ;
struct V_35 * V_36 ;
struct V_35 * V_106 [ V_107 + 1 ] ;
struct V_35 * V_47 ;
struct V_8 V_9 ;
int V_30 = - V_60 ;
V_26 = F_89 ( V_140 , V_59 ) ;
if ( ! V_26 ) {
F_93 ( L_4 ) ;
return V_30 ;
}
V_96 = F_63 ( V_26 ) ;
V_30 = F_67 ( V_106 , V_107 , V_100 , NULL ) ;
if ( V_30 < 0 )
goto V_108;
V_30 = - V_45 ;
V_47 = V_106 [ V_109 ] ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
F_74 ( & V_9 . V_94 ) ;
V_9 . V_13 = F_56 ( V_47 ) ;
if ( V_9 . V_13 == NULL )
goto V_108;
V_131 = F_86 ( V_26 , V_124 , V_44 -> V_142 , V_51 , sizeof( * V_129 ) , 0 ) ;
if ( ! V_131 )
goto V_145;
V_129 = F_87 ( V_131 ) ;
V_129 -> V_133 = V_134 ;
V_129 -> V_135 = 0 ;
V_129 -> V_136 = 0 ;
V_36 = F_15 ( V_26 , V_137 ) ;
if ( V_36 == NULL )
goto V_145;
V_30 = V_9 . V_13 -> V_77 ( V_26 , & V_144 , V_51 , & V_9 ) ;
if ( V_30 < 0 )
goto V_145;
if ( V_30 == 0 )
goto V_146;
F_18 ( V_26 , V_36 ) ;
V_131 -> V_138 = F_63 ( V_26 ) - V_96 ;
V_131 -> V_147 |= V_148 ;
F_23 ( V_9 . V_13 -> V_49 ) ;
V_30 = F_99 ( V_26 , V_99 , V_124 , V_149 ,
V_44 -> V_147 & V_150 ) ;
if ( V_30 > 0 )
return 0 ;
return V_30 ;
V_145:
F_23 ( V_9 . V_13 -> V_49 ) ;
V_108:
V_146:
F_90 ( V_26 ) ;
return V_30 ;
}
static int
F_100 ( struct V_99 * V_99 , struct V_130 * V_44 , struct V_83 * V_84 ,
T_1 V_124 )
{
int V_20 ;
struct V_25 * V_26 ;
V_26 = F_89 ( V_140 , V_59 ) ;
if ( ! V_26 )
return - V_141 ;
if ( F_85 ( V_26 , V_84 , V_124 , V_44 -> V_142 , 0 , V_51 ,
0 , 1 ) <= 0 ) {
F_90 ( V_26 ) ;
return - V_45 ;
}
V_20 = F_60 ( V_84 , 0 ) ;
if ( V_20 < 0 ) {
F_90 ( V_26 ) ;
return V_20 ;
}
V_20 = F_99 ( V_26 , V_99 , V_124 , V_149 ,
V_44 -> V_147 & V_150 ) ;
if ( V_20 > 0 )
return 0 ;
return V_20 ;
}
static int
F_101 ( struct V_99 * V_99 , struct V_35 * V_100 , struct V_130 * V_44 ,
T_1 V_124 , int V_127 )
{
int V_32 , V_20 ;
struct V_35 * V_106 [ V_42 + 1 ] ;
struct V_8 * V_72 ;
F_102 ( V_84 ) ;
V_20 = F_67 ( V_106 , V_42 , V_100 , NULL ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_127 == V_51 && V_44 -> V_147 & V_148 ) {
if ( V_106 [ 1 ] != NULL )
return F_98 ( V_99 , V_106 [ 1 ] , V_44 , V_124 ) ;
else
return - V_45 ;
}
for ( V_32 = 1 ; V_32 <= V_42 && V_106 [ V_32 ] ; V_32 ++ ) {
V_72 = F_94 ( V_106 [ V_32 ] , V_44 , V_124 ) ;
if ( F_77 ( V_72 ) ) {
V_20 = F_78 ( V_72 ) ;
goto V_30;
}
V_72 -> V_39 = V_32 ;
F_49 ( & V_72 -> V_94 , & V_84 ) ;
}
if ( V_127 == V_52 )
V_20 = F_88 ( V_99 , V_124 , V_44 , & V_84 , V_127 ) ;
else {
V_20 = F_100 ( V_99 , V_44 , & V_84 , V_124 ) ;
if ( V_20 )
goto V_30;
return V_20 ;
}
V_30:
F_97 ( & V_84 ) ;
return V_20 ;
}
static int
F_103 ( struct V_99 * V_99 , struct V_130 * V_44 , struct V_83 * V_84 ,
T_1 V_124 )
{
struct V_25 * V_26 ;
int V_30 = 0 ;
V_26 = F_89 ( V_140 , V_59 ) ;
if ( ! V_26 )
return - V_141 ;
if ( F_85 ( V_26 , V_84 , V_124 , V_44 -> V_142 , V_44 -> V_147 ,
V_151 , 0 , 0 ) <= 0 ) {
F_90 ( V_26 ) ;
return - V_45 ;
}
V_30 = F_99 ( V_26 , V_99 , V_124 , V_149 ,
V_44 -> V_147 & V_150 ) ;
if ( V_30 > 0 )
V_30 = 0 ;
return V_30 ;
}
static int
F_104 ( struct V_99 * V_99 , struct V_35 * V_100 , struct V_130 * V_44 ,
T_1 V_124 , int V_102 )
{
int V_20 = 0 ;
F_102 ( V_84 ) ;
V_20 = F_76 ( V_99 , V_100 , NULL , NULL , V_102 , 0 , & V_84 ) ;
if ( V_20 )
goto V_41;
V_20 = F_103 ( V_99 , V_44 , & V_84 , V_124 ) ;
F_97 ( & V_84 ) ;
V_41:
return V_20 ;
}
static int F_105 ( struct V_25 * V_26 , struct V_130 * V_44 )
{
struct V_99 * V_99 = F_106 ( V_26 -> V_152 ) ;
struct V_35 * V_153 [ V_107 + 1 ] ;
T_1 V_124 = V_26 ? F_107 ( V_26 ) . V_124 : 0 ;
int V_20 = 0 , V_102 = 0 ;
if ( ( V_44 -> V_154 != V_52 ) && ! F_108 ( V_26 , V_155 ) )
return - V_22 ;
V_20 = F_109 ( V_44 , sizeof( struct V_128 ) , V_153 , V_107 , NULL ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_153 [ V_137 ] == NULL ) {
F_110 ( L_5 ) ;
return - V_45 ;
}
switch ( V_44 -> V_154 ) {
case V_151 :
if ( V_44 -> V_147 & V_156 )
V_102 = 1 ;
V_157:
V_20 = F_104 ( V_99 , V_153 [ V_137 ] , V_44 , V_124 , V_102 ) ;
if ( V_20 == - V_110 )
goto V_157;
break;
case V_51 :
V_20 = F_101 ( V_99 , V_153 [ V_137 ] , V_44 ,
V_124 , V_51 ) ;
break;
case V_52 :
V_20 = F_101 ( V_99 , V_153 [ V_137 ] , V_44 ,
V_124 , V_52 ) ;
break;
default:
F_111 () ;
}
return V_20 ;
}
static struct V_35 *
F_112 ( const struct V_130 * V_44 )
{
struct V_35 * V_158 , * V_159 [ V_107 + 1 ] ;
struct V_35 * V_106 [ V_42 + 1 ] ;
struct V_35 * V_100 [ V_160 + 1 ] ;
struct V_35 * V_47 ;
if ( F_109 ( V_44 , sizeof( struct V_128 ) , V_100 , V_160 , NULL ) < 0 )
return NULL ;
V_158 = V_100 [ V_137 ] ;
if ( V_158 == NULL )
return NULL ;
if ( F_113 ( V_106 , V_42 , F_114 ( V_158 ) ,
F_115 ( F_95 ( V_158 ) ) , NULL ) < 0 )
return NULL ;
if ( V_106 [ 1 ] == NULL )
return NULL ;
if ( F_113 ( V_159 , V_107 , F_114 ( V_106 [ 1 ] ) ,
F_95 ( V_106 [ 1 ] ) , NULL ) < 0 )
return NULL ;
V_47 = V_159 [ V_109 ] ;
return V_47 ;
}
static int
F_116 ( struct V_25 * V_26 , struct V_27 * V_28 )
{
struct V_130 * V_131 ;
unsigned char * V_96 = F_63 ( V_26 ) ;
struct V_35 * V_36 ;
struct V_71 * V_103 ;
struct V_8 V_9 ;
int V_20 = 0 ;
struct V_128 * V_129 = (struct V_128 * ) F_87 ( V_28 -> V_131 ) ;
struct V_35 * V_47 = F_112 ( V_28 -> V_131 ) ;
if ( V_47 == NULL ) {
F_117 ( L_6 ) ;
return 0 ;
}
V_103 = F_56 ( V_47 ) ;
if ( V_103 == NULL )
return 0 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 . V_13 = V_103 ;
V_131 = F_86 ( V_26 , F_107 ( V_28 -> V_26 ) . V_124 , V_28 -> V_131 -> V_142 ,
V_28 -> V_131 -> V_154 , sizeof( * V_129 ) , 0 ) ;
if ( ! V_131 )
goto V_145;
V_129 = F_87 ( V_131 ) ;
V_129 -> V_133 = V_134 ;
V_129 -> V_135 = 0 ;
V_129 -> V_136 = 0 ;
V_36 = F_15 ( V_26 , V_137 ) ;
if ( V_36 == NULL )
goto V_145;
V_20 = V_103 -> V_77 ( V_26 , V_28 , V_52 , & V_9 ) ;
if ( V_20 < 0 )
goto V_145;
if ( V_20 > 0 ) {
F_18 ( V_26 , V_36 ) ;
V_20 = V_26 -> V_139 ;
} else
F_19 ( V_26 , V_36 ) ;
V_131 -> V_138 = F_63 ( V_26 ) - V_96 ;
if ( F_107 ( V_28 -> V_26 ) . V_124 && V_20 )
V_131 -> V_147 |= V_161 ;
F_23 ( V_103 -> V_49 ) ;
return V_26 -> V_139 ;
V_145:
F_23 ( V_103 -> V_49 ) ;
F_17 ( V_26 , V_96 ) ;
return V_26 -> V_139 ;
}
static int T_3 F_118 ( void )
{
F_119 ( V_162 , V_151 , F_105 , NULL , NULL ) ;
F_119 ( V_162 , V_51 , F_105 , NULL , NULL ) ;
F_119 ( V_162 , V_52 , F_105 , F_116 ,
NULL ) ;
return 0 ;
}
