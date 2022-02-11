static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ,
V_4 , V_5 , 1 ) ) {
F_3 ( V_2 -> V_6 ,
L_1 ,
V_4 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_5 ( V_2 -> V_3 + V_8 ) ;
V_7 |= V_9 ;
F_6 ( V_7 , V_2 -> V_3 + V_8 ) ;
V_7 |= V_10 ;
F_6 ( V_7 , V_2 -> V_3 + V_8 ) ;
if ( F_2 ( V_2 -> V_3 ,
V_8 , V_11 , 0 ) ) {
F_3 ( V_2 -> V_6 ,
L_1 ,
V_8 ) ;
}
F_1 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_12 , V_2 -> V_3 + V_13 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_6 ( 0x0 , V_2 -> V_3 + V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
memset ( V_2 -> V_14 , 0 , V_2 -> V_15 ) ;
F_10 ( V_2 -> V_3 ) ;
F_6 ( V_16 , V_2 -> V_3 + V_17 ) ;
F_6 ( V_18 | V_19 |
V_20 | V_21 |
V_22 ,
V_2 -> V_3 + V_8 ) ;
F_6 ( V_2 -> V_23 , V_2 -> V_3 + V_24 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_25 ;
memset ( V_2 -> V_26 , 0 , V_2 -> V_15 ) ;
F_10 ( V_2 -> V_3 ) ;
F_6 ( V_2 -> V_15 / 4 , V_2 -> V_3 + V_27 ) ;
F_6 ( V_16 , V_2 -> V_3 + V_17 ) ;
V_25 = F_5 ( V_2 -> V_3 + V_28 ) ;
V_25 |= V_29 ;
F_6 ( V_25 , V_2 -> V_3 + V_28 ) ;
V_25 &= ~ V_30 ;
F_6 ( V_25 , V_2 -> V_3 + V_28 ) ;
V_25 = ( V_25 &
~ ( V_31 | V_32 ) ) |
V_32 ;
F_6 ( V_25 , V_2 -> V_3 + V_28 ) ;
F_6 ( V_2 -> V_33 , V_2 -> V_3 + V_34 ) ;
F_6 ( 0x0 , V_2 -> V_3 + V_35 ) ;
F_6 ( V_18 | V_19 |
V_20 | V_21 |
V_22 ,
V_2 -> V_3 + V_8 ) ;
F_6 ( V_2 -> V_23 , V_2 -> V_3 + V_24 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_6 ( V_36 , V_2 -> V_3 + V_17 ) ;
F_6 ( V_18 | V_19 ,
V_2 -> V_3 + V_8 ) ;
F_6 ( 0x0 , V_2 -> V_3 + V_37 ) ;
F_7 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static int F_14 ( struct V_1 * V_2 , enum V_38 V_39 )
{
unsigned long V_40 ;
F_15 ( & V_2 -> V_41 , V_40 ) ;
if ( V_2 -> V_42 ) {
F_16 ( & V_2 -> V_41 , V_40 ) ;
return - V_43 ;
}
if ( V_2 -> V_44 == V_45 ) {
F_9 ( V_2 ) ;
} else if ( V_2 -> V_44 == V_46 ) {
F_12 ( V_2 ) ;
} else {
if ( V_39 == V_16 )
F_9 ( V_2 ) ;
else
F_13 ( V_2 ) ;
}
V_2 -> V_47 = true ;
F_16 ( & V_2 -> V_41 , V_40 ) ;
F_17 ( V_2 -> V_6 , L_2 ) ;
return 0 ;
}
static int F_18 ( struct V_48 * V_49 , T_1 V_39 )
{
struct V_1 * V_2 = F_19 ( V_49 -> V_6 . V_50 ) ;
return F_14 ( V_2 , V_16 ) ;
}
static int F_20 ( struct V_48 * V_49 , int V_51 ,
int V_52 )
{
struct V_1 * V_2 = F_19 ( V_49 -> V_6 . V_50 ) ;
return F_14 ( V_2 , V_36 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
enum V_53 V_54 ;
T_2 V_55 ;
char * V_56 ;
T_1 V_57 ;
int V_58 ;
V_54 = F_22 ( F_5 ( V_2 -> V_3 + V_59 ) , 8 , 10 ) ;
if ( V_54 == V_60 )
V_55 = 1 ;
else if ( V_54 == V_61 )
V_55 = 2 ;
else if ( V_54 == V_62 )
V_55 = 4 ;
else
V_55 = 8 ;
V_56 = V_2 -> V_14 ;
while ( 1 ) {
for ( V_58 = 0 ; V_58 < V_55 ; V_58 ++ ) {
V_57 = F_5 ( V_2 -> V_3 + V_63 ) ;
if ( V_57 == 0xFFFFFFFF )
return;
memcpy ( V_56 , & V_57 , 4 ) ;
V_56 += 4 ;
}
}
}
static void F_23 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
F_21 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_64 , V_65 ;
V_64 = F_5 ( V_2 -> V_3 + V_66 ) ;
V_65 = F_5 ( V_2 -> V_3 + V_4 ) ;
if ( V_65 & F_25 ( 0 ) )
V_2 -> V_14 = V_2 -> V_26 + V_64 - V_2 -> V_33 ;
else
V_2 -> V_14 = V_2 -> V_26 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
F_24 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 -> V_3 ) ;
}
static void F_28 ( struct V_1 * V_2 , enum V_38 V_39 )
{
unsigned long V_40 ;
F_15 ( & V_2 -> V_41 , V_40 ) ;
if ( V_2 -> V_42 )
goto V_67;
if ( V_2 -> V_44 == V_45 ) {
F_23 ( V_2 ) ;
} else if ( V_2 -> V_44 == V_46 ) {
F_26 ( V_2 ) ;
} else {
if ( V_39 == V_16 )
F_23 ( V_2 ) ;
else
F_27 ( V_2 ) ;
}
V_67:
V_2 -> V_47 = false ;
F_16 ( & V_2 -> V_41 , V_40 ) ;
F_17 ( V_2 -> V_6 , L_3 ) ;
}
static void F_29 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_19 ( V_49 -> V_6 . V_50 ) ;
F_28 ( V_2 , V_16 ) ;
}
static void F_30 ( struct V_48 * V_49 , int V_51 ,
int V_52 )
{
struct V_1 * V_2 = F_19 ( V_49 -> V_6 . V_50 ) ;
F_28 ( V_2 , V_36 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_68 ;
unsigned long V_40 ;
enum V_38 V_39 ;
F_15 ( & V_2 -> V_41 , V_40 ) ;
if ( ! V_2 -> V_47 )
goto V_67;
if ( V_2 -> V_44 == V_45 ) {
F_23 ( V_2 ) ;
} else if ( V_2 -> V_44 == V_46 ) {
F_26 ( V_2 ) ;
} else {
V_39 = F_5 ( V_2 -> V_3 + V_17 ) ;
if ( V_39 == V_16 ) {
F_23 ( V_2 ) ;
} else {
V_68 = - V_69 ;
goto V_70;
}
}
V_67:
V_2 -> V_42 = true ;
F_16 ( & V_2 -> V_41 , V_40 ) ;
F_17 ( V_2 -> V_6 , L_4 ) ;
return 0 ;
V_70:
F_16 ( & V_2 -> V_41 , V_40 ) ;
return V_68 ;
}
static void F_32 ( struct V_1 * V_2 )
{
unsigned long V_40 ;
enum V_38 V_39 ;
F_15 ( & V_2 -> V_41 , V_40 ) ;
if ( ! V_2 -> V_47 )
goto V_67;
if ( V_2 -> V_44 == V_45 ) {
F_9 ( V_2 ) ;
} else if ( V_2 -> V_44 == V_46 ) {
F_12 ( V_2 ) ;
} else {
V_39 = F_5 ( V_2 -> V_3 + V_17 ) ;
if ( V_39 == V_16 )
F_9 ( V_2 ) ;
}
V_67:
V_2 -> V_42 = false ;
F_16 ( & V_2 -> V_41 , V_40 ) ;
F_17 ( V_2 -> V_6 , L_5 ) ;
}
static int F_33 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
struct V_1 * V_2 = F_34 ( V_72 -> V_73 ,
struct V_1 , V_74 ) ;
int V_68 = 0 ;
if ( V_2 -> V_75 ++ )
goto V_67;
V_68 = F_31 ( V_2 ) ;
if ( V_68 )
return V_68 ;
V_67:
F_35 ( V_71 , V_72 ) ;
F_36 ( V_2 -> V_6 , L_6 , V_76 ) ;
return 0 ;
}
static T_3 F_37 ( struct V_72 * V_72 , char T_4 * V_77 , T_5 V_78 ,
T_6 * V_79 )
{
struct V_1 * V_2 = F_34 ( V_72 -> V_73 ,
struct V_1 , V_74 ) ;
char * V_56 = V_2 -> V_14 + * V_79 ;
if ( * V_79 + V_78 > V_2 -> V_15 )
V_78 = V_2 -> V_15 - * V_79 ;
if ( V_2 -> V_44 == V_46 ) {
if ( V_56 == ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) )
V_56 = V_2 -> V_26 ;
else if ( V_56 > ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) )
V_56 -= V_2 -> V_15 ;
if ( ( V_56 + V_78 ) > ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) )
V_78 = ( char * ) ( V_2 -> V_26 + V_2 -> V_15 ) - V_56 ;
}
if ( F_38 ( V_77 , V_56 , V_78 ) ) {
F_36 ( V_2 -> V_6 , L_7 , V_76 ) ;
return - V_80 ;
}
* V_79 += V_78 ;
F_36 ( V_2 -> V_6 , L_8 ,
V_76 , V_78 , ( int ) ( V_2 -> V_15 - * V_79 ) ) ;
return V_78 ;
}
static int F_39 ( struct V_71 * V_71 , struct V_72 * V_72 )
{
struct V_1 * V_2 = F_34 ( V_72 -> V_73 ,
struct V_1 , V_74 ) ;
if ( -- V_2 -> V_75 ) {
if ( V_2 -> V_75 < 0 ) {
F_3 ( V_2 -> V_6 , L_9 ) ;
V_2 -> V_75 = 0 ;
}
goto V_67;
}
F_32 ( V_2 ) ;
V_67:
F_36 ( V_2 -> V_6 , L_10 , V_76 ) ;
return 0 ;
}
static T_3 F_40 ( struct V_81 * V_6 ,
struct V_82 * V_83 , char * V_14 )
{
unsigned long V_40 ;
T_1 V_84 , V_85 , V_86 , V_87 , V_88 ;
T_1 V_89 , V_90 , V_91 , V_38 , V_92 ;
T_1 V_93 ;
struct V_1 * V_2 = F_19 ( V_6 -> V_50 ) ;
F_41 ( V_2 -> V_6 ) ;
F_15 ( & V_2 -> V_41 , V_40 ) ;
F_10 ( V_2 -> V_3 ) ;
V_84 = F_5 ( V_2 -> V_3 + V_27 ) ;
V_85 = F_5 ( V_2 -> V_3 + V_4 ) ;
V_86 = F_5 ( V_2 -> V_3 + V_94 ) ;
V_87 = F_5 ( V_2 -> V_3 + V_66 ) ;
V_88 = F_5 ( V_2 -> V_3 + V_24 ) ;
V_89 = F_5 ( V_2 -> V_3 + V_13 ) ;
V_90 = F_5 ( V_2 -> V_3 + V_95 ) ;
V_91 = F_5 ( V_2 -> V_3 + V_8 ) ;
V_38 = F_5 ( V_2 -> V_3 + V_17 ) ;
V_92 = F_5 ( V_2 -> V_3 + V_96 ) ;
V_93 = F_5 ( V_2 -> V_3 + V_59 ) ;
F_11 ( V_2 -> V_3 ) ;
F_16 ( & V_2 -> V_41 , V_40 ) ;
F_42 ( V_2 -> V_6 ) ;
return sprintf ( V_14 ,
L_11
L_12
L_13
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
V_84 , V_85 , V_86 , V_87 , V_88 ,
V_89 , V_90 , V_91 , V_38 , V_92 , V_93 ) ;
return - V_97 ;
}
static T_3 F_43 ( struct V_81 * V_6 ,
struct V_82 * V_83 , char * V_14 )
{
struct V_1 * V_2 = F_19 ( V_6 -> V_50 ) ;
unsigned long V_65 = V_2 -> V_23 ;
return sprintf ( V_14 , L_22 , V_65 ) ;
}
static T_3 F_44 ( struct V_81 * V_6 ,
struct V_82 * V_83 ,
const char * V_14 , T_5 V_15 )
{
int V_68 ;
unsigned long V_65 ;
struct V_1 * V_2 = F_19 ( V_6 -> V_50 ) ;
V_68 = F_45 ( V_14 , 16 , & V_65 ) ;
if ( V_68 )
return V_68 ;
V_2 -> V_23 = V_65 ;
return V_15 ;
}
static int F_46 ( struct V_98 * V_99 , const struct V_100 * V_101 )
{
int V_68 = 0 ;
T_1 V_93 ;
void T_7 * V_3 ;
struct V_81 * V_6 = & V_99 -> V_6 ;
struct V_102 * V_103 = NULL ;
struct V_1 * V_2 ;
struct V_104 * V_105 = & V_99 -> V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 = V_99 -> V_6 . V_110 ;
if ( V_109 ) {
V_103 = F_47 ( V_6 , V_109 ) ;
if ( F_48 ( V_103 ) )
return F_49 ( V_103 ) ;
V_99 -> V_6 . V_111 = V_103 ;
}
V_2 = F_50 ( V_6 , sizeof( * V_2 ) , V_112 ) ;
if ( ! V_2 )
return - V_113 ;
V_2 -> V_6 = & V_99 -> V_6 ;
F_51 ( V_6 , V_2 ) ;
V_3 = F_52 ( V_6 , V_105 ) ;
if ( F_48 ( V_3 ) )
return F_49 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
F_53 ( & V_2 -> V_41 ) ;
V_93 = F_5 ( V_2 -> V_3 + V_59 ) ;
V_2 -> V_44 = F_22 ( V_93 , 6 , 7 ) ;
if ( V_2 -> V_44 == V_46 ) {
if ( V_109 )
V_68 = F_54 ( V_109 ,
L_23 ,
& V_2 -> V_15 ) ;
if ( V_68 )
V_2 -> V_15 = V_114 ;
} else {
V_2 -> V_15 = F_5 ( V_2 -> V_3 + V_27 ) * 4 ;
}
F_42 ( & V_99 -> V_6 ) ;
if ( V_2 -> V_44 == V_46 ) {
V_2 -> V_26 = F_55 ( V_6 , V_2 -> V_15 ,
& V_2 -> V_33 , V_112 ) ;
if ( ! V_2 -> V_26 )
return - V_113 ;
memset ( V_2 -> V_26 , 0 , V_2 -> V_15 ) ;
V_2 -> V_14 = V_2 -> V_26 ;
} else {
V_2 -> V_14 = F_50 ( V_6 , V_2 -> V_15 , V_112 ) ;
if ( ! V_2 -> V_14 )
return - V_113 ;
}
V_107 = F_50 ( V_6 , sizeof( * V_107 ) , V_112 ) ;
if ( ! V_107 ) {
V_68 = - V_113 ;
goto V_115;
}
V_107 -> V_103 = V_103 ;
V_107 -> V_6 = V_6 ;
V_107 -> V_116 . V_117 = V_118 ;
if ( V_2 -> V_44 == V_45 ) {
V_107 -> type = V_119 ;
V_107 -> V_120 = & V_121 ;
V_107 -> V_122 = V_123 ;
} else if ( V_2 -> V_44 == V_46 ) {
V_107 -> type = V_119 ;
V_107 -> V_120 = & V_124 ;
V_107 -> V_122 = V_125 ;
} else {
V_107 -> type = V_126 ;
V_107 -> V_116 . V_127 = V_128 ;
V_107 -> V_120 = & V_129 ;
V_107 -> V_122 = V_130 ;
}
V_2 -> V_49 = F_56 ( V_107 ) ;
if ( F_48 ( V_2 -> V_49 ) ) {
V_68 = F_49 ( V_2 -> V_49 ) ;
goto V_115;
}
V_2 -> V_74 . V_131 = V_103 -> V_131 ;
V_2 -> V_74 . V_132 = V_133 ;
V_2 -> V_74 . V_134 = & V_135 ;
V_68 = F_57 ( & V_2 -> V_74 ) ;
if ( V_68 )
goto V_136;
F_17 ( V_6 , L_24 ) ;
return 0 ;
V_136:
F_58 ( V_2 -> V_49 ) ;
V_115:
if ( V_2 -> V_44 == V_46 )
F_59 ( V_6 , V_2 -> V_15 ,
V_2 -> V_26 , V_2 -> V_33 ) ;
return V_68 ;
}
