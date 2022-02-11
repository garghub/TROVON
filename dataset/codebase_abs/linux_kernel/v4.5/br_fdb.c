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
. V_32 = V_29 -> V_33 -> V_27 ,
. V_34 = V_35 ,
. V_36 = V_37 ,
} ,
. V_16 = V_29 -> V_38 ,
} ;
F_24 ( V_11 . V_23 , V_29 -> V_23 . V_23 ) ;
F_25 ( V_29 -> V_33 -> V_27 , & V_11 . V_31 ) ;
}
static void F_26 ( struct V_6 * V_7 , struct V_2 * V_29 )
{
if ( V_29 -> V_12 )
F_22 ( V_7 , V_29 -> V_23 . V_23 ) ;
if ( V_29 -> V_39 )
F_23 ( V_29 ) ;
F_27 ( & V_29 -> V_40 ) ;
F_28 ( V_7 , V_29 , V_41 ) ;
F_29 ( & V_29 -> V_22 , F_12 ) ;
}
static void F_30 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
struct V_2 * V_29 )
{
const unsigned char * V_23 = V_29 -> V_23 . V_23 ;
struct V_42 * V_43 ;
const struct V_44 * V_45 ;
struct V_25 * V_46 ;
T_4 V_16 = V_29 -> V_38 ;
F_17 (op, &br->port_list, list) {
V_43 = F_31 ( V_46 ) ;
if ( V_46 != V_26 && F_32 ( V_46 -> V_27 -> V_47 , V_23 ) &&
( ! V_16 || F_33 ( V_43 , V_16 ) ) ) {
V_29 -> V_33 = V_46 ;
V_29 -> V_48 = 0 ;
return;
}
}
V_43 = F_34 ( V_7 ) ;
V_45 = F_33 ( V_43 , V_16 ) ;
if ( V_26 && F_32 ( V_7 -> V_27 -> V_47 , V_23 ) &&
( ! V_16 || ( V_45 && F_35 ( V_45 ) ) ) ) {
V_29 -> V_33 = NULL ;
V_29 -> V_48 = 0 ;
return;
}
F_26 ( V_7 , V_29 ) ;
}
void F_36 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_49 * V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_29 ;
F_37 ( & V_7 -> V_51 ) ;
V_29 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_29 && V_29 -> V_52 && ! V_29 -> V_48 && V_29 -> V_33 == V_26 )
F_30 ( V_7 , V_26 , V_29 ) ;
F_39 ( & V_7 -> V_51 ) ;
}
void F_40 ( struct V_25 * V_26 , const unsigned char * V_53 )
{
struct V_42 * V_43 ;
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_44 * V_45 ;
int V_54 ;
F_37 ( & V_7 -> V_51 ) ;
V_43 = F_31 ( V_26 ) ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
struct V_55 * V_56 ;
F_41 (h, &br->hash[i]) {
struct V_2 * V_29 ;
V_29 = F_42 ( V_56 , struct V_2 , V_40 ) ;
if ( V_29 -> V_33 == V_26 && V_29 -> V_52 && ! V_29 -> V_48 ) {
F_30 ( V_7 , V_26 , V_29 ) ;
if ( ! V_43 || ! V_43 -> V_57 )
goto V_58;
}
}
}
V_58:
F_43 ( V_7 , V_26 , V_53 , 0 ) ;
if ( ! V_43 || ! V_43 -> V_57 )
goto V_59;
F_17 (v, &vg->vlan_list, vlist)
F_43 ( V_7 , V_26 , V_53 , V_45 -> V_16 ) ;
V_59:
F_39 ( & V_7 -> V_51 ) ;
}
void F_44 ( struct V_6 * V_7 , const T_5 * V_53 )
{
struct V_42 * V_43 ;
struct V_2 * V_29 ;
struct V_44 * V_45 ;
F_37 ( & V_7 -> V_51 ) ;
V_29 = F_45 ( V_7 , V_7 -> V_27 -> V_47 , 0 ) ;
if ( V_29 && V_29 -> V_52 && ! V_29 -> V_33 )
F_30 ( V_7 , NULL , V_29 ) ;
F_43 ( V_7 , NULL , V_53 , 0 ) ;
V_43 = F_34 ( V_7 ) ;
if ( ! V_43 || ! V_43 -> V_57 )
goto V_60;
F_17 (v, &vg->vlan_list, vlist) {
V_29 = F_45 ( V_7 , V_7 -> V_27 -> V_47 , V_45 -> V_16 ) ;
if ( V_29 && V_29 -> V_52 && ! V_29 -> V_33 )
F_30 ( V_7 , NULL , V_29 ) ;
F_43 ( V_7 , NULL , V_53 , V_45 -> V_16 ) ;
}
V_60:
F_39 ( & V_7 -> V_51 ) ;
}
void F_46 ( unsigned long V_61 )
{
struct V_6 * V_7 = (struct V_6 * ) V_61 ;
unsigned long V_62 = F_6 ( V_7 ) ;
unsigned long V_63 = V_14 + V_7 -> V_10 ;
int V_54 ;
F_47 ( & V_7 -> V_51 ) ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
struct V_2 * V_29 ;
struct V_55 * V_64 ;
F_48 (f, n, &br->hash[i], hlist) {
unsigned long V_65 ;
if ( V_29 -> V_12 )
continue;
if ( V_29 -> V_39 )
continue;
V_65 = V_29 -> V_13 + V_62 ;
if ( F_8 ( V_65 , V_14 ) )
F_26 ( V_7 , V_29 ) ;
else if ( F_49 ( V_65 , V_63 ) )
V_63 = V_65 ;
}
}
F_50 ( & V_7 -> V_51 ) ;
F_51 ( & V_7 -> V_66 , F_52 ( V_63 ) ) ;
}
void F_53 ( struct V_6 * V_7 )
{
int V_54 ;
F_37 ( & V_7 -> V_51 ) ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
struct V_2 * V_29 ;
struct V_55 * V_64 ;
F_48 (f, n, &br->hash[i], hlist) {
if ( ! V_29 -> V_12 )
F_26 ( V_7 , V_29 ) ;
}
}
F_39 ( & V_7 -> V_51 ) ;
}
void F_54 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
T_4 V_16 ,
int V_67 )
{
int V_54 ;
F_37 ( & V_7 -> V_51 ) ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
struct V_55 * V_56 , * V_68 ;
F_55 (h, g, &br->hash[i]) {
struct V_2 * V_29
= F_42 ( V_56 , struct V_2 , V_40 ) ;
if ( V_29 -> V_33 != V_26 )
continue;
if ( ! V_67 )
if ( V_29 -> V_12 || ( V_16 && V_29 -> V_38 != V_16 ) )
continue;
if ( V_29 -> V_52 )
F_30 ( V_7 , V_26 , V_29 ) ;
else
F_26 ( V_7 , V_29 ) ;
}
}
F_39 ( & V_7 -> V_51 ) ;
}
struct V_2 * F_45 ( struct V_6 * V_7 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_56 (fdb,
&br->hash[br_mac_hash(addr, vid)], hlist) {
if ( F_32 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_38 == V_16 ) {
if ( F_57 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_58 ( struct V_69 * V_27 , unsigned char * V_23 )
{
struct V_2 * V_11 ;
struct V_25 * V_70 ;
int V_71 ;
F_59 () ;
V_70 = F_60 ( V_27 ) ;
if ( ! V_70 )
V_71 = 0 ;
else {
V_11 = F_45 ( V_70 -> V_7 , V_23 , 0 ) ;
V_71 = V_11 && V_11 -> V_33 && V_11 -> V_33 -> V_27 != V_27 &&
V_11 -> V_33 -> V_72 == V_73 ;
}
F_61 () ;
return V_71 ;
}
int F_62 ( struct V_6 * V_7 , void * V_74 ,
unsigned long V_75 , unsigned long V_76 )
{
struct V_77 * V_78 = V_74 ;
int V_54 , V_79 = 0 ;
struct V_2 * V_29 ;
memset ( V_74 , 0 , V_75 * sizeof( struct V_77 ) ) ;
F_59 () ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
F_56 (f, &br->hash[i], hlist) {
if ( V_79 >= V_75 )
goto V_60;
if ( F_7 ( V_7 , V_29 ) )
continue;
if ( ! V_29 -> V_33 )
continue;
if ( V_76 ) {
-- V_76 ;
continue;
}
memcpy ( V_78 -> V_80 , V_29 -> V_23 . V_23 , V_81 ) ;
V_78 -> V_82 = V_29 -> V_33 -> V_82 ;
V_78 -> V_83 = V_29 -> V_33 -> V_82 >> 8 ;
V_78 -> V_52 = V_29 -> V_52 ;
if ( ! V_29 -> V_12 )
V_78 -> V_84 = F_63 ( V_14 - V_29 -> V_13 ) ;
++ V_78 ;
++ V_79 ;
}
}
V_60:
F_61 () ;
return V_79 ;
}
static struct V_2 * F_38 ( struct V_49 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_64 (fdb, head, hlist) {
if ( F_32 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_38 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_65 ( struct V_49 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_56 (fdb, head, hlist) {
if ( F_32 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_38 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_66 ( struct V_49 * V_20 ,
struct V_25 * V_85 ,
const unsigned char * V_23 ,
T_2 V_16 ,
unsigned char V_52 ,
unsigned char V_12 )
{
struct V_2 * V_11 ;
V_11 = F_67 ( V_1 , V_86 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_23 . V_23 , V_23 , V_81 ) ;
V_11 -> V_33 = V_85 ;
V_11 -> V_38 = V_16 ;
V_11 -> V_52 = V_52 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_48 = 0 ;
V_11 -> V_39 = 0 ;
V_11 -> V_13 = V_11 -> V_87 = V_14 ;
F_68 ( & V_11 -> V_40 , V_20 ) ;
}
return V_11 ;
}
static int F_43 ( struct V_6 * V_7 , struct V_25 * V_85 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_49 * V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( ! F_69 ( V_23 ) )
return - V_88 ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( V_11 -> V_52 )
return 0 ;
F_70 ( V_7 , L_2
L_3 ,
V_85 ? V_85 -> V_27 -> V_89 : V_7 -> V_27 -> V_89 ) ;
F_26 ( V_7 , V_11 ) ;
}
V_11 = F_66 ( V_20 , V_85 , V_23 , V_16 , 1 , 1 ) ;
if ( ! V_11 )
return - V_4 ;
F_15 ( V_7 , V_23 ) ;
F_28 ( V_7 , V_11 , V_90 ) ;
return 0 ;
}
int F_71 ( struct V_6 * V_7 , struct V_25 * V_85 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_71 ;
F_37 ( & V_7 -> V_51 ) ;
V_71 = F_43 ( V_7 , V_85 , V_23 , V_16 ) ;
F_39 ( & V_7 -> V_51 ) ;
return V_71 ;
}
void F_72 ( struct V_6 * V_7 , struct V_25 * V_85 ,
const unsigned char * V_23 , T_4 V_16 , bool V_48 )
{
struct V_49 * V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_91 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_85 -> V_72 == V_92 ||
V_85 -> V_72 == V_73 ) )
return;
V_11 = F_65 ( V_20 , V_23 , V_16 ) ;
if ( F_73 ( V_11 ) ) {
if ( F_57 ( V_11 -> V_52 ) ) {
if ( F_74 () )
F_70 ( V_7 , L_4
L_5 ,
V_85 -> V_27 -> V_89 ) ;
} else {
if ( F_57 ( V_85 != V_11 -> V_33 ) ) {
V_11 -> V_33 = V_85 ;
V_91 = true ;
}
V_11 -> V_13 = V_14 ;
if ( F_57 ( V_48 ) )
V_11 -> V_48 = 1 ;
if ( F_57 ( V_91 ) )
F_28 ( V_7 , V_11 , V_90 ) ;
}
} else {
F_47 ( & V_7 -> V_51 ) ;
if ( F_73 ( ! F_38 ( V_20 , V_23 , V_16 ) ) ) {
V_11 = F_66 ( V_20 , V_85 , V_23 , V_16 , 0 , 0 ) ;
if ( V_11 ) {
if ( F_57 ( V_48 ) )
V_11 -> V_48 = 1 ;
F_28 ( V_7 , V_11 , V_90 ) ;
}
}
F_50 ( & V_7 -> V_51 ) ;
}
}
static int F_75 ( const struct V_6 * V_7 ,
const struct V_2 * V_11 )
{
if ( V_11 -> V_52 )
return V_93 ;
else if ( V_11 -> V_12 )
return V_94 ;
else if ( F_7 ( V_7 , V_11 ) )
return V_95 ;
else
return V_96 ;
}
static int F_76 ( struct V_97 * V_98 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_99 , T_3 V_100 , int type , unsigned int V_36 )
{
unsigned long V_101 = V_14 ;
struct V_102 V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
V_105 = F_77 ( V_98 , V_99 , V_100 , type , sizeof( * V_107 ) , V_36 ) ;
if ( V_105 == NULL )
return - V_108 ;
V_107 = F_78 ( V_105 ) ;
V_107 -> V_109 = V_110 ;
V_107 -> V_111 = 0 ;
V_107 -> V_112 = 0 ;
V_107 -> V_113 = V_11 -> V_39 ? V_114 : 0 ;
V_107 -> V_115 = 0 ;
V_107 -> V_116 = V_11 -> V_33 ? V_11 -> V_33 -> V_27 -> V_117 : V_7 -> V_27 -> V_117 ;
V_107 -> V_118 = F_75 ( V_7 , V_11 ) ;
if ( F_79 ( V_98 , V_119 , V_81 , & V_11 -> V_23 ) )
goto V_120;
if ( F_80 ( V_98 , V_121 , V_7 -> V_27 -> V_117 ) )
goto V_120;
V_103 . V_122 = F_81 ( V_101 - V_11 -> V_87 ) ;
V_103 . V_123 = 0 ;
V_103 . V_124 = F_81 ( V_101 - V_11 -> V_13 ) ;
V_103 . V_125 = 0 ;
if ( F_79 ( V_98 , V_126 , sizeof( V_103 ) , & V_103 ) )
goto V_120;
if ( V_11 -> V_38 && F_79 ( V_98 , V_127 , sizeof( T_4 ) , & V_11 -> V_38 ) )
goto V_120;
F_82 ( V_98 , V_105 ) ;
return 0 ;
V_120:
F_83 ( V_98 , V_105 ) ;
return - V_108 ;
}
static inline T_6 F_84 ( void )
{
return F_85 ( sizeof( struct V_106 ) )
+ F_86 ( V_81 )
+ F_86 ( sizeof( T_3 ) )
+ F_86 ( sizeof( T_4 ) )
+ F_86 ( sizeof( struct V_102 ) ) ;
}
static void F_28 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_128 * V_128 = F_87 ( V_7 -> V_27 ) ;
struct V_97 * V_98 ;
int V_24 = - V_129 ;
V_98 = F_88 ( F_84 () , V_86 ) ;
if ( V_98 == NULL )
goto V_130;
V_24 = F_76 ( V_98 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_24 < 0 ) {
F_89 ( V_24 == - V_108 ) ;
F_90 ( V_98 ) ;
goto V_130;
}
F_91 ( V_98 , V_128 , 0 , V_131 , NULL , V_86 ) ;
return;
V_130:
F_92 ( V_128 , V_131 , V_24 ) ;
}
int F_93 ( struct V_97 * V_98 ,
struct V_132 * V_133 ,
struct V_69 * V_27 ,
struct V_69 * V_134 ,
int V_135 )
{
struct V_6 * V_7 = F_94 ( V_27 ) ;
int V_54 ;
if ( ! ( V_27 -> V_136 & V_137 ) )
goto V_60;
if ( ! V_134 )
V_135 = F_95 ( V_98 , V_133 , V_27 , NULL , V_135 ) ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
struct V_2 * V_29 ;
F_56 (f, &br->hash[i], hlist) {
int V_24 ;
if ( V_135 < V_133 -> args [ 0 ] )
goto V_76;
if ( V_134 &&
( ! V_29 -> V_33 || V_29 -> V_33 -> V_27 != V_134 ) ) {
if ( V_134 != V_27 )
goto V_76;
if ( V_29 -> V_33 )
goto V_76;
}
if ( ! V_134 && V_29 -> V_33 )
goto V_76;
V_24 = F_76 ( V_98 , V_7 , V_29 ,
F_96 ( V_133 -> V_98 ) . V_99 ,
V_133 -> V_105 -> V_138 ,
V_90 ,
V_139 ) ;
if ( V_24 < 0 ) {
V_133 -> args [ 1 ] = V_24 ;
break;
}
V_76:
++ V_135 ;
}
}
V_60:
return V_135 ;
}
static int F_97 ( struct V_25 * V_85 , const T_7 * V_23 ,
T_2 V_72 , T_2 V_36 , T_2 V_16 )
{
struct V_6 * V_7 = V_85 -> V_7 ;
struct V_49 * V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_140 = false ;
if ( ! ( V_72 & V_93 ) && ! ( V_72 & V_94 ) &&
! ( V_85 -> V_72 == V_92 ||
V_85 -> V_72 == V_73 ) )
return - V_141 ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_36 & V_142 ) )
return - V_143 ;
V_11 = F_66 ( V_20 , V_85 , V_23 , V_16 , 0 , 0 ) ;
if ( ! V_11 )
return - V_4 ;
V_140 = true ;
} else {
if ( V_36 & V_144 )
return - V_145 ;
if ( V_11 -> V_33 != V_85 ) {
V_11 -> V_33 = V_85 ;
V_140 = true ;
}
}
if ( F_75 ( V_7 , V_11 ) != V_72 ) {
if ( V_72 & V_93 ) {
V_11 -> V_52 = 1 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else if ( V_72 & V_94 ) {
V_11 -> V_52 = 0 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else {
V_11 -> V_52 = 0 ;
if ( V_11 -> V_12 ) {
V_11 -> V_12 = 0 ;
F_22 ( V_7 , V_23 ) ;
}
}
V_140 = true ;
}
V_11 -> V_48 = 1 ;
V_11 -> V_87 = V_14 ;
if ( V_140 ) {
V_11 -> V_13 = V_14 ;
F_28 ( V_7 , V_11 , V_90 ) ;
}
return 0 ;
}
static int F_98 ( struct V_106 * V_107 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_146 , T_4 V_16 )
{
int V_24 = 0 ;
if ( V_107 -> V_113 & V_147 ) {
F_99 () ;
F_59 () ;
F_72 ( V_26 -> V_7 , V_26 , V_23 , V_16 , true ) ;
F_61 () ;
F_100 () ;
} else {
F_37 ( & V_26 -> V_7 -> V_51 ) ;
V_24 = F_97 ( V_26 , V_23 , V_107 -> V_118 ,
V_146 , V_16 ) ;
F_39 ( & V_26 -> V_7 -> V_51 ) ;
}
return V_24 ;
}
int F_101 ( struct V_106 * V_107 , struct V_148 * V_149 [] ,
struct V_69 * V_27 ,
const unsigned char * V_23 , T_4 V_16 , T_4 V_146 )
{
struct V_42 * V_43 ;
struct V_25 * V_26 = NULL ;
struct V_44 * V_45 ;
struct V_6 * V_7 = NULL ;
int V_24 = 0 ;
if ( ! ( V_107 -> V_118 & ( V_93 | V_94 | V_96 ) ) ) {
F_102 ( L_6 , V_107 -> V_118 ) ;
return - V_88 ;
}
if ( F_103 ( V_23 ) ) {
F_102 ( L_7 ) ;
return - V_88 ;
}
if ( V_27 -> V_136 & V_137 ) {
V_7 = F_94 ( V_27 ) ;
V_43 = F_34 ( V_7 ) ;
} else {
V_26 = F_104 ( V_27 ) ;
if ( ! V_26 ) {
F_102 ( L_8 ,
V_27 -> V_89 ) ;
return - V_88 ;
}
V_43 = F_31 ( V_26 ) ;
}
if ( V_16 ) {
V_45 = F_33 ( V_43 , V_16 ) ;
if ( ! V_45 || ! F_35 ( V_45 ) ) {
F_102 ( L_9 , V_16 , V_27 -> V_89 ) ;
return - V_88 ;
}
if ( V_27 -> V_136 & V_137 )
V_24 = F_71 ( V_7 , NULL , V_23 , V_16 ) ;
else
V_24 = F_98 ( V_107 , V_26 , V_23 , V_146 , V_16 ) ;
} else {
if ( V_27 -> V_136 & V_137 )
V_24 = F_71 ( V_7 , NULL , V_23 , 0 ) ;
else
V_24 = F_98 ( V_107 , V_26 , V_23 , V_146 , 0 ) ;
if ( V_24 || ! V_43 || ! V_43 -> V_57 )
goto V_60;
F_17 (v, &vg->vlan_list, vlist) {
if ( ! F_35 ( V_45 ) )
continue;
if ( V_27 -> V_136 & V_137 )
V_24 = F_71 ( V_7 , NULL , V_23 , V_45 -> V_16 ) ;
else
V_24 = F_98 ( V_107 , V_26 , V_23 , V_146 ,
V_45 -> V_16 ) ;
if ( V_24 )
goto V_60;
}
}
V_60:
return V_24 ;
}
static int F_105 ( struct V_6 * V_7 , const T_5 * V_23 ,
T_4 V_16 )
{
struct V_49 * V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_143 ;
F_26 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_6 * V_7 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_24 ;
F_37 ( & V_7 -> V_51 ) ;
V_24 = F_105 ( V_7 , V_23 , V_16 ) ;
F_39 ( & V_7 -> V_51 ) ;
return V_24 ;
}
static int F_107 ( struct V_25 * V_26 ,
const T_5 * V_23 , T_4 V_150 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_49 * V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_150 ) ] ;
struct V_2 * V_11 ;
V_11 = F_38 ( V_20 , V_23 , V_150 ) ;
if ( ! V_11 || V_11 -> V_33 != V_26 )
return - V_143 ;
F_26 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_108 ( struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_24 ;
F_37 ( & V_26 -> V_7 -> V_51 ) ;
V_24 = F_107 ( V_26 , V_23 , V_16 ) ;
F_39 ( & V_26 -> V_7 -> V_51 ) ;
return V_24 ;
}
int F_109 ( struct V_106 * V_107 , struct V_148 * V_149 [] ,
struct V_69 * V_27 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_42 * V_43 ;
struct V_25 * V_26 = NULL ;
struct V_44 * V_45 ;
struct V_6 * V_7 = NULL ;
int V_24 ;
if ( V_27 -> V_136 & V_137 ) {
V_7 = F_94 ( V_27 ) ;
V_43 = F_34 ( V_7 ) ;
} else {
V_26 = F_104 ( V_27 ) ;
if ( ! V_26 ) {
F_102 ( L_10 ,
V_27 -> V_89 ) ;
return - V_88 ;
}
V_43 = F_31 ( V_26 ) ;
}
if ( V_16 ) {
V_45 = F_33 ( V_43 , V_16 ) ;
if ( ! V_45 ) {
F_102 ( L_11 , V_16 , V_27 -> V_89 ) ;
return - V_88 ;
}
if ( V_27 -> V_136 & V_137 )
V_24 = F_106 ( V_7 , V_23 , V_16 ) ;
else
V_24 = F_108 ( V_26 , V_23 , V_16 ) ;
} else {
V_24 = - V_143 ;
if ( V_27 -> V_136 & V_137 )
V_24 = F_106 ( V_7 , V_23 , 0 ) ;
else
V_24 &= F_108 ( V_26 , V_23 , 0 ) ;
if ( ! V_43 || ! V_43 -> V_57 )
goto V_60;
F_17 (v, &vg->vlan_list, vlist) {
if ( ! F_35 ( V_45 ) )
continue;
if ( V_27 -> V_136 & V_137 )
V_24 = F_106 ( V_7 , V_23 , V_45 -> V_16 ) ;
else
V_24 &= F_108 ( V_26 , V_23 , V_45 -> V_16 ) ;
}
}
V_60:
return V_24 ;
}
int F_110 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 , * V_151 ;
int V_54 ;
int V_24 ;
F_16 () ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
F_64 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
V_24 = F_19 ( V_26 -> V_27 , V_11 -> V_23 . V_23 ) ;
if ( V_24 )
goto V_152;
}
}
return 0 ;
V_152:
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
F_64 (tmp, &br->hash[i], hlist) {
if ( V_151 == V_11 )
break;
if ( ! V_151 -> V_12 )
continue;
F_21 ( V_26 -> V_27 , V_151 -> V_23 . V_23 ) ;
}
}
return V_24 ;
}
void F_111 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 ;
int V_54 ;
F_16 () ;
for ( V_54 = 0 ; V_54 < V_18 ; V_54 ++ ) {
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
struct V_49 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_37 ( & V_7 -> V_51 ) ;
V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( ! V_11 ) {
V_11 = F_66 ( V_20 , V_26 , V_23 , V_16 , 0 , 0 ) ;
if ( ! V_11 ) {
V_24 = - V_4 ;
goto V_153;
}
V_11 -> V_39 = 1 ;
F_28 ( V_7 , V_11 , V_90 ) ;
} else if ( V_11 -> V_39 ) {
V_11 -> V_13 = V_11 -> V_87 = V_14 ;
} else if ( ! V_11 -> V_48 ) {
V_11 -> V_39 = 1 ;
V_11 -> V_13 = V_14 ;
F_28 ( V_7 , V_11 , V_90 ) ;
}
V_153:
F_39 ( & V_7 -> V_51 ) ;
return V_24 ;
}
int F_113 ( struct V_6 * V_7 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_49 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_37 ( & V_7 -> V_51 ) ;
V_20 = & V_7 -> V_50 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_38 ( V_20 , V_23 , V_16 ) ;
if ( V_11 && V_11 -> V_39 )
F_26 ( V_7 , V_11 ) ;
else
V_24 = - V_143 ;
F_39 ( & V_7 -> V_51 ) ;
return V_24 ;
}
