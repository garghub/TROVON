static int F_1 ( struct V_1 * V_2 , int V_3 )
{
bool V_4 ;
bool V_5 ;
V_4 = F_2 ( V_2 ) -> V_6 >= 6 ;
V_5 = F_2 ( V_2 ) -> V_6 >= 7 ;
if ( F_3 ( V_2 ) )
V_5 = false ;
if ( F_2 ( V_2 ) -> V_6 < 9 &&
( V_3 == 0 || ! V_4 ) )
return 0 ;
if ( V_3 == 1 )
return 1 ;
if ( V_3 == 2 && V_5 )
return 2 ;
#ifdef F_4
if ( F_2 ( V_2 ) -> V_6 == 6 && V_7 ) {
F_5 ( L_1 ) ;
return 0 ;
}
#endif
if ( F_6 ( V_2 ) && ! F_7 ( V_2 ) &&
V_2 -> V_8 -> V_9 < 0xb ) {
F_8 ( L_2 ) ;
return 0 ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 && V_10 . V_11 )
return 2 ;
else
return V_4 ? 1 : 0 ;
}
static int F_9 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
T_1 V_16 )
{
T_1 V_17 = 0 ;
if ( V_13 -> V_18 -> V_19 )
V_17 |= V_20 ;
V_13 -> V_21 -> V_22 ( V_13 -> V_21 , V_13 -> V_18 -> V_23 , V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
return 0 ;
}
static void F_10 ( struct V_12 * V_13 )
{
V_13 -> V_21 -> V_26 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_18 -> V_27 . V_28 ,
true ) ;
}
static T_2 F_11 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 )
{
T_2 V_32 = V_31 ? V_33 | V_34 : 0 ;
V_32 |= V_29 ;
switch ( V_30 ) {
case V_35 :
V_32 |= V_36 ;
break;
case V_37 :
V_32 |= V_38 ;
break;
default:
V_32 |= V_39 ;
break;
}
return V_32 ;
}
static T_4 F_12 ( const T_3 V_29 ,
const enum V_14 V_30 )
{
T_4 V_40 = V_33 | V_34 ;
V_40 |= V_29 ;
if ( V_30 != V_35 )
V_40 |= V_41 ;
else
V_40 |= V_36 ;
return V_40 ;
}
static T_5 F_13 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_14 ( V_29 ) ;
switch ( V_30 ) {
case V_43 :
case V_44 :
V_32 |= V_45 ;
break;
case V_35 :
V_32 |= V_46 ;
break;
default:
F_15 ( V_30 ) ;
}
return V_32 ;
}
static T_5 F_16 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_14 ( V_29 ) ;
switch ( V_30 ) {
case V_43 :
V_32 |= V_47 ;
break;
case V_44 :
V_32 |= V_45 ;
break;
case V_35 :
V_32 |= V_46 ;
break;
default:
F_15 ( V_30 ) ;
}
return V_32 ;
}
static T_5 F_17 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_48 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_14 ( V_29 ) ;
if ( ! ( V_48 & V_20 ) )
V_32 |= V_49 ;
if ( V_30 != V_35 )
V_32 |= V_50 ;
return V_32 ;
}
static T_5 F_18 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_19 ( V_29 ) ;
if ( V_30 != V_35 )
V_32 |= V_51 ;
return V_32 ;
}
static T_5 F_20 ( T_3 V_29 ,
enum V_14 V_30 ,
bool V_31 , T_1 V_16 )
{
T_5 V_32 = V_31 ? V_42 : 0 ;
V_32 |= F_19 ( V_29 ) ;
switch ( V_30 ) {
case V_35 :
break;
case V_37 :
V_32 |= V_52 ;
break;
default:
V_32 |= V_53 ;
break;
}
return V_32 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_54 * V_55 , T_6 V_48 )
{
struct V_56 * V_56 = & V_2 -> V_8 -> V_2 ;
V_55 -> V_57 = F_22 ( V_48 ) ;
if ( ! V_55 -> V_57 )
return - V_58 ;
V_55 -> V_59 = F_23 ( V_56 ,
V_55 -> V_57 , 0 , 4096 , V_60 ) ;
if ( F_24 ( V_56 , V_55 -> V_59 ) ) {
F_25 ( V_55 -> V_57 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
return F_21 ( V_2 , V_55 , V_62 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
if ( F_28 ( ! V_55 -> V_57 ) )
return;
F_29 ( & V_2 -> V_8 -> V_2 , V_55 -> V_59 , 4096 , V_60 ) ;
F_25 ( V_55 -> V_57 ) ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
}
static void * F_30 ( struct V_54 * V_55 )
{
return F_31 ( V_55 -> V_57 ) ;
}
static void F_32 ( struct V_1 * V_2 , void * V_63 )
{
if ( F_7 ( V_2 ) || F_33 ( V_2 ) )
F_34 ( V_63 , V_64 ) ;
F_35 ( V_63 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_54 * V_55 ,
const T_7 V_65 )
{
int V_66 ;
T_7 * const V_63 = F_30 ( V_55 ) ;
for ( V_66 = 0 ; V_66 < 512 ; V_66 ++ )
V_63 [ V_66 ] = V_65 ;
F_32 ( V_2 , V_63 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_54 * V_55 ,
const T_8 V_67 )
{
T_7 V_68 = V_67 ;
V_68 = V_68 << 32 | V_67 ;
F_36 ( V_2 , V_55 , V_68 ) ;
}
static struct V_69 * F_38 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
int V_71 ;
V_70 = F_39 ( sizeof( * V_70 ) , V_62 ) ;
if ( V_70 == NULL )
return F_40 ( - V_58 ) ;
V_71 = F_21 ( V_2 , F_41 ( V_70 ) , V_72 | V_73 ) ;
if ( V_71 ) {
F_42 ( V_70 ) ;
return F_40 ( V_71 ) ;
}
F_43 ( F_44 ( V_70 ) , 1 ) ;
return V_70 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
F_46 ( F_44 ( V_70 ) , 1 ) ;
F_47 ( V_2 , V_70 ) ;
F_42 ( V_70 ) ;
}
static struct V_74 * F_48 ( struct V_1 * V_2 )
{
struct V_74 * V_75 ;
const T_9 V_76 = F_2 ( V_2 ) -> V_6 >= 8 ?
V_77 : V_78 ;
int V_71 = - V_58 ;
V_75 = F_39 ( sizeof( * V_75 ) , V_62 ) ;
if ( ! V_75 )
return F_40 ( - V_58 ) ;
V_75 -> V_79 = F_49 ( F_50 ( V_76 ) , sizeof( * V_75 -> V_79 ) ,
V_62 ) ;
if ( ! V_75 -> V_79 )
goto V_80;
V_71 = F_51 ( V_2 , V_75 ) ;
if ( V_71 )
goto V_81;
return V_75 ;
V_81:
F_42 ( V_75 -> V_79 ) ;
V_80:
F_42 ( V_75 ) ;
return F_40 ( V_71 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
F_47 ( V_2 , V_75 ) ;
F_42 ( V_75 -> V_79 ) ;
F_42 ( V_75 ) ;
}
static void F_53 ( struct V_82 * V_21 ,
struct V_74 * V_75 )
{
T_2 V_83 ;
V_83 = F_11 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true ) ;
F_55 ( V_21 -> V_2 , V_75 , V_83 ) ;
}
static void F_56 ( struct V_82 * V_21 ,
struct V_74 * V_75 )
{
T_5 V_83 ;
F_28 ( F_54 ( V_21 -> V_84 ) == 0 ) ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true , 0 ) ;
F_57 ( V_21 -> V_2 , V_75 , V_83 ) ;
}
static struct V_86 * F_58 ( struct V_1 * V_2 )
{
struct V_86 * V_87 ;
int V_71 = - V_58 ;
V_87 = F_39 ( sizeof( * V_87 ) , V_62 ) ;
if ( ! V_87 )
return F_40 ( - V_58 ) ;
V_87 -> V_88 = F_49 ( F_50 ( V_89 ) ,
sizeof( * V_87 -> V_88 ) , V_62 ) ;
if ( ! V_87 -> V_88 )
goto V_80;
V_71 = F_51 ( V_2 , V_87 ) ;
if ( V_71 )
goto V_81;
return V_87 ;
V_81:
F_42 ( V_87 -> V_88 ) ;
V_80:
F_42 ( V_87 ) ;
return F_40 ( V_71 ) ;
}
static void F_59 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
if ( F_44 ( V_87 ) ) {
F_47 ( V_2 , V_87 ) ;
F_42 ( V_87 -> V_88 ) ;
F_42 ( V_87 ) ;
}
}
static void F_60 ( struct V_82 * V_21 ,
struct V_86 * V_87 )
{
T_4 V_90 ;
V_90 = F_12 ( F_54 ( V_21 -> V_91 ) , V_44 ) ;
F_55 ( V_21 -> V_2 , V_87 , V_90 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
T_9 V_94 = F_62 ( V_2 ) ;
V_93 -> V_95 = F_49 ( F_50 ( V_94 ) ,
sizeof( unsigned long ) ,
V_62 ) ;
if ( ! V_93 -> V_95 )
return - V_58 ;
V_93 -> V_96 = F_49 ( V_94 , sizeof( * V_93 -> V_96 ) ,
V_62 ) ;
if ( ! V_93 -> V_96 ) {
F_42 ( V_93 -> V_95 ) ;
V_93 -> V_95 = NULL ;
return - V_58 ;
}
return 0 ;
}
static void F_63 ( struct V_92 * V_93 )
{
F_42 ( V_93 -> V_95 ) ;
F_42 ( V_93 -> V_96 ) ;
V_93 -> V_96 = NULL ;
}
static struct
V_92 * F_64 ( struct V_1 * V_2 )
{
struct V_92 * V_93 ;
int V_71 = - V_58 ;
F_28 ( ! F_65 ( V_2 ) ) ;
V_93 = F_39 ( sizeof( * V_93 ) , V_62 ) ;
if ( ! V_93 )
return F_40 ( - V_58 ) ;
V_71 = F_61 ( V_2 , V_93 ) ;
if ( V_71 )
goto V_80;
V_71 = F_51 ( V_2 , V_93 ) ;
if ( V_71 )
goto V_81;
return V_93 ;
V_81:
F_63 ( V_93 ) ;
V_80:
F_42 ( V_93 ) ;
return F_40 ( V_71 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
F_63 ( V_93 ) ;
if ( F_65 ( V_2 ) ) {
F_47 ( V_2 , V_93 ) ;
F_42 ( V_93 ) ;
}
}
static void F_67 ( struct V_82 * V_21 ,
struct V_92 * V_93 )
{
T_10 V_97 ;
V_97 = F_68 ( F_54 ( V_21 -> V_98 ) , V_44 ) ;
F_55 ( V_21 -> V_2 , V_93 , V_97 ) ;
}
static void F_69 ( struct V_82 * V_21 ,
struct V_99 * V_100 )
{
T_11 V_101 ;
V_101 = F_70 ( F_54 ( V_21 -> V_102 ) ,
V_44 ) ;
F_55 ( V_21 -> V_2 , V_100 , V_101 ) ;
}
static void
F_71 ( struct V_103 * V_104 ,
struct V_92 * V_93 ,
struct V_86 * V_87 ,
int V_105 )
{
T_10 * V_106 ;
if ( ! F_65 ( V_104 -> V_27 . V_2 ) )
return;
V_106 = F_72 ( V_93 ) ;
V_106 [ V_105 ] = F_68 ( F_54 ( V_87 ) , V_44 ) ;
F_73 ( V_104 , V_106 ) ;
}
static void
F_74 ( struct V_103 * V_104 ,
struct V_99 * V_100 ,
struct V_92 * V_93 ,
int V_105 )
{
T_11 * V_107 = F_72 ( V_100 ) ;
F_28 ( ! F_65 ( V_104 -> V_27 . V_2 ) ) ;
V_107 [ V_105 ] = F_70 ( F_54 ( V_93 ) , V_44 ) ;
F_73 ( V_104 , V_107 ) ;
}
static int F_75 ( struct V_108 * V_109 ,
unsigned V_110 ,
T_3 V_29 )
{
struct V_111 * V_112 = V_109 -> V_112 ;
int V_71 ;
F_76 ( V_110 >= 4 ) ;
V_71 = F_77 ( V_109 , 6 ) ;
if ( V_71 )
return V_71 ;
F_78 ( V_112 , F_79 ( 1 ) ) ;
F_78 ( V_112 , F_80 ( V_112 , V_110 ) ) ;
F_78 ( V_112 , F_81 ( V_29 ) ) ;
F_78 ( V_112 , F_79 ( 1 ) ) ;
F_78 ( V_112 , F_82 ( V_112 , V_110 ) ) ;
F_78 ( V_112 , F_83 ( V_29 ) ) ;
F_84 ( V_112 ) ;
return 0 ;
}
static int F_85 ( struct V_103 * V_104 ,
struct V_108 * V_109 )
{
int V_66 , V_71 ;
for ( V_66 = V_113 - 1 ; V_66 >= 0 ; V_66 -- ) {
const T_3 V_114 = F_86 ( V_104 , V_66 ) ;
V_71 = F_75 ( V_109 , V_66 , V_114 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
static int F_87 ( struct V_103 * V_104 ,
struct V_108 * V_109 )
{
return F_75 ( V_109 , 0 , F_54 ( & V_104 -> V_100 ) ) ;
}
static void F_88 ( struct V_82 * V_21 ,
struct V_92 * V_93 ,
T_7 V_25 ,
T_7 V_115 ,
T_2 V_83 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
T_2 * V_116 ;
unsigned V_117 = F_90 ( V_25 ) ;
unsigned V_40 = F_91 ( V_25 ) ;
unsigned V_32 = F_92 ( V_25 ) ;
unsigned V_118 = V_115 >> V_119 ;
unsigned V_120 , V_66 ;
if ( F_28 ( ! V_93 ) )
return;
while ( V_118 ) {
struct V_86 * V_87 ;
struct V_74 * V_75 ;
if ( F_28 ( ! V_93 -> V_96 [ V_117 ] ) )
break;
V_87 = V_93 -> V_96 [ V_117 ] ;
if ( F_28 ( ! V_87 -> V_121 [ V_40 ] ) )
break;
V_75 = V_87 -> V_121 [ V_40 ] ;
if ( F_28 ( ! F_44 ( V_75 ) ) )
break;
V_120 = V_32 + V_118 ;
if ( V_120 > V_77 )
V_120 = V_77 ;
V_116 = F_72 ( V_75 ) ;
for ( V_66 = V_32 ; V_66 < V_120 ; V_66 ++ ) {
V_116 [ V_66 ] = V_83 ;
V_118 -- ;
}
F_73 ( V_104 , V_75 ) ;
V_32 = 0 ;
if ( ++ V_40 == V_89 ) {
if ( ++ V_117 == F_62 ( V_21 -> V_2 ) )
break;
V_40 = 0 ;
}
}
}
static void F_93 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_115 ,
bool V_122 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
T_2 V_83 = F_11 ( F_54 ( V_21 -> V_84 ) ,
V_44 , V_122 ) ;
if ( ! F_65 ( V_21 -> V_2 ) ) {
F_88 ( V_21 , & V_104 -> V_93 , V_25 , V_115 ,
V_83 ) ;
} else {
T_7 V_123 , V_124 ;
struct V_92 * V_93 ;
F_94 (pdp, &ppgtt->pml4, start, length, templ4, pml4e) {
F_88 ( V_21 , V_93 , V_25 , V_115 ,
V_83 ) ;
}
}
}
static void
F_95 ( struct V_82 * V_21 ,
struct V_92 * V_93 ,
struct V_125 * V_126 ,
T_7 V_25 ,
enum V_14 V_15 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
T_2 * V_116 ;
unsigned V_117 = F_90 ( V_25 ) ;
unsigned V_40 = F_91 ( V_25 ) ;
unsigned V_32 = F_92 ( V_25 ) ;
V_116 = NULL ;
while ( F_96 ( V_126 ) ) {
if ( V_116 == NULL ) {
struct V_86 * V_87 = V_93 -> V_96 [ V_117 ] ;
struct V_74 * V_75 = V_87 -> V_121 [ V_40 ] ;
V_116 = F_72 ( V_75 ) ;
}
V_116 [ V_32 ] =
F_11 ( F_97 ( V_126 ) ,
V_15 , true ) ;
if ( ++ V_32 == V_77 ) {
F_73 ( V_104 , V_116 ) ;
V_116 = NULL ;
if ( ++ V_40 == V_89 ) {
if ( ++ V_117 == F_62 ( V_21 -> V_2 ) )
break;
V_40 = 0 ;
}
V_32 = 0 ;
}
}
if ( V_116 )
F_73 ( V_104 , V_116 ) ;
}
static void F_98 ( struct V_82 * V_21 ,
struct V_127 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 ,
T_1 V_16 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
struct V_125 V_126 ;
F_99 ( & V_126 , V_23 -> V_128 , F_100 ( V_23 -> V_128 ) , 0 ) ;
if ( ! F_65 ( V_21 -> V_2 ) ) {
F_95 ( V_21 , & V_104 -> V_93 , & V_126 , V_25 ,
V_15 ) ;
} else {
struct V_92 * V_93 ;
T_7 V_123 , V_124 ;
T_7 V_115 = ( T_7 ) V_23 -> V_129 << V_119 ;
F_94 (pdp, &ppgtt->pml4, start, length, templ4, pml4e) {
F_95 ( V_21 , V_93 , & V_126 ,
V_25 , V_15 ) ;
}
}
}
static void F_101 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
int V_66 ;
if ( ! F_44 ( V_87 ) )
return;
F_102 (i, pd->used_pdes, I915_PDES) {
if ( F_28 ( ! V_87 -> V_121 [ V_66 ] ) )
continue;
F_52 ( V_2 , V_87 -> V_121 [ V_66 ] ) ;
V_87 -> V_121 [ V_66 ] = NULL ;
}
}
static int F_103 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
V_21 -> V_84 = F_38 ( V_2 ) ;
if ( F_104 ( V_21 -> V_84 ) )
return F_105 ( V_21 -> V_84 ) ;
V_21 -> V_91 = F_48 ( V_2 ) ;
if ( F_104 ( V_21 -> V_91 ) ) {
F_45 ( V_2 , V_21 -> V_84 ) ;
return F_105 ( V_21 -> V_91 ) ;
}
V_21 -> V_98 = F_58 ( V_2 ) ;
if ( F_104 ( V_21 -> V_98 ) ) {
F_52 ( V_2 , V_21 -> V_91 ) ;
F_45 ( V_2 , V_21 -> V_84 ) ;
return F_105 ( V_21 -> V_98 ) ;
}
if ( F_65 ( V_2 ) ) {
V_21 -> V_102 = F_64 ( V_2 ) ;
if ( F_104 ( V_21 -> V_102 ) ) {
F_59 ( V_2 , V_21 -> V_98 ) ;
F_52 ( V_2 , V_21 -> V_91 ) ;
F_45 ( V_2 , V_21 -> V_84 ) ;
return F_105 ( V_21 -> V_102 ) ;
}
}
F_53 ( V_21 , V_21 -> V_91 ) ;
F_60 ( V_21 , V_21 -> V_98 ) ;
if ( F_65 ( V_2 ) )
F_67 ( V_21 , V_21 -> V_102 ) ;
return 0 ;
}
static int F_106 ( struct V_103 * V_104 , bool V_130 )
{
enum V_131 V_132 ;
struct V_1 * V_2 = V_104 -> V_27 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
unsigned int V_136 = F_107 ( V_137 ) ;
int V_66 ;
if ( F_65 ( V_2 ) ) {
T_12 V_59 = F_54 ( & V_104 -> V_100 ) ;
F_108 ( V_136 , F_83 ( V_59 ) ) ;
F_108 ( V_136 + 4 , F_81 ( V_59 ) ) ;
V_132 = ( V_130 ? V_138 :
V_139 ) ;
} else {
for ( V_66 = 0 ; V_66 < V_113 ; V_66 ++ ) {
T_12 V_59 = F_86 ( V_104 , V_66 ) ;
F_108 ( V_136 , F_83 ( V_59 ) ) ;
F_108 ( V_136 + 4 , F_81 ( V_59 ) ) ;
V_136 += 8 ;
}
V_132 = ( V_130 ? V_140 :
V_141 ) ;
}
F_108 ( F_107 ( V_142 ) , V_132 ) ;
return 0 ;
}
static void F_109 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
if ( F_65 ( V_2 ) )
F_66 ( V_2 , V_21 -> V_102 ) ;
F_59 ( V_2 , V_21 -> V_98 ) ;
F_52 ( V_2 , V_21 -> V_91 ) ;
F_45 ( V_2 , V_21 -> V_84 ) ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
int V_66 ;
F_102 (i, pdp->used_pdpes, I915_PDPES_PER_PDP(dev)) {
if ( F_28 ( ! V_93 -> V_96 [ V_66 ] ) )
continue;
F_101 ( V_2 , V_93 -> V_96 [ V_66 ] ) ;
F_59 ( V_2 , V_93 -> V_96 [ V_66 ] ) ;
}
F_66 ( V_2 , V_93 ) ;
}
static void F_111 ( struct V_103 * V_104 )
{
int V_66 ;
F_102 (i, ppgtt->pml4.used_pml4es, GEN8_PML4ES_PER_PML4) {
if ( F_28 ( ! V_104 -> V_100 . V_143 [ V_66 ] ) )
continue;
F_110 ( V_104 -> V_27 . V_2 , V_104 -> V_100 . V_143 [ V_66 ] ) ;
}
F_47 ( V_104 -> V_27 . V_2 , & V_104 -> V_100 ) ;
}
static void F_112 ( struct V_82 * V_21 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
if ( F_3 ( V_21 -> V_2 ) )
F_106 ( V_104 , false ) ;
if ( ! F_65 ( V_104 -> V_27 . V_2 ) )
F_110 ( V_104 -> V_27 . V_2 , & V_104 -> V_93 ) ;
else
F_111 ( V_104 ) ;
F_109 ( V_21 ) ;
}
static int F_113 ( struct V_82 * V_21 ,
struct V_86 * V_87 ,
T_7 V_25 ,
T_7 V_115 ,
unsigned long * V_144 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_74 * V_75 ;
T_7 V_145 ;
T_8 V_40 ;
F_114 (pt, pd, start, length, temp, pde) {
if ( F_115 ( V_40 , V_87 -> V_88 ) ) {
F_28 ( V_75 == V_21 -> V_91 ) ;
continue;
}
V_75 = F_48 ( V_2 ) ;
if ( F_104 ( V_75 ) )
goto V_146;
F_53 ( V_21 , V_75 ) ;
V_87 -> V_121 [ V_40 ] = V_75 ;
F_116 ( V_40 , V_144 ) ;
F_117 ( V_21 , V_40 , V_25 , V_147 ) ;
}
return 0 ;
V_146:
F_102 (pde, new_pts, I915_PDES)
F_52 ( V_2 , V_87 -> V_121 [ V_40 ] ) ;
return - V_58 ;
}
static int
F_118 ( struct V_82 * V_21 ,
struct V_92 * V_93 ,
T_7 V_25 ,
T_7 V_115 ,
unsigned long * V_148 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_86 * V_87 ;
T_7 V_145 ;
T_8 V_117 ;
T_8 V_94 = F_62 ( V_2 ) ;
F_28 ( ! F_119 ( V_148 , V_94 ) ) ;
F_120 (pd, pdp, start, length, temp, pdpe) {
if ( F_115 ( V_117 , V_93 -> V_95 ) )
continue;
V_87 = F_58 ( V_2 ) ;
if ( F_104 ( V_87 ) )
goto V_146;
F_60 ( V_21 , V_87 ) ;
V_93 -> V_96 [ V_117 ] = V_87 ;
F_116 ( V_117 , V_148 ) ;
F_121 ( V_21 , V_117 , V_25 , V_149 ) ;
}
return 0 ;
V_146:
F_102 (pdpe, new_pds, pdpes)
F_59 ( V_2 , V_93 -> V_96 [ V_117 ] ) ;
return - V_58 ;
}
static int
F_122 ( struct V_82 * V_21 ,
struct V_99 * V_100 ,
T_7 V_25 ,
T_7 V_115 ,
unsigned long * V_150 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_92 * V_93 ;
T_7 V_145 ;
T_8 V_124 ;
F_28 ( ! F_119 ( V_150 , V_151 ) ) ;
F_94 (pdp, pml4, start, length, temp, pml4e) {
if ( ! F_115 ( V_124 , V_100 -> V_152 ) ) {
V_93 = F_64 ( V_2 ) ;
if ( F_104 ( V_93 ) )
goto V_146;
F_67 ( V_21 , V_93 ) ;
V_100 -> V_143 [ V_124 ] = V_93 ;
F_116 ( V_124 , V_150 ) ;
F_123 ( V_21 ,
V_124 ,
V_25 ,
V_153 ) ;
}
}
return 0 ;
V_146:
F_102 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_66 ( V_2 , V_100 -> V_143 [ V_124 ] ) ;
return - V_58 ;
}
static void
F_124 ( unsigned long * V_148 , unsigned long * V_144 )
{
F_42 ( V_144 ) ;
F_42 ( V_148 ) ;
}
static
int T_13 F_125 ( unsigned long * * V_148 ,
unsigned long * * V_144 ,
T_8 V_94 )
{
unsigned long * V_154 ;
unsigned long * V_155 ;
V_154 = F_49 ( F_50 ( V_94 ) , sizeof( unsigned long ) , V_156 ) ;
if ( ! V_154 )
return - V_58 ;
V_155 = F_49 ( V_94 , F_50 ( V_89 ) * sizeof( unsigned long ) ,
V_156 ) ;
if ( ! V_155 )
goto V_157;
* V_148 = V_154 ;
* V_144 = V_155 ;
return 0 ;
V_157:
F_124 ( V_154 , V_155 ) ;
return - V_58 ;
}
static void F_126 ( struct V_103 * V_104 )
{
V_104 -> V_158 = F_2 ( V_104 -> V_27 . V_2 ) -> V_159 ;
}
static int F_127 ( struct V_82 * V_21 ,
struct V_92 * V_93 ,
T_7 V_25 ,
T_7 V_115 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
unsigned long * V_160 , * V_161 ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_86 * V_87 ;
const T_7 V_162 = V_25 ;
const T_7 V_163 = V_115 ;
T_7 V_145 ;
T_8 V_117 ;
T_8 V_94 = F_62 ( V_2 ) ;
int V_71 ;
if ( F_28 ( V_25 + V_115 < V_25 ) )
return - V_164 ;
if ( F_28 ( V_25 + V_115 > V_21 -> V_165 ) )
return - V_164 ;
V_71 = F_125 ( & V_160 , & V_161 , V_94 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_118 ( V_21 , V_93 , V_25 , V_115 ,
V_160 ) ;
if ( V_71 ) {
F_124 ( V_160 , V_161 ) ;
return V_71 ;
}
F_120 (pd, pdp, start, length, temp, pdpe) {
V_71 = F_113 ( V_21 , V_87 , V_25 , V_115 ,
V_161 + V_117 * F_50 ( V_89 ) ) ;
if ( V_71 )
goto V_157;
}
V_25 = V_162 ;
V_115 = V_163 ;
F_120 (pd, pdp, start, length, temp, pdpe) {
T_4 * const V_96 = F_72 ( V_87 ) ;
struct V_74 * V_75 ;
T_7 V_166 = V_115 ;
T_7 V_167 = V_25 ;
T_8 V_40 ;
F_28 ( ! V_87 ) ;
F_114 (pt, pd, pd_start, pd_len, temp, pde) {
F_28 ( ! V_75 ) ;
F_28 ( ! V_166 ) ;
F_28 ( ! F_128 ( V_167 , V_166 ) ) ;
F_129 ( V_75 -> V_79 ,
F_92 ( V_167 ) ,
F_128 ( V_167 , V_166 ) ) ;
F_116 ( V_40 , V_87 -> V_88 ) ;
V_96 [ V_40 ] = F_12 ( F_54 ( V_75 ) ,
V_44 ) ;
F_130 ( & V_104 -> V_27 , V_40 , V_75 ,
F_92 ( V_25 ) ,
F_128 ( V_25 , V_115 ) ,
V_77 ) ;
}
F_73 ( V_104 , V_96 ) ;
F_116 ( V_117 , V_93 -> V_95 ) ;
F_71 ( V_104 , V_93 , V_87 , V_117 ) ;
}
F_124 ( V_160 , V_161 ) ;
F_126 ( V_104 ) ;
return 0 ;
V_157:
while ( V_117 -- ) {
F_102 (temp, new_page_tables + pdpe *
BITS_TO_LONGS(I915_PDES), I915_PDES)
F_52 ( V_2 , V_93 -> V_96 [ V_117 ] -> V_121 [ V_145 ] ) ;
}
F_102 (pdpe, new_page_dirs, pdpes)
F_59 ( V_2 , V_93 -> V_96 [ V_117 ] ) ;
F_124 ( V_160 , V_161 ) ;
F_126 ( V_104 ) ;
return V_71 ;
}
static int F_131 ( struct V_82 * V_21 ,
struct V_99 * V_100 ,
T_7 V_25 ,
T_7 V_115 )
{
F_132 ( V_150 , V_151 ) ;
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
struct V_92 * V_93 ;
T_7 V_145 , V_124 ;
int V_71 = 0 ;
F_133 ( V_150 , V_151 ) ;
V_71 = F_122 ( V_21 , V_100 , V_25 , V_115 ,
V_150 ) ;
if ( V_71 )
return V_71 ;
F_134 ( F_135 ( V_150 , V_151 ) > 2 ,
L_3
L_4 ) ;
F_94 (pdp, pml4, start, length, temp, pml4e) {
F_28 ( ! V_93 ) ;
V_71 = F_127 ( V_21 , V_93 , V_25 , V_115 ) ;
if ( V_71 )
goto V_157;
F_74 ( V_104 , V_100 , V_93 , V_124 ) ;
}
F_136 ( V_100 -> V_152 , V_150 , V_100 -> V_152 ,
V_151 ) ;
return 0 ;
V_157:
F_102 (pml4e, new_pdps, GEN8_PML4ES_PER_PML4)
F_110 ( V_21 -> V_2 , V_100 -> V_143 [ V_124 ] ) ;
return V_71 ;
}
static int F_137 ( struct V_82 * V_21 ,
T_7 V_25 , T_7 V_115 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
if ( F_65 ( V_21 -> V_2 ) )
return F_131 ( V_21 , & V_104 -> V_100 , V_25 , V_115 ) ;
else
return F_127 ( V_21 , & V_104 -> V_93 , V_25 , V_115 ) ;
}
static void F_138 ( struct V_92 * V_93 ,
T_7 V_25 , T_7 V_115 ,
T_2 V_83 ,
struct V_168 * V_169 )
{
struct V_86 * V_87 ;
T_7 V_145 ;
T_8 V_117 ;
F_120 (pd, pdp, start, length, temp, pdpe) {
struct V_74 * V_75 ;
T_7 V_166 = V_115 ;
T_7 V_167 = V_25 ;
T_8 V_40 ;
if ( ! F_115 ( V_117 , V_93 -> V_95 ) )
continue;
F_139 ( V_169 , L_5 , V_117 ) ;
F_114 (pt, pd, pd_start, pd_len, temp, pde) {
T_8 V_32 ;
T_2 * V_116 ;
if ( ! F_115 ( V_40 , V_87 -> V_88 ) )
continue;
V_116 = F_72 ( V_75 ) ;
for ( V_32 = 0 ; V_32 < V_77 ; V_32 += 4 ) {
T_7 V_170 =
( V_117 << V_149 ) |
( V_40 << V_147 ) |
( V_32 << V_171 ) ;
int V_66 ;
bool V_172 = false ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ )
if ( V_116 [ V_32 + V_66 ] != V_83 )
V_172 = true ;
if ( ! V_172 )
continue;
F_139 ( V_169 , L_6 , V_170 , V_117 , V_40 , V_32 ) ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ ) {
if ( V_116 [ V_32 + V_66 ] != V_83 )
F_139 ( V_169 , L_7 , V_116 [ V_32 + V_66 ] ) ;
else
F_140 ( V_169 , L_8 ) ;
}
F_140 ( V_169 , L_9 ) ;
}
F_35 ( V_116 ) ;
}
}
}
static void F_141 ( struct V_103 * V_104 , struct V_168 * V_169 )
{
struct V_82 * V_21 = & V_104 -> V_27 ;
T_7 V_25 = V_104 -> V_27 . V_25 ;
T_7 V_115 = V_104 -> V_27 . V_165 ;
T_2 V_83 = F_11 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true ) ;
if ( ! F_65 ( V_21 -> V_2 ) ) {
F_138 ( & V_104 -> V_93 , V_25 , V_115 , V_83 , V_169 ) ;
} else {
T_7 V_123 , V_124 ;
struct V_99 * V_100 = & V_104 -> V_100 ;
struct V_92 * V_93 ;
F_94 (pdp, pml4, start, length, templ4, pml4e) {
if ( ! F_115 ( V_124 , V_100 -> V_152 ) )
continue;
F_139 ( V_169 , L_10 , V_124 ) ;
F_138 ( V_93 , V_25 , V_115 , V_83 , V_169 ) ;
}
}
}
static int F_142 ( struct V_103 * V_104 )
{
unsigned long * V_160 , * V_161 ;
T_8 V_94 = F_62 ( V_2 ) ;
int V_71 ;
V_71 = F_125 ( & V_160 , & V_161 , V_94 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_118 ( & V_104 -> V_27 , & V_104 -> V_93 ,
0 , 1ULL << 32 ,
V_160 ) ;
if ( ! V_71 )
* V_104 -> V_93 . V_95 = * V_160 ;
F_124 ( V_160 , V_161 ) ;
return V_71 ;
}
static int F_143 ( struct V_103 * V_104 )
{
int V_71 ;
V_71 = F_103 ( & V_104 -> V_27 ) ;
if ( V_71 )
return V_71 ;
V_104 -> V_27 . V_25 = 0 ;
V_104 -> V_27 . V_173 = F_112 ;
V_104 -> V_27 . V_174 = F_137 ;
V_104 -> V_27 . V_22 = F_98 ;
V_104 -> V_27 . V_26 = F_93 ;
V_104 -> V_27 . V_175 = F_10 ;
V_104 -> V_27 . V_176 = F_9 ;
V_104 -> V_177 = F_141 ;
if ( F_65 ( V_104 -> V_27 . V_2 ) ) {
V_71 = F_51 ( V_104 -> V_27 . V_2 , & V_104 -> V_100 ) ;
if ( V_71 )
goto V_178;
F_69 ( & V_104 -> V_27 , & V_104 -> V_100 ) ;
V_104 -> V_27 . V_165 = 1ULL << 48 ;
V_104 -> V_179 = F_87 ;
} else {
V_71 = F_61 ( V_104 -> V_27 . V_2 , & V_104 -> V_93 ) ;
if ( V_71 )
goto V_178;
V_104 -> V_27 . V_165 = 1ULL << 32 ;
V_104 -> V_179 = F_85 ;
F_123 ( & V_104 -> V_27 ,
0 , 0 ,
V_153 ) ;
if ( F_3 ( V_104 -> V_27 . V_2 ) ) {
V_71 = F_142 ( V_104 ) ;
if ( V_71 )
goto V_178;
}
}
if ( F_3 ( V_104 -> V_27 . V_2 ) )
F_106 ( V_104 , true ) ;
return 0 ;
V_178:
F_109 ( & V_104 -> V_27 ) ;
return V_71 ;
}
static void F_144 ( struct V_103 * V_104 , struct V_168 * V_169 )
{
struct V_82 * V_21 = & V_104 -> V_27 ;
struct V_74 * V_16 ;
T_5 V_83 ;
T_8 V_180 ;
T_8 V_32 , V_40 , V_145 ;
T_8 V_25 = V_104 -> V_27 . V_25 , V_115 = V_104 -> V_27 . V_165 ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true , 0 ) ;
F_145 (unused, &ppgtt->pd, start, length, temp, pde) {
T_1 V_181 ;
T_5 * V_116 ;
const T_3 V_182 = F_54 ( V_104 -> V_87 . V_121 [ V_40 ] ) ;
V_180 = F_146 ( V_104 -> V_183 + V_40 ) ;
V_181 = ( F_147 ( V_182 ) | V_184 ) ;
if ( V_180 != V_181 )
F_139 ( V_169 , L_11 ,
V_40 ,
V_180 ,
V_181 ) ;
F_139 ( V_169 , L_12 , V_180 ) ;
V_116 = F_72 ( V_104 -> V_87 . V_121 [ V_40 ] ) ;
for ( V_32 = 0 ; V_32 < V_78 ; V_32 += 4 ) {
unsigned long V_170 =
( V_40 * V_64 * V_78 ) +
( V_32 * V_64 ) ;
int V_66 ;
bool V_172 = false ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ )
if ( V_116 [ V_32 + V_66 ] != V_83 )
V_172 = true ;
if ( ! V_172 )
continue;
F_139 ( V_169 , L_13 , V_170 , V_40 , V_32 ) ;
for ( V_66 = 0 ; V_66 < 4 ; V_66 ++ ) {
if ( V_116 [ V_32 + V_66 ] != V_83 )
F_139 ( V_169 , L_14 , V_116 [ V_32 + V_66 ] ) ;
else
F_140 ( V_169 , L_8 ) ;
}
F_140 ( V_169 , L_9 ) ;
}
F_73 ( V_104 , V_116 ) ;
}
}
static void F_148 ( struct V_86 * V_87 ,
const int V_40 , struct V_74 * V_75 )
{
struct V_103 * V_104 =
F_89 ( V_87 , struct V_103 , V_87 ) ;
T_1 V_180 ;
V_180 = F_147 ( F_54 ( V_75 ) ) ;
V_180 |= V_184 ;
F_149 ( V_180 , V_104 -> V_183 + V_40 ) ;
}
static void F_150 ( struct V_133 * V_134 ,
struct V_86 * V_87 ,
T_8 V_25 , T_8 V_115 )
{
struct V_74 * V_75 ;
T_8 V_40 , V_145 ;
F_145 (pt, pd, start, length, temp, pde)
F_148 ( V_87 , V_40 , V_75 ) ;
F_146 ( V_134 -> V_185 . V_186 ) ;
}
static T_8 F_151 ( struct V_103 * V_104 )
{
F_76 ( V_104 -> V_87 . V_27 . V_187 & 0x3f ) ;
return ( V_104 -> V_87 . V_27 . V_187 / 64 ) << 16 ;
}
static int F_152 ( struct V_103 * V_104 ,
struct V_108 * V_109 )
{
struct V_111 * V_112 = V_109 -> V_112 ;
int V_71 ;
V_71 = V_112 -> V_188 ( V_109 , V_189 , V_189 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_77 ( V_109 , 6 ) ;
if ( V_71 )
return V_71 ;
F_78 ( V_112 , F_79 ( 2 ) ) ;
F_78 ( V_112 , F_153 ( V_112 ) ) ;
F_78 ( V_112 , V_190 ) ;
F_78 ( V_112 , F_154 ( V_112 ) ) ;
F_78 ( V_112 , F_151 ( V_104 ) ) ;
F_78 ( V_112 , V_191 ) ;
F_84 ( V_112 ) ;
return 0 ;
}
static int F_155 ( struct V_103 * V_104 ,
struct V_108 * V_109 )
{
struct V_111 * V_112 = V_109 -> V_112 ;
struct V_133 * V_134 = F_156 ( V_104 -> V_27 . V_2 ) ;
F_108 ( F_153 ( V_112 ) , V_190 ) ;
F_108 ( F_154 ( V_112 ) , F_151 ( V_104 ) ) ;
return 0 ;
}
static int F_157 ( struct V_103 * V_104 ,
struct V_108 * V_109 )
{
struct V_111 * V_112 = V_109 -> V_112 ;
int V_71 ;
V_71 = V_112 -> V_188 ( V_109 , V_189 , V_189 ) ;
if ( V_71 )
return V_71 ;
V_71 = F_77 ( V_109 , 6 ) ;
if ( V_71 )
return V_71 ;
F_78 ( V_112 , F_79 ( 2 ) ) ;
F_78 ( V_112 , F_153 ( V_112 ) ) ;
F_78 ( V_112 , V_190 ) ;
F_78 ( V_112 , F_154 ( V_112 ) ) ;
F_78 ( V_112 , F_151 ( V_104 ) ) ;
F_78 ( V_112 , V_191 ) ;
F_84 ( V_112 ) ;
if ( V_112 -> V_192 != V_193 ) {
V_71 = V_112 -> V_188 ( V_109 , V_189 , V_189 ) ;
if ( V_71 )
return V_71 ;
}
return 0 ;
}
static int F_158 ( struct V_103 * V_104 ,
struct V_108 * V_109 )
{
struct V_111 * V_112 = V_109 -> V_112 ;
struct V_1 * V_2 = V_104 -> V_27 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
F_108 ( F_153 ( V_112 ) , V_190 ) ;
F_108 ( F_154 ( V_112 ) , F_151 ( V_104 ) ) ;
F_159 ( F_153 ( V_112 ) ) ;
return 0 ;
}
static void F_160 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_111 * V_112 ;
int V_194 ;
F_161 (ring, dev_priv, j) {
T_1 V_195 = F_65 ( V_2 ) ? V_196 : 0 ;
F_108 ( F_162 ( V_112 ) ,
F_163 ( V_197 | V_195 ) ) ;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_111 * V_112 ;
T_8 V_198 , V_199 ;
int V_66 ;
V_199 = F_165 ( V_200 ) ;
F_108 ( V_200 , V_199 | V_201 ) ;
V_198 = F_165 ( V_202 ) ;
if ( F_166 ( V_2 ) ) {
V_198 |= V_203 ;
} else {
V_198 |= V_204 ;
V_198 &= ~ V_205 ;
}
F_108 ( V_202 , V_198 ) ;
F_161 (ring, dev_priv, i) {
F_108 ( F_162 ( V_112 ) ,
F_163 ( V_197 ) ) ;
}
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
T_8 V_198 , V_206 , V_199 ;
V_199 = F_165 ( V_200 ) ;
F_108 ( V_200 , V_199 | V_207 |
V_201 ) ;
V_206 = F_165 ( V_208 ) ;
F_108 ( V_208 , V_206 | V_209 ) ;
V_198 = F_165 ( V_202 ) ;
F_108 ( V_202 , V_198 | V_210 | V_211 ) ;
F_108 ( V_212 , F_163 ( V_197 ) ) ;
}
static void F_168 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_115 ,
bool V_122 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
T_5 * V_116 , V_83 ;
unsigned V_213 = V_25 >> V_119 ;
unsigned V_118 = V_115 >> V_119 ;
unsigned V_214 = V_213 / V_78 ;
unsigned V_215 = V_213 % V_78 ;
unsigned V_120 , V_66 ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , true , 0 ) ;
while ( V_118 ) {
V_120 = V_215 + V_118 ;
if ( V_120 > V_78 )
V_120 = V_78 ;
V_116 = F_72 ( V_104 -> V_87 . V_121 [ V_214 ] ) ;
for ( V_66 = V_215 ; V_66 < V_120 ; V_66 ++ )
V_116 [ V_66 ] = V_83 ;
F_73 ( V_104 , V_116 ) ;
V_118 -= V_120 - V_215 ;
V_215 = 0 ;
V_214 ++ ;
}
}
static void F_169 ( struct V_82 * V_21 ,
struct V_127 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_48 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
T_5 * V_116 ;
unsigned V_213 = V_25 >> V_119 ;
unsigned V_214 = V_213 / V_78 ;
unsigned V_216 = V_213 % V_78 ;
struct V_125 V_126 ;
V_116 = NULL ;
F_170 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_116 == NULL )
V_116 = F_72 ( V_104 -> V_87 . V_121 [ V_214 ] ) ;
V_116 [ V_216 ] =
V_21 -> V_85 ( F_97 ( & V_126 ) ,
V_15 , true , V_48 ) ;
if ( ++ V_216 == V_78 ) {
F_73 ( V_104 , V_116 ) ;
V_116 = NULL ;
V_214 ++ ;
V_216 = 0 ;
}
}
if ( V_116 )
F_73 ( V_104 , V_116 ) ;
}
static int F_171 ( struct V_82 * V_21 ,
T_7 V_217 , T_7 V_218 )
{
F_132 ( V_161 , V_89 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
struct V_74 * V_75 ;
T_8 V_25 , V_115 , V_219 , V_220 ;
T_8 V_40 , V_145 ;
int V_71 ;
if ( F_28 ( V_217 + V_218 > V_104 -> V_27 . V_165 ) )
return - V_164 ;
V_25 = V_219 = V_217 ;
V_115 = V_220 = V_218 ;
F_133 ( V_161 , V_89 ) ;
F_145 (pt, &ppgtt->pd, start, length, temp, pde) {
if ( V_75 != V_21 -> V_91 ) {
F_28 ( F_119 ( V_75 -> V_79 , V_78 ) ) ;
continue;
}
F_28 ( ! F_119 ( V_75 -> V_79 , V_78 ) ) ;
V_75 = F_48 ( V_2 ) ;
if ( F_104 ( V_75 ) ) {
V_71 = F_105 ( V_75 ) ;
goto V_146;
}
F_56 ( V_21 , V_75 ) ;
V_104 -> V_87 . V_121 [ V_40 ] = V_75 ;
F_116 ( V_40 , V_161 ) ;
F_117 ( V_21 , V_40 , V_25 , V_221 ) ;
}
V_25 = V_219 ;
V_115 = V_220 ;
F_145 (pt, &ppgtt->pd, start, length, temp, pde) {
F_132 ( V_222 , V_78 ) ;
F_133 ( V_222 , V_78 ) ;
F_129 ( V_222 , F_172 ( V_25 ) ,
F_173 ( V_25 , V_115 ) ) ;
if ( F_174 ( V_40 , V_161 ) )
F_148 ( & V_104 -> V_87 , V_40 , V_75 ) ;
F_130 ( V_21 , V_40 , V_75 ,
F_172 ( V_25 ) ,
F_173 ( V_25 , V_115 ) ,
V_78 ) ;
F_136 ( V_75 -> V_79 , V_222 , V_75 -> V_79 ,
V_78 ) ;
}
F_28 ( ! F_119 ( V_161 , V_89 ) ) ;
F_146 ( V_134 -> V_185 . V_186 ) ;
F_126 ( V_104 ) ;
return 0 ;
V_146:
F_102 (pde, new_page_tables, I915_PDES) {
struct V_74 * V_75 = V_104 -> V_87 . V_121 [ V_40 ] ;
V_104 -> V_87 . V_121 [ V_40 ] = V_21 -> V_91 ;
F_52 ( V_21 -> V_2 , V_75 ) ;
}
F_126 ( V_104 ) ;
return V_71 ;
}
static int F_175 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
V_21 -> V_84 = F_38 ( V_2 ) ;
if ( F_104 ( V_21 -> V_84 ) )
return F_105 ( V_21 -> V_84 ) ;
V_21 -> V_91 = F_48 ( V_2 ) ;
if ( F_104 ( V_21 -> V_91 ) ) {
F_45 ( V_2 , V_21 -> V_84 ) ;
return F_105 ( V_21 -> V_91 ) ;
}
F_56 ( V_21 , V_21 -> V_91 ) ;
return 0 ;
}
static void F_176 ( struct V_82 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
F_52 ( V_2 , V_21 -> V_91 ) ;
F_45 ( V_2 , V_21 -> V_84 ) ;
}
static void F_177 ( struct V_82 * V_21 )
{
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 , V_27 ) ;
struct V_74 * V_75 ;
T_8 V_40 ;
F_178 ( & V_104 -> V_24 ) ;
F_179 (pt, ppgtt, pde) {
if ( V_75 != V_21 -> V_91 )
F_52 ( V_104 -> V_27 . V_2 , V_75 ) ;
}
F_176 ( V_21 ) ;
}
static int F_180 ( struct V_103 * V_104 )
{
struct V_82 * V_21 = & V_104 -> V_27 ;
struct V_1 * V_2 = V_104 -> V_27 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
bool V_223 = false ;
int V_71 ;
F_76 ( ! F_181 ( & V_134 -> V_185 . V_27 . V_224 ) ) ;
V_71 = F_175 ( V_21 ) ;
if ( V_71 )
return V_71 ;
V_225:
V_71 = F_182 ( & V_134 -> V_185 . V_27 . V_224 ,
& V_104 -> V_24 , V_226 ,
V_227 , 0 ,
0 , V_134 -> V_185 . V_27 . V_165 ,
V_228 ) ;
if ( V_71 == - V_229 && ! V_223 ) {
V_71 = F_183 ( V_2 , & V_134 -> V_185 . V_27 ,
V_226 , V_227 ,
V_35 ,
0 , V_134 -> V_185 . V_27 . V_165 ,
0 ) ;
if ( V_71 )
goto V_157;
V_223 = true ;
goto V_225;
}
if ( V_71 )
goto V_157;
if ( V_104 -> V_24 . V_25 < V_134 -> V_185 . V_230 )
F_184 ( L_15 ) ;
return 0 ;
V_157:
F_176 ( V_21 ) ;
return V_71 ;
}
static int F_185 ( struct V_103 * V_104 )
{
return F_180 ( V_104 ) ;
}
static void F_186 ( struct V_103 * V_104 ,
T_7 V_25 , T_7 V_115 )
{
struct V_74 * V_16 ;
T_8 V_40 , V_145 ;
F_145 (unused, &ppgtt->pd, start, length, temp, pde)
V_104 -> V_87 . V_121 [ V_40 ] = V_104 -> V_27 . V_91 ;
}
static int F_187 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_27 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
int V_71 ;
V_104 -> V_27 . V_85 = V_134 -> V_185 . V_27 . V_85 ;
if ( F_188 ( V_2 ) ) {
V_104 -> V_179 = F_158 ;
} else if ( F_166 ( V_2 ) ) {
V_104 -> V_179 = F_152 ;
} else if ( F_189 ( V_2 ) ) {
V_104 -> V_179 = F_157 ;
} else
F_190 () ;
if ( F_3 ( V_2 ) )
V_104 -> V_179 = F_155 ;
V_71 = F_185 ( V_104 ) ;
if ( V_71 )
return V_71 ;
V_104 -> V_27 . V_174 = F_171 ;
V_104 -> V_27 . V_26 = F_168 ;
V_104 -> V_27 . V_22 = F_169 ;
V_104 -> V_27 . V_175 = F_10 ;
V_104 -> V_27 . V_176 = F_9 ;
V_104 -> V_27 . V_173 = F_177 ;
V_104 -> V_27 . V_25 = 0 ;
V_104 -> V_27 . V_165 = V_89 * V_78 * V_64 ;
V_104 -> V_177 = F_144 ;
V_104 -> V_87 . V_27 . V_187 =
V_104 -> V_24 . V_25 / V_64 * sizeof( T_5 ) ;
V_104 -> V_183 = ( T_5 V_231 * ) V_134 -> V_185 . V_186 +
V_104 -> V_87 . V_27 . V_187 / sizeof( T_5 ) ;
F_186 ( V_104 , 0 , V_104 -> V_27 . V_165 ) ;
F_150 ( V_134 , & V_104 -> V_87 , 0 , V_104 -> V_27 . V_165 ) ;
F_8 ( L_16 ,
V_104 -> V_24 . V_28 >> 20 ,
V_104 -> V_24 . V_25 / V_64 ) ;
F_184 ( L_17 ,
V_104 -> V_87 . V_27 . V_187 << 10 ) ;
return 0 ;
}
static int F_191 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
V_104 -> V_27 . V_2 = V_2 ;
if ( F_2 ( V_2 ) -> V_6 < 8 )
return F_187 ( V_104 ) ;
else
return F_143 ( V_104 ) ;
}
static void F_192 ( struct V_82 * V_21 ,
struct V_133 * V_134 )
{
F_193 ( & V_21 -> V_224 , V_21 -> V_25 , V_21 -> V_165 ) ;
V_21 -> V_2 = V_134 -> V_2 ;
F_194 ( & V_21 -> V_232 ) ;
F_194 ( & V_21 -> V_233 ) ;
F_195 ( & V_21 -> V_234 , & V_134 -> V_235 ) ;
}
int F_196 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
int V_71 = 0 ;
V_71 = F_191 ( V_2 , V_104 ) ;
if ( V_71 == 0 ) {
F_197 ( & V_104 -> V_236 ) ;
F_192 ( & V_104 -> V_27 , V_134 ) ;
}
return V_71 ;
}
int F_198 ( struct V_1 * V_2 )
{
if ( V_10 . V_11 )
return 0 ;
if ( ! F_199 ( V_2 ) )
return 0 ;
if ( F_188 ( V_2 ) )
F_167 ( V_2 ) ;
else if ( F_189 ( V_2 ) )
F_164 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_6 >= 8 )
F_160 ( V_2 ) ;
else
F_15 ( F_2 ( V_2 ) -> V_6 ) ;
return 0 ;
}
int F_200 ( struct V_108 * V_109 )
{
struct V_133 * V_134 = V_109 -> V_112 -> V_2 -> V_135 ;
struct V_103 * V_104 = V_134 -> V_224 . V_237 ;
if ( V_10 . V_11 )
return 0 ;
if ( ! V_104 )
return 0 ;
return V_104 -> V_179 ( V_104 , V_109 ) ;
}
struct V_103 *
F_201 ( struct V_1 * V_2 , struct V_238 * V_239 )
{
struct V_103 * V_104 ;
int V_71 ;
V_104 = F_39 ( sizeof( * V_104 ) , V_62 ) ;
if ( ! V_104 )
return F_40 ( - V_58 ) ;
V_71 = F_196 ( V_2 , V_104 ) ;
if ( V_71 ) {
F_42 ( V_104 ) ;
return F_40 ( V_71 ) ;
}
V_104 -> V_240 = V_239 ;
F_202 ( & V_104 -> V_27 ) ;
return V_104 ;
}
void F_203 ( struct V_241 * V_241 )
{
struct V_103 * V_104 =
F_89 ( V_241 , struct V_103 , V_236 ) ;
F_204 ( & V_104 -> V_27 ) ;
F_28 ( ! F_205 ( & V_104 -> V_27 . V_232 ) ) ;
F_28 ( ! F_205 ( & V_104 -> V_27 . V_233 ) ) ;
F_206 ( & V_104 -> V_27 . V_234 ) ;
F_207 ( & V_104 -> V_27 . V_224 ) ;
V_104 -> V_27 . V_173 ( & V_104 -> V_27 ) ;
F_42 ( V_104 ) ;
}
static bool F_208 ( struct V_1 * V_2 )
{
#ifdef F_4
if ( F_209 ( V_2 ) && F_210 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_211 ( struct V_133 * V_134 )
{
bool V_71 = V_134 -> V_224 . V_242 ;
if ( F_212 ( V_134 -> V_185 . V_243 ) ) {
V_134 -> V_224 . V_242 = false ;
if ( F_213 ( V_134 -> V_2 ) ) {
F_214 ( L_18 ) ;
F_215 ( 10 ) ;
}
}
return V_71 ;
}
static void F_216 ( struct V_133 * V_134 , bool V_242 )
{
if ( F_212 ( V_134 -> V_185 . V_243 ) )
V_134 -> V_224 . V_242 = V_242 ;
}
void F_217 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_111 * V_112 ;
int V_66 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_161 (ring, dev_priv, i) {
T_1 V_244 ;
V_244 = F_165 ( F_218 ( V_112 ) ) ;
if ( V_244 & V_245 ) {
F_8 ( L_19
L_20
L_21
L_22
L_23 ,
V_244 & V_246 ,
V_244 & V_247 ? L_24 : L_25 ,
F_219 ( V_244 ) ,
F_220 ( V_244 ) ) ;
F_108 ( F_218 ( V_112 ) ,
V_244 & ~ V_245 ) ;
}
}
F_159 ( F_218 ( & V_134 -> V_112 [ V_193 ] ) ) ;
}
static void F_221 ( struct V_133 * V_134 )
{
if ( F_2 ( V_134 -> V_2 ) -> V_6 < 6 ) {
F_222 () ;
} else {
F_108 ( V_248 , V_249 ) ;
F_159 ( V_248 ) ;
}
}
void F_223 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_217 ( V_2 ) ;
V_134 -> V_185 . V_27 . V_26 ( & V_134 -> V_185 . V_27 ,
V_134 -> V_185 . V_27 . V_25 ,
V_134 -> V_185 . V_27 . V_165 ,
true ) ;
F_221 ( V_134 ) ;
}
int F_224 ( struct V_250 * V_18 )
{
if ( ! F_225 ( & V_18 -> V_27 . V_2 -> V_8 -> V_2 ,
V_18 -> V_23 -> V_128 , V_18 -> V_23 -> V_251 ,
V_60 ) )
return - V_229 ;
return 0 ;
}
static void F_226 ( void V_231 * V_29 , T_2 V_32 )
{
#ifdef F_227
F_227 ( V_32 , V_29 ) ;
#else
F_228 ( ( T_1 ) V_32 , V_29 ) ;
F_228 ( V_32 >> 32 , V_29 + 4 ) ;
#endif
}
static void F_229 ( struct V_82 * V_21 ,
struct V_127 * V_252 ,
T_7 V_25 ,
enum V_14 V_30 , T_1 V_16 )
{
struct V_133 * V_134 = V_21 -> V_2 -> V_135 ;
unsigned V_213 = V_25 >> V_119 ;
T_2 V_231 * V_253 =
( T_2 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
int V_66 = 0 ;
struct V_125 V_126 ;
T_3 V_29 = 0 ;
F_170 (st->sgl, &sg_iter, st->nents, 0 ) {
V_29 = F_230 ( V_126 . V_254 ) +
( V_126 . V_255 << V_119 ) ;
F_226 ( & V_253 [ V_66 ] ,
F_11 ( V_29 , V_30 , true ) ) ;
V_66 ++ ;
}
if ( V_66 != 0 )
F_28 ( F_231 ( & V_253 [ V_66 - 1 ] )
!= F_11 ( V_29 , V_30 , true ) ) ;
F_108 ( V_248 , V_249 ) ;
F_159 ( V_248 ) ;
}
static void F_232 ( struct V_82 * V_21 ,
struct V_127 * V_252 ,
T_7 V_25 ,
enum V_14 V_30 , T_1 V_48 )
{
struct V_133 * V_134 = V_21 -> V_2 -> V_135 ;
unsigned V_213 = V_25 >> V_119 ;
T_5 V_231 * V_253 =
( T_5 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
int V_66 = 0 ;
struct V_125 V_126 ;
T_3 V_29 = 0 ;
F_170 (st->sgl, &sg_iter, st->nents, 0 ) {
V_29 = F_97 ( & V_126 ) ;
F_228 ( V_21 -> V_85 ( V_29 , V_30 , true , V_48 ) , & V_253 [ V_66 ] ) ;
V_66 ++ ;
}
if ( V_66 != 0 ) {
unsigned long V_185 = F_146 ( & V_253 [ V_66 - 1 ] ) ;
F_28 ( V_185 != V_21 -> V_85 ( V_29 , V_30 , true , V_48 ) ) ;
}
F_108 ( V_248 , V_249 ) ;
F_159 ( V_248 ) ;
}
static void F_233 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_115 ,
bool V_122 )
{
struct V_133 * V_134 = V_21 -> V_2 -> V_135 ;
unsigned V_213 = V_25 >> V_119 ;
unsigned V_118 = V_115 >> V_119 ;
T_2 V_83 , V_231 * V_256 =
( T_2 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
const int V_257 = F_234 ( V_134 -> V_185 ) - V_213 ;
int V_66 ;
if ( F_134 ( V_118 > V_257 ,
L_26 ,
V_213 , V_118 , V_257 ) )
V_118 = V_257 ;
V_83 = F_11 ( F_54 ( V_21 -> V_84 ) ,
V_44 ,
V_122 ) ;
for ( V_66 = 0 ; V_66 < V_118 ; V_66 ++ )
F_226 ( & V_256 [ V_66 ] , V_83 ) ;
F_146 ( V_256 ) ;
}
static void F_235 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_115 ,
bool V_122 )
{
struct V_133 * V_134 = V_21 -> V_2 -> V_135 ;
unsigned V_213 = V_25 >> V_119 ;
unsigned V_118 = V_115 >> V_119 ;
T_5 V_83 , V_231 * V_256 =
( T_5 V_231 * ) V_134 -> V_185 . V_186 + V_213 ;
const int V_257 = F_234 ( V_134 -> V_185 ) - V_213 ;
int V_66 ;
if ( F_134 ( V_118 > V_257 ,
L_26 ,
V_213 , V_118 , V_257 ) )
V_118 = V_257 ;
V_83 = V_21 -> V_85 ( F_54 ( V_21 -> V_84 ) ,
V_44 , V_122 , 0 ) ;
for ( V_66 = 0 ; V_66 < V_118 ; V_66 ++ )
F_228 ( V_83 , & V_256 [ V_66 ] ) ;
F_146 ( V_256 ) ;
}
static void F_236 ( struct V_82 * V_21 ,
struct V_127 * V_23 ,
T_7 V_25 ,
enum V_14 V_15 , T_1 V_16 )
{
unsigned int V_48 = ( V_15 == V_35 ) ?
V_258 : V_259 ;
F_237 ( V_23 , V_25 >> V_119 , V_48 ) ;
}
static void F_238 ( struct V_82 * V_21 ,
T_7 V_25 ,
T_7 V_115 ,
bool V_16 )
{
unsigned V_213 = V_25 >> V_119 ;
unsigned V_118 = V_115 >> V_119 ;
F_239 ( V_213 , V_118 ) ;
}
static int F_240 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
T_1 V_48 )
{
struct V_250 * V_18 = V_13 -> V_18 ;
T_1 V_17 = 0 ;
int V_71 ;
V_71 = F_241 ( V_13 ) ;
if ( V_71 )
return V_71 ;
if ( V_18 -> V_19 )
V_17 |= V_20 ;
V_13 -> V_21 -> V_22 ( V_13 -> V_21 , V_13 -> V_260 . V_23 ,
V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
V_13 -> V_261 |= V_262 | V_263 ;
return 0 ;
}
static int F_242 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
T_1 V_48 )
{
struct V_1 * V_2 = V_13 -> V_21 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_250 * V_18 = V_13 -> V_18 ;
struct V_127 * V_23 = V_18 -> V_23 ;
T_1 V_17 = 0 ;
int V_71 ;
V_71 = F_241 ( V_13 ) ;
if ( V_71 )
return V_71 ;
V_23 = V_13 -> V_260 . V_23 ;
if ( V_18 -> V_19 )
V_17 |= V_20 ;
if ( V_48 & V_262 ) {
V_13 -> V_21 -> V_22 ( V_13 -> V_21 , V_23 ,
V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
}
if ( V_48 & V_263 ) {
struct V_103 * V_264 = V_134 -> V_224 . V_237 ;
V_264 -> V_27 . V_22 ( & V_264 -> V_27 , V_23 ,
V_13 -> V_24 . V_25 ,
V_15 , V_17 ) ;
}
return 0 ;
}
static void F_243 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_21 -> V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_250 * V_18 = V_13 -> V_18 ;
const T_7 V_28 = F_244 ( T_7 ,
V_18 -> V_27 . V_28 ,
V_13 -> V_24 . V_28 ) ;
if ( V_13 -> V_261 & V_262 ) {
V_13 -> V_21 -> V_26 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_28 ,
true ) ;
}
if ( V_134 -> V_224 . V_237 && V_13 -> V_261 & V_263 ) {
struct V_103 * V_264 = V_134 -> V_224 . V_237 ;
V_264 -> V_27 . V_26 ( & V_264 -> V_27 ,
V_13 -> V_24 . V_25 ,
V_28 ,
true ) ;
}
}
void F_245 ( struct V_250 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_27 . V_2 ;
struct V_133 * V_134 = V_2 -> V_135 ;
bool V_242 ;
V_242 = F_211 ( V_134 ) ;
F_246 ( & V_2 -> V_8 -> V_2 , V_18 -> V_23 -> V_128 , V_18 -> V_23 -> V_251 ,
V_60 ) ;
F_216 ( V_134 , V_242 ) ;
}
static void F_247 ( struct V_265 * V_24 ,
unsigned long V_266 ,
T_12 * V_25 ,
T_12 * V_267 )
{
if ( V_24 -> V_266 != V_266 )
* V_25 += 4096 ;
if ( ! F_205 ( & V_24 -> V_268 ) ) {
V_24 = F_248 ( V_24 -> V_268 . V_269 ,
struct V_265 ,
V_268 ) ;
if ( V_24 -> V_270 && V_24 -> V_266 != V_266 )
* V_267 -= 4096 ;
}
}
static int F_249 ( struct V_1 * V_2 ,
T_12 V_25 ,
T_12 V_230 ,
T_12 V_267 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_82 * V_271 = & V_134 -> V_185 . V_27 ;
struct V_265 * V_110 ;
struct V_250 * V_18 ;
unsigned long V_272 , V_273 ;
int V_71 ;
F_76 ( V_230 > V_267 ) ;
V_271 -> V_25 = V_25 ;
V_271 -> V_165 = V_267 - V_25 - V_64 ;
F_192 ( V_271 , V_134 ) ;
V_271 -> V_165 += V_64 ;
if ( F_3 ( V_2 ) ) {
V_71 = F_250 ( V_2 ) ;
if ( V_71 )
return V_71 ;
}
if ( ! F_251 ( V_2 ) )
V_271 -> V_224 . V_274 = F_247 ;
F_252 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_12 * V_13 = F_253 ( V_18 , V_271 ) ;
F_254 ( L_27 ,
F_255 ( V_18 ) , V_18 -> V_27 . V_28 ) ;
F_28 ( F_256 ( V_18 ) ) ;
V_71 = F_257 ( & V_271 -> V_224 , & V_13 -> V_24 ) ;
if ( V_71 ) {
F_254 ( L_28 , V_71 ) ;
return V_71 ;
}
V_13 -> V_261 |= V_262 ;
F_258 ( V_13 ) ;
F_195 ( & V_13 -> V_275 , & V_271 -> V_233 ) ;
}
F_259 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_254 ( L_29 ,
V_272 , V_273 ) ;
V_271 -> V_26 ( V_271 , V_272 ,
V_273 - V_272 , true ) ;
}
V_271 -> V_26 ( V_271 , V_267 - V_64 , V_64 , true ) ;
if ( F_199 ( V_2 ) && ! F_260 ( V_2 ) ) {
struct V_103 * V_104 ;
V_104 = F_39 ( sizeof( * V_104 ) , V_62 ) ;
if ( ! V_104 )
return - V_58 ;
V_71 = F_191 ( V_2 , V_104 ) ;
if ( V_71 ) {
V_104 -> V_27 . V_173 ( & V_104 -> V_27 ) ;
F_42 ( V_104 ) ;
return V_71 ;
}
if ( V_104 -> V_27 . V_174 )
V_71 = V_104 -> V_27 . V_174 ( & V_104 -> V_27 , 0 ,
V_104 -> V_27 . V_165 ) ;
if ( V_71 ) {
V_104 -> V_27 . V_173 ( & V_104 -> V_27 ) ;
F_42 ( V_104 ) ;
return V_71 ;
}
V_104 -> V_27 . V_26 ( & V_104 -> V_27 ,
V_104 -> V_27 . V_25 ,
V_104 -> V_27 . V_165 ,
true ) ;
V_134 -> V_224 . V_237 = V_104 ;
F_28 ( V_134 -> V_185 . V_27 . V_176 != F_240 ) ;
V_134 -> V_185 . V_27 . V_176 = F_242 ;
}
return 0 ;
}
void F_261 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
T_12 V_276 , V_277 ;
V_276 = V_134 -> V_185 . V_27 . V_165 ;
V_277 = V_134 -> V_185 . V_230 ;
F_249 ( V_2 , 0 , V_277 , V_276 ) ;
}
void F_262 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_82 * V_21 = & V_134 -> V_185 . V_27 ;
if ( V_134 -> V_224 . V_237 ) {
struct V_103 * V_104 = V_134 -> V_224 . V_237 ;
V_104 -> V_27 . V_173 ( & V_104 -> V_27 ) ;
}
if ( F_181 ( & V_21 -> V_224 ) ) {
if ( F_3 ( V_2 ) )
F_263 () ;
F_207 ( & V_21 -> V_224 ) ;
F_206 ( & V_21 -> V_234 ) ;
}
V_21 -> V_173 ( V_21 ) ;
}
static unsigned int F_264 ( T_14 V_278 )
{
V_278 >>= V_279 ;
V_278 &= V_280 ;
return V_278 << 20 ;
}
static unsigned int F_265 ( T_14 V_281 )
{
V_281 >>= V_282 ;
V_281 &= V_283 ;
if ( V_281 )
V_281 = 1 << V_281 ;
#ifdef F_266
if ( V_281 > 4 )
V_281 = 4 ;
#endif
return V_281 << 20 ;
}
static unsigned int F_267 ( T_14 V_284 )
{
V_284 >>= V_279 ;
V_284 &= V_280 ;
if ( V_284 )
return 1 << ( 20 + V_284 ) ;
return 0 ;
}
static T_9 F_268 ( T_14 V_278 )
{
V_278 >>= V_285 ;
V_278 &= V_286 ;
return V_278 << 25 ;
}
static T_9 F_269 ( T_14 V_281 )
{
V_281 >>= V_287 ;
V_281 &= V_288 ;
return V_281 << 25 ;
}
static T_9 F_270 ( T_14 V_284 )
{
V_284 >>= V_285 ;
V_284 &= V_286 ;
if ( V_284 < 0x11 )
return V_284 << 25 ;
else if ( V_284 < 0x17 )
return ( V_284 - 0x11 + 2 ) << 22 ;
else
return ( V_284 - 0x17 + 9 ) << 22 ;
}
static T_9 F_271 ( T_14 V_289 )
{
V_289 >>= V_287 ;
V_289 &= V_288 ;
if ( V_289 < 0xf0 )
return V_289 << 25 ;
else
return ( V_289 - 0xf0 + 1 ) << 22 ;
}
static int F_272 ( struct V_1 * V_2 ,
T_9 V_276 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_69 * V_84 ;
T_15 V_290 ;
V_290 = F_273 ( V_2 -> V_8 , 0 ) +
( F_274 ( V_2 -> V_8 , 0 ) / 2 ) ;
if ( F_33 ( V_2 ) )
V_134 -> V_185 . V_186 = F_275 ( V_290 , V_276 ) ;
else
V_134 -> V_185 . V_186 = F_276 ( V_290 , V_276 ) ;
if ( ! V_134 -> V_185 . V_186 ) {
F_214 ( L_30 ) ;
return - V_58 ;
}
V_84 = F_38 ( V_2 ) ;
if ( F_104 ( V_84 ) ) {
F_214 ( L_31 ) ;
F_277 ( V_134 -> V_185 . V_186 ) ;
return F_105 ( V_84 ) ;
}
V_134 -> V_185 . V_27 . V_84 = V_84 ;
return 0 ;
}
static void F_278 ( struct V_133 * V_134 )
{
T_7 V_291 ;
V_291 = F_279 ( 0 , V_292 | V_293 ) |
F_279 ( 1 , V_294 | V_295 ) |
F_279 ( 2 , V_296 | V_295 ) |
F_279 ( 3 , V_297 ) |
F_279 ( 4 , V_292 | V_295 | F_280 ( 0 ) ) |
F_279 ( 5 , V_292 | V_295 | F_280 ( 1 ) ) |
F_279 ( 6 , V_292 | V_295 | F_280 ( 2 ) ) |
F_279 ( 7 , V_292 | V_295 | F_280 ( 3 ) ) ;
if ( ! F_199 ( V_134 -> V_2 ) )
V_291 = F_279 ( 0 , V_297 ) ;
F_108 ( V_298 , V_291 ) ;
F_108 ( V_299 , V_291 >> 32 ) ;
}
static void F_281 ( struct V_133 * V_134 )
{
T_7 V_291 ;
V_291 = F_279 ( 0 , V_300 ) |
F_279 ( 1 , 0 ) |
F_279 ( 2 , 0 ) |
F_279 ( 3 , 0 ) |
F_279 ( 4 , V_300 ) |
F_279 ( 5 , V_300 ) |
F_279 ( 6 , V_300 ) |
F_279 ( 7 , V_300 ) ;
F_108 ( V_298 , V_291 ) ;
F_108 ( V_299 , V_291 >> 32 ) ;
}
static int F_282 ( struct V_1 * V_2 ,
T_12 * V_301 ,
T_9 * V_302 ,
T_15 * V_303 ,
T_12 * V_230 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
T_12 V_276 ;
T_14 V_278 ;
int V_71 ;
* V_303 = F_273 ( V_2 -> V_8 , 2 ) ;
* V_230 = F_274 ( V_2 -> V_8 , 2 ) ;
if ( ! F_283 ( V_2 -> V_8 , F_284 ( 39 ) ) )
F_285 ( V_2 -> V_8 , F_284 ( 39 ) ) ;
F_286 ( V_2 -> V_8 , V_304 , & V_278 ) ;
if ( F_2 ( V_2 ) -> V_6 >= 9 ) {
* V_302 = F_271 ( V_278 ) ;
V_276 = F_265 ( V_278 ) ;
} else if ( F_7 ( V_2 ) ) {
* V_302 = F_270 ( V_278 ) ;
V_276 = F_267 ( V_278 ) ;
} else {
* V_302 = F_269 ( V_278 ) ;
V_276 = F_265 ( V_278 ) ;
}
* V_301 = ( V_276 / sizeof( T_2 ) ) << V_119 ;
if ( F_7 ( V_2 ) || F_33 ( V_2 ) )
F_281 ( V_134 ) ;
else
F_278 ( V_134 ) ;
V_71 = F_272 ( V_2 , V_276 ) ;
V_134 -> V_185 . V_27 . V_26 = F_233 ;
V_134 -> V_185 . V_27 . V_22 = F_229 ;
V_134 -> V_185 . V_27 . V_176 = F_240 ;
V_134 -> V_185 . V_27 . V_175 = F_243 ;
return V_71 ;
}
static int F_287 ( struct V_1 * V_2 ,
T_12 * V_301 ,
T_9 * V_302 ,
T_15 * V_303 ,
T_12 * V_230 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
unsigned int V_276 ;
T_14 V_278 ;
int V_71 ;
* V_303 = F_273 ( V_2 -> V_8 , 2 ) ;
* V_230 = F_274 ( V_2 -> V_8 , 2 ) ;
if ( ( * V_230 < ( 64 << 20 ) || ( * V_230 > ( 512 << 20 ) ) ) ) {
F_214 ( L_32 ,
V_134 -> V_185 . V_230 ) ;
return - V_305 ;
}
if ( ! F_283 ( V_2 -> V_8 , F_284 ( 40 ) ) )
F_285 ( V_2 -> V_8 , F_284 ( 40 ) ) ;
F_286 ( V_2 -> V_8 , V_304 , & V_278 ) ;
* V_302 = F_268 ( V_278 ) ;
V_276 = F_264 ( V_278 ) ;
* V_301 = ( V_276 / sizeof( T_5 ) ) << V_119 ;
V_71 = F_272 ( V_2 , V_276 ) ;
V_134 -> V_185 . V_27 . V_26 = F_235 ;
V_134 -> V_185 . V_27 . V_22 = F_232 ;
V_134 -> V_185 . V_27 . V_176 = F_240 ;
V_134 -> V_185 . V_27 . V_175 = F_243 ;
return V_71 ;
}
static void F_288 ( struct V_82 * V_21 )
{
struct V_306 * V_185 = F_89 ( V_21 , struct V_306 , V_27 ) ;
F_277 ( V_185 -> V_186 ) ;
F_45 ( V_21 -> V_2 , V_21 -> V_84 ) ;
}
static int F_289 ( struct V_1 * V_2 ,
T_12 * V_301 ,
T_9 * V_302 ,
T_15 * V_303 ,
T_12 * V_230 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
int V_71 ;
V_71 = F_290 ( V_134 -> V_307 , V_134 -> V_2 -> V_8 , NULL ) ;
if ( ! V_71 ) {
F_214 ( L_33 ) ;
return - V_308 ;
}
F_291 ( V_301 , V_302 , V_303 , V_230 ) ;
V_134 -> V_185 . V_243 = F_208 ( V_134 -> V_2 ) ;
V_134 -> V_185 . V_27 . V_22 = F_236 ;
V_134 -> V_185 . V_27 . V_26 = F_238 ;
V_134 -> V_185 . V_27 . V_176 = F_240 ;
V_134 -> V_185 . V_27 . V_175 = F_243 ;
if ( F_212 ( V_134 -> V_185 . V_243 ) )
F_5 ( L_34 ) ;
return 0 ;
}
static void F_292 ( struct V_82 * V_21 )
{
F_293 () ;
}
int F_294 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_306 * V_185 = & V_134 -> V_185 ;
int V_71 ;
if ( F_2 ( V_2 ) -> V_6 <= 5 ) {
V_185 -> V_309 = F_289 ;
V_185 -> V_27 . V_173 = F_292 ;
} else if ( F_2 ( V_2 ) -> V_6 < 8 ) {
V_185 -> V_309 = F_287 ;
V_185 -> V_27 . V_173 = F_288 ;
if ( F_166 ( V_2 ) && V_134 -> V_310 )
V_185 -> V_27 . V_85 = F_20 ;
else if ( F_166 ( V_2 ) )
V_185 -> V_27 . V_85 = F_18 ;
else if ( F_6 ( V_2 ) )
V_185 -> V_27 . V_85 = F_17 ;
else if ( F_2 ( V_2 ) -> V_6 >= 7 )
V_185 -> V_27 . V_85 = F_16 ;
else
V_185 -> V_27 . V_85 = F_13 ;
} else {
V_134 -> V_185 . V_309 = F_282 ;
V_134 -> V_185 . V_27 . V_173 = F_288 ;
}
V_185 -> V_27 . V_2 = V_2 ;
V_71 = V_185 -> V_309 ( V_2 , & V_185 -> V_27 . V_165 , & V_185 -> V_311 ,
& V_185 -> V_303 , & V_185 -> V_230 ) ;
if ( V_71 )
return V_71 ;
F_5 ( L_35 ,
V_185 -> V_27 . V_165 >> 20 ) ;
F_8 ( L_36 , V_185 -> V_230 >> 20 ) ;
F_8 ( L_37 , V_185 -> V_311 >> 20 ) ;
#ifdef F_4
if ( V_7 )
F_5 ( L_38 ) ;
#endif
V_10 . V_3 = F_1 ( V_2 , V_10 . V_3 ) ;
F_8 ( L_39 , V_10 . V_3 ) ;
return 0 ;
}
void F_295 ( struct V_1 * V_2 )
{
struct V_133 * V_134 = V_2 -> V_135 ;
struct V_250 * V_18 ;
struct V_82 * V_21 ;
struct V_12 * V_13 ;
bool V_188 ;
F_217 ( V_2 ) ;
V_134 -> V_185 . V_27 . V_26 ( & V_134 -> V_185 . V_27 ,
V_134 -> V_185 . V_27 . V_25 ,
V_134 -> V_185 . V_27 . V_165 ,
true ) ;
V_21 = & V_134 -> V_185 . V_27 ;
F_252 (obj, &dev_priv->mm.bound_list, global_list) {
V_188 = false ;
F_252 (vma, &obj->vma_list, vma_link) {
if ( V_13 -> V_21 != V_21 )
continue;
F_28 ( F_296 ( V_13 , V_18 -> V_15 ,
V_312 ) ) ;
V_188 = true ;
}
if ( V_188 )
F_297 ( V_18 , V_18 -> V_313 ) ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 ) {
if ( F_7 ( V_2 ) || F_33 ( V_2 ) )
F_281 ( V_134 ) ;
else
F_278 ( V_134 ) ;
return;
}
if ( F_199 ( V_2 ) ) {
F_252 (vm, &dev_priv->vm_list, global_link) {
struct V_103 * V_104 =
F_89 ( V_21 , struct V_103 ,
V_27 ) ;
if ( F_298 ( V_21 ) )
V_104 = V_134 -> V_224 . V_237 ;
F_150 ( V_134 , & V_104 -> V_87 ,
0 , V_104 -> V_27 . V_165 ) ;
}
}
F_221 ( V_134 ) ;
}
static struct V_12 *
F_299 ( struct V_250 * V_18 ,
struct V_82 * V_21 ,
const struct V_314 * V_260 )
{
struct V_12 * V_13 ;
if ( F_28 ( F_298 ( V_21 ) != ! ! V_260 ) )
return F_40 ( - V_61 ) ;
V_13 = F_300 ( F_156 ( V_18 -> V_27 . V_2 ) -> V_315 , V_62 ) ;
if ( V_13 == NULL )
return F_40 ( - V_58 ) ;
F_194 ( & V_13 -> V_316 ) ;
F_194 ( & V_13 -> V_275 ) ;
F_194 ( & V_13 -> V_317 ) ;
V_13 -> V_21 = V_21 ;
V_13 -> V_18 = V_18 ;
if ( F_298 ( V_21 ) )
V_13 -> V_260 = * V_260 ;
F_195 ( & V_13 -> V_316 , & V_18 -> V_318 ) ;
if ( ! F_298 ( V_21 ) )
F_301 ( F_302 ( V_21 ) ) ;
return V_13 ;
}
struct V_12 *
F_303 ( struct V_250 * V_18 ,
struct V_82 * V_21 )
{
struct V_12 * V_13 ;
V_13 = F_253 ( V_18 , V_21 ) ;
if ( ! V_13 )
V_13 = F_299 ( V_18 , V_21 ,
F_298 ( V_21 ) ? & V_319 : NULL ) ;
return V_13 ;
}
struct V_12 *
F_304 ( struct V_250 * V_18 ,
const struct V_314 * V_320 )
{
struct V_82 * V_321 = F_305 ( V_18 ) ;
struct V_12 * V_13 ;
if ( F_28 ( ! V_320 ) )
return F_40 ( - V_61 ) ;
V_13 = F_306 ( V_18 , V_320 ) ;
if ( F_104 ( V_13 ) )
return V_13 ;
if ( ! V_13 )
V_13 = F_299 ( V_18 , V_321 , V_320 ) ;
return V_13 ;
}
static struct V_322 *
F_307 ( T_3 * V_323 , unsigned int V_136 ,
unsigned int V_324 , unsigned int V_325 ,
struct V_127 * V_252 , struct V_322 * V_254 )
{
unsigned int V_326 , V_327 ;
unsigned int V_328 ;
if ( ! V_254 ) {
V_252 -> V_251 = 0 ;
V_254 = V_252 -> V_128 ;
}
for ( V_326 = 0 ; V_326 < V_324 ; V_326 ++ ) {
V_328 = V_324 * ( V_325 - 1 ) + V_326 ;
for ( V_327 = 0 ; V_327 < V_325 ; V_327 ++ ) {
V_252 -> V_251 ++ ;
F_308 ( V_254 , NULL , V_64 , 0 ) ;
F_230 ( V_254 ) = V_323 [ V_136 + V_328 ] ;
F_309 ( V_254 ) = V_64 ;
V_254 = F_310 ( V_254 ) ;
V_328 -= V_324 ;
}
}
return V_254 ;
}
static struct V_127 *
F_311 ( struct V_314 * V_260 ,
struct V_250 * V_18 )
{
struct V_329 * V_330 = & V_260 -> V_331 ;
unsigned int V_332 = V_330 -> V_28 >> V_119 ;
unsigned int V_333 ;
struct V_125 V_126 ;
unsigned long V_66 ;
T_3 * V_334 ;
struct V_127 * V_252 ;
unsigned int V_335 ;
struct V_322 * V_254 ;
int V_71 = - V_58 ;
V_334 = F_312 ( V_18 -> V_27 . V_28 / V_64 ,
sizeof( T_3 ) ) ;
if ( ! V_334 )
return F_40 ( V_71 ) ;
if ( V_330 -> V_336 == V_337 )
V_333 = V_330 -> V_338 >> V_119 ;
else
V_333 = 0 ;
V_252 = F_313 ( sizeof( * V_252 ) , V_62 ) ;
if ( ! V_252 )
goto V_339;
V_71 = F_314 ( V_252 , V_332 + V_333 , V_62 ) ;
if ( V_71 )
goto V_340;
V_66 = 0 ;
F_170 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_334 [ V_66 ] = F_97 ( & V_126 ) ;
V_66 ++ ;
}
V_254 = F_307 ( V_334 , 0 ,
V_330 -> V_341 , V_330 -> V_342 ,
V_252 , NULL ) ;
if ( V_330 -> V_336 == V_337 ) {
V_335 = V_332 ;
if ( F_315 ( V_330 -> V_343 ) )
V_335 -- ;
V_330 -> V_335 = V_335 ;
F_307 ( V_334 , V_335 ,
V_330 -> V_344 ,
V_330 -> V_345 ,
V_252 , V_254 ) ;
}
F_254 (
L_40 ,
V_18 -> V_27 . V_28 , V_330 -> V_346 , V_330 -> V_325 ,
V_330 -> V_336 , V_330 -> V_341 ,
V_330 -> V_342 , V_332 + V_333 ,
V_332 ) ;
F_316 ( V_334 ) ;
return V_252 ;
V_340:
F_42 ( V_252 ) ;
V_339:
F_316 ( V_334 ) ;
F_254 (
L_41 ,
V_18 -> V_27 . V_28 , V_71 , V_330 -> V_346 , V_330 -> V_325 ,
V_330 -> V_336 , V_330 -> V_341 ,
V_330 -> V_342 , V_332 + V_333 ,
V_332 ) ;
return F_40 ( V_71 ) ;
}
static struct V_127 *
F_317 ( const struct V_314 * V_320 ,
struct V_250 * V_18 )
{
struct V_127 * V_252 ;
struct V_322 * V_254 ;
struct V_125 V_347 ;
int V_71 = - V_58 ;
V_252 = F_313 ( sizeof( * V_252 ) , V_62 ) ;
if ( ! V_252 )
goto V_339;
V_71 = F_314 ( V_252 , V_320 -> V_348 . V_349 . V_28 , V_62 ) ;
if ( V_71 )
goto V_340;
V_254 = V_252 -> V_128 ;
V_252 -> V_251 = 0 ;
F_170 (obj->pages->sgl, &obj_sg_iter, obj->pages->nents,
view->params.partial.offset)
{
if ( V_252 -> V_251 >= V_320 -> V_348 . V_349 . V_28 )
break;
F_308 ( V_254 , NULL , V_64 , 0 ) ;
F_230 ( V_254 ) = F_97 ( & V_347 ) ;
F_309 ( V_254 ) = V_64 ;
V_254 = F_310 ( V_254 ) ;
V_252 -> V_251 ++ ;
}
return V_252 ;
V_340:
F_42 ( V_252 ) ;
V_339:
return F_40 ( V_71 ) ;
}
static int
F_241 ( struct V_12 * V_13 )
{
int V_71 = 0 ;
if ( V_13 -> V_260 . V_23 )
return 0 ;
if ( V_13 -> V_260 . type == V_350 )
V_13 -> V_260 . V_23 = V_13 -> V_18 -> V_23 ;
else if ( V_13 -> V_260 . type == V_351 )
V_13 -> V_260 . V_23 =
F_311 ( & V_13 -> V_260 , V_13 -> V_18 ) ;
else if ( V_13 -> V_260 . type == V_352 )
V_13 -> V_260 . V_23 =
F_317 ( & V_13 -> V_260 , V_13 -> V_18 ) ;
else
F_318 ( 1 , L_42 ,
V_13 -> V_260 . type ) ;
if ( ! V_13 -> V_260 . V_23 ) {
F_214 ( L_43 ,
V_13 -> V_260 . type ) ;
V_71 = - V_61 ;
} else if ( F_104 ( V_13 -> V_260 . V_23 ) ) {
V_71 = F_105 ( V_13 -> V_260 . V_23 ) ;
V_13 -> V_260 . V_23 = NULL ;
F_214 ( L_44 ,
V_13 -> V_260 . type , V_71 ) ;
}
return V_71 ;
}
int F_296 ( struct V_12 * V_13 , enum V_14 V_15 ,
T_1 V_48 )
{
int V_71 ;
T_1 V_353 ;
if ( F_28 ( V_48 == 0 ) )
return - V_61 ;
V_353 = 0 ;
if ( V_48 & V_354 )
V_353 |= V_262 ;
if ( V_48 & V_355 )
V_353 |= V_263 ;
if ( V_48 & V_312 )
V_353 |= V_13 -> V_261 ;
else
V_353 &= ~ V_13 -> V_261 ;
if ( V_353 == 0 )
return 0 ;
if ( V_13 -> V_261 == 0 && V_13 -> V_21 -> V_174 ) {
F_319 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_24 . V_28 ,
F_320 ( V_13 -> V_21 ) ) ;
V_13 -> V_356 ++ ;
V_71 = V_13 -> V_21 -> V_174 ( V_13 -> V_21 ,
V_13 -> V_24 . V_25 ,
V_13 -> V_24 . V_28 ) ;
V_13 -> V_356 -- ;
if ( V_71 )
return V_71 ;
}
V_71 = V_13 -> V_21 -> V_176 ( V_13 , V_15 , V_353 ) ;
if ( V_71 )
return V_71 ;
V_13 -> V_261 |= V_353 ;
return 0 ;
}
T_9
F_321 ( struct V_250 * V_18 ,
const struct V_314 * V_320 )
{
if ( V_320 -> type == V_350 ) {
return V_18 -> V_27 . V_28 ;
} else if ( V_320 -> type == V_351 ) {
return V_320 -> V_331 . V_28 ;
} else if ( V_320 -> type == V_352 ) {
return V_320 -> V_348 . V_349 . V_28 << V_119 ;
} else {
F_318 ( 1 , L_42 , V_320 -> type ) ;
return V_18 -> V_27 . V_28 ;
}
}
