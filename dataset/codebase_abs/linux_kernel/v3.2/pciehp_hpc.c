static inline int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_2 ( V_6 , F_3 ( V_6 ) + V_3 , V_4 ) ;
}
static inline int F_4 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_5 ( V_6 , F_3 ( V_6 ) + V_3 , V_4 ) ;
}
static inline int F_6 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_7 ( V_6 , F_3 ( V_6 ) + V_3 , V_4 ) ;
}
static inline int F_8 ( struct V_1 * V_2 , int V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
return F_9 ( V_6 , F_3 ( V_6 ) + V_3 , V_4 ) ;
}
static void F_10 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_11 ( 0 , V_2 ) ;
F_12 ( & V_2 -> V_10 ) ;
if ( ! V_11 )
V_11 = 2 ;
F_13 ( V_2 , V_11 ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_12 )
{
if ( ( V_12 <= 0 ) || ( V_12 > 60 ) )
V_12 = 2 ;
V_2 -> V_10 . V_13 = & F_10 ;
V_2 -> V_10 . V_9 = ( unsigned long ) V_2 ;
V_2 -> V_10 . V_14 = V_15 + V_12 * V_16 ;
F_14 ( & V_2 -> V_10 ) ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
int V_17 , V_18 = V_2 -> V_7 -> V_18 ;
if ( V_19 ) {
F_12 ( & V_2 -> V_10 ) ;
F_13 ( V_2 , 10 ) ;
return 0 ;
}
V_17 = F_16 ( V_18 , F_11 , V_20 , V_21 , V_2 ) ;
if ( V_17 )
F_17 ( V_2 , L_1 ,
V_18 ) ;
return V_17 ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
if ( V_19 )
F_19 ( & V_2 -> V_10 ) ;
else
F_20 ( V_2 -> V_7 -> V_18 , V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_1 V_22 ;
int V_23 , V_24 = 1000 ;
V_23 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( ! V_23 && ( V_22 & V_26 ) ) {
F_6 ( V_2 , V_25 , V_26 ) ;
return 1 ;
}
while ( V_24 > 0 ) {
F_22 ( 10 ) ;
V_24 -= 10 ;
V_23 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( ! V_23 && ( V_22 & V_26 ) ) {
F_6 ( V_2 , V_25 , V_26 ) ;
return 1 ;
}
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , int V_27 )
{
unsigned int V_28 = V_19 ? 2500 : 1000 ;
unsigned long V_24 = F_24 ( V_28 ) ;
int V_29 ;
if ( V_27 )
V_29 = F_21 ( V_2 ) ;
else
V_29 = F_25 ( V_2 -> V_30 , ! V_2 -> V_31 , V_24 ) ;
if ( ! V_29 )
F_26 ( V_2 , L_2 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_32 , T_1 V_33 )
{
int V_17 = 0 ;
T_1 V_22 ;
T_1 V_34 ;
F_28 ( & V_2 -> V_35 ) ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_3 ,
V_36 ) ;
goto V_37;
}
if ( V_22 & V_26 ) {
if ( ! V_2 -> V_38 ) {
F_26 ( V_2 , L_4 ) ;
} else if ( ! F_29 ( V_2 ) ) {
F_26 ( V_2 , L_5
L_6 ) ;
V_2 -> V_38 = 0 ;
} else {
F_26 ( V_2 , L_7
L_8 ) ;
}
}
V_17 = F_1 ( V_2 , V_39 , & V_34 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_9 , V_36 ) ;
goto V_37;
}
V_34 &= ~ V_33 ;
V_34 |= ( V_32 & V_33 ) ;
V_2 -> V_31 = 1 ;
F_30 () ;
V_17 = F_6 ( V_2 , V_39 , V_34 ) ;
if ( V_17 )
F_17 ( V_2 , L_10 ) ;
if ( ! V_17 && ! V_2 -> V_38 ) {
int V_27 = 0 ;
if ( ! ( V_34 & V_40 ) ||
! ( V_34 & V_41 ) )
V_27 = 1 ;
F_23 ( V_2 , V_27 ) ;
}
V_37:
F_31 ( & V_2 -> V_35 ) ;
return V_17 ;
}
static inline int F_32 ( struct V_1 * V_2 )
{
T_1 V_42 ;
if ( F_1 ( V_2 , V_43 , & V_42 ) )
return 0 ;
return ! ! ( V_42 & V_44 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
int V_24 = 1000 ;
if ( F_32 ( V_2 ) )
return;
while ( V_24 > 0 ) {
F_22 ( 10 ) ;
V_24 -= 10 ;
if ( F_32 ( V_2 ) )
return;
}
F_26 ( V_2 , L_11 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
T_1 V_45 ;
int V_17 = 0 ;
if ( V_2 -> V_46 )
F_33 ( V_2 ) ;
else
F_22 ( 1000 ) ;
F_22 ( 1000 ) ;
V_17 = F_1 ( V_2 , V_43 , & V_45 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_12 ) ;
return V_17 ;
}
F_26 ( V_2 , L_13 , V_36 , V_45 ) ;
if ( ( V_45 & V_47 ) ||
! ( V_45 & V_48 ) ) {
F_17 ( V_2 , L_14 ) ;
V_17 = - 1 ;
return V_17 ;
}
if ( V_2 -> V_7 -> V_8 -> V_49 -> V_50 > V_51 )
F_22 ( 100 ) ;
F_35 ( V_2 -> V_7 -> V_8 -> V_49 , V_45 ) ;
return V_17 ;
}
int F_36 ( struct V_52 * V_52 , T_3 * V_53 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_34 ;
T_3 V_54 ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_39 , & V_34 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_9 , V_36 ) ;
return V_17 ;
}
F_26 ( V_2 , L_15 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_34 ) ;
V_54 = ( V_34 & V_55 ) >> 6 ;
switch ( V_54 ) {
case 0 :
* V_53 = 0xFF ;
break;
case 1 :
* V_53 = 1 ;
break;
case 2 :
* V_53 = 2 ;
break;
case 3 :
* V_53 = 0 ;
break;
default:
* V_53 = 0xFF ;
break;
}
return 0 ;
}
int F_37 ( struct V_52 * V_52 , T_3 * V_53 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_34 ;
T_3 V_56 ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_39 , & V_34 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_9 , V_36 ) ;
return V_17 ;
}
F_26 ( V_2 , L_16 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_34 ) ;
V_56 = ( V_34 & V_57 ) >> 10 ;
switch ( V_56 ) {
case 0 :
* V_53 = 1 ;
break;
case 1 :
* V_53 = 0 ;
break;
default:
* V_53 = 0xFF ;
break;
}
return V_17 ;
}
int F_38 ( struct V_52 * V_52 , T_3 * V_53 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_22 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_3 ,
V_36 ) ;
return V_17 ;
}
* V_53 = ! ! ( V_22 & V_58 ) ;
return 0 ;
}
int F_39 ( struct V_52 * V_52 , T_3 * V_53 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_22 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_3 ,
V_36 ) ;
return V_17 ;
}
* V_53 = ! ! ( V_22 & V_59 ) ;
return 0 ;
}
int F_40 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_22 ;
int V_17 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_17 ) ;
return V_17 ;
}
return ! ! ( V_22 & V_60 ) ;
}
int F_41 ( struct V_52 * V_52 , T_3 V_4 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_61 ;
T_1 V_62 ;
V_62 = V_55 ;
switch ( V_4 ) {
case 0 :
V_61 = 0x00C0 ;
break;
case 1 :
V_61 = 0x0040 ;
break;
case 2 :
V_61 = 0x0080 ;
break;
default:
return - V_63 ;
}
F_26 ( V_2 , L_18 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_61 ) ;
return F_27 ( V_2 , V_61 , V_62 ) ;
}
void F_42 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_61 ;
T_1 V_62 ;
V_61 = 0x0100 ;
V_62 = V_64 ;
F_27 ( V_2 , V_61 , V_62 ) ;
F_26 ( V_2 , L_18 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_61 ) ;
}
void F_43 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_61 ;
T_1 V_62 ;
V_61 = 0x0300 ;
V_62 = V_64 ;
F_27 ( V_2 , V_61 , V_62 ) ;
F_26 ( V_2 , L_18 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_61 ) ;
}
void F_44 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_61 ;
T_1 V_62 ;
V_61 = 0x0200 ;
V_62 = V_64 ;
F_27 ( V_2 , V_61 , V_62 ) ;
F_26 ( V_2 , L_18 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_61 ) ;
}
int F_45 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_61 ;
T_1 V_62 ;
T_1 V_22 ;
int V_17 = 0 ;
V_17 = F_1 ( V_2 , V_25 , & V_22 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_3 ,
V_36 ) ;
return V_17 ;
}
V_22 &= V_60 ;
if ( V_22 ) {
V_17 = F_6 ( V_2 , V_25 , V_22 ) ;
if ( V_17 ) {
F_17 ( V_2 ,
L_19 ,
V_36 ) ;
return V_17 ;
}
}
V_2 -> V_65 = 0 ;
V_61 = V_66 ;
V_62 = V_57 ;
V_17 = F_27 ( V_2 , V_61 , V_62 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_20 , V_61 ) ;
return V_17 ;
}
F_26 ( V_2 , L_18 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_61 ) ;
return V_17 ;
}
int F_46 ( struct V_52 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
T_1 V_61 ;
T_1 V_62 ;
int V_17 ;
V_61 = V_67 ;
V_62 = V_57 ;
V_17 = F_27 ( V_2 , V_61 , V_62 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_21 ) ;
return V_17 ;
}
F_26 ( V_2 , L_18 , V_36 ,
F_3 ( V_2 -> V_7 -> V_8 ) + V_39 , V_61 ) ;
return 0 ;
}
static T_4 F_11 ( int V_18 , void * V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
struct V_52 * V_52 = V_2 -> V_52 ;
T_1 V_69 , V_70 ;
V_70 = 0 ;
do {
if ( F_1 ( V_2 , V_25 , & V_69 ) ) {
F_17 ( V_2 , L_22 ,
V_36 ) ;
return V_71 ;
}
V_69 &= ( V_72 | V_60 |
V_73 | V_74 |
V_26 ) ;
V_69 &= ~ V_70 ;
V_70 |= V_69 ;
if ( ! V_70 )
return V_71 ;
if ( V_69 && F_6 ( V_2 , V_25 , V_70 ) ) {
F_17 ( V_2 , L_23 ,
V_36 ) ;
return V_71 ;
}
} while ( V_69 );
F_26 ( V_2 , L_24 , V_36 , V_70 ) ;
if ( V_70 & V_26 ) {
V_2 -> V_31 = 0 ;
F_30 () ;
F_47 ( & V_2 -> V_30 ) ;
}
if ( ! ( V_70 & ~ V_26 ) )
return V_75 ;
if ( V_70 & V_73 )
F_48 ( V_52 ) ;
if ( V_70 & V_72 )
F_49 ( V_52 ) ;
if ( V_70 & V_74 )
F_50 ( V_52 ) ;
if ( ( V_70 & V_60 ) && ! V_2 -> V_65 ) {
V_2 -> V_65 = 1 ;
F_51 ( V_52 ) ;
}
return V_75 ;
}
int F_52 ( struct V_52 * V_52 ,
enum V_76 * V_4 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
enum V_76 V_77 ;
T_2 V_78 ;
int V_17 = 0 ;
V_17 = F_4 ( V_2 , V_79 , & V_78 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_25 , V_36 ) ;
return V_17 ;
}
switch ( ( V_78 & V_48 ) >> 4 ) {
case 0 :
V_77 = V_80 ;
break;
case 1 :
V_77 = V_81 ;
break;
case 2 :
V_77 = V_82 ;
break;
case 4 :
V_77 = V_83 ;
break;
case 8 :
V_77 = V_84 ;
break;
case 12 :
V_77 = V_85 ;
break;
case 16 :
V_77 = V_86 ;
break;
case 32 :
V_77 = V_87 ;
break;
default:
V_77 = V_88 ;
break;
}
* V_4 = V_77 ;
F_26 ( V_2 , L_26 , V_77 ) ;
return V_17 ;
}
int F_53 ( struct V_52 * V_52 ,
enum V_76 * V_4 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
enum V_76 V_77 = V_88 ;
int V_17 = 0 ;
T_1 V_45 ;
V_17 = F_1 ( V_2 , V_43 , & V_45 ) ;
if ( V_17 ) {
F_17 ( V_2 , L_27 ,
V_36 ) ;
return V_17 ;
}
switch ( ( V_45 & V_48 ) >> 4 ) {
case 0 :
V_77 = V_80 ;
break;
case 1 :
V_77 = V_81 ;
break;
case 2 :
V_77 = V_82 ;
break;
case 4 :
V_77 = V_83 ;
break;
case 8 :
V_77 = V_84 ;
break;
case 12 :
V_77 = V_85 ;
break;
case 16 :
V_77 = V_86 ;
break;
case 32 :
V_77 = V_87 ;
break;
default:
V_77 = V_88 ;
break;
}
* V_4 = V_77 ;
F_26 ( V_2 , L_28 , V_77 ) ;
return V_17 ;
}
int F_54 ( struct V_1 * V_2 )
{
T_1 V_32 , V_33 ;
V_32 = V_89 ;
if ( F_55 ( V_2 ) )
V_32 |= V_90 ;
if ( F_56 ( V_2 ) )
V_32 |= V_91 ;
if ( ! V_19 )
V_32 |= V_40 | V_41 ;
V_33 = ( V_89 | V_90 |
V_91 | V_92 |
V_40 | V_41 ) ;
if ( F_27 ( V_2 , V_32 , V_33 ) ) {
F_17 ( V_2 , L_29 ) ;
return - 1 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_1 V_33 ;
V_33 = ( V_89 | V_90 |
V_91 | V_92 |
V_40 | V_41 |
V_93 ) ;
if ( F_27 ( V_2 , 0 , V_33 ) )
F_58 ( V_2 , L_30 ) ;
}
int F_59 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) )
return - 1 ;
if ( F_54 ( V_2 ) ) {
F_18 ( V_2 ) ;
return - 1 ;
}
V_2 -> V_94 = 1 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 ) {
F_57 ( V_2 ) ;
F_18 ( V_2 ) ;
V_2 -> V_94 = 0 ;
}
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_52 * V_52 ;
V_52 = F_62 ( sizeof( * V_52 ) , V_95 ) ;
if ( ! V_52 )
return - V_96 ;
V_52 -> V_2 = V_2 ;
F_63 ( & V_52 -> V_97 ) ;
F_64 ( & V_52 -> V_98 , V_99 ) ;
V_2 -> V_52 = V_52 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_52 * V_52 = V_2 -> V_52 ;
F_66 ( & V_52 -> V_98 ) ;
F_67 ( V_100 ) ;
F_67 ( V_101 ) ;
F_68 ( V_52 ) ;
}
static inline void F_69 ( struct V_1 * V_2 )
{
int V_102 ;
T_1 V_103 ;
struct V_5 * V_104 = V_2 -> V_7 -> V_8 ;
if ( ! V_105 )
return;
F_70 ( V_2 , L_31 ) ;
F_70 ( V_2 , L_32 ,
F_71 ( V_104 ) , V_104 -> V_18 ) ;
F_70 ( V_2 , L_33 , V_104 -> V_106 ) ;
F_70 ( V_2 , L_34 , V_104 -> V_107 ) ;
F_70 ( V_2 , L_35 ,
V_104 -> V_108 ) ;
F_70 ( V_2 , L_36 ,
V_104 -> V_109 ) ;
F_70 ( V_2 , L_37 ,
F_3 ( V_104 ) ) ;
for ( V_102 = 0 ; V_102 < V_110 ; V_102 ++ ) {
if ( ! F_72 ( V_104 , V_102 ) )
continue;
F_70 ( V_2 , L_38 ,
V_102 , & V_104 -> V_111 [ V_102 ] ) ;
}
F_70 ( V_2 , L_39 , V_2 -> V_112 ) ;
F_70 ( V_2 , L_40 , F_73 ( V_2 ) ) ;
F_70 ( V_2 , L_41 ,
F_55 ( V_2 ) ? L_42 : L_43 ) ;
F_70 ( V_2 , L_44 ,
F_74 ( V_2 ) ? L_42 : L_43 ) ;
F_70 ( V_2 , L_45 ,
F_56 ( V_2 ) ? L_42 : L_43 ) ;
F_70 ( V_2 , L_46 ,
F_75 ( V_2 ) ? L_42 : L_43 ) ;
F_70 ( V_2 , L_47 ,
F_76 ( V_2 ) ? L_42 : L_43 ) ;
F_70 ( V_2 , L_48 ,
F_77 ( V_2 ) ? L_42 : L_43 ) ;
F_70 ( V_2 , L_49 ,
F_78 ( V_2 ) ? L_42 : L_43 ) ;
F_70 ( V_2 , L_50 ,
F_29 ( V_2 ) ? L_43 : L_42 ) ;
F_1 ( V_2 , V_25 , & V_103 ) ;
F_70 ( V_2 , L_51 , V_103 ) ;
F_1 ( V_2 , V_39 , & V_103 ) ;
F_70 ( V_2 , L_52 , V_103 ) ;
}
struct V_1 * F_79 ( struct V_113 * V_6 )
{
struct V_1 * V_2 ;
T_2 V_112 , V_114 ;
struct V_5 * V_104 = V_6 -> V_8 ;
V_2 = F_62 ( sizeof( * V_2 ) , V_95 ) ;
if ( ! V_2 ) {
F_80 ( & V_6 -> V_107 , L_53 , V_36 ) ;
goto abort;
}
V_2 -> V_7 = V_6 ;
if ( ! F_3 ( V_104 ) ) {
F_17 ( V_2 , L_54 ) ;
goto V_115;
}
if ( F_4 ( V_2 , V_116 , & V_112 ) ) {
F_17 ( V_2 , L_55 ) ;
goto V_115;
}
V_2 -> V_112 = V_112 ;
F_63 ( & V_2 -> V_35 ) ;
F_81 ( & V_2 -> V_30 ) ;
F_69 ( V_2 ) ;
if ( F_29 ( V_2 ) ||
! ( F_74 ( V_2 ) | F_75 ( V_2 ) | F_76 ( V_2 ) | F_78 ( V_2 ) ) )
V_2 -> V_38 = 1 ;
if ( F_4 ( V_2 , V_79 , & V_114 ) ) {
F_17 ( V_2 , L_25 , V_36 ) ;
goto V_115;
}
if ( V_114 & V_117 ) {
F_26 ( V_2 , L_56 ) ;
V_2 -> V_46 = 1 ;
}
if ( F_6 ( V_2 , V_25 , 0x1f ) )
goto V_115;
F_57 ( V_2 ) ;
F_70 ( V_2 , L_57 ,
V_104 -> V_106 , V_104 -> V_107 , V_104 -> V_109 ,
V_104 -> V_108 ) ;
if ( F_61 ( V_2 ) )
goto V_115;
return V_2 ;
V_115:
F_68 ( V_2 ) ;
abort:
return NULL ;
}
void F_82 ( struct V_1 * V_2 )
{
F_60 ( V_2 ) ;
F_65 ( V_2 ) ;
F_68 ( V_2 ) ;
}
