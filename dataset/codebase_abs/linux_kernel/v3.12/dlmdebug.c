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
static void F_26 ( struct V_69 * V_69 )
{
struct V_70 * V_71 ;
V_71 = F_27 ( V_69 , struct V_70 , V_72 ) ;
F_28 ( V_71 ) ;
}
static void F_29 ( struct V_70 * V_71 )
{
if ( V_71 )
F_30 ( & V_71 -> V_72 , F_26 ) ;
}
static void F_31 ( struct V_70 * V_71 )
{
F_32 ( & V_71 -> V_72 ) ;
}
static int F_33 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
F_25 ( ( unsigned long ) V_74 -> V_75 ) ;
return 0 ;
}
static T_2 F_34 ( struct V_74 * V_74 , char T_3 * V_24 ,
T_4 V_76 , T_5 * V_77 )
{
return F_35 ( V_24 , V_76 , V_77 , V_74 -> V_75 ,
F_36 ( V_74 -> V_78 -> V_79 ) ) ;
}
static int F_37 ( struct V_80 * V_81 , char * V_24 , int V_28 )
{
struct V_1 * V_2 ;
int V_46 = 0 ;
unsigned long V_82 = 0 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_29 , V_81 -> V_27 ) ;
F_2 ( & V_81 -> V_3 ) ;
F_16 (res, &dlm->purge_list, purge) {
++ V_82 ;
if ( V_28 - V_46 < 100 )
continue;
F_2 ( & V_2 -> V_3 ) ;
V_46 += F_15 ( V_2 -> V_26 . V_27 ,
V_2 -> V_26 . V_28 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_30 ,
( V_83 - V_2 -> V_31 ) / V_84 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
F_4 ( & V_81 -> V_3 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_31 , V_82 ) ;
return V_46 ;
}
static int F_38 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
struct V_80 * V_81 = V_73 -> V_85 ;
char * V_24 = NULL ;
V_24 = ( char * ) F_24 ( V_67 ) ;
if ( ! V_24 )
goto V_86;
F_39 ( V_73 , F_37 ( V_81 , V_24 , V_68 - 1 ) ) ;
V_74 -> V_75 = V_24 ;
return 0 ;
V_86:
return - V_87 ;
}
static int F_40 ( struct V_80 * V_81 , char * V_24 , int V_28 )
{
struct V_51 * V_52 ;
struct V_88 * V_89 ;
int V_50 , V_46 = 0 ;
unsigned long V_82 = 0 , V_90 = 0 , V_91 = 0 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_32 , V_81 -> V_27 ) ;
F_2 ( & V_81 -> V_92 ) ;
for ( V_50 = 0 ; V_50 < V_93 ; V_50 ++ ) {
V_89 = F_41 ( V_81 , V_50 ) ;
F_42 (mle, bucket, master_hash_node) {
++ V_82 ;
++ V_91 ;
if ( V_28 - V_46 < 200 )
continue;
V_46 += F_22 ( V_52 , V_24 + V_46 , V_28 - V_46 ) ;
}
V_90 = F_43 ( V_90 , V_91 ) ;
V_91 = 0 ;
}
F_4 ( & V_81 -> V_92 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_33 , V_82 , V_90 ) ;
return V_46 ;
}
static int F_44 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
struct V_80 * V_81 = V_73 -> V_85 ;
char * V_24 = NULL ;
V_24 = ( char * ) F_24 ( V_67 ) ;
if ( ! V_24 )
goto V_86;
F_39 ( V_73 , F_40 ( V_81 , V_24 , V_68 - 1 ) ) ;
V_74 -> V_75 = V_24 ;
return 0 ;
V_86:
return - V_87 ;
}
static int F_45 ( struct V_8 * V_9 , int V_94 , char * V_24 , int V_28 )
{
int V_46 ;
#define F_46 1
F_2 ( & V_9 -> V_3 ) ;
V_46 = snprintf ( V_24 , V_28 , L_34
L_35 ,
F_46 ,
V_94 , V_9 -> V_10 . type , V_9 -> V_10 . V_11 ,
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
static int F_47 ( struct V_1 * V_2 , char * V_24 , int V_28 )
{
struct V_8 * V_9 ;
int V_50 ;
int V_46 = 0 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_36 ) ;
V_46 += F_15 ( V_2 -> V_26 . V_27 , V_2 -> V_26 . V_28 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
#define F_48 1
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_37 ,
F_48 ,
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
for ( V_50 = 0 ; V_50 < V_95 ; V_50 ++ )
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_40 , ( unsigned char ) V_2 -> V_96 [ V_50 ] ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
F_16 (lock, &res->granted, list)
V_46 += F_45 ( V_9 , 0 , V_24 + V_46 , V_28 - V_46 ) ;
F_16 (lock, &res->converting, list)
V_46 += F_45 ( V_9 , 1 , V_24 + V_46 , V_28 - V_46 ) ;
F_16 (lock, &res->blocked, list)
V_46 += F_45 ( V_9 , 2 , V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
return V_46 ;
}
static void * F_49 ( struct V_97 * V_98 , T_5 * V_99 )
{
struct V_100 * V_101 = V_98 -> V_102 ;
struct V_80 * V_81 = V_101 -> V_103 ;
struct V_1 * V_104 = V_101 -> V_105 ;
struct V_1 * V_2 = NULL ;
struct V_106 * V_107 ;
F_2 ( & V_81 -> V_108 ) ;
if ( V_104 )
V_107 = & V_104 -> V_109 ;
else {
V_107 = & V_81 -> V_110 ;
if ( F_14 ( V_107 ) ) {
V_101 = NULL ;
F_4 ( & V_81 -> V_108 ) ;
goto V_86;
}
}
F_16 (res, track_list, tracking) {
if ( & V_2 -> V_109 == & V_81 -> V_110 )
V_2 = NULL ;
else
F_50 ( V_2 ) ;
break;
}
F_4 ( & V_81 -> V_108 ) ;
if ( V_104 )
F_51 ( V_104 ) ;
V_101 -> V_105 = V_2 ;
if ( V_2 ) {
F_2 ( & V_2 -> V_3 ) ;
F_47 ( V_2 , V_101 -> V_111 , V_101 -> V_112 - 1 ) ;
F_4 ( & V_2 -> V_3 ) ;
} else
V_101 = NULL ;
V_86:
return V_101 ;
}
static void F_52 ( struct V_97 * V_98 , void * V_113 )
{
}
static void * F_53 ( struct V_97 * V_98 , void * V_113 , T_5 * V_99 )
{
return NULL ;
}
static int F_54 ( struct V_97 * V_114 , void * V_113 )
{
struct V_100 * V_101 = (struct V_100 * ) V_113 ;
F_55 ( V_114 , L_41 , V_101 -> V_111 ) ;
return 0 ;
}
static int F_56 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
struct V_80 * V_81 = V_73 -> V_85 ;
int V_115 = - V_87 ;
struct V_97 * V_116 ;
struct V_100 * V_101 = NULL ;
V_101 = F_57 ( sizeof( struct V_100 ) , V_117 ) ;
if ( ! V_101 ) {
F_58 ( V_115 ) ;
goto V_86;
}
V_101 -> V_112 = V_68 ;
V_101 -> V_111 = F_59 ( V_101 -> V_112 , V_117 ) ;
if ( ! V_101 -> V_111 ) {
F_58 ( V_115 ) ;
goto V_86;
}
V_115 = F_60 ( V_74 , & V_118 ) ;
if ( V_115 ) {
F_58 ( V_115 ) ;
goto V_86;
}
V_116 = V_74 -> V_75 ;
V_116 -> V_102 = V_101 ;
F_61 ( V_81 ) ;
V_101 -> V_103 = V_81 ;
return 0 ;
V_86:
if ( V_101 )
F_28 ( V_101 -> V_111 ) ;
F_28 ( V_101 ) ;
return V_115 ;
}
static int F_62 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
struct V_97 * V_116 = V_74 -> V_75 ;
struct V_100 * V_101 = (struct V_100 * ) V_116 -> V_102 ;
if ( V_101 -> V_105 )
F_51 ( V_101 -> V_105 ) ;
F_63 ( V_101 -> V_103 ) ;
F_28 ( V_101 -> V_111 ) ;
return F_64 ( V_73 , V_74 ) ;
}
static int F_65 ( struct V_80 * V_81 , char * V_24 , int V_28 )
{
int V_46 = 0 ;
struct V_119 * V_12 ;
char * V_30 ;
int V_120 = 0 , V_121 = 0 ;
int V_50 ;
F_2 ( & V_81 -> V_3 ) ;
switch ( V_81 -> V_122 ) {
case V_123 :
V_30 = L_42 ; break;
case V_124 :
V_30 = L_43 ; break;
case V_125 :
V_30 = L_44 ; break;
case V_126 :
V_30 = L_45 ; break;
default:
V_30 = L_46 ; break;
}
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_47 ,
V_81 -> V_27 , V_81 -> V_127 , V_81 -> V_128 . V_129 ,
V_81 -> V_128 . V_130 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_48 ,
F_66 ( V_81 -> V_131 ) , V_81 -> V_132 , V_30 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_49 ,
V_81 -> V_133 , V_81 -> V_134 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_50 ) ;
V_46 += F_21 ( V_81 -> V_135 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_51 ) ;
V_46 += F_21 ( V_81 -> V_136 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_52 ) ;
V_46 += F_21 ( V_81 -> V_137 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_53 ,
F_13 ( & V_81 -> V_138 ) ,
F_13 ( & V_81 -> V_139 ) ) ;
for ( V_50 = 0 ; V_50 < V_140 ; ++ V_50 )
V_121 += F_13 ( & V_81 -> V_141 [ V_50 ] ) ;
for ( V_50 = 0 ; V_50 < V_140 ; ++ V_50 )
V_120 += F_13 ( & V_81 -> V_142 [ V_50 ] ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_54 , V_120 , V_121 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_55 ,
F_13 ( & V_81 -> V_142 [ V_54 ] ) ,
F_13 ( & V_81 -> V_141 [ V_54 ] ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_56 ,
F_13 ( & V_81 -> V_142 [ V_55 ] ) ,
F_13 ( & V_81 -> V_141 [ V_55 ] ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_57 ,
F_13 ( & V_81 -> V_142 [ V_143 ] ) ,
F_13 ( & V_81 -> V_141 [ V_143 ] ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_58
L_59 ,
( F_14 ( & V_81 -> V_144 ) ? L_60 : L_61 ) ,
( F_14 ( & V_81 -> V_145 ) ? L_60 : L_61 ) ,
( F_14 ( & V_81 -> V_146 ) ? L_60 : L_61 ) ,
( F_14 ( & V_81 -> V_147 ) ? L_60 : L_61 ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_62 , V_81 -> V_148 ,
F_13 ( & V_81 -> V_149 . V_15 ) ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_63 , V_81 -> V_150 . V_151 ) ;
if ( V_81 -> V_150 . V_30 == V_152 )
V_30 = L_64 ;
else
V_30 = L_65 ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 ,
L_66 ,
F_66 ( V_81 -> V_153 ) ,
V_81 -> V_150 . V_59 , V_30 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_67 ) ;
V_46 += F_21 ( V_81 -> V_154 , V_6 ,
V_24 + V_46 , V_28 - V_46 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_25 ) ;
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_68 ) ;
F_16 (node, &dlm->reco.node_data, list) {
switch ( V_12 -> V_30 ) {
case V_155 :
V_30 = L_69 ;
break;
case V_156 :
V_30 = L_70 ;
break;
case V_157 :
V_30 = L_71 ;
break;
case V_158 :
V_30 = L_72 ;
break;
case V_159 :
V_30 = L_73 ;
break;
case V_160 :
V_30 = L_74 ;
break;
case V_161 :
V_30 = L_75 ;
break;
default:
V_30 = L_76 ;
break;
}
V_46 += snprintf ( V_24 + V_46 , V_28 - V_46 , L_77 ,
V_12 -> V_132 , V_30 ) ;
}
F_4 ( & V_81 -> V_3 ) ;
return V_46 ;
}
static int F_67 ( struct V_73 * V_73 , struct V_74 * V_74 )
{
struct V_80 * V_81 = V_73 -> V_85 ;
char * V_24 = NULL ;
V_24 = ( char * ) F_24 ( V_67 ) ;
if ( ! V_24 )
goto V_86;
F_39 ( V_73 , F_65 ( V_81 , V_24 , V_68 - 1 ) ) ;
V_74 -> V_75 = V_24 ;
return 0 ;
V_86:
return - V_87 ;
}
int F_68 ( struct V_80 * V_81 )
{
struct V_70 * V_71 = V_81 -> V_70 ;
V_71 -> V_162 = F_69 ( V_163 ,
V_164 | V_165 ,
V_81 -> V_166 ,
V_81 , & V_167 ) ;
if ( ! V_71 -> V_162 ) {
F_58 ( - V_87 ) ;
goto V_86;
}
V_71 -> V_168 =
F_69 ( V_169 ,
V_164 | V_165 ,
V_81 -> V_166 ,
V_81 , & V_170 ) ;
if ( ! V_71 -> V_168 ) {
F_58 ( - V_87 ) ;
goto V_86;
}
V_71 -> V_171 = F_69 ( V_172 ,
V_164 | V_165 ,
V_81 -> V_166 ,
V_81 , & V_173 ) ;
if ( ! V_71 -> V_171 ) {
F_58 ( - V_87 ) ;
goto V_86;
}
V_71 -> V_174 =
F_69 ( V_175 ,
V_164 | V_165 ,
V_81 -> V_166 ,
V_81 , & V_176 ) ;
if ( ! V_71 -> V_174 ) {
F_58 ( - V_87 ) ;
goto V_86;
}
F_31 ( V_71 ) ;
return 0 ;
V_86:
F_70 ( V_81 ) ;
return - V_87 ;
}
void F_70 ( struct V_80 * V_81 )
{
struct V_70 * V_71 = V_81 -> V_70 ;
if ( V_71 ) {
F_71 ( V_71 -> V_174 ) ;
F_71 ( V_71 -> V_171 ) ;
F_71 ( V_71 -> V_168 ) ;
F_71 ( V_71 -> V_162 ) ;
F_29 ( V_71 ) ;
}
}
int F_72 ( struct V_80 * V_81 )
{
V_81 -> V_166 = F_73 ( V_81 -> V_27 ,
V_177 ) ;
if ( ! V_81 -> V_166 ) {
F_58 ( - V_87 ) ;
goto V_86;
}
V_81 -> V_70 = F_57 ( sizeof( struct V_70 ) ,
V_117 ) ;
if ( ! V_81 -> V_70 ) {
F_58 ( - V_87 ) ;
goto V_86;
}
F_74 ( & V_81 -> V_70 -> V_72 ) ;
return 0 ;
V_86:
F_75 ( V_81 ) ;
return - V_87 ;
}
void F_75 ( struct V_80 * V_81 )
{
F_71 ( V_81 -> V_166 ) ;
}
int F_76 ( void )
{
V_177 = F_73 ( V_178 , NULL ) ;
if ( ! V_177 ) {
F_58 ( - V_87 ) ;
return - V_87 ;
}
return 0 ;
}
void F_77 ( void )
{
F_71 ( V_177 ) ;
}
