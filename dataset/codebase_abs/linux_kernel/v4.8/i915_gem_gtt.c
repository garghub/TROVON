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
if ( V_18 -> V_23 -> V_24 )
V_22 |= V_25 ;
V_18 -> V_3 -> V_26 ( V_18 -> V_3 , V_18 -> V_23 -> V_27 , V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
return 0 ;
}
static void F_15 ( struct V_17 * V_18 )
{
V_18 -> V_3 -> V_30 ( V_18 -> V_3 ,
V_18 -> V_28 . V_29 ,
V_18 -> V_23 -> V_4 . V_31 ,
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
if ( ! ( V_51 & V_25 ) )
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
struct V_61 * V_61 = & V_58 -> V_13 -> V_58 ;
V_60 -> V_62 = F_27 ( V_51 ) ;
if ( ! V_60 -> V_62 )
return - V_63 ;
V_60 -> V_64 = F_28 ( V_61 ,
V_60 -> V_62 , 0 , 4096 , V_65 ) ;
if ( F_29 ( V_61 , V_60 -> V_64 ) ) {
F_30 ( V_60 -> V_62 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_31 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
return F_26 ( V_58 , V_60 , V_67 ) ;
}
static void F_32 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
if ( F_33 ( ! V_60 -> V_62 ) )
return;
F_34 ( & V_58 -> V_13 -> V_58 , V_60 -> V_64 , 4096 , V_65 ) ;
F_30 ( V_60 -> V_62 ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
}
static void * F_35 ( struct V_59 * V_60 )
{
return F_36 ( V_60 -> V_62 ) ;
}
static void F_37 ( struct V_57 * V_58 , void * V_68 )
{
if ( F_38 ( V_58 ) || F_39 ( V_58 ) )
F_40 ( V_68 , V_69 ) ;
F_41 ( V_68 ) ;
}
static void F_42 ( struct V_57 * V_58 , struct V_59 * V_60 ,
const T_7 V_70 )
{
int V_71 ;
T_7 * const V_68 = F_35 ( V_60 ) ;
for ( V_71 = 0 ; V_71 < 512 ; V_71 ++ )
V_68 [ V_71 ] = V_70 ;
F_37 ( V_58 , V_68 ) ;
}
static void F_43 ( struct V_57 * V_58 , struct V_59 * V_60 ,
const T_8 V_72 )
{
T_7 V_73 = V_72 ;
V_73 = V_73 << 32 | V_72 ;
F_42 ( V_58 , V_60 , V_73 ) ;
}
static struct V_74 * F_44 ( struct V_57 * V_58 )
{
struct V_74 * V_75 ;
int V_76 ;
V_75 = F_45 ( sizeof( * V_75 ) , V_67 ) ;
if ( V_75 == NULL )
return F_46 ( - V_63 ) ;
V_76 = F_26 ( V_58 , F_47 ( V_75 ) , V_77 | V_78 ) ;
if ( V_76 ) {
F_48 ( V_75 ) ;
return F_46 ( V_76 ) ;
}
F_49 ( F_50 ( V_75 ) , 1 ) ;
return V_75 ;
}
static void F_51 ( struct V_57 * V_58 ,
struct V_74 * V_75 )
{
F_52 ( F_50 ( V_75 ) , 1 ) ;
F_53 ( V_58 , V_75 ) ;
F_48 ( V_75 ) ;
}
static struct V_79 * F_54 ( struct V_57 * V_58 )
{
struct V_79 * V_80 ;
const T_9 V_81 = F_55 ( V_58 ) -> V_82 >= 8 ?
V_83 : V_84 ;
int V_76 = - V_63 ;
V_80 = F_45 ( sizeof( * V_80 ) , V_67 ) ;
if ( ! V_80 )
return F_46 ( - V_63 ) ;
V_80 -> V_85 = F_56 ( F_57 ( V_81 ) , sizeof( * V_80 -> V_85 ) ,
V_67 ) ;
if ( ! V_80 -> V_85 )
goto V_86;
V_76 = F_58 ( V_58 , V_80 ) ;
if ( V_76 )
goto V_87;
return V_80 ;
V_87:
F_48 ( V_80 -> V_85 ) ;
V_86:
F_48 ( V_80 ) ;
return F_46 ( V_76 ) ;
}
static void F_59 ( struct V_57 * V_58 , struct V_79 * V_80 )
{
F_53 ( V_58 , V_80 ) ;
F_48 ( V_80 -> V_85 ) ;
F_48 ( V_80 ) ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
T_2 V_88 ;
V_88 = F_16 ( F_61 ( V_3 -> V_89 ) ,
V_47 , true ) ;
F_62 ( V_3 -> V_58 , V_80 , V_88 ) ;
}
static void F_63 ( struct V_2 * V_3 ,
struct V_79 * V_80 )
{
T_5 V_88 ;
F_33 ( F_61 ( V_3 -> V_89 ) == 0 ) ;
V_88 = V_3 -> V_90 ( F_61 ( V_3 -> V_89 ) ,
V_47 , true , 0 ) ;
F_64 ( V_3 -> V_58 , V_80 , V_88 ) ;
}
static struct V_91 * F_65 ( struct V_57 * V_58 )
{
struct V_91 * V_92 ;
int V_76 = - V_63 ;
V_92 = F_45 ( sizeof( * V_92 ) , V_67 ) ;
if ( ! V_92 )
return F_46 ( - V_63 ) ;
V_92 -> V_93 = F_56 ( F_57 ( V_94 ) ,
sizeof( * V_92 -> V_93 ) , V_67 ) ;
if ( ! V_92 -> V_93 )
goto V_86;
V_76 = F_58 ( V_58 , V_92 ) ;
if ( V_76 )
goto V_87;
return V_92 ;
V_87:
F_48 ( V_92 -> V_93 ) ;
V_86:
F_48 ( V_92 ) ;
return F_46 ( V_76 ) ;
}
static void F_66 ( struct V_57 * V_58 , struct V_91 * V_92 )
{
if ( F_50 ( V_92 ) ) {
F_53 ( V_58 , V_92 ) ;
F_48 ( V_92 -> V_93 ) ;
F_48 ( V_92 ) ;
}
}
static void F_67 ( struct V_2 * V_3 ,
struct V_91 * V_92 )
{
T_4 V_95 ;
V_95 = F_17 ( F_61 ( V_3 -> V_96 ) , V_47 ) ;
F_62 ( V_3 -> V_58 , V_92 , V_95 ) ;
}
static int F_68 ( struct V_57 * V_58 ,
struct V_97 * V_98 )
{
T_9 V_99 = F_69 ( V_58 ) ;
V_98 -> V_100 = F_56 ( F_57 ( V_99 ) ,
sizeof( unsigned long ) ,
V_67 ) ;
if ( ! V_98 -> V_100 )
return - V_63 ;
V_98 -> V_101 = F_56 ( V_99 , sizeof( * V_98 -> V_101 ) ,
V_67 ) ;
if ( ! V_98 -> V_101 ) {
F_48 ( V_98 -> V_100 ) ;
V_98 -> V_100 = NULL ;
return - V_63 ;
}
return 0 ;
}
static void F_70 ( struct V_97 * V_98 )
{
F_48 ( V_98 -> V_100 ) ;
F_48 ( V_98 -> V_101 ) ;
V_98 -> V_101 = NULL ;
}
static struct
V_97 * F_71 ( struct V_57 * V_58 )
{
struct V_97 * V_98 ;
int V_76 = - V_63 ;
F_33 ( ! F_72 ( V_58 ) ) ;
V_98 = F_45 ( sizeof( * V_98 ) , V_67 ) ;
if ( ! V_98 )
return F_46 ( - V_63 ) ;
V_76 = F_68 ( V_58 , V_98 ) ;
if ( V_76 )
goto V_86;
V_76 = F_58 ( V_58 , V_98 ) ;
if ( V_76 )
goto V_87;
return V_98 ;
V_87:
F_70 ( V_98 ) ;
V_86:
F_48 ( V_98 ) ;
return F_46 ( V_76 ) ;
}
static void F_73 ( struct V_57 * V_58 ,
struct V_97 * V_98 )
{
F_70 ( V_98 ) ;
if ( F_72 ( V_58 ) ) {
F_53 ( V_58 , V_98 ) ;
F_48 ( V_98 ) ;
}
}
static void F_74 ( struct V_2 * V_3 ,
struct V_97 * V_98 )
{
T_10 V_102 ;
V_102 = F_75 ( F_61 ( V_3 -> V_103 ) , V_47 ) ;
F_62 ( V_3 -> V_58 , V_98 , V_102 ) ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_104 * V_105 )
{
T_11 V_106 ;
V_106 = F_77 ( F_61 ( V_3 -> V_107 ) ,
V_47 ) ;
F_62 ( V_3 -> V_58 , V_105 , V_106 ) ;
}
static void
F_78 ( struct V_108 * V_109 ,
struct V_97 * V_98 ,
struct V_91 * V_92 ,
int V_110 )
{
T_10 * V_111 ;
if ( ! F_72 ( V_109 -> V_4 . V_58 ) )
return;
V_111 = F_79 ( V_98 ) ;
V_111 [ V_110 ] = F_75 ( F_61 ( V_92 ) , V_47 ) ;
F_80 ( V_109 , V_111 ) ;
}
static void
F_81 ( struct V_108 * V_109 ,
struct V_104 * V_105 ,
struct V_97 * V_98 ,
int V_110 )
{
T_11 * V_112 = F_79 ( V_105 ) ;
F_33 ( ! F_72 ( V_109 -> V_4 . V_58 ) ) ;
V_112 [ V_110 ] = F_77 ( F_61 ( V_98 ) , V_47 ) ;
F_80 ( V_109 , V_112 ) ;
}
static int F_82 ( struct V_113 * V_114 ,
unsigned V_115 ,
T_3 V_32 )
{
struct V_116 * V_117 = V_114 -> V_117 ;
int V_76 ;
F_83 ( V_115 >= 4 ) ;
V_76 = F_84 ( V_114 , 6 ) ;
if ( V_76 )
return V_76 ;
F_85 ( V_117 , F_86 ( 1 ) ) ;
F_87 ( V_117 , F_88 ( V_117 , V_115 ) ) ;
F_85 ( V_117 , F_89 ( V_32 ) ) ;
F_85 ( V_117 , F_86 ( 1 ) ) ;
F_87 ( V_117 , F_90 ( V_117 , V_115 ) ) ;
F_85 ( V_117 , F_91 ( V_32 ) ) ;
F_92 ( V_117 ) ;
return 0 ;
}
static int F_93 ( struct V_108 * V_109 ,
struct V_113 * V_114 )
{
int V_71 , V_76 ;
for ( V_71 = V_118 - 1 ; V_71 >= 0 ; V_71 -- ) {
const T_3 V_119 = F_94 ( V_109 , V_71 ) ;
V_76 = F_82 ( V_114 , V_71 , V_119 ) ;
if ( V_76 )
return V_76 ;
}
return 0 ;
}
static int F_95 ( struct V_108 * V_109 ,
struct V_113 * V_114 )
{
return F_82 ( V_114 , 0 , F_61 ( & V_109 -> V_105 ) ) ;
}
static void F_96 ( struct V_2 * V_3 ,
struct V_97 * V_98 ,
T_7 V_29 ,
T_7 V_120 ,
T_2 V_88 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
T_2 * V_121 ;
unsigned V_122 = F_98 ( V_29 ) ;
unsigned V_43 = F_99 ( V_29 ) ;
unsigned V_35 = F_100 ( V_29 ) ;
unsigned V_123 = V_120 >> V_124 ;
unsigned V_125 , V_71 ;
if ( F_33 ( ! V_98 ) )
return;
while ( V_123 ) {
struct V_91 * V_92 ;
struct V_79 * V_80 ;
if ( F_33 ( ! V_98 -> V_101 [ V_122 ] ) )
break;
V_92 = V_98 -> V_101 [ V_122 ] ;
if ( F_33 ( ! V_92 -> V_126 [ V_43 ] ) )
break;
V_80 = V_92 -> V_126 [ V_43 ] ;
if ( F_33 ( ! F_50 ( V_80 ) ) )
break;
V_125 = V_35 + V_123 ;
if ( V_125 > V_83 )
V_125 = V_83 ;
V_121 = F_79 ( V_80 ) ;
for ( V_71 = V_35 ; V_71 < V_125 ; V_71 ++ ) {
V_121 [ V_71 ] = V_88 ;
V_123 -- ;
}
F_80 ( V_109 , V_121 ) ;
V_35 = 0 ;
if ( ++ V_43 == V_94 ) {
if ( ++ V_122 == F_69 ( V_3 -> V_58 ) )
break;
V_43 = 0 ;
}
}
}
static void F_101 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_120 ,
bool V_127 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
T_2 V_88 = F_16 ( F_61 ( V_3 -> V_89 ) ,
V_47 , V_127 ) ;
if ( ! F_72 ( V_3 -> V_58 ) ) {
F_96 ( V_3 , & V_109 -> V_98 , V_29 , V_120 ,
V_88 ) ;
} else {
T_7 V_128 ;
struct V_97 * V_98 ;
F_102 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_96 ( V_3 , V_98 , V_29 , V_120 ,
V_88 ) ;
}
}
}
static void
F_103 ( struct V_2 * V_3 ,
struct V_97 * V_98 ,
struct V_129 * V_130 ,
T_7 V_29 ,
enum V_19 V_20 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
T_2 * V_121 ;
unsigned V_122 = F_98 ( V_29 ) ;
unsigned V_43 = F_99 ( V_29 ) ;
unsigned V_35 = F_100 ( V_29 ) ;
V_121 = NULL ;
while ( F_104 ( V_130 ) ) {
if ( V_121 == NULL ) {
struct V_91 * V_92 = V_98 -> V_101 [ V_122 ] ;
struct V_79 * V_80 = V_92 -> V_126 [ V_43 ] ;
V_121 = F_79 ( V_80 ) ;
}
V_121 [ V_35 ] =
F_16 ( F_105 ( V_130 ) ,
V_20 , true ) ;
if ( ++ V_35 == V_83 ) {
F_80 ( V_109 , V_121 ) ;
V_121 = NULL ;
if ( ++ V_43 == V_94 ) {
if ( ++ V_122 == F_69 ( V_3 -> V_58 ) )
break;
V_43 = 0 ;
}
V_35 = 0 ;
}
}
if ( V_121 )
F_80 ( V_109 , V_121 ) ;
}
static void F_106 ( struct V_2 * V_3 ,
struct V_131 * V_27 ,
T_7 V_29 ,
enum V_19 V_20 ,
T_1 V_21 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
struct V_129 V_130 ;
F_107 ( & V_130 , V_27 -> V_132 , F_108 ( V_27 -> V_132 ) , 0 ) ;
if ( ! F_72 ( V_3 -> V_58 ) ) {
F_103 ( V_3 , & V_109 -> V_98 , & V_130 , V_29 ,
V_20 ) ;
} else {
struct V_97 * V_98 ;
T_7 V_128 ;
T_7 V_120 = ( T_7 ) V_27 -> V_133 << V_124 ;
F_102 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_103 ( V_3 , V_98 , & V_130 ,
V_29 , V_20 ) ;
}
}
}
static void F_109 ( struct V_57 * V_58 ,
struct V_91 * V_92 )
{
int V_71 ;
if ( ! F_50 ( V_92 ) )
return;
F_110 (i, pd->used_pdes, I915_PDES) {
if ( F_33 ( ! V_92 -> V_126 [ V_71 ] ) )
continue;
F_59 ( V_58 , V_92 -> V_126 [ V_71 ] ) ;
V_92 -> V_126 [ V_71 ] = NULL ;
}
}
static int F_111 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
int V_76 ;
V_3 -> V_89 = F_44 ( V_58 ) ;
if ( F_112 ( V_3 -> V_89 ) )
return F_113 ( V_3 -> V_89 ) ;
V_3 -> V_96 = F_54 ( V_58 ) ;
if ( F_112 ( V_3 -> V_96 ) ) {
V_76 = F_113 ( V_3 -> V_96 ) ;
goto F_51;
}
V_3 -> V_103 = F_65 ( V_58 ) ;
if ( F_112 ( V_3 -> V_103 ) ) {
V_76 = F_113 ( V_3 -> V_103 ) ;
goto F_59;
}
if ( F_72 ( V_58 ) ) {
V_3 -> V_107 = F_71 ( V_58 ) ;
if ( F_112 ( V_3 -> V_107 ) ) {
V_76 = F_113 ( V_3 -> V_107 ) ;
goto F_66;
}
}
F_60 ( V_3 , V_3 -> V_96 ) ;
F_67 ( V_3 , V_3 -> V_103 ) ;
if ( F_72 ( V_58 ) )
F_74 ( V_3 , V_3 -> V_107 ) ;
return 0 ;
F_66:
F_66 ( V_58 , V_3 -> V_103 ) ;
F_59:
F_59 ( V_58 , V_3 -> V_96 ) ;
F_51:
F_51 ( V_58 , V_3 -> V_89 ) ;
return V_76 ;
}
static int F_114 ( struct V_108 * V_109 , bool V_134 )
{
enum V_135 V_136 ;
struct V_5 * V_6 = F_115 ( V_109 -> V_4 . V_58 ) ;
int V_71 ;
if ( F_72 ( V_6 ) ) {
T_12 V_64 = F_61 ( & V_109 -> V_105 ) ;
F_116 ( F_117 ( V_98 [ 0 ] . V_137 ) , F_91 ( V_64 ) ) ;
F_116 ( F_117 ( V_98 [ 0 ] . V_138 ) , F_89 ( V_64 ) ) ;
V_136 = ( V_134 ? V_139 :
V_140 ) ;
} else {
for ( V_71 = 0 ; V_71 < V_118 ; V_71 ++ ) {
T_12 V_64 = F_94 ( V_109 , V_71 ) ;
F_116 ( F_117 ( V_98 [ V_71 ] . V_137 ) , F_91 ( V_64 ) ) ;
F_116 ( F_117 ( V_98 [ V_71 ] . V_138 ) , F_89 ( V_64 ) ) ;
}
V_136 = ( V_134 ? V_141 :
V_142 ) ;
}
F_116 ( F_117 ( V_143 ) , V_136 ) ;
return 0 ;
}
static void F_118 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
if ( F_72 ( V_58 ) )
F_73 ( V_58 , V_3 -> V_107 ) ;
F_66 ( V_58 , V_3 -> V_103 ) ;
F_59 ( V_58 , V_3 -> V_96 ) ;
F_51 ( V_58 , V_3 -> V_89 ) ;
}
static void F_119 ( struct V_57 * V_58 ,
struct V_97 * V_98 )
{
int V_71 ;
F_110 (i, pdp->used_pdpes, I915_PDPES_PER_PDP(dev)) {
if ( F_33 ( ! V_98 -> V_101 [ V_71 ] ) )
continue;
F_109 ( V_58 , V_98 -> V_101 [ V_71 ] ) ;
F_66 ( V_58 , V_98 -> V_101 [ V_71 ] ) ;
}
F_73 ( V_58 , V_98 ) ;
}
static void F_120 ( struct V_108 * V_109 )
{
int V_71 ;
F_110 (i, ppgtt->pml4.used_pml4es, GEN8_PML4ES_PER_PML4) {
if ( F_33 ( ! V_109 -> V_105 . V_144 [ V_71 ] ) )
continue;
F_119 ( V_109 -> V_4 . V_58 , V_109 -> V_105 . V_144 [ V_71 ] ) ;
}
F_53 ( V_109 -> V_4 . V_58 , & V_109 -> V_105 ) ;
}
static void F_121 ( struct V_2 * V_3 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
if ( F_8 ( F_115 ( V_3 -> V_58 ) ) )
F_114 ( V_109 , false ) ;
if ( ! F_72 ( V_109 -> V_4 . V_58 ) )
F_119 ( V_109 -> V_4 . V_58 , & V_109 -> V_98 ) ;
else
F_120 ( V_109 ) ;
F_118 ( V_3 ) ;
}
static int F_122 ( struct V_2 * V_3 ,
struct V_91 * V_92 ,
T_7 V_29 ,
T_7 V_120 ,
unsigned long * V_145 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_79 * V_80 ;
T_8 V_43 ;
F_123 (pt, pd, start, length, pde) {
if ( F_124 ( V_43 , V_92 -> V_93 ) ) {
F_33 ( V_80 == V_3 -> V_96 ) ;
continue;
}
V_80 = F_54 ( V_58 ) ;
if ( F_112 ( V_80 ) )
goto V_146;
F_60 ( V_3 , V_80 ) ;
V_92 -> V_126 [ V_43 ] = V_80 ;
F_125 ( V_43 , V_145 ) ;
F_126 ( V_3 , V_43 , V_29 , V_147 ) ;
}
return 0 ;
V_146:
F_110 (pde, new_pts, I915_PDES)
F_59 ( V_58 , V_92 -> V_126 [ V_43 ] ) ;
return - V_63 ;
}
static int
F_127 ( struct V_2 * V_3 ,
struct V_97 * V_98 ,
T_7 V_29 ,
T_7 V_120 ,
unsigned long * V_148 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_91 * V_92 ;
T_8 V_122 ;
T_8 V_99 = F_69 ( V_58 ) ;
F_33 ( ! F_128 ( V_148 , V_99 ) ) ;
F_129 (pd, pdp, start, length, pdpe) {
if ( F_124 ( V_122 , V_98 -> V_100 ) )
continue;
V_92 = F_65 ( V_58 ) ;
if ( F_112 ( V_92 ) )
goto V_146;
F_67 ( V_3 , V_92 ) ;
V_98 -> V_101 [ V_122 ] = V_92 ;
F_125 ( V_122 , V_148 ) ;
F_130 ( V_3 , V_122 , V_29 , V_149 ) ;
}
return 0 ;
V_146:
F_110 (pdpe, new_pds, pdpes)
F_66 ( V_58 , V_98 -> V_101 [ V_122 ] ) ;
return - V_63 ;
}
static int
F_131 ( struct V_2 * V_3 ,
struct V_104 * V_105 ,
T_7 V_29 ,
T_7 V_120 ,
unsigned long * V_150 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_97 * V_98 ;
T_8 V_128 ;
F_33 ( ! F_128 ( V_150 , V_151 ) ) ;
F_102 (pdp, pml4, start, length, pml4e) {
if ( ! F_124 ( V_128 , V_105 -> V_152 ) ) {
V_98 = F_71 ( V_58 ) ;
if ( F_112 ( V_98 ) )
goto V_146;
F_74 ( V_3 , V_98 ) ;
V_105 -> V_144 [ V_128 ] = V_98 ;
F_125 ( V_128 , V_150 ) ;
F_132 ( V_3 ,
V_128 ,
V_29 ,
V_153 ) ;
}
}
return 0 ;
V_146:
F_110 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_73 ( V_58 , V_105 -> V_144 [ V_128 ] ) ;
return - V_63 ;
}
static void
F_133 ( unsigned long * V_148 , unsigned long * V_145 )
{
F_48 ( V_145 ) ;
F_48 ( V_148 ) ;
}
static
int T_13 F_134 ( unsigned long * * V_148 ,
unsigned long * * V_145 ,
T_8 V_99 )
{
unsigned long * V_154 ;
unsigned long * V_155 ;
V_154 = F_56 ( F_57 ( V_99 ) , sizeof( unsigned long ) , V_156 ) ;
if ( ! V_154 )
return - V_63 ;
V_155 = F_56 ( V_99 , F_57 ( V_94 ) * sizeof( unsigned long ) ,
V_156 ) ;
if ( ! V_155 )
goto V_157;
* V_148 = V_154 ;
* V_145 = V_155 ;
return 0 ;
V_157:
F_133 ( V_154 , V_155 ) ;
return - V_63 ;
}
static void F_135 ( struct V_108 * V_109 )
{
V_109 -> V_158 = F_55 ( V_109 -> V_4 . V_58 ) -> V_159 ;
}
static int F_136 ( struct V_2 * V_3 ,
struct V_97 * V_98 ,
T_7 V_29 ,
T_7 V_120 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
unsigned long * V_160 , * V_161 ;
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_91 * V_92 ;
const T_7 V_162 = V_29 ;
const T_7 V_163 = V_120 ;
T_8 V_122 ;
T_8 V_99 = F_69 ( V_58 ) ;
int V_76 ;
if ( F_33 ( V_29 + V_120 < V_29 ) )
return - V_164 ;
if ( F_33 ( V_29 + V_120 > V_3 -> V_165 ) )
return - V_164 ;
V_76 = F_134 ( & V_160 , & V_161 , V_99 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_127 ( V_3 , V_98 , V_29 , V_120 ,
V_160 ) ;
if ( V_76 ) {
F_133 ( V_160 , V_161 ) ;
return V_76 ;
}
F_129 (pd, pdp, start, length, pdpe) {
V_76 = F_122 ( V_3 , V_92 , V_29 , V_120 ,
V_161 + V_122 * F_57 ( V_94 ) ) ;
if ( V_76 )
goto V_157;
}
V_29 = V_162 ;
V_120 = V_163 ;
F_129 (pd, pdp, start, length, pdpe) {
T_4 * const V_101 = F_79 ( V_92 ) ;
struct V_79 * V_80 ;
T_7 V_166 = V_120 ;
T_7 V_167 = V_29 ;
T_8 V_43 ;
F_33 ( ! V_92 ) ;
F_123 (pt, pd, pd_start, pd_len, pde) {
F_33 ( ! V_80 ) ;
F_33 ( ! V_166 ) ;
F_33 ( ! F_137 ( V_167 , V_166 ) ) ;
F_138 ( V_80 -> V_85 ,
F_100 ( V_167 ) ,
F_137 ( V_167 , V_166 ) ) ;
F_125 ( V_43 , V_92 -> V_93 ) ;
V_101 [ V_43 ] = F_17 ( F_61 ( V_80 ) ,
V_47 ) ;
F_139 ( & V_109 -> V_4 , V_43 , V_80 ,
F_100 ( V_29 ) ,
F_137 ( V_29 , V_120 ) ,
V_83 ) ;
}
F_80 ( V_109 , V_101 ) ;
F_125 ( V_122 , V_98 -> V_100 ) ;
F_78 ( V_109 , V_98 , V_92 , V_122 ) ;
}
F_133 ( V_160 , V_161 ) ;
F_135 ( V_109 ) ;
return 0 ;
V_157:
while ( V_122 -- ) {
unsigned long V_168 ;
F_110 (temp, new_page_tables + pdpe *
BITS_TO_LONGS(I915_PDES), I915_PDES)
F_59 ( V_58 , V_98 -> V_101 [ V_122 ] -> V_126 [ V_168 ] ) ;
}
F_110 (pdpe, new_page_dirs, pdpes)
F_66 ( V_58 , V_98 -> V_101 [ V_122 ] ) ;
F_133 ( V_160 , V_161 ) ;
F_135 ( V_109 ) ;
return V_76 ;
}
static int F_140 ( struct V_2 * V_3 ,
struct V_104 * V_105 ,
T_7 V_29 ,
T_7 V_120 )
{
F_141 ( V_150 , V_151 ) ;
struct V_108 * V_109 = F_97 ( V_3 ) ;
struct V_97 * V_98 ;
T_7 V_128 ;
int V_76 = 0 ;
F_142 ( V_150 , V_151 ) ;
V_76 = F_131 ( V_3 , V_105 , V_29 , V_120 ,
V_150 ) ;
if ( V_76 )
return V_76 ;
F_143 ( F_144 ( V_150 , V_151 ) > 2 ,
L_3
L_4 ) ;
F_102 (pdp, pml4, start, length, pml4e) {
F_33 ( ! V_98 ) ;
V_76 = F_136 ( V_3 , V_98 , V_29 , V_120 ) ;
if ( V_76 )
goto V_157;
F_81 ( V_109 , V_105 , V_98 , V_128 ) ;
}
F_145 ( V_105 -> V_152 , V_150 , V_105 -> V_152 ,
V_151 ) ;
return 0 ;
V_157:
F_110 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_119 ( V_3 -> V_58 , V_105 -> V_144 [ V_128 ] ) ;
return V_76 ;
}
static int F_146 ( struct V_2 * V_3 ,
T_7 V_29 , T_7 V_120 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
if ( F_72 ( V_3 -> V_58 ) )
return F_140 ( V_3 , & V_109 -> V_105 , V_29 , V_120 ) ;
else
return F_136 ( V_3 , & V_109 -> V_98 , V_29 , V_120 ) ;
}
static void F_147 ( struct V_97 * V_98 ,
T_7 V_29 , T_7 V_120 ,
T_2 V_88 ,
struct V_169 * V_170 )
{
struct V_91 * V_92 ;
T_8 V_122 ;
F_129 (pd, pdp, start, length, pdpe) {
struct V_79 * V_80 ;
T_7 V_166 = V_120 ;
T_7 V_167 = V_29 ;
T_8 V_43 ;
if ( ! F_124 ( V_122 , V_98 -> V_100 ) )
continue;
F_148 ( V_170 , L_5 , V_122 ) ;
F_123 (pt, pd, pd_start, pd_len, pde) {
T_8 V_35 ;
T_2 * V_121 ;
if ( ! F_124 ( V_43 , V_92 -> V_93 ) )
continue;
V_121 = F_79 ( V_80 ) ;
for ( V_35 = 0 ; V_35 < V_83 ; V_35 += 4 ) {
T_7 V_171 =
( V_122 << V_149 ) |
( V_43 << V_147 ) |
( V_35 << V_172 ) ;
int V_71 ;
bool V_173 = false ;
for ( V_71 = 0 ; V_71 < 4 ; V_71 ++ )
if ( V_121 [ V_35 + V_71 ] != V_88 )
V_173 = true ;
if ( ! V_173 )
continue;
F_148 ( V_170 , L_6 , V_171 , V_122 , V_43 , V_35 ) ;
for ( V_71 = 0 ; V_71 < 4 ; V_71 ++ ) {
if ( V_121 [ V_35 + V_71 ] != V_88 )
F_148 ( V_170 , L_7 , V_121 [ V_35 + V_71 ] ) ;
else
F_149 ( V_170 , L_8 ) ;
}
F_149 ( V_170 , L_9 ) ;
}
F_41 ( V_121 ) ;
}
}
}
static void F_150 ( struct V_108 * V_109 , struct V_169 * V_170 )
{
struct V_2 * V_3 = & V_109 -> V_4 ;
T_7 V_29 = V_109 -> V_4 . V_29 ;
T_7 V_120 = V_109 -> V_4 . V_165 ;
T_2 V_88 = F_16 ( F_61 ( V_3 -> V_89 ) ,
V_47 , true ) ;
if ( ! F_72 ( V_3 -> V_58 ) ) {
F_147 ( & V_109 -> V_98 , V_29 , V_120 , V_88 , V_170 ) ;
} else {
T_7 V_128 ;
struct V_104 * V_105 = & V_109 -> V_105 ;
struct V_97 * V_98 ;
F_102 (pdp, pml4, start, length, pml4e) {
if ( ! F_124 ( V_128 , V_105 -> V_152 ) )
continue;
F_148 ( V_170 , L_10 , V_128 ) ;
F_147 ( V_98 , V_29 , V_120 , V_88 , V_170 ) ;
}
}
}
static int F_151 ( struct V_108 * V_109 )
{
unsigned long * V_160 , * V_161 ;
T_8 V_99 = F_69 ( V_58 ) ;
int V_76 ;
V_76 = F_134 ( & V_160 , & V_161 , V_99 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_127 ( & V_109 -> V_4 , & V_109 -> V_98 ,
0 , 1ULL << 32 ,
V_160 ) ;
if ( ! V_76 )
* V_109 -> V_98 . V_100 = * V_160 ;
F_133 ( V_160 , V_161 ) ;
return V_76 ;
}
static int F_152 ( struct V_108 * V_109 )
{
int V_76 ;
V_76 = F_111 ( & V_109 -> V_4 ) ;
if ( V_76 )
return V_76 ;
V_109 -> V_4 . V_29 = 0 ;
V_109 -> V_4 . V_174 = F_121 ;
V_109 -> V_4 . V_175 = F_146 ;
V_109 -> V_4 . V_26 = F_106 ;
V_109 -> V_4 . V_30 = F_101 ;
V_109 -> V_4 . V_176 = F_15 ;
V_109 -> V_4 . V_177 = F_14 ;
V_109 -> V_178 = F_150 ;
if ( F_72 ( V_109 -> V_4 . V_58 ) ) {
V_76 = F_58 ( V_109 -> V_4 . V_58 , & V_109 -> V_105 ) ;
if ( V_76 )
goto V_179;
F_76 ( & V_109 -> V_4 , & V_109 -> V_105 ) ;
V_109 -> V_4 . V_165 = 1ULL << 48 ;
V_109 -> V_180 = F_95 ;
} else {
V_76 = F_68 ( V_109 -> V_4 . V_58 , & V_109 -> V_98 ) ;
if ( V_76 )
goto V_179;
V_109 -> V_4 . V_165 = 1ULL << 32 ;
V_109 -> V_180 = F_93 ;
F_132 ( & V_109 -> V_4 ,
0 , 0 ,
V_153 ) ;
if ( F_8 ( F_115 ( V_109 -> V_4 . V_58 ) ) ) {
V_76 = F_151 ( V_109 ) ;
if ( V_76 )
goto V_179;
}
}
if ( F_8 ( F_115 ( V_109 -> V_4 . V_58 ) ) )
F_114 ( V_109 , true ) ;
return 0 ;
V_179:
F_118 ( & V_109 -> V_4 ) ;
return V_76 ;
}
static void F_153 ( struct V_108 * V_109 , struct V_169 * V_170 )
{
struct V_2 * V_3 = & V_109 -> V_4 ;
struct V_79 * V_21 ;
T_5 V_88 ;
T_8 V_181 ;
T_8 V_35 , V_43 ;
T_8 V_29 = V_109 -> V_4 . V_29 , V_120 = V_109 -> V_4 . V_165 ;
V_88 = V_3 -> V_90 ( F_61 ( V_3 -> V_89 ) ,
V_47 , true , 0 ) ;
F_154 (unused, &ppgtt->pd, start, length, pde) {
T_1 V_182 ;
T_5 * V_121 ;
const T_3 V_183 = F_61 ( V_109 -> V_92 . V_126 [ V_43 ] ) ;
V_181 = F_155 ( V_109 -> V_184 + V_43 ) ;
V_182 = ( F_156 ( V_183 ) | V_185 ) ;
if ( V_181 != V_182 )
F_148 ( V_170 , L_11 ,
V_43 ,
V_181 ,
V_182 ) ;
F_148 ( V_170 , L_12 , V_181 ) ;
V_121 = F_79 ( V_109 -> V_92 . V_126 [ V_43 ] ) ;
for ( V_35 = 0 ; V_35 < V_84 ; V_35 += 4 ) {
unsigned long V_171 =
( V_43 * V_69 * V_84 ) +
( V_35 * V_69 ) ;
int V_71 ;
bool V_173 = false ;
for ( V_71 = 0 ; V_71 < 4 ; V_71 ++ )
if ( V_121 [ V_35 + V_71 ] != V_88 )
V_173 = true ;
if ( ! V_173 )
continue;
F_148 ( V_170 , L_13 , V_171 , V_43 , V_35 ) ;
for ( V_71 = 0 ; V_71 < 4 ; V_71 ++ ) {
if ( V_121 [ V_35 + V_71 ] != V_88 )
F_148 ( V_170 , L_14 , V_121 [ V_35 + V_71 ] ) ;
else
F_149 ( V_170 , L_8 ) ;
}
F_149 ( V_170 , L_9 ) ;
}
F_80 ( V_109 , V_121 ) ;
}
}
static void F_157 ( struct V_91 * V_92 ,
const int V_43 , struct V_79 * V_80 )
{
struct V_108 * V_109 =
F_4 ( V_92 , struct V_108 , V_92 ) ;
T_1 V_181 ;
V_181 = F_156 ( F_61 ( V_80 ) ) ;
V_181 |= V_185 ;
F_158 ( V_181 , V_109 -> V_184 + V_43 ) ;
}
static void F_159 ( struct V_5 * V_6 ,
struct V_91 * V_92 ,
T_8 V_29 , T_8 V_120 )
{
struct V_1 * V_186 = & V_6 -> V_186 ;
struct V_79 * V_80 ;
T_8 V_43 ;
F_154 (pt, pd, start, length, pde)
F_157 ( V_92 , V_43 , V_80 ) ;
F_155 ( V_186 -> V_187 ) ;
}
static T_8 F_160 ( struct V_108 * V_109 )
{
F_83 ( V_109 -> V_92 . V_4 . V_188 & 0x3f ) ;
return ( V_109 -> V_92 . V_4 . V_188 / 64 ) << 16 ;
}
static int F_161 ( struct V_108 * V_109 ,
struct V_113 * V_114 )
{
struct V_116 * V_117 = V_114 -> V_117 ;
int V_76 ;
V_76 = V_117 -> V_189 ( V_114 , V_190 , V_190 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_84 ( V_114 , 6 ) ;
if ( V_76 )
return V_76 ;
F_85 ( V_117 , F_86 ( 2 ) ) ;
F_87 ( V_117 , F_162 ( V_117 ) ) ;
F_85 ( V_117 , V_191 ) ;
F_87 ( V_117 , F_163 ( V_117 ) ) ;
F_85 ( V_117 , F_160 ( V_109 ) ) ;
F_85 ( V_117 , V_192 ) ;
F_92 ( V_117 ) ;
return 0 ;
}
static int F_164 ( struct V_108 * V_109 ,
struct V_113 * V_114 )
{
struct V_116 * V_117 = V_114 -> V_117 ;
int V_76 ;
V_76 = V_117 -> V_189 ( V_114 , V_190 , V_190 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_84 ( V_114 , 6 ) ;
if ( V_76 )
return V_76 ;
F_85 ( V_117 , F_86 ( 2 ) ) ;
F_87 ( V_117 , F_162 ( V_117 ) ) ;
F_85 ( V_117 , V_191 ) ;
F_87 ( V_117 , F_163 ( V_117 ) ) ;
F_85 ( V_117 , F_160 ( V_109 ) ) ;
F_85 ( V_117 , V_192 ) ;
F_92 ( V_117 ) ;
if ( V_117 -> V_193 != V_194 ) {
V_76 = V_117 -> V_189 ( V_114 , V_190 , V_190 ) ;
if ( V_76 )
return V_76 ;
}
return 0 ;
}
static int F_165 ( struct V_108 * V_109 ,
struct V_113 * V_114 )
{
struct V_116 * V_117 = V_114 -> V_117 ;
struct V_5 * V_6 = V_114 -> V_15 ;
F_116 ( F_162 ( V_117 ) , V_191 ) ;
F_116 ( F_163 ( V_117 ) , F_160 ( V_109 ) ) ;
return 0 ;
}
static void F_166 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_116 * V_117 ;
F_167 (engine, dev_priv) {
T_1 V_195 = F_72 ( V_58 ) ? V_196 : 0 ;
F_116 ( F_168 ( V_117 ) ,
F_169 ( V_197 | V_195 ) ) ;
}
}
static void F_170 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_116 * V_117 ;
T_8 V_198 , V_199 ;
V_199 = F_171 ( V_200 ) ;
F_116 ( V_200 , V_199 | V_201 ) ;
V_198 = F_171 ( V_202 ) ;
if ( F_172 ( V_58 ) ) {
V_198 |= V_203 ;
} else {
V_198 |= V_204 ;
V_198 &= ~ V_205 ;
}
F_116 ( V_202 , V_198 ) ;
F_167 (engine, dev_priv) {
F_116 ( F_168 ( V_117 ) ,
F_169 ( V_197 ) ) ;
}
}
static void F_173 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
T_8 V_198 , V_206 , V_199 ;
V_199 = F_171 ( V_200 ) ;
F_116 ( V_200 , V_199 | V_207 |
V_201 ) ;
V_206 = F_171 ( V_208 ) ;
F_116 ( V_208 , V_206 | V_209 ) ;
V_198 = F_171 ( V_202 ) ;
F_116 ( V_202 , V_198 | V_210 | V_211 ) ;
F_116 ( V_212 , F_169 ( V_197 ) ) ;
}
static void F_174 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_120 ,
bool V_127 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
T_5 * V_121 , V_88 ;
unsigned V_213 = V_29 >> V_124 ;
unsigned V_123 = V_120 >> V_124 ;
unsigned V_214 = V_213 / V_84 ;
unsigned V_215 = V_213 % V_84 ;
unsigned V_125 , V_71 ;
V_88 = V_3 -> V_90 ( F_61 ( V_3 -> V_89 ) ,
V_47 , true , 0 ) ;
while ( V_123 ) {
V_125 = V_215 + V_123 ;
if ( V_125 > V_84 )
V_125 = V_84 ;
V_121 = F_79 ( V_109 -> V_92 . V_126 [ V_214 ] ) ;
for ( V_71 = V_215 ; V_71 < V_125 ; V_71 ++ )
V_121 [ V_71 ] = V_88 ;
F_80 ( V_109 , V_121 ) ;
V_123 -= V_125 - V_215 ;
V_215 = 0 ;
V_214 ++ ;
}
}
static void F_175 ( struct V_2 * V_3 ,
struct V_131 * V_27 ,
T_7 V_29 ,
enum V_19 V_20 , T_1 V_51 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
unsigned V_213 = V_29 >> V_124 ;
unsigned V_214 = V_213 / V_84 ;
unsigned V_216 = V_213 % V_84 ;
T_5 * V_121 = NULL ;
struct V_217 V_217 ;
T_3 V_32 ;
F_176 (addr, sgt_iter, pages) {
if ( V_121 == NULL )
V_121 = F_79 ( V_109 -> V_92 . V_126 [ V_214 ] ) ;
V_121 [ V_216 ] =
V_3 -> V_90 ( V_32 , V_20 , true , V_51 ) ;
if ( ++ V_216 == V_84 ) {
F_80 ( V_109 , V_121 ) ;
V_121 = NULL ;
V_214 ++ ;
V_216 = 0 ;
}
}
if ( V_121 )
F_80 ( V_109 , V_121 ) ;
}
static int F_177 ( struct V_2 * V_3 ,
T_7 V_218 , T_7 V_219 )
{
F_141 ( V_161 , V_94 ) ;
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
struct V_108 * V_109 = F_97 ( V_3 ) ;
struct V_79 * V_80 ;
T_8 V_29 , V_120 , V_220 , V_221 ;
T_8 V_43 ;
int V_76 ;
if ( F_33 ( V_218 + V_219 > V_109 -> V_4 . V_165 ) )
return - V_164 ;
V_29 = V_220 = V_218 ;
V_120 = V_221 = V_219 ;
F_142 ( V_161 , V_94 ) ;
F_154 (pt, &ppgtt->pd, start, length, pde) {
if ( V_80 != V_3 -> V_96 ) {
F_33 ( F_128 ( V_80 -> V_85 , V_84 ) ) ;
continue;
}
F_33 ( ! F_128 ( V_80 -> V_85 , V_84 ) ) ;
V_80 = F_54 ( V_58 ) ;
if ( F_112 ( V_80 ) ) {
V_76 = F_113 ( V_80 ) ;
goto V_146;
}
F_63 ( V_3 , V_80 ) ;
V_109 -> V_92 . V_126 [ V_43 ] = V_80 ;
F_125 ( V_43 , V_161 ) ;
F_126 ( V_3 , V_43 , V_29 , V_222 ) ;
}
V_29 = V_220 ;
V_120 = V_221 ;
F_154 (pt, &ppgtt->pd, start, length, pde) {
F_141 ( V_223 , V_84 ) ;
F_142 ( V_223 , V_84 ) ;
F_138 ( V_223 , F_178 ( V_29 ) ,
F_179 ( V_29 , V_120 ) ) ;
if ( F_180 ( V_43 , V_161 ) )
F_157 ( & V_109 -> V_92 , V_43 , V_80 ) ;
F_139 ( V_3 , V_43 , V_80 ,
F_178 ( V_29 ) ,
F_179 ( V_29 , V_120 ) ,
V_84 ) ;
F_145 ( V_80 -> V_85 , V_223 , V_80 -> V_85 ,
V_84 ) ;
}
F_33 ( ! F_128 ( V_161 , V_94 ) ) ;
F_155 ( V_186 -> V_187 ) ;
F_135 ( V_109 ) ;
return 0 ;
V_146:
F_110 (pde, new_page_tables, I915_PDES) {
struct V_79 * V_80 = V_109 -> V_92 . V_126 [ V_43 ] ;
V_109 -> V_92 . V_126 [ V_43 ] = V_3 -> V_96 ;
F_59 ( V_3 -> V_58 , V_80 ) ;
}
F_135 ( V_109 ) ;
return V_76 ;
}
static int F_181 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
V_3 -> V_89 = F_44 ( V_58 ) ;
if ( F_112 ( V_3 -> V_89 ) )
return F_113 ( V_3 -> V_89 ) ;
V_3 -> V_96 = F_54 ( V_58 ) ;
if ( F_112 ( V_3 -> V_96 ) ) {
F_51 ( V_58 , V_3 -> V_89 ) ;
return F_113 ( V_3 -> V_96 ) ;
}
F_63 ( V_3 , V_3 -> V_96 ) ;
return 0 ;
}
static void F_182 ( struct V_2 * V_3 )
{
struct V_57 * V_58 = V_3 -> V_58 ;
F_59 ( V_58 , V_3 -> V_96 ) ;
F_51 ( V_58 , V_3 -> V_89 ) ;
}
static void F_183 ( struct V_2 * V_3 )
{
struct V_108 * V_109 = F_97 ( V_3 ) ;
struct V_91 * V_92 = & V_109 -> V_92 ;
struct V_57 * V_58 = V_3 -> V_58 ;
struct V_79 * V_80 ;
T_8 V_43 ;
F_184 ( & V_109 -> V_28 ) ;
F_185 (pt, pd, pde)
if ( V_80 != V_3 -> V_96 )
F_59 ( V_58 , V_80 ) ;
F_182 ( V_3 ) ;
}
static int F_186 ( struct V_108 * V_109 )
{
struct V_2 * V_3 = & V_109 -> V_4 ;
struct V_57 * V_58 = V_109 -> V_4 . V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
bool V_224 = false ;
int V_76 ;
F_83 ( ! F_187 ( & V_186 -> V_4 . V_225 ) ) ;
V_76 = F_181 ( V_3 ) ;
if ( V_76 )
return V_76 ;
V_226:
V_76 = F_188 ( & V_186 -> V_4 . V_225 ,
& V_109 -> V_28 , V_227 ,
V_228 , 0 ,
0 , V_186 -> V_4 . V_165 ,
V_229 ) ;
if ( V_76 == - V_230 && ! V_224 ) {
V_76 = F_189 ( V_58 , & V_186 -> V_4 ,
V_227 , V_228 ,
V_38 ,
0 , V_186 -> V_4 . V_165 ,
0 ) ;
if ( V_76 )
goto V_157;
V_224 = true ;
goto V_226;
}
if ( V_76 )
goto V_157;
if ( V_109 -> V_28 . V_29 < V_186 -> V_231 )
F_190 ( L_15 ) ;
return 0 ;
V_157:
F_182 ( V_3 ) ;
return V_76 ;
}
static int F_191 ( struct V_108 * V_109 )
{
return F_186 ( V_109 ) ;
}
static void F_192 ( struct V_108 * V_109 ,
T_7 V_29 , T_7 V_120 )
{
struct V_79 * V_21 ;
T_8 V_43 ;
F_154 (unused, &ppgtt->pd, start, length, pde)
V_109 -> V_92 . V_126 [ V_43 ] = V_109 -> V_4 . V_96 ;
}
static int F_193 ( struct V_108 * V_109 )
{
struct V_57 * V_58 = V_109 -> V_4 . V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
int V_76 ;
V_109 -> V_4 . V_90 = V_186 -> V_4 . V_90 ;
if ( F_8 ( V_6 ) || F_10 ( V_58 ) )
V_109 -> V_180 = F_165 ;
else if ( F_172 ( V_58 ) )
V_109 -> V_180 = F_161 ;
else if ( F_194 ( V_58 ) )
V_109 -> V_180 = F_164 ;
else
F_195 () ;
V_76 = F_191 ( V_109 ) ;
if ( V_76 )
return V_76 ;
V_109 -> V_4 . V_175 = F_177 ;
V_109 -> V_4 . V_30 = F_174 ;
V_109 -> V_4 . V_26 = F_175 ;
V_109 -> V_4 . V_176 = F_15 ;
V_109 -> V_4 . V_177 = F_14 ;
V_109 -> V_4 . V_174 = F_183 ;
V_109 -> V_4 . V_29 = 0 ;
V_109 -> V_4 . V_165 = V_94 * V_84 * V_69 ;
V_109 -> V_178 = F_153 ;
V_109 -> V_92 . V_4 . V_188 =
V_109 -> V_28 . V_29 / V_69 * sizeof( T_5 ) ;
V_109 -> V_184 = ( T_5 V_232 * ) V_186 -> V_187 +
V_109 -> V_92 . V_4 . V_188 / sizeof( T_5 ) ;
F_192 ( V_109 , 0 , V_109 -> V_4 . V_165 ) ;
F_159 ( V_6 , & V_109 -> V_92 , 0 , V_109 -> V_4 . V_165 ) ;
F_13 ( L_16 ,
V_109 -> V_28 . V_31 >> 20 ,
V_109 -> V_28 . V_29 / V_69 ) ;
F_190 ( L_17 ,
V_109 -> V_92 . V_4 . V_188 << 10 ) ;
return 0 ;
}
static int F_196 ( struct V_57 * V_58 , struct V_108 * V_109 )
{
V_109 -> V_4 . V_58 = V_58 ;
if ( F_55 ( V_58 ) -> V_82 < 8 )
return F_193 ( V_109 ) ;
else
return F_152 ( V_109 ) ;
}
static void F_197 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
F_198 ( & V_3 -> V_225 , V_3 -> V_29 , V_3 -> V_165 ) ;
V_3 -> V_58 = & V_6 -> V_12 ;
F_199 ( & V_3 -> V_233 ) ;
F_199 ( & V_3 -> V_234 ) ;
F_200 ( & V_3 -> V_235 , & V_6 -> V_236 ) ;
}
static void F_201 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
if ( F_7 ( V_58 ) )
F_116 ( V_237 , V_238 ) ;
else if ( F_38 ( V_58 ) )
F_116 ( V_237 , V_239 ) ;
else if ( F_202 ( V_58 ) )
F_116 ( V_237 , V_240 ) ;
else if ( F_39 ( V_58 ) )
F_116 ( V_237 , V_241 ) ;
}
static int F_203 ( struct V_57 * V_58 , struct V_108 * V_109 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
int V_76 = 0 ;
V_76 = F_196 ( V_58 , V_109 ) ;
if ( V_76 == 0 ) {
F_204 ( & V_109 -> V_242 ) ;
F_197 ( & V_109 -> V_4 , V_6 ) ;
}
return V_76 ;
}
int F_205 ( struct V_57 * V_58 )
{
F_201 ( V_58 ) ;
if ( V_15 . V_16 )
return 0 ;
if ( ! F_206 ( V_58 ) )
return 0 ;
if ( F_10 ( V_58 ) )
F_173 ( V_58 ) ;
else if ( F_194 ( V_58 ) )
F_170 ( V_58 ) ;
else if ( F_55 ( V_58 ) -> V_82 >= 8 )
F_166 ( V_58 ) ;
else
F_20 ( F_55 ( V_58 ) -> V_82 ) ;
return 0 ;
}
struct V_108 *
F_207 ( struct V_57 * V_58 , struct V_243 * V_244 )
{
struct V_108 * V_109 ;
int V_76 ;
V_109 = F_45 ( sizeof( * V_109 ) , V_67 ) ;
if ( ! V_109 )
return F_46 ( - V_63 ) ;
V_76 = F_203 ( V_58 , V_109 ) ;
if ( V_76 ) {
F_48 ( V_109 ) ;
return F_46 ( V_76 ) ;
}
V_109 -> V_245 = V_244 ;
F_208 ( & V_109 -> V_4 ) ;
return V_109 ;
}
void F_209 ( struct V_246 * V_246 )
{
struct V_108 * V_109 =
F_4 ( V_246 , struct V_108 , V_242 ) ;
F_210 ( & V_109 -> V_4 ) ;
F_33 ( ! F_211 ( & V_109 -> V_4 . V_233 ) ) ;
F_33 ( ! F_211 ( & V_109 -> V_4 . V_234 ) ) ;
F_212 ( & V_109 -> V_4 . V_235 ) ;
F_213 ( & V_109 -> V_4 . V_225 ) ;
V_109 -> V_4 . V_174 ( & V_109 -> V_4 ) ;
F_48 ( V_109 ) ;
}
static bool F_214 ( struct V_57 * V_58 )
{
#ifdef F_9
if ( F_215 ( V_58 ) && F_216 ( V_58 ) && V_11 )
return true ;
#endif
return false ;
}
static bool F_217 ( struct V_5 * V_6 )
{
struct V_1 * V_186 = & V_6 -> V_186 ;
bool V_76 = V_6 -> V_225 . V_247 ;
if ( F_218 ( V_186 -> V_248 ) ) {
V_6 -> V_225 . V_247 = false ;
if ( F_219 ( V_6 ) ) {
F_220 ( L_18 ) ;
F_221 ( 10 ) ;
}
}
return V_76 ;
}
static void F_222 ( struct V_5 * V_6 , bool V_247 )
{
struct V_1 * V_186 = & V_6 -> V_186 ;
if ( F_218 ( V_186 -> V_248 ) )
V_6 -> V_225 . V_247 = V_247 ;
}
void F_223 ( struct V_5 * V_6 )
{
struct V_116 * V_117 ;
if ( F_55 ( V_6 ) -> V_82 < 6 )
return;
F_167 (engine, dev_priv) {
T_1 V_249 ;
V_249 = F_171 ( F_224 ( V_117 ) ) ;
if ( V_249 & V_250 ) {
F_13 ( L_19
L_20
L_21
L_22
L_23 ,
V_249 & V_251 ,
V_249 & V_252 ? L_24 : L_25 ,
F_225 ( V_249 ) ,
F_226 ( V_249 ) ) ;
F_116 ( F_224 ( V_117 ) ,
V_249 & ~ V_250 ) ;
}
}
F_227 ( F_224 ( & V_6 -> V_117 [ V_194 ] ) ) ;
}
static void F_228 ( struct V_5 * V_6 )
{
if ( F_55 ( V_6 ) -> V_82 < 6 ) {
F_229 () ;
} else {
F_116 ( V_253 , V_254 ) ;
F_227 ( V_253 ) ;
}
}
void F_230 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
if ( F_55 ( V_58 ) -> V_82 < 6 )
return;
F_223 ( V_6 ) ;
V_186 -> V_4 . V_30 ( & V_186 -> V_4 , V_186 -> V_4 . V_29 , V_186 -> V_4 . V_165 ,
true ) ;
F_228 ( V_6 ) ;
}
int F_231 ( struct V_255 * V_23 )
{
if ( ! F_232 ( & V_23 -> V_4 . V_58 -> V_13 -> V_58 ,
V_23 -> V_27 -> V_132 , V_23 -> V_27 -> V_256 ,
V_65 ) )
return - V_230 ;
return 0 ;
}
static void F_233 ( void V_232 * V_32 , T_2 V_35 )
{
#ifdef F_234
F_234 ( V_35 , V_32 ) ;
#else
F_235 ( ( T_1 ) V_35 , V_32 ) ;
F_235 ( V_35 >> 32 , V_32 + 4 ) ;
#endif
}
static void F_236 ( struct V_2 * V_3 ,
T_3 V_32 ,
T_7 V_257 ,
enum V_19 V_33 ,
T_1 V_21 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
T_2 V_232 * V_35 =
( T_2 V_232 * ) V_6 -> V_186 . V_187 +
( V_257 >> V_124 ) ;
int V_258 ;
V_258 = F_237 ( V_6 ) ;
F_233 ( V_35 , F_16 ( V_32 , V_33 , true ) ) ;
F_116 ( V_253 , V_254 ) ;
F_227 ( V_253 ) ;
F_238 ( V_6 , V_258 ) ;
}
static void F_239 ( struct V_2 * V_3 ,
struct V_131 * V_259 ,
T_7 V_29 ,
enum V_19 V_33 , T_1 V_21 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
struct V_1 * V_186 = F_1 ( V_3 ) ;
struct V_217 V_217 ;
T_2 V_232 * V_260 ;
T_2 V_261 ;
T_3 V_32 ;
int V_258 ;
int V_71 = 0 ;
V_258 = F_237 ( V_6 ) ;
V_260 = ( T_2 V_232 * ) V_186 -> V_187 + ( V_29 >> V_124 ) ;
F_176 (addr, sgt_iter, st) {
V_261 = F_16 ( V_32 , V_33 , true ) ;
F_233 ( & V_260 [ V_71 ++ ] , V_261 ) ;
}
if ( V_71 != 0 )
F_33 ( F_240 ( & V_260 [ V_71 - 1 ] ) != V_261 ) ;
F_116 ( V_253 , V_254 ) ;
F_227 ( V_253 ) ;
F_238 ( V_6 , V_258 ) ;
}
static int F_241 ( void * V_262 )
{
struct V_26 * V_263 = V_262 ;
F_239 ( V_263 -> V_3 , V_263 -> V_259 ,
V_263 -> V_29 , V_263 -> V_33 , V_263 -> V_51 ) ;
return 0 ;
}
static void F_242 ( struct V_2 * V_3 ,
struct V_131 * V_259 ,
T_7 V_29 ,
enum V_19 V_33 ,
T_1 V_51 )
{
struct V_26 V_263 = { V_3 , V_259 , V_29 , V_33 , V_51 } ;
F_243 ( F_241 , & V_263 , NULL ) ;
}
static void F_244 ( struct V_2 * V_3 ,
T_3 V_32 ,
T_7 V_257 ,
enum V_19 V_33 ,
T_1 V_51 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
T_5 V_232 * V_35 =
( T_5 V_232 * ) V_6 -> V_186 . V_187 +
( V_257 >> V_124 ) ;
int V_258 ;
V_258 = F_237 ( V_6 ) ;
F_235 ( V_3 -> V_90 ( V_32 , V_33 , true , V_51 ) , V_35 ) ;
F_116 ( V_253 , V_254 ) ;
F_227 ( V_253 ) ;
F_238 ( V_6 , V_258 ) ;
}
static void F_245 ( struct V_2 * V_3 ,
struct V_131 * V_259 ,
T_7 V_29 ,
enum V_19 V_33 , T_1 V_51 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
struct V_1 * V_186 = F_1 ( V_3 ) ;
struct V_217 V_217 ;
T_5 V_232 * V_260 ;
T_5 V_261 ;
T_3 V_32 ;
int V_258 ;
int V_71 = 0 ;
V_258 = F_237 ( V_6 ) ;
V_260 = ( T_5 V_232 * ) V_186 -> V_187 + ( V_29 >> V_124 ) ;
F_176 (addr, sgt_iter, st) {
V_261 = V_3 -> V_90 ( V_32 , V_33 , true , V_51 ) ;
F_235 ( V_261 , & V_260 [ V_71 ++ ] ) ;
}
if ( V_71 != 0 )
F_33 ( F_155 ( & V_260 [ V_71 - 1 ] ) != V_261 ) ;
F_116 ( V_253 , V_254 ) ;
F_227 ( V_253 ) ;
F_238 ( V_6 , V_258 ) ;
}
static void F_246 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_120 ,
bool V_127 )
{
}
static void F_247 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_120 ,
bool V_127 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
struct V_1 * V_186 = F_1 ( V_3 ) ;
unsigned V_213 = V_29 >> V_124 ;
unsigned V_123 = V_120 >> V_124 ;
T_2 V_88 , V_232 * V_264 =
( T_2 V_232 * ) V_186 -> V_187 + V_213 ;
const int V_265 = F_248 ( V_186 ) - V_213 ;
int V_71 ;
int V_258 ;
V_258 = F_237 ( V_6 ) ;
if ( F_143 ( V_123 > V_265 ,
L_26 ,
V_213 , V_123 , V_265 ) )
V_123 = V_265 ;
V_88 = F_16 ( F_61 ( V_3 -> V_89 ) ,
V_47 ,
V_127 ) ;
for ( V_71 = 0 ; V_71 < V_123 ; V_71 ++ )
F_233 ( & V_264 [ V_71 ] , V_88 ) ;
F_155 ( V_264 ) ;
F_238 ( V_6 , V_258 ) ;
}
static void F_249 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_120 ,
bool V_127 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
struct V_1 * V_186 = F_1 ( V_3 ) ;
unsigned V_213 = V_29 >> V_124 ;
unsigned V_123 = V_120 >> V_124 ;
T_5 V_88 , V_232 * V_264 =
( T_5 V_232 * ) V_186 -> V_187 + V_213 ;
const int V_265 = F_248 ( V_186 ) - V_213 ;
int V_71 ;
int V_258 ;
V_258 = F_237 ( V_6 ) ;
if ( F_143 ( V_123 > V_265 ,
L_26 ,
V_213 , V_123 , V_265 ) )
V_123 = V_265 ;
V_88 = V_3 -> V_90 ( F_61 ( V_3 -> V_89 ) ,
V_47 , V_127 , 0 ) ;
for ( V_71 = 0 ; V_71 < V_123 ; V_71 ++ )
F_235 ( V_88 , & V_264 [ V_71 ] ) ;
F_155 ( V_264 ) ;
F_238 ( V_6 , V_258 ) ;
}
static void F_250 ( struct V_2 * V_3 ,
T_3 V_32 ,
T_7 V_257 ,
enum V_19 V_20 ,
T_1 V_21 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
unsigned int V_51 = ( V_20 == V_38 ) ?
V_266 : V_267 ;
int V_258 ;
V_258 = F_237 ( V_6 ) ;
F_251 ( V_32 , V_257 >> V_124 , V_51 ) ;
F_238 ( V_6 , V_258 ) ;
}
static void F_252 ( struct V_2 * V_3 ,
struct V_131 * V_27 ,
T_7 V_29 ,
enum V_19 V_20 , T_1 V_21 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
unsigned int V_51 = ( V_20 == V_38 ) ?
V_266 : V_267 ;
int V_258 ;
V_258 = F_237 ( V_6 ) ;
F_253 ( V_27 , V_29 >> V_124 , V_51 ) ;
F_238 ( V_6 , V_258 ) ;
}
static void F_254 ( struct V_2 * V_3 ,
T_7 V_29 ,
T_7 V_120 ,
bool V_21 )
{
struct V_5 * V_6 = F_115 ( V_3 -> V_58 ) ;
unsigned V_213 = V_29 >> V_124 ;
unsigned V_123 = V_120 >> V_124 ;
int V_258 ;
V_258 = F_237 ( V_6 ) ;
F_255 ( V_213 , V_123 ) ;
F_238 ( V_6 , V_258 ) ;
}
static int F_256 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
T_1 V_51 )
{
struct V_255 * V_23 = V_18 -> V_23 ;
T_1 V_22 = 0 ;
int V_76 ;
V_76 = F_257 ( V_18 ) ;
if ( V_76 )
return V_76 ;
if ( V_23 -> V_24 )
V_22 |= V_25 ;
V_18 -> V_3 -> V_26 ( V_18 -> V_3 , V_18 -> V_268 . V_27 ,
V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
V_18 -> V_269 |= V_270 | V_271 ;
return 0 ;
}
static int F_258 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
T_1 V_51 )
{
T_1 V_22 ;
int V_76 ;
V_76 = F_257 ( V_18 ) ;
if ( V_76 )
return V_76 ;
V_22 = 0 ;
if ( V_18 -> V_23 -> V_24 )
V_22 |= V_25 ;
if ( V_51 & V_270 ) {
V_18 -> V_3 -> V_26 ( V_18 -> V_3 ,
V_18 -> V_268 . V_27 ,
V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
}
if ( V_51 & V_271 ) {
struct V_108 * V_272 =
F_115 ( V_18 -> V_3 -> V_58 ) -> V_225 . V_273 ;
V_272 -> V_4 . V_26 ( & V_272 -> V_4 ,
V_18 -> V_268 . V_27 ,
V_18 -> V_28 . V_29 ,
V_20 , V_22 ) ;
}
return 0 ;
}
static void F_259 ( struct V_17 * V_18 )
{
struct V_57 * V_58 = V_18 -> V_3 -> V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_255 * V_23 = V_18 -> V_23 ;
const T_7 V_31 = F_260 ( T_7 ,
V_23 -> V_4 . V_31 ,
V_18 -> V_28 . V_31 ) ;
if ( V_18 -> V_269 & V_270 ) {
V_18 -> V_3 -> V_30 ( V_18 -> V_3 ,
V_18 -> V_28 . V_29 ,
V_31 ,
true ) ;
}
if ( V_6 -> V_225 . V_273 && V_18 -> V_269 & V_271 ) {
struct V_108 * V_272 = V_6 -> V_225 . V_273 ;
V_272 -> V_4 . V_30 ( & V_272 -> V_4 ,
V_18 -> V_28 . V_29 ,
V_31 ,
true ) ;
}
}
void F_261 ( struct V_255 * V_23 )
{
struct V_57 * V_58 = V_23 -> V_4 . V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
bool V_247 ;
V_247 = F_217 ( V_6 ) ;
F_262 ( & V_58 -> V_13 -> V_58 , V_23 -> V_27 -> V_132 , V_23 -> V_27 -> V_256 ,
V_65 ) ;
F_222 ( V_6 , V_247 ) ;
}
static void F_263 ( struct V_274 * V_28 ,
unsigned long V_275 ,
T_12 * V_29 ,
T_12 * V_276 )
{
if ( V_28 -> V_275 != V_275 )
* V_29 += 4096 ;
if ( ! F_211 ( & V_28 -> V_277 ) ) {
V_28 = F_264 ( V_28 -> V_277 . V_278 ,
struct V_274 ,
V_277 ) ;
if ( V_28 -> V_279 && V_28 -> V_275 != V_275 )
* V_276 -= 4096 ;
}
}
static int F_265 ( struct V_57 * V_58 ,
T_12 V_29 ,
T_12 V_231 ,
T_12 V_276 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
struct V_274 * V_115 ;
struct V_255 * V_23 ;
unsigned long V_280 , V_281 ;
int V_76 ;
F_83 ( V_231 > V_276 ) ;
V_186 -> V_4 . V_29 = V_29 ;
V_186 -> V_4 . V_165 = V_276 - V_29 - V_69 ;
F_197 ( & V_186 -> V_4 , V_6 ) ;
V_186 -> V_4 . V_165 += V_69 ;
V_76 = F_266 ( V_6 ) ;
if ( V_76 )
return V_76 ;
if ( ! F_267 ( V_58 ) )
V_186 -> V_4 . V_225 . V_282 = F_263 ;
F_268 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_17 * V_18 = F_269 ( V_23 , & V_186 -> V_4 ) ;
F_270 ( L_27 ,
F_271 ( V_23 ) , V_23 -> V_4 . V_31 ) ;
F_33 ( F_272 ( V_23 ) ) ;
V_76 = F_273 ( & V_186 -> V_4 . V_225 , & V_18 -> V_28 ) ;
if ( V_76 ) {
F_270 ( L_28 , V_76 ) ;
return V_76 ;
}
V_18 -> V_269 |= V_270 ;
F_274 ( V_18 ) ;
F_200 ( & V_18 -> V_283 , & V_186 -> V_4 . V_234 ) ;
}
F_275 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_270 ( L_29 ,
V_280 , V_281 ) ;
V_186 -> V_4 . V_30 ( & V_186 -> V_4 , V_280 ,
V_281 - V_280 , true ) ;
}
V_186 -> V_4 . V_30 ( & V_186 -> V_4 , V_276 - V_69 , V_69 , true ) ;
if ( F_206 ( V_58 ) && ! F_276 ( V_58 ) ) {
struct V_108 * V_109 ;
V_109 = F_45 ( sizeof( * V_109 ) , V_67 ) ;
if ( ! V_109 )
return - V_63 ;
V_76 = F_196 ( V_58 , V_109 ) ;
if ( V_76 ) {
V_109 -> V_4 . V_174 ( & V_109 -> V_4 ) ;
F_48 ( V_109 ) ;
return V_76 ;
}
if ( V_109 -> V_4 . V_175 )
V_76 = V_109 -> V_4 . V_175 ( & V_109 -> V_4 , 0 ,
V_109 -> V_4 . V_165 ) ;
if ( V_76 ) {
V_109 -> V_4 . V_174 ( & V_109 -> V_4 ) ;
F_48 ( V_109 ) ;
return V_76 ;
}
V_109 -> V_4 . V_30 ( & V_109 -> V_4 ,
V_109 -> V_4 . V_29 ,
V_109 -> V_4 . V_165 ,
true ) ;
V_6 -> V_225 . V_273 = V_109 ;
F_33 ( V_186 -> V_4 . V_177 != F_256 ) ;
V_186 -> V_4 . V_177 = F_258 ;
}
return 0 ;
}
void F_277 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
F_265 ( V_58 , 0 , V_186 -> V_231 , V_186 -> V_4 . V_165 ) ;
}
void F_278 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
if ( V_6 -> V_225 . V_273 ) {
struct V_108 * V_109 = V_6 -> V_225 . V_273 ;
V_109 -> V_4 . V_174 ( & V_109 -> V_4 ) ;
F_48 ( V_109 ) ;
}
F_279 ( V_58 ) ;
if ( F_187 ( & V_186 -> V_4 . V_225 ) ) {
F_280 ( V_6 ) ;
F_213 ( & V_186 -> V_4 . V_225 ) ;
F_212 ( & V_186 -> V_4 . V_235 ) ;
}
V_186 -> V_4 . V_174 ( & V_186 -> V_4 ) ;
}
static unsigned int F_281 ( T_14 V_284 )
{
V_284 >>= V_285 ;
V_284 &= V_286 ;
return V_284 << 20 ;
}
static unsigned int F_282 ( T_14 V_287 )
{
V_287 >>= V_288 ;
V_287 &= V_289 ;
if ( V_287 )
V_287 = 1 << V_287 ;
#ifdef F_283
if ( V_287 > 4 )
V_287 = 4 ;
#endif
return V_287 << 20 ;
}
static unsigned int F_284 ( T_14 V_290 )
{
V_290 >>= V_285 ;
V_290 &= V_286 ;
if ( V_290 )
return 1 << ( 20 + V_290 ) ;
return 0 ;
}
static T_9 F_285 ( T_14 V_284 )
{
V_284 >>= V_291 ;
V_284 &= V_292 ;
return V_284 << 25 ;
}
static T_9 F_286 ( T_14 V_287 )
{
V_287 >>= V_293 ;
V_287 &= V_294 ;
return V_287 << 25 ;
}
static T_9 F_287 ( T_14 V_290 )
{
V_290 >>= V_291 ;
V_290 &= V_292 ;
if ( V_290 < 0x11 )
return V_290 << 25 ;
else if ( V_290 < 0x17 )
return ( V_290 - 0x11 + 2 ) << 22 ;
else
return ( V_290 - 0x17 + 9 ) << 22 ;
}
static T_9 F_288 ( T_14 V_295 )
{
V_295 >>= V_293 ;
V_295 &= V_294 ;
if ( V_295 < 0xf0 )
return V_295 << 25 ;
else
return ( V_295 - 0xf0 + 1 ) << 22 ;
}
static int F_289 ( struct V_57 * V_58 ,
T_9 V_296 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
struct V_74 * V_89 ;
T_15 V_297 ;
V_297 = F_290 ( V_58 -> V_13 , 0 ) +
( F_291 ( V_58 -> V_13 , 0 ) / 2 ) ;
if ( F_39 ( V_58 ) )
V_186 -> V_187 = F_292 ( V_297 , V_296 ) ;
else
V_186 -> V_187 = F_293 ( V_297 , V_296 ) ;
if ( ! V_186 -> V_187 ) {
F_220 ( L_30 ) ;
return - V_63 ;
}
V_89 = F_44 ( V_58 ) ;
if ( F_112 ( V_89 ) ) {
F_220 ( L_31 ) ;
F_294 ( V_186 -> V_187 ) ;
return F_113 ( V_89 ) ;
}
V_186 -> V_4 . V_89 = V_89 ;
return 0 ;
}
static void F_295 ( struct V_5 * V_6 )
{
T_7 V_298 ;
V_298 = F_296 ( 0 , V_299 | V_300 ) |
F_296 ( 1 , V_301 | V_302 ) |
F_296 ( 2 , V_303 | V_302 ) |
F_296 ( 3 , V_304 ) |
F_296 ( 4 , V_299 | V_302 | F_297 ( 0 ) ) |
F_296 ( 5 , V_299 | V_302 | F_297 ( 1 ) ) |
F_296 ( 6 , V_299 | V_302 | F_297 ( 2 ) ) |
F_296 ( 7 , V_299 | V_302 | F_297 ( 3 ) ) ;
if ( ! F_206 ( V_6 ) )
V_298 = F_296 ( 0 , V_304 ) ;
F_116 ( V_305 , V_298 ) ;
F_116 ( V_306 , V_298 >> 32 ) ;
}
static void F_298 ( struct V_5 * V_6 )
{
T_7 V_298 ;
V_298 = F_296 ( 0 , V_307 ) |
F_296 ( 1 , 0 ) |
F_296 ( 2 , 0 ) |
F_296 ( 3 , 0 ) |
F_296 ( 4 , V_307 ) |
F_296 ( 5 , V_307 ) |
F_296 ( 6 , V_307 ) |
F_296 ( 7 , V_307 ) ;
F_116 ( V_305 , V_298 ) ;
F_116 ( V_306 , V_298 >> 32 ) ;
}
static int F_299 ( struct V_1 * V_186 )
{
struct V_57 * V_58 = V_186 -> V_4 . V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
T_14 V_284 ;
int V_76 ;
V_186 -> V_308 = F_290 ( V_58 -> V_13 , 2 ) ;
V_186 -> V_231 = F_291 ( V_58 -> V_13 , 2 ) ;
if ( ! F_300 ( V_58 -> V_13 , F_301 ( 39 ) ) )
F_302 ( V_58 -> V_13 , F_301 ( 39 ) ) ;
F_303 ( V_58 -> V_13 , V_309 , & V_284 ) ;
if ( F_55 ( V_58 ) -> V_82 >= 9 ) {
V_186 -> V_310 = F_288 ( V_284 ) ;
V_186 -> V_31 = F_282 ( V_284 ) ;
} else if ( F_38 ( V_58 ) ) {
V_186 -> V_310 = F_287 ( V_284 ) ;
V_186 -> V_31 = F_284 ( V_284 ) ;
} else {
V_186 -> V_310 = F_286 ( V_284 ) ;
V_186 -> V_31 = F_282 ( V_284 ) ;
}
V_186 -> V_4 . V_165 = ( V_186 -> V_31 / sizeof( T_2 ) ) << V_124 ;
if ( F_38 ( V_58 ) || F_39 ( V_58 ) )
F_298 ( V_6 ) ;
else
F_295 ( V_6 ) ;
V_76 = F_289 ( V_58 , V_186 -> V_31 ) ;
V_186 -> V_4 . V_177 = F_256 ;
V_186 -> V_4 . V_176 = F_259 ;
V_186 -> V_4 . V_311 = F_236 ;
V_186 -> V_4 . V_30 = F_246 ;
if ( ! F_276 ( V_6 ) || F_304 ( V_6 ) )
V_186 -> V_4 . V_30 = F_247 ;
V_186 -> V_4 . V_26 = F_239 ;
if ( F_38 ( V_6 ) )
V_186 -> V_4 . V_26 = F_242 ;
return V_76 ;
}
static int F_305 ( struct V_1 * V_186 )
{
struct V_57 * V_58 = V_186 -> V_4 . V_58 ;
T_14 V_284 ;
int V_76 ;
V_186 -> V_308 = F_290 ( V_58 -> V_13 , 2 ) ;
V_186 -> V_231 = F_291 ( V_58 -> V_13 , 2 ) ;
if ( ( V_186 -> V_231 < ( 64 << 20 ) || ( V_186 -> V_231 > ( 512 << 20 ) ) ) ) {
F_220 ( L_32 , V_186 -> V_231 ) ;
return - V_312 ;
}
if ( ! F_300 ( V_58 -> V_13 , F_301 ( 40 ) ) )
F_302 ( V_58 -> V_13 , F_301 ( 40 ) ) ;
F_303 ( V_58 -> V_13 , V_309 , & V_284 ) ;
V_186 -> V_310 = F_285 ( V_284 ) ;
V_186 -> V_31 = F_281 ( V_284 ) ;
V_186 -> V_4 . V_165 = ( V_186 -> V_31 / sizeof( T_5 ) ) << V_124 ;
V_76 = F_289 ( V_58 , V_186 -> V_31 ) ;
V_186 -> V_4 . V_30 = F_249 ;
V_186 -> V_4 . V_311 = F_244 ;
V_186 -> V_4 . V_26 = F_245 ;
V_186 -> V_4 . V_177 = F_256 ;
V_186 -> V_4 . V_176 = F_259 ;
return V_76 ;
}
static void F_306 ( struct V_2 * V_3 )
{
struct V_1 * V_186 = F_4 ( V_3 , struct V_1 , V_4 ) ;
F_294 ( V_186 -> V_187 ) ;
F_51 ( V_3 -> V_58 , V_3 -> V_89 ) ;
}
static int F_307 ( struct V_1 * V_186 )
{
struct V_57 * V_58 = V_186 -> V_4 . V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
int V_76 ;
V_76 = F_308 ( V_6 -> V_313 , V_6 -> V_12 . V_13 , NULL ) ;
if ( ! V_76 ) {
F_220 ( L_33 ) ;
return - V_314 ;
}
F_309 ( & V_186 -> V_4 . V_165 , & V_186 -> V_310 ,
& V_186 -> V_308 , & V_186 -> V_231 ) ;
V_186 -> V_248 = F_214 ( & V_6 -> V_12 ) ;
V_186 -> V_4 . V_311 = F_250 ;
V_186 -> V_4 . V_26 = F_252 ;
V_186 -> V_4 . V_30 = F_254 ;
V_186 -> V_4 . V_177 = F_256 ;
V_186 -> V_4 . V_176 = F_259 ;
if ( F_218 ( V_186 -> V_248 ) )
F_11 ( L_34 ) ;
return 0 ;
}
static void F_310 ( struct V_2 * V_3 )
{
F_311 () ;
}
int F_312 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
int V_76 ;
if ( F_55 ( V_58 ) -> V_82 <= 5 ) {
V_186 -> V_315 = F_307 ;
V_186 -> V_4 . V_174 = F_310 ;
} else if ( F_55 ( V_58 ) -> V_82 < 8 ) {
V_186 -> V_315 = F_305 ;
V_186 -> V_4 . V_174 = F_306 ;
if ( F_313 ( V_58 ) )
V_186 -> V_4 . V_90 = F_25 ;
else if ( F_172 ( V_58 ) )
V_186 -> V_4 . V_90 = F_23 ;
else if ( F_12 ( V_58 ) )
V_186 -> V_4 . V_90 = F_22 ;
else if ( F_55 ( V_58 ) -> V_82 >= 7 )
V_186 -> V_4 . V_90 = F_21 ;
else
V_186 -> V_4 . V_90 = F_18 ;
} else {
V_186 -> V_315 = F_299 ;
V_186 -> V_4 . V_174 = F_306 ;
}
V_186 -> V_4 . V_58 = V_58 ;
V_186 -> V_4 . V_316 = true ;
V_76 = V_186 -> V_315 ( V_186 ) ;
if ( V_76 )
return V_76 ;
if ( ( V_186 -> V_4 . V_165 - 1 ) >> 32 ) {
F_220 ( L_35
L_36 ,
V_186 -> V_4 . V_165 >> 20 ) ;
V_186 -> V_4 . V_165 = 1ULL << 32 ;
V_186 -> V_231 = F_314 ( V_186 -> V_231 , V_186 -> V_4 . V_165 ) ;
}
V_76 = F_315 ( V_58 ) ;
if ( V_76 )
goto V_317;
F_11 ( L_37 ,
V_186 -> V_4 . V_165 >> 20 ) ;
F_13 ( L_38 , V_186 -> V_231 >> 20 ) ;
F_13 ( L_39 , V_186 -> V_310 >> 20 ) ;
#ifdef F_9
if ( V_11 )
F_11 ( L_40 ) ;
#endif
return 0 ;
V_317:
V_186 -> V_4 . V_174 ( & V_186 -> V_4 ) ;
return V_76 ;
}
int F_316 ( struct V_57 * V_58 )
{
if ( F_55 ( V_58 ) -> V_82 < 6 && ! F_317 () )
return - V_314 ;
return 0 ;
}
void F_318 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
struct V_255 * V_23 ;
struct V_17 * V_18 ;
F_223 ( V_6 ) ;
V_186 -> V_4 . V_30 ( & V_186 -> V_4 , V_186 -> V_4 . V_29 , V_186 -> V_4 . V_165 ,
true ) ;
F_268 (obj, &dev_priv->mm.bound_list, global_list) {
F_268 (vma, &obj->vma_list, obj_link) {
if ( V_18 -> V_3 != & V_186 -> V_4 )
continue;
F_33 ( F_319 ( V_18 , V_23 -> V_20 ,
V_318 ) ) ;
}
if ( V_23 -> V_319 )
F_33 ( F_320 ( V_23 , false ) ) ;
}
if ( F_55 ( V_58 ) -> V_82 >= 8 ) {
if ( F_38 ( V_58 ) || F_39 ( V_58 ) )
F_298 ( V_6 ) ;
else
F_295 ( V_6 ) ;
return;
}
if ( F_206 ( V_58 ) ) {
struct V_2 * V_3 ;
F_268 (vm, &dev_priv->vm_list, global_link) {
struct V_108 * V_109 ;
if ( V_3 -> V_316 )
V_109 = V_6 -> V_225 . V_273 ;
else
V_109 = F_97 ( V_3 ) ;
F_159 ( V_6 , & V_109 -> V_92 ,
0 , V_109 -> V_4 . V_165 ) ;
}
}
F_228 ( V_6 ) ;
}
static struct V_17 *
F_321 ( struct V_255 * V_23 ,
struct V_2 * V_3 ,
const struct V_320 * V_268 )
{
struct V_17 * V_18 ;
if ( F_33 ( F_3 ( V_3 ) != ! ! V_268 ) )
return F_46 ( - V_66 ) ;
V_18 = F_322 ( F_115 ( V_23 -> V_4 . V_58 ) -> V_321 , V_67 ) ;
if ( V_18 == NULL )
return F_46 ( - V_63 ) ;
F_199 ( & V_18 -> V_283 ) ;
F_199 ( & V_18 -> V_322 ) ;
F_199 ( & V_18 -> V_323 ) ;
V_18 -> V_3 = V_3 ;
V_18 -> V_23 = V_23 ;
V_18 -> V_316 = F_3 ( V_3 ) ;
if ( F_3 ( V_3 ) )
V_18 -> V_268 = * V_268 ;
else
F_323 ( F_97 ( V_3 ) ) ;
F_200 ( & V_18 -> V_322 , & V_23 -> V_324 ) ;
return V_18 ;
}
struct V_17 *
F_324 ( struct V_255 * V_23 ,
struct V_2 * V_3 )
{
struct V_17 * V_18 ;
V_18 = F_269 ( V_23 , V_3 ) ;
if ( ! V_18 )
V_18 = F_321 ( V_23 , V_3 ,
F_3 ( V_3 ) ? & V_325 : NULL ) ;
return V_18 ;
}
struct V_17 *
F_325 ( struct V_255 * V_23 ,
const struct V_320 * V_326 )
{
struct V_57 * V_58 = V_23 -> V_4 . V_58 ;
struct V_5 * V_6 = F_115 ( V_58 ) ;
struct V_1 * V_186 = & V_6 -> V_186 ;
struct V_17 * V_18 = F_326 ( V_23 , V_326 ) ;
if ( ! V_18 )
V_18 = F_321 ( V_23 , & V_186 -> V_4 , V_326 ) ;
return V_18 ;
}
static struct V_327 *
F_327 ( const T_3 * V_328 , unsigned int V_257 ,
unsigned int V_329 , unsigned int V_330 ,
unsigned int V_331 ,
struct V_131 * V_259 , struct V_327 * V_332 )
{
unsigned int V_333 , V_334 ;
unsigned int V_335 ;
for ( V_333 = 0 ; V_333 < V_329 ; V_333 ++ ) {
V_335 = V_331 * ( V_330 - 1 ) + V_333 ;
for ( V_334 = 0 ; V_334 < V_330 ; V_334 ++ ) {
V_259 -> V_256 ++ ;
F_328 ( V_332 , NULL , V_69 , 0 ) ;
F_329 ( V_332 ) = V_328 [ V_257 + V_335 ] ;
F_330 ( V_332 ) = V_69 ;
V_332 = F_331 ( V_332 ) ;
V_335 -= V_331 ;
}
}
return V_332 ;
}
static struct V_131 *
F_332 ( struct V_336 * V_337 ,
struct V_255 * V_23 )
{
const T_9 V_338 = V_23 -> V_4 . V_31 / V_69 ;
unsigned int V_339 = V_337 -> V_340 [ 0 ] . V_329 * V_337 -> V_340 [ 0 ] . V_330 ;
unsigned int V_341 ;
struct V_217 V_217 ;
T_3 V_342 ;
unsigned long V_71 ;
T_3 * V_343 ;
struct V_131 * V_259 ;
unsigned int V_344 ;
struct V_327 * V_332 ;
int V_76 = - V_63 ;
V_343 = F_333 ( V_338 ,
sizeof( T_3 ) ,
V_156 ) ;
if ( ! V_343 )
return F_46 ( V_76 ) ;
if ( V_337 -> V_345 == V_346 )
V_341 = V_337 -> V_340 [ 1 ] . V_329 * V_337 -> V_340 [ 1 ] . V_330 ;
else
V_341 = 0 ;
V_259 = F_334 ( sizeof( * V_259 ) , V_67 ) ;
if ( ! V_259 )
goto V_347;
V_76 = F_335 ( V_259 , V_339 + V_341 , V_67 ) ;
if ( V_76 )
goto V_348;
V_71 = 0 ;
F_176 (dma_addr, sgt_iter, obj->pages)
V_343 [ V_71 ++ ] = V_342 ;
F_2 ( V_71 != V_338 ) ;
V_259 -> V_256 = 0 ;
V_332 = V_259 -> V_132 ;
V_332 = F_327 ( V_343 , 0 ,
V_337 -> V_340 [ 0 ] . V_329 , V_337 -> V_340 [ 0 ] . V_330 ,
V_337 -> V_340 [ 0 ] . V_329 ,
V_259 , V_332 ) ;
if ( V_337 -> V_345 == V_346 ) {
V_344 = V_339 ;
if ( F_336 ( V_337 -> V_349 ) )
V_344 -- ;
V_337 -> V_344 = V_344 ;
V_332 = F_327 ( V_343 , V_337 -> V_344 ,
V_337 -> V_340 [ 1 ] . V_329 , V_337 -> V_340 [ 1 ] . V_330 ,
V_337 -> V_340 [ 1 ] . V_329 ,
V_259 , V_332 ) ;
}
F_270 ( L_41 ,
V_23 -> V_4 . V_31 , V_337 -> V_340 [ 0 ] . V_329 ,
V_337 -> V_340 [ 0 ] . V_330 , V_339 + V_341 ,
V_339 ) ;
F_337 ( V_343 ) ;
return V_259 ;
V_348:
F_48 ( V_259 ) ;
V_347:
F_337 ( V_343 ) ;
F_270 ( L_42 ,
V_23 -> V_4 . V_31 , V_76 , V_337 -> V_340 [ 0 ] . V_329 ,
V_337 -> V_340 [ 0 ] . V_330 , V_339 + V_341 ,
V_339 ) ;
return F_46 ( V_76 ) ;
}
static struct V_131 *
F_338 ( const struct V_320 * V_326 ,
struct V_255 * V_23 )
{
struct V_131 * V_259 ;
struct V_327 * V_332 ;
struct V_129 V_350 ;
int V_76 = - V_63 ;
V_259 = F_334 ( sizeof( * V_259 ) , V_67 ) ;
if ( ! V_259 )
goto V_347;
V_76 = F_335 ( V_259 , V_326 -> V_351 . V_352 . V_31 , V_67 ) ;
if ( V_76 )
goto V_348;
V_332 = V_259 -> V_132 ;
V_259 -> V_256 = 0 ;
F_339 (obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if ( V_259 -> V_256 >= V_326 -> V_351 . V_352 . V_31 )
break;
F_328 ( V_332 , NULL , V_69 , 0 ) ;
F_329 ( V_332 ) = F_105 ( & V_350 ) ;
F_330 ( V_332 ) = V_69 ;
V_332 = F_331 ( V_332 ) ;
V_259 -> V_256 ++ ;
}
return V_259 ;
V_348:
F_48 ( V_259 ) ;
V_347:
return F_46 ( V_76 ) ;
}
static int
F_257 ( struct V_17 * V_18 )
{
int V_76 = 0 ;
if ( V_18 -> V_268 . V_27 )
return 0 ;
if ( V_18 -> V_268 . type == V_353 )
V_18 -> V_268 . V_27 = V_18 -> V_23 -> V_27 ;
else if ( V_18 -> V_268 . type == V_354 )
V_18 -> V_268 . V_27 =
F_332 ( & V_18 -> V_268 . V_351 . V_355 , V_18 -> V_23 ) ;
else if ( V_18 -> V_268 . type == V_356 )
V_18 -> V_268 . V_27 =
F_338 ( & V_18 -> V_268 , V_18 -> V_23 ) ;
else
F_340 ( 1 , L_43 ,
V_18 -> V_268 . type ) ;
if ( ! V_18 -> V_268 . V_27 ) {
F_220 ( L_44 ,
V_18 -> V_268 . type ) ;
V_76 = - V_66 ;
} else if ( F_112 ( V_18 -> V_268 . V_27 ) ) {
V_76 = F_113 ( V_18 -> V_268 . V_27 ) ;
V_18 -> V_268 . V_27 = NULL ;
F_220 ( L_45 ,
V_18 -> V_268 . type , V_76 ) ;
}
return V_76 ;
}
int F_319 ( struct V_17 * V_18 , enum V_19 V_20 ,
T_1 V_51 )
{
int V_76 ;
T_1 V_357 ;
if ( F_33 ( V_51 == 0 ) )
return - V_66 ;
V_357 = 0 ;
if ( V_51 & V_358 )
V_357 |= V_270 ;
if ( V_51 & V_359 )
V_357 |= V_271 ;
if ( V_51 & V_318 )
V_357 |= V_18 -> V_269 ;
else
V_357 &= ~ V_18 -> V_269 ;
if ( V_357 == 0 )
return 0 ;
if ( V_18 -> V_269 == 0 && V_18 -> V_3 -> V_175 ) {
V_18 -> V_360 ++ ;
F_341 ( V_18 ) ;
V_76 = V_18 -> V_3 -> V_175 ( V_18 -> V_3 ,
V_18 -> V_28 . V_29 ,
V_18 -> V_28 . V_31 ) ;
V_18 -> V_360 -- ;
if ( V_76 )
return V_76 ;
}
V_76 = V_18 -> V_3 -> V_177 ( V_18 , V_20 , V_357 ) ;
if ( V_76 )
return V_76 ;
V_18 -> V_269 |= V_357 ;
return 0 ;
}
T_9
F_342 ( struct V_255 * V_23 ,
const struct V_320 * V_326 )
{
if ( V_326 -> type == V_353 ) {
return V_23 -> V_4 . V_31 ;
} else if ( V_326 -> type == V_354 ) {
return F_343 ( & V_326 -> V_351 . V_355 ) << V_124 ;
} else if ( V_326 -> type == V_356 ) {
return V_326 -> V_351 . V_352 . V_31 << V_124 ;
} else {
F_340 ( 1 , L_43 , V_326 -> type ) ;
return V_23 -> V_4 . V_31 ;
}
}
void V_232 * F_344 ( struct V_17 * V_18 )
{
void V_232 * V_361 ;
F_345 ( & V_18 -> V_3 -> V_58 -> V_362 ) ;
if ( F_33 ( ! V_18 -> V_23 -> V_363 ) )
return F_46 ( - V_164 ) ;
F_2 ( ! V_18 -> V_316 ) ;
F_2 ( ( V_18 -> V_269 & V_270 ) == 0 ) ;
V_361 = V_18 -> V_364 ;
if ( V_361 == NULL ) {
V_361 = F_346 ( F_1 ( V_18 -> V_3 ) -> V_365 ,
V_18 -> V_28 . V_29 ,
V_18 -> V_28 . V_31 ) ;
if ( V_361 == NULL )
return F_46 ( - V_63 ) ;
V_18 -> V_364 = V_361 ;
}
V_18 -> V_360 ++ ;
return V_361 ;
}
