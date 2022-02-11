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
return ! V_11 -> V_12 &&
F_8 ( V_11 -> V_13 + F_6 ( V_7 ) , V_14 ) ;
}
static inline int F_9 ( const unsigned char * V_15 , T_2 V_16 )
{
T_3 V_17 = F_10 ( ( T_3 * ) ( V_15 + 2 ) ) ;
return F_11 ( V_17 , V_16 , V_5 ) & ( V_18 - 1 ) ;
}
static void F_12 ( struct V_19 * V_20 )
{
struct V_2 * V_21
= F_13 ( V_20 , struct V_2 , V_22 ) ;
F_14 ( V_1 , V_21 ) ;
}
static void F_15 ( struct V_6 * V_7 , const unsigned char * V_23 )
{
int V_24 ;
struct V_25 * V_26 ;
F_16 () ;
F_17 (p, &br->port_list, list) {
if ( ! F_18 ( V_26 ) ) {
V_24 = F_19 ( V_26 -> V_27 , V_23 ) ;
if ( V_24 )
goto V_28;
}
}
return;
V_28:
F_20 (p, &br->port_list, list) {
if ( ! F_18 ( V_26 ) )
F_21 ( V_26 -> V_27 , V_23 ) ;
}
}
static void F_22 ( struct V_6 * V_7 , const unsigned char * V_23 )
{
struct V_25 * V_26 ;
F_16 () ;
F_17 (p, &br->port_list, list) {
if ( ! F_18 ( V_26 ) )
F_21 ( V_26 -> V_27 , V_23 ) ;
}
}
static void F_23 ( struct V_2 * V_29 )
{
struct V_30 V_11 = {
. V_31 = {
. V_32 = V_33 ,
. V_34 = V_35 ,
} ,
. V_16 = V_29 -> V_36 ,
} ;
F_24 ( V_11 . V_23 , V_29 -> V_23 . V_23 ) ;
F_25 ( V_29 -> V_37 -> V_27 , & V_11 . V_31 ) ;
}
static void F_26 ( struct V_6 * V_7 , struct V_2 * V_29 )
{
if ( V_29 -> V_12 )
F_22 ( V_7 , V_29 -> V_23 . V_23 ) ;
if ( V_29 -> V_38 )
F_23 ( V_29 ) ;
F_27 ( & V_29 -> V_39 ) ;
F_28 ( V_7 , V_29 , V_40 ) ;
F_29 ( & V_29 -> V_22 , F_12 ) ;
}
static void F_30 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
struct V_2 * V_29 )
{
const unsigned char * V_23 = V_29 -> V_23 . V_23 ;
struct V_41 * V_42 ;
const struct V_43 * V_44 ;
struct V_25 * V_45 ;
T_4 V_16 = V_29 -> V_36 ;
F_17 (op, &br->port_list, list) {
V_42 = F_31 ( V_45 ) ;
if ( V_45 != V_26 && F_32 ( V_45 -> V_27 -> V_46 , V_23 ) &&
( ! V_16 || F_33 ( V_42 , V_16 ) ) ) {
V_29 -> V_37 = V_45 ;
V_29 -> V_47 = 0 ;
return;
}
}
V_42 = F_34 ( V_7 ) ;
V_44 = F_33 ( V_42 , V_16 ) ;
if ( V_26 && F_32 ( V_7 -> V_27 -> V_46 , V_23 ) &&
( ! V_16 || ( V_44 && F_35 ( V_44 ) ) ) ) {
V_29 -> V_37 = NULL ;
V_29 -> V_47 = 0 ;
return;
}
F_26 ( V_7 , V_29 ) ;
}
void F_36 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_48 * V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_29 ;
F_37 ( & V_7 -> V_50 ) ;
V_29 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_29 && V_29 -> V_51 && ! V_29 -> V_47 && V_29 -> V_37 == V_26 )
F_30 ( V_7 , V_26 , V_29 ) ;
F_39 ( & V_7 -> V_50 ) ;
}
void F_40 ( struct V_25 * V_26 , const unsigned char * V_52 )
{
struct V_41 * V_42 ;
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_43 * V_44 ;
int V_53 ;
F_37 ( & V_7 -> V_50 ) ;
V_42 = F_31 ( V_26 ) ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
struct V_54 * V_55 ;
F_41 (h, &br->hash[i]) {
struct V_2 * V_29 ;
V_29 = F_42 ( V_55 , struct V_2 , V_39 ) ;
if ( V_29 -> V_37 == V_26 && V_29 -> V_51 && ! V_29 -> V_47 ) {
F_30 ( V_7 , V_26 , V_29 ) ;
if ( ! V_42 || ! V_42 -> V_56 )
goto V_57;
}
}
}
V_57:
F_43 ( V_7 , V_26 , V_52 , 0 ) ;
if ( ! V_42 || ! V_42 -> V_56 )
goto V_58;
F_17 (v, &vg->vlan_list, vlist)
F_43 ( V_7 , V_26 , V_52 , V_44 -> V_16 ) ;
V_58:
F_39 ( & V_7 -> V_50 ) ;
}
void F_44 ( struct V_6 * V_7 , const T_5 * V_52 )
{
struct V_41 * V_42 ;
struct V_2 * V_29 ;
struct V_43 * V_44 ;
F_37 ( & V_7 -> V_50 ) ;
V_29 = F_45 ( V_7 , V_7 -> V_27 -> V_46 , 0 ) ;
if ( V_29 && V_29 -> V_51 && ! V_29 -> V_37 )
F_30 ( V_7 , NULL , V_29 ) ;
F_43 ( V_7 , NULL , V_52 , 0 ) ;
V_42 = F_34 ( V_7 ) ;
if ( ! V_42 || ! V_42 -> V_56 )
goto V_59;
F_17 (v, &vg->vlan_list, vlist) {
V_29 = F_45 ( V_7 , V_7 -> V_27 -> V_46 , V_44 -> V_16 ) ;
if ( V_29 && V_29 -> V_51 && ! V_29 -> V_37 )
F_30 ( V_7 , NULL , V_29 ) ;
F_43 ( V_7 , NULL , V_52 , V_44 -> V_16 ) ;
}
V_59:
F_39 ( & V_7 -> V_50 ) ;
}
void F_46 ( unsigned long V_60 )
{
struct V_6 * V_7 = (struct V_6 * ) V_60 ;
unsigned long V_61 = F_6 ( V_7 ) ;
unsigned long V_62 = V_14 + V_7 -> V_10 ;
int V_53 ;
F_47 ( & V_7 -> V_50 ) ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
struct V_2 * V_29 ;
struct V_54 * V_63 ;
F_48 (f, n, &br->hash[i], hlist) {
unsigned long V_64 ;
if ( V_29 -> V_12 )
continue;
if ( V_29 -> V_38 )
continue;
V_64 = V_29 -> V_13 + V_61 ;
if ( F_8 ( V_64 , V_14 ) )
F_26 ( V_7 , V_29 ) ;
else if ( F_49 ( V_64 , V_62 ) )
V_62 = V_64 ;
}
}
F_50 ( & V_7 -> V_50 ) ;
F_51 ( & V_7 -> V_65 , F_52 ( V_62 ) ) ;
}
void F_53 ( struct V_6 * V_7 )
{
int V_53 ;
F_37 ( & V_7 -> V_50 ) ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
struct V_2 * V_29 ;
struct V_54 * V_63 ;
F_48 (f, n, &br->hash[i], hlist) {
if ( ! V_29 -> V_12 )
F_26 ( V_7 , V_29 ) ;
}
}
F_39 ( & V_7 -> V_50 ) ;
}
void F_54 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
T_4 V_16 ,
int V_66 )
{
int V_53 ;
F_37 ( & V_7 -> V_50 ) ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
struct V_54 * V_55 , * V_67 ;
F_55 (h, g, &br->hash[i]) {
struct V_2 * V_29
= F_42 ( V_55 , struct V_2 , V_39 ) ;
if ( V_29 -> V_37 != V_26 )
continue;
if ( ! V_66 )
if ( V_29 -> V_12 || ( V_16 && V_29 -> V_36 != V_16 ) )
continue;
if ( V_29 -> V_51 )
F_30 ( V_7 , V_26 , V_29 ) ;
else
F_26 ( V_7 , V_29 ) ;
}
}
F_39 ( & V_7 -> V_50 ) ;
}
struct V_2 * F_45 ( struct V_6 * V_7 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_56 (fdb,
&br->hash[br_mac_hash(addr, vid)], hlist) {
if ( F_32 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_36 == V_16 ) {
if ( F_57 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_58 ( struct V_68 * V_27 , unsigned char * V_23 )
{
struct V_2 * V_11 ;
struct V_25 * V_69 ;
int V_70 ;
F_59 () ;
V_69 = F_60 ( V_27 ) ;
if ( ! V_69 )
V_70 = 0 ;
else {
V_11 = F_45 ( V_69 -> V_7 , V_23 , 0 ) ;
V_70 = V_11 && V_11 -> V_37 && V_11 -> V_37 -> V_27 != V_27 &&
V_11 -> V_37 -> V_71 == V_72 ;
}
F_61 () ;
return V_70 ;
}
int F_62 ( struct V_6 * V_7 , void * V_73 ,
unsigned long V_74 , unsigned long V_75 )
{
struct V_76 * V_77 = V_73 ;
int V_53 , V_78 = 0 ;
struct V_2 * V_29 ;
memset ( V_73 , 0 , V_74 * sizeof( struct V_76 ) ) ;
F_59 () ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
F_56 (f, &br->hash[i], hlist) {
if ( V_78 >= V_74 )
goto V_59;
if ( F_7 ( V_7 , V_29 ) )
continue;
if ( ! V_29 -> V_37 )
continue;
if ( V_75 ) {
-- V_75 ;
continue;
}
memcpy ( V_77 -> V_79 , V_29 -> V_23 . V_23 , V_80 ) ;
V_77 -> V_81 = V_29 -> V_37 -> V_81 ;
V_77 -> V_82 = V_29 -> V_37 -> V_81 >> 8 ;
V_77 -> V_51 = V_29 -> V_51 ;
if ( ! V_29 -> V_12 )
V_77 -> V_83 = F_63 ( V_14 - V_29 -> V_13 ) ;
++ V_77 ;
++ V_78 ;
}
}
V_59:
F_61 () ;
return V_78 ;
}
static struct V_2 * F_38 ( struct V_48 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_64 (fdb, head, hlist) {
if ( F_32 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_36 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_65 ( struct V_48 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_56 (fdb, head, hlist) {
if ( F_32 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_36 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_66 ( struct V_48 * V_20 ,
struct V_25 * V_84 ,
const unsigned char * V_23 ,
T_2 V_16 ,
unsigned char V_51 ,
unsigned char V_12 )
{
struct V_2 * V_11 ;
V_11 = F_67 ( V_1 , V_85 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_23 . V_23 , V_23 , V_80 ) ;
V_11 -> V_37 = V_84 ;
V_11 -> V_36 = V_16 ;
V_11 -> V_51 = V_51 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_47 = 0 ;
V_11 -> V_38 = 0 ;
V_11 -> V_13 = V_11 -> V_86 = V_14 ;
F_68 ( & V_11 -> V_39 , V_20 ) ;
}
return V_11 ;
}
static int F_43 ( struct V_6 * V_7 , struct V_25 * V_84 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_48 * V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( ! F_69 ( V_23 ) )
return - V_87 ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( V_11 -> V_51 )
return 0 ;
F_70 ( V_7 , L_2
L_3 ,
V_84 ? V_84 -> V_27 -> V_88 : V_7 -> V_27 -> V_88 ) ;
F_26 ( V_7 , V_11 ) ;
}
V_11 = F_66 ( V_20 , V_84 , V_23 , V_16 , 1 , 1 ) ;
if ( ! V_11 )
return - V_4 ;
F_15 ( V_7 , V_23 ) ;
F_28 ( V_7 , V_11 , V_89 ) ;
return 0 ;
}
int F_71 ( struct V_6 * V_7 , struct V_25 * V_84 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_70 ;
F_37 ( & V_7 -> V_50 ) ;
V_70 = F_43 ( V_7 , V_84 , V_23 , V_16 ) ;
F_39 ( & V_7 -> V_50 ) ;
return V_70 ;
}
void F_72 ( struct V_6 * V_7 , struct V_25 * V_84 ,
const unsigned char * V_23 , T_4 V_16 , bool V_47 )
{
struct V_48 * V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_90 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_84 -> V_71 == V_91 ||
V_84 -> V_71 == V_72 ) )
return;
V_11 = F_65 ( V_20 , V_23 , V_16 ) ;
if ( F_73 ( V_11 ) ) {
if ( F_57 ( V_11 -> V_51 ) ) {
if ( F_74 () )
F_70 ( V_7 , L_4
L_5 ,
V_84 -> V_27 -> V_88 ) ;
} else {
if ( F_57 ( V_84 != V_11 -> V_37 ) ) {
V_11 -> V_37 = V_84 ;
V_90 = true ;
}
V_11 -> V_13 = V_14 ;
if ( F_57 ( V_47 ) )
V_11 -> V_47 = 1 ;
if ( F_57 ( V_90 ) )
F_28 ( V_7 , V_11 , V_89 ) ;
}
} else {
F_47 ( & V_7 -> V_50 ) ;
if ( F_73 ( ! F_38 ( V_20 , V_23 , V_16 ) ) ) {
V_11 = F_66 ( V_20 , V_84 , V_23 , V_16 , 0 , 0 ) ;
if ( V_11 ) {
if ( F_57 ( V_47 ) )
V_11 -> V_47 = 1 ;
F_28 ( V_7 , V_11 , V_89 ) ;
}
}
F_50 ( & V_7 -> V_50 ) ;
}
}
static int F_75 ( const struct V_6 * V_7 ,
const struct V_2 * V_11 )
{
if ( V_11 -> V_51 )
return V_92 ;
else if ( V_11 -> V_12 )
return V_93 ;
else if ( F_7 ( V_7 , V_11 ) )
return V_94 ;
else
return V_95 ;
}
static int F_76 ( struct V_96 * V_97 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_98 , T_3 V_99 , int type , unsigned int V_34 )
{
unsigned long V_100 = V_14 ;
struct V_101 V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
V_104 = F_77 ( V_97 , V_98 , V_99 , type , sizeof( * V_106 ) , V_34 ) ;
if ( V_104 == NULL )
return - V_107 ;
V_106 = F_78 ( V_104 ) ;
V_106 -> V_108 = V_109 ;
V_106 -> V_110 = 0 ;
V_106 -> V_111 = 0 ;
V_106 -> V_112 = V_11 -> V_38 ? V_113 : 0 ;
V_106 -> V_114 = 0 ;
V_106 -> V_115 = V_11 -> V_37 ? V_11 -> V_37 -> V_27 -> V_116 : V_7 -> V_27 -> V_116 ;
V_106 -> V_117 = F_75 ( V_7 , V_11 ) ;
if ( F_79 ( V_97 , V_118 , V_80 , & V_11 -> V_23 ) )
goto V_119;
if ( F_80 ( V_97 , V_120 , V_7 -> V_27 -> V_116 ) )
goto V_119;
V_102 . V_121 = F_81 ( V_100 - V_11 -> V_86 ) ;
V_102 . V_122 = 0 ;
V_102 . V_123 = F_81 ( V_100 - V_11 -> V_13 ) ;
V_102 . V_124 = 0 ;
if ( F_79 ( V_97 , V_125 , sizeof( V_102 ) , & V_102 ) )
goto V_119;
if ( V_11 -> V_36 && F_79 ( V_97 , V_126 , sizeof( T_4 ) , & V_11 -> V_36 ) )
goto V_119;
F_82 ( V_97 , V_104 ) ;
return 0 ;
V_119:
F_83 ( V_97 , V_104 ) ;
return - V_107 ;
}
static inline T_6 F_84 ( void )
{
return F_85 ( sizeof( struct V_105 ) )
+ F_86 ( V_80 )
+ F_86 ( sizeof( T_3 ) )
+ F_86 ( sizeof( T_4 ) )
+ F_86 ( sizeof( struct V_101 ) ) ;
}
static void F_28 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_127 * V_127 = F_87 ( V_7 -> V_27 ) ;
struct V_96 * V_97 ;
int V_24 = - V_128 ;
V_97 = F_88 ( F_84 () , V_85 ) ;
if ( V_97 == NULL )
goto V_129;
V_24 = F_76 ( V_97 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_24 < 0 ) {
F_89 ( V_24 == - V_107 ) ;
F_90 ( V_97 ) ;
goto V_129;
}
F_91 ( V_97 , V_127 , 0 , V_130 , NULL , V_85 ) ;
return;
V_129:
F_92 ( V_127 , V_130 , V_24 ) ;
}
int F_93 ( struct V_96 * V_97 ,
struct V_131 * V_132 ,
struct V_68 * V_27 ,
struct V_68 * V_133 ,
int V_134 )
{
struct V_6 * V_7 = F_94 ( V_27 ) ;
int V_53 ;
if ( ! ( V_27 -> V_135 & V_136 ) )
goto V_59;
if ( ! V_133 )
V_134 = F_95 ( V_97 , V_132 , V_27 , NULL , V_134 ) ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
struct V_2 * V_29 ;
F_56 (f, &br->hash[i], hlist) {
if ( V_134 < V_132 -> args [ 0 ] )
goto V_75;
if ( V_133 &&
( ! V_29 -> V_37 || V_29 -> V_37 -> V_27 != V_133 ) ) {
if ( V_133 != V_27 )
goto V_75;
if ( V_29 -> V_37 )
goto V_75;
}
if ( ! V_133 && V_29 -> V_37 )
goto V_75;
if ( F_76 ( V_97 , V_7 , V_29 ,
F_96 ( V_132 -> V_97 ) . V_98 ,
V_132 -> V_104 -> V_137 ,
V_89 ,
V_138 ) < 0 )
break;
V_75:
++ V_134 ;
}
}
V_59:
return V_134 ;
}
static int F_97 ( struct V_25 * V_84 , const T_7 * V_23 ,
T_2 V_71 , T_2 V_34 , T_2 V_16 )
{
struct V_6 * V_7 = V_84 -> V_7 ;
struct V_48 * V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_139 = false ;
if ( ! ( V_71 & V_92 ) && ! ( V_71 & V_93 ) &&
! ( V_84 -> V_71 == V_91 ||
V_84 -> V_71 == V_72 ) )
return - V_140 ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_34 & V_141 ) )
return - V_142 ;
V_11 = F_66 ( V_20 , V_84 , V_23 , V_16 , 0 , 0 ) ;
if ( ! V_11 )
return - V_4 ;
V_139 = true ;
} else {
if ( V_34 & V_143 )
return - V_144 ;
if ( V_11 -> V_37 != V_84 ) {
V_11 -> V_37 = V_84 ;
V_139 = true ;
}
}
if ( F_75 ( V_7 , V_11 ) != V_71 ) {
if ( V_71 & V_92 ) {
V_11 -> V_51 = 1 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else if ( V_71 & V_93 ) {
V_11 -> V_51 = 0 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else {
V_11 -> V_51 = 0 ;
if ( V_11 -> V_12 ) {
V_11 -> V_12 = 0 ;
F_22 ( V_7 , V_23 ) ;
}
}
V_139 = true ;
}
V_11 -> V_47 = 1 ;
V_11 -> V_86 = V_14 ;
if ( V_139 ) {
V_11 -> V_13 = V_14 ;
F_28 ( V_7 , V_11 , V_89 ) ;
}
return 0 ;
}
static int F_98 ( struct V_105 * V_106 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_145 , T_4 V_16 )
{
int V_24 = 0 ;
if ( V_106 -> V_112 & V_146 ) {
F_99 () ;
F_59 () ;
F_72 ( V_26 -> V_7 , V_26 , V_23 , V_16 , true ) ;
F_61 () ;
F_100 () ;
} else {
F_37 ( & V_26 -> V_7 -> V_50 ) ;
V_24 = F_97 ( V_26 , V_23 , V_106 -> V_117 ,
V_145 , V_16 ) ;
F_39 ( & V_26 -> V_7 -> V_50 ) ;
}
return V_24 ;
}
int F_101 ( struct V_105 * V_106 , struct V_147 * V_148 [] ,
struct V_68 * V_27 ,
const unsigned char * V_23 , T_4 V_16 , T_4 V_145 )
{
struct V_41 * V_42 ;
struct V_25 * V_26 = NULL ;
struct V_43 * V_44 ;
struct V_6 * V_7 = NULL ;
int V_24 = 0 ;
if ( ! ( V_106 -> V_117 & ( V_92 | V_93 | V_95 ) ) ) {
F_102 ( L_6 , V_106 -> V_117 ) ;
return - V_87 ;
}
if ( F_103 ( V_23 ) ) {
F_102 ( L_7 ) ;
return - V_87 ;
}
if ( V_27 -> V_135 & V_136 ) {
V_7 = F_94 ( V_27 ) ;
V_42 = F_34 ( V_7 ) ;
} else {
V_26 = F_104 ( V_27 ) ;
if ( ! V_26 ) {
F_102 ( L_8 ,
V_27 -> V_88 ) ;
return - V_87 ;
}
V_42 = F_31 ( V_26 ) ;
}
if ( V_16 ) {
V_44 = F_33 ( V_42 , V_16 ) ;
if ( ! V_44 || ! F_35 ( V_44 ) ) {
F_102 ( L_9 , V_16 , V_27 -> V_88 ) ;
return - V_87 ;
}
if ( V_27 -> V_135 & V_136 )
V_24 = F_71 ( V_7 , NULL , V_23 , V_16 ) ;
else
V_24 = F_98 ( V_106 , V_26 , V_23 , V_145 , V_16 ) ;
} else {
if ( V_27 -> V_135 & V_136 )
V_24 = F_71 ( V_7 , NULL , V_23 , 0 ) ;
else
V_24 = F_98 ( V_106 , V_26 , V_23 , V_145 , 0 ) ;
if ( V_24 || ! V_42 || ! V_42 -> V_56 )
goto V_59;
F_17 (v, &vg->vlan_list, vlist) {
if ( ! F_35 ( V_44 ) )
continue;
if ( V_27 -> V_135 & V_136 )
V_24 = F_71 ( V_7 , NULL , V_23 , V_44 -> V_16 ) ;
else
V_24 = F_98 ( V_106 , V_26 , V_23 , V_145 ,
V_44 -> V_16 ) ;
if ( V_24 )
goto V_59;
}
}
V_59:
return V_24 ;
}
static int F_105 ( struct V_6 * V_7 , const T_5 * V_23 ,
T_4 V_16 )
{
struct V_48 * V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_142 ;
F_26 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_24 ;
F_37 ( & V_7 -> V_50 ) ;
V_24 = F_105 ( V_7 , V_23 , V_16 ) ;
F_39 ( & V_7 -> V_50 ) ;
return V_24 ;
}
static int F_107 ( struct V_25 * V_26 ,
const T_5 * V_23 , T_4 V_149 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_48 * V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_149 ) ] ;
struct V_2 * V_11 ;
V_11 = F_38 ( V_20 , V_23 , V_149 ) ;
if ( ! V_11 || V_11 -> V_37 != V_26 )
return - V_142 ;
F_26 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_108 ( struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_24 ;
F_37 ( & V_26 -> V_7 -> V_50 ) ;
V_24 = F_107 ( V_26 , V_23 , V_16 ) ;
F_39 ( & V_26 -> V_7 -> V_50 ) ;
return V_24 ;
}
int F_109 ( struct V_105 * V_106 , struct V_147 * V_148 [] ,
struct V_68 * V_27 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_41 * V_42 ;
struct V_25 * V_26 = NULL ;
struct V_43 * V_44 ;
struct V_6 * V_7 = NULL ;
int V_24 ;
if ( V_27 -> V_135 & V_136 ) {
V_7 = F_94 ( V_27 ) ;
V_42 = F_34 ( V_7 ) ;
} else {
V_26 = F_104 ( V_27 ) ;
if ( ! V_26 ) {
F_102 ( L_10 ,
V_27 -> V_88 ) ;
return - V_87 ;
}
V_42 = F_31 ( V_26 ) ;
}
if ( V_16 ) {
V_44 = F_33 ( V_42 , V_16 ) ;
if ( ! V_44 ) {
F_102 ( L_11 , V_16 , V_27 -> V_88 ) ;
return - V_87 ;
}
if ( V_27 -> V_135 & V_136 )
V_24 = F_106 ( V_7 , V_23 , V_16 ) ;
else
V_24 = F_108 ( V_26 , V_23 , V_16 ) ;
} else {
V_24 = - V_142 ;
if ( V_27 -> V_135 & V_136 )
V_24 = F_106 ( V_7 , V_23 , 0 ) ;
else
V_24 &= F_108 ( V_26 , V_23 , 0 ) ;
if ( ! V_42 || ! V_42 -> V_56 )
goto V_59;
F_17 (v, &vg->vlan_list, vlist) {
if ( ! F_35 ( V_44 ) )
continue;
if ( V_27 -> V_135 & V_136 )
V_24 = F_106 ( V_7 , V_23 , V_44 -> V_16 ) ;
else
V_24 &= F_108 ( V_26 , V_23 , V_44 -> V_16 ) ;
}
}
V_59:
return V_24 ;
}
int F_110 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 , * V_150 ;
int V_53 ;
int V_24 ;
F_16 () ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
F_64 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
V_24 = F_19 ( V_26 -> V_27 , V_11 -> V_23 . V_23 ) ;
if ( V_24 )
goto V_151;
}
}
return 0 ;
V_151:
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
F_64 (tmp, &br->hash[i], hlist) {
if ( V_150 == V_11 )
break;
if ( ! V_150 -> V_12 )
continue;
F_21 ( V_26 -> V_27 , V_150 -> V_23 . V_23 ) ;
}
}
return V_24 ;
}
void F_111 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 ;
int V_53 ;
F_16 () ;
for ( V_53 = 0 ; V_53 < V_18 ; V_53 ++ ) {
F_56 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
F_21 ( V_26 -> V_27 , V_11 -> V_23 . V_23 ) ;
}
}
}
int F_112 ( struct V_6 * V_7 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_48 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_37 ( & V_7 -> V_50 ) ;
V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( ! V_11 ) {
V_11 = F_66 ( V_20 , V_26 , V_23 , V_16 , 0 , 0 ) ;
if ( ! V_11 ) {
V_24 = - V_4 ;
goto V_152;
}
V_11 -> V_38 = 1 ;
F_28 ( V_7 , V_11 , V_89 ) ;
} else if ( V_11 -> V_38 ) {
V_11 -> V_13 = V_11 -> V_86 = V_14 ;
} else if ( ! V_11 -> V_47 ) {
V_11 -> V_38 = 1 ;
V_11 -> V_13 = V_14 ;
F_28 ( V_7 , V_11 , V_89 ) ;
}
V_152:
F_39 ( & V_7 -> V_50 ) ;
return V_24 ;
}
int F_113 ( struct V_6 * V_7 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_48 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_37 ( & V_7 -> V_50 ) ;
V_20 = & V_7 -> V_49 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_11 && V_11 -> V_38 )
F_26 ( V_7 , V_11 ) ;
else
V_24 = - V_142 ;
F_39 ( & V_7 -> V_50 ) ;
return V_24 ;
}
