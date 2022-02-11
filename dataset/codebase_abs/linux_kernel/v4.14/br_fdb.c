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
static void F_33 ( struct V_6 * V_7 , struct V_2 * V_26 )
{
F_34 ( V_7 , V_26 ) ;
if ( V_26 -> V_12 )
F_32 ( V_7 , V_26 -> V_25 . V_25 ) ;
F_35 ( & V_26 -> V_35 ) ;
F_36 ( V_7 , V_26 , V_36 ) ;
F_37 ( & V_26 -> V_23 , F_12 ) ;
}
static void F_38 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
struct V_2 * V_26 )
{
const unsigned char * V_25 = V_26 -> V_25 . V_25 ;
struct V_37 * V_38 ;
const struct V_39 * V_40 ;
struct V_31 * V_41 ;
T_4 V_17 = V_26 -> V_27 ;
F_27 (op, &br->port_list, list) {
V_38 = F_39 ( V_41 ) ;
if ( V_41 != V_32 && F_19 ( V_41 -> V_33 -> V_42 , V_25 ) &&
( ! V_17 || F_40 ( V_38 , V_17 ) ) ) {
V_26 -> V_43 = V_41 ;
V_26 -> V_44 = 0 ;
return;
}
}
V_38 = F_41 ( V_7 ) ;
V_40 = F_40 ( V_38 , V_17 ) ;
if ( V_32 && F_19 ( V_7 -> V_33 -> V_42 , V_25 ) &&
( ! V_17 || ( V_40 && F_42 ( V_40 ) ) ) ) {
V_26 -> V_43 = NULL ;
V_26 -> V_44 = 0 ;
return;
}
F_33 ( V_7 , V_26 ) ;
}
void F_43 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_26 ;
F_44 ( & V_7 -> V_29 ) ;
V_26 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_26 && V_26 -> V_45 && ! V_26 -> V_44 && V_26 -> V_43 == V_32 )
F_38 ( V_7 , V_32 , V_26 ) ;
F_45 ( & V_7 -> V_29 ) ;
}
void F_46 ( struct V_31 * V_32 , const unsigned char * V_46 )
{
struct V_37 * V_38 ;
struct V_6 * V_7 = V_32 -> V_7 ;
struct V_39 * V_40 ;
int V_47 ;
F_44 ( & V_7 -> V_29 ) ;
V_38 = F_39 ( V_32 ) ;
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
struct V_48 * V_49 ;
F_47 (h, &br->hash[i]) {
struct V_2 * V_26 ;
V_26 = F_48 ( V_49 , struct V_2 , V_35 ) ;
if ( V_26 -> V_43 == V_32 && V_26 -> V_45 && ! V_26 -> V_44 ) {
F_38 ( V_7 , V_32 , V_26 ) ;
if ( ! V_38 || ! V_38 -> V_50 )
goto V_51;
}
}
}
V_51:
F_49 ( V_7 , V_32 , V_46 , 0 ) ;
if ( ! V_38 || ! V_38 -> V_50 )
goto V_52;
F_27 (v, &vg->vlan_list, vlist)
F_49 ( V_7 , V_32 , V_46 , V_40 -> V_17 ) ;
V_52:
F_45 ( & V_7 -> V_29 ) ;
}
void F_50 ( struct V_6 * V_7 , const T_5 * V_46 )
{
struct V_37 * V_38 ;
struct V_2 * V_26 ;
struct V_39 * V_40 ;
F_44 ( & V_7 -> V_29 ) ;
V_26 = F_20 ( V_7 , V_7 -> V_33 -> V_42 , 0 ) ;
if ( V_26 && V_26 -> V_45 && ! V_26 -> V_43 && ! V_26 -> V_44 )
F_38 ( V_7 , NULL , V_26 ) ;
F_49 ( V_7 , NULL , V_46 , 0 ) ;
V_38 = F_41 ( V_7 ) ;
if ( ! V_38 || ! V_38 -> V_50 )
goto V_53;
F_27 (v, &vg->vlan_list, vlist) {
if ( ! F_42 ( V_40 ) )
continue;
V_26 = F_20 ( V_7 , V_7 -> V_33 -> V_42 , V_40 -> V_17 ) ;
if ( V_26 && V_26 -> V_45 && ! V_26 -> V_43 && ! V_26 -> V_44 )
F_38 ( V_7 , NULL , V_26 ) ;
F_49 ( V_7 , NULL , V_46 , V_40 -> V_17 ) ;
}
V_53:
F_45 ( & V_7 -> V_29 ) ;
}
void F_51 ( struct V_54 * V_55 )
{
struct V_6 * V_7 = F_13 ( V_55 , struct V_6 ,
V_56 . V_55 ) ;
unsigned long V_57 = F_6 ( V_7 ) ;
unsigned long V_58 = V_57 ;
unsigned long V_59 = V_15 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
struct V_2 * V_26 ;
struct V_48 * V_60 ;
if ( ! V_7 -> V_28 [ V_47 ] . V_61 )
continue;
F_44 ( & V_7 -> V_29 ) ;
F_52 (f, n, &br->hash[i], hlist) {
unsigned long V_62 ;
if ( V_26 -> V_12 )
continue;
if ( V_26 -> V_13 )
continue;
V_62 = V_26 -> V_14 + V_57 ;
if ( F_53 ( V_62 , V_59 ) )
V_58 = F_54 ( V_58 , V_62 - V_59 ) ;
else
F_33 ( V_7 , V_26 ) ;
}
F_45 ( & V_7 -> V_29 ) ;
F_55 () ;
}
V_58 = F_56 (unsigned long, work_delay, msecs_to_jiffies(10)) ;
F_57 ( V_63 , & V_7 -> V_56 , V_58 ) ;
}
void F_58 ( struct V_6 * V_7 )
{
int V_47 ;
F_44 ( & V_7 -> V_29 ) ;
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
struct V_2 * V_26 ;
struct V_48 * V_60 ;
F_52 (f, n, &br->hash[i], hlist) {
if ( ! V_26 -> V_12 )
F_33 ( V_7 , V_26 ) ;
}
}
F_45 ( & V_7 -> V_29 ) ;
}
void F_59 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
T_4 V_17 ,
int V_64 )
{
int V_47 ;
F_44 ( & V_7 -> V_29 ) ;
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
struct V_48 * V_49 , * V_65 ;
F_60 (h, g, &br->hash[i]) {
struct V_2 * V_26
= F_48 ( V_49 , struct V_2 , V_35 ) ;
if ( V_26 -> V_43 != V_32 )
continue;
if ( ! V_64 )
if ( V_26 -> V_12 || ( V_17 && V_26 -> V_27 != V_17 ) )
continue;
if ( V_26 -> V_45 )
F_38 ( V_7 , V_32 , V_26 ) ;
else
F_33 ( V_7 , V_26 ) ;
}
}
F_45 ( & V_7 -> V_29 ) ;
}
int F_61 ( struct V_66 * V_33 , unsigned char * V_25 )
{
struct V_2 * V_11 ;
struct V_31 * V_67 ;
int V_68 ;
F_22 () ;
V_67 = F_62 ( V_33 ) ;
if ( ! V_67 )
V_68 = 0 ;
else {
V_11 = F_24 ( V_67 -> V_7 , V_25 , 0 ) ;
V_68 = V_11 && V_11 -> V_43 && V_11 -> V_43 -> V_33 != V_33 &&
V_11 -> V_43 -> V_69 == V_70 ;
}
F_23 () ;
return V_68 ;
}
int F_63 ( struct V_6 * V_7 , void * V_71 ,
unsigned long V_72 , unsigned long V_73 )
{
struct V_74 * V_75 = V_71 ;
int V_47 , V_76 = 0 ;
struct V_2 * V_26 ;
memset ( V_71 , 0 , V_72 * sizeof( struct V_74 ) ) ;
F_22 () ;
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
F_18 (f, &br->hash[i], hlist) {
if ( V_76 >= V_72 )
goto V_53;
if ( F_7 ( V_7 , V_26 ) )
continue;
if ( ! V_26 -> V_43 )
continue;
if ( V_73 ) {
-- V_73 ;
continue;
}
memcpy ( V_75 -> V_77 , V_26 -> V_25 . V_25 , V_78 ) ;
V_75 -> V_79 = V_26 -> V_43 -> V_79 ;
V_75 -> V_80 = V_26 -> V_43 -> V_79 >> 8 ;
V_75 -> V_45 = V_26 -> V_45 ;
if ( ! V_26 -> V_12 )
V_75 -> V_81 = F_64 ( V_15 - V_26 -> V_14 ) ;
++ V_75 ;
++ V_76 ;
}
}
V_53:
F_23 () ;
return V_76 ;
}
static struct V_2 * F_65 ( struct V_24 * V_21 ,
struct V_31 * V_82 ,
const unsigned char * V_25 ,
T_2 V_17 ,
unsigned char V_45 ,
unsigned char V_12 )
{
struct V_2 * V_11 ;
V_11 = F_66 ( V_1 , V_83 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_25 . V_25 , V_25 , V_78 ) ;
V_11 -> V_43 = V_82 ;
V_11 -> V_27 = V_17 ;
V_11 -> V_45 = V_45 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_44 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_84 = 0 ;
V_11 -> V_14 = V_11 -> V_85 = V_15 ;
F_67 ( & V_11 -> V_35 , V_21 ) ;
}
return V_11 ;
}
static int F_49 ( struct V_6 * V_7 , struct V_31 * V_82 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
struct V_2 * V_11 ;
if ( ! F_68 ( V_25 ) )
return - V_86 ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 ) {
if ( V_11 -> V_45 )
return 0 ;
F_69 ( V_7 , L_2 ,
V_82 ? V_82 -> V_33 -> V_87 : V_7 -> V_33 -> V_87 , V_25 , V_17 ) ;
F_33 ( V_7 , V_11 ) ;
}
V_11 = F_65 ( V_21 , V_82 , V_25 , V_17 , 1 , 1 ) ;
if ( ! V_11 )
return - V_4 ;
F_25 ( V_7 , V_25 ) ;
F_36 ( V_7 , V_11 , V_88 ) ;
return 0 ;
}
int F_70 ( struct V_6 * V_7 , struct V_31 * V_82 ,
const unsigned char * V_25 , T_4 V_17 )
{
int V_68 ;
F_44 ( & V_7 -> V_29 ) ;
V_68 = F_49 ( V_7 , V_82 , V_25 , V_17 ) ;
F_45 ( & V_7 -> V_29 ) ;
return V_68 ;
}
void F_71 ( struct V_6 * V_7 , struct V_31 * V_82 ,
const unsigned char * V_25 , T_4 V_17 , bool V_44 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
struct V_2 * V_11 ;
bool V_89 = false ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_82 -> V_69 == V_90 ||
V_82 -> V_69 == V_70 ) )
return;
V_11 = F_15 ( V_21 , V_25 , V_17 ) ;
if ( F_72 ( V_11 ) ) {
if ( F_73 ( V_11 -> V_45 ) ) {
if ( F_74 () )
F_69 ( V_7 , L_3 ,
V_82 -> V_33 -> V_87 , V_25 , V_17 ) ;
} else {
unsigned long V_59 = V_15 ;
if ( F_73 ( V_82 != V_11 -> V_43 ) ) {
V_11 -> V_43 = V_82 ;
V_89 = true ;
if ( F_73 ( V_11 -> V_13 ) )
V_11 -> V_13 = 0 ;
}
if ( V_59 != V_11 -> V_14 )
V_11 -> V_14 = V_59 ;
if ( F_73 ( V_44 ) )
V_11 -> V_44 = 1 ;
if ( F_73 ( V_89 ) ) {
F_75 ( V_7 , V_82 , V_25 , V_17 , V_44 ) ;
F_36 ( V_7 , V_11 , V_88 ) ;
}
}
} else {
F_76 ( & V_7 -> V_29 ) ;
if ( F_72 ( ! F_15 ( V_21 , V_25 , V_17 ) ) ) {
V_11 = F_65 ( V_21 , V_82 , V_25 , V_17 , 0 , 0 ) ;
if ( V_11 ) {
if ( F_73 ( V_44 ) )
V_11 -> V_44 = 1 ;
F_75 ( V_7 , V_82 , V_25 , V_17 , V_44 ) ;
F_36 ( V_7 , V_11 , V_88 ) ;
}
}
F_77 ( & V_7 -> V_29 ) ;
}
}
static int F_78 ( const struct V_6 * V_7 ,
const struct V_2 * V_11 )
{
if ( V_11 -> V_45 )
return V_91 ;
else if ( V_11 -> V_12 )
return V_92 ;
else if ( F_7 ( V_7 , V_11 ) )
return V_93 ;
else
return V_94 ;
}
static int F_79 ( struct V_95 * V_96 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_3 V_97 , T_3 V_98 , int type , unsigned int V_99 )
{
unsigned long V_59 = V_15 ;
struct V_100 V_101 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
V_103 = F_80 ( V_96 , V_97 , V_98 , type , sizeof( * V_105 ) , V_99 ) ;
if ( V_103 == NULL )
return - V_106 ;
V_105 = F_81 ( V_103 ) ;
V_105 -> V_107 = V_108 ;
V_105 -> V_109 = 0 ;
V_105 -> V_110 = 0 ;
V_105 -> V_111 = 0 ;
V_105 -> V_112 = 0 ;
V_105 -> V_113 = V_11 -> V_43 ? V_11 -> V_43 -> V_33 -> V_114 : V_7 -> V_33 -> V_114 ;
V_105 -> V_115 = F_78 ( V_7 , V_11 ) ;
if ( V_11 -> V_84 )
V_105 -> V_111 |= V_116 ;
if ( V_11 -> V_13 )
V_105 -> V_111 |= V_117 ;
if ( F_82 ( V_96 , V_118 , V_78 , & V_11 -> V_25 ) )
goto V_119;
if ( F_83 ( V_96 , V_120 , V_7 -> V_33 -> V_114 ) )
goto V_119;
V_101 . V_121 = F_84 ( V_59 - V_11 -> V_85 ) ;
V_101 . V_122 = 0 ;
V_101 . V_123 = F_84 ( V_59 - V_11 -> V_14 ) ;
V_101 . V_124 = 0 ;
if ( F_82 ( V_96 , V_125 , sizeof( V_101 ) , & V_101 ) )
goto V_119;
if ( V_11 -> V_27 && F_82 ( V_96 , V_126 , sizeof( T_4 ) , & V_11 -> V_27 ) )
goto V_119;
F_85 ( V_96 , V_103 ) ;
return 0 ;
V_119:
F_86 ( V_96 , V_103 ) ;
return - V_106 ;
}
static inline T_6 F_87 ( void )
{
return F_88 ( sizeof( struct V_104 ) )
+ F_89 ( V_78 )
+ F_89 ( sizeof( T_3 ) )
+ F_89 ( sizeof( T_4 ) )
+ F_89 ( sizeof( struct V_100 ) ) ;
}
static void F_36 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_127 * V_127 = F_90 ( V_7 -> V_33 ) ;
struct V_95 * V_96 ;
int V_30 = - V_128 ;
F_91 ( V_11 , type ) ;
V_96 = F_92 ( F_87 () , V_83 ) ;
if ( V_96 == NULL )
goto V_129;
V_30 = F_79 ( V_96 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_30 < 0 ) {
F_93 ( V_30 == - V_106 ) ;
F_94 ( V_96 ) ;
goto V_129;
}
F_95 ( V_96 , V_127 , 0 , V_130 , NULL , V_83 ) ;
return;
V_129:
F_96 ( V_127 , V_130 , V_30 ) ;
}
int F_97 ( struct V_95 * V_96 ,
struct V_131 * V_132 ,
struct V_66 * V_33 ,
struct V_66 * V_133 ,
int * V_134 )
{
struct V_6 * V_7 = F_98 ( V_33 ) ;
int V_30 = 0 ;
int V_47 ;
if ( ! ( V_33 -> V_135 & V_136 ) )
goto V_53;
if ( ! V_133 ) {
V_30 = F_99 ( V_96 , V_132 , V_33 , NULL , V_134 ) ;
if ( V_30 < 0 )
goto V_53;
}
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
struct V_2 * V_26 ;
F_18 (f, &br->hash[i], hlist) {
if ( * V_134 < V_132 -> args [ 2 ] )
goto V_73;
if ( V_133 &&
( ! V_26 -> V_43 || V_26 -> V_43 -> V_33 != V_133 ) ) {
if ( V_133 != V_33 )
goto V_73;
if ( V_26 -> V_43 )
goto V_73;
}
if ( ! V_133 && V_26 -> V_43 )
goto V_73;
V_30 = F_79 ( V_96 , V_7 , V_26 ,
F_100 ( V_132 -> V_96 ) . V_97 ,
V_132 -> V_103 -> V_137 ,
V_88 ,
V_138 ) ;
if ( V_30 < 0 )
goto V_53;
V_73:
* V_134 += 1 ;
}
}
V_53:
return V_30 ;
}
static int F_101 ( struct V_6 * V_7 , struct V_31 * V_82 ,
const T_7 * V_25 , T_2 V_69 , T_2 V_99 , T_2 V_17 )
{
struct V_24 * V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
struct V_2 * V_11 ;
bool V_139 = false ;
if ( V_82 && ! ( V_69 & V_91 ) && ! ( V_69 & V_92 ) &&
! ( V_82 -> V_69 == V_90 ||
V_82 -> V_69 == V_70 ) )
return - V_140 ;
if ( ! V_82 && ! ( V_69 & V_91 ) ) {
F_102 ( L_4 ,
V_7 -> V_33 -> V_87 ) ;
return - V_86 ;
}
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_99 & V_141 ) )
return - V_142 ;
V_11 = F_65 ( V_21 , V_82 , V_25 , V_17 , 0 , 0 ) ;
if ( ! V_11 )
return - V_4 ;
V_139 = true ;
} else {
if ( V_99 & V_143 )
return - V_144 ;
if ( V_11 -> V_43 != V_82 ) {
V_11 -> V_43 = V_82 ;
V_139 = true ;
}
}
if ( F_78 ( V_7 , V_11 ) != V_69 ) {
if ( V_69 & V_91 ) {
V_11 -> V_45 = 1 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_25 ( V_7 , V_25 ) ;
}
} else if ( V_69 & V_92 ) {
V_11 -> V_45 = 0 ;
if ( ! V_11 -> V_12 ) {
V_11 -> V_12 = 1 ;
F_25 ( V_7 , V_25 ) ;
}
} else {
V_11 -> V_45 = 0 ;
if ( V_11 -> V_12 ) {
V_11 -> V_12 = 0 ;
F_32 ( V_7 , V_25 ) ;
}
}
V_139 = true ;
}
V_11 -> V_44 = 1 ;
V_11 -> V_85 = V_15 ;
if ( V_139 ) {
V_11 -> V_14 = V_15 ;
F_36 ( V_7 , V_11 , V_88 ) ;
}
return 0 ;
}
static int F_103 ( struct V_104 * V_105 , struct V_6 * V_7 ,
struct V_31 * V_32 , const unsigned char * V_25 ,
T_4 V_145 , T_4 V_17 )
{
int V_30 = 0 ;
if ( V_105 -> V_111 & V_146 ) {
if ( ! V_32 ) {
F_102 ( L_5 ,
V_7 -> V_33 -> V_87 ) ;
return - V_86 ;
}
F_104 () ;
F_22 () ;
F_71 ( V_7 , V_32 , V_25 , V_17 , true ) ;
F_23 () ;
F_105 () ;
} else if ( V_105 -> V_111 & V_117 ) {
V_30 = F_106 ( V_7 , V_32 , V_25 , V_17 ) ;
} else {
F_44 ( & V_7 -> V_29 ) ;
V_30 = F_101 ( V_7 , V_32 , V_25 , V_105 -> V_115 ,
V_145 , V_17 ) ;
F_45 ( & V_7 -> V_29 ) ;
}
return V_30 ;
}
int F_107 ( struct V_104 * V_105 , struct V_147 * V_148 [] ,
struct V_66 * V_33 ,
const unsigned char * V_25 , T_4 V_17 , T_4 V_145 )
{
struct V_37 * V_38 ;
struct V_31 * V_32 = NULL ;
struct V_39 * V_40 ;
struct V_6 * V_7 = NULL ;
int V_30 = 0 ;
F_108 ( V_105 , V_33 , V_25 , V_17 , V_145 ) ;
if ( ! ( V_105 -> V_115 & ( V_91 | V_92 | V_94 ) ) ) {
F_102 ( L_6 , V_105 -> V_115 ) ;
return - V_86 ;
}
if ( F_109 ( V_25 ) ) {
F_102 ( L_7 ) ;
return - V_86 ;
}
if ( V_33 -> V_135 & V_136 ) {
V_7 = F_98 ( V_33 ) ;
V_38 = F_41 ( V_7 ) ;
} else {
V_32 = F_110 ( V_33 ) ;
if ( ! V_32 ) {
F_102 ( L_8 ,
V_33 -> V_87 ) ;
return - V_86 ;
}
V_7 = V_32 -> V_7 ;
V_38 = F_39 ( V_32 ) ;
}
if ( V_17 ) {
V_40 = F_40 ( V_38 , V_17 ) ;
if ( ! V_40 || ! F_42 ( V_40 ) ) {
F_102 ( L_9 , V_17 , V_33 -> V_87 ) ;
return - V_86 ;
}
V_30 = F_103 ( V_105 , V_7 , V_32 , V_25 , V_145 , V_17 ) ;
} else {
V_30 = F_103 ( V_105 , V_7 , V_32 , V_25 , V_145 , 0 ) ;
if ( V_30 || ! V_38 || ! V_38 -> V_50 )
goto V_53;
F_27 (v, &vg->vlan_list, vlist) {
if ( ! F_42 ( V_40 ) )
continue;
V_30 = F_103 ( V_105 , V_7 , V_32 , V_25 , V_145 , V_40 -> V_17 ) ;
if ( V_30 )
goto V_53;
}
}
V_53:
return V_30 ;
}
static int F_111 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
const T_5 * V_25 , T_4 V_149 )
{
struct V_2 * V_11 ;
V_11 = F_20 ( V_7 , V_25 , V_149 ) ;
if ( ! V_11 || V_11 -> V_43 != V_32 )
return - V_142 ;
F_33 ( V_7 , V_11 ) ;
return 0 ;
}
static int F_112 ( struct V_6 * V_7 ,
const struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
int V_30 ;
F_44 ( & V_7 -> V_29 ) ;
V_30 = F_111 ( V_7 , V_32 , V_25 , V_17 ) ;
F_45 ( & V_7 -> V_29 ) ;
return V_30 ;
}
int F_113 ( struct V_104 * V_105 , struct V_147 * V_148 [] ,
struct V_66 * V_33 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_37 * V_38 ;
struct V_31 * V_32 = NULL ;
struct V_39 * V_40 ;
struct V_6 * V_7 ;
int V_30 ;
if ( V_33 -> V_135 & V_136 ) {
V_7 = F_98 ( V_33 ) ;
V_38 = F_41 ( V_7 ) ;
} else {
V_32 = F_110 ( V_33 ) ;
if ( ! V_32 ) {
F_102 ( L_10 ,
V_33 -> V_87 ) ;
return - V_86 ;
}
V_38 = F_39 ( V_32 ) ;
V_7 = V_32 -> V_7 ;
}
if ( V_17 ) {
V_40 = F_40 ( V_38 , V_17 ) ;
if ( ! V_40 ) {
F_102 ( L_11 , V_17 , V_33 -> V_87 ) ;
return - V_86 ;
}
V_30 = F_112 ( V_7 , V_32 , V_25 , V_17 ) ;
} else {
V_30 = - V_142 ;
V_30 &= F_112 ( V_7 , V_32 , V_25 , 0 ) ;
if ( ! V_38 || ! V_38 -> V_50 )
return V_30 ;
F_27 (v, &vg->vlan_list, vlist) {
if ( ! F_42 ( V_40 ) )
continue;
V_30 &= F_112 ( V_7 , V_32 , V_25 , V_40 -> V_17 ) ;
}
}
return V_30 ;
}
int F_114 ( struct V_6 * V_7 , struct V_31 * V_32 )
{
struct V_2 * V_11 , * V_150 ;
int V_47 ;
int V_30 ;
F_26 () ;
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
F_115 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
V_30 = F_29 ( V_32 -> V_33 , V_11 -> V_25 . V_25 ) ;
if ( V_30 )
goto V_151;
}
}
return 0 ;
V_151:
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
F_115 (tmp, &br->hash[i], hlist) {
if ( V_150 == V_11 )
break;
if ( ! V_150 -> V_12 )
continue;
F_31 ( V_32 -> V_33 , V_150 -> V_25 . V_25 ) ;
}
}
return V_30 ;
}
void F_116 ( struct V_6 * V_7 , struct V_31 * V_32 )
{
struct V_2 * V_11 ;
int V_47 ;
F_26 () ;
for ( V_47 = 0 ; V_47 < V_19 ; V_47 ++ ) {
F_18 (fdb, &br->hash[i], hlist) {
if ( ! V_11 -> V_12 )
continue;
F_31 ( V_32 -> V_33 , V_11 -> V_25 . V_25 ) ;
}
}
}
int F_106 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_11 ;
struct V_24 * V_21 ;
bool V_139 = false ;
int V_30 = 0 ;
F_117 ( V_7 , V_32 , V_25 , V_17 ) ;
F_44 ( & V_7 -> V_29 ) ;
V_21 = & V_7 -> V_28 [ F_9 ( V_25 , V_17 ) ] ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( ! V_11 ) {
V_11 = F_65 ( V_21 , V_32 , V_25 , V_17 , 0 , 0 ) ;
if ( ! V_11 ) {
V_30 = - V_4 ;
goto V_152;
}
V_11 -> V_13 = 1 ;
F_36 ( V_7 , V_11 , V_88 ) ;
} else {
V_11 -> V_14 = V_15 ;
if ( V_11 -> V_43 != V_32 ) {
V_11 -> V_43 = V_32 ;
V_139 = true ;
}
if ( V_11 -> V_13 ) {
V_11 -> V_85 = V_15 ;
} else if ( ! V_11 -> V_44 ) {
V_11 -> V_13 = 1 ;
V_139 = true ;
}
if ( V_139 )
F_36 ( V_7 , V_11 , V_88 ) ;
}
V_152:
F_45 ( & V_7 -> V_29 ) ;
return V_30 ;
}
int F_118 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_11 ;
int V_30 = 0 ;
F_44 ( & V_7 -> V_29 ) ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 && V_11 -> V_13 )
F_33 ( V_7 , V_11 ) ;
else
V_30 = - V_142 ;
F_45 ( & V_7 -> V_29 ) ;
return V_30 ;
}
void F_119 ( struct V_6 * V_7 , struct V_31 * V_32 ,
const unsigned char * V_25 , T_4 V_17 )
{
struct V_2 * V_11 ;
F_44 ( & V_7 -> V_29 ) ;
V_11 = F_20 ( V_7 , V_25 , V_17 ) ;
if ( V_11 )
V_11 -> V_84 = 1 ;
F_45 ( & V_7 -> V_29 ) ;
}
