static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 * V_2 -> V_4 . V_5 + V_2 -> V_4 . V_6 ;
}
static inline void F_2 ( void )
{
struct V_1 * V_2 = & V_7 [ V_8 ] ;
T_1 V_9 , V_10 , V_11 = F_3 ( 20 ) - 1 ;
if ( F_4 ( V_12 , V_11 , 0 ) )
return;
F_5 ( V_12 , V_9 , V_10 ) ;
if ( V_9 != V_11 )
return;
V_2 -> V_13 = 4 ;
V_2 -> V_14 = V_11 ;
V_2 -> V_4 . V_15 = 20 ;
V_2 -> V_4 . V_16 = 0xc0000 ;
V_2 -> V_4 . V_17 = 2 ;
V_2 -> V_18 = true ;
V_2 -> V_19 = true ;
V_20 = true ;
}
static inline bool F_6 ( struct V_1 * V_2 )
{
F_7 ( L_1 ,
V_21 . V_22 , V_21 . V_23 ) ;
return false ;
}
static bool F_8 ( struct V_1 * V_2 )
{
union V_24 V_25 ;
union V_26 V_27 ;
T_1 V_28 , V_29 ;
F_9 ( 0x00000010 , 3 , & V_25 . V_30 , & V_28 , & V_29 , & V_27 . V_30 ) ;
V_2 -> V_13 = V_27 . V_31 . V_32 + 1 ;
V_2 -> V_33 . V_34 = V_25 . V_31 . V_34 + 1 ;
V_2 -> V_14 = V_35 ;
if ( V_29 & V_36 ) {
V_2 -> V_33 . V_37 = true ;
V_2 -> V_33 . V_38 = V_35 - V_2 -> V_33 . V_34 ;
V_2 -> V_33 . V_39 = V_35 - V_2 -> V_33 . V_34 ;
} else {
if ( ! F_6 ( V_2 ) )
return false ;
}
V_2 -> V_40 = 3 ;
V_2 -> V_18 = true ;
V_2 -> V_19 = true ;
return true ;
}
static void F_10 ( int V_41 , struct V_1 * V_2 )
{
union V_42 V_25 ;
union V_26 V_27 ;
T_1 V_28 , V_29 ;
F_9 ( 0x00000010 , V_41 , & V_25 . V_30 , & V_28 , & V_29 , & V_27 . V_30 ) ;
V_2 -> V_13 = V_27 . V_31 . V_32 + 1 ;
V_2 -> V_4 . V_15 = V_25 . V_31 . V_15 + 1 ;
V_2 -> V_14 = F_3 ( V_25 . V_31 . V_15 + 1 ) - 1 ;
V_2 -> V_4 . V_16 = V_28 & V_2 -> V_14 ;
V_2 -> V_40 = ( V_2 -> V_4 . V_15 + 3 ) / 4 ;
V_2 -> V_18 = true ;
V_2 -> V_19 = true ;
}
static void F_11 ( int type )
{
struct V_1 * V_43 = & V_7 [ V_8 ] ;
struct V_1 * V_2 = & V_7 [ type ] ;
V_2 -> V_13 = V_43 -> V_13 / 2 ;
V_2 -> V_4 . V_15 = V_43 -> V_4 . V_15 ;
V_2 -> V_14 = V_43 -> V_14 ;
V_2 -> V_40 = ( V_2 -> V_4 . V_15 + 3 ) / 4 ;
V_2 -> V_18 = true ;
V_2 -> V_19 = false ;
}
static int F_12 ( int V_44 , int V_45 )
{
struct V_46 * V_47 = F_13 ( V_44 ) ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_47 -> V_49 ; V_48 ++ ) {
if ( V_47 -> V_50 [ V_48 ] . V_45 == V_45 )
return V_47 -> V_50 [ V_48 ] . V_51 ;
}
return - 1 ;
}
static T_1 F_14 ( unsigned long V_52 , struct V_1 * V_2 )
{
if ( V_2 -> V_33 . V_37 )
return V_35 - V_52 ;
F_15 ( L_2 ) ;
return V_2 -> V_14 ;
}
static void
F_16 ( struct V_53 * V_54 , struct V_55 * V_56 , struct V_1 * V_2 )
{
unsigned int V_48 ;
for ( V_48 = V_56 -> V_57 ; V_48 < V_56 -> V_58 ; V_48 ++ )
F_17 ( V_2 -> V_59 + V_48 , F_14 ( V_54 -> V_60 [ V_48 ] , V_2 ) ) ;
}
static void
F_18 ( struct V_53 * V_54 , struct V_55 * V_56 , struct V_1 * V_2 )
{
unsigned int V_48 ;
for ( V_48 = V_56 -> V_57 ; V_48 < V_56 -> V_58 ; V_48 ++ )
F_17 ( V_2 -> V_59 + F_1 ( V_2 , V_48 ) , V_54 -> V_60 [ V_48 ] ) ;
}
struct V_53 * F_19 ( int V_44 , struct V_1 * V_2 )
{
struct V_53 * V_54 ;
F_20 (d, &r->domains, list) {
if ( F_21 ( V_44 , & V_54 -> V_61 ) )
return V_54 ;
}
return NULL ;
}
void F_22 ( void * V_62 )
{
struct V_55 * V_56 = V_62 ;
struct V_1 * V_2 = V_56 -> V_63 ;
int V_44 = F_23 () ;
struct V_53 * V_54 ;
V_54 = F_19 ( V_44 , V_2 ) ;
if ( V_54 ) {
V_2 -> V_64 ( V_54 , V_56 , V_2 ) ;
return;
}
F_15 ( L_3 ,
V_44 , V_2 -> V_65 ) ;
}
struct V_53 * F_24 ( struct V_1 * V_2 , int V_51 ,
struct V_66 * * V_67 )
{
struct V_53 * V_54 ;
struct V_66 * V_9 ;
if ( V_51 < 0 )
return F_25 ( V_51 ) ;
F_26 (l, &r->domains) {
V_54 = F_27 ( V_9 , struct V_53 , V_68 ) ;
if ( V_51 == V_54 -> V_51 )
return V_54 ;
if ( V_51 < V_54 -> V_51 )
break;
}
if ( V_67 )
* V_67 = V_9 ;
return NULL ;
}
static int F_28 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_55 V_56 ;
T_1 * V_69 ;
int V_48 ;
V_69 = F_29 ( V_2 -> V_13 , sizeof( * V_54 -> V_60 ) , V_70 ) ;
if ( ! V_69 )
return - V_71 ;
V_54 -> V_60 = V_69 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_13 ; V_48 ++ , V_69 ++ )
* V_69 = V_2 -> V_14 ;
V_56 . V_57 = 0 ;
V_56 . V_58 = V_2 -> V_13 ;
V_2 -> V_64 ( V_54 , & V_56 , V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
T_2 V_72 ;
if ( F_31 () ) {
V_54 -> V_73 = F_32 ( F_33 ( V_2 -> V_74 ) ,
sizeof( unsigned long ) ,
V_70 ) ;
if ( ! V_54 -> V_73 )
return - V_71 ;
F_34 ( & V_54 -> V_75 , V_76 ) ;
}
if ( F_35 () ) {
V_72 = sizeof( * V_54 -> V_77 ) ;
V_54 -> V_77 = F_32 ( V_2 -> V_74 , V_72 , V_70 ) ;
if ( ! V_54 -> V_77 ) {
F_36 ( V_54 -> V_73 ) ;
return - V_71 ;
}
}
if ( F_37 () ) {
V_72 = sizeof( * V_54 -> V_78 ) ;
V_54 -> V_78 = F_32 ( V_2 -> V_74 , V_72 , V_70 ) ;
if ( ! V_54 -> V_78 ) {
F_36 ( V_54 -> V_73 ) ;
F_36 ( V_54 -> V_77 ) ;
return - V_71 ;
}
}
if ( F_38 () ) {
F_34 ( & V_54 -> V_79 , V_80 ) ;
F_39 ( V_54 , V_81 ) ;
}
return 0 ;
}
static void F_40 ( int V_44 , struct V_1 * V_2 )
{
int V_51 = F_12 ( V_44 , V_2 -> V_82 ) ;
struct V_66 * V_83 = NULL ;
struct V_53 * V_54 ;
V_54 = F_24 ( V_2 , V_51 , & V_83 ) ;
if ( F_41 ( V_54 ) ) {
F_42 ( L_4 , V_44 ) ;
return;
}
if ( V_54 ) {
F_43 ( V_44 , & V_54 -> V_61 ) ;
return;
}
V_54 = F_44 ( sizeof( * V_54 ) , V_70 , F_45 ( V_44 ) ) ;
if ( ! V_54 )
return;
V_54 -> V_51 = V_51 ;
F_43 ( V_44 , & V_54 -> V_61 ) ;
if ( V_2 -> V_18 && F_28 ( V_2 , V_54 ) ) {
F_36 ( V_54 ) ;
return;
}
if ( V_2 -> V_84 && F_30 ( V_2 , V_54 ) ) {
F_36 ( V_54 ) ;
return;
}
F_46 ( & V_54 -> V_68 , V_83 ) ;
if ( F_47 ( & V_85 ) )
F_48 ( V_2 , V_54 ) ;
}
static void F_49 ( int V_44 , struct V_1 * V_2 )
{
int V_51 = F_12 ( V_44 , V_2 -> V_82 ) ;
struct V_53 * V_54 ;
V_54 = F_24 ( V_2 , V_51 , NULL ) ;
if ( F_50 ( V_54 ) ) {
F_42 ( L_4 , V_44 ) ;
return;
}
F_51 ( V_44 , & V_54 -> V_61 ) ;
if ( F_52 ( & V_54 -> V_61 ) ) {
if ( F_47 ( & V_85 ) )
F_53 ( V_2 , V_54 -> V_51 ) ;
F_36 ( V_54 -> V_60 ) ;
F_36 ( V_54 -> V_73 ) ;
F_36 ( V_54 -> V_77 ) ;
F_36 ( V_54 -> V_78 ) ;
F_54 ( & V_54 -> V_68 ) ;
if ( F_38 () )
F_55 ( & V_54 -> V_79 ) ;
if ( F_31 () && F_56 ( V_2 , V_54 ) ) {
F_57 ( V_54 , true ) ;
F_55 ( & V_54 -> V_75 ) ;
}
F_36 ( V_54 ) ;
return;
}
if ( V_2 == & V_7 [ V_8 ] ) {
if ( F_38 () && V_44 == V_54 -> V_86 ) {
F_55 ( & V_54 -> V_79 ) ;
F_39 ( V_54 , 0 ) ;
}
if ( F_31 () && V_44 == V_54 -> V_87 &&
F_56 ( V_2 , V_54 ) ) {
F_55 ( & V_54 -> V_75 ) ;
F_58 ( V_54 , 0 ) ;
}
}
}
static void F_59 ( int V_44 )
{
struct V_88 * V_89 = F_60 ( & V_90 ) ;
V_89 -> V_91 = 0 ;
V_89 -> V_92 = 0 ;
V_89 -> V_93 = 0 ;
V_89 -> V_94 = 0 ;
F_61 ( V_95 , 0 , 0 ) ;
}
static int F_62 ( unsigned int V_44 )
{
struct V_1 * V_2 ;
F_63 ( & V_96 ) ;
F_64 (r)
F_40 ( V_44 , V_2 ) ;
F_43 ( V_44 , & V_97 . V_61 ) ;
F_59 ( V_44 ) ;
F_65 ( & V_96 ) ;
return 0 ;
}
static void F_66 ( struct V_98 * V_2 , unsigned int V_44 )
{
struct V_98 * V_99 ;
F_20 (cr, &r->mon.crdtgrp_list, mon.crdtgrp_list) {
if ( F_67 ( V_44 , & V_99 -> V_61 ) ) {
break;
}
}
}
static int F_68 ( unsigned int V_44 )
{
struct V_98 * V_100 ;
struct V_1 * V_2 ;
F_63 ( & V_96 ) ;
F_64 (r)
F_49 ( V_44 , V_2 ) ;
F_20 (rdtgrp, &rdt_all_groups, rdtgroup_list) {
if ( F_67 ( V_44 , & V_100 -> V_61 ) ) {
F_66 ( V_100 , V_44 ) ;
break;
}
}
F_59 ( V_44 ) ;
F_65 ( & V_96 ) ;
return 0 ;
}
static T_3 void F_69 ( void )
{
struct V_1 * V_2 ;
int V_101 ;
F_70 (r) {
V_101 = strlen ( V_2 -> V_65 ) ;
if ( V_101 > V_102 )
V_102 = V_101 ;
if ( V_2 -> V_40 > V_103 )
V_103 = V_2 -> V_40 ;
}
}
static int T_3 F_71 ( char * V_104 )
{
struct V_105 * V_106 ;
bool V_107 ;
char * V_108 ;
if ( * V_104 == '=' )
V_104 ++ ;
while ( ( V_108 = F_72 ( & V_104 , L_5 ) ) != NULL ) {
V_107 = * V_108 == '!' ;
if ( V_107 )
V_108 ++ ;
for ( V_106 = V_105 ; V_106 < & V_105 [ V_109 ] ; V_106 ++ ) {
if ( strcmp ( V_108 , V_106 -> V_65 ) == 0 ) {
if ( V_107 )
V_106 -> V_107 = true ;
else
V_106 -> V_110 = true ;
break;
}
}
}
return 1 ;
}
static bool T_3 F_73 ( int V_111 )
{
bool V_112 = F_74 ( V_111 ) ;
struct V_105 * V_106 ;
if ( ! V_112 )
return V_112 ;
for ( V_106 = V_105 ; V_106 < & V_105 [ V_109 ] ; V_106 ++ ) {
if ( V_111 == V_106 -> V_111 ) {
if ( V_106 -> V_107 )
V_112 = false ;
if ( V_106 -> V_110 )
V_112 = true ;
break;
}
}
return V_112 ;
}
static T_3 bool F_75 ( void )
{
bool V_112 = false ;
if ( V_20 )
return true ;
if ( ! F_74 ( V_113 ) )
return false ;
if ( F_73 ( V_114 ) ) {
F_10 ( 1 , & V_7 [ V_8 ] ) ;
if ( F_73 ( V_115 ) ) {
F_11 ( V_116 ) ;
F_11 ( V_117 ) ;
}
V_112 = true ;
}
if ( F_73 ( V_118 ) ) {
F_10 ( 2 , & V_7 [ V_119 ] ) ;
V_112 = true ;
}
if ( F_73 ( V_120 ) ) {
if ( F_8 ( & V_7 [ V_121 ] ) )
V_112 = true ;
}
return V_112 ;
}
static T_3 bool F_76 ( void )
{
if ( F_73 ( V_122 ) )
V_123 |= ( 1 << V_124 ) ;
if ( F_73 ( V_125 ) )
V_123 |= ( 1 << V_126 ) ;
if ( F_73 ( V_127 ) )
V_123 |= ( 1 << V_128 ) ;
if ( ! V_123 )
return false ;
return ! F_77 ( & V_7 [ V_8 ] ) ;
}
static T_3 void F_78 ( void )
{
switch ( V_21 . V_23 ) {
case V_129 :
if ( ! V_105 [ V_130 ] . V_107 )
F_2 () ;
break;
case V_131 :
if ( V_21 . V_132 <= 4 )
F_71 ( L_6 ) ;
}
}
static T_3 bool F_79 ( void )
{
F_78 () ;
V_20 = F_75 () ;
V_133 = F_76 () ;
return ( V_133 || V_20 ) ;
}
static int T_3 F_80 ( void )
{
struct V_1 * V_2 ;
int V_89 , V_112 ;
if ( ! F_79 () )
return - V_134 ;
F_69 () ;
V_89 = F_81 ( V_135 ,
L_7 ,
F_62 , F_68 ) ;
if ( V_89 < 0 )
return V_89 ;
V_112 = F_82 () ;
if ( V_112 ) {
F_83 ( V_89 ) ;
return V_112 ;
}
F_70 (r)
F_7 ( L_8 , V_2 -> V_65 ) ;
F_84 (r)
F_7 ( L_9 , V_2 -> V_65 ) ;
return 0 ;
}
