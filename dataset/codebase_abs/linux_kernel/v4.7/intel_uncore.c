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
F_10 ( 0 , V_12 ) ,
V_12 ,
V_13 ) ;
}
static inline void
F_11 ( const struct V_5 * V_6 )
{
if ( F_12 ( ( F_13 ( V_6 -> V_8 , V_6 -> V_14 ) &
V_15 ) == 0 ,
V_16 ) )
F_14 ( L_2 ,
F_1 ( V_6 -> V_2 ) ) ;
}
static inline void
F_15 ( const struct V_5 * V_6 )
{
F_7 ( V_6 -> V_8 , V_6 -> V_7 , V_6 -> V_17 ) ;
}
static inline void
F_16 ( const struct V_5 * V_6 )
{
if ( F_12 ( ( F_13 ( V_6 -> V_8 , V_6 -> V_14 ) &
V_15 ) ,
V_16 ) )
F_14 ( L_3 ,
F_1 ( V_6 -> V_2 ) ) ;
}
static inline void
F_17 ( const struct V_5 * V_6 )
{
F_7 ( V_6 -> V_8 , V_6 -> V_7 , V_6 -> V_18 ) ;
}
static inline void
F_18 ( const struct V_5 * V_6 )
{
if ( F_6 ( V_6 -> V_19 ) )
F_19 ( V_6 -> V_8 , V_6 -> V_19 ) ;
}
static void
F_20 ( struct V_20 * V_21 , enum V_22 V_23 )
{
struct V_5 * V_6 ;
F_21 (d, fw_domains, dev_priv) {
F_11 ( V_6 ) ;
F_15 ( V_6 ) ;
}
F_21 (d, fw_domains, dev_priv)
F_16 ( V_6 ) ;
}
static void
F_22 ( struct V_20 * V_21 , enum V_22 V_23 )
{
struct V_5 * V_6 ;
F_21 (d, fw_domains, dev_priv) {
F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
}
}
static void
F_23 ( struct V_20 * V_21 )
{
struct V_5 * V_6 ;
F_24 (d, dev_priv) {
F_18 ( V_6 ) ;
break;
}
}
static void
F_25 ( struct V_20 * V_21 , enum V_22 V_23 )
{
struct V_5 * V_6 ;
if ( V_21 -> V_24 . V_23 == 0 )
return;
F_21 (d, fw_domains, dev_priv)
F_5 ( V_6 ) ;
F_23 ( V_21 ) ;
}
static void F_26 ( struct V_20 * V_21 )
{
if ( F_27 ( ( F_13 ( V_21 , V_25 ) &
V_26 ) == 0 , 500 ) )
F_14 ( L_4 ) ;
}
static void F_28 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_20 ( V_21 , V_23 ) ;
F_26 ( V_21 ) ;
}
static void F_29 ( struct V_20 * V_21 )
{
T_1 V_27 ;
V_27 = F_13 ( V_21 , V_28 ) ;
if ( F_30 ( V_27 , L_5 , V_27 ) )
F_7 ( V_21 , V_28 , V_27 ) ;
}
static void F_31 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_22 ( V_21 , V_23 ) ;
F_29 ( V_21 ) ;
}
static inline T_1 F_32 ( struct V_20 * V_21 )
{
T_1 V_29 = F_13 ( V_21 , V_30 ) ;
return V_29 & V_31 ;
}
static int F_33 ( struct V_20 * V_21 )
{
int V_32 = 0 ;
if ( F_34 ( V_21 ) )
V_21 -> V_24 . V_33 = F_32 ( V_21 ) ;
if ( V_21 -> V_24 . V_33 < V_34 ) {
int V_35 = 500 ;
T_1 V_36 = F_32 ( V_21 ) ;
while ( V_36 <= V_34 && V_35 -- ) {
F_35 ( 10 ) ;
V_36 = F_32 ( V_21 ) ;
}
if ( F_4 ( V_35 < 0 && V_36 <= V_34 ) )
++ V_32 ;
V_21 -> V_24 . V_33 = V_36 ;
}
V_21 -> V_24 . V_33 -- ;
return V_32 ;
}
static enum V_37
F_36 ( struct V_38 * V_11 )
{
struct V_5 * V_39 =
F_37 ( V_11 , struct V_5 , V_11 ) ;
unsigned long V_40 ;
F_38 ( V_39 -> V_8 ) ;
F_39 ( & V_39 -> V_8 -> V_24 . V_41 , V_40 ) ;
if ( F_4 ( V_39 -> V_10 == 0 ) )
V_39 -> V_10 ++ ;
if ( -- V_39 -> V_10 == 0 )
V_39 -> V_8 -> V_24 . V_42 . V_43 ( V_39 -> V_8 ,
1 << V_39 -> V_2 ) ;
F_40 ( & V_39 -> V_8 -> V_24 . V_41 , V_40 ) ;
return V_44 ;
}
void F_41 ( struct V_45 * V_46 , bool V_47 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
unsigned long V_40 ;
struct V_5 * V_39 ;
int V_49 = 100 ;
enum V_22 V_50 = 0 , V_51 ;
while ( 1 ) {
V_51 = 0 ;
F_24 (domain, dev_priv) {
if ( F_42 ( & V_39 -> V_11 ) == 0 )
continue;
F_36 ( & V_39 -> V_11 ) ;
}
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_24 (domain, dev_priv) {
if ( F_43 ( & V_39 -> V_11 ) )
V_51 |= V_39 -> V_52 ;
}
if ( V_51 == 0 )
break;
if ( -- V_49 == 0 ) {
F_14 ( L_6 ) ;
break;
}
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_44 () ;
}
F_4 ( V_51 ) ;
F_24 (domain, dev_priv)
if ( V_39 -> V_10 )
V_50 |= V_39 -> V_52 ;
if ( V_50 )
V_21 -> V_24 . V_42 . V_43 ( V_21 , V_50 ) ;
F_25 ( V_21 , V_53 ) ;
if ( V_47 ) {
if ( V_50 )
V_21 -> V_24 . V_42 . V_54 ( V_21 , V_50 ) ;
if ( F_45 ( V_46 ) || F_46 ( V_46 ) )
V_21 -> V_24 . V_33 =
F_32 ( V_21 ) ;
}
if ( ! V_47 )
F_47 ( V_21 ) ;
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
}
static T_2 F_48 ( struct V_20 * V_21 )
{
const unsigned int V_55 [ 8 ] = { 4 , 8 , 12 , 16 , 16 , 16 , 16 , 16 } ;
const unsigned int V_56 [ 4 ] = { 1 , 1 , 2 , 2 } ;
const T_1 V_57 = V_21 -> V_58 ;
return F_49 ( V_57 ) *
V_55 [ F_50 ( V_57 ) ] *
V_56 [ F_51 ( V_57 ) ] *
1024 * 1024 ;
}
T_2 F_52 ( struct V_20 * V_21 )
{
if ( ! F_53 ( V_21 ) )
return 0 ;
if ( F_54 ( V_21 ) < 9 )
return 128 * 1024 * 1024 ;
return F_48 ( V_21 ) ;
}
static void F_55 ( struct V_20 * V_21 )
{
if ( F_56 ( V_21 ) ||
F_57 ( V_21 ) ||
F_54 ( V_21 ) >= 9 ) {
V_21 -> V_58 = F_13 ( V_21 ,
V_59 ) ;
} else {
V_21 -> V_58 = 0 ;
}
if ( F_53 ( V_21 ) )
F_58 ( L_7 ,
F_52 ( V_21 ) / ( 1024 * 1024 ) ) ;
}
static bool
F_59 ( struct V_20 * V_21 )
{
T_1 V_60 ;
V_60 = F_13 ( V_21 , V_61 ) ;
if ( F_60 ( ! ( V_60 & V_62 ) ) )
return false ;
F_7 ( V_21 , V_61 , V_62 ) ;
return true ;
}
static bool
F_61 ( struct V_20 * V_21 )
{
T_1 V_63 ;
V_63 = F_13 ( V_21 , V_64 ) ;
if ( F_60 ( ! ( V_63 & ( V_65 | V_66 ) ) ) )
return false ;
F_7 ( V_21 , V_64 , V_67 ) ;
return true ;
}
static bool
F_62 ( struct V_20 * V_21 )
{
if ( F_63 ( V_21 ) )
return F_59 ( V_21 ) ;
if ( F_34 ( V_21 ) || F_64 ( V_21 ) )
return F_61 ( V_21 ) ;
return false ;
}
static void F_65 ( struct V_45 * V_46 ,
bool V_68 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
if ( F_62 ( V_21 ) )
F_66 ( L_8 ) ;
if ( F_45 ( V_46 ) || F_46 ( V_46 ) )
F_7 ( V_21 , V_28 ,
F_13 ( V_21 , V_28 ) ) ;
if ( F_64 ( V_46 ) ) {
F_7 ( V_21 , V_30 ,
F_13 ( V_21 , V_30 ) |
V_69 |
V_70 ) ;
}
F_41 ( V_46 , V_68 ) ;
}
void F_67 ( struct V_45 * V_46 , bool V_68 )
{
F_65 ( V_46 , V_68 ) ;
F_68 ( V_46 ) ;
}
void F_69 ( struct V_45 * V_46 )
{
V_8 . V_71 = F_70 ( V_46 , V_8 . V_71 ) ;
F_71 ( V_46 ) ;
}
static void F_72 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
if ( ! V_21 -> V_24 . V_42 . V_54 )
return;
V_23 &= V_21 -> V_24 . V_23 ;
F_21 (domain, fw_domains, dev_priv) {
if ( V_39 -> V_10 ++ )
V_23 &= ~ V_39 -> V_52 ;
}
if ( V_23 )
V_21 -> V_24 . V_42 . V_54 ( V_21 , V_23 ) ;
}
void F_73 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
unsigned long V_40 ;
if ( ! V_21 -> V_24 . V_42 . V_54 )
return;
F_74 ( V_21 ) ;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_72 ( V_21 , V_23 ) ;
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
}
void F_75 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_76 ( & V_21 -> V_24 . V_41 ) ;
if ( ! V_21 -> V_24 . V_42 . V_54 )
return;
F_72 ( V_21 , V_23 ) ;
}
static void F_77 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
if ( ! V_21 -> V_24 . V_42 . V_43 )
return;
V_23 &= V_21 -> V_24 . V_23 ;
F_21 (domain, fw_domains, dev_priv) {
if ( F_4 ( V_39 -> V_10 == 0 ) )
continue;
if ( -- V_39 -> V_10 )
continue;
F_8 ( V_39 ) ;
}
}
void F_78 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
unsigned long V_40 ;
if ( ! V_21 -> V_24 . V_42 . V_43 )
return;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_77 ( V_21 , V_23 ) ;
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
}
void F_79 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
F_76 ( & V_21 -> V_24 . V_41 ) ;
if ( ! V_21 -> V_24 . V_42 . V_43 )
return;
F_77 ( V_21 , V_23 ) ;
}
void F_47 ( struct V_20 * V_21 )
{
struct V_5 * V_39 ;
if ( ! V_21 -> V_24 . V_42 . V_54 )
return;
F_24 (domain, dev_priv)
F_4 ( V_39 -> V_10 ) ;
}
static bool F_80 ( T_1 V_72 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < F_3 ( V_74 ) ; V_73 ++ )
if ( V_72 == V_74 [ V_73 ] . V_75 )
return true ;
return false ;
}
static bool F_81 ( T_1 V_72 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < F_3 ( V_76 ) ; V_73 ++ )
if ( V_72 == V_76 [ V_73 ] . V_75 )
return true ;
return false ;
}
static void
F_82 ( struct V_20 * V_21 )
{
F_7 ( V_21 , V_77 , 0 ) ;
}
static void
F_83 ( struct V_20 * V_21 ,
const T_3 V_75 ,
const bool V_78 ,
const bool V_79 )
{
if ( F_30 ( F_62 ( V_21 ) ,
L_9 ,
V_79 ? L_10 : L_11 ,
V_78 ? L_12 : L_13 ,
F_84 ( V_75 ) ) )
V_8 . V_80 -- ;
}
static inline void
F_85 ( struct V_20 * V_21 ,
const T_3 V_75 ,
const bool V_78 ,
const bool V_79 )
{
if ( F_60 ( ! V_8 . V_80 ) )
return;
F_83 ( V_21 , V_75 , V_78 , V_79 ) ;
}
static inline void F_86 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
if ( F_4 ( ! V_23 ) )
return;
F_21 (domain, fw_domains, dev_priv) {
if ( V_39 -> V_10 ) {
V_23 &= ~ V_39 -> V_52 ;
continue;
}
F_8 ( V_39 ) ;
}
if ( V_23 )
V_21 -> V_24 . V_42 . V_54 ( V_21 , V_23 ) ;
}
static void F_87 ( struct V_20 * V_21 ,
enum V_1 V_81 ,
T_3 V_7 ,
T_3 V_14 )
{
struct V_5 * V_6 ;
if ( F_4 ( V_81 >= V_4 ) )
return;
V_6 = & V_21 -> V_24 . V_82 [ V_81 ] ;
F_4 ( V_6 -> V_10 ) ;
V_6 -> V_10 = 0 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_14 = V_14 ;
if ( F_45 ( V_21 ) ) {
V_6 -> V_9 = 0 ;
V_6 -> V_17 = V_15 ;
V_6 -> V_18 = 0 ;
} else {
V_6 -> V_9 = F_88 ( 0xffff ) ;
V_6 -> V_17 = F_89 ( V_15 ) ;
V_6 -> V_18 = F_88 ( V_15 ) ;
}
if ( F_34 ( V_21 ) || F_64 ( V_21 ) )
V_6 -> V_19 = V_83 ;
else if ( F_45 ( V_21 ) || F_46 ( V_21 ) || F_90 ( V_21 ) )
V_6 -> V_19 = V_84 ;
V_6 -> V_8 = V_21 ;
V_6 -> V_2 = V_81 ;
F_2 ( V_85 != ( 1 << V_86 ) ) ;
F_2 ( V_87 != ( 1 << V_88 ) ) ;
F_2 ( V_89 != ( 1 << V_90 ) ) ;
V_6 -> V_52 = 1 << V_81 ;
F_91 ( & V_6 -> V_11 , V_91 , V_13 ) ;
V_6 -> V_11 . V_92 = F_36 ;
V_21 -> V_24 . V_23 |= ( 1 << V_81 ) ;
F_5 ( V_6 ) ;
}
static void F_92 ( struct V_45 * V_46 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
if ( F_93 ( V_21 ) -> V_93 <= 5 )
return;
if ( F_94 ( V_46 ) ) {
V_21 -> V_24 . V_42 . V_54 = F_20 ;
V_21 -> V_24 . V_42 . V_43 = F_22 ;
F_87 ( V_21 , V_86 ,
V_94 ,
V_95 ) ;
F_87 ( V_21 , V_88 ,
V_96 ,
V_97 ) ;
F_87 ( V_21 , V_90 ,
V_98 , V_99 ) ;
} else if ( F_34 ( V_46 ) || F_64 ( V_46 ) ) {
V_21 -> V_24 . V_42 . V_54 = F_20 ;
if ( ! F_64 ( V_46 ) )
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
else
V_21 -> V_24 . V_42 . V_43 = F_22 ;
F_87 ( V_21 , V_86 ,
V_100 , V_83 ) ;
F_87 ( V_21 , V_90 ,
V_101 , V_102 ) ;
} else if ( F_56 ( V_46 ) || F_57 ( V_46 ) ) {
V_21 -> V_24 . V_42 . V_54 =
F_28 ;
if ( F_56 ( V_46 ) )
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
else
V_21 -> V_24 . V_42 . V_43 = F_22 ;
F_87 ( V_21 , V_86 ,
V_103 , V_104 ) ;
} else if ( F_95 ( V_46 ) ) {
T_1 V_105 ;
V_21 -> V_24 . V_42 . V_54 =
F_28 ;
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
F_7 ( V_21 , V_106 , 0 ) ;
F_19 ( V_21 , V_84 ) ;
F_87 ( V_21 , V_86 ,
V_103 , V_107 ) ;
F_96 ( & V_46 -> V_108 ) ;
F_28 ( V_21 , V_53 ) ;
V_105 = F_13 ( V_21 , V_84 ) ;
F_31 ( V_21 , V_53 ) ;
F_97 ( & V_46 -> V_108 ) ;
if ( ! ( V_105 & V_109 ) ) {
F_58 ( L_14 ) ;
F_58 ( L_15 ) ;
F_87 ( V_21 , V_86 ,
V_106 , V_110 ) ;
}
} else if ( F_45 ( V_46 ) ) {
V_21 -> V_24 . V_42 . V_54 =
F_28 ;
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
F_87 ( V_21 , V_86 ,
V_106 , V_110 ) ;
}
F_4 ( V_21 -> V_24 . V_23 == 0 ) ;
}
void F_98 ( struct V_45 * V_46 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
F_99 ( V_46 ) ;
F_55 ( V_21 ) ;
F_92 ( V_46 ) ;
F_65 ( V_46 , false ) ;
V_21 -> V_24 . V_111 = 1 ;
switch ( F_93 ( V_46 ) -> V_93 ) {
default:
case 9 :
F_100 ( V_112 ) ;
F_101 ( V_112 ) ;
break;
case 8 :
if ( F_64 ( V_46 ) ) {
F_100 ( V_113 ) ;
F_101 ( V_113 ) ;
} else {
F_100 ( V_114 ) ;
F_101 ( V_115 ) ;
}
break;
case 7 :
case 6 :
if ( F_56 ( V_46 ) ) {
F_100 ( V_116 ) ;
} else {
F_100 ( V_115 ) ;
}
if ( F_34 ( V_46 ) ) {
F_101 ( V_117 ) ;
} else {
F_101 ( V_115 ) ;
}
break;
case 5 :
F_100 ( V_118 ) ;
F_101 ( V_118 ) ;
break;
case 4 :
case 3 :
case 2 :
F_100 ( V_119 ) ;
F_101 ( V_119 ) ;
break;
}
if ( F_102 ( V_46 ) ) {
F_100 ( V_120 ) ;
F_101 ( V_120 ) ;
}
F_68 ( V_46 ) ;
}
void F_103 ( struct V_45 * V_46 )
{
F_69 ( V_46 ) ;
F_41 ( V_46 , false ) ;
}
int F_104 ( struct V_45 * V_46 ,
void * V_121 , struct V_122 * V_123 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
struct V_124 * V_75 = V_121 ;
struct V_125 const * V_126 = V_127 ;
unsigned V_128 ;
T_3 V_129 , V_130 ;
int V_73 , V_32 = 0 ;
for ( V_73 = 0 ; V_73 < F_3 ( V_127 ) ; V_73 ++ , V_126 ++ ) {
if ( F_84 ( V_126 -> V_129 ) == ( V_75 -> V_72 & - V_126 -> V_128 ) &&
( 1 << F_93 ( V_46 ) -> V_93 & V_126 -> V_131 ) )
break;
}
if ( V_73 == F_3 ( V_127 ) )
return - V_132 ;
V_129 = V_126 -> V_129 ;
V_130 = V_126 -> V_130 ;
V_128 = V_126 -> V_128 ;
V_128 |= V_75 -> V_72 ^ F_84 ( V_129 ) ;
F_105 ( V_21 ) ;
switch ( V_128 ) {
case 8 | 1 :
V_75 -> V_133 = F_106 ( V_129 , V_130 ) ;
break;
case 8 :
V_75 -> V_133 = F_107 ( V_129 ) ;
break;
case 4 :
V_75 -> V_133 = F_108 ( V_129 ) ;
break;
case 2 :
V_75 -> V_133 = F_109 ( V_129 ) ;
break;
case 1 :
V_75 -> V_133 = F_110 ( V_129 ) ;
break;
default:
V_32 = - V_132 ;
goto V_134;
}
V_134:
F_111 ( V_21 ) ;
return V_32 ;
}
int F_112 ( struct V_45 * V_46 ,
void * V_121 , struct V_122 * V_123 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
struct V_135 * args = V_121 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
int V_32 ;
if ( args -> V_140 || args -> V_141 )
return - V_132 ;
if ( args -> V_142 == V_143 && ! F_113 ( V_144 ) )
return - V_145 ;
V_32 = F_114 ( & V_46 -> V_108 ) ;
if ( V_32 )
return V_32 ;
V_139 = F_115 ( V_123 -> V_146 , args -> V_142 ) ;
if ( F_116 ( V_139 ) ) {
F_97 ( & V_46 -> V_108 ) ;
return F_117 ( V_139 ) ;
}
V_137 = & V_139 -> V_147 ;
if ( F_113 ( V_144 ) )
args -> V_148 = F_118 ( & V_21 -> V_149 ) ;
else
args -> V_148 = 0 ;
args -> V_150 = V_137 -> V_150 ;
args -> V_151 = V_137 -> V_151 ;
F_97 ( & V_46 -> V_108 ) ;
return 0 ;
}
static int F_119 ( struct V_45 * V_46 )
{
T_4 V_152 ;
F_120 ( V_46 -> V_153 , V_154 , & V_152 ) ;
return ( V_152 & V_155 ) == 0 ;
}
static int F_121 ( struct V_45 * V_46 , unsigned V_156 )
{
F_122 ( V_46 -> V_153 , V_154 , V_157 ) ;
F_35 ( 20 ) ;
F_122 ( V_46 -> V_153 , V_154 , 0 ) ;
return F_123 ( F_119 ( V_46 ) , 500 ) ;
}
static int F_124 ( struct V_45 * V_46 )
{
T_4 V_152 ;
F_120 ( V_46 -> V_153 , V_154 , & V_152 ) ;
return ( V_152 & V_157 ) == 0 ;
}
static int F_125 ( struct V_45 * V_46 , unsigned V_156 )
{
F_122 ( V_46 -> V_153 , V_154 , V_157 ) ;
return F_123 ( F_124 ( V_46 ) , 500 ) ;
}
static int F_126 ( struct V_45 * V_46 , unsigned V_156 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
int V_32 ;
F_122 ( V_46 -> V_153 , V_154 ,
V_158 | V_157 ) ;
V_32 = F_123 ( F_124 ( V_46 ) , 500 ) ;
if ( V_32 )
return V_32 ;
F_127 ( V_159 , F_108 ( V_159 ) | V_160 ) ;
F_128 ( V_159 ) ;
F_122 ( V_46 -> V_153 , V_154 ,
V_161 | V_157 ) ;
V_32 = F_123 ( F_124 ( V_46 ) , 500 ) ;
if ( V_32 )
return V_32 ;
F_127 ( V_159 , F_108 ( V_159 ) & ~ V_160 ) ;
F_128 ( V_159 ) ;
F_122 ( V_46 -> V_153 , V_154 , 0 ) ;
return 0 ;
}
static int F_129 ( struct V_45 * V_46 , unsigned V_156 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
int V_32 ;
F_127 ( V_162 ,
V_163 | V_164 ) ;
V_32 = F_123 ( ( F_108 ( V_162 ) &
V_164 ) == 0 , 500 ) ;
if ( V_32 )
return V_32 ;
F_127 ( V_162 ,
V_165 | V_164 ) ;
V_32 = F_123 ( ( F_108 ( V_162 ) &
V_164 ) == 0 , 500 ) ;
if ( V_32 )
return V_32 ;
F_127 ( V_162 , 0 ) ;
return 0 ;
}
static int F_130 ( struct V_20 * V_21 ,
T_1 V_166 )
{
int V_32 ;
F_7 ( V_21 , V_167 , V_166 ) ;
#define F_131 ((__raw_i915_read32(dev_priv, GEN6_GDRST) & hw_domain_mask) == 0)
V_32 = F_123 ( F_131 , 500 ) ;
#undef F_131
return V_32 ;
}
static int F_132 ( struct V_45 * V_46 , unsigned V_156 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
struct V_168 * V_169 ;
const T_1 V_170 [ V_171 ] = {
[ V_172 ] = V_173 ,
[ V_174 ] = V_175 ,
[ V_176 ] = V_177 ,
[ V_178 ] = V_179 ,
[ V_180 ] = V_181 ,
} ;
T_1 V_182 ;
int V_32 ;
if ( V_156 == V_183 ) {
V_182 = V_184 ;
} else {
V_182 = 0 ;
F_133 (engine, dev_priv, engine_mask)
V_182 |= V_170 [ V_169 -> V_2 ] ;
}
V_32 = F_130 ( V_21 , V_182 ) ;
F_41 ( V_46 , true ) ;
return V_32 ;
}
static int F_134 ( struct V_20 * V_21 ,
T_3 V_75 ,
const T_1 V_52 ,
const T_1 V_185 ,
const unsigned long V_186 )
{
return F_123 ( ( F_135 ( V_75 ) & V_52 ) == V_185 , V_186 ) ;
}
static int F_136 ( struct V_168 * V_169 )
{
int V_32 ;
struct V_20 * V_21 = V_169 -> V_46 -> V_48 ;
F_137 ( F_138 ( V_169 -> V_187 ) ,
F_89 ( V_188 ) ) ;
V_32 = F_134 ( V_21 ,
F_138 ( V_169 -> V_187 ) ,
V_189 ,
V_189 ,
700 ) ;
if ( V_32 )
F_14 ( L_16 , V_169 -> V_190 ) ;
return V_32 ;
}
static void F_139 ( struct V_168 * V_169 )
{
struct V_20 * V_21 = V_169 -> V_46 -> V_48 ;
F_137 ( F_138 ( V_169 -> V_187 ) ,
F_88 ( V_188 ) ) ;
}
static int F_140 ( struct V_45 * V_46 , unsigned V_156 )
{
struct V_20 * V_21 = V_46 -> V_48 ;
struct V_168 * V_169 ;
F_133 (engine, dev_priv, engine_mask)
if ( F_136 ( V_169 ) )
goto V_191;
return F_132 ( V_46 , V_156 ) ;
V_191:
F_133 (engine, dev_priv, engine_mask)
F_139 ( V_169 ) ;
return - V_192 ;
}
bool F_141 ( struct V_45 * V_46 )
{
return F_142 ( V_46 ) != NULL ;
}
int F_143 ( struct V_20 * V_21 )
{
int V_32 ;
unsigned long V_40 ;
if ( ! V_8 . V_193 )
return - V_132 ;
F_73 ( V_21 , V_53 ) ;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
V_32 = F_130 ( V_21 , V_194 ) ;
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_78 ( V_21 , V_53 ) ;
return V_32 ;
}
bool F_144 ( struct V_20 * V_21 )
{
return F_62 ( V_21 ) ;
}
bool
F_145 ( struct V_20 * V_21 )
{
if ( F_146 ( V_8 . V_80 ||
V_21 -> V_24 . V_111 <= 0 ) )
return false ;
if ( F_146 ( F_144 ( V_21 ) ) ) {
F_66 ( L_17
L_18
L_19 ) ;
V_8 . V_80 ++ ;
V_21 -> V_24 . V_111 -- ;
return true ;
}
return false ;
}
static enum V_22
F_147 ( struct V_20 * V_21 ,
T_3 V_75 )
{
enum V_22 V_23 ;
if ( F_102 ( V_21 -> V_46 ) )
return 0 ;
switch ( F_93 ( V_21 ) -> V_93 ) {
case 9 :
V_23 = F_148 ( F_84 ( V_75 ) ) ;
break;
case 8 :
if ( F_64 ( V_21 ) )
V_23 = F_149 ( F_84 ( V_75 ) ) ;
else
V_23 = F_150 ( F_84 ( V_75 ) ) ;
break;
case 7 :
case 6 :
if ( F_34 ( V_21 ) )
V_23 = F_151 ( F_84 ( V_75 ) ) ;
else
V_23 = F_150 ( F_84 ( V_75 ) ) ;
break;
default:
F_152 ( F_93 ( V_21 ) -> V_93 ) ;
case 5 :
case 4 :
case 3 :
case 2 :
return 0 ;
}
F_4 ( V_23 & ~ V_21 -> V_24 . V_23 ) ;
return V_23 ;
}
static enum V_22
F_153 ( struct V_20 * V_21 ,
T_3 V_75 )
{
enum V_22 V_23 ;
if ( F_102 ( V_21 -> V_46 ) )
return 0 ;
switch ( F_93 ( V_21 ) -> V_93 ) {
case 9 :
V_23 = F_154 ( F_84 ( V_75 ) ) ;
break;
case 8 :
if ( F_64 ( V_21 ) )
V_23 = F_155 ( F_84 ( V_75 ) ) ;
else
V_23 = F_156 ( F_84 ( V_75 ) ) ;
break;
case 7 :
case 6 :
V_23 = V_85 ;
break;
default:
F_152 ( F_93 ( V_21 ) -> V_93 ) ;
case 5 :
case 4 :
case 3 :
case 2 :
return 0 ;
}
F_4 ( V_23 & ~ V_21 -> V_24 . V_23 ) ;
return V_23 ;
}
enum V_22
F_157 ( struct V_20 * V_21 ,
T_3 V_75 , unsigned int V_195 )
{
enum V_22 V_23 = 0 ;
F_4 ( ! V_195 ) ;
if ( V_195 & V_196 )
V_23 = F_147 ( V_21 , V_75 ) ;
if ( V_195 & V_197 )
V_23 |= F_153 ( V_21 , V_75 ) ;
return V_23 ;
}
