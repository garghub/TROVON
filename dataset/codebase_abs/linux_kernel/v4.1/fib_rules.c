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
V_7 -> V_14 = V_2 -> V_15 ;
V_7 -> V_16 = - 1 ;
V_7 -> V_17 = - 1 ;
F_4 ( & V_7 -> V_18 , & V_2 -> V_19 ) ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_6 * V_22 ;
if ( ! F_6 ( & V_2 -> V_19 ) ) {
V_21 = V_2 -> V_19 . V_23 ;
if ( V_21 -> V_23 != & V_2 -> V_19 ) {
V_22 = F_7 ( V_21 -> V_23 , struct V_6 , V_18 ) ;
if ( V_22 -> V_3 )
return V_22 -> V_3 - 1 ;
}
}
return 0 ;
}
static struct V_1 * F_8 ( struct V_24 * V_24 , int V_25 )
{
struct V_1 * V_2 ;
F_9 () ;
F_10 (ops, &net->rules_ops, list) {
if ( V_2 -> V_25 == V_25 ) {
if ( ! F_11 ( V_2 -> V_26 ) )
V_2 = NULL ;
F_12 () ;
return V_2 ;
}
}
F_12 () ;
return NULL ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 )
F_14 ( V_2 -> V_26 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_28 = - V_29 ;
struct V_1 * V_30 ;
struct V_24 * V_24 ;
V_24 = V_2 -> V_15 ;
if ( V_2 -> V_8 < sizeof( struct V_6 ) )
return - V_31 ;
if ( V_2 -> V_32 == NULL || V_2 -> V_33 == NULL ||
V_2 -> V_34 == NULL || V_2 -> V_35 == NULL ||
V_2 -> V_12 == NULL )
return - V_31 ;
F_17 ( & V_24 -> V_36 ) ;
F_18 (o, &net->rules_ops, list)
if ( V_2 -> V_25 == V_30 -> V_25 )
goto V_37;
F_19 ( & V_2 -> V_18 , & V_24 -> V_38 ) ;
V_28 = 0 ;
V_37:
F_20 ( & V_24 -> V_36 ) ;
return V_28 ;
}
struct V_1 *
F_21 ( const struct V_1 * V_39 , struct V_24 * V_24 )
{
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_22 ( V_39 , sizeof( * V_2 ) , V_9 ) ;
if ( V_2 == NULL )
return F_23 ( - V_10 ) ;
F_24 ( & V_2 -> V_19 ) ;
V_2 -> V_15 = V_24 ;
V_28 = F_16 ( V_2 ) ;
if ( V_28 ) {
F_25 ( V_2 ) ;
V_2 = F_23 ( V_28 ) ;
}
return V_2 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_22 , * V_40 ;
F_27 (rule, tmp, &ops->rules_list, list) {
F_28 ( & V_22 -> V_18 ) ;
if ( V_2 -> V_41 )
V_2 -> V_41 ( V_22 ) ;
F_29 ( V_22 ) ;
}
}
void F_30 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = V_2 -> V_15 ;
F_17 ( & V_24 -> V_36 ) ;
F_28 ( & V_2 -> V_18 ) ;
F_20 ( & V_24 -> V_36 ) ;
F_26 ( V_2 ) ;
F_31 ( V_2 , V_42 ) ;
}
static int F_32 ( struct V_6 * V_22 , struct V_1 * V_2 ,
struct V_43 * V_44 , int V_5 )
{
int V_45 = 0 ;
if ( V_22 -> V_46 && ( V_22 -> V_46 != V_44 -> V_47 ) )
goto V_48;
if ( V_22 -> V_49 && ( V_22 -> V_49 != V_44 -> V_50 ) )
goto V_48;
if ( ( V_22 -> V_51 ^ V_44 -> V_52 ) & V_22 -> V_53 )
goto V_48;
V_45 = V_2 -> V_32 ( V_22 , V_44 , V_5 ) ;
V_48:
return ( V_22 -> V_5 & V_54 ) ? ! V_45 : V_45 ;
}
int F_33 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int V_5 , struct V_55 * V_56 )
{
struct V_6 * V_22 ;
int V_28 ;
F_9 () ;
F_10 (rule, &ops->rules_list, list) {
V_57:
if ( ! F_32 ( V_22 , V_2 , V_44 , V_5 ) )
continue;
if ( V_22 -> V_12 == V_58 ) {
struct V_6 * V_59 ;
V_59 = F_34 ( V_22 -> V_60 ) ;
if ( V_59 == NULL ) {
continue;
} else {
V_22 = V_59 ;
goto V_57;
}
} else if ( V_22 -> V_12 == V_61 )
continue;
else
V_28 = V_2 -> V_12 ( V_22 , V_44 , V_5 , V_56 ) ;
if ( ! V_28 && V_2 -> V_62 && V_2 -> V_62 ( V_22 , V_56 ) )
continue;
if ( V_28 != - V_63 ) {
if ( ( V_56 -> V_5 & V_64 ) ||
F_35 ( F_36 ( & V_22 -> V_11 ) ) ) {
V_56 -> V_22 = V_22 ;
goto V_48;
}
break;
}
}
V_28 = - V_65 ;
V_48:
F_12 () ;
return V_28 ;
}
static int F_37 ( struct V_66 * V_67 , struct V_68 * * V_69 ,
struct V_1 * V_2 )
{
int V_28 = - V_31 ;
if ( V_67 -> V_70 )
if ( V_69 [ V_71 ] == NULL ||
V_67 -> V_70 > ( V_2 -> V_72 * 8 ) ||
F_38 ( V_69 [ V_71 ] ) != V_2 -> V_72 )
goto V_37;
if ( V_67 -> V_73 )
if ( V_69 [ V_74 ] == NULL ||
V_67 -> V_73 > ( V_2 -> V_72 * 8 ) ||
F_38 ( V_69 [ V_74 ] ) != V_2 -> V_72 )
goto V_37;
V_28 = 0 ;
V_37:
return V_28 ;
}
static int F_39 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_24 * V_24 = F_40 ( V_76 -> V_79 ) ;
struct V_66 * V_67 = F_41 ( V_78 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_22 , * V_7 , * V_80 = NULL ;
struct V_68 * V_69 [ V_81 + 1 ] ;
int V_28 = - V_31 , V_82 = 0 ;
if ( V_78 -> V_83 < F_42 ( sizeof( * V_67 ) ) )
goto V_37;
V_2 = F_8 ( V_24 , V_67 -> V_25 ) ;
if ( V_2 == NULL ) {
V_28 = - V_84 ;
goto V_37;
}
V_28 = F_43 ( V_78 , sizeof( * V_67 ) , V_69 , V_81 , V_2 -> V_85 ) ;
if ( V_28 < 0 )
goto V_37;
V_28 = F_37 ( V_67 , V_69 , V_2 ) ;
if ( V_28 < 0 )
goto V_37;
V_22 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_22 == NULL ) {
V_28 = - V_10 ;
goto V_37;
}
V_22 -> V_14 = V_24 ;
if ( V_69 [ V_86 ] )
V_22 -> V_3 = F_44 ( V_69 [ V_86 ] ) ;
if ( V_69 [ V_87 ] ) {
struct V_88 * V_89 ;
V_22 -> V_46 = - 1 ;
F_45 ( V_22 -> V_90 , V_69 [ V_87 ] , V_91 ) ;
V_89 = F_46 ( V_24 , V_22 -> V_90 ) ;
if ( V_89 )
V_22 -> V_46 = V_89 -> V_92 ;
}
if ( V_69 [ V_93 ] ) {
struct V_88 * V_89 ;
V_22 -> V_49 = - 1 ;
F_45 ( V_22 -> V_94 , V_69 [ V_93 ] , V_91 ) ;
V_89 = F_46 ( V_24 , V_22 -> V_94 ) ;
if ( V_89 )
V_22 -> V_49 = V_89 -> V_92 ;
}
if ( V_69 [ V_95 ] ) {
V_22 -> V_51 = F_44 ( V_69 [ V_95 ] ) ;
if ( V_22 -> V_51 )
V_22 -> V_53 = 0xFFFFFFFF ;
}
if ( V_69 [ V_96 ] )
V_22 -> V_53 = F_44 ( V_69 [ V_96 ] ) ;
V_22 -> V_12 = V_67 -> V_12 ;
V_22 -> V_5 = V_67 -> V_5 ;
V_22 -> V_4 = F_47 ( V_67 , V_69 ) ;
if ( V_69 [ V_97 ] )
V_22 -> V_16 = F_44 ( V_69 [ V_97 ] ) ;
else
V_22 -> V_16 = - 1 ;
if ( V_69 [ V_98 ] )
V_22 -> V_17 = F_44 ( V_69 [ V_98 ] ) ;
else
V_22 -> V_17 = - 1 ;
if ( ! V_69 [ V_86 ] && V_2 -> V_99 )
V_22 -> V_3 = V_2 -> V_99 ( V_2 ) ;
V_28 = - V_31 ;
if ( V_69 [ V_100 ] ) {
if ( V_22 -> V_12 != V_58 )
goto V_101;
V_22 -> V_59 = F_44 ( V_69 [ V_100 ] ) ;
if ( V_22 -> V_59 <= V_22 -> V_3 )
goto V_101;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 == V_22 -> V_59 ) {
F_48 ( V_22 -> V_60 , V_7 ) ;
break;
}
}
if ( F_49 ( V_22 -> V_60 , 1 ) == NULL )
V_82 = 1 ;
} else if ( V_22 -> V_12 == V_58 )
goto V_101;
V_28 = V_2 -> V_33 ( V_22 , V_76 , V_67 , V_69 ) ;
if ( V_28 < 0 )
goto V_101;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 > V_22 -> V_3 )
break;
V_80 = V_7 ;
}
F_50 ( V_22 ) ;
if ( V_80 )
F_51 ( & V_22 -> V_18 , & V_80 -> V_18 ) ;
else
F_51 ( & V_22 -> V_18 , & V_2 -> V_19 ) ;
if ( V_2 -> V_102 ) {
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 == V_58 &&
V_7 -> V_59 == V_22 -> V_3 &&
F_52 ( V_7 -> V_60 ) == NULL ) {
F_53 ( V_7 -> V_60 , V_22 ) ;
if ( -- V_2 -> V_102 == 0 )
break;
}
}
}
if ( V_22 -> V_12 == V_58 )
V_2 -> V_103 ++ ;
if ( V_82 )
V_2 -> V_102 ++ ;
F_54 ( V_104 , V_22 , V_2 , V_78 , F_55 ( V_76 ) . V_105 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
V_101:
F_25 ( V_22 ) ;
V_37:
F_13 ( V_2 ) ;
return V_28 ;
}
static int F_56 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_24 * V_24 = F_40 ( V_76 -> V_79 ) ;
struct V_66 * V_67 = F_41 ( V_78 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_22 , * V_40 ;
struct V_68 * V_69 [ V_81 + 1 ] ;
int V_28 = - V_31 ;
if ( V_78 -> V_83 < F_42 ( sizeof( * V_67 ) ) )
goto V_37;
V_2 = F_8 ( V_24 , V_67 -> V_25 ) ;
if ( V_2 == NULL ) {
V_28 = - V_84 ;
goto V_37;
}
V_28 = F_43 ( V_78 , sizeof( * V_67 ) , V_69 , V_81 , V_2 -> V_85 ) ;
if ( V_28 < 0 )
goto V_37;
V_28 = F_37 ( V_67 , V_69 , V_2 ) ;
if ( V_28 < 0 )
goto V_37;
F_18 (rule, &ops->rules_list, list) {
if ( V_67 -> V_12 && ( V_67 -> V_12 != V_22 -> V_12 ) )
continue;
if ( F_47 ( V_67 , V_69 ) &&
( F_47 ( V_67 , V_69 ) != V_22 -> V_4 ) )
continue;
if ( V_69 [ V_86 ] &&
( V_22 -> V_3 != F_44 ( V_69 [ V_86 ] ) ) )
continue;
if ( V_69 [ V_87 ] &&
F_57 ( V_69 [ V_87 ] , V_22 -> V_90 ) )
continue;
if ( V_69 [ V_93 ] &&
F_57 ( V_69 [ V_93 ] , V_22 -> V_94 ) )
continue;
if ( V_69 [ V_95 ] &&
( V_22 -> V_51 != F_44 ( V_69 [ V_95 ] ) ) )
continue;
if ( V_69 [ V_96 ] &&
( V_22 -> V_53 != F_44 ( V_69 [ V_96 ] ) ) )
continue;
if ( ! V_2 -> V_34 ( V_22 , V_67 , V_69 ) )
continue;
if ( V_22 -> V_5 & V_106 ) {
V_28 = - V_107 ;
goto V_37;
}
if ( V_2 -> V_41 ) {
V_28 = V_2 -> V_41 ( V_22 ) ;
if ( V_28 )
goto V_37;
}
F_28 ( & V_22 -> V_18 ) ;
if ( V_22 -> V_12 == V_58 ) {
V_2 -> V_103 -- ;
if ( F_52 ( V_22 -> V_60 ) == NULL )
V_2 -> V_102 -- ;
}
if ( V_2 -> V_103 > 0 ) {
F_18 (tmp, &ops->rules_list, list) {
if ( F_52 ( V_40 -> V_60 ) == V_22 ) {
F_48 ( V_40 -> V_60 , NULL ) ;
V_2 -> V_102 ++ ;
}
}
}
F_54 ( V_108 , V_22 , V_2 , V_78 ,
F_55 ( V_76 ) . V_105 ) ;
F_29 ( V_22 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
V_28 = - V_109 ;
V_37:
F_13 ( V_2 ) ;
return V_28 ;
}
static inline T_2 F_58 ( struct V_1 * V_2 ,
struct V_6 * V_22 )
{
T_2 V_110 = F_59 ( sizeof( struct V_66 ) )
+ F_60 ( V_91 )
+ F_60 ( V_91 )
+ F_60 ( 4 )
+ F_60 ( 4 )
+ F_60 ( 4 )
+ F_60 ( 4 )
+ F_60 ( 4 )
+ F_60 ( 4 ) ;
if ( V_2 -> V_111 )
V_110 += V_2 -> V_111 ( V_22 ) ;
return V_110 ;
}
static int F_61 ( struct V_75 * V_76 , struct V_6 * V_22 ,
T_1 V_112 , T_1 V_113 , int type , int V_5 ,
struct V_1 * V_2 )
{
struct V_77 * V_78 ;
struct V_66 * V_67 ;
V_78 = F_62 ( V_76 , V_112 , V_113 , type , sizeof( * V_67 ) , V_5 ) ;
if ( V_78 == NULL )
return - V_114 ;
V_67 = F_41 ( V_78 ) ;
V_67 -> V_25 = V_2 -> V_25 ;
V_67 -> V_4 = V_22 -> V_4 ;
if ( F_63 ( V_76 , V_115 , V_22 -> V_4 ) )
goto V_116;
if ( F_63 ( V_76 , V_97 , V_22 -> V_16 ) )
goto V_116;
V_67 -> V_117 = 0 ;
V_67 -> V_118 = 0 ;
V_67 -> V_12 = V_22 -> V_12 ;
V_67 -> V_5 = V_22 -> V_5 ;
if ( V_22 -> V_12 == V_58 &&
F_64 ( V_22 -> V_60 ) == NULL )
V_67 -> V_5 |= V_119 ;
if ( V_22 -> V_90 [ 0 ] ) {
if ( F_65 ( V_76 , V_87 , V_22 -> V_90 ) )
goto V_116;
if ( V_22 -> V_46 == - 1 )
V_67 -> V_5 |= V_120 ;
}
if ( V_22 -> V_94 [ 0 ] ) {
if ( F_65 ( V_76 , V_93 , V_22 -> V_94 ) )
goto V_116;
if ( V_22 -> V_49 == - 1 )
V_67 -> V_5 |= V_121 ;
}
if ( ( V_22 -> V_3 &&
F_63 ( V_76 , V_86 , V_22 -> V_3 ) ) ||
( V_22 -> V_51 &&
F_63 ( V_76 , V_95 , V_22 -> V_51 ) ) ||
( ( V_22 -> V_53 || V_22 -> V_51 ) &&
F_63 ( V_76 , V_96 , V_22 -> V_53 ) ) ||
( V_22 -> V_59 &&
F_63 ( V_76 , V_100 , V_22 -> V_59 ) ) )
goto V_116;
if ( V_22 -> V_17 != - 1 ) {
if ( F_63 ( V_76 , V_98 , V_22 -> V_17 ) )
goto V_116;
}
if ( V_2 -> V_35 ( V_22 , V_76 , V_67 ) < 0 )
goto V_116;
F_66 ( V_76 , V_78 ) ;
return 0 ;
V_116:
F_67 ( V_76 , V_78 ) ;
return - V_114 ;
}
static int F_68 ( struct V_75 * V_76 , struct V_122 * V_123 ,
struct V_1 * V_2 )
{
int V_124 = 0 ;
struct V_6 * V_22 ;
F_9 () ;
F_10 (rule, &ops->rules_list, list) {
if ( V_124 < V_123 -> args [ 1 ] )
goto V_125;
if ( F_61 ( V_76 , V_22 , F_55 ( V_123 -> V_76 ) . V_105 ,
V_123 -> V_78 -> V_126 , V_104 ,
V_127 , V_2 ) < 0 )
break;
V_125:
V_124 ++ ;
}
F_12 () ;
V_123 -> args [ 1 ] = V_124 ;
F_13 ( V_2 ) ;
return V_76 -> V_128 ;
}
static int F_69 ( struct V_75 * V_76 , struct V_122 * V_123 )
{
struct V_24 * V_24 = F_40 ( V_76 -> V_79 ) ;
struct V_1 * V_2 ;
int V_124 = 0 , V_25 ;
V_25 = F_70 ( V_123 -> V_78 ) ;
if ( V_25 != V_129 ) {
V_2 = F_8 ( V_24 , V_25 ) ;
if ( V_2 == NULL )
return - V_84 ;
return F_68 ( V_76 , V_123 , V_2 ) ;
}
F_9 () ;
F_10 (ops, &net->rules_ops, list) {
if ( V_124 < V_123 -> args [ 0 ] || ! F_11 ( V_2 -> V_26 ) )
goto V_125;
if ( F_68 ( V_76 , V_123 , V_2 ) < 0 )
break;
V_123 -> args [ 1 ] = 0 ;
V_125:
V_124 ++ ;
}
F_12 () ;
V_123 -> args [ 0 ] = V_124 ;
return V_76 -> V_128 ;
}
static void F_54 ( int V_130 , struct V_6 * V_22 ,
struct V_1 * V_2 , struct V_77 * V_78 ,
T_1 V_112 )
{
struct V_24 * V_24 ;
struct V_75 * V_76 ;
int V_28 = - V_131 ;
V_24 = V_2 -> V_15 ;
V_76 = F_71 ( F_58 ( V_2 , V_22 ) , V_9 ) ;
if ( V_76 == NULL )
goto V_37;
V_28 = F_61 ( V_76 , V_22 , V_112 , V_78 -> V_126 , V_130 , 0 , V_2 ) ;
if ( V_28 < 0 ) {
F_72 ( V_28 == - V_114 ) ;
F_73 ( V_76 ) ;
goto V_37;
}
F_74 ( V_76 , V_24 , V_112 , V_2 -> V_132 , V_78 , V_9 ) ;
return;
V_37:
if ( V_28 < 0 )
F_75 ( V_24 , V_2 -> V_132 , V_28 ) ;
}
static void F_76 ( struct V_20 * V_133 , struct V_88 * V_89 )
{
struct V_6 * V_22 ;
F_18 (rule, rules, list) {
if ( V_22 -> V_46 == - 1 &&
strcmp ( V_89 -> V_134 , V_22 -> V_90 ) == 0 )
V_22 -> V_46 = V_89 -> V_92 ;
if ( V_22 -> V_49 == - 1 &&
strcmp ( V_89 -> V_134 , V_22 -> V_94 ) == 0 )
V_22 -> V_49 = V_89 -> V_92 ;
}
}
static void F_77 ( struct V_20 * V_133 , struct V_88 * V_89 )
{
struct V_6 * V_22 ;
F_18 (rule, rules, list) {
if ( V_22 -> V_46 == V_89 -> V_92 )
V_22 -> V_46 = - 1 ;
if ( V_22 -> V_49 == V_89 -> V_92 )
V_22 -> V_49 = - 1 ;
}
}
static int F_78 ( struct V_135 * V_136 , unsigned long V_130 ,
void * V_137 )
{
struct V_88 * V_89 = F_79 ( V_137 ) ;
struct V_24 * V_24 = F_80 ( V_89 ) ;
struct V_1 * V_2 ;
F_81 () ;
switch ( V_130 ) {
case V_138 :
F_18 (ops, &net->rules_ops, list)
F_76 ( & V_2 -> V_19 , V_89 ) ;
break;
case V_139 :
F_18 (ops, &net->rules_ops, list) {
F_77 ( & V_2 -> V_19 , V_89 ) ;
F_76 ( & V_2 -> V_19 , V_89 ) ;
}
break;
case V_140 :
F_18 (ops, &net->rules_ops, list)
F_77 ( & V_2 -> V_19 , V_89 ) ;
break;
}
return V_141 ;
}
static int T_3 F_82 ( struct V_24 * V_24 )
{
F_24 ( & V_24 -> V_38 ) ;
F_83 ( & V_24 -> V_36 ) ;
return 0 ;
}
static int T_4 F_84 ( void )
{
int V_28 ;
F_85 ( V_142 , V_104 , F_39 , NULL , NULL ) ;
F_85 ( V_142 , V_108 , F_56 , NULL , NULL ) ;
F_85 ( V_142 , V_143 , NULL , F_69 , NULL ) ;
V_28 = F_86 ( & V_144 ) ;
if ( V_28 < 0 )
goto V_145;
V_28 = F_87 ( & V_146 ) ;
if ( V_28 < 0 )
goto V_147;
return 0 ;
V_147:
F_88 ( & V_144 ) ;
V_145:
F_89 ( V_142 , V_104 ) ;
F_89 ( V_142 , V_108 ) ;
F_89 ( V_142 , V_143 ) ;
return V_28 ;
}
