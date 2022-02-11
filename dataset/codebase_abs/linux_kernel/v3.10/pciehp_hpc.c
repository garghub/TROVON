static inline int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_2 ( V_6 , V_3 , V_4 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_4 ( V_6 , V_3 , V_4 ) ;
}
static inline int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_6 ( V_6 , V_3 , V_4 ) ;
}
static inline int F_7 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_8 ( V_6 , V_3 , V_4 ) ;
}
static void F_9 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_10 ( 0 , V_2 ) ;
F_11 ( & V_2 -> V_10 ) ;
if ( ! V_11 )
V_11 = 2 ;
F_12 ( V_2 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_12 )
{
if ( ( V_12 <= 0 ) || ( V_12 > 60 ) )
V_12 = 2 ;
V_2 -> V_10 . V_13 = & F_9 ;
V_2 -> V_10 . V_9 = ( unsigned long ) V_2 ;
V_2 -> V_10 . V_14 = V_15 + V_12 * V_16 ;
F_13 ( & V_2 -> V_10 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
int V_17 , V_18 = V_2 -> V_7 -> V_18 ;
if ( V_19 ) {
F_11 ( & V_2 -> V_10 ) ;
F_12 ( V_2 , 10 ) ;
return 0 ;
}
V_17 = F_15 ( V_18 , F_10 , V_20 , V_21 , V_2 ) ;
if ( V_17 )
F_16 ( V_2 , L_1 ,
V_18 ) ;
return V_17 ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
if ( V_19 )
F_18 ( & V_2 -> V_10 ) ;
else
F_19 ( V_2 -> V_7 -> V_18 , V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_22 ;
int V_23 , V_24 = 1000 ;
V_23 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( ! V_23 && ( V_22 & V_26 ) ) {
F_5 ( V_2 , V_25 , V_26 ) ;
return 1 ;
}
while ( V_24 > 0 ) {
F_21 ( 10 ) ;
V_24 -= 10 ;
V_23 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( ! V_23 && ( V_22 & V_26 ) ) {
F_5 ( V_2 , V_25 , V_26 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , int V_27 )
{
unsigned int V_28 = V_19 ? 2500 : 1000 ;
unsigned long V_24 = F_23 ( V_28 ) ;
int V_29 ;
if ( V_27 )
V_29 = F_20 ( V_2 ) ;
else
V_29 = F_24 ( V_2 -> V_30 , ! V_2 -> V_31 , V_24 ) ;
if ( ! V_29 )
F_25 ( V_2 , L_2 ) ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_32 , T_1 V_33 )
{
int V_17 = 0 ;
T_1 V_22 ;
T_1 V_34 ;
F_27 ( & V_2 -> V_35 ) ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_3 ,
V_36 ) ;
goto V_37;
}
if ( V_22 & V_26 ) {
if ( ! V_2 -> V_38 ) {
F_25 ( V_2 , L_4 ) ;
} else if ( ! F_28 ( V_2 ) ) {
F_25 ( V_2 , L_5
L_6 ) ;
V_2 -> V_38 = 0 ;
} else {
F_25 ( V_2 , L_7
L_8 ) ;
}
}
V_17 = F_1 ( V_2 , V_39 , & V_34 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_9 , V_36 ) ;
goto V_37;
}
V_34 &= ~ V_33 ;
V_34 |= ( V_32 & V_33 ) ;
V_2 -> V_31 = 1 ;
F_29 () ;
V_17 = F_5 ( V_2 , V_39 , V_34 ) ;
if ( V_17 )
F_16 ( V_2 , L_10 ) ;
if ( ! V_17 && ! V_2 -> V_38 ) {
int V_27 = 0 ;
if ( ! ( V_34 & V_40 ) ||
! ( V_34 & V_41 ) )
V_27 = 1 ;
F_22 ( V_2 , V_27 ) ;
}
V_37:
F_30 ( & V_2 -> V_35 ) ;
return V_17 ;
}
static bool F_31 ( struct V_1 * V_2 )
{
bool V_42 = false ;
T_1 V_43 ;
if ( F_1 ( V_2 , V_44 , & V_43 ) )
return V_42 ;
V_42 = ! ! ( V_43 & V_45 ) ;
if ( V_42 )
F_25 ( V_2 , L_11 , V_36 , V_43 ) ;
return V_42 ;
}
static void F_32 ( struct V_1 * V_2 , bool V_46 )
{
int V_24 = 1000 ;
if ( F_31 ( V_2 ) == V_46 )
return;
while ( V_24 > 0 ) {
F_21 ( 10 ) ;
V_24 -= 10 ;
if ( F_31 ( V_2 ) == V_46 )
return;
}
F_25 ( V_2 , L_12 ,
V_46 ? L_13 : L_14 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_32 ( V_2 , true ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_32 ( V_2 , false ) ;
}
static bool F_35 ( struct V_47 * V_48 , int V_49 )
{
T_2 V_50 ;
int V_51 = 0 ;
int V_52 = 1000 , V_53 = 20 ;
bool V_54 = false ;
do {
V_54 = F_36 ( V_48 , V_49 , & V_50 , 0 ) ;
V_51 ++ ;
if ( V_54 )
break;
F_21 ( V_53 ) ;
V_52 -= V_53 ;
} while ( V_52 > 0 );
if ( V_51 > 1 && V_55 )
F_37 ( V_56 L_15 ,
F_38 ( V_48 ) , V_48 -> V_57 , F_39 ( V_49 ) ,
F_40 ( V_49 ) , V_51 , V_53 , V_50 ) ;
return V_54 ;
}
int F_41 ( struct V_1 * V_2 )
{
T_1 V_43 ;
int V_17 = 0 ;
bool V_54 = false ;
if ( V_2 -> V_58 )
F_33 ( V_2 ) ;
else
F_21 ( 1000 ) ;
F_21 ( 100 ) ;
V_54 = F_35 ( V_2 -> V_7 -> V_8 -> V_59 ,
F_42 ( 0 , 0 ) ) ;
V_17 = F_1 ( V_2 , V_44 , & V_43 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_16 ) ;
return V_17 ;
}
F_25 ( V_2 , L_11 , V_36 , V_43 ) ;
if ( ( V_43 & V_60 ) ||
! ( V_43 & V_61 ) ) {
F_16 ( V_2 , L_17 ) ;
V_17 = - 1 ;
return V_17 ;
}
F_43 ( V_2 -> V_7 -> V_8 -> V_59 , V_43 ) ;
if ( ! V_54 && ! V_17 )
V_17 = - 1 ;
return V_17 ;
}
static int F_44 ( struct V_1 * V_2 , bool V_62 )
{
T_1 V_63 ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_64 , & V_63 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_18 ) ;
return V_17 ;
}
if ( V_62 )
V_63 &= ~ V_65 ;
else
V_63 |= V_65 ;
V_17 = F_5 ( V_2 , V_64 , V_63 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_19 ) ;
return V_17 ;
}
F_25 ( V_2 , L_20 , V_36 , V_63 ) ;
return V_17 ;
}
static int F_45 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , true ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
return F_44 ( V_2 , false ) ;
}
int F_47 ( struct V_66 * V_66 , T_3 * V_67 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_34 ;
T_3 V_68 ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_39 , & V_34 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_9 , V_36 ) ;
return V_17 ;
}
F_25 ( V_2 , L_21 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_34 ) ;
V_68 = ( V_34 & V_69 ) >> 6 ;
switch ( V_68 ) {
case 0 :
* V_67 = 0xFF ;
break;
case 1 :
* V_67 = 1 ;
break;
case 2 :
* V_67 = 2 ;
break;
case 3 :
* V_67 = 0 ;
break;
default:
* V_67 = 0xFF ;
break;
}
return 0 ;
}
int F_49 ( struct V_66 * V_66 , T_3 * V_67 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_34 ;
T_3 V_70 ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_39 , & V_34 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_9 , V_36 ) ;
return V_17 ;
}
F_25 ( V_2 , L_22 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_34 ) ;
V_70 = ( V_34 & V_71 ) >> 10 ;
switch ( V_70 ) {
case 0 :
* V_67 = 1 ;
break;
case 1 :
* V_67 = 0 ;
break;
default:
* V_67 = 0xFF ;
break;
}
return V_17 ;
}
int F_50 ( struct V_66 * V_66 , T_3 * V_67 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_22 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_3 ,
V_36 ) ;
return V_17 ;
}
* V_67 = ! ! ( V_22 & V_72 ) ;
return 0 ;
}
int F_51 ( struct V_66 * V_66 , T_3 * V_67 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_22 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_3 ,
V_36 ) ;
return V_17 ;
}
* V_67 = ! ! ( V_22 & V_73 ) ;
return 0 ;
}
int F_52 ( struct V_66 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_22 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_23 ) ;
return V_17 ;
}
return ! ! ( V_22 & V_74 ) ;
}
int F_53 ( struct V_66 * V_66 , T_3 V_4 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_75 ;
T_1 V_76 ;
V_76 = V_69 ;
switch ( V_4 ) {
case 0 :
V_75 = 0x00C0 ;
break;
case 1 :
V_75 = 0x0040 ;
break;
case 2 :
V_75 = 0x0080 ;
break;
default:
return - V_77 ;
}
F_25 ( V_2 , L_24 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_75 ) ;
return F_26 ( V_2 , V_75 , V_76 ) ;
}
void F_54 ( struct V_66 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_75 ;
T_1 V_76 ;
V_75 = 0x0100 ;
V_76 = V_78 ;
F_26 ( V_2 , V_75 , V_76 ) ;
F_25 ( V_2 , L_24 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_75 ) ;
}
void F_55 ( struct V_66 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_75 ;
T_1 V_76 ;
V_75 = 0x0300 ;
V_76 = V_78 ;
F_26 ( V_2 , V_75 , V_76 ) ;
F_25 ( V_2 , L_24 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_75 ) ;
}
void F_56 ( struct V_66 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_75 ;
T_1 V_76 ;
V_75 = 0x0200 ;
V_76 = V_78 ;
F_26 ( V_2 , V_75 , V_76 ) ;
F_25 ( V_2 , L_24 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_75 ) ;
}
int F_57 ( struct V_66 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_75 ;
T_1 V_76 ;
T_1 V_22 ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_3 ,
V_36 ) ;
return V_17 ;
}
V_22 &= V_74 ;
if ( V_22 ) {
V_17 = F_5 ( V_2 , V_25 , V_22 ) ;
if ( V_17 ) {
F_16 ( V_2 ,
L_25 ,
V_36 ) ;
return V_17 ;
}
}
V_2 -> V_79 = 0 ;
V_75 = V_80 ;
V_76 = V_71 ;
V_17 = F_26 ( V_2 , V_75 , V_76 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_26 , V_75 ) ;
return V_17 ;
}
F_25 ( V_2 , L_24 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_75 ) ;
V_17 = F_45 ( V_2 ) ;
if ( V_17 )
F_16 ( V_2 , L_27 , V_36 ) ;
return V_17 ;
}
int F_58 ( struct V_66 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_75 ;
T_1 V_76 ;
int V_17 ;
F_46 ( V_2 ) ;
if ( V_2 -> V_58 )
F_34 ( V_2 ) ;
else
F_21 ( 1000 ) ;
V_75 = V_81 ;
V_76 = V_71 ;
V_17 = F_26 ( V_2 , V_75 , V_76 ) ;
if ( V_17 ) {
F_16 ( V_2 , L_28 ) ;
return V_17 ;
}
F_25 ( V_2 , L_24 , V_36 ,
F_48 ( V_2 -> V_7 -> V_8 ) + V_39 , V_75 ) ;
return 0 ;
}
static T_4 F_10 ( int V_18 , void * V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
struct V_66 * V_66 = V_2 -> V_66 ;
T_1 V_83 , V_84 ;
V_84 = 0 ;
do {
if ( F_1 ( V_2 , V_25 , & V_83 ) ) {
F_16 ( V_2 , L_29 ,
V_36 ) ;
return V_85 ;
}
V_83 &= ( V_86 | V_74 |
V_87 | V_88 |
V_26 ) ;
V_83 &= ~ V_84 ;
V_84 |= V_83 ;
if ( ! V_84 )
return V_85 ;
if ( V_83 && F_5 ( V_2 , V_25 , V_84 ) ) {
F_16 ( V_2 , L_30 ,
V_36 ) ;
return V_85 ;
}
} while ( V_83 );
F_25 ( V_2 , L_31 , V_36 , V_84 ) ;
if ( V_84 & V_26 ) {
V_2 -> V_31 = 0 ;
F_29 () ;
F_59 ( & V_2 -> V_30 ) ;
}
if ( ! ( V_84 & ~ V_26 ) )
return V_89 ;
if ( V_84 & V_87 )
F_60 ( V_66 ) ;
if ( V_84 & V_86 )
F_61 ( V_66 ) ;
if ( V_84 & V_88 )
F_62 ( V_66 ) ;
if ( ( V_84 & V_74 ) && ! V_2 -> V_79 ) {
V_2 -> V_79 = 1 ;
F_63 ( V_66 ) ;
}
return V_89 ;
}
int F_64 ( struct V_1 * V_2 )
{
T_1 V_32 , V_33 ;
V_32 = V_90 ;
if ( F_65 ( V_2 ) )
V_32 |= V_91 ;
if ( F_66 ( V_2 ) )
V_32 |= V_92 ;
if ( ! V_19 )
V_32 |= V_40 | V_41 ;
V_33 = ( V_90 | V_91 |
V_92 | V_93 |
V_40 | V_41 ) ;
if ( F_26 ( V_2 , V_32 , V_33 ) ) {
F_16 ( V_2 , L_32 ) ;
return - 1 ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
T_1 V_33 ;
V_33 = ( V_90 | V_91 |
V_92 | V_93 |
V_40 | V_41 |
V_94 ) ;
if ( F_26 ( V_2 , 0 , V_33 ) )
F_68 ( V_2 , L_33 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
if ( F_14 ( V_2 ) )
return - 1 ;
if ( F_64 ( V_2 ) ) {
F_17 ( V_2 ) ;
return - 1 ;
}
V_2 -> V_95 = 1 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 ) {
F_67 ( V_2 ) ;
F_17 ( V_2 ) ;
V_2 -> V_95 = 0 ;
}
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_66 * V_66 ;
char V_96 [ 32 ] ;
V_66 = F_72 ( sizeof( * V_66 ) , V_97 ) ;
if ( ! V_66 )
return - V_98 ;
snprintf ( V_96 , sizeof( V_96 ) , L_34 , F_73 ( V_2 ) ) ;
V_66 -> V_99 = F_74 ( V_96 , 0 , 0 ) ;
if ( ! V_66 -> V_99 )
goto abort;
V_66 -> V_2 = V_2 ;
F_75 ( & V_66 -> V_100 ) ;
F_76 ( & V_66 -> V_101 , V_102 ) ;
V_2 -> V_66 = V_66 ;
return 0 ;
abort:
F_77 ( V_66 ) ;
return - V_98 ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_66 * V_66 = V_2 -> V_66 ;
F_79 ( & V_66 -> V_101 ) ;
F_80 ( V_66 -> V_99 ) ;
F_77 ( V_66 ) ;
}
static inline void F_81 ( struct V_1 * V_2 )
{
int V_103 ;
T_1 V_104 ;
struct V_5 * V_105 = V_2 -> V_7 -> V_8 ;
if ( ! V_55 )
return;
F_82 ( V_2 , L_35 ) ;
F_82 ( V_2 , L_36 ,
F_83 ( V_105 ) , V_105 -> V_18 ) ;
F_82 ( V_2 , L_37 , V_105 -> V_106 ) ;
F_82 ( V_2 , L_38 , V_105 -> V_107 ) ;
F_82 ( V_2 , L_39 ,
V_105 -> V_108 ) ;
F_82 ( V_2 , L_40 ,
V_105 -> V_109 ) ;
F_82 ( V_2 , L_41 ,
F_48 ( V_105 ) ) ;
for ( V_103 = 0 ; V_103 < V_110 ; V_103 ++ ) {
if ( ! F_84 ( V_105 , V_103 ) )
continue;
F_82 ( V_2 , L_42 ,
V_103 , & V_105 -> V_111 [ V_103 ] ) ;
}
F_82 ( V_2 , L_43 , V_2 -> V_112 ) ;
F_82 ( V_2 , L_44 , F_73 ( V_2 ) ) ;
F_82 ( V_2 , L_45 ,
F_65 ( V_2 ) ? L_46 : L_47 ) ;
F_82 ( V_2 , L_48 ,
F_85 ( V_2 ) ? L_46 : L_47 ) ;
F_82 ( V_2 , L_49 ,
F_66 ( V_2 ) ? L_46 : L_47 ) ;
F_82 ( V_2 , L_50 ,
F_86 ( V_2 ) ? L_46 : L_47 ) ;
F_82 ( V_2 , L_51 ,
F_87 ( V_2 ) ? L_46 : L_47 ) ;
F_82 ( V_2 , L_52 ,
F_88 ( V_2 ) ? L_46 : L_47 ) ;
F_82 ( V_2 , L_53 ,
F_89 ( V_2 ) ? L_46 : L_47 ) ;
F_82 ( V_2 , L_54 ,
F_28 ( V_2 ) ? L_47 : L_46 ) ;
F_1 ( V_2 , V_25 , & V_104 ) ;
F_82 ( V_2 , L_55 , V_104 ) ;
F_1 ( V_2 , V_39 , & V_104 ) ;
F_82 ( V_2 , L_56 , V_104 ) ;
}
struct V_1 * F_90 ( struct V_113 * V_6 )
{
struct V_1 * V_2 ;
T_2 V_112 , V_114 ;
struct V_5 * V_105 = V_6 -> V_8 ;
V_2 = F_72 ( sizeof( * V_2 ) , V_97 ) ;
if ( ! V_2 ) {
F_91 ( & V_6 -> V_107 , L_57 , V_36 ) ;
goto abort;
}
V_2 -> V_7 = V_6 ;
if ( F_3 ( V_2 , V_115 , & V_112 ) ) {
F_16 ( V_2 , L_58 ) ;
goto V_116;
}
V_2 -> V_112 = V_112 ;
F_75 ( & V_2 -> V_35 ) ;
F_92 ( & V_2 -> V_30 ) ;
F_81 ( V_2 ) ;
if ( F_28 ( V_2 ) ||
! ( F_85 ( V_2 ) | F_86 ( V_2 ) | F_87 ( V_2 ) | F_89 ( V_2 ) ) )
V_2 -> V_38 = 1 ;
if ( F_3 ( V_2 , V_117 , & V_114 ) ) {
F_16 ( V_2 , L_59 , V_36 ) ;
goto V_116;
}
if ( V_114 & V_118 ) {
F_25 ( V_2 , L_60 ) ;
V_2 -> V_58 = 1 ;
}
if ( F_5 ( V_2 , V_25 , 0x1f ) )
goto V_116;
F_67 ( V_2 ) ;
F_82 ( V_2 , L_61 ,
V_105 -> V_106 , V_105 -> V_107 , V_105 -> V_109 ,
V_105 -> V_108 ) ;
if ( F_71 ( V_2 ) )
goto V_116;
return V_2 ;
V_116:
F_77 ( V_2 ) ;
abort:
return NULL ;
}
void F_93 ( struct V_1 * V_2 )
{
F_70 ( V_2 ) ;
F_78 ( V_2 ) ;
F_77 ( V_2 ) ;
}
