static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_2 -> V_7 = F_2 ( V_3 << V_8 ) ;
if ( NULL == V_2 -> V_7 ) {
F_3 ( L_1 , V_3 ) ;
return - V_9 ;
}
F_3 ( L_2 ,
( unsigned long ) V_2 -> V_7 ,
V_3 << V_8 ) ;
memset ( V_2 -> V_7 , 0 , V_3 << V_8 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_10 = F_4 ( V_2 -> V_3 * sizeof( * V_2 -> V_10 ) ) ;
if ( NULL == V_2 -> V_10 )
goto V_11;
F_5 ( V_2 -> V_10 , V_2 -> V_3 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_3 ; V_6 ++ ) {
V_5 = F_6 ( V_2 -> V_7 + V_6 * V_12 ) ;
if ( NULL == V_5 )
goto V_13;
F_7 ( & V_2 -> V_10 [ V_6 ] , V_5 , V_12 , 0 ) ;
}
return 0 ;
V_13:
F_8 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
V_11:
F_8 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
return - V_9 ;
}
static int F_9 ( struct V_1 * V_2 )
{
V_2 -> V_14 = F_10 ( V_2 -> V_15 , V_2 -> V_10 ,
V_2 -> V_3 , V_16 ) ;
if ( 0 == V_2 -> V_14 ) {
F_11 ( L_3 , V_17 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 )
return 0 ;
F_13 ( V_2 -> V_15 , V_2 -> V_10 , V_2 -> V_14 , V_16 ) ;
V_2 -> V_14 = 0 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_10 ) ;
F_8 ( V_2 -> V_7 ) ;
V_2 -> V_18 = false ;
V_2 -> V_19 = 0 ;
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_16 ( V_21 , struct V_1 , V_21 ) ;
F_14 ( V_2 ) ;
F_17 ( & V_2 -> V_22 ) ;
F_18 ( V_2 ) ;
}
static void F_19 ( bool V_23 )
{
if ( V_23 )
F_20 ( V_24 , V_25 ) ;
else
F_20 ( V_24 , V_26 ) ;
}
static int F_21 ( void T_1 * V_27 )
{
return F_22 ( V_27 + V_28 ) ;
}
static int F_23 ( void T_1 * V_27 )
{
return F_22 ( V_27 + V_29 ) & V_30 ;
}
static int F_24 ( void T_1 * V_27 )
{
return F_22 ( V_27 + V_31 ) == 0 ;
}
static void F_25 ( void T_1 * V_27 , T_2 V_32 )
{
F_26 ( V_32 , V_27 + V_33 ) ;
}
static void F_27 ( void T_1 * V_27 , T_2 V_34 )
{
F_26 ( V_34 , V_27 + V_35 ) ;
}
static void F_28 ( struct V_1 * V_2 , bool V_36 )
{
T_2 V_32 ;
V_32 = ( V_36 ) ? ( V_37 | V_38 ) : V_37 ;
F_26 ( V_32 , V_2 -> V_27 + V_39 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_26 ( 0x0 , V_2 -> V_27 + V_39 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_2 V_40 , V_41 , V_42 , V_43 , V_44 , V_45 ;
if ( V_2 -> V_41 == 0 )
return;
V_40 = F_22 ( V_2 -> V_27 + V_39 ) ;
V_41 = F_22 ( V_2 -> V_27 + V_29 ) ;
V_42 = F_22 ( V_2 -> V_27 + V_28 ) ;
V_43 = F_22 ( V_2 -> V_27 + V_31 ) ;
V_44 = F_22 ( V_2 -> V_27 + V_35 ) ;
V_45 = F_22 ( V_2 -> V_27 + V_46 ) ;
F_31 ( V_2 -> V_15 , L_4 ) ;
F_31 ( V_2 -> V_15 , L_5 , V_40 ) ;
F_31 ( V_2 -> V_15 , L_6 , V_41 ) ;
F_31 ( V_2 -> V_15 , L_7 , V_42 ) ;
F_31 ( V_2 -> V_15 , L_8 , V_43 ) ;
F_31 ( V_2 -> V_15 , L_9 , V_44 ) ;
F_31 ( V_2 -> V_15 , L_10 , V_45 ) ;
}
static bool F_32 ( struct V_1 * V_2 )
{
T_3 V_32 ;
V_32 = F_33 ( V_2 -> V_27 + V_47 ) ;
if ( V_32 & V_48 )
return false ;
return V_32 == V_49 ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
T_3 V_32 ;
F_35 ( 0x0 , V_2 -> V_27 + V_51 ) ;
F_36 ( 500 ) ;
V_50 = V_52 ;
while ( F_37 ( V_52 , V_50 + V_53 ) ) {
V_32 = F_33 ( V_2 -> V_27 + V_47 ) ;
if ( ! ( V_32 & V_49 ) )
break;
F_38 ( 5000 , 10000 ) ;
}
V_32 = F_33 ( V_2 -> V_27 + V_47 ) ;
if ( V_32 & V_49 ) {
F_31 ( V_2 -> V_15 , L_11
L_12 , V_32 ) ;
}
if ( V_32 & V_48 ) {
F_31 ( V_2 -> V_15 , L_11
L_13 , V_32 ) ;
}
}
static int F_39 ( struct V_1 * V_2 )
{
unsigned long V_50 = V_52 ;
if ( F_32 ( V_2 ) ) {
F_40 ( V_2 -> V_15 , L_14 ) ;
return 0 ;
}
F_35 ( V_54 , V_2 -> V_27 + V_51 ) ;
while ( F_37 ( V_52 , V_50 + V_53 ) ) {
if ( F_32 ( V_2 ) )
return 0 ;
F_38 ( 5000 , 10000 ) ;
}
return F_32 ( V_2 ) ? 0 : - V_55 ;
}
static bool F_41 ( struct V_1 * V_2 )
{
T_3 V_32 ;
V_32 = F_33 ( V_2 -> V_27 + V_51 ) ;
if ( V_32 & V_54 )
return true ;
return false ;
}
static bool F_42 ( struct V_1 * V_2 )
{
if ( ! F_32 ( V_2 ) )
return false ;
return F_22 ( V_2 -> V_27 + V_29 ) & ( 1 << 18 ) ;
}
static int F_43 ( struct V_1 * V_2 , void * V_56 , T_4 V_34 )
{
T_2 * V_57 = V_56 ;
int V_42 = F_21 ( V_2 -> V_27 ) ;
int V_6 , V_58 ;
unsigned long V_59 ;
F_44 ( V_34 % 4 != 0 ) ;
while ( V_34 > 0 ) {
V_58 = F_45 ( T_4 , V_34 , V_42 ) ;
V_59 = V_52 + V_53 / 4 ;
for ( V_6 = 0 ; V_6 < V_58 / 4 ; V_6 ++ )
F_25 ( V_2 -> V_27 , V_57 [ V_6 ] ) ;
V_34 -= V_58 ;
V_57 += V_58 / 4 ;
while ( true ) {
if ( F_24 ( V_2 -> V_27 ) ) {
break;
} else {
F_40 ( V_2 -> V_15 , L_15 ) ;
F_46 () ;
}
if ( F_23 ( V_2 -> V_27 ) ) {
F_31 ( V_2 -> V_15 , L_16 ) ;
return - V_60 ;
}
if ( F_47 ( V_52 , V_59 ) ) {
F_31 ( V_2 -> V_15 , L_17 ) ;
return - V_55 ;
}
F_38 ( 5000 , 10000 ) ;
}
}
return 0 ;
}
static T_5 int F_48 ( struct V_1 * V_2 )
{
int V_61 ;
F_29 ( V_2 ) ;
F_27 ( V_2 -> V_27 , V_2 -> V_19 ) ;
F_40 ( V_2 -> V_15 , L_18 , V_2 -> V_19 ) ;
F_28 ( V_2 , false ) ;
F_40 ( V_2 -> V_15 , L_19 ) ;
V_61 = F_43 ( V_2 , V_2 -> V_7 , V_2 -> V_19 ) ;
if ( V_61 )
goto V_62;
V_61 = F_49 ( & V_2 -> V_63 , 2 * V_53 ) ;
if ( ! V_61 ) {
F_31 ( V_2 -> V_15 , L_20 ) ;
V_61 = - V_55 ;
goto V_62;
}
V_61 = V_2 -> V_41 ;
V_62:
F_29 ( V_2 ) ;
return V_61 ;
}
static T_5 int F_50 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_66 * V_67 ;
T_4 V_68 , V_58 , V_69 = 0 ;
struct V_70 V_71 ;
struct V_72 * V_73 ;
struct V_74 V_75 ;
T_6 V_76 ;
int V_61 , V_6 ;
F_29 ( V_2 ) ;
V_68 = F_51 ( V_2 -> V_19 , V_77 ) ;
V_61 = F_52 ( & V_75 , V_68 , V_78 ) ;
if ( V_61 ) {
F_31 ( V_2 -> V_15 , L_21 ) ;
V_61 = - V_9 ;
goto V_79;
}
V_69 = V_2 -> V_19 ;
F_53 (table.sgl, sg, num_pages, i) {
V_58 = F_45 ( T_4 , V_69 , V_77 ) ;
F_54 ( V_73 ) = V_80 ;
F_55 ( V_73 ) = V_58 ;
V_69 -= V_58 ;
}
V_61 = F_9 ( V_2 ) ;
if ( V_61 ) {
F_31 ( V_2 -> V_15 , L_22 ) ;
goto V_81;
}
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_82 = V_83 ;
V_71 . V_84 = V_85 ;
V_71 . V_86 = F_21 ( V_2 -> V_27 ) / 2 / 4 ;
V_61 = F_56 ( V_65 , & V_71 ) ;
if ( V_61 ) {
F_31 ( V_2 -> V_15 , L_23 ) ;
goto V_87;
}
V_61 = F_57 ( V_65 , 1 ) ;
if ( V_61 ) {
F_31 ( V_2 -> V_15 , L_24 ) ;
goto V_87;
}
V_67 = F_58 ( V_65 , V_75 . V_88 , V_68 ,
V_2 -> V_10 , V_2 -> V_14 , 0 ) ;
if ( ! V_67 ) {
F_31 ( V_2 -> V_15 , L_25 ) ;
V_61 = - V_9 ;
goto V_87;
}
V_76 = V_67 -> V_89 ( V_67 ) ;
if ( F_59 ( V_76 ) ) {
F_31 ( V_2 -> V_15 , L_26 ) ;
V_61 = - V_9 ;
goto V_87;
}
F_60 ( V_65 ) ;
F_27 ( V_2 -> V_27 , V_2 -> V_19 ) ;
F_40 ( V_2 -> V_15 , L_18 , V_2 -> V_19 ) ;
F_28 ( V_2 , true ) ;
F_40 ( V_2 -> V_15 , L_19 ) ;
V_61 = F_49 ( & V_2 -> V_63 , 2 * V_53 ) ;
if ( ! V_61 ) {
F_31 ( V_2 -> V_15 , L_20 ) ;
V_61 = - V_55 ;
goto V_62;
}
V_61 = V_2 -> V_41 ;
V_62:
F_29 ( V_2 ) ;
V_87:
F_12 ( V_2 ) ;
V_81:
F_61 ( & V_75 ) ;
V_79:
return V_61 ;
}
static T_7 F_62 ( int V_90 , void * V_91 )
{
struct V_1 * V_2 = V_91 ;
V_2 -> V_41 = F_23 ( V_2 -> V_27 ) ? - V_60 : 0 ;
F_40 ( V_2 -> V_15 , L_27 , V_2 -> V_41 ) ;
F_30 ( V_2 ) ;
F_29 ( V_2 ) ;
F_63 ( & V_2 -> V_63 ) ;
return V_92 ;
}
static int F_64 ( struct V_1 * V_2 )
{
T_2 V_32 ;
F_19 ( false ) ;
V_32 = V_37 | V_93 ;
F_26 ( V_32 , V_2 -> V_27 + V_39 ) ;
F_26 ( 0x0 , V_2 -> V_27 + V_39 ) ;
return 0 ;
}
static T_5 int F_65 ( struct V_1 * V_2 )
{
int V_61 ;
if ( V_2 -> V_19 != V_2 -> V_94 ) {
F_31 ( V_2 -> V_15 , L_28
L_29 ,
V_2 -> V_19 , V_2 -> V_94 ) ;
return - V_95 ;
}
if ( ! F_41 ( V_2 ) ) {
F_31 ( V_2 -> V_15 , L_30 ) ;
return - V_95 ;
}
if ( ! F_32 ( V_2 ) ) {
F_31 ( V_2 -> V_15 , L_31 ) ;
return - V_95 ;
}
F_19 ( false ) ;
V_61 = F_50 ( V_2 ) ;
if ( V_61 ) {
F_66 ( V_2 -> V_15 , L_32 ) ;
V_61 = F_48 ( V_2 ) ;
}
if ( V_61 ) {
F_31 ( V_2 -> V_15 , L_33 ) ;
return V_61 ;
}
F_14 ( V_2 ) ;
F_40 ( V_2 -> V_15 , L_34 ) ;
F_19 ( true ) ;
return 0 ;
}
static int F_67 ( struct V_96 * V_96 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_16 ( V_98 -> V_99 ,
struct V_1 , V_100 ) ;
unsigned int V_3 ;
int V_61 ;
V_61 = F_68 ( & V_2 -> V_22 ) ;
if ( V_61 )
return V_61 ;
V_98 -> V_99 = V_2 ;
F_69 ( & V_2 -> V_21 ) ;
if ( V_98 -> V_101 & V_102 )
V_2 -> V_19 = 0 ;
if ( V_2 -> V_18 )
return 0 ;
V_3 = F_51 ( V_2 -> V_94 , V_12 ) ;
V_61 = F_1 ( V_2 , V_3 ) ;
if ( V_61 ) {
F_31 ( V_2 -> V_15 , L_35 ) ;
F_70 ( & V_2 -> V_22 ) ;
F_71 ( & V_2 -> V_21 , F_15 ) ;
return V_61 ;
}
V_2 -> V_18 = true ;
return 0 ;
}
static int F_72 ( struct V_96 * V_96 , struct V_97 * V_98 )
{
struct V_1 * V_2 = V_98 -> V_99 ;
F_70 ( & V_2 -> V_22 ) ;
F_71 ( & V_2 -> V_21 , F_15 ) ;
return 0 ;
}
static T_8 F_73 ( struct V_97 * V_98 , const char T_9 * V_56 ,
T_4 V_34 , T_10 * V_103 )
{
struct V_1 * V_2 = V_98 -> V_99 ;
if ( V_2 -> V_19 >= V_2 -> V_94 )
return - V_104 ;
V_34 = F_45 ( T_4 , V_2 -> V_94 - V_2 -> V_19 , V_34 ) ;
if ( F_74 ( V_2 -> V_7 + V_2 -> V_19 , V_56 , V_34 ) )
return - V_105 ;
V_2 -> V_19 += V_34 ;
return V_34 ;
}
static T_8 F_75 ( struct V_97 * V_98 , char T_9 * V_56 , T_4 V_34 ,
T_10 * V_103 )
{
struct V_1 * V_2 = V_98 -> V_99 ;
return F_76 ( V_56 , V_34 , V_103 ,
V_2 -> V_7 , V_2 -> V_19 ) ;
}
static T_10 F_77 ( struct V_97 * V_98 , T_10 V_106 , int V_107 )
{
struct V_1 * V_2 = V_98 -> V_99 ;
if ( ( V_98 -> V_101 & V_108 ) != V_109 )
return - V_95 ;
return F_78 ( V_98 , V_106 , V_107 , V_2 -> V_94 ) ;
}
static T_8 F_79 ( struct V_110 * V_15 , struct V_111 * V_112 ,
char * V_56 )
{
struct V_1 * V_2 = F_80 ( V_15 ) ;
T_3 V_32 ;
V_32 = F_33 ( V_2 -> V_27 + V_113 ) ;
return snprintf ( V_56 , V_12 , L_36 , V_32 ) ;
}
static T_8 F_81 ( struct V_110 * V_15 , struct V_111 * V_112 ,
char * V_56 )
{
struct V_1 * V_2 = F_80 ( V_15 ) ;
return snprintf ( V_56 , V_12 , L_37 , F_32 ( V_2 ) ) ;
}
static T_8 F_82 ( struct V_110 * V_15 , struct V_111 * V_112 ,
char * V_56 )
{
struct V_1 * V_2 = F_80 ( V_15 ) ;
return snprintf ( V_56 , V_12 , L_37 , F_41 ( V_2 ) ) ;
}
static T_8 F_83 ( struct V_110 * V_15 , struct V_111 * V_112 ,
const char * V_56 , T_4 V_34 )
{
struct V_1 * V_2 = F_80 ( V_15 ) ;
unsigned long V_32 ;
int V_61 ;
V_61 = F_84 ( V_56 , 0 , & V_32 ) ;
if ( V_61 )
return V_61 ;
if ( V_32 ) {
V_61 = F_39 ( V_2 ) ;
if ( V_61 )
return V_61 ;
} else {
F_64 ( V_2 ) ;
F_34 ( V_2 ) ;
}
return V_34 ;
}
static T_8 F_85 ( struct V_110 * V_15 , struct V_111 * V_112 ,
char * V_56 )
{
struct V_1 * V_2 = F_80 ( V_15 ) ;
return snprintf ( V_56 , V_12 , L_37 , F_42 ( V_2 ) ) ;
}
static T_8 F_86 ( struct V_110 * V_15 , struct V_111 * V_112 ,
const char * V_56 , T_4 V_34 )
{
struct V_1 * V_2 = F_80 ( V_15 ) ;
unsigned long V_32 ;
int V_61 ;
V_61 = F_84 ( V_56 , 0 , & V_32 ) ;
if ( V_61 )
return V_61 ;
if ( F_68 ( & V_2 -> V_22 ) )
return - V_114 ;
V_61 = V_32 ? F_65 ( V_2 ) : F_64 ( V_2 ) ;
if ( V_61 )
goto V_115;
V_61 = V_34 ;
V_115:
F_70 ( & V_2 -> V_22 ) ;
return V_61 ;
}
static bool F_87 ( struct V_64 * V_65 , void * V_57 )
{
return V_65 -> V_116 == 0 && V_65 -> V_110 -> V_91 == 0 ;
}
static int F_88 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_89 ( V_118 ) ;
struct V_110 * V_119 = V_2 -> V_100 . V_119 ;
F_90 ( & V_119 -> V_120 , & V_121 ) ;
F_91 ( & V_2 -> V_100 ) ;
F_92 ( V_2 -> V_90 , V_2 ) ;
F_93 ( V_2 -> V_90 ) ;
F_34 ( V_2 ) ;
F_94 ( V_2 -> V_122 ) ;
F_94 ( V_2 -> V_27 ) ;
F_95 ( V_2 -> V_65 ) ;
F_71 ( & V_2 -> V_21 , F_15 ) ;
return 0 ;
}
static int F_96 ( struct V_117 * V_118 )
{
struct V_123 * V_124 = V_118 -> V_15 . V_124 ;
struct V_110 * V_119 ;
struct V_1 * V_2 ;
T_11 V_125 ;
T_2 V_126 ;
int V_61 ;
V_2 = F_97 ( sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 ) {
F_31 ( & V_118 -> V_15 , L_38 ) ;
V_61 = - V_9 ;
goto V_79;
}
V_2 -> V_100 . V_127 = V_128 ;
V_2 -> V_100 . V_129 = V_130 ;
V_2 -> V_100 . V_131 = & V_132 ;
F_98 ( & V_2 -> V_21 ) ;
F_99 ( V_118 , V_2 ) ;
V_2 -> V_15 = & V_118 -> V_15 ;
F_100 ( & V_2 -> V_22 ) ;
F_101 ( & V_2 -> V_63 ) ;
F_102 ( V_2 -> V_15 , V_2 ) ;
F_103 ( V_125 ) ;
F_104 ( V_133 , V_125 ) ;
F_104 ( V_134 , V_125 ) ;
F_104 ( V_135 , V_125 ) ;
V_2 -> V_65 = F_105 ( V_125 , F_87 , NULL ) ;
if ( ! V_2 -> V_65 ) {
F_31 ( & V_118 -> V_15 , L_39 ) ;
V_61 = - V_136 ;
goto V_137;
}
V_2 -> V_27 = F_106 ( V_124 , 0 ) ;
if ( ! V_2 -> V_27 ) {
F_31 ( & V_118 -> V_15 , L_40 ) ;
V_61 = - V_9 ;
goto V_138;
}
V_2 -> V_122 = F_107 ( F_108 () , 0x100000 ) ;
if ( ! V_2 -> V_122 ) {
F_31 ( & V_118 -> V_15 , L_41 ) ;
V_61 = - V_9 ;
goto V_139;
}
if ( ( F_22 ( V_2 -> V_122 + 0x114 ) & 0xE00 ) != 0xE00 ) {
F_31 ( & V_118 -> V_15 , L_42 ) ;
V_61 = - V_136 ;
goto V_140;
}
V_126 = F_33 ( V_2 -> V_27 + V_141 ) ;
if ( V_126 != 0x02 && V_126 != 0x03 ) {
F_31 ( & V_118 -> V_15 , L_43 ) ;
V_61 = - V_136 ;
goto V_140;
}
V_126 = F_22 ( V_2 -> V_27 + V_142 ) ;
V_2 -> V_94 = ( V_126 & ( 1 << 18 ) ) ? V_143 : V_144 ;
V_2 -> V_90 = F_109 ( V_124 , 0 ) ;
if ( V_2 -> V_90 == V_145 ) {
F_31 ( & V_118 -> V_15 , L_44 ) ;
V_61 = - V_136 ;
goto V_140;
}
V_61 = F_110 ( V_2 -> V_90 , F_62 , V_146 , V_130 , V_2 ) ;
if ( V_61 ) {
F_31 ( & V_118 -> V_15 , L_45 , V_2 -> V_90 ) ;
V_61 = - V_136 ;
goto V_147;
}
F_64 ( V_2 ) ;
V_61 = F_111 ( & V_2 -> V_100 ) ;
if ( V_61 ) {
F_31 ( & V_118 -> V_15 , L_46 ) ;
goto V_148;
}
V_119 = V_2 -> V_100 . V_119 ;
F_102 ( V_119 , V_2 ) ;
V_61 = F_112 ( & V_119 -> V_120 , & V_121 ) ;
if ( V_61 ) {
F_31 ( & V_118 -> V_15 , L_47 ) ;
goto V_149;
}
F_113 ( V_2 -> V_15 , L_48 ,
( V_126 & ( 1 << 17 ) ) ? L_49 : L_50 ,
( V_126 & ( 1 << 16 ) ) ? L_51 : L_52 ,
( V_126 & ( 1 << 18 ) ) ? L_53 : L_54 ) ;
return 0 ;
V_149:
F_91 ( & V_2 -> V_100 ) ;
V_148:
F_92 ( V_2 -> V_90 , V_2 ) ;
V_147:
F_93 ( V_2 -> V_90 ) ;
V_140:
F_94 ( V_2 -> V_122 ) ;
V_139:
F_94 ( V_2 -> V_27 ) ;
V_138:
F_95 ( V_2 -> V_65 ) ;
V_137:
F_71 ( & V_2 -> V_21 , F_15 ) ;
V_79:
return V_61 ;
}
static int T_12 F_114 ( void )
{
F_115 ( L_55 , & V_24 ) ;
return F_116 ( & V_150 ) ;
}
static void T_13 F_117 ( void )
{
F_118 ( & V_150 ) ;
F_119 ( V_24 ) ;
}
