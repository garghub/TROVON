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
static inline T_1 F_9 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 )
{
T_1 V_16 = V_15 ? V_17 | V_18 : 0 ;
V_16 |= V_12 ;
switch ( V_14 ) {
case V_19 :
V_16 |= V_20 ;
break;
case V_21 :
V_16 |= V_22 ;
break;
default:
V_16 |= V_23 ;
break;
}
return V_16 ;
}
static inline T_3 F_10 ( struct V_1 * V_2 ,
T_2 V_12 ,
enum V_13 V_14 )
{
T_3 V_24 = V_17 | V_18 ;
V_24 |= V_12 ;
if ( V_14 != V_19 )
V_24 |= V_25 ;
else
V_24 |= V_20 ;
return V_24 ;
}
static T_4 F_11 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_12 ( V_12 ) ;
switch ( V_14 ) {
case V_28 :
case V_29 :
V_16 |= V_30 ;
break;
case V_19 :
V_16 |= V_31 ;
break;
default:
F_13 ( V_14 ) ;
}
return V_16 ;
}
static T_4 F_14 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_12 ( V_12 ) ;
switch ( V_14 ) {
case V_28 :
V_16 |= V_32 ;
break;
case V_29 :
V_16 |= V_30 ;
break;
case V_19 :
V_16 |= V_31 ;
break;
default:
F_13 ( V_14 ) ;
}
return V_16 ;
}
static T_4 F_15 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_33 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_12 ( V_12 ) ;
if ( ! ( V_33 & V_34 ) )
V_16 |= V_35 ;
if ( V_14 != V_19 )
V_16 |= V_36 ;
return V_16 ;
}
static T_4 F_16 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_17 ( V_12 ) ;
if ( V_14 != V_19 )
V_16 |= V_37 ;
return V_16 ;
}
static T_4 F_18 ( T_2 V_12 ,
enum V_13 V_14 ,
bool V_15 , T_5 V_26 )
{
T_4 V_16 = V_15 ? V_27 : 0 ;
V_16 |= F_17 ( V_12 ) ;
switch ( V_14 ) {
case V_19 :
break;
case V_21 :
V_16 |= V_38 ;
break;
default:
V_16 |= V_39 ;
break;
}
return V_16 ;
}
static inline void F_19 ( T_2 V_40 ,
struct V_1 * V_2 )
{
struct V_41 * V_41 = & V_2 -> V_8 -> V_2 ;
F_20 ( V_41 , V_40 , 4096 , V_42 ) ;
}
static inline int F_21 ( struct V_43 * V_43 ,
struct V_1 * V_2 ,
T_2 * V_40 )
{
struct V_41 * V_41 = & V_2 -> V_8 -> V_2 ;
* V_40 = F_22 ( V_41 , V_43 , 0 , 4096 , V_42 ) ;
if ( F_23 ( V_41 , * V_40 ) )
return - V_44 ;
return 0 ;
}
static void F_24 ( struct V_45 * V_46 ,
struct V_1 * V_2 )
{
if ( F_25 ( ! V_46 -> V_43 ) )
return;
F_26 ( V_46 , V_2 ) ;
F_27 ( V_46 -> V_43 ) ;
F_28 ( V_46 -> V_47 ) ;
F_28 ( V_46 ) ;
}
static struct V_45 * F_29 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
const T_6 V_48 = F_2 ( V_2 ) -> V_6 >= 8 ?
V_49 : V_50 ;
int V_51 = - V_44 ;
V_46 = F_30 ( sizeof( * V_46 ) , V_52 ) ;
if ( ! V_46 )
return F_31 ( - V_44 ) ;
V_46 -> V_47 = F_32 ( F_33 ( V_48 ) , sizeof( * V_46 -> V_47 ) ,
V_52 ) ;
if ( ! V_46 -> V_47 )
goto V_53;
V_46 -> V_43 = F_34 ( V_52 ) ;
if ( ! V_46 -> V_43 )
goto V_54;
V_51 = F_35 ( V_46 , V_2 ) ;
if ( V_51 )
goto V_55;
return V_46 ;
V_55:
F_27 ( V_46 -> V_43 ) ;
V_54:
F_28 ( V_46 -> V_47 ) ;
V_53:
F_28 ( V_46 ) ;
return F_31 ( V_51 ) ;
}
static int F_36 ( struct V_56 * V_57 , T_7 V_24 , T_6 V_48 ,
struct V_1 * V_2 )
{
int V_58 , V_51 ;
if ( F_25 ( V_24 + V_48 > V_59 ) )
return - V_60 ;
for ( V_58 = V_24 ; V_58 < V_24 + V_48 ; V_58 ++ ) {
struct V_45 * V_46 = F_29 ( V_2 ) ;
if ( F_37 ( V_46 ) ) {
V_51 = F_38 ( V_46 ) ;
goto V_61;
}
F_39 ( V_57 -> V_62 [ V_58 ] ,
L_3 ,
V_58 , V_57 -> V_62 [ V_58 ] ) ;
V_57 -> V_62 [ V_58 ] = V_46 ;
}
return 0 ;
V_61:
while ( V_58 -- > V_24 )
F_24 ( V_57 -> V_62 [ V_58 ] , V_2 ) ;
return V_51 ;
}
static void F_40 ( struct V_56 * V_57 )
{
if ( V_57 -> V_43 ) {
F_27 ( V_57 -> V_43 ) ;
F_28 ( V_57 ) ;
}
}
static struct V_56 * F_41 ( void )
{
struct V_56 * V_57 ;
V_57 = F_30 ( sizeof( * V_57 ) , V_52 ) ;
if ( ! V_57 )
return F_31 ( - V_44 ) ;
V_57 -> V_43 = F_34 ( V_52 | V_63 ) ;
if ( ! V_57 -> V_43 ) {
F_28 ( V_57 ) ;
return F_31 ( - V_44 ) ;
}
return V_57 ;
}
static int F_42 ( struct V_64 * V_65 , unsigned V_66 ,
T_8 V_67 )
{
int V_51 ;
F_43 ( V_66 >= 4 ) ;
V_51 = F_44 ( V_65 , 6 ) ;
if ( V_51 )
return V_51 ;
F_45 ( V_65 , F_46 ( 1 ) ) ;
F_45 ( V_65 , F_47 ( V_65 , V_66 ) ) ;
F_45 ( V_65 , ( T_5 ) ( V_67 >> 32 ) ) ;
F_45 ( V_65 , F_46 ( 1 ) ) ;
F_45 ( V_65 , F_48 ( V_65 , V_66 ) ) ;
F_45 ( V_65 , ( T_5 ) ( V_67 ) ) ;
F_49 ( V_65 ) ;
return 0 ;
}
static int F_50 ( struct V_68 * V_69 ,
struct V_64 * V_65 )
{
int V_58 , V_51 ;
int V_70 = V_69 -> V_71 / V_59 ;
for ( V_58 = V_70 - 1 ; V_58 >= 0 ; V_58 -- ) {
T_2 V_12 = V_69 -> V_72 . V_73 [ V_58 ] -> V_40 ;
V_51 = F_42 ( V_65 , V_58 , V_12 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static void F_51 ( struct V_74 * V_75 ,
T_8 V_76 ,
T_8 V_77 ,
bool V_78 )
{
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 , V_79 ) ;
T_1 * V_80 , V_81 ;
unsigned V_82 = V_76 >> V_83 & V_84 ;
unsigned V_24 = V_76 >> V_85 & V_86 ;
unsigned V_16 = V_76 >> V_87 & V_88 ;
unsigned V_89 = V_77 >> V_90 ;
unsigned V_91 , V_58 ;
V_81 = F_9 ( V_69 -> V_79 . V_92 . V_12 ,
V_29 , V_78 ) ;
while ( V_89 ) {
struct V_56 * V_57 ;
struct V_45 * V_46 ;
struct V_43 * V_62 ;
if ( F_25 ( ! V_69 -> V_72 . V_73 [ V_82 ] ) )
continue;
V_57 = V_69 -> V_72 . V_73 [ V_82 ] ;
if ( F_25 ( ! V_57 -> V_62 [ V_24 ] ) )
continue;
V_46 = V_57 -> V_62 [ V_24 ] ;
if ( F_25 ( ! V_46 -> V_43 ) )
continue;
V_62 = V_46 -> V_43 ;
V_91 = V_16 + V_89 ;
if ( V_91 > V_49 )
V_91 = V_49 ;
V_80 = F_53 ( V_62 ) ;
for ( V_58 = V_16 ; V_58 < V_91 ; V_58 ++ ) {
V_80 [ V_58 ] = V_81 ;
V_89 -- ;
}
if ( ! F_54 ( V_69 -> V_79 . V_2 ) )
F_55 ( V_80 , V_93 ) ;
F_56 ( V_80 ) ;
V_16 = 0 ;
if ( ++ V_24 == V_59 ) {
V_82 ++ ;
V_24 = 0 ;
}
}
}
static void F_57 ( struct V_74 * V_75 ,
struct V_94 * V_95 ,
T_8 V_76 ,
enum V_13 V_96 , T_5 V_26 )
{
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 , V_79 ) ;
T_1 * V_80 ;
unsigned V_82 = V_76 >> V_83 & V_84 ;
unsigned V_24 = V_76 >> V_85 & V_86 ;
unsigned V_16 = V_76 >> V_87 & V_88 ;
struct V_97 V_98 ;
V_80 = NULL ;
F_58 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( F_25 ( V_82 >= V_99 ) )
break;
if ( V_80 == NULL ) {
struct V_56 * V_57 = V_69 -> V_72 . V_73 [ V_82 ] ;
struct V_45 * V_46 = V_57 -> V_62 [ V_24 ] ;
struct V_43 * V_62 = V_46 -> V_43 ;
V_80 = F_53 ( V_62 ) ;
}
V_80 [ V_16 ] =
F_9 ( F_59 ( & V_98 ) ,
V_96 , true ) ;
if ( ++ V_16 == V_49 ) {
if ( ! F_54 ( V_69 -> V_79 . V_2 ) )
F_55 ( V_80 , V_93 ) ;
F_56 ( V_80 ) ;
V_80 = NULL ;
if ( ++ V_24 == V_59 ) {
V_82 ++ ;
V_24 = 0 ;
}
V_16 = 0 ;
}
}
if ( V_80 ) {
if ( ! F_54 ( V_69 -> V_79 . V_2 ) )
F_55 ( V_80 , V_93 ) ;
F_56 ( V_80 ) ;
}
}
static void F_60 ( struct V_56 * V_57 , struct V_1 * V_2 )
{
int V_58 ;
if ( ! V_57 -> V_43 )
return;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( F_25 ( ! V_57 -> V_62 [ V_58 ] ) )
continue;
F_24 ( V_57 -> V_62 [ V_58 ] , V_2 ) ;
V_57 -> V_62 [ V_58 ] = NULL ;
}
}
static void F_61 ( struct V_68 * V_69 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_69 -> V_100 ; V_58 ++ ) {
if ( F_25 ( ! V_69 -> V_72 . V_73 [ V_58 ] ) )
continue;
F_60 ( V_69 -> V_72 . V_73 [ V_58 ] , V_69 -> V_79 . V_2 ) ;
F_40 ( V_69 -> V_72 . V_73 [ V_58 ] ) ;
}
}
static void F_62 ( struct V_68 * V_69 )
{
struct V_101 * V_102 = V_69 -> V_79 . V_2 -> V_8 ;
int V_58 , V_103 ;
for ( V_58 = 0 ; V_58 < V_69 -> V_100 ; V_58 ++ ) {
if ( ! V_69 -> V_72 . V_73 [ V_58 ] -> V_40 )
continue;
F_63 ( V_102 , V_69 -> V_72 . V_73 [ V_58 ] -> V_40 , V_93 ,
V_42 ) ;
for ( V_103 = 0 ; V_103 < V_59 ; V_103 ++ ) {
struct V_56 * V_57 = V_69 -> V_72 . V_73 [ V_58 ] ;
struct V_45 * V_46 ;
T_2 V_12 ;
if ( F_25 ( ! V_57 -> V_62 [ V_103 ] ) )
continue;
V_46 = V_57 -> V_62 [ V_103 ] ;
V_12 = V_46 -> V_40 ;
if ( V_12 )
F_63 ( V_102 , V_12 , V_93 ,
V_42 ) ;
}
}
}
static void F_64 ( struct V_74 * V_75 )
{
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 , V_79 ) ;
F_62 ( V_69 ) ;
F_61 ( V_69 ) ;
}
static int F_65 ( struct V_68 * V_69 )
{
int V_58 , V_51 ;
for ( V_58 = 0 ; V_58 < V_69 -> V_100 ; V_58 ++ ) {
V_51 = F_36 ( V_69 -> V_72 . V_73 [ V_58 ] ,
0 , V_59 , V_69 -> V_79 . V_2 ) ;
if ( V_51 )
goto V_104;
}
return 0 ;
V_104:
while ( V_58 -- )
F_60 ( V_69 -> V_72 . V_73 [ V_58 ] , V_69 -> V_79 . V_2 ) ;
return - V_44 ;
}
static int F_66 ( struct V_68 * V_69 ,
const int V_105 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_105 ; V_58 ++ ) {
V_69 -> V_72 . V_73 [ V_58 ] = F_41 () ;
if ( F_37 ( V_69 -> V_72 . V_73 [ V_58 ] ) )
goto V_104;
}
V_69 -> V_100 = V_105 ;
F_43 ( V_69 -> V_100 > V_99 ) ;
return 0 ;
V_104:
while ( V_58 -- )
F_40 ( V_69 -> V_72 . V_73 [ V_58 ] ) ;
return - V_44 ;
}
static int F_67 ( struct V_68 * V_69 ,
const int V_105 )
{
int V_51 ;
V_51 = F_66 ( V_69 , V_105 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_65 ( V_69 ) ;
if ( V_51 )
goto V_61;
V_69 -> V_71 = V_105 * V_59 ;
return 0 ;
V_61:
F_61 ( V_69 ) ;
return V_51 ;
}
static int F_68 ( struct V_68 * V_69 ,
const int V_57 )
{
T_2 V_106 ;
int V_51 ;
V_106 = F_69 ( V_69 -> V_79 . V_2 -> V_8 ,
V_69 -> V_72 . V_73 [ V_57 ] -> V_43 , 0 ,
V_93 , V_42 ) ;
V_51 = F_70 ( V_69 -> V_79 . V_2 -> V_8 , V_106 ) ;
if ( V_51 )
return V_51 ;
V_69 -> V_72 . V_73 [ V_57 ] -> V_40 = V_106 ;
return 0 ;
}
static int F_71 ( struct V_68 * V_69 ,
const int V_57 ,
const int V_46 )
{
T_2 V_107 ;
struct V_56 * V_108 = V_69 -> V_72 . V_73 [ V_57 ] ;
struct V_45 * V_109 = V_108 -> V_62 [ V_46 ] ;
struct V_43 * V_110 = V_109 -> V_43 ;
int V_51 ;
V_107 = F_69 ( V_69 -> V_79 . V_2 -> V_8 ,
V_110 , 0 , V_93 , V_42 ) ;
V_51 = F_70 ( V_69 -> V_79 . V_2 -> V_8 , V_107 ) ;
if ( V_51 )
return V_51 ;
V_109 -> V_40 = V_107 ;
return 0 ;
}
static int F_72 ( struct V_68 * V_69 , T_8 V_111 )
{
const int V_105 = F_73 ( V_111 , 1 << 30 ) ;
const int V_112 = V_59 * V_105 ;
int V_58 , V_103 , V_51 ;
if ( V_111 % ( 1 << 30 ) )
F_5 ( L_4 , V_111 ) ;
V_51 = F_67 ( V_69 , V_99 ) ;
if ( V_51 )
return V_51 ;
for ( V_58 = 0 ; V_58 < V_99 ; V_58 ++ ) {
V_51 = F_68 ( V_69 , V_58 ) ;
if ( V_51 )
goto V_113;
for ( V_103 = 0 ; V_103 < V_59 ; V_103 ++ ) {
V_51 = F_71 ( V_69 , V_58 , V_103 ) ;
if ( V_51 )
goto V_113;
}
}
for ( V_58 = 0 ; V_58 < V_99 ; V_58 ++ ) {
struct V_56 * V_57 = V_69 -> V_72 . V_73 [ V_58 ] ;
T_3 * V_114 ;
V_114 = F_53 ( V_69 -> V_72 . V_73 [ V_58 ] -> V_43 ) ;
for ( V_103 = 0 ; V_103 < V_59 ; V_103 ++ ) {
struct V_45 * V_46 = V_57 -> V_62 [ V_103 ] ;
T_2 V_12 = V_46 -> V_40 ;
V_114 [ V_103 ] = F_10 ( V_69 -> V_79 . V_2 , V_12 ,
V_29 ) ;
}
if ( ! F_54 ( V_69 -> V_79 . V_2 ) )
F_55 ( V_114 , V_93 ) ;
F_56 ( V_114 ) ;
}
V_69 -> V_115 = F_50 ;
V_69 -> V_79 . V_116 = F_51 ;
V_69 -> V_79 . V_117 = F_57 ;
V_69 -> V_79 . V_118 = F_64 ;
V_69 -> V_79 . V_76 = 0 ;
V_69 -> V_79 . V_119 = V_105 * V_59 * V_49 * V_93 ;
V_69 -> V_79 . V_116 ( & V_69 -> V_79 , 0 ,
V_69 -> V_100 * V_49 * V_93 ,
true ) ;
F_8 ( L_5 ,
V_69 -> V_100 , V_69 -> V_100 - V_105 ) ;
F_8 ( L_6 ,
V_69 -> V_71 ,
( V_69 -> V_71 - V_112 ) + V_111 % ( 1 << 30 ) ) ;
return 0 ;
V_113:
F_62 ( V_69 ) ;
F_61 ( V_69 ) ;
return V_51 ;
}
static void F_74 ( struct V_68 * V_69 , struct V_120 * V_121 )
{
struct V_122 * V_123 = V_69 -> V_79 . V_2 -> V_124 ;
struct V_74 * V_75 = & V_69 -> V_79 ;
T_4 T_9 * V_106 ;
T_4 V_81 ;
T_10 V_125 ;
int V_16 , V_24 ;
V_81 = V_75 -> V_126 ( V_75 -> V_92 . V_12 , V_29 , true , 0 ) ;
V_106 = ( T_4 T_9 * ) V_123 -> V_127 . V_128 +
V_69 -> V_57 . V_129 / sizeof( T_4 ) ;
F_75 ( V_121 , L_7 , V_75 ,
V_69 -> V_57 . V_129 ,
V_69 -> V_57 . V_129 + V_69 -> V_71 ) ;
for ( V_24 = 0 ; V_24 < V_69 -> V_71 ; V_24 ++ ) {
T_5 V_130 ;
T_4 * V_80 ;
T_2 V_107 = V_69 -> V_57 . V_62 [ V_24 ] -> V_40 ;
V_125 = F_76 ( V_106 + V_24 ) ;
V_130 = ( F_77 ( V_107 ) | V_131 ) ;
if ( V_125 != V_130 )
F_75 ( V_121 , L_8 ,
V_24 ,
V_125 ,
V_130 ) ;
F_75 ( V_121 , L_9 , V_125 ) ;
V_80 = F_53 ( V_69 -> V_57 . V_62 [ V_24 ] -> V_43 ) ;
for ( V_16 = 0 ; V_16 < V_50 ; V_16 += 4 ) {
unsigned long V_132 =
( V_24 * V_93 * V_50 ) +
( V_16 * V_93 ) ;
int V_58 ;
bool V_133 = false ;
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ )
if ( V_80 [ V_16 + V_58 ] != V_81 )
V_133 = true ;
if ( ! V_133 )
continue;
F_75 ( V_121 , L_10 , V_132 , V_24 , V_16 ) ;
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ ) {
if ( V_80 [ V_16 + V_58 ] != V_81 )
F_75 ( V_121 , L_11 , V_80 [ V_16 + V_58 ] ) ;
else
F_78 ( V_121 , L_12 ) ;
}
F_78 ( V_121 , L_13 ) ;
}
F_56 ( V_80 ) ;
}
}
static void F_79 ( struct V_56 * V_57 ,
const int V_24 , struct V_45 * V_46 )
{
struct V_68 * V_69 =
F_52 ( V_57 , struct V_68 , V_57 ) ;
T_5 V_125 ;
V_125 = F_77 ( V_46 -> V_40 ) ;
V_125 |= V_131 ;
F_80 ( V_125 , V_69 -> V_106 + V_24 ) ;
}
static void F_81 ( struct V_122 * V_123 ,
struct V_56 * V_57 ,
T_10 V_76 , T_10 V_77 )
{
struct V_45 * V_46 ;
T_10 V_24 , V_134 ;
F_82 (pt, pd, start, length, temp, pde)
F_79 ( V_57 , V_24 , V_46 ) ;
F_76 ( V_123 -> V_127 . V_128 ) ;
}
static T_10 F_83 ( struct V_68 * V_69 )
{
F_43 ( V_69 -> V_57 . V_129 & 0x3f ) ;
return ( V_69 -> V_57 . V_129 / 64 ) << 16 ;
}
static int F_84 ( struct V_68 * V_69 ,
struct V_64 * V_65 )
{
int V_51 ;
V_51 = V_65 -> V_135 ( V_65 , V_136 , V_136 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_44 ( V_65 , 6 ) ;
if ( V_51 )
return V_51 ;
F_45 ( V_65 , F_46 ( 2 ) ) ;
F_45 ( V_65 , F_85 ( V_65 ) ) ;
F_45 ( V_65 , V_137 ) ;
F_45 ( V_65 , F_86 ( V_65 ) ) ;
F_45 ( V_65 , F_83 ( V_69 ) ) ;
F_45 ( V_65 , V_138 ) ;
F_49 ( V_65 ) ;
return 0 ;
}
static int F_87 ( struct V_68 * V_69 ,
struct V_64 * V_65 )
{
struct V_122 * V_123 = F_88 ( V_69 -> V_79 . V_2 ) ;
F_89 ( F_85 ( V_65 ) , V_137 ) ;
F_89 ( F_86 ( V_65 ) , F_83 ( V_69 ) ) ;
return 0 ;
}
static int F_90 ( struct V_68 * V_69 ,
struct V_64 * V_65 )
{
int V_51 ;
V_51 = V_65 -> V_135 ( V_65 , V_136 , V_136 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_44 ( V_65 , 6 ) ;
if ( V_51 )
return V_51 ;
F_45 ( V_65 , F_46 ( 2 ) ) ;
F_45 ( V_65 , F_85 ( V_65 ) ) ;
F_45 ( V_65 , V_137 ) ;
F_45 ( V_65 , F_86 ( V_65 ) ) ;
F_45 ( V_65 , F_83 ( V_69 ) ) ;
F_45 ( V_65 , V_138 ) ;
F_49 ( V_65 ) ;
if ( V_65 -> V_139 != V_140 ) {
V_51 = V_65 -> V_135 ( V_65 , V_136 , V_136 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static int F_91 ( struct V_68 * V_69 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = V_69 -> V_79 . V_2 ;
struct V_122 * V_123 = V_2 -> V_124 ;
F_89 ( F_85 ( V_65 ) , V_137 ) ;
F_89 ( F_86 ( V_65 ) , F_83 ( V_69 ) ) ;
F_92 ( F_85 ( V_65 ) ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_64 * V_65 ;
int V_103 ;
F_94 (ring, dev_priv, j) {
F_89 ( F_95 ( V_65 ) ,
F_96 ( V_141 ) ) ;
}
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_64 * V_65 ;
T_10 V_142 , V_143 ;
int V_58 ;
V_143 = F_98 ( V_144 ) ;
F_89 ( V_144 , V_143 | V_145 ) ;
V_142 = F_98 ( V_146 ) ;
if ( F_99 ( V_2 ) ) {
V_142 |= V_147 ;
} else {
V_142 |= V_148 ;
V_142 &= ~ V_149 ;
}
F_89 ( V_146 , V_142 ) ;
F_94 (ring, dev_priv, i) {
F_89 ( F_95 ( V_65 ) ,
F_96 ( V_141 ) ) ;
}
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
T_10 V_142 , V_150 , V_143 ;
V_143 = F_98 ( V_144 ) ;
F_89 ( V_144 , V_143 | V_151 |
V_145 ) ;
V_150 = F_98 ( V_152 ) ;
F_89 ( V_152 , V_150 | V_153 ) ;
V_142 = F_98 ( V_146 ) ;
F_89 ( V_146 , V_142 | V_154 | V_155 ) ;
F_89 ( V_156 , F_96 ( V_141 ) ) ;
}
static void F_101 ( struct V_74 * V_75 ,
T_8 V_76 ,
T_8 V_77 ,
bool V_78 )
{
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 , V_79 ) ;
T_4 * V_80 , V_81 ;
unsigned V_157 = V_76 >> V_90 ;
unsigned V_89 = V_77 >> V_90 ;
unsigned V_158 = V_157 / V_50 ;
unsigned V_159 = V_157 % V_50 ;
unsigned V_91 , V_58 ;
V_81 = V_75 -> V_126 ( V_75 -> V_92 . V_12 , V_29 , true , 0 ) ;
while ( V_89 ) {
V_91 = V_159 + V_89 ;
if ( V_91 > V_50 )
V_91 = V_50 ;
V_80 = F_53 ( V_69 -> V_57 . V_62 [ V_158 ] -> V_43 ) ;
for ( V_58 = V_159 ; V_58 < V_91 ; V_58 ++ )
V_80 [ V_58 ] = V_81 ;
F_56 ( V_80 ) ;
V_89 -= V_91 - V_159 ;
V_159 = 0 ;
V_158 ++ ;
}
}
static void F_102 ( struct V_74 * V_75 ,
struct V_94 * V_95 ,
T_8 V_76 ,
enum V_13 V_96 , T_5 V_33 )
{
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 , V_79 ) ;
T_4 * V_80 ;
unsigned V_157 = V_76 >> V_90 ;
unsigned V_158 = V_157 / V_50 ;
unsigned V_160 = V_157 % V_50 ;
struct V_97 V_98 ;
V_80 = NULL ;
F_58 (pages->sgl, &sg_iter, pages->nents, 0 ) {
if ( V_80 == NULL )
V_80 = F_53 ( V_69 -> V_57 . V_62 [ V_158 ] -> V_43 ) ;
V_80 [ V_160 ] =
V_75 -> V_126 ( F_59 ( & V_98 ) ,
V_96 , true , V_33 ) ;
if ( ++ V_160 == V_50 ) {
F_56 ( V_80 ) ;
V_80 = NULL ;
V_158 ++ ;
V_160 = 0 ;
}
}
if ( V_80 )
F_56 ( V_80 ) ;
}
static inline void F_103 ( struct V_68 * V_69 )
{
V_69 -> V_161 = F_2 ( V_69 -> V_79 . V_2 ) -> V_162 ;
}
static void F_104 ( struct V_74 * V_75 ,
struct V_45 * V_46 )
{
T_4 * V_80 , V_81 ;
int V_58 ;
F_25 ( V_75 -> V_92 . V_12 == 0 ) ;
V_81 = V_75 -> V_126 ( V_75 -> V_92 . V_12 ,
V_29 , true , 0 ) ;
V_80 = F_53 ( V_46 -> V_43 ) ;
for ( V_58 = 0 ; V_58 < V_50 ; V_58 ++ )
V_80 [ V_58 ] = V_81 ;
F_56 ( V_80 ) ;
}
static int F_105 ( struct V_74 * V_75 ,
T_8 V_76 , T_8 V_77 )
{
F_106 ( V_163 , V_59 ) ;
struct V_1 * V_2 = V_75 -> V_2 ;
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 , V_79 ) ;
struct V_45 * V_46 ;
const T_10 V_164 = V_76 , V_165 = V_77 ;
T_10 V_24 , V_134 ;
int V_51 ;
F_25 ( F_107 ( V_76 ) ) ;
F_108 ( V_163 , V_59 ) ;
F_82 (pt, &ppgtt->pd, start, length, temp, pde) {
if ( V_46 != V_69 -> V_166 ) {
F_25 ( F_109 ( V_46 -> V_47 , V_50 ) ) ;
continue;
}
F_25 ( ! F_109 ( V_46 -> V_47 , V_50 ) ) ;
V_46 = F_29 ( V_2 ) ;
if ( F_37 ( V_46 ) ) {
V_51 = F_38 ( V_46 ) ;
goto V_104;
}
F_104 ( V_75 , V_46 ) ;
V_69 -> V_57 . V_62 [ V_24 ] = V_46 ;
F_110 ( V_24 , V_163 ) ;
F_111 ( V_75 , V_24 , V_76 , V_167 ) ;
}
V_76 = V_164 ;
V_77 = V_165 ;
F_82 (pt, &ppgtt->pd, start, length, temp, pde) {
F_106 ( V_168 , V_50 ) ;
F_108 ( V_168 , V_50 ) ;
F_112 ( V_168 , F_113 ( V_76 ) ,
F_114 ( V_76 , V_77 ) ) ;
if ( F_115 ( V_24 , V_163 ) )
F_79 ( & V_69 -> V_57 , V_24 , V_46 ) ;
F_116 ( V_75 , V_24 , V_46 ,
F_113 ( V_76 ) ,
F_114 ( V_76 , V_77 ) ,
V_50 ) ;
F_117 ( V_46 -> V_47 , V_168 , V_46 -> V_47 ,
V_50 ) ;
}
F_25 ( ! F_109 ( V_163 , V_59 ) ) ;
F_76 ( V_123 -> V_127 . V_128 ) ;
F_103 ( V_69 ) ;
return 0 ;
V_104:
F_118 (pde, new_page_tables, I915_PDES) {
struct V_45 * V_46 = V_69 -> V_57 . V_62 [ V_24 ] ;
V_69 -> V_57 . V_62 [ V_24 ] = V_69 -> V_166 ;
F_24 ( V_46 , V_75 -> V_2 ) ;
}
F_103 ( V_69 ) ;
return V_51 ;
}
static void F_119 ( struct V_68 * V_69 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_69 -> V_71 ; V_58 ++ ) {
struct V_45 * V_46 = V_69 -> V_57 . V_62 [ V_58 ] ;
if ( V_46 != V_69 -> V_166 )
F_24 ( V_69 -> V_57 . V_62 [ V_58 ] , V_69 -> V_79 . V_2 ) ;
}
F_24 ( V_69 -> V_166 , V_69 -> V_79 . V_2 ) ;
F_40 ( & V_69 -> V_57 ) ;
}
static void F_120 ( struct V_74 * V_75 )
{
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 , V_79 ) ;
F_121 ( & V_69 -> V_169 ) ;
F_119 ( V_69 ) ;
}
static int F_122 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = V_69 -> V_79 . V_2 ;
struct V_122 * V_123 = V_2 -> V_124 ;
bool V_170 = false ;
int V_51 ;
F_43 ( ! F_123 ( & V_123 -> V_127 . V_79 . V_171 ) ) ;
V_69 -> V_166 = F_29 ( V_69 -> V_79 . V_2 ) ;
if ( F_37 ( V_69 -> V_166 ) )
return F_38 ( V_69 -> V_166 ) ;
F_104 ( & V_69 -> V_79 , V_69 -> V_166 ) ;
V_172:
V_51 = F_124 ( & V_123 -> V_127 . V_79 . V_171 ,
& V_69 -> V_169 , V_173 ,
V_174 , 0 ,
0 , V_123 -> V_127 . V_79 . V_119 ,
V_175 ) ;
if ( V_51 == - V_176 && ! V_170 ) {
V_51 = F_125 ( V_2 , & V_123 -> V_127 . V_79 ,
V_173 , V_174 ,
V_19 ,
0 , V_123 -> V_127 . V_79 . V_119 ,
0 ) ;
if ( V_51 )
goto V_61;
V_170 = true ;
goto V_172;
}
if ( V_51 )
goto V_61;
if ( V_69 -> V_169 . V_76 < V_123 -> V_127 . V_177 )
F_126 ( L_14 ) ;
V_69 -> V_71 = V_59 ;
return 0 ;
V_61:
F_24 ( V_69 -> V_166 , V_69 -> V_79 . V_2 ) ;
return V_51 ;
}
static int F_127 ( struct V_68 * V_69 )
{
return F_122 ( V_69 ) ;
}
static void F_128 ( struct V_68 * V_69 ,
T_8 V_76 , T_8 V_77 )
{
struct V_45 * V_26 ;
T_10 V_24 , V_134 ;
F_82 (unused, &ppgtt->pd, start, length, temp, pde)
V_69 -> V_57 . V_62 [ V_24 ] = V_69 -> V_166 ;
}
static int F_129 ( struct V_68 * V_69 , bool V_178 )
{
struct V_1 * V_2 = V_69 -> V_79 . V_2 ;
struct V_122 * V_123 = V_2 -> V_124 ;
int V_51 ;
V_69 -> V_79 . V_126 = V_123 -> V_127 . V_79 . V_126 ;
if ( F_130 ( V_2 ) ) {
V_69 -> V_115 = F_91 ;
} else if ( F_99 ( V_2 ) ) {
V_69 -> V_115 = F_84 ;
} else if ( F_131 ( V_2 ) ) {
V_69 -> V_115 = F_90 ;
} else
F_132 () ;
if ( F_3 ( V_2 ) )
V_69 -> V_115 = F_87 ;
V_51 = F_127 ( V_69 ) ;
if ( V_51 )
return V_51 ;
if ( V_178 ) {
V_51 = F_36 ( & V_69 -> V_57 , 0 , V_69 -> V_71 ,
V_69 -> V_79 . V_2 ) ;
if ( V_51 ) {
F_120 ( & V_69 -> V_79 ) ;
return V_51 ;
}
}
V_69 -> V_79 . V_179 = F_105 ;
V_69 -> V_79 . V_116 = F_101 ;
V_69 -> V_79 . V_117 = F_102 ;
V_69 -> V_79 . V_118 = F_120 ;
V_69 -> V_79 . V_76 = 0 ;
V_69 -> V_79 . V_119 = V_69 -> V_71 * V_50 * V_93 ;
V_69 -> V_180 = F_74 ;
V_69 -> V_57 . V_129 =
V_69 -> V_169 . V_76 / V_93 * sizeof( T_4 ) ;
V_69 -> V_106 = ( T_4 T_9 * ) V_123 -> V_127 . V_128 +
V_69 -> V_57 . V_129 / sizeof( T_4 ) ;
if ( V_178 )
V_69 -> V_79 . V_116 ( & V_69 -> V_79 , 0 , V_69 -> V_79 . V_119 , true ) ;
else
F_128 ( V_69 , 0 , V_69 -> V_79 . V_119 ) ;
F_81 ( V_123 , & V_69 -> V_57 , 0 , V_69 -> V_79 . V_119 ) ;
F_8 ( L_15 ,
V_69 -> V_169 . V_111 >> 20 ,
V_69 -> V_169 . V_76 / V_93 ) ;
F_126 ( L_16 ,
V_69 -> V_57 . V_129 << 10 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , struct V_68 * V_69 ,
bool V_178 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
V_69 -> V_79 . V_2 = V_2 ;
V_69 -> V_79 . V_92 = V_123 -> V_127 . V_79 . V_92 ;
if ( F_2 ( V_2 ) -> V_6 < 8 )
return F_129 ( V_69 , V_178 ) ;
else
return F_72 ( V_69 , V_123 -> V_127 . V_79 . V_119 ) ;
}
int F_134 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
int V_51 = 0 ;
V_51 = F_133 ( V_2 , V_69 , false ) ;
if ( V_51 == 0 ) {
F_135 ( & V_69 -> V_181 ) ;
F_136 ( & V_69 -> V_79 . V_171 , V_69 -> V_79 . V_76 ,
V_69 -> V_79 . V_119 ) ;
F_137 ( V_123 , & V_69 -> V_79 ) ;
}
return V_51 ;
}
int F_138 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_64 * V_65 ;
struct V_68 * V_69 = V_123 -> V_171 . V_182 ;
int V_58 , V_51 = 0 ;
if ( V_10 . V_11 )
return 0 ;
if ( ! F_139 ( V_2 ) )
return 0 ;
if ( F_130 ( V_2 ) )
F_100 ( V_2 ) ;
else if ( F_131 ( V_2 ) )
F_97 ( V_2 ) ;
else if ( F_2 ( V_2 ) -> V_6 >= 8 )
F_93 ( V_2 ) ;
else
F_13 ( F_2 ( V_2 ) -> V_6 ) ;
if ( V_69 ) {
F_94 (ring, dev_priv, i) {
V_51 = V_69 -> V_115 ( V_69 , V_65 ) ;
if ( V_51 != 0 )
return V_51 ;
}
}
return V_51 ;
}
struct V_68 *
F_140 ( struct V_1 * V_2 , struct V_183 * V_184 )
{
struct V_68 * V_69 ;
int V_51 ;
V_69 = F_30 ( sizeof( * V_69 ) , V_52 ) ;
if ( ! V_69 )
return F_31 ( - V_44 ) ;
V_51 = F_134 ( V_2 , V_69 ) ;
if ( V_51 ) {
F_28 ( V_69 ) ;
return F_31 ( V_51 ) ;
}
V_69 -> V_185 = V_184 ;
F_141 ( & V_69 -> V_79 ) ;
return V_69 ;
}
void F_142 ( struct V_186 * V_186 )
{
struct V_68 * V_69 =
F_52 ( V_186 , struct V_68 , V_181 ) ;
F_143 ( & V_69 -> V_79 ) ;
F_25 ( ! F_144 ( & V_69 -> V_79 . V_187 ) ) ;
F_25 ( ! F_144 ( & V_69 -> V_79 . V_188 ) ) ;
F_145 ( & V_69 -> V_79 . V_189 ) ;
F_146 ( & V_69 -> V_79 . V_171 ) ;
V_69 -> V_79 . V_118 ( & V_69 -> V_79 ) ;
F_28 ( V_69 ) ;
}
static void
F_147 ( struct V_190 * V_191 ,
enum V_13 V_96 ,
T_5 V_33 )
{
if ( V_191 -> V_192 -> V_193 )
V_33 |= V_34 ;
V_191 -> V_75 -> V_117 ( V_191 -> V_75 , V_191 -> V_192 -> V_95 , V_191 -> V_169 . V_76 ,
V_96 , V_33 ) ;
}
static void F_148 ( struct V_190 * V_191 )
{
V_191 -> V_75 -> V_116 ( V_191 -> V_75 ,
V_191 -> V_169 . V_76 ,
V_191 -> V_192 -> V_79 . V_111 ,
true ) ;
}
static inline bool F_149 ( struct V_1 * V_2 )
{
#ifdef F_4
if ( F_150 ( V_2 ) && F_151 ( V_2 ) && V_7 )
return true ;
#endif
return false ;
}
static bool F_152 ( struct V_122 * V_123 )
{
bool V_51 = V_123 -> V_171 . V_194 ;
if ( F_153 ( V_123 -> V_127 . V_195 ) ) {
V_123 -> V_171 . V_194 = false ;
if ( F_154 ( V_123 -> V_2 ) ) {
F_155 ( L_17 ) ;
F_156 ( 10 ) ;
}
}
return V_51 ;
}
static void F_157 ( struct V_122 * V_123 , bool V_194 )
{
if ( F_153 ( V_123 -> V_127 . V_195 ) )
V_123 -> V_171 . V_194 = V_194 ;
}
void F_158 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_64 * V_65 ;
int V_58 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_94 (ring, dev_priv, i) {
T_5 V_196 ;
V_196 = F_98 ( F_159 ( V_65 ) ) ;
if ( V_196 & V_197 ) {
F_8 ( L_18
L_19
L_20
L_21
L_22 ,
V_196 & V_198 ,
V_196 & V_199 ? L_23 : L_24 ,
F_160 ( V_196 ) ,
F_161 ( V_196 ) ) ;
F_89 ( F_159 ( V_65 ) ,
V_196 & ~ V_197 ) ;
}
}
F_92 ( F_159 ( & V_123 -> V_65 [ V_140 ] ) ) ;
}
static void F_162 ( struct V_122 * V_123 )
{
if ( F_2 ( V_123 -> V_2 ) -> V_6 < 6 ) {
F_163 () ;
} else {
F_89 ( V_200 , V_201 ) ;
F_92 ( V_200 ) ;
}
}
void F_164 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
if ( F_2 ( V_2 ) -> V_6 < 6 )
return;
F_158 ( V_2 ) ;
V_123 -> V_127 . V_79 . V_116 ( & V_123 -> V_127 . V_79 ,
V_123 -> V_127 . V_79 . V_76 ,
V_123 -> V_127 . V_79 . V_119 ,
true ) ;
F_162 ( V_123 ) ;
}
void F_165 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_202 * V_192 ;
struct V_74 * V_75 ;
F_158 ( V_2 ) ;
V_123 -> V_127 . V_79 . V_116 ( & V_123 -> V_127 . V_79 ,
V_123 -> V_127 . V_79 . V_76 ,
V_123 -> V_127 . V_79 . V_119 ,
true ) ;
F_166 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_190 * V_191 = F_167 ( V_192 ,
& V_123 -> V_127 . V_79 ) ;
if ( ! V_191 )
continue;
F_168 ( V_192 , V_192 -> V_203 ) ;
V_191 -> V_204 &= ~ V_205 ;
F_25 ( F_169 ( V_191 , V_192 -> V_96 , V_205 ) ) ;
}
if ( F_2 ( V_2 ) -> V_6 >= 8 ) {
if ( F_7 ( V_2 ) )
F_170 ( V_123 ) ;
else
F_171 ( V_123 ) ;
return;
}
if ( F_139 ( V_2 ) ) {
F_166 (vm, &dev_priv->vm_list, global_link) {
struct V_68 * V_69 =
F_52 ( V_75 , struct V_68 ,
V_79 ) ;
if ( F_172 ( V_75 ) )
V_69 = V_123 -> V_171 . V_182 ;
F_81 ( V_123 , & V_69 -> V_57 ,
0 , V_69 -> V_79 . V_119 ) ;
}
}
F_162 ( V_123 ) ;
}
int F_173 ( struct V_202 * V_192 )
{
if ( V_192 -> V_206 )
return 0 ;
if ( ! F_174 ( & V_192 -> V_79 . V_2 -> V_8 -> V_2 ,
V_192 -> V_95 -> V_207 , V_192 -> V_95 -> V_208 ,
V_42 ) )
return - V_176 ;
return 0 ;
}
static inline void F_175 ( void T_9 * V_12 , T_1 V_16 )
{
#ifdef F_176
F_176 ( V_16 , V_12 ) ;
#else
F_177 ( ( T_5 ) V_16 , V_12 ) ;
F_177 ( V_16 >> 32 , V_12 + 4 ) ;
#endif
}
static void F_178 ( struct V_74 * V_75 ,
struct V_94 * V_209 ,
T_8 V_76 ,
enum V_13 V_14 , T_5 V_26 )
{
struct V_122 * V_123 = V_75 -> V_2 -> V_124 ;
unsigned V_157 = V_76 >> V_90 ;
T_1 T_9 * V_210 =
( T_1 T_9 * ) V_123 -> V_127 . V_128 + V_157 ;
int V_58 = 0 ;
struct V_97 V_98 ;
T_2 V_12 = 0 ;
F_58 (st->sgl, &sg_iter, st->nents, 0 ) {
V_12 = F_179 ( V_98 . V_211 ) +
( V_98 . V_212 << V_90 ) ;
F_175 ( & V_210 [ V_58 ] ,
F_9 ( V_12 , V_14 , true ) ) ;
V_58 ++ ;
}
if ( V_58 != 0 )
F_25 ( F_180 ( & V_210 [ V_58 - 1 ] )
!= F_9 ( V_12 , V_14 , true ) ) ;
F_89 ( V_200 , V_201 ) ;
F_92 ( V_200 ) ;
}
static void F_181 ( struct V_74 * V_75 ,
struct V_94 * V_209 ,
T_8 V_76 ,
enum V_13 V_14 , T_5 V_33 )
{
struct V_122 * V_123 = V_75 -> V_2 -> V_124 ;
unsigned V_157 = V_76 >> V_90 ;
T_4 T_9 * V_210 =
( T_4 T_9 * ) V_123 -> V_127 . V_128 + V_157 ;
int V_58 = 0 ;
struct V_97 V_98 ;
T_2 V_12 = 0 ;
F_58 (st->sgl, &sg_iter, st->nents, 0 ) {
V_12 = F_59 ( & V_98 ) ;
F_177 ( V_75 -> V_126 ( V_12 , V_14 , true , V_33 ) , & V_210 [ V_58 ] ) ;
V_58 ++ ;
}
if ( V_58 != 0 ) {
unsigned long V_127 = F_76 ( & V_210 [ V_58 - 1 ] ) ;
F_25 ( V_127 != V_75 -> V_126 ( V_12 , V_14 , true , V_33 ) ) ;
}
F_89 ( V_200 , V_201 ) ;
F_92 ( V_200 ) ;
}
static void F_182 ( struct V_74 * V_75 ,
T_8 V_76 ,
T_8 V_77 ,
bool V_78 )
{
struct V_122 * V_123 = V_75 -> V_2 -> V_124 ;
unsigned V_157 = V_76 >> V_90 ;
unsigned V_89 = V_77 >> V_90 ;
T_1 V_81 , T_9 * V_213 =
( T_1 T_9 * ) V_123 -> V_127 . V_128 + V_157 ;
const int V_214 = F_183 ( V_123 -> V_127 ) - V_157 ;
int V_58 ;
if ( F_39 ( V_89 > V_214 ,
L_25 ,
V_157 , V_89 , V_214 ) )
V_89 = V_214 ;
V_81 = F_9 ( V_75 -> V_92 . V_12 ,
V_29 ,
V_78 ) ;
for ( V_58 = 0 ; V_58 < V_89 ; V_58 ++ )
F_175 ( & V_213 [ V_58 ] , V_81 ) ;
F_76 ( V_213 ) ;
}
static void F_184 ( struct V_74 * V_75 ,
T_8 V_76 ,
T_8 V_77 ,
bool V_78 )
{
struct V_122 * V_123 = V_75 -> V_2 -> V_124 ;
unsigned V_157 = V_76 >> V_90 ;
unsigned V_89 = V_77 >> V_90 ;
T_4 V_81 , T_9 * V_213 =
( T_4 T_9 * ) V_123 -> V_127 . V_128 + V_157 ;
const int V_214 = F_183 ( V_123 -> V_127 ) - V_157 ;
int V_58 ;
if ( F_39 ( V_89 > V_214 ,
L_25 ,
V_157 , V_89 , V_214 ) )
V_89 = V_214 ;
V_81 = V_75 -> V_126 ( V_75 -> V_92 . V_12 , V_29 , V_78 , 0 ) ;
for ( V_58 = 0 ; V_58 < V_89 ; V_58 ++ )
F_177 ( V_81 , & V_213 [ V_58 ] ) ;
F_76 ( V_213 ) ;
}
static void F_185 ( struct V_190 * V_191 ,
enum V_13 V_96 ,
T_5 V_26 )
{
const unsigned long V_66 = V_191 -> V_169 . V_76 >> V_90 ;
unsigned int V_33 = ( V_96 == V_19 ) ?
V_215 : V_216 ;
F_43 ( ! F_172 ( V_191 -> V_75 ) ) ;
F_186 ( V_191 -> V_217 . V_95 , V_66 , V_33 ) ;
V_191 -> V_204 = V_205 ;
}
static void F_187 ( struct V_74 * V_75 ,
T_8 V_76 ,
T_8 V_77 ,
bool V_26 )
{
unsigned V_157 = V_76 >> V_90 ;
unsigned V_89 = V_77 >> V_90 ;
F_188 ( V_157 , V_89 ) ;
}
static void F_189 ( struct V_190 * V_191 )
{
const unsigned int V_218 = V_191 -> V_169 . V_76 >> V_90 ;
const unsigned int V_111 = V_191 -> V_192 -> V_79 . V_111 >> V_90 ;
F_43 ( ! F_172 ( V_191 -> V_75 ) ) ;
V_191 -> V_204 = 0 ;
F_188 ( V_218 , V_111 ) ;
}
static void F_190 ( struct V_190 * V_191 ,
enum V_13 V_96 ,
T_5 V_33 )
{
struct V_1 * V_2 = V_191 -> V_75 -> V_2 ;
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_202 * V_192 = V_191 -> V_192 ;
struct V_94 * V_95 = V_192 -> V_95 ;
if ( V_192 -> V_193 )
V_33 |= V_34 ;
if ( F_172 ( V_191 -> V_75 ) )
V_95 = V_191 -> V_217 . V_95 ;
if ( ! V_123 -> V_171 . V_182 || V_33 & V_205 ) {
if ( ! ( V_191 -> V_204 & V_205 ) ||
( V_96 != V_192 -> V_96 ) ) {
V_191 -> V_75 -> V_117 ( V_191 -> V_75 , V_95 ,
V_191 -> V_169 . V_76 ,
V_96 , V_33 ) ;
V_191 -> V_204 |= V_205 ;
}
}
if ( V_123 -> V_171 . V_182 &&
( ! ( V_191 -> V_204 & V_219 ) ||
( V_96 != V_192 -> V_96 ) ) ) {
struct V_68 * V_220 = V_123 -> V_171 . V_182 ;
V_220 -> V_79 . V_117 ( & V_220 -> V_79 , V_95 ,
V_191 -> V_169 . V_76 ,
V_96 , V_33 ) ;
V_191 -> V_204 |= V_219 ;
}
}
static void F_191 ( struct V_190 * V_191 )
{
struct V_1 * V_2 = V_191 -> V_75 -> V_2 ;
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_202 * V_192 = V_191 -> V_192 ;
if ( V_191 -> V_204 & V_205 ) {
V_191 -> V_75 -> V_116 ( V_191 -> V_75 ,
V_191 -> V_169 . V_76 ,
V_192 -> V_79 . V_111 ,
true ) ;
V_191 -> V_204 &= ~ V_205 ;
}
if ( V_191 -> V_204 & V_219 ) {
struct V_68 * V_220 = V_123 -> V_171 . V_182 ;
V_220 -> V_79 . V_116 ( & V_220 -> V_79 ,
V_191 -> V_169 . V_76 ,
V_192 -> V_79 . V_111 ,
true ) ;
V_191 -> V_204 &= ~ V_219 ;
}
}
void F_192 ( struct V_202 * V_192 )
{
struct V_1 * V_2 = V_192 -> V_79 . V_2 ;
struct V_122 * V_123 = V_2 -> V_124 ;
bool V_194 ;
V_194 = F_152 ( V_123 ) ;
if ( ! V_192 -> V_206 )
F_193 ( & V_2 -> V_8 -> V_2 ,
V_192 -> V_95 -> V_207 , V_192 -> V_95 -> V_208 ,
V_42 ) ;
F_157 ( V_123 , V_194 ) ;
}
static void F_194 ( struct V_221 * V_169 ,
unsigned long V_222 ,
T_11 * V_76 ,
T_11 * V_223 )
{
if ( V_169 -> V_222 != V_222 )
* V_76 += 4096 ;
if ( ! F_144 ( & V_169 -> V_224 ) ) {
V_169 = F_195 ( V_169 -> V_224 . V_225 ,
struct V_221 ,
V_224 ) ;
if ( V_169 -> V_226 && V_169 -> V_222 != V_222 )
* V_223 -= 4096 ;
}
}
static int F_196 ( struct V_1 * V_2 ,
unsigned long V_76 ,
unsigned long V_177 ,
unsigned long V_223 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_74 * V_227 = & V_123 -> V_127 . V_79 ;
struct V_221 * V_66 ;
struct V_202 * V_192 ;
unsigned long V_228 , V_229 ;
int V_51 ;
F_43 ( V_177 > V_223 ) ;
F_136 ( & V_227 -> V_171 , V_76 , V_223 - V_76 - V_93 ) ;
V_123 -> V_127 . V_79 . V_76 = V_76 ;
V_123 -> V_127 . V_79 . V_119 = V_223 - V_76 ;
if ( F_3 ( V_2 ) ) {
V_51 = F_197 ( V_2 ) ;
if ( V_51 )
return V_51 ;
}
if ( ! F_54 ( V_2 ) )
V_123 -> V_127 . V_79 . V_171 . V_230 = F_194 ;
F_166 (obj, &dev_priv->mm.bound_list, global_list) {
struct V_190 * V_191 = F_167 ( V_192 , V_227 ) ;
F_198 ( L_26 ,
F_199 ( V_192 ) , V_192 -> V_79 . V_111 ) ;
F_25 ( F_200 ( V_192 ) ) ;
V_51 = F_201 ( & V_227 -> V_171 , & V_191 -> V_169 ) ;
if ( V_51 ) {
F_198 ( L_27 , V_51 ) ;
return V_51 ;
}
V_191 -> V_204 |= V_205 ;
}
F_202 (entry, &ggtt_vm->mm, hole_start, hole_end) {
F_198 ( L_28 ,
V_228 , V_229 ) ;
V_227 -> V_116 ( V_227 , V_228 ,
V_229 - V_228 , true ) ;
}
V_227 -> V_116 ( V_227 , V_223 - V_93 , V_93 , true ) ;
if ( F_139 ( V_2 ) && ! F_203 ( V_2 ) ) {
struct V_68 * V_69 ;
V_69 = F_30 ( sizeof( * V_69 ) , V_52 ) ;
if ( ! V_69 )
return - V_44 ;
V_51 = F_133 ( V_2 , V_69 , true ) ;
if ( V_51 ) {
F_28 ( V_69 ) ;
return V_51 ;
}
V_123 -> V_171 . V_182 = V_69 ;
}
return 0 ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
unsigned long V_231 , V_232 ;
V_231 = V_123 -> V_127 . V_79 . V_119 ;
V_232 = V_123 -> V_127 . V_177 ;
F_196 ( V_2 , 0 , V_232 , V_231 ) ;
}
void F_205 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_74 * V_75 = & V_123 -> V_127 . V_79 ;
if ( V_123 -> V_171 . V_182 ) {
struct V_68 * V_69 = V_123 -> V_171 . V_182 ;
V_69 -> V_79 . V_118 ( & V_69 -> V_79 ) ;
}
if ( F_123 ( & V_75 -> V_171 ) ) {
if ( F_3 ( V_2 ) )
F_206 () ;
F_146 ( & V_75 -> V_171 ) ;
F_145 ( & V_75 -> V_189 ) ;
}
V_75 -> V_118 ( V_75 ) ;
}
static int F_207 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_43 * V_43 ;
T_2 V_233 ;
V_43 = F_34 ( V_52 | V_234 | V_63 ) ;
if ( V_43 == NULL )
return - V_44 ;
F_208 ( V_43 , 1 ) ;
#ifdef F_4
V_233 = F_69 ( V_2 -> V_8 , V_43 , 0 , V_93 ,
V_42 ) ;
if ( F_70 ( V_2 -> V_8 , V_233 ) )
return - V_60 ;
#else
V_233 = F_209 ( V_43 ) ;
#endif
V_123 -> V_127 . V_79 . V_92 . V_43 = V_43 ;
V_123 -> V_127 . V_79 . V_92 . V_12 = V_233 ;
return 0 ;
}
static void F_210 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_43 * V_43 = V_123 -> V_127 . V_79 . V_92 . V_43 ;
F_211 ( V_43 , 1 ) ;
F_63 ( V_2 -> V_8 , V_123 -> V_127 . V_79 . V_92 . V_12 ,
V_93 , V_42 ) ;
F_27 ( V_43 ) ;
}
static inline unsigned int F_212 ( T_12 V_235 )
{
V_235 >>= V_236 ;
V_235 &= V_237 ;
return V_235 << 20 ;
}
static inline unsigned int F_213 ( T_12 V_238 )
{
V_238 >>= V_239 ;
V_238 &= V_240 ;
if ( V_238 )
V_238 = 1 << V_238 ;
#ifdef F_214
if ( V_238 > 4 )
V_238 = 4 ;
#endif
return V_238 << 20 ;
}
static inline unsigned int F_215 ( T_12 V_241 )
{
V_241 >>= V_236 ;
V_241 &= V_237 ;
if ( V_241 )
return 1 << ( 20 + V_241 ) ;
return 0 ;
}
static inline T_6 F_216 ( T_12 V_235 )
{
V_235 >>= V_242 ;
V_235 &= V_243 ;
return V_235 << 25 ;
}
static inline T_6 F_217 ( T_12 V_238 )
{
V_238 >>= V_244 ;
V_238 &= V_245 ;
return V_238 << 25 ;
}
static T_6 F_218 ( T_12 V_241 )
{
V_241 >>= V_242 ;
V_241 &= V_243 ;
if ( V_241 < 0x11 )
return V_241 << 25 ;
else if ( V_241 < 0x17 )
return ( V_241 - 0x11 + 2 ) << 22 ;
else
return ( V_241 - 0x17 + 9 ) << 22 ;
}
static T_6 F_219 ( T_12 V_246 )
{
V_246 >>= V_244 ;
V_246 &= V_245 ;
if ( V_246 < 0xf0 )
return V_246 << 25 ;
else
return ( V_246 - 0xf0 + 1 ) << 22 ;
}
static int F_220 ( struct V_1 * V_2 ,
T_6 V_231 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
T_13 V_247 ;
int V_51 ;
V_247 = F_221 ( V_2 -> V_8 , 0 ) +
( F_222 ( V_2 -> V_8 , 0 ) / 2 ) ;
V_123 -> V_127 . V_128 = F_223 ( V_247 , V_231 ) ;
if ( ! V_123 -> V_127 . V_128 ) {
F_155 ( L_29 ) ;
return - V_44 ;
}
V_51 = F_207 ( V_2 ) ;
if ( V_51 ) {
F_155 ( L_30 ) ;
F_224 ( V_123 -> V_127 . V_128 ) ;
}
return V_51 ;
}
static void F_171 ( struct V_122 * V_123 )
{
T_8 V_248 ;
V_248 = F_225 ( 0 , V_249 | V_250 ) |
F_225 ( 1 , V_251 | V_252 ) |
F_225 ( 2 , V_253 | V_252 ) |
F_225 ( 3 , V_254 ) |
F_225 ( 4 , V_249 | V_252 | F_226 ( 0 ) ) |
F_225 ( 5 , V_249 | V_252 | F_226 ( 1 ) ) |
F_225 ( 6 , V_249 | V_252 | F_226 ( 2 ) ) |
F_225 ( 7 , V_249 | V_252 | F_226 ( 3 ) ) ;
if ( ! F_139 ( V_123 -> V_2 ) )
V_248 = F_225 ( 0 , V_254 ) ;
F_89 ( V_255 , V_248 ) ;
F_89 ( V_255 + 4 , V_248 >> 32 ) ;
}
static void F_170 ( struct V_122 * V_123 )
{
T_8 V_248 ;
V_248 = F_225 ( 0 , V_256 ) |
F_225 ( 1 , 0 ) |
F_225 ( 2 , 0 ) |
F_225 ( 3 , 0 ) |
F_225 ( 4 , V_256 ) |
F_225 ( 5 , V_256 ) |
F_225 ( 6 , V_256 ) |
F_225 ( 7 , V_256 ) ;
F_89 ( V_255 , V_248 ) ;
F_89 ( V_255 + 4 , V_248 >> 32 ) ;
}
static int F_227 ( struct V_1 * V_2 ,
T_6 * V_257 ,
T_6 * V_258 ,
T_13 * V_259 ,
unsigned long * V_177 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
unsigned int V_231 ;
T_12 V_235 ;
int V_51 ;
* V_259 = F_221 ( V_2 -> V_8 , 2 ) ;
* V_177 = F_222 ( V_2 -> V_8 , 2 ) ;
if ( ! F_228 ( V_2 -> V_8 , F_229 ( 39 ) ) )
F_230 ( V_2 -> V_8 , F_229 ( 39 ) ) ;
F_231 ( V_2 -> V_8 , V_260 , & V_235 ) ;
if ( F_2 ( V_2 ) -> V_6 >= 9 ) {
* V_258 = F_219 ( V_235 ) ;
V_231 = F_213 ( V_235 ) ;
} else if ( F_7 ( V_2 ) ) {
* V_258 = F_218 ( V_235 ) ;
V_231 = F_215 ( V_235 ) ;
} else {
* V_258 = F_217 ( V_235 ) ;
V_231 = F_213 ( V_235 ) ;
}
* V_257 = ( V_231 / sizeof( T_1 ) ) << V_90 ;
if ( F_7 ( V_2 ) )
F_170 ( V_123 ) ;
else
F_171 ( V_123 ) ;
V_51 = F_220 ( V_2 , V_231 ) ;
V_123 -> V_127 . V_79 . V_116 = F_182 ;
V_123 -> V_127 . V_79 . V_117 = F_178 ;
return V_51 ;
}
static int F_232 ( struct V_1 * V_2 ,
T_6 * V_257 ,
T_6 * V_258 ,
T_13 * V_259 ,
unsigned long * V_177 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
unsigned int V_231 ;
T_12 V_235 ;
int V_51 ;
* V_259 = F_221 ( V_2 -> V_8 , 2 ) ;
* V_177 = F_222 ( V_2 -> V_8 , 2 ) ;
if ( ( * V_177 < ( 64 << 20 ) || ( * V_177 > ( 512 << 20 ) ) ) ) {
F_155 ( L_31 ,
V_123 -> V_127 . V_177 ) ;
return - V_261 ;
}
if ( ! F_228 ( V_2 -> V_8 , F_229 ( 40 ) ) )
F_230 ( V_2 -> V_8 , F_229 ( 40 ) ) ;
F_231 ( V_2 -> V_8 , V_260 , & V_235 ) ;
* V_258 = F_216 ( V_235 ) ;
V_231 = F_212 ( V_235 ) ;
* V_257 = ( V_231 / sizeof( T_4 ) ) << V_90 ;
V_51 = F_220 ( V_2 , V_231 ) ;
V_123 -> V_127 . V_79 . V_116 = F_184 ;
V_123 -> V_127 . V_79 . V_117 = F_181 ;
return V_51 ;
}
static void F_233 ( struct V_74 * V_75 )
{
struct V_262 * V_127 = F_52 ( V_75 , struct V_262 , V_79 ) ;
F_224 ( V_127 -> V_128 ) ;
F_210 ( V_75 -> V_2 ) ;
}
static int F_234 ( struct V_1 * V_2 ,
T_6 * V_257 ,
T_6 * V_258 ,
T_13 * V_259 ,
unsigned long * V_177 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
int V_51 ;
V_51 = F_235 ( V_123 -> V_263 , V_123 -> V_2 -> V_8 , NULL ) ;
if ( ! V_51 ) {
F_155 ( L_32 ) ;
return - V_264 ;
}
F_236 ( V_257 , V_258 , V_259 , V_177 ) ;
V_123 -> V_127 . V_195 = F_149 ( V_123 -> V_2 ) ;
V_123 -> V_127 . V_79 . V_116 = F_187 ;
if ( F_153 ( V_123 -> V_127 . V_195 ) )
F_5 ( L_33 ) ;
return 0 ;
}
static void F_237 ( struct V_74 * V_75 )
{
F_238 () ;
}
int F_239 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = V_2 -> V_124 ;
struct V_262 * V_127 = & V_123 -> V_127 ;
int V_51 ;
if ( F_2 ( V_2 ) -> V_6 <= 5 ) {
V_127 -> V_265 = F_234 ;
V_127 -> V_79 . V_118 = F_237 ;
} else if ( F_2 ( V_2 ) -> V_6 < 8 ) {
V_127 -> V_265 = F_232 ;
V_127 -> V_79 . V_118 = F_233 ;
if ( F_99 ( V_2 ) && V_123 -> V_266 )
V_127 -> V_79 . V_126 = F_18 ;
else if ( F_99 ( V_2 ) )
V_127 -> V_79 . V_126 = F_16 ;
else if ( F_6 ( V_2 ) )
V_127 -> V_79 . V_126 = F_15 ;
else if ( F_2 ( V_2 ) -> V_6 >= 7 )
V_127 -> V_79 . V_126 = F_14 ;
else
V_127 -> V_79 . V_126 = F_11 ;
} else {
V_123 -> V_127 . V_265 = F_227 ;
V_123 -> V_127 . V_79 . V_118 = F_233 ;
}
V_51 = V_127 -> V_265 ( V_2 , & V_127 -> V_79 . V_119 , & V_127 -> V_267 ,
& V_127 -> V_259 , & V_127 -> V_177 ) ;
if ( V_51 )
return V_51 ;
V_127 -> V_79 . V_2 = V_2 ;
F_5 ( L_34 ,
V_127 -> V_79 . V_119 >> 20 ) ;
F_8 ( L_35 , V_127 -> V_177 >> 20 ) ;
F_8 ( L_36 , V_127 -> V_267 >> 20 ) ;
#ifdef F_4
if ( V_7 )
F_5 ( L_37 ) ;
#endif
V_10 . V_3 = F_1 ( V_2 , V_10 . V_3 ) ;
F_8 ( L_38 , V_10 . V_3 ) ;
return 0 ;
}
static struct V_190 *
F_240 ( struct V_202 * V_192 ,
struct V_74 * V_75 ,
const struct V_268 * V_217 )
{
struct V_190 * V_191 ;
if ( F_25 ( F_172 ( V_75 ) != ! ! V_217 ) )
return F_31 ( - V_60 ) ;
V_191 = F_30 ( sizeof( * V_191 ) , V_52 ) ;
if ( V_191 == NULL )
return F_31 ( - V_44 ) ;
F_241 ( & V_191 -> V_269 ) ;
F_241 ( & V_191 -> V_270 ) ;
F_241 ( & V_191 -> V_271 ) ;
V_191 -> V_75 = V_75 ;
V_191 -> V_192 = V_192 ;
if ( F_2 ( V_75 -> V_2 ) -> V_6 >= 6 ) {
if ( F_172 ( V_75 ) ) {
V_191 -> V_217 = * V_217 ;
V_191 -> V_272 = F_191 ;
V_191 -> V_273 = F_190 ;
} else {
V_191 -> V_272 = F_148 ;
V_191 -> V_273 = F_147 ;
}
} else {
F_43 ( ! F_172 ( V_75 ) ) ;
V_191 -> V_217 = * V_217 ;
V_191 -> V_272 = F_189 ;
V_191 -> V_273 = F_185 ;
}
F_242 ( & V_191 -> V_269 , & V_192 -> V_274 ) ;
if ( ! F_172 ( V_75 ) )
F_243 ( F_244 ( V_75 ) ) ;
return V_191 ;
}
struct V_190 *
F_245 ( struct V_202 * V_192 ,
struct V_74 * V_75 )
{
struct V_190 * V_191 ;
V_191 = F_167 ( V_192 , V_75 ) ;
if ( ! V_191 )
V_191 = F_240 ( V_192 , V_75 ,
F_172 ( V_75 ) ? & V_275 : NULL ) ;
return V_191 ;
}
struct V_190 *
F_246 ( struct V_202 * V_192 ,
const struct V_268 * V_276 )
{
struct V_74 * V_277 = F_247 ( V_192 ) ;
struct V_190 * V_191 ;
if ( F_25 ( ! V_276 ) )
return F_31 ( - V_60 ) ;
V_191 = F_248 ( V_192 , V_276 ) ;
if ( F_37 ( V_191 ) )
return V_191 ;
if ( ! V_191 )
V_191 = F_240 ( V_192 , V_277 , V_276 ) ;
return V_191 ;
}
static void
F_249 ( T_2 * V_278 , unsigned int V_279 , unsigned int V_280 ,
struct V_94 * V_209 )
{
unsigned int V_281 , V_282 ;
unsigned int V_283 ;
struct V_284 * V_211 = V_209 -> V_207 ;
V_209 -> V_208 = 0 ;
for ( V_281 = 0 ; V_281 < V_279 ; V_281 ++ ) {
V_283 = V_279 * ( V_280 - 1 ) + V_281 ;
for ( V_282 = 0 ; V_282 < V_280 ; V_282 ++ ) {
V_209 -> V_208 ++ ;
F_250 ( V_211 , NULL , V_93 , 0 ) ;
F_179 ( V_211 ) = V_278 [ V_283 ] ;
F_251 ( V_211 ) = V_93 ;
V_211 = F_252 ( V_211 ) ;
V_283 -= V_279 ;
}
}
}
static struct V_94 *
F_253 ( struct V_268 * V_217 ,
struct V_202 * V_192 )
{
struct V_1 * V_2 = V_192 -> V_79 . V_2 ;
struct V_285 * V_286 = & V_217 -> V_287 ;
unsigned long V_111 , V_95 , V_288 ;
struct V_97 V_98 ;
unsigned long V_58 ;
T_2 * V_289 ;
struct V_94 * V_209 ;
unsigned int V_290 , V_291 ;
unsigned int V_292 , V_293 ;
int V_51 = - V_44 ;
V_95 = V_192 -> V_79 . V_111 / V_93 ;
V_291 = F_254 ( V_2 , V_286 -> V_294 ,
V_286 -> V_295 ) ;
V_290 = V_93 / V_291 ;
V_292 = F_73 ( V_286 -> V_296 , V_290 ) ;
V_293 = F_73 ( V_286 -> V_280 , V_291 ) ;
V_288 = V_292 * V_293 ;
V_111 = V_288 * V_93 ;
V_289 = F_255 ( V_95 , sizeof( T_2 ) ) ;
if ( ! V_289 )
return F_31 ( V_51 ) ;
V_209 = F_256 ( sizeof( * V_209 ) , V_52 ) ;
if ( ! V_209 )
goto V_297;
V_51 = F_257 ( V_209 , V_288 , V_52 ) ;
if ( V_51 )
goto V_298;
V_58 = 0 ;
F_58 (obj->pages->sgl, &sg_iter, obj->pages->nents, 0 ) {
V_289 [ V_58 ] = F_59 ( & V_98 ) ;
V_58 ++ ;
}
F_249 ( V_289 , V_292 , V_293 , V_209 ) ;
F_198 (
L_39 ,
V_111 , V_286 -> V_296 , V_286 -> V_280 ,
V_286 -> V_294 , V_292 , V_293 ,
V_288 ) ;
F_258 ( V_289 ) ;
return V_209 ;
V_298:
F_28 ( V_209 ) ;
V_297:
F_258 ( V_289 ) ;
F_198 (
L_40 ,
V_111 , V_51 , V_286 -> V_296 , V_286 -> V_280 ,
V_286 -> V_294 , V_292 , V_293 ,
V_288 ) ;
return F_31 ( V_51 ) ;
}
static inline int
F_259 ( struct V_190 * V_191 )
{
int V_51 = 0 ;
if ( V_191 -> V_217 . V_95 )
return 0 ;
if ( V_191 -> V_217 . type == V_299 )
V_191 -> V_217 . V_95 = V_191 -> V_192 -> V_95 ;
else if ( V_191 -> V_217 . type == V_300 )
V_191 -> V_217 . V_95 =
F_253 ( & V_191 -> V_217 , V_191 -> V_192 ) ;
else
F_260 ( 1 , L_41 ,
V_191 -> V_217 . type ) ;
if ( ! V_191 -> V_217 . V_95 ) {
F_155 ( L_42 ,
V_191 -> V_217 . type ) ;
V_51 = - V_60 ;
} else if ( F_37 ( V_191 -> V_217 . V_95 ) ) {
V_51 = F_38 ( V_191 -> V_217 . V_95 ) ;
V_191 -> V_217 . V_95 = NULL ;
F_155 ( L_43 ,
V_191 -> V_217 . type , V_51 ) ;
}
return V_51 ;
}
int F_169 ( struct V_190 * V_191 , enum V_13 V_96 ,
T_5 V_33 )
{
if ( F_172 ( V_191 -> V_75 ) ) {
int V_51 = F_259 ( V_191 ) ;
if ( V_51 )
return V_51 ;
}
V_191 -> V_273 ( V_191 , V_96 , V_33 ) ;
return 0 ;
}
