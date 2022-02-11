static inline T_1 F_1 ( const struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( const struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( const struct V_6 * V_7 )
{
return F_1 ( F_6 ( V_7 ) , V_8 ) ;
}
static inline void F_7 ( struct V_6 * V_7 , T_1 V_9 )
{
F_3 ( F_6 ( V_7 ) , V_10 , V_9 ) ;
}
static inline T_1 F_8 ( const struct V_6 * V_7 )
{
T_1 V_11 ;
V_11 = F_1 ( F_6 ( V_7 ) , V_12 ) ;
F_9 ( V_7 -> V_7 , L_1 , V_12 , V_11 ) ;
return V_11 ;
}
static inline T_1 F_10 ( const struct V_6 * V_7 )
{
T_1 V_11 ;
V_11 = F_1 ( F_6 ( V_7 ) , V_13 ) ;
F_9 ( V_7 -> V_7 , L_2 , V_13 , V_11 ) ;
return V_11 ;
}
static inline void F_11 ( struct V_6 * V_7 , T_1 V_11 )
{
F_12 ( V_7 -> V_7 , L_2 , V_13 , V_11 ) ;
F_3 ( F_6 ( V_7 ) , V_13 , V_11 ) ;
}
static inline void F_13 ( struct V_6 * V_7 , T_1 V_11 )
{
V_11 &= ~ V_14 ;
F_11 ( V_7 , V_11 ) ;
}
static inline T_1 F_14 ( const struct V_6 * V_7 )
{
T_1 V_11 ;
V_11 = F_1 ( F_6 ( V_7 ) , V_15 ) ;
F_9 ( V_7 -> V_7 , L_3 , V_13 , V_11 ) ;
return V_11 ;
}
static inline void F_15 ( struct V_6 * V_7 , T_1 V_11 )
{
F_12 ( V_7 -> V_7 , L_3 , V_13 , V_11 ) ;
F_3 ( F_6 ( V_7 ) , V_15 , V_11 ) ;
}
static int F_16 ( struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 = F_17 ( V_7 -> V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_16 * V_20 = & V_2 -> V_21 -> V_17 ;
int V_22 ;
int V_23 ;
if ( ! V_17 )
return - V_24 ;
V_17 -> V_25 = V_20 -> V_25 ;
for ( V_23 = 0 ; V_23 < V_20 -> V_25 && V_23 < V_26 ; V_23 ++ ) {
V_22 = F_18 ( V_19 ,
V_20 -> V_27 [ V_23 ] , & V_17 -> V_27 [ V_23 ] ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_17 ( V_7 -> V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_28 , V_11 ;
V_28 = F_10 ( V_7 ) ;
V_7 -> V_29 = ( V_28 & V_30 ) >> 24 ;
V_11 = 0 ;
F_18 ( V_19 , V_31 , & V_11 ) ;
V_2 -> V_32 =
( ( V_11 & V_33 ) == V_33 ) ;
V_2 -> V_34 = V_35 ;
if ( V_2 -> V_32 ) {
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 )
V_2 -> V_34 = V_37 ;
}
}
static inline enum V_38 F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_34 ;
}
static void F_21 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
if ( V_28 & V_14 )
F_11 ( V_7 , V_28 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
V_28 |= V_39 ;
F_13 ( V_7 , V_28 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
V_28 &= ~ V_39 ;
F_13 ( V_7 , V_28 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
V_28 |= V_40 ;
V_28 &= ~ V_41 ;
F_13 ( V_7 , V_28 ) ;
F_25 () ;
}
static void F_26 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
V_28 |= V_39 | V_40 | V_42 ;
F_13 ( V_7 , V_28 ) ;
}
static bool F_27 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
return ( V_28 & V_42 ) == V_42 ;
}
static bool F_28 ( struct V_6 * V_7 )
{
T_1 V_43 = F_8 ( V_7 ) ;
return ( V_43 & V_44 ) == V_44 ;
}
static int F_29 ( struct V_6 * V_7 )
{
F_30 ( & V_7 -> V_45 ) ;
F_31 ( V_7 -> V_46 ,
V_7 -> V_47 ,
F_32 ( V_48 ) ) ;
F_33 ( & V_7 -> V_45 ) ;
if ( ! V_7 -> V_47 ) {
F_34 ( V_7 -> V_7 , L_4 ) ;
return - V_49 ;
}
F_24 ( V_7 ) ;
V_7 -> V_47 = false ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
int V_22 = F_29 ( V_7 ) ;
if ( V_22 )
return V_22 ;
F_36 ( V_7 -> V_7 , L_5 ) ;
F_26 ( V_7 ) ;
return V_22 ;
}
static unsigned char F_37 ( struct V_6 * V_7 )
{
T_1 V_28 ;
char V_50 , V_51 ;
V_28 = F_10 ( V_7 ) ;
V_50 = ( char ) ( ( V_28 & V_52 ) >> 8 ) ;
V_51 = ( char ) ( ( V_28 & V_53 ) >> 16 ) ;
return ( unsigned char ) ( V_51 - V_50 ) ;
}
static bool F_38 ( struct V_6 * V_7 )
{
return F_37 ( V_7 ) == 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
unsigned char V_54 , V_55 ;
V_54 = F_37 ( V_7 ) ;
V_55 = V_7 -> V_29 - V_54 ;
if ( V_54 > V_7 -> V_29 )
return - V_56 ;
return V_55 ;
}
static T_2 F_40 ( const struct V_6 * V_7 )
{
return V_7 -> V_29 * sizeof( T_1 ) - sizeof( struct V_57 ) ;
}
static int F_41 ( struct V_6 * V_7 ,
struct V_57 * V_58 ,
unsigned char * V_59 )
{
unsigned long V_60 ;
unsigned long V_61 = V_58 -> V_61 ;
T_1 * V_62 = ( T_1 * ) V_59 ;
T_1 V_28 ;
T_1 V_63 ;
int V_23 ;
int V_55 ;
F_36 ( V_7 -> V_7 , V_64 , F_42 ( V_58 ) ) ;
V_55 = F_43 ( V_7 ) ;
F_36 ( V_7 -> V_7 , L_6 , V_55 ) ;
V_63 = F_44 ( V_61 ) ;
if ( V_55 < 0 || V_63 > V_55 )
return - V_65 ;
F_7 ( V_7 , * ( ( T_1 * ) V_58 ) ) ;
for ( V_23 = 0 ; V_23 < V_61 / 4 ; V_23 ++ )
F_7 ( V_7 , V_62 [ V_23 ] ) ;
V_60 = V_61 & 0x3 ;
if ( V_60 > 0 ) {
T_1 V_11 = 0 ;
memcpy ( & V_11 , & V_59 [ V_61 - V_60 ] , V_60 ) ;
F_7 ( V_7 , V_11 ) ;
}
V_28 = F_10 ( V_7 ) | V_40 ;
F_13 ( V_7 , V_28 ) ;
if ( ! F_28 ( V_7 ) )
return - V_66 ;
return 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
T_1 V_67 ;
char V_50 , V_51 ;
unsigned char V_68 , V_54 ;
V_67 = F_8 ( V_7 ) ;
V_68 = ( unsigned char ) ( ( V_67 & V_69 ) >> 24 ) ;
V_50 = ( char ) ( ( V_67 & V_70 ) >> 8 ) ;
V_51 = ( char ) ( ( V_67 & V_71 ) >> 16 ) ;
V_54 = ( unsigned char ) ( V_51 - V_50 ) ;
if ( V_54 > V_68 )
return - V_56 ;
F_36 ( V_7 -> V_7 , L_7 , V_54 ) ;
return ( int ) V_54 ;
}
static int F_46 ( struct V_6 * V_7 , unsigned char * V_72 ,
unsigned long V_73 )
{
T_1 * V_62 = ( T_1 * ) V_72 ;
T_1 V_28 ;
for (; V_73 >= sizeof( T_1 ) ; V_73 -= sizeof( T_1 ) )
* V_62 ++ = F_5 ( V_7 ) ;
if ( V_73 > 0 ) {
T_1 V_11 = F_5 ( V_7 ) ;
memcpy ( V_62 , & V_11 , V_73 ) ;
}
V_28 = F_10 ( V_7 ) | V_40 ;
F_13 ( V_7 , V_28 ) ;
return 0 ;
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_74 ) ;
F_9 ( V_7 -> V_7 , L_8 , V_74 , V_11 ) ;
V_11 |= V_75 ;
F_12 ( V_7 -> V_7 , L_8 , V_74 , V_11 ) ;
F_3 ( V_2 , V_74 , V_11 ) ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_74 ) ;
F_9 ( V_7 -> V_7 , L_8 , V_74 , V_11 ) ;
F_49 ( ! ( V_11 & V_75 ) , L_9 ) ;
V_11 |= V_76 ;
F_12 ( V_7 -> V_7 , L_8 , V_74 , V_11 ) ;
F_3 ( V_2 , V_74 , V_11 ) ;
}
static int F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_77 = F_32 ( V_78 ) ;
int V_22 ;
V_7 -> V_79 = V_80 ;
V_22 = F_51 ( V_7 , V_81 ) ;
if ( V_22 )
return V_22 ;
F_30 ( & V_7 -> V_45 ) ;
F_31 ( V_7 -> V_82 ,
V_7 -> V_79 == V_83 , V_77 ) ;
F_33 ( & V_7 -> V_45 ) ;
if ( V_7 -> V_79 == V_83 ) {
F_47 ( V_7 ) ;
V_22 = 0 ;
} else {
V_22 = - V_49 ;
}
V_7 -> V_79 = V_84 ;
V_2 -> V_34 = V_37 ;
return V_22 ;
}
static int F_52 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_77 = F_32 ( V_78 ) ;
int V_22 ;
if ( V_7 -> V_79 == V_83 )
goto V_85;
V_7 -> V_79 = V_80 ;
F_48 ( V_7 ) ;
F_30 ( & V_7 -> V_45 ) ;
F_31 ( V_7 -> V_82 ,
V_7 -> V_79 == V_83 , V_77 ) ;
F_33 ( & V_7 -> V_45 ) ;
V_85:
if ( V_7 -> V_79 != V_83 ) {
V_22 = - V_49 ;
goto V_86;
}
V_7 -> V_79 = V_87 ;
V_22 = F_51 ( V_7 , V_88 ) ;
if ( V_22 )
return V_22 ;
F_30 ( & V_7 -> V_45 ) ;
F_31 ( V_7 -> V_82 ,
V_7 -> V_79 == V_89 , V_77 ) ;
F_33 ( & V_7 -> V_45 ) ;
if ( V_7 -> V_79 == V_89 )
V_22 = 0 ;
else
V_22 = - V_49 ;
V_86:
V_7 -> V_79 = V_84 ;
V_2 -> V_34 = V_35 ;
return V_22 ;
}
static bool F_53 ( struct V_6 * V_7 )
{
return V_7 -> V_79 >= V_80 &&
V_7 -> V_79 <= V_87 ;
}
static bool F_54 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_7 ) ;
if ( V_2 -> V_32 )
return true ;
if ( ( V_11 & V_90 ) == 0 )
goto V_91;
if ( ! V_7 -> V_92 )
goto V_91;
return true ;
V_91:
F_36 ( V_7 -> V_7 , L_10 ,
V_2 -> V_32 ,
! ! ( V_11 & V_90 ) ,
V_7 -> V_93 . V_94 ,
V_7 -> V_93 . V_95 ,
V_96 ,
V_97 ) ;
return false ;
}
static T_1 F_55 ( struct V_6 * V_7 , bool V_98 )
{
T_1 V_11 = F_14 ( V_7 ) ;
V_11 |= V_36 ;
if ( V_98 )
V_11 |= V_99 ;
else
V_11 &= ~ V_99 ;
F_15 ( V_7 , V_11 ) ;
V_11 = F_14 ( V_7 ) ;
return V_11 ;
}
static T_1 F_56 ( struct V_6 * V_7 )
{
T_1 V_11 = F_14 ( V_7 ) ;
V_11 &= ~ V_36 ;
V_11 |= V_99 ;
F_15 ( V_7 , V_11 ) ;
V_11 = F_14 ( V_7 ) ;
return V_11 ;
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_100 = F_32 ( V_101 ) ;
unsigned long V_102 = F_32 ( V_78 ) ;
int V_22 ;
T_1 V_11 ;
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 ) {
F_36 ( V_7 -> V_7 , L_11 ) ;
V_22 = 0 ;
goto V_103;
}
V_7 -> V_79 = V_80 ;
V_22 = F_51 ( V_7 , V_81 ) ;
if ( V_22 )
goto V_86;
F_30 ( & V_7 -> V_45 ) ;
F_31 ( V_7 -> V_82 ,
V_7 -> V_79 == V_83 , V_102 ) ;
F_33 ( & V_7 -> V_45 ) ;
if ( V_7 -> V_79 != V_83 ) {
V_22 = - V_49 ;
goto V_86;
}
V_7 -> V_79 = V_87 ;
V_11 = F_55 ( V_7 , true ) ;
if ( ! ( V_11 & V_104 ) ) {
F_36 ( V_7 -> V_7 , L_12 ) ;
V_22 = 0 ;
goto V_103;
}
F_30 ( & V_7 -> V_45 ) ;
F_31 ( V_7 -> V_82 ,
V_7 -> V_79 == V_89 , V_100 ) ;
F_33 ( & V_7 -> V_45 ) ;
if ( V_7 -> V_79 != V_89 ) {
V_11 = F_14 ( V_7 ) ;
if ( ! ( V_11 & V_36 ) ) {
V_22 = - V_49 ;
goto V_86;
}
}
V_22 = 0 ;
V_103:
V_2 -> V_34 = V_37 ;
V_86:
V_7 -> V_79 = V_84 ;
F_36 ( V_7 -> V_7 , L_13 , V_22 ) ;
return V_22 ;
}
static int F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 ) {
F_36 ( V_7 -> V_7 , L_14 ) ;
goto V_103;
}
F_55 ( V_7 , false ) ;
V_103:
V_2 -> V_34 = V_37 ;
V_7 -> V_79 = V_84 ;
F_36 ( V_7 -> V_7 , L_15 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_77 = F_32 ( V_101 ) ;
int V_22 ;
T_1 V_11 ;
V_7 -> V_79 = V_87 ;
V_11 = F_14 ( V_7 ) ;
if ( ! ( V_11 & V_36 ) ) {
F_36 ( V_7 -> V_7 , L_16 ) ;
V_22 = 0 ;
goto V_105;
}
V_11 = F_56 ( V_7 ) ;
if ( ! ( V_11 & V_104 ) ) {
F_36 ( V_7 -> V_7 , L_17 ) ;
V_22 = 0 ;
goto V_105;
}
F_30 ( & V_7 -> V_45 ) ;
F_31 ( V_7 -> V_82 ,
V_7 -> V_79 == V_89 , V_77 ) ;
F_33 ( & V_7 -> V_45 ) ;
if ( V_7 -> V_79 != V_89 ) {
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 ) {
V_22 = - V_49 ;
goto V_86;
}
}
V_22 = 0 ;
V_105:
V_2 -> V_34 = V_35 ;
V_86:
V_7 -> V_79 = V_84 ;
F_36 ( V_7 -> V_7 , L_18 , V_22 ) ;
return V_22 ;
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_7 -> V_79 != V_87 )
return;
V_7 -> V_79 = V_89 ;
V_2 -> V_34 = V_35 ;
if ( F_61 ( & V_7 -> V_82 ) )
F_62 ( & V_7 -> V_82 ) ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_7 -> V_79 == V_87 &&
( V_2 -> V_106 & V_107 ) ) {
V_7 -> V_79 = V_89 ;
if ( V_2 -> V_34 == V_37 ) {
V_2 -> V_34 = V_35 ;
if ( V_7 -> V_108 != V_109 ) {
F_36 ( V_7 -> V_7 , L_19 ) ;
F_26 ( V_7 ) ;
}
} else {
V_2 -> V_34 = V_37 ;
}
F_62 ( & V_7 -> V_82 ) ;
}
if ( V_2 -> V_34 == V_37 && ( V_2 -> V_106 & V_110 ) ) {
F_36 ( V_7 -> V_7 , L_20 ) ;
F_64 ( V_7 ) ;
}
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_32 )
F_63 ( V_7 ) ;
else
F_60 ( V_7 ) ;
}
int F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_32 )
return F_57 ( V_7 ) ;
else
return F_50 ( V_7 ) ;
}
int F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_32 )
return F_59 ( V_7 ) ;
else
return F_52 ( V_7 ) ;
}
static int F_68 ( struct V_6 * V_7 , bool V_111 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_22 ;
T_1 V_28 ;
if ( V_111 ) {
F_22 ( V_7 ) ;
if ( V_2 -> V_32 ) {
V_22 = F_59 ( V_7 ) ;
if ( V_22 )
return V_22 ;
}
}
V_28 = F_10 ( V_7 ) ;
if ( ( V_28 & V_41 ) == V_41 ) {
F_69 ( V_7 -> V_7 , L_21 , V_28 ) ;
V_28 &= ~ V_41 ;
F_13 ( V_7 , V_28 ) ;
V_28 = F_10 ( V_7 ) ;
}
V_28 |= V_41 | V_40 | V_14 ;
if ( ! V_111 )
V_28 &= ~ V_39 ;
V_7 -> V_47 = false ;
F_11 ( V_7 , V_28 ) ;
V_28 = F_10 ( V_7 ) ;
if ( ( V_28 & V_41 ) == 0 )
F_69 ( V_7 -> V_7 , L_22 , V_28 ) ;
if ( ( V_28 & V_42 ) == V_42 )
F_69 ( V_7 -> V_7 , L_23 , V_28 ) ;
if ( ! V_111 ) {
F_24 ( V_7 ) ;
if ( V_2 -> V_32 ) {
V_22 = F_58 ( V_7 ) ;
if ( V_22 )
return V_22 ;
}
}
return 0 ;
}
T_3 F_70 ( int V_112 , void * V_113 )
{
struct V_6 * V_7 = (struct V_6 * ) V_113 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_28 ;
V_28 = F_10 ( V_7 ) ;
if ( ! ( V_28 & V_14 ) )
return V_114 ;
V_2 -> V_106 = V_28 & V_14 ;
F_36 ( V_7 -> V_7 , L_24 , V_2 -> V_106 ) ;
F_11 ( V_7 , V_28 ) ;
return V_115 ;
}
T_3 F_71 ( int V_112 , void * V_113 )
{
struct V_6 * V_7 = (struct V_6 * ) V_113 ;
struct V_116 V_117 ;
T_4 V_118 ;
int V_119 = 0 ;
F_36 ( V_7 -> V_7 , L_25 ) ;
F_33 ( & V_7 -> V_45 ) ;
F_72 ( & V_117 ) ;
if ( ! F_73 ( V_7 ) && V_7 -> V_120 != V_121 ) {
F_69 ( V_7 -> V_7 , L_26 ) ;
F_74 ( & V_7 -> V_122 ) ;
goto V_123;
}
F_65 ( V_7 ) ;
if ( ! F_75 ( V_7 ) ) {
if ( F_73 ( V_7 ) ) {
F_36 ( V_7 -> V_7 , L_27 ) ;
V_7 -> V_47 = true ;
F_62 ( & V_7 -> V_46 ) ;
} else {
F_36 ( V_7 -> V_7 , L_28 ) ;
}
goto V_123;
}
V_118 = F_76 ( V_7 ) ;
while ( V_118 > 0 ) {
F_36 ( V_7 -> V_7 , L_29 , V_118 ) ;
V_119 = F_77 ( V_7 , & V_117 , & V_118 ) ;
if ( V_119 == - V_124 )
break;
if ( V_119 && V_7 -> V_120 != V_121 ) {
F_34 ( V_7 -> V_7 , L_30 ,
V_119 ) ;
F_74 ( & V_7 -> V_122 ) ;
goto V_123;
}
}
V_7 -> V_125 = F_78 ( V_7 ) ;
if ( V_7 -> V_79 != V_80 &&
V_7 -> V_79 != V_83 ) {
V_119 = F_79 ( V_7 , & V_117 ) ;
V_7 -> V_125 = F_78 ( V_7 ) ;
}
F_80 ( V_7 , & V_117 ) ;
V_123:
F_36 ( V_7 -> V_7 , L_31 , V_119 ) ;
F_30 ( & V_7 -> V_45 ) ;
return V_126 ;
}
static bool F_81 ( struct V_18 * V_19 )
{
T_1 V_11 ;
F_18 ( V_19 , V_127 , & V_11 ) ;
return ( V_11 & 0x600 ) == 0x200 ;
}
static bool F_82 ( struct V_18 * V_19 )
{
T_1 V_11 ;
F_18 ( V_19 , V_31 , & V_11 ) ;
return ( V_11 & 0xf0000 ) == 0xf0000 ;
}
struct V_6 * F_83 ( struct V_18 * V_19 ,
const struct V_128 * V_21 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_84 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_129 ) ;
if ( ! V_7 )
return NULL ;
V_2 = F_6 ( V_7 ) ;
F_85 ( V_7 , & V_19 -> V_7 , & V_130 ) ;
V_2 -> V_21 = V_21 ;
return V_7 ;
}
