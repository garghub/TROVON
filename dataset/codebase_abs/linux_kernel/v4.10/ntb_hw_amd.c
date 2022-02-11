static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 || V_3 > V_2 -> V_4 )
return - V_5 ;
return 1 << V_3 ;
}
static int F_2 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_4 ;
}
static int F_4 ( struct V_6 * V_7 , int V_3 ,
T_1 * V_8 ,
T_2 * V_9 ,
T_2 * V_10 ,
T_2 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_12 ;
V_12 = F_1 ( V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_8 )
* V_8 = F_5 ( V_2 -> V_7 . V_13 , V_12 ) ;
if ( V_9 )
* V_9 = F_6 ( V_2 -> V_7 . V_13 , V_12 ) ;
if ( V_10 )
* V_10 = V_14 ;
if ( V_11 )
* V_11 = 1 ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , int V_3 ,
T_3 V_15 , T_2 V_9 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned long V_16 , V_17 = 0 ;
T_2 V_18 ;
void T_4 * V_19 , * V_20 ;
T_5 V_21 , V_22 , V_23 ;
int V_12 ;
V_12 = F_1 ( V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
V_18 = F_6 ( V_2 -> V_7 . V_13 , V_12 ) ;
if ( V_9 > V_18 )
return - V_5 ;
V_19 = V_2 -> V_24 ;
V_20 = V_2 -> V_20 ;
V_21 = F_5 ( V_2 -> V_7 . V_13 , V_12 ) ;
if ( V_12 != 1 ) {
V_16 = V_25 + ( ( V_12 - 2 ) << 2 ) ;
V_17 = V_26 + ( ( V_12 - 2 ) << 2 ) ;
V_22 = V_9 ;
F_8 ( V_15 , V_20 + V_16 ) ;
V_23 = F_9 ( V_20 + V_16 ) ;
if ( V_23 != V_15 ) {
F_8 ( 0 , V_20 + V_16 ) ;
return - V_27 ;
}
F_8 ( V_22 , V_19 + V_17 ) ;
V_23 = F_9 ( V_19 + V_17 ) ;
if ( V_23 != V_22 ) {
F_8 ( V_21 , V_19 + V_17 ) ;
F_8 ( 0 , V_20 + V_16 ) ;
return - V_27 ;
}
} else {
V_16 = V_28 ;
V_17 = V_29 ;
V_22 = V_9 ;
F_8 ( V_15 , V_20 + V_16 ) ;
V_23 = F_9 ( V_20 + V_16 ) ;
if ( V_23 != V_15 ) {
F_8 ( 0 , V_20 + V_16 ) ;
return - V_27 ;
}
F_10 ( V_22 , V_19 + V_17 ) ;
V_23 = F_11 ( V_19 + V_17 ) ;
if ( V_23 != V_22 ) {
F_10 ( V_21 , V_19 + V_17 ) ;
F_10 ( 0 , V_20 + V_16 ) ;
return - V_27 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_30 )
return F_13 ( V_2 -> V_31 ) ;
if ( V_2 -> V_30 & V_32 ) {
V_2 -> V_30 = 0 ;
return 1 ;
}
if ( V_2 -> V_30 & V_33 )
V_2 -> V_30 &= ~ V_33 ;
else if ( V_2 -> V_30 & ( V_34 | V_35 ) )
V_2 -> V_30 = 0 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
enum V_36 * V_37 ,
enum V_38 * V_39 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_40 = 0 ;
if ( F_12 ( V_2 ) ) {
if ( V_37 )
* V_37 = F_15 ( V_2 -> V_41 ) ;
if ( V_39 )
* V_39 = F_16 ( V_2 -> V_41 ) ;
F_17 ( F_18 ( V_2 ) , L_1 ) ;
V_40 = 1 ;
} else {
if ( V_37 )
* V_37 = V_42 ;
if ( V_39 )
* V_39 = V_43 ;
F_17 ( F_18 ( V_2 ) , L_2 ) ;
}
return V_40 ;
}
static int F_19 ( struct V_6 * V_7 ,
enum V_36 V_44 ,
enum V_38 V_45 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_46 ;
V_2 -> V_47 &= ~ V_48 ;
F_10 ( V_2 -> V_47 , V_19 + V_49 ) ;
if ( V_2 -> V_7 . V_50 == V_51 )
return - V_5 ;
F_17 ( F_18 ( V_2 ) , L_3 ) ;
V_46 = F_11 ( V_19 + V_52 ) ;
V_46 |= ( V_53 | V_54 ) ;
F_10 ( V_46 , V_19 + V_52 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_46 ;
V_2 -> V_47 |= V_48 ;
F_10 ( V_2 -> V_47 , V_19 + V_49 ) ;
if ( V_2 -> V_7 . V_50 == V_51 )
return - V_5 ;
F_17 ( F_18 ( V_2 ) , L_3 ) ;
V_46 = F_11 ( V_19 + V_52 ) ;
V_46 &= ~ ( V_53 | V_54 ) ;
F_10 ( V_46 , V_19 + V_52 ) ;
return 0 ;
}
static T_5 F_21 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_55 ;
}
static int F_22 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_56 ;
}
static T_5 F_23 ( struct V_6 * V_7 , int V_57 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( V_57 < 0 || V_57 > V_2 -> V_56 )
return 0 ;
return F_3 ( V_7 ) -> V_55 & ( 1 << V_57 ) ;
}
static T_5 F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
return ( T_5 ) F_25 ( V_19 + V_58 ) ;
}
static int F_26 ( struct V_6 * V_7 , T_5 V_59 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
F_27 ( ( V_60 ) V_59 , V_19 + V_58 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 , T_5 V_59 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
unsigned long V_61 ;
if ( V_59 & ~ V_2 -> V_55 )
return - V_5 ;
F_29 ( & V_2 -> V_62 , V_61 ) ;
V_2 -> V_63 |= V_59 ;
F_27 ( ( V_60 ) V_2 -> V_63 , V_19 + V_64 ) ;
F_30 ( & V_2 -> V_62 , V_61 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , T_5 V_59 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
unsigned long V_61 ;
if ( V_59 & ~ V_2 -> V_55 )
return - V_5 ;
F_29 ( & V_2 -> V_62 , V_61 ) ;
V_2 -> V_63 &= ~ V_59 ;
F_27 ( ( V_60 ) V_2 -> V_63 , V_19 + V_64 ) ;
F_30 ( & V_2 -> V_62 , V_61 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , T_5 V_59 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
F_27 ( ( V_60 ) V_59 , V_19 + V_65 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_66 ;
}
static T_6 F_34 ( struct V_6 * V_7 , int V_3 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_67 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return 0 ;
V_67 = V_2 -> V_68 + ( V_3 << 2 ) ;
return F_11 ( V_19 + V_69 + V_67 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
int V_3 , T_6 V_70 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_67 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return - V_5 ;
V_67 = V_2 -> V_68 + ( V_3 << 2 ) ;
F_10 ( V_70 , V_19 + V_69 + V_67 ) ;
return 0 ;
}
static T_6 F_36 ( struct V_6 * V_7 , int V_3 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_67 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return - V_5 ;
V_67 = V_2 -> V_71 + ( V_3 << 2 ) ;
return F_11 ( V_19 + V_69 + V_67 ) ;
}
static int F_37 ( struct V_6 * V_7 ,
int V_3 , T_6 V_70 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_67 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return - V_5 ;
V_67 = V_2 -> V_71 + ( V_3 << 2 ) ;
F_10 ( V_70 , V_19 + V_69 + V_67 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , T_6 V_72 )
{
void T_4 * V_19 = V_2 -> V_24 ;
int V_73 ;
V_73 = F_11 ( V_19 + V_74 ) ;
V_73 |= V_72 ;
F_10 ( V_73 , V_19 + V_74 ) ;
V_2 -> V_30 |= V_72 ;
}
static void F_39 ( struct V_1 * V_2 , int V_75 )
{
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_76 ;
V_76 = F_11 ( V_19 + V_77 ) ;
if ( ! ( V_76 & V_48 ) )
return;
F_17 ( F_18 ( V_2 ) , L_4 , V_76 , V_75 ) ;
V_76 &= V_48 ;
switch ( V_76 ) {
case V_78 :
F_40 ( F_18 ( V_2 ) , L_5 ) ;
break;
case V_33 :
F_38 ( V_2 , V_33 ) ;
F_41 ( & V_2 -> V_7 ) ;
F_42 ( & V_2 -> V_79 , V_80 ) ;
break;
case V_81 :
case V_82 :
case V_32 :
case V_35 :
F_38 ( V_2 , V_76 ) ;
F_41 ( & V_2 -> V_7 ) ;
break;
case V_34 :
V_19 = V_2 -> V_20 ;
V_76 = F_11 ( V_19 + V_83 ) ;
if ( V_76 & 0x1 )
F_40 ( F_18 ( V_2 ) , L_6 ) ;
F_38 ( V_2 , V_34 ) ;
F_42 ( & V_2 -> V_79 ,
V_80 ) ;
break;
default:
F_40 ( F_18 ( V_2 ) , L_7 , V_76 ) ;
break;
}
}
static T_7 F_43 ( struct V_1 * V_2 , int V_75 )
{
F_17 ( F_18 ( V_2 ) , L_8 , V_75 ) ;
if ( V_75 > ( V_84 - 1 ) || ( V_2 -> V_85 == 1 ) )
F_39 ( V_2 , V_75 ) ;
if ( V_75 < V_84 )
F_44 ( & V_2 -> V_7 , V_75 ) ;
return V_86 ;
}
static T_7 F_45 ( int V_87 , void * V_88 )
{
struct V_89 * V_90 = V_88 ;
return F_43 ( V_90 -> V_2 , V_90 -> V_91 ) ;
}
static T_7 F_46 ( int V_87 , void * V_88 )
{
struct V_1 * V_2 = V_88 ;
return F_43 ( V_2 , V_87 - F_47 ( V_2 ) -> V_87 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_92 , int V_93 )
{
struct V_94 * V_13 ;
int V_95 , V_96 , V_97 , V_98 ;
V_13 = F_47 ( V_2 ) ;
V_98 = F_49 ( & V_13 -> V_88 ) ;
V_2 -> V_63 = V_2 -> V_55 ;
V_2 -> V_75 = F_50 ( V_93 * sizeof( * V_2 -> V_75 ) ,
V_99 , V_98 ) ;
if ( ! V_2 -> V_75 )
goto V_100;
V_2 -> V_101 = F_50 ( V_93 * sizeof( * V_2 -> V_101 ) ,
V_99 , V_98 ) ;
if ( ! V_2 -> V_101 )
goto V_102;
for ( V_96 = 0 ; V_96 < V_93 ; ++ V_96 )
V_2 -> V_101 [ V_96 ] . V_103 = V_96 ;
V_97 = F_51 ( V_13 , V_2 -> V_101 ,
V_92 , V_93 ) ;
if ( V_97 < 0 )
goto V_104;
if ( V_97 < V_92 ) {
F_52 ( V_13 ) ;
goto V_104;
}
for ( V_96 = 0 ; V_96 < V_97 ; ++ V_96 ) {
V_2 -> V_75 [ V_96 ] . V_2 = V_2 ;
V_2 -> V_75 [ V_96 ] . V_91 = V_96 ;
V_95 = F_53 ( V_2 -> V_101 [ V_96 ] . V_105 , F_45 , 0 ,
L_9 , & V_2 -> V_75 [ V_96 ] ) ;
if ( V_95 )
goto V_106;
}
F_17 ( F_18 ( V_2 ) , L_10 ) ;
V_2 -> V_56 = V_92 ;
V_2 -> V_85 = V_93 ;
return 0 ;
V_106:
while ( V_96 -- > 0 )
F_54 ( V_2 -> V_101 [ V_96 ] . V_105 , & V_2 -> V_75 [ V_96 ] ) ;
F_52 ( V_13 ) ;
V_104:
F_55 ( V_2 -> V_101 ) ;
V_102:
F_55 ( V_2 -> V_75 ) ;
V_100:
V_2 -> V_101 = NULL ;
V_2 -> V_75 = NULL ;
V_95 = F_56 ( V_13 ) ;
if ( V_95 )
goto V_107;
V_95 = F_53 ( V_13 -> V_87 , F_46 , 0 ,
L_11 , V_2 ) ;
if ( V_95 )
goto V_108;
F_17 ( F_18 ( V_2 ) , L_12 ) ;
V_2 -> V_56 = 1 ;
V_2 -> V_85 = 1 ;
return 0 ;
V_108:
F_57 ( V_13 ) ;
V_107:
F_58 ( V_13 , 1 ) ;
V_95 = F_53 ( V_13 -> V_87 , F_46 , V_109 ,
L_11 , V_2 ) ;
if ( V_95 )
goto V_110;
F_17 ( F_18 ( V_2 ) , L_13 ) ;
V_2 -> V_56 = 1 ;
V_2 -> V_85 = 1 ;
return 0 ;
V_110:
return V_95 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_94 * V_13 ;
void T_4 * V_19 = V_2 -> V_24 ;
int V_96 ;
V_13 = F_47 ( V_2 ) ;
V_2 -> V_63 = V_2 -> V_55 ;
F_10 ( V_2 -> V_63 , V_19 + V_64 ) ;
if ( V_2 -> V_101 ) {
V_96 = V_2 -> V_85 ;
while ( V_96 -- )
F_54 ( V_2 -> V_101 [ V_96 ] . V_105 , & V_2 -> V_75 [ V_96 ] ) ;
F_52 ( V_13 ) ;
F_55 ( V_2 -> V_101 ) ;
F_55 ( V_2 -> V_75 ) ;
} else {
F_54 ( V_13 -> V_87 , V_2 ) ;
if ( F_60 ( V_13 ) )
F_57 ( V_13 ) ;
else
F_58 ( V_13 , 0 ) ;
}
}
static T_8 F_61 ( struct V_111 * V_112 , char T_9 * V_113 ,
T_10 V_114 , T_11 * V_115 )
{
struct V_1 * V_2 ;
void T_4 * V_19 ;
char * V_116 ;
T_10 V_117 ;
T_8 V_40 , V_118 ;
union { T_5 V_119 ; T_6 V_120 ; V_60 V_121 ; } V_122 ;
V_2 = V_112 -> V_123 ;
V_19 = V_2 -> V_24 ;
V_117 = F_62 ( V_114 , 0x800ul ) ;
V_116 = F_63 ( V_117 , V_99 ) ;
if ( ! V_116 )
return - V_124 ;
V_118 = 0 ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_14 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_15 ,
F_65 ( V_2 -> V_7 . V_50 ) ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_16 , V_2 -> V_41 ) ;
if ( ! F_12 ( V_2 ) ) {
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_17 ) ;
} else {
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_18 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_19 ,
F_15 ( V_2 -> V_41 ) ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_20 ,
F_16 ( V_2 -> V_41 ) ) ;
}
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_21 , V_2 -> V_4 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_22 , V_2 -> V_66 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_23 , V_2 -> V_56 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_24 , V_2 -> V_85 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_25 , V_2 -> V_55 ) ;
V_122 . V_120 = F_11 ( V_2 -> V_24 + V_64 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_26 , V_122 . V_120 ) ;
V_122 . V_120 = F_11 ( V_19 + V_58 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_27 , V_122 . V_120 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_28 ) ;
V_122 . V_119 = F_9 ( V_19 + V_28 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_29 , V_122 . V_119 ) ;
V_122 . V_119 = F_9 ( V_2 -> V_24 + V_25 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_30 , V_122 . V_119 ) ;
V_122 . V_119 = F_9 ( V_2 -> V_24 + V_125 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_31 , V_122 . V_119 ) ;
V_122 . V_120 = F_11 ( V_19 + V_29 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_32 , V_122 . V_120 ) ;
V_122 . V_119 = F_9 ( V_2 -> V_24 + V_26 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_33 , V_122 . V_119 ) ;
V_122 . V_119 = F_9 ( V_2 -> V_24 + V_126 ) ;
V_118 += F_64 ( V_116 + V_118 , V_117 - V_118 ,
L_34 , V_122 . V_119 ) ;
V_40 = F_66 ( V_113 , V_114 , V_115 , V_116 , V_118 ) ;
F_55 ( V_116 ) ;
return V_40 ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( ! V_127 ) {
V_2 -> V_127 = NULL ;
V_2 -> V_128 = NULL ;
} else {
V_2 -> V_127 =
F_68 ( F_69 ( V_2 ) , V_127 ) ;
if ( ! V_2 -> V_127 )
V_2 -> V_128 = NULL ;
else
V_2 -> V_128 =
F_70 ( L_35 , V_129 ,
V_2 -> V_127 , V_2 ,
& V_130 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 -> V_127 ) ;
}
static inline void F_73 ( struct V_1 * V_2 ,
struct V_94 * V_13 )
{
V_2 -> V_7 . V_13 = V_13 ;
V_2 -> V_7 . V_50 = V_131 ;
V_2 -> V_7 . V_132 = & V_133 ;
V_2 -> V_47 = V_48 ;
F_74 ( & V_2 -> V_62 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_20 ;
T_6 V_73 , V_134 ;
int V_95 ;
V_73 = F_11 ( V_19 + V_135 ) ;
V_73 &= V_136 ;
F_17 ( F_18 ( V_2 ) , L_36 , V_137 , V_73 ) ;
if ( V_73 == V_2 -> V_31 )
return 0 ;
V_2 -> V_31 = V_73 ;
V_95 = F_76 ( V_2 -> V_7 . V_13 ,
V_138 , & V_134 ) ;
if ( V_95 )
return 0 ;
V_2 -> V_41 = V_134 ;
return 1 ;
}
static void F_77 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_78 ( V_140 ) ;
if ( F_75 ( V_2 ) )
F_41 ( & V_2 -> V_7 ) ;
if ( ! F_12 ( V_2 ) )
F_42 ( & V_2 -> V_79 , V_80 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return F_48 ( V_2 , V_84 , V_141 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
unsigned int V_73 ;
V_73 = F_11 ( V_19 + V_135 ) ;
if ( ! ( V_73 & V_142 ) ) {
V_73 |= V_142 ;
F_10 ( V_73 , V_19 + V_135 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
unsigned int V_73 ;
V_73 = F_11 ( V_19 + V_135 ) ;
if ( V_73 & V_142 ) {
V_73 &= ~ V_142 ;
F_10 ( V_73 , V_19 + V_135 ) ;
F_11 ( V_19 + V_135 ) ;
}
}
static int F_82 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
V_2 -> V_4 = V_143 ;
V_2 -> V_66 = V_144 ;
V_2 -> V_56 = V_84 ;
switch ( V_2 -> V_7 . V_50 ) {
case V_145 :
case V_51 :
V_2 -> V_66 >>= 1 ;
if ( V_2 -> V_7 . V_50 == V_145 ) {
V_2 -> V_68 = 0 ;
V_2 -> V_71 = 0x20 ;
} else {
V_2 -> V_68 = 0x20 ;
V_2 -> V_71 = 0 ;
}
F_83 ( & V_2 -> V_79 , F_77 ) ;
F_42 ( & V_2 -> V_79 , V_80 ) ;
break;
default:
F_84 ( F_18 ( V_2 ) , L_37 ) ;
return - V_5 ;
}
V_2 -> V_55 = F_85 ( V_2 -> V_56 ) - 1 ;
F_10 ( V_2 -> V_47 , V_19 + V_49 ) ;
return 0 ;
}
static enum V_146 F_86 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_147 ;
V_147 = F_11 ( V_19 + V_135 ) ;
if ( V_147 & V_148 )
return V_51 ;
else
return V_145 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_94 * V_13 ;
int V_95 = 0 ;
V_13 = F_47 ( V_2 ) ;
V_2 -> V_7 . V_50 = F_86 ( V_2 ) ;
F_17 ( F_18 ( V_2 ) , L_38 ,
F_65 ( V_2 -> V_7 . V_50 ) ) ;
V_95 = F_82 ( V_2 ) ;
if ( V_95 )
return V_95 ;
V_95 = F_79 ( V_2 ) ;
if ( V_95 ) {
F_84 ( F_18 ( V_2 ) , L_39 ) ;
return V_95 ;
}
V_2 -> V_55 = F_85 ( V_2 -> V_56 ) - 1 ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_89 ( & V_2 -> V_79 ) ;
F_59 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_94 * V_13 )
{
int V_95 ;
F_91 ( V_13 , V_2 ) ;
V_95 = F_92 ( V_13 ) ;
if ( V_95 )
goto V_149;
V_95 = F_93 ( V_13 , V_150 ) ;
if ( V_95 )
goto V_151;
F_94 ( V_13 ) ;
V_95 = F_95 ( V_13 , F_96 ( 64 ) ) ;
if ( V_95 ) {
V_95 = F_95 ( V_13 , F_96 ( 32 ) ) ;
if ( V_95 )
goto V_152;
F_97 ( F_18 ( V_2 ) , L_40 ) ;
}
V_95 = F_98 ( V_13 , F_96 ( 64 ) ) ;
if ( V_95 ) {
V_95 = F_98 ( V_13 , F_96 ( 32 ) ) ;
if ( V_95 )
goto V_152;
F_97 ( F_18 ( V_2 ) , L_41 ) ;
}
V_2 -> V_24 = F_99 ( V_13 , 0 , 0 ) ;
if ( ! V_2 -> V_24 ) {
V_95 = - V_27 ;
goto V_152;
}
V_2 -> V_20 = V_2 -> V_24 + V_153 ;
return 0 ;
V_152:
F_100 ( V_13 ) ;
V_151:
F_101 ( V_13 ) ;
V_149:
F_91 ( V_13 , NULL ) ;
return V_95 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_94 * V_13 = F_47 ( V_2 ) ;
F_103 ( V_13 , V_2 -> V_24 ) ;
F_100 ( V_13 ) ;
F_104 ( V_13 ) ;
F_101 ( V_13 ) ;
F_91 ( V_13 , NULL ) ;
}
static int F_105 ( struct V_94 * V_13 ,
const struct V_154 * V_155 )
{
struct V_1 * V_2 ;
int V_95 , V_98 ;
V_98 = F_49 ( & V_13 -> V_88 ) ;
V_2 = F_50 ( sizeof( * V_2 ) , V_99 , V_98 ) ;
if ( ! V_2 ) {
V_95 = - V_124 ;
goto V_156;
}
F_73 ( V_2 , V_13 ) ;
V_95 = F_90 ( V_2 , V_13 ) ;
if ( V_95 )
goto V_157;
V_95 = F_87 ( V_2 ) ;
if ( V_95 )
goto V_158;
F_80 ( V_2 ) ;
F_75 ( V_2 ) ;
F_67 ( V_2 ) ;
V_95 = F_106 ( & V_2 -> V_7 ) ;
if ( V_95 )
goto V_159;
F_40 ( & V_13 -> V_88 , L_42 ) ;
return 0 ;
V_159:
F_71 ( V_2 ) ;
F_88 ( V_2 ) ;
V_158:
F_102 ( V_2 ) ;
V_157:
F_55 ( V_2 ) ;
V_156:
return V_95 ;
}
static void F_107 ( struct V_94 * V_13 )
{
struct V_1 * V_2 = F_108 ( V_13 ) ;
F_109 ( & V_2 -> V_7 ) ;
F_71 ( V_2 ) ;
F_81 ( V_2 ) ;
F_88 ( V_2 ) ;
F_102 ( V_2 ) ;
F_55 ( V_2 ) ;
}
static int T_12 F_110 ( void )
{
F_111 ( L_43 , V_160 , V_161 ) ;
if ( F_112 () )
V_127 = F_68 ( V_162 , NULL ) ;
return F_113 ( & V_163 ) ;
}
static void T_13 F_114 ( void )
{
F_115 ( & V_163 ) ;
F_72 ( V_127 ) ;
}
