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
F_9 ( & V_6 -> V_10 , V_11 + 1 ) ;
}
static inline void
F_10 ( const struct V_5 * V_6 )
{
if ( F_11 ( ( F_12 ( V_6 -> V_8 , V_6 -> V_12 ) &
V_13 ) == 0 ,
V_14 ) )
F_13 ( L_2 ,
F_1 ( V_6 -> V_2 ) ) ;
}
static inline void
F_14 ( const struct V_5 * V_6 )
{
F_7 ( V_6 -> V_8 , V_6 -> V_7 , V_6 -> V_15 ) ;
}
static inline void
F_15 ( const struct V_5 * V_6 )
{
if ( F_11 ( ( F_12 ( V_6 -> V_8 , V_6 -> V_12 ) &
V_13 ) ,
V_14 ) )
F_13 ( L_3 ,
F_1 ( V_6 -> V_2 ) ) ;
}
static inline void
F_16 ( const struct V_5 * V_6 )
{
F_7 ( V_6 -> V_8 , V_6 -> V_7 , V_6 -> V_16 ) ;
}
static inline void
F_17 ( const struct V_5 * V_6 )
{
if ( F_6 ( V_6 -> V_17 ) )
F_18 ( V_6 -> V_8 , V_6 -> V_17 ) ;
}
static void
F_19 ( struct V_18 * V_19 , enum V_20 V_21 )
{
struct V_5 * V_6 ;
enum V_1 V_2 ;
F_20 (d, fw_domains, dev_priv, id) {
F_10 ( V_6 ) ;
F_14 ( V_6 ) ;
F_15 ( V_6 ) ;
}
}
static void
F_21 ( struct V_18 * V_19 , enum V_20 V_21 )
{
struct V_5 * V_6 ;
enum V_1 V_2 ;
F_20 (d, fw_domains, dev_priv, id) {
F_16 ( V_6 ) ;
F_17 ( V_6 ) ;
}
}
static void
F_22 ( struct V_18 * V_19 )
{
struct V_5 * V_6 ;
enum V_1 V_2 ;
F_23 (d, dev_priv, id) {
F_17 ( V_6 ) ;
break;
}
}
static void
F_24 ( struct V_18 * V_19 , enum V_20 V_21 )
{
struct V_5 * V_6 ;
enum V_1 V_2 ;
if ( V_19 -> V_22 . V_21 == 0 )
return;
F_20 (d, fw_domains, dev_priv, id)
F_5 ( V_6 ) ;
F_22 ( V_19 ) ;
}
static void F_25 ( struct V_18 * V_19 )
{
if ( F_26 ( ( F_12 ( V_19 , V_23 ) &
V_24 ) == 0 , 500 ) )
F_13 ( L_4 ) ;
}
static void F_27 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
F_19 ( V_19 , V_21 ) ;
F_25 ( V_19 ) ;
}
static void F_28 ( struct V_18 * V_19 )
{
T_1 V_25 ;
V_25 = F_12 ( V_19 , V_26 ) ;
if ( F_29 ( V_25 , L_5 , V_25 ) )
F_7 ( V_19 , V_26 , V_25 ) ;
}
static void F_30 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
F_21 ( V_19 , V_21 ) ;
F_28 ( V_19 ) ;
}
static inline T_1 F_31 ( struct V_18 * V_19 )
{
T_1 V_27 = F_12 ( V_19 , V_28 ) ;
return V_27 & V_29 ;
}
static int F_32 ( struct V_18 * V_19 )
{
int V_30 = 0 ;
if ( F_33 ( V_19 -> V_31 ) )
V_19 -> V_22 . V_32 = F_31 ( V_19 ) ;
if ( V_19 -> V_22 . V_32 < V_33 ) {
int V_34 = 500 ;
T_1 V_35 = F_31 ( V_19 ) ;
while ( V_35 <= V_33 && V_34 -- ) {
F_34 ( 10 ) ;
V_35 = F_31 ( V_19 ) ;
}
if ( F_4 ( V_34 < 0 && V_35 <= V_33 ) )
++ V_30 ;
V_19 -> V_22 . V_32 = V_35 ;
}
V_19 -> V_22 . V_32 -- ;
return V_30 ;
}
static void F_35 ( unsigned long V_36 )
{
struct V_5 * V_37 = ( void * ) V_36 ;
unsigned long V_38 ;
F_36 ( V_37 -> V_8 ) ;
F_37 ( & V_37 -> V_8 -> V_22 . V_39 , V_38 ) ;
if ( F_4 ( V_37 -> V_40 == 0 ) )
V_37 -> V_40 ++ ;
if ( -- V_37 -> V_40 == 0 )
V_37 -> V_8 -> V_22 . V_41 . V_42 ( V_37 -> V_8 ,
1 << V_37 -> V_2 ) ;
F_38 ( & V_37 -> V_8 -> V_22 . V_39 , V_38 ) ;
}
void F_39 ( struct V_43 * V_31 , bool V_44 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
unsigned long V_38 ;
struct V_5 * V_37 ;
int V_46 = 100 ;
enum V_1 V_2 ;
enum V_20 V_47 = 0 , V_48 ;
while ( 1 ) {
V_48 = 0 ;
F_23 (domain, dev_priv, id) {
if ( F_40 ( & V_37 -> V_10 ) == 0 )
continue;
F_35 ( ( unsigned long ) V_37 ) ;
}
F_37 ( & V_19 -> V_22 . V_39 , V_38 ) ;
F_23 (domain, dev_priv, id) {
if ( F_41 ( & V_37 -> V_10 ) )
V_48 |= ( 1 << V_2 ) ;
}
if ( V_48 == 0 )
break;
if ( -- V_46 == 0 ) {
F_13 ( L_6 ) ;
break;
}
F_38 ( & V_19 -> V_22 . V_39 , V_38 ) ;
F_42 () ;
}
F_4 ( V_48 ) ;
F_23 (domain, dev_priv, id)
if ( V_37 -> V_40 )
V_47 |= 1 << V_2 ;
if ( V_47 )
V_19 -> V_22 . V_41 . V_42 ( V_19 , V_47 ) ;
F_24 ( V_19 , V_49 ) ;
if ( V_44 ) {
if ( V_47 )
V_19 -> V_22 . V_41 . V_50 ( V_19 , V_47 ) ;
if ( F_43 ( V_31 ) || F_44 ( V_31 ) )
V_19 -> V_22 . V_32 =
F_31 ( V_19 ) ;
}
if ( ! V_44 )
F_45 ( V_19 ) ;
F_38 ( & V_19 -> V_22 . V_39 , V_38 ) ;
}
static void F_46 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
if ( ( F_47 ( V_31 ) || F_48 ( V_31 ) ||
F_49 ( V_31 ) -> V_51 >= 9 ) &&
( F_12 ( V_19 , V_52 ) & V_53 ) ) {
V_19 -> V_54 = 128 ;
F_50 ( L_7 , V_19 -> V_54 ) ;
}
}
static bool
F_51 ( struct V_18 * V_19 )
{
T_1 V_55 ;
V_55 = F_12 ( V_19 , V_56 ) ;
if ( F_52 ( ! ( V_55 & V_57 ) ) )
return false ;
F_7 ( V_19 , V_56 , V_57 ) ;
return true ;
}
static bool
F_53 ( struct V_18 * V_19 )
{
T_1 V_58 ;
V_58 = F_12 ( V_19 , V_59 ) ;
if ( F_52 ( ! ( V_58 & ( V_60 | V_61 ) ) ) )
return false ;
F_7 ( V_19 , V_59 , V_62 ) ;
return true ;
}
static bool
F_54 ( struct V_18 * V_19 )
{
if ( F_55 ( V_19 ) )
return F_51 ( V_19 ) ;
if ( F_33 ( V_19 ) || F_56 ( V_19 ) )
return F_53 ( V_19 ) ;
return false ;
}
static void F_57 ( struct V_43 * V_31 ,
bool V_63 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
if ( F_54 ( V_19 ) )
F_58 ( L_8 ) ;
if ( F_43 ( V_31 ) || F_44 ( V_31 ) )
F_7 ( V_19 , V_26 ,
F_12 ( V_19 , V_26 ) ) ;
if ( F_56 ( V_31 ) ) {
F_7 ( V_19 , V_28 ,
F_12 ( V_19 , V_28 ) |
V_64 |
V_65 ) ;
}
F_39 ( V_31 , V_63 ) ;
}
void F_59 ( struct V_43 * V_31 , bool V_63 )
{
F_57 ( V_31 , V_63 ) ;
F_60 ( V_31 ) ;
}
void F_61 ( struct V_43 * V_31 )
{
V_8 . V_66 = F_62 ( V_31 , V_8 . V_66 ) ;
F_63 ( V_31 ) ;
}
static void F_64 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
struct V_5 * V_37 ;
enum V_1 V_2 ;
if ( ! V_19 -> V_22 . V_41 . V_50 )
return;
V_21 &= V_19 -> V_22 . V_21 ;
F_20 (domain, fw_domains, dev_priv, id) {
if ( V_37 -> V_40 ++ )
V_21 &= ~ ( 1 << V_2 ) ;
}
if ( V_21 )
V_19 -> V_22 . V_41 . V_50 ( V_19 , V_21 ) ;
}
void F_65 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
unsigned long V_38 ;
if ( ! V_19 -> V_22 . V_41 . V_50 )
return;
F_66 ( V_19 ) ;
F_37 ( & V_19 -> V_22 . V_39 , V_38 ) ;
F_64 ( V_19 , V_21 ) ;
F_38 ( & V_19 -> V_22 . V_39 , V_38 ) ;
}
void F_67 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
F_68 ( & V_19 -> V_22 . V_39 ) ;
if ( ! V_19 -> V_22 . V_41 . V_50 )
return;
F_64 ( V_19 , V_21 ) ;
}
static void F_69 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
struct V_5 * V_37 ;
enum V_1 V_2 ;
if ( ! V_19 -> V_22 . V_41 . V_42 )
return;
V_21 &= V_19 -> V_22 . V_21 ;
F_20 (domain, fw_domains, dev_priv, id) {
if ( F_4 ( V_37 -> V_40 == 0 ) )
continue;
if ( -- V_37 -> V_40 )
continue;
V_37 -> V_40 ++ ;
F_8 ( V_37 ) ;
}
}
void F_70 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
unsigned long V_38 ;
if ( ! V_19 -> V_22 . V_41 . V_42 )
return;
F_37 ( & V_19 -> V_22 . V_39 , V_38 ) ;
F_69 ( V_19 , V_21 ) ;
F_38 ( & V_19 -> V_22 . V_39 , V_38 ) ;
}
void F_71 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
F_68 ( & V_19 -> V_22 . V_39 ) ;
if ( ! V_19 -> V_22 . V_41 . V_42 )
return;
F_69 ( V_19 , V_21 ) ;
}
void F_45 ( struct V_18 * V_19 )
{
struct V_5 * V_37 ;
enum V_1 V_2 ;
if ( ! V_19 -> V_22 . V_41 . V_50 )
return;
F_23 (domain, dev_priv, id)
F_4 ( V_37 -> V_40 ) ;
}
static void
F_72 ( struct V_18 * V_19 )
{
F_7 ( V_19 , V_67 , 0 ) ;
}
static void
F_73 ( struct V_18 * V_19 ,
const T_2 V_68 ,
const bool V_69 ,
const bool V_70 )
{
if ( V_8 . V_71 < 2 &&
( F_33 ( V_19 ) || F_56 ( V_19 ) ) )
return;
if ( F_29 ( F_54 ( V_19 ) ,
L_9 ,
V_70 ? L_10 : L_11 ,
V_69 ? L_12 : L_13 ,
F_74 ( V_68 ) ) )
V_8 . V_71 -- ;
}
static inline void
F_75 ( struct V_18 * V_19 ,
const T_2 V_68 ,
const bool V_69 ,
const bool V_70 )
{
if ( F_52 ( ! V_8 . V_71 ) )
return;
F_73 ( V_19 , V_68 , V_69 , V_70 ) ;
}
static inline void F_76 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
struct V_5 * V_37 ;
enum V_1 V_2 ;
if ( F_4 ( ! V_21 ) )
return;
F_20 (domain, fw_domains, dev_priv, id) {
if ( V_37 -> V_40 ) {
V_21 &= ~ ( 1 << V_2 ) ;
continue;
}
V_37 -> V_40 ++ ;
F_8 ( V_37 ) ;
}
if ( V_21 )
V_19 -> V_22 . V_41 . V_50 ( V_19 , V_21 ) ;
}
static bool F_77 ( struct V_18 * V_19 ,
T_2 V_68 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < F_3 ( V_73 ) ; V_72 ++ )
if ( F_78 ( V_68 , V_73 [ V_72 ] ) )
return true ;
return false ;
}
static bool F_79 ( struct V_18 * V_19 ,
T_2 V_68 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < F_3 ( V_74 ) ; V_72 ++ )
if ( F_78 ( V_68 , V_74 [ V_72 ] ) )
return true ;
return false ;
}
static void F_80 ( struct V_18 * V_19 ,
enum V_1 V_75 ,
T_2 V_7 ,
T_2 V_12 )
{
struct V_5 * V_6 ;
if ( F_4 ( V_75 >= V_4 ) )
return;
V_6 = & V_19 -> V_22 . V_76 [ V_75 ] ;
F_4 ( V_6 -> V_40 ) ;
V_6 -> V_40 = 0 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_12 = V_12 ;
if ( F_43 ( V_19 ) ) {
V_6 -> V_9 = 0 ;
V_6 -> V_15 = V_13 ;
V_6 -> V_16 = 0 ;
} else {
V_6 -> V_9 = F_81 ( 0xffff ) ;
V_6 -> V_15 = F_82 ( V_13 ) ;
V_6 -> V_16 = F_81 ( V_13 ) ;
}
if ( F_33 ( V_19 ) || F_56 ( V_19 ) )
V_6 -> V_17 = V_77 ;
else if ( F_43 ( V_19 ) || F_44 ( V_19 ) || F_83 ( V_19 ) )
V_6 -> V_17 = V_78 ;
V_6 -> V_8 = V_19 ;
V_6 -> V_2 = V_75 ;
F_84 ( & V_6 -> V_10 , F_35 , ( unsigned long ) V_6 ) ;
V_19 -> V_22 . V_21 |= ( 1 << V_75 ) ;
F_5 ( V_6 ) ;
}
static void F_85 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
if ( F_49 ( V_19 -> V_31 ) -> V_51 <= 5 )
return;
if ( F_86 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 = F_19 ;
V_19 -> V_22 . V_41 . V_42 = F_21 ;
F_80 ( V_19 , V_79 ,
V_80 ,
V_81 ) ;
F_80 ( V_19 , V_82 ,
V_83 ,
V_84 ) ;
F_80 ( V_19 , V_85 ,
V_86 , V_87 ) ;
} else if ( F_33 ( V_31 ) || F_56 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 = F_19 ;
if ( ! F_56 ( V_31 ) )
V_19 -> V_22 . V_41 . V_42 =
F_30 ;
else
V_19 -> V_22 . V_41 . V_42 = F_21 ;
F_80 ( V_19 , V_79 ,
V_88 , V_77 ) ;
F_80 ( V_19 , V_85 ,
V_89 , V_90 ) ;
} else if ( F_47 ( V_31 ) || F_48 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 =
F_27 ;
if ( F_47 ( V_31 ) )
V_19 -> V_22 . V_41 . V_42 =
F_30 ;
else
V_19 -> V_22 . V_41 . V_42 = F_21 ;
F_80 ( V_19 , V_79 ,
V_91 , V_92 ) ;
} else if ( F_87 ( V_31 ) ) {
T_1 V_93 ;
V_19 -> V_22 . V_41 . V_50 =
F_27 ;
V_19 -> V_22 . V_41 . V_42 =
F_30 ;
F_7 ( V_19 , V_94 , 0 ) ;
F_18 ( V_19 , V_78 ) ;
F_80 ( V_19 , V_79 ,
V_91 , V_95 ) ;
F_88 ( & V_31 -> V_96 ) ;
F_27 ( V_19 , V_49 ) ;
V_93 = F_12 ( V_19 , V_78 ) ;
F_30 ( V_19 , V_49 ) ;
F_89 ( & V_31 -> V_96 ) ;
if ( ! ( V_93 & V_97 ) ) {
F_50 ( L_14 ) ;
F_50 ( L_15 ) ;
F_80 ( V_19 , V_79 ,
V_94 , V_98 ) ;
}
} else if ( F_43 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 =
F_27 ;
V_19 -> V_22 . V_41 . V_42 =
F_30 ;
F_80 ( V_19 , V_79 ,
V_94 , V_98 ) ;
}
F_4 ( V_19 -> V_22 . V_21 == 0 ) ;
}
void F_90 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
F_91 ( V_31 ) ;
F_46 ( V_31 ) ;
F_85 ( V_31 ) ;
F_57 ( V_31 , false ) ;
V_19 -> V_22 . V_99 = 1 ;
switch ( F_49 ( V_31 ) -> V_51 ) {
default:
case 9 :
F_92 ( V_100 ) ;
F_93 ( V_100 ) ;
break;
case 8 :
if ( F_56 ( V_31 ) ) {
F_92 ( V_101 ) ;
F_93 ( V_101 ) ;
} else {
F_92 ( V_102 ) ;
F_93 ( V_103 ) ;
}
break;
case 7 :
case 6 :
if ( F_47 ( V_31 ) ) {
F_92 ( V_104 ) ;
} else {
F_92 ( V_103 ) ;
}
if ( F_33 ( V_31 ) ) {
F_93 ( V_105 ) ;
} else {
F_93 ( V_103 ) ;
}
break;
case 5 :
F_92 ( V_106 ) ;
F_93 ( V_106 ) ;
break;
case 4 :
case 3 :
case 2 :
F_92 ( V_107 ) ;
F_93 ( V_107 ) ;
break;
}
if ( F_94 ( V_31 ) ) {
F_92 ( V_108 ) ;
F_93 ( V_108 ) ;
}
F_60 ( V_31 ) ;
}
void F_95 ( struct V_43 * V_31 )
{
F_61 ( V_31 ) ;
F_39 ( V_31 , false ) ;
}
int F_96 ( struct V_43 * V_31 ,
void * V_109 , struct V_110 * V_111 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
struct V_112 * V_68 = V_109 ;
struct V_113 const * V_114 = V_115 ;
unsigned V_116 ;
T_2 V_117 , V_118 ;
int V_72 , V_30 = 0 ;
for ( V_72 = 0 ; V_72 < F_3 ( V_115 ) ; V_72 ++ , V_114 ++ ) {
if ( F_74 ( V_114 -> V_117 ) == ( V_68 -> V_119 & - V_114 -> V_116 ) &&
( 1 << F_49 ( V_31 ) -> V_51 & V_114 -> V_120 ) )
break;
}
if ( V_72 == F_3 ( V_115 ) )
return - V_121 ;
V_117 = V_114 -> V_117 ;
V_118 = V_114 -> V_118 ;
V_116 = V_114 -> V_116 ;
V_116 |= V_68 -> V_119 ^ F_74 ( V_117 ) ;
F_97 ( V_19 ) ;
switch ( V_116 ) {
case 8 | 1 :
V_68 -> V_122 = F_98 ( V_117 , V_118 ) ;
break;
case 8 :
V_68 -> V_122 = F_99 ( V_117 ) ;
break;
case 4 :
V_68 -> V_122 = F_100 ( V_117 ) ;
break;
case 2 :
V_68 -> V_122 = F_101 ( V_117 ) ;
break;
case 1 :
V_68 -> V_122 = F_102 ( V_117 ) ;
break;
default:
V_30 = - V_121 ;
goto V_123;
}
V_123:
F_103 ( V_19 ) ;
return V_30 ;
}
int F_104 ( struct V_43 * V_31 ,
void * V_109 , struct V_110 * V_111 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
struct V_124 * args = V_109 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
int V_30 ;
if ( args -> V_129 || args -> V_130 )
return - V_121 ;
if ( args -> V_131 == V_132 && ! F_105 ( V_133 ) )
return - V_134 ;
V_30 = F_106 ( & V_31 -> V_96 ) ;
if ( V_30 )
return V_30 ;
V_128 = F_107 ( V_111 -> V_135 , args -> V_131 ) ;
if ( F_108 ( V_128 ) ) {
F_89 ( & V_31 -> V_96 ) ;
return F_109 ( V_128 ) ;
}
V_126 = & V_128 -> V_136 ;
if ( F_105 ( V_133 ) )
args -> V_137 = F_110 ( & V_19 -> V_138 ) ;
else
args -> V_137 = 0 ;
args -> V_139 = V_126 -> V_139 ;
args -> V_140 = V_126 -> V_140 ;
F_89 ( & V_31 -> V_96 ) ;
return 0 ;
}
static int F_111 ( struct V_43 * V_31 )
{
T_3 V_141 ;
F_112 ( V_31 -> V_142 , V_143 , & V_141 ) ;
return ( V_141 & V_144 ) == 0 ;
}
static int F_113 ( struct V_43 * V_31 )
{
F_114 ( V_31 -> V_142 , V_143 , V_145 ) ;
F_34 ( 20 ) ;
F_114 ( V_31 -> V_142 , V_143 , 0 ) ;
return F_115 ( F_111 ( V_31 ) , 500 ) ;
}
static int F_116 ( struct V_43 * V_31 )
{
T_3 V_141 ;
F_112 ( V_31 -> V_142 , V_143 , & V_141 ) ;
return ( V_141 & V_145 ) == 0 ;
}
static int F_117 ( struct V_43 * V_31 )
{
F_114 ( V_31 -> V_142 , V_143 , V_145 ) ;
return F_115 ( F_116 ( V_31 ) , 500 ) ;
}
static int F_118 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
int V_30 ;
F_114 ( V_31 -> V_142 , V_143 ,
V_146 | V_145 ) ;
V_30 = F_115 ( F_116 ( V_31 ) , 500 ) ;
if ( V_30 )
return V_30 ;
F_119 ( V_147 , F_100 ( V_147 ) | V_148 ) ;
F_120 ( V_147 ) ;
F_114 ( V_31 -> V_142 , V_143 ,
V_149 | V_145 ) ;
V_30 = F_115 ( F_116 ( V_31 ) , 500 ) ;
if ( V_30 )
return V_30 ;
F_119 ( V_147 , F_100 ( V_147 ) & ~ V_148 ) ;
F_120 ( V_147 ) ;
F_114 ( V_31 -> V_142 , V_143 , 0 ) ;
return 0 ;
}
static int F_121 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
int V_30 ;
F_119 ( V_150 ,
V_151 | V_152 ) ;
V_30 = F_115 ( ( F_100 ( V_150 ) &
V_152 ) == 0 , 500 ) ;
if ( V_30 )
return V_30 ;
F_119 ( V_150 ,
V_153 | V_152 ) ;
V_30 = F_115 ( ( F_100 ( V_150 ) &
V_152 ) == 0 , 500 ) ;
if ( V_30 )
return V_30 ;
F_119 ( V_150 , 0 ) ;
return 0 ;
}
static int F_122 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
int V_30 ;
F_7 ( V_19 , V_154 , V_155 ) ;
V_30 = F_115 ( ( F_12 ( V_19 , V_154 ) & V_155 ) == 0 , 500 ) ;
F_39 ( V_31 , true ) ;
return V_30 ;
}
static int F_123 ( struct V_18 * V_19 ,
T_2 V_68 ,
const T_1 V_156 ,
const T_1 V_157 ,
const unsigned long V_158 )
{
return F_115 ( ( F_100 ( V_68 ) & V_156 ) == V_157 , V_158 ) ;
}
static int F_124 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
struct V_159 * V_160 ;
int V_72 ;
F_125 (engine, dev_priv, i) {
F_119 ( F_126 ( V_160 -> V_161 ) ,
F_82 ( V_162 ) ) ;
if ( F_123 ( V_19 ,
F_126 ( V_160 -> V_161 ) ,
V_163 ,
V_163 ,
700 ) ) {
F_13 ( L_16 , V_160 -> V_164 ) ;
goto V_165;
}
}
return F_122 ( V_31 ) ;
V_165:
F_125 (engine, dev_priv, i)
F_119 ( F_126 ( V_160 -> V_161 ) ,
F_81 ( V_162 ) ) ;
return - V_166 ;
}
bool F_127 ( struct V_43 * V_31 )
{
return F_128 ( V_31 ) != NULL ;
}
bool F_129 ( struct V_18 * V_19 )
{
return F_54 ( V_19 ) ;
}
bool
F_130 ( struct V_18 * V_19 )
{
if ( F_131 ( V_8 . V_71 ||
V_19 -> V_22 . V_99 <= 0 ) )
return false ;
if ( F_131 ( F_129 ( V_19 ) ) ) {
F_58 ( L_17
L_18
L_19 ) ;
V_8 . V_71 ++ ;
V_19 -> V_22 . V_99 -- ;
return true ;
}
return false ;
}
