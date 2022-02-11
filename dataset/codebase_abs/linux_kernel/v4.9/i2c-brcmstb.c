static inline int F_1 ( struct V_1 * V_2 )
{
return ( V_3 * V_2 -> V_4 ) ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_4 ;
}
static void F_3 ( struct V_1 * V_2 ,
bool V_5 )
{
if ( V_5 )
V_2 -> V_6 -> V_7 |= V_8 ;
else
V_2 -> V_6 -> V_7 &= ~ V_8 ;
F_4 () ;
F_5 ( V_2 , V_2 -> V_6 -> V_7 , V_7 ) ;
}
static T_1 F_6 ( int V_9 , void * V_10 )
{
struct V_1 * V_2 = V_10 ;
T_2 V_11 = F_7 ( V_2 , V_7 ) ;
T_2 V_12 = F_7 ( V_2 , V_13 ) ;
F_8 ( V_2 -> V_14 , L_1 ,
V_11 , V_12 ) ;
if ( ! ( V_11 & V_8 ) )
return V_15 ;
F_3 ( V_2 , V_16 ) ;
F_9 ( & V_2 -> V_17 ) ;
F_8 ( V_2 -> V_14 , L_2 ) ;
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned long V_19 = V_20 + F_11 ( V_21 ) ;
while ( ( F_7 ( V_2 , V_13 ) & V_22 ) ) {
if ( F_12 ( V_20 , V_19 ) )
return - V_23 ;
F_13 () ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
unsigned long V_19 = F_11 ( V_21 ) ;
if ( V_2 -> V_9 >= 0 ) {
if ( ! F_15 ( & V_2 -> V_17 , V_19 ) )
V_24 = - V_23 ;
} else {
T_2 V_25 ;
unsigned long V_26 = V_20 + V_19 ;
do {
V_25 = F_7 ( V_2 , V_13 ) &
V_22 ;
if ( F_12 ( V_20 , V_26 ) ) {
V_24 = - V_23 ;
break;
}
F_13 () ;
} while ( ! V_25 );
}
if ( V_2 -> V_9 < 0 || V_24 == - V_23 )
F_3 ( V_2 , V_16 ) ;
return V_24 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_2 V_27 )
{
T_2 V_28 = V_2 -> V_6 -> V_13 ;
V_2 -> V_6 -> V_13 = ( V_28 & ~ V_29 ) | V_27 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_30 V_31 )
{
int V_32 = 0 ;
struct V_33 * V_34 = V_2 -> V_6 ;
V_32 = F_10 ( V_2 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_2 -> V_9 >= 0 )
F_18 ( & V_2 -> V_17 ) ;
F_3 ( V_2 , V_35 ) ;
V_34 -> V_13 |= V_36 ;
F_5 ( V_2 , V_34 -> V_13 , V_13 ) ;
V_32 = F_14 ( V_2 ) ;
if ( V_32 ) {
F_8 ( V_2 -> V_14 , L_3 ,
V_37 [ V_31 ] ) ;
goto V_38;
}
if ( ( V_39 || V_40 ) &&
F_7 ( V_2 , V_13 ) & V_41 ) {
V_32 = - V_42 ;
F_8 ( V_2 -> V_14 , L_4 ,
V_37 [ V_31 ] ) ;
}
V_38:
F_5 ( V_2 , 0 , V_43 ) ;
F_5 ( V_2 , 0 , V_13 ) ;
return V_32 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_3 * V_44 , unsigned int V_45 ,
struct V_46 * V_47 )
{
int V_48 , V_49 , V_50 , V_32 ;
enum V_30 V_31 ;
T_2 V_7 ;
struct V_33 * V_34 = V_2 -> V_6 ;
int V_51 = V_47 -> V_52 & V_53 ;
int V_4 = F_2 ( V_2 ) ;
if ( V_51 ) {
V_31 = ( V_47 -> V_52 & V_54 ) ? V_55
: V_56 ;
V_34 -> V_57 |= V_58 ;
} else {
V_31 = ( V_47 -> V_52 & V_54 ) ? V_39 : V_40 ;
V_34 -> V_57 &= ~ V_58 ;
}
F_5 ( V_2 , V_34 -> V_57 , V_57 ) ;
V_7 = V_34 -> V_7 & ~ V_59 ;
if ( V_31 == V_40 || V_31 == V_56 )
V_34 -> V_7 = V_7 | V_60 ;
else
V_34 -> V_7 = V_7 | V_61 ;
F_5 ( V_2 , F_20 ( V_4 ) &
( V_45 << V_62 ) , V_43 ) ;
if ( V_31 == V_40 || V_31 == V_56 ) {
for ( V_48 = 0 , V_50 = 0 ; V_48 < V_45 ; V_48 += V_4 , V_50 ++ ) {
T_2 V_63 = 0 ;
for ( V_49 = 0 ; V_49 < V_4 ; V_49 ++ ) {
V_63 >>= V_64 ;
if ( ( V_48 + V_49 ) < V_45 )
V_63 |= V_44 [ V_48 + V_49 ] <<
( V_64 * ( V_4 - 1 ) ) ;
}
F_5 ( V_2 , V_63 , V_65 [ V_50 ] ) ;
}
}
V_32 = F_17 ( V_2 , V_31 ) ;
if ( V_32 != 0 ) {
F_8 ( V_2 -> V_14 , L_5 , V_37 [ V_31 ] ) ;
return V_32 ;
}
if ( V_31 == V_39 || V_31 == V_55 ) {
for ( V_48 = 0 , V_50 = 0 ; V_48 < V_45 ; V_48 += V_4 , V_50 ++ ) {
T_2 V_66 = F_7 ( V_2 , V_67 [ V_50 ] ) ;
for ( V_49 = 0 ; V_49 < V_4 &&
( V_49 + V_48 ) < V_45 ; V_49 ++ ) {
V_44 [ V_48 + V_49 ] = V_66 & 0xff ;
V_66 >>= V_64 ;
}
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 * V_44 , unsigned int V_68 )
{
enum V_30 V_31 = V_68 ? V_40 : V_56 ;
F_5 ( V_2 , 1 , V_43 ) ;
F_5 ( V_2 , * V_44 , V_65 ) ;
return F_17 ( V_2 , V_31 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_46 * V_69 )
{
unsigned char V_70 ;
if ( V_69 -> V_52 & V_71 ) {
V_70 = 0xF0 | ( ( V_69 -> V_70 & 0x300 ) >> 7 ) ;
F_5 ( V_2 , V_70 , V_72 ) ;
V_70 = V_69 -> V_70 & 0xFF ;
if ( F_21 ( V_2 , & V_70 , 0 ) < 0 )
return - V_42 ;
if ( V_69 -> V_52 & V_54 ) {
F_16 ( V_2 , V_73
| V_74 ) ;
V_70 = 0xF0 | ( ( V_69 -> V_70 & 0x300 ) >> 7 ) | 0x01 ;
if ( F_21 ( V_2 , & V_70 , 0 ) < 0 )
return - V_42 ;
}
} else {
V_70 = F_23 ( V_69 ) ;
F_5 ( V_2 , V_70 , V_72 ) ;
}
return 0 ;
}
static int F_24 ( struct V_75 * V_76 ,
struct V_46 V_77 [] , int V_78 )
{
struct V_1 * V_2 = F_25 ( V_76 ) ;
struct V_46 * V_47 ;
int V_32 = 0 ;
int V_50 ;
int V_79 ;
T_3 * V_80 ;
int V_45 = 0 ;
int V_81 = F_1 ( V_2 ) ;
if ( V_2 -> V_82 )
return - V_83 ;
for ( V_50 = 0 ; V_50 < V_78 ; V_50 ++ ) {
V_47 = & V_77 [ V_50 ] ;
V_45 = V_47 -> V_45 ;
V_80 = V_47 -> V_44 ;
F_8 ( V_2 -> V_14 ,
L_6 , V_50 ,
V_78 - 1 , V_47 -> V_52 ,
V_47 -> V_44 ? V_47 -> V_44 [ 0 ] : '0' , V_47 -> V_45 ) ;
if ( V_50 < ( V_78 - 1 ) && ( V_77 [ V_50 + 1 ] . V_52 & V_84 ) )
F_16 ( V_2 , ~ ( V_29 ) ) ;
else
F_16 ( V_2 ,
V_73 | V_74 ) ;
if ( ! ( V_47 -> V_52 & V_84 ) ) {
V_32 = F_22 ( V_2 , V_47 ) ;
if ( V_32 < 0 ) {
F_8 ( V_2 -> V_14 ,
L_7 ,
V_47 -> V_70 , V_50 , V_32 ) ;
goto V_85;
}
}
while ( V_45 ) {
V_79 = F_26 ( V_45 , V_81 ) ;
if ( V_45 <= V_81 && V_50 == ( V_78 - 1 ) )
F_16 ( V_2 ,
~ ( V_29 ) ) ;
V_32 = F_19 ( V_2 , V_80 ,
V_79 , V_47 ) ;
if ( V_32 < 0 )
goto V_85;
V_45 -= V_79 ;
V_80 += V_79 ;
}
}
V_32 = V_78 ;
V_85:
return V_32 ;
}
static T_2 F_27 ( struct V_75 * V_86 )
{
return V_87 | V_88 | V_89
| V_90 | V_91 ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_50 = 0 , V_92 = F_29 ( V_93 ) ;
T_2 V_94 = V_2 -> V_94 ;
for ( V_50 = 0 ; V_50 < V_92 ; V_50 ++ ) {
if ( V_93 [ V_50 ] . V_95 == V_94 ) {
V_2 -> V_6 -> V_7 &= ~ ( V_96
| V_97 ) ;
V_2 -> V_6 -> V_7 |= ( V_93 [ V_50 ] . V_98 |
V_93 [ V_50 ] . V_99 ) ;
F_5 ( V_2 , V_2 -> V_6 -> V_7 , V_7 ) ;
break;
}
}
if ( V_50 == V_92 ) {
V_50 = ( F_7 ( V_2 , V_7 ) & V_96 ) >>
V_100 ;
F_30 ( V_2 -> V_14 , L_8 ,
V_93 [ V_50 ] . V_95 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) == sizeof( T_2 ) )
V_2 -> V_6 -> V_57 = V_101 ;
else
V_2 -> V_6 -> V_57 &= ~ V_101 ;
F_5 ( V_2 , V_2 -> V_6 -> V_57 , V_57 ) ;
F_28 ( V_2 ) ;
}
static int F_32 ( struct V_102 * V_103 )
{
int V_32 = 0 ;
struct V_1 * V_2 ;
struct V_75 * V_86 ;
struct V_104 * V_105 ;
const char * V_106 ;
V_2 = F_33 ( & V_103 -> V_2 , sizeof( * V_2 ) , V_107 ) ;
if ( ! V_2 )
return - V_108 ;
V_2 -> V_6 = F_33 ( & V_103 -> V_2 , sizeof( * V_2 -> V_6 ) , V_107 ) ;
if ( ! V_2 -> V_6 )
return - V_108 ;
F_34 ( V_103 , V_2 ) ;
V_2 -> V_14 = & V_103 -> V_2 ;
F_35 ( & V_2 -> V_17 ) ;
V_105 = F_36 ( V_103 , V_109 , 0 ) ;
V_2 -> V_110 = F_37 ( V_2 -> V_14 , V_105 ) ;
if ( F_38 ( V_2 -> V_110 ) ) {
V_32 = - V_108 ;
goto V_111;
}
V_32 = F_39 ( V_2 -> V_14 -> V_112 , L_9 ,
& V_106 ) ;
if ( V_32 < 0 )
V_106 = NULL ;
V_2 -> V_9 = F_40 ( V_103 , 0 ) ;
F_3 ( V_2 , V_16 ) ;
V_32 = F_41 ( & V_103 -> V_2 , V_2 -> V_9 , F_6 ,
V_113 ,
V_106 ? V_106 : V_103 -> V_114 ,
V_2 ) ;
if ( V_32 ) {
F_8 ( V_2 -> V_14 , L_10 ) ;
V_2 -> V_9 = - 1 ;
}
if ( F_42 ( V_2 -> V_14 -> V_112 ,
L_11 , & V_2 -> V_94 ) ) {
F_30 ( V_2 -> V_14 , L_12 ,
V_93 [ 0 ] . V_95 ) ;
V_2 -> V_94 = V_93 [ 0 ] . V_95 ;
}
if ( F_43 ( V_2 -> V_14 -> V_112 ,
L_13 ) )
V_2 -> V_4 = sizeof( T_3 ) ;
else
V_2 -> V_4 = sizeof( T_2 ) ;
F_31 ( V_2 ) ;
V_86 = & V_2 -> V_76 ;
F_44 ( V_86 , V_2 ) ;
V_86 -> V_115 = V_116 ;
F_45 ( V_86 -> V_114 , L_14 , sizeof( V_86 -> V_114 ) ) ;
if ( V_106 )
F_46 ( V_86 -> V_114 , V_106 , sizeof( V_86 -> V_114 ) ) ;
V_86 -> V_117 = & V_118 ;
V_86 -> V_2 . V_119 = & V_103 -> V_2 ;
V_86 -> V_2 . V_112 = V_103 -> V_2 . V_112 ;
V_32 = F_47 ( V_86 ) ;
if ( V_32 )
goto V_111;
F_48 ( V_2 -> V_14 , L_15 ,
V_106 ? V_106 : L_16 , V_2 -> V_94 ,
( V_2 -> V_9 >= 0 ) ? L_17 : L_18 ) ;
return 0 ;
V_111:
return V_32 ;
}
static int F_49 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_50 ( V_103 ) ;
F_51 ( & V_2 -> V_76 ) ;
return 0 ;
}
static int F_52 ( struct V_14 * V_2 )
{
struct V_1 * V_120 = F_53 ( V_2 ) ;
F_54 ( & V_120 -> V_76 ) ;
V_120 -> V_82 = true ;
F_55 ( & V_120 -> V_76 ) ;
return 0 ;
}
static int F_56 ( struct V_14 * V_2 )
{
struct V_1 * V_120 = F_53 ( V_2 ) ;
F_54 ( & V_120 -> V_76 ) ;
F_31 ( V_120 ) ;
V_120 -> V_82 = false ;
F_55 ( & V_120 -> V_76 ) ;
return 0 ;
}
