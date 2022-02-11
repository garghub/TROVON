static int F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_3 * V_9 ;
struct V_10 * V_11 ;
V_8 = F_2 ( V_4 -> V_12 , struct V_7 , V_13 . V_14 ) ;
V_11 = & V_8 -> V_15 -> V_14 ;
V_9 = V_11 -> V_16 -> V_17 ( V_2 , V_4 -> V_18 , V_11 ) ;
if ( V_9 == NULL )
return - V_19 ;
F_3 ( V_4 , V_9 ) ;
return 0 ;
}
static void F_4 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_20 * V_21 = F_5 ( V_4 ) ;
struct V_22 * V_23 = V_4 -> V_18 ;
F_6 ( & V_21 -> V_24 ) ;
F_7 ( V_23 ) ;
F_8 ( V_21 ) ;
}
struct V_3 * F_9 ( const struct V_1 * V_2 ,
const struct V_22 * V_25 ,
struct V_10 * V_26 )
{
struct V_22 * V_23 ;
struct V_20 * V_4 ;
struct V_3 * V_27 ;
F_10 ( V_25 == NULL ) ;
F_11 ( V_4 ) ;
if ( V_4 != NULL ) {
V_27 = & V_4 -> V_24 . V_28 ;
V_23 = & V_4 -> V_29 ;
F_12 ( V_23 ) ;
F_13 ( & V_4 -> V_24 , V_23 , V_26 ) ;
F_14 ( V_23 , V_27 ) ;
V_27 -> V_30 = & V_31 ;
return V_27 ;
} else {
return NULL ;
}
}
static struct V_7 * F_15 ( struct V_32 * V_33 )
{
struct V_7 * V_8 , * V_34 = NULL ;
F_16 (ls, &ls_list_head, ls_linkage) {
if ( V_8 -> V_15 == V_33 ) {
F_17 ( & V_8 -> V_35 ) ;
V_34 = V_8 ;
break;
}
}
return V_34 ;
}
struct V_7 * F_18 ( struct V_32 * V_33 )
{
struct V_7 * V_8 ;
F_19 ( & V_36 ) ;
V_8 = F_15 ( V_33 ) ;
F_20 ( & V_36 ) ;
return V_8 ;
}
struct V_7 * F_21 ( struct V_32 * V_33 )
{
struct V_7 * V_8 ;
F_19 ( & V_36 ) ;
V_8 = F_15 ( V_33 ) ;
if ( V_8 )
GOTO ( V_37 , V_8 ) ;
F_11 ( V_8 ) ;
if ( V_8 == NULL )
GOTO ( V_37 , V_8 = F_22 ( - V_19 ) ) ;
F_23 ( & V_8 -> V_35 , 1 ) ;
F_24 ( & V_8 -> V_38 ) ;
F_25 ( & V_8 -> V_39 ) ;
V_8 -> V_15 = V_33 ;
F_10 ( V_33 -> V_14 . V_40 ) ;
F_26 ( & V_8 -> V_13 . V_14 , & V_41 ) ;
V_8 -> V_13 . V_14 . V_16 = & V_42 ;
V_8 -> V_13 . V_14 . V_40 = V_33 -> V_14 . V_40 ;
F_27 ( & V_8 -> V_43 , & V_44 ) ;
V_37:
F_20 ( & V_36 ) ;
return V_8 ;
}
void F_28 ( const struct V_1 * V_2 , struct V_7 * V_8 )
{
F_10 ( V_2 ) ;
if ( ! F_29 ( & V_8 -> V_35 ) )
return;
F_19 ( & V_36 ) ;
if ( F_30 ( & V_8 -> V_35 ) == 0 ) {
F_10 ( F_31 ( & V_8 -> V_38 ) ) ;
F_32 ( & V_8 -> V_43 ) ;
F_33 ( V_2 , V_8 -> V_13 . V_14 . V_40 , ~ 0 ) ;
F_34 ( & V_8 -> V_13 . V_14 ) ;
F_8 ( V_8 ) ;
}
F_20 ( & V_36 ) ;
}
int F_35 ( const struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_47 * V_48 )
{
F_10 ( V_46 -> V_49 ) ;
F_10 ( V_46 -> V_50 ) ;
F_19 ( & V_46 -> V_51 ) ;
V_48 -> V_52 = V_46 -> V_53 ;
V_48 -> V_54 = ++ V_46 -> V_55 ;
V_48 -> V_56 = 0 ;
F_20 ( & V_46 -> V_51 ) ;
return 0 ;
}
int F_36 ( const struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_57 * V_4 , struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
int V_66 ;
if ( V_46 != NULL ) {
F_10 ( F_38 ( V_46 -> V_50 ) ) ;
V_66 = F_39 ( V_2 , V_46 -> V_50 ,
sizeof( struct V_67 ) , 0 , V_63 ) ;
if ( V_66 )
return V_66 ;
}
V_66 = F_40 ( V_2 , V_4 , V_59 , NULL , V_61 , V_63 ) ;
if ( V_66 )
return V_66 ;
V_65 -> V_68 . V_69 = NULL ;
V_65 -> V_68 . V_70 = sizeof( V_65 -> V_71 ) ;
V_66 = F_41 ( V_2 , V_4 , & V_65 -> V_68 , V_72 , 0 , V_63 ) ;
return V_66 ;
}
int F_42 ( const struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_57 * V_4 , struct V_58 * V_59 ,
struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
T_1 V_73 ;
int V_66 ;
V_66 = F_43 ( V_2 , V_4 , V_59 , NULL , V_61 , V_63 ) ;
if ( V_66 )
return V_66 ;
if ( V_46 == NULL )
return V_66 ;
F_10 ( V_46 -> V_50 ) ;
F_10 ( F_38 ( V_46 -> V_50 ) ) ;
F_19 ( & V_46 -> V_51 ) ;
V_73 = F_44 ( V_46 -> V_55 ) ;
V_65 -> V_74 = 0 ;
V_65 -> V_68 . V_69 = & V_73 ;
V_65 -> V_68 . V_70 = sizeof( V_73 ) ;
V_66 = F_45 ( V_2 , V_46 -> V_50 , & V_65 -> V_68 , & V_65 -> V_74 ,
V_63 ) ;
F_20 ( & V_46 -> V_51 ) ;
return V_66 ;
}
struct V_57 * F_46 ( const struct V_1 * V_2 ,
const struct V_47 * V_48 ,
struct V_45 * V_46 ,
struct V_7 * V_8 ,
struct V_57 * V_75 ,
const char * V_76 , struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_57 * V_77 ;
struct V_62 * V_63 ;
int V_66 ;
V_77 = F_47 ( V_2 , V_8 , V_48 ) ;
if ( F_48 ( F_49 ( V_77 ) ) )
return V_77 ;
F_10 ( V_77 != NULL ) ;
if ( F_38 ( V_77 ) )
GOTO ( V_78 , V_66 = - V_79 ) ;
V_63 = F_50 ( V_2 , V_8 -> V_15 ) ;
if ( F_49 ( V_63 ) )
GOTO ( V_78 , V_66 = F_51 ( V_63 ) ) ;
V_66 = F_36 ( V_2 , V_46 , V_77 , V_59 , V_61 , V_63 ) ;
if ( V_66 )
GOTO ( V_80 , V_66 ) ;
if ( V_65 -> V_81 . V_82 == V_83 ) {
F_52 ( V_2 , V_77 , V_63 ) ;
F_52 ( V_2 , V_75 , V_63 ) ;
}
V_66 = F_53 ( V_2 , V_75 , ( void * ) V_48 , ( void * ) V_76 , V_63 ) ;
if ( V_66 )
GOTO ( V_80 , V_66 ) ;
V_66 = F_54 ( V_2 , V_8 -> V_15 , V_63 ) ;
if ( V_66 )
GOTO ( V_80 , V_66 ) ;
F_55 ( V_2 , V_77 , 0 ) ;
if ( F_38 ( V_77 ) )
GOTO ( V_84 , V_66 = 0 ) ;
F_56 ( V_85 , L_1 V_86 L_2 ,
F_57 ( F_58 ( & V_77 -> V_28 ) ) ) ;
V_66 = F_42 ( V_2 , V_46 , V_77 , V_59 , V_61 , V_63 ) ;
if ( V_66 )
GOTO ( V_84 , V_66 ) ;
F_10 ( F_38 ( V_77 ) ) ;
if ( V_65 -> V_81 . V_82 == V_83 ) {
if ( ! F_59 ( V_2 , V_77 ) )
GOTO ( V_87 , V_66 = - V_88 ) ;
V_66 = F_60 ( V_2 , V_77 , ( void * ) V_48 , ( void * ) L_3 , V_63 ,
V_89 , 1 ) ;
if ( V_66 )
GOTO ( V_87 , V_66 ) ;
F_61 ( V_2 , V_77 , V_63 ) ;
V_66 = F_60 ( V_2 , V_77 , ( void * ) F_58 ( & V_75 -> V_28 ) ,
( void * ) L_4 , V_63 , V_89 , 1 ) ;
if ( V_66 )
GOTO ( V_87 , V_66 ) ;
}
F_55 ( V_2 , V_75 , 0 ) ;
V_66 = F_60 ( V_2 , V_75 , ( const struct V_90 * ) V_48 ,
( const struct V_91 * ) V_76 , V_63 , V_89 , 1 ) ;
if ( V_65 -> V_81 . V_82 == V_83 )
F_61 ( V_2 , V_75 , V_63 ) ;
F_62 ( V_2 , V_75 ) ;
if ( V_66 )
GOTO ( V_87 , V_66 ) ;
V_87:
if ( V_66 )
F_63 ( V_2 , V_77 , V_63 ) ;
V_84:
F_62 ( V_2 , V_77 ) ;
V_80:
F_64 ( V_2 , V_8 -> V_15 , V_63 ) ;
V_78:
if ( V_66 ) {
F_65 ( V_2 , & V_77 -> V_28 ) ;
V_77 = F_22 ( V_66 ) ;
}
return V_77 ;
}
struct V_57 * F_66 ( const struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_57 * V_75 ,
const char * V_76 , T_2 V_92 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_57 * V_77 ;
int V_66 ;
F_10 ( V_75 ) ;
V_66 = F_67 ( V_2 , V_75 , V_76 , & V_65 -> V_93 ) ;
if ( V_66 == 0 )
V_77 = F_47 ( V_2 , F_68 ( V_46 -> V_49 ) , & V_65 -> V_93 ) ;
else if ( V_66 != - V_94 )
V_77 = F_22 ( V_66 ) ;
else {
V_66 = F_35 ( V_2 , V_46 , & V_65 -> V_93 ) ;
if ( V_66 < 0 ) {
V_77 = F_22 ( V_66 ) ;
} else {
V_65 -> V_95 . V_96 = V_97 ;
V_65 -> V_95 . V_98 = V_92 ;
V_65 -> V_81 . V_82 = F_69 ( V_92 & V_99 ) ;
V_77 = F_46 ( V_2 , & V_65 -> V_93 , V_46 ,
F_68 ( V_46 -> V_49 ) ,
V_75 , V_76 , & V_65 -> V_95 ,
& V_65 -> V_81 ) ;
}
}
return V_77 ;
}
struct V_57 * F_70 ( const struct V_1 * V_2 ,
struct V_32 * V_100 ,
const struct V_47 * V_48 ,
struct V_57 * V_75 ,
const char * V_76 ,
T_2 V_92 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_57 * V_77 ;
int V_66 ;
F_10 ( V_75 ) ;
V_66 = F_67 ( V_2 , V_75 , V_76 , & V_65 -> V_93 ) ;
if ( V_66 == 0 ) {
V_77 = F_71 ( V_2 , V_100 , & V_65 -> V_93 ) ;
} else if ( V_66 != - V_94 ) {
V_77 = F_22 ( V_66 ) ;
} else {
struct V_7 * V_8 ;
V_8 = F_21 ( V_100 ) ;
if ( F_49 ( V_8 ) ) {
V_77 = F_72 ( V_8 ) ;
} else {
V_65 -> V_95 . V_96 = V_97 ;
V_65 -> V_95 . V_98 = V_92 ;
V_65 -> V_81 . V_82 = F_69 ( V_92 & V_99 ) ;
V_77 = F_46 ( V_2 , V_48 , NULL , V_8 , V_75 ,
V_76 , & V_65 -> V_95 ,
& V_65 -> V_81 ) ;
if ( ! F_49 ( V_77 ) ) {
V_65 -> V_93 = V_77 -> V_28 . V_18 -> V_101 ;
F_65 ( V_2 , & V_77 -> V_28 ) ;
V_77 = F_71 ( V_2 , V_100 , & V_65 -> V_93 ) ;
}
F_28 ( V_2 , V_8 ) ;
}
}
return V_77 ;
}
struct V_57 * F_73 ( const struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_57 * V_75 ,
const char * V_76 , T_2 V_92 ,
const struct V_102 * V_103 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_57 * V_77 ;
int V_66 ;
F_10 ( V_75 ) ;
V_66 = F_67 ( V_2 , V_75 , V_76 , & V_65 -> V_93 ) ;
if ( V_66 == 0 ) {
V_77 = F_47 ( V_2 , F_68 ( V_46 -> V_49 ) , & V_65 -> V_93 ) ;
} else if ( V_66 != - V_94 ) {
V_77 = F_22 ( V_66 ) ;
} else {
V_66 = F_35 ( V_2 , V_46 , & V_65 -> V_93 ) ;
if ( V_66 < 0 ) {
V_77 = F_22 ( V_66 ) ;
} else {
V_65 -> V_95 . V_96 = V_97 ;
V_65 -> V_95 . V_98 = V_92 ;
V_65 -> V_81 . V_82 = V_104 ;
V_65 -> V_81 . V_105 . V_106 . V_107 = V_103 ;
V_77 = F_46 ( V_2 , & V_65 -> V_93 , V_46 ,
F_68 ( V_46 -> V_49 ) ,
V_75 , V_76 , & V_65 -> V_95 ,
& V_65 -> V_81 ) ;
}
}
return V_77 ;
}
struct V_57 *
F_74 ( const struct V_1 * V_2 ,
struct V_32 * V_100 ,
const struct V_47 * V_48 ,
struct V_57 * V_75 ,
const char * V_76 , T_2 V_92 ,
const struct V_102 * V_103 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_57 * V_77 ;
int V_66 ;
F_10 ( V_75 ) ;
V_66 = F_67 ( V_2 , V_75 , V_76 , & V_65 -> V_93 ) ;
if ( V_66 == 0 ) {
if ( ! F_75 ( V_48 , & V_65 -> V_93 ) )
V_77 = F_22 ( - V_108 ) ;
else
V_77 = F_71 ( V_2 , V_100 , V_48 ) ;
} else if ( V_66 != - V_94 ) {
V_77 = F_22 ( V_66 ) ;
} else {
struct V_7 * V_8 ;
V_8 = F_21 ( V_100 ) ;
if ( F_49 ( V_8 ) ) {
V_77 = F_72 ( V_8 ) ;
} else {
V_65 -> V_95 . V_96 = V_97 ;
V_65 -> V_95 . V_98 = V_92 ;
V_65 -> V_81 . V_82 = V_104 ;
V_65 -> V_81 . V_105 . V_106 . V_107 = V_103 ;
V_77 = F_46 ( V_2 , V_48 , NULL , V_8 , V_75 ,
V_76 , & V_65 -> V_95 ,
& V_65 -> V_81 ) ;
if ( ! F_49 ( V_77 ) ) {
V_65 -> V_93 = V_77 -> V_28 . V_18 -> V_101 ;
F_65 ( V_2 , & V_77 -> V_28 ) ;
V_77 = F_71 ( V_2 , V_100 , & V_65 -> V_93 ) ;
}
F_28 ( V_2 , V_8 ) ;
}
}
return V_77 ;
}
static int F_76 ( const struct V_1 * V_2 ,
struct V_32 * V_100 ,
struct V_57 * V_109 ,
struct V_57 * V_110 , const char * V_76 ,
struct V_62 * V_63 )
{
int V_66 ;
V_66 = F_77 ( V_2 , V_109 , ( const struct V_91 * ) V_76 , V_63 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_78 ( V_2 , V_110 , V_63 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_79 ( V_2 , V_110 , V_63 ) ;
}
int F_80 ( const struct V_1 * V_2 , struct V_32 * V_100 ,
struct V_57 * V_75 , const char * V_76 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_57 * V_77 ;
struct V_62 * V_63 ;
int V_66 ;
V_66 = F_67 ( V_2 , V_75 , V_76 , & V_65 -> V_93 ) ;
if ( V_66 == - V_94 )
return 0 ;
else if ( V_66 < 0 )
return V_66 ;
V_77 = F_71 ( V_2 , V_100 , & V_65 -> V_93 ) ;
if ( F_48 ( F_49 ( V_77 ) ) )
return F_51 ( V_77 ) ;
V_63 = F_50 ( V_2 , V_100 ) ;
if ( F_49 ( V_63 ) )
GOTO ( V_78 , V_66 = F_51 ( V_63 ) ) ;
V_66 = F_76 ( V_2 , V_100 , V_75 , V_77 , V_76 , V_63 ) ;
if ( V_66 < 0 )
GOTO ( V_111 , V_66 ) ;
V_66 = F_54 ( V_2 , V_100 , V_63 ) ;
if ( V_66 < 0 )
GOTO ( V_111 , V_66 ) ;
F_55 ( V_2 , V_77 , 0 ) ;
V_66 = F_81 ( V_2 , V_75 , (struct V_91 * ) V_76 , V_63 , V_89 ) ;
if ( V_66 < 0 )
GOTO ( V_84 , V_66 ) ;
V_66 = F_82 ( V_2 , V_77 , V_63 ) ;
if ( V_66 < 0 ) {
V_66 = F_60 ( V_2 , V_75 ,
( const struct V_90 * ) & V_65 -> V_93 ,
( const struct V_91 * ) V_76 , V_63 , V_89 , 1 ) ;
GOTO ( V_84 , V_66 ) ;
}
V_66 = F_63 ( V_2 , V_77 , V_63 ) ;
V_84:
F_62 ( V_2 , V_77 ) ;
V_111:
F_64 ( V_2 , V_100 , V_63 ) ;
V_78:
F_65 ( V_2 , & V_77 -> V_28 ) ;
return V_66 ;
}
struct V_45 * F_83 ( struct V_7 * V_8 , T_3 V_112 )
{
struct V_45 * V_46 , * V_34 = NULL ;
F_16 (los, &ls->ls_los_list, los_list) {
if ( V_46 -> V_53 == V_112 ) {
F_17 ( & V_46 -> V_113 ) ;
V_34 = V_46 ;
break;
}
}
return V_34 ;
}
void F_84 ( struct V_45 * V_46 )
{
if ( F_29 ( & V_46 -> V_113 ) )
F_85 () ;
return;
}
int F_86 ( const struct V_1 * V_2 , struct V_32 * V_33 ,
T_3 V_114 , T_2 * V_115 , struct V_7 * V_8 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_57 * V_116 = NULL ;
struct V_67 V_117 ;
struct V_57 * V_4 = NULL ;
int V_66 = 0 ;
V_66 = F_87 ( V_2 , V_33 , & V_65 -> V_93 ) ;
if ( V_66 )
return V_66 ;
V_116 = F_47 ( V_2 , V_8 , & V_65 -> V_93 ) ;
if ( F_49 ( V_116 ) )
return F_51 ( V_116 ) ;
snprintf ( V_65 -> V_118 , sizeof( V_65 -> V_118 ) , L_5 V_119 L_6 ,
V_114 ) ;
V_66 = F_67 ( V_2 , V_116 , V_65 -> V_118 , & V_65 -> V_93 ) ;
F_65 ( V_2 , & V_116 -> V_28 ) ;
if ( V_66 == - V_94 ) {
if ( V_114 != V_120 )
return 0 ;
V_65 -> V_93 . V_52 = V_120 ;
V_65 -> V_93 . V_54 = 1 ;
V_65 -> V_93 . V_56 = 0 ;
V_4 = F_47 ( V_2 , V_8 , & V_65 -> V_93 ) ;
if ( F_49 ( V_4 ) )
return F_51 ( V_4 ) ;
if ( ! F_38 ( V_4 ) ) {
F_65 ( V_2 , & V_4 -> V_28 ) ;
return 0 ;
}
F_56 ( V_121 , L_7 ) ;
} else if ( V_66 < 0 ) {
return V_66 ;
} else {
F_56 ( V_121 , L_8 V_119 L_2 ,
V_114 ) ;
V_4 = F_47 ( V_2 , V_8 , & V_65 -> V_93 ) ;
if ( F_49 ( V_4 ) )
return F_51 ( V_4 ) ;
}
F_10 ( F_38 ( V_4 ) ) ;
V_65 -> V_74 = 0 ;
V_65 -> V_68 . V_69 = & V_117 ;
V_65 -> V_68 . V_70 = sizeof( V_117 ) ;
F_88 ( V_2 , V_4 , 0 ) ;
V_66 = F_89 ( V_2 , V_4 , & V_65 -> V_68 , & V_65 -> V_74 ) ;
F_90 ( V_2 , V_4 ) ;
F_65 ( V_2 , & V_4 -> V_28 ) ;
if ( V_66 == 0 && F_91 ( V_117 . V_122 ) != V_123 ) {
F_92 ( L_9 V_119 L_10 ,
V_4 -> V_28 . V_12 -> V_124 -> V_125 , V_114 ,
F_91 ( V_117 . V_122 ) ) ;
return - V_108 ;
} else if ( V_66 < 0 ) {
F_92 ( L_11 V_119 L_12 ,
V_4 -> V_28 . V_12 -> V_124 -> V_125 , V_114 , V_66 ) ;
return V_66 ;
}
* V_115 = F_91 ( V_117 . V_126 ) ;
return V_66 ;
}
int F_93 ( const struct V_1 * V_2 , struct V_32 * V_33 ,
const struct V_47 * V_127 ,
struct V_45 * * V_46 )
{
struct V_64 * V_65 = F_37 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_73 ;
struct V_57 * V_4 = NULL ;
struct V_62 * V_63 ;
T_2 V_115 = F_94 ( V_127 ) ;
int V_66 = 0 ;
V_8 = F_21 ( V_33 ) ;
if ( F_49 ( V_8 ) )
return F_51 ( V_8 ) ;
F_19 ( & V_8 -> V_39 ) ;
* V_46 = F_83 ( V_8 , F_95 ( V_127 ) ) ;
if ( * V_46 != NULL )
GOTO ( V_78 , V_66 = 0 ) ;
F_11 ( * V_46 ) ;
if ( * V_46 == NULL )
GOTO ( V_78 , V_66 = - V_19 ) ;
F_23 ( & ( * V_46 ) -> V_113 , 1 ) ;
F_25 ( & ( * V_46 ) -> V_51 ) ;
( * V_46 ) -> V_49 = & V_8 -> V_13 ;
F_17 ( & V_8 -> V_35 ) ;
F_27 ( & ( * V_46 ) -> V_128 , & V_8 -> V_38 ) ;
V_65 -> V_93 . V_52 = F_95 ( V_127 ) ;
V_65 -> V_93 . V_54 = V_129 ;
V_65 -> V_93 . V_56 = 0 ;
V_4 = F_47 ( V_2 , V_8 , & V_65 -> V_93 ) ;
if ( F_49 ( V_4 ) )
GOTO ( V_130 , V_66 = F_51 ( V_4 ) ) ;
if ( ! F_38 ( V_4 ) ) {
V_66 = F_86 ( V_2 , V_33 , F_95 ( V_127 ) ,
& V_115 , V_8 ) ;
if ( V_66 < 0 )
GOTO ( V_130 , V_66 ) ;
V_63 = F_50 ( V_2 , V_33 ) ;
if ( F_49 ( V_63 ) )
GOTO ( V_130 , V_66 = F_51 ( V_63 ) ) ;
V_65 -> V_95 . V_96 = V_97 | V_131 ;
V_65 -> V_95 . V_98 = V_132 | V_133 | V_134 ;
V_65 -> V_81 . V_82 = F_69 ( V_132 ) ;
V_66 = F_40 ( V_2 , V_4 , & V_65 -> V_95 , NULL ,
& V_65 -> V_81 , V_63 ) ;
if ( V_66 )
GOTO ( V_135 , V_66 ) ;
V_66 = F_39 ( V_2 , V_4 , sizeof( V_73 ) , 0 , V_63 ) ;
if ( V_66 )
GOTO ( V_135 , V_66 ) ;
V_66 = F_54 ( V_2 , V_33 , V_63 ) ;
if ( V_66 )
GOTO ( V_135 , V_66 ) ;
F_55 ( V_2 , V_4 , 0 ) ;
if ( F_38 ( V_4 ) )
GOTO ( V_136 , V_66 = 0 ) ;
V_66 = F_43 ( V_2 , V_4 , & V_65 -> V_95 , NULL , & V_65 -> V_81 ,
V_63 ) ;
if ( V_66 )
GOTO ( V_136 , V_66 ) ;
V_73 = F_44 ( V_115 ) ;
V_65 -> V_74 = 0 ;
V_65 -> V_68 . V_69 = & V_73 ;
V_65 -> V_68 . V_70 = sizeof( V_73 ) ;
V_66 = F_45 ( V_2 , V_4 , & V_65 -> V_68 , & V_65 -> V_74 , V_63 ) ;
if ( V_66 )
GOTO ( V_136 , V_66 ) ;
V_136:
F_62 ( V_2 , V_4 ) ;
V_135:
F_64 ( V_2 , V_33 , V_63 ) ;
} else {
V_65 -> V_74 = 0 ;
V_65 -> V_68 . V_69 = & V_73 ;
V_65 -> V_68 . V_70 = sizeof( V_73 ) ;
F_88 ( V_2 , V_4 , 0 ) ;
V_66 = F_89 ( V_2 , V_4 , & V_65 -> V_68 , & V_65 -> V_74 ) ;
F_90 ( V_2 , V_4 ) ;
if ( V_66 == 0 && F_96 ( V_73 ) > V_137 ) {
F_92 ( L_13 V_138 L_14 ,
V_4 -> V_28 . V_12 -> V_124 -> V_125 ,
F_96 ( V_73 ) ) ;
V_66 = - V_108 ;
}
}
V_130:
if ( V_66 != 0 ) {
F_32 ( & ( * V_46 ) -> V_128 ) ;
F_97 ( & V_8 -> V_35 ) ;
F_8 ( * V_46 ) ;
* V_46 = NULL ;
if ( V_4 != NULL && ! F_49 ( V_4 ) )
F_65 ( V_2 , & V_4 -> V_28 ) ;
} else {
( * V_46 ) -> V_53 = F_95 ( V_127 ) ;
( * V_46 ) -> V_55 = F_96 ( V_73 ) ;
( * V_46 ) -> V_50 = V_4 ;
F_98 ( ( * V_46 ) -> V_55 >= V_115 , L_15 ,
( * V_46 ) -> V_55 , V_115 ) ;
}
V_78:
F_20 ( & V_8 -> V_39 ) ;
F_28 ( V_2 , V_8 ) ;
return V_66 ;
}
void F_99 ( const struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_7 * V_8 ;
if ( ! F_29 ( & V_46 -> V_113 ) )
return;
F_10 ( V_2 ) ;
F_10 ( V_46 -> V_49 ) ;
V_8 = F_68 ( V_46 -> V_49 ) ;
F_19 ( & V_8 -> V_39 ) ;
if ( F_30 ( & V_46 -> V_113 ) == 0 ) {
if ( V_46 -> V_50 )
F_65 ( V_2 , & V_46 -> V_50 -> V_28 ) ;
F_32 ( & V_46 -> V_128 ) ;
F_8 ( V_46 ) ;
}
F_20 ( & V_8 -> V_39 ) ;
F_28 ( V_2 , V_8 ) ;
}
