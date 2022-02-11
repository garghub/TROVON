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
static T_1 F_5 ( struct V_1 * V_2 )
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
struct V_43 * V_44 , int V_5 ,
struct V_45 * V_46 )
{
int V_47 = 0 ;
if ( V_22 -> V_48 && ( V_22 -> V_48 != V_44 -> V_49 ) )
goto V_50;
if ( V_22 -> V_51 && ( V_22 -> V_51 != V_44 -> V_52 ) )
goto V_50;
if ( ( V_22 -> V_53 ^ V_44 -> V_54 ) & V_22 -> V_55 )
goto V_50;
if ( V_22 -> V_56 && ( V_22 -> V_56 != V_44 -> V_57 . V_56 ) )
goto V_50;
if ( V_22 -> V_58 && ! F_33 ( V_22 -> V_14 , V_44 , V_46 ) )
goto V_50;
V_47 = V_2 -> V_32 ( V_22 , V_44 , V_5 ) ;
V_50:
return ( V_22 -> V_5 & V_59 ) ? ! V_47 : V_47 ;
}
int F_34 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int V_5 , struct V_45 * V_46 )
{
struct V_6 * V_22 ;
int V_28 ;
F_9 () ;
F_10 (rule, &ops->rules_list, list) {
V_60:
if ( ! F_32 ( V_22 , V_2 , V_44 , V_5 , V_46 ) )
continue;
if ( V_22 -> V_12 == V_61 ) {
struct V_6 * V_62 ;
V_62 = F_35 ( V_22 -> V_63 ) ;
if ( V_62 == NULL ) {
continue;
} else {
V_22 = V_62 ;
goto V_60;
}
} else if ( V_22 -> V_12 == V_64 )
continue;
else
V_28 = V_2 -> V_12 ( V_22 , V_44 , V_5 , V_46 ) ;
if ( ! V_28 && V_2 -> V_65 && V_2 -> V_65 ( V_22 , V_46 ) )
continue;
if ( V_28 != - V_66 ) {
if ( ( V_46 -> V_5 & V_67 ) ||
F_36 ( F_37 ( & V_22 -> V_11 ) ) ) {
V_46 -> V_22 = V_22 ;
goto V_50;
}
break;
}
}
V_28 = - V_68 ;
V_50:
F_12 () ;
return V_28 ;
}
static int F_38 ( struct V_69 * V_70 , struct V_71 * * V_72 ,
struct V_1 * V_2 )
{
int V_28 = - V_31 ;
if ( V_70 -> V_73 )
if ( V_72 [ V_74 ] == NULL ||
V_70 -> V_73 > ( V_2 -> V_75 * 8 ) ||
F_39 ( V_72 [ V_74 ] ) != V_2 -> V_75 )
goto V_37;
if ( V_70 -> V_76 )
if ( V_72 [ V_77 ] == NULL ||
V_70 -> V_76 > ( V_2 -> V_75 * 8 ) ||
F_39 ( V_72 [ V_77 ] ) != V_2 -> V_75 )
goto V_37;
V_28 = 0 ;
V_37:
return V_28 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_69 * V_70 ,
struct V_71 * * V_72 , struct V_6 * V_22 )
{
struct V_6 * V_7 ;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 != V_22 -> V_12 )
continue;
if ( V_7 -> V_4 != V_22 -> V_4 )
continue;
if ( V_7 -> V_3 != V_22 -> V_3 )
continue;
if ( memcmp ( V_7 -> V_78 , V_22 -> V_78 , V_79 ) )
continue;
if ( memcmp ( V_7 -> V_80 , V_22 -> V_80 , V_79 ) )
continue;
if ( V_7 -> V_53 != V_22 -> V_53 )
continue;
if ( V_7 -> V_55 != V_22 -> V_55 )
continue;
if ( V_7 -> V_56 != V_22 -> V_56 )
continue;
if ( V_7 -> V_14 != V_22 -> V_14 )
continue;
if ( V_7 -> V_58 != V_22 -> V_58 )
continue;
if ( ! V_2 -> V_34 ( V_7 , V_70 , V_72 ) )
continue;
return 1 ;
}
return 0 ;
}
int F_41 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_24 * V_24 = F_42 ( V_82 -> V_85 ) ;
struct V_69 * V_70 = F_43 ( V_84 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_22 , * V_7 , * V_86 = NULL ;
struct V_71 * V_72 [ V_87 + 1 ] ;
int V_28 = - V_31 , V_88 = 0 ;
if ( V_84 -> V_89 < F_44 ( sizeof( * V_70 ) ) )
goto V_37;
V_2 = F_8 ( V_24 , V_70 -> V_25 ) ;
if ( V_2 == NULL ) {
V_28 = - V_90 ;
goto V_37;
}
V_28 = F_45 ( V_84 , sizeof( * V_70 ) , V_72 , V_87 , V_2 -> V_91 ) ;
if ( V_28 < 0 )
goto V_37;
V_28 = F_38 ( V_70 , V_72 , V_2 ) ;
if ( V_28 < 0 )
goto V_37;
V_22 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_22 == NULL ) {
V_28 = - V_10 ;
goto V_37;
}
V_22 -> V_14 = V_24 ;
V_22 -> V_3 = V_72 [ V_92 ] ? F_46 ( V_72 [ V_92 ] )
: F_5 ( V_2 ) ;
if ( V_72 [ V_93 ] ) {
struct V_94 * V_95 ;
V_22 -> V_48 = - 1 ;
F_47 ( V_22 -> V_78 , V_72 [ V_93 ] , V_79 ) ;
V_95 = F_48 ( V_24 , V_22 -> V_78 ) ;
if ( V_95 )
V_22 -> V_48 = V_95 -> V_96 ;
}
if ( V_72 [ V_97 ] ) {
struct V_94 * V_95 ;
V_22 -> V_51 = - 1 ;
F_47 ( V_22 -> V_80 , V_72 [ V_97 ] , V_79 ) ;
V_95 = F_48 ( V_24 , V_22 -> V_80 ) ;
if ( V_95 )
V_22 -> V_51 = V_95 -> V_96 ;
}
if ( V_72 [ V_98 ] ) {
V_22 -> V_53 = F_46 ( V_72 [ V_98 ] ) ;
if ( V_22 -> V_53 )
V_22 -> V_55 = 0xFFFFFFFF ;
}
if ( V_72 [ V_99 ] )
V_22 -> V_55 = F_46 ( V_72 [ V_99 ] ) ;
if ( V_72 [ V_100 ] )
V_22 -> V_56 = F_49 ( V_72 [ V_100 ] ) ;
if ( V_72 [ V_101 ] ) {
#ifdef F_50
V_22 -> V_58 = F_51 ( V_72 [ V_101 ] ) ;
if ( V_22 -> V_58 != 1 )
#endif
goto V_102;
}
V_22 -> V_12 = V_70 -> V_12 ;
V_22 -> V_5 = V_70 -> V_5 ;
V_22 -> V_4 = F_52 ( V_70 , V_72 ) ;
if ( V_72 [ V_103 ] )
V_22 -> V_16 = F_46 ( V_72 [ V_103 ] ) ;
else
V_22 -> V_16 = - 1 ;
if ( V_72 [ V_104 ] )
V_22 -> V_17 = F_46 ( V_72 [ V_104 ] ) ;
else
V_22 -> V_17 = - 1 ;
V_28 = - V_31 ;
if ( V_72 [ V_105 ] ) {
if ( V_22 -> V_12 != V_61 )
goto V_102;
V_22 -> V_62 = F_46 ( V_72 [ V_105 ] ) ;
if ( V_22 -> V_62 <= V_22 -> V_3 )
goto V_102;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 == V_22 -> V_62 ) {
F_53 ( V_22 -> V_63 , V_7 ) ;
break;
}
}
if ( F_54 ( V_22 -> V_63 , 1 ) == NULL )
V_88 = 1 ;
} else if ( V_22 -> V_12 == V_61 )
goto V_102;
if ( V_22 -> V_58 && V_22 -> V_4 )
goto V_102;
if ( ( V_84 -> V_106 & V_107 ) &&
F_40 ( V_2 , V_70 , V_72 , V_22 ) ) {
V_28 = - V_29 ;
goto V_102;
}
V_28 = V_2 -> V_33 ( V_22 , V_82 , V_70 , V_72 ) ;
if ( V_28 < 0 )
goto V_102;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 > V_22 -> V_3 )
break;
V_86 = V_7 ;
}
F_55 ( V_22 ) ;
if ( V_86 )
F_56 ( & V_22 -> V_18 , & V_86 -> V_18 ) ;
else
F_56 ( & V_22 -> V_18 , & V_2 -> V_19 ) ;
if ( V_2 -> V_108 ) {
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 == V_61 &&
V_7 -> V_62 == V_22 -> V_3 &&
F_57 ( V_7 -> V_63 ) == NULL ) {
F_58 ( V_7 -> V_63 , V_22 ) ;
if ( -- V_2 -> V_108 == 0 )
break;
}
}
}
if ( V_22 -> V_12 == V_61 )
V_2 -> V_109 ++ ;
if ( V_88 )
V_2 -> V_108 ++ ;
if ( V_22 -> V_56 )
F_59 () ;
F_60 ( V_110 , V_22 , V_2 , V_84 , F_61 ( V_82 ) . V_111 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
V_102:
F_25 ( V_22 ) ;
V_37:
F_13 ( V_2 ) ;
return V_28 ;
}
int F_62 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_24 * V_24 = F_42 ( V_82 -> V_85 ) ;
struct V_69 * V_70 = F_43 ( V_84 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_22 , * V_40 ;
struct V_71 * V_72 [ V_87 + 1 ] ;
int V_28 = - V_31 ;
if ( V_84 -> V_89 < F_44 ( sizeof( * V_70 ) ) )
goto V_37;
V_2 = F_8 ( V_24 , V_70 -> V_25 ) ;
if ( V_2 == NULL ) {
V_28 = - V_90 ;
goto V_37;
}
V_28 = F_45 ( V_84 , sizeof( * V_70 ) , V_72 , V_87 , V_2 -> V_91 ) ;
if ( V_28 < 0 )
goto V_37;
V_28 = F_38 ( V_70 , V_72 , V_2 ) ;
if ( V_28 < 0 )
goto V_37;
F_18 (rule, &ops->rules_list, list) {
if ( V_70 -> V_12 && ( V_70 -> V_12 != V_22 -> V_12 ) )
continue;
if ( F_52 ( V_70 , V_72 ) &&
( F_52 ( V_70 , V_72 ) != V_22 -> V_4 ) )
continue;
if ( V_72 [ V_92 ] &&
( V_22 -> V_3 != F_46 ( V_72 [ V_92 ] ) ) )
continue;
if ( V_72 [ V_93 ] &&
F_63 ( V_72 [ V_93 ] , V_22 -> V_78 ) )
continue;
if ( V_72 [ V_97 ] &&
F_63 ( V_72 [ V_97 ] , V_22 -> V_80 ) )
continue;
if ( V_72 [ V_98 ] &&
( V_22 -> V_53 != F_46 ( V_72 [ V_98 ] ) ) )
continue;
if ( V_72 [ V_99 ] &&
( V_22 -> V_55 != F_46 ( V_72 [ V_99 ] ) ) )
continue;
if ( V_72 [ V_100 ] &&
( V_22 -> V_56 != F_49 ( V_72 [ V_100 ] ) ) )
continue;
if ( V_72 [ V_101 ] &&
( V_22 -> V_58 != F_51 ( V_72 [ V_101 ] ) ) )
continue;
if ( ! V_2 -> V_34 ( V_22 , V_70 , V_72 ) )
continue;
if ( V_22 -> V_5 & V_112 ) {
V_28 = - V_113 ;
goto V_37;
}
if ( V_2 -> V_41 ) {
V_28 = V_2 -> V_41 ( V_22 ) ;
if ( V_28 )
goto V_37;
}
if ( V_22 -> V_56 )
F_64 () ;
F_28 ( & V_22 -> V_18 ) ;
if ( V_22 -> V_12 == V_61 ) {
V_2 -> V_109 -- ;
if ( F_57 ( V_22 -> V_63 ) == NULL )
V_2 -> V_108 -- ;
}
if ( V_2 -> V_109 > 0 ) {
F_18 (tmp, &ops->rules_list, list) {
if ( F_57 ( V_40 -> V_63 ) == V_22 ) {
F_53 ( V_40 -> V_63 , NULL ) ;
V_2 -> V_108 ++ ;
}
}
}
F_60 ( V_114 , V_22 , V_2 , V_84 ,
F_61 ( V_82 ) . V_111 ) ;
F_29 ( V_22 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
V_28 = - V_115 ;
V_37:
F_13 ( V_2 ) ;
return V_28 ;
}
static inline T_2 F_65 ( struct V_1 * V_2 ,
struct V_6 * V_22 )
{
T_2 V_116 = F_66 ( sizeof( struct V_69 ) )
+ F_67 ( V_79 )
+ F_67 ( V_79 )
+ F_67 ( 4 )
+ F_67 ( 4 )
+ F_67 ( 4 )
+ F_67 ( 4 )
+ F_67 ( 4 )
+ F_67 ( 4 )
+ F_68 ( 8 ) ;
if ( V_2 -> V_117 )
V_116 += V_2 -> V_117 ( V_22 ) ;
return V_116 ;
}
static int F_69 ( struct V_81 * V_82 , struct V_6 * V_22 ,
T_1 V_118 , T_1 V_119 , int type , int V_5 ,
struct V_1 * V_2 )
{
struct V_83 * V_84 ;
struct V_69 * V_70 ;
V_84 = F_70 ( V_82 , V_118 , V_119 , type , sizeof( * V_70 ) , V_5 ) ;
if ( V_84 == NULL )
return - V_120 ;
V_70 = F_43 ( V_84 ) ;
V_70 -> V_25 = V_2 -> V_25 ;
V_70 -> V_4 = V_22 -> V_4 ;
if ( F_71 ( V_82 , V_121 , V_22 -> V_4 ) )
goto V_122;
if ( F_71 ( V_82 , V_103 , V_22 -> V_16 ) )
goto V_122;
V_70 -> V_123 = 0 ;
V_70 -> V_124 = 0 ;
V_70 -> V_12 = V_22 -> V_12 ;
V_70 -> V_5 = V_22 -> V_5 ;
if ( V_22 -> V_12 == V_61 &&
F_72 ( V_22 -> V_63 ) == NULL )
V_70 -> V_5 |= V_125 ;
if ( V_22 -> V_78 [ 0 ] ) {
if ( F_73 ( V_82 , V_93 , V_22 -> V_78 ) )
goto V_122;
if ( V_22 -> V_48 == - 1 )
V_70 -> V_5 |= V_126 ;
}
if ( V_22 -> V_80 [ 0 ] ) {
if ( F_73 ( V_82 , V_97 , V_22 -> V_80 ) )
goto V_122;
if ( V_22 -> V_51 == - 1 )
V_70 -> V_5 |= V_127 ;
}
if ( ( V_22 -> V_3 &&
F_71 ( V_82 , V_92 , V_22 -> V_3 ) ) ||
( V_22 -> V_53 &&
F_71 ( V_82 , V_98 , V_22 -> V_53 ) ) ||
( ( V_22 -> V_55 || V_22 -> V_53 ) &&
F_71 ( V_82 , V_99 , V_22 -> V_55 ) ) ||
( V_22 -> V_62 &&
F_71 ( V_82 , V_105 , V_22 -> V_62 ) ) ||
( V_22 -> V_56 &&
F_74 ( V_82 , V_100 , V_22 -> V_56 , V_128 ) ) ||
( V_22 -> V_58 &&
F_75 ( V_82 , V_101 , V_22 -> V_58 ) ) )
goto V_122;
if ( V_22 -> V_17 != - 1 ) {
if ( F_71 ( V_82 , V_104 , V_22 -> V_17 ) )
goto V_122;
}
if ( V_2 -> V_35 ( V_22 , V_82 , V_70 ) < 0 )
goto V_122;
F_76 ( V_82 , V_84 ) ;
return 0 ;
V_122:
F_77 ( V_82 , V_84 ) ;
return - V_120 ;
}
static int F_78 ( struct V_81 * V_82 , struct V_129 * V_130 ,
struct V_1 * V_2 )
{
int V_131 = 0 ;
struct V_6 * V_22 ;
int V_28 = 0 ;
F_9 () ;
F_10 (rule, &ops->rules_list, list) {
if ( V_131 < V_130 -> args [ 1 ] )
goto V_132;
V_28 = F_69 ( V_82 , V_22 , F_61 ( V_130 -> V_82 ) . V_111 ,
V_130 -> V_84 -> V_133 , V_110 ,
V_134 , V_2 ) ;
if ( V_28 )
break;
V_132:
V_131 ++ ;
}
F_12 () ;
V_130 -> args [ 1 ] = V_131 ;
F_13 ( V_2 ) ;
return V_28 ;
}
static int F_79 ( struct V_81 * V_82 , struct V_129 * V_130 )
{
struct V_24 * V_24 = F_42 ( V_82 -> V_85 ) ;
struct V_1 * V_2 ;
int V_131 = 0 , V_25 ;
V_25 = F_80 ( V_130 -> V_84 ) ;
if ( V_25 != V_135 ) {
V_2 = F_8 ( V_24 , V_25 ) ;
if ( V_2 == NULL )
return - V_90 ;
F_78 ( V_82 , V_130 , V_2 ) ;
return V_82 -> V_136 ;
}
F_9 () ;
F_10 (ops, &net->rules_ops, list) {
if ( V_131 < V_130 -> args [ 0 ] || ! F_11 ( V_2 -> V_26 ) )
goto V_132;
if ( F_78 ( V_82 , V_130 , V_2 ) < 0 )
break;
V_130 -> args [ 1 ] = 0 ;
V_132:
V_131 ++ ;
}
F_12 () ;
V_130 -> args [ 0 ] = V_131 ;
return V_82 -> V_136 ;
}
static void F_60 ( int V_137 , struct V_6 * V_22 ,
struct V_1 * V_2 , struct V_83 * V_84 ,
T_1 V_118 )
{
struct V_24 * V_24 ;
struct V_81 * V_82 ;
int V_28 = - V_138 ;
V_24 = V_2 -> V_15 ;
V_82 = F_81 ( F_65 ( V_2 , V_22 ) , V_9 ) ;
if ( V_82 == NULL )
goto V_37;
V_28 = F_69 ( V_82 , V_22 , V_118 , V_84 -> V_133 , V_137 , 0 , V_2 ) ;
if ( V_28 < 0 ) {
F_82 ( V_28 == - V_120 ) ;
F_83 ( V_82 ) ;
goto V_37;
}
F_84 ( V_82 , V_24 , V_118 , V_2 -> V_139 , V_84 , V_9 ) ;
return;
V_37:
if ( V_28 < 0 )
F_85 ( V_24 , V_2 -> V_139 , V_28 ) ;
}
static void F_86 ( struct V_20 * V_140 , struct V_94 * V_95 )
{
struct V_6 * V_22 ;
F_18 (rule, rules, list) {
if ( V_22 -> V_48 == - 1 &&
strcmp ( V_95 -> V_141 , V_22 -> V_78 ) == 0 )
V_22 -> V_48 = V_95 -> V_96 ;
if ( V_22 -> V_51 == - 1 &&
strcmp ( V_95 -> V_141 , V_22 -> V_80 ) == 0 )
V_22 -> V_51 = V_95 -> V_96 ;
}
}
static void F_87 ( struct V_20 * V_140 , struct V_94 * V_95 )
{
struct V_6 * V_22 ;
F_18 (rule, rules, list) {
if ( V_22 -> V_48 == V_95 -> V_96 )
V_22 -> V_48 = - 1 ;
if ( V_22 -> V_51 == V_95 -> V_96 )
V_22 -> V_51 = - 1 ;
}
}
static int F_88 ( struct V_142 * V_143 , unsigned long V_137 ,
void * V_144 )
{
struct V_94 * V_95 = F_89 ( V_144 ) ;
struct V_24 * V_24 = F_90 ( V_95 ) ;
struct V_1 * V_2 ;
F_91 () ;
switch ( V_137 ) {
case V_145 :
F_18 (ops, &net->rules_ops, list)
F_86 ( & V_2 -> V_19 , V_95 ) ;
break;
case V_146 :
F_18 (ops, &net->rules_ops, list) {
F_87 ( & V_2 -> V_19 , V_95 ) ;
F_86 ( & V_2 -> V_19 , V_95 ) ;
}
break;
case V_147 :
F_18 (ops, &net->rules_ops, list)
F_87 ( & V_2 -> V_19 , V_95 ) ;
break;
}
return V_148 ;
}
static int T_3 F_92 ( struct V_24 * V_24 )
{
F_24 ( & V_24 -> V_38 ) ;
F_93 ( & V_24 -> V_36 ) ;
return 0 ;
}
static int T_4 F_94 ( void )
{
int V_28 ;
F_95 ( V_149 , V_110 , F_41 , NULL , NULL ) ;
F_95 ( V_149 , V_114 , F_62 , NULL , NULL ) ;
F_95 ( V_149 , V_150 , NULL , F_79 , NULL ) ;
V_28 = F_96 ( & V_151 ) ;
if ( V_28 < 0 )
goto V_152;
V_28 = F_97 ( & V_153 ) ;
if ( V_28 < 0 )
goto V_154;
return 0 ;
V_154:
F_98 ( & V_151 ) ;
V_152:
F_99 ( V_149 , V_110 ) ;
F_99 ( V_149 , V_114 ) ;
F_99 ( V_149 , V_150 ) ;
return V_28 ;
}
