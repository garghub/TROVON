static int F_1 ( struct V_1 * V_2 , int V_3 )
{
bool V_4 ;
bool V_5 ;
bool V_6 ;
V_4 = F_2 ( V_2 ) -> V_7 >= 6 ;
V_5 = F_2 ( V_2 ) -> V_7 >= 7 ;
V_6 = F_3 ( V_2 ) || F_2 ( V_2 ) -> V_7 >= 9 ;
if ( F_4 ( V_2 ) )
V_5 = false ;
if ( F_2 ( V_2 ) -> V_7 < 9 &&
( V_3 == 0 || ! V_4 ) )
return 0 ;
if ( V_3 == 1 )
return 1 ;
if ( V_3 == 2 && V_5 )
return 2 ;
if ( V_3 == 3 && V_6 )
return 3 ;
#ifdef F_5
if ( F_2 ( V_2 ) -> V_7 == 6 && V_8 ) {
F_6 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_7 ( V_2 ) && V_2 -> V_9 -> V_10 < 0xb ) {
F_8 ( L_2 ) ;
return 0 ;
}
if ( F_2 ( V_2 ) -> V_7 >= 8 && V_11 . V_12 )
return V_6 ? 3 : 2 ;
else
return V_4 ? 1 : 0 ;
}
static int F_9 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_17 )
{
T_1 V_18 = 0 ;
if ( V_14 -> V_19 -> V_20 )
V_18 |= V_21 ;
V_14 -> V_22 -> V_23 ( V_14 -> V_22 , V_14 -> V_19 -> V_24 , V_14 -> V_25 . V_26 ,
V_16 , V_18 ) ;
return 0 ;
}
static void F_10 ( struct V_13 * V_14 )
{
V_14 -> V_22 -> V_27 ( V_14 -> V_22 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_19 -> V_28 . V_29 ,
true ) ;
}
static T_2 F_11 ( T_3 V_30 ,
enum V_15 V_31 ,
bool V_32 )
{
T_2 V_33 = V_32 ? V_34 | V_35 : 0 ;
V_33 |= V_30 ;
switch ( V_31 ) {
case V_36 :
V_33 |= V_37 ;
break;
case V_38 :
V_33 |= V_39 ;
break;
default:
V_33 |= V_40 ;
break;
}
return V_33 ;
}
static T_4 F_12 ( const T_3 V_30 ,
const enum V_15 V_31 )
{
T_4 V_41 = V_34 | V_35 ;
V_41 |= V_30 ;
if ( V_31 != V_36 )
V_41 |= V_42 ;
else
V_41 |= V_37 ;
return V_41 ;
}
static T_5 F_13 ( T_3 V_30 ,
enum V_15 V_31 ,
bool V_32 , T_1 V_17 )
{
T_5 V_33 = V_32 ? V_43 : 0 ;
V_33 |= F_14 ( V_30 ) ;
switch ( V_31 ) {
case V_44 :
case V_45 :
V_33 |= V_46 ;
break;
case V_36 :
V_33 |= V_47 ;
break;
default:
F_15 ( V_31 ) ;
}
return V_33 ;
}
static T_5 F_16 ( T_3 V_30 ,
enum V_15 V_31 ,
bool V_32 , T_1 V_17 )
{
T_5 V_33 = V_32 ? V_43 : 0 ;
V_33 |= F_14 ( V_30 ) ;
switch ( V_31 ) {
case V_44 :
V_33 |= V_48 ;
break;
case V_45 :
V_33 |= V_46 ;
break;
case V_36 :
V_33 |= V_47 ;
break;
default:
F_15 ( V_31 ) ;
}
return V_33 ;
}
static T_5 F_17 ( T_3 V_30 ,
enum V_15 V_31 ,
bool V_32 , T_1 V_49 )
{
T_5 V_33 = V_32 ? V_43 : 0 ;
V_33 |= F_14 ( V_30 ) ;
if ( ! ( V_49 & V_21 ) )
V_33 |= V_50 ;
if ( V_31 != V_36 )
V_33 |= V_51 ;
return V_33 ;
}
static T_5 F_18 ( T_3 V_30 ,
enum V_15 V_31 ,
bool V_32 , T_1 V_17 )
{
T_5 V_33 = V_32 ? V_43 : 0 ;
V_33 |= F_19 ( V_30 ) ;
if ( V_31 != V_36 )
V_33 |= V_52 ;
return V_33 ;
}
static T_5 F_20 ( T_3 V_30 ,
enum V_15 V_31 ,
bool V_32 , T_1 V_17 )
{
T_5 V_33 = V_32 ? V_43 : 0 ;
V_33 |= F_19 ( V_30 ) ;
switch ( V_31 ) {
case V_36 :
break;
case V_38 :
V_33 |= V_53 ;
break;
default:
V_33 |= V_54 ;
break;
}
return V_33 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_6 V_49 )
{
struct V_57 * V_57 = & V_2 -> V_9 -> V_2 ;
V_56 -> V_58 = F_22 ( V_49 ) ;
if ( ! V_56 -> V_58 )
return - V_59 ;
V_56 -> V_60 = F_23 ( V_57 ,
V_56 -> V_58 , 0 , 4096 , V_61 ) ;
if ( F_24 ( V_57 , V_56 -> V_60 ) ) {
F_25 ( V_56 -> V_58 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
return F_21 ( V_2 , V_56 , V_63 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
if ( F_28 ( ! V_56 -> V_58 ) )
return;
F_29 ( & V_2 -> V_9 -> V_2 , V_56 -> V_60 , 4096 , V_61 ) ;
F_25 ( V_56 -> V_58 ) ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
}
static void * F_30 ( struct V_55 * V_56 )
{
return F_31 ( V_56 -> V_58 ) ;
}
static void F_32 ( struct V_1 * V_2 , void * V_64 )
{
if ( F_33 ( V_2 ) || F_34 ( V_2 ) )
F_35 ( V_64 , V_65 ) ;
F_36 ( V_64 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_55 * V_56 ,
const T_7 V_66 )
{
int V_67 ;
T_7 * const V_64 = F_30 ( V_56 ) ;
for ( V_67 = 0 ; V_67 < 512 ; V_67 ++ )
V_64 [ V_67 ] = V_66 ;
F_32 ( V_2 , V_64 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_55 * V_56 ,
const T_8 V_68 )
{
T_7 V_69 = V_68 ;
V_69 = V_69 << 32 | V_68 ;
F_37 ( V_2 , V_56 , V_69 ) ;
}
static struct V_70 * F_39 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
int V_72 ;
V_71 = F_40 ( sizeof( * V_71 ) , V_63 ) ;
if ( V_71 == NULL )
return F_41 ( - V_59 ) ;
V_72 = F_21 ( V_2 , F_42 ( V_71 ) , V_73 | V_74 ) ;
if ( V_72 ) {
F_43 ( V_71 ) ;
return F_41 ( V_72 ) ;
}
F_44 ( F_45 ( V_71 ) , 1 ) ;
return V_71 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
F_47 ( F_45 ( V_71 ) , 1 ) ;
F_48 ( V_2 , V_71 ) ;
F_43 ( V_71 ) ;
}
static struct V_75 * F_49 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
const T_9 V_77 = F_2 ( V_2 ) -> V_7 >= 8 ?
V_78 : V_79 ;
int V_72 = - V_59 ;
V_76 = F_40 ( sizeof( * V_76 ) , V_63 ) ;
if ( ! V_76 )
return F_41 ( - V_59 ) ;
V_76 -> V_80 = F_50 ( F_51 ( V_77 ) , sizeof( * V_76 -> V_80 ) ,
V_63 ) ;
if ( ! V_76 -> V_80 )
goto V_81;
V_72 = F_52 ( V_2 , V_76 ) ;
if ( V_72 )
goto V_82;
return V_76 ;
V_82:
F_43 ( V_76 -> V_80 ) ;
V_81:
F_43 ( V_76 ) ;
return F_41 ( V_72 ) ;
}
static void F_53 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
F_48 ( V_2 , V_76 ) ;
F_43 ( V_76 -> V_80 ) ;
F_43 ( V_76 ) ;
}
static void F_54 ( struct V_83 * V_22 ,
struct V_75 * V_76 )
{
T_2 V_84 ;
V_84 = F_11 ( F_55 ( V_22 -> V_85 ) ,
V_45 , true ) ;
F_56 ( V_22 -> V_2 , V_76 , V_84 ) ;
}
static void F_57 ( struct V_83 * V_22 ,
struct V_75 * V_76 )
{
T_5 V_84 ;
F_28 ( F_55 ( V_22 -> V_85 ) == 0 ) ;
V_84 = V_22 -> V_86 ( F_55 ( V_22 -> V_85 ) ,
V_45 , true , 0 ) ;
F_58 ( V_22 -> V_2 , V_76 , V_84 ) ;
}
static struct V_87 * F_59 ( struct V_1 * V_2 )
{
struct V_87 * V_88 ;
int V_72 = - V_59 ;
V_88 = F_40 ( sizeof( * V_88 ) , V_63 ) ;
if ( ! V_88 )
return F_41 ( - V_59 ) ;
V_88 -> V_89 = F_50 ( F_51 ( V_90 ) ,
sizeof( * V_88 -> V_89 ) , V_63 ) ;
if ( ! V_88 -> V_89 )
goto V_81;
V_72 = F_52 ( V_2 , V_88 ) ;
if ( V_72 )
goto V_82;
return V_88 ;
V_82:
F_43 ( V_88 -> V_89 ) ;
V_81:
F_43 ( V_88 ) ;
return F_41 ( V_72 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
if ( F_45 ( V_88 ) ) {
F_48 ( V_2 , V_88 ) ;
F_43 ( V_88 -> V_89 ) ;
F_43 ( V_88 ) ;
}
}
static void F_61 ( struct V_83 * V_22 ,
struct V_87 * V_88 )
{
T_4 V_91 ;
V_91 = F_12 ( F_55 ( V_22 -> V_92 ) , V_45 ) ;
F_56 ( V_22 -> V_2 , V_88 , V_91 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
T_9 V_95 = F_63 ( V_2 ) ;
V_94 -> V_96 = F_50 ( F_51 ( V_95 ) ,
sizeof( unsigned long ) ,
V_63 ) ;
if ( ! V_94 -> V_96 )
return - V_59 ;
V_94 -> V_97 = F_50 ( V_95 , sizeof( * V_94 -> V_97 ) ,
V_63 ) ;
if ( ! V_94 -> V_97 ) {
F_43 ( V_94 -> V_96 ) ;
V_94 -> V_96 = NULL ;
return - V_59 ;
}
return 0 ;
}
static void F_64 ( struct V_93 * V_94 )
{
F_43 ( V_94 -> V_96 ) ;
F_43 ( V_94 -> V_97 ) ;
V_94 -> V_97 = NULL ;
}
static struct
V_93 * F_65 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
int V_72 = - V_59 ;
F_28 ( ! F_66 ( V_2 ) ) ;
V_94 = F_40 ( sizeof( * V_94 ) , V_63 ) ;
if ( ! V_94 )
return F_41 ( - V_59 ) ;
V_72 = F_62 ( V_2 , V_94 ) ;
if ( V_72 )
goto V_81;
V_72 = F_52 ( V_2 , V_94 ) ;
if ( V_72 )
goto V_82;
return V_94 ;
V_82:
F_64 ( V_94 ) ;
V_81:
F_43 ( V_94 ) ;
return F_41 ( V_72 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
F_64 ( V_94 ) ;
if ( F_66 ( V_2 ) ) {
F_48 ( V_2 , V_94 ) ;
F_43 ( V_94 ) ;
}
}
static void F_68 ( struct V_83 * V_22 ,
struct V_93 * V_94 )
{
T_10 V_98 ;
V_98 = F_69 ( F_55 ( V_22 -> V_99 ) , V_45 ) ;
F_56 ( V_22 -> V_2 , V_94 , V_98 ) ;
}
static void F_70 ( struct V_83 * V_22 ,
struct V_100 * V_101 )
{
T_11 V_102 ;
V_102 = F_71 ( F_55 ( V_22 -> V_103 ) ,
V_45 ) ;
F_56 ( V_22 -> V_2 , V_101 , V_102 ) ;
}
static void
F_72 ( struct V_104 * V_105 ,
struct V_93 * V_94 ,
struct V_87 * V_88 ,
int V_106 )
{
T_10 * V_107 ;
if ( ! F_66 ( V_105 -> V_28 . V_2 ) )
return;
V_107 = F_73 ( V_94 ) ;
V_107 [ V_106 ] = F_69 ( F_55 ( V_88 ) , V_45 ) ;
F_74 ( V_105 , V_107 ) ;
}
static void
F_75 ( struct V_104 * V_105 ,
struct V_100 * V_101 ,
struct V_93 * V_94 ,
int V_106 )
{
T_11 * V_108 = F_73 ( V_101 ) ;
F_28 ( ! F_66 ( V_105 -> V_28 . V_2 ) ) ;
V_108 [ V_106 ] = F_71 ( F_55 ( V_94 ) , V_45 ) ;
F_74 ( V_105 , V_108 ) ;
}
static int F_76 ( struct V_109 * V_110 ,
unsigned V_111 ,
T_3 V_30 )
{
struct V_112 * V_113 = V_110 -> V_113 ;
int V_72 ;
F_77 ( V_111 >= 4 ) ;
V_72 = F_78 ( V_110 , 6 ) ;
if ( V_72 )
return V_72 ;
F_79 ( V_113 , F_80 ( 1 ) ) ;
F_81 ( V_113 , F_82 ( V_113 , V_111 ) ) ;
F_79 ( V_113 , F_83 ( V_30 ) ) ;
F_79 ( V_113 , F_80 ( 1 ) ) ;
F_81 ( V_113 , F_84 ( V_113 , V_111 ) ) ;
F_79 ( V_113 , F_85 ( V_30 ) ) ;
F_86 ( V_113 ) ;
return 0 ;
}
static int F_87 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
int V_67 , V_72 ;
for ( V_67 = V_114 - 1 ; V_67 >= 0 ; V_67 -- ) {
const T_3 V_115 = F_88 ( V_105 , V_67 ) ;
V_72 = F_76 ( V_110 , V_67 , V_115 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_89 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
return F_76 ( V_110 , 0 , F_55 ( & V_105 -> V_101 ) ) ;
}
static void F_90 ( struct V_83 * V_22 ,
struct V_93 * V_94 ,
T_7 V_26 ,
T_7 V_116 ,
T_2 V_84 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
T_2 * V_117 ;
unsigned V_118 = F_92 ( V_26 ) ;
unsigned V_41 = F_93 ( V_26 ) ;
unsigned V_33 = F_94 ( V_26 ) ;
unsigned V_119 = V_116 >> V_120 ;
unsigned V_121 , V_67 ;
if ( F_28 ( ! V_94 ) )
return;
while ( V_119 ) {
struct V_87 * V_88 ;
struct V_75 * V_76 ;
if ( F_28 ( ! V_94 -> V_97 [ V_118 ] ) )
break;
V_88 = V_94 -> V_97 [ V_118 ] ;
if ( F_28 ( ! V_88 -> V_122 [ V_41 ] ) )
break;
V_76 = V_88 -> V_122 [ V_41 ] ;
if ( F_28 ( ! F_45 ( V_76 ) ) )
break;
V_121 = V_33 + V_119 ;
if ( V_121 > V_78 )
V_121 = V_78 ;
V_117 = F_73 ( V_76 ) ;
for ( V_67 = V_33 ; V_67 < V_121 ; V_67 ++ ) {
V_117 [ V_67 ] = V_84 ;
V_119 -- ;
}
F_74 ( V_105 , V_76 ) ;
V_33 = 0 ;
if ( ++ V_41 == V_90 ) {
if ( ++ V_118 == F_63 ( V_22 -> V_2 ) )
break;
V_41 = 0 ;
}
}
}
static void F_95 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_123 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
T_2 V_84 = F_11 ( F_55 ( V_22 -> V_85 ) ,
V_45 , V_123 ) ;
if ( ! F_66 ( V_22 -> V_2 ) ) {
F_90 ( V_22 , & V_105 -> V_94 , V_26 , V_116 ,
V_84 ) ;
} else {
T_7 V_124 ;
struct V_93 * V_94 ;
F_96 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_90 ( V_22 , V_94 , V_26 , V_116 ,
V_84 ) ;
}
}
}
static void
F_97 ( struct V_83 * V_22 ,
struct V_93 * V_94 ,
struct V_125 * V_126 ,
T_7 V_26 ,
enum V_15 V_16 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
T_2 * V_117 ;
unsigned V_118 = F_92 ( V_26 ) ;
unsigned V_41 = F_93 ( V_26 ) ;
unsigned V_33 = F_94 ( V_26 ) ;
V_117 = NULL ;
while ( F_98 ( V_126 ) ) {
if ( V_117 == NULL ) {
struct V_87 * V_88 = V_94 -> V_97 [ V_118 ] ;
struct V_75 * V_76 = V_88 -> V_122 [ V_41 ] ;
V_117 = F_73 ( V_76 ) ;
}
V_117 [ V_33 ] =
F_11 ( F_99 ( V_126 ) ,
V_16 , true ) ;
if ( ++ V_33 == V_78 ) {
F_74 ( V_105 , V_117 ) ;
V_117 = NULL ;
if ( ++ V_41 == V_90 ) {
if ( ++ V_118 == F_63 ( V_22 -> V_2 ) )
break;
V_41 = 0 ;
}
V_33 = 0 ;
}
}
if ( V_117 )
F_74 ( V_105 , V_117 ) ;
}
static void F_100 ( struct V_83 * V_22 ,
struct V_127 * V_24 ,
T_7 V_26 ,
enum V_15 V_16 ,
T_1 V_17 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
struct V_125 V_126 ;
F_101 ( & V_126 , V_24 -> V_128 , F_102 ( V_24 -> V_128 ) , 0 ) ;
if ( ! F_66 ( V_22 -> V_2 ) ) {
F_97 ( V_22 , & V_105 -> V_94 , & V_126 , V_26 ,
V_16 ) ;
} else {
struct V_93 * V_94 ;
T_7 V_124 ;
T_7 V_116 = ( T_7 ) V_24 -> V_129 << V_120 ;
F_96 (pdp, &ppgtt->pml4, start, length, pml4e) {
F_97 ( V_22 , V_94 , & V_126 ,
V_26 , V_16 ) ;
}
}
}
static void F_103 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
int V_67 ;
if ( ! F_45 ( V_88 ) )
return;
F_104 (i, pd->used_pdes, I915_PDES) {
if ( F_28 ( ! V_88 -> V_122 [ V_67 ] ) )
continue;
F_53 ( V_2 , V_88 -> V_122 [ V_67 ] ) ;
V_88 -> V_122 [ V_67 ] = NULL ;
}
}
static int F_105 ( struct V_83 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
V_22 -> V_85 = F_39 ( V_2 ) ;
if ( F_106 ( V_22 -> V_85 ) )
return F_107 ( V_22 -> V_85 ) ;
V_22 -> V_92 = F_49 ( V_2 ) ;
if ( F_106 ( V_22 -> V_92 ) ) {
F_46 ( V_2 , V_22 -> V_85 ) ;
return F_107 ( V_22 -> V_92 ) ;
}
V_22 -> V_99 = F_59 ( V_2 ) ;
if ( F_106 ( V_22 -> V_99 ) ) {
F_53 ( V_2 , V_22 -> V_92 ) ;
F_46 ( V_2 , V_22 -> V_85 ) ;
return F_107 ( V_22 -> V_99 ) ;
}
if ( F_66 ( V_2 ) ) {
V_22 -> V_103 = F_65 ( V_2 ) ;
if ( F_106 ( V_22 -> V_103 ) ) {
F_60 ( V_2 , V_22 -> V_99 ) ;
F_53 ( V_2 , V_22 -> V_92 ) ;
F_46 ( V_2 , V_22 -> V_85 ) ;
return F_107 ( V_22 -> V_103 ) ;
}
}
F_54 ( V_22 , V_22 -> V_92 ) ;
F_61 ( V_22 , V_22 -> V_99 ) ;
if ( F_66 ( V_2 ) )
F_68 ( V_22 , V_22 -> V_103 ) ;
return 0 ;
}
static int F_108 ( struct V_104 * V_105 , bool V_130 )
{
enum V_131 V_132 ;
struct V_1 * V_2 = V_105 -> V_28 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
int V_67 ;
if ( F_66 ( V_2 ) ) {
T_12 V_60 = F_55 ( & V_105 -> V_101 ) ;
F_109 ( F_110 ( V_94 [ 0 ] . V_136 ) , F_85 ( V_60 ) ) ;
F_109 ( F_110 ( V_94 [ 0 ] . V_137 ) , F_83 ( V_60 ) ) ;
V_132 = ( V_130 ? V_138 :
V_139 ) ;
} else {
for ( V_67 = 0 ; V_67 < V_114 ; V_67 ++ ) {
T_12 V_60 = F_88 ( V_105 , V_67 ) ;
F_109 ( F_110 ( V_94 [ V_67 ] . V_136 ) , F_85 ( V_60 ) ) ;
F_109 ( F_110 ( V_94 [ V_67 ] . V_137 ) , F_83 ( V_60 ) ) ;
}
V_132 = ( V_130 ? V_140 :
V_141 ) ;
}
F_109 ( F_110 ( V_142 ) , V_132 ) ;
return 0 ;
}
static void F_111 ( struct V_83 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
if ( F_66 ( V_2 ) )
F_67 ( V_2 , V_22 -> V_103 ) ;
F_60 ( V_2 , V_22 -> V_99 ) ;
F_53 ( V_2 , V_22 -> V_92 ) ;
F_46 ( V_2 , V_22 -> V_85 ) ;
}
static void F_112 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
int V_67 ;
F_104 (i, pdp->used_pdpes, I915_PDPES_PER_PDP(dev)) {
if ( F_28 ( ! V_94 -> V_97 [ V_67 ] ) )
continue;
F_103 ( V_2 , V_94 -> V_97 [ V_67 ] ) ;
F_60 ( V_2 , V_94 -> V_97 [ V_67 ] ) ;
}
F_67 ( V_2 , V_94 ) ;
}
static void F_113 ( struct V_104 * V_105 )
{
int V_67 ;
F_104 (i, ppgtt->pml4.used_pml4es, GEN8_PML4ES_PER_PML4) {
if ( F_28 ( ! V_105 -> V_101 . V_143 [ V_67 ] ) )
continue;
F_112 ( V_105 -> V_28 . V_2 , V_105 -> V_101 . V_143 [ V_67 ] ) ;
}
F_48 ( V_105 -> V_28 . V_2 , & V_105 -> V_101 ) ;
}
static void F_114 ( struct V_83 * V_22 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
if ( F_4 ( V_22 -> V_2 ) )
F_108 ( V_105 , false ) ;
if ( ! F_66 ( V_105 -> V_28 . V_2 ) )
F_112 ( V_105 -> V_28 . V_2 , & V_105 -> V_94 ) ;
else
F_113 ( V_105 ) ;
F_111 ( V_22 ) ;
}
static int F_115 ( struct V_83 * V_22 ,
struct V_87 * V_88 ,
T_7 V_26 ,
T_7 V_116 ,
unsigned long * V_144 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_75 * V_76 ;
T_8 V_41 ;
F_116 (pt, pd, start, length, pde) {
if ( F_117 ( V_41 , V_88 -> V_89 ) ) {
F_28 ( V_76 == V_22 -> V_92 ) ;
continue;
}
V_76 = F_49 ( V_2 ) ;
if ( F_106 ( V_76 ) )
goto V_145;
F_54 ( V_22 , V_76 ) ;
V_88 -> V_122 [ V_41 ] = V_76 ;
F_118 ( V_41 , V_144 ) ;
F_119 ( V_22 , V_41 , V_26 , V_146 ) ;
}
return 0 ;
V_145:
F_104 (pde, new_pts, I915_PDES)
F_53 ( V_2 , V_88 -> V_122 [ V_41 ] ) ;
return - V_59 ;
}
static int
F_120 ( struct V_83 * V_22 ,
struct V_93 * V_94 ,
T_7 V_26 ,
T_7 V_116 ,
unsigned long * V_147 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_87 * V_88 ;
T_8 V_118 ;
T_8 V_95 = F_63 ( V_2 ) ;
F_28 ( ! F_121 ( V_147 , V_95 ) ) ;
F_122 (pd, pdp, start, length, pdpe) {
if ( F_117 ( V_118 , V_94 -> V_96 ) )
continue;
V_88 = F_59 ( V_2 ) ;
if ( F_106 ( V_88 ) )
goto V_145;
F_61 ( V_22 , V_88 ) ;
V_94 -> V_97 [ V_118 ] = V_88 ;
F_118 ( V_118 , V_147 ) ;
F_123 ( V_22 , V_118 , V_26 , V_148 ) ;
}
return 0 ;
V_145:
F_104 (pdpe, new_pds, pdpes)
F_60 ( V_2 , V_94 -> V_97 [ V_118 ] ) ;
return - V_59 ;
}
static int
F_124 ( struct V_83 * V_22 ,
struct V_100 * V_101 ,
T_7 V_26 ,
T_7 V_116 ,
unsigned long * V_149 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 ;
T_8 V_124 ;
F_28 ( ! F_121 ( V_149 , V_150 ) ) ;
F_96 (pdp, pml4, start, length, pml4e) {
if ( ! F_117 ( V_124 , V_101 -> V_151 ) ) {
V_94 = F_65 ( V_2 ) ;
if ( F_106 ( V_94 ) )
goto V_145;
F_68 ( V_22 , V_94 ) ;
V_101 -> V_143 [ V_124 ] = V_94 ;
F_118 ( V_124 , V_149 ) ;
F_125 ( V_22 ,
V_124 ,
V_26 ,
V_152 ) ;
}
}
return 0 ;
V_145:
F_104 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_67 ( V_2 , V_101 -> V_143 [ V_124 ] ) ;
return - V_59 ;
}
static void
F_126 ( unsigned long * V_147 , unsigned long * V_144 )
{
F_43 ( V_144 ) ;
F_43 ( V_147 ) ;
}
static
int T_13 F_127 ( unsigned long * * V_147 ,
unsigned long * * V_144 ,
T_8 V_95 )
{
unsigned long * V_153 ;
unsigned long * V_154 ;
V_153 = F_50 ( F_51 ( V_95 ) , sizeof( unsigned long ) , V_155 ) ;
if ( ! V_153 )
return - V_59 ;
V_154 = F_50 ( V_95 , F_51 ( V_90 ) * sizeof( unsigned long ) ,
V_155 ) ;
if ( ! V_154 )
goto V_156;
* V_147 = V_153 ;
* V_144 = V_154 ;
return 0 ;
V_156:
F_126 ( V_153 , V_154 ) ;
return - V_59 ;
}
static void F_128 ( struct V_104 * V_105 )
{
V_105 -> V_157 = F_2 ( V_105 -> V_28 . V_2 ) -> V_158 ;
}
static int F_129 ( struct V_83 * V_22 ,
struct V_93 * V_94 ,
T_7 V_26 ,
T_7 V_116 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
unsigned long * V_159 , * V_160 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_87 * V_88 ;
const T_7 V_161 = V_26 ;
const T_7 V_162 = V_116 ;
T_8 V_118 ;
T_8 V_95 = F_63 ( V_2 ) ;
int V_72 ;
if ( F_28 ( V_26 + V_116 < V_26 ) )
return - V_163 ;
if ( F_28 ( V_26 + V_116 > V_22 -> V_164 ) )
return - V_163 ;
V_72 = F_127 ( & V_159 , & V_160 , V_95 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_120 ( V_22 , V_94 , V_26 , V_116 ,
V_159 ) ;
if ( V_72 ) {
F_126 ( V_159 , V_160 ) ;
return V_72 ;
}
F_122 (pd, pdp, start, length, pdpe) {
V_72 = F_115 ( V_22 , V_88 , V_26 , V_116 ,
V_160 + V_118 * F_51 ( V_90 ) ) ;
if ( V_72 )
goto V_156;
}
V_26 = V_161 ;
V_116 = V_162 ;
F_122 (pd, pdp, start, length, pdpe) {
T_4 * const V_97 = F_73 ( V_88 ) ;
struct V_75 * V_76 ;
T_7 V_165 = V_116 ;
T_7 V_166 = V_26 ;
T_8 V_41 ;
F_28 ( ! V_88 ) ;
F_116 (pt, pd, pd_start, pd_len, pde) {
F_28 ( ! V_76 ) ;
F_28 ( ! V_165 ) ;
F_28 ( ! F_130 ( V_166 , V_165 ) ) ;
F_131 ( V_76 -> V_80 ,
F_94 ( V_166 ) ,
F_130 ( V_166 , V_165 ) ) ;
F_118 ( V_41 , V_88 -> V_89 ) ;
V_97 [ V_41 ] = F_12 ( F_55 ( V_76 ) ,
V_45 ) ;
F_132 ( & V_105 -> V_28 , V_41 , V_76 ,
F_94 ( V_26 ) ,
F_130 ( V_26 , V_116 ) ,
V_78 ) ;
}
F_74 ( V_105 , V_97 ) ;
F_118 ( V_118 , V_94 -> V_96 ) ;
F_72 ( V_105 , V_94 , V_88 , V_118 ) ;
}
F_126 ( V_159 , V_160 ) ;
F_128 ( V_105 ) ;
return 0 ;
V_156:
while ( V_118 -- ) {
unsigned long V_167 ;
F_104 (temp, new_page_tables + pdpe *
BITS_TO_LONGS(I915_PDES), I915_PDES)
F_53 ( V_2 , V_94 -> V_97 [ V_118 ] -> V_122 [ V_167 ] ) ;
}
F_104 (pdpe, new_page_dirs, pdpes)
F_60 ( V_2 , V_94 -> V_97 [ V_118 ] ) ;
F_126 ( V_159 , V_160 ) ;
F_128 ( V_105 ) ;
return V_72 ;
}
static int F_133 ( struct V_83 * V_22 ,
struct V_100 * V_101 ,
T_7 V_26 ,
T_7 V_116 )
{
F_134 ( V_149 , V_150 ) ;
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
struct V_93 * V_94 ;
T_7 V_124 ;
int V_72 = 0 ;
F_135 ( V_149 , V_150 ) ;
V_72 = F_124 ( V_22 , V_101 , V_26 , V_116 ,
V_149 ) ;
if ( V_72 )
return V_72 ;
F_136 ( F_137 ( V_149 , V_150 ) > 2 ,
L_3
L_4 ) ;
F_96 (pdp, pml4, start, length, pml4e) {
F_28 ( ! V_94 ) ;
V_72 = F_129 ( V_22 , V_94 , V_26 , V_116 ) ;
if ( V_72 )
goto V_156;
F_75 ( V_105 , V_101 , V_94 , V_124 ) ;
}
F_138 ( V_101 -> V_151 , V_149 , V_101 -> V_151 ,
V_150 ) ;
return 0 ;
V_156:
F_104 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_112 ( V_22 -> V_2 , V_101 -> V_143 [ V_124 ] ) ;
return V_72 ;
}
static int F_139 ( struct V_83 * V_22 ,
T_7 V_26 , T_7 V_116 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
if ( F_66 ( V_22 -> V_2 ) )
return F_133 ( V_22 , & V_105 -> V_101 , V_26 , V_116 ) ;
else
return F_129 ( V_22 , & V_105 -> V_94 , V_26 , V_116 ) ;
}
static void F_140 ( struct V_93 * V_94 ,
T_7 V_26 , T_7 V_116 ,
T_2 V_84 ,
struct V_168 * V_169 )
{
struct V_87 * V_88 ;
T_8 V_118 ;
F_122 (pd, pdp, start, length, pdpe) {
struct V_75 * V_76 ;
T_7 V_165 = V_116 ;
T_7 V_166 = V_26 ;
T_8 V_41 ;
if ( ! F_117 ( V_118 , V_94 -> V_96 ) )
continue;
F_141 ( V_169 , L_5 , V_118 ) ;
F_116 (pt, pd, pd_start, pd_len, pde) {
T_8 V_33 ;
T_2 * V_117 ;
if ( ! F_117 ( V_41 , V_88 -> V_89 ) )
continue;
V_117 = F_73 ( V_76 ) ;
for ( V_33 = 0 ; V_33 < V_78 ; V_33 += 4 ) {
T_7 V_170 =
( V_118 << V_148 ) |
( V_41 << V_146 ) |
( V_33 << V_171 ) ;
int V_67 ;
bool V_172 = false ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ )
if ( V_117 [ V_33 + V_67 ] != V_84 )
V_172 = true ;
if ( ! V_172 )
continue;
F_141 ( V_169 , L_6 , V_170 , V_118 , V_41 , V_33 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
if ( V_117 [ V_33 + V_67 ] != V_84 )
F_141 ( V_169 , L_7 , V_117 [ V_33 + V_67 ] ) ;
else
F_142 ( V_169 , L_8 ) ;
}
F_142 ( V_169 , L_9 ) ;
}
F_36 ( V_117 ) ;
}
}
}
static void F_143 ( struct V_104 * V_105 , struct V_168 * V_169 )
{
struct V_83 * V_22 = & V_105 -> V_28 ;
T_7 V_26 = V_105 -> V_28 . V_26 ;
T_7 V_116 = V_105 -> V_28 . V_164 ;
T_2 V_84 = F_11 ( F_55 ( V_22 -> V_85 ) ,
V_45 , true ) ;
if ( ! F_66 ( V_22 -> V_2 ) ) {
F_140 ( & V_105 -> V_94 , V_26 , V_116 , V_84 , V_169 ) ;
} else {
T_7 V_124 ;
struct V_100 * V_101 = & V_105 -> V_101 ;
struct V_93 * V_94 ;
F_96 (pdp, pml4, start, length, pml4e) {
if ( ! F_117 ( V_124 , V_101 -> V_151 ) )
continue;
F_141 ( V_169 , L_10 , V_124 ) ;
F_140 ( V_94 , V_26 , V_116 , V_84 , V_169 ) ;
}
}
}
static int F_144 ( struct V_104 * V_105 )
{
unsigned long * V_159 , * V_160 ;
T_8 V_95 = F_63 ( V_2 ) ;
int V_72 ;
V_72 = F_127 ( & V_159 , & V_160 , V_95 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_120 ( & V_105 -> V_28 , & V_105 -> V_94 ,
0 , 1ULL << 32 ,
V_159 ) ;
if ( ! V_72 )
* V_105 -> V_94 . V_96 = * V_159 ;
F_126 ( V_159 , V_160 ) ;
return V_72 ;
}
static int F_145 ( struct V_104 * V_105 )
{
int V_72 ;
V_72 = F_105 ( & V_105 -> V_28 ) ;
if ( V_72 )
return V_72 ;
V_105 -> V_28 . V_26 = 0 ;
V_105 -> V_28 . V_173 = F_114 ;
V_105 -> V_28 . V_174 = F_139 ;
V_105 -> V_28 . V_23 = F_100 ;
V_105 -> V_28 . V_27 = F_95 ;
V_105 -> V_28 . V_175 = F_10 ;
V_105 -> V_28 . V_176 = F_9 ;
V_105 -> V_177 = F_143 ;
if ( F_66 ( V_105 -> V_28 . V_2 ) ) {
V_72 = F_52 ( V_105 -> V_28 . V_2 , & V_105 -> V_101 ) ;
if ( V_72 )
goto V_178;
F_70 ( & V_105 -> V_28 , & V_105 -> V_101 ) ;
V_105 -> V_28 . V_164 = 1ULL << 48 ;
V_105 -> V_179 = F_89 ;
} else {
V_72 = F_62 ( V_105 -> V_28 . V_2 , & V_105 -> V_94 ) ;
if ( V_72 )
goto V_178;
V_105 -> V_28 . V_164 = 1ULL << 32 ;
V_105 -> V_179 = F_87 ;
F_125 ( & V_105 -> V_28 ,
0 , 0 ,
V_152 ) ;
if ( F_4 ( V_105 -> V_28 . V_2 ) ) {
V_72 = F_144 ( V_105 ) ;
if ( V_72 )
goto V_178;
}
}
if ( F_4 ( V_105 -> V_28 . V_2 ) )
F_108 ( V_105 , true ) ;
return 0 ;
V_178:
F_111 ( & V_105 -> V_28 ) ;
return V_72 ;
}
static void F_146 ( struct V_104 * V_105 , struct V_168 * V_169 )
{
struct V_83 * V_22 = & V_105 -> V_28 ;
struct V_75 * V_17 ;
T_5 V_84 ;
T_8 V_180 ;
T_8 V_33 , V_41 , V_167 ;
T_8 V_26 = V_105 -> V_28 . V_26 , V_116 = V_105 -> V_28 . V_164 ;
V_84 = V_22 -> V_86 ( F_55 ( V_22 -> V_85 ) ,
V_45 , true , 0 ) ;
F_147 (unused, &ppgtt->pd, start, length, temp, pde) {
T_1 V_181 ;
T_5 * V_117 ;
const T_3 V_182 = F_55 ( V_105 -> V_88 . V_122 [ V_41 ] ) ;
V_180 = F_148 ( V_105 -> V_183 + V_41 ) ;
V_181 = ( F_149 ( V_182 ) | V_184 ) ;
if ( V_180 != V_181 )
F_141 ( V_169 , L_11 ,
V_41 ,
V_180 ,
V_181 ) ;
F_141 ( V_169 , L_12 , V_180 ) ;
V_117 = F_73 ( V_105 -> V_88 . V_122 [ V_41 ] ) ;
for ( V_33 = 0 ; V_33 < V_79 ; V_33 += 4 ) {
unsigned long V_170 =
( V_41 * V_65 * V_79 ) +
( V_33 * V_65 ) ;
int V_67 ;
bool V_172 = false ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ )
if ( V_117 [ V_33 + V_67 ] != V_84 )
V_172 = true ;
if ( ! V_172 )
continue;
F_141 ( V_169 , L_13 , V_170 , V_41 , V_33 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
if ( V_117 [ V_33 + V_67 ] != V_84 )
F_141 ( V_169 , L_14 , V_117 [ V_33 + V_67 ] ) ;
else
F_142 ( V_169 , L_8 ) ;
}
F_142 ( V_169 , L_9 ) ;
}
F_74 ( V_105 , V_117 ) ;
}
}
static void F_150 ( struct V_87 * V_88 ,
const int V_41 , struct V_75 * V_76 )
{
struct V_104 * V_105 =
F_91 ( V_88 , struct V_104 , V_88 ) ;
T_1 V_180 ;
V_180 = F_149 ( F_55 ( V_76 ) ) ;
V_180 |= V_184 ;
F_151 ( V_180 , V_105 -> V_183 + V_41 ) ;
}
static void F_152 ( struct V_133 * V_134 ,
struct V_87 * V_88 ,
T_8 V_26 , T_8 V_116 )
{
struct V_75 * V_76 ;
T_8 V_41 , V_167 ;
F_147 (pt, pd, start, length, temp, pde)
F_150 ( V_88 , V_41 , V_76 ) ;
F_148 ( V_134 -> V_185 . V_186 ) ;
}
static T_8 F_153 ( struct V_104 * V_105 )
{
F_77 ( V_105 -> V_88 . V_28 . V_187 & 0x3f ) ;
return ( V_105 -> V_88 . V_28 . V_187 / 64 ) << 16 ;
}
static int F_154 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
struct V_112 * V_113 = V_110 -> V_113 ;
int V_72 ;
V_72 = V_113 -> V_188 ( V_110 , V_189 , V_189 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_78 ( V_110 , 6 ) ;
if ( V_72 )
return V_72 ;
F_79 ( V_113 , F_80 ( 2 ) ) ;
F_81 ( V_113 , F_155 ( V_113 ) ) ;
F_79 ( V_113 , V_190 ) ;
F_81 ( V_113 , F_156 ( V_113 ) ) ;
F_79 ( V_113 , F_153 ( V_105 ) ) ;
F_79 ( V_113 , V_191 ) ;
F_86 ( V_113 ) ;
return 0 ;
}
static int F_157 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
struct V_112 * V_113 = V_110 -> V_113 ;
struct V_133 * V_134 = F_158 ( V_105 -> V_28 . V_2 ) ;
F_109 ( F_155 ( V_113 ) , V_190 ) ;
F_109 ( F_156 ( V_113 ) , F_153 ( V_105 ) ) ;
return 0 ;
}
static int F_159 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
struct V_112 * V_113 = V_110 -> V_113 ;
int V_72 ;
V_72 = V_113 -> V_188 ( V_110 , V_189 , V_189 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_78 ( V_110 , 6 ) ;
if ( V_72 )
return V_72 ;
F_79 ( V_113 , F_80 ( 2 ) ) ;
F_81 ( V_113 , F_155 ( V_113 ) ) ;
F_79 ( V_113 , V_190 ) ;
F_81 ( V_113 , F_156 ( V_113 ) ) ;
F_79 ( V_113 , F_153 ( V_105 ) ) ;
F_79 ( V_113 , V_191 ) ;
F_86 ( V_113 ) ;
if ( V_113 -> V_192 != V_193 ) {
V_72 = V_113 -> V_188 ( V_110 , V_189 , V_189 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_160 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
struct V_112 * V_113 = V_110 -> V_113 ;
struct V_1 * V_2 = V_105 -> V_28 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
F_109 ( F_155 ( V_113 ) , V_190 ) ;
F_109 ( F_156 ( V_113 ) , F_153 ( V_105 ) ) ;
F_161 ( F_155 ( V_113 ) ) ;
return 0 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_112 * V_113 ;
int V_194 ;
F_163 (ring, dev_priv, j) {
T_1 V_195 = F_66 ( V_2 ) ? V_196 : 0 ;
F_109 ( F_164 ( V_113 ) ,
F_165 ( V_197 | V_195 ) ) ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_112 * V_113 ;
T_8 V_198 , V_199 ;
int V_67 ;
V_199 = F_167 ( V_200 ) ;
F_109 ( V_200 , V_199 | V_201 ) ;
V_198 = F_167 ( V_202 ) ;
if ( F_168 ( V_2 ) ) {
V_198 |= V_203 ;
} else {
V_198 |= V_204 ;
V_198 &= ~ V_205 ;
}
F_109 ( V_202 , V_198 ) ;
F_163 (ring, dev_priv, i) {
F_109 ( F_164 ( V_113 ) ,
F_165 ( V_197 ) ) ;
}
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
T_8 V_198 , V_206 , V_199 ;
V_199 = F_167 ( V_200 ) ;
F_109 ( V_200 , V_199 | V_207 |
V_201 ) ;
V_206 = F_167 ( V_208 ) ;
F_109 ( V_208 , V_206 | V_209 ) ;
V_198 = F_167 ( V_202 ) ;
F_109 ( V_202 , V_198 | V_210 | V_211 ) ;
F_109 ( V_212 , F_165 ( V_197 ) ) ;
}
static void F_170 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_123 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
T_5 * V_117 , V_84 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_119 = V_116 >> V_120 ;
unsigned V_214 = V_213 / V_79 ;
unsigned V_215 = V_213 % V_79 ;
unsigned V_121 , V_67 ;
V_84 = V_22 -> V_86 ( F_55 ( V_22 -> V_85 ) ,
V_45 , true , 0 ) ;
while ( V_119 ) {
V_121 = V_215 + V_119 ;
if ( V_121 > V_79 )
V_121 = V_79 ;
V_117 = F_73 ( V_105 -> V_88 . V_122 [ V_214 ] ) ;
for ( V_67 = V_215 ; V_67 < V_121 ; V_67 ++ )
V_117 [ V_67 ] = V_84 ;
F_74 ( V_105 , V_117 ) ;
V_119 -= V_121 - V_215 ;
V_215 = 0 ;
V_214 ++ ;
}
}
static void F_171 ( struct V_83 * V_22 ,
struct V_127 * V_24 ,
T_7 V_26 ,
enum V_15 V_16 , T_1 V_49 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
T_5 * V_117 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_214 = V_213 / V_79 ;
unsigned V_216 = V_213 % V_79 ;
struct V_125 V_126 ;
V_117 = NULL ;
F_172 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_117 == NULL )
V_117 = F_73 ( V_105 -> V_88 . V_122 [ V_214 ] ) ;
V_117 [ V_216 ] =
V_22 -> V_86 ( F_99 ( & V_126 ) ,
V_16 , true , V_49 ) ;
if ( ++ V_216 == V_79 ) {
F_74 ( V_105 , V_117 ) ;
V_117 = NULL ;
V_214 ++ ;
V_216 = 0 ;
}
}
if ( V_117 )
F_74 ( V_105 , V_117 ) ;
}
static int F_173 ( struct V_83 * V_22 ,
T_7 V_217 , T_7 V_218 )
{
F_134 ( V_160 , V_90 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
struct V_75 * V_76 ;
T_8 V_26 , V_116 , V_219 , V_220 ;
T_8 V_41 , V_167 ;
int V_72 ;
if ( F_28 ( V_217 + V_218 > V_105 -> V_28 . V_164 ) )
return - V_163 ;
V_26 = V_219 = V_217 ;
V_116 = V_220 = V_218 ;
F_135 ( V_160 , V_90 ) ;
F_147 (pt, &ppgtt->pd, start, length, temp, pde) {
if ( V_76 != V_22 -> V_92 ) {
F_28 ( F_121 ( V_76 -> V_80 , V_79 ) ) ;
continue;
}
F_28 ( ! F_121 ( V_76 -> V_80 , V_79 ) ) ;
V_76 = F_49 ( V_2 ) ;
if ( F_106 ( V_76 ) ) {
V_72 = F_107 ( V_76 ) ;
goto V_145;
}
F_57 ( V_22 , V_76 ) ;
V_105 -> V_88 . V_122 [ V_41 ] = V_76 ;
F_118 ( V_41 , V_160 ) ;
F_119 ( V_22 , V_41 , V_26 , V_221 ) ;
}
V_26 = V_219 ;
V_116 = V_220 ;
F_147 (pt, &ppgtt->pd, start, length, temp, pde) {
F_134 ( V_222 , V_79 ) ;
F_135 ( V_222 , V_79 ) ;
F_131 ( V_222 , F_174 ( V_26 ) ,
F_175 ( V_26 , V_116 ) ) ;
if ( F_176 ( V_41 , V_160 ) )
F_150 ( & V_105 -> V_88 , V_41 , V_76 ) ;
F_132 ( V_22 , V_41 , V_76 ,
F_174 ( V_26 ) ,
F_175 ( V_26 , V_116 ) ,
V_79 ) ;
F_138 ( V_76 -> V_80 , V_222 , V_76 -> V_80 ,
V_79 ) ;
}
F_28 ( ! F_121 ( V_160 , V_90 ) ) ;
F_148 ( V_134 -> V_185 . V_186 ) ;
F_128 ( V_105 ) ;
return 0 ;
V_145:
F_104 (pde, new_page_tables, I915_PDES) {
struct V_75 * V_76 = V_105 -> V_88 . V_122 [ V_41 ] ;
V_105 -> V_88 . V_122 [ V_41 ] = V_22 -> V_92 ;
F_53 ( V_22 -> V_2 , V_76 ) ;
}
F_128 ( V_105 ) ;
return V_72 ;
}
static int F_177 ( struct V_83 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
V_22 -> V_85 = F_39 ( V_2 ) ;
if ( F_106 ( V_22 -> V_85 ) )
return F_107 ( V_22 -> V_85 ) ;
V_22 -> V_92 = F_49 ( V_2 ) ;
if ( F_106 ( V_22 -> V_92 ) ) {
F_46 ( V_2 , V_22 -> V_85 ) ;
return F_107 ( V_22 -> V_92 ) ;
}
F_57 ( V_22 , V_22 -> V_92 ) ;
return 0 ;
}
static void F_178 ( struct V_83 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_53 ( V_2 , V_22 -> V_92 ) ;
F_46 ( V_2 , V_22 -> V_85 ) ;
}
static void F_179 ( struct V_83 * V_22 )
{
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 , V_28 ) ;
struct V_75 * V_76 ;
T_8 V_41 ;
F_180 ( & V_105 -> V_25 ) ;
F_181 (pt, ppgtt, pde) {
if ( V_76 != V_22 -> V_92 )
F_53 ( V_105 -> V_28 . V_2 , V_76 ) ;
}
F_178 ( V_22 ) ;
}
static int F_182 ( struct V_104 * V_105 )
{
struct V_83 * V_22 = & V_105 -> V_28 ;
struct V_1 * V_2 = V_105 -> V_28 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
bool V_223 = false ;
int V_72 ;
F_77 ( ! F_183 ( & V_134 -> V_185 . V_28 . V_224 ) ) ;
V_72 = F_177 ( V_22 ) ;
if ( V_72 )
return V_72 ;
V_225:
V_72 = F_184 ( & V_134 -> V_185 . V_28 . V_224 ,
& V_105 -> V_25 , V_226 ,
V_227 , 0 ,
0 , V_134 -> V_185 . V_28 . V_164 ,
V_228 ) ;
if ( V_72 == - V_229 && ! V_223 ) {
V_72 = F_185 ( V_2 , & V_134 -> V_185 . V_28 ,
V_226 , V_227 ,
V_36 ,
0 , V_134 -> V_185 . V_28 . V_164 ,
0 ) ;
if ( V_72 )
goto V_156;
V_223 = true ;
goto V_225;
}
if ( V_72 )
goto V_156;
if ( V_105 -> V_25 . V_26 < V_134 -> V_185 . V_230 )
F_186 ( L_15 ) ;
return 0 ;
V_156:
F_178 ( V_22 ) ;
return V_72 ;
}
static int F_187 ( struct V_104 * V_105 )
{
return F_182 ( V_105 ) ;
}
static void F_188 ( struct V_104 * V_105 ,
T_7 V_26 , T_7 V_116 )
{
struct V_75 * V_17 ;
T_8 V_41 , V_167 ;
F_147 (unused, &ppgtt->pd, start, length, temp, pde)
V_105 -> V_88 . V_122 [ V_41 ] = V_105 -> V_28 . V_92 ;
}
static int F_189 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_28 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
int V_72 ;
V_105 -> V_28 . V_86 = V_134 -> V_185 . V_28 . V_86 ;
if ( F_190 ( V_2 ) ) {
V_105 -> V_179 = F_160 ;
} else if ( F_168 ( V_2 ) ) {
V_105 -> V_179 = F_154 ;
} else if ( F_191 ( V_2 ) ) {
V_105 -> V_179 = F_159 ;
} else
F_192 () ;
if ( F_4 ( V_2 ) )
V_105 -> V_179 = F_157 ;
V_72 = F_187 ( V_105 ) ;
if ( V_72 )
return V_72 ;
V_105 -> V_28 . V_174 = F_173 ;
V_105 -> V_28 . V_27 = F_170 ;
V_105 -> V_28 . V_23 = F_171 ;
V_105 -> V_28 . V_175 = F_10 ;
V_105 -> V_28 . V_176 = F_9 ;
V_105 -> V_28 . V_173 = F_179 ;
V_105 -> V_28 . V_26 = 0 ;
V_105 -> V_28 . V_164 = V_90 * V_79 * V_65 ;
V_105 -> V_177 = F_146 ;
V_105 -> V_88 . V_28 . V_187 =
V_105 -> V_25 . V_26 / V_65 * sizeof( T_5 ) ;
V_105 -> V_183 = ( T_5 V_231 * ) V_134 -> V_185 . V_186 +
V_105 -> V_88 . V_28 . V_187 / sizeof( T_5 ) ;
F_188 ( V_105 , 0 , V_105 -> V_28 . V_164 ) ;
F_152 ( V_134 , & V_105 -> V_88 , 0 , V_105 -> V_28 . V_164 ) ;
F_8 ( L_16 ,
V_105 -> V_25 . V_29 >> 20 ,
V_105 -> V_25 . V_26 / V_65 ) ;
F_186 ( L_17 ,
V_105 -> V_88 . V_28 . V_187 << 10 ) ;
return 0 ;
}
static int F_193 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
V_105 -> V_28 . V_2 = V_2 ;
if ( F_2 ( V_2 ) -> V_7 < 8 )
return F_189 ( V_105 ) ;
else
return F_145 ( V_105 ) ;
}
static void F_194 ( struct V_83 * V_22 ,
struct V_133 * V_134 )
{
F_195 ( & V_22 -> V_224 , V_22 -> V_26 , V_22 -> V_164 ) ;
V_22 -> V_2 = V_134 -> V_2 ;
F_196 ( & V_22 -> V_232 ) ;
F_196 ( & V_22 -> V_233 ) ;
F_197 ( & V_22 -> V_234 , & V_134 -> V_235 ) ;
}
static void F_198 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
if ( F_3 ( V_2 ) )
F_109 ( V_236 , V_237 ) ;
else if ( F_33 ( V_2 ) )
F_109 ( V_236 , V_238 ) ;
else if ( F_199 ( V_2 ) )
F_109 ( V_236 , V_239 ) ;
else if ( F_34 ( V_2 ) )
F_109 ( V_236 , V_240 ) ;
}
int F_200 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
int V_72 = 0 ;
V_72 = F_193 ( V_2 , V_105 ) ;
if ( V_72 == 0 ) {
F_201 ( & V_105 -> V_241 ) ;
F_194 ( & V_105 -> V_28 , V_134 ) ;
}
return V_72 ;
}
int F_202 ( struct V_1 * V_2 )
{
F_198 ( V_2 ) ;
if ( V_11 . V_12 )
return 0 ;
if ( ! F_203 ( V_2 ) )
return 0 ;
if ( F_190 ( V_2 ) )
F_169 ( V_2 ) ;
else if ( F_191 ( V_2 ) )
F_166 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_7 >= 8 )
F_162 ( V_2 ) ;
else
F_15 ( F_2 ( V_2 ) -> V_7 ) ;
return 0 ;
}
int F_204 ( struct V_109 * V_110 )
{
struct V_133 * V_134 = V_110 -> V_113 -> V_2 -> V_135 ;
struct V_104 * V_105 = V_134 -> V_224 . V_242 ;
if ( V_11 . V_12 )
return 0 ;
if ( ! V_105 )
return 0 ;
return V_105 -> V_179 ( V_105 , V_110 ) ;
}
struct V_104 *
F_205 ( struct V_1 * V_2 , struct V_243 * V_244 )
{
struct V_104 * V_105 ;
int V_72 ;
V_105 = F_40 ( sizeof( * V_105 ) , V_63 ) ;
if ( ! V_105 )
return F_41 ( - V_59 ) ;
V_72 = F_200 ( V_2 , V_105 ) ;
if ( V_72 ) {
F_43 ( V_105 ) ;
return F_41 ( V_72 ) ;
}
V_105 -> V_245 = V_244 ;
F_206 ( & V_105 -> V_28 ) ;
return V_105 ;
}
void F_207 ( struct V_246 * V_246 )
{
struct V_104 * V_105 =
F_91 ( V_246 , struct V_104 , V_241 ) ;
F_208 ( & V_105 -> V_28 ) ;
F_28 ( ! F_209 ( & V_105 -> V_28 . V_232 ) ) ;
F_28 ( ! F_209 ( & V_105 -> V_28 . V_233 ) ) ;
F_210 ( & V_105 -> V_28 . V_234 ) ;
F_211 ( & V_105 -> V_28 . V_224 ) ;
V_105 -> V_28 . V_173 ( & V_105 -> V_28 ) ;
F_43 ( V_105 ) ;
}
static bool F_212 ( struct V_1 * V_2 )
{
#ifdef F_5
if ( F_213 ( V_2 ) && F_214 ( V_2 ) && V_8 )
return true ;
#endif
return false ;
}
static bool F_215 ( struct V_133 * V_134 )
{
bool V_72 = V_134 -> V_224 . V_247 ;
if ( F_216 ( V_134 -> V_185 . V_248 ) ) {
V_134 -> V_224 . V_247 = false ;
if ( F_217 ( V_134 -> V_2 ) ) {
F_218 ( L_18 ) ;
F_219 ( 10 ) ;
}
}
return V_72 ;
}
static void F_220 ( struct V_133 * V_134 , bool V_247 )
{
if ( F_216 ( V_134 -> V_185 . V_248 ) )
V_134 -> V_224 . V_247 = V_247 ;
}
void F_221 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_112 * V_113 ;
int V_67 ;
if ( F_2 ( V_2 ) -> V_7 < 6 )
return;
F_163 (ring, dev_priv, i) {
T_1 V_249 ;
V_249 = F_167 ( F_222 ( V_113 ) ) ;
if ( V_249 & V_250 ) {
F_8 ( L_19
L_20
L_21
L_22
L_23 ,
V_249 & V_251 ,
V_249 & V_252 ? L_24 : L_25 ,
F_223 ( V_249 ) ,
F_224 ( V_249 ) ) ;
F_109 ( F_222 ( V_113 ) ,
V_249 & ~ V_250 ) ;
}
}
F_161 ( F_222 ( & V_134 -> V_113 [ V_193 ] ) ) ;
}
static void F_225 ( struct V_133 * V_134 )
{
if ( F_2 ( V_134 -> V_2 ) -> V_7 < 6 ) {
F_226 () ;
} else {
F_109 ( V_253 , V_254 ) ;
F_161 ( V_253 ) ;
}
}
void F_227 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
if ( F_2 ( V_2 ) -> V_7 < 6 )
return;
F_221 ( V_2 ) ;
V_134 -> V_185 . V_28 . V_27 ( & V_134 -> V_185 . V_28 ,
V_134 -> V_185 . V_28 . V_26 ,
V_134 -> V_185 . V_28 . V_164 ,
true ) ;
F_225 ( V_134 ) ;
}
int F_228 ( struct V_255 * V_19 )
{
if ( ! F_229 ( & V_19 -> V_28 . V_2 -> V_9 -> V_2 ,
V_19 -> V_24 -> V_128 , V_19 -> V_24 -> V_256 ,
V_61 ) )
return - V_229 ;
return 0 ;
}
static void F_230 ( void V_231 * V_30 , T_2 V_33 )
{
#ifdef F_231
F_231 ( V_33 , V_30 ) ;
#else
F_232 ( ( T_1 ) V_33 , V_30 ) ;
F_232 ( V_33 >> 32 , V_30 + 4 ) ;
#endif
}
static void F_233 ( struct V_83 * V_22 ,
struct V_127 * V_257 ,
T_7 V_26 ,
enum V_15 V_31 , T_1 V_17 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_135 ;
unsigned V_213 = V_26 >> V_120 ;
T_2 V_231 * V_258 =
( T_2 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
int V_67 = 0 ;
struct V_125 V_126 ;
T_3 V_30 = 0 ;
int V_259 ;
V_259 = F_234 ( V_134 ) ;
F_172 (st->sgl, &sg_iter, st->nents, 0 ) {
V_30 = F_235 ( V_126 . V_260 ) +
( V_126 . V_261 << V_120 ) ;
F_230 ( & V_258 [ V_67 ] ,
F_11 ( V_30 , V_31 , true ) ) ;
V_67 ++ ;
}
if ( V_67 != 0 )
F_28 ( F_236 ( & V_258 [ V_67 - 1 ] )
!= F_11 ( V_30 , V_31 , true ) ) ;
F_109 ( V_253 , V_254 ) ;
F_161 ( V_253 ) ;
F_237 ( V_134 , V_259 ) ;
}
static int F_238 ( void * V_262 )
{
struct V_23 * V_263 = V_262 ;
F_233 ( V_263 -> V_22 , V_263 -> V_257 ,
V_263 -> V_26 , V_263 -> V_31 , V_263 -> V_49 ) ;
return 0 ;
}
static void F_239 ( struct V_83 * V_22 ,
struct V_127 * V_257 ,
T_7 V_26 ,
enum V_15 V_31 ,
T_1 V_49 )
{
struct V_23 V_263 = { V_22 , V_257 , V_26 , V_31 , V_49 } ;
F_240 ( F_238 , & V_263 , NULL ) ;
}
static void F_241 ( struct V_83 * V_22 ,
struct V_127 * V_257 ,
T_7 V_26 ,
enum V_15 V_31 , T_1 V_49 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_135 ;
unsigned V_213 = V_26 >> V_120 ;
T_5 V_231 * V_258 =
( T_5 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
int V_67 = 0 ;
struct V_125 V_126 ;
T_3 V_30 = 0 ;
int V_259 ;
V_259 = F_234 ( V_134 ) ;
F_172 (st->sgl, &sg_iter, st->nents, 0 ) {
V_30 = F_99 ( & V_126 ) ;
F_232 ( V_22 -> V_86 ( V_30 , V_31 , true , V_49 ) , & V_258 [ V_67 ] ) ;
V_67 ++ ;
}
if ( V_67 != 0 ) {
unsigned long V_185 = F_148 ( & V_258 [ V_67 - 1 ] ) ;
F_28 ( V_185 != V_22 -> V_86 ( V_30 , V_31 , true , V_49 ) ) ;
}
F_109 ( V_253 , V_254 ) ;
F_161 ( V_253 ) ;
F_237 ( V_134 , V_259 ) ;
}
static void F_242 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_123 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_135 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_119 = V_116 >> V_120 ;
T_2 V_84 , V_231 * V_264 =
( T_2 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
const int V_265 = F_243 ( V_134 -> V_185 ) - V_213 ;
int V_67 ;
int V_259 ;
V_259 = F_234 ( V_134 ) ;
if ( F_136 ( V_119 > V_265 ,
L_26 ,
V_213 , V_119 , V_265 ) )
V_119 = V_265 ;
V_84 = F_11 ( F_55 ( V_22 -> V_85 ) ,
V_45 ,
V_123 ) ;
for ( V_67 = 0 ; V_67 < V_119 ; V_67 ++ )
F_230 ( & V_264 [ V_67 ] , V_84 ) ;
F_148 ( V_264 ) ;
F_237 ( V_134 , V_259 ) ;
}
static void F_244 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_123 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_135 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_119 = V_116 >> V_120 ;
T_5 V_84 , V_231 * V_264 =
( T_5 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
const int V_265 = F_243 ( V_134 -> V_185 ) - V_213 ;
int V_67 ;
int V_259 ;
V_259 = F_234 ( V_134 ) ;
if ( F_136 ( V_119 > V_265 ,
L_26 ,
V_213 , V_119 , V_265 ) )
V_119 = V_265 ;
V_84 = V_22 -> V_86 ( F_55 ( V_22 -> V_85 ) ,
V_45 , V_123 , 0 ) ;
for ( V_67 = 0 ; V_67 < V_119 ; V_67 ++ )
F_232 ( V_84 , & V_264 [ V_67 ] ) ;
F_148 ( V_264 ) ;
F_237 ( V_134 , V_259 ) ;
}
static void F_245 ( struct V_83 * V_22 ,
struct V_127 * V_24 ,
T_7 V_26 ,
enum V_15 V_16 , T_1 V_17 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_135 ;
unsigned int V_49 = ( V_16 == V_36 ) ?
V_266 : V_267 ;
int V_259 ;
V_259 = F_234 ( V_134 ) ;
F_246 ( V_24 , V_26 >> V_120 , V_49 ) ;
F_237 ( V_134 , V_259 ) ;
}
static void F_247 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_17 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_135 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_119 = V_116 >> V_120 ;
int V_259 ;
V_259 = F_234 ( V_134 ) ;
F_248 ( V_213 , V_119 ) ;
F_237 ( V_134 , V_259 ) ;
}
static int F_249 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_49 )
{
struct V_255 * V_19 = V_14 -> V_19 ;
T_1 V_18 = 0 ;
int V_72 ;
V_72 = F_250 ( V_14 ) ;
if ( V_72 )
return V_72 ;
if ( V_19 -> V_20 )
V_18 |= V_21 ;
V_14 -> V_22 -> V_23 ( V_14 -> V_22 , V_14 -> V_268 . V_24 ,
V_14 -> V_25 . V_26 ,
V_16 , V_18 ) ;
V_14 -> V_269 |= V_270 | V_271 ;
return 0 ;
}
static int F_251 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_49 )
{
struct V_1 * V_2 = V_14 -> V_22 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_255 * V_19 = V_14 -> V_19 ;
struct V_127 * V_24 = V_19 -> V_24 ;
T_1 V_18 = 0 ;
int V_72 ;
V_72 = F_250 ( V_14 ) ;
if ( V_72 )
return V_72 ;
V_24 = V_14 -> V_268 . V_24 ;
if ( V_19 -> V_20 )
V_18 |= V_21 ;
if ( V_49 & V_270 ) {
V_14 -> V_22 -> V_23 ( V_14 -> V_22 , V_24 ,
V_14 -> V_25 . V_26 ,
V_16 , V_18 ) ;
}
if ( V_49 & V_271 ) {
struct V_104 * V_272 = V_134 -> V_224 . V_242 ;
V_272 -> V_28 . V_23 ( & V_272 -> V_28 , V_24 ,
V_14 -> V_25 . V_26 ,
V_16 , V_18 ) ;
}
return 0 ;
}
static void F_252 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_22 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_255 * V_19 = V_14 -> V_19 ;
const T_7 V_29 = F_253 ( T_7 ,
V_19 -> V_28 . V_29 ,
V_14 -> V_25 . V_29 ) ;
if ( V_14 -> V_269 & V_270 ) {
V_14 -> V_22 -> V_27 ( V_14 -> V_22 ,
V_14 -> V_25 . V_26 ,
V_29 ,
true ) ;
}
if ( V_134 -> V_224 . V_242 && V_14 -> V_269 & V_271 ) {
struct V_104 * V_272 = V_134 -> V_224 . V_242 ;
V_272 -> V_28 . V_27 ( & V_272 -> V_28 ,
V_14 -> V_25 . V_26 ,
V_29 ,
true ) ;
}
}
void F_254 ( struct V_255 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_28 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
bool V_247 ;
V_247 = F_215 ( V_134 ) ;
F_255 ( & V_2 -> V_9 -> V_2 , V_19 -> V_24 -> V_128 , V_19 -> V_24 -> V_256 ,
V_61 ) ;
F_220 ( V_134 , V_247 ) ;
}
static void F_256 ( struct V_273 * V_25 ,
unsigned long V_274 ,
T_12 * V_26 ,
T_12 * V_275 )
{
if ( V_25 -> V_274 != V_274 )
* V_26 += 4096 ;
if ( ! F_209 ( & V_25 -> V_276 ) ) {
V_25 = F_257 ( V_25 -> V_276 . V_277 ,
struct V_273 ,
V_276 ) ;
if ( V_25 -> V_278 && V_25 -> V_274 != V_274 )
* V_275 -= 4096 ;
}
}
static int F_258 ( struct V_1 * V_2 ,
T_12 V_26 ,
T_12 V_230 ,
T_12 V_275 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_83 * V_279 = & V_134 -> V_185 . V_28 ;
struct V_273 * V_111 ;
struct V_255 * V_19 ;
unsigned long V_280 , V_281 ;
int V_72 ;
F_77 ( V_230 > V_275 ) ;
V_279 -> V_26 = V_26 ;
V_279 -> V_164 = V_275 - V_26 - V_65 ;
F_194 ( V_279 , V_134 ) ;
V_279 -> V_164 += V_65 ;
if ( F_4 ( V_2 ) ) {
V_72 = F_259 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
if ( ! F_260 ( V_2 ) )
V_279 -> V_224 . V_282 = F_256 ;
F_261 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_13 * V_14 = F_262 ( V_19 , V_279 ) ;
F_263 ( L_27 ,
F_264 ( V_19 ) , V_19 -> V_28 . V_29 ) ;
F_28 ( F_265 ( V_19 ) ) ;
V_72 = F_266 ( & V_279 -> V_224 , & V_14 -> V_25 ) ;
if ( V_72 ) {
F_263 ( L_28 , V_72 ) ;
return V_72 ;
}
V_14 -> V_269 |= V_270 ;
F_267 ( V_14 ) ;
F_197 ( & V_14 -> V_283 , & V_279 -> V_233 ) ;
}
F_268 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_263 ( L_29 ,
V_280 , V_281 ) ;
V_279 -> V_27 ( V_279 , V_280 ,
V_281 - V_280 , true ) ;
}
V_279 -> V_27 ( V_279 , V_275 - V_65 , V_65 , true ) ;
if ( F_203 ( V_2 ) && ! F_269 ( V_2 ) ) {
struct V_104 * V_105 ;
V_105 = F_40 ( sizeof( * V_105 ) , V_63 ) ;
if ( ! V_105 )
return - V_59 ;
V_72 = F_193 ( V_2 , V_105 ) ;
if ( V_72 ) {
V_105 -> V_28 . V_173 ( & V_105 -> V_28 ) ;
F_43 ( V_105 ) ;
return V_72 ;
}
if ( V_105 -> V_28 . V_174 )
V_72 = V_105 -> V_28 . V_174 ( & V_105 -> V_28 , 0 ,
V_105 -> V_28 . V_164 ) ;
if ( V_72 ) {
V_105 -> V_28 . V_173 ( & V_105 -> V_28 ) ;
F_43 ( V_105 ) ;
return V_72 ;
}
V_105 -> V_28 . V_27 ( & V_105 -> V_28 ,
V_105 -> V_28 . V_26 ,
V_105 -> V_28 . V_164 ,
true ) ;
V_134 -> V_224 . V_242 = V_105 ;
F_28 ( V_134 -> V_185 . V_28 . V_176 != F_249 ) ;
V_134 -> V_185 . V_28 . V_176 = F_251 ;
}
return 0 ;
}
void F_270 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
T_12 V_284 , V_285 ;
V_284 = V_134 -> V_185 . V_28 . V_164 ;
V_285 = V_134 -> V_185 . V_230 ;
F_258 ( V_2 , 0 , V_285 , V_284 ) ;
}
void F_271 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_83 * V_22 = & V_134 -> V_185 . V_28 ;
if ( V_134 -> V_224 . V_242 ) {
struct V_104 * V_105 = V_134 -> V_224 . V_242 ;
V_105 -> V_28 . V_173 ( & V_105 -> V_28 ) ;
}
F_272 ( V_2 ) ;
if ( F_183 ( & V_22 -> V_224 ) ) {
if ( F_4 ( V_2 ) )
F_273 () ;
F_211 ( & V_22 -> V_224 ) ;
F_210 ( & V_22 -> V_234 ) ;
}
V_22 -> V_173 ( V_22 ) ;
}
static unsigned int F_274 ( T_14 V_286 )
{
V_286 >>= V_287 ;
V_286 &= V_288 ;
return V_286 << 20 ;
}
static unsigned int F_275 ( T_14 V_289 )
{
V_289 >>= V_290 ;
V_289 &= V_291 ;
if ( V_289 )
V_289 = 1 << V_289 ;
#ifdef F_276
if ( V_289 > 4 )
V_289 = 4 ;
#endif
return V_289 << 20 ;
}
static unsigned int F_277 ( T_14 V_292 )
{
V_292 >>= V_287 ;
V_292 &= V_288 ;
if ( V_292 )
return 1 << ( 20 + V_292 ) ;
return 0 ;
}
static T_9 F_278 ( T_14 V_286 )
{
V_286 >>= V_293 ;
V_286 &= V_294 ;
return V_286 << 25 ;
}
static T_9 F_279 ( T_14 V_289 )
{
V_289 >>= V_295 ;
V_289 &= V_296 ;
return V_289 << 25 ;
}
static T_9 F_280 ( T_14 V_292 )
{
V_292 >>= V_293 ;
V_292 &= V_294 ;
if ( V_292 < 0x11 )
return V_292 << 25 ;
else if ( V_292 < 0x17 )
return ( V_292 - 0x11 + 2 ) << 22 ;
else
return ( V_292 - 0x17 + 9 ) << 22 ;
}
static T_9 F_281 ( T_14 V_297 )
{
V_297 >>= V_295 ;
V_297 &= V_296 ;
if ( V_297 < 0xf0 )
return V_297 << 25 ;
else
return ( V_297 - 0xf0 + 1 ) << 22 ;
}
static int F_282 ( struct V_1 * V_2 ,
T_9 V_284 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_70 * V_85 ;
T_15 V_298 ;
V_298 = F_283 ( V_2 -> V_9 , 0 ) +
( F_284 ( V_2 -> V_9 , 0 ) / 2 ) ;
if ( F_34 ( V_2 ) )
V_134 -> V_185 . V_186 = F_285 ( V_298 , V_284 ) ;
else
V_134 -> V_185 . V_186 = F_286 ( V_298 , V_284 ) ;
if ( ! V_134 -> V_185 . V_186 ) {
F_218 ( L_30 ) ;
return - V_59 ;
}
V_85 = F_39 ( V_2 ) ;
if ( F_106 ( V_85 ) ) {
F_218 ( L_31 ) ;
F_287 ( V_134 -> V_185 . V_186 ) ;
return F_107 ( V_85 ) ;
}
V_134 -> V_185 . V_28 . V_85 = V_85 ;
return 0 ;
}
static void F_288 ( struct V_133 * V_134 )
{
T_7 V_299 ;
V_299 = F_289 ( 0 , V_300 | V_301 ) |
F_289 ( 1 , V_302 | V_303 ) |
F_289 ( 2 , V_304 | V_303 ) |
F_289 ( 3 , V_305 ) |
F_289 ( 4 , V_300 | V_303 | F_290 ( 0 ) ) |
F_289 ( 5 , V_300 | V_303 | F_290 ( 1 ) ) |
F_289 ( 6 , V_300 | V_303 | F_290 ( 2 ) ) |
F_289 ( 7 , V_300 | V_303 | F_290 ( 3 ) ) ;
if ( ! F_203 ( V_134 -> V_2 ) )
V_299 = F_289 ( 0 , V_305 ) ;
F_109 ( V_306 , V_299 ) ;
F_109 ( V_307 , V_299 >> 32 ) ;
}
static void F_291 ( struct V_133 * V_134 )
{
T_7 V_299 ;
V_299 = F_289 ( 0 , V_308 ) |
F_289 ( 1 , 0 ) |
F_289 ( 2 , 0 ) |
F_289 ( 3 , 0 ) |
F_289 ( 4 , V_308 ) |
F_289 ( 5 , V_308 ) |
F_289 ( 6 , V_308 ) |
F_289 ( 7 , V_308 ) ;
F_109 ( V_306 , V_299 ) ;
F_109 ( V_307 , V_299 >> 32 ) ;
}
static int F_292 ( struct V_1 * V_2 ,
T_12 * V_309 ,
T_9 * V_310 ,
T_15 * V_311 ,
T_12 * V_230 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
T_12 V_284 ;
T_14 V_286 ;
int V_72 ;
* V_311 = F_283 ( V_2 -> V_9 , 2 ) ;
* V_230 = F_284 ( V_2 -> V_9 , 2 ) ;
if ( ! F_293 ( V_2 -> V_9 , F_294 ( 39 ) ) )
F_295 ( V_2 -> V_9 , F_294 ( 39 ) ) ;
F_296 ( V_2 -> V_9 , V_312 , & V_286 ) ;
if ( F_2 ( V_2 ) -> V_7 >= 9 ) {
* V_310 = F_281 ( V_286 ) ;
V_284 = F_275 ( V_286 ) ;
} else if ( F_33 ( V_2 ) ) {
* V_310 = F_280 ( V_286 ) ;
V_284 = F_277 ( V_286 ) ;
} else {
* V_310 = F_279 ( V_286 ) ;
V_284 = F_275 ( V_286 ) ;
}
* V_309 = ( V_284 / sizeof( T_2 ) ) << V_120 ;
if ( F_33 ( V_2 ) || F_34 ( V_2 ) )
F_291 ( V_134 ) ;
else
F_288 ( V_134 ) ;
V_72 = F_282 ( V_2 , V_284 ) ;
V_134 -> V_185 . V_28 . V_27 = F_242 ;
V_134 -> V_185 . V_28 . V_23 = F_233 ;
V_134 -> V_185 . V_28 . V_176 = F_249 ;
V_134 -> V_185 . V_28 . V_175 = F_252 ;
if ( F_33 ( V_134 ) )
V_134 -> V_185 . V_28 . V_23 = F_239 ;
return V_72 ;
}
static int F_297 ( struct V_1 * V_2 ,
T_12 * V_309 ,
T_9 * V_310 ,
T_15 * V_311 ,
T_12 * V_230 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
unsigned int V_284 ;
T_14 V_286 ;
int V_72 ;
* V_311 = F_283 ( V_2 -> V_9 , 2 ) ;
* V_230 = F_284 ( V_2 -> V_9 , 2 ) ;
if ( ( * V_230 < ( 64 << 20 ) || ( * V_230 > ( 512 << 20 ) ) ) ) {
F_218 ( L_32 ,
V_134 -> V_185 . V_230 ) ;
return - V_313 ;
}
if ( ! F_293 ( V_2 -> V_9 , F_294 ( 40 ) ) )
F_295 ( V_2 -> V_9 , F_294 ( 40 ) ) ;
F_296 ( V_2 -> V_9 , V_312 , & V_286 ) ;
* V_310 = F_278 ( V_286 ) ;
V_284 = F_274 ( V_286 ) ;
* V_309 = ( V_284 / sizeof( T_5 ) ) << V_120 ;
V_72 = F_282 ( V_2 , V_284 ) ;
V_134 -> V_185 . V_28 . V_27 = F_244 ;
V_134 -> V_185 . V_28 . V_23 = F_241 ;
V_134 -> V_185 . V_28 . V_176 = F_249 ;
V_134 -> V_185 . V_28 . V_175 = F_252 ;
return V_72 ;
}
static void F_298 ( struct V_83 * V_22 )
{
struct V_314 * V_185 = F_91 ( V_22 , struct V_314 , V_28 ) ;
F_287 ( V_185 -> V_186 ) ;
F_46 ( V_22 -> V_2 , V_22 -> V_85 ) ;
}
static int F_299 ( struct V_1 * V_2 ,
T_12 * V_309 ,
T_9 * V_310 ,
T_15 * V_311 ,
T_12 * V_230 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
int V_72 ;
V_72 = F_300 ( V_134 -> V_315 , V_134 -> V_2 -> V_9 , NULL ) ;
if ( ! V_72 ) {
F_218 ( L_33 ) ;
return - V_316 ;
}
F_301 ( V_309 , V_310 , V_311 , V_230 ) ;
V_134 -> V_185 . V_248 = F_212 ( V_134 -> V_2 ) ;
V_134 -> V_185 . V_28 . V_23 = F_245 ;
V_134 -> V_185 . V_28 . V_27 = F_247 ;
V_134 -> V_185 . V_28 . V_176 = F_249 ;
V_134 -> V_185 . V_28 . V_175 = F_252 ;
if ( F_216 ( V_134 -> V_185 . V_248 ) )
F_6 ( L_34 ) ;
return 0 ;
}
static void F_302 ( struct V_83 * V_22 )
{
F_303 () ;
}
int F_304 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_314 * V_185 = & V_134 -> V_185 ;
int V_72 ;
if ( F_2 ( V_2 ) -> V_7 <= 5 ) {
V_185 -> V_317 = F_299 ;
V_185 -> V_28 . V_173 = F_302 ;
} else if ( F_2 ( V_2 ) -> V_7 < 8 ) {
V_185 -> V_317 = F_297 ;
V_185 -> V_28 . V_173 = F_298 ;
if ( F_168 ( V_2 ) && V_134 -> V_318 )
V_185 -> V_28 . V_86 = F_20 ;
else if ( F_168 ( V_2 ) )
V_185 -> V_28 . V_86 = F_18 ;
else if ( F_7 ( V_2 ) )
V_185 -> V_28 . V_86 = F_17 ;
else if ( F_2 ( V_2 ) -> V_7 >= 7 )
V_185 -> V_28 . V_86 = F_16 ;
else
V_185 -> V_28 . V_86 = F_13 ;
} else {
V_134 -> V_185 . V_317 = F_292 ;
V_134 -> V_185 . V_28 . V_173 = F_298 ;
}
V_185 -> V_28 . V_2 = V_2 ;
V_185 -> V_28 . V_319 = true ;
V_72 = V_185 -> V_317 ( V_2 , & V_185 -> V_28 . V_164 , & V_185 -> V_320 ,
& V_185 -> V_311 , & V_185 -> V_230 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_305 ( V_2 ) ;
if ( V_72 )
goto V_321;
F_6 ( L_35 ,
V_185 -> V_28 . V_164 >> 20 ) ;
F_8 ( L_36 , V_185 -> V_230 >> 20 ) ;
F_8 ( L_37 , V_185 -> V_320 >> 20 ) ;
#ifdef F_5
if ( V_8 )
F_6 ( L_38 ) ;
#endif
V_11 . V_3 = F_1 ( V_2 , V_11 . V_3 ) ;
F_8 ( L_39 , V_11 . V_3 ) ;
return 0 ;
V_321:
V_185 -> V_28 . V_173 ( & V_134 -> V_185 . V_28 ) ;
return V_72 ;
}
void F_306 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_255 * V_19 ;
struct V_83 * V_22 ;
struct V_13 * V_14 ;
bool V_188 ;
F_221 ( V_2 ) ;
V_134 -> V_185 . V_28 . V_27 ( & V_134 -> V_185 . V_28 ,
V_134 -> V_185 . V_28 . V_26 ,
V_134 -> V_185 . V_28 . V_164 ,
true ) ;
V_22 = & V_134 -> V_185 . V_28 ;
F_261 (obj, &dev_priv->mm.bound_list, global_list) {
V_188 = false ;
F_261 (vma, &obj->vma_list, obj_link) {
if ( V_14 -> V_22 != V_22 )
continue;
F_28 ( F_307 ( V_14 , V_19 -> V_16 ,
V_322 ) ) ;
V_188 = true ;
}
if ( V_188 )
F_308 ( V_19 , V_19 -> V_323 ) ;
}
if ( F_2 ( V_2 ) -> V_7 >= 8 ) {
if ( F_33 ( V_2 ) || F_34 ( V_2 ) )
F_291 ( V_134 ) ;
else
F_288 ( V_134 ) ;
return;
}
if ( F_203 ( V_2 ) ) {
F_261 (vm, &dev_priv->vm_list, global_link) {
struct V_104 * V_105 =
F_91 ( V_22 , struct V_104 ,
V_28 ) ;
if ( F_309 ( V_22 ) )
V_105 = V_134 -> V_224 . V_242 ;
F_152 ( V_134 , & V_105 -> V_88 ,
0 , V_105 -> V_28 . V_164 ) ;
}
}
F_225 ( V_134 ) ;
}
static struct V_13 *
F_310 ( struct V_255 * V_19 ,
struct V_83 * V_22 ,
const struct V_324 * V_268 )
{
struct V_13 * V_14 ;
if ( F_28 ( F_309 ( V_22 ) != ! ! V_268 ) )
return F_41 ( - V_62 ) ;
V_14 = F_311 ( F_158 ( V_19 -> V_28 . V_2 ) -> V_325 , V_63 ) ;
if ( V_14 == NULL )
return F_41 ( - V_59 ) ;
F_196 ( & V_14 -> V_283 ) ;
F_196 ( & V_14 -> V_326 ) ;
F_196 ( & V_14 -> V_327 ) ;
V_14 -> V_22 = V_22 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_319 = F_309 ( V_22 ) ;
if ( F_309 ( V_22 ) )
V_14 -> V_268 = * V_268 ;
else
F_312 ( F_313 ( V_22 ) ) ;
F_197 ( & V_14 -> V_326 , & V_19 -> V_328 ) ;
return V_14 ;
}
struct V_13 *
F_314 ( struct V_255 * V_19 ,
struct V_83 * V_22 )
{
struct V_13 * V_14 ;
V_14 = F_262 ( V_19 , V_22 ) ;
if ( ! V_14 )
V_14 = F_310 ( V_19 , V_22 ,
F_309 ( V_22 ) ? & V_329 : NULL ) ;
return V_14 ;
}
struct V_13 *
F_315 ( struct V_255 * V_19 ,
const struct V_324 * V_330 )
{
struct V_83 * V_331 = F_316 ( V_19 ) ;
struct V_13 * V_14 ;
if ( F_28 ( ! V_330 ) )
return F_41 ( - V_62 ) ;
V_14 = F_317 ( V_19 , V_330 ) ;
if ( F_106 ( V_14 ) )
return V_14 ;
if ( ! V_14 )
V_14 = F_310 ( V_19 , V_331 , V_330 ) ;
return V_14 ;
}
static struct V_332 *
F_318 ( const T_3 * V_333 , unsigned int V_334 ,
unsigned int V_335 , unsigned int V_336 ,
unsigned int V_337 ,
struct V_127 * V_257 , struct V_332 * V_260 )
{
unsigned int V_338 , V_339 ;
unsigned int V_340 ;
if ( ! V_260 ) {
V_257 -> V_256 = 0 ;
V_260 = V_257 -> V_128 ;
}
for ( V_338 = 0 ; V_338 < V_335 ; V_338 ++ ) {
V_340 = V_337 * ( V_336 - 1 ) + V_338 ;
for ( V_339 = 0 ; V_339 < V_336 ; V_339 ++ ) {
V_257 -> V_256 ++ ;
F_319 ( V_260 , NULL , V_65 , 0 ) ;
F_235 ( V_260 ) = V_333 [ V_334 + V_340 ] ;
F_320 ( V_260 ) = V_65 ;
V_260 = F_321 ( V_260 ) ;
V_340 -= V_337 ;
}
}
return V_260 ;
}
static struct V_127 *
F_322 ( struct V_341 * V_342 ,
struct V_255 * V_19 )
{
unsigned int V_343 = V_342 -> V_29 >> V_120 ;
unsigned int V_344 ;
struct V_125 V_126 ;
unsigned long V_67 ;
T_3 * V_345 ;
struct V_127 * V_257 ;
unsigned int V_346 ;
struct V_332 * V_260 ;
int V_72 = - V_59 ;
V_345 = F_323 ( V_19 -> V_28 . V_29 / V_65 ,
sizeof( T_3 ) ) ;
if ( ! V_345 )
return F_41 ( V_72 ) ;
if ( V_342 -> V_347 == V_348 )
V_344 = V_342 -> V_349 >> V_120 ;
else
V_344 = 0 ;
V_257 = F_324 ( sizeof( * V_257 ) , V_63 ) ;
if ( ! V_257 )
goto V_350;
V_72 = F_325 ( V_257 , V_343 + V_344 , V_63 ) ;
if ( V_72 )
goto V_351;
V_67 = 0 ;
F_172 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_345 [ V_67 ] = F_99 ( & V_126 ) ;
V_67 ++ ;
}
V_260 = F_318 ( V_345 , 0 ,
V_342 -> V_352 , V_342 -> V_353 ,
V_342 -> V_352 ,
V_257 , NULL ) ;
if ( V_342 -> V_347 == V_348 ) {
V_346 = V_343 ;
if ( F_326 ( V_342 -> V_354 ) )
V_346 -- ;
V_342 -> V_346 = V_346 ;
F_318 ( V_345 , V_346 ,
V_342 -> V_355 ,
V_342 -> V_356 ,
V_342 -> V_355 ,
V_257 , V_260 ) ;
}
F_263 (
L_40 ,
V_19 -> V_28 . V_29 , V_342 -> V_357 , V_342 -> V_336 ,
V_342 -> V_347 , V_342 -> V_352 ,
V_342 -> V_353 , V_343 + V_344 ,
V_343 ) ;
F_327 ( V_345 ) ;
return V_257 ;
V_351:
F_43 ( V_257 ) ;
V_350:
F_327 ( V_345 ) ;
F_263 (
L_41 ,
V_19 -> V_28 . V_29 , V_72 , V_342 -> V_357 , V_342 -> V_336 ,
V_342 -> V_347 , V_342 -> V_352 ,
V_342 -> V_353 , V_343 + V_344 ,
V_343 ) ;
return F_41 ( V_72 ) ;
}
static struct V_127 *
F_328 ( const struct V_324 * V_330 ,
struct V_255 * V_19 )
{
struct V_127 * V_257 ;
struct V_332 * V_260 ;
struct V_125 V_358 ;
int V_72 = - V_59 ;
V_257 = F_324 ( sizeof( * V_257 ) , V_63 ) ;
if ( ! V_257 )
goto V_350;
V_72 = F_325 ( V_257 , V_330 -> V_359 . V_360 . V_29 , V_63 ) ;
if ( V_72 )
goto V_351;
V_260 = V_257 -> V_128 ;
V_257 -> V_256 = 0 ;
F_172 (obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if ( V_257 -> V_256 >= V_330 -> V_359 . V_360 . V_29 )
break;
F_319 ( V_260 , NULL , V_65 , 0 ) ;
F_235 ( V_260 ) = F_99 ( & V_358 ) ;
F_320 ( V_260 ) = V_65 ;
V_260 = F_321 ( V_260 ) ;
V_257 -> V_256 ++ ;
}
return V_257 ;
V_351:
F_43 ( V_257 ) ;
V_350:
return F_41 ( V_72 ) ;
}
static int
F_250 ( struct V_13 * V_14 )
{
int V_72 = 0 ;
if ( V_14 -> V_268 . V_24 )
return 0 ;
if ( V_14 -> V_268 . type == V_361 )
V_14 -> V_268 . V_24 = V_14 -> V_19 -> V_24 ;
else if ( V_14 -> V_268 . type == V_362 )
V_14 -> V_268 . V_24 =
F_322 ( & V_14 -> V_268 . V_359 . V_363 , V_14 -> V_19 ) ;
else if ( V_14 -> V_268 . type == V_364 )
V_14 -> V_268 . V_24 =
F_328 ( & V_14 -> V_268 , V_14 -> V_19 ) ;
else
F_329 ( 1 , L_42 ,
V_14 -> V_268 . type ) ;
if ( ! V_14 -> V_268 . V_24 ) {
F_218 ( L_43 ,
V_14 -> V_268 . type ) ;
V_72 = - V_62 ;
} else if ( F_106 ( V_14 -> V_268 . V_24 ) ) {
V_72 = F_107 ( V_14 -> V_268 . V_24 ) ;
V_14 -> V_268 . V_24 = NULL ;
F_218 ( L_44 ,
V_14 -> V_268 . type , V_72 ) ;
}
return V_72 ;
}
int F_307 ( struct V_13 * V_14 , enum V_15 V_16 ,
T_1 V_49 )
{
int V_72 ;
T_1 V_365 ;
if ( F_28 ( V_49 == 0 ) )
return - V_62 ;
V_365 = 0 ;
if ( V_49 & V_366 )
V_365 |= V_270 ;
if ( V_49 & V_367 )
V_365 |= V_271 ;
if ( V_49 & V_322 )
V_365 |= V_14 -> V_269 ;
else
V_365 &= ~ V_14 -> V_269 ;
if ( V_365 == 0 )
return 0 ;
if ( V_14 -> V_269 == 0 && V_14 -> V_22 -> V_174 ) {
V_14 -> V_368 ++ ;
F_330 ( V_14 ) ;
V_72 = V_14 -> V_22 -> V_174 ( V_14 -> V_22 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_29 ) ;
V_14 -> V_368 -- ;
if ( V_72 )
return V_72 ;
}
V_72 = V_14 -> V_22 -> V_176 ( V_14 , V_16 , V_365 ) ;
if ( V_72 )
return V_72 ;
V_14 -> V_269 |= V_365 ;
return 0 ;
}
T_9
F_331 ( struct V_255 * V_19 ,
const struct V_324 * V_330 )
{
if ( V_330 -> type == V_361 ) {
return V_19 -> V_28 . V_29 ;
} else if ( V_330 -> type == V_362 ) {
return V_330 -> V_359 . V_363 . V_29 ;
} else if ( V_330 -> type == V_364 ) {
return V_330 -> V_359 . V_360 . V_29 << V_120 ;
} else {
F_329 ( 1 , L_42 , V_330 -> type ) ;
return V_19 -> V_28 . V_29 ;
}
}
