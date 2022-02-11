bool F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 || V_2 -> V_4 || V_2 -> V_5 || V_2 -> V_6 ||
V_2 -> V_7 )
return false ;
if ( V_2 -> V_8 != - 1 || V_2 -> V_9 != - 1 )
return false ;
if ( ! F_2 ( V_2 -> V_10 . V_11 , V_12 . V_11 ) ||
! F_2 ( V_2 -> V_10 . V_13 , V_12 . V_13 ) )
return false ;
return true ;
}
int F_3 ( struct V_14 * V_15 ,
T_1 V_16 , T_1 V_17 , T_1 V_7 )
{
struct V_1 * V_18 ;
V_18 = F_4 ( V_15 -> V_19 , V_20 ) ;
if ( V_18 == NULL )
return - V_21 ;
F_5 ( & V_18 -> V_22 , 1 ) ;
V_18 -> V_23 = V_24 ;
V_18 -> V_16 = V_16 ;
V_18 -> V_17 = V_17 ;
V_18 -> V_7 = V_7 ;
V_18 -> V_25 = V_15 -> V_26 ;
V_18 -> V_10 = V_12 ;
V_18 -> V_9 = - 1 ;
V_18 -> V_8 = - 1 ;
F_6 ( & V_18 -> V_27 , & V_15 -> V_28 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_14 * V_15 )
{
struct V_29 * V_30 ;
struct V_1 * V_2 ;
if ( ! F_8 ( & V_15 -> V_28 ) ) {
V_30 = V_15 -> V_28 . V_31 ;
if ( V_30 -> V_31 != & V_15 -> V_28 ) {
V_2 = F_9 ( V_30 -> V_31 , struct V_1 , V_27 ) ;
if ( V_2 -> V_16 )
return V_2 -> V_16 - 1 ;
}
}
return 0 ;
}
static struct V_14 * F_10 ( struct V_32 * V_32 , int V_33 )
{
struct V_14 * V_15 ;
F_11 () ;
F_12 (ops, &net->rules_ops, list) {
if ( V_15 -> V_33 == V_33 ) {
if ( ! F_13 ( V_15 -> V_34 ) )
V_15 = NULL ;
F_14 () ;
return V_15 ;
}
}
F_14 () ;
return NULL ;
}
static void F_15 ( struct V_14 * V_15 )
{
if ( V_15 )
F_16 ( V_15 -> V_34 ) ;
}
static void F_17 ( struct V_14 * V_15 )
{
if ( V_15 -> V_35 )
V_15 -> V_35 ( V_15 ) ;
}
static int F_18 ( struct V_14 * V_15 )
{
int V_36 = - V_37 ;
struct V_14 * V_38 ;
struct V_32 * V_32 ;
V_32 = V_15 -> V_26 ;
if ( V_15 -> V_19 < sizeof( struct V_1 ) )
return - V_39 ;
if ( V_15 -> V_40 == NULL || V_15 -> V_41 == NULL ||
V_15 -> V_42 == NULL || V_15 -> V_43 == NULL ||
V_15 -> V_23 == NULL )
return - V_39 ;
F_19 ( & V_32 -> V_44 ) ;
F_20 (o, &net->rules_ops, list)
if ( V_15 -> V_33 == V_38 -> V_33 )
goto V_45;
F_21 ( & V_15 -> V_27 , & V_32 -> V_46 ) ;
V_36 = 0 ;
V_45:
F_22 ( & V_32 -> V_44 ) ;
return V_36 ;
}
struct V_14 *
F_23 ( const struct V_14 * V_47 , struct V_32 * V_32 )
{
struct V_14 * V_15 ;
int V_36 ;
V_15 = F_24 ( V_47 , sizeof( * V_15 ) , V_20 ) ;
if ( V_15 == NULL )
return F_25 ( - V_21 ) ;
F_26 ( & V_15 -> V_28 ) ;
V_15 -> V_26 = V_32 ;
V_36 = F_18 ( V_15 ) ;
if ( V_36 ) {
F_27 ( V_15 ) ;
V_15 = F_25 ( V_36 ) ;
}
return V_15 ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_1 * V_2 , * V_48 ;
F_29 (rule, tmp, &ops->rules_list, list) {
F_30 ( & V_2 -> V_27 ) ;
if ( V_15 -> V_49 )
V_15 -> V_49 ( V_2 ) ;
F_31 ( V_2 ) ;
}
}
void F_32 ( struct V_14 * V_15 )
{
struct V_32 * V_32 = V_15 -> V_26 ;
F_19 ( & V_32 -> V_44 ) ;
F_30 ( & V_15 -> V_27 ) ;
F_22 ( & V_32 -> V_44 ) ;
F_28 ( V_15 ) ;
F_33 ( V_15 , V_50 ) ;
}
static int F_34 ( struct V_51 * V_52 )
{
return F_35 ( V_52 -> V_11 ) && F_35 ( V_52 -> V_13 ) ;
}
static struct V_51 F_36 ( struct V_53 * * V_54 )
{
struct V_55 * V_56 ;
struct V_51 V_57 ;
V_56 = (struct V_55 * ) F_37 ( V_54 [ V_58 ] ) ;
V_57 . V_11 = F_38 ( F_39 () , V_56 -> V_11 ) ;
V_57 . V_13 = F_38 ( F_39 () , V_56 -> V_13 ) ;
return V_57 ;
}
static int F_40 ( struct V_59 * V_60 , struct V_51 * V_52 )
{
struct V_55 V_57 = {
F_41 ( F_39 () , V_52 -> V_11 ) ,
F_41 (current_user_ns(), range->end)
} ;
return F_42 ( V_60 , V_58 , sizeof( V_57 ) , & V_57 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_61 * V_62 , int V_7 ,
struct V_63 * V_64 )
{
int V_65 = 0 ;
if ( V_2 -> V_3 && ( V_2 -> V_3 != V_62 -> V_66 ) )
goto V_57;
if ( V_2 -> V_4 && ( V_2 -> V_4 != V_62 -> V_67 ) )
goto V_57;
if ( ( V_2 -> V_5 ^ V_62 -> V_68 ) & V_2 -> V_69 )
goto V_57;
if ( V_2 -> V_6 && ( V_2 -> V_6 != V_62 -> V_70 . V_6 ) )
goto V_57;
if ( V_2 -> V_71 && ! F_44 ( V_2 -> V_25 , V_62 , V_64 ) )
goto V_57;
if ( F_45 ( V_62 -> V_72 , V_2 -> V_10 . V_11 ) ||
F_46 ( V_62 -> V_72 , V_2 -> V_10 . V_13 ) )
goto V_57;
V_65 = V_15 -> V_40 ( V_2 , V_62 , V_7 ) ;
V_57:
return ( V_2 -> V_7 & V_73 ) ? ! V_65 : V_65 ;
}
int F_47 ( struct V_14 * V_15 , struct V_61 * V_62 ,
int V_7 , struct V_63 * V_64 )
{
struct V_1 * V_2 ;
int V_36 ;
F_11 () ;
F_12 (rule, &ops->rules_list, list) {
V_74:
if ( ! F_43 ( V_2 , V_15 , V_62 , V_7 , V_64 ) )
continue;
if ( V_2 -> V_23 == V_75 ) {
struct V_1 * V_76 ;
V_76 = F_48 ( V_2 -> V_77 ) ;
if ( V_76 == NULL ) {
continue;
} else {
V_2 = V_76 ;
goto V_74;
}
} else if ( V_2 -> V_23 == V_78 )
continue;
else
V_36 = V_15 -> V_23 ( V_2 , V_62 , V_7 , V_64 ) ;
if ( ! V_36 && V_15 -> V_79 && V_15 -> V_79 ( V_2 , V_64 ) )
continue;
if ( V_36 != - V_80 ) {
if ( ( V_64 -> V_7 & V_81 ) ||
F_49 ( F_50 ( & V_2 -> V_22 ) ) ) {
V_64 -> V_2 = V_2 ;
goto V_57;
}
break;
}
}
V_36 = - V_82 ;
V_57:
F_14 () ;
return V_36 ;
}
static int F_51 ( struct V_83 * V_84 , struct V_53 * * V_54 ,
struct V_14 * V_15 )
{
int V_36 = - V_39 ;
if ( V_84 -> V_85 )
if ( V_54 [ V_86 ] == NULL ||
V_84 -> V_85 > ( V_15 -> V_87 * 8 ) ||
F_52 ( V_54 [ V_86 ] ) != V_15 -> V_87 )
goto V_45;
if ( V_84 -> V_88 )
if ( V_54 [ V_89 ] == NULL ||
V_84 -> V_88 > ( V_15 -> V_87 * 8 ) ||
F_52 ( V_54 [ V_89 ] ) != V_15 -> V_87 )
goto V_45;
V_36 = 0 ;
V_45:
return V_36 ;
}
static int F_53 ( struct V_14 * V_15 , struct V_83 * V_84 ,
struct V_53 * * V_54 , struct V_1 * V_2 )
{
struct V_1 * V_18 ;
F_20 (r, &ops->rules_list, list) {
if ( V_18 -> V_23 != V_2 -> V_23 )
continue;
if ( V_18 -> V_17 != V_2 -> V_17 )
continue;
if ( V_18 -> V_16 != V_2 -> V_16 )
continue;
if ( memcmp ( V_18 -> V_90 , V_2 -> V_90 , V_91 ) )
continue;
if ( memcmp ( V_18 -> V_92 , V_2 -> V_92 , V_91 ) )
continue;
if ( V_18 -> V_5 != V_2 -> V_5 )
continue;
if ( V_18 -> V_69 != V_2 -> V_69 )
continue;
if ( V_18 -> V_6 != V_2 -> V_6 )
continue;
if ( V_18 -> V_25 != V_2 -> V_25 )
continue;
if ( V_18 -> V_71 != V_2 -> V_71 )
continue;
if ( ! F_2 ( V_18 -> V_10 . V_11 , V_2 -> V_10 . V_11 ) ||
! F_2 ( V_18 -> V_10 . V_13 , V_2 -> V_10 . V_13 ) )
continue;
if ( ! V_15 -> V_42 ( V_18 , V_84 , V_54 ) )
continue;
return 1 ;
}
return 0 ;
}
int F_54 ( struct V_59 * V_60 , struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_32 * V_32 = F_55 ( V_60 -> V_97 ) ;
struct V_83 * V_84 = F_56 ( V_94 ) ;
struct V_14 * V_15 = NULL ;
struct V_1 * V_2 , * V_18 , * V_98 = NULL ;
struct V_53 * V_54 [ V_99 + 1 ] ;
int V_36 = - V_39 , V_100 = 0 ;
if ( V_94 -> V_101 < F_57 ( sizeof( * V_84 ) ) )
goto V_45;
V_15 = F_10 ( V_32 , V_84 -> V_33 ) ;
if ( V_15 == NULL ) {
V_36 = - V_102 ;
goto V_45;
}
V_36 = F_58 ( V_94 , sizeof( * V_84 ) , V_54 , V_99 , V_15 -> V_103 , V_96 ) ;
if ( V_36 < 0 )
goto V_45;
V_36 = F_51 ( V_84 , V_54 , V_15 ) ;
if ( V_36 < 0 )
goto V_45;
V_2 = F_4 ( V_15 -> V_19 , V_20 ) ;
if ( V_2 == NULL ) {
V_36 = - V_21 ;
goto V_45;
}
F_5 ( & V_2 -> V_22 , 1 ) ;
V_2 -> V_25 = V_32 ;
V_2 -> V_16 = V_54 [ V_104 ] ? F_59 ( V_54 [ V_104 ] )
: F_7 ( V_15 ) ;
if ( V_54 [ V_105 ] ) {
struct V_106 * V_107 ;
V_2 -> V_3 = - 1 ;
F_60 ( V_2 -> V_90 , V_54 [ V_105 ] , V_91 ) ;
V_107 = F_61 ( V_32 , V_2 -> V_90 ) ;
if ( V_107 )
V_2 -> V_3 = V_107 -> V_108 ;
}
if ( V_54 [ V_109 ] ) {
struct V_106 * V_107 ;
V_2 -> V_4 = - 1 ;
F_60 ( V_2 -> V_92 , V_54 [ V_109 ] , V_91 ) ;
V_107 = F_61 ( V_32 , V_2 -> V_92 ) ;
if ( V_107 )
V_2 -> V_4 = V_107 -> V_108 ;
}
if ( V_54 [ V_110 ] ) {
V_2 -> V_5 = F_59 ( V_54 [ V_110 ] ) ;
if ( V_2 -> V_5 )
V_2 -> V_69 = 0xFFFFFFFF ;
}
if ( V_54 [ V_111 ] )
V_2 -> V_69 = F_59 ( V_54 [ V_111 ] ) ;
if ( V_54 [ V_112 ] )
V_2 -> V_6 = F_62 ( V_54 [ V_112 ] ) ;
V_36 = - V_39 ;
if ( V_54 [ V_113 ] ) {
#ifdef F_63
V_2 -> V_71 = F_64 ( V_54 [ V_113 ] ) ;
if ( V_2 -> V_71 != 1 )
#endif
goto V_114;
}
V_2 -> V_23 = V_84 -> V_23 ;
V_2 -> V_7 = V_84 -> V_7 ;
V_2 -> V_17 = F_65 ( V_84 , V_54 ) ;
if ( V_54 [ V_115 ] )
V_2 -> V_9 = F_59 ( V_54 [ V_115 ] ) ;
else
V_2 -> V_9 = - 1 ;
if ( V_54 [ V_116 ] )
V_2 -> V_8 = F_59 ( V_54 [ V_116 ] ) ;
else
V_2 -> V_8 = - 1 ;
if ( V_54 [ V_117 ] ) {
if ( V_2 -> V_23 != V_75 )
goto V_114;
V_2 -> V_76 = F_59 ( V_54 [ V_117 ] ) ;
if ( V_2 -> V_76 <= V_2 -> V_16 )
goto V_114;
F_20 (r, &ops->rules_list, list) {
if ( V_18 -> V_16 == V_2 -> V_76 ) {
F_66 ( V_2 -> V_77 , V_18 ) ;
break;
}
}
if ( F_67 ( V_2 -> V_77 , 1 ) == NULL )
V_100 = 1 ;
} else if ( V_2 -> V_23 == V_75 )
goto V_114;
if ( V_2 -> V_71 && V_2 -> V_17 )
goto V_114;
if ( V_54 [ V_58 ] ) {
if ( F_39 () != V_32 -> V_118 ) {
V_36 = - V_119 ;
goto V_114;
}
V_2 -> V_10 = F_36 ( V_54 ) ;
if ( ! F_34 ( & V_2 -> V_10 ) ||
! F_68 ( V_2 -> V_10 . V_11 , V_2 -> V_10 . V_13 ) )
goto V_114;
} else {
V_2 -> V_10 = V_12 ;
}
if ( ( V_94 -> V_120 & V_121 ) &&
F_53 ( V_15 , V_84 , V_54 , V_2 ) ) {
V_36 = - V_37 ;
goto V_114;
}
V_36 = V_15 -> V_41 ( V_2 , V_60 , V_84 , V_54 ) ;
if ( V_36 < 0 )
goto V_114;
F_20 (r, &ops->rules_list, list) {
if ( V_18 -> V_16 > V_2 -> V_16 )
break;
V_98 = V_18 ;
}
if ( V_98 )
F_69 ( & V_2 -> V_27 , & V_98 -> V_27 ) ;
else
F_69 ( & V_2 -> V_27 , & V_15 -> V_28 ) ;
if ( V_15 -> V_122 ) {
F_20 (r, &ops->rules_list, list) {
if ( V_18 -> V_23 == V_75 &&
V_18 -> V_76 == V_2 -> V_16 &&
F_70 ( V_18 -> V_77 ) == NULL ) {
F_71 ( V_18 -> V_77 , V_2 ) ;
if ( -- V_15 -> V_122 == 0 )
break;
}
}
}
if ( V_2 -> V_23 == V_75 )
V_15 -> V_123 ++ ;
if ( V_100 )
V_15 -> V_122 ++ ;
if ( V_2 -> V_6 )
F_72 () ;
F_73 ( V_124 , V_2 , V_15 , V_94 , F_74 ( V_60 ) . V_125 ) ;
F_17 ( V_15 ) ;
F_15 ( V_15 ) ;
return 0 ;
V_114:
F_27 ( V_2 ) ;
V_45:
F_15 ( V_15 ) ;
return V_36 ;
}
int F_75 ( struct V_59 * V_60 , struct V_93 * V_94 ,
struct V_95 * V_96 )
{
struct V_32 * V_32 = F_55 ( V_60 -> V_97 ) ;
struct V_83 * V_84 = F_56 ( V_94 ) ;
struct V_14 * V_15 = NULL ;
struct V_1 * V_2 , * V_18 ;
struct V_53 * V_54 [ V_99 + 1 ] ;
struct V_51 V_52 ;
int V_36 = - V_39 ;
if ( V_94 -> V_101 < F_57 ( sizeof( * V_84 ) ) )
goto V_45;
V_15 = F_10 ( V_32 , V_84 -> V_33 ) ;
if ( V_15 == NULL ) {
V_36 = - V_102 ;
goto V_45;
}
V_36 = F_58 ( V_94 , sizeof( * V_84 ) , V_54 , V_99 , V_15 -> V_103 , V_96 ) ;
if ( V_36 < 0 )
goto V_45;
V_36 = F_51 ( V_84 , V_54 , V_15 ) ;
if ( V_36 < 0 )
goto V_45;
if ( V_54 [ V_58 ] ) {
V_52 = F_36 ( V_54 ) ;
if ( ! F_34 ( & V_52 ) ) {
V_36 = - V_39 ;
goto V_45;
}
} else {
V_52 = V_12 ;
}
F_20 (rule, &ops->rules_list, list) {
if ( V_84 -> V_23 && ( V_84 -> V_23 != V_2 -> V_23 ) )
continue;
if ( F_65 ( V_84 , V_54 ) &&
( F_65 ( V_84 , V_54 ) != V_2 -> V_17 ) )
continue;
if ( V_54 [ V_104 ] &&
( V_2 -> V_16 != F_59 ( V_54 [ V_104 ] ) ) )
continue;
if ( V_54 [ V_105 ] &&
F_76 ( V_54 [ V_105 ] , V_2 -> V_90 ) )
continue;
if ( V_54 [ V_109 ] &&
F_76 ( V_54 [ V_109 ] , V_2 -> V_92 ) )
continue;
if ( V_54 [ V_110 ] &&
( V_2 -> V_5 != F_59 ( V_54 [ V_110 ] ) ) )
continue;
if ( V_54 [ V_111 ] &&
( V_2 -> V_69 != F_59 ( V_54 [ V_111 ] ) ) )
continue;
if ( V_54 [ V_112 ] &&
( V_2 -> V_6 != F_62 ( V_54 [ V_112 ] ) ) )
continue;
if ( V_54 [ V_113 ] &&
( V_2 -> V_71 != F_64 ( V_54 [ V_113 ] ) ) )
continue;
if ( F_34 ( & V_52 ) &&
( ! F_2 ( V_2 -> V_10 . V_11 , V_52 . V_11 ) ||
! F_2 ( V_2 -> V_10 . V_13 , V_52 . V_13 ) ) )
continue;
if ( ! V_15 -> V_42 ( V_2 , V_84 , V_54 ) )
continue;
if ( V_2 -> V_7 & V_126 ) {
V_36 = - V_119 ;
goto V_45;
}
if ( V_15 -> V_49 ) {
V_36 = V_15 -> V_49 ( V_2 ) ;
if ( V_36 )
goto V_45;
}
if ( V_2 -> V_6 )
F_77 () ;
F_30 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_23 == V_75 ) {
V_15 -> V_123 -- ;
if ( F_70 ( V_2 -> V_77 ) == NULL )
V_15 -> V_122 -- ;
}
if ( V_15 -> V_123 > 0 ) {
struct V_1 * V_127 ;
V_127 = F_78 ( V_2 , V_27 ) ;
if ( & V_127 -> V_27 == & V_15 -> V_28 || V_127 -> V_16 != V_2 -> V_16 )
V_127 = NULL ;
F_20 (r, &ops->rules_list, list) {
if ( F_70 ( V_18 -> V_77 ) != V_2 )
continue;
F_71 ( V_18 -> V_77 , V_127 ) ;
if ( ! V_127 )
V_15 -> V_122 ++ ;
}
}
F_73 ( V_128 , V_2 , V_15 , V_94 ,
F_74 ( V_60 ) . V_125 ) ;
F_31 ( V_2 ) ;
F_17 ( V_15 ) ;
F_15 ( V_15 ) ;
return 0 ;
}
V_36 = - V_129 ;
V_45:
F_15 ( V_15 ) ;
return V_36 ;
}
static inline T_2 F_79 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
T_2 V_130 = F_80 ( sizeof( struct V_83 ) )
+ F_81 ( V_91 )
+ F_81 ( V_91 )
+ F_81 ( 4 )
+ F_81 ( 4 )
+ F_81 ( 4 )
+ F_81 ( 4 )
+ F_81 ( 4 )
+ F_81 ( 4 )
+ F_82 ( 8 )
+ F_81 ( sizeof( struct V_51 ) ) ;
if ( V_15 -> V_131 )
V_130 += V_15 -> V_131 ( V_2 ) ;
return V_130 ;
}
static int F_83 ( struct V_59 * V_60 , struct V_1 * V_2 ,
T_1 V_132 , T_1 V_133 , int type , int V_7 ,
struct V_14 * V_15 )
{
struct V_93 * V_94 ;
struct V_83 * V_84 ;
V_94 = F_84 ( V_60 , V_132 , V_133 , type , sizeof( * V_84 ) , V_7 ) ;
if ( V_94 == NULL )
return - V_134 ;
V_84 = F_56 ( V_94 ) ;
V_84 -> V_33 = V_15 -> V_33 ;
V_84 -> V_17 = V_2 -> V_17 ;
if ( F_85 ( V_60 , V_135 , V_2 -> V_17 ) )
goto V_136;
if ( F_85 ( V_60 , V_115 , V_2 -> V_9 ) )
goto V_136;
V_84 -> V_137 = 0 ;
V_84 -> V_138 = 0 ;
V_84 -> V_23 = V_2 -> V_23 ;
V_84 -> V_7 = V_2 -> V_7 ;
if ( V_2 -> V_23 == V_75 &&
F_86 ( V_2 -> V_77 ) == NULL )
V_84 -> V_7 |= V_139 ;
if ( V_2 -> V_90 [ 0 ] ) {
if ( F_87 ( V_60 , V_105 , V_2 -> V_90 ) )
goto V_136;
if ( V_2 -> V_3 == - 1 )
V_84 -> V_7 |= V_140 ;
}
if ( V_2 -> V_92 [ 0 ] ) {
if ( F_87 ( V_60 , V_109 , V_2 -> V_92 ) )
goto V_136;
if ( V_2 -> V_4 == - 1 )
V_84 -> V_7 |= V_141 ;
}
if ( ( V_2 -> V_16 &&
F_85 ( V_60 , V_104 , V_2 -> V_16 ) ) ||
( V_2 -> V_5 &&
F_85 ( V_60 , V_110 , V_2 -> V_5 ) ) ||
( ( V_2 -> V_69 || V_2 -> V_5 ) &&
F_85 ( V_60 , V_111 , V_2 -> V_69 ) ) ||
( V_2 -> V_76 &&
F_85 ( V_60 , V_117 , V_2 -> V_76 ) ) ||
( V_2 -> V_6 &&
F_88 ( V_60 , V_112 , V_2 -> V_6 , V_142 ) ) ||
( V_2 -> V_71 &&
F_89 ( V_60 , V_113 , V_2 -> V_71 ) ) ||
( F_34 ( & V_2 -> V_10 ) &&
F_40 ( V_60 , & V_2 -> V_10 ) ) )
goto V_136;
if ( V_2 -> V_8 != - 1 ) {
if ( F_85 ( V_60 , V_116 , V_2 -> V_8 ) )
goto V_136;
}
if ( V_15 -> V_43 ( V_2 , V_60 , V_84 ) < 0 )
goto V_136;
F_90 ( V_60 , V_94 ) ;
return 0 ;
V_136:
F_91 ( V_60 , V_94 ) ;
return - V_134 ;
}
static int F_92 ( struct V_59 * V_60 , struct V_143 * V_144 ,
struct V_14 * V_15 )
{
int V_145 = 0 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_11 () ;
F_12 (rule, &ops->rules_list, list) {
if ( V_145 < V_144 -> args [ 1 ] )
goto V_146;
V_36 = F_83 ( V_60 , V_2 , F_74 ( V_144 -> V_60 ) . V_125 ,
V_144 -> V_94 -> V_147 , V_124 ,
V_148 , V_15 ) ;
if ( V_36 )
break;
V_146:
V_145 ++ ;
}
F_14 () ;
V_144 -> args [ 1 ] = V_145 ;
F_15 ( V_15 ) ;
return V_36 ;
}
static int F_93 ( struct V_59 * V_60 , struct V_143 * V_144 )
{
struct V_32 * V_32 = F_55 ( V_60 -> V_97 ) ;
struct V_14 * V_15 ;
int V_145 = 0 , V_33 ;
V_33 = F_94 ( V_144 -> V_94 ) ;
if ( V_33 != V_149 ) {
V_15 = F_10 ( V_32 , V_33 ) ;
if ( V_15 == NULL )
return - V_102 ;
F_92 ( V_60 , V_144 , V_15 ) ;
return V_60 -> V_150 ;
}
F_11 () ;
F_12 (ops, &net->rules_ops, list) {
if ( V_145 < V_144 -> args [ 0 ] || ! F_13 ( V_15 -> V_34 ) )
goto V_146;
if ( F_92 ( V_60 , V_144 , V_15 ) < 0 )
break;
V_144 -> args [ 1 ] = 0 ;
V_146:
V_145 ++ ;
}
F_14 () ;
V_144 -> args [ 0 ] = V_145 ;
return V_60 -> V_150 ;
}
static void F_73 ( int V_151 , struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_93 * V_94 ,
T_1 V_132 )
{
struct V_32 * V_32 ;
struct V_59 * V_60 ;
int V_36 = - V_152 ;
V_32 = V_15 -> V_26 ;
V_60 = F_95 ( F_79 ( V_15 , V_2 ) , V_20 ) ;
if ( V_60 == NULL )
goto V_45;
V_36 = F_83 ( V_60 , V_2 , V_132 , V_94 -> V_147 , V_151 , 0 , V_15 ) ;
if ( V_36 < 0 ) {
F_96 ( V_36 == - V_134 ) ;
F_97 ( V_60 ) ;
goto V_45;
}
F_98 ( V_60 , V_32 , V_132 , V_15 -> V_153 , V_94 , V_20 ) ;
return;
V_45:
if ( V_36 < 0 )
F_99 ( V_32 , V_15 -> V_153 , V_36 ) ;
}
static void F_100 ( struct V_29 * V_154 , struct V_106 * V_107 )
{
struct V_1 * V_2 ;
F_20 (rule, rules, list) {
if ( V_2 -> V_3 == - 1 &&
strcmp ( V_107 -> V_155 , V_2 -> V_90 ) == 0 )
V_2 -> V_3 = V_107 -> V_108 ;
if ( V_2 -> V_4 == - 1 &&
strcmp ( V_107 -> V_155 , V_2 -> V_92 ) == 0 )
V_2 -> V_4 = V_107 -> V_108 ;
}
}
static void F_101 ( struct V_29 * V_154 , struct V_106 * V_107 )
{
struct V_1 * V_2 ;
F_20 (rule, rules, list) {
if ( V_2 -> V_3 == V_107 -> V_108 )
V_2 -> V_3 = - 1 ;
if ( V_2 -> V_4 == V_107 -> V_108 )
V_2 -> V_4 = - 1 ;
}
}
static int F_102 ( struct V_156 * V_157 , unsigned long V_151 ,
void * V_158 )
{
struct V_106 * V_107 = F_103 ( V_158 ) ;
struct V_32 * V_32 = F_104 ( V_107 ) ;
struct V_14 * V_15 ;
F_105 () ;
switch ( V_151 ) {
case V_159 :
F_20 (ops, &net->rules_ops, list)
F_100 ( & V_15 -> V_28 , V_107 ) ;
break;
case V_160 :
F_20 (ops, &net->rules_ops, list) {
F_101 ( & V_15 -> V_28 , V_107 ) ;
F_100 ( & V_15 -> V_28 , V_107 ) ;
}
break;
case V_161 :
F_20 (ops, &net->rules_ops, list)
F_101 ( & V_15 -> V_28 , V_107 ) ;
break;
}
return V_162 ;
}
static int T_3 F_106 ( struct V_32 * V_32 )
{
F_26 ( & V_32 -> V_46 ) ;
F_107 ( & V_32 -> V_44 ) ;
return 0 ;
}
static int T_4 F_108 ( void )
{
int V_36 ;
F_109 ( V_163 , V_124 , F_54 , NULL , NULL ) ;
F_109 ( V_163 , V_128 , F_75 , NULL , NULL ) ;
F_109 ( V_163 , V_164 , NULL , F_93 , NULL ) ;
V_36 = F_110 ( & V_165 ) ;
if ( V_36 < 0 )
goto V_166;
V_36 = F_111 ( & V_167 ) ;
if ( V_36 < 0 )
goto V_168;
return 0 ;
V_168:
F_112 ( & V_165 ) ;
V_166:
F_113 ( V_163 , V_124 ) ;
F_113 ( V_163 , V_128 ) ;
F_113 ( V_163 , V_164 ) ;
return V_36 ;
}
