static void F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 = 32 ;
F_2 (r)
V_3 = F_3 ( V_3 , V_2 -> V_4 ) ;
V_5 = F_4 ( V_3 ) - 1 ;
V_5 &= ~ 1 ;
}
int F_5 ( void )
{
int V_6 = F_6 ( V_5 ) ;
if ( V_6 == 0 )
return - V_7 ;
V_6 -- ;
V_5 &= ~ ( 1 << V_6 ) ;
return V_6 ;
}
static void F_7 ( int V_6 )
{
V_5 |= 1 << V_6 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_10 V_10 = { . V_11 = V_12 | V_13 ,
. V_14 = F_9 () ,
. V_15 = F_10 () , } ;
if ( F_11 ( V_10 . V_14 , V_16 ) &&
F_12 ( V_10 . V_15 , V_17 ) )
return 0 ;
return F_13 ( V_9 , & V_10 ) ;
}
static int F_14 ( struct V_8 * V_18 , struct V_19 * V_20 )
{
struct V_8 * V_9 ;
int V_21 ;
V_9 = F_15 ( V_18 , V_20 -> V_22 , V_20 -> V_23 ,
0 , V_20 -> V_24 , V_20 , NULL , NULL ) ;
if ( F_16 ( V_9 ) )
return F_17 ( V_9 ) ;
V_21 = F_8 ( V_9 ) ;
if ( V_21 ) {
F_18 ( V_9 ) ;
return V_21 ;
}
return 0 ;
}
static int F_19 ( struct V_8 * V_9 , struct V_19 * V_25 ,
int V_26 )
{
struct V_19 * V_20 ;
int V_21 ;
F_20 ( & V_27 ) ;
for ( V_20 = V_25 ; V_20 < V_25 + V_26 ; V_20 ++ ) {
V_21 = F_14 ( V_9 , V_20 ) ;
if ( V_21 )
goto error;
}
return 0 ;
error:
F_21 ( L_1 , V_20 -> V_22 , V_21 ) ;
while ( -- V_20 >= V_25 )
F_22 ( V_9 , V_20 -> V_22 ) ;
return V_21 ;
}
static int F_23 ( struct V_28 * V_29 , void * V_30 )
{
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_19 * V_20 = V_32 -> V_9 -> V_34 ;
if ( V_20 -> V_35 )
return V_20 -> V_35 ( V_32 , V_29 , V_30 ) ;
return 0 ;
}
static T_1 F_24 ( struct V_31 * V_32 , char * V_36 ,
T_2 V_37 , T_3 V_38 )
{
struct V_19 * V_20 = V_32 -> V_9 -> V_34 ;
if ( V_20 -> V_39 )
return V_20 -> V_39 ( V_32 , V_36 , V_37 , V_38 ) ;
return - V_40 ;
}
static bool F_25 ( struct V_31 * V_32 )
{
struct V_19 * V_20 = V_32 -> V_9 -> V_34 ;
return V_20 -> V_41 & V_42 ;
}
static int F_26 ( struct V_31 * V_32 ,
struct V_28 * V_43 , void * V_44 )
{
struct V_45 * V_46 ;
int V_21 = 0 ;
V_46 = F_27 ( V_32 -> V_9 ) ;
if ( V_46 ) {
F_28 ( V_43 , F_25 ( V_32 ) ? L_2 : L_3 ,
F_29 ( & V_46 -> V_47 ) ) ;
} else {
V_21 = - V_48 ;
}
F_30 ( V_32 -> V_9 ) ;
return V_21 ;
}
static void F_31 ( void * V_6 )
{
if ( V_6 )
F_32 ( V_49 , * ( int * ) V_6 ) ;
F_33 () ;
}
static void
F_34 ( const struct V_50 * V_47 , int * V_6 )
{
int V_51 = F_35 () ;
if ( F_36 ( V_51 , V_47 ) )
F_31 ( V_6 ) ;
F_37 ( V_47 , F_31 , V_6 , 1 ) ;
F_38 () ;
}
static T_1 F_39 ( struct V_31 * V_32 ,
char * V_36 , T_2 V_37 , T_3 V_38 )
{
T_4 V_52 , V_53 ;
struct V_45 * V_46 , * V_2 ;
int V_21 ;
if ( ! V_36 )
return - V_40 ;
if ( ! F_40 ( & V_52 , V_54 ) )
return - V_55 ;
if ( ! F_40 ( & V_53 , V_54 ) ) {
F_41 ( V_52 ) ;
return - V_55 ;
}
V_46 = F_27 ( V_32 -> V_9 ) ;
if ( ! V_46 ) {
V_21 = - V_48 ;
goto V_56;
}
if ( F_25 ( V_32 ) )
V_21 = F_42 ( V_36 , V_53 ) ;
else
V_21 = F_43 ( V_36 , V_53 ) ;
if ( V_21 )
goto V_56;
F_44 ( V_52 , V_53 , V_57 ) ;
if ( F_45 ( V_52 ) ) {
V_21 = - V_40 ;
goto V_56;
}
F_44 ( V_52 , & V_46 -> V_47 , V_53 ) ;
if ( F_45 ( V_52 ) ) {
if ( V_46 == & V_58 ) {
V_21 = - V_40 ;
goto V_56;
}
F_46 ( & V_58 . V_47 ,
& V_58 . V_47 , V_52 ) ;
F_34 ( V_52 , & V_58 . V_6 ) ;
}
F_44 ( V_52 , V_53 , & V_46 -> V_47 ) ;
if ( F_45 ( V_52 ) ) {
F_47 (r, &rdt_all_groups, rdtgroup_list) {
if ( V_2 == V_46 )
continue;
F_44 ( & V_2 -> V_47 , & V_2 -> V_47 , V_52 ) ;
}
F_34 ( V_52 , & V_46 -> V_6 ) ;
}
F_48 ( & V_46 -> V_47 , V_53 ) ;
V_56:
F_30 ( V_32 -> V_9 ) ;
F_41 ( V_52 ) ;
F_41 ( V_53 ) ;
return V_21 ? : V_37 ;
}
static void F_49 ( struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_45 * V_46 ;
V_62 = F_50 ( V_60 , struct V_61 , V_63 ) ;
V_46 = V_62 -> V_46 ;
if ( F_51 ( & V_46 -> V_64 ) &&
( V_46 -> V_41 & V_65 ) ) {
V_66 -> V_6 = 0 ;
F_52 ( V_46 ) ;
}
F_53 () ;
F_33 () ;
F_54 () ;
F_52 ( V_62 ) ;
}
static int F_55 ( struct V_67 * V_68 ,
struct V_45 * V_46 )
{
struct V_61 * V_62 ;
int V_21 ;
V_62 = F_56 ( sizeof( * V_62 ) , V_54 ) ;
if ( ! V_62 )
return - V_55 ;
V_62 -> V_63 . V_69 = F_49 ;
V_62 -> V_46 = V_46 ;
F_57 ( & V_46 -> V_64 ) ;
V_21 = F_58 ( V_68 , & V_62 -> V_63 , true ) ;
if ( V_21 ) {
F_59 ( & V_46 -> V_64 ) ;
F_52 ( V_62 ) ;
} else {
V_68 -> V_6 = V_46 -> V_6 ;
}
return V_21 ;
}
static int F_60 ( struct V_67 * V_70 ,
struct V_31 * V_32 )
{
const struct V_71 * V_72 = F_61 ( V_70 ) ;
const struct V_71 * V_71 = F_62 () ;
int V_21 = 0 ;
if ( ! F_11 ( V_71 -> V_73 , V_16 ) &&
! F_11 ( V_71 -> V_73 , V_72 -> V_74 ) &&
! F_11 ( V_71 -> V_73 , V_72 -> V_75 ) )
V_21 = - V_76 ;
F_63 ( V_72 ) ;
return V_21 ;
}
static int F_64 ( T_5 V_77 , struct V_45 * V_46 ,
struct V_31 * V_32 )
{
struct V_67 * V_68 ;
int V_21 ;
F_65 () ;
if ( V_77 ) {
V_68 = F_66 ( V_77 ) ;
if ( ! V_68 ) {
F_67 () ;
return - V_78 ;
}
} else {
V_68 = V_66 ;
}
F_68 ( V_68 ) ;
F_67 () ;
V_21 = F_60 ( V_68 , V_32 ) ;
if ( ! V_21 )
V_21 = F_55 ( V_68 , V_46 ) ;
F_69 ( V_68 ) ;
return V_21 ;
}
static T_1 F_70 ( struct V_31 * V_32 ,
char * V_36 , T_2 V_37 , T_3 V_38 )
{
struct V_45 * V_46 ;
int V_21 = 0 ;
T_5 V_77 ;
if ( F_71 ( F_72 ( V_36 ) , 0 , & V_77 ) || V_77 < 0 )
return - V_40 ;
V_46 = F_27 ( V_32 -> V_9 ) ;
if ( V_46 )
V_21 = F_64 ( V_77 , V_46 , V_32 ) ;
else
V_21 = - V_48 ;
F_30 ( V_32 -> V_9 ) ;
return V_21 ? : V_37 ;
}
static void F_73 ( struct V_45 * V_2 , struct V_28 * V_43 )
{
struct V_67 * V_79 , * V_80 ;
F_65 () ;
F_74 (p, t) {
if ( V_80 -> V_6 == V_2 -> V_6 )
F_28 ( V_43 , L_4 , V_80 -> V_77 ) ;
}
F_67 () ;
}
static int F_75 ( struct V_31 * V_32 ,
struct V_28 * V_43 , void * V_44 )
{
struct V_45 * V_46 ;
int V_21 = 0 ;
V_46 = F_27 ( V_32 -> V_9 ) ;
if ( V_46 )
F_73 ( V_46 , V_43 ) ;
else
V_21 = - V_48 ;
F_30 ( V_32 -> V_9 ) ;
return V_21 ;
}
static int F_76 ( struct V_31 * V_32 ,
struct V_28 * V_81 , void * V_44 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_82 -> V_34 ;
F_28 ( V_81 , L_4 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_77 ( struct V_31 * V_32 ,
struct V_28 * V_81 , void * V_44 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_82 -> V_34 ;
F_28 ( V_81 , L_5 , V_2 -> V_83 ) ;
return 0 ;
}
static int F_78 ( struct V_31 * V_32 ,
struct V_28 * V_81 , void * V_44 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_82 -> V_34 ;
F_28 ( V_81 , L_6 , V_2 -> V_84 . V_85 ) ;
return 0 ;
}
static int F_79 ( struct V_31 * V_32 ,
struct V_28 * V_81 , void * V_44 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_82 -> V_34 ;
F_28 ( V_81 , L_6 , V_2 -> V_86 . V_87 ) ;
return 0 ;
}
static int F_80 ( struct V_31 * V_32 ,
struct V_28 * V_81 , void * V_44 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_82 -> V_34 ;
F_28 ( V_81 , L_6 , V_2 -> V_86 . V_88 ) ;
return 0 ;
}
static int F_81 ( struct V_31 * V_32 ,
struct V_28 * V_81 , void * V_44 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_82 -> V_34 ;
F_28 ( V_81 , L_6 , V_2 -> V_86 . V_89 ) ;
return 0 ;
}
void F_82 ( struct V_1 * V_2 )
{
V_2 -> V_90 = V_91 ;
V_2 -> V_92 = F_83 ( V_91 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
V_2 -> V_90 = V_93 ;
V_2 -> V_92 = F_83 ( V_93 ) ;
}
static int F_85 ( struct V_8 * V_18 )
{
struct V_8 * V_94 ;
struct V_19 * V_95 ;
struct V_1 * V_2 ;
int V_21 , V_26 ;
V_96 = F_86 ( V_18 , L_7 , V_18 -> V_23 , NULL ) ;
if ( F_16 ( V_96 ) )
return F_17 ( V_96 ) ;
F_87 ( V_96 ) ;
F_2 (r) {
V_94 = F_86 ( V_96 , V_2 -> V_22 ,
V_96 -> V_23 , V_2 ) ;
if ( F_16 ( V_94 ) ) {
V_21 = F_17 ( V_94 ) ;
goto V_97;
}
F_87 ( V_94 ) ;
V_21 = F_8 ( V_94 ) ;
if ( V_21 )
goto V_97;
V_95 = V_2 -> V_90 ;
V_26 = V_2 -> V_92 ;
V_21 = F_19 ( V_94 , V_95 , V_26 ) ;
if ( V_21 )
goto V_97;
F_88 ( V_94 ) ;
}
F_87 ( V_96 ) ;
V_21 = F_8 ( V_96 ) ;
if ( V_21 )
goto V_97;
F_88 ( V_96 ) ;
return 0 ;
V_97:
F_18 ( V_96 ) ;
return V_21 ;
}
static void F_89 ( void * V_30 )
{
bool * V_98 = V_30 ;
F_90 ( V_99 , * V_98 ? V_100 : 0ULL ) ;
}
static int F_91 ( struct V_1 * V_2 , bool V_98 )
{
T_4 V_47 ;
struct V_101 * V_102 ;
int V_51 ;
if ( ! F_40 ( & V_47 , V_54 ) )
return - V_55 ;
F_47 (d, &r->domains, list) {
F_92 ( F_93 ( & V_102 -> V_47 ) , V_47 ) ;
}
V_51 = F_35 () ;
if ( F_36 ( V_51 , V_47 ) )
F_89 ( & V_98 ) ;
F_37 ( V_47 , F_89 , & V_98 , 1 ) ;
F_38 () ;
F_41 ( V_47 ) ;
return 0 ;
}
static int F_94 ( void )
{
struct V_1 * V_103 = & V_104 [ V_105 ] ;
struct V_1 * V_106 = & V_104 [ V_107 ] ;
struct V_1 * V_108 = & V_104 [ V_109 ] ;
int V_21 ;
if ( ! V_108 -> V_110 || ! V_103 -> V_110 || ! V_106 -> V_110 )
return - V_40 ;
V_21 = F_91 ( V_108 , true ) ;
if ( ! V_21 ) {
V_108 -> V_111 = false ;
V_103 -> V_111 = true ;
V_106 -> V_111 = true ;
}
return V_21 ;
}
static void F_95 ( void )
{
struct V_1 * V_2 = & V_104 [ V_109 ] ;
V_2 -> V_111 = V_2 -> V_110 ;
if ( V_104 [ V_105 ] . V_111 ) {
V_104 [ V_105 ] . V_111 = false ;
V_104 [ V_107 ] . V_111 = false ;
F_91 ( V_2 , false ) ;
}
}
static int F_96 ( char * V_112 )
{
char * V_113 , * V_114 = V_112 ;
int V_21 = 0 ;
while ( ( V_113 = F_97 ( & V_114 , L_8 ) ) != NULL ) {
if ( ! * V_113 )
return - V_40 ;
if ( ! strcmp ( V_113 , L_9 ) )
V_21 = F_94 () ;
}
return V_21 ;
}
static struct V_45 * F_98 ( struct V_8 * V_9 )
{
if ( F_99 ( V_9 ) == V_115 ) {
if ( V_9 == V_96 || V_9 -> V_82 == V_96 )
return NULL ;
else
return V_9 -> V_34 ;
} else {
return V_9 -> V_82 -> V_34 ;
}
}
struct V_45 * F_27 ( struct V_8 * V_9 )
{
struct V_45 * V_46 = F_98 ( V_9 ) ;
if ( ! V_46 )
return NULL ;
F_57 ( & V_46 -> V_64 ) ;
F_100 ( V_9 ) ;
F_101 ( & V_27 ) ;
if ( V_46 -> V_41 & V_65 )
return NULL ;
return V_46 ;
}
void F_30 ( struct V_8 * V_9 )
{
struct V_45 * V_46 = F_98 ( V_9 ) ;
if ( ! V_46 )
return;
F_102 ( & V_27 ) ;
if ( F_51 ( & V_46 -> V_64 ) &&
( V_46 -> V_41 & V_65 ) ) {
F_103 ( V_9 ) ;
F_104 ( V_46 -> V_9 ) ;
F_52 ( V_46 ) ;
} else {
F_103 ( V_9 ) ;
}
}
static struct V_116 * F_105 ( struct V_117 * V_118 ,
int V_41 , const char * V_119 ,
void * V_112 )
{
struct V_116 * V_116 ;
int V_21 ;
F_101 ( & V_27 ) ;
if ( F_106 ( & V_120 ) ) {
V_116 = F_107 ( - V_121 ) ;
goto V_122;
}
V_21 = F_96 ( V_112 ) ;
if ( V_21 ) {
V_116 = F_107 ( V_21 ) ;
goto V_123;
}
F_1 () ;
V_21 = F_85 ( V_58 . V_9 ) ;
if ( V_21 ) {
V_116 = F_107 ( V_21 ) ;
goto V_123;
}
V_116 = F_108 ( V_118 , V_41 , V_124 ,
V_125 , NULL ) ;
if ( F_16 ( V_116 ) )
goto V_97;
F_109 ( & V_120 ) ;
goto V_122;
V_97:
F_18 ( V_96 ) ;
V_123:
F_95 () ;
V_122:
F_102 ( & V_27 ) ;
return V_116 ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_126 V_126 ;
T_4 V_47 ;
struct V_101 * V_102 ;
int V_127 , V_51 ;
if ( ! F_40 ( & V_47 , V_54 ) )
return - V_55 ;
V_126 . V_128 = V_2 ;
V_126 . V_129 = 0 ;
V_126 . V_130 = V_2 -> V_4 ;
F_47 (d, &r->domains, list) {
F_92 ( F_93 ( & V_102 -> V_47 ) , V_47 ) ;
for ( V_127 = 0 ; V_127 < V_2 -> V_4 ; V_127 ++ )
V_102 -> V_131 [ V_127 ] = V_2 -> V_83 ;
}
V_51 = F_35 () ;
if ( F_36 ( V_51 , V_47 ) )
F_111 ( & V_126 ) ;
F_37 ( V_47 , F_111 , & V_126 , 1 ) ;
F_38 () ;
F_41 ( V_47 ) ;
return 0 ;
}
static void F_112 ( struct V_45 * V_132 , struct V_45 * V_133 ,
struct V_50 * V_134 )
{
struct V_67 * V_79 , * V_80 ;
F_113 ( & V_135 ) ;
F_74 (p, t) {
if ( ! V_132 || V_80 -> V_6 == V_132 -> V_6 ) {
V_80 -> V_6 = V_133 -> V_6 ;
#ifdef F_114
if ( V_134 && V_80 -> V_136 )
F_92 ( F_115 ( V_80 ) , V_134 ) ;
#endif
}
}
F_116 ( & V_135 ) ;
}
static void F_117 ( void )
{
struct V_45 * V_46 , * V_137 ;
F_112 ( NULL , & V_58 , NULL ) ;
F_118 (rdtgrp, tmp, &rdt_all_groups, rdtgroup_list) {
if ( V_46 == & V_58 )
continue;
F_46 ( & V_58 . V_47 ,
& V_58 . V_47 , & V_46 -> V_47 ) ;
F_18 ( V_46 -> V_9 ) ;
F_119 ( & V_46 -> V_138 ) ;
F_52 ( V_46 ) ;
}
F_120 () ;
F_34 ( V_57 , & V_58 . V_6 ) ;
F_121 () ;
F_18 ( V_96 ) ;
}
static void F_122 ( struct V_139 * V_140 )
{
struct V_1 * V_2 ;
F_101 ( & V_27 ) ;
F_2 (r)
F_110 ( V_2 ) ;
F_95 () ;
F_117 () ;
F_123 ( & V_120 ) ;
F_124 ( V_140 ) ;
F_102 ( & V_27 ) ;
}
static int F_125 ( struct V_8 * V_18 , const char * V_22 ,
T_6 V_23 )
{
struct V_45 * V_82 , * V_46 ;
struct V_8 * V_9 ;
int V_21 , V_6 ;
if ( V_18 != V_58 . V_9 )
return - V_76 ;
if ( strchr ( V_22 , '\n' ) )
return - V_40 ;
V_82 = F_27 ( V_18 ) ;
if ( ! V_82 ) {
V_21 = - V_141 ;
goto V_142;
}
V_21 = F_5 () ;
if ( V_21 < 0 )
goto V_142;
V_6 = V_21 ;
V_46 = F_56 ( sizeof( * V_46 ) , V_54 ) ;
if ( ! V_46 ) {
V_21 = - V_7 ;
goto V_143;
}
V_46 -> V_6 = V_6 ;
F_126 ( & V_46 -> V_138 , & V_144 ) ;
V_9 = F_86 ( V_82 -> V_9 , V_22 , V_23 , V_46 ) ;
if ( F_16 ( V_9 ) ) {
V_21 = F_17 ( V_9 ) ;
goto V_145;
}
V_46 -> V_9 = V_9 ;
F_87 ( V_9 ) ;
V_21 = F_8 ( V_9 ) ;
if ( V_21 )
goto V_97;
V_21 = F_19 ( V_9 , V_146 ,
F_83 ( V_146 ) ) ;
if ( V_21 )
goto V_97;
F_88 ( V_9 ) ;
V_21 = 0 ;
goto V_142;
V_97:
F_18 ( V_46 -> V_9 ) ;
V_145:
F_119 ( & V_46 -> V_138 ) ;
F_52 ( V_46 ) ;
V_143:
F_7 ( V_6 ) ;
V_142:
F_30 ( V_18 ) ;
return V_21 ;
}
static int F_127 ( struct V_8 * V_9 )
{
int V_21 , V_51 , V_6 = V_58 . V_6 ;
struct V_45 * V_46 ;
T_4 V_52 ;
if ( ! F_40 ( & V_52 , V_54 ) )
return - V_55 ;
V_46 = F_27 ( V_9 ) ;
if ( ! V_46 ) {
V_21 = - V_76 ;
goto V_122;
}
F_112 ( V_46 , & V_58 , V_52 ) ;
F_46 ( & V_58 . V_47 ,
& V_58 . V_47 , & V_46 -> V_47 ) ;
F_128 (cpu, &rdtgrp->cpu_mask)
F_129 ( V_49 , V_51 ) = V_6 ;
F_46 ( V_52 , V_52 , & V_46 -> V_47 ) ;
F_34 ( V_52 , NULL ) ;
V_46 -> V_41 = V_65 ;
F_7 ( V_46 -> V_6 ) ;
F_119 ( & V_46 -> V_138 ) ;
F_87 ( V_9 ) ;
F_18 ( V_46 -> V_9 ) ;
V_21 = 0 ;
V_122:
F_30 ( V_9 ) ;
F_41 ( V_52 ) ;
return V_21 ;
}
static int F_130 ( struct V_28 * V_81 , struct V_147 * V_148 )
{
if ( V_104 [ V_105 ] . V_111 )
F_131 ( V_81 , L_10 ) ;
return 0 ;
}
static int T_7 F_132 ( void )
{
int V_21 ;
V_124 = F_133 ( & V_149 ,
V_150 ,
& V_58 ) ;
if ( F_16 ( V_124 ) )
return F_17 ( V_124 ) ;
F_101 ( & V_27 ) ;
V_58 . V_6 = 0 ;
F_126 ( & V_58 . V_138 , & V_144 ) ;
V_21 = F_19 ( V_124 -> V_9 , V_146 ,
F_83 ( V_146 ) ) ;
if ( V_21 ) {
F_134 ( V_124 ) ;
goto V_122;
}
V_58 . V_9 = V_124 -> V_9 ;
F_88 ( V_58 . V_9 ) ;
V_122:
F_102 ( & V_27 ) ;
return V_21 ;
}
int T_7 F_135 ( void )
{
int V_21 = 0 ;
V_21 = F_132 () ;
if ( V_21 )
return V_21 ;
V_21 = F_136 ( V_151 , L_11 ) ;
if ( V_21 )
goto V_152;
V_21 = F_137 ( & V_153 ) ;
if ( V_21 )
goto V_154;
return 0 ;
V_154:
F_138 ( V_151 , L_11 ) ;
V_152:
F_134 ( V_124 ) ;
return V_21 ;
}
