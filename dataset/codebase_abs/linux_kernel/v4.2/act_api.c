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
int F_7 ( struct V_1 * V_2 , bool V_14 , bool V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_16 = 0 ;
if ( V_4 ) {
if ( V_14 )
V_4 -> V_17 -- ;
else if ( V_15 && V_4 -> V_17 > 0 )
return - V_18 ;
V_4 -> V_19 -- ;
if ( V_4 -> V_17 <= 0 && V_4 -> V_19 <= 0 ) {
if ( V_2 -> V_8 -> V_20 )
V_2 -> V_8 -> V_20 ( V_2 , V_14 ) ;
F_1 ( V_2 ) ;
V_16 = 1 ;
}
}
return V_16 ;
}
static int F_8 ( struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
int V_27 = 0 , V_28 = - 1 , V_29 = 0 , V_30 = 0 , V_31 = 0 ;
struct V_32 * V_33 ;
F_2 ( & V_7 -> V_9 ) ;
V_30 = V_24 -> args [ 0 ] ;
for ( V_29 = 0 ; V_29 < ( V_7 -> V_34 + 1 ) ; V_29 ++ ) {
V_26 = & V_7 -> V_35 [ F_9 ( V_29 , V_7 -> V_34 ) ] ;
F_10 (p, head, tcfc_head) {
V_28 ++ ;
if ( V_28 < V_30 )
continue;
V_2 -> V_5 = V_4 ;
V_2 -> V_36 = V_31 ;
V_33 = F_11 ( V_22 , V_2 -> V_36 ) ;
if ( V_33 == NULL )
goto V_37;
V_27 = F_12 ( V_22 , V_2 , 0 , 0 ) ;
if ( V_27 < 0 ) {
V_28 -- ;
F_13 ( V_22 , V_33 ) ;
goto V_38;
}
F_14 ( V_22 , V_33 ) ;
V_31 ++ ;
if ( V_31 >= V_39 )
goto V_38;
}
}
V_38:
F_4 ( & V_7 -> V_9 ) ;
if ( V_31 )
V_24 -> args [ 0 ] += V_31 ;
return V_31 ;
V_37:
F_15 ( V_22 , V_33 ) ;
goto V_38;
}
static int F_16 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_25 * V_26 ;
struct V_40 * V_41 ;
struct V_3 * V_4 ;
struct V_32 * V_33 ;
int V_29 = 0 , V_31 = 0 ;
int V_16 = - V_42 ;
V_33 = F_11 ( V_22 , V_2 -> V_36 ) ;
if ( V_33 == NULL )
goto V_37;
if ( F_17 ( V_22 , V_43 , V_2 -> V_8 -> V_44 ) )
goto V_37;
for ( V_29 = 0 ; V_29 < ( V_7 -> V_34 + 1 ) ; V_29 ++ ) {
V_26 = & V_7 -> V_35 [ F_9 ( V_29 , V_7 -> V_34 ) ] ;
F_18 (p, n, head, tcfc_head) {
V_2 -> V_5 = V_4 ;
V_16 = F_7 ( V_2 , false , true ) ;
if ( V_16 == V_45 ) {
F_19 ( V_2 -> V_8 -> V_46 ) ;
V_31 ++ ;
} else if ( V_16 < 0 )
goto V_37;
}
}
if ( F_20 ( V_22 , V_47 , V_31 ) )
goto V_37;
F_14 ( V_22 , V_33 ) ;
return V_31 ;
V_37:
F_15 ( V_22 , V_33 ) ;
return V_16 ;
}
static int F_21 ( struct V_21 * V_22 , struct V_23 * V_24 ,
int type , struct V_1 * V_2 )
{
if ( type == V_48 ) {
return F_16 ( V_22 , V_2 ) ;
} else if ( type == V_49 ) {
return F_8 ( V_22 , V_24 , V_2 ) ;
} else {
F_22 ( 1 , L_1 , type ) ;
return - V_42 ;
}
}
static struct V_3 * F_23 ( T_1 V_28 , struct V_6 * V_7 )
{
struct V_3 * V_4 = NULL ;
struct V_25 * V_26 ;
F_2 ( & V_7 -> V_9 ) ;
V_26 = & V_7 -> V_35 [ F_9 ( V_28 , V_7 -> V_34 ) ] ;
F_10 (p, head, tcfc_head)
if ( V_4 -> V_50 == V_28 )
break;
F_4 ( & V_7 -> V_9 ) ;
return V_4 ;
}
T_1 F_24 ( struct V_6 * V_7 )
{
T_1 V_51 = V_7 -> V_28 ;
do {
if ( ++ V_51 == 0 )
V_51 = 1 ;
} while ( F_23 ( V_51 , V_7 ) );
V_7 -> V_28 = V_51 ;
return V_51 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_3 * V_4 = F_23 ( V_28 , V_7 ) ;
if ( V_4 ) {
V_2 -> V_5 = V_4 ;
return 1 ;
}
return 0 ;
}
int F_26 ( T_1 V_28 , struct V_1 * V_2 , int V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_3 * V_4 = NULL ;
if ( V_28 && ( V_4 = F_23 ( V_28 , V_7 ) ) != NULL ) {
if ( V_14 )
V_4 -> V_17 ++ ;
V_4 -> V_19 ++ ;
V_2 -> V_5 = V_4 ;
return 1 ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 , struct V_32 * V_52 )
{
struct V_3 * V_53 = V_2 -> V_5 ;
if ( V_52 )
F_5 ( & V_53 -> V_11 ,
& V_53 -> V_12 ) ;
F_6 ( V_53 , V_13 ) ;
}
int F_28 ( T_1 V_28 , struct V_32 * V_52 , struct V_1 * V_2 ,
int V_54 , int V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
struct V_3 * V_4 = F_29 ( V_54 , V_55 ) ;
if ( F_30 ( ! V_4 ) )
return - V_56 ;
V_4 -> V_19 = 1 ;
if ( V_14 )
V_4 -> V_17 = 1 ;
F_31 ( & V_4 -> V_57 ) ;
F_32 ( & V_4 -> V_10 ) ;
V_4 -> V_50 = V_28 ? V_28 : F_24 ( V_7 ) ;
V_4 -> V_58 . V_59 = V_60 ;
V_4 -> V_58 . V_61 = V_60 ;
if ( V_52 ) {
int V_27 = F_33 ( & V_4 -> V_11 , NULL ,
& V_4 -> V_12 ,
& V_4 -> V_57 , V_52 ) ;
if ( V_27 ) {
F_34 ( V_4 ) ;
return V_27 ;
}
}
V_2 -> V_5 = ( void * ) V_4 ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
unsigned int V_62 = F_9 ( V_4 -> V_50 , V_7 -> V_34 ) ;
F_2 ( & V_7 -> V_9 ) ;
F_36 ( & V_4 -> V_10 , & V_7 -> V_35 [ V_62 ] ) ;
F_4 ( & V_7 -> V_9 ) ;
}
int F_37 ( struct V_63 * V_64 , unsigned int V_65 )
{
struct V_63 * V_2 ;
int V_27 ;
if ( ! V_64 -> V_64 || ! V_64 -> V_66 || ! V_64 -> V_67 )
return - V_42 ;
if ( ! V_64 -> V_68 )
V_64 -> V_68 = F_25 ;
if ( ! V_64 -> V_69 )
V_64 -> V_69 = F_21 ;
V_64 -> V_7 = F_38 ( sizeof( struct V_6 ) , V_55 ) ;
if ( ! V_64 -> V_7 )
return - V_56 ;
V_27 = F_39 ( V_64 -> V_7 , V_65 ) ;
if ( V_27 ) {
F_34 ( V_64 -> V_7 ) ;
return V_27 ;
}
F_40 ( & V_70 ) ;
F_41 (a, &act_base, head) {
if ( V_64 -> type == V_2 -> type || ( strcmp ( V_64 -> V_44 , V_2 -> V_44 ) == 0 ) ) {
F_42 ( & V_70 ) ;
F_43 ( V_64 -> V_7 ) ;
F_34 ( V_64 -> V_7 ) ;
return - V_71 ;
}
}
F_44 ( & V_64 -> V_26 , & V_72 ) ;
F_42 ( & V_70 ) ;
return 0 ;
}
int F_45 ( struct V_63 * V_64 )
{
struct V_63 * V_2 ;
int V_27 = - V_73 ;
F_40 ( & V_70 ) ;
F_41 (a, &act_base, head) {
if ( V_2 == V_64 ) {
F_46 ( & V_64 -> V_26 ) ;
F_43 ( V_64 -> V_7 ) ;
F_34 ( V_64 -> V_7 ) ;
V_27 = 0 ;
break;
}
}
F_42 ( & V_70 ) ;
return V_27 ;
}
static struct V_63 * F_47 ( char * V_44 )
{
struct V_63 * V_2 , * V_74 = NULL ;
if ( V_44 ) {
F_48 ( & V_70 ) ;
F_41 (a, &act_base, head) {
if ( strcmp ( V_44 , V_2 -> V_44 ) == 0 ) {
if ( F_49 ( V_2 -> V_46 ) )
V_74 = V_2 ;
break;
}
}
F_50 ( & V_70 ) ;
}
return V_74 ;
}
static struct V_63 * F_51 ( struct V_32 * V_44 )
{
struct V_63 * V_2 , * V_74 = NULL ;
if ( V_44 ) {
F_48 ( & V_70 ) ;
F_41 (a, &act_base, head) {
if ( F_52 ( V_44 , V_2 -> V_44 ) == 0 ) {
if ( F_49 ( V_2 -> V_46 ) )
V_74 = V_2 ;
break;
}
}
F_50 ( & V_70 ) ;
}
return V_74 ;
}
int F_53 ( struct V_21 * V_22 , const struct V_75 * V_76 ,
struct V_77 * V_74 )
{
const struct V_1 * V_2 ;
int V_16 = - 1 ;
if ( V_22 -> V_78 & V_79 ) {
V_22 -> V_78 = F_54 ( V_22 -> V_78 ) ;
V_16 = V_80 ;
goto V_81;
}
F_41 (a, actions, list) {
V_82:
V_16 = V_2 -> V_8 -> V_64 ( V_22 , V_2 , V_74 ) ;
if ( V_16 == V_83 )
goto V_82;
if ( V_16 != V_84 )
goto V_81;
}
V_81:
return V_16 ;
}
int F_55 ( struct V_75 * V_76 , int V_14 )
{
struct V_1 * V_2 , * V_85 ;
int V_16 = 0 ;
F_56 (a, tmp, actions, list) {
V_16 = F_7 ( V_2 , V_14 , true ) ;
if ( V_16 == V_45 )
F_19 ( V_2 -> V_8 -> V_46 ) ;
else if ( V_16 < 0 )
return V_16 ;
F_46 ( & V_2 -> V_86 ) ;
F_34 ( V_2 ) ;
}
return V_16 ;
}
int
F_57 ( struct V_21 * V_22 , struct V_1 * V_2 , int V_14 , int V_87 )
{
return V_2 -> V_8 -> V_66 ( V_22 , V_2 , V_14 , V_87 ) ;
}
int
F_12 ( struct V_21 * V_22 , struct V_1 * V_2 , int V_14 , int V_87 )
{
int V_27 = - V_42 ;
unsigned char * V_88 = F_58 ( V_22 ) ;
struct V_32 * V_33 ;
if ( F_17 ( V_22 , V_43 , V_2 -> V_8 -> V_44 ) )
goto V_37;
if ( F_59 ( V_22 , V_2 , 0 ) )
goto V_37;
V_33 = F_11 ( V_22 , V_89 ) ;
if ( V_33 == NULL )
goto V_37;
V_27 = F_57 ( V_22 , V_2 , V_14 , V_87 ) ;
if ( V_27 > 0 ) {
F_14 ( V_22 , V_33 ) ;
return V_27 ;
}
V_37:
F_13 ( V_22 , V_88 ) ;
return - 1 ;
}
int
F_60 ( struct V_21 * V_22 , struct V_75 * V_76 , int V_14 , int V_87 )
{
struct V_1 * V_2 ;
int V_27 = - V_42 ;
struct V_32 * V_33 ;
F_41 (a, actions, list) {
V_33 = F_11 ( V_22 , V_2 -> V_36 ) ;
if ( V_33 == NULL )
goto V_37;
V_27 = F_12 ( V_22 , V_2 , V_14 , V_87 ) ;
if ( V_27 < 0 )
goto V_90;
F_14 ( V_22 , V_33 ) ;
}
return 0 ;
V_37:
V_27 = - V_42 ;
V_90:
F_15 ( V_22 , V_33 ) ;
return V_27 ;
}
struct V_1 * F_61 ( struct V_91 * V_91 , struct V_32 * V_92 ,
struct V_32 * V_52 , char * V_93 , int V_94 ,
int V_14 )
{
struct V_1 * V_2 ;
struct V_63 * V_95 ;
char V_96 [ V_97 ] ;
struct V_32 * V_98 [ V_99 + 1 ] ;
struct V_32 * V_44 ;
int V_27 ;
if ( V_93 == NULL ) {
V_27 = F_62 ( V_98 , V_99 , V_92 , NULL ) ;
if ( V_27 < 0 )
goto V_100;
V_27 = - V_42 ;
V_44 = V_98 [ V_101 ] ;
if ( V_44 == NULL )
goto V_100;
if ( F_63 ( V_96 , V_44 , V_97 ) >= V_97 )
goto V_100;
} else {
V_27 = - V_42 ;
if ( F_64 ( V_96 , V_93 , V_97 ) >= V_97 )
goto V_100;
}
V_95 = F_47 ( V_96 ) ;
if ( V_95 == NULL ) {
#ifdef F_65
F_66 () ;
F_67 ( L_2 , V_96 ) ;
F_68 () ;
V_95 = F_47 ( V_96 ) ;
if ( V_95 != NULL ) {
V_27 = - V_102 ;
goto V_103;
}
#endif
V_27 = - V_73 ;
goto V_100;
}
V_27 = - V_56 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_55 ) ;
if ( V_2 == NULL )
goto V_103;
V_2 -> V_8 = V_95 ;
F_69 ( & V_2 -> V_86 ) ;
if ( V_93 == NULL )
V_27 = V_95 -> V_67 ( V_91 , V_98 [ V_104 ] , V_52 , V_2 , V_94 , V_14 ) ;
else
V_27 = V_95 -> V_67 ( V_91 , V_92 , V_52 , V_2 , V_94 , V_14 ) ;
if ( V_27 < 0 )
goto V_105;
if ( V_27 != V_106 )
F_19 ( V_95 -> V_46 ) ;
return V_2 ;
V_105:
F_34 ( V_2 ) ;
V_103:
F_19 ( V_95 -> V_46 ) ;
V_100:
return F_70 ( V_27 ) ;
}
int F_71 ( struct V_91 * V_91 , struct V_32 * V_92 ,
struct V_32 * V_52 , char * V_93 , int V_94 ,
int V_14 , struct V_75 * V_76 )
{
struct V_32 * V_98 [ V_39 + 1 ] ;
struct V_1 * V_64 ;
int V_27 ;
int V_29 ;
V_27 = F_62 ( V_98 , V_39 , V_92 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
for ( V_29 = 1 ; V_29 <= V_39 && V_98 [ V_29 ] ; V_29 ++ ) {
V_64 = F_61 ( V_91 , V_98 [ V_29 ] , V_52 , V_93 , V_94 , V_14 ) ;
if ( F_72 ( V_64 ) ) {
V_27 = F_73 ( V_64 ) ;
goto V_27;
}
V_64 -> V_36 = V_29 ;
F_44 ( & V_64 -> V_86 , V_76 ) ;
}
return 0 ;
V_27:
F_55 ( V_76 , V_14 ) ;
return V_27 ;
}
int F_59 ( struct V_21 * V_22 , struct V_1 * V_2 ,
int V_107 )
{
int V_27 = 0 ;
struct V_108 V_109 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
goto V_90;
if ( V_107 ) {
if ( V_2 -> type == V_110 )
V_27 = F_74 ( V_22 , 0 ,
V_111 , V_112 , & V_4 -> V_57 , & V_109 ) ;
else
return 0 ;
} else
V_27 = F_75 ( V_22 , V_113 ,
& V_4 -> V_57 , & V_109 ) ;
if ( V_27 < 0 )
goto V_90;
if ( F_76 ( & V_109 , NULL , & V_4 -> V_11 ) < 0 ||
F_77 ( & V_109 , & V_4 -> V_11 ,
& V_4 -> V_12 ) < 0 ||
F_78 ( & V_109 , NULL ,
& V_4 -> V_114 ,
V_4 -> V_114 . V_115 ) < 0 )
goto V_90;
if ( F_79 ( & V_109 ) < 0 )
goto V_90;
return 0 ;
V_90:
return - 1 ;
}
static int
F_80 ( struct V_21 * V_22 , struct V_75 * V_76 , T_1 V_116 , T_1 V_117 ,
T_2 V_118 , int V_119 , int V_14 , int V_87 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 ;
unsigned char * V_88 = F_58 ( V_22 ) ;
struct V_32 * V_33 ;
V_123 = F_81 ( V_22 , V_116 , V_117 , V_119 , sizeof( * V_121 ) , V_118 ) ;
if ( ! V_123 )
goto V_124;
V_121 = F_82 ( V_123 ) ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_33 = F_11 ( V_22 , V_129 ) ;
if ( V_33 == NULL )
goto V_124;
if ( F_60 ( V_22 , V_76 , V_14 , V_87 ) < 0 )
goto V_124;
F_14 ( V_22 , V_33 ) ;
V_123 -> V_130 = F_58 ( V_22 ) - V_88 ;
return V_22 -> V_131 ;
V_124:
F_13 ( V_22 , V_88 ) ;
return - 1 ;
}
static int
F_83 ( struct V_91 * V_91 , T_1 V_116 , struct V_122 * V_41 ,
struct V_75 * V_76 , int V_119 )
{
struct V_21 * V_22 ;
V_22 = F_84 ( V_132 , V_55 ) ;
if ( ! V_22 )
return - V_133 ;
if ( F_80 ( V_22 , V_76 , V_116 , V_41 -> V_134 , 0 , V_119 , 0 , 0 ) <= 0 ) {
F_85 ( V_22 ) ;
return - V_42 ;
}
return F_86 ( V_22 , V_91 , V_116 ) ;
}
static struct V_1 * F_87 ( int V_29 )
{
struct V_1 * V_64 ;
V_64 = F_29 ( sizeof( * V_64 ) , V_55 ) ;
if ( V_64 == NULL ) {
F_88 ( L_3 ) ;
return NULL ;
}
V_64 -> V_36 = V_29 ;
F_69 ( & V_64 -> V_86 ) ;
return V_64 ;
}
static struct V_1 *
F_89 ( struct V_32 * V_92 , struct V_122 * V_41 , T_1 V_116 )
{
struct V_32 * V_98 [ V_99 + 1 ] ;
struct V_1 * V_2 ;
int V_28 ;
int V_27 ;
V_27 = F_62 ( V_98 , V_99 , V_92 , NULL ) ;
if ( V_27 < 0 )
goto V_100;
V_27 = - V_42 ;
if ( V_98 [ V_135 ] == NULL ||
F_90 ( V_98 [ V_135 ] ) < sizeof( V_28 ) )
goto V_100;
V_28 = F_91 ( V_98 [ V_135 ] ) ;
V_27 = - V_56 ;
V_2 = F_87 ( 0 ) ;
if ( V_2 == NULL )
goto V_100;
V_27 = - V_42 ;
V_2 -> V_8 = F_51 ( V_98 [ V_101 ] ) ;
if ( V_2 -> V_8 == NULL )
goto V_105;
V_27 = - V_73 ;
if ( V_2 -> V_8 -> V_68 ( V_2 , V_28 ) == 0 )
goto V_103;
F_19 ( V_2 -> V_8 -> V_46 ) ;
return V_2 ;
V_103:
F_19 ( V_2 -> V_8 -> V_46 ) ;
V_105:
F_34 ( V_2 ) ;
V_100:
return F_70 ( V_27 ) ;
}
static void F_92 ( struct V_75 * V_76 )
{
struct V_1 * V_2 , * V_85 ;
F_56 (a, tmp, actions, list) {
F_46 ( & V_2 -> V_86 ) ;
F_34 ( V_2 ) ;
}
}
static int F_93 ( struct V_91 * V_91 , struct V_32 * V_92 ,
struct V_122 * V_41 , T_1 V_116 )
{
struct V_21 * V_22 ;
unsigned char * V_88 ;
struct V_122 * V_123 ;
struct V_120 * V_121 ;
struct V_23 V_136 ;
struct V_32 * V_33 ;
struct V_32 * V_98 [ V_99 + 1 ] ;
struct V_32 * V_44 ;
struct V_1 V_2 ;
int V_27 = - V_56 ;
V_22 = F_84 ( V_132 , V_55 ) ;
if ( ! V_22 ) {
F_88 ( L_4 ) ;
return V_27 ;
}
V_88 = F_58 ( V_22 ) ;
V_27 = F_62 ( V_98 , V_99 , V_92 , NULL ) ;
if ( V_27 < 0 )
goto V_100;
V_27 = - V_42 ;
V_44 = V_98 [ V_101 ] ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
F_69 ( & V_2 . V_86 ) ;
V_2 . V_8 = F_51 ( V_44 ) ;
if ( V_2 . V_8 == NULL )
goto V_100;
V_123 = F_81 ( V_22 , V_116 , V_41 -> V_134 , V_48 , sizeof( * V_121 ) , 0 ) ;
if ( ! V_123 )
goto V_137;
V_121 = F_82 ( V_123 ) ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_33 = F_11 ( V_22 , V_129 ) ;
if ( V_33 == NULL )
goto V_137;
V_27 = V_2 . V_8 -> V_69 ( V_22 , & V_136 , V_48 , & V_2 ) ;
if ( V_27 < 0 )
goto V_137;
if ( V_27 == 0 )
goto V_138;
F_14 ( V_22 , V_33 ) ;
V_123 -> V_130 = F_58 ( V_22 ) - V_88 ;
V_123 -> V_139 |= V_140 ;
F_19 ( V_2 . V_8 -> V_46 ) ;
V_27 = F_94 ( V_22 , V_91 , V_116 , V_141 ,
V_41 -> V_139 & V_142 ) ;
if ( V_27 > 0 )
return 0 ;
return V_27 ;
V_137:
F_19 ( V_2 . V_8 -> V_46 ) ;
V_100:
V_138:
F_85 ( V_22 ) ;
return V_27 ;
}
static int
F_95 ( struct V_91 * V_91 , struct V_122 * V_41 , struct V_75 * V_76 ,
T_1 V_116 )
{
int V_16 ;
struct V_21 * V_22 ;
V_22 = F_84 ( V_132 , V_55 ) ;
if ( ! V_22 )
return - V_133 ;
if ( F_80 ( V_22 , V_76 , V_116 , V_41 -> V_134 , 0 , V_48 ,
0 , 1 ) <= 0 ) {
F_85 ( V_22 ) ;
return - V_42 ;
}
V_16 = F_55 ( V_76 , 0 ) ;
if ( V_16 < 0 ) {
F_85 ( V_22 ) ;
return V_16 ;
}
V_16 = F_94 ( V_22 , V_91 , V_116 , V_141 ,
V_41 -> V_139 & V_142 ) ;
if ( V_16 > 0 )
return 0 ;
return V_16 ;
}
static int
F_96 ( struct V_91 * V_91 , struct V_32 * V_92 , struct V_122 * V_41 ,
T_1 V_116 , int V_119 )
{
int V_29 , V_16 ;
struct V_32 * V_98 [ V_39 + 1 ] ;
struct V_1 * V_64 ;
F_97 ( V_76 ) ;
V_16 = F_62 ( V_98 , V_39 , V_92 , NULL ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_119 == V_48 && V_41 -> V_139 & V_140 ) {
if ( V_98 [ 1 ] != NULL )
return F_93 ( V_91 , V_98 [ 1 ] , V_41 , V_116 ) ;
else
return - V_42 ;
}
for ( V_29 = 1 ; V_29 <= V_39 && V_98 [ V_29 ] ; V_29 ++ ) {
V_64 = F_89 ( V_98 [ V_29 ] , V_41 , V_116 ) ;
if ( F_72 ( V_64 ) ) {
V_16 = F_73 ( V_64 ) ;
goto V_27;
}
V_64 -> V_36 = V_29 ;
F_44 ( & V_64 -> V_86 , & V_76 ) ;
}
if ( V_119 == V_49 )
V_16 = F_83 ( V_91 , V_116 , V_41 , & V_76 , V_119 ) ;
else {
V_16 = F_95 ( V_91 , V_41 , & V_76 , V_116 ) ;
if ( V_16 )
goto V_27;
return V_16 ;
}
V_27:
F_92 ( & V_76 ) ;
return V_16 ;
}
static int
F_98 ( struct V_91 * V_91 , struct V_122 * V_41 , struct V_75 * V_76 ,
T_1 V_116 )
{
struct V_21 * V_22 ;
int V_27 = 0 ;
V_22 = F_84 ( V_132 , V_55 ) ;
if ( ! V_22 )
return - V_133 ;
if ( F_80 ( V_22 , V_76 , V_116 , V_41 -> V_134 , V_41 -> V_139 ,
V_143 , 0 , 0 ) <= 0 ) {
F_85 ( V_22 ) ;
return - V_42 ;
}
V_27 = F_94 ( V_22 , V_91 , V_116 , V_141 ,
V_41 -> V_139 & V_142 ) ;
if ( V_27 > 0 )
V_27 = 0 ;
return V_27 ;
}
static int
F_99 ( struct V_91 * V_91 , struct V_32 * V_92 , struct V_122 * V_41 ,
T_1 V_116 , int V_94 )
{
int V_16 = 0 ;
F_97 ( V_76 ) ;
V_16 = F_71 ( V_91 , V_92 , NULL , NULL , V_94 , 0 , & V_76 ) ;
if ( V_16 )
goto V_38;
V_16 = F_98 ( V_91 , V_41 , & V_76 , V_116 ) ;
F_92 ( & V_76 ) ;
V_38:
return V_16 ;
}
static int F_100 ( struct V_21 * V_22 , struct V_122 * V_41 )
{
struct V_91 * V_91 = F_101 ( V_22 -> V_144 ) ;
struct V_32 * V_145 [ V_99 + 1 ] ;
T_1 V_116 = V_22 ? F_102 ( V_22 ) . V_116 : 0 ;
int V_16 = 0 , V_94 = 0 ;
if ( ( V_41 -> V_146 != V_49 ) && ! F_103 ( V_22 , V_147 ) )
return - V_18 ;
V_16 = F_104 ( V_41 , sizeof( struct V_120 ) , V_145 , V_99 , NULL ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_145 [ V_129 ] == NULL ) {
F_105 ( L_5 ) ;
return - V_42 ;
}
switch ( V_41 -> V_146 ) {
case V_143 :
if ( V_41 -> V_139 & V_148 )
V_94 = 1 ;
V_149:
V_16 = F_99 ( V_91 , V_145 [ V_129 ] , V_41 , V_116 , V_94 ) ;
if ( V_16 == - V_102 )
goto V_149;
break;
case V_48 :
V_16 = F_96 ( V_91 , V_145 [ V_129 ] , V_41 ,
V_116 , V_48 ) ;
break;
case V_49 :
V_16 = F_96 ( V_91 , V_145 [ V_129 ] , V_41 ,
V_116 , V_49 ) ;
break;
default:
F_106 () ;
}
return V_16 ;
}
static struct V_32 *
F_107 ( const struct V_122 * V_41 )
{
struct V_32 * V_150 , * V_151 [ V_99 + 1 ] ;
struct V_32 * V_98 [ V_39 + 1 ] ;
struct V_32 * V_92 [ V_152 + 1 ] ;
struct V_32 * V_44 ;
if ( F_104 ( V_41 , sizeof( struct V_120 ) , V_92 , V_152 , NULL ) < 0 )
return NULL ;
V_150 = V_92 [ V_129 ] ;
if ( V_150 == NULL )
return NULL ;
if ( F_108 ( V_98 , V_39 , F_109 ( V_150 ) ,
F_110 ( F_90 ( V_150 ) ) , NULL ) < 0 )
return NULL ;
if ( V_98 [ 1 ] == NULL )
return NULL ;
if ( F_108 ( V_151 , V_99 , F_109 ( V_98 [ 1 ] ) ,
F_90 ( V_98 [ 1 ] ) , NULL ) < 0 )
return NULL ;
V_44 = V_151 [ V_101 ] ;
return V_44 ;
}
static int
F_111 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_122 * V_123 ;
unsigned char * V_88 = F_58 ( V_22 ) ;
struct V_32 * V_33 ;
struct V_63 * V_95 ;
struct V_1 V_2 ;
int V_16 = 0 ;
struct V_120 * V_121 = (struct V_120 * ) F_82 ( V_24 -> V_123 ) ;
struct V_32 * V_44 = F_107 ( V_24 -> V_123 ) ;
if ( V_44 == NULL ) {
F_112 ( L_6 ) ;
return 0 ;
}
V_95 = F_51 ( V_44 ) ;
if ( V_95 == NULL )
return 0 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 . V_8 = V_95 ;
V_123 = F_81 ( V_22 , F_102 ( V_24 -> V_22 ) . V_116 , V_24 -> V_123 -> V_134 ,
V_24 -> V_123 -> V_146 , sizeof( * V_121 ) , 0 ) ;
if ( ! V_123 )
goto V_137;
V_121 = F_82 ( V_123 ) ;
V_121 -> V_125 = V_126 ;
V_121 -> V_127 = 0 ;
V_121 -> V_128 = 0 ;
V_33 = F_11 ( V_22 , V_129 ) ;
if ( V_33 == NULL )
goto V_137;
V_16 = V_95 -> V_69 ( V_22 , V_24 , V_49 , & V_2 ) ;
if ( V_16 < 0 )
goto V_137;
if ( V_16 > 0 ) {
F_14 ( V_22 , V_33 ) ;
V_16 = V_22 -> V_131 ;
} else
F_15 ( V_22 , V_33 ) ;
V_123 -> V_130 = F_58 ( V_22 ) - V_88 ;
if ( F_102 ( V_24 -> V_22 ) . V_116 && V_16 )
V_123 -> V_139 |= V_153 ;
F_19 ( V_95 -> V_46 ) ;
return V_22 -> V_131 ;
V_137:
F_19 ( V_95 -> V_46 ) ;
F_13 ( V_22 , V_88 ) ;
return V_22 -> V_131 ;
}
static int T_3 F_113 ( void )
{
F_114 ( V_154 , V_143 , F_100 , NULL , NULL ) ;
F_114 ( V_154 , V_48 , F_100 , NULL , NULL ) ;
F_114 ( V_154 , V_49 , F_100 , F_111 ,
NULL ) ;
return 0 ;
}
