const char *
F_1 ( const enum V_1 V_2 )
{
F_2 ( F_3 ( V_3 ) != V_4 ) ;
if ( V_2 >= 0 && V_2 < V_4 )
return V_3 [ V_2 ] ;
F_4 ( V_2 ) ;
return L_1 ;
}
static inline void
F_5 ( const struct V_5 * V_6 )
{
F_4 ( ! F_6 ( V_6 -> V_7 ) ) ;
F_7 ( V_6 -> V_8 , V_6 -> V_7 , V_6 -> V_9 ) ;
}
static inline void
F_8 ( struct V_5 * V_6 )
{
V_6 -> V_10 ++ ;
F_9 ( & V_6 -> V_11 ,
V_12 ,
V_12 ,
V_13 ) ;
}
static inline void
F_10 ( const struct V_5 * V_6 )
{
if ( F_11 ( ( F_12 ( V_6 -> V_8 , V_6 -> V_14 ) &
V_15 ) == 0 ,
V_16 ) )
F_13 ( L_2 ,
F_1 ( V_6 -> V_2 ) ) ;
}
static inline void
F_14 ( const struct V_5 * V_6 )
{
F_7 ( V_6 -> V_8 , V_6 -> V_7 , V_6 -> V_17 ) ;
}
static inline void
F_15 ( const struct V_5 * V_6 )
{
if ( F_11 ( ( F_12 ( V_6 -> V_8 , V_6 -> V_14 ) &
V_15 ) ,
V_16 ) )
F_13 ( L_3 ,
F_1 ( V_6 -> V_2 ) ) ;
}
static inline void
F_16 ( const struct V_5 * V_6 )
{
F_7 ( V_6 -> V_8 , V_6 -> V_7 , V_6 -> V_18 ) ;
}
static inline void
F_17 ( const struct V_5 * V_6 )
{
if ( F_6 ( V_6 -> V_19 ) )
F_18 ( V_6 -> V_8 , V_6 -> V_19 ) ;
}
static void
F_19 ( struct V_20 * V_21 , enum V_22 V_23 )
{
struct V_5 * V_6 ;
F_20 (d, fw_domains, dev_priv) {
F_10 ( V_6 ) ;
F_14 ( V_6 ) ;
}
F_20 (d, fw_domains, dev_priv)
F_15 ( V_6 ) ;
}
static void
F_21 ( struct V_20 * V_21 , enum V_22 V_23 )
{
struct V_5 * V_6 ;
F_20 (d, fw_domains, dev_priv) {
F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
}
}
static void
F_22 ( struct V_20 * V_21 )
{
struct V_5 * V_6 ;
F_23 (d, dev_priv) {
F_17 ( V_6 ) ;
break;
}
}
static void
F_24 ( struct V_20 * V_21 , enum V_22 V_23 )
{
struct V_5 * V_6 ;
if ( V_21 -> V_24 . V_23 == 0 )
return;
F_20 (d, fw_domains, dev_priv)
F_5 ( V_6 ) ;
F_22 ( V_21 ) ;
}
static void F_25 ( struct V_20 * V_21 )
{
if ( F_26 ( ( F_12 ( V_21 , V_25 ) &
V_26 ) == 0 , 500 ) )
F_13 ( L_4 ) ;
}
static void F_27 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_19 ( V_21 , V_23 ) ;
F_25 ( V_21 ) ;
}
static void F_28 ( struct V_20 * V_21 )
{
T_1 V_27 ;
V_27 = F_12 ( V_21 , V_28 ) ;
if ( F_29 ( V_27 , L_5 , V_27 ) )
F_7 ( V_21 , V_28 , V_27 ) ;
}
static void F_30 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_21 ( V_21 , V_23 ) ;
F_28 ( V_21 ) ;
}
static inline T_1 F_31 ( struct V_20 * V_21 )
{
T_1 V_29 = F_12 ( V_21 , V_30 ) ;
return V_29 & V_31 ;
}
static int F_32 ( struct V_20 * V_21 )
{
int V_32 = 0 ;
if ( F_33 ( V_21 ) )
V_21 -> V_24 . V_33 = F_31 ( V_21 ) ;
if ( V_21 -> V_24 . V_33 < V_34 ) {
int V_35 = 500 ;
T_1 V_36 = F_31 ( V_21 ) ;
while ( V_36 <= V_34 && V_35 -- ) {
F_34 ( 10 ) ;
V_36 = F_31 ( V_21 ) ;
}
if ( F_4 ( V_35 < 0 && V_36 <= V_34 ) )
++ V_32 ;
V_21 -> V_24 . V_33 = V_36 ;
}
V_21 -> V_24 . V_33 -- ;
return V_32 ;
}
static enum V_37
F_35 ( struct V_38 * V_11 )
{
struct V_5 * V_39 =
F_36 ( V_11 , struct V_5 , V_11 ) ;
struct V_20 * V_21 = V_39 -> V_8 ;
unsigned long V_40 ;
F_37 ( V_21 ) ;
F_38 ( & V_21 -> V_24 . V_41 , V_40 ) ;
if ( F_4 ( V_39 -> V_10 == 0 ) )
V_39 -> V_10 ++ ;
if ( -- V_39 -> V_10 == 0 ) {
V_21 -> V_24 . V_42 . V_43 ( V_21 , V_39 -> V_44 ) ;
V_21 -> V_24 . V_45 &= ~ V_39 -> V_44 ;
}
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
return V_46 ;
}
void F_40 ( struct V_20 * V_21 ,
bool V_47 )
{
unsigned long V_40 ;
struct V_5 * V_39 ;
int V_48 = 100 ;
enum V_22 V_49 , V_50 ;
while ( 1 ) {
V_50 = 0 ;
F_23 (domain, dev_priv) {
if ( F_41 ( & V_39 -> V_11 ) == 0 )
continue;
F_35 ( & V_39 -> V_11 ) ;
}
F_38 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_23 (domain, dev_priv) {
if ( F_42 ( & V_39 -> V_11 ) )
V_50 |= V_39 -> V_44 ;
}
if ( V_50 == 0 )
break;
if ( -- V_48 == 0 ) {
F_13 ( L_6 ) ;
break;
}
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_43 () ;
}
F_4 ( V_50 ) ;
V_49 = V_21 -> V_24 . V_45 ;
if ( V_49 )
V_21 -> V_24 . V_42 . V_43 ( V_21 , V_49 ) ;
F_24 ( V_21 , V_51 ) ;
if ( V_47 ) {
if ( V_49 )
V_21 -> V_24 . V_42 . V_52 ( V_21 , V_49 ) ;
if ( F_44 ( V_21 ) || F_45 ( V_21 ) )
V_21 -> V_24 . V_33 =
F_31 ( V_21 ) ;
}
if ( ! V_47 )
F_46 ( V_21 ) ;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
}
static T_2 F_47 ( struct V_20 * V_21 )
{
const unsigned int V_53 [ 8 ] = { 4 , 8 , 12 , 16 , 16 , 16 , 16 , 16 } ;
const unsigned int V_54 [ 4 ] = { 1 , 1 , 2 , 2 } ;
const T_1 V_55 = V_21 -> V_56 ;
return F_48 ( V_55 ) *
V_53 [ F_49 ( V_55 ) ] *
V_54 [ F_50 ( V_55 ) ] *
1024 * 1024 ;
}
T_2 F_51 ( struct V_20 * V_21 )
{
if ( ! F_52 ( V_21 ) )
return 0 ;
if ( F_53 ( V_21 ) < 9 )
return 128 * 1024 * 1024 ;
return F_47 ( V_21 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
if ( F_55 ( V_21 ) ||
F_56 ( V_21 ) ||
F_53 ( V_21 ) >= 9 ) {
V_21 -> V_56 = F_12 ( V_21 ,
V_57 ) ;
} else {
V_21 -> V_56 = 0 ;
}
if ( F_52 ( V_21 ) )
F_57 ( L_7 ,
F_51 ( V_21 ) / ( 1024 * 1024 ) ) ;
}
static bool
F_58 ( struct V_20 * V_21 )
{
T_1 V_58 ;
V_58 = F_12 ( V_21 , V_59 ) ;
if ( F_59 ( ! ( V_58 & V_60 ) ) )
return false ;
F_7 ( V_21 , V_59 , V_60 ) ;
return true ;
}
static bool
F_60 ( struct V_20 * V_21 )
{
T_1 V_61 ;
V_61 = F_12 ( V_21 , V_62 ) ;
if ( F_59 ( ! ( V_61 & ( V_63 | V_64 ) ) ) )
return false ;
F_7 ( V_21 , V_62 , V_65 ) ;
return true ;
}
static bool
F_61 ( struct V_20 * V_21 )
{
if ( F_62 ( V_21 ) )
return F_58 ( V_21 ) ;
if ( F_33 ( V_21 ) || F_63 ( V_21 ) )
return F_60 ( V_21 ) ;
return false ;
}
static void F_64 ( struct V_20 * V_21 ,
bool V_66 )
{
struct V_67 * V_68 = F_65 ( V_21 ) ;
if ( F_61 ( V_21 ) )
F_66 ( L_8 ) ;
if ( F_44 ( V_21 ) || F_45 ( V_21 ) )
F_7 ( V_21 , V_28 ,
F_12 ( V_21 , V_28 ) ) ;
if ( F_63 ( V_21 ) ) {
F_7 ( V_21 , V_30 ,
F_12 ( V_21 , V_30 ) |
V_69 |
V_70 ) ;
}
if ( ! F_67 ( V_21 , V_71 , V_72 ) )
V_68 -> V_73 = false ;
F_40 ( V_21 , V_66 ) ;
}
void F_68 ( struct V_20 * V_21 ,
bool V_66 )
{
F_64 ( V_21 , V_66 ) ;
F_69 ( V_21 ) ;
}
void F_70 ( struct V_20 * V_21 )
{
V_8 . V_74 = F_71 ( V_21 , V_8 . V_74 ) ;
F_72 ( V_21 ) ;
}
static void F_73 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
V_23 &= V_21 -> V_24 . V_23 ;
F_20 (domain, fw_domains, dev_priv) {
if ( V_39 -> V_10 ++ )
V_23 &= ~ V_39 -> V_44 ;
}
if ( V_23 ) {
V_21 -> V_24 . V_42 . V_52 ( V_21 , V_23 ) ;
V_21 -> V_24 . V_45 |= V_23 ;
}
}
void F_74 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
unsigned long V_40 ;
if ( ! V_21 -> V_24 . V_42 . V_52 )
return;
F_75 ( V_21 ) ;
F_38 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_73 ( V_21 , V_23 ) ;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
}
void F_76 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_77 ( & V_21 -> V_24 . V_41 ) ;
if ( ! V_21 -> V_24 . V_42 . V_52 )
return;
F_73 ( V_21 , V_23 ) ;
}
static void F_78 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
V_23 &= V_21 -> V_24 . V_23 ;
F_20 (domain, fw_domains, dev_priv) {
if ( F_4 ( V_39 -> V_10 == 0 ) )
continue;
if ( -- V_39 -> V_10 )
continue;
F_8 ( V_39 ) ;
}
}
void F_79 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
unsigned long V_40 ;
if ( ! V_21 -> V_24 . V_42 . V_43 )
return;
F_38 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_78 ( V_21 , V_23 ) ;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
}
void F_80 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_77 ( & V_21 -> V_24 . V_41 ) ;
if ( ! V_21 -> V_24 . V_42 . V_43 )
return;
F_78 ( V_21 , V_23 ) ;
}
void F_46 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_24 . V_42 . V_52 )
return;
F_4 ( V_21 -> V_24 . V_45 ) ;
}
static int F_81 ( T_1 V_75 , const struct V_76 * V_77 )
{
if ( V_75 < V_77 -> V_78 )
return - 1 ;
else if ( V_75 > V_77 -> V_79 )
return 1 ;
else
return 0 ;
}
static enum V_22
F_82 ( struct V_20 * V_21 , T_1 V_75 )
{
const struct V_76 * V_77 ;
V_77 = BSEARCH ( V_75 ,
V_21 -> V_24 . V_80 ,
V_21 -> V_24 . V_81 ,
F_81 ) ;
return V_77 ? V_77 -> V_82 : 0 ;
}
static void
F_83 ( struct V_20 * V_21 )
{
const struct V_76 * V_83 ;
unsigned int V_84 ;
T_3 V_85 ;
unsigned int V_86 ;
if ( ! F_84 ( V_87 ) )
return;
V_83 = V_21 -> V_24 . V_80 ;
if ( ! V_83 )
return;
V_84 = V_21 -> V_24 . V_81 ;
for ( V_86 = 0 , V_85 = - 1 ; V_86 < V_84 ; V_86 ++ , V_83 ++ ) {
F_85 ( F_86 ( V_21 ) &&
( V_85 + 1 ) != ( T_3 ) V_83 -> V_78 ) ;
F_85 ( V_85 >= ( T_3 ) V_83 -> V_78 ) ;
V_85 = V_83 -> V_78 ;
F_85 ( V_85 >= ( T_3 ) V_83 -> V_79 ) ;
V_85 = V_83 -> V_79 ;
}
}
static void F_87 ( void )
{
const T_4 * V_88 = V_89 ;
T_3 V_85 ;
T_1 V_75 ;
unsigned int V_86 ;
if ( ! F_84 ( V_87 ) )
return;
for ( V_86 = 0 , V_85 = - 1 ; V_86 < F_3 ( V_89 ) ; V_86 ++ , V_88 ++ ) {
V_75 = F_88 ( * V_88 ) ;
F_85 ( V_85 >= ( T_3 ) V_75 ) ;
V_85 = V_75 ;
}
}
static int F_89 ( T_1 V_90 , const T_4 * V_88 )
{
T_1 V_75 = F_88 ( * V_88 ) ;
if ( V_90 < V_75 )
return - 1 ;
else if ( V_90 > V_75 )
return 1 ;
else
return 0 ;
}
static bool F_90 ( T_1 V_75 )
{
const T_4 * V_91 = V_89 ;
return BSEARCH ( V_75 , V_91 , F_3 ( V_89 ) ,
F_89 ) ;
}
static void
F_91 ( struct V_20 * V_21 )
{
F_7 ( V_21 , V_92 , 0 ) ;
}
static void
F_92 ( struct V_20 * V_21 ,
const T_4 V_88 ,
const bool V_93 ,
const bool V_94 )
{
if ( F_29 ( F_61 ( V_21 ) && ! V_94 ,
L_9 ,
V_93 ? L_10 : L_11 ,
F_88 ( V_88 ) ) )
V_8 . V_95 -- ;
}
static inline void
F_93 ( struct V_20 * V_21 ,
const T_4 V_88 ,
const bool V_93 ,
const bool V_94 )
{
if ( F_59 ( ! V_8 . V_95 ) )
return;
F_92 ( V_21 , V_88 , V_93 , V_94 ) ;
}
static void F_94 ( struct V_20 * V_21 ,
T_1 V_88 ,
enum V_22 V_96 ,
enum V_97 V_98 )
{
enum V_99 V_100 ;
T_1 V_101 = 0 ;
V_100 = V_102 [ V_96 - 1 ] ;
V_101 |= V_88 ;
V_101 |= ( V_98 << V_103 ) ;
V_101 |= ( V_100 << V_104 ) ;
V_101 |= V_105 ;
F_7 ( V_21 , V_106 , V_101 ) ;
if ( F_11 ( ( F_12 ( V_21 ,
V_106 ) &
V_105 ) == 0 ,
V_16 ) )
F_13 ( L_12 ) ;
}
static inline T_1
F_95 ( struct V_20 * V_21 ,
T_1 V_88 ,
enum V_22 V_96 )
{
F_94 ( V_21 , V_88 , V_96 ,
V_107 ) ;
return F_12 ( V_21 , V_108 ) ;
}
static inline void
F_96 ( struct V_20 * V_21 ,
T_1 V_88 , T_1 V_109 ,
enum V_22 V_96 )
{
F_7 ( V_21 , V_108 , V_109 ) ;
F_94 ( V_21 , V_88 , V_96 ,
V_110 ) ;
}
static T_5 void F_97 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
F_20 (domain, fw_domains, dev_priv)
F_8 ( V_39 ) ;
V_21 -> V_24 . V_42 . V_52 ( V_21 , V_23 ) ;
V_21 -> V_24 . V_45 |= V_23 ;
}
static inline void F_98 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
if ( F_4 ( ! V_23 ) )
return;
V_23 &= V_21 -> V_24 . V_23 ;
V_23 &= ~ V_21 -> V_24 . V_45 ;
if ( V_23 )
F_97 ( V_21 , V_23 ) ;
}
static void F_99 ( struct V_20 * V_21 ,
enum V_1 V_111 ,
T_4 V_7 ,
T_4 V_14 )
{
struct V_5 * V_6 ;
if ( F_4 ( V_111 >= V_4 ) )
return;
V_6 = & V_21 -> V_24 . V_96 [ V_111 ] ;
F_4 ( V_6 -> V_10 ) ;
V_6 -> V_10 = 0 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_14 = V_14 ;
if ( F_44 ( V_21 ) ) {
V_6 -> V_9 = 0 ;
V_6 -> V_17 = V_15 ;
V_6 -> V_18 = 0 ;
} else {
V_6 -> V_9 = F_100 ( 0xffff ) ;
V_6 -> V_17 = F_101 ( V_15 ) ;
V_6 -> V_18 = F_100 ( V_15 ) ;
}
if ( F_33 ( V_21 ) || F_63 ( V_21 ) )
V_6 -> V_19 = V_112 ;
else if ( F_44 ( V_21 ) || F_45 ( V_21 ) || F_102 ( V_21 ) )
V_6 -> V_19 = V_113 ;
V_6 -> V_8 = V_21 ;
V_6 -> V_2 = V_111 ;
F_2 ( V_114 != ( 1 << V_115 ) ) ;
F_2 ( V_116 != ( 1 << V_117 ) ) ;
F_2 ( V_118 != ( 1 << V_119 ) ) ;
V_6 -> V_44 = 1 << V_111 ;
F_103 ( & V_6 -> V_11 , V_120 , V_13 ) ;
V_6 -> V_11 . V_121 = F_35 ;
V_21 -> V_24 . V_23 |= ( 1 << V_111 ) ;
F_5 ( V_6 ) ;
}
static void F_104 ( struct V_20 * V_21 )
{
if ( F_105 ( V_21 ) -> V_122 <= 5 )
return;
if ( F_86 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_52 = F_19 ;
V_21 -> V_24 . V_42 . V_43 = F_21 ;
F_99 ( V_21 , V_115 ,
V_123 ,
V_124 ) ;
F_99 ( V_21 , V_117 ,
V_125 ,
V_126 ) ;
F_99 ( V_21 , V_119 ,
V_127 , V_128 ) ;
} else if ( F_33 ( V_21 ) || F_63 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_52 = F_19 ;
if ( ! F_63 ( V_21 ) )
V_21 -> V_24 . V_42 . V_43 =
F_30 ;
else
V_21 -> V_24 . V_42 . V_43 = F_21 ;
F_99 ( V_21 , V_115 ,
V_129 , V_112 ) ;
F_99 ( V_21 , V_119 ,
V_130 , V_131 ) ;
} else if ( F_55 ( V_21 ) || F_56 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_52 =
F_27 ;
if ( F_55 ( V_21 ) )
V_21 -> V_24 . V_42 . V_43 =
F_30 ;
else
V_21 -> V_24 . V_42 . V_43 = F_21 ;
F_99 ( V_21 , V_115 ,
V_132 , V_133 ) ;
} else if ( F_106 ( V_21 ) ) {
T_1 V_134 ;
V_21 -> V_24 . V_42 . V_52 =
F_27 ;
V_21 -> V_24 . V_42 . V_43 =
F_30 ;
F_7 ( V_21 , V_135 , 0 ) ;
F_18 ( V_21 , V_113 ) ;
F_99 ( V_21 , V_115 ,
V_132 , V_136 ) ;
F_107 ( & V_21 -> V_24 . V_41 ) ;
F_27 ( V_21 , V_51 ) ;
V_134 = F_12 ( V_21 , V_113 ) ;
F_30 ( V_21 , V_51 ) ;
F_108 ( & V_21 -> V_24 . V_41 ) ;
if ( ! ( V_134 & V_137 ) ) {
F_57 ( L_13 ) ;
F_57 ( L_14 ) ;
F_99 ( V_21 , V_115 ,
V_135 , V_138 ) ;
}
} else if ( F_44 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_52 =
F_27 ;
V_21 -> V_24 . V_42 . V_43 =
F_30 ;
F_99 ( V_21 , V_115 ,
V_135 , V_138 ) ;
}
F_4 ( V_21 -> V_24 . V_23 == 0 ) ;
}
void F_109 ( struct V_20 * V_21 )
{
F_110 ( V_21 ) ;
F_54 ( V_21 ) ;
F_104 ( V_21 ) ;
F_64 ( V_21 , false ) ;
V_21 -> V_24 . V_139 = 1 ;
switch ( F_105 ( V_21 ) -> V_122 ) {
default:
case 9 :
F_111 ( V_140 ) ;
F_112 ( V_141 ) ;
F_113 ( V_141 ) ;
if ( F_114 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_142 =
V_143 ;
V_21 -> V_24 . V_42 . V_144 =
V_145 ;
V_21 -> V_24 . V_42 . V_146 =
V_147 ;
}
break;
case 8 :
if ( F_63 ( V_21 ) ) {
F_111 ( V_148 ) ;
F_112 ( V_141 ) ;
F_113 ( V_141 ) ;
} else {
F_112 ( V_149 ) ;
F_113 ( V_150 ) ;
}
break;
case 7 :
case 6 :
F_112 ( V_150 ) ;
if ( F_33 ( V_21 ) ) {
F_111 ( V_151 ) ;
F_113 ( V_141 ) ;
} else {
F_113 ( V_150 ) ;
}
break;
case 5 :
F_112 ( V_152 ) ;
F_113 ( V_152 ) ;
break;
case 4 :
case 3 :
case 2 :
F_112 ( V_153 ) ;
F_113 ( V_153 ) ;
break;
}
F_83 ( V_21 ) ;
if ( F_53 ( V_21 ) >= 8 )
F_87 () ;
if ( F_115 ( V_21 ) ) {
F_112 ( V_154 ) ;
F_113 ( V_154 ) ;
}
F_69 ( V_21 ) ;
}
void F_116 ( struct V_20 * V_21 )
{
F_70 ( V_21 ) ;
F_40 ( V_21 , false ) ;
}
int F_117 ( struct V_155 * V_156 ,
void * V_109 , struct V_157 * V_158 )
{
struct V_20 * V_21 = F_118 ( V_156 ) ;
struct V_159 * V_88 = V_109 ;
struct V_160 const * V_77 = V_161 ;
unsigned V_162 ;
T_4 V_163 , V_164 ;
int V_86 , V_32 = 0 ;
for ( V_86 = 0 ; V_86 < F_3 ( V_161 ) ; V_86 ++ , V_77 ++ ) {
if ( F_88 ( V_77 -> V_163 ) == ( V_88 -> V_75 & - V_77 -> V_162 ) &&
( F_105 ( V_21 ) -> V_165 & V_77 -> V_166 ) )
break;
}
if ( V_86 == F_3 ( V_161 ) )
return - V_167 ;
V_163 = V_77 -> V_163 ;
V_164 = V_77 -> V_164 ;
V_162 = V_77 -> V_162 ;
V_162 |= V_88 -> V_75 ^ F_88 ( V_163 ) ;
F_119 ( V_21 ) ;
switch ( V_162 ) {
case 8 | 1 :
V_88 -> V_168 = F_120 ( V_163 , V_164 ) ;
break;
case 8 :
V_88 -> V_168 = F_121 ( V_163 ) ;
break;
case 4 :
V_88 -> V_168 = F_122 ( V_163 ) ;
break;
case 2 :
V_88 -> V_168 = F_123 ( V_163 ) ;
break;
case 1 :
V_88 -> V_168 = F_124 ( V_163 ) ;
break;
default:
V_32 = - V_167 ;
goto V_169;
}
V_169:
F_125 ( V_21 ) ;
return V_32 ;
}
static int F_126 ( struct V_170 * V_171 )
{
T_6 V_172 ;
F_127 ( V_171 , V_173 , & V_172 ) ;
return ( V_172 & V_174 ) == 0 ;
}
static int F_128 ( struct V_20 * V_21 , unsigned V_175 )
{
struct V_170 * V_171 = V_21 -> V_176 . V_171 ;
F_129 ( V_171 , V_173 , V_177 ) ;
F_34 ( 20 ) ;
F_129 ( V_171 , V_173 , 0 ) ;
return F_130 ( F_126 ( V_171 ) , 500 ) ;
}
static int F_131 ( struct V_170 * V_171 )
{
T_6 V_172 ;
F_127 ( V_171 , V_173 , & V_172 ) ;
return ( V_172 & V_177 ) == 0 ;
}
static int F_132 ( struct V_20 * V_21 , unsigned V_175 )
{
struct V_170 * V_171 = V_21 -> V_176 . V_171 ;
F_129 ( V_171 , V_173 , V_177 ) ;
return F_130 ( F_131 ( V_171 ) , 500 ) ;
}
static int F_133 ( struct V_20 * V_21 , unsigned V_175 )
{
struct V_170 * V_171 = V_21 -> V_176 . V_171 ;
int V_32 ;
F_129 ( V_171 , V_173 ,
V_178 | V_177 ) ;
V_32 = F_130 ( F_131 ( V_171 ) , 500 ) ;
if ( V_32 )
return V_32 ;
F_134 ( V_179 , F_122 ( V_179 ) | V_180 ) ;
F_135 ( V_179 ) ;
F_129 ( V_171 , V_173 ,
V_181 | V_177 ) ;
V_32 = F_130 ( F_131 ( V_171 ) , 500 ) ;
if ( V_32 )
return V_32 ;
F_134 ( V_179 , F_122 ( V_179 ) & ~ V_180 ) ;
F_135 ( V_179 ) ;
F_129 ( V_171 , V_173 , 0 ) ;
return 0 ;
}
static int F_136 ( struct V_20 * V_21 ,
unsigned V_175 )
{
int V_32 ;
F_134 ( V_182 ,
V_183 | V_184 ) ;
V_32 = F_137 ( V_21 ,
V_182 , V_184 , 0 ,
500 ) ;
if ( V_32 )
return V_32 ;
F_134 ( V_182 ,
V_185 | V_184 ) ;
V_32 = F_137 ( V_21 ,
V_182 , V_184 , 0 ,
500 ) ;
if ( V_32 )
return V_32 ;
F_134 ( V_182 , 0 ) ;
return 0 ;
}
static int F_138 ( struct V_20 * V_21 ,
T_1 V_186 )
{
F_7 ( V_21 , V_187 , V_186 ) ;
return F_139 ( V_21 ,
V_187 , V_186 , 0 ,
500 ) ;
}
static int F_140 ( struct V_20 * V_21 ,
unsigned V_175 )
{
struct V_188 * V_189 ;
const T_1 V_190 [ V_191 ] = {
[ V_192 ] = V_193 ,
[ V_194 ] = V_195 ,
[ V_196 ] = V_197 ,
[ V_198 ] = V_199 ,
[ V_200 ] = V_201 ,
} ;
T_1 V_202 ;
int V_32 ;
if ( V_175 == V_203 ) {
V_202 = V_204 ;
} else {
unsigned int V_205 ;
V_202 = 0 ;
F_141 (engine, dev_priv, engine_mask, tmp)
V_202 |= V_190 [ V_189 -> V_2 ] ;
}
V_32 = F_138 ( V_21 , V_202 ) ;
F_40 ( V_21 , true ) ;
return V_32 ;
}
int F_139 ( struct V_20 * V_21 ,
T_4 V_88 ,
const T_1 V_44 ,
const T_1 V_206 ,
const unsigned long V_207 )
{
#define F_142 ((I915_READ_FW(reg) & mask) == value)
int V_32 = F_143 ( F_142 , 2 ) ;
if ( V_32 )
V_32 = F_130 ( F_142 , V_207 ) ;
return V_32 ;
#undef F_142
}
int F_137 ( struct V_20 * V_21 ,
T_4 V_88 ,
const T_1 V_44 ,
const T_1 V_206 ,
const unsigned long V_207 )
{
unsigned V_49 =
F_144 ( V_21 , V_88 , V_208 ) ;
int V_32 ;
F_74 ( V_21 , V_49 ) ;
V_32 = F_143 ( ( F_145 ( V_88 ) & V_44 ) == V_206 , 2 ) ;
F_79 ( V_21 , V_49 ) ;
if ( V_32 )
V_32 = F_130 ( ( F_146 ( V_88 ) & V_44 ) == V_206 ,
V_207 ) ;
return V_32 ;
}
static int F_147 ( struct V_188 * V_189 )
{
struct V_20 * V_21 = V_189 -> V_8 ;
int V_32 ;
F_148 ( F_149 ( V_189 -> V_209 ) ,
F_101 ( V_210 ) ) ;
V_32 = F_139 ( V_21 ,
F_149 ( V_189 -> V_209 ) ,
V_211 ,
V_211 ,
700 ) ;
if ( V_32 )
F_13 ( L_15 , V_189 -> V_212 ) ;
return V_32 ;
}
static void F_150 ( struct V_188 * V_189 )
{
struct V_20 * V_21 = V_189 -> V_8 ;
F_148 ( F_149 ( V_189 -> V_209 ) ,
F_100 ( V_210 ) ) ;
}
static int F_151 ( struct V_20 * V_21 ,
unsigned V_175 )
{
struct V_188 * V_189 ;
unsigned int V_205 ;
F_141 (engine, dev_priv, engine_mask, tmp)
if ( F_147 ( V_189 ) )
goto V_213;
return F_140 ( V_21 , V_175 ) ;
V_213:
F_141 (engine, dev_priv, engine_mask, tmp)
F_150 ( V_189 ) ;
return - V_214 ;
}
static T_7 F_152 ( struct V_20 * V_21 )
{
if ( ! V_8 . V_215 )
return NULL ;
if ( F_105 ( V_21 ) -> V_122 >= 8 )
return F_151 ;
else if ( F_105 ( V_21 ) -> V_122 >= 6 )
return F_140 ;
else if ( F_153 ( V_21 ) )
return F_136 ;
else if ( F_154 ( V_21 ) )
return F_133 ;
else if ( F_155 ( V_21 ) )
return F_132 ;
else if ( F_105 ( V_21 ) -> V_122 >= 3 )
return F_128 ;
else
return NULL ;
}
int F_156 ( struct V_20 * V_21 , unsigned V_175 )
{
T_7 V_215 ;
int V_32 ;
V_215 = F_152 ( V_21 ) ;
if ( V_215 == NULL )
return - V_216 ;
F_74 ( V_21 , V_51 ) ;
V_32 = V_215 ( V_21 , V_175 ) ;
F_79 ( V_21 , V_51 ) ;
return V_32 ;
}
bool F_157 ( struct V_20 * V_21 )
{
return F_152 ( V_21 ) != NULL ;
}
int F_158 ( struct V_20 * V_21 )
{
int V_32 ;
unsigned long V_40 ;
if ( ! F_159 ( V_21 ) )
return - V_167 ;
F_74 ( V_21 , V_51 ) ;
F_38 ( & V_21 -> V_24 . V_41 , V_40 ) ;
V_32 = F_138 ( V_21 , V_217 ) ;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_79 ( V_21 , V_51 ) ;
return V_32 ;
}
bool F_160 ( struct V_20 * V_21 )
{
return F_61 ( V_21 ) ;
}
bool
F_161 ( struct V_20 * V_21 )
{
if ( F_162 ( V_8 . V_95 ||
V_21 -> V_24 . V_139 <= 0 ) )
return false ;
if ( F_162 ( F_160 ( V_21 ) ) ) {
F_66 ( L_16
L_17
L_18 ) ;
V_8 . V_95 ++ ;
V_21 -> V_24 . V_139 -- ;
return true ;
}
return false ;
}
static enum V_22
F_163 ( struct V_20 * V_21 ,
T_4 V_88 )
{
T_1 V_75 = F_88 ( V_88 ) ;
enum V_22 V_23 ;
if ( F_164 ( V_21 ) ) {
V_23 = F_165 ( V_75 ) ;
} else if ( F_53 ( V_21 ) >= 6 ) {
V_23 = F_166 ( V_75 ) ;
} else {
F_4 ( ! F_167 ( V_21 , 2 , 5 ) ) ;
V_23 = 0 ;
}
F_4 ( V_23 & ~ V_21 -> V_24 . V_23 ) ;
return V_23 ;
}
static enum V_22
F_168 ( struct V_20 * V_21 ,
T_4 V_88 )
{
T_1 V_75 = F_88 ( V_88 ) ;
enum V_22 V_23 ;
if ( F_164 ( V_21 ) && ! F_33 ( V_21 ) ) {
V_23 = F_169 ( V_75 ) ;
} else if ( F_102 ( V_21 ) ) {
V_23 = F_170 ( V_75 ) ;
} else if ( F_167 ( V_21 , 6 , 7 ) ) {
V_23 = V_114 ;
} else {
F_4 ( ! F_167 ( V_21 , 2 , 5 ) ) ;
V_23 = 0 ;
}
F_4 ( V_23 & ~ V_21 -> V_24 . V_23 ) ;
return V_23 ;
}
enum V_22
F_144 ( struct V_20 * V_21 ,
T_4 V_88 , unsigned int V_218 )
{
enum V_22 V_23 = 0 ;
F_4 ( ! V_218 ) ;
if ( F_115 ( V_21 ) )
return 0 ;
if ( V_218 & V_208 )
V_23 = F_163 ( V_21 , V_88 ) ;
if ( V_218 & V_219 )
V_23 |= F_168 ( V_21 , V_88 ) ;
return V_23 ;
}
