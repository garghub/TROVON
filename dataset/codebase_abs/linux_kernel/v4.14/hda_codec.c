static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_8 ) ;
struct V_9 * V_10 = V_7 -> V_10 ;
int V_11 ;
if ( V_3 == ~ 0 )
return - 1 ;
V_12:
F_3 ( V_7 ) ;
F_4 ( & V_10 -> V_8 . V_13 ) ;
if ( V_4 & V_14 )
V_10 -> V_15 = 1 ;
V_11 = F_5 ( & V_10 -> V_8 , V_7 -> V_8 . V_16 ,
V_3 , V_5 ) ;
V_10 -> V_15 = 0 ;
F_6 ( & V_10 -> V_8 . V_13 ) ;
F_7 ( V_7 ) ;
if ( ! F_8 ( V_7 ) && V_5 && V_11 == - V_17 ) {
if ( V_10 -> V_18 ) {
F_9 ( V_7 ,
L_1 ) ;
F_10 ( V_10 ) ;
}
goto V_12;
}
if ( ! V_11 || F_8 ( V_7 ) )
V_10 -> V_18 = 0 ;
return V_11 ;
}
void F_11 ( struct V_6 * V_7 , const struct V_19 * V_20 )
{
for (; V_20 -> V_21 ; V_20 ++ )
F_12 ( V_7 , V_20 -> V_21 , 0 , V_20 -> V_22 , V_20 -> V_23 ) ;
}
static struct V_24 *
F_13 ( struct V_6 * V_7 , T_1 V_21 )
{
struct V_24 * V_25 ;
F_14 (p, &codec->conn_list, list) {
if ( V_25 -> V_21 == V_21 )
return V_25 ;
}
return NULL ;
}
static int F_15 ( struct V_6 * V_7 , T_1 V_21 , int V_26 ,
const T_1 * V_27 )
{
struct V_24 * V_25 ;
V_25 = F_16 ( sizeof( * V_25 ) + V_26 * sizeof( T_1 ) , V_28 ) ;
if ( ! V_25 )
return - V_29 ;
V_25 -> V_26 = V_26 ;
V_25 -> V_21 = V_21 ;
memcpy ( V_25 -> V_30 , V_27 , V_26 * sizeof( T_1 ) ) ;
F_17 ( & V_25 -> V_27 , & V_7 -> V_31 ) ;
return 0 ;
}
static void F_18 ( struct V_6 * V_7 )
{
while ( ! F_19 ( & V_7 -> V_31 ) ) {
struct V_24 * V_25 ;
V_25 = F_20 ( & V_7 -> V_31 , F_21 ( * V_25 ) , V_27 ) ;
F_22 ( & V_25 -> V_27 ) ;
F_23 ( V_25 ) ;
}
}
static int F_24 ( struct V_6 * V_7 , T_1 V_21 )
{
T_1 V_27 [ 32 ] ;
T_1 * V_32 = V_27 ;
int V_26 ;
V_26 = F_25 ( V_7 , V_21 , V_27 , F_26 ( V_27 ) ) ;
if ( V_26 == - V_33 ) {
V_26 = F_27 ( V_7 , V_21 ) ;
V_32 = F_16 ( sizeof( T_1 ) * V_26 , V_28 ) ;
if ( ! V_32 )
return - V_29 ;
V_26 = F_25 ( V_7 , V_21 , V_32 , V_26 ) ;
}
if ( V_26 >= 0 )
V_26 = F_28 ( V_7 , V_21 , V_26 , V_32 ) ;
if ( V_32 != V_27 )
F_23 ( V_32 ) ;
return V_26 ;
}
int F_29 ( struct V_6 * V_7 , T_1 V_21 ,
const T_1 * * V_34 )
{
bool V_35 = false ;
for (; ; ) {
int V_11 ;
const struct V_24 * V_25 ;
V_25 = F_13 ( V_7 , V_21 ) ;
if ( V_25 ) {
if ( V_34 )
* V_34 = V_25 -> V_30 ;
return V_25 -> V_26 ;
}
if ( F_30 ( V_35 ) )
return - V_36 ;
V_11 = F_24 ( V_7 , V_21 ) ;
if ( V_11 < 0 )
return V_11 ;
V_35 = true ;
}
}
int F_31 ( struct V_6 * V_7 , T_1 V_21 ,
T_1 * V_31 , int V_37 )
{
const T_1 * V_27 ;
int V_26 = F_29 ( V_7 , V_21 , & V_27 ) ;
if ( V_26 > 0 && V_31 ) {
if ( V_26 > V_37 ) {
F_32 ( V_7 , L_2 ,
V_26 , V_21 ) ;
return - V_36 ;
}
memcpy ( V_31 , V_27 , V_26 * sizeof( T_1 ) ) ;
}
return V_26 ;
}
int F_28 ( struct V_6 * V_7 , T_1 V_21 , int V_26 ,
const T_1 * V_27 )
{
struct V_24 * V_25 ;
V_25 = F_13 ( V_7 , V_21 ) ;
if ( V_25 ) {
F_22 ( & V_25 -> V_27 ) ;
F_23 ( V_25 ) ;
}
return F_15 ( V_7 , V_21 , V_26 , V_27 ) ;
}
int F_33 ( struct V_6 * V_7 , T_1 V_38 ,
T_1 V_21 , int V_39 )
{
const T_1 * V_40 ;
int V_41 , V_42 ;
V_42 = F_29 ( V_7 , V_38 , & V_40 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
if ( V_40 [ V_41 ] == V_21 )
return V_41 ;
if ( ! V_39 )
return - 1 ;
if ( V_39 > 10 ) {
F_9 ( V_7 , L_3 , V_21 ) ;
return - 1 ;
}
V_39 ++ ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
unsigned int type = F_34 ( F_35 ( V_7 , V_40 [ V_41 ] ) ) ;
if ( type == V_43 || type == V_44 )
continue;
if ( F_33 ( V_7 , V_40 [ V_41 ] , V_21 , V_39 ) >= 0 )
return V_41 ;
}
return - 1 ;
}
unsigned int F_36 ( struct V_6 * V_7 , T_1 V_21 )
{
unsigned int V_45 = F_35 ( V_7 , V_21 ) ;
unsigned int V_46 ;
if ( ! V_7 -> V_47 || ! ( V_45 & V_48 ) ||
F_34 ( V_45 ) != V_43 )
return 0 ;
V_46 = F_37 ( & V_7 -> V_8 , V_21 , V_49 ) ;
if ( V_46 == - 1 )
V_46 = 0 ;
return V_46 & V_50 ;
}
int F_38 ( struct V_6 * V_7 , T_1 V_21 ,
T_2 * V_51 , int V_52 )
{
unsigned int V_46 ;
int V_41 , V_53 , V_54 ;
V_46 = F_36 ( V_7 , V_21 ) ;
if ( ! V_46 )
return 0 ;
V_53 = V_46 + 1 ;
V_53 = V_53 < V_52 ? V_53 : V_52 ;
V_54 = 0 ;
while ( V_54 < V_53 ) {
if ( F_39 ( & V_7 -> V_8 , V_21 ,
V_55 , V_54 , & V_46 ) )
break;
for ( V_41 = 0 ; V_41 < 8 ; V_41 ++ ) {
V_51 [ V_54 ] = ( T_2 ) V_46 ;
V_46 >>= 4 ;
V_54 ++ ;
if ( V_54 >= V_53 )
break;
}
}
return V_54 ;
}
int F_40 ( struct V_6 * V_7 , T_1 V_21 )
{
if ( ! V_7 -> V_47 )
return 0 ;
return F_41 ( V_7 , V_21 , 0 , V_56 , 0 ) ;
}
int F_42 ( struct V_6 * V_7 , T_1 V_21 , int V_57 )
{
int V_58 , V_59 ;
if ( ! V_7 -> V_47 )
return 0 ;
V_59 = F_36 ( V_7 , V_21 ) + 1 ;
if ( V_59 == 1 )
return 0 ;
if ( V_59 <= V_57 )
return - V_36 ;
V_58 = F_12 ( V_7 , V_21 , 0 ,
V_60 , V_57 ) ;
return V_58 ;
}
static int F_43 ( struct V_6 * V_7 , T_1 V_61 )
{
int V_41 ;
T_1 V_21 ;
V_7 -> V_45 = F_16 ( V_7 -> V_8 . V_62 * 4 , V_28 ) ;
if ( ! V_7 -> V_45 )
return - V_29 ;
V_21 = V_7 -> V_8 . V_63 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_8 . V_62 ; V_41 ++ , V_21 ++ )
V_7 -> V_45 [ V_41 ] = F_37 ( & V_7 -> V_8 ,
V_21 , V_64 ) ;
return 0 ;
}
static int F_44 ( struct V_6 * V_7 )
{
T_1 V_21 ;
F_45 (nid, codec) {
struct V_65 * V_66 ;
unsigned int V_45 = F_35 ( V_7 , V_21 ) ;
unsigned int V_67 = F_34 ( V_45 ) ;
if ( V_67 != V_43 )
continue;
V_66 = F_46 ( & V_7 -> V_68 ) ;
if ( ! V_66 )
return - V_29 ;
V_66 -> V_21 = V_21 ;
V_66 -> V_69 = F_41 ( V_7 , V_21 , 0 ,
V_70 , 0 ) ;
V_66 -> V_71 = F_41 ( V_7 , V_21 , 0 ,
V_72 ,
0 ) ;
}
return 0 ;
}
static struct V_65 * F_47 ( struct V_6 * V_7 ,
struct V_73 * V_74 ,
T_1 V_21 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_74 -> V_75 ; V_41 ++ ) {
struct V_65 * V_66 = F_48 ( V_74 , V_41 ) ;
if ( V_66 -> V_21 == V_21 )
return V_66 ;
}
return NULL ;
}
int F_49 ( struct V_6 * V_7 , struct V_73 * V_27 ,
T_1 V_21 , unsigned int V_69 )
{
struct V_65 * V_66 ;
V_66 = F_47 ( V_7 , V_27 , V_21 ) ;
if ( ! V_66 ) {
V_66 = F_46 ( V_27 ) ;
if ( ! V_66 )
return - V_29 ;
V_66 -> V_21 = V_21 ;
}
V_66 -> V_69 = V_69 ;
return 0 ;
}
int F_50 ( struct V_6 * V_7 ,
T_1 V_21 , unsigned int V_69 )
{
return F_49 ( V_7 , & V_7 -> V_76 , V_21 , V_69 ) ;
}
unsigned int F_51 ( struct V_6 * V_7 , T_1 V_21 )
{
struct V_65 * V_66 ;
#ifdef F_52
{
unsigned int V_69 = 0 ;
F_4 ( & V_7 -> V_77 ) ;
V_66 = F_47 ( V_7 , & V_7 -> V_78 , V_21 ) ;
if ( V_66 )
V_69 = V_66 -> V_69 ;
F_6 ( & V_7 -> V_77 ) ;
if ( V_69 )
return V_69 ;
}
#endif
V_66 = F_47 ( V_7 , & V_7 -> V_76 , V_21 ) ;
if ( V_66 )
return V_66 -> V_69 ;
V_66 = F_47 ( V_7 , & V_7 -> V_68 , V_21 ) ;
if ( V_66 )
return V_66 -> V_69 ;
return 0 ;
}
int F_53 ( struct V_6 * V_7 , T_1 V_21 ,
unsigned int V_79 )
{
struct V_65 * V_66 ;
V_66 = F_47 ( V_7 , & V_7 -> V_68 , V_21 ) ;
if ( ! V_66 )
return - V_36 ;
V_66 -> V_80 = V_79 ;
return 0 ;
}
int F_54 ( struct V_6 * V_7 , T_1 V_21 )
{
struct V_65 * V_66 ;
V_66 = F_47 ( V_7 , & V_7 -> V_68 , V_21 ) ;
if ( ! V_66 )
return 0 ;
return V_66 -> V_80 ;
}
void F_55 ( struct V_6 * V_7 )
{
int V_41 ;
if ( V_7 -> V_10 -> V_81 )
return;
for ( V_41 = 0 ; V_41 < V_7 -> V_68 . V_75 ; V_41 ++ ) {
struct V_65 * V_66 = F_48 ( & V_7 -> V_68 , V_41 ) ;
F_41 ( V_7 , V_66 -> V_21 , 0 ,
V_82 , 0 ) ;
}
V_7 -> V_83 = 1 ;
}
static void F_56 ( struct V_6 * V_7 )
{
int V_41 ;
if ( ! V_7 -> V_83 )
return;
if ( V_7 -> V_10 -> V_81 )
return;
for ( V_41 = 0 ; V_41 < V_7 -> V_68 . V_75 ; V_41 ++ ) {
struct V_65 * V_66 = F_48 ( & V_7 -> V_68 , V_41 ) ;
F_12 ( V_7 , V_66 -> V_21 , 0 ,
V_82 ,
V_66 -> V_71 ) ;
}
V_7 -> V_83 = 0 ;
}
static void F_57 ( struct V_84 * V_85 )
{
struct V_6 * V_7 =
F_2 ( V_85 , struct V_6 , V_86 . V_85 ) ;
F_58 ( V_7 ) ;
F_59 ( V_7 ) ;
if ( ! V_7 -> V_87 )
return;
F_60 ( & V_7 -> V_86 ,
V_7 -> V_87 ) ;
}
static void F_61 ( struct V_6 * V_7 )
{
F_62 ( & V_7 -> V_76 ) ;
#ifdef F_52
F_62 ( & V_7 -> V_78 ) ;
#endif
F_62 ( & V_7 -> V_68 ) ;
}
static struct V_88 *
F_63 ( struct V_6 * V_7 , T_1 V_21 )
{
struct V_88 * V_25 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_89 . V_75 ; V_41 ++ ) {
V_25 = F_48 ( & V_7 -> V_89 , V_41 ) ;
if ( V_25 -> V_21 == V_21 )
return V_25 ;
}
V_25 = F_46 ( & V_7 -> V_89 ) ;
if ( V_25 )
V_25 -> V_21 = V_21 ;
return V_25 ;
}
static void F_64 ( struct V_90 * V_90 )
{
struct V_91 * V_92 = F_2 ( V_90 , struct V_91 , V_90 ) ;
if ( V_92 -> V_92 )
F_65 ( V_92 -> V_7 -> V_93 , V_92 -> V_92 ) ;
F_66 ( V_92 -> V_94 , V_92 -> V_7 -> V_10 -> V_95 ) ;
F_23 ( V_92 -> V_96 ) ;
F_23 ( V_92 ) ;
}
void F_67 ( struct V_91 * V_92 )
{
F_68 ( & V_92 -> V_90 , F_64 ) ;
}
struct V_91 * F_69 ( struct V_6 * V_7 ,
const char * V_97 , ... )
{
struct V_91 * V_92 ;
T_3 args ;
V_92 = F_70 ( sizeof( * V_92 ) , V_28 ) ;
if ( ! V_92 )
return NULL ;
V_92 -> V_7 = V_7 ;
F_71 ( & V_92 -> V_90 ) ;
va_start ( args , V_97 ) ;
V_92 -> V_96 = F_72 ( V_28 , V_97 , args ) ;
va_end ( args ) ;
if ( ! V_92 -> V_96 ) {
F_23 ( V_92 ) ;
return NULL ;
}
F_73 ( & V_92 -> V_27 , & V_7 -> V_98 ) ;
return V_92 ;
}
static void F_74 ( struct V_6 * V_7 )
{
struct V_91 * V_92 , * V_99 ;
F_75 (pcm, n, &codec->pcm_list_head, list) {
F_76 ( & V_92 -> V_27 ) ;
if ( V_92 -> V_92 )
F_77 ( V_7 -> V_93 , V_92 -> V_92 ) ;
F_67 ( V_92 ) ;
}
}
void F_78 ( struct V_6 * V_7 )
{
if ( V_7 -> V_100 ) {
F_79 ( F_80 ( V_7 ) ) ;
F_81 ( F_80 ( V_7 ) ) ;
V_7 -> V_100 = 0 ;
}
F_82 ( & V_7 -> V_86 ) ;
if ( ! V_7 -> V_101 )
F_83 ( V_7 ) ;
F_74 ( V_7 ) ;
F_84 ( V_7 ) ;
memset ( & V_7 -> V_102 , 0 , sizeof( V_7 -> V_102 ) ) ;
F_85 ( V_7 ) ;
V_7 -> V_103 = NULL ;
V_7 -> V_104 = NULL ;
F_62 ( & V_7 -> V_76 ) ;
F_62 ( & V_7 -> V_89 ) ;
F_62 ( & V_7 -> V_105 ) ;
F_62 ( & V_7 -> V_106 ) ;
V_7 -> V_107 = NULL ;
V_7 -> V_108 = NULL ;
V_7 -> V_109 = 0 ;
F_62 ( & V_7 -> V_110 ) ;
F_62 ( & V_7 -> V_111 ) ;
F_18 ( V_7 ) ;
F_86 ( & V_7 -> V_8 ) ;
}
void F_87 ( struct V_6 * V_7 )
{
if ( V_7 -> V_100 )
return;
if ( F_88 ( F_80 ( V_7 ) ) ) {
F_89 ( V_7 ) ;
F_90 ( & V_7 -> V_8 , true ) ;
F_91 ( F_80 ( V_7 ) ) ;
F_92 ( V_7 ) ;
V_7 -> V_100 = 1 ;
}
}
static int F_93 ( struct V_112 * V_94 )
{
F_87 ( V_94 -> V_113 ) ;
return 0 ;
}
static int F_94 ( struct V_112 * V_94 )
{
struct V_6 * V_7 = V_94 -> V_113 ;
F_84 ( V_7 ) ;
return 0 ;
}
static int F_95 ( struct V_112 * V_94 )
{
struct V_6 * V_7 = V_94 -> V_113 ;
V_7 -> V_101 = 1 ;
F_96 ( & V_7 -> V_8 ) ;
F_90 ( & V_7 -> V_8 , false ) ;
F_97 ( F_80 ( V_7 ) ) ;
return 0 ;
}
static void F_98 ( struct V_94 * V_2 )
{
struct V_6 * V_7 = F_99 ( V_2 ) ;
F_61 ( V_7 ) ;
F_100 ( & V_7 -> V_8 ) ;
F_101 ( V_7 ) ;
F_23 ( V_7 -> V_114 ) ;
F_23 ( V_7 -> V_45 ) ;
F_23 ( V_7 ) ;
}
int F_102 ( struct V_9 * V_10 , struct V_115 * V_93 ,
unsigned int V_116 , struct V_6 * * V_117 )
{
struct V_6 * V_7 ;
char V_118 [ 31 ] ;
T_1 V_119 ;
int V_11 ;
static struct V_120 V_121 = {
. V_122 = F_93 ,
. V_123 = F_94 ,
. V_124 = F_95 ,
} ;
if ( F_30 ( ! V_10 ) )
return - V_36 ;
if ( F_30 ( V_116 > V_125 ) )
return - V_36 ;
V_7 = F_70 ( sizeof( * V_7 ) , V_28 ) ;
if ( ! V_7 )
return - V_29 ;
sprintf ( V_118 , L_4 , V_93 -> V_126 , V_116 ) ;
V_11 = F_103 ( & V_7 -> V_8 , & V_10 -> V_8 , V_118 ,
V_116 ) ;
if ( V_11 < 0 ) {
F_23 ( V_7 ) ;
return V_11 ;
}
V_7 -> V_8 . V_2 . V_127 = F_98 ;
V_7 -> V_8 . type = V_128 ;
V_7 -> V_8 . V_129 = F_1 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_93 = V_93 ;
V_7 -> V_16 = V_116 ;
F_104 ( & V_7 -> V_130 ) ;
F_104 ( & V_7 -> V_131 ) ;
F_105 ( & V_7 -> V_110 , sizeof( struct V_132 ) , 32 ) ;
F_105 ( & V_7 -> V_111 , sizeof( struct V_132 ) , 32 ) ;
F_105 ( & V_7 -> V_68 , sizeof( struct V_65 ) , 16 ) ;
F_105 ( & V_7 -> V_76 , sizeof( struct V_65 ) , 16 ) ;
F_105 ( & V_7 -> V_89 , sizeof( struct V_88 ) , 8 ) ;
F_105 ( & V_7 -> V_105 , sizeof( struct V_133 ) , 16 ) ;
F_105 ( & V_7 -> V_134 , sizeof( struct V_135 ) , 16 ) ;
F_105 ( & V_7 -> V_106 , sizeof( struct V_19 * ) , 8 ) ;
F_106 ( & V_7 -> V_31 ) ;
F_106 ( & V_7 -> V_98 ) ;
F_107 ( & V_7 -> V_86 , F_57 ) ;
V_7 -> V_136 = - 1 ;
V_7 -> V_137 = V_138 ;
#ifdef F_108
V_7 -> V_139 = V_140 ;
#endif
F_109 ( V_7 ) ;
if ( V_7 -> V_10 -> V_114 ) {
V_7 -> V_114 = F_110 ( V_7 -> V_10 -> V_114 , V_28 ) ;
if ( ! V_7 -> V_114 ) {
V_11 = - V_29 ;
goto error;
}
}
V_119 = V_7 -> V_8 . V_141 ? V_7 -> V_8 . V_141 : V_7 -> V_8 . V_142 ;
V_11 = F_43 ( V_7 , V_119 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_44 ( V_7 ) ;
if ( V_11 < 0 )
goto error;
F_111 ( V_7 , V_143 ) ;
F_112 ( V_7 ) ;
F_113 ( V_7 ) ;
sprintf ( V_118 , L_5 , V_7 -> V_8 . V_144 ,
V_7 -> V_8 . V_145 , V_7 -> V_8 . V_146 ) ;
F_114 ( V_93 , V_118 ) ;
V_11 = F_115 ( V_93 , V_147 , V_7 , & V_121 ) ;
if ( V_11 < 0 )
goto error;
if ( V_117 )
* V_117 = V_7 ;
return 0 ;
error:
F_97 ( F_80 ( V_7 ) ) ;
return V_11 ;
}
int F_116 ( struct V_6 * V_7 )
{
T_1 V_119 ;
int V_11 ;
V_11 = F_117 ( & V_7 -> V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
F_23 ( V_7 -> V_45 ) ;
V_119 = V_7 -> V_8 . V_141 ? V_7 -> V_8 . V_141 : V_7 -> V_8 . V_142 ;
V_11 = F_43 ( V_7 , V_119 ) ;
if ( V_11 < 0 )
return V_11 ;
F_62 ( & V_7 -> V_68 ) ;
V_11 = F_44 ( V_7 ) ;
return V_11 ;
}
static void F_118 ( struct V_6 * V_7 ,
struct V_88 * V_25 , T_1 V_21 ,
T_4 V_148 , int V_149 )
{
unsigned int V_150 , V_151 ;
if ( V_25 -> V_148 != V_148 || V_25 -> V_149 != V_149 ) {
V_150 = F_41 ( V_7 , V_21 , 0 , V_152 , 0 ) ;
V_151 = ( V_148 << 4 ) | V_149 ;
if ( V_150 != V_151 )
F_12 ( V_7 , V_21 , 0 ,
V_153 ,
V_151 ) ;
V_25 -> V_148 = V_148 ;
V_25 -> V_149 = V_149 ;
}
}
static void F_119 ( struct V_6 * V_7 , struct V_88 * V_25 ,
T_1 V_21 , int V_154 )
{
unsigned int V_150 ;
if ( V_25 -> V_155 != V_154 ) {
V_150 = F_41 ( V_7 , V_21 , 0 ,
V_156 , 0 ) ;
if ( V_150 != V_154 ) {
F_120 ( 1 ) ;
F_12 ( V_7 , V_21 , 0 ,
V_157 ,
V_154 ) ;
}
V_25 -> V_155 = V_154 ;
}
}
void F_121 ( struct V_6 * V_7 , T_1 V_21 ,
T_4 V_148 ,
int V_149 , int V_154 )
{
struct V_6 * V_158 ;
struct V_88 * V_25 ;
int type ;
int V_41 ;
if ( ! V_21 )
return;
F_9 ( V_7 ,
L_6 ,
V_21 , V_148 , V_149 , V_154 ) ;
V_25 = F_63 ( V_7 , V_21 ) ;
if ( ! V_25 )
return;
if ( V_7 -> V_102 . V_159 )
V_7 -> V_102 . V_159 ( V_7 , V_21 , true ) ;
if ( V_7 -> V_160 )
F_119 ( V_7 , V_25 , V_21 , V_154 ) ;
F_118 ( V_7 , V_25 , V_21 , V_148 , V_149 ) ;
if ( ! V_7 -> V_160 )
F_119 ( V_7 , V_25 , V_21 , V_154 ) ;
V_25 -> V_161 = 1 ;
V_25 -> V_162 = 0 ;
type = F_34 ( F_35 ( V_7 , V_21 ) ) ;
F_122 (c, codec->bus) {
for ( V_41 = 0 ; V_41 < V_158 -> V_89 . V_75 ; V_41 ++ ) {
V_25 = F_48 ( & V_158 -> V_89 , V_41 ) ;
if ( ! V_25 -> V_161 && V_25 -> V_148 == V_148 &&
F_34 ( F_35 ( V_158 , V_25 -> V_21 ) ) == type )
V_25 -> V_162 = 1 ;
}
}
}
void F_123 ( struct V_6 * V_7 , T_1 V_21 ,
int V_163 )
{
struct V_88 * V_25 ;
if ( ! V_21 )
return;
if ( V_7 -> V_164 )
V_163 = 1 ;
F_9 ( V_7 , L_7 , V_21 ) ;
V_25 = F_63 ( V_7 , V_21 ) ;
if ( V_25 ) {
if ( V_163 )
F_124 ( V_7 , V_25 ) ;
else
V_25 -> V_161 = 0 ;
}
}
static void F_124 ( struct V_6 * V_7 ,
struct V_88 * V_165 )
{
T_1 V_21 = V_165 -> V_21 ;
if ( V_165 -> V_148 || V_165 -> V_149 )
F_12 ( V_7 , V_21 , 0 , V_153 , 0 ) ;
if ( V_165 -> V_155 )
F_12 ( V_7 , V_21 , 0 , V_157 , 0
) ;
memset ( V_165 , 0 , sizeof( * V_165 ) ) ;
V_165 -> V_21 = V_21 ;
if ( V_7 -> V_102 . V_159 )
V_7 -> V_102 . V_159 ( V_7 , V_21 , false ) ;
}
static void F_125 ( struct V_6 * V_7 )
{
struct V_6 * V_158 ;
int V_41 ;
F_122 (c, codec->bus) {
for ( V_41 = 0 ; V_41 < V_158 -> V_89 . V_75 ; V_41 ++ ) {
struct V_88 * V_25 ;
V_25 = F_48 ( & V_158 -> V_89 , V_41 ) ;
if ( V_25 -> V_162 )
F_124 ( V_158 , V_25 ) ;
}
}
}
static void F_126 ( struct V_6 * V_7 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_89 . V_75 ; V_41 ++ ) {
struct V_88 * V_25 = F_48 ( & V_7 -> V_89 , V_41 ) ;
if ( V_25 -> V_148 )
F_124 ( V_7 , V_25 ) ;
}
}
T_4 F_127 ( struct V_6 * V_7 , T_1 V_21 , int V_166 )
{
if ( ! ( F_35 ( V_7 , V_21 ) & V_167 ) )
V_21 = V_7 -> V_8 . V_141 ;
return F_128 ( V_7 , V_21 ,
V_166 == V_168 ?
V_169 : V_170 ) ;
}
bool F_129 ( struct V_6 * V_7 , T_1 V_21 ,
int V_171 , unsigned int V_172 )
{
if ( ! V_21 )
return false ;
if ( F_35 ( V_7 , V_21 ) & ( 1 << ( V_171 + 1 ) ) )
if ( F_127 ( V_7 , V_21 , V_171 ) & V_172 )
return true ;
return false ;
}
int F_130 ( struct V_6 * V_7 , T_1 V_21 , int V_171 ,
unsigned int V_173 )
{
unsigned int V_46 ;
F_131 ( V_7 , V_21 ,
F_35 ( V_7 , V_21 ) | V_167 ) ;
V_46 = V_171 == V_168 ? V_169 : V_170 ;
return F_132 ( & V_7 -> V_8 , V_21 , V_46 , V_173 ) ;
}
int F_133 ( struct V_6 * V_7 , T_1 V_21 ,
int V_174 , int V_171 , int V_175 , int V_176 , int V_79 )
{
unsigned int V_3 = F_134 ( V_21 , V_174 , V_171 , V_175 ) ;
if ( ( F_127 ( V_7 , V_21 , V_171 ) &
( V_177 | V_178 ) ) == V_178 )
V_3 |= V_179 ;
return F_135 ( & V_7 -> V_8 , V_3 , V_176 , V_79 ) ;
}
int F_136 ( struct V_6 * V_7 , T_1 V_21 ,
int V_166 , int V_175 , int V_176 , int V_79 )
{
int V_174 , V_58 = 0 ;
if ( F_30 ( V_176 & ~ 0xff ) )
V_176 &= 0xff ;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ )
V_58 |= F_133 ( V_7 , V_21 , V_174 , V_166 ,
V_175 , V_176 , V_79 ) ;
return V_58 ;
}
int F_137 ( struct V_6 * V_7 , T_1 V_21 , int V_174 ,
int V_171 , int V_175 , int V_176 , int V_79 )
{
int V_180 ;
if ( ! V_7 -> V_8 . V_181 )
return - V_36 ;
F_138 ( V_7 -> V_8 . V_181 , true ) ;
V_180 = F_139 ( V_7 , V_21 , V_174 , V_171 , V_175 ) ;
F_138 ( V_7 -> V_8 . V_181 , false ) ;
if ( V_180 >= 0 )
return 0 ;
return F_133 ( V_7 , V_21 , V_174 , V_171 , V_175 , V_176 , V_79 ) ;
}
int F_140 ( struct V_6 * V_7 , T_1 V_21 ,
int V_171 , int V_175 , int V_176 , int V_79 )
{
int V_174 , V_58 = 0 ;
if ( F_30 ( V_176 & ~ 0xff ) )
V_176 &= 0xff ;
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ )
V_58 |= F_137 ( V_7 , V_21 , V_174 , V_171 ,
V_175 , V_176 , V_79 ) ;
return V_58 ;
}
static T_4 F_141 ( struct V_6 * V_7 , T_1 V_21 , int V_171 ,
unsigned int V_182 )
{
T_4 V_173 = F_127 ( V_7 , V_21 , V_171 ) ;
V_173 = ( V_173 & V_183 ) >> V_184 ;
if ( V_182 < V_173 )
V_173 -= V_182 ;
return V_173 ;
}
int F_142 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_5 V_21 = F_144 ( V_186 ) ;
T_2 V_189 = F_145 ( V_186 ) ;
int V_171 = F_146 ( V_186 ) ;
unsigned int V_182 = F_147 ( V_186 ) ;
V_188 -> type = V_190 ;
V_188 -> V_191 = V_189 == 3 ? 2 : 1 ;
V_188 -> V_192 . integer . V_193 = 0 ;
V_188 -> V_192 . integer . V_194 = F_141 ( V_7 , V_21 , V_171 , V_182 ) ;
if ( ! V_188 -> V_192 . integer . V_194 ) {
F_148 ( V_7 ,
L_8 ,
V_21 , V_186 -> V_195 . V_96 ) ;
return - V_36 ;
}
return 0 ;
}
static inline unsigned int
F_149 ( struct V_6 * V_7 , T_1 V_21 ,
int V_174 , int V_171 , int V_175 , unsigned int V_182 )
{
unsigned int V_79 ;
V_79 = F_139 ( V_7 , V_21 , V_174 , V_171 , V_175 ) ;
V_79 &= V_196 ;
if ( V_79 >= V_182 )
V_79 -= V_182 ;
else
V_79 = 0 ;
return V_79 ;
}
static inline int
F_150 ( struct V_6 * V_7 , T_1 V_21 ,
int V_174 , int V_171 , int V_175 , unsigned int V_182 ,
unsigned int V_79 )
{
unsigned int V_197 ;
if ( V_79 > 0 )
V_79 += V_182 ;
V_197 = F_141 ( V_7 , V_21 , V_171 , 0 ) ;
if ( V_79 > V_197 )
V_79 = V_197 ;
return F_133 ( V_7 , V_21 , V_174 , V_171 , V_175 ,
V_196 , V_79 ) ;
}
int F_151 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_1 V_21 = F_144 ( V_186 ) ;
int V_189 = F_145 ( V_186 ) ;
int V_171 = F_146 ( V_186 ) ;
int V_175 = F_152 ( V_186 ) ;
unsigned int V_182 = F_147 ( V_186 ) ;
long * V_200 = V_199 -> V_192 . integer . V_192 ;
if ( V_189 & 1 )
* V_200 ++ = F_149 ( V_7 , V_21 , 0 , V_171 , V_175 , V_182 ) ;
if ( V_189 & 2 )
* V_200 = F_149 ( V_7 , V_21 , 1 , V_171 , V_175 , V_182 ) ;
return 0 ;
}
int F_153 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_1 V_21 = F_144 ( V_186 ) ;
int V_189 = F_145 ( V_186 ) ;
int V_171 = F_146 ( V_186 ) ;
int V_175 = F_152 ( V_186 ) ;
unsigned int V_182 = F_147 ( V_186 ) ;
long * V_200 = V_199 -> V_192 . integer . V_192 ;
int V_201 = 0 ;
if ( V_189 & 1 ) {
V_201 = F_150 ( V_7 , V_21 , 0 , V_171 , V_175 , V_182 , * V_200 ) ;
V_200 ++ ;
}
if ( V_189 & 2 )
V_201 |= F_150 ( V_7 , V_21 , 1 , V_171 , V_175 , V_182 , * V_200 ) ;
return V_201 ;
}
static void F_154 ( struct V_185 * V_186 , unsigned int * V_202 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_1 V_21 = F_144 ( V_186 ) ;
int V_171 = F_146 ( V_186 ) ;
unsigned int V_182 = F_147 ( V_186 ) ;
bool V_203 = F_155 ( V_186 ) ;
T_4 V_173 , V_204 , V_205 ;
V_173 = F_127 ( V_7 , V_21 , V_171 ) ;
V_205 = ( V_173 & V_206 ) >> V_207 ;
V_205 = ( V_205 + 1 ) * 25 ;
V_204 = - ( ( V_173 & V_208 ) >> V_209 ) ;
V_204 += V_182 ;
V_204 = ( ( int ) V_204 ) * ( ( int ) V_205 ) ;
if ( V_203 || ( V_173 & V_178 ) )
V_205 |= V_210 ;
V_202 [ 0 ] = V_211 ;
V_202 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_202 [ 2 ] = V_204 ;
V_202 [ 3 ] = V_205 ;
}
int F_156 ( struct V_185 * V_186 , int V_212 ,
unsigned int V_213 , unsigned int T_6 * V_214 )
{
unsigned int V_202 [ 4 ] ;
if ( V_213 < 4 * sizeof( unsigned int ) )
return - V_29 ;
F_154 ( V_186 , V_202 ) ;
if ( F_157 ( V_214 , V_202 , sizeof( V_202 ) ) )
return - V_215 ;
return 0 ;
}
void F_158 ( struct V_6 * V_7 , T_1 V_21 , int V_171 ,
unsigned int * V_202 )
{
T_4 V_173 ;
int V_42 , V_216 ;
V_173 = F_127 ( V_7 , V_21 , V_171 ) ;
V_42 = ( V_173 & V_183 ) >> V_184 ;
V_216 = ( V_173 & V_206 ) >> V_207 ;
V_216 = ( V_216 + 1 ) * 25 ;
V_202 [ 0 ] = V_211 ;
V_202 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_202 [ 2 ] = - V_42 * V_216 ;
V_202 [ 3 ] = V_216 ;
}
static struct V_185 *
F_159 ( struct V_6 * V_7 , const char * V_96 , int V_2 , int V_175 )
{
struct V_217 V_195 ;
memset ( & V_195 , 0 , sizeof( V_195 ) ) ;
V_195 . V_218 = V_219 ;
V_195 . V_94 = V_2 ;
V_195 . V_220 = V_175 ;
if ( F_30 ( strlen ( V_96 ) >= sizeof( V_195 . V_96 ) ) )
return NULL ;
strcpy ( V_195 . V_96 , V_96 ) ;
return F_160 ( V_7 -> V_93 , & V_195 ) ;
}
struct V_185 * F_161 ( struct V_6 * V_7 ,
const char * V_96 )
{
return F_159 ( V_7 , V_96 , 0 , 0 ) ;
}
static int F_162 ( struct V_6 * V_7 , const char * V_96 ,
int V_221 )
{
int V_41 , V_175 ;
for ( V_41 = 0 , V_175 = V_221 ; V_41 < 16 ; V_41 ++ , V_175 ++ ) {
if ( ! F_159 ( V_7 , V_96 , 0 , V_175 ) )
return V_175 ;
}
return - V_222 ;
}
int F_163 ( struct V_6 * V_7 , T_1 V_21 ,
struct V_185 * V_223 )
{
int V_11 ;
unsigned short V_4 = 0 ;
struct V_132 * V_224 ;
if ( V_223 -> V_195 . V_225 & V_226 ) {
V_4 |= V_227 ;
if ( V_21 == 0 )
V_21 = F_164 ( V_223 -> V_228 ) ;
}
if ( ( V_223 -> V_195 . V_225 & V_229 ) != 0 && V_21 == 0 )
V_21 = V_223 -> V_195 . V_225 & 0xffff ;
if ( V_223 -> V_195 . V_225 & ( V_229 | V_226 ) )
V_223 -> V_195 . V_225 = 0 ;
V_11 = F_165 ( V_7 -> V_93 , V_223 ) ;
if ( V_11 < 0 )
return V_11 ;
V_224 = F_46 ( & V_7 -> V_110 ) ;
if ( ! V_224 )
return - V_29 ;
V_224 -> V_223 = V_223 ;
V_224 -> V_21 = V_21 ;
V_224 -> V_4 = V_4 ;
return 0 ;
}
int F_166 ( struct V_6 * V_7 , struct V_185 * V_223 ,
unsigned int V_220 , T_1 V_21 )
{
struct V_132 * V_224 ;
if ( V_21 > 0 ) {
V_224 = F_46 ( & V_7 -> V_111 ) ;
if ( ! V_224 )
return - V_29 ;
V_224 -> V_223 = V_223 ;
V_224 -> V_220 = V_220 ;
V_224 -> V_21 = V_21 ;
return 0 ;
}
F_32 ( V_7 , L_9 ,
V_223 -> V_195 . V_96 , V_223 -> V_195 . V_220 , V_220 ) ;
return - V_36 ;
}
void F_83 ( struct V_6 * V_7 )
{
int V_41 ;
struct V_132 * V_230 = V_7 -> V_110 . V_27 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_110 . V_75 ; V_41 ++ )
F_167 ( V_7 -> V_93 , V_230 [ V_41 ] . V_223 ) ;
F_62 ( & V_7 -> V_110 ) ;
F_62 ( & V_7 -> V_111 ) ;
}
int F_168 ( struct V_9 * V_10 )
{
struct V_115 * V_93 = V_10 -> V_93 ;
struct V_6 * V_7 ;
F_169 ( & V_93 -> V_231 ) ;
if ( V_93 -> V_81 )
goto V_232;
V_93 -> V_81 = 1 ;
if ( ! F_19 ( & V_93 -> V_233 ) )
goto V_234;
F_122 (codec, bus) {
struct V_91 * V_235 ;
F_14 (cpcm, &codec->pcm_list_head, list) {
if ( ! V_235 -> V_92 )
continue;
if ( V_235 -> V_92 -> V_236 [ 0 ] . V_237 ||
V_235 -> V_92 -> V_236 [ 1 ] . V_237 )
goto V_234;
}
}
F_170 ( & V_93 -> V_231 ) ;
return 0 ;
V_234:
V_93 -> V_81 = 0 ;
V_232:
F_170 ( & V_93 -> V_231 ) ;
return - V_36 ;
}
void F_171 ( struct V_9 * V_10 )
{
struct V_115 * V_93 = V_10 -> V_93 ;
F_169 ( & V_93 -> V_231 ) ;
V_93 -> V_81 = 0 ;
F_170 ( & V_93 -> V_231 ) ;
}
int F_172 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
if ( F_168 ( V_10 ) < 0 )
return - V_222 ;
F_96 ( & V_7 -> V_8 ) ;
F_171 ( V_10 ) ;
return 0 ;
}
static int F_173 ( struct V_6 * V_7 , const char * const * V_238 ,
const char * V_239 , T_7 V_240 , void * V_241 )
{
struct V_132 * V_230 ;
const char * const * V_242 ;
int V_41 , V_11 ;
V_230 = V_7 -> V_110 . V_27 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_110 . V_75 ; V_41 ++ ) {
struct V_185 * V_243 = V_230 [ V_41 ] . V_223 ;
if ( ! V_243 || V_243 -> V_195 . V_218 != V_219 )
continue;
for ( V_242 = V_238 ; * V_242 ; V_242 ++ ) {
char V_244 [ sizeof( V_243 -> V_195 . V_96 ) ] ;
const char * V_96 = * V_242 ;
if ( V_239 ) {
snprintf ( V_244 , sizeof( V_244 ) , L_10 ,
V_96 , V_239 ) ;
V_96 = V_244 ;
}
if ( ! strcmp ( V_243 -> V_195 . V_96 , V_96 ) ) {
V_11 = V_240 ( V_7 , V_241 , V_243 ) ;
if ( V_11 )
return V_11 ;
break;
}
}
}
return 0 ;
}
static int F_174 ( struct V_6 * V_7 ,
void * V_241 , struct V_185 * V_243 )
{
return 1 ;
}
static int F_175 ( struct V_185 * V_223 , int V_79 )
{
struct V_198 * V_199 ;
V_199 = F_70 ( sizeof( * V_199 ) , V_28 ) ;
if ( ! V_199 )
return - V_29 ;
V_199 -> V_192 . integer . V_192 [ 0 ] = V_79 ;
V_199 -> V_192 . integer . V_192 [ 1 ] = V_79 ;
V_223 -> V_245 ( V_223 , V_199 ) ;
F_23 ( V_199 ) ;
return 0 ;
}
static int F_176 ( struct V_185 * V_223 , void * V_246 )
{
struct V_247 * V_248 = V_246 ;
int V_214 [ 4 ] ;
const int * V_202 = NULL ;
int V_216 ;
int V_79 ;
if ( V_223 -> V_249 [ 0 ] . V_250 & V_251 ) {
if ( V_223 -> V_202 . V_158 != F_156 ) {
F_32 ( V_248 -> V_7 ,
L_11 ,
V_223 -> V_195 . V_96 , V_223 -> V_195 . V_220 ) ;
return 0 ;
}
F_154 ( V_223 , V_214 ) ;
V_202 = V_214 ;
} else if ( V_223 -> V_249 [ 0 ] . V_250 & V_252 )
V_202 = V_223 -> V_202 . V_25 ;
if ( ! V_202 || V_202 [ 0 ] != V_211 )
return 0 ;
V_216 = V_202 [ 3 ] ;
V_216 &= ~ V_210 ;
if ( ! V_216 )
return 0 ;
if ( V_248 -> V_216 && V_248 -> V_216 != V_216 ) {
F_32 ( V_248 -> V_7 ,
L_12 ,
V_248 -> V_216 , V_216 ) ;
return 0 ;
}
V_248 -> V_216 = V_216 ;
V_79 = - V_202 [ 2 ] / V_216 ;
if ( V_79 > 0 ) {
F_175 ( V_223 , V_79 ) ;
return V_79 ;
}
return 0 ;
}
static int F_177 ( struct V_185 * V_253 , void * V_246 )
{
return F_175 ( V_253 , 1 ) ;
}
static int F_178 ( struct V_6 * V_7 ,
void * V_241 , struct V_185 * V_253 )
{
return F_179 ( V_241 , V_253 ) ;
}
int F_180 ( struct V_6 * V_7 , char * V_96 ,
unsigned int * V_202 , const char * const * V_238 ,
const char * V_239 , bool V_254 ,
struct V_185 * * V_255 )
{
struct V_185 * V_223 ;
int V_11 ;
if ( V_255 )
* V_255 = NULL ;
V_11 = F_173 ( V_7 , V_238 , V_239 , F_174 , NULL ) ;
if ( V_11 != 1 ) {
F_9 ( V_7 , L_13 , V_96 ) ;
return 0 ;
}
V_223 = F_181 ( V_96 , V_202 ) ;
if ( ! V_223 )
return - V_29 ;
V_11 = F_163 ( V_7 , 0 , V_223 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_173 ( V_7 , V_238 , V_239 , F_178 , V_223 ) ;
if ( V_11 < 0 )
return V_11 ;
F_175 ( V_223 , 0 ) ;
if ( V_254 ) {
struct V_247 V_248 = {
. V_7 = V_7 ,
. V_216 = 0 ,
} ;
F_182 ( V_223 ,
V_202 ? F_176 : F_177 ,
& V_248 ) ;
}
if ( V_255 )
* V_255 = V_223 ;
return 0 ;
}
static int F_183 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
static const char * const V_256 [] = {
L_14 , L_15 , L_16
} ;
return F_184 ( V_188 , 1 , 3 , V_256 ) ;
}
static int F_185 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_257 * V_258 = F_143 ( V_186 ) ;
V_199 -> V_192 . V_259 . V_224 [ 0 ] = V_258 -> V_260 ;
return 0 ;
}
static int F_186 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_257 * V_258 = F_143 ( V_186 ) ;
unsigned int V_261 = V_258 -> V_260 ;
V_258 -> V_260 = V_199 -> V_192 . V_259 . V_224 [ 0 ] ;
if ( V_258 -> V_260 > V_262 )
V_258 -> V_260 = V_262 ;
if ( V_261 == V_258 -> V_260 )
return 0 ;
F_187 ( V_258 ) ;
return 1 ;
}
static void F_188 ( void * V_263 , int V_264 )
{
struct V_257 * V_258 = V_263 ;
if ( V_258 -> V_260 != V_262 )
V_264 = V_258 -> V_260 ;
V_258 -> V_258 ( V_258 -> V_7 , V_264 ) ;
}
int F_189 ( struct V_6 * V_7 ,
struct V_257 * V_258 ,
bool V_265 )
{
struct V_185 * V_223 ;
if ( ! V_258 -> V_258 || ! V_258 -> V_266 )
return 0 ;
V_258 -> V_7 = V_7 ;
V_258 -> V_260 = V_262 ;
F_190 ( V_258 -> V_266 , F_188 , V_258 ) ;
if ( ! V_265 )
return 0 ;
V_223 = F_191 ( & V_267 , V_258 ) ;
if ( ! V_223 )
return - V_29 ;
return F_163 ( V_7 , 0 , V_223 ) ;
}
void F_187 ( struct V_257 * V_258 )
{
if ( ! V_258 -> V_258 || ! V_258 -> V_7 )
return;
if ( V_258 -> V_7 -> V_10 -> V_81 )
return;
F_192 ( V_258 -> V_266 ) ;
}
int F_193 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
int V_189 = F_145 ( V_186 ) ;
V_188 -> type = V_268 ;
V_188 -> V_191 = V_189 == 3 ? 2 : 1 ;
V_188 -> V_192 . integer . V_193 = 0 ;
V_188 -> V_192 . integer . V_194 = 1 ;
return 0 ;
}
int F_194 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_1 V_21 = F_144 ( V_186 ) ;
int V_189 = F_145 ( V_186 ) ;
int V_171 = F_146 ( V_186 ) ;
int V_175 = F_152 ( V_186 ) ;
long * V_200 = V_199 -> V_192 . integer . V_192 ;
if ( V_189 & 1 )
* V_200 ++ = ( F_139 ( V_7 , V_21 , 0 , V_171 , V_175 ) &
V_269 ) ? 0 : 1 ;
if ( V_189 & 2 )
* V_200 = ( F_139 ( V_7 , V_21 , 1 , V_171 , V_175 ) &
V_269 ) ? 0 : 1 ;
return 0 ;
}
int F_195 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_1 V_21 = F_144 ( V_186 ) ;
int V_189 = F_145 ( V_186 ) ;
int V_171 = F_146 ( V_186 ) ;
int V_175 = F_152 ( V_186 ) ;
long * V_200 = V_199 -> V_192 . integer . V_192 ;
int V_201 = 0 ;
if ( V_189 & 1 ) {
V_201 = F_133 ( V_7 , V_21 , 0 , V_171 , V_175 ,
V_269 ,
* V_200 ? 0 : V_269 ) ;
V_200 ++ ;
}
if ( V_189 & 2 )
V_201 |= F_133 ( V_7 , V_21 , 1 , V_171 , V_175 ,
V_269 ,
* V_200 ? 0 : V_269 ) ;
F_196 ( V_7 , V_21 ) ;
return V_201 ;
}
static int F_197 ( struct V_185 * V_186 ,
struct V_187 * V_188 )
{
V_188 -> type = V_270 ;
V_188 -> V_191 = 1 ;
return 0 ;
}
static int F_198 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
V_199 -> V_192 . V_271 . V_272 [ 0 ] = V_273 |
V_274 |
V_275 |
V_276 ;
V_199 -> V_192 . V_271 . V_272 [ 1 ] = V_277 |
V_278 ;
return 0 ;
}
static int F_199 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
V_199 -> V_192 . V_271 . V_272 [ 0 ] = V_273 |
V_274 |
V_279 ;
return 0 ;
}
static int F_200 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
int V_175 = V_186 -> V_228 ;
struct V_133 * V_280 ;
F_4 ( & V_7 -> V_130 ) ;
V_280 = F_48 ( & V_7 -> V_105 , V_175 ) ;
V_199 -> V_192 . V_271 . V_272 [ 0 ] = V_280 -> V_272 & 0xff ;
V_199 -> V_192 . V_271 . V_272 [ 1 ] = ( V_280 -> V_272 >> 8 ) & 0xff ;
V_199 -> V_192 . V_271 . V_272 [ 2 ] = ( V_280 -> V_272 >> 16 ) & 0xff ;
V_199 -> V_192 . V_271 . V_272 [ 3 ] = ( V_280 -> V_272 >> 24 ) & 0xff ;
F_6 ( & V_7 -> V_130 ) ;
return 0 ;
}
static unsigned short F_201 ( unsigned int V_281 )
{
unsigned short V_79 = 0 ;
if ( V_281 & V_273 )
V_79 |= V_282 ;
if ( V_281 & V_274 )
V_79 |= V_283 ;
if ( V_281 & V_273 ) {
if ( ( V_281 & V_284 ) ==
V_279 )
V_79 |= V_285 ;
} else {
if ( ( V_281 & V_286 ) ==
V_275 )
V_79 |= V_285 ;
if ( ! ( V_281 & V_276 ) )
V_79 |= V_287 ;
if ( V_281 & ( V_278 << 8 ) )
V_79 |= V_288 ;
V_79 |= V_281 & ( V_277 << 8 ) ;
}
return V_79 ;
}
static unsigned int F_202 ( unsigned short V_79 )
{
unsigned int V_281 = 0 ;
if ( V_79 & V_283 )
V_281 |= V_274 ;
if ( V_79 & V_282 )
V_281 |= V_273 ;
if ( V_281 & V_273 ) {
if ( V_79 & V_285 )
V_281 |= V_279 ;
} else {
if ( V_79 & V_285 )
V_281 |= V_275 ;
if ( ! ( V_79 & V_287 ) )
V_281 |= V_276 ;
if ( V_79 & V_288 )
V_281 |= ( V_278 << 8 ) ;
V_281 |= V_79 & ( 0x7f << 8 ) ;
}
return V_281 ;
}
static void F_203 ( struct V_6 * V_7 , T_1 V_21 ,
int V_176 , int V_79 )
{
const T_1 * V_289 ;
F_204 ( & V_7 -> V_8 , V_21 , V_290 ,
V_176 , V_79 ) ;
V_289 = V_7 -> V_108 ;
if ( ! V_289 )
return;
for (; * V_289 ; V_289 ++ )
F_204 ( & V_7 -> V_8 , * V_289 ,
V_290 , V_176 , V_79 ) ;
}
static inline void F_205 ( struct V_6 * V_7 , T_1 V_21 ,
int V_291 , int V_292 )
{
unsigned int V_176 = 0 ;
unsigned int V_79 = 0 ;
if ( V_291 != - 1 ) {
V_176 |= 0xff ;
V_79 = V_291 ;
}
if ( V_292 != - 1 ) {
V_176 |= 0xff00 ;
V_79 |= V_292 << 8 ;
}
F_203 ( V_7 , V_21 , V_176 , V_79 ) ;
}
static int F_206 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
int V_175 = V_186 -> V_228 ;
struct V_133 * V_280 ;
T_1 V_21 ;
unsigned short V_79 ;
int V_201 ;
F_4 ( & V_7 -> V_130 ) ;
V_280 = F_48 ( & V_7 -> V_105 , V_175 ) ;
V_21 = V_280 -> V_21 ;
V_280 -> V_272 = V_199 -> V_192 . V_271 . V_272 [ 0 ] |
( ( unsigned int ) V_199 -> V_192 . V_271 . V_272 [ 1 ] << 8 ) |
( ( unsigned int ) V_199 -> V_192 . V_271 . V_272 [ 2 ] << 16 ) |
( ( unsigned int ) V_199 -> V_192 . V_271 . V_272 [ 3 ] << 24 ) ;
V_79 = F_201 ( V_280 -> V_272 ) ;
V_79 |= V_280 -> V_293 & 1 ;
V_201 = V_280 -> V_293 != V_79 ;
V_280 -> V_293 = V_79 ;
if ( V_201 && V_21 != ( T_5 ) - 1 )
F_205 ( V_7 , V_21 , V_79 & 0xff , ( V_79 >> 8 ) & 0xff ) ;
F_6 ( & V_7 -> V_130 ) ;
return V_201 ;
}
static int F_207 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
int V_175 = V_186 -> V_228 ;
struct V_133 * V_280 ;
F_4 ( & V_7 -> V_130 ) ;
V_280 = F_48 ( & V_7 -> V_105 , V_175 ) ;
V_199 -> V_192 . integer . V_192 [ 0 ] = V_280 -> V_293 & V_294 ;
F_6 ( & V_7 -> V_130 ) ;
return 0 ;
}
static inline void F_208 ( struct V_6 * V_7 , T_1 V_21 ,
int V_291 , int V_292 )
{
F_205 ( V_7 , V_21 , V_291 , V_292 ) ;
if ( ( F_35 ( V_7 , V_21 ) & V_295 ) &&
( V_291 & V_294 ) )
F_136 ( V_7 , V_21 , V_168 , 0 ,
V_269 , 0 ) ;
}
static int F_209 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
int V_175 = V_186 -> V_228 ;
struct V_133 * V_280 ;
T_1 V_21 ;
unsigned short V_79 ;
int V_201 ;
F_4 ( & V_7 -> V_130 ) ;
V_280 = F_48 ( & V_7 -> V_105 , V_175 ) ;
V_21 = V_280 -> V_21 ;
V_79 = V_280 -> V_293 & ~ V_294 ;
if ( V_199 -> V_192 . integer . V_192 [ 0 ] )
V_79 |= V_294 ;
V_201 = V_280 -> V_293 != V_79 ;
V_280 -> V_293 = V_79 ;
if ( V_201 && V_21 != ( T_5 ) - 1 )
F_208 ( V_7 , V_21 , V_79 & 0xff , - 1 ) ;
F_6 ( & V_7 -> V_130 ) ;
return V_201 ;
}
int F_210 ( struct V_6 * V_7 ,
T_1 V_296 ,
T_1 V_297 ,
int type )
{
int V_11 ;
struct V_185 * V_223 ;
struct V_298 * V_299 ;
int V_175 = 0 ;
int V_79 = 0 ;
const int V_300 = 16 ;
struct V_133 * V_280 ;
struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_10 -> V_301 == V_302 &&
type == V_303 ) {
V_175 = V_300 ;
} else if ( V_10 -> V_301 == V_303 &&
type == V_302 ) {
for ( V_299 = V_304 ; V_299 -> V_96 ; V_299 ++ ) {
V_223 = F_159 ( V_7 , V_299 -> V_96 , 0 , 0 ) ;
if ( ! V_223 )
break;
V_223 -> V_195 . V_220 = V_300 ;
}
V_10 -> V_301 = V_302 ;
}
if ( ! V_10 -> V_301 )
V_10 -> V_301 = type ;
V_175 = F_162 ( V_7 , L_17 , V_175 ) ;
if ( V_175 < 0 ) {
F_32 ( V_7 , L_18 ) ;
return - V_222 ;
}
V_280 = F_46 ( & V_7 -> V_105 ) ;
if ( ! V_280 )
return - V_29 ;
for ( V_299 = V_304 ; V_299 -> V_96 ; V_299 ++ ) {
V_223 = F_191 ( V_299 , V_7 ) ;
if ( ! V_223 )
return - V_29 ;
V_223 -> V_195 . V_220 = V_175 ;
V_223 -> V_228 = V_7 -> V_105 . V_75 - 1 ;
V_11 = F_163 ( V_7 , V_296 , V_223 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_280 -> V_21 = V_297 ;
F_211 ( & V_7 -> V_8 , V_297 ,
V_305 , & V_79 ) ;
V_280 -> V_293 = V_79 ;
V_280 -> V_272 = F_202 ( V_280 -> V_293 ) ;
return 0 ;
}
struct V_133 * F_212 ( struct V_6 * V_7 ,
T_1 V_21 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_105 . V_75 ; V_41 ++ ) {
struct V_133 * V_280 =
F_48 ( & V_7 -> V_105 , V_41 ) ;
if ( V_280 -> V_21 == V_21 )
return V_280 ;
}
return NULL ;
}
void F_213 ( struct V_6 * V_7 , int V_175 )
{
struct V_133 * V_280 ;
F_4 ( & V_7 -> V_130 ) ;
V_280 = F_48 ( & V_7 -> V_105 , V_175 ) ;
V_280 -> V_21 = ( T_5 ) - 1 ;
F_6 ( & V_7 -> V_130 ) ;
}
void F_214 ( struct V_6 * V_7 , int V_175 , T_1 V_21 )
{
struct V_133 * V_280 ;
unsigned short V_79 ;
F_4 ( & V_7 -> V_130 ) ;
V_280 = F_48 ( & V_7 -> V_105 , V_175 ) ;
if ( V_280 -> V_21 != V_21 ) {
V_280 -> V_21 = V_21 ;
V_79 = V_280 -> V_293 ;
F_208 ( V_7 , V_21 , V_79 & 0xff , ( V_79 >> 8 ) & 0xff ) ;
}
F_6 ( & V_7 -> V_130 ) ;
}
static int F_215 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_306 * V_307 = F_143 ( V_186 ) ;
V_199 -> V_192 . integer . V_192 [ 0 ] = V_307 -> V_308 ;
return 0 ;
}
static int F_216 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_306 * V_307 = F_143 ( V_186 ) ;
V_307 -> V_308 = ! ! V_199 -> V_192 . integer . V_192 [ 0 ] ;
return 0 ;
}
int F_217 ( struct V_6 * V_7 ,
struct V_306 * V_307 )
{
struct V_185 * V_223 ;
if ( ! V_307 -> V_309 )
return 0 ;
V_223 = F_191 ( & V_310 , V_307 ) ;
if ( ! V_223 )
return - V_29 ;
return F_163 ( V_7 , V_307 -> V_309 , V_223 ) ;
}
static int F_218 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
V_199 -> V_192 . integer . V_192 [ 0 ] = V_7 -> V_311 ;
return 0 ;
}
static int F_219 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_1 V_21 = V_186 -> V_228 ;
unsigned int V_79 = ! ! V_199 -> V_192 . integer . V_192 [ 0 ] ;
int V_201 ;
F_4 ( & V_7 -> V_130 ) ;
V_201 = V_7 -> V_311 != V_79 ;
if ( V_201 ) {
V_7 -> V_311 = V_79 ;
F_220 ( & V_7 -> V_8 , V_21 ,
V_290 , V_79 ) ;
}
F_6 ( & V_7 -> V_130 ) ;
return V_201 ;
}
static int F_221 ( struct V_185 * V_186 ,
struct V_198 * V_199 )
{
struct V_6 * V_7 = F_143 ( V_186 ) ;
T_1 V_21 = V_186 -> V_228 ;
unsigned int V_79 ;
unsigned int V_281 ;
F_211 ( & V_7 -> V_8 , V_21 ,
V_305 , & V_79 ) ;
V_281 = F_202 ( V_79 ) ;
V_199 -> V_192 . V_271 . V_272 [ 0 ] = V_281 ;
V_199 -> V_192 . V_271 . V_272 [ 1 ] = V_281 >> 8 ;
V_199 -> V_192 . V_271 . V_272 [ 2 ] = V_281 >> 16 ;
V_199 -> V_192 . V_271 . V_272 [ 3 ] = V_281 >> 24 ;
return 0 ;
}
int F_222 ( struct V_6 * V_7 , T_1 V_21 )
{
int V_11 ;
struct V_185 * V_223 ;
struct V_298 * V_299 ;
int V_175 ;
V_175 = F_162 ( V_7 , L_19 , 0 ) ;
if ( V_175 < 0 ) {
F_32 ( V_7 , L_20 ) ;
return - V_222 ;
}
for ( V_299 = V_312 ; V_299 -> V_96 ; V_299 ++ ) {
V_223 = F_191 ( V_299 , V_7 ) ;
if ( ! V_223 )
return - V_29 ;
V_223 -> V_228 = V_21 ;
V_11 = F_163 ( V_7 , V_21 , V_223 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_7 -> V_311 =
F_41 ( V_7 , V_21 , 0 ,
V_305 , 0 ) &
V_294 ;
return 0 ;
}
void F_223 ( struct V_6 * V_7 , T_1 V_119 ,
unsigned int V_313 )
{
T_1 V_21 ;
F_45 (nid, codec) {
unsigned int V_45 = F_35 ( V_7 , V_21 ) ;
unsigned int V_314 = V_313 ;
if ( ! ( V_45 & V_315 ) )
continue;
if ( V_7 -> V_316 ) {
V_314 = V_7 -> V_316 ( V_7 , V_21 , V_313 ) ;
if ( V_314 != V_313 && V_313 == V_317 )
continue;
}
F_12 ( V_7 , V_21 , 0 , V_318 ,
V_314 ) ;
}
}
static unsigned int F_224 ( struct V_6 * V_7 ,
T_1 V_119 ,
unsigned int V_313 )
{
unsigned long V_319 = V_140 + F_225 ( 500 ) ;
unsigned int V_314 , V_320 ;
for (; ; ) {
V_314 = F_41 ( V_7 , V_119 , 0 ,
V_321 , 0 ) ;
if ( V_314 & V_322 )
break;
V_320 = ( V_314 >> 4 ) & 0x0f ;
if ( V_320 == V_313 )
break;
if ( F_226 ( V_140 , V_319 ) )
break;
F_120 ( 1 ) ;
}
return V_314 ;
}
unsigned int F_227 ( struct V_6 * V_7 ,
T_1 V_21 ,
unsigned int V_313 )
{
if ( V_21 == V_7 -> V_8 . V_141 || V_21 == V_7 -> V_8 . V_142 )
return V_313 ;
if ( V_313 == V_317 &&
F_34 ( F_35 ( V_7 , V_21 ) ) == V_43 &&
( F_228 ( V_7 , V_21 ) & V_323 ) ) {
int V_324 = F_41 ( V_7 , V_21 , 0 ,
V_325 , 0 ) ;
if ( V_324 & 0x02 )
return V_143 ;
}
return V_313 ;
}
static unsigned int F_111 ( struct V_6 * V_7 ,
unsigned int V_313 )
{
T_1 V_119 = V_7 -> V_8 . V_141 ? V_7 -> V_8 . V_141 : V_7 -> V_8 . V_142 ;
int V_191 ;
unsigned int V_314 ;
int V_4 = 0 ;
if ( V_313 == V_317 ) {
if ( V_7 -> V_136 < 0 )
F_120 ( F_229 ( V_7 ) ? 10 : 100 ) ;
else if ( V_7 -> V_136 > 0 )
F_120 ( V_7 -> V_136 ) ;
V_4 = V_14 ;
}
for ( V_191 = 0 ; V_191 < 10 ; V_191 ++ ) {
if ( V_7 -> V_102 . V_326 )
V_7 -> V_102 . V_326 ( V_7 , V_119 ,
V_313 ) ;
else {
V_314 = V_313 ;
if ( V_7 -> V_316 )
V_314 = V_7 -> V_316 ( V_7 , V_119 , V_314 ) ;
if ( V_314 == V_313 || V_313 != V_317 )
F_41 ( V_7 , V_119 , V_4 ,
V_318 ,
V_314 ) ;
F_223 ( V_7 , V_119 , V_313 ) ;
}
V_314 = F_224 ( V_7 , V_119 , V_313 ) ;
if ( ! ( V_314 & V_322 ) )
break;
}
return V_314 ;
}
static void F_230 ( struct V_6 * V_7 )
{
T_1 V_21 ;
if ( ! V_7 -> V_316 )
return;
F_45 (nid, codec) {
unsigned int V_45 = F_35 ( V_7 , V_21 ) ;
unsigned int V_80 ;
if ( ! ( V_45 & V_315 ) )
continue;
V_80 = V_7 -> V_316 ( V_7 , V_21 , V_143 ) ;
if ( V_80 == V_143 )
continue;
if ( ! F_231 ( V_7 , V_21 , V_80 ) )
F_12 ( V_7 , V_21 , 0 ,
V_318 , V_80 ) ;
}
}
static void F_232 ( struct V_6 * V_7 )
{
if ( V_7 -> V_327 . V_27 )
F_11 ( V_7 , V_7 -> V_327 . V_27 ) ;
}
static inline void F_232 ( struct V_6 * V_7 ) {}
static void F_233 ( struct V_6 * V_7 , bool V_328 )
{
unsigned long V_329 = V_140 - V_7 -> V_139 ;
if ( V_328 )
V_7 -> V_330 += V_329 ;
else
V_7 -> V_331 += V_329 ;
V_7 -> V_139 += V_329 ;
}
void F_234 ( struct V_6 * V_7 )
{
F_233 ( V_7 , F_235 ( V_7 ) ) ;
}
static unsigned int F_236 ( struct V_6 * V_7 )
{
unsigned int V_314 ;
F_237 ( & V_7 -> V_8 . V_332 ) ;
if ( V_7 -> V_102 . V_333 )
V_7 -> V_102 . V_333 ( V_7 ) ;
F_126 ( V_7 ) ;
V_314 = F_111 ( V_7 , V_317 ) ;
F_233 ( V_7 , true ) ;
F_238 ( & V_7 -> V_8 . V_332 ) ;
return V_314 ;
}
static void F_239 ( struct V_6 * V_7 )
{
F_237 ( & V_7 -> V_8 . V_332 ) ;
if ( V_7 -> V_8 . V_181 )
F_240 ( V_7 -> V_8 . V_181 ) ;
V_7 -> V_139 = V_140 ;
F_111 ( V_7 , V_143 ) ;
F_56 ( V_7 ) ;
F_232 ( V_7 ) ;
F_58 ( V_7 ) ;
if ( V_7 -> V_102 . V_334 )
V_7 -> V_102 . V_334 ( V_7 ) ;
else {
if ( V_7 -> V_102 . V_335 )
V_7 -> V_102 . V_335 ( V_7 ) ;
if ( V_7 -> V_8 . V_181 )
F_241 ( V_7 -> V_8 . V_181 ) ;
}
if ( V_7 -> V_87 )
F_57 ( & V_7 -> V_86 . V_85 ) ;
else
F_242 ( V_7 ) ;
F_238 ( & V_7 -> V_8 . V_332 ) ;
}
static int F_243 ( struct V_94 * V_2 )
{
struct V_6 * V_7 = F_99 ( V_2 ) ;
struct V_91 * V_92 ;
unsigned int V_314 ;
F_82 ( & V_7 -> V_86 ) ;
F_14 (pcm, &codec->pcm_list_head, list)
F_244 ( V_92 -> V_92 ) ;
V_314 = F_236 ( V_7 ) ;
if ( F_245 ( V_7 ) && F_229 ( V_7 ) &&
( V_314 & V_336 ) )
F_246 ( & V_7 -> V_8 ) ;
F_90 ( & V_7 -> V_8 , false ) ;
return 0 ;
}
static int F_247 ( struct V_94 * V_2 )
{
struct V_6 * V_7 = F_99 ( V_2 ) ;
F_90 ( & V_7 -> V_8 , true ) ;
F_248 ( & V_7 -> V_8 ) ;
F_239 ( V_7 ) ;
F_249 ( V_2 ) ;
return 0 ;
}
static int F_250 ( struct V_6 * V_7 )
{
struct V_91 * V_92 ;
int V_337 , V_11 ;
F_14 (pcm, &codec->pcm_list_head, list) {
for ( V_337 = 0 ; V_337 < 2 ; V_337 ++ ) {
struct V_338 * V_339 = & V_92 -> V_340 [ V_337 ] ;
struct V_341 * V_342 ;
const struct V_343 * V_344 ;
if ( ! V_92 -> V_92 || V_92 -> V_345 || ! V_339 -> V_346 )
continue;
V_344 = V_339 -> V_342 ? V_339 -> V_342 : V_347 ;
V_11 = F_251 ( V_92 -> V_92 , V_337 , V_344 ,
V_339 -> V_348 ,
0 , & V_342 ) ;
if ( V_11 < 0 )
return V_11 ;
V_342 -> V_349 = V_350 ;
}
}
return 0 ;
}
int F_252 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
F_232 ( V_7 ) ;
if ( V_7 -> V_102 . V_335 )
V_11 = V_7 -> V_102 . V_335 ( V_7 ) ;
if ( ! V_11 && V_7 -> V_102 . V_351 )
V_11 = V_7 -> V_102 . V_351 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_250 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_7 -> V_87 )
F_57 ( & V_7 -> V_86 . V_85 ) ;
else
F_242 ( V_7 ) ;
F_230 ( V_7 ) ;
return 0 ;
}
static int F_253 ( struct V_338 * V_339 ,
struct V_6 * V_7 ,
struct V_352 * V_353 )
{
return 0 ;
}
static int F_254 ( struct V_338 * V_339 ,
struct V_6 * V_7 ,
unsigned int V_148 ,
unsigned int V_154 ,
struct V_352 * V_353 )
{
F_121 ( V_7 , V_339 -> V_21 , V_148 , 0 , V_154 ) ;
return 0 ;
}
static int F_255 ( struct V_338 * V_339 ,
struct V_6 * V_7 ,
struct V_352 * V_353 )
{
F_256 ( V_7 , V_339 -> V_21 ) ;
return 0 ;
}
static int F_257 ( struct V_6 * V_7 ,
struct V_338 * V_354 )
{
int V_11 ;
if ( V_354 -> V_21 && ( ! V_354 -> V_355 || ! V_354 -> V_356 ) ) {
V_11 = F_258 ( V_7 , V_354 -> V_21 ,
V_354 -> V_355 ? NULL : & V_354 -> V_355 ,
V_354 -> V_356 ? NULL : & V_354 -> V_356 ,
V_354 -> V_357 ? NULL : & V_354 -> V_357 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_354 -> V_358 . V_359 == NULL )
V_354 -> V_358 . V_359 = F_253 ;
if ( V_354 -> V_358 . V_360 == NULL )
V_354 -> V_358 . V_360 = F_253 ;
if ( V_354 -> V_358 . V_361 == NULL ) {
if ( F_30 ( ! V_354 -> V_21 ) )
return - V_36 ;
V_354 -> V_358 . V_361 = F_254 ;
}
if ( V_354 -> V_358 . V_362 == NULL ) {
if ( F_30 ( ! V_354 -> V_21 ) )
return - V_36 ;
V_354 -> V_358 . V_362 = F_255 ;
}
return 0 ;
}
int F_259 ( struct V_6 * V_7 ,
struct V_338 * V_339 ,
unsigned int V_340 ,
unsigned int V_154 ,
struct V_352 * V_353 )
{
int V_58 ;
F_4 ( & V_7 -> V_10 -> V_363 ) ;
if ( V_339 -> V_358 . V_361 )
V_58 = V_339 -> V_358 . V_361 ( V_339 , V_7 , V_340 , V_154 ,
V_353 ) ;
else
V_58 = - V_364 ;
if ( V_58 >= 0 )
F_125 ( V_7 ) ;
F_6 ( & V_7 -> V_10 -> V_363 ) ;
return V_58 ;
}
void F_260 ( struct V_6 * V_7 ,
struct V_338 * V_339 ,
struct V_352 * V_353 )
{
F_4 ( & V_7 -> V_10 -> V_363 ) ;
if ( V_339 -> V_358 . V_362 )
V_339 -> V_358 . V_362 ( V_339 , V_7 , V_353 ) ;
F_6 ( & V_7 -> V_10 -> V_363 ) ;
}
static int F_261 ( struct V_9 * V_10 , unsigned int type )
{
static int V_365 [ V_366 ] [ 5 ] = {
[ V_367 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_303 ] = { 1 , - 1 } ,
[ V_302 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_368 ] = { 6 , - 1 } ,
} ;
int V_41 ;
if ( type >= V_366 ) {
F_262 ( V_10 -> V_93 -> V_2 , L_21 , type ) ;
return - V_36 ;
}
for ( V_41 = 0 ; V_365 [ type ] [ V_41 ] >= 0 ; V_41 ++ ) {
#ifndef F_263
if ( V_365 [ type ] [ V_41 ] >= 8 )
break;
#endif
if ( ! F_264 ( V_365 [ type ] [ V_41 ] , V_10 -> V_95 ) )
return V_365 [ type ] [ V_41 ] ;
}
#ifdef F_263
for ( V_41 = 10 ; V_41 < 32 ; V_41 ++ ) {
if ( ! F_264 ( V_41 , V_10 -> V_95 ) )
return V_41 ;
}
#endif
F_265 ( V_10 -> V_93 -> V_2 , L_22 ,
V_369 [ type ] ) ;
#ifndef F_263
F_265 ( V_10 -> V_93 -> V_2 ,
L_23 ) ;
#endif
return - V_17 ;
}
int F_266 ( struct V_6 * V_7 )
{
struct V_91 * V_235 ;
int V_11 ;
if ( ! F_19 ( & V_7 -> V_98 ) )
return 0 ;
if ( ! V_7 -> V_102 . V_370 )
return 0 ;
V_11 = V_7 -> V_102 . V_370 ( V_7 ) ;
if ( V_11 < 0 ) {
F_32 ( V_7 , L_24 ,
V_7 -> V_8 . V_16 , V_11 ) ;
return V_11 ;
}
F_14 (cpcm, &codec->pcm_list_head, list) {
int V_340 ;
for ( V_340 = 0 ; V_340 < 2 ; V_340 ++ ) {
struct V_338 * V_354 = & V_235 -> V_340 [ V_340 ] ;
if ( ! V_354 -> V_346 )
continue;
V_11 = F_257 ( V_7 , V_354 ) ;
if ( V_11 < 0 ) {
F_148 ( V_7 ,
L_25 ,
V_235 -> V_96 ) ;
return V_11 ;
}
}
}
return 0 ;
}
int F_267 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_91 * V_235 ;
int V_2 , V_11 ;
V_11 = F_266 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
F_14 (cpcm, &codec->pcm_list_head, list) {
if ( V_235 -> V_92 )
continue;
if ( ! V_235 -> V_340 [ 0 ] . V_346 && ! V_235 -> V_340 [ 1 ] . V_346 )
continue;
V_2 = F_261 ( V_10 , V_235 -> V_371 ) ;
if ( V_2 < 0 ) {
V_235 -> V_94 = V_372 ;
continue;
}
V_235 -> V_94 = V_2 ;
V_11 = F_268 ( V_10 , V_7 , V_235 ) ;
if ( V_11 < 0 ) {
F_32 ( V_7 ,
L_26 ,
V_2 , V_7 -> V_8 . V_16 ) ;
continue;
}
}
return 0 ;
}
int F_269 ( struct V_6 * V_7 ,
const struct V_298 * V_373 )
{
int V_11 ;
for (; V_373 -> V_96 ; V_373 ++ ) {
struct V_185 * V_223 ;
int V_16 = 0 , V_175 = 0 ;
if ( V_373 -> V_218 == - 1 )
continue;
for (; ; ) {
V_223 = F_191 ( V_373 , V_7 ) ;
if ( ! V_223 )
return - V_29 ;
if ( V_16 > 0 )
V_223 -> V_195 . V_94 = V_16 ;
if ( V_175 > 0 )
V_223 -> V_195 . V_220 = V_175 ;
V_11 = F_163 ( V_7 , 0 , V_223 ) ;
if ( ! V_11 )
break;
if ( ! V_16 && V_7 -> V_8 . V_16 )
V_16 = V_7 -> V_8 . V_16 ;
else if ( ! V_175 && ! V_373 -> V_220 ) {
V_175 = F_162 ( V_7 ,
V_373 -> V_96 , 0 ) ;
if ( V_175 <= 0 )
return V_11 ;
} else
return V_11 ;
}
}
return 0 ;
}
static void F_270 ( struct V_6 * V_7 , int V_374 )
{
struct V_94 * V_2 = F_80 ( V_7 ) ;
if ( V_374 == 0 && V_7 -> V_375 )
V_374 = 3000 ;
if ( V_374 > 0 ) {
F_271 ( V_2 , V_374 ) ;
F_272 ( V_2 ) ;
F_273 ( V_2 ) ;
if ( ! F_274 ( V_2 ) )
F_249 ( V_2 ) ;
} else {
F_275 ( V_2 ) ;
F_276 ( V_2 ) ;
}
}
void F_277 ( struct V_9 * V_10 , int V_374 )
{
struct V_6 * V_158 ;
F_122 (c, bus)
F_270 ( V_158 , V_374 ) ;
}
int F_278 ( struct V_6 * V_7 ,
struct V_376 * V_377 ,
T_1 V_21 )
{
const struct V_378 * V_25 ;
int V_174 , V_379 ;
if ( ! V_377 -> V_380 )
return 0 ;
for ( V_25 = V_377 -> V_380 ; V_25 -> V_21 ; V_25 ++ ) {
if ( V_25 -> V_21 == V_21 )
break;
}
if ( ! V_25 -> V_21 )
return 0 ;
for ( V_25 = V_377 -> V_380 ; V_25 -> V_21 ; V_25 ++ ) {
for ( V_174 = 0 ; V_174 < 2 ; V_174 ++ ) {
V_379 = F_139 ( V_7 , V_25 -> V_21 , V_174 , V_25 -> V_171 ,
V_25 -> V_175 ) ;
if ( ! ( V_379 & V_269 ) && V_379 > 0 ) {
if ( ! V_377 -> V_381 ) {
V_377 -> V_381 = 1 ;
F_3 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_377 -> V_381 ) {
V_377 -> V_381 = 0 ;
F_7 ( V_7 ) ;
}
return 0 ;
}
int F_279 ( const struct V_382 * V_383 ,
struct V_187 * V_188 )
{
unsigned int V_220 ;
V_188 -> type = V_384 ;
V_188 -> V_191 = 1 ;
V_188 -> V_192 . V_259 . V_230 = V_383 -> V_385 ;
if ( ! V_383 -> V_385 )
return 0 ;
V_220 = V_188 -> V_192 . V_259 . V_224 ;
if ( V_220 >= V_383 -> V_385 )
V_220 = V_383 -> V_385 - 1 ;
strcpy ( V_188 -> V_192 . V_259 . V_96 , V_383 -> V_230 [ V_220 ] . V_386 ) ;
return 0 ;
}
int F_280 ( struct V_6 * V_7 ,
const struct V_382 * V_383 ,
struct V_198 * V_199 ,
T_1 V_21 ,
unsigned int * V_387 )
{
unsigned int V_175 ;
if ( ! V_383 -> V_385 )
return 0 ;
V_175 = V_199 -> V_192 . V_259 . V_224 [ 0 ] ;
if ( V_175 >= V_383 -> V_385 )
V_175 = V_383 -> V_385 - 1 ;
if ( * V_387 == V_175 )
return 0 ;
F_281 ( V_7 , V_21 , 0 , V_388 ,
V_383 -> V_230 [ V_175 ] . V_220 ) ;
* V_387 = V_175 ;
return 1 ;
}
int F_282 ( struct V_185 * V_186 ,
struct V_187 * V_188 ,
int V_385 , const char * const * V_256 )
{
static const char * const V_389 [] = {
L_27 , L_28
} ;
if ( ! V_256 || ! V_385 ) {
V_385 = 2 ;
V_256 = V_389 ;
}
return F_184 ( V_188 , 1 , V_385 , V_256 ) ;
}
static void F_283 ( struct V_6 * V_7 , T_1 V_21 ,
unsigned int V_148 , unsigned int V_154 )
{
struct V_133 * V_280 ;
unsigned int V_390 ;
bool V_391 ;
V_280 = F_212 ( V_7 , V_21 ) ;
if ( F_284 ( V_280 == NULL ) )
return;
V_390 = F_41 ( V_7 , V_21 , 0 ,
V_156 , 0 ) ;
V_391 = V_7 -> V_109 &&
( V_280 -> V_293 & V_294 ) &&
V_390 != V_154 ;
if ( V_391 )
F_205 ( V_7 , V_21 ,
V_280 -> V_293 & ~ V_294 & 0xff ,
- 1 ) ;
F_121 ( V_7 , V_21 , V_148 , 0 , V_154 ) ;
if ( V_7 -> V_108 ) {
const T_1 * V_289 ;
for ( V_289 = V_7 -> V_108 ; * V_289 ; V_289 ++ )
F_121 ( V_7 , * V_289 , V_148 , 0 ,
V_154 ) ;
}
if ( V_391 )
F_205 ( V_7 , V_21 ,
V_280 -> V_293 & 0xff , - 1 ) ;
}
static void F_285 ( struct V_6 * V_7 , T_1 V_21 )
{
F_256 ( V_7 , V_21 ) ;
if ( V_7 -> V_108 ) {
const T_1 * V_289 ;
for ( V_289 = V_7 -> V_108 ; * V_289 ; V_289 ++ )
F_256 ( V_7 , * V_289 ) ;
}
}
int F_286 ( struct V_6 * V_7 ,
struct V_306 * V_307 )
{
F_4 ( & V_7 -> V_130 ) ;
if ( V_307 -> V_392 == V_393 )
F_285 ( V_7 , V_307 -> V_309 ) ;
V_307 -> V_392 = V_394 ;
F_6 ( & V_7 -> V_130 ) ;
return 0 ;
}
int F_287 ( struct V_6 * V_7 ,
struct V_306 * V_307 ,
unsigned int V_148 ,
unsigned int V_154 ,
struct V_352 * V_353 )
{
F_4 ( & V_7 -> V_130 ) ;
F_283 ( V_7 , V_307 -> V_309 , V_148 , V_154 ) ;
F_6 ( & V_7 -> V_130 ) ;
return 0 ;
}
int F_288 ( struct V_6 * V_7 ,
struct V_306 * V_307 )
{
F_4 ( & V_7 -> V_130 ) ;
F_285 ( V_7 , V_307 -> V_309 ) ;
F_6 ( & V_7 -> V_130 ) ;
return 0 ;
}
int F_289 ( struct V_6 * V_7 ,
struct V_306 * V_307 )
{
F_4 ( & V_7 -> V_130 ) ;
V_307 -> V_392 = 0 ;
F_6 ( & V_7 -> V_130 ) ;
return 0 ;
}
int F_290 ( struct V_6 * V_7 ,
struct V_306 * V_307 ,
struct V_352 * V_353 ,
struct V_338 * V_339 )
{
struct V_395 * V_396 = V_353 -> V_396 ;
V_396 -> V_397 . V_348 = V_307 -> V_398 ;
if ( V_307 -> V_309 ) {
if ( ! V_307 -> V_399 ) {
V_307 -> V_399 = V_339 -> V_355 ;
V_307 -> V_400 = V_339 -> V_356 ;
V_307 -> V_401 = V_339 -> V_357 ;
} else {
V_396 -> V_397 . V_355 = V_307 -> V_399 ;
V_396 -> V_397 . V_356 = V_307 -> V_400 ;
V_339 -> V_357 = V_307 -> V_401 ;
}
if ( ! V_307 -> V_402 ) {
F_258 ( V_7 , V_307 -> V_309 ,
& V_307 -> V_402 ,
& V_307 -> V_403 ,
& V_307 -> V_404 ) ;
}
F_4 ( & V_7 -> V_130 ) ;
if ( V_307 -> V_308 ) {
if ( ( V_396 -> V_397 . V_355 & V_307 -> V_402 ) &&
( V_396 -> V_397 . V_356 & V_307 -> V_403 ) ) {
V_396 -> V_397 . V_355 &= V_307 -> V_402 ;
V_396 -> V_397 . V_356 &= V_307 -> V_403 ;
if ( V_307 -> V_404 < V_339 -> V_357 )
V_339 -> V_357 = V_307 -> V_404 ;
} else {
V_307 -> V_308 = 0 ;
}
}
F_6 ( & V_7 -> V_130 ) ;
}
return F_291 ( V_353 -> V_396 , 0 ,
V_405 , 2 ) ;
}
int F_292 ( struct V_6 * V_7 ,
struct V_306 * V_307 ,
unsigned int V_148 ,
unsigned int V_154 ,
struct V_352 * V_353 )
{
const T_1 * V_111 = V_307 -> V_406 ;
int V_189 = V_353 -> V_396 -> V_407 ;
struct V_133 * V_280 ;
int V_41 ;
F_4 ( & V_7 -> V_130 ) ;
V_280 = F_212 ( V_7 , V_307 -> V_309 ) ;
if ( V_307 -> V_309 && V_307 -> V_308 &&
V_307 -> V_392 != V_394 ) {
if ( V_189 == 2 && V_280 != NULL &&
F_293 ( V_7 , V_307 -> V_309 ,
V_154 ) &&
! ( V_280 -> V_272 & V_274 ) ) {
V_307 -> V_392 = V_393 ;
F_283 ( V_7 , V_307 -> V_309 ,
V_148 , V_154 ) ;
} else {
V_307 -> V_392 = 0 ;
F_285 ( V_7 , V_307 -> V_309 ) ;
}
}
F_6 ( & V_7 -> V_130 ) ;
F_121 ( V_7 , V_111 [ V_408 ] , V_148 ,
0 , V_154 ) ;
if ( ! V_307 -> V_409 &&
V_307 -> V_410 && V_307 -> V_410 != V_111 [ V_408 ] )
F_121 ( V_7 , V_307 -> V_410 , V_148 ,
0 , V_154 ) ;
for ( V_41 = 0 ; V_41 < F_26 ( V_307 -> V_411 ) ; V_41 ++ )
if ( ! V_307 -> V_409 && V_307 -> V_411 [ V_41 ] )
F_121 ( V_7 ,
V_307 -> V_411 [ V_41 ] ,
V_148 , 0 , V_154 ) ;
for ( V_41 = 1 ; V_41 < V_307 -> V_412 ; V_41 ++ ) {
if ( V_189 >= ( V_41 + 1 ) * 2 )
F_121 ( V_7 , V_111 [ V_41 ] , V_148 ,
V_41 * 2 , V_154 ) ;
else if ( ! V_307 -> V_409 )
F_121 ( V_7 , V_111 [ V_41 ] , V_148 ,
0 , V_154 ) ;
}
for ( V_41 = 0 ; V_41 < F_26 ( V_307 -> V_413 ) ; V_41 ++ ) {
int V_174 = 0 ;
if ( ! V_307 -> V_413 [ V_41 ] )
break;
if ( V_189 >= ( V_41 + 1 ) * 2 )
V_174 = V_41 * 2 ;
else if ( ! V_307 -> V_409 )
break;
F_121 ( V_7 , V_307 -> V_413 [ V_41 ] ,
V_148 , V_174 , V_154 ) ;
}
return 0 ;
}
int F_294 ( struct V_6 * V_7 ,
struct V_306 * V_307 )
{
const T_1 * V_111 = V_307 -> V_406 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_307 -> V_412 ; V_41 ++ )
F_256 ( V_7 , V_111 [ V_41 ] ) ;
if ( V_307 -> V_410 )
F_256 ( V_7 , V_307 -> V_410 ) ;
for ( V_41 = 0 ; V_41 < F_26 ( V_307 -> V_411 ) ; V_41 ++ )
if ( V_307 -> V_411 [ V_41 ] )
F_256 ( V_7 ,
V_307 -> V_411 [ V_41 ] ) ;
for ( V_41 = 0 ; V_41 < F_26 ( V_307 -> V_413 ) ; V_41 ++ )
if ( V_307 -> V_413 [ V_41 ] )
F_256 ( V_7 ,
V_307 -> V_413 [ V_41 ] ) ;
F_4 ( & V_7 -> V_130 ) ;
if ( V_307 -> V_309 && V_307 -> V_392 == V_393 ) {
F_285 ( V_7 , V_307 -> V_309 ) ;
V_307 -> V_392 = 0 ;
}
F_6 ( & V_7 -> V_130 ) ;
return 0 ;
}
unsigned int F_295 ( struct V_6 * V_7 , T_1 V_66 )
{
unsigned int V_414 ;
unsigned int V_150 ;
V_150 = F_41 ( V_7 , V_66 , 0 ,
V_72 , 0 ) ;
V_414 = F_228 ( V_7 , V_66 ) ;
V_414 = ( V_414 & V_415 ) >> V_416 ;
if ( ( V_414 & V_417 ) && V_150 != V_418 )
return V_419 ;
else if ( V_414 & V_420 )
return V_421 ;
else if ( V_414 & V_422 )
return V_423 ;
else if ( V_414 & V_424 )
return V_425 ;
return V_426 ;
}
unsigned int F_296 ( struct V_6 * V_7 ,
T_1 V_66 , unsigned int V_79 )
{
static unsigned int V_427 [] [ 2 ] = {
{ V_423 , V_422 } ,
{ V_419 , V_417 } ,
{ V_421 , V_420 } ,
{ V_425 , V_424 } ,
} ;
unsigned int V_428 ;
if ( ! V_79 )
return 0 ;
V_428 = F_228 ( V_7 , V_66 ) ;
if ( ! V_428 )
return V_79 ;
if ( V_79 & V_429 ) {
if ( ! ( V_428 & V_430 ) )
V_79 &= ~ ( V_429 | V_431 ) ;
else if ( ( V_79 & V_431 ) && ! ( V_428 & V_432 ) )
V_79 &= ~ V_431 ;
}
if ( V_79 & V_433 ) {
if ( ! ( V_428 & V_434 ) )
V_79 &= ~ ( V_433 | V_435 ) ;
else {
unsigned int V_436 , V_437 ;
int V_41 ;
V_436 = ( V_428 & V_415 ) >> V_416 ;
V_437 = V_79 & V_435 ;
for ( V_41 = 0 ; V_41 < F_26 ( V_427 ) ; V_41 ++ ) {
if ( V_437 == V_427 [ V_41 ] [ 0 ] &&
! ( V_436 & V_427 [ V_41 ] [ 1 ] ) ) {
if ( V_41 == F_26 ( V_427 ) - 1 )
V_437 = V_426 ;
else
V_437 = V_427 [ V_41 + 1 ] [ 0 ] ;
}
}
V_79 &= ~ V_435 ;
V_79 |= V_437 ;
}
}
return V_79 ;
}
int F_297 ( struct V_6 * V_7 , T_1 V_66 ,
unsigned int V_79 , bool V_438 )
{
V_79 = F_296 ( V_7 , V_66 , V_79 ) ;
F_53 ( V_7 , V_66 , V_79 ) ;
if ( V_438 )
return F_298 ( V_7 , V_66 , 0 ,
V_82 , V_79 ) ;
else
return F_12 ( V_7 , V_66 , 0 ,
V_82 , V_79 ) ;
}
int F_299 ( struct V_6 * V_7 ,
struct V_382 * V_383 , const char * V_386 ,
int V_220 , int * V_439 )
{
int V_41 , V_440 = 0 ;
if ( V_383 -> V_385 >= V_441 ) {
F_32 ( V_7 , L_29 ) ;
return - V_36 ;
}
for ( V_41 = 0 ; V_41 < V_383 -> V_385 ; V_41 ++ ) {
if ( ! strncmp ( V_386 , V_383 -> V_230 [ V_41 ] . V_386 , strlen ( V_386 ) ) )
V_440 ++ ;
}
if ( V_439 )
* V_439 = V_440 ;
if ( V_440 > 0 )
snprintf ( V_383 -> V_230 [ V_383 -> V_385 ] . V_386 ,
sizeof( V_383 -> V_230 [ V_383 -> V_385 ] . V_386 ) ,
L_30 , V_386 , V_440 ) ;
else
F_300 ( V_383 -> V_230 [ V_383 -> V_385 ] . V_386 , V_386 ,
sizeof( V_383 -> V_230 [ V_383 -> V_385 ] . V_386 ) ) ;
V_383 -> V_230 [ V_383 -> V_385 ] . V_220 = V_220 ;
V_383 -> V_385 ++ ;
return 0 ;
}
void F_301 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_122 (codec, bus) {
F_82 ( & V_7 -> V_86 ) ;
#ifdef F_108
if ( F_235 ( V_7 ) ) {
F_236 ( V_7 ) ;
F_239 ( V_7 ) ;
}
#endif
}
}
void F_302 ( int V_92 , char * V_442 , int V_443 )
{
static unsigned int V_172 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_41 , V_444 ;
for ( V_41 = 0 , V_444 = 0 ; V_41 < F_26 ( V_172 ) ; V_41 ++ )
if ( V_92 & ( V_445 << V_41 ) )
V_444 += snprintf ( V_442 + V_444 , V_443 - V_444 , L_31 , V_172 [ V_41 ] ) ;
V_442 [ V_444 ] = '\0' ;
}
