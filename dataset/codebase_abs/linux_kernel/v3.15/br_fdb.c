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
static void F_15 ( struct V_6 * V_7 , struct V_2 * V_23 )
{
F_16 ( & V_23 -> V_24 ) ;
F_17 ( V_7 , V_23 , V_25 ) ;
F_18 ( & V_23 -> V_22 , F_12 ) ;
}
static void F_19 ( struct V_6 * V_7 ,
const struct V_26 * V_27 ,
struct V_2 * V_23 )
{
const unsigned char * V_28 = V_23 -> V_28 . V_28 ;
T_4 V_16 = V_23 -> V_29 ;
struct V_26 * V_30 ;
F_20 (op, &br->port_list, list) {
if ( V_30 != V_27 && F_21 ( V_30 -> V_31 -> V_32 , V_28 ) &&
( ! V_16 || F_22 ( V_30 , V_16 ) ) ) {
V_23 -> V_33 = V_30 ;
V_23 -> V_34 = 0 ;
return;
}
}
if ( V_27 && F_21 ( V_7 -> V_31 -> V_32 , V_28 ) &&
( ! V_16 || F_23 ( V_7 , V_16 ) ) ) {
V_23 -> V_33 = NULL ;
V_23 -> V_34 = 0 ;
return;
}
F_15 ( V_7 , V_23 ) ;
}
void F_24 ( struct V_6 * V_7 ,
const struct V_26 * V_27 ,
const unsigned char * V_28 , T_4 V_16 )
{
struct V_35 * V_20 = & V_7 -> V_36 [ F_9 ( V_28 , V_16 ) ] ;
struct V_2 * V_23 ;
F_25 ( & V_7 -> V_37 ) ;
V_23 = F_26 ( V_20 , V_28 , V_16 ) ;
if ( V_23 && V_23 -> V_38 && ! V_23 -> V_34 && V_23 -> V_33 == V_27 )
F_19 ( V_7 , V_27 , V_23 ) ;
F_27 ( & V_7 -> V_37 ) ;
}
void F_28 ( struct V_26 * V_27 , const unsigned char * V_39 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
struct V_40 * V_41 = F_29 ( V_27 ) ;
bool V_42 = ! V_41 ;
int V_43 ;
T_4 V_16 ;
F_25 ( & V_7 -> V_37 ) ;
for ( V_43 = 0 ; V_43 < V_18 ; V_43 ++ ) {
struct V_44 * V_45 ;
F_30 (h, &br->hash[i]) {
struct V_2 * V_23 ;
V_23 = F_31 ( V_45 , struct V_2 , V_24 ) ;
if ( V_23 -> V_33 == V_27 && V_23 -> V_38 && ! V_23 -> V_34 ) {
F_19 ( V_7 , V_27 , V_23 ) ;
if ( V_42 )
goto V_46;
}
}
}
V_46:
F_32 ( V_7 , V_27 , V_39 , 0 ) ;
if ( V_42 )
goto V_47;
F_33 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_32 ( V_7 , V_27 , V_39 , V_16 ) ;
V_47:
F_27 ( & V_7 -> V_37 ) ;
}
void F_34 ( struct V_6 * V_7 , const T_5 * V_39 )
{
struct V_2 * V_23 ;
struct V_40 * V_41 ;
T_4 V_16 = 0 ;
F_25 ( & V_7 -> V_37 ) ;
V_23 = F_35 ( V_7 , V_7 -> V_31 -> V_32 , 0 ) ;
if ( V_23 && V_23 -> V_38 && ! V_23 -> V_33 )
F_19 ( V_7 , NULL , V_23 ) ;
F_32 ( V_7 , NULL , V_39 , 0 ) ;
V_41 = F_36 ( V_7 ) ;
if ( ! V_41 )
goto V_48;
F_37 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_23 = F_35 ( V_7 , V_7 -> V_31 -> V_32 , V_16 ) ;
if ( V_23 && V_23 -> V_38 && ! V_23 -> V_33 )
F_19 ( V_7 , NULL , V_23 ) ;
F_32 ( V_7 , NULL , V_39 , V_16 ) ;
}
V_48:
F_27 ( & V_7 -> V_37 ) ;
}
void F_38 ( unsigned long V_49 )
{
struct V_6 * V_7 = (struct V_6 * ) V_49 ;
unsigned long V_50 = F_6 ( V_7 ) ;
unsigned long V_51 = V_14 + V_7 -> V_10 ;
int V_43 ;
F_39 ( & V_7 -> V_37 ) ;
for ( V_43 = 0 ; V_43 < V_18 ; V_43 ++ ) {
struct V_2 * V_23 ;
struct V_44 * V_52 ;
F_40 (f, n, &br->hash[i], hlist) {
unsigned long V_53 ;
if ( V_23 -> V_12 )
continue;
V_53 = V_23 -> V_13 + V_50 ;
if ( F_8 ( V_53 , V_14 ) )
F_15 ( V_7 , V_23 ) ;
else if ( F_41 ( V_53 , V_51 ) )
V_51 = V_53 ;
}
}
F_42 ( & V_7 -> V_37 ) ;
F_43 ( & V_7 -> V_54 , F_44 ( V_51 ) ) ;
}
void F_45 ( struct V_6 * V_7 )
{
int V_43 ;
F_25 ( & V_7 -> V_37 ) ;
for ( V_43 = 0 ; V_43 < V_18 ; V_43 ++ ) {
struct V_2 * V_23 ;
struct V_44 * V_52 ;
F_40 (f, n, &br->hash[i], hlist) {
if ( ! V_23 -> V_12 )
F_15 ( V_7 , V_23 ) ;
}
}
F_27 ( & V_7 -> V_37 ) ;
}
void F_46 ( struct V_6 * V_7 ,
const struct V_26 * V_27 ,
int V_55 )
{
int V_43 ;
F_25 ( & V_7 -> V_37 ) ;
for ( V_43 = 0 ; V_43 < V_18 ; V_43 ++ ) {
struct V_44 * V_45 , * V_56 ;
F_47 (h, g, &br->hash[i]) {
struct V_2 * V_23
= F_31 ( V_45 , struct V_2 , V_24 ) ;
if ( V_23 -> V_33 != V_27 )
continue;
if ( V_23 -> V_12 && ! V_55 )
continue;
if ( V_23 -> V_38 )
F_19 ( V_7 , V_27 , V_23 ) ;
else
F_15 ( V_7 , V_23 ) ;
}
}
F_27 ( & V_7 -> V_37 ) ;
}
struct V_2 * F_35 ( struct V_6 * V_7 ,
const unsigned char * V_28 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_48 (fdb,
&br->hash[br_mac_hash(addr, vid)], hlist) {
if ( F_21 ( V_11 -> V_28 . V_28 , V_28 ) &&
V_11 -> V_29 == V_16 ) {
if ( F_49 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_50 ( struct V_57 * V_31 , unsigned char * V_28 )
{
struct V_2 * V_11 ;
struct V_26 * V_58 ;
int V_59 ;
F_51 () ;
V_58 = F_52 ( V_31 ) ;
if ( ! V_58 )
V_59 = 0 ;
else {
V_11 = F_35 ( V_58 -> V_7 , V_28 , 0 ) ;
V_59 = V_11 && V_11 -> V_33 && V_11 -> V_33 -> V_31 != V_31 &&
V_11 -> V_33 -> V_60 == V_61 ;
}
F_53 () ;
return V_59 ;
}
int F_54 ( struct V_6 * V_7 , void * V_62 ,
unsigned long V_63 , unsigned long V_64 )
{
struct V_65 * V_66 = V_62 ;
int V_43 , V_67 = 0 ;
struct V_2 * V_23 ;
memset ( V_62 , 0 , V_63 * sizeof( struct V_65 ) ) ;
F_51 () ;
for ( V_43 = 0 ; V_43 < V_18 ; V_43 ++ ) {
F_48 (f, &br->hash[i], hlist) {
if ( V_67 >= V_63 )
goto V_48;
if ( F_7 ( V_7 , V_23 ) )
continue;
if ( ! V_23 -> V_33 )
continue;
if ( V_64 ) {
-- V_64 ;
continue;
}
memcpy ( V_66 -> V_68 , V_23 -> V_28 . V_28 , V_69 ) ;
V_66 -> V_70 = V_23 -> V_33 -> V_70 ;
V_66 -> V_71 = V_23 -> V_33 -> V_70 >> 8 ;
V_66 -> V_38 = V_23 -> V_38 ;
if ( ! V_23 -> V_12 )
V_66 -> V_72 = F_55 ( V_14 - V_23 -> V_13 ) ;
++ V_66 ;
++ V_67 ;
}
}
V_48:
F_53 () ;
return V_67 ;
}
static struct V_2 * F_26 ( struct V_35 * V_20 ,
const unsigned char * V_28 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_56 (fdb, head, hlist) {
if ( F_21 ( V_11 -> V_28 . V_28 , V_28 ) &&
V_11 -> V_29 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_57 ( struct V_35 * V_20 ,
const unsigned char * V_28 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_48 (fdb, head, hlist) {
if ( F_21 ( V_11 -> V_28 . V_28 , V_28 ) &&
V_11 -> V_29 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_58 ( struct V_35 * V_20 ,
struct V_26 * V_73 ,
const unsigned char * V_28 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
V_11 = F_59 ( V_1 , V_74 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_28 . V_28 , V_28 , V_69 ) ;
V_11 -> V_33 = V_73 ;
V_11 -> V_29 = V_16 ;
V_11 -> V_38 = 0 ;
V_11 -> V_12 = 0 ;
V_11 -> V_34 = 0 ;
V_11 -> V_13 = V_11 -> V_75 = V_14 ;
F_60 ( & V_11 -> V_24 , V_20 ) ;
}
return V_11 ;
}
static int F_32 ( struct V_6 * V_7 , struct V_26 * V_73 ,
const unsigned char * V_28 , T_4 V_16 )
{
struct V_35 * V_20 = & V_7 -> V_36 [ F_9 ( V_28 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( ! F_61 ( V_28 ) )
return - V_76 ;
V_11 = F_26 ( V_20 , V_28 , V_16 ) ;
if ( V_11 ) {
if ( V_11 -> V_38 )
return 0 ;
F_62 ( V_7 , L_2
L_3 ,
V_73 ? V_73 -> V_31 -> V_77 : V_7 -> V_31 -> V_77 ) ;
F_15 ( V_7 , V_11 ) ;
}
V_11 = F_58 ( V_20 , V_73 , V_28 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_11 -> V_38 = V_11 -> V_12 = 1 ;
F_17 ( V_7 , V_11 , V_78 ) ;
return 0 ;
}
int F_63 ( struct V_6 * V_7 , struct V_26 * V_73 ,
const unsigned char * V_28 , T_4 V_16 )
{
int V_59 ;
F_25 ( & V_7 -> V_37 ) ;
V_59 = F_32 ( V_7 , V_73 , V_28 , V_16 ) ;
F_27 ( & V_7 -> V_37 ) ;
return V_59 ;
}
void F_64 ( struct V_6 * V_7 , struct V_26 * V_73 ,
const unsigned char * V_28 , T_4 V_16 , bool V_34 )
{
struct V_35 * V_20 = & V_7 -> V_36 [ F_9 ( V_28 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_79 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_73 -> V_60 == V_80 ||
V_73 -> V_60 == V_61 ) )
return;
V_11 = F_57 ( V_20 , V_28 , V_16 ) ;
if ( F_65 ( V_11 ) ) {
if ( F_49 ( V_11 -> V_38 ) ) {
if ( F_66 () )
F_62 ( V_7 , L_4
L_5 ,
V_73 -> V_31 -> V_77 ) ;
} else {
if ( F_49 ( V_73 != V_11 -> V_33 ) ) {
V_11 -> V_33 = V_73 ;
V_79 = true ;
}
V_11 -> V_13 = V_14 ;
if ( F_49 ( V_34 ) )
V_11 -> V_34 = 1 ;
if ( F_49 ( V_79 ) )
F_17 ( V_7 , V_11 , V_78 ) ;
}
} else {
F_39 ( & V_7 -> V_37 ) ;
if ( F_65 ( ! F_26 ( V_20 , V_28 , V_16 ) ) ) {
V_11 = F_58 ( V_20 , V_73 , V_28 , V_16 ) ;
if ( V_11 ) {
if ( F_49 ( V_34 ) )
V_11 -> V_34 = 1 ;
F_17 ( V_7 , V_11 , V_78 ) ;
}
}
F_42 ( & V_7 -> V_37 ) ;
}
}
static int F_67 ( const struct V_2 * V_11 )
{
if ( V_11 -> V_38 )
return V_81 ;
else if ( V_11 -> V_12 )
return V_82 ;
else if ( F_7 ( V_11 -> V_33 -> V_7 , V_11 ) )
return V_83 ;
else
return V_84 ;
}
static int F_68 ( struct V_85 * V_86 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_87 , T_3 V_88 , int type , unsigned int V_89 )
{
unsigned long V_90 = V_14 ;
struct V_91 V_92 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
V_94 = F_69 ( V_86 , V_87 , V_88 , type , sizeof( * V_96 ) , V_89 ) ;
if ( V_94 == NULL )
return - V_97 ;
V_96 = F_70 ( V_94 ) ;
V_96 -> V_98 = V_99 ;
V_96 -> V_100 = 0 ;
V_96 -> V_101 = 0 ;
V_96 -> V_102 = 0 ;
V_96 -> V_103 = 0 ;
V_96 -> V_104 = V_11 -> V_33 ? V_11 -> V_33 -> V_31 -> V_105 : V_7 -> V_31 -> V_105 ;
V_96 -> V_106 = F_67 ( V_11 ) ;
if ( F_71 ( V_86 , V_107 , V_69 , & V_11 -> V_28 ) )
goto V_108;
V_92 . V_109 = F_72 ( V_90 - V_11 -> V_75 ) ;
V_92 . V_110 = 0 ;
V_92 . V_111 = F_72 ( V_90 - V_11 -> V_13 ) ;
V_92 . V_112 = 0 ;
if ( F_71 ( V_86 , V_113 , sizeof( V_92 ) , & V_92 ) )
goto V_108;
if ( F_71 ( V_86 , V_114 , sizeof( T_4 ) , & V_11 -> V_29 ) )
goto V_108;
return F_73 ( V_86 , V_94 ) ;
V_108:
F_74 ( V_86 , V_94 ) ;
return - V_97 ;
}
static inline T_6 F_75 ( void )
{
return F_76 ( sizeof( struct V_95 ) )
+ F_77 ( V_69 )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( struct V_91 ) ) ;
}
static void F_17 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_115 * V_115 = F_78 ( V_7 -> V_31 ) ;
struct V_85 * V_86 ;
int V_116 = - V_117 ;
V_86 = F_79 ( F_75 () , V_74 ) ;
if ( V_86 == NULL )
goto V_118;
V_116 = F_68 ( V_86 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_116 < 0 ) {
F_80 ( V_116 == - V_97 ) ;
F_81 ( V_86 ) ;
goto V_118;
}
F_82 ( V_86 , V_115 , 0 , V_119 , NULL , V_74 ) ;
return;
V_118:
F_83 ( V_115 , V_119 , V_116 ) ;
}
int F_84 ( struct V_85 * V_86 ,
struct V_120 * V_121 ,
struct V_57 * V_31 ,
int V_122 )
{
struct V_6 * V_7 = F_85 ( V_31 ) ;
int V_43 ;
if ( ! ( V_31 -> V_123 & V_124 ) )
goto V_48;
for ( V_43 = 0 ; V_43 < V_18 ; V_43 ++ ) {
struct V_2 * V_23 ;
F_48 (f, &br->hash[i], hlist) {
if ( V_122 < V_121 -> args [ 0 ] )
goto V_64;
if ( F_68 ( V_86 , V_7 , V_23 ,
F_86 ( V_121 -> V_86 ) . V_87 ,
V_121 -> V_94 -> V_125 ,
V_78 ,
V_126 ) < 0 )
break;
V_64:
++ V_122 ;
}
}
V_48:
return V_122 ;
}
static int F_87 ( struct V_26 * V_73 , const T_7 * V_28 ,
T_2 V_60 , T_2 V_89 , T_2 V_16 )
{
struct V_6 * V_7 = V_73 -> V_7 ;
struct V_35 * V_20 = & V_7 -> V_36 [ F_9 ( V_28 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_127 = false ;
V_11 = F_26 ( V_20 , V_28 , V_16 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_89 & V_128 ) )
return - V_129 ;
V_11 = F_58 ( V_20 , V_73 , V_28 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_127 = true ;
} else {
if ( V_89 & V_130 )
return - V_131 ;
if ( V_11 -> V_33 != V_73 ) {
V_11 -> V_33 = V_73 ;
V_127 = true ;
}
}
if ( F_67 ( V_11 ) != V_60 ) {
if ( V_60 & V_81 )
V_11 -> V_38 = V_11 -> V_12 = 1 ;
else if ( V_60 & V_82 ) {
V_11 -> V_38 = 0 ;
V_11 -> V_12 = 1 ;
} else
V_11 -> V_38 = V_11 -> V_12 = 0 ;
V_127 = true ;
}
V_11 -> V_34 = 1 ;
V_11 -> V_75 = V_14 ;
if ( V_127 ) {
V_11 -> V_13 = V_14 ;
F_17 ( V_7 , V_11 , V_78 ) ;
}
return 0 ;
}
static int F_88 ( struct V_95 * V_96 , struct V_26 * V_27 ,
const unsigned char * V_28 , T_4 V_132 , T_4 V_16 )
{
int V_116 = 0 ;
if ( V_96 -> V_102 & V_133 ) {
F_51 () ;
F_64 ( V_27 -> V_7 , V_27 , V_28 , V_16 , true ) ;
F_53 () ;
} else {
F_25 ( & V_27 -> V_7 -> V_37 ) ;
V_116 = F_87 ( V_27 , V_28 , V_96 -> V_106 ,
V_132 , V_16 ) ;
F_27 ( & V_27 -> V_7 -> V_37 ) ;
}
return V_116 ;
}
int F_89 ( struct V_95 * V_96 , struct V_134 * V_135 [] ,
struct V_57 * V_31 ,
const unsigned char * V_28 , T_4 V_132 )
{
struct V_26 * V_27 ;
int V_116 = 0 ;
struct V_40 * V_41 ;
unsigned short V_16 = V_136 ;
if ( ! ( V_96 -> V_106 & ( V_81 | V_82 | V_84 ) ) ) {
F_90 ( L_6 , V_96 -> V_106 ) ;
return - V_76 ;
}
if ( V_135 [ V_114 ] ) {
if ( F_91 ( V_135 [ V_114 ] ) != sizeof( unsigned short ) ) {
F_90 ( L_7 ) ;
return - V_76 ;
}
V_16 = F_92 ( V_135 [ V_114 ] ) ;
if ( ! V_16 || V_16 >= V_137 ) {
F_90 ( L_8 ,
V_16 ) ;
return - V_76 ;
}
}
if ( F_93 ( V_28 ) ) {
F_90 ( L_9 ) ;
return - V_76 ;
}
V_27 = F_94 ( V_31 ) ;
if ( V_27 == NULL ) {
F_90 ( L_10 ,
V_31 -> V_77 ) ;
return - V_76 ;
}
V_41 = F_29 ( V_27 ) ;
if ( V_16 != V_136 ) {
if ( ! V_41 || ! F_95 ( V_16 , V_41 -> V_138 ) ) {
F_90 ( L_11
L_12 , V_16 , V_31 -> V_77 ) ;
return - V_76 ;
}
V_116 = F_88 ( V_96 , V_27 , V_28 , V_132 , V_16 ) ;
} else {
if ( ! V_41 || F_96 ( V_41 -> V_138 , V_136 ) ) {
V_116 = F_88 ( V_96 , V_27 , V_28 , V_132 , 0 ) ;
goto V_48;
}
F_33 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_116 = F_88 ( V_96 , V_27 , V_28 , V_132 , V_16 ) ;
if ( V_116 )
goto V_48;
}
}
V_48:
return V_116 ;
}
static int F_97 ( struct V_6 * V_7 , const T_5 * V_28 , T_4 V_139 )
{
struct V_35 * V_20 = & V_7 -> V_36 [ F_9 ( V_28 , V_139 ) ] ;
struct V_2 * V_11 ;
V_11 = F_26 ( V_20 , V_28 , V_139 ) ;
if ( ! V_11 )
return - V_129 ;
F_15 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_98 ( struct V_26 * V_27 ,
const unsigned char * V_28 , T_4 V_16 )
{
int V_116 ;
F_25 ( & V_27 -> V_7 -> V_37 ) ;
V_116 = F_97 ( V_27 -> V_7 , V_28 , V_16 ) ;
F_27 ( & V_27 -> V_7 -> V_37 ) ;
return V_116 ;
}
int F_99 ( struct V_95 * V_96 , struct V_134 * V_135 [] ,
struct V_57 * V_31 ,
const unsigned char * V_28 )
{
struct V_26 * V_27 ;
int V_116 ;
struct V_40 * V_41 ;
unsigned short V_16 = V_136 ;
if ( V_135 [ V_114 ] ) {
if ( F_91 ( V_135 [ V_114 ] ) != sizeof( unsigned short ) ) {
F_90 ( L_7 ) ;
return - V_76 ;
}
V_16 = F_92 ( V_135 [ V_114 ] ) ;
if ( ! V_16 || V_16 >= V_137 ) {
F_90 ( L_8 ,
V_16 ) ;
return - V_76 ;
}
}
V_27 = F_94 ( V_31 ) ;
if ( V_27 == NULL ) {
F_90 ( L_13 ,
V_31 -> V_77 ) ;
return - V_76 ;
}
V_41 = F_29 ( V_27 ) ;
if ( V_16 != V_136 ) {
if ( ! V_41 || ! F_95 ( V_16 , V_41 -> V_138 ) ) {
F_90 ( L_14
L_12 , V_16 , V_31 -> V_77 ) ;
return - V_76 ;
}
V_116 = F_98 ( V_27 , V_28 , V_16 ) ;
} else {
if ( ! V_41 || F_96 ( V_41 -> V_138 , V_136 ) ) {
V_116 = F_98 ( V_27 , V_28 , 0 ) ;
goto V_48;
}
V_116 = - V_129 ;
F_33 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_116 &= F_98 ( V_27 , V_28 , V_16 ) ;
}
}
V_48:
return V_116 ;
}
