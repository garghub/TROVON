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
F_7 ( V_12 ) ;
F_8 ( & V_11 -> V_17 ) ;
}
F_9 () ;
}
}
static void F_10 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
struct V_22 * V_22 )
{
struct V_22 * V_23 ;
V_23 = F_11 ( V_11 ) ;
if ( ( V_23 ) && ( ! V_22 ) ) {
F_12 ( V_24 , V_2 , L_1 ,
V_11 -> V_25 ) ;
F_13 ( V_2 , V_11 ,
L_2 ) ;
} else if ( ( ! V_23 ) && ( V_22 ) ) {
F_12 ( V_24 , V_2 ,
L_3 ,
V_11 -> V_25 , V_22 -> V_26 ) ;
} else if ( V_22 && V_23 ) {
F_12 ( V_24 , V_2 ,
L_4 ,
V_11 -> V_25 , V_22 -> V_26 ,
V_23 -> V_26 ) ;
}
if ( V_23 )
F_14 ( V_23 ) ;
if ( V_22 && ! F_15 ( & V_22 -> V_27 ) )
V_22 = NULL ;
F_5 ( & V_11 -> V_28 ) ;
F_16 ( V_11 -> V_29 , V_22 ) ;
F_8 ( & V_11 -> V_28 ) ;
if ( V_23 )
F_14 ( V_23 ) ;
}
void F_17 ( struct V_2 * V_2 , struct V_11 * V_11 ,
struct V_22 * V_22 )
{
struct V_22 * V_29 = NULL ;
if ( ! V_11 )
goto V_30;
V_29 = F_11 ( V_11 ) ;
if ( V_29 != V_22 )
F_10 ( V_2 , V_11 , V_22 ) ;
V_30:
if ( V_29 )
F_14 ( V_29 ) ;
}
void F_18 ( struct V_11 * V_11 ,
struct V_22 * V_22 )
{
if ( F_19 ( & V_22 -> V_31 ) )
goto V_30;
F_20 ( & V_22 -> V_31 ) ;
F_21 ( & V_22 -> V_31 ) ;
F_14 ( V_22 ) ;
F_22 ( & V_11 -> V_32 ) ;
V_30:
return;
}
void F_23 ( struct V_11 * V_11 ,
struct V_22 * V_22 )
{
struct V_7 * V_8 ;
struct V_22 * V_33 , * V_29 = NULL ;
T_3 V_34 = 0 ;
F_5 ( & V_11 -> V_28 ) ;
if ( ! F_24 ( V_11 -> V_25 ,
V_22 -> V_11 -> V_35 ) )
goto V_36;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_36;
if ( V_22 -> V_37 < V_29 -> V_37 - V_38 )
goto V_36;
F_4 (tmp_neigh_node, node,
&orig_node->neigh_list, list) {
if ( V_33 == V_22 )
continue;
if ( F_19 ( & V_33 -> V_31 ) )
continue;
if ( ( V_22 -> V_39 == V_33 -> V_39 ) ||
( F_24 ( V_22 -> V_26 , V_33 -> V_26 ) ) ) {
V_34 = 1 ;
break;
}
}
if ( V_34 )
goto V_36;
if ( ! F_19 ( & V_22 -> V_31 ) )
goto V_30;
if ( ! F_15 ( & V_22 -> V_27 ) )
goto V_30;
F_25 ( & V_22 -> V_31 , & V_11 -> V_40 ) ;
F_26 ( & V_11 -> V_32 ) ;
goto V_30;
V_36:
F_18 ( V_11 , V_22 ) ;
V_30:
F_8 ( & V_11 -> V_28 ) ;
if ( V_29 )
F_14 ( V_29 ) ;
}
void F_27 ( const struct V_11 * V_11 ,
struct V_11 * V_41 ,
const struct V_42 * V_42 )
{
if ( ! ( V_42 -> V_43 & V_44 ) )
return;
memcpy ( V_41 -> V_35 , V_11 -> V_25 , V_45 ) ;
}
int F_28 ( struct V_2 * V_2 , T_4 V_46 ,
unsigned long * V_47 )
{
if ( ( V_46 <= - V_48 ) ||
( V_46 >= V_49 ) ) {
if ( F_29 ( * V_47 , V_50 ) ) {
* V_47 = V_51 ;
F_12 ( V_52 , V_2 ,
L_5 ) ;
return 0 ;
} else {
return 1 ;
}
}
return 0 ;
}
int F_30 ( struct V_53 * V_54 , struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 -> V_3 ) ;
struct V_55 * V_55 ;
if ( F_31 ( ! F_32 ( V_54 , V_56 ) ) )
return V_57 ;
V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
if ( ! F_34 ( V_55 -> V_58 ) )
return V_57 ;
if ( F_34 ( V_55 -> V_59 ) )
return V_57 ;
if ( F_35 ( V_54 , 0 ) < 0 )
return V_57 ;
if ( F_36 ( V_54 ) < 0 )
return V_57 ;
V_2 -> V_60 -> V_61 ( V_1 , V_54 ) ;
F_37 ( V_54 ) ;
return V_62 ;
}
static int F_38 ( struct V_2 * V_2 ,
struct V_53 * V_54 , T_2 V_63 )
{
struct V_1 * V_64 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_29 = NULL ;
struct V_65 * V_66 ;
int V_67 = V_57 ;
V_66 = (struct V_65 * ) V_54 -> V_68 ;
if ( V_66 -> V_69 != V_70 ) {
F_39 ( V_66 , V_63 ) ;
goto V_30;
}
V_64 = F_40 ( V_2 ) ;
if ( ! V_64 )
goto V_30;
V_11 = F_41 ( V_2 , V_66 -> V_25 ) ;
if ( ! V_11 )
goto V_30;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_30;
if ( F_35 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_66 = (struct V_65 * ) V_54 -> V_68 ;
memcpy ( V_66 -> V_71 , V_66 -> V_25 , V_45 ) ;
memcpy ( V_66 -> V_25 , V_64 -> V_72 -> V_73 , V_45 ) ;
V_66 -> V_69 = V_74 ;
V_66 -> V_75 . V_76 = V_77 ;
F_42 ( V_54 , V_29 -> V_39 , V_29 -> V_26 ) ;
V_67 = V_62 ;
V_30:
if ( V_64 )
F_43 ( V_64 ) ;
if ( V_29 )
F_14 ( V_29 ) ;
if ( V_11 )
F_44 ( V_11 ) ;
return V_67 ;
}
static int F_45 ( struct V_2 * V_2 ,
struct V_53 * V_54 )
{
struct V_1 * V_64 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_29 = NULL ;
struct V_66 * V_66 ;
int V_67 = V_57 ;
V_66 = (struct V_66 * ) V_54 -> V_68 ;
if ( V_66 -> V_69 != V_70 ) {
F_46 ( L_6 ,
V_66 -> V_25 , V_66 -> V_71 ) ;
goto V_30;
}
V_64 = F_40 ( V_2 ) ;
if ( ! V_64 )
goto V_30;
V_11 = F_41 ( V_2 , V_66 -> V_25 ) ;
if ( ! V_11 )
goto V_30;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_30;
if ( F_35 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_66 = (struct V_66 * ) V_54 -> V_68 ;
memcpy ( V_66 -> V_71 , V_66 -> V_25 , V_45 ) ;
memcpy ( V_66 -> V_25 , V_64 -> V_72 -> V_73 , V_45 ) ;
V_66 -> V_69 = V_78 ;
V_66 -> V_75 . V_76 = V_77 ;
F_42 ( V_54 , V_29 -> V_39 , V_29 -> V_26 ) ;
V_67 = V_62 ;
V_30:
if ( V_64 )
F_43 ( V_64 ) ;
if ( V_29 )
F_14 ( V_29 ) ;
if ( V_11 )
F_44 ( V_11 ) ;
return V_67 ;
}
int F_47 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
struct V_65 * V_66 ;
struct V_55 * V_55 ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_29 = NULL ;
int V_80 = sizeof( struct V_66 ) ;
int V_67 = V_57 ;
if ( V_54 -> V_81 >= sizeof( struct V_65 ) )
V_80 = sizeof( struct V_65 ) ;
if ( F_31 ( ! F_32 ( V_54 , V_80 ) ) )
goto V_30;
V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_55 -> V_58 ) )
goto V_30;
if ( F_34 ( V_55 -> V_59 ) )
goto V_30;
if ( ! F_48 ( V_55 -> V_58 ) )
goto V_30;
V_66 = (struct V_65 * ) V_54 -> V_68 ;
if ( ( V_80 == sizeof( struct V_65 ) ) &&
( V_66 -> V_82 < V_83 ) ) {
memcpy ( & ( V_66 -> V_84 [ V_66 -> V_82 ] ) ,
V_55 -> V_58 , V_45 ) ;
V_66 -> V_82 ++ ;
}
if ( F_48 ( V_66 -> V_71 ) )
return F_38 ( V_2 , V_54 , V_80 ) ;
if ( V_66 -> V_75 . V_76 < 2 )
return F_45 ( V_2 , V_54 ) ;
V_11 = F_41 ( V_2 , V_66 -> V_71 ) ;
if ( ! V_11 )
goto V_30;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_30;
if ( F_35 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_66 = (struct V_65 * ) V_54 -> V_68 ;
V_66 -> V_75 . V_76 -- ;
F_42 ( V_54 , V_29 -> V_39 , V_29 -> V_26 ) ;
V_67 = V_62 ;
V_30:
if ( V_29 )
F_14 ( V_29 ) ;
if ( V_11 )
F_44 ( V_11 ) ;
return V_67 ;
}
static struct V_22 * F_49 ( struct V_11 * V_85 ,
const struct V_1 * V_79 )
{
struct V_22 * V_33 ;
struct V_22 * V_29 = NULL , * V_86 = NULL ;
F_3 () ;
F_50 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_86 )
V_86 = V_33 ;
if ( V_33 -> V_39 == V_79 )
continue;
if ( ! F_15 ( & V_33 -> V_27 ) )
continue;
V_29 = V_33 ;
break;
}
if ( ! V_29 && V_86 &&
F_15 ( & V_86 -> V_27 ) )
V_29 = V_86 ;
if ( ! V_29 )
goto V_30;
F_5 ( & V_85 -> V_28 ) ;
F_20 ( & V_85 -> V_40 ) ;
F_25 ( & V_85 -> V_40 ,
& V_29 -> V_31 ) ;
F_8 ( & V_85 -> V_28 ) ;
V_30:
F_9 () ;
return V_29 ;
}
static struct V_22 * F_51 ( struct V_11 * V_85 ,
const struct V_1 * V_79 )
{
struct V_22 * V_33 ;
struct V_22 * V_29 = NULL , * V_86 = NULL ;
F_3 () ;
F_50 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_86 )
V_86 = V_33 ;
if ( V_33 -> V_39 == V_79 )
continue;
if ( ! F_15 ( & V_33 -> V_27 ) )
continue;
if ( ( ! V_29 ) ||
( V_33 -> V_37 > V_29 -> V_37 ) ) {
if ( V_29 )
F_14 ( V_29 ) ;
V_29 = V_33 ;
F_15 ( & V_29 -> V_27 ) ;
}
F_14 ( V_33 ) ;
}
if ( ! V_29 && V_86 &&
F_15 ( & V_86 -> V_27 ) )
V_29 = V_86 ;
F_9 () ;
return V_29 ;
}
int F_52 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
struct V_87 * V_88 ;
T_5 V_89 ;
struct V_55 * V_55 ;
if ( F_31 ( ! F_32 ( V_54 , sizeof( struct V_87 ) ) ) )
goto V_30;
if ( F_35 ( V_54 , sizeof( struct V_87 ) ) < 0 )
goto V_30;
V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_55 -> V_58 ) )
goto V_30;
if ( F_34 ( V_55 -> V_59 ) )
goto V_30;
V_88 = (struct V_87 * ) V_54 -> V_68 ;
V_88 -> V_90 = F_53 ( V_88 -> V_90 ) ;
switch ( V_88 -> V_43 & V_91 ) {
case V_92 :
if ( ! F_54 ( V_2 , V_88 ) ) {
F_12 ( V_93 , V_2 ,
L_7 ,
V_88 -> V_71 ,
( V_88 -> V_43 & V_94 ? 'F' : '.' ) ) ;
V_88 -> V_90 = F_55 ( V_88 -> V_90 ) ;
return F_56 ( V_54 , V_79 ) ;
}
break;
case V_95 :
if ( F_48 ( V_88 -> V_71 ) ) {
if ( F_36 ( V_54 ) < 0 )
goto V_30;
V_89 = V_88 -> V_90 * sizeof( struct V_96 ) ;
if ( F_31 ( F_57 ( V_54 ) <
sizeof( struct V_87 ) + V_89 ) )
goto V_30;
F_58 ( V_2 , V_88 ) ;
} else {
F_12 ( V_93 , V_2 ,
L_8 ,
V_88 -> V_71 ,
( V_88 -> V_43 & V_94 ? 'F' : '.' ) ) ;
V_88 -> V_90 = F_55 ( V_88 -> V_90 ) ;
return F_56 ( V_54 , V_79 ) ;
}
break;
}
V_30:
return V_57 ;
}
int F_59 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
struct V_97 * V_97 ;
struct V_11 * V_11 ;
struct V_55 * V_55 ;
if ( F_31 ( ! F_32 ( V_54 , sizeof( struct V_97 ) ) ) )
goto V_30;
V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_55 -> V_58 ) )
goto V_30;
if ( F_34 ( V_55 -> V_59 ) )
goto V_30;
V_97 = (struct V_97 * ) V_54 -> V_68 ;
if ( ! F_48 ( V_97 -> V_71 ) )
return F_56 ( V_54 , V_79 ) ;
V_11 = F_41 ( V_2 , V_97 -> V_98 ) ;
if ( ! V_11 )
goto V_30;
F_12 ( V_93 , V_2 ,
L_9 ,
V_97 -> V_98 , V_97 -> V_99 ) ;
F_60 ( V_2 , V_11 , V_97 -> V_99 ,
F_61 ( & V_11 -> V_100 ) + 1 , true , false ) ;
V_2 -> V_101 = true ;
F_44 ( V_11 ) ;
V_30:
return V_57 ;
}
struct V_22 * F_62 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
const struct V_1 * V_79 )
{
struct V_11 * V_102 ;
struct V_11 * V_103 ;
struct V_22 * V_29 ;
static T_3 V_104 [ V_45 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_105 ;
if ( ! V_11 )
return NULL ;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_106;
V_105 = F_61 ( & V_2 -> V_107 ) ;
F_3 () ;
V_103 = V_29 -> V_11 ;
if ( ! V_103 )
goto V_108;
if ( ( ! V_79 ) && ( ! V_105 ) )
goto V_109;
if ( F_24 ( V_103 -> V_35 , V_104 ) )
goto V_109;
if ( F_24 ( V_103 -> V_35 , V_103 -> V_25 ) ) {
V_102 = V_103 ;
} else {
V_102 = F_41 ( V_2 ,
V_103 -> V_35 ) ;
if ( ! V_102 )
goto V_109;
F_44 ( V_102 ) ;
}
if ( F_61 ( & V_102 -> V_32 ) < 2 )
goto V_109;
F_14 ( V_29 ) ;
if ( V_105 )
V_29 = F_49 ( V_102 , V_79 ) ;
else
V_29 = F_51 ( V_102 , V_79 ) ;
V_109:
if ( V_29 && V_29 -> V_39 -> V_110 != V_111 )
goto V_108;
F_9 () ;
return V_29 ;
V_108:
F_9 () ;
V_106:
if ( V_29 )
F_14 ( V_29 ) ;
return NULL ;
}
static int F_63 ( struct V_53 * V_54 , int V_80 )
{
struct V_55 * V_55 ;
if ( F_31 ( ! F_32 ( V_54 , V_80 ) ) )
return - 1 ;
V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
if ( F_34 ( V_55 -> V_58 ) )
return - 1 ;
if ( F_34 ( V_55 -> V_59 ) )
return - 1 ;
if ( ! F_48 ( V_55 -> V_58 ) )
return - 1 ;
return 0 ;
}
int F_56 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_22 = NULL ;
struct V_112 * V_112 ;
struct V_55 * V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
int V_67 = V_57 ;
struct V_53 * V_113 ;
V_112 = (struct V_112 * ) V_54 -> V_68 ;
if ( V_112 -> V_75 . V_76 < 2 ) {
F_46 ( L_10 ,
V_55 -> V_59 , V_112 -> V_114 ) ;
goto V_30;
}
V_11 = F_41 ( V_2 , V_112 -> V_114 ) ;
if ( ! V_11 )
goto V_30;
V_22 = F_62 ( V_2 , V_11 , V_79 ) ;
if ( ! V_22 )
goto V_30;
if ( F_35 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_112 = (struct V_112 * ) V_54 -> V_68 ;
if ( V_112 -> V_75 . V_115 == V_116 &&
F_61 ( & V_2 -> V_117 ) &&
V_54 -> V_81 > V_22 -> V_39 -> V_72 -> V_118 ) {
V_67 = F_64 ( V_54 , V_2 ,
V_22 -> V_39 , V_22 -> V_26 ) ;
goto V_30;
}
if ( V_112 -> V_75 . V_115 == V_119 &&
F_65 ( V_54 , V_22 -> V_39 -> V_72 -> V_118 ) ) {
V_67 = F_66 ( V_54 , V_2 , & V_113 ) ;
if ( V_67 == V_57 )
goto V_30;
if ( ! V_113 ) {
V_67 = V_62 ;
goto V_30;
}
V_54 = V_113 ;
V_112 = (struct V_112 * ) V_54 -> V_68 ;
}
V_112 -> V_75 . V_76 -- ;
F_42 ( V_54 , V_22 -> V_39 , V_22 -> V_26 ) ;
V_67 = V_62 ;
V_30:
if ( V_22 )
F_14 ( V_22 ) ;
if ( V_11 )
F_44 ( V_11 ) ;
return V_67 ;
}
static int F_67 ( struct V_2 * V_2 ,
struct V_53 * V_54 ) {
T_3 V_120 ;
struct V_11 * V_11 ;
struct V_55 * V_55 ;
struct V_1 * V_64 ;
struct V_112 * V_112 ;
bool V_101 ;
if ( F_35 ( V_54 , sizeof( struct V_112 ) ) < 0 )
return 0 ;
V_112 = (struct V_112 * ) V_54 -> V_68 ;
if ( F_48 ( V_112 -> V_114 ) ) {
V_101 = V_2 -> V_101 ;
V_120 = ( T_3 ) F_61 ( & V_2 -> V_121 ) ;
} else {
V_11 = F_41 ( V_2 , V_112 -> V_114 ) ;
if ( ! V_11 )
return 0 ;
V_120 = ( T_3 ) F_61 ( & V_11 -> V_100 ) ;
V_101 = V_11 -> V_101 ;
F_44 ( V_11 ) ;
}
if ( F_68 ( V_112 -> V_121 , V_120 ) || V_101 ) {
if ( F_36 ( V_54 ) < 0 )
return 0 ;
V_55 = (struct V_55 * ) ( V_54 -> V_68 +
sizeof( struct V_112 ) ) ;
V_11 = F_69 ( V_2 , NULL , V_55 -> V_58 ) ;
if ( ! V_11 ) {
if ( ! F_70 ( V_2 , V_55 -> V_58 ) )
return 0 ;
V_64 = F_40 ( V_2 ) ;
if ( ! V_64 )
return 0 ;
memcpy ( V_112 -> V_114 ,
V_64 -> V_72 -> V_73 , V_45 ) ;
F_43 ( V_64 ) ;
} else {
memcpy ( V_112 -> V_114 , V_11 -> V_25 ,
V_45 ) ;
V_120 = ( T_3 )
F_61 ( & V_11 -> V_100 ) ;
F_44 ( V_11 ) ;
}
F_12 ( V_24 , V_2 ,
L_11 ,
V_112 -> V_121 , V_120 , V_55 -> V_58 ,
V_112 -> V_114 ) ;
V_112 -> V_121 = V_120 ;
}
return 1 ;
}
int F_71 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
struct V_112 * V_112 ;
int V_80 = sizeof( * V_112 ) ;
if ( F_63 ( V_54 , V_80 ) < 0 )
return V_57 ;
if ( ! F_67 ( V_2 , V_54 ) )
return V_57 ;
V_112 = (struct V_112 * ) V_54 -> V_68 ;
if ( F_48 ( V_112 -> V_114 ) ) {
F_72 ( V_79 -> V_3 , V_54 , V_79 , V_80 ) ;
return V_62 ;
}
return F_56 ( V_54 , V_79 ) ;
}
int F_73 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
struct V_122 * V_112 ;
int V_80 = sizeof( * V_112 ) ;
struct V_53 * V_113 = NULL ;
int V_67 ;
if ( F_63 ( V_54 , V_80 ) < 0 )
return V_57 ;
if ( ! F_67 ( V_2 , V_54 ) )
return V_57 ;
V_112 = (struct V_122 * ) V_54 -> V_68 ;
if ( F_48 ( V_112 -> V_114 ) ) {
V_67 = F_66 ( V_54 , V_2 , & V_113 ) ;
if ( V_67 == V_57 )
return V_57 ;
if ( ! V_113 )
return V_62 ;
F_72 ( V_79 -> V_3 , V_113 , V_79 ,
sizeof( struct V_112 ) ) ;
return V_62 ;
}
return F_56 ( V_54 , V_79 ) ;
}
int F_74 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_123 * V_123 ;
struct V_55 * V_55 ;
int V_80 = sizeof( * V_123 ) ;
int V_67 = V_57 ;
T_4 V_124 ;
if ( F_31 ( ! F_32 ( V_54 , V_80 ) ) )
goto V_30;
V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
if ( ! F_34 ( V_55 -> V_58 ) )
goto V_30;
if ( F_34 ( V_55 -> V_59 ) )
goto V_30;
if ( F_48 ( V_55 -> V_59 ) )
goto V_30;
V_123 = (struct V_123 * ) V_54 -> V_68 ;
if ( F_48 ( V_123 -> V_25 ) )
goto V_30;
if ( V_123 -> V_75 . V_76 < 2 )
goto V_30;
V_11 = F_41 ( V_2 , V_123 -> V_25 ) ;
if ( ! V_11 )
goto V_30;
F_5 ( & V_11 -> V_125 ) ;
if ( F_75 ( V_11 -> V_126 , V_11 -> V_127 ,
F_76 ( V_123 -> V_128 ) ) )
goto V_129;
V_124 = F_76 ( V_123 -> V_128 ) - V_11 -> V_127 ;
if ( F_28 ( V_2 , V_124 ,
& V_11 -> V_130 ) )
goto V_129;
if ( F_6 ( V_2 , V_11 -> V_126 , V_124 , 1 ) )
V_11 -> V_127 = F_76 ( V_123 -> V_128 ) ;
F_8 ( & V_11 -> V_125 ) ;
F_77 ( V_2 , V_54 , 1 ) ;
F_72 ( V_79 -> V_3 , V_54 , V_79 , V_80 ) ;
V_67 = V_62 ;
goto V_30;
V_129:
F_8 ( & V_11 -> V_125 ) ;
V_30:
if ( V_11 )
F_44 ( V_11 ) ;
return V_67 ;
}
int F_78 ( struct V_53 * V_54 , struct V_1 * V_79 )
{
struct V_131 * V_131 ;
struct V_55 * V_55 ;
struct V_2 * V_2 = F_2 ( V_79 -> V_3 ) ;
int V_80 = sizeof( * V_131 ) ;
if ( F_36 ( V_54 ) < 0 )
return V_57 ;
if ( F_31 ( ! F_32 ( V_54 , V_80 ) ) )
return V_57 ;
V_131 = (struct V_131 * ) V_54 -> V_68 ;
V_55 = (struct V_55 * ) F_33 ( V_54 ) ;
if ( ! F_48 ( V_55 -> V_58 ) )
return V_57 ;
if ( F_48 ( V_131 -> V_132 ) )
return V_57 ;
if ( F_48 ( V_131 -> V_133 ) )
return V_57 ;
switch ( V_131 -> V_134 ) {
case V_135 :
F_79 ( V_2 , V_131 ,
F_57 ( V_54 ) ) ;
break;
case V_136 :
F_80 ( V_2 , V_131 ,
F_57 ( V_54 ) ) ;
break;
default:
break;
}
return V_57 ;
}
