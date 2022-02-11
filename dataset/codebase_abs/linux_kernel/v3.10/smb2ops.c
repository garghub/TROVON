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
F_2 ( V_8 , L_1 ) ;
break;
case 2 :
V_2 -> V_6 = true ;
V_2 -> V_7 = false ;
V_2 -> V_4 = 1 ;
F_2 ( V_9 , L_2 ) ;
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
F_3 ( struct V_1 * V_2 , const unsigned int V_10 ,
const int V_11 )
{
int * V_12 , V_13 = 0 ;
F_4 ( & V_2 -> V_14 ) ;
V_12 = V_2 -> V_15 -> V_16 ( V_2 , V_11 ) ;
* V_12 += V_10 ;
V_2 -> V_17 -- ;
if ( V_2 -> V_17 == 0 && ( V_11 & V_18 ) != V_19 )
V_13 = F_1 ( V_2 ) ;
else if ( V_2 -> V_17 > 0 && V_2 -> V_5 == 0 &&
V_2 -> V_7 ) {
if ( V_2 -> V_3 > 1 ) {
V_2 -> V_3 -- ;
V_2 -> V_5 ++ ;
}
}
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
if ( V_13 )
F_7 ( V_2 ) ;
}
static void
F_8 ( struct V_1 * V_2 , const int V_12 )
{
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 = V_12 ;
F_5 ( & V_2 -> V_14 ) ;
}
static int *
F_9 ( struct V_1 * V_2 , const int V_11 )
{
switch ( V_11 ) {
case V_21 :
return & V_2 -> V_4 ;
case V_22 :
return & V_2 -> V_5 ;
default:
return & V_2 -> V_3 ;
}
}
static unsigned int
F_10 ( struct V_23 * V_24 )
{
return F_11 ( ( (struct V_25 * ) V_24 -> V_26 ) -> V_27 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 )
{
T_1 V_24 ;
F_4 ( & V_28 ) ;
V_24 = V_2 -> V_29 ++ ;
F_5 ( & V_28 ) ;
return V_24 ;
}
static struct V_23 *
F_13 ( struct V_1 * V_2 , char * V_30 )
{
struct V_23 * V_24 ;
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
F_4 ( & V_28 ) ;
F_14 (mid, &server->pending_mid_q, qhead) {
if ( ( V_24 -> V_24 == V_31 -> V_32 ) &&
( V_24 -> V_33 == V_34 ) &&
( V_24 -> V_35 == V_31 -> V_36 ) ) {
F_5 ( & V_28 ) ;
return V_24 ;
}
}
F_5 ( & V_28 ) ;
return NULL ;
}
static void
F_15 ( void * V_30 )
{
#ifdef F_16
struct V_25 * V_37 = (struct V_25 * ) V_30 ;
F_2 ( V_8 , L_3 ,
V_37 -> V_36 , V_37 -> V_38 , V_37 -> V_39 , V_37 -> V_32 ,
V_37 -> V_40 ) ;
F_2 ( V_8 , L_4 , V_37 , F_17 ( V_37 ) ) ;
#endif
}
static bool
F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_41 == 0 ;
}
static int
F_19 ( const unsigned int V_42 , struct V_43 * V_44 )
{
int V_13 ;
V_44 -> V_2 -> V_29 = 0 ;
V_13 = F_20 ( V_42 , V_44 ) ;
if ( V_13 == - V_45 )
V_13 = - V_46 ;
return V_13 ;
}
static unsigned int
F_21 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_51 ;
V_51 = V_50 -> V_51 ? V_50 -> V_51 : V_52 ;
V_51 = F_22 (unsigned int, wsize, server->max_write) ;
V_51 = F_22 (unsigned int, wsize, 2 << 15 ) ;
return V_51 ;
}
static unsigned int
F_23 ( struct V_47 * V_48 , struct V_49 * V_50 )
{
struct V_1 * V_2 = V_48 -> V_44 -> V_2 ;
unsigned int V_53 ;
V_53 = V_50 -> V_53 ? V_50 -> V_53 : V_52 ;
V_53 = F_22 (unsigned int, rsize, server->max_read) ;
V_53 = F_22 (unsigned int, rsize, 2 << 15 ) ;
return V_53 ;
}
static int
F_24 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_54 * V_55 , const char * V_56 )
{
int V_13 ;
T_1 V_57 , V_58 ;
T_2 * V_59 ;
T_3 V_60 = V_61 ;
V_59 = F_25 ( V_56 , V_55 ) ;
if ( ! V_59 )
return - V_62 ;
V_13 = F_26 ( V_42 , V_48 , V_59 , & V_57 , & V_58 ,
V_63 , V_64 , 0 , 0 , & V_60 , NULL ) ;
if ( V_13 ) {
F_27 ( V_59 ) ;
return V_13 ;
}
V_13 = F_28 ( V_42 , V_48 , V_57 , V_58 ) ;
F_27 ( V_59 ) ;
return V_13 ;
}
static int
F_29 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_54 * V_55 , const char * V_56 ,
T_4 * V_65 , T_5 * V_66 )
{
* V_65 = F_30 ( V_66 -> V_67 ) ;
return 0 ;
}
static int
F_31 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_68 * V_69 , T_5 * V_66 )
{
int V_13 ;
struct V_70 * V_71 ;
V_71 = F_32 ( sizeof( struct V_70 ) + V_72 * 2 ,
V_73 ) ;
if ( V_71 == NULL )
return - V_62 ;
V_13 = F_33 ( V_42 , V_48 , V_69 -> V_57 , V_69 -> V_58 ,
V_71 ) ;
if ( ! V_13 )
F_34 ( V_66 , V_71 ) ;
F_27 ( V_71 ) ;
return V_13 ;
}
static bool
F_35 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_36 ( struct V_47 * V_48 )
{
#ifdef F_37
int V_74 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ ) {
F_38 ( & V_48 -> V_76 . V_77 . V_78 [ V_74 ] , 0 ) ;
F_38 ( & V_48 -> V_76 . V_77 . V_79 [ V_74 ] , 0 ) ;
}
#endif
}
static void
F_39 ( struct V_80 * V_81 , struct V_47 * V_48 )
{
#ifdef F_37
T_6 * V_82 = V_48 -> V_76 . V_77 . V_78 ;
T_6 * V_83 = V_48 -> V_76 . V_77 . V_79 ;
F_40 ( V_81 , L_5 ,
F_41 ( & V_82 [ V_84 ] ) ,
F_41 ( & V_83 [ V_84 ] ) ) ;
F_40 ( V_81 , L_6 ,
F_41 ( & V_82 [ V_85 ] ) ,
F_41 ( & V_83 [ V_85 ] ) ) ;
#define F_42 0x0002
F_40 ( V_81 , L_7 ,
F_41 ( & V_82 [ V_86 ] ) ,
F_41 ( & V_83 [ V_86 ] ) ) ;
F_40 ( V_81 , L_8 ,
F_41 ( & V_82 [ V_87 ] ) ,
F_41 ( & V_83 [ V_87 ] ) ) ;
F_40 ( V_81 , L_9 ,
F_41 ( & V_82 [ V_88 ] ) ,
F_41 ( & V_83 [ V_88 ] ) ) ;
F_40 ( V_81 , L_10 ,
F_41 ( & V_82 [ V_89 ] ) ,
F_41 ( & V_83 [ V_89 ] ) ) ;
F_40 ( V_81 , L_11 ,
F_41 ( & V_82 [ V_90 ] ) ,
F_41 ( & V_83 [ V_90 ] ) ) ;
F_40 ( V_81 , L_12 ,
F_41 ( & V_82 [ V_91 ] ) ,
F_41 ( & V_83 [ V_91 ] ) ) ;
F_40 ( V_81 , L_13 ,
F_41 ( & V_82 [ V_92 ] ) ,
F_41 ( & V_83 [ V_92 ] ) ) ;
F_40 ( V_81 , L_14 ,
F_41 ( & V_82 [ V_93 ] ) ,
F_41 ( & V_83 [ V_93 ] ) ) ;
F_40 ( V_81 , L_15 ,
F_41 ( & V_82 [ V_94 ] ) ,
F_41 ( & V_83 [ V_94 ] ) ) ;
F_40 ( V_81 , L_16 ,
F_41 ( & V_82 [ V_95 ] ) ,
F_41 ( & V_83 [ V_95 ] ) ) ;
F_40 ( V_81 , L_17 ,
F_41 ( & V_82 [ V_96 ] ) ,
F_41 ( & V_83 [ V_96 ] ) ) ;
F_40 ( V_81 , L_18 ,
F_41 ( & V_82 [ V_97 ] ) ,
F_41 ( & V_83 [ V_97 ] ) ) ;
F_40 ( V_81 , L_19 ,
F_41 ( & V_82 [ V_98 ] ) ,
F_41 ( & V_83 [ V_98 ] ) ) ;
F_40 ( V_81 , L_20 ,
F_41 ( & V_82 [ V_99 ] ) ,
F_41 ( & V_83 [ V_99 ] ) ) ;
F_40 ( V_81 , L_21 ,
F_41 ( & V_82 [ V_100 ] ) ,
F_41 ( & V_83 [ V_100 ] ) ) ;
F_40 ( V_81 , L_22 ,
F_41 ( & V_82 [ V_101 ] ) ,
F_41 ( & V_83 [ V_101 ] ) ) ;
F_40 ( V_81 , L_23 ,
F_41 ( & V_82 [ V_102 ] ) ,
F_41 ( & V_83 [ V_102 ] ) ) ;
#endif
}
static void
F_43 ( struct V_103 * V_104 , struct V_68 * V_69 , T_7 V_60 )
{
struct V_105 * V_106 = F_44 ( V_104 -> V_107 -> V_108 ) ;
V_104 -> V_69 . V_57 = V_69 -> V_57 ;
V_104 -> V_69 . V_58 = V_69 -> V_58 ;
F_45 ( V_106 , V_60 ) ;
V_106 -> V_109 = V_106 -> V_110 ;
}
static void
F_46 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_68 * V_69 )
{
F_28 ( V_42 , V_48 , V_69 -> V_57 , V_69 -> V_58 ) ;
}
static int
F_47 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_68 * V_69 )
{
return F_48 ( V_42 , V_48 , V_69 -> V_57 , V_69 -> V_58 ) ;
}
static unsigned int
F_49 ( char * V_30 )
{
struct V_111 * V_112 = (struct V_111 * ) V_30 ;
return V_112 -> V_113 ;
}
static unsigned int
F_50 ( char * V_30 )
{
struct V_111 * V_112 = (struct V_111 * ) V_30 ;
return F_51 ( V_112 -> V_114 ) ;
}
static int
F_52 ( const unsigned int V_42 , struct V_103 * V_104 ,
struct V_115 * V_116 , unsigned int * V_117 ,
char * * V_30 , int * V_118 )
{
V_116 -> V_57 = V_104 -> V_69 . V_57 ;
V_116 -> V_58 = V_104 -> V_69 . V_58 ;
return F_53 ( V_42 , V_116 , V_117 , V_30 , V_118 ) ;
}
static int
F_54 ( const unsigned int V_42 , struct V_103 * V_104 ,
struct V_115 * V_116 , unsigned int * V_119 ,
struct V_120 * V_121 , unsigned long V_122 )
{
V_116 -> V_57 = V_104 -> V_69 . V_57 ;
V_116 -> V_58 = V_104 -> V_69 . V_58 ;
return F_55 ( V_42 , V_116 , V_119 , V_121 , V_122 ) ;
}
static int
F_56 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_103 * V_104 , T_1 V_123 , bool V_124 )
{
T_8 V_125 = F_57 ( V_123 ) ;
return F_58 ( V_42 , V_48 , V_104 -> V_69 . V_57 ,
V_104 -> V_69 . V_58 , V_104 -> V_126 , & V_125 ) ;
}
static int
F_59 ( const unsigned int V_42 , struct V_47 * V_48 ,
const char * V_127 , struct V_54 * V_55 ,
struct V_68 * V_69 , T_9 V_128 ,
struct V_129 * V_130 )
{
T_2 * V_59 ;
int V_13 ;
T_3 V_60 = V_61 ;
T_1 V_57 , V_58 ;
V_59 = F_25 ( V_127 , V_55 ) ;
if ( ! V_59 )
return - V_62 ;
V_13 = F_26 ( V_42 , V_48 , V_59 , & V_57 , & V_58 ,
V_63 | V_131 , V_64 , 0 , 0 ,
& V_60 , NULL ) ;
F_27 ( V_59 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_24 ) ;
return V_13 ;
}
V_130 -> V_132 = 0 ;
V_130 -> V_133 = 0 ;
V_69 -> V_57 = V_57 ;
V_69 -> V_58 = V_58 ;
V_13 = F_60 ( V_42 , V_48 , V_57 , V_58 , 0 ,
V_130 ) ;
if ( V_13 ) {
F_2 ( V_8 , L_25 ) ;
F_28 ( V_42 , V_48 , V_57 , V_58 ) ;
}
return V_13 ;
}
static int
F_61 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_68 * V_69 , T_9 V_128 ,
struct V_129 * V_130 )
{
return F_60 ( V_42 , V_48 , V_69 -> V_57 ,
V_69 -> V_58 , 0 , V_130 ) ;
}
static int
F_62 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_68 * V_69 )
{
return F_28 ( V_42 , V_48 , V_69 -> V_57 , V_69 -> V_58 ) ;
}
static bool
F_63 ( char * V_30 , struct V_1 * V_2 , int V_134 )
{
struct V_25 * V_31 = (struct V_25 * ) V_30 ;
if ( V_31 -> V_38 != V_135 )
return false ;
if ( ! V_134 ) {
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_3 += F_11 ( V_31 -> V_27 ) ;
F_5 ( & V_2 -> V_14 ) ;
F_6 ( & V_2 -> V_20 ) ;
}
return true ;
}
static int
F_64 ( struct V_47 * V_48 , struct V_68 * V_69 ,
struct V_105 * V_106 )
{
if ( V_48 -> V_44 -> V_2 -> V_136 & V_137 )
return F_65 ( 0 , V_48 , V_106 -> V_138 ,
F_66 ( V_106 ) ) ;
return F_67 ( 0 , V_48 , V_69 -> V_57 ,
V_69 -> V_58 ,
V_106 -> V_139 ? 1 : 0 ) ;
}
static int
F_68 ( const unsigned int V_42 , struct V_47 * V_48 ,
struct V_140 * V_30 )
{
int V_13 ;
T_4 V_57 , V_58 ;
T_2 V_141 = 0 ;
T_10 V_60 = V_61 ;
V_13 = F_26 ( V_42 , V_48 , & V_141 , & V_57 , & V_58 ,
V_63 , V_64 , 0 , 0 , & V_60 , NULL ) ;
if ( V_13 )
return V_13 ;
V_30 -> V_142 = V_143 ;
V_13 = F_69 ( V_42 , V_48 , V_57 , V_58 , V_30 ) ;
F_28 ( V_42 , V_48 , V_57 , V_58 ) ;
return V_13 ;
}
static bool
F_70 ( struct V_103 * V_144 , struct V_103 * V_145 )
{
return V_144 -> V_69 . V_57 == V_145 -> V_69 . V_57 &&
V_144 -> V_69 . V_58 == V_145 -> V_69 . V_58 ;
}
static int
F_71 ( const unsigned int V_42 , struct V_103 * V_104 , T_1 V_146 ,
T_1 V_134 , T_7 type , int V_147 , int V_148 , bool V_149 )
{
if ( V_148 && ! V_147 )
type = V_150 ;
return F_72 ( V_42 , F_73 ( V_104 -> V_151 ) ,
V_104 -> V_69 . V_57 , V_104 -> V_69 . V_58 ,
V_152 -> V_153 , V_134 , V_146 , type , V_149 ) ;
}
static void
F_74 ( struct V_154 * V_154 , struct V_68 * V_69 )
{
memcpy ( V_69 -> V_138 , F_44 ( V_154 ) -> V_138 , V_155 ) ;
}
static void
F_75 ( struct V_154 * V_154 , struct V_68 * V_69 )
{
memcpy ( F_44 ( V_154 ) -> V_138 , V_69 -> V_138 , V_155 ) ;
}
static void
F_76 ( struct V_68 * V_69 )
{
F_77 ( V_69 -> V_138 , V_155 ) ;
}
