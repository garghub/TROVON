static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 , 0 ) ;
F_2 ( & V_2 -> V_5 , 0 ) ;
F_2 ( & V_2 -> V_6 , 0 ) ;
V_2 -> V_7 = NULL ;
F_3 ( & V_2 -> V_8 ) ;
F_2 ( & V_2 -> V_9 , 1 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 , * V_14 ;
F_7 ( V_2 ) ;
F_8 (pos, n, &set->set_list) {
struct V_15 * V_16 = F_9 ( V_13 ,
struct V_15 ,
V_17 ) ;
F_10 ( & V_16 -> V_17 ) ;
if ( V_16 -> V_18 . V_19 )
F_11 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_20 )
F_12 ( V_16 -> V_18 . V_20 , V_16 -> V_21 ) ;
if ( V_16 -> V_18 . V_22 )
F_13 ( V_16 -> V_18 . V_22 ,
sizeof( * V_16 -> V_18 . V_22 ) ) ;
F_13 ( V_16 , sizeof( * V_16 ) ) ;
}
if ( V_2 -> V_23 ) {
int V_24 = V_2 -> V_25 * sizeof( * V_2 -> V_23 ) ;
F_12 ( V_2 -> V_23 , V_24 ) ;
}
if ( V_2 -> V_26 )
F_14 ( V_2 -> V_26 ) ;
F_13 ( V_2 , sizeof( * V_2 ) ) ;
}
int F_15 ( struct V_1 * V_2 , int V_27 )
{
int V_28 = F_16 ( & V_2 -> V_4 ) ;
F_17 ( V_29 , L_1 , V_28 , V_2 -> V_3 ) ;
if ( V_28 == V_2 -> V_3 ) {
if ( V_27 )
return 1 ;
if ( F_18 ( & V_2 -> V_6 ) == 1 )
return 1 ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_30 )
{
V_16 -> V_31 = 1 ;
V_16 -> V_32 = V_30 ;
F_20 ( & V_2 -> V_4 ) ;
if ( V_30 == 0 )
F_20 ( & V_2 -> V_5 ) ;
F_21 ( & V_2 -> V_10 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_30 )
{
struct V_33 * V_34 = & V_2 -> V_35 -> V_36 -> V_37 . V_34 ;
F_19 ( V_2 , V_16 , V_30 ) ;
if ( V_30 && ! ( V_34 -> V_38 [ V_16 -> V_39 ] &&
V_34 -> V_38 [ V_16 -> V_39 ] -> V_40 ) )
V_30 = 0 ;
return V_30 ;
}
void F_23 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
F_24 ( & V_16 -> V_17 , & V_2 -> V_8 ) ;
V_2 -> V_3 ++ ;
V_16 -> V_41 = V_2 ;
}
static int F_25 ( struct V_33 * V_34 , int V_42 )
{
int V_30 ;
struct V_43 * V_44 ;
F_26 ( & V_34 -> V_45 ) ;
V_44 = V_34 -> V_38 [ V_42 ] ;
V_30 = ! V_44 || V_44 -> V_40 ||
( V_44 -> V_46 &&
F_27 ( V_44 -> V_46 ) -> V_47 ) ;
F_28 ( & V_34 -> V_45 ) ;
return V_30 ;
}
int F_29 ( struct V_33 * V_34 , int V_48 )
{
T_1 V_49 ;
struct V_50 V_51 ;
struct V_43 * V_44 ;
int V_30 = 0 ;
F_26 ( & V_34 -> V_45 ) ;
V_44 = V_34 -> V_38 [ V_48 ] ;
if ( F_30 ( V_44 == NULL ) )
GOTO ( V_52 , V_30 = 0 ) ;
if ( F_31 ( V_44 -> V_40 ) )
GOTO ( V_52 , V_30 = 1 ) ;
if ( V_44 -> V_46 && F_27 ( V_44 -> V_46 ) -> V_47 )
GOTO ( V_52 , V_30 = 0 ) ;
F_28 ( & V_34 -> V_45 ) ;
F_4 ( & V_49 ) ;
V_51 = F_32 ( F_33 ( V_53 ) ,
F_33 ( 1 ) , NULL , NULL ) ;
V_30 = F_34 ( V_49 , F_25 ( V_34 , V_48 ) , & V_51 ) ;
if ( V_44 != NULL && V_44 -> V_40 )
return 1 ;
return 0 ;
V_52:
F_28 ( & V_34 -> V_45 ) ;
return V_30 ;
}
static int F_35 ( struct V_54 * exp ,
struct V_55 * V_56 ,
struct V_57 * V_58 , T_2 V_59 , int V_42 ,
struct V_60 * V_61 , int V_30 )
{
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
if ( V_30 != V_62 &&
! ( V_30 == V_63 && ( V_59 & V_64 ) ) ) {
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
if ( V_34 -> V_38 [ V_42 ] && V_34 -> V_38 [ V_42 ] -> V_40 ) {
if ( V_30 != - V_65 && V_30 != - V_66 )
F_36 ( L_2 V_67 L_3
V_67 L_4 ,
exp -> V_36 -> V_68 ,
F_37 ( V_61 ) , F_37 ( & V_58 -> V_69 ) ,
V_58 -> V_70 , V_30 ) ;
} else
V_30 = V_62 ;
}
return V_30 ;
}
int F_38 ( struct V_15 * V_16 , T_3 V_71 , int V_30 )
{
struct V_1 * V_2 = V_16 -> V_41 ;
struct V_55 * V_56 ;
struct V_72 * V_61 = V_2 -> V_73 ;
struct V_57 * V_58 ;
F_7 ( V_61 != NULL ) ;
V_56 = V_2 -> V_26 -> V_74 + V_16 -> V_75 ;
V_58 = V_61 -> V_20 -> V_76 [ V_16 -> V_75 ] ;
F_39 ( V_61 -> V_20 ) ;
F_40 ( V_56 , V_58 , V_61 -> V_77 ,
& V_16 -> V_18 . V_20 -> V_76 [ 0 ] -> V_78 , V_71 , V_30 ) ;
if ( V_30 == V_63 && ( V_61 -> V_77 & V_64 ) )
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
V_30 = F_35 ( V_2 -> V_35 , V_56 , V_58 , V_61 -> V_77 ,
V_16 -> V_39 , & V_61 -> V_20 -> V_79 , V_30 ) ;
F_41 ( V_61 -> V_20 ) ;
F_19 ( V_2 , V_16 , V_30 ) ;
return V_30 ;
}
static int F_42 ( void * V_80 , int V_30 )
{
struct V_72 * V_81 = V_80 ;
struct V_82 * V_83 ;
struct V_15 * V_84 ;
V_84 = F_43 ( V_81 , struct V_15 , V_18 ) ;
V_83 = V_84 -> V_41 -> V_85 ;
return F_38 ( V_84 , V_83 -> V_86 , V_30 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_3 V_71 )
{
struct V_15 * V_16 ;
struct V_33 * V_34 = & V_2 -> V_35 -> V_36 -> V_37 . V_34 ;
int V_28 = F_16 ( & V_2 -> V_4 ) ;
int V_30 = 0 ;
if ( V_28 && V_28 == F_16 ( & V_2 -> V_5 ) )
return 0 ;
F_45 (req, &set->set_list, rq_link) {
struct V_55 * V_56 ;
if ( ! V_16 -> V_31 || V_16 -> V_32 )
continue;
V_56 = V_2 -> V_26 -> V_74 + V_16 -> V_75 ;
F_7 ( V_56 ) ;
if ( ! F_46 ( V_56 ) )
continue;
V_30 = F_47 ( V_34 -> V_38 [ V_16 -> V_39 ] -> V_46 ,
V_16 -> V_18 . V_20 , V_71 , V_56 ) ;
if ( V_30 && V_34 -> V_38 [ V_16 -> V_39 ] &&
V_34 -> V_38 [ V_16 -> V_39 ] -> V_40 )
F_36 ( L_5 V_67 L_6
L_7 ,
V_2 -> V_35 -> V_36 -> V_68 ,
F_37 ( & V_16 -> V_18 . V_20 -> V_79 ) ,
V_16 -> V_39 , V_30 ) ;
}
if ( V_2 -> V_26 )
F_14 ( V_2 -> V_26 ) ;
return V_30 ;
}
int F_48 ( struct V_1 * V_2 , T_3 V_71 , int V_30 ,
struct V_87 * V_88 )
{
int V_89 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( ! V_88 ) {
if ( V_30 )
F_2 ( & V_2 -> V_4 , 0 ) ;
V_89 = F_44 ( V_2 , V_71 ) ;
} else if ( V_2 -> V_26 )
F_14 ( V_2 -> V_26 ) ;
F_49 ( V_2 ) ;
return V_30 ? V_30 : V_89 ;
}
static void F_50 ( void * V_90 )
{
struct V_91 * V_92 = V_90 ;
F_20 ( & V_92 -> V_93 ) ;
F_17 ( V_29 , L_8 , V_92 ,
F_16 ( & V_92 -> V_93 ) ) ;
}
static struct V_91 * F_51 ( struct V_94 * V_95 )
{
struct V_91 * V_92 ;
F_52 ( V_92 , sizeof( * V_92 ) +
sizeof( * V_92 -> V_74 ) * V_95 -> V_96 ) ;
if ( V_92 == NULL )
return NULL ;
F_2 ( & V_92 -> V_93 , 2 ) ;
V_92 -> V_97 = V_95 -> V_96 ;
F_3 ( & V_92 -> V_98 . V_99 ) ;
F_53 ( & V_92 -> V_98 , & V_100 ) ;
return V_92 ;
}
int F_54 ( struct V_54 * exp , struct V_72 * V_81 ,
struct V_82 * V_83 ,
struct V_1 * * V_101 )
{
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
struct V_1 * V_2 ;
int V_102 , V_30 = 0 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_73 = V_81 ;
V_2 -> V_85 = V_83 ;
V_2 -> V_26 = F_51 ( V_81 -> V_20 ) ;
if ( V_2 -> V_26 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_81 -> V_105 -> V_80 = V_2 -> V_26 -> V_98 . V_106 ;
for ( V_102 = 0 ; V_102 < V_81 -> V_20 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 ;
struct V_15 * V_16 ;
T_4 V_107 , V_108 ;
V_58 = V_81 -> V_20 -> V_76 [ V_102 ] ;
if ( ! F_55 ( V_81 -> V_20 , V_102 ,
V_81 -> V_109 . V_110 . V_107 ,
V_81 -> V_109 . V_110 . V_108 ,
& V_107 , & V_108 ) )
continue;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
continue;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_21 = sizeof( * V_16 -> V_18 . V_20 ) +
sizeof( struct V_57 * ) +
sizeof( struct V_57 ) ;
F_56 ( V_16 -> V_18 . V_20 , V_16 -> V_21 ) ;
if ( V_16 -> V_18 . V_20 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
V_16 -> V_18 . V_20 -> V_76 [ 0 ] =
( ( void * ) V_16 -> V_18 . V_20 ) + sizeof( * V_16 -> V_18 . V_20 ) +
sizeof( struct V_57 * ) ;
V_16 -> V_18 . V_105 = V_2 -> V_26 -> V_74 + V_102 ;
V_16 -> V_18 . V_112 = F_42 ;
V_16 -> V_18 . V_77 = V_81 -> V_77 ;
F_7 ( V_16 -> V_18 . V_105 ) ;
V_16 -> V_18 . V_109 . V_110 . V_113 =
V_81 -> V_109 . V_110 . V_113 ;
V_16 -> V_18 . V_109 . V_110 . V_107 = V_107 ;
V_16 -> V_18 . V_109 . V_110 . V_108 = V_108 ;
V_16 -> V_39 = V_58 -> V_70 ;
V_16 -> V_75 = V_102 ;
V_16 -> V_18 . V_20 -> V_79 = V_58 -> V_69 ;
V_16 -> V_18 . V_20 -> V_96 = 0 ;
V_16 -> V_18 . V_20 -> V_76 [ 0 ] -> V_114 =
V_58 -> V_114 ;
V_16 -> V_18 . V_20 -> V_76 [ 0 ] -> V_115 = V_58 -> V_115 ;
V_16 -> V_18 . V_20 -> V_76 [ 0 ] -> V_78 = V_58 -> V_78 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return 0 ;
V_104:
F_48 ( V_2 , V_83 -> V_86 , V_30 , NULL ) ;
return V_30 ;
}
int F_57 ( struct V_1 * V_2 , T_3 V_71 , T_2 V_59 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
V_30 = F_44 ( V_2 , V_71 ) ;
if ( ( V_2 -> V_3 == F_16 ( & V_2 -> V_5 ) ) &&
( V_59 & V_117 ) )
F_14 ( V_2 -> V_26 ) ;
F_49 ( V_2 ) ;
return V_30 ;
}
int F_58 ( struct V_54 * exp , struct V_72 * V_81 ,
struct V_94 * V_95 , T_5 * V_118 ,
T_3 V_71 , struct V_55 * V_119 ,
struct V_1 * * V_101 )
{
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
struct V_1 * V_2 ;
int V_102 , V_30 = 0 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_73 = V_81 ;
V_2 -> V_73 -> V_20 = V_95 ;
V_2 -> V_26 = F_51 ( V_95 ) ;
if ( V_2 -> V_26 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_119 -> V_80 = V_2 -> V_26 -> V_98 . V_106 ;
for ( V_102 = 0 ; V_102 < V_95 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 ;
struct V_15 * V_16 ;
T_4 V_107 , V_108 ;
V_58 = V_95 -> V_76 [ V_102 ] ;
if ( ! F_55 ( V_95 , V_102 , V_118 -> V_110 . V_107 ,
V_118 -> V_110 . V_108 , & V_107 , & V_108 ) )
continue;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
GOTO ( V_104 , V_30 = - V_116 ) ;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_21 = sizeof( * V_16 -> V_18 . V_20 ) ;
F_56 ( V_16 -> V_18 . V_20 , V_16 -> V_21 ) ;
if ( V_16 -> V_18 . V_20 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
V_16 -> V_18 . V_109 . V_110 . V_107 = V_107 ;
V_16 -> V_18 . V_109 . V_110 . V_108 = V_108 ;
V_16 -> V_18 . V_109 . V_110 . V_113 = V_118 -> V_110 . V_113 ;
V_16 -> V_39 = V_58 -> V_70 ;
V_16 -> V_75 = V_102 ;
V_16 -> V_18 . V_20 -> V_79 = V_58 -> V_69 ;
V_16 -> V_18 . V_20 -> V_96 = 0 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_57 ( V_2 , V_71 , 0 ) ;
return V_30 ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( V_2 -> V_26 )
F_14 ( V_2 -> V_26 ) ;
F_49 ( V_2 ) ;
return V_30 ;
}
int F_60 ( struct V_54 * exp , struct V_72 * V_81 ,
struct V_94 * V_95 , T_3 V_71 ,
struct V_55 * V_119 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
int V_102 , V_30 = 0 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_73 = V_81 ;
V_2 -> V_73 -> V_20 = V_95 ;
V_2 -> V_26 = F_61 ( V_119 ) ;
if ( V_2 -> V_26 == NULL ) {
F_36 ( L_10 , V_119 ) ;
GOTO ( V_104 , V_30 = - V_120 ) ;
}
V_119 -> V_80 = V_2 -> V_26 -> V_98 . V_106 ;
for ( V_102 = 0 ; V_102 < V_95 -> V_96 ; V_102 ++ ) {
struct V_15 * V_16 ;
struct V_55 * V_56 ;
struct V_57 * V_58 = V_95 -> V_76 [ V_102 ] ;
V_56 = V_2 -> V_26 -> V_74 + V_102 ;
if ( ! F_46 ( V_56 ) ) {
F_17 ( V_29 , L_11 V_67 L_12 ,
V_58 -> V_70 , F_37 ( & V_58 -> V_69 ) ) ;
continue;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_21 = sizeof( * V_16 -> V_18 . V_20 ) ;
F_56 ( V_16 -> V_18 . V_20 , V_16 -> V_21 ) ;
if ( V_16 -> V_18 . V_20 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
V_16 -> V_39 = V_58 -> V_70 ;
V_16 -> V_75 = V_102 ;
V_16 -> V_18 . V_20 -> V_79 = V_58 -> V_69 ;
V_16 -> V_18 . V_20 -> V_96 = 0 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_59 ( V_2 ) ;
return V_30 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_15 * V_16 ;
struct V_121 * V_122 ;
int V_30 = 0 , V_123 = 0 ;
F_7 ( V_2 -> V_73 != NULL ) ;
if ( V_2 -> V_73 -> V_19 == NULL )
return 0 ;
if ( ! F_16 ( & V_2 -> V_5 ) )
return - V_116 ;
F_63 ( V_122 ) ;
if ( V_122 == NULL )
GOTO ( V_52 , V_30 = - V_103 ) ;
F_64 (pos, &set->set_list) {
V_16 = F_9 ( V_13 , struct V_15 , V_17 ) ;
if ( ! V_16 -> V_31 || V_16 -> V_32 )
continue;
if ( V_16 -> V_18 . V_19 -> V_124 == 0 )
continue;
F_65 ( V_122 , V_16 -> V_18 . V_19 ,
V_16 -> V_18 . V_19 -> V_124 ,
V_2 -> V_73 -> V_20 , V_16 -> V_75 , & V_123 ) ;
}
if ( ! V_123 ) {
F_36 ( L_13 ) ;
V_30 = - V_116 ;
}
if ( ( V_2 -> V_73 -> V_19 -> V_124 & V_125 ) &&
( V_2 -> V_73 -> V_20 -> V_96 != V_123 ) ) {
F_36 ( L_14 ) ;
GOTO ( V_52 , V_30 = - V_116 ) ;
}
V_122 -> V_126 = V_2 -> V_73 -> V_19 -> V_126 ;
memcpy ( V_2 -> V_73 -> V_19 , V_122 , sizeof( * V_2 -> V_73 -> V_19 ) ) ;
V_52:
if ( V_122 )
F_11 ( V_122 ) ;
return V_30 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_94 * V_95 = V_2 -> V_73 -> V_20 ;
struct V_57 * V_58 = NULL ;
struct V_12 * V_13 ;
struct V_15 * V_16 ;
F_64 (pos, &set->set_list) {
V_16 = F_9 ( V_13 , struct V_15 , V_17 ) ;
if ( ! V_16 -> V_31 || V_16 -> V_32 )
continue;
V_58 = V_95 -> V_76 [ V_16 -> V_75 ] ;
if ( V_16 -> V_18 . V_19 -> V_124 & V_127 )
V_58 -> V_78 . V_128 = V_16 -> V_18 . V_19 -> V_129 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_30 = F_66 ( V_2 ) ;
}
F_49 ( V_2 ) ;
return V_30 ;
}
int F_68 ( struct V_54 * exp , struct V_72 * V_81 ,
T_6 V_130 , struct V_131 * V_132 ,
struct V_133 * V_134 ,
struct V_1 * * V_101 )
{
struct {
T_6 V_135 ;
T_6 V_136 ;
T_6 V_137 ;
} * V_138 = NULL ;
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_102 , V_139 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_140 = V_134 ;
V_2 -> V_73 = V_81 ;
V_2 -> V_25 = V_130 ;
F_56 ( V_2 -> V_23 , V_130 * sizeof( * V_2 -> V_23 ) ) ;
if ( ! V_2 -> V_23 )
GOTO ( V_52 , V_30 = - V_103 ) ;
F_56 ( V_138 , sizeof( * V_138 ) * V_81 -> V_20 -> V_96 ) ;
if ( ! V_138 )
GOTO ( V_52 , V_30 = - V_103 ) ;
for ( V_102 = 0 ; V_102 < V_130 ; V_102 ++ ) {
int V_141 = F_69 ( V_81 -> V_20 , V_132 [ V_102 ] . V_137 ) ;
V_138 [ V_141 ] . V_136 ++ ;
}
V_139 = 0 ;
for ( V_102 = 0 ; V_102 < V_81 -> V_20 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 = NULL ;
struct V_15 * V_16 ;
if ( V_138 [ V_102 ] . V_136 == 0 )
continue;
V_58 = V_81 -> V_20 -> V_76 [ V_102 ] ;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
GOTO ( V_52 , V_30 = - V_116 ) ;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_52 , V_30 = - V_103 ) ;
F_63 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_52 , V_30 = - V_103 ) ;
}
if ( V_81 -> V_19 ) {
memcpy ( V_16 -> V_18 . V_19 , V_81 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
}
V_16 -> V_18 . V_19 -> V_126 = V_58 -> V_69 ;
V_16 -> V_18 . V_19 -> V_142 = V_102 ;
V_16 -> V_21 = sizeof( * V_16 -> V_18 . V_20 ) ;
F_56 ( V_16 -> V_18 . V_20 , V_16 -> V_21 ) ;
if ( V_16 -> V_18 . V_20 == NULL ) {
F_11 ( V_16 -> V_18 . V_19 ) ;
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_52 , V_30 = - V_103 ) ;
}
V_16 -> V_39 = V_58 -> V_70 ;
V_16 -> V_75 = V_102 ;
V_16 -> V_18 . V_20 -> V_79 = V_58 -> V_69 ;
V_16 -> V_143 = V_138 [ V_102 ] . V_136 ;
V_16 -> V_144 = V_139 ;
V_139 += V_16 -> V_143 ;
V_138 [ V_102 ] . V_135 = V_16 -> V_144 ;
V_16 -> V_18 . V_145 = V_81 -> V_145 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_52 , V_30 = - V_116 ) ;
for ( V_102 = 0 ; V_102 < V_130 ; V_102 ++ ) {
int V_141 = F_69 ( V_81 -> V_20 , V_132 [ V_102 ] . V_137 ) ;
V_139 = V_138 [ V_141 ] . V_135 + V_138 [ V_141 ] . V_137 ;
F_7 ( V_139 < V_130 ) ;
V_2 -> V_23 [ V_139 ] = V_132 [ V_102 ] ;
F_70 ( V_81 -> V_20 , V_132 [ V_102 ] . V_137 , V_141 ,
& V_2 -> V_23 [ V_139 ] . V_137 ) ;
V_138 [ V_141 ] . V_137 ++ ;
}
V_52:
if ( V_138 )
F_12 ( V_138 ,
sizeof( * V_138 ) * V_81 -> V_20 -> V_96 ) ;
if ( V_30 == 0 )
* V_101 = V_2 ;
else
F_67 ( V_2 ) ;
return V_30 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) )
V_30 = F_62 ( V_2 ) ;
F_49 ( V_2 ) ;
return V_30 ;
}
static int F_72 ( void * V_80 , int V_30 )
{
struct V_72 * V_81 = V_80 ;
struct V_15 * V_84 ;
V_84 = F_43 ( V_81 , struct V_15 , V_18 ) ;
return F_22 ( V_84 -> V_41 , V_84 , V_30 ) ;
}
int F_73 ( struct V_54 * exp , struct V_72 * V_81 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_102 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_73 = V_81 ;
for ( V_102 = 0 ; V_102 < V_81 -> V_20 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 ;
struct V_15 * V_16 ;
V_58 = V_81 -> V_20 -> V_76 [ V_102 ] ;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
if ( V_81 -> V_19 -> V_124 & V_125 )
GOTO ( V_104 , V_30 = - V_116 ) ;
continue;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_75 = V_102 ;
V_16 -> V_39 = V_58 -> V_70 ;
F_63 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
memcpy ( V_16 -> V_18 . V_19 , V_81 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_126 = V_58 -> V_69 ;
V_16 -> V_18 . V_112 = F_72 ;
V_16 -> V_18 . V_145 = V_81 -> V_145 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_71 ( V_2 ) ;
return V_30 ;
}
int F_74 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
}
F_49 ( V_2 ) ;
return 0 ;
}
int F_75 ( struct V_54 * exp , struct V_72 * V_81 ,
struct V_121 * V_146 , struct V_94 * V_95 ,
struct V_133 * V_134 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_102 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_73 = V_81 ;
V_2 -> V_73 -> V_20 = V_95 ;
V_2 -> V_73 -> V_19 = V_146 ;
V_2 -> V_140 = V_134 ;
if ( V_134 != NULL && V_146 -> V_124 & V_147 )
V_2 -> V_7 = V_134 -> V_148 ;
for ( V_102 = 0 ; V_102 < V_95 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 ;
struct V_15 * V_16 ;
V_58 = V_95 -> V_76 [ V_102 ] ;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
continue;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_75 = V_102 ;
V_16 -> V_39 = V_58 -> V_70 ;
F_63 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
memcpy ( V_16 -> V_18 . V_19 , V_146 , sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_126 = V_58 -> V_69 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_74 ( V_2 ) ;
return V_30 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_30 = F_62 ( V_2 ) ;
}
F_49 ( V_2 ) ;
return V_30 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_30 )
{
struct V_33 * V_34 = & V_16 -> V_41 -> V_35 -> V_36 -> V_37 . V_34 ;
struct V_94 * V_95 = V_16 -> V_41 -> V_73 -> V_20 ;
F_19 ( V_2 , V_16 , V_30 ) ;
if ( V_30 && ! ( V_34 -> V_38 [ V_16 -> V_39 ] &&
V_34 -> V_38 [ V_16 -> V_39 ] -> V_40 ) )
V_30 = 0 ;
if ( V_30 == 0 ) {
if ( V_16 -> V_18 . V_19 -> V_124 & V_149 )
V_95 -> V_76 [ V_16 -> V_75 ] -> V_78 . V_150 =
V_16 -> V_18 . V_19 -> V_151 ;
if ( V_16 -> V_18 . V_19 -> V_124 & V_152 )
V_95 -> V_76 [ V_16 -> V_75 ] -> V_78 . V_153 =
V_16 -> V_18 . V_19 -> V_154 ;
if ( V_16 -> V_18 . V_19 -> V_124 & V_155 )
V_95 -> V_76 [ V_16 -> V_75 ] -> V_78 . V_156 =
V_16 -> V_18 . V_19 -> V_157 ;
}
return V_30 ;
}
static int F_78 ( void * V_80 , int V_30 )
{
struct V_72 * V_81 = V_80 ;
struct V_15 * V_84 ;
V_84 = F_43 ( V_81 , struct V_15 , V_18 ) ;
return F_77 ( V_84 -> V_41 , V_84 , V_30 ) ;
}
int F_79 ( struct V_54 * exp , struct V_72 * V_81 ,
struct V_133 * V_134 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_102 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_140 = V_134 ;
V_2 -> V_73 = V_81 ;
if ( V_134 != NULL && V_81 -> V_19 -> V_124 & V_147 )
V_2 -> V_7 = V_134 -> V_148 ;
for ( V_102 = 0 ; V_102 < V_81 -> V_20 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 = V_81 -> V_20 -> V_76 [ V_102 ] ;
struct V_15 * V_16 ;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
continue;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_75 = V_102 ;
V_16 -> V_39 = V_58 -> V_70 ;
F_63 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
memcpy ( V_16 -> V_18 . V_19 , V_81 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_126 = V_58 -> V_69 ;
V_16 -> V_18 . V_19 -> V_142 = V_102 ;
V_16 -> V_18 . V_112 = F_78 ;
V_16 -> V_18 . V_145 = V_81 -> V_145 ;
if ( V_81 -> V_19 -> V_124 & V_158 ) {
int V_137 = F_70 ( V_81 -> V_20 ,
V_81 -> V_19 -> V_159 , V_102 ,
& V_16 -> V_18 . V_19 -> V_159 ) ;
if ( V_137 < 0 && V_16 -> V_18 . V_19 -> V_159 )
V_16 -> V_18 . V_19 -> V_159 -- ;
F_17 ( V_160 , L_15 ,
V_102 , V_16 -> V_18 . V_19 -> V_159 ,
V_81 -> V_19 -> V_159 ) ;
}
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_76 ( V_2 ) ;
return V_30 ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_30 = - V_116 ;
if ( F_16 ( & V_2 -> V_5 ) )
V_30 = F_62 ( V_2 ) ;
}
F_49 ( V_2 ) ;
return V_30 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_15 * V_16 , int V_30 )
{
struct V_33 * V_34 = & V_16 -> V_41 -> V_35 -> V_36 -> V_37 . V_34 ;
struct V_94 * V_95 = V_16 -> V_41 -> V_73 -> V_20 ;
F_19 ( V_2 , V_16 , V_30 ) ;
if ( V_30 && ! V_34 -> V_38 [ V_16 -> V_39 ] -> V_40 )
V_30 = 0 ;
if ( V_30 == 0 ) {
F_39 ( V_95 ) ;
if ( V_16 -> V_18 . V_19 -> V_124 & V_127 ) {
V_95 -> V_76 [ V_16 -> V_75 ] -> V_78 . V_128 =
V_16 -> V_18 . V_19 -> V_129 ;
}
F_41 ( V_95 ) ;
}
return V_30 ;
}
static int F_82 ( void * V_80 , int V_30 )
{
struct V_72 * V_81 = V_80 ;
struct V_15 * V_84 ;
V_84 = F_43 ( V_81 , struct V_15 , V_18 ) ;
return F_81 ( V_84 -> V_41 , V_84 , V_30 ) ;
}
int F_83 ( struct V_54 * exp , struct V_72 * V_81 ,
struct V_133 * V_134 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_102 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_73 = V_81 ;
V_2 -> V_35 = exp ;
for ( V_102 = 0 ; V_102 < V_81 -> V_20 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 = V_81 -> V_20 -> V_76 [ V_102 ] ;
struct V_15 * V_16 ;
T_4 V_161 , V_162 ;
if ( ! F_55 ( V_81 -> V_20 , V_102 ,
V_81 -> V_109 . V_110 . V_107 ,
V_81 -> V_109 . V_110 . V_108 ,
& V_161 , & V_162 ) )
continue;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
GOTO ( V_104 , V_30 = - V_116 ) ;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_75 = V_102 ;
V_16 -> V_39 = V_58 -> V_70 ;
F_63 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
memcpy ( V_16 -> V_18 . V_19 , V_81 -> V_19 ,
sizeof( * V_16 -> V_18 . V_19 ) ) ;
V_16 -> V_18 . V_19 -> V_126 = V_58 -> V_69 ;
V_16 -> V_18 . V_19 -> V_124 |= V_163 ;
V_16 -> V_18 . V_19 -> V_142 = V_102 ;
V_16 -> V_18 . V_112 = F_82 ;
V_16 -> V_18 . V_109 . V_110 . V_107 = V_161 ;
V_16 -> V_18 . V_109 . V_110 . V_108 = V_162 ;
V_16 -> V_18 . V_109 . V_110 . V_113 = - 1 ;
V_16 -> V_18 . V_145 = V_81 -> V_145 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_80 ( V_2 ) ;
return V_30 ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
F_7 ( V_2 -> V_35 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
if ( ! F_16 ( & V_2 -> V_5 ) )
V_30 = - V_116 ;
}
F_49 ( V_2 ) ;
return V_30 ;
}
static int F_85 ( void * V_80 , int V_30 )
{
struct V_72 * V_81 = V_80 ;
struct V_15 * V_84 ;
V_84 = F_43 ( V_81 , struct V_15 , V_18 ) ;
return F_22 ( V_84 -> V_41 , V_84 , V_30 ) ;
}
int F_86 ( struct V_54 * exp , struct V_72 * V_81 ,
T_4 V_107 , T_4 V_108 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & exp -> V_36 -> V_37 . V_34 ;
int V_30 = 0 , V_102 ;
F_87 ( V_2 ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_35 = exp ;
V_2 -> V_73 = V_81 ;
for ( V_102 = 0 ; V_102 < V_81 -> V_20 -> V_96 ; V_102 ++ ) {
struct V_57 * V_58 = V_81 -> V_20 -> V_76 [ V_102 ] ;
struct V_15 * V_16 ;
T_4 V_161 , V_162 ;
if ( ! F_29 ( V_34 , V_58 -> V_70 ) ) {
F_17 ( V_111 , L_9 , V_58 -> V_70 ) ;
continue;
}
if ( ! F_55 ( V_81 -> V_20 , V_102 , V_107 , V_108 , & V_161 ,
& V_162 ) )
continue;
F_87 ( V_16 ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
V_16 -> V_75 = V_102 ;
V_16 -> V_39 = V_58 -> V_70 ;
F_63 ( V_16 -> V_18 . V_19 ) ;
if ( V_16 -> V_18 . V_19 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
* V_16 -> V_18 . V_19 = * V_81 -> V_19 ;
V_16 -> V_18 . V_19 -> V_126 = V_58 -> V_69 ;
V_16 -> V_18 . V_19 -> V_142 = V_102 ;
V_16 -> V_18 . V_109 . V_110 . V_107 = V_161 ;
V_16 -> V_18 . V_109 . V_110 . V_108 = V_162 ;
V_16 -> V_18 . V_109 . V_110 . V_113 = - 1 ;
V_16 -> V_18 . V_112 = F_85 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_84 ( V_2 ) ;
return V_30 ;
}
int F_88 ( struct V_164 * V_165 , struct V_166 * V_167 , int V_168 )
{
if ( V_168 ) {
T_3 V_169 = F_89 ( & V_165 -> V_37 . V_34 ,
V_170 , 0 ) ;
if ( V_167 -> V_171 != V_172 )
F_90 ( V_167 -> V_171 , V_169 ) ;
if ( V_167 -> V_173 != V_172 )
F_90 ( V_167 -> V_173 , V_169 ) ;
F_91 ( & V_165 -> V_174 ) ;
memcpy ( & V_165 -> V_175 , V_167 , sizeof( * V_167 ) ) ;
V_165 -> V_176 = F_92 () ;
F_93 ( & V_165 -> V_174 ) ;
return 0 ;
}
return - V_116 ;
}
int F_94 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
if ( V_2 == NULL )
return 0 ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_30 = F_88 ( V_2 -> V_177 , V_2 -> V_73 -> V_22 ,
F_16 ( & V_2 -> V_5 ) ) ;
}
F_49 ( V_2 ) ;
return V_30 ;
}
void F_95 ( struct V_166 * V_167 , struct V_166 * V_178 ,
int V_168 )
{
int V_139 = 0 , V_179 = 0 ;
T_2 V_180 ;
if ( V_168 == 0 ) {
memcpy ( V_167 , V_178 , sizeof( * V_178 ) ) ;
} else {
if ( V_167 -> V_181 != V_178 -> V_181 ) {
V_180 = V_167 -> V_181 | V_178 -> V_181 ;
for ( V_139 = 0 ; V_139 <= 64 ; ++ V_139 ) {
if ( V_180 & 1 ) {
if ( V_179 )
break;
else
V_179 = 1 ;
V_139 = 0 ;
}
V_180 >>= 1 ;
}
}
if ( V_167 -> V_181 < V_178 -> V_181 ) {
V_167 -> V_181 = V_178 -> V_181 ;
V_167 -> V_182 >>= V_139 ;
V_167 -> V_183 >>= V_139 ;
V_167 -> V_184 >>= V_139 ;
} else if ( V_139 != 0 ) {
V_178 -> V_182 >>= V_139 ;
V_178 -> V_183 >>= V_139 ;
V_178 -> V_184 >>= V_139 ;
}
V_167 -> V_182 += V_178 -> V_182 ;
V_167 -> V_183 += V_178 -> V_183 ;
V_167 -> V_184 += V_178 -> V_184 ;
F_96 ( V_167 -> V_171 , V_178 -> V_171 ) ;
F_96 ( V_167 -> V_173 , V_178 -> V_173 ) ;
}
}
static int F_97 ( void * V_80 , int V_30 )
{
struct V_72 * V_81 = V_80 ;
struct V_15 * V_84 ;
struct V_1 * V_2 ;
struct V_166 * V_167 , * V_178 ;
struct V_33 * V_34 ;
struct V_43 * V_44 ;
struct V_164 * V_185 , * V_186 ;
int V_168 ;
V_84 = F_43 ( V_81 , struct V_15 , V_18 ) ;
V_2 = V_84 -> V_41 ;
V_185 = V_2 -> V_177 ;
V_34 = & V_185 -> V_37 . V_34 ;
V_167 = V_2 -> V_73 -> V_22 ;
V_178 = V_81 -> V_22 ;
V_168 = F_16 ( & V_2 -> V_5 ) ;
F_19 ( V_2 , V_84 , V_30 ) ;
if ( V_30 )
GOTO ( V_52 , V_30 ) ;
F_98 ( V_185 ) ;
V_44 = V_34 -> V_38 [ V_84 -> V_39 ] ;
if ( ! V_44 || ! V_44 -> V_40 )
GOTO ( V_187 , V_30 ) ;
V_186 = F_99 ( V_44 -> V_46 ) ;
F_91 ( & V_186 -> V_174 ) ;
memcpy ( & V_186 -> V_175 , V_178 , sizeof( * V_178 ) ) ;
if ( ( V_81 -> V_77 & V_188 ) == 0 )
V_186 -> V_176 = F_92 () ;
F_93 ( & V_186 -> V_174 ) ;
V_187:
F_95 ( V_167 , V_178 , V_168 ) ;
F_100 ( V_185 ) ;
V_52:
if ( V_2 -> V_73 -> V_77 & V_189 &&
F_15 ( V_2 , 0 ) ) {
F_101 ( NULL , V_2 , V_2 -> V_3 !=
F_16 ( & V_2 -> V_5 ) ) ;
}
return 0 ;
}
int F_102 ( struct V_164 * V_165 , struct V_72 * V_81 ,
struct V_1 * * V_101 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 = & V_165 -> V_37 . V_34 ;
int V_30 = 0 , V_102 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return - V_103 ;
F_1 ( V_2 ) ;
V_2 -> V_177 = V_165 ;
V_2 -> V_73 = V_81 ;
for ( V_102 = 0 ; V_102 < V_34 -> V_190 . V_191 ; V_102 ++ ) {
struct V_15 * V_16 ;
if ( V_34 -> V_38 [ V_102 ] == NULL ||
( ! F_29 ( V_34 , V_102 ) &&
( V_81 -> V_77 & V_192 ) ) ) {
F_17 ( V_111 , L_9 , V_102 ) ;
continue;
}
if ( ! V_34 -> V_38 [ V_102 ] -> V_46 ) {
F_17 ( V_111 , L_16 , V_102 ) ;
continue;
}
F_52 ( V_16 , sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
GOTO ( V_104 , V_30 = - V_103 ) ;
F_52 ( V_16 -> V_18 . V_22 , sizeof( * V_16 -> V_18 . V_22 ) ) ;
if ( V_16 -> V_18 . V_22 == NULL ) {
F_13 ( V_16 , sizeof( * V_16 ) ) ;
GOTO ( V_104 , V_30 = - V_103 ) ;
}
V_16 -> V_39 = V_102 ;
V_16 -> V_18 . V_112 = F_97 ;
V_16 -> V_18 . V_77 = V_81 -> V_77 ;
F_23 ( V_16 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_104 , V_30 = - V_116 ) ;
* V_101 = V_2 ;
return V_30 ;
V_104:
F_94 ( V_2 ) ;
return V_30 ;
}
