static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 , 0 ) ;
F_2 ( & V_2 -> V_5 , 0 ) ;
F_2 ( & V_2 -> V_6 , 0 ) ;
V_2 -> V_7 = 0 ;
F_3 ( & V_2 -> V_8 ) ;
F_2 ( & V_2 -> V_9 , 1 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 , * V_14 ;
V_15 ;
F_7 ( V_2 ) ;
F_8 (pos, n, &set->set_list) {
struct V_16 * V_17 = F_9 ( V_13 ,
struct V_16 ,
V_18 ) ;
F_10 ( & V_17 -> V_18 ) ;
if ( V_17 -> V_19 . V_20 )
F_11 ( V_17 -> V_19 . V_20 ) ;
if ( V_17 -> V_19 . V_21 )
F_12 ( V_17 -> V_19 . V_21 , V_17 -> V_22 ) ;
if ( V_17 -> V_19 . V_23 )
F_13 ( V_17 -> V_19 . V_23 ,
sizeof( * V_17 -> V_19 . V_23 ) ) ;
F_13 ( V_17 , sizeof( * V_17 ) ) ;
}
if ( V_2 -> V_24 ) {
int V_25 = V_2 -> V_26 * sizeof( * V_2 -> V_24 ) ;
F_12 ( V_2 -> V_24 , V_25 ) ;
}
if ( V_2 -> V_27 )
F_14 ( V_2 -> V_27 ) ;
F_13 ( V_2 , sizeof( * V_2 ) ) ;
EXIT ;
}
int F_15 ( struct V_1 * V_2 , int V_28 )
{
int V_29 = F_16 ( & V_2 -> V_4 ) ;
F_17 ( V_30 , L_1 , V_29 , V_2 -> V_3 ) ;
if ( V_29 == V_2 -> V_3 ) {
if ( V_28 )
return 1 ;
if ( F_18 ( & V_2 -> V_6 ) == 1 )
return 1 ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_31 )
{
V_17 -> V_32 = 1 ;
V_17 -> V_33 = V_31 ;
F_20 ( & V_2 -> V_4 ) ;
if ( V_31 == 0 )
F_20 ( & V_2 -> V_5 ) ;
F_21 ( & V_2 -> V_10 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_31 )
{
struct V_34 * V_35 = & V_2 -> V_36 -> V_37 -> V_38 . V_35 ;
V_15 ;
F_19 ( V_2 , V_17 , V_31 ) ;
if ( V_31 && ! ( V_35 -> V_39 [ V_17 -> V_40 ] &&
V_35 -> V_39 [ V_17 -> V_40 ] -> V_41 ) )
V_31 = 0 ;
RETURN ( V_31 ) ;
}
void F_23 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
F_24 ( & V_17 -> V_18 , & V_2 -> V_8 ) ;
V_2 -> V_3 ++ ;
V_17 -> V_42 = V_2 ;
}
static int F_25 ( struct V_34 * V_35 , int V_43 )
{
int V_31 = 0 ;
F_26 ( & V_35 -> V_44 ) ;
if ( V_35 -> V_39 [ V_43 ] == NULL ||
V_35 -> V_39 [ V_43 ] -> V_41 ||
( V_35 -> V_39 [ V_43 ] -> V_45 != NULL &&
F_27 ( V_35 -> V_39 [ V_43 ] -> V_45 ) -> V_46 ) )
V_31 = 1 ;
F_28 ( & V_35 -> V_44 ) ;
return V_31 ;
}
int F_29 ( struct V_34 * V_35 , int V_47 )
{
T_1 V_48 ;
struct V_49 V_50 ;
struct V_51 * V_52 ;
int V_31 = 0 ;
F_26 ( & V_35 -> V_44 ) ;
V_52 = V_35 -> V_39 [ V_47 ] ;
if ( F_30 ( V_52 == NULL ) )
GOTO ( V_53 , V_31 = 0 ) ;
if ( F_31 ( V_52 -> V_41 ) )
GOTO ( V_53 , V_31 = 1 ) ;
if ( V_52 -> V_45 && F_27 ( V_52 -> V_45 ) -> V_46 )
GOTO ( V_53 , V_31 = 0 ) ;
F_28 ( & V_35 -> V_44 ) ;
F_4 ( & V_48 ) ;
V_50 = F_32 ( F_33 ( V_54 ) ,
F_33 ( 1 ) , NULL , NULL ) ;
V_31 = F_34 ( V_48 , F_25 ( V_35 , V_47 ) , & V_50 ) ;
if ( V_52 != NULL && V_52 -> V_41 )
return 1 ;
return 0 ;
V_53:
F_28 ( & V_35 -> V_44 ) ;
return V_31 ;
}
static int F_35 ( struct V_55 * exp ,
struct V_56 * V_57 ,
struct V_58 * V_59 , int V_60 , int V_43 ,
struct V_61 * V_62 , int V_31 )
{
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
if ( V_31 != V_63 &&
! ( V_31 == V_64 && ( V_60 & V_65 ) ) ) {
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
if ( V_35 -> V_39 [ V_43 ] && V_35 -> V_39 [ V_43 ] -> V_41 ) {
if ( V_31 != - V_66 && V_31 != - V_67 )
F_36 ( L_2 V_68 L_3
V_68 L_4 ,
exp -> V_37 -> V_69 ,
F_37 ( V_62 ) , F_37 ( & V_59 -> V_70 ) ,
V_59 -> V_71 , V_31 ) ;
} else
V_31 = V_63 ;
}
return V_31 ;
}
int F_38 ( struct V_16 * V_17 , T_2 V_72 , int V_31 )
{
struct V_1 * V_2 = V_17 -> V_42 ;
struct V_56 * V_57 ;
struct V_73 * V_62 = V_2 -> V_74 ;
struct V_58 * V_59 ;
V_15 ;
F_7 ( V_62 != NULL ) ;
V_57 = V_2 -> V_27 -> V_75 + V_17 -> V_76 ;
V_59 = V_62 -> V_21 -> V_77 [ V_17 -> V_76 ] ;
F_39 ( V_62 -> V_21 ) ;
F_40 ( V_57 , V_59 , V_62 -> V_78 ,
& V_17 -> V_19 . V_21 -> V_77 [ 0 ] -> V_79 , V_72 , V_31 ) ;
if ( V_31 == V_64 && ( V_62 -> V_78 & V_65 ) )
memset ( V_57 , 0 , sizeof *V_57 ) ;
V_31 = F_35 ( V_2 -> V_36 , V_57 , V_59 , V_62 -> V_78 ,
V_17 -> V_40 , & V_62 -> V_21 -> V_80 , V_31 ) ;
F_41 ( V_62 -> V_21 ) ;
F_19 ( V_2 , V_17 , V_31 ) ;
RETURN ( V_31 ) ;
}
static int F_42 ( void * V_81 , int V_31 )
{
struct V_73 * V_82 = V_81 ;
struct V_83 * V_84 ;
struct V_16 * V_85 ;
V_85 = F_43 ( V_82 , struct V_16 , V_19 ) ;
V_84 = V_85 -> V_42 -> V_86 ;
return F_38 ( V_85 , V_84 -> V_87 , V_31 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_2 V_72 )
{
struct V_16 * V_17 ;
struct V_34 * V_35 = & V_2 -> V_36 -> V_37 -> V_38 . V_35 ;
int V_29 = F_16 ( & V_2 -> V_4 ) ;
int V_31 = 0 ;
V_15 ;
if ( V_29 && V_29 == F_16 ( & V_2 -> V_5 ) )
RETURN ( 0 ) ;
F_45 (req, &set->set_list, rq_link) {
struct V_56 * V_57 ;
if ( ! V_17 -> V_32 || V_17 -> V_33 )
continue;
V_57 = V_2 -> V_27 -> V_75 + V_17 -> V_76 ;
F_7 ( V_57 ) ;
if ( ! F_46 ( V_57 ) )
continue;
V_31 = F_47 ( V_35 -> V_39 [ V_17 -> V_40 ] -> V_45 ,
V_17 -> V_19 . V_21 , V_72 , V_57 ) ;
if ( V_31 && V_35 -> V_39 [ V_17 -> V_40 ] &&
V_35 -> V_39 [ V_17 -> V_40 ] -> V_41 )
F_36 ( L_5 V_68 L_6
L_7 ,
V_2 -> V_36 -> V_37 -> V_69 ,
F_37 ( & V_17 -> V_19 . V_21 -> V_80 ) ,
V_17 -> V_40 , V_31 ) ;
}
if ( V_2 -> V_27 )
F_14 ( V_2 -> V_27 ) ;
RETURN ( V_31 ) ;
}
int F_48 ( struct V_1 * V_2 , T_2 V_72 , int V_31 ,
struct V_88 * V_89 )
{
int V_90 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( ! V_89 ) {
if ( V_31 )
F_2 ( & V_2 -> V_4 , 0 ) ;
V_90 = F_44 ( V_2 , V_72 ) ;
} else if ( V_2 -> V_27 )
F_14 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
RETURN ( V_31 ? V_31 : V_90 ) ;
}
static void F_50 ( void * V_91 )
{
struct V_92 * V_93 = V_91 ;
F_20 ( & V_93 -> V_94 ) ;
F_17 ( V_30 , L_8 , V_93 ,
F_16 ( & V_93 -> V_94 ) ) ;
}
static struct V_92 * F_51 ( struct V_95 * V_96 )
{
struct V_92 * V_93 ;
F_52 ( V_93 , sizeof *V_93 +
sizeof( * V_93 -> V_75 ) * V_96 -> V_97 ) ;
if ( V_93 == NULL )
return NULL ;
F_2 ( & V_93 -> V_94 , 2 ) ;
V_93 -> V_98 = V_96 -> V_97 ;
F_3 ( & V_93 -> V_99 . V_100 ) ;
F_53 ( & V_93 -> V_99 , & V_101 ) ;
return V_93 ;
}
int F_54 ( struct V_55 * exp , struct V_73 * V_82 ,
struct V_83 * V_84 ,
struct V_1 * * V_102 )
{
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
struct V_1 * V_2 ;
int V_103 , V_31 = 0 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_74 = V_82 ;
V_2 -> V_86 = V_84 ;
V_2 -> V_27 = F_51 ( V_82 -> V_21 ) ;
if ( V_2 -> V_27 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_82 -> V_106 -> V_81 = V_2 -> V_27 -> V_99 . V_107 ;
for ( V_103 = 0 ; V_103 < V_82 -> V_21 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 ;
struct V_16 * V_17 ;
T_3 V_108 , V_109 ;
V_59 = V_82 -> V_21 -> V_77 [ V_103 ] ;
if ( ! F_55 ( V_82 -> V_21 , V_103 ,
V_82 -> V_110 . V_111 . V_108 ,
V_82 -> V_110 . V_111 . V_109 ,
& V_108 , & V_109 ) )
continue;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
continue;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_22 = sizeof( * V_17 -> V_19 . V_21 ) +
sizeof( struct V_58 * ) +
sizeof( struct V_58 ) ;
F_56 ( V_17 -> V_19 . V_21 , V_17 -> V_22 ) ;
if ( V_17 -> V_19 . V_21 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
V_17 -> V_19 . V_21 -> V_77 [ 0 ] =
( ( void * ) V_17 -> V_19 . V_21 ) + sizeof( * V_17 -> V_19 . V_21 ) +
sizeof( struct V_58 * ) ;
V_17 -> V_19 . V_106 = V_2 -> V_27 -> V_75 + V_103 ;
V_17 -> V_19 . V_113 = F_42 ;
V_17 -> V_19 . V_78 = V_82 -> V_78 ;
F_7 ( V_17 -> V_19 . V_106 ) ;
V_17 -> V_19 . V_110 . V_111 . V_114 =
V_82 -> V_110 . V_111 . V_114 ;
V_17 -> V_19 . V_110 . V_111 . V_108 = V_108 ;
V_17 -> V_19 . V_110 . V_111 . V_109 = V_109 ;
V_17 -> V_40 = V_59 -> V_71 ;
V_17 -> V_76 = V_103 ;
V_17 -> V_19 . V_21 -> V_80 = V_59 -> V_70 ;
V_17 -> V_19 . V_21 -> V_97 = 0 ;
V_17 -> V_19 . V_21 -> V_77 [ 0 ] -> V_115 =
V_59 -> V_115 ;
V_17 -> V_19 . V_21 -> V_77 [ 0 ] -> V_116 = V_59 -> V_116 ;
V_17 -> V_19 . V_21 -> V_77 [ 0 ] -> V_79 = V_59 -> V_79 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( 0 ) ;
V_105:
F_48 ( V_2 , V_84 -> V_87 , V_31 , NULL ) ;
RETURN ( V_31 ) ;
}
int F_57 ( struct V_1 * V_2 , T_2 V_72 , int V_60 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
V_31 = F_44 ( V_2 , V_72 ) ;
if ( ( V_2 -> V_3 == F_16 ( & V_2 -> V_5 ) ) &&
( V_60 & V_118 ) )
F_14 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_58 ( struct V_55 * exp , struct V_73 * V_82 ,
struct V_95 * V_96 , T_4 * V_119 ,
T_2 V_72 , struct V_56 * V_120 ,
struct V_1 * * V_102 )
{
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
struct V_1 * V_2 ;
int V_103 , V_31 = 0 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_74 = V_82 ;
V_2 -> V_74 -> V_21 = V_96 ;
V_2 -> V_27 = F_51 ( V_96 ) ;
if ( V_2 -> V_27 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_120 -> V_81 = V_2 -> V_27 -> V_99 . V_107 ;
for ( V_103 = 0 ; V_103 < V_96 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 ;
struct V_16 * V_17 ;
T_3 V_108 , V_109 ;
V_59 = V_96 -> V_77 [ V_103 ] ;
if ( ! F_55 ( V_96 , V_103 , V_119 -> V_111 . V_108 ,
V_119 -> V_111 . V_109 , & V_108 , & V_109 ) )
continue;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
GOTO ( V_105 , V_31 = - V_117 ) ;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_22 = sizeof( * V_17 -> V_19 . V_21 ) ;
F_56 ( V_17 -> V_19 . V_21 , V_17 -> V_22 ) ;
if ( V_17 -> V_19 . V_21 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
V_17 -> V_19 . V_110 . V_111 . V_108 = V_108 ;
V_17 -> V_19 . V_110 . V_111 . V_109 = V_109 ;
V_17 -> V_19 . V_110 . V_111 . V_114 = V_119 -> V_111 . V_114 ;
V_17 -> V_40 = V_59 -> V_71 ;
V_17 -> V_76 = V_103 ;
V_17 -> V_19 . V_21 -> V_80 = V_59 -> V_70 ;
V_17 -> V_19 . V_21 -> V_97 = 0 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_57 ( V_2 , V_72 , 0 ) ;
RETURN ( V_31 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( V_2 -> V_27 )
F_14 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_60 ( struct V_55 * exp , struct V_73 * V_82 ,
struct V_95 * V_96 , T_2 V_72 ,
struct V_56 * V_120 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
int V_103 , V_31 = 0 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_74 = V_82 ;
V_2 -> V_74 -> V_21 = V_96 ;
V_2 -> V_27 = F_61 ( V_120 ) ;
if ( V_2 -> V_27 == NULL ) {
F_36 ( L_10 , V_120 ) ;
GOTO ( V_105 , V_31 = - V_121 ) ;
}
V_120 -> V_81 = V_2 -> V_27 -> V_99 . V_107 ;
for ( V_103 = 0 ; V_103 < V_96 -> V_97 ; V_103 ++ ) {
struct V_16 * V_17 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = V_96 -> V_77 [ V_103 ] ;
V_57 = V_2 -> V_27 -> V_75 + V_103 ;
if ( ! F_46 ( V_57 ) ) {
F_17 ( V_30 , L_11 V_68 L_12 ,
V_59 -> V_71 , F_37 ( & V_59 -> V_70 ) ) ;
continue;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_22 = sizeof( * V_17 -> V_19 . V_21 ) ;
F_56 ( V_17 -> V_19 . V_21 , V_17 -> V_22 ) ;
if ( V_17 -> V_19 . V_21 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
V_17 -> V_40 = V_59 -> V_71 ;
V_17 -> V_76 = V_103 ;
V_17 -> V_19 . V_21 -> V_80 = V_59 -> V_70 ;
V_17 -> V_19 . V_21 -> V_97 = 0 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_59 ( V_2 ) ;
RETURN ( V_31 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_16 * V_17 ;
struct V_122 * V_123 ;
int V_31 = 0 , V_124 = 0 ;
V_15 ;
F_7 ( V_2 -> V_74 != NULL ) ;
if ( V_2 -> V_74 -> V_20 == NULL )
RETURN ( 0 ) ;
if ( ! F_16 ( & V_2 -> V_5 ) )
RETURN ( - V_117 ) ;
F_63 ( V_123 ) ;
if ( V_123 == NULL )
GOTO ( V_53 , V_31 = - V_104 ) ;
F_64 (pos, &set->set_list) {
V_17 = F_9 ( V_13 , struct V_16 , V_18 ) ;
if ( ! V_17 -> V_32 || V_17 -> V_33 )
continue;
if ( V_17 -> V_19 . V_20 -> V_125 == 0 )
continue;
F_65 ( V_123 , V_17 -> V_19 . V_20 ,
V_17 -> V_19 . V_20 -> V_125 ,
V_2 -> V_74 -> V_21 , V_17 -> V_76 , & V_124 ) ;
}
if ( ! V_124 ) {
F_36 ( L_13 ) ;
V_31 = - V_117 ;
}
if ( ( V_2 -> V_74 -> V_20 -> V_125 & V_126 ) &&
( V_2 -> V_74 -> V_21 -> V_97 != V_124 ) ) {
F_36 ( L_14 ) ;
GOTO ( V_53 , V_31 = - V_117 ) ;
}
V_123 -> V_127 = V_2 -> V_74 -> V_20 -> V_127 ;
memcpy ( V_2 -> V_74 -> V_20 , V_123 , sizeof( * V_2 -> V_74 -> V_20 ) ) ;
V_53:
if ( V_123 )
F_11 ( V_123 ) ;
RETURN ( V_31 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_95 * V_96 = V_2 -> V_74 -> V_21 ;
struct V_58 * V_59 = NULL ;
struct V_12 * V_13 ;
struct V_16 * V_17 ;
V_15 ;
F_64 (pos, &set->set_list) {
V_17 = F_9 ( V_13 , struct V_16 , V_18 ) ;
if ( ! V_17 -> V_32 || V_17 -> V_33 )
continue;
V_59 = V_96 -> V_77 [ V_17 -> V_76 ] ;
if ( V_17 -> V_19 . V_20 -> V_125 & V_128 )
V_59 -> V_79 . V_129 = V_17 -> V_19 . V_20 -> V_130 ;
}
RETURN ( 0 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_31 = F_66 ( V_2 ) ;
}
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_68 ( struct V_55 * exp , struct V_73 * V_82 ,
T_5 V_131 , struct V_132 * V_133 ,
struct V_134 * V_135 ,
struct V_1 * * V_102 )
{
struct {
T_5 V_136 ;
T_5 V_137 ;
T_5 V_138 ;
} * V_139 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
int V_31 = 0 , V_103 , V_140 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_141 = V_135 ;
V_2 -> V_74 = V_82 ;
V_2 -> V_26 = V_131 ;
F_56 ( V_2 -> V_24 , V_131 * sizeof( * V_2 -> V_24 ) ) ;
if ( ! V_2 -> V_24 )
GOTO ( V_53 , V_31 = - V_104 ) ;
F_56 ( V_139 , sizeof( * V_139 ) * V_82 -> V_21 -> V_97 ) ;
if ( ! V_139 )
GOTO ( V_53 , V_31 = - V_104 ) ;
for ( V_103 = 0 ; V_103 < V_131 ; V_103 ++ ) {
int V_142 = F_69 ( V_82 -> V_21 , V_133 [ V_103 ] . V_138 ) ;
V_139 [ V_142 ] . V_137 ++ ;
}
V_140 = 0 ;
for ( V_103 = 0 ; V_103 < V_82 -> V_21 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 = NULL ;
struct V_16 * V_17 ;
if ( V_139 [ V_103 ] . V_137 == 0 )
continue;
V_59 = V_82 -> V_21 -> V_77 [ V_103 ] ;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
GOTO ( V_53 , V_31 = - V_117 ) ;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_53 , V_31 = - V_104 ) ;
F_63 ( V_17 -> V_19 . V_20 ) ;
if ( V_17 -> V_19 . V_20 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_53 , V_31 = - V_104 ) ;
}
if ( V_82 -> V_20 ) {
memcpy ( V_17 -> V_19 . V_20 , V_82 -> V_20 ,
sizeof( * V_17 -> V_19 . V_20 ) ) ;
}
V_17 -> V_19 . V_20 -> V_127 = V_59 -> V_70 ;
V_17 -> V_19 . V_20 -> V_143 = V_103 ;
V_17 -> V_22 = sizeof( * V_17 -> V_19 . V_21 ) ;
F_56 ( V_17 -> V_19 . V_21 , V_17 -> V_22 ) ;
if ( V_17 -> V_19 . V_21 == NULL ) {
F_11 ( V_17 -> V_19 . V_20 ) ;
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_53 , V_31 = - V_104 ) ;
}
V_17 -> V_40 = V_59 -> V_71 ;
V_17 -> V_76 = V_103 ;
V_17 -> V_19 . V_21 -> V_80 = V_59 -> V_70 ;
V_17 -> V_144 = V_139 [ V_103 ] . V_137 ;
V_17 -> V_145 = V_140 ;
V_140 += V_17 -> V_144 ;
V_139 [ V_103 ] . V_136 = V_17 -> V_145 ;
V_17 -> V_19 . V_146 = V_82 -> V_146 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_53 , V_31 = - V_117 ) ;
for ( V_103 = 0 ; V_103 < V_131 ; V_103 ++ ) {
int V_142 = F_69 ( V_82 -> V_21 , V_133 [ V_103 ] . V_138 ) ;
V_140 = V_139 [ V_142 ] . V_136 + V_139 [ V_142 ] . V_138 ;
F_7 ( V_140 < V_131 ) ;
V_2 -> V_24 [ V_140 ] = V_133 [ V_103 ] ;
F_70 ( V_82 -> V_21 , V_133 [ V_103 ] . V_138 , V_142 ,
& V_2 -> V_24 [ V_140 ] . V_138 ) ;
V_139 [ V_142 ] . V_138 ++ ;
}
V_53:
if ( V_139 )
F_12 ( V_139 ,
sizeof( * V_139 ) * V_82 -> V_21 -> V_97 ) ;
if ( V_31 == 0 )
* V_102 = V_2 ;
else
F_67 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( F_16 ( & V_2 -> V_4 ) )
V_31 = F_62 ( V_2 ) ;
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
static int F_72 ( void * V_81 , int V_31 )
{
struct V_73 * V_82 = V_81 ;
struct V_16 * V_85 ;
V_85 = F_43 ( V_82 , struct V_16 , V_19 ) ;
return F_22 ( V_85 -> V_42 , V_85 , V_31 ) ;
}
int F_73 ( struct V_55 * exp , struct V_73 * V_82 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
int V_31 = 0 , V_103 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_74 = V_82 ;
for ( V_103 = 0 ; V_103 < V_82 -> V_21 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 ;
struct V_16 * V_17 ;
V_59 = V_82 -> V_21 -> V_77 [ V_103 ] ;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
if ( V_82 -> V_20 -> V_125 & V_126 )
GOTO ( V_105 , V_31 = - V_117 ) ;
continue;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_76 = V_103 ;
V_17 -> V_40 = V_59 -> V_71 ;
F_63 ( V_17 -> V_19 . V_20 ) ;
if ( V_17 -> V_19 . V_20 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
memcpy ( V_17 -> V_19 . V_20 , V_82 -> V_20 ,
sizeof( * V_17 -> V_19 . V_20 ) ) ;
V_17 -> V_19 . V_20 -> V_127 = V_59 -> V_70 ;
V_17 -> V_19 . V_113 = F_72 ;
V_17 -> V_19 . V_146 = V_82 -> V_146 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_71 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_74 ( struct V_1 * V_2 )
{
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
}
F_49 ( V_2 ) ;
RETURN ( 0 ) ;
}
int F_75 ( struct V_55 * exp , struct V_73 * V_82 ,
struct V_122 * V_147 , struct V_95 * V_96 ,
struct V_134 * V_135 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
int V_31 = 0 , V_103 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_74 = V_82 ;
V_2 -> V_74 -> V_21 = V_96 ;
V_2 -> V_74 -> V_20 = V_147 ;
V_2 -> V_141 = V_135 ;
if ( V_135 != NULL && V_147 -> V_125 & V_148 )
V_2 -> V_7 = V_135 -> V_149 ;
for ( V_103 = 0 ; V_103 < V_96 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 ;
struct V_16 * V_17 ;
V_59 = V_96 -> V_77 [ V_103 ] ;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
continue;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_76 = V_103 ;
V_17 -> V_40 = V_59 -> V_71 ;
F_63 ( V_17 -> V_19 . V_20 ) ;
if ( V_17 -> V_19 . V_20 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
memcpy ( V_17 -> V_19 . V_20 , V_147 , sizeof( * V_17 -> V_19 . V_20 ) ) ;
V_17 -> V_19 . V_20 -> V_127 = V_59 -> V_70 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_74 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_31 = F_62 ( V_2 ) ;
}
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_31 )
{
struct V_34 * V_35 = & V_17 -> V_42 -> V_36 -> V_37 -> V_38 . V_35 ;
struct V_95 * V_96 = V_17 -> V_42 -> V_74 -> V_21 ;
V_15 ;
F_19 ( V_2 , V_17 , V_31 ) ;
if ( V_31 && ! ( V_35 -> V_39 [ V_17 -> V_40 ] &&
V_35 -> V_39 [ V_17 -> V_40 ] -> V_41 ) )
V_31 = 0 ;
if ( V_31 == 0 ) {
if ( V_17 -> V_19 . V_20 -> V_125 & V_150 )
V_96 -> V_77 [ V_17 -> V_76 ] -> V_79 . V_151 =
V_17 -> V_19 . V_20 -> V_152 ;
if ( V_17 -> V_19 . V_20 -> V_125 & V_153 )
V_96 -> V_77 [ V_17 -> V_76 ] -> V_79 . V_154 =
V_17 -> V_19 . V_20 -> V_155 ;
if ( V_17 -> V_19 . V_20 -> V_125 & V_156 )
V_96 -> V_77 [ V_17 -> V_76 ] -> V_79 . V_157 =
V_17 -> V_19 . V_20 -> V_158 ;
}
RETURN ( V_31 ) ;
}
static int F_78 ( void * V_81 , int V_31 )
{
struct V_73 * V_82 = V_81 ;
struct V_16 * V_85 ;
V_85 = F_43 ( V_82 , struct V_16 , V_19 ) ;
return F_77 ( V_85 -> V_42 , V_85 , V_31 ) ;
}
int F_79 ( struct V_55 * exp , struct V_73 * V_82 ,
struct V_134 * V_135 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
int V_31 = 0 , V_103 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_141 = V_135 ;
V_2 -> V_74 = V_82 ;
if ( V_135 != NULL && V_82 -> V_20 -> V_125 & V_148 )
V_2 -> V_7 = V_135 -> V_149 ;
for ( V_103 = 0 ; V_103 < V_82 -> V_21 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 = V_82 -> V_21 -> V_77 [ V_103 ] ;
struct V_16 * V_17 ;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
continue;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_76 = V_103 ;
V_17 -> V_40 = V_59 -> V_71 ;
F_63 ( V_17 -> V_19 . V_20 ) ;
if ( V_17 -> V_19 . V_20 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
memcpy ( V_17 -> V_19 . V_20 , V_82 -> V_20 ,
sizeof( * V_17 -> V_19 . V_20 ) ) ;
V_17 -> V_19 . V_20 -> V_127 = V_59 -> V_70 ;
V_17 -> V_19 . V_20 -> V_143 = V_103 ;
V_17 -> V_19 . V_113 = F_78 ;
V_17 -> V_19 . V_146 = V_82 -> V_146 ;
if ( V_82 -> V_20 -> V_125 & V_159 ) {
int V_138 = F_70 ( V_82 -> V_21 ,
V_82 -> V_20 -> V_160 , V_103 ,
& V_17 -> V_19 . V_20 -> V_160 ) ;
if ( V_138 < 0 && V_17 -> V_19 . V_20 -> V_160 )
V_17 -> V_19 . V_20 -> V_160 -- ;
F_17 ( V_161 , L_15 V_162 L_16 V_162 L_17 ,
V_103 , V_17 -> V_19 . V_20 -> V_160 ,
V_82 -> V_20 -> V_160 ) ;
}
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_76 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_31 = - V_117 ;
if ( F_16 ( & V_2 -> V_5 ) )
V_31 = F_62 ( V_2 ) ;
}
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_31 )
{
struct V_34 * V_35 = & V_17 -> V_42 -> V_36 -> V_37 -> V_38 . V_35 ;
struct V_95 * V_96 = V_17 -> V_42 -> V_74 -> V_21 ;
V_15 ;
F_19 ( V_2 , V_17 , V_31 ) ;
if ( V_31 && ! V_35 -> V_39 [ V_17 -> V_40 ] -> V_41 )
V_31 = 0 ;
if ( V_31 == 0 ) {
F_39 ( V_96 ) ;
if ( V_17 -> V_19 . V_20 -> V_125 & V_128 ) {
V_96 -> V_77 [ V_17 -> V_76 ] -> V_79 . V_129 =
V_17 -> V_19 . V_20 -> V_130 ;
}
F_41 ( V_96 ) ;
}
RETURN ( V_31 ) ;
}
static int F_82 ( void * V_81 , int V_31 )
{
struct V_73 * V_82 = V_81 ;
struct V_16 * V_85 ;
V_85 = F_43 ( V_82 , struct V_16 , V_19 ) ;
return F_81 ( V_85 -> V_42 , V_85 , V_31 ) ;
}
int F_83 ( struct V_55 * exp , struct V_73 * V_82 ,
struct V_134 * V_135 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
int V_31 = 0 , V_103 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_74 = V_82 ;
V_2 -> V_36 = exp ;
for ( V_103 = 0 ; V_103 < V_82 -> V_21 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 = V_82 -> V_21 -> V_77 [ V_103 ] ;
struct V_16 * V_17 ;
T_3 V_163 , V_164 ;
if ( ! F_55 ( V_82 -> V_21 , V_103 ,
V_82 -> V_110 . V_111 . V_108 ,
V_82 -> V_110 . V_111 . V_109 ,
& V_163 , & V_164 ) )
continue;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
GOTO ( V_105 , V_31 = - V_117 ) ;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_76 = V_103 ;
V_17 -> V_40 = V_59 -> V_71 ;
F_63 ( V_17 -> V_19 . V_20 ) ;
if ( V_17 -> V_19 . V_20 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
memcpy ( V_17 -> V_19 . V_20 , V_82 -> V_20 ,
sizeof( * V_17 -> V_19 . V_20 ) ) ;
V_17 -> V_19 . V_20 -> V_127 = V_59 -> V_70 ;
V_17 -> V_19 . V_20 -> V_125 |= V_165 ;
V_17 -> V_19 . V_20 -> V_143 = V_103 ;
V_17 -> V_19 . V_113 = F_82 ;
V_17 -> V_19 . V_110 . V_111 . V_108 = V_163 ;
V_17 -> V_19 . V_110 . V_111 . V_109 = V_164 ;
V_17 -> V_19 . V_110 . V_111 . V_114 = - 1 ;
V_17 -> V_19 . V_146 = V_82 -> V_146 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_80 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
F_7 ( V_2 -> V_36 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
if ( ! F_16 ( & V_2 -> V_5 ) )
V_31 = - V_117 ;
}
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
static int F_85 ( void * V_81 , int V_31 )
{
struct V_73 * V_82 = V_81 ;
struct V_16 * V_85 ;
V_85 = F_43 ( V_82 , struct V_16 , V_19 ) ;
return F_22 ( V_85 -> V_42 , V_85 , V_31 ) ;
}
int F_86 ( struct V_55 * exp , struct V_73 * V_82 ,
T_3 V_108 , T_3 V_109 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 = & exp -> V_37 -> V_38 . V_35 ;
int V_31 = 0 , V_103 ;
V_15 ;
F_87 ( V_2 ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_36 = exp ;
V_2 -> V_74 = V_82 ;
for ( V_103 = 0 ; V_103 < V_82 -> V_21 -> V_97 ; V_103 ++ ) {
struct V_58 * V_59 = V_82 -> V_21 -> V_77 [ V_103 ] ;
struct V_16 * V_17 ;
T_3 V_163 , V_164 ;
if ( ! F_29 ( V_35 , V_59 -> V_71 ) ) {
F_17 ( V_112 , L_9 , V_59 -> V_71 ) ;
continue;
}
if ( ! F_55 ( V_82 -> V_21 , V_103 , V_108 , V_109 , & V_163 ,
& V_164 ) )
continue;
F_87 ( V_17 ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
V_17 -> V_76 = V_103 ;
V_17 -> V_40 = V_59 -> V_71 ;
F_63 ( V_17 -> V_19 . V_20 ) ;
if ( V_17 -> V_19 . V_20 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
* V_17 -> V_19 . V_20 = * V_82 -> V_20 ;
V_17 -> V_19 . V_20 -> V_127 = V_59 -> V_70 ;
V_17 -> V_19 . V_20 -> V_143 = V_103 ;
V_17 -> V_19 . V_110 . V_111 . V_108 = V_163 ;
V_17 -> V_19 . V_110 . V_111 . V_109 = V_164 ;
V_17 -> V_19 . V_110 . V_111 . V_114 = - 1 ;
V_17 -> V_19 . V_113 = F_85 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_84 ( V_2 ) ;
RETURN ( V_31 ) ;
}
int F_88 ( struct V_166 * V_167 , struct V_168 * V_169 , int V_170 )
{
V_15 ;
if ( V_170 ) {
T_2 V_171 = F_89 ( & V_167 -> V_38 . V_35 ,
V_172 , 0 ) ;
if ( V_169 -> V_173 != V_174 )
F_90 ( V_169 -> V_173 , V_171 ) ;
if ( V_169 -> V_175 != V_174 )
F_90 ( V_169 -> V_175 , V_171 ) ;
F_91 ( & V_167 -> V_176 ) ;
memcpy ( & V_167 -> V_177 , V_169 , sizeof( * V_169 ) ) ;
V_167 -> V_178 = F_92 () ;
F_93 ( & V_167 -> V_176 ) ;
RETURN ( 0 ) ;
}
RETURN ( - V_117 ) ;
}
int F_94 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
V_15 ;
if ( V_2 == NULL )
RETURN ( 0 ) ;
if ( F_16 ( & V_2 -> V_4 ) ) {
V_31 = F_88 ( V_2 -> V_179 , V_2 -> V_74 -> V_23 ,
F_16 ( & V_2 -> V_5 ) ) ;
}
F_49 ( V_2 ) ;
RETURN ( V_31 ) ;
}
void F_95 ( struct V_168 * V_169 , struct V_168 * V_180 ,
int V_170 )
{
int V_140 = 0 , V_181 = 0 ;
T_6 V_182 ;
if ( V_170 == 0 ) {
memcpy ( V_169 , V_180 , sizeof( * V_180 ) ) ;
} else {
if ( V_169 -> V_183 != V_180 -> V_183 ) {
V_182 = V_169 -> V_183 | V_180 -> V_183 ;
for ( V_140 = 0 ; V_140 <= 64 ; ++ V_140 ) {
if ( V_182 & 1 ) {
if ( V_181 )
break;
else
V_181 = 1 ;
V_140 = 0 ;
}
V_182 >>= 1 ;
}
}
if ( V_169 -> V_183 < V_180 -> V_183 ) {
V_169 -> V_183 = V_180 -> V_183 ;
V_169 -> V_184 >>= V_140 ;
V_169 -> V_185 >>= V_140 ;
V_169 -> V_186 >>= V_140 ;
} else if ( V_140 != 0 ) {
V_180 -> V_184 >>= V_140 ;
V_180 -> V_185 >>= V_140 ;
V_180 -> V_186 >>= V_140 ;
}
V_169 -> V_184 += V_180 -> V_184 ;
V_169 -> V_185 += V_180 -> V_185 ;
V_169 -> V_186 += V_180 -> V_186 ;
F_96 ( V_169 -> V_173 , V_180 -> V_173 ) ;
F_96 ( V_169 -> V_175 , V_180 -> V_175 ) ;
}
}
static int F_97 ( void * V_81 , int V_31 )
{
struct V_73 * V_82 = V_81 ;
struct V_16 * V_85 ;
struct V_1 * V_2 ;
struct V_168 * V_169 , * V_180 ;
struct V_34 * V_35 ;
struct V_51 * V_52 ;
struct V_166 * V_187 , * V_188 ;
int V_170 ;
V_15 ;
V_85 = F_43 ( V_82 , struct V_16 , V_19 ) ;
V_2 = V_85 -> V_42 ;
V_187 = V_2 -> V_179 ;
V_35 = & V_187 -> V_38 . V_35 ;
V_169 = V_2 -> V_74 -> V_23 ;
V_180 = V_82 -> V_23 ;
V_170 = F_16 ( & V_2 -> V_5 ) ;
F_19 ( V_2 , V_85 , V_31 ) ;
if ( V_31 )
GOTO ( V_53 , V_31 ) ;
F_98 ( V_187 ) ;
V_52 = V_35 -> V_39 [ V_85 -> V_40 ] ;
if ( ! V_52 || ! V_52 -> V_41 )
GOTO ( V_189 , V_31 ) ;
V_188 = F_99 ( V_52 -> V_45 ) ;
F_91 ( & V_188 -> V_176 ) ;
memcpy ( & V_188 -> V_177 , V_180 , sizeof( * V_180 ) ) ;
if ( ( V_82 -> V_78 & V_190 ) == 0 )
V_188 -> V_178 = F_92 () ;
F_93 ( & V_188 -> V_176 ) ;
V_189:
F_95 ( V_169 , V_180 , V_170 ) ;
F_100 ( V_187 ) ;
V_53:
if ( V_2 -> V_74 -> V_78 & V_191 &&
F_15 ( V_2 , 0 ) ) {
F_101 ( NULL , V_2 , V_2 -> V_3 !=
F_16 ( & V_2 -> V_5 ) ) ;
}
RETURN ( 0 ) ;
}
int F_102 ( struct V_166 * V_167 , struct V_73 * V_82 ,
struct V_1 * * V_102 )
{
struct V_1 * V_2 ;
struct V_34 * V_35 = & V_167 -> V_38 . V_35 ;
int V_31 = 0 , V_103 ;
V_15 ;
F_52 ( V_2 , sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
RETURN ( - V_104 ) ;
F_1 ( V_2 ) ;
V_2 -> V_179 = V_167 ;
V_2 -> V_74 = V_82 ;
for ( V_103 = 0 ; V_103 < V_35 -> V_192 . V_193 ; V_103 ++ ) {
struct V_16 * V_17 ;
if ( V_35 -> V_39 [ V_103 ] == NULL ||
( ! F_29 ( V_35 , V_103 ) &&
( V_82 -> V_78 & V_194 ) ) ) {
F_17 ( V_112 , L_9 , V_103 ) ;
continue;
}
if ( ! V_35 -> V_39 [ V_103 ] -> V_45 ) {
F_17 ( V_112 , L_18 , V_103 ) ;
continue;
}
F_52 ( V_17 , sizeof( * V_17 ) ) ;
if ( V_17 == NULL )
GOTO ( V_105 , V_31 = - V_104 ) ;
F_52 ( V_17 -> V_19 . V_23 , sizeof( * V_17 -> V_19 . V_23 ) ) ;
if ( V_17 -> V_19 . V_23 == NULL ) {
F_13 ( V_17 , sizeof( * V_17 ) ) ;
GOTO ( V_105 , V_31 = - V_104 ) ;
}
V_17 -> V_40 = V_103 ;
V_17 -> V_19 . V_113 = F_97 ;
V_17 -> V_19 . V_78 = V_82 -> V_78 ;
F_23 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_3 )
GOTO ( V_105 , V_31 = - V_117 ) ;
* V_102 = V_2 ;
RETURN ( V_31 ) ;
V_105:
F_94 ( V_2 ) ;
RETURN ( V_31 ) ;
}
