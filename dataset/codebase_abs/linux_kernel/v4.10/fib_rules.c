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
V_7 -> V_16 = V_17 ;
V_7 -> V_18 = - 1 ;
V_7 -> V_19 = - 1 ;
F_4 ( & V_7 -> V_20 , & V_2 -> V_21 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_6 * V_24 ;
if ( ! F_6 ( & V_2 -> V_21 ) ) {
V_23 = V_2 -> V_21 . V_25 ;
if ( V_23 -> V_25 != & V_2 -> V_21 ) {
V_24 = F_7 ( V_23 -> V_25 , struct V_6 , V_20 ) ;
if ( V_24 -> V_3 )
return V_24 -> V_3 - 1 ;
}
}
return 0 ;
}
static struct V_1 * F_8 ( struct V_26 * V_26 , int V_27 )
{
struct V_1 * V_2 ;
F_9 () ;
F_10 (ops, &net->rules_ops, list) {
if ( V_2 -> V_27 == V_27 ) {
if ( ! F_11 ( V_2 -> V_28 ) )
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
F_14 ( V_2 -> V_28 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 )
V_2 -> V_29 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_30 = - V_31 ;
struct V_1 * V_32 ;
struct V_26 * V_26 ;
V_26 = V_2 -> V_15 ;
if ( V_2 -> V_8 < sizeof( struct V_6 ) )
return - V_33 ;
if ( V_2 -> V_34 == NULL || V_2 -> V_35 == NULL ||
V_2 -> V_36 == NULL || V_2 -> V_37 == NULL ||
V_2 -> V_12 == NULL )
return - V_33 ;
F_17 ( & V_26 -> V_38 ) ;
F_18 (o, &net->rules_ops, list)
if ( V_2 -> V_27 == V_32 -> V_27 )
goto V_39;
F_19 ( & V_2 -> V_20 , & V_26 -> V_40 ) ;
V_30 = 0 ;
V_39:
F_20 ( & V_26 -> V_38 ) ;
return V_30 ;
}
struct V_1 *
F_21 ( const struct V_1 * V_41 , struct V_26 * V_26 )
{
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_22 ( V_41 , sizeof( * V_2 ) , V_9 ) ;
if ( V_2 == NULL )
return F_23 ( - V_10 ) ;
F_24 ( & V_2 -> V_21 ) ;
V_2 -> V_15 = V_26 ;
V_30 = F_16 ( V_2 ) ;
if ( V_30 ) {
F_25 ( V_2 ) ;
V_2 = F_23 ( V_30 ) ;
}
return V_2 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_24 , * V_42 ;
F_27 (rule, tmp, &ops->rules_list, list) {
F_28 ( & V_24 -> V_20 ) ;
if ( V_2 -> V_43 )
V_2 -> V_43 ( V_24 ) ;
F_29 ( V_24 ) ;
}
}
void F_30 ( struct V_1 * V_2 )
{
struct V_26 * V_26 = V_2 -> V_15 ;
F_17 ( & V_26 -> V_38 ) ;
F_28 ( & V_2 -> V_20 ) ;
F_20 ( & V_26 -> V_38 ) ;
F_26 ( V_2 ) ;
F_31 ( V_2 , V_44 ) ;
}
static int F_32 ( struct V_45 * V_46 )
{
return F_33 ( V_46 -> V_47 ) && F_33 ( V_46 -> V_48 ) ;
}
static struct V_45 F_34 ( struct V_49 * * V_50 )
{
struct V_51 * V_52 ;
struct V_45 V_53 ;
V_52 = (struct V_51 * ) F_35 ( V_50 [ V_54 ] ) ;
V_53 . V_47 = F_36 ( F_37 () , V_52 -> V_47 ) ;
V_53 . V_48 = F_36 ( F_37 () , V_52 -> V_48 ) ;
return V_53 ;
}
static int F_38 ( struct V_55 * V_56 , struct V_45 * V_46 )
{
struct V_51 V_53 = {
F_39 ( F_37 () , V_46 -> V_47 ) ,
F_39 (current_user_ns(), range->end)
} ;
return F_40 ( V_56 , V_54 , sizeof( V_53 ) , & V_53 ) ;
}
static int F_41 ( struct V_6 * V_24 , struct V_1 * V_2 ,
struct V_57 * V_58 , int V_5 ,
struct V_59 * V_60 )
{
int V_61 = 0 ;
if ( V_24 -> V_62 && ( V_24 -> V_62 != V_58 -> V_63 ) )
goto V_53;
if ( V_24 -> V_64 && ( V_24 -> V_64 != V_58 -> V_65 ) )
goto V_53;
if ( ( V_24 -> V_66 ^ V_58 -> V_67 ) & V_24 -> V_68 )
goto V_53;
if ( V_24 -> V_69 && ( V_24 -> V_69 != V_58 -> V_70 . V_69 ) )
goto V_53;
if ( V_24 -> V_71 && ! F_42 ( V_24 -> V_14 , V_58 , V_60 ) )
goto V_53;
if ( F_43 ( V_58 -> V_72 , V_24 -> V_16 . V_47 ) ||
F_44 ( V_58 -> V_72 , V_24 -> V_16 . V_48 ) )
goto V_53;
V_61 = V_2 -> V_34 ( V_24 , V_58 , V_5 ) ;
V_53:
return ( V_24 -> V_5 & V_73 ) ? ! V_61 : V_61 ;
}
int F_45 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_5 , struct V_59 * V_60 )
{
struct V_6 * V_24 ;
int V_30 ;
F_9 () ;
F_10 (rule, &ops->rules_list, list) {
V_74:
if ( ! F_41 ( V_24 , V_2 , V_58 , V_5 , V_60 ) )
continue;
if ( V_24 -> V_12 == V_75 ) {
struct V_6 * V_76 ;
V_76 = F_46 ( V_24 -> V_77 ) ;
if ( V_76 == NULL ) {
continue;
} else {
V_24 = V_76 ;
goto V_74;
}
} else if ( V_24 -> V_12 == V_78 )
continue;
else
V_30 = V_2 -> V_12 ( V_24 , V_58 , V_5 , V_60 ) ;
if ( ! V_30 && V_2 -> V_79 && V_2 -> V_79 ( V_24 , V_60 ) )
continue;
if ( V_30 != - V_80 ) {
if ( ( V_60 -> V_5 & V_81 ) ||
F_47 ( F_48 ( & V_24 -> V_11 ) ) ) {
V_60 -> V_24 = V_24 ;
goto V_53;
}
break;
}
}
V_30 = - V_82 ;
V_53:
F_12 () ;
return V_30 ;
}
static int F_49 ( struct V_83 * V_84 , struct V_49 * * V_50 ,
struct V_1 * V_2 )
{
int V_30 = - V_33 ;
if ( V_84 -> V_85 )
if ( V_50 [ V_86 ] == NULL ||
V_84 -> V_85 > ( V_2 -> V_87 * 8 ) ||
F_50 ( V_50 [ V_86 ] ) != V_2 -> V_87 )
goto V_39;
if ( V_84 -> V_88 )
if ( V_50 [ V_89 ] == NULL ||
V_84 -> V_88 > ( V_2 -> V_87 * 8 ) ||
F_50 ( V_50 [ V_89 ] ) != V_2 -> V_87 )
goto V_39;
V_30 = 0 ;
V_39:
return V_30 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_49 * * V_50 , struct V_6 * V_24 )
{
struct V_6 * V_7 ;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 != V_24 -> V_12 )
continue;
if ( V_7 -> V_4 != V_24 -> V_4 )
continue;
if ( V_7 -> V_3 != V_24 -> V_3 )
continue;
if ( memcmp ( V_7 -> V_90 , V_24 -> V_90 , V_91 ) )
continue;
if ( memcmp ( V_7 -> V_92 , V_24 -> V_92 , V_91 ) )
continue;
if ( V_7 -> V_66 != V_24 -> V_66 )
continue;
if ( V_7 -> V_68 != V_24 -> V_68 )
continue;
if ( V_7 -> V_69 != V_24 -> V_69 )
continue;
if ( V_7 -> V_14 != V_24 -> V_14 )
continue;
if ( V_7 -> V_71 != V_24 -> V_71 )
continue;
if ( ! F_52 ( V_7 -> V_16 . V_47 , V_24 -> V_16 . V_47 ) ||
! F_52 ( V_7 -> V_16 . V_48 , V_24 -> V_16 . V_48 ) )
continue;
if ( ! V_2 -> V_36 ( V_7 , V_84 , V_50 ) )
continue;
return 1 ;
}
return 0 ;
}
int F_53 ( struct V_55 * V_56 , struct V_93 * V_94 )
{
struct V_26 * V_26 = F_54 ( V_56 -> V_95 ) ;
struct V_83 * V_84 = F_55 ( V_94 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_24 , * V_7 , * V_96 = NULL ;
struct V_49 * V_50 [ V_97 + 1 ] ;
int V_30 = - V_33 , V_98 = 0 ;
if ( V_94 -> V_99 < F_56 ( sizeof( * V_84 ) ) )
goto V_39;
V_2 = F_8 ( V_26 , V_84 -> V_27 ) ;
if ( V_2 == NULL ) {
V_30 = - V_100 ;
goto V_39;
}
V_30 = F_57 ( V_94 , sizeof( * V_84 ) , V_50 , V_97 , V_2 -> V_101 ) ;
if ( V_30 < 0 )
goto V_39;
V_30 = F_49 ( V_84 , V_50 , V_2 ) ;
if ( V_30 < 0 )
goto V_39;
V_24 = F_2 ( V_2 -> V_8 , V_9 ) ;
if ( V_24 == NULL ) {
V_30 = - V_10 ;
goto V_39;
}
V_24 -> V_14 = V_26 ;
V_24 -> V_3 = V_50 [ V_102 ] ? F_58 ( V_50 [ V_102 ] )
: F_5 ( V_2 ) ;
if ( V_50 [ V_103 ] ) {
struct V_104 * V_105 ;
V_24 -> V_62 = - 1 ;
F_59 ( V_24 -> V_90 , V_50 [ V_103 ] , V_91 ) ;
V_105 = F_60 ( V_26 , V_24 -> V_90 ) ;
if ( V_105 )
V_24 -> V_62 = V_105 -> V_106 ;
}
if ( V_50 [ V_107 ] ) {
struct V_104 * V_105 ;
V_24 -> V_64 = - 1 ;
F_59 ( V_24 -> V_92 , V_50 [ V_107 ] , V_91 ) ;
V_105 = F_60 ( V_26 , V_24 -> V_92 ) ;
if ( V_105 )
V_24 -> V_64 = V_105 -> V_106 ;
}
if ( V_50 [ V_108 ] ) {
V_24 -> V_66 = F_58 ( V_50 [ V_108 ] ) ;
if ( V_24 -> V_66 )
V_24 -> V_68 = 0xFFFFFFFF ;
}
if ( V_50 [ V_109 ] )
V_24 -> V_68 = F_58 ( V_50 [ V_109 ] ) ;
if ( V_50 [ V_110 ] )
V_24 -> V_69 = F_61 ( V_50 [ V_110 ] ) ;
if ( V_50 [ V_111 ] ) {
#ifdef F_62
V_24 -> V_71 = F_63 ( V_50 [ V_111 ] ) ;
if ( V_24 -> V_71 != 1 )
#endif
goto V_112;
}
V_24 -> V_12 = V_84 -> V_12 ;
V_24 -> V_5 = V_84 -> V_5 ;
V_24 -> V_4 = F_64 ( V_84 , V_50 ) ;
if ( V_50 [ V_113 ] )
V_24 -> V_18 = F_58 ( V_50 [ V_113 ] ) ;
else
V_24 -> V_18 = - 1 ;
if ( V_50 [ V_114 ] )
V_24 -> V_19 = F_58 ( V_50 [ V_114 ] ) ;
else
V_24 -> V_19 = - 1 ;
V_30 = - V_33 ;
if ( V_50 [ V_115 ] ) {
if ( V_24 -> V_12 != V_75 )
goto V_112;
V_24 -> V_76 = F_58 ( V_50 [ V_115 ] ) ;
if ( V_24 -> V_76 <= V_24 -> V_3 )
goto V_112;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 == V_24 -> V_76 ) {
F_65 ( V_24 -> V_77 , V_7 ) ;
break;
}
}
if ( F_66 ( V_24 -> V_77 , 1 ) == NULL )
V_98 = 1 ;
} else if ( V_24 -> V_12 == V_75 )
goto V_112;
if ( V_24 -> V_71 && V_24 -> V_4 )
goto V_112;
if ( V_50 [ V_54 ] ) {
if ( F_37 () != V_26 -> V_116 ) {
V_30 = - V_117 ;
goto V_112;
}
V_24 -> V_16 = F_34 ( V_50 ) ;
if ( ! F_32 ( & V_24 -> V_16 ) ||
! F_67 ( V_24 -> V_16 . V_47 , V_24 -> V_16 . V_48 ) )
goto V_112;
} else {
V_24 -> V_16 = V_17 ;
}
if ( ( V_94 -> V_118 & V_119 ) &&
F_51 ( V_2 , V_84 , V_50 , V_24 ) ) {
V_30 = - V_31 ;
goto V_112;
}
V_30 = V_2 -> V_35 ( V_24 , V_56 , V_84 , V_50 ) ;
if ( V_30 < 0 )
goto V_112;
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_3 > V_24 -> V_3 )
break;
V_96 = V_7 ;
}
F_68 ( V_24 ) ;
if ( V_96 )
F_69 ( & V_24 -> V_20 , & V_96 -> V_20 ) ;
else
F_69 ( & V_24 -> V_20 , & V_2 -> V_21 ) ;
if ( V_2 -> V_120 ) {
F_18 (r, &ops->rules_list, list) {
if ( V_7 -> V_12 == V_75 &&
V_7 -> V_76 == V_24 -> V_3 &&
F_70 ( V_7 -> V_77 ) == NULL ) {
F_71 ( V_7 -> V_77 , V_24 ) ;
if ( -- V_2 -> V_120 == 0 )
break;
}
}
}
if ( V_24 -> V_12 == V_75 )
V_2 -> V_121 ++ ;
if ( V_98 )
V_2 -> V_120 ++ ;
if ( V_24 -> V_69 )
F_72 () ;
F_73 ( V_122 , V_24 , V_2 , V_94 , F_74 ( V_56 ) . V_123 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
V_112:
F_25 ( V_24 ) ;
V_39:
F_13 ( V_2 ) ;
return V_30 ;
}
int F_75 ( struct V_55 * V_56 , struct V_93 * V_94 )
{
struct V_26 * V_26 = F_54 ( V_56 -> V_95 ) ;
struct V_83 * V_84 = F_55 ( V_94 ) ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_24 , * V_42 ;
struct V_49 * V_50 [ V_97 + 1 ] ;
struct V_45 V_46 ;
int V_30 = - V_33 ;
if ( V_94 -> V_99 < F_56 ( sizeof( * V_84 ) ) )
goto V_39;
V_2 = F_8 ( V_26 , V_84 -> V_27 ) ;
if ( V_2 == NULL ) {
V_30 = - V_100 ;
goto V_39;
}
V_30 = F_57 ( V_94 , sizeof( * V_84 ) , V_50 , V_97 , V_2 -> V_101 ) ;
if ( V_30 < 0 )
goto V_39;
V_30 = F_49 ( V_84 , V_50 , V_2 ) ;
if ( V_30 < 0 )
goto V_39;
if ( V_50 [ V_54 ] ) {
V_46 = F_34 ( V_50 ) ;
if ( ! F_32 ( & V_46 ) )
goto V_39;
} else {
V_46 = V_17 ;
}
F_18 (rule, &ops->rules_list, list) {
if ( V_84 -> V_12 && ( V_84 -> V_12 != V_24 -> V_12 ) )
continue;
if ( F_64 ( V_84 , V_50 ) &&
( F_64 ( V_84 , V_50 ) != V_24 -> V_4 ) )
continue;
if ( V_50 [ V_102 ] &&
( V_24 -> V_3 != F_58 ( V_50 [ V_102 ] ) ) )
continue;
if ( V_50 [ V_103 ] &&
F_76 ( V_50 [ V_103 ] , V_24 -> V_90 ) )
continue;
if ( V_50 [ V_107 ] &&
F_76 ( V_50 [ V_107 ] , V_24 -> V_92 ) )
continue;
if ( V_50 [ V_108 ] &&
( V_24 -> V_66 != F_58 ( V_50 [ V_108 ] ) ) )
continue;
if ( V_50 [ V_109 ] &&
( V_24 -> V_68 != F_58 ( V_50 [ V_109 ] ) ) )
continue;
if ( V_50 [ V_110 ] &&
( V_24 -> V_69 != F_61 ( V_50 [ V_110 ] ) ) )
continue;
if ( V_50 [ V_111 ] &&
( V_24 -> V_71 != F_63 ( V_50 [ V_111 ] ) ) )
continue;
if ( F_32 ( & V_46 ) &&
( ! F_52 ( V_24 -> V_16 . V_47 , V_46 . V_47 ) ||
! F_52 ( V_24 -> V_16 . V_48 , V_46 . V_48 ) ) )
continue;
if ( ! V_2 -> V_36 ( V_24 , V_84 , V_50 ) )
continue;
if ( V_24 -> V_5 & V_124 ) {
V_30 = - V_117 ;
goto V_39;
}
if ( V_2 -> V_43 ) {
V_30 = V_2 -> V_43 ( V_24 ) ;
if ( V_30 )
goto V_39;
}
if ( V_24 -> V_69 )
F_77 () ;
F_28 ( & V_24 -> V_20 ) ;
if ( V_24 -> V_12 == V_75 ) {
V_2 -> V_121 -- ;
if ( F_70 ( V_24 -> V_77 ) == NULL )
V_2 -> V_120 -- ;
}
if ( V_2 -> V_121 > 0 ) {
F_18 (tmp, &ops->rules_list, list) {
if ( F_70 ( V_42 -> V_77 ) == V_24 ) {
F_65 ( V_42 -> V_77 , NULL ) ;
V_2 -> V_120 ++ ;
}
}
}
F_73 ( V_125 , V_24 , V_2 , V_94 ,
F_74 ( V_56 ) . V_123 ) ;
F_29 ( V_24 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
V_30 = - V_126 ;
V_39:
F_13 ( V_2 ) ;
return V_30 ;
}
static inline T_2 F_78 ( struct V_1 * V_2 ,
struct V_6 * V_24 )
{
T_2 V_127 = F_79 ( sizeof( struct V_83 ) )
+ F_80 ( V_91 )
+ F_80 ( V_91 )
+ F_80 ( 4 )
+ F_80 ( 4 )
+ F_80 ( 4 )
+ F_80 ( 4 )
+ F_80 ( 4 )
+ F_80 ( 4 )
+ F_81 ( 8 )
+ F_80 ( sizeof( struct V_45 ) ) ;
if ( V_2 -> V_128 )
V_127 += V_2 -> V_128 ( V_24 ) ;
return V_127 ;
}
static int F_82 ( struct V_55 * V_56 , struct V_6 * V_24 ,
T_1 V_129 , T_1 V_130 , int type , int V_5 ,
struct V_1 * V_2 )
{
struct V_93 * V_94 ;
struct V_83 * V_84 ;
V_94 = F_83 ( V_56 , V_129 , V_130 , type , sizeof( * V_84 ) , V_5 ) ;
if ( V_94 == NULL )
return - V_131 ;
V_84 = F_55 ( V_94 ) ;
V_84 -> V_27 = V_2 -> V_27 ;
V_84 -> V_4 = V_24 -> V_4 ;
if ( F_84 ( V_56 , V_132 , V_24 -> V_4 ) )
goto V_133;
if ( F_84 ( V_56 , V_113 , V_24 -> V_18 ) )
goto V_133;
V_84 -> V_134 = 0 ;
V_84 -> V_135 = 0 ;
V_84 -> V_12 = V_24 -> V_12 ;
V_84 -> V_5 = V_24 -> V_5 ;
if ( V_24 -> V_12 == V_75 &&
F_85 ( V_24 -> V_77 ) == NULL )
V_84 -> V_5 |= V_136 ;
if ( V_24 -> V_90 [ 0 ] ) {
if ( F_86 ( V_56 , V_103 , V_24 -> V_90 ) )
goto V_133;
if ( V_24 -> V_62 == - 1 )
V_84 -> V_5 |= V_137 ;
}
if ( V_24 -> V_92 [ 0 ] ) {
if ( F_86 ( V_56 , V_107 , V_24 -> V_92 ) )
goto V_133;
if ( V_24 -> V_64 == - 1 )
V_84 -> V_5 |= V_138 ;
}
if ( ( V_24 -> V_3 &&
F_84 ( V_56 , V_102 , V_24 -> V_3 ) ) ||
( V_24 -> V_66 &&
F_84 ( V_56 , V_108 , V_24 -> V_66 ) ) ||
( ( V_24 -> V_68 || V_24 -> V_66 ) &&
F_84 ( V_56 , V_109 , V_24 -> V_68 ) ) ||
( V_24 -> V_76 &&
F_84 ( V_56 , V_115 , V_24 -> V_76 ) ) ||
( V_24 -> V_69 &&
F_87 ( V_56 , V_110 , V_24 -> V_69 , V_139 ) ) ||
( V_24 -> V_71 &&
F_88 ( V_56 , V_111 , V_24 -> V_71 ) ) ||
( F_32 ( & V_24 -> V_16 ) &&
F_38 ( V_56 , & V_24 -> V_16 ) ) )
goto V_133;
if ( V_24 -> V_19 != - 1 ) {
if ( F_84 ( V_56 , V_114 , V_24 -> V_19 ) )
goto V_133;
}
if ( V_2 -> V_37 ( V_24 , V_56 , V_84 ) < 0 )
goto V_133;
F_89 ( V_56 , V_94 ) ;
return 0 ;
V_133:
F_90 ( V_56 , V_94 ) ;
return - V_131 ;
}
static int F_91 ( struct V_55 * V_56 , struct V_140 * V_141 ,
struct V_1 * V_2 )
{
int V_142 = 0 ;
struct V_6 * V_24 ;
int V_30 = 0 ;
F_9 () ;
F_10 (rule, &ops->rules_list, list) {
if ( V_142 < V_141 -> args [ 1 ] )
goto V_143;
V_30 = F_82 ( V_56 , V_24 , F_74 ( V_141 -> V_56 ) . V_123 ,
V_141 -> V_94 -> V_144 , V_122 ,
V_145 , V_2 ) ;
if ( V_30 )
break;
V_143:
V_142 ++ ;
}
F_12 () ;
V_141 -> args [ 1 ] = V_142 ;
F_13 ( V_2 ) ;
return V_30 ;
}
static int F_92 ( struct V_55 * V_56 , struct V_140 * V_141 )
{
struct V_26 * V_26 = F_54 ( V_56 -> V_95 ) ;
struct V_1 * V_2 ;
int V_142 = 0 , V_27 ;
V_27 = F_93 ( V_141 -> V_94 ) ;
if ( V_27 != V_146 ) {
V_2 = F_8 ( V_26 , V_27 ) ;
if ( V_2 == NULL )
return - V_100 ;
F_91 ( V_56 , V_141 , V_2 ) ;
return V_56 -> V_147 ;
}
F_9 () ;
F_10 (ops, &net->rules_ops, list) {
if ( V_142 < V_141 -> args [ 0 ] || ! F_11 ( V_2 -> V_28 ) )
goto V_143;
if ( F_91 ( V_56 , V_141 , V_2 ) < 0 )
break;
V_141 -> args [ 1 ] = 0 ;
V_143:
V_142 ++ ;
}
F_12 () ;
V_141 -> args [ 0 ] = V_142 ;
return V_56 -> V_147 ;
}
static void F_73 ( int V_148 , struct V_6 * V_24 ,
struct V_1 * V_2 , struct V_93 * V_94 ,
T_1 V_129 )
{
struct V_26 * V_26 ;
struct V_55 * V_56 ;
int V_30 = - V_149 ;
V_26 = V_2 -> V_15 ;
V_56 = F_94 ( F_78 ( V_2 , V_24 ) , V_9 ) ;
if ( V_56 == NULL )
goto V_39;
V_30 = F_82 ( V_56 , V_24 , V_129 , V_94 -> V_144 , V_148 , 0 , V_2 ) ;
if ( V_30 < 0 ) {
F_95 ( V_30 == - V_131 ) ;
F_96 ( V_56 ) ;
goto V_39;
}
F_97 ( V_56 , V_26 , V_129 , V_2 -> V_150 , V_94 , V_9 ) ;
return;
V_39:
if ( V_30 < 0 )
F_98 ( V_26 , V_2 -> V_150 , V_30 ) ;
}
static void F_99 ( struct V_22 * V_151 , struct V_104 * V_105 )
{
struct V_6 * V_24 ;
F_18 (rule, rules, list) {
if ( V_24 -> V_62 == - 1 &&
strcmp ( V_105 -> V_152 , V_24 -> V_90 ) == 0 )
V_24 -> V_62 = V_105 -> V_106 ;
if ( V_24 -> V_64 == - 1 &&
strcmp ( V_105 -> V_152 , V_24 -> V_92 ) == 0 )
V_24 -> V_64 = V_105 -> V_106 ;
}
}
static void F_100 ( struct V_22 * V_151 , struct V_104 * V_105 )
{
struct V_6 * V_24 ;
F_18 (rule, rules, list) {
if ( V_24 -> V_62 == V_105 -> V_106 )
V_24 -> V_62 = - 1 ;
if ( V_24 -> V_64 == V_105 -> V_106 )
V_24 -> V_64 = - 1 ;
}
}
static int F_101 ( struct V_153 * V_154 , unsigned long V_148 ,
void * V_155 )
{
struct V_104 * V_105 = F_102 ( V_155 ) ;
struct V_26 * V_26 = F_103 ( V_105 ) ;
struct V_1 * V_2 ;
F_104 () ;
switch ( V_148 ) {
case V_156 :
F_18 (ops, &net->rules_ops, list)
F_99 ( & V_2 -> V_21 , V_105 ) ;
break;
case V_157 :
F_18 (ops, &net->rules_ops, list) {
F_100 ( & V_2 -> V_21 , V_105 ) ;
F_99 ( & V_2 -> V_21 , V_105 ) ;
}
break;
case V_158 :
F_18 (ops, &net->rules_ops, list)
F_100 ( & V_2 -> V_21 , V_105 ) ;
break;
}
return V_159 ;
}
static int T_3 F_105 ( struct V_26 * V_26 )
{
F_24 ( & V_26 -> V_40 ) ;
F_106 ( & V_26 -> V_38 ) ;
return 0 ;
}
static int T_4 F_107 ( void )
{
int V_30 ;
F_108 ( V_160 , V_122 , F_53 , NULL , NULL ) ;
F_108 ( V_160 , V_125 , F_75 , NULL , NULL ) ;
F_108 ( V_160 , V_161 , NULL , F_92 , NULL ) ;
V_30 = F_109 ( & V_162 ) ;
if ( V_30 < 0 )
goto V_163;
V_30 = F_110 ( & V_164 ) ;
if ( V_30 < 0 )
goto V_165;
return 0 ;
V_165:
F_111 ( & V_162 ) ;
V_163:
F_112 ( V_160 , V_122 ) ;
F_112 ( V_160 , V_125 ) ;
F_112 ( V_160 , V_161 ) ;
return V_30 ;
}
