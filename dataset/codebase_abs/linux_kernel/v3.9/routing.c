void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned long * V_13 ;
T_1 V_14 ;
T_2 V_15 ;
T_3 * V_16 ;
for ( V_14 = 0 ; V_14 < V_7 -> V_17 ; V_14 ++ ) {
V_10 = & V_7 -> V_18 [ V_14 ] ;
F_3 () ;
F_4 (orig_node, head, hash_entry) {
F_5 ( & V_12 -> V_19 ) ;
V_15 = V_2 -> V_20 * V_21 ;
V_13 = & ( V_12 -> V_22 [ V_15 ] ) ;
F_6 ( V_4 , V_13 , 1 , 0 ) ;
V_16 = & V_12 -> V_23 [ V_2 -> V_20 ] ;
* V_16 = F_7 ( V_13 , V_24 ) ;
F_8 ( & V_12 -> V_19 ) ;
}
F_9 () ;
}
}
static void F_10 ( struct V_3 * V_4 ,
struct V_11 * V_12 ,
struct V_25 * V_26 )
{
struct V_25 * V_27 ;
V_27 = F_11 ( V_12 ) ;
if ( ( V_27 ) && ( ! V_26 ) ) {
F_12 ( V_28 , V_4 ,
L_1 , V_12 -> V_29 ) ;
F_13 ( V_4 , V_12 ,
L_2 ) ;
} else if ( ( ! V_27 ) && ( V_26 ) ) {
F_12 ( V_28 , V_4 ,
L_3 ,
V_12 -> V_29 , V_26 -> V_30 ) ;
} else if ( V_26 && V_27 ) {
F_12 ( V_28 , V_4 ,
L_4 ,
V_12 -> V_29 , V_26 -> V_30 ,
V_27 -> V_30 ) ;
}
if ( V_27 )
F_14 ( V_27 ) ;
if ( V_26 && ! F_15 ( & V_26 -> V_31 ) )
V_26 = NULL ;
F_5 ( & V_12 -> V_32 ) ;
F_16 ( V_12 -> V_33 , V_26 ) ;
F_8 ( & V_12 -> V_32 ) ;
if ( V_27 )
F_14 ( V_27 ) ;
}
void F_17 ( struct V_3 * V_4 ,
struct V_11 * V_12 ,
struct V_25 * V_26 )
{
struct V_25 * V_33 = NULL ;
if ( ! V_12 )
goto V_34;
V_33 = F_11 ( V_12 ) ;
if ( V_33 != V_26 )
F_10 ( V_4 , V_12 , V_26 ) ;
V_34:
if ( V_33 )
F_14 ( V_33 ) ;
}
void F_18 ( struct V_11 * V_12 ,
struct V_25 * V_26 )
{
if ( F_19 ( & V_26 -> V_35 ) )
goto V_34;
F_20 ( & V_26 -> V_35 ) ;
F_21 ( & V_26 -> V_35 ) ;
F_14 ( V_26 ) ;
F_22 ( & V_12 -> V_36 ) ;
V_34:
return;
}
void F_23 ( struct V_11 * V_12 ,
struct V_25 * V_26 )
{
struct V_25 * V_37 , * V_33 = NULL ;
T_3 V_38 = 0 ;
F_5 ( & V_12 -> V_32 ) ;
if ( ! F_24 ( V_12 -> V_29 ,
V_26 -> V_12 -> V_39 ) )
goto V_40;
V_33 = F_11 ( V_12 ) ;
if ( ! V_33 )
goto V_40;
if ( V_26 -> V_41 < V_33 -> V_41 - V_42 )
goto V_40;
F_4 (tmp_neigh_node,
&orig_node->neigh_list, list) {
if ( V_37 == V_26 )
continue;
if ( F_19 ( & V_37 -> V_35 ) )
continue;
if ( ( V_26 -> V_43 == V_37 -> V_43 ) ||
( F_24 ( V_26 -> V_30 ,
V_37 -> V_30 ) ) ) {
V_38 = 1 ;
break;
}
}
if ( V_38 )
goto V_40;
if ( ! F_19 ( & V_26 -> V_35 ) )
goto V_34;
if ( ! F_15 ( & V_26 -> V_31 ) )
goto V_34;
F_25 ( & V_26 -> V_35 , & V_12 -> V_44 ) ;
F_26 ( & V_12 -> V_36 ) ;
goto V_34;
V_40:
F_18 ( V_12 , V_26 ) ;
V_34:
F_8 ( & V_12 -> V_32 ) ;
if ( V_33 )
F_14 ( V_33 ) ;
}
void
F_27 ( const struct V_11 * V_12 ,
struct V_11 * V_45 ,
const struct V_46 * V_47 )
{
if ( ! ( V_47 -> V_48 & V_49 ) )
return;
memcpy ( V_45 -> V_39 , V_12 -> V_29 , V_50 ) ;
}
int F_28 ( struct V_3 * V_4 , T_4 V_51 ,
unsigned long * V_52 )
{
if ( V_51 <= - V_24 ||
V_51 >= V_53 ) {
if ( ! F_29 ( * V_52 ,
V_54 ) )
return 1 ;
* V_52 = V_55 ;
F_12 ( V_56 , V_4 ,
L_5 ) ;
}
return 0 ;
}
bool F_30 ( struct V_57 * V_58 ,
struct V_1 * V_2 ,
int V_59 )
{
struct V_60 * V_60 ;
if ( F_31 ( ! F_32 ( V_58 , V_59 ) ) )
return false ;
V_60 = (struct V_60 * ) F_33 ( V_58 ) ;
if ( ! F_34 ( V_60 -> V_61 ) )
return false ;
if ( F_34 ( V_60 -> V_62 ) )
return false ;
if ( F_35 ( V_58 , 0 ) < 0 )
return false ;
if ( F_36 ( V_58 ) < 0 )
return false ;
return true ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_57 * V_58 , T_2 V_63 )
{
struct V_1 * V_64 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_65 * V_66 ;
int V_67 = V_68 ;
V_66 = (struct V_65 * ) V_58 -> V_69 ;
if ( V_66 -> V_70 != V_71 ) {
F_38 ( V_66 , V_63 ) ;
goto V_34;
}
V_64 = F_39 ( V_4 ) ;
if ( ! V_64 )
goto V_34;
V_12 = F_40 ( V_4 , V_66 -> V_29 ) ;
if ( ! V_12 )
goto V_34;
if ( F_35 ( V_58 , V_72 ) < 0 )
goto V_34;
V_66 = (struct V_65 * ) V_58 -> V_69 ;
memcpy ( V_66 -> V_73 , V_66 -> V_29 , V_50 ) ;
memcpy ( V_66 -> V_29 , V_64 -> V_74 -> V_75 , V_50 ) ;
V_66 -> V_70 = V_76 ;
V_66 -> V_77 . V_78 = V_79 ;
if ( F_41 ( V_58 , V_12 , NULL ) )
V_67 = V_80 ;
V_34:
if ( V_64 )
F_42 ( V_64 ) ;
if ( V_12 )
F_43 ( V_12 ) ;
return V_67 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_57 * V_58 )
{
struct V_1 * V_64 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_81 * V_66 ;
int V_67 = V_68 ;
V_66 = (struct V_81 * ) V_58 -> V_69 ;
if ( V_66 -> V_70 != V_71 ) {
F_45 ( L_6 ,
V_66 -> V_29 , V_66 -> V_73 ) ;
goto V_34;
}
V_64 = F_39 ( V_4 ) ;
if ( ! V_64 )
goto V_34;
V_12 = F_40 ( V_4 , V_66 -> V_29 ) ;
if ( ! V_12 )
goto V_34;
if ( F_35 ( V_58 , V_72 ) < 0 )
goto V_34;
V_66 = (struct V_81 * ) V_58 -> V_69 ;
memcpy ( V_66 -> V_73 , V_66 -> V_29 , V_50 ) ;
memcpy ( V_66 -> V_29 , V_64 -> V_74 -> V_75 , V_50 ) ;
V_66 -> V_70 = V_82 ;
V_66 -> V_77 . V_78 = V_79 ;
if ( F_41 ( V_58 , V_12 , NULL ) )
V_67 = V_80 ;
V_34:
if ( V_64 )
F_42 ( V_64 ) ;
if ( V_12 )
F_43 ( V_12 ) ;
return V_67 ;
}
int F_46 ( struct V_57 * V_58 ,
struct V_1 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
struct V_65 * V_66 ;
struct V_60 * V_60 ;
struct V_11 * V_12 = NULL ;
int V_84 = sizeof( struct V_81 ) ;
int V_67 = V_68 ;
if ( V_58 -> V_85 >= sizeof( struct V_65 ) )
V_84 = sizeof( struct V_65 ) ;
if ( F_31 ( ! F_32 ( V_58 , V_84 ) ) )
goto V_34;
V_60 = (struct V_60 * ) F_33 ( V_58 ) ;
if ( F_34 ( V_60 -> V_61 ) )
goto V_34;
if ( F_34 ( V_60 -> V_62 ) )
goto V_34;
if ( ! F_47 ( V_4 , V_60 -> V_61 ) )
goto V_34;
V_66 = (struct V_65 * ) V_58 -> V_69 ;
if ( ( V_84 == sizeof( struct V_65 ) ) &&
( V_66 -> V_86 < V_87 ) ) {
memcpy ( & ( V_66 -> V_88 [ V_66 -> V_86 ] ) ,
V_60 -> V_61 , V_50 ) ;
V_66 -> V_86 ++ ;
}
if ( F_47 ( V_4 , V_66 -> V_73 ) )
return F_37 ( V_4 , V_58 , V_84 ) ;
if ( V_66 -> V_77 . V_78 < 2 )
return F_44 ( V_4 , V_58 ) ;
V_12 = F_40 ( V_4 , V_66 -> V_73 ) ;
if ( ! V_12 )
goto V_34;
if ( F_35 ( V_58 , V_72 ) < 0 )
goto V_34;
V_66 = (struct V_65 * ) V_58 -> V_69 ;
V_66 -> V_77 . V_78 -- ;
if ( F_41 ( V_58 , V_12 , V_83 ) )
V_67 = V_80 ;
V_34:
if ( V_12 )
F_43 ( V_12 ) ;
return V_67 ;
}
static struct V_25 *
F_48 ( struct V_11 * V_89 ,
const struct V_1 * V_83 )
{
struct V_25 * V_37 ;
struct V_25 * V_33 = NULL , * V_90 = NULL ;
F_3 () ;
F_49 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_90 )
V_90 = V_37 ;
if ( V_37 -> V_43 == V_83 )
continue;
if ( ! F_15 ( & V_37 -> V_31 ) )
continue;
V_33 = V_37 ;
break;
}
if ( ! V_33 && V_90 &&
F_15 ( & V_90 -> V_31 ) )
V_33 = V_90 ;
if ( ! V_33 )
goto V_34;
F_5 ( & V_89 -> V_32 ) ;
F_20 ( & V_89 -> V_44 ) ;
F_25 ( & V_89 -> V_44 ,
& V_33 -> V_35 ) ;
F_8 ( & V_89 -> V_32 ) ;
V_34:
F_9 () ;
return V_33 ;
}
static struct V_25 *
F_50 ( struct V_11 * V_89 ,
const struct V_1 * V_83 )
{
struct V_25 * V_37 ;
struct V_25 * V_33 = NULL , * V_90 = NULL ;
F_3 () ;
F_49 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_90 )
V_90 = V_37 ;
if ( V_37 -> V_43 == V_83 )
continue;
if ( V_33 && V_37 -> V_41 <= V_33 -> V_41 )
continue;
if ( ! F_15 ( & V_37 -> V_31 ) )
continue;
if ( V_33 )
F_14 ( V_33 ) ;
V_33 = V_37 ;
}
if ( ! V_33 && V_90 &&
F_15 ( & V_90 -> V_31 ) )
V_33 = V_90 ;
F_9 () ;
return V_33 ;
}
static int F_51 ( struct V_3 * V_4 ,
struct V_57 * V_58 , int V_84 )
{
struct V_60 * V_60 ;
if ( F_31 ( ! F_32 ( V_58 , V_84 ) ) )
return - 1 ;
V_60 = (struct V_60 * ) F_33 ( V_58 ) ;
if ( F_34 ( V_60 -> V_61 ) )
return - 1 ;
if ( F_34 ( V_60 -> V_62 ) )
return - 1 ;
if ( ! F_47 ( V_4 , V_60 -> V_61 ) )
return - 1 ;
return 0 ;
}
int F_52 ( struct V_57 * V_58 , struct V_1 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
struct V_91 * V_92 ;
T_5 V_93 ;
int V_84 = sizeof( * V_92 ) ;
char V_94 ;
T_2 V_95 ;
if ( F_51 ( V_4 , V_58 , V_84 ) < 0 )
return V_68 ;
if ( F_35 ( V_58 , sizeof( struct V_91 ) ) < 0 )
goto V_34;
V_92 = (struct V_91 * ) V_58 -> V_69 ;
switch ( V_92 -> V_48 & V_96 ) {
case V_97 :
F_53 ( V_4 , V_98 ) ;
if ( ! F_54 ( V_4 , V_92 ) ) {
if ( V_92 -> V_48 & V_99 )
V_94 = 'F' ;
else
V_94 = '.' ;
F_12 ( V_100 , V_4 ,
L_7 ,
V_92 -> V_73 ,
V_94 ) ;
return F_55 ( V_58 , V_83 ) ;
}
break;
case V_101 :
F_53 ( V_4 , V_102 ) ;
if ( F_47 ( V_4 , V_92 -> V_73 ) ) {
if ( F_36 ( V_58 ) < 0 )
goto V_34;
V_92 = (struct V_91 * ) V_58 -> V_69 ;
V_93 = F_56 ( F_57 ( V_92 -> V_103 ) ) ;
V_95 = sizeof( struct V_91 ) ;
V_95 += V_93 ;
if ( F_31 ( F_58 ( V_58 ) < V_95 ) )
goto V_34;
F_59 ( V_4 , V_92 ) ;
} else {
if ( V_92 -> V_48 & V_99 )
V_94 = 'F' ;
else
V_94 = '.' ;
F_12 ( V_100 , V_4 ,
L_8 ,
V_92 -> V_73 ,
V_94 ) ;
return F_55 ( V_58 , V_83 ) ;
}
break;
}
V_34:
return V_68 ;
}
int F_60 ( struct V_57 * V_58 , struct V_1 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
struct V_104 * V_105 ;
struct V_11 * V_12 ;
if ( F_51 ( V_4 , V_58 ,
sizeof( * V_105 ) ) < 0 )
goto V_34;
F_53 ( V_4 , V_106 ) ;
V_105 = (struct V_104 * ) V_58 -> V_69 ;
if ( ! F_47 ( V_4 , V_105 -> V_73 ) )
return F_55 ( V_58 , V_83 ) ;
if ( F_61 ( V_4 , V_105 -> V_107 ) )
goto V_34;
V_12 = F_40 ( V_4 , V_105 -> V_107 ) ;
if ( ! V_12 )
goto V_34;
F_12 ( V_100 , V_4 ,
L_9 ,
V_105 -> V_107 , V_105 -> V_108 ) ;
F_62 ( V_4 , V_12 , V_105 -> V_108 ,
V_109 ,
F_63 ( & V_12 -> V_110 ) + 1 ) ;
F_43 ( V_12 ) ;
V_34:
return V_68 ;
}
struct V_25 *
F_64 ( struct V_3 * V_4 ,
struct V_11 * V_12 ,
const struct V_1 * V_83 )
{
struct V_11 * V_111 ;
struct V_11 * V_112 ;
struct V_25 * V_33 ;
static T_3 V_113 [ V_50 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_114 ;
T_3 * V_39 ;
if ( ! V_12 )
return NULL ;
V_33 = F_11 ( V_12 ) ;
if ( ! V_33 )
goto V_115;
V_114 = F_63 ( & V_4 -> V_116 ) ;
F_3 () ;
V_112 = V_33 -> V_12 ;
if ( ! V_112 )
goto V_117;
if ( ( ! V_83 ) && ( ! V_114 ) )
goto V_118;
V_39 = V_112 -> V_39 ;
if ( F_24 ( V_39 , V_113 ) )
goto V_118;
if ( F_24 ( V_39 , V_112 -> V_29 ) ) {
V_111 = V_112 ;
} else {
V_111 = F_40 ( V_4 ,
V_39 ) ;
if ( ! V_111 )
goto V_118;
F_43 ( V_111 ) ;
}
if ( F_63 ( & V_111 -> V_36 ) < 2 )
goto V_118;
F_14 ( V_33 ) ;
if ( V_114 )
V_33 = F_48 ( V_111 , V_83 ) ;
else
V_33 = F_50 ( V_111 , V_83 ) ;
V_118:
if ( V_33 && V_33 -> V_43 -> V_119 != V_120 )
goto V_117;
F_9 () ;
return V_33 ;
V_117:
F_9 () ;
V_115:
if ( V_33 )
F_14 ( V_33 ) ;
return NULL ;
}
static int F_55 ( struct V_57 * V_58 ,
struct V_1 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
struct V_11 * V_12 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_121 * V_122 ;
struct V_60 * V_60 = (struct V_60 * ) F_33 ( V_58 ) ;
int V_67 = V_68 ;
struct V_57 * V_123 ;
V_122 = (struct V_121 * ) V_58 -> V_69 ;
if ( V_122 -> V_77 . V_78 < 2 ) {
F_45 ( L_10 ,
V_60 -> V_62 , V_122 -> V_124 ) ;
goto V_34;
}
V_12 = F_40 ( V_4 , V_122 -> V_124 ) ;
if ( ! V_12 )
goto V_34;
V_26 = F_64 ( V_4 , V_12 , V_83 ) ;
if ( ! V_26 )
goto V_34;
if ( F_35 ( V_58 , V_72 ) < 0 )
goto V_34;
V_122 = (struct V_121 * ) V_58 -> V_69 ;
if ( V_122 -> V_77 . V_125 == V_126 &&
F_63 ( & V_4 -> V_127 ) &&
V_58 -> V_85 > V_26 -> V_43 -> V_74 -> V_128 ) {
V_67 = F_65 ( V_58 , V_4 ,
V_26 -> V_43 ,
V_26 -> V_30 ) ;
goto V_34;
}
if ( V_122 -> V_77 . V_125 == V_129 &&
F_66 ( V_58 ,
V_26 -> V_43 -> V_74 -> V_128 ) ) {
V_67 = F_67 ( V_58 , V_4 , & V_123 ) ;
if ( V_67 == V_68 )
goto V_34;
if ( ! V_123 ) {
V_67 = V_80 ;
goto V_34;
}
V_58 = V_123 ;
V_122 = (struct V_121 * ) V_58 -> V_69 ;
}
V_122 -> V_77 . V_78 -- ;
F_53 ( V_4 , V_130 ) ;
F_68 ( V_4 , V_131 ,
V_58 -> V_85 + V_72 ) ;
if ( F_41 ( V_58 , V_12 , V_83 ) )
V_67 = V_80 ;
V_34:
if ( V_26 )
F_14 ( V_26 ) ;
if ( V_12 )
F_43 ( V_12 ) ;
return V_67 ;
}
static bool
F_69 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
T_3 * V_132 )
{
struct V_11 * V_12 = NULL ;
struct V_1 * V_64 = NULL ;
bool V_67 = false ;
T_3 * V_133 , V_134 ;
if ( F_70 ( V_4 , V_132 ) ) {
V_64 = F_39 ( V_4 ) ;
if ( ! V_64 )
goto V_34;
V_133 = V_64 -> V_74 -> V_75 ;
V_134 = ( T_3 ) F_63 ( & V_4 -> V_135 . V_136 ) ;
} else {
V_12 = F_71 ( V_4 , NULL , V_132 ) ;
if ( ! V_12 )
goto V_34;
if ( F_24 ( V_12 -> V_29 , V_122 -> V_124 ) )
goto V_34;
V_133 = V_12 -> V_29 ;
V_134 = ( T_3 ) F_63 ( & V_12 -> V_110 ) ;
}
memcpy ( V_122 -> V_124 , V_133 , V_50 ) ;
V_122 -> V_137 = V_134 ;
V_67 = true ;
V_34:
if ( V_64 )
F_42 ( V_64 ) ;
if ( V_12 )
F_43 ( V_12 ) ;
return V_67 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_57 * V_58 ) {
T_3 V_138 , V_139 ;
struct V_11 * V_12 ;
struct V_60 * V_60 ;
struct V_1 * V_64 ;
struct V_121 * V_122 ;
int V_140 ;
if ( F_32 ( V_58 , sizeof( * V_122 ) + V_72 ) < 0 )
return 0 ;
if ( F_35 ( V_58 , sizeof( * V_122 ) ) < 0 )
return 0 ;
V_122 = (struct V_121 * ) V_58 -> V_69 ;
V_60 = (struct V_60 * ) ( V_58 -> V_69 + sizeof( * V_122 ) ) ;
if ( F_73 ( V_4 , V_60 -> V_61 ) ) {
if ( F_69 ( V_4 , V_122 ,
V_60 -> V_61 ) )
F_74 ( F_12 , V_100 ,
V_4 ,
L_11 ,
V_122 -> V_124 ,
V_60 -> V_61 ) ;
return 1 ;
}
V_138 = ( T_3 ) F_63 ( & V_4 -> V_135 . V_136 ) ;
if ( ! F_47 ( V_4 , V_122 -> V_124 ) ) {
V_12 = F_40 ( V_4 ,
V_122 -> V_124 ) ;
if ( ! V_12 )
return 0 ;
V_138 = ( T_3 ) F_63 ( & V_12 -> V_110 ) ;
F_43 ( V_12 ) ;
}
V_140 = F_75 ( V_122 -> V_137 , V_138 ) ;
if ( ! V_140 )
return 1 ;
V_139 = V_122 -> V_137 ;
if ( F_69 ( V_4 , V_122 ,
V_60 -> V_61 ) ) {
F_74 ( F_12 , V_100 , V_4 ,
L_12 ,
V_122 -> V_124 , V_60 -> V_61 ,
V_139 , V_138 ) ;
return 1 ;
}
if ( ! F_70 ( V_4 , V_60 -> V_61 ) )
return 0 ;
V_64 = F_39 ( V_4 ) ;
if ( ! V_64 )
return 0 ;
memcpy ( V_122 -> V_124 , V_64 -> V_74 -> V_75 , V_50 ) ;
F_42 ( V_64 ) ;
V_122 -> V_137 = V_138 ;
return 1 ;
}
int F_76 ( struct V_57 * V_58 ,
struct V_1 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
struct V_121 * V_122 ;
struct V_141 * V_142 ;
T_3 * V_133 ;
struct V_11 * V_12 = NULL ;
int V_84 = sizeof( * V_122 ) ;
bool V_143 ;
V_122 = (struct V_121 * ) V_58 -> V_69 ;
V_142 = (struct V_141 * ) V_58 -> V_69 ;
V_143 = V_122 -> V_77 . V_125 == V_144 ;
if ( V_143 )
V_84 = sizeof( * V_142 ) ;
if ( F_51 ( V_4 , V_58 , V_84 ) < 0 )
return V_68 ;
if ( ! F_72 ( V_4 , V_58 ) )
return V_68 ;
if ( F_47 ( V_4 , V_122 -> V_124 ) ) {
if ( V_143 ) {
F_77 ( V_4 ,
V_142 -> V_145 ) ;
V_133 = V_142 -> V_107 ;
V_12 = F_40 ( V_4 , V_133 ) ;
}
if ( F_78 ( V_4 , V_58 ,
V_84 ) )
goto V_146;
if ( F_79 ( V_4 , V_58 ,
V_84 ) )
goto V_146;
F_80 ( V_83 -> V_5 , V_58 , V_83 , V_84 ,
V_12 ) ;
V_146:
if ( V_12 )
F_43 ( V_12 ) ;
return V_80 ;
}
return F_55 ( V_58 , V_83 ) ;
}
int F_81 ( struct V_57 * V_58 ,
struct V_1 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
struct V_147 * V_122 ;
int V_84 = sizeof( * V_122 ) ;
struct V_57 * V_123 = NULL ;
int V_67 ;
if ( F_51 ( V_4 , V_58 , V_84 ) < 0 )
return V_68 ;
if ( ! F_72 ( V_4 , V_58 ) )
return V_68 ;
V_122 = (struct V_147 * ) V_58 -> V_69 ;
if ( F_47 ( V_4 , V_122 -> V_124 ) ) {
V_67 = F_67 ( V_58 , V_4 , & V_123 ) ;
if ( V_67 == V_68 )
return V_68 ;
if ( ! V_123 )
return V_80 ;
if ( F_78 ( V_4 , V_123 ,
V_84 ) )
goto V_146;
if ( F_79 ( V_4 , V_123 ,
V_84 ) )
goto V_146;
F_80 ( V_83 -> V_5 , V_123 , V_83 ,
sizeof( struct V_121 ) , NULL ) ;
V_146:
return V_80 ;
}
return F_55 ( V_58 , V_83 ) ;
}
int F_82 ( struct V_57 * V_58 ,
struct V_1 * V_83 )
{
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
struct V_11 * V_12 = NULL ;
struct V_148 * V_149 ;
struct V_60 * V_60 ;
int V_84 = sizeof( * V_149 ) ;
int V_67 = V_68 ;
T_4 V_150 ;
if ( F_31 ( ! F_32 ( V_58 , V_84 ) ) )
goto V_34;
V_60 = (struct V_60 * ) F_33 ( V_58 ) ;
if ( ! F_34 ( V_60 -> V_61 ) )
goto V_34;
if ( F_34 ( V_60 -> V_62 ) )
goto V_34;
if ( F_47 ( V_4 , V_60 -> V_62 ) )
goto V_34;
V_149 = (struct V_148 * ) V_58 -> V_69 ;
if ( F_47 ( V_4 , V_149 -> V_29 ) )
goto V_34;
if ( V_149 -> V_77 . V_78 < 2 )
goto V_34;
V_12 = F_40 ( V_4 , V_149 -> V_29 ) ;
if ( ! V_12 )
goto V_34;
F_5 ( & V_12 -> V_151 ) ;
if ( F_83 ( V_12 -> V_152 , V_12 -> V_153 ,
F_84 ( V_149 -> V_154 ) ) )
goto V_155;
V_150 = F_84 ( V_149 -> V_154 ) - V_12 -> V_153 ;
if ( F_28 ( V_4 , V_150 ,
& V_12 -> V_156 ) )
goto V_155;
if ( F_6 ( V_4 , V_12 -> V_152 , V_150 , 1 ) )
V_12 -> V_153 = F_84 ( V_149 -> V_154 ) ;
F_8 ( & V_12 -> V_151 ) ;
if ( F_85 ( V_4 , V_58 ) )
goto V_34;
F_86 ( V_4 , V_58 , 1 ) ;
if ( F_87 ( V_58 , V_12 , V_84 ) )
goto V_34;
if ( F_78 ( V_4 , V_58 , V_84 ) )
goto V_146;
if ( F_79 ( V_4 , V_58 , V_84 ) )
goto V_146;
F_80 ( V_83 -> V_5 , V_58 , V_83 , V_84 ,
V_12 ) ;
V_146:
V_67 = V_80 ;
goto V_34;
V_155:
F_8 ( & V_12 -> V_151 ) ;
V_34:
if ( V_12 )
F_43 ( V_12 ) ;
return V_67 ;
}
int F_88 ( struct V_57 * V_58 ,
struct V_1 * V_83 )
{
struct V_157 * V_158 ;
struct V_60 * V_60 ;
struct V_3 * V_4 = F_2 ( V_83 -> V_5 ) ;
int V_84 = sizeof( * V_158 ) ;
if ( F_36 ( V_58 ) < 0 )
return V_68 ;
if ( F_31 ( ! F_32 ( V_58 , V_84 ) ) )
return V_68 ;
V_158 = (struct V_157 * ) V_58 -> V_69 ;
V_60 = (struct V_60 * ) F_33 ( V_58 ) ;
if ( ! F_47 ( V_4 , V_60 -> V_61 ) )
return V_68 ;
if ( F_47 ( V_4 , V_158 -> V_159 ) )
return V_68 ;
if ( F_47 ( V_4 , V_158 -> V_160 ) )
return V_68 ;
switch ( V_158 -> V_161 ) {
case V_162 :
F_89 ( V_4 , V_158 ,
F_58 ( V_58 ) ) ;
break;
case V_163 :
F_90 ( V_4 , V_158 ,
F_58 ( V_58 ) ) ;
break;
default:
break;
}
return V_68 ;
}
