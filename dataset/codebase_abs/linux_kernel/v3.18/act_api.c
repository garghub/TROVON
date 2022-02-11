void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
F_2 ( & V_7 -> V_9 ) ;
F_3 ( & V_4 -> V_10 ) ;
F_4 ( & V_7 -> V_9 ) ;
F_5 ( & V_4 -> V_11 ,
& V_4 -> V_12 ) ;
F_6 ( V_4 , V_13 ) ;
}
int F_7 ( struct V_1 * V_2 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_15 = 0 ;
if ( V_4 ) {
if ( V_14 )
V_4 -> V_16 -- ;
else if ( V_4 -> V_16 > 0 )
return - V_17 ;
V_4 -> V_18 -- ;
if ( V_4 -> V_16 <= 0 && V_4 -> V_18 <= 0 ) {
if ( V_2 -> V_8 -> V_19 )
V_2 -> V_8 -> V_19 ( V_2 , V_14 ) ;
F_1 ( V_2 ) ;
V_15 = 1 ;
}
}
return V_15 ;
}
static int F_8 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_26 = 0 , V_27 = - 1 , V_28 = 0 , V_29 = 0 , V_30 = 0 ;
struct V_31 * V_32 ;
F_2 ( & V_7 -> V_9 ) ;
V_29 = V_23 -> args [ 0 ] ;
for ( V_28 = 0 ; V_28 < ( V_7 -> V_33 + 1 ) ; V_28 ++ ) {
V_25 = & V_7 -> V_34 [ F_9 ( V_28 , V_7 -> V_33 ) ] ;
F_10 (p, head, tcfc_head) {
V_27 ++ ;
if ( V_27 < V_29 )
continue;
V_2 -> V_5 = V_4 ;
V_2 -> V_35 = V_30 ;
V_32 = F_11 ( V_21 , V_2 -> V_35 ) ;
if ( V_32 == NULL )
goto V_36;
V_26 = F_12 ( V_21 , V_2 , 0 , 0 ) ;
if ( V_26 < 0 ) {
V_27 -- ;
F_13 ( V_21 , V_32 ) ;
goto V_37;
}
F_14 ( V_21 , V_32 ) ;
V_30 ++ ;
if ( V_30 >= V_38 )
goto V_37;
}
}
V_37:
F_4 ( & V_7 -> V_9 ) ;
if ( V_30 )
V_23 -> args [ 0 ] += V_30 ;
return V_30 ;
V_36:
F_15 ( V_21 , V_32 ) ;
goto V_37;
}
static int F_16 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_24 * V_25 ;
struct V_39 * V_40 ;
struct V_3 * V_4 ;
struct V_31 * V_32 ;
int V_28 = 0 , V_30 = 0 ;
int V_15 = - V_41 ;
V_32 = F_11 ( V_21 , V_2 -> V_35 ) ;
if ( V_32 == NULL )
goto V_36;
if ( F_17 ( V_21 , V_42 , V_2 -> V_8 -> V_43 ) )
goto V_36;
for ( V_28 = 0 ; V_28 < ( V_7 -> V_33 + 1 ) ; V_28 ++ ) {
V_25 = & V_7 -> V_34 [ F_9 ( V_28 , V_7 -> V_33 ) ] ;
F_18 (p, n, head, tcfc_head) {
V_2 -> V_5 = V_4 ;
V_15 = F_7 ( V_2 , 0 ) ;
if ( V_15 == V_44 ) {
F_19 ( V_2 -> V_8 -> V_45 ) ;
V_30 ++ ;
} else if ( V_15 < 0 )
goto V_36;
}
}
if ( F_20 ( V_21 , V_46 , V_30 ) )
goto V_36;
F_14 ( V_21 , V_32 ) ;
return V_30 ;
V_36:
F_15 ( V_21 , V_32 ) ;
return V_15 ;
}
static int F_21 ( struct V_20 * V_21 , struct V_22 * V_23 ,
int type , struct V_1 * V_2 )
{
if ( type == V_47 ) {
return F_16 ( V_21 , V_2 ) ;
} else if ( type == V_48 ) {
return F_8 ( V_21 , V_23 , V_2 ) ;
} else {
F_22 ( 1 , L_1 , type ) ;
return - V_41 ;
}
}
static struct V_3 * F_23 ( T_1 V_27 , struct V_6 * V_7 )
{
struct V_3 * V_4 = NULL ;
struct V_24 * V_25 ;
F_2 ( & V_7 -> V_9 ) ;
V_25 = & V_7 -> V_34 [ F_9 ( V_27 , V_7 -> V_33 ) ] ;
F_10 (p, head, tcfc_head)
if ( V_4 -> V_49 == V_27 )
break;
F_4 ( & V_7 -> V_9 ) ;
return V_4 ;
}
T_1 F_24 ( struct V_6 * V_7 )
{
T_1 V_50 = V_7 -> V_27 ;
do {
if ( ++ V_50 == 0 )
V_50 = 1 ;
} while ( F_23 ( V_50 , V_7 ) );
V_7 -> V_27 = V_50 ;
return V_50 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_27 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_3 * V_4 = F_23 ( V_27 , V_7 ) ;
if ( V_4 ) {
V_2 -> V_5 = V_4 ;
return 1 ;
}
return 0 ;
}
int F_26 ( T_1 V_27 , struct V_1 * V_2 , int V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_3 * V_4 = NULL ;
if ( V_27 && ( V_4 = F_23 ( V_27 , V_7 ) ) != NULL ) {
if ( V_14 )
V_4 -> V_16 ++ ;
V_4 -> V_18 ++ ;
V_2 -> V_5 = V_4 ;
return 1 ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 , struct V_31 * V_51 )
{
struct V_3 * V_52 = V_2 -> V_5 ;
if ( V_51 )
F_5 ( & V_52 -> V_11 ,
& V_52 -> V_12 ) ;
F_6 ( V_52 , V_13 ) ;
}
int F_28 ( T_1 V_27 , struct V_31 * V_51 , struct V_1 * V_2 ,
int V_53 , int V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_3 * V_4 = F_29 ( V_53 , V_54 ) ;
if ( F_30 ( ! V_4 ) )
return - V_55 ;
V_4 -> V_18 = 1 ;
if ( V_14 )
V_4 -> V_16 = 1 ;
F_31 ( & V_4 -> V_56 ) ;
F_32 ( & V_4 -> V_10 ) ;
V_4 -> V_49 = V_27 ? V_27 : F_24 ( V_7 ) ;
V_4 -> V_57 . V_58 = V_59 ;
V_4 -> V_57 . V_60 = V_59 ;
if ( V_51 ) {
int V_26 = F_33 ( & V_4 -> V_11 , NULL ,
& V_4 -> V_12 ,
& V_4 -> V_56 , V_51 ) ;
if ( V_26 ) {
F_34 ( V_4 ) ;
return V_26 ;
}
}
V_2 -> V_5 = ( void * ) V_4 ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
unsigned int V_61 = F_9 ( V_4 -> V_49 , V_7 -> V_33 ) ;
F_2 ( & V_7 -> V_9 ) ;
F_36 ( & V_4 -> V_10 , & V_7 -> V_34 [ V_61 ] ) ;
F_4 ( & V_7 -> V_9 ) ;
}
int F_37 ( struct V_62 * V_63 , unsigned int V_64 )
{
struct V_62 * V_2 ;
int V_26 ;
if ( ! V_63 -> V_63 || ! V_63 -> V_65 || ! V_63 -> V_66 )
return - V_41 ;
if ( ! V_63 -> V_67 )
V_63 -> V_67 = F_25 ;
if ( ! V_63 -> V_68 )
V_63 -> V_68 = F_21 ;
V_63 -> V_7 = F_38 ( sizeof( struct V_6 ) , V_54 ) ;
if ( ! V_63 -> V_7 )
return - V_55 ;
V_26 = F_39 ( V_63 -> V_7 , V_64 ) ;
if ( V_26 ) {
F_34 ( V_63 -> V_7 ) ;
return V_26 ;
}
F_40 ( & V_69 ) ;
F_41 (a, &act_base, head) {
if ( V_63 -> type == V_2 -> type || ( strcmp ( V_63 -> V_43 , V_2 -> V_43 ) == 0 ) ) {
F_42 ( & V_69 ) ;
F_43 ( V_63 -> V_7 ) ;
F_34 ( V_63 -> V_7 ) ;
return - V_70 ;
}
}
F_44 ( & V_63 -> V_25 , & V_71 ) ;
F_42 ( & V_69 ) ;
return 0 ;
}
int F_45 ( struct V_62 * V_63 )
{
struct V_62 * V_2 ;
int V_26 = - V_72 ;
F_40 ( & V_69 ) ;
F_41 (a, &act_base, head) {
if ( V_2 == V_63 ) {
F_46 ( & V_63 -> V_25 ) ;
F_43 ( V_63 -> V_7 ) ;
F_34 ( V_63 -> V_7 ) ;
V_26 = 0 ;
break;
}
}
F_42 ( & V_69 ) ;
return V_26 ;
}
static struct V_62 * F_47 ( char * V_43 )
{
struct V_62 * V_2 , * V_73 = NULL ;
if ( V_43 ) {
F_48 ( & V_69 ) ;
F_41 (a, &act_base, head) {
if ( strcmp ( V_43 , V_2 -> V_43 ) == 0 ) {
if ( F_49 ( V_2 -> V_45 ) )
V_73 = V_2 ;
break;
}
}
F_50 ( & V_69 ) ;
}
return V_73 ;
}
static struct V_62 * F_51 ( struct V_31 * V_43 )
{
struct V_62 * V_2 , * V_73 = NULL ;
if ( V_43 ) {
F_48 ( & V_69 ) ;
F_41 (a, &act_base, head) {
if ( F_52 ( V_43 , V_2 -> V_43 ) == 0 ) {
if ( F_49 ( V_2 -> V_45 ) )
V_73 = V_2 ;
break;
}
}
F_50 ( & V_69 ) ;
}
return V_73 ;
}
int F_53 ( struct V_20 * V_21 , const struct V_74 * V_75 ,
struct V_76 * V_73 )
{
const struct V_1 * V_2 ;
int V_15 = - 1 ;
if ( V_21 -> V_77 & V_78 ) {
V_21 -> V_77 = F_54 ( V_21 -> V_77 ) ;
V_15 = V_79 ;
goto V_80;
}
F_41 (a, actions, list) {
V_81:
V_15 = V_2 -> V_8 -> V_63 ( V_21 , V_2 , V_73 ) ;
if ( V_82 & V_21 -> V_77 ) {
V_21 -> V_77 = F_55 ( V_21 -> V_77 ) ;
V_21 -> V_77 = F_56 ( V_21 -> V_77 ) ;
}
if ( V_15 == V_83 )
goto V_81;
if ( V_15 != V_84 )
goto V_80;
}
V_80:
return V_15 ;
}
int F_57 ( struct V_74 * V_75 , int V_14 )
{
struct V_1 * V_2 , * V_85 ;
int V_15 = 0 ;
F_58 (a, tmp, actions, list) {
V_15 = F_7 ( V_2 , V_14 ) ;
if ( V_15 == V_44 )
F_19 ( V_2 -> V_8 -> V_45 ) ;
else if ( V_15 < 0 )
return V_15 ;
F_46 ( & V_2 -> V_86 ) ;
F_34 ( V_2 ) ;
}
return V_15 ;
}
int
F_59 ( struct V_20 * V_21 , struct V_1 * V_2 , int V_14 , int V_87 )
{
return V_2 -> V_8 -> V_65 ( V_21 , V_2 , V_14 , V_87 ) ;
}
int
F_12 ( struct V_20 * V_21 , struct V_1 * V_2 , int V_14 , int V_87 )
{
int V_26 = - V_41 ;
unsigned char * V_88 = F_60 ( V_21 ) ;
struct V_31 * V_32 ;
if ( F_17 ( V_21 , V_42 , V_2 -> V_8 -> V_43 ) )
goto V_36;
if ( F_61 ( V_21 , V_2 , 0 ) )
goto V_36;
V_32 = F_11 ( V_21 , V_89 ) ;
if ( V_32 == NULL )
goto V_36;
V_26 = F_59 ( V_21 , V_2 , V_14 , V_87 ) ;
if ( V_26 > 0 ) {
F_14 ( V_21 , V_32 ) ;
return V_26 ;
}
V_36:
F_13 ( V_21 , V_88 ) ;
return - 1 ;
}
int
F_62 ( struct V_20 * V_21 , struct V_74 * V_75 , int V_14 , int V_87 )
{
struct V_1 * V_2 ;
int V_26 = - V_41 ;
struct V_31 * V_32 ;
F_41 (a, actions, list) {
V_32 = F_11 ( V_21 , V_2 -> V_35 ) ;
if ( V_32 == NULL )
goto V_36;
V_26 = F_12 ( V_21 , V_2 , V_14 , V_87 ) ;
if ( V_26 < 0 )
goto V_90;
F_14 ( V_21 , V_32 ) ;
}
return 0 ;
V_36:
V_26 = - V_41 ;
V_90:
F_15 ( V_21 , V_32 ) ;
return V_26 ;
}
struct V_1 * F_63 ( struct V_91 * V_91 , struct V_31 * V_92 ,
struct V_31 * V_51 , char * V_93 , int V_94 ,
int V_14 )
{
struct V_1 * V_2 ;
struct V_62 * V_95 ;
char V_96 [ V_97 ] ;
struct V_31 * V_98 [ V_99 + 1 ] ;
struct V_31 * V_43 ;
int V_26 ;
if ( V_93 == NULL ) {
V_26 = F_64 ( V_98 , V_99 , V_92 , NULL ) ;
if ( V_26 < 0 )
goto V_100;
V_26 = - V_41 ;
V_43 = V_98 [ V_101 ] ;
if ( V_43 == NULL )
goto V_100;
if ( F_65 ( V_96 , V_43 , V_97 ) >= V_97 )
goto V_100;
} else {
V_26 = - V_41 ;
if ( F_66 ( V_96 , V_93 , V_97 ) >= V_97 )
goto V_100;
}
V_95 = F_47 ( V_96 ) ;
if ( V_95 == NULL ) {
#ifdef F_67
F_68 () ;
F_69 ( L_2 , V_96 ) ;
F_70 () ;
V_95 = F_47 ( V_96 ) ;
if ( V_95 != NULL ) {
V_26 = - V_102 ;
goto V_103;
}
#endif
V_26 = - V_72 ;
goto V_100;
}
V_26 = - V_55 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_54 ) ;
if ( V_2 == NULL )
goto V_103;
V_2 -> V_8 = V_95 ;
F_71 ( & V_2 -> V_86 ) ;
if ( V_93 == NULL )
V_26 = V_95 -> V_66 ( V_91 , V_98 [ V_104 ] , V_51 , V_2 , V_94 , V_14 ) ;
else
V_26 = V_95 -> V_66 ( V_91 , V_92 , V_51 , V_2 , V_94 , V_14 ) ;
if ( V_26 < 0 )
goto V_105;
if ( V_26 != V_106 )
F_19 ( V_95 -> V_45 ) ;
return V_2 ;
V_105:
F_34 ( V_2 ) ;
V_103:
F_19 ( V_95 -> V_45 ) ;
V_100:
return F_72 ( V_26 ) ;
}
int F_73 ( struct V_91 * V_91 , struct V_31 * V_92 ,
struct V_31 * V_51 , char * V_93 , int V_94 ,
int V_14 , struct V_74 * V_75 )
{
struct V_31 * V_98 [ V_38 + 1 ] ;
struct V_1 * V_63 ;
int V_26 ;
int V_28 ;
V_26 = F_64 ( V_98 , V_38 , V_92 , NULL ) ;
if ( V_26 < 0 )
return V_26 ;
for ( V_28 = 1 ; V_28 <= V_38 && V_98 [ V_28 ] ; V_28 ++ ) {
V_63 = F_63 ( V_91 , V_98 [ V_28 ] , V_51 , V_93 , V_94 , V_14 ) ;
if ( F_74 ( V_63 ) ) {
V_26 = F_75 ( V_63 ) ;
goto V_26;
}
V_63 -> V_35 = V_28 ;
F_44 ( & V_63 -> V_86 , V_75 ) ;
}
return 0 ;
V_26:
F_57 ( V_75 , V_14 ) ;
return V_26 ;
}
int F_61 ( struct V_20 * V_21 , struct V_1 * V_2 ,
int V_107 )
{
int V_26 = 0 ;
struct V_108 V_109 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
goto V_90;
if ( V_107 ) {
if ( V_2 -> type == V_110 )
V_26 = F_76 ( V_21 , 0 ,
V_111 , V_112 , & V_4 -> V_56 , & V_109 ) ;
else
return 0 ;
} else
V_26 = F_77 ( V_21 , V_113 ,
& V_4 -> V_56 , & V_109 ) ;
if ( V_26 < 0 )
goto V_90;
if ( F_78 ( & V_109 , NULL , & V_4 -> V_11 ) < 0 ||
F_79 ( & V_109 , & V_4 -> V_11 ,
& V_4 -> V_12 ) < 0 ||
F_80 ( & V_109 , NULL ,
& V_4 -> V_114 ,
V_4 -> V_114 . V_115 ) < 0 )
goto V_90;
if ( F_81 ( & V_109 ) < 0 )
goto V_90;
return 0 ;
V_90:
return - 1 ;
}
static int
F_82 ( struct V_20 * V_21 , struct V_74 * V_75 , T_1 V_116 , T_1 V_117 ,
T_2 V_118 , int V_119 , int V_14 , int V_87 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 ;
unsigned char * V_88 = F_60 ( V_21 ) ;
struct V_31 * V_32 ;
V_123 = F_83 ( V_21 , V_116 , V_117 , V_119 , sizeof( * V_121 ) , V_118 ) ;
if ( ! V_123 )
goto V_124;
V_121 = F_84 ( V_123 ) ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_32 = F_11 ( V_21 , V_129 ) ;
if ( V_32 == NULL )
goto V_124;
if ( F_62 ( V_21 , V_75 , V_14 , V_87 ) < 0 )
goto V_124;
F_14 ( V_21 , V_32 ) ;
V_123 -> V_130 = F_60 ( V_21 ) - V_88 ;
return V_21 -> V_131 ;
V_124:
F_13 ( V_21 , V_88 ) ;
return - 1 ;
}
static int
F_85 ( struct V_91 * V_91 , T_1 V_116 , struct V_122 * V_40 ,
struct V_74 * V_75 , int V_119 )
{
struct V_20 * V_21 ;
V_21 = F_86 ( V_132 , V_54 ) ;
if ( ! V_21 )
return - V_133 ;
if ( F_82 ( V_21 , V_75 , V_116 , V_40 -> V_134 , 0 , V_119 , 0 , 0 ) <= 0 ) {
F_87 ( V_21 ) ;
return - V_41 ;
}
return F_88 ( V_21 , V_91 , V_116 ) ;
}
static struct V_1 * F_89 ( int V_28 )
{
struct V_1 * V_63 ;
V_63 = F_29 ( sizeof( * V_63 ) , V_54 ) ;
if ( V_63 == NULL ) {
F_90 ( L_3 ) ;
return NULL ;
}
V_63 -> V_35 = V_28 ;
F_71 ( & V_63 -> V_86 ) ;
return V_63 ;
}
static struct V_1 *
F_91 ( struct V_31 * V_92 , struct V_122 * V_40 , T_1 V_116 )
{
struct V_31 * V_98 [ V_99 + 1 ] ;
struct V_1 * V_2 ;
int V_27 ;
int V_26 ;
V_26 = F_64 ( V_98 , V_99 , V_92 , NULL ) ;
if ( V_26 < 0 )
goto V_100;
V_26 = - V_41 ;
if ( V_98 [ V_135 ] == NULL ||
F_92 ( V_98 [ V_135 ] ) < sizeof( V_27 ) )
goto V_100;
V_27 = F_93 ( V_98 [ V_135 ] ) ;
V_26 = - V_55 ;
V_2 = F_89 ( 0 ) ;
if ( V_2 == NULL )
goto V_100;
V_26 = - V_41 ;
V_2 -> V_8 = F_51 ( V_98 [ V_101 ] ) ;
if ( V_2 -> V_8 == NULL )
goto V_105;
V_26 = - V_72 ;
if ( V_2 -> V_8 -> V_67 ( V_2 , V_27 ) == 0 )
goto V_103;
F_19 ( V_2 -> V_8 -> V_45 ) ;
return V_2 ;
V_103:
F_19 ( V_2 -> V_8 -> V_45 ) ;
V_105:
F_34 ( V_2 ) ;
V_100:
return F_72 ( V_26 ) ;
}
static void F_94 ( struct V_74 * V_75 )
{
struct V_1 * V_2 , * V_85 ;
F_58 (a, tmp, actions, list) {
F_46 ( & V_2 -> V_86 ) ;
F_34 ( V_2 ) ;
}
}
static int F_95 ( struct V_91 * V_91 , struct V_31 * V_92 ,
struct V_122 * V_40 , T_1 V_116 )
{
struct V_20 * V_21 ;
unsigned char * V_88 ;
struct V_122 * V_123 ;
struct V_120 * V_121 ;
struct V_22 V_136 ;
struct V_31 * V_32 ;
struct V_31 * V_98 [ V_99 + 1 ] ;
struct V_31 * V_43 ;
struct V_1 V_2 ;
int V_26 = - V_55 ;
V_21 = F_86 ( V_132 , V_54 ) ;
if ( ! V_21 ) {
F_90 ( L_4 ) ;
return V_26 ;
}
V_88 = F_60 ( V_21 ) ;
V_26 = F_64 ( V_98 , V_99 , V_92 , NULL ) ;
if ( V_26 < 0 )
goto V_100;
V_26 = - V_41 ;
V_43 = V_98 [ V_101 ] ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
F_71 ( & V_2 . V_86 ) ;
V_2 . V_8 = F_51 ( V_43 ) ;
if ( V_2 . V_8 == NULL )
goto V_100;
V_123 = F_83 ( V_21 , V_116 , V_40 -> V_134 , V_47 , sizeof( * V_121 ) , 0 ) ;
if ( ! V_123 )
goto V_137;
V_121 = F_84 ( V_123 ) ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_32 = F_11 ( V_21 , V_129 ) ;
if ( V_32 == NULL )
goto V_137;
V_26 = V_2 . V_8 -> V_68 ( V_21 , & V_136 , V_47 , & V_2 ) ;
if ( V_26 < 0 )
goto V_137;
if ( V_26 == 0 )
goto V_138;
F_14 ( V_21 , V_32 ) ;
V_123 -> V_130 = F_60 ( V_21 ) - V_88 ;
V_123 -> V_139 |= V_140 ;
F_19 ( V_2 . V_8 -> V_45 ) ;
V_26 = F_96 ( V_21 , V_91 , V_116 , V_141 ,
V_40 -> V_139 & V_142 ) ;
if ( V_26 > 0 )
return 0 ;
return V_26 ;
V_137:
F_19 ( V_2 . V_8 -> V_45 ) ;
V_100:
V_138:
F_87 ( V_21 ) ;
return V_26 ;
}
static int
F_97 ( struct V_91 * V_91 , struct V_122 * V_40 , struct V_74 * V_75 ,
T_1 V_116 )
{
int V_15 ;
struct V_20 * V_21 ;
V_21 = F_86 ( V_132 , V_54 ) ;
if ( ! V_21 )
return - V_133 ;
if ( F_82 ( V_21 , V_75 , V_116 , V_40 -> V_134 , 0 , V_47 ,
0 , 1 ) <= 0 ) {
F_87 ( V_21 ) ;
return - V_41 ;
}
V_15 = F_57 ( V_75 , 0 ) ;
if ( V_15 < 0 ) {
F_87 ( V_21 ) ;
return V_15 ;
}
V_15 = F_96 ( V_21 , V_91 , V_116 , V_141 ,
V_40 -> V_139 & V_142 ) ;
if ( V_15 > 0 )
return 0 ;
return V_15 ;
}
static int
F_98 ( struct V_91 * V_91 , struct V_31 * V_92 , struct V_122 * V_40 ,
T_1 V_116 , int V_119 )
{
int V_28 , V_15 ;
struct V_31 * V_98 [ V_38 + 1 ] ;
struct V_1 * V_63 ;
F_99 ( V_75 ) ;
V_15 = F_64 ( V_98 , V_38 , V_92 , NULL ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_119 == V_47 && V_40 -> V_139 & V_140 ) {
if ( V_98 [ 1 ] != NULL )
return F_95 ( V_91 , V_98 [ 1 ] , V_40 , V_116 ) ;
else
return - V_41 ;
}
for ( V_28 = 1 ; V_28 <= V_38 && V_98 [ V_28 ] ; V_28 ++ ) {
V_63 = F_91 ( V_98 [ V_28 ] , V_40 , V_116 ) ;
if ( F_74 ( V_63 ) ) {
V_15 = F_75 ( V_63 ) ;
goto V_26;
}
V_63 -> V_35 = V_28 ;
F_44 ( & V_63 -> V_86 , & V_75 ) ;
}
if ( V_119 == V_48 )
V_15 = F_85 ( V_91 , V_116 , V_40 , & V_75 , V_119 ) ;
else {
V_15 = F_97 ( V_91 , V_40 , & V_75 , V_116 ) ;
if ( V_15 )
goto V_26;
return V_15 ;
}
V_26:
F_94 ( & V_75 ) ;
return V_15 ;
}
static int
F_100 ( struct V_91 * V_91 , struct V_122 * V_40 , struct V_74 * V_75 ,
T_1 V_116 )
{
struct V_20 * V_21 ;
int V_26 = 0 ;
V_21 = F_86 ( V_132 , V_54 ) ;
if ( ! V_21 )
return - V_133 ;
if ( F_82 ( V_21 , V_75 , V_116 , V_40 -> V_134 , V_40 -> V_139 ,
V_143 , 0 , 0 ) <= 0 ) {
F_87 ( V_21 ) ;
return - V_41 ;
}
V_26 = F_96 ( V_21 , V_91 , V_116 , V_141 ,
V_40 -> V_139 & V_142 ) ;
if ( V_26 > 0 )
V_26 = 0 ;
return V_26 ;
}
static int
F_101 ( struct V_91 * V_91 , struct V_31 * V_92 , struct V_122 * V_40 ,
T_1 V_116 , int V_94 )
{
int V_15 = 0 ;
F_99 ( V_75 ) ;
V_15 = F_73 ( V_91 , V_92 , NULL , NULL , V_94 , 0 , & V_75 ) ;
if ( V_15 )
goto V_37;
V_15 = F_100 ( V_91 , V_40 , & V_75 , V_116 ) ;
F_94 ( & V_75 ) ;
V_37:
return V_15 ;
}
static int F_102 ( struct V_20 * V_21 , struct V_122 * V_40 )
{
struct V_91 * V_91 = F_103 ( V_21 -> V_144 ) ;
struct V_31 * V_145 [ V_99 + 1 ] ;
T_1 V_116 = V_21 ? F_104 ( V_21 ) . V_116 : 0 ;
int V_15 = 0 , V_94 = 0 ;
if ( ( V_40 -> V_146 != V_48 ) && ! F_105 ( V_21 , V_147 ) )
return - V_17 ;
V_15 = F_106 ( V_40 , sizeof( struct V_120 ) , V_145 , V_99 , NULL ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_145 [ V_129 ] == NULL ) {
F_107 ( L_5 ) ;
return - V_41 ;
}
switch ( V_40 -> V_146 ) {
case V_143 :
if ( V_40 -> V_139 & V_148 )
V_94 = 1 ;
V_149:
V_15 = F_101 ( V_91 , V_145 [ V_129 ] , V_40 , V_116 , V_94 ) ;
if ( V_15 == - V_102 )
goto V_149;
break;
case V_47 :
V_15 = F_98 ( V_91 , V_145 [ V_129 ] , V_40 ,
V_116 , V_47 ) ;
break;
case V_48 :
V_15 = F_98 ( V_91 , V_145 [ V_129 ] , V_40 ,
V_116 , V_48 ) ;
break;
default:
F_108 () ;
}
return V_15 ;
}
static struct V_31 *
F_109 ( const struct V_122 * V_40 )
{
struct V_31 * V_150 , * V_151 [ V_99 + 1 ] ;
struct V_31 * V_98 [ V_38 + 1 ] ;
struct V_31 * V_92 [ V_152 + 1 ] ;
struct V_31 * V_43 ;
if ( F_106 ( V_40 , sizeof( struct V_120 ) , V_92 , V_152 , NULL ) < 0 )
return NULL ;
V_150 = V_92 [ V_129 ] ;
if ( V_150 == NULL )
return NULL ;
if ( F_110 ( V_98 , V_38 , F_111 ( V_150 ) ,
F_112 ( F_92 ( V_150 ) ) , NULL ) < 0 )
return NULL ;
if ( V_98 [ 1 ] == NULL )
return NULL ;
if ( F_110 ( V_151 , V_99 , F_111 ( V_98 [ 1 ] ) ,
F_92 ( V_98 [ 1 ] ) , NULL ) < 0 )
return NULL ;
V_43 = V_151 [ V_101 ] ;
return V_43 ;
}
static int
F_113 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_122 * V_123 ;
unsigned char * V_88 = F_60 ( V_21 ) ;
struct V_31 * V_32 ;
struct V_62 * V_95 ;
struct V_1 V_2 ;
int V_15 = 0 ;
struct V_120 * V_121 = (struct V_120 * ) F_84 ( V_23 -> V_123 ) ;
struct V_31 * V_43 = F_109 ( V_23 -> V_123 ) ;
if ( V_43 == NULL ) {
F_114 ( L_6 ) ;
return 0 ;
}
V_95 = F_51 ( V_43 ) ;
if ( V_95 == NULL )
return 0 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 . V_8 = V_95 ;
V_123 = F_83 ( V_21 , F_104 ( V_23 -> V_21 ) . V_116 , V_23 -> V_123 -> V_134 ,
V_23 -> V_123 -> V_146 , sizeof( * V_121 ) , 0 ) ;
if ( ! V_123 )
goto V_137;
V_121 = F_84 ( V_123 ) ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_32 = F_11 ( V_21 , V_129 ) ;
if ( V_32 == NULL )
goto V_137;
V_15 = V_95 -> V_68 ( V_21 , V_23 , V_48 , & V_2 ) ;
if ( V_15 < 0 )
goto V_137;
if ( V_15 > 0 ) {
F_14 ( V_21 , V_32 ) ;
V_15 = V_21 -> V_131 ;
} else
F_15 ( V_21 , V_32 ) ;
V_123 -> V_130 = F_60 ( V_21 ) - V_88 ;
if ( F_104 ( V_23 -> V_21 ) . V_116 && V_15 )
V_123 -> V_139 |= V_153 ;
F_19 ( V_95 -> V_45 ) ;
return V_21 -> V_131 ;
V_137:
F_19 ( V_95 -> V_45 ) ;
F_13 ( V_21 , V_88 ) ;
return V_21 -> V_131 ;
}
static int T_3 F_115 ( void )
{
F_116 ( V_154 , V_143 , F_102 , NULL , NULL ) ;
F_116 ( V_154 , V_47 , F_102 , NULL , NULL ) ;
F_116 ( V_154 , V_48 , F_102 , F_113 ,
NULL ) ;
return 0 ;
}
