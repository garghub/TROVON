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
if ( V_2 -> V_39 )
V_2 -> V_39 ( V_20 ) ;
F_30 ( V_20 ) ;
}
}
static void F_31 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_32 ( V_41 , struct V_1 , V_42 ) ;
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
F_35 ( & V_2 -> V_42 , F_31 ) ;
}
static int F_36 ( struct V_6 * V_20 , struct V_1 * V_2 ,
struct V_43 * V_44 , int V_5 )
{
int V_45 = 0 ;
if ( V_20 -> V_46 && ( V_20 -> V_46 != V_44 -> V_47 ) )
goto V_48;
if ( V_20 -> V_49 && ( V_20 -> V_49 != V_44 -> V_50 ) )
goto V_48;
if ( ( V_20 -> V_51 ^ V_44 -> V_52 ) & V_20 -> V_53 )
goto V_48;
V_45 = V_2 -> V_30 ( V_20 , V_44 , V_5 ) ;
V_48:
return ( V_20 -> V_5 & V_54 ) ? ! V_45 : V_45 ;
}
int F_37 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int V_5 , struct V_55 * V_56 )
{
struct V_6 * V_20 ;
int V_26 ;
F_10 () ;
F_11 (rule, &ops->rules_list, list) {
V_57:
if ( ! F_36 ( V_20 , V_2 , V_44 , V_5 ) )
continue;
if ( V_20 -> V_12 == V_58 ) {
struct V_6 * V_59 ;
V_59 = F_38 ( V_20 -> V_60 ) ;
if ( V_59 == NULL ) {
continue;
} else {
V_20 = V_59 ;
goto V_57;
}
} else if ( V_20 -> V_12 == V_61 )
continue;
else
V_26 = V_2 -> V_12 ( V_20 , V_44 , V_5 , V_56 ) ;
if ( V_26 != - V_62 ) {
if ( ( V_56 -> V_5 & V_63 ) ||
F_39 ( F_40 ( & V_20 -> V_11 ) ) ) {
V_56 -> V_20 = V_20 ;
goto V_48;
}
break;
}
}
V_26 = - V_64 ;
V_48:
F_13 () ;
return V_26 ;
}
static int F_41 ( struct V_65 * V_66 , struct V_67 * * V_68 ,
struct V_1 * V_2 )
{
int V_26 = - V_29 ;
if ( V_66 -> V_69 )
if ( V_68 [ V_70 ] == NULL ||
V_66 -> V_69 > ( V_2 -> V_71 * 8 ) ||
F_42 ( V_68 [ V_70 ] ) != V_2 -> V_71 )
goto V_35;
if ( V_66 -> V_72 )
if ( V_68 [ V_73 ] == NULL ||
V_66 -> V_72 > ( V_2 -> V_71 * 8 ) ||
F_42 ( V_68 [ V_73 ] ) != V_2 -> V_71 )
goto V_35;
V_26 = 0 ;
V_35:
return V_26 ;
}
static int F_43 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
struct V_22 * V_22 = F_44 ( V_75 -> V_78 ) ;
struct V_65 * V_66 = F_45 ( V_77 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_20 , * V_7 , * V_79 = NULL ;
struct V_67 * V_68 [ V_80 + 1 ] ;
int V_26 = - V_29 , V_81 = 0 ;
if ( V_77 -> V_82 < F_46 ( sizeof( * V_66 ) ) )
goto V_35;
V_2 = F_9 ( V_22 , V_66 -> V_23 ) ;
if ( V_2 == NULL ) {
V_26 = - V_83 ;
goto V_35;
}
V_26 = F_47 ( V_77 , sizeof( * V_66 ) , V_68 , V_80 , V_2 -> V_84 ) ;
if ( V_26 < 0 )
goto V_35;
V_26 = F_41 ( V_66 , V_68 , V_2 ) ;
if ( V_26 < 0 )
goto V_35;
V_20 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_20 == NULL ) {
V_26 = - V_10 ;
goto V_35;
}
V_20 -> V_14 = F_4 ( V_22 ) ;
if ( V_68 [ V_85 ] )
V_20 -> V_3 = F_48 ( V_68 [ V_85 ] ) ;
if ( V_68 [ V_86 ] ) {
struct V_87 * V_88 ;
V_20 -> V_46 = - 1 ;
F_49 ( V_20 -> V_89 , V_68 [ V_86 ] , V_90 ) ;
V_88 = F_50 ( V_22 , V_20 -> V_89 ) ;
if ( V_88 )
V_20 -> V_46 = V_88 -> V_91 ;
}
if ( V_68 [ V_92 ] ) {
struct V_87 * V_88 ;
V_20 -> V_49 = - 1 ;
F_49 ( V_20 -> V_93 , V_68 [ V_92 ] , V_90 ) ;
V_88 = F_50 ( V_22 , V_20 -> V_93 ) ;
if ( V_88 )
V_20 -> V_49 = V_88 -> V_91 ;
}
if ( V_68 [ V_94 ] ) {
V_20 -> V_51 = F_48 ( V_68 [ V_94 ] ) ;
if ( V_20 -> V_51 )
V_20 -> V_53 = 0xFFFFFFFF ;
}
if ( V_68 [ V_95 ] )
V_20 -> V_53 = F_48 ( V_68 [ V_95 ] ) ;
V_20 -> V_12 = V_66 -> V_12 ;
V_20 -> V_5 = V_66 -> V_5 ;
V_20 -> V_4 = F_51 ( V_66 , V_68 ) ;
if ( ! V_68 [ V_85 ] && V_2 -> V_96 )
V_20 -> V_3 = V_2 -> V_96 ( V_2 ) ;
V_26 = - V_29 ;
if ( V_68 [ V_97 ] ) {
if ( V_20 -> V_12 != V_58 )
goto V_98;
V_20 -> V_59 = F_48 ( V_68 [ V_97 ] ) ;
if ( V_20 -> V_59 <= V_20 -> V_3 )
goto V_98;
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 == V_20 -> V_59 ) {
F_52 ( V_20 -> V_60 , V_7 ) ;
break;
}
}
if ( F_53 ( V_20 -> V_60 , 1 ) == NULL )
V_81 = 1 ;
} else if ( V_20 -> V_12 == V_58 )
goto V_98;
V_26 = V_2 -> V_31 ( V_20 , V_75 , V_66 , V_68 ) ;
if ( V_26 < 0 )
goto V_98;
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 > V_20 -> V_3 )
break;
V_79 = V_7 ;
}
F_54 ( V_20 ) ;
if ( V_79 )
F_55 ( & V_20 -> V_16 , & V_79 -> V_16 ) ;
else
F_55 ( & V_20 -> V_16 , & V_2 -> V_17 ) ;
if ( V_2 -> V_99 ) {
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 == V_58 &&
V_7 -> V_59 == V_20 -> V_3 &&
F_56 ( V_7 -> V_60 ) == NULL ) {
F_57 ( V_7 -> V_60 , V_20 ) ;
if ( -- V_2 -> V_99 == 0 )
break;
}
}
}
if ( V_20 -> V_12 == V_58 )
V_2 -> V_100 ++ ;
if ( V_81 )
V_2 -> V_99 ++ ;
F_58 ( V_101 , V_20 , V_2 , V_77 , F_59 ( V_75 ) . V_102 ) ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
V_98:
F_33 ( V_20 -> V_14 ) ;
F_26 ( V_20 ) ;
V_35:
F_14 ( V_2 ) ;
return V_26 ;
}
static int F_60 ( struct V_74 * V_75 , struct V_76 * V_77 )
{
struct V_22 * V_22 = F_44 ( V_75 -> V_78 ) ;
struct V_65 * V_66 = F_45 ( V_77 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_20 , * V_38 ;
struct V_67 * V_68 [ V_80 + 1 ] ;
int V_26 = - V_29 ;
if ( V_77 -> V_82 < F_46 ( sizeof( * V_66 ) ) )
goto V_35;
V_2 = F_9 ( V_22 , V_66 -> V_23 ) ;
if ( V_2 == NULL ) {
V_26 = - V_83 ;
goto V_35;
}
V_26 = F_47 ( V_77 , sizeof( * V_66 ) , V_68 , V_80 , V_2 -> V_84 ) ;
if ( V_26 < 0 )
goto V_35;
V_26 = F_41 ( V_66 , V_68 , V_2 ) ;
if ( V_26 < 0 )
goto V_35;
F_19 (rule, &ops->rules_list, list) {
if ( V_66 -> V_12 && ( V_66 -> V_12 != V_20 -> V_12 ) )
continue;
if ( V_66 -> V_4 && ( F_51 ( V_66 , V_68 ) != V_20 -> V_4 ) )
continue;
if ( V_68 [ V_85 ] &&
( V_20 -> V_3 != F_48 ( V_68 [ V_85 ] ) ) )
continue;
if ( V_68 [ V_86 ] &&
F_61 ( V_68 [ V_86 ] , V_20 -> V_89 ) )
continue;
if ( V_68 [ V_92 ] &&
F_61 ( V_68 [ V_92 ] , V_20 -> V_93 ) )
continue;
if ( V_68 [ V_94 ] &&
( V_20 -> V_51 != F_48 ( V_68 [ V_94 ] ) ) )
continue;
if ( V_68 [ V_95 ] &&
( V_20 -> V_53 != F_48 ( V_68 [ V_95 ] ) ) )
continue;
if ( ! V_2 -> V_32 ( V_20 , V_66 , V_68 ) )
continue;
if ( V_20 -> V_5 & V_103 ) {
V_26 = - V_104 ;
goto V_35;
}
F_29 ( & V_20 -> V_16 ) ;
if ( V_20 -> V_12 == V_58 ) {
V_2 -> V_100 -- ;
if ( F_56 ( V_20 -> V_60 ) == NULL )
V_2 -> V_99 -- ;
}
if ( V_2 -> V_100 > 0 ) {
F_19 (tmp, &ops->rules_list, list) {
if ( F_56 ( V_38 -> V_60 ) == V_20 ) {
F_52 ( V_38 -> V_60 , NULL ) ;
V_2 -> V_99 ++ ;
}
}
}
F_58 ( V_105 , V_20 , V_2 , V_77 ,
F_59 ( V_75 ) . V_102 ) ;
if ( V_2 -> V_39 )
V_2 -> V_39 ( V_20 ) ;
F_30 ( V_20 ) ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
V_26 = - V_106 ;
V_35:
F_14 ( V_2 ) ;
return V_26 ;
}
static inline T_2 F_62 ( struct V_1 * V_2 ,
struct V_6 * V_20 )
{
T_2 V_107 = F_63 ( sizeof( struct V_65 ) )
+ F_64 ( V_90 )
+ F_64 ( V_90 )
+ F_64 ( 4 )
+ F_64 ( 4 )
+ F_64 ( 4 )
+ F_64 ( 4 ) ;
if ( V_2 -> V_108 )
V_107 += V_2 -> V_108 ( V_20 ) ;
return V_107 ;
}
static int F_65 ( struct V_74 * V_75 , struct V_6 * V_20 ,
T_1 V_109 , T_1 V_110 , int type , int V_5 ,
struct V_1 * V_2 )
{
struct V_76 * V_77 ;
struct V_65 * V_66 ;
V_77 = F_66 ( V_75 , V_109 , V_110 , type , sizeof( * V_66 ) , V_5 ) ;
if ( V_77 == NULL )
return - V_111 ;
V_66 = F_45 ( V_77 ) ;
V_66 -> V_23 = V_2 -> V_23 ;
V_66 -> V_4 = V_20 -> V_4 ;
if ( F_67 ( V_75 , V_112 , V_20 -> V_4 ) )
goto V_113;
V_66 -> V_114 = 0 ;
V_66 -> V_115 = 0 ;
V_66 -> V_12 = V_20 -> V_12 ;
V_66 -> V_5 = V_20 -> V_5 ;
if ( V_20 -> V_12 == V_58 &&
F_68 ( V_20 -> V_60 ) == NULL )
V_66 -> V_5 |= V_116 ;
if ( V_20 -> V_89 [ 0 ] ) {
if ( F_69 ( V_75 , V_86 , V_20 -> V_89 ) )
goto V_113;
if ( V_20 -> V_46 == - 1 )
V_66 -> V_5 |= V_117 ;
}
if ( V_20 -> V_93 [ 0 ] ) {
if ( F_69 ( V_75 , V_92 , V_20 -> V_93 ) )
goto V_113;
if ( V_20 -> V_49 == - 1 )
V_66 -> V_5 |= V_118 ;
}
if ( ( V_20 -> V_3 &&
F_67 ( V_75 , V_85 , V_20 -> V_3 ) ) ||
( V_20 -> V_51 &&
F_67 ( V_75 , V_94 , V_20 -> V_51 ) ) ||
( ( V_20 -> V_53 || V_20 -> V_51 ) &&
F_67 ( V_75 , V_95 , V_20 -> V_53 ) ) ||
( V_20 -> V_59 &&
F_67 ( V_75 , V_97 , V_20 -> V_59 ) ) )
goto V_113;
if ( V_2 -> V_33 ( V_20 , V_75 , V_66 ) < 0 )
goto V_113;
return F_70 ( V_75 , V_77 ) ;
V_113:
F_71 ( V_75 , V_77 ) ;
return - V_111 ;
}
static int F_72 ( struct V_74 * V_75 , struct V_119 * V_120 ,
struct V_1 * V_2 )
{
int V_121 = 0 ;
struct V_6 * V_20 ;
F_10 () ;
F_11 (rule, &ops->rules_list, list) {
if ( V_121 < V_120 -> args [ 1 ] )
goto V_122;
if ( F_65 ( V_75 , V_20 , F_59 ( V_120 -> V_75 ) . V_102 ,
V_120 -> V_77 -> V_123 , V_101 ,
V_124 , V_2 ) < 0 )
break;
V_122:
V_121 ++ ;
}
F_13 () ;
V_120 -> args [ 1 ] = V_121 ;
F_14 ( V_2 ) ;
return V_75 -> V_125 ;
}
static int F_73 ( struct V_74 * V_75 , struct V_119 * V_120 )
{
struct V_22 * V_22 = F_44 ( V_75 -> V_78 ) ;
struct V_1 * V_2 ;
int V_121 = 0 , V_23 ;
V_23 = F_74 ( V_120 -> V_77 ) ;
if ( V_23 != V_126 ) {
V_2 = F_9 ( V_22 , V_23 ) ;
if ( V_2 == NULL )
return - V_83 ;
return F_72 ( V_75 , V_120 , V_2 ) ;
}
F_10 () ;
F_11 (ops, &net->rules_ops, list) {
if ( V_121 < V_120 -> args [ 0 ] || ! F_12 ( V_2 -> V_24 ) )
goto V_122;
if ( F_72 ( V_75 , V_120 , V_2 ) < 0 )
break;
V_120 -> args [ 1 ] = 0 ;
V_122:
V_121 ++ ;
}
F_13 () ;
V_120 -> args [ 0 ] = V_121 ;
return V_75 -> V_125 ;
}
static void F_58 ( int V_127 , struct V_6 * V_20 ,
struct V_1 * V_2 , struct V_76 * V_77 ,
T_1 V_109 )
{
struct V_22 * V_22 ;
struct V_74 * V_75 ;
int V_26 = - V_128 ;
V_22 = V_2 -> V_15 ;
V_75 = F_75 ( F_62 ( V_2 , V_20 ) , V_9 ) ;
if ( V_75 == NULL )
goto V_35;
V_26 = F_65 ( V_75 , V_20 , V_109 , V_77 -> V_123 , V_127 , 0 , V_2 ) ;
if ( V_26 < 0 ) {
F_76 ( V_26 == - V_111 ) ;
F_77 ( V_75 ) ;
goto V_35;
}
F_78 ( V_75 , V_22 , V_109 , V_2 -> V_129 , V_77 , V_9 ) ;
return;
V_35:
if ( V_26 < 0 )
F_79 ( V_22 , V_2 -> V_129 , V_26 ) ;
}
static void F_80 ( struct V_18 * V_130 , struct V_87 * V_88 )
{
struct V_6 * V_20 ;
F_19 (rule, rules, list) {
if ( V_20 -> V_46 == - 1 &&
strcmp ( V_88 -> V_131 , V_20 -> V_89 ) == 0 )
V_20 -> V_46 = V_88 -> V_91 ;
if ( V_20 -> V_49 == - 1 &&
strcmp ( V_88 -> V_131 , V_20 -> V_93 ) == 0 )
V_20 -> V_49 = V_88 -> V_91 ;
}
}
static void F_81 ( struct V_18 * V_130 , struct V_87 * V_88 )
{
struct V_6 * V_20 ;
F_19 (rule, rules, list) {
if ( V_20 -> V_46 == V_88 -> V_91 )
V_20 -> V_46 = - 1 ;
if ( V_20 -> V_49 == V_88 -> V_91 )
V_20 -> V_49 = - 1 ;
}
}
static int F_82 ( struct V_132 * V_133 , unsigned long V_127 ,
void * V_134 )
{
struct V_87 * V_88 = V_134 ;
struct V_22 * V_22 = F_83 ( V_88 ) ;
struct V_1 * V_2 ;
F_84 () ;
switch ( V_127 ) {
case V_135 :
F_19 (ops, &net->rules_ops, list)
F_80 ( & V_2 -> V_17 , V_88 ) ;
break;
case V_136 :
F_19 (ops, &net->rules_ops, list)
F_81 ( & V_2 -> V_17 , V_88 ) ;
break;
}
return V_137 ;
}
static int T_3 F_85 ( struct V_22 * V_22 )
{
F_25 ( & V_22 -> V_36 ) ;
F_86 ( & V_22 -> V_34 ) ;
return 0 ;
}
static int T_4 F_87 ( void )
{
int V_26 ;
F_88 ( V_138 , V_101 , F_43 , NULL , NULL ) ;
F_88 ( V_138 , V_105 , F_60 , NULL , NULL ) ;
F_88 ( V_138 , V_139 , NULL , F_73 , NULL ) ;
V_26 = F_89 ( & V_140 ) ;
if ( V_26 < 0 )
goto V_141;
V_26 = F_90 ( & V_142 ) ;
if ( V_26 < 0 )
goto V_143;
return 0 ;
V_143:
F_91 ( & V_140 ) ;
V_141:
F_92 ( V_138 , V_101 ) ;
F_92 ( V_138 , V_105 ) ;
F_92 ( V_138 , V_139 ) ;
return V_26 ;
}
