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
V_16 = V_25 + ( ( V_12 - 2 ) << 3 ) ;
V_17 = V_26 + ( ( V_12 - 2 ) << 3 ) ;
V_22 = V_21 + V_9 ;
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
if ( V_15 & ( ~ 0ull << 32 ) )
return - V_5 ;
if ( ( V_15 + V_9 ) & ( ~ 0ull << 32 ) )
return - V_5 ;
V_22 = V_21 + V_9 ;
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
if ( V_2 -> V_30 & V_32 )
V_2 -> V_30 &= ~ V_32 ;
else if ( V_2 -> V_30 & V_33 )
V_2 -> V_30 = 0 ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
enum V_34 * V_35 ,
enum V_36 * V_37 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_38 = 0 ;
if ( F_12 ( V_2 ) ) {
if ( V_35 )
* V_35 = F_15 ( V_2 -> V_39 ) ;
if ( V_37 )
* V_37 = F_16 ( V_2 -> V_39 ) ;
F_17 ( F_18 ( V_2 ) , L_1 ) ;
V_38 = 1 ;
} else {
if ( V_35 )
* V_35 = V_40 ;
if ( V_37 )
* V_37 = V_41 ;
F_17 ( F_18 ( V_2 ) , L_2 ) ;
}
return V_38 ;
}
static int F_19 ( struct V_6 * V_7 ,
enum V_34 V_42 ,
enum V_36 V_43 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_44 ;
V_2 -> V_45 &= ~ V_46 ;
F_10 ( V_2 -> V_45 , V_19 + V_47 ) ;
if ( V_2 -> V_7 . V_48 == V_49 )
return - V_5 ;
F_17 ( F_18 ( V_2 ) , L_3 ) ;
V_44 = F_11 ( V_19 + V_50 ) ;
V_44 |= ( V_51 | V_52 ) ;
F_10 ( V_44 , V_19 + V_50 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_44 ;
V_2 -> V_45 |= V_46 ;
F_10 ( V_2 -> V_45 , V_19 + V_47 ) ;
if ( V_2 -> V_7 . V_48 == V_49 )
return - V_5 ;
F_17 ( F_18 ( V_2 ) , L_3 ) ;
V_44 = F_11 ( V_19 + V_50 ) ;
V_44 &= ~ ( V_51 | V_52 ) ;
F_10 ( V_44 , V_19 + V_50 ) ;
return 0 ;
}
static T_5 F_21 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_53 ;
}
static int F_22 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_54 ;
}
static T_5 F_23 ( struct V_6 * V_7 , int V_55 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( V_55 < 0 || V_55 > V_2 -> V_54 )
return 0 ;
return F_3 ( V_7 ) -> V_53 & ( 1 << V_55 ) ;
}
static T_5 F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
return ( T_5 ) F_25 ( V_19 + V_56 ) ;
}
static int F_26 ( struct V_6 * V_7 , T_5 V_57 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
F_27 ( ( V_58 ) V_57 , V_19 + V_56 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_7 , T_5 V_57 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
unsigned long V_59 ;
if ( V_57 & ~ V_2 -> V_53 )
return - V_5 ;
F_29 ( & V_2 -> V_60 , V_59 ) ;
V_2 -> V_61 |= V_57 ;
F_27 ( ( V_58 ) V_2 -> V_61 , V_19 + V_62 ) ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , T_5 V_57 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
unsigned long V_59 ;
if ( V_57 & ~ V_2 -> V_53 )
return - V_5 ;
F_29 ( & V_2 -> V_60 , V_59 ) ;
V_2 -> V_61 &= ~ V_57 ;
F_27 ( ( V_58 ) V_2 -> V_61 , V_19 + V_62 ) ;
F_30 ( & V_2 -> V_60 , V_59 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 ,
T_1 * V_63 ,
T_2 * V_64 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( V_63 )
* V_63 = ( T_1 ) ( V_2 -> V_20 + V_65 ) ;
if ( V_64 )
* V_64 = sizeof( T_6 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , T_5 V_57 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
F_27 ( ( V_58 ) V_57 , V_19 + V_65 ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_66 ;
}
static T_6 F_35 ( struct V_6 * V_7 , int V_3 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_67 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return 0 ;
V_67 = V_2 -> V_68 + ( V_3 << 2 ) ;
return F_11 ( V_19 + V_69 + V_67 ) ;
}
static int F_36 ( struct V_6 * V_7 ,
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
static int F_37 ( struct V_6 * V_7 , int V_3 ,
T_1 * V_71 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return - V_5 ;
if ( V_71 )
* V_71 = ( T_1 ) ( V_2 -> V_24 + V_69 +
V_2 -> V_72 + ( V_3 << 2 ) ) ;
return 0 ;
}
static T_6 F_38 ( struct V_6 * V_7 , int V_3 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_67 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return - V_5 ;
V_67 = V_2 -> V_72 + ( V_3 << 2 ) ;
return F_11 ( V_19 + V_69 + V_67 ) ;
}
static int F_39 ( struct V_6 * V_7 ,
int V_3 , T_6 V_70 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_67 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_66 )
return - V_5 ;
V_67 = V_2 -> V_72 + ( V_3 << 2 ) ;
F_10 ( V_70 , V_19 + V_69 + V_67 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , T_6 V_73 )
{
void T_4 * V_19 = V_2 -> V_24 ;
int V_74 ;
V_74 = F_11 ( V_19 + V_75 ) ;
V_74 |= V_73 ;
F_10 ( V_74 , V_19 + V_75 ) ;
V_2 -> V_30 |= V_73 ;
}
static void F_41 ( struct V_1 * V_2 , int V_76 )
{
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_77 ;
V_77 = F_11 ( V_19 + V_78 ) ;
if ( ! ( V_77 & V_46 ) )
return;
F_17 ( F_18 ( V_2 ) , L_4 , V_77 , V_76 ) ;
V_77 &= V_46 ;
switch ( V_77 ) {
case V_79 :
F_42 ( F_18 ( V_2 ) , L_5 ) ;
break;
case V_32 :
F_40 ( V_2 , V_32 ) ;
F_43 ( & V_2 -> V_7 ) ;
F_44 ( & V_2 -> V_80 , V_81 ) ;
break;
case V_82 :
case V_83 :
F_40 ( V_2 , V_77 ) ;
F_43 ( & V_2 -> V_7 ) ;
break;
case V_33 :
V_19 = V_2 -> V_20 ;
V_77 = F_11 ( V_19 + V_84 ) ;
if ( V_77 & 0x1 )
F_42 ( F_18 ( V_2 ) , L_6 ) ;
F_40 ( V_2 , V_33 ) ;
F_44 ( & V_2 -> V_80 ,
V_81 ) ;
break;
default:
F_42 ( F_18 ( V_2 ) , L_7 , V_77 ) ;
break;
}
}
static T_7 F_45 ( struct V_1 * V_2 , int V_76 )
{
F_17 ( F_18 ( V_2 ) , L_8 , V_76 ) ;
if ( V_76 > ( V_85 - 1 ) || ( V_2 -> V_86 == 1 ) )
F_41 ( V_2 , V_76 ) ;
if ( V_76 < V_85 )
F_46 ( & V_2 -> V_7 , V_76 ) ;
return V_87 ;
}
static T_7 F_47 ( int V_88 , void * V_89 )
{
struct V_90 * V_91 = V_89 ;
return F_45 ( V_91 -> V_2 , V_91 -> V_92 ) ;
}
static T_7 F_48 ( int V_88 , void * V_89 )
{
struct V_1 * V_2 = V_89 ;
return F_45 ( V_2 , V_88 - F_49 ( V_2 ) -> V_88 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_93 , int V_94 )
{
struct V_95 * V_13 ;
int V_96 , V_97 , V_98 , V_99 ;
V_13 = F_49 ( V_2 ) ;
V_99 = F_51 ( & V_13 -> V_89 ) ;
V_2 -> V_61 = V_2 -> V_53 ;
V_2 -> V_76 = F_52 ( V_94 * sizeof( * V_2 -> V_76 ) ,
V_100 , V_99 ) ;
if ( ! V_2 -> V_76 )
goto V_101;
V_2 -> V_102 = F_52 ( V_94 * sizeof( * V_2 -> V_102 ) ,
V_100 , V_99 ) ;
if ( ! V_2 -> V_102 )
goto V_103;
for ( V_97 = 0 ; V_97 < V_94 ; ++ V_97 )
V_2 -> V_102 [ V_97 ] . V_104 = V_97 ;
V_98 = F_53 ( V_13 , V_2 -> V_102 ,
V_93 , V_94 ) ;
if ( V_98 < 0 )
goto V_105;
if ( V_98 < V_93 ) {
F_54 ( V_13 ) ;
goto V_105;
}
for ( V_97 = 0 ; V_97 < V_98 ; ++ V_97 ) {
V_2 -> V_76 [ V_97 ] . V_2 = V_2 ;
V_2 -> V_76 [ V_97 ] . V_92 = V_97 ;
V_96 = F_55 ( V_2 -> V_102 [ V_97 ] . V_106 , F_47 , 0 ,
L_9 , & V_2 -> V_76 [ V_97 ] ) ;
if ( V_96 )
goto V_107;
}
F_17 ( F_18 ( V_2 ) , L_10 ) ;
V_2 -> V_54 = V_93 ;
V_2 -> V_86 = V_94 ;
return 0 ;
V_107:
while ( V_97 -- > 0 )
F_56 ( V_2 -> V_102 [ V_97 ] . V_106 , V_2 ) ;
F_54 ( V_13 ) ;
V_105:
F_57 ( V_2 -> V_102 ) ;
V_103:
F_57 ( V_2 -> V_76 ) ;
V_101:
V_2 -> V_102 = NULL ;
V_2 -> V_76 = NULL ;
V_96 = F_58 ( V_13 ) ;
if ( V_96 )
goto V_108;
V_96 = F_55 ( V_13 -> V_88 , F_48 , 0 ,
L_11 , V_2 ) ;
if ( V_96 )
goto V_109;
F_17 ( F_18 ( V_2 ) , L_12 ) ;
V_2 -> V_54 = 1 ;
V_2 -> V_86 = 1 ;
return 0 ;
V_109:
F_59 ( V_13 ) ;
V_108:
F_60 ( V_13 , 1 ) ;
V_96 = F_55 ( V_13 -> V_88 , F_48 , V_110 ,
L_11 , V_2 ) ;
if ( V_96 )
goto V_111;
F_17 ( F_18 ( V_2 ) , L_13 ) ;
V_2 -> V_54 = 1 ;
V_2 -> V_86 = 1 ;
return 0 ;
V_111:
return V_96 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_95 * V_13 ;
void T_4 * V_19 = V_2 -> V_24 ;
int V_97 ;
V_13 = F_49 ( V_2 ) ;
V_2 -> V_61 = V_2 -> V_53 ;
F_10 ( V_2 -> V_61 , V_19 + V_62 ) ;
if ( V_2 -> V_102 ) {
V_97 = V_2 -> V_86 ;
while ( V_97 -- )
F_56 ( V_2 -> V_102 [ V_97 ] . V_106 , & V_2 -> V_76 [ V_97 ] ) ;
F_54 ( V_13 ) ;
F_57 ( V_2 -> V_102 ) ;
F_57 ( V_2 -> V_76 ) ;
} else {
F_56 ( V_13 -> V_88 , V_2 ) ;
if ( F_62 ( V_13 ) )
F_59 ( V_13 ) ;
else
F_60 ( V_13 , 0 ) ;
}
}
static T_8 F_63 ( struct V_112 * V_113 , char T_9 * V_114 ,
T_10 V_115 , T_11 * V_116 )
{
struct V_1 * V_2 ;
void T_4 * V_19 ;
char * V_117 ;
T_10 V_118 ;
T_8 V_38 , V_119 ;
union { T_5 V_120 ; T_6 V_121 ; V_58 V_122 ; } V_123 ;
V_2 = V_113 -> V_124 ;
V_19 = V_2 -> V_24 ;
V_118 = F_64 ( V_115 , 0x800ul ) ;
V_117 = F_65 ( V_118 , V_100 ) ;
if ( ! V_117 )
return - V_125 ;
V_119 = 0 ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_14 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_15 ,
F_67 ( V_2 -> V_7 . V_48 ) ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_16 , V_2 -> V_39 ) ;
if ( ! F_12 ( V_2 ) ) {
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_17 ) ;
} else {
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_18 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_19 ,
F_15 ( V_2 -> V_39 ) ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_20 ,
F_16 ( V_2 -> V_39 ) ) ;
}
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_21 , V_2 -> V_4 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_22 , V_2 -> V_66 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_23 , V_2 -> V_54 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_24 , V_2 -> V_86 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_25 , V_2 -> V_53 ) ;
V_123 . V_121 = F_11 ( V_2 -> V_24 + V_62 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_26 , V_123 . V_121 ) ;
V_123 . V_121 = F_11 ( V_19 + V_56 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_27 , V_123 . V_121 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_28 ) ;
V_123 . V_120 = F_9 ( V_19 + V_28 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_29 , V_123 . V_120 ) ;
V_123 . V_120 = F_9 ( V_2 -> V_24 + V_25 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_30 , V_123 . V_120 ) ;
V_123 . V_120 = F_9 ( V_2 -> V_24 + V_126 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_31 , V_123 . V_120 ) ;
V_123 . V_121 = F_11 ( V_19 + V_29 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_32 , V_123 . V_121 ) ;
V_123 . V_120 = F_9 ( V_2 -> V_24 + V_26 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_33 , V_123 . V_120 ) ;
V_123 . V_120 = F_9 ( V_2 -> V_24 + V_127 ) ;
V_119 += F_66 ( V_117 + V_119 , V_118 - V_119 ,
L_34 , V_123 . V_120 ) ;
V_38 = F_68 ( V_114 , V_115 , V_116 , V_117 , V_119 ) ;
F_57 ( V_117 ) ;
return V_38 ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( ! V_128 ) {
V_2 -> V_128 = NULL ;
V_2 -> V_129 = NULL ;
} else {
V_2 -> V_128 =
F_70 ( F_71 ( V_2 ) , V_128 ) ;
if ( ! V_2 -> V_128 )
V_2 -> V_129 = NULL ;
else
V_2 -> V_129 =
F_72 ( L_35 , V_130 ,
V_2 -> V_128 , V_2 ,
& V_131 ) ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_128 ) ;
}
static inline void F_75 ( struct V_1 * V_2 ,
struct V_95 * V_13 )
{
V_2 -> V_7 . V_13 = V_13 ;
V_2 -> V_7 . V_48 = V_132 ;
V_2 -> V_7 . V_133 = & V_134 ;
V_2 -> V_45 = V_46 ;
F_76 ( & V_2 -> V_60 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_20 ;
T_6 V_74 , V_135 ;
int V_96 ;
V_74 = F_11 ( V_19 + V_136 ) ;
V_74 &= V_137 ;
F_17 ( F_18 ( V_2 ) , L_36 , V_138 , V_74 ) ;
if ( V_74 == V_2 -> V_31 )
return 0 ;
V_2 -> V_31 = V_74 ;
V_96 = F_78 ( V_2 -> V_7 . V_13 ,
V_139 , & V_135 ) ;
if ( V_96 )
return 0 ;
V_2 -> V_39 = V_135 ;
return 1 ;
}
static void F_79 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_80 ( V_141 ) ;
if ( F_77 ( V_2 ) )
F_43 ( & V_2 -> V_7 ) ;
if ( ! F_12 ( V_2 ) )
F_44 ( & V_2 -> V_80 , V_81 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
return F_50 ( V_2 , V_85 , V_142 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
unsigned int V_74 ;
V_74 = F_11 ( V_19 + V_136 ) ;
if ( ! ( V_74 & V_143 ) ) {
V_74 |= V_143 ;
F_10 ( V_74 , V_19 + V_136 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
unsigned int V_74 ;
V_74 = F_11 ( V_19 + V_136 ) ;
if ( V_74 & V_143 ) {
V_74 &= ~ V_143 ;
F_10 ( V_74 , V_19 + V_136 ) ;
F_11 ( V_19 + V_136 ) ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
V_2 -> V_4 = V_144 ;
V_2 -> V_66 = V_145 ;
V_2 -> V_54 = V_85 ;
switch ( V_2 -> V_7 . V_48 ) {
case V_146 :
case V_49 :
V_2 -> V_66 >>= 1 ;
if ( V_2 -> V_7 . V_48 == V_146 ) {
V_2 -> V_68 = 0 ;
V_2 -> V_72 = 0x20 ;
} else {
V_2 -> V_68 = 0x20 ;
V_2 -> V_72 = 0 ;
}
F_85 ( & V_2 -> V_80 , F_79 ) ;
F_44 ( & V_2 -> V_80 , V_81 ) ;
break;
default:
F_86 ( F_18 ( V_2 ) , L_37 ) ;
return - V_5 ;
}
V_2 -> V_53 = F_87 ( V_2 -> V_54 ) - 1 ;
F_10 ( V_2 -> V_45 , V_19 + V_47 ) ;
return 0 ;
}
static enum V_147 F_88 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_148 ;
V_148 = F_11 ( V_19 + V_136 ) ;
if ( V_148 & V_149 )
return V_49 ;
else
return V_146 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_95 * V_13 ;
int V_96 = 0 ;
V_13 = F_49 ( V_2 ) ;
V_2 -> V_7 . V_48 = F_88 ( V_2 ) ;
F_17 ( F_18 ( V_2 ) , L_38 ,
F_67 ( V_2 -> V_7 . V_48 ) ) ;
V_96 = F_84 ( V_2 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_81 ( V_2 ) ;
if ( V_96 ) {
F_86 ( F_18 ( V_2 ) , L_39 ) ;
return V_96 ;
}
V_2 -> V_53 = F_87 ( V_2 -> V_54 ) - 1 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
F_91 ( & V_2 -> V_80 ) ;
F_61 ( V_2 ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_95 * V_13 )
{
int V_96 ;
F_93 ( V_13 , V_2 ) ;
V_96 = F_94 ( V_13 ) ;
if ( V_96 )
goto V_150;
V_96 = F_95 ( V_13 , V_151 ) ;
if ( V_96 )
goto V_152;
F_96 ( V_13 ) ;
V_96 = F_97 ( V_13 , F_98 ( 64 ) ) ;
if ( V_96 ) {
V_96 = F_97 ( V_13 , F_98 ( 32 ) ) ;
if ( V_96 )
goto V_153;
F_99 ( F_18 ( V_2 ) , L_40 ) ;
}
V_96 = F_100 ( V_13 , F_98 ( 64 ) ) ;
if ( V_96 ) {
V_96 = F_100 ( V_13 , F_98 ( 32 ) ) ;
if ( V_96 )
goto V_153;
F_99 ( F_18 ( V_2 ) , L_41 ) ;
}
V_2 -> V_24 = F_101 ( V_13 , 0 , 0 ) ;
if ( ! V_2 -> V_24 ) {
V_96 = - V_27 ;
goto V_153;
}
V_2 -> V_20 = V_2 -> V_24 + V_154 ;
return 0 ;
V_153:
F_102 ( V_13 ) ;
V_152:
F_103 ( V_13 ) ;
V_150:
F_93 ( V_13 , NULL ) ;
return V_96 ;
}
static void F_104 ( struct V_1 * V_2 )
{
struct V_95 * V_13 = F_49 ( V_2 ) ;
F_105 ( V_13 , V_2 -> V_24 ) ;
F_102 ( V_13 ) ;
F_106 ( V_13 ) ;
F_103 ( V_13 ) ;
F_93 ( V_13 , NULL ) ;
}
static int F_107 ( struct V_95 * V_13 ,
const struct V_155 * V_156 )
{
struct V_1 * V_2 ;
int V_96 , V_99 ;
V_99 = F_51 ( & V_13 -> V_89 ) ;
V_2 = F_52 ( sizeof( * V_2 ) , V_100 , V_99 ) ;
if ( ! V_2 ) {
V_96 = - V_125 ;
goto V_157;
}
F_75 ( V_2 , V_13 ) ;
V_96 = F_92 ( V_2 , V_13 ) ;
if ( V_96 )
goto V_158;
V_96 = F_89 ( V_2 ) ;
if ( V_96 )
goto V_159;
F_82 ( V_2 ) ;
F_77 ( V_2 ) ;
F_69 ( V_2 ) ;
V_96 = F_108 ( & V_2 -> V_7 ) ;
if ( V_96 )
goto V_160;
F_42 ( & V_13 -> V_89 , L_42 ) ;
return 0 ;
V_160:
F_73 ( V_2 ) ;
F_90 ( V_2 ) ;
V_159:
F_104 ( V_2 ) ;
V_158:
F_57 ( V_2 ) ;
V_157:
return V_96 ;
}
static void F_109 ( struct V_95 * V_13 )
{
struct V_1 * V_2 = F_110 ( V_13 ) ;
F_111 ( & V_2 -> V_7 ) ;
F_73 ( V_2 ) ;
F_83 ( V_2 ) ;
F_90 ( V_2 ) ;
F_104 ( V_2 ) ;
F_57 ( V_2 ) ;
}
static int T_12 F_112 ( void )
{
F_113 ( L_43 , V_161 , V_162 ) ;
if ( F_114 () )
V_128 = F_70 ( V_163 , NULL ) ;
return F_115 ( & V_164 ) ;
}
static void T_13 F_116 ( void )
{
F_117 ( & V_164 ) ;
F_74 ( V_128 ) ;
}
