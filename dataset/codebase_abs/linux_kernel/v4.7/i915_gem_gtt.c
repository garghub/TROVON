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
struct V_104 * V_105 = F_91 ( V_22 ) ;
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
F_74 ( V_105 , V_117 ) ;
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
struct V_104 * V_105 = F_91 ( V_22 ) ;
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
struct V_104 * V_105 = F_91 ( V_22 ) ;
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
struct V_104 * V_105 = F_91 ( V_22 ) ;
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
struct V_133 * V_134 = F_109 ( V_105 -> V_28 . V_2 ) ;
int V_67 ;
if ( F_66 ( V_134 ) ) {
T_12 V_60 = F_55 ( & V_105 -> V_101 ) ;
F_110 ( F_111 ( V_94 [ 0 ] . V_135 ) , F_85 ( V_60 ) ) ;
F_110 ( F_111 ( V_94 [ 0 ] . V_136 ) , F_83 ( V_60 ) ) ;
V_132 = ( V_130 ? V_137 :
V_138 ) ;
} else {
for ( V_67 = 0 ; V_67 < V_114 ; V_67 ++ ) {
T_12 V_60 = F_88 ( V_105 , V_67 ) ;
F_110 ( F_111 ( V_94 [ V_67 ] . V_135 ) , F_85 ( V_60 ) ) ;
F_110 ( F_111 ( V_94 [ V_67 ] . V_136 ) , F_83 ( V_60 ) ) ;
}
V_132 = ( V_130 ? V_139 :
V_140 ) ;
}
F_110 ( F_111 ( V_141 ) , V_132 ) ;
return 0 ;
}
static void F_112 ( struct V_83 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
if ( F_66 ( V_2 ) )
F_67 ( V_2 , V_22 -> V_103 ) ;
F_60 ( V_2 , V_22 -> V_99 ) ;
F_53 ( V_2 , V_22 -> V_92 ) ;
F_46 ( V_2 , V_22 -> V_85 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
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
static void F_114 ( struct V_104 * V_105 )
{
int V_67 ;
F_104 (i, ppgtt->pml4.used_pml4es, GEN8_PML4ES_PER_PML4) {
if ( F_28 ( ! V_105 -> V_101 . V_142 [ V_67 ] ) )
continue;
F_113 ( V_105 -> V_28 . V_2 , V_105 -> V_101 . V_142 [ V_67 ] ) ;
}
F_48 ( V_105 -> V_28 . V_2 , & V_105 -> V_101 ) ;
}
static void F_115 ( struct V_83 * V_22 )
{
struct V_104 * V_105 = F_91 ( V_22 ) ;
if ( F_4 ( V_22 -> V_2 ) )
F_108 ( V_105 , false ) ;
if ( ! F_66 ( V_105 -> V_28 . V_2 ) )
F_113 ( V_105 -> V_28 . V_2 , & V_105 -> V_94 ) ;
else
F_114 ( V_105 ) ;
F_112 ( V_22 ) ;
}
static int F_116 ( struct V_83 * V_22 ,
struct V_87 * V_88 ,
T_7 V_26 ,
T_7 V_116 ,
unsigned long * V_143 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_75 * V_76 ;
T_8 V_41 ;
F_117 (pt, pd, start, length, pde) {
if ( F_118 ( V_41 , V_88 -> V_89 ) ) {
F_28 ( V_76 == V_22 -> V_92 ) ;
continue;
}
V_76 = F_49 ( V_2 ) ;
if ( F_106 ( V_76 ) )
goto V_144;
F_54 ( V_22 , V_76 ) ;
V_88 -> V_122 [ V_41 ] = V_76 ;
F_119 ( V_41 , V_143 ) ;
F_120 ( V_22 , V_41 , V_26 , V_145 ) ;
}
return 0 ;
V_144:
F_104 (pde, new_pts, I915_PDES)
F_53 ( V_2 , V_88 -> V_122 [ V_41 ] ) ;
return - V_59 ;
}
static int
F_121 ( struct V_83 * V_22 ,
struct V_93 * V_94 ,
T_7 V_26 ,
T_7 V_116 ,
unsigned long * V_146 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_87 * V_88 ;
T_8 V_118 ;
T_8 V_95 = F_63 ( V_2 ) ;
F_28 ( ! F_122 ( V_146 , V_95 ) ) ;
F_123 (pd, pdp, start, length, pdpe) {
if ( F_118 ( V_118 , V_94 -> V_96 ) )
continue;
V_88 = F_59 ( V_2 ) ;
if ( F_106 ( V_88 ) )
goto V_144;
F_61 ( V_22 , V_88 ) ;
V_94 -> V_97 [ V_118 ] = V_88 ;
F_119 ( V_118 , V_146 ) ;
F_124 ( V_22 , V_118 , V_26 , V_147 ) ;
}
return 0 ;
V_144:
F_104 (pdpe, new_pds, pdpes)
F_60 ( V_2 , V_94 -> V_97 [ V_118 ] ) ;
return - V_59 ;
}
static int
F_125 ( struct V_83 * V_22 ,
struct V_100 * V_101 ,
T_7 V_26 ,
T_7 V_116 ,
unsigned long * V_148 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_93 * V_94 ;
T_8 V_124 ;
F_28 ( ! F_122 ( V_148 , V_149 ) ) ;
F_96 (pdp, pml4, start, length, pml4e) {
if ( ! F_118 ( V_124 , V_101 -> V_150 ) ) {
V_94 = F_65 ( V_2 ) ;
if ( F_106 ( V_94 ) )
goto V_144;
F_68 ( V_22 , V_94 ) ;
V_101 -> V_142 [ V_124 ] = V_94 ;
F_119 ( V_124 , V_148 ) ;
F_126 ( V_22 ,
V_124 ,
V_26 ,
V_151 ) ;
}
}
return 0 ;
V_144:
F_104 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_67 ( V_2 , V_101 -> V_142 [ V_124 ] ) ;
return - V_59 ;
}
static void
F_127 ( unsigned long * V_146 , unsigned long * V_143 )
{
F_43 ( V_143 ) ;
F_43 ( V_146 ) ;
}
static
int T_13 F_128 ( unsigned long * * V_146 ,
unsigned long * * V_143 ,
T_8 V_95 )
{
unsigned long * V_152 ;
unsigned long * V_153 ;
V_152 = F_50 ( F_51 ( V_95 ) , sizeof( unsigned long ) , V_154 ) ;
if ( ! V_152 )
return - V_59 ;
V_153 = F_50 ( V_95 , F_51 ( V_90 ) * sizeof( unsigned long ) ,
V_154 ) ;
if ( ! V_153 )
goto V_155;
* V_146 = V_152 ;
* V_143 = V_153 ;
return 0 ;
V_155:
F_127 ( V_152 , V_153 ) ;
return - V_59 ;
}
static void F_129 ( struct V_104 * V_105 )
{
V_105 -> V_156 = F_2 ( V_105 -> V_28 . V_2 ) -> V_157 ;
}
static int F_130 ( struct V_83 * V_22 ,
struct V_93 * V_94 ,
T_7 V_26 ,
T_7 V_116 )
{
struct V_104 * V_105 = F_91 ( V_22 ) ;
unsigned long * V_158 , * V_159 ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_87 * V_88 ;
const T_7 V_160 = V_26 ;
const T_7 V_161 = V_116 ;
T_8 V_118 ;
T_8 V_95 = F_63 ( V_2 ) ;
int V_72 ;
if ( F_28 ( V_26 + V_116 < V_26 ) )
return - V_162 ;
if ( F_28 ( V_26 + V_116 > V_22 -> V_163 ) )
return - V_162 ;
V_72 = F_128 ( & V_158 , & V_159 , V_95 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_121 ( V_22 , V_94 , V_26 , V_116 ,
V_158 ) ;
if ( V_72 ) {
F_127 ( V_158 , V_159 ) ;
return V_72 ;
}
F_123 (pd, pdp, start, length, pdpe) {
V_72 = F_116 ( V_22 , V_88 , V_26 , V_116 ,
V_159 + V_118 * F_51 ( V_90 ) ) ;
if ( V_72 )
goto V_155;
}
V_26 = V_160 ;
V_116 = V_161 ;
F_123 (pd, pdp, start, length, pdpe) {
T_4 * const V_97 = F_73 ( V_88 ) ;
struct V_75 * V_76 ;
T_7 V_164 = V_116 ;
T_7 V_165 = V_26 ;
T_8 V_41 ;
F_28 ( ! V_88 ) ;
F_117 (pt, pd, pd_start, pd_len, pde) {
F_28 ( ! V_76 ) ;
F_28 ( ! V_164 ) ;
F_28 ( ! F_131 ( V_165 , V_164 ) ) ;
F_132 ( V_76 -> V_80 ,
F_94 ( V_165 ) ,
F_131 ( V_165 , V_164 ) ) ;
F_119 ( V_41 , V_88 -> V_89 ) ;
V_97 [ V_41 ] = F_12 ( F_55 ( V_76 ) ,
V_45 ) ;
F_133 ( & V_105 -> V_28 , V_41 , V_76 ,
F_94 ( V_26 ) ,
F_131 ( V_26 , V_116 ) ,
V_78 ) ;
}
F_74 ( V_105 , V_97 ) ;
F_119 ( V_118 , V_94 -> V_96 ) ;
F_72 ( V_105 , V_94 , V_88 , V_118 ) ;
}
F_127 ( V_158 , V_159 ) ;
F_129 ( V_105 ) ;
return 0 ;
V_155:
while ( V_118 -- ) {
unsigned long V_166 ;
F_104 (temp, new_page_tables + pdpe *
BITS_TO_LONGS(I915_PDES), I915_PDES)
F_53 ( V_2 , V_94 -> V_97 [ V_118 ] -> V_122 [ V_166 ] ) ;
}
F_104 (pdpe, new_page_dirs, pdpes)
F_60 ( V_2 , V_94 -> V_97 [ V_118 ] ) ;
F_127 ( V_158 , V_159 ) ;
F_129 ( V_105 ) ;
return V_72 ;
}
static int F_134 ( struct V_83 * V_22 ,
struct V_100 * V_101 ,
T_7 V_26 ,
T_7 V_116 )
{
F_135 ( V_148 , V_149 ) ;
struct V_104 * V_105 = F_91 ( V_22 ) ;
struct V_93 * V_94 ;
T_7 V_124 ;
int V_72 = 0 ;
F_136 ( V_148 , V_149 ) ;
V_72 = F_125 ( V_22 , V_101 , V_26 , V_116 ,
V_148 ) ;
if ( V_72 )
return V_72 ;
F_137 ( F_138 ( V_148 , V_149 ) > 2 ,
L_3
L_4 ) ;
F_96 (pdp, pml4, start, length, pml4e) {
F_28 ( ! V_94 ) ;
V_72 = F_130 ( V_22 , V_94 , V_26 , V_116 ) ;
if ( V_72 )
goto V_155;
F_75 ( V_105 , V_101 , V_94 , V_124 ) ;
}
F_139 ( V_101 -> V_150 , V_148 , V_101 -> V_150 ,
V_149 ) ;
return 0 ;
V_155:
F_104 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_113 ( V_22 -> V_2 , V_101 -> V_142 [ V_124 ] ) ;
return V_72 ;
}
static int F_140 ( struct V_83 * V_22 ,
T_7 V_26 , T_7 V_116 )
{
struct V_104 * V_105 = F_91 ( V_22 ) ;
if ( F_66 ( V_22 -> V_2 ) )
return F_134 ( V_22 , & V_105 -> V_101 , V_26 , V_116 ) ;
else
return F_130 ( V_22 , & V_105 -> V_94 , V_26 , V_116 ) ;
}
static void F_141 ( struct V_93 * V_94 ,
T_7 V_26 , T_7 V_116 ,
T_2 V_84 ,
struct V_167 * V_168 )
{
struct V_87 * V_88 ;
T_8 V_118 ;
F_123 (pd, pdp, start, length, pdpe) {
struct V_75 * V_76 ;
T_7 V_164 = V_116 ;
T_7 V_165 = V_26 ;
T_8 V_41 ;
if ( ! F_118 ( V_118 , V_94 -> V_96 ) )
continue;
F_142 ( V_168 , L_5 , V_118 ) ;
F_117 (pt, pd, pd_start, pd_len, pde) {
T_8 V_33 ;
T_2 * V_117 ;
if ( ! F_118 ( V_41 , V_88 -> V_89 ) )
continue;
V_117 = F_73 ( V_76 ) ;
for ( V_33 = 0 ; V_33 < V_78 ; V_33 += 4 ) {
T_7 V_169 =
( V_118 << V_147 ) |
( V_41 << V_145 ) |
( V_33 << V_170 ) ;
int V_67 ;
bool V_171 = false ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ )
if ( V_117 [ V_33 + V_67 ] != V_84 )
V_171 = true ;
if ( ! V_171 )
continue;
F_142 ( V_168 , L_6 , V_169 , V_118 , V_41 , V_33 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
if ( V_117 [ V_33 + V_67 ] != V_84 )
F_142 ( V_168 , L_7 , V_117 [ V_33 + V_67 ] ) ;
else
F_143 ( V_168 , L_8 ) ;
}
F_143 ( V_168 , L_9 ) ;
}
F_36 ( V_117 ) ;
}
}
}
static void F_144 ( struct V_104 * V_105 , struct V_167 * V_168 )
{
struct V_83 * V_22 = & V_105 -> V_28 ;
T_7 V_26 = V_105 -> V_28 . V_26 ;
T_7 V_116 = V_105 -> V_28 . V_163 ;
T_2 V_84 = F_11 ( F_55 ( V_22 -> V_85 ) ,
V_45 , true ) ;
if ( ! F_66 ( V_22 -> V_2 ) ) {
F_141 ( & V_105 -> V_94 , V_26 , V_116 , V_84 , V_168 ) ;
} else {
T_7 V_124 ;
struct V_100 * V_101 = & V_105 -> V_101 ;
struct V_93 * V_94 ;
F_96 (pdp, pml4, start, length, pml4e) {
if ( ! F_118 ( V_124 , V_101 -> V_150 ) )
continue;
F_142 ( V_168 , L_10 , V_124 ) ;
F_141 ( V_94 , V_26 , V_116 , V_84 , V_168 ) ;
}
}
}
static int F_145 ( struct V_104 * V_105 )
{
unsigned long * V_158 , * V_159 ;
T_8 V_95 = F_63 ( V_2 ) ;
int V_72 ;
V_72 = F_128 ( & V_158 , & V_159 , V_95 ) ;
if ( V_72 )
return V_72 ;
V_72 = F_121 ( & V_105 -> V_28 , & V_105 -> V_94 ,
0 , 1ULL << 32 ,
V_158 ) ;
if ( ! V_72 )
* V_105 -> V_94 . V_96 = * V_158 ;
F_127 ( V_158 , V_159 ) ;
return V_72 ;
}
static int F_146 ( struct V_104 * V_105 )
{
int V_72 ;
V_72 = F_105 ( & V_105 -> V_28 ) ;
if ( V_72 )
return V_72 ;
V_105 -> V_28 . V_26 = 0 ;
V_105 -> V_28 . V_172 = F_115 ;
V_105 -> V_28 . V_173 = F_140 ;
V_105 -> V_28 . V_23 = F_100 ;
V_105 -> V_28 . V_27 = F_95 ;
V_105 -> V_28 . V_174 = F_10 ;
V_105 -> V_28 . V_175 = F_9 ;
V_105 -> V_176 = F_144 ;
if ( F_66 ( V_105 -> V_28 . V_2 ) ) {
V_72 = F_52 ( V_105 -> V_28 . V_2 , & V_105 -> V_101 ) ;
if ( V_72 )
goto V_177;
F_70 ( & V_105 -> V_28 , & V_105 -> V_101 ) ;
V_105 -> V_28 . V_163 = 1ULL << 48 ;
V_105 -> V_178 = F_89 ;
} else {
V_72 = F_62 ( V_105 -> V_28 . V_2 , & V_105 -> V_94 ) ;
if ( V_72 )
goto V_177;
V_105 -> V_28 . V_163 = 1ULL << 32 ;
V_105 -> V_178 = F_87 ;
F_126 ( & V_105 -> V_28 ,
0 , 0 ,
V_151 ) ;
if ( F_4 ( V_105 -> V_28 . V_2 ) ) {
V_72 = F_145 ( V_105 ) ;
if ( V_72 )
goto V_177;
}
}
if ( F_4 ( V_105 -> V_28 . V_2 ) )
F_108 ( V_105 , true ) ;
return 0 ;
V_177:
F_112 ( & V_105 -> V_28 ) ;
return V_72 ;
}
static void F_147 ( struct V_104 * V_105 , struct V_167 * V_168 )
{
struct V_83 * V_22 = & V_105 -> V_28 ;
struct V_75 * V_17 ;
T_5 V_84 ;
T_8 V_179 ;
T_8 V_33 , V_41 , V_166 ;
T_8 V_26 = V_105 -> V_28 . V_26 , V_116 = V_105 -> V_28 . V_163 ;
V_84 = V_22 -> V_86 ( F_55 ( V_22 -> V_85 ) ,
V_45 , true , 0 ) ;
F_148 (unused, &ppgtt->pd, start, length, temp, pde) {
T_1 V_180 ;
T_5 * V_117 ;
const T_3 V_181 = F_55 ( V_105 -> V_88 . V_122 [ V_41 ] ) ;
V_179 = F_149 ( V_105 -> V_182 + V_41 ) ;
V_180 = ( F_150 ( V_181 ) | V_183 ) ;
if ( V_179 != V_180 )
F_142 ( V_168 , L_11 ,
V_41 ,
V_179 ,
V_180 ) ;
F_142 ( V_168 , L_12 , V_179 ) ;
V_117 = F_73 ( V_105 -> V_88 . V_122 [ V_41 ] ) ;
for ( V_33 = 0 ; V_33 < V_79 ; V_33 += 4 ) {
unsigned long V_169 =
( V_41 * V_65 * V_79 ) +
( V_33 * V_65 ) ;
int V_67 ;
bool V_171 = false ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ )
if ( V_117 [ V_33 + V_67 ] != V_84 )
V_171 = true ;
if ( ! V_171 )
continue;
F_142 ( V_168 , L_13 , V_169 , V_41 , V_33 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
if ( V_117 [ V_33 + V_67 ] != V_84 )
F_142 ( V_168 , L_14 , V_117 [ V_33 + V_67 ] ) ;
else
F_143 ( V_168 , L_8 ) ;
}
F_143 ( V_168 , L_9 ) ;
}
F_74 ( V_105 , V_117 ) ;
}
}
static void F_151 ( struct V_87 * V_88 ,
const int V_41 , struct V_75 * V_76 )
{
struct V_104 * V_105 =
F_152 ( V_88 , struct V_104 , V_88 ) ;
T_1 V_179 ;
V_179 = F_150 ( F_55 ( V_76 ) ) ;
V_179 |= V_183 ;
F_153 ( V_179 , V_105 -> V_182 + V_41 ) ;
}
static void F_154 ( struct V_133 * V_134 ,
struct V_87 * V_88 ,
T_8 V_26 , T_8 V_116 )
{
struct V_184 * V_185 = & V_134 -> V_185 ;
struct V_75 * V_76 ;
T_8 V_41 , V_166 ;
F_148 (pt, pd, start, length, temp, pde)
F_151 ( V_88 , V_41 , V_76 ) ;
F_149 ( V_185 -> V_186 ) ;
}
static T_8 F_155 ( struct V_104 * V_105 )
{
F_77 ( V_105 -> V_88 . V_28 . V_187 & 0x3f ) ;
return ( V_105 -> V_88 . V_28 . V_187 / 64 ) << 16 ;
}
static int F_156 ( struct V_104 * V_105 ,
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
F_81 ( V_113 , F_157 ( V_113 ) ) ;
F_79 ( V_113 , V_190 ) ;
F_81 ( V_113 , F_158 ( V_113 ) ) ;
F_79 ( V_113 , F_155 ( V_105 ) ) ;
F_79 ( V_113 , V_191 ) ;
F_86 ( V_113 ) ;
return 0 ;
}
static int F_159 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
struct V_112 * V_113 = V_110 -> V_113 ;
struct V_133 * V_134 = F_109 ( V_105 -> V_28 . V_2 ) ;
F_110 ( F_157 ( V_113 ) , V_190 ) ;
F_110 ( F_158 ( V_113 ) , F_155 ( V_105 ) ) ;
return 0 ;
}
static int F_160 ( struct V_104 * V_105 ,
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
F_81 ( V_113 , F_157 ( V_113 ) ) ;
F_79 ( V_113 , V_190 ) ;
F_81 ( V_113 , F_158 ( V_113 ) ) ;
F_79 ( V_113 , F_155 ( V_105 ) ) ;
F_79 ( V_113 , V_191 ) ;
F_86 ( V_113 ) ;
if ( V_113 -> V_192 != V_193 ) {
V_72 = V_113 -> V_188 ( V_110 , V_189 , V_189 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_161 ( struct V_104 * V_105 ,
struct V_109 * V_110 )
{
struct V_112 * V_113 = V_110 -> V_113 ;
struct V_1 * V_2 = V_105 -> V_28 . V_2 ;
struct V_133 * V_134 = V_2 -> V_194 ;
F_110 ( F_157 ( V_113 ) , V_190 ) ;
F_110 ( F_158 ( V_113 ) , F_155 ( V_105 ) ) ;
F_162 ( F_157 ( V_113 ) ) ;
return 0 ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_194 ;
struct V_112 * V_113 ;
F_164 (engine, dev_priv) {
T_1 V_195 = F_66 ( V_2 ) ? V_196 : 0 ;
F_110 ( F_165 ( V_113 ) ,
F_166 ( V_197 | V_195 ) ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_194 ;
struct V_112 * V_113 ;
T_8 V_198 , V_199 ;
V_199 = F_168 ( V_200 ) ;
F_110 ( V_200 , V_199 | V_201 ) ;
V_198 = F_168 ( V_202 ) ;
if ( F_169 ( V_2 ) ) {
V_198 |= V_203 ;
} else {
V_198 |= V_204 ;
V_198 &= ~ V_205 ;
}
F_110 ( V_202 , V_198 ) ;
F_164 (engine, dev_priv) {
F_110 ( F_165 ( V_113 ) ,
F_166 ( V_197 ) ) ;
}
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_194 ;
T_8 V_198 , V_206 , V_199 ;
V_199 = F_168 ( V_200 ) ;
F_110 ( V_200 , V_199 | V_207 |
V_201 ) ;
V_206 = F_168 ( V_208 ) ;
F_110 ( V_208 , V_206 | V_209 ) ;
V_198 = F_168 ( V_202 ) ;
F_110 ( V_202 , V_198 | V_210 | V_211 ) ;
F_110 ( V_212 , F_166 ( V_197 ) ) ;
}
static void F_171 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_123 )
{
struct V_104 * V_105 = F_91 ( V_22 ) ;
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
static void F_172 ( struct V_83 * V_22 ,
struct V_127 * V_24 ,
T_7 V_26 ,
enum V_15 V_16 , T_1 V_49 )
{
struct V_104 * V_105 = F_91 ( V_22 ) ;
T_5 * V_117 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_214 = V_213 / V_79 ;
unsigned V_216 = V_213 % V_79 ;
struct V_125 V_126 ;
V_117 = NULL ;
F_173 (pages->sgl, &sg_iter, pages->nents, 0 ) {
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
static int F_174 ( struct V_83 * V_22 ,
T_7 V_217 , T_7 V_218 )
{
F_135 ( V_159 , V_90 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
struct V_104 * V_105 = F_91 ( V_22 ) ;
struct V_75 * V_76 ;
T_8 V_26 , V_116 , V_219 , V_220 ;
T_8 V_41 , V_166 ;
int V_72 ;
if ( F_28 ( V_217 + V_218 > V_105 -> V_28 . V_163 ) )
return - V_162 ;
V_26 = V_219 = V_217 ;
V_116 = V_220 = V_218 ;
F_136 ( V_159 , V_90 ) ;
F_148 (pt, &ppgtt->pd, start, length, temp, pde) {
if ( V_76 != V_22 -> V_92 ) {
F_28 ( F_122 ( V_76 -> V_80 , V_79 ) ) ;
continue;
}
F_28 ( ! F_122 ( V_76 -> V_80 , V_79 ) ) ;
V_76 = F_49 ( V_2 ) ;
if ( F_106 ( V_76 ) ) {
V_72 = F_107 ( V_76 ) ;
goto V_144;
}
F_57 ( V_22 , V_76 ) ;
V_105 -> V_88 . V_122 [ V_41 ] = V_76 ;
F_119 ( V_41 , V_159 ) ;
F_120 ( V_22 , V_41 , V_26 , V_221 ) ;
}
V_26 = V_219 ;
V_116 = V_220 ;
F_148 (pt, &ppgtt->pd, start, length, temp, pde) {
F_135 ( V_222 , V_79 ) ;
F_136 ( V_222 , V_79 ) ;
F_132 ( V_222 , F_175 ( V_26 ) ,
F_176 ( V_26 , V_116 ) ) ;
if ( F_177 ( V_41 , V_159 ) )
F_151 ( & V_105 -> V_88 , V_41 , V_76 ) ;
F_133 ( V_22 , V_41 , V_76 ,
F_175 ( V_26 ) ,
F_176 ( V_26 , V_116 ) ,
V_79 ) ;
F_139 ( V_76 -> V_80 , V_222 , V_76 -> V_80 ,
V_79 ) ;
}
F_28 ( ! F_122 ( V_159 , V_90 ) ) ;
F_149 ( V_185 -> V_186 ) ;
F_129 ( V_105 ) ;
return 0 ;
V_144:
F_104 (pde, new_page_tables, I915_PDES) {
struct V_75 * V_76 = V_105 -> V_88 . V_122 [ V_41 ] ;
V_105 -> V_88 . V_122 [ V_41 ] = V_22 -> V_92 ;
F_53 ( V_22 -> V_2 , V_76 ) ;
}
F_129 ( V_105 ) ;
return V_72 ;
}
static int F_178 ( struct V_83 * V_22 )
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
static void F_179 ( struct V_83 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
F_53 ( V_2 , V_22 -> V_92 ) ;
F_46 ( V_2 , V_22 -> V_85 ) ;
}
static void F_180 ( struct V_83 * V_22 )
{
struct V_104 * V_105 = F_91 ( V_22 ) ;
struct V_75 * V_76 ;
T_8 V_41 ;
F_181 ( & V_105 -> V_25 ) ;
F_182 (pt, ppgtt, pde) {
if ( V_76 != V_22 -> V_92 )
F_53 ( V_105 -> V_28 . V_2 , V_76 ) ;
}
F_179 ( V_22 ) ;
}
static int F_183 ( struct V_104 * V_105 )
{
struct V_83 * V_22 = & V_105 -> V_28 ;
struct V_1 * V_2 = V_105 -> V_28 . V_2 ;
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
bool V_223 = false ;
int V_72 ;
F_77 ( ! F_184 ( & V_185 -> V_28 . V_224 ) ) ;
V_72 = F_178 ( V_22 ) ;
if ( V_72 )
return V_72 ;
V_225:
V_72 = F_185 ( & V_185 -> V_28 . V_224 ,
& V_105 -> V_25 , V_226 ,
V_227 , 0 ,
0 , V_185 -> V_28 . V_163 ,
V_228 ) ;
if ( V_72 == - V_229 && ! V_223 ) {
V_72 = F_186 ( V_2 , & V_185 -> V_28 ,
V_226 , V_227 ,
V_36 ,
0 , V_185 -> V_28 . V_163 ,
0 ) ;
if ( V_72 )
goto V_155;
V_223 = true ;
goto V_225;
}
if ( V_72 )
goto V_155;
if ( V_105 -> V_25 . V_26 < V_185 -> V_230 )
F_187 ( L_15 ) ;
return 0 ;
V_155:
F_179 ( V_22 ) ;
return V_72 ;
}
static int F_188 ( struct V_104 * V_105 )
{
return F_183 ( V_105 ) ;
}
static void F_189 ( struct V_104 * V_105 ,
T_7 V_26 , T_7 V_116 )
{
struct V_75 * V_17 ;
T_8 V_41 , V_166 ;
F_148 (unused, &ppgtt->pd, start, length, temp, pde)
V_105 -> V_88 . V_122 [ V_41 ] = V_105 -> V_28 . V_92 ;
}
static int F_190 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_28 . V_2 ;
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
int V_72 ;
V_105 -> V_28 . V_86 = V_185 -> V_28 . V_86 ;
if ( F_191 ( V_2 ) ) {
V_105 -> V_178 = F_161 ;
} else if ( F_169 ( V_2 ) ) {
V_105 -> V_178 = F_156 ;
} else if ( F_192 ( V_2 ) ) {
V_105 -> V_178 = F_160 ;
} else
F_193 () ;
if ( F_4 ( V_2 ) )
V_105 -> V_178 = F_159 ;
V_72 = F_188 ( V_105 ) ;
if ( V_72 )
return V_72 ;
V_105 -> V_28 . V_173 = F_174 ;
V_105 -> V_28 . V_27 = F_171 ;
V_105 -> V_28 . V_23 = F_172 ;
V_105 -> V_28 . V_174 = F_10 ;
V_105 -> V_28 . V_175 = F_9 ;
V_105 -> V_28 . V_172 = F_180 ;
V_105 -> V_28 . V_26 = 0 ;
V_105 -> V_28 . V_163 = V_90 * V_79 * V_65 ;
V_105 -> V_176 = F_147 ;
V_105 -> V_88 . V_28 . V_187 =
V_105 -> V_25 . V_26 / V_65 * sizeof( T_5 ) ;
V_105 -> V_182 = ( T_5 V_231 * ) V_185 -> V_186 +
V_105 -> V_88 . V_28 . V_187 / sizeof( T_5 ) ;
F_189 ( V_105 , 0 , V_105 -> V_28 . V_163 ) ;
F_154 ( V_134 , & V_105 -> V_88 , 0 , V_105 -> V_28 . V_163 ) ;
F_8 ( L_16 ,
V_105 -> V_25 . V_29 >> 20 ,
V_105 -> V_25 . V_26 / V_65 ) ;
F_187 ( L_17 ,
V_105 -> V_88 . V_28 . V_187 << 10 ) ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
V_105 -> V_28 . V_2 = V_2 ;
if ( F_2 ( V_2 ) -> V_7 < 8 )
return F_190 ( V_105 ) ;
else
return F_146 ( V_105 ) ;
}
static void F_195 ( struct V_83 * V_22 ,
struct V_133 * V_134 )
{
F_196 ( & V_22 -> V_224 , V_22 -> V_26 , V_22 -> V_163 ) ;
V_22 -> V_2 = V_134 -> V_2 ;
F_197 ( & V_22 -> V_232 ) ;
F_197 ( & V_22 -> V_233 ) ;
F_198 ( & V_22 -> V_234 , & V_134 -> V_235 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_194 ;
if ( F_3 ( V_2 ) )
F_110 ( V_236 , V_237 ) ;
else if ( F_33 ( V_2 ) )
F_110 ( V_236 , V_238 ) ;
else if ( F_200 ( V_2 ) )
F_110 ( V_236 , V_239 ) ;
else if ( F_34 ( V_2 ) )
F_110 ( V_236 , V_240 ) ;
}
int F_201 ( struct V_1 * V_2 , struct V_104 * V_105 )
{
struct V_133 * V_134 = V_2 -> V_194 ;
int V_72 = 0 ;
V_72 = F_194 ( V_2 , V_105 ) ;
if ( V_72 == 0 ) {
F_202 ( & V_105 -> V_241 ) ;
F_195 ( & V_105 -> V_28 , V_134 ) ;
}
return V_72 ;
}
int F_203 ( struct V_1 * V_2 )
{
F_199 ( V_2 ) ;
if ( V_11 . V_12 )
return 0 ;
if ( ! F_204 ( V_2 ) )
return 0 ;
if ( F_191 ( V_2 ) )
F_170 ( V_2 ) ;
else if ( F_192 ( V_2 ) )
F_167 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_7 >= 8 )
F_163 ( V_2 ) ;
else
F_15 ( F_2 ( V_2 ) -> V_7 ) ;
return 0 ;
}
int F_205 ( struct V_109 * V_110 )
{
struct V_133 * V_134 = V_110 -> V_11 ;
struct V_104 * V_105 = V_134 -> V_224 . V_242 ;
if ( V_11 . V_12 )
return 0 ;
if ( ! V_105 )
return 0 ;
return V_105 -> V_178 ( V_105 , V_110 ) ;
}
struct V_104 *
F_206 ( struct V_1 * V_2 , struct V_243 * V_244 )
{
struct V_104 * V_105 ;
int V_72 ;
V_105 = F_40 ( sizeof( * V_105 ) , V_63 ) ;
if ( ! V_105 )
return F_41 ( - V_59 ) ;
V_72 = F_201 ( V_2 , V_105 ) ;
if ( V_72 ) {
F_43 ( V_105 ) ;
return F_41 ( V_72 ) ;
}
V_105 -> V_245 = V_244 ;
F_207 ( & V_105 -> V_28 ) ;
return V_105 ;
}
void F_208 ( struct V_246 * V_246 )
{
struct V_104 * V_105 =
F_152 ( V_246 , struct V_104 , V_241 ) ;
F_209 ( & V_105 -> V_28 ) ;
F_28 ( ! F_210 ( & V_105 -> V_28 . V_232 ) ) ;
F_28 ( ! F_210 ( & V_105 -> V_28 . V_233 ) ) ;
F_211 ( & V_105 -> V_28 . V_234 ) ;
F_212 ( & V_105 -> V_28 . V_224 ) ;
V_105 -> V_28 . V_172 ( & V_105 -> V_28 ) ;
F_43 ( V_105 ) ;
}
static bool F_213 ( struct V_1 * V_2 )
{
#ifdef F_5
if ( F_214 ( V_2 ) && F_215 ( V_2 ) && V_8 )
return true ;
#endif
return false ;
}
static bool F_216 ( struct V_133 * V_134 )
{
struct V_184 * V_185 = & V_134 -> V_185 ;
bool V_72 = V_134 -> V_224 . V_247 ;
if ( F_217 ( V_185 -> V_248 ) ) {
V_134 -> V_224 . V_247 = false ;
if ( F_218 ( V_134 -> V_2 ) ) {
F_219 ( L_18 ) ;
F_220 ( 10 ) ;
}
}
return V_72 ;
}
static void F_221 ( struct V_133 * V_134 , bool V_247 )
{
struct V_184 * V_185 = & V_134 -> V_185 ;
if ( F_217 ( V_185 -> V_248 ) )
V_134 -> V_224 . V_247 = V_247 ;
}
void F_222 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_194 ;
struct V_112 * V_113 ;
if ( F_2 ( V_2 ) -> V_7 < 6 )
return;
F_164 (engine, dev_priv) {
T_1 V_249 ;
V_249 = F_168 ( F_223 ( V_113 ) ) ;
if ( V_249 & V_250 ) {
F_8 ( L_19
L_20
L_21
L_22
L_23 ,
V_249 & V_251 ,
V_249 & V_252 ? L_24 : L_25 ,
F_224 ( V_249 ) ,
F_225 ( V_249 ) ) ;
F_110 ( F_223 ( V_113 ) ,
V_249 & ~ V_250 ) ;
}
}
F_162 ( F_223 ( & V_134 -> V_113 [ V_193 ] ) ) ;
}
static void F_226 ( struct V_133 * V_134 )
{
if ( F_2 ( V_134 ) -> V_7 < 6 ) {
F_227 () ;
} else {
F_110 ( V_253 , V_254 ) ;
F_162 ( V_253 ) ;
}
}
void F_228 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
if ( F_2 ( V_2 ) -> V_7 < 6 )
return;
F_222 ( V_2 ) ;
V_185 -> V_28 . V_27 ( & V_185 -> V_28 , V_185 -> V_28 . V_26 , V_185 -> V_28 . V_163 ,
true ) ;
F_226 ( V_134 ) ;
}
int F_229 ( struct V_255 * V_19 )
{
if ( ! F_230 ( & V_19 -> V_28 . V_2 -> V_9 -> V_2 ,
V_19 -> V_24 -> V_128 , V_19 -> V_24 -> V_256 ,
V_61 ) )
return - V_229 ;
return 0 ;
}
static void F_231 ( void V_231 * V_30 , T_2 V_33 )
{
#ifdef F_232
F_232 ( V_33 , V_30 ) ;
#else
F_233 ( ( T_1 ) V_33 , V_30 ) ;
F_233 ( V_33 >> 32 , V_30 + 4 ) ;
#endif
}
static void F_234 ( struct V_83 * V_22 ,
struct V_127 * V_257 ,
T_7 V_26 ,
enum V_15 V_31 , T_1 V_17 )
{
struct V_133 * V_134 = F_109 ( V_22 -> V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
unsigned V_213 = V_26 >> V_120 ;
T_2 V_231 * V_258 =
( T_2 V_231 * ) V_185 -> V_186 + V_213 ;
int V_67 = 0 ;
struct V_125 V_126 ;
T_3 V_30 = 0 ;
int V_259 ;
V_259 = F_235 ( V_134 ) ;
F_173 (st->sgl, &sg_iter, st->nents, 0 ) {
V_30 = F_236 ( V_126 . V_260 ) +
( V_126 . V_261 << V_120 ) ;
F_231 ( & V_258 [ V_67 ] ,
F_11 ( V_30 , V_31 , true ) ) ;
V_67 ++ ;
}
if ( V_67 != 0 )
F_28 ( F_237 ( & V_258 [ V_67 - 1 ] )
!= F_11 ( V_30 , V_31 , true ) ) ;
F_110 ( V_253 , V_254 ) ;
F_162 ( V_253 ) ;
F_238 ( V_134 , V_259 ) ;
}
static int F_239 ( void * V_262 )
{
struct V_23 * V_263 = V_262 ;
F_234 ( V_263 -> V_22 , V_263 -> V_257 ,
V_263 -> V_26 , V_263 -> V_31 , V_263 -> V_49 ) ;
return 0 ;
}
static void F_240 ( struct V_83 * V_22 ,
struct V_127 * V_257 ,
T_7 V_26 ,
enum V_15 V_31 ,
T_1 V_49 )
{
struct V_23 V_263 = { V_22 , V_257 , V_26 , V_31 , V_49 } ;
F_241 ( F_239 , & V_263 , NULL ) ;
}
static void F_242 ( struct V_83 * V_22 ,
struct V_127 * V_257 ,
T_7 V_26 ,
enum V_15 V_31 , T_1 V_49 )
{
struct V_133 * V_134 = F_109 ( V_22 -> V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
unsigned V_213 = V_26 >> V_120 ;
T_5 V_231 * V_258 =
( T_5 V_231 * ) V_185 -> V_186 + V_213 ;
int V_67 = 0 ;
struct V_125 V_126 ;
T_3 V_30 = 0 ;
int V_259 ;
V_259 = F_235 ( V_134 ) ;
F_173 (st->sgl, &sg_iter, st->nents, 0 ) {
V_30 = F_99 ( & V_126 ) ;
F_233 ( V_22 -> V_86 ( V_30 , V_31 , true , V_49 ) , & V_258 [ V_67 ] ) ;
V_67 ++ ;
}
if ( V_67 != 0 ) {
unsigned long V_264 = F_149 ( & V_258 [ V_67 - 1 ] ) ;
F_28 ( V_264 != V_22 -> V_86 ( V_30 , V_31 , true , V_49 ) ) ;
}
F_110 ( V_253 , V_254 ) ;
F_162 ( V_253 ) ;
F_238 ( V_134 , V_259 ) ;
}
static void F_243 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_123 )
{
struct V_133 * V_134 = F_109 ( V_22 -> V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_119 = V_116 >> V_120 ;
T_2 V_84 , V_231 * V_265 =
( T_2 V_231 * ) V_185 -> V_186 + V_213 ;
const int V_266 = F_244 ( V_185 ) - V_213 ;
int V_67 ;
int V_259 ;
V_259 = F_235 ( V_134 ) ;
if ( F_137 ( V_119 > V_266 ,
L_26 ,
V_213 , V_119 , V_266 ) )
V_119 = V_266 ;
V_84 = F_11 ( F_55 ( V_22 -> V_85 ) ,
V_45 ,
V_123 ) ;
for ( V_67 = 0 ; V_67 < V_119 ; V_67 ++ )
F_231 ( & V_265 [ V_67 ] , V_84 ) ;
F_149 ( V_265 ) ;
F_238 ( V_134 , V_259 ) ;
}
static void F_245 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_123 )
{
struct V_133 * V_134 = F_109 ( V_22 -> V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_119 = V_116 >> V_120 ;
T_5 V_84 , V_231 * V_265 =
( T_5 V_231 * ) V_185 -> V_186 + V_213 ;
const int V_266 = F_244 ( V_185 ) - V_213 ;
int V_67 ;
int V_259 ;
V_259 = F_235 ( V_134 ) ;
if ( F_137 ( V_119 > V_266 ,
L_26 ,
V_213 , V_119 , V_266 ) )
V_119 = V_266 ;
V_84 = V_22 -> V_86 ( F_55 ( V_22 -> V_85 ) ,
V_45 , V_123 , 0 ) ;
for ( V_67 = 0 ; V_67 < V_119 ; V_67 ++ )
F_233 ( V_84 , & V_265 [ V_67 ] ) ;
F_149 ( V_265 ) ;
F_238 ( V_134 , V_259 ) ;
}
static void F_246 ( struct V_83 * V_22 ,
struct V_127 * V_24 ,
T_7 V_26 ,
enum V_15 V_16 , T_1 V_17 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_194 ;
unsigned int V_49 = ( V_16 == V_36 ) ?
V_267 : V_268 ;
int V_259 ;
V_259 = F_235 ( V_134 ) ;
F_247 ( V_24 , V_26 >> V_120 , V_49 ) ;
F_238 ( V_134 , V_259 ) ;
}
static void F_248 ( struct V_83 * V_22 ,
T_7 V_26 ,
T_7 V_116 ,
bool V_17 )
{
struct V_133 * V_134 = V_22 -> V_2 -> V_194 ;
unsigned V_213 = V_26 >> V_120 ;
unsigned V_119 = V_116 >> V_120 ;
int V_259 ;
V_259 = F_235 ( V_134 ) ;
F_249 ( V_213 , V_119 ) ;
F_238 ( V_134 , V_259 ) ;
}
static int F_250 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_49 )
{
struct V_255 * V_19 = V_14 -> V_19 ;
T_1 V_18 = 0 ;
int V_72 ;
V_72 = F_251 ( V_14 ) ;
if ( V_72 )
return V_72 ;
if ( V_19 -> V_20 )
V_18 |= V_21 ;
V_14 -> V_22 -> V_23 ( V_14 -> V_22 , V_14 -> V_269 . V_24 ,
V_14 -> V_25 . V_26 ,
V_16 , V_18 ) ;
V_14 -> V_270 |= V_271 | V_272 ;
return 0 ;
}
static int F_252 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
T_1 V_49 )
{
T_1 V_18 ;
int V_72 ;
V_72 = F_251 ( V_14 ) ;
if ( V_72 )
return V_72 ;
V_18 = 0 ;
if ( V_14 -> V_19 -> V_20 )
V_18 |= V_21 ;
if ( V_49 & V_271 ) {
V_14 -> V_22 -> V_23 ( V_14 -> V_22 ,
V_14 -> V_269 . V_24 ,
V_14 -> V_25 . V_26 ,
V_16 , V_18 ) ;
}
if ( V_49 & V_272 ) {
struct V_104 * V_273 =
F_109 ( V_14 -> V_22 -> V_2 ) -> V_224 . V_242 ;
V_273 -> V_28 . V_23 ( & V_273 -> V_28 ,
V_14 -> V_269 . V_24 ,
V_14 -> V_25 . V_26 ,
V_16 , V_18 ) ;
}
return 0 ;
}
static void F_253 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_22 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_194 ;
struct V_255 * V_19 = V_14 -> V_19 ;
const T_7 V_29 = F_254 ( T_7 ,
V_19 -> V_28 . V_29 ,
V_14 -> V_25 . V_29 ) ;
if ( V_14 -> V_270 & V_271 ) {
V_14 -> V_22 -> V_27 ( V_14 -> V_22 ,
V_14 -> V_25 . V_26 ,
V_29 ,
true ) ;
}
if ( V_134 -> V_224 . V_242 && V_14 -> V_270 & V_272 ) {
struct V_104 * V_273 = V_134 -> V_224 . V_242 ;
V_273 -> V_28 . V_27 ( & V_273 -> V_28 ,
V_14 -> V_25 . V_26 ,
V_29 ,
true ) ;
}
}
void F_255 ( struct V_255 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_28 . V_2 ;
struct V_133 * V_134 = V_2 -> V_194 ;
bool V_247 ;
V_247 = F_216 ( V_134 ) ;
F_256 ( & V_2 -> V_9 -> V_2 , V_19 -> V_24 -> V_128 , V_19 -> V_24 -> V_256 ,
V_61 ) ;
F_221 ( V_134 , V_247 ) ;
}
static void F_257 ( struct V_274 * V_25 ,
unsigned long V_275 ,
T_12 * V_26 ,
T_12 * V_276 )
{
if ( V_25 -> V_275 != V_275 )
* V_26 += 4096 ;
if ( ! F_210 ( & V_25 -> V_277 ) ) {
V_25 = F_258 ( V_25 -> V_277 . V_278 ,
struct V_274 ,
V_277 ) ;
if ( V_25 -> V_279 && V_25 -> V_275 != V_275 )
* V_276 -= 4096 ;
}
}
static int F_259 ( struct V_1 * V_2 ,
T_12 V_26 ,
T_12 V_230 ,
T_12 V_276 )
{
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
struct V_274 * V_111 ;
struct V_255 * V_19 ;
unsigned long V_280 , V_281 ;
int V_72 ;
F_77 ( V_230 > V_276 ) ;
V_185 -> V_28 . V_26 = V_26 ;
V_185 -> V_28 . V_163 = V_276 - V_26 - V_65 ;
F_195 ( & V_185 -> V_28 , V_134 ) ;
V_185 -> V_28 . V_163 += V_65 ;
if ( F_4 ( V_2 ) ) {
V_72 = F_260 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
if ( ! F_261 ( V_2 ) )
V_185 -> V_28 . V_224 . V_282 = F_257 ;
F_262 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_13 * V_14 = F_263 ( V_19 , & V_185 -> V_28 ) ;
F_264 ( L_27 ,
F_265 ( V_19 ) , V_19 -> V_28 . V_29 ) ;
F_28 ( F_266 ( V_19 ) ) ;
V_72 = F_267 ( & V_185 -> V_28 . V_224 , & V_14 -> V_25 ) ;
if ( V_72 ) {
F_264 ( L_28 , V_72 ) ;
return V_72 ;
}
V_14 -> V_270 |= V_271 ;
F_268 ( V_14 ) ;
F_198 ( & V_14 -> V_283 , & V_185 -> V_28 . V_233 ) ;
}
F_269 (entry, &ggtt->base.mm, hole_start, hole_end) {
F_264 ( L_29 ,
V_280 , V_281 ) ;
V_185 -> V_28 . V_27 ( & V_185 -> V_28 , V_280 ,
V_281 - V_280 , true ) ;
}
V_185 -> V_28 . V_27 ( & V_185 -> V_28 , V_276 - V_65 , V_65 , true ) ;
if ( F_204 ( V_2 ) && ! F_270 ( V_2 ) ) {
struct V_104 * V_105 ;
V_105 = F_40 ( sizeof( * V_105 ) , V_63 ) ;
if ( ! V_105 )
return - V_59 ;
V_72 = F_194 ( V_2 , V_105 ) ;
if ( V_72 ) {
V_105 -> V_28 . V_172 ( & V_105 -> V_28 ) ;
F_43 ( V_105 ) ;
return V_72 ;
}
if ( V_105 -> V_28 . V_173 )
V_72 = V_105 -> V_28 . V_173 ( & V_105 -> V_28 , 0 ,
V_105 -> V_28 . V_163 ) ;
if ( V_72 ) {
V_105 -> V_28 . V_172 ( & V_105 -> V_28 ) ;
F_43 ( V_105 ) ;
return V_72 ;
}
V_105 -> V_28 . V_27 ( & V_105 -> V_28 ,
V_105 -> V_28 . V_26 ,
V_105 -> V_28 . V_163 ,
true ) ;
V_134 -> V_224 . V_242 = V_105 ;
F_28 ( V_185 -> V_28 . V_175 != F_250 ) ;
V_185 -> V_28 . V_175 = F_252 ;
}
return 0 ;
}
void F_271 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
F_259 ( V_2 , 0 , V_185 -> V_230 , V_185 -> V_28 . V_163 ) ;
}
void F_272 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
if ( V_134 -> V_224 . V_242 ) {
struct V_104 * V_105 = V_134 -> V_224 . V_242 ;
V_105 -> V_28 . V_172 ( & V_105 -> V_28 ) ;
}
F_273 ( V_2 ) ;
if ( F_184 ( & V_185 -> V_28 . V_224 ) ) {
if ( F_4 ( V_2 ) )
F_274 () ;
F_212 ( & V_185 -> V_28 . V_224 ) ;
F_211 ( & V_185 -> V_28 . V_234 ) ;
}
V_185 -> V_28 . V_172 ( & V_185 -> V_28 ) ;
}
static unsigned int F_275 ( T_14 V_284 )
{
V_284 >>= V_285 ;
V_284 &= V_286 ;
return V_284 << 20 ;
}
static unsigned int F_276 ( T_14 V_287 )
{
V_287 >>= V_288 ;
V_287 &= V_289 ;
if ( V_287 )
V_287 = 1 << V_287 ;
#ifdef F_277
if ( V_287 > 4 )
V_287 = 4 ;
#endif
return V_287 << 20 ;
}
static unsigned int F_278 ( T_14 V_290 )
{
V_290 >>= V_285 ;
V_290 &= V_286 ;
if ( V_290 )
return 1 << ( 20 + V_290 ) ;
return 0 ;
}
static T_9 F_279 ( T_14 V_284 )
{
V_284 >>= V_291 ;
V_284 &= V_292 ;
return V_284 << 25 ;
}
static T_9 F_280 ( T_14 V_287 )
{
V_287 >>= V_293 ;
V_287 &= V_294 ;
return V_287 << 25 ;
}
static T_9 F_281 ( T_14 V_290 )
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
static T_9 F_282 ( T_14 V_295 )
{
V_295 >>= V_293 ;
V_295 &= V_294 ;
if ( V_295 < 0xf0 )
return V_295 << 25 ;
else
return ( V_295 - 0xf0 + 1 ) << 22 ;
}
static int F_283 ( struct V_1 * V_2 ,
T_9 V_296 )
{
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
struct V_70 * V_85 ;
T_15 V_297 ;
V_297 = F_284 ( V_2 -> V_9 , 0 ) +
( F_285 ( V_2 -> V_9 , 0 ) / 2 ) ;
if ( F_34 ( V_2 ) )
V_185 -> V_186 = F_286 ( V_297 , V_296 ) ;
else
V_185 -> V_186 = F_287 ( V_297 , V_296 ) ;
if ( ! V_185 -> V_186 ) {
F_219 ( L_30 ) ;
return - V_59 ;
}
V_85 = F_39 ( V_2 ) ;
if ( F_106 ( V_85 ) ) {
F_219 ( L_31 ) ;
F_288 ( V_185 -> V_186 ) ;
return F_107 ( V_85 ) ;
}
V_185 -> V_28 . V_85 = V_85 ;
return 0 ;
}
static void F_289 ( struct V_133 * V_134 )
{
T_7 V_298 ;
V_298 = F_290 ( 0 , V_299 | V_300 ) |
F_290 ( 1 , V_301 | V_302 ) |
F_290 ( 2 , V_303 | V_302 ) |
F_290 ( 3 , V_304 ) |
F_290 ( 4 , V_299 | V_302 | F_291 ( 0 ) ) |
F_290 ( 5 , V_299 | V_302 | F_291 ( 1 ) ) |
F_290 ( 6 , V_299 | V_302 | F_291 ( 2 ) ) |
F_290 ( 7 , V_299 | V_302 | F_291 ( 3 ) ) ;
if ( ! F_204 ( V_134 ) )
V_298 = F_290 ( 0 , V_304 ) ;
F_110 ( V_305 , V_298 ) ;
F_110 ( V_306 , V_298 >> 32 ) ;
}
static void F_292 ( struct V_133 * V_134 )
{
T_7 V_298 ;
V_298 = F_290 ( 0 , V_307 ) |
F_290 ( 1 , 0 ) |
F_290 ( 2 , 0 ) |
F_290 ( 3 , 0 ) |
F_290 ( 4 , V_307 ) |
F_290 ( 5 , V_307 ) |
F_290 ( 6 , V_307 ) |
F_290 ( 7 , V_307 ) ;
F_110 ( V_305 , V_298 ) ;
F_110 ( V_306 , V_298 >> 32 ) ;
}
static int F_293 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = V_185 -> V_28 . V_2 ;
struct V_133 * V_134 = F_109 ( V_2 ) ;
T_14 V_284 ;
int V_72 ;
V_185 -> V_308 = F_284 ( V_2 -> V_9 , 2 ) ;
V_185 -> V_230 = F_285 ( V_2 -> V_9 , 2 ) ;
if ( ! F_294 ( V_2 -> V_9 , F_295 ( 39 ) ) )
F_296 ( V_2 -> V_9 , F_295 ( 39 ) ) ;
F_297 ( V_2 -> V_9 , V_309 , & V_284 ) ;
if ( F_2 ( V_2 ) -> V_7 >= 9 ) {
V_185 -> V_310 = F_282 ( V_284 ) ;
V_185 -> V_29 = F_276 ( V_284 ) ;
} else if ( F_33 ( V_2 ) ) {
V_185 -> V_310 = F_281 ( V_284 ) ;
V_185 -> V_29 = F_278 ( V_284 ) ;
} else {
V_185 -> V_310 = F_280 ( V_284 ) ;
V_185 -> V_29 = F_276 ( V_284 ) ;
}
V_185 -> V_28 . V_163 = ( V_185 -> V_29 / sizeof( T_2 ) ) << V_120 ;
if ( F_33 ( V_2 ) || F_34 ( V_2 ) )
F_292 ( V_134 ) ;
else
F_289 ( V_134 ) ;
V_72 = F_283 ( V_2 , V_185 -> V_29 ) ;
V_185 -> V_28 . V_27 = F_243 ;
if ( F_33 ( V_134 ) )
V_185 -> V_28 . V_23 = F_240 ;
else
V_185 -> V_28 . V_23 = F_234 ;
V_185 -> V_28 . V_175 = F_250 ;
V_185 -> V_28 . V_174 = F_253 ;
return V_72 ;
}
static int F_298 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = V_185 -> V_28 . V_2 ;
T_14 V_284 ;
int V_72 ;
V_185 -> V_308 = F_284 ( V_2 -> V_9 , 2 ) ;
V_185 -> V_230 = F_285 ( V_2 -> V_9 , 2 ) ;
if ( ( V_185 -> V_230 < ( 64 << 20 ) || ( V_185 -> V_230 > ( 512 << 20 ) ) ) ) {
F_219 ( L_32 , V_185 -> V_230 ) ;
return - V_311 ;
}
if ( ! F_294 ( V_2 -> V_9 , F_295 ( 40 ) ) )
F_296 ( V_2 -> V_9 , F_295 ( 40 ) ) ;
F_297 ( V_2 -> V_9 , V_309 , & V_284 ) ;
V_185 -> V_310 = F_279 ( V_284 ) ;
V_185 -> V_29 = F_275 ( V_284 ) ;
V_185 -> V_28 . V_163 = ( V_185 -> V_29 / sizeof( T_5 ) ) << V_120 ;
V_72 = F_283 ( V_2 , V_185 -> V_29 ) ;
V_185 -> V_28 . V_27 = F_245 ;
V_185 -> V_28 . V_23 = F_242 ;
V_185 -> V_28 . V_175 = F_250 ;
V_185 -> V_28 . V_174 = F_253 ;
return V_72 ;
}
static void F_299 ( struct V_83 * V_22 )
{
struct V_184 * V_185 = F_152 ( V_22 , struct V_184 , V_28 ) ;
F_288 ( V_185 -> V_186 ) ;
F_46 ( V_22 -> V_2 , V_22 -> V_85 ) ;
}
static int F_300 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = V_185 -> V_28 . V_2 ;
struct V_133 * V_134 = F_109 ( V_2 ) ;
int V_72 ;
V_72 = F_301 ( V_134 -> V_312 , V_134 -> V_2 -> V_9 , NULL ) ;
if ( ! V_72 ) {
F_219 ( L_33 ) ;
return - V_313 ;
}
F_302 ( & V_185 -> V_28 . V_163 , & V_185 -> V_310 ,
& V_185 -> V_308 , & V_185 -> V_230 ) ;
V_185 -> V_248 = F_213 ( V_134 -> V_2 ) ;
V_185 -> V_28 . V_23 = F_246 ;
V_185 -> V_28 . V_27 = F_248 ;
V_185 -> V_28 . V_175 = F_250 ;
V_185 -> V_28 . V_174 = F_253 ;
if ( F_217 ( V_185 -> V_248 ) )
F_6 ( L_34 ) ;
return 0 ;
}
static void F_303 ( struct V_83 * V_22 )
{
F_304 () ;
}
int F_305 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
int V_72 ;
if ( F_2 ( V_2 ) -> V_7 <= 5 ) {
V_185 -> V_314 = F_300 ;
V_185 -> V_28 . V_172 = F_303 ;
} else if ( F_2 ( V_2 ) -> V_7 < 8 ) {
V_185 -> V_314 = F_298 ;
V_185 -> V_28 . V_172 = F_299 ;
if ( F_306 ( V_2 ) )
V_185 -> V_28 . V_86 = F_20 ;
else if ( F_169 ( V_2 ) )
V_185 -> V_28 . V_86 = F_18 ;
else if ( F_7 ( V_2 ) )
V_185 -> V_28 . V_86 = F_17 ;
else if ( F_2 ( V_2 ) -> V_7 >= 7 )
V_185 -> V_28 . V_86 = F_16 ;
else
V_185 -> V_28 . V_86 = F_13 ;
} else {
V_185 -> V_314 = F_293 ;
V_185 -> V_28 . V_172 = F_299 ;
}
V_185 -> V_28 . V_2 = V_2 ;
V_185 -> V_28 . V_315 = true ;
V_72 = V_185 -> V_314 ( V_185 ) ;
if ( V_72 )
return V_72 ;
if ( ( V_185 -> V_28 . V_163 - 1 ) >> 32 ) {
F_219 ( L_35
L_36 ,
V_185 -> V_28 . V_163 >> 20 ) ;
V_185 -> V_28 . V_163 = 1ULL << 32 ;
V_185 -> V_230 = F_307 ( V_185 -> V_230 , V_185 -> V_28 . V_163 ) ;
}
V_72 = F_308 ( V_2 ) ;
if ( V_72 )
goto V_316;
F_6 ( L_37 ,
V_185 -> V_28 . V_163 >> 20 ) ;
F_8 ( L_38 , V_185 -> V_230 >> 20 ) ;
F_8 ( L_39 , V_185 -> V_310 >> 20 ) ;
#ifdef F_5
if ( V_8 )
F_6 ( L_40 ) ;
#endif
V_11 . V_3 = F_1 ( V_2 , V_11 . V_3 ) ;
F_8 ( L_41 , V_11 . V_3 ) ;
return 0 ;
V_316:
V_185 -> V_28 . V_172 ( & V_185 -> V_28 ) ;
return V_72 ;
}
int F_309 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) -> V_7 < 6 && ! F_310 () )
return - V_313 ;
return 0 ;
}
void F_311 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
struct V_255 * V_19 ;
struct V_13 * V_14 ;
bool V_188 ;
F_222 ( V_2 ) ;
V_185 -> V_28 . V_27 ( & V_185 -> V_28 , V_185 -> V_28 . V_26 , V_185 -> V_28 . V_163 ,
true ) ;
F_262 (obj, &dev_priv->mm.bound_list, global_list) {
V_188 = false ;
F_262 (vma, &obj->vma_list, obj_link) {
if ( V_14 -> V_22 != & V_185 -> V_28 )
continue;
F_28 ( F_312 ( V_14 , V_19 -> V_16 ,
V_317 ) ) ;
V_188 = true ;
}
if ( V_188 )
F_313 ( V_19 , V_19 -> V_318 ) ;
}
if ( F_2 ( V_2 ) -> V_7 >= 8 ) {
if ( F_33 ( V_2 ) || F_34 ( V_2 ) )
F_292 ( V_134 ) ;
else
F_289 ( V_134 ) ;
return;
}
if ( F_204 ( V_2 ) ) {
struct V_83 * V_22 ;
F_262 (vm, &dev_priv->vm_list, global_link) {
struct V_104 * V_105 ;
if ( V_22 -> V_315 )
V_105 = V_134 -> V_224 . V_242 ;
else
V_105 = F_91 ( V_22 ) ;
F_154 ( V_134 , & V_105 -> V_88 ,
0 , V_105 -> V_28 . V_163 ) ;
}
}
F_226 ( V_134 ) ;
}
static struct V_13 *
F_314 ( struct V_255 * V_19 ,
struct V_83 * V_22 ,
const struct V_319 * V_269 )
{
struct V_13 * V_14 ;
if ( F_28 ( F_315 ( V_22 ) != ! ! V_269 ) )
return F_41 ( - V_62 ) ;
V_14 = F_316 ( F_109 ( V_19 -> V_28 . V_2 ) -> V_320 , V_63 ) ;
if ( V_14 == NULL )
return F_41 ( - V_59 ) ;
F_197 ( & V_14 -> V_283 ) ;
F_197 ( & V_14 -> V_321 ) ;
F_197 ( & V_14 -> V_322 ) ;
V_14 -> V_22 = V_22 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_315 = F_315 ( V_22 ) ;
if ( F_315 ( V_22 ) )
V_14 -> V_269 = * V_269 ;
else
F_317 ( F_91 ( V_22 ) ) ;
F_198 ( & V_14 -> V_321 , & V_19 -> V_323 ) ;
return V_14 ;
}
struct V_13 *
F_318 ( struct V_255 * V_19 ,
struct V_83 * V_22 )
{
struct V_13 * V_14 ;
V_14 = F_263 ( V_19 , V_22 ) ;
if ( ! V_14 )
V_14 = F_314 ( V_19 , V_22 ,
F_315 ( V_22 ) ? & V_324 : NULL ) ;
return V_14 ;
}
struct V_13 *
F_319 ( struct V_255 * V_19 ,
const struct V_319 * V_325 )
{
struct V_1 * V_2 = V_19 -> V_28 . V_2 ;
struct V_133 * V_134 = F_109 ( V_2 ) ;
struct V_184 * V_185 = & V_134 -> V_185 ;
struct V_13 * V_14 = F_320 ( V_19 , V_325 ) ;
if ( ! V_14 )
V_14 = F_314 ( V_19 , & V_185 -> V_28 , V_325 ) ;
return V_14 ;
}
static struct V_326 *
F_321 ( const T_3 * V_327 , unsigned int V_328 ,
unsigned int V_329 , unsigned int V_330 ,
unsigned int V_331 ,
struct V_127 * V_257 , struct V_326 * V_260 )
{
unsigned int V_332 , V_333 ;
unsigned int V_334 ;
for ( V_332 = 0 ; V_332 < V_329 ; V_332 ++ ) {
V_334 = V_331 * ( V_330 - 1 ) + V_332 ;
for ( V_333 = 0 ; V_333 < V_330 ; V_333 ++ ) {
V_257 -> V_256 ++ ;
F_322 ( V_260 , NULL , V_65 , 0 ) ;
F_236 ( V_260 ) = V_327 [ V_328 + V_334 ] ;
F_323 ( V_260 ) = V_65 ;
V_260 = F_324 ( V_260 ) ;
V_334 -= V_331 ;
}
}
return V_260 ;
}
static struct V_127 *
F_325 ( struct V_335 * V_336 ,
struct V_255 * V_19 )
{
unsigned int V_337 = V_336 -> V_338 [ 0 ] . V_329 * V_336 -> V_338 [ 0 ] . V_330 ;
unsigned int V_339 ;
struct V_125 V_126 ;
unsigned long V_67 ;
T_3 * V_340 ;
struct V_127 * V_257 ;
unsigned int V_341 ;
struct V_326 * V_260 ;
int V_72 = - V_59 ;
V_340 = F_326 ( V_19 -> V_28 . V_29 / V_65 ,
sizeof( T_3 ) ,
V_154 ) ;
if ( ! V_340 )
return F_41 ( V_72 ) ;
if ( V_336 -> V_342 == V_343 )
V_339 = V_336 -> V_338 [ 1 ] . V_329 * V_336 -> V_338 [ 1 ] . V_330 ;
else
V_339 = 0 ;
V_257 = F_327 ( sizeof( * V_257 ) , V_63 ) ;
if ( ! V_257 )
goto V_344;
V_72 = F_328 ( V_257 , V_337 + V_339 , V_63 ) ;
if ( V_72 )
goto V_345;
V_67 = 0 ;
F_173 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_340 [ V_67 ] = F_99 ( & V_126 ) ;
V_67 ++ ;
}
V_257 -> V_256 = 0 ;
V_260 = V_257 -> V_128 ;
V_260 = F_321 ( V_340 , 0 ,
V_336 -> V_338 [ 0 ] . V_329 , V_336 -> V_338 [ 0 ] . V_330 ,
V_336 -> V_338 [ 0 ] . V_329 ,
V_257 , V_260 ) ;
if ( V_336 -> V_342 == V_343 ) {
V_341 = V_337 ;
if ( F_329 ( V_336 -> V_346 ) )
V_341 -- ;
V_336 -> V_341 = V_341 ;
V_260 = F_321 ( V_340 , V_336 -> V_341 ,
V_336 -> V_338 [ 1 ] . V_329 , V_336 -> V_338 [ 1 ] . V_330 ,
V_336 -> V_338 [ 1 ] . V_329 ,
V_257 , V_260 ) ;
}
F_264 ( L_42 ,
V_19 -> V_28 . V_29 , V_336 -> V_338 [ 0 ] . V_329 ,
V_336 -> V_338 [ 0 ] . V_330 , V_337 + V_339 ,
V_337 ) ;
F_330 ( V_340 ) ;
return V_257 ;
V_345:
F_43 ( V_257 ) ;
V_344:
F_330 ( V_340 ) ;
F_264 ( L_43 ,
V_19 -> V_28 . V_29 , V_72 , V_336 -> V_338 [ 0 ] . V_329 ,
V_336 -> V_338 [ 0 ] . V_330 , V_337 + V_339 ,
V_337 ) ;
return F_41 ( V_72 ) ;
}
static struct V_127 *
F_331 ( const struct V_319 * V_325 ,
struct V_255 * V_19 )
{
struct V_127 * V_257 ;
struct V_326 * V_260 ;
struct V_125 V_347 ;
int V_72 = - V_59 ;
V_257 = F_327 ( sizeof( * V_257 ) , V_63 ) ;
if ( ! V_257 )
goto V_344;
V_72 = F_328 ( V_257 , V_325 -> V_348 . V_349 . V_29 , V_63 ) ;
if ( V_72 )
goto V_345;
V_260 = V_257 -> V_128 ;
V_257 -> V_256 = 0 ;
F_173 (obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if ( V_257 -> V_256 >= V_325 -> V_348 . V_349 . V_29 )
break;
F_322 ( V_260 , NULL , V_65 , 0 ) ;
F_236 ( V_260 ) = F_99 ( & V_347 ) ;
F_323 ( V_260 ) = V_65 ;
V_260 = F_324 ( V_260 ) ;
V_257 -> V_256 ++ ;
}
return V_257 ;
V_345:
F_43 ( V_257 ) ;
V_344:
return F_41 ( V_72 ) ;
}
static int
F_251 ( struct V_13 * V_14 )
{
int V_72 = 0 ;
if ( V_14 -> V_269 . V_24 )
return 0 ;
if ( V_14 -> V_269 . type == V_350 )
V_14 -> V_269 . V_24 = V_14 -> V_19 -> V_24 ;
else if ( V_14 -> V_269 . type == V_351 )
V_14 -> V_269 . V_24 =
F_325 ( & V_14 -> V_269 . V_348 . V_352 , V_14 -> V_19 ) ;
else if ( V_14 -> V_269 . type == V_353 )
V_14 -> V_269 . V_24 =
F_331 ( & V_14 -> V_269 , V_14 -> V_19 ) ;
else
F_332 ( 1 , L_44 ,
V_14 -> V_269 . type ) ;
if ( ! V_14 -> V_269 . V_24 ) {
F_219 ( L_45 ,
V_14 -> V_269 . type ) ;
V_72 = - V_62 ;
} else if ( F_106 ( V_14 -> V_269 . V_24 ) ) {
V_72 = F_107 ( V_14 -> V_269 . V_24 ) ;
V_14 -> V_269 . V_24 = NULL ;
F_219 ( L_46 ,
V_14 -> V_269 . type , V_72 ) ;
}
return V_72 ;
}
int F_312 ( struct V_13 * V_14 , enum V_15 V_16 ,
T_1 V_49 )
{
int V_72 ;
T_1 V_354 ;
if ( F_28 ( V_49 == 0 ) )
return - V_62 ;
V_354 = 0 ;
if ( V_49 & V_355 )
V_354 |= V_271 ;
if ( V_49 & V_356 )
V_354 |= V_272 ;
if ( V_49 & V_317 )
V_354 |= V_14 -> V_270 ;
else
V_354 &= ~ V_14 -> V_270 ;
if ( V_354 == 0 )
return 0 ;
if ( V_14 -> V_270 == 0 && V_14 -> V_22 -> V_173 ) {
V_14 -> V_357 ++ ;
F_333 ( V_14 ) ;
V_72 = V_14 -> V_22 -> V_173 ( V_14 -> V_22 ,
V_14 -> V_25 . V_26 ,
V_14 -> V_25 . V_29 ) ;
V_14 -> V_357 -- ;
if ( V_72 )
return V_72 ;
}
V_72 = V_14 -> V_22 -> V_175 ( V_14 , V_16 , V_354 ) ;
if ( V_72 )
return V_72 ;
V_14 -> V_270 |= V_354 ;
return 0 ;
}
T_9
F_334 ( struct V_255 * V_19 ,
const struct V_319 * V_325 )
{
if ( V_325 -> type == V_350 ) {
return V_19 -> V_28 . V_29 ;
} else if ( V_325 -> type == V_351 ) {
return F_335 ( & V_325 -> V_348 . V_352 ) << V_120 ;
} else if ( V_325 -> type == V_353 ) {
return V_325 -> V_348 . V_349 . V_29 << V_120 ;
} else {
F_332 ( 1 , L_44 , V_325 -> type ) ;
return V_19 -> V_28 . V_29 ;
}
}
