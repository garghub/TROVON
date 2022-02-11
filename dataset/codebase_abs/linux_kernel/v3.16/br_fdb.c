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
struct V_25 * V_26 , * V_27 ;
F_16 () ;
F_17 (p, &br->port_list, list) {
if ( ! F_18 ( V_26 ) ) {
V_24 = F_19 ( V_26 -> V_28 , V_23 ) ;
if ( V_24 )
goto V_29;
}
}
return;
V_29:
F_17 (tmp, &br->port_list, list) {
if ( V_27 == V_26 )
break;
if ( ! F_18 ( V_27 ) )
F_20 ( V_27 -> V_28 , V_23 ) ;
}
}
static void F_21 ( struct V_6 * V_7 , const unsigned char * V_23 )
{
struct V_25 * V_26 ;
F_16 () ;
F_17 (p, &br->port_list, list) {
if ( ! F_18 ( V_26 ) )
F_20 ( V_26 -> V_28 , V_23 ) ;
}
}
static void F_22 ( struct V_6 * V_7 , struct V_2 * V_30 )
{
if ( V_30 -> V_12 )
F_21 ( V_7 , V_30 -> V_23 . V_23 ) ;
F_23 ( & V_30 -> V_31 ) ;
F_24 ( V_7 , V_30 , V_32 ) ;
F_25 ( & V_30 -> V_22 , F_12 ) ;
}
static void F_26 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
struct V_2 * V_30 )
{
const unsigned char * V_23 = V_30 -> V_23 . V_23 ;
T_4 V_16 = V_30 -> V_33 ;
struct V_25 * V_34 ;
F_17 (op, &br->port_list, list) {
if ( V_34 != V_26 && F_27 ( V_34 -> V_28 -> V_35 , V_23 ) &&
( ! V_16 || F_28 ( V_34 , V_16 ) ) ) {
V_30 -> V_36 = V_34 ;
V_30 -> V_37 = 0 ;
return;
}
}
if ( V_26 && F_27 ( V_7 -> V_28 -> V_35 , V_23 ) &&
( ! V_16 || F_29 ( V_7 , V_16 ) ) ) {
V_30 -> V_36 = NULL ;
V_30 -> V_37 = 0 ;
return;
}
F_22 ( V_7 , V_30 ) ;
}
void F_30 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_38 * V_20 = & V_7 -> V_39 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_30 ;
F_31 ( & V_7 -> V_40 ) ;
V_30 = F_32 ( V_20 , V_23 , V_16 ) ;
if ( V_30 && V_30 -> V_41 && ! V_30 -> V_37 && V_30 -> V_36 == V_26 )
F_26 ( V_7 , V_26 , V_30 ) ;
F_33 ( & V_7 -> V_40 ) ;
}
void F_34 ( struct V_25 * V_26 , const unsigned char * V_42 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_43 * V_44 = F_35 ( V_26 ) ;
bool V_45 = ! V_44 ;
int V_46 ;
T_4 V_16 ;
F_31 ( & V_7 -> V_40 ) ;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
struct V_47 * V_48 ;
F_36 (h, &br->hash[i]) {
struct V_2 * V_30 ;
V_30 = F_37 ( V_48 , struct V_2 , V_31 ) ;
if ( V_30 -> V_36 == V_26 && V_30 -> V_41 && ! V_30 -> V_37 ) {
F_26 ( V_7 , V_26 , V_30 ) ;
if ( V_45 )
goto V_49;
}
}
}
V_49:
F_38 ( V_7 , V_26 , V_42 , 0 ) ;
if ( V_45 )
goto V_50;
F_39 (vid, pv->vlan_bitmap, VLAN_N_VID)
F_38 ( V_7 , V_26 , V_42 , V_16 ) ;
V_50:
F_33 ( & V_7 -> V_40 ) ;
}
void F_40 ( struct V_6 * V_7 , const T_5 * V_42 )
{
struct V_2 * V_30 ;
struct V_43 * V_44 ;
T_4 V_16 = 0 ;
F_31 ( & V_7 -> V_40 ) ;
V_30 = F_41 ( V_7 , V_7 -> V_28 -> V_35 , 0 ) ;
if ( V_30 && V_30 -> V_41 && ! V_30 -> V_36 )
F_26 ( V_7 , NULL , V_30 ) ;
F_38 ( V_7 , NULL , V_42 , 0 ) ;
V_44 = F_42 ( V_7 ) ;
if ( ! V_44 )
goto V_51;
F_43 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_30 = F_41 ( V_7 , V_7 -> V_28 -> V_35 , V_16 ) ;
if ( V_30 && V_30 -> V_41 && ! V_30 -> V_36 )
F_26 ( V_7 , NULL , V_30 ) ;
F_38 ( V_7 , NULL , V_42 , V_16 ) ;
}
V_51:
F_33 ( & V_7 -> V_40 ) ;
}
void F_44 ( unsigned long V_52 )
{
struct V_6 * V_7 = (struct V_6 * ) V_52 ;
unsigned long V_53 = F_6 ( V_7 ) ;
unsigned long V_54 = V_14 + V_7 -> V_10 ;
int V_46 ;
F_45 ( & V_7 -> V_40 ) ;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
struct V_2 * V_30 ;
struct V_47 * V_55 ;
F_46 (f, n, &br->hash[i], hlist) {
unsigned long V_56 ;
if ( V_30 -> V_12 )
continue;
V_56 = V_30 -> V_13 + V_53 ;
if ( F_8 ( V_56 , V_14 ) )
F_22 ( V_7 , V_30 ) ;
else if ( F_47 ( V_56 , V_54 ) )
V_54 = V_56 ;
}
}
F_48 ( & V_7 -> V_40 ) ;
F_49 ( & V_7 -> V_57 , F_50 ( V_54 ) ) ;
}
void F_51 ( struct V_6 * V_7 )
{
int V_46 ;
F_31 ( & V_7 -> V_40 ) ;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
struct V_2 * V_30 ;
struct V_47 * V_55 ;
F_46 (f, n, &br->hash[i], hlist) {
if ( ! V_30 -> V_12 )
F_22 ( V_7 , V_30 ) ;
}
}
F_33 ( & V_7 -> V_40 ) ;
}
void F_52 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
int V_58 )
{
int V_46 ;
F_31 ( & V_7 -> V_40 ) ;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
struct V_47 * V_48 , * V_59 ;
F_53 (h, g, &br->hash[i]) {
struct V_2 * V_30
= F_37 ( V_48 , struct V_2 , V_31 ) ;
if ( V_30 -> V_36 != V_26 )
continue;
if ( V_30 -> V_12 && ! V_58 )
continue;
if ( V_30 -> V_41 )
F_26 ( V_7 , V_26 , V_30 ) ;
else
F_22 ( V_7 , V_30 ) ;
}
}
F_33 ( & V_7 -> V_40 ) ;
}
struct V_2 * F_41 ( struct V_6 * V_7 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_54 (fdb,
&br->hash[br_mac_hash(addr, vid)], hlist) {
if ( F_27 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_33 == V_16 ) {
if ( F_55 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_56 ( struct V_60 * V_28 , unsigned char * V_23 )
{
struct V_2 * V_11 ;
struct V_25 * V_61 ;
int V_62 ;
F_57 () ;
V_61 = F_58 ( V_28 ) ;
if ( ! V_61 )
V_62 = 0 ;
else {
V_11 = F_41 ( V_61 -> V_7 , V_23 , 0 ) ;
V_62 = V_11 && V_11 -> V_36 && V_11 -> V_36 -> V_28 != V_28 &&
V_11 -> V_36 -> V_63 == V_64 ;
}
F_59 () ;
return V_62 ;
}
int F_60 ( struct V_6 * V_7 , void * V_65 ,
unsigned long V_66 , unsigned long V_67 )
{
struct V_68 * V_69 = V_65 ;
int V_46 , V_70 = 0 ;
struct V_2 * V_30 ;
memset ( V_65 , 0 , V_66 * sizeof( struct V_68 ) ) ;
F_57 () ;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
F_54 (f, &br->hash[i], hlist) {
if ( V_70 >= V_66 )
goto V_51;
if ( F_7 ( V_7 , V_30 ) )
continue;
if ( ! V_30 -> V_36 )
continue;
if ( V_67 ) {
-- V_67 ;
continue;
}
memcpy ( V_69 -> V_71 , V_30 -> V_23 . V_23 , V_72 ) ;
V_69 -> V_73 = V_30 -> V_36 -> V_73 ;
V_69 -> V_74 = V_30 -> V_36 -> V_73 >> 8 ;
V_69 -> V_41 = V_30 -> V_41 ;
if ( ! V_30 -> V_12 )
V_69 -> V_75 = F_61 ( V_14 - V_30 -> V_13 ) ;
++ V_69 ;
++ V_70 ;
}
}
V_51:
F_59 () ;
return V_70 ;
}
static struct V_2 * F_32 ( struct V_38 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_62 (fdb, head, hlist) {
if ( F_27 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_33 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_63 ( struct V_38 * V_20 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_54 (fdb, head, hlist) {
if ( F_27 ( V_11 -> V_23 . V_23 , V_23 ) &&
V_11 -> V_33 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_64 ( struct V_38 * V_20 ,
struct V_25 * V_76 ,
const unsigned char * V_23 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
V_11 = F_65 ( V_1 , V_77 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_23 . V_23 , V_23 , V_72 ) ;
V_11 -> V_36 = V_76 ;
V_11 -> V_33 = V_16 ;
V_11 -> V_41 = 0 ;
V_11 -> V_12 = 0 ;
V_11 -> V_37 = 0 ;
V_11 -> V_13 = V_11 -> V_78 = V_14 ;
F_66 ( & V_11 -> V_31 , V_20 ) ;
}
return V_11 ;
}
static int F_38 ( struct V_6 * V_7 , struct V_25 * V_76 ,
const unsigned char * V_23 , T_4 V_16 )
{
struct V_38 * V_20 = & V_7 -> V_39 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( ! F_67 ( V_23 ) )
return - V_79 ;
V_11 = F_32 ( V_20 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( V_11 -> V_41 )
return 0 ;
F_68 ( V_7 , L_2
L_3 ,
V_76 ? V_76 -> V_28 -> V_80 : V_7 -> V_28 -> V_80 ) ;
F_22 ( V_7 , V_11 ) ;
}
V_11 = F_64 ( V_20 , V_76 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_11 -> V_41 = V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
F_24 ( V_7 , V_11 , V_81 ) ;
return 0 ;
}
int F_69 ( struct V_6 * V_7 , struct V_25 * V_76 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_62 ;
F_31 ( & V_7 -> V_40 ) ;
V_62 = F_38 ( V_7 , V_76 , V_23 , V_16 ) ;
F_33 ( & V_7 -> V_40 ) ;
return V_62 ;
}
void F_70 ( struct V_6 * V_7 , struct V_25 * V_76 ,
const unsigned char * V_23 , T_4 V_16 , bool V_37 )
{
struct V_38 * V_20 = & V_7 -> V_39 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_82 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_76 -> V_63 == V_83 ||
V_76 -> V_63 == V_64 ) )
return;
V_11 = F_63 ( V_20 , V_23 , V_16 ) ;
if ( F_71 ( V_11 ) ) {
if ( F_55 ( V_11 -> V_41 ) ) {
if ( F_72 () )
F_68 ( V_7 , L_4
L_5 ,
V_76 -> V_28 -> V_80 ) ;
} else {
if ( F_55 ( V_76 != V_11 -> V_36 ) ) {
V_11 -> V_36 = V_76 ;
V_82 = true ;
}
V_11 -> V_13 = V_14 ;
if ( F_55 ( V_37 ) )
V_11 -> V_37 = 1 ;
if ( F_55 ( V_82 ) )
F_24 ( V_7 , V_11 , V_81 ) ;
}
} else {
F_45 ( & V_7 -> V_40 ) ;
if ( F_71 ( ! F_32 ( V_20 , V_23 , V_16 ) ) ) {
V_11 = F_64 ( V_20 , V_76 , V_23 , V_16 ) ;
if ( V_11 ) {
if ( F_55 ( V_37 ) )
V_11 -> V_37 = 1 ;
F_24 ( V_7 , V_11 , V_81 ) ;
}
}
F_48 ( & V_7 -> V_40 ) ;
}
}
static int F_73 ( const struct V_2 * V_11 )
{
if ( V_11 -> V_41 )
return V_84 ;
else if ( V_11 -> V_12 )
return V_85 ;
else if ( F_7 ( V_11 -> V_36 -> V_7 , V_11 ) )
return V_86 ;
else
return V_87 ;
}
static int F_74 ( struct V_88 * V_89 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_90 , T_3 V_91 , int type , unsigned int V_92 )
{
unsigned long V_93 = V_14 ;
struct V_94 V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
V_97 = F_75 ( V_89 , V_90 , V_91 , type , sizeof( * V_99 ) , V_92 ) ;
if ( V_97 == NULL )
return - V_100 ;
V_99 = F_76 ( V_97 ) ;
V_99 -> V_101 = V_102 ;
V_99 -> V_103 = 0 ;
V_99 -> V_104 = 0 ;
V_99 -> V_105 = 0 ;
V_99 -> V_106 = 0 ;
V_99 -> V_107 = V_11 -> V_36 ? V_11 -> V_36 -> V_28 -> V_108 : V_7 -> V_28 -> V_108 ;
V_99 -> V_109 = F_73 ( V_11 ) ;
if ( F_77 ( V_89 , V_110 , V_72 , & V_11 -> V_23 ) )
goto V_111;
if ( F_78 ( V_89 , V_112 , V_7 -> V_28 -> V_108 ) )
goto V_111;
V_95 . V_113 = F_79 ( V_93 - V_11 -> V_78 ) ;
V_95 . V_114 = 0 ;
V_95 . V_115 = F_79 ( V_93 - V_11 -> V_13 ) ;
V_95 . V_116 = 0 ;
if ( F_77 ( V_89 , V_117 , sizeof( V_95 ) , & V_95 ) )
goto V_111;
if ( F_77 ( V_89 , V_118 , sizeof( T_4 ) , & V_11 -> V_33 ) )
goto V_111;
return F_80 ( V_89 , V_97 ) ;
V_111:
F_81 ( V_89 , V_97 ) ;
return - V_100 ;
}
static inline T_6 F_82 ( void )
{
return F_83 ( sizeof( struct V_98 ) )
+ F_84 ( V_72 )
+ F_84 ( sizeof( T_3 ) )
+ F_84 ( sizeof( T_4 ) )
+ F_84 ( sizeof( struct V_94 ) ) ;
}
static void F_24 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_119 * V_119 = F_85 ( V_7 -> V_28 ) ;
struct V_88 * V_89 ;
int V_24 = - V_120 ;
V_89 = F_86 ( F_82 () , V_77 ) ;
if ( V_89 == NULL )
goto V_121;
V_24 = F_74 ( V_89 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_24 < 0 ) {
F_87 ( V_24 == - V_100 ) ;
F_88 ( V_89 ) ;
goto V_121;
}
F_89 ( V_89 , V_119 , 0 , V_122 , NULL , V_77 ) ;
return;
V_121:
F_90 ( V_119 , V_122 , V_24 ) ;
}
int F_91 ( struct V_88 * V_89 ,
struct V_123 * V_124 ,
struct V_60 * V_28 ,
int V_125 )
{
struct V_6 * V_7 = F_92 ( V_28 ) ;
int V_46 ;
if ( ! ( V_28 -> V_126 & V_127 ) )
goto V_51;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
struct V_2 * V_30 ;
F_54 (f, &br->hash[i], hlist) {
if ( V_125 < V_124 -> args [ 0 ] )
goto V_67;
if ( F_74 ( V_89 , V_7 , V_30 ,
F_93 ( V_124 -> V_89 ) . V_90 ,
V_124 -> V_97 -> V_128 ,
V_81 ,
V_129 ) < 0 )
break;
V_67:
++ V_125 ;
}
}
V_51:
return V_125 ;
}
static int F_94 ( struct V_25 * V_76 , const T_7 * V_23 ,
T_2 V_63 , T_2 V_92 , T_2 V_16 )
{
struct V_6 * V_7 = V_76 -> V_7 ;
struct V_38 * V_20 = & V_7 -> V_39 [ F_9 ( V_23 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_130 = false ;
V_11 = F_32 ( V_20 , V_23 , V_16 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_92 & V_131 ) )
return - V_132 ;
V_11 = F_64 ( V_20 , V_76 , V_23 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_130 = true ;
} else {
if ( V_92 & V_133 )
return - V_134 ;
if ( V_11 -> V_36 != V_76 ) {
V_11 -> V_36 = V_76 ;
V_130 = true ;
}
}
if ( F_73 ( V_11 ) != V_63 ) {
if ( V_63 & V_84 ) {
V_11 -> V_41 = 1 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else if ( V_63 & V_85 ) {
V_11 -> V_41 = 0 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_15 ( V_7 , V_23 ) ;
}
} else {
V_11 -> V_41 = 0 ;
if ( V_11 -> V_12 ) {
V_11 -> V_12 = 0 ;
F_21 ( V_7 , V_23 ) ;
}
}
V_130 = true ;
}
V_11 -> V_37 = 1 ;
V_11 -> V_78 = V_14 ;
if ( V_130 ) {
V_11 -> V_13 = V_14 ;
F_24 ( V_7 , V_11 , V_81 ) ;
}
return 0 ;
}
static int F_95 ( struct V_98 * V_99 , struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_135 , T_4 V_16 )
{
int V_24 = 0 ;
if ( V_99 -> V_105 & V_136 ) {
F_57 () ;
F_70 ( V_26 -> V_7 , V_26 , V_23 , V_16 , true ) ;
F_59 () ;
} else {
F_31 ( & V_26 -> V_7 -> V_40 ) ;
V_24 = F_94 ( V_26 , V_23 , V_99 -> V_109 ,
V_135 , V_16 ) ;
F_33 ( & V_26 -> V_7 -> V_40 ) ;
}
return V_24 ;
}
int F_96 ( struct V_98 * V_99 , struct V_137 * V_138 [] ,
struct V_60 * V_28 ,
const unsigned char * V_23 , T_4 V_135 )
{
struct V_25 * V_26 ;
int V_24 = 0 ;
struct V_43 * V_44 ;
unsigned short V_16 = V_139 ;
if ( ! ( V_99 -> V_109 & ( V_84 | V_85 | V_87 ) ) ) {
F_97 ( L_6 , V_99 -> V_109 ) ;
return - V_79 ;
}
if ( V_138 [ V_118 ] ) {
if ( F_98 ( V_138 [ V_118 ] ) != sizeof( unsigned short ) ) {
F_97 ( L_7 ) ;
return - V_79 ;
}
V_16 = F_99 ( V_138 [ V_118 ] ) ;
if ( ! V_16 || V_16 >= V_140 ) {
F_97 ( L_8 ,
V_16 ) ;
return - V_79 ;
}
}
if ( F_100 ( V_23 ) ) {
F_97 ( L_9 ) ;
return - V_79 ;
}
V_26 = F_101 ( V_28 ) ;
if ( V_26 == NULL ) {
F_97 ( L_10 ,
V_28 -> V_80 ) ;
return - V_79 ;
}
V_44 = F_35 ( V_26 ) ;
if ( V_16 != V_139 ) {
if ( ! V_44 || ! F_102 ( V_16 , V_44 -> V_141 ) ) {
F_97 ( L_11
L_12 , V_16 , V_28 -> V_80 ) ;
return - V_79 ;
}
V_24 = F_95 ( V_99 , V_26 , V_23 , V_135 , V_16 ) ;
} else {
if ( ! V_44 || F_103 ( V_44 -> V_141 , V_139 ) ) {
V_24 = F_95 ( V_99 , V_26 , V_23 , V_135 , 0 ) ;
goto V_51;
}
F_39 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_24 = F_95 ( V_99 , V_26 , V_23 , V_135 , V_16 ) ;
if ( V_24 )
goto V_51;
}
}
V_51:
return V_24 ;
}
static int F_104 ( struct V_6 * V_7 , const T_5 * V_23 , T_4 V_142 )
{
struct V_38 * V_20 = & V_7 -> V_39 [ F_9 ( V_23 , V_142 ) ] ;
struct V_2 * V_11 ;
V_11 = F_32 ( V_20 , V_23 , V_142 ) ;
if ( ! V_11 )
return - V_132 ;
F_22 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_105 ( struct V_25 * V_26 ,
const unsigned char * V_23 , T_4 V_16 )
{
int V_24 ;
F_31 ( & V_26 -> V_7 -> V_40 ) ;
V_24 = F_104 ( V_26 -> V_7 , V_23 , V_16 ) ;
F_33 ( & V_26 -> V_7 -> V_40 ) ;
return V_24 ;
}
int F_106 ( struct V_98 * V_99 , struct V_137 * V_138 [] ,
struct V_60 * V_28 ,
const unsigned char * V_23 )
{
struct V_25 * V_26 ;
int V_24 ;
struct V_43 * V_44 ;
unsigned short V_16 = V_139 ;
if ( V_138 [ V_118 ] ) {
if ( F_98 ( V_138 [ V_118 ] ) != sizeof( unsigned short ) ) {
F_97 ( L_7 ) ;
return - V_79 ;
}
V_16 = F_99 ( V_138 [ V_118 ] ) ;
if ( ! V_16 || V_16 >= V_140 ) {
F_97 ( L_8 ,
V_16 ) ;
return - V_79 ;
}
}
V_26 = F_101 ( V_28 ) ;
if ( V_26 == NULL ) {
F_97 ( L_13 ,
V_28 -> V_80 ) ;
return - V_79 ;
}
V_44 = F_35 ( V_26 ) ;
if ( V_16 != V_139 ) {
if ( ! V_44 || ! F_102 ( V_16 , V_44 -> V_141 ) ) {
F_97 ( L_14
L_12 , V_16 , V_28 -> V_80 ) ;
return - V_79 ;
}
V_24 = F_105 ( V_26 , V_23 , V_16 ) ;
} else {
if ( ! V_44 || F_103 ( V_44 -> V_141 , V_139 ) ) {
V_24 = F_105 ( V_26 , V_23 , 0 ) ;
goto V_51;
}
V_24 = - V_132 ;
F_39 (vid, pv->vlan_bitmap, VLAN_N_VID) {
V_24 &= F_105 ( V_26 , V_23 , V_16 ) ;
}
}
V_51:
return V_24 ;
}
int F_107 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 , * V_27 ;
int V_46 ;
int V_24 ;
F_16 () ;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
F_62 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
V_24 = F_19 ( V_26 -> V_28 , V_11 -> V_23 . V_23 ) ;
if ( V_24 )
goto V_143;
}
}
return 0 ;
V_143:
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
F_62 (tmp, &br->hash[i], hlist) {
if ( V_27 == V_11 )
break;
if ( ! V_27 -> V_12 )
continue;
F_20 ( V_26 -> V_28 , V_27 -> V_23 . V_23 ) ;
}
}
return V_24 ;
}
void F_108 ( struct V_6 * V_7 , struct V_25 * V_26 )
{
struct V_2 * V_11 ;
int V_46 ;
F_16 () ;
for ( V_46 = 0 ; V_46 < V_18 ; V_46 ++ ) {
F_54 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
F_20 ( V_26 -> V_28 , V_11 -> V_23 . V_23 ) ;
}
}
}
