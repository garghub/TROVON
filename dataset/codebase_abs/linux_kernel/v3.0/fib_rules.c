int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_7 == NULL )
return - V_10 ;
F_3 ( & V_7 -> V_11 , 1 ) ;
V_7 -> V_12 = V_13 ;
V_7 -> V_3 = V_3 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_14 = F_4 ( V_2 -> V_15 ) ;
F_5 ( & V_7 -> V_16 , & V_2 -> V_17 ) ;
return 0 ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_6 * V_20 ;
if ( ! F_7 ( & V_2 -> V_17 ) ) {
V_19 = V_2 -> V_17 . V_21 ;
if ( V_19 -> V_21 != & V_2 -> V_17 ) {
V_20 = F_8 ( V_19 -> V_21 , struct V_6 , V_16 ) ;
if ( V_20 -> V_3 )
return V_20 -> V_3 - 1 ;
}
}
return 0 ;
}
static struct V_1 * F_9 ( struct V_22 * V_22 , int V_23 )
{
struct V_1 * V_2 ;
F_10 () ;
F_11 (ops, &net->rules_ops, list) {
if ( V_2 -> V_23 == V_23 ) {
if ( ! F_12 ( V_2 -> V_24 ) )
V_2 = NULL ;
F_13 () ;
return V_2 ;
}
}
F_13 () ;
return NULL ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( V_2 )
F_15 ( V_2 -> V_24 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 )
V_2 -> V_25 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_26 = - V_27 ;
struct V_1 * V_28 ;
struct V_22 * V_22 ;
V_22 = V_2 -> V_15 ;
if ( V_2 -> V_8 < sizeof( struct V_6 ) )
return - V_29 ;
if ( V_2 -> V_30 == NULL || V_2 -> V_31 == NULL ||
V_2 -> V_32 == NULL || V_2 -> V_33 == NULL ||
V_2 -> V_12 == NULL )
return - V_29 ;
F_18 ( & V_22 -> V_34 ) ;
F_19 (o, &net->rules_ops, list)
if ( V_2 -> V_23 == V_28 -> V_23 )
goto V_35;
F_4 ( V_22 ) ;
F_20 ( & V_2 -> V_16 , & V_22 -> V_36 ) ;
V_26 = 0 ;
V_35:
F_21 ( & V_22 -> V_34 ) ;
return V_26 ;
}
struct V_1 *
F_22 ( const struct V_1 * V_37 , struct V_22 * V_22 )
{
struct V_1 * V_2 ;
int V_26 ;
V_2 = F_23 ( V_37 , sizeof( * V_2 ) , V_9 ) ;
if ( V_2 == NULL )
return F_24 ( - V_10 ) ;
F_25 ( & V_2 -> V_17 ) ;
V_2 -> V_15 = V_22 ;
V_26 = F_17 ( V_2 ) ;
if ( V_26 ) {
F_26 ( V_2 ) ;
V_2 = F_24 ( V_26 ) ;
}
return V_2 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_20 , * V_38 ;
F_28 (rule, tmp, &ops->rules_list, list) {
F_29 ( & V_20 -> V_16 ) ;
F_30 ( V_20 ) ;
}
}
static void F_31 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_32 ( V_40 , struct V_1 , V_41 ) ;
struct V_22 * V_22 = V_2 -> V_15 ;
F_33 ( V_22 ) ;
F_26 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = V_2 -> V_15 ;
F_18 ( & V_22 -> V_34 ) ;
F_29 ( & V_2 -> V_16 ) ;
F_27 ( V_2 ) ;
F_21 ( & V_22 -> V_34 ) ;
F_35 ( & V_2 -> V_41 , F_31 ) ;
}
static int F_36 ( struct V_6 * V_20 , struct V_1 * V_2 ,
struct V_42 * V_43 , int V_5 )
{
int V_44 = 0 ;
if ( V_20 -> V_45 && ( V_20 -> V_45 != V_43 -> V_46 ) )
goto V_47;
if ( V_20 -> V_48 && ( V_20 -> V_48 != V_43 -> V_49 ) )
goto V_47;
if ( ( V_20 -> V_50 ^ V_43 -> V_51 ) & V_20 -> V_52 )
goto V_47;
V_44 = V_2 -> V_30 ( V_20 , V_43 , V_5 ) ;
V_47:
return ( V_20 -> V_5 & V_53 ) ? ! V_44 : V_44 ;
}
int F_37 ( struct V_1 * V_2 , struct V_42 * V_43 ,
int V_5 , struct V_54 * V_55 )
{
struct V_6 * V_20 ;
int V_26 ;
F_10 () ;
F_11 (rule, &ops->rules_list, list) {
V_56:
if ( ! F_36 ( V_20 , V_2 , V_43 , V_5 ) )
continue;
if ( V_20 -> V_12 == V_57 ) {
struct V_6 * V_58 ;
V_58 = F_38 ( V_20 -> V_59 ) ;
if ( V_58 == NULL ) {
continue;
} else {
V_20 = V_58 ;
goto V_56;
}
} else if ( V_20 -> V_12 == V_60 )
continue;
else
V_26 = V_2 -> V_12 ( V_20 , V_43 , V_5 , V_55 ) ;
if ( V_26 != - V_61 ) {
if ( ( V_55 -> V_5 & V_62 ) ||
F_39 ( F_40 ( & V_20 -> V_11 ) ) ) {
V_55 -> V_20 = V_20 ;
goto V_47;
}
break;
}
}
V_26 = - V_63 ;
V_47:
F_13 () ;
return V_26 ;
}
static int F_41 ( struct V_64 * V_65 , struct V_66 * * V_67 ,
struct V_1 * V_2 )
{
int V_26 = - V_29 ;
if ( V_65 -> V_68 )
if ( V_67 [ V_69 ] == NULL ||
V_65 -> V_68 > ( V_2 -> V_70 * 8 ) ||
F_42 ( V_67 [ V_69 ] ) != V_2 -> V_70 )
goto V_35;
if ( V_65 -> V_71 )
if ( V_67 [ V_72 ] == NULL ||
V_65 -> V_71 > ( V_2 -> V_70 * 8 ) ||
F_42 ( V_67 [ V_72 ] ) != V_2 -> V_70 )
goto V_35;
V_26 = 0 ;
V_35:
return V_26 ;
}
static int F_43 ( struct V_73 * V_74 , struct V_75 * V_76 , void * V_55 )
{
struct V_22 * V_22 = F_44 ( V_74 -> V_77 ) ;
struct V_64 * V_65 = F_45 ( V_76 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_20 , * V_7 , * V_78 = NULL ;
struct V_66 * V_67 [ V_79 + 1 ] ;
int V_26 = - V_29 , V_80 = 0 ;
if ( V_76 -> V_81 < F_46 ( sizeof( * V_65 ) ) )
goto V_35;
V_2 = F_9 ( V_22 , V_65 -> V_23 ) ;
if ( V_2 == NULL ) {
V_26 = - V_82 ;
goto V_35;
}
V_26 = F_47 ( V_76 , sizeof( * V_65 ) , V_67 , V_79 , V_2 -> V_83 ) ;
if ( V_26 < 0 )
goto V_35;
V_26 = F_41 ( V_65 , V_67 , V_2 ) ;
if ( V_26 < 0 )
goto V_35;
V_20 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_20 == NULL ) {
V_26 = - V_10 ;
goto V_35;
}
V_20 -> V_14 = F_4 ( V_22 ) ;
if ( V_67 [ V_84 ] )
V_20 -> V_3 = F_48 ( V_67 [ V_84 ] ) ;
if ( V_67 [ V_85 ] ) {
struct V_86 * V_87 ;
V_20 -> V_45 = - 1 ;
F_49 ( V_20 -> V_88 , V_67 [ V_85 ] , V_89 ) ;
V_87 = F_50 ( V_22 , V_20 -> V_88 ) ;
if ( V_87 )
V_20 -> V_45 = V_87 -> V_90 ;
}
if ( V_67 [ V_91 ] ) {
struct V_86 * V_87 ;
V_20 -> V_48 = - 1 ;
F_49 ( V_20 -> V_92 , V_67 [ V_91 ] , V_89 ) ;
V_87 = F_50 ( V_22 , V_20 -> V_92 ) ;
if ( V_87 )
V_20 -> V_48 = V_87 -> V_90 ;
}
if ( V_67 [ V_93 ] ) {
V_20 -> V_50 = F_48 ( V_67 [ V_93 ] ) ;
if ( V_20 -> V_50 )
V_20 -> V_52 = 0xFFFFFFFF ;
}
if ( V_67 [ V_94 ] )
V_20 -> V_52 = F_48 ( V_67 [ V_94 ] ) ;
V_20 -> V_12 = V_65 -> V_12 ;
V_20 -> V_5 = V_65 -> V_5 ;
V_20 -> V_4 = F_51 ( V_65 , V_67 ) ;
if ( ! V_67 [ V_84 ] && V_2 -> V_95 )
V_20 -> V_3 = V_2 -> V_95 ( V_2 ) ;
V_26 = - V_29 ;
if ( V_67 [ V_96 ] ) {
if ( V_20 -> V_12 != V_57 )
goto V_97;
V_20 -> V_58 = F_48 ( V_67 [ V_96 ] ) ;
if ( V_20 -> V_58 <= V_20 -> V_3 )
goto V_97;
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 == V_20 -> V_58 ) {
F_52 ( V_20 -> V_59 , V_7 ) ;
break;
}
}
if ( F_53 ( V_20 -> V_59 , 1 ) == NULL )
V_80 = 1 ;
} else if ( V_20 -> V_12 == V_57 )
goto V_97;
V_26 = V_2 -> V_31 ( V_20 , V_74 , V_65 , V_67 ) ;
if ( V_26 < 0 )
goto V_97;
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 > V_20 -> V_3 )
break;
V_78 = V_7 ;
}
F_54 ( V_20 ) ;
if ( V_78 )
F_55 ( & V_20 -> V_16 , & V_78 -> V_16 ) ;
else
F_55 ( & V_20 -> V_16 , & V_2 -> V_17 ) ;
if ( V_2 -> V_98 ) {
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 == V_57 &&
V_7 -> V_58 == V_20 -> V_3 ) {
F_56 ( F_57 ( V_7 -> V_59 ) != NULL ) ;
F_58 ( V_7 -> V_59 , V_20 ) ;
if ( -- V_2 -> V_98 == 0 )
break;
}
}
}
if ( V_20 -> V_12 == V_57 )
V_2 -> V_99 ++ ;
if ( V_80 )
V_2 -> V_98 ++ ;
F_59 ( V_100 , V_20 , V_2 , V_76 , F_60 ( V_74 ) . V_101 ) ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
V_97:
F_33 ( V_20 -> V_14 ) ;
F_26 ( V_20 ) ;
V_35:
F_14 ( V_2 ) ;
return V_26 ;
}
static int F_61 ( struct V_73 * V_74 , struct V_75 * V_76 , void * V_55 )
{
struct V_22 * V_22 = F_44 ( V_74 -> V_77 ) ;
struct V_64 * V_65 = F_45 ( V_76 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_20 , * V_38 ;
struct V_66 * V_67 [ V_79 + 1 ] ;
int V_26 = - V_29 ;
if ( V_76 -> V_81 < F_46 ( sizeof( * V_65 ) ) )
goto V_35;
V_2 = F_9 ( V_22 , V_65 -> V_23 ) ;
if ( V_2 == NULL ) {
V_26 = - V_82 ;
goto V_35;
}
V_26 = F_47 ( V_76 , sizeof( * V_65 ) , V_67 , V_79 , V_2 -> V_83 ) ;
if ( V_26 < 0 )
goto V_35;
V_26 = F_41 ( V_65 , V_67 , V_2 ) ;
if ( V_26 < 0 )
goto V_35;
F_19 (rule, &ops->rules_list, list) {
if ( V_65 -> V_12 && ( V_65 -> V_12 != V_20 -> V_12 ) )
continue;
if ( V_65 -> V_4 && ( F_51 ( V_65 , V_67 ) != V_20 -> V_4 ) )
continue;
if ( V_67 [ V_84 ] &&
( V_20 -> V_3 != F_48 ( V_67 [ V_84 ] ) ) )
continue;
if ( V_67 [ V_85 ] &&
F_62 ( V_67 [ V_85 ] , V_20 -> V_88 ) )
continue;
if ( V_67 [ V_91 ] &&
F_62 ( V_67 [ V_91 ] , V_20 -> V_92 ) )
continue;
if ( V_67 [ V_93 ] &&
( V_20 -> V_50 != F_48 ( V_67 [ V_93 ] ) ) )
continue;
if ( V_67 [ V_94 ] &&
( V_20 -> V_52 != F_48 ( V_67 [ V_94 ] ) ) )
continue;
if ( ! V_2 -> V_32 ( V_20 , V_65 , V_67 ) )
continue;
if ( V_20 -> V_5 & V_102 ) {
V_26 = - V_103 ;
goto V_35;
}
F_29 ( & V_20 -> V_16 ) ;
if ( V_20 -> V_12 == V_57 )
V_2 -> V_99 -- ;
if ( V_2 -> V_99 > 0 ) {
F_19 (tmp, &ops->rules_list, list) {
if ( F_57 ( V_38 -> V_59 ) == V_20 ) {
F_58 ( V_38 -> V_59 , NULL ) ;
V_2 -> V_98 ++ ;
}
}
}
F_59 ( V_104 , V_20 , V_2 , V_76 ,
F_60 ( V_74 ) . V_101 ) ;
F_30 ( V_20 ) ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
V_26 = - V_105 ;
V_35:
F_14 ( V_2 ) ;
return V_26 ;
}
static inline T_2 F_63 ( struct V_1 * V_2 ,
struct V_6 * V_20 )
{
T_2 V_106 = F_64 ( sizeof( struct V_64 ) )
+ F_65 ( V_89 )
+ F_65 ( V_89 )
+ F_65 ( 4 )
+ F_65 ( 4 )
+ F_65 ( 4 )
+ F_65 ( 4 ) ;
if ( V_2 -> V_107 )
V_106 += V_2 -> V_107 ( V_20 ) ;
return V_106 ;
}
static int F_66 ( struct V_73 * V_74 , struct V_6 * V_20 ,
T_1 V_101 , T_1 V_108 , int type , int V_5 ,
struct V_1 * V_2 )
{
struct V_75 * V_76 ;
struct V_64 * V_65 ;
V_76 = F_67 ( V_74 , V_101 , V_108 , type , sizeof( * V_65 ) , V_5 ) ;
if ( V_76 == NULL )
return - V_109 ;
V_65 = F_45 ( V_76 ) ;
V_65 -> V_23 = V_2 -> V_23 ;
V_65 -> V_4 = V_20 -> V_4 ;
F_68 ( V_74 , V_110 , V_20 -> V_4 ) ;
V_65 -> V_111 = 0 ;
V_65 -> V_112 = 0 ;
V_65 -> V_12 = V_20 -> V_12 ;
V_65 -> V_5 = V_20 -> V_5 ;
if ( V_20 -> V_12 == V_57 &&
F_69 ( V_20 -> V_59 ) == NULL )
V_65 -> V_5 |= V_113 ;
if ( V_20 -> V_88 [ 0 ] ) {
F_70 ( V_74 , V_85 , V_20 -> V_88 ) ;
if ( V_20 -> V_45 == - 1 )
V_65 -> V_5 |= V_114 ;
}
if ( V_20 -> V_92 [ 0 ] ) {
F_70 ( V_74 , V_91 , V_20 -> V_92 ) ;
if ( V_20 -> V_48 == - 1 )
V_65 -> V_5 |= V_115 ;
}
if ( V_20 -> V_3 )
F_68 ( V_74 , V_84 , V_20 -> V_3 ) ;
if ( V_20 -> V_50 )
F_68 ( V_74 , V_93 , V_20 -> V_50 ) ;
if ( V_20 -> V_52 || V_20 -> V_50 )
F_68 ( V_74 , V_94 , V_20 -> V_52 ) ;
if ( V_20 -> V_58 )
F_68 ( V_74 , V_96 , V_20 -> V_58 ) ;
if ( V_2 -> V_33 ( V_20 , V_74 , V_65 ) < 0 )
goto V_116;
return F_71 ( V_74 , V_76 ) ;
V_116:
F_72 ( V_74 , V_76 ) ;
return - V_109 ;
}
static int F_73 ( struct V_73 * V_74 , struct V_117 * V_118 ,
struct V_1 * V_2 )
{
int V_119 = 0 ;
struct V_6 * V_20 ;
F_10 () ;
F_11 (rule, &ops->rules_list, list) {
if ( V_119 < V_118 -> args [ 1 ] )
goto V_120;
if ( F_66 ( V_74 , V_20 , F_60 ( V_118 -> V_74 ) . V_101 ,
V_118 -> V_76 -> V_121 , V_100 ,
V_122 , V_2 ) < 0 )
break;
V_120:
V_119 ++ ;
}
F_13 () ;
V_118 -> args [ 1 ] = V_119 ;
F_14 ( V_2 ) ;
return V_74 -> V_123 ;
}
static int F_74 ( struct V_73 * V_74 , struct V_117 * V_118 )
{
struct V_22 * V_22 = F_44 ( V_74 -> V_77 ) ;
struct V_1 * V_2 ;
int V_119 = 0 , V_23 ;
V_23 = F_75 ( V_118 -> V_76 ) ;
if ( V_23 != V_124 ) {
V_2 = F_9 ( V_22 , V_23 ) ;
if ( V_2 == NULL )
return - V_82 ;
return F_73 ( V_74 , V_118 , V_2 ) ;
}
F_10 () ;
F_11 (ops, &net->rules_ops, list) {
if ( V_119 < V_118 -> args [ 0 ] || ! F_12 ( V_2 -> V_24 ) )
goto V_120;
if ( F_73 ( V_74 , V_118 , V_2 ) < 0 )
break;
V_118 -> args [ 1 ] = 0 ;
V_120:
V_119 ++ ;
}
F_13 () ;
V_118 -> args [ 0 ] = V_119 ;
return V_74 -> V_123 ;
}
static void F_59 ( int V_125 , struct V_6 * V_20 ,
struct V_1 * V_2 , struct V_75 * V_76 ,
T_1 V_101 )
{
struct V_22 * V_22 ;
struct V_73 * V_74 ;
int V_26 = - V_126 ;
V_22 = V_2 -> V_15 ;
V_74 = F_76 ( F_63 ( V_2 , V_20 ) , V_9 ) ;
if ( V_74 == NULL )
goto V_35;
V_26 = F_66 ( V_74 , V_20 , V_101 , V_76 -> V_121 , V_125 , 0 , V_2 ) ;
if ( V_26 < 0 ) {
F_77 ( V_26 == - V_109 ) ;
F_78 ( V_74 ) ;
goto V_35;
}
F_79 ( V_74 , V_22 , V_101 , V_2 -> V_127 , V_76 , V_9 ) ;
return;
V_35:
if ( V_26 < 0 )
F_80 ( V_22 , V_2 -> V_127 , V_26 ) ;
}
static void F_81 ( struct V_18 * V_128 , struct V_86 * V_87 )
{
struct V_6 * V_20 ;
F_19 (rule, rules, list) {
if ( V_20 -> V_45 == - 1 &&
strcmp ( V_87 -> V_129 , V_20 -> V_88 ) == 0 )
V_20 -> V_45 = V_87 -> V_90 ;
if ( V_20 -> V_48 == - 1 &&
strcmp ( V_87 -> V_129 , V_20 -> V_92 ) == 0 )
V_20 -> V_48 = V_87 -> V_90 ;
}
}
static void F_82 ( struct V_18 * V_128 , struct V_86 * V_87 )
{
struct V_6 * V_20 ;
F_19 (rule, rules, list) {
if ( V_20 -> V_45 == V_87 -> V_90 )
V_20 -> V_45 = - 1 ;
if ( V_20 -> V_48 == V_87 -> V_90 )
V_20 -> V_48 = - 1 ;
}
}
static int F_83 ( struct V_130 * V_131 , unsigned long V_125 ,
void * V_132 )
{
struct V_86 * V_87 = V_132 ;
struct V_22 * V_22 = F_84 ( V_87 ) ;
struct V_1 * V_2 ;
F_85 () ;
switch ( V_125 ) {
case V_133 :
F_19 (ops, &net->rules_ops, list)
F_81 ( & V_2 -> V_17 , V_87 ) ;
break;
case V_134 :
F_19 (ops, &net->rules_ops, list)
F_82 ( & V_2 -> V_17 , V_87 ) ;
break;
}
return V_135 ;
}
static int T_3 F_86 ( struct V_22 * V_22 )
{
F_25 ( & V_22 -> V_36 ) ;
F_87 ( & V_22 -> V_34 ) ;
return 0 ;
}
static int T_4 F_88 ( void )
{
int V_26 ;
F_89 ( V_136 , V_100 , F_43 , NULL ) ;
F_89 ( V_136 , V_104 , F_61 , NULL ) ;
F_89 ( V_136 , V_137 , NULL , F_74 ) ;
V_26 = F_90 ( & V_138 ) ;
if ( V_26 < 0 )
goto V_139;
V_26 = F_91 ( & V_140 ) ;
if ( V_26 < 0 )
goto V_141;
return 0 ;
V_141:
F_92 ( & V_138 ) ;
V_139:
F_93 ( V_136 , V_100 ) ;
F_93 ( V_136 , V_104 ) ;
F_93 ( V_136 , V_137 ) ;
return V_26 ;
}
