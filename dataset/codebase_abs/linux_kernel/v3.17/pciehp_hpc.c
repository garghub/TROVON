static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
static void F_2 ( unsigned long V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 ;
F_3 ( 0 , V_3 ) ;
F_4 ( & V_3 -> V_7 ) ;
if ( ! V_8 )
V_8 = 2 ;
F_5 ( V_3 , V_8 ) ;
}
static void F_5 ( struct V_2 * V_3 , int V_9 )
{
if ( ( V_9 <= 0 ) || ( V_9 > 60 ) )
V_9 = 2 ;
V_3 -> V_7 . V_10 = & F_2 ;
V_3 -> V_7 . V_6 = ( unsigned long ) V_3 ;
V_3 -> V_7 . V_11 = V_12 + V_9 * V_13 ;
F_6 ( & V_3 -> V_7 ) ;
}
static inline int F_7 ( struct V_2 * V_3 )
{
int V_14 , V_15 = V_3 -> V_4 -> V_15 ;
if ( V_16 ) {
F_4 ( & V_3 -> V_7 ) ;
F_5 ( V_3 , 10 ) ;
return 0 ;
}
V_14 = F_8 ( V_15 , F_3 , V_17 , V_18 , V_3 ) ;
if ( V_14 )
F_9 ( V_3 , L_1 ,
V_15 ) ;
return V_14 ;
}
static inline void F_10 ( struct V_2 * V_3 )
{
if ( V_16 )
F_11 ( & V_3 -> V_7 ) ;
else
F_12 ( V_3 -> V_4 -> V_15 , V_3 ) ;
}
static int F_13 ( struct V_2 * V_3 , int V_19 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 & V_23 ) {
F_15 ( V_20 , V_22 ,
V_23 ) ;
return 1 ;
}
while ( V_19 > 0 ) {
F_16 ( 10 ) ;
V_19 -= 10 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 & V_23 ) {
F_15 ( V_20 , V_22 ,
V_23 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_17 ( struct V_2 * V_3 )
{
unsigned int V_24 = V_16 ? 2500 : 1000 ;
unsigned long V_25 = F_18 ( V_24 ) ;
unsigned long V_26 = V_3 -> V_27 + V_25 ;
unsigned long V_28 , V_19 ;
int V_29 ;
if ( F_19 ( V_3 ) )
return;
if ( ! V_3 -> V_30 )
return;
V_28 = V_12 ;
if ( F_20 ( V_26 , V_28 ) )
V_19 = 1 ;
else
V_19 = V_26 - V_28 ;
if ( V_3 -> V_31 & V_32 &&
V_3 -> V_31 & V_33 )
V_29 = F_21 ( V_3 -> V_34 , ! V_3 -> V_30 , V_19 ) ;
else
V_29 = F_13 ( V_3 , F_22 ( V_19 ) ) ;
if ( ! V_29 )
F_23 ( V_3 , L_2 ,
V_3 -> V_31 ,
F_22 ( V_28 - V_3 -> V_27 ) ) ;
}
static void F_24 ( struct V_2 * V_3 , T_1 V_35 , T_1 V_36 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_25 ( & V_3 -> V_37 ) ;
F_17 ( V_3 ) ;
F_14 ( V_20 , V_38 , & V_31 ) ;
V_31 &= ~ V_36 ;
V_31 |= ( V_35 & V_36 ) ;
V_3 -> V_30 = 1 ;
F_26 () ;
F_15 ( V_20 , V_38 , V_31 ) ;
V_3 -> V_27 = V_12 ;
V_3 -> V_31 = V_31 ;
F_27 ( & V_3 -> V_37 ) ;
}
bool F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_39 ;
bool V_40 ;
F_14 ( V_20 , V_41 , & V_39 ) ;
V_40 = ! ! ( V_39 & V_42 ) ;
if ( V_40 )
F_29 ( V_3 , L_3 , V_43 , V_39 ) ;
return V_40 ;
}
static void F_30 ( struct V_2 * V_3 , bool V_44 )
{
int V_19 = 1000 ;
if ( F_28 ( V_3 ) == V_44 )
return;
while ( V_19 > 0 ) {
F_16 ( 10 ) ;
V_19 -= 10 ;
if ( F_28 ( V_3 ) == V_44 )
return;
}
F_29 ( V_3 , L_4 ,
V_44 ? L_5 : L_6 ) ;
}
static void F_31 ( struct V_2 * V_3 )
{
F_30 ( V_3 , true ) ;
}
static bool F_32 ( struct V_45 * V_46 , int V_47 )
{
T_2 V_48 ;
int V_49 = 0 ;
int V_50 = 1000 , V_51 = 20 ;
bool V_52 = false ;
do {
V_52 = F_33 ( V_46 , V_47 , & V_48 , 0 ) ;
V_49 ++ ;
if ( V_52 )
break;
F_16 ( V_51 ) ;
V_50 -= V_51 ;
} while ( V_50 > 0 );
if ( V_49 > 1 && V_53 )
F_34 ( V_54 L_7 ,
F_35 ( V_46 ) , V_46 -> V_55 , F_36 ( V_47 ) ,
F_37 ( V_47 ) , V_49 , V_51 , V_48 ) ;
return V_52 ;
}
int F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
bool V_52 ;
T_1 V_39 ;
if ( V_3 -> V_56 )
F_31 ( V_3 ) ;
else
F_16 ( 1000 ) ;
F_16 ( 100 ) ;
V_52 = F_32 ( V_3 -> V_4 -> V_5 -> V_57 ,
F_39 ( 0 , 0 ) ) ;
F_14 ( V_20 , V_41 , & V_39 ) ;
F_29 ( V_3 , L_3 , V_43 , V_39 ) ;
if ( ( V_39 & V_58 ) ||
! ( V_39 & V_59 ) ) {
F_9 ( V_3 , L_8 ) ;
return - 1 ;
}
F_40 ( V_3 -> V_4 -> V_5 -> V_57 , V_39 ) ;
if ( ! V_52 )
return - 1 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , bool V_60 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_61 ;
F_14 ( V_20 , V_62 , & V_61 ) ;
if ( V_60 )
V_61 &= ~ V_63 ;
else
V_61 |= V_63 ;
F_15 ( V_20 , V_62 , V_61 ) ;
F_29 ( V_3 , L_9 , V_43 , V_61 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 )
{
return F_41 ( V_3 , true ) ;
}
void F_43 ( struct V_64 * V_64 , T_3 * V_65 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_14 ( V_20 , V_38 , & V_31 ) ;
F_29 ( V_3 , L_10 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 , V_31 ) ;
switch ( V_31 & V_66 ) {
case V_67 :
* V_65 = 1 ;
break;
case V_68 :
* V_65 = 2 ;
break;
case V_69 :
* V_65 = 0 ;
break;
default:
* V_65 = 0xFF ;
break;
}
}
void F_45 ( struct V_64 * V_64 , T_3 * V_65 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_14 ( V_20 , V_38 , & V_31 ) ;
F_29 ( V_3 , L_11 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 , V_31 ) ;
switch ( V_31 & V_70 ) {
case V_71 :
* V_65 = 1 ;
break;
case V_72 :
* V_65 = 0 ;
break;
default:
* V_65 = 0xFF ;
break;
}
}
void F_46 ( struct V_64 * V_64 , T_3 * V_65 )
{
struct V_1 * V_20 = F_1 ( V_64 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
* V_65 = ! ! ( V_21 & V_73 ) ;
}
void F_47 ( struct V_64 * V_64 , T_3 * V_65 )
{
struct V_1 * V_20 = F_1 ( V_64 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
* V_65 = ! ! ( V_21 & V_74 ) ;
}
int F_48 ( struct V_64 * V_64 )
{
struct V_1 * V_20 = F_1 ( V_64 -> V_3 ) ;
T_1 V_21 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
return ! ! ( V_21 & V_75 ) ;
}
void F_49 ( struct V_64 * V_64 , T_3 V_76 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
T_1 V_77 ;
if ( ! F_50 ( V_3 ) )
return;
switch ( V_76 ) {
case 0 :
V_77 = V_69 ;
break;
case 1 :
V_77 = V_67 ;
break;
case 2 :
V_77 = V_68 ;
break;
default:
return;
}
F_29 ( V_3 , L_12 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 , V_77 ) ;
F_24 ( V_3 , V_77 , V_66 ) ;
}
void F_51 ( struct V_64 * V_64 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
if ( ! F_52 ( V_3 ) )
return;
F_24 ( V_3 , V_78 , V_79 ) ;
F_29 ( V_3 , L_12 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 ,
V_78 ) ;
}
void F_53 ( struct V_64 * V_64 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
if ( ! F_52 ( V_3 ) )
return;
F_24 ( V_3 , V_80 , V_79 ) ;
F_29 ( V_3 , L_12 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 ,
V_80 ) ;
}
void F_54 ( struct V_64 * V_64 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
if ( ! F_52 ( V_3 ) )
return;
F_24 ( V_3 , V_81 , V_79 ) ;
F_29 ( V_3 , L_12 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 ,
V_81 ) ;
}
int F_55 ( struct V_64 * V_64 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_21 ;
int V_14 ;
F_14 ( V_20 , V_22 , & V_21 ) ;
if ( V_21 & V_75 )
F_15 ( V_20 , V_22 ,
V_75 ) ;
V_3 -> V_82 = 0 ;
F_24 ( V_3 , V_71 , V_70 ) ;
F_29 ( V_3 , L_12 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 ,
V_71 ) ;
V_14 = F_42 ( V_3 ) ;
if ( V_14 )
F_9 ( V_3 , L_13 , V_43 ) ;
return V_14 ;
}
void F_56 ( struct V_64 * V_64 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
F_24 ( V_3 , V_72 , V_70 ) ;
F_29 ( V_3 , L_12 , V_43 ,
F_44 ( V_3 -> V_4 -> V_5 ) + V_38 ,
V_72 ) ;
}
static T_4 F_3 ( int V_15 , void * V_83 )
{
struct V_2 * V_3 = (struct V_2 * ) V_83 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_45 * V_57 = V_20 -> V_57 ;
struct V_1 * V_84 ;
struct V_64 * V_64 = V_3 -> V_64 ;
T_1 V_85 , V_86 ;
V_86 = 0 ;
do {
F_14 ( V_20 , V_22 , & V_85 ) ;
V_85 &= ( V_87 | V_75 |
V_88 | V_89 |
V_23 | V_90 ) ;
V_85 &= ~ V_86 ;
V_86 |= V_85 ;
if ( ! V_86 )
return V_91 ;
if ( V_85 )
F_15 ( V_20 , V_22 ,
V_86 ) ;
} while ( V_85 );
F_29 ( V_3 , L_14 , V_43 , V_86 ) ;
if ( V_86 & V_23 ) {
V_3 -> V_30 = 0 ;
F_26 () ;
F_57 ( & V_3 -> V_34 ) ;
}
if ( V_57 ) {
F_58 (dev, &subordinate->devices, bus_list) {
if ( V_84 -> V_92 ) {
F_29 ( V_3 , L_15 ,
V_86 , F_59 ( V_84 ) ) ;
return V_93 ;
}
}
}
if ( ! ( V_86 & ~ V_23 ) )
return V_93 ;
if ( V_86 & V_88 )
F_60 ( V_64 ) ;
if ( V_86 & V_87 )
F_61 ( V_64 ) ;
if ( V_86 & V_89 )
F_62 ( V_64 ) ;
if ( ( V_86 & V_75 ) && ! V_3 -> V_82 ) {
V_3 -> V_82 = 1 ;
F_63 ( V_64 ) ;
}
if ( V_86 & V_90 )
F_64 ( V_64 ) ;
return V_93 ;
}
void F_65 ( struct V_2 * V_3 )
{
T_1 V_35 , V_36 ;
V_35 = V_94 ;
if ( F_66 ( V_3 ) )
V_35 |= V_95 ;
else
V_35 |= V_96 ;
if ( F_67 ( V_3 ) )
V_35 |= V_97 ;
if ( ! V_16 )
V_35 |= V_32 | V_33 ;
V_36 = ( V_96 | V_95 |
V_97 | V_98 |
V_32 | V_33 |
V_94 ) ;
F_24 ( V_3 , V_35 , V_36 ) ;
}
static void F_68 ( struct V_2 * V_3 )
{
T_1 V_36 ;
V_36 = ( V_96 | V_95 |
V_97 | V_98 |
V_32 | V_33 |
V_94 ) ;
F_24 ( V_3 , 0 , V_36 ) ;
}
int F_69 ( struct V_64 * V_64 , int V_99 )
{
struct V_2 * V_3 = V_64 -> V_3 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
T_1 V_100 = 0 , V_101 = 0 ;
if ( V_99 )
return 0 ;
if ( ! F_66 ( V_3 ) ) {
V_101 |= V_96 ;
V_100 |= V_89 ;
}
V_101 |= V_94 ;
V_100 |= V_90 ;
F_24 ( V_3 , 0 , V_101 ) ;
if ( V_16 )
F_11 ( & V_3 -> V_7 ) ;
F_70 ( V_3 -> V_4 -> V_5 ) ;
F_15 ( V_20 , V_22 , V_100 ) ;
F_24 ( V_3 , V_101 , V_101 ) ;
if ( V_16 )
F_2 ( V_3 -> V_7 . V_6 ) ;
return 0 ;
}
int F_71 ( struct V_2 * V_3 )
{
if ( F_7 ( V_3 ) )
return - 1 ;
F_65 ( V_3 ) ;
V_3 -> V_102 = 1 ;
return 0 ;
}
static void F_72 ( struct V_2 * V_3 )
{
if ( V_3 -> V_102 ) {
F_68 ( V_3 ) ;
F_10 ( V_3 ) ;
V_3 -> V_102 = 0 ;
}
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_64 * V_64 ;
V_64 = F_74 ( sizeof( * V_64 ) , V_103 ) ;
if ( ! V_64 )
return - V_104 ;
V_64 -> V_105 = F_75 ( L_16 , 0 , 0 , F_76 ( V_3 ) ) ;
if ( ! V_64 -> V_105 )
goto abort;
V_64 -> V_3 = V_3 ;
F_77 ( & V_64 -> V_106 ) ;
F_77 ( & V_64 -> V_107 ) ;
F_78 ( & V_64 -> V_108 , V_109 ) ;
V_3 -> V_64 = V_64 ;
return 0 ;
abort:
F_79 ( V_64 ) ;
return - V_104 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_64 * V_64 = V_3 -> V_64 ;
F_81 ( & V_64 -> V_108 ) ;
F_82 ( V_64 -> V_105 ) ;
F_79 ( V_64 ) ;
}
static inline void F_83 ( struct V_2 * V_3 )
{
int V_110 ;
T_1 V_111 ;
struct V_1 * V_20 = V_3 -> V_4 -> V_5 ;
if ( ! V_53 )
return;
F_23 ( V_3 , L_17 ) ;
F_23 ( V_3 , L_18 ,
F_59 ( V_20 ) , V_20 -> V_15 ) ;
F_23 ( V_3 , L_19 , V_20 -> V_112 ) ;
F_23 ( V_3 , L_20 , V_20 -> V_113 ) ;
F_23 ( V_3 , L_21 ,
V_20 -> V_114 ) ;
F_23 ( V_3 , L_22 ,
V_20 -> V_115 ) ;
F_23 ( V_3 , L_23 ,
F_44 ( V_20 ) ) ;
for ( V_110 = 0 ; V_110 < V_116 ; V_110 ++ ) {
if ( ! F_84 ( V_20 , V_110 ) )
continue;
F_23 ( V_3 , L_24 ,
V_110 , & V_20 -> V_117 [ V_110 ] ) ;
}
F_23 ( V_3 , L_25 , V_3 -> V_118 ) ;
F_23 ( V_3 , L_26 , F_76 ( V_3 ) ) ;
F_23 ( V_3 , L_27 ,
F_66 ( V_3 ) ? L_28 : L_29 ) ;
F_23 ( V_3 , L_30 ,
F_85 ( V_3 ) ? L_28 : L_29 ) ;
F_23 ( V_3 , L_31 ,
F_67 ( V_3 ) ? L_28 : L_29 ) ;
F_23 ( V_3 , L_32 ,
F_50 ( V_3 ) ? L_28 : L_29 ) ;
F_23 ( V_3 , L_33 ,
F_52 ( V_3 ) ? L_28 : L_29 ) ;
F_23 ( V_3 , L_34 ,
F_86 ( V_3 ) ? L_28 : L_29 ) ;
F_23 ( V_3 , L_35 ,
F_87 ( V_3 ) ? L_28 : L_29 ) ;
F_23 ( V_3 , L_36 ,
F_19 ( V_3 ) ? L_29 : L_28 ) ;
F_14 ( V_20 , V_22 , & V_111 ) ;
F_23 ( V_3 , L_37 , V_111 ) ;
F_14 ( V_20 , V_38 , & V_111 ) ;
F_23 ( V_3 , L_38 , V_111 ) ;
}
struct V_2 * F_88 ( struct V_119 * V_84 )
{
struct V_2 * V_3 ;
T_2 V_118 , V_120 ;
struct V_1 * V_20 = V_84 -> V_5 ;
V_3 = F_74 ( sizeof( * V_3 ) , V_103 ) ;
if ( ! V_3 ) {
F_89 ( & V_84 -> V_113 , L_39 , V_43 ) ;
goto abort;
}
V_3 -> V_4 = V_84 ;
F_90 ( V_20 , V_121 , & V_118 ) ;
V_3 -> V_118 = V_118 ;
F_77 ( & V_3 -> V_37 ) ;
F_91 ( & V_3 -> V_34 ) ;
F_83 ( V_3 ) ;
F_90 ( V_20 , V_122 , & V_120 ) ;
if ( V_120 & V_123 ) {
F_29 ( V_3 , L_40 ) ;
V_3 -> V_56 = 1 ;
}
F_15 ( V_20 , V_22 ,
V_87 | V_75 |
V_88 | V_89 |
V_23 | V_90 ) ;
F_68 ( V_3 ) ;
F_23 ( V_3 , L_41 ,
( V_118 & V_124 ) >> 19 ,
F_92 ( V_118 , V_125 ) ,
F_92 ( V_118 , V_126 ) ,
F_92 ( V_118 , V_127 ) ,
F_92 ( V_118 , V_128 ) ,
F_92 ( V_118 , V_129 ) ,
F_92 ( V_118 , V_130 ) ,
F_92 ( V_118 , V_131 ) ,
F_92 ( V_120 , V_123 ) ) ;
if ( F_73 ( V_3 ) )
goto V_132;
return V_3 ;
V_132:
F_79 ( V_3 ) ;
abort:
return NULL ;
}
void F_93 ( struct V_2 * V_3 )
{
F_72 ( V_3 ) ;
F_80 ( V_3 ) ;
F_79 ( V_3 ) ;
}
