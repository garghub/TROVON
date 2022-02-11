static void F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 = 32 ;
F_2 (r)
V_3 = F_3 ( V_3 , V_2 -> V_4 ) ;
V_5 = F_4 ( V_3 ) - 1 ;
V_5 &= ~ 1 ;
}
static int F_5 ( void )
{
T_1 V_6 = F_6 ( V_5 ) ;
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
static int F_19 ( struct V_25 * V_26 , void * V_27 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_19 * V_20 = V_29 -> V_9 -> V_31 ;
if ( V_20 -> V_32 )
return V_20 -> V_32 ( V_29 , V_26 , V_27 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_28 * V_29 , char * V_33 ,
T_3 V_34 , T_4 V_35 )
{
struct V_19 * V_20 = V_29 -> V_9 -> V_31 ;
if ( V_20 -> V_36 )
return V_20 -> V_36 ( V_29 , V_33 , V_34 , V_35 ) ;
return - V_37 ;
}
static bool F_21 ( struct V_28 * V_29 )
{
struct V_19 * V_20 = V_29 -> V_9 -> V_31 ;
return V_20 -> V_38 & V_39 ;
}
static int F_22 ( struct V_28 * V_29 ,
struct V_25 * V_40 , void * V_41 )
{
struct V_42 * V_43 ;
int V_21 = 0 ;
V_43 = F_23 ( V_29 -> V_9 ) ;
if ( V_43 ) {
F_24 ( V_40 , F_21 ( V_29 ) ? L_1 : L_2 ,
F_25 ( & V_43 -> V_44 ) ) ;
} else {
V_21 = - V_45 ;
}
F_26 ( V_29 -> V_9 ) ;
return V_21 ;
}
static void F_27 ( void * V_46 )
{
struct V_42 * V_2 = V_46 ;
if ( V_2 ) {
F_28 ( V_47 . V_48 , V_2 -> V_6 ) ;
F_28 ( V_47 . V_49 , V_2 -> V_50 . V_51 ) ;
}
F_29 () ;
}
static void
F_30 ( const struct V_52 * V_44 , struct V_42 * V_2 )
{
int V_53 = F_31 () ;
if ( F_32 ( V_53 , V_44 ) )
F_27 ( V_2 ) ;
F_33 ( V_44 , F_27 , V_2 , 1 ) ;
F_34 () ;
}
static int F_35 ( struct V_42 * V_43 , T_5 V_54 ,
T_5 V_55 )
{
struct V_42 * V_56 = V_43 -> V_50 . V_57 , * V_58 ;
struct V_59 * V_60 ;
F_36 ( V_55 , V_54 , & V_56 -> V_44 ) ;
if ( F_37 ( V_55 ) )
return - V_37 ;
F_36 ( V_55 , & V_43 -> V_44 , V_54 ) ;
if ( F_37 ( V_55 ) ) {
F_38 ( & V_56 -> V_44 , & V_56 -> V_44 , V_55 ) ;
F_30 ( V_55 , V_56 ) ;
}
F_36 ( V_55 , V_54 , & V_43 -> V_44 ) ;
if ( F_37 ( V_55 ) ) {
V_60 = & V_56 -> V_50 . V_61 ;
F_39 (crgrp, head, mon.crdtgrp_list) {
if ( V_58 == V_43 )
continue;
F_36 ( & V_58 -> V_44 , & V_58 -> V_44 ,
V_55 ) ;
}
F_30 ( V_55 , V_43 ) ;
}
F_40 ( & V_43 -> V_44 , V_54 ) ;
return 0 ;
}
static void F_41 ( struct V_42 * V_2 , struct V_52 * V_26 )
{
struct V_42 * V_58 ;
F_36 ( & V_2 -> V_44 , & V_2 -> V_44 , V_26 ) ;
F_39 (crgrp, &r->mon.crdtgrp_list, mon.crdtgrp_list)
F_42 ( & V_58 -> V_44 , & V_2 -> V_44 , & V_58 -> V_44 ) ;
}
static int F_43 ( struct V_42 * V_43 , T_5 V_54 ,
T_5 V_55 , T_5 V_62 )
{
struct V_42 * V_2 , * V_58 ;
struct V_59 * V_60 ;
F_36 ( V_55 , & V_43 -> V_44 , V_54 ) ;
if ( F_37 ( V_55 ) ) {
if ( V_43 == & V_63 )
return - V_37 ;
F_38 ( & V_63 . V_44 ,
& V_63 . V_44 , V_55 ) ;
F_30 ( V_55 , & V_63 ) ;
}
F_36 ( V_55 , V_54 , & V_43 -> V_44 ) ;
if ( F_37 ( V_55 ) ) {
F_39 (r, &rdt_all_groups, rdtgroup_list) {
if ( V_2 == V_43 )
continue;
F_42 ( V_62 , & V_2 -> V_44 , V_55 ) ;
if ( F_37 ( V_62 ) )
F_41 ( V_2 , V_62 ) ;
}
F_30 ( V_55 , V_43 ) ;
}
F_40 ( & V_43 -> V_44 , V_54 ) ;
V_60 = & V_43 -> V_50 . V_61 ;
F_39 (crgrp, head, mon.crdtgrp_list) {
F_42 ( V_55 , & V_43 -> V_44 , & V_58 -> V_44 ) ;
F_30 ( V_55 , V_43 ) ;
F_44 ( & V_58 -> V_44 ) ;
}
return 0 ;
}
static T_2 F_45 ( struct V_28 * V_29 ,
char * V_33 , T_3 V_34 , T_4 V_35 )
{
T_5 V_55 , V_54 , V_62 ;
struct V_42 * V_43 ;
int V_21 ;
if ( ! V_33 )
return - V_37 ;
if ( ! F_46 ( & V_55 , V_64 ) )
return - V_65 ;
if ( ! F_46 ( & V_54 , V_64 ) ) {
F_47 ( V_55 ) ;
return - V_65 ;
}
if ( ! F_46 ( & V_62 , V_64 ) ) {
F_47 ( V_55 ) ;
F_47 ( V_54 ) ;
return - V_65 ;
}
V_43 = F_23 ( V_29 -> V_9 ) ;
if ( ! V_43 ) {
V_21 = - V_45 ;
goto V_66;
}
if ( F_21 ( V_29 ) )
V_21 = F_48 ( V_33 , V_54 ) ;
else
V_21 = F_49 ( V_33 , V_54 ) ;
if ( V_21 )
goto V_66;
F_36 ( V_55 , V_54 , V_67 ) ;
if ( F_37 ( V_55 ) ) {
V_21 = - V_37 ;
goto V_66;
}
if ( V_43 -> type == V_68 )
V_21 = F_43 ( V_43 , V_54 , V_55 , V_62 ) ;
else if ( V_43 -> type == V_69 )
V_21 = F_35 ( V_43 , V_54 , V_55 ) ;
else
V_21 = - V_37 ;
V_66:
F_26 ( V_29 -> V_9 ) ;
F_47 ( V_55 ) ;
F_47 ( V_54 ) ;
F_47 ( V_62 ) ;
return V_21 ? : V_34 ;
}
static void F_50 ( struct V_70 * V_60 )
{
struct V_71 * V_72 ;
struct V_42 * V_43 ;
V_72 = F_51 ( V_60 , struct V_71 , V_73 ) ;
V_43 = V_72 -> V_43 ;
if ( F_52 ( & V_43 -> V_74 ) &&
( V_43 -> V_38 & V_75 ) ) {
V_76 -> V_6 = 0 ;
V_76 -> V_51 = 0 ;
F_53 ( V_43 ) ;
}
F_54 () ;
F_29 () ;
F_55 () ;
F_53 ( V_72 ) ;
}
static int F_56 ( struct V_77 * V_78 ,
struct V_42 * V_43 )
{
struct V_71 * V_72 ;
int V_21 ;
V_72 = F_57 ( sizeof( * V_72 ) , V_64 ) ;
if ( ! V_72 )
return - V_65 ;
V_72 -> V_73 . V_79 = F_50 ;
V_72 -> V_43 = V_43 ;
F_58 ( & V_43 -> V_74 ) ;
V_21 = F_59 ( V_78 , & V_72 -> V_73 , true ) ;
if ( V_21 ) {
F_60 ( & V_43 -> V_74 ) ;
F_53 ( V_72 ) ;
} else {
if ( V_43 -> type == V_68 ) {
V_78 -> V_6 = V_43 -> V_6 ;
V_78 -> V_51 = V_43 -> V_50 . V_51 ;
} else if ( V_43 -> type == V_69 ) {
if ( V_43 -> V_50 . V_57 -> V_6 == V_78 -> V_6 )
V_78 -> V_51 = V_43 -> V_50 . V_51 ;
else
V_21 = - V_37 ;
}
}
return V_21 ;
}
static int F_61 ( struct V_77 * V_80 ,
struct V_28 * V_29 )
{
const struct V_81 * V_82 = F_62 ( V_80 ) ;
const struct V_81 * V_81 = F_63 () ;
int V_21 = 0 ;
if ( ! F_11 ( V_81 -> V_83 , V_16 ) &&
! F_11 ( V_81 -> V_83 , V_82 -> V_84 ) &&
! F_11 ( V_81 -> V_83 , V_82 -> V_85 ) )
V_21 = - V_86 ;
F_64 ( V_82 ) ;
return V_21 ;
}
static int F_65 ( T_6 V_87 , struct V_42 * V_43 ,
struct V_28 * V_29 )
{
struct V_77 * V_78 ;
int V_21 ;
F_66 () ;
if ( V_87 ) {
V_78 = F_67 ( V_87 ) ;
if ( ! V_78 ) {
F_68 () ;
return - V_88 ;
}
} else {
V_78 = V_76 ;
}
F_69 ( V_78 ) ;
F_68 () ;
V_21 = F_61 ( V_78 , V_29 ) ;
if ( ! V_21 )
V_21 = F_56 ( V_78 , V_43 ) ;
F_70 ( V_78 ) ;
return V_21 ;
}
static T_2 F_71 ( struct V_28 * V_29 ,
char * V_33 , T_3 V_34 , T_4 V_35 )
{
struct V_42 * V_43 ;
int V_21 = 0 ;
T_6 V_87 ;
if ( F_72 ( F_73 ( V_33 ) , 0 , & V_87 ) || V_87 < 0 )
return - V_37 ;
V_43 = F_23 ( V_29 -> V_9 ) ;
if ( V_43 )
V_21 = F_65 ( V_87 , V_43 , V_29 ) ;
else
V_21 = - V_45 ;
F_26 ( V_29 -> V_9 ) ;
return V_21 ? : V_34 ;
}
static void F_74 ( struct V_42 * V_2 , struct V_25 * V_40 )
{
struct V_77 * V_89 , * V_90 ;
F_66 () ;
F_75 (p, t) {
if ( ( V_2 -> type == V_68 && V_90 -> V_6 == V_2 -> V_6 ) ||
( V_2 -> type == V_69 && V_90 -> V_51 == V_2 -> V_50 . V_51 ) )
F_24 ( V_40 , L_3 , V_90 -> V_87 ) ;
}
F_68 () ;
}
static int F_76 ( struct V_28 * V_29 ,
struct V_25 * V_40 , void * V_41 )
{
struct V_42 * V_43 ;
int V_21 = 0 ;
V_43 = F_23 ( V_29 -> V_9 ) ;
if ( V_43 )
F_74 ( V_43 , V_40 ) ;
else
V_21 = - V_45 ;
F_26 ( V_29 -> V_9 ) ;
return V_21 ;
}
static int F_77 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_3 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_78 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_4 , V_2 -> V_92 ) ;
return 0 ;
}
static int F_79 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_5 , V_2 -> V_93 . V_94 ) ;
return 0 ;
}
static int F_80 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_4 , V_2 -> V_93 . V_95 ) ;
return 0 ;
}
static int F_81 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_5 , V_2 -> V_96 . V_97 ) ;
return 0 ;
}
static int F_82 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_3 , V_2 -> V_98 ) ;
return 0 ;
}
static int F_83 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
struct V_99 * V_100 ;
F_39 (mevt, &r->evt_list, list)
F_24 ( V_91 , L_6 , V_100 -> V_22 ) ;
return 0 ;
}
static int F_84 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_5 , V_2 -> V_96 . V_101 ) ;
return 0 ;
}
static int F_85 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_5 , V_2 -> V_96 . V_102 ) ;
return 0 ;
}
static int F_86 ( struct V_28 * V_29 ,
struct V_25 * V_91 , void * V_41 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
F_24 ( V_91 , L_5 , V_103 * V_2 -> V_104 ) ;
return 0 ;
}
static T_2 F_87 ( struct V_28 * V_29 ,
char * V_33 , T_3 V_34 , T_4 V_35 )
{
struct V_1 * V_2 = V_29 -> V_9 -> V_57 -> V_31 ;
unsigned int V_105 ;
int V_21 ;
V_21 = F_88 ( V_33 , 0 , & V_105 ) ;
if ( V_21 )
return V_21 ;
if ( V_105 > ( V_106 . V_107 * 1024 ) )
return - V_37 ;
V_103 = V_105 / V_2 -> V_104 ;
return V_34 ;
}
static int F_89 ( struct V_8 * V_9 , unsigned long V_108 )
{
struct V_19 * V_109 , * V_20 ;
int V_21 , V_110 ;
V_109 = V_111 ;
V_110 = F_90 ( V_111 ) ;
F_91 ( & V_112 ) ;
for ( V_20 = V_109 ; V_20 < V_109 + V_110 ; V_20 ++ ) {
if ( ( V_108 & V_20 -> V_108 ) == V_20 -> V_108 ) {
V_21 = F_14 ( V_9 , V_20 ) ;
if ( V_21 )
goto error;
}
}
return 0 ;
error:
F_92 ( L_7 , V_20 -> V_22 , V_21 ) ;
while ( -- V_20 >= V_109 ) {
if ( ( V_108 & V_20 -> V_108 ) == V_20 -> V_108 )
F_93 ( V_9 , V_20 -> V_22 ) ;
}
return V_21 ;
}
static int F_94 ( struct V_1 * V_2 , char * V_22 ,
unsigned long V_108 )
{
struct V_8 * V_113 ;
int V_21 ;
V_113 = F_95 ( V_114 , V_22 ,
V_114 -> V_23 , V_2 ) ;
if ( F_16 ( V_113 ) )
return F_17 ( V_113 ) ;
F_96 ( V_113 ) ;
V_21 = F_8 ( V_113 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_89 ( V_113 , V_108 ) ;
if ( ! V_21 )
F_97 ( V_113 ) ;
return V_21 ;
}
static int F_98 ( struct V_8 * V_18 )
{
struct V_1 * V_2 ;
unsigned long V_108 ;
char V_22 [ 32 ] ;
int V_21 ;
V_114 = F_95 ( V_18 , L_8 , V_18 -> V_23 , NULL ) ;
if ( F_16 ( V_114 ) )
return F_17 ( V_114 ) ;
F_96 ( V_114 ) ;
F_2 (r) {
V_108 = V_2 -> V_108 | V_115 ;
V_21 = F_94 ( V_2 , V_2 -> V_22 , V_108 ) ;
if ( V_21 )
goto V_116;
}
F_99 (r) {
V_108 = V_2 -> V_108 | V_117 ;
sprintf ( V_22 , L_9 , V_2 -> V_22 ) ;
V_21 = F_94 ( V_2 , V_22 , V_108 ) ;
if ( V_21 )
goto V_116;
}
F_96 ( V_114 ) ;
V_21 = F_8 ( V_114 ) ;
if ( V_21 )
goto V_116;
F_97 ( V_114 ) ;
return 0 ;
V_116:
F_18 ( V_114 ) ;
return V_21 ;
}
static int
F_100 ( struct V_8 * V_18 , struct V_42 * V_56 ,
char * V_22 , struct V_8 * * V_118 )
{
struct V_8 * V_9 ;
int V_21 ;
V_9 = F_95 ( V_18 , V_22 , V_18 -> V_23 , V_56 ) ;
if ( F_16 ( V_9 ) )
return F_17 ( V_9 ) ;
if ( V_118 )
* V_118 = V_9 ;
F_96 ( V_9 ) ;
V_21 = F_8 ( V_9 ) ;
if ( V_21 )
goto V_116;
F_97 ( V_9 ) ;
return 0 ;
V_116:
F_18 ( V_9 ) ;
return V_21 ;
}
static void F_101 ( void * V_27 )
{
bool * V_119 = V_27 ;
F_102 ( V_120 , * V_119 ? V_121 : 0ULL ) ;
}
static int F_103 ( struct V_1 * V_2 , bool V_119 )
{
T_5 V_44 ;
struct V_122 * V_123 ;
int V_53 ;
if ( ! F_46 ( & V_44 , V_64 ) )
return - V_65 ;
F_39 (d, &r->domains, list) {
F_104 ( F_105 ( & V_123 -> V_44 ) , V_44 ) ;
}
V_53 = F_31 () ;
if ( F_32 ( V_53 , V_44 ) )
F_101 ( & V_119 ) ;
F_33 ( V_44 , F_101 , & V_119 , 1 ) ;
F_34 () ;
F_47 ( V_44 ) ;
return 0 ;
}
static int F_106 ( void )
{
struct V_1 * V_124 = & V_125 [ V_126 ] ;
struct V_1 * V_127 = & V_125 [ V_128 ] ;
struct V_1 * V_129 = & V_125 [ V_130 ] ;
int V_21 ;
if ( ! V_129 -> V_131 || ! V_124 -> V_131 ||
! V_127 -> V_131 )
return - V_37 ;
V_21 = F_103 ( V_129 , true ) ;
if ( ! V_21 ) {
V_129 -> V_132 = false ;
V_124 -> V_132 = true ;
V_127 -> V_132 = true ;
}
return V_21 ;
}
static void F_107 ( void )
{
struct V_1 * V_2 = & V_125 [ V_130 ] ;
V_2 -> V_132 = V_2 -> V_131 ;
if ( V_125 [ V_126 ] . V_132 ) {
V_125 [ V_126 ] . V_132 = false ;
V_125 [ V_128 ] . V_132 = false ;
F_103 ( V_2 , false ) ;
}
}
static int F_108 ( char * V_133 )
{
char * V_134 , * V_135 = V_133 ;
int V_21 = 0 ;
while ( ( V_134 = F_109 ( & V_135 , L_10 ) ) != NULL ) {
if ( ! * V_134 )
return - V_37 ;
if ( ! strcmp ( V_134 , L_11 ) )
V_21 = F_106 () ;
}
return V_21 ;
}
static struct V_42 * F_110 ( struct V_8 * V_9 )
{
if ( F_111 ( V_9 ) == V_136 ) {
if ( V_9 == V_114 || V_9 -> V_57 == V_114 )
return NULL ;
else
return V_9 -> V_31 ;
} else {
return V_9 -> V_57 -> V_31 ;
}
}
struct V_42 * F_23 ( struct V_8 * V_9 )
{
struct V_42 * V_43 = F_110 ( V_9 ) ;
if ( ! V_43 )
return NULL ;
F_58 ( & V_43 -> V_74 ) ;
F_112 ( V_9 ) ;
F_113 ( & V_112 ) ;
if ( V_43 -> V_38 & V_75 )
return NULL ;
return V_43 ;
}
void F_26 ( struct V_8 * V_9 )
{
struct V_42 * V_43 = F_110 ( V_9 ) ;
if ( ! V_43 )
return;
F_114 ( & V_112 ) ;
if ( F_52 ( & V_43 -> V_74 ) &&
( V_43 -> V_38 & V_75 ) ) {
F_115 ( V_9 ) ;
F_116 ( V_43 -> V_9 ) ;
F_53 ( V_43 ) ;
} else {
F_115 ( V_9 ) ;
}
}
static struct V_137 * F_117 ( struct V_138 * V_139 ,
int V_38 , const char * V_140 ,
void * V_133 )
{
struct V_122 * V_141 ;
struct V_1 * V_2 ;
struct V_137 * V_137 ;
int V_21 ;
F_113 ( & V_112 ) ;
if ( F_118 ( & V_142 ) ) {
V_137 = F_119 ( - V_143 ) ;
goto V_144;
}
V_21 = F_108 ( V_133 ) ;
if ( V_21 ) {
V_137 = F_119 ( V_21 ) ;
goto V_145;
}
F_1 () ;
V_21 = F_98 ( V_63 . V_9 ) ;
if ( V_21 ) {
V_137 = F_119 ( V_21 ) ;
goto V_145;
}
if ( V_146 ) {
V_21 = F_100 ( V_63 . V_9 ,
NULL , L_12 ,
& V_147 ) ;
if ( V_21 ) {
V_137 = F_119 ( V_21 ) ;
goto V_148;
}
F_96 ( V_147 ) ;
V_21 = F_120 ( V_63 . V_9 ,
& V_63 , & V_149 ) ;
if ( V_21 ) {
V_137 = F_119 ( V_21 ) ;
goto V_150;
}
F_96 ( V_149 ) ;
V_63 . V_50 . V_151 = V_149 ;
}
V_137 = F_121 ( V_139 , V_38 , V_152 ,
V_153 , NULL ) ;
if ( F_16 ( V_137 ) )
goto V_154;
if ( V_155 )
F_122 ( & V_156 ) ;
if ( V_146 )
F_122 ( & V_157 ) ;
if ( V_155 || V_146 )
F_122 ( & V_142 ) ;
if ( F_123 () ) {
V_2 = & V_125 [ V_130 ] ;
F_39 (dom, &r->domains, list)
F_124 ( V_141 , V_158 ) ;
}
goto V_144;
V_154:
if ( V_146 )
F_18 ( V_149 ) ;
V_150:
if ( V_146 )
F_18 ( V_147 ) ;
V_148:
F_18 ( V_114 ) ;
V_145:
F_107 () ;
V_144:
F_114 ( & V_112 ) ;
return V_137 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_159 V_159 ;
T_5 V_44 ;
struct V_122 * V_123 ;
int V_160 , V_53 ;
if ( ! F_46 ( & V_44 , V_64 ) )
return - V_65 ;
V_159 . V_161 = V_2 ;
V_159 . V_162 = 0 ;
V_159 . V_163 = V_2 -> V_4 ;
F_39 (d, &r->domains, list) {
F_104 ( F_105 ( & V_123 -> V_44 ) , V_44 ) ;
for ( V_160 = 0 ; V_160 < V_2 -> V_4 ; V_160 ++ )
V_123 -> V_164 [ V_160 ] = V_2 -> V_92 ;
}
V_53 = F_31 () ;
if ( F_32 ( V_53 , V_44 ) )
F_126 ( & V_159 ) ;
F_33 ( V_44 , F_126 , & V_159 , 1 ) ;
F_34 () ;
F_47 ( V_44 ) ;
return 0 ;
}
static bool F_127 ( struct V_77 * V_90 , struct V_42 * V_2 )
{
return ( V_155 &&
( V_2 -> type == V_68 ) && ( V_90 -> V_6 == V_2 -> V_6 ) ) ;
}
static bool F_128 ( struct V_77 * V_90 , struct V_42 * V_2 )
{
return ( V_146 &&
( V_2 -> type == V_69 ) && ( V_90 -> V_51 == V_2 -> V_50 . V_51 ) ) ;
}
static void F_129 ( struct V_42 * V_165 , struct V_42 * V_166 ,
struct V_52 * V_167 )
{
struct V_77 * V_89 , * V_90 ;
F_130 ( & V_168 ) ;
F_75 (p, t) {
if ( ! V_165 || F_127 ( V_90 , V_165 ) ||
F_128 ( V_90 , V_165 ) ) {
V_90 -> V_6 = V_166 -> V_6 ;
V_90 -> V_51 = V_166 -> V_50 . V_51 ;
#ifdef F_131
if ( V_167 && V_90 -> V_169 )
F_104 ( F_132 ( V_90 ) , V_167 ) ;
#endif
}
}
F_133 ( & V_168 ) ;
}
static void F_134 ( struct V_42 * V_43 )
{
struct V_42 * V_170 , * V_171 ;
struct V_59 * V_60 ;
V_60 = & V_43 -> V_50 . V_61 ;
F_135 (sentry, stmp, head, mon.crdtgrp_list) {
F_136 ( V_170 -> V_50 . V_51 ) ;
F_137 ( & V_170 -> V_50 . V_61 ) ;
F_53 ( V_170 ) ;
}
}
static void F_138 ( void )
{
struct V_42 * V_43 , * V_172 ;
F_129 ( NULL , & V_63 , NULL ) ;
F_135 (rdtgrp, tmp, &rdt_all_groups, rdtgroup_list) {
F_134 ( V_43 ) ;
if ( V_43 == & V_63 )
continue;
F_38 ( & V_63 . V_44 ,
& V_63 . V_44 , & V_43 -> V_44 ) ;
F_136 ( V_43 -> V_50 . V_51 ) ;
F_18 ( V_43 -> V_9 ) ;
F_137 ( & V_43 -> V_173 ) ;
F_53 ( V_43 ) ;
}
F_139 () ;
F_30 ( V_67 , & V_63 ) ;
F_140 () ;
F_18 ( V_114 ) ;
F_18 ( V_147 ) ;
F_18 ( V_149 ) ;
}
static void F_141 ( struct V_174 * V_175 )
{
struct V_1 * V_2 ;
F_113 ( & V_112 ) ;
F_2 (r)
F_125 ( V_2 ) ;
F_107 () ;
F_138 () ;
F_142 ( & V_156 ) ;
F_142 ( & V_157 ) ;
F_142 ( & V_142 ) ;
F_143 ( V_175 ) ;
F_114 ( & V_112 ) ;
}
static int F_144 ( struct V_8 * V_18 , const char * V_22 ,
void * V_31 )
{
struct V_8 * V_9 ;
int V_21 = 0 ;
V_9 = F_15 ( V_18 , V_22 , 0444 , 0 ,
& V_176 , V_31 , NULL , NULL ) ;
if ( F_16 ( V_9 ) )
return F_17 ( V_9 ) ;
V_21 = F_8 ( V_9 ) ;
if ( V_21 ) {
F_18 ( V_9 ) ;
return V_21 ;
}
return V_21 ;
}
void F_145 ( struct V_1 * V_2 , unsigned int V_177 )
{
struct V_42 * V_56 , * V_58 ;
char V_22 [ 32 ] ;
if ( ! V_2 -> V_178 )
return;
F_39 (prgrp, &rdt_all_groups, rdtgroup_list) {
sprintf ( V_22 , L_13 , V_2 -> V_22 , V_177 ) ;
F_93 ( V_56 -> V_50 . V_151 , V_22 ) ;
F_39 (crgrp, &prgrp->mon.crdtgrp_list, mon.crdtgrp_list)
F_93 ( V_58 -> V_50 . V_151 , V_22 ) ;
}
}
static int F_146 ( struct V_8 * V_18 ,
struct V_122 * V_123 ,
struct V_1 * V_2 , struct V_42 * V_56 )
{
union V_179 V_31 ;
struct V_8 * V_9 ;
struct V_99 * V_100 ;
struct V_180 V_181 ;
char V_22 [ 32 ] ;
int V_21 ;
sprintf ( V_22 , L_13 , V_2 -> V_22 , V_123 -> V_182 ) ;
V_9 = F_95 ( V_18 , V_22 , V_18 -> V_23 , V_56 ) ;
if ( F_16 ( V_9 ) )
return F_17 ( V_9 ) ;
F_96 ( V_9 ) ;
V_21 = F_8 ( V_9 ) ;
if ( V_21 )
goto V_116;
if ( F_147 ( F_148 ( & V_2 -> V_183 ) ) ) {
V_21 = - V_86 ;
goto V_116;
}
V_31 . V_184 . V_185 = V_2 -> V_185 ;
V_31 . V_184 . V_186 = V_123 -> V_182 ;
F_39 (mevt, &r->evt_list, list) {
V_31 . V_184 . V_187 = V_100 -> V_187 ;
V_21 = F_144 ( V_9 , V_100 -> V_22 , V_31 . V_31 ) ;
if ( V_21 )
goto V_116;
if ( F_149 ( V_100 -> V_187 ) )
F_150 ( & V_181 , V_123 , V_56 , V_100 -> V_187 , true ) ;
}
F_97 ( V_9 ) ;
return 0 ;
V_116:
F_18 ( V_9 ) ;
return V_21 ;
}
void F_151 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_8 * V_18 ;
struct V_42 * V_56 , * V_58 ;
struct V_59 * V_60 ;
if ( ! V_2 -> V_178 )
return;
F_39 (prgrp, &rdt_all_groups, rdtgroup_list) {
V_18 = V_56 -> V_50 . V_151 ;
F_146 ( V_18 , V_123 , V_2 , V_56 ) ;
V_60 = & V_56 -> V_50 . V_61 ;
F_39 (crgrp, head, mon.crdtgrp_list) {
V_18 = V_58 -> V_50 . V_151 ;
F_146 ( V_18 , V_123 , V_2 , V_58 ) ;
}
}
}
static int F_152 ( struct V_8 * V_18 ,
struct V_1 * V_2 ,
struct V_42 * V_56 )
{
struct V_122 * V_141 ;
int V_21 ;
F_39 (dom, &r->domains, list) {
V_21 = F_146 ( V_18 , V_141 , V_2 , V_56 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_120 ( struct V_8 * V_18 ,
struct V_42 * V_56 ,
struct V_8 * * V_118 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_21 ;
V_21 = F_100 ( V_18 , NULL , L_14 , & V_9 ) ;
if ( V_21 )
return V_21 ;
if ( V_118 )
* V_118 = V_9 ;
F_99 (r) {
V_21 = F_152 ( V_9 , V_2 , V_56 ) ;
if ( V_21 )
goto V_116;
}
return 0 ;
V_116:
F_18 ( V_9 ) ;
return V_21 ;
}
static int F_153 ( struct V_8 * V_18 ,
struct V_8 * V_188 ,
const char * V_22 , T_7 V_23 ,
enum V_189 V_190 , struct V_42 * * V_2 )
{
struct V_42 * V_191 , * V_43 ;
struct V_8 * V_9 ;
T_8 V_192 = 0 ;
int V_21 ;
V_191 = F_23 ( V_188 ) ;
if ( ! V_191 ) {
V_21 = - V_193 ;
goto V_194;
}
V_43 = F_57 ( sizeof( * V_43 ) , V_64 ) ;
if ( ! V_43 ) {
V_21 = - V_7 ;
goto V_194;
}
* V_2 = V_43 ;
V_43 -> V_50 . V_57 = V_191 ;
V_43 -> type = V_190 ;
F_154 ( & V_43 -> V_50 . V_61 ) ;
V_9 = F_95 ( V_18 , V_22 , V_23 , V_43 ) ;
if ( F_16 ( V_9 ) ) {
V_21 = F_17 ( V_9 ) ;
goto V_195;
}
V_43 -> V_9 = V_9 ;
F_96 ( V_9 ) ;
V_21 = F_8 ( V_9 ) ;
if ( V_21 )
goto V_116;
V_192 = V_196 | V_197 ;
V_192 = V_196 | F_155 ( V_198 + V_190 ) ;
V_21 = F_89 ( V_9 , V_192 ) ;
if ( V_21 )
goto V_116;
if ( V_146 ) {
V_21 = F_156 () ;
if ( V_21 < 0 )
goto V_116;
V_43 -> V_50 . V_51 = V_21 ;
V_21 = F_120 ( V_9 , V_43 , & V_43 -> V_50 . V_151 ) ;
if ( V_21 )
goto V_199;
}
F_97 ( V_9 ) ;
return 0 ;
V_199:
F_136 ( V_43 -> V_50 . V_51 ) ;
V_116:
F_18 ( V_43 -> V_9 ) ;
V_195:
F_53 ( V_43 ) ;
V_194:
F_26 ( V_188 ) ;
return V_21 ;
}
static void F_157 ( struct V_42 * V_200 )
{
F_18 ( V_200 -> V_9 ) ;
F_136 ( V_200 -> V_50 . V_51 ) ;
F_53 ( V_200 ) ;
}
static int F_158 ( struct V_8 * V_18 ,
struct V_8 * V_188 ,
const char * V_22 ,
T_7 V_23 )
{
struct V_42 * V_43 , * V_56 ;
int V_21 ;
V_21 = F_153 ( V_18 , V_188 , V_22 , V_23 , V_69 ,
& V_43 ) ;
if ( V_21 )
return V_21 ;
V_56 = V_43 -> V_50 . V_57 ;
V_43 -> V_6 = V_56 -> V_6 ;
F_159 ( & V_43 -> V_50 . V_61 , & V_56 -> V_50 . V_61 ) ;
F_26 ( V_188 ) ;
return V_21 ;
}
static int F_160 ( struct V_8 * V_18 ,
struct V_8 * V_188 ,
const char * V_22 , T_7 V_23 )
{
struct V_42 * V_43 ;
struct V_8 * V_9 ;
T_1 V_6 ;
int V_21 ;
V_21 = F_153 ( V_18 , V_188 , V_22 , V_23 , V_68 ,
& V_43 ) ;
if ( V_21 )
return V_21 ;
V_9 = V_43 -> V_9 ;
V_21 = F_5 () ;
if ( V_21 < 0 )
goto V_201;
V_6 = V_21 ;
V_43 -> V_6 = V_6 ;
F_161 ( & V_43 -> V_173 , & V_202 ) ;
if ( V_146 ) {
V_21 = F_100 ( V_9 , NULL , L_12 , NULL ) ;
if ( V_21 )
goto V_203;
}
goto V_194;
V_203:
F_7 ( V_6 ) ;
F_137 ( & V_43 -> V_173 ) ;
V_201:
F_157 ( V_43 ) ;
V_194:
F_26 ( V_188 ) ;
return V_21 ;
}
static bool F_162 ( struct V_8 * V_9 , const char * V_22 )
{
return ( ! strcmp ( V_9 -> V_22 , L_12 ) &&
strcmp ( V_22 , L_12 ) ) ;
}
static int F_163 ( struct V_8 * V_18 , const char * V_22 ,
T_7 V_23 )
{
if ( strchr ( V_22 , '\n' ) )
return - V_37 ;
if ( V_155 && V_18 == V_63 . V_9 )
return F_160 ( V_18 , V_18 , V_22 , V_23 ) ;
if ( V_146 && F_162 ( V_18 , V_22 ) )
return F_158 ( V_18 , V_18 -> V_57 , V_22 , V_23 ) ;
return - V_86 ;
}
static int F_164 ( struct V_8 * V_9 , struct V_42 * V_43 ,
T_5 V_55 )
{
struct V_42 * V_191 = V_43 -> V_50 . V_57 ;
int V_53 ;
F_129 ( V_43 , V_191 , V_55 ) ;
F_165 (cpu, &rdtgrp->cpu_mask)
F_166 ( V_47 . V_49 , V_53 ) = V_191 -> V_50 . V_51 ;
F_38 ( V_55 , V_55 , & V_43 -> V_44 ) ;
F_30 ( V_55 , NULL ) ;
V_43 -> V_38 = V_75 ;
F_136 ( V_43 -> V_50 . V_51 ) ;
F_147 ( F_148 ( & V_191 -> V_50 . V_61 ) ) ;
F_137 ( & V_43 -> V_50 . V_61 ) ;
F_96 ( V_9 ) ;
F_18 ( V_43 -> V_9 ) ;
return 0 ;
}
static int F_167 ( struct V_8 * V_9 , struct V_42 * V_43 ,
T_5 V_55 )
{
int V_53 ;
F_129 ( V_43 , & V_63 , V_55 ) ;
F_38 ( & V_63 . V_44 ,
& V_63 . V_44 , & V_43 -> V_44 ) ;
F_165 (cpu, &rdtgrp->cpu_mask) {
F_166 ( V_47 . V_48 , V_53 ) = V_63 . V_6 ;
F_166 ( V_47 . V_49 , V_53 ) = V_63 . V_50 . V_51 ;
}
F_38 ( V_55 , V_55 , & V_43 -> V_44 ) ;
F_30 ( V_55 , NULL ) ;
V_43 -> V_38 = V_75 ;
F_7 ( V_43 -> V_6 ) ;
F_136 ( V_43 -> V_50 . V_51 ) ;
F_134 ( V_43 ) ;
F_137 ( & V_43 -> V_173 ) ;
F_96 ( V_9 ) ;
F_18 ( V_43 -> V_9 ) ;
return 0 ;
}
static int F_168 ( struct V_8 * V_9 )
{
struct V_8 * V_18 = V_9 -> V_57 ;
struct V_42 * V_43 ;
T_5 V_55 ;
int V_21 = 0 ;
if ( ! F_46 ( & V_55 , V_64 ) )
return - V_65 ;
V_43 = F_23 ( V_9 ) ;
if ( ! V_43 ) {
V_21 = - V_86 ;
goto V_144;
}
if ( V_43 -> type == V_68 && V_18 == V_63 . V_9 )
V_21 = F_167 ( V_9 , V_43 , V_55 ) ;
else if ( V_43 -> type == V_69 &&
F_162 ( V_18 , V_9 -> V_22 ) )
V_21 = F_164 ( V_9 , V_43 , V_55 ) ;
else
V_21 = - V_86 ;
V_144:
F_26 ( V_9 ) ;
F_47 ( V_55 ) ;
return V_21 ;
}
static int F_169 ( struct V_25 * V_91 , struct V_204 * V_205 )
{
if ( V_125 [ V_126 ] . V_132 )
F_170 ( V_91 , L_15 ) ;
return 0 ;
}
static int T_9 F_171 ( void )
{
int V_21 ;
V_152 = F_172 ( & V_206 ,
V_207 ,
& V_63 ) ;
if ( F_16 ( V_152 ) )
return F_17 ( V_152 ) ;
F_113 ( & V_112 ) ;
V_63 . V_6 = 0 ;
V_63 . V_50 . V_51 = 0 ;
V_63 . type = V_68 ;
F_154 ( & V_63 . V_50 . V_61 ) ;
F_161 ( & V_63 . V_173 , & V_202 ) ;
V_21 = F_89 ( V_152 -> V_9 , V_208 ) ;
if ( V_21 ) {
F_173 ( V_152 ) ;
goto V_144;
}
V_63 . V_9 = V_152 -> V_9 ;
F_97 ( V_63 . V_9 ) ;
V_144:
F_114 ( & V_112 ) ;
return V_21 ;
}
int T_9 F_174 ( void )
{
int V_21 = 0 ;
V_21 = F_171 () ;
if ( V_21 )
return V_21 ;
V_21 = F_175 ( V_209 , L_16 ) ;
if ( V_21 )
goto V_210;
V_21 = F_176 ( & V_211 ) ;
if ( V_21 )
goto V_212;
return 0 ;
V_212:
F_177 ( V_209 , L_16 ) ;
V_210:
F_173 ( V_152 ) ;
return V_21 ;
}
