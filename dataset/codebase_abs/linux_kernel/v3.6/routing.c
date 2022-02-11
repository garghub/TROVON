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
struct V_27 * V_35 = NULL ;
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
V_35 = F_11 ( V_14 ) ;
if ( ! V_35 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_68 = (struct V_67 * ) V_60 -> V_71 ;
memcpy ( V_68 -> V_75 , V_68 -> V_31 , V_52 ) ;
memcpy ( V_68 -> V_31 , V_66 -> V_76 -> V_77 , V_52 ) ;
V_68 -> V_72 = V_78 ;
V_68 -> V_79 . V_80 = V_81 ;
F_41 ( V_60 , V_35 -> V_45 , V_35 -> V_32 ) ;
V_69 = V_82 ;
V_36:
if ( V_66 )
F_42 ( V_66 ) ;
if ( V_35 )
F_14 ( V_35 ) ;
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_59 * V_60 )
{
struct V_1 * V_66 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_27 * V_35 = NULL ;
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
V_35 = F_11 ( V_14 ) ;
if ( ! V_35 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_68 = (struct V_83 * ) V_60 -> V_71 ;
memcpy ( V_68 -> V_75 , V_68 -> V_31 , V_52 ) ;
memcpy ( V_68 -> V_31 , V_66 -> V_76 -> V_77 , V_52 ) ;
V_68 -> V_72 = V_84 ;
V_68 -> V_79 . V_80 = V_81 ;
F_41 ( V_60 , V_35 -> V_45 , V_35 -> V_32 ) ;
V_69 = V_82 ;
V_36:
if ( V_66 )
F_42 ( V_66 ) ;
if ( V_35 )
F_14 ( V_35 ) ;
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
struct V_27 * V_35 = NULL ;
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
V_35 = F_11 ( V_14 ) ;
if ( ! V_35 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_68 = (struct V_67 * ) V_60 -> V_71 ;
V_68 -> V_79 . V_80 -- ;
F_41 ( V_60 , V_35 -> V_45 , V_35 -> V_32 ) ;
V_69 = V_82 ;
V_36:
if ( V_35 )
F_14 ( V_35 ) ;
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
if ( ! F_15 ( & V_39 -> V_33 ) )
continue;
if ( ( ! V_35 ) ||
( V_39 -> V_43 > V_35 -> V_43 ) ) {
if ( V_35 )
F_14 ( V_35 ) ;
V_35 = V_39 ;
F_15 ( & V_35 -> V_33 ) ;
}
F_14 ( V_39 ) ;
}
if ( ! V_35 && V_92 &&
F_15 ( & V_92 -> V_33 ) )
V_35 = V_92 ;
F_9 () ;
return V_35 ;
}
int F_51 ( struct V_59 * V_60 , struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_93 * V_94 ;
T_5 V_95 ;
struct V_62 * V_62 ;
char V_96 ;
T_2 V_97 ;
if ( F_31 ( ! F_32 ( V_60 ,
sizeof( struct V_93 ) ) ) )
goto V_36;
if ( F_35 ( V_60 , sizeof( struct V_93 ) ) < 0 )
goto V_36;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( F_34 ( V_62 -> V_63 ) )
goto V_36;
if ( F_34 ( V_62 -> V_64 ) )
goto V_36;
V_94 = (struct V_93 * ) V_60 -> V_71 ;
switch ( V_94 -> V_50 & V_98 ) {
case V_99 :
F_52 ( V_4 , V_100 ) ;
if ( ! F_53 ( V_4 , V_94 ) ) {
if ( V_94 -> V_50 & V_101 )
V_96 = 'F' ;
else
V_96 = '.' ;
F_12 ( V_102 , V_4 ,
L_7 ,
V_94 -> V_75 ,
V_96 ) ;
return F_54 ( V_60 , V_85 ) ;
}
break;
case V_103 :
F_52 ( V_4 , V_104 ) ;
if ( F_47 ( V_94 -> V_75 ) ) {
if ( F_36 ( V_60 ) < 0 )
goto V_36;
V_94 = (struct V_93 * ) V_60 -> V_71 ;
V_95 = F_55 ( F_56 ( V_94 -> V_105 ) ) ;
V_97 = sizeof( struct V_93 ) ;
V_97 += V_95 ;
if ( F_31 ( F_57 ( V_60 ) < V_97 ) )
goto V_36;
F_58 ( V_4 , V_94 ) ;
} else {
if ( V_94 -> V_50 & V_101 )
V_96 = 'F' ;
else
V_96 = '.' ;
F_12 ( V_102 , V_4 ,
L_8 ,
V_94 -> V_75 ,
V_96 ) ;
return F_54 ( V_60 , V_85 ) ;
}
break;
}
V_36:
return V_70 ;
}
int F_59 ( struct V_59 * V_60 , struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_106 * V_107 ;
struct V_13 * V_14 ;
struct V_62 * V_62 ;
if ( F_31 ( ! F_32 ( V_60 ,
sizeof( struct V_106 ) ) ) )
goto V_36;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( F_34 ( V_62 -> V_63 ) )
goto V_36;
if ( F_34 ( V_62 -> V_64 ) )
goto V_36;
F_52 ( V_4 , V_108 ) ;
V_107 = (struct V_106 * ) V_60 -> V_71 ;
if ( ! F_47 ( V_107 -> V_75 ) )
return F_54 ( V_60 , V_85 ) ;
if ( F_60 ( V_4 , V_107 -> V_109 ) )
goto V_36;
V_14 = F_40 ( V_4 , V_107 -> V_109 ) ;
if ( ! V_14 )
goto V_36;
F_12 ( V_102 , V_4 ,
L_9 ,
V_107 -> V_109 , V_107 -> V_110 ) ;
F_61 ( V_4 , V_14 , V_107 -> V_110 ,
V_111 ,
F_62 ( & V_14 -> V_112 ) + 1 ) ;
V_4 -> V_113 = true ;
F_43 ( V_14 ) ;
V_36:
return V_70 ;
}
struct V_27 *
F_63 ( struct V_3 * V_4 ,
struct V_13 * V_14 ,
const struct V_1 * V_85 )
{
struct V_13 * V_114 ;
struct V_13 * V_115 ;
struct V_27 * V_35 ;
static T_3 V_116 [ V_52 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_117 ;
T_3 * V_41 ;
if ( ! V_14 )
return NULL ;
V_35 = F_11 ( V_14 ) ;
if ( ! V_35 )
goto V_118;
V_117 = F_62 ( & V_4 -> V_119 ) ;
F_3 () ;
V_115 = V_35 -> V_14 ;
if ( ! V_115 )
goto V_120;
if ( ( ! V_85 ) && ( ! V_117 ) )
goto V_121;
V_41 = V_115 -> V_41 ;
if ( F_24 ( V_41 , V_116 ) )
goto V_121;
if ( F_24 ( V_41 , V_115 -> V_31 ) ) {
V_114 = V_115 ;
} else {
V_114 = F_40 ( V_4 ,
V_41 ) ;
if ( ! V_114 )
goto V_121;
F_43 ( V_114 ) ;
}
if ( F_62 ( & V_114 -> V_38 ) < 2 )
goto V_121;
F_14 ( V_35 ) ;
if ( V_117 )
V_35 = F_48 ( V_114 , V_85 ) ;
else
V_35 = F_50 ( V_114 , V_85 ) ;
V_121:
if ( V_35 && V_35 -> V_45 -> V_122 != V_123 )
goto V_120;
F_9 () ;
return V_35 ;
V_120:
F_9 () ;
V_118:
if ( V_35 )
F_14 ( V_35 ) ;
return NULL ;
}
static int F_64 ( struct V_59 * V_60 , int V_86 )
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
static int F_54 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_13 * V_14 = NULL ;
struct V_27 * V_28 = NULL ;
struct V_124 * V_125 ;
struct V_62 * V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
int V_69 = V_70 ;
struct V_59 * V_126 ;
V_125 = (struct V_124 * ) V_60 -> V_71 ;
if ( V_125 -> V_79 . V_80 < 2 ) {
F_45 ( L_10 ,
V_62 -> V_64 , V_125 -> V_127 ) ;
goto V_36;
}
V_14 = F_40 ( V_4 , V_125 -> V_127 ) ;
if ( ! V_14 )
goto V_36;
V_28 = F_63 ( V_4 , V_14 , V_85 ) ;
if ( ! V_28 )
goto V_36;
if ( F_35 ( V_60 , V_74 ) < 0 )
goto V_36;
V_125 = (struct V_124 * ) V_60 -> V_71 ;
if ( V_125 -> V_79 . V_128 == V_129 &&
F_62 ( & V_4 -> V_130 ) &&
V_60 -> V_87 > V_28 -> V_45 -> V_76 -> V_131 ) {
V_69 = F_65 ( V_60 , V_4 ,
V_28 -> V_45 ,
V_28 -> V_32 ) ;
goto V_36;
}
if ( V_125 -> V_79 . V_128 == V_132 &&
F_66 ( V_60 ,
V_28 -> V_45 -> V_76 -> V_131 ) ) {
V_69 = F_67 ( V_60 , V_4 , & V_126 ) ;
if ( V_69 == V_70 )
goto V_36;
if ( ! V_126 ) {
V_69 = V_82 ;
goto V_36;
}
V_60 = V_126 ;
V_125 = (struct V_124 * ) V_60 -> V_71 ;
}
V_125 -> V_79 . V_80 -- ;
F_52 ( V_4 , V_133 ) ;
F_68 ( V_4 , V_134 ,
V_60 -> V_87 + V_74 ) ;
F_41 ( V_60 , V_28 -> V_45 , V_28 -> V_32 ) ;
V_69 = V_82 ;
V_36:
if ( V_28 )
F_14 ( V_28 ) ;
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
static int F_69 ( struct V_3 * V_4 ,
struct V_59 * V_60 ) {
T_3 V_135 ;
struct V_13 * V_14 ;
struct V_62 * V_62 ;
struct V_1 * V_66 ;
struct V_124 * V_125 ;
bool V_113 ;
int V_136 ;
if ( F_35 ( V_60 , sizeof( struct V_124 ) ) < 0 )
return 0 ;
V_125 = (struct V_124 * ) V_60 -> V_71 ;
if ( F_47 ( V_125 -> V_127 ) ) {
V_113 = V_4 -> V_113 ;
V_135 = ( T_3 ) F_62 ( & V_4 -> V_137 ) ;
} else {
V_14 = F_40 ( V_4 ,
V_125 -> V_127 ) ;
if ( ! V_14 )
return 0 ;
V_135 = ( T_3 ) F_62 ( & V_14 -> V_112 ) ;
V_113 = V_14 -> V_113 ;
F_43 ( V_14 ) ;
}
V_136 = F_70 ( V_125 -> V_137 , V_135 ) ;
if ( V_136 || V_113 ) {
if ( F_32 ( V_60 , sizeof( struct V_124 ) +
V_74 ) < 0 )
return 0 ;
V_62 = (struct V_62 * ) ( V_60 -> V_71 + sizeof( * V_125 ) ) ;
if ( F_71 ( V_4 ,
V_62 -> V_63 ) )
return 1 ;
V_14 = F_72 ( V_4 , NULL ,
V_62 -> V_63 ) ;
if ( ! V_14 ) {
if ( ! F_73 ( V_4 , V_62 -> V_63 ) )
return 0 ;
V_66 = F_39 ( V_4 ) ;
if ( ! V_66 )
return 0 ;
memcpy ( V_125 -> V_127 ,
V_66 -> V_76 -> V_77 , V_52 ) ;
F_42 ( V_66 ) ;
} else {
memcpy ( V_125 -> V_127 , V_14 -> V_31 ,
V_52 ) ;
V_135 = ( T_3 )
F_62 ( & V_14 -> V_112 ) ;
F_43 ( V_14 ) ;
}
F_12 ( V_30 , V_4 ,
L_11 ,
V_125 -> V_137 , V_135 , V_62 -> V_63 ,
V_125 -> V_127 ) ;
V_125 -> V_137 = V_135 ;
}
return 1 ;
}
int F_74 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_124 * V_125 ;
int V_86 = sizeof( * V_125 ) ;
if ( F_64 ( V_60 , V_86 ) < 0 )
return V_70 ;
if ( ! F_69 ( V_4 , V_60 ) )
return V_70 ;
V_125 = (struct V_124 * ) V_60 -> V_71 ;
if ( F_47 ( V_125 -> V_127 ) ) {
F_75 ( V_85 -> V_5 , V_60 , V_85 ,
V_86 ) ;
return V_82 ;
}
return F_54 ( V_60 , V_85 ) ;
}
int F_76 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_138 * V_125 ;
int V_86 = sizeof( * V_125 ) ;
struct V_59 * V_126 = NULL ;
int V_69 ;
if ( F_64 ( V_60 , V_86 ) < 0 )
return V_70 ;
if ( ! F_69 ( V_4 , V_60 ) )
return V_70 ;
V_125 = (struct V_138 * ) V_60 -> V_71 ;
if ( F_47 ( V_125 -> V_127 ) ) {
V_69 = F_67 ( V_60 , V_4 , & V_126 ) ;
if ( V_69 == V_70 )
return V_70 ;
if ( ! V_126 )
return V_82 ;
F_75 ( V_85 -> V_5 , V_126 , V_85 ,
sizeof( struct V_124 ) ) ;
return V_82 ;
}
return F_54 ( V_60 , V_85 ) ;
}
int F_77 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
struct V_13 * V_14 = NULL ;
struct V_139 * V_140 ;
struct V_62 * V_62 ;
int V_86 = sizeof( * V_140 ) ;
int V_69 = V_70 ;
T_4 V_141 ;
if ( F_31 ( ! F_32 ( V_60 , V_86 ) ) )
goto V_36;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( ! F_34 ( V_62 -> V_63 ) )
goto V_36;
if ( F_34 ( V_62 -> V_64 ) )
goto V_36;
if ( F_47 ( V_62 -> V_64 ) )
goto V_36;
V_140 = (struct V_139 * ) V_60 -> V_71 ;
if ( F_47 ( V_140 -> V_31 ) )
goto V_36;
if ( V_140 -> V_79 . V_80 < 2 )
goto V_36;
V_14 = F_40 ( V_4 , V_140 -> V_31 ) ;
if ( ! V_14 )
goto V_36;
F_5 ( & V_14 -> V_142 ) ;
if ( F_78 ( V_14 -> V_143 , V_14 -> V_144 ,
F_79 ( V_140 -> V_145 ) ) )
goto V_146;
V_141 = F_79 ( V_140 -> V_145 ) - V_14 -> V_144 ;
if ( F_28 ( V_4 , V_141 ,
& V_14 -> V_147 ) )
goto V_146;
if ( F_6 ( V_4 , V_14 -> V_143 , V_141 , 1 ) )
V_14 -> V_144 = F_79 ( V_140 -> V_145 ) ;
F_8 ( & V_14 -> V_142 ) ;
if ( F_80 ( V_4 , V_140 , V_86 ) )
goto V_36;
F_81 ( V_4 , V_60 , 1 ) ;
if ( F_82 ( V_60 , V_14 , V_86 ) )
goto V_36;
F_75 ( V_85 -> V_5 , V_60 , V_85 , V_86 ) ;
V_69 = V_82 ;
goto V_36;
V_146:
F_8 ( & V_14 -> V_142 ) ;
V_36:
if ( V_14 )
F_43 ( V_14 ) ;
return V_69 ;
}
int F_83 ( struct V_59 * V_60 ,
struct V_1 * V_85 )
{
struct V_148 * V_149 ;
struct V_62 * V_62 ;
struct V_3 * V_4 = F_2 ( V_85 -> V_5 ) ;
int V_86 = sizeof( * V_149 ) ;
if ( F_36 ( V_60 ) < 0 )
return V_70 ;
if ( F_31 ( ! F_32 ( V_60 , V_86 ) ) )
return V_70 ;
V_149 = (struct V_148 * ) V_60 -> V_71 ;
V_62 = (struct V_62 * ) F_33 ( V_60 ) ;
if ( ! F_47 ( V_62 -> V_63 ) )
return V_70 ;
if ( F_47 ( V_149 -> V_150 ) )
return V_70 ;
if ( F_47 ( V_149 -> V_151 ) )
return V_70 ;
switch ( V_149 -> V_152 ) {
case V_153 :
F_84 ( V_4 , V_149 ,
F_57 ( V_60 ) ) ;
break;
case V_154 :
F_85 ( V_4 , V_149 ,
F_57 ( V_60 ) ) ;
break;
default:
break;
}
return V_70 ;
}
