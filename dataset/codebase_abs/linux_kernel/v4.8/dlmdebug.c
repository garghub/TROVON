void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_4 ;
F_6 ( & V_2 -> V_3 ) ;
F_7 ( L_1 ) ;
V_4 = 0 ;
while ( 1 ) {
V_4 = F_8 ( V_2 -> V_5 , V_6 , V_4 ) ;
if ( V_4 >= V_6 )
break;
F_7 ( L_2 , V_4 ) ;
V_4 ++ ;
}
F_7 ( L_3 , V_2 -> V_7 ) ;
}
static void F_9 ( struct V_8 * V_9 )
{
F_2 ( & V_9 -> V_3 ) ;
F_7 ( L_4
L_5
L_6 ,
V_9 -> V_10 . type , V_9 -> V_10 . V_11 , V_9 -> V_10 . V_12 ,
F_10 ( F_11 ( V_9 -> V_10 . V_13 ) ) ,
F_12 ( F_11 ( V_9 -> V_10 . V_13 ) ) ,
F_13 ( & V_9 -> V_14 . V_15 ) ,
( F_14 ( & V_9 -> V_16 ) ? 'y' : 'n' ) ,
( V_9 -> V_17 ? 'y' : 'n' ) ,
( F_14 ( & V_9 -> V_18 ) ? 'y' : 'n' ) ,
( V_9 -> V_19 ? 'y' : 'n' ) ,
( V_9 -> V_20 ? 'y' : 'n' ) ,
( V_9 -> V_21 ? 'y' : 'n' ) ,
( V_9 -> V_22 ? 'y' : 'n' ) ,
( V_9 -> V_23 ? 'y' : 'n' ) ) ;
F_4 ( & V_9 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
char V_24 [ V_25 ] ;
F_6 ( & V_2 -> V_3 ) ;
F_15 ( V_2 -> V_26 . V_27 , V_2 -> V_26 . V_28 ,
V_24 , sizeof( V_24 ) ) ;
F_7 ( L_7 ,
V_24 , V_2 -> V_29 , V_2 -> V_30 ) ;
F_7 ( L_8 ,
V_2 -> V_31 , F_13 ( & V_2 -> V_32 . V_15 ) ,
F_14 ( & V_2 -> V_33 ) ? L_9 : L_10 ) ;
F_7 ( L_11
L_12 ,
F_14 ( & V_2 -> V_34 ) ? L_9 : L_10 ,
F_14 ( & V_2 -> V_35 ) ? L_9 : L_10 ,
V_2 -> V_36 ? L_10 : L_9 ) ;
F_7 ( L_13 ,
V_2 -> V_7 , F_13 ( & V_2 -> V_37 ) ) ;
F_5 ( V_2 ) ;
F_7 ( L_14 ) ;
F_16 (lock, &res->granted, list) {
F_9 ( V_9 ) ;
}
F_7 ( L_15 ) ;
F_16 (lock, &res->converting, list) {
F_9 ( V_9 ) ;
}
F_7 ( L_16 ) ;
F_16 (lock, &res->blocked, list) {
F_9 ( V_9 ) ;
}
}
void F_17 ( struct V_8 * V_38 )
{
F_1 ( V_38 -> V_39 ) ;
}
const char * F_18 ( enum V_40 V_41 )
{
if ( V_41 >= V_42 || V_41 < 0 )
return V_43 [ V_42 ] ;
return V_43 [ V_41 ] ;
}
const char * F_19 ( enum V_40 V_41 )
{
if ( V_41 >= V_42 || V_41 < 0 )
return V_44 [ V_42 ] ;
return V_44 [ V_41 ] ;
}
static int F_15 ( const char * V_26 , int V_45 , char * V_24 ,
int V_28 )
{
int V_46 = 0 ;
T_1 V_47 ;
#define F_20 18
if ( * V_26 == 'N' ) {
memcpy ( ( T_1 * ) & V_47 ,
( char * ) & V_26 [ F_20 ] ,
sizeof( T_1 ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_17 ,
F_20 - 1 , V_26 ,
( unsigned int ) F_11 ( V_47 ) ) ;
} else
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_18 ,
V_45 , V_26 ) ;
return V_46 ;
}
static int F_21 ( unsigned long * V_48 , int V_49 ,
char * V_24 , int V_28 )
{
int V_46 = 0 ;
int V_50 = - 1 ;
while ( ( V_50 = F_8 ( V_48 , V_49 , V_50 + 1 ) ) < V_49 )
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_19 , V_50 ) ;
return V_46 ;
}
static int F_22 ( struct V_51 * V_52 , char * V_24 , int V_28 )
{
int V_46 = 0 ;
char * V_53 ;
if ( V_52 -> type == V_54 )
V_53 = L_20 ;
else if ( V_52 -> type == V_55 )
V_53 = L_21 ;
else
V_53 = L_22 ;
V_46 += F_15 ( V_52 -> V_56 , V_52 -> V_57 , V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_23 ,
V_53 , V_52 -> V_58 , V_52 -> V_59 ,
! F_14 ( & V_52 -> V_60 ) ,
! ! V_52 -> V_61 ,
F_13 ( & V_52 -> V_62 . V_15 ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_24 ) ;
V_46 += F_21 ( V_52 -> V_63 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_26 ) ;
V_46 += F_21 ( V_52 -> V_64 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_27 ) ;
V_46 += F_21 ( V_52 -> V_65 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_28 ) ;
V_46 += F_21 ( V_52 -> V_66 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
return V_46 ;
}
void F_23 ( struct V_51 * V_52 )
{
char * V_24 ;
V_24 = ( char * ) F_24 ( V_67 ) ;
if ( V_24 ) {
F_22 ( V_52 , V_24 , V_68 - 1 ) ;
F_25 ( ( unsigned long ) V_24 ) ;
}
}
static int F_26 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
F_25 ( ( unsigned long ) V_70 -> V_71 ) ;
return 0 ;
}
static T_2 F_27 ( struct V_70 * V_70 , char T_3 * V_24 ,
T_4 V_72 , T_5 * V_73 )
{
return F_28 ( V_24 , V_72 , V_73 , V_70 -> V_71 ,
F_29 ( V_70 -> V_74 -> V_75 ) ) ;
}
static int F_30 ( struct V_76 * V_77 , char * V_24 , int V_28 )
{
struct V_1 * V_2 ;
int V_46 = 0 ;
unsigned long V_78 = 0 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_29 , V_77 -> V_27 ) ;
F_2 ( & V_77 -> V_3 ) ;
F_16 (res, &dlm->purge_list, purge) {
++ V_78 ;
if ( V_28 - V_46 < 100 )
continue;
F_2 ( & V_2 -> V_3 ) ;
V_46 += F_15 ( V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_28 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_30 ,
( V_79 - V_2 -> V_31 ) / V_80 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
F_4 ( & V_77 -> V_3 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_31 , V_78 ) ;
return V_46 ;
}
static int F_31 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_76 * V_77 = V_69 -> V_81 ;
char * V_24 = NULL ;
V_24 = ( char * ) F_24 ( V_67 ) ;
if ( ! V_24 )
goto V_82;
F_32 ( V_69 , F_30 ( V_77 , V_24 , V_68 - 1 ) ) ;
V_70 -> V_71 = V_24 ;
return 0 ;
V_82:
return - V_83 ;
}
static int F_33 ( struct V_76 * V_77 , char * V_24 , int V_28 )
{
struct V_51 * V_52 ;
struct V_84 * V_85 ;
int V_50 , V_46 = 0 ;
unsigned long V_78 = 0 , V_86 = 0 , V_87 = 0 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_32 , V_77 -> V_27 ) ;
F_2 ( & V_77 -> V_88 ) ;
for ( V_50 = 0 ; V_50 < V_89 ; V_50 ++ ) {
V_85 = F_34 ( V_77 , V_50 ) ;
F_35 (mle, bucket, master_hash_node) {
++ V_78 ;
++ V_87 ;
if ( V_28 - V_46 < 200 )
continue;
V_46 += F_22 ( V_52 , V_24 + V_46 , V_28 - V_46 ) ;
}
V_86 = F_36 ( V_86 , V_87 ) ;
V_87 = 0 ;
}
F_4 ( & V_77 -> V_88 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_33 , V_78 , V_86 ) ;
return V_46 ;
}
static int F_37 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_76 * V_77 = V_69 -> V_81 ;
char * V_24 = NULL ;
V_24 = ( char * ) F_24 ( V_67 ) ;
if ( ! V_24 )
goto V_82;
F_32 ( V_69 , F_33 ( V_77 , V_24 , V_68 - 1 ) ) ;
V_70 -> V_71 = V_24 ;
return 0 ;
V_82:
return - V_83 ;
}
static int F_38 ( struct V_8 * V_9 , int V_90 , char * V_24 , int V_28 )
{
int V_46 ;
#define F_39 1
F_2 ( & V_9 -> V_3 ) ;
V_46 = snprintf ( V_24 , V_28 , L_34
L_35 ,
F_39 ,
V_90 , V_9 -> V_10 . type , V_9 -> V_10 . V_11 ,
V_9 -> V_10 . V_12 ,
F_10 ( F_11 ( V_9 -> V_10 . V_13 ) ) ,
F_12 ( F_11 ( V_9 -> V_10 . V_13 ) ) ,
! F_14 ( & V_9 -> V_16 ) ,
! F_14 ( & V_9 -> V_18 ) ,
V_9 -> V_17 , V_9 -> V_19 ,
V_9 -> V_20 , V_9 -> V_21 ,
V_9 -> V_22 , V_9 -> V_23 ,
F_13 ( & V_9 -> V_14 . V_15 ) ) ;
F_4 ( & V_9 -> V_3 ) ;
return V_46 ;
}
static int F_40 ( struct V_1 * V_2 , char * V_24 , int V_28 )
{
struct V_8 * V_9 ;
int V_50 ;
int V_46 = 0 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_36 ) ;
V_46 += F_15 ( V_2 -> V_26 . V_27 , V_2 -> V_26 . V_28 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
#define F_41 1
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_37 ,
F_41 ,
V_2 -> V_29 , V_2 -> V_30 , V_2 -> V_31 ,
! F_14 ( & V_2 -> V_33 ) ,
! F_14 ( & V_2 -> V_34 ) ,
! F_14 ( & V_2 -> V_35 ) ,
V_2 -> V_7 , V_2 -> V_36 ,
F_13 ( & V_2 -> V_37 ) ,
F_13 ( & V_2 -> V_32 . V_15 ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_38 ) ;
V_46 += F_21 ( V_2 -> V_5 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_39 ) ;
for ( V_50 = 0 ; V_50 < V_91 ; V_50 ++ )
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_40 , ( unsigned char ) V_2 -> V_92 [ V_50 ] ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
F_16 (lock, &res->granted, list)
V_46 += F_38 ( V_9 , 0 , V_24 + V_46 , V_28 - V_46 ) ;
F_16 (lock, &res->converting, list)
V_46 += F_38 ( V_9 , 1 , V_24 + V_46 , V_28 - V_46 ) ;
F_16 (lock, &res->blocked, list)
V_46 += F_38 ( V_9 , 2 , V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
return V_46 ;
}
static void * F_42 ( struct V_93 * V_94 , T_5 * V_95 )
{
struct V_96 * V_97 = V_94 -> V_98 ;
struct V_76 * V_77 = V_97 -> V_99 ;
struct V_1 * V_100 = V_97 -> V_101 ;
struct V_1 * V_2 = NULL ;
struct V_102 * V_103 ;
F_2 ( & V_77 -> V_104 ) ;
if ( V_100 )
V_103 = & V_100 -> V_105 ;
else {
V_103 = & V_77 -> V_106 ;
if ( F_14 ( V_103 ) ) {
V_97 = NULL ;
F_4 ( & V_77 -> V_104 ) ;
goto V_82;
}
}
F_16 (res, track_list, tracking) {
if ( & V_2 -> V_105 == & V_77 -> V_106 )
V_2 = NULL ;
else
F_43 ( V_2 ) ;
break;
}
F_4 ( & V_77 -> V_104 ) ;
if ( V_100 )
F_44 ( V_100 ) ;
V_97 -> V_101 = V_2 ;
if ( V_2 ) {
F_2 ( & V_2 -> V_3 ) ;
F_40 ( V_2 , V_97 -> V_107 , V_97 -> V_108 - 1 ) ;
F_4 ( & V_2 -> V_3 ) ;
} else
V_97 = NULL ;
V_82:
return V_97 ;
}
static void F_45 ( struct V_93 * V_94 , void * V_109 )
{
}
static void * F_46 ( struct V_93 * V_94 , void * V_109 , T_5 * V_95 )
{
return NULL ;
}
static int F_47 ( struct V_93 * V_110 , void * V_109 )
{
struct V_96 * V_97 = (struct V_96 * ) V_109 ;
F_48 ( V_110 , L_41 , V_97 -> V_107 ) ;
return 0 ;
}
static int F_49 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_76 * V_77 = V_69 -> V_81 ;
struct V_96 * V_97 ;
void * V_24 ;
V_24 = F_50 ( V_68 , V_111 ) ;
if ( ! V_24 )
goto V_82;
V_97 = F_51 ( V_70 , & V_112 , sizeof( * V_97 ) ) ;
if ( ! V_97 )
goto V_113;
V_97 -> V_108 = V_68 ;
V_97 -> V_107 = V_24 ;
F_52 ( V_77 ) ;
V_97 -> V_99 = V_77 ;
return 0 ;
V_113:
F_53 ( V_24 ) ;
V_82:
F_54 ( - V_83 ) ;
return - V_83 ;
}
static int F_55 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_93 * V_114 = V_70 -> V_71 ;
struct V_96 * V_97 = (struct V_96 * ) V_114 -> V_98 ;
if ( V_97 -> V_101 )
F_44 ( V_97 -> V_101 ) ;
F_56 ( V_97 -> V_99 ) ;
F_53 ( V_97 -> V_107 ) ;
return F_57 ( V_69 , V_70 ) ;
}
static int F_58 ( struct V_76 * V_77 , char * V_24 , int V_28 )
{
int V_46 = 0 ;
struct V_115 * V_12 ;
char * V_30 ;
int V_116 = 0 , V_117 = 0 ;
int V_50 ;
F_2 ( & V_77 -> V_3 ) ;
switch ( V_77 -> V_118 ) {
case V_119 :
V_30 = L_42 ; break;
case V_120 :
V_30 = L_43 ; break;
case V_121 :
V_30 = L_44 ; break;
case V_122 :
V_30 = L_45 ; break;
default:
V_30 = L_46 ; break;
}
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_47 ,
V_77 -> V_27 , V_77 -> V_123 , V_77 -> V_124 . V_125 ,
V_77 -> V_124 . V_126 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_48 ,
F_59 ( V_77 -> V_127 ) , V_77 -> V_128 , V_30 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_49 ,
V_77 -> V_129 , V_77 -> V_130 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_50 ) ;
V_46 += F_21 ( V_77 -> V_131 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_51 ) ;
V_46 += F_21 ( V_77 -> V_132 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_52 ) ;
V_46 += F_21 ( V_77 -> V_133 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_53 ,
F_13 ( & V_77 -> V_134 ) ,
F_13 ( & V_77 -> V_135 ) ) ;
for ( V_50 = 0 ; V_50 < V_136 ; ++ V_50 )
V_117 += F_13 ( & V_77 -> V_137 [ V_50 ] ) ;
for ( V_50 = 0 ; V_50 < V_136 ; ++ V_50 )
V_116 += F_13 ( & V_77 -> V_138 [ V_50 ] ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_54 , V_116 , V_117 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_55 ,
F_13 ( & V_77 -> V_138 [ V_54 ] ) ,
F_13 ( & V_77 -> V_137 [ V_54 ] ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_56 ,
F_13 ( & V_77 -> V_138 [ V_55 ] ) ,
F_13 ( & V_77 -> V_137 [ V_55 ] ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_57 ,
F_13 ( & V_77 -> V_138 [ V_139 ] ) ,
F_13 ( & V_77 -> V_137 [ V_139 ] ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_58
L_59 ,
( F_14 ( & V_77 -> V_140 ) ? L_60 : L_61 ) ,
( F_14 ( & V_77 -> V_141 ) ? L_60 : L_61 ) ,
( F_14 ( & V_77 -> V_142 ) ? L_60 : L_61 ) ,
( F_14 ( & V_77 -> V_143 ) ? L_60 : L_61 ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_62 , V_77 -> V_144 ,
F_13 ( & V_77 -> V_145 . V_15 ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_63 , V_77 -> V_146 . V_147 ) ;
if ( V_77 -> V_146 . V_30 == V_148 )
V_30 = L_64 ;
else
V_30 = L_65 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_66 ,
F_59 ( V_77 -> V_149 ) ,
V_77 -> V_146 . V_59 , V_30 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_67 ) ;
V_46 += F_21 ( V_77 -> V_150 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_68 ) ;
F_16 (node, &dlm->reco.node_data, list) {
switch ( V_12 -> V_30 ) {
case V_151 :
V_30 = L_69 ;
break;
case V_152 :
V_30 = L_70 ;
break;
case V_153 :
V_30 = L_71 ;
break;
case V_154 :
V_30 = L_72 ;
break;
case V_155 :
V_30 = L_73 ;
break;
case V_156 :
V_30 = L_74 ;
break;
case V_157 :
V_30 = L_75 ;
break;
default:
V_30 = L_76 ;
break;
}
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_77 ,
V_12 -> V_128 , V_30 ) ;
}
F_4 ( & V_77 -> V_3 ) ;
return V_46 ;
}
static int F_60 ( struct V_69 * V_69 , struct V_70 * V_70 )
{
struct V_76 * V_77 = V_69 -> V_81 ;
char * V_24 = NULL ;
V_24 = ( char * ) F_24 ( V_67 ) ;
if ( ! V_24 )
goto V_82;
F_32 ( V_69 , F_58 ( V_77 , V_24 , V_68 - 1 ) ) ;
V_70 -> V_71 = V_24 ;
return 0 ;
V_82:
return - V_83 ;
}
int F_61 ( struct V_76 * V_77 )
{
struct V_158 * V_159 = V_77 -> V_158 ;
V_159 -> V_160 = F_62 ( V_161 ,
V_162 | V_163 ,
V_77 -> V_164 ,
V_77 , & V_165 ) ;
if ( ! V_159 -> V_160 ) {
F_54 ( - V_83 ) ;
goto V_82;
}
V_159 -> V_166 =
F_62 ( V_167 ,
V_162 | V_163 ,
V_77 -> V_164 ,
V_77 , & V_168 ) ;
if ( ! V_159 -> V_166 ) {
F_54 ( - V_83 ) ;
goto V_82;
}
V_159 -> V_169 = F_62 ( V_170 ,
V_162 | V_163 ,
V_77 -> V_164 ,
V_77 , & V_171 ) ;
if ( ! V_159 -> V_169 ) {
F_54 ( - V_83 ) ;
goto V_82;
}
V_159 -> V_172 =
F_62 ( V_173 ,
V_162 | V_163 ,
V_77 -> V_164 ,
V_77 , & V_174 ) ;
if ( ! V_159 -> V_172 ) {
F_54 ( - V_83 ) ;
goto V_82;
}
return 0 ;
V_82:
return - V_83 ;
}
void F_63 ( struct V_76 * V_77 )
{
struct V_158 * V_159 = V_77 -> V_158 ;
if ( V_159 ) {
F_64 ( V_159 -> V_172 ) ;
F_64 ( V_159 -> V_169 ) ;
F_64 ( V_159 -> V_166 ) ;
F_64 ( V_159 -> V_160 ) ;
F_53 ( V_159 ) ;
V_159 = NULL ;
}
}
int F_65 ( struct V_76 * V_77 )
{
V_77 -> V_164 = F_66 ( V_77 -> V_27 ,
V_175 ) ;
if ( ! V_77 -> V_164 ) {
F_54 ( - V_83 ) ;
goto V_82;
}
V_77 -> V_158 = F_67 ( sizeof( struct V_158 ) ,
V_111 ) ;
if ( ! V_77 -> V_158 ) {
F_54 ( - V_83 ) ;
goto V_82;
}
return 0 ;
V_82:
F_68 ( V_77 ) ;
return - V_83 ;
}
void F_68 ( struct V_76 * V_77 )
{
F_64 ( V_77 -> V_164 ) ;
}
int F_69 ( void )
{
V_175 = F_66 ( V_176 , NULL ) ;
if ( ! V_175 ) {
F_54 ( - V_83 ) ;
return - V_83 ;
}
return 0 ;
}
void F_70 ( void )
{
F_64 ( V_175 ) ;
}
