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
V_21 -> V_24 . V_25 |= V_23 ;
}
static void
F_21 ( struct V_20 * V_21 , enum V_22 V_23 )
{
struct V_5 * V_6 ;
F_20 (d, fw_domains, dev_priv) {
F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
}
V_21 -> V_24 . V_25 &= ~ V_23 ;
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
if ( F_26 ( ( F_12 ( V_21 , V_26 ) &
V_27 ) == 0 , 500 ) )
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
T_1 V_28 ;
V_28 = F_12 ( V_21 , V_29 ) ;
if ( F_29 ( V_28 , L_5 , V_28 ) )
F_7 ( V_21 , V_29 , V_28 ) ;
}
static void F_30 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_21 ( V_21 , V_23 ) ;
F_28 ( V_21 ) ;
}
static inline T_1 F_31 ( struct V_20 * V_21 )
{
T_1 V_30 = F_12 ( V_21 , V_31 ) ;
return V_30 & V_32 ;
}
static int F_32 ( struct V_20 * V_21 )
{
int V_33 = 0 ;
if ( F_33 ( V_21 ) )
V_21 -> V_24 . V_34 = F_31 ( V_21 ) ;
if ( V_21 -> V_24 . V_34 < V_35 ) {
int V_36 = 500 ;
T_1 V_37 = F_31 ( V_21 ) ;
while ( V_37 <= V_35 && V_36 -- ) {
F_34 ( 10 ) ;
V_37 = F_31 ( V_21 ) ;
}
if ( F_4 ( V_36 < 0 && V_37 <= V_35 ) )
++ V_33 ;
V_21 -> V_24 . V_34 = V_37 ;
}
V_21 -> V_24 . V_34 -- ;
return V_33 ;
}
static enum V_38
F_35 ( struct V_39 * V_11 )
{
struct V_5 * V_40 =
F_36 ( V_11 , struct V_5 , V_11 ) ;
struct V_20 * V_21 = V_40 -> V_8 ;
unsigned long V_41 ;
F_37 ( V_21 ) ;
F_38 ( & V_21 -> V_24 . V_42 , V_41 ) ;
if ( F_4 ( V_40 -> V_10 == 0 ) )
V_40 -> V_10 ++ ;
if ( -- V_40 -> V_10 == 0 )
V_21 -> V_24 . V_43 . V_44 ( V_21 , V_40 -> V_45 ) ;
F_39 ( & V_21 -> V_24 . V_42 , V_41 ) ;
return V_46 ;
}
void F_40 ( struct V_20 * V_21 ,
bool V_47 )
{
unsigned long V_41 ;
struct V_5 * V_40 ;
int V_48 = 100 ;
enum V_22 V_49 , V_50 ;
while ( 1 ) {
V_50 = 0 ;
F_23 (domain, dev_priv) {
if ( F_41 ( & V_40 -> V_11 ) == 0 )
continue;
F_35 ( & V_40 -> V_11 ) ;
}
F_38 ( & V_21 -> V_24 . V_42 , V_41 ) ;
F_23 (domain, dev_priv) {
if ( F_42 ( & V_40 -> V_11 ) )
V_50 |= V_40 -> V_45 ;
}
if ( V_50 == 0 )
break;
if ( -- V_48 == 0 ) {
F_13 ( L_6 ) ;
break;
}
F_39 ( & V_21 -> V_24 . V_42 , V_41 ) ;
F_43 () ;
}
F_4 ( V_50 ) ;
V_49 = V_21 -> V_24 . V_25 ;
if ( V_49 )
V_21 -> V_24 . V_43 . V_44 ( V_21 , V_49 ) ;
F_24 ( V_21 , V_51 ) ;
if ( V_47 ) {
if ( V_49 )
V_21 -> V_24 . V_43 . V_52 ( V_21 , V_49 ) ;
if ( F_44 ( V_21 ) || F_45 ( V_21 ) )
V_21 -> V_24 . V_34 =
F_31 ( V_21 ) ;
}
if ( ! V_47 )
F_46 ( V_21 ) ;
F_39 ( & V_21 -> V_24 . V_42 , V_41 ) ;
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
F_7 ( V_21 , V_29 ,
F_12 ( V_21 , V_29 ) ) ;
if ( F_63 ( V_21 ) ) {
F_7 ( V_21 , V_31 ,
F_12 ( V_21 , V_31 ) |
V_69 |
V_70 ) ;
}
if ( F_67 ( V_21 , 0 , V_71 ) )
V_68 -> V_72 = false ;
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
V_8 . V_73 = F_71 ( V_21 , V_8 . V_73 ) ;
F_72 ( V_21 ) ;
}
static void F_73 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_40 ;
V_23 &= V_21 -> V_24 . V_23 ;
F_20 (domain, fw_domains, dev_priv) {
if ( V_40 -> V_10 ++ )
V_23 &= ~ V_40 -> V_45 ;
}
if ( V_23 )
V_21 -> V_24 . V_43 . V_52 ( V_21 , V_23 ) ;
}
void F_74 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
unsigned long V_41 ;
if ( ! V_21 -> V_24 . V_43 . V_52 )
return;
F_75 ( V_21 ) ;
F_38 ( & V_21 -> V_24 . V_42 , V_41 ) ;
F_73 ( V_21 , V_23 ) ;
F_39 ( & V_21 -> V_24 . V_42 , V_41 ) ;
}
void F_76 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_77 ( & V_21 -> V_24 . V_42 ) ;
if ( ! V_21 -> V_24 . V_43 . V_52 )
return;
F_73 ( V_21 , V_23 ) ;
}
static void F_78 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_40 ;
V_23 &= V_21 -> V_24 . V_23 ;
F_20 (domain, fw_domains, dev_priv) {
if ( F_4 ( V_40 -> V_10 == 0 ) )
continue;
if ( -- V_40 -> V_10 )
continue;
F_8 ( V_40 ) ;
}
}
void F_79 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
unsigned long V_41 ;
if ( ! V_21 -> V_24 . V_43 . V_44 )
return;
F_38 ( & V_21 -> V_24 . V_42 , V_41 ) ;
F_78 ( V_21 , V_23 ) ;
F_39 ( & V_21 -> V_24 . V_42 , V_41 ) ;
}
void F_80 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_77 ( & V_21 -> V_24 . V_42 ) ;
if ( ! V_21 -> V_24 . V_43 . V_44 )
return;
F_78 ( V_21 , V_23 ) ;
}
void F_46 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_24 . V_43 . V_52 )
return;
F_4 ( V_21 -> V_24 . V_25 ) ;
}
static int F_81 ( T_1 V_74 , const struct V_75 * V_76 )
{
if ( V_74 < V_76 -> V_77 )
return - 1 ;
else if ( V_74 > V_76 -> V_78 )
return 1 ;
else
return 0 ;
}
static enum V_22
F_82 ( struct V_20 * V_21 , T_1 V_74 )
{
const struct V_75 * V_76 ;
V_76 = BSEARCH ( V_74 ,
V_21 -> V_24 . V_79 ,
V_21 -> V_24 . V_80 ,
F_81 ) ;
if ( ! V_76 )
return 0 ;
F_29 ( V_76 -> V_81 & ~ V_21 -> V_24 . V_23 ,
L_9 ,
V_76 -> V_81 & ~ V_21 -> V_24 . V_23 , V_74 ) ;
return V_76 -> V_81 ;
}
static void
F_83 ( struct V_20 * V_21 )
{
const struct V_75 * V_82 ;
unsigned int V_83 ;
T_3 V_84 ;
unsigned int V_85 ;
if ( ! F_84 ( V_86 ) )
return;
V_82 = V_21 -> V_24 . V_79 ;
if ( ! V_82 )
return;
V_83 = V_21 -> V_24 . V_80 ;
for ( V_85 = 0 , V_84 = - 1 ; V_85 < V_83 ; V_85 ++ , V_82 ++ ) {
F_85 ( F_86 ( V_21 ) &&
( V_84 + 1 ) != ( T_3 ) V_82 -> V_77 ) ;
F_85 ( V_84 >= ( T_3 ) V_82 -> V_77 ) ;
V_84 = V_82 -> V_77 ;
F_85 ( V_84 >= ( T_3 ) V_82 -> V_78 ) ;
V_84 = V_82 -> V_78 ;
}
}
static void F_87 ( void )
{
const T_4 * V_87 = V_88 ;
T_3 V_84 ;
T_1 V_74 ;
unsigned int V_85 ;
if ( ! F_84 ( V_86 ) )
return;
for ( V_85 = 0 , V_84 = - 1 ; V_85 < F_3 ( V_88 ) ; V_85 ++ , V_87 ++ ) {
V_74 = F_88 ( * V_87 ) ;
F_85 ( V_84 >= ( T_3 ) V_74 ) ;
V_84 = V_74 ;
}
}
static int F_89 ( T_1 V_89 , const T_4 * V_87 )
{
T_1 V_74 = F_88 ( * V_87 ) ;
if ( V_89 < V_74 )
return - 1 ;
else if ( V_89 > V_74 )
return 1 ;
else
return 0 ;
}
static bool F_90 ( T_1 V_74 )
{
const T_4 * V_90 = V_88 ;
return BSEARCH ( V_74 , V_90 , F_3 ( V_88 ) ,
F_89 ) ;
}
static void
F_91 ( struct V_20 * V_21 )
{
F_7 ( V_21 , V_91 , 0 ) ;
}
static void
F_92 ( struct V_20 * V_21 ,
const T_4 V_87 ,
const bool V_92 ,
const bool V_93 )
{
if ( F_29 ( F_61 ( V_21 ) && ! V_93 ,
L_10 ,
V_92 ? L_11 : L_12 ,
F_88 ( V_87 ) ) )
V_8 . V_94 -- ;
}
static inline void
F_93 ( struct V_20 * V_21 ,
const T_4 V_87 ,
const bool V_92 ,
const bool V_93 )
{
if ( F_59 ( ! V_8 . V_94 ) )
return;
F_92 ( V_21 , V_87 , V_92 , V_93 ) ;
}
static void F_94 ( struct V_20 * V_21 ,
T_1 V_87 ,
enum V_22 V_95 ,
enum V_96 V_97 )
{
enum V_98 V_99 ;
T_1 V_100 = 0 ;
V_99 = V_101 [ V_95 - 1 ] ;
V_100 |= V_87 ;
V_100 |= ( V_97 << V_102 ) ;
V_100 |= ( V_99 << V_103 ) ;
V_100 |= V_104 ;
F_7 ( V_21 , V_105 , V_100 ) ;
if ( F_11 ( ( F_12 ( V_21 ,
V_105 ) &
V_104 ) == 0 ,
V_16 ) )
F_13 ( L_13 ) ;
}
static inline T_1
F_95 ( struct V_20 * V_21 ,
T_1 V_87 ,
enum V_22 V_95 )
{
F_94 ( V_21 , V_87 , V_95 ,
V_106 ) ;
return F_12 ( V_21 , V_107 ) ;
}
static inline void
F_96 ( struct V_20 * V_21 ,
T_1 V_87 , T_1 V_108 ,
enum V_22 V_95 )
{
F_7 ( V_21 , V_107 , V_108 ) ;
F_94 ( V_21 , V_87 , V_95 ,
V_109 ) ;
}
static T_5 void F_97 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_40 ;
F_20 (domain, fw_domains, dev_priv)
F_8 ( V_40 ) ;
V_21 -> V_24 . V_43 . V_52 ( V_21 , V_23 ) ;
}
static inline void F_98 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
if ( F_4 ( ! V_23 ) )
return;
V_23 &= V_21 -> V_24 . V_23 ;
V_23 &= ~ V_21 -> V_24 . V_25 ;
if ( V_23 )
F_97 ( V_21 , V_23 ) ;
}
static void F_99 ( struct V_20 * V_21 ,
enum V_1 V_110 ,
T_4 V_7 ,
T_4 V_14 )
{
struct V_5 * V_6 ;
if ( F_4 ( V_110 >= V_4 ) )
return;
V_6 = & V_21 -> V_24 . V_95 [ V_110 ] ;
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
V_6 -> V_19 = V_111 ;
else if ( F_44 ( V_21 ) || F_45 ( V_21 ) || F_102 ( V_21 ) )
V_6 -> V_19 = V_112 ;
V_6 -> V_8 = V_21 ;
V_6 -> V_2 = V_110 ;
F_2 ( V_113 != ( 1 << V_114 ) ) ;
F_2 ( V_115 != ( 1 << V_116 ) ) ;
F_2 ( V_117 != ( 1 << V_118 ) ) ;
V_6 -> V_45 = 1 << V_110 ;
F_103 ( & V_6 -> V_11 , V_119 , V_13 ) ;
V_6 -> V_11 . V_120 = F_35 ;
V_21 -> V_24 . V_23 |= ( 1 << V_110 ) ;
F_5 ( V_6 ) ;
}
static void F_104 ( struct V_20 * V_21 )
{
if ( F_105 ( V_21 ) -> V_121 <= 5 )
return;
if ( F_86 ( V_21 ) ) {
V_21 -> V_24 . V_43 . V_52 = F_19 ;
V_21 -> V_24 . V_43 . V_44 = F_21 ;
F_99 ( V_21 , V_114 ,
V_122 ,
V_123 ) ;
F_99 ( V_21 , V_116 ,
V_124 ,
V_125 ) ;
F_99 ( V_21 , V_118 ,
V_126 , V_127 ) ;
} else if ( F_33 ( V_21 ) || F_63 ( V_21 ) ) {
V_21 -> V_24 . V_43 . V_52 = F_19 ;
if ( ! F_63 ( V_21 ) )
V_21 -> V_24 . V_43 . V_44 =
F_30 ;
else
V_21 -> V_24 . V_43 . V_44 = F_21 ;
F_99 ( V_21 , V_114 ,
V_128 , V_111 ) ;
F_99 ( V_21 , V_118 ,
V_129 , V_130 ) ;
} else if ( F_55 ( V_21 ) || F_56 ( V_21 ) ) {
V_21 -> V_24 . V_43 . V_52 =
F_27 ;
if ( F_55 ( V_21 ) )
V_21 -> V_24 . V_43 . V_44 =
F_30 ;
else
V_21 -> V_24 . V_43 . V_44 = F_21 ;
F_99 ( V_21 , V_114 ,
V_131 , V_132 ) ;
} else if ( F_106 ( V_21 ) ) {
T_1 V_133 ;
V_21 -> V_24 . V_43 . V_52 =
F_27 ;
V_21 -> V_24 . V_43 . V_44 =
F_30 ;
F_7 ( V_21 , V_134 , 0 ) ;
F_18 ( V_21 , V_112 ) ;
F_99 ( V_21 , V_114 ,
V_131 , V_135 ) ;
F_107 ( & V_21 -> V_24 . V_42 ) ;
F_27 ( V_21 , V_51 ) ;
V_133 = F_12 ( V_21 , V_112 ) ;
F_30 ( V_21 , V_51 ) ;
F_108 ( & V_21 -> V_24 . V_42 ) ;
if ( ! ( V_133 & V_136 ) ) {
F_57 ( L_14 ) ;
F_57 ( L_15 ) ;
F_99 ( V_21 , V_114 ,
V_134 , V_137 ) ;
}
} else if ( F_44 ( V_21 ) ) {
V_21 -> V_24 . V_43 . V_52 =
F_27 ;
V_21 -> V_24 . V_43 . V_44 =
F_30 ;
F_99 ( V_21 , V_114 ,
V_134 , V_137 ) ;
}
F_4 ( V_21 -> V_24 . V_23 == 0 ) ;
}
void F_109 ( struct V_20 * V_21 )
{
F_110 ( V_21 ) ;
F_54 ( V_21 ) ;
F_104 ( V_21 ) ;
F_64 ( V_21 , false ) ;
V_21 -> V_24 . V_138 = 1 ;
switch ( F_105 ( V_21 ) -> V_121 ) {
default:
case 9 :
F_111 ( V_139 ) ;
F_112 ( V_140 ) ;
F_113 ( V_140 ) ;
if ( F_114 ( V_21 ) ) {
V_21 -> V_24 . V_43 . V_141 =
V_142 ;
V_21 -> V_24 . V_43 . V_143 =
V_144 ;
V_21 -> V_24 . V_43 . V_145 =
V_146 ;
}
break;
case 8 :
if ( F_63 ( V_21 ) ) {
F_111 ( V_147 ) ;
F_112 ( V_140 ) ;
F_113 ( V_140 ) ;
} else {
F_112 ( V_148 ) ;
F_113 ( V_149 ) ;
}
break;
case 7 :
case 6 :
F_112 ( V_149 ) ;
if ( F_33 ( V_21 ) ) {
F_111 ( V_150 ) ;
F_113 ( V_140 ) ;
} else {
F_113 ( V_149 ) ;
}
break;
case 5 :
F_112 ( V_151 ) ;
F_113 ( V_151 ) ;
break;
case 4 :
case 3 :
case 2 :
F_112 ( V_152 ) ;
F_113 ( V_152 ) ;
break;
}
F_83 ( V_21 ) ;
if ( F_53 ( V_21 ) >= 8 )
F_87 () ;
if ( F_115 ( V_21 ) ) {
F_112 ( V_153 ) ;
F_113 ( V_153 ) ;
}
F_69 ( V_21 ) ;
}
void F_116 ( struct V_20 * V_21 )
{
F_70 ( V_21 ) ;
F_40 ( V_21 , false ) ;
}
int F_117 ( struct V_154 * V_155 ,
void * V_108 , struct V_156 * V_157 )
{
struct V_20 * V_21 = F_118 ( V_155 ) ;
struct V_158 * V_87 = V_108 ;
struct V_159 const * V_76 = V_160 ;
unsigned V_161 ;
T_4 V_162 , V_163 ;
int V_85 , V_33 = 0 ;
for ( V_85 = 0 ; V_85 < F_3 ( V_160 ) ; V_85 ++ , V_76 ++ ) {
if ( F_88 ( V_76 -> V_162 ) == ( V_87 -> V_74 & - V_76 -> V_161 ) &&
( F_105 ( V_21 ) -> V_164 & V_76 -> V_165 ) )
break;
}
if ( V_85 == F_3 ( V_160 ) )
return - V_166 ;
V_162 = V_76 -> V_162 ;
V_163 = V_76 -> V_163 ;
V_161 = V_76 -> V_161 ;
V_161 |= V_87 -> V_74 ^ F_88 ( V_162 ) ;
F_119 ( V_21 ) ;
switch ( V_161 ) {
case 8 | 1 :
V_87 -> V_167 = F_120 ( V_162 , V_163 ) ;
break;
case 8 :
V_87 -> V_167 = F_121 ( V_162 ) ;
break;
case 4 :
V_87 -> V_167 = F_122 ( V_162 ) ;
break;
case 2 :
V_87 -> V_167 = F_123 ( V_162 ) ;
break;
case 1 :
V_87 -> V_167 = F_124 ( V_162 ) ;
break;
default:
V_33 = - V_166 ;
goto V_168;
}
V_168:
F_125 ( V_21 ) ;
return V_33 ;
}
static int F_126 ( struct V_169 * V_170 )
{
T_6 V_171 ;
F_127 ( V_170 , V_172 , & V_171 ) ;
return ( V_171 & V_173 ) == 0 ;
}
static int F_128 ( struct V_20 * V_21 , unsigned V_174 )
{
struct V_169 * V_170 = V_21 -> V_175 . V_170 ;
F_129 ( V_170 , V_172 , V_176 ) ;
F_34 ( 20 ) ;
F_129 ( V_170 , V_172 , 0 ) ;
return F_130 ( F_126 ( V_170 ) , 500 ) ;
}
static int F_131 ( struct V_169 * V_170 )
{
T_6 V_171 ;
F_127 ( V_170 , V_172 , & V_171 ) ;
return ( V_171 & V_176 ) == 0 ;
}
static int F_132 ( struct V_20 * V_21 , unsigned V_174 )
{
struct V_169 * V_170 = V_21 -> V_175 . V_170 ;
F_129 ( V_170 , V_172 , V_176 ) ;
return F_130 ( F_131 ( V_170 ) , 500 ) ;
}
static int F_133 ( struct V_20 * V_21 , unsigned V_174 )
{
struct V_169 * V_170 = V_21 -> V_175 . V_170 ;
int V_33 ;
F_129 ( V_170 , V_172 ,
V_177 | V_176 ) ;
V_33 = F_130 ( F_131 ( V_170 ) , 500 ) ;
if ( V_33 )
return V_33 ;
F_134 ( V_178 , F_122 ( V_178 ) | V_179 ) ;
F_135 ( V_178 ) ;
F_129 ( V_170 , V_172 ,
V_180 | V_176 ) ;
V_33 = F_130 ( F_131 ( V_170 ) , 500 ) ;
if ( V_33 )
return V_33 ;
F_134 ( V_178 , F_122 ( V_178 ) & ~ V_179 ) ;
F_135 ( V_178 ) ;
F_129 ( V_170 , V_172 , 0 ) ;
return 0 ;
}
static int F_136 ( struct V_20 * V_21 ,
unsigned V_174 )
{
int V_33 ;
F_134 ( V_181 ,
V_182 | V_183 ) ;
V_33 = F_137 ( V_21 ,
V_181 , V_183 , 0 ,
500 ) ;
if ( V_33 )
return V_33 ;
F_134 ( V_181 ,
V_184 | V_183 ) ;
V_33 = F_137 ( V_21 ,
V_181 , V_183 , 0 ,
500 ) ;
if ( V_33 )
return V_33 ;
F_134 ( V_181 , 0 ) ;
return 0 ;
}
static int F_138 ( struct V_20 * V_21 ,
T_1 V_185 )
{
F_7 ( V_21 , V_186 , V_185 ) ;
return F_139 ( V_21 ,
V_186 , V_185 , 0 ,
500 ) ;
}
static int F_140 ( struct V_20 * V_21 ,
unsigned V_174 )
{
struct V_187 * V_188 ;
const T_1 V_189 [ V_190 ] = {
[ V_191 ] = V_192 ,
[ V_193 ] = V_194 ,
[ V_195 ] = V_196 ,
[ V_197 ] = V_198 ,
[ V_199 ] = V_200 ,
} ;
T_1 V_201 ;
int V_33 ;
if ( V_174 == V_202 ) {
V_201 = V_203 ;
} else {
unsigned int V_204 ;
V_201 = 0 ;
F_141 (engine, dev_priv, engine_mask, tmp)
V_201 |= V_189 [ V_188 -> V_2 ] ;
}
V_33 = F_138 ( V_21 , V_201 ) ;
F_40 ( V_21 , true ) ;
return V_33 ;
}
int F_139 ( struct V_20 * V_21 ,
T_4 V_87 ,
const T_1 V_45 ,
const T_1 V_205 ,
const unsigned long V_206 )
{
#define F_142 ((I915_READ_FW(reg) & mask) == value)
int V_33 = F_143 ( F_142 , 2 ) ;
if ( V_33 )
V_33 = F_130 ( F_142 , V_206 ) ;
return V_33 ;
#undef F_142
}
int F_137 ( struct V_20 * V_21 ,
T_4 V_87 ,
const T_1 V_45 ,
const T_1 V_205 ,
const unsigned long V_206 )
{
unsigned V_49 =
F_144 ( V_21 , V_87 , V_207 ) ;
int V_33 ;
F_74 ( V_21 , V_49 ) ;
V_33 = F_143 ( ( F_145 ( V_87 ) & V_45 ) == V_205 , 2 ) ;
F_79 ( V_21 , V_49 ) ;
if ( V_33 )
V_33 = F_130 ( ( F_146 ( V_87 ) & V_45 ) == V_205 ,
V_206 ) ;
return V_33 ;
}
static int F_147 ( struct V_187 * V_188 )
{
struct V_20 * V_21 = V_188 -> V_8 ;
int V_33 ;
F_148 ( F_149 ( V_188 -> V_208 ) ,
F_101 ( V_209 ) ) ;
V_33 = F_139 ( V_21 ,
F_149 ( V_188 -> V_208 ) ,
V_210 ,
V_210 ,
700 ) ;
if ( V_33 )
F_13 ( L_16 , V_188 -> V_211 ) ;
return V_33 ;
}
static void F_150 ( struct V_187 * V_188 )
{
struct V_20 * V_21 = V_188 -> V_8 ;
F_148 ( F_149 ( V_188 -> V_208 ) ,
F_100 ( V_209 ) ) ;
}
static int F_151 ( struct V_20 * V_21 ,
unsigned V_174 )
{
struct V_187 * V_188 ;
unsigned int V_204 ;
F_141 (engine, dev_priv, engine_mask, tmp)
if ( F_147 ( V_188 ) )
goto V_212;
return F_140 ( V_21 , V_174 ) ;
V_212:
F_141 (engine, dev_priv, engine_mask, tmp)
F_150 ( V_188 ) ;
return - V_213 ;
}
static T_7 F_152 ( struct V_20 * V_21 )
{
if ( ! V_8 . V_214 )
return NULL ;
if ( F_105 ( V_21 ) -> V_121 >= 8 )
return F_151 ;
else if ( F_105 ( V_21 ) -> V_121 >= 6 )
return F_140 ;
else if ( F_153 ( V_21 ) )
return F_136 ;
else if ( F_154 ( V_21 ) )
return F_133 ;
else if ( F_155 ( V_21 ) || F_156 ( V_21 ) )
return F_132 ;
else if ( F_105 ( V_21 ) -> V_121 >= 3 )
return F_128 ;
else
return NULL ;
}
int F_157 ( struct V_20 * V_21 , unsigned V_174 )
{
T_7 V_214 ;
int V_33 ;
V_214 = F_152 ( V_21 ) ;
if ( V_214 == NULL )
return - V_215 ;
F_74 ( V_21 , V_51 ) ;
V_33 = V_214 ( V_21 , V_174 ) ;
F_79 ( V_21 , V_51 ) ;
return V_33 ;
}
bool F_158 ( struct V_20 * V_21 )
{
return F_152 ( V_21 ) != NULL ;
}
int F_159 ( struct V_20 * V_21 )
{
int V_33 ;
unsigned long V_41 ;
if ( ! F_160 ( V_21 ) )
return - V_166 ;
F_74 ( V_21 , V_51 ) ;
F_38 ( & V_21 -> V_24 . V_42 , V_41 ) ;
V_33 = F_138 ( V_21 , V_216 ) ;
F_39 ( & V_21 -> V_24 . V_42 , V_41 ) ;
F_79 ( V_21 , V_51 ) ;
return V_33 ;
}
bool F_161 ( struct V_20 * V_21 )
{
return F_61 ( V_21 ) ;
}
bool
F_162 ( struct V_20 * V_21 )
{
if ( F_163 ( V_8 . V_94 ||
V_21 -> V_24 . V_138 <= 0 ) )
return false ;
if ( F_163 ( F_161 ( V_21 ) ) ) {
F_66 ( L_17
L_18
L_19 ) ;
V_8 . V_94 ++ ;
V_21 -> V_24 . V_138 -- ;
return true ;
}
return false ;
}
static enum V_22
F_164 ( struct V_20 * V_21 ,
T_4 V_87 )
{
T_1 V_74 = F_88 ( V_87 ) ;
enum V_22 V_23 ;
if ( F_165 ( V_21 ) ) {
V_23 = F_166 ( V_74 ) ;
} else if ( F_53 ( V_21 ) >= 6 ) {
V_23 = F_167 ( V_74 ) ;
} else {
F_4 ( ! F_168 ( V_21 , 2 , 5 ) ) ;
V_23 = 0 ;
}
F_4 ( V_23 & ~ V_21 -> V_24 . V_23 ) ;
return V_23 ;
}
static enum V_22
F_169 ( struct V_20 * V_21 ,
T_4 V_87 )
{
T_1 V_74 = F_88 ( V_87 ) ;
enum V_22 V_23 ;
if ( F_165 ( V_21 ) && ! F_33 ( V_21 ) ) {
V_23 = F_170 ( V_74 ) ;
} else if ( F_102 ( V_21 ) ) {
V_23 = F_171 ( V_74 ) ;
} else if ( F_168 ( V_21 , 6 , 7 ) ) {
V_23 = V_113 ;
} else {
F_4 ( ! F_168 ( V_21 , 2 , 5 ) ) ;
V_23 = 0 ;
}
F_4 ( V_23 & ~ V_21 -> V_24 . V_23 ) ;
return V_23 ;
}
enum V_22
F_144 ( struct V_20 * V_21 ,
T_4 V_87 , unsigned int V_217 )
{
enum V_22 V_23 = 0 ;
F_4 ( ! V_217 ) ;
if ( F_115 ( V_21 ) )
return 0 ;
if ( V_217 & V_207 )
V_23 = F_164 ( V_21 , V_87 ) ;
if ( V_217 & V_218 )
V_23 |= F_169 ( V_21 , V_87 ) ;
return V_23 ;
}
