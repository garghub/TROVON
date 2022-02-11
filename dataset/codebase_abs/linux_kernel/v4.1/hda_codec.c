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
if ( ! F_12 ( V_18 ) && V_16 && V_22 < 0 && V_21 -> V_28 ) {
if ( V_21 -> V_29 ) {
F_13 ( V_18 ,
L_36 ) ;
V_21 -> V_30 . V_31 ( V_21 ) ;
}
goto V_23;
}
if ( ! V_22 || F_12 ( V_18 ) )
V_21 -> V_29 = 0 ;
return V_22 ;
}
unsigned int F_14 ( struct V_17 * V_18 , T_2 V_32 ,
int V_15 ,
unsigned int V_33 , unsigned int V_34 )
{
unsigned int V_14 = F_15 ( & V_18 -> V_19 , V_32 , V_33 , V_34 ) ;
unsigned int V_16 ;
if ( F_16 ( & V_18 -> V_19 , V_14 , V_15 , & V_16 ) )
return - 1 ;
return V_16 ;
}
int F_17 ( struct V_17 * V_18 , T_2 V_32 , int V_15 ,
unsigned int V_33 , unsigned int V_34 )
{
unsigned int V_14 = F_15 ( & V_18 -> V_19 , V_32 , V_33 , V_34 ) ;
return F_16 ( & V_18 -> V_19 , V_14 , V_15 , NULL ) ;
}
void F_18 ( struct V_17 * V_18 , const struct V_35 * V_36 )
{
for (; V_36 -> V_32 ; V_36 ++ )
F_17 ( V_18 , V_36 -> V_32 , 0 , V_36 -> V_33 , V_36 -> V_37 ) ;
}
static struct V_38 *
F_19 ( struct V_17 * V_18 , T_2 V_32 )
{
struct V_38 * V_39 ;
F_20 (p, &codec->conn_list, list) {
if ( V_39 -> V_32 == V_32 )
return V_39 ;
}
return NULL ;
}
static int F_21 ( struct V_17 * V_18 , T_2 V_32 , int V_40 ,
const T_2 * V_41 )
{
struct V_38 * V_39 ;
V_39 = F_22 ( sizeof( * V_39 ) + V_40 * sizeof( T_2 ) , V_42 ) ;
if ( ! V_39 )
return - V_43 ;
V_39 -> V_40 = V_40 ;
V_39 -> V_32 = V_32 ;
memcpy ( V_39 -> V_44 , V_41 , V_40 * sizeof( T_2 ) ) ;
F_23 ( & V_39 -> V_41 , & V_18 -> V_45 ) ;
return 0 ;
}
static void F_24 ( struct V_17 * V_18 )
{
while ( ! F_25 ( & V_18 -> V_45 ) ) {
struct V_38 * V_39 ;
V_39 = F_26 ( & V_18 -> V_45 , F_27 ( * V_39 ) , V_41 ) ;
F_28 ( & V_39 -> V_41 ) ;
F_29 ( V_39 ) ;
}
}
static int F_30 ( struct V_17 * V_18 , T_2 V_32 )
{
T_2 V_41 [ 32 ] ;
T_2 * V_46 = V_41 ;
int V_40 ;
V_40 = F_31 ( V_18 , V_32 , V_41 , F_2 ( V_41 ) ) ;
if ( V_40 == - V_47 ) {
V_40 = F_32 ( V_18 , V_32 ) ;
V_46 = F_22 ( sizeof( T_2 ) * V_40 , V_42 ) ;
if ( ! V_46 )
return - V_43 ;
V_40 = F_31 ( V_18 , V_32 , V_46 , V_40 ) ;
}
if ( V_40 >= 0 )
V_40 = F_33 ( V_18 , V_32 , V_40 , V_46 ) ;
if ( V_46 != V_41 )
F_29 ( V_46 ) ;
return V_40 ;
}
int F_34 ( struct V_17 * V_18 , T_2 V_32 ,
const T_2 * * V_48 )
{
bool V_49 = false ;
for (; ; ) {
int V_22 ;
const struct V_38 * V_39 ;
V_39 = F_19 ( V_18 , V_32 ) ;
if ( V_39 ) {
if ( V_48 )
* V_48 = V_39 -> V_44 ;
return V_39 -> V_40 ;
}
if ( F_35 ( V_49 ) )
return - V_50 ;
V_22 = F_30 ( V_18 , V_32 ) ;
if ( V_22 < 0 )
return V_22 ;
V_49 = true ;
}
}
int F_36 ( struct V_17 * V_18 , T_2 V_32 ,
T_2 * V_45 , int V_51 )
{
const T_2 * V_41 ;
int V_40 = F_34 ( V_18 , V_32 , & V_41 ) ;
if ( V_40 > 0 && V_45 ) {
if ( V_40 > V_51 ) {
F_37 ( V_18 , L_37 ,
V_40 , V_32 ) ;
return - V_50 ;
}
memcpy ( V_45 , V_41 , V_40 * sizeof( T_2 ) ) ;
}
return V_40 ;
}
int F_33 ( struct V_17 * V_18 , T_2 V_32 , int V_40 ,
const T_2 * V_41 )
{
struct V_38 * V_39 ;
V_39 = F_19 ( V_18 , V_32 ) ;
if ( V_39 ) {
F_28 ( & V_39 -> V_41 ) ;
F_29 ( V_39 ) ;
}
return F_21 ( V_18 , V_32 , V_40 , V_41 ) ;
}
int F_38 ( struct V_17 * V_18 , T_2 V_52 ,
T_2 V_32 , int V_53 )
{
const T_2 * V_54 ;
int V_5 , V_55 ;
V_55 = F_34 ( V_18 , V_52 , & V_54 ) ;
for ( V_5 = 0 ; V_5 < V_55 ; V_5 ++ )
if ( V_54 [ V_5 ] == V_32 )
return V_5 ;
if ( ! V_53 )
return - 1 ;
if ( V_53 > 10 ) {
F_13 ( V_18 , L_38 , V_32 ) ;
return - 1 ;
}
V_53 ++ ;
for ( V_5 = 0 ; V_5 < V_55 ; V_5 ++ ) {
unsigned int type = F_39 ( F_40 ( V_18 , V_54 [ V_5 ] ) ) ;
if ( type == V_56 || type == V_57 )
continue;
if ( F_38 ( V_18 , V_54 [ V_5 ] , V_32 , V_53 ) >= 0 )
return V_5 ;
}
return - 1 ;
}
static unsigned int F_41 ( struct V_17 * V_18 , T_2 V_32 )
{
unsigned int V_58 = F_40 ( V_18 , V_32 ) ;
unsigned int V_34 ;
if ( ! V_18 -> V_59 || ! ( V_58 & V_60 ) ||
F_39 ( V_58 ) != V_56 )
return 0 ;
V_34 = F_42 ( & V_18 -> V_19 , V_32 , V_61 ) ;
if ( V_34 == - 1 && V_18 -> V_21 -> V_28 )
V_34 = 0 ;
return V_34 & V_62 ;
}
int F_43 ( struct V_17 * V_18 , T_2 V_32 ,
T_3 * V_63 , int V_64 )
{
unsigned int V_34 ;
int V_5 , V_65 , V_66 ;
V_34 = F_41 ( V_18 , V_32 ) ;
if ( ! V_34 )
return 0 ;
V_65 = V_34 + 1 ;
V_65 = V_65 < V_64 ? V_65 : V_64 ;
V_66 = 0 ;
while ( V_66 < V_65 ) {
V_34 = F_14 ( V_18 , V_32 , 0 ,
V_67 , V_66 ) ;
if ( V_34 == - 1 && V_18 -> V_21 -> V_28 )
break;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_63 [ V_66 ] = ( T_3 ) V_34 ;
V_34 >>= 4 ;
V_66 ++ ;
if ( V_66 >= V_65 )
break;
}
}
return V_66 ;
}
static void F_44 ( struct V_20 * V_21 )
{
if ( ! V_21 )
return;
if ( V_21 -> V_30 . V_68 )
V_21 -> V_30 . V_68 ( V_21 ) ;
F_45 ( & V_21 -> V_19 ) ;
F_29 ( V_21 ) ;
}
static int F_46 ( struct V_69 * V_70 )
{
F_44 ( V_70 -> V_71 ) ;
return 0 ;
}
static int F_47 ( struct V_69 * V_70 )
{
struct V_20 * V_21 = V_70 -> V_71 ;
V_21 -> V_72 = 1 ;
return 0 ;
}
static int F_48 ( struct V_73 * V_74 , unsigned int V_14 )
{
struct V_20 * V_21 = F_6 ( V_74 , struct V_20 , V_19 ) ;
return V_21 -> V_30 . V_75 ( V_21 , V_14 ) ;
}
static int F_49 ( struct V_73 * V_74 , unsigned int V_27 ,
unsigned int * V_16 )
{
struct V_20 * V_21 = F_6 ( V_74 , struct V_20 , V_19 ) ;
* V_16 = V_21 -> V_30 . V_76 ( V_21 , V_27 ) ;
return V_21 -> V_28 ? - V_77 : 0 ;
}
int F_50 ( struct V_78 * V_79 ,
struct V_20 * * V_80 )
{
struct V_20 * V_21 ;
int V_22 ;
static struct V_81 V_82 = {
. V_83 = F_47 ,
. V_84 = F_46 ,
} ;
if ( V_80 )
* V_80 = NULL ;
V_21 = F_51 ( sizeof( * V_21 ) , V_42 ) ;
if ( ! V_21 )
return - V_43 ;
V_22 = F_52 ( & V_21 -> V_19 , V_79 -> V_13 , & V_85 ) ;
if ( V_22 < 0 ) {
F_29 ( V_21 ) ;
return V_22 ;
}
V_21 -> V_79 = V_79 ;
F_53 ( & V_21 -> V_86 ) ;
V_22 = F_54 ( V_79 , V_87 , V_21 , & V_82 ) ;
if ( V_22 < 0 ) {
F_44 ( V_21 ) ;
return V_22 ;
}
if ( V_80 )
* V_80 = V_21 ;
return 0 ;
}
static int F_55 ( struct V_17 * V_18 , T_2 V_88 )
{
int V_5 ;
T_2 V_32 ;
V_18 -> V_58 = F_22 ( V_18 -> V_19 . V_89 * 4 , V_42 ) ;
if ( ! V_18 -> V_58 )
return - V_43 ;
V_32 = V_18 -> V_19 . V_90 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_19 . V_89 ; V_5 ++ , V_32 ++ )
V_18 -> V_58 [ V_5 ] = F_42 ( & V_18 -> V_19 ,
V_32 , V_91 ) ;
return 0 ;
}
static int F_56 ( struct V_17 * V_18 )
{
T_2 V_32 ;
F_57 (nid, codec) {
struct V_92 * V_93 ;
unsigned int V_58 = F_40 ( V_18 , V_32 ) ;
unsigned int V_94 = F_39 ( V_58 ) ;
if ( V_94 != V_56 )
continue;
V_93 = F_58 ( & V_18 -> V_95 ) ;
if ( ! V_93 )
return - V_43 ;
V_93 -> V_32 = V_32 ;
V_93 -> V_1 = F_14 ( V_18 , V_32 , 0 ,
V_96 , 0 ) ;
V_93 -> V_97 = F_14 ( V_18 , V_32 , 0 ,
V_98 ,
0 ) ;
}
return 0 ;
}
static struct V_92 * F_59 ( struct V_17 * V_18 ,
struct V_99 * V_100 ,
T_2 V_32 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_100 -> V_101 ; V_5 ++ ) {
struct V_92 * V_93 = F_60 ( V_100 , V_5 ) ;
if ( V_93 -> V_32 == V_32 )
return V_93 ;
}
return NULL ;
}
int F_61 ( struct V_17 * V_18 , struct V_99 * V_41 ,
T_2 V_32 , unsigned int V_1 )
{
struct V_92 * V_93 ;
V_93 = F_59 ( V_18 , V_41 , V_32 ) ;
if ( ! V_93 ) {
V_93 = F_58 ( V_41 ) ;
if ( ! V_93 )
return - V_43 ;
V_93 -> V_32 = V_32 ;
}
V_93 -> V_1 = V_1 ;
return 0 ;
}
int F_62 ( struct V_17 * V_18 ,
T_2 V_32 , unsigned int V_1 )
{
return F_61 ( V_18 , & V_18 -> V_102 , V_32 , V_1 ) ;
}
unsigned int F_63 ( struct V_17 * V_18 , T_2 V_32 )
{
struct V_92 * V_93 ;
#ifdef F_64
{
unsigned int V_1 = 0 ;
F_8 ( & V_18 -> V_103 ) ;
V_93 = F_59 ( V_18 , & V_18 -> V_104 , V_32 ) ;
if ( V_93 )
V_1 = V_93 -> V_1 ;
F_10 ( & V_18 -> V_103 ) ;
if ( V_1 )
return V_1 ;
}
#endif
V_93 = F_59 ( V_18 , & V_18 -> V_102 , V_32 ) ;
if ( V_93 )
return V_93 -> V_1 ;
V_93 = F_59 ( V_18 , & V_18 -> V_95 , V_32 ) ;
if ( V_93 )
return V_93 -> V_1 ;
return 0 ;
}
int F_65 ( struct V_17 * V_18 , T_2 V_32 ,
unsigned int V_105 )
{
struct V_92 * V_93 ;
V_93 = F_59 ( V_18 , & V_18 -> V_95 , V_32 ) ;
if ( ! V_93 )
return - V_50 ;
V_93 -> V_106 = V_105 ;
return 0 ;
}
int F_66 ( struct V_17 * V_18 , T_2 V_32 )
{
struct V_92 * V_93 ;
V_93 = F_59 ( V_18 , & V_18 -> V_95 , V_32 ) ;
if ( ! V_93 )
return 0 ;
return V_93 -> V_106 ;
}
void F_67 ( struct V_17 * V_18 )
{
int V_5 ;
if ( V_18 -> V_21 -> V_72 )
return;
for ( V_5 = 0 ; V_5 < V_18 -> V_95 . V_101 ; V_5 ++ ) {
struct V_92 * V_93 = F_60 ( & V_18 -> V_95 , V_5 ) ;
F_14 ( V_18 , V_93 -> V_32 , 0 ,
V_107 , 0 ) ;
}
V_18 -> V_108 = 1 ;
}
static void F_68 ( struct V_17 * V_18 )
{
int V_5 ;
if ( ! V_18 -> V_108 )
return;
if ( V_18 -> V_21 -> V_72 )
return;
for ( V_5 = 0 ; V_5 < V_18 -> V_95 . V_101 ; V_5 ++ ) {
struct V_92 * V_93 = F_60 ( & V_18 -> V_95 , V_5 ) ;
F_17 ( V_18 , V_93 -> V_32 , 0 ,
V_107 ,
V_93 -> V_97 ) ;
}
V_18 -> V_108 = 0 ;
}
static void F_69 ( struct V_109 * V_110 )
{
struct V_17 * V_18 =
F_6 ( V_110 , struct V_17 , V_111 . V_110 ) ;
F_70 ( V_18 ) ;
F_71 ( V_18 ) ;
if ( ! V_18 -> V_112 )
return;
F_72 ( & V_18 -> V_111 ,
V_18 -> V_112 ) ;
}
static void F_73 ( struct V_17 * V_18 )
{
F_74 ( & V_18 -> V_102 ) ;
#ifdef F_64
F_74 ( & V_18 -> V_104 ) ;
#endif
F_74 ( & V_18 -> V_95 ) ;
}
static struct V_113 *
F_75 ( struct V_17 * V_18 , T_2 V_32 )
{
struct V_113 * V_39 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_114 . V_101 ; V_5 ++ ) {
V_39 = F_60 ( & V_18 -> V_114 , V_5 ) ;
if ( V_39 -> V_32 == V_32 )
return V_39 ;
}
V_39 = F_58 ( & V_18 -> V_114 ) ;
if ( V_39 )
V_39 -> V_32 = V_32 ;
return V_39 ;
}
static void F_76 ( struct V_115 * V_115 )
{
struct V_116 * V_117 = F_6 ( V_115 , struct V_116 , V_115 ) ;
if ( V_117 -> V_117 )
F_77 ( V_117 -> V_18 -> V_79 , V_117 -> V_117 ) ;
F_78 ( V_117 -> V_70 , V_117 -> V_18 -> V_21 -> V_118 ) ;
F_29 ( V_117 -> V_119 ) ;
F_29 ( V_117 ) ;
}
void F_79 ( struct V_116 * V_117 )
{
F_80 ( & V_117 -> V_115 , F_76 ) ;
}
struct V_116 * F_81 ( struct V_17 * V_18 ,
const char * V_120 , ... )
{
struct V_116 * V_117 ;
T_4 args ;
V_117 = F_51 ( sizeof( * V_117 ) , V_42 ) ;
if ( ! V_117 )
return NULL ;
V_117 -> V_18 = V_18 ;
F_82 ( & V_117 -> V_115 ) ;
va_start ( args , V_120 ) ;
V_117 -> V_119 = F_83 ( V_42 , V_120 , args ) ;
va_end ( args ) ;
if ( ! V_117 -> V_119 ) {
F_29 ( V_117 ) ;
return NULL ;
}
F_84 ( & V_117 -> V_41 , & V_18 -> V_121 ) ;
return V_117 ;
}
static void F_85 ( struct V_17 * V_18 )
{
struct V_116 * V_117 , * V_122 ;
F_86 (pcm, n, &codec->pcm_list_head, list) {
F_87 ( & V_117 -> V_41 ) ;
if ( V_117 -> V_117 )
F_88 ( V_18 -> V_79 , V_117 -> V_117 ) ;
F_79 ( V_117 ) ;
}
}
void F_89 ( struct V_17 * V_18 )
{
if ( V_18 -> V_123 ) {
F_90 ( F_91 ( V_18 ) ) ;
F_92 ( F_91 ( V_18 ) ) ;
V_18 -> V_123 = 0 ;
}
F_93 ( & V_18 -> V_111 ) ;
if ( ! V_18 -> V_124 )
F_94 ( V_18 ) ;
F_85 ( V_18 ) ;
F_95 ( V_18 ) ;
memset ( & V_18 -> V_125 , 0 , sizeof( V_18 -> V_125 ) ) ;
F_96 ( V_18 ) ;
V_18 -> V_126 = NULL ;
V_18 -> V_127 = NULL ;
F_74 ( & V_18 -> V_102 ) ;
F_74 ( & V_18 -> V_114 ) ;
F_74 ( & V_18 -> V_128 ) ;
F_74 ( & V_18 -> V_129 ) ;
V_18 -> V_130 = NULL ;
V_18 -> V_131 = NULL ;
V_18 -> V_132 = 0 ;
F_74 ( & V_18 -> V_133 ) ;
F_74 ( & V_18 -> V_134 ) ;
F_24 ( V_18 ) ;
F_97 ( & V_18 -> V_19 ) ;
}
void F_98 ( struct V_17 * V_18 )
{
if ( V_18 -> V_123 )
return;
if ( F_99 ( F_91 ( V_18 ) ) ) {
F_100 ( V_18 ) ;
F_101 ( F_91 ( V_18 ) ) ;
F_102 ( V_18 ) ;
V_18 -> V_123 = 1 ;
}
}
static int F_103 ( struct V_69 * V_70 )
{
F_98 ( V_70 -> V_71 ) ;
return 0 ;
}
static int F_104 ( struct V_69 * V_70 )
{
struct V_17 * V_18 = V_70 -> V_71 ;
F_95 ( V_18 ) ;
return 0 ;
}
static int F_105 ( struct V_69 * V_70 )
{
struct V_17 * V_18 = V_70 -> V_71 ;
V_18 -> V_124 = 1 ;
F_106 ( & V_18 -> V_19 ) ;
F_107 ( F_91 ( V_18 ) ) ;
return 0 ;
}
static void F_108 ( struct V_70 * V_13 )
{
struct V_17 * V_18 = F_109 ( V_13 ) ;
F_73 ( V_18 ) ;
F_110 ( & V_18 -> V_19 ) ;
F_111 ( V_18 ) ;
F_29 ( V_18 -> V_135 ) ;
F_29 ( V_18 -> V_58 ) ;
F_29 ( V_18 ) ;
}
int F_112 ( struct V_20 * V_21 , struct V_78 * V_79 ,
unsigned int V_136 , struct V_17 * * V_137 )
{
struct V_17 * V_18 ;
char V_138 [ 31 ] ;
T_2 V_139 ;
int V_22 ;
static struct V_81 V_82 = {
. V_140 = F_103 ,
. V_83 = F_104 ,
. V_84 = F_105 ,
} ;
if ( F_35 ( ! V_21 ) )
return - V_50 ;
if ( F_35 ( V_136 > V_141 ) )
return - V_50 ;
V_18 = F_51 ( sizeof( * V_18 ) , V_42 ) ;
if ( ! V_18 )
return - V_43 ;
sprintf ( V_138 , L_39 , V_79 -> V_142 , V_136 ) ;
V_22 = F_113 ( & V_18 -> V_19 , & V_21 -> V_19 , V_138 ,
V_136 ) ;
if ( V_22 < 0 ) {
F_29 ( V_18 ) ;
return V_22 ;
}
V_18 -> V_19 . V_13 . V_143 = F_108 ;
V_18 -> V_19 . type = V_144 ;
V_18 -> V_19 . V_145 = F_5 ;
V_18 -> V_21 = V_21 ;
V_18 -> V_79 = V_79 ;
V_18 -> V_27 = V_136 ;
F_53 ( & V_18 -> V_146 ) ;
F_53 ( & V_18 -> V_147 ) ;
F_114 ( & V_18 -> V_133 , sizeof( struct V_148 ) , 32 ) ;
F_114 ( & V_18 -> V_134 , sizeof( struct V_148 ) , 32 ) ;
F_114 ( & V_18 -> V_95 , sizeof( struct V_92 ) , 16 ) ;
F_114 ( & V_18 -> V_102 , sizeof( struct V_92 ) , 16 ) ;
F_114 ( & V_18 -> V_114 , sizeof( struct V_113 ) , 8 ) ;
F_114 ( & V_18 -> V_128 , sizeof( struct V_149 ) , 16 ) ;
F_114 ( & V_18 -> V_150 , sizeof( struct V_151 ) , 16 ) ;
F_114 ( & V_18 -> V_129 , sizeof( struct V_35 * ) , 8 ) ;
F_115 ( & V_18 -> V_45 ) ;
F_115 ( & V_18 -> V_121 ) ;
F_116 ( & V_18 -> V_111 , F_69 ) ;
V_18 -> V_152 = - 1 ;
V_18 -> V_153 = V_154 ;
#ifdef F_117
V_18 -> V_155 = V_156 ;
#endif
F_118 ( V_18 ) ;
if ( V_18 -> V_21 -> V_135 ) {
V_18 -> V_135 = F_119 ( V_18 -> V_21 -> V_135 , V_42 ) ;
if ( ! V_18 -> V_135 ) {
V_22 = - V_157 ;
goto error;
}
}
V_139 = V_18 -> V_19 . V_158 ? V_18 -> V_19 . V_158 : V_18 -> V_19 . V_159 ;
V_22 = F_55 ( V_18 , V_139 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_56 ( V_18 ) ;
if ( V_22 < 0 )
goto error;
F_120 ( V_18 , V_160 ) ;
F_121 ( V_18 ) ;
F_122 ( V_18 ) ;
sprintf ( V_138 , L_40 , V_18 -> V_19 . V_161 ,
V_18 -> V_19 . V_162 , V_18 -> V_19 . V_163 ) ;
F_123 ( V_79 , V_138 ) ;
V_22 = F_54 ( V_79 , V_164 , V_18 , & V_82 ) ;
if ( V_22 < 0 )
goto error;
if ( V_137 )
* V_137 = V_18 ;
return 0 ;
error:
F_107 ( F_91 ( V_18 ) ) ;
return V_22 ;
}
int F_124 ( struct V_17 * V_18 )
{
T_2 V_139 ;
int V_22 ;
V_22 = F_125 ( & V_18 -> V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
F_29 ( V_18 -> V_58 ) ;
V_139 = V_18 -> V_19 . V_158 ? V_18 -> V_19 . V_158 : V_18 -> V_19 . V_159 ;
V_22 = F_55 ( V_18 , V_139 ) ;
if ( V_22 < 0 )
return V_22 ;
F_74 ( & V_18 -> V_95 ) ;
V_22 = F_56 ( V_18 ) ;
return V_22 ;
}
static void F_126 ( struct V_17 * V_18 ,
struct V_113 * V_39 , T_2 V_32 ,
T_1 V_165 , int V_166 )
{
unsigned int V_167 , V_168 ;
if ( V_39 -> V_165 != V_165 || V_39 -> V_166 != V_166 ) {
V_167 = F_14 ( V_18 , V_32 , 0 , V_169 , 0 ) ;
V_168 = ( V_165 << 4 ) | V_166 ;
if ( V_167 != V_168 )
F_17 ( V_18 , V_32 , 0 ,
V_170 ,
V_168 ) ;
V_39 -> V_165 = V_165 ;
V_39 -> V_166 = V_166 ;
}
}
static void F_127 ( struct V_17 * V_18 , struct V_113 * V_39 ,
T_2 V_32 , int V_171 )
{
unsigned int V_167 ;
if ( V_39 -> V_172 != V_171 ) {
V_167 = F_14 ( V_18 , V_32 , 0 ,
V_173 , 0 ) ;
if ( V_167 != V_171 ) {
F_128 ( 1 ) ;
F_17 ( V_18 , V_32 , 0 ,
V_174 ,
V_171 ) ;
}
V_39 -> V_172 = V_171 ;
}
}
void F_129 ( struct V_17 * V_18 , T_2 V_32 ,
T_1 V_165 ,
int V_166 , int V_171 )
{
struct V_17 * V_175 ;
struct V_113 * V_39 ;
int type ;
int V_5 ;
if ( ! V_32 )
return;
F_13 ( V_18 ,
L_41 ,
V_32 , V_165 , V_166 , V_171 ) ;
V_39 = F_75 ( V_18 , V_32 ) ;
if ( ! V_39 )
return;
if ( V_18 -> V_125 . V_176 )
V_18 -> V_125 . V_176 ( V_18 , V_32 , true ) ;
if ( V_18 -> V_177 )
F_127 ( V_18 , V_39 , V_32 , V_171 ) ;
F_126 ( V_18 , V_39 , V_32 , V_165 , V_166 ) ;
if ( ! V_18 -> V_177 )
F_127 ( V_18 , V_39 , V_32 , V_171 ) ;
V_39 -> V_178 = 1 ;
V_39 -> V_179 = 0 ;
type = F_39 ( F_40 ( V_18 , V_32 ) ) ;
F_130 (c, codec->bus) {
for ( V_5 = 0 ; V_5 < V_175 -> V_114 . V_101 ; V_5 ++ ) {
V_39 = F_60 ( & V_175 -> V_114 , V_5 ) ;
if ( ! V_39 -> V_178 && V_39 -> V_165 == V_165 &&
F_39 ( F_40 ( V_175 , V_39 -> V_32 ) ) == type )
V_39 -> V_179 = 1 ;
}
}
}
void F_131 ( struct V_17 * V_18 , T_2 V_32 ,
int V_180 )
{
struct V_113 * V_39 ;
if ( ! V_32 )
return;
if ( V_18 -> V_181 )
V_180 = 1 ;
F_13 ( V_18 , L_42 , V_32 ) ;
V_39 = F_75 ( V_18 , V_32 ) ;
if ( V_39 ) {
if ( V_180 )
F_132 ( V_18 , V_39 ) ;
else
V_39 -> V_178 = 0 ;
}
}
static void F_132 ( struct V_17 * V_18 ,
struct V_113 * V_182 )
{
T_2 V_32 = V_182 -> V_32 ;
if ( V_182 -> V_165 || V_182 -> V_166 )
F_17 ( V_18 , V_32 , 0 , V_170 , 0 ) ;
if ( V_182 -> V_172 )
F_17 ( V_18 , V_32 , 0 , V_174 , 0
) ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> V_32 = V_32 ;
if ( V_18 -> V_125 . V_176 )
V_18 -> V_125 . V_176 ( V_18 , V_32 , false ) ;
}
static void F_133 ( struct V_17 * V_18 )
{
struct V_17 * V_175 ;
int V_5 ;
F_130 (c, codec->bus) {
for ( V_5 = 0 ; V_5 < V_175 -> V_114 . V_101 ; V_5 ++ ) {
struct V_113 * V_39 ;
V_39 = F_60 ( & V_175 -> V_114 , V_5 ) ;
if ( V_39 -> V_179 )
F_132 ( V_175 , V_39 ) ;
}
}
}
static void F_134 ( struct V_17 * V_18 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_114 . V_101 ; V_5 ++ ) {
struct V_113 * V_39 = F_60 ( & V_18 -> V_114 , V_5 ) ;
if ( V_39 -> V_165 )
F_132 ( V_18 , V_39 ) ;
}
}
T_1 F_135 ( struct V_17 * V_18 , T_2 V_32 , int V_183 )
{
if ( ! ( F_40 ( V_18 , V_32 ) & V_184 ) )
V_32 = V_18 -> V_19 . V_158 ;
return F_136 ( V_18 , V_32 ,
V_183 == V_185 ?
V_186 : V_187 ) ;
}
bool F_137 ( struct V_17 * V_18 , T_2 V_32 ,
int V_188 , unsigned int V_189 )
{
if ( ! V_32 )
return false ;
if ( F_40 ( V_18 , V_32 ) & ( 1 << ( V_188 + 1 ) ) )
if ( F_135 ( V_18 , V_32 , V_188 ) & V_189 )
return true ;
return false ;
}
int F_138 ( struct V_17 * V_18 , T_2 V_32 , int V_188 ,
unsigned int V_190 )
{
unsigned int V_34 ;
F_139 ( V_18 , V_32 ,
F_40 ( V_18 , V_32 ) | V_184 ) ;
V_34 = V_188 == V_185 ? V_186 : V_187 ;
return F_140 ( & V_18 -> V_19 , V_32 , V_34 , V_190 ) ;
}
int F_141 ( struct V_17 * V_18 , T_2 V_32 ,
int V_191 , int V_188 , int V_192 , int V_193 , int V_105 )
{
unsigned int V_14 = F_142 ( V_32 , V_191 , V_188 , V_192 ) ;
if ( ( F_135 ( V_18 , V_32 , V_188 ) &
( V_194 | V_195 ) ) == V_195 )
V_14 |= V_196 ;
return F_143 ( & V_18 -> V_19 , V_14 , V_193 , V_105 ) ;
}
int F_144 ( struct V_17 * V_18 , T_2 V_32 ,
int V_183 , int V_192 , int V_193 , int V_105 )
{
int V_191 , V_197 = 0 ;
if ( F_35 ( V_193 & ~ 0xff ) )
V_193 &= 0xff ;
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
V_197 |= F_141 ( V_18 , V_32 , V_191 , V_183 ,
V_192 , V_193 , V_105 ) ;
return V_197 ;
}
int F_145 ( struct V_17 * V_18 , T_2 V_32 , int V_191 ,
int V_188 , int V_192 , int V_193 , int V_105 )
{
int V_198 ;
if ( ! V_18 -> V_19 . V_199 )
return - V_50 ;
F_146 ( V_18 -> V_19 . V_199 , true ) ;
V_198 = F_147 ( V_18 , V_32 , V_191 , V_188 , V_192 ) ;
F_146 ( V_18 -> V_19 . V_199 , false ) ;
if ( V_198 >= 0 )
return 0 ;
return F_141 ( V_18 , V_32 , V_191 , V_188 , V_192 , V_193 , V_105 ) ;
}
int F_148 ( struct V_17 * V_18 , T_2 V_32 ,
int V_188 , int V_192 , int V_193 , int V_105 )
{
int V_191 , V_197 = 0 ;
if ( F_35 ( V_193 & ~ 0xff ) )
V_193 &= 0xff ;
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
V_197 |= F_145 ( V_18 , V_32 , V_191 , V_188 ,
V_192 , V_193 , V_105 ) ;
return V_197 ;
}
static T_1 F_149 ( struct V_17 * V_18 , T_2 V_32 , int V_188 ,
unsigned int V_200 )
{
T_1 V_190 = F_135 ( V_18 , V_32 , V_188 ) ;
V_190 = ( V_190 & V_201 ) >> V_202 ;
if ( V_200 < V_190 )
V_190 -= V_200 ;
return V_190 ;
}
int F_150 ( struct V_203 * V_204 ,
struct V_205 * V_206 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_5 V_32 = F_152 ( V_204 ) ;
T_3 V_207 = F_153 ( V_204 ) ;
int V_188 = F_154 ( V_204 ) ;
unsigned int V_200 = F_155 ( V_204 ) ;
V_206 -> type = V_208 ;
V_206 -> V_209 = V_207 == 3 ? 2 : 1 ;
V_206 -> V_210 . integer . V_211 = 0 ;
V_206 -> V_210 . integer . V_212 = F_149 ( V_18 , V_32 , V_188 , V_200 ) ;
if ( ! V_206 -> V_210 . integer . V_212 ) {
F_156 ( V_18 ,
L_43 ,
V_32 , V_204 -> V_213 . V_119 ) ;
return - V_50 ;
}
return 0 ;
}
static inline unsigned int
F_157 ( struct V_17 * V_18 , T_2 V_32 ,
int V_191 , int V_188 , int V_192 , unsigned int V_200 )
{
unsigned int V_105 ;
V_105 = F_147 ( V_18 , V_32 , V_191 , V_188 , V_192 ) ;
V_105 &= V_214 ;
if ( V_105 >= V_200 )
V_105 -= V_200 ;
else
V_105 = 0 ;
return V_105 ;
}
static inline int
F_158 ( struct V_17 * V_18 , T_2 V_32 ,
int V_191 , int V_188 , int V_192 , unsigned int V_200 ,
unsigned int V_105 )
{
unsigned int V_215 ;
if ( V_105 > 0 )
V_105 += V_200 ;
V_215 = F_149 ( V_18 , V_32 , V_188 , 0 ) ;
if ( V_105 > V_215 )
V_105 = V_215 ;
return F_141 ( V_18 , V_32 , V_191 , V_188 , V_192 ,
V_214 , V_105 ) ;
}
int F_159 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_2 V_32 = F_152 ( V_204 ) ;
int V_207 = F_153 ( V_204 ) ;
int V_188 = F_154 ( V_204 ) ;
int V_192 = F_160 ( V_204 ) ;
unsigned int V_200 = F_155 ( V_204 ) ;
long * V_218 = V_217 -> V_210 . integer . V_210 ;
if ( V_207 & 1 )
* V_218 ++ = F_157 ( V_18 , V_32 , 0 , V_188 , V_192 , V_200 ) ;
if ( V_207 & 2 )
* V_218 = F_157 ( V_18 , V_32 , 1 , V_188 , V_192 , V_200 ) ;
return 0 ;
}
int F_161 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_2 V_32 = F_152 ( V_204 ) ;
int V_207 = F_153 ( V_204 ) ;
int V_188 = F_154 ( V_204 ) ;
int V_192 = F_160 ( V_204 ) ;
unsigned int V_200 = F_155 ( V_204 ) ;
long * V_218 = V_217 -> V_210 . integer . V_210 ;
int V_219 = 0 ;
if ( V_207 & 1 ) {
V_219 = F_158 ( V_18 , V_32 , 0 , V_188 , V_192 , V_200 , * V_218 ) ;
V_218 ++ ;
}
if ( V_207 & 2 )
V_219 |= F_158 ( V_18 , V_32 , 1 , V_188 , V_192 , V_200 , * V_218 ) ;
return V_219 ;
}
int F_162 ( struct V_203 * V_204 , int V_220 ,
unsigned int V_221 , unsigned int T_6 * V_222 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_2 V_32 = F_152 ( V_204 ) ;
int V_188 = F_154 ( V_204 ) ;
unsigned int V_200 = F_155 ( V_204 ) ;
bool V_223 = F_163 ( V_204 ) ;
T_1 V_190 , V_224 , V_225 ;
if ( V_221 < 4 * sizeof( unsigned int ) )
return - V_43 ;
V_190 = F_135 ( V_18 , V_32 , V_188 ) ;
V_225 = ( V_190 & V_226 ) >> V_227 ;
V_225 = ( V_225 + 1 ) * 25 ;
V_224 = - ( ( V_190 & V_228 ) >> V_229 ) ;
V_224 += V_200 ;
V_224 = ( ( int ) V_224 ) * ( ( int ) V_225 ) ;
if ( V_223 || ( V_190 & V_195 ) )
V_225 |= V_230 ;
if ( F_164 ( V_231 , V_222 ) )
return - V_232 ;
if ( F_164 ( 2 * sizeof( unsigned int ) , V_222 + 1 ) )
return - V_232 ;
if ( F_164 ( V_224 , V_222 + 2 ) )
return - V_232 ;
if ( F_164 ( V_225 , V_222 + 3 ) )
return - V_232 ;
return 0 ;
}
void F_165 ( struct V_17 * V_18 , T_2 V_32 , int V_188 ,
unsigned int * V_233 )
{
T_1 V_190 ;
int V_55 , V_234 ;
V_190 = F_135 ( V_18 , V_32 , V_188 ) ;
V_55 = ( V_190 & V_201 ) >> V_202 ;
V_234 = ( V_190 & V_226 ) >> V_227 ;
V_234 = ( V_234 + 1 ) * 25 ;
V_233 [ 0 ] = V_231 ;
V_233 [ 1 ] = 2 * sizeof( unsigned int ) ;
V_233 [ 2 ] = - V_55 * V_234 ;
V_233 [ 3 ] = V_234 ;
}
static struct V_203 *
F_166 ( struct V_17 * V_18 , const char * V_119 , int V_13 , int V_192 )
{
struct V_235 V_213 ;
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
V_213 . V_236 = V_237 ;
V_213 . V_70 = V_13 ;
V_213 . V_238 = V_192 ;
if ( F_35 ( strlen ( V_119 ) >= sizeof( V_213 . V_119 ) ) )
return NULL ;
strcpy ( V_213 . V_119 , V_119 ) ;
return F_167 ( V_18 -> V_79 , & V_213 ) ;
}
struct V_203 * F_168 ( struct V_17 * V_18 ,
const char * V_119 )
{
return F_166 ( V_18 , V_119 , 0 , 0 ) ;
}
static int F_169 ( struct V_17 * V_18 , const char * V_119 ,
int V_239 )
{
int V_5 , V_192 ;
for ( V_5 = 0 , V_192 = V_239 ; V_5 < 16 ; V_5 ++ , V_192 ++ ) {
if ( ! F_166 ( V_18 , V_119 , 0 , V_192 ) )
return V_192 ;
}
return - V_240 ;
}
int F_170 ( struct V_17 * V_18 , T_2 V_32 ,
struct V_203 * V_241 )
{
int V_22 ;
unsigned short V_15 = 0 ;
struct V_148 * V_242 ;
if ( V_241 -> V_213 . V_243 & V_244 ) {
V_15 |= V_245 ;
if ( V_32 == 0 )
V_32 = F_171 ( V_241 -> V_246 ) ;
}
if ( ( V_241 -> V_213 . V_243 & V_247 ) != 0 && V_32 == 0 )
V_32 = V_241 -> V_213 . V_243 & 0xffff ;
if ( V_241 -> V_213 . V_243 & ( V_247 | V_244 ) )
V_241 -> V_213 . V_243 = 0 ;
V_22 = F_172 ( V_18 -> V_79 , V_241 ) ;
if ( V_22 < 0 )
return V_22 ;
V_242 = F_58 ( & V_18 -> V_133 ) ;
if ( ! V_242 )
return - V_43 ;
V_242 -> V_241 = V_241 ;
V_242 -> V_32 = V_32 ;
V_242 -> V_15 = V_15 ;
return 0 ;
}
int F_173 ( struct V_17 * V_18 , struct V_203 * V_241 ,
unsigned int V_238 , T_2 V_32 )
{
struct V_148 * V_242 ;
if ( V_32 > 0 ) {
V_242 = F_58 ( & V_18 -> V_134 ) ;
if ( ! V_242 )
return - V_43 ;
V_242 -> V_241 = V_241 ;
V_242 -> V_238 = V_238 ;
V_242 -> V_32 = V_32 ;
return 0 ;
}
F_37 ( V_18 , L_44 ,
V_241 -> V_213 . V_119 , V_241 -> V_213 . V_238 , V_238 ) ;
return - V_50 ;
}
void F_94 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_148 * V_248 = V_18 -> V_133 . V_41 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_133 . V_101 ; V_5 ++ )
F_174 ( V_18 -> V_79 , V_248 [ V_5 ] . V_241 ) ;
F_74 ( & V_18 -> V_133 ) ;
F_74 ( & V_18 -> V_134 ) ;
}
int F_175 ( struct V_20 * V_21 )
{
struct V_78 * V_79 = V_21 -> V_79 ;
struct V_17 * V_18 ;
F_176 ( & V_79 -> V_249 ) ;
if ( V_79 -> V_72 )
goto V_250;
V_79 -> V_72 = 1 ;
if ( ! F_25 ( & V_79 -> V_251 ) )
goto V_252;
F_130 (codec, bus) {
struct V_116 * V_253 ;
F_20 (cpcm, &codec->pcm_list_head, list) {
if ( ! V_253 -> V_117 )
continue;
if ( V_253 -> V_117 -> V_254 [ 0 ] . V_255 ||
V_253 -> V_117 -> V_254 [ 1 ] . V_255 )
goto V_252;
}
}
F_177 ( & V_79 -> V_249 ) ;
return 0 ;
V_252:
V_79 -> V_72 = 0 ;
V_250:
F_177 ( & V_79 -> V_249 ) ;
return - V_50 ;
}
void F_178 ( struct V_20 * V_21 )
{
struct V_78 * V_79 = V_21 -> V_79 ;
F_176 ( & V_79 -> V_249 ) ;
V_79 -> V_72 = 0 ;
F_177 ( & V_79 -> V_249 ) ;
}
int F_179 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_21 ;
if ( F_175 ( V_21 ) < 0 )
return - V_240 ;
F_106 ( & V_18 -> V_19 ) ;
F_178 ( V_21 ) ;
return 0 ;
}
static int F_180 ( struct V_17 * V_18 , const char * const * V_256 ,
const char * V_257 , T_7 V_258 , void * V_259 )
{
struct V_148 * V_248 ;
const char * const * V_260 ;
int V_5 , V_22 ;
V_248 = V_18 -> V_133 . V_41 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_133 . V_101 ; V_5 ++ ) {
struct V_203 * V_261 = V_248 [ V_5 ] . V_241 ;
if ( ! V_261 || V_261 -> V_213 . V_236 != V_237 )
continue;
for ( V_260 = V_256 ; * V_260 ; V_260 ++ ) {
char V_262 [ sizeof( V_261 -> V_213 . V_119 ) ] ;
const char * V_119 = * V_260 ;
if ( V_257 ) {
snprintf ( V_262 , sizeof( V_262 ) , L_45 ,
V_119 , V_257 ) ;
V_119 = V_262 ;
}
if ( ! strcmp ( V_261 -> V_213 . V_119 , V_119 ) ) {
V_22 = V_258 ( V_18 , V_259 , V_261 ) ;
if ( V_22 )
return V_22 ;
break;
}
}
}
return 0 ;
}
static int F_181 ( struct V_17 * V_18 ,
void * V_259 , struct V_203 * V_261 )
{
return 1 ;
}
static int F_182 ( struct V_17 * V_18 ,
struct V_203 * V_241 , int * V_263 )
{
int V_222 [ 4 ] ;
const int * V_233 = NULL ;
int V_105 = - 1 ;
if ( V_241 -> V_264 [ 0 ] . V_265 & V_266 ) {
T_8 V_267 = F_183 () ;
F_184 ( F_185 () ) ;
if ( ! V_241 -> V_233 . V_175 ( V_241 , 0 , sizeof( V_222 ) , V_222 ) )
V_233 = V_222 ;
F_184 ( V_267 ) ;
} else if ( V_241 -> V_264 [ 0 ] . V_265 & V_268 )
V_233 = V_241 -> V_233 . V_39 ;
if ( V_233 && V_233 [ 0 ] == V_231 ) {
int V_234 = V_233 [ 3 ] ;
V_234 &= ~ V_230 ;
if ( ! V_234 )
return - 1 ;
if ( * V_263 && * V_263 != V_234 ) {
F_37 ( V_18 , L_46 ,
- * V_263 , V_234 ) ;
return - 1 ;
}
* V_263 = V_234 ;
V_105 = - V_233 [ 2 ] / V_234 ;
}
return V_105 ;
}
static int F_186 ( struct V_203 * V_241 , int V_105 )
{
struct V_216 * V_217 ;
V_217 = F_51 ( sizeof( * V_217 ) , V_42 ) ;
if ( ! V_217 )
return - V_43 ;
V_217 -> V_210 . integer . V_210 [ 0 ] = V_105 ;
V_217 -> V_210 . integer . V_210 [ 1 ] = V_105 ;
V_241 -> V_269 ( V_241 , V_217 ) ;
F_29 ( V_217 ) ;
return 0 ;
}
static int F_187 ( struct V_17 * V_18 ,
void * V_259 , struct V_203 * V_270 )
{
int V_271 = F_182 ( V_18 , V_270 , V_259 ) ;
if ( V_271 > 0 )
F_186 ( V_270 , V_271 ) ;
return 0 ;
}
static int F_188 ( struct V_17 * V_18 ,
void * V_259 , struct V_203 * V_270 )
{
return F_186 ( V_270 , 1 ) ;
}
static int F_189 ( struct V_17 * V_18 ,
void * V_259 , struct V_203 * V_270 )
{
return F_190 ( V_259 , V_270 ) ;
}
int F_191 ( struct V_17 * V_18 , char * V_119 ,
unsigned int * V_233 , const char * const * V_256 ,
const char * V_257 , bool V_272 ,
struct V_203 * * V_273 )
{
struct V_203 * V_241 ;
int V_22 ;
if ( V_273 )
* V_273 = NULL ;
V_22 = F_180 ( V_18 , V_256 , V_257 , F_181 , NULL ) ;
if ( V_22 != 1 ) {
F_13 ( V_18 , L_47 , V_119 ) ;
return 0 ;
}
V_241 = F_192 ( V_119 , V_233 ) ;
if ( ! V_241 )
return - V_43 ;
V_22 = F_170 ( V_18 , 0 , V_241 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_180 ( V_18 , V_256 , V_257 , F_189 , V_241 ) ;
if ( V_22 < 0 )
return V_22 ;
F_186 ( V_241 , 0 ) ;
if ( V_272 ) {
int V_234 = 0 ;
F_180 ( V_18 , V_256 , V_257 ,
V_233 ? F_187 : F_188 , & V_234 ) ;
}
if ( V_273 )
* V_273 = V_241 ;
return 0 ;
}
static int F_193 ( struct V_203 * V_204 ,
struct V_205 * V_206 )
{
static const char * const V_274 [] = {
L_48 , L_49 , L_50
} ;
return F_194 ( V_206 , 1 , 3 , V_274 ) ;
}
static int F_195 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_275 * V_276 = F_151 ( V_204 ) ;
V_217 -> V_210 . V_277 . V_242 [ 0 ] = V_276 -> V_278 ;
return 0 ;
}
static int F_196 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_275 * V_276 = F_151 ( V_204 ) ;
unsigned int V_279 = V_276 -> V_278 ;
V_276 -> V_278 = V_217 -> V_210 . V_277 . V_242 [ 0 ] ;
if ( V_276 -> V_278 > V_280 )
V_276 -> V_278 = V_280 ;
if ( V_279 == V_276 -> V_278 )
return 0 ;
F_197 ( V_276 ) ;
return 1 ;
}
static void F_198 ( void * V_281 , int V_282 )
{
struct V_275 * V_276 = V_281 ;
if ( V_276 -> V_278 != V_280 )
V_282 = V_276 -> V_278 ;
V_276 -> V_276 ( V_276 -> V_18 , V_282 ) ;
}
int F_199 ( struct V_17 * V_18 ,
struct V_275 * V_276 ,
bool V_283 )
{
struct V_203 * V_241 ;
if ( ! V_276 -> V_276 || ! V_276 -> V_284 )
return 0 ;
V_276 -> V_18 = V_18 ;
V_276 -> V_278 = V_280 ;
F_200 ( V_276 -> V_284 , F_198 , V_276 ) ;
if ( ! V_283 )
return 0 ;
V_241 = F_201 ( & V_285 , V_276 ) ;
if ( ! V_241 )
return - V_43 ;
return F_170 ( V_18 , 0 , V_241 ) ;
}
void F_197 ( struct V_275 * V_276 )
{
if ( ! V_276 -> V_276 || ! V_276 -> V_18 )
return;
if ( V_276 -> V_18 -> V_21 -> V_72 )
return;
F_202 ( V_276 -> V_284 ) ;
}
int F_203 ( struct V_203 * V_204 ,
struct V_205 * V_206 )
{
int V_207 = F_153 ( V_204 ) ;
V_206 -> type = V_286 ;
V_206 -> V_209 = V_207 == 3 ? 2 : 1 ;
V_206 -> V_210 . integer . V_211 = 0 ;
V_206 -> V_210 . integer . V_212 = 1 ;
return 0 ;
}
int F_204 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_2 V_32 = F_152 ( V_204 ) ;
int V_207 = F_153 ( V_204 ) ;
int V_188 = F_154 ( V_204 ) ;
int V_192 = F_160 ( V_204 ) ;
long * V_218 = V_217 -> V_210 . integer . V_210 ;
if ( V_207 & 1 )
* V_218 ++ = ( F_147 ( V_18 , V_32 , 0 , V_188 , V_192 ) &
V_287 ) ? 0 : 1 ;
if ( V_207 & 2 )
* V_218 = ( F_147 ( V_18 , V_32 , 1 , V_188 , V_192 ) &
V_287 ) ? 0 : 1 ;
return 0 ;
}
int F_205 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_2 V_32 = F_152 ( V_204 ) ;
int V_207 = F_153 ( V_204 ) ;
int V_188 = F_154 ( V_204 ) ;
int V_192 = F_160 ( V_204 ) ;
long * V_218 = V_217 -> V_210 . integer . V_210 ;
int V_219 = 0 ;
if ( V_207 & 1 ) {
V_219 = F_141 ( V_18 , V_32 , 0 , V_188 , V_192 ,
V_287 ,
* V_218 ? 0 : V_287 ) ;
V_218 ++ ;
}
if ( V_207 & 2 )
V_219 |= F_141 ( V_18 , V_32 , 1 , V_188 , V_192 ,
V_287 ,
* V_218 ? 0 : V_287 ) ;
F_206 ( V_18 , V_32 ) ;
return V_219 ;
}
int F_207 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
unsigned long V_288 ;
int V_22 ;
F_8 ( & V_18 -> V_147 ) ;
V_288 = V_204 -> V_246 ;
V_204 -> V_246 = V_288 & ~ V_289 ;
V_22 = F_204 ( V_204 , V_217 ) ;
V_204 -> V_246 = V_288 ;
F_10 ( & V_18 -> V_147 ) ;
return V_22 ;
}
int F_208 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
unsigned long V_288 ;
int V_5 , V_290 , V_22 = 0 , V_219 = 0 ;
F_8 ( & V_18 -> V_147 ) ;
V_288 = V_204 -> V_246 ;
V_290 = ( V_288 & V_289 ) >> V_291 ;
for ( V_5 = 0 ; V_5 < V_290 ; V_5 ++ ) {
V_204 -> V_246 = ( V_288 & ~ V_289 ) |
( V_5 << V_291 ) ;
V_22 = F_205 ( V_204 , V_217 ) ;
if ( V_22 < 0 )
break;
V_219 |= V_22 ;
}
V_204 -> V_246 = V_288 ;
F_10 ( & V_18 -> V_147 ) ;
return V_22 < 0 ? V_22 : V_219 ;
}
int F_209 ( struct V_203 * V_204 ,
struct V_205 * V_206 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
struct V_292 * V_175 ;
int V_22 ;
F_8 ( & V_18 -> V_147 ) ;
V_175 = (struct V_292 * ) V_204 -> V_246 ;
V_204 -> V_246 = * V_175 -> V_293 ;
V_22 = V_175 -> V_30 -> V_294 ( V_204 , V_206 ) ;
V_204 -> V_246 = ( long ) V_175 ;
F_10 ( & V_18 -> V_147 ) ;
return V_22 ;
}
int F_210 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
struct V_292 * V_175 ;
int V_22 ;
F_8 ( & V_18 -> V_147 ) ;
V_175 = (struct V_292 * ) V_204 -> V_246 ;
V_204 -> V_246 = * V_175 -> V_293 ;
V_22 = V_175 -> V_30 -> V_295 ( V_204 , V_217 ) ;
V_204 -> V_246 = ( long ) V_175 ;
F_10 ( & V_18 -> V_147 ) ;
return V_22 ;
}
int F_211 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
struct V_292 * V_175 ;
unsigned long * V_296 ;
int V_22 = 0 , V_219 = 0 ;
F_8 ( & V_18 -> V_147 ) ;
V_175 = (struct V_292 * ) V_204 -> V_246 ;
for ( V_296 = V_175 -> V_293 ; * V_296 ; V_296 ++ ) {
V_204 -> V_246 = * V_296 ;
V_22 = V_175 -> V_30 -> V_269 ( V_204 , V_217 ) ;
if ( V_22 < 0 )
break;
V_219 |= V_22 ;
}
V_204 -> V_246 = ( long ) V_175 ;
F_10 ( & V_18 -> V_147 ) ;
return V_22 < 0 ? V_22 : V_219 ;
}
int F_212 ( struct V_203 * V_204 , int V_220 ,
unsigned int V_221 , unsigned int T_6 * V_233 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
struct V_292 * V_175 ;
int V_22 ;
F_8 ( & V_18 -> V_147 ) ;
V_175 = (struct V_292 * ) V_204 -> V_246 ;
V_204 -> V_246 = * V_175 -> V_293 ;
V_22 = V_175 -> V_30 -> V_233 ( V_204 , V_220 , V_221 , V_233 ) ;
V_204 -> V_246 = ( long ) V_175 ;
F_10 ( & V_18 -> V_147 ) ;
return V_22 ;
}
static int F_213 ( struct V_203 * V_204 ,
struct V_205 * V_206 )
{
V_206 -> type = V_297 ;
V_206 -> V_209 = 1 ;
return 0 ;
}
static int F_214 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
V_217 -> V_210 . V_298 . V_299 [ 0 ] = V_300 |
V_301 |
V_302 |
V_303 ;
V_217 -> V_210 . V_298 . V_299 [ 1 ] = V_304 |
V_305 ;
return 0 ;
}
static int F_215 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
V_217 -> V_210 . V_298 . V_299 [ 0 ] = V_300 |
V_301 |
V_306 ;
return 0 ;
}
static int F_216 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
int V_192 = V_204 -> V_246 ;
struct V_149 * V_307 ;
F_8 ( & V_18 -> V_146 ) ;
V_307 = F_60 ( & V_18 -> V_128 , V_192 ) ;
V_217 -> V_210 . V_298 . V_299 [ 0 ] = V_307 -> V_299 & 0xff ;
V_217 -> V_210 . V_298 . V_299 [ 1 ] = ( V_307 -> V_299 >> 8 ) & 0xff ;
V_217 -> V_210 . V_298 . V_299 [ 2 ] = ( V_307 -> V_299 >> 16 ) & 0xff ;
V_217 -> V_210 . V_298 . V_299 [ 3 ] = ( V_307 -> V_299 >> 24 ) & 0xff ;
F_10 ( & V_18 -> V_146 ) ;
return 0 ;
}
static unsigned short F_217 ( unsigned int V_308 )
{
unsigned short V_105 = 0 ;
if ( V_308 & V_300 )
V_105 |= V_309 ;
if ( V_308 & V_301 )
V_105 |= V_310 ;
if ( V_308 & V_300 ) {
if ( ( V_308 & V_311 ) ==
V_306 )
V_105 |= V_312 ;
} else {
if ( ( V_308 & V_313 ) ==
V_302 )
V_105 |= V_312 ;
if ( ! ( V_308 & V_303 ) )
V_105 |= V_314 ;
if ( V_308 & ( V_305 << 8 ) )
V_105 |= V_315 ;
V_105 |= V_308 & ( V_304 << 8 ) ;
}
return V_105 ;
}
static unsigned int F_218 ( unsigned short V_105 )
{
unsigned int V_308 = 0 ;
if ( V_105 & V_310 )
V_308 |= V_301 ;
if ( V_105 & V_309 )
V_308 |= V_300 ;
if ( V_308 & V_300 ) {
if ( V_105 & V_312 )
V_308 |= V_306 ;
} else {
if ( V_105 & V_312 )
V_308 |= V_302 ;
if ( ! ( V_105 & V_314 ) )
V_308 |= V_303 ;
if ( V_105 & V_315 )
V_308 |= ( V_305 << 8 ) ;
V_308 |= V_105 & ( 0x7f << 8 ) ;
}
return V_308 ;
}
static void F_219 ( struct V_17 * V_18 , T_2 V_32 ,
int V_193 , int V_105 )
{
const T_2 * V_316 ;
F_220 ( & V_18 -> V_19 , V_32 , V_317 ,
V_193 , V_105 ) ;
V_316 = V_18 -> V_131 ;
if ( ! V_316 )
return;
for (; * V_316 ; V_316 ++ )
F_220 ( & V_18 -> V_19 , * V_316 ,
V_317 , V_193 , V_105 ) ;
}
static inline void F_221 ( struct V_17 * V_18 , T_2 V_32 ,
int V_318 , int V_319 )
{
unsigned int V_193 = 0 ;
unsigned int V_105 = 0 ;
if ( V_318 != - 1 ) {
V_193 |= 0xff ;
V_105 = V_318 ;
}
if ( V_319 != - 1 ) {
V_193 |= 0xff00 ;
V_105 |= V_319 << 8 ;
}
F_219 ( V_18 , V_32 , V_193 , V_105 ) ;
}
static int F_222 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
int V_192 = V_204 -> V_246 ;
struct V_149 * V_307 ;
T_2 V_32 ;
unsigned short V_105 ;
int V_219 ;
F_8 ( & V_18 -> V_146 ) ;
V_307 = F_60 ( & V_18 -> V_128 , V_192 ) ;
V_32 = V_307 -> V_32 ;
V_307 -> V_299 = V_217 -> V_210 . V_298 . V_299 [ 0 ] |
( ( unsigned int ) V_217 -> V_210 . V_298 . V_299 [ 1 ] << 8 ) |
( ( unsigned int ) V_217 -> V_210 . V_298 . V_299 [ 2 ] << 16 ) |
( ( unsigned int ) V_217 -> V_210 . V_298 . V_299 [ 3 ] << 24 ) ;
V_105 = F_217 ( V_307 -> V_299 ) ;
V_105 |= V_307 -> V_320 & 1 ;
V_219 = V_307 -> V_320 != V_105 ;
V_307 -> V_320 = V_105 ;
if ( V_219 && V_32 != ( T_5 ) - 1 )
F_221 ( V_18 , V_32 , V_105 & 0xff , ( V_105 >> 8 ) & 0xff ) ;
F_10 ( & V_18 -> V_146 ) ;
return V_219 ;
}
static int F_223 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
int V_192 = V_204 -> V_246 ;
struct V_149 * V_307 ;
F_8 ( & V_18 -> V_146 ) ;
V_307 = F_60 ( & V_18 -> V_128 , V_192 ) ;
V_217 -> V_210 . integer . V_210 [ 0 ] = V_307 -> V_320 & V_321 ;
F_10 ( & V_18 -> V_146 ) ;
return 0 ;
}
static inline void F_224 ( struct V_17 * V_18 , T_2 V_32 ,
int V_318 , int V_319 )
{
F_221 ( V_18 , V_32 , V_318 , V_319 ) ;
if ( ( F_40 ( V_18 , V_32 ) & V_322 ) &&
( V_318 & V_321 ) )
F_144 ( V_18 , V_32 , V_185 , 0 ,
V_287 , 0 ) ;
}
static int F_225 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
int V_192 = V_204 -> V_246 ;
struct V_149 * V_307 ;
T_2 V_32 ;
unsigned short V_105 ;
int V_219 ;
F_8 ( & V_18 -> V_146 ) ;
V_307 = F_60 ( & V_18 -> V_128 , V_192 ) ;
V_32 = V_307 -> V_32 ;
V_105 = V_307 -> V_320 & ~ V_321 ;
if ( V_217 -> V_210 . integer . V_210 [ 0 ] )
V_105 |= V_321 ;
V_219 = V_307 -> V_320 != V_105 ;
V_307 -> V_320 = V_105 ;
if ( V_219 && V_32 != ( T_5 ) - 1 )
F_224 ( V_18 , V_32 , V_105 & 0xff , - 1 ) ;
F_10 ( & V_18 -> V_146 ) ;
return V_219 ;
}
int F_226 ( struct V_17 * V_18 ,
T_2 V_323 ,
T_2 V_324 ,
int type )
{
int V_22 ;
struct V_203 * V_241 ;
struct V_325 * V_326 ;
int V_192 = 0 ;
int V_105 = 0 ;
const int V_327 = 16 ;
struct V_149 * V_307 ;
struct V_20 * V_21 = V_18 -> V_21 ;
if ( V_21 -> V_328 == V_329 &&
type == V_330 ) {
V_192 = V_327 ;
} else if ( V_21 -> V_328 == V_330 &&
type == V_329 ) {
for ( V_326 = V_331 ; V_326 -> V_119 ; V_326 ++ ) {
V_241 = F_166 ( V_18 , V_326 -> V_119 , 0 , 0 ) ;
if ( ! V_241 )
break;
V_241 -> V_213 . V_238 = V_327 ;
}
V_21 -> V_328 = V_329 ;
}
if ( ! V_21 -> V_328 )
V_21 -> V_328 = type ;
V_192 = F_169 ( V_18 , L_51 , V_192 ) ;
if ( V_192 < 0 ) {
F_37 ( V_18 , L_52 ) ;
return - V_240 ;
}
V_307 = F_58 ( & V_18 -> V_128 ) ;
if ( ! V_307 )
return - V_43 ;
for ( V_326 = V_331 ; V_326 -> V_119 ; V_326 ++ ) {
V_241 = F_201 ( V_326 , V_18 ) ;
if ( ! V_241 )
return - V_43 ;
V_241 -> V_213 . V_238 = V_192 ;
V_241 -> V_246 = V_18 -> V_128 . V_101 - 1 ;
V_22 = F_170 ( V_18 , V_323 , V_241 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_307 -> V_32 = V_324 ;
F_227 ( & V_18 -> V_19 , V_324 ,
V_332 , & V_105 ) ;
V_307 -> V_320 = V_105 ;
V_307 -> V_299 = F_218 ( V_307 -> V_320 ) ;
return 0 ;
}
struct V_149 * F_228 ( struct V_17 * V_18 ,
T_2 V_32 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_128 . V_101 ; V_5 ++ ) {
struct V_149 * V_307 =
F_60 ( & V_18 -> V_128 , V_5 ) ;
if ( V_307 -> V_32 == V_32 )
return V_307 ;
}
return NULL ;
}
void F_229 ( struct V_17 * V_18 , int V_192 )
{
struct V_149 * V_307 ;
F_8 ( & V_18 -> V_146 ) ;
V_307 = F_60 ( & V_18 -> V_128 , V_192 ) ;
V_307 -> V_32 = ( T_5 ) - 1 ;
F_10 ( & V_18 -> V_146 ) ;
}
void F_230 ( struct V_17 * V_18 , int V_192 , T_2 V_32 )
{
struct V_149 * V_307 ;
unsigned short V_105 ;
F_8 ( & V_18 -> V_146 ) ;
V_307 = F_60 ( & V_18 -> V_128 , V_192 ) ;
if ( V_307 -> V_32 != V_32 ) {
V_307 -> V_32 = V_32 ;
V_105 = V_307 -> V_320 ;
F_224 ( V_18 , V_32 , V_105 & 0xff , ( V_105 >> 8 ) & 0xff ) ;
}
F_10 ( & V_18 -> V_146 ) ;
}
static int F_231 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_333 * V_334 = F_151 ( V_204 ) ;
V_217 -> V_210 . integer . V_210 [ 0 ] = V_334 -> V_335 ;
return 0 ;
}
static int F_232 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_333 * V_334 = F_151 ( V_204 ) ;
V_334 -> V_335 = ! ! V_217 -> V_210 . integer . V_210 [ 0 ] ;
return 0 ;
}
int F_233 ( struct V_17 * V_18 ,
struct V_333 * V_334 )
{
struct V_203 * V_241 ;
if ( ! V_334 -> V_336 )
return 0 ;
V_241 = F_201 ( & V_337 , V_334 ) ;
if ( ! V_241 )
return - V_43 ;
return F_170 ( V_18 , V_334 -> V_336 , V_241 ) ;
}
static int F_234 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
V_217 -> V_210 . integer . V_210 [ 0 ] = V_18 -> V_338 ;
return 0 ;
}
static int F_235 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_2 V_32 = V_204 -> V_246 ;
unsigned int V_105 = ! ! V_217 -> V_210 . integer . V_210 [ 0 ] ;
int V_219 ;
F_8 ( & V_18 -> V_146 ) ;
V_219 = V_18 -> V_338 != V_105 ;
if ( V_219 ) {
V_18 -> V_338 = V_105 ;
F_236 ( & V_18 -> V_19 , V_32 ,
V_317 , V_105 ) ;
}
F_10 ( & V_18 -> V_146 ) ;
return V_219 ;
}
static int F_237 ( struct V_203 * V_204 ,
struct V_216 * V_217 )
{
struct V_17 * V_18 = F_151 ( V_204 ) ;
T_2 V_32 = V_204 -> V_246 ;
unsigned int V_105 ;
unsigned int V_308 ;
F_227 ( & V_18 -> V_19 , V_32 ,
V_332 , & V_105 ) ;
V_308 = F_218 ( V_105 ) ;
V_217 -> V_210 . V_298 . V_299 [ 0 ] = V_308 ;
V_217 -> V_210 . V_298 . V_299 [ 1 ] = V_308 >> 8 ;
V_217 -> V_210 . V_298 . V_299 [ 2 ] = V_308 >> 16 ;
V_217 -> V_210 . V_298 . V_299 [ 3 ] = V_308 >> 24 ;
return 0 ;
}
int F_238 ( struct V_17 * V_18 , T_2 V_32 )
{
int V_22 ;
struct V_203 * V_241 ;
struct V_325 * V_326 ;
int V_192 ;
V_192 = F_169 ( V_18 , L_53 , 0 ) ;
if ( V_192 < 0 ) {
F_37 ( V_18 , L_54 ) ;
return - V_240 ;
}
for ( V_326 = V_339 ; V_326 -> V_119 ; V_326 ++ ) {
V_241 = F_201 ( V_326 , V_18 ) ;
if ( ! V_241 )
return - V_43 ;
V_241 -> V_246 = V_32 ;
V_22 = F_170 ( V_18 , V_32 , V_241 ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_18 -> V_338 =
F_14 ( V_18 , V_32 , 0 ,
V_332 , 0 ) &
V_321 ;
return 0 ;
}
void F_239 ( struct V_17 * V_18 , T_2 V_139 ,
unsigned int V_340 )
{
T_2 V_32 ;
F_57 (nid, codec) {
unsigned int V_58 = F_40 ( V_18 , V_32 ) ;
unsigned int V_341 = V_340 ;
if ( ! ( V_58 & V_342 ) )
continue;
if ( V_18 -> V_343 ) {
V_341 = V_18 -> V_343 ( V_18 , V_32 , V_340 ) ;
if ( V_341 != V_340 && V_340 == V_344 )
continue;
}
F_17 ( V_18 , V_32 , 0 , V_345 ,
V_341 ) ;
}
}
static unsigned int F_240 ( struct V_17 * V_18 ,
T_2 V_139 ,
unsigned int V_340 )
{
unsigned long V_346 = V_156 + F_241 ( 500 ) ;
unsigned int V_341 , V_347 ;
for (; ; ) {
V_341 = F_14 ( V_18 , V_139 , 0 ,
V_348 , 0 ) ;
if ( V_341 & V_349 )
break;
V_347 = ( V_341 >> 4 ) & 0x0f ;
if ( V_347 == V_340 )
break;
if ( F_242 ( V_156 , V_346 ) )
break;
F_128 ( 1 ) ;
}
return V_341 ;
}
unsigned int F_243 ( struct V_17 * V_18 ,
T_2 V_32 ,
unsigned int V_340 )
{
if ( V_32 == V_18 -> V_19 . V_158 || V_32 == V_18 -> V_19 . V_159 )
return V_340 ;
if ( V_340 == V_344 &&
F_39 ( F_40 ( V_18 , V_32 ) ) == V_56 &&
( F_244 ( V_18 , V_32 ) & V_350 ) ) {
int V_351 = F_14 ( V_18 , V_32 , 0 ,
V_352 , 0 ) ;
if ( V_351 & 0x02 )
return V_160 ;
}
return V_340 ;
}
static unsigned int F_120 ( struct V_17 * V_18 ,
unsigned int V_340 )
{
T_2 V_139 = V_18 -> V_19 . V_158 ? V_18 -> V_19 . V_158 : V_18 -> V_19 . V_159 ;
int V_209 ;
unsigned int V_341 ;
int V_15 = 0 ;
if ( V_340 == V_344 ) {
if ( V_18 -> V_152 < 0 )
F_128 ( F_245 ( V_18 ) ? 10 : 100 ) ;
else if ( V_18 -> V_152 > 0 )
F_128 ( V_18 -> V_152 ) ;
V_15 = V_25 ;
}
for ( V_209 = 0 ; V_209 < 10 ; V_209 ++ ) {
if ( V_18 -> V_125 . V_353 )
V_18 -> V_125 . V_353 ( V_18 , V_139 ,
V_340 ) ;
else {
V_341 = V_340 ;
if ( V_18 -> V_343 )
V_341 = V_18 -> V_343 ( V_18 , V_139 , V_341 ) ;
if ( V_341 == V_340 || V_340 != V_344 )
F_14 ( V_18 , V_139 , V_15 ,
V_345 ,
V_341 ) ;
F_239 ( V_18 , V_139 , V_340 ) ;
}
V_341 = F_240 ( V_18 , V_139 , V_340 ) ;
if ( ! ( V_341 & V_349 ) )
break;
}
return V_341 ;
}
static void F_246 ( struct V_17 * V_18 )
{
T_2 V_32 ;
if ( ! V_18 -> V_343 )
return;
F_57 (nid, codec) {
unsigned int V_58 = F_40 ( V_18 , V_32 ) ;
unsigned int V_106 ;
if ( ! ( V_58 & V_342 ) )
continue;
V_106 = V_18 -> V_343 ( V_18 , V_32 , V_160 ) ;
if ( V_106 == V_160 )
continue;
if ( ! F_247 ( V_18 , V_32 , V_106 ) )
F_17 ( V_18 , V_32 , 0 ,
V_345 , V_106 ) ;
}
}
static void F_248 ( struct V_17 * V_18 )
{
if ( V_18 -> V_354 . V_41 )
F_18 ( V_18 , V_18 -> V_354 . V_41 ) ;
}
static inline void F_248 ( struct V_17 * V_18 ) {}
static void F_249 ( struct V_17 * V_18 , bool V_355 )
{
unsigned long V_356 = V_156 - V_18 -> V_155 ;
if ( V_355 )
V_18 -> V_357 += V_356 ;
else
V_18 -> V_358 += V_356 ;
V_18 -> V_155 += V_356 ;
}
void F_250 ( struct V_17 * V_18 )
{
F_249 ( V_18 , F_251 ( V_18 ) ) ;
}
static unsigned int F_252 ( struct V_17 * V_18 )
{
unsigned int V_341 ;
F_253 ( & V_18 -> V_19 . V_359 ) ;
if ( V_18 -> V_125 . V_360 )
V_18 -> V_125 . V_360 ( V_18 ) ;
F_134 ( V_18 ) ;
V_341 = F_120 ( V_18 , V_344 ) ;
F_249 ( V_18 , true ) ;
F_254 ( & V_18 -> V_19 . V_359 ) ;
return V_341 ;
}
static void F_255 ( struct V_17 * V_18 )
{
F_253 ( & V_18 -> V_19 . V_359 ) ;
if ( V_18 -> V_19 . V_199 )
F_256 ( V_18 -> V_19 . V_199 ) ;
V_18 -> V_155 = V_156 ;
F_120 ( V_18 , V_160 ) ;
F_68 ( V_18 ) ;
F_248 ( V_18 ) ;
F_70 ( V_18 ) ;
if ( V_18 -> V_125 . V_361 )
V_18 -> V_125 . V_361 ( V_18 ) ;
else {
if ( V_18 -> V_125 . V_362 )
V_18 -> V_125 . V_362 ( V_18 ) ;
if ( V_18 -> V_19 . V_199 )
F_257 ( V_18 -> V_19 . V_199 ) ;
}
if ( V_18 -> V_112 )
F_69 ( & V_18 -> V_111 . V_110 ) ;
else
F_258 ( V_18 ) ;
F_254 ( & V_18 -> V_19 . V_359 ) ;
}
static int F_259 ( struct V_70 * V_13 )
{
struct V_17 * V_18 = F_109 ( V_13 ) ;
struct V_116 * V_117 ;
unsigned int V_341 ;
F_93 ( & V_18 -> V_111 ) ;
F_20 (pcm, &codec->pcm_list_head, list)
F_260 ( V_117 -> V_117 ) ;
V_341 = F_252 ( V_18 ) ;
if ( F_261 ( V_18 ) && F_245 ( V_18 ) &&
( V_341 & V_363 ) )
F_262 ( & V_18 -> V_19 ) ;
return 0 ;
}
static int F_263 ( struct V_70 * V_13 )
{
struct V_17 * V_18 = F_109 ( V_13 ) ;
F_264 ( & V_18 -> V_19 ) ;
F_255 ( V_18 ) ;
F_265 ( V_13 ) ;
return 0 ;
}
static int F_266 ( struct V_17 * V_18 )
{
struct V_116 * V_117 ;
int V_364 , V_22 ;
F_20 (pcm, &codec->pcm_list_head, list) {
for ( V_364 = 0 ; V_364 < 2 ; V_364 ++ ) {
struct V_365 * V_366 = & V_117 -> V_367 [ V_364 ] ;
struct V_368 * V_369 ;
const struct V_370 * V_371 ;
if ( ! V_117 || V_117 -> V_372 ||
! V_366 -> V_373 )
continue;
V_371 = V_366 -> V_369 ? V_366 -> V_369 : V_374 ;
V_22 = F_267 ( V_117 -> V_117 , V_364 , V_371 ,
V_366 -> V_375 ,
0 , & V_369 ) ;
if ( V_22 < 0 )
return V_22 ;
V_369 -> V_376 = V_377 ;
}
}
return 0 ;
}
int F_268 ( struct V_17 * V_18 )
{
int V_22 = 0 ;
F_248 ( V_18 ) ;
if ( V_18 -> V_125 . V_362 )
V_22 = V_18 -> V_125 . V_362 ( V_18 ) ;
if ( ! V_22 && V_18 -> V_125 . V_378 )
V_22 = V_18 -> V_125 . V_378 ( V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_266 ( V_18 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_18 -> V_112 )
F_69 ( & V_18 -> V_111 . V_110 ) ;
else
F_258 ( V_18 ) ;
F_246 ( V_18 ) ;
return 0 ;
}
unsigned int F_269 ( struct V_17 * V_18 ,
unsigned int V_379 ,
unsigned int V_380 ,
unsigned int V_171 ,
unsigned int V_381 ,
unsigned short V_382 )
{
int V_5 ;
unsigned int V_105 = 0 ;
for ( V_5 = 0 ; V_383 [ V_5 ] . V_384 ; V_5 ++ )
if ( V_383 [ V_5 ] . V_384 == V_379 ) {
V_105 = V_383 [ V_5 ] . V_385 ;
break;
}
if ( ! V_383 [ V_5 ] . V_384 ) {
F_13 ( V_18 , L_55 , V_379 ) ;
return 0 ;
}
if ( V_380 == 0 || V_380 > 8 ) {
F_13 ( V_18 , L_56 , V_380 ) ;
return 0 ;
}
V_105 |= V_380 - 1 ;
switch ( F_270 ( V_171 ) ) {
case 8 :
V_105 |= V_386 ;
break;
case 16 :
V_105 |= V_387 ;
break;
case 20 :
case 24 :
case 32 :
if ( V_381 >= 32 || V_171 == V_388 )
V_105 |= V_389 ;
else if ( V_381 >= 24 )
V_105 |= V_390 ;
else
V_105 |= V_391 ;
break;
default:
F_13 ( V_18 , L_57 ,
F_270 ( V_171 ) ) ;
return 0 ;
}
if ( V_382 & V_310 )
V_105 |= V_392 ;
return V_105 ;
}
static unsigned int F_271 ( struct V_17 * V_18 , T_2 V_32 )
{
unsigned int V_105 = 0 ;
if ( V_32 != V_18 -> V_19 . V_158 &&
( F_40 ( V_18 , V_32 ) & V_393 ) )
V_105 = F_136 ( V_18 , V_32 , V_394 ) ;
if ( ! V_105 || V_105 == - 1 )
V_105 = F_136 ( V_18 , V_18 -> V_19 . V_158 , V_394 ) ;
if ( ! V_105 || V_105 == - 1 )
return 0 ;
return V_105 ;
}
static unsigned int F_272 ( struct V_17 * V_18 , T_2 V_32 )
{
unsigned int V_254 = F_136 ( V_18 , V_32 , V_395 ) ;
if ( ! V_254 || V_254 == - 1 )
V_254 = F_136 ( V_18 , V_18 -> V_19 . V_158 , V_395 ) ;
if ( ! V_254 || V_254 == - 1 )
return 0 ;
return V_254 ;
}
int F_273 ( struct V_17 * V_18 , T_2 V_32 ,
T_1 * V_396 , T_9 * V_397 , unsigned int * V_398 )
{
unsigned int V_5 , V_105 , V_58 ;
V_58 = F_40 ( V_18 , V_32 ) ;
V_105 = F_271 ( V_18 , V_32 ) ;
if ( V_396 ) {
T_1 V_399 = 0 ;
for ( V_5 = 0 ; V_5 < V_400 ; V_5 ++ ) {
if ( V_105 & ( 1 << V_5 ) )
V_399 |= V_383 [ V_5 ] . V_401 ;
}
if ( V_399 == 0 ) {
F_37 ( V_18 ,
L_58 ,
V_32 , V_105 ,
( V_58 & V_393 ) ? 1 : 0 ) ;
return - V_77 ;
}
* V_396 = V_399 ;
}
if ( V_397 || V_398 ) {
T_9 V_402 = 0 ;
unsigned int V_254 , V_403 ;
V_254 = F_272 ( V_18 , V_32 ) ;
if ( ! V_254 )
return - V_77 ;
V_403 = 0 ;
if ( V_254 & V_404 ) {
if ( V_105 & V_405 ) {
V_402 |= V_406 ;
V_403 = 8 ;
}
if ( V_105 & V_407 ) {
V_402 |= V_408 ;
V_403 = 16 ;
}
if ( V_58 & V_60 ) {
if ( V_105 & V_409 )
V_402 |= V_410 ;
if ( V_105 & ( V_411 | V_412 ) )
V_402 |= V_413 ;
if ( V_105 & V_412 )
V_403 = 24 ;
else if ( V_105 & V_411 )
V_403 = 20 ;
} else if ( V_105 & ( V_411 | V_412 |
V_409 ) ) {
V_402 |= V_413 ;
if ( V_105 & V_409 )
V_403 = 32 ;
else if ( V_105 & V_412 )
V_403 = 24 ;
else if ( V_105 & V_411 )
V_403 = 20 ;
}
}
#if 0
if (streams & AC_SUPFMT_FLOAT32) {
formats |= SNDRV_PCM_FMTBIT_FLOAT_LE;
if (!bps)
bps = 32;
}
#endif
if ( V_254 == V_414 ) {
V_402 |= V_406 ;
V_403 = 8 ;
}
if ( V_402 == 0 ) {
F_37 ( V_18 ,
L_59 ,
V_32 , V_105 ,
( V_58 & V_393 ) ? 1 : 0 ,
V_254 ) ;
return - V_77 ;
}
if ( V_397 )
* V_397 = V_402 ;
if ( V_398 )
* V_398 = V_403 ;
}
return 0 ;
}
int F_274 ( struct V_17 * V_18 , T_2 V_32 ,
unsigned int V_171 )
{
int V_5 ;
unsigned int V_105 = 0 , V_379 , V_367 ;
V_105 = F_271 ( V_18 , V_32 ) ;
if ( ! V_105 )
return 0 ;
V_379 = V_171 & 0xff00 ;
for ( V_5 = 0 ; V_5 < V_400 ; V_5 ++ )
if ( V_383 [ V_5 ] . V_385 == V_379 ) {
if ( V_105 & ( 1 << V_5 ) )
break;
return 0 ;
}
if ( V_5 >= V_400 )
return 0 ;
V_367 = F_272 ( V_18 , V_32 ) ;
if ( ! V_367 )
return 0 ;
if ( V_367 & V_404 ) {
switch ( V_171 & 0xf0 ) {
case 0x00 :
if ( ! ( V_105 & V_405 ) )
return 0 ;
break;
case 0x10 :
if ( ! ( V_105 & V_407 ) )
return 0 ;
break;
case 0x20 :
if ( ! ( V_105 & V_411 ) )
return 0 ;
break;
case 0x30 :
if ( ! ( V_105 & V_412 ) )
return 0 ;
break;
case 0x40 :
if ( ! ( V_105 & V_409 ) )
return 0 ;
break;
default:
return 0 ;
}
} else {
}
return 1 ;
}
static int F_275 ( struct V_365 * V_366 ,
struct V_17 * V_18 ,
struct V_415 * V_416 )
{
return 0 ;
}
static int F_276 ( struct V_365 * V_366 ,
struct V_17 * V_18 ,
unsigned int V_165 ,
unsigned int V_171 ,
struct V_415 * V_416 )
{
F_129 ( V_18 , V_366 -> V_32 , V_165 , 0 , V_171 ) ;
return 0 ;
}
static int F_277 ( struct V_365 * V_366 ,
struct V_17 * V_18 ,
struct V_415 * V_416 )
{
F_278 ( V_18 , V_366 -> V_32 ) ;
return 0 ;
}
static int F_279 ( struct V_17 * V_18 ,
struct V_365 * V_294 )
{
int V_22 ;
if ( V_294 -> V_32 && ( ! V_294 -> V_399 || ! V_294 -> V_402 ) ) {
V_22 = F_273 ( V_18 , V_294 -> V_32 ,
V_294 -> V_399 ? NULL : & V_294 -> V_399 ,
V_294 -> V_402 ? NULL : & V_294 -> V_402 ,
V_294 -> V_381 ? NULL : & V_294 -> V_381 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( V_294 -> V_30 . V_417 == NULL )
V_294 -> V_30 . V_417 = F_275 ;
if ( V_294 -> V_30 . V_418 == NULL )
V_294 -> V_30 . V_418 = F_275 ;
if ( V_294 -> V_30 . V_419 == NULL ) {
if ( F_35 ( ! V_294 -> V_32 ) )
return - V_50 ;
V_294 -> V_30 . V_419 = F_276 ;
}
if ( V_294 -> V_30 . V_420 == NULL ) {
if ( F_35 ( ! V_294 -> V_32 ) )
return - V_50 ;
V_294 -> V_30 . V_420 = F_277 ;
}
return 0 ;
}
int F_280 ( struct V_17 * V_18 ,
struct V_365 * V_366 ,
unsigned int V_367 ,
unsigned int V_171 ,
struct V_415 * V_416 )
{
int V_197 ;
F_8 ( & V_18 -> V_21 -> V_86 ) ;
if ( V_366 -> V_30 . V_419 )
V_197 = V_366 -> V_30 . V_419 ( V_366 , V_18 , V_367 , V_171 ,
V_416 ) ;
else
V_197 = - V_157 ;
if ( V_197 >= 0 )
F_133 ( V_18 ) ;
F_10 ( & V_18 -> V_21 -> V_86 ) ;
return V_197 ;
}
void F_281 ( struct V_17 * V_18 ,
struct V_365 * V_366 ,
struct V_415 * V_416 )
{
F_8 ( & V_18 -> V_21 -> V_86 ) ;
if ( V_366 -> V_30 . V_420 )
V_366 -> V_30 . V_420 ( V_366 , V_18 , V_416 ) ;
F_10 ( & V_18 -> V_21 -> V_86 ) ;
}
static int F_282 ( struct V_20 * V_21 , unsigned int type )
{
static int V_421 [ V_422 ] [ 5 ] = {
[ V_423 ] = { 0 , 2 , 4 , 5 , - 1 } ,
[ V_330 ] = { 1 , - 1 } ,
[ V_329 ] = { 3 , 7 , 8 , 9 , - 1 } ,
[ V_424 ] = { 6 , - 1 } ,
} ;
int V_5 ;
if ( type >= V_422 ) {
F_283 ( V_21 -> V_79 -> V_13 , L_60 , type ) ;
return - V_50 ;
}
for ( V_5 = 0 ; V_421 [ type ] [ V_5 ] >= 0 ; V_5 ++ ) {
#ifndef F_284
if ( V_421 [ type ] [ V_5 ] >= 8 )
break;
#endif
if ( ! F_285 ( V_421 [ type ] [ V_5 ] , V_21 -> V_118 ) )
return V_421 [ type ] [ V_5 ] ;
}
#ifdef F_284
for ( V_5 = 10 ; V_5 < 32 ; V_5 ++ ) {
if ( ! F_285 ( V_5 , V_21 -> V_118 ) )
return V_5 ;
}
#endif
F_286 ( V_21 -> V_79 -> V_13 , L_61 ,
V_425 [ type ] ) ;
#ifndef F_284
F_286 ( V_21 -> V_79 -> V_13 ,
L_62 ) ;
#endif
return - V_426 ;
}
int F_287 ( struct V_17 * V_18 )
{
struct V_116 * V_253 ;
int V_22 ;
if ( ! F_25 ( & V_18 -> V_121 ) )
return 0 ;
if ( ! V_18 -> V_125 . V_427 )
return 0 ;
V_22 = V_18 -> V_125 . V_427 ( V_18 ) ;
if ( V_22 < 0 ) {
F_37 ( V_18 , L_63 ,
V_18 -> V_19 . V_27 , V_22 ) ;
return V_22 ;
}
F_20 (cpcm, &codec->pcm_list_head, list) {
int V_367 ;
for ( V_367 = 0 ; V_367 < 2 ; V_367 ++ ) {
struct V_365 * V_294 = & V_253 -> V_367 [ V_367 ] ;
if ( ! V_294 -> V_373 )
continue;
V_22 = F_279 ( V_18 , V_294 ) ;
if ( V_22 < 0 ) {
F_156 ( V_18 ,
L_64 ,
V_253 -> V_119 ) ;
return V_22 ;
}
}
}
return 0 ;
}
int F_288 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = V_18 -> V_21 ;
struct V_116 * V_253 ;
int V_13 , V_22 ;
if ( F_35 ( ! V_21 -> V_30 . V_428 ) )
return - V_50 ;
V_22 = F_287 ( V_18 ) ;
if ( V_22 < 0 ) {
F_179 ( V_18 ) ;
return V_22 ;
}
F_20 (cpcm, &codec->pcm_list_head, list) {
if ( V_253 -> V_117 )
continue;
if ( ! V_253 -> V_367 [ 0 ] . V_373 && ! V_253 -> V_367 [ 1 ] . V_373 )
continue;
V_13 = F_282 ( V_21 , V_253 -> V_429 ) ;
if ( V_13 < 0 )
continue;
V_253 -> V_70 = V_13 ;
V_22 = V_21 -> V_30 . V_428 ( V_21 , V_18 , V_253 ) ;
if ( V_22 < 0 ) {
F_37 ( V_18 ,
L_65 ,
V_13 , V_18 -> V_19 . V_27 ) ;
continue;
}
}
return 0 ;
}
int F_289 ( struct V_17 * V_18 ,
const struct V_325 * V_430 )
{
int V_22 ;
for (; V_430 -> V_119 ; V_430 ++ ) {
struct V_203 * V_241 ;
int V_27 = 0 , V_192 = 0 ;
if ( V_430 -> V_236 == - 1 )
continue;
for (; ; ) {
V_241 = F_201 ( V_430 , V_18 ) ;
if ( ! V_241 )
return - V_43 ;
if ( V_27 > 0 )
V_241 -> V_213 . V_70 = V_27 ;
if ( V_192 > 0 )
V_241 -> V_213 . V_238 = V_192 ;
V_22 = F_170 ( V_18 , 0 , V_241 ) ;
if ( ! V_22 )
break;
if ( ! V_27 && V_18 -> V_19 . V_27 )
V_27 = V_18 -> V_19 . V_27 ;
else if ( ! V_192 && ! V_430 -> V_238 ) {
V_192 = F_169 ( V_18 ,
V_430 -> V_119 , 0 ) ;
if ( V_192 <= 0 )
return V_22 ;
} else
return V_22 ;
}
}
return 0 ;
}
static void F_290 ( struct V_17 * V_18 , int V_431 )
{
struct V_70 * V_13 = F_91 ( V_18 ) ;
if ( V_431 > 0 ) {
F_291 ( V_13 , V_431 ) ;
F_292 ( V_13 ) ;
F_293 ( V_13 ) ;
if ( ! F_294 ( V_13 ) )
F_265 ( V_13 ) ;
} else {
F_295 ( V_13 ) ;
F_296 ( V_13 ) ;
}
}
void F_297 ( struct V_20 * V_21 , int V_431 )
{
struct V_17 * V_175 ;
F_130 (c, bus)
F_290 ( V_175 , V_431 ) ;
}
int F_298 ( struct V_17 * V_18 ,
struct V_432 * V_433 ,
T_2 V_32 )
{
const struct V_434 * V_39 ;
int V_191 , V_435 ;
if ( ! V_433 -> V_436 )
return 0 ;
for ( V_39 = V_433 -> V_436 ; V_39 -> V_32 ; V_39 ++ ) {
if ( V_39 -> V_32 == V_32 )
break;
}
if ( ! V_39 -> V_32 )
return 0 ;
for ( V_39 = V_433 -> V_436 ; V_39 -> V_32 ; V_39 ++ ) {
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ ) {
V_435 = F_147 ( V_18 , V_39 -> V_32 , V_191 , V_39 -> V_188 ,
V_39 -> V_192 ) ;
if ( ! ( V_435 & V_287 ) && V_435 > 0 ) {
if ( ! V_433 -> V_437 ) {
V_433 -> V_437 = 1 ;
F_7 ( V_18 ) ;
}
return 1 ;
}
}
}
if ( V_433 -> V_437 ) {
V_433 -> V_437 = 0 ;
F_11 ( V_18 ) ;
}
return 0 ;
}
int F_299 ( const struct V_438 * V_439 ,
struct V_205 * V_206 )
{
unsigned int V_238 ;
V_206 -> type = V_440 ;
V_206 -> V_209 = 1 ;
V_206 -> V_210 . V_277 . V_248 = V_439 -> V_441 ;
if ( ! V_439 -> V_441 )
return 0 ;
V_238 = V_206 -> V_210 . V_277 . V_242 ;
if ( V_238 >= V_439 -> V_441 )
V_238 = V_439 -> V_441 - 1 ;
strcpy ( V_206 -> V_210 . V_277 . V_119 , V_439 -> V_248 [ V_238 ] . V_442 ) ;
return 0 ;
}
int F_300 ( struct V_17 * V_18 ,
const struct V_438 * V_439 ,
struct V_216 * V_217 ,
T_2 V_32 ,
unsigned int * V_443 )
{
unsigned int V_192 ;
if ( ! V_439 -> V_441 )
return 0 ;
V_192 = V_217 -> V_210 . V_277 . V_242 [ 0 ] ;
if ( V_192 >= V_439 -> V_441 )
V_192 = V_439 -> V_441 - 1 ;
if ( * V_443 == V_192 )
return 0 ;
F_301 ( V_18 , V_32 , 0 , V_444 ,
V_439 -> V_248 [ V_192 ] . V_238 ) ;
* V_443 = V_192 ;
return 1 ;
}
int F_302 ( struct V_203 * V_204 ,
struct V_205 * V_206 ,
int V_441 , const char * const * V_274 )
{
static const char * const V_445 [] = {
L_66 , L_67
} ;
if ( ! V_274 || ! V_441 ) {
V_441 = 2 ;
V_274 = V_445 ;
}
return F_194 ( V_206 , 1 , V_441 , V_274 ) ;
}
static void F_303 ( struct V_17 * V_18 , T_2 V_32 ,
unsigned int V_165 , unsigned int V_171 )
{
struct V_149 * V_307 ;
unsigned int V_446 ;
bool V_447 ;
V_307 = F_228 ( V_18 , V_32 ) ;
V_446 = F_14 ( V_18 , V_32 , 0 ,
V_173 , 0 ) ;
V_447 = V_18 -> V_132 &&
( V_307 -> V_320 & V_321 ) &&
V_446 != V_171 ;
if ( V_447 )
F_221 ( V_18 , V_32 ,
V_307 -> V_320 & ~ V_321 & 0xff ,
- 1 ) ;
F_129 ( V_18 , V_32 , V_165 , 0 , V_171 ) ;
if ( V_18 -> V_131 ) {
const T_2 * V_316 ;
for ( V_316 = V_18 -> V_131 ; * V_316 ; V_316 ++ )
F_129 ( V_18 , * V_316 , V_165 , 0 ,
V_171 ) ;
}
if ( V_447 )
F_221 ( V_18 , V_32 ,
V_307 -> V_320 & 0xff , - 1 ) ;
}
static void F_304 ( struct V_17 * V_18 , T_2 V_32 )
{
F_278 ( V_18 , V_32 ) ;
if ( V_18 -> V_131 ) {
const T_2 * V_316 ;
for ( V_316 = V_18 -> V_131 ; * V_316 ; V_316 ++ )
F_278 ( V_18 , * V_316 ) ;
}
}
int F_305 ( struct V_17 * V_18 ,
struct V_333 * V_334 )
{
F_8 ( & V_18 -> V_146 ) ;
if ( V_334 -> V_448 == V_449 )
F_304 ( V_18 , V_334 -> V_336 ) ;
V_334 -> V_448 = V_450 ;
F_10 ( & V_18 -> V_146 ) ;
return 0 ;
}
int F_306 ( struct V_17 * V_18 ,
struct V_333 * V_334 ,
unsigned int V_165 ,
unsigned int V_171 ,
struct V_415 * V_416 )
{
F_8 ( & V_18 -> V_146 ) ;
F_303 ( V_18 , V_334 -> V_336 , V_165 , V_171 ) ;
F_10 ( & V_18 -> V_146 ) ;
return 0 ;
}
int F_307 ( struct V_17 * V_18 ,
struct V_333 * V_334 )
{
F_8 ( & V_18 -> V_146 ) ;
F_304 ( V_18 , V_334 -> V_336 ) ;
F_10 ( & V_18 -> V_146 ) ;
return 0 ;
}
int F_308 ( struct V_17 * V_18 ,
struct V_333 * V_334 )
{
F_8 ( & V_18 -> V_146 ) ;
V_334 -> V_448 = 0 ;
F_10 ( & V_18 -> V_146 ) ;
return 0 ;
}
int F_309 ( struct V_17 * V_18 ,
struct V_333 * V_334 ,
struct V_415 * V_416 ,
struct V_365 * V_366 )
{
struct V_451 * V_452 = V_416 -> V_452 ;
V_452 -> V_453 . V_375 = V_334 -> V_454 ;
if ( V_334 -> V_336 ) {
if ( ! V_334 -> V_455 ) {
V_334 -> V_455 = V_366 -> V_399 ;
V_334 -> V_456 = V_366 -> V_402 ;
V_334 -> V_457 = V_366 -> V_381 ;
} else {
V_452 -> V_453 . V_399 = V_334 -> V_455 ;
V_452 -> V_453 . V_402 = V_334 -> V_456 ;
V_366 -> V_381 = V_334 -> V_457 ;
}
if ( ! V_334 -> V_458 ) {
F_273 ( V_18 , V_334 -> V_336 ,
& V_334 -> V_458 ,
& V_334 -> V_459 ,
& V_334 -> V_460 ) ;
}
F_8 ( & V_18 -> V_146 ) ;
if ( V_334 -> V_335 ) {
if ( ( V_452 -> V_453 . V_399 & V_334 -> V_458 ) &&
( V_452 -> V_453 . V_402 & V_334 -> V_459 ) ) {
V_452 -> V_453 . V_399 &= V_334 -> V_458 ;
V_452 -> V_453 . V_402 &= V_334 -> V_459 ;
if ( V_334 -> V_460 < V_366 -> V_381 )
V_366 -> V_381 = V_334 -> V_460 ;
} else {
V_334 -> V_335 = 0 ;
}
}
F_10 ( & V_18 -> V_146 ) ;
}
return F_310 ( V_416 -> V_452 , 0 ,
V_461 , 2 ) ;
}
int F_311 ( struct V_17 * V_18 ,
struct V_333 * V_334 ,
unsigned int V_165 ,
unsigned int V_171 ,
struct V_415 * V_416 )
{
const T_2 * V_134 = V_334 -> V_462 ;
int V_207 = V_416 -> V_452 -> V_380 ;
struct V_149 * V_307 ;
int V_5 ;
F_8 ( & V_18 -> V_146 ) ;
V_307 = F_228 ( V_18 , V_334 -> V_336 ) ;
if ( V_334 -> V_336 && V_334 -> V_335 &&
V_334 -> V_448 != V_450 ) {
if ( V_207 == 2 &&
F_274 ( V_18 , V_334 -> V_336 ,
V_171 ) &&
! ( V_307 -> V_299 & V_301 ) ) {
V_334 -> V_448 = V_449 ;
F_303 ( V_18 , V_334 -> V_336 ,
V_165 , V_171 ) ;
} else {
V_334 -> V_448 = 0 ;
F_304 ( V_18 , V_334 -> V_336 ) ;
}
}
F_10 ( & V_18 -> V_146 ) ;
F_129 ( V_18 , V_134 [ V_463 ] , V_165 ,
0 , V_171 ) ;
if ( ! V_334 -> V_464 &&
V_334 -> V_465 && V_334 -> V_465 != V_134 [ V_463 ] )
F_129 ( V_18 , V_334 -> V_465 , V_165 ,
0 , V_171 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_334 -> V_466 ) ; V_5 ++ )
if ( ! V_334 -> V_464 && V_334 -> V_466 [ V_5 ] )
F_129 ( V_18 ,
V_334 -> V_466 [ V_5 ] ,
V_165 , 0 , V_171 ) ;
for ( V_5 = 1 ; V_5 < V_334 -> V_467 ; V_5 ++ ) {
if ( V_207 >= ( V_5 + 1 ) * 2 )
F_129 ( V_18 , V_134 [ V_5 ] , V_165 ,
V_5 * 2 , V_171 ) ;
else if ( ! V_334 -> V_464 )
F_129 ( V_18 , V_134 [ V_5 ] , V_165 ,
0 , V_171 ) ;
}
for ( V_5 = 0 ; V_5 < F_2 ( V_334 -> V_468 ) ; V_5 ++ ) {
int V_191 = 0 ;
if ( ! V_334 -> V_468 [ V_5 ] )
break;
if ( V_207 >= ( V_5 + 1 ) * 2 )
V_191 = V_5 * 2 ;
else if ( ! V_334 -> V_464 )
break;
F_129 ( V_18 , V_334 -> V_468 [ V_5 ] ,
V_165 , V_191 , V_171 ) ;
}
return 0 ;
}
int F_312 ( struct V_17 * V_18 ,
struct V_333 * V_334 )
{
const T_2 * V_134 = V_334 -> V_462 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_334 -> V_467 ; V_5 ++ )
F_278 ( V_18 , V_134 [ V_5 ] ) ;
if ( V_334 -> V_465 )
F_278 ( V_18 , V_334 -> V_465 ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_334 -> V_466 ) ; V_5 ++ )
if ( V_334 -> V_466 [ V_5 ] )
F_278 ( V_18 ,
V_334 -> V_466 [ V_5 ] ) ;
for ( V_5 = 0 ; V_5 < F_2 ( V_334 -> V_468 ) ; V_5 ++ )
if ( V_334 -> V_468 [ V_5 ] )
F_278 ( V_18 ,
V_334 -> V_468 [ V_5 ] ) ;
F_8 ( & V_18 -> V_146 ) ;
if ( V_334 -> V_336 && V_334 -> V_448 == V_449 ) {
F_304 ( V_18 , V_334 -> V_336 ) ;
V_334 -> V_448 = 0 ;
}
F_10 ( & V_18 -> V_146 ) ;
return 0 ;
}
unsigned int F_313 ( struct V_17 * V_18 , T_2 V_93 )
{
unsigned int V_469 ;
unsigned int V_167 ;
V_167 = F_14 ( V_18 , V_93 , 0 ,
V_98 , 0 ) ;
V_469 = F_244 ( V_18 , V_93 ) ;
V_469 = ( V_469 & V_470 ) >> V_471 ;
if ( ( V_469 & V_472 ) && V_167 != V_473 )
return V_474 ;
else if ( V_469 & V_475 )
return V_476 ;
else if ( V_469 & V_477 )
return V_478 ;
else if ( V_469 & V_479 )
return V_480 ;
return V_481 ;
}
unsigned int F_314 ( struct V_17 * V_18 ,
T_2 V_93 , unsigned int V_105 )
{
static unsigned int V_482 [] [ 2 ] = {
{ V_478 , V_477 } ,
{ V_474 , V_472 } ,
{ V_476 , V_475 } ,
{ V_480 , V_479 } ,
} ;
unsigned int V_483 ;
if ( ! V_105 )
return 0 ;
V_483 = F_244 ( V_18 , V_93 ) ;
if ( ! V_483 )
return V_105 ;
if ( V_105 & V_484 ) {
if ( ! ( V_483 & V_485 ) )
V_105 &= ~ ( V_484 | V_486 ) ;
else if ( ( V_105 & V_486 ) && ! ( V_483 & V_487 ) )
V_105 &= ~ V_486 ;
}
if ( V_105 & V_488 ) {
if ( ! ( V_483 & V_489 ) )
V_105 &= ~ ( V_488 | V_490 ) ;
else {
unsigned int V_491 , V_492 ;
int V_5 ;
V_491 = ( V_483 & V_470 ) >> V_471 ;
V_492 = V_105 & V_490 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_482 ) ; V_5 ++ ) {
if ( V_492 == V_482 [ V_5 ] [ 0 ] &&
! ( V_491 & V_482 [ V_5 ] [ 1 ] ) ) {
if ( V_5 == F_2 ( V_482 ) - 1 )
V_492 = V_481 ;
else
V_492 = V_482 [ V_5 + 1 ] [ 0 ] ;
}
}
V_105 &= ~ V_490 ;
V_105 |= V_492 ;
}
}
return V_105 ;
}
int F_315 ( struct V_17 * V_18 , T_2 V_93 ,
unsigned int V_105 , bool V_493 )
{
V_105 = F_314 ( V_18 , V_93 , V_105 ) ;
F_65 ( V_18 , V_93 , V_105 ) ;
if ( V_493 )
return F_316 ( V_18 , V_93 , 0 ,
V_107 , V_105 ) ;
else
return F_17 ( V_18 , V_93 , 0 ,
V_107 , V_105 ) ;
}
int F_317 ( struct V_17 * V_18 ,
struct V_438 * V_439 , const char * V_442 ,
int V_238 , int * V_494 )
{
int V_5 , V_495 = 0 ;
if ( V_439 -> V_441 >= V_496 ) {
F_37 ( V_18 , L_68 ) ;
return - V_50 ;
}
for ( V_5 = 0 ; V_5 < V_439 -> V_441 ; V_5 ++ ) {
if ( ! strncmp ( V_442 , V_439 -> V_248 [ V_5 ] . V_442 , strlen ( V_442 ) ) )
V_495 ++ ;
}
if ( V_494 )
* V_494 = V_495 ;
if ( V_495 > 0 )
snprintf ( V_439 -> V_248 [ V_439 -> V_441 ] . V_442 ,
sizeof( V_439 -> V_248 [ V_439 -> V_441 ] . V_442 ) ,
L_69 , V_442 , V_495 ) ;
else
F_318 ( V_439 -> V_248 [ V_439 -> V_441 ] . V_442 , V_442 ,
sizeof( V_439 -> V_248 [ V_439 -> V_441 ] . V_442 ) ) ;
V_439 -> V_248 [ V_439 -> V_441 ] . V_238 = V_238 ;
V_439 -> V_441 ++ ;
return 0 ;
}
void F_319 ( struct V_20 * V_21 )
{
struct V_17 * V_18 ;
F_130 (codec, bus) {
F_93 ( & V_18 -> V_111 ) ;
#ifdef F_117
if ( F_251 ( V_18 ) ) {
F_252 ( V_18 ) ;
F_255 ( V_18 ) ;
}
#endif
}
}
void F_320 ( int V_117 , char * V_497 , int V_498 )
{
static unsigned int V_189 [] = { 8 , 16 , 20 , 24 , 32 } ;
int V_5 , V_499 ;
for ( V_5 = 0 , V_499 = 0 ; V_5 < F_2 ( V_189 ) ; V_5 ++ )
if ( V_117 & ( V_405 << V_5 ) )
V_499 += snprintf ( V_497 + V_499 , V_498 - V_499 , L_70 , V_189 [ V_5 ] ) ;
V_497 [ V_499 ] = '\0' ;
}
