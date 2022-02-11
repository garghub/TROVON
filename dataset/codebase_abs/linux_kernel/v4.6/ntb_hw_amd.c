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
static int F_32 ( struct V_6 * V_7 , T_5 V_57 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
F_27 ( ( V_58 ) V_57 , V_19 + V_63 ) ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
return F_3 ( V_7 ) -> V_64 ;
}
static T_6 F_34 ( struct V_6 * V_7 , int V_3 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_65 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_64 )
return 0 ;
V_65 = V_2 -> V_66 + ( V_3 << 2 ) ;
return F_11 ( V_19 + V_67 + V_65 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
int V_3 , T_6 V_68 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_65 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_64 )
return - V_5 ;
V_65 = V_2 -> V_66 + ( V_3 << 2 ) ;
F_10 ( V_68 , V_19 + V_67 + V_65 ) ;
return 0 ;
}
static T_6 F_36 ( struct V_6 * V_7 , int V_3 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_65 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_64 )
return - V_5 ;
V_65 = V_2 -> V_69 + ( V_3 << 2 ) ;
return F_11 ( V_19 + V_67 + V_65 ) ;
}
static int F_37 ( struct V_6 * V_7 ,
int V_3 , T_6 V_68 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_65 ;
if ( V_3 < 0 || V_3 >= V_2 -> V_64 )
return - V_5 ;
V_65 = V_2 -> V_69 + ( V_3 << 2 ) ;
F_10 ( V_68 , V_19 + V_67 + V_65 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , T_6 V_70 )
{
void T_4 * V_19 = V_2 -> V_24 ;
int V_71 ;
V_71 = F_11 ( V_19 + V_72 ) ;
V_71 |= V_70 ;
F_10 ( V_71 , V_19 + V_72 ) ;
V_2 -> V_30 |= V_70 ;
}
static void F_39 ( struct V_1 * V_2 , int V_73 )
{
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_74 ;
V_74 = F_11 ( V_19 + V_75 ) ;
if ( ! ( V_74 & V_46 ) )
return;
F_17 ( F_18 ( V_2 ) , L_4 , V_74 , V_73 ) ;
V_74 &= V_46 ;
switch ( V_74 ) {
case V_76 :
F_40 ( F_18 ( V_2 ) , L_5 ) ;
break;
case V_32 :
F_38 ( V_2 , V_32 ) ;
F_41 ( & V_2 -> V_7 ) ;
F_42 ( & V_2 -> V_77 , V_78 ) ;
break;
case V_79 :
case V_80 :
F_38 ( V_2 , V_74 ) ;
F_41 ( & V_2 -> V_7 ) ;
break;
case V_33 :
V_19 = V_2 -> V_20 ;
V_74 = F_11 ( V_19 + V_81 ) ;
if ( V_74 & 0x1 )
F_40 ( F_18 ( V_2 ) , L_6 ) ;
F_38 ( V_2 , V_33 ) ;
F_42 ( & V_2 -> V_77 ,
V_78 ) ;
break;
default:
F_40 ( F_18 ( V_2 ) , L_7 , V_74 ) ;
break;
}
}
static T_7 F_43 ( struct V_1 * V_2 , int V_73 )
{
F_17 ( F_18 ( V_2 ) , L_8 , V_73 ) ;
if ( V_73 > ( V_82 - 1 ) || ( V_2 -> V_83 == 1 ) )
F_39 ( V_2 , V_73 ) ;
if ( V_73 < V_82 )
F_44 ( & V_2 -> V_7 , V_73 ) ;
return V_84 ;
}
static T_7 F_45 ( int V_85 , void * V_86 )
{
struct V_87 * V_88 = V_86 ;
return F_43 ( V_88 -> V_2 , V_88 -> V_89 ) ;
}
static T_7 F_46 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
return F_43 ( V_2 , V_85 - F_47 ( V_2 ) -> V_85 ) ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_90 , int V_91 )
{
struct V_92 * V_13 ;
int V_93 , V_94 , V_95 , V_96 ;
V_13 = F_47 ( V_2 ) ;
V_96 = F_49 ( & V_13 -> V_86 ) ;
V_2 -> V_61 = V_2 -> V_53 ;
V_2 -> V_73 = F_50 ( V_91 * sizeof( * V_2 -> V_73 ) ,
V_97 , V_96 ) ;
if ( ! V_2 -> V_73 )
goto V_98;
V_2 -> V_99 = F_50 ( V_91 * sizeof( * V_2 -> V_99 ) ,
V_97 , V_96 ) ;
if ( ! V_2 -> V_99 )
goto V_100;
for ( V_94 = 0 ; V_94 < V_91 ; ++ V_94 )
V_2 -> V_99 [ V_94 ] . V_101 = V_94 ;
V_95 = F_51 ( V_13 , V_2 -> V_99 ,
V_90 , V_91 ) ;
if ( V_95 < 0 )
goto V_102;
if ( V_95 < V_90 ) {
F_52 ( V_13 ) ;
goto V_102;
}
for ( V_94 = 0 ; V_94 < V_95 ; ++ V_94 ) {
V_2 -> V_73 [ V_94 ] . V_2 = V_2 ;
V_2 -> V_73 [ V_94 ] . V_89 = V_94 ;
V_93 = F_53 ( V_2 -> V_99 [ V_94 ] . V_103 , F_45 , 0 ,
L_9 , & V_2 -> V_73 [ V_94 ] ) ;
if ( V_93 )
goto V_104;
}
F_17 ( F_18 ( V_2 ) , L_10 ) ;
V_2 -> V_54 = V_90 ;
V_2 -> V_83 = V_91 ;
return 0 ;
V_104:
while ( V_94 -- > 0 )
F_54 ( V_2 -> V_99 [ V_94 ] . V_103 , V_2 ) ;
F_52 ( V_13 ) ;
V_102:
F_55 ( V_2 -> V_99 ) ;
V_100:
F_55 ( V_2 -> V_73 ) ;
V_98:
V_2 -> V_99 = NULL ;
V_2 -> V_73 = NULL ;
V_93 = F_56 ( V_13 ) ;
if ( V_93 )
goto V_105;
V_93 = F_53 ( V_13 -> V_85 , F_46 , 0 ,
L_11 , V_2 ) ;
if ( V_93 )
goto V_106;
F_17 ( F_18 ( V_2 ) , L_12 ) ;
V_2 -> V_54 = 1 ;
V_2 -> V_83 = 1 ;
return 0 ;
V_106:
F_57 ( V_13 ) ;
V_105:
F_58 ( V_13 , 1 ) ;
V_93 = F_53 ( V_13 -> V_85 , F_46 , V_107 ,
L_11 , V_2 ) ;
if ( V_93 )
goto V_108;
F_17 ( F_18 ( V_2 ) , L_13 ) ;
V_2 -> V_54 = 1 ;
V_2 -> V_83 = 1 ;
return 0 ;
V_108:
return V_93 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_92 * V_13 ;
void T_4 * V_19 = V_2 -> V_24 ;
int V_94 ;
V_13 = F_47 ( V_2 ) ;
V_2 -> V_61 = V_2 -> V_53 ;
F_10 ( V_2 -> V_61 , V_19 + V_62 ) ;
if ( V_2 -> V_99 ) {
V_94 = V_2 -> V_83 ;
while ( V_94 -- )
F_54 ( V_2 -> V_99 [ V_94 ] . V_103 , & V_2 -> V_73 [ V_94 ] ) ;
F_52 ( V_13 ) ;
F_55 ( V_2 -> V_99 ) ;
F_55 ( V_2 -> V_73 ) ;
} else {
F_54 ( V_13 -> V_85 , V_2 ) ;
if ( F_60 ( V_13 ) )
F_57 ( V_13 ) ;
else
F_58 ( V_13 , 0 ) ;
}
}
static T_8 F_61 ( struct V_109 * V_110 , char T_9 * V_111 ,
T_10 V_112 , T_11 * V_113 )
{
struct V_1 * V_2 ;
void T_4 * V_19 ;
char * V_114 ;
T_10 V_115 ;
T_8 V_38 , V_116 ;
union { T_5 V_117 ; T_6 V_118 ; V_58 V_119 ; } V_120 ;
V_2 = V_110 -> V_121 ;
V_19 = V_2 -> V_24 ;
V_115 = F_62 ( V_112 , 0x800ul ) ;
V_114 = F_63 ( V_115 , V_97 ) ;
if ( ! V_114 )
return - V_122 ;
V_116 = 0 ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_14 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_15 ,
F_65 ( V_2 -> V_7 . V_48 ) ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_16 , V_2 -> V_39 ) ;
if ( ! F_12 ( V_2 ) ) {
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_17 ) ;
} else {
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_18 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_19 ,
F_15 ( V_2 -> V_39 ) ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_20 ,
F_16 ( V_2 -> V_39 ) ) ;
}
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_21 , V_2 -> V_4 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_22 , V_2 -> V_64 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_23 , V_2 -> V_54 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_24 , V_2 -> V_83 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_25 , V_2 -> V_53 ) ;
V_120 . V_118 = F_11 ( V_2 -> V_24 + V_62 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_26 , V_120 . V_118 ) ;
V_120 . V_118 = F_11 ( V_19 + V_56 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_27 , V_120 . V_118 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_28 ) ;
V_120 . V_117 = F_9 ( V_19 + V_28 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_29 , V_120 . V_117 ) ;
V_120 . V_117 = F_9 ( V_2 -> V_24 + V_25 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_30 , V_120 . V_117 ) ;
V_120 . V_117 = F_9 ( V_2 -> V_24 + V_123 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_31 , V_120 . V_117 ) ;
V_120 . V_118 = F_11 ( V_19 + V_29 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_32 , V_120 . V_118 ) ;
V_120 . V_117 = F_9 ( V_2 -> V_24 + V_26 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_33 , V_120 . V_117 ) ;
V_120 . V_117 = F_9 ( V_2 -> V_24 + V_124 ) ;
V_116 += F_64 ( V_114 + V_116 , V_115 - V_116 ,
L_34 , V_120 . V_117 ) ;
V_38 = F_66 ( V_111 , V_112 , V_113 , V_114 , V_116 ) ;
F_55 ( V_114 ) ;
return V_38 ;
}
static void F_67 ( struct V_1 * V_2 )
{
if ( ! V_125 ) {
V_2 -> V_125 = NULL ;
V_2 -> V_126 = NULL ;
} else {
V_2 -> V_125 =
F_68 ( F_69 ( V_2 ) , V_125 ) ;
if ( ! V_2 -> V_125 )
V_2 -> V_126 = NULL ;
else
V_2 -> V_126 =
F_70 ( L_35 , V_127 ,
V_2 -> V_125 , V_2 ,
& V_128 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
F_72 ( V_2 -> V_125 ) ;
}
static inline void F_73 ( struct V_1 * V_2 ,
struct V_92 * V_13 )
{
V_2 -> V_7 . V_13 = V_13 ;
V_2 -> V_7 . V_48 = V_129 ;
V_2 -> V_7 . V_130 = & V_131 ;
V_2 -> V_45 = V_46 ;
F_74 ( & V_2 -> V_60 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_20 ;
T_6 V_71 , V_132 ;
int V_93 ;
V_71 = F_11 ( V_19 + V_133 ) ;
V_71 &= V_134 ;
F_17 ( F_18 ( V_2 ) , L_36 , V_135 , V_71 ) ;
if ( V_71 == V_2 -> V_31 )
return 0 ;
V_2 -> V_31 = V_71 ;
V_93 = F_76 ( V_2 -> V_7 . V_13 ,
V_136 , & V_132 ) ;
if ( V_93 )
return 0 ;
V_2 -> V_39 = V_132 ;
return 1 ;
}
static void F_77 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_78 ( V_138 ) ;
if ( F_75 ( V_2 ) )
F_41 ( & V_2 -> V_7 ) ;
if ( ! F_12 ( V_2 ) )
F_42 ( & V_2 -> V_77 , V_78 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return F_48 ( V_2 , V_82 , V_139 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
unsigned int V_71 ;
V_71 = F_11 ( V_19 + V_133 ) ;
if ( ! ( V_71 & V_140 ) ) {
V_71 |= V_140 ;
F_10 ( V_71 , V_19 + V_133 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
unsigned int V_71 ;
V_71 = F_11 ( V_19 + V_133 ) ;
if ( V_71 & V_140 ) {
V_71 &= ~ V_140 ;
F_10 ( V_71 , V_19 + V_133 ) ;
F_11 ( V_19 + V_133 ) ;
}
}
static int F_82 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
V_2 -> V_4 = V_141 ;
V_2 -> V_64 = V_142 ;
V_2 -> V_54 = V_82 ;
switch ( V_2 -> V_7 . V_48 ) {
case V_143 :
case V_49 :
V_2 -> V_64 >>= 1 ;
if ( V_2 -> V_7 . V_48 == V_143 ) {
V_2 -> V_66 = 0 ;
V_2 -> V_69 = 0x20 ;
} else {
V_2 -> V_66 = 0x20 ;
V_2 -> V_69 = 0 ;
}
F_83 ( & V_2 -> V_77 , F_77 ) ;
F_42 ( & V_2 -> V_77 , V_78 ) ;
break;
default:
F_84 ( F_18 ( V_2 ) , L_37 ) ;
return - V_5 ;
}
V_2 -> V_53 = F_85 ( V_2 -> V_54 ) - 1 ;
F_10 ( V_2 -> V_45 , V_19 + V_47 ) ;
return 0 ;
}
static enum V_144 F_86 ( struct V_1 * V_2 )
{
void T_4 * V_19 = V_2 -> V_24 ;
T_6 V_145 ;
V_145 = F_11 ( V_19 + V_133 ) ;
if ( V_145 & V_146 )
return V_49 ;
else
return V_143 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_92 * V_13 ;
int V_93 = 0 ;
V_13 = F_47 ( V_2 ) ;
V_2 -> V_7 . V_48 = F_86 ( V_2 ) ;
F_17 ( F_18 ( V_2 ) , L_38 ,
F_65 ( V_2 -> V_7 . V_48 ) ) ;
V_93 = F_82 ( V_2 ) ;
if ( V_93 )
return V_93 ;
V_93 = F_79 ( V_2 ) ;
if ( V_93 ) {
F_84 ( F_18 ( V_2 ) , L_39 ) ;
return V_93 ;
}
V_2 -> V_53 = F_85 ( V_2 -> V_54 ) - 1 ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_89 ( & V_2 -> V_77 ) ;
F_59 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_92 * V_13 )
{
int V_93 ;
F_91 ( V_13 , V_2 ) ;
V_93 = F_92 ( V_13 ) ;
if ( V_93 )
goto V_147;
V_93 = F_93 ( V_13 , V_148 ) ;
if ( V_93 )
goto V_149;
F_94 ( V_13 ) ;
V_93 = F_95 ( V_13 , F_96 ( 64 ) ) ;
if ( V_93 ) {
V_93 = F_95 ( V_13 , F_96 ( 32 ) ) ;
if ( V_93 )
goto V_150;
F_97 ( F_18 ( V_2 ) , L_40 ) ;
}
V_93 = F_98 ( V_13 , F_96 ( 64 ) ) ;
if ( V_93 ) {
V_93 = F_98 ( V_13 , F_96 ( 32 ) ) ;
if ( V_93 )
goto V_150;
F_97 ( F_18 ( V_2 ) , L_41 ) ;
}
V_2 -> V_24 = F_99 ( V_13 , 0 , 0 ) ;
if ( ! V_2 -> V_24 ) {
V_93 = - V_27 ;
goto V_150;
}
V_2 -> V_20 = V_2 -> V_24 + V_151 ;
return 0 ;
V_150:
F_100 ( V_13 ) ;
V_149:
F_101 ( V_13 ) ;
V_147:
F_91 ( V_13 , NULL ) ;
return V_93 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_92 * V_13 = F_47 ( V_2 ) ;
F_103 ( V_13 , V_2 -> V_24 ) ;
F_100 ( V_13 ) ;
F_104 ( V_13 ) ;
F_101 ( V_13 ) ;
F_91 ( V_13 , NULL ) ;
}
static int F_105 ( struct V_92 * V_13 ,
const struct V_152 * V_153 )
{
struct V_1 * V_2 ;
int V_93 , V_96 ;
V_96 = F_49 ( & V_13 -> V_86 ) ;
V_2 = F_50 ( sizeof( * V_2 ) , V_97 , V_96 ) ;
if ( ! V_2 ) {
V_93 = - V_122 ;
goto V_154;
}
F_73 ( V_2 , V_13 ) ;
V_93 = F_90 ( V_2 , V_13 ) ;
if ( V_93 )
goto V_155;
V_93 = F_87 ( V_2 ) ;
if ( V_93 )
goto V_156;
F_80 ( V_2 ) ;
F_75 ( V_2 ) ;
F_67 ( V_2 ) ;
V_93 = F_106 ( & V_2 -> V_7 ) ;
if ( V_93 )
goto V_157;
F_40 ( & V_13 -> V_86 , L_42 ) ;
return 0 ;
V_157:
F_71 ( V_2 ) ;
F_88 ( V_2 ) ;
V_156:
F_102 ( V_2 ) ;
V_155:
F_55 ( V_2 ) ;
V_154:
return V_93 ;
}
static void F_107 ( struct V_92 * V_13 )
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
F_111 ( L_43 , V_158 , V_159 ) ;
if ( F_112 () )
V_125 = F_68 ( V_160 , NULL ) ;
return F_113 ( & V_161 ) ;
}
static void T_13 F_114 ( void )
{
F_115 ( & V_161 ) ;
F_72 ( V_125 ) ;
}
