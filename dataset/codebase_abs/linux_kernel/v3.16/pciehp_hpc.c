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
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_20 ;
int V_21 = 1000 ;
F_14 ( V_19 , V_22 , & V_20 ) ;
if ( V_20 & V_23 ) {
F_15 ( V_19 , V_22 ,
V_23 ) ;
return 1 ;
}
while ( V_21 > 0 ) {
F_16 ( 10 ) ;
V_21 -= 10 ;
F_14 ( V_19 , V_22 , & V_20 ) ;
if ( V_20 & V_23 ) {
F_15 ( V_19 , V_22 ,
V_23 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , int V_24 )
{
unsigned int V_25 = V_16 ? 2500 : 1000 ;
unsigned long V_21 = F_18 ( V_25 ) ;
int V_26 ;
if ( V_24 )
V_26 = F_13 ( V_3 ) ;
else
V_26 = F_19 ( V_3 -> V_27 , ! V_3 -> V_28 , V_21 ) ;
if ( ! V_26 )
F_20 ( V_3 , L_2 ) ;
}
static void F_21 ( struct V_2 * V_3 , T_1 V_29 , T_1 V_30 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_20 ;
T_1 V_31 ;
F_22 ( & V_3 -> V_32 ) ;
F_14 ( V_19 , V_22 , & V_20 ) ;
if ( V_20 & V_23 ) {
F_15 ( V_19 , V_22 ,
V_23 ) ;
if ( ! V_3 -> V_33 ) {
F_20 ( V_3 , L_3 ) ;
} else if ( ! F_23 ( V_3 ) ) {
F_20 ( V_3 , L_4 ) ;
V_3 -> V_33 = 0 ;
} else {
F_20 ( V_3 , L_5 ) ;
}
}
F_14 ( V_19 , V_34 , & V_31 ) ;
V_31 &= ~ V_30 ;
V_31 |= ( V_29 & V_30 ) ;
V_3 -> V_28 = 1 ;
F_24 () ;
F_15 ( V_19 , V_34 , V_31 ) ;
if ( ! V_3 -> V_33 ) {
int V_24 = 0 ;
if ( ! ( V_31 & V_35 ) ||
! ( V_31 & V_36 ) )
V_24 = 1 ;
F_17 ( V_3 , V_24 ) ;
}
F_25 ( & V_3 -> V_32 ) ;
}
bool F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_37 ;
bool V_38 ;
F_14 ( V_19 , V_39 , & V_37 ) ;
V_38 = ! ! ( V_37 & V_40 ) ;
if ( V_38 )
F_20 ( V_3 , L_6 , V_41 , V_37 ) ;
return V_38 ;
}
static void F_27 ( struct V_2 * V_3 , bool V_42 )
{
int V_21 = 1000 ;
if ( F_26 ( V_3 ) == V_42 )
return;
while ( V_21 > 0 ) {
F_16 ( 10 ) ;
V_21 -= 10 ;
if ( F_26 ( V_3 ) == V_42 )
return;
}
F_20 ( V_3 , L_7 ,
V_42 ? L_8 : L_9 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
F_27 ( V_3 , true ) ;
}
static bool F_29 ( struct V_43 * V_44 , int V_45 )
{
T_2 V_46 ;
int V_47 = 0 ;
int V_48 = 1000 , V_49 = 20 ;
bool V_50 = false ;
do {
V_50 = F_30 ( V_44 , V_45 , & V_46 , 0 ) ;
V_47 ++ ;
if ( V_50 )
break;
F_16 ( V_49 ) ;
V_48 -= V_49 ;
} while ( V_48 > 0 );
if ( V_47 > 1 && V_51 )
F_31 ( V_52 L_10 ,
F_32 ( V_44 ) , V_44 -> V_53 , F_33 ( V_45 ) ,
F_34 ( V_45 ) , V_47 , V_49 , V_46 ) ;
return V_50 ;
}
int F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
bool V_50 ;
T_1 V_37 ;
if ( V_3 -> V_54 )
F_28 ( V_3 ) ;
else
F_16 ( 1000 ) ;
F_16 ( 100 ) ;
V_50 = F_29 ( V_3 -> V_4 -> V_5 -> V_55 ,
F_36 ( 0 , 0 ) ) ;
F_14 ( V_19 , V_39 , & V_37 ) ;
F_20 ( V_3 , L_6 , V_41 , V_37 ) ;
if ( ( V_37 & V_56 ) ||
! ( V_37 & V_57 ) ) {
F_9 ( V_3 , L_11 ) ;
return - 1 ;
}
F_37 ( V_3 -> V_4 -> V_5 -> V_55 , V_37 ) ;
if ( ! V_50 )
return - 1 ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , bool V_58 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_59 ;
F_14 ( V_19 , V_60 , & V_59 ) ;
if ( V_58 )
V_59 &= ~ V_61 ;
else
V_59 |= V_61 ;
F_15 ( V_19 , V_60 , V_59 ) ;
F_20 ( V_3 , L_12 , V_41 , V_59 ) ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 )
{
return F_38 ( V_3 , true ) ;
}
void F_40 ( struct V_62 * V_62 , T_3 * V_63 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_14 ( V_19 , V_34 , & V_31 ) ;
F_20 ( V_3 , L_13 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 , V_31 ) ;
switch ( V_31 & V_64 ) {
case V_65 :
* V_63 = 1 ;
break;
case V_66 :
* V_63 = 2 ;
break;
case V_67 :
* V_63 = 0 ;
break;
default:
* V_63 = 0xFF ;
break;
}
}
void F_42 ( struct V_62 * V_62 , T_3 * V_63 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_31 ;
F_14 ( V_19 , V_34 , & V_31 ) ;
F_20 ( V_3 , L_14 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 , V_31 ) ;
switch ( V_31 & V_68 ) {
case V_69 :
* V_63 = 1 ;
break;
case V_70 :
* V_63 = 0 ;
break;
default:
* V_63 = 0xFF ;
break;
}
}
void F_43 ( struct V_62 * V_62 , T_3 * V_63 )
{
struct V_1 * V_19 = F_1 ( V_62 -> V_3 ) ;
T_1 V_20 ;
F_14 ( V_19 , V_22 , & V_20 ) ;
* V_63 = ! ! ( V_20 & V_71 ) ;
}
void F_44 ( struct V_62 * V_62 , T_3 * V_63 )
{
struct V_1 * V_19 = F_1 ( V_62 -> V_3 ) ;
T_1 V_20 ;
F_14 ( V_19 , V_22 , & V_20 ) ;
* V_63 = ! ! ( V_20 & V_72 ) ;
}
int F_45 ( struct V_62 * V_62 )
{
struct V_1 * V_19 = F_1 ( V_62 -> V_3 ) ;
T_1 V_20 ;
F_14 ( V_19 , V_22 , & V_20 ) ;
return ! ! ( V_20 & V_73 ) ;
}
void F_46 ( struct V_62 * V_62 , T_3 V_74 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
T_1 V_75 ;
if ( ! F_47 ( V_3 ) )
return;
switch ( V_74 ) {
case 0 :
V_75 = V_67 ;
break;
case 1 :
V_75 = V_65 ;
break;
case 2 :
V_75 = V_66 ;
break;
default:
return;
}
F_20 ( V_3 , L_15 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 , V_75 ) ;
F_21 ( V_3 , V_75 , V_64 ) ;
}
void F_48 ( struct V_62 * V_62 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
if ( ! F_49 ( V_3 ) )
return;
F_21 ( V_3 , V_76 , V_77 ) ;
F_20 ( V_3 , L_15 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 ,
V_76 ) ;
}
void F_50 ( struct V_62 * V_62 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
if ( ! F_49 ( V_3 ) )
return;
F_21 ( V_3 , V_78 , V_77 ) ;
F_20 ( V_3 , L_15 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 ,
V_78 ) ;
}
void F_51 ( struct V_62 * V_62 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
if ( ! F_49 ( V_3 ) )
return;
F_21 ( V_3 , V_79 , V_77 ) ;
F_20 ( V_3 , L_15 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 ,
V_79 ) ;
}
int F_52 ( struct V_62 * V_62 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_20 ;
int V_14 ;
F_14 ( V_19 , V_22 , & V_20 ) ;
if ( V_20 & V_73 )
F_15 ( V_19 , V_22 ,
V_73 ) ;
V_3 -> V_80 = 0 ;
F_21 ( V_3 , V_69 , V_68 ) ;
F_20 ( V_3 , L_15 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 ,
V_69 ) ;
V_14 = F_39 ( V_3 ) ;
if ( V_14 )
F_9 ( V_3 , L_16 , V_41 ) ;
return V_14 ;
}
void F_53 ( struct V_62 * V_62 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
F_21 ( V_3 , V_70 , V_68 ) ;
F_20 ( V_3 , L_15 , V_41 ,
F_41 ( V_3 -> V_4 -> V_5 ) + V_34 ,
V_70 ) ;
}
static T_4 F_3 ( int V_15 , void * V_81 )
{
struct V_2 * V_3 = (struct V_2 * ) V_81 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_62 * V_62 = V_3 -> V_62 ;
T_1 V_82 , V_83 ;
V_83 = 0 ;
do {
F_14 ( V_19 , V_22 , & V_82 ) ;
V_82 &= ( V_84 | V_73 |
V_85 | V_86 |
V_23 | V_87 ) ;
V_82 &= ~ V_83 ;
V_83 |= V_82 ;
if ( ! V_83 )
return V_88 ;
if ( V_82 )
F_15 ( V_19 , V_22 ,
V_83 ) ;
} while ( V_82 );
F_20 ( V_3 , L_17 , V_41 , V_83 ) ;
if ( V_83 & V_23 ) {
V_3 -> V_28 = 0 ;
F_24 () ;
F_54 ( & V_3 -> V_27 ) ;
}
if ( ! ( V_83 & ~ V_23 ) )
return V_89 ;
if ( V_83 & V_85 )
F_55 ( V_62 ) ;
if ( V_83 & V_84 )
F_56 ( V_62 ) ;
if ( V_83 & V_86 )
F_57 ( V_62 ) ;
if ( ( V_83 & V_73 ) && ! V_3 -> V_80 ) {
V_3 -> V_80 = 1 ;
F_58 ( V_62 ) ;
}
if ( V_83 & V_87 )
F_59 ( V_62 ) ;
return V_89 ;
}
void F_60 ( struct V_2 * V_3 )
{
T_1 V_29 , V_30 ;
V_29 = V_90 ;
if ( F_61 ( V_3 ) )
V_29 |= V_91 ;
else
V_29 |= V_92 ;
if ( F_62 ( V_3 ) )
V_29 |= V_93 ;
if ( ! V_16 )
V_29 |= V_35 | V_36 ;
V_30 = ( V_92 | V_91 |
V_93 | V_94 |
V_35 | V_36 |
V_90 ) ;
F_21 ( V_3 , V_29 , V_30 ) ;
}
static void F_63 ( struct V_2 * V_3 )
{
T_1 V_30 ;
V_30 = ( V_92 | V_91 |
V_93 | V_94 |
V_35 | V_36 |
V_90 ) ;
F_21 ( V_3 , 0 , V_30 ) ;
}
int F_64 ( struct V_62 * V_62 , int V_95 )
{
struct V_2 * V_3 = V_62 -> V_3 ;
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_96 = 0 , V_97 = 0 ;
if ( V_95 )
return 0 ;
if ( ! F_61 ( V_3 ) ) {
V_97 |= V_92 ;
V_96 |= V_86 ;
}
V_97 |= V_90 ;
V_96 |= V_87 ;
F_21 ( V_3 , 0 , V_97 ) ;
if ( V_16 )
F_11 ( & V_3 -> V_7 ) ;
F_65 ( V_3 -> V_4 -> V_5 ) ;
F_15 ( V_19 , V_22 , V_96 ) ;
F_21 ( V_3 , V_97 , V_97 ) ;
if ( V_16 )
F_2 ( V_3 -> V_7 . V_6 ) ;
return 0 ;
}
int F_66 ( struct V_2 * V_3 )
{
if ( F_7 ( V_3 ) )
return - 1 ;
F_60 ( V_3 ) ;
V_3 -> V_98 = 1 ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
if ( V_3 -> V_98 ) {
F_63 ( V_3 ) ;
F_10 ( V_3 ) ;
V_3 -> V_98 = 0 ;
}
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_62 * V_62 ;
V_62 = F_69 ( sizeof( * V_62 ) , V_99 ) ;
if ( ! V_62 )
return - V_100 ;
V_62 -> V_101 = F_70 ( L_18 , 0 , 0 , F_71 ( V_3 ) ) ;
if ( ! V_62 -> V_101 )
goto abort;
V_62 -> V_3 = V_3 ;
F_72 ( & V_62 -> V_102 ) ;
F_72 ( & V_62 -> V_103 ) ;
F_73 ( & V_62 -> V_104 , V_105 ) ;
V_3 -> V_62 = V_62 ;
return 0 ;
abort:
F_74 ( V_62 ) ;
return - V_100 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_62 * V_62 = V_3 -> V_62 ;
F_76 ( & V_62 -> V_104 ) ;
F_77 ( V_62 -> V_101 ) ;
F_74 ( V_62 ) ;
}
static inline void F_78 ( struct V_2 * V_3 )
{
int V_106 ;
T_1 V_107 ;
struct V_1 * V_19 = V_3 -> V_4 -> V_5 ;
if ( ! V_51 )
return;
F_79 ( V_3 , L_19 ) ;
F_79 ( V_3 , L_20 ,
F_80 ( V_19 ) , V_19 -> V_15 ) ;
F_79 ( V_3 , L_21 , V_19 -> V_108 ) ;
F_79 ( V_3 , L_22 , V_19 -> V_109 ) ;
F_79 ( V_3 , L_23 ,
V_19 -> V_110 ) ;
F_79 ( V_3 , L_24 ,
V_19 -> V_111 ) ;
F_79 ( V_3 , L_25 ,
F_41 ( V_19 ) ) ;
for ( V_106 = 0 ; V_106 < V_112 ; V_106 ++ ) {
if ( ! F_81 ( V_19 , V_106 ) )
continue;
F_79 ( V_3 , L_26 ,
V_106 , & V_19 -> V_113 [ V_106 ] ) ;
}
F_79 ( V_3 , L_27 , V_3 -> V_114 ) ;
F_79 ( V_3 , L_28 , F_71 ( V_3 ) ) ;
F_79 ( V_3 , L_29 ,
F_61 ( V_3 ) ? L_30 : L_31 ) ;
F_79 ( V_3 , L_32 ,
F_82 ( V_3 ) ? L_30 : L_31 ) ;
F_79 ( V_3 , L_33 ,
F_62 ( V_3 ) ? L_30 : L_31 ) ;
F_79 ( V_3 , L_34 ,
F_47 ( V_3 ) ? L_30 : L_31 ) ;
F_79 ( V_3 , L_35 ,
F_49 ( V_3 ) ? L_30 : L_31 ) ;
F_79 ( V_3 , L_36 ,
F_83 ( V_3 ) ? L_30 : L_31 ) ;
F_79 ( V_3 , L_37 ,
F_84 ( V_3 ) ? L_30 : L_31 ) ;
F_79 ( V_3 , L_38 ,
F_23 ( V_3 ) ? L_31 : L_30 ) ;
F_14 ( V_19 , V_22 , & V_107 ) ;
F_79 ( V_3 , L_39 , V_107 ) ;
F_14 ( V_19 , V_34 , & V_107 ) ;
F_79 ( V_3 , L_40 , V_107 ) ;
}
struct V_2 * F_85 ( struct V_115 * V_116 )
{
struct V_2 * V_3 ;
T_2 V_114 , V_117 ;
struct V_1 * V_19 = V_116 -> V_5 ;
V_3 = F_69 ( sizeof( * V_3 ) , V_99 ) ;
if ( ! V_3 ) {
F_86 ( & V_116 -> V_109 , L_41 , V_41 ) ;
goto abort;
}
V_3 -> V_4 = V_116 ;
F_87 ( V_19 , V_118 , & V_114 ) ;
V_3 -> V_114 = V_114 ;
F_72 ( & V_3 -> V_32 ) ;
F_88 ( & V_3 -> V_27 ) ;
F_78 ( V_3 ) ;
if ( F_23 ( V_3 ) ||
! ( F_82 ( V_3 ) | F_47 ( V_3 ) | F_49 ( V_3 ) | F_84 ( V_3 ) ) )
V_3 -> V_33 = 1 ;
F_87 ( V_19 , V_119 , & V_117 ) ;
if ( V_117 & V_120 ) {
F_20 ( V_3 , L_42 ) ;
V_3 -> V_54 = 1 ;
}
F_15 ( V_19 , V_22 ,
V_84 | V_73 |
V_85 | V_86 |
V_23 ) ;
F_63 ( V_3 ) ;
F_79 ( V_3 , L_43 ,
( V_114 & V_121 ) >> 19 ,
F_89 ( V_114 , V_122 ) ,
F_89 ( V_114 , V_123 ) ,
F_89 ( V_114 , V_124 ) ,
F_89 ( V_114 , V_125 ) ,
F_89 ( V_114 , V_126 ) ,
F_89 ( V_114 , V_127 ) ,
F_89 ( V_114 , V_128 ) ,
F_89 ( V_117 , V_120 ) ) ;
if ( F_68 ( V_3 ) )
goto V_129;
return V_3 ;
V_129:
F_74 ( V_3 ) ;
abort:
return NULL ;
}
void F_90 ( struct V_2 * V_3 )
{
F_67 ( V_3 ) ;
F_75 ( V_3 ) ;
F_74 ( V_3 ) ;
}
