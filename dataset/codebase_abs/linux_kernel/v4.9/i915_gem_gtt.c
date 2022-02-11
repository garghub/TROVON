static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
F_2 ( ! F_3 ( V_3 ) ) ;
return F_4 ( V_3 , struct V_1 , V_4 ) ;
}
int F_5 ( struct V_5 * V_6 ,
int V_7 )
{
bool V_8 ;
bool V_9 ;
bool V_10 ;
V_8 = F_6 ( V_6 ) >= 6 ;
V_9 = F_6 ( V_6 ) >= 7 ;
V_10 =
F_7 ( V_6 ) || F_6 ( V_6 ) >= 9 ;
if ( F_8 ( V_6 ) ) {
V_9 = false ;
V_10 = false ;
}
if ( ! V_8 )
return 0 ;
if ( V_7 == 0 && F_6 ( V_6 ) < 9 )
return 0 ;
if ( V_7 == 1 )
return 1 ;
if ( V_7 == 2 && V_9 )
return 2 ;
if ( V_7 == 3 && V_10 )
return 3 ;
#ifdef F_9
if ( F_10 ( V_6 ) && V_11 ) {
F_11 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_12 ( V_6 ) && V_6 -> V_12 . V_13 -> V_14 < 0xb ) {
F_13 ( L_2 ) ;
return 0 ;
}
if ( F_6 ( V_6 ) >= 8 && V_15 . V_16 && V_9 )
return V_10 ? 3 : 2 ;
else
return V_8 ? 1 : 0 ;
}
static int F_14 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
T_1 V_21 )
{
T_1 V_22 = 0 ;
V_18 -> V_23 = V_18 -> V_24 -> V_23 ;
if ( V_18 -> V_24 -> V_25 )
V_22 |= V_26 ;
V_18 -> V_3 -> V_27 ( V_18 -> V_3 , V_18 -> V_23 , V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
return 0 ;
}
static void F_15 ( struct V_17 * V_18 )
{
V_18 -> V_3 -> V_30 ( V_18 -> V_3 ,
V_18 -> V_28 . V_29 ,
V_18 -> V_31 ,
true ) ;
}
static T_2 F_16 ( T_3 V_32 ,
enum V_19 V_33 ,
bool V_34 )
{
T_2 V_35 = V_34 ? V_36 | V_37 : 0 ;
V_35 |= V_32 ;
switch ( V_33 ) {
case V_38 :
V_35 |= V_39 ;
break;
case V_40 :
V_35 |= V_41 ;
break;
default:
V_35 |= V_42 ;
break;
}
return V_35 ;
}
static T_4 F_17 ( const T_3 V_32 ,
const enum V_19 V_33 )
{
T_4 V_43 = V_36 | V_37 ;
V_43 |= V_32 ;
if ( V_33 != V_38 )
V_43 |= V_44 ;
else
V_43 |= V_39 ;
return V_43 ;
}
static T_5 F_18 ( T_3 V_32 ,
enum V_19 V_33 ,
bool V_34 , T_1 V_21 )
{
T_5 V_35 = V_34 ? V_45 : 0 ;
V_35 |= F_19 ( V_32 ) ;
switch ( V_33 ) {
case V_46 :
case V_47 :
V_35 |= V_48 ;
break;
case V_38 :
V_35 |= V_49 ;
break;
default:
F_20 ( V_33 ) ;
}
return V_35 ;
}
static T_5 F_21 ( T_3 V_32 ,
enum V_19 V_33 ,
bool V_34 , T_1 V_21 )
{
T_5 V_35 = V_34 ? V_45 : 0 ;
V_35 |= F_19 ( V_32 ) ;
switch ( V_33 ) {
case V_46 :
V_35 |= V_50 ;
break;
case V_47 :
V_35 |= V_48 ;
break;
case V_38 :
V_35 |= V_49 ;
break;
default:
F_20 ( V_33 ) ;
}
return V_35 ;
}
static T_5 F_22 ( T_3 V_32 ,
enum V_19 V_33 ,
bool V_34 , T_1 V_51 )
{
T_5 V_35 = V_34 ? V_45 : 0 ;
V_35 |= F_19 ( V_32 ) ;
if ( ! ( V_51 & V_26 ) )
V_35 |= V_52 ;
if ( V_33 != V_38 )
V_35 |= V_53 ;
return V_35 ;
}
static T_5 F_23 ( T_3 V_32 ,
enum V_19 V_33 ,
bool V_34 , T_1 V_21 )
{
T_5 V_35 = V_34 ? V_45 : 0 ;
V_35 |= F_24 ( V_32 ) ;
if ( V_33 != V_38 )
V_35 |= V_54 ;
return V_35 ;
}
static T_5 F_25 ( T_3 V_32 ,
enum V_19 V_33 ,
bool V_34 , T_1 V_21 )
{
T_5 V_35 = V_34 ? V_45 : 0 ;
V_35 |= F_24 ( V_32 ) ;
switch ( V_33 ) {
case V_38 :
break;
case V_40 :
V_35 |= V_55 ;
break;
default:
V_35 |= V_56 ;
break;
}
return V_35 ;
}
static int F_26 ( struct V_57 * V_58 ,
struct V_59 * V_60 , T_6 V_51 )
{
struct V_61 * V_62 = & V_58 -> V_13 -> V_58 ;
V_60 -> V_63 = F_27 ( V_51 ) ;
if ( ! V_60 -> V_63 )
return - V_64 ;
V_60 -> V_65 = F_28 ( V_62 ,
V_60 -> V_63 , 0 , 4096 , V_66 ) ;
if ( F_29 ( V_62 , V_60 -> V_65 ) ) {
F_30 ( V_60 -> V_63 ) ;
return - V_67 ;
}
return 0 ;
}
static int F_31 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
return F_26 ( V_58 , V_60 , V_68 ) ;
}
static void F_32 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
struct V_69 * V_13 = V_58 -> V_13 ;
if ( F_33 ( ! V_60 -> V_63 ) )
return;
F_34 ( & V_13 -> V_58 , V_60 -> V_65 , 4096 , V_66 ) ;
F_30 ( V_60 -> V_63 ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
}
static void * F_35 ( struct V_59 * V_60 )
{
return F_36 ( V_60 -> V_63 ) ;
}
static void F_37 ( struct V_57 * V_58 , void * V_70 )
{
if ( F_38 ( V_58 ) || F_39 ( V_58 ) )
F_40 ( V_70 , V_71 ) ;
F_41 ( V_70 ) ;
}
static void F_42 ( struct V_57 * V_58 , struct V_59 * V_60 ,
const T_7 V_72 )
{
int V_73 ;
T_7 * const V_70 = F_35 ( V_60 ) ;
for ( V_73 = 0 ; V_73 < 512 ; V_73 ++ )
V_70 [ V_73 ] = V_72 ;
F_37 ( V_58 , V_70 ) ;
}
static void F_43 ( struct V_57 * V_58 , struct V_59 * V_60 ,
const T_8 V_74 )
{
T_7 V_75 = V_74 ;
V_75 = V_75 << 32 | V_74 ;
F_42 ( V_58 , V_60 , V_75 ) ;
}
static int
F_44 ( struct V_57 * V_58 ,
struct V_59 * V_76 ,
T_6 V_77 )
{
return F_26 ( V_58 , V_76 , V_77 | V_78 ) ;
}
static void F_45 ( struct V_57 * V_58 ,
struct V_59 * V_76 )
{
F_32 ( V_58 , V_76 ) ;
}
static struct V_79 * F_46 ( struct V_57 * V_58 )
{
struct V_79 * V_80 ;
const T_9 V_81 = F_47 ( V_58 ) -> V_82 >= 8 ?
V_83 : V_84 ;
int V_85 = - V_64 ;
V_80 = F_48 ( sizeof( * V_80 ) , V_86 ) ;
if ( ! V_80 )
return F_49 ( - V_64 ) ;
V_80 -> V_87 = F_50 ( F_51 ( V_81 ) , sizeof( * V_80 -> V_87 ) ,
V_86 ) ;
if ( ! V_80 -> V_87 )
goto V_88;
V_85 = F_52 ( V_58 , V_80 ) ;
if ( V_85 )
goto V_89;
return V_80 ;
V_89:
F_53 ( V_80 -> V_87 ) ;
V_88:
F_53 ( V_80 ) ;
return F_49 ( V_85 ) ;
}
static void F_54 ( struct V_57 * V_58 , struct V_79 * V_80 )
{
F_55 ( V_58 , V_80 ) ;
F_53 ( V_80 -> V_87 ) ;
F_53 ( V_80 ) ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
T_2 V_90 ;
V_90 = F_16 ( V_3 -> V_91 . V_65 ,
V_47 , true ) ;
F_57 ( V_3 -> V_58 , V_80 , V_90 ) ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
T_5 V_90 ;
F_33 ( V_3 -> V_91 . V_65 == 0 ) ;
V_90 = V_3 -> V_92 ( V_3 -> V_91 . V_65 ,
V_47 , true , 0 ) ;
F_59 ( V_3 -> V_58 , V_80 , V_90 ) ;
}
static struct V_93 * F_60 ( struct V_57 * V_58 )
{
struct V_93 * V_94 ;
int V_85 = - V_64 ;
V_94 = F_48 ( sizeof( * V_94 ) , V_86 ) ;
if ( ! V_94 )
return F_49 ( - V_64 ) ;
V_94 -> V_95 = F_50 ( F_51 ( V_96 ) ,
sizeof( * V_94 -> V_95 ) , V_86 ) ;
if ( ! V_94 -> V_95 )
goto V_88;
V_85 = F_52 ( V_58 , V_94 ) ;
if ( V_85 )
goto V_89;
return V_94 ;
V_89:
F_53 ( V_94 -> V_95 ) ;
V_88:
F_53 ( V_94 ) ;
return F_49 ( V_85 ) ;
}
static void F_61 ( struct V_57 * V_58 , struct V_93 * V_94 )
{
if ( F_62 ( V_94 ) ) {
F_55 ( V_58 , V_94 ) ;
F_53 ( V_94 -> V_95 ) ;
F_53 ( V_94 ) ;
}
}
static void F_63 ( struct V_2 * V_3 ,
struct V_93 * V_94 )
{
T_4 V_97 ;
V_97 = F_17 ( F_64 ( V_3 -> V_98 ) , V_47 ) ;
F_57 ( V_3 -> V_58 , V_94 , V_97 ) ;
}
static int F_65 ( struct V_57 * V_58 ,
struct V_99 * V_100 )
{
T_9 V_101 = F_66 ( V_58 ) ;
V_100 -> V_102 = F_50 ( F_51 ( V_101 ) ,
sizeof( unsigned long ) ,
V_86 ) ;
if ( ! V_100 -> V_102 )
return - V_64 ;
V_100 -> V_103 = F_50 ( V_101 , sizeof( * V_100 -> V_103 ) ,
V_86 ) ;
if ( ! V_100 -> V_103 ) {
F_53 ( V_100 -> V_102 ) ;
V_100 -> V_102 = NULL ;
return - V_64 ;
}
return 0 ;
}
static void F_67 ( struct V_99 * V_100 )
{
F_53 ( V_100 -> V_102 ) ;
F_53 ( V_100 -> V_103 ) ;
V_100 -> V_103 = NULL ;
}
static struct
V_99 * F_68 ( struct V_57 * V_58 )
{
struct V_99 * V_100 ;
int V_85 = - V_64 ;
F_33 ( ! F_69 ( V_58 ) ) ;
V_100 = F_48 ( sizeof( * V_100 ) , V_86 ) ;
if ( ! V_100 )
return F_49 ( - V_64 ) ;
V_85 = F_65 ( V_58 , V_100 ) ;
if ( V_85 )
goto V_88;
V_85 = F_52 ( V_58 , V_100 ) ;
if ( V_85 )
goto V_89;
return V_100 ;
V_89:
F_67 ( V_100 ) ;
V_88:
F_53 ( V_100 ) ;
return F_49 ( V_85 ) ;
}
static void F_70 ( struct V_57 * V_58 ,
struct V_99 * V_100 )
{
F_67 ( V_100 ) ;
if ( F_69 ( V_58 ) ) {
F_55 ( V_58 , V_100 ) ;
F_53 ( V_100 ) ;
}
}
static void F_71 ( struct V_2 * V_3 ,
struct V_99 * V_100 )
{
T_10 V_104 ;
V_104 = F_72 ( F_64 ( V_3 -> V_105 ) , V_47 ) ;
F_57 ( V_3 -> V_58 , V_100 , V_104 ) ;
}
static void F_73 ( struct V_2 * V_3 ,
struct V_106 * V_107 )
{
T_11 V_108 ;
V_108 = F_74 ( F_64 ( V_3 -> V_109 ) ,
V_47 ) ;
F_57 ( V_3 -> V_58 , V_107 , V_108 ) ;
}
static void
F_75 ( struct V_110 * V_111 ,
struct V_99 * V_100 ,
struct V_93 * V_94 ,
int V_112 )
{
T_10 * V_113 ;
if ( ! F_69 ( V_111 -> V_4 . V_58 ) )
return;
V_113 = F_76 ( V_100 ) ;
V_113 [ V_112 ] = F_72 ( F_64 ( V_94 ) , V_47 ) ;
F_77 ( V_111 , V_113 ) ;
}
static void
F_78 ( struct V_110 * V_111 ,
struct V_106 * V_107 ,
struct V_99 * V_100 ,
int V_112 )
{
T_11 * V_114 = F_76 ( V_107 ) ;
F_33 ( ! F_69 ( V_111 -> V_4 . V_58 ) ) ;
V_114 [ V_112 ] = F_74 ( F_64 ( V_100 ) , V_47 ) ;
F_77 ( V_111 , V_114 ) ;
}
static int F_79 ( struct V_115 * V_116 ,
unsigned V_117 ,
T_3 V_32 )
{
struct V_118 * V_119 = V_116 -> V_119 ;
struct V_120 * V_121 = V_116 -> V_121 ;
int V_85 ;
F_80 ( V_117 >= 4 ) ;
V_85 = F_81 ( V_116 , 6 ) ;
if ( V_85 )
return V_85 ;
F_82 ( V_119 , F_83 ( 1 ) ) ;
F_84 ( V_119 , F_85 ( V_121 , V_117 ) ) ;
F_82 ( V_119 , F_86 ( V_32 ) ) ;
F_82 ( V_119 , F_83 ( 1 ) ) ;
F_84 ( V_119 , F_87 ( V_121 , V_117 ) ) ;
F_82 ( V_119 , F_88 ( V_32 ) ) ;
F_89 ( V_119 ) ;
return 0 ;
}
static int F_90 ( struct V_110 * V_111 ,
struct V_115 * V_116 )
{
int V_73 , V_85 ;
for ( V_73 = V_122 - 1 ; V_73 >= 0 ; V_73 -- ) {
const T_3 V_123 = F_91 ( V_111 , V_73 ) ;
V_85 = F_79 ( V_116 , V_73 , V_123 ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
static int F_92 ( struct V_110 * V_111 ,
struct V_115 * V_116 )
{
return F_79 ( V_116 , 0 , F_64 ( & V_111 -> V_107 ) ) ;
}
static void F_93 ( struct V_2 * V_3 ,
struct V_99 * V_100 ,
T_7 V_29 ,
T_7 V_124 ,
T_2 V_90 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
T_2 * V_125 ;
unsigned V_126 = F_95 ( V_29 ) ;
unsigned V_43 = F_96 ( V_29 ) ;
unsigned V_35 = F_97 ( V_29 ) ;
unsigned V_127 = V_124 >> V_128 ;
unsigned V_129 , V_73 ;
if ( F_33 ( ! V_100 ) )
return;
while ( V_127 ) {
struct V_93 * V_94 ;
struct V_79 * V_80 ;
if ( F_33 ( ! V_100 -> V_103 [ V_126 ] ) )
break;
V_94 = V_100 -> V_103 [ V_126 ] ;
if ( F_33 ( ! V_94 -> V_130 [ V_43 ] ) )
break;
V_80 = V_94 -> V_130 [ V_43 ] ;
if ( F_33 ( ! F_62 ( V_80 ) ) )
break;
V_129 = V_35 + V_127 ;
if ( V_129 > V_83 )
V_129 = V_83 ;
V_125 = F_76 ( V_80 ) ;
for ( V_73 = V_35 ; V_73 < V_129 ; V_73 ++ ) {
V_125 [ V_73 ] = V_90 ;
V_127 -- ;
}
F_77 ( V_111 , V_125 ) ;
V_35 = 0 ;
if ( ++ V_43 == V_96 ) {
if ( ++ V_126 == F_66 ( V_3 -> V_58 ) )
break;
V_43 = 0 ;
}
}
}
static void F_98 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_124 ,
bool V_131 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
T_2 V_90 = F_16 ( V_3 -> V_91 . V_65 ,
V_47 , V_131 ) ;
if ( ! F_69 ( V_3 -> V_58 ) ) {
F_93 ( V_3 , & V_111 -> V_100 , V_29 , V_124 ,
V_90 ) ;
} else {
T_7 V_132 ;
struct V_99 * V_100 ;
F_99 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_93 ( V_3 , V_100 , V_29 , V_124 ,
V_90 ) ;
}
}
}
static void
F_100 ( struct V_2 * V_3 ,
struct V_99 * V_100 ,
struct V_133 * V_134 ,
T_7 V_29 ,
enum V_19 V_20 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
T_2 * V_125 ;
unsigned V_126 = F_95 ( V_29 ) ;
unsigned V_43 = F_96 ( V_29 ) ;
unsigned V_35 = F_97 ( V_29 ) ;
V_125 = NULL ;
while ( F_101 ( V_134 ) ) {
if ( V_125 == NULL ) {
struct V_93 * V_94 = V_100 -> V_103 [ V_126 ] ;
struct V_79 * V_80 = V_94 -> V_130 [ V_43 ] ;
V_125 = F_76 ( V_80 ) ;
}
V_125 [ V_35 ] =
F_16 ( F_102 ( V_134 ) ,
V_20 , true ) ;
if ( ++ V_35 == V_83 ) {
F_77 ( V_111 , V_125 ) ;
V_125 = NULL ;
if ( ++ V_43 == V_96 ) {
if ( ++ V_126 == F_66 ( V_3 -> V_58 ) )
break;
V_43 = 0 ;
}
V_35 = 0 ;
}
}
if ( V_125 )
F_77 ( V_111 , V_125 ) ;
}
static void F_103 ( struct V_2 * V_3 ,
struct V_135 * V_23 ,
T_7 V_29 ,
enum V_19 V_20 ,
T_1 V_21 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
struct V_133 V_134 ;
F_104 ( & V_134 , V_23 -> V_136 , F_105 ( V_23 -> V_136 ) , 0 ) ;
if ( ! F_69 ( V_3 -> V_58 ) ) {
F_100 ( V_3 , & V_111 -> V_100 , & V_134 , V_29 ,
V_20 ) ;
} else {
struct V_99 * V_100 ;
T_7 V_132 ;
T_7 V_124 = ( T_7 ) V_23 -> V_137 << V_128 ;
F_99 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_100 ( V_3 , V_100 , & V_134 ,
V_29 , V_20 ) ;
}
}
}
static void F_106 ( struct V_57 * V_58 ,
struct V_93 * V_94 )
{
int V_73 ;
if ( ! F_62 ( V_94 ) )
return;
F_107 (i, pd->used_pdes, I915_PDES) {
if ( F_33 ( ! V_94 -> V_130 [ V_73 ] ) )
continue;
F_54 ( V_58 , V_94 -> V_130 [ V_73 ] ) ;
V_94 -> V_130 [ V_73 ] = NULL ;
}
}
static int F_108 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
int V_85 ;
V_85 = F_44 ( V_58 , & V_3 -> V_91 , V_68 ) ;
if ( V_85 )
return V_85 ;
V_3 -> V_98 = F_46 ( V_58 ) ;
if ( F_109 ( V_3 -> V_98 ) ) {
V_85 = F_110 ( V_3 -> V_98 ) ;
goto V_138;
}
V_3 -> V_105 = F_60 ( V_58 ) ;
if ( F_109 ( V_3 -> V_105 ) ) {
V_85 = F_110 ( V_3 -> V_105 ) ;
goto F_54;
}
if ( F_69 ( V_58 ) ) {
V_3 -> V_109 = F_68 ( V_58 ) ;
if ( F_109 ( V_3 -> V_109 ) ) {
V_85 = F_110 ( V_3 -> V_109 ) ;
goto F_61;
}
}
F_56 ( V_3 , V_3 -> V_98 ) ;
F_63 ( V_3 , V_3 -> V_105 ) ;
if ( F_69 ( V_58 ) )
F_71 ( V_3 , V_3 -> V_109 ) ;
return 0 ;
F_61:
F_61 ( V_58 , V_3 -> V_105 ) ;
F_54:
F_54 ( V_58 , V_3 -> V_98 ) ;
V_138:
F_45 ( V_58 , & V_3 -> V_91 ) ;
return V_85 ;
}
static int F_111 ( struct V_110 * V_111 , bool V_139 )
{
enum V_140 V_141 ;
struct V_5 * V_6 = F_112 ( V_111 -> V_4 . V_58 ) ;
int V_73 ;
if ( F_69 ( V_6 ) ) {
T_12 V_65 = F_64 ( & V_111 -> V_107 ) ;
F_113 ( F_114 ( V_100 [ 0 ] . V_142 ) , F_88 ( V_65 ) ) ;
F_113 ( F_114 ( V_100 [ 0 ] . V_143 ) , F_86 ( V_65 ) ) ;
V_141 = ( V_139 ? V_144 :
V_145 ) ;
} else {
for ( V_73 = 0 ; V_73 < V_122 ; V_73 ++ ) {
T_12 V_65 = F_91 ( V_111 , V_73 ) ;
F_113 ( F_114 ( V_100 [ V_73 ] . V_142 ) , F_88 ( V_65 ) ) ;
F_113 ( F_114 ( V_100 [ V_73 ] . V_143 ) , F_86 ( V_65 ) ) ;
}
V_141 = ( V_139 ? V_146 :
V_147 ) ;
}
F_113 ( F_114 ( V_148 ) , V_141 ) ;
return 0 ;
}
static void F_115 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
if ( F_69 ( V_58 ) )
F_70 ( V_58 , V_3 -> V_109 ) ;
F_61 ( V_58 , V_3 -> V_105 ) ;
F_54 ( V_58 , V_3 -> V_98 ) ;
F_45 ( V_58 , & V_3 -> V_91 ) ;
}
static void F_116 ( struct V_57 * V_58 ,
struct V_99 * V_100 )
{
int V_73 ;
F_107 (i, pdp->used_pdpes, I915_PDPES_PER_PDP(dev)) {
if ( F_33 ( ! V_100 -> V_103 [ V_73 ] ) )
continue;
F_106 ( V_58 , V_100 -> V_103 [ V_73 ] ) ;
F_61 ( V_58 , V_100 -> V_103 [ V_73 ] ) ;
}
F_70 ( V_58 , V_100 ) ;
}
static void F_117 ( struct V_110 * V_111 )
{
int V_73 ;
F_107 (i, ppgtt->pml4.used_pml4es, GEN8_PML4ES_PER_PML4) {
if ( F_33 ( ! V_111 -> V_107 . V_149 [ V_73 ] ) )
continue;
F_116 ( V_111 -> V_4 . V_58 , V_111 -> V_107 . V_149 [ V_73 ] ) ;
}
F_55 ( V_111 -> V_4 . V_58 , & V_111 -> V_107 ) ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
if ( F_8 ( F_112 ( V_3 -> V_58 ) ) )
F_111 ( V_111 , false ) ;
if ( ! F_69 ( V_111 -> V_4 . V_58 ) )
F_116 ( V_111 -> V_4 . V_58 , & V_111 -> V_100 ) ;
else
F_117 ( V_111 ) ;
F_115 ( V_3 ) ;
}
static int F_119 ( struct V_2 * V_3 ,
struct V_93 * V_94 ,
T_7 V_29 ,
T_7 V_124 ,
unsigned long * V_150 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_79 * V_80 ;
T_8 V_43 ;
F_120 (pt, pd, start, length, pde) {
if ( F_121 ( V_43 , V_94 -> V_95 ) ) {
F_33 ( V_80 == V_3 -> V_98 ) ;
continue;
}
V_80 = F_46 ( V_58 ) ;
if ( F_109 ( V_80 ) )
goto V_151;
F_56 ( V_3 , V_80 ) ;
V_94 -> V_130 [ V_43 ] = V_80 ;
F_122 ( V_43 , V_150 ) ;
F_123 ( V_3 , V_43 , V_29 , V_152 ) ;
}
return 0 ;
V_151:
F_107 (pde, new_pts, I915_PDES)
F_54 ( V_58 , V_94 -> V_130 [ V_43 ] ) ;
return - V_64 ;
}
static int
F_124 ( struct V_2 * V_3 ,
struct V_99 * V_100 ,
T_7 V_29 ,
T_7 V_124 ,
unsigned long * V_153 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_93 * V_94 ;
T_8 V_126 ;
T_8 V_101 = F_66 ( V_58 ) ;
F_33 ( ! F_125 ( V_153 , V_101 ) ) ;
F_126 (pd, pdp, start, length, pdpe) {
if ( F_121 ( V_126 , V_100 -> V_102 ) )
continue;
V_94 = F_60 ( V_58 ) ;
if ( F_109 ( V_94 ) )
goto V_151;
F_63 ( V_3 , V_94 ) ;
V_100 -> V_103 [ V_126 ] = V_94 ;
F_122 ( V_126 , V_153 ) ;
F_127 ( V_3 , V_126 , V_29 , V_154 ) ;
}
return 0 ;
V_151:
F_107 (pdpe, new_pds, pdpes)
F_61 ( V_58 , V_100 -> V_103 [ V_126 ] ) ;
return - V_64 ;
}
static int
F_128 ( struct V_2 * V_3 ,
struct V_106 * V_107 ,
T_7 V_29 ,
T_7 V_124 ,
unsigned long * V_155 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_99 * V_100 ;
T_8 V_132 ;
F_33 ( ! F_125 ( V_155 , V_156 ) ) ;
F_99 (pdp, pml4, start, length, pml4e) {
if ( ! F_121 ( V_132 , V_107 -> V_157 ) ) {
V_100 = F_68 ( V_58 ) ;
if ( F_109 ( V_100 ) )
goto V_151;
F_71 ( V_3 , V_100 ) ;
V_107 -> V_149 [ V_132 ] = V_100 ;
F_122 ( V_132 , V_155 ) ;
F_129 ( V_3 ,
V_132 ,
V_29 ,
V_158 ) ;
}
}
return 0 ;
V_151:
F_107 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_70 ( V_58 , V_107 -> V_149 [ V_132 ] ) ;
return - V_64 ;
}
static void
F_130 ( unsigned long * V_153 , unsigned long * V_150 )
{
F_53 ( V_150 ) ;
F_53 ( V_153 ) ;
}
static
int T_13 F_131 ( unsigned long * * V_153 ,
unsigned long * * V_150 ,
T_8 V_101 )
{
unsigned long * V_159 ;
unsigned long * V_160 ;
V_159 = F_50 ( F_51 ( V_101 ) , sizeof( unsigned long ) , V_161 ) ;
if ( ! V_159 )
return - V_64 ;
V_160 = F_50 ( V_101 , F_51 ( V_96 ) * sizeof( unsigned long ) ,
V_161 ) ;
if ( ! V_160 )
goto V_162;
* V_153 = V_159 ;
* V_150 = V_160 ;
return 0 ;
V_162:
F_130 ( V_159 , V_160 ) ;
return - V_64 ;
}
static void F_132 ( struct V_110 * V_111 )
{
V_111 -> V_163 = F_47 ( V_111 -> V_4 . V_58 ) -> V_164 ;
}
static int F_133 ( struct V_2 * V_3 ,
struct V_99 * V_100 ,
T_7 V_29 ,
T_7 V_124 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
unsigned long * V_165 , * V_166 ;
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_93 * V_94 ;
const T_7 V_167 = V_29 ;
const T_7 V_168 = V_124 ;
T_8 V_126 ;
T_8 V_101 = F_66 ( V_58 ) ;
int V_85 ;
if ( F_33 ( V_29 + V_124 < V_29 ) )
return - V_169 ;
if ( F_33 ( V_29 + V_124 > V_3 -> V_170 ) )
return - V_169 ;
V_85 = F_131 ( & V_165 , & V_166 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_124 ( V_3 , V_100 , V_29 , V_124 ,
V_165 ) ;
if ( V_85 ) {
F_130 ( V_165 , V_166 ) ;
return V_85 ;
}
F_126 (pd, pdp, start, length, pdpe) {
V_85 = F_119 ( V_3 , V_94 , V_29 , V_124 ,
V_166 + V_126 * F_51 ( V_96 ) ) ;
if ( V_85 )
goto V_162;
}
V_29 = V_167 ;
V_124 = V_168 ;
F_126 (pd, pdp, start, length, pdpe) {
T_4 * const V_103 = F_76 ( V_94 ) ;
struct V_79 * V_80 ;
T_7 V_171 = V_124 ;
T_7 V_172 = V_29 ;
T_8 V_43 ;
F_33 ( ! V_94 ) ;
F_120 (pt, pd, pd_start, pd_len, pde) {
F_33 ( ! V_80 ) ;
F_33 ( ! V_171 ) ;
F_33 ( ! F_134 ( V_172 , V_171 ) ) ;
F_135 ( V_80 -> V_87 ,
F_97 ( V_172 ) ,
F_134 ( V_172 , V_171 ) ) ;
F_122 ( V_43 , V_94 -> V_95 ) ;
V_103 [ V_43 ] = F_17 ( F_64 ( V_80 ) ,
V_47 ) ;
F_136 ( & V_111 -> V_4 , V_43 , V_80 ,
F_97 ( V_29 ) ,
F_134 ( V_29 , V_124 ) ,
V_83 ) ;
}
F_77 ( V_111 , V_103 ) ;
F_122 ( V_126 , V_100 -> V_102 ) ;
F_75 ( V_111 , V_100 , V_94 , V_126 ) ;
}
F_130 ( V_165 , V_166 ) ;
F_132 ( V_111 ) ;
return 0 ;
V_162:
while ( V_126 -- ) {
unsigned long V_173 ;
F_107 (temp, new_page_tables + pdpe *
BITS_TO_LONGS(I915_PDES), I915_PDES)
F_54 ( V_58 , V_100 -> V_103 [ V_126 ] -> V_130 [ V_173 ] ) ;
}
F_107 (pdpe, new_page_dirs, pdpes)
F_61 ( V_58 , V_100 -> V_103 [ V_126 ] ) ;
F_130 ( V_165 , V_166 ) ;
F_132 ( V_111 ) ;
return V_85 ;
}
static int F_137 ( struct V_2 * V_3 ,
struct V_106 * V_107 ,
T_7 V_29 ,
T_7 V_124 )
{
F_138 ( V_155 , V_156 ) ;
struct V_110 * V_111 = F_94 ( V_3 ) ;
struct V_99 * V_100 ;
T_7 V_132 ;
int V_85 = 0 ;
F_139 ( V_155 , V_156 ) ;
V_85 = F_128 ( V_3 , V_107 , V_29 , V_124 ,
V_155 ) ;
if ( V_85 )
return V_85 ;
F_140 ( F_141 ( V_155 , V_156 ) > 2 ,
L_3
L_4 ) ;
F_99 (pdp, pml4, start, length, pml4e) {
F_33 ( ! V_100 ) ;
V_85 = F_133 ( V_3 , V_100 , V_29 , V_124 ) ;
if ( V_85 )
goto V_162;
F_78 ( V_111 , V_107 , V_100 , V_132 ) ;
}
F_142 ( V_107 -> V_157 , V_155 , V_107 -> V_157 ,
V_156 ) ;
return 0 ;
V_162:
F_107 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_116 ( V_3 -> V_58 , V_107 -> V_149 [ V_132 ] ) ;
return V_85 ;
}
static int F_143 ( struct V_2 * V_3 ,
T_7 V_29 , T_7 V_124 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
if ( F_69 ( V_3 -> V_58 ) )
return F_137 ( V_3 , & V_111 -> V_107 , V_29 , V_124 ) ;
else
return F_133 ( V_3 , & V_111 -> V_100 , V_29 , V_124 ) ;
}
static void F_144 ( struct V_99 * V_100 ,
T_7 V_29 , T_7 V_124 ,
T_2 V_90 ,
struct V_174 * V_175 )
{
struct V_93 * V_94 ;
T_8 V_126 ;
F_126 (pd, pdp, start, length, pdpe) {
struct V_79 * V_80 ;
T_7 V_171 = V_124 ;
T_7 V_172 = V_29 ;
T_8 V_43 ;
if ( ! F_121 ( V_126 , V_100 -> V_102 ) )
continue;
F_145 ( V_175 , L_5 , V_126 ) ;
F_120 (pt, pd, pd_start, pd_len, pde) {
T_8 V_35 ;
T_2 * V_125 ;
if ( ! F_121 ( V_43 , V_94 -> V_95 ) )
continue;
V_125 = F_76 ( V_80 ) ;
for ( V_35 = 0 ; V_35 < V_83 ; V_35 += 4 ) {
T_7 V_176 =
( V_126 << V_154 ) |
( V_43 << V_152 ) |
( V_35 << V_177 ) ;
int V_73 ;
bool V_178 = false ;
for ( V_73 = 0 ; V_73 < 4 ; V_73 ++ )
if ( V_125 [ V_35 + V_73 ] != V_90 )
V_178 = true ;
if ( ! V_178 )
continue;
F_145 ( V_175 , L_6 , V_176 , V_126 , V_43 , V_35 ) ;
for ( V_73 = 0 ; V_73 < 4 ; V_73 ++ ) {
if ( V_125 [ V_35 + V_73 ] != V_90 )
F_145 ( V_175 , L_7 , V_125 [ V_35 + V_73 ] ) ;
else
F_146 ( V_175 , L_8 ) ;
}
F_146 ( V_175 , L_9 ) ;
}
F_41 ( V_125 ) ;
}
}
}
static void F_147 ( struct V_110 * V_111 , struct V_174 * V_175 )
{
struct V_2 * V_3 = & V_111 -> V_4 ;
T_7 V_29 = V_111 -> V_4 . V_29 ;
T_7 V_124 = V_111 -> V_4 . V_170 ;
T_2 V_90 = F_16 ( V_3 -> V_91 . V_65 ,
V_47 , true ) ;
if ( ! F_69 ( V_3 -> V_58 ) ) {
F_144 ( & V_111 -> V_100 , V_29 , V_124 , V_90 , V_175 ) ;
} else {
T_7 V_132 ;
struct V_106 * V_107 = & V_111 -> V_107 ;
struct V_99 * V_100 ;
F_99 (pdp, pml4, start, length, pml4e) {
if ( ! F_121 ( V_132 , V_107 -> V_157 ) )
continue;
F_145 ( V_175 , L_10 , V_132 ) ;
F_144 ( V_100 , V_29 , V_124 , V_90 , V_175 ) ;
}
}
}
static int F_148 ( struct V_110 * V_111 )
{
unsigned long * V_165 , * V_166 ;
T_8 V_101 = F_66 ( V_58 ) ;
int V_85 ;
V_85 = F_131 ( & V_165 , & V_166 , V_101 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_124 ( & V_111 -> V_4 , & V_111 -> V_100 ,
0 , 1ULL << 32 ,
V_165 ) ;
if ( ! V_85 )
* V_111 -> V_100 . V_102 = * V_165 ;
F_130 ( V_165 , V_166 ) ;
return V_85 ;
}
static int F_149 ( struct V_110 * V_111 )
{
int V_85 ;
V_85 = F_108 ( & V_111 -> V_4 ) ;
if ( V_85 )
return V_85 ;
V_111 -> V_4 . V_29 = 0 ;
V_111 -> V_4 . V_179 = F_118 ;
V_111 -> V_4 . V_180 = F_143 ;
V_111 -> V_4 . V_27 = F_103 ;
V_111 -> V_4 . V_30 = F_98 ;
V_111 -> V_4 . V_181 = F_15 ;
V_111 -> V_4 . V_182 = F_14 ;
V_111 -> V_183 = F_147 ;
if ( F_69 ( V_111 -> V_4 . V_58 ) ) {
V_85 = F_52 ( V_111 -> V_4 . V_58 , & V_111 -> V_107 ) ;
if ( V_85 )
goto V_184;
F_73 ( & V_111 -> V_4 , & V_111 -> V_107 ) ;
V_111 -> V_4 . V_170 = 1ULL << 48 ;
V_111 -> V_185 = F_92 ;
} else {
V_85 = F_65 ( V_111 -> V_4 . V_58 , & V_111 -> V_100 ) ;
if ( V_85 )
goto V_184;
V_111 -> V_4 . V_170 = 1ULL << 32 ;
V_111 -> V_185 = F_90 ;
F_129 ( & V_111 -> V_4 ,
0 , 0 ,
V_158 ) ;
if ( F_8 ( F_112 ( V_111 -> V_4 . V_58 ) ) ) {
V_85 = F_148 ( V_111 ) ;
if ( V_85 )
goto V_184;
}
}
if ( F_8 ( F_112 ( V_111 -> V_4 . V_58 ) ) )
F_111 ( V_111 , true ) ;
return 0 ;
V_184:
F_115 ( & V_111 -> V_4 ) ;
return V_85 ;
}
static void F_150 ( struct V_110 * V_111 , struct V_174 * V_175 )
{
struct V_2 * V_3 = & V_111 -> V_4 ;
struct V_79 * V_21 ;
T_5 V_90 ;
T_8 V_186 ;
T_8 V_35 , V_43 ;
T_8 V_29 = V_111 -> V_4 . V_29 , V_124 = V_111 -> V_4 . V_170 ;
V_90 = V_3 -> V_92 ( V_3 -> V_91 . V_65 ,
V_47 , true , 0 ) ;
F_151 (unused, &ppgtt->pd, start, length, pde) {
T_1 V_187 ;
T_5 * V_125 ;
const T_3 V_188 = F_64 ( V_111 -> V_94 . V_130 [ V_43 ] ) ;
V_186 = F_152 ( V_111 -> V_189 + V_43 ) ;
V_187 = ( F_153 ( V_188 ) | V_190 ) ;
if ( V_186 != V_187 )
F_145 ( V_175 , L_11 ,
V_43 ,
V_186 ,
V_187 ) ;
F_145 ( V_175 , L_12 , V_186 ) ;
V_125 = F_76 ( V_111 -> V_94 . V_130 [ V_43 ] ) ;
for ( V_35 = 0 ; V_35 < V_84 ; V_35 += 4 ) {
unsigned long V_176 =
( V_43 * V_71 * V_84 ) +
( V_35 * V_71 ) ;
int V_73 ;
bool V_178 = false ;
for ( V_73 = 0 ; V_73 < 4 ; V_73 ++ )
if ( V_125 [ V_35 + V_73 ] != V_90 )
V_178 = true ;
if ( ! V_178 )
continue;
F_145 ( V_175 , L_13 , V_176 , V_43 , V_35 ) ;
for ( V_73 = 0 ; V_73 < 4 ; V_73 ++ ) {
if ( V_125 [ V_35 + V_73 ] != V_90 )
F_145 ( V_175 , L_14 , V_125 [ V_35 + V_73 ] ) ;
else
F_146 ( V_175 , L_8 ) ;
}
F_146 ( V_175 , L_9 ) ;
}
F_77 ( V_111 , V_125 ) ;
}
}
static void F_154 ( struct V_93 * V_94 ,
const int V_43 , struct V_79 * V_80 )
{
struct V_110 * V_111 =
F_4 ( V_94 , struct V_110 , V_94 ) ;
T_1 V_186 ;
V_186 = F_153 ( F_64 ( V_80 ) ) ;
V_186 |= V_190 ;
F_155 ( V_186 , V_111 -> V_189 + V_43 ) ;
}
static void F_156 ( struct V_5 * V_6 ,
struct V_93 * V_94 ,
T_8 V_29 , T_8 V_124 )
{
struct V_1 * V_191 = & V_6 -> V_191 ;
struct V_79 * V_80 ;
T_8 V_43 ;
F_151 (pt, pd, start, length, pde)
F_154 ( V_94 , V_43 , V_80 ) ;
F_152 ( V_191 -> V_192 ) ;
}
static T_8 F_157 ( struct V_110 * V_111 )
{
F_80 ( V_111 -> V_94 . V_4 . V_193 & 0x3f ) ;
return ( V_111 -> V_94 . V_4 . V_193 / 64 ) << 16 ;
}
static int F_158 ( struct V_110 * V_111 ,
struct V_115 * V_116 )
{
struct V_118 * V_119 = V_116 -> V_119 ;
struct V_120 * V_121 = V_116 -> V_121 ;
int V_85 ;
V_85 = V_121 -> V_194 ( V_116 , V_195 | V_196 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_81 ( V_116 , 6 ) ;
if ( V_85 )
return V_85 ;
F_82 ( V_119 , F_83 ( 2 ) ) ;
F_84 ( V_119 , F_159 ( V_121 ) ) ;
F_82 ( V_119 , V_197 ) ;
F_84 ( V_119 , F_160 ( V_121 ) ) ;
F_82 ( V_119 , F_157 ( V_111 ) ) ;
F_82 ( V_119 , V_198 ) ;
F_89 ( V_119 ) ;
return 0 ;
}
static int F_161 ( struct V_110 * V_111 ,
struct V_115 * V_116 )
{
struct V_118 * V_119 = V_116 -> V_119 ;
struct V_120 * V_121 = V_116 -> V_121 ;
int V_85 ;
V_85 = V_121 -> V_194 ( V_116 , V_195 | V_196 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_81 ( V_116 , 6 ) ;
if ( V_85 )
return V_85 ;
F_82 ( V_119 , F_83 ( 2 ) ) ;
F_84 ( V_119 , F_159 ( V_121 ) ) ;
F_82 ( V_119 , V_197 ) ;
F_84 ( V_119 , F_160 ( V_121 ) ) ;
F_82 ( V_119 , F_157 ( V_111 ) ) ;
F_82 ( V_119 , V_198 ) ;
F_89 ( V_119 ) ;
if ( V_121 -> V_199 != V_200 ) {
V_85 = V_121 -> V_194 ( V_116 , V_195 | V_196 ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
static int F_162 ( struct V_110 * V_111 ,
struct V_115 * V_116 )
{
struct V_120 * V_121 = V_116 -> V_121 ;
struct V_5 * V_6 = V_116 -> V_15 ;
F_113 ( F_159 ( V_121 ) , V_197 ) ;
F_113 ( F_160 ( V_121 ) , F_157 ( V_111 ) ) ;
return 0 ;
}
static void F_163 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_112 ( V_58 ) ;
struct V_120 * V_121 ;
F_164 (engine, dev_priv) {
T_1 V_201 = F_69 ( V_58 ) ? V_202 : 0 ;
F_113 ( F_165 ( V_121 ) ,
F_166 ( V_203 | V_201 ) ) ;
}
}
static void F_167 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_112 ( V_58 ) ;
struct V_120 * V_121 ;
T_8 V_204 , V_205 ;
V_205 = F_168 ( V_206 ) ;
F_113 ( V_206 , V_205 | V_207 ) ;
V_204 = F_168 ( V_208 ) ;
if ( F_169 ( V_58 ) ) {
V_204 |= V_209 ;
} else {
V_204 |= V_210 ;
V_204 &= ~ V_211 ;
}
F_113 ( V_208 , V_204 ) ;
F_164 (engine, dev_priv) {
F_113 ( F_165 ( V_121 ) ,
F_166 ( V_203 ) ) ;
}
}
static void F_170 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_112 ( V_58 ) ;
T_8 V_204 , V_212 , V_205 ;
V_205 = F_168 ( V_206 ) ;
F_113 ( V_206 , V_205 | V_213 |
V_207 ) ;
V_212 = F_168 ( V_214 ) ;
F_113 ( V_214 , V_212 | V_215 ) ;
V_204 = F_168 ( V_208 ) ;
F_113 ( V_208 , V_204 | V_216 | V_217 ) ;
F_113 ( V_218 , F_166 ( V_203 ) ) ;
}
static void F_171 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_124 ,
bool V_131 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
T_5 * V_125 , V_90 ;
unsigned V_219 = V_29 >> V_128 ;
unsigned V_127 = V_124 >> V_128 ;
unsigned V_220 = V_219 / V_84 ;
unsigned V_221 = V_219 % V_84 ;
unsigned V_129 , V_73 ;
V_90 = V_3 -> V_92 ( V_3 -> V_91 . V_65 ,
V_47 , true , 0 ) ;
while ( V_127 ) {
V_129 = V_221 + V_127 ;
if ( V_129 > V_84 )
V_129 = V_84 ;
V_125 = F_76 ( V_111 -> V_94 . V_130 [ V_220 ] ) ;
for ( V_73 = V_221 ; V_73 < V_129 ; V_73 ++ )
V_125 [ V_73 ] = V_90 ;
F_77 ( V_111 , V_125 ) ;
V_127 -= V_129 - V_221 ;
V_221 = 0 ;
V_220 ++ ;
}
}
static void F_172 ( struct V_2 * V_3 ,
struct V_135 * V_23 ,
T_7 V_29 ,
enum V_19 V_20 , T_1 V_51 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
unsigned V_219 = V_29 >> V_128 ;
unsigned V_220 = V_219 / V_84 ;
unsigned V_222 = V_219 % V_84 ;
T_5 * V_125 = NULL ;
struct V_223 V_223 ;
T_3 V_32 ;
F_173 (addr, sgt_iter, pages) {
if ( V_125 == NULL )
V_125 = F_76 ( V_111 -> V_94 . V_130 [ V_220 ] ) ;
V_125 [ V_222 ] =
V_3 -> V_92 ( V_32 , V_20 , true , V_51 ) ;
if ( ++ V_222 == V_84 ) {
F_77 ( V_111 , V_125 ) ;
V_125 = NULL ;
V_220 ++ ;
V_222 = 0 ;
}
}
if ( V_125 )
F_77 ( V_111 , V_125 ) ;
}
static int F_174 ( struct V_2 * V_3 ,
T_7 V_224 , T_7 V_225 )
{
F_138 ( V_166 , V_96 ) ;
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_5 * V_6 = F_112 ( V_58 ) ;
struct V_1 * V_191 = & V_6 -> V_191 ;
struct V_110 * V_111 = F_94 ( V_3 ) ;
struct V_79 * V_80 ;
T_8 V_29 , V_124 , V_226 , V_227 ;
T_8 V_43 ;
int V_85 ;
if ( F_33 ( V_224 + V_225 > V_111 -> V_4 . V_170 ) )
return - V_169 ;
V_29 = V_226 = V_224 ;
V_124 = V_227 = V_225 ;
F_139 ( V_166 , V_96 ) ;
F_151 (pt, &ppgtt->pd, start, length, pde) {
if ( V_80 != V_3 -> V_98 ) {
F_33 ( F_125 ( V_80 -> V_87 , V_84 ) ) ;
continue;
}
F_33 ( ! F_125 ( V_80 -> V_87 , V_84 ) ) ;
V_80 = F_46 ( V_58 ) ;
if ( F_109 ( V_80 ) ) {
V_85 = F_110 ( V_80 ) ;
goto V_151;
}
F_58 ( V_3 , V_80 ) ;
V_111 -> V_94 . V_130 [ V_43 ] = V_80 ;
F_122 ( V_43 , V_166 ) ;
F_123 ( V_3 , V_43 , V_29 , V_228 ) ;
}
V_29 = V_226 ;
V_124 = V_227 ;
F_151 (pt, &ppgtt->pd, start, length, pde) {
F_138 ( V_229 , V_84 ) ;
F_139 ( V_229 , V_84 ) ;
F_135 ( V_229 , F_175 ( V_29 ) ,
F_176 ( V_29 , V_124 ) ) ;
if ( F_177 ( V_43 , V_166 ) )
F_154 ( & V_111 -> V_94 , V_43 , V_80 ) ;
F_136 ( V_3 , V_43 , V_80 ,
F_175 ( V_29 ) ,
F_176 ( V_29 , V_124 ) ,
V_84 ) ;
F_142 ( V_80 -> V_87 , V_229 , V_80 -> V_87 ,
V_84 ) ;
}
F_33 ( ! F_125 ( V_166 , V_96 ) ) ;
F_152 ( V_191 -> V_192 ) ;
F_132 ( V_111 ) ;
return 0 ;
V_151:
F_107 (pde, new_page_tables, I915_PDES) {
struct V_79 * V_80 = V_111 -> V_94 . V_130 [ V_43 ] ;
V_111 -> V_94 . V_130 [ V_43 ] = V_3 -> V_98 ;
F_54 ( V_3 -> V_58 , V_80 ) ;
}
F_132 ( V_111 ) ;
return V_85 ;
}
static int F_178 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
int V_85 ;
V_85 = F_44 ( V_58 , & V_3 -> V_91 , V_68 ) ;
if ( V_85 )
return V_85 ;
V_3 -> V_98 = F_46 ( V_58 ) ;
if ( F_109 ( V_3 -> V_98 ) ) {
F_45 ( V_58 , & V_3 -> V_91 ) ;
return F_110 ( V_3 -> V_98 ) ;
}
F_58 ( V_3 , V_3 -> V_98 ) ;
return 0 ;
}
static void F_179 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
F_54 ( V_58 , V_3 -> V_98 ) ;
F_45 ( V_58 , & V_3 -> V_91 ) ;
}
static void F_180 ( struct V_2 * V_3 )
{
struct V_110 * V_111 = F_94 ( V_3 ) ;
struct V_93 * V_94 = & V_111 -> V_94 ;
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_79 * V_80 ;
T_8 V_43 ;
F_181 ( & V_111 -> V_28 ) ;
F_182 (pt, pd, pde)
if ( V_80 != V_3 -> V_98 )
F_54 ( V_58 , V_80 ) ;
F_179 ( V_3 ) ;
}
static int F_183 ( struct V_110 * V_111 )
{
struct V_2 * V_3 = & V_111 -> V_4 ;
struct V_57 * V_58 = V_111 -> V_4 . V_58 ;
struct V_5 * V_6 = F_112 ( V_58 ) ;
struct V_1 * V_191 = & V_6 -> V_191 ;
bool V_230 = false ;
int V_85 ;
F_80 ( ! F_184 ( & V_191 -> V_4 . V_231 ) ) ;
V_85 = F_178 ( V_3 ) ;
if ( V_85 )
return V_85 ;
V_232:
V_85 = F_185 ( & V_191 -> V_4 . V_231 ,
& V_111 -> V_28 , V_233 ,
V_234 , 0 ,
0 , V_191 -> V_4 . V_170 ,
V_235 ) ;
if ( V_85 == - V_236 && ! V_230 ) {
V_85 = F_186 ( & V_191 -> V_4 ,
V_233 , V_234 ,
V_38 ,
0 , V_191 -> V_4 . V_170 ,
0 ) ;
if ( V_85 )
goto V_162;
V_230 = true ;
goto V_232;
}
if ( V_85 )
goto V_162;
if ( V_111 -> V_28 . V_29 < V_191 -> V_237 )
F_187 ( L_15 ) ;
return 0 ;
V_162:
F_179 ( V_3 ) ;
return V_85 ;
}
static int F_188 ( struct V_110 * V_111 )
{
return F_183 ( V_111 ) ;
}
static void F_189 ( struct V_110 * V_111 ,
T_7 V_29 , T_7 V_124 )
{
struct V_79 * V_21 ;
T_8 V_43 ;
F_151 (unused, &ppgtt->pd, start, length, pde)
V_111 -> V_94 . V_130 [ V_43 ] = V_111 -> V_4 . V_98 ;
}
static int F_190 ( struct V_110 * V_111 )
{
struct V_57 * V_58 = V_111 -> V_4 . V_58 ;
struct V_5 * V_6 = F_112 ( V_58 ) ;
struct V_1 * V_191 = & V_6 -> V_191 ;
int V_85 ;
V_111 -> V_4 . V_92 = V_191 -> V_4 . V_92 ;
if ( F_8 ( V_6 ) || F_10 ( V_58 ) )
V_111 -> V_185 = F_162 ;
else if ( F_169 ( V_58 ) )
V_111 -> V_185 = F_158 ;
else if ( F_191 ( V_58 ) )
V_111 -> V_185 = F_161 ;
else
F_192 () ;
V_85 = F_188 ( V_111 ) ;
if ( V_85 )
return V_85 ;
V_111 -> V_4 . V_180 = F_174 ;
V_111 -> V_4 . V_30 = F_171 ;
V_111 -> V_4 . V_27 = F_172 ;
V_111 -> V_4 . V_181 = F_15 ;
V_111 -> V_4 . V_182 = F_14 ;
V_111 -> V_4 . V_179 = F_180 ;
V_111 -> V_4 . V_29 = 0 ;
V_111 -> V_4 . V_170 = V_96 * V_84 * V_71 ;
V_111 -> V_183 = F_150 ;
V_111 -> V_94 . V_4 . V_193 =
V_111 -> V_28 . V_29 / V_71 * sizeof( T_5 ) ;
V_111 -> V_189 = ( T_5 V_238 * ) V_191 -> V_192 +
V_111 -> V_94 . V_4 . V_193 / sizeof( T_5 ) ;
F_189 ( V_111 , 0 , V_111 -> V_4 . V_170 ) ;
F_156 ( V_6 , & V_111 -> V_94 , 0 , V_111 -> V_4 . V_170 ) ;
F_13 ( L_16 ,
V_111 -> V_28 . V_31 >> 20 ,
V_111 -> V_28 . V_29 / V_71 ) ;
F_187 ( L_17 ,
V_111 -> V_94 . V_4 . V_193 << 10 ) ;
return 0 ;
}
static int F_193 ( struct V_110 * V_111 ,
struct V_5 * V_6 )
{
V_111 -> V_4 . V_58 = & V_6 -> V_12 ;
if ( F_47 ( V_6 ) -> V_82 < 8 )
return F_190 ( V_111 ) ;
else
return F_149 ( V_111 ) ;
}
static void F_194 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
F_195 ( & V_3 -> V_231 , V_3 -> V_29 , V_3 -> V_170 ) ;
F_196 ( & V_3 -> V_239 ) ;
F_196 ( & V_3 -> V_240 ) ;
F_196 ( & V_3 -> V_241 ) ;
F_197 ( & V_3 -> V_242 , & V_6 -> V_243 ) ;
}
static void F_198 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_112 ( V_58 ) ;
if ( F_7 ( V_58 ) )
F_113 ( V_244 , V_245 ) ;
else if ( F_38 ( V_58 ) )
F_113 ( V_244 , V_246 ) ;
else if ( F_199 ( V_58 ) )
F_113 ( V_244 , V_247 ) ;
else if ( F_39 ( V_58 ) )
F_113 ( V_244 , V_248 ) ;
}
static int F_200 ( struct V_110 * V_111 ,
struct V_5 * V_6 ,
struct V_249 * V_250 )
{
int V_85 ;
V_85 = F_193 ( V_111 , V_6 ) ;
if ( V_85 == 0 ) {
F_201 ( & V_111 -> V_251 ) ;
F_194 ( & V_111 -> V_4 , V_6 ) ;
V_111 -> V_4 . V_252 = V_250 ;
}
return V_85 ;
}
int F_202 ( struct V_57 * V_58 )
{
F_198 ( V_58 ) ;
if ( V_15 . V_16 )
return 0 ;
if ( ! F_203 ( V_58 ) )
return 0 ;
if ( F_10 ( V_58 ) )
F_170 ( V_58 ) ;
else if ( F_191 ( V_58 ) )
F_167 ( V_58 ) ;
else if ( F_47 ( V_58 ) -> V_82 >= 8 )
F_163 ( V_58 ) ;
else
F_20 ( F_47 ( V_58 ) -> V_82 ) ;
return 0 ;
}
struct V_110 *
F_204 ( struct V_5 * V_6 ,
struct V_249 * V_253 )
{
struct V_110 * V_111 ;
int V_85 ;
V_111 = F_48 ( sizeof( * V_111 ) , V_86 ) ;
if ( ! V_111 )
return F_49 ( - V_64 ) ;
V_85 = F_200 ( V_111 , V_6 , V_253 ) ;
if ( V_85 ) {
F_53 ( V_111 ) ;
return F_49 ( V_85 ) ;
}
F_205 ( & V_111 -> V_4 ) ;
return V_111 ;
}
void F_206 ( struct V_254 * V_254 )
{
struct V_110 * V_111 =
F_4 ( V_254 , struct V_110 , V_251 ) ;
F_207 ( & V_111 -> V_4 ) ;
F_33 ( ! F_208 ( & V_111 -> V_4 . V_239 ) ) ;
F_33 ( ! F_208 ( & V_111 -> V_4 . V_240 ) ) ;
F_33 ( ! F_208 ( & V_111 -> V_4 . V_241 ) ) ;
F_209 ( & V_111 -> V_4 . V_242 ) ;
F_210 ( & V_111 -> V_4 . V_231 ) ;
V_111 -> V_4 . V_179 ( & V_111 -> V_4 ) ;
F_53 ( V_111 ) ;
}
static bool F_211 ( struct V_5 * V_6 )
{
#ifdef F_9
if ( F_212 ( V_6 ) && F_213 ( V_6 ) && V_11 )
return true ;
#endif
return false ;
}
void F_214 ( struct V_5 * V_6 )
{
struct V_120 * V_121 ;
if ( F_47 ( V_6 ) -> V_82 < 6 )
return;
F_164 (engine, dev_priv) {
T_1 V_255 ;
V_255 = F_168 ( F_215 ( V_121 ) ) ;
if ( V_255 & V_256 ) {
F_13 ( L_18
L_19
L_20
L_21
L_22 ,
V_255 & V_257 ,
V_255 & V_258 ? L_23 : L_24 ,
F_216 ( V_255 ) ,
F_217 ( V_255 ) ) ;
F_113 ( F_215 ( V_121 ) ,
V_255 & ~ V_256 ) ;
}
}
F_218 ( F_215 ( & V_6 -> V_121 [ V_200 ] ) ) ;
}
static void F_219 ( struct V_5 * V_6 )
{
if ( F_47 ( V_6 ) -> V_82 < 6 ) {
F_220 () ;
} else {
F_113 ( V_259 , V_260 ) ;
F_218 ( V_259 ) ;
}
}
void F_221 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_112 ( V_58 ) ;
struct V_1 * V_191 = & V_6 -> V_191 ;
if ( F_47 ( V_58 ) -> V_82 < 6 )
return;
F_214 ( V_6 ) ;
V_191 -> V_4 . V_30 ( & V_191 -> V_4 , V_191 -> V_4 . V_29 , V_191 -> V_4 . V_170 ,
true ) ;
F_219 ( V_6 ) ;
}
int F_222 ( struct V_261 * V_24 )
{
if ( ! F_223 ( & V_24 -> V_4 . V_58 -> V_13 -> V_58 ,
V_24 -> V_23 -> V_136 , V_24 -> V_23 -> V_262 ,
V_66 ) )
return - V_236 ;
return 0 ;
}
static void F_224 ( void V_238 * V_32 , T_2 V_35 )
{
F_225 ( V_35 , V_32 ) ;
}
static void F_226 ( struct V_2 * V_3 ,
T_3 V_32 ,
T_7 V_263 ,
enum V_19 V_33 ,
T_1 V_21 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
T_2 V_238 * V_35 =
( T_2 V_238 * ) V_6 -> V_191 . V_192 +
( V_263 >> V_128 ) ;
int V_264 ;
V_264 = F_227 ( V_6 ) ;
F_224 ( V_35 , F_16 ( V_32 , V_33 , true ) ) ;
F_113 ( V_259 , V_260 ) ;
F_218 ( V_259 ) ;
F_228 ( V_6 , V_264 ) ;
}
static void F_229 ( struct V_2 * V_3 ,
struct V_135 * V_265 ,
T_7 V_29 ,
enum V_19 V_33 , T_1 V_21 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
struct V_1 * V_191 = F_1 ( V_3 ) ;
struct V_223 V_223 ;
T_2 V_238 * V_266 ;
T_2 V_267 ;
T_3 V_32 ;
int V_264 ;
int V_73 = 0 ;
V_264 = F_227 ( V_6 ) ;
V_266 = ( T_2 V_238 * ) V_191 -> V_192 + ( V_29 >> V_128 ) ;
F_173 (addr, sgt_iter, st) {
V_267 = F_16 ( V_32 , V_33 , true ) ;
F_224 ( & V_266 [ V_73 ++ ] , V_267 ) ;
}
if ( V_73 != 0 )
F_33 ( F_230 ( & V_266 [ V_73 - 1 ] ) != V_267 ) ;
F_113 ( V_259 , V_260 ) ;
F_218 ( V_259 ) ;
F_228 ( V_6 , V_264 ) ;
}
static int F_231 ( void * V_268 )
{
struct V_27 * V_269 = V_268 ;
F_229 ( V_269 -> V_3 , V_269 -> V_265 ,
V_269 -> V_29 , V_269 -> V_33 , V_269 -> V_51 ) ;
return 0 ;
}
static void F_232 ( struct V_2 * V_3 ,
struct V_135 * V_265 ,
T_7 V_29 ,
enum V_19 V_33 ,
T_1 V_51 )
{
struct V_27 V_269 = { V_3 , V_265 , V_29 , V_33 , V_51 } ;
F_233 ( F_231 , & V_269 , NULL ) ;
}
static void F_234 ( struct V_2 * V_3 ,
T_3 V_32 ,
T_7 V_263 ,
enum V_19 V_33 ,
T_1 V_51 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
T_5 V_238 * V_35 =
( T_5 V_238 * ) V_6 -> V_191 . V_192 +
( V_263 >> V_128 ) ;
int V_264 ;
V_264 = F_227 ( V_6 ) ;
F_235 ( V_3 -> V_92 ( V_32 , V_33 , true , V_51 ) , V_35 ) ;
F_113 ( V_259 , V_260 ) ;
F_218 ( V_259 ) ;
F_228 ( V_6 , V_264 ) ;
}
static void F_236 ( struct V_2 * V_3 ,
struct V_135 * V_265 ,
T_7 V_29 ,
enum V_19 V_33 , T_1 V_51 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
struct V_1 * V_191 = F_1 ( V_3 ) ;
struct V_223 V_223 ;
T_5 V_238 * V_266 ;
T_5 V_267 ;
T_3 V_32 ;
int V_264 ;
int V_73 = 0 ;
V_264 = F_227 ( V_6 ) ;
V_266 = ( T_5 V_238 * ) V_191 -> V_192 + ( V_29 >> V_128 ) ;
F_173 (addr, sgt_iter, st) {
V_267 = V_3 -> V_92 ( V_32 , V_33 , true , V_51 ) ;
F_235 ( V_267 , & V_266 [ V_73 ++ ] ) ;
}
if ( V_73 != 0 )
F_33 ( F_152 ( & V_266 [ V_73 - 1 ] ) != V_267 ) ;
F_113 ( V_259 , V_260 ) ;
F_218 ( V_259 ) ;
F_228 ( V_6 , V_264 ) ;
}
static void F_237 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_124 ,
bool V_131 )
{
}
static void F_238 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_124 ,
bool V_131 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
struct V_1 * V_191 = F_1 ( V_3 ) ;
unsigned V_219 = V_29 >> V_128 ;
unsigned V_127 = V_124 >> V_128 ;
T_2 V_90 , V_238 * V_270 =
( T_2 V_238 * ) V_191 -> V_192 + V_219 ;
const int V_271 = F_239 ( V_191 ) - V_219 ;
int V_73 ;
int V_264 ;
V_264 = F_227 ( V_6 ) ;
if ( F_140 ( V_127 > V_271 ,
L_25 ,
V_219 , V_127 , V_271 ) )
V_127 = V_271 ;
V_90 = F_16 ( V_3 -> V_91 . V_65 ,
V_47 ,
V_131 ) ;
for ( V_73 = 0 ; V_73 < V_127 ; V_73 ++ )
F_224 ( & V_270 [ V_73 ] , V_90 ) ;
F_152 ( V_270 ) ;
F_228 ( V_6 , V_264 ) ;
}
static void F_240 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_124 ,
bool V_131 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
struct V_1 * V_191 = F_1 ( V_3 ) ;
unsigned V_219 = V_29 >> V_128 ;
unsigned V_127 = V_124 >> V_128 ;
T_5 V_90 , V_238 * V_270 =
( T_5 V_238 * ) V_191 -> V_192 + V_219 ;
const int V_271 = F_239 ( V_191 ) - V_219 ;
int V_73 ;
int V_264 ;
V_264 = F_227 ( V_6 ) ;
if ( F_140 ( V_127 > V_271 ,
L_25 ,
V_219 , V_127 , V_271 ) )
V_127 = V_271 ;
V_90 = V_3 -> V_92 ( V_3 -> V_91 . V_65 ,
V_47 , V_131 , 0 ) ;
for ( V_73 = 0 ; V_73 < V_127 ; V_73 ++ )
F_235 ( V_90 , & V_270 [ V_73 ] ) ;
F_152 ( V_270 ) ;
F_228 ( V_6 , V_264 ) ;
}
static void F_241 ( struct V_2 * V_3 ,
T_3 V_32 ,
T_7 V_263 ,
enum V_19 V_20 ,
T_1 V_21 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
unsigned int V_51 = ( V_20 == V_38 ) ?
V_272 : V_273 ;
int V_264 ;
V_264 = F_227 ( V_6 ) ;
F_242 ( V_32 , V_263 >> V_128 , V_51 ) ;
F_228 ( V_6 , V_264 ) ;
}
static void F_243 ( struct V_2 * V_3 ,
struct V_135 * V_23 ,
T_7 V_29 ,
enum V_19 V_20 , T_1 V_21 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
unsigned int V_51 = ( V_20 == V_38 ) ?
V_272 : V_273 ;
int V_264 ;
V_264 = F_227 ( V_6 ) ;
F_244 ( V_23 , V_29 >> V_128 , V_51 ) ;
F_228 ( V_6 , V_264 ) ;
}
static void F_245 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_124 ,
bool V_21 )
{
struct V_5 * V_6 = F_112 ( V_3 -> V_58 ) ;
unsigned V_219 = V_29 >> V_128 ;
unsigned V_127 = V_124 >> V_128 ;
int V_264 ;
V_264 = F_227 ( V_6 ) ;
F_246 ( V_219 , V_127 ) ;
F_228 ( V_6 , V_264 ) ;
}
static int F_247 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
T_1 V_51 )
{
struct V_261 * V_24 = V_18 -> V_24 ;
T_1 V_22 = 0 ;
int V_85 ;
V_85 = F_248 ( V_18 ) ;
if ( V_85 )
return V_85 ;
if ( V_24 -> V_25 )
V_22 |= V_26 ;
V_18 -> V_3 -> V_27 ( V_18 -> V_3 , V_18 -> V_23 , V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
V_18 -> V_51 |= V_274 | V_275 ;
return 0 ;
}
static int F_249 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
T_1 V_51 )
{
T_1 V_22 ;
int V_85 ;
V_85 = F_248 ( V_18 ) ;
if ( V_85 )
return V_85 ;
V_22 = 0 ;
if ( V_18 -> V_24 -> V_25 )
V_22 |= V_26 ;
if ( V_51 & V_274 ) {
V_18 -> V_3 -> V_27 ( V_18 -> V_3 ,
V_18 -> V_23 , V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
}
if ( V_51 & V_275 ) {
struct V_110 * V_276 =
F_112 ( V_18 -> V_3 -> V_58 ) -> V_231 . V_277 ;
V_276 -> V_4 . V_27 ( & V_276 -> V_4 ,
V_18 -> V_23 , V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
}
return 0 ;
}
static void F_250 ( struct V_17 * V_18 )
{
struct V_110 * V_276 = F_112 ( V_18 -> V_3 -> V_58 ) -> V_231 . V_277 ;
const T_12 V_31 = F_251 ( V_18 -> V_31 , V_18 -> V_28 . V_31 ) ;
if ( V_18 -> V_51 & V_274 )
V_18 -> V_3 -> V_30 ( V_18 -> V_3 ,
V_18 -> V_28 . V_29 , V_31 ,
true ) ;
if ( V_18 -> V_51 & V_275 && V_276 )
V_276 -> V_4 . V_30 ( & V_276 -> V_4 ,
V_18 -> V_28 . V_29 , V_31 ,
true ) ;
}
void F_252 ( struct V_261 * V_24 )
{
struct V_5 * V_6 = F_112 ( V_24 -> V_4 . V_58 ) ;
struct V_61 * V_62 = & V_6 -> V_12 . V_13 -> V_58 ;
struct V_1 * V_191 = & V_6 -> V_191 ;
if ( F_253 ( V_191 -> V_278 ) ) {
if ( F_254 ( V_6 , V_279 ) ) {
F_255 ( L_26 ) ;
F_256 ( 10 ) ;
}
}
F_257 ( V_62 , V_24 -> V_23 -> V_136 , V_24 -> V_23 -> V_262 ,
V_66 ) ;
}
static void F_258 ( struct V_280 * V_28 ,
unsigned long V_281 ,
T_12 * V_29 ,
T_12 * V_282 )
{
if ( V_28 -> V_281 != V_281 )
* V_29 += 4096 ;
V_28 = F_259 ( & V_28 -> V_283 ,
struct V_280 ,
V_283 ) ;
if ( V_28 && V_28 -> V_284 && V_28 -> V_281 != V_281 )
* V_282 -= 4096 ;
}
int F_260 ( struct V_5 * V_6 )
{
struct V_1 * V_191 = & V_6 -> V_191 ;
unsigned long V_285 , V_286 ;
struct V_280 * V_117 ;
int V_85 ;
V_85 = F_261 ( V_6 ) ;
if ( V_85 )
return V_85 ;
F_262 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_263 ( L_27 ,
V_285 , V_286 ) ;
V_191 -> V_4 . V_30 ( & V_191 -> V_4 , V_285 ,
V_286 - V_285 , true ) ;
}
V_191 -> V_4 . V_30 ( & V_191 -> V_4 ,
V_191 -> V_4 . V_170 - V_71 , V_71 ,
true ) ;
if ( F_203 ( V_6 ) && ! F_264 ( V_6 ) ) {
struct V_110 * V_111 ;
V_111 = F_48 ( sizeof( * V_111 ) , V_86 ) ;
if ( ! V_111 )
return - V_64 ;
V_85 = F_193 ( V_111 , V_6 ) ;
if ( V_85 ) {
F_53 ( V_111 ) ;
return V_85 ;
}
if ( V_111 -> V_4 . V_180 )
V_85 = V_111 -> V_4 . V_180 ( & V_111 -> V_4 , 0 ,
V_111 -> V_4 . V_170 ) ;
if ( V_85 ) {
V_111 -> V_4 . V_179 ( & V_111 -> V_4 ) ;
F_53 ( V_111 ) ;
return V_85 ;
}
V_111 -> V_4 . V_30 ( & V_111 -> V_4 ,
V_111 -> V_4 . V_29 ,
V_111 -> V_4 . V_170 ,
true ) ;
V_6 -> V_231 . V_277 = V_111 ;
F_33 ( V_191 -> V_4 . V_182 != F_247 ) ;
V_191 -> V_4 . V_182 = F_249 ;
}
return 0 ;
}
void F_265 ( struct V_5 * V_6 )
{
struct V_1 * V_191 = & V_6 -> V_191 ;
if ( V_6 -> V_231 . V_277 ) {
struct V_110 * V_111 = V_6 -> V_231 . V_277 ;
V_111 -> V_4 . V_179 ( & V_111 -> V_4 ) ;
F_53 ( V_111 ) ;
}
F_266 ( & V_6 -> V_12 ) ;
if ( F_184 ( & V_191 -> V_4 . V_231 ) ) {
F_267 ( V_6 ) ;
F_210 ( & V_191 -> V_4 . V_231 ) ;
F_209 ( & V_191 -> V_4 . V_242 ) ;
}
V_191 -> V_4 . V_179 ( & V_191 -> V_4 ) ;
F_268 ( V_191 -> V_287 ) ;
F_269 ( & V_191 -> V_288 ) ;
}
static unsigned int F_270 ( T_14 V_289 )
{
V_289 >>= V_290 ;
V_289 &= V_291 ;
return V_289 << 20 ;
}
static unsigned int F_271 ( T_14 V_292 )
{
V_292 >>= V_293 ;
V_292 &= V_294 ;
if ( V_292 )
V_292 = 1 << V_292 ;
#ifdef F_272
if ( V_292 > 4 )
V_292 = 4 ;
#endif
return V_292 << 20 ;
}
static unsigned int F_273 ( T_14 V_295 )
{
V_295 >>= V_290 ;
V_295 &= V_291 ;
if ( V_295 )
return 1 << ( 20 + V_295 ) ;
return 0 ;
}
static T_9 F_274 ( T_14 V_289 )
{
V_289 >>= V_296 ;
V_289 &= V_297 ;
return V_289 << 25 ;
}
static T_9 F_275 ( T_14 V_292 )
{
V_292 >>= V_298 ;
V_292 &= V_299 ;
return V_292 << 25 ;
}
static T_9 F_276 ( T_14 V_295 )
{
V_295 >>= V_296 ;
V_295 &= V_297 ;
if ( V_295 < 0x11 )
return V_295 << 25 ;
else if ( V_295 < 0x17 )
return ( V_295 - 0x11 + 2 ) << 22 ;
else
return ( V_295 - 0x17 + 9 ) << 22 ;
}
static T_9 F_277 ( T_14 V_300 )
{
V_300 >>= V_298 ;
V_300 &= V_299 ;
if ( V_300 < 0xf0 )
return V_300 << 25 ;
else
return ( V_300 - 0xf0 + 1 ) << 22 ;
}
static int F_278 ( struct V_1 * V_191 , T_12 V_31 )
{
struct V_69 * V_13 = V_191 -> V_4 . V_58 -> V_13 ;
T_15 V_301 ;
int V_85 ;
V_301 = F_279 ( V_13 , 0 ) + F_280 ( V_13 , 0 ) / 2 ;
if ( F_39 ( V_191 -> V_4 . V_58 ) )
V_191 -> V_192 = F_281 ( V_301 , V_31 ) ;
else
V_191 -> V_192 = F_282 ( V_301 , V_31 ) ;
if ( ! V_191 -> V_192 ) {
F_255 ( L_28 ) ;
return - V_64 ;
}
V_85 = F_44 ( V_191 -> V_4 . V_58 ,
& V_191 -> V_4 . V_91 ,
V_302 ) ;
if ( V_85 ) {
F_255 ( L_29 ) ;
F_283 ( V_191 -> V_192 ) ;
return V_85 ;
}
return 0 ;
}
static void F_284 ( struct V_5 * V_6 )
{
T_7 V_303 ;
V_303 = F_285 ( 0 , V_304 | V_305 ) |
F_285 ( 1 , V_306 | V_307 ) |
F_285 ( 2 , V_308 | V_307 ) |
F_285 ( 3 , V_309 ) |
F_285 ( 4 , V_304 | V_307 | F_286 ( 0 ) ) |
F_285 ( 5 , V_304 | V_307 | F_286 ( 1 ) ) |
F_285 ( 6 , V_304 | V_307 | F_286 ( 2 ) ) |
F_285 ( 7 , V_304 | V_307 | F_286 ( 3 ) ) ;
if ( ! F_203 ( V_6 ) )
V_303 = F_285 ( 0 , V_309 ) ;
F_113 ( V_310 , V_303 ) ;
F_113 ( V_311 , V_303 >> 32 ) ;
}
static void F_287 ( struct V_5 * V_6 )
{
T_7 V_303 ;
V_303 = F_285 ( 0 , V_312 ) |
F_285 ( 1 , 0 ) |
F_285 ( 2 , 0 ) |
F_285 ( 3 , 0 ) |
F_285 ( 4 , V_312 ) |
F_285 ( 5 , V_312 ) |
F_285 ( 6 , V_312 ) |
F_285 ( 7 , V_312 ) ;
F_113 ( V_310 , V_303 ) ;
F_113 ( V_311 , V_303 >> 32 ) ;
}
static void F_288 ( struct V_2 * V_3 )
{
struct V_1 * V_191 = F_1 ( V_3 ) ;
F_283 ( V_191 -> V_192 ) ;
F_45 ( V_3 -> V_58 , & V_3 -> V_91 ) ;
}
static int F_289 ( struct V_1 * V_191 )
{
struct V_5 * V_6 = F_112 ( V_191 -> V_4 . V_58 ) ;
struct V_69 * V_13 = V_6 -> V_12 . V_13 ;
unsigned int V_31 ;
T_14 V_289 ;
V_191 -> V_313 = F_279 ( V_13 , 2 ) ;
V_191 -> V_237 = F_280 ( V_13 , 2 ) ;
if ( ! F_290 ( V_13 , F_291 ( 39 ) ) )
F_292 ( V_13 , F_291 ( 39 ) ) ;
F_293 ( V_13 , V_314 , & V_289 ) ;
if ( F_6 ( V_6 ) >= 9 ) {
V_191 -> V_315 = F_277 ( V_289 ) ;
V_31 = F_271 ( V_289 ) ;
} else if ( F_38 ( V_6 ) ) {
V_191 -> V_315 = F_276 ( V_289 ) ;
V_31 = F_273 ( V_289 ) ;
} else {
V_191 -> V_315 = F_275 ( V_289 ) ;
V_31 = F_271 ( V_289 ) ;
}
V_191 -> V_4 . V_170 = ( V_31 / sizeof( T_2 ) ) << V_128 ;
if ( F_38 ( V_6 ) || F_39 ( V_6 ) )
F_287 ( V_6 ) ;
else
F_284 ( V_6 ) ;
V_191 -> V_4 . V_179 = F_288 ;
V_191 -> V_4 . V_182 = F_247 ;
V_191 -> V_4 . V_181 = F_250 ;
V_191 -> V_4 . V_316 = F_226 ;
V_191 -> V_4 . V_30 = F_237 ;
if ( ! F_264 ( V_6 ) || F_294 ( V_6 ) )
V_191 -> V_4 . V_30 = F_238 ;
V_191 -> V_4 . V_27 = F_229 ;
if ( F_38 ( V_6 ) )
V_191 -> V_4 . V_27 = F_232 ;
return F_278 ( V_191 , V_31 ) ;
}
static int F_295 ( struct V_1 * V_191 )
{
struct V_5 * V_6 = F_112 ( V_191 -> V_4 . V_58 ) ;
struct V_69 * V_13 = V_6 -> V_12 . V_13 ;
unsigned int V_31 ;
T_14 V_289 ;
V_191 -> V_313 = F_279 ( V_13 , 2 ) ;
V_191 -> V_237 = F_280 ( V_13 , 2 ) ;
if ( V_191 -> V_237 < ( 64 << 20 ) || V_191 -> V_237 > ( 512 << 20 ) ) {
F_255 ( L_30 , V_191 -> V_237 ) ;
return - V_317 ;
}
if ( ! F_290 ( V_13 , F_291 ( 40 ) ) )
F_292 ( V_13 , F_291 ( 40 ) ) ;
F_293 ( V_13 , V_314 , & V_289 ) ;
V_191 -> V_315 = F_274 ( V_289 ) ;
V_31 = F_270 ( V_289 ) ;
V_191 -> V_4 . V_170 = ( V_31 / sizeof( T_5 ) ) << V_128 ;
V_191 -> V_4 . V_30 = F_240 ;
V_191 -> V_4 . V_316 = F_234 ;
V_191 -> V_4 . V_27 = F_236 ;
V_191 -> V_4 . V_182 = F_247 ;
V_191 -> V_4 . V_181 = F_250 ;
V_191 -> V_4 . V_179 = F_288 ;
if ( F_296 ( V_6 ) )
V_191 -> V_4 . V_92 = F_25 ;
else if ( F_169 ( V_6 ) )
V_191 -> V_4 . V_92 = F_23 ;
else if ( F_12 ( V_6 ) )
V_191 -> V_4 . V_92 = F_22 ;
else if ( F_6 ( V_6 ) >= 7 )
V_191 -> V_4 . V_92 = F_21 ;
else
V_191 -> V_4 . V_92 = F_18 ;
return F_278 ( V_191 , V_31 ) ;
}
static void F_297 ( struct V_2 * V_3 )
{
F_298 () ;
}
static int F_299 ( struct V_1 * V_191 )
{
struct V_5 * V_6 = F_112 ( V_191 -> V_4 . V_58 ) ;
int V_85 ;
V_85 = F_300 ( V_6 -> V_318 , V_6 -> V_12 . V_13 , NULL ) ;
if ( ! V_85 ) {
F_255 ( L_31 ) ;
return - V_319 ;
}
F_301 ( & V_191 -> V_4 . V_170 , & V_191 -> V_315 ,
& V_191 -> V_313 , & V_191 -> V_237 ) ;
V_191 -> V_278 = F_211 ( V_6 ) ;
V_191 -> V_4 . V_316 = F_241 ;
V_191 -> V_4 . V_27 = F_243 ;
V_191 -> V_4 . V_30 = F_245 ;
V_191 -> V_4 . V_182 = F_247 ;
V_191 -> V_4 . V_181 = F_250 ;
V_191 -> V_4 . V_179 = F_297 ;
if ( F_253 ( V_191 -> V_278 ) )
F_11 ( L_32 ) ;
return 0 ;
}
int F_302 ( struct V_5 * V_6 )
{
struct V_1 * V_191 = & V_6 -> V_191 ;
int V_85 ;
V_191 -> V_4 . V_58 = & V_6 -> V_12 ;
if ( F_6 ( V_6 ) <= 5 )
V_85 = F_299 ( V_191 ) ;
else if ( F_6 ( V_6 ) < 8 )
V_85 = F_295 ( V_191 ) ;
else
V_85 = F_289 ( V_191 ) ;
if ( V_85 )
return V_85 ;
if ( ( V_191 -> V_4 . V_170 - 1 ) >> 32 ) {
F_255 ( L_33
L_34 ,
V_191 -> V_4 . V_170 >> 20 ) ;
V_191 -> V_4 . V_170 = 1ULL << 32 ;
V_191 -> V_237 = F_251 ( V_191 -> V_237 , V_191 -> V_4 . V_170 ) ;
}
if ( V_191 -> V_237 > V_191 -> V_4 . V_170 ) {
F_255 ( L_35
L_36 ,
V_191 -> V_237 , V_191 -> V_4 . V_170 ) ;
V_191 -> V_237 = V_191 -> V_4 . V_170 ;
}
F_11 ( L_37 ,
V_191 -> V_4 . V_170 >> 20 ) ;
F_13 ( L_38 , V_191 -> V_237 >> 20 ) ;
F_13 ( L_39 , V_191 -> V_315 >> 20 ) ;
#ifdef F_9
if ( V_11 )
F_11 ( L_40 ) ;
#endif
return 0 ;
}
int F_303 ( struct V_5 * V_6 )
{
struct V_1 * V_191 = & V_6 -> V_191 ;
int V_85 ;
F_196 ( & V_6 -> V_243 ) ;
V_191 -> V_4 . V_170 -= V_71 ;
F_194 ( & V_191 -> V_4 , V_6 ) ;
V_191 -> V_4 . V_170 += V_71 ;
if ( ! F_304 ( V_6 ) )
V_191 -> V_4 . V_231 . V_320 = F_258 ;
if ( ! F_305 ( & V_6 -> V_191 . V_288 ,
V_6 -> V_191 . V_313 ,
V_6 -> V_191 . V_237 ) ) {
V_85 = - V_319 ;
goto V_321;
}
V_191 -> V_287 = F_306 ( V_191 -> V_313 , V_191 -> V_237 ) ;
V_85 = F_307 ( & V_6 -> V_12 ) ;
if ( V_85 )
goto V_321;
return 0 ;
V_321:
V_191 -> V_4 . V_179 ( & V_191 -> V_4 ) ;
return V_85 ;
}
int F_308 ( struct V_5 * V_6 )
{
if ( F_6 ( V_6 ) < 6 && ! F_309 () )
return - V_319 ;
return 0 ;
}
void F_310 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_112 ( V_58 ) ;
struct V_1 * V_191 = & V_6 -> V_191 ;
struct V_261 * V_24 , * V_322 ;
F_214 ( V_6 ) ;
V_191 -> V_4 . V_30 ( & V_191 -> V_4 , V_191 -> V_4 . V_29 , V_191 -> V_4 . V_170 ,
true ) ;
V_191 -> V_4 . V_323 = true ;
F_311 (obj, on,
&dev_priv->mm.bound_list, global_list) {
bool V_324 = false ;
struct V_17 * V_18 ;
F_312 (vma, &obj->vma_list, obj_link) {
if ( V_18 -> V_3 != & V_191 -> V_4 )
continue;
if ( ! F_313 ( V_18 ) )
continue;
F_33 ( F_314 ( V_18 , V_24 -> V_20 ,
V_325 ) ) ;
V_324 = true ;
}
if ( V_324 )
F_33 ( F_315 ( V_24 , false ) ) ;
}
V_191 -> V_4 . V_323 = false ;
if ( F_47 ( V_58 ) -> V_82 >= 8 ) {
if ( F_38 ( V_58 ) || F_39 ( V_58 ) )
F_287 ( V_6 ) ;
else
F_284 ( V_6 ) ;
return;
}
if ( F_203 ( V_58 ) ) {
struct V_2 * V_3 ;
F_312 (vm, &dev_priv->vm_list, global_link) {
struct V_110 * V_111 ;
if ( F_3 ( V_3 ) )
V_111 = V_6 -> V_231 . V_277 ;
else
V_111 = F_94 ( V_3 ) ;
F_156 ( V_6 , & V_111 -> V_94 ,
0 , V_111 -> V_4 . V_170 ) ;
}
}
F_219 ( V_6 ) ;
}
static void
F_316 ( struct V_326 * V_327 ,
struct V_115 * V_328 )
{
const unsigned int V_329 = V_328 -> V_121 -> V_199 ;
struct V_17 * V_18 =
F_4 ( V_327 , struct V_17 , V_330 [ V_329 ] ) ;
F_2 ( ! F_317 ( V_18 , V_329 ) ) ;
F_318 ( V_18 , V_329 ) ;
if ( F_319 ( V_18 ) )
return;
F_320 ( & V_18 -> V_331 , & V_18 -> V_3 -> V_240 ) ;
if ( F_253 ( F_321 ( V_18 ) && ! F_322 ( V_18 ) ) )
F_33 ( F_313 ( V_18 ) ) ;
}
void F_323 ( struct V_17 * V_18 )
{
F_2 ( V_18 -> V_28 . V_284 ) ;
F_2 ( F_319 ( V_18 ) ) ;
F_2 ( ! F_321 ( V_18 ) ) ;
F_2 ( V_18 -> V_332 ) ;
F_209 ( & V_18 -> V_331 ) ;
if ( ! F_324 ( V_18 ) )
F_325 ( F_94 ( V_18 -> V_3 ) ) ;
F_326 ( F_112 ( V_18 -> V_24 -> V_4 . V_58 ) -> V_333 , V_18 ) ;
}
void F_327 ( struct V_17 * V_18 )
{
F_2 ( F_321 ( V_18 ) ) ;
V_18 -> V_51 |= V_334 ;
F_328 ( & V_18 -> V_335 ) ;
if ( ! F_319 ( V_18 ) && ! F_322 ( V_18 ) )
F_33 ( F_313 ( V_18 ) ) ;
}
static struct V_17 *
F_329 ( struct V_261 * V_24 ,
struct V_2 * V_3 ,
const struct V_336 * V_337 )
{
struct V_17 * V_18 ;
int V_73 ;
F_2 ( V_3 -> V_323 ) ;
V_18 = F_330 ( F_112 ( V_24 -> V_4 . V_58 ) -> V_333 , V_86 ) ;
if ( V_18 == NULL )
return F_49 ( - V_64 ) ;
F_196 ( & V_18 -> V_338 ) ;
for ( V_73 = 0 ; V_73 < F_331 ( V_18 -> V_330 ) ; V_73 ++ )
F_332 ( & V_18 -> V_330 [ V_73 ] , F_316 ) ;
F_332 ( & V_18 -> V_339 , NULL ) ;
F_333 ( & V_18 -> V_331 , & V_3 -> V_241 ) ;
V_18 -> V_3 = V_3 ;
V_18 -> V_24 = V_24 ;
V_18 -> V_31 = V_24 -> V_4 . V_31 ;
if ( V_337 ) {
V_18 -> V_340 = * V_337 ;
if ( V_337 -> type == V_341 ) {
V_18 -> V_31 = V_337 -> V_342 . V_343 . V_31 ;
V_18 -> V_31 <<= V_128 ;
} else if ( V_337 -> type == V_344 ) {
V_18 -> V_31 =
F_334 ( & V_337 -> V_342 . V_345 ) ;
V_18 -> V_31 <<= V_128 ;
}
}
if ( F_3 ( V_3 ) ) {
V_18 -> V_51 |= V_346 ;
} else {
F_335 ( F_94 ( V_3 ) ) ;
}
F_197 ( & V_18 -> V_335 , & V_24 -> V_347 ) ;
return V_18 ;
}
static inline bool F_336 ( struct V_17 * V_18 ,
struct V_2 * V_3 ,
const struct V_336 * V_337 )
{
if ( V_18 -> V_3 != V_3 )
return false ;
if ( ! F_324 ( V_18 ) )
return true ;
if ( ! V_337 )
return V_18 -> V_340 . type == 0 ;
if ( V_18 -> V_340 . type != V_337 -> type )
return false ;
return memcmp ( & V_18 -> V_340 . V_342 ,
& V_337 -> V_342 ,
sizeof( V_337 -> V_342 ) ) == 0 ;
}
struct V_17 *
F_337 ( struct V_261 * V_24 ,
struct V_2 * V_3 ,
const struct V_336 * V_337 )
{
F_2 ( V_337 && ! F_3 ( V_3 ) ) ;
F_2 ( F_338 ( V_24 , V_3 , V_337 ) ) ;
return F_329 ( V_24 , V_3 , V_337 ) ;
}
struct V_17 *
F_338 ( struct V_261 * V_24 ,
struct V_2 * V_3 ,
const struct V_336 * V_337 )
{
struct V_17 * V_18 ;
F_339 (vma, &obj->vma_list, obj_link)
if ( F_336 ( V_18 , V_3 , V_337 ) )
return V_18 ;
return NULL ;
}
struct V_17 *
F_340 ( struct V_261 * V_24 ,
struct V_2 * V_3 ,
const struct V_336 * V_337 )
{
struct V_17 * V_18 ;
F_2 ( V_337 && ! F_3 ( V_3 ) ) ;
V_18 = F_338 ( V_24 , V_3 , V_337 ) ;
if ( ! V_18 )
V_18 = F_329 ( V_24 , V_3 , V_337 ) ;
F_2 ( F_321 ( V_18 ) ) ;
return V_18 ;
}
static struct V_348 *
F_341 ( const T_3 * V_349 , unsigned int V_263 ,
unsigned int V_350 , unsigned int V_351 ,
unsigned int V_352 ,
struct V_135 * V_265 , struct V_348 * V_353 )
{
unsigned int V_354 , V_355 ;
unsigned int V_356 ;
for ( V_354 = 0 ; V_354 < V_350 ; V_354 ++ ) {
V_356 = V_352 * ( V_351 - 1 ) + V_354 ;
for ( V_355 = 0 ; V_355 < V_351 ; V_355 ++ ) {
V_265 -> V_262 ++ ;
F_342 ( V_353 , NULL , V_71 , 0 ) ;
F_343 ( V_353 ) = V_349 [ V_263 + V_356 ] ;
F_344 ( V_353 ) = V_71 ;
V_353 = F_345 ( V_353 ) ;
V_356 -= V_352 ;
}
}
return V_353 ;
}
static struct V_135 *
F_346 ( const struct V_357 * V_358 ,
struct V_261 * V_24 )
{
const T_9 V_359 = V_24 -> V_4 . V_31 / V_71 ;
unsigned int V_31 = F_334 ( V_358 ) ;
struct V_223 V_223 ;
T_3 V_360 ;
unsigned long V_73 ;
T_3 * V_361 ;
struct V_135 * V_265 ;
struct V_348 * V_353 ;
int V_85 = - V_64 ;
V_361 = F_347 ( V_359 ,
sizeof( T_3 ) ,
V_161 ) ;
if ( ! V_361 )
return F_49 ( V_85 ) ;
V_265 = F_348 ( sizeof( * V_265 ) , V_86 ) ;
if ( ! V_265 )
goto V_362;
V_85 = F_349 ( V_265 , V_31 , V_86 ) ;
if ( V_85 )
goto V_363;
V_73 = 0 ;
F_173 (dma_addr, sgt_iter, obj->pages)
V_361 [ V_73 ++ ] = V_360 ;
F_2 ( V_73 != V_359 ) ;
V_265 -> V_262 = 0 ;
V_353 = V_265 -> V_136 ;
for ( V_73 = 0 ; V_73 < F_331 ( V_358 -> V_364 ) ; V_73 ++ ) {
V_353 = F_341 ( V_361 , V_358 -> V_364 [ V_73 ] . V_263 ,
V_358 -> V_364 [ V_73 ] . V_350 , V_358 -> V_364 [ V_73 ] . V_351 ,
V_358 -> V_364 [ V_73 ] . V_352 , V_265 , V_353 ) ;
}
F_263 ( L_41 ,
V_24 -> V_4 . V_31 , V_358 -> V_364 [ 0 ] . V_350 , V_358 -> V_364 [ 0 ] . V_351 , V_31 ) ;
F_350 ( V_361 ) ;
return V_265 ;
V_363:
F_53 ( V_265 ) ;
V_362:
F_350 ( V_361 ) ;
F_263 ( L_42 ,
V_24 -> V_4 . V_31 , V_358 -> V_364 [ 0 ] . V_350 , V_358 -> V_364 [ 0 ] . V_351 , V_31 ) ;
return F_49 ( V_85 ) ;
}
static struct V_135 *
F_351 ( const struct V_336 * V_337 ,
struct V_261 * V_24 )
{
struct V_135 * V_265 ;
struct V_348 * V_353 ;
struct V_133 V_365 ;
int V_85 = - V_64 ;
V_265 = F_348 ( sizeof( * V_265 ) , V_86 ) ;
if ( ! V_265 )
goto V_362;
V_85 = F_349 ( V_265 , V_337 -> V_342 . V_343 . V_31 , V_86 ) ;
if ( V_85 )
goto V_363;
V_353 = V_265 -> V_136 ;
V_265 -> V_262 = 0 ;
F_352 (obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if ( V_265 -> V_262 >= V_337 -> V_342 . V_343 . V_31 )
break;
F_342 ( V_353 , NULL , V_71 , 0 ) ;
F_343 ( V_353 ) = F_102 ( & V_365 ) ;
F_344 ( V_353 ) = V_71 ;
V_353 = F_345 ( V_353 ) ;
V_265 -> V_262 ++ ;
}
return V_265 ;
V_363:
F_53 ( V_265 ) ;
V_362:
return F_49 ( V_85 ) ;
}
static int
F_248 ( struct V_17 * V_18 )
{
int V_85 = 0 ;
if ( V_18 -> V_23 )
return 0 ;
if ( V_18 -> V_340 . type == V_366 )
V_18 -> V_23 = V_18 -> V_24 -> V_23 ;
else if ( V_18 -> V_340 . type == V_344 )
V_18 -> V_23 =
F_346 ( & V_18 -> V_340 . V_342 . V_345 , V_18 -> V_24 ) ;
else if ( V_18 -> V_340 . type == V_341 )
V_18 -> V_23 = F_351 ( & V_18 -> V_340 , V_18 -> V_24 ) ;
else
F_353 ( 1 , L_43 ,
V_18 -> V_340 . type ) ;
if ( ! V_18 -> V_23 ) {
F_255 ( L_44 ,
V_18 -> V_340 . type ) ;
V_85 = - V_67 ;
} else if ( F_109 ( V_18 -> V_23 ) ) {
V_85 = F_110 ( V_18 -> V_23 ) ;
V_18 -> V_23 = NULL ;
F_255 ( L_45 ,
V_18 -> V_340 . type , V_85 ) ;
}
return V_85 ;
}
int F_314 ( struct V_17 * V_18 , enum V_19 V_20 ,
T_1 V_51 )
{
T_1 V_367 ;
T_1 V_368 ;
int V_85 ;
if ( F_33 ( V_51 == 0 ) )
return - V_67 ;
V_367 = 0 ;
if ( V_51 & V_369 )
V_367 |= V_274 ;
if ( V_51 & V_370 )
V_367 |= V_275 ;
V_368 = V_18 -> V_51 & ( V_274 | V_275 ) ;
if ( V_51 & V_325 )
V_367 |= V_368 ;
else
V_367 &= ~ V_368 ;
if ( V_367 == 0 )
return 0 ;
if ( V_368 == 0 && V_18 -> V_3 -> V_180 ) {
F_354 ( V_18 ) ;
V_85 = V_18 -> V_3 -> V_180 ( V_18 -> V_3 ,
V_18 -> V_28 . V_29 ,
V_18 -> V_28 . V_31 ) ;
if ( V_85 )
return V_85 ;
}
V_85 = V_18 -> V_3 -> V_182 ( V_18 , V_20 , V_367 ) ;
if ( V_85 )
return V_85 ;
V_18 -> V_51 |= V_367 ;
return 0 ;
}
void V_238 * F_355 ( struct V_17 * V_18 )
{
void V_238 * V_371 ;
F_356 ( F_112 ( V_18 -> V_3 -> V_58 ) ) ;
F_357 ( & V_18 -> V_3 -> V_58 -> V_372 ) ;
if ( F_33 ( ! F_358 ( V_18 ) ) )
return F_359 ( - V_169 ) ;
F_2 ( ! F_324 ( V_18 ) ) ;
F_2 ( ( V_18 -> V_51 & V_274 ) == 0 ) ;
V_371 = V_18 -> V_373 ;
if ( V_371 == NULL ) {
V_371 = F_360 ( & F_1 ( V_18 -> V_3 ) -> V_288 ,
V_18 -> V_28 . V_29 ,
V_18 -> V_28 . V_31 ) ;
if ( V_371 == NULL )
return F_359 ( - V_64 ) ;
V_18 -> V_373 = V_371 ;
}
F_361 ( V_18 ) ;
return V_371 ;
}
void F_362 ( struct V_17 * * V_374 )
{
struct V_17 * V_18 ;
V_18 = F_363 ( V_374 ) ;
if ( ! V_18 )
return;
F_364 ( V_18 ) ;
F_365 ( V_18 ) ;
}
