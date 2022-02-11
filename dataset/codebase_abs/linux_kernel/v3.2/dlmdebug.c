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
struct V_24 * V_25 ;
struct V_8 * V_9 ;
char V_26 [ V_27 ] ;
F_6 ( & V_2 -> V_3 ) ;
F_15 ( V_2 -> V_28 . V_29 , V_2 -> V_28 . V_30 ,
V_26 , sizeof( V_26 ) ) ;
F_7 ( L_7 ,
V_26 , V_2 -> V_31 , V_2 -> V_32 ) ;
F_7 ( L_8 ,
V_2 -> V_33 , F_13 ( & V_2 -> V_34 . V_15 ) ,
F_14 ( & V_2 -> V_35 ) ? L_9 : L_10 ) ;
F_7 ( L_11
L_12 ,
F_14 ( & V_2 -> V_36 ) ? L_9 : L_10 ,
F_14 ( & V_2 -> V_37 ) ? L_9 : L_10 ,
V_2 -> V_38 ? L_10 : L_9 ) ;
F_7 ( L_13 ,
V_2 -> V_7 , F_13 ( & V_2 -> V_39 ) ) ;
F_5 ( V_2 ) ;
F_7 ( L_14 ) ;
F_16 (iter2, &res->granted) {
V_9 = F_17 ( V_25 , struct V_8 , V_40 ) ;
F_9 ( V_9 ) ;
}
F_7 ( L_15 ) ;
F_16 (iter2, &res->converting) {
V_9 = F_17 ( V_25 , struct V_8 , V_40 ) ;
F_9 ( V_9 ) ;
}
F_7 ( L_16 ) ;
F_16 (iter2, &res->blocked) {
V_9 = F_17 ( V_25 , struct V_8 , V_40 ) ;
F_9 ( V_9 ) ;
}
}
void F_18 ( struct V_8 * V_41 )
{
F_1 ( V_41 -> V_42 ) ;
}
const char * F_19 ( enum V_43 V_44 )
{
if ( V_44 >= V_45 || V_44 < 0 )
return V_46 [ V_45 ] ;
return V_46 [ V_44 ] ;
}
const char * F_20 ( enum V_43 V_44 )
{
if ( V_44 >= V_45 || V_44 < 0 )
return V_47 [ V_45 ] ;
return V_47 [ V_44 ] ;
}
static int F_15 ( const char * V_28 , int V_48 , char * V_26 ,
int V_30 )
{
int V_49 = 0 ;
T_1 V_50 ;
#define F_21 18
if ( * V_28 == 'N' ) {
memcpy ( ( T_1 * ) & V_50 ,
( char * ) & V_28 [ F_21 ] ,
sizeof( T_1 ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_17 ,
F_21 - 1 , V_28 ,
( unsigned int ) F_11 ( V_50 ) ) ;
} else
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_18 ,
V_48 , V_28 ) ;
return V_49 ;
}
static int F_22 ( unsigned long * V_51 , int V_52 ,
char * V_26 , int V_30 )
{
int V_49 = 0 ;
int V_53 = - 1 ;
while ( ( V_53 = F_8 ( V_51 , V_52 , V_53 + 1 ) ) < V_52 )
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_19 , V_53 ) ;
return V_49 ;
}
static int F_23 ( struct V_54 * V_55 , char * V_26 , int V_30 )
{
int V_49 = 0 ;
char * V_56 ;
if ( V_55 -> type == V_57 )
V_56 = L_20 ;
else if ( V_55 -> type == V_58 )
V_56 = L_21 ;
else
V_56 = L_22 ;
V_49 += F_15 ( V_55 -> V_59 , V_55 -> V_60 , V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_23 ,
V_56 , V_55 -> V_61 , V_55 -> V_62 ,
! F_14 ( & V_55 -> V_63 ) ,
! ! V_55 -> V_64 ,
F_13 ( & V_55 -> V_65 . V_15 ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_24 ) ;
V_49 += F_22 ( V_55 -> V_66 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_26 ) ;
V_49 += F_22 ( V_55 -> V_67 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_27 ) ;
V_49 += F_22 ( V_55 -> V_68 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_28 ) ;
V_49 += F_22 ( V_55 -> V_69 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
return V_49 ;
}
void F_24 ( struct V_54 * V_55 )
{
char * V_26 ;
V_26 = ( char * ) F_25 ( V_70 ) ;
if ( V_26 ) {
F_23 ( V_55 , V_26 , V_71 - 1 ) ;
F_26 ( ( unsigned long ) V_26 ) ;
}
}
static void F_27 ( struct V_72 * V_72 )
{
struct V_73 * V_74 ;
V_74 = F_28 ( V_72 , struct V_73 , V_75 ) ;
F_29 ( V_74 ) ;
}
static void F_30 ( struct V_73 * V_74 )
{
if ( V_74 )
F_31 ( & V_74 -> V_75 , F_27 ) ;
}
static void F_32 ( struct V_73 * V_74 )
{
F_33 ( & V_74 -> V_75 ) ;
}
static int F_34 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
F_26 ( ( unsigned long ) V_77 -> V_78 ) ;
return 0 ;
}
static T_2 F_35 ( struct V_77 * V_77 , char T_3 * V_26 ,
T_4 V_79 , T_5 * V_80 )
{
return F_36 ( V_26 , V_79 , V_80 , V_77 -> V_78 ,
F_37 ( V_77 -> V_81 -> V_82 ) ) ;
}
static int F_38 ( struct V_83 * V_84 , char * V_26 , int V_30 )
{
struct V_1 * V_2 ;
int V_49 = 0 ;
unsigned long V_85 = 0 ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_29 , V_84 -> V_29 ) ;
F_2 ( & V_84 -> V_3 ) ;
F_39 (res, &dlm->purge_list, purge) {
++ V_85 ;
if ( V_30 - V_49 < 100 )
continue;
F_2 ( & V_2 -> V_3 ) ;
V_49 += F_15 ( V_2 -> V_28 . V_29 ,
V_2 -> V_28 . V_30 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_30 ,
( V_86 - V_2 -> V_33 ) / V_87 ) ;
F_4 ( & V_2 -> V_3 ) ;
}
F_4 ( & V_84 -> V_3 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_31 , V_85 ) ;
return V_49 ;
}
static int F_40 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
struct V_83 * V_84 = V_76 -> V_88 ;
char * V_26 = NULL ;
V_26 = ( char * ) F_25 ( V_70 ) ;
if ( ! V_26 )
goto V_89;
F_41 ( V_76 , F_38 ( V_84 , V_26 , V_71 - 1 ) ) ;
V_77 -> V_78 = V_26 ;
return 0 ;
V_89:
return - V_90 ;
}
static int F_42 ( struct V_83 * V_84 , char * V_26 , int V_30 )
{
struct V_54 * V_55 ;
struct V_91 * V_92 ;
struct V_93 * V_40 ;
int V_53 , V_49 = 0 ;
unsigned long V_85 = 0 , V_94 = 0 , V_95 = 0 ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_32 , V_84 -> V_29 ) ;
F_2 ( & V_84 -> V_96 ) ;
for ( V_53 = 0 ; V_53 < V_97 ; V_53 ++ ) {
V_92 = F_43 ( V_84 , V_53 ) ;
F_44 (list, bucket) {
V_55 = F_45 ( V_40 , struct V_54 ,
V_98 ) ;
++ V_85 ;
++ V_95 ;
if ( V_30 - V_49 < 200 )
continue;
V_49 += F_23 ( V_55 , V_26 + V_49 , V_30 - V_49 ) ;
}
V_94 = F_46 ( V_94 , V_95 ) ;
V_95 = 0 ;
}
F_4 ( & V_84 -> V_96 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_33 , V_85 , V_94 ) ;
return V_49 ;
}
static int F_47 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
struct V_83 * V_84 = V_76 -> V_88 ;
char * V_26 = NULL ;
V_26 = ( char * ) F_25 ( V_70 ) ;
if ( ! V_26 )
goto V_89;
F_41 ( V_76 , F_42 ( V_84 , V_26 , V_71 - 1 ) ) ;
V_77 -> V_78 = V_26 ;
return 0 ;
V_89:
return - V_90 ;
}
static int F_48 ( struct V_8 * V_9 , int V_99 , char * V_26 , int V_30 )
{
int V_49 ;
#define F_49 1
F_2 ( & V_9 -> V_3 ) ;
V_49 = snprintf ( V_26 , V_30 , L_34
L_35 ,
F_49 ,
V_99 , V_9 -> V_10 . type , V_9 -> V_10 . V_11 ,
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
return V_49 ;
}
static int F_50 ( struct V_1 * V_2 , char * V_26 , int V_30 )
{
struct V_8 * V_9 ;
int V_53 ;
int V_49 = 0 ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_36 ) ;
V_49 += F_15 ( V_2 -> V_28 . V_29 , V_2 -> V_28 . V_30 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
#define F_51 1
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_37 ,
F_51 ,
V_2 -> V_31 , V_2 -> V_32 , V_2 -> V_33 ,
! F_14 ( & V_2 -> V_35 ) ,
! F_14 ( & V_2 -> V_36 ) ,
! F_14 ( & V_2 -> V_37 ) ,
V_2 -> V_7 , V_2 -> V_38 ,
F_13 ( & V_2 -> V_39 ) ,
F_13 ( & V_2 -> V_34 . V_15 ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_38 ) ;
V_49 += F_22 ( V_2 -> V_5 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_39 ) ;
for ( V_53 = 0 ; V_53 < V_100 ; V_53 ++ )
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_40 , ( unsigned char ) V_2 -> V_101 [ V_53 ] ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
F_39 (lock, &res->granted, list)
V_49 += F_48 ( V_9 , 0 , V_26 + V_49 , V_30 - V_49 ) ;
F_39 (lock, &res->converting, list)
V_49 += F_48 ( V_9 , 1 , V_26 + V_49 , V_30 - V_49 ) ;
F_39 (lock, &res->blocked, list)
V_49 += F_48 ( V_9 , 2 , V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
return V_49 ;
}
static void * F_52 ( struct V_102 * V_103 , T_5 * V_104 )
{
struct V_105 * V_106 = V_103 -> V_107 ;
struct V_83 * V_84 = V_106 -> V_108 ;
struct V_1 * V_109 = V_106 -> V_110 ;
struct V_1 * V_2 = NULL ;
struct V_24 * V_111 ;
F_2 ( & V_84 -> V_112 ) ;
if ( V_109 )
V_111 = & V_109 -> V_113 ;
else {
V_111 = & V_84 -> V_114 ;
if ( F_14 ( V_111 ) ) {
V_106 = NULL ;
F_4 ( & V_84 -> V_112 ) ;
goto V_89;
}
}
F_39 (res, track_list, tracking) {
if ( & V_2 -> V_113 == & V_84 -> V_114 )
V_2 = NULL ;
else
F_53 ( V_2 ) ;
break;
}
F_4 ( & V_84 -> V_112 ) ;
if ( V_109 )
F_54 ( V_109 ) ;
V_106 -> V_110 = V_2 ;
if ( V_2 ) {
F_2 ( & V_2 -> V_3 ) ;
F_50 ( V_2 , V_106 -> V_115 , V_106 -> V_116 - 1 ) ;
F_4 ( & V_2 -> V_3 ) ;
} else
V_106 = NULL ;
V_89:
return V_106 ;
}
static void F_55 ( struct V_102 * V_103 , void * V_117 )
{
}
static void * F_56 ( struct V_102 * V_103 , void * V_117 , T_5 * V_104 )
{
return NULL ;
}
static int F_57 ( struct V_102 * V_118 , void * V_117 )
{
struct V_105 * V_106 = (struct V_105 * ) V_117 ;
F_58 ( V_118 , L_41 , V_106 -> V_115 ) ;
return 0 ;
}
static int F_59 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
struct V_83 * V_84 = V_76 -> V_88 ;
int V_119 = - V_90 ;
struct V_102 * V_120 ;
struct V_105 * V_106 = NULL ;
V_106 = F_60 ( sizeof( struct V_105 ) , V_121 ) ;
if ( ! V_106 ) {
F_61 ( V_119 ) ;
goto V_89;
}
V_106 -> V_116 = V_71 ;
V_106 -> V_115 = F_62 ( V_106 -> V_116 , V_121 ) ;
if ( ! V_106 -> V_115 ) {
F_61 ( V_119 ) ;
goto V_89;
}
V_119 = F_63 ( V_77 , & V_122 ) ;
if ( V_119 ) {
F_61 ( V_119 ) ;
goto V_89;
}
V_120 = V_77 -> V_78 ;
V_120 -> V_107 = V_106 ;
F_64 ( V_84 ) ;
V_106 -> V_108 = V_84 ;
return 0 ;
V_89:
if ( V_106 )
F_29 ( V_106 -> V_115 ) ;
F_29 ( V_106 ) ;
return V_119 ;
}
static int F_65 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
struct V_102 * V_120 = V_77 -> V_78 ;
struct V_105 * V_106 = (struct V_105 * ) V_120 -> V_107 ;
if ( V_106 -> V_110 )
F_54 ( V_106 -> V_110 ) ;
F_66 ( V_106 -> V_108 ) ;
F_29 ( V_106 -> V_115 ) ;
return F_67 ( V_76 , V_77 ) ;
}
static int F_68 ( struct V_83 * V_84 , char * V_26 , int V_30 )
{
int V_49 = 0 ;
struct V_123 * V_12 ;
char * V_32 ;
int V_124 = 0 , V_125 = 0 ;
int V_53 ;
F_2 ( & V_84 -> V_3 ) ;
switch ( V_84 -> V_126 ) {
case V_127 :
V_32 = L_42 ; break;
case V_128 :
V_32 = L_43 ; break;
case V_129 :
V_32 = L_44 ; break;
case V_130 :
V_32 = L_45 ; break;
default:
V_32 = L_46 ; break;
}
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_47 ,
V_84 -> V_29 , V_84 -> V_131 , V_84 -> V_132 . V_133 ,
V_84 -> V_132 . V_134 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_48 ,
F_69 ( V_84 -> V_135 ) , V_84 -> V_136 , V_32 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_49 ,
V_84 -> V_137 , V_84 -> V_138 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_50 ) ;
V_49 += F_22 ( V_84 -> V_139 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_51 ) ;
V_49 += F_22 ( V_84 -> V_140 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_52 ) ;
V_49 += F_22 ( V_84 -> V_141 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_53 ,
F_13 ( & V_84 -> V_142 ) ,
F_13 ( & V_84 -> V_143 ) ) ;
for ( V_53 = 0 ; V_53 < V_144 ; ++ V_53 )
V_125 += F_13 ( & V_84 -> V_145 [ V_53 ] ) ;
for ( V_53 = 0 ; V_53 < V_144 ; ++ V_53 )
V_124 += F_13 ( & V_84 -> V_146 [ V_53 ] ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_54 , V_124 , V_125 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_55 ,
F_13 ( & V_84 -> V_146 [ V_57 ] ) ,
F_13 ( & V_84 -> V_145 [ V_57 ] ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_56 ,
F_13 ( & V_84 -> V_146 [ V_58 ] ) ,
F_13 ( & V_84 -> V_145 [ V_58 ] ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_57 ,
F_13 ( & V_84 -> V_146 [ V_147 ] ) ,
F_13 ( & V_84 -> V_145 [ V_147 ] ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_58
L_59 ,
( F_14 ( & V_84 -> V_148 ) ? L_60 : L_61 ) ,
( F_14 ( & V_84 -> V_149 ) ? L_60 : L_61 ) ,
( F_14 ( & V_84 -> V_150 ) ? L_60 : L_61 ) ,
( F_14 ( & V_84 -> V_151 ) ? L_60 : L_61 ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_62 , V_84 -> V_152 ,
F_13 ( & V_84 -> V_153 . V_15 ) ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_63 , V_84 -> V_154 . V_155 ) ;
if ( V_84 -> V_154 . V_32 == V_156 )
V_32 = L_64 ;
else
V_32 = L_65 ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 ,
L_66 ,
F_69 ( V_84 -> V_157 ) ,
V_84 -> V_154 . V_62 , V_32 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_67 ) ;
V_49 += F_22 ( V_84 -> V_158 , V_6 ,
V_26 + V_49 , V_30 - V_49 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_25 ) ;
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_68 ) ;
F_39 (node, &dlm->reco.node_data, list) {
switch ( V_12 -> V_32 ) {
case V_159 :
V_32 = L_69 ;
break;
case V_160 :
V_32 = L_70 ;
break;
case V_161 :
V_32 = L_71 ;
break;
case V_162 :
V_32 = L_72 ;
break;
case V_163 :
V_32 = L_73 ;
break;
case V_164 :
V_32 = L_74 ;
break;
case V_165 :
V_32 = L_75 ;
break;
default:
V_32 = L_76 ;
break;
}
V_49 += snprintf ( V_26 + V_49 , V_30 - V_49 , L_77 ,
V_12 -> V_136 , V_32 ) ;
}
F_4 ( & V_84 -> V_3 ) ;
return V_49 ;
}
static int F_70 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
struct V_83 * V_84 = V_76 -> V_88 ;
char * V_26 = NULL ;
V_26 = ( char * ) F_25 ( V_70 ) ;
if ( ! V_26 )
goto V_89;
F_41 ( V_76 , F_68 ( V_84 , V_26 , V_71 - 1 ) ) ;
V_77 -> V_78 = V_26 ;
return 0 ;
V_89:
return - V_90 ;
}
int F_71 ( struct V_83 * V_84 )
{
struct V_73 * V_74 = V_84 -> V_73 ;
V_74 -> V_166 = F_72 ( V_167 ,
V_168 | V_169 ,
V_84 -> V_170 ,
V_84 , & V_171 ) ;
if ( ! V_74 -> V_166 ) {
F_61 ( - V_90 ) ;
goto V_89;
}
V_74 -> V_172 =
F_72 ( V_173 ,
V_168 | V_169 ,
V_84 -> V_170 ,
V_84 , & V_174 ) ;
if ( ! V_74 -> V_172 ) {
F_61 ( - V_90 ) ;
goto V_89;
}
V_74 -> V_175 = F_72 ( V_176 ,
V_168 | V_169 ,
V_84 -> V_170 ,
V_84 , & V_177 ) ;
if ( ! V_74 -> V_175 ) {
F_61 ( - V_90 ) ;
goto V_89;
}
V_74 -> V_178 =
F_72 ( V_179 ,
V_168 | V_169 ,
V_84 -> V_170 ,
V_84 , & V_180 ) ;
if ( ! V_74 -> V_178 ) {
F_61 ( - V_90 ) ;
goto V_89;
}
F_32 ( V_74 ) ;
return 0 ;
V_89:
F_73 ( V_84 ) ;
return - V_90 ;
}
void F_73 ( struct V_83 * V_84 )
{
struct V_73 * V_74 = V_84 -> V_73 ;
if ( V_74 ) {
F_74 ( V_74 -> V_178 ) ;
F_74 ( V_74 -> V_175 ) ;
F_74 ( V_74 -> V_172 ) ;
F_74 ( V_74 -> V_166 ) ;
F_30 ( V_74 ) ;
}
}
int F_75 ( struct V_83 * V_84 )
{
V_84 -> V_170 = F_76 ( V_84 -> V_29 ,
V_181 ) ;
if ( ! V_84 -> V_170 ) {
F_61 ( - V_90 ) ;
goto V_89;
}
V_84 -> V_73 = F_60 ( sizeof( struct V_73 ) ,
V_121 ) ;
if ( ! V_84 -> V_73 ) {
F_61 ( - V_90 ) ;
goto V_89;
}
F_77 ( & V_84 -> V_73 -> V_75 ) ;
return 0 ;
V_89:
F_78 ( V_84 ) ;
return - V_90 ;
}
void F_78 ( struct V_83 * V_84 )
{
F_74 ( V_84 -> V_170 ) ;
}
int F_79 ( void )
{
V_181 = F_76 ( V_182 , NULL ) ;
if ( ! V_181 ) {
F_61 ( - V_90 ) ;
return - V_90 ;
}
return 0 ;
}
void F_80 ( void )
{
F_74 ( V_181 ) ;
}
