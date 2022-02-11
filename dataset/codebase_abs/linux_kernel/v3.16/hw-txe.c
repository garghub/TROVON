static inline T_1 F_1 ( void T_2 * V_1 ,
unsigned long V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 ,
unsigned long V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static inline T_1 F_5 ( struct V_4 * V_5 ,
unsigned long V_2 )
{
return F_1 ( V_5 -> V_6 [ V_7 ] , V_2 ) ;
}
static inline T_1 F_6 ( struct V_4 * V_5 ,
unsigned long V_2 )
{
F_7 ( ! V_5 -> V_8 , L_1 ) ;
return F_5 ( V_5 , V_2 ) ;
}
static inline void F_8 ( struct V_4 * V_5 ,
unsigned long V_2 , T_1 V_3 )
{
F_3 ( V_5 -> V_6 [ V_7 ] , V_2 , V_3 ) ;
}
static inline void F_9 ( struct V_4 * V_5 ,
unsigned long V_2 , T_1 V_3 )
{
F_7 ( ! V_5 -> V_8 , L_2 ) ;
F_8 ( V_5 , V_2 , V_3 ) ;
}
static inline T_1 F_10 ( struct V_4 * V_5 ,
unsigned long V_2 )
{
return F_1 ( V_5 -> V_6 [ V_9 ] , V_2 ) ;
}
static inline void F_11 ( struct V_4 * V_5 ,
unsigned long V_2 , T_1 V_3 )
{
F_3 ( V_5 -> V_6 [ V_9 ] , V_2 , V_3 ) ;
}
static bool F_12 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
bool V_13 = V_5 -> V_8 != V_12 ;
F_14 ( & V_11 -> V_14 -> V_11 , L_3 ,
V_5 -> V_8 , V_12 ) ;
if ( V_13 ) {
V_11 -> V_15 = V_16 ;
F_11 ( V_5 , V_17 , V_12 ) ;
}
return V_13 ;
}
static T_1 F_15 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_18 ;
V_18 = F_10 ( V_5 , V_17 ) ;
return V_18 & V_19 ;
}
static T_1 F_16 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_18 ;
V_18 = F_10 ( V_5 , V_20 ) ;
return V_18 & V_21 ;
}
static int F_17 ( struct V_10 * V_11 , T_1 V_22 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
int V_23 = 0 ;
do {
V_5 -> V_8 = F_16 ( V_11 ) ;
if ( V_5 -> V_8 == V_22 ) {
V_11 -> V_15 = V_24 ;
F_14 ( & V_11 -> V_14 -> V_11 ,
L_4 , V_23 ) ;
return V_23 ;
}
F_18 ( & V_11 -> V_25 ) ;
F_19 ( V_26 / 5 ) ;
F_20 ( & V_11 -> V_25 ) ;
V_23 += V_26 / 5 ;
} while ( V_23 < V_27 );
V_11 -> V_15 = V_24 ;
F_21 ( & V_11 -> V_14 -> V_11 , L_5 ) ;
return - V_28 ;
}
static int F_22 ( struct V_10 * V_11 , T_1 V_22 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
const unsigned long V_29 =
F_23 ( V_27 ) ;
long V_30 ;
int V_31 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
if ( V_5 -> V_8 == V_22 )
return 0 ;
F_18 ( & V_11 -> V_25 ) ;
V_30 = F_24 ( V_5 -> V_32 ,
V_11 -> V_15 == V_33 , V_29 ) ;
F_20 ( & V_11 -> V_25 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_31 = V_5 -> V_8 == V_22 ? 0 : - V_28 ;
if ( V_31 )
F_25 ( & V_11 -> V_14 -> V_11 , L_6 ,
V_30 , V_5 -> V_8 , V_11 -> V_15 ) ;
else
F_14 ( & V_11 -> V_14 -> V_11 , L_7 ,
F_26 ( V_29 - V_30 ) ,
V_5 -> V_8 , V_11 -> V_15 ) ;
V_11 -> V_15 = V_24 ;
return V_31 ;
}
int F_27 ( struct V_10 * V_11 , T_1 V_12 )
{
if ( F_12 ( V_11 , V_12 ) )
return F_22 ( V_11 , V_12 ) ;
return 0 ;
}
static bool F_28 ( struct V_10 * V_11 )
{
return true ;
}
static inline enum V_34 F_29 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return V_5 -> V_8 ? V_35 : V_36 ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_37 ;
V_37 = F_6 ( V_5 , V_38 ) ;
V_37 |= V_39 ;
F_9 ( V_5 , V_38 , V_37 ) ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_32 ( V_40 , & V_5 -> V_41 ) ;
F_9 ( V_5 , V_42 , 1 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
F_11 ( V_5 ,
V_43 ,
V_44 ) ;
}
static bool F_34 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_45 ;
V_45 = F_6 ( V_5 , V_46 ) ;
return ! ! ( V_47 & V_45 ) ;
}
static inline void F_35 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_8 ( V_5 , V_48 ,
V_49 ) ;
F_11 ( V_5 , V_50 , V_51 ) ;
F_11 ( V_5 , V_52 , V_53 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_54 , 0 ) ;
F_11 ( V_5 , V_55 , 0 ) ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_54 , V_53 ) ;
F_11 ( V_5 , V_55 , V_56 ) ;
}
static bool F_38 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
bool V_31 = ( V_5 -> V_41 & ( V_57 |
V_58 |
V_59 |
V_60 ) ) ;
if ( V_31 ) {
F_14 ( & V_11 -> V_14 -> V_11 ,
L_8 ,
! ! ( V_5 -> V_41 & V_59 ) ,
! ! ( V_5 -> V_41 & V_57 ) ,
! ! ( V_5 -> V_41 & V_58 ) ,
! ! ( V_5 -> V_41 & V_60 ) ) ;
}
return V_31 ;
}
static void F_39 ( struct V_10 * V_11 ,
unsigned long V_61 , T_1 V_3 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_9 ( V_5 , V_62 +
( V_61 * sizeof( T_1 ) ) , V_3 ) ;
}
static T_1 F_40 ( const struct V_10 * V_11 ,
unsigned long V_61 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 ,
V_63 + ( V_61 * sizeof( T_1 ) ) ) ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 ,
V_64 ,
V_65 ) ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_64 ,
V_66 ) ;
}
static T_1 F_43 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 , V_67 ) ;
}
static inline bool F_44 ( T_1 V_68 )
{
return ! ! ( V_68 & V_69 ) ;
}
static bool F_45 ( struct V_10 * V_11 )
{
T_1 V_68 = F_43 ( V_11 ) ;
return F_44 ( V_68 ) ;
}
static inline bool F_46 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_18 = F_10 ( V_5 , V_67 ) ;
return ! ! ( V_18 & V_70 ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
if ( F_45 ( V_11 ) )
return 0 ;
F_18 ( & V_11 -> V_25 ) ;
F_24 ( V_11 -> V_71 , V_11 -> V_72 ,
F_23 ( V_73 ) ) ;
F_20 ( & V_11 -> V_25 ) ;
if ( ! V_11 -> V_72 ) {
F_21 ( & V_11 -> V_14 -> V_11 , L_9 ) ;
return - V_28 ;
}
V_11 -> V_72 = false ;
return 0 ;
}
static void F_48 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
V_11 -> V_74 = V_75 / 4 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_68 = F_43 ( V_11 ) ;
F_14 ( & V_11 -> V_14 -> V_11 , L_10 ,
V_5 -> V_8 , V_5 -> V_68 ) ;
}
static int F_49 ( struct V_10 * V_11 ,
struct V_76 * V_77 , unsigned char * V_78 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
unsigned long V_79 ;
unsigned long V_80 ;
int V_81 = V_11 -> V_74 ;
T_1 * V_82 = ( T_1 * ) V_78 ;
T_1 V_83 ;
int V_84 ;
if ( F_50 ( ! V_77 || ! V_78 ) )
return - V_85 ;
V_80 = V_77 -> V_80 ;
F_14 ( & V_11 -> V_14 -> V_11 , V_86 , F_51 ( V_77 ) ) ;
V_83 = F_52 ( V_80 ) ;
if ( V_83 > V_81 )
return - V_87 ;
if ( F_7 ( ! V_5 -> V_8 , L_11 ) )
return - V_88 ;
F_30 ( V_11 ) ;
if ( ! F_34 ( V_11 ) ) {
struct V_89 V_90 ;
V_89 ( V_11 , & V_90 ) ;
F_21 ( & V_11 -> V_14 -> V_11 , L_12 V_91 L_13 ,
F_53 ( V_90 ) ) ;
return - V_88 ;
}
F_39 ( V_11 , 0 , * ( ( T_1 * ) V_77 ) ) ;
for ( V_84 = 0 ; V_84 < V_80 / 4 ; V_84 ++ )
F_39 ( V_11 , V_84 + 1 , V_82 [ V_84 ] ) ;
V_79 = V_80 & 0x3 ;
if ( V_79 > 0 ) {
T_1 V_18 = 0 ;
memcpy ( & V_18 , & V_78 [ V_80 - V_79 ] , V_79 ) ;
F_39 ( V_11 , V_84 + 1 , V_18 ) ;
}
V_5 -> V_81 = 0 ;
F_31 ( V_5 ) ;
return 0 ;
}
static T_3 F_54 ( const struct V_10 * V_11 )
{
return V_75 - sizeof( struct V_76 ) ;
}
static int F_55 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return V_5 -> V_81 ;
}
static int F_56 ( struct V_10 * V_11 )
{
return V_75 / 4 ;
}
static T_1 F_57 ( const struct V_10 * V_11 )
{
return F_40 ( V_11 , 0 ) ;
}
static int F_58 ( struct V_10 * V_11 ,
unsigned char * V_78 , unsigned long V_92 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_84 ;
T_1 * V_82 = ( T_1 * ) V_78 ;
T_1 V_79 = V_92 & 0x3 ;
if ( F_50 ( ! V_78 || ! V_92 ) )
return - V_85 ;
F_14 ( & V_11 -> V_14 -> V_11 ,
L_14 ,
V_92 , F_40 ( V_11 , 0 ) ) ;
for ( V_84 = 0 ; V_84 < V_92 / 4 ; V_84 ++ ) {
T_1 V_18 = F_40 ( V_11 , V_84 + 1 ) ;
F_14 ( & V_11 -> V_14 -> V_11 , L_15 , V_84 , V_18 ) ;
* V_82 ++ = V_18 ;
}
if ( V_79 ) {
T_1 V_18 = F_40 ( V_11 , V_84 + 1 ) ;
memcpy ( V_82 , & V_18 , V_79 ) ;
}
F_33 ( V_5 ) ;
return 0 ;
}
static int F_59 ( struct V_10 * V_11 , bool V_93 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_94 ;
( void ) F_5 ( V_5 , V_42 ) ;
V_94 = F_15 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
F_36 ( V_11 ) ;
if ( V_94 != V_5 -> V_8 )
if ( F_17 ( V_11 , V_94 ) < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 ,
L_16 ) ;
return - V_95 ;
}
if ( V_94 ) {
F_12 ( V_11 , 0 ) ;
if ( F_17 ( V_11 , 0 ) < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 ,
L_17 ) ;
return - V_95 ;
}
}
F_42 ( V_11 ) ;
return 0 ;
}
static int F_60 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
int V_31 ;
T_1 V_96 ;
F_37 ( V_11 ) ;
V_31 = F_47 ( V_11 ) ;
if ( V_31 < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 , L_18 ) ;
return V_31 ;
}
V_96 = F_10 ( V_5 , V_50 ) ;
if ( V_96 & V_97 )
F_11 ( V_5 , V_50 , V_97 ) ;
F_32 ( V_98 , & V_5 -> V_41 ) ;
V_31 = F_27 ( V_11 , 1 ) ;
if ( V_31 < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 , L_17 ) ;
return V_31 ;
}
F_30 ( V_11 ) ;
F_33 ( V_5 ) ;
F_41 ( V_11 ) ;
return 0 ;
}
static bool F_61 ( struct V_10 * V_11 , bool V_99 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_96 ;
T_1 V_100 ;
T_1 V_101 ;
T_1 V_8 ;
bool V_102 ;
V_100 = F_10 ( V_5 , V_52 ) ;
V_102 = ( V_100 & V_53 ) ;
if ( ! V_102 )
goto V_103;
V_96 = F_10 ( V_5 , V_50 ) ;
V_8 = F_16 ( V_11 ) ;
if ( V_100 & V_104 && V_8 )
V_101 = F_5 ( V_5 ,
V_48 ) ;
else
V_101 = 0 ;
V_102 = V_102 ||
( V_96 & V_51 ) ||
( V_101 & V_49 ) ;
if ( V_102 && V_99 ) {
V_5 -> V_41 |= V_96 & V_51 ;
if ( V_101 & V_105 )
V_5 -> V_41 |= V_59 ;
F_36 ( V_11 ) ;
F_8 ( V_5 ,
V_48 , V_101 ) ;
F_11 ( V_5 , V_50 , V_96 ) ;
F_11 ( V_5 , V_52 , V_100 ) ;
}
V_103:
return V_102 ;
}
T_4 F_62 ( int V_106 , void * V_107 )
{
struct V_10 * V_11 = V_107 ;
if ( F_61 ( V_11 , true ) )
return V_108 ;
return V_109 ;
}
T_4 F_63 ( int V_106 , void * V_107 )
{
struct V_10 * V_11 = (struct V_10 * ) V_107 ;
struct V_4 * V_5 = F_13 ( V_11 ) ;
struct V_110 V_111 ;
T_5 V_81 ;
int V_112 = 0 ;
F_14 ( & V_11 -> V_14 -> V_11 , L_19 ,
F_10 ( V_5 , V_52 ) ,
F_10 ( V_5 , V_50 ) ,
F_5 ( V_5 , V_48 ) ) ;
F_20 ( & V_11 -> V_25 ) ;
F_64 ( & V_111 ) ;
if ( F_65 ( V_11 -> V_14 ) )
F_61 ( V_11 , true ) ;
F_38 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_68 = F_43 ( V_11 ) ;
if ( F_66 ( V_113 , & V_5 -> V_41 ) ) {
F_14 ( & V_11 -> V_14 -> V_11 , L_20 ) ;
if ( F_44 ( V_5 -> V_68 ) ) {
F_14 ( & V_11 -> V_14 -> V_11 , L_21 ) ;
V_11 -> V_72 = true ;
} else {
V_11 -> V_72 = false ;
if ( V_11 -> V_114 != V_115 ) {
F_25 ( & V_11 -> V_14 -> V_11 , L_22 ) ;
F_67 ( & V_11 -> V_116 ) ;
goto V_117;
}
}
F_68 ( & V_11 -> V_71 ) ;
}
if ( F_66 ( V_118 , & V_5 -> V_41 ) ) {
F_14 ( & V_11 -> V_14 -> V_11 ,
L_23 , V_5 -> V_8 ) ;
V_11 -> V_15 = V_33 ;
if ( F_69 ( & V_5 -> V_32 ) )
F_68 ( & V_5 -> V_32 ) ;
}
V_81 = F_70 ( V_11 ) ;
if ( F_66 ( V_98 , & V_5 -> V_41 ) ) {
V_112 = F_71 ( V_11 , & V_111 , & V_81 ) ;
if ( V_112 && V_11 -> V_114 != V_115 ) {
F_21 ( & V_11 -> V_14 -> V_11 ,
L_24 , V_112 ) ;
F_67 ( & V_11 -> V_116 ) ;
goto V_117;
}
}
if ( F_66 ( V_40 , & V_5 -> V_41 ) ) {
V_11 -> V_119 = true ;
V_5 -> V_81 = V_11 -> V_74 ;
}
if ( V_5 -> V_8 && V_11 -> V_119 ) {
V_11 -> V_119 = F_72 ( V_11 ) ;
V_112 = F_73 ( V_11 , & V_111 ) ;
if ( V_112 && V_112 != - V_87 )
F_21 ( & V_11 -> V_14 -> V_11 , L_25 ,
V_112 ) ;
V_11 -> V_119 = F_72 ( V_11 ) ;
}
F_74 ( V_11 , & V_111 ) ;
V_117:
F_14 ( & V_11 -> V_14 -> V_11 , L_26 , V_112 ) ;
F_18 ( & V_11 -> V_25 ) ;
F_75 ( V_11 ) ;
return V_120 ;
}
static int F_76 ( struct V_10 * V_11 ,
struct V_89 * V_90 )
{
const T_1 V_121 [] = { V_122 , V_123 } ;
int V_84 ;
if ( ! V_90 )
return - V_85 ;
V_90 -> V_124 = 2 ;
for ( V_84 = 0 ; V_84 < V_90 -> V_124 && V_84 < V_125 ; V_84 ++ ) {
int V_31 ;
V_31 = F_77 ( V_11 -> V_14 ,
V_121 [ V_84 ] , & V_90 -> V_45 [ V_84 ] ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
struct V_10 * F_78 ( struct V_126 * V_14 ,
const struct V_127 * V_128 )
{
struct V_10 * V_11 ;
struct V_4 * V_5 ;
V_11 = F_79 ( sizeof( struct V_10 ) +
sizeof( struct V_4 ) , V_129 ) ;
if ( ! V_11 )
return NULL ;
F_80 ( V_11 , V_128 ) ;
V_5 = F_13 ( V_11 ) ;
F_81 ( & V_5 -> V_32 ) ;
V_11 -> V_130 = & V_131 ;
V_11 -> V_14 = V_14 ;
return V_11 ;
}
int F_82 ( struct V_10 * V_11 , T_6 V_132 , T_1 V_133 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_134 = F_83 ( V_132 ) ;
T_1 V_135 = F_84 ( V_132 ) ;
T_1 V_136 ;
if ( V_135 & ~ 0xF )
return - V_85 ;
if ( V_134 & 0xF )
return - V_85 ;
if ( V_133 & 0x4 )
return - V_85 ;
if ( V_133 > V_137 )
return - V_85 ;
V_136 = V_138 ;
V_136 |= V_135 << V_139 ;
F_11 ( V_5 , V_140 , V_133 ) ;
F_11 ( V_5 , V_141 , V_134 ) ;
F_11 ( V_5 , V_142 , V_136 ) ;
F_14 ( & V_11 -> V_14 -> V_11 , L_27 ,
V_133 , V_134 , V_136 ) ;
return 0 ;
}
