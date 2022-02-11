void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_4 -> V_5 ) ;
F_5 ( & V_2 -> V_7 ,
& V_2 -> V_8 ) ;
F_6 ( V_2 , V_9 ) ;
}
int F_7 ( struct V_1 * V_2 , int V_10 ,
struct V_3 * V_4 )
{
int V_11 = 0 ;
if ( V_2 ) {
if ( V_10 )
V_2 -> V_12 -- ;
V_2 -> V_13 -- ;
if ( V_2 -> V_12 <= 0 && V_2 -> V_13 <= 0 ) {
F_1 ( V_2 , V_4 ) ;
V_11 = 1 ;
}
}
return V_11 ;
}
static int F_8 ( struct V_14 * V_15 , struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_20 -> V_4 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
int V_23 = 0 , V_24 = - 1 , V_25 = 0 , V_26 = 0 , V_27 = 0 ;
struct V_28 * V_29 ;
F_2 ( & V_4 -> V_5 ) ;
V_26 = V_17 -> args [ 0 ] ;
for ( V_25 = 0 ; V_25 < ( V_4 -> V_30 + 1 ) ; V_25 ++ ) {
V_22 = & V_4 -> V_31 [ F_9 ( V_25 , V_4 -> V_30 ) ] ;
F_10 (p, head, tcfc_head) {
V_24 ++ ;
if ( V_24 < V_26 )
continue;
V_19 -> V_32 = V_2 ;
V_19 -> V_33 = V_27 ;
V_29 = F_11 ( V_15 , V_19 -> V_33 ) ;
if ( V_29 == NULL )
goto V_34;
V_23 = F_12 ( V_15 , V_19 , 0 , 0 ) ;
if ( V_23 < 0 ) {
V_24 -- ;
F_13 ( V_15 , V_29 ) ;
goto V_35;
}
F_14 ( V_15 , V_29 ) ;
V_27 ++ ;
if ( V_27 >= V_36 )
goto V_35;
}
}
V_35:
F_4 ( & V_4 -> V_5 ) ;
if ( V_27 )
V_17 -> args [ 0 ] += V_27 ;
return V_27 ;
V_34:
F_15 ( V_15 , V_29 ) ;
goto V_35;
}
static int F_16 ( struct V_14 * V_15 , struct V_18 * V_19 )
{
struct V_3 * V_4 = V_19 -> V_20 -> V_4 ;
struct V_21 * V_22 ;
struct V_37 * V_38 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
int V_25 = 0 , V_27 = 0 ;
V_29 = F_11 ( V_15 , V_19 -> V_33 ) ;
if ( V_29 == NULL )
goto V_34;
if ( F_17 ( V_15 , V_39 , V_19 -> V_20 -> V_40 ) )
goto V_34;
for ( V_25 = 0 ; V_25 < ( V_4 -> V_30 + 1 ) ; V_25 ++ ) {
V_22 = & V_4 -> V_31 [ F_9 ( V_25 , V_4 -> V_30 ) ] ;
F_18 (p, n, head, tcfc_head) {
if ( V_41 == F_7 ( V_2 , 0 , V_4 ) ) {
F_19 ( V_19 -> V_20 -> V_42 ) ;
V_27 ++ ;
}
}
}
if ( F_20 ( V_15 , V_43 , V_27 ) )
goto V_34;
F_14 ( V_15 , V_29 ) ;
return V_27 ;
V_34:
F_15 ( V_15 , V_29 ) ;
return - V_44 ;
}
static int F_21 ( struct V_14 * V_15 , struct V_16 * V_17 ,
int type , struct V_18 * V_19 )
{
if ( type == V_45 ) {
return F_16 ( V_15 , V_19 ) ;
} else if ( type == V_46 ) {
return F_8 ( V_15 , V_17 , V_19 ) ;
} else {
F_22 ( 1 , L_1 , type ) ;
return - V_44 ;
}
}
static struct V_1 * F_23 ( T_1 V_24 , struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
struct V_21 * V_22 ;
F_2 ( & V_4 -> V_5 ) ;
V_22 = & V_4 -> V_31 [ F_9 ( V_24 , V_4 -> V_30 ) ] ;
F_10 (p, head, tcfc_head)
if ( V_2 -> V_47 == V_24 )
break;
F_4 ( & V_4 -> V_5 ) ;
return V_2 ;
}
T_1 F_24 ( struct V_3 * V_4 )
{
T_1 V_48 = V_4 -> V_24 ;
do {
if ( ++ V_48 == 0 )
V_48 = 1 ;
} while ( F_23 ( V_48 , V_4 ) );
V_4 -> V_24 = V_48 ;
return V_48 ;
}
int F_25 ( struct V_18 * V_19 , T_1 V_24 )
{
struct V_3 * V_4 = V_19 -> V_20 -> V_4 ;
struct V_1 * V_2 = F_23 ( V_24 , V_4 ) ;
if ( V_2 ) {
V_19 -> V_32 = V_2 ;
return 1 ;
}
return 0 ;
}
struct V_1 * F_26 ( T_1 V_24 , struct V_18 * V_19 , int V_10 )
{
struct V_3 * V_4 = V_19 -> V_20 -> V_4 ;
struct V_1 * V_2 = NULL ;
if ( V_24 && ( V_2 = F_23 ( V_24 , V_4 ) ) != NULL ) {
if ( V_10 )
V_2 -> V_12 ++ ;
V_2 -> V_13 ++ ;
V_19 -> V_32 = V_2 ;
}
return V_2 ;
}
struct V_1 * F_27 ( T_1 V_24 , struct V_28 * V_49 ,
struct V_18 * V_19 , int V_50 , int V_10 )
{
struct V_3 * V_4 = V_19 -> V_20 -> V_4 ;
struct V_1 * V_2 = F_28 ( V_50 , V_51 ) ;
if ( F_29 ( ! V_2 ) )
return F_30 ( - V_52 ) ;
V_2 -> V_13 = 1 ;
if ( V_10 )
V_2 -> V_12 = 1 ;
F_31 ( & V_2 -> V_53 ) ;
F_32 ( & V_2 -> V_6 ) ;
V_2 -> V_47 = V_24 ? V_24 : F_24 ( V_4 ) ;
V_2 -> V_54 . V_55 = V_56 ;
V_2 -> V_54 . V_57 = V_56 ;
if ( V_49 ) {
int V_23 = F_33 ( & V_2 -> V_7 , & V_2 -> V_8 ,
& V_2 -> V_53 , V_49 ) ;
if ( V_23 ) {
F_34 ( V_2 ) ;
return F_30 ( V_23 ) ;
}
}
V_19 -> V_32 = ( void * ) V_2 ;
return V_2 ;
}
void F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_58 = F_9 ( V_2 -> V_47 , V_4 -> V_30 ) ;
F_2 ( & V_4 -> V_5 ) ;
F_36 ( & V_2 -> V_6 , & V_4 -> V_31 [ V_58 ] ) ;
F_4 ( & V_4 -> V_5 ) ;
}
int F_37 ( struct V_59 * V_60 )
{
struct V_59 * V_19 ;
if ( ! V_60 -> V_60 || ! V_60 -> V_61 || ! V_60 -> V_62 || ! V_60 -> V_63 )
return - V_44 ;
if ( ! V_60 -> V_64 )
V_60 -> V_64 = F_25 ;
if ( ! V_60 -> V_65 )
V_60 -> V_65 = F_21 ;
F_38 ( & V_66 ) ;
F_39 (a, &act_base, head) {
if ( V_60 -> type == V_19 -> type || ( strcmp ( V_60 -> V_40 , V_19 -> V_40 ) == 0 ) ) {
F_40 ( & V_66 ) ;
return - V_67 ;
}
}
F_41 ( & V_60 -> V_22 , & V_68 ) ;
F_40 ( & V_66 ) ;
return 0 ;
}
int F_42 ( struct V_59 * V_60 )
{
struct V_59 * V_19 ;
int V_23 = - V_69 ;
F_38 ( & V_66 ) ;
F_39 (a, &act_base, head) {
if ( V_19 == V_60 ) {
F_43 ( & V_60 -> V_22 ) ;
V_23 = 0 ;
break;
}
}
F_40 ( & V_66 ) ;
return V_23 ;
}
static struct V_59 * F_44 ( char * V_40 )
{
struct V_59 * V_19 , * V_70 = NULL ;
if ( V_40 ) {
F_45 ( & V_66 ) ;
F_39 (a, &act_base, head) {
if ( strcmp ( V_40 , V_19 -> V_40 ) == 0 ) {
if ( F_46 ( V_19 -> V_42 ) )
V_70 = V_19 ;
break;
}
}
F_47 ( & V_66 ) ;
}
return V_70 ;
}
static struct V_59 * F_48 ( struct V_28 * V_40 )
{
struct V_59 * V_19 , * V_70 = NULL ;
if ( V_40 ) {
F_45 ( & V_66 ) ;
F_39 (a, &act_base, head) {
if ( F_49 ( V_40 , V_19 -> V_40 ) == 0 ) {
if ( F_46 ( V_19 -> V_42 ) )
V_70 = V_19 ;
break;
}
}
F_47 ( & V_66 ) ;
}
return V_70 ;
}
int F_50 ( struct V_14 * V_15 , const struct V_71 * V_72 ,
struct V_73 * V_70 )
{
const struct V_18 * V_19 ;
int V_11 = - 1 ;
if ( V_15 -> V_74 & V_75 ) {
V_15 -> V_74 = F_51 ( V_15 -> V_74 ) ;
V_11 = V_76 ;
goto V_77;
}
F_39 (a, actions, list) {
V_78:
V_11 = V_19 -> V_20 -> V_60 ( V_15 , V_19 , V_70 ) ;
if ( V_79 & V_15 -> V_74 ) {
V_15 -> V_74 = F_52 ( V_15 -> V_74 ) ;
V_15 -> V_74 = F_53 ( V_15 -> V_74 ) ;
}
if ( V_11 == V_80 )
goto V_78;
if ( V_11 != V_81 )
goto V_77;
}
V_77:
return V_11 ;
}
void F_54 ( struct V_71 * V_72 , int V_10 )
{
struct V_18 * V_19 , * V_82 ;
F_55 (a, tmp, actions, list) {
if ( V_19 -> V_20 -> V_62 ( V_19 , V_10 ) == V_41 )
F_19 ( V_19 -> V_20 -> V_42 ) ;
F_43 ( & V_19 -> V_83 ) ;
F_34 ( V_19 ) ;
}
}
int
F_56 ( struct V_14 * V_15 , struct V_18 * V_19 , int V_10 , int V_84 )
{
return V_19 -> V_20 -> V_61 ( V_15 , V_19 , V_10 , V_84 ) ;
}
int
F_12 ( struct V_14 * V_15 , struct V_18 * V_19 , int V_10 , int V_84 )
{
int V_23 = - V_44 ;
unsigned char * V_85 = F_57 ( V_15 ) ;
struct V_28 * V_29 ;
if ( F_17 ( V_15 , V_39 , V_19 -> V_20 -> V_40 ) )
goto V_34;
if ( F_58 ( V_15 , V_19 , 0 ) )
goto V_34;
V_29 = F_11 ( V_15 , V_86 ) ;
if ( V_29 == NULL )
goto V_34;
V_23 = F_56 ( V_15 , V_19 , V_10 , V_84 ) ;
if ( V_23 > 0 ) {
F_14 ( V_15 , V_29 ) ;
return V_23 ;
}
V_34:
F_13 ( V_15 , V_85 ) ;
return - 1 ;
}
int
F_59 ( struct V_14 * V_15 , struct V_71 * V_72 , int V_10 , int V_84 )
{
struct V_18 * V_19 ;
int V_23 = - V_44 ;
struct V_28 * V_29 ;
F_39 (a, actions, list) {
V_29 = F_11 ( V_15 , V_19 -> V_33 ) ;
if ( V_29 == NULL )
goto V_34;
V_23 = F_12 ( V_15 , V_19 , V_10 , V_84 ) ;
if ( V_23 < 0 )
goto V_87;
F_14 ( V_15 , V_29 ) ;
}
return 0 ;
V_34:
V_23 = - V_44 ;
V_87:
F_15 ( V_15 , V_29 ) ;
return V_23 ;
}
struct V_18 * F_60 ( struct V_88 * V_88 , struct V_28 * V_89 ,
struct V_28 * V_49 , char * V_90 , int V_91 ,
int V_10 )
{
struct V_18 * V_19 ;
struct V_59 * V_92 ;
char V_93 [ V_94 ] ;
struct V_28 * V_95 [ V_96 + 1 ] ;
struct V_28 * V_40 ;
int V_23 ;
if ( V_90 == NULL ) {
V_23 = F_61 ( V_95 , V_96 , V_89 , NULL ) ;
if ( V_23 < 0 )
goto V_97;
V_23 = - V_44 ;
V_40 = V_95 [ V_98 ] ;
if ( V_40 == NULL )
goto V_97;
if ( F_62 ( V_93 , V_40 , V_94 ) >= V_94 )
goto V_97;
} else {
V_23 = - V_44 ;
if ( F_63 ( V_93 , V_90 , V_94 ) >= V_94 )
goto V_97;
}
V_92 = F_44 ( V_93 ) ;
if ( V_92 == NULL ) {
#ifdef F_64
F_65 () ;
F_66 ( L_2 , V_93 ) ;
F_67 () ;
V_92 = F_44 ( V_93 ) ;
if ( V_92 != NULL ) {
V_23 = - V_99 ;
goto V_100;
}
#endif
V_23 = - V_69 ;
goto V_97;
}
V_23 = - V_52 ;
V_19 = F_28 ( sizeof( * V_19 ) , V_51 ) ;
if ( V_19 == NULL )
goto V_100;
V_19 -> V_20 = V_92 ;
F_68 ( & V_19 -> V_83 ) ;
if ( V_90 == NULL )
V_23 = V_92 -> V_63 ( V_88 , V_95 [ V_101 ] , V_49 , V_19 , V_91 , V_10 ) ;
else
V_23 = V_92 -> V_63 ( V_88 , V_89 , V_49 , V_19 , V_91 , V_10 ) ;
if ( V_23 < 0 )
goto V_102;
if ( V_23 != V_103 )
F_19 ( V_92 -> V_42 ) ;
return V_19 ;
V_102:
F_34 ( V_19 ) ;
V_100:
F_19 ( V_92 -> V_42 ) ;
V_97:
return F_30 ( V_23 ) ;
}
int F_69 ( struct V_88 * V_88 , struct V_28 * V_89 ,
struct V_28 * V_49 , char * V_90 , int V_91 ,
int V_10 , struct V_71 * V_72 )
{
struct V_28 * V_95 [ V_36 + 1 ] ;
struct V_18 * V_60 ;
int V_23 ;
int V_25 ;
V_23 = F_61 ( V_95 , V_36 , V_89 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
for ( V_25 = 1 ; V_25 <= V_36 && V_95 [ V_25 ] ; V_25 ++ ) {
V_60 = F_60 ( V_88 , V_95 [ V_25 ] , V_49 , V_90 , V_91 , V_10 ) ;
if ( F_70 ( V_60 ) ) {
V_23 = F_71 ( V_60 ) ;
goto V_23;
}
V_60 -> V_33 = V_25 ;
F_41 ( & V_60 -> V_83 , V_72 ) ;
}
return 0 ;
V_23:
F_54 ( V_72 , V_10 ) ;
return V_23 ;
}
int F_58 ( struct V_14 * V_15 , struct V_18 * V_19 ,
int V_104 )
{
int V_23 = 0 ;
struct V_105 V_106 ;
struct V_1 * V_2 = V_19 -> V_32 ;
if ( V_2 == NULL )
goto V_87;
if ( V_104 ) {
if ( V_19 -> type == V_107 )
V_23 = F_72 ( V_15 , 0 ,
V_108 , V_109 , & V_2 -> V_53 , & V_106 ) ;
else
return 0 ;
} else
V_23 = F_73 ( V_15 , V_110 ,
& V_2 -> V_53 , & V_106 ) ;
if ( V_23 < 0 )
goto V_87;
if ( F_74 ( & V_106 , & V_2 -> V_7 ) < 0 ||
F_75 ( & V_106 , & V_2 -> V_7 ,
& V_2 -> V_8 ) < 0 ||
F_76 ( & V_106 , & V_2 -> V_111 ) < 0 )
goto V_87;
if ( F_77 ( & V_106 ) < 0 )
goto V_87;
return 0 ;
V_87:
return - 1 ;
}
static int
F_78 ( struct V_14 * V_15 , struct V_71 * V_72 , T_1 V_112 , T_1 V_113 ,
T_2 V_114 , int V_115 , int V_10 , int V_84 )
{
struct V_116 * V_117 ;
struct V_118 * V_119 ;
unsigned char * V_85 = F_57 ( V_15 ) ;
struct V_28 * V_29 ;
V_119 = F_79 ( V_15 , V_112 , V_113 , V_115 , sizeof( * V_117 ) , V_114 ) ;
if ( ! V_119 )
goto V_120;
V_117 = F_80 ( V_119 ) ;
V_117 -> V_121 = V_122 ;
V_117 -> V_123 = 0 ;
V_117 -> V_124 = 0 ;
V_29 = F_11 ( V_15 , V_125 ) ;
if ( V_29 == NULL )
goto V_120;
if ( F_59 ( V_15 , V_72 , V_10 , V_84 ) < 0 )
goto V_120;
F_14 ( V_15 , V_29 ) ;
V_119 -> V_126 = F_57 ( V_15 ) - V_85 ;
return V_15 -> V_127 ;
V_120:
F_13 ( V_15 , V_85 ) ;
return - 1 ;
}
static int
F_81 ( struct V_88 * V_88 , T_1 V_112 , struct V_118 * V_38 ,
struct V_71 * V_72 , int V_115 )
{
struct V_14 * V_15 ;
V_15 = F_82 ( V_128 , V_51 ) ;
if ( ! V_15 )
return - V_129 ;
if ( F_78 ( V_15 , V_72 , V_112 , V_38 -> V_130 , 0 , V_115 , 0 , 0 ) <= 0 ) {
F_83 ( V_15 ) ;
return - V_44 ;
}
return F_84 ( V_15 , V_88 , V_112 ) ;
}
static struct V_18 *
F_85 ( struct V_28 * V_89 , struct V_118 * V_38 , T_1 V_112 )
{
struct V_28 * V_95 [ V_96 + 1 ] ;
struct V_18 * V_19 ;
int V_24 ;
int V_23 ;
V_23 = F_61 ( V_95 , V_96 , V_89 , NULL ) ;
if ( V_23 < 0 )
goto V_97;
V_23 = - V_44 ;
if ( V_95 [ V_131 ] == NULL ||
F_86 ( V_95 [ V_131 ] ) < sizeof( V_24 ) )
goto V_97;
V_24 = F_87 ( V_95 [ V_131 ] ) ;
V_23 = - V_52 ;
V_19 = F_28 ( sizeof( struct V_18 ) , V_51 ) ;
if ( V_19 == NULL )
goto V_97;
F_68 ( & V_19 -> V_83 ) ;
V_23 = - V_44 ;
V_19 -> V_20 = F_48 ( V_95 [ V_98 ] ) ;
if ( V_19 -> V_20 == NULL )
goto V_102;
V_23 = - V_69 ;
if ( V_19 -> V_20 -> V_64 ( V_19 , V_24 ) == 0 )
goto V_100;
F_19 ( V_19 -> V_20 -> V_42 ) ;
return V_19 ;
V_100:
F_19 ( V_19 -> V_20 -> V_42 ) ;
V_102:
F_34 ( V_19 ) ;
V_97:
return F_30 ( V_23 ) ;
}
static void F_88 ( struct V_71 * V_72 )
{
struct V_18 * V_19 , * V_82 ;
F_55 (a, tmp, actions, list) {
F_43 ( & V_19 -> V_83 ) ;
F_34 ( V_19 ) ;
}
}
static struct V_18 * F_89 ( int V_25 )
{
struct V_18 * V_60 ;
V_60 = F_28 ( sizeof( * V_60 ) , V_51 ) ;
if ( V_60 == NULL ) {
F_90 ( L_3 ) ;
return NULL ;
}
V_60 -> V_33 = V_25 ;
F_68 ( & V_60 -> V_83 ) ;
return V_60 ;
}
static int F_91 ( struct V_88 * V_88 , struct V_28 * V_89 ,
struct V_118 * V_38 , T_1 V_112 )
{
struct V_14 * V_15 ;
unsigned char * V_85 ;
struct V_118 * V_119 ;
struct V_116 * V_117 ;
struct V_16 V_132 ;
struct V_28 * V_29 ;
struct V_28 * V_95 [ V_96 + 1 ] ;
struct V_28 * V_40 ;
struct V_18 * V_19 = F_89 ( 0 ) ;
int V_23 = - V_52 ;
if ( V_19 == NULL ) {
F_90 ( L_4 ) ;
return V_23 ;
}
V_15 = F_82 ( V_128 , V_51 ) ;
if ( ! V_15 ) {
F_90 ( L_5 ) ;
F_34 ( V_19 ) ;
return V_23 ;
}
V_85 = F_57 ( V_15 ) ;
V_23 = F_61 ( V_95 , V_96 , V_89 , NULL ) ;
if ( V_23 < 0 )
goto V_97;
V_23 = - V_44 ;
V_40 = V_95 [ V_98 ] ;
V_19 -> V_20 = F_48 ( V_40 ) ;
if ( V_19 -> V_20 == NULL )
goto V_97;
V_119 = F_79 ( V_15 , V_112 , V_38 -> V_130 , V_45 , sizeof( * V_117 ) , 0 ) ;
if ( ! V_119 )
goto V_133;
V_117 = F_80 ( V_119 ) ;
V_117 -> V_121 = V_122 ;
V_117 -> V_123 = 0 ;
V_117 -> V_124 = 0 ;
V_29 = F_11 ( V_15 , V_125 ) ;
if ( V_29 == NULL )
goto V_133;
V_23 = V_19 -> V_20 -> V_65 ( V_15 , & V_132 , V_45 , V_19 ) ;
if ( V_23 < 0 )
goto V_133;
if ( V_23 == 0 )
goto V_134;
F_14 ( V_15 , V_29 ) ;
V_119 -> V_126 = F_57 ( V_15 ) - V_85 ;
V_119 -> V_135 |= V_136 ;
F_19 ( V_19 -> V_20 -> V_42 ) ;
F_34 ( V_19 ) ;
V_23 = F_92 ( V_15 , V_88 , V_112 , V_137 ,
V_38 -> V_135 & V_138 ) ;
if ( V_23 > 0 )
return 0 ;
return V_23 ;
V_133:
F_19 ( V_19 -> V_20 -> V_42 ) ;
V_97:
V_134:
F_83 ( V_15 ) ;
F_34 ( V_19 ) ;
return V_23 ;
}
static int
F_93 ( struct V_88 * V_88 , struct V_118 * V_38 , struct V_71 * V_72 ,
T_1 V_112 )
{
int V_11 ;
struct V_14 * V_15 ;
V_15 = F_82 ( V_128 , V_51 ) ;
if ( ! V_15 )
return - V_129 ;
if ( F_78 ( V_15 , V_72 , V_112 , V_38 -> V_130 , 0 , V_45 ,
0 , 1 ) <= 0 ) {
F_83 ( V_15 ) ;
return - V_44 ;
}
F_54 ( V_72 , 0 ) ;
V_11 = F_92 ( V_15 , V_88 , V_112 , V_137 ,
V_38 -> V_135 & V_138 ) ;
if ( V_11 > 0 )
return 0 ;
return V_11 ;
}
static int
F_94 ( struct V_88 * V_88 , struct V_28 * V_89 , struct V_118 * V_38 ,
T_1 V_112 , int V_115 )
{
int V_25 , V_11 ;
struct V_28 * V_95 [ V_36 + 1 ] ;
struct V_18 * V_60 ;
F_95 ( V_72 ) ;
V_11 = F_61 ( V_95 , V_36 , V_89 , NULL ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_115 == V_45 && V_38 -> V_135 & V_136 ) {
if ( V_95 [ 1 ] != NULL )
return F_91 ( V_88 , V_95 [ 1 ] , V_38 , V_112 ) ;
else
return - V_44 ;
}
for ( V_25 = 1 ; V_25 <= V_36 && V_95 [ V_25 ] ; V_25 ++ ) {
V_60 = F_85 ( V_95 [ V_25 ] , V_38 , V_112 ) ;
if ( F_70 ( V_60 ) ) {
V_11 = F_71 ( V_60 ) ;
goto V_23;
}
V_60 -> V_33 = V_25 ;
F_41 ( & V_60 -> V_83 , & V_72 ) ;
}
if ( V_115 == V_46 )
V_11 = F_81 ( V_88 , V_112 , V_38 , & V_72 , V_115 ) ;
else {
V_11 = F_93 ( V_88 , V_38 , & V_72 , V_112 ) ;
if ( V_11 )
goto V_23;
return V_11 ;
}
V_23:
F_88 ( & V_72 ) ;
return V_11 ;
}
static int
F_96 ( struct V_88 * V_88 , struct V_118 * V_38 , struct V_71 * V_72 ,
T_1 V_112 )
{
struct V_14 * V_15 ;
int V_23 = 0 ;
V_15 = F_82 ( V_128 , V_51 ) ;
if ( ! V_15 )
return - V_129 ;
if ( F_78 ( V_15 , V_72 , V_112 , V_38 -> V_130 , V_38 -> V_135 ,
V_139 , 0 , 0 ) <= 0 ) {
F_83 ( V_15 ) ;
return - V_44 ;
}
V_23 = F_92 ( V_15 , V_88 , V_112 , V_137 ,
V_38 -> V_135 & V_138 ) ;
if ( V_23 > 0 )
V_23 = 0 ;
return V_23 ;
}
static int
F_97 ( struct V_88 * V_88 , struct V_28 * V_89 , struct V_118 * V_38 ,
T_1 V_112 , int V_91 )
{
int V_11 = 0 ;
F_95 ( V_72 ) ;
V_11 = F_69 ( V_88 , V_89 , NULL , NULL , V_91 , 0 , & V_72 ) ;
if ( V_11 )
goto V_35;
V_11 = F_96 ( V_88 , V_38 , & V_72 , V_112 ) ;
F_88 ( & V_72 ) ;
V_35:
return V_11 ;
}
static int F_98 ( struct V_14 * V_15 , struct V_118 * V_38 )
{
struct V_88 * V_88 = F_99 ( V_15 -> V_140 ) ;
struct V_28 * V_141 [ V_96 + 1 ] ;
T_1 V_112 = V_15 ? F_100 ( V_15 ) . V_112 : 0 ;
int V_11 = 0 , V_91 = 0 ;
if ( ( V_38 -> V_142 != V_46 ) && ! F_101 ( V_143 ) )
return - V_144 ;
V_11 = F_102 ( V_38 , sizeof( struct V_116 ) , V_141 , V_96 , NULL ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_141 [ V_125 ] == NULL ) {
F_103 ( L_6 ) ;
return - V_44 ;
}
switch ( V_38 -> V_142 ) {
case V_139 :
if ( V_38 -> V_135 & V_145 )
V_91 = 1 ;
V_146:
V_11 = F_97 ( V_88 , V_141 [ V_125 ] , V_38 , V_112 , V_91 ) ;
if ( V_11 == - V_99 )
goto V_146;
break;
case V_45 :
V_11 = F_94 ( V_88 , V_141 [ V_125 ] , V_38 ,
V_112 , V_45 ) ;
break;
case V_46 :
V_11 = F_94 ( V_88 , V_141 [ V_125 ] , V_38 ,
V_112 , V_46 ) ;
break;
default:
F_104 () ;
}
return V_11 ;
}
static struct V_28 *
F_105 ( const struct V_118 * V_38 )
{
struct V_28 * V_147 , * V_148 [ V_96 + 1 ] ;
struct V_28 * V_95 [ V_36 + 1 ] ;
struct V_28 * V_89 [ V_149 + 1 ] ;
struct V_28 * V_40 ;
if ( F_102 ( V_38 , sizeof( struct V_116 ) , V_89 , V_149 , NULL ) < 0 )
return NULL ;
V_147 = V_89 [ V_125 ] ;
if ( V_147 == NULL )
return NULL ;
if ( F_106 ( V_95 , V_36 , F_107 ( V_147 ) ,
F_108 ( F_86 ( V_147 ) ) , NULL ) < 0 )
return NULL ;
if ( V_95 [ 1 ] == NULL )
return NULL ;
if ( F_106 ( V_148 , V_96 , F_107 ( V_95 [ 1 ] ) ,
F_86 ( V_95 [ 1 ] ) , NULL ) < 0 )
return NULL ;
V_40 = V_148 [ V_98 ] ;
return V_40 ;
}
static int
F_109 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
struct V_118 * V_119 ;
unsigned char * V_85 = F_57 ( V_15 ) ;
struct V_28 * V_29 ;
struct V_59 * V_92 ;
struct V_18 V_19 ;
int V_11 = 0 ;
struct V_116 * V_117 = (struct V_116 * ) F_80 ( V_17 -> V_119 ) ;
struct V_28 * V_40 = F_105 ( V_17 -> V_119 ) ;
if ( V_40 == NULL ) {
F_110 ( L_7 ) ;
return 0 ;
}
V_92 = F_48 ( V_40 ) ;
if ( V_92 == NULL )
return 0 ;
memset ( & V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 . V_20 = V_92 ;
V_119 = F_79 ( V_15 , F_100 ( V_17 -> V_15 ) . V_112 , V_17 -> V_119 -> V_130 ,
V_17 -> V_119 -> V_142 , sizeof( * V_117 ) , 0 ) ;
if ( ! V_119 )
goto V_133;
V_117 = F_80 ( V_119 ) ;
V_117 -> V_121 = V_122 ;
V_117 -> V_123 = 0 ;
V_117 -> V_124 = 0 ;
V_29 = F_11 ( V_15 , V_125 ) ;
if ( V_29 == NULL )
goto V_133;
V_11 = V_92 -> V_65 ( V_15 , V_17 , V_46 , & V_19 ) ;
if ( V_11 < 0 )
goto V_133;
if ( V_11 > 0 ) {
F_14 ( V_15 , V_29 ) ;
V_11 = V_15 -> V_127 ;
} else
F_15 ( V_15 , V_29 ) ;
V_119 -> V_126 = F_57 ( V_15 ) - V_85 ;
if ( F_100 ( V_17 -> V_15 ) . V_112 && V_11 )
V_119 -> V_135 |= V_150 ;
F_19 ( V_92 -> V_42 ) ;
return V_15 -> V_127 ;
V_133:
F_19 ( V_92 -> V_42 ) ;
F_13 ( V_15 , V_85 ) ;
return V_15 -> V_127 ;
}
static int T_3 F_111 ( void )
{
F_112 ( V_151 , V_139 , F_98 , NULL , NULL ) ;
F_112 ( V_151 , V_45 , F_98 , NULL , NULL ) ;
F_112 ( V_151 , V_46 , F_98 , F_109 ,
NULL ) ;
return 0 ;
}
