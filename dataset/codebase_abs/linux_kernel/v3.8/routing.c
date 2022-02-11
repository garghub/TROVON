void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long * V_15 ;
T_1 V_16 ;
T_2 V_17 ;
T_3 * V_18 ;
for ( V_16 = 0 ; V_16 < V_7 -> V_19 ; V_16 ++ ) {
V_12 = & V_7 -> V_20 [ V_16 ] ;
F_3 () ;
F_4 (orig_node, node, head, hash_entry) {
F_5 ( & V_14 -> V_21 ) ;
V_17 = V_2 -> V_22 * V_23 ;
V_15 = & ( V_14 -> V_24 [ V_17 ] ) ;
F_6 ( V_4 , V_15 , 1 , 0 ) ;
V_18 = & V_14 -> V_25 [ V_2 -> V_22 ] ;
* V_18 = F_7 ( V_15 , V_26 ) ;
F_8 ( & V_14 -> V_21 ) ;
}
F_9 () ;
}
}
static void F_10 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
struct V_27 * V_28 )
{
struct V_27 * V_29 ;
V_29 = F_11 ( V_14 ) ;
if ( ( V_29 ) && ( ! V_28 ) ) {
F_12 ( V_30 , V_4 ,
L_1 , V_14 -> V_31 ) ;
F_13 ( V_4 , V_14 ,
L_2 ) ;
} else if ( ( ! V_29 ) && ( V_28 ) ) {
F_12 ( V_30 , V_4 ,
L_3 ,
V_14 -> V_31 , V_28 -> V_32 ) ;
} else if ( V_28 && V_29 ) {
F_12 ( V_30 , V_4 ,
L_4 ,
V_14 -> V_31 , V_28 -> V_32 ,
V_29 -> V_32 ) ;
}
if ( V_29 )
F_14 ( V_29 ) ;
if ( V_28 && ! F_15 ( & V_28 -> V_33 ) )
V_28 = NULL ;
F_5 ( & V_14 -> V_34 ) ;
F_16 ( V_14 -> V_35 , V_28 ) ;
F_8 ( & V_14 -> V_34 ) ;
if ( V_29 )
F_14 ( V_29 ) ;
}
void F_17 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
struct V_27 * V_28 )
{
struct V_27 * V_35 = NULL ;
if ( ! V_14 )
goto V_36;
V_35 = F_11 ( V_14 ) ;
if ( V_35 != V_28 )
F_10 ( V_4 , V_14 , V_28 ) ;
V_36:
if ( V_35 )
F_14 ( V_35 ) ;
}
void F_18 ( struct V_13 * V_14 ,
struct V_27 * V_28 )
{
if ( F_19 ( & V_28 -> V_37 ) )
goto V_36;
F_20 ( & V_28 -> V_37 ) ;
F_21 ( & V_28 -> V_37 ) ;
F_14 ( V_28 ) ;
F_22 ( & V_14 -> V_38 ) ;
V_36:
return;
}
void F_23 ( struct V_13 * V_14 ,
struct V_27 * V_28 )
{
struct V_9 * V_10 ;
struct V_27 * V_39 , * V_35 = NULL ;
T_3 V_40 = 0 ;
F_5 ( & V_14 -> V_34 ) ;
if ( ! F_24 ( V_14 -> V_31 ,
V_28 -> V_14 -> V_41 ) )
goto V_42;
V_35 = F_11 ( V_14 ) ;
if ( ! V_35 )
goto V_42;
if ( V_28 -> V_43 < V_35 -> V_43 - V_44 )
goto V_42;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( V_39 == V_28 )
continue;
if ( F_19 ( & V_39 -> V_37 ) )
continue;
if ( ( V_28 -> V_45 == V_39 -> V_45 ) ||
( F_24 ( V_28 -> V_32 ,
V_39 -> V_32 ) ) ) {
V_40 = 1 ;
break;
}
}
if ( V_40 )
goto V_42;
if ( ! F_19 ( & V_28 -> V_37 ) )
goto V_36;
if ( ! F_15 ( & V_28 -> V_33 ) )
goto V_36;
F_25 ( & V_28 -> V_37 , & V_14 -> V_46 ) ;
F_26 ( & V_14 -> V_38 ) ;
goto V_36;
V_42:
F_18 ( V_14 , V_28 ) ;
V_36:
F_8 ( & V_14 -> V_34 ) ;
if ( V_35 )
F_14 ( V_35 ) ;
}
void
F_27 ( const struct V_13 * V_14 ,
struct V_13 * V_47 ,
const struct V_48 * V_49 )
{
if ( ! ( V_49 -> V_50 & V_51 ) )
return;
memcpy ( V_47 -> V_41 , V_14 -> V_31 , V_52 ) ;
}
int F_28 ( struct V_3 * V_4 , T_4 V_53 ,
unsigned long * V_54 )
{
if ( V_53 <= - V_26 ||
V_53 >= V_55 ) {
if ( ! F_29 ( * V_54 ,
V_56 ) )
return 1 ;
* V_54 = V_57 ;
F_12 ( V_58 , V_4 ,
L_5 ) ;
}
return 0 ;
}
bool F_30 ( struct V_59 * V_60 ,
struct V_1 * V_2 ,
int V_61 )
{
struct V_62 * V_62 ;
if ( F_31 ( ! F_32 ( V_60 , V_61 ) ) )
return false ;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( ! F_34 ( V_62 -> V_63 ) )
return false ;
if ( F_34 ( V_62 -> V_64 ) )
return false ;
if ( F_35 ( V_60 , 0 ) < 0 )
return false ;
if ( F_36 ( V_60 ) < 0 )
return false ;
return true ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_59 * V_60 , T_2 V_65 )
{
struct V_1 * V_66 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_67 * V_68 ;
int V_69 = V_70 ;
V_68 = (struct V_67 * ) V_60 -> V_71 ;
if ( V_68 -> V_72 != V_73 ) {
F_38 ( V_68 , V_65 ) ;
goto V_36;
}
V_66 = F_39 ( V_4 ) ;
if ( ! V_66 )
goto V_36;
V_14 = F_40 ( V_4 , V_68 -> V_31 ) ;
if ( ! V_14 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_68 = (struct V_67 * ) V_60 -> V_71 ;
memcpy ( V_68 -> V_75 , V_68 -> V_31 , V_52 ) ;
memcpy ( V_68 -> V_31 , V_66 -> V_76 -> V_77 , V_52 ) ;
V_68 -> V_72 = V_78 ;
V_68 -> V_79 . V_80 = V_81 ;
if ( F_41 ( V_60 , V_14 , NULL ) )
V_69 = V_82 ;
V_36:
if ( V_66 )
F_42 ( V_66 ) ;
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_59 * V_60 )
{
struct V_1 * V_66 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_83 * V_68 ;
int V_69 = V_70 ;
V_68 = (struct V_83 * ) V_60 -> V_71 ;
if ( V_68 -> V_72 != V_73 ) {
F_45 ( L_6 ,
V_68 -> V_31 , V_68 -> V_75 ) ;
goto V_36;
}
V_66 = F_39 ( V_4 ) ;
if ( ! V_66 )
goto V_36;
V_14 = F_40 ( V_4 , V_68 -> V_31 ) ;
if ( ! V_14 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_68 = (struct V_83 * ) V_60 -> V_71 ;
memcpy ( V_68 -> V_75 , V_68 -> V_31 , V_52 ) ;
memcpy ( V_68 -> V_31 , V_66 -> V_76 -> V_77 , V_52 ) ;
V_68 -> V_72 = V_84 ;
V_68 -> V_79 . V_80 = V_81 ;
if ( F_41 ( V_60 , V_14 , NULL ) )
V_69 = V_82 ;
V_36:
if ( V_66 )
F_42 ( V_66 ) ;
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
int F_46 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_67 * V_68 ;
struct V_62 * V_62 ;
struct V_13 * V_14 = NULL ;
int V_86 = sizeof( struct V_83 ) ;
int V_69 = V_70 ;
if ( V_60 -> V_87 >= sizeof( struct V_67 ) )
V_86 = sizeof( struct V_67 ) ;
if ( F_31 ( ! F_32 ( V_60 , V_86 ) ) )
goto V_36;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( F_34 ( V_62 -> V_63 ) )
goto V_36;
if ( F_34 ( V_62 -> V_64 ) )
goto V_36;
if ( ! F_47 ( V_62 -> V_63 ) )
goto V_36;
V_68 = (struct V_67 * ) V_60 -> V_71 ;
if ( ( V_86 == sizeof( struct V_67 ) ) &&
( V_68 -> V_88 < V_89 ) ) {
memcpy ( & ( V_68 -> V_90 [ V_68 -> V_88 ] ) ,
V_62 -> V_63 , V_52 ) ;
V_68 -> V_88 ++ ;
}
if ( F_47 ( V_68 -> V_75 ) )
return F_37 ( V_4 , V_60 , V_86 ) ;
if ( V_68 -> V_79 . V_80 < 2 )
return F_44 ( V_4 , V_60 ) ;
V_14 = F_40 ( V_4 , V_68 -> V_75 ) ;
if ( ! V_14 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_68 = (struct V_67 * ) V_60 -> V_71 ;
V_68 -> V_79 . V_80 -- ;
if ( F_41 ( V_60 , V_14 , V_85 ) )
V_69 = V_82 ;
V_36:
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
static struct V_27 *
F_48 ( struct V_13 * V_91 ,
const struct V_1 * V_85 )
{
struct V_27 * V_39 ;
struct V_27 * V_35 = NULL , * V_92 = NULL ;
F_3 () ;
F_49 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_92 )
V_92 = V_39 ;
if ( V_39 -> V_45 == V_85 )
continue;
if ( ! F_15 ( & V_39 -> V_33 ) )
continue;
V_35 = V_39 ;
break;
}
if ( ! V_35 && V_92 &&
F_15 ( & V_92 -> V_33 ) )
V_35 = V_92 ;
if ( ! V_35 )
goto V_36;
F_5 ( & V_91 -> V_34 ) ;
F_20 ( & V_91 -> V_46 ) ;
F_25 ( & V_91 -> V_46 ,
& V_35 -> V_37 ) ;
F_8 ( & V_91 -> V_34 ) ;
V_36:
F_9 () ;
return V_35 ;
}
static struct V_27 *
F_50 ( struct V_13 * V_91 ,
const struct V_1 * V_85 )
{
struct V_27 * V_39 ;
struct V_27 * V_35 = NULL , * V_92 = NULL ;
F_3 () ;
F_49 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_92 )
V_92 = V_39 ;
if ( V_39 -> V_45 == V_85 )
continue;
if ( V_35 && V_39 -> V_43 <= V_35 -> V_43 )
continue;
if ( ! F_15 ( & V_39 -> V_33 ) )
continue;
if ( V_35 )
F_14 ( V_35 ) ;
V_35 = V_39 ;
}
if ( ! V_35 && V_92 &&
F_15 ( & V_92 -> V_33 ) )
V_35 = V_92 ;
F_9 () ;
return V_35 ;
}
static int F_51 ( struct V_59 * V_60 , int V_86 )
{
struct V_62 * V_62 ;
if ( F_31 ( ! F_32 ( V_60 , V_86 ) ) )
return - 1 ;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( F_34 ( V_62 -> V_63 ) )
return - 1 ;
if ( F_34 ( V_62 -> V_64 ) )
return - 1 ;
if ( ! F_47 ( V_62 -> V_63 ) )
return - 1 ;
return 0 ;
}
int F_52 ( struct V_59 * V_60 , struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_93 * V_94 ;
T_5 V_95 ;
int V_86 = sizeof( * V_94 ) ;
char V_96 ;
T_2 V_97 ;
if ( F_51 ( V_60 , V_86 ) < 0 )
return V_70 ;
if ( F_35 ( V_60 , sizeof( struct V_93 ) ) < 0 )
goto V_36;
V_94 = (struct V_93 * ) V_60 -> V_71 ;
switch ( V_94 -> V_50 & V_98 ) {
case V_99 :
F_53 ( V_4 , V_100 ) ;
if ( ! F_54 ( V_4 , V_94 ) ) {
if ( V_94 -> V_50 & V_101 )
V_96 = 'F' ;
else
V_96 = '.' ;
F_12 ( V_102 , V_4 ,
L_7 ,
V_94 -> V_75 ,
V_96 ) ;
return F_55 ( V_60 , V_85 ) ;
}
break;
case V_103 :
F_53 ( V_4 , V_104 ) ;
if ( F_47 ( V_94 -> V_75 ) ) {
if ( F_36 ( V_60 ) < 0 )
goto V_36;
V_94 = (struct V_93 * ) V_60 -> V_71 ;
V_95 = F_56 ( F_57 ( V_94 -> V_105 ) ) ;
V_97 = sizeof( struct V_93 ) ;
V_97 += V_95 ;
if ( F_31 ( F_58 ( V_60 ) < V_97 ) )
goto V_36;
F_59 ( V_4 , V_94 ) ;
} else {
if ( V_94 -> V_50 & V_101 )
V_96 = 'F' ;
else
V_96 = '.' ;
F_12 ( V_102 , V_4 ,
L_8 ,
V_94 -> V_75 ,
V_96 ) ;
return F_55 ( V_60 , V_85 ) ;
}
break;
}
V_36:
return V_70 ;
}
int F_60 ( struct V_59 * V_60 , struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_106 * V_107 ;
struct V_13 * V_14 ;
if ( F_51 ( V_60 , sizeof( * V_107 ) ) < 0 )
goto V_36;
F_53 ( V_4 , V_108 ) ;
V_107 = (struct V_106 * ) V_60 -> V_71 ;
if ( ! F_47 ( V_107 -> V_75 ) )
return F_55 ( V_60 , V_85 ) ;
if ( F_61 ( V_4 , V_107 -> V_109 ) )
goto V_36;
V_14 = F_40 ( V_4 , V_107 -> V_109 ) ;
if ( ! V_14 )
goto V_36;
F_12 ( V_102 , V_4 ,
L_9 ,
V_107 -> V_109 , V_107 -> V_110 ) ;
F_62 ( V_4 , V_14 , V_107 -> V_110 ,
V_111 ,
F_63 ( & V_14 -> V_112 ) + 1 ) ;
F_43 ( V_14 ) ;
V_36:
return V_70 ;
}
struct V_27 *
F_64 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
const struct V_1 * V_85 )
{
struct V_13 * V_113 ;
struct V_13 * V_114 ;
struct V_27 * V_35 ;
static T_3 V_115 [ V_52 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_116 ;
T_3 * V_41 ;
if ( ! V_14 )
return NULL ;
V_35 = F_11 ( V_14 ) ;
if ( ! V_35 )
goto V_117;
V_116 = F_63 ( & V_4 -> V_118 ) ;
F_3 () ;
V_114 = V_35 -> V_14 ;
if ( ! V_114 )
goto V_119;
if ( ( ! V_85 ) && ( ! V_116 ) )
goto V_120;
V_41 = V_114 -> V_41 ;
if ( F_24 ( V_41 , V_115 ) )
goto V_120;
if ( F_24 ( V_41 , V_114 -> V_31 ) ) {
V_113 = V_114 ;
} else {
V_113 = F_40 ( V_4 ,
V_41 ) ;
if ( ! V_113 )
goto V_120;
F_43 ( V_113 ) ;
}
if ( F_63 ( & V_113 -> V_38 ) < 2 )
goto V_120;
F_14 ( V_35 ) ;
if ( V_116 )
V_35 = F_48 ( V_113 , V_85 ) ;
else
V_35 = F_50 ( V_113 , V_85 ) ;
V_120:
if ( V_35 && V_35 -> V_45 -> V_121 != V_122 )
goto V_119;
F_9 () ;
return V_35 ;
V_119:
F_9 () ;
V_117:
if ( V_35 )
F_14 ( V_35 ) ;
return NULL ;
}
static int F_55 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_13 * V_14 = NULL ;
struct V_27 * V_28 = NULL ;
struct V_123 * V_124 ;
struct V_62 * V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
int V_69 = V_70 ;
struct V_59 * V_125 ;
V_124 = (struct V_123 * ) V_60 -> V_71 ;
if ( V_124 -> V_79 . V_80 < 2 ) {
F_45 ( L_10 ,
V_62 -> V_64 , V_124 -> V_126 ) ;
goto V_36;
}
V_14 = F_40 ( V_4 , V_124 -> V_126 ) ;
if ( ! V_14 )
goto V_36;
V_28 = F_64 ( V_4 , V_14 , V_85 ) ;
if ( ! V_28 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_124 = (struct V_123 * ) V_60 -> V_71 ;
if ( V_124 -> V_79 . V_127 == V_128 &&
F_63 ( & V_4 -> V_129 ) &&
V_60 -> V_87 > V_28 -> V_45 -> V_76 -> V_130 ) {
V_69 = F_65 ( V_60 , V_4 ,
V_28 -> V_45 ,
V_28 -> V_32 ) ;
goto V_36;
}
if ( V_124 -> V_79 . V_127 == V_131 &&
F_66 ( V_60 ,
V_28 -> V_45 -> V_76 -> V_130 ) ) {
V_69 = F_67 ( V_60 , V_4 , & V_125 ) ;
if ( V_69 == V_70 )
goto V_36;
if ( ! V_125 ) {
V_69 = V_82 ;
goto V_36;
}
V_60 = V_125 ;
V_124 = (struct V_123 * ) V_60 -> V_71 ;
}
V_124 -> V_79 . V_80 -- ;
F_53 ( V_4 , V_132 ) ;
F_68 ( V_4 , V_133 ,
V_60 -> V_87 + V_74 ) ;
if ( F_41 ( V_60 , V_14 , V_85 ) )
V_69 = V_82 ;
V_36:
if ( V_28 )
F_14 ( V_28 ) ;
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
static bool
F_69 ( struct V_3 * V_4 ,
struct V_123 * V_124 ,
T_3 * V_134 )
{
struct V_13 * V_14 = NULL ;
struct V_1 * V_66 = NULL ;
bool V_69 = false ;
T_3 * V_135 , V_136 ;
if ( F_70 ( V_4 , V_134 ) ) {
V_66 = F_39 ( V_4 ) ;
if ( ! V_66 )
goto V_36;
V_135 = V_66 -> V_76 -> V_77 ;
V_136 = ( T_3 ) F_63 ( & V_4 -> V_137 . V_138 ) ;
} else {
V_14 = F_71 ( V_4 , NULL , V_134 ) ;
if ( ! V_14 )
goto V_36;
if ( F_24 ( V_14 -> V_31 , V_124 -> V_126 ) )
goto V_36;
V_135 = V_14 -> V_31 ;
V_136 = ( T_3 ) F_63 ( & V_14 -> V_112 ) ;
}
memcpy ( V_124 -> V_126 , V_135 , V_52 ) ;
V_124 -> V_139 = V_136 ;
V_69 = true ;
V_36:
if ( V_66 )
F_42 ( V_66 ) ;
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_59 * V_60 ) {
T_3 V_140 , V_141 ;
struct V_13 * V_14 ;
struct V_62 * V_62 ;
struct V_1 * V_66 ;
struct V_123 * V_124 ;
int V_142 ;
if ( F_32 ( V_60 , sizeof( * V_124 ) + V_74 ) < 0 )
return 0 ;
if ( F_35 ( V_60 , sizeof( * V_124 ) ) < 0 )
return 0 ;
V_124 = (struct V_123 * ) V_60 -> V_71 ;
V_62 = (struct V_62 * ) ( V_60 -> V_71 + sizeof( * V_124 ) ) ;
if ( F_73 ( V_4 , V_62 -> V_63 ) ) {
if ( F_69 ( V_4 , V_124 ,
V_62 -> V_63 ) )
F_74 ( F_12 , V_102 ,
V_4 ,
L_11 ,
V_124 -> V_126 ,
V_62 -> V_63 ) ;
return 1 ;
}
V_140 = ( T_3 ) F_63 ( & V_4 -> V_137 . V_138 ) ;
if ( ! F_47 ( V_124 -> V_126 ) ) {
V_14 = F_40 ( V_4 ,
V_124 -> V_126 ) ;
if ( ! V_14 )
return 0 ;
V_140 = ( T_3 ) F_63 ( & V_14 -> V_112 ) ;
F_43 ( V_14 ) ;
}
V_142 = F_75 ( V_124 -> V_139 , V_140 ) ;
if ( ! V_142 )
return 1 ;
V_141 = V_124 -> V_139 ;
if ( F_69 ( V_4 , V_124 ,
V_62 -> V_63 ) ) {
F_74 ( F_12 , V_102 , V_4 ,
L_12 ,
V_124 -> V_126 , V_62 -> V_63 ,
V_141 , V_140 ) ;
return 1 ;
}
if ( ! F_70 ( V_4 , V_62 -> V_63 ) )
return 0 ;
V_66 = F_39 ( V_4 ) ;
if ( ! V_66 )
return 0 ;
memcpy ( V_124 -> V_126 , V_66 -> V_76 -> V_77 , V_52 ) ;
F_42 ( V_66 ) ;
V_124 -> V_139 = V_140 ;
return 1 ;
}
int F_76 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_123 * V_124 ;
struct V_143 * V_144 ;
T_3 * V_135 ;
struct V_13 * V_14 = NULL ;
int V_86 = sizeof( * V_124 ) ;
bool V_145 ;
V_124 = (struct V_123 * ) V_60 -> V_71 ;
V_144 = (struct V_143 * ) V_60 -> V_71 ;
V_145 = V_124 -> V_79 . V_127 == V_146 ;
if ( V_145 )
V_86 = sizeof( * V_144 ) ;
if ( F_51 ( V_60 , V_86 ) < 0 )
return V_70 ;
if ( ! F_72 ( V_4 , V_60 ) )
return V_70 ;
if ( F_47 ( V_124 -> V_126 ) ) {
if ( V_145 ) {
F_77 ( V_4 ,
V_144 -> V_147 ) ;
V_135 = V_144 -> V_109 ;
V_14 = F_40 ( V_4 , V_135 ) ;
}
if ( F_78 ( V_4 , V_60 ,
V_86 ) )
goto V_148;
if ( F_79 ( V_4 , V_60 ,
V_86 ) )
goto V_148;
F_80 ( V_85 -> V_5 , V_60 , V_85 , V_86 ,
V_14 ) ;
V_148:
if ( V_14 )
F_43 ( V_14 ) ;
return V_82 ;
}
return F_55 ( V_60 , V_85 ) ;
}
int F_81 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_149 * V_124 ;
int V_86 = sizeof( * V_124 ) ;
struct V_59 * V_125 = NULL ;
int V_69 ;
if ( F_51 ( V_60 , V_86 ) < 0 )
return V_70 ;
if ( ! F_72 ( V_4 , V_60 ) )
return V_70 ;
V_124 = (struct V_149 * ) V_60 -> V_71 ;
if ( F_47 ( V_124 -> V_126 ) ) {
V_69 = F_67 ( V_60 , V_4 , & V_125 ) ;
if ( V_69 == V_70 )
return V_70 ;
if ( ! V_125 )
return V_82 ;
if ( F_78 ( V_4 , V_125 ,
V_86 ) )
goto V_148;
if ( F_79 ( V_4 , V_125 ,
V_86 ) )
goto V_148;
F_80 ( V_85 -> V_5 , V_125 , V_85 ,
sizeof( struct V_123 ) , NULL ) ;
V_148:
return V_82 ;
}
return F_55 ( V_60 , V_85 ) ;
}
int F_82 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_13 * V_14 = NULL ;
struct V_150 * V_151 ;
struct V_62 * V_62 ;
int V_86 = sizeof( * V_151 ) ;
int V_69 = V_70 ;
T_4 V_152 ;
if ( F_31 ( ! F_32 ( V_60 , V_86 ) ) )
goto V_36;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( ! F_34 ( V_62 -> V_63 ) )
goto V_36;
if ( F_34 ( V_62 -> V_64 ) )
goto V_36;
if ( F_47 ( V_62 -> V_64 ) )
goto V_36;
V_151 = (struct V_150 * ) V_60 -> V_71 ;
if ( F_47 ( V_151 -> V_31 ) )
goto V_36;
if ( V_151 -> V_79 . V_80 < 2 )
goto V_36;
V_14 = F_40 ( V_4 , V_151 -> V_31 ) ;
if ( ! V_14 )
goto V_36;
F_5 ( & V_14 -> V_153 ) ;
if ( F_83 ( V_14 -> V_154 , V_14 -> V_155 ,
F_84 ( V_151 -> V_156 ) ) )
goto V_157;
V_152 = F_84 ( V_151 -> V_156 ) - V_14 -> V_155 ;
if ( F_28 ( V_4 , V_152 ,
& V_14 -> V_158 ) )
goto V_157;
if ( F_6 ( V_4 , V_14 -> V_154 , V_152 , 1 ) )
V_14 -> V_155 = F_84 ( V_151 -> V_156 ) ;
F_8 ( & V_14 -> V_153 ) ;
if ( F_85 ( V_4 , V_60 ) )
goto V_36;
F_86 ( V_4 , V_60 , 1 ) ;
if ( F_87 ( V_60 , V_14 , V_86 ) )
goto V_36;
if ( F_78 ( V_4 , V_60 , V_86 ) )
goto V_148;
if ( F_79 ( V_4 , V_60 , V_86 ) )
goto V_148;
F_80 ( V_85 -> V_5 , V_60 , V_85 , V_86 ,
V_14 ) ;
V_148:
V_69 = V_82 ;
goto V_36;
V_157:
F_8 ( & V_14 -> V_153 ) ;
V_36:
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
int F_88 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_159 * V_160 ;
struct V_62 * V_62 ;
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
int V_86 = sizeof( * V_160 ) ;
if ( F_36 ( V_60 ) < 0 )
return V_70 ;
if ( F_31 ( ! F_32 ( V_60 , V_86 ) ) )
return V_70 ;
V_160 = (struct V_159 * ) V_60 -> V_71 ;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( ! F_47 ( V_62 -> V_63 ) )
return V_70 ;
if ( F_47 ( V_160 -> V_161 ) )
return V_70 ;
if ( F_47 ( V_160 -> V_162 ) )
return V_70 ;
switch ( V_160 -> V_163 ) {
case V_164 :
F_89 ( V_4 , V_160 ,
F_58 ( V_60 ) ) ;
break;
case V_165 :
F_90 ( V_4 , V_160 ,
F_58 ( V_60 ) ) ;
break;
default:
break;
}
return V_70 ;
}
