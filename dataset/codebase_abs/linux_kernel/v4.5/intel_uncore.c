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
static void F_51 ( struct V_43 * V_31 ,
bool V_55 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
if ( F_52 ( V_31 ) )
F_7 ( V_19 , V_56 , V_57 ) ;
if ( F_43 ( V_31 ) || F_44 ( V_31 ) )
F_7 ( V_19 , V_26 ,
F_12 ( V_19 , V_26 ) ) ;
if ( F_53 ( V_31 ) ) {
F_7 ( V_19 , V_28 ,
F_12 ( V_19 , V_28 ) |
V_58 |
V_59 ) ;
}
F_39 ( V_31 , V_55 ) ;
}
void F_54 ( struct V_43 * V_31 , bool V_55 )
{
F_51 ( V_31 , V_55 ) ;
F_55 ( V_31 ) ;
}
void F_56 ( struct V_43 * V_31 )
{
F_57 ( V_31 ) ;
}
static void F_58 ( struct V_18 * V_19 ,
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
void F_59 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
unsigned long V_38 ;
if ( ! V_19 -> V_22 . V_41 . V_50 )
return;
F_60 ( V_19 ) ;
F_37 ( & V_19 -> V_22 . V_39 , V_38 ) ;
F_58 ( V_19 , V_21 ) ;
F_38 ( & V_19 -> V_22 . V_39 , V_38 ) ;
}
void F_61 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
F_62 ( & V_19 -> V_22 . V_39 ) ;
if ( ! V_19 -> V_22 . V_41 . V_50 )
return;
F_58 ( V_19 , V_21 ) ;
}
static void F_63 ( struct V_18 * V_19 ,
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
void F_64 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
unsigned long V_38 ;
if ( ! V_19 -> V_22 . V_41 . V_42 )
return;
F_37 ( & V_19 -> V_22 . V_39 , V_38 ) ;
F_63 ( V_19 , V_21 ) ;
F_38 ( & V_19 -> V_22 . V_39 , V_38 ) ;
}
void F_65 ( struct V_18 * V_19 ,
enum V_20 V_21 )
{
F_62 ( & V_19 -> V_22 . V_39 ) ;
if ( ! V_19 -> V_22 . V_41 . V_42 )
return;
F_63 ( V_19 , V_21 ) ;
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
F_66 ( struct V_18 * V_19 )
{
F_7 ( V_19 , V_60 , 0 ) ;
}
static void
F_67 ( struct V_18 * V_19 ,
T_2 V_61 , bool V_62 , bool V_63 )
{
const char * V_64 = V_62 ? L_8 : L_9 ;
const char * V_65 = V_63 ? L_10 : L_11 ;
if ( ! V_8 . V_66 )
return;
if ( F_12 ( V_19 , V_56 ) & V_57 ) {
F_29 ( 1 , L_12 ,
V_65 , V_64 , F_68 ( V_61 ) ) ;
F_7 ( V_19 , V_56 , V_57 ) ;
V_8 . V_66 -- ;
}
}
static void
F_69 ( struct V_18 * V_19 )
{
static bool V_67 = true ;
if ( V_8 . V_66 || ! V_67 )
return;
if ( F_12 ( V_19 , V_56 ) & V_57 ) {
F_70 ( L_13
L_14
L_15 ) ;
F_7 ( V_19 , V_56 , V_57 ) ;
V_8 . V_66 = V_67 -- ;
}
}
static inline void F_71 ( struct V_18 * V_19 ,
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
static bool F_72 ( struct V_18 * V_19 ,
T_2 V_61 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < F_3 ( V_69 ) ; V_68 ++ )
if ( F_73 ( V_61 , V_69 [ V_68 ] ) )
return true ;
return false ;
}
static bool F_74 ( struct V_18 * V_19 ,
T_2 V_61 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < F_3 ( V_70 ) ; V_68 ++ )
if ( F_73 ( V_61 , V_70 [ V_68 ] ) )
return true ;
return false ;
}
static void F_75 ( struct V_18 * V_19 ,
enum V_1 V_71 ,
T_2 V_7 ,
T_2 V_12 )
{
struct V_5 * V_6 ;
if ( F_4 ( V_71 >= V_4 ) )
return;
V_6 = & V_19 -> V_22 . V_72 [ V_71 ] ;
F_4 ( V_6 -> V_40 ) ;
V_6 -> V_40 = 0 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_12 = V_12 ;
if ( F_43 ( V_19 ) ) {
V_6 -> V_9 = 0 ;
V_6 -> V_15 = V_13 ;
V_6 -> V_16 = 0 ;
} else {
V_6 -> V_9 = F_76 ( 0xffff ) ;
V_6 -> V_15 = F_77 ( V_13 ) ;
V_6 -> V_16 = F_76 ( V_13 ) ;
}
if ( F_33 ( V_19 ) || F_53 ( V_19 ) )
V_6 -> V_17 = V_73 ;
else if ( F_43 ( V_19 ) || F_44 ( V_19 ) || F_78 ( V_19 ) )
V_6 -> V_17 = V_74 ;
V_6 -> V_8 = V_19 ;
V_6 -> V_2 = V_71 ;
F_79 ( & V_6 -> V_10 , F_35 , ( unsigned long ) V_6 ) ;
V_19 -> V_22 . V_21 |= ( 1 << V_71 ) ;
F_5 ( V_6 ) ;
}
static void F_80 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
if ( F_49 ( V_19 -> V_31 ) -> V_51 <= 5 )
return;
if ( F_81 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 = F_19 ;
V_19 -> V_22 . V_41 . V_42 = F_21 ;
F_75 ( V_19 , V_75 ,
V_76 ,
V_77 ) ;
F_75 ( V_19 , V_78 ,
V_79 ,
V_80 ) ;
F_75 ( V_19 , V_81 ,
V_82 , V_83 ) ;
} else if ( F_33 ( V_31 ) || F_53 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 = F_19 ;
if ( ! F_53 ( V_31 ) )
V_19 -> V_22 . V_41 . V_42 =
F_30 ;
else
V_19 -> V_22 . V_41 . V_42 = F_21 ;
F_75 ( V_19 , V_75 ,
V_84 , V_73 ) ;
F_75 ( V_19 , V_81 ,
V_85 , V_86 ) ;
} else if ( F_47 ( V_31 ) || F_48 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 =
F_27 ;
V_19 -> V_22 . V_41 . V_42 = F_21 ;
F_75 ( V_19 , V_75 ,
V_87 , V_88 ) ;
} else if ( F_82 ( V_31 ) ) {
T_1 V_89 ;
V_19 -> V_22 . V_41 . V_50 =
F_27 ;
V_19 -> V_22 . V_41 . V_42 =
F_30 ;
F_7 ( V_19 , V_90 , 0 ) ;
F_18 ( V_19 , V_74 ) ;
F_75 ( V_19 , V_75 ,
V_87 , V_91 ) ;
F_83 ( & V_31 -> V_92 ) ;
F_27 ( V_19 , V_49 ) ;
V_89 = F_12 ( V_19 , V_74 ) ;
F_30 ( V_19 , V_49 ) ;
F_84 ( & V_31 -> V_92 ) ;
if ( ! ( V_89 & V_93 ) ) {
F_50 ( L_16 ) ;
F_50 ( L_17 ) ;
F_75 ( V_19 , V_75 ,
V_90 , V_94 ) ;
}
} else if ( F_43 ( V_31 ) ) {
V_19 -> V_22 . V_41 . V_50 =
F_27 ;
V_19 -> V_22 . V_41 . V_42 =
F_30 ;
F_75 ( V_19 , V_75 ,
V_90 , V_94 ) ;
}
F_4 ( V_19 -> V_22 . V_21 == 0 ) ;
}
void F_85 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
F_86 ( V_31 ) ;
F_46 ( V_31 ) ;
F_80 ( V_31 ) ;
F_51 ( V_31 , false ) ;
switch ( F_49 ( V_31 ) -> V_51 ) {
default:
case 9 :
F_87 ( V_95 ) ;
F_88 ( V_95 ) ;
break;
case 8 :
if ( F_53 ( V_31 ) ) {
F_87 ( V_96 ) ;
F_88 ( V_96 ) ;
} else {
F_87 ( V_97 ) ;
F_88 ( V_98 ) ;
}
break;
case 7 :
case 6 :
if ( F_47 ( V_31 ) ) {
F_87 ( V_99 ) ;
} else {
F_87 ( V_98 ) ;
}
if ( F_33 ( V_31 ) ) {
F_88 ( V_100 ) ;
} else {
F_88 ( V_98 ) ;
}
break;
case 5 :
F_87 ( V_101 ) ;
F_88 ( V_101 ) ;
break;
case 4 :
case 3 :
case 2 :
F_87 ( V_102 ) ;
F_88 ( V_102 ) ;
break;
}
if ( F_89 ( V_31 ) ) {
F_87 ( V_103 ) ;
F_88 ( V_103 ) ;
}
F_55 ( V_31 ) ;
}
void F_90 ( struct V_43 * V_31 )
{
F_56 ( V_31 ) ;
F_39 ( V_31 , false ) ;
}
int F_91 ( struct V_43 * V_31 ,
void * V_104 , struct V_105 * V_106 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
struct V_107 * V_61 = V_104 ;
struct V_108 const * V_109 = V_110 ;
unsigned V_111 ;
T_2 V_112 , V_113 ;
int V_68 , V_30 = 0 ;
for ( V_68 = 0 ; V_68 < F_3 ( V_110 ) ; V_68 ++ , V_109 ++ ) {
if ( F_68 ( V_109 -> V_112 ) == ( V_61 -> V_114 & - V_109 -> V_111 ) &&
( 1 << F_49 ( V_31 ) -> V_51 & V_109 -> V_115 ) )
break;
}
if ( V_68 == F_3 ( V_110 ) )
return - V_116 ;
V_112 = V_109 -> V_112 ;
V_113 = V_109 -> V_113 ;
V_111 = V_109 -> V_111 ;
V_111 |= V_61 -> V_114 ^ F_68 ( V_112 ) ;
F_92 ( V_19 ) ;
switch ( V_111 ) {
case 8 | 1 :
V_61 -> V_117 = F_93 ( V_112 , V_113 ) ;
break;
case 8 :
V_61 -> V_117 = F_94 ( V_112 ) ;
break;
case 4 :
V_61 -> V_117 = F_95 ( V_112 ) ;
break;
case 2 :
V_61 -> V_117 = F_96 ( V_112 ) ;
break;
case 1 :
V_61 -> V_117 = F_97 ( V_112 ) ;
break;
default:
V_30 = - V_116 ;
goto V_118;
}
V_118:
F_98 ( V_19 ) ;
return V_30 ;
}
int F_99 ( struct V_43 * V_31 ,
void * V_104 , struct V_105 * V_106 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
struct V_119 * args = V_104 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
int V_30 ;
if ( args -> V_124 || args -> V_125 )
return - V_116 ;
if ( args -> V_126 == V_127 && ! F_100 ( V_128 ) )
return - V_129 ;
V_30 = F_101 ( & V_31 -> V_92 ) ;
if ( V_30 )
return V_30 ;
V_123 = F_102 ( V_106 -> V_130 , args -> V_126 ) ;
if ( F_103 ( V_123 ) ) {
F_84 ( & V_31 -> V_92 ) ;
return F_104 ( V_123 ) ;
}
V_121 = & V_123 -> V_131 ;
if ( F_100 ( V_128 ) )
args -> V_132 = F_105 ( & V_19 -> V_133 ) ;
else
args -> V_132 = 0 ;
args -> V_134 = V_121 -> V_134 ;
args -> V_135 = V_121 -> V_135 ;
F_84 ( & V_31 -> V_92 ) ;
return 0 ;
}
static int F_106 ( struct V_43 * V_31 )
{
T_3 V_136 ;
F_107 ( V_31 -> V_137 , V_138 , & V_136 ) ;
return ( V_136 & V_139 ) == 0 ;
}
static int F_108 ( struct V_43 * V_31 )
{
F_109 ( V_31 -> V_137 , V_138 , V_140 ) ;
F_34 ( 20 ) ;
F_109 ( V_31 -> V_137 , V_138 , 0 ) ;
return F_110 ( F_106 ( V_31 ) , 500 ) ;
}
static int F_111 ( struct V_43 * V_31 )
{
T_3 V_136 ;
F_107 ( V_31 -> V_137 , V_138 , & V_136 ) ;
return ( V_136 & V_140 ) == 0 ;
}
static int F_112 ( struct V_43 * V_31 )
{
F_109 ( V_31 -> V_137 , V_138 , V_140 ) ;
return F_110 ( F_111 ( V_31 ) , 500 ) ;
}
static int F_113 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
int V_30 ;
F_109 ( V_31 -> V_137 , V_138 ,
V_141 | V_140 ) ;
V_30 = F_110 ( F_111 ( V_31 ) , 500 ) ;
if ( V_30 )
return V_30 ;
F_114 ( V_142 , F_95 ( V_142 ) | V_143 ) ;
F_115 ( V_142 ) ;
F_109 ( V_31 -> V_137 , V_138 ,
V_144 | V_140 ) ;
V_30 = F_110 ( F_111 ( V_31 ) , 500 ) ;
if ( V_30 )
return V_30 ;
F_114 ( V_142 , F_95 ( V_142 ) & ~ V_143 ) ;
F_115 ( V_142 ) ;
F_109 ( V_31 -> V_137 , V_138 , 0 ) ;
return 0 ;
}
static int F_116 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
int V_30 ;
F_114 ( V_145 ,
V_146 | V_147 ) ;
V_30 = F_110 ( ( F_95 ( V_145 ) &
V_147 ) == 0 , 500 ) ;
if ( V_30 )
return V_30 ;
F_114 ( V_145 ,
V_148 | V_147 ) ;
V_30 = F_110 ( ( F_95 ( V_145 ) &
V_147 ) == 0 , 500 ) ;
if ( V_30 )
return V_30 ;
F_114 ( V_145 , 0 ) ;
return 0 ;
}
static int F_117 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
int V_30 ;
F_7 ( V_19 , V_149 , V_150 ) ;
V_30 = F_110 ( ( F_12 ( V_19 , V_149 ) & V_150 ) == 0 , 500 ) ;
F_39 ( V_31 , true ) ;
return V_30 ;
}
static int F_118 ( struct V_18 * V_19 ,
T_2 V_61 ,
const T_1 V_151 ,
const T_1 V_152 ,
const unsigned long V_153 )
{
return F_110 ( ( F_95 ( V_61 ) & V_151 ) == V_152 , V_153 ) ;
}
static int F_119 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
struct V_154 * V_155 ;
int V_68 ;
F_120 (engine, dev_priv, i) {
F_114 ( F_121 ( V_155 -> V_156 ) ,
F_77 ( V_157 ) ) ;
if ( F_118 ( V_19 ,
F_121 ( V_155 -> V_156 ) ,
V_158 ,
V_158 ,
700 ) ) {
F_13 ( L_18 , V_155 -> V_159 ) ;
goto V_160;
}
}
return F_117 ( V_31 ) ;
V_160:
F_120 (engine, dev_priv, i)
F_114 ( F_121 ( V_155 -> V_156 ) ,
F_76 ( V_157 ) ) ;
return - V_161 ;
}
bool F_122 ( struct V_43 * V_31 )
{
return F_123 ( V_31 ) != NULL ;
}
void F_124 ( struct V_43 * V_31 )
{
struct V_18 * V_19 = V_31 -> V_45 ;
if ( F_52 ( V_31 ) &&
( F_12 ( V_19 , V_56 ) & V_57 ) ) {
F_13 ( L_19 ) ;
F_7 ( V_19 , V_56 , V_57 ) ;
}
}
