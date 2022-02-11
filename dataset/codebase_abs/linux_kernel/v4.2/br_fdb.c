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
struct V_30 V_31 = {
. V_32 = V_33 ,
. V_34 . V_11 = {
. V_23 = V_29 -> V_23 . V_23 ,
. V_16 = V_29 -> V_35 ,
} ,
} ;
F_24 ( V_29 -> V_36 -> V_27 , & V_31 ) ;
}
static void F_25 ( struct V_6 * V_7 , struct V_2 * V_29 )
{
if ( V_29 -> V_12 )
F_22 ( V_7 , V_29 -> V_23 . V_23 ) ;
if ( V_29 -> V_37 )
F_23 ( V_29 ) ;
F_26 ( & V_29 -> V_38 ) ;
F_27 ( V_7 , V_29 , V_39 ) ;
F_28 ( & V_29 -> V_22 , F_12 ) ;
}
static void F_29 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
struct V_2 * V_29 )
{
const unsigned char * V_23 = V_29 -> V_23 . V_23 ;
T_4 V_16 = V_29 -> V_35 ;
struct V_25 * V_40 ;
F_17 (op, &br->port_list, list) {
if ( V_40 != V_26 && F_30 ( V_40 -> V_27 -> V_41 , V_23 ) &&
( ! V_16 || F_31 ( V_40 , V_16 ) ) ) {
V_29 -> V_36 = V_40 ;
V_29 -> V_42 = 0 ;
return;
}
}
if ( V_26 && F_30 ( V_7 -> V_27 -> V_41 , V_23 ) &&
( ! V_16 || F_32 ( V_7 , V_16 ) ) ) {
V_29 -> V_36 = NULL ;
V_29 -> V_42 = 0 ;
return;
}
F_25 ( V_7 , V_29 ) ;
}
void F_33 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_43 * V_20 = & V_7 -> V_44 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_29 ;
F_34 ( & V_7 -> V_45 ) ;
V_29 = F_35 ( V_20 , V_23 , V_16 ) ;
if ( V_29 && V_29 -> V_46 && ! V_29 -> V_42 && V_29 -> V_36 == V_26 )
F_29 ( V_7 , V_26 , V_29 ) ;
F_36 ( & V_7 -> V_45 ) ;
}
void F_37 ( struct V_25 * V_26 , const unsigned char * V_47 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_48 * V_49 = F_38 ( V_26 ) ;
bool V_50 = ! V_49 ;
int V_51 ;
T_4 V_16 ;
F_34 ( & V_7 -> V_45 ) ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
struct V_52 * V_53 ;
F_39 (h, &br->hash[i]) {
struct V_2 * V_29 ;
V_29 = F_40 ( V_53 , struct V_2 , V_38 ) ;
if ( V_29 -> V_36 == V_26 && V_29 -> V_46 && ! V_29 -> V_42 ) {
F_29 ( V_7 , V_26 , V_29 ) ;
if ( V_50 )
goto V_54;
}
}
}
V_54:
F_41 ( V_7 , V_26 , V_47 , 0 ) ;
if ( V_50 )
goto V_55;
F_42 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_41 ( V_7 , V_26 , V_47 , V_16 ) ;
V_55:
F_36 ( & V_7 -> V_45 ) ;
}
void F_43 ( struct V_6 * V_7 , const T_5 * V_47 )
{
struct V_2 * V_29 ;
struct V_48 * V_49 ;
T_4 V_16 = 0 ;
F_34 ( & V_7 -> V_45 ) ;
V_29 = F_44 ( V_7 , V_7 -> V_27 -> V_41 , 0 ) ;
if ( V_29 && V_29 -> V_46 && ! V_29 -> V_36 )
F_29 ( V_7 , NULL , V_29 ) ;
F_41 ( V_7 , NULL , V_47 , 0 ) ;
V_49 = F_45 ( V_7 ) ;
if ( ! V_49 )
goto V_56;
F_46 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_29 = F_44 ( V_7 , V_7 -> V_27 -> V_41 , V_16 ) ;
if ( V_29 && V_29 -> V_46 && ! V_29 -> V_36 )
F_29 ( V_7 , NULL , V_29 ) ;
F_41 ( V_7 , NULL , V_47 , V_16 ) ;
}
V_56:
F_36 ( & V_7 -> V_45 ) ;
}
void F_47 ( unsigned long V_57 )
{
struct V_6 * V_7 = (struct V_6 * ) V_57 ;
unsigned long V_58 = F_6 ( V_7 ) ;
unsigned long V_59 = V_14 + V_7 -> V_10 ;
int V_51 ;
F_48 ( & V_7 -> V_45 ) ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
struct V_2 * V_29 ;
struct V_52 * V_60 ;
F_49 (f, n, &br->hash[i], hlist) {
unsigned long V_61 ;
if ( V_29 -> V_12 )
continue;
V_61 = V_29 -> V_13 + V_58 ;
if ( F_8 ( V_61 , V_14 ) )
F_25 ( V_7 , V_29 ) ;
else if ( F_50 ( V_61 , V_59 ) )
V_59 = V_61 ;
}
}
F_51 ( & V_7 -> V_45 ) ;
F_52 ( & V_7 -> V_62 , F_53 ( V_59 ) ) ;
}
void F_54 ( struct V_6 * V_7 )
{
int V_51 ;
F_34 ( & V_7 -> V_45 ) ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
struct V_2 * V_29 ;
struct V_52 * V_60 ;
F_49 (f, n, &br->hash[i], hlist) {
if ( ! V_29 -> V_12 )
F_25 ( V_7 , V_29 ) ;
}
}
F_36 ( & V_7 -> V_45 ) ;
}
void F_55 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
T_4 V_16 ,
int V_63 )
{
int V_51 ;
F_34 ( & V_7 -> V_45 ) ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
struct V_52 * V_53 , * V_64 ;
F_56 (h, g, &br->hash[i]) {
struct V_2 * V_29
= F_40 ( V_53 , struct V_2 , V_38 ) ;
if ( V_29 -> V_36 != V_26 )
continue;
if ( ! V_63 )
if ( V_29 -> V_12 || ( V_16 && V_29 -> V_35 != V_16 ) )
continue;
if ( V_29 -> V_46 )
F_29 ( V_7 , V_26 , V_29 ) ;
else
F_25 ( V_7 , V_29 ) ;
}
}
F_36 ( & V_7 -> V_45 ) ;
}
struct V_2 * F_44 ( struct V_6 * V_7 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_57 (fdb,
&br->hash[br_mac_hash(addr, vid)], hlist) {
if ( F_30 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_35 == V_16 ) {
if ( F_58 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_59 ( struct V_65 * V_27 , unsigned char * V_23 )
{
struct V_2 * V_11 ;
struct V_25 * V_66 ;
int V_67 ;
F_60 () ;
V_66 = F_61 ( V_27 ) ;
if ( ! V_66 )
V_67 = 0 ;
else {
V_11 = F_44 ( V_66 -> V_7 , V_23 , 0 ) ;
V_67 = V_11 && V_11 -> V_36 && V_11 -> V_36 -> V_27 != V_27 &&
V_11 -> V_36 -> V_68 == V_69 ;
}
F_62 () ;
return V_67 ;
}
int F_63 ( struct V_6 * V_7 , void * V_70 ,
unsigned long V_71 , unsigned long V_72 )
{
struct V_73 * V_74 = V_70 ;
int V_51 , V_75 = 0 ;
struct V_2 * V_29 ;
memset ( V_70 , 0 , V_71 * sizeof( struct V_73 ) ) ;
F_60 () ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
F_57 (f, &br->hash[i], hlist) {
if ( V_75 >= V_71 )
goto V_56;
if ( F_7 ( V_7 , V_29 ) )
continue;
if ( ! V_29 -> V_36 )
continue;
if ( V_72 ) {
-- V_72 ;
continue;
}
memcpy ( V_74 -> V_76 , V_29 -> V_23 . V_23 , V_77 ) ;
V_74 -> V_78 = V_29 -> V_36 -> V_78 ;
V_74 -> V_79 = V_29 -> V_36 -> V_78 >> 8 ;
V_74 -> V_46 = V_29 -> V_46 ;
if ( ! V_29 -> V_12 )
V_74 -> V_80 = F_64 ( V_14 - V_29 -> V_13 ) ;
++ V_74 ;
++ V_75 ;
}
}
V_56:
F_62 () ;
return V_75 ;
}
static struct V_2 * F_35 ( struct V_43 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_65 (fdb, head, hlist) {
if ( F_30 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_35 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_66 ( struct V_43 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_57 (fdb, head, hlist) {
if ( F_30 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_35 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_67 ( struct V_43 * V_20 ,
struct V_25 * V_81 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
V_11 = F_68 ( V_1 , V_82 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_23 . V_23 , V_23 , V_77 ) ;
V_11 -> V_36 = V_81 ;
V_11 -> V_35 = V_16 ;
V_11 -> V_46 = 0 ;
V_11 -> V_12 = 0 ;
V_11 -> V_42 = 0 ;
V_11 -> V_37 = 0 ;
V_11 -> V_13 = V_11 -> V_83 = V_14 ;
F_69 ( & V_11 -> V_38 , V_20 ) ;
}
return V_11 ;
}
static int F_41 ( struct V_6 * V_7 , struct V_25 * V_81 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_43 * V_20 = & V_7 -> V_44 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( ! F_70 ( V_23 ) )
return - V_84 ;
V_11 = F_35 ( V_20 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( V_11 -> V_46 )
return 0 ;
F_71 ( V_7 , L_2
L_3 ,
V_81 ? V_81 -> V_27 -> V_85 : V_7 -> V_27 -> V_85 ) ;
F_25 ( V_7 , V_11 ) ;
}
V_11 = F_67 ( V_20 , V_81 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_11 -> V_46 = V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
F_27 ( V_7 , V_11 , V_86 ) ;
return 0 ;
}
int F_72 ( struct V_6 * V_7 , struct V_25 * V_81 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_67 ;
F_34 ( & V_7 -> V_45 ) ;
V_67 = F_41 ( V_7 , V_81 , V_23 , V_16 ) ;
F_36 ( & V_7 -> V_45 ) ;
return V_67 ;
}
void F_73 ( struct V_6 * V_7 , struct V_25 * V_81 ,
const unsigned char * V_23 , T_4 V_16 , bool V_42 )
{
struct V_43 * V_20 = & V_7 -> V_44 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_87 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_81 -> V_68 == V_88 ||
V_81 -> V_68 == V_69 ) )
return;
V_11 = F_66 ( V_20 , V_23 , V_16 ) ;
if ( F_74 ( V_11 ) ) {
if ( F_58 ( V_11 -> V_46 ) ) {
if ( F_75 () )
F_71 ( V_7 , L_4
L_5 ,
V_81 -> V_27 -> V_85 ) ;
} else {
if ( F_58 ( V_81 != V_11 -> V_36 ) ) {
V_11 -> V_36 = V_81 ;
V_87 = true ;
}
V_11 -> V_13 = V_14 ;
if ( F_58 ( V_42 ) )
V_11 -> V_42 = 1 ;
if ( F_58 ( V_87 ) )
F_27 ( V_7 , V_11 , V_86 ) ;
}
} else {
F_48 ( & V_7 -> V_45 ) ;
if ( F_74 ( ! F_35 ( V_20 , V_23 , V_16 ) ) ) {
V_11 = F_67 ( V_20 , V_81 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( F_58 ( V_42 ) )
V_11 -> V_42 = 1 ;
F_27 ( V_7 , V_11 , V_86 ) ;
}
}
F_51 ( & V_7 -> V_45 ) ;
}
}
static int F_76 ( const struct V_2 * V_11 )
{
if ( V_11 -> V_46 )
return V_89 ;
else if ( V_11 -> V_12 )
return V_90 ;
else if ( F_7 ( V_11 -> V_36 -> V_7 , V_11 ) )
return V_91 ;
else
return V_92 ;
}
static int F_77 ( struct V_93 * V_94 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_95 , T_3 V_96 , int type , unsigned int V_97 )
{
unsigned long V_98 = V_14 ;
struct V_99 V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
V_102 = F_78 ( V_94 , V_95 , V_96 , type , sizeof( * V_104 ) , V_97 ) ;
if ( V_102 == NULL )
return - V_105 ;
V_104 = F_79 ( V_102 ) ;
V_104 -> V_106 = V_107 ;
V_104 -> V_108 = 0 ;
V_104 -> V_109 = 0 ;
V_104 -> V_110 = V_11 -> V_37 ? V_111 : 0 ;
V_104 -> V_112 = 0 ;
V_104 -> V_113 = V_11 -> V_36 ? V_11 -> V_36 -> V_27 -> V_114 : V_7 -> V_27 -> V_114 ;
V_104 -> V_115 = F_76 ( V_11 ) ;
if ( F_80 ( V_94 , V_116 , V_77 , & V_11 -> V_23 ) )
goto V_117;
if ( F_81 ( V_94 , V_118 , V_7 -> V_27 -> V_114 ) )
goto V_117;
V_100 . V_119 = F_82 ( V_98 - V_11 -> V_83 ) ;
V_100 . V_120 = 0 ;
V_100 . V_121 = F_82 ( V_98 - V_11 -> V_13 ) ;
V_100 . V_122 = 0 ;
if ( F_80 ( V_94 , V_123 , sizeof( V_100 ) , & V_100 ) )
goto V_117;
if ( V_11 -> V_35 && F_80 ( V_94 , V_124 , sizeof( T_4 ) , & V_11 -> V_35 ) )
goto V_117;
F_83 ( V_94 , V_102 ) ;
return 0 ;
V_117:
F_84 ( V_94 , V_102 ) ;
return - V_105 ;
}
static inline T_6 F_85 ( void )
{
return F_86 ( sizeof( struct V_103 ) )
+ F_87 ( V_77 )
+ F_87 ( sizeof( T_3 ) )
+ F_87 ( sizeof( T_4 ) )
+ F_87 ( sizeof( struct V_99 ) ) ;
}
static void F_27 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_125 * V_125 = F_88 ( V_7 -> V_27 ) ;
struct V_93 * V_94 ;
int V_24 = - V_126 ;
V_94 = F_89 ( F_85 () , V_82 ) ;
if ( V_94 == NULL )
goto V_127;
V_24 = F_77 ( V_94 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_24 < 0 ) {
F_90 ( V_24 == - V_105 ) ;
F_91 ( V_94 ) ;
goto V_127;
}
F_92 ( V_94 , V_125 , 0 , V_128 , NULL , V_82 ) ;
return;
V_127:
F_93 ( V_125 , V_128 , V_24 ) ;
}
int F_94 ( struct V_93 * V_94 ,
struct V_129 * V_130 ,
struct V_65 * V_27 ,
struct V_65 * V_131 ,
int V_132 )
{
struct V_6 * V_7 = F_95 ( V_27 ) ;
int V_51 ;
if ( ! ( V_27 -> V_133 & V_134 ) )
goto V_56;
if ( ! V_131 )
V_132 = F_96 ( V_94 , V_130 , V_27 , NULL , V_132 ) ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
struct V_2 * V_29 ;
F_57 (f, &br->hash[i], hlist) {
if ( V_132 < V_130 -> args [ 0 ] )
goto V_72;
if ( V_131 &&
( ! V_29 -> V_36 || V_29 -> V_36 -> V_27 != V_131 ) ) {
if ( V_131 != V_27 )
goto V_72;
if ( V_29 -> V_36 )
goto V_72;
}
if ( ! V_131 && V_29 -> V_36 )
goto V_72;
if ( F_77 ( V_94 , V_7 , V_29 ,
F_97 ( V_130 -> V_94 ) . V_95 ,
V_130 -> V_102 -> V_135 ,
V_86 ,
V_136 ) < 0 )
break;
V_72:
++ V_132 ;
}
}
V_56:
return V_132 ;
}
static int F_98 ( struct V_25 * V_81 , const T_7 * V_23 ,
T_2 V_68 , T_2 V_97 , T_2 V_16 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
struct V_43 * V_20 = & V_7 -> V_44 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_137 = false ;
if ( ! ( V_68 & V_89 ) && ! ( V_68 & V_90 ) &&
! ( V_81 -> V_68 == V_88 ||
V_81 -> V_68 == V_69 ) )
return - V_138 ;
V_11 = F_35 ( V_20 , V_23 , V_16 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_97 & V_139 ) )
return - V_140 ;
V_11 = F_67 ( V_20 , V_81 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_137 = true ;
} else {
if ( V_97 & V_141 )
return - V_142 ;
if ( V_11 -> V_36 != V_81 ) {
V_11 -> V_36 = V_81 ;
V_137 = true ;
}
}
if ( F_76 ( V_11 ) != V_68 ) {
if ( V_68 & V_89 ) {
V_11 -> V_46 = 1 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else if ( V_68 & V_90 ) {
V_11 -> V_46 = 0 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else {
V_11 -> V_46 = 0 ;
if ( V_11 -> V_12 ) {
V_11 -> V_12 = 0 ;
F_22 ( V_7 , V_23 ) ;
}
}
V_137 = true ;
}
V_11 -> V_42 = 1 ;
V_11 -> V_83 = V_14 ;
if ( V_137 ) {
V_11 -> V_13 = V_14 ;
F_27 ( V_7 , V_11 , V_86 ) ;
}
return 0 ;
}
static int F_99 ( struct V_103 * V_104 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_143 , T_4 V_16 )
{
int V_24 = 0 ;
if ( V_104 -> V_110 & V_144 ) {
F_100 () ;
F_60 () ;
F_73 ( V_26 -> V_7 , V_26 , V_23 , V_16 , true ) ;
F_62 () ;
F_101 () ;
} else {
F_34 ( & V_26 -> V_7 -> V_45 ) ;
V_24 = F_98 ( V_26 , V_23 , V_104 -> V_115 ,
V_143 , V_16 ) ;
F_36 ( & V_26 -> V_7 -> V_45 ) ;
}
return V_24 ;
}
int F_102 ( struct V_103 * V_104 , struct V_145 * V_146 [] ,
struct V_65 * V_27 ,
const unsigned char * V_23 , T_4 V_16 , T_4 V_143 )
{
struct V_25 * V_26 ;
int V_24 = 0 ;
struct V_48 * V_49 ;
if ( ! ( V_104 -> V_115 & ( V_89 | V_90 | V_92 ) ) ) {
F_103 ( L_6 , V_104 -> V_115 ) ;
return - V_84 ;
}
if ( F_104 ( V_23 ) ) {
F_103 ( L_7 ) ;
return - V_84 ;
}
V_26 = F_105 ( V_27 ) ;
if ( V_26 == NULL ) {
F_103 ( L_8 ,
V_27 -> V_85 ) ;
return - V_84 ;
}
V_49 = F_38 ( V_26 ) ;
if ( V_16 ) {
if ( ! V_49 || ! F_106 ( V_16 , V_49 -> V_147 ) ) {
F_103 ( L_9
L_10 , V_16 , V_27 -> V_85 ) ;
return - V_84 ;
}
V_24 = F_99 ( V_104 , V_26 , V_23 , V_143 , V_16 ) ;
} else {
V_24 = F_99 ( V_104 , V_26 , V_23 , V_143 , 0 ) ;
if ( V_24 || ! V_49 )
goto V_56;
F_42 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_24 = F_99 ( V_104 , V_26 , V_23 , V_143 , V_16 ) ;
if ( V_24 )
goto V_56;
}
}
V_56:
return V_24 ;
}
static int F_107 ( struct V_25 * V_26 ,
const T_5 * V_23 , T_4 V_148 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_43 * V_20 = & V_7 -> V_44 [ F_9 ( V_23 , V_148 ) ] ;
struct V_2 * V_11 ;
V_11 = F_35 ( V_20 , V_23 , V_148 ) ;
if ( ! V_11 || V_11 -> V_36 != V_26 )
return - V_140 ;
F_25 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_108 ( struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_24 ;
F_34 ( & V_26 -> V_7 -> V_45 ) ;
V_24 = F_107 ( V_26 , V_23 , V_16 ) ;
F_36 ( & V_26 -> V_7 -> V_45 ) ;
return V_24 ;
}
int F_109 ( struct V_103 * V_104 , struct V_145 * V_146 [] ,
struct V_65 * V_27 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_25 * V_26 ;
int V_24 ;
struct V_48 * V_49 ;
V_26 = F_105 ( V_27 ) ;
if ( V_26 == NULL ) {
F_103 ( L_11 ,
V_27 -> V_85 ) ;
return - V_84 ;
}
V_49 = F_38 ( V_26 ) ;
if ( V_16 ) {
if ( ! V_49 || ! F_106 ( V_16 , V_49 -> V_147 ) ) {
F_103 ( L_12
L_10 , V_16 , V_27 -> V_85 ) ;
return - V_84 ;
}
V_24 = F_108 ( V_26 , V_23 , V_16 ) ;
} else {
V_24 = - V_140 ;
V_24 &= F_108 ( V_26 , V_23 , 0 ) ;
if ( ! V_49 )
goto V_56;
F_42 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_24 &= F_108 ( V_26 , V_23 , V_16 ) ;
}
}
V_56:
return V_24 ;
}
int F_110 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 , * V_149 ;
int V_51 ;
int V_24 ;
F_16 () ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
F_65 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
V_24 = F_19 ( V_26 -> V_27 , V_11 -> V_23 . V_23 ) ;
if ( V_24 )
goto V_150;
}
}
return 0 ;
V_150:
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
F_65 (tmp, &br->hash[i], hlist) {
if ( V_149 == V_11 )
break;
if ( ! V_149 -> V_12 )
continue;
F_21 ( V_26 -> V_27 , V_149 -> V_23 . V_23 ) ;
}
}
return V_24 ;
}
void F_111 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 ;
int V_51 ;
F_16 () ;
for ( V_51 = 0 ; V_51 < V_18 ; V_51 ++ ) {
F_57 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
F_21 ( V_26 -> V_27 , V_11 -> V_23 . V_23 ) ;
}
}
}
int F_112 ( struct V_6 * V_7 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_43 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_34 ( & V_7 -> V_45 ) ;
V_20 = & V_7 -> V_44 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_35 ( V_20 , V_23 , V_16 ) ;
if ( ! V_11 ) {
V_11 = F_67 ( V_20 , V_26 , V_23 , V_16 ) ;
if ( ! V_11 ) {
V_24 = - V_4 ;
goto V_151;
}
V_11 -> V_37 = 1 ;
F_27 ( V_7 , V_11 , V_86 ) ;
} else if ( V_11 -> V_37 ) {
V_11 -> V_13 = V_11 -> V_83 = V_14 ;
} else if ( ! V_11 -> V_42 ) {
V_11 -> V_37 = 1 ;
V_11 -> V_13 = V_14 ;
F_27 ( V_7 , V_11 , V_86 ) ;
}
V_151:
F_36 ( & V_7 -> V_45 ) ;
return V_24 ;
}
int F_113 ( struct V_6 * V_7 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_43 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_34 ( & V_7 -> V_45 ) ;
V_20 = & V_7 -> V_44 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_35 ( V_20 , V_23 , V_16 ) ;
if ( V_11 && V_11 -> V_37 )
F_25 ( V_7 , V_11 ) ;
else
V_24 = - V_140 ;
F_36 ( & V_7 -> V_45 ) ;
return V_24 ;
}
