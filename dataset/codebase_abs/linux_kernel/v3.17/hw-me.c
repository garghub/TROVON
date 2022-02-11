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
static void F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( F_6 ( V_7 ) ) ;
V_7 -> V_13 = ( V_11 & V_14 ) >> 24 ;
V_2 -> V_15 = V_16 ;
}
static inline enum V_17 F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return V_2 -> V_15 ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
if ( ( V_11 & V_12 ) == V_12 )
F_3 ( V_2 , V_10 , V_11 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_18 ;
F_9 ( V_2 , V_11 ) ;
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 &= ~ V_18 ;
F_9 ( V_2 , V_11 ) ;
}
static void F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_19 ;
V_11 &= ~ V_20 ;
F_9 ( V_2 , V_11 ) ;
F_16 () ;
}
static int F_17 ( struct V_6 * V_7 , bool V_21 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_11 = F_8 ( V_2 ) ;
V_11 |= V_20 | V_19 | V_12 ;
if ( V_21 )
V_11 |= V_18 ;
else
V_11 &= ~ V_18 ;
V_7 -> V_22 = false ;
F_3 ( V_2 , V_10 , V_11 ) ;
V_11 = F_8 ( V_2 ) ;
if ( ( V_11 & V_20 ) == 0 )
F_18 ( & V_7 -> V_23 -> V_7 , L_1 , V_11 ) ;
if ( ( V_11 & V_24 ) == V_24 )
F_18 ( & V_7 -> V_23 -> V_7 , L_2 , V_11 ) ;
if ( V_21 == false )
F_15 ( V_7 ) ;
return 0 ;
}
static void F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_25 = F_8 ( V_2 ) ;
V_2 -> V_25 |= V_18 | V_19 | V_24 ;
F_9 ( V_2 , V_2 -> V_25 ) ;
}
static bool F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_25 = F_8 ( V_2 ) ;
return ( V_2 -> V_25 & V_24 ) == V_24 ;
}
static bool F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
V_2 -> V_26 = F_7 ( V_2 ) ;
return ( V_2 -> V_26 & V_27 ) == V_27 ;
}
static int F_22 ( struct V_6 * V_7 )
{
int V_28 ;
F_23 ( & V_7 -> V_29 ) ;
V_28 = F_24 ( V_7 -> V_30 ,
V_7 -> V_22 ,
F_25 ( V_31 ) ) ;
F_26 ( & V_7 -> V_29 ) ;
if ( ! V_28 && ! V_7 -> V_22 ) {
if ( ! V_28 )
V_28 = - V_32 ;
F_27 ( & V_7 -> V_23 -> V_7 ,
L_3 , V_28 ) ;
return V_28 ;
}
V_7 -> V_22 = false ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 )
{
int V_33 = F_22 ( V_7 ) ;
if ( V_33 )
return V_33 ;
F_29 ( & V_7 -> V_23 -> V_7 , L_4 ) ;
F_19 ( V_7 ) ;
return V_33 ;
}
static unsigned char F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_34 , V_35 ;
V_2 -> V_25 = F_8 ( V_2 ) ;
V_34 = ( char ) ( ( V_2 -> V_25 & V_36 ) >> 8 ) ;
V_35 = ( char ) ( ( V_2 -> V_25 & V_37 ) >> 16 ) ;
return ( unsigned char ) ( V_35 - V_34 ) ;
}
static bool F_31 ( struct V_6 * V_7 )
{
return F_30 ( V_7 ) == 0 ;
}
static int F_32 ( struct V_6 * V_7 )
{
unsigned char V_38 , V_39 ;
V_38 = F_30 ( V_7 ) ;
V_39 = V_7 -> V_13 - V_38 ;
if ( V_38 > V_7 -> V_13 )
return - V_40 ;
return V_39 ;
}
static T_2 F_33 ( const struct V_6 * V_7 )
{
return V_7 -> V_13 * sizeof( T_1 ) - sizeof( struct V_41 ) ;
}
static int F_34 ( struct V_6 * V_7 ,
struct V_41 * V_42 ,
unsigned char * V_43 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_44 ;
unsigned long V_45 = V_42 -> V_45 ;
T_1 * V_46 = ( T_1 * ) V_43 ;
T_1 V_11 ;
T_1 V_47 ;
int V_48 ;
int V_39 ;
F_29 ( & V_7 -> V_23 -> V_7 , V_49 , F_35 ( V_42 ) ) ;
V_39 = F_36 ( V_7 ) ;
F_29 ( & V_7 -> V_23 -> V_7 , L_5 , V_39 ) ;
V_47 = F_37 ( V_45 ) ;
if ( V_39 < 0 || V_47 > V_39 )
return - V_50 ;
F_3 ( V_2 , V_51 , * ( ( T_1 * ) V_42 ) ) ;
for ( V_48 = 0 ; V_48 < V_45 / 4 ; V_48 ++ )
F_3 ( V_2 , V_51 , V_46 [ V_48 ] ) ;
V_44 = V_45 & 0x3 ;
if ( V_44 > 0 ) {
T_1 V_52 = 0 ;
memcpy ( & V_52 , & V_43 [ V_45 - V_44 ] , V_44 ) ;
F_3 ( V_2 , V_51 , V_52 ) ;
}
V_11 = F_8 ( V_2 ) | V_19 ;
F_9 ( V_2 , V_11 ) ;
if ( ! F_21 ( V_7 ) )
return - V_53 ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
char V_34 , V_35 ;
unsigned char V_54 , V_38 ;
V_2 -> V_26 = F_7 ( V_2 ) ;
V_54 = ( unsigned char ) ( ( V_2 -> V_26 & V_55 ) >> 24 ) ;
V_34 = ( char ) ( ( V_2 -> V_26 & V_56 ) >> 8 ) ;
V_35 = ( char ) ( ( V_2 -> V_26 & V_57 ) >> 16 ) ;
V_38 = ( unsigned char ) ( V_35 - V_34 ) ;
if ( V_38 > V_54 )
return - V_40 ;
F_29 ( & V_7 -> V_23 -> V_7 , L_6 , V_38 ) ;
return ( int ) V_38 ;
}
static int F_39 ( struct V_6 * V_7 , unsigned char * V_58 ,
unsigned long V_59 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 * V_46 = ( T_1 * ) V_58 ;
T_1 V_11 ;
for (; V_59 >= sizeof( T_1 ) ; V_59 -= sizeof( T_1 ) )
* V_46 ++ = F_5 ( V_7 ) ;
if ( V_59 > 0 ) {
T_1 V_52 = F_5 ( V_7 ) ;
memcpy ( V_46 , & V_52 , V_59 ) ;
}
V_11 = F_8 ( V_2 ) | V_19 ;
F_9 ( V_2 , V_11 ) ;
return 0 ;
}
static void F_40 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_52 = F_1 ( V_2 , V_60 ) ;
V_52 |= V_61 ;
F_3 ( V_2 , V_60 , V_52 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_52 = F_1 ( V_2 , V_60 ) ;
F_42 ( ! ( V_52 & V_61 ) , L_7 ) ;
V_52 |= V_62 ;
F_3 ( V_2 , V_60 , V_52 ) ;
}
int F_43 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_63 = F_25 ( V_64 ) ;
int V_33 ;
V_7 -> V_65 = V_66 ;
V_33 = F_44 ( V_7 , V_67 ) ;
if ( V_33 )
return V_33 ;
F_23 ( & V_7 -> V_29 ) ;
F_45 ( V_7 -> V_68 ,
V_7 -> V_65 == V_69 , V_63 ) ;
F_26 ( & V_7 -> V_29 ) ;
if ( V_7 -> V_65 == V_69 ) {
F_40 ( V_7 ) ;
V_33 = 0 ;
} else {
V_33 = - V_32 ;
}
V_7 -> V_65 = V_70 ;
V_2 -> V_15 = V_71 ;
return V_33 ;
}
int F_46 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_63 = F_25 ( V_64 ) ;
int V_33 ;
if ( V_7 -> V_65 == V_69 )
goto V_72;
V_7 -> V_65 = V_66 ;
F_41 ( V_7 ) ;
F_23 ( & V_7 -> V_29 ) ;
F_45 ( V_7 -> V_68 ,
V_7 -> V_65 == V_69 , V_63 ) ;
F_26 ( & V_7 -> V_29 ) ;
V_72:
if ( V_7 -> V_65 == V_69 )
V_33 = F_44 ( V_7 , V_73 ) ;
else
V_33 = - V_32 ;
V_7 -> V_65 = V_70 ;
V_2 -> V_15 = V_16 ;
return V_33 ;
}
static bool F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_52 = F_1 ( V_2 , V_9 ) ;
if ( ( V_52 & V_74 ) == 0 )
goto V_75;
if ( V_7 -> V_76 . V_77 < V_78 )
goto V_75;
if ( V_7 -> V_76 . V_77 == V_78 &&
V_7 -> V_76 . V_79 < V_80 )
goto V_75;
return true ;
V_75:
F_29 ( & V_7 -> V_23 -> V_7 , L_8 ,
! ! ( V_52 & V_74 ) ,
V_7 -> V_76 . V_77 ,
V_7 -> V_76 . V_79 ,
V_78 ,
V_80 ) ;
return false ;
}
T_3 F_48 ( int V_81 , void * V_82 )
{
struct V_6 * V_7 = (struct V_6 * ) V_82 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_83 = F_8 ( V_2 ) ;
if ( ( V_83 & V_12 ) != V_12 )
return V_84 ;
F_3 ( V_2 , V_10 , V_83 ) ;
return V_85 ;
}
T_3 F_49 ( int V_81 , void * V_82 )
{
struct V_6 * V_7 = (struct V_6 * ) V_82 ;
struct V_86 V_87 ;
T_4 V_88 ;
int V_89 = 0 ;
F_29 ( & V_7 -> V_23 -> V_7 , L_9 ) ;
F_26 ( & V_7 -> V_29 ) ;
F_50 ( & V_87 ) ;
if ( F_51 ( V_7 -> V_23 ) )
F_52 ( V_7 ) ;
if ( ! F_53 ( V_7 ) && V_7 -> V_90 != V_91 ) {
F_18 ( & V_7 -> V_23 -> V_7 , L_10 ) ;
F_54 ( & V_7 -> V_92 ) ;
goto V_93;
}
if ( ! F_55 ( V_7 ) ) {
if ( F_53 ( V_7 ) ) {
F_15 ( V_7 ) ;
F_29 ( & V_7 -> V_23 -> V_7 , L_11 ) ;
V_7 -> V_22 = true ;
F_56 ( & V_7 -> V_30 ) ;
} else {
F_29 ( & V_7 -> V_23 -> V_7 , L_12 ) ;
}
goto V_93;
}
V_88 = F_57 ( V_7 ) ;
while ( V_88 > 0 ) {
F_29 ( & V_7 -> V_23 -> V_7 , L_13 , V_88 ) ;
V_89 = F_58 ( V_7 , & V_87 , & V_88 ) ;
if ( V_89 == - V_94 )
break;
if ( V_89 && V_7 -> V_90 != V_91 ) {
F_27 ( & V_7 -> V_23 -> V_7 , L_14 ,
V_89 ) ;
F_54 ( & V_7 -> V_92 ) ;
goto V_93;
}
}
V_7 -> V_95 = F_59 ( V_7 ) ;
if ( V_7 -> V_65 == V_70 ) {
V_89 = F_60 ( V_7 , & V_87 ) ;
V_7 -> V_95 = F_59 ( V_7 ) ;
}
F_61 ( V_7 , & V_87 ) ;
V_93:
F_29 ( & V_7 -> V_23 -> V_7 , L_15 , V_89 ) ;
F_23 ( & V_7 -> V_29 ) ;
return V_96 ;
}
static bool F_62 ( struct V_97 * V_23 )
{
T_1 V_52 ;
F_63 ( V_23 , V_98 , & V_52 ) ;
return ( V_52 & 0x600 ) == 0x200 ;
}
static bool F_64 ( struct V_97 * V_23 )
{
T_1 V_52 ;
F_63 ( V_23 , V_99 , & V_52 ) ;
return ( V_52 & 0xf0000 ) == 0xf0000 ;
}
struct V_6 * F_65 ( struct V_97 * V_23 ,
const struct V_100 * V_101 )
{
struct V_6 * V_7 ;
V_7 = F_66 ( sizeof( struct V_6 ) +
sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_7 )
return NULL ;
F_67 ( V_7 , V_101 ) ;
V_7 -> V_103 = & V_104 ;
V_7 -> V_23 = V_23 ;
return V_7 ;
}
