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
static inline int F_9 ( const unsigned char * V_15 )
{
T_2 V_16 = F_10 ( ( T_2 * ) ( V_15 + 2 ) ) ;
return F_11 ( V_16 , V_5 ) & ( V_17 - 1 ) ;
}
static void F_12 ( struct V_18 * V_19 )
{
struct V_2 * V_20
= F_13 ( V_19 , struct V_2 , V_21 ) ;
F_14 ( V_1 , V_20 ) ;
}
static void F_15 ( struct V_6 * V_7 , struct V_2 * V_22 )
{
F_16 ( & V_22 -> V_23 ) ;
F_17 ( V_7 , V_22 , V_24 ) ;
F_18 ( & V_22 -> V_21 , F_12 ) ;
}
void F_19 ( struct V_25 * V_26 , const unsigned char * V_27 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
int V_28 ;
F_20 ( & V_7 -> V_29 ) ;
for ( V_28 = 0 ; V_28 < V_17 ; V_28 ++ ) {
struct V_30 * V_31 ;
F_21 (h, &br->hash[i]) {
struct V_2 * V_22 ;
V_22 = F_22 ( V_31 , struct V_2 , V_23 ) ;
if ( V_22 -> V_32 == V_26 && V_22 -> V_33 ) {
struct V_25 * V_34 ;
F_23 (op, &br->port_list, list) {
if ( V_34 != V_26 &&
F_24 ( V_34 -> V_35 -> V_36 ,
V_22 -> V_37 . V_37 ) ) {
V_22 -> V_32 = V_34 ;
goto V_38;
}
}
F_15 ( V_7 , V_22 ) ;
goto V_38;
}
}
}
V_38:
F_25 ( V_7 , V_26 , V_27 ) ;
F_26 ( & V_7 -> V_29 ) ;
}
void F_27 ( struct V_6 * V_7 , const T_3 * V_27 )
{
struct V_2 * V_22 ;
V_22 = F_28 ( V_7 , V_7 -> V_35 -> V_36 ) ;
if ( V_22 && V_22 -> V_33 && ! V_22 -> V_32 )
F_15 ( V_7 , V_22 ) ;
F_25 ( V_7 , NULL , V_27 ) ;
}
void F_29 ( unsigned long V_39 )
{
struct V_6 * V_7 = (struct V_6 * ) V_39 ;
unsigned long V_40 = F_6 ( V_7 ) ;
unsigned long V_41 = V_14 + V_7 -> V_10 ;
int V_28 ;
F_30 ( & V_7 -> V_29 ) ;
for ( V_28 = 0 ; V_28 < V_17 ; V_28 ++ ) {
struct V_2 * V_22 ;
struct V_30 * V_31 , * V_42 ;
F_31 (f, h, n, &br->hash[i], hlist) {
unsigned long V_43 ;
if ( V_22 -> V_12 )
continue;
V_43 = V_22 -> V_13 + V_40 ;
if ( F_8 ( V_43 , V_14 ) )
F_15 ( V_7 , V_22 ) ;
else if ( F_32 ( V_43 , V_41 ) )
V_41 = V_43 ;
}
}
F_33 ( & V_7 -> V_29 ) ;
F_34 ( & V_7 -> V_44 , F_35 ( V_41 ) ) ;
}
void F_36 ( struct V_6 * V_7 )
{
int V_28 ;
F_20 ( & V_7 -> V_29 ) ;
for ( V_28 = 0 ; V_28 < V_17 ; V_28 ++ ) {
struct V_2 * V_22 ;
struct V_30 * V_31 , * V_42 ;
F_31 (f, h, n, &br->hash[i], hlist) {
if ( ! V_22 -> V_12 )
F_15 ( V_7 , V_22 ) ;
}
}
F_26 ( & V_7 -> V_29 ) ;
}
void F_37 ( struct V_6 * V_7 ,
const struct V_25 * V_26 ,
int V_45 )
{
int V_28 ;
F_20 ( & V_7 -> V_29 ) ;
for ( V_28 = 0 ; V_28 < V_17 ; V_28 ++ ) {
struct V_30 * V_31 , * V_46 ;
F_38 (h, g, &br->hash[i]) {
struct V_2 * V_22
= F_22 ( V_31 , struct V_2 , V_23 ) ;
if ( V_22 -> V_32 != V_26 )
continue;
if ( V_22 -> V_12 && ! V_45 )
continue;
if ( V_22 -> V_33 ) {
struct V_25 * V_34 ;
F_23 (op, &br->port_list, list) {
if ( V_34 != V_26 &&
F_24 ( V_34 -> V_35 -> V_36 ,
V_22 -> V_37 . V_37 ) ) {
V_22 -> V_32 = V_34 ;
goto V_47;
}
}
}
F_15 ( V_7 , V_22 ) ;
V_47: ;
}
}
F_26 ( & V_7 -> V_29 ) ;
}
struct V_2 * F_28 ( struct V_6 * V_7 ,
const unsigned char * V_37 )
{
struct V_30 * V_31 ;
struct V_2 * V_11 ;
F_39 (fdb, h, &br->hash[br_mac_hash(addr)], hlist) {
if ( F_24 ( V_11 -> V_37 . V_37 , V_37 ) ) {
if ( F_40 ( F_7 ( V_7 , V_11 ) ) )
break;
return V_11 ;
}
}
return NULL ;
}
int F_41 ( struct V_48 * V_35 , unsigned char * V_37 )
{
struct V_2 * V_11 ;
struct V_25 * V_49 ;
int V_50 ;
F_42 () ;
V_49 = F_43 ( V_35 ) ;
if ( ! V_49 )
V_50 = 0 ;
else {
V_11 = F_28 ( V_49 -> V_7 , V_37 ) ;
V_50 = V_11 && V_11 -> V_32 && V_11 -> V_32 -> V_35 != V_35 &&
V_11 -> V_32 -> V_51 == V_52 ;
}
F_44 () ;
return V_50 ;
}
int F_45 ( struct V_6 * V_7 , void * V_53 ,
unsigned long V_54 , unsigned long V_55 )
{
struct V_56 * V_57 = V_53 ;
int V_28 , V_58 = 0 ;
struct V_30 * V_31 ;
struct V_2 * V_22 ;
memset ( V_53 , 0 , V_54 * sizeof( struct V_56 ) ) ;
F_42 () ;
for ( V_28 = 0 ; V_28 < V_17 ; V_28 ++ ) {
F_39 (f, h, &br->hash[i], hlist) {
if ( V_58 >= V_54 )
goto V_59;
if ( F_7 ( V_7 , V_22 ) )
continue;
if ( ! V_22 -> V_32 )
continue;
if ( V_55 ) {
-- V_55 ;
continue;
}
memcpy ( V_57 -> V_60 , V_22 -> V_37 . V_37 , V_61 ) ;
V_57 -> V_62 = V_22 -> V_32 -> V_62 ;
V_57 -> V_63 = V_22 -> V_32 -> V_62 >> 8 ;
V_57 -> V_33 = V_22 -> V_33 ;
if ( ! V_22 -> V_12 )
V_57 -> V_64 = F_46 ( V_14 - V_22 -> V_13 ) ;
++ V_57 ;
++ V_58 ;
}
}
V_59:
F_44 () ;
return V_58 ;
}
static struct V_2 * F_47 ( struct V_65 * V_19 ,
const unsigned char * V_37 )
{
struct V_30 * V_31 ;
struct V_2 * V_11 ;
F_48 (fdb, h, head, hlist) {
if ( F_24 ( V_11 -> V_37 . V_37 , V_37 ) )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_49 ( struct V_65 * V_19 ,
const unsigned char * V_37 )
{
struct V_30 * V_31 ;
struct V_2 * V_11 ;
F_39 (fdb, h, head, hlist) {
if ( F_24 ( V_11 -> V_37 . V_37 , V_37 ) )
return V_11 ;
}
return NULL ;
}
static struct V_2 * F_50 ( struct V_65 * V_19 ,
struct V_25 * V_66 ,
const unsigned char * V_37 )
{
struct V_2 * V_11 ;
V_11 = F_51 ( V_1 , V_67 ) ;
if ( V_11 ) {
memcpy ( V_11 -> V_37 . V_37 , V_37 , V_61 ) ;
V_11 -> V_32 = V_66 ;
V_11 -> V_33 = 0 ;
V_11 -> V_12 = 0 ;
V_11 -> V_13 = V_11 -> V_68 = V_14 ;
F_52 ( & V_11 -> V_23 , V_19 ) ;
}
return V_11 ;
}
static int F_25 ( struct V_6 * V_7 , struct V_25 * V_66 ,
const unsigned char * V_37 )
{
struct V_65 * V_19 = & V_7 -> V_69 [ F_9 ( V_37 ) ] ;
struct V_2 * V_11 ;
if ( ! F_53 ( V_37 ) )
return - V_70 ;
V_11 = F_47 ( V_19 , V_37 ) ;
if ( V_11 ) {
if ( V_11 -> V_33 )
return 0 ;
F_54 ( V_7 , L_2
L_3 ,
V_66 -> V_35 -> V_71 ) ;
F_15 ( V_7 , V_11 ) ;
}
V_11 = F_50 ( V_19 , V_66 , V_37 ) ;
if ( ! V_11 )
return - V_4 ;
V_11 -> V_33 = V_11 -> V_12 = 1 ;
F_17 ( V_7 , V_11 , V_72 ) ;
return 0 ;
}
int F_55 ( struct V_6 * V_7 , struct V_25 * V_66 ,
const unsigned char * V_37 )
{
int V_50 ;
F_20 ( & V_7 -> V_29 ) ;
V_50 = F_25 ( V_7 , V_66 , V_37 ) ;
F_26 ( & V_7 -> V_29 ) ;
return V_50 ;
}
void F_56 ( struct V_6 * V_7 , struct V_25 * V_66 ,
const unsigned char * V_37 )
{
struct V_65 * V_19 = & V_7 -> V_69 [ F_9 ( V_37 ) ] ;
struct V_2 * V_11 ;
if ( F_6 ( V_7 ) == 0 )
return;
if ( ! ( V_66 -> V_51 == V_73 ||
V_66 -> V_51 == V_52 ) )
return;
V_11 = F_49 ( V_19 , V_37 ) ;
if ( F_57 ( V_11 ) ) {
if ( F_40 ( V_11 -> V_33 ) ) {
if ( F_58 () )
F_54 ( V_7 , L_4
L_5 ,
V_66 -> V_35 -> V_71 ) ;
} else {
V_11 -> V_32 = V_66 ;
V_11 -> V_13 = V_14 ;
}
} else {
F_30 ( & V_7 -> V_29 ) ;
if ( F_57 ( ! F_47 ( V_19 , V_37 ) ) ) {
V_11 = F_50 ( V_19 , V_66 , V_37 ) ;
if ( V_11 )
F_17 ( V_7 , V_11 , V_72 ) ;
}
F_33 ( & V_7 -> V_29 ) ;
}
}
static int F_59 ( const struct V_2 * V_11 )
{
if ( V_11 -> V_33 )
return V_74 ;
else if ( V_11 -> V_12 )
return V_75 ;
else if ( F_7 ( V_11 -> V_32 -> V_7 , V_11 ) )
return V_76 ;
else
return V_77 ;
}
static int F_60 ( struct V_78 * V_79 , const struct V_6 * V_7 ,
const struct V_2 * V_11 ,
T_2 V_80 , T_2 V_81 , int type , unsigned int V_82 )
{
unsigned long V_83 = V_14 ;
struct V_84 V_85 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
V_87 = F_61 ( V_79 , V_80 , V_81 , type , sizeof( * V_89 ) , V_82 ) ;
if ( V_87 == NULL )
return - V_90 ;
V_89 = F_62 ( V_87 ) ;
V_89 -> V_91 = V_92 ;
V_89 -> V_93 = 0 ;
V_89 -> V_94 = 0 ;
V_89 -> V_95 = 0 ;
V_89 -> V_96 = 0 ;
V_89 -> V_97 = V_11 -> V_32 ? V_11 -> V_32 -> V_35 -> V_98 : V_7 -> V_35 -> V_98 ;
V_89 -> V_99 = F_59 ( V_11 ) ;
if ( F_63 ( V_79 , V_100 , V_61 , & V_11 -> V_37 ) )
goto V_101;
V_85 . V_102 = F_64 ( V_83 - V_11 -> V_68 ) ;
V_85 . V_103 = 0 ;
V_85 . V_104 = F_64 ( V_83 - V_11 -> V_13 ) ;
V_85 . V_105 = 0 ;
if ( F_63 ( V_79 , V_106 , sizeof( V_85 ) , & V_85 ) )
goto V_101;
return F_65 ( V_79 , V_87 ) ;
V_101:
F_66 ( V_79 , V_87 ) ;
return - V_90 ;
}
static inline T_4 F_67 ( void )
{
return F_68 ( sizeof( struct V_88 ) )
+ F_69 ( V_61 )
+ F_69 ( sizeof( struct V_84 ) ) ;
}
static void F_17 ( struct V_6 * V_7 ,
const struct V_2 * V_11 , int type )
{
struct V_107 * V_107 = F_70 ( V_7 -> V_35 ) ;
struct V_78 * V_79 ;
int V_108 = - V_109 ;
V_79 = F_71 ( F_67 () , V_67 ) ;
if ( V_79 == NULL )
goto V_110;
V_108 = F_60 ( V_79 , V_7 , V_11 , 0 , 0 , type , 0 ) ;
if ( V_108 < 0 ) {
F_72 ( V_108 == - V_90 ) ;
F_73 ( V_79 ) ;
goto V_110;
}
F_74 ( V_79 , V_107 , 0 , V_111 , NULL , V_67 ) ;
return;
V_110:
if ( V_108 < 0 )
F_75 ( V_107 , V_111 , V_108 ) ;
}
int F_76 ( struct V_78 * V_79 ,
struct V_112 * V_113 ,
struct V_48 * V_35 ,
int V_114 )
{
struct V_6 * V_7 = F_77 ( V_35 ) ;
int V_28 ;
if ( ! ( V_35 -> V_115 & V_116 ) )
goto V_59;
for ( V_28 = 0 ; V_28 < V_17 ; V_28 ++ ) {
struct V_30 * V_31 ;
struct V_2 * V_22 ;
F_39 (f, h, &br->hash[i], hlist) {
if ( V_114 < V_113 -> args [ 0 ] )
goto V_55;
if ( F_60 ( V_79 , V_7 , V_22 ,
F_78 ( V_113 -> V_79 ) . V_80 ,
V_113 -> V_87 -> V_117 ,
V_72 ,
V_118 ) < 0 )
break;
V_55:
++ V_114 ;
}
}
V_59:
return V_114 ;
}
static int F_79 ( struct V_25 * V_66 , const T_5 * V_37 ,
T_6 V_51 , T_6 V_82 )
{
struct V_6 * V_7 = V_66 -> V_7 ;
struct V_65 * V_19 = & V_7 -> V_69 [ F_9 ( V_37 ) ] ;
struct V_2 * V_11 ;
V_11 = F_47 ( V_19 , V_37 ) ;
if ( V_11 == NULL ) {
if ( ! ( V_82 & V_119 ) )
return - V_120 ;
V_11 = F_50 ( V_19 , V_66 , V_37 ) ;
if ( ! V_11 )
return - V_4 ;
F_17 ( V_7 , V_11 , V_72 ) ;
} else {
if ( V_82 & V_121 )
return - V_122 ;
}
if ( F_59 ( V_11 ) != V_51 ) {
if ( V_51 & V_74 )
V_11 -> V_33 = V_11 -> V_12 = 1 ;
else if ( V_51 & V_75 ) {
V_11 -> V_33 = 0 ;
V_11 -> V_12 = 1 ;
} else
V_11 -> V_33 = V_11 -> V_12 = 0 ;
V_11 -> V_13 = V_11 -> V_68 = V_14 ;
F_17 ( V_7 , V_11 , V_72 ) ;
}
return 0 ;
}
int F_80 ( struct V_88 * V_89 , struct V_123 * V_124 [] ,
struct V_48 * V_35 ,
const unsigned char * V_37 , T_7 V_125 )
{
struct V_25 * V_26 ;
int V_108 = 0 ;
if ( ! ( V_89 -> V_99 & ( V_74 | V_75 | V_77 ) ) ) {
F_81 ( L_6 , V_89 -> V_99 ) ;
return - V_70 ;
}
V_26 = F_82 ( V_35 ) ;
if ( V_26 == NULL ) {
F_81 ( L_7 ,
V_35 -> V_71 ) ;
return - V_70 ;
}
if ( V_89 -> V_95 & V_126 ) {
F_42 () ;
F_56 ( V_26 -> V_7 , V_26 , V_37 ) ;
F_44 () ;
} else {
F_20 ( & V_26 -> V_7 -> V_29 ) ;
V_108 = F_79 ( V_26 , V_37 , V_89 -> V_99 , V_125 ) ;
F_26 ( & V_26 -> V_7 -> V_29 ) ;
}
return V_108 ;
}
static int F_83 ( struct V_25 * V_26 , const T_3 * V_37 )
{
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_65 * V_19 = & V_7 -> V_69 [ F_9 ( V_37 ) ] ;
struct V_2 * V_11 ;
V_11 = F_47 ( V_19 , V_37 ) ;
if ( ! V_11 )
return - V_120 ;
F_15 ( V_26 -> V_7 , V_11 ) ;
return 0 ;
}
int F_84 ( struct V_88 * V_89 , struct V_48 * V_35 ,
const unsigned char * V_37 )
{
struct V_25 * V_26 ;
int V_108 ;
V_26 = F_82 ( V_35 ) ;
if ( V_26 == NULL ) {
F_81 ( L_8 ,
V_35 -> V_71 ) ;
return - V_70 ;
}
F_20 ( & V_26 -> V_7 -> V_29 ) ;
V_108 = F_83 ( V_26 , V_37 ) ;
F_26 ( & V_26 -> V_7 -> V_29 ) ;
return V_108 ;
}
