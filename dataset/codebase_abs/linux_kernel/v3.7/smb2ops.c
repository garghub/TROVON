static int
F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 += V_2 -> V_4 + V_2 -> V_5 ;
V_2 -> V_5 = V_2 -> V_4 = 0 ;
switch ( V_2 -> V_3 ) {
case 0 :
return - 1 ;
case 1 :
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
F_2 ( 1 , L_1 ) ;
break;
case 2 :
V_2 -> V_6 = true ;
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
F_3 ( 1 , L_2 ) ;
break;
default:
V_2 -> V_6 = true ;
V_2 -> V_7 = true ;
V_2 -> V_4 = 1 ;
V_2 -> V_5 = 1 ;
}
V_2 -> V_3 -= V_2 -> V_4 + V_2 -> V_5 ;
return 0 ;
}
static void
F_4 ( struct V_1 * V_2 , const unsigned int V_8 ,
const int V_9 )
{
int * V_10 , V_11 = 0 ;
F_5 ( & V_2 -> V_12 ) ;
V_10 = V_2 -> V_13 -> V_14 ( V_2 , V_9 ) ;
* V_10 += V_8 ;
V_2 -> V_15 -- ;
if ( V_2 -> V_15 == 0 && ( V_9 & V_16 ) != V_17 )
V_11 = F_1 ( V_2 ) ;
else if ( V_2 -> V_15 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_18 ) ;
if ( V_11 )
F_8 ( V_2 ) ;
}
static void
F_9 ( struct V_1 * V_2 , const int V_10 )
{
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_3 = V_10 ;
F_6 ( & V_2 -> V_12 ) ;
}
static int *
F_10 ( struct V_1 * V_2 , const int V_9 )
{
switch ( V_9 ) {
case V_19 :
return & V_2 -> V_4 ;
case V_20 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_11 ( struct V_21 * V_22 )
{
return F_12 ( ( (struct V_23 * ) V_22 -> V_24 ) -> V_25 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 )
{
T_1 V_22 ;
F_5 ( & V_26 ) ;
V_22 = V_2 -> V_27 ++ ;
F_6 ( & V_26 ) ;
return V_22 ;
}
static struct V_21 *
F_14 ( struct V_1 * V_2 , char * V_28 )
{
struct V_21 * V_22 ;
struct V_23 * V_29 = (struct V_23 * ) V_28 ;
F_5 ( & V_26 ) ;
F_15 (mid, &server->pending_mid_q, qhead) {
if ( ( V_22 -> V_22 == V_29 -> V_30 ) &&
( V_22 -> V_31 == V_32 ) &&
( V_22 -> V_33 == V_29 -> V_34 ) ) {
F_6 ( & V_26 ) ;
return V_22 ;
}
}
F_6 ( & V_26 ) ;
return NULL ;
}
static void
F_16 ( void * V_28 )
{
#ifdef F_17
struct V_23 * V_35 = (struct V_23 * ) V_28 ;
F_2 ( 1 , L_3 ,
V_35 -> V_34 , V_35 -> V_36 , V_35 -> V_37 , V_35 -> V_30 ,
V_35 -> V_38 ) ;
F_2 ( 1 , L_4 , V_35 , F_18 ( V_35 ) ) ;
#endif
}
static bool
F_19 ( struct V_1 * V_2 )
{
return V_2 -> V_39 == 0 ;
}
static int
F_20 ( const unsigned int V_40 , struct V_41 * V_42 )
{
int V_11 ;
V_42 -> V_2 -> V_27 = 0 ;
V_11 = F_21 ( V_40 , V_42 ) ;
if ( V_11 == - V_43 )
V_11 = - V_44 ;
return V_11 ;
}
static unsigned int
F_22 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_1 * V_2 = V_46 -> V_42 -> V_2 ;
unsigned int V_49 ;
V_49 = V_48 -> V_49 ? V_48 -> V_49 : V_50 ;
V_49 = F_23 (unsigned int, wsize, server->max_write) ;
V_49 = F_23 (unsigned int, wsize, 2 << 15 ) ;
return V_49 ;
}
static unsigned int
F_24 ( struct V_45 * V_46 , struct V_47 * V_48 )
{
struct V_1 * V_2 = V_46 -> V_42 -> V_2 ;
unsigned int V_51 ;
V_51 = V_48 -> V_51 ? V_48 -> V_51 : V_50 ;
V_51 = F_23 (unsigned int, rsize, server->max_read) ;
V_51 = F_23 (unsigned int, rsize, 2 << 15 ) ;
return V_51 ;
}
static int
F_25 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_52 * V_53 , const char * V_54 )
{
int V_11 ;
T_1 V_55 , V_56 ;
T_2 * V_57 ;
T_3 V_58 = V_59 ;
V_57 = F_26 ( V_54 , V_53 ) ;
if ( ! V_57 )
return - V_60 ;
V_11 = F_27 ( V_40 , V_46 , V_57 , & V_55 , & V_56 ,
V_61 , V_62 , 0 , 0 , & V_58 , NULL ) ;
if ( V_11 ) {
F_28 ( V_57 ) ;
return V_11 ;
}
V_11 = F_29 ( V_40 , V_46 , V_55 , V_56 ) ;
F_28 ( V_57 ) ;
return V_11 ;
}
static int
F_30 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_52 * V_53 , const char * V_54 ,
T_4 * V_63 , T_5 * V_64 )
{
* V_63 = F_31 ( V_64 -> V_65 ) ;
return 0 ;
}
static int
F_32 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 , T_5 * V_64 )
{
int V_11 ;
struct V_68 * V_69 ;
V_69 = F_33 ( sizeof( struct V_68 ) + V_70 * 2 ,
V_71 ) ;
if ( V_69 == NULL )
return - V_60 ;
V_11 = F_34 ( V_40 , V_46 , V_67 -> V_55 , V_67 -> V_56 ,
V_69 ) ;
if ( ! V_11 )
F_35 ( V_64 , V_69 ) ;
F_28 ( V_69 ) ;
return V_11 ;
}
static char *
F_36 ( struct V_47 * V_72 , struct V_52 * V_53 ,
struct V_45 * V_46 )
{
int V_73 = V_72 -> V_74 ? strlen ( V_72 -> V_74 ) : 0 ;
char * V_54 = NULL ;
if ( V_73 == 0 ) {
V_54 = F_33 ( 2 , V_71 ) ;
return V_54 ;
}
F_2 ( 1 , L_5 ) ;
return NULL ;
}
static bool
F_37 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_38 ( struct V_45 * V_46 )
{
#ifdef F_39
int V_75 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
F_40 ( & V_46 -> V_77 . V_78 . V_79 [ V_75 ] , 0 ) ;
F_40 ( & V_46 -> V_77 . V_78 . V_80 [ V_75 ] , 0 ) ;
}
#endif
}
static void
F_41 ( struct V_81 * V_82 , struct V_45 * V_46 )
{
#ifdef F_39
T_6 * V_83 = V_46 -> V_77 . V_78 . V_79 ;
T_6 * V_84 = V_46 -> V_77 . V_78 . V_80 ;
F_42 ( V_82 , L_6 ,
F_43 ( & V_83 [ V_85 ] ) ,
F_43 ( & V_84 [ V_85 ] ) ) ;
F_42 ( V_82 , L_7 ,
F_43 ( & V_83 [ V_86 ] ) ,
F_43 ( & V_84 [ V_86 ] ) ) ;
#define F_44 0x0002
F_42 ( V_82 , L_8 ,
F_43 ( & V_83 [ V_87 ] ) ,
F_43 ( & V_84 [ V_87 ] ) ) ;
F_42 ( V_82 , L_9 ,
F_43 ( & V_83 [ V_88 ] ) ,
F_43 ( & V_84 [ V_88 ] ) ) ;
F_42 ( V_82 , L_10 ,
F_43 ( & V_83 [ V_89 ] ) ,
F_43 ( & V_84 [ V_89 ] ) ) ;
F_42 ( V_82 , L_11 ,
F_43 ( & V_83 [ V_90 ] ) ,
F_43 ( & V_84 [ V_90 ] ) ) ;
F_42 ( V_82 , L_12 ,
F_43 ( & V_83 [ V_91 ] ) ,
F_43 ( & V_84 [ V_91 ] ) ) ;
F_42 ( V_82 , L_13 ,
F_43 ( & V_83 [ V_92 ] ) ,
F_43 ( & V_84 [ V_92 ] ) ) ;
F_42 ( V_82 , L_14 ,
F_43 ( & V_83 [ V_93 ] ) ,
F_43 ( & V_84 [ V_93 ] ) ) ;
F_42 ( V_82 , L_15 ,
F_43 ( & V_83 [ V_94 ] ) ,
F_43 ( & V_84 [ V_94 ] ) ) ;
F_42 ( V_82 , L_16 ,
F_43 ( & V_83 [ V_95 ] ) ,
F_43 ( & V_84 [ V_95 ] ) ) ;
F_42 ( V_82 , L_17 ,
F_43 ( & V_83 [ V_96 ] ) ,
F_43 ( & V_84 [ V_96 ] ) ) ;
F_42 ( V_82 , L_18 ,
F_43 ( & V_83 [ V_97 ] ) ,
F_43 ( & V_84 [ V_97 ] ) ) ;
F_42 ( V_82 , L_19 ,
F_43 ( & V_83 [ V_98 ] ) ,
F_43 ( & V_84 [ V_98 ] ) ) ;
F_42 ( V_82 , L_20 ,
F_43 ( & V_83 [ V_99 ] ) ,
F_43 ( & V_84 [ V_99 ] ) ) ;
F_42 ( V_82 , L_21 ,
F_43 ( & V_83 [ V_100 ] ) ,
F_43 ( & V_84 [ V_100 ] ) ) ;
F_42 ( V_82 , L_22 ,
F_43 ( & V_83 [ V_101 ] ) ,
F_43 ( & V_84 [ V_101 ] ) ) ;
F_42 ( V_82 , L_23 ,
F_43 ( & V_83 [ V_102 ] ) ,
F_43 ( & V_84 [ V_102 ] ) ) ;
F_42 ( V_82 , L_24 ,
F_43 ( & V_83 [ V_103 ] ) ,
F_43 ( & V_84 [ V_103 ] ) ) ;
#endif
}
static void
F_45 ( struct V_104 * V_105 , struct V_66 * V_67 , T_7 V_58 )
{
struct V_106 * V_107 = F_46 ( V_105 -> V_108 -> V_109 ) ;
V_105 -> V_67 . V_55 = V_67 -> V_55 ;
V_105 -> V_67 . V_56 = V_67 -> V_56 ;
F_47 ( V_107 , V_58 ) ;
V_107 -> V_110 = V_107 -> V_111 ;
}
static void
F_48 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 )
{
F_29 ( V_40 , V_46 , V_67 -> V_55 , V_67 -> V_56 ) ;
}
static int
F_49 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 )
{
return F_50 ( V_40 , V_46 , V_67 -> V_55 , V_67 -> V_56 ) ;
}
static unsigned int
F_51 ( char * V_28 )
{
struct V_112 * V_113 = (struct V_112 * ) V_28 ;
return V_113 -> V_114 ;
}
static unsigned int
F_52 ( char * V_28 )
{
struct V_112 * V_113 = (struct V_112 * ) V_28 ;
return F_53 ( V_113 -> V_115 ) ;
}
static int
F_54 ( const unsigned int V_40 , struct V_104 * V_105 ,
struct V_116 * V_117 , unsigned int * V_118 ,
char * * V_28 , int * V_119 )
{
V_117 -> V_55 = V_105 -> V_67 . V_55 ;
V_117 -> V_56 = V_105 -> V_67 . V_56 ;
return F_55 ( V_40 , V_117 , V_118 , V_28 , V_119 ) ;
}
static int
F_56 ( const unsigned int V_40 , struct V_104 * V_105 ,
struct V_116 * V_117 , unsigned int * V_120 ,
struct V_121 * V_122 , unsigned long V_123 )
{
V_117 -> V_55 = V_105 -> V_67 . V_55 ;
V_117 -> V_56 = V_105 -> V_67 . V_56 ;
return F_57 ( V_40 , V_117 , V_120 , V_122 , V_123 ) ;
}
static int
F_58 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_104 * V_105 , T_1 V_124 , bool V_125 )
{
T_8 V_126 = F_59 ( V_124 ) ;
return F_60 ( V_40 , V_46 , V_105 -> V_67 . V_55 ,
V_105 -> V_67 . V_56 , V_105 -> V_127 , & V_126 ) ;
}
static int
F_61 ( const unsigned int V_40 , struct V_45 * V_46 ,
const char * V_128 , struct V_52 * V_53 ,
struct V_66 * V_67 , T_9 V_129 ,
struct V_130 * V_131 )
{
T_2 * V_57 ;
int V_11 ;
T_3 V_58 = V_59 ;
T_1 V_55 , V_56 ;
V_57 = F_26 ( V_128 , V_53 ) ;
if ( ! V_57 )
return - V_60 ;
V_11 = F_27 ( V_40 , V_46 , V_57 , & V_55 , & V_56 ,
V_61 | V_132 , V_62 , 0 , 0 ,
& V_58 , NULL ) ;
F_28 ( V_57 ) ;
if ( V_11 ) {
F_2 ( 1 , L_25 ) ;
return V_11 ;
}
V_131 -> V_133 = 0 ;
V_131 -> V_134 = 0 ;
V_67 -> V_55 = V_55 ;
V_67 -> V_56 = V_56 ;
V_11 = F_62 ( V_40 , V_46 , V_55 , V_56 , 0 ,
V_131 ) ;
if ( V_11 ) {
F_2 ( 1 , L_26 ) ;
F_29 ( V_40 , V_46 , V_55 , V_56 ) ;
}
return V_11 ;
}
static int
F_63 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 , T_9 V_129 ,
struct V_130 * V_131 )
{
return F_62 ( V_40 , V_46 , V_67 -> V_55 ,
V_67 -> V_56 , 0 , V_131 ) ;
}
static int
F_64 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 )
{
return F_29 ( V_40 , V_46 , V_67 -> V_55 , V_67 -> V_56 ) ;
}
static bool
F_65 ( char * V_28 , struct V_1 * V_2 , int V_135 )
{
struct V_23 * V_29 = (struct V_23 * ) V_28 ;
if ( V_29 -> V_36 != V_136 )
return false ;
if ( ! V_135 ) {
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_3 += F_12 ( V_29 -> V_25 ) ;
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_18 ) ;
}
return true ;
}
static int
F_66 ( struct V_45 * V_46 , struct V_66 * V_67 ,
struct V_106 * V_107 )
{
if ( V_46 -> V_42 -> V_2 -> V_137 & V_138 )
return F_67 ( 0 , V_46 , V_107 -> V_139 ,
F_68 ( V_107 ) ) ;
return F_69 ( 0 , V_46 , V_67 -> V_55 ,
V_67 -> V_56 ,
V_107 -> V_140 ? 1 : 0 ) ;
}
static int
F_70 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_141 * V_28 )
{
int V_11 ;
T_4 V_55 , V_56 ;
T_2 V_142 = 0 ;
T_10 V_58 = V_59 ;
V_11 = F_27 ( V_40 , V_46 , & V_142 , & V_55 , & V_56 ,
V_61 , V_62 , 0 , 0 , & V_58 , NULL ) ;
if ( V_11 )
return V_11 ;
V_28 -> V_143 = V_144 ;
V_11 = F_71 ( V_40 , V_46 , V_55 , V_56 , V_28 ) ;
F_29 ( V_40 , V_46 , V_55 , V_56 ) ;
return V_11 ;
}
static bool
F_72 ( struct V_104 * V_145 , struct V_104 * V_146 )
{
return V_145 -> V_67 . V_55 == V_146 -> V_67 . V_55 &&
V_145 -> V_67 . V_56 == V_146 -> V_67 . V_56 ;
}
static int
F_73 ( const unsigned int V_40 , struct V_104 * V_105 , T_1 V_147 ,
T_1 V_135 , T_7 type , int V_148 , int V_149 , bool V_150 )
{
if ( V_149 && ! V_148 )
type = V_151 ;
return F_74 ( V_40 , F_75 ( V_105 -> V_152 ) ,
V_105 -> V_67 . V_55 , V_105 -> V_67 . V_56 ,
V_153 -> V_154 , V_135 , V_147 , type , V_150 ) ;
}
static void
F_76 ( struct V_155 * V_155 , struct V_66 * V_67 )
{
memcpy ( V_67 -> V_139 , F_46 ( V_155 ) -> V_139 , V_156 ) ;
}
static void
F_77 ( struct V_155 * V_155 , struct V_66 * V_67 )
{
memcpy ( F_46 ( V_155 ) -> V_139 , V_67 -> V_139 , V_156 ) ;
}
static void
F_78 ( struct V_66 * V_67 )
{
F_79 ( V_67 -> V_139 , V_156 ) ;
}
