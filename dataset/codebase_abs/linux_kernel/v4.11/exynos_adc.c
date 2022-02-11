static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_4 ( V_2 -> V_6 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_8 , L_1 , V_7 ) ;
return V_7 ;
}
if ( V_2 -> V_3 -> V_4 ) {
V_7 = F_4 ( V_2 -> V_5 ) ;
if ( V_7 ) {
F_2 ( V_2 -> V_6 ) ;
F_5 ( V_2 -> V_8 ,
L_2 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
F_7 ( V_2 -> V_5 ) ;
F_7 ( V_2 -> V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_9 ( V_2 -> V_6 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_8 , L_3 , V_7 ) ;
return V_7 ;
}
if ( V_2 -> V_3 -> V_4 ) {
V_7 = F_9 ( V_2 -> V_5 ) ;
if ( V_7 ) {
F_7 ( V_2 -> V_6 ) ;
F_5 ( V_2 -> V_8 ,
L_4 , V_7 ) ;
return V_7 ;
}
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_9 ;
if ( V_2 -> V_3 -> V_10 )
F_11 ( V_2 -> V_11 , V_2 -> V_3 -> V_12 , 1 ) ;
V_9 = F_12 ( 49 ) | V_13 ;
V_9 |= V_14 ;
F_13 ( V_9 , F_14 ( V_2 -> V_15 ) ) ;
F_13 ( V_2 -> V_16 , F_15 ( V_2 -> V_15 ) ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_17 ;
if ( V_2 -> V_3 -> V_10 )
F_11 ( V_2 -> V_11 , V_2 -> V_3 -> V_12 , 0 ) ;
V_17 = F_17 ( F_14 ( V_2 -> V_15 ) ) ;
V_17 |= V_18 ;
F_13 ( V_17 , F_14 ( V_2 -> V_15 ) ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_13 ( 1 , F_19 ( V_2 -> V_15 ) ) ;
}
static void F_20 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
T_1 V_9 ;
F_13 ( V_19 , F_21 ( V_2 -> V_15 ) ) ;
V_9 = F_17 ( F_14 ( V_2 -> V_15 ) ) ;
F_13 ( V_9 | V_20 , F_14 ( V_2 -> V_15 ) ) ;
}
static void F_22 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
T_1 V_9 ;
V_9 = F_17 ( F_14 ( V_2 -> V_15 ) ) ;
V_9 |= V_21 ;
F_13 ( V_9 , F_14 ( V_2 -> V_15 ) ) ;
F_13 ( V_19 , F_23 ( V_2 -> V_15 ) ) ;
V_9 = F_17 ( F_14 ( V_2 -> V_15 ) ) ;
F_13 ( V_9 | V_20 , F_14 ( V_2 -> V_15 ) ) ;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
T_1 V_9 ;
F_13 ( V_19 , F_23 ( V_2 -> V_15 ) ) ;
V_9 = F_17 ( F_14 ( V_2 -> V_15 ) ) ;
F_13 ( V_9 | V_20 , F_14 ( V_2 -> V_15 ) ) ;
}
static void F_25 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
T_1 V_9 ;
V_9 = F_17 ( F_14 ( V_2 -> V_15 ) ) ;
V_9 &= ~ F_26 ( 0x7 ) ;
V_9 |= F_26 ( V_19 ) ;
F_13 ( V_9 | V_20 , F_14 ( V_2 -> V_15 ) ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 V_9 , V_22 ;
if ( V_2 -> V_3 -> V_10 )
F_11 ( V_2 -> V_11 , V_2 -> V_3 -> V_12 , 1 ) ;
V_9 = V_23 ;
F_13 ( V_9 , F_28 ( V_2 -> V_15 ) ) ;
V_22 = V_24 | V_25 |
V_26 | F_29 ( 0 ) ;
F_13 ( V_22 , F_30 ( V_2 -> V_15 ) ) ;
F_13 ( 1 , F_31 ( V_2 -> V_15 ) ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_17 ;
if ( V_2 -> V_3 -> V_10 )
F_11 ( V_2 -> V_11 , V_2 -> V_3 -> V_12 , 0 ) ;
V_17 = F_17 ( F_28 ( V_2 -> V_15 ) ) ;
V_17 &= ~ V_20 ;
F_13 ( V_17 , F_28 ( V_2 -> V_15 ) ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_13 ( 1 , F_34 ( V_2 -> V_15 ) ) ;
}
static void F_35 ( struct V_1 * V_2 ,
unsigned long V_19 )
{
T_1 V_9 , V_22 ;
V_22 = F_17 ( F_30 ( V_2 -> V_15 ) ) ;
V_22 &= ~ V_27 ;
V_22 |= F_36 ( V_19 ) ;
F_13 ( V_22 , F_30 ( V_2 -> V_15 ) ) ;
V_9 = F_17 ( F_28 ( V_2 -> V_15 ) ) ;
F_13 ( V_9 | V_20 , F_28 ( V_2 -> V_15 ) ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
T_1 V_9 , V_22 ;
if ( V_2 -> V_3 -> V_10 )
F_11 ( V_2 -> V_11 , V_2 -> V_3 -> V_12 , 1 ) ;
V_9 = V_23 ;
F_13 ( V_9 , F_28 ( V_2 -> V_15 ) ) ;
V_22 = F_17 ( F_30 ( V_2 -> V_15 ) ) ;
V_22 &= ~ F_29 ( 7 ) ;
V_22 |= F_29 ( 0 ) ;
F_13 ( V_22 , F_30 ( V_2 -> V_15 ) ) ;
F_13 ( 1 , F_31 ( V_2 -> V_15 ) ) ;
}
static struct V_28 * F_38 ( struct V_29 * V_30 )
{
const struct V_31 * V_32 ;
V_32 = F_39 ( V_33 , V_30 -> V_8 . V_34 ) ;
return (struct V_28 * ) V_32 -> V_3 ;
}
static int F_40 ( struct V_35 * V_36 ,
struct V_37 const * V_38 ,
int * V_39 ,
int * V_40 ,
long V_41 )
{
struct V_1 * V_2 = F_41 ( V_36 ) ;
unsigned long V_42 ;
int V_7 ;
if ( V_41 != V_43 )
return - V_44 ;
F_42 ( & V_36 -> V_45 ) ;
F_43 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_3 -> V_47 )
V_2 -> V_3 -> V_47 ( V_2 , V_38 -> V_48 ) ;
V_42 = F_44 ( & V_2 -> V_46 ,
V_49 ) ;
if ( V_42 == 0 ) {
F_45 ( & V_36 -> V_8 , L_5 ) ;
if ( V_2 -> V_3 -> V_50 )
V_2 -> V_3 -> V_50 ( V_2 ) ;
V_7 = - V_51 ;
} else {
* V_39 = V_2 -> V_52 ;
* V_40 = 0 ;
V_7 = V_53 ;
}
F_46 ( & V_36 -> V_45 ) ;
return V_7 ;
}
static int F_47 ( struct V_35 * V_36 , int * V_54 , int * V_55 )
{
struct V_1 * V_2 = F_41 ( V_36 ) ;
unsigned long V_42 ;
int V_7 ;
F_42 ( & V_36 -> V_45 ) ;
V_2 -> V_56 = true ;
F_43 ( & V_2 -> V_46 ) ;
F_13 ( V_57 | V_58 ,
F_48 ( V_2 -> V_15 ) ) ;
V_2 -> V_3 -> V_47 ( V_2 , V_59 ) ;
V_42 = F_44 ( & V_2 -> V_46 ,
V_49 ) ;
if ( V_42 == 0 ) {
F_45 ( & V_36 -> V_8 , L_5 ) ;
if ( V_2 -> V_3 -> V_50 )
V_2 -> V_3 -> V_50 ( V_2 ) ;
V_7 = - V_51 ;
} else {
* V_54 = V_2 -> V_60 ;
* V_55 = V_2 -> V_61 ;
V_7 = 0 ;
}
V_2 -> V_56 = false ;
F_46 ( & V_36 -> V_45 ) ;
return V_7 ;
}
static T_2 F_49 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = (struct V_1 * ) V_63 ;
T_1 V_41 = V_2 -> V_3 -> V_41 ;
if ( V_2 -> V_56 ) {
V_2 -> V_60 = F_17 ( F_50 ( V_2 -> V_15 ) ) ;
V_2 -> V_61 = F_17 ( F_51 ( V_2 -> V_15 ) ) ;
F_13 ( V_64 | V_65 , F_48 ( V_2 -> V_15 ) ) ;
} else {
V_2 -> V_52 = F_17 ( F_50 ( V_2 -> V_15 ) ) & V_41 ;
}
if ( V_2 -> V_3 -> V_66 )
V_2 -> V_3 -> V_66 ( V_2 ) ;
F_52 ( & V_2 -> V_46 ) ;
return V_67 ;
}
static T_2 F_53 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_35 * V_8 = F_54 ( V_2 -> V_8 ) ;
T_1 V_54 , V_55 ;
bool V_68 ;
int V_7 ;
while ( V_2 -> V_69 -> V_70 ) {
V_7 = F_47 ( V_8 , & V_54 , & V_55 ) ;
if ( V_7 == - V_51 )
break;
V_68 = V_54 & V_55 & V_71 ;
if ( ! V_68 ) {
F_55 ( V_2 -> V_69 , V_72 , 0 ) ;
F_56 ( V_2 -> V_69 ) ;
break;
}
F_57 ( V_2 -> V_69 , V_73 , V_54 & V_74 ) ;
F_57 ( V_2 -> V_69 , V_75 , V_55 & V_76 ) ;
F_55 ( V_2 -> V_69 , V_72 , 1 ) ;
F_56 ( V_2 -> V_69 ) ;
F_58 ( 1000 , 1100 ) ;
} ;
F_13 ( 0 , F_59 ( V_2 -> V_15 ) ) ;
return V_67 ;
}
static int F_60 ( struct V_35 * V_36 ,
unsigned V_77 , unsigned V_78 ,
unsigned * V_79 )
{
struct V_1 * V_2 = F_41 ( V_36 ) ;
if ( V_79 == NULL )
return - V_44 ;
* V_79 = F_17 ( V_2 -> V_15 + V_77 ) ;
return 0 ;
}
static int F_61 ( struct V_80 * V_8 , void * V_81 )
{
struct V_29 * V_30 = F_62 ( V_8 ) ;
F_63 ( V_30 ) ;
return 0 ;
}
static int F_64 ( struct V_82 * V_8 )
{
struct V_1 * V_2 = F_65 ( V_8 ) ;
F_66 ( V_2 -> V_83 ) ;
return 0 ;
}
static void F_67 ( struct V_82 * V_8 )
{
struct V_1 * V_2 = F_65 ( V_8 ) ;
F_68 ( V_2 -> V_83 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_83 <= 0 )
return - V_84 ;
V_2 -> V_69 = F_70 () ;
if ( ! V_2 -> V_69 )
return - V_85 ;
V_2 -> V_69 -> V_86 [ 0 ] = F_71 ( V_87 ) | F_71 ( V_88 ) ;
V_2 -> V_69 -> V_89 [ F_72 ( V_72 ) ] = F_71 ( V_72 ) ;
F_73 ( V_2 -> V_69 , V_73 , 0 , 0x3FF , 0 , 0 ) ;
F_73 ( V_2 -> V_69 , V_75 , 0 , 0x3FF , 0 , 0 ) ;
V_2 -> V_69 -> V_90 = L_6 ;
V_2 -> V_69 -> V_91 . V_92 = V_93 ;
V_2 -> V_69 -> V_94 = F_64 ;
V_2 -> V_69 -> V_95 = F_67 ;
F_74 ( V_2 -> V_69 , V_2 ) ;
V_7 = F_75 ( V_2 -> V_69 ) ;
if ( V_7 ) {
F_76 ( V_2 -> V_69 ) ;
return V_7 ;
}
F_68 ( V_2 -> V_83 ) ;
V_7 = F_77 ( V_2 -> V_83 , NULL , F_53 ,
V_96 , L_7 , V_2 ) ;
if ( V_7 )
F_78 ( V_2 -> V_69 ) ;
return V_7 ;
}
static int F_79 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = NULL ;
struct V_97 * V_98 = V_30 -> V_8 . V_34 ;
struct V_99 * V_100 = F_80 ( & V_30 -> V_8 ) ;
struct V_35 * V_36 = NULL ;
struct V_101 * V_102 ;
bool V_103 = false ;
int V_7 = - V_84 ;
int V_62 ;
V_36 = F_81 ( & V_30 -> V_8 , sizeof( struct V_1 ) ) ;
if ( ! V_36 ) {
F_5 ( & V_30 -> V_8 , L_8 ) ;
return - V_85 ;
}
V_2 = F_41 ( V_36 ) ;
V_2 -> V_3 = F_38 ( V_30 ) ;
if ( ! V_2 -> V_3 ) {
F_5 ( & V_30 -> V_8 , L_9 ) ;
return - V_44 ;
}
V_102 = F_82 ( V_30 , V_104 , 0 ) ;
V_2 -> V_15 = F_83 ( & V_30 -> V_8 , V_102 ) ;
if ( F_84 ( V_2 -> V_15 ) )
return F_85 ( V_2 -> V_15 ) ;
if ( V_2 -> V_3 -> V_10 ) {
V_2 -> V_11 = F_86 (
V_30 -> V_8 . V_34 ,
L_10 ) ;
if ( F_84 ( V_2 -> V_11 ) ) {
F_5 ( & V_30 -> V_8 , L_11 ) ;
return F_85 ( V_2 -> V_11 ) ;
}
}
V_62 = F_87 ( V_30 , 0 ) ;
if ( V_62 < 0 ) {
F_5 ( & V_30 -> V_8 , L_12 ) ;
return V_62 ;
}
V_2 -> V_62 = V_62 ;
V_62 = F_87 ( V_30 , 1 ) ;
if ( V_62 == - V_105 )
return V_62 ;
V_2 -> V_83 = V_62 ;
V_2 -> V_8 = & V_30 -> V_8 ;
F_88 ( & V_2 -> V_46 ) ;
V_2 -> V_6 = F_89 ( & V_30 -> V_8 , L_13 ) ;
if ( F_84 ( V_2 -> V_6 ) ) {
F_5 ( & V_30 -> V_8 , L_14 ,
F_85 ( V_2 -> V_6 ) ) ;
return F_85 ( V_2 -> V_6 ) ;
}
if ( V_2 -> V_3 -> V_4 ) {
V_2 -> V_5 = F_89 ( & V_30 -> V_8 , L_15 ) ;
if ( F_84 ( V_2 -> V_5 ) ) {
F_5 ( & V_30 -> V_8 ,
L_16 ,
F_85 ( V_2 -> V_5 ) ) ;
return F_85 ( V_2 -> V_5 ) ;
}
}
V_2 -> V_106 = F_90 ( & V_30 -> V_8 , L_17 ) ;
if ( F_84 ( V_2 -> V_106 ) ) {
F_5 ( & V_30 -> V_8 , L_18 ,
F_85 ( V_2 -> V_106 ) ) ;
return F_85 ( V_2 -> V_106 ) ;
}
V_7 = F_91 ( V_2 -> V_106 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 ) ;
if ( V_7 )
goto V_107;
V_7 = F_8 ( V_2 ) ;
if ( V_7 )
goto V_108;
F_92 ( V_30 , V_36 ) ;
V_36 -> V_90 = F_93 ( & V_30 -> V_8 ) ;
V_36 -> V_8 . V_109 = & V_30 -> V_8 ;
V_36 -> V_8 . V_34 = V_30 -> V_8 . V_34 ;
V_36 -> V_2 = & V_110 ;
V_36 -> V_111 = V_112 ;
V_36 -> V_113 = V_114 ;
V_36 -> V_115 = V_2 -> V_3 -> V_115 ;
V_7 = F_94 ( V_2 -> V_62 , F_49 ,
0 , F_93 ( & V_30 -> V_8 ) , V_2 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_30 -> V_8 , L_19 ,
V_2 -> V_62 ) ;
goto V_116;
}
V_7 = F_95 ( V_36 ) ;
if ( V_7 )
goto V_117;
if ( V_2 -> V_3 -> V_50 )
V_2 -> V_3 -> V_50 ( V_2 ) ;
if ( F_96 ( V_118 ) ) {
V_103 = F_97 ( V_30 -> V_8 . V_34 ,
L_20 ) || V_100 ;
}
if ( V_100 )
V_2 -> V_16 = V_100 -> V_16 ;
else
V_2 -> V_16 = 10000 ;
if ( V_103 )
V_7 = F_69 ( V_2 ) ;
if ( V_7 )
goto V_119;
V_7 = F_98 ( V_98 , V_33 , NULL , & V_36 -> V_8 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_30 -> V_8 , L_21 ) ;
goto V_120;
}
return 0 ;
V_120:
F_99 ( & V_36 -> V_8 , NULL ,
F_61 ) ;
if ( V_103 ) {
F_78 ( V_2 -> V_69 ) ;
F_100 ( V_2 -> V_83 , V_2 ) ;
}
V_119:
F_101 ( V_36 ) ;
V_117:
F_100 ( V_2 -> V_62 , V_2 ) ;
V_116:
if ( V_2 -> V_3 -> V_121 )
V_2 -> V_3 -> V_121 ( V_2 ) ;
F_6 ( V_2 ) ;
V_108:
F_1 ( V_2 ) ;
V_107:
F_102 ( V_2 -> V_106 ) ;
return V_7 ;
}
static int F_103 ( struct V_29 * V_30 )
{
struct V_35 * V_36 = F_104 ( V_30 ) ;
struct V_1 * V_2 = F_41 ( V_36 ) ;
if ( F_96 ( V_118 ) ) {
F_100 ( V_2 -> V_83 , V_2 ) ;
F_78 ( V_2 -> V_69 ) ;
}
F_99 ( & V_36 -> V_8 , NULL ,
F_61 ) ;
F_101 ( V_36 ) ;
F_100 ( V_2 -> V_62 , V_2 ) ;
if ( V_2 -> V_3 -> V_121 )
V_2 -> V_3 -> V_121 ( V_2 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 ) ;
F_102 ( V_2 -> V_106 ) ;
return 0 ;
}
static int F_105 ( struct V_80 * V_8 )
{
struct V_35 * V_36 = F_54 ( V_8 ) ;
struct V_1 * V_2 = F_41 ( V_36 ) ;
if ( V_2 -> V_3 -> V_121 )
V_2 -> V_3 -> V_121 ( V_2 ) ;
F_6 ( V_2 ) ;
F_102 ( V_2 -> V_106 ) ;
return 0 ;
}
static int F_106 ( struct V_80 * V_8 )
{
struct V_35 * V_36 = F_54 ( V_8 ) ;
struct V_1 * V_2 = F_41 ( V_36 ) ;
int V_7 ;
V_7 = F_91 ( V_2 -> V_106 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_8 ( V_2 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_3 -> V_50 )
V_2 -> V_3 -> V_50 ( V_2 ) ;
return 0 ;
}
