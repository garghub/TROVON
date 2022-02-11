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
static unsigned int F_36 ( struct V_6 * V_7 , T_1 V_21 )
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
static int F_40 ( struct V_6 * V_7 , T_1 V_56 )
{
int V_41 ;
T_1 V_21 ;
V_7 -> V_45 = F_16 ( V_7 -> V_8 . V_57 * 4 , V_28 ) ;
if ( ! V_7 -> V_45 )
return - V_29 ;
V_21 = V_7 -> V_8 . V_58 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_8 . V_57 ; V_41 ++ , V_21 ++ )
V_7 -> V_45 [ V_41 ] = F_37 ( & V_7 -> V_8 ,
V_21 , V_59 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
T_1 V_21 ;
F_42 (nid, codec) {
struct V_60 * V_61 ;
unsigned int V_45 = F_35 ( V_7 , V_21 ) ;
unsigned int V_62 = F_34 ( V_45 ) ;
if ( V_62 != V_43 )
continue;
V_61 = F_43 ( & V_7 -> V_63 ) ;
if ( ! V_61 )
return - V_29 ;
V_61 -> V_21 = V_21 ;
V_61 -> V_64 = F_44 ( V_7 , V_21 , 0 ,
V_65 , 0 ) ;
V_61 -> V_66 = F_44 ( V_7 , V_21 , 0 ,
V_67 ,
0 ) ;
}
return 0 ;
}
static struct V_60 * F_45 ( struct V_6 * V_7 ,
struct V_68 * V_69 ,
T_1 V_21 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_69 -> V_70 ; V_41 ++ ) {
struct V_60 * V_61 = F_46 ( V_69 , V_41 ) ;
if ( V_61 -> V_21 == V_21 )
return V_61 ;
}
return NULL ;
}
int F_47 ( struct V_6 * V_7 , struct V_68 * V_27 ,
T_1 V_21 , unsigned int V_64 )
{
struct V_60 * V_61 ;
V_61 = F_45 ( V_7 , V_27 , V_21 ) ;
if ( ! V_61 ) {
V_61 = F_43 ( V_27 ) ;
if ( ! V_61 )
return - V_29 ;
V_61 -> V_21 = V_21 ;
}
V_61 -> V_64 = V_64 ;
return 0 ;
}
int F_48 ( struct V_6 * V_7 ,
T_1 V_21 , unsigned int V_64 )
{
return F_47 ( V_7 , & V_7 -> V_71 , V_21 , V_64 ) ;
}
unsigned int F_49 ( struct V_6 * V_7 , T_1 V_21 )
{
struct V_60 * V_61 ;
#ifdef F_50
{
unsigned int V_64 = 0 ;
F_4 ( & V_7 -> V_72 ) ;
V_61 = F_45 ( V_7 , & V_7 -> V_73 , V_21 ) ;
if ( V_61 )
V_64 = V_61 -> V_64 ;
F_6 ( & V_7 -> V_72 ) ;
if ( V_64 )
return V_64 ;
}
#endif
V_61 = F_45 ( V_7 , & V_7 -> V_71 , V_21 ) ;
if ( V_61 )
return V_61 -> V_64 ;
V_61 = F_45 ( V_7 , & V_7 -> V_63 , V_21 ) ;
if ( V_61 )
return V_61 -> V_64 ;
return 0 ;
}
int F_51 ( struct V_6 * V_7 , T_1 V_21 ,
unsigned int V_74 )
{
struct V_60 * V_61 ;
V_61 = F_45 ( V_7 , & V_7 -> V_63 , V_21 ) ;
if ( ! V_61 )
return - V_36 ;
V_61 -> V_75 = V_74 ;
return 0 ;
}
int F_52 ( struct V_6 * V_7 , T_1 V_21 )
{
struct V_60 * V_61 ;
V_61 = F_45 ( V_7 , & V_7 -> V_63 , V_21 ) ;
if ( ! V_61 )
return 0 ;
return V_61 -> V_75 ;
}
void F_53 ( struct V_6 * V_7 )
{
int V_41 ;
if ( V_7 -> V_10 -> V_76 )
return;
for ( V_41 = 0 ; V_41 < V_7 -> V_63 . V_70 ; V_41 ++ ) {
struct V_60 * V_61 = F_46 ( & V_7 -> V_63 , V_41 ) ;
F_44 ( V_7 , V_61 -> V_21 , 0 ,
V_77 , 0 ) ;
}
V_7 -> V_78 = 1 ;
}
static void F_54 ( struct V_6 * V_7 )
{
int V_41 ;
if ( ! V_7 -> V_78 )
return;
if ( V_7 -> V_10 -> V_76 )
return;
for ( V_41 = 0 ; V_41 < V_7 -> V_63 . V_70 ; V_41 ++ ) {
struct V_60 * V_61 = F_46 ( & V_7 -> V_63 , V_41 ) ;
F_12 ( V_7 , V_61 -> V_21 , 0 ,
V_77 ,
V_61 -> V_66 ) ;
}
V_7 -> V_78 = 0 ;
}
static void F_55 ( struct V_79 * V_80 )
{
struct V_6 * V_7 =
F_2 ( V_80 , struct V_6 , V_81 . V_80 ) ;
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
if ( ! V_7 -> V_82 )
return;
F_58 ( & V_7 -> V_81 ,
V_7 -> V_82 ) ;
}
static void F_59 ( struct V_6 * V_7 )
{
F_60 ( & V_7 -> V_71 ) ;
#ifdef F_50
F_60 ( & V_7 -> V_73 ) ;
#endif
F_60 ( & V_7 -> V_63 ) ;
}
static struct V_83 *
F_61 ( struct V_6 * V_7 , T_1 V_21 )
{
struct V_83 * V_25 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_84 . V_70 ; V_41 ++ ) {
V_25 = F_46 ( & V_7 -> V_84 , V_41 ) ;
if ( V_25 -> V_21 == V_21 )
return V_25 ;
}
V_25 = F_43 ( & V_7 -> V_84 ) ;
if ( V_25 )
V_25 -> V_21 = V_21 ;
return V_25 ;
}
static void F_62 ( struct V_85 * V_85 )
{
struct V_86 * V_87 = F_2 ( V_85 , struct V_86 , V_85 ) ;
if ( V_87 -> V_87 )
F_63 ( V_87 -> V_7 -> V_88 , V_87 -> V_87 ) ;
F_64 ( V_87 -> V_89 , V_87 -> V_7 -> V_10 -> V_90 ) ;
F_23 ( V_87 -> V_91 ) ;
F_23 ( V_87 ) ;
}
void F_65 ( struct V_86 * V_87 )
{
F_66 ( & V_87 -> V_85 , F_62 ) ;
}
struct V_86 * F_67 ( struct V_6 * V_7 ,
const char * V_92 , ... )
{
struct V_86 * V_87 ;
T_3 args ;
V_87 = F_68 ( sizeof( * V_87 ) , V_28 ) ;
if ( ! V_87 )
return NULL ;
V_87 -> V_7 = V_7 ;
F_69 ( & V_87 -> V_85 ) ;
va_start ( args , V_92 ) ;
V_87 -> V_91 = F_70 ( V_28 , V_92 , args ) ;
va_end ( args ) ;
if ( ! V_87 -> V_91 ) {
F_23 ( V_87 ) ;
return NULL ;
}
F_71 ( & V_87 -> V_27 , & V_7 -> V_93 ) ;
return V_87 ;
}
static void F_72 ( struct V_6 * V_7 )
{
struct V_86 * V_87 , * V_94 ;
F_73 (pcm, n, &codec->pcm_list_head, list) {
F_74 ( & V_87 -> V_27 ) ;
if ( V_87 -> V_87 )
F_75 ( V_7 -> V_88 , V_87 -> V_87 ) ;
F_65 ( V_87 ) ;
}
}
void F_76 ( struct V_6 * V_7 )
{
if ( V_7 -> V_95 ) {
F_77 ( F_78 ( V_7 ) ) ;
F_79 ( F_78 ( V_7 ) ) ;
V_7 -> V_95 = 0 ;
}
F_80 ( & V_7 -> V_81 ) ;
if ( ! V_7 -> V_96 )
F_81 ( V_7 ) ;
F_72 ( V_7 ) ;
F_82 ( V_7 ) ;
memset ( & V_7 -> V_97 , 0 , sizeof( V_7 -> V_97 ) ) ;
F_83 ( V_7 ) ;
V_7 -> V_98 = NULL ;
V_7 -> V_99 = NULL ;
F_60 ( & V_7 -> V_71 ) ;
F_60 ( & V_7 -> V_84 ) ;
F_60 ( & V_7 -> V_100 ) ;
F_60 ( & V_7 -> V_101 ) ;
V_7 -> V_102 = NULL ;
V_7 -> V_103 = NULL ;
V_7 -> V_104 = 0 ;
F_60 ( & V_7 -> V_105 ) ;
F_60 ( & V_7 -> V_106 ) ;
F_18 ( V_7 ) ;
F_84 ( & V_7 -> V_8 ) ;
}
void F_85 ( struct V_6 * V_7 )
{
if ( V_7 -> V_95 )
return;
if ( F_86 ( F_78 ( V_7 ) ) ) {
F_87 ( V_7 ) ;
F_88 ( & V_7 -> V_8 , true ) ;
F_89 ( F_78 ( V_7 ) ) ;
F_90 ( V_7 ) ;
V_7 -> V_95 = 1 ;
}
}
static int F_91 ( struct V_107 * V_89 )
{
F_85 ( V_89 -> V_108 ) ;
return 0 ;
}
static int F_92 ( struct V_107 * V_89 )
{
struct V_6 * V_7 = V_89 -> V_108 ;
F_82 ( V_7 ) ;
return 0 ;
}
static int F_93 ( struct V_107 * V_89 )
{
struct V_6 * V_7 = V_89 -> V_108 ;
V_7 -> V_96 = 1 ;
F_94 ( & V_7 -> V_8 ) ;
F_88 ( & V_7 -> V_8 , false ) ;
F_95 ( F_78 ( V_7 ) ) ;
return 0 ;
}
static void F_96 ( struct V_89 * V_2 )
{
struct V_6 * V_7 = F_97 ( V_2 ) ;
F_59 ( V_7 ) ;
F_98 ( & V_7 -> V_8 ) ;
F_99 ( V_7 ) ;
F_23 ( V_7 -> V_109 ) ;
F_23 ( V_7 -> V_45 ) ;
F_23 ( V_7 ) ;
}
int F_100 ( struct V_9 * V_10 , struct V_110 * V_88 ,
unsigned int V_111 , struct V_6 * * V_112 )
{
struct V_6 * V_7 ;
char V_113 [ 31 ] ;
T_1 V_114 ;
int V_11 ;
static struct V_115 V_116 = {
. V_117 = F_91 ,
. V_118 = F_92 ,
. V_119 = F_93 ,
} ;
if ( F_30 ( ! V_10 ) )
return - V_36 ;
if ( F_30 ( V_111 > V_120 ) )
return - V_36 ;
V_7 = F_68 ( sizeof( * V_7 ) , V_28 ) ;
if ( ! V_7 )
return - V_29 ;
sprintf ( V_113 , L_4 , V_88 -> V_121 , V_111 ) ;
V_11 = F_101 ( & V_7 -> V_8 , & V_10 -> V_8 , V_113 ,
V_111 ) ;
if ( V_11 < 0 ) {
F_23 ( V_7 ) ;
return V_11 ;
}
V_7 -> V_8 . V_2 . V_122 = F_96 ;
V_7 -> V_8 . type = V_123 ;
V_7 -> V_8 . V_124 = F_1 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_88 = V_88 ;
V_7 -> V_16 = V_111 ;
F_102 ( & V_7 -> V_125 ) ;
F_102 ( & V_7 -> V_126 ) ;
F_103 ( & V_7 -> V_105 , sizeof( struct V_127 ) , 32 ) ;
F_103 ( & V_7 -> V_106 , sizeof( struct V_127 ) , 32 ) ;
F_103 ( & V_7 -> V_63 , sizeof( struct V_60 ) , 16 ) ;
F_103 ( & V_7 -> V_71 , sizeof( struct V_60 ) , 16 ) ;
F_103 ( & V_7 -> V_84 , sizeof( struct V_83 ) , 8 ) ;
F_103 ( & V_7 -> V_100 , sizeof( struct V_128 ) , 16 ) ;
F_103 ( & V_7 -> V_129 , sizeof( struct V_130 ) , 16 ) ;
F_103 ( & V_7 -> V_101 , sizeof( struct V_19 * ) , 8 ) ;
F_104 ( & V_7 -> V_31 ) ;
F_104 ( & V_7 -> V_93 ) ;
F_105 ( & V_7 -> V_81 , F_55 ) ;
V_7 -> V_131 = - 1 ;
V_7 -> V_132 = V_133 ;
#ifdef F_106
V_7 -> V_134 = V_135 ;
#endif
F_107 ( V_7 ) ;
if ( V_7 -> V_10 -> V_109 ) {
V_7 -> V_109 = F_108 ( V_7 -> V_10 -> V_109 , V_28 ) ;
if ( ! V_7 -> V_109 ) {
V_11 = - V_29 ;
goto error;
}
}
V_114 = V_7 -> V_8 . V_136 ? V_7 -> V_8 . V_136 : V_7 -> V_8 . V_137 ;
V_11 = F_40 ( V_7 , V_114 ) ;
if ( V_11 < 0 )
goto error;
V_11 = F_41 ( V_7 ) ;
if ( V_11 < 0 )
goto error;
F_109 ( V_7 , V_138 ) ;
F_110 ( V_7 ) ;
F_111 ( V_7 ) ;
sprintf ( V_113 , L_5 , V_7 -> V_8 . V_139 ,
V_7 -> V_8 . V_140 , V_7 -> V_8 . V_141 ) ;
F_112 ( V_88 , V_113 ) ;
V_11 = F_113 ( V_88 , V_142 , V_7 , & V_116 ) ;
if ( V_11 < 0 )
goto error;
if ( V_112 )
* V_112 = V_7 ;
return 0 ;
error:
F_95 ( F_78 ( V_7 ) ) ;
return V_11 ;
}
int F_114 ( struct V_6 * V_7 )
{
T_1 V_114 ;
int V_11 ;
V_11 = F_115 ( & V_7 -> V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
F_23 ( V_7 -> V_45 ) ;
V_114 = V_7 -> V_8 . V_136 ? V_7 -> V_8 . V_136 : V_7 -> V_8 . V_137 ;
V_11 = F_40 ( V_7 , V_114 ) ;
if ( V_11 < 0 )
return V_11 ;
F_60 ( & V_7 -> V_63 ) ;
V_11 = F_41 ( V_7 ) ;
return V_11 ;
}
static void F_116 ( struct V_6 * V_7 ,
struct V_83 * V_25 , T_1 V_21 ,
T_4 V_143 , int V_144 )
{
unsigned int V_145 , V_146 ;
if ( V_25 -> V_143 != V_143 || V_25 -> V_144 != V_144 ) {
V_145 = F_44 ( V_7 , V_21 , 0 , V_147 , 0 ) ;
V_146 = ( V_143 << 4 ) | V_144 ;
if ( V_145 != V_146 )
F_12 ( V_7 , V_21 , 0 ,
V_148 ,
V_146 ) ;
V_25 -> V_143 = V_143 ;
V_25 -> V_144 = V_144 ;
}
}
static void F_117 ( struct V_6 * V_7 , struct V_83 * V_25 ,
T_1 V_21 , int V_149 )
{
unsigned int V_145 ;
if ( V_25 -> V_150 != V_149 ) {
V_145 = F_44 ( V_7 , V_21 , 0 ,
V_151 , 0 ) ;
if ( V_145 != V_149 ) {
F_118 ( 1 ) ;
F_12 ( V_7 , V_21 , 0 ,
V_152 ,
V_149 ) ;
}
V_25 -> V_150 = V_149 ;
}
}
void F_119 ( struct V_6 * V_7 , T_1 V_21 ,
T_4 V_143 ,
int V_144 , int V_149 )
{
struct V_6 * V_153 ;
struct V_83 * V_25 ;
int type ;
int V_41 ;
if ( ! V_21 )
return;
F_9 ( V_7 ,
L_6 ,
V_21 , V_143 , V_144 , V_149 ) ;
V_25 = F_61 ( V_7 , V_21 ) ;
if ( ! V_25 )
return;
if ( V_7 -> V_97 . V_154 )
V_7 -> V_97 . V_154 ( V_7 , V_21 , true ) ;
if ( V_7 -> V_155 )
F_117 ( V_7 , V_25 , V_21 , V_149 ) ;
F_116 ( V_7 , V_25 , V_21 , V_143 , V_144 ) ;
if ( ! V_7 -> V_155 )
F_117 ( V_7 , V_25 , V_21 , V_149 ) ;
V_25 -> V_156 = 1 ;
V_25 -> V_157 = 0 ;
type = F_34 ( F_35 ( V_7 , V_21 ) ) ;
F_120 (c, codec->bus) {
for ( V_41 = 0 ; V_41 < V_153 -> V_84 . V_70 ; V_41 ++ ) {
V_25 = F_46 ( & V_153 -> V_84 , V_41 ) ;
if ( ! V_25 -> V_156 && V_25 -> V_143 == V_143 &&
F_34 ( F_35 ( V_153 , V_25 -> V_21 ) ) == type )
V_25 -> V_157 = 1 ;
}
}
}
void F_121 ( struct V_6 * V_7 , T_1 V_21 ,
int V_158 )
{
struct V_83 * V_25 ;
if ( ! V_21 )
return;
if ( V_7 -> V_159 )
V_158 = 1 ;
F_9 ( V_7 , L_7 , V_21 ) ;
V_25 = F_61 ( V_7 , V_21 ) ;
if ( V_25 ) {
if ( V_158 )
F_122 ( V_7 , V_25 ) ;
else
V_25 -> V_156 = 0 ;
}
}
static void F_122 ( struct V_6 * V_7 ,
struct V_83 * V_160 )
{
T_1 V_21 = V_160 -> V_21 ;
if ( V_160 -> V_143 || V_160 -> V_144 )
F_12 ( V_7 , V_21 , 0 , V_148 , 0 ) ;
if ( V_160 -> V_150 )
F_12 ( V_7 , V_21 , 0 , V_152 , 0
) ;
memset ( V_160 , 0 , sizeof( * V_160 ) ) ;
V_160 -> V_21 = V_21 ;
if ( V_7 -> V_97 . V_154 )
V_7 -> V_97 . V_154 ( V_7 , V_21 , false ) ;
}
static void F_123 ( struct V_6 * V_7 )
{
struct V_6 * V_153 ;
int V_41 ;
F_120 (c, codec->bus) {
for ( V_41 = 0 ; V_41 < V_153 -> V_84 . V_70 ; V_41 ++ ) {
struct V_83 * V_25 ;
V_25 = F_46 ( & V_153 -> V_84 , V_41 ) ;
if ( V_25 -> V_157 )
F_122 ( V_153 , V_25 ) ;
}
}
}
static void F_124 ( struct V_6 * V_7 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_84 . V_70 ; V_41 ++ ) {
struct V_83 * V_25 = F_46 ( & V_7 -> V_84 , V_41 ) ;
if ( V_25 -> V_143 )
F_122 ( V_7 , V_25 ) ;
}
}
T_4 F_125 ( struct V_6 * V_7 , T_1 V_21 , int V_161 )
{
if ( ! ( F_35 ( V_7 , V_21 ) & V_162 ) )
V_21 = V_7 -> V_8 . V_136 ;
return F_126 ( V_7 , V_21 ,
V_161 == V_163 ?
V_164 : V_165 ) ;
}
bool F_127 ( struct V_6 * V_7 , T_1 V_21 ,
int V_166 , unsigned int V_167 )
{
if ( ! V_21 )
return false ;
if ( F_35 ( V_7 , V_21 ) & ( 1 << ( V_166 + 1 ) ) )
if ( F_125 ( V_7 , V_21 , V_166 ) & V_167 )
return true ;
return false ;
}
int F_128 ( struct V_6 * V_7 , T_1 V_21 , int V_166 ,
unsigned int V_168 )
{
unsigned int V_46 ;
F_129 ( V_7 , V_21 ,
F_35 ( V_7 , V_21 ) | V_162 ) ;
V_46 = V_166 == V_163 ? V_164 : V_165 ;
return F_130 ( & V_7 -> V_8 , V_21 , V_46 , V_168 ) ;
}
int F_131 ( struct V_6 * V_7 , T_1 V_21 ,
int V_169 , int V_166 , int V_170 , int V_171 , int V_74 )
{
unsigned int V_3 = F_132 ( V_21 , V_169 , V_166 , V_170 ) ;
if ( ( F_125 ( V_7 , V_21 , V_166 ) &
( V_172 | V_173 ) ) == V_173 )
V_3 |= V_174 ;
return F_133 ( & V_7 -> V_8 , V_3 , V_171 , V_74 ) ;
}
int F_134 ( struct V_6 * V_7 , T_1 V_21 ,
int V_161 , int V_170 , int V_171 , int V_74 )
{
int V_169 , V_175 = 0 ;
if ( F_30 ( V_171 & ~ 0xff ) )
V_171 &= 0xff ;
for ( V_169 = 0 ; V_169 < 2 ; V_169 ++ )
V_175 |= F_131 ( V_7 , V_21 , V_169 , V_161 ,
V_170 , V_171 , V_74 ) ;
return V_175 ;
}
int F_135 ( struct V_6 * V_7 , T_1 V_21 , int V_169 ,
int V_166 , int V_170 , int V_171 , int V_74 )
{
int V_176 ;
if ( ! V_7 -> V_8 . V_177 )
return - V_36 ;
F_136 ( V_7 -> V_8 . V_177 , true ) ;
V_176 = F_137 ( V_7 , V_21 , V_169 , V_166 , V_170 ) ;
F_136 ( V_7 -> V_8 . V_177 , false ) ;
if ( V_176 >= 0 )
return 0 ;
return F_131 ( V_7 , V_21 , V_169 , V_166 , V_170 , V_171 , V_74 ) ;
}
int F_138 ( struct V_6 * V_7 , T_1 V_21 ,
int V_166 , int V_170 , int V_171 , int V_74 )
{
int V_169 , V_175 = 0 ;
if ( F_30 ( V_171 & ~ 0xff ) )
V_171 &= 0xff ;
for ( V_169 = 0 ; V_169 < 2 ; V_169 ++ )
V_175 |= F_135 ( V_7 , V_21 , V_169 , V_166 ,
V_170 , V_171 , V_74 ) ;
return V_175 ;
}
static T_4 F_139 ( struct V_6 * V_7 , T_1 V_21 , int V_166 ,
unsigned int V_178 )
{
T_4 V_168 = F_125 ( V_7 , V_21 , V_166 ) ;
V_168 = ( V_168 & V_179 ) >> V_180 ;
if ( V_178 < V_168 )
V_168 -= V_178 ;
return V_168 ;
}
int F_140 ( struct V_181 * V_182 ,
struct V_183 * V_184 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_5 V_21 = F_142 ( V_182 ) ;
T_2 V_185 = F_143 ( V_182 ) ;
int V_166 = F_144 ( V_182 ) ;
unsigned int V_178 = F_145 ( V_182 ) ;
V_184 -> type = V_186 ;
V_184 -> V_187 = V_185 == 3 ? 2 : 1 ;
V_184 -> V_188 . integer . V_189 = 0 ;
V_184 -> V_188 . integer . V_190 = F_139 ( V_7 , V_21 , V_166 , V_178 ) ;
if ( ! V_184 -> V_188 . integer . V_190 ) {
F_146 ( V_7 ,
L_8 ,
V_21 , V_182 -> V_191 . V_91 ) ;
return - V_36 ;
}
return 0 ;
}
static inline unsigned int
F_147 ( struct V_6 * V_7 , T_1 V_21 ,
int V_169 , int V_166 , int V_170 , unsigned int V_178 )
{
unsigned int V_74 ;
V_74 = F_137 ( V_7 , V_21 , V_169 , V_166 , V_170 ) ;
V_74 &= V_192 ;
if ( V_74 >= V_178 )
V_74 -= V_178 ;
else
V_74 = 0 ;
return V_74 ;
}
static inline int
F_148 ( struct V_6 * V_7 , T_1 V_21 ,
int V_169 , int V_166 , int V_170 , unsigned int V_178 ,
unsigned int V_74 )
{
unsigned int V_193 ;
if ( V_74 > 0 )
V_74 += V_178 ;
V_193 = F_139 ( V_7 , V_21 , V_166 , 0 ) ;
if ( V_74 > V_193 )
V_74 = V_193 ;
return F_131 ( V_7 , V_21 , V_169 , V_166 , V_170 ,
V_192 , V_74 ) ;
}
int F_149 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_1 V_21 = F_142 ( V_182 ) ;
int V_185 = F_143 ( V_182 ) ;
int V_166 = F_144 ( V_182 ) ;
int V_170 = F_150 ( V_182 ) ;
unsigned int V_178 = F_145 ( V_182 ) ;
long * V_196 = V_195 -> V_188 . integer . V_188 ;
if ( V_185 & 1 )
* V_196 ++ = F_147 ( V_7 , V_21 , 0 , V_166 , V_170 , V_178 ) ;
if ( V_185 & 2 )
* V_196 = F_147 ( V_7 , V_21 , 1 , V_166 , V_170 , V_178 ) ;
return 0 ;
}
int F_151 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_1 V_21 = F_142 ( V_182 ) ;
int V_185 = F_143 ( V_182 ) ;
int V_166 = F_144 ( V_182 ) ;
int V_170 = F_150 ( V_182 ) ;
unsigned int V_178 = F_145 ( V_182 ) ;
long * V_196 = V_195 -> V_188 . integer . V_188 ;
int V_197 = 0 ;
if ( V_185 & 1 ) {
V_197 = F_148 ( V_7 , V_21 , 0 , V_166 , V_170 , V_178 , * V_196 ) ;
V_196 ++ ;
}
if ( V_185 & 2 )
V_197 |= F_148 ( V_7 , V_21 , 1 , V_166 , V_170 , V_178 , * V_196 ) ;
return V_197 ;
}
int F_152 ( struct V_181 * V_182 , int V_198 ,
unsigned int V_199 , unsigned int T_6 * V_200 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_1 V_21 = F_142 ( V_182 ) ;
int V_166 = F_144 ( V_182 ) ;
unsigned int V_178 = F_145 ( V_182 ) ;
bool V_201 = F_153 ( V_182 ) ;
T_4 V_168 , V_202 , V_203 ;
if ( V_199 < 4 * sizeof( unsigned int ) )
return - V_29 ;
V_168 = F_125 ( V_7 , V_21 , V_166 ) ;
V_203 = ( V_168 & V_204 ) >> V_205 ;
V_203 = ( V_203 + 1 ) * 25 ;
V_202 = - ( ( V_168 & V_206 ) >> V_207 ) ;
V_202 += V_178 ;
V_202 = ( ( int ) V_202 ) * ( ( int ) V_203 ) ;
if ( V_201 || ( V_168 & V_173 ) )
V_203 |= V_208 ;
if ( F_154 ( V_209 , V_200 ) )
return - V_210 ;
if ( F_154 ( 2 * sizeof( unsigned int ) , V_200 + 1 ) )
return - V_210 ;
if ( F_154 ( V_202 , V_200 + 2 ) )
return - V_210 ;
if ( F_154 ( V_203 , V_200 + 3 ) )
return - V_210 ;
return 0 ;
}
void F_155 ( struct V_6 * V_7 , T_1 V_21 , int V_166 ,
unsigned int * V_211 )
{
T_4 V_168 ;
int V_42 , V_212 ;
V_168 = F_125 ( V_7 , V_21 , V_166 ) ;
V_42 = ( V_168 & V_179 ) >> V_180 ;
V_212 = ( V_168 & V_204 ) >> V_205 ;
V_212 = ( V_212 + 1 ) * 25 ;
V_211 [ 0 ] = V_209 ;
V_211 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_211 [ 2 ] = - V_42 * V_212 ;
V_211 [ 3 ] = V_212 ;
}
static struct V_181 *
F_156 ( struct V_6 * V_7 , const char * V_91 , int V_2 , int V_170 )
{
struct V_213 V_191 ;
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
V_191 . V_214 = V_215 ;
V_191 . V_89 = V_2 ;
V_191 . V_216 = V_170 ;
if ( F_30 ( strlen ( V_91 ) >= sizeof( V_191 . V_91 ) ) )
return NULL ;
strcpy ( V_191 . V_91 , V_91 ) ;
return F_157 ( V_7 -> V_88 , & V_191 ) ;
}
struct V_181 * F_158 ( struct V_6 * V_7 ,
const char * V_91 )
{
return F_156 ( V_7 , V_91 , 0 , 0 ) ;
}
static int F_159 ( struct V_6 * V_7 , const char * V_91 ,
int V_217 )
{
int V_41 , V_170 ;
for ( V_41 = 0 , V_170 = V_217 ; V_41 < 16 ; V_41 ++ , V_170 ++ ) {
if ( ! F_156 ( V_7 , V_91 , 0 , V_170 ) )
return V_170 ;
}
return - V_218 ;
}
int F_160 ( struct V_6 * V_7 , T_1 V_21 ,
struct V_181 * V_219 )
{
int V_11 ;
unsigned short V_4 = 0 ;
struct V_127 * V_220 ;
if ( V_219 -> V_191 . V_221 & V_222 ) {
V_4 |= V_223 ;
if ( V_21 == 0 )
V_21 = F_161 ( V_219 -> V_224 ) ;
}
if ( ( V_219 -> V_191 . V_221 & V_225 ) != 0 && V_21 == 0 )
V_21 = V_219 -> V_191 . V_221 & 0xffff ;
if ( V_219 -> V_191 . V_221 & ( V_225 | V_222 ) )
V_219 -> V_191 . V_221 = 0 ;
V_11 = F_162 ( V_7 -> V_88 , V_219 ) ;
if ( V_11 < 0 )
return V_11 ;
V_220 = F_43 ( & V_7 -> V_105 ) ;
if ( ! V_220 )
return - V_29 ;
V_220 -> V_219 = V_219 ;
V_220 -> V_21 = V_21 ;
V_220 -> V_4 = V_4 ;
return 0 ;
}
int F_163 ( struct V_6 * V_7 , struct V_181 * V_219 ,
unsigned int V_216 , T_1 V_21 )
{
struct V_127 * V_220 ;
if ( V_21 > 0 ) {
V_220 = F_43 ( & V_7 -> V_106 ) ;
if ( ! V_220 )
return - V_29 ;
V_220 -> V_219 = V_219 ;
V_220 -> V_216 = V_216 ;
V_220 -> V_21 = V_21 ;
return 0 ;
}
F_32 ( V_7 , L_9 ,
V_219 -> V_191 . V_91 , V_219 -> V_191 . V_216 , V_216 ) ;
return - V_36 ;
}
void F_81 ( struct V_6 * V_7 )
{
int V_41 ;
struct V_127 * V_226 = V_7 -> V_105 . V_27 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_105 . V_70 ; V_41 ++ )
F_164 ( V_7 -> V_88 , V_226 [ V_41 ] . V_219 ) ;
F_60 ( & V_7 -> V_105 ) ;
F_60 ( & V_7 -> V_106 ) ;
}
int F_165 ( struct V_9 * V_10 )
{
struct V_110 * V_88 = V_10 -> V_88 ;
struct V_6 * V_7 ;
F_166 ( & V_88 -> V_227 ) ;
if ( V_88 -> V_76 )
goto V_228;
V_88 -> V_76 = 1 ;
if ( ! F_19 ( & V_88 -> V_229 ) )
goto V_230;
F_120 (codec, bus) {
struct V_86 * V_231 ;
F_14 (cpcm, &codec->pcm_list_head, list) {
if ( ! V_231 -> V_87 )
continue;
if ( V_231 -> V_87 -> V_232 [ 0 ] . V_233 ||
V_231 -> V_87 -> V_232 [ 1 ] . V_233 )
goto V_230;
}
}
F_167 ( & V_88 -> V_227 ) ;
return 0 ;
V_230:
V_88 -> V_76 = 0 ;
V_228:
F_167 ( & V_88 -> V_227 ) ;
return - V_36 ;
}
void F_168 ( struct V_9 * V_10 )
{
struct V_110 * V_88 = V_10 -> V_88 ;
F_166 ( & V_88 -> V_227 ) ;
V_88 -> V_76 = 0 ;
F_167 ( & V_88 -> V_227 ) ;
}
int F_169 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
if ( F_165 ( V_10 ) < 0 )
return - V_218 ;
F_94 ( & V_7 -> V_8 ) ;
F_168 ( V_10 ) ;
return 0 ;
}
static int F_170 ( struct V_6 * V_7 , const char * const * V_234 ,
const char * V_235 , T_7 V_236 , void * V_237 )
{
struct V_127 * V_226 ;
const char * const * V_238 ;
int V_41 , V_11 ;
V_226 = V_7 -> V_105 . V_27 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_105 . V_70 ; V_41 ++ ) {
struct V_181 * V_239 = V_226 [ V_41 ] . V_219 ;
if ( ! V_239 || V_239 -> V_191 . V_214 != V_215 )
continue;
for ( V_238 = V_234 ; * V_238 ; V_238 ++ ) {
char V_240 [ sizeof( V_239 -> V_191 . V_91 ) ] ;
const char * V_91 = * V_238 ;
if ( V_235 ) {
snprintf ( V_240 , sizeof( V_240 ) , L_10 ,
V_91 , V_235 ) ;
V_91 = V_240 ;
}
if ( ! strcmp ( V_239 -> V_191 . V_91 , V_91 ) ) {
V_11 = V_236 ( V_7 , V_237 , V_239 ) ;
if ( V_11 )
return V_11 ;
break;
}
}
}
return 0 ;
}
static int F_171 ( struct V_6 * V_7 ,
void * V_237 , struct V_181 * V_239 )
{
return 1 ;
}
static int F_172 ( struct V_6 * V_7 ,
struct V_181 * V_219 , int * V_241 )
{
int V_200 [ 4 ] ;
const int * V_211 = NULL ;
int V_74 = - 1 ;
if ( V_219 -> V_242 [ 0 ] . V_243 & V_244 ) {
T_8 V_245 = F_173 () ;
F_174 ( F_175 () ) ;
if ( ! V_219 -> V_211 . V_153 ( V_219 , 0 , sizeof( V_200 ) , V_200 ) )
V_211 = V_200 ;
F_174 ( V_245 ) ;
} else if ( V_219 -> V_242 [ 0 ] . V_243 & V_246 )
V_211 = V_219 -> V_211 . V_25 ;
if ( V_211 && V_211 [ 0 ] == V_209 ) {
int V_212 = V_211 [ 3 ] ;
V_212 &= ~ V_208 ;
if ( ! V_212 )
return - 1 ;
if ( * V_241 && * V_241 != V_212 ) {
F_32 ( V_7 , L_11 ,
- * V_241 , V_212 ) ;
return - 1 ;
}
* V_241 = V_212 ;
V_74 = - V_211 [ 2 ] / V_212 ;
}
return V_74 ;
}
static int F_176 ( struct V_181 * V_219 , int V_74 )
{
struct V_194 * V_195 ;
V_195 = F_68 ( sizeof( * V_195 ) , V_28 ) ;
if ( ! V_195 )
return - V_29 ;
V_195 -> V_188 . integer . V_188 [ 0 ] = V_74 ;
V_195 -> V_188 . integer . V_188 [ 1 ] = V_74 ;
V_219 -> V_247 ( V_219 , V_195 ) ;
F_23 ( V_195 ) ;
return 0 ;
}
static int F_177 ( struct V_6 * V_7 ,
void * V_237 , struct V_181 * V_248 )
{
int V_249 = F_172 ( V_7 , V_248 , V_237 ) ;
if ( V_249 > 0 )
F_176 ( V_248 , V_249 ) ;
return 0 ;
}
static int F_178 ( struct V_6 * V_7 ,
void * V_237 , struct V_181 * V_248 )
{
return F_176 ( V_248 , 1 ) ;
}
static int F_179 ( struct V_6 * V_7 ,
void * V_237 , struct V_181 * V_248 )
{
return F_180 ( V_237 , V_248 ) ;
}
int F_181 ( struct V_6 * V_7 , char * V_91 ,
unsigned int * V_211 , const char * const * V_234 ,
const char * V_235 , bool V_250 ,
struct V_181 * * V_251 )
{
struct V_181 * V_219 ;
int V_11 ;
if ( V_251 )
* V_251 = NULL ;
V_11 = F_170 ( V_7 , V_234 , V_235 , F_171 , NULL ) ;
if ( V_11 != 1 ) {
F_9 ( V_7 , L_12 , V_91 ) ;
return 0 ;
}
V_219 = F_182 ( V_91 , V_211 ) ;
if ( ! V_219 )
return - V_29 ;
V_11 = F_160 ( V_7 , 0 , V_219 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_170 ( V_7 , V_234 , V_235 , F_179 , V_219 ) ;
if ( V_11 < 0 )
return V_11 ;
F_176 ( V_219 , 0 ) ;
if ( V_250 ) {
int V_212 = 0 ;
F_170 ( V_7 , V_234 , V_235 ,
V_211 ? F_177 : F_178 , & V_212 ) ;
}
if ( V_251 )
* V_251 = V_219 ;
return 0 ;
}
static int F_183 ( struct V_181 * V_182 ,
struct V_183 * V_184 )
{
static const char * const V_252 [] = {
L_13 , L_14 , L_15
} ;
return F_184 ( V_184 , 1 , 3 , V_252 ) ;
}
static int F_185 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_253 * V_254 = F_141 ( V_182 ) ;
V_195 -> V_188 . V_255 . V_220 [ 0 ] = V_254 -> V_256 ;
return 0 ;
}
static int F_186 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_253 * V_254 = F_141 ( V_182 ) ;
unsigned int V_257 = V_254 -> V_256 ;
V_254 -> V_256 = V_195 -> V_188 . V_255 . V_220 [ 0 ] ;
if ( V_254 -> V_256 > V_258 )
V_254 -> V_256 = V_258 ;
if ( V_257 == V_254 -> V_256 )
return 0 ;
F_187 ( V_254 ) ;
return 1 ;
}
static void F_188 ( void * V_259 , int V_260 )
{
struct V_253 * V_254 = V_259 ;
if ( V_254 -> V_256 != V_258 )
V_260 = V_254 -> V_256 ;
V_254 -> V_254 ( V_254 -> V_7 , V_260 ) ;
}
int F_189 ( struct V_6 * V_7 ,
struct V_253 * V_254 ,
bool V_261 )
{
struct V_181 * V_219 ;
if ( ! V_254 -> V_254 || ! V_254 -> V_262 )
return 0 ;
V_254 -> V_7 = V_7 ;
V_254 -> V_256 = V_258 ;
F_190 ( V_254 -> V_262 , F_188 , V_254 ) ;
if ( ! V_261 )
return 0 ;
V_219 = F_191 ( & V_263 , V_254 ) ;
if ( ! V_219 )
return - V_29 ;
return F_160 ( V_7 , 0 , V_219 ) ;
}
void F_187 ( struct V_253 * V_254 )
{
if ( ! V_254 -> V_254 || ! V_254 -> V_7 )
return;
if ( V_254 -> V_7 -> V_10 -> V_76 )
return;
F_192 ( V_254 -> V_262 ) ;
}
int F_193 ( struct V_181 * V_182 ,
struct V_183 * V_184 )
{
int V_185 = F_143 ( V_182 ) ;
V_184 -> type = V_264 ;
V_184 -> V_187 = V_185 == 3 ? 2 : 1 ;
V_184 -> V_188 . integer . V_189 = 0 ;
V_184 -> V_188 . integer . V_190 = 1 ;
return 0 ;
}
int F_194 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_1 V_21 = F_142 ( V_182 ) ;
int V_185 = F_143 ( V_182 ) ;
int V_166 = F_144 ( V_182 ) ;
int V_170 = F_150 ( V_182 ) ;
long * V_196 = V_195 -> V_188 . integer . V_188 ;
if ( V_185 & 1 )
* V_196 ++ = ( F_137 ( V_7 , V_21 , 0 , V_166 , V_170 ) &
V_265 ) ? 0 : 1 ;
if ( V_185 & 2 )
* V_196 = ( F_137 ( V_7 , V_21 , 1 , V_166 , V_170 ) &
V_265 ) ? 0 : 1 ;
return 0 ;
}
int F_195 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_1 V_21 = F_142 ( V_182 ) ;
int V_185 = F_143 ( V_182 ) ;
int V_166 = F_144 ( V_182 ) ;
int V_170 = F_150 ( V_182 ) ;
long * V_196 = V_195 -> V_188 . integer . V_188 ;
int V_197 = 0 ;
if ( V_185 & 1 ) {
V_197 = F_131 ( V_7 , V_21 , 0 , V_166 , V_170 ,
V_265 ,
* V_196 ? 0 : V_265 ) ;
V_196 ++ ;
}
if ( V_185 & 2 )
V_197 |= F_131 ( V_7 , V_21 , 1 , V_166 , V_170 ,
V_265 ,
* V_196 ? 0 : V_265 ) ;
F_196 ( V_7 , V_21 ) ;
return V_197 ;
}
int F_197 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
unsigned long V_266 ;
int V_11 ;
F_4 ( & V_7 -> V_126 ) ;
V_266 = V_182 -> V_224 ;
V_182 -> V_224 = V_266 & ~ V_267 ;
V_11 = F_194 ( V_182 , V_195 ) ;
V_182 -> V_224 = V_266 ;
F_6 ( & V_7 -> V_126 ) ;
return V_11 ;
}
int F_198 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
unsigned long V_266 ;
int V_41 , V_268 , V_11 = 0 , V_197 = 0 ;
F_4 ( & V_7 -> V_126 ) ;
V_266 = V_182 -> V_224 ;
V_268 = ( V_266 & V_267 ) >> V_269 ;
for ( V_41 = 0 ; V_41 < V_268 ; V_41 ++ ) {
V_182 -> V_224 = ( V_266 & ~ V_267 ) |
( V_41 << V_269 ) ;
V_11 = F_195 ( V_182 , V_195 ) ;
if ( V_11 < 0 )
break;
V_197 |= V_11 ;
}
V_182 -> V_224 = V_266 ;
F_6 ( & V_7 -> V_126 ) ;
return V_11 < 0 ? V_11 : V_197 ;
}
int F_199 ( struct V_181 * V_182 ,
struct V_183 * V_184 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
struct V_270 * V_153 ;
int V_11 ;
F_4 ( & V_7 -> V_126 ) ;
V_153 = (struct V_270 * ) V_182 -> V_224 ;
V_182 -> V_224 = * V_153 -> V_271 ;
V_11 = V_153 -> V_272 -> V_273 ( V_182 , V_184 ) ;
V_182 -> V_224 = ( long ) V_153 ;
F_6 ( & V_7 -> V_126 ) ;
return V_11 ;
}
int F_200 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
struct V_270 * V_153 ;
int V_11 ;
F_4 ( & V_7 -> V_126 ) ;
V_153 = (struct V_270 * ) V_182 -> V_224 ;
V_182 -> V_224 = * V_153 -> V_271 ;
V_11 = V_153 -> V_272 -> V_274 ( V_182 , V_195 ) ;
V_182 -> V_224 = ( long ) V_153 ;
F_6 ( & V_7 -> V_126 ) ;
return V_11 ;
}
int F_201 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
struct V_270 * V_153 ;
unsigned long * V_275 ;
int V_11 = 0 , V_197 = 0 ;
F_4 ( & V_7 -> V_126 ) ;
V_153 = (struct V_270 * ) V_182 -> V_224 ;
for ( V_275 = V_153 -> V_271 ; * V_275 ; V_275 ++ ) {
V_182 -> V_224 = * V_275 ;
V_11 = V_153 -> V_272 -> V_247 ( V_182 , V_195 ) ;
if ( V_11 < 0 )
break;
V_197 |= V_11 ;
}
V_182 -> V_224 = ( long ) V_153 ;
F_6 ( & V_7 -> V_126 ) ;
return V_11 < 0 ? V_11 : V_197 ;
}
int F_202 ( struct V_181 * V_182 , int V_198 ,
unsigned int V_199 , unsigned int T_6 * V_211 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
struct V_270 * V_153 ;
int V_11 ;
F_4 ( & V_7 -> V_126 ) ;
V_153 = (struct V_270 * ) V_182 -> V_224 ;
V_182 -> V_224 = * V_153 -> V_271 ;
V_11 = V_153 -> V_272 -> V_211 ( V_182 , V_198 , V_199 , V_211 ) ;
V_182 -> V_224 = ( long ) V_153 ;
F_6 ( & V_7 -> V_126 ) ;
return V_11 ;
}
static int F_203 ( struct V_181 * V_182 ,
struct V_183 * V_184 )
{
V_184 -> type = V_276 ;
V_184 -> V_187 = 1 ;
return 0 ;
}
static int F_204 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
V_195 -> V_188 . V_277 . V_278 [ 0 ] = V_279 |
V_280 |
V_281 |
V_282 ;
V_195 -> V_188 . V_277 . V_278 [ 1 ] = V_283 |
V_284 ;
return 0 ;
}
static int F_205 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
V_195 -> V_188 . V_277 . V_278 [ 0 ] = V_279 |
V_280 |
V_285 ;
return 0 ;
}
static int F_206 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
int V_170 = V_182 -> V_224 ;
struct V_128 * V_286 ;
F_4 ( & V_7 -> V_125 ) ;
V_286 = F_46 ( & V_7 -> V_100 , V_170 ) ;
V_195 -> V_188 . V_277 . V_278 [ 0 ] = V_286 -> V_278 & 0xff ;
V_195 -> V_188 . V_277 . V_278 [ 1 ] = ( V_286 -> V_278 >> 8 ) & 0xff ;
V_195 -> V_188 . V_277 . V_278 [ 2 ] = ( V_286 -> V_278 >> 16 ) & 0xff ;
V_195 -> V_188 . V_277 . V_278 [ 3 ] = ( V_286 -> V_278 >> 24 ) & 0xff ;
F_6 ( & V_7 -> V_125 ) ;
return 0 ;
}
static unsigned short F_207 ( unsigned int V_287 )
{
unsigned short V_74 = 0 ;
if ( V_287 & V_279 )
V_74 |= V_288 ;
if ( V_287 & V_280 )
V_74 |= V_289 ;
if ( V_287 & V_279 ) {
if ( ( V_287 & V_290 ) ==
V_285 )
V_74 |= V_291 ;
} else {
if ( ( V_287 & V_292 ) ==
V_281 )
V_74 |= V_291 ;
if ( ! ( V_287 & V_282 ) )
V_74 |= V_293 ;
if ( V_287 & ( V_284 << 8 ) )
V_74 |= V_294 ;
V_74 |= V_287 & ( V_283 << 8 ) ;
}
return V_74 ;
}
static unsigned int F_208 ( unsigned short V_74 )
{
unsigned int V_287 = 0 ;
if ( V_74 & V_289 )
V_287 |= V_280 ;
if ( V_74 & V_288 )
V_287 |= V_279 ;
if ( V_287 & V_279 ) {
if ( V_74 & V_291 )
V_287 |= V_285 ;
} else {
if ( V_74 & V_291 )
V_287 |= V_281 ;
if ( ! ( V_74 & V_293 ) )
V_287 |= V_282 ;
if ( V_74 & V_294 )
V_287 |= ( V_284 << 8 ) ;
V_287 |= V_74 & ( 0x7f << 8 ) ;
}
return V_287 ;
}
static void F_209 ( struct V_6 * V_7 , T_1 V_21 ,
int V_171 , int V_74 )
{
const T_1 * V_295 ;
F_210 ( & V_7 -> V_8 , V_21 , V_296 ,
V_171 , V_74 ) ;
V_295 = V_7 -> V_103 ;
if ( ! V_295 )
return;
for (; * V_295 ; V_295 ++ )
F_210 ( & V_7 -> V_8 , * V_295 ,
V_296 , V_171 , V_74 ) ;
}
static inline void F_211 ( struct V_6 * V_7 , T_1 V_21 ,
int V_297 , int V_298 )
{
unsigned int V_171 = 0 ;
unsigned int V_74 = 0 ;
if ( V_297 != - 1 ) {
V_171 |= 0xff ;
V_74 = V_297 ;
}
if ( V_298 != - 1 ) {
V_171 |= 0xff00 ;
V_74 |= V_298 << 8 ;
}
F_209 ( V_7 , V_21 , V_171 , V_74 ) ;
}
static int F_212 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
int V_170 = V_182 -> V_224 ;
struct V_128 * V_286 ;
T_1 V_21 ;
unsigned short V_74 ;
int V_197 ;
F_4 ( & V_7 -> V_125 ) ;
V_286 = F_46 ( & V_7 -> V_100 , V_170 ) ;
V_21 = V_286 -> V_21 ;
V_286 -> V_278 = V_195 -> V_188 . V_277 . V_278 [ 0 ] |
( ( unsigned int ) V_195 -> V_188 . V_277 . V_278 [ 1 ] << 8 ) |
( ( unsigned int ) V_195 -> V_188 . V_277 . V_278 [ 2 ] << 16 ) |
( ( unsigned int ) V_195 -> V_188 . V_277 . V_278 [ 3 ] << 24 ) ;
V_74 = F_207 ( V_286 -> V_278 ) ;
V_74 |= V_286 -> V_299 & 1 ;
V_197 = V_286 -> V_299 != V_74 ;
V_286 -> V_299 = V_74 ;
if ( V_197 && V_21 != ( T_5 ) - 1 )
F_211 ( V_7 , V_21 , V_74 & 0xff , ( V_74 >> 8 ) & 0xff ) ;
F_6 ( & V_7 -> V_125 ) ;
return V_197 ;
}
static int F_213 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
int V_170 = V_182 -> V_224 ;
struct V_128 * V_286 ;
F_4 ( & V_7 -> V_125 ) ;
V_286 = F_46 ( & V_7 -> V_100 , V_170 ) ;
V_195 -> V_188 . integer . V_188 [ 0 ] = V_286 -> V_299 & V_300 ;
F_6 ( & V_7 -> V_125 ) ;
return 0 ;
}
static inline void F_214 ( struct V_6 * V_7 , T_1 V_21 ,
int V_297 , int V_298 )
{
F_211 ( V_7 , V_21 , V_297 , V_298 ) ;
if ( ( F_35 ( V_7 , V_21 ) & V_301 ) &&
( V_297 & V_300 ) )
F_134 ( V_7 , V_21 , V_163 , 0 ,
V_265 , 0 ) ;
}
static int F_215 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
int V_170 = V_182 -> V_224 ;
struct V_128 * V_286 ;
T_1 V_21 ;
unsigned short V_74 ;
int V_197 ;
F_4 ( & V_7 -> V_125 ) ;
V_286 = F_46 ( & V_7 -> V_100 , V_170 ) ;
V_21 = V_286 -> V_21 ;
V_74 = V_286 -> V_299 & ~ V_300 ;
if ( V_195 -> V_188 . integer . V_188 [ 0 ] )
V_74 |= V_300 ;
V_197 = V_286 -> V_299 != V_74 ;
V_286 -> V_299 = V_74 ;
if ( V_197 && V_21 != ( T_5 ) - 1 )
F_214 ( V_7 , V_21 , V_74 & 0xff , - 1 ) ;
F_6 ( & V_7 -> V_125 ) ;
return V_197 ;
}
int F_216 ( struct V_6 * V_7 ,
T_1 V_302 ,
T_1 V_303 ,
int type )
{
int V_11 ;
struct V_181 * V_219 ;
struct V_304 * V_305 ;
int V_170 = 0 ;
int V_74 = 0 ;
const int V_306 = 16 ;
struct V_128 * V_286 ;
struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_10 -> V_307 == V_308 &&
type == V_309 ) {
V_170 = V_306 ;
} else if ( V_10 -> V_307 == V_309 &&
type == V_308 ) {
for ( V_305 = V_310 ; V_305 -> V_91 ; V_305 ++ ) {
V_219 = F_156 ( V_7 , V_305 -> V_91 , 0 , 0 ) ;
if ( ! V_219 )
break;
V_219 -> V_191 . V_216 = V_306 ;
}
V_10 -> V_307 = V_308 ;
}
if ( ! V_10 -> V_307 )
V_10 -> V_307 = type ;
V_170 = F_159 ( V_7 , L_16 , V_170 ) ;
if ( V_170 < 0 ) {
F_32 ( V_7 , L_17 ) ;
return - V_218 ;
}
V_286 = F_43 ( & V_7 -> V_100 ) ;
if ( ! V_286 )
return - V_29 ;
for ( V_305 = V_310 ; V_305 -> V_91 ; V_305 ++ ) {
V_219 = F_191 ( V_305 , V_7 ) ;
if ( ! V_219 )
return - V_29 ;
V_219 -> V_191 . V_216 = V_170 ;
V_219 -> V_224 = V_7 -> V_100 . V_70 - 1 ;
V_11 = F_160 ( V_7 , V_302 , V_219 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_286 -> V_21 = V_303 ;
F_217 ( & V_7 -> V_8 , V_303 ,
V_311 , & V_74 ) ;
V_286 -> V_299 = V_74 ;
V_286 -> V_278 = F_208 ( V_286 -> V_299 ) ;
return 0 ;
}
struct V_128 * F_218 ( struct V_6 * V_7 ,
T_1 V_21 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_7 -> V_100 . V_70 ; V_41 ++ ) {
struct V_128 * V_286 =
F_46 ( & V_7 -> V_100 , V_41 ) ;
if ( V_286 -> V_21 == V_21 )
return V_286 ;
}
return NULL ;
}
void F_219 ( struct V_6 * V_7 , int V_170 )
{
struct V_128 * V_286 ;
F_4 ( & V_7 -> V_125 ) ;
V_286 = F_46 ( & V_7 -> V_100 , V_170 ) ;
V_286 -> V_21 = ( T_5 ) - 1 ;
F_6 ( & V_7 -> V_125 ) ;
}
void F_220 ( struct V_6 * V_7 , int V_170 , T_1 V_21 )
{
struct V_128 * V_286 ;
unsigned short V_74 ;
F_4 ( & V_7 -> V_125 ) ;
V_286 = F_46 ( & V_7 -> V_100 , V_170 ) ;
if ( V_286 -> V_21 != V_21 ) {
V_286 -> V_21 = V_21 ;
V_74 = V_286 -> V_299 ;
F_214 ( V_7 , V_21 , V_74 & 0xff , ( V_74 >> 8 ) & 0xff ) ;
}
F_6 ( & V_7 -> V_125 ) ;
}
static int F_221 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_312 * V_313 = F_141 ( V_182 ) ;
V_195 -> V_188 . integer . V_188 [ 0 ] = V_313 -> V_314 ;
return 0 ;
}
static int F_222 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_312 * V_313 = F_141 ( V_182 ) ;
V_313 -> V_314 = ! ! V_195 -> V_188 . integer . V_188 [ 0 ] ;
return 0 ;
}
int F_223 ( struct V_6 * V_7 ,
struct V_312 * V_313 )
{
struct V_181 * V_219 ;
if ( ! V_313 -> V_315 )
return 0 ;
V_219 = F_191 ( & V_316 , V_313 ) ;
if ( ! V_219 )
return - V_29 ;
return F_160 ( V_7 , V_313 -> V_315 , V_219 ) ;
}
static int F_224 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
V_195 -> V_188 . integer . V_188 [ 0 ] = V_7 -> V_317 ;
return 0 ;
}
static int F_225 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_1 V_21 = V_182 -> V_224 ;
unsigned int V_74 = ! ! V_195 -> V_188 . integer . V_188 [ 0 ] ;
int V_197 ;
F_4 ( & V_7 -> V_125 ) ;
V_197 = V_7 -> V_317 != V_74 ;
if ( V_197 ) {
V_7 -> V_317 = V_74 ;
F_226 ( & V_7 -> V_8 , V_21 ,
V_296 , V_74 ) ;
}
F_6 ( & V_7 -> V_125 ) ;
return V_197 ;
}
static int F_227 ( struct V_181 * V_182 ,
struct V_194 * V_195 )
{
struct V_6 * V_7 = F_141 ( V_182 ) ;
T_1 V_21 = V_182 -> V_224 ;
unsigned int V_74 ;
unsigned int V_287 ;
F_217 ( & V_7 -> V_8 , V_21 ,
V_311 , & V_74 ) ;
V_287 = F_208 ( V_74 ) ;
V_195 -> V_188 . V_277 . V_278 [ 0 ] = V_287 ;
V_195 -> V_188 . V_277 . V_278 [ 1 ] = V_287 >> 8 ;
V_195 -> V_188 . V_277 . V_278 [ 2 ] = V_287 >> 16 ;
V_195 -> V_188 . V_277 . V_278 [ 3 ] = V_287 >> 24 ;
return 0 ;
}
int F_228 ( struct V_6 * V_7 , T_1 V_21 )
{
int V_11 ;
struct V_181 * V_219 ;
struct V_304 * V_305 ;
int V_170 ;
V_170 = F_159 ( V_7 , L_18 , 0 ) ;
if ( V_170 < 0 ) {
F_32 ( V_7 , L_19 ) ;
return - V_218 ;
}
for ( V_305 = V_318 ; V_305 -> V_91 ; V_305 ++ ) {
V_219 = F_191 ( V_305 , V_7 ) ;
if ( ! V_219 )
return - V_29 ;
V_219 -> V_224 = V_21 ;
V_11 = F_160 ( V_7 , V_21 , V_219 ) ;
if ( V_11 < 0 )
return V_11 ;
}
V_7 -> V_317 =
F_44 ( V_7 , V_21 , 0 ,
V_311 , 0 ) &
V_300 ;
return 0 ;
}
void F_229 ( struct V_6 * V_7 , T_1 V_114 ,
unsigned int V_319 )
{
T_1 V_21 ;
F_42 (nid, codec) {
unsigned int V_45 = F_35 ( V_7 , V_21 ) ;
unsigned int V_320 = V_319 ;
if ( ! ( V_45 & V_321 ) )
continue;
if ( V_7 -> V_322 ) {
V_320 = V_7 -> V_322 ( V_7 , V_21 , V_319 ) ;
if ( V_320 != V_319 && V_319 == V_323 )
continue;
}
F_12 ( V_7 , V_21 , 0 , V_324 ,
V_320 ) ;
}
}
static unsigned int F_230 ( struct V_6 * V_7 ,
T_1 V_114 ,
unsigned int V_319 )
{
unsigned long V_325 = V_135 + F_231 ( 500 ) ;
unsigned int V_320 , V_326 ;
for (; ; ) {
V_320 = F_44 ( V_7 , V_114 , 0 ,
V_327 , 0 ) ;
if ( V_320 & V_328 )
break;
V_326 = ( V_320 >> 4 ) & 0x0f ;
if ( V_326 == V_319 )
break;
if ( F_232 ( V_135 , V_325 ) )
break;
F_118 ( 1 ) ;
}
return V_320 ;
}
unsigned int F_233 ( struct V_6 * V_7 ,
T_1 V_21 ,
unsigned int V_319 )
{
if ( V_21 == V_7 -> V_8 . V_136 || V_21 == V_7 -> V_8 . V_137 )
return V_319 ;
if ( V_319 == V_323 &&
F_34 ( F_35 ( V_7 , V_21 ) ) == V_43 &&
( F_234 ( V_7 , V_21 ) & V_329 ) ) {
int V_330 = F_44 ( V_7 , V_21 , 0 ,
V_331 , 0 ) ;
if ( V_330 & 0x02 )
return V_138 ;
}
return V_319 ;
}
static unsigned int F_109 ( struct V_6 * V_7 ,
unsigned int V_319 )
{
T_1 V_114 = V_7 -> V_8 . V_136 ? V_7 -> V_8 . V_136 : V_7 -> V_8 . V_137 ;
int V_187 ;
unsigned int V_320 ;
int V_4 = 0 ;
if ( V_319 == V_323 ) {
if ( V_7 -> V_131 < 0 )
F_118 ( F_235 ( V_7 ) ? 10 : 100 ) ;
else if ( V_7 -> V_131 > 0 )
F_118 ( V_7 -> V_131 ) ;
V_4 = V_14 ;
}
for ( V_187 = 0 ; V_187 < 10 ; V_187 ++ ) {
if ( V_7 -> V_97 . V_332 )
V_7 -> V_97 . V_332 ( V_7 , V_114 ,
V_319 ) ;
else {
V_320 = V_319 ;
if ( V_7 -> V_322 )
V_320 = V_7 -> V_322 ( V_7 , V_114 , V_320 ) ;
if ( V_320 == V_319 || V_319 != V_323 )
F_44 ( V_7 , V_114 , V_4 ,
V_324 ,
V_320 ) ;
F_229 ( V_7 , V_114 , V_319 ) ;
}
V_320 = F_230 ( V_7 , V_114 , V_319 ) ;
if ( ! ( V_320 & V_328 ) )
break;
}
return V_320 ;
}
static void F_236 ( struct V_6 * V_7 )
{
T_1 V_21 ;
if ( ! V_7 -> V_322 )
return;
F_42 (nid, codec) {
unsigned int V_45 = F_35 ( V_7 , V_21 ) ;
unsigned int V_75 ;
if ( ! ( V_45 & V_321 ) )
continue;
V_75 = V_7 -> V_322 ( V_7 , V_21 , V_138 ) ;
if ( V_75 == V_138 )
continue;
if ( ! F_237 ( V_7 , V_21 , V_75 ) )
F_12 ( V_7 , V_21 , 0 ,
V_324 , V_75 ) ;
}
}
static void F_238 ( struct V_6 * V_7 )
{
if ( V_7 -> V_333 . V_27 )
F_11 ( V_7 , V_7 -> V_333 . V_27 ) ;
}
static inline void F_238 ( struct V_6 * V_7 ) {}
static void F_239 ( struct V_6 * V_7 , bool V_334 )
{
unsigned long V_335 = V_135 - V_7 -> V_134 ;
if ( V_334 )
V_7 -> V_336 += V_335 ;
else
V_7 -> V_337 += V_335 ;
V_7 -> V_134 += V_335 ;
}
void F_240 ( struct V_6 * V_7 )
{
F_239 ( V_7 , F_241 ( V_7 ) ) ;
}
static unsigned int F_242 ( struct V_6 * V_7 )
{
unsigned int V_320 ;
F_243 ( & V_7 -> V_8 . V_338 ) ;
if ( V_7 -> V_97 . V_339 )
V_7 -> V_97 . V_339 ( V_7 ) ;
F_124 ( V_7 ) ;
V_320 = F_109 ( V_7 , V_323 ) ;
F_239 ( V_7 , true ) ;
F_244 ( & V_7 -> V_8 . V_338 ) ;
return V_320 ;
}
static void F_245 ( struct V_6 * V_7 )
{
F_243 ( & V_7 -> V_8 . V_338 ) ;
if ( V_7 -> V_8 . V_177 )
F_246 ( V_7 -> V_8 . V_177 ) ;
V_7 -> V_134 = V_135 ;
F_109 ( V_7 , V_138 ) ;
F_54 ( V_7 ) ;
F_238 ( V_7 ) ;
F_56 ( V_7 ) ;
if ( V_7 -> V_97 . V_340 )
V_7 -> V_97 . V_340 ( V_7 ) ;
else {
if ( V_7 -> V_97 . V_341 )
V_7 -> V_97 . V_341 ( V_7 ) ;
if ( V_7 -> V_8 . V_177 )
F_247 ( V_7 -> V_8 . V_177 ) ;
}
if ( V_7 -> V_82 )
F_55 ( & V_7 -> V_81 . V_80 ) ;
else
F_248 ( V_7 ) ;
F_244 ( & V_7 -> V_8 . V_338 ) ;
}
static int F_249 ( struct V_89 * V_2 )
{
struct V_6 * V_7 = F_97 ( V_2 ) ;
struct V_86 * V_87 ;
unsigned int V_320 ;
F_80 ( & V_7 -> V_81 ) ;
F_14 (pcm, &codec->pcm_list_head, list)
F_250 ( V_87 -> V_87 ) ;
V_320 = F_242 ( V_7 ) ;
if ( F_251 ( V_7 ) && F_235 ( V_7 ) &&
( V_320 & V_342 ) )
F_252 ( & V_7 -> V_8 ) ;
F_88 ( & V_7 -> V_8 , false ) ;
return 0 ;
}
static int F_253 ( struct V_89 * V_2 )
{
struct V_6 * V_7 = F_97 ( V_2 ) ;
F_88 ( & V_7 -> V_8 , true ) ;
F_254 ( & V_7 -> V_8 ) ;
F_245 ( V_7 ) ;
F_255 ( V_2 ) ;
return 0 ;
}
static int F_256 ( struct V_6 * V_7 )
{
struct V_86 * V_87 ;
int V_343 , V_11 ;
F_14 (pcm, &codec->pcm_list_head, list) {
for ( V_343 = 0 ; V_343 < 2 ; V_343 ++ ) {
struct V_344 * V_345 = & V_87 -> V_346 [ V_343 ] ;
struct V_347 * V_348 ;
const struct V_349 * V_350 ;
if ( ! V_87 -> V_87 || V_87 -> V_351 || ! V_345 -> V_352 )
continue;
V_350 = V_345 -> V_348 ? V_345 -> V_348 : V_353 ;
V_11 = F_257 ( V_87 -> V_87 , V_343 , V_350 ,
V_345 -> V_354 ,
0 , & V_348 ) ;
if ( V_11 < 0 )
return V_11 ;
V_348 -> V_355 = V_356 ;
}
}
return 0 ;
}
int F_258 ( struct V_6 * V_7 )
{
int V_11 = 0 ;
F_238 ( V_7 ) ;
if ( V_7 -> V_97 . V_341 )
V_11 = V_7 -> V_97 . V_341 ( V_7 ) ;
if ( ! V_11 && V_7 -> V_97 . V_357 )
V_11 = V_7 -> V_97 . V_357 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_256 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_7 -> V_82 )
F_55 ( & V_7 -> V_81 . V_80 ) ;
else
F_248 ( V_7 ) ;
F_236 ( V_7 ) ;
return 0 ;
}
static int F_259 ( struct V_344 * V_345 ,
struct V_6 * V_7 ,
struct V_358 * V_359 )
{
return 0 ;
}
static int F_260 ( struct V_344 * V_345 ,
struct V_6 * V_7 ,
unsigned int V_143 ,
unsigned int V_149 ,
struct V_358 * V_359 )
{
F_119 ( V_7 , V_345 -> V_21 , V_143 , 0 , V_149 ) ;
return 0 ;
}
static int F_261 ( struct V_344 * V_345 ,
struct V_6 * V_7 ,
struct V_358 * V_359 )
{
F_262 ( V_7 , V_345 -> V_21 ) ;
return 0 ;
}
static int F_263 ( struct V_6 * V_7 ,
struct V_344 * V_273 )
{
int V_11 ;
if ( V_273 -> V_21 && ( ! V_273 -> V_360 || ! V_273 -> V_361 ) ) {
V_11 = F_264 ( V_7 , V_273 -> V_21 ,
V_273 -> V_360 ? NULL : & V_273 -> V_360 ,
V_273 -> V_361 ? NULL : & V_273 -> V_361 ,
V_273 -> V_362 ? NULL : & V_273 -> V_362 ) ;
if ( V_11 < 0 )
return V_11 ;
}
if ( V_273 -> V_272 . V_363 == NULL )
V_273 -> V_272 . V_363 = F_259 ;
if ( V_273 -> V_272 . V_364 == NULL )
V_273 -> V_272 . V_364 = F_259 ;
if ( V_273 -> V_272 . V_365 == NULL ) {
if ( F_30 ( ! V_273 -> V_21 ) )
return - V_36 ;
V_273 -> V_272 . V_365 = F_260 ;
}
if ( V_273 -> V_272 . V_366 == NULL ) {
if ( F_30 ( ! V_273 -> V_21 ) )
return - V_36 ;
V_273 -> V_272 . V_366 = F_261 ;
}
return 0 ;
}
int F_265 ( struct V_6 * V_7 ,
struct V_344 * V_345 ,
unsigned int V_346 ,
unsigned int V_149 ,
struct V_358 * V_359 )
{
int V_175 ;
F_4 ( & V_7 -> V_10 -> V_367 ) ;
if ( V_345 -> V_272 . V_365 )
V_175 = V_345 -> V_272 . V_365 ( V_345 , V_7 , V_346 , V_149 ,
V_359 ) ;
else
V_175 = - V_368 ;
if ( V_175 >= 0 )
F_123 ( V_7 ) ;
F_6 ( & V_7 -> V_10 -> V_367 ) ;
return V_175 ;
}
void F_266 ( struct V_6 * V_7 ,
struct V_344 * V_345 ,
struct V_358 * V_359 )
{
F_4 ( & V_7 -> V_10 -> V_367 ) ;
if ( V_345 -> V_272 . V_366 )
V_345 -> V_272 . V_366 ( V_345 , V_7 , V_359 ) ;
F_6 ( & V_7 -> V_10 -> V_367 ) ;
}
static int F_267 ( struct V_9 * V_10 , unsigned int type )
{
static int V_369 [ V_370 ] [ 5 ] = {
[ V_371 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_309 ] = { 1 , - 1 } ,
[ V_308 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_372 ] = { 6 , - 1 } ,
} ;
int V_41 ;
if ( type >= V_370 ) {
F_268 ( V_10 -> V_88 -> V_2 , L_20 , type ) ;
return - V_36 ;
}
for ( V_41 = 0 ; V_369 [ type ] [ V_41 ] >= 0 ; V_41 ++ ) {
#ifndef F_269
if ( V_369 [ type ] [ V_41 ] >= 8 )
break;
#endif
if ( ! F_270 ( V_369 [ type ] [ V_41 ] , V_10 -> V_90 ) )
return V_369 [ type ] [ V_41 ] ;
}
#ifdef F_269
for ( V_41 = 10 ; V_41 < 32 ; V_41 ++ ) {
if ( ! F_270 ( V_41 , V_10 -> V_90 ) )
return V_41 ;
}
#endif
F_271 ( V_10 -> V_88 -> V_2 , L_21 ,
V_373 [ type ] ) ;
#ifndef F_269
F_271 ( V_10 -> V_88 -> V_2 ,
L_22 ) ;
#endif
return - V_17 ;
}
int F_272 ( struct V_6 * V_7 )
{
struct V_86 * V_231 ;
int V_11 ;
if ( ! F_19 ( & V_7 -> V_93 ) )
return 0 ;
if ( ! V_7 -> V_97 . V_374 )
return 0 ;
V_11 = V_7 -> V_97 . V_374 ( V_7 ) ;
if ( V_11 < 0 ) {
F_32 ( V_7 , L_23 ,
V_7 -> V_8 . V_16 , V_11 ) ;
return V_11 ;
}
F_14 (cpcm, &codec->pcm_list_head, list) {
int V_346 ;
for ( V_346 = 0 ; V_346 < 2 ; V_346 ++ ) {
struct V_344 * V_273 = & V_231 -> V_346 [ V_346 ] ;
if ( ! V_273 -> V_352 )
continue;
V_11 = F_263 ( V_7 , V_273 ) ;
if ( V_11 < 0 ) {
F_146 ( V_7 ,
L_24 ,
V_231 -> V_91 ) ;
return V_11 ;
}
}
}
return 0 ;
}
int F_273 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_10 ;
struct V_86 * V_231 ;
int V_2 , V_11 ;
V_11 = F_272 ( V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
F_14 (cpcm, &codec->pcm_list_head, list) {
if ( V_231 -> V_87 )
continue;
if ( ! V_231 -> V_346 [ 0 ] . V_352 && ! V_231 -> V_346 [ 1 ] . V_352 )
continue;
V_2 = F_267 ( V_10 , V_231 -> V_375 ) ;
if ( V_2 < 0 )
continue;
V_231 -> V_89 = V_2 ;
V_11 = F_274 ( V_10 , V_7 , V_231 ) ;
if ( V_11 < 0 ) {
F_32 ( V_7 ,
L_25 ,
V_2 , V_7 -> V_8 . V_16 ) ;
continue;
}
}
return 0 ;
}
int F_275 ( struct V_6 * V_7 ,
const struct V_304 * V_376 )
{
int V_11 ;
for (; V_376 -> V_91 ; V_376 ++ ) {
struct V_181 * V_219 ;
int V_16 = 0 , V_170 = 0 ;
if ( V_376 -> V_214 == - 1 )
continue;
for (; ; ) {
V_219 = F_191 ( V_376 , V_7 ) ;
if ( ! V_219 )
return - V_29 ;
if ( V_16 > 0 )
V_219 -> V_191 . V_89 = V_16 ;
if ( V_170 > 0 )
V_219 -> V_191 . V_216 = V_170 ;
V_11 = F_160 ( V_7 , 0 , V_219 ) ;
if ( ! V_11 )
break;
if ( ! V_16 && V_7 -> V_8 . V_16 )
V_16 = V_7 -> V_8 . V_16 ;
else if ( ! V_170 && ! V_376 -> V_216 ) {
V_170 = F_159 ( V_7 ,
V_376 -> V_91 , 0 ) ;
if ( V_170 <= 0 )
return V_11 ;
} else
return V_11 ;
}
}
return 0 ;
}
static void F_276 ( struct V_6 * V_7 , int V_377 )
{
struct V_89 * V_2 = F_78 ( V_7 ) ;
if ( V_377 == 0 && V_7 -> V_378 )
V_377 = 3000 ;
if ( V_377 > 0 ) {
F_277 ( V_2 , V_377 ) ;
F_278 ( V_2 ) ;
F_279 ( V_2 ) ;
if ( ! F_280 ( V_2 ) )
F_255 ( V_2 ) ;
} else {
F_281 ( V_2 ) ;
F_282 ( V_2 ) ;
}
}
void F_283 ( struct V_9 * V_10 , int V_377 )
{
struct V_6 * V_153 ;
F_120 (c, bus)
F_276 ( V_153 , V_377 ) ;
}
int F_284 ( struct V_6 * V_7 ,
struct V_379 * V_380 ,
T_1 V_21 )
{
const struct V_381 * V_25 ;
int V_169 , V_382 ;
if ( ! V_380 -> V_383 )
return 0 ;
for ( V_25 = V_380 -> V_383 ; V_25 -> V_21 ; V_25 ++ ) {
if ( V_25 -> V_21 == V_21 )
break;
}
if ( ! V_25 -> V_21 )
return 0 ;
for ( V_25 = V_380 -> V_383 ; V_25 -> V_21 ; V_25 ++ ) {
for ( V_169 = 0 ; V_169 < 2 ; V_169 ++ ) {
V_382 = F_137 ( V_7 , V_25 -> V_21 , V_169 , V_25 -> V_166 ,
V_25 -> V_170 ) ;
if ( ! ( V_382 & V_265 ) && V_382 > 0 ) {
if ( ! V_380 -> V_384 ) {
V_380 -> V_384 = 1 ;
F_3 ( V_7 ) ;
}
return 1 ;
}
}
}
if ( V_380 -> V_384 ) {
V_380 -> V_384 = 0 ;
F_7 ( V_7 ) ;
}
return 0 ;
}
int F_285 ( const struct V_385 * V_386 ,
struct V_183 * V_184 )
{
unsigned int V_216 ;
V_184 -> type = V_387 ;
V_184 -> V_187 = 1 ;
V_184 -> V_188 . V_255 . V_226 = V_386 -> V_388 ;
if ( ! V_386 -> V_388 )
return 0 ;
V_216 = V_184 -> V_188 . V_255 . V_220 ;
if ( V_216 >= V_386 -> V_388 )
V_216 = V_386 -> V_388 - 1 ;
strcpy ( V_184 -> V_188 . V_255 . V_91 , V_386 -> V_226 [ V_216 ] . V_389 ) ;
return 0 ;
}
int F_286 ( struct V_6 * V_7 ,
const struct V_385 * V_386 ,
struct V_194 * V_195 ,
T_1 V_21 ,
unsigned int * V_390 )
{
unsigned int V_170 ;
if ( ! V_386 -> V_388 )
return 0 ;
V_170 = V_195 -> V_188 . V_255 . V_220 [ 0 ] ;
if ( V_170 >= V_386 -> V_388 )
V_170 = V_386 -> V_388 - 1 ;
if ( * V_390 == V_170 )
return 0 ;
F_287 ( V_7 , V_21 , 0 , V_391 ,
V_386 -> V_226 [ V_170 ] . V_216 ) ;
* V_390 = V_170 ;
return 1 ;
}
int F_288 ( struct V_181 * V_182 ,
struct V_183 * V_184 ,
int V_388 , const char * const * V_252 )
{
static const char * const V_392 [] = {
L_26 , L_27
} ;
if ( ! V_252 || ! V_388 ) {
V_388 = 2 ;
V_252 = V_392 ;
}
return F_184 ( V_184 , 1 , V_388 , V_252 ) ;
}
static void F_289 ( struct V_6 * V_7 , T_1 V_21 ,
unsigned int V_143 , unsigned int V_149 )
{
struct V_128 * V_286 ;
unsigned int V_393 ;
bool V_394 ;
V_286 = F_218 ( V_7 , V_21 ) ;
if ( F_290 ( V_286 == NULL ) )
return;
V_393 = F_44 ( V_7 , V_21 , 0 ,
V_151 , 0 ) ;
V_394 = V_7 -> V_104 &&
( V_286 -> V_299 & V_300 ) &&
V_393 != V_149 ;
if ( V_394 )
F_211 ( V_7 , V_21 ,
V_286 -> V_299 & ~ V_300 & 0xff ,
- 1 ) ;
F_119 ( V_7 , V_21 , V_143 , 0 , V_149 ) ;
if ( V_7 -> V_103 ) {
const T_1 * V_295 ;
for ( V_295 = V_7 -> V_103 ; * V_295 ; V_295 ++ )
F_119 ( V_7 , * V_295 , V_143 , 0 ,
V_149 ) ;
}
if ( V_394 )
F_211 ( V_7 , V_21 ,
V_286 -> V_299 & 0xff , - 1 ) ;
}
static void F_291 ( struct V_6 * V_7 , T_1 V_21 )
{
F_262 ( V_7 , V_21 ) ;
if ( V_7 -> V_103 ) {
const T_1 * V_295 ;
for ( V_295 = V_7 -> V_103 ; * V_295 ; V_295 ++ )
F_262 ( V_7 , * V_295 ) ;
}
}
int F_292 ( struct V_6 * V_7 ,
struct V_312 * V_313 )
{
F_4 ( & V_7 -> V_125 ) ;
if ( V_313 -> V_395 == V_396 )
F_291 ( V_7 , V_313 -> V_315 ) ;
V_313 -> V_395 = V_397 ;
F_6 ( & V_7 -> V_125 ) ;
return 0 ;
}
int F_293 ( struct V_6 * V_7 ,
struct V_312 * V_313 ,
unsigned int V_143 ,
unsigned int V_149 ,
struct V_358 * V_359 )
{
F_4 ( & V_7 -> V_125 ) ;
F_289 ( V_7 , V_313 -> V_315 , V_143 , V_149 ) ;
F_6 ( & V_7 -> V_125 ) ;
return 0 ;
}
int F_294 ( struct V_6 * V_7 ,
struct V_312 * V_313 )
{
F_4 ( & V_7 -> V_125 ) ;
F_291 ( V_7 , V_313 -> V_315 ) ;
F_6 ( & V_7 -> V_125 ) ;
return 0 ;
}
int F_295 ( struct V_6 * V_7 ,
struct V_312 * V_313 )
{
F_4 ( & V_7 -> V_125 ) ;
V_313 -> V_395 = 0 ;
F_6 ( & V_7 -> V_125 ) ;
return 0 ;
}
int F_296 ( struct V_6 * V_7 ,
struct V_312 * V_313 ,
struct V_358 * V_359 ,
struct V_344 * V_345 )
{
struct V_398 * V_399 = V_359 -> V_399 ;
V_399 -> V_400 . V_354 = V_313 -> V_401 ;
if ( V_313 -> V_315 ) {
if ( ! V_313 -> V_402 ) {
V_313 -> V_402 = V_345 -> V_360 ;
V_313 -> V_403 = V_345 -> V_361 ;
V_313 -> V_404 = V_345 -> V_362 ;
} else {
V_399 -> V_400 . V_360 = V_313 -> V_402 ;
V_399 -> V_400 . V_361 = V_313 -> V_403 ;
V_345 -> V_362 = V_313 -> V_404 ;
}
if ( ! V_313 -> V_405 ) {
F_264 ( V_7 , V_313 -> V_315 ,
& V_313 -> V_405 ,
& V_313 -> V_406 ,
& V_313 -> V_407 ) ;
}
F_4 ( & V_7 -> V_125 ) ;
if ( V_313 -> V_314 ) {
if ( ( V_399 -> V_400 . V_360 & V_313 -> V_405 ) &&
( V_399 -> V_400 . V_361 & V_313 -> V_406 ) ) {
V_399 -> V_400 . V_360 &= V_313 -> V_405 ;
V_399 -> V_400 . V_361 &= V_313 -> V_406 ;
if ( V_313 -> V_407 < V_345 -> V_362 )
V_345 -> V_362 = V_313 -> V_407 ;
} else {
V_313 -> V_314 = 0 ;
}
}
F_6 ( & V_7 -> V_125 ) ;
}
return F_297 ( V_359 -> V_399 , 0 ,
V_408 , 2 ) ;
}
int F_298 ( struct V_6 * V_7 ,
struct V_312 * V_313 ,
unsigned int V_143 ,
unsigned int V_149 ,
struct V_358 * V_359 )
{
const T_1 * V_106 = V_313 -> V_409 ;
int V_185 = V_359 -> V_399 -> V_410 ;
struct V_128 * V_286 ;
int V_41 ;
F_4 ( & V_7 -> V_125 ) ;
V_286 = F_218 ( V_7 , V_313 -> V_315 ) ;
if ( V_313 -> V_315 && V_313 -> V_314 &&
V_313 -> V_395 != V_397 ) {
if ( V_185 == 2 && V_286 != NULL &&
F_299 ( V_7 , V_313 -> V_315 ,
V_149 ) &&
! ( V_286 -> V_278 & V_280 ) ) {
V_313 -> V_395 = V_396 ;
F_289 ( V_7 , V_313 -> V_315 ,
V_143 , V_149 ) ;
} else {
V_313 -> V_395 = 0 ;
F_291 ( V_7 , V_313 -> V_315 ) ;
}
}
F_6 ( & V_7 -> V_125 ) ;
F_119 ( V_7 , V_106 [ V_411 ] , V_143 ,
0 , V_149 ) ;
if ( ! V_313 -> V_412 &&
V_313 -> V_413 && V_313 -> V_413 != V_106 [ V_411 ] )
F_119 ( V_7 , V_313 -> V_413 , V_143 ,
0 , V_149 ) ;
for ( V_41 = 0 ; V_41 < F_26 ( V_313 -> V_414 ) ; V_41 ++ )
if ( ! V_313 -> V_412 && V_313 -> V_414 [ V_41 ] )
F_119 ( V_7 ,
V_313 -> V_414 [ V_41 ] ,
V_143 , 0 , V_149 ) ;
for ( V_41 = 1 ; V_41 < V_313 -> V_415 ; V_41 ++ ) {
if ( V_185 >= ( V_41 + 1 ) * 2 )
F_119 ( V_7 , V_106 [ V_41 ] , V_143 ,
V_41 * 2 , V_149 ) ;
else if ( ! V_313 -> V_412 )
F_119 ( V_7 , V_106 [ V_41 ] , V_143 ,
0 , V_149 ) ;
}
for ( V_41 = 0 ; V_41 < F_26 ( V_313 -> V_416 ) ; V_41 ++ ) {
int V_169 = 0 ;
if ( ! V_313 -> V_416 [ V_41 ] )
break;
if ( V_185 >= ( V_41 + 1 ) * 2 )
V_169 = V_41 * 2 ;
else if ( ! V_313 -> V_412 )
break;
F_119 ( V_7 , V_313 -> V_416 [ V_41 ] ,
V_143 , V_169 , V_149 ) ;
}
return 0 ;
}
int F_300 ( struct V_6 * V_7 ,
struct V_312 * V_313 )
{
const T_1 * V_106 = V_313 -> V_409 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_313 -> V_415 ; V_41 ++ )
F_262 ( V_7 , V_106 [ V_41 ] ) ;
if ( V_313 -> V_413 )
F_262 ( V_7 , V_313 -> V_413 ) ;
for ( V_41 = 0 ; V_41 < F_26 ( V_313 -> V_414 ) ; V_41 ++ )
if ( V_313 -> V_414 [ V_41 ] )
F_262 ( V_7 ,
V_313 -> V_414 [ V_41 ] ) ;
for ( V_41 = 0 ; V_41 < F_26 ( V_313 -> V_416 ) ; V_41 ++ )
if ( V_313 -> V_416 [ V_41 ] )
F_262 ( V_7 ,
V_313 -> V_416 [ V_41 ] ) ;
F_4 ( & V_7 -> V_125 ) ;
if ( V_313 -> V_315 && V_313 -> V_395 == V_396 ) {
F_291 ( V_7 , V_313 -> V_315 ) ;
V_313 -> V_395 = 0 ;
}
F_6 ( & V_7 -> V_125 ) ;
return 0 ;
}
unsigned int F_301 ( struct V_6 * V_7 , T_1 V_61 )
{
unsigned int V_417 ;
unsigned int V_145 ;
V_145 = F_44 ( V_7 , V_61 , 0 ,
V_67 , 0 ) ;
V_417 = F_234 ( V_7 , V_61 ) ;
V_417 = ( V_417 & V_418 ) >> V_419 ;
if ( ( V_417 & V_420 ) && V_145 != V_421 )
return V_422 ;
else if ( V_417 & V_423 )
return V_424 ;
else if ( V_417 & V_425 )
return V_426 ;
else if ( V_417 & V_427 )
return V_428 ;
return V_429 ;
}
unsigned int F_302 ( struct V_6 * V_7 ,
T_1 V_61 , unsigned int V_74 )
{
static unsigned int V_430 [] [ 2 ] = {
{ V_426 , V_425 } ,
{ V_422 , V_420 } ,
{ V_424 , V_423 } ,
{ V_428 , V_427 } ,
} ;
unsigned int V_431 ;
if ( ! V_74 )
return 0 ;
V_431 = F_234 ( V_7 , V_61 ) ;
if ( ! V_431 )
return V_74 ;
if ( V_74 & V_432 ) {
if ( ! ( V_431 & V_433 ) )
V_74 &= ~ ( V_432 | V_434 ) ;
else if ( ( V_74 & V_434 ) && ! ( V_431 & V_435 ) )
V_74 &= ~ V_434 ;
}
if ( V_74 & V_436 ) {
if ( ! ( V_431 & V_437 ) )
V_74 &= ~ ( V_436 | V_438 ) ;
else {
unsigned int V_439 , V_440 ;
int V_41 ;
V_439 = ( V_431 & V_418 ) >> V_419 ;
V_440 = V_74 & V_438 ;
for ( V_41 = 0 ; V_41 < F_26 ( V_430 ) ; V_41 ++ ) {
if ( V_440 == V_430 [ V_41 ] [ 0 ] &&
! ( V_439 & V_430 [ V_41 ] [ 1 ] ) ) {
if ( V_41 == F_26 ( V_430 ) - 1 )
V_440 = V_429 ;
else
V_440 = V_430 [ V_41 + 1 ] [ 0 ] ;
}
}
V_74 &= ~ V_438 ;
V_74 |= V_440 ;
}
}
return V_74 ;
}
int F_303 ( struct V_6 * V_7 , T_1 V_61 ,
unsigned int V_74 , bool V_441 )
{
V_74 = F_302 ( V_7 , V_61 , V_74 ) ;
F_51 ( V_7 , V_61 , V_74 ) ;
if ( V_441 )
return F_304 ( V_7 , V_61 , 0 ,
V_77 , V_74 ) ;
else
return F_12 ( V_7 , V_61 , 0 ,
V_77 , V_74 ) ;
}
int F_305 ( struct V_6 * V_7 ,
struct V_385 * V_386 , const char * V_389 ,
int V_216 , int * V_442 )
{
int V_41 , V_443 = 0 ;
if ( V_386 -> V_388 >= V_444 ) {
F_32 ( V_7 , L_28 ) ;
return - V_36 ;
}
for ( V_41 = 0 ; V_41 < V_386 -> V_388 ; V_41 ++ ) {
if ( ! strncmp ( V_389 , V_386 -> V_226 [ V_41 ] . V_389 , strlen ( V_389 ) ) )
V_443 ++ ;
}
if ( V_442 )
* V_442 = V_443 ;
if ( V_443 > 0 )
snprintf ( V_386 -> V_226 [ V_386 -> V_388 ] . V_389 ,
sizeof( V_386 -> V_226 [ V_386 -> V_388 ] . V_389 ) ,
L_29 , V_389 , V_443 ) ;
else
F_306 ( V_386 -> V_226 [ V_386 -> V_388 ] . V_389 , V_389 ,
sizeof( V_386 -> V_226 [ V_386 -> V_388 ] . V_389 ) ) ;
V_386 -> V_226 [ V_386 -> V_388 ] . V_216 = V_216 ;
V_386 -> V_388 ++ ;
return 0 ;
}
void F_307 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
F_120 (codec, bus) {
F_80 ( & V_7 -> V_81 ) ;
#ifdef F_106
if ( F_241 ( V_7 ) ) {
F_242 ( V_7 ) ;
F_245 ( V_7 ) ;
}
#endif
}
}
void F_308 ( int V_87 , char * V_445 , int V_446 )
{
static unsigned int V_167 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_41 , V_447 ;
for ( V_41 = 0 , V_447 = 0 ; V_41 < F_26 ( V_167 ) ; V_41 ++ )
if ( V_87 & ( V_448 << V_41 ) )
V_447 += snprintf ( V_445 + V_447 , V_446 - V_447 , L_30 , V_167 [ V_41 ] ) ;
V_445 [ V_447 ] = '\0' ;
}
