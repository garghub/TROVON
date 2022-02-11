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
static int F_51 ( struct V_83 * V_84 , struct V_32 * V_32 ,
enum V_85 V_86 ,
struct V_1 * V_2 , int V_33 )
{
struct V_87 V_88 = {
. V_88 . V_33 = V_33 ,
. V_2 = V_2 ,
} ;
return F_52 ( V_84 , V_32 , V_86 , & V_88 . V_88 ) ;
}
static int F_53 ( struct V_32 * V_32 ,
enum V_85 V_86 ,
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_87 V_88 = {
. V_88 . V_33 = V_15 -> V_33 ,
. V_2 = V_2 ,
} ;
V_15 -> V_89 ++ ;
return F_54 ( V_32 , V_86 , & V_88 . V_88 ) ;
}
int F_55 ( struct V_32 * V_32 , struct V_83 * V_84 , int V_33 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
V_15 = F_10 ( V_32 , V_33 ) ;
if ( ! V_15 )
return - V_90 ;
F_12 (rule, &ops->rules_list, list)
F_51 ( V_84 , V_32 , V_91 , V_2 ,
V_33 ) ;
F_15 ( V_15 ) ;
return 0 ;
}
unsigned int F_56 ( struct V_32 * V_32 , int V_33 )
{
unsigned int V_89 ;
struct V_14 * V_15 ;
F_57 () ;
V_15 = F_10 ( V_32 , V_33 ) ;
if ( ! V_15 )
return 0 ;
V_89 = V_15 -> V_89 ;
F_15 ( V_15 ) ;
return V_89 ;
}
static int F_58 ( struct V_92 * V_93 , struct V_53 * * V_54 ,
struct V_14 * V_15 )
{
int V_36 = - V_39 ;
if ( V_93 -> V_94 )
if ( V_54 [ V_95 ] == NULL ||
V_93 -> V_94 > ( V_15 -> V_96 * 8 ) ||
F_59 ( V_54 [ V_95 ] ) != V_15 -> V_96 )
goto V_45;
if ( V_93 -> V_97 )
if ( V_54 [ V_98 ] == NULL ||
V_93 -> V_97 > ( V_15 -> V_96 * 8 ) ||
F_59 ( V_54 [ V_98 ] ) != V_15 -> V_96 )
goto V_45;
V_36 = 0 ;
V_45:
return V_36 ;
}
static int F_60 ( struct V_14 * V_15 , struct V_92 * V_93 ,
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
if ( memcmp ( V_18 -> V_99 , V_2 -> V_99 , V_100 ) )
continue;
if ( memcmp ( V_18 -> V_101 , V_2 -> V_101 , V_100 ) )
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
if ( ! V_15 -> V_42 ( V_18 , V_93 , V_54 ) )
continue;
return 1 ;
}
return 0 ;
}
int F_61 ( struct V_59 * V_60 , struct V_102 * V_103 ,
struct V_104 * V_105 )
{
struct V_32 * V_32 = F_62 ( V_60 -> V_106 ) ;
struct V_92 * V_93 = F_63 ( V_103 ) ;
struct V_14 * V_15 = NULL ;
struct V_1 * V_2 , * V_18 , * V_107 = NULL ;
struct V_53 * V_54 [ V_108 + 1 ] ;
int V_36 = - V_39 , V_109 = 0 ;
if ( V_103 -> V_110 < F_64 ( sizeof( * V_93 ) ) )
goto V_45;
V_15 = F_10 ( V_32 , V_93 -> V_33 ) ;
if ( V_15 == NULL ) {
V_36 = - V_90 ;
goto V_45;
}
V_36 = F_65 ( V_103 , sizeof( * V_93 ) , V_54 , V_108 , V_15 -> V_111 , V_105 ) ;
if ( V_36 < 0 )
goto V_45;
V_36 = F_58 ( V_93 , V_54 , V_15 ) ;
if ( V_36 < 0 )
goto V_45;
V_2 = F_4 ( V_15 -> V_19 , V_20 ) ;
if ( V_2 == NULL ) {
V_36 = - V_21 ;
goto V_45;
}
F_5 ( & V_2 -> V_22 , 1 ) ;
V_2 -> V_25 = V_32 ;
V_2 -> V_16 = V_54 [ V_112 ] ? F_66 ( V_54 [ V_112 ] )
: F_7 ( V_15 ) ;
if ( V_54 [ V_113 ] ) {
struct V_114 * V_115 ;
V_2 -> V_3 = - 1 ;
F_67 ( V_2 -> V_99 , V_54 [ V_113 ] , V_100 ) ;
V_115 = F_68 ( V_32 , V_2 -> V_99 ) ;
if ( V_115 )
V_2 -> V_3 = V_115 -> V_116 ;
}
if ( V_54 [ V_117 ] ) {
struct V_114 * V_115 ;
V_2 -> V_4 = - 1 ;
F_67 ( V_2 -> V_101 , V_54 [ V_117 ] , V_100 ) ;
V_115 = F_68 ( V_32 , V_2 -> V_101 ) ;
if ( V_115 )
V_2 -> V_4 = V_115 -> V_116 ;
}
if ( V_54 [ V_118 ] ) {
V_2 -> V_5 = F_66 ( V_54 [ V_118 ] ) ;
if ( V_2 -> V_5 )
V_2 -> V_69 = 0xFFFFFFFF ;
}
if ( V_54 [ V_119 ] )
V_2 -> V_69 = F_66 ( V_54 [ V_119 ] ) ;
if ( V_54 [ V_120 ] )
V_2 -> V_6 = F_69 ( V_54 [ V_120 ] ) ;
V_36 = - V_39 ;
if ( V_54 [ V_121 ] ) {
#ifdef F_70
V_2 -> V_71 = F_71 ( V_54 [ V_121 ] ) ;
if ( V_2 -> V_71 != 1 )
#endif
goto V_122;
}
V_2 -> V_23 = V_93 -> V_23 ;
V_2 -> V_7 = V_93 -> V_7 ;
V_2 -> V_17 = F_72 ( V_93 , V_54 ) ;
if ( V_54 [ V_123 ] )
V_2 -> V_9 = F_66 ( V_54 [ V_123 ] ) ;
else
V_2 -> V_9 = - 1 ;
if ( V_54 [ V_124 ] )
V_2 -> V_8 = F_66 ( V_54 [ V_124 ] ) ;
else
V_2 -> V_8 = - 1 ;
if ( V_54 [ V_125 ] ) {
if ( V_2 -> V_23 != V_75 )
goto V_122;
V_2 -> V_76 = F_66 ( V_54 [ V_125 ] ) ;
if ( V_2 -> V_76 <= V_2 -> V_16 )
goto V_122;
F_20 (r, &ops->rules_list, list) {
if ( V_18 -> V_16 == V_2 -> V_76 ) {
F_73 ( V_2 -> V_77 , V_18 ) ;
break;
}
}
if ( F_74 ( V_2 -> V_77 , 1 ) == NULL )
V_109 = 1 ;
} else if ( V_2 -> V_23 == V_75 )
goto V_122;
if ( V_2 -> V_71 && V_2 -> V_17 )
goto V_122;
if ( V_54 [ V_58 ] ) {
if ( F_39 () != V_32 -> V_126 ) {
V_36 = - V_127 ;
goto V_122;
}
V_2 -> V_10 = F_36 ( V_54 ) ;
if ( ! F_34 ( & V_2 -> V_10 ) ||
! F_75 ( V_2 -> V_10 . V_11 , V_2 -> V_10 . V_13 ) )
goto V_122;
} else {
V_2 -> V_10 = V_12 ;
}
if ( ( V_103 -> V_128 & V_129 ) &&
F_60 ( V_15 , V_93 , V_54 , V_2 ) ) {
V_36 = - V_37 ;
goto V_122;
}
V_36 = V_15 -> V_41 ( V_2 , V_60 , V_93 , V_54 ) ;
if ( V_36 < 0 )
goto V_122;
F_20 (r, &ops->rules_list, list) {
if ( V_18 -> V_16 > V_2 -> V_16 )
break;
V_107 = V_18 ;
}
if ( V_107 )
F_76 ( & V_2 -> V_27 , & V_107 -> V_27 ) ;
else
F_76 ( & V_2 -> V_27 , & V_15 -> V_28 ) ;
if ( V_15 -> V_130 ) {
F_20 (r, &ops->rules_list, list) {
if ( V_18 -> V_23 == V_75 &&
V_18 -> V_76 == V_2 -> V_16 &&
F_77 ( V_18 -> V_77 ) == NULL ) {
F_78 ( V_18 -> V_77 , V_2 ) ;
if ( -- V_15 -> V_130 == 0 )
break;
}
}
}
if ( V_2 -> V_23 == V_75 )
V_15 -> V_131 ++ ;
if ( V_109 )
V_15 -> V_130 ++ ;
if ( V_2 -> V_6 )
F_79 () ;
F_53 ( V_32 , V_91 , V_2 , V_15 ) ;
F_80 ( V_132 , V_2 , V_15 , V_103 , F_81 ( V_60 ) . V_133 ) ;
F_17 ( V_15 ) ;
F_15 ( V_15 ) ;
return 0 ;
V_122:
F_27 ( V_2 ) ;
V_45:
F_15 ( V_15 ) ;
return V_36 ;
}
int F_82 ( struct V_59 * V_60 , struct V_102 * V_103 ,
struct V_104 * V_105 )
{
struct V_32 * V_32 = F_62 ( V_60 -> V_106 ) ;
struct V_92 * V_93 = F_63 ( V_103 ) ;
struct V_14 * V_15 = NULL ;
struct V_1 * V_2 , * V_18 ;
struct V_53 * V_54 [ V_108 + 1 ] ;
struct V_51 V_52 ;
int V_36 = - V_39 ;
if ( V_103 -> V_110 < F_64 ( sizeof( * V_93 ) ) )
goto V_45;
V_15 = F_10 ( V_32 , V_93 -> V_33 ) ;
if ( V_15 == NULL ) {
V_36 = - V_90 ;
goto V_45;
}
V_36 = F_65 ( V_103 , sizeof( * V_93 ) , V_54 , V_108 , V_15 -> V_111 , V_105 ) ;
if ( V_36 < 0 )
goto V_45;
V_36 = F_58 ( V_93 , V_54 , V_15 ) ;
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
if ( V_93 -> V_23 && ( V_93 -> V_23 != V_2 -> V_23 ) )
continue;
if ( F_72 ( V_93 , V_54 ) &&
( F_72 ( V_93 , V_54 ) != V_2 -> V_17 ) )
continue;
if ( V_54 [ V_112 ] &&
( V_2 -> V_16 != F_66 ( V_54 [ V_112 ] ) ) )
continue;
if ( V_54 [ V_113 ] &&
F_83 ( V_54 [ V_113 ] , V_2 -> V_99 ) )
continue;
if ( V_54 [ V_117 ] &&
F_83 ( V_54 [ V_117 ] , V_2 -> V_101 ) )
continue;
if ( V_54 [ V_118 ] &&
( V_2 -> V_5 != F_66 ( V_54 [ V_118 ] ) ) )
continue;
if ( V_54 [ V_119 ] &&
( V_2 -> V_69 != F_66 ( V_54 [ V_119 ] ) ) )
continue;
if ( V_54 [ V_120 ] &&
( V_2 -> V_6 != F_69 ( V_54 [ V_120 ] ) ) )
continue;
if ( V_54 [ V_121 ] &&
( V_2 -> V_71 != F_71 ( V_54 [ V_121 ] ) ) )
continue;
if ( F_34 ( & V_52 ) &&
( ! F_2 ( V_2 -> V_10 . V_11 , V_52 . V_11 ) ||
! F_2 ( V_2 -> V_10 . V_13 , V_52 . V_13 ) ) )
continue;
if ( ! V_15 -> V_42 ( V_2 , V_93 , V_54 ) )
continue;
if ( V_2 -> V_7 & V_134 ) {
V_36 = - V_127 ;
goto V_45;
}
if ( V_15 -> V_49 ) {
V_36 = V_15 -> V_49 ( V_2 ) ;
if ( V_36 )
goto V_45;
}
if ( V_2 -> V_6 )
F_84 () ;
F_30 ( & V_2 -> V_27 ) ;
if ( V_2 -> V_23 == V_75 ) {
V_15 -> V_131 -- ;
if ( F_77 ( V_2 -> V_77 ) == NULL )
V_15 -> V_130 -- ;
}
if ( V_15 -> V_131 > 0 ) {
struct V_1 * V_135 ;
V_135 = F_85 ( V_2 , V_27 ) ;
if ( & V_135 -> V_27 == & V_15 -> V_28 || V_135 -> V_16 != V_2 -> V_16 )
V_135 = NULL ;
F_20 (r, &ops->rules_list, list) {
if ( F_77 ( V_18 -> V_77 ) != V_2 )
continue;
F_78 ( V_18 -> V_77 , V_135 ) ;
if ( ! V_135 )
V_15 -> V_130 ++ ;
}
}
F_53 ( V_32 , V_136 , V_2 , V_15 ) ;
F_80 ( V_137 , V_2 , V_15 , V_103 ,
F_81 ( V_60 ) . V_133 ) ;
F_31 ( V_2 ) ;
F_17 ( V_15 ) ;
F_15 ( V_15 ) ;
return 0 ;
}
V_36 = - V_138 ;
V_45:
F_15 ( V_15 ) ;
return V_36 ;
}
static inline T_2 F_86 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
T_2 V_139 = F_87 ( sizeof( struct V_92 ) )
+ F_88 ( V_100 )
+ F_88 ( V_100 )
+ F_88 ( 4 )
+ F_88 ( 4 )
+ F_88 ( 4 )
+ F_88 ( 4 )
+ F_88 ( 4 )
+ F_88 ( 4 )
+ F_89 ( 8 )
+ F_88 ( sizeof( struct V_51 ) ) ;
if ( V_15 -> V_140 )
V_139 += V_15 -> V_140 ( V_2 ) ;
return V_139 ;
}
static int F_90 ( struct V_59 * V_60 , struct V_1 * V_2 ,
T_1 V_141 , T_1 V_142 , int type , int V_7 ,
struct V_14 * V_15 )
{
struct V_102 * V_103 ;
struct V_92 * V_93 ;
V_103 = F_91 ( V_60 , V_141 , V_142 , type , sizeof( * V_93 ) , V_7 ) ;
if ( V_103 == NULL )
return - V_143 ;
V_93 = F_63 ( V_103 ) ;
V_93 -> V_33 = V_15 -> V_33 ;
V_93 -> V_17 = V_2 -> V_17 ;
if ( F_92 ( V_60 , V_144 , V_2 -> V_17 ) )
goto V_145;
if ( F_92 ( V_60 , V_123 , V_2 -> V_9 ) )
goto V_145;
V_93 -> V_146 = 0 ;
V_93 -> V_147 = 0 ;
V_93 -> V_23 = V_2 -> V_23 ;
V_93 -> V_7 = V_2 -> V_7 ;
if ( V_2 -> V_23 == V_75 &&
F_93 ( V_2 -> V_77 ) == NULL )
V_93 -> V_7 |= V_148 ;
if ( V_2 -> V_99 [ 0 ] ) {
if ( F_94 ( V_60 , V_113 , V_2 -> V_99 ) )
goto V_145;
if ( V_2 -> V_3 == - 1 )
V_93 -> V_7 |= V_149 ;
}
if ( V_2 -> V_101 [ 0 ] ) {
if ( F_94 ( V_60 , V_117 , V_2 -> V_101 ) )
goto V_145;
if ( V_2 -> V_4 == - 1 )
V_93 -> V_7 |= V_150 ;
}
if ( ( V_2 -> V_16 &&
F_92 ( V_60 , V_112 , V_2 -> V_16 ) ) ||
( V_2 -> V_5 &&
F_92 ( V_60 , V_118 , V_2 -> V_5 ) ) ||
( ( V_2 -> V_69 || V_2 -> V_5 ) &&
F_92 ( V_60 , V_119 , V_2 -> V_69 ) ) ||
( V_2 -> V_76 &&
F_92 ( V_60 , V_125 , V_2 -> V_76 ) ) ||
( V_2 -> V_6 &&
F_95 ( V_60 , V_120 , V_2 -> V_6 , V_151 ) ) ||
( V_2 -> V_71 &&
F_96 ( V_60 , V_121 , V_2 -> V_71 ) ) ||
( F_34 ( & V_2 -> V_10 ) &&
F_40 ( V_60 , & V_2 -> V_10 ) ) )
goto V_145;
if ( V_2 -> V_8 != - 1 ) {
if ( F_92 ( V_60 , V_124 , V_2 -> V_8 ) )
goto V_145;
}
if ( V_15 -> V_43 ( V_2 , V_60 , V_93 ) < 0 )
goto V_145;
F_97 ( V_60 , V_103 ) ;
return 0 ;
V_145:
F_98 ( V_60 , V_103 ) ;
return - V_143 ;
}
static int F_99 ( struct V_59 * V_60 , struct V_152 * V_153 ,
struct V_14 * V_15 )
{
int V_154 = 0 ;
struct V_1 * V_2 ;
int V_36 = 0 ;
F_11 () ;
F_12 (rule, &ops->rules_list, list) {
if ( V_154 < V_153 -> args [ 1 ] )
goto V_155;
V_36 = F_90 ( V_60 , V_2 , F_81 ( V_153 -> V_60 ) . V_133 ,
V_153 -> V_103 -> V_156 , V_132 ,
V_157 , V_15 ) ;
if ( V_36 )
break;
V_155:
V_154 ++ ;
}
F_14 () ;
V_153 -> args [ 1 ] = V_154 ;
F_15 ( V_15 ) ;
return V_36 ;
}
static int F_100 ( struct V_59 * V_60 , struct V_152 * V_153 )
{
struct V_32 * V_32 = F_62 ( V_60 -> V_106 ) ;
struct V_14 * V_15 ;
int V_154 = 0 , V_33 ;
V_33 = F_101 ( V_153 -> V_103 ) ;
if ( V_33 != V_158 ) {
V_15 = F_10 ( V_32 , V_33 ) ;
if ( V_15 == NULL )
return - V_90 ;
F_99 ( V_60 , V_153 , V_15 ) ;
return V_60 -> V_159 ;
}
F_11 () ;
F_12 (ops, &net->rules_ops, list) {
if ( V_154 < V_153 -> args [ 0 ] || ! F_13 ( V_15 -> V_34 ) )
goto V_155;
if ( F_99 ( V_60 , V_153 , V_15 ) < 0 )
break;
V_153 -> args [ 1 ] = 0 ;
V_155:
V_154 ++ ;
}
F_14 () ;
V_153 -> args [ 0 ] = V_154 ;
return V_60 -> V_159 ;
}
static void F_80 ( int V_160 , struct V_1 * V_2 ,
struct V_14 * V_15 , struct V_102 * V_103 ,
T_1 V_141 )
{
struct V_32 * V_32 ;
struct V_59 * V_60 ;
int V_36 = - V_161 ;
V_32 = V_15 -> V_26 ;
V_60 = F_102 ( F_86 ( V_15 , V_2 ) , V_20 ) ;
if ( V_60 == NULL )
goto V_45;
V_36 = F_90 ( V_60 , V_2 , V_141 , V_103 -> V_156 , V_160 , 0 , V_15 ) ;
if ( V_36 < 0 ) {
F_103 ( V_36 == - V_143 ) ;
F_104 ( V_60 ) ;
goto V_45;
}
F_105 ( V_60 , V_32 , V_141 , V_15 -> V_162 , V_103 , V_20 ) ;
return;
V_45:
if ( V_36 < 0 )
F_106 ( V_32 , V_15 -> V_162 , V_36 ) ;
}
static void F_107 ( struct V_29 * V_163 , struct V_114 * V_115 )
{
struct V_1 * V_2 ;
F_20 (rule, rules, list) {
if ( V_2 -> V_3 == - 1 &&
strcmp ( V_115 -> V_164 , V_2 -> V_99 ) == 0 )
V_2 -> V_3 = V_115 -> V_116 ;
if ( V_2 -> V_4 == - 1 &&
strcmp ( V_115 -> V_164 , V_2 -> V_101 ) == 0 )
V_2 -> V_4 = V_115 -> V_116 ;
}
}
static void F_108 ( struct V_29 * V_163 , struct V_114 * V_115 )
{
struct V_1 * V_2 ;
F_20 (rule, rules, list) {
if ( V_2 -> V_3 == V_115 -> V_116 )
V_2 -> V_3 = - 1 ;
if ( V_2 -> V_4 == V_115 -> V_116 )
V_2 -> V_4 = - 1 ;
}
}
static int F_109 ( struct V_83 * V_165 , unsigned long V_160 ,
void * V_166 )
{
struct V_114 * V_115 = F_110 ( V_166 ) ;
struct V_32 * V_32 = F_111 ( V_115 ) ;
struct V_14 * V_15 ;
F_57 () ;
switch ( V_160 ) {
case V_167 :
F_20 (ops, &net->rules_ops, list)
F_107 ( & V_15 -> V_28 , V_115 ) ;
break;
case V_168 :
F_20 (ops, &net->rules_ops, list) {
F_108 ( & V_15 -> V_28 , V_115 ) ;
F_107 ( & V_15 -> V_28 , V_115 ) ;
}
break;
case V_169 :
F_20 (ops, &net->rules_ops, list)
F_108 ( & V_15 -> V_28 , V_115 ) ;
break;
}
return V_170 ;
}
static int T_3 F_112 ( struct V_32 * V_32 )
{
F_26 ( & V_32 -> V_46 ) ;
F_113 ( & V_32 -> V_44 ) ;
return 0 ;
}
static int T_4 F_114 ( void )
{
int V_36 ;
F_115 ( V_171 , V_132 , F_61 , NULL , 0 ) ;
F_115 ( V_171 , V_137 , F_82 , NULL , 0 ) ;
F_115 ( V_171 , V_172 , NULL , F_100 , 0 ) ;
V_36 = F_116 ( & V_173 ) ;
if ( V_36 < 0 )
goto V_174;
V_36 = F_117 ( & V_175 ) ;
if ( V_36 < 0 )
goto V_176;
return 0 ;
V_176:
F_118 ( & V_173 ) ;
V_174:
F_119 ( V_171 , V_132 ) ;
F_119 ( V_171 , V_137 ) ;
F_119 ( V_171 , V_172 ) ;
return V_36 ;
}
