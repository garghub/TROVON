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
static bool
F_36 ( struct V_1 * V_2 )
{
return V_2 -> V_6 ;
}
static void
F_37 ( struct V_45 * V_46 )
{
#ifdef F_38
int V_72 ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
F_39 ( & V_46 -> V_74 . V_75 . V_76 [ V_72 ] , 0 ) ;
F_39 ( & V_46 -> V_74 . V_75 . V_77 [ V_72 ] , 0 ) ;
}
#endif
}
static void
F_40 ( struct V_78 * V_79 , struct V_45 * V_46 )
{
#ifdef F_38
T_6 * V_80 = V_46 -> V_74 . V_75 . V_76 ;
T_6 * V_81 = V_46 -> V_74 . V_75 . V_77 ;
F_41 ( V_79 , L_5 ,
F_42 ( & V_80 [ V_82 ] ) ,
F_42 ( & V_81 [ V_82 ] ) ) ;
F_41 ( V_79 , L_6 ,
F_42 ( & V_80 [ V_83 ] ) ,
F_42 ( & V_81 [ V_83 ] ) ) ;
#define F_43 0x0002
F_41 ( V_79 , L_7 ,
F_42 ( & V_80 [ V_84 ] ) ,
F_42 ( & V_81 [ V_84 ] ) ) ;
F_41 ( V_79 , L_8 ,
F_42 ( & V_80 [ V_85 ] ) ,
F_42 ( & V_81 [ V_85 ] ) ) ;
F_41 ( V_79 , L_9 ,
F_42 ( & V_80 [ V_86 ] ) ,
F_42 ( & V_81 [ V_86 ] ) ) ;
F_41 ( V_79 , L_10 ,
F_42 ( & V_80 [ V_87 ] ) ,
F_42 ( & V_81 [ V_87 ] ) ) ;
F_41 ( V_79 , L_11 ,
F_42 ( & V_80 [ V_88 ] ) ,
F_42 ( & V_81 [ V_88 ] ) ) ;
F_41 ( V_79 , L_12 ,
F_42 ( & V_80 [ V_89 ] ) ,
F_42 ( & V_81 [ V_89 ] ) ) ;
F_41 ( V_79 , L_13 ,
F_42 ( & V_80 [ V_90 ] ) ,
F_42 ( & V_81 [ V_90 ] ) ) ;
F_41 ( V_79 , L_14 ,
F_42 ( & V_80 [ V_91 ] ) ,
F_42 ( & V_81 [ V_91 ] ) ) ;
F_41 ( V_79 , L_15 ,
F_42 ( & V_80 [ V_92 ] ) ,
F_42 ( & V_81 [ V_92 ] ) ) ;
F_41 ( V_79 , L_16 ,
F_42 ( & V_80 [ V_93 ] ) ,
F_42 ( & V_81 [ V_93 ] ) ) ;
F_41 ( V_79 , L_17 ,
F_42 ( & V_80 [ V_94 ] ) ,
F_42 ( & V_81 [ V_94 ] ) ) ;
F_41 ( V_79 , L_18 ,
F_42 ( & V_80 [ V_95 ] ) ,
F_42 ( & V_81 [ V_95 ] ) ) ;
F_41 ( V_79 , L_19 ,
F_42 ( & V_80 [ V_96 ] ) ,
F_42 ( & V_81 [ V_96 ] ) ) ;
F_41 ( V_79 , L_20 ,
F_42 ( & V_80 [ V_97 ] ) ,
F_42 ( & V_81 [ V_97 ] ) ) ;
F_41 ( V_79 , L_21 ,
F_42 ( & V_80 [ V_98 ] ) ,
F_42 ( & V_81 [ V_98 ] ) ) ;
F_41 ( V_79 , L_22 ,
F_42 ( & V_80 [ V_99 ] ) ,
F_42 ( & V_81 [ V_99 ] ) ) ;
F_41 ( V_79 , L_23 ,
F_42 ( & V_80 [ V_100 ] ) ,
F_42 ( & V_81 [ V_100 ] ) ) ;
#endif
}
static void
F_44 ( struct V_101 * V_102 , struct V_66 * V_67 , T_7 V_58 )
{
struct V_103 * V_104 = F_45 ( V_102 -> V_105 -> V_106 ) ;
V_102 -> V_67 . V_55 = V_67 -> V_55 ;
V_102 -> V_67 . V_56 = V_67 -> V_56 ;
F_46 ( V_104 , V_58 ) ;
V_104 -> V_107 = V_104 -> V_108 ;
}
static void
F_47 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 )
{
F_29 ( V_40 , V_46 , V_67 -> V_55 , V_67 -> V_56 ) ;
}
static int
F_48 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 )
{
return F_49 ( V_40 , V_46 , V_67 -> V_55 , V_67 -> V_56 ) ;
}
static unsigned int
F_50 ( char * V_28 )
{
struct V_109 * V_110 = (struct V_109 * ) V_28 ;
return V_110 -> V_111 ;
}
static unsigned int
F_51 ( char * V_28 )
{
struct V_109 * V_110 = (struct V_109 * ) V_28 ;
return F_52 ( V_110 -> V_112 ) ;
}
static int
F_53 ( const unsigned int V_40 , struct V_101 * V_102 ,
struct V_113 * V_114 , unsigned int * V_115 ,
char * * V_28 , int * V_116 )
{
V_114 -> V_55 = V_102 -> V_67 . V_55 ;
V_114 -> V_56 = V_102 -> V_67 . V_56 ;
return F_54 ( V_40 , V_114 , V_115 , V_28 , V_116 ) ;
}
static int
F_55 ( const unsigned int V_40 , struct V_101 * V_102 ,
struct V_113 * V_114 , unsigned int * V_117 ,
struct V_118 * V_119 , unsigned long V_120 )
{
V_114 -> V_55 = V_102 -> V_67 . V_55 ;
V_114 -> V_56 = V_102 -> V_67 . V_56 ;
return F_56 ( V_40 , V_114 , V_117 , V_119 , V_120 ) ;
}
static int
F_57 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_101 * V_102 , T_1 V_121 , bool V_122 )
{
T_8 V_123 = F_58 ( V_121 ) ;
return F_59 ( V_40 , V_46 , V_102 -> V_67 . V_55 ,
V_102 -> V_67 . V_56 , V_102 -> V_124 , & V_123 ) ;
}
static int
F_60 ( const unsigned int V_40 , struct V_45 * V_46 ,
const char * V_125 , struct V_52 * V_53 ,
struct V_66 * V_67 , T_9 V_126 ,
struct V_127 * V_128 )
{
T_2 * V_57 ;
int V_11 ;
T_3 V_58 = V_59 ;
T_1 V_55 , V_56 ;
V_57 = F_26 ( V_125 , V_53 ) ;
if ( ! V_57 )
return - V_60 ;
V_11 = F_27 ( V_40 , V_46 , V_57 , & V_55 , & V_56 ,
V_61 | V_129 , V_62 , 0 , 0 ,
& V_58 , NULL ) ;
F_28 ( V_57 ) ;
if ( V_11 ) {
F_2 ( 1 , L_24 ) ;
return V_11 ;
}
V_128 -> V_130 = 0 ;
V_128 -> V_131 = 0 ;
V_67 -> V_55 = V_55 ;
V_67 -> V_56 = V_56 ;
V_11 = F_61 ( V_40 , V_46 , V_55 , V_56 , 0 ,
V_128 ) ;
if ( V_11 ) {
F_2 ( 1 , L_25 ) ;
F_29 ( V_40 , V_46 , V_55 , V_56 ) ;
}
return V_11 ;
}
static int
F_62 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 , T_9 V_126 ,
struct V_127 * V_128 )
{
return F_61 ( V_40 , V_46 , V_67 -> V_55 ,
V_67 -> V_56 , 0 , V_128 ) ;
}
static int
F_63 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_66 * V_67 )
{
return F_29 ( V_40 , V_46 , V_67 -> V_55 , V_67 -> V_56 ) ;
}
static bool
F_64 ( char * V_28 , struct V_1 * V_2 , int V_132 )
{
struct V_23 * V_29 = (struct V_23 * ) V_28 ;
if ( V_29 -> V_36 != V_133 )
return false ;
if ( ! V_132 ) {
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_3 += F_12 ( V_29 -> V_25 ) ;
F_6 ( & V_2 -> V_12 ) ;
F_7 ( & V_2 -> V_18 ) ;
}
return true ;
}
static int
F_65 ( struct V_45 * V_46 , struct V_66 * V_67 ,
struct V_103 * V_104 )
{
if ( V_46 -> V_42 -> V_2 -> V_134 & V_135 )
return F_66 ( 0 , V_46 , V_104 -> V_136 ,
F_67 ( V_104 ) ) ;
return F_68 ( 0 , V_46 , V_67 -> V_55 ,
V_67 -> V_56 ,
V_104 -> V_137 ? 1 : 0 ) ;
}
static int
F_69 ( const unsigned int V_40 , struct V_45 * V_46 ,
struct V_138 * V_28 )
{
int V_11 ;
T_4 V_55 , V_56 ;
T_2 V_139 = 0 ;
T_10 V_58 = V_59 ;
V_11 = F_27 ( V_40 , V_46 , & V_139 , & V_55 , & V_56 ,
V_61 , V_62 , 0 , 0 , & V_58 , NULL ) ;
if ( V_11 )
return V_11 ;
V_28 -> V_140 = V_141 ;
V_11 = F_70 ( V_40 , V_46 , V_55 , V_56 , V_28 ) ;
F_29 ( V_40 , V_46 , V_55 , V_56 ) ;
return V_11 ;
}
static bool
F_71 ( struct V_101 * V_142 , struct V_101 * V_143 )
{
return V_142 -> V_67 . V_55 == V_143 -> V_67 . V_55 &&
V_142 -> V_67 . V_56 == V_143 -> V_67 . V_56 ;
}
static int
F_72 ( const unsigned int V_40 , struct V_101 * V_102 , T_1 V_144 ,
T_1 V_132 , T_7 type , int V_145 , int V_146 , bool V_147 )
{
if ( V_146 && ! V_145 )
type = V_148 ;
return F_73 ( V_40 , F_74 ( V_102 -> V_149 ) ,
V_102 -> V_67 . V_55 , V_102 -> V_67 . V_56 ,
V_150 -> V_151 , V_132 , V_144 , type , V_147 ) ;
}
static void
F_75 ( struct V_152 * V_152 , struct V_66 * V_67 )
{
memcpy ( V_67 -> V_136 , F_45 ( V_152 ) -> V_136 , V_153 ) ;
}
static void
F_76 ( struct V_152 * V_152 , struct V_66 * V_67 )
{
memcpy ( F_45 ( V_152 ) -> V_136 , V_67 -> V_136 , V_153 ) ;
}
static void
F_77 ( struct V_66 * V_67 )
{
F_78 ( V_67 -> V_136 , V_153 ) ;
}
