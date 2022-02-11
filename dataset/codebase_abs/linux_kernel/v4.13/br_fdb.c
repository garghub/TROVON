int T_1 F_1 ( void )
{
V_1 = F_2 ( L_1 ,
sizeof( struct V_2 ) ,
0 ,
V_3 , NULL ) ;
if ( ! V_1 )
return - V_4 ;
F_3 ( & V_5 , sizeof( V_5 ) ) ;
return 0 ;
}
void F_4 ( void )
{
F_5 ( V_1 ) ;
}
static inline unsigned long F_6 ( const struct V_6 * V_7 )
{
return V_7 -> V_8 ? V_7 -> V_9 : V_7 -> V_10 ;
}
static inline int F_7 ( const struct V_6 * V_7 ,
const struct V_2 * V_11 )
{
return ! V_11 -> V_12 && ! V_11 -> V_13 &&
F_8 ( V_11 -> V_14 + F_6 ( V_7 ) , V_15 ) ;
}
static inline int F_9 ( const unsigned char * V_16 , T_2 V_17 )
{
T_3 V_18 = F_10 ( ( T_3 * ) ( V_16 + 2 ) ) ;
return F_11 ( V_18 , V_17 , V_5 ) & ( V_19 - 1 ) ;
}
static void F_12 ( struct V_20 * V_21 )
{
struct V_2 * V_22
= F_13 ( V_21 , struct V_2 , V_23 ) ;
F_14 ( V_1 , V_22 ) ;
}
static struct V_2 * F_15 ( struct V_24 * V_21 ,
const unsigned char * V_25 ,
T_2 V_17 )
{
struct V_2 * V_26 ;
F_16 ( ! F_17 () ) ;
F_18 (f, head, hlist)
if ( F_19 ( V_26 -> V_25 . V_25 , V_25 ) && V_26 -> V_27 == V_17 )
break;
return V_26 ;
}
static struct V_2 * F_20 ( struct V_6 * V_7 ,
const unsigned char * V_25 ,
T_2 V_17 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
struct V_2 * V_11 ;
F_21 ( & V_7 -> V_29 ) ;
F_22 () ;
V_11 = F_15 ( V_21 , V_25 , V_17 ) ;
F_23 () ;
return V_11 ;
}
struct V_2 * F_24 ( struct V_6 * V_7 ,
const unsigned char * V_25 ,
T_2 V_17 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
return F_15 ( V_21 , V_25 , V_17 ) ;
}
static void F_25 ( struct V_6 * V_7 , const unsigned char * V_25 )
{
int V_30 ;
struct V_31 * V_32 ;
F_26 () ;
F_27 (p, &br->port_list, list) {
if ( ! F_28 ( V_32 ) ) {
V_30 = F_29 ( V_32 -> V_33 , V_25 ) ;
if ( V_30 )
goto V_34;
}
}
return;
V_34:
F_30 (p, &br->port_list, list) {
if ( ! F_28 ( V_32 ) )
F_31 ( V_32 -> V_33 , V_25 ) ;
}
}
static void F_32 ( struct V_6 * V_7 , const unsigned char * V_25 )
{
struct V_31 * V_32 ;
F_26 () ;
F_27 (p, &br->port_list, list) {
if ( ! F_28 ( V_32 ) )
F_31 ( V_32 -> V_33 , V_25 ) ;
}
}
static void F_33 ( struct V_2 * V_26 )
{
struct V_35 V_11 = {
. V_36 = {
. V_37 = V_26 -> V_38 -> V_33 ,
. V_39 = V_40 ,
. V_41 = V_42 ,
} ,
. V_17 = V_26 -> V_27 ,
} ;
F_34 ( V_11 . V_25 , V_26 -> V_25 . V_25 ) ;
F_35 ( V_26 -> V_38 -> V_33 , & V_11 . V_36 ) ;
}
static void F_36 ( struct V_6 * V_7 , struct V_2 * V_26 )
{
if ( V_26 -> V_12 )
F_32 ( V_7 , V_26 -> V_25 . V_25 ) ;
if ( V_26 -> V_13 )
F_33 ( V_26 ) ;
F_37 ( & V_26 -> V_43 ) ;
F_38 ( V_7 , V_26 , V_44 ) ;
F_39 ( & V_26 -> V_23 , F_12 ) ;
}
static void F_40 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
struct V_2 * V_26 )
{
const unsigned char * V_25 = V_26 -> V_25 . V_25 ;
struct V_45 * V_46 ;
const struct V_47 * V_48 ;
struct V_31 * V_49 ;
T_4 V_17 = V_26 -> V_27 ;
F_27 (op, &br->port_list, list) {
V_46 = F_41 ( V_49 ) ;
if ( V_49 != V_32 && F_19 ( V_49 -> V_33 -> V_50 , V_25 ) &&
( ! V_17 || F_42 ( V_46 , V_17 ) ) ) {
V_26 -> V_38 = V_49 ;
V_26 -> V_51 = 0 ;
return;
}
}
V_46 = F_43 ( V_7 ) ;
V_48 = F_42 ( V_46 , V_17 ) ;
if ( V_32 && F_19 ( V_7 -> V_33 -> V_50 , V_25 ) &&
( ! V_17 || ( V_48 && F_44 ( V_48 ) ) ) ) {
V_26 -> V_38 = NULL ;
V_26 -> V_51 = 0 ;
return;
}
F_36 ( V_7 , V_26 ) ;
}
void F_45 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_26 ;
F_46 ( & V_7 -> V_29 ) ;
V_26 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_26 && V_26 -> V_52 && ! V_26 -> V_51 && V_26 -> V_38 == V_32 )
F_40 ( V_7 , V_32 , V_26 ) ;
F_47 ( & V_7 -> V_29 ) ;
}
void F_48 ( struct V_31 * V_32 , const unsigned char * V_53 )
{
struct V_45 * V_46 ;
struct V_6 * V_7 = V_32 -> V_7 ;
struct V_47 * V_48 ;
int V_54 ;
F_46 ( & V_7 -> V_29 ) ;
V_46 = F_41 ( V_32 ) ;
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
struct V_55 * V_56 ;
F_49 (h, &br->hash[i]) {
struct V_2 * V_26 ;
V_26 = F_50 ( V_56 , struct V_2 , V_43 ) ;
if ( V_26 -> V_38 == V_32 && V_26 -> V_52 && ! V_26 -> V_51 ) {
F_40 ( V_7 , V_32 , V_26 ) ;
if ( ! V_46 || ! V_46 -> V_57 )
goto V_58;
}
}
}
V_58:
F_51 ( V_7 , V_32 , V_53 , 0 ) ;
if ( ! V_46 || ! V_46 -> V_57 )
goto V_59;
F_27 (v, &vg->vlan_list, vlist)
F_51 ( V_7 , V_32 , V_53 , V_48 -> V_17 ) ;
V_59:
F_47 ( & V_7 -> V_29 ) ;
}
void F_52 ( struct V_6 * V_7 , const T_5 * V_53 )
{
struct V_45 * V_46 ;
struct V_2 * V_26 ;
struct V_47 * V_48 ;
F_46 ( & V_7 -> V_29 ) ;
V_26 = F_20 ( V_7 , V_7 -> V_33 -> V_50 , 0 ) ;
if ( V_26 && V_26 -> V_52 && ! V_26 -> V_38 && ! V_26 -> V_51 )
F_40 ( V_7 , NULL , V_26 ) ;
F_51 ( V_7 , NULL , V_53 , 0 ) ;
V_46 = F_43 ( V_7 ) ;
if ( ! V_46 || ! V_46 -> V_57 )
goto V_60;
F_27 (v, &vg->vlan_list, vlist) {
if ( ! F_44 ( V_48 ) )
continue;
V_26 = F_20 ( V_7 , V_7 -> V_33 -> V_50 , V_48 -> V_17 ) ;
if ( V_26 && V_26 -> V_52 && ! V_26 -> V_38 && ! V_26 -> V_51 )
F_40 ( V_7 , NULL , V_26 ) ;
F_51 ( V_7 , NULL , V_53 , V_48 -> V_17 ) ;
}
V_60:
F_47 ( & V_7 -> V_29 ) ;
}
void F_53 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = F_13 ( V_62 , struct V_6 ,
V_63 . V_62 ) ;
unsigned long V_64 = F_6 ( V_7 ) ;
unsigned long V_65 = V_64 ;
unsigned long V_66 = V_15 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
struct V_2 * V_26 ;
struct V_55 * V_67 ;
if ( ! V_7 -> V_28 [ V_54 ] . V_68 )
continue;
F_46 ( & V_7 -> V_29 ) ;
F_54 (f, n, &br->hash[i], hlist) {
unsigned long V_69 ;
if ( V_26 -> V_12 )
continue;
if ( V_26 -> V_13 )
continue;
V_69 = V_26 -> V_14 + V_64 ;
if ( F_55 ( V_69 , V_66 ) )
V_65 = F_56 ( V_65 , V_69 - V_66 ) ;
else
F_36 ( V_7 , V_26 ) ;
}
F_47 ( & V_7 -> V_29 ) ;
F_57 () ;
}
V_65 = F_58 (unsigned long, work_delay, msecs_to_jiffies(10)) ;
F_59 ( V_70 , & V_7 -> V_63 , V_65 ) ;
}
void F_60 ( struct V_6 * V_7 )
{
int V_54 ;
F_46 ( & V_7 -> V_29 ) ;
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
struct V_2 * V_26 ;
struct V_55 * V_67 ;
F_54 (f, n, &br->hash[i], hlist) {
if ( ! V_26 -> V_12 )
F_36 ( V_7 , V_26 ) ;
}
}
F_47 ( & V_7 -> V_29 ) ;
}
void F_61 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
T_4 V_17 ,
int V_71 )
{
int V_54 ;
F_46 ( & V_7 -> V_29 ) ;
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
struct V_55 * V_56 , * V_72 ;
F_62 (h, g, &br->hash[i]) {
struct V_2 * V_26
= F_50 ( V_56 , struct V_2 , V_43 ) ;
if ( V_26 -> V_38 != V_32 )
continue;
if ( ! V_71 )
if ( V_26 -> V_12 || ( V_17 && V_26 -> V_27 != V_17 ) )
continue;
if ( V_26 -> V_52 )
F_40 ( V_7 , V_32 , V_26 ) ;
else
F_36 ( V_7 , V_26 ) ;
}
}
F_47 ( & V_7 -> V_29 ) ;
}
int F_63 ( struct V_73 * V_33 , unsigned char * V_25 )
{
struct V_2 * V_11 ;
struct V_31 * V_74 ;
int V_75 ;
F_22 () ;
V_74 = F_64 ( V_33 ) ;
if ( ! V_74 )
V_75 = 0 ;
else {
V_11 = F_24 ( V_74 -> V_7 , V_25 , 0 ) ;
V_75 = V_11 && V_11 -> V_38 && V_11 -> V_38 -> V_33 != V_33 &&
V_11 -> V_38 -> V_76 == V_77 ;
}
F_23 () ;
return V_75 ;
}
int F_65 ( struct V_6 * V_7 , void * V_78 ,
unsigned long V_79 , unsigned long V_80 )
{
struct V_81 * V_82 = V_78 ;
int V_54 , V_83 = 0 ;
struct V_2 * V_26 ;
memset ( V_78 , 0 , V_79 * sizeof( struct V_81 ) ) ;
F_22 () ;
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
F_18 (f, &br->hash[i], hlist) {
if ( V_83 >= V_79 )
goto V_60;
if ( F_7 ( V_7 , V_26 ) )
continue;
if ( ! V_26 -> V_38 )
continue;
if ( V_80 ) {
-- V_80 ;
continue;
}
memcpy ( V_82 -> V_84 , V_26 -> V_25 . V_25 , V_85 ) ;
V_82 -> V_86 = V_26 -> V_38 -> V_86 ;
V_82 -> V_87 = V_26 -> V_38 -> V_86 >> 8 ;
V_82 -> V_52 = V_26 -> V_52 ;
if ( ! V_26 -> V_12 )
V_82 -> V_88 = F_66 ( V_15 - V_26 -> V_14 ) ;
++ V_82 ;
++ V_83 ;
}
}
V_60:
F_23 () ;
return V_83 ;
}
static struct V_2 * F_67 ( struct V_24 * V_21 ,
struct V_31 * V_89 ,
const unsigned char * V_25 ,
T_2 V_17 ,
unsigned char V_52 ,
unsigned char V_12 )
{
struct V_2 * V_11 ;
V_11 = F_68 ( V_1 , V_90 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_25 . V_25 , V_25 , V_85 ) ;
V_11 -> V_38 = V_89 ;
V_11 -> V_27 = V_17 ;
V_11 -> V_52 = V_52 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_51 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_91 = 0 ;
V_11 -> V_14 = V_11 -> V_92 = V_15 ;
F_69 ( & V_11 -> V_43 , V_21 ) ;
}
return V_11 ;
}
static int F_51 ( struct V_6 * V_7 , struct V_31 * V_89 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
struct V_2 * V_11 ;
if ( ! F_70 ( V_25 ) )
return - V_93 ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 ) {
if ( V_11 -> V_52 )
return 0 ;
F_71 ( V_7 , L_2 ,
V_89 ? V_89 -> V_33 -> V_94 : V_7 -> V_33 -> V_94 , V_25 , V_17 ) ;
F_36 ( V_7 , V_11 ) ;
}
V_11 = F_67 ( V_21 , V_89 , V_25 , V_17 , 1 , 1 ) ;
if ( ! V_11 )
return - V_4 ;
F_25 ( V_7 , V_25 ) ;
F_38 ( V_7 , V_11 , V_95 ) ;
return 0 ;
}
int F_72 ( struct V_6 * V_7 , struct V_31 * V_89 ,
const unsigned char * V_25 , T_4 V_17 )
{
int V_75 ;
F_46 ( & V_7 -> V_29 ) ;
V_75 = F_51 ( V_7 , V_89 , V_25 , V_17 ) ;
F_47 ( & V_7 -> V_29 ) ;
return V_75 ;
}
void F_73 ( struct V_6 * V_7 , struct V_31 * V_89 ,
const unsigned char * V_25 , T_4 V_17 , bool V_51 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
struct V_2 * V_11 ;
bool V_96 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_89 -> V_76 == V_97 ||
V_89 -> V_76 == V_77 ) )
return;
V_11 = F_15 ( V_21 , V_25 , V_17 ) ;
if ( F_74 ( V_11 ) ) {
if ( F_75 ( V_11 -> V_52 ) ) {
if ( F_76 () )
F_71 ( V_7 , L_3 ,
V_89 -> V_33 -> V_94 , V_25 , V_17 ) ;
} else {
unsigned long V_66 = V_15 ;
if ( F_75 ( V_89 != V_11 -> V_38 ) ) {
V_11 -> V_38 = V_89 ;
V_96 = true ;
if ( F_75 ( V_11 -> V_13 ) )
V_11 -> V_13 = 0 ;
}
if ( V_66 != V_11 -> V_14 )
V_11 -> V_14 = V_66 ;
if ( F_75 ( V_51 ) )
V_11 -> V_51 = 1 ;
if ( F_75 ( V_96 ) )
F_38 ( V_7 , V_11 , V_95 ) ;
}
} else {
F_77 ( & V_7 -> V_29 ) ;
if ( F_74 ( ! F_15 ( V_21 , V_25 , V_17 ) ) ) {
V_11 = F_67 ( V_21 , V_89 , V_25 , V_17 , 0 , 0 ) ;
if ( V_11 ) {
if ( F_75 ( V_51 ) )
V_11 -> V_51 = 1 ;
F_38 ( V_7 , V_11 , V_95 ) ;
}
}
F_78 ( & V_7 -> V_29 ) ;
}
}
static int F_79 ( const struct V_6 * V_7 ,
const struct V_2 * V_11 )
{
if ( V_11 -> V_52 )
return V_98 ;
else if ( V_11 -> V_12 )
return V_99 ;
else if ( F_7 ( V_7 , V_11 ) )
return V_100 ;
else
return V_101 ;
}
static int F_80 ( struct V_102 * V_103 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_104 , T_3 V_105 , int type , unsigned int V_41 )
{
unsigned long V_66 = V_15 ;
struct V_106 V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
V_109 = F_81 ( V_103 , V_104 , V_105 , type , sizeof( * V_111 ) , V_41 ) ;
if ( V_109 == NULL )
return - V_112 ;
V_111 = F_82 ( V_109 ) ;
V_111 -> V_113 = V_114 ;
V_111 -> V_115 = 0 ;
V_111 -> V_116 = 0 ;
V_111 -> V_117 = 0 ;
V_111 -> V_118 = 0 ;
V_111 -> V_119 = V_11 -> V_38 ? V_11 -> V_38 -> V_33 -> V_120 : V_7 -> V_33 -> V_120 ;
V_111 -> V_121 = F_79 ( V_7 , V_11 ) ;
if ( V_11 -> V_91 )
V_111 -> V_117 |= V_122 ;
if ( V_11 -> V_13 )
V_111 -> V_117 |= V_123 ;
if ( F_83 ( V_103 , V_124 , V_85 , & V_11 -> V_25 ) )
goto V_125;
if ( F_84 ( V_103 , V_126 , V_7 -> V_33 -> V_120 ) )
goto V_125;
V_107 . V_127 = F_85 ( V_66 - V_11 -> V_92 ) ;
V_107 . V_128 = 0 ;
V_107 . V_129 = F_85 ( V_66 - V_11 -> V_14 ) ;
V_107 . V_130 = 0 ;
if ( F_83 ( V_103 , V_131 , sizeof( V_107 ) , & V_107 ) )
goto V_125;
if ( V_11 -> V_27 && F_83 ( V_103 , V_132 , sizeof( T_4 ) , & V_11 -> V_27 ) )
goto V_125;
F_86 ( V_103 , V_109 ) ;
return 0 ;
V_125:
F_87 ( V_103 , V_109 ) ;
return - V_112 ;
}
static inline T_6 F_88 ( void )
{
return F_89 ( sizeof( struct V_110 ) )
+ F_90 ( V_85 )
+ F_90 ( sizeof( T_3 ) )
+ F_90 ( sizeof( T_4 ) )
+ F_90 ( sizeof( struct V_106 ) ) ;
}
static void F_38 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_133 * V_133 = F_91 ( V_7 -> V_33 ) ;
struct V_102 * V_103 ;
int V_30 = - V_134 ;
F_92 ( V_11 , type ) ;
V_103 = F_93 ( F_88 () , V_90 ) ;
if ( V_103 == NULL )
goto V_135;
V_30 = F_80 ( V_103 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_30 < 0 ) {
F_94 ( V_30 == - V_112 ) ;
F_95 ( V_103 ) ;
goto V_135;
}
F_96 ( V_103 , V_133 , 0 , V_136 , NULL , V_90 ) ;
return;
V_135:
F_97 ( V_133 , V_136 , V_30 ) ;
}
int F_98 ( struct V_102 * V_103 ,
struct V_137 * V_138 ,
struct V_73 * V_33 ,
struct V_73 * V_139 ,
int * V_140 )
{
struct V_6 * V_7 = F_99 ( V_33 ) ;
int V_30 = 0 ;
int V_54 ;
if ( ! ( V_33 -> V_141 & V_142 ) )
goto V_60;
if ( ! V_139 ) {
V_30 = F_100 ( V_103 , V_138 , V_33 , NULL , V_140 ) ;
if ( V_30 < 0 )
goto V_60;
}
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
struct V_2 * V_26 ;
F_18 (f, &br->hash[i], hlist) {
if ( * V_140 < V_138 -> args [ 2 ] )
goto V_80;
if ( V_139 &&
( ! V_26 -> V_38 || V_26 -> V_38 -> V_33 != V_139 ) ) {
if ( V_139 != V_33 )
goto V_80;
if ( V_26 -> V_38 )
goto V_80;
}
if ( ! V_139 && V_26 -> V_38 )
goto V_80;
V_30 = F_80 ( V_103 , V_7 , V_26 ,
F_101 ( V_138 -> V_103 ) . V_104 ,
V_138 -> V_109 -> V_143 ,
V_95 ,
V_144 ) ;
if ( V_30 < 0 )
goto V_60;
V_80:
* V_140 += 1 ;
}
}
V_60:
return V_30 ;
}
static int F_102 ( struct V_6 * V_7 , struct V_31 * V_89 ,
const T_7 * V_25 , T_2 V_76 , T_2 V_41 , T_2 V_17 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
struct V_2 * V_11 ;
bool V_145 = false ;
if ( V_89 && ! ( V_76 & V_98 ) && ! ( V_76 & V_99 ) &&
! ( V_89 -> V_76 == V_97 ||
V_89 -> V_76 == V_77 ) )
return - V_146 ;
if ( ! V_89 && ! ( V_76 & V_98 ) ) {
F_103 ( L_4 ,
V_7 -> V_33 -> V_94 ) ;
return - V_93 ;
}
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_41 & V_147 ) )
return - V_148 ;
V_11 = F_67 ( V_21 , V_89 , V_25 , V_17 , 0 , 0 ) ;
if ( ! V_11 )
return - V_4 ;
V_145 = true ;
} else {
if ( V_41 & V_149 )
return - V_150 ;
if ( V_11 -> V_38 != V_89 ) {
V_11 -> V_38 = V_89 ;
V_145 = true ;
}
}
if ( F_79 ( V_7 , V_11 ) != V_76 ) {
if ( V_76 & V_98 ) {
V_11 -> V_52 = 1 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_25 ( V_7 , V_25 ) ;
}
} else if ( V_76 & V_99 ) {
V_11 -> V_52 = 0 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_25 ( V_7 , V_25 ) ;
}
} else {
V_11 -> V_52 = 0 ;
if ( V_11 -> V_12 ) {
V_11 -> V_12 = 0 ;
F_32 ( V_7 , V_25 ) ;
}
}
V_145 = true ;
}
V_11 -> V_51 = 1 ;
V_11 -> V_92 = V_15 ;
if ( V_145 ) {
V_11 -> V_14 = V_15 ;
F_38 ( V_7 , V_11 , V_95 ) ;
}
return 0 ;
}
static int F_104 ( struct V_110 * V_111 , struct V_6 * V_7 ,
struct V_31 * V_32 , const unsigned char * V_25 ,
T_4 V_151 , T_4 V_17 )
{
int V_30 = 0 ;
if ( V_111 -> V_117 & V_152 ) {
if ( ! V_32 ) {
F_103 ( L_5 ,
V_7 -> V_33 -> V_94 ) ;
return - V_93 ;
}
F_105 () ;
F_22 () ;
F_73 ( V_7 , V_32 , V_25 , V_17 , true ) ;
F_23 () ;
F_106 () ;
} else if ( V_111 -> V_117 & V_123 ) {
V_30 = F_107 ( V_7 , V_32 , V_25 , V_17 ) ;
} else {
F_46 ( & V_7 -> V_29 ) ;
V_30 = F_102 ( V_7 , V_32 , V_25 , V_111 -> V_121 ,
V_151 , V_17 ) ;
F_47 ( & V_7 -> V_29 ) ;
}
return V_30 ;
}
int F_108 ( struct V_110 * V_111 , struct V_153 * V_154 [] ,
struct V_73 * V_33 ,
const unsigned char * V_25 , T_4 V_17 , T_4 V_151 )
{
struct V_45 * V_46 ;
struct V_31 * V_32 = NULL ;
struct V_47 * V_48 ;
struct V_6 * V_7 = NULL ;
int V_30 = 0 ;
if ( ! ( V_111 -> V_121 & ( V_98 | V_99 | V_101 ) ) ) {
F_103 ( L_6 , V_111 -> V_121 ) ;
return - V_93 ;
}
if ( F_109 ( V_25 ) ) {
F_103 ( L_7 ) ;
return - V_93 ;
}
if ( V_33 -> V_141 & V_142 ) {
V_7 = F_99 ( V_33 ) ;
V_46 = F_43 ( V_7 ) ;
} else {
V_32 = F_110 ( V_33 ) ;
if ( ! V_32 ) {
F_103 ( L_8 ,
V_33 -> V_94 ) ;
return - V_93 ;
}
V_7 = V_32 -> V_7 ;
V_46 = F_41 ( V_32 ) ;
}
if ( V_17 ) {
V_48 = F_42 ( V_46 , V_17 ) ;
if ( ! V_48 || ! F_44 ( V_48 ) ) {
F_103 ( L_9 , V_17 , V_33 -> V_94 ) ;
return - V_93 ;
}
V_30 = F_104 ( V_111 , V_7 , V_32 , V_25 , V_151 , V_17 ) ;
} else {
V_30 = F_104 ( V_111 , V_7 , V_32 , V_25 , V_151 , 0 ) ;
if ( V_30 || ! V_46 || ! V_46 -> V_57 )
goto V_60;
F_27 (v, &vg->vlan_list, vlist) {
if ( ! F_44 ( V_48 ) )
continue;
V_30 = F_104 ( V_111 , V_7 , V_32 , V_25 , V_151 , V_48 -> V_17 ) ;
if ( V_30 )
goto V_60;
}
}
V_60:
return V_30 ;
}
static int F_111 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
const T_5 * V_25 , T_4 V_155 )
{
struct V_2 * V_11 ;
V_11 = F_20 ( V_7 , V_25 , V_155 ) ;
if ( ! V_11 || V_11 -> V_38 != V_32 )
return - V_148 ;
F_36 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_112 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
int V_30 ;
F_46 ( & V_7 -> V_29 ) ;
V_30 = F_111 ( V_7 , V_32 , V_25 , V_17 ) ;
F_47 ( & V_7 -> V_29 ) ;
return V_30 ;
}
int F_113 ( struct V_110 * V_111 , struct V_153 * V_154 [] ,
struct V_73 * V_33 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_45 * V_46 ;
struct V_31 * V_32 = NULL ;
struct V_47 * V_48 ;
struct V_6 * V_7 ;
int V_30 ;
if ( V_33 -> V_141 & V_142 ) {
V_7 = F_99 ( V_33 ) ;
V_46 = F_43 ( V_7 ) ;
} else {
V_32 = F_110 ( V_33 ) ;
if ( ! V_32 ) {
F_103 ( L_10 ,
V_33 -> V_94 ) ;
return - V_93 ;
}
V_46 = F_41 ( V_32 ) ;
V_7 = V_32 -> V_7 ;
}
if ( V_17 ) {
V_48 = F_42 ( V_46 , V_17 ) ;
if ( ! V_48 ) {
F_103 ( L_11 , V_17 , V_33 -> V_94 ) ;
return - V_93 ;
}
V_30 = F_112 ( V_7 , V_32 , V_25 , V_17 ) ;
} else {
V_30 = - V_148 ;
V_30 &= F_112 ( V_7 , V_32 , V_25 , 0 ) ;
if ( ! V_46 || ! V_46 -> V_57 )
return V_30 ;
F_27 (v, &vg->vlan_list, vlist) {
if ( ! F_44 ( V_48 ) )
continue;
V_30 &= F_112 ( V_7 , V_32 , V_25 , V_48 -> V_17 ) ;
}
}
return V_30 ;
}
int F_114 ( struct V_6 * V_7 , struct V_31 * V_32 )
{
struct V_2 * V_11 , * V_156 ;
int V_54 ;
int V_30 ;
F_26 () ;
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
F_115 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
V_30 = F_29 ( V_32 -> V_33 , V_11 -> V_25 . V_25 ) ;
if ( V_30 )
goto V_157;
}
}
return 0 ;
V_157:
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
F_115 (tmp, &br->hash[i], hlist) {
if ( V_156 == V_11 )
break;
if ( ! V_156 -> V_12 )
continue;
F_31 ( V_32 -> V_33 , V_156 -> V_25 . V_25 ) ;
}
}
return V_30 ;
}
void F_116 ( struct V_6 * V_7 , struct V_31 * V_32 )
{
struct V_2 * V_11 ;
int V_54 ;
F_26 () ;
for ( V_54 = 0 ; V_54 < V_19 ; V_54 ++ ) {
F_18 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
F_31 ( V_32 -> V_33 , V_11 -> V_25 . V_25 ) ;
}
}
}
int F_107 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_11 ;
struct V_24 * V_21 ;
bool V_145 = false ;
int V_30 = 0 ;
F_46 ( & V_7 -> V_29 ) ;
V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( ! V_11 ) {
V_11 = F_67 ( V_21 , V_32 , V_25 , V_17 , 0 , 0 ) ;
if ( ! V_11 ) {
V_30 = - V_4 ;
goto V_158;
}
V_11 -> V_13 = 1 ;
F_38 ( V_7 , V_11 , V_95 ) ;
} else {
V_11 -> V_14 = V_15 ;
if ( V_11 -> V_38 != V_32 ) {
V_11 -> V_38 = V_32 ;
V_145 = true ;
}
if ( V_11 -> V_13 ) {
V_11 -> V_92 = V_15 ;
} else if ( ! V_11 -> V_51 ) {
V_11 -> V_13 = 1 ;
V_145 = true ;
}
if ( V_145 )
F_38 ( V_7 , V_11 , V_95 ) ;
}
V_158:
F_47 ( & V_7 -> V_29 ) ;
return V_30 ;
}
int F_117 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_11 ;
int V_30 = 0 ;
F_46 ( & V_7 -> V_29 ) ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 && V_11 -> V_13 )
F_36 ( V_7 , V_11 ) ;
else
V_30 = - V_148 ;
F_47 ( & V_7 -> V_29 ) ;
return V_30 ;
}
void F_118 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_11 ;
F_46 ( & V_7 -> V_29 ) ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 )
V_11 -> V_91 = 1 ;
F_47 ( & V_7 -> V_29 ) ;
}
