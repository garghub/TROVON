const char *
F_1 ( const enum V_1 V_2 )
{
F_2 ( ( sizeof( V_3 ) / sizeof( const char * ) ) !=
V_4 ) ;
if ( V_2 >= 0 && V_2 < V_4 )
return V_3 [ V_2 ] ;
F_3 ( V_2 ) ;
return L_1 ;
}
static void
F_4 ( struct V_5 * V_6 )
{
F_5 ( F_6 ( V_6 -> V_7 ) && V_6 -> V_8 . V_9 ,
L_2 ) ;
}
static inline void
F_7 ( const struct V_10 * V_11 )
{
F_3 ( V_11 -> V_12 == 0 ) ;
F_8 ( V_11 -> V_13 , V_11 -> V_12 , V_11 -> V_14 ) ;
}
static inline void
F_9 ( struct V_10 * V_11 )
{
F_10 ( & V_11 -> V_15 , V_16 + 1 ) ;
}
static inline void
F_11 ( const struct V_10 * V_11 )
{
if ( F_12 ( ( F_13 ( V_11 -> V_13 , V_11 -> V_17 ) &
V_18 ) == 0 ,
V_19 ) )
F_14 ( L_3 ,
F_1 ( V_11 -> V_2 ) ) ;
}
static inline void
F_15 ( const struct V_10 * V_11 )
{
F_8 ( V_11 -> V_13 , V_11 -> V_12 , V_11 -> V_20 ) ;
}
static inline void
F_16 ( const struct V_10 * V_11 )
{
if ( F_12 ( ( F_13 ( V_11 -> V_13 , V_11 -> V_17 ) &
V_18 ) ,
V_19 ) )
F_14 ( L_4 ,
F_1 ( V_11 -> V_2 ) ) ;
}
static inline void
F_17 ( const struct V_10 * V_11 )
{
F_8 ( V_11 -> V_13 , V_11 -> V_12 , V_11 -> V_21 ) ;
}
static inline void
F_18 ( const struct V_10 * V_11 )
{
if ( V_11 -> V_22 )
F_19 ( V_11 -> V_13 , V_11 -> V_22 ) ;
}
static void
F_20 ( struct V_5 * V_6 , enum V_23 V_24 )
{
struct V_10 * V_11 ;
enum V_1 V_2 ;
F_21 (d, fw_domains, dev_priv, id) {
F_11 ( V_11 ) ;
F_15 ( V_11 ) ;
F_16 ( V_11 ) ;
}
}
static void
F_22 ( struct V_5 * V_6 , enum V_23 V_24 )
{
struct V_10 * V_11 ;
enum V_1 V_2 ;
F_21 (d, fw_domains, dev_priv, id) {
F_17 ( V_11 ) ;
F_18 ( V_11 ) ;
}
}
static void
F_23 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
enum V_1 V_2 ;
F_24 (d, dev_priv, id) {
F_18 ( V_11 ) ;
break;
}
}
static void
F_25 ( struct V_5 * V_6 , enum V_23 V_24 )
{
struct V_10 * V_11 ;
enum V_1 V_2 ;
if ( V_6 -> V_25 . V_24 == 0 )
return;
F_21 (d, fw_domains, dev_priv, id)
F_7 ( V_11 ) ;
F_23 ( V_6 ) ;
}
static void F_26 ( struct V_5 * V_6 )
{
if ( F_27 ( ( F_13 ( V_6 , V_26 ) &
V_27 ) == 0 , 500 ) )
F_14 ( L_5 ) ;
}
static void F_28 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
F_20 ( V_6 , V_24 ) ;
F_26 ( V_6 ) ;
}
static void F_29 ( struct V_5 * V_6 )
{
T_1 V_28 ;
V_28 = F_13 ( V_6 , V_29 ) ;
if ( F_30 ( V_28 , L_6 , V_28 ) )
F_8 ( V_6 , V_29 , V_28 ) ;
}
static void F_31 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
F_22 ( V_6 , V_24 ) ;
F_29 ( V_6 ) ;
}
static inline T_1 F_32 ( struct V_5 * V_6 )
{
T_1 V_30 = F_13 ( V_6 , V_31 ) ;
return V_30 & V_32 ;
}
static int F_33 ( struct V_5 * V_6 )
{
int V_33 = 0 ;
if ( F_34 ( V_6 -> V_7 ) )
V_6 -> V_25 . V_34 = F_32 ( V_6 ) ;
if ( V_6 -> V_25 . V_34 < V_35 ) {
int V_36 = 500 ;
T_1 V_37 = F_32 ( V_6 ) ;
while ( V_37 <= V_35 && V_36 -- ) {
F_35 ( 10 ) ;
V_37 = F_32 ( V_6 ) ;
}
if ( F_3 ( V_36 < 0 && V_37 <= V_35 ) )
++ V_33 ;
V_6 -> V_25 . V_34 = V_37 ;
}
V_6 -> V_25 . V_34 -- ;
return V_33 ;
}
static void F_36 ( unsigned long V_38 )
{
struct V_10 * V_39 = ( void * ) V_38 ;
unsigned long V_40 ;
F_4 ( V_39 -> V_13 ) ;
F_37 ( & V_39 -> V_13 -> V_25 . V_41 , V_40 ) ;
if ( F_3 ( V_39 -> V_42 == 0 ) )
V_39 -> V_42 ++ ;
if ( -- V_39 -> V_42 == 0 )
V_39 -> V_13 -> V_25 . V_43 . V_44 ( V_39 -> V_13 ,
1 << V_39 -> V_2 ) ;
F_38 ( & V_39 -> V_13 -> V_25 . V_41 , V_40 ) ;
}
void F_39 ( struct V_45 * V_7 , bool V_46 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
unsigned long V_40 ;
struct V_10 * V_39 ;
int V_48 = 100 ;
enum V_1 V_2 ;
enum V_23 V_49 = 0 , V_50 ;
while ( 1 ) {
V_50 = 0 ;
F_24 (domain, dev_priv, id) {
if ( F_40 ( & V_39 -> V_15 ) == 0 )
continue;
F_36 ( ( unsigned long ) V_39 ) ;
}
F_37 ( & V_6 -> V_25 . V_41 , V_40 ) ;
F_24 (domain, dev_priv, id) {
if ( F_41 ( & V_39 -> V_15 ) )
V_50 |= ( 1 << V_2 ) ;
}
if ( V_50 == 0 )
break;
if ( -- V_48 == 0 ) {
F_14 ( L_7 ) ;
break;
}
F_38 ( & V_6 -> V_25 . V_41 , V_40 ) ;
F_42 () ;
}
F_3 ( V_50 ) ;
F_24 (domain, dev_priv, id)
if ( V_39 -> V_42 )
V_49 |= 1 << V_2 ;
if ( V_49 )
V_6 -> V_25 . V_43 . V_44 ( V_6 , V_49 ) ;
F_25 ( V_6 , V_51 ) ;
if ( V_46 ) {
if ( V_49 )
V_6 -> V_25 . V_43 . V_52 ( V_6 , V_49 ) ;
if ( F_43 ( V_7 ) || F_44 ( V_7 ) )
V_6 -> V_25 . V_34 =
F_32 ( V_6 ) ;
}
if ( ! V_46 )
F_45 ( V_6 ) ;
F_38 ( & V_6 -> V_25 . V_41 , V_40 ) ;
}
static void F_46 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
if ( ( F_47 ( V_7 ) || F_48 ( V_7 ) ||
F_49 ( V_7 ) -> V_53 >= 9 ) &&
( F_13 ( V_6 , V_54 ) & V_55 ) ) {
V_6 -> V_56 = 128 ;
F_50 ( L_8 , V_6 -> V_56 ) ;
}
}
static void F_51 ( struct V_45 * V_7 ,
bool V_57 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
if ( F_52 ( V_7 ) )
F_8 ( V_6 , V_58 , V_59 ) ;
if ( F_43 ( V_7 ) || F_44 ( V_7 ) )
F_8 ( V_6 , V_29 ,
F_13 ( V_6 , V_29 ) ) ;
if ( F_53 ( V_7 ) ) {
F_8 ( V_6 , V_31 ,
F_13 ( V_6 , V_31 ) |
V_60 |
V_61 ) ;
}
F_39 ( V_7 , V_57 ) ;
}
void F_54 ( struct V_45 * V_7 , bool V_57 )
{
F_51 ( V_7 , V_57 ) ;
F_55 ( V_7 ) ;
}
void F_56 ( struct V_45 * V_7 )
{
F_57 ( V_7 ) ;
}
static void F_58 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
struct V_10 * V_39 ;
enum V_1 V_2 ;
if ( ! V_6 -> V_25 . V_43 . V_52 )
return;
V_24 &= V_6 -> V_25 . V_24 ;
F_21 (domain, fw_domains, dev_priv, id) {
if ( V_39 -> V_42 ++ )
V_24 &= ~ ( 1 << V_2 ) ;
}
if ( V_24 )
V_6 -> V_25 . V_43 . V_52 ( V_6 , V_24 ) ;
}
void F_59 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
unsigned long V_40 ;
if ( ! V_6 -> V_25 . V_43 . V_52 )
return;
F_3 ( V_6 -> V_8 . V_9 ) ;
F_37 ( & V_6 -> V_25 . V_41 , V_40 ) ;
F_58 ( V_6 , V_24 ) ;
F_38 ( & V_6 -> V_25 . V_41 , V_40 ) ;
}
void F_60 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
F_61 ( & V_6 -> V_25 . V_41 ) ;
if ( ! V_6 -> V_25 . V_43 . V_52 )
return;
F_58 ( V_6 , V_24 ) ;
}
static void F_62 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
struct V_10 * V_39 ;
enum V_1 V_2 ;
if ( ! V_6 -> V_25 . V_43 . V_44 )
return;
V_24 &= V_6 -> V_25 . V_24 ;
F_21 (domain, fw_domains, dev_priv, id) {
if ( F_3 ( V_39 -> V_42 == 0 ) )
continue;
if ( -- V_39 -> V_42 )
continue;
V_39 -> V_42 ++ ;
F_9 ( V_39 ) ;
}
}
void F_63 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
unsigned long V_40 ;
if ( ! V_6 -> V_25 . V_43 . V_44 )
return;
F_37 ( & V_6 -> V_25 . V_41 , V_40 ) ;
F_62 ( V_6 , V_24 ) ;
F_38 ( & V_6 -> V_25 . V_41 , V_40 ) ;
}
void F_64 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
F_61 ( & V_6 -> V_25 . V_41 ) ;
if ( ! V_6 -> V_25 . V_43 . V_44 )
return;
F_62 ( V_6 , V_24 ) ;
}
void F_45 ( struct V_5 * V_6 )
{
struct V_10 * V_39 ;
enum V_1 V_2 ;
if ( ! V_6 -> V_25 . V_43 . V_52 )
return;
F_24 (domain, dev_priv, id)
F_3 ( V_39 -> V_42 ) ;
}
static void
F_65 ( struct V_5 * V_6 )
{
F_8 ( V_6 , V_62 , 0 ) ;
}
static void
F_66 ( struct V_5 * V_6 , T_1 V_63 , bool V_64 ,
bool V_65 )
{
const char * V_66 = V_64 ? L_9 : L_10 ;
const char * V_67 = V_65 ? L_11 : L_12 ;
if ( ! V_13 . V_68 )
return;
if ( F_13 ( V_6 , V_58 ) & V_59 ) {
F_30 ( 1 , L_13 ,
V_67 , V_66 , V_63 ) ;
F_8 ( V_6 , V_58 , V_59 ) ;
V_13 . V_68 -- ;
}
}
static void
F_67 ( struct V_5 * V_6 )
{
static bool V_69 = true ;
if ( V_13 . V_68 || ! V_69 )
return;
if ( F_13 ( V_6 , V_58 ) & V_59 ) {
F_68 ( L_14
L_15
L_16 ) ;
F_8 ( V_6 , V_58 , V_59 ) ;
V_13 . V_68 = V_69 -- ;
}
}
static inline void F_69 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
struct V_10 * V_39 ;
enum V_1 V_2 ;
if ( F_3 ( ! V_24 ) )
return;
F_21 (domain, fw_domains, dev_priv, id) {
if ( V_39 -> V_42 ) {
V_24 &= ~ ( 1 << V_2 ) ;
continue;
}
V_39 -> V_42 ++ ;
F_9 ( V_39 ) ;
}
if ( V_24 )
V_6 -> V_25 . V_43 . V_52 ( V_6 , V_24 ) ;
}
static bool F_70 ( struct V_5 * V_6 , T_1 V_63 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_71 ( V_71 ) ; V_70 ++ )
if ( V_63 == V_71 [ V_70 ] )
return true ;
return false ;
}
static bool F_72 ( struct V_5 * V_6 , T_1 V_63 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_71 ( V_72 ) ; V_70 ++ )
if ( V_63 == V_72 [ V_70 ] )
return true ;
return false ;
}
static void F_73 ( struct V_5 * V_6 ,
enum V_1 V_73 ,
T_1 V_12 , T_1 V_17 )
{
struct V_10 * V_11 ;
if ( F_3 ( V_73 >= V_4 ) )
return;
V_11 = & V_6 -> V_25 . V_74 [ V_73 ] ;
F_3 ( V_11 -> V_42 ) ;
V_11 -> V_42 = 0 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_17 = V_17 ;
if ( F_43 ( V_6 ) ) {
V_11 -> V_14 = 0 ;
V_11 -> V_20 = V_18 ;
V_11 -> V_21 = 0 ;
} else {
V_11 -> V_14 = F_74 ( 0xffff ) ;
V_11 -> V_20 = F_75 ( V_18 ) ;
V_11 -> V_21 = F_74 ( V_18 ) ;
}
if ( F_34 ( V_6 ) )
V_11 -> V_22 = V_75 ;
else if ( F_43 ( V_6 ) || F_44 ( V_6 ) || F_76 ( V_6 ) )
V_11 -> V_22 = V_76 ;
else
V_11 -> V_22 = 0 ;
V_11 -> V_13 = V_6 ;
V_11 -> V_2 = V_73 ;
F_77 ( & V_11 -> V_15 , F_36 , ( unsigned long ) V_11 ) ;
V_6 -> V_25 . V_24 |= ( 1 << V_73 ) ;
F_7 ( V_11 ) ;
}
static void F_78 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
if ( F_49 ( V_6 -> V_7 ) -> V_53 <= 5 )
return;
if ( F_79 ( V_7 ) ) {
V_6 -> V_25 . V_43 . V_52 = F_20 ;
V_6 -> V_25 . V_43 . V_44 = F_22 ;
F_73 ( V_6 , V_77 ,
V_78 ,
V_79 ) ;
F_73 ( V_6 , V_80 ,
V_81 ,
V_82 ) ;
F_73 ( V_6 , V_83 ,
V_84 , V_85 ) ;
} else if ( F_34 ( V_7 ) ) {
V_6 -> V_25 . V_43 . V_52 = F_20 ;
if ( ! F_53 ( V_7 ) )
V_6 -> V_25 . V_43 . V_44 =
F_31 ;
else
V_6 -> V_25 . V_43 . V_44 = F_22 ;
F_73 ( V_6 , V_77 ,
V_86 , V_75 ) ;
F_73 ( V_6 , V_83 ,
V_87 , V_88 ) ;
} else if ( F_47 ( V_7 ) || F_48 ( V_7 ) ) {
V_6 -> V_25 . V_43 . V_52 =
F_28 ;
V_6 -> V_25 . V_43 . V_44 = F_22 ;
F_73 ( V_6 , V_77 ,
V_89 , V_90 ) ;
} else if ( F_80 ( V_7 ) ) {
T_1 V_91 ;
V_6 -> V_25 . V_43 . V_52 =
F_28 ;
V_6 -> V_25 . V_43 . V_44 =
F_31 ;
F_8 ( V_6 , V_92 , 0 ) ;
F_19 ( V_6 , V_76 ) ;
F_73 ( V_6 , V_77 ,
V_89 , V_93 ) ;
F_81 ( & V_7 -> V_94 ) ;
F_28 ( V_6 , V_51 ) ;
V_91 = F_13 ( V_6 , V_76 ) ;
F_31 ( V_6 , V_51 ) ;
F_82 ( & V_7 -> V_94 ) ;
if ( ! ( V_91 & V_95 ) ) {
F_50 ( L_17 ) ;
F_50 ( L_18 ) ;
F_73 ( V_6 , V_77 ,
V_92 , V_96 ) ;
}
} else if ( F_43 ( V_7 ) ) {
V_6 -> V_25 . V_43 . V_52 =
F_28 ;
V_6 -> V_25 . V_43 . V_44 =
F_31 ;
F_73 ( V_6 , V_77 ,
V_92 , V_96 ) ;
}
F_3 ( V_6 -> V_25 . V_24 == 0 ) ;
}
void F_83 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
F_84 ( V_7 ) ;
F_46 ( V_7 ) ;
F_78 ( V_7 ) ;
F_51 ( V_7 , false ) ;
switch ( F_49 ( V_7 ) -> V_53 ) {
default:
F_85 ( F_49 ( V_7 ) -> V_53 ) ;
return;
case 9 :
F_86 ( V_97 ) ;
F_87 ( V_97 ) ;
break;
case 8 :
if ( F_53 ( V_7 ) ) {
F_86 ( V_98 ) ;
F_87 ( V_98 ) ;
} else {
F_86 ( V_99 ) ;
F_87 ( V_100 ) ;
}
break;
case 7 :
case 6 :
if ( F_47 ( V_7 ) ) {
F_86 ( V_101 ) ;
} else {
F_86 ( V_100 ) ;
}
if ( F_34 ( V_7 ) ) {
F_87 ( V_102 ) ;
} else {
F_87 ( V_100 ) ;
}
break;
case 5 :
F_86 ( V_103 ) ;
F_87 ( V_103 ) ;
break;
case 4 :
case 3 :
case 2 :
F_86 ( V_104 ) ;
F_87 ( V_104 ) ;
break;
}
if ( F_88 ( V_7 ) ) {
F_86 ( V_105 ) ;
F_87 ( V_105 ) ;
}
F_55 ( V_7 ) ;
}
void F_89 ( struct V_45 * V_7 )
{
F_56 ( V_7 ) ;
F_39 ( V_7 , false ) ;
}
int F_90 ( struct V_45 * V_7 ,
void * V_106 , struct V_107 * V_108 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
struct V_109 * V_63 = V_106 ;
struct V_110 const * V_111 = V_112 ;
unsigned V_113 ;
T_2 V_114 ;
int V_70 , V_33 = 0 ;
for ( V_70 = 0 ; V_70 < F_71 ( V_112 ) ; V_70 ++ , V_111 ++ ) {
if ( V_111 -> V_114 == ( V_63 -> V_114 & - V_111 -> V_113 ) &&
( 1 << F_49 ( V_7 ) -> V_53 & V_111 -> V_115 ) )
break;
}
if ( V_70 == F_71 ( V_112 ) )
return - V_116 ;
V_114 = V_111 -> V_114 ;
V_113 = V_111 -> V_113 ;
V_113 |= V_63 -> V_114 ^ V_114 ;
F_91 ( V_6 ) ;
switch ( V_113 ) {
case 8 | 1 :
V_63 -> V_117 = F_92 ( V_114 , V_114 + 4 ) ;
break;
case 8 :
V_63 -> V_117 = F_93 ( V_114 ) ;
break;
case 4 :
V_63 -> V_117 = F_94 ( V_114 ) ;
break;
case 2 :
V_63 -> V_117 = F_95 ( V_114 ) ;
break;
case 1 :
V_63 -> V_117 = F_96 ( V_114 ) ;
break;
default:
V_33 = - V_116 ;
goto V_118;
}
V_118:
F_97 ( V_6 ) ;
return V_33 ;
}
int F_98 ( struct V_45 * V_7 ,
void * V_106 , struct V_107 * V_108 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
struct V_119 * args = V_106 ;
struct V_120 * V_121 ;
struct V_122 * V_123 ;
int V_33 ;
if ( args -> V_124 || args -> V_125 )
return - V_116 ;
if ( args -> V_126 == V_127 && ! F_99 ( V_128 ) )
return - V_129 ;
V_33 = F_100 ( & V_7 -> V_94 ) ;
if ( V_33 )
return V_33 ;
V_123 = F_101 ( V_108 -> V_130 , args -> V_126 ) ;
if ( F_102 ( V_123 ) ) {
F_82 ( & V_7 -> V_94 ) ;
return F_103 ( V_123 ) ;
}
V_121 = & V_123 -> V_131 ;
if ( F_99 ( V_128 ) )
args -> V_132 = F_104 ( & V_6 -> V_133 ) ;
else
args -> V_132 = 0 ;
args -> V_134 = V_121 -> V_134 ;
args -> V_135 = V_121 -> V_135 ;
F_82 ( & V_7 -> V_94 ) ;
return 0 ;
}
static int F_105 ( struct V_45 * V_7 )
{
T_3 V_136 ;
F_106 ( V_7 -> V_137 , V_138 , & V_136 ) ;
return ( V_136 & V_139 ) == 0 ;
}
static int F_107 ( struct V_45 * V_7 )
{
F_108 ( V_7 -> V_137 , V_138 , V_140 ) ;
F_35 ( 20 ) ;
F_108 ( V_7 -> V_137 , V_138 , 0 ) ;
return F_109 ( F_105 ( V_7 ) , 500 ) ;
}
static int F_110 ( struct V_45 * V_7 )
{
T_3 V_136 ;
F_106 ( V_7 -> V_137 , V_138 , & V_136 ) ;
return ( V_136 & V_140 ) == 0 ;
}
static int F_111 ( struct V_45 * V_7 )
{
F_108 ( V_7 -> V_137 , V_138 , V_140 ) ;
return F_109 ( F_110 ( V_7 ) , 500 ) ;
}
static int F_112 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
int V_33 ;
F_108 ( V_7 -> V_137 , V_138 ,
V_141 | V_140 ) ;
V_33 = F_109 ( F_110 ( V_7 ) , 500 ) ;
if ( V_33 )
return V_33 ;
F_113 ( V_142 , F_94 ( V_142 ) | V_143 ) ;
F_114 ( V_142 ) ;
F_108 ( V_7 -> V_137 , V_138 ,
V_144 | V_140 ) ;
V_33 = F_109 ( F_110 ( V_7 ) , 500 ) ;
if ( V_33 )
return V_33 ;
F_113 ( V_142 , F_94 ( V_142 ) & ~ V_143 ) ;
F_114 ( V_142 ) ;
F_108 ( V_7 -> V_137 , V_138 , 0 ) ;
return 0 ;
}
static int F_115 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
int V_33 ;
F_113 ( V_145 + V_146 ,
V_147 | V_148 ) ;
V_33 = F_109 ( ( F_94 ( V_145 + V_146 ) &
V_148 ) == 0 , 500 ) ;
if ( V_33 )
return V_33 ;
F_113 ( V_145 + V_146 ,
V_149 | V_148 ) ;
V_33 = F_109 ( ( F_94 ( V_145 + V_146 ) &
V_148 ) == 0 , 500 ) ;
if ( V_33 )
return V_33 ;
F_113 ( V_145 + V_146 , 0 ) ;
return 0 ;
}
static int F_116 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
int V_33 ;
F_8 ( V_6 , V_150 , V_151 ) ;
V_33 = F_109 ( ( F_13 ( V_6 , V_150 ) & V_151 ) == 0 , 500 ) ;
F_39 ( V_7 , true ) ;
return V_33 ;
}
int F_117 ( struct V_45 * V_7 )
{
if ( F_49 ( V_7 ) -> V_53 >= 6 )
return F_116 ( V_7 ) ;
else if ( F_118 ( V_7 ) )
return F_115 ( V_7 ) ;
else if ( F_119 ( V_7 ) )
return F_112 ( V_7 ) ;
else if ( F_120 ( V_7 ) )
return F_111 ( V_7 ) ;
else if ( F_49 ( V_7 ) -> V_53 >= 3 )
return F_107 ( V_7 ) ;
else
return - V_152 ;
}
void F_121 ( struct V_45 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_47 ;
if ( F_52 ( V_7 ) &&
( F_13 ( V_6 , V_58 ) & V_59 ) ) {
F_14 ( L_19 ) ;
F_8 ( V_6 , V_58 , V_59 ) ;
}
}
