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
int V_22 = 0 ;
do {
V_5 -> V_8 = F_16 ( V_11 ) ;
if ( V_5 -> V_8 == V_21 ) {
V_11 -> V_14 = V_23 ;
F_14 ( V_11 -> V_11 ,
L_4 , V_22 ) ;
return V_22 ;
}
F_18 ( & V_11 -> V_24 ) ;
F_19 ( V_25 / 5 ) ;
F_20 ( & V_11 -> V_24 ) ;
V_22 += V_25 / 5 ;
} while ( V_22 < V_26 );
V_11 -> V_14 = V_23 ;
F_21 ( V_11 -> V_11 , L_5 ) ;
return - V_27 ;
}
static int F_22 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
const unsigned long V_28 =
F_23 ( V_26 ) ;
long V_29 ;
int V_30 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
if ( V_5 -> V_8 == V_21 )
return 0 ;
F_18 ( & V_11 -> V_24 ) ;
V_29 = F_24 ( V_5 -> V_31 ,
V_11 -> V_14 == V_32 , V_28 ) ;
F_20 ( & V_11 -> V_24 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_30 = V_5 -> V_8 == V_21 ? 0 : - V_27 ;
if ( V_30 )
F_25 ( V_11 -> V_11 , L_6 ,
V_29 , V_5 -> V_8 , V_11 -> V_14 ) ;
else
F_14 ( V_11 -> V_11 , L_7 ,
F_26 ( V_28 - V_29 ) ,
V_5 -> V_8 , V_11 -> V_14 ) ;
V_11 -> V_14 = V_23 ;
return V_30 ;
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
static inline enum V_33 F_29 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return V_5 -> V_8 ? V_34 : V_35 ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_36 ;
V_36 = F_6 ( V_5 , V_37 ) ;
V_36 |= V_38 ;
F_9 ( V_5 , V_37 , V_36 ) ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_32 ( V_39 , & V_5 -> V_40 ) ;
F_9 ( V_5 , V_41 , 1 ) ;
}
static void F_33 ( struct V_4 * V_5 )
{
F_11 ( V_5 ,
V_42 ,
V_43 ) ;
}
static bool F_34 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_44 ;
V_44 = F_6 ( V_5 , V_45 ) ;
return ! ! ( V_46 & V_44 ) ;
}
static inline void F_35 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_8 ( V_5 , V_47 ,
V_48 ) ;
F_11 ( V_5 , V_49 , V_50 ) ;
F_11 ( V_5 , V_51 , V_52 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_53 , 0 ) ;
F_11 ( V_5 , V_54 , 0 ) ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_53 , V_52 ) ;
F_11 ( V_5 , V_54 , V_55 ) ;
}
static bool F_38 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
bool V_30 = ( V_5 -> V_40 & ( V_56 |
V_57 |
V_58 |
V_59 ) ) ;
if ( V_30 ) {
F_14 ( V_11 -> V_11 ,
L_8 ,
! ! ( V_5 -> V_40 & V_58 ) ,
! ! ( V_5 -> V_40 & V_56 ) ,
! ! ( V_5 -> V_40 & V_57 ) ,
! ! ( V_5 -> V_40 & V_59 ) ) ;
}
return V_30 ;
}
static void F_39 ( struct V_10 * V_11 ,
unsigned long V_60 , T_1 V_3 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_9 ( V_5 , V_61 +
( V_60 * sizeof( T_1 ) ) , V_3 ) ;
}
static T_1 F_40 ( const struct V_10 * V_11 ,
unsigned long V_60 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 ,
V_62 + ( V_60 * sizeof( T_1 ) ) ) ;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 ,
V_63 ,
V_64 ) ;
}
static void F_42 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_63 ,
V_65 ) ;
}
static T_1 F_43 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 , V_66 ) ;
}
static inline bool F_44 ( T_1 V_67 )
{
return ! ! ( V_67 & V_68 ) ;
}
static bool F_45 ( struct V_10 * V_11 )
{
T_1 V_67 = F_43 ( V_11 ) ;
return F_44 ( V_67 ) ;
}
static inline bool F_46 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_17 = F_10 ( V_5 , V_66 ) ;
return ! ! ( V_17 & V_69 ) ;
}
static int F_47 ( struct V_10 * V_11 )
{
if ( F_45 ( V_11 ) )
return 0 ;
F_18 ( & V_11 -> V_24 ) ;
F_24 ( V_11 -> V_70 , V_11 -> V_71 ,
F_23 ( V_72 ) ) ;
F_20 ( & V_11 -> V_24 ) ;
if ( ! V_11 -> V_71 ) {
F_21 ( V_11 -> V_11 , L_9 ) ;
return - V_27 ;
}
V_11 -> V_71 = false ;
return 0 ;
}
static int F_48 ( struct V_10 * V_11 ,
struct V_73 * V_74 )
{
const struct V_73 * V_75 = & V_76 ;
struct V_77 * V_78 = F_49 ( V_11 -> V_11 ) ;
int V_30 ;
int V_79 ;
if ( ! V_74 )
return - V_80 ;
V_74 -> V_81 = V_75 -> V_81 ;
for ( V_79 = 0 ; V_79 < V_75 -> V_81 && V_79 < V_82 ; V_79 ++ ) {
V_30 = F_50 ( V_78 ,
V_75 -> V_44 [ V_79 ] , & V_74 -> V_44 [ V_79 ] ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
static void F_51 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
V_11 -> V_83 = V_84 / 4 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_67 = F_43 ( V_11 ) ;
F_14 ( V_11 -> V_11 , L_10 ,
V_5 -> V_8 , V_5 -> V_67 ) ;
}
static int F_52 ( struct V_10 * V_11 ,
struct V_85 * V_86 , unsigned char * V_87 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
unsigned long V_88 ;
unsigned long V_89 ;
int V_90 = V_11 -> V_83 ;
T_1 * V_91 = ( T_1 * ) V_87 ;
T_1 V_92 ;
int V_79 ;
if ( F_53 ( ! V_86 || ! V_87 ) )
return - V_80 ;
V_89 = V_86 -> V_89 ;
F_14 ( V_11 -> V_11 , V_93 , F_54 ( V_86 ) ) ;
V_92 = F_55 ( V_89 ) ;
if ( V_92 > V_90 )
return - V_94 ;
if ( F_7 ( ! V_5 -> V_8 , L_11 ) )
return - V_95 ;
F_30 ( V_11 ) ;
if ( ! F_34 ( V_11 ) ) {
struct V_73 V_74 ;
V_73 ( V_11 , & V_74 ) ;
F_21 ( V_11 -> V_11 , L_12 V_96 L_13 ,
F_56 ( V_74 ) ) ;
return - V_95 ;
}
F_39 ( V_11 , 0 , * ( ( T_1 * ) V_86 ) ) ;
for ( V_79 = 0 ; V_79 < V_89 / 4 ; V_79 ++ )
F_39 ( V_11 , V_79 + 1 , V_91 [ V_79 ] ) ;
V_88 = V_89 & 0x3 ;
if ( V_88 > 0 ) {
T_1 V_17 = 0 ;
memcpy ( & V_17 , & V_87 [ V_89 - V_88 ] , V_88 ) ;
F_39 ( V_11 , V_79 + 1 , V_17 ) ;
}
V_5 -> V_90 = 0 ;
F_31 ( V_5 ) ;
return 0 ;
}
static T_3 F_57 ( const struct V_10 * V_11 )
{
return V_84 - sizeof( struct V_85 ) ;
}
static int F_58 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return V_5 -> V_90 ;
}
static int F_59 ( struct V_10 * V_11 )
{
return V_84 / 4 ;
}
static T_1 F_60 ( const struct V_10 * V_11 )
{
return F_40 ( V_11 , 0 ) ;
}
static int F_61 ( struct V_10 * V_11 ,
unsigned char * V_87 , unsigned long V_97 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 * V_91 , V_17 ;
T_1 V_88 ;
T_1 V_79 ;
if ( F_53 ( ! V_87 || ! V_97 ) )
return - V_80 ;
V_91 = ( T_1 * ) V_87 ;
V_88 = V_97 & 0x3 ;
F_14 ( V_11 -> V_11 , L_14 ,
V_97 , F_40 ( V_11 , 0 ) ) ;
for ( V_79 = 0 ; V_79 < V_97 / 4 ; V_79 ++ ) {
V_17 = F_40 ( V_11 , V_79 + 1 ) ;
F_14 ( V_11 -> V_11 , L_15 , V_79 , V_17 ) ;
* V_91 ++ = V_17 ;
}
if ( V_88 ) {
V_17 = F_40 ( V_11 , V_79 + 1 ) ;
memcpy ( V_91 , & V_17 , V_88 ) ;
}
F_33 ( V_5 ) ;
return 0 ;
}
static int F_62 ( struct V_10 * V_11 , bool V_98 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_99 ;
( void ) F_5 ( V_5 , V_41 ) ;
V_99 = F_15 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
F_36 ( V_11 ) ;
if ( V_99 != V_5 -> V_8 )
if ( F_17 ( V_11 , V_99 ) < 0 ) {
F_21 ( V_11 -> V_11 , L_16 ) ;
return - V_100 ;
}
if ( V_99 ) {
F_12 ( V_11 , 0 ) ;
if ( F_17 ( V_11 , 0 ) < 0 ) {
F_21 ( V_11 -> V_11 , L_17 ) ;
return - V_100 ;
}
}
F_42 ( V_11 ) ;
return 0 ;
}
static int F_63 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
int V_30 ;
T_1 V_101 ;
F_37 ( V_11 ) ;
V_30 = F_47 ( V_11 ) ;
if ( V_30 < 0 ) {
F_21 ( V_11 -> V_11 , L_18 ) ;
return V_30 ;
}
V_101 = F_10 ( V_5 , V_49 ) ;
if ( V_101 & V_102 )
F_11 ( V_5 , V_49 , V_102 ) ;
F_32 ( V_103 , & V_5 -> V_40 ) ;
V_30 = F_27 ( V_11 , 1 ) ;
if ( V_30 < 0 ) {
F_21 ( V_11 -> V_11 , L_17 ) ;
return V_30 ;
}
F_30 ( V_11 ) ;
F_33 ( V_5 ) ;
F_41 ( V_11 ) ;
return 0 ;
}
static bool F_64 ( struct V_10 * V_11 , bool V_104 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_101 ;
T_1 V_105 ;
T_1 V_106 ;
T_1 V_8 ;
bool V_107 ;
V_105 = F_10 ( V_5 , V_51 ) ;
V_107 = ( V_105 & V_52 ) ;
if ( ! V_107 )
goto V_108;
V_101 = F_10 ( V_5 , V_49 ) ;
V_8 = F_16 ( V_11 ) ;
if ( V_105 & V_109 && V_8 )
V_106 = F_5 ( V_5 ,
V_47 ) ;
else
V_106 = 0 ;
V_107 = V_107 ||
( V_101 & V_50 ) ||
( V_106 & V_48 ) ;
if ( V_107 && V_104 ) {
V_5 -> V_40 |= V_101 & V_50 ;
if ( V_106 & V_110 )
V_5 -> V_40 |= V_58 ;
F_36 ( V_11 ) ;
F_8 ( V_5 ,
V_47 , V_106 ) ;
F_11 ( V_5 , V_49 , V_101 ) ;
F_11 ( V_5 , V_51 , V_105 ) ;
}
V_108:
return V_107 ;
}
T_4 F_65 ( int V_111 , void * V_112 )
{
struct V_10 * V_11 = V_112 ;
if ( F_64 ( V_11 , true ) )
return V_113 ;
return V_114 ;
}
T_4 F_66 ( int V_111 , void * V_112 )
{
struct V_10 * V_11 = (struct V_10 * ) V_112 ;
struct V_4 * V_5 = F_13 ( V_11 ) ;
struct V_115 V_116 ;
T_5 V_90 ;
int V_117 = 0 ;
F_14 ( V_11 -> V_11 , L_19 ,
F_10 ( V_5 , V_51 ) ,
F_10 ( V_5 , V_49 ) ,
F_5 ( V_5 , V_47 ) ) ;
F_20 ( & V_11 -> V_24 ) ;
F_67 ( & V_116 ) ;
if ( F_68 ( F_49 ( V_11 -> V_11 ) ) )
F_64 ( V_11 , true ) ;
F_38 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_67 = F_43 ( V_11 ) ;
if ( F_69 ( V_118 , & V_5 -> V_40 ) ) {
F_14 ( V_11 -> V_11 , L_20 ) ;
if ( F_44 ( V_5 -> V_67 ) ) {
F_14 ( V_11 -> V_11 , L_21 ) ;
V_11 -> V_71 = true ;
} else {
V_11 -> V_71 = false ;
if ( V_11 -> V_119 != V_120 ) {
F_25 ( V_11 -> V_11 , L_22 ) ;
F_70 ( & V_11 -> V_121 ) ;
goto V_122;
}
}
F_71 ( & V_11 -> V_70 ) ;
}
if ( F_69 ( V_123 , & V_5 -> V_40 ) ) {
F_14 ( V_11 -> V_11 ,
L_23 , V_5 -> V_8 ) ;
V_11 -> V_14 = V_32 ;
if ( F_72 ( & V_5 -> V_31 ) )
F_71 ( & V_5 -> V_31 ) ;
}
V_90 = F_73 ( V_11 ) ;
if ( F_69 ( V_103 , & V_5 -> V_40 ) ) {
V_117 = F_74 ( V_11 , & V_116 , & V_90 ) ;
if ( V_117 && V_11 -> V_119 != V_120 ) {
F_21 ( V_11 -> V_11 ,
L_24 , V_117 ) ;
F_70 ( & V_11 -> V_121 ) ;
goto V_122;
}
}
if ( F_69 ( V_39 , & V_5 -> V_40 ) ) {
V_11 -> V_124 = true ;
V_5 -> V_90 = V_11 -> V_83 ;
}
if ( V_5 -> V_8 && V_11 -> V_124 ) {
V_11 -> V_124 = F_75 ( V_11 ) ;
V_117 = F_76 ( V_11 , & V_116 ) ;
if ( V_117 && V_117 != - V_94 )
F_21 ( V_11 -> V_11 , L_25 ,
V_117 ) ;
V_11 -> V_124 = F_75 ( V_11 ) ;
}
F_77 ( V_11 , & V_116 ) ;
V_122:
F_14 ( V_11 -> V_11 , L_26 , V_117 ) ;
F_18 ( & V_11 -> V_24 ) ;
F_78 ( V_11 ) ;
return V_125 ;
}
struct V_10 * F_79 ( struct V_77 * V_78 )
{
struct V_10 * V_11 ;
struct V_4 * V_5 ;
V_11 = F_80 ( sizeof( struct V_10 ) +
sizeof( struct V_4 ) , V_126 ) ;
if ( ! V_11 )
return NULL ;
F_81 ( V_11 , & V_78 -> V_11 , & V_127 ) ;
V_5 = F_13 ( V_11 ) ;
F_82 ( & V_5 -> V_31 ) ;
return V_11 ;
}
int F_83 ( struct V_10 * V_11 , T_6 V_128 , T_1 V_129 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_130 = F_84 ( V_128 ) ;
T_1 V_131 = F_85 ( V_128 ) ;
T_1 V_132 ;
if ( V_131 & ~ 0xF )
return - V_80 ;
if ( V_130 & 0xF )
return - V_80 ;
if ( V_129 & 0x4 )
return - V_80 ;
if ( V_129 > V_133 )
return - V_80 ;
V_132 = V_134 ;
V_132 |= V_131 << V_135 ;
F_11 ( V_5 , V_136 , V_129 ) ;
F_11 ( V_5 , V_137 , V_130 ) ;
F_11 ( V_5 , V_138 , V_132 ) ;
F_14 ( V_11 -> V_11 , L_27 ,
V_129 , V_130 , V_132 ) ;
return 0 ;
}
