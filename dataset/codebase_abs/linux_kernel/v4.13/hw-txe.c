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
F_14 ( V_11 -> V_11 , L_3 ,
V_5 -> V_8 , V_12 ) ;
if ( V_13 ) {
V_11 -> V_14 = V_15 ;
F_11 ( V_5 , V_16 , V_12 ) ;
}
return V_13 ;
}
static T_1 F_15 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_17 ;
V_17 = F_10 ( V_5 , V_16 ) ;
return V_17 & V_18 ;
}
static T_1 F_16 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_17 ;
V_17 = F_10 ( V_5 , V_19 ) ;
return V_17 & V_20 ;
}
static int F_17 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_3 V_22 , V_23 ;
V_23 = F_18 () ;
V_22 = F_19 ( V_23 , F_20 ( V_24 ) ) ;
do {
V_5 -> V_8 = F_16 ( V_11 ) ;
if ( V_5 -> V_8 == V_21 ) {
V_11 -> V_14 = V_25 ;
F_14 ( V_11 -> V_11 , L_4 ,
F_21 ( F_22 ( F_18 () , V_23 ) ) ) ;
return 0 ;
}
F_23 ( 20 , 50 ) ;
} while ( F_24 ( F_18 () , V_22 ) );
V_11 -> V_14 = V_25 ;
F_25 ( V_11 -> V_11 , L_5 ) ;
return - V_26 ;
}
static int F_26 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
const unsigned long V_27 =
F_27 ( V_24 ) ;
long V_28 ;
int V_29 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
if ( V_5 -> V_8 == V_21 )
return 0 ;
F_28 ( & V_11 -> V_30 ) ;
V_28 = F_29 ( V_5 -> V_31 ,
V_11 -> V_14 == V_32 , V_27 ) ;
F_30 ( & V_11 -> V_30 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_29 = V_5 -> V_8 == V_21 ? 0 : - V_26 ;
if ( V_29 )
F_31 ( V_11 -> V_11 , L_6 ,
V_28 , V_5 -> V_8 , V_11 -> V_14 ) ;
else
F_14 ( V_11 -> V_11 , L_7 ,
F_32 ( V_27 - V_28 ) ,
V_5 -> V_8 , V_11 -> V_14 ) ;
V_11 -> V_14 = V_25 ;
return V_29 ;
}
int F_33 ( struct V_10 * V_11 , T_1 V_12 )
{
if ( F_12 ( V_11 , V_12 ) )
return F_26 ( V_11 , V_12 ) ;
return 0 ;
}
static bool F_34 ( struct V_10 * V_11 )
{
return V_11 -> V_14 == V_15 ;
}
static bool F_35 ( struct V_10 * V_11 )
{
return true ;
}
static inline enum V_33 F_36 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return V_5 -> V_8 ? V_34 : V_35 ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_36 ;
V_36 = F_6 ( V_5 , V_37 ) ;
V_36 |= V_38 ;
F_9 ( V_5 , V_37 , V_36 ) ;
}
static void F_38 ( struct V_4 * V_5 )
{
F_39 ( V_39 , & V_5 -> V_40 ) ;
F_9 ( V_5 , V_41 , 1 ) ;
}
static void F_40 ( struct V_4 * V_5 )
{
F_11 ( V_5 ,
V_42 ,
V_43 ) ;
}
static bool F_41 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_44 ;
V_44 = F_6 ( V_5 , V_45 ) ;
return ! ! ( V_46 & V_44 ) ;
}
static inline void F_42 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_8 ( V_5 , V_47 ,
V_48 ) ;
F_11 ( V_5 , V_49 , V_50 ) ;
F_11 ( V_5 , V_51 , V_52 ) ;
}
static void F_43 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_53 , 0 ) ;
F_11 ( V_5 , V_54 , 0 ) ;
}
static void F_44 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_53 , V_52 ) ;
F_11 ( V_5 , V_54 , V_55 ) ;
}
static void F_45 ( struct V_10 * V_11 )
{
struct V_56 * V_57 = F_46 ( V_11 -> V_11 ) ;
F_47 ( V_57 -> V_58 ) ;
}
static bool F_48 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
bool V_29 = ( V_5 -> V_40 & ( V_59 |
V_60 |
V_61 |
V_62 ) ) ;
if ( V_29 ) {
F_14 ( V_11 -> V_11 ,
L_8 ,
! ! ( V_5 -> V_40 & V_61 ) ,
! ! ( V_5 -> V_40 & V_59 ) ,
! ! ( V_5 -> V_40 & V_60 ) ,
! ! ( V_5 -> V_40 & V_62 ) ) ;
}
return V_29 ;
}
static void F_49 ( struct V_10 * V_11 ,
unsigned long V_63 , T_1 V_3 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_9 ( V_5 , V_64 +
( V_63 * sizeof( T_1 ) ) , V_3 ) ;
}
static T_1 F_50 ( const struct V_10 * V_11 ,
unsigned long V_63 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 ,
V_65 + ( V_63 * sizeof( T_1 ) ) ) ;
}
static void F_51 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 ,
V_66 ,
V_67 ) ;
}
static void F_52 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_66 ,
V_68 ) ;
}
static T_1 F_53 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 , V_69 ) ;
}
static inline bool F_54 ( T_1 V_70 )
{
return ! ! ( V_70 & V_71 ) ;
}
static bool F_55 ( struct V_10 * V_11 )
{
T_1 V_70 = F_53 ( V_11 ) ;
return F_54 ( V_70 ) ;
}
static inline bool F_56 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_17 = F_10 ( V_5 , V_69 ) ;
return ! ! ( V_17 & V_72 ) ;
}
static int F_57 ( struct V_10 * V_11 )
{
if ( F_55 ( V_11 ) )
return 0 ;
F_28 ( & V_11 -> V_30 ) ;
F_29 ( V_11 -> V_73 , V_11 -> V_74 ,
F_27 ( V_75 ) ) ;
F_30 ( & V_11 -> V_30 ) ;
if ( ! V_11 -> V_74 ) {
F_25 ( V_11 -> V_11 , L_9 ) ;
return - V_26 ;
}
V_11 -> V_74 = false ;
return 0 ;
}
static int F_58 ( struct V_10 * V_11 ,
struct V_76 * V_77 )
{
const struct V_76 * V_78 = & V_79 ;
struct V_56 * V_57 = F_46 ( V_11 -> V_11 ) ;
int V_29 ;
int V_80 ;
if ( ! V_77 )
return - V_81 ;
V_77 -> V_82 = V_78 -> V_82 ;
for ( V_80 = 0 ; V_80 < V_78 -> V_82 && V_80 < V_83 ; V_80 ++ ) {
V_29 = F_59 ( V_57 , V_78 -> V_44 [ V_80 ] ,
& V_77 -> V_44 [ V_80 ] ) ;
F_60 ( V_11 -> V_11 , L_10 ,
V_78 -> V_44 [ V_80 ] ,
V_77 -> V_44 [ V_80 ] ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
static void F_61 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
V_11 -> V_84 = V_85 / 4 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_70 = F_53 ( V_11 ) ;
F_14 ( V_11 -> V_11 , L_11 ,
V_5 -> V_8 , V_5 -> V_70 ) ;
}
static int F_62 ( struct V_10 * V_11 ,
struct V_86 * V_87 ,
const unsigned char * V_88 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
unsigned long V_89 ;
unsigned long V_90 ;
int V_91 = V_11 -> V_84 ;
T_1 * V_92 = ( T_1 * ) V_88 ;
T_1 V_93 ;
int V_80 ;
if ( F_63 ( ! V_87 || ! V_88 ) )
return - V_81 ;
V_90 = V_87 -> V_90 ;
F_14 ( V_11 -> V_11 , V_94 , F_64 ( V_87 ) ) ;
V_93 = F_65 ( V_90 ) ;
if ( V_93 > V_91 )
return - V_95 ;
if ( F_7 ( ! V_5 -> V_8 , L_12 ) )
return - V_96 ;
F_37 ( V_11 ) ;
if ( ! F_41 ( V_11 ) ) {
char V_97 [ V_98 ] ;
F_66 ( V_11 , V_97 , V_98 ) ;
F_25 ( V_11 -> V_11 , L_13 , V_97 ) ;
return - V_96 ;
}
F_49 ( V_11 , 0 , * ( ( T_1 * ) V_87 ) ) ;
for ( V_80 = 0 ; V_80 < V_90 / 4 ; V_80 ++ )
F_49 ( V_11 , V_80 + 1 , V_92 [ V_80 ] ) ;
V_89 = V_90 & 0x3 ;
if ( V_89 > 0 ) {
T_1 V_17 = 0 ;
memcpy ( & V_17 , & V_88 [ V_90 - V_89 ] , V_89 ) ;
F_49 ( V_11 , V_80 + 1 , V_17 ) ;
}
V_5 -> V_91 = 0 ;
F_38 ( V_5 ) ;
return 0 ;
}
static T_4 F_67 ( const struct V_10 * V_11 )
{
return V_85 - sizeof( struct V_86 ) ;
}
static int F_68 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return V_5 -> V_91 ;
}
static int F_69 ( struct V_10 * V_11 )
{
return V_85 / 4 ;
}
static T_1 F_70 ( const struct V_10 * V_11 )
{
return F_50 ( V_11 , 0 ) ;
}
static int F_71 ( struct V_10 * V_11 ,
unsigned char * V_88 , unsigned long V_99 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 * V_92 , V_17 ;
T_1 V_89 ;
T_1 V_80 ;
if ( F_63 ( ! V_88 || ! V_99 ) )
return - V_81 ;
V_92 = ( T_1 * ) V_88 ;
V_89 = V_99 & 0x3 ;
F_14 ( V_11 -> V_11 , L_14 ,
V_99 , F_50 ( V_11 , 0 ) ) ;
for ( V_80 = 0 ; V_80 < V_99 / 4 ; V_80 ++ ) {
V_17 = F_50 ( V_11 , V_80 + 1 ) ;
F_14 ( V_11 -> V_11 , L_15 , V_80 , V_17 ) ;
* V_92 ++ = V_17 ;
}
if ( V_89 ) {
V_17 = F_50 ( V_11 , V_80 + 1 ) ;
memcpy ( V_92 , & V_17 , V_89 ) ;
}
F_40 ( V_5 ) ;
return 0 ;
}
static int F_72 ( struct V_10 * V_11 , bool V_100 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_101 ;
( void ) F_5 ( V_5 , V_41 ) ;
V_101 = F_15 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
F_43 ( V_11 ) ;
if ( V_101 != V_5 -> V_8 )
if ( F_17 ( V_11 , V_101 ) < 0 ) {
F_25 ( V_11 -> V_11 , L_16 ) ;
return - V_102 ;
}
if ( V_101 ) {
F_12 ( V_11 , 0 ) ;
if ( F_17 ( V_11 , 0 ) < 0 ) {
F_25 ( V_11 -> V_11 , L_17 ) ;
return - V_102 ;
}
}
F_52 ( V_11 ) ;
return 0 ;
}
static int F_73 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
int V_29 ;
T_1 V_103 ;
F_44 ( V_11 ) ;
V_29 = F_57 ( V_11 ) ;
if ( V_29 < 0 ) {
F_25 ( V_11 -> V_11 , L_18 ) ;
return V_29 ;
}
V_103 = F_10 ( V_5 , V_49 ) ;
if ( V_103 & V_104 )
F_11 ( V_5 , V_49 , V_104 ) ;
F_39 ( V_105 , & V_5 -> V_40 ) ;
V_29 = F_33 ( V_11 , 1 ) ;
if ( V_29 < 0 ) {
F_25 ( V_11 -> V_11 , L_17 ) ;
return V_29 ;
}
F_74 ( V_11 -> V_11 ) ;
F_37 ( V_11 ) ;
F_40 ( V_5 ) ;
F_51 ( V_11 ) ;
return 0 ;
}
static bool F_75 ( struct V_10 * V_11 , bool V_106 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_103 ;
T_1 V_107 ;
T_1 V_108 ;
T_1 V_8 ;
bool V_109 ;
V_107 = F_10 ( V_5 , V_51 ) ;
V_109 = ( V_107 & V_52 ) ;
if ( ! V_109 )
goto V_110;
V_103 = F_10 ( V_5 , V_49 ) ;
V_8 = F_16 ( V_11 ) ;
if ( V_107 & V_111 && V_8 ) {
V_108 = F_5 ( V_5 ,
V_47 ) ;
} else {
V_108 = 0 ;
V_107 &= ~ V_111 ;
}
V_109 = V_109 ||
( V_103 & V_50 ) ||
( V_108 & V_48 ) ;
if ( V_109 && V_106 ) {
V_5 -> V_40 |= V_103 & V_50 ;
if ( V_108 & V_112 )
V_5 -> V_40 |= V_61 ;
F_43 ( V_11 ) ;
F_8 ( V_5 ,
V_47 , V_108 ) ;
F_11 ( V_5 , V_49 , V_103 ) ;
F_11 ( V_5 , V_51 , V_107 ) ;
}
V_110:
return V_109 ;
}
T_5 F_76 ( int V_58 , void * V_113 )
{
struct V_10 * V_11 = V_113 ;
if ( F_75 ( V_11 , true ) )
return V_114 ;
return V_115 ;
}
T_5 F_77 ( int V_58 , void * V_113 )
{
struct V_10 * V_11 = (struct V_10 * ) V_113 ;
struct V_4 * V_5 = F_13 ( V_11 ) ;
struct V_116 V_117 ;
T_6 V_91 ;
int V_118 = 0 ;
F_14 ( V_11 -> V_11 , L_19 ,
F_10 ( V_5 , V_51 ) ,
F_10 ( V_5 , V_49 ) ,
F_5 ( V_5 , V_47 ) ) ;
F_30 ( & V_11 -> V_30 ) ;
F_78 ( & V_117 ) ;
if ( F_79 ( F_46 ( V_11 -> V_11 ) ) )
F_75 ( V_11 , true ) ;
F_48 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_70 = F_53 ( V_11 ) ;
if ( F_80 ( V_119 , & V_5 -> V_40 ) ) {
F_14 ( V_11 -> V_11 , L_20 ) ;
if ( F_54 ( V_5 -> V_70 ) ) {
F_14 ( V_11 -> V_11 , L_21 ) ;
V_11 -> V_74 = true ;
} else {
V_11 -> V_74 = false ;
if ( V_11 -> V_120 != V_121 ) {
F_31 ( V_11 -> V_11 , L_22 ) ;
F_81 ( & V_11 -> V_122 ) ;
goto V_123;
}
}
F_82 ( & V_11 -> V_73 ) ;
}
if ( F_80 ( V_124 , & V_5 -> V_40 ) ) {
F_14 ( V_11 -> V_11 ,
L_23 , V_5 -> V_8 ) ;
V_11 -> V_14 = V_32 ;
if ( F_83 ( & V_5 -> V_31 ) )
F_82 ( & V_5 -> V_31 ) ;
}
V_91 = F_84 ( V_11 ) ;
if ( F_80 ( V_105 , & V_5 -> V_40 ) ) {
V_118 = F_85 ( V_11 , & V_117 , & V_91 ) ;
if ( V_118 && V_11 -> V_120 != V_121 ) {
F_25 ( V_11 -> V_11 ,
L_24 , V_118 ) ;
F_81 ( & V_11 -> V_122 ) ;
goto V_123;
}
}
if ( F_80 ( V_39 , & V_5 -> V_40 ) ) {
V_11 -> V_125 = true ;
V_5 -> V_91 = V_11 -> V_84 ;
}
if ( V_5 -> V_8 && V_11 -> V_125 ) {
V_11 -> V_125 = F_86 ( V_11 ) ;
V_118 = F_87 ( V_11 , & V_117 ) ;
if ( V_118 && V_118 != - V_95 )
F_25 ( V_11 -> V_11 , L_25 ,
V_118 ) ;
V_11 -> V_125 = F_86 ( V_11 ) ;
}
F_88 ( V_11 , & V_117 ) ;
V_123:
F_14 ( V_11 -> V_11 , L_26 , V_118 ) ;
F_28 ( & V_11 -> V_30 ) ;
F_89 ( V_11 ) ;
return V_126 ;
}
struct V_10 * F_90 ( struct V_56 * V_57 )
{
struct V_10 * V_11 ;
struct V_4 * V_5 ;
V_11 = F_91 ( & V_57 -> V_11 , sizeof( struct V_10 ) +
sizeof( struct V_4 ) , V_127 ) ;
if ( ! V_11 )
return NULL ;
F_92 ( V_11 , & V_57 -> V_11 , & V_128 ) ;
V_5 = F_13 ( V_11 ) ;
F_93 ( & V_5 -> V_31 ) ;
return V_11 ;
}
int F_94 ( struct V_10 * V_11 , T_7 V_129 , T_1 V_130 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_131 = F_95 ( V_129 ) ;
T_1 V_132 = F_96 ( V_129 ) ;
T_1 V_133 ;
if ( V_132 & ~ 0xF )
return - V_81 ;
if ( V_131 & 0xF )
return - V_81 ;
if ( V_130 & 0x4 )
return - V_81 ;
if ( V_130 > V_134 )
return - V_81 ;
V_133 = V_135 ;
V_133 |= V_132 << V_136 ;
F_11 ( V_5 , V_137 , V_130 ) ;
F_11 ( V_5 , V_138 , V_131 ) ;
F_11 ( V_5 , V_139 , V_133 ) ;
F_14 ( V_11 -> V_11 , L_27 ,
V_130 , V_131 , V_133 ) ;
return 0 ;
}
