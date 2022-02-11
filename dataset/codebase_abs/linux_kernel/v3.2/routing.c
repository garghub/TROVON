void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = F_2 ( V_1 -> V_3 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_11 ;
unsigned long * V_12 ;
int V_13 ;
T_1 V_14 ;
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
L_4
L_5 ,
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
T_2 V_34 = 0 ;
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
int F_28 ( struct V_2 * V_2 , T_3 V_46 ,
unsigned long * V_47 )
{
if ( ( V_46 <= - V_48 )
|| ( V_46 >= V_49 ) ) {
if ( F_29 ( V_50 , * V_47 +
F_30 ( V_51 ) ) ) {
* V_47 = V_50 ;
F_12 ( V_52 , V_2 ,
L_6 ) ;
return 0 ;
} else
return 1 ;
}
return 0 ;
}
int F_31 ( struct V_53 * V_54 , struct V_1 * V_1 )
{
struct V_55 * V_55 ;
if ( F_32 ( ! F_33 ( V_54 , V_56 ) ) )
return V_57 ;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
if ( ! F_35 ( V_55 -> V_58 ) )
return V_57 ;
if ( F_35 ( V_55 -> V_59 ) )
return V_57 ;
if ( F_36 ( V_54 , 0 ) < 0 )
return V_57 ;
if ( F_37 ( V_54 ) < 0 )
return V_57 ;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
F_38 ( V_55 , V_54 -> V_60 , F_39 ( V_54 ) , V_1 ) ;
F_40 ( V_54 ) ;
return V_61 ;
}
static int F_41 ( struct V_2 * V_2 ,
struct V_53 * V_54 , T_1 V_62 )
{
struct V_1 * V_63 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_29 = NULL ;
struct V_64 * V_65 ;
int V_66 = V_57 ;
V_65 = (struct V_64 * ) V_54 -> V_60 ;
if ( V_65 -> V_67 != V_68 ) {
F_42 ( V_65 , V_62 ) ;
goto V_30;
}
V_63 = F_43 ( V_2 ) ;
if ( ! V_63 )
goto V_30;
V_11 = F_44 ( V_2 , V_65 -> V_25 ) ;
if ( ! V_11 )
goto V_30;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_30;
if ( F_36 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_65 = (struct V_64 * ) V_54 -> V_60 ;
memcpy ( V_65 -> V_69 , V_65 -> V_25 , V_45 ) ;
memcpy ( V_65 -> V_25 , V_63 -> V_70 -> V_71 , V_45 ) ;
V_65 -> V_67 = V_72 ;
V_65 -> V_73 = V_74 ;
F_45 ( V_54 , V_29 -> V_39 , V_29 -> V_26 ) ;
V_66 = V_61 ;
V_30:
if ( V_63 )
F_46 ( V_63 ) ;
if ( V_29 )
F_14 ( V_29 ) ;
if ( V_11 )
F_47 ( V_11 ) ;
return V_66 ;
}
static int F_48 ( struct V_2 * V_2 ,
struct V_53 * V_54 )
{
struct V_1 * V_63 = NULL ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_29 = NULL ;
struct V_65 * V_65 ;
int V_66 = V_57 ;
V_65 = (struct V_65 * ) V_54 -> V_60 ;
if ( V_65 -> V_67 != V_68 ) {
F_49 ( L_7
L_8 , V_65 -> V_25 ,
V_65 -> V_69 ) ;
goto V_30;
}
V_63 = F_43 ( V_2 ) ;
if ( ! V_63 )
goto V_30;
V_11 = F_44 ( V_2 , V_65 -> V_25 ) ;
if ( ! V_11 )
goto V_30;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_30;
if ( F_36 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_65 = (struct V_65 * ) V_54 -> V_60 ;
memcpy ( V_65 -> V_69 , V_65 -> V_25 , V_45 ) ;
memcpy ( V_65 -> V_25 , V_63 -> V_70 -> V_71 , V_45 ) ;
V_65 -> V_67 = V_75 ;
V_65 -> V_73 = V_74 ;
F_45 ( V_54 , V_29 -> V_39 , V_29 -> V_26 ) ;
V_66 = V_61 ;
V_30:
if ( V_63 )
F_46 ( V_63 ) ;
if ( V_29 )
F_14 ( V_29 ) ;
if ( V_11 )
F_47 ( V_11 ) ;
return V_66 ;
}
int F_50 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
struct V_64 * V_65 ;
struct V_55 * V_55 ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_29 = NULL ;
int V_77 = sizeof( struct V_65 ) ;
int V_66 = V_57 ;
if ( V_54 -> V_78 >= sizeof( struct V_64 ) )
V_77 = sizeof( struct V_64 ) ;
if ( F_32 ( ! F_33 ( V_54 , V_77 ) ) )
goto V_30;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
if ( F_35 ( V_55 -> V_58 ) )
goto V_30;
if ( F_35 ( V_55 -> V_59 ) )
goto V_30;
if ( ! F_51 ( V_55 -> V_58 ) )
goto V_30;
V_65 = (struct V_64 * ) V_54 -> V_60 ;
if ( ( V_77 == sizeof( struct V_64 ) ) &&
( V_65 -> V_79 < V_80 ) ) {
memcpy ( & ( V_65 -> V_81 [ V_65 -> V_79 ] ) ,
V_55 -> V_58 , V_45 ) ;
V_65 -> V_79 ++ ;
}
if ( F_51 ( V_65 -> V_69 ) )
return F_41 ( V_2 , V_54 , V_77 ) ;
if ( V_65 -> V_73 < 2 )
return F_48 ( V_2 , V_54 ) ;
V_11 = F_44 ( V_2 , V_65 -> V_69 ) ;
if ( ! V_11 )
goto V_30;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_30;
if ( F_36 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_65 = (struct V_64 * ) V_54 -> V_60 ;
V_65 -> V_73 -- ;
F_45 ( V_54 , V_29 -> V_39 , V_29 -> V_26 ) ;
V_66 = V_61 ;
V_30:
if ( V_29 )
F_14 ( V_29 ) ;
if ( V_11 )
F_47 ( V_11 ) ;
return V_66 ;
}
static struct V_22 * F_52 ( struct V_11 * V_82 ,
const struct V_1 * V_76 )
{
struct V_22 * V_33 ;
struct V_22 * V_29 = NULL , * V_83 = NULL ;
F_3 () ;
F_53 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_83 )
V_83 = V_33 ;
if ( V_33 -> V_39 == V_76 )
continue;
if ( ! F_15 ( & V_33 -> V_27 ) )
continue;
V_29 = V_33 ;
break;
}
if ( ! V_29 && V_83 &&
F_15 ( & V_83 -> V_27 ) )
V_29 = V_83 ;
if ( ! V_29 )
goto V_30;
F_5 ( & V_82 -> V_28 ) ;
F_20 ( & V_82 -> V_40 ) ;
F_25 ( & V_82 -> V_40 ,
& V_29 -> V_31 ) ;
F_8 ( & V_82 -> V_28 ) ;
V_30:
F_9 () ;
return V_29 ;
}
static struct V_22 * F_54 ( struct V_11 * V_82 ,
const struct V_1 * V_76 )
{
struct V_22 * V_33 ;
struct V_22 * V_29 = NULL , * V_83 = NULL ;
F_3 () ;
F_53 (tmp_neigh_node, &primary_orig->bond_list,
bonding_list) {
if ( ! V_83 )
V_83 = V_33 ;
if ( V_33 -> V_39 == V_76 )
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
if ( ! V_29 && V_83 &&
F_15 ( & V_83 -> V_27 ) )
V_29 = V_83 ;
F_9 () ;
return V_29 ;
}
int F_55 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
struct V_84 * V_85 ;
struct V_55 * V_55 ;
if ( F_32 ( ! F_33 ( V_54 , sizeof( struct V_84 ) ) ) )
goto V_30;
if ( F_36 ( V_54 , sizeof( struct V_84 ) ) < 0 )
goto V_30;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
if ( F_35 ( V_55 -> V_58 ) )
goto V_30;
if ( F_35 ( V_55 -> V_59 ) )
goto V_30;
V_85 = (struct V_84 * ) V_54 -> V_60 ;
V_85 -> V_86 = F_56 ( V_85 -> V_86 ) ;
switch ( V_85 -> V_43 & V_87 ) {
case V_88 :
if ( ! F_57 ( V_2 , V_85 ) ) {
F_12 ( V_89 , V_2 ,
L_9 ,
V_85 -> V_69 ,
( V_85 -> V_43 & V_90 ? 'F' : '.' ) ) ;
V_85 -> V_86 = F_58 ( V_85 -> V_86 ) ;
return F_59 ( V_54 , V_76 ) ;
}
break;
case V_91 :
if ( F_37 ( V_54 ) < 0 )
goto V_30;
if ( F_51 ( V_85 -> V_69 ) )
F_60 ( V_2 , V_85 ) ;
else {
F_12 ( V_89 , V_2 ,
L_10 ,
V_85 -> V_69 ,
( V_85 -> V_43 & V_90 ? 'F' : '.' ) ) ;
V_85 -> V_86 = F_58 ( V_85 -> V_86 ) ;
return F_59 ( V_54 , V_76 ) ;
}
break;
}
V_30:
return V_57 ;
}
int F_61 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
struct V_92 * V_92 ;
struct V_11 * V_11 ;
struct V_55 * V_55 ;
if ( F_32 ( ! F_33 ( V_54 , sizeof( struct V_92 ) ) ) )
goto V_30;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
if ( F_35 ( V_55 -> V_58 ) )
goto V_30;
if ( F_35 ( V_55 -> V_59 ) )
goto V_30;
V_92 = (struct V_92 * ) V_54 -> V_60 ;
if ( ! F_51 ( V_92 -> V_69 ) )
return F_59 ( V_54 , V_76 ) ;
V_11 = F_44 ( V_2 , V_92 -> V_93 ) ;
if ( ! V_11 )
goto V_30;
F_12 ( V_89 , V_2 , L_11
L_12 , V_92 -> V_93 ,
V_92 -> V_94 ) ;
F_62 ( V_2 , V_11 , V_92 -> V_94 ,
F_63 ( & V_11 -> V_95 ) + 1 , true , false ) ;
V_2 -> V_96 = true ;
F_47 ( V_11 ) ;
V_30:
return V_57 ;
}
struct V_22 * F_64 ( struct V_2 * V_2 ,
struct V_11 * V_11 ,
const struct V_1 * V_76 )
{
struct V_11 * V_97 ;
struct V_11 * V_98 ;
struct V_22 * V_29 ;
static T_2 V_99 [ V_45 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
int V_100 ;
if ( ! V_11 )
return NULL ;
V_29 = F_11 ( V_11 ) ;
if ( ! V_29 )
goto V_101;
V_100 = F_63 ( & V_2 -> V_102 ) ;
F_3 () ;
V_98 = V_29 -> V_11 ;
if ( ! V_98 )
goto V_103;
if ( ( ! V_76 ) && ( ! V_100 ) )
goto V_104;
if ( F_24 ( V_98 -> V_35 , V_99 ) )
goto V_104;
if ( F_24 ( V_98 -> V_35 , V_98 -> V_25 ) ) {
V_97 = V_98 ;
} else {
V_97 = F_44 ( V_2 ,
V_98 -> V_35 ) ;
if ( ! V_97 )
goto V_104;
F_47 ( V_97 ) ;
}
if ( F_63 ( & V_97 -> V_32 ) < 2 )
goto V_104;
F_14 ( V_29 ) ;
if ( V_100 )
V_29 = F_52 ( V_97 , V_76 ) ;
else
V_29 = F_54 ( V_97 , V_76 ) ;
V_104:
if ( V_29 && V_29 -> V_39 -> V_105 != V_106 )
goto V_103;
F_9 () ;
return V_29 ;
V_103:
F_9 () ;
V_101:
if ( V_29 )
F_14 ( V_29 ) ;
return NULL ;
}
static int F_65 ( struct V_53 * V_54 , int V_77 )
{
struct V_55 * V_55 ;
if ( F_32 ( ! F_33 ( V_54 , V_77 ) ) )
return - 1 ;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
if ( F_35 ( V_55 -> V_58 ) )
return - 1 ;
if ( F_35 ( V_55 -> V_59 ) )
return - 1 ;
if ( ! F_51 ( V_55 -> V_58 ) )
return - 1 ;
return 0 ;
}
int F_59 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_22 * V_22 = NULL ;
struct V_107 * V_107 ;
struct V_55 * V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
int V_66 = V_57 ;
struct V_53 * V_108 ;
V_107 = (struct V_107 * ) V_54 -> V_60 ;
if ( V_107 -> V_73 < 2 ) {
F_49 ( L_13
L_8 , V_55 -> V_59 ,
V_107 -> V_109 ) ;
goto V_30;
}
V_11 = F_44 ( V_2 , V_107 -> V_109 ) ;
if ( ! V_11 )
goto V_30;
V_22 = F_64 ( V_2 , V_11 , V_76 ) ;
if ( ! V_22 )
goto V_30;
if ( F_36 ( V_54 , sizeof( struct V_55 ) ) < 0 )
goto V_30;
V_107 = (struct V_107 * ) V_54 -> V_60 ;
if ( V_107 -> V_110 == V_111 &&
F_63 ( & V_2 -> V_112 ) &&
V_54 -> V_78 > V_22 -> V_39 -> V_70 -> V_113 ) {
V_66 = F_66 ( V_54 , V_2 ,
V_22 -> V_39 , V_22 -> V_26 ) ;
goto V_30;
}
if ( V_107 -> V_110 == V_114 &&
F_67 ( V_54 , V_22 -> V_39 -> V_70 -> V_113 ) ) {
V_66 = F_68 ( V_54 , V_2 , & V_108 ) ;
if ( V_66 == V_57 )
goto V_30;
if ( ! V_108 ) {
V_66 = V_61 ;
goto V_30;
}
V_54 = V_108 ;
V_107 = (struct V_107 * ) V_54 -> V_60 ;
}
V_107 -> V_73 -- ;
F_45 ( V_54 , V_22 -> V_39 , V_22 -> V_26 ) ;
V_66 = V_61 ;
V_30:
if ( V_22 )
F_14 ( V_22 ) ;
if ( V_11 )
F_47 ( V_11 ) ;
return V_66 ;
}
static int F_69 ( struct V_2 * V_2 ,
struct V_53 * V_54 ) {
T_2 V_115 ;
struct V_11 * V_11 ;
struct V_55 * V_55 ;
struct V_1 * V_63 ;
struct V_107 * V_107 ;
bool V_96 ;
if ( F_36 ( V_54 , sizeof( struct V_107 ) ) < 0 )
return 0 ;
V_107 = (struct V_107 * ) V_54 -> V_60 ;
if ( F_51 ( V_107 -> V_109 ) ) {
V_96 = V_2 -> V_96 ;
V_115 = ( T_2 ) F_63 ( & V_2 -> V_116 ) ;
} else {
V_11 = F_44 ( V_2 , V_107 -> V_109 ) ;
if ( ! V_11 )
return 0 ;
V_115 = ( T_2 ) F_63 ( & V_11 -> V_95 ) ;
V_96 = V_11 -> V_96 ;
F_47 ( V_11 ) ;
}
if ( F_70 ( V_107 -> V_116 , V_115 ) || V_96 ) {
if ( F_37 ( V_54 ) < 0 )
return 0 ;
V_55 = (struct V_55 * ) ( V_54 -> V_60 +
sizeof( struct V_107 ) ) ;
V_11 = F_71 ( V_2 , NULL , V_55 -> V_58 ) ;
if ( ! V_11 ) {
if ( ! F_72 ( V_2 , V_55 -> V_58 ) )
return 0 ;
V_63 = F_43 ( V_2 ) ;
if ( ! V_63 )
return 0 ;
memcpy ( V_107 -> V_109 ,
V_63 -> V_70 -> V_71 , V_45 ) ;
F_46 ( V_63 ) ;
} else {
memcpy ( V_107 -> V_109 , V_11 -> V_25 ,
V_45 ) ;
V_115 = ( T_2 )
F_63 ( & V_11 -> V_95 ) ;
F_47 ( V_11 ) ;
}
F_12 ( V_24 , V_2 , L_14
L_15
L_16 , V_107 -> V_116 , V_115 ,
V_55 -> V_58 , V_107 -> V_109 ) ;
V_107 -> V_116 = V_115 ;
}
return 1 ;
}
int F_73 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
struct V_107 * V_107 ;
int V_77 = sizeof( * V_107 ) ;
if ( F_65 ( V_54 , V_77 ) < 0 )
return V_57 ;
if ( ! F_69 ( V_2 , V_54 ) )
return V_57 ;
V_107 = (struct V_107 * ) V_54 -> V_60 ;
if ( F_51 ( V_107 -> V_109 ) ) {
F_74 ( V_76 -> V_3 , V_54 , V_76 , V_77 ) ;
return V_61 ;
}
return F_59 ( V_54 , V_76 ) ;
}
int F_75 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
struct V_117 * V_107 ;
int V_77 = sizeof( * V_107 ) ;
struct V_53 * V_108 = NULL ;
int V_66 ;
if ( F_65 ( V_54 , V_77 ) < 0 )
return V_57 ;
if ( ! F_69 ( V_2 , V_54 ) )
return V_57 ;
V_107 = (struct V_117 * ) V_54 -> V_60 ;
if ( F_51 ( V_107 -> V_109 ) ) {
V_66 = F_68 ( V_54 , V_2 , & V_108 ) ;
if ( V_66 == V_57 )
return V_57 ;
if ( ! V_108 )
return V_61 ;
F_74 ( V_76 -> V_3 , V_108 , V_76 ,
sizeof( struct V_107 ) ) ;
return V_61 ;
}
return F_59 ( V_54 , V_76 ) ;
}
int F_76 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
struct V_11 * V_11 = NULL ;
struct V_118 * V_118 ;
struct V_55 * V_55 ;
int V_77 = sizeof( * V_118 ) ;
int V_66 = V_57 ;
T_3 V_119 ;
if ( F_32 ( ! F_33 ( V_54 , V_77 ) ) )
goto V_30;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
if ( ! F_35 ( V_55 -> V_58 ) )
goto V_30;
if ( F_35 ( V_55 -> V_59 ) )
goto V_30;
if ( F_51 ( V_55 -> V_59 ) )
goto V_30;
V_118 = (struct V_118 * ) V_54 -> V_60 ;
if ( F_51 ( V_118 -> V_25 ) )
goto V_30;
if ( V_118 -> V_73 < 2 )
goto V_30;
V_11 = F_44 ( V_2 , V_118 -> V_25 ) ;
if ( ! V_11 )
goto V_30;
F_5 ( & V_11 -> V_120 ) ;
if ( F_77 ( V_11 -> V_121 , V_11 -> V_122 ,
F_78 ( V_118 -> V_123 ) ) )
goto V_124;
V_119 = F_78 ( V_118 -> V_123 ) - V_11 -> V_122 ;
if ( F_28 ( V_2 , V_119 ,
& V_11 -> V_125 ) )
goto V_124;
if ( F_6 ( V_2 , V_11 -> V_121 , V_119 , 1 ) )
V_11 -> V_122 = F_78 ( V_118 -> V_123 ) ;
F_8 ( & V_11 -> V_120 ) ;
F_79 ( V_2 , V_54 , 1 ) ;
F_74 ( V_76 -> V_3 , V_54 , V_76 , V_77 ) ;
V_66 = V_61 ;
goto V_30;
V_124:
F_8 ( & V_11 -> V_120 ) ;
V_30:
if ( V_11 )
F_47 ( V_11 ) ;
return V_66 ;
}
int F_80 ( struct V_53 * V_54 , struct V_1 * V_76 )
{
struct V_126 * V_126 ;
struct V_55 * V_55 ;
struct V_2 * V_2 = F_2 ( V_76 -> V_3 ) ;
int V_77 = sizeof( * V_126 ) ;
if ( F_37 ( V_54 ) < 0 )
return V_57 ;
if ( F_32 ( ! F_33 ( V_54 , V_77 ) ) )
return V_57 ;
V_126 = (struct V_126 * ) V_54 -> V_60 ;
V_55 = (struct V_55 * ) F_34 ( V_54 ) ;
if ( ! F_51 ( V_55 -> V_58 ) )
return V_57 ;
if ( F_51 ( V_126 -> V_127 ) )
return V_57 ;
if ( F_51 ( V_126 -> V_128 ) )
return V_57 ;
switch ( V_126 -> V_129 ) {
case V_130 :
F_81 ( V_2 , V_126 ,
F_39 ( V_54 ) ) ;
break;
case V_131 :
F_82 ( V_2 , V_126 ,
F_39 ( V_54 ) ) ;
break;
default:
break;
}
return V_57 ;
}
