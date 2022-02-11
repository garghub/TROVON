static int T_1 F_1 ( char * V_1 )
{
unsigned long V_2 ;
if ( ! F_2 ( V_1 , 0 , & V_2 ) )
V_3 = V_2 ? 1 : 0 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
unsigned long V_4 ;
if ( ! F_2 ( V_1 , 0 , & V_4 ) )
V_5 = V_4 ? 1 : 0 ;
return 1 ;
}
static int F_4 ( void )
{
return ( V_6 || F_5 ( & V_7 ) ) ;
}
static int F_6 ( void )
{
return ( V_6 || F_7 () || F_8 () ) ;
}
static int F_9 ( T_2 V_8 )
{
if ( V_8 == V_9 ) {
F_10 () ;
F_11 () ;
F_12 () ;
F_13 () ;
}
return 0 ;
}
static int F_14 ( T_2 V_8 )
{
if ( V_8 == V_9 ) {
F_15 () ;
F_16 ( V_10 , NULL ) ;
}
return 0 ;
}
static void F_17 ( void )
{
struct V_11 * V_11 = (struct V_11 * ) V_12 -> V_13 ;
struct V_14 * V_15 ;
V_15 = F_18 ( sizeof( struct V_14 ) , V_16 ) ;
if ( ! V_15 )
F_19 ( L_1 ) ;
V_15 -> V_17 = V_15 -> V_18 = V_19 ;
V_11 -> V_20 = V_15 ;
}
static inline T_2 F_20 ( const struct V_11 * V_11 )
{
const struct V_14 * V_15 ;
V_15 = V_11 -> V_20 ;
return V_15 -> V_18 ;
}
static inline T_2 F_21 ( const struct V_21 * V_22 )
{
T_2 V_18 ;
F_22 () ;
V_18 = F_20 ( F_23 ( V_22 ) ) ;
F_24 () ;
return V_18 ;
}
static int F_25 ( struct V_23 * V_23 )
{
struct V_24 * V_25 ;
T_2 V_18 = F_26 () ;
V_25 = F_27 ( V_26 , V_27 ) ;
if ( ! V_25 )
return - V_28 ;
F_28 ( & V_25 -> V_29 ) ;
F_29 ( & V_25 -> V_30 ) ;
V_25 -> V_23 = V_23 ;
V_25 -> V_18 = V_31 ;
V_25 -> V_32 = V_33 ;
V_25 -> F_21 = V_18 ;
V_25 -> V_34 = V_35 ;
V_23 -> V_36 = V_25 ;
return 0 ;
}
static int F_30 ( struct V_23 * V_23 ,
struct V_37 * V_38 ,
bool V_39 )
{
struct V_24 * V_25 = V_23 -> V_36 ;
F_31 ( V_39 ) ;
if ( V_40 && V_25 -> V_34 != V_41 ) {
if ( ! V_39 )
return - V_42 ;
F_32 ( V_23 , V_38 ) ;
}
return 0 ;
}
static struct V_24 * F_33 ( struct V_23 * V_23 )
{
return V_23 -> V_36 ;
}
static struct V_24 * F_34 ( struct V_23 * V_23 , bool V_43 )
{
int error ;
error = F_30 ( V_23 , NULL , ! V_43 ) ;
if ( error )
return F_35 ( error ) ;
return V_23 -> V_36 ;
}
static struct V_24 * F_36 ( struct V_23 * V_23 )
{
F_30 ( V_23 , NULL , true ) ;
return V_23 -> V_36 ;
}
static struct V_24 * F_37 ( struct V_37 * V_37 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
return V_23 -> V_36 ;
}
static struct V_24 * F_39 ( struct V_37 * V_37 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
F_30 ( V_23 , V_37 , true ) ;
return V_23 -> V_36 ;
}
static void F_40 ( struct V_44 * V_45 )
{
struct V_24 * V_25 ;
V_25 = F_41 ( V_45 , struct V_24 , V_43 ) ;
F_42 ( V_26 , V_25 ) ;
}
static void F_43 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_36 ;
struct V_46 * V_47 = V_23 -> V_48 -> V_49 ;
if ( ! F_44 ( & V_25 -> V_30 ) ) {
F_45 ( & V_47 -> V_50 ) ;
F_46 ( & V_25 -> V_30 ) ;
F_47 ( & V_47 -> V_50 ) ;
}
F_48 ( & V_25 -> V_43 , F_40 ) ;
}
static int F_49 ( struct V_51 * V_51 )
{
struct V_52 * V_53 ;
T_2 V_18 = F_26 () ;
V_53 = F_27 ( V_54 , V_16 ) ;
if ( ! V_53 )
return - V_28 ;
V_53 -> V_18 = V_18 ;
V_53 -> V_55 = V_18 ;
V_51 -> V_56 = V_53 ;
return 0 ;
}
static void F_50 ( struct V_51 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_56 ;
V_51 -> V_56 = NULL ;
F_42 ( V_54 , V_53 ) ;
}
static int F_51 ( struct V_57 * V_58 )
{
struct V_46 * V_47 ;
V_47 = F_18 ( sizeof( struct V_46 ) , V_16 ) ;
if ( ! V_47 )
return - V_28 ;
F_52 ( & V_47 -> V_29 ) ;
F_29 ( & V_47 -> V_59 ) ;
F_28 ( & V_47 -> V_50 ) ;
V_47 -> V_58 = V_58 ;
V_47 -> V_18 = V_31 ;
V_47 -> V_60 = V_61 ;
V_47 -> V_62 = V_31 ;
V_58 -> V_49 = V_47 ;
return 0 ;
}
static void F_53 ( struct V_57 * V_58 )
{
struct V_46 * V_47 = V_58 -> V_49 ;
V_58 -> V_49 = NULL ;
F_54 ( V_47 ) ;
}
static inline int F_55 ( struct V_23 * V_23 )
{
return F_32 ( V_23 , NULL ) ;
}
static int F_56 ( T_2 V_18 ,
struct V_46 * V_47 ,
const struct V_11 * V_11 )
{
const struct V_14 * V_15 = V_11 -> V_20 ;
int V_63 ;
V_63 = F_57 ( V_15 -> V_18 , V_47 -> V_18 , V_64 ,
V_65 , NULL ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_15 -> V_18 , V_18 , V_64 ,
V_66 , NULL ) ;
return V_63 ;
}
static int F_58 ( T_2 V_18 ,
struct V_46 * V_47 ,
const struct V_11 * V_11 )
{
const struct V_14 * V_15 = V_11 -> V_20 ;
int V_63 ;
V_63 = F_57 ( V_15 -> V_18 , V_47 -> V_18 , V_64 ,
V_65 , NULL ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_18 , V_47 -> V_18 , V_64 ,
V_67 , NULL ) ;
return V_63 ;
}
static int F_59 ( struct V_57 * V_58 )
{
struct V_46 * V_47 = V_58 -> V_49 ;
return V_47 -> V_68 == V_69 ||
V_47 -> V_68 == V_70 ||
V_47 -> V_68 == V_71 ||
V_47 -> V_68 == V_72 ||
! strcmp ( V_58 -> V_73 -> V_74 , L_2 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_3 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_4 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_5 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_6 ) ||
( V_75 &&
( ! strcmp ( V_58 -> V_73 -> V_74 , L_7 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_8 ) ) ) ;
}
static int F_60 ( struct V_57 * V_58 )
{
struct V_46 * V_47 = V_58 -> V_49 ;
struct V_37 * V_76 = V_58 -> V_77 ;
struct V_23 * V_78 = F_38 ( V_76 ) ;
int V_63 = 0 ;
if ( V_47 -> V_68 == V_69 ) {
if ( ! ( V_78 -> V_79 & V_80 ) ) {
F_61 ( V_81 L_9
L_10 , V_58 -> V_82 , V_58 -> V_73 -> V_74 ) ;
V_63 = - V_83 ;
goto V_84;
}
V_63 = F_62 ( V_76 , V_78 , V_85 , NULL , 0 ) ;
if ( V_63 < 0 && V_63 != - V_86 ) {
if ( V_63 == - V_83 )
F_61 ( V_81 L_11
L_12 ,
V_58 -> V_82 , V_58 -> V_73 -> V_74 ) ;
else
F_61 ( V_81 L_11
L_13 , V_58 -> V_82 ,
V_58 -> V_73 -> V_74 , - V_63 ) ;
goto V_84;
}
}
V_47 -> V_87 |= V_88 ;
if ( F_59 ( V_58 ) )
V_47 -> V_87 |= V_89 ;
else
V_47 -> V_87 &= ~ V_89 ;
V_63 = F_32 ( V_78 , V_76 ) ;
F_45 ( & V_47 -> V_50 ) ;
V_90:
if ( ! F_63 ( & V_47 -> V_59 ) ) {
struct V_24 * V_25 =
F_64 ( V_47 -> V_59 . V_91 ,
struct V_24 , V_30 ) ;
struct V_23 * V_23 = V_25 -> V_23 ;
F_46 ( & V_25 -> V_30 ) ;
F_47 ( & V_47 -> V_50 ) ;
V_23 = F_65 ( V_23 ) ;
if ( V_23 ) {
if ( ! F_66 ( V_23 ) )
F_55 ( V_23 ) ;
F_67 ( V_23 ) ;
}
F_45 ( & V_47 -> V_50 ) ;
goto V_90;
}
F_47 ( & V_47 -> V_50 ) ;
V_84:
return V_63 ;
}
static int F_68 ( const struct V_57 * V_58 ,
struct V_92 * V_93 )
{
int V_63 = 0 , V_94 ;
struct V_46 * V_47 = V_58 -> V_49 ;
char * V_95 = NULL ;
T_2 V_96 ;
char V_97 ;
F_69 ( V_93 ) ;
if ( ! ( V_47 -> V_87 & V_88 ) )
return - V_98 ;
if ( ! V_40 )
return - V_98 ;
F_70 ( V_99 >= ( 1 << V_100 ) ) ;
V_97 = V_47 -> V_87 & V_99 ;
for ( V_94 = 0 ; V_94 < V_100 ; V_94 ++ ) {
if ( V_97 & 0x01 )
V_93 -> V_101 ++ ;
V_97 >>= 1 ;
}
if ( V_47 -> V_87 & V_89 )
V_93 -> V_101 ++ ;
V_93 -> V_102 = F_71 ( V_93 -> V_101 , sizeof( char * ) , V_103 ) ;
if ( ! V_93 -> V_102 ) {
V_63 = - V_28 ;
goto V_104;
}
V_93 -> V_105 = F_71 ( V_93 -> V_101 , sizeof( int ) , V_103 ) ;
if ( ! V_93 -> V_105 ) {
V_63 = - V_28 ;
goto V_104;
}
V_94 = 0 ;
if ( V_47 -> V_87 & V_106 ) {
V_63 = F_72 ( V_47 -> V_18 , & V_95 , & V_96 ) ;
if ( V_63 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_106 ;
}
if ( V_47 -> V_87 & V_107 ) {
V_63 = F_72 ( V_47 -> V_62 , & V_95 , & V_96 ) ;
if ( V_63 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_107 ;
}
if ( V_47 -> V_87 & V_108 ) {
V_63 = F_72 ( V_47 -> V_60 , & V_95 , & V_96 ) ;
if ( V_63 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_108 ;
}
if ( V_47 -> V_87 & V_109 ) {
struct V_37 * V_76 = V_47 -> V_58 -> V_77 ;
struct V_24 * V_25 = F_39 ( V_76 ) ;
V_63 = F_72 ( V_25 -> V_18 , & V_95 , & V_96 ) ;
if ( V_63 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_109 ;
}
if ( V_47 -> V_87 & V_89 ) {
V_93 -> V_102 [ V_94 ] = NULL ;
V_93 -> V_105 [ V_94 ++ ] = V_89 ;
}
F_73 ( V_94 != V_93 -> V_101 ) ;
return 0 ;
V_104:
F_74 ( V_93 ) ;
return V_63 ;
}
static int F_75 ( struct V_46 * V_47 , char V_110 ,
T_2 V_111 , T_2 V_112 )
{
char V_113 = V_47 -> V_87 & V_99 ;
if ( V_47 -> V_87 & V_88 )
if ( ! ( V_47 -> V_87 & V_110 ) ||
( V_111 != V_112 ) )
return 1 ;
if ( ! ( V_47 -> V_87 & V_88 ) )
if ( V_113 & V_110 )
return 1 ;
return 0 ;
}
static int F_76 ( struct V_57 * V_58 ,
struct V_92 * V_93 ,
unsigned long V_114 ,
unsigned long * V_115 )
{
const struct V_11 * V_11 = F_77 () ;
int V_63 = 0 , V_94 ;
struct V_46 * V_47 = V_58 -> V_49 ;
const char * V_74 = V_58 -> V_73 -> V_74 ;
struct V_37 * V_76 = V_47 -> V_58 -> V_77 ;
struct V_24 * V_116 ;
T_2 V_117 = 0 , V_118 = 0 , V_119 = 0 ;
T_2 V_120 = 0 ;
char * * V_121 = V_93 -> V_102 ;
int * V_87 = V_93 -> V_105 ;
int V_122 = V_93 -> V_101 ;
F_78 ( & V_47 -> V_29 ) ;
if ( ! V_40 ) {
if ( ! V_122 ) {
goto V_84;
}
V_63 = - V_98 ;
F_61 ( V_81 L_14
L_15 ) ;
goto V_84;
}
if ( V_114 && ! V_115 ) {
V_63 = - V_98 ;
goto V_84;
}
if ( ( V_47 -> V_87 & V_88 ) && ( V_58 -> V_73 -> V_123 & V_124 )
&& ( V_122 == 0 ) )
goto V_84;
V_116 = F_37 ( V_76 ) ;
for ( V_94 = 0 ; V_94 < V_122 ; V_94 ++ ) {
T_2 V_18 ;
if ( V_87 [ V_94 ] == V_89 )
continue;
V_63 = F_79 ( V_121 [ V_94 ] , & V_18 , V_16 ) ;
if ( V_63 ) {
F_61 ( V_81 L_16
L_17 ,
V_121 [ V_94 ] , V_58 -> V_82 , V_74 , V_63 ) ;
goto V_84;
}
switch ( V_87 [ V_94 ] ) {
case V_106 :
V_117 = V_18 ;
if ( F_75 ( V_47 , V_106 , V_47 -> V_18 ,
V_117 ) )
goto V_125;
V_47 -> V_87 |= V_106 ;
break;
case V_107 :
V_118 = V_18 ;
if ( F_75 ( V_47 , V_107 , V_47 -> V_62 ,
V_118 ) )
goto V_125;
V_47 -> V_87 |= V_107 ;
break;
case V_109 :
V_119 = V_18 ;
if ( F_75 ( V_47 , V_109 , V_116 -> V_18 ,
V_119 ) )
goto V_125;
V_47 -> V_87 |= V_109 ;
break;
case V_108 :
V_120 = V_18 ;
if ( F_75 ( V_47 , V_108 , V_47 -> V_60 ,
V_120 ) )
goto V_125;
V_47 -> V_87 |= V_108 ;
break;
default:
V_63 = - V_98 ;
goto V_84;
}
}
if ( V_47 -> V_87 & V_88 ) {
if ( ( V_47 -> V_87 & V_99 ) && ! V_122 )
goto V_125;
V_63 = 0 ;
goto V_84;
}
if ( strcmp ( V_58 -> V_73 -> V_74 , L_18 ) == 0 )
V_47 -> V_87 |= V_126 | V_127 ;
if ( ! strcmp ( V_58 -> V_73 -> V_74 , L_4 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_5 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_2 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_3 ) )
V_47 -> V_87 |= V_127 ;
if ( ! V_47 -> V_68 ) {
V_63 = F_80 ( V_58 ) ;
if ( V_63 ) {
F_61 ( V_81
L_19 ,
V_128 , V_58 -> V_73 -> V_74 , V_63 ) ;
goto V_84;
}
}
if ( V_58 -> V_129 != & V_130 &&
strcmp ( V_58 -> V_73 -> V_74 , L_20 ) &&
strcmp ( V_58 -> V_73 -> V_74 , L_21 ) &&
strcmp ( V_58 -> V_73 -> V_74 , L_22 ) ) {
if ( V_118 || V_117 || V_119 ||
V_120 ) {
V_63 = - V_131 ;
goto V_84;
}
if ( V_47 -> V_68 == V_69 ) {
V_47 -> V_68 = V_132 ;
V_63 = F_81 ( F_26 () , F_26 () ,
V_33 , NULL ,
& V_47 -> V_62 ) ;
if ( V_63 )
goto V_84;
}
goto V_133;
}
if ( V_117 ) {
V_63 = F_56 ( V_117 , V_47 , V_11 ) ;
if ( V_63 )
goto V_84;
V_47 -> V_18 = V_117 ;
}
if ( V_114 & V_134 && ! V_118 ) {
V_47 -> V_68 = V_72 ;
* V_115 |= V_134 ;
}
if ( V_118 ) {
if ( ! V_117 ) {
V_63 = F_56 ( V_118 , V_47 ,
V_11 ) ;
if ( V_63 )
goto V_84;
V_47 -> V_18 = V_118 ;
} else {
V_63 = F_58 ( V_118 , V_47 ,
V_11 ) ;
if ( V_63 )
goto V_84;
}
if ( ! V_119 )
V_119 = V_118 ;
V_47 -> V_62 = V_118 ;
V_47 -> V_68 = V_132 ;
}
if ( V_119 ) {
V_63 = F_58 ( V_119 , V_47 ,
V_11 ) ;
if ( V_63 )
goto V_84;
V_116 -> V_18 = V_119 ;
V_116 -> V_34 = V_41 ;
}
if ( V_120 ) {
if ( V_47 -> V_68 != V_69 &&
V_47 -> V_68 != V_72 ) {
V_63 = - V_98 ;
F_61 ( V_81 L_23
L_24 ) ;
goto V_84;
}
if ( V_120 != V_47 -> V_60 ) {
V_63 = F_58 ( V_120 ,
V_47 , V_11 ) ;
if ( V_63 )
goto V_84;
}
V_47 -> V_60 = V_120 ;
}
V_133:
V_63 = F_60 ( V_58 ) ;
V_84:
F_82 ( & V_47 -> V_29 ) ;
return V_63 ;
V_125:
V_63 = - V_98 ;
F_61 ( V_81 L_25
L_26 , V_58 -> V_82 , V_74 ) ;
goto V_84;
}
static int F_83 ( const struct V_57 * V_135 ,
const struct V_57 * V_136 )
{
struct V_46 * V_137 = V_135 -> V_49 ;
struct V_46 * V_138 = V_136 -> V_49 ;
char V_139 = V_137 -> V_87 & V_99 ;
char V_140 = V_138 -> V_87 & V_99 ;
if ( V_139 != V_140 )
goto V_141;
if ( ( V_139 & V_106 ) && V_137 -> V_18 != V_138 -> V_18 )
goto V_141;
if ( ( V_139 & V_107 ) && V_137 -> V_62 != V_138 -> V_62 )
goto V_141;
if ( ( V_139 & V_108 ) && V_137 -> V_60 != V_138 -> V_60 )
goto V_141;
if ( V_139 & V_109 ) {
struct V_24 * V_142 = F_39 ( V_135 -> V_77 ) ;
struct V_24 * V_143 = F_39 ( V_136 -> V_77 ) ;
if ( V_142 -> V_18 != V_143 -> V_18 )
goto V_141;
}
return 0 ;
V_141:
F_61 ( V_81 L_27
L_28
L_29 , V_136 -> V_82 , V_136 -> V_73 -> V_74 ) ;
return - V_144 ;
}
static int F_84 ( const struct V_57 * V_135 ,
struct V_57 * V_136 ,
unsigned long V_114 ,
unsigned long * V_115 )
{
int V_63 = 0 ;
const struct V_46 * V_145 = V_135 -> V_49 ;
struct V_46 * V_146 = V_136 -> V_49 ;
int V_147 = ( V_145 -> V_87 & V_106 ) ;
int V_148 = ( V_145 -> V_87 & V_107 ) ;
int V_149 = ( V_145 -> V_87 & V_109 ) ;
if ( ! V_40 )
return 0 ;
if ( V_114 && ! V_115 )
return - V_98 ;
F_73 ( ! ( V_145 -> V_87 & V_88 ) ) ;
if ( V_146 -> V_87 & V_88 )
return F_83 ( V_135 , V_136 ) ;
F_78 ( & V_146 -> V_29 ) ;
V_146 -> V_87 = V_145 -> V_87 ;
V_146 -> V_18 = V_145 -> V_18 ;
V_146 -> V_60 = V_145 -> V_60 ;
V_146 -> V_68 = V_145 -> V_68 ;
if ( V_146 -> V_68 == V_72 &&
! ( V_114 & V_134 ) && ! V_148 ) {
V_63 = F_80 ( V_136 ) ;
if ( V_63 )
goto V_84;
}
if ( V_114 & V_134 && ! V_148 ) {
V_146 -> V_68 = V_72 ;
* V_115 |= V_134 ;
}
if ( V_148 ) {
T_2 V_18 = V_145 -> V_62 ;
if ( ! V_147 )
V_146 -> V_18 = V_18 ;
if ( ! V_149 ) {
struct V_24 * V_150 = F_39 ( V_136 -> V_77 ) ;
V_150 -> V_18 = V_18 ;
}
V_146 -> V_62 = V_18 ;
}
if ( V_149 ) {
const struct V_24 * V_151 = F_39 ( V_135 -> V_77 ) ;
struct V_24 * V_150 = F_39 ( V_136 -> V_77 ) ;
V_150 -> V_18 = V_151 -> V_18 ;
}
F_60 ( V_136 ) ;
V_84:
F_82 ( & V_146 -> V_29 ) ;
return V_63 ;
}
static int F_85 ( char * V_152 ,
struct V_92 * V_93 )
{
char * V_153 ;
char * V_95 = NULL , * V_154 = NULL ;
char * V_155 = NULL , * V_156 = NULL ;
int V_63 , V_101 = 0 ;
V_93 -> V_101 = 0 ;
while ( ( V_153 = F_86 ( & V_152 , L_30 ) ) != NULL ) {
int V_157 ;
T_3 args [ V_158 ] ;
if ( ! * V_153 )
continue;
V_157 = F_87 ( V_153 , V_159 , args ) ;
switch ( V_157 ) {
case V_160 :
if ( V_95 || V_154 ) {
V_63 = - V_98 ;
F_61 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_95 = F_88 ( & args [ 0 ] ) ;
if ( ! V_95 ) {
V_63 = - V_28 ;
goto V_161;
}
break;
case V_162 :
if ( V_155 ) {
V_63 = - V_98 ;
F_61 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_155 = F_88 ( & args [ 0 ] ) ;
if ( ! V_155 ) {
V_63 = - V_28 ;
goto V_161;
}
break;
case V_163 :
if ( V_156 ) {
V_63 = - V_98 ;
F_61 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_156 = F_88 ( & args [ 0 ] ) ;
if ( ! V_156 ) {
V_63 = - V_28 ;
goto V_161;
}
break;
case V_164 :
if ( V_95 || V_154 ) {
V_63 = - V_98 ;
F_61 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_154 = F_88 ( & args [ 0 ] ) ;
if ( ! V_154 ) {
V_63 = - V_28 ;
goto V_161;
}
break;
case V_165 :
break;
default:
V_63 = - V_98 ;
F_61 ( V_81 L_31 ) ;
goto V_161;
}
}
V_63 = - V_28 ;
V_93 -> V_102 = F_71 ( V_100 , sizeof( char * ) , V_16 ) ;
if ( ! V_93 -> V_102 )
goto V_161;
V_93 -> V_105 = F_71 ( V_100 , sizeof( int ) ,
V_16 ) ;
if ( ! V_93 -> V_105 )
goto V_161;
if ( V_155 ) {
V_93 -> V_102 [ V_101 ] = V_155 ;
V_93 -> V_105 [ V_101 ++ ] = V_106 ;
}
if ( V_95 ) {
V_93 -> V_102 [ V_101 ] = V_95 ;
V_93 -> V_105 [ V_101 ++ ] = V_107 ;
}
if ( V_156 ) {
V_93 -> V_102 [ V_101 ] = V_156 ;
V_93 -> V_105 [ V_101 ++ ] = V_109 ;
}
if ( V_154 ) {
V_93 -> V_102 [ V_101 ] = V_154 ;
V_93 -> V_105 [ V_101 ++ ] = V_108 ;
}
V_93 -> V_101 = V_101 ;
return 0 ;
V_161:
F_74 ( V_93 ) ;
F_54 ( V_95 ) ;
F_54 ( V_154 ) ;
F_54 ( V_155 ) ;
F_54 ( V_156 ) ;
return V_63 ;
}
static int F_89 ( struct V_57 * V_58 , void * V_166 )
{
int V_63 = 0 ;
char * V_152 = V_166 ;
struct V_92 V_93 ;
F_69 ( & V_93 ) ;
if ( ! V_166 )
goto V_84;
F_73 ( V_58 -> V_73 -> V_123 & V_124 ) ;
V_63 = F_85 ( V_152 , & V_93 ) ;
if ( V_63 )
goto V_161;
V_84:
V_63 = F_76 ( V_58 , & V_93 , 0 , NULL ) ;
V_161:
F_74 ( & V_93 ) ;
return V_63 ;
}
static void F_90 ( struct V_167 * V_168 ,
struct V_92 * V_93 )
{
int V_94 ;
char * V_169 ;
for ( V_94 = 0 ; V_94 < V_93 -> V_101 ; V_94 ++ ) {
char * V_170 ;
if ( V_93 -> V_102 [ V_94 ] )
V_170 = strchr ( V_93 -> V_102 [ V_94 ] , ',' ) ;
else
V_170 = NULL ;
switch ( V_93 -> V_105 [ V_94 ] ) {
case V_107 :
V_169 = V_171 ;
break;
case V_106 :
V_169 = V_172 ;
break;
case V_109 :
V_169 = V_173 ;
break;
case V_108 :
V_169 = V_174 ;
break;
case V_89 :
F_91 ( V_168 , ',' ) ;
F_92 ( V_168 , V_175 ) ;
continue;
default:
F_93 () ;
return;
} ;
F_91 ( V_168 , ',' ) ;
F_92 ( V_168 , V_169 ) ;
if ( V_170 )
F_91 ( V_168 , '\"' ) ;
F_94 ( V_168 , V_93 -> V_102 [ V_94 ] , L_32 ) ;
if ( V_170 )
F_91 ( V_168 , '\"' ) ;
}
}
static int F_95 ( struct V_167 * V_168 , struct V_57 * V_58 )
{
struct V_92 V_93 ;
int V_63 ;
V_63 = F_68 ( V_58 , & V_93 ) ;
if ( V_63 ) {
if ( V_63 == - V_98 )
V_63 = 0 ;
return V_63 ;
}
F_90 ( V_168 , & V_93 ) ;
F_74 ( & V_93 ) ;
return V_63 ;
}
static inline T_4 F_96 ( T_5 V_176 )
{
switch ( V_176 & V_177 ) {
case V_178 :
return V_179 ;
case V_180 :
return V_181 ;
case V_182 :
return V_33 ;
case V_183 :
return V_184 ;
case V_185 :
return V_186 ;
case V_187 :
return V_188 ;
case V_189 :
return V_190 ;
}
return V_33 ;
}
static inline int F_97 ( int V_191 )
{
return ( V_191 == V_192 || V_191 == V_193 ) ;
}
static inline int F_98 ( int V_191 )
{
return ( V_191 == V_192 || V_191 == V_194 ) ;
}
static inline T_4 F_99 ( int V_195 , int type , int V_191 )
{
int V_196 = V_197 ;
switch ( V_195 ) {
case V_198 :
switch ( type ) {
case V_199 :
case V_200 :
return V_201 ;
case V_202 :
return V_203 ;
}
break;
case V_204 :
case V_205 :
switch ( type ) {
case V_199 :
case V_200 :
if ( F_97 ( V_191 ) )
return V_206 ;
else if ( V_196 && V_191 == V_207 )
return V_208 ;
else
return V_209 ;
case V_202 :
if ( F_98 ( V_191 ) )
return V_210 ;
else if ( V_196 && ( V_191 == V_211 ||
V_191 == V_212 ) )
return V_213 ;
else
return V_209 ;
case V_214 :
return V_215 ;
default:
return V_209 ;
}
break;
case V_216 :
switch ( V_191 ) {
case V_217 :
return V_218 ;
case V_219 :
return V_220 ;
case V_221 :
return V_222 ;
case V_223 :
return V_224 ;
case V_225 :
return V_226 ;
case V_227 :
return V_228 ;
case V_229 :
return V_230 ;
case V_231 :
return V_232 ;
case V_233 :
return V_234 ;
case V_235 :
return V_236 ;
case V_237 :
return V_238 ;
case V_239 :
return V_240 ;
case V_241 :
return V_242 ;
case V_243 :
return V_244 ;
case V_245 :
return V_246 ;
case V_247 :
return V_248 ;
default:
return V_249 ;
}
case V_250 :
return V_251 ;
case V_252 :
return V_253 ;
case V_254 :
return V_255 ;
}
if ( V_196 ) {
switch ( V_195 ) {
case V_256 :
return V_257 ;
case V_258 :
return V_259 ;
case V_260 :
return V_261 ;
case V_262 :
return V_263 ;
case V_264 :
return V_265 ;
case V_266 :
return V_267 ;
case V_268 :
return V_269 ;
case V_270 :
return V_271 ;
case V_272 :
return V_273 ;
case V_274 :
return V_275 ;
case V_276 :
return V_277 ;
case V_278 :
return V_279 ;
case V_280 :
return V_281 ;
case V_282 :
return V_283 ;
case V_284 :
return V_285 ;
case V_286 :
return V_287 ;
case V_288 :
return V_289 ;
case V_290 :
return V_291 ;
case V_292 :
return V_293 ;
case V_294 :
return V_295 ;
case V_296 :
return V_297 ;
case V_298 :
return V_299 ;
case V_300 :
return V_301 ;
case V_302 :
return V_303 ;
case V_304 :
return V_305 ;
case V_306 :
return V_307 ;
case V_308 :
return V_309 ;
#if V_310 > 44
#error New address family defined, please update this function.
#endif
}
}
return V_311 ;
}
static int F_100 ( struct V_37 * V_37 ,
T_4 V_312 ,
T_4 V_87 ,
T_2 * V_18 )
{
int V_63 ;
struct V_57 * V_58 = V_37 -> V_313 ;
char * V_314 , * V_315 ;
V_314 = ( char * ) F_101 ( V_16 ) ;
if ( ! V_314 )
return - V_28 ;
V_315 = F_102 ( V_37 , V_314 , V_316 ) ;
if ( F_103 ( V_315 ) )
V_63 = F_104 ( V_315 ) ;
else {
if ( V_87 & V_126 ) {
while ( V_315 [ 1 ] >= '0' && V_315 [ 1 ] <= '9' ) {
V_315 [ 1 ] = '/' ;
V_315 ++ ;
}
}
V_63 = F_105 ( V_58 -> V_73 -> V_74 , V_315 , V_312 , V_18 ) ;
}
F_106 ( ( unsigned long ) V_314 ) ;
return V_63 ;
}
static int F_32 ( struct V_23 * V_23 , struct V_37 * V_38 )
{
struct V_46 * V_47 = NULL ;
struct V_24 * V_25 = V_23 -> V_36 ;
T_2 F_21 , V_18 = 0 ;
T_4 V_32 ;
struct V_37 * V_37 ;
#define F_107 255
char * V_95 = NULL ;
unsigned V_96 = 0 ;
int V_63 = 0 ;
if ( V_25 -> V_34 == V_41 )
return 0 ;
F_45 ( & V_25 -> V_29 ) ;
if ( V_25 -> V_34 == V_41 )
goto V_317;
if ( V_25 -> V_32 == V_33 )
V_25 -> V_32 = F_96 ( V_23 -> V_318 ) ;
V_47 = V_23 -> V_48 -> V_49 ;
if ( ! ( V_47 -> V_87 & V_88 ) ) {
F_45 ( & V_47 -> V_50 ) ;
if ( F_63 ( & V_25 -> V_30 ) )
F_108 ( & V_25 -> V_30 , & V_47 -> V_59 ) ;
F_47 ( & V_47 -> V_50 ) ;
goto V_317;
}
V_32 = V_25 -> V_32 ;
F_21 = V_25 -> F_21 ;
V_18 = V_25 -> V_18 ;
V_25 -> V_34 = V_319 ;
F_47 ( & V_25 -> V_29 ) ;
switch ( V_47 -> V_68 ) {
case V_72 :
break;
case V_69 :
if ( ! ( V_23 -> V_79 & V_80 ) ) {
V_18 = V_47 -> V_60 ;
break;
}
if ( V_38 ) {
V_37 = F_109 ( V_38 ) ;
} else {
V_37 = F_110 ( V_23 ) ;
}
if ( ! V_37 ) {
goto V_84;
}
V_96 = F_107 ;
V_95 = F_111 ( V_96 + 1 , V_27 ) ;
if ( ! V_95 ) {
V_63 = - V_28 ;
F_112 ( V_37 ) ;
goto V_84;
}
V_95 [ V_96 ] = '\0' ;
V_63 = F_62 ( V_37 , V_23 , V_85 , V_95 , V_96 ) ;
if ( V_63 == - V_320 ) {
F_54 ( V_95 ) ;
V_63 = F_62 ( V_37 , V_23 , V_85 , NULL , 0 ) ;
if ( V_63 < 0 ) {
F_112 ( V_37 ) ;
goto V_84;
}
V_96 = V_63 ;
V_95 = F_111 ( V_96 + 1 , V_27 ) ;
if ( ! V_95 ) {
V_63 = - V_28 ;
F_112 ( V_37 ) ;
goto V_84;
}
V_95 [ V_96 ] = '\0' ;
V_63 = F_62 ( V_37 , V_23 , V_85 , V_95 , V_96 ) ;
}
F_112 ( V_37 ) ;
if ( V_63 < 0 ) {
if ( V_63 != - V_86 ) {
F_61 ( V_81 L_33
L_34 , V_128 ,
- V_63 , V_23 -> V_48 -> V_82 , V_23 -> V_321 ) ;
F_54 ( V_95 ) ;
goto V_84;
}
V_18 = V_47 -> V_60 ;
V_63 = 0 ;
} else {
V_63 = F_113 ( V_95 , V_63 , & V_18 ,
V_47 -> V_60 ,
V_27 ) ;
if ( V_63 ) {
char * V_322 = V_23 -> V_48 -> V_82 ;
unsigned long V_323 = V_23 -> V_321 ;
if ( V_63 == - V_98 ) {
if ( F_114 () )
F_61 ( V_324 L_35
L_36
L_37 , V_323 , V_322 , V_95 ) ;
} else {
F_61 ( V_81 L_38
L_39 ,
V_128 , V_95 , - V_63 , V_322 , V_323 ) ;
}
F_54 ( V_95 ) ;
V_63 = 0 ;
break;
}
}
F_54 ( V_95 ) ;
break;
case V_71 :
V_18 = F_21 ;
break;
case V_70 :
V_18 = V_47 -> V_18 ;
V_63 = F_81 ( F_21 , V_18 , V_32 , NULL , & V_18 ) ;
if ( V_63 )
goto V_84;
break;
case V_132 :
V_18 = V_47 -> V_62 ;
break;
default:
V_18 = V_47 -> V_18 ;
if ( ( V_47 -> V_87 & V_127 ) && ! F_115 ( V_23 -> V_318 ) ) {
if ( V_38 )
V_37 = F_109 ( V_38 ) ;
else
V_37 = F_110 ( V_23 ) ;
if ( ! V_37 )
goto V_84;
V_63 = F_100 ( V_37 , V_32 ,
V_47 -> V_87 , & V_18 ) ;
F_112 ( V_37 ) ;
if ( V_63 )
goto V_84;
}
break;
}
V_84:
F_45 ( & V_25 -> V_29 ) ;
if ( V_25 -> V_34 == V_319 ) {
if ( ! V_18 || V_63 ) {
V_25 -> V_34 = V_35 ;
goto V_317;
}
V_25 -> V_34 = V_41 ;
V_25 -> V_18 = V_18 ;
}
V_317:
F_47 ( & V_25 -> V_29 ) ;
return V_63 ;
}
static inline T_2 F_116 ( int V_325 )
{
T_2 V_326 = 0 ;
switch ( V_325 ) {
case V_327 :
V_326 = V_328 ;
break;
case V_329 :
V_326 = V_330 ;
break;
case V_331 :
V_326 = V_332 ;
break;
default:
V_326 = V_333 ;
break;
}
return V_326 ;
}
static int F_117 ( const struct V_11 * V_11 ,
int V_334 , int V_335 , bool V_336 )
{
struct V_337 V_338 ;
struct V_339 V_340 ;
T_4 V_32 ;
T_2 V_18 = F_20 ( V_11 ) ;
T_2 V_341 = F_118 ( V_334 ) ;
int V_63 ;
V_338 . type = V_342 ;
V_338 . V_343 . V_334 = V_334 ;
switch ( F_119 ( V_334 ) ) {
case 0 :
V_32 = V_336 ? V_344 : V_345 ;
break;
case 1 :
V_32 = V_336 ? V_346 : V_347 ;
break;
default:
F_61 ( V_348
L_40 , V_334 ) ;
F_93 () ;
return - V_98 ;
}
V_63 = F_120 ( V_18 , V_18 , V_32 , V_341 , 0 , & V_340 ) ;
if ( V_335 == V_349 ) {
int V_350 = F_121 ( V_18 , V_18 , V_32 , V_341 , & V_340 , V_63 , & V_338 , 0 ) ;
if ( V_350 )
return V_350 ;
}
return V_63 ;
}
static int F_122 ( const struct V_11 * V_11 ,
struct V_23 * V_23 ,
T_2 V_351 ,
struct V_337 * V_352 )
{
struct V_24 * V_25 ;
T_2 V_18 ;
F_123 ( V_11 ) ;
if ( F_124 ( F_66 ( V_23 ) ) )
return 0 ;
V_18 = F_20 ( V_11 ) ;
V_25 = V_23 -> V_36 ;
return F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_351 , V_352 ) ;
}
static inline int F_125 ( const struct V_11 * V_11 ,
struct V_37 * V_37 ,
T_2 V_341 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
struct V_337 V_338 ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_37 ;
F_30 ( V_23 , V_37 , true ) ;
return F_122 ( V_11 , V_23 , V_341 , & V_338 ) ;
}
static inline int F_126 ( const struct V_11 * V_11 ,
const struct V_315 * V_315 ,
T_2 V_341 )
{
struct V_23 * V_23 = F_38 ( V_315 -> V_37 ) ;
struct V_337 V_338 ;
V_338 . type = V_354 ;
V_338 . V_343 . V_315 = * V_315 ;
F_30 ( V_23 , V_315 -> V_37 , true ) ;
return F_122 ( V_11 , V_23 , V_341 , & V_338 ) ;
}
static inline int F_127 ( const struct V_11 * V_11 ,
struct V_51 * V_51 ,
T_2 V_341 )
{
struct V_337 V_338 ;
V_338 . type = V_355 ;
V_338 . V_343 . V_51 = V_51 ;
return F_122 ( V_11 , F_128 ( V_51 ) , V_341 , & V_338 ) ;
}
static int F_129 ( const struct V_11 * V_11 ,
struct V_51 * V_51 ,
T_2 V_341 )
{
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
struct V_337 V_338 ;
T_2 V_18 = F_20 ( V_11 ) ;
int V_63 ;
V_338 . type = V_355 ;
V_338 . V_343 . V_51 = V_51 ;
if ( V_18 != V_53 -> V_18 ) {
V_63 = F_57 ( V_18 , V_53 -> V_18 ,
V_356 ,
V_357 ,
& V_338 ) ;
if ( V_63 )
goto V_84;
}
V_63 = 0 ;
if ( V_341 )
V_63 = F_122 ( V_11 , V_23 , V_341 , & V_338 ) ;
V_84:
return V_63 ;
}
static int
F_130 ( const struct V_14 * V_15 ,
struct V_23 * V_358 ,
const struct V_359 * V_74 , T_4 V_312 ,
T_2 * V_360 )
{
const struct V_46 * V_47 = V_358 -> V_48 -> V_49 ;
if ( ( V_47 -> V_87 & V_88 ) &&
( V_47 -> V_68 == V_132 ) ) {
* V_360 = V_47 -> V_62 ;
} else if ( ( V_47 -> V_87 & V_89 ) &&
V_15 -> V_361 ) {
* V_360 = V_15 -> V_361 ;
} else {
const struct V_24 * V_362 = F_36 ( V_358 ) ;
return F_81 ( V_15 -> V_18 , V_362 -> V_18 , V_312 ,
V_74 , V_360 ) ;
}
return 0 ;
}
static int F_131 ( struct V_23 * V_358 ,
struct V_37 * V_37 ,
T_4 V_312 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_24 * V_362 ;
struct V_46 * V_47 ;
T_2 V_18 , V_363 ;
struct V_337 V_338 ;
int V_63 ;
V_362 = F_36 ( V_358 ) ;
V_47 = V_358 -> V_48 -> V_49 ;
V_18 = V_15 -> V_18 ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_37 ;
V_63 = F_57 ( V_18 , V_362 -> V_18 , V_186 ,
V_364 | V_365 ,
& V_338 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_130 ( F_132 () , V_358 ,
& V_37 -> V_366 , V_312 , & V_363 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_18 , V_363 , V_312 , V_367 , & V_338 ) ;
if ( V_63 )
return V_63 ;
return F_57 ( V_363 , V_47 -> V_18 ,
V_64 ,
V_67 , & V_338 ) ;
}
static int F_133 ( struct V_23 * V_358 ,
struct V_37 * V_37 ,
int V_368 )
{
struct V_24 * V_362 , * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
T_2 V_341 ;
int V_63 ;
V_362 = F_36 ( V_358 ) ;
V_25 = F_39 ( V_37 ) ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_37 ;
V_341 = V_365 ;
V_341 |= ( V_368 ? V_369 : V_364 ) ;
V_63 = F_57 ( V_18 , V_362 -> V_18 , V_186 , V_341 , & V_338 ) ;
if ( V_63 )
return V_63 ;
switch ( V_368 ) {
case V_370 :
V_341 = V_371 ;
break;
case V_372 :
V_341 = V_373 ;
break;
case V_374 :
V_341 = V_375 ;
break;
default:
F_61 ( V_81 L_41 ,
V_128 , V_368 ) ;
return 0 ;
}
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_341 , & V_338 ) ;
return V_63 ;
}
static inline int F_134 ( struct V_23 * V_376 ,
struct V_37 * V_377 ,
struct V_23 * V_378 ,
struct V_37 * V_379 )
{
struct V_24 * V_380 , * V_381 , * V_382 , * V_383 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
T_2 V_341 ;
int V_384 , V_385 ;
int V_63 ;
V_380 = F_36 ( V_376 ) ;
V_382 = F_39 ( V_377 ) ;
V_384 = F_135 ( V_377 ) ;
V_381 = F_36 ( V_378 ) ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_377 ;
V_63 = F_57 ( V_18 , V_380 -> V_18 , V_186 ,
V_369 | V_365 , & V_338 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_18 , V_382 -> V_18 ,
V_382 -> V_32 , V_386 , & V_338 ) ;
if ( V_63 )
return V_63 ;
if ( V_384 && V_378 != V_376 ) {
V_63 = F_57 ( V_18 , V_382 -> V_18 ,
V_382 -> V_32 , V_387 , & V_338 ) ;
if ( V_63 )
return V_63 ;
}
V_338 . V_343 . V_37 = V_379 ;
V_341 = V_364 | V_365 ;
if ( F_136 ( V_379 ) )
V_341 |= V_369 ;
V_63 = F_57 ( V_18 , V_381 -> V_18 , V_186 , V_341 , & V_338 ) ;
if ( V_63 )
return V_63 ;
if ( F_136 ( V_379 ) ) {
V_383 = F_39 ( V_379 ) ;
V_385 = F_135 ( V_379 ) ;
V_63 = F_57 ( V_18 , V_383 -> V_18 ,
V_383 -> V_32 ,
( V_385 ? V_375 : V_373 ) , & V_338 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_137 ( const struct V_11 * V_11 ,
struct V_57 * V_58 ,
T_2 V_351 ,
struct V_337 * V_338 )
{
struct V_46 * V_47 ;
T_2 V_18 = F_20 ( V_11 ) ;
V_47 = V_58 -> V_49 ;
return F_57 ( V_18 , V_47 -> V_18 , V_64 , V_351 , V_338 ) ;
}
static inline T_2 F_138 ( int V_176 , int V_388 )
{
T_2 V_341 = 0 ;
if ( ! F_139 ( V_176 ) ) {
if ( V_388 & V_389 )
V_341 |= V_390 ;
if ( V_388 & V_391 )
V_341 |= V_392 ;
if ( V_388 & V_393 )
V_341 |= V_394 ;
else if ( V_388 & V_395 )
V_341 |= V_396 ;
} else {
if ( V_388 & V_389 )
V_341 |= V_365 ;
if ( V_388 & V_395 )
V_341 |= V_397 ;
if ( V_388 & V_391 )
V_341 |= V_398 ;
}
return V_341 ;
}
static inline T_2 F_140 ( struct V_51 * V_51 )
{
T_2 V_341 = 0 ;
if ( V_51 -> V_399 & V_400 )
V_341 |= V_392 ;
if ( V_51 -> V_399 & V_401 ) {
if ( V_51 -> V_402 & V_403 )
V_341 |= V_394 ;
else
V_341 |= V_396 ;
}
if ( ! V_341 ) {
V_341 = V_404 ;
}
return V_341 ;
}
static inline T_2 F_141 ( struct V_51 * V_51 )
{
T_2 V_341 = F_140 ( V_51 ) ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
if ( V_405 && V_23 -> V_48 -> V_406 != V_407 )
V_341 |= V_408 ;
return V_341 ;
}
static int F_142 ( struct V_21 * V_409 )
{
T_2 V_410 = F_26 () ;
T_2 V_411 = F_21 ( V_409 ) ;
return F_57 ( V_410 , V_411 , V_412 ,
V_413 , NULL ) ;
}
static int F_143 ( struct V_21 * V_414 ,
struct V_21 * V_415 )
{
T_2 V_410 = F_26 () ;
T_2 V_416 = F_21 ( V_414 ) ;
T_2 V_417 = F_21 ( V_415 ) ;
int V_63 ;
if ( V_410 != V_416 ) {
V_63 = F_57 ( V_410 , V_416 , V_412 ,
V_418 , NULL ) ;
if ( V_63 )
return V_63 ;
}
return F_57 ( V_416 , V_417 , V_412 , V_419 ,
NULL ) ;
}
static int F_144 ( struct V_21 * V_414 ,
struct V_21 * V_415 )
{
T_2 V_416 = F_21 ( V_414 ) ;
T_2 V_417 = F_21 ( V_415 ) ;
return F_57 ( V_416 , V_417 , V_412 , V_420 ,
NULL ) ;
}
static int F_145 ( struct V_21 * V_414 ,
struct V_21 * V_415 ,
struct V_51 * V_51 )
{
T_2 V_18 = F_21 ( V_415 ) ;
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_37 * V_37 = V_51 -> V_421 . V_37 ;
struct V_24 * V_25 ;
struct V_337 V_338 ;
int V_63 ;
V_338 . type = V_354 ;
V_338 . V_343 . V_315 = V_51 -> V_421 ;
if ( V_18 != V_53 -> V_18 ) {
V_63 = F_57 ( V_18 , V_53 -> V_18 ,
V_356 ,
V_357 ,
& V_338 ) ;
if ( V_63 )
return V_63 ;
}
if ( F_124 ( F_66 ( F_38 ( V_37 ) ) ) )
return 0 ;
V_25 = F_39 ( V_37 ) ;
return F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , F_140 ( V_51 ) ,
& V_338 ) ;
}
static int F_146 ( struct V_21 * V_422 ,
unsigned int V_176 )
{
T_2 V_18 = F_26 () ;
T_2 V_423 = F_21 ( V_422 ) ;
if ( V_176 & V_424 )
return F_57 ( V_18 , V_423 , V_33 , V_392 , NULL ) ;
return F_57 ( V_18 , V_423 , V_425 , V_426 , NULL ) ;
}
static int F_147 ( struct V_21 * V_427 )
{
return F_57 ( F_21 ( V_427 ) , F_26 () , V_425 ,
V_426 , NULL ) ;
}
static int F_148 ( struct V_21 * V_428 , T_6 * V_429 ,
T_6 * V_430 , T_6 * V_431 )
{
return F_57 ( F_26 () , F_21 ( V_428 ) , V_425 ,
V_432 , NULL ) ;
}
static int F_149 ( struct V_11 * V_138 , const struct V_11 * V_137 ,
const T_6 * V_429 ,
const T_6 * V_430 ,
const T_6 * V_431 )
{
return F_57 ( F_20 ( V_137 ) , F_20 ( V_138 ) , V_425 ,
V_433 , NULL ) ;
}
static int F_150 ( const struct V_11 * V_11 , struct V_434 * V_435 ,
int V_334 , int V_335 )
{
return F_117 ( V_11 , V_334 , V_335 , V_435 == & V_130 ) ;
}
static int F_151 ( int V_436 , int type , int V_437 , struct V_57 * V_58 )
{
const struct V_11 * V_11 = F_77 () ;
int V_63 = 0 ;
if ( ! V_58 )
return 0 ;
switch ( V_436 ) {
case V_438 :
case V_439 :
case V_440 :
case V_441 :
case V_442 :
V_63 = F_137 ( V_11 , V_58 , V_443 , NULL ) ;
break;
case V_444 :
case V_445 :
case V_446 :
V_63 = F_137 ( V_11 , V_58 , V_447 , NULL ) ;
break;
default:
V_63 = 0 ;
break;
}
return V_63 ;
}
static int F_152 ( struct V_37 * V_37 )
{
const struct V_11 * V_11 = F_77 () ;
return F_125 ( V_11 , V_37 , V_448 ) ;
}
static int F_153 ( int type )
{
switch ( type ) {
case V_449 :
case V_450 :
return F_57 ( F_26 () , V_19 ,
V_451 , V_452 , NULL ) ;
case V_453 :
case V_454 :
case V_455 :
return F_57 ( F_26 () , V_19 ,
V_451 , V_456 ,
NULL ) ;
}
return F_57 ( F_26 () , V_19 ,
V_451 , V_457 , NULL ) ;
}
static int F_154 ( struct V_458 * V_459 , long V_460 )
{
int V_63 , V_461 = 0 ;
V_63 = F_117 ( F_77 () , V_462 ,
V_463 , true ) ;
if ( V_63 == 0 )
V_461 = 1 ;
return V_461 ;
}
static T_2 F_155 ( void )
{
T_2 V_18 = 0 ;
struct V_21 * V_464 ;
F_22 () ;
V_464 = F_156 ( V_12 ) ;
if ( V_464 )
V_18 = F_21 ( V_464 ) ;
F_24 () ;
return V_18 ;
}
static int F_157 ( const struct V_465 * V_466 ,
const struct V_14 * V_467 ,
const struct V_14 * V_468 )
{
int V_469 = ( V_466 -> V_470 & V_471 ) ;
int V_472 = ! F_158 ( V_466 -> V_51 -> V_421 . V_473 ) ;
int V_63 ;
if ( ! V_469 && ! V_472 )
return 0 ;
if ( V_468 -> V_18 == V_467 -> V_18 )
return 0 ;
V_63 = F_159 ( V_467 -> V_18 , V_468 -> V_18 ) ;
if ( V_63 ) {
if ( V_469 )
return - V_474 ;
else
return - V_131 ;
}
return 0 ;
}
static int F_160 ( struct V_465 * V_466 )
{
const struct V_14 * V_467 ;
struct V_14 * V_468 ;
struct V_24 * V_25 ;
struct V_337 V_338 ;
struct V_23 * V_23 = F_128 ( V_466 -> V_51 ) ;
int V_63 ;
if ( V_466 -> V_475 )
return 0 ;
V_467 = F_132 () ;
V_468 = V_466 -> V_11 -> V_20 ;
V_25 = F_36 ( V_23 ) ;
V_468 -> V_18 = V_467 -> V_18 ;
V_468 -> V_17 = V_467 -> V_18 ;
V_468 -> V_361 = 0 ;
V_468 -> V_476 = 0 ;
V_468 -> V_477 = 0 ;
if ( V_467 -> V_478 ) {
V_468 -> V_18 = V_467 -> V_478 ;
V_468 -> V_478 = 0 ;
V_63 = F_157 ( V_466 , V_467 , V_468 ) ;
if ( V_63 )
return V_63 ;
} else {
V_63 = F_81 ( V_467 -> V_18 , V_25 -> V_18 ,
V_425 , NULL ,
& V_468 -> V_18 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_157 ( V_466 , V_467 , V_468 ) ;
if ( V_63 )
V_468 -> V_18 = V_467 -> V_18 ;
}
V_338 . type = V_355 ;
V_338 . V_343 . V_51 = V_466 -> V_51 ;
if ( V_468 -> V_18 == V_467 -> V_18 ) {
V_63 = F_57 ( V_467 -> V_18 , V_25 -> V_18 ,
V_33 , V_479 , & V_338 ) ;
if ( V_63 )
return V_63 ;
} else {
V_63 = F_57 ( V_467 -> V_18 , V_468 -> V_18 ,
V_425 , V_480 , & V_338 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_468 -> V_18 , V_25 -> V_18 ,
V_33 , V_481 , & V_338 ) ;
if ( V_63 )
return V_63 ;
if ( V_466 -> V_470 & V_482 ) {
V_63 = F_57 ( V_467 -> V_18 , V_468 -> V_18 ,
V_425 , V_483 ,
NULL ) ;
if ( V_63 )
return - V_474 ;
}
if ( V_466 -> V_470 & V_484 ) {
T_2 V_485 = F_155 () ;
if ( V_485 != 0 ) {
V_63 = F_57 ( V_485 , V_468 -> V_18 ,
V_425 ,
V_426 , NULL ) ;
if ( V_63 )
return - V_474 ;
}
}
V_466 -> V_486 |= V_487 ;
}
return 0 ;
}
static int F_161 ( struct V_465 * V_466 )
{
const struct V_14 * V_15 = F_132 () ;
T_2 V_18 , V_17 ;
int V_488 = 0 ;
V_18 = V_15 -> V_18 ;
V_17 = V_15 -> V_17 ;
if ( V_17 != V_18 ) {
V_488 = F_57 ( V_17 , V_18 ,
V_425 ,
V_489 , NULL ) ;
}
return ! ! V_488 ;
}
static int F_162 ( const void * V_153 , struct V_51 * V_51 , unsigned V_490 )
{
return F_129 ( V_153 , V_51 , F_140 ( V_51 ) ) ? V_490 + 1 : 0 ;
}
static inline void F_163 ( const struct V_11 * V_11 ,
struct V_491 * V_492 )
{
struct V_51 * V_51 , * V_493 = NULL ;
struct V_494 * V_495 ;
int V_496 = 0 ;
unsigned V_497 ;
V_495 = F_164 () ;
if ( V_495 ) {
F_45 ( & V_495 -> V_498 ) ;
if ( ! F_63 ( & V_495 -> V_499 ) ) {
struct V_500 * V_501 ;
V_501 = F_165 ( & V_495 -> V_499 ,
struct V_500 , V_30 ) ;
V_51 = V_501 -> V_51 ;
if ( F_127 ( V_11 , V_51 , V_392 | V_396 ) )
V_496 = 1 ;
}
F_47 ( & V_495 -> V_498 ) ;
F_166 ( V_495 ) ;
}
if ( V_496 )
F_167 () ;
V_497 = F_168 ( V_492 , 0 , F_162 , V_11 ) ;
if ( ! V_497 )
return;
V_493 = F_169 ( & V_502 , V_503 , V_11 ) ;
if ( F_103 ( V_493 ) )
V_493 = NULL ;
do {
F_170 ( V_497 - 1 , V_493 , 0 ) ;
} while ( ( V_497 = F_168 ( V_492 , V_497 , F_162 , V_11 ) ) != 0 );
if ( V_493 )
F_171 ( V_493 ) ;
}
static void F_172 ( struct V_465 * V_466 )
{
struct V_14 * V_468 ;
struct V_504 * V_505 , * V_506 ;
int V_63 , V_94 ;
V_468 = V_466 -> V_11 -> V_20 ;
if ( V_468 -> V_18 == V_468 -> V_17 )
return;
F_163 ( V_466 -> V_11 , V_12 -> V_492 ) ;
V_12 -> V_507 = 0 ;
V_63 = F_57 ( V_468 -> V_17 , V_468 -> V_18 , V_425 ,
V_508 , NULL ) ;
if ( V_63 ) {
F_173 ( V_12 ) ;
for ( V_94 = 0 ; V_94 < V_509 ; V_94 ++ ) {
V_505 = V_12 -> signal -> V_505 + V_94 ;
V_506 = V_510 . signal -> V_505 + V_94 ;
V_505 -> V_511 = F_174 ( V_505 -> V_512 , V_506 -> V_511 ) ;
}
F_175 ( V_12 ) ;
if ( F_176 ( V_513 ) )
F_177 ( V_12 , V_504 ( V_514 ) ) ;
}
}
static void F_178 ( struct V_465 * V_466 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_515 V_516 ;
T_2 V_17 , V_18 ;
int V_63 , V_94 ;
V_17 = V_15 -> V_17 ;
V_18 = V_15 -> V_18 ;
if ( V_18 == V_17 )
return;
V_63 = F_57 ( V_17 , V_18 , V_425 , V_517 , NULL ) ;
if ( V_63 ) {
if ( F_176 ( V_513 ) ) {
memset ( & V_516 , 0 , sizeof V_516 ) ;
for ( V_94 = 0 ; V_94 < 3 ; V_94 ++ )
F_179 ( V_94 , & V_516 , NULL ) ;
}
F_180 ( & V_12 -> V_518 -> V_519 ) ;
if ( ! F_181 ( V_12 ) ) {
F_182 ( & V_12 -> V_520 ) ;
F_182 ( & V_12 -> signal -> V_521 ) ;
F_183 ( V_12 , 1 ) ;
F_184 ( & V_12 -> V_522 ) ;
F_185 () ;
}
F_186 ( & V_12 -> V_518 -> V_519 ) ;
}
F_187 ( & V_523 ) ;
F_188 ( V_12 , V_12 -> V_524 ) ;
F_189 ( & V_523 ) ;
}
static int F_190 ( struct V_57 * V_58 )
{
return F_51 ( V_58 ) ;
}
static void F_191 ( struct V_57 * V_58 )
{
F_53 ( V_58 ) ;
}
static inline int F_192 ( char * V_169 , int V_525 , char * V_526 , int V_527 )
{
if ( V_525 > V_527 )
return 0 ;
return ! memcmp ( V_169 , V_526 , V_525 ) ;
}
static inline int F_193 ( char * V_526 , int V_96 )
{
return ( F_192 ( V_171 , sizeof( V_171 ) - 1 , V_526 , V_96 ) ||
F_192 ( V_172 , sizeof( V_172 ) - 1 , V_526 , V_96 ) ||
F_192 ( V_174 , sizeof( V_174 ) - 1 , V_526 , V_96 ) ||
F_192 ( V_173 , sizeof( V_173 ) - 1 , V_526 , V_96 ) ||
F_192 ( V_175 , sizeof( V_175 ) - 1 , V_526 , V_96 ) ) ;
}
static inline void F_194 ( char * * V_415 , char * V_414 , int * V_528 , int V_96 )
{
if ( ! * V_528 ) {
* * V_415 = ',' ;
* V_415 += 1 ;
} else
* V_528 = 0 ;
memcpy ( * V_415 , V_414 , V_96 ) ;
* V_415 += V_96 ;
}
static inline void F_195 ( char * * V_415 , char * V_414 , int * V_528 ,
int V_96 )
{
int V_529 = 0 ;
if ( ! * V_528 ) {
* * V_415 = '|' ;
* V_415 += 1 ;
} else
* V_528 = 0 ;
while ( V_529 < V_96 ) {
if ( * V_414 != '"' ) {
* * V_415 = * V_414 ;
* V_415 += 1 ;
}
V_414 += 1 ;
V_529 += 1 ;
}
}
static int F_196 ( char * V_530 , char * V_531 )
{
int V_532 , V_53 , V_63 = 0 ;
char * V_533 , * V_534 , * V_535 ;
char * V_536 , * V_537 , * V_538 ;
int V_539 = 0 ;
V_534 = V_530 ;
V_536 = V_531 ;
V_538 = ( char * ) F_197 ( V_16 ) ;
if ( ! V_538 ) {
V_63 = - V_28 ;
goto V_84;
}
V_537 = V_538 ;
V_532 = V_53 = 1 ;
V_533 = V_535 = V_530 ;
do {
if ( * V_535 == '"' )
V_539 = ! V_539 ;
if ( ( * V_535 == ',' && V_539 == 0 ) ||
* V_535 == '\0' ) {
int V_96 = V_535 - V_534 ;
if ( F_193 ( V_534 , V_96 ) )
F_195 ( & V_536 , V_534 , & V_53 , V_96 ) ;
else
F_194 ( & V_538 , V_534 , & V_532 , V_96 ) ;
V_534 = V_535 + 1 ;
}
} while ( * V_535 ++ );
strcpy ( V_533 , V_537 ) ;
F_106 ( ( unsigned long ) V_537 ) ;
V_84:
return V_63 ;
}
static int F_198 ( struct V_57 * V_58 , void * V_166 )
{
int V_63 , V_94 , * V_87 ;
struct V_92 V_93 ;
char * V_540 , * * V_121 ;
struct V_46 * V_47 = V_58 -> V_49 ;
if ( ! ( V_47 -> V_87 & V_88 ) )
return 0 ;
if ( ! V_166 )
return 0 ;
if ( V_58 -> V_73 -> V_123 & V_124 )
return 0 ;
F_69 ( & V_93 ) ;
V_540 = F_199 () ;
if ( ! V_540 )
return - V_28 ;
V_63 = F_196 ( V_166 , V_540 ) ;
if ( V_63 )
goto V_541;
V_63 = F_85 ( V_540 , & V_93 ) ;
if ( V_63 )
goto V_541;
V_121 = V_93 . V_102 ;
V_87 = V_93 . V_105 ;
for ( V_94 = 0 ; V_94 < V_93 . V_101 ; V_94 ++ ) {
T_2 V_18 ;
if ( V_87 [ V_94 ] == V_89 )
continue;
V_63 = F_79 ( V_121 [ V_94 ] , & V_18 , V_16 ) ;
if ( V_63 ) {
F_61 ( V_81 L_16
L_17 ,
V_121 [ V_94 ] , V_58 -> V_82 , V_58 -> V_73 -> V_74 , V_63 ) ;
goto V_542;
}
V_63 = - V_98 ;
switch ( V_87 [ V_94 ] ) {
case V_106 :
if ( F_75 ( V_47 , V_106 , V_47 -> V_18 , V_18 ) )
goto V_543;
break;
case V_107 :
if ( F_75 ( V_47 , V_107 , V_47 -> V_62 , V_18 ) )
goto V_543;
break;
case V_109 : {
struct V_24 * V_116 ;
V_116 = F_39 ( V_58 -> V_77 ) ;
if ( F_75 ( V_47 , V_109 , V_116 -> V_18 , V_18 ) )
goto V_543;
break;
}
case V_108 :
if ( F_75 ( V_47 , V_108 , V_47 -> V_60 , V_18 ) )
goto V_543;
break;
default:
goto V_542;
}
}
V_63 = 0 ;
V_542:
F_74 ( & V_93 ) ;
V_541:
F_200 ( V_540 ) ;
return V_63 ;
V_543:
F_61 ( V_81 L_42
L_43 , V_58 -> V_82 ,
V_58 -> V_73 -> V_74 ) ;
goto V_542;
}
static int F_201 ( struct V_57 * V_58 , int V_87 , void * V_166 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_337 V_338 ;
int V_63 ;
V_63 = F_89 ( V_58 , V_166 ) ;
if ( V_63 )
return V_63 ;
if ( V_87 & V_544 )
return 0 ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_58 -> V_77 ;
return F_137 ( V_11 , V_58 , V_545 , & V_338 ) ;
}
static int F_202 ( struct V_37 * V_37 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_337 V_338 ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_37 -> V_313 -> V_77 ;
return F_137 ( V_11 , V_37 -> V_313 , V_546 , & V_338 ) ;
}
static int F_203 ( const char * V_547 ,
const struct V_315 * V_315 ,
const char * type ,
unsigned long V_87 ,
void * V_166 )
{
const struct V_11 * V_11 = F_77 () ;
if ( V_87 & V_548 )
return F_137 ( V_11 , V_315 -> V_37 -> V_313 ,
V_549 , NULL ) ;
else
return F_126 ( V_11 , V_315 , V_550 ) ;
}
static int F_204 ( struct V_551 * V_473 , int V_87 )
{
const struct V_11 * V_11 = F_77 () ;
return F_137 ( V_11 , V_473 -> V_552 ,
V_553 , NULL ) ;
}
static int F_205 ( struct V_23 * V_23 )
{
return F_25 ( V_23 ) ;
}
static void F_206 ( struct V_23 * V_23 )
{
F_43 ( V_23 ) ;
}
static int F_207 ( struct V_37 * V_37 , int V_176 ,
const struct V_359 * V_74 , void * * V_554 ,
T_2 * V_555 )
{
T_2 V_363 ;
int V_63 ;
V_63 = F_130 ( F_132 () ,
F_208 ( V_37 -> V_556 ) , V_74 ,
F_96 ( V_176 ) ,
& V_363 ) ;
if ( V_63 )
return V_63 ;
return F_72 ( V_363 , ( char * * ) V_554 , V_555 ) ;
}
static int F_209 ( struct V_37 * V_37 , int V_176 ,
struct V_359 * V_74 ,
const struct V_11 * V_137 ,
struct V_11 * V_138 )
{
T_2 V_363 ;
int V_63 ;
struct V_14 * V_15 ;
V_63 = F_130 ( V_137 -> V_20 ,
F_208 ( V_37 -> V_556 ) , V_74 ,
F_96 ( V_176 ) ,
& V_363 ) ;
if ( V_63 )
return V_63 ;
V_15 = V_138 -> V_20 ;
V_15 -> V_361 = V_363 ;
return 0 ;
}
static int F_210 ( struct V_23 * V_23 , struct V_23 * V_358 ,
const struct V_359 * V_359 ,
const char * * V_74 ,
void * * V_557 , T_7 * V_96 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_46 * V_47 ;
T_2 V_18 , V_363 , V_558 ;
int V_63 ;
char * V_95 ;
V_47 = V_358 -> V_48 -> V_49 ;
V_18 = V_15 -> V_18 ;
V_363 = V_15 -> V_361 ;
V_63 = F_130 ( F_132 () ,
V_358 , V_359 ,
F_96 ( V_23 -> V_318 ) ,
& V_363 ) ;
if ( V_63 )
return V_63 ;
if ( V_47 -> V_87 & V_88 ) {
struct V_24 * V_25 = V_23 -> V_36 ;
V_25 -> V_32 = F_96 ( V_23 -> V_318 ) ;
V_25 -> V_18 = V_363 ;
V_25 -> V_34 = V_41 ;
}
if ( ! V_40 || ! ( V_47 -> V_87 & V_89 ) )
return - V_83 ;
if ( V_74 )
* V_74 = V_559 ;
if ( V_557 && V_96 ) {
V_63 = F_211 ( V_363 , & V_95 , & V_558 ) ;
if ( V_63 )
return V_63 ;
* V_557 = V_95 ;
* V_96 = V_558 ;
}
return 0 ;
}
static int F_212 ( struct V_23 * V_358 , struct V_37 * V_37 , T_5 V_176 )
{
return F_131 ( V_358 , V_37 , V_33 ) ;
}
static int F_213 ( struct V_37 * V_377 , struct V_23 * V_358 , struct V_37 * V_379 )
{
return F_133 ( V_358 , V_377 , V_370 ) ;
}
static int F_214 ( struct V_23 * V_358 , struct V_37 * V_37 )
{
return F_133 ( V_358 , V_37 , V_372 ) ;
}
static int F_215 ( struct V_23 * V_358 , struct V_37 * V_37 , const char * V_74 )
{
return F_131 ( V_358 , V_37 , V_181 ) ;
}
static int F_216 ( struct V_23 * V_358 , struct V_37 * V_37 , T_5 V_388 )
{
return F_131 ( V_358 , V_37 , V_186 ) ;
}
static int F_217 ( struct V_23 * V_358 , struct V_37 * V_37 )
{
return F_133 ( V_358 , V_37 , V_374 ) ;
}
static int F_218 ( struct V_23 * V_358 , struct V_37 * V_37 , T_5 V_176 , T_8 V_322 )
{
return F_131 ( V_358 , V_37 , F_96 ( V_176 ) ) ;
}
static int F_219 ( struct V_23 * V_560 , struct V_37 * V_377 ,
struct V_23 * V_561 , struct V_37 * V_379 )
{
return F_134 ( V_560 , V_377 , V_561 , V_379 ) ;
}
static int F_220 ( struct V_37 * V_37 )
{
const struct V_11 * V_11 = F_77 () ;
return F_125 ( V_11 , V_37 , V_392 ) ;
}
static int F_221 ( struct V_37 * V_37 , struct V_23 * V_23 ,
bool V_43 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_337 V_338 ;
struct V_24 * V_25 ;
T_2 V_18 ;
F_123 ( V_11 ) ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_37 ;
V_18 = F_20 ( V_11 ) ;
V_25 = F_34 ( V_23 , V_43 ) ;
if ( F_103 ( V_25 ) )
return F_104 ( V_25 ) ;
return F_222 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_392 , & V_338 ,
V_43 ? V_562 : 0 ) ;
}
static T_9 int F_223 ( struct V_23 * V_23 ,
T_2 V_351 , T_2 V_563 , T_2 V_564 ,
int V_565 ,
unsigned V_87 )
{
struct V_337 V_338 ;
struct V_24 * V_25 = V_23 -> V_36 ;
int V_63 ;
V_338 . type = V_566 ;
V_338 . V_343 . V_23 = V_23 ;
V_63 = F_224 ( F_26 () , V_25 -> V_18 , V_25 -> V_32 , V_351 ,
V_563 , V_564 , V_565 , & V_338 , V_87 ) ;
if ( V_63 )
return V_63 ;
return 0 ;
}
static int F_225 ( struct V_23 * V_23 , int V_388 )
{
const struct V_11 * V_11 = F_77 () ;
T_2 V_351 ;
bool V_567 ;
unsigned V_87 = V_388 & V_562 ;
struct V_24 * V_25 ;
T_2 V_18 ;
struct V_339 V_340 ;
int V_63 , V_350 ;
T_2 V_563 , V_564 ;
V_567 = V_388 & V_568 ;
V_388 &= ( V_391 | V_395 | V_389 | V_393 ) ;
if ( ! V_388 )
return 0 ;
F_123 ( V_11 ) ;
if ( F_124 ( F_66 ( V_23 ) ) )
return 0 ;
V_351 = F_138 ( V_23 -> V_318 , V_388 ) ;
V_18 = F_20 ( V_11 ) ;
V_25 = F_34 ( V_23 , V_87 & V_562 ) ;
if ( F_103 ( V_25 ) )
return F_104 ( V_25 ) ;
V_63 = F_120 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_351 , 0 , & V_340 ) ;
V_563 = F_226 ( V_351 , & V_340 , V_63 ,
V_567 ? V_569 : 0 ,
& V_564 ) ;
if ( F_227 ( ! V_563 ) )
return V_63 ;
V_350 = F_223 ( V_23 , V_351 , V_563 , V_564 , V_63 , V_87 ) ;
if ( V_350 )
return V_350 ;
return V_63 ;
}
static int F_228 ( struct V_37 * V_37 , struct V_570 * V_570 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_23 * V_23 = F_38 ( V_37 ) ;
unsigned int V_571 = V_570 -> V_571 ;
T_10 V_341 = V_396 ;
if ( V_571 & V_572 ) {
V_571 &= ~ ( V_573 | V_574 | V_575 |
V_572 ) ;
if ( ! V_571 )
return 0 ;
}
if ( V_571 & ( V_575 | V_576 | V_577 |
V_578 | V_579 | V_580 ) )
return F_125 ( V_11 , V_37 , V_581 ) ;
if ( V_405 &&
V_23 -> V_48 -> V_406 != V_407 &&
( V_571 & V_582 ) &&
! ( V_571 & V_583 ) )
V_341 |= V_408 ;
return F_125 ( V_11 , V_37 , V_341 ) ;
}
static int F_229 ( const struct V_315 * V_315 )
{
return F_126 ( F_77 () , V_315 , V_584 ) ;
}
static int F_230 ( struct V_37 * V_37 , const char * V_74 )
{
const struct V_11 * V_11 = F_77 () ;
if ( ! strncmp ( V_74 , V_585 ,
sizeof V_585 - 1 ) ) {
if ( ! strcmp ( V_74 , V_586 ) ) {
if ( ! F_231 ( V_587 ) )
return - V_474 ;
} else if ( ! F_231 ( V_462 ) ) {
return - V_474 ;
}
}
return F_125 ( V_11 , V_37 , V_581 ) ;
}
static bool F_232 ( bool V_335 )
{
const struct V_11 * V_11 = F_77 () ;
int V_588 = V_335 ? V_349 : V_463 ;
if ( F_233 ( V_11 , & V_130 , V_589 , V_588 ) )
return false ;
if ( F_117 ( V_11 , V_589 , V_588 , true ) )
return false ;
return true ;
}
static int F_234 ( struct V_37 * V_37 , const char * V_74 ,
const void * V_557 , T_7 V_590 , int V_87 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
struct V_24 * V_25 ;
struct V_46 * V_47 ;
struct V_337 V_338 ;
T_2 V_363 , V_18 = F_26 () ;
int V_63 = 0 ;
if ( strcmp ( V_74 , V_85 ) )
return F_230 ( V_37 , V_74 ) ;
V_47 = V_23 -> V_48 -> V_49 ;
if ( ! ( V_47 -> V_87 & V_89 ) )
return - V_83 ;
if ( ! F_235 ( V_23 ) )
return - V_474 ;
V_338 . type = V_353 ;
V_338 . V_343 . V_37 = V_37 ;
V_25 = F_39 ( V_37 ) ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 ,
V_591 , & V_338 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_236 ( V_557 , V_590 , & V_363 , V_16 ) ;
if ( V_63 == - V_98 ) {
if ( ! F_232 ( true ) ) {
struct V_592 * V_593 ;
T_7 V_594 ;
const char * V_1 ;
if ( V_557 ) {
V_1 = V_557 ;
if ( V_1 [ V_590 - 1 ] == '\0' )
V_594 = V_590 - 1 ;
else
V_594 = V_590 ;
} else {
V_1 = L_44 ;
V_594 = 0 ;
}
V_593 = F_237 ( V_12 -> V_595 , V_103 , V_596 ) ;
F_238 ( V_593 , L_45 ) ;
F_239 ( V_593 , V_557 , V_594 ) ;
F_240 ( V_593 ) ;
return V_63 ;
}
V_63 = F_241 ( V_557 , V_590 , & V_363 ) ;
}
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_18 , V_363 , V_25 -> V_32 ,
V_597 , & V_338 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_242 ( V_25 -> V_18 , V_363 , V_18 ,
V_25 -> V_32 ) ;
if ( V_63 )
return V_63 ;
return F_57 ( V_363 ,
V_47 -> V_18 ,
V_64 ,
V_67 ,
& V_338 ) ;
}
static void F_243 ( struct V_37 * V_37 , const char * V_74 ,
const void * V_557 , T_7 V_590 ,
int V_87 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
struct V_24 * V_25 ;
T_2 V_363 ;
int V_63 ;
if ( strcmp ( V_74 , V_85 ) ) {
return;
}
V_63 = F_241 ( V_557 , V_590 , & V_363 ) ;
if ( V_63 ) {
F_61 ( V_348 L_46
L_47 ,
V_23 -> V_48 -> V_82 , V_23 -> V_321 , - V_63 ) ;
return;
}
V_25 = F_39 ( V_37 ) ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_32 = F_96 ( V_23 -> V_318 ) ;
V_25 -> V_18 = V_363 ;
V_25 -> V_34 = V_41 ;
F_47 ( & V_25 -> V_29 ) ;
return;
}
static int F_244 ( struct V_37 * V_37 , const char * V_74 )
{
const struct V_11 * V_11 = F_77 () ;
return F_125 ( V_11 , V_37 , V_584 ) ;
}
static int F_245 ( struct V_37 * V_37 )
{
const struct V_11 * V_11 = F_77 () ;
return F_125 ( V_11 , V_37 , V_584 ) ;
}
static int F_246 ( struct V_37 * V_37 , const char * V_74 )
{
if ( strcmp ( V_74 , V_85 ) )
return F_230 ( V_37 , V_74 ) ;
return - V_131 ;
}
static int F_247 ( struct V_23 * V_23 , const char * V_74 , void * * V_314 , bool V_598 )
{
T_2 V_590 ;
int error ;
char * V_95 = NULL ;
struct V_24 * V_25 ;
if ( strcmp ( V_74 , V_559 ) )
return - V_83 ;
V_25 = F_36 ( V_23 ) ;
if ( F_232 ( false ) )
error = F_211 ( V_25 -> V_18 , & V_95 ,
& V_590 ) ;
else
error = F_72 ( V_25 -> V_18 , & V_95 , & V_590 ) ;
if ( error )
return error ;
error = V_590 ;
if ( V_598 ) {
* V_314 = V_95 ;
goto V_599;
}
F_54 ( V_95 ) ;
V_599:
return error ;
}
static int F_248 ( struct V_23 * V_23 , const char * V_74 ,
const void * V_557 , T_7 V_590 , int V_87 )
{
struct V_24 * V_25 = F_33 ( V_23 ) ;
T_2 V_363 ;
int V_63 ;
if ( strcmp ( V_74 , V_559 ) )
return - V_83 ;
if ( ! V_557 || ! V_590 )
return - V_131 ;
V_63 = F_236 ( V_557 , V_590 , & V_363 , V_16 ) ;
if ( V_63 )
return V_63 ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_32 = F_96 ( V_23 -> V_318 ) ;
V_25 -> V_18 = V_363 ;
V_25 -> V_34 = V_41 ;
F_47 ( & V_25 -> V_29 ) ;
return 0 ;
}
static int F_249 ( struct V_23 * V_23 , char * V_314 , T_7 V_600 )
{
const int V_96 = sizeof( V_85 ) ;
if ( V_314 && V_96 <= V_600 )
memcpy ( V_314 , V_85 , V_96 ) ;
return V_96 ;
}
static void F_250 ( struct V_23 * V_23 , T_2 * V_601 )
{
struct V_24 * V_25 = F_33 ( V_23 ) ;
* V_601 = V_25 -> V_18 ;
}
static int F_251 ( struct V_37 * V_602 , struct V_11 * * V_138 )
{
T_2 V_18 ;
struct V_14 * V_15 ;
struct V_11 * V_603 = * V_138 ;
if ( V_603 == NULL ) {
V_603 = F_252 () ;
if ( ! V_603 )
return - V_28 ;
}
V_15 = V_603 -> V_20 ;
F_250 ( F_208 ( V_602 ) , & V_18 ) ;
V_15 -> V_361 = V_18 ;
* V_138 = V_603 ;
return 0 ;
}
static int F_253 ( const char * V_74 )
{
if ( strcmp ( V_74 , V_85 ) == 0 )
return 1 ;
return - V_83 ;
}
static int F_254 ( struct V_51 * V_51 , int V_388 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
if ( ( V_51 -> V_402 & V_403 ) && ( V_388 & V_395 ) )
V_388 |= V_393 ;
return F_129 ( V_11 , V_51 ,
F_138 ( V_23 -> V_318 , V_388 ) ) ;
}
static int F_255 ( struct V_51 * V_51 , int V_388 )
{
struct V_23 * V_23 = F_128 ( V_51 ) ;
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_24 * V_25 ;
T_2 V_18 = F_26 () ;
if ( ! V_388 )
return 0 ;
V_25 = F_36 ( V_23 ) ;
if ( V_18 == V_53 -> V_18 && V_53 -> V_604 == V_25 -> V_18 &&
V_53 -> V_605 == F_256 () )
return 0 ;
return F_254 ( V_51 , V_388 ) ;
}
static int F_257 ( struct V_51 * V_51 )
{
return F_49 ( V_51 ) ;
}
static void F_258 ( struct V_51 * V_51 )
{
F_50 ( V_51 ) ;
}
static int F_259 ( const struct V_11 * V_11 , struct V_51 * V_51 ,
T_2 V_606 , T_4 V_607 )
{
struct V_337 V_338 ;
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
struct V_24 * V_25 ;
struct V_608 V_609 ;
T_2 V_610 = F_20 ( V_11 ) ;
int V_63 ;
T_11 V_611 = V_607 >> 8 ;
T_11 V_612 = V_607 & 0xff ;
V_338 . type = V_613 ;
V_338 . V_343 . V_614 = & V_609 ;
V_338 . V_343 . V_614 -> V_607 = V_607 ;
V_338 . V_343 . V_614 -> V_315 = V_51 -> V_421 ;
if ( V_610 != V_53 -> V_18 ) {
V_63 = F_57 ( V_610 , V_53 -> V_18 ,
V_356 ,
V_357 ,
& V_338 ) ;
if ( V_63 )
goto V_84;
}
if ( F_124 ( F_66 ( V_23 ) ) )
return 0 ;
V_25 = F_36 ( V_23 ) ;
V_63 = F_260 ( V_610 , V_25 -> V_18 , V_25 -> V_32 ,
V_606 , V_611 , V_612 , & V_338 ) ;
V_84:
return V_63 ;
}
static int F_261 ( struct V_51 * V_51 , unsigned int V_607 ,
unsigned long V_615 )
{
const struct V_11 * V_11 = F_77 () ;
int error = 0 ;
switch ( V_607 ) {
case V_616 :
case V_617 :
case V_618 :
case V_619 :
case V_620 :
error = F_129 ( V_11 , V_51 , V_584 ) ;
break;
case V_621 :
case V_622 :
error = F_129 ( V_11 , V_51 , V_581 ) ;
break;
case V_623 :
case V_624 :
error = F_129 ( V_11 , V_51 , 0 ) ;
break;
case V_625 :
case V_626 :
error = F_117 ( V_11 , V_627 ,
V_349 , true ) ;
break;
default:
error = F_259 ( V_11 , V_51 , V_404 , ( T_4 ) V_607 ) ;
}
return error ;
}
static int F_262 ( struct V_51 * V_51 , unsigned long V_628 , int V_629 )
{
const struct V_11 * V_11 = F_77 () ;
T_2 V_18 = F_20 ( V_11 ) ;
int V_63 = 0 ;
if ( V_630 &&
( V_628 & V_631 ) && ( ! V_51 || F_66 ( F_128 ( V_51 ) ) ||
( ! V_629 && ( V_628 & V_632 ) ) ) ) {
V_63 = F_57 ( V_18 , V_18 , V_425 ,
V_633 , NULL ) ;
if ( V_63 )
goto error;
}
if ( V_51 ) {
T_2 V_341 = V_392 ;
if ( V_629 && ( V_628 & V_632 ) )
V_341 |= V_396 ;
if ( V_628 & V_631 )
V_341 |= V_390 ;
return F_129 ( V_11 , V_51 , V_341 ) ;
}
error:
return V_63 ;
}
static int F_263 ( unsigned long V_634 )
{
int V_63 = 0 ;
if ( V_634 < V_635 ) {
T_2 V_18 = F_26 () ;
V_63 = F_57 ( V_18 , V_18 , V_636 ,
V_637 , NULL ) ;
}
return V_63 ;
}
static int F_264 ( struct V_51 * V_51 , unsigned long V_638 ,
unsigned long V_628 , unsigned long V_87 )
{
struct V_337 V_338 ;
int V_63 ;
if ( V_51 ) {
V_338 . type = V_355 ;
V_338 . V_343 . V_51 = V_51 ;
V_63 = F_122 ( F_77 () , F_128 ( V_51 ) ,
V_639 , & V_338 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_640 )
V_628 = V_638 ;
return F_262 ( V_51 , V_628 ,
( V_87 & V_641 ) == V_642 ) ;
}
static int F_265 ( struct V_643 * V_644 ,
unsigned long V_638 ,
unsigned long V_628 )
{
const struct V_11 * V_11 = F_77 () ;
T_2 V_18 = F_20 ( V_11 ) ;
if ( V_640 )
V_628 = V_638 ;
if ( V_630 &&
( V_628 & V_631 ) && ! ( V_644 -> V_645 & V_646 ) ) {
int V_63 = 0 ;
if ( V_644 -> V_647 >= V_644 -> V_648 -> V_649 &&
V_644 -> V_650 <= V_644 -> V_648 -> V_651 ) {
V_63 = F_57 ( V_18 , V_18 , V_425 ,
V_652 , NULL ) ;
} else if ( ! V_644 -> V_653 &&
( ( V_644 -> V_647 <= V_644 -> V_648 -> V_654 &&
V_644 -> V_650 >= V_644 -> V_648 -> V_654 ) ||
F_266 ( V_644 ) ) ) {
V_63 = F_57 ( V_18 , V_18 , V_425 ,
V_655 , NULL ) ;
} else if ( V_644 -> V_653 && V_644 -> V_656 ) {
V_63 = F_129 ( V_11 , V_644 -> V_653 , V_657 ) ;
}
if ( V_63 )
return V_63 ;
}
return F_262 ( V_644 -> V_653 , V_628 , V_644 -> V_645 & V_658 ) ;
}
static int F_267 ( struct V_51 * V_51 , unsigned int V_607 )
{
const struct V_11 * V_11 = F_77 () ;
return F_129 ( V_11 , V_51 , V_659 ) ;
}
static int F_268 ( struct V_51 * V_51 , unsigned int V_607 ,
unsigned long V_615 )
{
const struct V_11 * V_11 = F_77 () ;
int V_660 = 0 ;
switch ( V_607 ) {
case V_661 :
if ( ( V_51 -> V_402 & V_403 ) && ! ( V_615 & V_403 ) ) {
V_660 = F_129 ( V_11 , V_51 , V_396 ) ;
break;
}
case V_662 :
case V_663 :
case V_664 :
case V_665 :
case V_666 :
case V_667 :
V_660 = F_129 ( V_11 , V_51 , 0 ) ;
break;
case V_668 :
case V_669 :
case V_670 :
case V_671 :
case V_672 :
case V_673 :
#if V_674 == 32
case V_675 :
case V_676 :
case V_677 :
#endif
V_660 = F_129 ( V_11 , V_51 , V_659 ) ;
break;
}
return V_660 ;
}
static void F_269 ( struct V_51 * V_51 )
{
struct V_52 * V_53 ;
V_53 = V_51 -> V_56 ;
V_53 -> V_55 = F_26 () ;
}
static int F_270 ( struct V_21 * V_678 ,
struct V_679 * V_680 , int V_681 )
{
struct V_51 * V_51 ;
T_2 V_18 = F_21 ( V_678 ) ;
T_2 V_326 ;
struct V_52 * V_53 ;
V_51 = F_41 ( V_680 , struct V_51 , V_682 ) ;
V_53 = V_51 -> V_56 ;
if ( ! V_681 )
V_326 = F_116 ( V_683 ) ;
else
V_326 = F_116 ( V_681 ) ;
return F_57 ( V_53 -> V_55 , V_18 ,
V_425 , V_326 , NULL ) ;
}
static int F_271 ( struct V_51 * V_51 )
{
const struct V_11 * V_11 = F_77 () ;
return F_129 ( V_11 , V_51 , F_140 ( V_51 ) ) ;
}
static int F_272 ( struct V_51 * V_51 , const struct V_11 * V_11 )
{
struct V_52 * V_53 ;
struct V_24 * V_25 ;
V_53 = V_51 -> V_56 ;
V_25 = F_36 ( F_128 ( V_51 ) ) ;
V_53 -> V_604 = V_25 -> V_18 ;
V_53 -> V_605 = F_256 () ;
return F_127 ( V_11 , V_51 , F_141 ( V_51 ) ) ;
}
static int F_273 ( struct V_21 * V_22 ,
unsigned long V_684 )
{
T_2 V_18 = F_26 () ;
return F_57 ( V_18 , V_18 , V_425 , V_685 , NULL ) ;
}
static int F_274 ( struct V_11 * V_11 , T_12 V_686 )
{
struct V_14 * V_15 ;
V_15 = F_18 ( sizeof( struct V_14 ) , V_686 ) ;
if ( ! V_15 )
return - V_28 ;
V_11 -> V_20 = V_15 ;
return 0 ;
}
static void F_275 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_20 ;
F_73 ( V_11 -> V_20 && ( unsigned long ) V_11 -> V_20 < V_316 ) ;
V_11 -> V_20 = ( void * ) 0x7UL ;
F_54 ( V_15 ) ;
}
static int F_276 ( struct V_11 * V_138 , const struct V_11 * V_137 ,
T_12 V_686 )
{
const struct V_14 * V_467 ;
struct V_14 * V_15 ;
V_467 = V_137 -> V_20 ;
V_15 = F_277 ( V_467 , sizeof( struct V_14 ) , V_686 ) ;
if ( ! V_15 )
return - V_28 ;
V_138 -> V_20 = V_15 ;
return 0 ;
}
static void F_278 ( struct V_11 * V_138 , const struct V_11 * V_137 )
{
const struct V_14 * V_467 = V_137 -> V_20 ;
struct V_14 * V_15 = V_138 -> V_20 ;
* V_15 = * V_467 ;
}
static int F_279 ( struct V_11 * V_138 , T_2 V_601 )
{
struct V_14 * V_15 = V_138 -> V_20 ;
T_2 V_18 = F_26 () ;
int V_687 ;
V_687 = F_57 ( V_18 , V_601 ,
V_688 ,
V_689 ,
NULL ) ;
if ( V_687 == 0 ) {
V_15 -> V_18 = V_601 ;
V_15 -> V_361 = 0 ;
V_15 -> V_476 = 0 ;
V_15 -> V_477 = 0 ;
}
return V_687 ;
}
static int F_280 ( struct V_11 * V_138 , struct V_23 * V_23 )
{
struct V_24 * V_25 = F_36 ( V_23 ) ;
struct V_14 * V_15 = V_138 -> V_20 ;
T_2 V_18 = F_26 () ;
int V_687 ;
V_687 = F_57 ( V_18 , V_25 -> V_18 ,
V_688 ,
V_690 ,
NULL ) ;
if ( V_687 == 0 )
V_15 -> V_361 = V_25 -> V_18 ;
return V_687 ;
}
static int F_281 ( char * V_691 )
{
struct V_337 V_338 ;
V_338 . type = V_692 ;
V_338 . V_343 . V_691 = V_691 ;
return F_57 ( F_26 () , V_19 , V_451 ,
V_693 , & V_338 ) ;
}
static int F_282 ( struct V_51 * V_51 )
{
struct V_337 V_338 ;
struct V_24 * V_25 ;
struct V_52 * V_53 ;
T_2 V_18 = F_26 () ;
int V_63 ;
if ( V_51 == NULL )
return F_57 ( V_18 , V_18 , V_451 ,
V_694 , NULL ) ;
V_338 . type = V_355 ;
V_338 . V_343 . V_51 = V_51 ;
V_53 = V_51 -> V_56 ;
if ( V_18 != V_53 -> V_18 ) {
V_63 = F_57 ( V_18 , V_53 -> V_18 , V_356 , V_357 , & V_338 ) ;
if ( V_63 )
return V_63 ;
}
V_25 = F_36 ( F_128 ( V_51 ) ) ;
return F_57 ( V_18 , V_25 -> V_18 , V_451 ,
V_694 , & V_338 ) ;
}
static int F_283 ( struct V_51 * V_51 ,
enum V_695 V_437 )
{
int V_63 = 0 ;
switch ( V_437 ) {
case V_696 :
V_63 = F_282 ( V_51 ) ;
break;
default:
break;
}
return V_63 ;
}
static int F_284 ( struct V_21 * V_153 , T_13 V_697 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_698 , NULL ) ;
}
static int F_285 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_699 , NULL ) ;
}
static int F_286 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_700 , NULL ) ;
}
static void F_287 ( struct V_21 * V_153 , T_2 * V_601 )
{
* V_601 = F_21 ( V_153 ) ;
}
static int F_288 ( struct V_21 * V_153 , int V_701 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_702 , NULL ) ;
}
static int F_289 ( struct V_21 * V_153 , int V_703 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_702 , NULL ) ;
}
static int F_290 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_704 , NULL ) ;
}
int F_291 ( const struct V_11 * V_11 , const struct V_11 * V_705 ,
unsigned int V_87 )
{
T_2 V_341 = 0 ;
if ( ! V_87 )
return 0 ;
if ( V_87 & V_706 )
V_341 |= V_707 ;
if ( V_87 & V_708 )
V_341 |= V_709 ;
return F_57 ( F_20 ( V_11 ) , F_20 ( V_705 ) ,
V_425 , V_341 , NULL ) ;
}
static int F_292 ( struct V_21 * V_153 , unsigned int V_710 ,
struct V_504 * V_711 )
{
struct V_504 * V_712 = V_153 -> signal -> V_505 + V_710 ;
if ( V_712 -> V_512 != V_711 -> V_512 )
return F_57 ( F_26 () , F_21 ( V_153 ) ,
V_425 , V_707 , NULL ) ;
return 0 ;
}
static int F_293 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_702 , NULL ) ;
}
static int F_294 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_704 , NULL ) ;
}
static int F_295 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_425 ,
V_702 , NULL ) ;
}
static int F_296 ( struct V_21 * V_153 , struct V_713 * V_714 ,
int V_325 , T_2 V_601 )
{
T_2 V_326 ;
if ( ! V_325 )
V_326 = V_715 ;
else
V_326 = F_116 ( V_325 ) ;
if ( ! V_601 )
V_601 = F_26 () ;
return F_57 ( V_601 , F_21 ( V_153 ) , V_425 , V_326 , NULL ) ;
}
static void F_297 ( struct V_21 * V_153 ,
struct V_23 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_36 ;
T_2 V_18 = F_21 ( V_153 ) ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_32 = F_96 ( V_23 -> V_318 ) ;
V_25 -> V_18 = V_18 ;
V_25 -> V_34 = V_41 ;
F_47 ( & V_25 -> V_29 ) ;
}
static int F_298 ( struct V_716 * V_717 ,
struct V_337 * V_338 , T_11 * V_718 )
{
int V_719 , V_720 , V_687 = - V_98 ;
struct V_721 V_722 , * V_723 ;
V_719 = F_299 ( V_717 ) ;
V_723 = F_300 ( V_717 , V_719 , sizeof( V_722 ) , & V_722 ) ;
if ( V_723 == NULL )
goto V_84;
V_720 = V_723 -> V_724 * 4 ;
if ( V_720 < sizeof( V_722 ) )
goto V_84;
V_338 -> V_343 . V_725 -> V_726 . V_727 = V_723 -> V_727 ;
V_338 -> V_343 . V_725 -> V_726 . V_728 = V_723 -> V_728 ;
V_687 = 0 ;
if ( V_718 )
* V_718 = V_723 -> V_191 ;
switch ( V_723 -> V_191 ) {
case V_193 : {
struct V_729 V_730 , * V_731 ;
if ( F_301 ( V_723 -> V_732 ) & V_733 )
break;
V_719 += V_720 ;
V_731 = F_300 ( V_717 , V_719 , sizeof( V_730 ) , & V_730 ) ;
if ( V_731 == NULL )
break;
V_338 -> V_343 . V_725 -> V_734 = V_731 -> V_735 ;
V_338 -> V_343 . V_725 -> V_736 = V_731 -> V_737 ;
break;
}
case V_194 : {
struct V_738 V_739 , * V_740 ;
if ( F_301 ( V_723 -> V_732 ) & V_733 )
break;
V_719 += V_720 ;
V_740 = F_300 ( V_717 , V_719 , sizeof( V_739 ) , & V_739 ) ;
if ( V_740 == NULL )
break;
V_338 -> V_343 . V_725 -> V_734 = V_740 -> V_735 ;
V_338 -> V_343 . V_725 -> V_736 = V_740 -> V_737 ;
break;
}
case V_741 : {
struct V_742 V_743 , * V_744 ;
if ( F_301 ( V_723 -> V_732 ) & V_733 )
break;
V_719 += V_720 ;
V_744 = F_300 ( V_717 , V_719 , sizeof( V_743 ) , & V_743 ) ;
if ( V_744 == NULL )
break;
V_338 -> V_343 . V_725 -> V_734 = V_744 -> V_745 ;
V_338 -> V_343 . V_725 -> V_736 = V_744 -> V_746 ;
break;
}
default:
break;
}
V_84:
return V_687 ;
}
static int F_302 ( struct V_716 * V_717 ,
struct V_337 * V_338 , T_11 * V_718 )
{
T_11 V_747 ;
int V_687 = - V_98 , V_719 ;
struct V_748 V_749 , * V_750 ;
T_14 V_732 ;
V_719 = F_299 ( V_717 ) ;
V_750 = F_300 ( V_717 , V_719 , sizeof( V_749 ) , & V_749 ) ;
if ( V_750 == NULL )
goto V_84;
V_338 -> V_343 . V_725 -> V_751 . V_727 = V_750 -> V_727 ;
V_338 -> V_343 . V_725 -> V_751 . V_728 = V_750 -> V_728 ;
V_687 = 0 ;
V_747 = V_750 -> V_747 ;
V_719 += sizeof( V_749 ) ;
V_719 = F_303 ( V_717 , V_719 , & V_747 , & V_732 ) ;
if ( V_719 < 0 )
goto V_84;
if ( V_718 )
* V_718 = V_747 ;
switch ( V_747 ) {
case V_193 : {
struct V_729 V_730 , * V_731 ;
V_731 = F_300 ( V_717 , V_719 , sizeof( V_730 ) , & V_730 ) ;
if ( V_731 == NULL )
break;
V_338 -> V_343 . V_725 -> V_734 = V_731 -> V_735 ;
V_338 -> V_343 . V_725 -> V_736 = V_731 -> V_737 ;
break;
}
case V_194 : {
struct V_738 V_739 , * V_740 ;
V_740 = F_300 ( V_717 , V_719 , sizeof( V_739 ) , & V_739 ) ;
if ( V_740 == NULL )
break;
V_338 -> V_343 . V_725 -> V_734 = V_740 -> V_735 ;
V_338 -> V_343 . V_725 -> V_736 = V_740 -> V_737 ;
break;
}
case V_741 : {
struct V_742 V_743 , * V_744 ;
V_744 = F_300 ( V_717 , V_719 , sizeof( V_743 ) , & V_743 ) ;
if ( V_744 == NULL )
break;
V_338 -> V_343 . V_725 -> V_734 = V_744 -> V_745 ;
V_338 -> V_343 . V_725 -> V_736 = V_744 -> V_746 ;
break;
}
default:
break;
}
V_84:
return V_687 ;
}
static int F_304 ( struct V_716 * V_717 , struct V_337 * V_338 ,
char * * V_752 , int V_602 , T_11 * V_718 )
{
char * V_753 ;
int V_687 ;
switch ( V_338 -> V_343 . V_725 -> V_195 ) {
case V_204 :
V_687 = F_298 ( V_717 , V_338 , V_718 ) ;
if ( V_687 )
goto V_754;
V_753 = ( char * ) ( V_602 ? & V_338 -> V_343 . V_725 -> V_726 . V_727 :
& V_338 -> V_343 . V_725 -> V_726 . V_728 ) ;
goto V_755;
#if F_176 ( V_756 )
case V_205 :
V_687 = F_302 ( V_717 , V_338 , V_718 ) ;
if ( V_687 )
goto V_754;
V_753 = ( char * ) ( V_602 ? & V_338 -> V_343 . V_725 -> V_751 . V_727 :
& V_338 -> V_343 . V_725 -> V_751 . V_728 ) ;
goto V_755;
#endif
default:
V_753 = NULL ;
goto V_755;
}
V_754:
F_61 ( V_81
L_48
L_49 ) ;
return V_687 ;
V_755:
if ( V_752 )
* V_752 = V_753 ;
return 0 ;
}
static int F_305 ( struct V_716 * V_717 , T_4 V_195 , T_2 * V_18 )
{
int V_660 ;
T_2 V_757 ;
T_2 V_758 ;
T_2 V_759 ;
V_660 = F_306 ( V_717 , & V_757 ) ;
if ( F_124 ( V_660 ) )
return - V_131 ;
V_660 = F_307 ( V_717 , V_195 , & V_759 , & V_758 ) ;
if ( F_124 ( V_660 ) )
return - V_131 ;
V_660 = F_308 ( V_758 , V_759 , V_757 , V_18 ) ;
if ( F_124 ( V_660 ) ) {
F_61 ( V_81
L_50
L_51 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_309 ( T_2 V_760 , T_2 V_761 , T_2 * V_762 )
{
int V_660 = 0 ;
if ( V_761 != V_763 )
V_660 = F_310 ( V_760 , V_761 , V_762 ) ;
else
* V_762 = V_760 ;
return V_660 ;
}
static int F_311 ( const struct V_14 * V_15 ,
T_4 V_764 , T_2 * V_765 )
{
if ( V_15 -> V_477 > V_763 ) {
* V_765 = V_15 -> V_477 ;
return 0 ;
}
return F_81 ( V_15 -> V_18 , V_15 -> V_18 , V_764 , NULL ,
V_765 ) ;
}
static int F_312 ( struct V_766 * V_767 , T_2 V_351 )
{
struct V_768 * V_769 = V_767 -> V_770 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
if ( V_769 -> V_18 == V_19 )
return 0 ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_767 = V_767 ;
return F_57 ( F_26 () , V_769 -> V_18 , V_769 -> V_32 , V_351 ,
& V_338 ) ;
}
static int F_313 ( int V_195 , int type ,
int V_191 , int V_773 )
{
const struct V_14 * V_15 = F_132 () ;
T_2 V_363 ;
T_4 V_764 ;
int V_63 ;
if ( V_773 )
return 0 ;
V_764 = F_99 ( V_195 , type , V_191 ) ;
V_63 = F_311 ( V_15 , V_764 , & V_363 ) ;
if ( V_63 )
return V_63 ;
return F_57 ( V_15 -> V_18 , V_363 , V_764 , V_774 , NULL ) ;
}
static int F_314 ( struct V_775 * V_766 , int V_195 ,
int type , int V_191 , int V_773 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_24 * V_25 = F_33 ( F_315 ( V_766 ) ) ;
struct V_768 * V_769 ;
T_4 V_32 = F_99 ( V_195 , type , V_191 ) ;
T_2 V_18 = V_19 ;
int V_660 = 0 ;
if ( ! V_773 ) {
V_660 = F_311 ( V_15 , V_32 , & V_18 ) ;
if ( V_660 )
return V_660 ;
}
V_25 -> V_32 = V_32 ;
V_25 -> V_18 = V_18 ;
V_25 -> V_34 = V_41 ;
if ( V_766 -> V_767 ) {
V_769 = V_766 -> V_767 -> V_770 ;
V_769 -> V_32 = V_32 ;
V_769 -> V_18 = V_18 ;
V_660 = F_316 ( V_766 -> V_767 , V_195 ) ;
}
return V_660 ;
}
static int F_317 ( struct V_775 * V_766 , struct V_776 * V_777 , int V_778 )
{
struct V_766 * V_767 = V_766 -> V_767 ;
T_4 V_195 ;
int V_660 ;
V_660 = F_312 ( V_767 , V_779 ) ;
if ( V_660 )
goto V_84;
V_195 = V_767 -> V_780 ;
if ( V_195 == V_204 || V_195 == V_205 ) {
char * V_753 ;
struct V_768 * V_769 = V_767 -> V_770 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
struct V_781 * V_782 = NULL ;
struct V_783 * V_784 = NULL ;
unsigned short V_785 ;
T_2 V_18 , V_786 ;
if ( V_195 == V_204 ) {
if ( V_778 < sizeof( struct V_781 ) ) {
V_660 = - V_98 ;
goto V_84;
}
V_782 = (struct V_781 * ) V_777 ;
V_785 = F_301 ( V_782 -> V_787 ) ;
V_753 = ( char * ) & V_782 -> V_788 . V_789 ;
} else {
if ( V_778 < V_790 ) {
V_660 = - V_98 ;
goto V_84;
}
V_784 = (struct V_783 * ) V_777 ;
V_785 = F_301 ( V_784 -> V_791 ) ;
V_753 = ( char * ) & V_784 -> V_792 . V_793 ;
}
if ( V_785 ) {
int V_794 , V_795 ;
F_318 ( F_319 ( V_767 ) , & V_794 , & V_795 ) ;
if ( V_785 < V_796 ( V_797 ( F_319 ( V_767 ) ), V_794 ) ||
V_785 > V_795 ) {
V_660 = F_320 ( V_767 -> V_798 ,
V_785 , & V_18 ) ;
if ( V_660 )
goto V_84;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_734 = F_321 ( V_785 ) ;
V_338 . V_343 . V_725 -> V_195 = V_195 ;
V_660 = F_57 ( V_769 -> V_18 , V_18 ,
V_769 -> V_32 ,
V_799 , & V_338 ) ;
if ( V_660 )
goto V_84;
}
}
switch ( V_769 -> V_32 ) {
case V_206 :
V_786 = V_800 ;
break;
case V_210 :
V_786 = V_801 ;
break;
case V_215 :
V_786 = V_802 ;
break;
default:
V_786 = V_803 ;
break;
}
V_660 = F_322 ( V_753 , V_195 , & V_18 ) ;
if ( V_660 )
goto V_84;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_734 = F_321 ( V_785 ) ;
V_338 . V_343 . V_725 -> V_195 = V_195 ;
if ( V_195 == V_204 )
V_338 . V_343 . V_725 -> V_726 . V_727 = V_782 -> V_788 . V_789 ;
else
V_338 . V_343 . V_725 -> V_751 . V_727 = V_784 -> V_792 ;
V_660 = F_57 ( V_769 -> V_18 , V_18 ,
V_769 -> V_32 , V_786 , & V_338 ) ;
if ( V_660 )
goto V_84;
}
V_84:
return V_660 ;
}
static int F_323 ( struct V_775 * V_766 , struct V_776 * V_777 , int V_778 )
{
struct V_766 * V_767 = V_766 -> V_767 ;
struct V_768 * V_769 = V_767 -> V_770 ;
int V_660 ;
V_660 = F_312 ( V_767 , V_804 ) ;
if ( V_660 )
return V_660 ;
if ( V_769 -> V_32 == V_206 ||
V_769 -> V_32 == V_215 ) {
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
struct V_781 * V_782 = NULL ;
struct V_783 * V_784 = NULL ;
unsigned short V_785 ;
T_2 V_18 , V_326 ;
if ( V_767 -> V_780 == V_204 ) {
V_782 = (struct V_781 * ) V_777 ;
if ( V_778 < sizeof( struct V_781 ) )
return - V_98 ;
V_785 = F_301 ( V_782 -> V_787 ) ;
} else {
V_784 = (struct V_783 * ) V_777 ;
if ( V_778 < V_790 )
return - V_98 ;
V_785 = F_301 ( V_784 -> V_791 ) ;
}
V_660 = F_320 ( V_767 -> V_798 , V_785 , & V_18 ) ;
if ( V_660 )
goto V_84;
V_326 = ( V_769 -> V_32 == V_206 ) ?
V_805 : V_806 ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_736 = F_321 ( V_785 ) ;
V_338 . V_343 . V_725 -> V_195 = V_767 -> V_780 ;
V_660 = F_57 ( V_769 -> V_18 , V_18 , V_769 -> V_32 , V_326 , & V_338 ) ;
if ( V_660 )
goto V_84;
}
V_660 = F_324 ( V_767 , V_777 ) ;
V_84:
return V_660 ;
}
static int F_325 ( struct V_775 * V_766 , int V_807 )
{
return F_312 ( V_766 -> V_767 , V_808 ) ;
}
static int F_326 ( struct V_775 * V_766 , struct V_775 * V_809 )
{
int V_660 ;
struct V_24 * V_25 ;
struct V_24 * V_150 ;
T_4 V_32 ;
T_2 V_18 ;
V_660 = F_312 ( V_766 -> V_767 , V_810 ) ;
if ( V_660 )
return V_660 ;
V_25 = F_33 ( F_315 ( V_766 ) ) ;
F_45 ( & V_25 -> V_29 ) ;
V_32 = V_25 -> V_32 ;
V_18 = V_25 -> V_18 ;
F_47 ( & V_25 -> V_29 ) ;
V_150 = F_33 ( F_315 ( V_809 ) ) ;
V_150 -> V_32 = V_32 ;
V_150 -> V_18 = V_18 ;
V_150 -> V_34 = V_41 ;
return 0 ;
}
static int F_327 ( struct V_775 * V_766 , struct V_811 * V_812 ,
int V_590 )
{
return F_312 ( V_766 -> V_767 , V_813 ) ;
}
static int F_328 ( struct V_775 * V_766 , struct V_811 * V_812 ,
int V_590 , int V_87 )
{
return F_312 ( V_766 -> V_767 , V_814 ) ;
}
static int F_329 ( struct V_775 * V_766 )
{
return F_312 ( V_766 -> V_767 , V_815 ) ;
}
static int F_330 ( struct V_775 * V_766 )
{
return F_312 ( V_766 -> V_767 , V_815 ) ;
}
static int F_331 ( struct V_775 * V_766 , int V_816 , int V_817 )
{
int V_660 ;
V_660 = F_312 ( V_766 -> V_767 , V_818 ) ;
if ( V_660 )
return V_660 ;
return F_332 ( V_766 , V_816 , V_817 ) ;
}
static int F_333 ( struct V_775 * V_766 , int V_816 ,
int V_817 )
{
return F_312 ( V_766 -> V_767 , V_819 ) ;
}
static int F_334 ( struct V_775 * V_766 , int V_820 )
{
return F_312 ( V_766 -> V_767 , V_821 ) ;
}
static int F_335 ( struct V_766 * V_766 ,
struct V_766 * V_822 ,
struct V_766 * V_823 )
{
struct V_768 * V_824 = V_766 -> V_770 ;
struct V_768 * V_825 = V_822 -> V_770 ;
struct V_768 * V_826 = V_823 -> V_770 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
int V_660 ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_767 = V_822 ;
V_660 = F_57 ( V_824 -> V_18 , V_825 -> V_18 ,
V_825 -> V_32 ,
V_827 , & V_338 ) ;
if ( V_660 )
return V_660 ;
V_826 -> V_828 = V_824 -> V_18 ;
V_660 = F_310 ( V_825 -> V_18 , V_824 -> V_18 ,
& V_826 -> V_18 ) ;
if ( V_660 )
return V_660 ;
V_824 -> V_828 = V_826 -> V_18 ;
return 0 ;
}
static int F_336 ( struct V_775 * V_766 ,
struct V_775 * V_822 )
{
struct V_768 * V_829 = V_766 -> V_767 -> V_770 ;
struct V_768 * V_830 = V_822 -> V_767 -> V_770 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_767 = V_822 -> V_767 ;
return F_57 ( V_829 -> V_18 , V_830 -> V_18 , V_830 -> V_32 , V_831 ,
& V_338 ) ;
}
static int F_337 ( struct V_725 * V_435 , int V_832 ,
char * V_753 , T_4 V_195 , T_2 V_828 ,
struct V_337 * V_338 )
{
int V_660 ;
T_2 V_833 ;
T_2 V_834 ;
V_660 = F_338 ( V_435 , V_832 , & V_833 ) ;
if ( V_660 )
return V_660 ;
V_660 = F_57 ( V_828 , V_833 ,
V_835 , V_836 , V_338 ) ;
if ( V_660 )
return V_660 ;
V_660 = F_322 ( V_753 , V_195 , & V_834 ) ;
if ( V_660 )
return V_660 ;
return F_57 ( V_828 , V_834 ,
V_837 , V_838 , V_338 ) ;
}
static int F_339 ( struct V_766 * V_767 , struct V_716 * V_717 ,
T_4 V_195 )
{
int V_660 = 0 ;
struct V_768 * V_769 = V_767 -> V_770 ;
T_2 V_760 = V_769 -> V_18 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
char * V_753 ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_839 = V_717 -> V_840 ;
V_338 . V_343 . V_725 -> V_195 = V_195 ;
V_660 = F_304 ( V_717 , & V_338 , & V_753 , 1 , NULL ) ;
if ( V_660 )
return V_660 ;
if ( F_4 () ) {
V_660 = F_57 ( V_760 , V_717 -> V_841 , V_842 ,
V_843 , & V_338 ) ;
if ( V_660 )
return V_660 ;
}
V_660 = F_340 ( V_769 , V_717 , V_195 , & V_338 ) ;
if ( V_660 )
return V_660 ;
V_660 = F_341 ( V_769 -> V_18 , V_717 , & V_338 ) ;
return V_660 ;
}
static int F_342 ( struct V_766 * V_767 , struct V_716 * V_717 )
{
int V_660 ;
struct V_768 * V_769 = V_767 -> V_770 ;
T_4 V_195 = V_767 -> V_780 ;
T_2 V_760 = V_769 -> V_18 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
char * V_753 ;
T_11 V_844 ;
T_11 V_845 ;
if ( V_195 != V_204 && V_195 != V_205 )
return 0 ;
if ( V_195 == V_205 && V_717 -> V_191 == F_321 ( V_846 ) )
V_195 = V_204 ;
if ( ! V_847 )
return F_339 ( V_767 , V_717 , V_195 ) ;
V_844 = F_4 () ;
V_845 = F_6 () ;
if ( ! V_844 && ! V_845 )
return 0 ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_839 = V_717 -> V_840 ;
V_338 . V_343 . V_725 -> V_195 = V_195 ;
V_660 = F_304 ( V_717 , & V_338 , & V_753 , 1 , NULL ) ;
if ( V_660 )
return V_660 ;
if ( V_845 ) {
T_2 V_828 ;
V_660 = F_305 ( V_717 , V_195 , & V_828 ) ;
if ( V_660 )
return V_660 ;
V_660 = F_337 ( F_319 ( V_767 ) , V_717 -> V_840 ,
V_753 , V_195 , V_828 , & V_338 ) ;
if ( V_660 ) {
F_343 ( V_717 , V_195 , V_660 , 0 ) ;
return V_660 ;
}
V_660 = F_57 ( V_760 , V_828 , V_848 ,
V_849 , & V_338 ) ;
if ( V_660 ) {
F_343 ( V_717 , V_195 , V_660 , 0 ) ;
return V_660 ;
}
}
if ( V_844 ) {
V_660 = F_57 ( V_760 , V_717 -> V_841 , V_842 ,
V_843 , & V_338 ) ;
if ( V_660 )
return V_660 ;
}
return V_660 ;
}
static int F_344 ( struct V_775 * V_766 , char T_15 * V_850 ,
int T_15 * V_851 , unsigned V_96 )
{
int V_660 = 0 ;
char * V_852 ;
T_2 V_853 ;
struct V_768 * V_769 = V_766 -> V_767 -> V_770 ;
T_2 V_828 = V_763 ;
if ( V_769 -> V_32 == V_201 ||
V_769 -> V_32 == V_206 )
V_828 = V_769 -> V_828 ;
if ( V_828 == V_763 )
return - V_854 ;
V_660 = F_72 ( V_828 , & V_852 , & V_853 ) ;
if ( V_660 )
return V_660 ;
if ( V_853 > V_96 ) {
V_660 = - V_320 ;
goto V_855;
}
if ( F_345 ( V_850 , V_852 , V_853 ) )
V_660 = - V_856 ;
V_855:
if ( F_346 ( V_853 , V_851 ) )
V_660 = - V_856 ;
F_54 ( V_852 ) ;
return V_660 ;
}
static int F_347 ( struct V_775 * V_766 , struct V_716 * V_717 , T_2 * V_601 )
{
T_2 V_857 = V_763 ;
T_4 V_195 ;
struct V_24 * V_25 ;
if ( V_717 && V_717 -> V_191 == F_321 ( V_846 ) )
V_195 = V_204 ;
else if ( V_717 && V_717 -> V_191 == F_321 ( V_858 ) )
V_195 = V_205 ;
else if ( V_766 )
V_195 = V_766 -> V_767 -> V_780 ;
else
goto V_84;
if ( V_766 && V_195 == V_198 ) {
V_25 = F_33 ( F_315 ( V_766 ) ) ;
V_857 = V_25 -> V_18 ;
} else if ( V_717 )
F_305 ( V_717 , V_195 , & V_857 ) ;
V_84:
* V_601 = V_857 ;
if ( V_857 == V_763 )
return - V_98 ;
return 0 ;
}
static int F_348 ( struct V_766 * V_767 , int V_195 , T_12 V_859 )
{
struct V_768 * V_769 ;
V_769 = F_18 ( sizeof( * V_769 ) , V_859 ) ;
if ( ! V_769 )
return - V_28 ;
V_769 -> V_828 = V_31 ;
V_769 -> V_18 = V_31 ;
V_769 -> V_32 = V_311 ;
F_349 ( V_769 ) ;
V_767 -> V_770 = V_769 ;
return 0 ;
}
static void F_350 ( struct V_766 * V_767 )
{
struct V_768 * V_769 = V_767 -> V_770 ;
V_767 -> V_770 = NULL ;
F_351 ( V_769 ) ;
F_54 ( V_769 ) ;
}
static void F_352 ( const struct V_766 * V_767 , struct V_766 * V_823 )
{
struct V_768 * V_769 = V_767 -> V_770 ;
struct V_768 * V_860 = V_823 -> V_770 ;
V_860 -> V_18 = V_769 -> V_18 ;
V_860 -> V_828 = V_769 -> V_828 ;
V_860 -> V_32 = V_769 -> V_32 ;
F_349 ( V_860 ) ;
}
static void F_353 ( struct V_766 * V_767 , T_2 * V_601 )
{
if ( ! V_767 )
* V_601 = V_861 ;
else {
struct V_768 * V_769 = V_767 -> V_770 ;
* V_601 = V_769 -> V_18 ;
}
}
static void F_354 ( struct V_766 * V_767 , struct V_775 * V_427 )
{
struct V_24 * V_25 =
F_33 ( F_315 ( V_427 ) ) ;
struct V_768 * V_769 = V_767 -> V_770 ;
if ( V_767 -> V_780 == V_204 || V_767 -> V_780 == V_205 ||
V_767 -> V_780 == V_198 )
V_25 -> V_18 = V_769 -> V_18 ;
V_769 -> V_32 = V_25 -> V_32 ;
}
static int F_355 ( struct V_766 * V_767 , struct V_716 * V_717 ,
struct V_862 * V_863 )
{
struct V_768 * V_769 = V_767 -> V_770 ;
int V_660 ;
T_4 V_195 = V_863 -> V_864 -> V_195 ;
T_2 V_865 ;
T_2 V_866 ;
V_660 = F_305 ( V_717 , V_195 , & V_866 ) ;
if ( V_660 )
return V_660 ;
V_660 = F_309 ( V_769 -> V_18 , V_866 , & V_865 ) ;
if ( V_660 )
return V_660 ;
V_863 -> V_601 = V_865 ;
V_863 -> V_857 = V_866 ;
return F_356 ( V_863 , V_195 ) ;
}
static void F_357 ( struct V_766 * V_823 ,
const struct V_862 * V_863 )
{
struct V_768 * V_860 = V_823 -> V_770 ;
V_860 -> V_18 = V_863 -> V_601 ;
V_860 -> V_828 = V_863 -> V_857 ;
F_358 ( V_823 , V_863 -> V_864 -> V_195 ) ;
}
static void F_359 ( struct V_766 * V_767 , struct V_716 * V_717 )
{
T_4 V_195 = V_767 -> V_780 ;
struct V_768 * V_769 = V_767 -> V_770 ;
if ( V_195 == V_205 && V_717 -> V_191 == F_321 ( V_846 ) )
V_195 = V_204 ;
F_305 ( V_717 , V_195 , & V_769 -> V_828 ) ;
}
static int F_360 ( T_2 V_18 )
{
const struct V_14 * V_867 ;
T_2 V_868 ;
V_867 = F_132 () ;
V_868 = V_867 -> V_18 ;
return F_57 ( V_868 , V_18 , V_842 , V_869 , NULL ) ;
}
static void F_361 ( void )
{
F_362 ( & V_7 ) ;
}
static void F_363 ( void )
{
F_364 ( & V_7 ) ;
}
static void F_365 ( const struct V_862 * V_863 ,
struct V_870 * V_871 )
{
V_871 -> V_872 = V_863 -> V_601 ;
}
static int F_366 ( void * * V_20 )
{
struct V_873 * V_874 ;
V_874 = F_18 ( sizeof( * V_874 ) , V_16 ) ;
if ( ! V_874 )
return - V_28 ;
V_874 -> V_18 = F_26 () ;
* V_20 = V_874 ;
return 0 ;
}
static void F_367 ( void * V_20 )
{
F_54 ( V_20 ) ;
}
static int F_368 ( void )
{
T_2 V_18 = F_26 () ;
return F_57 ( V_18 , V_18 , V_875 , V_876 ,
NULL ) ;
}
static int F_369 ( void * V_20 )
{
struct V_873 * V_874 = V_20 ;
return F_57 ( F_26 () , V_874 -> V_18 , V_875 ,
V_877 , NULL ) ;
}
static int F_370 ( struct V_766 * V_767 , void * V_20 )
{
struct V_873 * V_874 = V_20 ;
struct V_768 * V_769 = V_767 -> V_770 ;
V_769 -> V_18 = V_874 -> V_18 ;
V_769 -> V_32 = V_875 ;
return 0 ;
}
static int F_371 ( void * V_20 )
{
struct V_873 * V_874 = V_20 ;
T_2 V_18 = F_26 () ;
int V_660 ;
V_660 = F_57 ( V_18 , V_874 -> V_18 , V_875 ,
V_878 , NULL ) ;
if ( V_660 )
return V_660 ;
V_660 = F_57 ( V_18 , V_18 , V_875 ,
V_879 , NULL ) ;
if ( V_660 )
return V_660 ;
V_874 -> V_18 = V_18 ;
return 0 ;
}
static int F_372 ( struct V_766 * V_767 , struct V_716 * V_717 )
{
int V_660 = 0 ;
T_2 V_326 ;
struct V_880 * V_881 ;
struct V_768 * V_769 = V_767 -> V_770 ;
if ( V_717 -> V_96 < V_882 ) {
V_660 = - V_98 ;
goto V_84;
}
V_881 = F_373 ( V_717 ) ;
V_660 = F_374 ( V_769 -> V_32 , V_881 -> V_883 , & V_326 ) ;
if ( V_660 ) {
if ( V_660 == - V_98 ) {
F_375 ( L_52
L_53
L_54 ,
V_767 -> V_798 , V_881 -> V_883 ,
V_884 [ V_769 -> V_32 - 1 ] . V_74 ,
F_376 ( V_12 ) , V_12 -> V_885 ) ;
if ( ! V_3 || F_377 () )
V_660 = 0 ;
}
if ( V_660 == - V_886 )
V_660 = 0 ;
goto V_84;
}
V_660 = F_312 ( V_767 , V_326 ) ;
V_84:
return V_660 ;
}
static unsigned int F_378 ( struct V_716 * V_717 ,
const struct V_887 * V_888 ,
T_4 V_195 )
{
int V_660 ;
char * V_753 ;
T_2 V_828 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
T_11 V_844 ;
T_11 V_889 ;
T_11 V_845 ;
if ( ! V_847 )
return V_890 ;
V_844 = F_4 () ;
V_889 = F_7 () ;
V_845 = F_6 () ;
if ( ! V_844 && ! V_845 )
return V_890 ;
if ( F_305 ( V_717 , V_195 , & V_828 ) != 0 )
return V_891 ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_839 = V_888 -> V_832 ;
V_338 . V_343 . V_725 -> V_195 = V_195 ;
if ( F_304 ( V_717 , & V_338 , & V_753 , 1 , NULL ) != 0 )
return V_891 ;
if ( V_845 ) {
V_660 = F_337 ( F_379 ( V_888 ) , V_888 -> V_832 ,
V_753 , V_195 , V_828 , & V_338 ) ;
if ( V_660 ) {
F_343 ( V_717 , V_195 , V_660 , 1 ) ;
return V_891 ;
}
}
if ( V_844 )
if ( F_57 ( V_828 , V_717 -> V_841 ,
V_842 , V_892 , & V_338 ) )
return V_891 ;
if ( V_889 )
if ( F_380 ( V_717 , V_195 , V_828 ) != 0 )
return V_891 ;
return V_890 ;
}
static unsigned int F_381 ( void * V_893 ,
struct V_716 * V_717 ,
const struct V_894 * V_895 )
{
return F_378 ( V_717 , V_895 -> V_896 , V_204 ) ;
}
static unsigned int F_382 ( void * V_893 ,
struct V_716 * V_717 ,
const struct V_894 * V_895 )
{
return F_378 ( V_717 , V_895 -> V_896 , V_205 ) ;
}
static unsigned int F_383 ( struct V_716 * V_717 ,
T_4 V_195 )
{
struct V_766 * V_767 ;
T_2 V_18 ;
if ( ! F_7 () )
return V_890 ;
V_767 = V_717 -> V_767 ;
if ( V_767 ) {
struct V_768 * V_769 ;
if ( F_384 ( V_767 ) )
return V_890 ;
V_769 = V_767 -> V_770 ;
V_18 = V_769 -> V_18 ;
} else
V_18 = V_19 ;
if ( F_380 ( V_717 , V_195 , V_18 ) != 0 )
return V_891 ;
return V_890 ;
}
static unsigned int F_385 ( void * V_893 ,
struct V_716 * V_717 ,
const struct V_894 * V_895 )
{
return F_383 ( V_717 , V_204 ) ;
}
static unsigned int F_386 ( void * V_893 ,
struct V_716 * V_717 ,
const struct V_894 * V_895 )
{
return F_383 ( V_717 , V_205 ) ;
}
static unsigned int F_387 ( struct V_716 * V_717 ,
int V_832 ,
T_4 V_195 )
{
struct V_766 * V_767 = F_388 ( V_717 ) ;
struct V_768 * V_769 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
char * V_753 ;
T_11 V_718 ;
if ( V_767 == NULL )
return V_890 ;
V_769 = V_767 -> V_770 ;
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_839 = V_832 ;
V_338 . V_343 . V_725 -> V_195 = V_195 ;
if ( F_304 ( V_717 , & V_338 , & V_753 , 0 , & V_718 ) )
return V_891 ;
if ( F_4 () )
if ( F_57 ( V_769 -> V_18 , V_717 -> V_841 ,
V_842 , V_897 , & V_338 ) )
return F_389 ( - V_898 ) ;
if ( F_390 ( V_769 -> V_18 , V_717 , & V_338 , V_718 ) )
return F_389 ( - V_898 ) ;
return V_890 ;
}
static unsigned int F_391 ( struct V_716 * V_717 ,
const struct V_887 * V_899 ,
T_4 V_195 )
{
T_2 V_900 ;
T_2 V_828 ;
int V_832 = V_899 -> V_832 ;
struct V_766 * V_767 ;
struct V_337 V_338 ;
struct V_771 V_725 = { 0 ,} ;
char * V_753 ;
T_11 V_844 ;
T_11 V_845 ;
if ( ! V_847 )
return F_387 ( V_717 , V_832 , V_195 ) ;
V_844 = F_4 () ;
V_845 = F_6 () ;
if ( ! V_844 && ! V_845 )
return V_890 ;
V_767 = F_388 ( V_717 ) ;
#ifdef F_392
if ( F_393 ( V_717 ) != NULL && F_393 ( V_717 ) -> V_901 != NULL &&
! ( V_767 && F_384 ( V_767 ) ) )
return V_890 ;
#endif
if ( V_767 == NULL ) {
if ( V_717 -> V_840 ) {
V_900 = V_902 ;
if ( F_305 ( V_717 , V_195 , & V_828 ) )
return V_891 ;
} else {
V_900 = V_897 ;
V_828 = V_19 ;
}
} else if ( F_384 ( V_767 ) ) {
T_2 V_761 ;
struct V_768 * V_769 ;
V_769 = V_767 -> V_770 ;
if ( F_305 ( V_717 , V_195 , & V_761 ) )
return V_891 ;
if ( V_761 == V_763 ) {
switch ( V_195 ) {
case V_204 :
if ( F_394 ( V_717 ) -> V_87 & V_903 )
return V_890 ;
break;
case V_205 :
if ( F_395 ( V_717 ) -> V_87 & V_904 )
return V_890 ;
break;
default:
return F_389 ( - V_898 ) ;
}
}
if ( F_309 ( V_769 -> V_18 , V_761 , & V_828 ) )
return V_891 ;
V_900 = V_897 ;
} else {
struct V_768 * V_769 = V_767 -> V_770 ;
V_828 = V_769 -> V_18 ;
V_900 = V_897 ;
}
V_338 . type = V_772 ;
V_338 . V_343 . V_725 = & V_725 ;
V_338 . V_343 . V_725 -> V_839 = V_832 ;
V_338 . V_343 . V_725 -> V_195 = V_195 ;
if ( F_304 ( V_717 , & V_338 , & V_753 , 0 , NULL ) )
return V_891 ;
if ( V_844 )
if ( F_57 ( V_828 , V_717 -> V_841 ,
V_842 , V_900 , & V_338 ) )
return F_389 ( - V_898 ) ;
if ( V_845 ) {
T_2 V_833 ;
T_2 V_834 ;
if ( F_338 ( F_379 ( V_899 ) , V_832 , & V_833 ) )
return V_891 ;
if ( F_57 ( V_828 , V_833 ,
V_835 , V_905 , & V_338 ) )
return F_389 ( - V_898 ) ;
if ( F_322 ( V_753 , V_195 , & V_834 ) )
return V_891 ;
if ( F_57 ( V_828 , V_834 ,
V_837 , V_906 , & V_338 ) )
return F_389 ( - V_898 ) ;
}
return V_890 ;
}
static unsigned int F_396 ( void * V_893 ,
struct V_716 * V_717 ,
const struct V_894 * V_895 )
{
return F_391 ( V_717 , V_895 -> V_84 , V_204 ) ;
}
static unsigned int F_397 ( void * V_893 ,
struct V_716 * V_717 ,
const struct V_894 * V_895 )
{
return F_391 ( V_717 , V_895 -> V_84 , V_205 ) ;
}
static int F_398 ( struct V_766 * V_767 , struct V_716 * V_717 )
{
return F_372 ( V_767 , V_717 ) ;
}
static int F_399 ( struct V_907 * V_326 ,
T_4 V_32 )
{
struct V_908 * V_25 ;
V_25 = F_18 ( sizeof( struct V_908 ) , V_16 ) ;
if ( ! V_25 )
return - V_28 ;
V_25 -> V_32 = V_32 ;
V_25 -> V_18 = F_26 () ;
V_326 -> V_20 = V_25 ;
return 0 ;
}
static void F_400 ( struct V_907 * V_326 )
{
struct V_908 * V_25 = V_326 -> V_20 ;
V_326 -> V_20 = NULL ;
F_54 ( V_25 ) ;
}
static int F_401 ( struct V_909 * V_812 )
{
struct V_910 * V_911 ;
V_911 = F_18 ( sizeof( struct V_910 ) , V_16 ) ;
if ( ! V_911 )
return - V_28 ;
V_911 -> V_18 = V_31 ;
V_812 -> V_20 = V_911 ;
return 0 ;
}
static void F_402 ( struct V_909 * V_812 )
{
struct V_910 * V_911 = V_812 -> V_20 ;
V_812 -> V_20 = NULL ;
F_54 ( V_911 ) ;
}
static int F_403 ( struct V_907 * V_912 ,
T_2 V_351 )
{
struct V_908 * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
V_25 = V_912 -> V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_912 -> V_915 ;
return F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_351 , & V_338 ) ;
}
static int F_404 ( struct V_909 * V_812 )
{
return F_401 ( V_812 ) ;
}
static void F_405 ( struct V_909 * V_812 )
{
F_402 ( V_812 ) ;
}
static int F_406 ( struct V_916 * V_917 )
{
struct V_908 * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_63 = F_399 ( & V_917 -> V_918 , V_919 ) ;
if ( V_63 )
return V_63 ;
V_25 = V_917 -> V_918 . V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_917 -> V_918 . V_915 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_919 ,
V_920 , & V_338 ) ;
if ( V_63 ) {
F_400 ( & V_917 -> V_918 ) ;
return V_63 ;
}
return 0 ;
}
static void F_407 ( struct V_916 * V_917 )
{
F_400 ( & V_917 -> V_918 ) ;
}
static int F_408 ( struct V_916 * V_917 , int V_921 )
{
struct V_908 * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
V_25 = V_917 -> V_918 . V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_917 -> V_918 . V_915 ;
return F_57 ( V_18 , V_25 -> V_18 , V_919 ,
V_922 , & V_338 ) ;
}
static int F_409 ( struct V_916 * V_917 , int V_607 )
{
int V_660 ;
int V_351 ;
switch ( V_607 ) {
case V_923 :
case V_924 :
return F_57 ( F_26 () , V_19 ,
V_451 , V_925 , NULL ) ;
case V_926 :
case V_927 :
V_351 = V_928 | V_922 ;
break;
case V_929 :
V_351 = V_930 ;
break;
case V_931 :
V_351 = V_932 ;
break;
default:
return 0 ;
}
V_660 = F_403 ( & V_917 -> V_918 , V_351 ) ;
return V_660 ;
}
static int F_410 ( struct V_916 * V_917 , struct V_909 * V_812 , int V_921 )
{
struct V_908 * V_25 ;
struct V_910 * V_911 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_25 = V_917 -> V_918 . V_20 ;
V_911 = V_812 -> V_20 ;
if ( V_911 -> V_18 == V_31 ) {
V_63 = F_81 ( V_18 , V_25 -> V_18 , V_933 ,
NULL , & V_911 -> V_18 ) ;
if ( V_63 )
return V_63 ;
}
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_917 -> V_918 . V_915 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_919 ,
V_934 , & V_338 ) ;
if ( ! V_63 )
V_63 = F_57 ( V_18 , V_911 -> V_18 , V_933 ,
V_935 , & V_338 ) ;
if ( ! V_63 )
V_63 = F_57 ( V_911 -> V_18 , V_25 -> V_18 , V_919 ,
V_936 , & V_338 ) ;
return V_63 ;
}
static int F_411 ( struct V_916 * V_917 , struct V_909 * V_812 ,
struct V_21 * V_428 ,
long type , int V_176 )
{
struct V_908 * V_25 ;
struct V_910 * V_911 ;
struct V_337 V_338 ;
T_2 V_18 = F_21 ( V_428 ) ;
int V_63 ;
V_25 = V_917 -> V_918 . V_20 ;
V_911 = V_812 -> V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_917 -> V_918 . V_915 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 ,
V_919 , V_937 , & V_338 ) ;
if ( ! V_63 )
V_63 = F_57 ( V_18 , V_911 -> V_18 ,
V_933 , V_938 , & V_338 ) ;
return V_63 ;
}
static int F_412 ( struct V_939 * V_940 )
{
struct V_908 * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_63 = F_399 ( & V_940 -> V_941 , V_942 ) ;
if ( V_63 )
return V_63 ;
V_25 = V_940 -> V_941 . V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_940 -> V_941 . V_915 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_942 ,
V_943 , & V_338 ) ;
if ( V_63 ) {
F_400 ( & V_940 -> V_941 ) ;
return V_63 ;
}
return 0 ;
}
static void F_413 ( struct V_939 * V_940 )
{
F_400 ( & V_940 -> V_941 ) ;
}
static int F_414 ( struct V_939 * V_940 , int V_944 )
{
struct V_908 * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
V_25 = V_940 -> V_941 . V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_940 -> V_941 . V_915 ;
return F_57 ( V_18 , V_25 -> V_18 , V_942 ,
V_945 , & V_338 ) ;
}
static int F_415 ( struct V_939 * V_940 , int V_607 )
{
int V_351 ;
int V_660 ;
switch ( V_607 ) {
case V_923 :
case V_946 :
return F_57 ( F_26 () , V_19 ,
V_451 , V_925 , NULL ) ;
case V_926 :
case V_947 :
V_351 = V_948 | V_945 ;
break;
case V_929 :
V_351 = V_949 ;
break;
case V_950 :
case V_951 :
V_351 = V_952 ;
break;
case V_931 :
V_351 = V_953 ;
break;
default:
return 0 ;
}
V_660 = F_403 ( & V_940 -> V_941 , V_351 ) ;
return V_660 ;
}
static int F_416 ( struct V_939 * V_940 ,
char T_15 * V_954 , int V_944 )
{
T_2 V_351 ;
if ( V_944 & V_955 )
V_351 = V_956 ;
else
V_351 = V_956 | V_957 ;
return F_403 ( & V_940 -> V_941 , V_351 ) ;
}
static int F_417 ( struct V_958 * V_959 )
{
struct V_908 * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_63 = F_399 ( & V_959 -> V_960 , V_961 ) ;
if ( V_63 )
return V_63 ;
V_25 = V_959 -> V_960 . V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_959 -> V_960 . V_915 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_961 ,
V_962 , & V_338 ) ;
if ( V_63 ) {
F_400 ( & V_959 -> V_960 ) ;
return V_63 ;
}
return 0 ;
}
static void F_418 ( struct V_958 * V_959 )
{
F_400 ( & V_959 -> V_960 ) ;
}
static int F_419 ( struct V_958 * V_959 , int V_963 )
{
struct V_908 * V_25 ;
struct V_337 V_338 ;
T_2 V_18 = F_26 () ;
V_25 = V_959 -> V_960 . V_20 ;
V_338 . type = V_913 ;
V_338 . V_343 . V_914 = V_959 -> V_960 . V_915 ;
return F_57 ( V_18 , V_25 -> V_18 , V_961 ,
V_964 , & V_338 ) ;
}
static int F_420 ( struct V_958 * V_959 , int V_607 )
{
int V_660 ;
T_2 V_351 ;
switch ( V_607 ) {
case V_923 :
case V_965 :
return F_57 ( F_26 () , V_19 ,
V_451 , V_925 , NULL ) ;
case V_966 :
case V_967 :
case V_968 :
V_351 = V_969 ;
break;
case V_970 :
case V_971 :
V_351 = V_972 ;
break;
case V_973 :
case V_974 :
V_351 = V_975 ;
break;
case V_931 :
V_351 = V_976 ;
break;
case V_929 :
V_351 = V_977 ;
break;
case V_926 :
case V_978 :
V_351 = V_969 | V_964 ;
break;
default:
return 0 ;
}
V_660 = F_403 ( & V_959 -> V_960 , V_351 ) ;
return V_660 ;
}
static int F_421 ( struct V_958 * V_959 ,
struct V_979 * V_980 , unsigned V_981 , int V_982 )
{
T_2 V_351 ;
if ( V_982 )
V_351 = V_972 | V_975 ;
else
V_351 = V_972 ;
return F_403 ( & V_959 -> V_960 , V_351 ) ;
}
static int F_422 ( struct V_907 * V_983 , short V_110 )
{
T_2 V_341 = 0 ;
V_341 = 0 ;
if ( V_110 & V_984 )
V_341 |= V_985 ;
if ( V_110 & V_986 )
V_341 |= V_987 ;
if ( V_341 == 0 )
return 0 ;
return F_403 ( V_983 , V_341 ) ;
}
static void F_423 ( struct V_907 * V_983 , T_2 * V_601 )
{
struct V_908 * V_25 = V_983 -> V_20 ;
* V_601 = V_25 -> V_18 ;
}
static void F_424 ( struct V_37 * V_37 , struct V_23 * V_23 )
{
if ( V_23 )
F_32 ( V_23 , V_37 ) ;
}
static int F_425 ( struct V_21 * V_153 ,
char * V_74 , char * * V_557 )
{
const struct V_14 * V_867 ;
T_2 V_18 ;
int error ;
unsigned V_96 ;
F_22 () ;
V_867 = F_23 ( V_153 ) -> V_20 ;
if ( V_12 != V_153 ) {
error = F_57 ( F_26 () , V_867 -> V_18 ,
V_425 , V_988 , NULL ) ;
if ( error )
goto V_989;
}
if ( ! strcmp ( V_74 , L_55 ) )
V_18 = V_867 -> V_18 ;
else if ( ! strcmp ( V_74 , L_56 ) )
V_18 = V_867 -> V_17 ;
else if ( ! strcmp ( V_74 , L_57 ) )
V_18 = V_867 -> V_478 ;
else if ( ! strcmp ( V_74 , L_58 ) )
V_18 = V_867 -> V_361 ;
else if ( ! strcmp ( V_74 , L_59 ) )
V_18 = V_867 -> V_476 ;
else if ( ! strcmp ( V_74 , L_60 ) )
V_18 = V_867 -> V_477 ;
else {
error = - V_98 ;
goto V_989;
}
F_24 () ;
if ( ! V_18 )
return 0 ;
error = F_72 ( V_18 , V_557 , & V_96 ) ;
if ( error )
return error ;
return V_96 ;
V_989:
F_24 () ;
return error ;
}
static int F_426 ( const char * V_74 , void * V_557 , T_7 V_590 )
{
struct V_14 * V_15 ;
struct V_11 * V_138 ;
T_2 V_410 = F_26 () , V_18 = 0 , V_485 ;
int error ;
char * V_1 = V_557 ;
if ( ! strcmp ( V_74 , L_57 ) )
error = F_57 ( V_410 , V_410 , V_425 ,
V_990 , NULL ) ;
else if ( ! strcmp ( V_74 , L_58 ) )
error = F_57 ( V_410 , V_410 , V_425 ,
V_991 , NULL ) ;
else if ( ! strcmp ( V_74 , L_59 ) )
error = F_57 ( V_410 , V_410 , V_425 ,
V_992 , NULL ) ;
else if ( ! strcmp ( V_74 , L_60 ) )
error = F_57 ( V_410 , V_410 , V_425 ,
V_993 , NULL ) ;
else if ( ! strcmp ( V_74 , L_55 ) )
error = F_57 ( V_410 , V_410 , V_425 ,
V_994 , NULL ) ;
else
error = - V_98 ;
if ( error )
return error ;
if ( V_590 && V_1 [ 0 ] && V_1 [ 0 ] != '\n' ) {
if ( V_1 [ V_590 - 1 ] == '\n' ) {
V_1 [ V_590 - 1 ] = 0 ;
V_590 -- ;
}
error = F_236 ( V_557 , V_590 , & V_18 , V_16 ) ;
if ( error == - V_98 && ! strcmp ( V_74 , L_58 ) ) {
if ( ! F_232 ( true ) ) {
struct V_592 * V_593 ;
T_7 V_594 ;
if ( V_1 [ V_590 - 1 ] == '\0' )
V_594 = V_590 - 1 ;
else
V_594 = V_590 ;
V_593 = F_237 ( V_12 -> V_595 , V_103 , V_596 ) ;
F_238 ( V_593 , L_61 ) ;
F_239 ( V_593 , V_557 , V_594 ) ;
F_240 ( V_593 ) ;
return error ;
}
error = F_241 ( V_557 , V_590 ,
& V_18 ) ;
}
if ( error )
return error ;
}
V_138 = F_252 () ;
if ( ! V_138 )
return - V_28 ;
V_15 = V_138 -> V_20 ;
if ( ! strcmp ( V_74 , L_57 ) ) {
V_15 -> V_478 = V_18 ;
} else if ( ! strcmp ( V_74 , L_58 ) ) {
V_15 -> V_361 = V_18 ;
} else if ( ! strcmp ( V_74 , L_59 ) ) {
error = F_57 ( V_410 , V_18 , V_995 , V_996 ,
NULL ) ;
if ( error )
goto V_997;
V_15 -> V_476 = V_18 ;
} else if ( ! strcmp ( V_74 , L_60 ) ) {
V_15 -> V_477 = V_18 ;
} else if ( ! strcmp ( V_74 , L_55 ) ) {
error = - V_98 ;
if ( V_18 == 0 )
goto V_997;
error = - V_474 ;
if ( ! F_427 () ) {
error = F_159 ( V_15 -> V_18 , V_18 ) ;
if ( error )
goto V_997;
}
error = F_57 ( V_15 -> V_18 , V_18 , V_425 ,
V_998 , NULL ) ;
if ( error )
goto V_997;
V_485 = F_155 () ;
if ( V_485 != 0 ) {
error = F_57 ( V_485 , V_18 , V_425 ,
V_426 , NULL ) ;
if ( error )
goto V_997;
}
V_15 -> V_18 = V_18 ;
} else {
error = - V_98 ;
goto V_997;
}
F_428 ( V_138 ) ;
return V_590 ;
V_997:
F_429 ( V_138 ) ;
return error ;
}
static int F_430 ( const char * V_74 )
{
return ( strcmp ( V_74 , V_559 ) == 0 ) ;
}
static int F_431 ( T_2 V_601 , char * * V_540 , T_2 * V_999 )
{
return F_72 ( V_601 , V_540 , V_999 ) ;
}
static int F_432 ( const char * V_540 , T_2 V_999 , T_2 * V_601 )
{
return F_236 ( V_540 , V_999 , V_601 , V_16 ) ;
}
static void F_433 ( char * V_540 , T_2 V_999 )
{
F_54 ( V_540 ) ;
}
static void F_434 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_36 ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_34 = V_35 ;
F_47 ( & V_25 -> V_29 ) ;
}
static int F_435 ( struct V_23 * V_23 , void * V_554 , T_2 V_555 )
{
return F_248 ( V_23 , V_559 , V_554 , V_555 , 0 ) ;
}
static int F_436 ( struct V_37 * V_37 , void * V_554 , T_2 V_555 )
{
return F_437 ( V_37 , V_85 , V_554 , V_555 , 0 ) ;
}
static int F_438 ( struct V_23 * V_23 , void * * V_554 , T_2 * V_555 )
{
int V_96 = 0 ;
V_96 = F_247 ( V_23 , V_559 ,
V_554 , true ) ;
if ( V_96 < 0 )
return V_96 ;
* V_555 = V_96 ;
return 0 ;
}
static int F_439 ( struct V_915 * V_1000 , const struct V_11 * V_11 ,
unsigned long V_87 )
{
const struct V_14 * V_15 ;
struct V_1001 * V_1002 ;
V_1002 = F_18 ( sizeof( struct V_1001 ) , V_16 ) ;
if ( ! V_1002 )
return - V_28 ;
V_15 = V_11 -> V_20 ;
if ( V_15 -> V_476 )
V_1002 -> V_18 = V_15 -> V_476 ;
else
V_1002 -> V_18 = V_15 -> V_18 ;
V_1000 -> V_20 = V_1002 ;
return 0 ;
}
static void F_440 ( struct V_915 * V_1000 )
{
struct V_1001 * V_1002 = V_1000 -> V_20 ;
V_1000 -> V_20 = NULL ;
F_54 ( V_1002 ) ;
}
static int F_441 ( T_16 V_1003 ,
const struct V_11 * V_11 ,
unsigned V_326 )
{
struct V_915 * V_915 ;
struct V_1001 * V_1002 ;
T_2 V_18 ;
if ( V_326 == 0 )
return 0 ;
V_18 = F_20 ( V_11 ) ;
V_915 = F_442 ( V_1003 ) ;
V_1002 = V_915 -> V_20 ;
return F_57 ( V_18 , V_1002 -> V_18 , V_995 , V_326 , NULL ) ;
}
static int F_443 ( struct V_915 * V_915 , char * * V_1004 )
{
struct V_1001 * V_1002 = V_915 -> V_20 ;
char * V_95 = NULL ;
unsigned V_96 ;
int V_63 ;
V_63 = F_72 ( V_1002 -> V_18 , & V_95 , & V_96 ) ;
if ( ! V_63 )
V_63 = V_96 ;
* V_1004 = V_95 ;
return V_63 ;
}
static int F_444 ( void * V_1005 , T_17 V_1006 , T_4 V_1007 )
{
struct V_337 V_338 ;
int V_660 ;
T_2 V_18 = 0 ;
struct V_1008 * V_1009 = V_1005 ;
struct V_1010 V_1011 ;
V_660 = F_445 ( V_1006 , V_1007 , & V_18 ) ;
if ( V_660 )
return V_660 ;
V_338 . type = V_1012 ;
V_1011 . V_1006 = V_1006 ;
V_1011 . V_1013 = V_1007 ;
V_338 . V_343 . V_1011 = & V_1011 ;
return F_57 ( V_1009 -> V_18 , V_18 ,
V_1014 ,
V_1015 , & V_338 ) ;
}
static int F_446 ( void * V_1005 , const char * V_547 ,
T_11 V_1016 )
{
struct V_337 V_338 ;
int V_660 ;
T_2 V_18 = 0 ;
struct V_1008 * V_1009 = V_1005 ;
struct V_1017 V_1018 ;
V_660 = F_447 ( V_547 , V_1016 , & V_18 ) ;
if ( V_660 )
return V_660 ;
V_338 . type = V_1019 ;
strncpy ( V_1018 . V_547 , V_547 , sizeof( V_1018 . V_547 ) ) ;
V_1018 . V_1020 = V_1016 ;
V_338 . V_343 . V_1018 = & V_1018 ;
return F_57 ( V_1009 -> V_18 , V_18 ,
V_1021 ,
V_1022 , & V_338 ) ;
}
static int F_448 ( void * * V_1005 )
{
struct V_1008 * V_1009 ;
V_1009 = F_18 ( sizeof( * V_1009 ) , V_16 ) ;
if ( ! V_1009 )
return - V_28 ;
V_1009 -> V_18 = F_26 () ;
* V_1005 = V_1009 ;
return 0 ;
}
static void F_449 ( void * V_1005 )
{
F_54 ( V_1005 ) ;
}
static T_1 int F_450 ( void )
{
if ( ! F_451 ( L_62 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_61 ( V_1023 L_63 ) ;
return 0 ;
}
F_61 ( V_1023 L_64 ) ;
F_17 () ;
V_630 = ! ( V_1024 & V_646 ) ;
V_26 = F_452 ( L_65 ,
sizeof( struct V_24 ) ,
0 , V_1025 , NULL ) ;
V_54 = F_452 ( L_66 ,
sizeof( struct V_52 ) ,
0 , V_1025 , NULL ) ;
F_453 () ;
F_454 ( V_1026 , F_455 ( V_1026 ) , L_62 ) ;
if ( F_456 ( F_9 , V_9 ) )
F_19 ( L_67 ) ;
if ( F_456 ( F_14 , V_9 ) )
F_19 ( L_68 ) ;
if ( V_3 )
F_61 ( V_1027 L_69 ) ;
else
F_61 ( V_1027 L_70 ) ;
return 0 ;
}
static void F_457 ( struct V_57 * V_58 , void * V_1028 )
{
F_89 ( V_58 , NULL ) ;
}
void F_458 ( void )
{
F_61 ( V_1027 L_71 ) ;
F_61 ( V_1027 L_72 ) ;
F_459 ( F_457 , NULL ) ;
}
static int T_18 F_460 ( struct V_725 * V_725 )
{
return F_461 ( V_725 , V_1029 ,
F_455 ( V_1029 ) ) ;
}
static void T_19 F_462 ( struct V_725 * V_725 )
{
F_463 ( V_725 , V_1029 ,
F_455 ( V_1029 ) ) ;
}
static int T_1 F_464 ( void )
{
int V_660 ;
if ( ! V_5 )
return 0 ;
F_61 ( V_1027 L_73 ) ;
V_660 = F_465 ( & V_1030 ) ;
if ( V_660 )
F_19 ( L_74 , V_660 ) ;
return 0 ;
}
static void F_466 ( void )
{
F_61 ( V_1027 L_75 ) ;
F_467 ( & V_1030 ) ;
}
int F_468 ( void )
{
if ( V_40 ) {
return - V_98 ;
}
if ( V_1031 ) {
return - V_98 ;
}
F_61 ( V_1023 L_76 ) ;
V_1031 = 1 ;
V_5 = 0 ;
F_469 ( V_1026 , F_455 ( V_1026 ) ) ;
F_470 () ;
F_466 () ;
F_471 () ;
return 0 ;
}
