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
V_5 -> V_15 = false ;
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
F_14 ( & V_11 -> V_14 -> V_11 ,
L_4 , V_22 ) ;
return V_22 ;
}
F_18 ( & V_11 -> V_23 ) ;
F_19 ( V_24 / 5 ) ;
F_20 ( & V_11 -> V_23 ) ;
V_22 += V_24 / 5 ;
} while ( V_22 < V_25 );
F_21 ( & V_11 -> V_14 -> V_11 , L_5 ) ;
return - V_26 ;
}
static int F_22 ( struct V_10 * V_11 , T_1 V_21 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
const unsigned long V_27 =
F_23 ( V_25 ) ;
long V_28 ;
int V_29 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
if ( V_5 -> V_8 == V_21 )
return 0 ;
F_18 ( & V_11 -> V_23 ) ;
V_28 = F_24 ( V_5 -> V_30 ,
V_5 -> V_15 , V_27 ) ;
F_20 ( & V_11 -> V_23 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_29 = V_5 -> V_8 == V_21 ? 0 : - V_26 ;
if ( V_29 )
F_21 ( & V_11 -> V_14 -> V_11 , L_6 ) ;
else
F_14 ( & V_11 -> V_14 -> V_11 , L_4 ,
F_25 ( V_27 - V_28 ) ) ;
V_5 -> V_15 = false ;
return V_29 ;
}
int F_26 ( struct V_10 * V_11 , T_1 V_12 )
{
if ( F_12 ( V_11 , V_12 ) )
return F_22 ( V_11 , V_12 ) ;
return 0 ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_31 ;
V_31 = F_6 ( V_5 , V_32 ) ;
V_31 |= V_33 ;
F_9 ( V_5 , V_32 , V_31 ) ;
}
static void F_28 ( struct V_4 * V_5 )
{
F_29 ( V_34 , & V_5 -> V_35 ) ;
F_9 ( V_5 , V_36 , 1 ) ;
}
static void F_30 ( struct V_4 * V_5 )
{
F_11 ( V_5 ,
V_37 ,
V_38 ) ;
}
static bool F_31 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_39 ;
V_39 = F_6 ( V_5 , V_40 ) ;
return ! ! ( V_41 & V_39 ) ;
}
static inline void F_32 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_8 ( V_5 , V_42 ,
V_43 ) ;
F_11 ( V_5 , V_44 , V_45 ) ;
F_11 ( V_5 , V_46 , V_47 ) ;
}
static void F_33 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_48 , 0 ) ;
F_11 ( V_5 , V_49 , 0 ) ;
}
static void F_34 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_48 , V_47 ) ;
F_11 ( V_5 , V_49 , V_50 ) ;
}
static bool F_35 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
bool V_29 = ( V_5 -> V_35 & ( V_51 |
V_52 |
V_53 |
V_54 ) ) ;
if ( V_29 ) {
F_14 ( & V_11 -> V_14 -> V_11 ,
L_7 ,
! ! ( V_5 -> V_35 & V_53 ) ,
! ! ( V_5 -> V_35 & V_51 ) ,
! ! ( V_5 -> V_35 & V_52 ) ,
! ! ( V_5 -> V_35 & V_54 ) ) ;
}
return V_29 ;
}
static void F_36 ( struct V_10 * V_11 ,
unsigned long V_55 , T_1 V_3 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_9 ( V_5 , V_56 +
( V_55 * sizeof( T_1 ) ) , V_3 ) ;
}
static T_1 F_37 ( const struct V_10 * V_11 ,
unsigned long V_55 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 ,
V_57 + ( V_55 * sizeof( T_1 ) ) ) ;
}
static void F_38 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 ,
V_58 ,
V_59 ) ;
}
static void F_39 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
F_11 ( V_5 , V_58 ,
V_60 ) ;
}
static T_1 F_40 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return F_10 ( V_5 , V_61 ) ;
}
static inline bool F_41 ( T_1 V_62 )
{
return ! ! ( V_62 & V_63 ) ;
}
static bool F_42 ( struct V_10 * V_11 )
{
T_1 V_62 = F_40 ( V_11 ) ;
return F_41 ( V_62 ) ;
}
static inline bool F_43 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_17 = F_10 ( V_5 , V_61 ) ;
return ! ! ( V_17 & V_64 ) ;
}
static int F_44 ( struct V_10 * V_11 )
{
if ( F_42 ( V_11 ) )
return 0 ;
F_18 ( & V_11 -> V_23 ) ;
F_24 ( V_11 -> V_65 , V_11 -> V_66 ,
F_23 ( V_67 ) ) ;
F_20 ( & V_11 -> V_23 ) ;
if ( ! V_11 -> V_66 ) {
F_21 ( & V_11 -> V_14 -> V_11 , L_8 ) ;
return - V_26 ;
}
V_11 -> V_66 = false ;
return 0 ;
}
static void F_45 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
V_11 -> V_68 = V_69 / 4 ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_62 = F_40 ( V_11 ) ;
F_14 ( & V_11 -> V_14 -> V_11 , L_9 ,
V_5 -> V_8 , V_5 -> V_62 ) ;
}
static int F_46 ( struct V_10 * V_11 ,
struct V_70 * V_71 , unsigned char * V_72 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
unsigned long V_73 ;
unsigned long V_74 ;
int V_75 = V_11 -> V_68 ;
T_1 * V_76 = ( T_1 * ) V_72 ;
T_1 V_77 ;
int V_78 ;
if ( F_47 ( ! V_71 || ! V_72 ) )
return - V_79 ;
V_74 = V_71 -> V_74 ;
F_14 ( & V_11 -> V_14 -> V_11 , V_80 , F_48 ( V_71 ) ) ;
V_77 = F_49 ( V_74 ) ;
if ( V_77 > V_75 )
return - V_81 ;
if ( F_7 ( ! V_5 -> V_8 , L_10 ) )
return - V_82 ;
F_27 ( V_11 ) ;
if ( ! F_31 ( V_11 ) ) {
F_21 ( & V_11 -> V_14 -> V_11 , L_11 ) ;
return - V_82 ;
}
F_36 ( V_11 , 0 , * ( ( T_1 * ) V_71 ) ) ;
for ( V_78 = 0 ; V_78 < V_74 / 4 ; V_78 ++ )
F_36 ( V_11 , V_78 + 1 , V_76 [ V_78 ] ) ;
V_73 = V_74 & 0x3 ;
if ( V_73 > 0 ) {
T_1 V_17 = 0 ;
memcpy ( & V_17 , & V_72 [ V_74 - V_73 ] , V_73 ) ;
F_36 ( V_11 , V_78 + 1 , V_17 ) ;
}
V_5 -> V_75 = 0 ;
F_28 ( V_5 ) ;
return 0 ;
}
static T_3 F_50 ( const struct V_10 * V_11 )
{
return V_69 - sizeof( struct V_70 ) ;
}
static int F_51 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
return V_5 -> V_75 ;
}
static int F_52 ( struct V_10 * V_11 )
{
return V_69 / 4 ;
}
static T_1 F_53 ( const struct V_10 * V_11 )
{
return F_37 ( V_11 , 0 ) ;
}
static int F_54 ( struct V_10 * V_11 ,
unsigned char * V_72 , unsigned long V_83 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_78 ;
T_1 * V_76 = ( T_1 * ) V_72 ;
T_1 V_73 = V_83 & 0x3 ;
if ( F_47 ( ! V_72 || ! V_83 ) )
return - V_79 ;
F_14 ( & V_11 -> V_14 -> V_11 ,
L_12 ,
V_83 , F_37 ( V_11 , 0 ) ) ;
for ( V_78 = 0 ; V_78 < V_83 / 4 ; V_78 ++ ) {
T_1 V_17 = F_37 ( V_11 , V_78 + 1 ) ;
F_14 ( & V_11 -> V_14 -> V_11 , L_13 , V_78 , V_17 ) ;
* V_76 ++ = V_17 ;
}
if ( V_73 ) {
T_1 V_17 = F_37 ( V_11 , V_78 + 1 ) ;
memcpy ( V_76 , & V_17 , V_73 ) ;
}
F_30 ( V_5 ) ;
return 0 ;
}
static int F_55 ( struct V_10 * V_11 , bool V_84 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_85 ;
( void ) F_5 ( V_5 , V_36 ) ;
V_85 = F_15 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
F_33 ( V_11 ) ;
if ( V_85 != V_5 -> V_8 )
if ( F_17 ( V_11 , V_85 ) < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 ,
L_14 ) ;
return - V_86 ;
}
if ( V_85 ) {
F_12 ( V_11 , 0 ) ;
if ( F_17 ( V_11 , 0 ) < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 ,
L_15 ) ;
return - V_86 ;
}
}
F_39 ( V_11 ) ;
return 0 ;
}
static int F_56 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
int V_29 ;
T_1 V_87 ;
F_34 ( V_11 ) ;
V_29 = F_44 ( V_11 ) ;
if ( V_29 < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 , L_16 ) ;
return V_29 ;
}
V_87 = F_10 ( V_5 , V_44 ) ;
if ( V_87 & V_88 )
F_11 ( V_5 , V_44 , V_88 ) ;
F_29 ( V_89 , & V_5 -> V_35 ) ;
V_29 = F_26 ( V_11 , 1 ) ;
if ( V_29 < 0 ) {
F_21 ( & V_11 -> V_14 -> V_11 , L_15 ) ;
return V_29 ;
}
F_27 ( V_11 ) ;
F_30 ( V_5 ) ;
F_38 ( V_11 ) ;
return 0 ;
}
static bool F_57 ( struct V_10 * V_11 , bool V_90 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_87 ;
T_1 V_91 ;
T_1 V_92 ;
T_1 V_8 ;
bool V_93 ;
V_91 = F_10 ( V_5 , V_46 ) ;
V_93 = ( V_91 & V_47 ) ;
if ( ! V_93 )
goto V_94;
V_87 = F_10 ( V_5 , V_44 ) ;
V_8 = F_16 ( V_11 ) ;
if ( V_91 & V_95 && V_8 )
V_92 = F_5 ( V_5 ,
V_42 ) ;
else
V_92 = 0 ;
V_93 = V_93 ||
( V_87 & V_45 ) ||
( V_92 & V_43 ) ;
if ( V_93 && V_90 ) {
V_5 -> V_35 |= V_87 & V_45 ;
if ( V_92 & V_96 )
V_5 -> V_35 |= V_53 ;
F_33 ( V_11 ) ;
F_8 ( V_5 ,
V_42 , V_92 ) ;
F_11 ( V_5 , V_44 , V_87 ) ;
F_11 ( V_5 , V_46 , V_91 ) ;
}
V_94:
return V_93 ;
}
T_4 F_58 ( int V_97 , void * V_98 )
{
struct V_10 * V_11 = V_98 ;
if ( F_57 ( V_11 , true ) )
return V_99 ;
return V_100 ;
}
T_4 F_59 ( int V_97 , void * V_98 )
{
struct V_10 * V_11 = (struct V_10 * ) V_98 ;
struct V_4 * V_5 = F_13 ( V_11 ) ;
struct V_101 V_102 ;
T_5 V_75 ;
int V_103 = 0 ;
F_14 ( & V_11 -> V_14 -> V_11 , L_17 ,
F_10 ( V_5 , V_46 ) ,
F_10 ( V_5 , V_44 ) ,
F_5 ( V_5 , V_42 ) ) ;
F_20 ( & V_11 -> V_23 ) ;
F_60 ( & V_102 ) ;
if ( F_61 ( V_11 -> V_14 ) )
F_57 ( V_11 , true ) ;
F_35 ( V_11 ) ;
V_5 -> V_8 = F_16 ( V_11 ) ;
V_5 -> V_62 = F_40 ( V_11 ) ;
if ( F_62 ( V_104 , & V_5 -> V_35 ) ) {
F_14 ( & V_11 -> V_14 -> V_11 , L_18 ) ;
if ( F_41 ( V_5 -> V_62 ) ) {
F_14 ( & V_11 -> V_14 -> V_11 , L_19 ) ;
V_11 -> V_66 = true ;
} else {
V_11 -> V_66 = false ;
if ( V_11 -> V_105 != V_106 ) {
F_63 ( & V_11 -> V_14 -> V_11 , L_20 ) ;
F_64 ( & V_11 -> V_107 ) ;
goto V_108;
}
}
F_65 ( & V_11 -> V_65 ) ;
}
if ( F_62 ( V_109 , & V_5 -> V_35 ) ) {
F_14 ( & V_11 -> V_14 -> V_11 ,
L_21 , V_5 -> V_8 ) ;
V_5 -> V_15 = true ;
if ( F_66 ( & V_5 -> V_30 ) )
F_65 ( & V_5 -> V_30 ) ;
}
V_75 = F_67 ( V_11 ) ;
if ( F_62 ( V_89 , & V_5 -> V_35 ) ) {
V_103 = F_68 ( V_11 , & V_102 , & V_75 ) ;
if ( V_103 && V_11 -> V_105 != V_106 ) {
F_21 ( & V_11 -> V_14 -> V_11 ,
L_22 , V_103 ) ;
F_64 ( & V_11 -> V_107 ) ;
goto V_108;
}
}
if ( F_62 ( V_34 , & V_5 -> V_35 ) ) {
V_11 -> V_110 = true ;
V_5 -> V_75 = V_11 -> V_68 ;
}
if ( V_5 -> V_8 && V_11 -> V_110 ) {
V_11 -> V_110 = F_69 ( V_11 ) ;
V_103 = F_70 ( V_11 , & V_102 ) ;
if ( V_103 && V_103 != - V_81 )
F_21 ( & V_11 -> V_14 -> V_11 , L_23 ,
V_103 ) ;
V_11 -> V_110 = F_69 ( V_11 ) ;
}
F_71 ( V_11 , & V_102 ) ;
V_108:
F_14 ( & V_11 -> V_14 -> V_11 , L_24 , V_103 ) ;
F_18 ( & V_11 -> V_23 ) ;
F_72 ( V_11 ) ;
return V_111 ;
}
struct V_10 * F_73 ( struct V_112 * V_14 )
{
struct V_10 * V_11 ;
struct V_4 * V_5 ;
V_11 = F_74 ( sizeof( struct V_10 ) +
sizeof( struct V_4 ) , V_113 ) ;
if ( ! V_11 )
return NULL ;
F_75 ( V_11 ) ;
V_5 = F_13 ( V_11 ) ;
F_76 ( & V_5 -> V_30 ) ;
V_11 -> V_114 = & V_115 ;
V_11 -> V_14 = V_14 ;
return V_11 ;
}
int F_77 ( struct V_10 * V_11 , T_6 V_116 , T_1 V_117 )
{
struct V_4 * V_5 = F_13 ( V_11 ) ;
T_1 V_118 = F_78 ( V_116 ) ;
T_1 V_119 = F_79 ( V_116 ) ;
T_1 V_120 ;
if ( V_119 & ~ 0xF )
return - V_79 ;
if ( V_118 & 0xF )
return - V_79 ;
if ( V_117 & 0x4 )
return - V_79 ;
if ( V_117 > V_121 )
return - V_79 ;
V_120 = V_122 ;
V_120 |= V_119 << V_123 ;
F_11 ( V_5 , V_124 , V_117 ) ;
F_11 ( V_5 , V_125 , V_118 ) ;
F_11 ( V_5 , V_126 , V_120 ) ;
F_14 ( & V_11 -> V_14 -> V_11 , L_25 ,
V_117 , V_118 , V_120 ) ;
return 0 ;
}
