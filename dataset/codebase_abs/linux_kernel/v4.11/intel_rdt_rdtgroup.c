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
static int F_25 ( struct V_31 * V_32 ,
struct V_28 * V_41 , void * V_42 )
{
struct V_43 * V_44 ;
int V_21 = 0 ;
V_44 = F_26 ( V_32 -> V_9 ) ;
if ( V_44 )
F_27 ( V_41 , L_2 , F_28 ( & V_44 -> V_45 ) ) ;
else
V_21 = - V_46 ;
F_29 ( V_32 -> V_9 ) ;
return V_21 ;
}
static void F_30 ( void * V_6 )
{
if ( V_6 )
F_31 ( V_47 , * ( int * ) V_6 ) ;
F_32 () ;
}
static void
F_33 ( const struct V_48 * V_45 , int * V_6 )
{
int V_49 = F_34 () ;
if ( F_35 ( V_49 , V_45 ) )
F_30 ( V_6 ) ;
F_36 ( V_45 , F_30 , V_6 , 1 ) ;
F_37 () ;
}
static T_1 F_38 ( struct V_31 * V_32 ,
char * V_36 , T_2 V_37 , T_3 V_38 )
{
T_4 V_50 , V_51 ;
struct V_43 * V_44 , * V_2 ;
int V_21 ;
if ( ! V_36 )
return - V_40 ;
if ( ! F_39 ( & V_50 , V_52 ) )
return - V_53 ;
if ( ! F_39 ( & V_51 , V_52 ) ) {
F_40 ( V_50 ) ;
return - V_53 ;
}
V_44 = F_26 ( V_32 -> V_9 ) ;
if ( ! V_44 ) {
V_21 = - V_46 ;
goto V_54;
}
V_21 = F_41 ( V_36 , V_51 ) ;
if ( V_21 )
goto V_54;
F_42 ( V_50 , V_51 , V_55 ) ;
if ( F_43 ( V_50 ) ) {
V_21 = - V_40 ;
goto V_54;
}
F_42 ( V_50 , & V_44 -> V_45 , V_51 ) ;
if ( F_43 ( V_50 ) ) {
if ( V_44 == & V_56 ) {
V_21 = - V_40 ;
goto V_54;
}
F_44 ( & V_56 . V_45 ,
& V_56 . V_45 , V_50 ) ;
F_33 ( V_50 , & V_56 . V_6 ) ;
}
F_42 ( V_50 , V_51 , & V_44 -> V_45 ) ;
if ( F_43 ( V_50 ) ) {
F_45 (r, &rdt_all_groups, rdtgroup_list) {
if ( V_2 == V_44 )
continue;
F_42 ( & V_2 -> V_45 , & V_2 -> V_45 , V_50 ) ;
}
F_33 ( V_50 , & V_44 -> V_6 ) ;
}
F_46 ( & V_44 -> V_45 , V_51 ) ;
V_54:
F_29 ( V_32 -> V_9 ) ;
F_40 ( V_50 ) ;
F_40 ( V_51 ) ;
return V_21 ? : V_37 ;
}
static void F_47 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
struct V_43 * V_44 ;
V_60 = F_48 ( V_58 , struct V_59 , V_61 ) ;
V_44 = V_60 -> V_44 ;
if ( F_49 ( & V_44 -> V_62 ) &&
( V_44 -> V_63 & V_64 ) ) {
V_65 -> V_6 = 0 ;
F_50 ( V_44 ) ;
}
F_51 () ;
F_32 () ;
F_52 () ;
F_50 ( V_60 ) ;
}
static int F_53 ( struct V_66 * V_67 ,
struct V_43 * V_44 )
{
struct V_59 * V_60 ;
int V_21 ;
V_60 = F_54 ( sizeof( * V_60 ) , V_52 ) ;
if ( ! V_60 )
return - V_53 ;
V_60 -> V_61 . V_68 = F_47 ;
V_60 -> V_44 = V_44 ;
F_55 ( & V_44 -> V_62 ) ;
V_21 = F_56 ( V_67 , & V_60 -> V_61 , true ) ;
if ( V_21 ) {
F_57 ( & V_44 -> V_62 ) ;
F_50 ( V_60 ) ;
} else {
V_67 -> V_6 = V_44 -> V_6 ;
}
return V_21 ;
}
static int F_58 ( struct V_66 * V_69 ,
struct V_31 * V_32 )
{
const struct V_70 * V_71 = F_59 ( V_69 ) ;
const struct V_70 * V_70 = F_60 () ;
int V_21 = 0 ;
if ( ! F_11 ( V_70 -> V_72 , V_16 ) &&
! F_11 ( V_70 -> V_72 , V_71 -> V_73 ) &&
! F_11 ( V_70 -> V_72 , V_71 -> V_74 ) )
V_21 = - V_75 ;
F_61 ( V_71 ) ;
return V_21 ;
}
static int F_62 ( T_5 V_76 , struct V_43 * V_44 ,
struct V_31 * V_32 )
{
struct V_66 * V_67 ;
int V_21 ;
F_63 () ;
if ( V_76 ) {
V_67 = F_64 ( V_76 ) ;
if ( ! V_67 ) {
F_65 () ;
return - V_77 ;
}
} else {
V_67 = V_65 ;
}
F_66 ( V_67 ) ;
F_65 () ;
V_21 = F_58 ( V_67 , V_32 ) ;
if ( ! V_21 )
V_21 = F_53 ( V_67 , V_44 ) ;
F_67 ( V_67 ) ;
return V_21 ;
}
static T_1 F_68 ( struct V_31 * V_32 ,
char * V_36 , T_2 V_37 , T_3 V_38 )
{
struct V_43 * V_44 ;
int V_21 = 0 ;
T_5 V_76 ;
if ( F_69 ( F_70 ( V_36 ) , 0 , & V_76 ) || V_76 < 0 )
return - V_40 ;
V_44 = F_26 ( V_32 -> V_9 ) ;
if ( V_44 )
V_21 = F_62 ( V_76 , V_44 , V_32 ) ;
else
V_21 = - V_46 ;
F_29 ( V_32 -> V_9 ) ;
return V_21 ? : V_37 ;
}
static void F_71 ( struct V_43 * V_2 , struct V_28 * V_41 )
{
struct V_66 * V_78 , * V_79 ;
F_63 () ;
F_72 (p, t) {
if ( V_79 -> V_6 == V_2 -> V_6 )
F_27 ( V_41 , L_3 , V_79 -> V_76 ) ;
}
F_65 () ;
}
static int F_73 ( struct V_31 * V_32 ,
struct V_28 * V_41 , void * V_42 )
{
struct V_43 * V_44 ;
int V_21 = 0 ;
V_44 = F_26 ( V_32 -> V_9 ) ;
if ( V_44 )
F_71 ( V_44 , V_41 ) ;
else
V_21 = - V_46 ;
F_29 ( V_32 -> V_9 ) ;
return V_21 ;
}
static int F_74 ( struct V_31 * V_32 ,
struct V_28 * V_80 , void * V_42 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_81 -> V_34 ;
F_27 ( V_80 , L_3 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_75 ( struct V_31 * V_32 ,
struct V_28 * V_80 , void * V_42 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_81 -> V_34 ;
F_27 ( V_80 , L_4 , V_2 -> V_82 ) ;
return 0 ;
}
static int F_76 ( struct V_31 * V_32 ,
struct V_28 * V_80 , void * V_42 )
{
struct V_1 * V_2 = V_32 -> V_9 -> V_81 -> V_34 ;
F_27 ( V_80 , L_3 , V_2 -> V_83 ) ;
return 0 ;
}
static int F_77 ( struct V_8 * V_18 )
{
struct V_8 * V_84 ;
struct V_1 * V_2 ;
int V_21 ;
V_85 = F_78 ( V_18 , L_5 , V_18 -> V_23 , NULL ) ;
if ( F_16 ( V_85 ) )
return F_17 ( V_85 ) ;
F_79 ( V_85 ) ;
F_2 (r) {
V_84 = F_78 ( V_85 , V_2 -> V_22 ,
V_85 -> V_23 , V_2 ) ;
if ( F_16 ( V_84 ) ) {
V_21 = F_17 ( V_84 ) ;
goto V_86;
}
F_79 ( V_84 ) ;
V_21 = F_8 ( V_84 ) ;
if ( V_21 )
goto V_86;
V_21 = F_19 ( V_84 , V_87 ,
F_80 ( V_87 ) ) ;
if ( V_21 )
goto V_86;
F_81 ( V_84 ) ;
}
F_79 ( V_85 ) ;
V_21 = F_8 ( V_85 ) ;
if ( V_21 )
goto V_86;
F_81 ( V_85 ) ;
return 0 ;
V_86:
F_18 ( V_85 ) ;
return V_21 ;
}
static void F_82 ( void * V_30 )
{
bool * V_88 = V_30 ;
F_83 ( V_89 , * V_88 ? V_90 : 0ULL ) ;
}
static int F_84 ( struct V_1 * V_2 , bool V_88 )
{
T_4 V_45 ;
struct V_91 * V_92 ;
int V_49 ;
if ( ! F_39 ( & V_45 , V_52 ) )
return - V_53 ;
F_45 (d, &r->domains, list) {
F_85 ( F_86 ( & V_92 -> V_45 ) , V_45 ) ;
}
V_49 = F_34 () ;
if ( F_35 ( V_49 , V_45 ) )
F_82 ( & V_88 ) ;
F_36 ( V_45 , F_82 , & V_88 , 1 ) ;
F_37 () ;
F_40 ( V_45 ) ;
return 0 ;
}
static int F_87 ( void )
{
struct V_1 * V_93 = & V_94 [ V_95 ] ;
struct V_1 * V_96 = & V_94 [ V_97 ] ;
struct V_1 * V_98 = & V_94 [ V_99 ] ;
int V_21 ;
if ( ! V_98 -> V_100 || ! V_93 -> V_100 || ! V_96 -> V_100 )
return - V_40 ;
V_21 = F_84 ( V_98 , true ) ;
if ( ! V_21 ) {
V_98 -> V_101 = false ;
V_93 -> V_101 = true ;
V_96 -> V_101 = true ;
}
return V_21 ;
}
static void F_88 ( void )
{
struct V_1 * V_2 = & V_94 [ V_99 ] ;
V_2 -> V_101 = V_2 -> V_100 ;
if ( V_94 [ V_95 ] . V_101 ) {
V_94 [ V_95 ] . V_101 = false ;
V_94 [ V_97 ] . V_101 = false ;
F_84 ( V_2 , false ) ;
}
}
static int F_89 ( char * V_102 )
{
char * V_103 , * V_104 = V_102 ;
int V_21 = 0 ;
while ( ( V_103 = F_90 ( & V_104 , L_6 ) ) != NULL ) {
if ( ! * V_103 )
return - V_40 ;
if ( ! strcmp ( V_103 , L_7 ) )
V_21 = F_87 () ;
}
return V_21 ;
}
static struct V_43 * F_91 ( struct V_8 * V_9 )
{
if ( F_92 ( V_9 ) == V_105 ) {
if ( V_9 == V_85 || V_9 -> V_81 == V_85 )
return NULL ;
else
return V_9 -> V_34 ;
} else {
return V_9 -> V_81 -> V_34 ;
}
}
struct V_43 * F_26 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = F_91 ( V_9 ) ;
if ( ! V_44 )
return NULL ;
F_55 ( & V_44 -> V_62 ) ;
F_93 ( V_9 ) ;
F_94 ( & V_27 ) ;
if ( V_44 -> V_63 & V_64 )
return NULL ;
return V_44 ;
}
void F_29 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = F_91 ( V_9 ) ;
if ( ! V_44 )
return;
F_95 ( & V_27 ) ;
if ( F_49 ( & V_44 -> V_62 ) &&
( V_44 -> V_63 & V_64 ) ) {
F_96 ( V_9 ) ;
F_97 ( V_44 -> V_9 ) ;
F_50 ( V_44 ) ;
} else {
F_96 ( V_9 ) ;
}
}
static struct V_106 * F_98 ( struct V_107 * V_108 ,
int V_63 , const char * V_109 ,
void * V_102 )
{
struct V_106 * V_106 ;
int V_21 ;
F_94 ( & V_27 ) ;
if ( F_99 ( & V_110 ) ) {
V_106 = F_100 ( - V_111 ) ;
goto V_112;
}
V_21 = F_89 ( V_102 ) ;
if ( V_21 ) {
V_106 = F_100 ( V_21 ) ;
goto V_113;
}
F_1 () ;
V_21 = F_77 ( V_56 . V_9 ) ;
if ( V_21 ) {
V_106 = F_100 ( V_21 ) ;
goto V_113;
}
V_106 = F_101 ( V_108 , V_63 , V_114 ,
V_115 , NULL ) ;
if ( F_16 ( V_106 ) )
goto V_113;
F_102 ( & V_110 ) ;
goto V_112;
V_113:
F_88 () ;
V_112:
F_95 ( & V_27 ) ;
return V_106 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_116 V_116 ;
T_4 V_45 ;
struct V_91 * V_92 ;
int V_117 , V_49 ;
if ( ! F_39 ( & V_45 , V_52 ) )
return - V_53 ;
V_116 . V_118 = V_2 ;
V_116 . V_119 = 0 ;
V_116 . V_120 = V_2 -> V_4 ;
F_45 (d, &r->domains, list) {
F_85 ( F_86 ( & V_92 -> V_45 ) , V_45 ) ;
for ( V_117 = 0 ; V_117 < V_2 -> V_4 ; V_117 ++ )
V_92 -> V_121 [ V_117 ] = V_2 -> V_82 ;
}
V_49 = F_34 () ;
if ( F_35 ( V_49 , V_45 ) )
F_104 ( & V_116 ) ;
F_36 ( V_45 , F_104 , & V_116 , 1 ) ;
F_37 () ;
F_40 ( V_45 ) ;
return 0 ;
}
static void F_105 ( struct V_43 * V_122 , struct V_43 * V_123 ,
struct V_48 * V_124 )
{
struct V_66 * V_78 , * V_79 ;
F_106 ( & V_125 ) ;
F_72 (p, t) {
if ( ! V_122 || V_79 -> V_6 == V_122 -> V_6 ) {
V_79 -> V_6 = V_123 -> V_6 ;
#ifdef F_107
if ( V_124 && V_79 -> V_126 )
F_85 ( F_108 ( V_79 ) , V_124 ) ;
#endif
}
}
F_109 ( & V_125 ) ;
}
static void F_110 ( void )
{
struct V_43 * V_44 , * V_127 ;
F_105 ( NULL , & V_56 , NULL ) ;
F_111 (rdtgrp, tmp, &rdt_all_groups, rdtgroup_list) {
if ( V_44 == & V_56 )
continue;
F_44 ( & V_56 . V_45 ,
& V_56 . V_45 , & V_44 -> V_45 ) ;
F_18 ( V_44 -> V_9 ) ;
F_112 ( & V_44 -> V_128 ) ;
F_50 ( V_44 ) ;
}
F_113 () ;
F_33 ( V_55 , & V_56 . V_6 ) ;
F_114 () ;
F_18 ( V_85 ) ;
}
static void F_115 ( struct V_129 * V_130 )
{
struct V_1 * V_2 ;
F_94 ( & V_27 ) ;
F_2 (r)
F_103 ( V_2 ) ;
F_88 () ;
F_110 () ;
F_116 ( & V_110 ) ;
F_117 ( V_130 ) ;
F_95 ( & V_27 ) ;
}
static int F_118 ( struct V_8 * V_18 , const char * V_22 ,
T_6 V_23 )
{
struct V_43 * V_81 , * V_44 ;
struct V_8 * V_9 ;
int V_21 , V_6 ;
if ( V_18 != V_56 . V_9 )
return - V_75 ;
if ( strchr ( V_22 , '\n' ) )
return - V_40 ;
V_81 = F_26 ( V_18 ) ;
if ( ! V_81 ) {
V_21 = - V_131 ;
goto V_132;
}
V_21 = F_5 () ;
if ( V_21 < 0 )
goto V_132;
V_6 = V_21 ;
V_44 = F_54 ( sizeof( * V_44 ) , V_52 ) ;
if ( ! V_44 ) {
V_21 = - V_7 ;
goto V_133;
}
V_44 -> V_6 = V_6 ;
F_119 ( & V_44 -> V_128 , & V_134 ) ;
V_9 = F_78 ( V_81 -> V_9 , V_22 , V_23 , V_44 ) ;
if ( F_16 ( V_9 ) ) {
V_21 = F_17 ( V_9 ) ;
goto V_135;
}
V_44 -> V_9 = V_9 ;
F_79 ( V_9 ) ;
V_21 = F_8 ( V_9 ) ;
if ( V_21 )
goto V_86;
V_21 = F_19 ( V_9 , V_136 ,
F_80 ( V_136 ) ) ;
if ( V_21 )
goto V_86;
F_81 ( V_9 ) ;
V_21 = 0 ;
goto V_132;
V_86:
F_18 ( V_44 -> V_9 ) ;
V_135:
F_112 ( & V_44 -> V_128 ) ;
F_50 ( V_44 ) ;
V_133:
F_7 ( V_6 ) ;
V_132:
F_29 ( V_18 ) ;
return V_21 ;
}
static int F_120 ( struct V_8 * V_9 )
{
int V_21 , V_49 , V_6 = V_56 . V_6 ;
struct V_43 * V_44 ;
T_4 V_50 ;
if ( ! F_39 ( & V_50 , V_52 ) )
return - V_53 ;
V_44 = F_26 ( V_9 ) ;
if ( ! V_44 ) {
V_21 = - V_75 ;
goto V_112;
}
F_105 ( V_44 , & V_56 , V_50 ) ;
F_44 ( & V_56 . V_45 ,
& V_56 . V_45 , & V_44 -> V_45 ) ;
F_121 (cpu, &rdtgrp->cpu_mask)
F_122 ( V_47 , V_49 ) = V_6 ;
F_44 ( V_50 , V_50 , & V_44 -> V_45 ) ;
F_33 ( V_50 , NULL ) ;
V_44 -> V_63 = V_64 ;
F_7 ( V_44 -> V_6 ) ;
F_112 ( & V_44 -> V_128 ) ;
F_79 ( V_9 ) ;
F_18 ( V_44 -> V_9 ) ;
V_21 = 0 ;
V_112:
F_29 ( V_9 ) ;
F_40 ( V_50 ) ;
return V_21 ;
}
static int F_123 ( struct V_28 * V_80 , struct V_137 * V_138 )
{
if ( V_94 [ V_95 ] . V_101 )
F_124 ( V_80 , L_8 ) ;
return 0 ;
}
static int T_7 F_125 ( void )
{
int V_21 ;
V_114 = F_126 ( & V_139 ,
V_140 ,
& V_56 ) ;
if ( F_16 ( V_114 ) )
return F_17 ( V_114 ) ;
F_94 ( & V_27 ) ;
V_56 . V_6 = 0 ;
F_119 ( & V_56 . V_128 , & V_134 ) ;
V_21 = F_19 ( V_114 -> V_9 , V_136 ,
F_80 ( V_136 ) ) ;
if ( V_21 ) {
F_127 ( V_114 ) ;
goto V_112;
}
V_56 . V_9 = V_114 -> V_9 ;
F_81 ( V_56 . V_9 ) ;
V_112:
F_95 ( & V_27 ) ;
return V_21 ;
}
int T_7 F_128 ( void )
{
int V_21 = 0 ;
V_21 = F_125 () ;
if ( V_21 )
return V_21 ;
V_21 = F_129 ( V_141 , L_9 ) ;
if ( V_21 )
goto V_142;
V_21 = F_130 ( & V_143 ) ;
if ( V_21 )
goto V_144;
return 0 ;
V_144:
F_131 ( V_141 , L_9 ) ;
V_142:
F_127 ( V_114 ) ;
return V_21 ;
}
