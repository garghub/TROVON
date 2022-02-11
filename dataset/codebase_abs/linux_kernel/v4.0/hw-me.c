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
static T_1 F_5 ( const struct V_6 * V_7 )
{
return F_1 ( F_6 ( V_7 ) , V_8 ) ;
}
static inline T_1 F_7 ( const struct V_1 * V_2 )
{
return F_1 ( V_2 , V_9 ) ;
}
static inline T_1 F_8 ( const struct V_1 * V_2 )
{
return F_1 ( V_2 , V_10 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_11 )
{
V_11 &= ~ V_12 ;
F_3 ( V_2 , V_10 , V_11 ) ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_11 ( V_7 -> V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
const struct V_13 * V_17 = & V_2 -> V_18 -> V_14 ;
int V_19 ;
int V_20 ;
if ( ! V_14 )
return - V_21 ;
V_14 -> V_22 = V_17 -> V_22 ;
for ( V_20 = 0 ; V_20 < V_17 -> V_22 && V_20 < V_23 ; V_20 ++ ) {
V_19 = F_12 ( V_16 ,
V_17 -> V_24 [ V_20 ] , & V_14 -> V_24 [ V_20 ] ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( F_6 ( V_7 ) ) ;
V_7 -> V_25 = ( V_11 & V_26 ) >> 24 ;
V_2 -> V_27 = V_28 ;
}
static inline enum V_29 F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_27 ;
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
if ( ( V_11 & V_12 ) == V_12 )
F_3 ( V_2 , V_10 , V_11 ) ;
}
static void F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_30 ;
F_9 ( V_2 , V_11 ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 &= ~ V_30 ;
F_9 ( V_2 , V_11 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_31 ;
V_11 &= ~ V_32 ;
F_9 ( V_2 , V_11 ) ;
F_19 () ;
}
static int F_20 ( struct V_6 * V_7 , bool V_33 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
if ( ( V_11 & V_32 ) == V_32 ) {
F_21 ( V_7 -> V_7 , L_1 , V_11 ) ;
V_11 &= ~ V_32 ;
F_9 ( V_2 , V_11 ) ;
V_11 = F_8 ( V_2 ) ;
}
V_11 |= V_32 | V_31 | V_12 ;
if ( V_33 )
V_11 |= V_30 ;
else
V_11 &= ~ V_30 ;
V_7 -> V_34 = false ;
F_3 ( V_2 , V_10 , V_11 ) ;
V_11 = F_8 ( V_2 ) ;
if ( ( V_11 & V_32 ) == 0 )
F_21 ( V_7 -> V_7 , L_2 , V_11 ) ;
if ( ( V_11 & V_35 ) == V_35 )
F_21 ( V_7 -> V_7 , L_3 , V_11 ) ;
if ( V_33 == false )
F_18 ( V_7 ) ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_30 | V_31 | V_35 ;
F_9 ( V_2 , V_11 ) ;
}
static bool F_23 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
return ( V_11 & V_35 ) == V_35 ;
}
static bool F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_36 = F_7 ( V_2 ) ;
return ( V_36 & V_37 ) == V_37 ;
}
static int F_25 ( struct V_6 * V_7 )
{
F_26 ( & V_7 -> V_38 ) ;
F_27 ( V_7 -> V_39 ,
V_7 -> V_34 ,
F_28 ( V_40 ) ) ;
F_29 ( & V_7 -> V_38 ) ;
if ( ! V_7 -> V_34 ) {
F_30 ( V_7 -> V_7 , L_4 ) ;
return - V_41 ;
}
F_18 ( V_7 ) ;
V_7 -> V_34 = false ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 )
{
int V_19 = F_25 ( V_7 ) ;
if ( V_19 )
return V_19 ;
F_32 ( V_7 -> V_7 , L_5 ) ;
F_22 ( V_7 ) ;
return V_19 ;
}
static unsigned char F_33 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 ;
char V_42 , V_43 ;
V_11 = F_8 ( V_2 ) ;
V_42 = ( char ) ( ( V_11 & V_44 ) >> 8 ) ;
V_43 = ( char ) ( ( V_11 & V_45 ) >> 16 ) ;
return ( unsigned char ) ( V_43 - V_42 ) ;
}
static bool F_34 ( struct V_6 * V_7 )
{
return F_33 ( V_7 ) == 0 ;
}
static int F_35 ( struct V_6 * V_7 )
{
unsigned char V_46 , V_47 ;
V_46 = F_33 ( V_7 ) ;
V_47 = V_7 -> V_25 - V_46 ;
if ( V_46 > V_7 -> V_25 )
return - V_48 ;
return V_47 ;
}
static T_2 F_36 ( const struct V_6 * V_7 )
{
return V_7 -> V_25 * sizeof( T_1 ) - sizeof( struct V_49 ) ;
}
static int F_37 ( struct V_6 * V_7 ,
struct V_49 * V_50 ,
unsigned char * V_51 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_52 ;
unsigned long V_53 = V_50 -> V_53 ;
T_1 * V_54 = ( T_1 * ) V_51 ;
T_1 V_11 ;
T_1 V_55 ;
int V_20 ;
int V_47 ;
F_32 ( V_7 -> V_7 , V_56 , F_38 ( V_50 ) ) ;
V_47 = F_39 ( V_7 ) ;
F_32 ( V_7 -> V_7 , L_6 , V_47 ) ;
V_55 = F_40 ( V_53 ) ;
if ( V_47 < 0 || V_55 > V_47 )
return - V_57 ;
F_3 ( V_2 , V_58 , * ( ( T_1 * ) V_50 ) ) ;
for ( V_20 = 0 ; V_20 < V_53 / 4 ; V_20 ++ )
F_3 ( V_2 , V_58 , V_54 [ V_20 ] ) ;
V_52 = V_53 & 0x3 ;
if ( V_52 > 0 ) {
T_1 V_59 = 0 ;
memcpy ( & V_59 , & V_51 [ V_53 - V_52 ] , V_52 ) ;
F_3 ( V_2 , V_58 , V_59 ) ;
}
V_11 = F_8 ( V_2 ) | V_31 ;
F_9 ( V_2 , V_11 ) ;
if ( ! F_24 ( V_7 ) )
return - V_60 ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_61 ;
char V_42 , V_43 ;
unsigned char V_62 , V_46 ;
V_61 = F_7 ( V_2 ) ;
V_62 = ( unsigned char ) ( ( V_61 & V_63 ) >> 24 ) ;
V_42 = ( char ) ( ( V_61 & V_64 ) >> 8 ) ;
V_43 = ( char ) ( ( V_61 & V_65 ) >> 16 ) ;
V_46 = ( unsigned char ) ( V_43 - V_42 ) ;
if ( V_46 > V_62 )
return - V_48 ;
F_32 ( V_7 -> V_7 , L_7 , V_46 ) ;
return ( int ) V_46 ;
}
static int F_42 ( struct V_6 * V_7 , unsigned char * V_66 ,
unsigned long V_67 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 * V_54 = ( T_1 * ) V_66 ;
T_1 V_11 ;
for (; V_67 >= sizeof( T_1 ) ; V_67 -= sizeof( T_1 ) )
* V_54 ++ = F_5 ( V_7 ) ;
if ( V_67 > 0 ) {
T_1 V_59 = F_5 ( V_7 ) ;
memcpy ( V_54 , & V_59 , V_67 ) ;
}
V_11 = F_8 ( V_2 ) | V_31 ;
F_9 ( V_2 , V_11 ) ;
return 0 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_59 = F_1 ( V_2 , V_68 ) ;
V_59 |= V_69 ;
F_3 ( V_2 , V_68 , V_59 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_59 = F_1 ( V_2 , V_68 ) ;
F_45 ( ! ( V_59 & V_69 ) , L_8 ) ;
V_59 |= V_70 ;
F_3 ( V_2 , V_68 , V_59 ) ;
}
int F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_71 = F_28 ( V_72 ) ;
int V_19 ;
V_7 -> V_73 = V_74 ;
V_19 = F_47 ( V_7 , V_75 ) ;
if ( V_19 )
return V_19 ;
F_26 ( & V_7 -> V_38 ) ;
F_27 ( V_7 -> V_76 ,
V_7 -> V_73 == V_77 , V_71 ) ;
F_29 ( & V_7 -> V_38 ) ;
if ( V_7 -> V_73 == V_77 ) {
F_43 ( V_7 ) ;
V_19 = 0 ;
} else {
V_19 = - V_41 ;
}
V_7 -> V_73 = V_78 ;
V_2 -> V_27 = V_79 ;
return V_19 ;
}
int F_48 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_71 = F_28 ( V_72 ) ;
int V_19 ;
if ( V_7 -> V_73 == V_77 )
goto V_80;
V_7 -> V_73 = V_74 ;
F_44 ( V_7 ) ;
F_26 ( & V_7 -> V_38 ) ;
F_27 ( V_7 -> V_76 ,
V_7 -> V_73 == V_77 , V_71 ) ;
F_29 ( & V_7 -> V_38 ) ;
V_80:
if ( V_7 -> V_73 == V_77 )
V_19 = F_47 ( V_7 , V_81 ) ;
else
V_19 = - V_41 ;
V_7 -> V_73 = V_78 ;
V_2 -> V_27 = V_28 ;
return V_19 ;
}
static bool F_49 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_59 = F_1 ( V_2 , V_9 ) ;
if ( ( V_59 & V_82 ) == 0 )
goto V_83;
if ( ! V_7 -> V_84 )
goto V_83;
return true ;
V_83:
F_32 ( V_7 -> V_7 , L_9 ,
! ! ( V_59 & V_82 ) ,
V_7 -> V_85 . V_86 ,
V_7 -> V_85 . V_87 ,
V_88 ,
V_89 ) ;
return false ;
}
T_3 F_50 ( int V_90 , void * V_91 )
{
struct V_6 * V_7 = (struct V_6 * ) V_91 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_92 = F_8 ( V_2 ) ;
if ( ( V_92 & V_12 ) != V_12 )
return V_93 ;
F_3 ( V_2 , V_10 , V_92 ) ;
return V_94 ;
}
T_3 F_51 ( int V_90 , void * V_91 )
{
struct V_6 * V_7 = (struct V_6 * ) V_91 ;
struct V_95 V_96 ;
T_4 V_97 ;
int V_98 = 0 ;
F_32 ( V_7 -> V_7 , L_10 ) ;
F_29 ( & V_7 -> V_38 ) ;
F_52 ( & V_96 ) ;
if ( F_53 ( F_11 ( V_7 -> V_7 ) ) )
F_54 ( V_7 ) ;
if ( ! F_55 ( V_7 ) && V_7 -> V_99 != V_100 ) {
F_21 ( V_7 -> V_7 , L_11 ) ;
F_56 ( & V_7 -> V_101 ) ;
goto V_102;
}
if ( ! F_57 ( V_7 ) ) {
if ( F_55 ( V_7 ) ) {
F_32 ( V_7 -> V_7 , L_12 ) ;
V_7 -> V_34 = true ;
F_58 ( & V_7 -> V_39 ) ;
} else {
F_32 ( V_7 -> V_7 , L_13 ) ;
}
goto V_102;
}
V_97 = F_59 ( V_7 ) ;
while ( V_97 > 0 ) {
F_32 ( V_7 -> V_7 , L_14 , V_97 ) ;
V_98 = F_60 ( V_7 , & V_96 , & V_97 ) ;
if ( V_98 == - V_103 )
break;
if ( V_98 && V_7 -> V_99 != V_100 ) {
F_30 ( V_7 -> V_7 , L_15 ,
V_98 ) ;
F_56 ( & V_7 -> V_101 ) ;
goto V_102;
}
}
V_7 -> V_104 = F_61 ( V_7 ) ;
if ( V_7 -> V_73 == V_78 ) {
V_98 = F_62 ( V_7 , & V_96 ) ;
V_7 -> V_104 = F_61 ( V_7 ) ;
}
F_63 ( V_7 , & V_96 ) ;
V_102:
F_32 ( V_7 -> V_7 , L_16 , V_98 ) ;
F_26 ( & V_7 -> V_38 ) ;
return V_105 ;
}
static bool F_64 ( struct V_15 * V_16 )
{
T_1 V_59 ;
F_12 ( V_16 , V_106 , & V_59 ) ;
return ( V_59 & 0x600 ) == 0x200 ;
}
static bool F_65 ( struct V_15 * V_16 )
{
T_1 V_59 ;
F_12 ( V_16 , V_107 , & V_59 ) ;
return ( V_59 & 0xf0000 ) == 0xf0000 ;
}
struct V_6 * F_66 ( struct V_15 * V_16 ,
const struct V_108 * V_18 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_7 = F_67 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_109 ) ;
if ( ! V_7 )
return NULL ;
V_2 = F_6 ( V_7 ) ;
F_68 ( V_7 , & V_16 -> V_7 , & V_110 ) ;
V_2 -> V_18 = V_18 ;
return V_7 ;
}
