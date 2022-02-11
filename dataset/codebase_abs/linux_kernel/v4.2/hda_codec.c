const char * F_1 ( T_1 V_1 )
{
static char * V_2 [ 7 ] = {
L_1 , L_2 , L_3 , L_4 , L_5 , L_6 , L_7 ,
} ;
static unsigned char V_3 [] = {
0x07 , 0x08 ,
0x17 , 0x18 , 0x19 ,
0x37 , 0x38
} ;
static char * V_4 [] = {
L_8 , L_9 ,
L_10 , L_11 , L_12 ,
L_13 , L_14
} ;
int V_5 ;
V_1 = ( V_1 & V_6 ) >> V_7 ;
if ( ( V_1 & 0x0f ) < 7 )
return V_2 [ V_1 & 0x0f ] ;
for ( V_5 = 0 ; V_5 < F_2 ( V_3 ) ; V_5 ++ ) {
if ( V_1 == V_3 [ V_5 ] )
return V_4 [ V_5 ] ;
}
return L_15 ;
}
const char * F_3 ( T_1 V_1 )
{
static char * V_8 [ 4 ] = { L_16 , L_17 , L_18 , L_19 } ;
return V_8 [ ( V_1 >> ( V_7 + 4 ) ) & 3 ] ;
}
const char * F_4 ( T_1 V_1 )
{
static char * V_9 [ 16 ] = {
L_20 , L_21 , L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27 ,
L_28 , L_29 , L_30 , L_31 ,
L_32 , L_33 , L_34 , L_35
} ;
return V_9 [ ( V_1 & V_10 )
>> V_11 ] ;
}
static int F_5 ( struct V_12 * V_13 , unsigned int V_14 ,
unsigned int V_15 , unsigned int * V_16 )
{
struct V_17 * V_18 = F_6 ( V_13 , struct V_17 , V_19 ) ;
struct V_20 * V_21 = V_18 -> V_21 ;
int V_22 ;
if ( V_14 == ~ 0 )
return - 1 ;
V_23:
F_7 ( V_18 ) ;
F_8 ( & V_21 -> V_19 . V_24 ) ;
if ( V_15 & V_25 )
V_21 -> V_26 = 1 ;
V_22 = F_9 ( & V_21 -> V_19 , V_18 -> V_19 . V_27 ,
V_14 , V_16 ) ;
V_21 -> V_26 = 0 ;
F_10 ( & V_21 -> V_19 . V_24 ) ;
F_11 ( V_18 ) ;
if ( ! F_12 ( V_18 ) && V_16 && V_22 == - V_28 ) {
if ( V_21 -> V_29 ) {
F_13 ( V_18 ,
L_36 ) ;
F_14 ( V_21 ) ;
}
goto V_23;
}
if ( ! V_22 || F_12 ( V_18 ) )
V_21 -> V_29 = 0 ;
return V_22 ;
}
unsigned int F_15 ( struct V_17 * V_18 , T_2 V_30 ,
int V_15 ,
unsigned int V_31 , unsigned int V_32 )
{
unsigned int V_14 = F_16 ( & V_18 -> V_19 , V_30 , V_31 , V_32 ) ;
unsigned int V_16 ;
if ( F_17 ( & V_18 -> V_19 , V_14 , V_15 , & V_16 ) )
return - 1 ;
return V_16 ;
}
int F_18 ( struct V_17 * V_18 , T_2 V_30 , int V_15 ,
unsigned int V_31 , unsigned int V_32 )
{
unsigned int V_14 = F_16 ( & V_18 -> V_19 , V_30 , V_31 , V_32 ) ;
return F_17 ( & V_18 -> V_19 , V_14 , V_15 , NULL ) ;
}
void F_19 ( struct V_17 * V_18 , const struct V_33 * V_34 )
{
for (; V_34 -> V_30 ; V_34 ++ )
F_18 ( V_18 , V_34 -> V_30 , 0 , V_34 -> V_31 , V_34 -> V_35 ) ;
}
static struct V_36 *
F_20 ( struct V_17 * V_18 , T_2 V_30 )
{
struct V_36 * V_37 ;
F_21 (p, &codec->conn_list, list) {
if ( V_37 -> V_30 == V_30 )
return V_37 ;
}
return NULL ;
}
static int F_22 ( struct V_17 * V_18 , T_2 V_30 , int V_38 ,
const T_2 * V_39 )
{
struct V_36 * V_37 ;
V_37 = F_23 ( sizeof( * V_37 ) + V_38 * sizeof( T_2 ) , V_40 ) ;
if ( ! V_37 )
return - V_41 ;
V_37 -> V_38 = V_38 ;
V_37 -> V_30 = V_30 ;
memcpy ( V_37 -> V_42 , V_39 , V_38 * sizeof( T_2 ) ) ;
F_24 ( & V_37 -> V_39 , & V_18 -> V_43 ) ;
return 0 ;
}
static void F_25 ( struct V_17 * V_18 )
{
while ( ! F_26 ( & V_18 -> V_43 ) ) {
struct V_36 * V_37 ;
V_37 = F_27 ( & V_18 -> V_43 , F_28 ( * V_37 ) , V_39 ) ;
F_29 ( & V_37 -> V_39 ) ;
F_30 ( V_37 ) ;
}
}
static int F_31 ( struct V_17 * V_18 , T_2 V_30 )
{
T_2 V_39 [ 32 ] ;
T_2 * V_44 = V_39 ;
int V_38 ;
V_38 = F_32 ( V_18 , V_30 , V_39 , F_2 ( V_39 ) ) ;
if ( V_38 == - V_45 ) {
V_38 = F_33 ( V_18 , V_30 ) ;
V_44 = F_23 ( sizeof( T_2 ) * V_38 , V_40 ) ;
if ( ! V_44 )
return - V_41 ;
V_38 = F_32 ( V_18 , V_30 , V_44 , V_38 ) ;
}
if ( V_38 >= 0 )
V_38 = F_34 ( V_18 , V_30 , V_38 , V_44 ) ;
if ( V_44 != V_39 )
F_30 ( V_44 ) ;
return V_38 ;
}
int F_35 ( struct V_17 * V_18 , T_2 V_30 ,
const T_2 * * V_46 )
{
bool V_47 = false ;
for (; ; ) {
int V_22 ;
const struct V_36 * V_37 ;
V_37 = F_20 ( V_18 , V_30 ) ;
if ( V_37 ) {
if ( V_46 )
* V_46 = V_37 -> V_42 ;
return V_37 -> V_38 ;
}
if ( F_36 ( V_47 ) )
return - V_48 ;
V_22 = F_31 ( V_18 , V_30 ) ;
if ( V_22 < 0 )
return V_22 ;
V_47 = true ;
}
}
int F_37 ( struct V_17 * V_18 , T_2 V_30 ,
T_2 * V_43 , int V_49 )
{
const T_2 * V_39 ;
int V_38 = F_35 ( V_18 , V_30 , & V_39 ) ;
if ( V_38 > 0 && V_43 ) {
if ( V_38 > V_49 ) {
F_38 ( V_18 , L_37 ,
V_38 , V_30 ) ;
return - V_48 ;
}
memcpy ( V_43 , V_39 , V_38 * sizeof( T_2 ) ) ;
}
return V_38 ;
}
int F_34 ( struct V_17 * V_18 , T_2 V_30 , int V_38 ,
const T_2 * V_39 )
{
struct V_36 * V_37 ;
V_37 = F_20 ( V_18 , V_30 ) ;
if ( V_37 ) {
F_29 ( & V_37 -> V_39 ) ;
F_30 ( V_37 ) ;
}
return F_22 ( V_18 , V_30 , V_38 , V_39 ) ;
}
int F_39 ( struct V_17 * V_18 , T_2 V_50 ,
T_2 V_30 , int V_51 )
{
const T_2 * V_52 ;
int V_5 , V_53 ;
V_53 = F_35 ( V_18 , V_50 , & V_52 ) ;
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ )
if ( V_52 [ V_5 ] == V_30 )
return V_5 ;
if ( ! V_51 )
return - 1 ;
if ( V_51 > 10 ) {
F_13 ( V_18 , L_38 , V_30 ) ;
return - 1 ;
}
V_51 ++ ;
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
unsigned int type = F_40 ( F_41 ( V_18 , V_52 [ V_5 ] ) ) ;
if ( type == V_54 || type == V_55 )
continue;
if ( F_39 ( V_18 , V_52 [ V_5 ] , V_30 , V_51 ) >= 0 )
return V_5 ;
}
return - 1 ;
}
static unsigned int F_42 ( struct V_17 * V_18 , T_2 V_30 )
{
unsigned int V_56 = F_41 ( V_18 , V_30 ) ;
unsigned int V_32 ;
if ( ! V_18 -> V_57 || ! ( V_56 & V_58 ) ||
F_40 ( V_56 ) != V_54 )
return 0 ;
V_32 = F_43 ( & V_18 -> V_19 , V_30 , V_59 ) ;
if ( V_32 == - 1 )
V_32 = 0 ;
return V_32 & V_60 ;
}
int F_44 ( struct V_17 * V_18 , T_2 V_30 ,
T_3 * V_61 , int V_62 )
{
unsigned int V_32 ;
int V_5 , V_63 , V_64 ;
V_32 = F_42 ( V_18 , V_30 ) ;
if ( ! V_32 )
return 0 ;
V_63 = V_32 + 1 ;
V_63 = V_63 < V_62 ? V_63 : V_62 ;
V_64 = 0 ;
while ( V_64 < V_63 ) {
if ( F_45 ( & V_18 -> V_19 , V_30 ,
V_65 , V_64 , & V_32 ) )
break;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_61 [ V_64 ] = ( T_3 ) V_32 ;
V_32 >>= 4 ;
V_64 ++ ;
if ( V_64 >= V_63 )
break;
}
}
return V_64 ;
}
static int F_46 ( struct V_17 * V_18 , T_2 V_66 )
{
int V_5 ;
T_2 V_30 ;
V_18 -> V_56 = F_23 ( V_18 -> V_19 . V_67 * 4 , V_40 ) ;
if ( ! V_18 -> V_56 )
return - V_41 ;
V_30 = V_18 -> V_19 . V_68 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_19 . V_67 ; V_5 ++ , V_30 ++ )
V_18 -> V_56 [ V_5 ] = F_43 ( & V_18 -> V_19 ,
V_30 , V_69 ) ;
return 0 ;
}
static int F_47 ( struct V_17 * V_18 )
{
T_2 V_30 ;
F_48 (nid, codec) {
struct V_70 * V_71 ;
unsigned int V_56 = F_41 ( V_18 , V_30 ) ;
unsigned int V_72 = F_40 ( V_56 ) ;
if ( V_72 != V_54 )
continue;
V_71 = F_49 ( & V_18 -> V_73 ) ;
if ( ! V_71 )
return - V_41 ;
V_71 -> V_30 = V_30 ;
V_71 -> V_1 = F_15 ( V_18 , V_30 , 0 ,
V_74 , 0 ) ;
V_71 -> V_75 = F_15 ( V_18 , V_30 , 0 ,
V_76 ,
0 ) ;
}
return 0 ;
}
static struct V_70 * F_50 ( struct V_17 * V_18 ,
struct V_77 * V_78 ,
T_2 V_30 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_78 -> V_79 ; V_5 ++ ) {
struct V_70 * V_71 = F_51 ( V_78 , V_5 ) ;
if ( V_71 -> V_30 == V_30 )
return V_71 ;
}
return NULL ;
}
int F_52 ( struct V_17 * V_18 , struct V_77 * V_39 ,
T_2 V_30 , unsigned int V_1 )
{
struct V_70 * V_71 ;
V_71 = F_50 ( V_18 , V_39 , V_30 ) ;
if ( ! V_71 ) {
V_71 = F_49 ( V_39 ) ;
if ( ! V_71 )
return - V_41 ;
V_71 -> V_30 = V_30 ;
}
V_71 -> V_1 = V_1 ;
return 0 ;
}
int F_53 ( struct V_17 * V_18 ,
T_2 V_30 , unsigned int V_1 )
{
return F_52 ( V_18 , & V_18 -> V_80 , V_30 , V_1 ) ;
}
unsigned int F_54 ( struct V_17 * V_18 , T_2 V_30 )
{
struct V_70 * V_71 ;
#ifdef F_55
{
unsigned int V_1 = 0 ;
F_8 ( & V_18 -> V_81 ) ;
V_71 = F_50 ( V_18 , & V_18 -> V_82 , V_30 ) ;
if ( V_71 )
V_1 = V_71 -> V_1 ;
F_10 ( & V_18 -> V_81 ) ;
if ( V_1 )
return V_1 ;
}
#endif
V_71 = F_50 ( V_18 , & V_18 -> V_80 , V_30 ) ;
if ( V_71 )
return V_71 -> V_1 ;
V_71 = F_50 ( V_18 , & V_18 -> V_73 , V_30 ) ;
if ( V_71 )
return V_71 -> V_1 ;
return 0 ;
}
int F_56 ( struct V_17 * V_18 , T_2 V_30 ,
unsigned int V_83 )
{
struct V_70 * V_71 ;
V_71 = F_50 ( V_18 , & V_18 -> V_73 , V_30 ) ;
if ( ! V_71 )
return - V_48 ;
V_71 -> V_84 = V_83 ;
return 0 ;
}
int F_57 ( struct V_17 * V_18 , T_2 V_30 )
{
struct V_70 * V_71 ;
V_71 = F_50 ( V_18 , & V_18 -> V_73 , V_30 ) ;
if ( ! V_71 )
return 0 ;
return V_71 -> V_84 ;
}
void F_58 ( struct V_17 * V_18 )
{
int V_5 ;
if ( V_18 -> V_21 -> V_85 )
return;
for ( V_5 = 0 ; V_5 < V_18 -> V_73 . V_79 ; V_5 ++ ) {
struct V_70 * V_71 = F_51 ( & V_18 -> V_73 , V_5 ) ;
F_15 ( V_18 , V_71 -> V_30 , 0 ,
V_86 , 0 ) ;
}
V_18 -> V_87 = 1 ;
}
static void F_59 ( struct V_17 * V_18 )
{
int V_5 ;
if ( ! V_18 -> V_87 )
return;
if ( V_18 -> V_21 -> V_85 )
return;
for ( V_5 = 0 ; V_5 < V_18 -> V_73 . V_79 ; V_5 ++ ) {
struct V_70 * V_71 = F_51 ( & V_18 -> V_73 , V_5 ) ;
F_18 ( V_18 , V_71 -> V_30 , 0 ,
V_86 ,
V_71 -> V_75 ) ;
}
V_18 -> V_87 = 0 ;
}
static void F_60 ( struct V_88 * V_89 )
{
struct V_17 * V_18 =
F_6 ( V_89 , struct V_17 , V_90 . V_89 ) ;
F_61 ( V_18 ) ;
F_62 ( V_18 ) ;
if ( ! V_18 -> V_91 )
return;
F_63 ( & V_18 -> V_90 ,
V_18 -> V_91 ) ;
}
static void F_64 ( struct V_17 * V_18 )
{
F_65 ( & V_18 -> V_80 ) ;
#ifdef F_55
F_65 ( & V_18 -> V_82 ) ;
#endif
F_65 ( & V_18 -> V_73 ) ;
}
static struct V_92 *
F_66 ( struct V_17 * V_18 , T_2 V_30 )
{
struct V_92 * V_37 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_93 . V_79 ; V_5 ++ ) {
V_37 = F_51 ( & V_18 -> V_93 , V_5 ) ;
if ( V_37 -> V_30 == V_30 )
return V_37 ;
}
V_37 = F_49 ( & V_18 -> V_93 ) ;
if ( V_37 )
V_37 -> V_30 = V_30 ;
return V_37 ;
}
static void F_67 ( struct V_94 * V_94 )
{
struct V_95 * V_96 = F_6 ( V_94 , struct V_95 , V_94 ) ;
if ( V_96 -> V_96 )
F_68 ( V_96 -> V_18 -> V_97 , V_96 -> V_96 ) ;
F_69 ( V_96 -> V_98 , V_96 -> V_18 -> V_21 -> V_99 ) ;
F_30 ( V_96 -> V_100 ) ;
F_30 ( V_96 ) ;
}
void F_70 ( struct V_95 * V_96 )
{
F_71 ( & V_96 -> V_94 , F_67 ) ;
}
struct V_95 * F_72 ( struct V_17 * V_18 ,
const char * V_101 , ... )
{
struct V_95 * V_96 ;
T_4 args ;
V_96 = F_73 ( sizeof( * V_96 ) , V_40 ) ;
if ( ! V_96 )
return NULL ;
V_96 -> V_18 = V_18 ;
F_74 ( & V_96 -> V_94 ) ;
va_start ( args , V_101 ) ;
V_96 -> V_100 = F_75 ( V_40 , V_101 , args ) ;
va_end ( args ) ;
if ( ! V_96 -> V_100 ) {
F_30 ( V_96 ) ;
return NULL ;
}
F_76 ( & V_96 -> V_39 , & V_18 -> V_102 ) ;
return V_96 ;
}
static void F_77 ( struct V_17 * V_18 )
{
struct V_95 * V_96 , * V_103 ;
F_78 (pcm, n, &codec->pcm_list_head, list) {
F_79 ( & V_96 -> V_39 ) ;
if ( V_96 -> V_96 )
F_80 ( V_18 -> V_97 , V_96 -> V_96 ) ;
F_70 ( V_96 ) ;
}
}
void F_81 ( struct V_17 * V_18 )
{
if ( V_18 -> V_104 ) {
F_82 ( F_83 ( V_18 ) ) ;
F_84 ( F_83 ( V_18 ) ) ;
V_18 -> V_104 = 0 ;
}
F_85 ( & V_18 -> V_90 ) ;
if ( ! V_18 -> V_105 )
F_86 ( V_18 ) ;
F_77 ( V_18 ) ;
F_87 ( V_18 ) ;
memset ( & V_18 -> V_106 , 0 , sizeof( V_18 -> V_106 ) ) ;
F_88 ( V_18 ) ;
V_18 -> V_107 = NULL ;
V_18 -> V_108 = NULL ;
F_65 ( & V_18 -> V_80 ) ;
F_65 ( & V_18 -> V_93 ) ;
F_65 ( & V_18 -> V_109 ) ;
F_65 ( & V_18 -> V_110 ) ;
V_18 -> V_111 = NULL ;
V_18 -> V_112 = NULL ;
V_18 -> V_113 = 0 ;
F_65 ( & V_18 -> V_114 ) ;
F_65 ( & V_18 -> V_115 ) ;
F_25 ( V_18 ) ;
F_89 ( & V_18 -> V_19 ) ;
}
void F_90 ( struct V_17 * V_18 )
{
if ( V_18 -> V_104 )
return;
if ( F_91 ( F_83 ( V_18 ) ) ) {
F_92 ( V_18 ) ;
F_93 ( & V_18 -> V_19 , true ) ;
F_94 ( F_83 ( V_18 ) ) ;
F_95 ( V_18 ) ;
V_18 -> V_104 = 1 ;
}
}
static int F_96 ( struct V_116 * V_98 )
{
F_90 ( V_98 -> V_117 ) ;
return 0 ;
}
static int F_97 ( struct V_116 * V_98 )
{
struct V_17 * V_18 = V_98 -> V_117 ;
F_87 ( V_18 ) ;
return 0 ;
}
static int F_98 ( struct V_116 * V_98 )
{
struct V_17 * V_18 = V_98 -> V_117 ;
V_18 -> V_105 = 1 ;
F_99 ( & V_18 -> V_19 ) ;
F_93 ( & V_18 -> V_19 , false ) ;
F_100 ( F_83 ( V_18 ) ) ;
return 0 ;
}
static void F_101 ( struct V_98 * V_13 )
{
struct V_17 * V_18 = F_102 ( V_13 ) ;
F_64 ( V_18 ) ;
F_103 ( & V_18 -> V_19 ) ;
F_104 ( V_18 ) ;
F_30 ( V_18 -> V_118 ) ;
F_30 ( V_18 -> V_56 ) ;
F_30 ( V_18 ) ;
}
int F_105 ( struct V_20 * V_21 , struct V_119 * V_97 ,
unsigned int V_120 , struct V_17 * * V_121 )
{
struct V_17 * V_18 ;
char V_122 [ 31 ] ;
T_2 V_123 ;
int V_22 ;
static struct V_124 V_125 = {
. V_126 = F_96 ,
. V_127 = F_97 ,
. V_128 = F_98 ,
} ;
if ( F_36 ( ! V_21 ) )
return - V_48 ;
if ( F_36 ( V_120 > V_129 ) )
return - V_48 ;
V_18 = F_73 ( sizeof( * V_18 ) , V_40 ) ;
if ( ! V_18 )
return - V_41 ;
sprintf ( V_122 , L_39 , V_97 -> V_130 , V_120 ) ;
V_22 = F_106 ( & V_18 -> V_19 , & V_21 -> V_19 , V_122 ,
V_120 ) ;
if ( V_22 < 0 ) {
F_30 ( V_18 ) ;
return V_22 ;
}
V_18 -> V_19 . V_13 . V_131 = F_101 ;
V_18 -> V_19 . type = V_132 ;
V_18 -> V_19 . V_133 = F_5 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_97 = V_97 ;
V_18 -> V_27 = V_120 ;
F_107 ( & V_18 -> V_134 ) ;
F_107 ( & V_18 -> V_135 ) ;
F_108 ( & V_18 -> V_114 , sizeof( struct V_136 ) , 32 ) ;
F_108 ( & V_18 -> V_115 , sizeof( struct V_136 ) , 32 ) ;
F_108 ( & V_18 -> V_73 , sizeof( struct V_70 ) , 16 ) ;
F_108 ( & V_18 -> V_80 , sizeof( struct V_70 ) , 16 ) ;
F_108 ( & V_18 -> V_93 , sizeof( struct V_92 ) , 8 ) ;
F_108 ( & V_18 -> V_109 , sizeof( struct V_137 ) , 16 ) ;
F_108 ( & V_18 -> V_138 , sizeof( struct V_139 ) , 16 ) ;
F_108 ( & V_18 -> V_110 , sizeof( struct V_33 * ) , 8 ) ;
F_109 ( & V_18 -> V_43 ) ;
F_109 ( & V_18 -> V_102 ) ;
F_110 ( & V_18 -> V_90 , F_60 ) ;
V_18 -> V_140 = - 1 ;
V_18 -> V_141 = V_142 ;
#ifdef F_111
V_18 -> V_143 = V_144 ;
#endif
F_112 ( V_18 ) ;
if ( V_18 -> V_21 -> V_118 ) {
V_18 -> V_118 = F_113 ( V_18 -> V_21 -> V_118 , V_40 ) ;
if ( ! V_18 -> V_118 ) {
V_22 = - V_145 ;
goto error;
}
}
V_123 = V_18 -> V_19 . V_146 ? V_18 -> V_19 . V_146 : V_18 -> V_19 . V_147 ;
V_22 = F_46 ( V_18 , V_123 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_47 ( V_18 ) ;
if ( V_22 < 0 )
goto error;
F_114 ( V_18 , V_148 ) ;
F_115 ( V_18 ) ;
F_116 ( V_18 ) ;
sprintf ( V_122 , L_40 , V_18 -> V_19 . V_149 ,
V_18 -> V_19 . V_150 , V_18 -> V_19 . V_151 ) ;
F_117 ( V_97 , V_122 ) ;
V_22 = F_118 ( V_97 , V_152 , V_18 , & V_125 ) ;
if ( V_22 < 0 )
goto error;
if ( V_121 )
* V_121 = V_18 ;
return 0 ;
error:
F_100 ( F_83 ( V_18 ) ) ;
return V_22 ;
}
int F_119 ( struct V_17 * V_18 )
{
T_2 V_123 ;
int V_22 ;
V_22 = F_120 ( & V_18 -> V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_30 ( V_18 -> V_56 ) ;
V_123 = V_18 -> V_19 . V_146 ? V_18 -> V_19 . V_146 : V_18 -> V_19 . V_147 ;
V_22 = F_46 ( V_18 , V_123 ) ;
if ( V_22 < 0 )
return V_22 ;
F_65 ( & V_18 -> V_73 ) ;
V_22 = F_47 ( V_18 ) ;
return V_22 ;
}
static void F_121 ( struct V_17 * V_18 ,
struct V_92 * V_37 , T_2 V_30 ,
T_1 V_153 , int V_154 )
{
unsigned int V_155 , V_156 ;
if ( V_37 -> V_153 != V_153 || V_37 -> V_154 != V_154 ) {
V_155 = F_15 ( V_18 , V_30 , 0 , V_157 , 0 ) ;
V_156 = ( V_153 << 4 ) | V_154 ;
if ( V_155 != V_156 )
F_18 ( V_18 , V_30 , 0 ,
V_158 ,
V_156 ) ;
V_37 -> V_153 = V_153 ;
V_37 -> V_154 = V_154 ;
}
}
static void F_122 ( struct V_17 * V_18 , struct V_92 * V_37 ,
T_2 V_30 , int V_159 )
{
unsigned int V_155 ;
if ( V_37 -> V_160 != V_159 ) {
V_155 = F_15 ( V_18 , V_30 , 0 ,
V_161 , 0 ) ;
if ( V_155 != V_159 ) {
F_123 ( 1 ) ;
F_18 ( V_18 , V_30 , 0 ,
V_162 ,
V_159 ) ;
}
V_37 -> V_160 = V_159 ;
}
}
void F_124 ( struct V_17 * V_18 , T_2 V_30 ,
T_1 V_153 ,
int V_154 , int V_159 )
{
struct V_17 * V_163 ;
struct V_92 * V_37 ;
int type ;
int V_5 ;
if ( ! V_30 )
return;
F_13 ( V_18 ,
L_41 ,
V_30 , V_153 , V_154 , V_159 ) ;
V_37 = F_66 ( V_18 , V_30 ) ;
if ( ! V_37 )
return;
if ( V_18 -> V_106 . V_164 )
V_18 -> V_106 . V_164 ( V_18 , V_30 , true ) ;
if ( V_18 -> V_165 )
F_122 ( V_18 , V_37 , V_30 , V_159 ) ;
F_121 ( V_18 , V_37 , V_30 , V_153 , V_154 ) ;
if ( ! V_18 -> V_165 )
F_122 ( V_18 , V_37 , V_30 , V_159 ) ;
V_37 -> V_166 = 1 ;
V_37 -> V_167 = 0 ;
type = F_40 ( F_41 ( V_18 , V_30 ) ) ;
F_125 (c, codec->bus) {
for ( V_5 = 0 ; V_5 < V_163 -> V_93 . V_79 ; V_5 ++ ) {
V_37 = F_51 ( & V_163 -> V_93 , V_5 ) ;
if ( ! V_37 -> V_166 && V_37 -> V_153 == V_153 &&
F_40 ( F_41 ( V_163 , V_37 -> V_30 ) ) == type )
V_37 -> V_167 = 1 ;
}
}
}
void F_126 ( struct V_17 * V_18 , T_2 V_30 ,
int V_168 )
{
struct V_92 * V_37 ;
if ( ! V_30 )
return;
if ( V_18 -> V_169 )
V_168 = 1 ;
F_13 ( V_18 , L_42 , V_30 ) ;
V_37 = F_66 ( V_18 , V_30 ) ;
if ( V_37 ) {
if ( V_168 )
F_127 ( V_18 , V_37 ) ;
else
V_37 -> V_166 = 0 ;
}
}
static void F_127 ( struct V_17 * V_18 ,
struct V_92 * V_170 )
{
T_2 V_30 = V_170 -> V_30 ;
if ( V_170 -> V_153 || V_170 -> V_154 )
F_18 ( V_18 , V_30 , 0 , V_158 , 0 ) ;
if ( V_170 -> V_160 )
F_18 ( V_18 , V_30 , 0 , V_162 , 0
) ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
V_170 -> V_30 = V_30 ;
if ( V_18 -> V_106 . V_164 )
V_18 -> V_106 . V_164 ( V_18 , V_30 , false ) ;
}
static void F_128 ( struct V_17 * V_18 )
{
struct V_17 * V_163 ;
int V_5 ;
F_125 (c, codec->bus) {
for ( V_5 = 0 ; V_5 < V_163 -> V_93 . V_79 ; V_5 ++ ) {
struct V_92 * V_37 ;
V_37 = F_51 ( & V_163 -> V_93 , V_5 ) ;
if ( V_37 -> V_167 )
F_127 ( V_163 , V_37 ) ;
}
}
}
static void F_129 ( struct V_17 * V_18 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_93 . V_79 ; V_5 ++ ) {
struct V_92 * V_37 = F_51 ( & V_18 -> V_93 , V_5 ) ;
if ( V_37 -> V_153 )
F_127 ( V_18 , V_37 ) ;
}
}
T_1 F_130 ( struct V_17 * V_18 , T_2 V_30 , int V_171 )
{
if ( ! ( F_41 ( V_18 , V_30 ) & V_172 ) )
V_30 = V_18 -> V_19 . V_146 ;
return F_131 ( V_18 , V_30 ,
V_171 == V_173 ?
V_174 : V_175 ) ;
}
bool F_132 ( struct V_17 * V_18 , T_2 V_30 ,
int V_176 , unsigned int V_177 )
{
if ( ! V_30 )
return false ;
if ( F_41 ( V_18 , V_30 ) & ( 1 << ( V_176 + 1 ) ) )
if ( F_130 ( V_18 , V_30 , V_176 ) & V_177 )
return true ;
return false ;
}
int F_133 ( struct V_17 * V_18 , T_2 V_30 , int V_176 ,
unsigned int V_178 )
{
unsigned int V_32 ;
F_134 ( V_18 , V_30 ,
F_41 ( V_18 , V_30 ) | V_172 ) ;
V_32 = V_176 == V_173 ? V_174 : V_175 ;
return F_135 ( & V_18 -> V_19 , V_30 , V_32 , V_178 ) ;
}
int F_136 ( struct V_17 * V_18 , T_2 V_30 ,
int V_179 , int V_176 , int V_180 , int V_181 , int V_83 )
{
unsigned int V_14 = F_137 ( V_30 , V_179 , V_176 , V_180 ) ;
if ( ( F_130 ( V_18 , V_30 , V_176 ) &
( V_182 | V_183 ) ) == V_183 )
V_14 |= V_184 ;
return F_138 ( & V_18 -> V_19 , V_14 , V_181 , V_83 ) ;
}
int F_139 ( struct V_17 * V_18 , T_2 V_30 ,
int V_171 , int V_180 , int V_181 , int V_83 )
{
int V_179 , V_185 = 0 ;
if ( F_36 ( V_181 & ~ 0xff ) )
V_181 &= 0xff ;
for ( V_179 = 0 ; V_179 < 2 ; V_179 ++ )
V_185 |= F_136 ( V_18 , V_30 , V_179 , V_171 ,
V_180 , V_181 , V_83 ) ;
return V_185 ;
}
int F_140 ( struct V_17 * V_18 , T_2 V_30 , int V_179 ,
int V_176 , int V_180 , int V_181 , int V_83 )
{
int V_186 ;
if ( ! V_18 -> V_19 . V_187 )
return - V_48 ;
F_141 ( V_18 -> V_19 . V_187 , true ) ;
V_186 = F_142 ( V_18 , V_30 , V_179 , V_176 , V_180 ) ;
F_141 ( V_18 -> V_19 . V_187 , false ) ;
if ( V_186 >= 0 )
return 0 ;
return F_136 ( V_18 , V_30 , V_179 , V_176 , V_180 , V_181 , V_83 ) ;
}
int F_143 ( struct V_17 * V_18 , T_2 V_30 ,
int V_176 , int V_180 , int V_181 , int V_83 )
{
int V_179 , V_185 = 0 ;
if ( F_36 ( V_181 & ~ 0xff ) )
V_181 &= 0xff ;
for ( V_179 = 0 ; V_179 < 2 ; V_179 ++ )
V_185 |= F_140 ( V_18 , V_30 , V_179 , V_176 ,
V_180 , V_181 , V_83 ) ;
return V_185 ;
}
static T_1 F_144 ( struct V_17 * V_18 , T_2 V_30 , int V_176 ,
unsigned int V_188 )
{
T_1 V_178 = F_130 ( V_18 , V_30 , V_176 ) ;
V_178 = ( V_178 & V_189 ) >> V_190 ;
if ( V_188 < V_178 )
V_178 -= V_188 ;
return V_178 ;
}
int F_145 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_5 V_30 = F_147 ( V_192 ) ;
T_3 V_195 = F_148 ( V_192 ) ;
int V_176 = F_149 ( V_192 ) ;
unsigned int V_188 = F_150 ( V_192 ) ;
V_194 -> type = V_196 ;
V_194 -> V_197 = V_195 == 3 ? 2 : 1 ;
V_194 -> V_198 . integer . V_199 = 0 ;
V_194 -> V_198 . integer . V_200 = F_144 ( V_18 , V_30 , V_176 , V_188 ) ;
if ( ! V_194 -> V_198 . integer . V_200 ) {
F_151 ( V_18 ,
L_43 ,
V_30 , V_192 -> V_201 . V_100 ) ;
return - V_48 ;
}
return 0 ;
}
static inline unsigned int
F_152 ( struct V_17 * V_18 , T_2 V_30 ,
int V_179 , int V_176 , int V_180 , unsigned int V_188 )
{
unsigned int V_83 ;
V_83 = F_142 ( V_18 , V_30 , V_179 , V_176 , V_180 ) ;
V_83 &= V_202 ;
if ( V_83 >= V_188 )
V_83 -= V_188 ;
else
V_83 = 0 ;
return V_83 ;
}
static inline int
F_153 ( struct V_17 * V_18 , T_2 V_30 ,
int V_179 , int V_176 , int V_180 , unsigned int V_188 ,
unsigned int V_83 )
{
unsigned int V_203 ;
if ( V_83 > 0 )
V_83 += V_188 ;
V_203 = F_144 ( V_18 , V_30 , V_176 , 0 ) ;
if ( V_83 > V_203 )
V_83 = V_203 ;
return F_136 ( V_18 , V_30 , V_179 , V_176 , V_180 ,
V_202 , V_83 ) ;
}
int F_154 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_2 V_30 = F_147 ( V_192 ) ;
int V_195 = F_148 ( V_192 ) ;
int V_176 = F_149 ( V_192 ) ;
int V_180 = F_155 ( V_192 ) ;
unsigned int V_188 = F_150 ( V_192 ) ;
long * V_206 = V_205 -> V_198 . integer . V_198 ;
if ( V_195 & 1 )
* V_206 ++ = F_152 ( V_18 , V_30 , 0 , V_176 , V_180 , V_188 ) ;
if ( V_195 & 2 )
* V_206 = F_152 ( V_18 , V_30 , 1 , V_176 , V_180 , V_188 ) ;
return 0 ;
}
int F_156 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_2 V_30 = F_147 ( V_192 ) ;
int V_195 = F_148 ( V_192 ) ;
int V_176 = F_149 ( V_192 ) ;
int V_180 = F_155 ( V_192 ) ;
unsigned int V_188 = F_150 ( V_192 ) ;
long * V_206 = V_205 -> V_198 . integer . V_198 ;
int V_207 = 0 ;
if ( V_195 & 1 ) {
V_207 = F_153 ( V_18 , V_30 , 0 , V_176 , V_180 , V_188 , * V_206 ) ;
V_206 ++ ;
}
if ( V_195 & 2 )
V_207 |= F_153 ( V_18 , V_30 , 1 , V_176 , V_180 , V_188 , * V_206 ) ;
return V_207 ;
}
int F_157 ( struct V_191 * V_192 , int V_208 ,
unsigned int V_209 , unsigned int T_6 * V_210 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_2 V_30 = F_147 ( V_192 ) ;
int V_176 = F_149 ( V_192 ) ;
unsigned int V_188 = F_150 ( V_192 ) ;
bool V_211 = F_158 ( V_192 ) ;
T_1 V_178 , V_212 , V_213 ;
if ( V_209 < 4 * sizeof( unsigned int ) )
return - V_41 ;
V_178 = F_130 ( V_18 , V_30 , V_176 ) ;
V_213 = ( V_178 & V_214 ) >> V_215 ;
V_213 = ( V_213 + 1 ) * 25 ;
V_212 = - ( ( V_178 & V_216 ) >> V_217 ) ;
V_212 += V_188 ;
V_212 = ( ( int ) V_212 ) * ( ( int ) V_213 ) ;
if ( V_211 || ( V_178 & V_183 ) )
V_213 |= V_218 ;
if ( F_159 ( V_219 , V_210 ) )
return - V_220 ;
if ( F_159 ( 2 * sizeof( unsigned int ) , V_210 + 1 ) )
return - V_220 ;
if ( F_159 ( V_212 , V_210 + 2 ) )
return - V_220 ;
if ( F_159 ( V_213 , V_210 + 3 ) )
return - V_220 ;
return 0 ;
}
void F_160 ( struct V_17 * V_18 , T_2 V_30 , int V_176 ,
unsigned int * V_221 )
{
T_1 V_178 ;
int V_53 , V_222 ;
V_178 = F_130 ( V_18 , V_30 , V_176 ) ;
V_53 = ( V_178 & V_189 ) >> V_190 ;
V_222 = ( V_178 & V_214 ) >> V_215 ;
V_222 = ( V_222 + 1 ) * 25 ;
V_221 [ 0 ] = V_219 ;
V_221 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_221 [ 2 ] = - V_53 * V_222 ;
V_221 [ 3 ] = V_222 ;
}
static struct V_191 *
F_161 ( struct V_17 * V_18 , const char * V_100 , int V_13 , int V_180 )
{
struct V_223 V_201 ;
memset ( & V_201 , 0 , sizeof( V_201 ) ) ;
V_201 . V_224 = V_225 ;
V_201 . V_98 = V_13 ;
V_201 . V_226 = V_180 ;
if ( F_36 ( strlen ( V_100 ) >= sizeof( V_201 . V_100 ) ) )
return NULL ;
strcpy ( V_201 . V_100 , V_100 ) ;
return F_162 ( V_18 -> V_97 , & V_201 ) ;
}
struct V_191 * F_163 ( struct V_17 * V_18 ,
const char * V_100 )
{
return F_161 ( V_18 , V_100 , 0 , 0 ) ;
}
static int F_164 ( struct V_17 * V_18 , const char * V_100 ,
int V_227 )
{
int V_5 , V_180 ;
for ( V_5 = 0 , V_180 = V_227 ; V_5 < 16 ; V_5 ++ , V_180 ++ ) {
if ( ! F_161 ( V_18 , V_100 , 0 , V_180 ) )
return V_180 ;
}
return - V_228 ;
}
int F_165 ( struct V_17 * V_18 , T_2 V_30 ,
struct V_191 * V_229 )
{
int V_22 ;
unsigned short V_15 = 0 ;
struct V_136 * V_230 ;
if ( V_229 -> V_201 . V_231 & V_232 ) {
V_15 |= V_233 ;
if ( V_30 == 0 )
V_30 = F_166 ( V_229 -> V_234 ) ;
}
if ( ( V_229 -> V_201 . V_231 & V_235 ) != 0 && V_30 == 0 )
V_30 = V_229 -> V_201 . V_231 & 0xffff ;
if ( V_229 -> V_201 . V_231 & ( V_235 | V_232 ) )
V_229 -> V_201 . V_231 = 0 ;
V_22 = F_167 ( V_18 -> V_97 , V_229 ) ;
if ( V_22 < 0 )
return V_22 ;
V_230 = F_49 ( & V_18 -> V_114 ) ;
if ( ! V_230 )
return - V_41 ;
V_230 -> V_229 = V_229 ;
V_230 -> V_30 = V_30 ;
V_230 -> V_15 = V_15 ;
return 0 ;
}
int F_168 ( struct V_17 * V_18 , struct V_191 * V_229 ,
unsigned int V_226 , T_2 V_30 )
{
struct V_136 * V_230 ;
if ( V_30 > 0 ) {
V_230 = F_49 ( & V_18 -> V_115 ) ;
if ( ! V_230 )
return - V_41 ;
V_230 -> V_229 = V_229 ;
V_230 -> V_226 = V_226 ;
V_230 -> V_30 = V_30 ;
return 0 ;
}
F_38 ( V_18 , L_44 ,
V_229 -> V_201 . V_100 , V_229 -> V_201 . V_226 , V_226 ) ;
return - V_48 ;
}
void F_86 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_136 * V_236 = V_18 -> V_114 . V_39 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_114 . V_79 ; V_5 ++ )
F_169 ( V_18 -> V_97 , V_236 [ V_5 ] . V_229 ) ;
F_65 ( & V_18 -> V_114 ) ;
F_65 ( & V_18 -> V_115 ) ;
}
int F_170 ( struct V_20 * V_21 )
{
struct V_119 * V_97 = V_21 -> V_97 ;
struct V_17 * V_18 ;
F_171 ( & V_97 -> V_237 ) ;
if ( V_97 -> V_85 )
goto V_238;
V_97 -> V_85 = 1 ;
if ( ! F_26 ( & V_97 -> V_239 ) )
goto V_240;
F_125 (codec, bus) {
struct V_95 * V_241 ;
F_21 (cpcm, &codec->pcm_list_head, list) {
if ( ! V_241 -> V_96 )
continue;
if ( V_241 -> V_96 -> V_242 [ 0 ] . V_243 ||
V_241 -> V_96 -> V_242 [ 1 ] . V_243 )
goto V_240;
}
}
F_172 ( & V_97 -> V_237 ) ;
return 0 ;
V_240:
V_97 -> V_85 = 0 ;
V_238:
F_172 ( & V_97 -> V_237 ) ;
return - V_48 ;
}
void F_173 ( struct V_20 * V_21 )
{
struct V_119 * V_97 = V_21 -> V_97 ;
F_171 ( & V_97 -> V_237 ) ;
V_97 -> V_85 = 0 ;
F_172 ( & V_97 -> V_237 ) ;
}
int F_174 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_21 ;
if ( F_170 ( V_21 ) < 0 )
return - V_228 ;
F_99 ( & V_18 -> V_19 ) ;
F_173 ( V_21 ) ;
return 0 ;
}
static int F_175 ( struct V_17 * V_18 , const char * const * V_244 ,
const char * V_245 , T_7 V_246 , void * V_247 )
{
struct V_136 * V_236 ;
const char * const * V_248 ;
int V_5 , V_22 ;
V_236 = V_18 -> V_114 . V_39 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_114 . V_79 ; V_5 ++ ) {
struct V_191 * V_249 = V_236 [ V_5 ] . V_229 ;
if ( ! V_249 || V_249 -> V_201 . V_224 != V_225 )
continue;
for ( V_248 = V_244 ; * V_248 ; V_248 ++ ) {
char V_250 [ sizeof( V_249 -> V_201 . V_100 ) ] ;
const char * V_100 = * V_248 ;
if ( V_245 ) {
snprintf ( V_250 , sizeof( V_250 ) , L_45 ,
V_100 , V_245 ) ;
V_100 = V_250 ;
}
if ( ! strcmp ( V_249 -> V_201 . V_100 , V_100 ) ) {
V_22 = V_246 ( V_18 , V_247 , V_249 ) ;
if ( V_22 )
return V_22 ;
break;
}
}
}
return 0 ;
}
static int F_176 ( struct V_17 * V_18 ,
void * V_247 , struct V_191 * V_249 )
{
return 1 ;
}
static int F_177 ( struct V_17 * V_18 ,
struct V_191 * V_229 , int * V_251 )
{
int V_210 [ 4 ] ;
const int * V_221 = NULL ;
int V_83 = - 1 ;
if ( V_229 -> V_252 [ 0 ] . V_253 & V_254 ) {
T_8 V_255 = F_178 () ;
F_179 ( F_180 () ) ;
if ( ! V_229 -> V_221 . V_163 ( V_229 , 0 , sizeof( V_210 ) , V_210 ) )
V_221 = V_210 ;
F_179 ( V_255 ) ;
} else if ( V_229 -> V_252 [ 0 ] . V_253 & V_256 )
V_221 = V_229 -> V_221 . V_37 ;
if ( V_221 && V_221 [ 0 ] == V_219 ) {
int V_222 = V_221 [ 3 ] ;
V_222 &= ~ V_218 ;
if ( ! V_222 )
return - 1 ;
if ( * V_251 && * V_251 != V_222 ) {
F_38 ( V_18 , L_46 ,
- * V_251 , V_222 ) ;
return - 1 ;
}
* V_251 = V_222 ;
V_83 = - V_221 [ 2 ] / V_222 ;
}
return V_83 ;
}
static int F_181 ( struct V_191 * V_229 , int V_83 )
{
struct V_204 * V_205 ;
V_205 = F_73 ( sizeof( * V_205 ) , V_40 ) ;
if ( ! V_205 )
return - V_41 ;
V_205 -> V_198 . integer . V_198 [ 0 ] = V_83 ;
V_205 -> V_198 . integer . V_198 [ 1 ] = V_83 ;
V_229 -> V_257 ( V_229 , V_205 ) ;
F_30 ( V_205 ) ;
return 0 ;
}
static int F_182 ( struct V_17 * V_18 ,
void * V_247 , struct V_191 * V_258 )
{
int V_259 = F_177 ( V_18 , V_258 , V_247 ) ;
if ( V_259 > 0 )
F_181 ( V_258 , V_259 ) ;
return 0 ;
}
static int F_183 ( struct V_17 * V_18 ,
void * V_247 , struct V_191 * V_258 )
{
return F_181 ( V_258 , 1 ) ;
}
static int F_184 ( struct V_17 * V_18 ,
void * V_247 , struct V_191 * V_258 )
{
return F_185 ( V_247 , V_258 ) ;
}
int F_186 ( struct V_17 * V_18 , char * V_100 ,
unsigned int * V_221 , const char * const * V_244 ,
const char * V_245 , bool V_260 ,
struct V_191 * * V_261 )
{
struct V_191 * V_229 ;
int V_22 ;
if ( V_261 )
* V_261 = NULL ;
V_22 = F_175 ( V_18 , V_244 , V_245 , F_176 , NULL ) ;
if ( V_22 != 1 ) {
F_13 ( V_18 , L_47 , V_100 ) ;
return 0 ;
}
V_229 = F_187 ( V_100 , V_221 ) ;
if ( ! V_229 )
return - V_41 ;
V_22 = F_165 ( V_18 , 0 , V_229 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_175 ( V_18 , V_244 , V_245 , F_184 , V_229 ) ;
if ( V_22 < 0 )
return V_22 ;
F_181 ( V_229 , 0 ) ;
if ( V_260 ) {
int V_222 = 0 ;
F_175 ( V_18 , V_244 , V_245 ,
V_221 ? F_182 : F_183 , & V_222 ) ;
}
if ( V_261 )
* V_261 = V_229 ;
return 0 ;
}
static int F_188 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
static const char * const V_262 [] = {
L_48 , L_49 , L_50
} ;
return F_189 ( V_194 , 1 , 3 , V_262 ) ;
}
static int F_190 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_263 * V_264 = F_146 ( V_192 ) ;
V_205 -> V_198 . V_265 . V_230 [ 0 ] = V_264 -> V_266 ;
return 0 ;
}
static int F_191 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_263 * V_264 = F_146 ( V_192 ) ;
unsigned int V_267 = V_264 -> V_266 ;
V_264 -> V_266 = V_205 -> V_198 . V_265 . V_230 [ 0 ] ;
if ( V_264 -> V_266 > V_268 )
V_264 -> V_266 = V_268 ;
if ( V_267 == V_264 -> V_266 )
return 0 ;
F_192 ( V_264 ) ;
return 1 ;
}
static void F_193 ( void * V_269 , int V_270 )
{
struct V_263 * V_264 = V_269 ;
if ( V_264 -> V_266 != V_268 )
V_270 = V_264 -> V_266 ;
V_264 -> V_264 ( V_264 -> V_18 , V_270 ) ;
}
int F_194 ( struct V_17 * V_18 ,
struct V_263 * V_264 ,
bool V_271 )
{
struct V_191 * V_229 ;
if ( ! V_264 -> V_264 || ! V_264 -> V_272 )
return 0 ;
V_264 -> V_18 = V_18 ;
V_264 -> V_266 = V_268 ;
F_195 ( V_264 -> V_272 , F_193 , V_264 ) ;
if ( ! V_271 )
return 0 ;
V_229 = F_196 ( & V_273 , V_264 ) ;
if ( ! V_229 )
return - V_41 ;
return F_165 ( V_18 , 0 , V_229 ) ;
}
void F_192 ( struct V_263 * V_264 )
{
if ( ! V_264 -> V_264 || ! V_264 -> V_18 )
return;
if ( V_264 -> V_18 -> V_21 -> V_85 )
return;
F_197 ( V_264 -> V_272 ) ;
}
int F_198 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
int V_195 = F_148 ( V_192 ) ;
V_194 -> type = V_274 ;
V_194 -> V_197 = V_195 == 3 ? 2 : 1 ;
V_194 -> V_198 . integer . V_199 = 0 ;
V_194 -> V_198 . integer . V_200 = 1 ;
return 0 ;
}
int F_199 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_2 V_30 = F_147 ( V_192 ) ;
int V_195 = F_148 ( V_192 ) ;
int V_176 = F_149 ( V_192 ) ;
int V_180 = F_155 ( V_192 ) ;
long * V_206 = V_205 -> V_198 . integer . V_198 ;
if ( V_195 & 1 )
* V_206 ++ = ( F_142 ( V_18 , V_30 , 0 , V_176 , V_180 ) &
V_275 ) ? 0 : 1 ;
if ( V_195 & 2 )
* V_206 = ( F_142 ( V_18 , V_30 , 1 , V_176 , V_180 ) &
V_275 ) ? 0 : 1 ;
return 0 ;
}
int F_200 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_2 V_30 = F_147 ( V_192 ) ;
int V_195 = F_148 ( V_192 ) ;
int V_176 = F_149 ( V_192 ) ;
int V_180 = F_155 ( V_192 ) ;
long * V_206 = V_205 -> V_198 . integer . V_198 ;
int V_207 = 0 ;
if ( V_195 & 1 ) {
V_207 = F_136 ( V_18 , V_30 , 0 , V_176 , V_180 ,
V_275 ,
* V_206 ? 0 : V_275 ) ;
V_206 ++ ;
}
if ( V_195 & 2 )
V_207 |= F_136 ( V_18 , V_30 , 1 , V_176 , V_180 ,
V_275 ,
* V_206 ? 0 : V_275 ) ;
F_201 ( V_18 , V_30 ) ;
return V_207 ;
}
int F_202 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
unsigned long V_276 ;
int V_22 ;
F_8 ( & V_18 -> V_135 ) ;
V_276 = V_192 -> V_234 ;
V_192 -> V_234 = V_276 & ~ V_277 ;
V_22 = F_199 ( V_192 , V_205 ) ;
V_192 -> V_234 = V_276 ;
F_10 ( & V_18 -> V_135 ) ;
return V_22 ;
}
int F_203 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
unsigned long V_276 ;
int V_5 , V_278 , V_22 = 0 , V_207 = 0 ;
F_8 ( & V_18 -> V_135 ) ;
V_276 = V_192 -> V_234 ;
V_278 = ( V_276 & V_277 ) >> V_279 ;
for ( V_5 = 0 ; V_5 < V_278 ; V_5 ++ ) {
V_192 -> V_234 = ( V_276 & ~ V_277 ) |
( V_5 << V_279 ) ;
V_22 = F_200 ( V_192 , V_205 ) ;
if ( V_22 < 0 )
break;
V_207 |= V_22 ;
}
V_192 -> V_234 = V_276 ;
F_10 ( & V_18 -> V_135 ) ;
return V_22 < 0 ? V_22 : V_207 ;
}
int F_204 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
struct V_280 * V_163 ;
int V_22 ;
F_8 ( & V_18 -> V_135 ) ;
V_163 = (struct V_280 * ) V_192 -> V_234 ;
V_192 -> V_234 = * V_163 -> V_281 ;
V_22 = V_163 -> V_282 -> V_283 ( V_192 , V_194 ) ;
V_192 -> V_234 = ( long ) V_163 ;
F_10 ( & V_18 -> V_135 ) ;
return V_22 ;
}
int F_205 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
struct V_280 * V_163 ;
int V_22 ;
F_8 ( & V_18 -> V_135 ) ;
V_163 = (struct V_280 * ) V_192 -> V_234 ;
V_192 -> V_234 = * V_163 -> V_281 ;
V_22 = V_163 -> V_282 -> V_284 ( V_192 , V_205 ) ;
V_192 -> V_234 = ( long ) V_163 ;
F_10 ( & V_18 -> V_135 ) ;
return V_22 ;
}
int F_206 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
struct V_280 * V_163 ;
unsigned long * V_285 ;
int V_22 = 0 , V_207 = 0 ;
F_8 ( & V_18 -> V_135 ) ;
V_163 = (struct V_280 * ) V_192 -> V_234 ;
for ( V_285 = V_163 -> V_281 ; * V_285 ; V_285 ++ ) {
V_192 -> V_234 = * V_285 ;
V_22 = V_163 -> V_282 -> V_257 ( V_192 , V_205 ) ;
if ( V_22 < 0 )
break;
V_207 |= V_22 ;
}
V_192 -> V_234 = ( long ) V_163 ;
F_10 ( & V_18 -> V_135 ) ;
return V_22 < 0 ? V_22 : V_207 ;
}
int F_207 ( struct V_191 * V_192 , int V_208 ,
unsigned int V_209 , unsigned int T_6 * V_221 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
struct V_280 * V_163 ;
int V_22 ;
F_8 ( & V_18 -> V_135 ) ;
V_163 = (struct V_280 * ) V_192 -> V_234 ;
V_192 -> V_234 = * V_163 -> V_281 ;
V_22 = V_163 -> V_282 -> V_221 ( V_192 , V_208 , V_209 , V_221 ) ;
V_192 -> V_234 = ( long ) V_163 ;
F_10 ( & V_18 -> V_135 ) ;
return V_22 ;
}
static int F_208 ( struct V_191 * V_192 ,
struct V_193 * V_194 )
{
V_194 -> type = V_286 ;
V_194 -> V_197 = 1 ;
return 0 ;
}
static int F_209 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
V_205 -> V_198 . V_287 . V_288 [ 0 ] = V_289 |
V_290 |
V_291 |
V_292 ;
V_205 -> V_198 . V_287 . V_288 [ 1 ] = V_293 |
V_294 ;
return 0 ;
}
static int F_210 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
V_205 -> V_198 . V_287 . V_288 [ 0 ] = V_289 |
V_290 |
V_295 ;
return 0 ;
}
static int F_211 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
int V_180 = V_192 -> V_234 ;
struct V_137 * V_296 ;
F_8 ( & V_18 -> V_134 ) ;
V_296 = F_51 ( & V_18 -> V_109 , V_180 ) ;
V_205 -> V_198 . V_287 . V_288 [ 0 ] = V_296 -> V_288 & 0xff ;
V_205 -> V_198 . V_287 . V_288 [ 1 ] = ( V_296 -> V_288 >> 8 ) & 0xff ;
V_205 -> V_198 . V_287 . V_288 [ 2 ] = ( V_296 -> V_288 >> 16 ) & 0xff ;
V_205 -> V_198 . V_287 . V_288 [ 3 ] = ( V_296 -> V_288 >> 24 ) & 0xff ;
F_10 ( & V_18 -> V_134 ) ;
return 0 ;
}
static unsigned short F_212 ( unsigned int V_297 )
{
unsigned short V_83 = 0 ;
if ( V_297 & V_289 )
V_83 |= V_298 ;
if ( V_297 & V_290 )
V_83 |= V_299 ;
if ( V_297 & V_289 ) {
if ( ( V_297 & V_300 ) ==
V_295 )
V_83 |= V_301 ;
} else {
if ( ( V_297 & V_302 ) ==
V_291 )
V_83 |= V_301 ;
if ( ! ( V_297 & V_292 ) )
V_83 |= V_303 ;
if ( V_297 & ( V_294 << 8 ) )
V_83 |= V_304 ;
V_83 |= V_297 & ( V_293 << 8 ) ;
}
return V_83 ;
}
static unsigned int F_213 ( unsigned short V_83 )
{
unsigned int V_297 = 0 ;
if ( V_83 & V_299 )
V_297 |= V_290 ;
if ( V_83 & V_298 )
V_297 |= V_289 ;
if ( V_297 & V_289 ) {
if ( V_83 & V_301 )
V_297 |= V_295 ;
} else {
if ( V_83 & V_301 )
V_297 |= V_291 ;
if ( ! ( V_83 & V_303 ) )
V_297 |= V_292 ;
if ( V_83 & V_304 )
V_297 |= ( V_294 << 8 ) ;
V_297 |= V_83 & ( 0x7f << 8 ) ;
}
return V_297 ;
}
static void F_214 ( struct V_17 * V_18 , T_2 V_30 ,
int V_181 , int V_83 )
{
const T_2 * V_305 ;
F_215 ( & V_18 -> V_19 , V_30 , V_306 ,
V_181 , V_83 ) ;
V_305 = V_18 -> V_112 ;
if ( ! V_305 )
return;
for (; * V_305 ; V_305 ++ )
F_215 ( & V_18 -> V_19 , * V_305 ,
V_306 , V_181 , V_83 ) ;
}
static inline void F_216 ( struct V_17 * V_18 , T_2 V_30 ,
int V_307 , int V_308 )
{
unsigned int V_181 = 0 ;
unsigned int V_83 = 0 ;
if ( V_307 != - 1 ) {
V_181 |= 0xff ;
V_83 = V_307 ;
}
if ( V_308 != - 1 ) {
V_181 |= 0xff00 ;
V_83 |= V_308 << 8 ;
}
F_214 ( V_18 , V_30 , V_181 , V_83 ) ;
}
static int F_217 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
int V_180 = V_192 -> V_234 ;
struct V_137 * V_296 ;
T_2 V_30 ;
unsigned short V_83 ;
int V_207 ;
F_8 ( & V_18 -> V_134 ) ;
V_296 = F_51 ( & V_18 -> V_109 , V_180 ) ;
V_30 = V_296 -> V_30 ;
V_296 -> V_288 = V_205 -> V_198 . V_287 . V_288 [ 0 ] |
( ( unsigned int ) V_205 -> V_198 . V_287 . V_288 [ 1 ] << 8 ) |
( ( unsigned int ) V_205 -> V_198 . V_287 . V_288 [ 2 ] << 16 ) |
( ( unsigned int ) V_205 -> V_198 . V_287 . V_288 [ 3 ] << 24 ) ;
V_83 = F_212 ( V_296 -> V_288 ) ;
V_83 |= V_296 -> V_309 & 1 ;
V_207 = V_296 -> V_309 != V_83 ;
V_296 -> V_309 = V_83 ;
if ( V_207 && V_30 != ( T_5 ) - 1 )
F_216 ( V_18 , V_30 , V_83 & 0xff , ( V_83 >> 8 ) & 0xff ) ;
F_10 ( & V_18 -> V_134 ) ;
return V_207 ;
}
static int F_218 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
int V_180 = V_192 -> V_234 ;
struct V_137 * V_296 ;
F_8 ( & V_18 -> V_134 ) ;
V_296 = F_51 ( & V_18 -> V_109 , V_180 ) ;
V_205 -> V_198 . integer . V_198 [ 0 ] = V_296 -> V_309 & V_310 ;
F_10 ( & V_18 -> V_134 ) ;
return 0 ;
}
static inline void F_219 ( struct V_17 * V_18 , T_2 V_30 ,
int V_307 , int V_308 )
{
F_216 ( V_18 , V_30 , V_307 , V_308 ) ;
if ( ( F_41 ( V_18 , V_30 ) & V_311 ) &&
( V_307 & V_310 ) )
F_139 ( V_18 , V_30 , V_173 , 0 ,
V_275 , 0 ) ;
}
static int F_220 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
int V_180 = V_192 -> V_234 ;
struct V_137 * V_296 ;
T_2 V_30 ;
unsigned short V_83 ;
int V_207 ;
F_8 ( & V_18 -> V_134 ) ;
V_296 = F_51 ( & V_18 -> V_109 , V_180 ) ;
V_30 = V_296 -> V_30 ;
V_83 = V_296 -> V_309 & ~ V_310 ;
if ( V_205 -> V_198 . integer . V_198 [ 0 ] )
V_83 |= V_310 ;
V_207 = V_296 -> V_309 != V_83 ;
V_296 -> V_309 = V_83 ;
if ( V_207 && V_30 != ( T_5 ) - 1 )
F_219 ( V_18 , V_30 , V_83 & 0xff , - 1 ) ;
F_10 ( & V_18 -> V_134 ) ;
return V_207 ;
}
int F_221 ( struct V_17 * V_18 ,
T_2 V_312 ,
T_2 V_313 ,
int type )
{
int V_22 ;
struct V_191 * V_229 ;
struct V_314 * V_315 ;
int V_180 = 0 ;
int V_83 = 0 ;
const int V_316 = 16 ;
struct V_137 * V_296 ;
struct V_20 * V_21 = V_18 -> V_21 ;
if ( V_21 -> V_317 == V_318 &&
type == V_319 ) {
V_180 = V_316 ;
} else if ( V_21 -> V_317 == V_319 &&
type == V_318 ) {
for ( V_315 = V_320 ; V_315 -> V_100 ; V_315 ++ ) {
V_229 = F_161 ( V_18 , V_315 -> V_100 , 0 , 0 ) ;
if ( ! V_229 )
break;
V_229 -> V_201 . V_226 = V_316 ;
}
V_21 -> V_317 = V_318 ;
}
if ( ! V_21 -> V_317 )
V_21 -> V_317 = type ;
V_180 = F_164 ( V_18 , L_51 , V_180 ) ;
if ( V_180 < 0 ) {
F_38 ( V_18 , L_52 ) ;
return - V_228 ;
}
V_296 = F_49 ( & V_18 -> V_109 ) ;
if ( ! V_296 )
return - V_41 ;
for ( V_315 = V_320 ; V_315 -> V_100 ; V_315 ++ ) {
V_229 = F_196 ( V_315 , V_18 ) ;
if ( ! V_229 )
return - V_41 ;
V_229 -> V_201 . V_226 = V_180 ;
V_229 -> V_234 = V_18 -> V_109 . V_79 - 1 ;
V_22 = F_165 ( V_18 , V_312 , V_229 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_296 -> V_30 = V_313 ;
F_222 ( & V_18 -> V_19 , V_313 ,
V_321 , & V_83 ) ;
V_296 -> V_309 = V_83 ;
V_296 -> V_288 = F_213 ( V_296 -> V_309 ) ;
return 0 ;
}
struct V_137 * F_223 ( struct V_17 * V_18 ,
T_2 V_30 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_109 . V_79 ; V_5 ++ ) {
struct V_137 * V_296 =
F_51 ( & V_18 -> V_109 , V_5 ) ;
if ( V_296 -> V_30 == V_30 )
return V_296 ;
}
return NULL ;
}
void F_224 ( struct V_17 * V_18 , int V_180 )
{
struct V_137 * V_296 ;
F_8 ( & V_18 -> V_134 ) ;
V_296 = F_51 ( & V_18 -> V_109 , V_180 ) ;
V_296 -> V_30 = ( T_5 ) - 1 ;
F_10 ( & V_18 -> V_134 ) ;
}
void F_225 ( struct V_17 * V_18 , int V_180 , T_2 V_30 )
{
struct V_137 * V_296 ;
unsigned short V_83 ;
F_8 ( & V_18 -> V_134 ) ;
V_296 = F_51 ( & V_18 -> V_109 , V_180 ) ;
if ( V_296 -> V_30 != V_30 ) {
V_296 -> V_30 = V_30 ;
V_83 = V_296 -> V_309 ;
F_219 ( V_18 , V_30 , V_83 & 0xff , ( V_83 >> 8 ) & 0xff ) ;
}
F_10 ( & V_18 -> V_134 ) ;
}
static int F_226 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_322 * V_323 = F_146 ( V_192 ) ;
V_205 -> V_198 . integer . V_198 [ 0 ] = V_323 -> V_324 ;
return 0 ;
}
static int F_227 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_322 * V_323 = F_146 ( V_192 ) ;
V_323 -> V_324 = ! ! V_205 -> V_198 . integer . V_198 [ 0 ] ;
return 0 ;
}
int F_228 ( struct V_17 * V_18 ,
struct V_322 * V_323 )
{
struct V_191 * V_229 ;
if ( ! V_323 -> V_325 )
return 0 ;
V_229 = F_196 ( & V_326 , V_323 ) ;
if ( ! V_229 )
return - V_41 ;
return F_165 ( V_18 , V_323 -> V_325 , V_229 ) ;
}
static int F_229 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
V_205 -> V_198 . integer . V_198 [ 0 ] = V_18 -> V_327 ;
return 0 ;
}
static int F_230 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_2 V_30 = V_192 -> V_234 ;
unsigned int V_83 = ! ! V_205 -> V_198 . integer . V_198 [ 0 ] ;
int V_207 ;
F_8 ( & V_18 -> V_134 ) ;
V_207 = V_18 -> V_327 != V_83 ;
if ( V_207 ) {
V_18 -> V_327 = V_83 ;
F_231 ( & V_18 -> V_19 , V_30 ,
V_306 , V_83 ) ;
}
F_10 ( & V_18 -> V_134 ) ;
return V_207 ;
}
static int F_232 ( struct V_191 * V_192 ,
struct V_204 * V_205 )
{
struct V_17 * V_18 = F_146 ( V_192 ) ;
T_2 V_30 = V_192 -> V_234 ;
unsigned int V_83 ;
unsigned int V_297 ;
F_222 ( & V_18 -> V_19 , V_30 ,
V_321 , & V_83 ) ;
V_297 = F_213 ( V_83 ) ;
V_205 -> V_198 . V_287 . V_288 [ 0 ] = V_297 ;
V_205 -> V_198 . V_287 . V_288 [ 1 ] = V_297 >> 8 ;
V_205 -> V_198 . V_287 . V_288 [ 2 ] = V_297 >> 16 ;
V_205 -> V_198 . V_287 . V_288 [ 3 ] = V_297 >> 24 ;
return 0 ;
}
int F_233 ( struct V_17 * V_18 , T_2 V_30 )
{
int V_22 ;
struct V_191 * V_229 ;
struct V_314 * V_315 ;
int V_180 ;
V_180 = F_164 ( V_18 , L_53 , 0 ) ;
if ( V_180 < 0 ) {
F_38 ( V_18 , L_54 ) ;
return - V_228 ;
}
for ( V_315 = V_328 ; V_315 -> V_100 ; V_315 ++ ) {
V_229 = F_196 ( V_315 , V_18 ) ;
if ( ! V_229 )
return - V_41 ;
V_229 -> V_234 = V_30 ;
V_22 = F_165 ( V_18 , V_30 , V_229 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_18 -> V_327 =
F_15 ( V_18 , V_30 , 0 ,
V_321 , 0 ) &
V_310 ;
return 0 ;
}
void F_234 ( struct V_17 * V_18 , T_2 V_123 ,
unsigned int V_329 )
{
T_2 V_30 ;
F_48 (nid, codec) {
unsigned int V_56 = F_41 ( V_18 , V_30 ) ;
unsigned int V_330 = V_329 ;
if ( ! ( V_56 & V_331 ) )
continue;
if ( V_18 -> V_332 ) {
V_330 = V_18 -> V_332 ( V_18 , V_30 , V_329 ) ;
if ( V_330 != V_329 && V_329 == V_333 )
continue;
}
F_18 ( V_18 , V_30 , 0 , V_334 ,
V_330 ) ;
}
}
static unsigned int F_235 ( struct V_17 * V_18 ,
T_2 V_123 ,
unsigned int V_329 )
{
unsigned long V_335 = V_144 + F_236 ( 500 ) ;
unsigned int V_330 , V_336 ;
for (; ; ) {
V_330 = F_15 ( V_18 , V_123 , 0 ,
V_337 , 0 ) ;
if ( V_330 & V_338 )
break;
V_336 = ( V_330 >> 4 ) & 0x0f ;
if ( V_336 == V_329 )
break;
if ( F_237 ( V_144 , V_335 ) )
break;
F_123 ( 1 ) ;
}
return V_330 ;
}
unsigned int F_238 ( struct V_17 * V_18 ,
T_2 V_30 ,
unsigned int V_329 )
{
if ( V_30 == V_18 -> V_19 . V_146 || V_30 == V_18 -> V_19 . V_147 )
return V_329 ;
if ( V_329 == V_333 &&
F_40 ( F_41 ( V_18 , V_30 ) ) == V_54 &&
( F_239 ( V_18 , V_30 ) & V_339 ) ) {
int V_340 = F_15 ( V_18 , V_30 , 0 ,
V_341 , 0 ) ;
if ( V_340 & 0x02 )
return V_148 ;
}
return V_329 ;
}
static unsigned int F_114 ( struct V_17 * V_18 ,
unsigned int V_329 )
{
T_2 V_123 = V_18 -> V_19 . V_146 ? V_18 -> V_19 . V_146 : V_18 -> V_19 . V_147 ;
int V_197 ;
unsigned int V_330 ;
int V_15 = 0 ;
if ( V_329 == V_333 ) {
if ( V_18 -> V_140 < 0 )
F_123 ( F_240 ( V_18 ) ? 10 : 100 ) ;
else if ( V_18 -> V_140 > 0 )
F_123 ( V_18 -> V_140 ) ;
V_15 = V_25 ;
}
for ( V_197 = 0 ; V_197 < 10 ; V_197 ++ ) {
if ( V_18 -> V_106 . V_342 )
V_18 -> V_106 . V_342 ( V_18 , V_123 ,
V_329 ) ;
else {
V_330 = V_329 ;
if ( V_18 -> V_332 )
V_330 = V_18 -> V_332 ( V_18 , V_123 , V_330 ) ;
if ( V_330 == V_329 || V_329 != V_333 )
F_15 ( V_18 , V_123 , V_15 ,
V_334 ,
V_330 ) ;
F_234 ( V_18 , V_123 , V_329 ) ;
}
V_330 = F_235 ( V_18 , V_123 , V_329 ) ;
if ( ! ( V_330 & V_338 ) )
break;
}
return V_330 ;
}
static void F_241 ( struct V_17 * V_18 )
{
T_2 V_30 ;
if ( ! V_18 -> V_332 )
return;
F_48 (nid, codec) {
unsigned int V_56 = F_41 ( V_18 , V_30 ) ;
unsigned int V_84 ;
if ( ! ( V_56 & V_331 ) )
continue;
V_84 = V_18 -> V_332 ( V_18 , V_30 , V_148 ) ;
if ( V_84 == V_148 )
continue;
if ( ! F_242 ( V_18 , V_30 , V_84 ) )
F_18 ( V_18 , V_30 , 0 ,
V_334 , V_84 ) ;
}
}
static void F_243 ( struct V_17 * V_18 )
{
if ( V_18 -> V_343 . V_39 )
F_19 ( V_18 , V_18 -> V_343 . V_39 ) ;
}
static inline void F_243 ( struct V_17 * V_18 ) {}
static void F_244 ( struct V_17 * V_18 , bool V_344 )
{
unsigned long V_345 = V_144 - V_18 -> V_143 ;
if ( V_344 )
V_18 -> V_346 += V_345 ;
else
V_18 -> V_347 += V_345 ;
V_18 -> V_143 += V_345 ;
}
void F_245 ( struct V_17 * V_18 )
{
F_244 ( V_18 , F_246 ( V_18 ) ) ;
}
static unsigned int F_247 ( struct V_17 * V_18 )
{
unsigned int V_330 ;
F_248 ( & V_18 -> V_19 . V_348 ) ;
if ( V_18 -> V_106 . V_349 )
V_18 -> V_106 . V_349 ( V_18 ) ;
F_129 ( V_18 ) ;
V_330 = F_114 ( V_18 , V_333 ) ;
F_244 ( V_18 , true ) ;
F_249 ( & V_18 -> V_19 . V_348 ) ;
return V_330 ;
}
static void F_250 ( struct V_17 * V_18 )
{
F_248 ( & V_18 -> V_19 . V_348 ) ;
if ( V_18 -> V_19 . V_187 )
F_251 ( V_18 -> V_19 . V_187 ) ;
V_18 -> V_143 = V_144 ;
F_114 ( V_18 , V_148 ) ;
F_59 ( V_18 ) ;
F_243 ( V_18 ) ;
F_61 ( V_18 ) ;
if ( V_18 -> V_106 . V_350 )
V_18 -> V_106 . V_350 ( V_18 ) ;
else {
if ( V_18 -> V_106 . V_351 )
V_18 -> V_106 . V_351 ( V_18 ) ;
if ( V_18 -> V_19 . V_187 )
F_252 ( V_18 -> V_19 . V_187 ) ;
}
if ( V_18 -> V_91 )
F_60 ( & V_18 -> V_90 . V_89 ) ;
else
F_253 ( V_18 ) ;
F_249 ( & V_18 -> V_19 . V_348 ) ;
}
static int F_254 ( struct V_98 * V_13 )
{
struct V_17 * V_18 = F_102 ( V_13 ) ;
struct V_95 * V_96 ;
unsigned int V_330 ;
F_85 ( & V_18 -> V_90 ) ;
F_21 (pcm, &codec->pcm_list_head, list)
F_255 ( V_96 -> V_96 ) ;
V_330 = F_247 ( V_18 ) ;
if ( F_256 ( V_18 ) && F_240 ( V_18 ) &&
( V_330 & V_352 ) )
F_257 ( & V_18 -> V_19 ) ;
F_93 ( & V_18 -> V_19 , false ) ;
return 0 ;
}
static int F_258 ( struct V_98 * V_13 )
{
struct V_17 * V_18 = F_102 ( V_13 ) ;
F_93 ( & V_18 -> V_19 , true ) ;
F_259 ( & V_18 -> V_19 ) ;
F_250 ( V_18 ) ;
F_260 ( V_13 ) ;
return 0 ;
}
static int F_261 ( struct V_17 * V_18 )
{
struct V_95 * V_96 ;
int V_353 , V_22 ;
F_21 (pcm, &codec->pcm_list_head, list) {
for ( V_353 = 0 ; V_353 < 2 ; V_353 ++ ) {
struct V_354 * V_355 = & V_96 -> V_356 [ V_353 ] ;
struct V_357 * V_358 ;
const struct V_359 * V_360 ;
if ( ! V_96 || ! V_96 -> V_96 || V_96 -> V_361 ||
! V_355 -> V_362 )
continue;
V_360 = V_355 -> V_358 ? V_355 -> V_358 : V_363 ;
V_22 = F_262 ( V_96 -> V_96 , V_353 , V_360 ,
V_355 -> V_364 ,
0 , & V_358 ) ;
if ( V_22 < 0 )
return V_22 ;
V_358 -> V_365 = V_366 ;
}
}
return 0 ;
}
int F_263 ( struct V_17 * V_18 )
{
int V_22 = 0 ;
F_243 ( V_18 ) ;
if ( V_18 -> V_106 . V_351 )
V_22 = V_18 -> V_106 . V_351 ( V_18 ) ;
if ( ! V_22 && V_18 -> V_106 . V_367 )
V_22 = V_18 -> V_106 . V_367 ( V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_261 ( V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_18 -> V_91 )
F_60 ( & V_18 -> V_90 . V_89 ) ;
else
F_253 ( V_18 ) ;
F_241 ( V_18 ) ;
return 0 ;
}
static int F_264 ( struct V_354 * V_355 ,
struct V_17 * V_18 ,
struct V_368 * V_369 )
{
return 0 ;
}
static int F_265 ( struct V_354 * V_355 ,
struct V_17 * V_18 ,
unsigned int V_153 ,
unsigned int V_159 ,
struct V_368 * V_369 )
{
F_124 ( V_18 , V_355 -> V_30 , V_153 , 0 , V_159 ) ;
return 0 ;
}
static int F_266 ( struct V_354 * V_355 ,
struct V_17 * V_18 ,
struct V_368 * V_369 )
{
F_267 ( V_18 , V_355 -> V_30 ) ;
return 0 ;
}
static int F_268 ( struct V_17 * V_18 ,
struct V_354 * V_283 )
{
int V_22 ;
if ( V_283 -> V_30 && ( ! V_283 -> V_370 || ! V_283 -> V_371 ) ) {
V_22 = F_269 ( V_18 , V_283 -> V_30 ,
V_283 -> V_370 ? NULL : & V_283 -> V_370 ,
V_283 -> V_371 ? NULL : & V_283 -> V_371 ,
V_283 -> V_372 ? NULL : & V_283 -> V_372 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( V_283 -> V_282 . V_373 == NULL )
V_283 -> V_282 . V_373 = F_264 ;
if ( V_283 -> V_282 . V_374 == NULL )
V_283 -> V_282 . V_374 = F_264 ;
if ( V_283 -> V_282 . V_375 == NULL ) {
if ( F_36 ( ! V_283 -> V_30 ) )
return - V_48 ;
V_283 -> V_282 . V_375 = F_265 ;
}
if ( V_283 -> V_282 . V_376 == NULL ) {
if ( F_36 ( ! V_283 -> V_30 ) )
return - V_48 ;
V_283 -> V_282 . V_376 = F_266 ;
}
return 0 ;
}
int F_270 ( struct V_17 * V_18 ,
struct V_354 * V_355 ,
unsigned int V_356 ,
unsigned int V_159 ,
struct V_368 * V_369 )
{
int V_185 ;
F_8 ( & V_18 -> V_21 -> V_377 ) ;
if ( V_355 -> V_282 . V_375 )
V_185 = V_355 -> V_282 . V_375 ( V_355 , V_18 , V_356 , V_159 ,
V_369 ) ;
else
V_185 = - V_145 ;
if ( V_185 >= 0 )
F_128 ( V_18 ) ;
F_10 ( & V_18 -> V_21 -> V_377 ) ;
return V_185 ;
}
void F_271 ( struct V_17 * V_18 ,
struct V_354 * V_355 ,
struct V_368 * V_369 )
{
F_8 ( & V_18 -> V_21 -> V_377 ) ;
if ( V_355 -> V_282 . V_376 )
V_355 -> V_282 . V_376 ( V_355 , V_18 , V_369 ) ;
F_10 ( & V_18 -> V_21 -> V_377 ) ;
}
static int F_272 ( struct V_20 * V_21 , unsigned int type )
{
static int V_378 [ V_379 ] [ 5 ] = {
[ V_380 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_319 ] = { 1 , - 1 } ,
[ V_318 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_381 ] = { 6 , - 1 } ,
} ;
int V_5 ;
if ( type >= V_379 ) {
F_273 ( V_21 -> V_97 -> V_13 , L_55 , type ) ;
return - V_48 ;
}
for ( V_5 = 0 ; V_378 [ type ] [ V_5 ] >= 0 ; V_5 ++ ) {
#ifndef F_274
if ( V_378 [ type ] [ V_5 ] >= 8 )
break;
#endif
if ( ! F_275 ( V_378 [ type ] [ V_5 ] , V_21 -> V_99 ) )
return V_378 [ type ] [ V_5 ] ;
}
#ifdef F_274
for ( V_5 = 10 ; V_5 < 32 ; V_5 ++ ) {
if ( ! F_275 ( V_5 , V_21 -> V_99 ) )
return V_5 ;
}
#endif
F_276 ( V_21 -> V_97 -> V_13 , L_56 ,
V_382 [ type ] ) ;
#ifndef F_274
F_276 ( V_21 -> V_97 -> V_13 ,
L_57 ) ;
#endif
return - V_28 ;
}
int F_277 ( struct V_17 * V_18 )
{
struct V_95 * V_241 ;
int V_22 ;
if ( ! F_26 ( & V_18 -> V_102 ) )
return 0 ;
if ( ! V_18 -> V_106 . V_383 )
return 0 ;
V_22 = V_18 -> V_106 . V_383 ( V_18 ) ;
if ( V_22 < 0 ) {
F_38 ( V_18 , L_58 ,
V_18 -> V_19 . V_27 , V_22 ) ;
return V_22 ;
}
F_21 (cpcm, &codec->pcm_list_head, list) {
int V_356 ;
for ( V_356 = 0 ; V_356 < 2 ; V_356 ++ ) {
struct V_354 * V_283 = & V_241 -> V_356 [ V_356 ] ;
if ( ! V_283 -> V_362 )
continue;
V_22 = F_268 ( V_18 , V_283 ) ;
if ( V_22 < 0 ) {
F_151 ( V_18 ,
L_59 ,
V_241 -> V_100 ) ;
return V_22 ;
}
}
}
return 0 ;
}
int F_278 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_21 ;
struct V_95 * V_241 ;
int V_13 , V_22 ;
V_22 = F_277 ( V_18 ) ;
if ( V_22 < 0 ) {
F_174 ( V_18 ) ;
return V_22 ;
}
F_21 (cpcm, &codec->pcm_list_head, list) {
if ( V_241 -> V_96 )
continue;
if ( ! V_241 -> V_356 [ 0 ] . V_362 && ! V_241 -> V_356 [ 1 ] . V_362 )
continue;
V_13 = F_272 ( V_21 , V_241 -> V_384 ) ;
if ( V_13 < 0 )
continue;
V_241 -> V_98 = V_13 ;
V_22 = F_279 ( V_21 , V_18 , V_241 ) ;
if ( V_22 < 0 ) {
F_38 ( V_18 ,
L_60 ,
V_13 , V_18 -> V_19 . V_27 ) ;
continue;
}
}
return 0 ;
}
int F_280 ( struct V_17 * V_18 ,
const struct V_314 * V_385 )
{
int V_22 ;
for (; V_385 -> V_100 ; V_385 ++ ) {
struct V_191 * V_229 ;
int V_27 = 0 , V_180 = 0 ;
if ( V_385 -> V_224 == - 1 )
continue;
for (; ; ) {
V_229 = F_196 ( V_385 , V_18 ) ;
if ( ! V_229 )
return - V_41 ;
if ( V_27 > 0 )
V_229 -> V_201 . V_98 = V_27 ;
if ( V_180 > 0 )
V_229 -> V_201 . V_226 = V_180 ;
V_22 = F_165 ( V_18 , 0 , V_229 ) ;
if ( ! V_22 )
break;
if ( ! V_27 && V_18 -> V_19 . V_27 )
V_27 = V_18 -> V_19 . V_27 ;
else if ( ! V_180 && ! V_385 -> V_226 ) {
V_180 = F_164 ( V_18 ,
V_385 -> V_100 , 0 ) ;
if ( V_180 <= 0 )
return V_22 ;
} else
return V_22 ;
}
}
return 0 ;
}
static void F_281 ( struct V_17 * V_18 , int V_386 )
{
struct V_98 * V_13 = F_83 ( V_18 ) ;
if ( V_386 == 0 && V_18 -> V_387 )
V_386 = 3000 ;
if ( V_386 > 0 ) {
F_282 ( V_13 , V_386 ) ;
F_283 ( V_13 ) ;
F_284 ( V_13 ) ;
if ( ! F_285 ( V_13 ) )
F_260 ( V_13 ) ;
} else {
F_286 ( V_13 ) ;
F_287 ( V_13 ) ;
}
}
void F_288 ( struct V_20 * V_21 , int V_386 )
{
struct V_17 * V_163 ;
F_125 (c, bus)
F_281 ( V_163 , V_386 ) ;
}
int F_289 ( struct V_17 * V_18 ,
struct V_388 * V_389 ,
T_2 V_30 )
{
const struct V_390 * V_37 ;
int V_179 , V_391 ;
if ( ! V_389 -> V_392 )
return 0 ;
for ( V_37 = V_389 -> V_392 ; V_37 -> V_30 ; V_37 ++ ) {
if ( V_37 -> V_30 == V_30 )
break;
}
if ( ! V_37 -> V_30 )
return 0 ;
for ( V_37 = V_389 -> V_392 ; V_37 -> V_30 ; V_37 ++ ) {
for ( V_179 = 0 ; V_179 < 2 ; V_179 ++ ) {
V_391 = F_142 ( V_18 , V_37 -> V_30 , V_179 , V_37 -> V_176 ,
V_37 -> V_180 ) ;
if ( ! ( V_391 & V_275 ) && V_391 > 0 ) {
if ( ! V_389 -> V_393 ) {
V_389 -> V_393 = 1 ;
F_7 ( V_18 ) ;
}
return 1 ;
}
}
}
if ( V_389 -> V_393 ) {
V_389 -> V_393 = 0 ;
F_11 ( V_18 ) ;
}
return 0 ;
}
int F_290 ( const struct V_394 * V_395 ,
struct V_193 * V_194 )
{
unsigned int V_226 ;
V_194 -> type = V_396 ;
V_194 -> V_197 = 1 ;
V_194 -> V_198 . V_265 . V_236 = V_395 -> V_397 ;
if ( ! V_395 -> V_397 )
return 0 ;
V_226 = V_194 -> V_198 . V_265 . V_230 ;
if ( V_226 >= V_395 -> V_397 )
V_226 = V_395 -> V_397 - 1 ;
strcpy ( V_194 -> V_198 . V_265 . V_100 , V_395 -> V_236 [ V_226 ] . V_398 ) ;
return 0 ;
}
int F_291 ( struct V_17 * V_18 ,
const struct V_394 * V_395 ,
struct V_204 * V_205 ,
T_2 V_30 ,
unsigned int * V_399 )
{
unsigned int V_180 ;
if ( ! V_395 -> V_397 )
return 0 ;
V_180 = V_205 -> V_198 . V_265 . V_230 [ 0 ] ;
if ( V_180 >= V_395 -> V_397 )
V_180 = V_395 -> V_397 - 1 ;
if ( * V_399 == V_180 )
return 0 ;
F_292 ( V_18 , V_30 , 0 , V_400 ,
V_395 -> V_236 [ V_180 ] . V_226 ) ;
* V_399 = V_180 ;
return 1 ;
}
int F_293 ( struct V_191 * V_192 ,
struct V_193 * V_194 ,
int V_397 , const char * const * V_262 )
{
static const char * const V_401 [] = {
L_61 , L_62
} ;
if ( ! V_262 || ! V_397 ) {
V_397 = 2 ;
V_262 = V_401 ;
}
return F_189 ( V_194 , 1 , V_397 , V_262 ) ;
}
static void F_294 ( struct V_17 * V_18 , T_2 V_30 ,
unsigned int V_153 , unsigned int V_159 )
{
struct V_137 * V_296 ;
unsigned int V_402 ;
bool V_403 ;
V_296 = F_223 ( V_18 , V_30 ) ;
V_402 = F_15 ( V_18 , V_30 , 0 ,
V_161 , 0 ) ;
V_403 = V_18 -> V_113 &&
( V_296 -> V_309 & V_310 ) &&
V_402 != V_159 ;
if ( V_403 )
F_216 ( V_18 , V_30 ,
V_296 -> V_309 & ~ V_310 & 0xff ,
- 1 ) ;
F_124 ( V_18 , V_30 , V_153 , 0 , V_159 ) ;
if ( V_18 -> V_112 ) {
const T_2 * V_305 ;
for ( V_305 = V_18 -> V_112 ; * V_305 ; V_305 ++ )
F_124 ( V_18 , * V_305 , V_153 , 0 ,
V_159 ) ;
}
if ( V_403 )
F_216 ( V_18 , V_30 ,
V_296 -> V_309 & 0xff , - 1 ) ;
}
static void F_295 ( struct V_17 * V_18 , T_2 V_30 )
{
F_267 ( V_18 , V_30 ) ;
if ( V_18 -> V_112 ) {
const T_2 * V_305 ;
for ( V_305 = V_18 -> V_112 ; * V_305 ; V_305 ++ )
F_267 ( V_18 , * V_305 ) ;
}
}
int F_296 ( struct V_17 * V_18 ,
struct V_322 * V_323 )
{
F_8 ( & V_18 -> V_134 ) ;
if ( V_323 -> V_404 == V_405 )
F_295 ( V_18 , V_323 -> V_325 ) ;
V_323 -> V_404 = V_406 ;
F_10 ( & V_18 -> V_134 ) ;
return 0 ;
}
int F_297 ( struct V_17 * V_18 ,
struct V_322 * V_323 ,
unsigned int V_153 ,
unsigned int V_159 ,
struct V_368 * V_369 )
{
F_8 ( & V_18 -> V_134 ) ;
F_294 ( V_18 , V_323 -> V_325 , V_153 , V_159 ) ;
F_10 ( & V_18 -> V_134 ) ;
return 0 ;
}
int F_298 ( struct V_17 * V_18 ,
struct V_322 * V_323 )
{
F_8 ( & V_18 -> V_134 ) ;
F_295 ( V_18 , V_323 -> V_325 ) ;
F_10 ( & V_18 -> V_134 ) ;
return 0 ;
}
int F_299 ( struct V_17 * V_18 ,
struct V_322 * V_323 )
{
F_8 ( & V_18 -> V_134 ) ;
V_323 -> V_404 = 0 ;
F_10 ( & V_18 -> V_134 ) ;
return 0 ;
}
int F_300 ( struct V_17 * V_18 ,
struct V_322 * V_323 ,
struct V_368 * V_369 ,
struct V_354 * V_355 )
{
struct V_407 * V_408 = V_369 -> V_408 ;
V_408 -> V_409 . V_364 = V_323 -> V_410 ;
if ( V_323 -> V_325 ) {
if ( ! V_323 -> V_411 ) {
V_323 -> V_411 = V_355 -> V_370 ;
V_323 -> V_412 = V_355 -> V_371 ;
V_323 -> V_413 = V_355 -> V_372 ;
} else {
V_408 -> V_409 . V_370 = V_323 -> V_411 ;
V_408 -> V_409 . V_371 = V_323 -> V_412 ;
V_355 -> V_372 = V_323 -> V_413 ;
}
if ( ! V_323 -> V_414 ) {
F_269 ( V_18 , V_323 -> V_325 ,
& V_323 -> V_414 ,
& V_323 -> V_415 ,
& V_323 -> V_416 ) ;
}
F_8 ( & V_18 -> V_134 ) ;
if ( V_323 -> V_324 ) {
if ( ( V_408 -> V_409 . V_370 & V_323 -> V_414 ) &&
( V_408 -> V_409 . V_371 & V_323 -> V_415 ) ) {
V_408 -> V_409 . V_370 &= V_323 -> V_414 ;
V_408 -> V_409 . V_371 &= V_323 -> V_415 ;
if ( V_323 -> V_416 < V_355 -> V_372 )
V_355 -> V_372 = V_323 -> V_416 ;
} else {
V_323 -> V_324 = 0 ;
}
}
F_10 ( & V_18 -> V_134 ) ;
}
return F_301 ( V_369 -> V_408 , 0 ,
V_417 , 2 ) ;
}
int F_302 ( struct V_17 * V_18 ,
struct V_322 * V_323 ,
unsigned int V_153 ,
unsigned int V_159 ,
struct V_368 * V_369 )
{
const T_2 * V_115 = V_323 -> V_418 ;
int V_195 = V_369 -> V_408 -> V_419 ;
struct V_137 * V_296 ;
int V_5 ;
F_8 ( & V_18 -> V_134 ) ;
V_296 = F_223 ( V_18 , V_323 -> V_325 ) ;
if ( V_323 -> V_325 && V_323 -> V_324 &&
V_323 -> V_404 != V_406 ) {
if ( V_195 == 2 &&
F_303 ( V_18 , V_323 -> V_325 ,
V_159 ) &&
! ( V_296 -> V_288 & V_290 ) ) {
V_323 -> V_404 = V_405 ;
F_294 ( V_18 , V_323 -> V_325 ,
V_153 , V_159 ) ;
} else {
V_323 -> V_404 = 0 ;
F_295 ( V_18 , V_323 -> V_325 ) ;
}
}
F_10 ( & V_18 -> V_134 ) ;
F_124 ( V_18 , V_115 [ V_420 ] , V_153 ,
0 , V_159 ) ;
if ( ! V_323 -> V_421 &&
V_323 -> V_422 && V_323 -> V_422 != V_115 [ V_420 ] )
F_124 ( V_18 , V_323 -> V_422 , V_153 ,
0 , V_159 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_323 -> V_423 ) ; V_5 ++ )
if ( ! V_323 -> V_421 && V_323 -> V_423 [ V_5 ] )
F_124 ( V_18 ,
V_323 -> V_423 [ V_5 ] ,
V_153 , 0 , V_159 ) ;
for ( V_5 = 1 ; V_5 < V_323 -> V_424 ; V_5 ++ ) {
if ( V_195 >= ( V_5 + 1 ) * 2 )
F_124 ( V_18 , V_115 [ V_5 ] , V_153 ,
V_5 * 2 , V_159 ) ;
else if ( ! V_323 -> V_421 )
F_124 ( V_18 , V_115 [ V_5 ] , V_153 ,
0 , V_159 ) ;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_323 -> V_425 ) ; V_5 ++ ) {
int V_179 = 0 ;
if ( ! V_323 -> V_425 [ V_5 ] )
break;
if ( V_195 >= ( V_5 + 1 ) * 2 )
V_179 = V_5 * 2 ;
else if ( ! V_323 -> V_421 )
break;
F_124 ( V_18 , V_323 -> V_425 [ V_5 ] ,
V_153 , V_179 , V_159 ) ;
}
return 0 ;
}
int F_304 ( struct V_17 * V_18 ,
struct V_322 * V_323 )
{
const T_2 * V_115 = V_323 -> V_418 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_323 -> V_424 ; V_5 ++ )
F_267 ( V_18 , V_115 [ V_5 ] ) ;
if ( V_323 -> V_422 )
F_267 ( V_18 , V_323 -> V_422 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_323 -> V_423 ) ; V_5 ++ )
if ( V_323 -> V_423 [ V_5 ] )
F_267 ( V_18 ,
V_323 -> V_423 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_323 -> V_425 ) ; V_5 ++ )
if ( V_323 -> V_425 [ V_5 ] )
F_267 ( V_18 ,
V_323 -> V_425 [ V_5 ] ) ;
F_8 ( & V_18 -> V_134 ) ;
if ( V_323 -> V_325 && V_323 -> V_404 == V_405 ) {
F_295 ( V_18 , V_323 -> V_325 ) ;
V_323 -> V_404 = 0 ;
}
F_10 ( & V_18 -> V_134 ) ;
return 0 ;
}
unsigned int F_305 ( struct V_17 * V_18 , T_2 V_71 )
{
unsigned int V_426 ;
unsigned int V_155 ;
V_155 = F_15 ( V_18 , V_71 , 0 ,
V_76 , 0 ) ;
V_426 = F_239 ( V_18 , V_71 ) ;
V_426 = ( V_426 & V_427 ) >> V_428 ;
if ( ( V_426 & V_429 ) && V_155 != V_430 )
return V_431 ;
else if ( V_426 & V_432 )
return V_433 ;
else if ( V_426 & V_434 )
return V_435 ;
else if ( V_426 & V_436 )
return V_437 ;
return V_438 ;
}
unsigned int F_306 ( struct V_17 * V_18 ,
T_2 V_71 , unsigned int V_83 )
{
static unsigned int V_439 [] [ 2 ] = {
{ V_435 , V_434 } ,
{ V_431 , V_429 } ,
{ V_433 , V_432 } ,
{ V_437 , V_436 } ,
} ;
unsigned int V_440 ;
if ( ! V_83 )
return 0 ;
V_440 = F_239 ( V_18 , V_71 ) ;
if ( ! V_440 )
return V_83 ;
if ( V_83 & V_441 ) {
if ( ! ( V_440 & V_442 ) )
V_83 &= ~ ( V_441 | V_443 ) ;
else if ( ( V_83 & V_443 ) && ! ( V_440 & V_444 ) )
V_83 &= ~ V_443 ;
}
if ( V_83 & V_445 ) {
if ( ! ( V_440 & V_446 ) )
V_83 &= ~ ( V_445 | V_447 ) ;
else {
unsigned int V_448 , V_449 ;
int V_5 ;
V_448 = ( V_440 & V_427 ) >> V_428 ;
V_449 = V_83 & V_447 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_439 ) ; V_5 ++ ) {
if ( V_449 == V_439 [ V_5 ] [ 0 ] &&
! ( V_448 & V_439 [ V_5 ] [ 1 ] ) ) {
if ( V_5 == F_2 ( V_439 ) - 1 )
V_449 = V_438 ;
else
V_449 = V_439 [ V_5 + 1 ] [ 0 ] ;
}
}
V_83 &= ~ V_447 ;
V_83 |= V_449 ;
}
}
return V_83 ;
}
int F_307 ( struct V_17 * V_18 , T_2 V_71 ,
unsigned int V_83 , bool V_450 )
{
V_83 = F_306 ( V_18 , V_71 , V_83 ) ;
F_56 ( V_18 , V_71 , V_83 ) ;
if ( V_450 )
return F_308 ( V_18 , V_71 , 0 ,
V_86 , V_83 ) ;
else
return F_18 ( V_18 , V_71 , 0 ,
V_86 , V_83 ) ;
}
int F_309 ( struct V_17 * V_18 ,
struct V_394 * V_395 , const char * V_398 ,
int V_226 , int * V_451 )
{
int V_5 , V_452 = 0 ;
if ( V_395 -> V_397 >= V_453 ) {
F_38 ( V_18 , L_63 ) ;
return - V_48 ;
}
for ( V_5 = 0 ; V_5 < V_395 -> V_397 ; V_5 ++ ) {
if ( ! strncmp ( V_398 , V_395 -> V_236 [ V_5 ] . V_398 , strlen ( V_398 ) ) )
V_452 ++ ;
}
if ( V_451 )
* V_451 = V_452 ;
if ( V_452 > 0 )
snprintf ( V_395 -> V_236 [ V_395 -> V_397 ] . V_398 ,
sizeof( V_395 -> V_236 [ V_395 -> V_397 ] . V_398 ) ,
L_64 , V_398 , V_452 ) ;
else
F_310 ( V_395 -> V_236 [ V_395 -> V_397 ] . V_398 , V_398 ,
sizeof( V_395 -> V_236 [ V_395 -> V_397 ] . V_398 ) ) ;
V_395 -> V_236 [ V_395 -> V_397 ] . V_226 = V_226 ;
V_395 -> V_397 ++ ;
return 0 ;
}
void F_311 ( struct V_20 * V_21 )
{
struct V_17 * V_18 ;
F_125 (codec, bus) {
F_85 ( & V_18 -> V_90 ) ;
#ifdef F_111
if ( F_246 ( V_18 ) ) {
F_247 ( V_18 ) ;
F_250 ( V_18 ) ;
}
#endif
}
}
void F_312 ( int V_96 , char * V_454 , int V_455 )
{
static unsigned int V_177 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_5 , V_456 ;
for ( V_5 = 0 , V_456 = 0 ; V_5 < F_2 ( V_177 ) ; V_5 ++ )
if ( V_96 & ( V_457 << V_5 ) )
V_456 += snprintf ( V_454 + V_456 , V_455 - V_456 , L_65 , V_177 [ V_5 ] ) ;
V_454 [ V_456 ] = '\0' ;
}
