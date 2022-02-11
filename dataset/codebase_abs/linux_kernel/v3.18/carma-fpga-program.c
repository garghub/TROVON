static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = false ;
V_2 -> V_5 = 0 ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 , struct V_1 , V_7 ) ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_6 ( V_2 ) ;
}
static void F_7 ( bool V_9 )
{
if ( V_9 )
F_8 ( V_10 , V_11 ) ;
else
F_8 ( V_10 , V_12 ) ;
}
static int F_9 ( void T_1 * V_13 )
{
return F_10 ( V_13 + V_14 ) ;
}
static int F_11 ( void T_1 * V_13 )
{
return F_10 ( V_13 + V_15 ) & V_16 ;
}
static int F_12 ( void T_1 * V_13 )
{
return F_10 ( V_13 + V_17 ) == 0 ;
}
static void F_13 ( void T_1 * V_13 , T_2 V_18 )
{
F_14 ( V_18 , V_13 + V_19 ) ;
}
static void F_15 ( void T_1 * V_13 , T_2 V_20 )
{
F_14 ( V_20 , V_13 + V_21 ) ;
}
static void F_16 ( struct V_1 * V_2 , bool V_22 )
{
T_2 V_18 ;
V_18 = ( V_22 ) ? ( V_23 | V_24 ) : V_23 ;
F_14 ( V_18 , V_2 -> V_13 + V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_14 ( 0x0 , V_2 -> V_13 + V_25 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 V_26 , V_27 , V_28 , V_29 , V_30 , V_31 ;
if ( V_2 -> V_27 == 0 )
return;
V_26 = F_10 ( V_2 -> V_13 + V_25 ) ;
V_27 = F_10 ( V_2 -> V_13 + V_15 ) ;
V_28 = F_10 ( V_2 -> V_13 + V_14 ) ;
V_29 = F_10 ( V_2 -> V_13 + V_17 ) ;
V_30 = F_10 ( V_2 -> V_13 + V_21 ) ;
V_31 = F_10 ( V_2 -> V_13 + V_32 ) ;
F_19 ( V_2 -> V_33 , L_1 ) ;
F_19 ( V_2 -> V_33 , L_2 , V_26 ) ;
F_19 ( V_2 -> V_33 , L_3 , V_27 ) ;
F_19 ( V_2 -> V_33 , L_4 , V_28 ) ;
F_19 ( V_2 -> V_33 , L_5 , V_29 ) ;
F_19 ( V_2 -> V_33 , L_6 , V_30 ) ;
F_19 ( V_2 -> V_33 , L_7 , V_31 ) ;
}
static bool F_20 ( struct V_1 * V_2 )
{
T_3 V_18 ;
V_18 = F_21 ( V_2 -> V_13 + V_34 ) ;
if ( V_18 & V_35 )
return false ;
return V_18 == V_36 ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned long V_37 ;
T_3 V_18 ;
F_23 ( 0x0 , V_2 -> V_13 + V_38 ) ;
F_24 ( 500 ) ;
V_37 = V_39 ;
while ( F_25 ( V_39 , V_37 + V_40 ) ) {
V_18 = F_21 ( V_2 -> V_13 + V_34 ) ;
if ( ! ( V_18 & V_36 ) )
break;
F_26 ( 5000 , 10000 ) ;
}
V_18 = F_21 ( V_2 -> V_13 + V_34 ) ;
if ( V_18 & V_36 ) {
F_19 ( V_2 -> V_33 , L_8
L_9 , V_18 ) ;
}
if ( V_18 & V_35 ) {
F_19 ( V_2 -> V_33 , L_8
L_10 , V_18 ) ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
unsigned long V_37 = V_39 ;
if ( F_20 ( V_2 ) ) {
F_28 ( V_2 -> V_33 , L_11 ) ;
return 0 ;
}
F_23 ( V_41 , V_2 -> V_13 + V_38 ) ;
while ( F_25 ( V_39 , V_37 + V_40 ) ) {
if ( F_20 ( V_2 ) )
return 0 ;
F_26 ( 5000 , 10000 ) ;
}
return F_20 ( V_2 ) ? 0 : - V_42 ;
}
static bool F_29 ( struct V_1 * V_2 )
{
T_3 V_18 ;
V_18 = F_21 ( V_2 -> V_13 + V_38 ) ;
if ( V_18 & V_41 )
return true ;
return false ;
}
static bool F_30 ( struct V_1 * V_2 )
{
if ( ! F_20 ( V_2 ) )
return false ;
return F_10 ( V_2 -> V_13 + V_15 ) & ( 1 << 18 ) ;
}
static int F_31 ( struct V_1 * V_2 , void * V_43 , T_4 V_20 )
{
T_2 * V_44 = V_43 ;
int V_28 = F_9 ( V_2 -> V_13 ) ;
int V_45 , V_46 ;
unsigned long V_47 ;
F_32 ( V_20 % 4 != 0 ) ;
while ( V_20 > 0 ) {
V_46 = F_33 ( T_4 , V_20 , V_28 ) ;
V_47 = V_39 + V_40 / 4 ;
for ( V_45 = 0 ; V_45 < V_46 / 4 ; V_45 ++ )
F_13 ( V_2 -> V_13 , V_44 [ V_45 ] ) ;
V_20 -= V_46 ;
V_44 += V_46 / 4 ;
while ( true ) {
if ( F_12 ( V_2 -> V_13 ) ) {
break;
} else {
F_28 ( V_2 -> V_33 , L_12 ) ;
F_34 () ;
}
if ( F_11 ( V_2 -> V_13 ) ) {
F_19 ( V_2 -> V_33 , L_13 ) ;
return - V_48 ;
}
if ( F_35 ( V_39 , V_47 ) ) {
F_19 ( V_2 -> V_33 , L_14 ) ;
return - V_42 ;
}
F_26 ( 5000 , 10000 ) ;
}
}
return 0 ;
}
static T_5 int F_36 ( struct V_1 * V_2 )
{
int V_49 ;
F_17 ( V_2 ) ;
F_15 ( V_2 -> V_13 , V_2 -> V_5 ) ;
F_28 ( V_2 -> V_33 , L_15 , V_2 -> V_5 ) ;
F_16 ( V_2 , false ) ;
F_28 ( V_2 -> V_33 , L_16 ) ;
V_49 = F_31 ( V_2 , V_2 -> V_3 . V_50 , V_2 -> V_5 ) ;
if ( V_49 )
goto V_51;
V_49 = F_37 ( & V_2 -> V_52 , 2 * V_40 ) ;
if ( ! V_49 ) {
F_19 ( V_2 -> V_33 , L_17 ) ;
V_49 = - V_42 ;
goto V_51;
}
V_49 = V_2 -> V_27 ;
V_51:
F_17 ( V_2 ) ;
return V_49 ;
}
static T_5 int F_38 ( struct V_1 * V_2 )
{
struct V_53 * V_3 = & V_2 -> V_3 ;
struct V_54 * V_55 = V_2 -> V_55 ;
struct V_56 * V_57 ;
T_4 V_58 , V_46 , V_59 = 0 ;
struct V_60 V_61 ;
struct V_62 * V_63 ;
struct V_64 V_65 ;
T_6 V_66 ;
int V_49 , V_45 ;
F_17 ( V_2 ) ;
V_58 = F_39 ( V_2 -> V_5 , V_67 ) ;
V_49 = F_40 ( & V_65 , V_58 , V_68 ) ;
if ( V_49 ) {
F_19 ( V_2 -> V_33 , L_18 ) ;
V_49 = - V_69 ;
goto V_70;
}
V_59 = V_2 -> V_5 ;
F_41 (table.sgl, sg, num_pages, i) {
V_46 = F_33 ( T_4 , V_59 , V_67 ) ;
F_42 ( V_63 ) = V_71 ;
F_43 ( V_63 ) = V_46 ;
V_59 -= V_46 ;
}
V_49 = F_44 ( V_2 -> V_33 , & V_2 -> V_3 ) ;
if ( V_49 ) {
F_19 ( V_2 -> V_33 , L_19 ) ;
goto V_72;
}
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_73 = V_74 ;
V_61 . V_75 = V_76 ;
V_61 . V_77 = F_9 ( V_2 -> V_13 ) / 2 / 4 ;
V_49 = F_45 ( V_55 , & V_61 ) ;
if ( V_49 ) {
F_19 ( V_2 -> V_33 , L_20 ) ;
goto V_78;
}
V_49 = F_46 (chan, 1 )
if ( V_49 ) {
F_19 ( V_2 -> V_33 , L_21 ) ;
goto V_78;
}
V_57 = F_47 ( V_55 , V_65 . V_79 , V_58 ,
V_3 -> V_80 , V_3 -> V_81 , 0 ) ;
if ( ! V_57 ) {
F_19 ( V_2 -> V_33 , L_22 ) ;
V_49 = - V_69 ;
goto V_78;
}
V_66 = V_57 -> V_82 ( V_57 ) ;
if ( F_48 ( V_66 ) ) {
F_19 ( V_2 -> V_33 , L_23 ) ;
V_49 = - V_69 ;
goto V_78;
}
F_49 ( V_55 ) ;
F_15 ( V_2 -> V_13 , V_2 -> V_5 ) ;
F_28 ( V_2 -> V_33 , L_15 , V_2 -> V_5 ) ;
F_16 ( V_2 , true ) ;
F_28 ( V_2 -> V_33 , L_16 ) ;
V_49 = F_37 ( & V_2 -> V_52 , 2 * V_40 ) ;
if ( ! V_49 ) {
F_19 ( V_2 -> V_33 , L_17 ) ;
V_49 = - V_42 ;
goto V_51;
}
V_49 = V_2 -> V_27 ;
V_51:
F_17 ( V_2 ) ;
V_78:
F_50 ( V_2 -> V_33 , V_3 ) ;
V_72:
F_51 ( & V_65 ) ;
V_70:
return V_49 ;
}
static T_7 F_52 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
V_2 -> V_27 = F_11 ( V_2 -> V_13 ) ? - V_48 : 0 ;
F_28 ( V_2 -> V_33 , L_24 , V_2 -> V_27 ) ;
F_18 ( V_2 ) ;
F_17 ( V_2 ) ;
F_53 ( & V_2 -> V_52 ) ;
return V_85 ;
}
static int F_54 ( struct V_1 * V_2 )
{
T_2 V_18 ;
F_7 ( false ) ;
V_18 = V_23 | V_86 ;
F_14 ( V_18 , V_2 -> V_13 + V_25 ) ;
F_14 ( 0x0 , V_2 -> V_13 + V_25 ) ;
return 0 ;
}
static T_5 int F_55 ( struct V_1 * V_2 )
{
int V_49 ;
if ( V_2 -> V_5 != V_2 -> V_87 ) {
F_19 ( V_2 -> V_33 , L_25
L_26 ,
V_2 -> V_5 , V_2 -> V_87 ) ;
return - V_88 ;
}
if ( ! F_29 ( V_2 ) ) {
F_19 ( V_2 -> V_33 , L_27 ) ;
return - V_88 ;
}
if ( ! F_20 ( V_2 ) ) {
F_19 ( V_2 -> V_33 , L_28 ) ;
return - V_88 ;
}
F_7 ( false ) ;
V_49 = F_38 ( V_2 ) ;
if ( V_49 ) {
F_56 ( V_2 -> V_33 , L_29 ) ;
V_49 = F_36 ( V_2 ) ;
}
if ( V_49 ) {
F_19 ( V_2 -> V_33 , L_30 ) ;
return V_49 ;
}
F_1 ( V_2 ) ;
F_28 ( V_2 -> V_33 , L_31 ) ;
F_7 ( true ) ;
return 0 ;
}
static int F_57 ( struct V_89 * V_89 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_4 ( V_91 -> V_92 ,
struct V_1 , V_93 ) ;
unsigned int V_94 ;
int V_49 ;
V_49 = F_58 ( & V_2 -> V_8 ) ;
if ( V_49 )
return V_49 ;
V_91 -> V_92 = V_2 ;
F_59 ( & V_2 -> V_7 ) ;
if ( V_91 -> V_95 & V_96 )
V_2 -> V_5 = 0 ;
if ( V_2 -> V_4 )
return 0 ;
V_94 = F_39 ( V_2 -> V_87 , V_97 ) ;
V_49 = F_60 ( & V_2 -> V_3 , V_98 , V_94 ) ;
if ( V_49 ) {
F_19 ( V_2 -> V_33 , L_32 ) ;
F_61 ( & V_2 -> V_8 ) ;
F_62 ( & V_2 -> V_7 , F_3 ) ;
return V_49 ;
}
V_2 -> V_4 = true ;
return 0 ;
}
static int F_63 ( struct V_89 * V_89 , struct V_90 * V_91 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
F_61 ( & V_2 -> V_8 ) ;
F_62 ( & V_2 -> V_7 , F_3 ) ;
return 0 ;
}
static T_8 F_64 ( struct V_90 * V_91 , const char T_9 * V_43 ,
T_4 V_20 , T_10 * V_99 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
if ( V_2 -> V_5 >= V_2 -> V_87 )
return - V_100 ;
V_20 = F_33 ( T_4 , V_2 -> V_87 - V_2 -> V_5 , V_20 ) ;
if ( F_65 ( V_2 -> V_3 . V_50 + V_2 -> V_5 , V_43 , V_20 ) )
return - V_101 ;
V_2 -> V_5 += V_20 ;
return V_20 ;
}
static T_8 F_66 ( struct V_90 * V_91 , char T_9 * V_43 , T_4 V_20 ,
T_10 * V_99 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
return F_67 ( V_43 , V_20 , V_102 ,
V_2 -> V_3 . V_50 , V_2 -> V_5 ) ;
}
static T_10 F_68 ( struct V_90 * V_91 , T_10 V_103 , int V_104 )
{
struct V_1 * V_2 = V_91 -> V_92 ;
T_10 V_105 ;
if ( ( V_91 -> V_95 & V_106 ) != V_107 )
return - V_88 ;
return F_69 ( V_90 , V_103 , V_104 , V_2 -> V_87 ) ;
}
static T_8 F_70 ( struct V_108 * V_33 , struct V_109 * V_110 ,
char * V_43 )
{
struct V_1 * V_2 = F_71 ( V_33 ) ;
T_3 V_18 ;
V_18 = F_21 ( V_2 -> V_13 + V_111 ) ;
return snprintf ( V_43 , V_97 , L_33 , V_18 ) ;
}
static T_8 F_72 ( struct V_108 * V_33 , struct V_109 * V_110 ,
char * V_43 )
{
struct V_1 * V_2 = F_71 ( V_33 ) ;
return snprintf ( V_43 , V_97 , L_34 , F_20 ( V_2 ) ) ;
}
static T_8 F_73 ( struct V_108 * V_33 , struct V_109 * V_110 ,
char * V_43 )
{
struct V_1 * V_2 = F_71 ( V_33 ) ;
return snprintf ( V_43 , V_97 , L_34 , F_29 ( V_2 ) ) ;
}
static T_8 F_74 ( struct V_108 * V_33 , struct V_109 * V_110 ,
const char * V_43 , T_4 V_20 )
{
struct V_1 * V_2 = F_71 ( V_33 ) ;
unsigned long V_18 ;
int V_49 ;
V_49 = F_75 ( V_43 , 0 , & V_18 ) ;
if ( V_49 )
return V_49 ;
if ( V_18 ) {
V_49 = F_27 ( V_2 ) ;
if ( V_49 )
return V_49 ;
} else {
F_54 ( V_2 ) ;
F_22 ( V_2 ) ;
}
return V_20 ;
}
static T_8 F_76 ( struct V_108 * V_33 , struct V_109 * V_110 ,
char * V_43 )
{
struct V_1 * V_2 = F_71 ( V_33 ) ;
return snprintf ( V_43 , V_97 , L_34 , F_30 ( V_2 ) ) ;
}
static T_8 F_77 ( struct V_108 * V_33 , struct V_109 * V_110 ,
const char * V_43 , T_4 V_20 )
{
struct V_1 * V_2 = F_71 ( V_33 ) ;
unsigned long V_18 ;
int V_49 ;
V_49 = F_75 ( V_43 , 0 , & V_18 ) ;
if ( V_49 )
return V_49 ;
if ( F_58 ( & V_2 -> V_8 ) )
return - V_112 ;
V_49 = V_18 ? F_55 ( V_2 ) : F_54 ( V_2 ) ;
if ( V_49 )
goto V_113;
V_49 = V_20 ;
V_113:
F_61 ( & V_2 -> V_8 ) ;
return V_49 ;
}
static bool F_78 ( struct V_54 * V_55 , void * V_44 )
{
return V_55 -> V_114 == 0 && V_55 -> V_108 -> V_84 == 0 ;
}
static int F_79 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_80 ( V_116 ) ;
struct V_108 * V_117 = V_2 -> V_93 . V_117 ;
F_81 ( & V_117 -> V_118 , & V_119 ) ;
F_82 ( & V_2 -> V_93 ) ;
F_83 ( V_2 -> V_83 , V_2 ) ;
F_84 ( V_2 -> V_83 ) ;
F_22 ( V_2 ) ;
F_85 ( V_2 -> V_120 ) ;
F_85 ( V_2 -> V_13 ) ;
F_86 ( V_2 -> V_55 ) ;
F_62 ( & V_2 -> V_7 , F_3 ) ;
return 0 ;
}
static int F_87 ( struct V_115 * V_116 )
{
struct V_121 * V_122 = V_116 -> V_33 . V_122 ;
struct V_108 * V_117 ;
struct V_1 * V_2 ;
T_11 V_123 ;
T_2 V_124 ;
int V_49 ;
V_2 = F_88 ( sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 ) {
F_19 ( & V_116 -> V_33 , L_35 ) ;
V_49 = - V_69 ;
goto V_70;
}
V_2 -> V_93 . V_125 = V_126 ;
V_2 -> V_93 . V_127 = V_128 ;
V_2 -> V_93 . V_129 = & V_130 ;
F_89 ( & V_2 -> V_7 ) ;
F_90 ( V_116 , V_2 ) ;
V_2 -> V_33 = & V_116 -> V_33 ;
F_91 ( & V_2 -> V_8 ) ;
F_92 ( & V_2 -> V_52 ) ;
F_93 ( & V_2 -> V_3 ) ;
F_94 ( V_2 -> V_33 , V_2 ) ;
F_95 ( V_123 ) ;
F_96 ( V_131 , V_123 ) ;
F_96 ( V_132 , V_123 ) ;
F_96 ( V_133 , V_123 ) ;
V_2 -> V_55 = F_97 ( V_123 , F_78 , NULL ) ;
if ( ! V_2 -> V_55 ) {
F_19 ( & V_116 -> V_33 , L_36 ) ;
V_49 = - V_134 ;
goto V_135;
}
V_2 -> V_13 = F_98 ( V_122 , 0 ) ;
if ( ! V_2 -> V_13 ) {
F_19 ( & V_116 -> V_33 , L_37 ) ;
V_49 = - V_69 ;
goto V_136;
}
V_2 -> V_120 = F_99 ( F_100 () , 0x100000 ) ;
if ( ! V_2 -> V_120 ) {
F_19 ( & V_116 -> V_33 , L_38 ) ;
V_49 = - V_69 ;
goto V_137;
}
if ( ( F_10 ( V_2 -> V_120 + 0x114 ) & 0xE00 ) != 0xE00 ) {
F_19 ( & V_116 -> V_33 , L_39 ) ;
V_49 = - V_134 ;
goto V_138;
}
V_124 = F_21 ( V_2 -> V_13 + V_139 ) ;
if ( V_124 != 0x02 && V_124 != 0x03 ) {
F_19 ( & V_116 -> V_33 , L_40 ) ;
V_49 = - V_134 ;
goto V_138;
}
V_124 = F_10 ( V_2 -> V_13 + V_140 ) ;
V_2 -> V_87 = ( V_124 & ( 1 << 18 ) ) ? V_141 : V_142 ;
V_2 -> V_83 = F_101 ( V_122 , 0 ) ;
if ( V_2 -> V_83 == V_143 ) {
F_19 ( & V_116 -> V_33 , L_41 ) ;
V_49 = - V_134 ;
goto V_138;
}
V_49 = F_102 ( V_2 -> V_83 , F_52 , V_144 , V_128 , V_2 ) ;
if ( V_49 ) {
F_19 ( & V_116 -> V_33 , L_42 , V_2 -> V_83 ) ;
V_49 = - V_134 ;
goto V_145;
}
F_54 ( V_2 ) ;
V_49 = F_103 ( & V_2 -> V_93 ) ;
if ( V_49 ) {
F_19 ( & V_116 -> V_33 , L_43 ) ;
goto V_146;
}
V_117 = V_2 -> V_93 . V_117 ;
F_94 ( V_117 , V_2 ) ;
V_49 = F_104 ( & V_117 -> V_118 , & V_119 ) ;
if ( V_49 ) {
F_19 ( & V_116 -> V_33 , L_44 ) ;
goto V_147;
}
F_105 ( V_2 -> V_33 , L_45 ,
( V_124 & ( 1 << 17 ) ) ? L_46 : L_47 ,
( V_124 & ( 1 << 16 ) ) ? L_48 : L_49 ,
( V_124 & ( 1 << 18 ) ) ? L_50 : L_51 ) ;
return 0 ;
V_147:
F_82 ( & V_2 -> V_93 ) ;
V_146:
F_83 ( V_2 -> V_83 , V_2 ) ;
V_145:
F_84 ( V_2 -> V_83 ) ;
V_138:
F_85 ( V_2 -> V_120 ) ;
V_137:
F_85 ( V_2 -> V_13 ) ;
V_136:
F_86 ( V_2 -> V_55 ) ;
V_135:
F_62 ( & V_2 -> V_7 , F_3 ) ;
V_70:
return V_49 ;
}
static int T_12 F_106 ( void )
{
F_107 ( L_52 , & V_10 ) ;
return F_108 ( & V_148 ) ;
}
static void T_13 F_109 ( void )
{
F_110 ( & V_148 ) ;
F_111 ( V_10 ) ;
}
