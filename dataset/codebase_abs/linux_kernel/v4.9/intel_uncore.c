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
void F_41 ( struct V_20 * V_21 ,
bool V_45 )
{
unsigned long V_40 ;
struct V_5 * V_39 ;
int V_46 = 100 ;
enum V_22 V_47 = 0 , V_48 ;
while ( 1 ) {
V_48 = 0 ;
F_24 (domain, dev_priv) {
if ( F_42 ( & V_39 -> V_11 ) == 0 )
continue;
F_36 ( & V_39 -> V_11 ) ;
}
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_24 (domain, dev_priv) {
if ( F_43 ( & V_39 -> V_11 ) )
V_48 |= V_39 -> V_49 ;
}
if ( V_48 == 0 )
break;
if ( -- V_46 == 0 ) {
F_14 ( L_6 ) ;
break;
}
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_44 () ;
}
F_4 ( V_48 ) ;
F_24 (domain, dev_priv)
if ( V_39 -> V_10 )
V_47 |= V_39 -> V_49 ;
if ( V_47 )
V_21 -> V_24 . V_42 . V_43 ( V_21 , V_47 ) ;
F_25 ( V_21 , V_50 ) ;
if ( V_45 ) {
if ( V_47 )
V_21 -> V_24 . V_42 . V_51 ( V_21 , V_47 ) ;
if ( F_45 ( V_21 ) || F_46 ( V_21 ) )
V_21 -> V_24 . V_33 =
F_32 ( V_21 ) ;
}
if ( ! V_45 )
F_47 ( V_21 ) ;
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
}
static T_2 F_48 ( struct V_20 * V_21 )
{
const unsigned int V_52 [ 8 ] = { 4 , 8 , 12 , 16 , 16 , 16 , 16 , 16 } ;
const unsigned int V_53 [ 4 ] = { 1 , 1 , 2 , 2 } ;
const T_1 V_54 = V_21 -> V_55 ;
return F_49 ( V_54 ) *
V_52 [ F_50 ( V_54 ) ] *
V_53 [ F_51 ( V_54 ) ] *
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
V_21 -> V_55 = F_13 ( V_21 ,
V_56 ) ;
} else {
V_21 -> V_55 = 0 ;
}
if ( F_53 ( V_21 ) )
F_58 ( L_7 ,
F_52 ( V_21 ) / ( 1024 * 1024 ) ) ;
}
static bool
F_59 ( struct V_20 * V_21 )
{
T_1 V_57 ;
V_57 = F_13 ( V_21 , V_58 ) ;
if ( F_60 ( ! ( V_57 & V_59 ) ) )
return false ;
F_7 ( V_21 , V_58 , V_59 ) ;
return true ;
}
static bool
F_61 ( struct V_20 * V_21 )
{
T_1 V_60 ;
V_60 = F_13 ( V_21 , V_61 ) ;
if ( F_60 ( ! ( V_60 & ( V_62 | V_63 ) ) ) )
return false ;
F_7 ( V_21 , V_61 , V_64 ) ;
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
static void F_65 ( struct V_20 * V_21 ,
bool V_65 )
{
if ( F_62 ( V_21 ) )
F_66 ( L_8 ) ;
if ( F_45 ( V_21 ) || F_46 ( V_21 ) )
F_7 ( V_21 , V_28 ,
F_13 ( V_21 , V_28 ) ) ;
if ( F_64 ( V_21 ) ) {
F_7 ( V_21 , V_30 ,
F_13 ( V_21 , V_30 ) |
V_66 |
V_67 ) ;
}
F_41 ( V_21 , V_65 ) ;
}
void F_67 ( struct V_20 * V_21 ,
bool V_65 )
{
F_65 ( V_21 , V_65 ) ;
F_68 ( V_21 ) ;
}
void F_69 ( struct V_20 * V_21 )
{
V_8 . V_68 = F_70 ( V_21 , V_8 . V_68 ) ;
F_71 ( V_21 ) ;
}
static void F_72 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
if ( ! V_21 -> V_24 . V_42 . V_51 )
return;
V_23 &= V_21 -> V_24 . V_23 ;
F_21 (domain, fw_domains, dev_priv) {
if ( V_39 -> V_10 ++ )
V_23 &= ~ V_39 -> V_49 ;
}
if ( V_23 )
V_21 -> V_24 . V_42 . V_51 ( V_21 , V_23 ) ;
}
void F_73 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
unsigned long V_40 ;
if ( ! V_21 -> V_24 . V_42 . V_51 )
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
if ( ! V_21 -> V_24 . V_42 . V_51 )
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
if ( ! V_21 -> V_24 . V_42 . V_51 )
return;
F_24 (domain, dev_priv)
F_4 ( V_39 -> V_10 ) ;
}
static bool F_80 ( T_1 V_69 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_3 ( V_71 ) ; V_70 ++ )
if ( V_69 == V_71 [ V_70 ] . V_72 )
return true ;
return false ;
}
static bool F_81 ( T_1 V_69 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_3 ( V_73 ) ; V_70 ++ )
if ( V_69 == V_73 [ V_70 ] . V_72 )
return true ;
return false ;
}
static void
F_82 ( struct V_20 * V_21 )
{
F_7 ( V_21 , V_74 , 0 ) ;
}
static void
F_83 ( struct V_20 * V_21 ,
const T_3 V_72 ,
const bool V_75 ,
const bool V_76 )
{
if ( F_30 ( F_62 ( V_21 ) && ! V_76 ,
L_9 ,
V_75 ? L_10 : L_11 ,
F_84 ( V_72 ) ) )
V_8 . V_77 -- ;
}
static inline void
F_85 ( struct V_20 * V_21 ,
const T_3 V_72 ,
const bool V_75 ,
const bool V_76 )
{
if ( F_60 ( ! V_8 . V_77 ) )
return;
F_83 ( V_21 , V_72 , V_75 , V_76 ) ;
}
static inline void F_86 ( struct V_20 * V_21 ,
enum V_22 V_23 )
{
struct V_5 * V_39 ;
if ( F_4 ( ! V_23 ) )
return;
F_21 (domain, fw_domains, dev_priv) {
if ( V_39 -> V_10 ) {
V_23 &= ~ V_39 -> V_49 ;
continue;
}
F_8 ( V_39 ) ;
}
if ( V_23 )
V_21 -> V_24 . V_42 . V_51 ( V_21 , V_23 ) ;
}
static void F_87 ( struct V_20 * V_21 ,
enum V_1 V_78 ,
T_3 V_7 ,
T_3 V_14 )
{
struct V_5 * V_6 ;
if ( F_4 ( V_78 >= V_4 ) )
return;
V_6 = & V_21 -> V_24 . V_79 [ V_78 ] ;
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
V_6 -> V_19 = V_80 ;
else if ( F_45 ( V_21 ) || F_46 ( V_21 ) || F_90 ( V_21 ) )
V_6 -> V_19 = V_81 ;
V_6 -> V_8 = V_21 ;
V_6 -> V_2 = V_78 ;
F_2 ( V_82 != ( 1 << V_83 ) ) ;
F_2 ( V_84 != ( 1 << V_85 ) ) ;
F_2 ( V_86 != ( 1 << V_87 ) ) ;
V_6 -> V_49 = 1 << V_78 ;
F_91 ( & V_6 -> V_11 , V_88 , V_13 ) ;
V_6 -> V_11 . V_89 = F_36 ;
V_21 -> V_24 . V_23 |= ( 1 << V_78 ) ;
F_5 ( V_6 ) ;
}
static void F_92 ( struct V_20 * V_21 )
{
if ( F_93 ( V_21 ) -> V_90 <= 5 )
return;
if ( F_94 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_51 = F_20 ;
V_21 -> V_24 . V_42 . V_43 = F_22 ;
F_87 ( V_21 , V_83 ,
V_91 ,
V_92 ) ;
F_87 ( V_21 , V_85 ,
V_93 ,
V_94 ) ;
F_87 ( V_21 , V_87 ,
V_95 , V_96 ) ;
} else if ( F_34 ( V_21 ) || F_64 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_51 = F_20 ;
if ( ! F_64 ( V_21 ) )
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
else
V_21 -> V_24 . V_42 . V_43 = F_22 ;
F_87 ( V_21 , V_83 ,
V_97 , V_80 ) ;
F_87 ( V_21 , V_87 ,
V_98 , V_99 ) ;
} else if ( F_56 ( V_21 ) || F_57 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_51 =
F_28 ;
if ( F_56 ( V_21 ) )
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
else
V_21 -> V_24 . V_42 . V_43 = F_22 ;
F_87 ( V_21 , V_83 ,
V_100 , V_101 ) ;
} else if ( F_95 ( V_21 ) ) {
T_1 V_102 ;
V_21 -> V_24 . V_42 . V_51 =
F_28 ;
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
F_7 ( V_21 , V_103 , 0 ) ;
F_19 ( V_21 , V_81 ) ;
F_87 ( V_21 , V_83 ,
V_100 , V_104 ) ;
F_96 ( & V_21 -> V_24 . V_41 ) ;
F_28 ( V_21 , V_50 ) ;
V_102 = F_13 ( V_21 , V_81 ) ;
F_31 ( V_21 , V_50 ) ;
F_97 ( & V_21 -> V_24 . V_41 ) ;
if ( ! ( V_102 & V_105 ) ) {
F_58 ( L_12 ) ;
F_58 ( L_13 ) ;
F_87 ( V_21 , V_83 ,
V_103 , V_106 ) ;
}
} else if ( F_45 ( V_21 ) ) {
V_21 -> V_24 . V_42 . V_51 =
F_28 ;
V_21 -> V_24 . V_42 . V_43 =
F_31 ;
F_87 ( V_21 , V_83 ,
V_103 , V_106 ) ;
}
F_4 ( V_21 -> V_24 . V_23 == 0 ) ;
}
void F_98 ( struct V_20 * V_21 )
{
F_99 ( V_21 ) ;
F_55 ( V_21 ) ;
F_92 ( V_21 ) ;
F_65 ( V_21 , false ) ;
V_21 -> V_24 . V_107 = 1 ;
switch ( F_93 ( V_21 ) -> V_90 ) {
default:
case 9 :
F_100 ( V_108 ) ;
F_101 ( V_108 ) ;
break;
case 8 :
if ( F_64 ( V_21 ) ) {
F_100 ( V_109 ) ;
F_101 ( V_109 ) ;
} else {
F_100 ( V_110 ) ;
F_101 ( V_111 ) ;
}
break;
case 7 :
case 6 :
if ( F_56 ( V_21 ) ) {
F_100 ( V_112 ) ;
} else {
F_100 ( V_111 ) ;
}
if ( F_34 ( V_21 ) ) {
F_101 ( V_113 ) ;
} else {
F_101 ( V_111 ) ;
}
break;
case 5 :
F_100 ( V_114 ) ;
F_101 ( V_114 ) ;
break;
case 4 :
case 3 :
case 2 :
F_100 ( V_115 ) ;
F_101 ( V_115 ) ;
break;
}
if ( F_102 ( V_21 ) ) {
F_100 ( V_116 ) ;
F_101 ( V_116 ) ;
}
F_68 ( V_21 ) ;
}
void F_103 ( struct V_20 * V_21 )
{
F_69 ( V_21 ) ;
F_41 ( V_21 , false ) ;
}
int F_104 ( struct V_117 * V_118 ,
void * V_119 , struct V_120 * V_121 )
{
struct V_20 * V_21 = F_105 ( V_118 ) ;
struct V_122 * V_72 = V_119 ;
struct V_123 const * V_124 = V_125 ;
unsigned V_126 ;
T_3 V_127 , V_128 ;
int V_70 , V_32 = 0 ;
for ( V_70 = 0 ; V_70 < F_3 ( V_125 ) ; V_70 ++ , V_124 ++ ) {
if ( F_84 ( V_124 -> V_127 ) == ( V_72 -> V_69 & - V_124 -> V_126 ) &&
( F_93 ( V_118 ) -> V_129 & V_124 -> V_130 ) )
break;
}
if ( V_70 == F_3 ( V_125 ) )
return - V_131 ;
V_127 = V_124 -> V_127 ;
V_128 = V_124 -> V_128 ;
V_126 = V_124 -> V_126 ;
V_126 |= V_72 -> V_69 ^ F_84 ( V_127 ) ;
F_106 ( V_21 ) ;
switch ( V_126 ) {
case 8 | 1 :
V_72 -> V_132 = F_107 ( V_127 , V_128 ) ;
break;
case 8 :
V_72 -> V_132 = F_108 ( V_127 ) ;
break;
case 4 :
V_72 -> V_132 = F_109 ( V_127 ) ;
break;
case 2 :
V_72 -> V_132 = F_110 ( V_127 ) ;
break;
case 1 :
V_72 -> V_132 = F_111 ( V_127 ) ;
break;
default:
V_32 = - V_131 ;
goto V_133;
}
V_133:
F_112 ( V_21 ) ;
return V_32 ;
}
static int F_113 ( struct V_134 * V_135 )
{
T_4 V_136 ;
F_114 ( V_135 , V_137 , & V_136 ) ;
return ( V_136 & V_138 ) == 0 ;
}
static int F_115 ( struct V_20 * V_21 , unsigned V_139 )
{
struct V_134 * V_135 = V_21 -> V_140 . V_135 ;
F_116 ( V_135 , V_137 , V_141 ) ;
F_35 ( 20 ) ;
F_116 ( V_135 , V_137 , 0 ) ;
return F_117 ( F_113 ( V_135 ) , 500 ) ;
}
static int F_118 ( struct V_134 * V_135 )
{
T_4 V_136 ;
F_114 ( V_135 , V_137 , & V_136 ) ;
return ( V_136 & V_141 ) == 0 ;
}
static int F_119 ( struct V_20 * V_21 , unsigned V_139 )
{
struct V_134 * V_135 = V_21 -> V_140 . V_135 ;
F_116 ( V_135 , V_137 , V_141 ) ;
return F_117 ( F_118 ( V_135 ) , 500 ) ;
}
static int F_120 ( struct V_20 * V_21 , unsigned V_139 )
{
struct V_134 * V_135 = V_21 -> V_140 . V_135 ;
int V_32 ;
F_116 ( V_135 , V_137 ,
V_142 | V_141 ) ;
V_32 = F_117 ( F_118 ( V_135 ) , 500 ) ;
if ( V_32 )
return V_32 ;
F_121 ( V_143 , F_109 ( V_143 ) | V_144 ) ;
F_122 ( V_143 ) ;
F_116 ( V_135 , V_137 ,
V_145 | V_141 ) ;
V_32 = F_117 ( F_118 ( V_135 ) , 500 ) ;
if ( V_32 )
return V_32 ;
F_121 ( V_143 , F_109 ( V_143 ) & ~ V_144 ) ;
F_122 ( V_143 ) ;
F_116 ( V_135 , V_137 , 0 ) ;
return 0 ;
}
static int F_123 ( struct V_20 * V_21 ,
unsigned V_139 )
{
int V_32 ;
F_121 ( V_146 ,
V_147 | V_148 ) ;
V_32 = F_124 ( V_21 ,
V_146 , V_148 , 0 ,
500 ) ;
if ( V_32 )
return V_32 ;
F_121 ( V_146 ,
V_149 | V_148 ) ;
V_32 = F_124 ( V_21 ,
V_146 , V_148 , 0 ,
500 ) ;
if ( V_32 )
return V_32 ;
F_121 ( V_146 , 0 ) ;
return 0 ;
}
static int F_125 ( struct V_20 * V_21 ,
T_1 V_150 )
{
F_7 ( V_21 , V_151 , V_150 ) ;
return F_126 ( V_21 ,
V_151 , V_150 , 0 ,
500 ) ;
}
static int F_127 ( struct V_20 * V_21 ,
unsigned V_139 )
{
struct V_152 * V_153 ;
const T_1 V_154 [ V_155 ] = {
[ V_156 ] = V_157 ,
[ V_158 ] = V_159 ,
[ V_160 ] = V_161 ,
[ V_162 ] = V_163 ,
[ V_164 ] = V_165 ,
} ;
T_1 V_166 ;
int V_32 ;
if ( V_139 == V_167 ) {
V_166 = V_168 ;
} else {
unsigned int V_169 ;
V_166 = 0 ;
F_128 (engine, dev_priv, engine_mask, tmp)
V_166 |= V_154 [ V_153 -> V_2 ] ;
}
V_32 = F_125 ( V_21 , V_166 ) ;
F_41 ( V_21 , true ) ;
return V_32 ;
}
int F_126 ( struct V_20 * V_21 ,
T_3 V_72 ,
const T_1 V_49 ,
const T_1 V_170 ,
const unsigned long V_171 )
{
#define F_129 ((I915_READ_FW(reg) & mask) == value)
int V_32 = F_130 ( F_129 , 2 ) ;
if ( V_32 )
V_32 = F_117 ( F_129 , V_171 ) ;
return V_32 ;
#undef F_129
}
int F_124 ( struct V_20 * V_21 ,
T_3 V_72 ,
const T_1 V_49 ,
const T_1 V_170 ,
const unsigned long V_171 )
{
unsigned V_47 =
F_131 ( V_21 , V_72 , V_172 ) ;
int V_32 ;
F_73 ( V_21 , V_47 ) ;
V_32 = F_130 ( ( F_132 ( V_72 ) & V_49 ) == V_170 , 2 ) ;
F_78 ( V_21 , V_47 ) ;
if ( V_32 )
V_32 = F_117 ( ( F_133 ( V_72 ) & V_49 ) == V_170 ,
V_171 ) ;
return V_32 ;
}
static int F_134 ( struct V_152 * V_153 )
{
struct V_20 * V_21 = V_153 -> V_8 ;
int V_32 ;
F_135 ( F_136 ( V_153 -> V_173 ) ,
F_89 ( V_174 ) ) ;
V_32 = F_126 ( V_21 ,
F_136 ( V_153 -> V_173 ) ,
V_175 ,
V_175 ,
700 ) ;
if ( V_32 )
F_14 ( L_14 , V_153 -> V_176 ) ;
return V_32 ;
}
static void F_137 ( struct V_152 * V_153 )
{
struct V_20 * V_21 = V_153 -> V_8 ;
F_135 ( F_136 ( V_153 -> V_173 ) ,
F_88 ( V_174 ) ) ;
}
static int F_138 ( struct V_20 * V_21 ,
unsigned V_139 )
{
struct V_152 * V_153 ;
unsigned int V_169 ;
F_128 (engine, dev_priv, engine_mask, tmp)
if ( F_134 ( V_153 ) )
goto V_177;
return F_127 ( V_21 , V_139 ) ;
V_177:
F_128 (engine, dev_priv, engine_mask, tmp)
F_137 ( V_153 ) ;
return - V_178 ;
}
static T_5 F_139 ( struct V_20 * V_21 )
{
if ( ! V_8 . V_179 )
return NULL ;
if ( F_93 ( V_21 ) -> V_90 >= 8 )
return F_138 ;
else if ( F_93 ( V_21 ) -> V_90 >= 6 )
return F_127 ;
else if ( F_140 ( V_21 ) )
return F_123 ;
else if ( F_141 ( V_21 ) )
return F_120 ;
else if ( F_142 ( V_21 ) )
return F_119 ;
else if ( F_93 ( V_21 ) -> V_90 >= 3 )
return F_115 ;
else
return NULL ;
}
int F_143 ( struct V_20 * V_21 , unsigned V_139 )
{
T_5 V_179 ;
int V_32 ;
V_179 = F_139 ( V_21 ) ;
if ( V_179 == NULL )
return - V_180 ;
F_73 ( V_21 , V_50 ) ;
V_32 = V_179 ( V_21 , V_139 ) ;
F_78 ( V_21 , V_50 ) ;
return V_32 ;
}
bool F_144 ( struct V_20 * V_21 )
{
return F_139 ( V_21 ) != NULL ;
}
int F_145 ( struct V_20 * V_21 )
{
int V_32 ;
unsigned long V_40 ;
if ( ! F_146 ( V_21 ) )
return - V_131 ;
F_73 ( V_21 , V_50 ) ;
F_39 ( & V_21 -> V_24 . V_41 , V_40 ) ;
V_32 = F_125 ( V_21 , V_181 ) ;
F_40 ( & V_21 -> V_24 . V_41 , V_40 ) ;
F_78 ( V_21 , V_50 ) ;
return V_32 ;
}
bool F_147 ( struct V_20 * V_21 )
{
return F_62 ( V_21 ) ;
}
bool
F_148 ( struct V_20 * V_21 )
{
if ( F_149 ( V_8 . V_77 ||
V_21 -> V_24 . V_107 <= 0 ) )
return false ;
if ( F_149 ( F_147 ( V_21 ) ) ) {
F_66 ( L_15
L_16
L_17 ) ;
V_8 . V_77 ++ ;
V_21 -> V_24 . V_107 -- ;
return true ;
}
return false ;
}
static enum V_22
F_150 ( struct V_20 * V_21 ,
T_3 V_72 )
{
enum V_22 V_23 ;
if ( F_102 ( V_21 ) )
return 0 ;
switch ( F_54 ( V_21 ) ) {
case 9 :
V_23 = F_151 ( F_84 ( V_72 ) ) ;
break;
case 8 :
if ( F_64 ( V_21 ) )
V_23 = F_152 ( F_84 ( V_72 ) ) ;
else
V_23 = F_153 ( F_84 ( V_72 ) ) ;
break;
case 7 :
case 6 :
if ( F_34 ( V_21 ) )
V_23 = F_154 ( F_84 ( V_72 ) ) ;
else
V_23 = F_153 ( F_84 ( V_72 ) ) ;
break;
default:
F_155 ( F_93 ( V_21 ) -> V_90 ) ;
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
F_156 ( struct V_20 * V_21 ,
T_3 V_72 )
{
enum V_22 V_23 ;
if ( F_102 ( V_21 ) )
return 0 ;
switch ( F_54 ( V_21 ) ) {
case 9 :
V_23 = F_157 ( F_84 ( V_72 ) ) ;
break;
case 8 :
if ( F_64 ( V_21 ) )
V_23 = F_158 ( F_84 ( V_72 ) ) ;
else
V_23 = F_159 ( F_84 ( V_72 ) ) ;
break;
case 7 :
case 6 :
V_23 = V_82 ;
break;
default:
F_155 ( F_93 ( V_21 ) -> V_90 ) ;
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
F_131 ( struct V_20 * V_21 ,
T_3 V_72 , unsigned int V_182 )
{
enum V_22 V_23 = 0 ;
F_4 ( ! V_182 ) ;
if ( V_182 & V_172 )
V_23 = F_150 ( V_21 , V_72 ) ;
if ( V_182 & V_183 )
V_23 |= F_156 ( V_21 , V_72 ) ;
return V_23 ;
}
