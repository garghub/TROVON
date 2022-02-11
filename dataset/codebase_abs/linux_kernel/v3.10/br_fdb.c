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
void F_19 ( struct V_26 * V_27 , const unsigned char * V_28 )
{
struct V_6 * V_7 = V_27 -> V_7 ;
bool V_29 = ( F_20 ( V_27 ) == NULL ) ? true : false ;
int V_30 ;
F_21 ( & V_7 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
struct V_32 * V_33 ;
F_22 (h, &br->hash[i]) {
struct V_2 * V_23 ;
V_23 = F_23 ( V_33 , struct V_2 , V_24 ) ;
if ( V_23 -> V_34 == V_27 && V_23 -> V_35 ) {
struct V_26 * V_36 ;
T_4 V_16 = V_23 -> V_37 ;
F_24 (op, &br->port_list, list) {
if ( V_36 != V_27 &&
F_25 ( V_36 -> V_38 -> V_39 ,
V_23 -> V_40 . V_40 ) &&
F_26 ( V_36 , V_16 ) ) {
V_23 -> V_34 = V_36 ;
goto V_41;
}
}
F_15 ( V_7 , V_23 ) ;
V_41:
F_27 ( V_7 , V_27 , V_28 , V_16 ) ;
if ( V_29 )
goto V_42;
}
}
}
V_42:
F_28 ( & V_7 -> V_31 ) ;
}
void F_29 ( struct V_6 * V_7 , const T_5 * V_28 )
{
struct V_2 * V_23 ;
struct V_43 * V_44 ;
T_4 V_16 = 0 ;
V_23 = F_30 ( V_7 , V_7 -> V_38 -> V_39 , 0 ) ;
if ( V_23 && V_23 -> V_35 && ! V_23 -> V_34 )
F_15 ( V_7 , V_23 ) ;
F_27 ( V_7 , NULL , V_28 , 0 ) ;
V_44 = F_31 ( V_7 ) ;
if ( ! V_44 )
return;
F_32 (vid, pv->vlan_bitmap, BR_VLAN_BITMAP_LEN) {
V_23 = F_30 ( V_7 , V_7 -> V_38 -> V_39 , V_16 ) ;
if ( V_23 && V_23 -> V_35 && ! V_23 -> V_34 )
F_15 ( V_7 , V_23 ) ;
F_27 ( V_7 , NULL , V_28 , V_16 ) ;
}
}
void F_33 ( unsigned long V_45 )
{
struct V_6 * V_7 = (struct V_6 * ) V_45 ;
unsigned long V_46 = F_6 ( V_7 ) ;
unsigned long V_47 = V_14 + V_7 -> V_10 ;
int V_30 ;
F_34 ( & V_7 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
struct V_2 * V_23 ;
struct V_32 * V_48 ;
F_35 (f, n, &br->hash[i], hlist) {
unsigned long V_49 ;
if ( V_23 -> V_12 )
continue;
V_49 = V_23 -> V_13 + V_46 ;
if ( F_8 ( V_49 , V_14 ) )
F_15 ( V_7 , V_23 ) ;
else if ( F_36 ( V_49 , V_47 ) )
V_47 = V_49 ;
}
}
F_37 ( & V_7 -> V_31 ) ;
F_38 ( & V_7 -> V_50 , F_39 ( V_47 ) ) ;
}
void F_40 ( struct V_6 * V_7 )
{
int V_30 ;
F_21 ( & V_7 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
struct V_2 * V_23 ;
struct V_32 * V_48 ;
F_35 (f, n, &br->hash[i], hlist) {
if ( ! V_23 -> V_12 )
F_15 ( V_7 , V_23 ) ;
}
}
F_28 ( & V_7 -> V_31 ) ;
}
void F_41 ( struct V_6 * V_7 ,
const struct V_26 * V_27 ,
int V_51 )
{
int V_30 ;
F_21 ( & V_7 -> V_31 ) ;
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
struct V_32 * V_33 , * V_52 ;
F_42 (h, g, &br->hash[i]) {
struct V_2 * V_23
= F_23 ( V_33 , struct V_2 , V_24 ) ;
if ( V_23 -> V_34 != V_27 )
continue;
if ( V_23 -> V_12 && ! V_51 )
continue;
if ( V_23 -> V_35 ) {
struct V_26 * V_36 ;
F_24 (op, &br->port_list, list) {
if ( V_36 != V_27 &&
F_25 ( V_36 -> V_38 -> V_39 ,
V_23 -> V_40 . V_40 ) ) {
V_23 -> V_34 = V_36 ;
goto V_53;
}
}
}
F_15 ( V_7 , V_23 ) ;
V_53: ;
}
}
F_28 ( & V_7 -> V_31 ) ;
}
struct V_2 * F_30 ( struct V_6 * V_7 ,
const unsigned char * V_40 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_43 (fdb,
&br->hash[br_mac_hash(addr, vid)], hlist) {
if ( F_25 ( V_11 -> V_40 . V_40 , V_40 ) &&
V_11 -> V_37 == V_16 ) {
if ( F_44 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_45 ( struct V_54 * V_38 , unsigned char * V_40 )
{
struct V_2 * V_11 ;
struct V_26 * V_55 ;
int V_56 ;
F_46 () ;
V_55 = F_47 ( V_38 ) ;
if ( ! V_55 )
V_56 = 0 ;
else {
V_11 = F_30 ( V_55 -> V_7 , V_40 , 0 ) ;
V_56 = V_11 && V_11 -> V_34 && V_11 -> V_34 -> V_38 != V_38 &&
V_11 -> V_34 -> V_57 == V_58 ;
}
F_48 () ;
return V_56 ;
}
int F_49 ( struct V_6 * V_7 , void * V_59 ,
unsigned long V_60 , unsigned long V_61 )
{
struct V_62 * V_63 = V_59 ;
int V_30 , V_64 = 0 ;
struct V_2 * V_23 ;
memset ( V_59 , 0 , V_60 * sizeof( struct V_62 ) ) ;
F_46 () ;
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
F_43 (f, &br->hash[i], hlist) {
if ( V_64 >= V_60 )
goto V_65;
if ( F_7 ( V_7 , V_23 ) )
continue;
if ( ! V_23 -> V_34 )
continue;
if ( V_61 ) {
-- V_61 ;
continue;
}
memcpy ( V_63 -> V_66 , V_23 -> V_40 . V_40 , V_67 ) ;
V_63 -> V_68 = V_23 -> V_34 -> V_68 ;
V_63 -> V_69 = V_23 -> V_34 -> V_68 >> 8 ;
V_63 -> V_35 = V_23 -> V_35 ;
if ( ! V_23 -> V_12 )
V_63 -> V_70 = F_50 ( V_14 - V_23 -> V_13 ) ;
++ V_63 ;
++ V_64 ;
}
}
V_65:
F_48 () ;
return V_64 ;
}
static struct V_2 * F_51 ( struct V_71 * V_20 ,
const unsigned char * V_40 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_52 (fdb, head, hlist) {
if ( F_25 ( V_11 -> V_40 . V_40 , V_40 ) &&
V_11 -> V_37 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_53 ( struct V_71 * V_20 ,
const unsigned char * V_40 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
F_43 (fdb, head, hlist) {
if ( F_25 ( V_11 -> V_40 . V_40 , V_40 ) &&
V_11 -> V_37 == V_16 )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_54 ( struct V_71 * V_20 ,
struct V_26 * V_72 ,
const unsigned char * V_40 ,
T_2 V_16 )
{
struct V_2 * V_11 ;
V_11 = F_55 ( V_1 , V_73 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_40 . V_40 , V_40 , V_67 ) ;
V_11 -> V_34 = V_72 ;
V_11 -> V_37 = V_16 ;
V_11 -> V_35 = 0 ;
V_11 -> V_12 = 0 ;
V_11 -> V_13 = V_11 -> V_74 = V_14 ;
F_56 ( & V_11 -> V_24 , V_20 ) ;
}
return V_11 ;
}
static int F_27 ( struct V_6 * V_7 , struct V_26 * V_72 ,
const unsigned char * V_40 , T_4 V_16 )
{
struct V_71 * V_20 = & V_7 -> V_75 [ F_9 ( V_40 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( ! F_57 ( V_40 ) )
return - V_76 ;
V_11 = F_51 ( V_20 , V_40 , V_16 ) ;
if ( V_11 ) {
if ( V_11 -> V_35 )
return 0 ;
F_58 ( V_7 , L_2
L_3 ,
V_72 ? V_72 -> V_38 -> V_77 : V_7 -> V_38 -> V_77 ) ;
F_15 ( V_7 , V_11 ) ;
}
V_11 = F_54 ( V_20 , V_72 , V_40 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_11 -> V_35 = V_11 -> V_12 = 1 ;
F_17 ( V_7 , V_11 , V_78 ) ;
return 0 ;
}
int F_59 ( struct V_6 * V_7 , struct V_26 * V_72 ,
const unsigned char * V_40 , T_4 V_16 )
{
int V_56 ;
F_21 ( & V_7 -> V_31 ) ;
V_56 = F_27 ( V_7 , V_72 , V_40 , V_16 ) ;
F_28 ( & V_7 -> V_31 ) ;
return V_56 ;
}
void F_60 ( struct V_6 * V_7 , struct V_26 * V_72 ,
const unsigned char * V_40 , T_4 V_16 )
{
struct V_71 * V_20 = & V_7 -> V_75 [ F_9 ( V_40 , V_16 ) ] ;
struct V_2 * V_11 ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_72 -> V_57 == V_79 ||
V_72 -> V_57 == V_58 ) )
return;
V_11 = F_53 ( V_20 , V_40 , V_16 ) ;
if ( F_61 ( V_11 ) ) {
if ( F_44 ( V_11 -> V_35 ) ) {
if ( F_62 () )
F_58 ( V_7 , L_4
L_5 ,
V_72 -> V_38 -> V_77 ) ;
} else {
V_11 -> V_34 = V_72 ;
V_11 -> V_13 = V_14 ;
}
} else {
F_34 ( & V_7 -> V_31 ) ;
if ( F_61 ( ! F_51 ( V_20 , V_40 , V_16 ) ) ) {
V_11 = F_54 ( V_20 , V_72 , V_40 , V_16 ) ;
if ( V_11 )
F_17 ( V_7 , V_11 , V_78 ) ;
}
F_37 ( & V_7 -> V_31 ) ;
}
}
static int F_63 ( const struct V_2 * V_11 )
{
if ( V_11 -> V_35 )
return V_80 ;
else if ( V_11 -> V_12 )
return V_81 ;
else if ( F_7 ( V_11 -> V_34 -> V_7 , V_11 ) )
return V_82 ;
else
return V_83 ;
}
static int F_64 ( struct V_84 * V_85 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_86 , T_3 V_87 , int type , unsigned int V_88 )
{
unsigned long V_89 = V_14 ;
struct V_90 V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
V_93 = F_65 ( V_85 , V_86 , V_87 , type , sizeof( * V_95 ) , V_88 ) ;
if ( V_93 == NULL )
return - V_96 ;
V_95 = F_66 ( V_93 ) ;
V_95 -> V_97 = V_98 ;
V_95 -> V_99 = 0 ;
V_95 -> V_100 = 0 ;
V_95 -> V_101 = 0 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = V_11 -> V_34 ? V_11 -> V_34 -> V_38 -> V_104 : V_7 -> V_38 -> V_104 ;
V_95 -> V_105 = F_63 ( V_11 ) ;
if ( F_67 ( V_85 , V_106 , V_67 , & V_11 -> V_40 ) )
goto V_107;
V_91 . V_108 = F_68 ( V_89 - V_11 -> V_74 ) ;
V_91 . V_109 = 0 ;
V_91 . V_110 = F_68 ( V_89 - V_11 -> V_13 ) ;
V_91 . V_111 = 0 ;
if ( F_67 ( V_85 , V_112 , sizeof( V_91 ) , & V_91 ) )
goto V_107;
if ( F_67 ( V_85 , V_113 , sizeof( T_4 ) , & V_11 -> V_37 ) )
goto V_107;
return F_69 ( V_85 , V_93 ) ;
V_107:
F_70 ( V_85 , V_93 ) ;
return - V_96 ;
}
static inline T_6 F_71 ( void )
{
return F_72 ( sizeof( struct V_94 ) )
+ F_73 ( V_67 )
+ F_73 ( sizeof( T_4 ) )
+ F_73 ( sizeof( struct V_90 ) ) ;
}
static void F_17 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_114 * V_114 = F_74 ( V_7 -> V_38 ) ;
struct V_84 * V_85 ;
int V_115 = - V_116 ;
V_85 = F_75 ( F_71 () , V_73 ) ;
if ( V_85 == NULL )
goto V_117;
V_115 = F_64 ( V_85 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_115 < 0 ) {
F_76 ( V_115 == - V_96 ) ;
F_77 ( V_85 ) ;
goto V_117;
}
F_78 ( V_85 , V_114 , 0 , V_118 , NULL , V_73 ) ;
return;
V_117:
if ( V_115 < 0 )
F_79 ( V_114 , V_118 , V_115 ) ;
}
int F_80 ( struct V_84 * V_85 ,
struct V_119 * V_120 ,
struct V_54 * V_38 ,
int V_121 )
{
struct V_6 * V_7 = F_81 ( V_38 ) ;
int V_30 ;
if ( ! ( V_38 -> V_122 & V_123 ) )
goto V_65;
for ( V_30 = 0 ; V_30 < V_18 ; V_30 ++ ) {
struct V_2 * V_23 ;
F_43 (f, &br->hash[i], hlist) {
if ( V_121 < V_120 -> args [ 0 ] )
goto V_61;
if ( F_64 ( V_85 , V_7 , V_23 ,
F_82 ( V_120 -> V_85 ) . V_86 ,
V_120 -> V_93 -> V_124 ,
V_78 ,
V_125 ) < 0 )
break;
V_61:
++ V_121 ;
}
}
V_65:
return V_121 ;
}
static int F_83 ( struct V_26 * V_72 , const T_7 * V_40 ,
T_2 V_57 , T_2 V_88 , T_2 V_16 )
{
struct V_6 * V_7 = V_72 -> V_7 ;
struct V_71 * V_20 = & V_7 -> V_75 [ F_9 ( V_40 , V_16 ) ] ;
struct V_2 * V_11 ;
bool V_126 = false ;
V_11 = F_51 ( V_20 , V_40 , V_16 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_88 & V_127 ) )
return - V_128 ;
V_11 = F_54 ( V_20 , V_72 , V_40 , V_16 ) ;
if ( ! V_11 )
return - V_4 ;
V_126 = true ;
} else {
if ( V_88 & V_129 )
return - V_130 ;
if ( V_11 -> V_34 != V_72 ) {
V_11 -> V_34 = V_72 ;
V_126 = true ;
}
}
if ( F_63 ( V_11 ) != V_57 ) {
if ( V_57 & V_80 )
V_11 -> V_35 = V_11 -> V_12 = 1 ;
else if ( V_57 & V_81 ) {
V_11 -> V_35 = 0 ;
V_11 -> V_12 = 1 ;
} else
V_11 -> V_35 = V_11 -> V_12 = 0 ;
V_126 = true ;
}
V_11 -> V_74 = V_14 ;
if ( V_126 ) {
V_11 -> V_13 = V_14 ;
F_17 ( V_7 , V_11 , V_78 ) ;
}
return 0 ;
}
static int F_84 ( struct V_94 * V_95 , struct V_26 * V_27 ,
const unsigned char * V_40 , T_4 V_131 , T_4 V_16 )
{
int V_115 = 0 ;
if ( V_95 -> V_101 & V_132 ) {
F_46 () ;
F_60 ( V_27 -> V_7 , V_27 , V_40 , V_16 ) ;
F_48 () ;
} else {
F_21 ( & V_27 -> V_7 -> V_31 ) ;
V_115 = F_83 ( V_27 , V_40 , V_95 -> V_105 ,
V_131 , V_16 ) ;
F_28 ( & V_27 -> V_7 -> V_31 ) ;
}
return V_115 ;
}
int F_85 ( struct V_94 * V_95 , struct V_133 * V_134 [] ,
struct V_54 * V_38 ,
const unsigned char * V_40 , T_4 V_131 )
{
struct V_26 * V_27 ;
int V_115 = 0 ;
struct V_43 * V_44 ;
unsigned short V_16 = V_135 ;
if ( ! ( V_95 -> V_105 & ( V_80 | V_81 | V_83 ) ) ) {
F_86 ( L_6 , V_95 -> V_105 ) ;
return - V_76 ;
}
if ( V_134 [ V_113 ] ) {
if ( F_87 ( V_134 [ V_113 ] ) != sizeof( unsigned short ) ) {
F_86 ( L_7 ) ;
return - V_76 ;
}
V_16 = F_88 ( V_134 [ V_113 ] ) ;
if ( V_16 >= V_135 ) {
F_86 ( L_8 ,
V_16 ) ;
return - V_76 ;
}
}
V_27 = F_89 ( V_38 ) ;
if ( V_27 == NULL ) {
F_86 ( L_9 ,
V_38 -> V_77 ) ;
return - V_76 ;
}
V_44 = F_20 ( V_27 ) ;
if ( V_16 != V_135 ) {
if ( ! V_44 || ! F_90 ( V_16 , V_44 -> V_136 ) ) {
F_86 ( L_10
L_11 , V_16 , V_38 -> V_77 ) ;
return - V_76 ;
}
V_115 = F_84 ( V_95 , V_27 , V_40 , V_131 , V_16 ) ;
} else {
if ( ! V_44 || F_91 ( V_44 -> V_136 , V_137 ) ) {
V_115 = F_84 ( V_95 , V_27 , V_40 , V_131 , 0 ) ;
goto V_65;
}
F_92 (vid, pv->vlan_bitmap, BR_VLAN_BITMAP_LEN) {
V_115 = F_84 ( V_95 , V_27 , V_40 , V_131 , V_16 ) ;
if ( V_115 )
goto V_65;
}
}
V_65:
return V_115 ;
}
int F_93 ( struct V_6 * V_7 , const T_5 * V_40 ,
T_4 V_138 )
{
struct V_71 * V_20 = & V_7 -> V_75 [ F_9 ( V_40 , V_138 ) ] ;
struct V_2 * V_11 ;
V_11 = F_51 ( V_20 , V_40 , V_138 ) ;
if ( ! V_11 )
return - V_128 ;
F_15 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_94 ( struct V_26 * V_27 ,
const unsigned char * V_40 , T_4 V_16 )
{
int V_115 ;
F_21 ( & V_27 -> V_7 -> V_31 ) ;
V_115 = F_93 ( V_27 -> V_7 , V_40 , V_16 ) ;
F_28 ( & V_27 -> V_7 -> V_31 ) ;
return V_115 ;
}
int F_95 ( struct V_94 * V_95 , struct V_133 * V_134 [] ,
struct V_54 * V_38 ,
const unsigned char * V_40 )
{
struct V_26 * V_27 ;
int V_115 ;
struct V_43 * V_44 ;
unsigned short V_16 = V_135 ;
if ( V_134 [ V_113 ] ) {
if ( F_87 ( V_134 [ V_113 ] ) != sizeof( unsigned short ) ) {
F_86 ( L_7 ) ;
return - V_76 ;
}
V_16 = F_88 ( V_134 [ V_113 ] ) ;
if ( V_16 >= V_135 ) {
F_86 ( L_8 ,
V_16 ) ;
return - V_76 ;
}
}
V_27 = F_89 ( V_38 ) ;
if ( V_27 == NULL ) {
F_86 ( L_12 ,
V_38 -> V_77 ) ;
return - V_76 ;
}
V_44 = F_20 ( V_27 ) ;
if ( V_16 != V_135 ) {
if ( ! V_44 || ! F_90 ( V_16 , V_44 -> V_136 ) ) {
F_86 ( L_13
L_11 , V_16 , V_38 -> V_77 ) ;
return - V_76 ;
}
V_115 = F_94 ( V_27 , V_40 , V_16 ) ;
} else {
if ( ! V_44 || F_91 ( V_44 -> V_136 , V_137 ) ) {
V_115 = F_94 ( V_27 , V_40 , 0 ) ;
goto V_65;
}
V_115 = - V_128 ;
F_92 (vid, pv->vlan_bitmap, BR_VLAN_BITMAP_LEN) {
V_115 &= F_94 ( V_27 , V_40 , V_16 ) ;
}
}
V_65:
return V_115 ;
}
