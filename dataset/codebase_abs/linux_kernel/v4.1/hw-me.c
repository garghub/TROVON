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
static int F_14 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_15 ( V_7 -> V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_15 * V_19 = & V_2 -> V_20 -> V_16 ;
int V_21 ;
int V_22 ;
if ( ! V_16 )
return - V_23 ;
V_16 -> V_24 = V_19 -> V_24 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_24 && V_22 < V_25 ; V_22 ++ ) {
V_21 = F_16 ( V_18 ,
V_19 -> V_26 [ V_22 ] , & V_16 -> V_26 [ V_22 ] ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_27 = F_10 ( V_7 ) ;
V_7 -> V_28 = ( V_27 & V_29 ) >> 24 ;
V_2 -> V_30 = V_31 ;
}
static inline enum V_32 F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_30 ;
}
static void F_19 ( struct V_6 * V_7 )
{
T_1 V_27 = F_10 ( V_7 ) ;
if ( ( V_27 & V_14 ) == V_14 )
F_11 ( V_7 , V_27 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
T_1 V_27 = F_10 ( V_7 ) ;
V_27 |= V_33 ;
F_13 ( V_7 , V_27 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
T_1 V_27 = F_10 ( V_7 ) ;
V_27 &= ~ V_33 ;
F_13 ( V_7 , V_27 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
T_1 V_27 = F_10 ( V_7 ) ;
V_27 |= V_34 ;
V_27 &= ~ V_35 ;
F_13 ( V_7 , V_27 ) ;
F_23 () ;
}
static int F_24 ( struct V_6 * V_7 , bool V_36 )
{
T_1 V_27 = F_10 ( V_7 ) ;
if ( ( V_27 & V_35 ) == V_35 ) {
F_25 ( V_7 -> V_7 , L_3 , V_27 ) ;
V_27 &= ~ V_35 ;
F_13 ( V_7 , V_27 ) ;
V_27 = F_10 ( V_7 ) ;
}
V_27 |= V_35 | V_34 | V_14 ;
if ( V_36 )
V_27 |= V_33 ;
else
V_27 &= ~ V_33 ;
V_7 -> V_37 = false ;
F_11 ( V_7 , V_27 ) ;
V_27 = F_10 ( V_7 ) ;
if ( ( V_27 & V_35 ) == 0 )
F_25 ( V_7 -> V_7 , L_4 , V_27 ) ;
if ( ( V_27 & V_38 ) == V_38 )
F_25 ( V_7 -> V_7 , L_5 , V_27 ) ;
if ( V_36 == false )
F_22 ( V_7 ) ;
return 0 ;
}
static void F_26 ( struct V_6 * V_7 )
{
T_1 V_27 = F_10 ( V_7 ) ;
V_27 |= V_33 | V_34 | V_38 ;
F_13 ( V_7 , V_27 ) ;
}
static bool F_27 ( struct V_6 * V_7 )
{
T_1 V_27 = F_10 ( V_7 ) ;
return ( V_27 & V_38 ) == V_38 ;
}
static bool F_28 ( struct V_6 * V_7 )
{
T_1 V_39 = F_8 ( V_7 ) ;
return ( V_39 & V_40 ) == V_40 ;
}
static int F_29 ( struct V_6 * V_7 )
{
F_30 ( & V_7 -> V_41 ) ;
F_31 ( V_7 -> V_42 ,
V_7 -> V_37 ,
F_32 ( V_43 ) ) ;
F_33 ( & V_7 -> V_41 ) ;
if ( ! V_7 -> V_37 ) {
F_34 ( V_7 -> V_7 , L_6 ) ;
return - V_44 ;
}
F_22 ( V_7 ) ;
V_7 -> V_37 = false ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
int V_21 = F_29 ( V_7 ) ;
if ( V_21 )
return V_21 ;
F_36 ( V_7 -> V_7 , L_7 ) ;
F_26 ( V_7 ) ;
return V_21 ;
}
static unsigned char F_37 ( struct V_6 * V_7 )
{
T_1 V_27 ;
char V_45 , V_46 ;
V_27 = F_10 ( V_7 ) ;
V_45 = ( char ) ( ( V_27 & V_47 ) >> 8 ) ;
V_46 = ( char ) ( ( V_27 & V_48 ) >> 16 ) ;
return ( unsigned char ) ( V_46 - V_45 ) ;
}
static bool F_38 ( struct V_6 * V_7 )
{
return F_37 ( V_7 ) == 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
unsigned char V_49 , V_50 ;
V_49 = F_37 ( V_7 ) ;
V_50 = V_7 -> V_28 - V_49 ;
if ( V_49 > V_7 -> V_28 )
return - V_51 ;
return V_50 ;
}
static T_2 F_40 ( const struct V_6 * V_7 )
{
return V_7 -> V_28 * sizeof( T_1 ) - sizeof( struct V_52 ) ;
}
static int F_41 ( struct V_6 * V_7 ,
struct V_52 * V_53 ,
unsigned char * V_54 )
{
unsigned long V_55 ;
unsigned long V_56 = V_53 -> V_56 ;
T_1 * V_57 = ( T_1 * ) V_54 ;
T_1 V_27 ;
T_1 V_58 ;
int V_22 ;
int V_50 ;
F_36 ( V_7 -> V_7 , V_59 , F_42 ( V_53 ) ) ;
V_50 = F_43 ( V_7 ) ;
F_36 ( V_7 -> V_7 , L_8 , V_50 ) ;
V_58 = F_44 ( V_56 ) ;
if ( V_50 < 0 || V_58 > V_50 )
return - V_60 ;
F_7 ( V_7 , * ( ( T_1 * ) V_53 ) ) ;
for ( V_22 = 0 ; V_22 < V_56 / 4 ; V_22 ++ )
F_7 ( V_7 , V_57 [ V_22 ] ) ;
V_55 = V_56 & 0x3 ;
if ( V_55 > 0 ) {
T_1 V_11 = 0 ;
memcpy ( & V_11 , & V_54 [ V_56 - V_55 ] , V_55 ) ;
F_7 ( V_7 , V_11 ) ;
}
V_27 = F_10 ( V_7 ) | V_34 ;
F_13 ( V_7 , V_27 ) ;
if ( ! F_28 ( V_7 ) )
return - V_61 ;
return 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
T_1 V_62 ;
char V_45 , V_46 ;
unsigned char V_63 , V_49 ;
V_62 = F_8 ( V_7 ) ;
V_63 = ( unsigned char ) ( ( V_62 & V_64 ) >> 24 ) ;
V_45 = ( char ) ( ( V_62 & V_65 ) >> 8 ) ;
V_46 = ( char ) ( ( V_62 & V_66 ) >> 16 ) ;
V_49 = ( unsigned char ) ( V_46 - V_45 ) ;
if ( V_49 > V_63 )
return - V_51 ;
F_36 ( V_7 -> V_7 , L_9 , V_49 ) ;
return ( int ) V_49 ;
}
static int F_46 ( struct V_6 * V_7 , unsigned char * V_67 ,
unsigned long V_68 )
{
T_1 * V_57 = ( T_1 * ) V_67 ;
T_1 V_27 ;
for (; V_68 >= sizeof( T_1 ) ; V_68 -= sizeof( T_1 ) )
* V_57 ++ = F_5 ( V_7 ) ;
if ( V_68 > 0 ) {
T_1 V_11 = F_5 ( V_7 ) ;
memcpy ( V_57 , & V_11 , V_68 ) ;
}
V_27 = F_10 ( V_7 ) | V_34 ;
F_13 ( V_7 , V_27 ) ;
return 0 ;
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_69 ) ;
F_9 ( V_7 -> V_7 , L_10 , V_69 , V_11 ) ;
V_11 |= V_70 ;
F_12 ( V_7 -> V_7 , L_10 , V_69 , V_11 ) ;
F_3 ( V_2 , V_69 , V_11 ) ;
}
static void F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_2 , V_69 ) ;
F_9 ( V_7 -> V_7 , L_10 , V_69 , V_11 ) ;
F_49 ( ! ( V_11 & V_70 ) , L_11 ) ;
V_11 |= V_71 ;
F_12 ( V_7 -> V_7 , L_10 , V_69 , V_11 ) ;
F_3 ( V_2 , V_69 , V_11 ) ;
}
int F_50 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_72 = F_32 ( V_73 ) ;
int V_21 ;
V_7 -> V_74 = V_75 ;
V_21 = F_51 ( V_7 , V_76 ) ;
if ( V_21 )
return V_21 ;
F_30 ( & V_7 -> V_41 ) ;
F_31 ( V_7 -> V_77 ,
V_7 -> V_74 == V_78 , V_72 ) ;
F_33 ( & V_7 -> V_41 ) ;
if ( V_7 -> V_74 == V_78 ) {
F_47 ( V_7 ) ;
V_21 = 0 ;
} else {
V_21 = - V_44 ;
}
V_7 -> V_74 = V_79 ;
V_2 -> V_30 = V_80 ;
return V_21 ;
}
int F_52 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_72 = F_32 ( V_73 ) ;
int V_21 ;
if ( V_7 -> V_74 == V_78 )
goto V_81;
V_7 -> V_74 = V_75 ;
F_48 ( V_7 ) ;
F_30 ( & V_7 -> V_41 ) ;
F_31 ( V_7 -> V_77 ,
V_7 -> V_74 == V_78 , V_72 ) ;
F_33 ( & V_7 -> V_41 ) ;
V_81:
if ( V_7 -> V_74 == V_78 )
V_21 = F_51 ( V_7 , V_82 ) ;
else
V_21 = - V_44 ;
V_7 -> V_74 = V_79 ;
V_2 -> V_30 = V_31 ;
return V_21 ;
}
static bool F_53 ( struct V_6 * V_7 )
{
T_1 V_11 = F_8 ( V_7 ) ;
if ( ( V_11 & V_83 ) == 0 )
goto V_84;
if ( ! V_7 -> V_85 )
goto V_84;
return true ;
V_84:
F_36 ( V_7 -> V_7 , L_12 ,
! ! ( V_11 & V_83 ) ,
V_7 -> V_86 . V_87 ,
V_7 -> V_86 . V_88 ,
V_89 ,
V_90 ) ;
return false ;
}
T_3 F_54 ( int V_91 , void * V_92 )
{
struct V_6 * V_7 = (struct V_6 * ) V_92 ;
T_1 V_27 = F_10 ( V_7 ) ;
if ( ( V_27 & V_14 ) != V_14 )
return V_93 ;
F_11 ( V_7 , V_27 ) ;
return V_94 ;
}
T_3 F_55 ( int V_91 , void * V_92 )
{
struct V_6 * V_7 = (struct V_6 * ) V_92 ;
struct V_95 V_96 ;
T_4 V_97 ;
int V_98 = 0 ;
F_36 ( V_7 -> V_7 , L_13 ) ;
F_33 ( & V_7 -> V_41 ) ;
F_56 ( & V_96 ) ;
if ( F_57 ( F_15 ( V_7 -> V_7 ) ) )
F_58 ( V_7 ) ;
if ( ! F_59 ( V_7 ) && V_7 -> V_99 != V_100 ) {
F_25 ( V_7 -> V_7 , L_14 ) ;
F_60 ( & V_7 -> V_101 ) ;
goto V_102;
}
if ( ! F_61 ( V_7 ) ) {
if ( F_59 ( V_7 ) ) {
F_36 ( V_7 -> V_7 , L_15 ) ;
V_7 -> V_37 = true ;
F_62 ( & V_7 -> V_42 ) ;
} else {
F_36 ( V_7 -> V_7 , L_16 ) ;
}
goto V_102;
}
V_97 = F_63 ( V_7 ) ;
while ( V_97 > 0 ) {
F_36 ( V_7 -> V_7 , L_17 , V_97 ) ;
V_98 = F_64 ( V_7 , & V_96 , & V_97 ) ;
if ( V_98 == - V_103 )
break;
if ( V_98 && V_7 -> V_99 != V_100 ) {
F_34 ( V_7 -> V_7 , L_18 ,
V_98 ) ;
F_60 ( & V_7 -> V_101 ) ;
goto V_102;
}
}
V_7 -> V_104 = F_65 ( V_7 ) ;
if ( V_7 -> V_74 == V_79 ) {
V_98 = F_66 ( V_7 , & V_96 ) ;
V_7 -> V_104 = F_65 ( V_7 ) ;
}
F_67 ( V_7 , & V_96 ) ;
V_102:
F_36 ( V_7 -> V_7 , L_19 , V_98 ) ;
F_30 ( & V_7 -> V_41 ) ;
return V_105 ;
}
static bool F_68 ( struct V_17 * V_18 )
{
T_1 V_11 ;
F_16 ( V_18 , V_106 , & V_11 ) ;
return ( V_11 & 0x600 ) == 0x200 ;
}
static bool F_69 ( struct V_17 * V_18 )
{
T_1 V_11 ;
F_16 ( V_18 , V_107 , & V_11 ) ;
return ( V_11 & 0xf0000 ) == 0xf0000 ;
}
struct V_6 * F_70 ( struct V_17 * V_18 ,
const struct V_108 * V_20 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_71 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_109 ) ;
if ( ! V_7 )
return NULL ;
V_2 = F_6 ( V_7 ) ;
F_72 ( V_7 , & V_18 -> V_7 , & V_110 ) ;
V_2 -> V_20 = V_20 ;
return V_7 ;
}
