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
F_13 ( & V_9 -> V_14 ) ,
( F_14 ( & V_9 -> V_15 ) ? 'y' : 'n' ) ,
( V_9 -> V_16 ? 'y' : 'n' ) ,
( F_14 ( & V_9 -> V_17 ) ? 'y' : 'n' ) ,
( V_9 -> V_18 ? 'y' : 'n' ) ,
( V_9 -> V_19 ? 'y' : 'n' ) ,
( V_9 -> V_20 ? 'y' : 'n' ) ,
( V_9 -> V_21 ? 'y' : 'n' ) ,
( V_9 -> V_22 ? 'y' : 'n' ) ) ;
F_4 ( & V_9 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
char V_23 [ V_24 ] ;
F_6 ( & V_2 -> V_3 ) ;
F_15 ( V_2 -> V_25 . V_26 , V_2 -> V_25 . V_27 ,
V_23 , sizeof( V_23 ) ) ;
F_7 ( L_7 ,
V_23 , V_2 -> V_28 , V_2 -> V_29 ) ;
F_7 ( L_8 ,
V_2 -> V_30 , F_13 ( & V_2 -> V_31 ) ,
F_14 ( & V_2 -> V_32 ) ? L_9 : L_10 ) ;
F_7 ( L_11
L_12 ,
F_14 ( & V_2 -> V_33 ) ? L_9 : L_10 ,
F_14 ( & V_2 -> V_34 ) ? L_9 : L_10 ,
V_2 -> V_35 ? L_10 : L_9 ) ;
F_7 ( L_13 ,
V_2 -> V_7 , F_16 ( & V_2 -> V_36 ) ) ;
F_5 ( V_2 ) ;
F_7 ( L_14 ) ;
F_17 (lock, &res->granted, list) {
F_9 ( V_9 ) ;
}
F_7 ( L_15 ) ;
F_17 (lock, &res->converting, list) {
F_9 ( V_9 ) ;
}
F_7 ( L_16 ) ;
F_17 (lock, &res->blocked, list) {
F_9 ( V_9 ) ;
}
}
void F_18 ( struct V_8 * V_37 )
{
F_1 ( V_37 -> V_38 ) ;
}
const char * F_19 ( enum V_39 V_40 )
{
if ( V_40 >= V_41 || V_40 < 0 )
return V_42 [ V_41 ] ;
return V_42 [ V_40 ] ;
}
const char * F_20 ( enum V_39 V_40 )
{
if ( V_40 >= V_41 || V_40 < 0 )
return V_43 [ V_41 ] ;
return V_43 [ V_40 ] ;
}
static int F_15 ( const char * V_25 , int V_44 , char * V_23 ,
int V_27 )
{
int V_45 = 0 ;
T_1 V_46 ;
#define F_21 18
if ( * V_25 == 'N' ) {
memcpy ( ( T_1 * ) & V_46 ,
( char * ) & V_25 [ F_21 ] ,
sizeof( T_1 ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_17 ,
F_21 - 1 , V_25 ,
( unsigned int ) F_11 ( V_46 ) ) ;
} else
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_18 ,
V_44 , V_25 ) ;
return V_45 ;
}
static int F_22 ( unsigned long * V_47 , int V_48 ,
char * V_23 , int V_27 )
{
int V_45 = 0 ;
int V_49 = - 1 ;
while ( ( V_49 = F_8 ( V_47 , V_48 , V_49 + 1 ) ) < V_48 )
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_19 , V_49 ) ;
return V_45 ;
}
static int F_23 ( struct V_50 * V_51 , char * V_23 , int V_27 )
{
int V_45 = 0 ;
char * V_52 ;
if ( V_51 -> type == V_53 )
V_52 = L_20 ;
else if ( V_51 -> type == V_54 )
V_52 = L_21 ;
else
V_52 = L_22 ;
V_45 += F_15 ( V_51 -> V_55 , V_51 -> V_56 , V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_23 ,
V_52 , V_51 -> V_57 , V_51 -> V_58 ,
! F_14 ( & V_51 -> V_59 ) ,
! ! V_51 -> V_60 ,
F_13 ( & V_51 -> V_61 ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_24 ) ;
V_45 += F_22 ( V_51 -> V_62 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_26 ) ;
V_45 += F_22 ( V_51 -> V_63 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_27 ) ;
V_45 += F_22 ( V_51 -> V_64 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_28 ) ;
V_45 += F_22 ( V_51 -> V_65 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
return V_45 ;
}
void F_24 ( struct V_50 * V_51 )
{
char * V_23 ;
V_23 = ( char * ) F_25 ( V_66 ) ;
if ( V_23 ) {
F_23 ( V_51 , V_23 , V_67 - 1 ) ;
F_26 ( ( unsigned long ) V_23 ) ;
}
}
static int F_27 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
F_26 ( ( unsigned long ) V_69 -> V_70 ) ;
return 0 ;
}
static T_2 F_28 ( struct V_69 * V_69 , char T_3 * V_23 ,
T_4 V_71 , T_5 * V_72 )
{
return F_29 ( V_23 , V_71 , V_72 , V_69 -> V_70 ,
F_30 ( V_69 -> V_73 -> V_74 ) ) ;
}
static int F_31 ( struct V_75 * V_76 , char * V_23 , int V_27 )
{
struct V_1 * V_2 ;
int V_45 = 0 ;
unsigned long V_77 = 0 ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_29 , V_76 -> V_26 ) ;
F_2 ( & V_76 -> V_3 ) ;
F_17 (res, &dlm->purge_list, purge) {
++ V_77 ;
if ( V_27 - V_45 < 100 )
continue;
F_2 ( & V_2 -> V_3 ) ;
V_45 += F_15 ( V_2 -> V_25 . V_26 ,
V_2 -> V_25 . V_27 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_30 ,
( V_78 - V_2 -> V_30 ) / V_79 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
F_4 ( & V_76 -> V_3 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_31 , V_77 ) ;
return V_45 ;
}
static int F_32 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_75 * V_76 = V_68 -> V_80 ;
char * V_23 = NULL ;
V_23 = ( char * ) F_25 ( V_66 ) ;
if ( ! V_23 )
goto V_81;
F_33 ( V_68 , F_31 ( V_76 , V_23 , V_67 - 1 ) ) ;
V_69 -> V_70 = V_23 ;
return 0 ;
V_81:
return - V_82 ;
}
static int F_34 ( struct V_75 * V_76 , char * V_23 , int V_27 )
{
struct V_50 * V_51 ;
struct V_83 * V_84 ;
int V_49 , V_45 = 0 ;
unsigned long V_77 = 0 , V_85 = 0 , V_86 = 0 ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_32 , V_76 -> V_26 ) ;
F_2 ( & V_76 -> V_87 ) ;
for ( V_49 = 0 ; V_49 < V_88 ; V_49 ++ ) {
V_84 = F_35 ( V_76 , V_49 ) ;
F_36 (mle, bucket, master_hash_node) {
++ V_77 ;
++ V_86 ;
if ( V_27 - V_45 < 200 )
continue;
V_45 += F_23 ( V_51 , V_23 + V_45 , V_27 - V_45 ) ;
}
V_85 = F_37 ( V_85 , V_86 ) ;
V_86 = 0 ;
}
F_4 ( & V_76 -> V_87 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_33 , V_77 , V_85 ) ;
return V_45 ;
}
static int F_38 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_75 * V_76 = V_68 -> V_80 ;
char * V_23 = NULL ;
V_23 = ( char * ) F_25 ( V_66 ) ;
if ( ! V_23 )
goto V_81;
F_33 ( V_68 , F_34 ( V_76 , V_23 , V_67 - 1 ) ) ;
V_69 -> V_70 = V_23 ;
return 0 ;
V_81:
return - V_82 ;
}
static int F_39 ( struct V_8 * V_9 , int V_89 , char * V_23 , int V_27 )
{
int V_45 ;
#define F_40 1
F_2 ( & V_9 -> V_3 ) ;
V_45 = snprintf ( V_23 , V_27 , L_34
L_35 ,
F_40 ,
V_89 , V_9 -> V_10 . type , V_9 -> V_10 . V_11 ,
V_9 -> V_10 . V_12 ,
F_10 ( F_11 ( V_9 -> V_10 . V_13 ) ) ,
F_12 ( F_11 ( V_9 -> V_10 . V_13 ) ) ,
! F_14 ( & V_9 -> V_15 ) ,
! F_14 ( & V_9 -> V_17 ) ,
V_9 -> V_16 , V_9 -> V_18 ,
V_9 -> V_19 , V_9 -> V_20 ,
V_9 -> V_21 , V_9 -> V_22 ,
F_13 ( & V_9 -> V_14 ) ) ;
F_4 ( & V_9 -> V_3 ) ;
return V_45 ;
}
static int F_41 ( struct V_1 * V_2 , char * V_23 , int V_27 )
{
struct V_8 * V_9 ;
int V_49 ;
int V_45 = 0 ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_36 ) ;
V_45 += F_15 ( V_2 -> V_25 . V_26 , V_2 -> V_25 . V_27 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
#define F_42 1
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_37 ,
F_42 ,
V_2 -> V_28 , V_2 -> V_29 , V_2 -> V_30 ,
! F_14 ( & V_2 -> V_32 ) ,
! F_14 ( & V_2 -> V_33 ) ,
! F_14 ( & V_2 -> V_34 ) ,
V_2 -> V_7 , V_2 -> V_35 ,
F_16 ( & V_2 -> V_36 ) ,
F_13 ( & V_2 -> V_31 ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_38 ) ;
V_45 += F_22 ( V_2 -> V_5 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_39 ) ;
for ( V_49 = 0 ; V_49 < V_90 ; V_49 ++ )
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_40 , ( unsigned char ) V_2 -> V_91 [ V_49 ] ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
F_17 (lock, &res->granted, list)
V_45 += F_39 ( V_9 , 0 , V_23 + V_45 , V_27 - V_45 ) ;
F_17 (lock, &res->converting, list)
V_45 += F_39 ( V_9 , 1 , V_23 + V_45 , V_27 - V_45 ) ;
F_17 (lock, &res->blocked, list)
V_45 += F_39 ( V_9 , 2 , V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
return V_45 ;
}
static void * F_43 ( struct V_92 * V_93 , T_5 * V_94 )
{
struct V_95 * V_96 = V_93 -> V_97 ;
struct V_75 * V_76 = V_96 -> V_98 ;
struct V_1 * V_99 = V_96 -> V_100 ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_102 ;
F_2 ( & V_76 -> V_103 ) ;
if ( V_99 )
V_102 = & V_99 -> V_104 ;
else {
V_102 = & V_76 -> V_105 ;
if ( F_14 ( V_102 ) ) {
V_96 = NULL ;
F_4 ( & V_76 -> V_103 ) ;
goto V_81;
}
}
F_17 (res, track_list, tracking) {
if ( & V_2 -> V_104 == & V_76 -> V_105 )
V_2 = NULL ;
else
F_44 ( V_2 ) ;
break;
}
F_4 ( & V_76 -> V_103 ) ;
if ( V_99 )
F_45 ( V_99 ) ;
V_96 -> V_100 = V_2 ;
if ( V_2 ) {
F_2 ( & V_2 -> V_3 ) ;
F_41 ( V_2 , V_96 -> V_106 , V_96 -> V_107 - 1 ) ;
F_4 ( & V_2 -> V_3 ) ;
} else
V_96 = NULL ;
V_81:
return V_96 ;
}
static void F_46 ( struct V_92 * V_93 , void * V_108 )
{
}
static void * F_47 ( struct V_92 * V_93 , void * V_108 , T_5 * V_94 )
{
return NULL ;
}
static int F_48 ( struct V_92 * V_109 , void * V_108 )
{
struct V_95 * V_96 = (struct V_95 * ) V_108 ;
F_49 ( V_109 , L_41 , V_96 -> V_106 ) ;
return 0 ;
}
static int F_50 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_75 * V_76 = V_68 -> V_80 ;
struct V_95 * V_96 ;
void * V_23 ;
V_23 = F_51 ( V_67 , V_110 ) ;
if ( ! V_23 )
goto V_81;
V_96 = F_52 ( V_69 , & V_111 , sizeof( * V_96 ) ) ;
if ( ! V_96 )
goto V_112;
V_96 -> V_107 = V_67 ;
V_96 -> V_106 = V_23 ;
F_53 ( V_76 ) ;
V_96 -> V_98 = V_76 ;
return 0 ;
V_112:
F_54 ( V_23 ) ;
V_81:
F_55 ( - V_82 ) ;
return - V_82 ;
}
static int F_56 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_92 * V_113 = V_69 -> V_70 ;
struct V_95 * V_96 = (struct V_95 * ) V_113 -> V_97 ;
if ( V_96 -> V_100 )
F_45 ( V_96 -> V_100 ) ;
F_57 ( V_96 -> V_98 ) ;
F_54 ( V_96 -> V_106 ) ;
return F_58 ( V_68 , V_69 ) ;
}
static int F_59 ( struct V_75 * V_76 , char * V_23 , int V_27 )
{
int V_45 = 0 ;
struct V_114 * V_12 ;
char * V_29 ;
int V_115 = 0 , V_116 = 0 ;
int V_49 ;
F_2 ( & V_76 -> V_3 ) ;
switch ( V_76 -> V_117 ) {
case V_118 :
V_29 = L_42 ; break;
case V_119 :
V_29 = L_43 ; break;
case V_120 :
V_29 = L_44 ; break;
case V_121 :
V_29 = L_45 ; break;
default:
V_29 = L_46 ; break;
}
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_47 ,
V_76 -> V_26 , V_76 -> V_122 , V_76 -> V_123 . V_124 ,
V_76 -> V_123 . V_125 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_48 ,
F_60 ( V_76 -> V_126 ) , V_76 -> V_127 , V_29 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_49 ,
V_76 -> V_128 , V_76 -> V_129 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_50 ) ;
V_45 += F_22 ( V_76 -> V_130 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_51 ) ;
V_45 += F_22 ( V_76 -> V_131 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_52 ) ;
V_45 += F_22 ( V_76 -> V_132 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_53 ,
F_16 ( & V_76 -> V_133 ) ,
F_16 ( & V_76 -> V_134 ) ) ;
for ( V_49 = 0 ; V_49 < V_135 ; ++ V_49 )
V_116 += F_16 ( & V_76 -> V_136 [ V_49 ] ) ;
for ( V_49 = 0 ; V_49 < V_135 ; ++ V_49 )
V_115 += F_16 ( & V_76 -> V_137 [ V_49 ] ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_54 , V_115 , V_116 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_55 ,
F_16 ( & V_76 -> V_137 [ V_53 ] ) ,
F_16 ( & V_76 -> V_136 [ V_53 ] ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_56 ,
F_16 ( & V_76 -> V_137 [ V_54 ] ) ,
F_16 ( & V_76 -> V_136 [ V_54 ] ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_57 ,
F_16 ( & V_76 -> V_137 [ V_138 ] ) ,
F_16 ( & V_76 -> V_136 [ V_138 ] ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_58
L_59 ,
( F_14 ( & V_76 -> V_139 ) ? L_60 : L_61 ) ,
( F_14 ( & V_76 -> V_140 ) ? L_60 : L_61 ) ,
( F_14 ( & V_76 -> V_141 ) ? L_60 : L_61 ) ,
( F_14 ( & V_76 -> V_142 ) ? L_60 : L_61 ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_62 , V_76 -> V_143 ,
F_13 ( & V_76 -> V_144 ) ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_63 , V_76 -> V_145 . V_146 ) ;
if ( V_76 -> V_145 . V_29 == V_147 )
V_29 = L_64 ;
else
V_29 = L_65 ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 ,
L_66 ,
F_60 ( V_76 -> V_148 ) ,
V_76 -> V_145 . V_58 , V_29 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_67 ) ;
V_45 += F_22 ( V_76 -> V_149 , V_6 ,
V_23 + V_45 , V_27 - V_45 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_25 ) ;
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_68 ) ;
F_17 (node, &dlm->reco.node_data, list) {
switch ( V_12 -> V_29 ) {
case V_150 :
V_29 = L_69 ;
break;
case V_151 :
V_29 = L_70 ;
break;
case V_152 :
V_29 = L_71 ;
break;
case V_153 :
V_29 = L_72 ;
break;
case V_154 :
V_29 = L_73 ;
break;
case V_155 :
V_29 = L_74 ;
break;
case V_156 :
V_29 = L_75 ;
break;
default:
V_29 = L_76 ;
break;
}
V_45 += snprintf ( V_23 + V_45 , V_27 - V_45 , L_77 ,
V_12 -> V_127 , V_29 ) ;
}
F_4 ( & V_76 -> V_3 ) ;
return V_45 ;
}
static int F_61 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
struct V_75 * V_76 = V_68 -> V_80 ;
char * V_23 = NULL ;
V_23 = ( char * ) F_25 ( V_66 ) ;
if ( ! V_23 )
goto V_81;
F_33 ( V_68 , F_59 ( V_76 , V_23 , V_67 - 1 ) ) ;
V_69 -> V_70 = V_23 ;
return 0 ;
V_81:
return - V_82 ;
}
int F_62 ( struct V_75 * V_76 )
{
struct V_157 * V_158 = V_76 -> V_157 ;
V_158 -> V_159 = F_63 ( V_160 ,
V_161 | V_162 ,
V_76 -> V_163 ,
V_76 , & V_164 ) ;
if ( ! V_158 -> V_159 ) {
F_55 ( - V_82 ) ;
goto V_81;
}
V_158 -> V_165 =
F_63 ( V_166 ,
V_161 | V_162 ,
V_76 -> V_163 ,
V_76 , & V_167 ) ;
if ( ! V_158 -> V_165 ) {
F_55 ( - V_82 ) ;
goto V_81;
}
V_158 -> V_168 = F_63 ( V_169 ,
V_161 | V_162 ,
V_76 -> V_163 ,
V_76 , & V_170 ) ;
if ( ! V_158 -> V_168 ) {
F_55 ( - V_82 ) ;
goto V_81;
}
V_158 -> V_171 =
F_63 ( V_172 ,
V_161 | V_162 ,
V_76 -> V_163 ,
V_76 , & V_173 ) ;
if ( ! V_158 -> V_171 ) {
F_55 ( - V_82 ) ;
goto V_81;
}
return 0 ;
V_81:
return - V_82 ;
}
void F_64 ( struct V_75 * V_76 )
{
struct V_157 * V_158 = V_76 -> V_157 ;
if ( V_158 ) {
F_65 ( V_158 -> V_171 ) ;
F_65 ( V_158 -> V_168 ) ;
F_65 ( V_158 -> V_165 ) ;
F_65 ( V_158 -> V_159 ) ;
F_54 ( V_158 ) ;
V_158 = NULL ;
}
}
int F_66 ( struct V_75 * V_76 )
{
V_76 -> V_163 = F_67 ( V_76 -> V_26 ,
V_174 ) ;
if ( ! V_76 -> V_163 ) {
F_55 ( - V_82 ) ;
goto V_81;
}
V_76 -> V_157 = F_68 ( sizeof( struct V_157 ) ,
V_110 ) ;
if ( ! V_76 -> V_157 ) {
F_55 ( - V_82 ) ;
goto V_81;
}
return 0 ;
V_81:
F_69 ( V_76 ) ;
return - V_82 ;
}
void F_69 ( struct V_75 * V_76 )
{
F_65 ( V_76 -> V_163 ) ;
}
int F_70 ( void )
{
V_174 = F_67 ( V_175 , NULL ) ;
if ( ! V_174 ) {
F_55 ( - V_82 ) ;
return - V_82 ;
}
return 0 ;
}
void F_71 ( void )
{
F_65 ( V_174 ) ;
}
