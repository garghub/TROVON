static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 0 || V_3 > V_2 -> V_4 )
return - V_5 ;
return 1 << V_3 ;
}
static int F_2 ( struct V_6 * V_7 , int V_8 )
{
if ( V_8 != V_9 )
return - V_5 ;
return F_3 ( V_7 ) -> V_4 ;
}
static int F_4 ( struct V_6 * V_7 , int V_8 , int V_3 ,
T_1 * V_10 ,
T_1 * V_11 ,
T_1 * V_12 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_13 ;
if ( V_8 != V_9 )
return - V_5 ;
V_13 = F_1 ( V_2 , V_3 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_10 )
* V_10 = V_14 ;
if ( V_11 )
* V_11 = 1 ;
if ( V_12 )
* V_12 = F_5 ( V_2 -> V_7 . V_15 , V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 , int V_8 , int V_3 ,
T_2 V_16 , T_1 V_17 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned long V_18 , V_19 = 0 ;
T_1 V_20 ;
void T_3 * V_21 , * V_22 ;
T_4 V_23 , V_24 , V_25 ;
int V_13 ;
if ( V_8 != V_9 )
return - V_5 ;
V_13 = F_1 ( V_2 , V_3 ) ;
if ( V_13 < 0 )
return V_13 ;
V_20 = F_5 ( V_7 -> V_15 , V_13 ) ;
if ( V_17 > V_20 )
return - V_5 ;
V_21 = V_2 -> V_26 ;
V_22 = V_2 -> V_22 ;
V_23 = F_7 ( V_7 -> V_15 , V_13 ) ;
if ( V_13 != 1 ) {
V_18 = V_27 + ( ( V_13 - 2 ) << 2 ) ;
V_19 = V_28 + ( ( V_13 - 2 ) << 2 ) ;
V_24 = V_17 ;
F_8 ( V_16 , V_22 + V_18 ) ;
V_25 = F_9 ( V_22 + V_18 ) ;
if ( V_25 != V_16 ) {
F_8 ( 0 , V_22 + V_18 ) ;
return - V_29 ;
}
F_8 ( V_24 , V_21 + V_19 ) ;
V_25 = F_9 ( V_21 + V_19 ) ;
if ( V_25 != V_24 ) {
F_8 ( V_23 , V_21 + V_19 ) ;
F_8 ( 0 , V_22 + V_18 ) ;
return - V_29 ;
}
} else {
V_18 = V_30 ;
V_19 = V_31 ;
V_24 = V_17 ;
F_8 ( V_16 , V_22 + V_18 ) ;
V_25 = F_9 ( V_22 + V_18 ) ;
if ( V_25 != V_16 ) {
F_8 ( 0 , V_22 + V_18 ) ;
return - V_29 ;
}
F_10 ( V_24 , V_21 + V_19 ) ;
V_25 = F_11 ( V_21 + V_19 ) ;
if ( V_25 != V_24 ) {
F_10 ( V_23 , V_21 + V_19 ) ;
F_10 ( 0 , V_22 + V_18 ) ;
return - V_29 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_32 )
return F_13 ( V_2 -> V_33 ) ;
if ( V_2 -> V_32 & V_34 ) {
V_2 -> V_32 = 0 ;
return 1 ;
}
if ( V_2 -> V_32 & V_35 )
V_2 -> V_32 &= ~ V_35 ;
else if ( V_2 -> V_32 & ( V_36 | V_37 ) )
V_2 -> V_32 = 0 ;
return 0 ;
}
static T_4 F_14 ( struct V_6 * V_7 ,
enum V_38 * V_39 ,
enum V_40 * V_41 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_42 = 0 ;
if ( F_12 ( V_2 ) ) {
if ( V_39 )
* V_39 = F_15 ( V_2 -> V_43 ) ;
if ( V_41 )
* V_41 = F_16 ( V_2 -> V_43 ) ;
F_17 ( & V_7 -> V_15 -> V_44 , L_1 ) ;
V_42 = 1 ;
} else {
if ( V_39 )
* V_39 = V_45 ;
if ( V_41 )
* V_41 = V_46 ;
F_17 ( & V_7 -> V_15 -> V_44 , L_2 ) ;
}
return V_42 ;
}
static int F_18 ( struct V_6 * V_7 ,
enum V_38 V_47 ,
enum V_40 V_48 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
T_5 V_49 ;
V_2 -> V_50 &= ~ V_51 ;
F_10 ( V_2 -> V_50 , V_21 + V_52 ) ;
if ( V_2 -> V_7 . V_53 == V_54 )
return - V_5 ;
F_17 ( & V_7 -> V_15 -> V_44 , L_3 ) ;
V_49 = F_11 ( V_21 + V_55 ) ;
V_49 |= ( V_56 | V_57 ) ;
F_10 ( V_49 , V_21 + V_55 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
T_5 V_49 ;
V_2 -> V_50 |= V_51 ;
F_10 ( V_2 -> V_50 , V_21 + V_52 ) ;
if ( V_2 -> V_7 . V_53 == V_54 )
return - V_5 ;
F_17 ( & V_7 -> V_15 -> V_44 , L_3 ) ;
V_49 = F_11 ( V_21 + V_55 ) ;
V_49 &= ~ ( V_56 | V_57 ) ;
F_10 ( V_49 , V_21 + V_55 ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_4 ;
}
static int F_21 ( struct V_6 * V_7 , int V_3 ,
T_6 * V_58 , T_1 * V_17 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_13 ;
V_13 = F_1 ( V_2 , V_3 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_58 )
* V_58 = F_7 ( V_2 -> V_7 . V_15 , V_13 ) ;
if ( V_17 )
* V_17 = F_5 ( V_2 -> V_7 . V_15 , V_13 ) ;
return 0 ;
}
static T_4 F_22 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_59 ;
}
static int F_23 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_60 ;
}
static T_4 F_24 ( struct V_6 * V_7 , int V_61 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
if ( V_61 < 0 || V_61 > V_2 -> V_60 )
return 0 ;
return F_3 ( V_7 ) -> V_59 & ( 1 << V_61 ) ;
}
static T_4 F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
return ( T_4 ) F_26 ( V_21 + V_62 ) ;
}
static int F_27 ( struct V_6 * V_7 , T_4 V_63 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
F_28 ( ( V_64 ) V_63 , V_21 + V_62 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 , T_4 V_63 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
unsigned long V_65 ;
if ( V_63 & ~ V_2 -> V_59 )
return - V_5 ;
F_30 ( & V_2 -> V_66 , V_65 ) ;
V_2 -> V_67 |= V_63 ;
F_28 ( ( V_64 ) V_2 -> V_67 , V_21 + V_68 ) ;
F_31 ( & V_2 -> V_66 , V_65 ) ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , T_4 V_63 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
unsigned long V_65 ;
if ( V_63 & ~ V_2 -> V_59 )
return - V_5 ;
F_30 ( & V_2 -> V_66 , V_65 ) ;
V_2 -> V_67 &= ~ V_63 ;
F_28 ( ( V_64 ) V_2 -> V_67 , V_21 + V_68 ) ;
F_31 ( & V_2 -> V_66 , V_65 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , T_4 V_63 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
F_28 ( ( V_64 ) V_63 , V_21 + V_69 ) ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_70 ;
}
static T_5 F_35 ( struct V_6 * V_7 , int V_3 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
T_5 V_71 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_70 )
return 0 ;
V_71 = V_2 -> V_72 + ( V_3 << 2 ) ;
return F_11 ( V_21 + V_73 + V_71 ) ;
}
static int F_36 ( struct V_6 * V_7 ,
int V_3 , T_5 V_74 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
T_5 V_71 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_70 )
return - V_5 ;
V_71 = V_2 -> V_72 + ( V_3 << 2 ) ;
F_10 ( V_74 , V_21 + V_73 + V_71 ) ;
return 0 ;
}
static T_5 F_37 ( struct V_6 * V_7 , int V_8 , int V_75 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
T_5 V_71 ;
if ( V_75 < 0 || V_75 >= V_2 -> V_70 )
return - V_5 ;
V_71 = V_2 -> V_76 + ( V_75 << 2 ) ;
return F_11 ( V_21 + V_73 + V_71 ) ;
}
static int F_38 ( struct V_6 * V_7 , int V_8 ,
int V_75 , T_5 V_74 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_3 * V_21 = V_2 -> V_26 ;
T_5 V_71 ;
if ( V_75 < 0 || V_75 >= V_2 -> V_70 )
return - V_5 ;
V_71 = V_2 -> V_76 + ( V_75 << 2 ) ;
F_10 ( V_74 , V_21 + V_73 + V_71 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , T_5 V_77 )
{
void T_3 * V_21 = V_2 -> V_26 ;
int V_78 ;
V_78 = F_11 ( V_21 + V_79 ) ;
V_78 |= V_77 ;
F_10 ( V_78 , V_21 + V_79 ) ;
V_2 -> V_32 |= V_77 ;
}
static void F_40 ( struct V_1 * V_2 , int V_80 )
{
void T_3 * V_21 = V_2 -> V_26 ;
struct V_81 * V_44 = & V_2 -> V_7 . V_15 -> V_44 ;
T_5 V_82 ;
V_82 = F_11 ( V_21 + V_83 ) ;
if ( ! ( V_82 & V_51 ) )
return;
F_17 ( V_44 , L_4 , V_82 , V_80 ) ;
V_82 &= V_51 ;
switch ( V_82 ) {
case V_84 :
F_41 ( V_44 , L_5 ) ;
break;
case V_35 :
F_39 ( V_2 , V_35 ) ;
F_42 ( & V_2 -> V_7 ) ;
F_43 ( & V_2 -> V_85 , V_86 ) ;
break;
case V_87 :
case V_88 :
case V_34 :
case V_37 :
F_39 ( V_2 , V_82 ) ;
F_42 ( & V_2 -> V_7 ) ;
break;
case V_36 :
V_21 = V_2 -> V_22 ;
V_82 = F_11 ( V_21 + V_89 ) ;
if ( V_82 & 0x1 )
F_41 ( V_44 , L_6 ) ;
F_39 ( V_2 , V_36 ) ;
F_43 ( & V_2 -> V_85 ,
V_86 ) ;
break;
default:
F_41 ( V_44 , L_7 , V_82 ) ;
break;
}
}
static T_7 F_44 ( struct V_1 * V_2 , int V_80 )
{
F_17 ( & V_2 -> V_7 . V_15 -> V_44 , L_8 , V_80 ) ;
if ( V_80 > ( V_90 - 1 ) || ( V_2 -> V_91 == 1 ) )
F_40 ( V_2 , V_80 ) ;
if ( V_80 < V_90 )
F_45 ( & V_2 -> V_7 , V_80 ) ;
return V_92 ;
}
static T_7 F_46 ( int V_93 , void * V_44 )
{
struct V_94 * V_95 = V_44 ;
return F_44 ( V_95 -> V_2 , V_95 -> V_96 ) ;
}
static T_7 F_47 ( int V_93 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
return F_44 ( V_2 , V_93 - V_2 -> V_7 . V_15 -> V_93 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_97 , int V_98 )
{
struct V_99 * V_15 ;
int V_100 , V_101 , V_102 , V_103 ;
V_15 = V_2 -> V_7 . V_15 ;
V_103 = F_49 ( & V_15 -> V_44 ) ;
V_2 -> V_67 = V_2 -> V_59 ;
V_2 -> V_80 = F_50 ( V_98 * sizeof( * V_2 -> V_80 ) ,
V_104 , V_103 ) ;
if ( ! V_2 -> V_80 )
goto V_105;
V_2 -> V_106 = F_50 ( V_98 * sizeof( * V_2 -> V_106 ) ,
V_104 , V_103 ) ;
if ( ! V_2 -> V_106 )
goto V_107;
for ( V_101 = 0 ; V_101 < V_98 ; ++ V_101 )
V_2 -> V_106 [ V_101 ] . V_108 = V_101 ;
V_102 = F_51 ( V_15 , V_2 -> V_106 ,
V_97 , V_98 ) ;
if ( V_102 < 0 )
goto V_109;
if ( V_102 < V_97 ) {
F_52 ( V_15 ) ;
goto V_109;
}
for ( V_101 = 0 ; V_101 < V_102 ; ++ V_101 ) {
V_2 -> V_80 [ V_101 ] . V_2 = V_2 ;
V_2 -> V_80 [ V_101 ] . V_96 = V_101 ;
V_100 = F_53 ( V_2 -> V_106 [ V_101 ] . V_110 , F_46 , 0 ,
L_9 , & V_2 -> V_80 [ V_101 ] ) ;
if ( V_100 )
goto V_111;
}
F_17 ( & V_15 -> V_44 , L_10 ) ;
V_2 -> V_60 = V_97 ;
V_2 -> V_91 = V_98 ;
return 0 ;
V_111:
while ( V_101 -- > 0 )
F_54 ( V_2 -> V_106 [ V_101 ] . V_110 , & V_2 -> V_80 [ V_101 ] ) ;
F_52 ( V_15 ) ;
V_109:
F_55 ( V_2 -> V_106 ) ;
V_107:
F_55 ( V_2 -> V_80 ) ;
V_105:
V_2 -> V_106 = NULL ;
V_2 -> V_80 = NULL ;
V_100 = F_56 ( V_15 ) ;
if ( V_100 )
goto V_112;
V_100 = F_53 ( V_15 -> V_93 , F_47 , 0 ,
L_11 , V_2 ) ;
if ( V_100 )
goto V_113;
F_17 ( & V_15 -> V_44 , L_12 ) ;
V_2 -> V_60 = 1 ;
V_2 -> V_91 = 1 ;
return 0 ;
V_113:
F_57 ( V_15 ) ;
V_112:
F_58 ( V_15 , 1 ) ;
V_100 = F_53 ( V_15 -> V_93 , F_47 , V_114 ,
L_11 , V_2 ) ;
if ( V_100 )
goto V_115;
F_17 ( & V_15 -> V_44 , L_13 ) ;
V_2 -> V_60 = 1 ;
V_2 -> V_91 = 1 ;
return 0 ;
V_115:
return V_100 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_99 * V_15 ;
void T_3 * V_21 = V_2 -> V_26 ;
int V_101 ;
V_15 = V_2 -> V_7 . V_15 ;
V_2 -> V_67 = V_2 -> V_59 ;
F_10 ( V_2 -> V_67 , V_21 + V_68 ) ;
if ( V_2 -> V_106 ) {
V_101 = V_2 -> V_91 ;
while ( V_101 -- )
F_54 ( V_2 -> V_106 [ V_101 ] . V_110 , & V_2 -> V_80 [ V_101 ] ) ;
F_52 ( V_15 ) ;
F_55 ( V_2 -> V_106 ) ;
F_55 ( V_2 -> V_80 ) ;
} else {
F_54 ( V_15 -> V_93 , V_2 ) ;
if ( F_60 ( V_15 ) )
F_57 ( V_15 ) ;
else
F_58 ( V_15 , 0 ) ;
}
}
static T_8 F_61 ( struct V_116 * V_117 , char T_9 * V_118 ,
T_10 V_119 , T_11 * V_120 )
{
struct V_1 * V_2 ;
void T_3 * V_21 ;
char * V_121 ;
T_10 V_122 ;
T_8 V_42 , V_123 ;
union { T_4 V_124 ; T_5 V_125 ; V_64 V_126 ; } V_127 ;
V_2 = V_117 -> V_128 ;
V_21 = V_2 -> V_26 ;
V_122 = F_62 ( V_119 , 0x800ul ) ;
V_121 = F_63 ( V_122 , V_104 ) ;
if ( ! V_121 )
return - V_129 ;
V_123 = 0 ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_14 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_15 ,
F_65 ( V_2 -> V_7 . V_53 ) ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_16 , V_2 -> V_43 ) ;
if ( ! F_12 ( V_2 ) ) {
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_17 ) ;
} else {
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_18 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_19 ,
F_15 ( V_2 -> V_43 ) ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_20 ,
F_16 ( V_2 -> V_43 ) ) ;
}
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_21 , V_2 -> V_4 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_22 , V_2 -> V_70 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_23 , V_2 -> V_60 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_24 , V_2 -> V_91 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_25 , V_2 -> V_59 ) ;
V_127 . V_125 = F_11 ( V_2 -> V_26 + V_68 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_26 , V_127 . V_125 ) ;
V_127 . V_125 = F_11 ( V_21 + V_62 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_27 , V_127 . V_125 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_28 ) ;
V_127 . V_124 = F_9 ( V_21 + V_30 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_29 , V_127 . V_124 ) ;
V_127 . V_124 = F_9 ( V_2 -> V_26 + V_27 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_30 , V_127 . V_124 ) ;
V_127 . V_124 = F_9 ( V_2 -> V_26 + V_130 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_31 , V_127 . V_124 ) ;
V_127 . V_125 = F_11 ( V_21 + V_31 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_32 , V_127 . V_125 ) ;
V_127 . V_124 = F_9 ( V_2 -> V_26 + V_28 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_33 , V_127 . V_124 ) ;
V_127 . V_124 = F_9 ( V_2 -> V_26 + V_131 ) ;
V_123 += F_64 ( V_121 + V_123 , V_122 - V_123 ,
L_34 , V_127 . V_124 ) ;
V_42 = F_66 ( V_118 , V_119 , V_120 , V_121 , V_123 ) ;
F_55 ( V_121 ) ;
return V_42 ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( ! V_132 ) {
V_2 -> V_132 = NULL ;
V_2 -> V_133 = NULL ;
} else {
V_2 -> V_132 =
F_68 ( F_69 ( V_2 -> V_7 . V_15 ) ,
V_132 ) ;
if ( ! V_2 -> V_132 )
V_2 -> V_133 = NULL ;
else
V_2 -> V_133 =
F_70 ( L_35 , V_134 ,
V_2 -> V_132 , V_2 ,
& V_135 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 -> V_132 ) ;
}
static inline void F_73 ( struct V_1 * V_2 ,
struct V_99 * V_15 )
{
V_2 -> V_7 . V_15 = V_15 ;
V_2 -> V_7 . V_53 = V_136 ;
V_2 -> V_7 . V_137 = & V_138 ;
V_2 -> V_50 = V_51 ;
F_74 ( & V_2 -> V_66 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
void T_3 * V_21 = V_2 -> V_22 ;
T_5 V_78 , V_139 ;
int V_100 ;
V_78 = F_11 ( V_21 + V_140 ) ;
V_78 &= V_141 ;
F_17 ( & V_2 -> V_7 . V_15 -> V_44 , L_36 , V_142 , V_78 ) ;
if ( V_78 == V_2 -> V_33 )
return 0 ;
V_2 -> V_33 = V_78 ;
V_100 = F_76 ( V_2 -> V_7 . V_15 ,
V_143 , & V_139 ) ;
if ( V_100 )
return 0 ;
V_2 -> V_43 = V_139 ;
return 1 ;
}
static void F_77 ( struct V_144 * V_145 )
{
struct V_1 * V_2 = F_78 ( V_145 ) ;
if ( F_75 ( V_2 ) )
F_42 ( & V_2 -> V_7 ) ;
if ( ! F_12 ( V_2 ) )
F_43 ( & V_2 -> V_85 , V_86 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return F_48 ( V_2 , V_90 , V_146 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
void T_3 * V_21 = V_2 -> V_26 ;
unsigned int V_78 ;
V_78 = F_11 ( V_21 + V_140 ) ;
if ( ! ( V_78 & V_147 ) ) {
V_78 |= V_147 ;
F_10 ( V_78 , V_21 + V_140 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
void T_3 * V_21 = V_2 -> V_26 ;
unsigned int V_78 ;
V_78 = F_11 ( V_21 + V_140 ) ;
if ( V_78 & V_147 ) {
V_78 &= ~ V_147 ;
F_10 ( V_78 , V_21 + V_140 ) ;
F_11 ( V_21 + V_140 ) ;
}
}
static int F_82 ( struct V_1 * V_2 )
{
void T_3 * V_21 = V_2 -> V_26 ;
V_2 -> V_4 = V_148 ;
V_2 -> V_70 = V_149 ;
V_2 -> V_60 = V_90 ;
switch ( V_2 -> V_7 . V_53 ) {
case V_150 :
case V_54 :
V_2 -> V_70 >>= 1 ;
if ( V_2 -> V_7 . V_53 == V_150 ) {
V_2 -> V_72 = 0 ;
V_2 -> V_76 = 0x20 ;
} else {
V_2 -> V_72 = 0x20 ;
V_2 -> V_76 = 0 ;
}
F_83 ( & V_2 -> V_85 , F_77 ) ;
F_43 ( & V_2 -> V_85 , V_86 ) ;
break;
default:
F_84 ( & V_2 -> V_7 . V_15 -> V_44 ,
L_37 ) ;
return - V_5 ;
}
V_2 -> V_59 = F_85 ( V_2 -> V_60 ) - 1 ;
F_10 ( V_2 -> V_50 , V_21 + V_52 ) ;
return 0 ;
}
static enum V_151 F_86 ( struct V_1 * V_2 )
{
void T_3 * V_21 = V_2 -> V_26 ;
T_5 V_152 ;
V_152 = F_11 ( V_21 + V_140 ) ;
if ( V_152 & V_153 )
return V_54 ;
else
return V_150 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_99 * V_15 ;
int V_100 = 0 ;
V_15 = V_2 -> V_7 . V_15 ;
V_2 -> V_7 . V_53 = F_86 ( V_2 ) ;
F_17 ( & V_15 -> V_44 , L_38 ,
F_65 ( V_2 -> V_7 . V_53 ) ) ;
V_100 = F_82 ( V_2 ) ;
if ( V_100 )
return V_100 ;
V_100 = F_79 ( V_2 ) ;
if ( V_100 ) {
F_84 ( & V_15 -> V_44 , L_39 ) ;
return V_100 ;
}
V_2 -> V_59 = F_85 ( V_2 -> V_60 ) - 1 ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_89 ( & V_2 -> V_85 ) ;
F_59 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_99 * V_15 )
{
int V_100 ;
F_91 ( V_15 , V_2 ) ;
V_100 = F_92 ( V_15 ) ;
if ( V_100 )
goto V_154;
V_100 = F_93 ( V_15 , V_155 ) ;
if ( V_100 )
goto V_156;
F_94 ( V_15 ) ;
V_100 = F_95 ( V_15 , F_96 ( 64 ) ) ;
if ( V_100 ) {
V_100 = F_95 ( V_15 , F_96 ( 32 ) ) ;
if ( V_100 )
goto V_157;
F_97 ( & V_15 -> V_44 , L_40 ) ;
}
V_100 = F_98 ( V_15 , F_96 ( 64 ) ) ;
if ( V_100 ) {
V_100 = F_98 ( V_15 , F_96 ( 32 ) ) ;
if ( V_100 )
goto V_157;
F_97 ( & V_15 -> V_44 , L_41 ) ;
}
V_2 -> V_26 = F_99 ( V_15 , 0 , 0 ) ;
if ( ! V_2 -> V_26 ) {
V_100 = - V_29 ;
goto V_157;
}
V_2 -> V_22 = V_2 -> V_26 + V_158 ;
return 0 ;
V_157:
F_100 ( V_15 ) ;
V_156:
F_101 ( V_15 ) ;
V_154:
F_91 ( V_15 , NULL ) ;
return V_100 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_99 * V_15 = V_2 -> V_7 . V_15 ;
F_103 ( V_15 , V_2 -> V_26 ) ;
F_100 ( V_15 ) ;
F_104 ( V_15 ) ;
F_101 ( V_15 ) ;
F_91 ( V_15 , NULL ) ;
}
static int F_105 ( struct V_99 * V_15 ,
const struct V_159 * V_160 )
{
struct V_1 * V_2 ;
int V_100 , V_103 ;
V_103 = F_49 ( & V_15 -> V_44 ) ;
V_2 = F_50 ( sizeof( * V_2 ) , V_104 , V_103 ) ;
if ( ! V_2 ) {
V_100 = - V_129 ;
goto V_161;
}
F_73 ( V_2 , V_15 ) ;
V_100 = F_90 ( V_2 , V_15 ) ;
if ( V_100 )
goto V_162;
V_100 = F_87 ( V_2 ) ;
if ( V_100 )
goto V_163;
F_80 ( V_2 ) ;
F_75 ( V_2 ) ;
F_67 ( V_2 ) ;
V_100 = F_106 ( & V_2 -> V_7 ) ;
if ( V_100 )
goto V_164;
F_41 ( & V_15 -> V_44 , L_42 ) ;
return 0 ;
V_164:
F_71 ( V_2 ) ;
F_88 ( V_2 ) ;
V_163:
F_102 ( V_2 ) ;
V_162:
F_55 ( V_2 ) ;
V_161:
return V_100 ;
}
static void F_107 ( struct V_99 * V_15 )
{
struct V_1 * V_2 = F_108 ( V_15 ) ;
F_109 ( & V_2 -> V_7 ) ;
F_71 ( V_2 ) ;
F_81 ( V_2 ) ;
F_88 ( V_2 ) ;
F_102 ( V_2 ) ;
F_55 ( V_2 ) ;
}
static int T_12 F_110 ( void )
{
F_111 ( L_43 , V_165 , V_166 ) ;
if ( F_112 () )
V_132 = F_68 ( V_167 , NULL ) ;
return F_113 ( & V_168 ) ;
}
static void T_13 F_114 ( void )
{
F_115 ( & V_168 ) ;
F_72 ( V_132 ) ;
}
