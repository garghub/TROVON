void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 -> V_3 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_11 ;
unsigned long * V_12 ;
T_1 V_13 ;
T_2 V_14 ;
for ( V_13 = 0 ; V_13 < V_5 -> V_15 ; V_13 ++ ) {
V_10 = & V_5 -> V_16 [ V_13 ] ;
F_3 () ;
F_4 (orig_node, node, head, hash_entry) {
F_5 ( & V_11 -> V_17 ) ;
V_14 = V_1 -> V_18 * V_19 ;
V_12 = & ( V_11 -> V_20 [ V_14 ] ) ;
F_6 ( V_2 , V_12 , 1 , 0 ) ;
V_11 -> V_21 [ V_1 -> V_18 ] =
F_7 ( V_12 , V_22 ) ;
F_8 ( & V_11 -> V_17 ) ;
}
F_9 () ;
}
}
static void F_10 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
struct V_23 * V_23 )
{
struct V_23 * V_24 ;
V_24 = F_11 ( V_11 ) ;
if ( ( V_24 ) && ( ! V_23 ) ) {
F_12 ( V_25 , V_2 , L_1 ,
V_11 -> V_26 ) ;
F_13 ( V_2 , V_11 ,
L_2 ) ;
} else if ( ( ! V_24 ) && ( V_23 ) ) {
F_12 ( V_25 , V_2 ,
L_3 ,
V_11 -> V_26 , V_23 -> V_27 ) ;
} else if ( V_23 && V_24 ) {
F_12 ( V_25 , V_2 ,
L_4 ,
V_11 -> V_26 , V_23 -> V_27 ,
V_24 -> V_27 ) ;
}
if ( V_24 )
F_14 ( V_24 ) ;
if ( V_23 && ! F_15 ( & V_23 -> V_28 ) )
V_23 = NULL ;
F_5 ( & V_11 -> V_29 ) ;
F_16 ( V_11 -> V_30 , V_23 ) ;
F_8 ( & V_11 -> V_29 ) ;
if ( V_24 )
F_14 ( V_24 ) ;
}
void F_17 ( struct V_2 * V_2 , struct V_11 * V_11 ,
struct V_23 * V_23 )
{
struct V_23 * V_30 = NULL ;
if ( ! V_11 )
goto V_31;
V_30 = F_11 ( V_11 ) ;
if ( V_30 != V_23 )
F_10 ( V_2 , V_11 , V_23 ) ;
V_31:
if ( V_30 )
F_14 ( V_30 ) ;
}
void F_18 ( struct V_11 * V_11 ,
struct V_23 * V_23 )
{
if ( F_19 ( & V_23 -> V_32 ) )
goto V_31;
F_20 ( & V_23 -> V_32 ) ;
F_21 ( & V_23 -> V_32 ) ;
F_14 ( V_23 ) ;
F_22 ( & V_11 -> V_33 ) ;
V_31:
return;
}
void F_23 ( struct V_11 * V_11 ,
struct V_23 * V_23 )
{
struct V_7 * V_8 ;
struct V_23 * V_34 , * V_30 = NULL ;
T_3 V_35 = 0 ;
F_5 ( & V_11 -> V_29 ) ;
if ( ! F_24 ( V_11 -> V_26 ,
V_23 -> V_11 -> V_36 ) )
goto V_37;
V_30 = F_11 ( V_11 ) ;
if ( ! V_30 )
goto V_37;
if ( V_23 -> V_38 < V_30 -> V_38 - V_39 )
goto V_37;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( V_34 == V_23 )
continue;
if ( F_19 ( & V_34 -> V_32 ) )
continue;
if ( ( V_23 -> V_40 == V_34 -> V_40 ) ||
( F_24 ( V_23 -> V_27 , V_34 -> V_27 ) ) ) {
V_35 = 1 ;
break;
}
}
if ( V_35 )
goto V_37;
if ( ! F_19 ( & V_23 -> V_32 ) )
goto V_31;
if ( ! F_15 ( & V_23 -> V_28 ) )
goto V_31;
F_25 ( & V_23 -> V_32 , & V_11 -> V_41 ) ;
F_26 ( & V_11 -> V_33 ) ;
goto V_31;
V_37:
F_18 ( V_11 , V_23 ) ;
V_31:
F_8 ( & V_11 -> V_29 ) ;
if ( V_30 )
F_14 ( V_30 ) ;
}
void F_27 ( const struct V_11 * V_11 ,
struct V_11 * V_42 ,
const struct V_43 * V_43 )
{
if ( ! ( V_43 -> V_44 & V_45 ) )
return;
memcpy ( V_42 -> V_36 , V_11 -> V_26 , V_46 ) ;
}
int F_28 ( struct V_2 * V_2 , T_4 V_47 ,
unsigned long * V_48 )
{
if ( ( V_47 <= - V_22 ) ||
( V_47 >= V_49 ) ) {
if ( ! F_29 ( * V_48 , V_50 ) )
return 1 ;
* V_48 = V_51 ;
F_12 ( V_52 , V_2 ,
L_5 ) ;
}
return 0 ;
}
bool F_30 ( struct V_53 * V_54 ,
struct V_1 * V_1 ,
int V_55 )
{
struct V_56 * V_56 ;
if ( F_31 ( ! F_32 ( V_54 , V_55 ) ) )
return false ;
V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
if ( ! F_34 ( V_56 -> V_57 ) )
return false ;
if ( F_34 ( V_56 -> V_58 ) )
return false ;
if ( F_35 ( V_54 , 0 ) < 0 )
return false ;
if ( F_36 ( V_54 ) < 0 )
return false ;
return true ;
}
static int F_37 ( struct V_2 * V_2 ,
struct V_53 * V_54 , T_2 V_59 )
{
struct V_1 * V_60 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_23 * V_30 = NULL ;
struct V_61 * V_62 ;
int V_63 = V_64 ;
V_62 = (struct V_61 * ) V_54 -> V_65 ;
if ( V_62 -> V_66 != V_67 ) {
F_38 ( V_62 , V_59 ) ;
goto V_31;
}
V_60 = F_39 ( V_2 ) ;
if ( ! V_60 )
goto V_31;
V_11 = F_40 ( V_2 , V_62 -> V_26 ) ;
if ( ! V_11 )
goto V_31;
V_30 = F_11 ( V_11 ) ;
if ( ! V_30 )
goto V_31;
if ( F_35 ( V_54 , V_68 ) < 0 )
goto V_31;
V_62 = (struct V_61 * ) V_54 -> V_65 ;
memcpy ( V_62 -> V_69 , V_62 -> V_26 , V_46 ) ;
memcpy ( V_62 -> V_26 , V_60 -> V_70 -> V_71 , V_46 ) ;
V_62 -> V_66 = V_72 ;
V_62 -> V_73 . V_74 = V_75 ;
F_41 ( V_54 , V_30 -> V_40 , V_30 -> V_27 ) ;
V_63 = V_76 ;
V_31:
if ( V_60 )
F_42 ( V_60 ) ;
if ( V_30 )
F_14 ( V_30 ) ;
if ( V_11 )
F_43 ( V_11 ) ;
return V_63 ;
}
static int F_44 ( struct V_2 * V_2 ,
struct V_53 * V_54 )
{
struct V_1 * V_60 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_23 * V_30 = NULL ;
struct V_62 * V_62 ;
int V_63 = V_64 ;
V_62 = (struct V_62 * ) V_54 -> V_65 ;
if ( V_62 -> V_66 != V_67 ) {
F_45 ( L_6 ,
V_62 -> V_26 , V_62 -> V_69 ) ;
goto V_31;
}
V_60 = F_39 ( V_2 ) ;
if ( ! V_60 )
goto V_31;
V_11 = F_40 ( V_2 , V_62 -> V_26 ) ;
if ( ! V_11 )
goto V_31;
V_30 = F_11 ( V_11 ) ;
if ( ! V_30 )
goto V_31;
if ( F_35 ( V_54 , V_68 ) < 0 )
goto V_31;
V_62 = (struct V_62 * ) V_54 -> V_65 ;
memcpy ( V_62 -> V_69 , V_62 -> V_26 , V_46 ) ;
memcpy ( V_62 -> V_26 , V_60 -> V_70 -> V_71 , V_46 ) ;
V_62 -> V_66 = V_77 ;
V_62 -> V_73 . V_74 = V_75 ;
F_41 ( V_54 , V_30 -> V_40 , V_30 -> V_27 ) ;
V_63 = V_76 ;
V_31:
if ( V_60 )
F_42 ( V_60 ) ;
if ( V_30 )
F_14 ( V_30 ) ;
if ( V_11 )
F_43 ( V_11 ) ;
return V_63 ;
}
int F_46 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
struct V_61 * V_62 ;
struct V_56 * V_56 ;
struct V_11 * V_11 = NULL ;
struct V_23 * V_30 = NULL ;
int V_79 = sizeof( struct V_62 ) ;
int V_63 = V_64 ;
if ( V_54 -> V_80 >= sizeof( struct V_61 ) )
V_79 = sizeof( struct V_61 ) ;
if ( F_31 ( ! F_32 ( V_54 , V_79 ) ) )
goto V_31;
V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_56 -> V_57 ) )
goto V_31;
if ( F_34 ( V_56 -> V_58 ) )
goto V_31;
if ( ! F_47 ( V_56 -> V_57 ) )
goto V_31;
V_62 = (struct V_61 * ) V_54 -> V_65 ;
if ( ( V_79 == sizeof( struct V_61 ) ) &&
( V_62 -> V_81 < V_82 ) ) {
memcpy ( & ( V_62 -> V_83 [ V_62 -> V_81 ] ) ,
V_56 -> V_57 , V_46 ) ;
V_62 -> V_81 ++ ;
}
if ( F_47 ( V_62 -> V_69 ) )
return F_37 ( V_2 , V_54 , V_79 ) ;
if ( V_62 -> V_73 . V_74 < 2 )
return F_44 ( V_2 , V_54 ) ;
V_11 = F_40 ( V_2 , V_62 -> V_69 ) ;
if ( ! V_11 )
goto V_31;
V_30 = F_11 ( V_11 ) ;
if ( ! V_30 )
goto V_31;
if ( F_35 ( V_54 , V_68 ) < 0 )
goto V_31;
V_62 = (struct V_61 * ) V_54 -> V_65 ;
V_62 -> V_73 . V_74 -- ;
F_41 ( V_54 , V_30 -> V_40 , V_30 -> V_27 ) ;
V_63 = V_76 ;
V_31:
if ( V_30 )
F_14 ( V_30 ) ;
if ( V_11 )
F_43 ( V_11 ) ;
return V_63 ;
}
static struct V_23 * F_48 ( struct V_11 * V_84 ,
const struct V_1 * V_78 )
{
struct V_23 * V_34 ;
struct V_23 * V_30 = NULL , * V_85 = NULL ;
F_3 () ;
F_49 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_85 )
V_85 = V_34 ;
if ( V_34 -> V_40 == V_78 )
continue;
if ( ! F_15 ( & V_34 -> V_28 ) )
continue;
V_30 = V_34 ;
break;
}
if ( ! V_30 && V_85 &&
F_15 ( & V_85 -> V_28 ) )
V_30 = V_85 ;
if ( ! V_30 )
goto V_31;
F_5 ( & V_84 -> V_29 ) ;
F_20 ( & V_84 -> V_41 ) ;
F_25 ( & V_84 -> V_41 ,
& V_30 -> V_32 ) ;
F_8 ( & V_84 -> V_29 ) ;
V_31:
F_9 () ;
return V_30 ;
}
static struct V_23 * F_50 ( struct V_11 * V_84 ,
const struct V_1 * V_78 )
{
struct V_23 * V_34 ;
struct V_23 * V_30 = NULL , * V_85 = NULL ;
F_3 () ;
F_49 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_85 )
V_85 = V_34 ;
if ( V_34 -> V_40 == V_78 )
continue;
if ( ! F_15 ( & V_34 -> V_28 ) )
continue;
if ( ( ! V_30 ) ||
( V_34 -> V_38 > V_30 -> V_38 ) ) {
if ( V_30 )
F_14 ( V_30 ) ;
V_30 = V_34 ;
F_15 ( & V_30 -> V_28 ) ;
}
F_14 ( V_34 ) ;
}
if ( ! V_30 && V_85 &&
F_15 ( & V_85 -> V_28 ) )
V_30 = V_85 ;
F_9 () ;
return V_30 ;
}
int F_51 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
struct V_86 * V_87 ;
T_5 V_88 ;
struct V_56 * V_56 ;
if ( F_31 ( ! F_32 ( V_54 , sizeof( struct V_86 ) ) ) )
goto V_31;
if ( F_35 ( V_54 , sizeof( struct V_86 ) ) < 0 )
goto V_31;
V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_56 -> V_57 ) )
goto V_31;
if ( F_34 ( V_56 -> V_58 ) )
goto V_31;
V_87 = (struct V_86 * ) V_54 -> V_65 ;
V_87 -> V_89 = F_52 ( V_87 -> V_89 ) ;
switch ( V_87 -> V_44 & V_90 ) {
case V_91 :
if ( ! F_53 ( V_2 , V_87 ) ) {
F_12 ( V_92 , V_2 ,
L_7 ,
V_87 -> V_69 ,
( V_87 -> V_44 & V_93 ? 'F' : '.' ) ) ;
V_87 -> V_89 = F_54 ( V_87 -> V_89 ) ;
return F_55 ( V_54 , V_78 ) ;
}
break;
case V_94 :
if ( F_47 ( V_87 -> V_69 ) ) {
if ( F_36 ( V_54 ) < 0 )
goto V_31;
V_87 = (struct V_86 * ) V_54 -> V_65 ;
V_88 = V_87 -> V_89 * sizeof( struct V_95 ) ;
if ( F_31 ( F_56 ( V_54 ) <
sizeof( struct V_86 ) + V_88 ) )
goto V_31;
F_57 ( V_2 , V_87 ) ;
} else {
F_12 ( V_92 , V_2 ,
L_8 ,
V_87 -> V_69 ,
( V_87 -> V_44 & V_93 ? 'F' : '.' ) ) ;
V_87 -> V_89 = F_54 ( V_87 -> V_89 ) ;
return F_55 ( V_54 , V_78 ) ;
}
break;
}
V_31:
return V_64 ;
}
int F_58 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
struct V_96 * V_96 ;
struct V_11 * V_11 ;
struct V_56 * V_56 ;
if ( F_31 ( ! F_32 ( V_54 , sizeof( struct V_96 ) ) ) )
goto V_31;
V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_56 -> V_57 ) )
goto V_31;
if ( F_34 ( V_56 -> V_58 ) )
goto V_31;
V_96 = (struct V_96 * ) V_54 -> V_65 ;
if ( ! F_47 ( V_96 -> V_69 ) )
return F_55 ( V_54 , V_78 ) ;
if ( F_59 ( V_2 , V_96 -> V_97 ) )
goto V_31;
V_11 = F_40 ( V_2 , V_96 -> V_97 ) ;
if ( ! V_11 )
goto V_31;
F_12 ( V_92 , V_2 ,
L_9 ,
V_96 -> V_97 , V_96 -> V_98 ) ;
F_60 ( V_2 , V_11 , V_96 -> V_98 ,
F_61 ( & V_11 -> V_99 ) + 1 , true , false ) ;
V_2 -> V_100 = true ;
F_43 ( V_11 ) ;
V_31:
return V_64 ;
}
struct V_23 * F_62 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
const struct V_1 * V_78 )
{
struct V_11 * V_101 ;
struct V_11 * V_102 ;
struct V_23 * V_30 ;
static T_3 V_103 [ V_46 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_104 ;
if ( ! V_11 )
return NULL ;
V_30 = F_11 ( V_11 ) ;
if ( ! V_30 )
goto V_105;
V_104 = F_61 ( & V_2 -> V_106 ) ;
F_3 () ;
V_102 = V_30 -> V_11 ;
if ( ! V_102 )
goto V_107;
if ( ( ! V_78 ) && ( ! V_104 ) )
goto V_108;
if ( F_24 ( V_102 -> V_36 , V_103 ) )
goto V_108;
if ( F_24 ( V_102 -> V_36 , V_102 -> V_26 ) ) {
V_101 = V_102 ;
} else {
V_101 = F_40 ( V_2 ,
V_102 -> V_36 ) ;
if ( ! V_101 )
goto V_108;
F_43 ( V_101 ) ;
}
if ( F_61 ( & V_101 -> V_33 ) < 2 )
goto V_108;
F_14 ( V_30 ) ;
if ( V_104 )
V_30 = F_48 ( V_101 , V_78 ) ;
else
V_30 = F_50 ( V_101 , V_78 ) ;
V_108:
if ( V_30 && V_30 -> V_40 -> V_109 != V_110 )
goto V_107;
F_9 () ;
return V_30 ;
V_107:
F_9 () ;
V_105:
if ( V_30 )
F_14 ( V_30 ) ;
return NULL ;
}
static int F_63 ( struct V_53 * V_54 , int V_79 )
{
struct V_56 * V_56 ;
if ( F_31 ( ! F_32 ( V_54 , V_79 ) ) )
return - 1 ;
V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_56 -> V_57 ) )
return - 1 ;
if ( F_34 ( V_56 -> V_58 ) )
return - 1 ;
if ( ! F_47 ( V_56 -> V_57 ) )
return - 1 ;
return 0 ;
}
static int F_55 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_23 * V_23 = NULL ;
struct V_111 * V_111 ;
struct V_56 * V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
int V_63 = V_64 ;
struct V_53 * V_112 ;
V_111 = (struct V_111 * ) V_54 -> V_65 ;
if ( V_111 -> V_73 . V_74 < 2 ) {
F_45 ( L_10 ,
V_56 -> V_58 , V_111 -> V_113 ) ;
goto V_31;
}
V_11 = F_40 ( V_2 , V_111 -> V_113 ) ;
if ( ! V_11 )
goto V_31;
V_23 = F_62 ( V_2 , V_11 , V_78 ) ;
if ( ! V_23 )
goto V_31;
if ( F_35 ( V_54 , V_68 ) < 0 )
goto V_31;
V_111 = (struct V_111 * ) V_54 -> V_65 ;
if ( V_111 -> V_73 . V_114 == V_115 &&
F_61 ( & V_2 -> V_116 ) &&
V_54 -> V_80 > V_23 -> V_40 -> V_70 -> V_117 ) {
V_63 = F_64 ( V_54 , V_2 ,
V_23 -> V_40 , V_23 -> V_27 ) ;
goto V_31;
}
if ( V_111 -> V_73 . V_114 == V_118 &&
F_65 ( V_54 , V_23 -> V_40 -> V_70 -> V_117 ) ) {
V_63 = F_66 ( V_54 , V_2 , & V_112 ) ;
if ( V_63 == V_64 )
goto V_31;
if ( ! V_112 ) {
V_63 = V_76 ;
goto V_31;
}
V_54 = V_112 ;
V_111 = (struct V_111 * ) V_54 -> V_65 ;
}
V_111 -> V_73 . V_74 -- ;
F_41 ( V_54 , V_23 -> V_40 , V_23 -> V_27 ) ;
V_63 = V_76 ;
V_31:
if ( V_23 )
F_14 ( V_23 ) ;
if ( V_11 )
F_43 ( V_11 ) ;
return V_63 ;
}
static int F_67 ( struct V_2 * V_2 ,
struct V_53 * V_54 ) {
T_3 V_119 ;
struct V_11 * V_11 ;
struct V_56 * V_56 ;
struct V_1 * V_60 ;
struct V_111 * V_111 ;
bool V_100 ;
if ( F_35 ( V_54 , sizeof( struct V_111 ) ) < 0 )
return 0 ;
V_111 = (struct V_111 * ) V_54 -> V_65 ;
if ( F_47 ( V_111 -> V_113 ) ) {
V_100 = V_2 -> V_100 ;
V_119 = ( T_3 ) F_61 ( & V_2 -> V_120 ) ;
} else {
V_11 = F_40 ( V_2 , V_111 -> V_113 ) ;
if ( ! V_11 )
return 0 ;
V_119 = ( T_3 ) F_61 ( & V_11 -> V_99 ) ;
V_100 = V_11 -> V_100 ;
F_43 ( V_11 ) ;
}
if ( F_68 ( V_111 -> V_120 , V_119 ) || V_100 ) {
if ( F_32 ( V_54 , sizeof( struct V_111 ) +
V_68 ) < 0 )
return 0 ;
V_56 = (struct V_56 * ) ( V_54 -> V_65 +
sizeof( struct V_111 ) ) ;
if ( F_69 ( V_2 , V_56 -> V_57 ) )
return 1 ;
V_11 = F_70 ( V_2 , NULL , V_56 -> V_57 ) ;
if ( ! V_11 ) {
if ( ! F_71 ( V_2 , V_56 -> V_57 ) )
return 0 ;
V_60 = F_39 ( V_2 ) ;
if ( ! V_60 )
return 0 ;
memcpy ( V_111 -> V_113 ,
V_60 -> V_70 -> V_71 , V_46 ) ;
F_42 ( V_60 ) ;
} else {
memcpy ( V_111 -> V_113 , V_11 -> V_26 ,
V_46 ) ;
V_119 = ( T_3 )
F_61 ( & V_11 -> V_99 ) ;
F_43 ( V_11 ) ;
}
F_12 ( V_25 , V_2 ,
L_11 ,
V_111 -> V_120 , V_119 , V_56 -> V_57 ,
V_111 -> V_113 ) ;
V_111 -> V_120 = V_119 ;
}
return 1 ;
}
int F_72 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
struct V_111 * V_111 ;
int V_79 = sizeof( * V_111 ) ;
if ( F_63 ( V_54 , V_79 ) < 0 )
return V_64 ;
if ( ! F_67 ( V_2 , V_54 ) )
return V_64 ;
V_111 = (struct V_111 * ) V_54 -> V_65 ;
if ( F_47 ( V_111 -> V_113 ) ) {
F_73 ( V_78 -> V_3 , V_54 , V_78 , V_79 ) ;
return V_76 ;
}
return F_55 ( V_54 , V_78 ) ;
}
int F_74 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
struct V_121 * V_111 ;
int V_79 = sizeof( * V_111 ) ;
struct V_53 * V_112 = NULL ;
int V_63 ;
if ( F_63 ( V_54 , V_79 ) < 0 )
return V_64 ;
if ( ! F_67 ( V_2 , V_54 ) )
return V_64 ;
V_111 = (struct V_121 * ) V_54 -> V_65 ;
if ( F_47 ( V_111 -> V_113 ) ) {
V_63 = F_66 ( V_54 , V_2 , & V_112 ) ;
if ( V_63 == V_64 )
return V_64 ;
if ( ! V_112 )
return V_76 ;
F_73 ( V_78 -> V_3 , V_112 , V_78 ,
sizeof( struct V_111 ) ) ;
return V_76 ;
}
return F_55 ( V_54 , V_78 ) ;
}
int F_75 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_122 * V_122 ;
struct V_56 * V_56 ;
int V_79 = sizeof( * V_122 ) ;
int V_63 = V_64 ;
T_4 V_123 ;
if ( F_31 ( ! F_32 ( V_54 , V_79 ) ) )
goto V_31;
V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
if ( ! F_34 ( V_56 -> V_57 ) )
goto V_31;
if ( F_34 ( V_56 -> V_58 ) )
goto V_31;
if ( F_47 ( V_56 -> V_58 ) )
goto V_31;
V_122 = (struct V_122 * ) V_54 -> V_65 ;
if ( F_47 ( V_122 -> V_26 ) )
goto V_31;
if ( V_122 -> V_73 . V_74 < 2 )
goto V_31;
V_11 = F_40 ( V_2 , V_122 -> V_26 ) ;
if ( ! V_11 )
goto V_31;
F_5 ( & V_11 -> V_124 ) ;
if ( F_76 ( V_11 -> V_125 , V_11 -> V_126 ,
F_77 ( V_122 -> V_127 ) ) )
goto V_128;
V_123 = F_77 ( V_122 -> V_127 ) - V_11 -> V_126 ;
if ( F_28 ( V_2 , V_123 ,
& V_11 -> V_129 ) )
goto V_128;
if ( F_6 ( V_2 , V_11 -> V_125 , V_123 , 1 ) )
V_11 -> V_126 = F_77 ( V_122 -> V_127 ) ;
F_8 ( & V_11 -> V_124 ) ;
if ( F_78 ( V_2 , V_122 , V_79 ) )
goto V_31;
F_79 ( V_2 , V_54 , 1 ) ;
if ( F_80 ( V_54 , V_11 , V_79 ) )
goto V_31;
F_73 ( V_78 -> V_3 , V_54 , V_78 , V_79 ) ;
V_63 = V_76 ;
goto V_31;
V_128:
F_8 ( & V_11 -> V_124 ) ;
V_31:
if ( V_11 )
F_43 ( V_11 ) ;
return V_63 ;
}
int F_81 ( struct V_53 * V_54 , struct V_1 * V_78 )
{
struct V_130 * V_130 ;
struct V_56 * V_56 ;
struct V_2 * V_2 = F_2 ( V_78 -> V_3 ) ;
int V_79 = sizeof( * V_130 ) ;
if ( F_36 ( V_54 ) < 0 )
return V_64 ;
if ( F_31 ( ! F_32 ( V_54 , V_79 ) ) )
return V_64 ;
V_130 = (struct V_130 * ) V_54 -> V_65 ;
V_56 = (struct V_56 * ) F_33 ( V_54 ) ;
if ( ! F_47 ( V_56 -> V_57 ) )
return V_64 ;
if ( F_47 ( V_130 -> V_131 ) )
return V_64 ;
if ( F_47 ( V_130 -> V_132 ) )
return V_64 ;
switch ( V_130 -> V_133 ) {
case V_134 :
F_82 ( V_2 , V_130 ,
F_56 ( V_54 ) ) ;
break;
case V_135 :
F_83 ( V_2 , V_130 ,
F_56 ( V_54 ) ) ;
break;
default:
break;
}
return V_64 ;
}
