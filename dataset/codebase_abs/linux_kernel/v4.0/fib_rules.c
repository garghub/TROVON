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
V_7 -> V_16 = - 1 ;
V_7 -> V_17 = - 1 ;
F_5 ( & V_7 -> V_18 , & V_2 -> V_19 ) ;
return 0 ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_6 * V_22 ;
if ( ! F_7 ( & V_2 -> V_19 ) ) {
V_21 = V_2 -> V_19 . V_23 ;
if ( V_21 -> V_23 != & V_2 -> V_19 ) {
V_22 = F_8 ( V_21 -> V_23 , struct V_6 , V_18 ) ;
if ( V_22 -> V_3 )
return V_22 -> V_3 - 1 ;
}
}
return 0 ;
}
static struct V_1 * F_9 ( struct V_24 * V_24 , int V_25 )
{
struct V_1 * V_2 ;
F_10 () ;
F_11 (ops, &net->rules_ops, list) {
if ( V_2 -> V_25 == V_25 ) {
if ( ! F_12 ( V_2 -> V_26 ) )
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
F_15 ( V_2 -> V_26 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 )
V_2 -> V_27 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
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
F_18 ( & V_24 -> V_36 ) ;
F_19 (o, &net->rules_ops, list)
if ( V_2 -> V_25 == V_30 -> V_25 )
goto V_37;
F_4 ( V_24 ) ;
F_20 ( & V_2 -> V_18 , & V_24 -> V_38 ) ;
V_28 = 0 ;
V_37:
F_21 ( & V_24 -> V_36 ) ;
return V_28 ;
}
struct V_1 *
F_22 ( const struct V_1 * V_39 , struct V_24 * V_24 )
{
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_23 ( V_39 , sizeof( * V_2 ) , V_9 ) ;
if ( V_2 == NULL )
return F_24 ( - V_10 ) ;
F_25 ( & V_2 -> V_19 ) ;
V_2 -> V_15 = V_24 ;
V_28 = F_17 ( V_2 ) ;
if ( V_28 ) {
F_26 ( V_2 ) ;
V_2 = F_24 ( V_28 ) ;
}
return V_2 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_22 , * V_40 ;
F_28 (rule, tmp, &ops->rules_list, list) {
F_29 ( & V_22 -> V_18 ) ;
if ( V_2 -> V_41 )
V_2 -> V_41 ( V_22 ) ;
F_30 ( V_22 ) ;
}
}
static void F_31 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_32 ( V_43 , struct V_1 , V_44 ) ;
struct V_24 * V_24 = V_2 -> V_15 ;
F_33 ( V_24 ) ;
F_26 ( V_2 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = V_2 -> V_15 ;
F_18 ( & V_24 -> V_36 ) ;
F_29 ( & V_2 -> V_18 ) ;
F_21 ( & V_24 -> V_36 ) ;
F_27 ( V_2 ) ;
F_35 ( & V_2 -> V_44 , F_31 ) ;
}
static int F_36 ( struct V_6 * V_22 , struct V_1 * V_2 ,
struct V_45 * V_46 , int V_5 )
{
int V_47 = 0 ;
if ( V_22 -> V_48 && ( V_22 -> V_48 != V_46 -> V_49 ) )
goto V_50;
if ( V_22 -> V_51 && ( V_22 -> V_51 != V_46 -> V_52 ) )
goto V_50;
if ( ( V_22 -> V_53 ^ V_46 -> V_54 ) & V_22 -> V_55 )
goto V_50;
V_47 = V_2 -> V_32 ( V_22 , V_46 , V_5 ) ;
V_50:
return ( V_22 -> V_5 & V_56 ) ? ! V_47 : V_47 ;
}
int F_37 ( struct V_1 * V_2 , struct V_45 * V_46 ,
int V_5 , struct V_57 * V_58 )
{
struct V_6 * V_22 ;
int V_28 ;
F_10 () ;
F_11 (rule, &ops->rules_list, list) {
V_59:
if ( ! F_36 ( V_22 , V_2 , V_46 , V_5 ) )
continue;
if ( V_22 -> V_12 == V_60 ) {
struct V_6 * V_61 ;
V_61 = F_38 ( V_22 -> V_62 ) ;
if ( V_61 == NULL ) {
continue;
} else {
V_22 = V_61 ;
goto V_59;
}
} else if ( V_22 -> V_12 == V_63 )
continue;
else
V_28 = V_2 -> V_12 ( V_22 , V_46 , V_5 , V_58 ) ;
if ( ! V_28 && V_2 -> V_64 && V_2 -> V_64 ( V_22 , V_58 ) )
continue;
if ( V_28 != - V_65 ) {
if ( ( V_58 -> V_5 & V_66 ) ||
F_39 ( F_40 ( & V_22 -> V_11 ) ) ) {
V_58 -> V_22 = V_22 ;
goto V_50;
}
break;
}
}
V_28 = - V_67 ;
V_50:
F_13 () ;
return V_28 ;
}
static int F_41 ( struct V_68 * V_69 , struct V_70 * * V_71 ,
struct V_1 * V_2 )
{
int V_28 = - V_31 ;
if ( V_69 -> V_72 )
if ( V_71 [ V_73 ] == NULL ||
V_69 -> V_72 > ( V_2 -> V_74 * 8 ) ||
F_42 ( V_71 [ V_73 ] ) != V_2 -> V_74 )
goto V_37;
if ( V_69 -> V_75 )
if ( V_71 [ V_76 ] == NULL ||
V_69 -> V_75 > ( V_2 -> V_74 * 8 ) ||
F_42 ( V_71 [ V_76 ] ) != V_2 -> V_74 )
goto V_37;
V_28 = 0 ;
V_37:
return V_28 ;
}
static int F_43 ( struct V_77 * V_78 , struct V_79 * V_80 )
{
struct V_24 * V_24 = F_44 ( V_78 -> V_81 ) ;
struct V_68 * V_69 = F_45 ( V_80 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_22 , * V_7 , * V_82 = NULL ;
struct V_70 * V_71 [ V_83 + 1 ] ;
int V_28 = - V_31 , V_84 = 0 ;
if ( V_80 -> V_85 < F_46 ( sizeof( * V_69 ) ) )
goto V_37;
V_2 = F_9 ( V_24 , V_69 -> V_25 ) ;
if ( V_2 == NULL ) {
V_28 = - V_86 ;
goto V_37;
}
V_28 = F_47 ( V_80 , sizeof( * V_69 ) , V_71 , V_83 , V_2 -> V_87 ) ;
if ( V_28 < 0 )
goto V_37;
V_28 = F_41 ( V_69 , V_71 , V_2 ) ;
if ( V_28 < 0 )
goto V_37;
V_22 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_22 == NULL ) {
V_28 = - V_10 ;
goto V_37;
}
V_22 -> V_14 = F_4 ( V_24 ) ;
if ( V_71 [ V_88 ] )
V_22 -> V_3 = F_48 ( V_71 [ V_88 ] ) ;
if ( V_71 [ V_89 ] ) {
struct V_90 * V_91 ;
V_22 -> V_48 = - 1 ;
F_49 ( V_22 -> V_92 , V_71 [ V_89 ] , V_93 ) ;
V_91 = F_50 ( V_24 , V_22 -> V_92 ) ;
if ( V_91 )
V_22 -> V_48 = V_91 -> V_94 ;
}
if ( V_71 [ V_95 ] ) {
struct V_90 * V_91 ;
V_22 -> V_51 = - 1 ;
F_49 ( V_22 -> V_96 , V_71 [ V_95 ] , V_93 ) ;
V_91 = F_50 ( V_24 , V_22 -> V_96 ) ;
if ( V_91 )
V_22 -> V_51 = V_91 -> V_94 ;
}
if ( V_71 [ V_97 ] ) {
V_22 -> V_53 = F_48 ( V_71 [ V_97 ] ) ;
if ( V_22 -> V_53 )
V_22 -> V_55 = 0xFFFFFFFF ;
}
if ( V_71 [ V_98 ] )
V_22 -> V_55 = F_48 ( V_71 [ V_98 ] ) ;
V_22 -> V_12 = V_69 -> V_12 ;
V_22 -> V_5 = V_69 -> V_5 ;
V_22 -> V_4 = F_51 ( V_69 , V_71 ) ;
if ( V_71 [ V_99 ] )
V_22 -> V_16 = F_48 ( V_71 [ V_99 ] ) ;
else
V_22 -> V_16 = - 1 ;
if ( V_71 [ V_100 ] )
V_22 -> V_17 = F_48 ( V_71 [ V_100 ] ) ;
else
V_22 -> V_17 = - 1 ;
if ( ! V_71 [ V_88 ] && V_2 -> V_101 )
V_22 -> V_3 = V_2 -> V_101 ( V_2 ) ;
V_28 = - V_31 ;
if ( V_71 [ V_102 ] ) {
if ( V_22 -> V_12 != V_60 )
goto V_103;
V_22 -> V_61 = F_48 ( V_71 [ V_102 ] ) ;
if ( V_22 -> V_61 <= V_22 -> V_3 )
goto V_103;
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 == V_22 -> V_61 ) {
F_52 ( V_22 -> V_62 , V_7 ) ;
break;
}
}
if ( F_53 ( V_22 -> V_62 , 1 ) == NULL )
V_84 = 1 ;
} else if ( V_22 -> V_12 == V_60 )
goto V_103;
V_28 = V_2 -> V_33 ( V_22 , V_78 , V_69 , V_71 ) ;
if ( V_28 < 0 )
goto V_103;
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 > V_22 -> V_3 )
break;
V_82 = V_7 ;
}
F_54 ( V_22 ) ;
if ( V_82 )
F_55 ( & V_22 -> V_18 , & V_82 -> V_18 ) ;
else
F_55 ( & V_22 -> V_18 , & V_2 -> V_19 ) ;
if ( V_2 -> V_104 ) {
F_19 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 == V_60 &&
V_7 -> V_61 == V_22 -> V_3 &&
F_56 ( V_7 -> V_62 ) == NULL ) {
F_57 ( V_7 -> V_62 , V_22 ) ;
if ( -- V_2 -> V_104 == 0 )
break;
}
}
}
if ( V_22 -> V_12 == V_60 )
V_2 -> V_105 ++ ;
if ( V_84 )
V_2 -> V_104 ++ ;
F_58 ( V_106 , V_22 , V_2 , V_80 , F_59 ( V_78 ) . V_107 ) ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
V_103:
F_33 ( V_22 -> V_14 ) ;
F_26 ( V_22 ) ;
V_37:
F_14 ( V_2 ) ;
return V_28 ;
}
static int F_60 ( struct V_77 * V_78 , struct V_79 * V_80 )
{
struct V_24 * V_24 = F_44 ( V_78 -> V_81 ) ;
struct V_68 * V_69 = F_45 ( V_80 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_22 , * V_40 ;
struct V_70 * V_71 [ V_83 + 1 ] ;
int V_28 = - V_31 ;
if ( V_80 -> V_85 < F_46 ( sizeof( * V_69 ) ) )
goto V_37;
V_2 = F_9 ( V_24 , V_69 -> V_25 ) ;
if ( V_2 == NULL ) {
V_28 = - V_86 ;
goto V_37;
}
V_28 = F_47 ( V_80 , sizeof( * V_69 ) , V_71 , V_83 , V_2 -> V_87 ) ;
if ( V_28 < 0 )
goto V_37;
V_28 = F_41 ( V_69 , V_71 , V_2 ) ;
if ( V_28 < 0 )
goto V_37;
F_19 (rule, &ops->rules_list, list) {
if ( V_69 -> V_12 && ( V_69 -> V_12 != V_22 -> V_12 ) )
continue;
if ( F_51 ( V_69 , V_71 ) &&
( F_51 ( V_69 , V_71 ) != V_22 -> V_4 ) )
continue;
if ( V_71 [ V_88 ] &&
( V_22 -> V_3 != F_48 ( V_71 [ V_88 ] ) ) )
continue;
if ( V_71 [ V_89 ] &&
F_61 ( V_71 [ V_89 ] , V_22 -> V_92 ) )
continue;
if ( V_71 [ V_95 ] &&
F_61 ( V_71 [ V_95 ] , V_22 -> V_96 ) )
continue;
if ( V_71 [ V_97 ] &&
( V_22 -> V_53 != F_48 ( V_71 [ V_97 ] ) ) )
continue;
if ( V_71 [ V_98 ] &&
( V_22 -> V_55 != F_48 ( V_71 [ V_98 ] ) ) )
continue;
if ( ! V_2 -> V_34 ( V_22 , V_69 , V_71 ) )
continue;
if ( V_22 -> V_5 & V_108 ) {
V_28 = - V_109 ;
goto V_37;
}
F_29 ( & V_22 -> V_18 ) ;
if ( V_22 -> V_12 == V_60 ) {
V_2 -> V_105 -- ;
if ( F_56 ( V_22 -> V_62 ) == NULL )
V_2 -> V_104 -- ;
}
if ( V_2 -> V_105 > 0 ) {
F_19 (tmp, &ops->rules_list, list) {
if ( F_56 ( V_40 -> V_62 ) == V_22 ) {
F_52 ( V_40 -> V_62 , NULL ) ;
V_2 -> V_104 ++ ;
}
}
}
F_58 ( V_110 , V_22 , V_2 , V_80 ,
F_59 ( V_78 ) . V_107 ) ;
if ( V_2 -> V_41 )
V_2 -> V_41 ( V_22 ) ;
F_30 ( V_22 ) ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
V_28 = - V_111 ;
V_37:
F_14 ( V_2 ) ;
return V_28 ;
}
static inline T_2 F_62 ( struct V_1 * V_2 ,
struct V_6 * V_22 )
{
T_2 V_112 = F_63 ( sizeof( struct V_68 ) )
+ F_64 ( V_93 )
+ F_64 ( V_93 )
+ F_64 ( 4 )
+ F_64 ( 4 )
+ F_64 ( 4 )
+ F_64 ( 4 )
+ F_64 ( 4 )
+ F_64 ( 4 ) ;
if ( V_2 -> V_113 )
V_112 += V_2 -> V_113 ( V_22 ) ;
return V_112 ;
}
static int F_65 ( struct V_77 * V_78 , struct V_6 * V_22 ,
T_1 V_114 , T_1 V_115 , int type , int V_5 ,
struct V_1 * V_2 )
{
struct V_79 * V_80 ;
struct V_68 * V_69 ;
V_80 = F_66 ( V_78 , V_114 , V_115 , type , sizeof( * V_69 ) , V_5 ) ;
if ( V_80 == NULL )
return - V_116 ;
V_69 = F_45 ( V_80 ) ;
V_69 -> V_25 = V_2 -> V_25 ;
V_69 -> V_4 = V_22 -> V_4 ;
if ( F_67 ( V_78 , V_117 , V_22 -> V_4 ) )
goto V_118;
if ( F_67 ( V_78 , V_99 , V_22 -> V_16 ) )
goto V_118;
V_69 -> V_119 = 0 ;
V_69 -> V_120 = 0 ;
V_69 -> V_12 = V_22 -> V_12 ;
V_69 -> V_5 = V_22 -> V_5 ;
if ( V_22 -> V_12 == V_60 &&
F_68 ( V_22 -> V_62 ) == NULL )
V_69 -> V_5 |= V_121 ;
if ( V_22 -> V_92 [ 0 ] ) {
if ( F_69 ( V_78 , V_89 , V_22 -> V_92 ) )
goto V_118;
if ( V_22 -> V_48 == - 1 )
V_69 -> V_5 |= V_122 ;
}
if ( V_22 -> V_96 [ 0 ] ) {
if ( F_69 ( V_78 , V_95 , V_22 -> V_96 ) )
goto V_118;
if ( V_22 -> V_51 == - 1 )
V_69 -> V_5 |= V_123 ;
}
if ( ( V_22 -> V_3 &&
F_67 ( V_78 , V_88 , V_22 -> V_3 ) ) ||
( V_22 -> V_53 &&
F_67 ( V_78 , V_97 , V_22 -> V_53 ) ) ||
( ( V_22 -> V_55 || V_22 -> V_53 ) &&
F_67 ( V_78 , V_98 , V_22 -> V_55 ) ) ||
( V_22 -> V_61 &&
F_67 ( V_78 , V_102 , V_22 -> V_61 ) ) )
goto V_118;
if ( V_22 -> V_17 != - 1 ) {
if ( F_67 ( V_78 , V_100 , V_22 -> V_17 ) )
goto V_118;
}
if ( V_2 -> V_35 ( V_22 , V_78 , V_69 ) < 0 )
goto V_118;
F_70 ( V_78 , V_80 ) ;
return 0 ;
V_118:
F_71 ( V_78 , V_80 ) ;
return - V_116 ;
}
static int F_72 ( struct V_77 * V_78 , struct V_124 * V_125 ,
struct V_1 * V_2 )
{
int V_126 = 0 ;
struct V_6 * V_22 ;
F_10 () ;
F_11 (rule, &ops->rules_list, list) {
if ( V_126 < V_125 -> args [ 1 ] )
goto V_127;
if ( F_65 ( V_78 , V_22 , F_59 ( V_125 -> V_78 ) . V_107 ,
V_125 -> V_80 -> V_128 , V_106 ,
V_129 , V_2 ) < 0 )
break;
V_127:
V_126 ++ ;
}
F_13 () ;
V_125 -> args [ 1 ] = V_126 ;
F_14 ( V_2 ) ;
return V_78 -> V_130 ;
}
static int F_73 ( struct V_77 * V_78 , struct V_124 * V_125 )
{
struct V_24 * V_24 = F_44 ( V_78 -> V_81 ) ;
struct V_1 * V_2 ;
int V_126 = 0 , V_25 ;
V_25 = F_74 ( V_125 -> V_80 ) ;
if ( V_25 != V_131 ) {
V_2 = F_9 ( V_24 , V_25 ) ;
if ( V_2 == NULL )
return - V_86 ;
return F_72 ( V_78 , V_125 , V_2 ) ;
}
F_10 () ;
F_11 (ops, &net->rules_ops, list) {
if ( V_126 < V_125 -> args [ 0 ] || ! F_12 ( V_2 -> V_26 ) )
goto V_127;
if ( F_72 ( V_78 , V_125 , V_2 ) < 0 )
break;
V_125 -> args [ 1 ] = 0 ;
V_127:
V_126 ++ ;
}
F_13 () ;
V_125 -> args [ 0 ] = V_126 ;
return V_78 -> V_130 ;
}
static void F_58 ( int V_132 , struct V_6 * V_22 ,
struct V_1 * V_2 , struct V_79 * V_80 ,
T_1 V_114 )
{
struct V_24 * V_24 ;
struct V_77 * V_78 ;
int V_28 = - V_133 ;
V_24 = V_2 -> V_15 ;
V_78 = F_75 ( F_62 ( V_2 , V_22 ) , V_9 ) ;
if ( V_78 == NULL )
goto V_37;
V_28 = F_65 ( V_78 , V_22 , V_114 , V_80 -> V_128 , V_132 , 0 , V_2 ) ;
if ( V_28 < 0 ) {
F_76 ( V_28 == - V_116 ) ;
F_77 ( V_78 ) ;
goto V_37;
}
F_78 ( V_78 , V_24 , V_114 , V_2 -> V_134 , V_80 , V_9 ) ;
return;
V_37:
if ( V_28 < 0 )
F_79 ( V_24 , V_2 -> V_134 , V_28 ) ;
}
static void F_80 ( struct V_20 * V_135 , struct V_90 * V_91 )
{
struct V_6 * V_22 ;
F_19 (rule, rules, list) {
if ( V_22 -> V_48 == - 1 &&
strcmp ( V_91 -> V_136 , V_22 -> V_92 ) == 0 )
V_22 -> V_48 = V_91 -> V_94 ;
if ( V_22 -> V_51 == - 1 &&
strcmp ( V_91 -> V_136 , V_22 -> V_96 ) == 0 )
V_22 -> V_51 = V_91 -> V_94 ;
}
}
static void F_81 ( struct V_20 * V_135 , struct V_90 * V_91 )
{
struct V_6 * V_22 ;
F_19 (rule, rules, list) {
if ( V_22 -> V_48 == V_91 -> V_94 )
V_22 -> V_48 = - 1 ;
if ( V_22 -> V_51 == V_91 -> V_94 )
V_22 -> V_51 = - 1 ;
}
}
static int F_82 ( struct V_137 * V_138 , unsigned long V_132 ,
void * V_139 )
{
struct V_90 * V_91 = F_83 ( V_139 ) ;
struct V_24 * V_24 = F_84 ( V_91 ) ;
struct V_1 * V_2 ;
F_85 () ;
switch ( V_132 ) {
case V_140 :
F_19 (ops, &net->rules_ops, list)
F_80 ( & V_2 -> V_19 , V_91 ) ;
break;
case V_141 :
F_19 (ops, &net->rules_ops, list) {
F_81 ( & V_2 -> V_19 , V_91 ) ;
F_80 ( & V_2 -> V_19 , V_91 ) ;
}
break;
case V_142 :
F_19 (ops, &net->rules_ops, list)
F_81 ( & V_2 -> V_19 , V_91 ) ;
break;
}
return V_143 ;
}
static int T_3 F_86 ( struct V_24 * V_24 )
{
F_25 ( & V_24 -> V_38 ) ;
F_87 ( & V_24 -> V_36 ) ;
return 0 ;
}
static int T_4 F_88 ( void )
{
int V_28 ;
F_89 ( V_144 , V_106 , F_43 , NULL , NULL ) ;
F_89 ( V_144 , V_110 , F_60 , NULL , NULL ) ;
F_89 ( V_144 , V_145 , NULL , F_73 , NULL ) ;
V_28 = F_90 ( & V_146 ) ;
if ( V_28 < 0 )
goto V_147;
V_28 = F_91 ( & V_148 ) ;
if ( V_28 < 0 )
goto V_149;
return 0 ;
V_149:
F_92 ( & V_146 ) ;
V_147:
F_93 ( V_144 , V_106 ) ;
F_93 ( V_144 , V_110 ) ;
F_93 ( V_144 , V_145 ) ;
return V_28 ;
}
