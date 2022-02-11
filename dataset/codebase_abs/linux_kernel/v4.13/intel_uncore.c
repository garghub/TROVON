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
F_5 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
F_6 ( V_6 , V_8 -> V_9 , V_6 -> V_10 . V_11 ) ;
}
static inline void
F_7 ( struct V_7 * V_8 )
{
V_8 -> V_12 ++ ;
F_8 ( & V_8 -> V_13 ,
V_14 ,
V_14 ,
V_15 ) ;
}
static inline void
F_9 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( F_10 ( ( F_11 ( V_6 , V_8 -> V_16 ) &
V_17 ) == 0 ,
V_18 ) )
F_12 ( L_2 ,
F_1 ( V_8 -> V_2 ) ) ;
}
static inline void
F_13 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
F_6 ( V_6 , V_8 -> V_9 , V_6 -> V_10 . V_19 ) ;
}
static inline void
F_14 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( F_10 ( ( F_11 ( V_6 , V_8 -> V_16 ) &
V_17 ) ,
V_18 ) )
F_12 ( L_3 ,
F_1 ( V_8 -> V_2 ) ) ;
}
static inline void
F_15 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
F_6 ( V_6 , V_8 -> V_9 , V_6 -> V_10 . V_20 ) ;
}
static void
F_16 ( struct V_5 * V_6 , enum V_21 V_22 )
{
struct V_7 * V_8 ;
unsigned int V_23 ;
F_17 ( V_22 & ~ V_6 -> V_10 . V_22 ) ;
F_18 (d, fw_domains, i915, tmp) {
F_9 ( V_6 , V_8 ) ;
F_13 ( V_6 , V_8 ) ;
}
F_18 (d, fw_domains, i915, tmp)
F_14 ( V_6 , V_8 ) ;
V_6 -> V_10 . V_24 |= V_22 ;
}
static void
F_19 ( struct V_5 * V_6 , enum V_21 V_22 )
{
struct V_7 * V_8 ;
unsigned int V_23 ;
F_17 ( V_22 & ~ V_6 -> V_10 . V_22 ) ;
F_18 (d, fw_domains, i915, tmp)
F_15 ( V_6 , V_8 ) ;
V_6 -> V_10 . V_24 &= ~ V_22 ;
}
static void
F_20 ( struct V_5 * V_6 ,
enum V_21 V_22 )
{
struct V_7 * V_8 ;
unsigned int V_23 ;
if ( ! V_22 )
return;
F_17 ( V_22 & ~ V_6 -> V_10 . V_22 ) ;
F_18 (d, fw_domains, i915, tmp)
F_5 ( V_6 , V_8 ) ;
}
static void F_21 ( struct V_5 * V_25 )
{
if ( F_22 ( ( F_11 ( V_25 , V_26 ) &
V_27 ) == 0 , 500 ) )
F_12 ( L_4 ) ;
}
static void F_23 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
F_16 ( V_25 , V_22 ) ;
F_21 ( V_25 ) ;
}
static inline T_1 F_24 ( struct V_5 * V_25 )
{
T_1 V_28 = F_11 ( V_25 , V_29 ) ;
return V_28 & V_30 ;
}
static void F_25 ( struct V_5 * V_25 )
{
T_1 V_31 ;
if ( F_26 ( V_25 ) )
V_31 = F_24 ( V_25 ) ;
else
V_31 = V_25 -> V_10 . V_32 ;
if ( V_31 <= V_33 ) {
if ( F_10 ( ( V_31 = F_24 ( V_25 ) ) >
V_33 ,
V_34 ) ) {
F_27 ( L_5 , V_31 ) ;
return;
}
}
V_25 -> V_10 . V_32 = V_31 - 1 ;
}
static enum V_35
F_28 ( struct V_36 * V_13 )
{
struct V_7 * V_37 =
F_29 ( V_13 , struct V_7 , V_13 ) ;
struct V_5 * V_25 =
F_29 ( V_37 , struct V_5 , V_10 . V_38 [ V_37 -> V_2 ] ) ;
unsigned long V_39 ;
F_30 ( V_25 ) ;
if ( F_31 ( & V_37 -> V_40 , false ) )
return V_41 ;
F_32 ( & V_25 -> V_10 . V_42 , V_39 ) ;
if ( F_4 ( V_37 -> V_12 == 0 ) )
V_37 -> V_12 ++ ;
if ( -- V_37 -> V_12 == 0 )
V_25 -> V_10 . V_43 . V_44 ( V_25 , V_37 -> V_45 ) ;
F_33 ( & V_25 -> V_10 . V_42 , V_39 ) ;
return V_46 ;
}
static void F_34 ( struct V_5 * V_25 ,
bool V_47 )
{
unsigned long V_39 ;
struct V_7 * V_37 ;
int V_48 = 100 ;
enum V_21 V_49 , V_50 ;
while ( 1 ) {
unsigned int V_23 ;
V_50 = 0 ;
F_35 (domain, dev_priv, tmp) {
F_36 ( V_37 -> V_40 , false ) ;
if ( F_37 ( & V_37 -> V_13 ) == 0 )
continue;
F_28 ( & V_37 -> V_13 ) ;
}
F_32 ( & V_25 -> V_10 . V_42 , V_39 ) ;
F_35 (domain, dev_priv, tmp) {
if ( F_38 ( & V_37 -> V_13 ) )
V_50 |= V_37 -> V_45 ;
}
if ( V_50 == 0 )
break;
if ( -- V_48 == 0 ) {
F_12 ( L_6 ) ;
break;
}
F_33 ( & V_25 -> V_10 . V_42 , V_39 ) ;
F_39 () ;
}
F_4 ( V_50 ) ;
V_49 = V_25 -> V_10 . V_24 ;
if ( V_49 )
V_25 -> V_10 . V_43 . V_44 ( V_25 , V_49 ) ;
F_20 ( V_25 , V_25 -> V_10 . V_22 ) ;
if ( V_47 ) {
if ( V_49 )
V_25 -> V_10 . V_43 . V_51 ( V_25 , V_49 ) ;
if ( F_40 ( V_25 ) || F_41 ( V_25 ) )
V_25 -> V_10 . V_32 =
F_24 ( V_25 ) ;
}
if ( ! V_47 )
F_42 ( V_25 ) ;
F_33 ( & V_25 -> V_10 . V_42 , V_39 ) ;
}
static T_2 F_43 ( struct V_5 * V_25 )
{
const unsigned int V_52 [ 8 ] = { 4 , 8 , 12 , 16 , 16 , 16 , 16 , 16 } ;
const unsigned int V_53 [ 4 ] = { 1 , 1 , 2 , 2 } ;
const T_1 V_54 = V_25 -> V_55 ;
return F_44 ( V_54 ) *
V_52 [ F_45 ( V_54 ) ] *
V_53 [ F_46 ( V_54 ) ] *
1024 * 1024 ;
}
T_2 F_47 ( struct V_5 * V_25 )
{
if ( ! F_48 ( V_25 ) )
return 0 ;
if ( F_49 ( V_25 ) < 9 )
return 128 * 1024 * 1024 ;
return F_43 ( V_25 ) ;
}
static void F_50 ( struct V_5 * V_25 )
{
if ( F_51 ( V_25 ) ||
F_52 ( V_25 ) ||
F_49 ( V_25 ) >= 9 ) {
V_25 -> V_55 = F_11 ( V_25 ,
V_56 ) ;
} else {
V_25 -> V_55 = 0 ;
}
if ( F_48 ( V_25 ) )
F_53 ( L_7 ,
F_47 ( V_25 ) / ( 1024 * 1024 ) ) ;
}
static bool
F_54 ( struct V_5 * V_25 )
{
T_1 V_57 ;
V_57 = F_11 ( V_25 , V_58 ) ;
if ( F_55 ( ! ( V_57 & V_59 ) ) )
return false ;
F_6 ( V_25 , V_58 , V_59 ) ;
return true ;
}
static bool
F_56 ( struct V_5 * V_25 )
{
T_1 V_60 ;
V_60 = F_11 ( V_25 , V_61 ) ;
if ( F_55 ( ! ( V_60 & ( V_62 | V_63 ) ) ) )
return false ;
F_6 ( V_25 , V_61 , V_64 ) ;
return true ;
}
static bool
F_57 ( struct V_5 * V_25 )
{
T_1 V_65 ;
V_65 = F_11 ( V_25 , V_66 ) ;
if ( F_58 ( V_65 ) ) {
F_59 ( L_8 , V_65 ) ;
F_6 ( V_25 , V_66 , V_65 ) ;
}
return V_65 ;
}
static bool
F_60 ( struct V_5 * V_25 )
{
bool V_67 = false ;
if ( F_61 ( V_25 ) )
V_67 |= F_54 ( V_25 ) ;
if ( F_26 ( V_25 ) || F_62 ( V_25 ) )
V_67 |= F_56 ( V_25 ) ;
if ( F_40 ( V_25 ) || F_41 ( V_25 ) )
V_67 |= F_57 ( V_25 ) ;
return V_67 ;
}
static void F_63 ( struct V_5 * V_25 ,
bool V_68 )
{
if ( F_60 ( V_25 ) )
F_27 ( L_9 ) ;
if ( F_62 ( V_25 ) ) {
F_6 ( V_25 , V_29 ,
F_11 ( V_25 , V_29 ) |
V_69 |
V_70 ) ;
}
F_34 ( V_25 , V_68 ) ;
}
void F_64 ( struct V_5 * V_25 )
{
F_65 (
& V_25 -> V_10 . V_71 ) ;
F_34 ( V_25 , false ) ;
}
void F_66 ( struct V_5 * V_25 )
{
F_63 ( V_25 , true ) ;
F_67 (
& V_25 -> V_10 . V_71 ) ;
F_68 ( V_25 ) ;
}
void F_69 ( struct V_5 * V_25 )
{
V_6 . V_72 = F_70 ( V_25 , V_6 . V_72 ) ;
F_71 ( V_25 ) ;
}
static void F_72 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
struct V_7 * V_37 ;
unsigned int V_23 ;
V_22 &= V_25 -> V_10 . V_22 ;
F_18 (domain, fw_domains, dev_priv, tmp) {
if ( V_37 -> V_12 ++ ) {
V_22 &= ~ V_37 -> V_45 ;
V_37 -> V_40 = true ;
}
}
if ( V_22 )
V_25 -> V_10 . V_43 . V_51 ( V_25 , V_22 ) ;
}
void F_73 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
unsigned long V_39 ;
if ( ! V_25 -> V_10 . V_43 . V_51 )
return;
F_74 ( V_25 ) ;
F_32 ( & V_25 -> V_10 . V_42 , V_39 ) ;
F_72 ( V_25 , V_22 ) ;
F_33 ( & V_25 -> V_10 . V_42 , V_39 ) ;
}
void F_75 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
F_76 ( & V_25 -> V_10 . V_42 ) ;
if ( ! V_25 -> V_10 . V_43 . V_51 )
return;
F_72 ( V_25 , V_22 ) ;
}
static void F_77 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
struct V_7 * V_37 ;
unsigned int V_23 ;
V_22 &= V_25 -> V_10 . V_22 ;
F_18 (domain, fw_domains, dev_priv, tmp) {
if ( F_4 ( V_37 -> V_12 == 0 ) )
continue;
if ( -- V_37 -> V_12 ) {
V_37 -> V_40 = true ;
continue;
}
F_7 ( V_37 ) ;
}
}
void F_78 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
unsigned long V_39 ;
if ( ! V_25 -> V_10 . V_43 . V_44 )
return;
F_32 ( & V_25 -> V_10 . V_42 , V_39 ) ;
F_77 ( V_25 , V_22 ) ;
F_33 ( & V_25 -> V_10 . V_42 , V_39 ) ;
}
void F_79 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
F_76 ( & V_25 -> V_10 . V_42 ) ;
if ( ! V_25 -> V_10 . V_43 . V_44 )
return;
F_77 ( V_25 , V_22 ) ;
}
void F_42 ( struct V_5 * V_25 )
{
if ( ! V_25 -> V_10 . V_43 . V_51 )
return;
F_4 ( V_25 -> V_10 . V_24 ) ;
}
static int F_80 ( T_1 V_73 , const struct V_74 * V_75 )
{
if ( V_73 < V_75 -> V_76 )
return - 1 ;
else if ( V_73 > V_75 -> V_77 )
return 1 ;
else
return 0 ;
}
static enum V_21
F_81 ( struct V_5 * V_25 , T_1 V_73 )
{
const struct V_74 * V_75 ;
V_75 = BSEARCH ( V_73 ,
V_25 -> V_10 . V_78 ,
V_25 -> V_10 . V_79 ,
F_80 ) ;
if ( ! V_75 )
return 0 ;
F_82 ( V_75 -> V_80 & ~ V_25 -> V_10 . V_22 ,
L_10 ,
V_75 -> V_80 & ~ V_25 -> V_10 . V_22 , V_73 ) ;
return V_75 -> V_80 ;
}
static int F_83 ( T_1 V_81 , const T_3 * V_82 )
{
T_1 V_73 = F_84 ( * V_82 ) ;
if ( V_81 < V_73 )
return - 1 ;
else if ( V_81 > V_73 )
return 1 ;
else
return 0 ;
}
static bool F_85 ( T_1 V_73 )
{
const T_3 * V_83 = V_84 ;
return BSEARCH ( V_73 , V_83 , F_3 ( V_84 ) ,
F_83 ) ;
}
static void
F_86 ( struct V_5 * V_25 )
{
F_6 ( V_25 , V_85 , 0 ) ;
}
static void
F_87 ( struct V_5 * V_25 ,
const T_3 V_82 ,
const bool V_86 ,
const bool V_87 )
{
if ( F_82 ( F_60 ( V_25 ) && ! V_87 ,
L_11 ,
V_86 ? L_12 : L_13 ,
F_84 ( V_82 ) ) )
V_6 . V_88 -- ;
}
static inline void
F_88 ( struct V_5 * V_25 ,
const T_3 V_82 ,
const bool V_86 ,
const bool V_87 )
{
if ( F_55 ( ! V_6 . V_88 ) )
return;
F_87 ( V_25 , V_82 , V_86 , V_87 ) ;
}
static T_4 void F_89 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
struct V_7 * V_37 ;
unsigned int V_23 ;
F_17 ( V_22 & ~ V_25 -> V_10 . V_22 ) ;
F_18 (domain, fw_domains, dev_priv, tmp)
F_7 ( V_37 ) ;
V_25 -> V_10 . V_43 . V_51 ( V_25 , V_22 ) ;
}
static inline void F_90 ( struct V_5 * V_25 ,
enum V_21 V_22 )
{
if ( F_4 ( ! V_22 ) )
return;
V_22 &= V_25 -> V_10 . V_22 ;
V_22 &= ~ V_25 -> V_10 . V_24 ;
if ( V_22 )
F_89 ( V_25 , V_22 ) ;
}
static void F_91 ( struct V_5 * V_25 ,
enum V_1 V_89 ,
T_3 V_9 ,
T_3 V_16 )
{
struct V_7 * V_8 ;
if ( F_4 ( V_89 >= V_4 ) )
return;
V_8 = & V_25 -> V_10 . V_38 [ V_89 ] ;
F_4 ( V_8 -> V_12 ) ;
F_4 ( ! F_92 ( V_9 ) ) ;
F_4 ( ! F_92 ( V_16 ) ) ;
V_8 -> V_12 = 0 ;
V_8 -> V_9 = V_9 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_2 = V_89 ;
F_2 ( V_90 != ( 1 << V_91 ) ) ;
F_2 ( V_92 != ( 1 << V_93 ) ) ;
F_2 ( V_94 != ( 1 << V_95 ) ) ;
V_8 -> V_45 = F_93 ( V_89 ) ;
F_94 ( & V_8 -> V_13 , V_96 , V_15 ) ;
V_8 -> V_13 . V_97 = F_28 ;
V_25 -> V_10 . V_22 |= F_93 ( V_89 ) ;
F_5 ( V_25 , V_8 ) ;
}
static void F_95 ( struct V_5 * V_25 )
{
if ( F_49 ( V_25 ) <= 5 || F_96 ( V_25 ) )
return;
if ( F_40 ( V_25 ) ) {
V_25 -> V_10 . V_11 = 0 ;
V_25 -> V_10 . V_19 = V_17 ;
V_25 -> V_10 . V_20 = 0 ;
} else {
V_25 -> V_10 . V_11 = F_97 ( 0xffff ) ;
V_25 -> V_10 . V_19 = F_98 ( V_17 ) ;
V_25 -> V_10 . V_20 = F_97 ( V_17 ) ;
}
if ( F_99 ( V_25 ) ) {
V_25 -> V_10 . V_43 . V_51 = F_16 ;
V_25 -> V_10 . V_43 . V_44 = F_19 ;
F_91 ( V_25 , V_91 ,
V_98 ,
V_99 ) ;
F_91 ( V_25 , V_93 ,
V_100 ,
V_101 ) ;
F_91 ( V_25 , V_95 ,
V_102 , V_103 ) ;
} else if ( F_26 ( V_25 ) || F_62 ( V_25 ) ) {
V_25 -> V_10 . V_43 . V_51 = F_16 ;
V_25 -> V_10 . V_43 . V_44 = F_19 ;
F_91 ( V_25 , V_91 ,
V_104 , V_105 ) ;
F_91 ( V_25 , V_95 ,
V_106 , V_107 ) ;
} else if ( F_51 ( V_25 ) || F_52 ( V_25 ) ) {
V_25 -> V_10 . V_43 . V_51 =
F_23 ;
V_25 -> V_10 . V_43 . V_44 = F_19 ;
F_91 ( V_25 , V_91 ,
V_108 , V_109 ) ;
} else if ( F_100 ( V_25 ) ) {
T_1 V_110 ;
V_25 -> V_10 . V_43 . V_51 =
F_23 ;
V_25 -> V_10 . V_43 . V_44 = F_19 ;
F_6 ( V_25 , V_111 , 0 ) ;
F_101 ( V_25 , V_112 ) ;
F_91 ( V_25 , V_91 ,
V_108 , V_113 ) ;
F_102 ( & V_25 -> V_10 . V_42 ) ;
F_23 ( V_25 , V_90 ) ;
V_110 = F_11 ( V_25 , V_112 ) ;
F_19 ( V_25 , V_90 ) ;
F_103 ( & V_25 -> V_10 . V_42 ) ;
if ( ! ( V_110 & V_114 ) ) {
F_53 ( L_14 ) ;
F_53 ( L_15 ) ;
F_91 ( V_25 , V_91 ,
V_111 , V_115 ) ;
}
} else if ( F_40 ( V_25 ) ) {
V_25 -> V_10 . V_43 . V_51 =
F_23 ;
V_25 -> V_10 . V_43 . V_44 = F_19 ;
F_91 ( V_25 , V_91 ,
V_111 , V_115 ) ;
}
F_4 ( V_25 -> V_10 . V_22 == 0 ) ;
}
static int F_104 ( struct V_116 * V_117 ,
unsigned long V_118 , void * V_119 )
{
struct V_5 * V_25 = F_29 ( V_117 ,
struct V_5 , V_10 . V_71 ) ;
switch ( V_118 ) {
case V_120 :
F_73 ( V_25 , V_121 ) ;
break;
case V_122 :
F_78 ( V_25 , V_121 ) ;
break;
}
return V_123 ;
}
void F_105 ( struct V_5 * V_25 )
{
F_106 ( V_25 ) ;
F_50 ( V_25 ) ;
F_95 ( V_25 ) ;
F_63 ( V_25 , false ) ;
V_25 -> V_10 . V_124 = 1 ;
V_25 -> V_10 . V_71 . V_125 =
F_104 ;
if ( F_107 ( V_25 , 2 , 4 ) || F_96 ( V_25 ) ) {
F_108 ( V_25 , V_126 ) ;
F_109 ( V_25 , V_126 ) ;
} else if ( F_110 ( V_25 ) ) {
F_108 ( V_25 , V_127 ) ;
F_109 ( V_25 , V_127 ) ;
} else if ( F_107 ( V_25 , 6 , 7 ) ) {
F_108 ( V_25 , V_128 ) ;
if ( F_26 ( V_25 ) ) {
F_111 ( V_129 ) ;
F_109 ( V_25 , V_130 ) ;
} else {
F_109 ( V_25 , V_128 ) ;
}
} else if ( F_112 ( V_25 ) ) {
if ( F_62 ( V_25 ) ) {
F_111 ( V_131 ) ;
F_108 ( V_25 , V_130 ) ;
F_109 ( V_25 , V_130 ) ;
} else {
F_108 ( V_25 , V_132 ) ;
F_109 ( V_25 , V_128 ) ;
}
} else {
F_111 ( V_133 ) ;
F_108 ( V_25 , V_130 ) ;
F_109 ( V_25 , V_130 ) ;
}
F_67 (
& V_25 -> V_10 . V_71 ) ;
F_68 ( V_25 ) ;
}
void F_113 ( struct V_5 * V_25 )
{
F_65 (
& V_25 -> V_10 . V_71 ) ;
F_69 ( V_25 ) ;
F_34 ( V_25 , false ) ;
}
int F_114 ( struct V_134 * V_135 ,
void * V_119 , struct V_136 * V_137 )
{
struct V_5 * V_25 = F_115 ( V_135 ) ;
struct V_138 * V_82 = V_119 ;
struct V_139 const * V_75 = V_140 ;
unsigned V_141 ;
T_3 V_142 , V_143 ;
int V_144 , V_67 = 0 ;
for ( V_144 = 0 ; V_144 < F_3 ( V_140 ) ; V_144 ++ , V_75 ++ ) {
if ( F_84 ( V_75 -> V_142 ) == ( V_82 -> V_73 & - V_75 -> V_141 ) &&
( F_116 ( V_25 ) -> V_145 & V_75 -> V_146 ) )
break;
}
if ( V_144 == F_3 ( V_140 ) )
return - V_147 ;
V_142 = V_75 -> V_142 ;
V_143 = V_75 -> V_143 ;
V_141 = V_75 -> V_141 ;
V_141 |= V_82 -> V_73 ^ F_84 ( V_142 ) ;
F_117 ( V_25 ) ;
switch ( V_141 ) {
case 8 | 1 :
V_82 -> V_148 = F_118 ( V_142 , V_143 ) ;
break;
case 8 :
V_82 -> V_148 = F_119 ( V_142 ) ;
break;
case 4 :
V_82 -> V_148 = F_120 ( V_142 ) ;
break;
case 2 :
V_82 -> V_148 = F_121 ( V_142 ) ;
break;
case 1 :
V_82 -> V_148 = F_122 ( V_142 ) ;
break;
default:
V_67 = - V_147 ;
goto V_149;
}
V_149:
F_123 ( V_25 ) ;
return V_67 ;
}
static void F_124 ( struct V_5 * V_25 )
{
struct V_150 * V_151 ;
enum V_152 V_2 ;
F_125 (engine, dev_priv, id) {
const T_1 V_153 = V_151 -> V_154 ;
const T_3 V_155 = F_126 ( V_153 ) ;
F_127 ( V_155 , F_98 ( V_156 ) ) ;
if ( F_128 ( V_25 ,
V_155 ,
V_157 ,
V_157 ,
500 ) )
F_59 ( L_16 ,
V_151 -> V_158 ) ;
F_127 ( F_129 ( V_153 ) , 0 ) ;
F_127 ( F_130 ( V_153 ) , 0 ) ;
F_127 ( F_131 ( V_153 ) , 0 ) ;
if ( F_132 ( F_130 ( V_153 ) ) != 0 )
F_59 ( L_17 ,
V_151 -> V_158 ) ;
}
}
static bool F_133 ( struct V_159 * V_160 )
{
T_5 V_161 ;
F_134 ( V_160 , V_162 , & V_161 ) ;
return ( V_161 & V_163 ) == 0 ;
}
static int F_135 ( struct V_5 * V_25 , unsigned V_164 )
{
struct V_159 * V_160 = V_25 -> V_165 . V_160 ;
F_136 ( V_160 , V_162 , V_166 ) ;
F_137 ( 50 , 200 ) ;
F_136 ( V_160 , V_162 , 0 ) ;
return F_138 ( F_133 ( V_160 ) , 500 ) ;
}
static bool F_139 ( struct V_159 * V_160 )
{
T_5 V_161 ;
F_134 ( V_160 , V_162 , & V_161 ) ;
return ( V_161 & V_166 ) == 0 ;
}
static int F_140 ( struct V_5 * V_25 , unsigned V_164 )
{
struct V_159 * V_160 = V_25 -> V_165 . V_160 ;
F_124 ( V_25 ) ;
F_136 ( V_160 , V_162 , V_166 ) ;
return F_138 ( F_139 ( V_160 ) , 500 ) ;
}
static int F_141 ( struct V_5 * V_25 , unsigned V_164 )
{
struct V_159 * V_160 = V_25 -> V_165 . V_160 ;
int V_67 ;
F_142 ( V_167 ,
F_120 ( V_167 ) | V_168 ) ;
F_143 ( V_167 ) ;
F_124 ( V_25 ) ;
F_136 ( V_160 , V_162 ,
V_169 | V_166 ) ;
V_67 = F_138 ( F_139 ( V_160 ) , 500 ) ;
if ( V_67 ) {
F_59 ( L_18 ) ;
goto V_149;
}
F_136 ( V_160 , V_162 ,
V_170 | V_166 ) ;
V_67 = F_138 ( F_139 ( V_160 ) , 500 ) ;
if ( V_67 ) {
F_59 ( L_19 ) ;
goto V_149;
}
V_149:
F_136 ( V_160 , V_162 , 0 ) ;
F_142 ( V_167 ,
F_120 ( V_167 ) & ~ V_168 ) ;
F_143 ( V_167 ) ;
return V_67 ;
}
static int F_144 ( struct V_5 * V_25 ,
unsigned V_164 )
{
int V_67 ;
F_142 ( V_171 , V_172 | V_173 ) ;
V_67 = F_145 ( V_25 ,
V_171 , V_173 , 0 ,
500 ) ;
if ( V_67 ) {
F_59 ( L_19 ) ;
goto V_149;
}
F_142 ( V_171 , V_174 | V_173 ) ;
V_67 = F_145 ( V_25 ,
V_171 , V_173 , 0 ,
500 ) ;
if ( V_67 ) {
F_59 ( L_18 ) ;
goto V_149;
}
V_149:
F_142 ( V_171 , 0 ) ;
F_143 ( V_171 ) ;
return V_67 ;
}
static int F_146 ( struct V_5 * V_25 ,
T_1 V_175 )
{
int V_176 ;
F_6 ( V_25 , V_177 , V_175 ) ;
V_176 = F_128 ( V_25 ,
V_177 , V_175 , 0 ,
500 ) ;
if ( V_176 )
F_59 ( L_20 ,
V_175 ) ;
return V_176 ;
}
static int F_147 ( struct V_5 * V_25 ,
unsigned V_164 )
{
struct V_150 * V_151 ;
const T_1 V_178 [ V_179 ] = {
[ V_180 ] = V_181 ,
[ V_182 ] = V_183 ,
[ V_184 ] = V_185 ,
[ V_186 ] = V_187 ,
[ V_188 ] = V_189 ,
} ;
T_1 V_190 ;
int V_67 ;
if ( V_164 == V_191 ) {
V_190 = V_192 ;
} else {
unsigned int V_23 ;
V_190 = 0 ;
F_148 (engine, dev_priv, engine_mask, tmp)
V_190 |= V_178 [ V_151 -> V_2 ] ;
}
V_67 = F_146 ( V_25 , V_190 ) ;
F_34 ( V_25 , true ) ;
return V_67 ;
}
int F_149 ( struct V_5 * V_25 ,
T_3 V_82 ,
T_1 V_45 ,
T_1 V_193 ,
unsigned int V_194 ,
unsigned int V_195 ,
T_1 * V_196 )
{
T_1 V_197 ( V_198 ) ;
#define F_150 (((reg_value = I915_READ_FW(reg)) & mask) == value)
int V_67 ;
F_151 ( V_195 ) ;
F_17 ( V_194 > 20000 ) ;
V_67 = - V_199 ;
if ( V_194 && V_194 <= 20000 )
V_67 = F_152 ( F_150 , V_194 , 0 ) ;
if ( V_67 && V_195 )
V_67 = F_138 ( F_150 , V_195 ) ;
if ( V_196 )
* V_196 = V_198 ;
return V_67 ;
#undef F_150
}
int F_145 ( struct V_5 * V_25 ,
T_3 V_82 ,
T_1 V_45 ,
T_1 V_193 ,
unsigned int V_200 )
{
unsigned V_49 =
F_153 ( V_25 , V_82 , V_201 ) ;
int V_67 ;
F_154 () ;
F_102 ( & V_25 -> V_10 . V_42 ) ;
F_75 ( V_25 , V_49 ) ;
V_67 = F_149 ( V_25 ,
V_82 , V_45 , V_193 ,
2 , 0 , NULL ) ;
F_79 ( V_25 , V_49 ) ;
F_103 ( & V_25 -> V_10 . V_42 ) ;
if ( V_67 )
V_67 = F_138 ( ( F_155 ( V_82 ) & V_45 ) == V_193 ,
V_200 ) ;
return V_67 ;
}
static int F_156 ( struct V_150 * V_151 )
{
struct V_5 * V_25 = V_151 -> V_6 ;
int V_67 ;
F_127 ( F_157 ( V_151 -> V_154 ) ,
F_98 ( V_202 ) ) ;
V_67 = F_128 ( V_25 ,
F_157 ( V_151 -> V_154 ) ,
V_203 ,
V_203 ,
700 ) ;
if ( V_67 )
F_12 ( L_21 , V_151 -> V_158 ) ;
return V_67 ;
}
static void F_158 ( struct V_150 * V_151 )
{
struct V_5 * V_25 = V_151 -> V_6 ;
F_127 ( F_157 ( V_151 -> V_154 ) ,
F_97 ( V_202 ) ) ;
}
static int F_159 ( struct V_5 * V_25 ,
unsigned V_164 )
{
struct V_150 * V_151 ;
unsigned int V_23 ;
F_148 (engine, dev_priv, engine_mask, tmp)
if ( F_156 ( V_151 ) )
goto V_204;
return F_147 ( V_25 , V_164 ) ;
V_204:
F_148 (engine, dev_priv, engine_mask, tmp)
F_158 ( V_151 ) ;
return - V_205 ;
}
static T_6 F_160 ( struct V_5 * V_25 )
{
if ( ! V_6 . V_206 )
return NULL ;
if ( F_116 ( V_25 ) -> V_207 >= 8 )
return F_159 ;
else if ( F_116 ( V_25 ) -> V_207 >= 6 )
return F_147 ;
else if ( F_110 ( V_25 ) )
return F_144 ;
else if ( F_161 ( V_25 ) )
return F_141 ;
else if ( F_162 ( V_25 ) || F_163 ( V_25 ) )
return F_140 ;
else if ( F_116 ( V_25 ) -> V_207 >= 3 )
return F_135 ;
else
return NULL ;
}
int F_164 ( struct V_5 * V_25 , unsigned V_164 )
{
T_6 V_206 ;
int V_208 ;
int V_67 ;
F_154 () ;
V_206 = F_160 ( V_25 ) ;
if ( V_206 == NULL )
return - V_209 ;
F_73 ( V_25 , V_121 ) ;
for ( V_208 = 0 ; V_208 < 3 ; V_208 ++ ) {
V_67 = V_206 ( V_25 , V_164 ) ;
if ( V_67 != - V_199 )
break;
F_39 () ;
}
F_78 ( V_25 , V_121 ) ;
return V_67 ;
}
bool F_165 ( struct V_5 * V_25 )
{
return F_160 ( V_25 ) != NULL ;
}
int F_166 ( struct V_5 * V_25 )
{
int V_67 ;
if ( ! F_167 ( V_25 ) )
return - V_147 ;
F_73 ( V_25 , V_121 ) ;
V_67 = F_146 ( V_25 , V_210 ) ;
F_78 ( V_25 , V_121 ) ;
return V_67 ;
}
bool F_168 ( struct V_5 * V_25 )
{
return F_60 ( V_25 ) ;
}
bool
F_169 ( struct V_5 * V_25 )
{
if ( F_58 ( V_6 . V_88 ||
V_25 -> V_10 . V_124 <= 0 ) )
return false ;
if ( F_58 ( F_168 ( V_25 ) ) ) {
F_27 ( L_22
L_23
L_24 ) ;
V_6 . V_88 ++ ;
V_25 -> V_10 . V_124 -- ;
return true ;
}
return false ;
}
static enum V_21
F_170 ( struct V_5 * V_25 ,
T_3 V_82 )
{
T_1 V_73 = F_84 ( V_82 ) ;
enum V_21 V_22 ;
if ( F_171 ( V_25 ) ) {
V_22 = F_172 ( V_73 ) ;
} else if ( F_49 ( V_25 ) >= 6 ) {
V_22 = F_173 ( V_73 ) ;
} else {
F_4 ( ! F_107 ( V_25 , 2 , 5 ) ) ;
V_22 = 0 ;
}
F_4 ( V_22 & ~ V_25 -> V_10 . V_22 ) ;
return V_22 ;
}
static enum V_21
F_174 ( struct V_5 * V_25 ,
T_3 V_82 )
{
T_1 V_73 = F_84 ( V_82 ) ;
enum V_21 V_22 ;
if ( F_171 ( V_25 ) && ! F_26 ( V_25 ) ) {
V_22 = F_175 ( V_73 ) ;
} else if ( F_112 ( V_25 ) ) {
V_22 = F_176 ( V_73 ) ;
} else if ( F_107 ( V_25 , 6 , 7 ) ) {
V_22 = V_90 ;
} else {
F_4 ( ! F_107 ( V_25 , 2 , 5 ) ) ;
V_22 = 0 ;
}
F_4 ( V_22 & ~ V_25 -> V_10 . V_22 ) ;
return V_22 ;
}
enum V_21
F_153 ( struct V_5 * V_25 ,
T_3 V_82 , unsigned int V_211 )
{
enum V_21 V_22 = 0 ;
F_4 ( ! V_211 ) ;
if ( F_96 ( V_25 ) )
return 0 ;
if ( V_211 & V_201 )
V_22 = F_170 ( V_25 , V_82 ) ;
if ( V_211 & V_212 )
V_22 |= F_174 ( V_25 , V_82 ) ;
return V_22 ;
}
