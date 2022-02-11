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
static int F_32 ( struct V_5 * V_6 )
{
int V_30 = 0 ;
if ( F_33 ( V_6 -> V_7 ) )
V_6 -> V_25 . V_31 =
F_13 ( V_6 , V_32 ) &
V_33 ;
if ( V_6 -> V_25 . V_31 < V_34 ) {
int V_35 = 500 ;
T_1 V_36 = F_13 ( V_6 , V_32 ) & V_33 ;
while ( V_36 <= V_34 && V_35 -- ) {
F_34 ( 10 ) ;
V_36 = F_13 ( V_6 , V_32 ) & V_33 ;
}
if ( F_3 ( V_35 < 0 && V_36 <= V_34 ) )
++ V_30 ;
V_6 -> V_25 . V_31 = V_36 ;
}
V_6 -> V_25 . V_31 -- ;
return V_30 ;
}
static void F_35 ( unsigned long V_37 )
{
struct V_10 * V_38 = ( void * ) V_37 ;
unsigned long V_39 ;
F_4 ( V_38 -> V_13 ) ;
F_36 ( & V_38 -> V_13 -> V_25 . V_40 , V_39 ) ;
if ( F_3 ( V_38 -> V_41 == 0 ) )
V_38 -> V_41 ++ ;
if ( -- V_38 -> V_41 == 0 )
V_38 -> V_13 -> V_25 . V_42 . V_43 ( V_38 -> V_13 ,
1 << V_38 -> V_2 ) ;
F_37 ( & V_38 -> V_13 -> V_25 . V_40 , V_39 ) ;
}
void F_38 ( struct V_44 * V_7 , bool V_45 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
unsigned long V_39 ;
struct V_10 * V_38 ;
int V_47 = 100 ;
enum V_1 V_2 ;
enum V_23 V_48 = 0 , V_49 ;
while ( 1 ) {
V_49 = 0 ;
F_24 (domain, dev_priv, id) {
if ( F_39 ( & V_38 -> V_15 ) == 0 )
continue;
F_35 ( ( unsigned long ) V_38 ) ;
}
F_36 ( & V_6 -> V_25 . V_40 , V_39 ) ;
F_24 (domain, dev_priv, id) {
if ( F_40 ( & V_38 -> V_15 ) )
V_49 |= ( 1 << V_2 ) ;
}
if ( V_49 == 0 )
break;
if ( -- V_47 == 0 ) {
F_14 ( L_7 ) ;
break;
}
F_37 ( & V_6 -> V_25 . V_40 , V_39 ) ;
F_41 () ;
}
F_3 ( V_49 ) ;
F_24 (domain, dev_priv, id)
if ( V_38 -> V_41 )
V_48 |= 1 << V_2 ;
if ( V_48 )
V_6 -> V_25 . V_42 . V_43 ( V_6 , V_48 ) ;
F_25 ( V_6 , V_50 ) ;
if ( V_45 ) {
if ( V_48 )
V_6 -> V_25 . V_42 . V_51 ( V_6 , V_48 ) ;
if ( F_42 ( V_7 ) || F_43 ( V_7 ) )
V_6 -> V_25 . V_31 =
F_13 ( V_6 , V_32 ) &
V_33 ;
}
if ( ! V_45 )
F_44 ( V_6 ) ;
F_37 ( & V_6 -> V_25 . V_40 , V_39 ) ;
}
static void F_45 ( struct V_44 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
if ( ( F_46 ( V_7 ) || F_47 ( V_7 ) ) &&
( F_13 ( V_6 , V_52 ) == 1 ) ) {
V_6 -> V_53 = 128 ;
F_48 ( L_8 , V_6 -> V_53 ) ;
}
}
static void F_49 ( struct V_44 * V_7 ,
bool V_54 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
if ( F_50 ( V_7 ) )
F_8 ( V_6 , V_55 , V_56 ) ;
if ( F_42 ( V_7 ) || F_43 ( V_7 ) )
F_8 ( V_6 , V_29 ,
F_13 ( V_6 , V_29 ) ) ;
F_38 ( V_7 , V_54 ) ;
}
void F_51 ( struct V_44 * V_7 , bool V_54 )
{
F_49 ( V_7 , V_54 ) ;
F_52 ( V_7 ) ;
}
void F_53 ( struct V_44 * V_7 )
{
F_54 ( V_7 ) ;
}
void F_55 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
unsigned long V_39 ;
struct V_10 * V_38 ;
enum V_1 V_2 ;
if ( ! V_6 -> V_25 . V_42 . V_51 )
return;
F_3 ( V_6 -> V_8 . V_9 ) ;
V_24 &= V_6 -> V_25 . V_24 ;
F_36 ( & V_6 -> V_25 . V_40 , V_39 ) ;
F_21 (domain, fw_domains, dev_priv, id) {
if ( V_38 -> V_41 ++ )
V_24 &= ~ ( 1 << V_2 ) ;
}
if ( V_24 )
V_6 -> V_25 . V_42 . V_51 ( V_6 , V_24 ) ;
F_37 ( & V_6 -> V_25 . V_40 , V_39 ) ;
}
void F_56 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
unsigned long V_39 ;
struct V_10 * V_38 ;
enum V_1 V_2 ;
if ( ! V_6 -> V_25 . V_42 . V_43 )
return;
V_24 &= V_6 -> V_25 . V_24 ;
F_36 ( & V_6 -> V_25 . V_40 , V_39 ) ;
F_21 (domain, fw_domains, dev_priv, id) {
if ( F_3 ( V_38 -> V_41 == 0 ) )
continue;
if ( -- V_38 -> V_41 )
continue;
V_38 -> V_41 ++ ;
F_9 ( V_38 ) ;
}
F_37 ( & V_6 -> V_25 . V_40 , V_39 ) ;
}
void F_44 ( struct V_5 * V_6 )
{
struct V_10 * V_38 ;
enum V_1 V_2 ;
if ( ! V_6 -> V_25 . V_42 . V_51 )
return;
F_24 (domain, dev_priv, id)
F_3 ( V_38 -> V_41 ) ;
}
static void
F_57 ( struct V_5 * V_6 )
{
F_8 ( V_6 , V_57 , 0 ) ;
}
static void
F_58 ( struct V_5 * V_6 , T_1 V_58 , bool V_59 ,
bool V_60 )
{
const char * V_61 = V_59 ? L_9 : L_10 ;
const char * V_62 = V_60 ? L_11 : L_12 ;
if ( ! V_13 . V_63 )
return;
if ( F_13 ( V_6 , V_55 ) & V_56 ) {
F_30 ( 1 , L_13 ,
V_62 , V_61 , V_58 ) ;
F_8 ( V_6 , V_55 , V_56 ) ;
}
}
static void
F_59 ( struct V_5 * V_6 )
{
if ( V_13 . V_63 )
return;
if ( F_13 ( V_6 , V_55 ) & V_56 ) {
F_14 ( L_14 ) ;
F_8 ( V_6 , V_55 , V_56 ) ;
}
}
static inline void F_60 ( struct V_5 * V_6 ,
enum V_23 V_24 )
{
struct V_10 * V_38 ;
enum V_1 V_2 ;
if ( F_3 ( ! V_24 ) )
return;
F_21 (domain, fw_domains, dev_priv, id) {
if ( V_38 -> V_41 ) {
V_24 &= ~ ( 1 << V_2 ) ;
continue;
}
V_38 -> V_41 ++ ;
F_9 ( V_38 ) ;
}
if ( V_24 )
V_6 -> V_25 . V_42 . V_51 ( V_6 , V_24 ) ;
}
static bool F_61 ( struct V_5 * V_6 , T_1 V_58 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < F_62 ( V_65 ) ; V_64 ++ )
if ( V_58 == V_65 [ V_64 ] )
return true ;
return false ;
}
static bool F_63 ( struct V_5 * V_6 , T_1 V_58 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < F_62 ( V_66 ) ; V_64 ++ )
if ( V_58 == V_66 [ V_64 ] )
return true ;
return false ;
}
static void F_64 ( struct V_5 * V_6 ,
enum V_1 V_67 ,
T_1 V_12 , T_1 V_17 )
{
struct V_10 * V_11 ;
if ( F_3 ( V_67 >= V_4 ) )
return;
V_11 = & V_6 -> V_25 . V_68 [ V_67 ] ;
F_3 ( V_11 -> V_41 ) ;
V_11 -> V_41 = 0 ;
V_11 -> V_12 = V_12 ;
V_11 -> V_17 = V_17 ;
if ( F_42 ( V_6 ) ) {
V_11 -> V_14 = 0 ;
V_11 -> V_20 = V_18 ;
V_11 -> V_21 = 0 ;
} else {
V_11 -> V_14 = F_65 ( 0xffff ) ;
V_11 -> V_20 = F_66 ( V_18 ) ;
V_11 -> V_21 = F_65 ( V_18 ) ;
}
if ( F_33 ( V_6 ) )
V_11 -> V_22 = V_69 ;
else if ( F_42 ( V_6 ) || F_43 ( V_6 ) || F_67 ( V_6 ) )
V_11 -> V_22 = V_70 ;
else
V_11 -> V_22 = 0 ;
V_11 -> V_13 = V_6 ;
V_11 -> V_2 = V_67 ;
F_68 ( & V_11 -> V_15 , F_35 , ( unsigned long ) V_11 ) ;
V_6 -> V_25 . V_24 |= ( 1 << V_67 ) ;
F_7 ( V_11 ) ;
}
static void F_69 ( struct V_44 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
if ( F_70 ( V_6 -> V_7 ) -> V_71 <= 5 )
return;
if ( F_71 ( V_7 ) ) {
V_6 -> V_25 . V_42 . V_51 = F_20 ;
V_6 -> V_25 . V_42 . V_43 = F_22 ;
F_64 ( V_6 , V_72 ,
V_73 ,
V_74 ) ;
F_64 ( V_6 , V_75 ,
V_76 ,
V_77 ) ;
F_64 ( V_6 , V_78 ,
V_79 , V_80 ) ;
} else if ( F_33 ( V_7 ) ) {
V_6 -> V_25 . V_42 . V_51 = F_20 ;
if ( ! F_72 ( V_7 ) )
V_6 -> V_25 . V_42 . V_43 =
F_31 ;
else
V_6 -> V_25 . V_42 . V_43 = F_22 ;
F_64 ( V_6 , V_72 ,
V_81 , V_69 ) ;
F_64 ( V_6 , V_78 ,
V_82 , V_83 ) ;
} else if ( F_46 ( V_7 ) || F_47 ( V_7 ) ) {
V_6 -> V_25 . V_42 . V_51 =
F_28 ;
V_6 -> V_25 . V_42 . V_43 = F_22 ;
F_64 ( V_6 , V_72 ,
V_84 , V_85 ) ;
} else if ( F_73 ( V_7 ) ) {
T_1 V_86 ;
V_6 -> V_25 . V_42 . V_51 =
F_28 ;
V_6 -> V_25 . V_42 . V_43 =
F_31 ;
F_8 ( V_6 , V_87 , 0 ) ;
F_19 ( V_6 , V_70 ) ;
F_64 ( V_6 , V_72 ,
V_84 , V_88 ) ;
F_74 ( & V_7 -> V_89 ) ;
F_28 ( V_6 , V_50 ) ;
V_86 = F_13 ( V_6 , V_70 ) ;
F_31 ( V_6 , V_50 ) ;
F_75 ( & V_7 -> V_89 ) ;
if ( ! ( V_86 & V_90 ) ) {
F_48 ( L_15 ) ;
F_48 ( L_16 ) ;
F_64 ( V_6 , V_72 ,
V_87 , V_91 ) ;
}
} else if ( F_42 ( V_7 ) ) {
V_6 -> V_25 . V_42 . V_51 =
F_28 ;
V_6 -> V_25 . V_42 . V_43 =
F_31 ;
F_64 ( V_6 , V_72 ,
V_87 , V_91 ) ;
}
F_3 ( V_6 -> V_25 . V_24 == 0 ) ;
}
void F_76 ( struct V_44 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
F_45 ( V_7 ) ;
F_69 ( V_7 ) ;
F_49 ( V_7 , false ) ;
switch ( F_70 ( V_7 ) -> V_71 ) {
default:
F_77 ( F_70 ( V_7 ) -> V_71 ) ;
return;
case 9 :
F_78 ( V_92 ) ;
F_79 ( V_92 ) ;
break;
case 8 :
if ( F_72 ( V_7 ) ) {
F_78 ( V_93 ) ;
F_79 ( V_93 ) ;
} else {
F_78 ( V_94 ) ;
F_79 ( V_95 ) ;
}
break;
case 7 :
case 6 :
if ( F_46 ( V_7 ) ) {
F_78 ( V_96 ) ;
} else {
F_78 ( V_95 ) ;
}
if ( F_33 ( V_7 ) ) {
F_79 ( V_97 ) ;
} else {
F_79 ( V_95 ) ;
}
break;
case 5 :
F_78 ( V_98 ) ;
F_79 ( V_98 ) ;
break;
case 4 :
case 3 :
case 2 :
F_78 ( V_99 ) ;
F_79 ( V_99 ) ;
break;
}
F_52 ( V_7 ) ;
}
void F_80 ( struct V_44 * V_7 )
{
F_53 ( V_7 ) ;
F_38 ( V_7 , false ) ;
}
int F_81 ( struct V_44 * V_7 ,
void * V_100 , struct V_101 * V_102 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
struct V_103 * V_58 = V_100 ;
struct V_104 const * V_105 = V_106 ;
int V_64 , V_30 = 0 ;
for ( V_64 = 0 ; V_64 < F_62 ( V_106 ) ; V_64 ++ , V_105 ++ ) {
if ( V_105 -> V_107 == V_58 -> V_107 &&
( 1 << F_70 ( V_7 ) -> V_71 & V_105 -> V_108 ) )
break;
}
if ( V_64 == F_62 ( V_106 ) )
return - V_109 ;
F_82 ( V_6 ) ;
switch ( V_105 -> V_110 ) {
case 8 :
V_58 -> V_111 = F_83 ( V_58 -> V_107 ) ;
break;
case 4 :
V_58 -> V_111 = F_84 ( V_58 -> V_107 ) ;
break;
case 2 :
V_58 -> V_111 = F_85 ( V_58 -> V_107 ) ;
break;
case 1 :
V_58 -> V_111 = F_86 ( V_58 -> V_107 ) ;
break;
default:
F_77 ( V_105 -> V_110 ) ;
V_30 = - V_109 ;
goto V_112;
}
V_112:
F_87 ( V_6 ) ;
return V_30 ;
}
int F_88 ( struct V_44 * V_7 ,
void * V_100 , struct V_101 * V_102 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
struct V_113 * args = V_100 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
int V_30 ;
if ( args -> V_118 || args -> V_119 )
return - V_109 ;
if ( args -> V_120 == V_121 && ! F_89 ( V_122 ) )
return - V_123 ;
V_30 = F_90 ( & V_7 -> V_89 ) ;
if ( V_30 )
return V_30 ;
V_117 = F_91 ( V_102 -> V_124 , args -> V_120 ) ;
if ( F_92 ( V_117 ) ) {
F_75 ( & V_7 -> V_89 ) ;
return F_93 ( V_117 ) ;
}
V_115 = & V_117 -> V_125 ;
if ( F_89 ( V_122 ) )
args -> V_126 = F_94 ( & V_6 -> V_127 ) ;
else
args -> V_126 = 0 ;
args -> V_128 = V_115 -> V_128 ;
args -> V_129 = V_115 -> V_129 ;
F_75 ( & V_7 -> V_89 ) ;
return 0 ;
}
static int F_95 ( struct V_44 * V_7 )
{
T_2 V_130 ;
F_96 ( V_7 -> V_131 , V_132 , & V_130 ) ;
return ( V_130 & V_133 ) == 0 ;
}
static int F_97 ( struct V_44 * V_7 )
{
F_98 ( V_7 -> V_131 , V_132 , V_134 ) ;
F_34 ( 20 ) ;
F_98 ( V_7 -> V_131 , V_132 , 0 ) ;
return F_99 ( F_95 ( V_7 ) , 500 ) ;
}
static int F_100 ( struct V_44 * V_7 )
{
T_2 V_130 ;
F_96 ( V_7 -> V_131 , V_132 , & V_130 ) ;
return ( V_130 & V_134 ) == 0 ;
}
static int F_101 ( struct V_44 * V_7 )
{
F_98 ( V_7 -> V_131 , V_132 , V_134 ) ;
return F_99 ( F_100 ( V_7 ) , 500 ) ;
}
static int F_102 ( struct V_44 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
int V_30 ;
F_98 ( V_7 -> V_131 , V_132 ,
V_135 | V_134 ) ;
V_30 = F_99 ( F_100 ( V_7 ) , 500 ) ;
if ( V_30 )
return V_30 ;
F_103 ( V_136 , F_84 ( V_136 ) | V_137 ) ;
F_104 ( V_136 ) ;
F_98 ( V_7 -> V_131 , V_132 ,
V_138 | V_134 ) ;
V_30 = F_99 ( F_100 ( V_7 ) , 500 ) ;
if ( V_30 )
return V_30 ;
F_103 ( V_136 , F_84 ( V_136 ) & ~ V_137 ) ;
F_104 ( V_136 ) ;
F_98 ( V_7 -> V_131 , V_132 , 0 ) ;
return 0 ;
}
static int F_105 ( struct V_44 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
int V_30 ;
F_103 ( V_139 + V_140 ,
V_141 | V_142 ) ;
V_30 = F_99 ( ( F_84 ( V_139 + V_140 ) &
V_142 ) == 0 , 500 ) ;
if ( V_30 )
return V_30 ;
F_103 ( V_139 + V_140 ,
V_143 | V_142 ) ;
V_30 = F_99 ( ( F_84 ( V_139 + V_140 ) &
V_142 ) == 0 , 500 ) ;
if ( V_30 )
return V_30 ;
F_103 ( V_139 + V_140 , 0 ) ;
return 0 ;
}
static int F_106 ( struct V_44 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
int V_30 ;
F_8 ( V_6 , V_144 , V_145 ) ;
V_30 = F_99 ( ( F_13 ( V_6 , V_144 ) & V_145 ) == 0 , 500 ) ;
F_38 ( V_7 , true ) ;
return V_30 ;
}
int F_107 ( struct V_44 * V_7 )
{
if ( F_70 ( V_7 ) -> V_71 >= 6 )
return F_106 ( V_7 ) ;
else if ( F_108 ( V_7 ) )
return F_105 ( V_7 ) ;
else if ( F_109 ( V_7 ) )
return F_102 ( V_7 ) ;
else if ( F_110 ( V_7 ) )
return F_101 ( V_7 ) ;
else if ( F_70 ( V_7 ) -> V_71 >= 3 )
return F_97 ( V_7 ) ;
else
return - V_146 ;
}
void F_111 ( struct V_44 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_46 ;
if ( F_50 ( V_7 ) &&
( F_13 ( V_6 , V_55 ) & V_56 ) ) {
F_14 ( L_17 ) ;
F_8 ( V_6 , V_55 , V_56 ) ;
}
}
