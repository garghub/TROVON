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
static inline void F_14 ( struct V_6 * V_7 )
{
T_1 V_15 ;
V_15 = F_10 ( V_7 ) | V_16 ;
F_13 ( V_7 , V_15 ) ;
}
static inline T_1 F_15 ( const struct V_6 * V_7 )
{
T_1 V_11 ;
V_11 = F_1 ( F_6 ( V_7 ) , V_17 ) ;
F_9 ( V_7 -> V_7 , L_3 , V_17 , V_11 ) ;
return V_11 ;
}
static inline void F_16 ( struct V_6 * V_7 , T_1 V_11 )
{
F_12 ( V_7 -> V_7 , L_3 , V_17 , V_11 ) ;
F_3 ( F_6 ( V_7 ) , V_17 , V_11 ) ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_18 ( V_7 -> V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_18 * V_22 = & V_2 -> V_23 -> V_19 ;
int V_24 ;
int V_25 ;
if ( ! V_19 )
return - V_26 ;
V_19 -> V_27 = V_22 -> V_27 ;
for ( V_25 = 0 ; V_25 < V_22 -> V_27 && V_25 < V_28 ; V_25 ++ ) {
V_24 = F_19 ( V_21 , V_22 -> V_29 [ V_25 ] ,
& V_19 -> V_29 [ V_25 ] ) ;
F_20 ( V_7 -> V_7 , L_4 ,
V_22 -> V_29 [ V_25 ] ,
V_19 -> V_29 [ V_25 ] ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = F_18 ( V_7 -> V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_15 , V_11 ;
V_15 = F_10 ( V_7 ) ;
V_7 -> V_30 = ( V_15 & V_31 ) >> 24 ;
V_11 = 0 ;
F_19 ( V_21 , V_32 , & V_11 ) ;
F_20 ( V_7 -> V_7 , L_5 , V_32 , V_11 ) ;
V_2 -> V_33 =
( ( V_11 & V_34 ) == V_34 ) ;
V_2 -> V_35 = V_36 ;
if ( V_2 -> V_33 ) {
V_11 = F_15 ( V_7 ) ;
if ( V_11 & V_37 )
V_2 -> V_35 = V_38 ;
}
}
static inline enum V_39 F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_35 ;
}
static inline T_1 F_23 ( T_1 V_15 )
{
return V_15 & V_14 ;
}
static inline void F_24 ( struct V_6 * V_7 , T_1 V_15 )
{
V_15 &= ~ V_40 ;
F_13 ( V_7 , V_15 ) ;
}
static inline void F_25 ( struct V_6 * V_7 , T_1 V_15 )
{
if ( F_23 ( V_15 ) )
F_11 ( V_7 , V_15 ) ;
}
static void F_26 ( struct V_6 * V_7 )
{
T_1 V_15 = F_10 ( V_7 ) ;
F_25 ( V_7 , V_15 ) ;
}
static void F_27 ( struct V_6 * V_7 )
{
T_1 V_15 = F_10 ( V_7 ) ;
V_15 |= V_40 ;
F_13 ( V_7 , V_15 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
T_1 V_15 = F_10 ( V_7 ) ;
F_24 ( V_7 , V_15 ) ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = F_18 ( V_7 -> V_7 ) ;
F_30 ( V_21 -> V_41 ) ;
}
static void F_31 ( struct V_6 * V_7 )
{
T_1 V_15 = F_10 ( V_7 ) ;
V_15 |= V_16 ;
V_15 &= ~ V_42 ;
F_13 ( V_7 , V_15 ) ;
F_32 () ;
}
static void F_33 ( struct V_6 * V_7 )
{
T_1 V_15 = F_10 ( V_7 ) ;
V_15 |= V_40 | V_16 | V_43 ;
F_13 ( V_7 , V_15 ) ;
}
static bool F_34 ( struct V_6 * V_7 )
{
T_1 V_15 = F_10 ( V_7 ) ;
return ( V_15 & V_43 ) == V_43 ;
}
static bool F_35 ( struct V_6 * V_7 )
{
T_1 V_44 = F_8 ( V_7 ) ;
return ( V_44 & V_45 ) == V_45 ;
}
static bool F_36 ( struct V_6 * V_7 )
{
T_1 V_44 = F_8 ( V_7 ) ;
return ( V_44 & V_46 ) == V_46 ;
}
static int F_37 ( struct V_6 * V_7 )
{
F_38 ( & V_7 -> V_47 ) ;
F_39 ( V_7 -> V_48 ,
V_7 -> V_49 ,
F_40 ( V_50 ) ) ;
F_41 ( & V_7 -> V_47 ) ;
if ( ! V_7 -> V_49 ) {
F_42 ( V_7 -> V_7 , L_6 ) ;
return - V_51 ;
}
F_31 ( V_7 ) ;
V_7 -> V_49 = false ;
return 0 ;
}
static int F_43 ( struct V_6 * V_7 )
{
int V_24 = F_37 ( V_7 ) ;
if ( V_24 )
return V_24 ;
F_44 ( V_7 -> V_7 , L_7 ) ;
F_33 ( V_7 ) ;
return V_24 ;
}
static unsigned char F_45 ( struct V_6 * V_7 )
{
T_1 V_15 ;
char V_52 , V_53 ;
V_15 = F_10 ( V_7 ) ;
V_52 = ( char ) ( ( V_15 & V_54 ) >> 8 ) ;
V_53 = ( char ) ( ( V_15 & V_55 ) >> 16 ) ;
return ( unsigned char ) ( V_53 - V_52 ) ;
}
static bool F_46 ( struct V_6 * V_7 )
{
return F_45 ( V_7 ) == 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
unsigned char V_56 , V_57 ;
V_56 = F_45 ( V_7 ) ;
V_57 = V_7 -> V_30 - V_56 ;
if ( V_56 > V_7 -> V_30 )
return - V_58 ;
return V_57 ;
}
static T_2 F_48 ( const struct V_6 * V_7 )
{
return V_7 -> V_30 * sizeof( T_1 ) - sizeof( struct V_59 ) ;
}
static int F_49 ( struct V_6 * V_7 ,
struct V_59 * V_60 ,
const unsigned char * V_61 )
{
unsigned long V_62 ;
unsigned long V_63 = V_60 -> V_63 ;
T_1 * V_64 = ( T_1 * ) V_61 ;
T_1 V_65 ;
int V_25 ;
int V_57 ;
F_44 ( V_7 -> V_7 , V_66 , F_50 ( V_60 ) ) ;
V_57 = F_51 ( V_7 ) ;
F_44 ( V_7 -> V_7 , L_8 , V_57 ) ;
V_65 = F_52 ( V_63 ) ;
if ( V_57 < 0 || V_65 > V_57 )
return - V_67 ;
F_7 ( V_7 , * ( ( T_1 * ) V_60 ) ) ;
for ( V_25 = 0 ; V_25 < V_63 / 4 ; V_25 ++ )
F_7 ( V_7 , V_64 [ V_25 ] ) ;
V_62 = V_63 & 0x3 ;
if ( V_62 > 0 ) {
T_1 V_11 = 0 ;
memcpy ( & V_11 , & V_61 [ V_63 - V_62 ] , V_62 ) ;
F_7 ( V_7 , V_11 ) ;
}
F_14 ( V_7 ) ;
if ( ! F_35 ( V_7 ) )
return - V_68 ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 )
{
T_1 V_69 ;
char V_52 , V_53 ;
unsigned char V_70 , V_56 ;
V_69 = F_8 ( V_7 ) ;
V_70 = ( unsigned char ) ( ( V_69 & V_71 ) >> 24 ) ;
V_52 = ( char ) ( ( V_69 & V_72 ) >> 8 ) ;
V_53 = ( char ) ( ( V_69 & V_73 ) >> 16 ) ;
V_56 = ( unsigned char ) ( V_53 - V_52 ) ;
if ( V_56 > V_70 )
return - V_58 ;
F_44 ( V_7 -> V_7 , L_9 , V_56 ) ;
return ( int ) V_56 ;
}
static int F_54 ( struct V_6 * V_7 , unsigned char * V_74 ,
unsigned long V_75 )
{
T_1 * V_64 = ( T_1 * ) V_74 ;
for (; V_75 >= sizeof( T_1 ) ; V_75 -= sizeof( T_1 ) )
* V_64 ++ = F_5 ( V_7 ) ;
if ( V_75 > 0 ) {
T_1 V_11 = F_5 ( V_7 ) ;
memcpy ( V_64 , & V_11 , V_75 ) ;
}
F_14 ( V_7 ) ;
return 0 ;
}
static void F_55 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_76 ) ;
F_9 ( V_7 -> V_7 , L_10 , V_76 , V_11 ) ;
V_11 |= V_77 ;
F_12 ( V_7 -> V_7 , L_10 , V_76 , V_11 ) ;
F_3 ( V_2 , V_76 , V_11 ) ;
}
static void F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_76 ) ;
F_9 ( V_7 -> V_7 , L_10 , V_76 , V_11 ) ;
F_57 ( ! ( V_11 & V_77 ) , L_11 ) ;
V_11 |= V_78 ;
F_12 ( V_7 -> V_7 , L_10 , V_76 , V_11 ) ;
F_3 ( V_2 , V_76 , V_11 ) ;
}
static int F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_79 = F_40 ( V_80 ) ;
int V_24 ;
V_7 -> V_81 = V_82 ;
V_24 = F_59 ( V_7 , V_83 ) ;
if ( V_24 )
return V_24 ;
F_38 ( & V_7 -> V_47 ) ;
F_39 ( V_7 -> V_84 ,
V_7 -> V_81 == V_85 , V_79 ) ;
F_41 ( & V_7 -> V_47 ) ;
if ( V_7 -> V_81 == V_85 ) {
F_55 ( V_7 ) ;
V_24 = 0 ;
} else {
V_24 = - V_51 ;
}
V_7 -> V_81 = V_86 ;
V_2 -> V_35 = V_38 ;
return V_24 ;
}
static int F_60 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_79 = F_40 ( V_80 ) ;
int V_24 ;
if ( V_7 -> V_81 == V_85 )
goto V_87;
V_7 -> V_81 = V_82 ;
F_56 ( V_7 ) ;
F_38 ( & V_7 -> V_47 ) ;
F_39 ( V_7 -> V_84 ,
V_7 -> V_81 == V_85 , V_79 ) ;
F_41 ( & V_7 -> V_47 ) ;
V_87:
if ( V_7 -> V_81 != V_85 ) {
V_24 = - V_51 ;
goto V_88;
}
V_7 -> V_81 = V_89 ;
V_24 = F_59 ( V_7 , V_90 ) ;
if ( V_24 )
return V_24 ;
F_38 ( & V_7 -> V_47 ) ;
F_39 ( V_7 -> V_84 ,
V_7 -> V_81 == V_91 , V_79 ) ;
F_41 ( & V_7 -> V_47 ) ;
if ( V_7 -> V_81 == V_91 )
V_24 = 0 ;
else
V_24 = - V_51 ;
V_88:
V_7 -> V_81 = V_86 ;
V_2 -> V_35 = V_36 ;
return V_24 ;
}
static bool F_61 ( struct V_6 * V_7 )
{
return V_7 -> V_81 >= V_82 &&
V_7 -> V_81 <= V_89 ;
}
static bool F_62 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_7 ) ;
if ( V_2 -> V_33 )
return true ;
if ( ( V_11 & V_92 ) == 0 )
goto V_93;
if ( ! V_7 -> V_94 )
goto V_93;
return true ;
V_93:
F_44 ( V_7 -> V_7 , L_12 ,
V_2 -> V_33 ,
! ! ( V_11 & V_92 ) ,
V_7 -> V_95 . V_96 ,
V_7 -> V_95 . V_97 ,
V_98 ,
V_99 ) ;
return false ;
}
static T_1 F_63 ( struct V_6 * V_7 , bool V_100 )
{
T_1 V_11 = F_15 ( V_7 ) ;
V_11 |= V_37 ;
if ( V_100 )
V_11 |= V_101 ;
else
V_11 &= ~ V_101 ;
F_16 ( V_7 , V_11 ) ;
V_11 = F_15 ( V_7 ) ;
return V_11 ;
}
static T_1 F_64 ( struct V_6 * V_7 )
{
T_1 V_11 = F_15 ( V_7 ) ;
V_11 &= ~ V_37 ;
V_11 |= V_101 ;
F_16 ( V_7 , V_11 ) ;
V_11 = F_15 ( V_7 ) ;
return V_11 ;
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_102 = F_40 ( V_103 ) ;
unsigned long V_104 = F_40 ( V_80 ) ;
int V_24 ;
T_1 V_11 ;
V_11 = F_15 ( V_7 ) ;
if ( V_11 & V_37 ) {
F_44 ( V_7 -> V_7 , L_13 ) ;
V_24 = 0 ;
goto V_105;
}
V_7 -> V_81 = V_82 ;
V_24 = F_59 ( V_7 , V_83 ) ;
if ( V_24 )
goto V_88;
F_38 ( & V_7 -> V_47 ) ;
F_39 ( V_7 -> V_84 ,
V_7 -> V_81 == V_85 , V_104 ) ;
F_41 ( & V_7 -> V_47 ) ;
if ( V_7 -> V_81 != V_85 ) {
V_24 = - V_51 ;
goto V_88;
}
V_7 -> V_81 = V_89 ;
V_11 = F_63 ( V_7 , true ) ;
if ( ! ( V_11 & V_106 ) ) {
F_44 ( V_7 -> V_7 , L_14 ) ;
V_24 = 0 ;
goto V_105;
}
F_38 ( & V_7 -> V_47 ) ;
F_39 ( V_7 -> V_84 ,
V_7 -> V_81 == V_91 , V_102 ) ;
F_41 ( & V_7 -> V_47 ) ;
if ( V_7 -> V_81 != V_91 ) {
V_11 = F_15 ( V_7 ) ;
if ( ! ( V_11 & V_37 ) ) {
V_24 = - V_51 ;
goto V_88;
}
}
V_24 = 0 ;
V_105:
V_2 -> V_35 = V_38 ;
V_88:
V_7 -> V_81 = V_86 ;
F_44 ( V_7 -> V_7 , L_15 , V_24 ) ;
return V_24 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_15 ( V_7 ) ;
if ( V_11 & V_37 ) {
F_44 ( V_7 -> V_7 , L_16 ) ;
goto V_105;
}
F_63 ( V_7 , false ) ;
V_105:
V_2 -> V_35 = V_38 ;
V_7 -> V_81 = V_86 ;
F_44 ( V_7 -> V_7 , L_17 ) ;
return 0 ;
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_79 = F_40 ( V_103 ) ;
int V_24 ;
T_1 V_11 ;
V_7 -> V_81 = V_89 ;
V_11 = F_15 ( V_7 ) ;
if ( ! ( V_11 & V_37 ) ) {
F_44 ( V_7 -> V_7 , L_18 ) ;
V_24 = 0 ;
goto V_107;
}
V_11 = F_64 ( V_7 ) ;
if ( ! ( V_11 & V_106 ) ) {
F_44 ( V_7 -> V_7 , L_19 ) ;
V_24 = 0 ;
goto V_107;
}
F_38 ( & V_7 -> V_47 ) ;
F_39 ( V_7 -> V_84 ,
V_7 -> V_81 == V_91 , V_79 ) ;
F_41 ( & V_7 -> V_47 ) ;
if ( V_7 -> V_81 != V_91 ) {
V_11 = F_15 ( V_7 ) ;
if ( V_11 & V_37 ) {
V_24 = - V_51 ;
goto V_88;
}
}
V_24 = 0 ;
V_107:
V_2 -> V_35 = V_36 ;
V_88:
V_7 -> V_81 = V_86 ;
F_44 ( V_7 -> V_7 , L_20 , V_24 ) ;
return V_24 ;
}
static void F_68 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_7 -> V_81 != V_89 )
return;
V_7 -> V_81 = V_91 ;
V_2 -> V_35 = V_36 ;
if ( F_69 ( & V_7 -> V_84 ) )
F_70 ( & V_7 -> V_84 ) ;
}
static void F_71 ( struct V_6 * V_7 , T_1 V_108 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_7 -> V_81 == V_89 &&
( V_108 & V_109 ) ) {
V_7 -> V_81 = V_91 ;
if ( V_2 -> V_35 == V_38 ) {
V_2 -> V_35 = V_36 ;
if ( V_7 -> V_110 != V_111 ) {
F_44 ( V_7 -> V_7 , L_21 ) ;
F_33 ( V_7 ) ;
}
} else {
V_2 -> V_35 = V_38 ;
}
F_70 ( & V_7 -> V_84 ) ;
}
if ( V_2 -> V_35 == V_38 && ( V_108 & V_112 ) ) {
F_44 ( V_7 -> V_7 , L_22 ) ;
F_72 ( V_7 ) ;
}
}
static void F_73 ( struct V_6 * V_7 , T_1 V_108 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_33 )
F_71 ( V_7 , V_108 ) ;
else
F_68 ( V_7 ) ;
}
int F_74 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_33 )
return F_65 ( V_7 ) ;
else
return F_58 ( V_7 ) ;
}
int F_75 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_33 )
return F_67 ( V_7 ) ;
else
return F_60 ( V_7 ) ;
}
static int F_76 ( struct V_6 * V_7 , bool V_113 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_24 ;
T_1 V_15 ;
if ( V_113 ) {
F_27 ( V_7 ) ;
if ( V_2 -> V_33 ) {
V_24 = F_67 ( V_7 ) ;
if ( V_24 )
return V_24 ;
}
}
F_77 ( V_7 -> V_7 ) ;
V_15 = F_10 ( V_7 ) ;
if ( ( V_15 & V_42 ) == V_42 ) {
F_78 ( V_7 -> V_7 , L_23 , V_15 ) ;
V_15 &= ~ V_42 ;
F_13 ( V_7 , V_15 ) ;
V_15 = F_10 ( V_7 ) ;
}
V_15 |= V_42 | V_16 | V_14 ;
if ( ! V_113 )
V_15 &= ~ V_40 ;
V_7 -> V_49 = false ;
F_11 ( V_7 , V_15 ) ;
V_15 = F_10 ( V_7 ) ;
if ( ( V_15 & V_42 ) == 0 )
F_78 ( V_7 -> V_7 , L_24 , V_15 ) ;
if ( ( V_15 & V_43 ) == V_43 )
F_78 ( V_7 -> V_7 , L_25 , V_15 ) ;
if ( ! V_113 ) {
F_31 ( V_7 ) ;
if ( V_2 -> V_33 ) {
V_24 = F_66 ( V_7 ) ;
if ( V_24 )
return V_24 ;
}
}
return 0 ;
}
T_3 F_79 ( int V_41 , void * V_114 )
{
struct V_6 * V_7 = (struct V_6 * ) V_114 ;
T_1 V_15 ;
V_15 = F_10 ( V_7 ) ;
if ( ! F_23 ( V_15 ) )
return V_115 ;
F_44 ( V_7 -> V_7 , L_26 , F_23 ( V_15 ) ) ;
F_24 ( V_7 , V_15 ) ;
return V_116 ;
}
T_3 F_80 ( int V_41 , void * V_114 )
{
struct V_6 * V_7 = (struct V_6 * ) V_114 ;
struct V_117 V_118 ;
T_4 V_119 ;
T_1 V_15 ;
int V_120 = 0 ;
F_44 ( V_7 -> V_7 , L_27 ) ;
F_41 ( & V_7 -> V_47 ) ;
V_15 = F_10 ( V_7 ) ;
F_25 ( V_7 , V_15 ) ;
F_81 ( & V_118 ) ;
if ( ! F_82 ( V_7 ) && V_7 -> V_121 != V_122 ) {
F_78 ( V_7 -> V_7 , L_28 ) ;
F_83 ( & V_7 -> V_123 ) ;
goto V_124;
}
if ( F_36 ( V_7 ) )
F_14 ( V_7 ) ;
F_73 ( V_7 , F_23 ( V_15 ) ) ;
if ( ! F_84 ( V_7 ) ) {
if ( F_82 ( V_7 ) ) {
F_44 ( V_7 -> V_7 , L_29 ) ;
V_7 -> V_49 = true ;
F_70 ( & V_7 -> V_48 ) ;
} else {
F_44 ( V_7 -> V_7 , L_30 ) ;
}
goto V_124;
}
V_119 = F_85 ( V_7 ) ;
while ( V_119 > 0 ) {
F_44 ( V_7 -> V_7 , L_31 , V_119 ) ;
V_120 = F_86 ( V_7 , & V_118 , & V_119 ) ;
if ( V_120 == - V_125 )
break;
if ( V_120 && V_7 -> V_121 != V_122 ) {
F_42 ( V_7 -> V_7 , L_32 ,
V_120 ) ;
F_83 ( & V_7 -> V_123 ) ;
goto V_124;
}
}
V_7 -> V_126 = F_87 ( V_7 ) ;
if ( V_7 -> V_81 != V_82 &&
V_7 -> V_81 != V_85 ) {
V_120 = F_88 ( V_7 , & V_118 ) ;
V_7 -> V_126 = F_87 ( V_7 ) ;
}
F_89 ( V_7 , & V_118 ) ;
V_124:
F_44 ( V_7 -> V_7 , L_33 , V_120 ) ;
F_27 ( V_7 ) ;
F_38 ( & V_7 -> V_47 ) ;
return V_127 ;
}
static bool F_90 ( struct V_20 * V_21 )
{
T_1 V_11 ;
F_19 ( V_21 , V_128 , & V_11 ) ;
F_20 ( & V_21 -> V_7 , L_34 , V_128 , V_11 ) ;
return ( V_11 & 0x600 ) == 0x200 ;
}
static bool F_91 ( struct V_20 * V_21 )
{
T_1 V_11 ;
unsigned int V_129 ;
V_129 = F_92 ( F_93 ( V_21 -> V_129 ) , 0 ) ;
F_94 ( V_21 -> V_130 , V_129 , V_32 , & V_11 ) ;
F_20 ( & V_21 -> V_7 , L_5 , V_32 , V_11 ) ;
return ( V_11 & 0xf0000 ) == 0xf0000 ;
}
const struct V_131 * F_95 ( T_5 V_132 )
{
F_96 ( F_97 ( V_133 ) != V_134 ) ;
if ( V_132 >= V_134 )
return NULL ;
return V_133 [ V_132 ] ;
}
struct V_6 * F_98 ( struct V_20 * V_21 ,
const struct V_131 * V_23 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_99 ( & V_21 -> V_7 , sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_135 ) ;
if ( ! V_7 )
return NULL ;
V_2 = F_6 ( V_7 ) ;
F_100 ( V_7 , & V_21 -> V_7 , & V_136 ) ;
V_2 -> V_23 = V_23 ;
return V_7 ;
}
