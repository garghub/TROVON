static T_1 F_1 ( const unsigned char * V_1 )
{
T_2 V_2 = F_2 ( ( T_2 * ) V_1 ) ;
#ifdef F_3
V_2 >>= 16 ;
#else
V_2 <<= 16 ;
#endif
return F_4 ( V_2 , V_3 ) ;
}
static struct V_4 * F_5 ( const struct V_5 * V_6 )
{
return F_6 ( V_6 -> V_7 ) ;
}
static struct V_4 * F_7 ( const struct V_5 * V_6 )
{
return F_8 ( V_6 -> V_7 ) ;
}
static struct V_8 * F_9 ( const struct V_4 * V_9 ,
const unsigned char * V_1 )
{
struct V_8 * V_10 ;
T_1 V_11 = F_1 ( V_1 ) ;
F_10 (vlan, &port->vlan_hash[idx], hlist) {
if ( F_11 ( V_10 -> V_6 -> V_12 , V_1 ) )
return V_10 ;
}
return NULL ;
}
static struct V_13 * F_12 (
const struct V_8 * V_10 ,
const unsigned char * V_1 )
{
struct V_13 * V_14 ;
T_1 V_11 = F_1 ( V_1 ) ;
struct V_15 * V_16 = & V_10 -> V_9 -> V_17 [ V_11 ] ;
F_10 (entry, h, hlist) {
if ( F_11 ( V_14 -> V_1 , V_1 ) &&
V_14 -> V_10 == V_10 )
return V_14 ;
}
return NULL ;
}
static int F_13 ( struct V_8 * V_10 ,
const unsigned char * V_1 )
{
struct V_4 * V_9 = V_10 -> V_9 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
V_14 = F_12 ( V_10 , V_1 ) ;
if ( V_14 )
return 0 ;
V_14 = F_14 ( sizeof( * V_14 ) , V_18 ) ;
if ( ! V_14 )
return - V_19 ;
F_15 ( V_14 -> V_1 , V_1 ) ;
V_14 -> V_10 = V_10 ;
V_16 = & V_9 -> V_17 [ F_1 ( V_1 ) ] ;
F_16 ( & V_14 -> V_20 , V_16 ) ;
V_10 -> V_21 ++ ;
return 0 ;
}
static void F_17 ( struct V_8 * V_10 )
{
struct V_4 * V_9 = V_10 -> V_9 ;
const unsigned char * V_1 = V_10 -> V_6 -> V_12 ;
T_1 V_11 = F_1 ( V_1 ) ;
F_16 ( & V_10 -> V_20 , & V_9 -> V_22 [ V_11 ] ) ;
}
static void F_18 ( struct V_13 * V_14 )
{
F_19 ( & V_14 -> V_20 ) ;
F_20 ( V_14 , V_23 ) ;
}
static void F_21 ( struct V_8 * V_10 , bool V_24 )
{
F_19 ( & V_10 -> V_20 ) ;
if ( V_24 )
F_22 () ;
}
static void F_23 ( struct V_8 * V_10 ,
const unsigned char * V_1 )
{
F_21 ( V_10 , true ) ;
memcpy ( V_10 -> V_6 -> V_12 , V_1 , V_25 ) ;
F_17 ( V_10 ) ;
}
static bool F_24 ( const struct V_4 * V_9 ,
const unsigned char * V_1 )
{
if ( F_11 ( V_9 -> V_6 -> V_12 , V_1 ) )
return true ;
if ( F_9 ( V_9 , V_1 ) )
return true ;
return false ;
}
static int F_25 ( struct V_26 * V_27 ,
const struct V_8 * V_10 ,
const struct V_28 * V_29 , bool V_30 )
{
struct V_5 * V_6 = V_10 -> V_6 ;
if ( V_30 )
return F_26 ( V_6 , V_27 ) ;
V_27 -> V_6 = V_6 ;
if ( F_11 ( V_29 -> V_31 , V_6 -> V_32 ) )
V_27 -> V_33 = V_34 ;
else
V_27 -> V_33 = V_35 ;
return 0 ;
}
static T_1 F_27 ( const struct V_8 * V_10 )
{
return ( T_1 ) ( ( ( unsigned long ) V_10 ) >> V_36 ) ;
}
static unsigned int F_28 ( const struct V_8 * V_10 ,
const unsigned char * V_1 )
{
T_1 V_37 = F_29 ( V_1 + 2 ) ;
V_37 ^= F_27 ( V_10 ) ;
return F_30 ( V_37 , V_38 ) ;
}
static void F_31 ( struct V_26 * V_27 ,
const struct V_4 * V_9 ,
struct V_5 * V_39 ,
enum V_40 V_41 )
{
const struct V_28 * V_29 = F_32 ( V_27 ) ;
const struct V_8 * V_10 ;
struct V_26 * V_42 ;
unsigned int V_43 ;
int V_44 ;
unsigned int V_45 ;
if ( V_27 -> V_46 == F_33 ( V_47 ) )
return;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
F_10 (vlan, &port->vlan_hash[i], hlist) {
if ( V_10 -> V_6 == V_39 || ! ( V_10 -> V_41 & V_41 ) )
continue;
V_45 = F_28 ( V_10 , V_29 -> V_31 ) ;
if ( ! F_34 ( V_45 , V_10 -> V_49 ) )
continue;
V_44 = V_50 ;
V_42 = F_35 ( V_27 , V_51 ) ;
if ( F_36 ( V_42 ) )
V_44 = F_25 (
V_42 , V_10 , V_29 ,
V_41 == V_52 ) ? :
F_37 ( V_42 ) ;
F_38 ( V_10 , V_27 -> V_53 + V_54 ,
V_44 == V_55 , true ) ;
}
}
}
static void F_39 ( struct V_56 * V_57 )
{
struct V_4 * V_9 = F_40 ( V_57 , struct V_4 ,
V_58 ) ;
struct V_26 * V_27 ;
struct V_59 V_60 ;
F_41 ( & V_60 ) ;
F_42 ( & V_9 -> V_61 . V_62 ) ;
F_43 ( & V_9 -> V_61 , & V_60 ) ;
F_44 ( & V_9 -> V_61 . V_62 ) ;
while ( ( V_27 = F_45 ( & V_60 ) ) ) {
const struct V_8 * V_39 = F_46 ( V_27 ) -> V_39 ;
F_47 () ;
if ( ! V_39 )
F_31 ( V_27 , V_9 , NULL ,
V_63 |
V_64 |
V_65 |
V_52 ) ;
else if ( V_39 -> V_41 == V_64 )
F_31 ( V_27 , V_9 , V_39 -> V_6 ,
V_64 |
V_52 ) ;
else
F_31 ( V_27 , V_9 , V_39 -> V_6 ,
V_64 ) ;
F_48 () ;
if ( V_39 )
F_49 ( V_39 -> V_6 ) ;
F_50 ( V_27 ) ;
}
}
static void F_51 ( struct V_4 * V_9 ,
const struct V_8 * V_39 ,
struct V_26 * V_27 )
{
struct V_26 * V_42 ;
int V_44 = - V_19 ;
V_42 = F_35 ( V_27 , V_51 ) ;
if ( ! V_42 )
goto V_44;
F_46 ( V_42 ) -> V_39 = V_39 ;
F_52 ( & V_9 -> V_61 . V_62 ) ;
if ( F_53 ( & V_9 -> V_61 ) < V_66 ) {
if ( V_39 )
F_54 ( V_39 -> V_6 ) ;
F_55 ( & V_9 -> V_61 , V_42 ) ;
V_44 = 0 ;
}
F_56 ( & V_9 -> V_61 . V_62 ) ;
if ( V_44 )
goto V_67;
F_57 ( & V_9 -> V_58 ) ;
return;
V_67:
F_50 ( V_42 ) ;
V_44:
F_58 ( & V_27 -> V_6 -> V_68 ) ;
}
static void F_59 ( struct V_4 * V_9 ,
struct V_8 * V_10 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
struct V_69 * V_16 , * V_70 ;
F_60 (h, n, &port->vlan_source_hash[i]) {
struct V_13 * V_14 ;
V_14 = F_61 ( V_16 , struct V_13 ,
V_20 ) ;
if ( V_14 -> V_10 == V_10 )
F_18 ( V_14 ) ;
}
}
V_10 -> V_21 = 0 ;
}
static void F_62 ( struct V_26 * V_27 ,
struct V_8 * V_10 )
{
struct V_26 * V_42 ;
struct V_5 * V_6 ;
int V_53 ;
int V_71 ;
V_6 = V_10 -> V_6 ;
if ( F_63 ( ! ( V_6 -> V_72 & V_73 ) ) )
return;
V_42 = F_35 ( V_27 , V_51 ) ;
if ( ! V_42 )
return;
V_53 = V_42 -> V_53 + V_54 ;
V_42 -> V_6 = V_6 ;
V_42 -> V_33 = V_74 ;
V_71 = F_64 ( V_42 ) ;
F_38 ( V_10 , V_53 , V_71 == V_55 , false ) ;
}
static void F_65 ( struct V_26 * V_27 ,
struct V_4 * V_9 ,
const unsigned char * V_1 )
{
struct V_13 * V_14 ;
T_1 V_11 = F_1 ( V_1 ) ;
struct V_15 * V_16 = & V_9 -> V_17 [ V_11 ] ;
F_10 (entry, h, hlist) {
if ( F_11 ( V_14 -> V_1 , V_1 ) )
F_62 ( V_27 , V_14 -> V_10 ) ;
}
}
static T_3 F_66 ( struct V_26 * * V_75 )
{
struct V_4 * V_9 ;
struct V_26 * V_27 = * V_75 ;
const struct V_28 * V_29 = F_32 ( V_27 ) ;
const struct V_8 * V_10 ;
const struct V_8 * V_39 ;
struct V_5 * V_6 ;
unsigned int V_53 = 0 ;
int V_71 ;
T_3 V_76 ;
V_9 = F_5 ( V_27 -> V_6 ) ;
if ( F_67 ( V_29 -> V_31 ) ) {
unsigned int V_45 ;
V_27 = F_68 ( F_69 ( V_27 -> V_6 ) , V_27 , V_77 ) ;
if ( ! V_27 )
return V_78 ;
* V_75 = V_27 ;
V_29 = F_32 ( V_27 ) ;
F_65 ( V_27 , V_9 , V_29 -> V_79 ) ;
V_39 = F_9 ( V_9 , V_29 -> V_79 ) ;
if ( V_39 && V_39 -> V_41 != V_64 &&
V_39 -> V_41 != V_52 ) {
V_10 = V_39 ;
V_71 = F_25 ( V_27 , V_10 , V_29 , 0 ) ? :
F_64 ( V_27 ) ;
V_76 = V_78 ;
goto V_80;
}
V_45 = F_28 ( NULL , V_29 -> V_31 ) ;
if ( F_34 ( V_45 , V_9 -> V_49 ) )
F_51 ( V_9 , V_39 , V_27 ) ;
return V_81 ;
}
F_65 ( V_27 , V_9 , V_29 -> V_79 ) ;
if ( V_9 -> V_82 )
V_10 = F_70 ( & V_9 -> V_83 ,
struct V_8 , V_60 ) ;
else
V_10 = F_9 ( V_9 , V_29 -> V_31 ) ;
if ( V_10 == NULL )
return V_81 ;
V_6 = V_10 -> V_6 ;
if ( F_63 ( ! ( V_6 -> V_72 & V_73 ) ) ) {
F_50 ( V_27 ) ;
return V_78 ;
}
V_53 = V_27 -> V_53 + V_54 ;
V_27 = F_71 ( V_27 , V_51 ) ;
if ( ! V_27 ) {
V_71 = V_50 ;
V_76 = V_78 ;
goto V_80;
}
* V_75 = V_27 ;
V_27 -> V_6 = V_6 ;
V_27 -> V_33 = V_74 ;
V_71 = V_55 ;
V_76 = V_84 ;
V_80:
F_38 ( V_10 , V_53 , V_71 == V_55 , false ) ;
return V_76 ;
}
static int F_72 ( struct V_26 * V_27 , struct V_5 * V_6 )
{
const struct V_8 * V_10 = F_73 ( V_6 ) ;
const struct V_4 * V_9 = V_10 -> V_9 ;
const struct V_8 * V_85 ;
if ( V_10 -> V_41 == V_52 ) {
const struct V_28 * V_29 = ( void * ) V_27 -> V_86 ;
if ( F_67 ( V_29 -> V_31 ) ) {
F_31 ( V_27 , V_9 , V_6 , V_52 ) ;
goto V_87;
}
V_85 = F_9 ( V_9 , V_29 -> V_31 ) ;
if ( V_85 && V_85 -> V_41 == V_52 ) {
F_74 ( V_10 -> V_88 , V_27 ) ;
return V_89 ;
}
}
V_87:
V_27 -> V_6 = V_10 -> V_88 ;
return F_75 ( V_27 ) ;
}
static inline T_4 F_76 ( struct V_8 * V_10 , struct V_26 * V_27 )
{
#ifdef F_77
if ( V_10 -> V_90 )
F_78 ( V_10 -> V_90 , V_27 ) ;
#else
F_79 () ;
#endif
return V_91 ;
}
static T_4 F_80 ( struct V_26 * V_27 ,
struct V_5 * V_6 )
{
unsigned int V_53 = V_27 -> V_53 ;
int V_71 ;
struct V_8 * V_10 = F_73 ( V_6 ) ;
if ( F_63 ( F_81 ( V_6 ) ) )
return F_76 ( V_10 , V_27 ) ;
if ( V_10 -> V_92 ) {
V_27 -> V_6 = V_10 -> V_88 ;
V_71 = F_82 ( V_27 , V_10 -> V_92 ) ;
} else {
V_71 = F_72 ( V_27 , V_6 ) ;
}
if ( F_36 ( V_71 == V_89 || V_71 == V_93 ) ) {
struct V_94 * V_95 ;
V_95 = F_83 ( V_10 -> V_95 ) ;
F_84 ( & V_95 -> V_96 ) ;
V_95 -> V_97 ++ ;
V_95 -> V_98 += V_53 ;
F_85 ( & V_95 -> V_96 ) ;
} else {
F_86 ( V_10 -> V_95 -> V_99 ) ;
}
return V_71 ;
}
static int F_87 ( struct V_26 * V_27 , struct V_5 * V_6 ,
unsigned short type , const void * V_100 ,
const void * V_101 , unsigned V_53 )
{
const struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_88 = V_10 -> V_88 ;
return F_88 ( V_27 , V_88 , type , V_100 ,
V_101 ? : V_6 -> V_12 , V_53 ) ;
}
static int F_89 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_88 = V_10 -> V_88 ;
int V_44 ;
if ( V_10 -> V_9 -> V_82 ) {
if ( ! ( V_10 -> V_72 & V_102 ) ) {
V_44 = F_90 ( V_88 , 1 ) ;
if ( V_44 < 0 )
goto V_80;
}
goto V_103;
}
if ( V_88 -> V_104 & V_105 &&
V_6 -> V_106 == & V_107 ) {
V_10 -> V_92 =
V_88 -> V_108 -> V_109 ( V_88 , V_6 ) ;
if ( F_91 ( V_10 -> V_92 ) ) {
V_10 -> V_92 = NULL ;
} else
return 0 ;
}
V_44 = - V_110 ;
if ( F_24 ( V_10 -> V_9 , V_6 -> V_12 ) )
goto V_80;
V_44 = F_92 ( V_88 , V_6 -> V_12 ) ;
if ( V_44 < 0 )
goto V_80;
if ( V_6 -> V_72 & V_111 ) {
V_44 = F_93 ( V_88 , 1 ) ;
if ( V_44 < 0 )
goto V_112;
}
if ( V_6 -> V_72 & V_113 ) {
V_44 = F_90 ( V_88 , 1 ) ;
if ( V_44 < 0 )
goto V_114;
}
V_103:
F_17 ( V_10 ) ;
return 0 ;
V_114:
if ( V_6 -> V_72 & V_111 )
F_93 ( V_88 , - 1 ) ;
V_112:
F_94 ( V_88 , V_6 -> V_12 ) ;
V_80:
if ( V_10 -> V_92 ) {
V_88 -> V_108 -> V_115 ( V_88 ,
V_10 -> V_92 ) ;
V_10 -> V_92 = NULL ;
}
return V_44 ;
}
static int F_95 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_88 = V_10 -> V_88 ;
if ( V_10 -> V_92 ) {
V_88 -> V_108 -> V_115 ( V_88 ,
V_10 -> V_92 ) ;
V_10 -> V_92 = NULL ;
return 0 ;
}
F_96 ( V_88 , V_6 ) ;
F_97 ( V_88 , V_6 ) ;
if ( V_10 -> V_9 -> V_82 ) {
if ( ! ( V_10 -> V_72 & V_102 ) )
F_90 ( V_88 , - 1 ) ;
goto V_116;
}
if ( V_6 -> V_72 & V_111 )
F_93 ( V_88 , - 1 ) ;
if ( V_6 -> V_72 & V_113 )
F_90 ( V_88 , - 1 ) ;
F_94 ( V_88 , V_6 -> V_12 ) ;
V_116:
F_21 ( V_10 , ! V_6 -> V_117 ) ;
return 0 ;
}
static int F_98 ( struct V_5 * V_6 , unsigned char * V_1 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_88 = V_10 -> V_88 ;
int V_44 ;
if ( ! ( V_6 -> V_72 & V_73 ) ) {
F_15 ( V_6 -> V_12 , V_1 ) ;
} else {
if ( F_24 ( V_10 -> V_9 , V_1 ) )
return - V_110 ;
if ( ! V_10 -> V_9 -> V_82 ) {
V_44 = F_92 ( V_88 , V_1 ) ;
if ( V_44 )
return V_44 ;
F_94 ( V_88 , V_6 -> V_12 ) ;
}
F_23 ( V_10 , V_1 ) ;
}
return 0 ;
}
static int F_99 ( struct V_5 * V_6 , void * V_118 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_119 * V_1 = V_118 ;
if ( ! F_100 ( V_1 -> V_120 ) )
return - V_121 ;
if ( V_10 -> V_41 == V_65 ) {
F_101 ( V_10 -> V_88 , V_1 ) ;
return 0 ;
}
return F_98 ( V_6 , V_1 -> V_120 ) ;
}
static void F_102 ( struct V_5 * V_6 , int V_122 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_88 = V_10 -> V_88 ;
if ( V_6 -> V_72 & V_73 ) {
if ( V_122 & V_111 )
F_93 ( V_88 , V_6 -> V_72 & V_111 ? 1 : - 1 ) ;
if ( V_122 & V_113 )
F_90 ( V_88 ,
V_6 -> V_72 & V_113 ? 1 : - 1 ) ;
}
}
static void F_103 ( unsigned long * V_49 ,
struct V_5 * V_6 ,
struct V_8 * V_10 )
{
if ( V_6 -> V_72 & ( V_113 | V_111 ) ) {
F_104 ( V_49 , V_123 ) ;
} else {
struct V_124 * V_125 ;
F_105 ( V_126 , V_123 ) ;
F_106 ( V_126 , V_123 ) ;
F_107 (ha, dev) {
F_108 ( F_28 ( V_10 , V_125 -> V_1 ) , V_126 ) ;
}
F_108 ( F_28 ( V_10 , V_6 -> V_32 ) , V_126 ) ;
F_109 ( V_49 , V_126 , V_123 ) ;
}
}
static void F_110 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
F_103 ( V_10 -> V_49 , V_6 , V_10 ) ;
F_111 ( V_10 -> V_88 , V_6 ) ;
F_112 ( V_10 -> V_88 , V_6 ) ;
F_103 ( V_10 -> V_9 -> V_49 , V_10 -> V_88 , NULL ) ;
}
static int F_113 ( struct V_5 * V_6 , int V_127 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
if ( V_10 -> V_88 -> V_128 < V_127 )
return - V_129 ;
V_6 -> V_128 = V_127 ;
return 0 ;
}
static int F_114 ( struct V_5 * V_6 )
{
return ( (struct V_8 * ) F_73 ( V_6 ) ) -> V_130 ;
}
static void F_115 ( struct V_5 * V_6 )
{
F_116 ( V_6 ) ;
F_117 ( & V_6 -> V_131 ,
& V_132 ,
F_114 ( V_6 ) ) ;
}
static int F_118 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
const struct V_5 * V_88 = V_10 -> V_88 ;
struct V_4 * V_9 = V_10 -> V_9 ;
V_6 -> V_133 = ( V_6 -> V_133 & ~ V_134 ) |
( V_88 -> V_133 & V_134 ) ;
V_6 -> V_104 = V_88 -> V_104 & V_135 ;
V_6 -> V_104 |= V_136 ;
V_6 -> V_137 |= V_138 ;
V_6 -> V_139 = V_88 -> V_139 & V_135 ;
V_6 -> V_140 = V_88 -> V_140 ;
V_6 -> V_141 = V_88 -> V_141 ;
V_6 -> V_142 = V_88 -> V_142 ;
F_115 ( V_6 ) ;
V_10 -> V_95 = F_119 ( struct V_94 ) ;
if ( ! V_10 -> V_95 )
return - V_19 ;
V_9 -> V_143 += 1 ;
return 0 ;
}
static void F_120 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_4 * V_9 = V_10 -> V_9 ;
F_121 ( V_10 -> V_95 ) ;
F_59 ( V_9 , V_10 ) ;
V_9 -> V_143 -= 1 ;
if ( ! V_9 -> V_143 )
F_122 ( V_9 -> V_6 ) ;
}
static void F_123 ( struct V_5 * V_6 ,
struct V_144 * V_145 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
if ( V_10 -> V_95 ) {
struct V_94 * V_118 ;
T_2 V_146 , V_147 , V_148 , V_97 , V_98 ;
T_1 V_149 = 0 , V_99 = 0 ;
unsigned int V_150 ;
int V_43 ;
F_124 (i) {
V_118 = F_125 ( V_10 -> V_95 , V_43 ) ;
do {
V_150 = F_126 ( & V_118 -> V_96 ) ;
V_146 = V_118 -> V_146 ;
V_147 = V_118 -> V_147 ;
V_148 = V_118 -> V_148 ;
V_97 = V_118 -> V_97 ;
V_98 = V_118 -> V_98 ;
} while ( F_127 ( & V_118 -> V_96 , V_150 ) );
V_145 -> V_146 += V_146 ;
V_145 -> V_147 += V_147 ;
V_145 -> V_151 += V_148 ;
V_145 -> V_97 += V_97 ;
V_145 -> V_98 += V_98 ;
V_149 += V_118 -> V_149 ;
V_99 += V_118 -> V_99 ;
}
V_145 -> V_149 = V_149 ;
V_145 -> V_68 = V_149 ;
V_145 -> V_99 = V_99 ;
}
}
static int F_128 ( struct V_5 * V_6 ,
T_5 V_152 , T_6 V_153 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_88 = V_10 -> V_88 ;
return F_129 ( V_88 , V_152 , V_153 ) ;
}
static int F_130 ( struct V_5 * V_6 ,
T_5 V_152 , T_6 V_153 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_88 = V_10 -> V_88 ;
F_131 ( V_88 , V_152 , V_153 ) ;
return 0 ;
}
static int F_132 ( struct V_154 * V_155 , struct V_156 * V_157 [] ,
struct V_5 * V_6 ,
const unsigned char * V_1 , T_6 V_153 ,
T_6 V_72 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
int V_44 = - V_129 ;
if ( ! V_10 -> V_9 -> V_82 && F_133 ( V_1 ) )
return - V_158 ;
if ( V_72 & V_159 )
return - V_158 ;
if ( F_133 ( V_1 ) )
V_44 = F_134 ( V_6 , V_1 ) ;
else if ( F_67 ( V_1 ) )
V_44 = F_135 ( V_6 , V_1 ) ;
return V_44 ;
}
static int F_136 ( struct V_154 * V_155 , struct V_156 * V_157 [] ,
struct V_5 * V_6 ,
const unsigned char * V_1 , T_6 V_153 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
int V_44 = - V_129 ;
if ( ! V_10 -> V_9 -> V_82 && F_133 ( V_1 ) )
return - V_158 ;
if ( F_133 ( V_1 ) )
V_44 = F_94 ( V_6 , V_1 ) ;
else if ( F_67 ( V_1 ) )
V_44 = F_137 ( V_6 , V_1 ) ;
return V_44 ;
}
static void F_138 ( struct V_5 * V_6 ,
struct V_160 * V_161 )
{
F_139 ( V_161 -> V_162 , L_1 , sizeof( V_161 -> V_162 ) ) ;
F_139 ( V_161 -> V_163 , L_2 , sizeof( V_161 -> V_163 ) ) ;
}
static int F_140 ( struct V_5 * V_6 ,
struct V_164 * V_165 )
{
const struct V_8 * V_10 = F_73 ( V_6 ) ;
return F_141 ( V_10 -> V_88 , V_165 ) ;
}
static T_7 F_142 ( struct V_5 * V_6 ,
T_7 V_104 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
T_7 V_166 = V_10 -> V_88 -> V_104 ;
T_7 V_167 ;
V_104 |= V_168 ;
V_104 &= ( V_10 -> V_169 | ~ V_135 ) ;
V_167 = V_104 ;
V_166 &= ( V_104 | ~ V_138 ) ;
V_104 = F_143 ( V_166 , V_104 , V_167 ) ;
V_104 |= V_136 ;
V_104 &= ~ V_170 ;
return V_104 ;
}
static void F_144 ( struct V_5 * V_6 )
{
return;
}
static int F_145 ( struct V_5 * V_6 , struct V_171 * V_172 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_5 * V_173 = V_10 -> V_88 ;
struct V_90 * V_90 ;
int V_44 = 0 ;
V_90 = F_146 ( sizeof( * V_90 ) , V_18 ) ;
V_44 = - V_19 ;
if ( ! V_90 )
goto V_80;
V_44 = F_147 ( V_90 , V_173 ) ;
if ( V_44 ) {
F_148 ( V_90 ) ;
goto V_80;
}
V_10 -> V_90 = V_90 ;
V_80:
return V_44 ;
}
static void F_149 ( struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_90 * V_90 = V_10 -> V_90 ;
if ( ! V_90 )
return;
V_10 -> V_90 = NULL ;
F_150 ( V_90 ) ;
}
static int F_151 ( const struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
return V_10 -> V_88 -> V_174 ;
}
void F_152 ( struct V_5 * V_6 )
{
F_153 ( V_6 ) ;
V_6 -> V_175 = 0 ;
V_6 -> V_176 = V_177 ;
V_6 -> V_178 &= ~ V_179 ;
F_154 ( V_6 ) ;
V_6 -> V_178 |= V_180 ;
V_6 -> V_108 = & V_181 ;
V_6 -> V_182 = V_183 ;
V_6 -> V_184 = & V_185 ;
V_6 -> V_186 = & V_187 ;
}
static void F_155 ( struct V_5 * V_6 )
{
F_152 ( V_6 ) ;
V_6 -> V_178 |= V_188 ;
}
static int F_156 ( struct V_5 * V_6 )
{
struct V_4 * V_9 ;
unsigned int V_43 ;
int V_44 ;
if ( V_6 -> type != V_189 || V_6 -> V_72 & V_190 )
return - V_129 ;
if ( F_157 ( V_6 ) )
return - V_110 ;
V_9 = F_146 ( sizeof( * V_9 ) , V_18 ) ;
if ( V_9 == NULL )
return - V_19 ;
V_9 -> V_82 = false ;
V_9 -> V_6 = V_6 ;
F_158 ( & V_9 -> V_83 ) ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ )
F_159 ( & V_9 -> V_22 [ V_43 ] ) ;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ )
F_159 ( & V_9 -> V_17 [ V_43 ] ) ;
F_160 ( & V_9 -> V_61 ) ;
F_161 ( & V_9 -> V_58 , F_39 ) ;
V_44 = F_162 ( V_6 , F_66 , V_9 ) ;
if ( V_44 )
F_148 ( V_9 ) ;
else
V_6 -> V_178 |= V_191 ;
return V_44 ;
}
static void F_122 ( struct V_5 * V_6 )
{
struct V_4 * V_9 = F_7 ( V_6 ) ;
struct V_26 * V_27 ;
V_6 -> V_178 &= ~ V_191 ;
F_163 ( V_6 ) ;
F_164 ( & V_9 -> V_58 ) ;
while ( ( V_27 = F_45 ( & V_9 -> V_61 ) ) ) {
const struct V_8 * V_39 = F_46 ( V_27 ) -> V_39 ;
if ( V_39 )
F_49 ( V_39 -> V_6 ) ;
F_50 ( V_27 ) ;
}
F_148 ( V_9 ) ;
}
static int F_165 ( struct V_156 * V_157 [] , struct V_156 * V_86 [] )
{
if ( V_157 [ V_192 ] ) {
if ( F_166 ( V_157 [ V_192 ] ) != V_25 )
return - V_129 ;
if ( ! F_100 ( F_167 ( V_157 [ V_192 ] ) ) )
return - V_121 ;
}
if ( V_86 && V_86 [ V_193 ] &&
F_168 ( V_86 [ V_193 ] ) & ~ V_102 )
return - V_129 ;
if ( V_86 && V_86 [ V_194 ] ) {
switch ( F_169 ( V_86 [ V_194 ] ) ) {
case V_63 :
case V_64 :
case V_52 :
case V_65 :
case V_195 :
break;
default:
return - V_129 ;
}
}
if ( V_86 && V_86 [ V_196 ] ) {
switch ( F_169 ( V_86 [ V_196 ] ) ) {
case V_197 :
case V_198 :
case V_199 :
case V_200 :
break;
default:
return - V_129 ;
}
}
if ( V_86 && V_86 [ V_201 ] ) {
if ( F_166 ( V_86 [ V_201 ] ) != V_25 )
return - V_129 ;
if ( ! F_100 ( F_167 ( V_86 [ V_201 ] ) ) )
return - V_121 ;
}
if ( V_86 && V_86 [ V_202 ] )
return - V_129 ;
return 0 ;
}
static int F_170 ( struct V_8 * V_10 , T_1 V_41 ,
struct V_156 * V_86 [] )
{
char * V_1 = NULL ;
int V_71 , V_203 , V_53 ;
struct V_156 * V_204 , * V_205 ;
struct V_13 * V_14 ;
if ( V_86 [ V_201 ] )
V_1 = F_167 ( V_86 [ V_201 ] ) ;
if ( V_41 == V_197 ) {
if ( ! V_1 )
return - V_129 ;
return F_13 ( V_10 , V_1 ) ;
} else if ( V_41 == V_198 ) {
if ( ! V_1 )
return - V_129 ;
V_14 = F_12 ( V_10 , V_1 ) ;
if ( V_14 ) {
F_18 ( V_14 ) ;
V_10 -> V_21 -- ;
}
} else if ( V_41 == V_199 ) {
F_59 ( V_10 -> V_9 , V_10 ) ;
} else if ( V_41 == V_200 ) {
F_59 ( V_10 -> V_9 , V_10 ) ;
if ( V_1 ) {
V_71 = F_13 ( V_10 , V_1 ) ;
if ( V_71 )
return V_71 ;
}
if ( ! V_86 || ! V_86 [ V_206 ] )
return 0 ;
V_205 = F_167 ( V_86 [ V_206 ] ) ;
V_53 = F_166 ( V_86 [ V_206 ] ) ;
F_171 (nla, head, len, rem) {
if ( F_172 ( V_204 ) != V_201 ||
F_166 ( V_204 ) != V_25 )
continue;
V_1 = F_167 ( V_204 ) ;
V_71 = F_13 ( V_10 , V_1 ) ;
if ( V_71 )
return V_71 ;
}
} else {
return - V_129 ;
}
return 0 ;
}
int F_173 ( struct V_207 * V_208 , struct V_5 * V_6 ,
struct V_156 * V_157 [] , struct V_156 * V_86 [] )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
struct V_4 * V_9 ;
struct V_5 * V_88 ;
int V_44 ;
int V_209 ;
bool V_210 = false ;
if ( ! V_157 [ V_211 ] )
return - V_129 ;
V_88 = F_174 ( V_208 , F_169 ( V_157 [ V_211 ] ) ) ;
if ( V_88 == NULL )
return - V_212 ;
if ( F_175 ( V_88 ) )
V_88 = F_176 ( V_88 ) ;
if ( ! V_157 [ V_213 ] )
V_6 -> V_128 = V_88 -> V_128 ;
else if ( V_6 -> V_128 > V_88 -> V_128 )
return - V_129 ;
V_6 -> V_175 = V_214 ;
V_6 -> V_176 = V_88 -> V_176 ;
if ( ! V_157 [ V_192 ] )
F_177 ( V_6 ) ;
if ( ! F_178 ( V_88 ) ) {
V_44 = F_156 ( V_88 ) ;
if ( V_44 < 0 )
return V_44 ;
V_210 = true ;
}
V_9 = F_7 ( V_88 ) ;
if ( V_9 -> V_82 ) {
V_44 = - V_129 ;
goto V_215;
}
V_10 -> V_88 = V_88 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_169 = V_135 ;
V_10 -> V_130 = F_179 ( V_88 ) + 1 ;
V_10 -> V_41 = V_64 ;
if ( V_86 && V_86 [ V_194 ] )
V_10 -> V_41 = F_169 ( V_86 [ V_194 ] ) ;
if ( V_86 && V_86 [ V_193 ] )
V_10 -> V_72 = F_168 ( V_86 [ V_193 ] ) ;
if ( V_10 -> V_41 == V_65 ) {
if ( V_9 -> V_143 ) {
V_44 = - V_129 ;
goto V_215;
}
V_9 -> V_82 = true ;
F_180 ( V_6 , V_88 ) ;
}
if ( V_86 && V_86 [ V_196 ] ) {
if ( V_10 -> V_41 != V_195 ) {
V_44 = - V_129 ;
goto V_215;
}
V_209 = F_169 ( V_86 [ V_196 ] ) ;
V_44 = F_170 ( V_10 , V_209 , V_86 ) ;
if ( V_44 )
goto V_215;
}
V_44 = F_181 ( V_6 ) ;
if ( V_44 < 0 )
goto V_215;
V_6 -> V_178 |= V_216 ;
V_44 = F_182 ( V_88 , V_6 ) ;
if ( V_44 )
goto V_217;
F_183 ( & V_10 -> V_60 , & V_9 -> V_83 ) ;
F_184 ( V_88 , V_6 ) ;
F_185 ( V_6 ) ;
return 0 ;
V_217:
F_186 ( V_6 ) ;
V_215:
if ( V_210 )
F_122 ( V_9 -> V_6 ) ;
return V_44 ;
}
static int F_187 ( struct V_207 * V_208 , struct V_5 * V_6 ,
struct V_156 * V_157 [] , struct V_156 * V_86 [] )
{
return F_173 ( V_208 , V_6 , V_157 , V_86 ) ;
}
void F_188 ( struct V_5 * V_6 , struct V_218 * V_205 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
if ( V_10 -> V_41 == V_195 )
F_59 ( V_10 -> V_9 , V_10 ) ;
F_189 ( & V_10 -> V_60 ) ;
F_190 ( V_6 , V_205 ) ;
F_191 ( V_10 -> V_88 , V_6 ) ;
}
static int F_192 ( struct V_5 * V_6 ,
struct V_156 * V_157 [] , struct V_156 * V_86 [] )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
enum V_40 V_41 ;
bool V_219 = false ;
enum V_220 V_209 ;
int V_71 ;
if ( V_86 && V_86 [ V_194 ] ) {
V_219 = true ;
V_41 = F_169 ( V_86 [ V_194 ] ) ;
if ( ( V_41 == V_65 ) !=
( V_10 -> V_41 == V_65 ) )
return - V_129 ;
if ( V_10 -> V_41 == V_195 &&
V_10 -> V_41 != V_41 )
F_59 ( V_10 -> V_9 , V_10 ) ;
}
if ( V_86 && V_86 [ V_193 ] ) {
T_8 V_72 = F_168 ( V_86 [ V_193 ] ) ;
bool V_221 = ( V_72 ^ V_10 -> V_72 ) & V_102 ;
if ( V_10 -> V_9 -> V_82 && V_221 ) {
int V_44 ;
if ( V_72 & V_102 )
V_44 = F_90 ( V_10 -> V_88 , - 1 ) ;
else
V_44 = F_90 ( V_10 -> V_88 , 1 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_10 -> V_72 = V_72 ;
}
if ( V_219 )
V_10 -> V_41 = V_41 ;
if ( V_86 && V_86 [ V_196 ] ) {
if ( V_10 -> V_41 != V_195 )
return - V_129 ;
V_209 = F_169 ( V_86 [ V_196 ] ) ;
V_71 = F_170 ( V_10 , V_209 , V_86 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
static T_9 F_193 ( const struct V_8 * V_10 )
{
if ( V_10 -> V_21 == 0 )
return 0 ;
return F_194 ( 0 )
+ V_10 -> V_21 * F_194 ( sizeof( V_222 ) * V_25 ) ;
}
static T_9 F_195 ( const struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
return ( 0
+ F_194 ( 4 )
+ F_194 ( 2 )
+ F_194 ( 4 )
+ F_193 ( V_10 )
) ;
}
static int F_196 ( struct V_26 * V_27 ,
const struct V_8 * V_10 ,
const int V_43 )
{
struct V_15 * V_16 = & V_10 -> V_9 -> V_17 [ V_43 ] ;
struct V_13 * V_14 ;
F_10 (entry, h, hlist) {
if ( V_14 -> V_10 != V_10 )
continue;
if ( F_197 ( V_27 , V_201 , V_25 , V_14 -> V_1 ) )
return 1 ;
}
return 0 ;
}
static int F_198 ( struct V_26 * V_27 ,
const struct V_5 * V_6 )
{
struct V_8 * V_10 = F_73 ( V_6 ) ;
int V_43 ;
struct V_156 * V_223 ;
if ( F_199 ( V_27 , V_194 , V_10 -> V_41 ) )
goto V_224;
if ( F_200 ( V_27 , V_193 , V_10 -> V_72 ) )
goto V_224;
if ( F_199 ( V_27 , V_202 , V_10 -> V_21 ) )
goto V_224;
if ( V_10 -> V_21 > 0 ) {
V_223 = F_201 ( V_27 , V_206 ) ;
if ( V_223 == NULL )
goto V_224;
for ( V_43 = 0 ; V_43 < V_48 ; V_43 ++ ) {
if ( F_196 ( V_27 , V_10 , V_43 ) )
goto V_224;
}
F_202 ( V_27 , V_223 ) ;
}
return 0 ;
V_224:
return - V_225 ;
}
int F_203 ( struct V_106 * V_226 )
{
V_226 -> V_227 = F_165 ;
V_226 -> V_228 = V_229 ;
V_226 -> V_230 = V_231 ;
V_226 -> V_232 = F_192 ;
V_226 -> V_233 = F_195 ;
V_226 -> V_234 = F_198 ;
return F_204 ( V_226 ) ;
}
static struct V_207 * F_205 ( const struct V_5 * V_6 )
{
return F_69 ( F_176 ( V_6 ) ) ;
}
static int F_206 ( struct V_235 * V_236 ,
unsigned long V_237 , void * V_238 )
{
struct V_5 * V_6 = F_207 ( V_238 ) ;
struct V_8 * V_10 , * V_239 ;
struct V_4 * V_9 ;
F_208 ( V_240 ) ;
if ( ! F_178 ( V_6 ) )
return V_241 ;
V_9 = F_7 ( V_6 ) ;
switch ( V_237 ) {
case V_242 :
case V_243 :
F_209 (vlan, &port->vlans, list)
F_184 ( V_10 -> V_88 ,
V_10 -> V_6 ) ;
break;
case V_244 :
F_209 (vlan, &port->vlans, list) {
V_10 -> V_6 -> V_140 = V_6 -> V_140 ;
V_10 -> V_6 -> V_141 = V_6 -> V_141 ;
F_210 ( V_10 -> V_6 ) ;
}
break;
case V_245 :
F_209 (vlan, &port->vlans, list) {
if ( V_10 -> V_6 -> V_128 <= V_6 -> V_128 )
continue;
F_211 ( V_10 -> V_6 , V_6 -> V_128 ) ;
}
break;
case V_246 :
if ( ! V_9 -> V_82 )
return V_241 ;
V_10 = F_212 ( & V_9 -> V_83 ,
struct V_8 ,
V_60 ) ;
if ( F_98 ( V_10 -> V_6 , V_6 -> V_12 ) )
return V_247 ;
break;
case V_248 :
if ( V_6 -> V_249 != V_250 )
break;
F_213 (vlan, next, &port->vlans, list)
V_10 -> V_6 -> V_106 -> V_251 ( V_10 -> V_6 , & V_240 ) ;
F_214 ( & V_240 ) ;
break;
case V_252 :
return V_247 ;
case V_253 :
case V_254 :
case V_255 :
F_209 (vlan, &port->vlans, list)
F_215 ( V_237 , V_10 -> V_6 ) ;
}
return V_241 ;
}
static int T_10 F_216 ( void )
{
int V_44 ;
F_217 ( & V_256 ) ;
V_44 = F_203 ( & V_107 ) ;
if ( V_44 < 0 )
goto V_257;
return 0 ;
V_257:
F_218 ( & V_256 ) ;
return V_44 ;
}
static void T_11 F_219 ( void )
{
F_220 ( & V_107 ) ;
F_218 ( & V_256 ) ;
}
