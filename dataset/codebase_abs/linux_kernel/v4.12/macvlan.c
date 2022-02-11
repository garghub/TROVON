static inline bool F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 |= V_4 ;
}
static inline bool F_3 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 & V_5 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_3 |= V_5 ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_5 ;
}
static T_1 F_6 ( const unsigned char * V_6 )
{
T_2 V_7 = F_7 ( ( T_2 * ) V_6 ) ;
#ifdef F_8
V_7 >>= 16 ;
#else
V_7 <<= 16 ;
#endif
return F_9 ( V_7 , V_8 ) ;
}
static struct V_1 * F_10 ( const struct V_9 * V_10 )
{
return F_11 ( V_10 -> V_11 ) ;
}
static struct V_1 * F_12 ( const struct V_9 * V_10 )
{
return F_13 ( V_10 -> V_11 ) ;
}
static struct V_12 * F_14 ( const struct V_1 * V_2 ,
const unsigned char * V_6 )
{
struct V_12 * V_13 ;
T_1 V_14 = F_6 ( V_6 ) ;
F_15 (vlan, &port->vlan_hash[idx], hlist) {
if ( F_16 ( V_13 -> V_10 -> V_15 , V_6 ) )
return V_13 ;
}
return NULL ;
}
static struct V_16 * F_17 (
const struct V_12 * V_13 ,
const unsigned char * V_6 )
{
struct V_16 * V_17 ;
T_1 V_14 = F_6 ( V_6 ) ;
struct V_18 * V_19 = & V_13 -> V_2 -> V_20 [ V_14 ] ;
F_15 (entry, h, hlist) {
if ( F_16 ( V_17 -> V_6 , V_6 ) &&
V_17 -> V_13 == V_13 )
return V_17 ;
}
return NULL ;
}
static int F_18 ( struct V_12 * V_13 ,
const unsigned char * V_6 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
V_17 = F_17 ( V_13 , V_6 ) ;
if ( V_17 )
return 0 ;
V_17 = F_19 ( sizeof( * V_17 ) , V_21 ) ;
if ( ! V_17 )
return - V_22 ;
F_20 ( V_17 -> V_6 , V_6 ) ;
V_17 -> V_13 = V_13 ;
V_19 = & V_2 -> V_20 [ F_6 ( V_6 ) ] ;
F_21 ( & V_17 -> V_23 , V_19 ) ;
V_13 -> V_24 ++ ;
return 0 ;
}
static void F_22 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
const unsigned char * V_6 = V_13 -> V_10 -> V_15 ;
T_1 V_14 = F_6 ( V_6 ) ;
F_21 ( & V_13 -> V_23 , & V_2 -> V_25 [ V_14 ] ) ;
}
static void F_23 ( struct V_16 * V_17 )
{
F_24 ( & V_17 -> V_23 ) ;
F_25 ( V_17 , V_26 ) ;
}
static void F_26 ( struct V_12 * V_13 , bool V_27 )
{
F_24 ( & V_13 -> V_23 ) ;
if ( V_27 )
F_27 () ;
}
static void F_28 ( struct V_12 * V_13 ,
const unsigned char * V_6 )
{
F_26 ( V_13 , true ) ;
memcpy ( V_13 -> V_10 -> V_15 , V_6 , V_28 ) ;
F_22 ( V_13 ) ;
}
static bool F_29 ( const struct V_1 * V_2 ,
const unsigned char * V_6 )
{
if ( ! F_1 ( V_2 ) && ! F_3 ( V_2 ) &&
F_16 ( V_2 -> V_10 -> V_15 , V_6 ) )
return true ;
if ( F_14 ( V_2 , V_6 ) )
return true ;
return false ;
}
static int F_30 ( struct V_29 * V_30 ,
const struct V_12 * V_13 ,
const struct V_31 * V_32 , bool V_33 )
{
struct V_9 * V_10 = V_13 -> V_10 ;
if ( V_33 )
return F_31 ( V_10 , V_30 ) ;
V_30 -> V_10 = V_10 ;
if ( F_16 ( V_32 -> V_34 , V_10 -> V_35 ) )
V_30 -> V_36 = V_37 ;
else
V_30 -> V_36 = V_38 ;
return 0 ;
}
static T_1 F_32 ( const struct V_12 * V_13 )
{
return ( T_1 ) ( ( ( unsigned long ) V_13 ) >> V_39 ) ;
}
static unsigned int F_33 ( const struct V_12 * V_13 ,
const unsigned char * V_6 )
{
T_1 V_40 = F_34 ( V_6 + 2 ) ;
V_40 ^= F_32 ( V_13 ) ;
return F_35 ( V_40 , V_41 ) ;
}
static void F_36 ( struct V_29 * V_30 ,
const struct V_1 * V_2 ,
struct V_9 * V_42 ,
enum V_43 V_44 )
{
const struct V_31 * V_32 = F_37 ( V_30 ) ;
const struct V_12 * V_13 ;
struct V_29 * V_45 ;
unsigned int V_46 ;
int V_47 ;
unsigned int V_48 ;
if ( V_30 -> V_49 == F_38 ( V_50 ) )
return;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ ) {
F_15 (vlan, &port->vlan_hash[i], hlist) {
if ( V_13 -> V_10 == V_42 || ! ( V_13 -> V_44 & V_44 ) )
continue;
V_48 = F_33 ( V_13 , V_32 -> V_34 ) ;
if ( ! F_39 ( V_48 , V_13 -> V_52 ) )
continue;
V_47 = V_53 ;
V_45 = F_40 ( V_30 , V_54 ) ;
if ( F_41 ( V_45 ) )
V_47 = F_30 (
V_45 , V_13 , V_32 ,
V_44 == V_55 ) ? :
F_42 ( V_45 ) ;
F_43 ( V_13 , V_30 -> V_56 + V_57 ,
V_47 == V_58 , true ) ;
}
}
}
static void F_44 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_45 ( V_60 , struct V_1 ,
V_61 ) ;
struct V_29 * V_30 ;
struct V_62 V_63 ;
F_46 ( & V_63 ) ;
F_47 ( & V_2 -> V_64 . V_65 ) ;
F_48 ( & V_2 -> V_64 , & V_63 ) ;
F_49 ( & V_2 -> V_64 . V_65 ) ;
while ( ( V_30 = F_50 ( & V_63 ) ) ) {
const struct V_12 * V_42 = F_51 ( V_30 ) -> V_42 ;
F_52 () ;
if ( ! V_42 )
F_36 ( V_30 , V_2 , NULL ,
V_66 |
V_67 |
V_68 |
V_55 ) ;
else if ( V_42 -> V_44 == V_67 )
F_36 ( V_30 , V_2 , V_42 -> V_10 ,
V_67 |
V_55 ) ;
else
F_36 ( V_30 , V_2 , V_42 -> V_10 ,
V_67 ) ;
F_53 () ;
if ( V_42 )
F_54 ( V_42 -> V_10 ) ;
F_55 ( V_30 ) ;
}
}
static void F_56 ( struct V_1 * V_2 ,
const struct V_12 * V_42 ,
struct V_29 * V_30 )
{
struct V_29 * V_45 ;
int V_47 = - V_22 ;
V_45 = F_40 ( V_30 , V_54 ) ;
if ( ! V_45 )
goto V_47;
F_51 ( V_45 ) -> V_42 = V_42 ;
F_57 ( & V_2 -> V_64 . V_65 ) ;
if ( F_58 ( & V_2 -> V_64 ) < V_69 ) {
if ( V_42 )
F_59 ( V_42 -> V_10 ) ;
F_60 ( & V_2 -> V_64 , V_45 ) ;
V_47 = 0 ;
}
F_61 ( & V_2 -> V_64 . V_65 ) ;
if ( V_47 )
goto V_70;
F_62 ( & V_2 -> V_61 ) ;
return;
V_70:
F_55 ( V_45 ) ;
V_47:
F_63 ( & V_30 -> V_10 -> V_71 ) ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ ) {
struct V_72 * V_19 , * V_73 ;
F_65 (h, n, &port->vlan_source_hash[i]) {
struct V_16 * V_17 ;
V_17 = F_66 ( V_19 , struct V_16 ,
V_23 ) ;
if ( V_17 -> V_13 == V_13 )
F_23 ( V_17 ) ;
}
}
V_13 -> V_24 = 0 ;
}
static void F_67 ( struct V_29 * V_30 ,
struct V_12 * V_13 )
{
struct V_29 * V_45 ;
struct V_9 * V_10 ;
int V_56 ;
int V_74 ;
V_10 = V_13 -> V_10 ;
if ( F_68 ( ! ( V_10 -> V_3 & V_75 ) ) )
return;
V_45 = F_40 ( V_30 , V_54 ) ;
if ( ! V_45 )
return;
V_56 = V_45 -> V_56 + V_57 ;
V_45 -> V_10 = V_10 ;
V_45 -> V_36 = V_76 ;
V_74 = F_69 ( V_45 ) ;
F_43 ( V_13 , V_56 , V_74 == V_58 , false ) ;
}
static void F_70 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
const unsigned char * V_6 )
{
struct V_16 * V_17 ;
T_1 V_14 = F_6 ( V_6 ) ;
struct V_18 * V_19 = & V_2 -> V_20 [ V_14 ] ;
F_15 (entry, h, hlist) {
if ( F_16 ( V_17 -> V_6 , V_6 ) )
F_67 ( V_30 , V_17 -> V_13 ) ;
}
}
static T_3 F_71 ( struct V_29 * * V_77 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 = * V_77 ;
const struct V_31 * V_32 = F_37 ( V_30 ) ;
const struct V_12 * V_13 ;
const struct V_12 * V_42 ;
struct V_9 * V_10 ;
unsigned int V_56 = 0 ;
int V_74 ;
T_3 V_78 ;
V_2 = F_10 ( V_30 -> V_10 ) ;
if ( F_72 ( V_32 -> V_34 ) ) {
unsigned int V_48 ;
V_30 = F_73 ( F_74 ( V_30 -> V_10 ) , V_30 , V_79 ) ;
if ( ! V_30 )
return V_80 ;
* V_77 = V_30 ;
V_32 = F_37 ( V_30 ) ;
F_70 ( V_30 , V_2 , V_32 -> V_81 ) ;
V_42 = F_14 ( V_2 , V_32 -> V_81 ) ;
if ( V_42 && V_42 -> V_44 != V_67 &&
V_42 -> V_44 != V_55 ) {
V_13 = V_42 ;
V_74 = F_30 ( V_30 , V_13 , V_32 , 0 ) ? :
F_69 ( V_30 ) ;
V_78 = V_80 ;
goto V_82;
}
V_48 = F_33 ( NULL , V_32 -> V_34 ) ;
if ( F_39 ( V_48 , V_2 -> V_52 ) )
F_56 ( V_2 , V_42 , V_30 ) ;
return V_83 ;
}
F_70 ( V_30 , V_2 , V_32 -> V_81 ) ;
if ( F_1 ( V_2 ) )
V_13 = F_75 ( & V_2 -> V_84 ,
struct V_12 , V_63 ) ;
else
V_13 = F_14 ( V_2 , V_32 -> V_34 ) ;
if ( V_13 == NULL )
return V_83 ;
V_10 = V_13 -> V_10 ;
if ( F_68 ( ! ( V_10 -> V_3 & V_75 ) ) ) {
F_55 ( V_30 ) ;
return V_80 ;
}
V_56 = V_30 -> V_56 + V_57 ;
V_30 = F_76 ( V_30 , V_54 ) ;
if ( ! V_30 ) {
V_74 = V_53 ;
V_78 = V_80 ;
goto V_82;
}
* V_77 = V_30 ;
V_30 -> V_10 = V_10 ;
V_30 -> V_36 = V_76 ;
V_74 = V_58 ;
V_78 = V_85 ;
V_82:
F_43 ( V_13 , V_56 , V_74 == V_58 , false ) ;
return V_78 ;
}
static int F_77 ( struct V_29 * V_30 , struct V_9 * V_10 )
{
const struct V_12 * V_13 = F_78 ( V_10 ) ;
const struct V_1 * V_2 = V_13 -> V_2 ;
const struct V_12 * V_86 ;
if ( V_13 -> V_44 == V_55 ) {
const struct V_31 * V_32 = ( void * ) V_30 -> V_87 ;
if ( F_72 ( V_32 -> V_34 ) ) {
F_36 ( V_30 , V_2 , V_10 , V_55 ) ;
goto V_88;
}
V_86 = F_14 ( V_2 , V_32 -> V_34 ) ;
if ( V_86 && V_86 -> V_44 == V_55 ) {
F_79 ( V_13 -> V_89 , V_30 ) ;
return V_90 ;
}
}
V_88:
V_30 -> V_10 = V_13 -> V_89 ;
return F_80 ( V_30 ) ;
}
static inline T_4 F_81 ( struct V_12 * V_13 , struct V_29 * V_30 )
{
#ifdef F_82
if ( V_13 -> V_91 )
F_83 ( V_13 -> V_91 , V_30 ) ;
#else
F_84 () ;
#endif
return V_92 ;
}
static T_4 F_85 ( struct V_29 * V_30 ,
struct V_9 * V_10 )
{
unsigned int V_56 = V_30 -> V_56 ;
int V_74 ;
struct V_12 * V_13 = F_78 ( V_10 ) ;
if ( F_68 ( F_86 ( V_10 ) ) )
return F_81 ( V_13 , V_30 ) ;
if ( V_13 -> V_93 ) {
V_30 -> V_10 = V_13 -> V_89 ;
V_74 = F_87 ( V_30 , V_13 -> V_93 ) ;
} else {
V_74 = F_77 ( V_30 , V_10 ) ;
}
if ( F_41 ( V_74 == V_90 || V_74 == V_94 ) ) {
struct V_95 * V_96 ;
V_96 = F_88 ( V_13 -> V_96 ) ;
F_89 ( & V_96 -> V_97 ) ;
V_96 -> V_98 ++ ;
V_96 -> V_99 += V_56 ;
F_90 ( & V_96 -> V_97 ) ;
} else {
F_91 ( V_13 -> V_96 -> V_100 ) ;
}
return V_74 ;
}
static int F_92 ( struct V_29 * V_30 , struct V_9 * V_10 ,
unsigned short type , const void * V_101 ,
const void * V_102 , unsigned V_56 )
{
const struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_89 = V_13 -> V_89 ;
return F_93 ( V_30 , V_89 , type , V_101 ,
V_102 ? : V_10 -> V_15 , V_56 ) ;
}
static int F_94 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_89 = V_13 -> V_89 ;
int V_47 ;
if ( F_1 ( V_13 -> V_2 ) ) {
if ( ! ( V_13 -> V_3 & V_103 ) ) {
V_47 = F_95 ( V_89 , 1 ) ;
if ( V_47 < 0 )
goto V_82;
}
goto V_104;
}
if ( V_89 -> V_105 & V_106 &&
V_10 -> V_107 == & V_108 ) {
V_13 -> V_93 =
V_89 -> V_109 -> V_110 ( V_89 , V_10 ) ;
if ( F_96 ( V_13 -> V_93 ) ) {
V_13 -> V_93 = NULL ;
} else
return 0 ;
}
V_47 = - V_111 ;
if ( F_29 ( V_13 -> V_2 , V_10 -> V_15 ) )
goto V_82;
V_47 = F_97 ( V_89 , V_10 -> V_15 ) ;
if ( V_47 < 0 )
goto V_82;
if ( V_10 -> V_3 & V_112 ) {
V_47 = F_98 ( V_89 , 1 ) ;
if ( V_47 < 0 )
goto V_113;
}
if ( V_10 -> V_3 & V_114 ) {
V_47 = F_95 ( V_89 , 1 ) ;
if ( V_47 < 0 )
goto V_115;
}
V_104:
F_22 ( V_13 ) ;
return 0 ;
V_115:
if ( V_10 -> V_3 & V_112 )
F_98 ( V_89 , - 1 ) ;
V_113:
F_99 ( V_89 , V_10 -> V_15 ) ;
V_82:
if ( V_13 -> V_93 ) {
V_89 -> V_109 -> V_116 ( V_89 ,
V_13 -> V_93 ) ;
V_13 -> V_93 = NULL ;
}
return V_47 ;
}
static int F_100 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_89 = V_13 -> V_89 ;
if ( V_13 -> V_93 ) {
V_89 -> V_109 -> V_116 ( V_89 ,
V_13 -> V_93 ) ;
V_13 -> V_93 = NULL ;
return 0 ;
}
F_101 ( V_89 , V_10 ) ;
F_102 ( V_89 , V_10 ) ;
if ( F_1 ( V_13 -> V_2 ) ) {
if ( ! ( V_13 -> V_3 & V_103 ) )
F_95 ( V_89 , - 1 ) ;
goto V_117;
}
if ( V_10 -> V_3 & V_112 )
F_98 ( V_89 , - 1 ) ;
if ( V_10 -> V_3 & V_114 )
F_95 ( V_89 , - 1 ) ;
F_99 ( V_89 , V_10 -> V_15 ) ;
V_117:
F_26 ( V_13 , ! V_10 -> V_118 ) ;
return 0 ;
}
static int F_103 ( struct V_9 * V_10 , unsigned char * V_6 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_89 = V_13 -> V_89 ;
struct V_1 * V_2 = V_13 -> V_2 ;
int V_47 ;
if ( ! ( V_10 -> V_3 & V_75 ) ) {
F_20 ( V_10 -> V_15 , V_6 ) ;
} else {
if ( F_29 ( V_13 -> V_2 , V_6 ) )
return - V_111 ;
if ( ! F_1 ( V_2 ) ) {
V_47 = F_97 ( V_89 , V_6 ) ;
if ( V_47 )
return V_47 ;
F_99 ( V_89 , V_10 -> V_15 ) ;
}
F_28 ( V_13 , V_6 ) ;
}
if ( F_1 ( V_2 ) && ! F_3 ( V_2 ) ) {
F_20 ( V_13 -> V_2 -> V_119 ,
V_89 -> V_15 ) ;
}
F_5 ( V_2 ) ;
return 0 ;
}
static int F_104 ( struct V_9 * V_10 , void * V_120 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_121 * V_6 = V_120 ;
if ( ! F_105 ( V_6 -> V_122 ) )
return - V_123 ;
if ( F_106 ( V_10 -> V_15 , V_6 -> V_122 ) )
return 0 ;
if ( V_13 -> V_44 == V_68 ) {
F_4 ( V_13 -> V_2 ) ;
F_107 ( V_13 -> V_89 , V_6 ) ;
return 0 ;
}
return F_103 ( V_10 , V_6 -> V_122 ) ;
}
static void F_108 ( struct V_9 * V_10 , int V_124 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_89 = V_13 -> V_89 ;
if ( V_10 -> V_3 & V_75 ) {
if ( V_124 & V_112 )
F_98 ( V_89 , V_10 -> V_3 & V_112 ? 1 : - 1 ) ;
if ( V_124 & V_114 )
F_95 ( V_89 ,
V_10 -> V_3 & V_114 ? 1 : - 1 ) ;
}
}
static void F_109 ( unsigned long * V_52 ,
struct V_9 * V_10 ,
struct V_12 * V_13 )
{
if ( V_10 -> V_3 & ( V_114 | V_112 ) ) {
F_110 ( V_52 , V_125 ) ;
} else {
struct V_126 * V_127 ;
F_111 ( V_128 , V_125 ) ;
F_112 ( V_128 , V_125 ) ;
F_113 (ha, dev) {
F_114 ( F_33 ( V_13 , V_127 -> V_6 ) , V_128 ) ;
}
F_114 ( F_33 ( V_13 , V_10 -> V_35 ) , V_128 ) ;
F_115 ( V_52 , V_128 , V_125 ) ;
}
}
static void F_116 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
F_109 ( V_13 -> V_52 , V_10 , V_13 ) ;
F_117 ( V_13 -> V_89 , V_10 ) ;
F_118 ( V_13 -> V_89 , V_10 ) ;
F_109 ( V_13 -> V_2 -> V_52 , V_13 -> V_89 , NULL ) ;
}
static int F_119 ( struct V_9 * V_10 , int V_129 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
if ( V_13 -> V_89 -> V_130 < V_129 )
return - V_131 ;
V_10 -> V_130 = V_129 ;
return 0 ;
}
static int F_120 ( struct V_9 * V_10 )
{
return ( (struct V_12 * ) F_78 ( V_10 ) ) -> V_132 ;
}
static void F_121 ( struct V_9 * V_10 )
{
F_122 ( V_10 ) ;
F_123 ( & V_10 -> V_133 ,
& V_134 ,
F_120 ( V_10 ) ) ;
}
static int F_124 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
const struct V_9 * V_89 = V_13 -> V_89 ;
struct V_1 * V_2 = V_13 -> V_2 ;
V_10 -> V_135 = ( V_10 -> V_135 & ~ V_136 ) |
( V_89 -> V_135 & V_136 ) ;
V_10 -> V_105 = V_89 -> V_105 & V_137 ;
V_10 -> V_105 |= V_138 ;
V_10 -> V_139 |= V_140 ;
V_10 -> V_141 = V_89 -> V_141 & V_137 ;
V_10 -> V_141 |= V_142 ;
V_10 -> V_143 = V_89 -> V_143 ;
V_10 -> V_144 = V_89 -> V_144 ;
V_10 -> V_145 = V_89 -> V_145 ;
F_121 ( V_10 ) ;
V_13 -> V_96 = F_125 ( struct V_95 ) ;
if ( ! V_13 -> V_96 )
return - V_22 ;
V_2 -> V_146 += 1 ;
return 0 ;
}
static void F_126 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_127 ( V_13 -> V_96 ) ;
F_64 ( V_2 , V_13 ) ;
V_2 -> V_146 -= 1 ;
if ( ! V_2 -> V_146 )
F_128 ( V_2 -> V_10 ) ;
}
static void F_129 ( struct V_9 * V_10 ,
struct V_147 * V_148 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
if ( V_13 -> V_96 ) {
struct V_95 * V_120 ;
T_2 V_149 , V_150 , V_151 , V_98 , V_99 ;
T_1 V_152 = 0 , V_100 = 0 ;
unsigned int V_153 ;
int V_46 ;
F_130 (i) {
V_120 = F_131 ( V_13 -> V_96 , V_46 ) ;
do {
V_153 = F_132 ( & V_120 -> V_97 ) ;
V_149 = V_120 -> V_149 ;
V_150 = V_120 -> V_150 ;
V_151 = V_120 -> V_151 ;
V_98 = V_120 -> V_98 ;
V_99 = V_120 -> V_99 ;
} while ( F_133 ( & V_120 -> V_97 , V_153 ) );
V_148 -> V_149 += V_149 ;
V_148 -> V_150 += V_150 ;
V_148 -> V_154 += V_151 ;
V_148 -> V_98 += V_98 ;
V_148 -> V_99 += V_99 ;
V_152 += V_120 -> V_152 ;
V_100 += V_120 -> V_100 ;
}
V_148 -> V_152 = V_152 ;
V_148 -> V_71 = V_152 ;
V_148 -> V_100 = V_100 ;
}
}
static int F_134 ( struct V_9 * V_10 ,
T_5 V_155 , T_6 V_156 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_89 = V_13 -> V_89 ;
return F_135 ( V_89 , V_155 , V_156 ) ;
}
static int F_136 ( struct V_9 * V_10 ,
T_5 V_155 , T_6 V_156 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_89 = V_13 -> V_89 ;
F_137 ( V_89 , V_155 , V_156 ) ;
return 0 ;
}
static int F_138 ( struct V_157 * V_158 , struct V_159 * V_160 [] ,
struct V_9 * V_10 ,
const unsigned char * V_6 , T_6 V_156 ,
T_6 V_3 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
int V_47 = - V_131 ;
if ( ! F_1 ( V_13 -> V_2 ) && F_139 ( V_6 ) )
return - V_161 ;
if ( V_3 & V_162 )
return - V_161 ;
if ( F_139 ( V_6 ) )
V_47 = F_140 ( V_10 , V_6 ) ;
else if ( F_72 ( V_6 ) )
V_47 = F_141 ( V_10 , V_6 ) ;
return V_47 ;
}
static int F_142 ( struct V_157 * V_158 , struct V_159 * V_160 [] ,
struct V_9 * V_10 ,
const unsigned char * V_6 , T_6 V_156 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
int V_47 = - V_131 ;
if ( ! F_1 ( V_13 -> V_2 ) && F_139 ( V_6 ) )
return - V_161 ;
if ( F_139 ( V_6 ) )
V_47 = F_99 ( V_10 , V_6 ) ;
else if ( F_72 ( V_6 ) )
V_47 = F_143 ( V_10 , V_6 ) ;
return V_47 ;
}
static void F_144 ( struct V_9 * V_10 ,
struct V_163 * V_164 )
{
F_145 ( V_164 -> V_165 , L_1 , sizeof( V_164 -> V_165 ) ) ;
F_145 ( V_164 -> V_166 , L_2 , sizeof( V_164 -> V_166 ) ) ;
}
static int F_146 ( struct V_9 * V_10 ,
struct V_167 * V_168 )
{
const struct V_12 * V_13 = F_78 ( V_10 ) ;
return F_147 ( V_13 -> V_89 , V_168 ) ;
}
static T_7 F_148 ( struct V_9 * V_10 ,
T_7 V_105 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
T_7 V_169 = V_13 -> V_89 -> V_105 ;
T_7 V_170 ;
V_105 |= V_171 ;
V_105 &= ( V_13 -> V_172 | ~ V_137 ) ;
V_170 = V_105 ;
V_169 &= ( V_105 | ~ V_140 ) ;
V_105 = F_149 ( V_169 , V_105 , V_170 ) ;
V_105 |= V_138 ;
V_105 &= ~ V_173 ;
return V_105 ;
}
static void F_150 ( struct V_9 * V_10 )
{
return;
}
static int F_151 ( struct V_9 * V_10 , struct V_174 * V_175 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_9 * V_176 = V_13 -> V_89 ;
struct V_91 * V_91 ;
int V_47 = 0 ;
V_91 = F_152 ( sizeof( * V_91 ) , V_21 ) ;
V_47 = - V_22 ;
if ( ! V_91 )
goto V_82;
V_47 = F_153 ( V_91 , V_176 ) ;
if ( V_47 ) {
F_154 ( V_91 ) ;
goto V_82;
}
V_13 -> V_91 = V_91 ;
V_82:
return V_47 ;
}
static void F_155 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_91 * V_91 = V_13 -> V_91 ;
if ( ! V_91 )
return;
V_13 -> V_91 = NULL ;
F_156 ( V_91 ) ;
}
static int F_157 ( const struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
return V_13 -> V_89 -> V_177 ;
}
void F_158 ( struct V_9 * V_10 )
{
F_159 ( V_10 ) ;
V_10 -> V_178 = 0 ;
V_10 -> V_179 = V_180 ;
V_10 -> V_181 &= ~ V_182 ;
F_160 ( V_10 ) ;
V_10 -> V_181 |= V_183 ;
V_10 -> V_109 = & V_184 ;
V_10 -> V_185 = true ;
V_10 -> V_186 = & V_187 ;
V_10 -> V_188 = & V_189 ;
}
static void F_161 ( struct V_9 * V_10 )
{
F_158 ( V_10 ) ;
V_10 -> V_181 |= V_190 ;
}
static int F_162 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
unsigned int V_46 ;
int V_47 ;
if ( V_10 -> type != V_191 || V_10 -> V_3 & V_192 )
return - V_131 ;
if ( F_163 ( V_10 ) )
return - V_111 ;
V_2 = F_152 ( sizeof( * V_2 ) , V_21 ) ;
if ( V_2 == NULL )
return - V_22 ;
V_2 -> V_10 = V_10 ;
F_20 ( V_2 -> V_119 , V_10 -> V_15 ) ;
F_164 ( & V_2 -> V_84 ) ;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ )
F_165 ( & V_2 -> V_25 [ V_46 ] ) ;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ )
F_165 ( & V_2 -> V_20 [ V_46 ] ) ;
F_166 ( & V_2 -> V_64 ) ;
F_167 ( & V_2 -> V_61 , F_44 ) ;
V_47 = F_168 ( V_10 , F_71 , V_2 ) ;
if ( V_47 )
F_154 ( V_2 ) ;
else
V_10 -> V_181 |= V_193 ;
return V_47 ;
}
static void F_128 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_29 * V_30 ;
V_10 -> V_181 &= ~ V_193 ;
F_169 ( V_10 ) ;
F_170 ( & V_2 -> V_61 ) ;
while ( ( V_30 = F_50 ( & V_2 -> V_64 ) ) ) {
const struct V_12 * V_42 = F_51 ( V_30 ) -> V_42 ;
if ( V_42 )
F_54 ( V_42 -> V_10 ) ;
F_55 ( V_30 ) ;
}
if ( F_1 ( V_2 ) &&
! F_106 ( V_2 -> V_10 -> V_15 , V_2 -> V_119 ) ) {
struct V_121 V_194 ;
V_194 . V_195 = V_2 -> V_10 -> type ;
memcpy ( & V_194 . V_122 , V_2 -> V_119 , V_2 -> V_10 -> V_196 ) ;
F_107 ( V_2 -> V_10 , & V_194 ) ;
}
F_154 ( V_2 ) ;
}
static int F_171 ( struct V_159 * V_160 [] , struct V_159 * V_87 [] )
{
if ( V_160 [ V_197 ] ) {
if ( F_172 ( V_160 [ V_197 ] ) != V_28 )
return - V_131 ;
if ( ! F_105 ( F_173 ( V_160 [ V_197 ] ) ) )
return - V_123 ;
}
if ( V_87 && V_87 [ V_198 ] &&
F_174 ( V_87 [ V_198 ] ) & ~ V_103 )
return - V_131 ;
if ( V_87 && V_87 [ V_199 ] ) {
switch ( F_175 ( V_87 [ V_199 ] ) ) {
case V_66 :
case V_67 :
case V_55 :
case V_68 :
case V_200 :
break;
default:
return - V_131 ;
}
}
if ( V_87 && V_87 [ V_201 ] ) {
switch ( F_175 ( V_87 [ V_201 ] ) ) {
case V_202 :
case V_203 :
case V_204 :
case V_205 :
break;
default:
return - V_131 ;
}
}
if ( V_87 && V_87 [ V_206 ] ) {
if ( F_172 ( V_87 [ V_206 ] ) != V_28 )
return - V_131 ;
if ( ! F_105 ( F_173 ( V_87 [ V_206 ] ) ) )
return - V_123 ;
}
if ( V_87 && V_87 [ V_207 ] )
return - V_131 ;
return 0 ;
}
static int F_176 ( struct V_12 * V_13 , T_1 V_44 ,
struct V_159 * V_87 [] )
{
char * V_6 = NULL ;
int V_74 , V_208 , V_56 ;
struct V_159 * V_209 , * V_210 ;
struct V_16 * V_17 ;
if ( V_87 [ V_206 ] )
V_6 = F_173 ( V_87 [ V_206 ] ) ;
if ( V_44 == V_202 ) {
if ( ! V_6 )
return - V_131 ;
return F_18 ( V_13 , V_6 ) ;
} else if ( V_44 == V_203 ) {
if ( ! V_6 )
return - V_131 ;
V_17 = F_17 ( V_13 , V_6 ) ;
if ( V_17 ) {
F_23 ( V_17 ) ;
V_13 -> V_24 -- ;
}
} else if ( V_44 == V_204 ) {
F_64 ( V_13 -> V_2 , V_13 ) ;
} else if ( V_44 == V_205 ) {
F_64 ( V_13 -> V_2 , V_13 ) ;
if ( V_6 ) {
V_74 = F_18 ( V_13 , V_6 ) ;
if ( V_74 )
return V_74 ;
}
if ( ! V_87 || ! V_87 [ V_211 ] )
return 0 ;
V_210 = F_173 ( V_87 [ V_211 ] ) ;
V_56 = F_172 ( V_87 [ V_211 ] ) ;
F_177 (nla, head, len, rem) {
if ( F_178 ( V_209 ) != V_206 ||
F_172 ( V_209 ) != V_28 )
continue;
V_6 = F_173 ( V_209 ) ;
V_74 = F_18 ( V_13 , V_6 ) ;
if ( V_74 )
return V_74 ;
}
} else {
return - V_131 ;
}
return 0 ;
}
int F_179 ( struct V_212 * V_213 , struct V_9 * V_10 ,
struct V_159 * V_160 [] , struct V_159 * V_87 [] )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
struct V_1 * V_2 ;
struct V_9 * V_89 ;
int V_47 ;
int V_214 ;
bool V_215 = false ;
if ( ! V_160 [ V_216 ] )
return - V_131 ;
V_89 = F_180 ( V_213 , F_175 ( V_160 [ V_216 ] ) ) ;
if ( V_89 == NULL )
return - V_217 ;
if ( F_181 ( V_89 ) )
V_89 = F_182 ( V_89 ) ;
if ( ! V_160 [ V_218 ] )
V_10 -> V_130 = V_89 -> V_130 ;
else if ( V_10 -> V_130 > V_89 -> V_130 )
return - V_131 ;
V_10 -> V_178 = V_219 ;
V_10 -> V_179 = V_89 -> V_179 ;
if ( ! V_160 [ V_197 ] )
F_183 ( V_10 ) ;
if ( ! F_184 ( V_89 ) ) {
V_47 = F_162 ( V_89 ) ;
if ( V_47 < 0 )
return V_47 ;
V_215 = true ;
}
V_2 = F_12 ( V_89 ) ;
if ( F_1 ( V_2 ) ) {
V_47 = - V_131 ;
goto V_220;
}
V_13 -> V_89 = V_89 ;
V_13 -> V_10 = V_10 ;
V_13 -> V_2 = V_2 ;
V_13 -> V_172 = V_137 ;
V_13 -> V_132 = F_185 ( V_89 ) + 1 ;
V_13 -> V_44 = V_67 ;
if ( V_87 && V_87 [ V_199 ] )
V_13 -> V_44 = F_175 ( V_87 [ V_199 ] ) ;
if ( V_87 && V_87 [ V_198 ] )
V_13 -> V_3 = F_174 ( V_87 [ V_198 ] ) ;
if ( V_13 -> V_44 == V_68 ) {
if ( V_2 -> V_146 ) {
V_47 = - V_131 ;
goto V_220;
}
F_2 ( V_2 ) ;
F_186 ( V_10 , V_89 ) ;
}
if ( V_87 && V_87 [ V_201 ] ) {
if ( V_13 -> V_44 != V_200 ) {
V_47 = - V_131 ;
goto V_220;
}
V_214 = F_175 ( V_87 [ V_201 ] ) ;
V_47 = F_176 ( V_13 , V_214 , V_87 ) ;
if ( V_47 )
goto V_220;
}
V_47 = F_187 ( V_10 ) ;
if ( V_47 < 0 )
goto V_220;
V_10 -> V_181 |= V_221 ;
V_47 = F_188 ( V_89 , V_10 ) ;
if ( V_47 )
goto V_222;
F_189 ( & V_13 -> V_63 , & V_2 -> V_84 ) ;
F_190 ( V_89 , V_10 ) ;
F_191 ( V_10 ) ;
return 0 ;
V_222:
F_192 ( V_10 ) ;
V_220:
if ( V_215 )
F_128 ( V_2 -> V_10 ) ;
return V_47 ;
}
static int F_193 ( struct V_212 * V_213 , struct V_9 * V_10 ,
struct V_159 * V_160 [] , struct V_159 * V_87 [] )
{
return F_179 ( V_213 , V_10 , V_160 , V_87 ) ;
}
void F_194 ( struct V_9 * V_10 , struct V_223 * V_210 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
if ( V_13 -> V_44 == V_200 )
F_64 ( V_13 -> V_2 , V_13 ) ;
F_195 ( & V_13 -> V_63 ) ;
F_196 ( V_10 , V_210 ) ;
F_197 ( V_13 -> V_89 , V_10 ) ;
}
static int F_198 ( struct V_9 * V_10 ,
struct V_159 * V_160 [] , struct V_159 * V_87 [] )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
enum V_43 V_44 ;
bool V_224 = false ;
enum V_225 V_214 ;
int V_74 ;
if ( V_87 && V_87 [ V_199 ] ) {
V_224 = true ;
V_44 = F_175 ( V_87 [ V_199 ] ) ;
if ( ( V_44 == V_68 ) !=
( V_13 -> V_44 == V_68 ) )
return - V_131 ;
if ( V_13 -> V_44 == V_200 &&
V_13 -> V_44 != V_44 )
F_64 ( V_13 -> V_2 , V_13 ) ;
}
if ( V_87 && V_87 [ V_198 ] ) {
T_8 V_3 = F_174 ( V_87 [ V_198 ] ) ;
bool V_226 = ( V_3 ^ V_13 -> V_3 ) & V_103 ;
if ( F_1 ( V_13 -> V_2 ) && V_226 ) {
int V_47 ;
if ( V_3 & V_103 )
V_47 = F_95 ( V_13 -> V_89 , - 1 ) ;
else
V_47 = F_95 ( V_13 -> V_89 , 1 ) ;
if ( V_47 < 0 )
return V_47 ;
}
V_13 -> V_3 = V_3 ;
}
if ( V_224 )
V_13 -> V_44 = V_44 ;
if ( V_87 && V_87 [ V_201 ] ) {
if ( V_13 -> V_44 != V_200 )
return - V_131 ;
V_214 = F_175 ( V_87 [ V_201 ] ) ;
V_74 = F_176 ( V_13 , V_214 , V_87 ) ;
if ( V_74 )
return V_74 ;
}
return 0 ;
}
static T_9 F_199 ( const struct V_12 * V_13 )
{
if ( V_13 -> V_24 == 0 )
return 0 ;
return F_200 ( 0 )
+ V_13 -> V_24 * F_200 ( sizeof( V_227 ) * V_28 ) ;
}
static T_9 F_201 ( const struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
return ( 0
+ F_200 ( 4 )
+ F_200 ( 2 )
+ F_200 ( 4 )
+ F_199 ( V_13 )
) ;
}
static int F_202 ( struct V_29 * V_30 ,
const struct V_12 * V_13 ,
const int V_46 )
{
struct V_18 * V_19 = & V_13 -> V_2 -> V_20 [ V_46 ] ;
struct V_16 * V_17 ;
F_15 (entry, h, hlist) {
if ( V_17 -> V_13 != V_13 )
continue;
if ( F_203 ( V_30 , V_206 , V_28 , V_17 -> V_6 ) )
return 1 ;
}
return 0 ;
}
static int F_204 ( struct V_29 * V_30 ,
const struct V_9 * V_10 )
{
struct V_12 * V_13 = F_78 ( V_10 ) ;
int V_46 ;
struct V_159 * V_228 ;
if ( F_205 ( V_30 , V_199 , V_13 -> V_44 ) )
goto V_229;
if ( F_206 ( V_30 , V_198 , V_13 -> V_3 ) )
goto V_229;
if ( F_205 ( V_30 , V_207 , V_13 -> V_24 ) )
goto V_229;
if ( V_13 -> V_24 > 0 ) {
V_228 = F_207 ( V_30 , V_211 ) ;
if ( V_228 == NULL )
goto V_229;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ ) {
if ( F_202 ( V_30 , V_13 , V_46 ) )
goto V_229;
}
F_208 ( V_30 , V_228 ) ;
}
return 0 ;
V_229:
return - V_230 ;
}
int F_209 ( struct V_107 * V_231 )
{
V_231 -> V_232 = F_171 ;
V_231 -> V_233 = V_234 ;
V_231 -> V_235 = V_236 ;
V_231 -> V_237 = F_198 ;
V_231 -> V_238 = F_201 ;
V_231 -> V_239 = F_204 ;
return F_210 ( V_231 ) ;
}
static struct V_212 * F_211 ( const struct V_9 * V_10 )
{
return F_74 ( F_182 ( V_10 ) ) ;
}
static int F_212 ( struct V_240 * V_241 ,
unsigned long V_242 , void * V_243 )
{
struct V_9 * V_10 = F_213 ( V_243 ) ;
struct V_12 * V_13 , * V_244 ;
struct V_1 * V_2 ;
F_214 ( V_245 ) ;
if ( ! F_184 ( V_10 ) )
return V_246 ;
V_2 = F_12 ( V_10 ) ;
switch ( V_242 ) {
case V_247 :
case V_248 :
F_215 (vlan, &port->vlans, list)
F_190 ( V_13 -> V_89 ,
V_13 -> V_10 ) ;
break;
case V_249 :
F_215 (vlan, &port->vlans, list) {
V_13 -> V_10 -> V_143 = V_10 -> V_143 ;
V_13 -> V_10 -> V_144 = V_10 -> V_144 ;
F_216 ( V_13 -> V_10 ) ;
}
break;
case V_250 :
F_215 (vlan, &port->vlans, list) {
if ( V_13 -> V_10 -> V_130 <= V_10 -> V_130 )
continue;
F_217 ( V_13 -> V_10 , V_10 -> V_130 ) ;
}
break;
case V_251 :
if ( ! F_1 ( V_2 ) )
return V_246 ;
V_13 = F_218 ( & V_2 -> V_84 ,
struct V_12 ,
V_63 ) ;
if ( F_103 ( V_13 -> V_10 , V_10 -> V_15 ) )
return V_252 ;
break;
case V_253 :
if ( V_10 -> V_254 != V_255 )
break;
F_219 (vlan, next, &port->vlans, list)
V_13 -> V_10 -> V_107 -> V_256 ( V_13 -> V_10 , & V_245 ) ;
F_220 ( & V_245 ) ;
break;
case V_257 :
return V_252 ;
case V_258 :
case V_259 :
case V_260 :
F_215 (vlan, &port->vlans, list)
F_221 ( V_242 , V_13 -> V_10 ) ;
}
return V_246 ;
}
static int T_10 F_222 ( void )
{
int V_47 ;
F_223 ( & V_261 ) ;
V_47 = F_209 ( & V_108 ) ;
if ( V_47 < 0 )
goto V_262;
return 0 ;
V_262:
F_224 ( & V_261 ) ;
return V_47 ;
}
static void T_11 F_225 ( void )
{
F_226 ( & V_108 ) ;
F_224 ( & V_261 ) ;
}
