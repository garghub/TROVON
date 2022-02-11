static int F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_3 * V_9 ;
struct V_10 * V_11 ;
V_12 ;
V_8 = F_2 ( V_4 -> V_13 , struct V_7 , V_14 . V_15 ) ;
V_11 = & V_8 -> V_16 -> V_15 ;
V_9 = V_11 -> V_17 -> V_18 ( V_2 , V_4 -> V_19 , V_11 ) ;
if ( V_9 == NULL )
RETURN ( - V_20 ) ;
F_3 ( V_4 , V_9 ) ;
RETURN ( 0 ) ;
}
static void F_4 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_21 * V_22 = F_5 ( V_4 ) ;
struct V_23 * V_24 = V_4 -> V_19 ;
F_6 ( & V_22 -> V_25 ) ;
F_7 ( V_24 ) ;
F_8 ( V_22 ) ;
}
struct V_3 * F_9 ( const struct V_1 * V_2 ,
const struct V_23 * V_26 ,
struct V_10 * V_27 )
{
struct V_23 * V_24 ;
struct V_21 * V_4 ;
struct V_3 * V_28 ;
F_10 ( V_26 == NULL ) ;
F_11 ( V_4 ) ;
if ( V_4 != NULL ) {
V_28 = & V_4 -> V_25 . V_29 ;
V_24 = & V_4 -> V_30 ;
F_12 ( V_24 ) ;
F_13 ( & V_4 -> V_25 , V_24 , V_27 ) ;
F_14 ( V_24 , V_28 ) ;
V_28 -> V_31 = & V_32 ;
return V_28 ;
} else {
return NULL ;
}
}
static struct V_7 * F_15 ( struct V_33 * V_34 )
{
struct V_7 * V_8 , * V_35 = NULL ;
F_16 (ls, &ls_list_head, ls_linkage) {
if ( V_8 -> V_16 == V_34 ) {
F_17 ( & V_8 -> V_36 ) ;
V_35 = V_8 ;
break;
}
}
return V_35 ;
}
struct V_7 * F_18 ( struct V_33 * V_34 )
{
struct V_7 * V_8 ;
F_19 ( & V_37 ) ;
V_8 = F_15 ( V_34 ) ;
F_20 ( & V_37 ) ;
return V_8 ;
}
struct V_7 * F_21 ( struct V_33 * V_34 )
{
struct V_7 * V_8 ;
V_12 ;
F_19 ( & V_37 ) ;
V_8 = F_15 ( V_34 ) ;
if ( V_8 )
GOTO ( V_38 , V_8 ) ;
F_11 ( V_8 ) ;
if ( V_8 == NULL )
GOTO ( V_38 , V_8 = F_22 ( - V_20 ) ) ;
F_23 ( & V_8 -> V_36 , 1 ) ;
F_24 ( & V_8 -> V_39 ) ;
F_25 ( & V_8 -> V_40 ) ;
V_8 -> V_16 = V_34 ;
F_10 ( V_34 -> V_15 . V_41 ) ;
F_26 ( & V_8 -> V_14 . V_15 , & V_42 ) ;
V_8 -> V_14 . V_15 . V_17 = & V_43 ;
V_8 -> V_14 . V_15 . V_41 = V_34 -> V_15 . V_41 ;
F_27 ( & V_8 -> V_44 , & V_45 ) ;
V_38:
F_20 ( & V_37 ) ;
RETURN ( V_8 ) ;
}
void F_28 ( const struct V_1 * V_2 , struct V_7 * V_8 )
{
F_10 ( V_2 ) ;
if ( ! F_29 ( & V_8 -> V_36 ) )
return;
F_19 ( & V_37 ) ;
if ( F_30 ( & V_8 -> V_36 ) == 0 ) {
F_10 ( F_31 ( & V_8 -> V_39 ) ) ;
F_32 ( & V_8 -> V_44 ) ;
F_33 ( V_2 , V_8 -> V_14 . V_15 . V_41 , ~ 0 ) ;
F_34 ( & V_8 -> V_14 . V_15 ) ;
F_8 ( V_8 ) ;
}
F_20 ( & V_37 ) ;
}
int F_35 ( const struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
F_10 ( V_47 -> V_50 ) ;
F_10 ( V_47 -> V_51 ) ;
F_19 ( & V_47 -> V_52 ) ;
V_49 -> V_53 = V_47 -> V_54 ;
V_49 -> V_55 = ++ V_47 -> V_56 ;
V_49 -> V_57 = 0 ;
F_20 ( & V_47 -> V_52 ) ;
return 0 ;
}
int F_36 ( const struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_58 * V_4 , struct V_59 * V_60 ,
struct V_61 * V_62 ,
struct V_63 * V_64 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
int V_67 ;
V_12 ;
if ( V_47 != NULL ) {
F_10 ( F_38 ( V_47 -> V_51 ) ) ;
V_67 = F_39 ( V_2 , V_47 -> V_51 ,
sizeof( struct V_68 ) , 0 , V_64 ) ;
if ( V_67 )
RETURN ( V_67 ) ;
}
V_67 = F_40 ( V_2 , V_4 , V_60 , NULL , V_62 , V_64 ) ;
if ( V_67 )
RETURN ( V_67 ) ;
V_66 -> V_69 . V_70 = NULL ;
V_66 -> V_69 . V_71 = sizeof( V_66 -> V_72 ) ;
V_67 = F_41 ( V_2 , V_4 , & V_66 -> V_69 , V_73 , 0 , V_64 ) ;
RETURN ( V_67 ) ;
}
int F_42 ( const struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_58 * V_4 , struct V_59 * V_60 ,
struct V_61 * V_62 , struct V_63 * V_64 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
T_1 V_74 ;
int V_67 ;
V_12 ;
V_67 = F_43 ( V_2 , V_4 , V_60 , NULL , V_62 , V_64 ) ;
if ( V_67 )
RETURN ( V_67 ) ;
if ( V_47 == NULL )
RETURN ( V_67 ) ;
F_10 ( V_47 -> V_51 ) ;
F_10 ( F_38 ( V_47 -> V_51 ) ) ;
F_19 ( & V_47 -> V_52 ) ;
V_74 = F_44 ( V_47 -> V_56 ) ;
V_66 -> V_75 = 0 ;
V_66 -> V_69 . V_70 = & V_74 ;
V_66 -> V_69 . V_71 = sizeof( V_74 ) ;
V_67 = F_45 ( V_2 , V_47 -> V_51 , & V_66 -> V_69 , & V_66 -> V_75 ,
V_64 ) ;
F_20 ( & V_47 -> V_52 ) ;
RETURN ( V_67 ) ;
}
struct V_58 * F_46 ( const struct V_1 * V_2 ,
const struct V_48 * V_49 ,
struct V_46 * V_47 ,
struct V_7 * V_8 ,
struct V_58 * V_76 ,
const char * V_77 , struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_58 * V_78 ;
struct V_63 * V_64 ;
int V_67 ;
V_78 = F_47 ( V_2 , V_8 , V_49 ) ;
if ( F_48 ( F_49 ( V_78 ) ) )
RETURN ( V_78 ) ;
F_10 ( V_78 != NULL ) ;
if ( F_38 ( V_78 ) )
GOTO ( V_79 , V_67 = - V_80 ) ;
V_64 = F_50 ( V_2 , V_8 -> V_16 ) ;
if ( F_49 ( V_64 ) )
GOTO ( V_79 , V_67 = F_51 ( V_64 ) ) ;
V_67 = F_36 ( V_2 , V_47 , V_78 , V_60 , V_62 , V_64 ) ;
if ( V_67 )
GOTO ( V_81 , V_67 ) ;
if ( V_66 -> V_82 . V_83 == V_84 ) {
F_52 ( V_2 , V_78 , V_64 ) ;
F_52 ( V_2 , V_76 , V_64 ) ;
}
V_67 = F_53 ( V_2 , V_76 , ( void * ) V_49 , ( void * ) V_77 , V_64 ) ;
if ( V_67 )
GOTO ( V_81 , V_67 ) ;
V_67 = F_54 ( V_2 , V_8 -> V_16 , V_64 ) ;
if ( V_67 )
GOTO ( V_81 , V_67 ) ;
F_55 ( V_2 , V_78 , 0 ) ;
if ( F_38 ( V_78 ) )
GOTO ( V_85 , V_67 = 0 ) ;
F_56 ( V_86 , L_1 V_87 L_2 ,
F_57 ( F_58 ( & V_78 -> V_29 ) ) ) ;
V_67 = F_42 ( V_2 , V_47 , V_78 , V_60 , V_62 , V_64 ) ;
if ( V_67 )
GOTO ( V_85 , V_67 ) ;
F_10 ( F_38 ( V_78 ) ) ;
if ( V_66 -> V_82 . V_83 == V_84 ) {
if ( ! F_59 ( V_2 , V_78 ) )
GOTO ( V_88 , V_67 = - V_89 ) ;
V_67 = F_60 ( V_2 , V_78 , ( void * ) V_49 , ( void * ) L_3 , V_64 ,
V_90 , 1 ) ;
if ( V_67 )
GOTO ( V_88 , V_67 ) ;
F_61 ( V_2 , V_78 , V_64 ) ;
V_67 = F_60 ( V_2 , V_78 , ( void * ) F_58 ( & V_76 -> V_29 ) ,
( void * ) L_4 , V_64 , V_90 , 1 ) ;
if ( V_67 )
GOTO ( V_88 , V_67 ) ;
}
F_55 ( V_2 , V_76 , 0 ) ;
V_67 = F_60 ( V_2 , V_76 , ( const struct V_91 * ) V_49 ,
( const struct V_92 * ) V_77 , V_64 , V_90 , 1 ) ;
if ( V_66 -> V_82 . V_83 == V_84 )
F_61 ( V_2 , V_76 , V_64 ) ;
F_62 ( V_2 , V_76 ) ;
if ( V_67 )
GOTO ( V_88 , V_67 ) ;
V_88:
if ( V_67 )
F_63 ( V_2 , V_78 , V_64 ) ;
V_85:
F_62 ( V_2 , V_78 ) ;
V_81:
F_64 ( V_2 , V_8 -> V_16 , V_64 ) ;
V_79:
if ( V_67 ) {
F_65 ( V_2 , & V_78 -> V_29 ) ;
V_78 = F_22 ( V_67 ) ;
}
RETURN ( V_78 ) ;
}
struct V_58 * F_66 ( const struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_58 * V_76 ,
const char * V_77 , T_2 V_93 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_58 * V_78 ;
int V_67 ;
F_10 ( V_76 ) ;
V_67 = F_67 ( V_2 , V_76 , V_77 , & V_66 -> V_94 ) ;
if ( V_67 == 0 )
V_78 = F_47 ( V_2 , F_68 ( V_47 -> V_50 ) , & V_66 -> V_94 ) ;
else if ( V_67 != - V_95 )
V_78 = F_22 ( V_67 ) ;
else {
V_67 = F_35 ( V_2 , V_47 , & V_66 -> V_94 ) ;
if ( V_67 < 0 ) {
V_78 = F_22 ( V_67 ) ;
} else {
V_66 -> V_96 . V_97 = V_98 ;
V_66 -> V_96 . V_99 = V_93 ;
V_66 -> V_82 . V_83 = F_69 ( V_93 & V_100 ) ;
V_78 = F_46 ( V_2 , & V_66 -> V_94 , V_47 ,
F_68 ( V_47 -> V_50 ) ,
V_76 , V_77 , & V_66 -> V_96 ,
& V_66 -> V_82 ) ;
}
}
return V_78 ;
}
struct V_58 * F_70 ( const struct V_1 * V_2 ,
struct V_33 * V_101 ,
const struct V_48 * V_49 ,
struct V_58 * V_76 ,
const char * V_77 ,
T_2 V_93 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_58 * V_78 ;
int V_67 ;
F_10 ( V_76 ) ;
V_67 = F_67 ( V_2 , V_76 , V_77 , & V_66 -> V_94 ) ;
if ( V_67 == 0 ) {
V_78 = F_71 ( V_2 , V_101 , & V_66 -> V_94 ) ;
} else if ( V_67 != - V_95 ) {
V_78 = F_22 ( V_67 ) ;
} else {
struct V_7 * V_8 ;
V_8 = F_21 ( V_101 ) ;
if ( F_49 ( V_8 ) ) {
V_78 = F_22 ( F_51 ( V_8 ) ) ;
} else {
V_66 -> V_96 . V_97 = V_98 ;
V_66 -> V_96 . V_99 = V_93 ;
V_66 -> V_82 . V_83 = F_69 ( V_93 & V_100 ) ;
V_78 = F_46 ( V_2 , V_49 , NULL , V_8 , V_76 ,
V_77 , & V_66 -> V_96 ,
& V_66 -> V_82 ) ;
if ( ! F_49 ( V_78 ) ) {
V_66 -> V_94 = V_78 -> V_29 . V_19 -> V_102 ;
F_65 ( V_2 , & V_78 -> V_29 ) ;
V_78 = F_71 ( V_2 , V_101 , & V_66 -> V_94 ) ;
}
F_28 ( V_2 , V_8 ) ;
}
}
return V_78 ;
}
struct V_58 * F_72 ( const struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_58 * V_76 ,
const char * V_77 , T_2 V_93 ,
const struct V_103 * V_104 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_58 * V_78 ;
int V_67 ;
F_10 ( V_76 ) ;
V_67 = F_67 ( V_2 , V_76 , V_77 , & V_66 -> V_94 ) ;
if ( V_67 == 0 ) {
V_78 = F_47 ( V_2 , F_68 ( V_47 -> V_50 ) , & V_66 -> V_94 ) ;
} else if ( V_67 != - V_95 ) {
V_78 = F_22 ( V_67 ) ;
} else {
V_67 = F_35 ( V_2 , V_47 , & V_66 -> V_94 ) ;
if ( V_67 < 0 ) {
V_78 = F_22 ( V_67 ) ;
} else {
V_66 -> V_96 . V_97 = V_98 ;
V_66 -> V_96 . V_99 = V_93 ;
V_66 -> V_82 . V_83 = V_105 ;
V_66 -> V_82 . V_106 . V_107 . V_108 = V_104 ;
V_78 = F_46 ( V_2 , & V_66 -> V_94 , V_47 ,
F_68 ( V_47 -> V_50 ) ,
V_76 , V_77 , & V_66 -> V_96 ,
& V_66 -> V_82 ) ;
}
}
return V_78 ;
}
struct V_58 *
F_73 ( const struct V_1 * V_2 ,
struct V_33 * V_101 ,
const struct V_48 * V_49 ,
struct V_58 * V_76 ,
const char * V_77 , T_2 V_93 ,
const struct V_103 * V_104 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_58 * V_78 ;
int V_67 ;
F_10 ( V_76 ) ;
V_67 = F_67 ( V_2 , V_76 , V_77 , & V_66 -> V_94 ) ;
if ( V_67 == 0 ) {
if ( ! F_74 ( V_49 , & V_66 -> V_94 ) )
V_78 = F_22 ( - V_109 ) ;
else
V_78 = F_71 ( V_2 , V_101 , V_49 ) ;
} else if ( V_67 != - V_95 ) {
V_78 = F_22 ( V_67 ) ;
} else {
struct V_7 * V_8 ;
V_8 = F_21 ( V_101 ) ;
if ( F_49 ( V_8 ) ) {
V_78 = F_22 ( F_51 ( V_8 ) ) ;
} else {
V_66 -> V_96 . V_97 = V_98 ;
V_66 -> V_96 . V_99 = V_93 ;
V_66 -> V_82 . V_83 = V_105 ;
V_66 -> V_82 . V_106 . V_107 . V_108 = V_104 ;
V_78 = F_46 ( V_2 , V_49 , NULL , V_8 , V_76 ,
V_77 , & V_66 -> V_96 ,
& V_66 -> V_82 ) ;
if ( ! F_49 ( V_78 ) ) {
V_66 -> V_94 = V_78 -> V_29 . V_19 -> V_102 ;
F_65 ( V_2 , & V_78 -> V_29 ) ;
V_78 = F_71 ( V_2 , V_101 , & V_66 -> V_94 ) ;
}
F_28 ( V_2 , V_8 ) ;
}
}
return V_78 ;
}
static int F_75 ( const struct V_1 * V_2 ,
struct V_33 * V_101 ,
struct V_58 * V_110 ,
struct V_58 * V_111 , const char * V_77 ,
struct V_63 * V_64 )
{
int V_67 ;
V_67 = F_76 ( V_2 , V_110 , ( const struct V_92 * ) V_77 , V_64 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_77 ( V_2 , V_111 , V_64 ) ;
if ( V_67 < 0 )
return V_67 ;
return F_78 ( V_2 , V_111 , V_64 ) ;
}
int F_79 ( const struct V_1 * V_2 , struct V_33 * V_101 ,
struct V_58 * V_76 , const char * V_77 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_58 * V_78 ;
struct V_63 * V_64 ;
int V_67 ;
V_12 ;
V_67 = F_67 ( V_2 , V_76 , V_77 , & V_66 -> V_94 ) ;
if ( V_67 == - V_95 )
RETURN ( 0 ) ;
else if ( V_67 < 0 )
RETURN ( V_67 ) ;
V_78 = F_71 ( V_2 , V_101 , & V_66 -> V_94 ) ;
if ( F_48 ( F_49 ( V_78 ) ) )
RETURN ( F_51 ( V_78 ) ) ;
V_64 = F_50 ( V_2 , V_101 ) ;
if ( F_49 ( V_64 ) )
GOTO ( V_79 , V_67 = F_51 ( V_64 ) ) ;
V_67 = F_75 ( V_2 , V_101 , V_76 , V_78 , V_77 , V_64 ) ;
if ( V_67 < 0 )
GOTO ( V_112 , V_67 ) ;
V_67 = F_54 ( V_2 , V_101 , V_64 ) ;
if ( V_67 < 0 )
GOTO ( V_112 , V_67 ) ;
F_55 ( V_2 , V_78 , 0 ) ;
V_67 = F_80 ( V_2 , V_76 , (struct V_92 * ) V_77 , V_64 , V_90 ) ;
if ( V_67 < 0 )
GOTO ( V_85 , V_67 ) ;
V_67 = F_81 ( V_2 , V_78 , V_64 ) ;
if ( V_67 < 0 ) {
V_67 = F_60 ( V_2 , V_76 ,
( const struct V_91 * ) & V_66 -> V_94 ,
( const struct V_92 * ) V_77 , V_64 , V_90 , 1 ) ;
GOTO ( V_85 , V_67 ) ;
}
V_67 = F_63 ( V_2 , V_78 , V_64 ) ;
V_85:
F_62 ( V_2 , V_78 ) ;
V_112:
F_64 ( V_2 , V_101 , V_64 ) ;
V_79:
F_65 ( V_2 , & V_78 -> V_29 ) ;
return V_67 ;
}
struct V_46 * F_82 ( struct V_7 * V_8 , T_3 V_113 )
{
struct V_46 * V_47 , * V_35 = NULL ;
F_16 (los, &ls->ls_los_list, los_list) {
if ( V_47 -> V_54 == V_113 ) {
F_17 ( & V_47 -> V_114 ) ;
V_35 = V_47 ;
break;
}
}
return V_35 ;
}
void F_83 ( struct V_46 * V_47 )
{
if ( F_29 ( & V_47 -> V_114 ) )
F_84 () ;
return;
}
int F_85 ( const struct V_1 * V_2 , struct V_33 * V_34 ,
T_3 V_115 , T_2 * V_116 , struct V_7 * V_8 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_58 * V_117 = NULL ;
struct V_68 V_118 ;
struct V_58 * V_4 = NULL ;
int V_67 = 0 ;
V_67 = F_86 ( V_2 , V_34 , & V_66 -> V_94 ) ;
if ( V_67 )
return V_67 ;
V_117 = F_47 ( V_2 , V_8 , & V_66 -> V_94 ) ;
if ( F_49 ( V_117 ) )
return F_51 ( V_117 ) ;
snprintf ( V_66 -> V_119 , sizeof( V_66 -> V_119 ) , L_5 V_120 L_6 ,
V_115 ) ;
V_67 = F_67 ( V_2 , V_117 , V_66 -> V_119 , & V_66 -> V_94 ) ;
F_65 ( V_2 , & V_117 -> V_29 ) ;
if ( V_67 == - V_95 ) {
if ( V_115 != V_121 )
return 0 ;
V_66 -> V_94 . V_53 = V_121 ;
V_66 -> V_94 . V_55 = 1 ;
V_66 -> V_94 . V_57 = 0 ;
V_4 = F_47 ( V_2 , V_8 , & V_66 -> V_94 ) ;
if ( F_49 ( V_4 ) )
return F_51 ( V_4 ) ;
if ( ! F_38 ( V_4 ) ) {
F_65 ( V_2 , & V_4 -> V_29 ) ;
return 0 ;
}
F_56 ( V_122 , L_7 ) ;
} else if ( V_67 < 0 ) {
return V_67 ;
} else {
F_56 ( V_122 , L_8 V_120 L_2 ,
V_115 ) ;
V_4 = F_47 ( V_2 , V_8 , & V_66 -> V_94 ) ;
if ( F_49 ( V_4 ) )
return F_51 ( V_4 ) ;
}
F_10 ( F_38 ( V_4 ) ) ;
V_66 -> V_75 = 0 ;
V_66 -> V_69 . V_70 = & V_118 ;
V_66 -> V_69 . V_71 = sizeof( V_118 ) ;
F_87 ( V_2 , V_4 , 0 ) ;
V_67 = F_88 ( V_2 , V_4 , & V_66 -> V_69 , & V_66 -> V_75 ) ;
F_89 ( V_2 , V_4 ) ;
F_65 ( V_2 , & V_4 -> V_29 ) ;
if ( V_67 == 0 && F_90 ( V_118 . V_123 ) != V_124 ) {
F_91 ( L_9 V_120 L_10 ,
V_4 -> V_29 . V_13 -> V_125 -> V_126 , V_115 ,
F_90 ( V_118 . V_123 ) ) ;
return - V_109 ;
} else if ( V_67 < 0 ) {
F_91 ( L_11 V_120 L_12 ,
V_4 -> V_29 . V_13 -> V_125 -> V_126 , V_115 , V_67 ) ;
return V_67 ;
}
* V_116 = F_90 ( V_118 . V_127 ) ;
return V_67 ;
}
int F_92 ( const struct V_1 * V_2 , struct V_33 * V_34 ,
const struct V_48 * V_128 ,
struct V_46 * * V_47 )
{
struct V_65 * V_66 = F_37 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_74 ;
struct V_58 * V_4 = NULL ;
struct V_63 * V_64 ;
T_2 V_116 = F_93 ( V_128 ) ;
int V_67 = 0 ;
V_12 ;
V_8 = F_21 ( V_34 ) ;
if ( F_49 ( V_8 ) )
RETURN ( F_51 ( V_8 ) ) ;
F_19 ( & V_8 -> V_40 ) ;
* V_47 = F_82 ( V_8 , F_94 ( V_128 ) ) ;
if ( * V_47 != NULL )
GOTO ( V_79 , V_67 = 0 ) ;
F_11 ( * V_47 ) ;
if ( * V_47 == NULL )
GOTO ( V_79 , V_67 = - V_20 ) ;
F_23 ( & ( * V_47 ) -> V_114 , 1 ) ;
F_25 ( & ( * V_47 ) -> V_52 ) ;
( * V_47 ) -> V_50 = & V_8 -> V_14 ;
F_17 ( & V_8 -> V_36 ) ;
F_27 ( & ( * V_47 ) -> V_129 , & V_8 -> V_39 ) ;
V_66 -> V_94 . V_53 = F_94 ( V_128 ) ;
V_66 -> V_94 . V_55 = V_130 ;
V_66 -> V_94 . V_57 = 0 ;
V_4 = F_47 ( V_2 , V_8 , & V_66 -> V_94 ) ;
if ( F_49 ( V_4 ) )
GOTO ( V_131 , V_67 = F_51 ( V_4 ) ) ;
if ( ! F_38 ( V_4 ) ) {
V_67 = F_85 ( V_2 , V_34 , F_94 ( V_128 ) ,
& V_116 , V_8 ) ;
if ( V_67 < 0 )
GOTO ( V_131 , V_67 ) ;
V_64 = F_50 ( V_2 , V_34 ) ;
if ( F_49 ( V_64 ) )
GOTO ( V_131 , V_67 = F_51 ( V_64 ) ) ;
V_66 -> V_96 . V_97 = V_98 | V_132 ;
V_66 -> V_96 . V_99 = V_133 | V_134 | V_135 ;
V_66 -> V_82 . V_83 = F_69 ( V_133 ) ;
V_67 = F_40 ( V_2 , V_4 , & V_66 -> V_96 , NULL ,
& V_66 -> V_82 , V_64 ) ;
if ( V_67 )
GOTO ( V_136 , V_67 ) ;
V_67 = F_39 ( V_2 , V_4 , sizeof( V_74 ) , 0 , V_64 ) ;
if ( V_67 )
GOTO ( V_136 , V_67 ) ;
V_67 = F_54 ( V_2 , V_34 , V_64 ) ;
if ( V_67 )
GOTO ( V_136 , V_67 ) ;
F_55 ( V_2 , V_4 , 0 ) ;
if ( F_38 ( V_4 ) )
GOTO ( V_137 , V_67 = 0 ) ;
V_67 = F_43 ( V_2 , V_4 , & V_66 -> V_96 , NULL , & V_66 -> V_82 ,
V_64 ) ;
if ( V_67 )
GOTO ( V_137 , V_67 ) ;
V_74 = F_44 ( V_116 ) ;
V_66 -> V_75 = 0 ;
V_66 -> V_69 . V_70 = & V_74 ;
V_66 -> V_69 . V_71 = sizeof( V_74 ) ;
V_67 = F_45 ( V_2 , V_4 , & V_66 -> V_69 , & V_66 -> V_75 , V_64 ) ;
if ( V_67 )
GOTO ( V_137 , V_67 ) ;
V_137:
F_62 ( V_2 , V_4 ) ;
V_136:
F_64 ( V_2 , V_34 , V_64 ) ;
} else {
V_66 -> V_75 = 0 ;
V_66 -> V_69 . V_70 = & V_74 ;
V_66 -> V_69 . V_71 = sizeof( V_74 ) ;
F_87 ( V_2 , V_4 , 0 ) ;
V_67 = F_88 ( V_2 , V_4 , & V_66 -> V_69 , & V_66 -> V_75 ) ;
F_89 ( V_2 , V_4 ) ;
if ( V_67 == 0 && F_95 ( V_74 ) > V_138 ) {
F_91 ( L_13 V_139 L_14 ,
V_4 -> V_29 . V_13 -> V_125 -> V_126 ,
F_95 ( V_74 ) ) ;
V_67 = - V_109 ;
}
}
V_131:
if ( V_67 != 0 ) {
F_32 ( & ( * V_47 ) -> V_129 ) ;
F_96 ( & V_8 -> V_36 ) ;
F_8 ( * V_47 ) ;
* V_47 = NULL ;
if ( V_4 != NULL && ! F_49 ( V_4 ) )
F_65 ( V_2 , & V_4 -> V_29 ) ;
} else {
( * V_47 ) -> V_54 = F_94 ( V_128 ) ;
( * V_47 ) -> V_56 = F_95 ( V_74 ) ;
( * V_47 ) -> V_51 = V_4 ;
F_97 ( ( * V_47 ) -> V_56 >= V_116 , L_15 ,
( * V_47 ) -> V_56 , V_116 ) ;
}
V_79:
F_20 ( & V_8 -> V_40 ) ;
F_28 ( V_2 , V_8 ) ;
return V_67 ;
}
void F_98 ( const struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_7 * V_8 ;
if ( ! F_29 ( & V_47 -> V_114 ) )
return;
F_10 ( V_2 ) ;
F_10 ( V_47 -> V_50 ) ;
V_8 = F_68 ( V_47 -> V_50 ) ;
F_19 ( & V_8 -> V_40 ) ;
if ( F_30 ( & V_47 -> V_114 ) == 0 ) {
if ( V_47 -> V_51 )
F_65 ( V_2 , & V_47 -> V_51 -> V_29 ) ;
F_32 ( & V_47 -> V_129 ) ;
F_8 ( V_47 ) ;
}
F_20 ( & V_8 -> V_40 ) ;
F_28 ( V_2 , V_8 ) ;
}
