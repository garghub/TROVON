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
F_9 ( V_7 -> V_7 , L_3 , V_15 , V_11 ) ;
return V_11 ;
}
static inline void F_15 ( struct V_6 * V_7 , T_1 V_11 )
{
F_12 ( V_7 -> V_7 , L_3 , V_15 , V_11 ) ;
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
V_22 = F_18 ( V_19 , V_20 -> V_27 [ V_23 ] ,
& V_17 -> V_27 [ V_23 ] ) ;
F_19 ( V_7 -> V_7 , L_4 ,
V_20 -> V_27 [ V_23 ] ,
V_17 -> V_27 [ V_23 ] ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static void F_20 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_17 ( V_7 -> V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_28 , V_11 ;
V_28 = F_10 ( V_7 ) ;
V_7 -> V_29 = ( V_28 & V_30 ) >> 24 ;
V_11 = 0 ;
F_18 ( V_19 , V_31 , & V_11 ) ;
F_19 ( V_7 -> V_7 , L_5 , V_31 , V_11 ) ;
V_2 -> V_32 =
( ( V_11 & V_33 ) == V_33 ) ;
V_2 -> V_34 = V_35 ;
if ( V_2 -> V_32 ) {
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 )
V_2 -> V_34 = V_37 ;
}
}
static inline enum V_38 F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_34 ;
}
static inline T_1 F_22 ( T_1 V_28 )
{
return V_28 & V_14 ;
}
static inline void F_23 ( struct V_6 * V_7 , T_1 V_28 )
{
V_28 &= ~ V_39 ;
F_13 ( V_7 , V_28 ) ;
}
static inline void F_24 ( struct V_6 * V_7 , T_1 V_28 )
{
if ( F_22 ( V_28 ) )
F_11 ( V_7 , V_28 ) ;
}
static void F_25 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
F_24 ( V_7 , V_28 ) ;
}
static void F_26 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
V_28 |= V_39 ;
F_13 ( V_7 , V_28 ) ;
}
static void F_27 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
F_23 ( V_7 , V_28 ) ;
}
static void F_28 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_17 ( V_7 -> V_7 ) ;
F_29 ( V_19 -> V_40 ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
V_28 |= V_41 ;
V_28 &= ~ V_42 ;
F_13 ( V_7 , V_28 ) ;
F_31 () ;
}
static void F_32 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
V_28 |= V_39 | V_41 | V_43 ;
F_13 ( V_7 , V_28 ) ;
}
static bool F_33 ( struct V_6 * V_7 )
{
T_1 V_28 = F_10 ( V_7 ) ;
return ( V_28 & V_43 ) == V_43 ;
}
static bool F_34 ( struct V_6 * V_7 )
{
T_1 V_44 = F_8 ( V_7 ) ;
return ( V_44 & V_45 ) == V_45 ;
}
static int F_35 ( struct V_6 * V_7 )
{
F_36 ( & V_7 -> V_46 ) ;
F_37 ( V_7 -> V_47 ,
V_7 -> V_48 ,
F_38 ( V_49 ) ) ;
F_39 ( & V_7 -> V_46 ) ;
if ( ! V_7 -> V_48 ) {
F_40 ( V_7 -> V_7 , L_6 ) ;
return - V_50 ;
}
F_30 ( V_7 ) ;
V_7 -> V_48 = false ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
int V_22 = F_35 ( V_7 ) ;
if ( V_22 )
return V_22 ;
F_42 ( V_7 -> V_7 , L_7 ) ;
F_32 ( V_7 ) ;
return V_22 ;
}
static unsigned char F_43 ( struct V_6 * V_7 )
{
T_1 V_28 ;
char V_51 , V_52 ;
V_28 = F_10 ( V_7 ) ;
V_51 = ( char ) ( ( V_28 & V_53 ) >> 8 ) ;
V_52 = ( char ) ( ( V_28 & V_54 ) >> 16 ) ;
return ( unsigned char ) ( V_52 - V_51 ) ;
}
static bool F_44 ( struct V_6 * V_7 )
{
return F_43 ( V_7 ) == 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
unsigned char V_55 , V_56 ;
V_55 = F_43 ( V_7 ) ;
V_56 = V_7 -> V_29 - V_55 ;
if ( V_55 > V_7 -> V_29 )
return - V_57 ;
return V_56 ;
}
static T_2 F_46 ( const struct V_6 * V_7 )
{
return V_7 -> V_29 * sizeof( T_1 ) - sizeof( struct V_58 ) ;
}
static int F_47 ( struct V_6 * V_7 ,
struct V_58 * V_59 ,
const unsigned char * V_60 )
{
unsigned long V_61 ;
unsigned long V_62 = V_59 -> V_62 ;
T_1 * V_63 = ( T_1 * ) V_60 ;
T_1 V_28 ;
T_1 V_64 ;
int V_23 ;
int V_56 ;
F_42 ( V_7 -> V_7 , V_65 , F_48 ( V_59 ) ) ;
V_56 = F_49 ( V_7 ) ;
F_42 ( V_7 -> V_7 , L_8 , V_56 ) ;
V_64 = F_50 ( V_62 ) ;
if ( V_56 < 0 || V_64 > V_56 )
return - V_66 ;
F_7 ( V_7 , * ( ( T_1 * ) V_59 ) ) ;
for ( V_23 = 0 ; V_23 < V_62 / 4 ; V_23 ++ )
F_7 ( V_7 , V_63 [ V_23 ] ) ;
V_61 = V_62 & 0x3 ;
if ( V_61 > 0 ) {
T_1 V_11 = 0 ;
memcpy ( & V_11 , & V_60 [ V_62 - V_61 ] , V_61 ) ;
F_7 ( V_7 , V_11 ) ;
}
V_28 = F_10 ( V_7 ) | V_41 ;
F_13 ( V_7 , V_28 ) ;
if ( ! F_34 ( V_7 ) )
return - V_67 ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 )
{
T_1 V_68 ;
char V_51 , V_52 ;
unsigned char V_69 , V_55 ;
V_68 = F_8 ( V_7 ) ;
V_69 = ( unsigned char ) ( ( V_68 & V_70 ) >> 24 ) ;
V_51 = ( char ) ( ( V_68 & V_71 ) >> 8 ) ;
V_52 = ( char ) ( ( V_68 & V_72 ) >> 16 ) ;
V_55 = ( unsigned char ) ( V_52 - V_51 ) ;
if ( V_55 > V_69 )
return - V_57 ;
F_42 ( V_7 -> V_7 , L_9 , V_55 ) ;
return ( int ) V_55 ;
}
static int F_52 ( struct V_6 * V_7 , unsigned char * V_73 ,
unsigned long V_74 )
{
T_1 * V_63 = ( T_1 * ) V_73 ;
T_1 V_28 ;
for (; V_74 >= sizeof( T_1 ) ; V_74 -= sizeof( T_1 ) )
* V_63 ++ = F_5 ( V_7 ) ;
if ( V_74 > 0 ) {
T_1 V_11 = F_5 ( V_7 ) ;
memcpy ( V_63 , & V_11 , V_74 ) ;
}
V_28 = F_10 ( V_7 ) | V_41 ;
F_13 ( V_7 , V_28 ) ;
return 0 ;
}
static void F_53 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_75 ) ;
F_9 ( V_7 -> V_7 , L_10 , V_75 , V_11 ) ;
V_11 |= V_76 ;
F_12 ( V_7 -> V_7 , L_10 , V_75 , V_11 ) ;
F_3 ( V_2 , V_75 , V_11 ) ;
}
static void F_54 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_75 ) ;
F_9 ( V_7 -> V_7 , L_10 , V_75 , V_11 ) ;
F_55 ( ! ( V_11 & V_76 ) , L_11 ) ;
V_11 |= V_77 ;
F_12 ( V_7 -> V_7 , L_10 , V_75 , V_11 ) ;
F_3 ( V_2 , V_75 , V_11 ) ;
}
static int F_56 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_78 = F_38 ( V_79 ) ;
int V_22 ;
V_7 -> V_80 = V_81 ;
V_22 = F_57 ( V_7 , V_82 ) ;
if ( V_22 )
return V_22 ;
F_36 ( & V_7 -> V_46 ) ;
F_37 ( V_7 -> V_83 ,
V_7 -> V_80 == V_84 , V_78 ) ;
F_39 ( & V_7 -> V_46 ) ;
if ( V_7 -> V_80 == V_84 ) {
F_53 ( V_7 ) ;
V_22 = 0 ;
} else {
V_22 = - V_50 ;
}
V_7 -> V_80 = V_85 ;
V_2 -> V_34 = V_37 ;
return V_22 ;
}
static int F_58 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_78 = F_38 ( V_79 ) ;
int V_22 ;
if ( V_7 -> V_80 == V_84 )
goto V_86;
V_7 -> V_80 = V_81 ;
F_54 ( V_7 ) ;
F_36 ( & V_7 -> V_46 ) ;
F_37 ( V_7 -> V_83 ,
V_7 -> V_80 == V_84 , V_78 ) ;
F_39 ( & V_7 -> V_46 ) ;
V_86:
if ( V_7 -> V_80 != V_84 ) {
V_22 = - V_50 ;
goto V_87;
}
V_7 -> V_80 = V_88 ;
V_22 = F_57 ( V_7 , V_89 ) ;
if ( V_22 )
return V_22 ;
F_36 ( & V_7 -> V_46 ) ;
F_37 ( V_7 -> V_83 ,
V_7 -> V_80 == V_90 , V_78 ) ;
F_39 ( & V_7 -> V_46 ) ;
if ( V_7 -> V_80 == V_90 )
V_22 = 0 ;
else
V_22 = - V_50 ;
V_87:
V_7 -> V_80 = V_85 ;
V_2 -> V_34 = V_35 ;
return V_22 ;
}
static bool F_59 ( struct V_6 * V_7 )
{
return V_7 -> V_80 >= V_81 &&
V_7 -> V_80 <= V_88 ;
}
static bool F_60 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_7 ) ;
if ( V_2 -> V_32 )
return true ;
if ( ( V_11 & V_91 ) == 0 )
goto V_92;
if ( ! V_7 -> V_93 )
goto V_92;
return true ;
V_92:
F_42 ( V_7 -> V_7 , L_12 ,
V_2 -> V_32 ,
! ! ( V_11 & V_91 ) ,
V_7 -> V_94 . V_95 ,
V_7 -> V_94 . V_96 ,
V_97 ,
V_98 ) ;
return false ;
}
static T_1 F_61 ( struct V_6 * V_7 , bool V_99 )
{
T_1 V_11 = F_14 ( V_7 ) ;
V_11 |= V_36 ;
if ( V_99 )
V_11 |= V_100 ;
else
V_11 &= ~ V_100 ;
F_15 ( V_7 , V_11 ) ;
V_11 = F_14 ( V_7 ) ;
return V_11 ;
}
static T_1 F_62 ( struct V_6 * V_7 )
{
T_1 V_11 = F_14 ( V_7 ) ;
V_11 &= ~ V_36 ;
V_11 |= V_100 ;
F_15 ( V_7 , V_11 ) ;
V_11 = F_14 ( V_7 ) ;
return V_11 ;
}
static int F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_101 = F_38 ( V_102 ) ;
unsigned long V_103 = F_38 ( V_79 ) ;
int V_22 ;
T_1 V_11 ;
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 ) {
F_42 ( V_7 -> V_7 , L_13 ) ;
V_22 = 0 ;
goto V_104;
}
V_7 -> V_80 = V_81 ;
V_22 = F_57 ( V_7 , V_82 ) ;
if ( V_22 )
goto V_87;
F_36 ( & V_7 -> V_46 ) ;
F_37 ( V_7 -> V_83 ,
V_7 -> V_80 == V_84 , V_103 ) ;
F_39 ( & V_7 -> V_46 ) ;
if ( V_7 -> V_80 != V_84 ) {
V_22 = - V_50 ;
goto V_87;
}
V_7 -> V_80 = V_88 ;
V_11 = F_61 ( V_7 , true ) ;
if ( ! ( V_11 & V_105 ) ) {
F_42 ( V_7 -> V_7 , L_14 ) ;
V_22 = 0 ;
goto V_104;
}
F_36 ( & V_7 -> V_46 ) ;
F_37 ( V_7 -> V_83 ,
V_7 -> V_80 == V_90 , V_101 ) ;
F_39 ( & V_7 -> V_46 ) ;
if ( V_7 -> V_80 != V_90 ) {
V_11 = F_14 ( V_7 ) ;
if ( ! ( V_11 & V_36 ) ) {
V_22 = - V_50 ;
goto V_87;
}
}
V_22 = 0 ;
V_104:
V_2 -> V_34 = V_37 ;
V_87:
V_7 -> V_80 = V_85 ;
F_42 ( V_7 -> V_7 , L_15 , V_22 ) ;
return V_22 ;
}
static int F_64 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 ) {
F_42 ( V_7 -> V_7 , L_16 ) ;
goto V_104;
}
F_61 ( V_7 , false ) ;
V_104:
V_2 -> V_34 = V_37 ;
V_7 -> V_80 = V_85 ;
F_42 ( V_7 -> V_7 , L_17 ) ;
return 0 ;
}
static int F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_78 = F_38 ( V_102 ) ;
int V_22 ;
T_1 V_11 ;
V_7 -> V_80 = V_88 ;
V_11 = F_14 ( V_7 ) ;
if ( ! ( V_11 & V_36 ) ) {
F_42 ( V_7 -> V_7 , L_18 ) ;
V_22 = 0 ;
goto V_106;
}
V_11 = F_62 ( V_7 ) ;
if ( ! ( V_11 & V_105 ) ) {
F_42 ( V_7 -> V_7 , L_19 ) ;
V_22 = 0 ;
goto V_106;
}
F_36 ( & V_7 -> V_46 ) ;
F_37 ( V_7 -> V_83 ,
V_7 -> V_80 == V_90 , V_78 ) ;
F_39 ( & V_7 -> V_46 ) ;
if ( V_7 -> V_80 != V_90 ) {
V_11 = F_14 ( V_7 ) ;
if ( V_11 & V_36 ) {
V_22 = - V_50 ;
goto V_87;
}
}
V_22 = 0 ;
V_106:
V_2 -> V_34 = V_35 ;
V_87:
V_7 -> V_80 = V_85 ;
F_42 ( V_7 -> V_7 , L_20 , V_22 ) ;
return V_22 ;
}
static void F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_7 -> V_80 != V_88 )
return;
V_7 -> V_80 = V_90 ;
V_2 -> V_34 = V_35 ;
if ( F_67 ( & V_7 -> V_83 ) )
F_68 ( & V_7 -> V_83 ) ;
}
static void F_69 ( struct V_6 * V_7 , T_1 V_107 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_7 -> V_80 == V_88 &&
( V_107 & V_108 ) ) {
V_7 -> V_80 = V_90 ;
if ( V_2 -> V_34 == V_37 ) {
V_2 -> V_34 = V_35 ;
if ( V_7 -> V_109 != V_110 ) {
F_42 ( V_7 -> V_7 , L_21 ) ;
F_32 ( V_7 ) ;
}
} else {
V_2 -> V_34 = V_37 ;
}
F_68 ( & V_7 -> V_83 ) ;
}
if ( V_2 -> V_34 == V_37 && ( V_107 & V_111 ) ) {
F_42 ( V_7 -> V_7 , L_22 ) ;
F_70 ( V_7 ) ;
}
}
static void F_71 ( struct V_6 * V_7 , T_1 V_107 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_32 )
F_69 ( V_7 , V_107 ) ;
else
F_66 ( V_7 ) ;
}
int F_72 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_32 )
return F_63 ( V_7 ) ;
else
return F_56 ( V_7 ) ;
}
int F_73 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
if ( V_2 -> V_32 )
return F_65 ( V_7 ) ;
else
return F_58 ( V_7 ) ;
}
static int F_74 ( struct V_6 * V_7 , bool V_112 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_22 ;
T_1 V_28 ;
if ( V_112 ) {
F_26 ( V_7 ) ;
if ( V_2 -> V_32 ) {
V_22 = F_65 ( V_7 ) ;
if ( V_22 )
return V_22 ;
}
}
F_75 ( V_7 -> V_7 ) ;
V_28 = F_10 ( V_7 ) ;
if ( ( V_28 & V_42 ) == V_42 ) {
F_76 ( V_7 -> V_7 , L_23 , V_28 ) ;
V_28 &= ~ V_42 ;
F_13 ( V_7 , V_28 ) ;
V_28 = F_10 ( V_7 ) ;
}
V_28 |= V_42 | V_41 | V_14 ;
if ( ! V_112 )
V_28 &= ~ V_39 ;
V_7 -> V_48 = false ;
F_11 ( V_7 , V_28 ) ;
V_28 = F_10 ( V_7 ) ;
if ( ( V_28 & V_42 ) == 0 )
F_76 ( V_7 -> V_7 , L_24 , V_28 ) ;
if ( ( V_28 & V_43 ) == V_43 )
F_76 ( V_7 -> V_7 , L_25 , V_28 ) ;
if ( ! V_112 ) {
F_30 ( V_7 ) ;
if ( V_2 -> V_32 ) {
V_22 = F_64 ( V_7 ) ;
if ( V_22 )
return V_22 ;
}
}
return 0 ;
}
T_3 F_77 ( int V_40 , void * V_113 )
{
struct V_6 * V_7 = (struct V_6 * ) V_113 ;
T_1 V_28 ;
V_28 = F_10 ( V_7 ) ;
if ( ! F_22 ( V_28 ) )
return V_114 ;
F_42 ( V_7 -> V_7 , L_26 , F_22 ( V_28 ) ) ;
F_23 ( V_7 , V_28 ) ;
return V_115 ;
}
T_3 F_78 ( int V_40 , void * V_113 )
{
struct V_6 * V_7 = (struct V_6 * ) V_113 ;
struct V_116 V_117 ;
T_4 V_118 ;
T_1 V_28 ;
int V_119 = 0 ;
F_42 ( V_7 -> V_7 , L_27 ) ;
F_39 ( & V_7 -> V_46 ) ;
V_28 = F_10 ( V_7 ) ;
F_24 ( V_7 , V_28 ) ;
F_79 ( & V_117 ) ;
if ( ! F_80 ( V_7 ) && V_7 -> V_120 != V_121 ) {
F_76 ( V_7 -> V_7 , L_28 ) ;
F_81 ( & V_7 -> V_122 ) ;
goto V_123;
}
F_71 ( V_7 , F_22 ( V_28 ) ) ;
if ( ! F_82 ( V_7 ) ) {
if ( F_80 ( V_7 ) ) {
F_42 ( V_7 -> V_7 , L_29 ) ;
V_7 -> V_48 = true ;
F_68 ( & V_7 -> V_47 ) ;
} else {
F_42 ( V_7 -> V_7 , L_30 ) ;
}
goto V_123;
}
V_118 = F_83 ( V_7 ) ;
while ( V_118 > 0 ) {
F_42 ( V_7 -> V_7 , L_31 , V_118 ) ;
V_119 = F_84 ( V_7 , & V_117 , & V_118 ) ;
if ( V_119 == - V_124 )
break;
if ( V_119 && V_7 -> V_120 != V_121 ) {
F_40 ( V_7 -> V_7 , L_32 ,
V_119 ) ;
F_81 ( & V_7 -> V_122 ) ;
goto V_123;
}
}
V_7 -> V_125 = F_85 ( V_7 ) ;
if ( V_7 -> V_80 != V_81 &&
V_7 -> V_80 != V_84 ) {
V_119 = F_86 ( V_7 , & V_117 ) ;
V_7 -> V_125 = F_85 ( V_7 ) ;
}
F_87 ( V_7 , & V_117 ) ;
V_123:
F_42 ( V_7 -> V_7 , L_33 , V_119 ) ;
F_26 ( V_7 ) ;
F_36 ( & V_7 -> V_46 ) ;
return V_126 ;
}
static bool F_88 ( struct V_18 * V_19 )
{
T_1 V_11 ;
F_18 ( V_19 , V_127 , & V_11 ) ;
F_19 ( & V_19 -> V_7 , L_34 , V_127 , V_11 ) ;
return ( V_11 & 0x600 ) == 0x200 ;
}
static bool F_89 ( struct V_18 * V_19 )
{
T_1 V_11 ;
unsigned int V_128 ;
V_128 = F_90 ( F_91 ( V_19 -> V_128 ) , 0 ) ;
F_92 ( V_19 -> V_129 , V_128 , V_31 , & V_11 ) ;
F_19 ( & V_19 -> V_7 , L_5 , V_31 , V_11 ) ;
return ( V_11 & 0xf0000 ) == 0xf0000 ;
}
struct V_6 * F_93 ( struct V_18 * V_19 ,
const struct V_130 * V_21 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_94 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_131 ) ;
if ( ! V_7 )
return NULL ;
V_2 = F_6 ( V_7 ) ;
F_95 ( V_7 , & V_19 -> V_7 , & V_132 ) ;
V_2 -> V_21 = V_21 ;
return V_7 ;
}
