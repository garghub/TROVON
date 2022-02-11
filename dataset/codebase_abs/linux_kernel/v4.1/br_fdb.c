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
static void F_23 ( struct V_6 * V_7 , struct V_2 * V_29 )
{
if ( V_29 -> V_12 )
F_22 ( V_7 , V_29 -> V_23 . V_23 ) ;
F_24 ( & V_29 -> V_30 ) ;
F_25 ( V_7 , V_29 , V_31 ) ;
F_26 ( & V_29 -> V_22 , F_12 ) ;
}
static void F_27 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
struct V_2 * V_29 )
{
const unsigned char * V_23 = V_29 -> V_23 . V_23 ;
T_4 V_16 = V_29 -> V_32 ;
struct V_25 * V_33 ;
F_17 (op, &br->port_list, list) {
if ( V_33 != V_26 && F_28 ( V_33 -> V_27 -> V_34 , V_23 ) &&
( ! V_16 || F_29 ( V_33 , V_16 ) ) ) {
V_29 -> V_35 = V_33 ;
V_29 -> V_36 = 0 ;
return;
}
}
if ( V_26 && F_28 ( V_7 -> V_27 -> V_34 , V_23 ) &&
( ! V_16 || F_30 ( V_7 , V_16 ) ) ) {
V_29 -> V_35 = NULL ;
V_29 -> V_36 = 0 ;
return;
}
F_23 ( V_7 , V_29 ) ;
}
void F_31 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_37 * V_20 = & V_7 -> V_38 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_29 ;
F_32 ( & V_7 -> V_39 ) ;
V_29 = F_33 ( V_20 , V_23 , V_16 ) ;
if ( V_29 && V_29 -> V_40 && ! V_29 -> V_36 && V_29 -> V_35 == V_26 )
F_27 ( V_7 , V_26 , V_29 ) ;
F_34 ( & V_7 -> V_39 ) ;
}
void F_35 ( struct V_25 * V_26 , const unsigned char * V_41 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_42 * V_43 = F_36 ( V_26 ) ;
bool V_44 = ! V_43 ;
int V_45 ;
T_4 V_16 ;
F_32 ( & V_7 -> V_39 ) ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
struct V_46 * V_47 ;
F_37 (h, &br->hash[i]) {
struct V_2 * V_29 ;
V_29 = F_38 ( V_47 , struct V_2 , V_30 ) ;
if ( V_29 -> V_35 == V_26 && V_29 -> V_40 && ! V_29 -> V_36 ) {
F_27 ( V_7 , V_26 , V_29 ) ;
if ( V_44 )
goto V_48;
}
}
}
V_48:
F_39 ( V_7 , V_26 , V_41 , 0 ) ;
if ( V_44 )
goto V_49;
F_40 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_39 ( V_7 , V_26 , V_41 , V_16 ) ;
V_49:
F_34 ( & V_7 -> V_39 ) ;
}
void F_41 ( struct V_6 * V_7 , const T_5 * V_41 )
{
struct V_2 * V_29 ;
struct V_42 * V_43 ;
T_4 V_16 = 0 ;
F_32 ( & V_7 -> V_39 ) ;
V_29 = F_42 ( V_7 , V_7 -> V_27 -> V_34 , 0 ) ;
if ( V_29 && V_29 -> V_40 && ! V_29 -> V_35 )
F_27 ( V_7 , NULL , V_29 ) ;
F_39 ( V_7 , NULL , V_41 , 0 ) ;
V_43 = F_43 ( V_7 ) ;
if ( ! V_43 )
goto V_50;
F_44 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_29 = F_42 ( V_7 , V_7 -> V_27 -> V_34 , V_16 ) ;
if ( V_29 && V_29 -> V_40 && ! V_29 -> V_35 )
F_27 ( V_7 , NULL , V_29 ) ;
F_39 ( V_7 , NULL , V_41 , V_16 ) ;
}
V_50:
F_34 ( & V_7 -> V_39 ) ;
}
void F_45 ( unsigned long V_51 )
{
struct V_6 * V_7 = (struct V_6 * ) V_51 ;
unsigned long V_52 = F_6 ( V_7 ) ;
unsigned long V_53 = V_14 + V_7 -> V_10 ;
int V_45 ;
F_46 ( & V_7 -> V_39 ) ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
struct V_2 * V_29 ;
struct V_46 * V_54 ;
F_47 (f, n, &br->hash[i], hlist) {
unsigned long V_55 ;
if ( V_29 -> V_12 )
continue;
V_55 = V_29 -> V_13 + V_52 ;
if ( F_8 ( V_55 , V_14 ) )
F_23 ( V_7 , V_29 ) ;
else if ( F_48 ( V_55 , V_53 ) )
V_53 = V_55 ;
}
}
F_49 ( & V_7 -> V_39 ) ;
F_50 ( & V_7 -> V_56 , F_51 ( V_53 ) ) ;
}
void F_52 ( struct V_6 * V_7 )
{
int V_45 ;
F_32 ( & V_7 -> V_39 ) ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
struct V_2 * V_29 ;
struct V_46 * V_54 ;
F_47 (f, n, &br->hash[i], hlist) {
if ( ! V_29 -> V_12 )
F_23 ( V_7 , V_29 ) ;
}
}
F_34 ( & V_7 -> V_39 ) ;
}
void F_53 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
int V_57 )
{
int V_45 ;
F_32 ( & V_7 -> V_39 ) ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
struct V_46 * V_47 , * V_58 ;
F_54 (h, g, &br->hash[i]) {
struct V_2 * V_29
= F_38 ( V_47 , struct V_2 , V_30 ) ;
if ( V_29 -> V_35 != V_26 )
continue;
if ( V_29 -> V_12 && ! V_57 )
continue;
if ( V_29 -> V_40 )
F_27 ( V_7 , V_26 , V_29 ) ;
else
F_23 ( V_7 , V_29 ) ;
}
}
F_34 ( & V_7 -> V_39 ) ;
}
struct V_2 * F_42 ( struct V_6 * V_7 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_55 (fdb,
&br->hash[br_mac_hash(addr, vid)], hlist) {
if ( F_28 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_32 == V_16 ) {
if ( F_56 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_57 ( struct V_59 * V_27 , unsigned char * V_23 )
{
struct V_2 * V_11 ;
struct V_25 * V_60 ;
int V_61 ;
F_58 () ;
V_60 = F_59 ( V_27 ) ;
if ( ! V_60 )
V_61 = 0 ;
else {
V_11 = F_42 ( V_60 -> V_7 , V_23 , 0 ) ;
V_61 = V_11 && V_11 -> V_35 && V_11 -> V_35 -> V_27 != V_27 &&
V_11 -> V_35 -> V_62 == V_63 ;
}
F_60 () ;
return V_61 ;
}
int F_61 ( struct V_6 * V_7 , void * V_64 ,
unsigned long V_65 , unsigned long V_66 )
{
struct V_67 * V_68 = V_64 ;
int V_45 , V_69 = 0 ;
struct V_2 * V_29 ;
memset ( V_64 , 0 , V_65 * sizeof( struct V_67 ) ) ;
F_58 () ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
F_55 (f, &br->hash[i], hlist) {
if ( V_69 >= V_65 )
goto V_50;
if ( F_7 ( V_7 , V_29 ) )
continue;
if ( ! V_29 -> V_35 )
continue;
if ( V_66 ) {
-- V_66 ;
continue;
}
memcpy ( V_68 -> V_70 , V_29 -> V_23 . V_23 , V_71 ) ;
V_68 -> V_72 = V_29 -> V_35 -> V_72 ;
V_68 -> V_73 = V_29 -> V_35 -> V_72 >> 8 ;
V_68 -> V_40 = V_29 -> V_40 ;
if ( ! V_29 -> V_12 )
V_68 -> V_74 = F_62 ( V_14 - V_29 -> V_13 ) ;
++ V_68 ;
++ V_69 ;
}
}
V_50:
F_60 () ;
return V_69 ;
}
static struct V_2 * F_33 ( struct V_37 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_63 (fdb, head, hlist) {
if ( F_28 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_32 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_64 ( struct V_37 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_55 (fdb, head, hlist) {
if ( F_28 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_32 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_65 ( struct V_37 * V_20 ,
struct V_25 * V_75 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
V_11 = F_66 ( V_1 , V_76 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_23 . V_23 , V_23 , V_71 ) ;
V_11 -> V_35 = V_75 ;
V_11 -> V_32 = V_16 ;
V_11 -> V_40 = 0 ;
V_11 -> V_12 = 0 ;
V_11 -> V_36 = 0 ;
V_11 -> V_77 = 0 ;
V_11 -> V_13 = V_11 -> V_78 = V_14 ;
F_67 ( & V_11 -> V_30 , V_20 ) ;
}
return V_11 ;
}
static int F_39 ( struct V_6 * V_7 , struct V_25 * V_75 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_37 * V_20 = & V_7 -> V_38 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( ! F_68 ( V_23 ) )
return - V_79 ;
V_11 = F_33 ( V_20 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( V_11 -> V_40 )
return 0 ;
F_69 ( V_7 , L_2
L_3 ,
V_75 ? V_75 -> V_27 -> V_80 : V_7 -> V_27 -> V_80 ) ;
F_23 ( V_7 , V_11 ) ;
}
V_11 = F_65 ( V_20 , V_75 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_11 -> V_40 = V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
F_25 ( V_7 , V_11 , V_81 ) ;
return 0 ;
}
int F_70 ( struct V_6 * V_7 , struct V_25 * V_75 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_61 ;
F_32 ( & V_7 -> V_39 ) ;
V_61 = F_39 ( V_7 , V_75 , V_23 , V_16 ) ;
F_34 ( & V_7 -> V_39 ) ;
return V_61 ;
}
void F_71 ( struct V_6 * V_7 , struct V_25 * V_75 ,
const unsigned char * V_23 , T_4 V_16 , bool V_36 )
{
struct V_37 * V_20 = & V_7 -> V_38 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_82 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_75 -> V_62 == V_83 ||
V_75 -> V_62 == V_63 ) )
return;
V_11 = F_64 ( V_20 , V_23 , V_16 ) ;
if ( F_72 ( V_11 ) ) {
if ( F_56 ( V_11 -> V_40 ) ) {
if ( F_73 () )
F_69 ( V_7 , L_4
L_5 ,
V_75 -> V_27 -> V_80 ) ;
} else {
if ( F_56 ( V_75 != V_11 -> V_35 ) ) {
V_11 -> V_35 = V_75 ;
V_82 = true ;
}
V_11 -> V_13 = V_14 ;
if ( F_56 ( V_36 ) )
V_11 -> V_36 = 1 ;
if ( F_56 ( V_82 ) )
F_25 ( V_7 , V_11 , V_81 ) ;
}
} else {
F_46 ( & V_7 -> V_39 ) ;
if ( F_72 ( ! F_33 ( V_20 , V_23 , V_16 ) ) ) {
V_11 = F_65 ( V_20 , V_75 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( F_56 ( V_36 ) )
V_11 -> V_36 = 1 ;
F_25 ( V_7 , V_11 , V_81 ) ;
}
}
F_49 ( & V_7 -> V_39 ) ;
}
}
static int F_74 ( const struct V_2 * V_11 )
{
if ( V_11 -> V_40 )
return V_84 ;
else if ( V_11 -> V_12 )
return V_85 ;
else if ( F_7 ( V_11 -> V_35 -> V_7 , V_11 ) )
return V_86 ;
else
return V_87 ;
}
static int F_75 ( struct V_88 * V_89 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_90 , T_3 V_91 , int type , unsigned int V_92 )
{
unsigned long V_93 = V_14 ;
struct V_94 V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
V_97 = F_76 ( V_89 , V_90 , V_91 , type , sizeof( * V_99 ) , V_92 ) ;
if ( V_97 == NULL )
return - V_100 ;
V_99 = F_77 ( V_97 ) ;
V_99 -> V_101 = V_102 ;
V_99 -> V_103 = 0 ;
V_99 -> V_104 = 0 ;
V_99 -> V_105 = V_11 -> V_77 ? V_106 : 0 ;
V_99 -> V_107 = 0 ;
V_99 -> V_108 = V_11 -> V_35 ? V_11 -> V_35 -> V_27 -> V_109 : V_7 -> V_27 -> V_109 ;
V_99 -> V_110 = F_74 ( V_11 ) ;
if ( F_78 ( V_89 , V_111 , V_71 , & V_11 -> V_23 ) )
goto V_112;
if ( F_79 ( V_89 , V_113 , V_7 -> V_27 -> V_109 ) )
goto V_112;
V_95 . V_114 = F_80 ( V_93 - V_11 -> V_78 ) ;
V_95 . V_115 = 0 ;
V_95 . V_116 = F_80 ( V_93 - V_11 -> V_13 ) ;
V_95 . V_117 = 0 ;
if ( F_78 ( V_89 , V_118 , sizeof( V_95 ) , & V_95 ) )
goto V_112;
if ( V_11 -> V_32 && F_78 ( V_89 , V_119 , sizeof( T_4 ) , & V_11 -> V_32 ) )
goto V_112;
F_81 ( V_89 , V_97 ) ;
return 0 ;
V_112:
F_82 ( V_89 , V_97 ) ;
return - V_100 ;
}
static inline T_6 F_83 ( void )
{
return F_84 ( sizeof( struct V_98 ) )
+ F_85 ( V_71 )
+ F_85 ( sizeof( T_3 ) )
+ F_85 ( sizeof( T_4 ) )
+ F_85 ( sizeof( struct V_94 ) ) ;
}
static void F_25 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_120 * V_120 = F_86 ( V_7 -> V_27 ) ;
struct V_88 * V_89 ;
int V_24 = - V_121 ;
V_89 = F_87 ( F_83 () , V_76 ) ;
if ( V_89 == NULL )
goto V_122;
V_24 = F_75 ( V_89 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_24 < 0 ) {
F_88 ( V_24 == - V_100 ) ;
F_89 ( V_89 ) ;
goto V_122;
}
F_90 ( V_89 , V_120 , 0 , V_123 , NULL , V_76 ) ;
return;
V_122:
F_91 ( V_120 , V_123 , V_24 ) ;
}
int F_92 ( struct V_88 * V_89 ,
struct V_124 * V_125 ,
struct V_59 * V_27 ,
struct V_59 * V_126 ,
int V_127 )
{
struct V_6 * V_7 = F_93 ( V_27 ) ;
int V_45 ;
if ( ! ( V_27 -> V_128 & V_129 ) )
goto V_50;
if ( ! V_126 )
V_127 = F_94 ( V_89 , V_125 , V_27 , NULL , V_127 ) ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
struct V_2 * V_29 ;
F_55 (f, &br->hash[i], hlist) {
if ( V_127 < V_125 -> args [ 0 ] )
goto V_66;
if ( V_126 &&
( ! V_29 -> V_35 || V_29 -> V_35 -> V_27 != V_126 ) ) {
if ( V_126 != V_27 )
goto V_66;
if ( V_29 -> V_35 )
goto V_66;
}
if ( ! V_126 && V_29 -> V_35 )
goto V_66;
if ( F_75 ( V_89 , V_7 , V_29 ,
F_95 ( V_125 -> V_89 ) . V_90 ,
V_125 -> V_97 -> V_130 ,
V_81 ,
V_131 ) < 0 )
break;
V_66:
++ V_127 ;
}
}
V_50:
return V_127 ;
}
static int F_96 ( struct V_25 * V_75 , const T_7 * V_23 ,
T_2 V_62 , T_2 V_92 , T_2 V_16 )
{
struct V_6 * V_7 = V_75 -> V_7 ;
struct V_37 * V_20 = & V_7 -> V_38 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_132 = false ;
V_11 = F_33 ( V_20 , V_23 , V_16 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_92 & V_133 ) )
return - V_134 ;
V_11 = F_65 ( V_20 , V_75 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_132 = true ;
} else {
if ( V_92 & V_135 )
return - V_136 ;
if ( V_11 -> V_35 != V_75 ) {
V_11 -> V_35 = V_75 ;
V_132 = true ;
}
}
if ( F_74 ( V_11 ) != V_62 ) {
if ( V_62 & V_84 ) {
V_11 -> V_40 = 1 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else if ( V_62 & V_85 ) {
V_11 -> V_40 = 0 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else {
V_11 -> V_40 = 0 ;
if ( V_11 -> V_12 ) {
V_11 -> V_12 = 0 ;
F_22 ( V_7 , V_23 ) ;
}
}
V_132 = true ;
}
V_11 -> V_36 = 1 ;
V_11 -> V_78 = V_14 ;
if ( V_132 ) {
V_11 -> V_13 = V_14 ;
F_25 ( V_7 , V_11 , V_81 ) ;
}
return 0 ;
}
static int F_97 ( struct V_98 * V_99 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_137 , T_4 V_16 )
{
int V_24 = 0 ;
if ( V_99 -> V_105 & V_138 ) {
F_98 () ;
F_58 () ;
F_71 ( V_26 -> V_7 , V_26 , V_23 , V_16 , true ) ;
F_60 () ;
F_99 () ;
} else {
F_32 ( & V_26 -> V_7 -> V_39 ) ;
V_24 = F_96 ( V_26 , V_23 , V_99 -> V_110 ,
V_137 , V_16 ) ;
F_34 ( & V_26 -> V_7 -> V_39 ) ;
}
return V_24 ;
}
int F_100 ( struct V_98 * V_99 , struct V_139 * V_140 [] ,
struct V_59 * V_27 ,
const unsigned char * V_23 , T_4 V_16 , T_4 V_137 )
{
struct V_25 * V_26 ;
int V_24 = 0 ;
struct V_42 * V_43 ;
if ( ! ( V_99 -> V_110 & ( V_84 | V_85 | V_87 ) ) ) {
F_101 ( L_6 , V_99 -> V_110 ) ;
return - V_79 ;
}
if ( F_102 ( V_23 ) ) {
F_101 ( L_7 ) ;
return - V_79 ;
}
V_26 = F_103 ( V_27 ) ;
if ( V_26 == NULL ) {
F_101 ( L_8 ,
V_27 -> V_80 ) ;
return - V_79 ;
}
V_43 = F_36 ( V_26 ) ;
if ( V_16 ) {
if ( ! V_43 || ! F_104 ( V_16 , V_43 -> V_141 ) ) {
F_101 ( L_9
L_10 , V_16 , V_27 -> V_80 ) ;
return - V_79 ;
}
V_24 = F_97 ( V_99 , V_26 , V_23 , V_137 , V_16 ) ;
} else {
V_24 = F_97 ( V_99 , V_26 , V_23 , V_137 , 0 ) ;
if ( V_24 || ! V_43 )
goto V_50;
F_40 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_24 = F_97 ( V_99 , V_26 , V_23 , V_137 , V_16 ) ;
if ( V_24 )
goto V_50;
}
}
V_50:
return V_24 ;
}
static int F_105 ( struct V_6 * V_7 , const T_5 * V_23 , T_4 V_142 )
{
struct V_37 * V_20 = & V_7 -> V_38 [ F_9 ( V_23 , V_142 ) ] ;
struct V_2 * V_11 ;
V_11 = F_33 ( V_20 , V_23 , V_142 ) ;
if ( ! V_11 )
return - V_134 ;
F_23 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_24 ;
F_32 ( & V_26 -> V_7 -> V_39 ) ;
V_24 = F_105 ( V_26 -> V_7 , V_23 , V_16 ) ;
F_34 ( & V_26 -> V_7 -> V_39 ) ;
return V_24 ;
}
int F_107 ( struct V_98 * V_99 , struct V_139 * V_140 [] ,
struct V_59 * V_27 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_25 * V_26 ;
int V_24 ;
struct V_42 * V_43 ;
V_26 = F_103 ( V_27 ) ;
if ( V_26 == NULL ) {
F_101 ( L_11 ,
V_27 -> V_80 ) ;
return - V_79 ;
}
V_43 = F_36 ( V_26 ) ;
if ( V_16 ) {
if ( ! V_43 || ! F_104 ( V_16 , V_43 -> V_141 ) ) {
F_101 ( L_12
L_10 , V_16 , V_27 -> V_80 ) ;
return - V_79 ;
}
V_24 = F_106 ( V_26 , V_23 , V_16 ) ;
} else {
V_24 = - V_134 ;
V_24 &= F_106 ( V_26 , V_23 , 0 ) ;
if ( ! V_43 )
goto V_50;
F_40 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_24 &= F_106 ( V_26 , V_23 , V_16 ) ;
}
}
V_50:
return V_24 ;
}
int F_108 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 , * V_143 ;
int V_45 ;
int V_24 ;
F_16 () ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
F_63 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
V_24 = F_19 ( V_26 -> V_27 , V_11 -> V_23 . V_23 ) ;
if ( V_24 )
goto V_144;
}
}
return 0 ;
V_144:
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
F_63 (tmp, &br->hash[i], hlist) {
if ( V_143 == V_11 )
break;
if ( ! V_143 -> V_12 )
continue;
F_21 ( V_26 -> V_27 , V_143 -> V_23 . V_23 ) ;
}
}
return V_24 ;
}
void F_109 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 ;
int V_45 ;
F_16 () ;
for ( V_45 = 0 ; V_45 < V_18 ; V_45 ++ ) {
F_55 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
F_21 ( V_26 -> V_27 , V_11 -> V_23 . V_23 ) ;
}
}
}
int F_110 ( struct V_6 * V_7 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_37 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_32 ( & V_7 -> V_39 ) ;
V_20 = & V_7 -> V_38 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_33 ( V_20 , V_23 , V_16 ) ;
if ( ! V_11 ) {
V_11 = F_65 ( V_20 , V_26 , V_23 , V_16 ) ;
if ( ! V_11 ) {
V_24 = - V_4 ;
goto V_145;
}
V_11 -> V_77 = 1 ;
F_25 ( V_7 , V_11 , V_81 ) ;
} else if ( V_11 -> V_77 ) {
V_11 -> V_13 = V_11 -> V_78 = V_14 ;
} else if ( ! V_11 -> V_36 ) {
V_11 -> V_77 = 1 ;
V_11 -> V_13 = V_14 ;
F_25 ( V_7 , V_11 , V_81 ) ;
}
V_145:
F_34 ( & V_7 -> V_39 ) ;
return V_24 ;
}
int F_111 ( struct V_6 * V_7 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_37 * V_20 ;
struct V_2 * V_11 ;
int V_24 = 0 ;
F_16 () ;
F_32 ( & V_7 -> V_39 ) ;
V_20 = & V_7 -> V_38 [ F_9 ( V_23 , V_16 ) ] ;
V_11 = F_33 ( V_20 , V_23 , V_16 ) ;
if ( V_11 && V_11 -> V_77 )
F_23 ( V_7 , V_11 ) ;
else
V_24 = - V_134 ;
F_34 ( & V_7 -> V_39 ) ;
return V_24 ;
}
