static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_5 * V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( ( V_7 ) && ( ! V_6 ) ) {
F_3 ( V_8 , V_2 ,
L_1 , V_4 -> V_9 ) ;
F_4 ( V_2 , V_4 ,
L_2 ) ;
} else if ( ( ! V_7 ) && ( V_6 ) ) {
F_3 ( V_8 , V_2 ,
L_3 ,
V_4 -> V_9 , V_6 -> V_10 ) ;
} else if ( V_6 && V_7 ) {
F_3 ( V_8 , V_2 ,
L_4 ,
V_4 -> V_9 , V_6 -> V_10 ,
V_7 -> V_10 ) ;
}
if ( V_7 )
F_5 ( V_7 ) ;
if ( V_6 && ! F_6 ( & V_6 -> V_11 ) )
V_6 = NULL ;
F_7 ( & V_4 -> V_12 ) ;
F_8 ( V_4 -> V_13 , V_6 ) ;
F_9 ( & V_4 -> V_12 ) ;
if ( V_7 )
F_5 ( V_7 ) ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_5 * V_13 = NULL ;
if ( ! V_4 )
goto V_14;
V_13 = F_2 ( V_4 ) ;
if ( V_13 != V_6 )
F_1 ( V_2 , V_4 , V_6 ) ;
V_14:
if ( V_13 )
F_5 ( V_13 ) ;
}
void F_11 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( F_12 ( & V_6 -> V_15 ) )
goto V_14;
F_13 ( & V_6 -> V_15 ) ;
F_14 ( & V_6 -> V_15 ) ;
F_5 ( V_6 ) ;
F_15 ( & V_4 -> V_16 ) ;
V_14:
return;
}
void F_16 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_5 * V_17 , * V_13 = NULL ;
T_1 V_18 = 0 ;
F_7 ( & V_4 -> V_12 ) ;
if ( ! F_17 ( V_4 -> V_9 ,
V_6 -> V_4 -> V_19 ) )
goto V_20;
V_13 = F_2 ( V_4 ) ;
if ( ! V_13 )
goto V_20;
if ( V_6 -> V_21 < V_13 -> V_21 - V_22 )
goto V_20;
F_18 (tmp_neigh_node,
&orig_node->neigh_list, list) {
if ( V_17 == V_6 )
continue;
if ( F_12 ( & V_17 -> V_15 ) )
continue;
if ( ( V_6 -> V_23 == V_17 -> V_23 ) ||
( F_17 ( V_6 -> V_10 ,
V_17 -> V_10 ) ) ) {
V_18 = 1 ;
break;
}
}
if ( V_18 )
goto V_20;
if ( ! F_12 ( & V_6 -> V_15 ) )
goto V_14;
if ( ! F_6 ( & V_6 -> V_11 ) )
goto V_14;
F_19 ( & V_6 -> V_15 , & V_4 -> V_24 ) ;
F_20 ( & V_4 -> V_16 ) ;
goto V_14;
V_20:
F_11 ( V_4 , V_6 ) ;
V_14:
F_9 ( & V_4 -> V_12 ) ;
if ( V_13 )
F_5 ( V_13 ) ;
}
void
F_21 ( const struct V_3 * V_4 ,
struct V_3 * V_25 ,
const struct V_26 * V_27 )
{
if ( ! ( V_27 -> V_28 & V_29 ) )
return;
memcpy ( V_25 -> V_19 , V_4 -> V_9 , V_30 ) ;
}
int F_22 ( struct V_1 * V_2 , T_2 V_31 ,
unsigned long * V_32 )
{
if ( V_31 <= - V_33 ||
V_31 >= V_34 ) {
if ( ! F_23 ( * V_32 ,
V_35 ) )
return 1 ;
* V_32 = V_36 ;
F_3 ( V_37 , V_2 ,
L_5 ) ;
}
return 0 ;
}
bool F_24 ( struct V_38 * V_39 ,
struct V_40 * V_41 ,
int V_42 )
{
struct V_43 * V_43 ;
if ( F_25 ( ! F_26 ( V_39 , V_42 ) ) )
return false ;
V_43 = F_27 ( V_39 ) ;
if ( ! F_28 ( V_43 -> V_44 ) )
return false ;
if ( F_28 ( V_43 -> V_45 ) )
return false ;
if ( F_29 ( V_39 , 0 ) < 0 )
return false ;
if ( F_30 ( V_39 ) < 0 )
return false ;
return true ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_38 * V_39 , T_3 V_46 )
{
struct V_40 * V_47 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_48 * V_49 ;
int V_50 = V_51 ;
V_49 = (struct V_48 * ) V_39 -> V_52 ;
if ( V_49 -> V_53 != V_54 ) {
F_32 ( V_49 , V_46 ) ;
goto V_14;
}
V_47 = F_33 ( V_2 ) ;
if ( ! V_47 )
goto V_14;
V_4 = F_34 ( V_2 , V_49 -> V_9 ) ;
if ( ! V_4 )
goto V_14;
if ( F_29 ( V_39 , V_55 ) < 0 )
goto V_14;
V_49 = (struct V_48 * ) V_39 -> V_52 ;
memcpy ( V_49 -> V_56 , V_49 -> V_9 , V_30 ) ;
memcpy ( V_49 -> V_9 , V_47 -> V_57 -> V_58 , V_30 ) ;
V_49 -> V_53 = V_59 ;
V_49 -> V_60 . V_61 = V_62 ;
if ( F_35 ( V_39 , V_4 , NULL ) != V_63 )
V_50 = V_64 ;
V_14:
if ( V_47 )
F_36 ( V_47 ) ;
if ( V_4 )
F_37 ( V_4 ) ;
return V_50 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_40 * V_47 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_65 * V_49 ;
int V_50 = V_51 ;
V_49 = (struct V_65 * ) V_39 -> V_52 ;
if ( V_49 -> V_53 != V_54 ) {
F_39 ( L_6 ,
V_49 -> V_9 , V_49 -> V_56 ) ;
goto V_14;
}
V_47 = F_33 ( V_2 ) ;
if ( ! V_47 )
goto V_14;
V_4 = F_34 ( V_2 , V_49 -> V_9 ) ;
if ( ! V_4 )
goto V_14;
if ( F_29 ( V_39 , V_55 ) < 0 )
goto V_14;
V_49 = (struct V_65 * ) V_39 -> V_52 ;
memcpy ( V_49 -> V_56 , V_49 -> V_9 , V_30 ) ;
memcpy ( V_49 -> V_9 , V_47 -> V_57 -> V_58 , V_30 ) ;
V_49 -> V_53 = V_66 ;
V_49 -> V_60 . V_61 = V_62 ;
if ( F_35 ( V_39 , V_4 , NULL ) != V_63 )
V_50 = V_64 ;
V_14:
if ( V_47 )
F_36 ( V_47 ) ;
if ( V_4 )
F_37 ( V_4 ) ;
return V_50 ;
}
int F_40 ( struct V_38 * V_39 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
struct V_48 * V_49 ;
struct V_43 * V_43 ;
struct V_3 * V_4 = NULL ;
int V_69 = sizeof( struct V_65 ) ;
int V_50 = V_51 ;
if ( V_39 -> V_70 >= sizeof( struct V_48 ) )
V_69 = sizeof( struct V_48 ) ;
if ( F_25 ( ! F_26 ( V_39 , V_69 ) ) )
goto V_14;
V_43 = F_27 ( V_39 ) ;
if ( F_28 ( V_43 -> V_44 ) )
goto V_14;
if ( F_28 ( V_43 -> V_45 ) )
goto V_14;
if ( ! F_42 ( V_2 , V_43 -> V_44 ) )
goto V_14;
V_49 = (struct V_48 * ) V_39 -> V_52 ;
if ( ( V_69 == sizeof( struct V_48 ) ) &&
( V_49 -> V_71 < V_72 ) ) {
memcpy ( & ( V_49 -> V_73 [ V_49 -> V_71 ] ) ,
V_43 -> V_44 , V_30 ) ;
V_49 -> V_71 ++ ;
}
if ( F_42 ( V_2 , V_49 -> V_56 ) )
return F_31 ( V_2 , V_39 , V_69 ) ;
if ( V_49 -> V_60 . V_61 < 2 )
return F_38 ( V_2 , V_39 ) ;
V_4 = F_34 ( V_2 , V_49 -> V_56 ) ;
if ( ! V_4 )
goto V_14;
if ( F_29 ( V_39 , V_55 ) < 0 )
goto V_14;
V_49 = (struct V_48 * ) V_39 -> V_52 ;
V_49 -> V_60 . V_61 -- ;
if ( F_35 ( V_39 , V_4 , V_67 ) != V_63 )
V_50 = V_64 ;
V_14:
if ( V_4 )
F_37 ( V_4 ) ;
return V_50 ;
}
static struct V_5 *
F_43 ( struct V_3 * V_74 ,
const struct V_40 * V_67 )
{
struct V_5 * V_17 ;
struct V_5 * V_13 = NULL , * V_75 = NULL ;
F_44 () ;
F_45 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_75 )
V_75 = V_17 ;
if ( V_17 -> V_23 == V_67 )
continue;
if ( ! F_6 ( & V_17 -> V_11 ) )
continue;
V_13 = V_17 ;
break;
}
if ( ! V_13 && V_75 &&
F_6 ( & V_75 -> V_11 ) )
V_13 = V_75 ;
if ( ! V_13 )
goto V_14;
F_7 ( & V_74 -> V_12 ) ;
F_13 ( & V_74 -> V_24 ) ;
F_19 ( & V_74 -> V_24 ,
& V_13 -> V_15 ) ;
F_9 ( & V_74 -> V_12 ) ;
V_14:
F_46 () ;
return V_13 ;
}
static struct V_5 *
F_47 ( struct V_3 * V_74 ,
const struct V_40 * V_67 )
{
struct V_5 * V_17 ;
struct V_5 * V_13 = NULL , * V_75 = NULL ;
F_44 () ;
F_45 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_75 )
V_75 = V_17 ;
if ( V_17 -> V_23 == V_67 )
continue;
if ( V_13 && V_17 -> V_21 <= V_13 -> V_21 )
continue;
if ( ! F_6 ( & V_17 -> V_11 ) )
continue;
if ( V_13 )
F_5 ( V_13 ) ;
V_13 = V_17 ;
}
if ( ! V_13 && V_75 &&
F_6 ( & V_75 -> V_11 ) )
V_13 = V_75 ;
F_46 () ;
return V_13 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_38 * V_39 , int V_69 )
{
struct V_43 * V_43 ;
if ( F_25 ( ! F_26 ( V_39 , V_69 ) ) )
return - V_76 ;
V_43 = F_27 ( V_39 ) ;
if ( F_28 ( V_43 -> V_44 ) )
return - V_77 ;
if ( F_28 ( V_43 -> V_45 ) )
return - V_77 ;
if ( ! F_42 ( V_2 , V_43 -> V_44 ) )
return - V_78 ;
return 0 ;
}
int F_49 ( struct V_38 * V_39 , struct V_40 * V_67 )
{
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
struct V_79 * V_80 ;
T_4 V_81 ;
int V_69 = sizeof( * V_80 ) ;
char V_82 ;
T_3 V_83 ;
if ( F_48 ( V_2 , V_39 , V_69 ) < 0 )
return V_51 ;
if ( F_29 ( V_39 , sizeof( struct V_79 ) ) < 0 )
goto V_14;
V_80 = (struct V_79 * ) V_39 -> V_52 ;
switch ( V_80 -> V_28 & V_84 ) {
case V_85 :
F_50 ( V_2 , V_86 ) ;
if ( ! F_51 ( V_2 , V_80 ) ) {
if ( V_80 -> V_28 & V_87 )
V_82 = 'F' ;
else
V_82 = '.' ;
F_3 ( V_88 , V_2 ,
L_7 ,
V_80 -> V_56 ,
V_82 ) ;
return F_52 ( V_39 , V_67 ) ;
}
break;
case V_89 :
F_50 ( V_2 , V_90 ) ;
if ( F_42 ( V_2 , V_80 -> V_56 ) ) {
if ( F_30 ( V_39 ) < 0 )
goto V_14;
V_80 = (struct V_79 * ) V_39 -> V_52 ;
V_81 = F_53 ( F_54 ( V_80 -> V_91 ) ) ;
V_83 = sizeof( struct V_79 ) ;
V_83 += V_81 ;
if ( F_25 ( F_55 ( V_39 ) < V_83 ) )
goto V_14;
F_56 ( V_2 , V_80 ) ;
} else {
if ( V_80 -> V_28 & V_87 )
V_82 = 'F' ;
else
V_82 = '.' ;
F_3 ( V_88 , V_2 ,
L_8 ,
V_80 -> V_56 ,
V_82 ) ;
return F_52 ( V_39 , V_67 ) ;
}
break;
}
V_14:
return V_51 ;
}
int F_57 ( struct V_38 * V_39 , struct V_40 * V_67 )
{
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
struct V_92 * V_93 ;
struct V_3 * V_4 ;
if ( F_48 ( V_2 , V_39 ,
sizeof( * V_93 ) ) < 0 )
goto V_14;
F_50 ( V_2 , V_94 ) ;
V_93 = (struct V_92 * ) V_39 -> V_52 ;
if ( ! F_42 ( V_2 , V_93 -> V_56 ) )
return F_52 ( V_39 , V_67 ) ;
if ( F_58 ( V_2 , V_93 -> V_95 ) )
goto V_14;
V_4 = F_34 ( V_2 , V_93 -> V_95 ) ;
if ( ! V_4 )
goto V_14;
F_3 ( V_88 , V_2 ,
L_9 ,
V_93 -> V_95 , V_93 -> V_96 ) ;
F_59 ( V_2 , V_4 , V_93 -> V_96 ,
V_97 ,
F_60 ( & V_4 -> V_98 ) + 1 ) ;
F_37 ( V_4 ) ;
V_14:
return V_51 ;
}
struct V_5 *
F_61 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_40 * V_67 )
{
struct V_3 * V_99 ;
struct V_3 * V_100 ;
struct V_5 * V_13 ;
static T_1 V_101 [ V_30 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_102 ;
T_1 * V_19 ;
if ( ! V_4 )
return NULL ;
V_13 = F_2 ( V_4 ) ;
if ( ! V_13 )
goto V_103;
V_102 = F_60 ( & V_2 -> V_104 ) ;
F_44 () ;
V_100 = V_13 -> V_4 ;
if ( ! V_100 )
goto V_105;
if ( ( ! V_67 ) && ( ! V_102 ) )
goto V_106;
V_19 = V_100 -> V_19 ;
if ( F_17 ( V_19 , V_101 ) )
goto V_106;
if ( F_17 ( V_19 , V_100 -> V_9 ) ) {
V_99 = V_100 ;
} else {
V_99 = F_34 ( V_2 ,
V_19 ) ;
if ( ! V_99 )
goto V_106;
F_37 ( V_99 ) ;
}
if ( F_60 ( & V_99 -> V_16 ) < 2 )
goto V_106;
F_5 ( V_13 ) ;
if ( V_102 )
V_13 = F_43 ( V_99 , V_67 ) ;
else
V_13 = F_47 ( V_99 , V_67 ) ;
V_106:
if ( V_13 && V_13 -> V_23 -> V_107 != V_108 )
goto V_105;
F_46 () ;
return V_13 ;
V_105:
F_46 () ;
V_103:
if ( V_13 )
F_5 ( V_13 ) ;
return NULL ;
}
static int F_52 ( struct V_38 * V_39 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 = NULL ;
struct V_109 * V_110 ;
struct V_43 * V_43 = F_27 ( V_39 ) ;
int V_111 , V_112 , V_50 = V_51 ;
struct V_38 * V_113 ;
V_110 = (struct V_109 * ) V_39 -> V_52 ;
if ( V_110 -> V_60 . V_61 < 2 ) {
F_39 ( L_10 ,
V_43 -> V_45 , V_110 -> V_114 ) ;
goto V_14;
}
V_4 = F_34 ( V_2 , V_110 -> V_114 ) ;
if ( ! V_4 )
goto V_14;
V_6 = F_61 ( V_2 , V_4 , V_67 ) ;
if ( ! V_6 )
goto V_14;
if ( F_29 ( V_39 , V_55 ) < 0 )
goto V_14;
V_110 = (struct V_109 * ) V_39 -> V_52 ;
if ( V_110 -> V_60 . V_115 == V_116 &&
F_60 ( & V_2 -> V_117 ) &&
V_39 -> V_70 > V_6 -> V_23 -> V_57 -> V_118 ) {
V_50 = F_62 ( V_39 , V_2 ,
V_6 -> V_23 ,
V_6 -> V_10 ) ;
goto V_14;
}
if ( V_110 -> V_60 . V_115 == V_119 &&
F_63 ( V_39 ,
V_6 -> V_23 -> V_57 -> V_118 ) ) {
V_50 = F_64 ( V_39 , V_2 , & V_113 ) ;
if ( V_50 == V_51 )
goto V_14;
if ( ! V_113 ) {
V_50 = V_64 ;
goto V_14;
}
V_39 = V_113 ;
V_110 = (struct V_109 * ) V_39 -> V_52 ;
}
V_110 -> V_60 . V_61 -- ;
switch ( V_110 -> V_60 . V_115 ) {
case V_120 :
V_112 = sizeof( struct V_121 ) ;
break;
case V_116 :
V_112 = sizeof( struct V_109 ) ;
break;
default:
V_112 = - 1 ;
break;
}
if ( V_112 > 0 )
F_65 ( V_39 , V_112 ) ;
V_111 = F_35 ( V_39 , V_4 , V_67 ) ;
if ( V_111 == V_122 ) {
F_50 ( V_2 , V_123 ) ;
F_66 ( V_2 , V_124 ,
V_39 -> V_70 + V_55 ) ;
V_50 = V_64 ;
} else if ( V_111 == V_125 ) {
V_50 = V_64 ;
}
V_14:
if ( V_6 )
F_5 ( V_6 ) ;
if ( V_4 )
F_37 ( V_4 ) ;
return V_50 ;
}
static bool
F_67 ( struct V_1 * V_2 ,
struct V_109 * V_110 ,
T_1 * V_126 )
{
struct V_3 * V_4 = NULL ;
struct V_40 * V_47 = NULL ;
bool V_50 = false ;
T_1 * V_127 , V_128 ;
if ( F_68 ( V_2 , V_126 ) ) {
V_47 = F_33 ( V_2 ) ;
if ( ! V_47 )
goto V_14;
V_127 = V_47 -> V_57 -> V_58 ;
V_128 = ( T_1 ) F_60 ( & V_2 -> V_129 . V_130 ) ;
} else {
V_4 = F_69 ( V_2 , NULL , V_126 ) ;
if ( ! V_4 )
goto V_14;
if ( F_17 ( V_4 -> V_9 , V_110 -> V_114 ) )
goto V_14;
V_127 = V_4 -> V_9 ;
V_128 = ( T_1 ) F_60 ( & V_4 -> V_98 ) ;
}
memcpy ( V_110 -> V_114 , V_127 , V_30 ) ;
V_110 -> V_131 = V_128 ;
V_50 = true ;
V_14:
if ( V_47 )
F_36 ( V_47 ) ;
if ( V_4 )
F_37 ( V_4 ) ;
return V_50 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_38 * V_39 , int V_112 ) {
T_1 V_132 , V_133 ;
struct V_3 * V_4 ;
struct V_43 * V_43 ;
struct V_40 * V_47 ;
struct V_109 * V_110 ;
int V_134 ;
if ( F_26 ( V_39 , V_112 + V_55 ) < 0 )
return 0 ;
if ( F_29 ( V_39 , sizeof( * V_110 ) ) < 0 )
return 0 ;
V_110 = (struct V_109 * ) V_39 -> V_52 ;
V_43 = (struct V_43 * ) ( V_39 -> V_52 + V_112 ) ;
if ( F_71 ( V_2 , V_43 -> V_44 ) ) {
if ( F_67 ( V_2 , V_110 ,
V_43 -> V_44 ) )
F_72 ( F_3 , V_88 ,
V_2 ,
L_11 ,
V_110 -> V_114 ,
V_43 -> V_44 ) ;
return 1 ;
}
V_132 = ( T_1 ) F_60 ( & V_2 -> V_129 . V_130 ) ;
if ( ! F_42 ( V_2 , V_110 -> V_114 ) ) {
V_4 = F_34 ( V_2 ,
V_110 -> V_114 ) ;
if ( ! V_4 )
return 0 ;
V_132 = ( T_1 ) F_60 ( & V_4 -> V_98 ) ;
F_37 ( V_4 ) ;
}
V_134 = F_73 ( V_110 -> V_131 , V_132 ) ;
if ( ! V_134 )
return 1 ;
V_133 = V_110 -> V_131 ;
if ( F_67 ( V_2 , V_110 ,
V_43 -> V_44 ) ) {
F_72 ( F_3 , V_88 , V_2 ,
L_12 ,
V_110 -> V_114 , V_43 -> V_44 ,
V_133 , V_132 ) ;
return 1 ;
}
if ( ! F_68 ( V_2 , V_43 -> V_44 ) )
return 0 ;
V_47 = F_33 ( V_2 ) ;
if ( ! V_47 )
return 0 ;
memcpy ( V_110 -> V_114 , V_47 -> V_57 -> V_58 , V_30 ) ;
F_36 ( V_47 ) ;
V_110 -> V_131 = V_132 ;
return 1 ;
}
int F_74 ( struct V_38 * V_39 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
struct V_109 * V_110 ;
struct V_121 * V_135 ;
T_1 * V_127 ;
struct V_3 * V_4 = NULL ;
int V_136 , V_69 = sizeof( * V_110 ) ;
bool V_137 ;
V_110 = (struct V_109 * ) V_39 -> V_52 ;
V_135 = (struct V_121 * ) V_39 -> V_52 ;
V_137 = V_110 -> V_60 . V_115 == V_120 ;
if ( V_137 )
V_69 = sizeof( * V_135 ) ;
V_136 = F_48 ( V_2 , V_39 , V_69 ) ;
if ( V_136 == - V_78 )
F_75 ( V_2 , V_39 ) ;
if ( V_136 < 0 )
return V_51 ;
if ( ! F_70 ( V_2 , V_39 , V_69 ) )
return V_51 ;
if ( F_42 ( V_2 , V_110 -> V_114 ) ) {
if ( V_137 ) {
F_76 ( V_2 ,
V_135 -> V_138 ) ;
V_127 = V_135 -> V_95 ;
V_4 = F_34 ( V_2 , V_127 ) ;
}
if ( F_77 ( V_2 , V_39 ,
V_69 ) )
goto V_139;
if ( F_78 ( V_2 , V_39 ,
V_69 ) )
goto V_139;
F_79 ( V_67 -> V_68 , V_39 , V_67 , V_69 ,
V_4 ) ;
V_139:
if ( V_4 )
F_37 ( V_4 ) ;
return V_64 ;
}
return F_52 ( V_39 , V_67 ) ;
}
int F_80 ( struct V_38 * V_39 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
struct V_140 * V_110 ;
int V_69 = sizeof( * V_110 ) ;
struct V_38 * V_113 = NULL ;
int V_50 ;
if ( F_48 ( V_2 , V_39 , V_69 ) < 0 )
return V_51 ;
if ( ! F_70 ( V_2 , V_39 , V_69 ) )
return V_51 ;
V_110 = (struct V_140 * ) V_39 -> V_52 ;
if ( F_42 ( V_2 , V_110 -> V_114 ) ) {
V_50 = F_64 ( V_39 , V_2 , & V_113 ) ;
if ( V_50 == V_51 )
return V_51 ;
if ( ! V_113 )
return V_64 ;
if ( F_77 ( V_2 , V_113 ,
V_69 ) )
goto V_139;
if ( F_78 ( V_2 , V_113 ,
V_69 ) )
goto V_139;
F_79 ( V_67 -> V_68 , V_113 , V_67 ,
sizeof( struct V_109 ) , NULL ) ;
V_139:
return V_64 ;
}
return F_52 ( V_39 , V_67 ) ;
}
int F_81 ( struct V_38 * V_39 ,
struct V_40 * V_67 )
{
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
struct V_3 * V_4 = NULL ;
struct V_141 * V_142 ;
struct V_43 * V_43 ;
int V_69 = sizeof( * V_142 ) ;
int V_50 = V_51 ;
T_2 V_143 ;
if ( F_25 ( ! F_26 ( V_39 , V_69 ) ) )
goto V_14;
V_43 = F_27 ( V_39 ) ;
if ( ! F_28 ( V_43 -> V_44 ) )
goto V_14;
if ( F_28 ( V_43 -> V_45 ) )
goto V_14;
if ( F_42 ( V_2 , V_43 -> V_45 ) )
goto V_14;
V_142 = (struct V_141 * ) V_39 -> V_52 ;
if ( F_42 ( V_2 , V_142 -> V_9 ) )
goto V_14;
if ( V_142 -> V_60 . V_61 < 2 )
goto V_14;
V_4 = F_34 ( V_2 , V_142 -> V_9 ) ;
if ( ! V_4 )
goto V_14;
F_7 ( & V_4 -> V_144 ) ;
if ( F_82 ( V_4 -> V_145 , V_4 -> V_146 ,
F_83 ( V_142 -> V_147 ) ) )
goto V_148;
V_143 = F_83 ( V_142 -> V_147 ) - V_4 -> V_146 ;
if ( F_22 ( V_2 , V_143 ,
& V_4 -> V_149 ) )
goto V_148;
if ( F_84 ( V_2 , V_4 -> V_145 , V_143 , 1 ) )
V_4 -> V_146 = F_83 ( V_142 -> V_147 ) ;
F_9 ( & V_4 -> V_144 ) ;
if ( F_85 ( V_2 , V_39 ) )
goto V_14;
F_65 ( V_39 , sizeof( struct V_141 ) ) ;
F_86 ( V_2 , V_39 , 1 ) ;
if ( F_87 ( V_39 , V_4 , V_69 ) )
goto V_14;
if ( F_77 ( V_2 , V_39 , V_69 ) )
goto V_139;
if ( F_78 ( V_2 , V_39 , V_69 ) )
goto V_139;
F_79 ( V_67 -> V_68 , V_39 , V_67 , V_69 ,
V_4 ) ;
V_139:
V_50 = V_64 ;
goto V_14;
V_148:
F_9 ( & V_4 -> V_144 ) ;
V_14:
if ( V_4 )
F_37 ( V_4 ) ;
return V_50 ;
}
int F_88 ( struct V_38 * V_39 ,
struct V_40 * V_67 )
{
struct V_150 * V_151 ;
struct V_43 * V_43 ;
struct V_1 * V_2 = F_41 ( V_67 -> V_68 ) ;
int V_69 = sizeof( * V_151 ) ;
if ( F_30 ( V_39 ) < 0 )
return V_51 ;
if ( F_25 ( ! F_26 ( V_39 , V_69 ) ) )
return V_51 ;
V_151 = (struct V_150 * ) V_39 -> V_52 ;
V_43 = F_27 ( V_39 ) ;
if ( ! F_42 ( V_2 , V_43 -> V_44 ) )
return V_51 ;
if ( F_42 ( V_2 , V_151 -> V_152 ) )
return V_51 ;
if ( F_42 ( V_2 , V_151 -> V_153 ) )
return V_51 ;
switch ( V_151 -> V_154 ) {
case V_155 :
F_89 ( V_2 , V_151 ,
F_55 ( V_39 ) ) ;
break;
case V_156 :
F_90 ( V_2 , V_151 ,
F_55 ( V_39 ) ) ;
break;
default:
break;
}
return V_51 ;
}
