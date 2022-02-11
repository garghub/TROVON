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
! strcmp ( V_58 -> V_73 -> V_74 , L_3 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_7 ) ||
! strcmp ( V_58 -> V_73 -> V_74 , L_8 ) )
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
case V_203 :
return V_204 ;
}
break;
case V_205 :
case V_206 :
switch ( type ) {
case V_199 :
case V_200 :
if ( F_97 ( V_191 ) )
return V_207 ;
else if ( V_196 && V_191 == V_208 )
return V_209 ;
else
return V_210 ;
case V_202 :
if ( F_98 ( V_191 ) )
return V_211 ;
else if ( V_196 && ( V_191 == V_212 ||
V_191 == V_213 ) )
return V_214 ;
else
return V_210 ;
case V_215 :
return V_216 ;
default:
return V_210 ;
}
break;
case V_217 :
switch ( V_191 ) {
case V_218 :
return V_219 ;
case V_220 :
return V_221 ;
case V_222 :
return V_223 ;
case V_224 :
return V_225 ;
case V_226 :
return V_227 ;
case V_228 :
return V_229 ;
case V_230 :
return V_231 ;
case V_232 :
return V_233 ;
case V_234 :
return V_235 ;
case V_236 :
return V_237 ;
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
case V_242 :
return V_243 ;
case V_244 :
return V_245 ;
case V_246 :
return V_247 ;
case V_248 :
return V_249 ;
default:
return V_250 ;
}
case V_251 :
return V_252 ;
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
}
if ( V_196 ) {
switch ( V_195 ) {
case V_257 :
return V_258 ;
case V_259 :
return V_260 ;
case V_261 :
return V_262 ;
case V_263 :
return V_264 ;
case V_265 :
return V_266 ;
case V_267 :
return V_268 ;
case V_269 :
return V_270 ;
case V_271 :
return V_272 ;
case V_273 :
return V_274 ;
case V_275 :
return V_276 ;
case V_277 :
return V_278 ;
case V_279 :
return V_280 ;
case V_281 :
return V_282 ;
case V_283 :
return V_284 ;
case V_285 :
return V_286 ;
case V_287 :
return V_288 ;
case V_289 :
return V_290 ;
case V_291 :
return V_292 ;
case V_293 :
return V_294 ;
case V_295 :
return V_296 ;
case V_297 :
return V_298 ;
case V_299 :
return V_300 ;
case V_301 :
return V_302 ;
case V_303 :
return V_304 ;
case V_305 :
return V_306 ;
case V_307 :
return V_308 ;
case V_309 :
return V_310 ;
#if V_311 > 44
#error New address family defined, please update this function.
#endif
}
}
return V_312 ;
}
static int F_100 ( struct V_37 * V_37 ,
T_4 V_313 ,
T_4 V_87 ,
T_2 * V_18 )
{
int V_63 ;
struct V_57 * V_58 = V_37 -> V_314 ;
char * V_315 , * V_316 ;
V_315 = ( char * ) F_101 ( V_16 ) ;
if ( ! V_315 )
return - V_28 ;
V_316 = F_102 ( V_37 , V_315 , V_317 ) ;
if ( F_103 ( V_316 ) )
V_63 = F_104 ( V_316 ) ;
else {
if ( V_87 & V_126 ) {
while ( V_316 [ 1 ] >= '0' && V_316 [ 1 ] <= '9' ) {
V_316 [ 1 ] = '/' ;
V_316 ++ ;
}
}
V_63 = F_105 ( V_58 -> V_73 -> V_74 , V_316 , V_313 , V_18 ) ;
}
F_106 ( ( unsigned long ) V_315 ) ;
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
goto V_318;
if ( V_25 -> V_32 == V_33 )
V_25 -> V_32 = F_96 ( V_23 -> V_319 ) ;
V_47 = V_23 -> V_48 -> V_49 ;
if ( ! ( V_47 -> V_87 & V_88 ) ) {
F_45 ( & V_47 -> V_50 ) ;
if ( F_63 ( & V_25 -> V_30 ) )
F_108 ( & V_25 -> V_30 , & V_47 -> V_59 ) ;
F_47 ( & V_47 -> V_50 ) ;
goto V_318;
}
V_32 = V_25 -> V_32 ;
F_21 = V_25 -> F_21 ;
V_18 = V_25 -> V_18 ;
V_25 -> V_34 = V_320 ;
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
if ( V_63 == - V_321 ) {
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
- V_63 , V_23 -> V_48 -> V_82 , V_23 -> V_322 ) ;
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
char * V_323 = V_23 -> V_48 -> V_82 ;
unsigned long V_324 = V_23 -> V_322 ;
if ( V_63 == - V_98 ) {
if ( F_114 () )
F_61 ( V_325 L_35
L_36
L_37 , V_324 , V_323 , V_95 ) ;
} else {
F_61 ( V_81 L_38
L_39 ,
V_128 , V_95 , - V_63 , V_323 , V_324 ) ;
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
if ( ( V_47 -> V_87 & V_127 ) && ! F_115 ( V_23 -> V_319 ) ) {
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
if ( V_25 -> V_34 == V_320 ) {
if ( ! V_18 || V_63 ) {
V_25 -> V_34 = V_35 ;
goto V_318;
}
V_25 -> V_34 = V_41 ;
V_25 -> V_18 = V_18 ;
}
V_318:
F_47 ( & V_25 -> V_29 ) ;
return V_63 ;
}
static inline T_2 F_116 ( int V_326 )
{
T_2 V_327 = 0 ;
switch ( V_326 ) {
case V_328 :
V_327 = V_329 ;
break;
case V_330 :
V_327 = V_331 ;
break;
case V_332 :
V_327 = V_333 ;
break;
default:
V_327 = V_334 ;
break;
}
return V_327 ;
}
static int F_117 ( const struct V_11 * V_11 ,
int V_335 , int V_336 , bool V_337 )
{
struct V_338 V_339 ;
struct V_340 V_341 ;
T_4 V_32 ;
T_2 V_18 = F_20 ( V_11 ) ;
T_2 V_342 = F_118 ( V_335 ) ;
int V_63 ;
V_339 . type = V_343 ;
V_339 . V_344 . V_335 = V_335 ;
switch ( F_119 ( V_335 ) ) {
case 0 :
V_32 = V_337 ? V_345 : V_346 ;
break;
case 1 :
V_32 = V_337 ? V_347 : V_348 ;
break;
default:
F_61 ( V_349
L_40 , V_335 ) ;
F_93 () ;
return - V_98 ;
}
V_63 = F_120 ( V_18 , V_18 , V_32 , V_342 , 0 , & V_341 ) ;
if ( V_336 == V_350 ) {
int V_351 = F_121 ( V_18 , V_18 , V_32 , V_342 , & V_341 , V_63 , & V_339 , 0 ) ;
if ( V_351 )
return V_351 ;
}
return V_63 ;
}
static int F_122 ( const struct V_11 * V_11 ,
struct V_23 * V_23 ,
T_2 V_352 ,
struct V_338 * V_353 )
{
struct V_24 * V_25 ;
T_2 V_18 ;
F_123 ( V_11 ) ;
if ( F_124 ( F_66 ( V_23 ) ) )
return 0 ;
V_18 = F_20 ( V_11 ) ;
V_25 = V_23 -> V_36 ;
return F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_352 , V_353 ) ;
}
static inline int F_125 ( const struct V_11 * V_11 ,
struct V_37 * V_37 ,
T_2 V_342 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
struct V_338 V_339 ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_37 ;
F_30 ( V_23 , V_37 , true ) ;
return F_122 ( V_11 , V_23 , V_342 , & V_339 ) ;
}
static inline int F_126 ( const struct V_11 * V_11 ,
const struct V_316 * V_316 ,
T_2 V_342 )
{
struct V_23 * V_23 = F_38 ( V_316 -> V_37 ) ;
struct V_338 V_339 ;
V_339 . type = V_355 ;
V_339 . V_344 . V_316 = * V_316 ;
F_30 ( V_23 , V_316 -> V_37 , true ) ;
return F_122 ( V_11 , V_23 , V_342 , & V_339 ) ;
}
static inline int F_127 ( const struct V_11 * V_11 ,
struct V_51 * V_51 ,
T_2 V_342 )
{
struct V_338 V_339 ;
V_339 . type = V_356 ;
V_339 . V_344 . V_51 = V_51 ;
return F_122 ( V_11 , F_128 ( V_51 ) , V_342 , & V_339 ) ;
}
static int F_129 ( const struct V_11 * V_11 ,
struct V_51 * V_51 ,
T_2 V_342 )
{
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
struct V_338 V_339 ;
T_2 V_18 = F_20 ( V_11 ) ;
int V_63 ;
V_339 . type = V_356 ;
V_339 . V_344 . V_51 = V_51 ;
if ( V_18 != V_53 -> V_18 ) {
V_63 = F_57 ( V_18 , V_53 -> V_18 ,
V_357 ,
V_358 ,
& V_339 ) ;
if ( V_63 )
goto V_84;
}
V_63 = 0 ;
if ( V_342 )
V_63 = F_122 ( V_11 , V_23 , V_342 , & V_339 ) ;
V_84:
return V_63 ;
}
static int
F_130 ( const struct V_14 * V_15 ,
struct V_23 * V_359 ,
const struct V_360 * V_74 , T_4 V_313 ,
T_2 * V_361 )
{
const struct V_46 * V_47 = V_359 -> V_48 -> V_49 ;
if ( ( V_47 -> V_87 & V_88 ) &&
( V_47 -> V_68 == V_132 ) ) {
* V_361 = V_47 -> V_62 ;
} else if ( ( V_47 -> V_87 & V_89 ) &&
V_15 -> V_362 ) {
* V_361 = V_15 -> V_362 ;
} else {
const struct V_24 * V_363 = F_36 ( V_359 ) ;
return F_81 ( V_15 -> V_18 , V_363 -> V_18 , V_313 ,
V_74 , V_361 ) ;
}
return 0 ;
}
static int F_131 ( struct V_23 * V_359 ,
struct V_37 * V_37 ,
T_4 V_313 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_24 * V_363 ;
struct V_46 * V_47 ;
T_2 V_18 , V_364 ;
struct V_338 V_339 ;
int V_63 ;
V_363 = F_36 ( V_359 ) ;
V_47 = V_359 -> V_48 -> V_49 ;
V_18 = V_15 -> V_18 ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_37 ;
V_63 = F_57 ( V_18 , V_363 -> V_18 , V_186 ,
V_365 | V_366 ,
& V_339 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_130 ( F_132 () , V_359 ,
& V_37 -> V_367 , V_313 , & V_364 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_18 , V_364 , V_313 , V_368 , & V_339 ) ;
if ( V_63 )
return V_63 ;
return F_57 ( V_364 , V_47 -> V_18 ,
V_64 ,
V_67 , & V_339 ) ;
}
static int F_133 ( struct V_23 * V_359 ,
struct V_37 * V_37 ,
int V_369 )
{
struct V_24 * V_363 , * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
T_2 V_342 ;
int V_63 ;
V_363 = F_36 ( V_359 ) ;
V_25 = F_39 ( V_37 ) ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_37 ;
V_342 = V_366 ;
V_342 |= ( V_369 ? V_370 : V_365 ) ;
V_63 = F_57 ( V_18 , V_363 -> V_18 , V_186 , V_342 , & V_339 ) ;
if ( V_63 )
return V_63 ;
switch ( V_369 ) {
case V_371 :
V_342 = V_372 ;
break;
case V_373 :
V_342 = V_374 ;
break;
case V_375 :
V_342 = V_376 ;
break;
default:
F_61 ( V_81 L_41 ,
V_128 , V_369 ) ;
return 0 ;
}
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_342 , & V_339 ) ;
return V_63 ;
}
static inline int F_134 ( struct V_23 * V_377 ,
struct V_37 * V_378 ,
struct V_23 * V_379 ,
struct V_37 * V_380 )
{
struct V_24 * V_381 , * V_382 , * V_383 , * V_384 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
T_2 V_342 ;
int V_385 , V_386 ;
int V_63 ;
V_381 = F_36 ( V_377 ) ;
V_383 = F_39 ( V_378 ) ;
V_385 = F_135 ( V_378 ) ;
V_382 = F_36 ( V_379 ) ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_378 ;
V_63 = F_57 ( V_18 , V_381 -> V_18 , V_186 ,
V_370 | V_366 , & V_339 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_18 , V_383 -> V_18 ,
V_383 -> V_32 , V_387 , & V_339 ) ;
if ( V_63 )
return V_63 ;
if ( V_385 && V_379 != V_377 ) {
V_63 = F_57 ( V_18 , V_383 -> V_18 ,
V_383 -> V_32 , V_388 , & V_339 ) ;
if ( V_63 )
return V_63 ;
}
V_339 . V_344 . V_37 = V_380 ;
V_342 = V_365 | V_366 ;
if ( F_136 ( V_380 ) )
V_342 |= V_370 ;
V_63 = F_57 ( V_18 , V_382 -> V_18 , V_186 , V_342 , & V_339 ) ;
if ( V_63 )
return V_63 ;
if ( F_136 ( V_380 ) ) {
V_384 = F_39 ( V_380 ) ;
V_386 = F_135 ( V_380 ) ;
V_63 = F_57 ( V_18 , V_384 -> V_18 ,
V_384 -> V_32 ,
( V_386 ? V_376 : V_374 ) , & V_339 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_137 ( const struct V_11 * V_11 ,
struct V_57 * V_58 ,
T_2 V_352 ,
struct V_338 * V_339 )
{
struct V_46 * V_47 ;
T_2 V_18 = F_20 ( V_11 ) ;
V_47 = V_58 -> V_49 ;
return F_57 ( V_18 , V_47 -> V_18 , V_64 , V_352 , V_339 ) ;
}
static inline T_2 F_138 ( int V_176 , int V_389 )
{
T_2 V_342 = 0 ;
if ( ! F_139 ( V_176 ) ) {
if ( V_389 & V_390 )
V_342 |= V_391 ;
if ( V_389 & V_392 )
V_342 |= V_393 ;
if ( V_389 & V_394 )
V_342 |= V_395 ;
else if ( V_389 & V_396 )
V_342 |= V_397 ;
} else {
if ( V_389 & V_390 )
V_342 |= V_366 ;
if ( V_389 & V_396 )
V_342 |= V_398 ;
if ( V_389 & V_392 )
V_342 |= V_399 ;
}
return V_342 ;
}
static inline T_2 F_140 ( struct V_51 * V_51 )
{
T_2 V_342 = 0 ;
if ( V_51 -> V_400 & V_401 )
V_342 |= V_393 ;
if ( V_51 -> V_400 & V_402 ) {
if ( V_51 -> V_403 & V_404 )
V_342 |= V_395 ;
else
V_342 |= V_397 ;
}
if ( ! V_342 ) {
V_342 = V_405 ;
}
return V_342 ;
}
static inline T_2 F_141 ( struct V_51 * V_51 )
{
T_2 V_342 = F_140 ( V_51 ) ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
if ( V_406 && V_23 -> V_48 -> V_407 != V_408 )
V_342 |= V_409 ;
return V_342 ;
}
static int F_142 ( struct V_21 * V_410 )
{
T_2 V_411 = F_26 () ;
T_2 V_412 = F_21 ( V_410 ) ;
return F_57 ( V_411 , V_412 , V_413 ,
V_414 , NULL ) ;
}
static int F_143 ( struct V_21 * V_415 ,
struct V_21 * V_416 )
{
T_2 V_411 = F_26 () ;
T_2 V_417 = F_21 ( V_415 ) ;
T_2 V_418 = F_21 ( V_416 ) ;
int V_63 ;
if ( V_411 != V_417 ) {
V_63 = F_57 ( V_411 , V_417 , V_413 ,
V_419 , NULL ) ;
if ( V_63 )
return V_63 ;
}
return F_57 ( V_417 , V_418 , V_413 , V_420 ,
NULL ) ;
}
static int F_144 ( struct V_21 * V_415 ,
struct V_21 * V_416 )
{
T_2 V_417 = F_21 ( V_415 ) ;
T_2 V_418 = F_21 ( V_416 ) ;
return F_57 ( V_417 , V_418 , V_413 , V_421 ,
NULL ) ;
}
static int F_145 ( struct V_21 * V_415 ,
struct V_21 * V_416 ,
struct V_51 * V_51 )
{
T_2 V_18 = F_21 ( V_416 ) ;
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_37 * V_37 = V_51 -> V_422 . V_37 ;
struct V_24 * V_25 ;
struct V_338 V_339 ;
int V_63 ;
V_339 . type = V_355 ;
V_339 . V_344 . V_316 = V_51 -> V_422 ;
if ( V_18 != V_53 -> V_18 ) {
V_63 = F_57 ( V_18 , V_53 -> V_18 ,
V_357 ,
V_358 ,
& V_339 ) ;
if ( V_63 )
return V_63 ;
}
if ( F_124 ( F_66 ( F_38 ( V_37 ) ) ) )
return 0 ;
V_25 = F_39 ( V_37 ) ;
return F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , F_140 ( V_51 ) ,
& V_339 ) ;
}
static int F_146 ( struct V_21 * V_423 ,
unsigned int V_176 )
{
T_2 V_18 = F_26 () ;
T_2 V_424 = F_21 ( V_423 ) ;
if ( V_176 & V_425 )
return F_57 ( V_18 , V_424 , V_33 , V_393 , NULL ) ;
return F_57 ( V_18 , V_424 , V_426 , V_427 , NULL ) ;
}
static int F_147 ( struct V_21 * V_428 )
{
return F_57 ( F_21 ( V_428 ) , F_26 () , V_426 ,
V_427 , NULL ) ;
}
static int F_148 ( struct V_21 * V_429 , T_6 * V_430 ,
T_6 * V_431 , T_6 * V_432 )
{
return F_57 ( F_26 () , F_21 ( V_429 ) , V_426 ,
V_433 , NULL ) ;
}
static int F_149 ( struct V_11 * V_138 , const struct V_11 * V_137 ,
const T_6 * V_430 ,
const T_6 * V_431 ,
const T_6 * V_432 )
{
return F_57 ( F_20 ( V_137 ) , F_20 ( V_138 ) , V_426 ,
V_434 , NULL ) ;
}
static int F_150 ( const struct V_11 * V_11 , struct V_435 * V_436 ,
int V_335 , int V_336 )
{
return F_117 ( V_11 , V_335 , V_336 , V_436 == & V_130 ) ;
}
static int F_151 ( int V_437 , int type , int V_438 , struct V_57 * V_58 )
{
const struct V_11 * V_11 = F_77 () ;
int V_63 = 0 ;
if ( ! V_58 )
return 0 ;
switch ( V_437 ) {
case V_439 :
case V_440 :
case V_441 :
case V_442 :
case V_443 :
V_63 = F_137 ( V_11 , V_58 , V_444 , NULL ) ;
break;
case V_445 :
case V_446 :
case V_447 :
V_63 = F_137 ( V_11 , V_58 , V_448 , NULL ) ;
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
return F_125 ( V_11 , V_37 , V_449 ) ;
}
static int F_153 ( int type )
{
switch ( type ) {
case V_450 :
case V_451 :
return F_57 ( F_26 () , V_19 ,
V_452 , V_453 , NULL ) ;
case V_454 :
case V_455 :
case V_456 :
return F_57 ( F_26 () , V_19 ,
V_452 , V_457 ,
NULL ) ;
}
return F_57 ( F_26 () , V_19 ,
V_452 , V_458 , NULL ) ;
}
static int F_154 ( struct V_459 * V_460 , long V_461 )
{
int V_63 , V_462 = 0 ;
V_63 = F_117 ( F_77 () , V_463 ,
V_464 , true ) ;
if ( V_63 == 0 )
V_462 = 1 ;
return V_462 ;
}
static T_2 F_155 ( void )
{
T_2 V_18 = 0 ;
struct V_21 * V_465 ;
F_22 () ;
V_465 = F_156 ( V_12 ) ;
if ( V_465 )
V_18 = F_21 ( V_465 ) ;
F_24 () ;
return V_18 ;
}
static int F_157 ( const struct V_466 * V_467 ,
const struct V_14 * V_468 ,
const struct V_14 * V_469 )
{
int V_470 = ( V_467 -> V_471 & V_472 ) ;
int V_473 = ! F_158 ( V_467 -> V_51 -> V_422 . V_474 ) ;
int V_63 ;
T_2 V_342 ;
if ( ! V_470 && ! V_473 )
return 0 ;
if ( V_469 -> V_18 == V_468 -> V_18 )
return 0 ;
if ( V_475 ) {
V_342 = 0 ;
if ( V_470 )
V_342 |= V_476 ;
if ( V_473 )
V_342 |= V_477 ;
V_63 = F_57 ( V_468 -> V_18 , V_469 -> V_18 ,
V_478 , V_342 , NULL ) ;
if ( ! V_63 )
return 0 ;
}
V_63 = F_159 ( V_468 -> V_18 , V_469 -> V_18 ) ;
if ( ! V_63 )
return 0 ;
if ( V_470 )
return - V_479 ;
return - V_131 ;
}
static int F_160 ( struct V_466 * V_467 )
{
const struct V_14 * V_468 ;
struct V_14 * V_469 ;
struct V_24 * V_25 ;
struct V_338 V_339 ;
struct V_23 * V_23 = F_128 ( V_467 -> V_51 ) ;
int V_63 ;
if ( V_467 -> V_480 )
return 0 ;
V_468 = F_132 () ;
V_469 = V_467 -> V_11 -> V_20 ;
V_25 = F_36 ( V_23 ) ;
V_469 -> V_18 = V_468 -> V_18 ;
V_469 -> V_17 = V_468 -> V_18 ;
V_469 -> V_362 = 0 ;
V_469 -> V_481 = 0 ;
V_469 -> V_482 = 0 ;
if ( V_468 -> V_483 ) {
V_469 -> V_18 = V_468 -> V_483 ;
V_469 -> V_483 = 0 ;
V_63 = F_157 ( V_467 , V_468 , V_469 ) ;
if ( V_63 )
return V_63 ;
} else {
V_63 = F_81 ( V_468 -> V_18 , V_25 -> V_18 ,
V_426 , NULL ,
& V_469 -> V_18 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_157 ( V_467 , V_468 , V_469 ) ;
if ( V_63 )
V_469 -> V_18 = V_468 -> V_18 ;
}
V_339 . type = V_356 ;
V_339 . V_344 . V_51 = V_467 -> V_51 ;
if ( V_469 -> V_18 == V_468 -> V_18 ) {
V_63 = F_57 ( V_468 -> V_18 , V_25 -> V_18 ,
V_33 , V_484 , & V_339 ) ;
if ( V_63 )
return V_63 ;
} else {
V_63 = F_57 ( V_468 -> V_18 , V_469 -> V_18 ,
V_426 , V_485 , & V_339 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_469 -> V_18 , V_25 -> V_18 ,
V_33 , V_486 , & V_339 ) ;
if ( V_63 )
return V_63 ;
if ( V_467 -> V_471 & V_487 ) {
V_63 = F_57 ( V_468 -> V_18 , V_469 -> V_18 ,
V_426 , V_488 ,
NULL ) ;
if ( V_63 )
return - V_479 ;
}
if ( V_467 -> V_471 & V_489 ) {
T_2 V_490 = F_155 () ;
if ( V_490 != 0 ) {
V_63 = F_57 ( V_490 , V_469 -> V_18 ,
V_426 ,
V_427 , NULL ) ;
if ( V_63 )
return - V_479 ;
}
}
V_467 -> V_491 |= V_492 ;
V_63 = F_57 ( V_468 -> V_18 , V_469 -> V_18 ,
V_426 , V_493 ,
NULL ) ;
V_467 -> V_494 |= ! ! V_63 ;
}
return 0 ;
}
static int F_161 ( const void * V_153 , struct V_51 * V_51 , unsigned V_495 )
{
return F_129 ( V_153 , V_51 , F_140 ( V_51 ) ) ? V_495 + 1 : 0 ;
}
static inline void F_162 ( const struct V_11 * V_11 ,
struct V_496 * V_497 )
{
struct V_51 * V_51 , * V_498 = NULL ;
struct V_499 * V_500 ;
int V_501 = 0 ;
unsigned V_502 ;
V_500 = F_163 () ;
if ( V_500 ) {
F_45 ( & V_500 -> V_503 ) ;
if ( ! F_63 ( & V_500 -> V_504 ) ) {
struct V_505 * V_506 ;
V_506 = F_164 ( & V_500 -> V_504 ,
struct V_505 , V_30 ) ;
V_51 = V_506 -> V_51 ;
if ( F_127 ( V_11 , V_51 , V_393 | V_397 ) )
V_501 = 1 ;
}
F_47 ( & V_500 -> V_503 ) ;
F_165 ( V_500 ) ;
}
if ( V_501 )
F_166 () ;
V_502 = F_167 ( V_497 , 0 , F_161 , V_11 ) ;
if ( ! V_502 )
return;
V_498 = F_168 ( & V_507 , V_508 , V_11 ) ;
if ( F_103 ( V_498 ) )
V_498 = NULL ;
do {
F_169 ( V_502 - 1 , V_498 , 0 ) ;
} while ( ( V_502 = F_167 ( V_497 , V_502 , F_161 , V_11 ) ) != 0 );
if ( V_498 )
F_170 ( V_498 ) ;
}
static void F_171 ( struct V_466 * V_467 )
{
struct V_14 * V_469 ;
struct V_509 * V_510 , * V_511 ;
int V_63 , V_94 ;
V_469 = V_467 -> V_11 -> V_20 ;
if ( V_469 -> V_18 == V_469 -> V_17 )
return;
F_162 ( V_467 -> V_11 , V_12 -> V_497 ) ;
V_12 -> V_512 = 0 ;
V_63 = F_57 ( V_469 -> V_17 , V_469 -> V_18 , V_426 ,
V_513 , NULL ) ;
if ( V_63 ) {
F_172 ( V_12 ) ;
for ( V_94 = 0 ; V_94 < V_514 ; V_94 ++ ) {
V_510 = V_12 -> signal -> V_510 + V_94 ;
V_511 = V_515 . signal -> V_510 + V_94 ;
V_510 -> V_516 = F_173 ( V_510 -> V_517 , V_511 -> V_516 ) ;
}
F_174 ( V_12 ) ;
if ( F_175 ( V_518 ) )
F_176 ( V_12 , V_509 ( V_519 ) ) ;
}
}
static void F_177 ( struct V_466 * V_467 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_520 V_521 ;
T_2 V_17 , V_18 ;
int V_63 , V_94 ;
V_17 = V_15 -> V_17 ;
V_18 = V_15 -> V_18 ;
if ( V_18 == V_17 )
return;
V_63 = F_57 ( V_17 , V_18 , V_426 , V_522 , NULL ) ;
if ( V_63 ) {
if ( F_175 ( V_518 ) ) {
memset ( & V_521 , 0 , sizeof V_521 ) ;
for ( V_94 = 0 ; V_94 < 3 ; V_94 ++ )
F_178 ( V_94 , & V_521 , NULL ) ;
}
F_179 ( & V_12 -> V_523 -> V_524 ) ;
if ( ! F_180 ( V_12 ) ) {
F_181 ( & V_12 -> V_525 ) ;
F_181 ( & V_12 -> signal -> V_526 ) ;
F_182 ( V_12 , 1 ) ;
F_183 ( & V_12 -> V_527 ) ;
F_184 () ;
}
F_185 ( & V_12 -> V_523 -> V_524 ) ;
}
F_186 ( & V_528 ) ;
F_187 ( V_12 , V_12 -> V_529 ) ;
F_188 ( & V_528 ) ;
}
static int F_189 ( struct V_57 * V_58 )
{
return F_51 ( V_58 ) ;
}
static void F_190 ( struct V_57 * V_58 )
{
F_53 ( V_58 ) ;
}
static inline int F_191 ( char * V_169 , int V_530 , char * V_531 , int V_532 )
{
if ( V_530 > V_532 )
return 0 ;
return ! memcmp ( V_169 , V_531 , V_530 ) ;
}
static inline int F_192 ( char * V_531 , int V_96 )
{
return ( F_191 ( V_171 , sizeof( V_171 ) - 1 , V_531 , V_96 ) ||
F_191 ( V_172 , sizeof( V_172 ) - 1 , V_531 , V_96 ) ||
F_191 ( V_174 , sizeof( V_174 ) - 1 , V_531 , V_96 ) ||
F_191 ( V_173 , sizeof( V_173 ) - 1 , V_531 , V_96 ) ||
F_191 ( V_175 , sizeof( V_175 ) - 1 , V_531 , V_96 ) ) ;
}
static inline void F_193 ( char * * V_416 , char * V_415 , int * V_533 , int V_96 )
{
if ( ! * V_533 ) {
* * V_416 = ',' ;
* V_416 += 1 ;
} else
* V_533 = 0 ;
memcpy ( * V_416 , V_415 , V_96 ) ;
* V_416 += V_96 ;
}
static inline void F_194 ( char * * V_416 , char * V_415 , int * V_533 ,
int V_96 )
{
int V_534 = 0 ;
if ( ! * V_533 ) {
* * V_416 = '|' ;
* V_416 += 1 ;
} else
* V_533 = 0 ;
while ( V_534 < V_96 ) {
if ( * V_415 != '"' ) {
* * V_416 = * V_415 ;
* V_416 += 1 ;
}
V_415 += 1 ;
V_534 += 1 ;
}
}
static int F_195 ( char * V_535 , char * V_536 )
{
int V_537 , V_53 , V_63 = 0 ;
char * V_538 , * V_539 , * V_540 ;
char * V_541 , * V_542 , * V_543 ;
int V_544 = 0 ;
V_539 = V_535 ;
V_541 = V_536 ;
V_543 = ( char * ) F_196 ( V_16 ) ;
if ( ! V_543 ) {
V_63 = - V_28 ;
goto V_84;
}
V_542 = V_543 ;
V_537 = V_53 = 1 ;
V_538 = V_540 = V_535 ;
do {
if ( * V_540 == '"' )
V_544 = ! V_544 ;
if ( ( * V_540 == ',' && V_544 == 0 ) ||
* V_540 == '\0' ) {
int V_96 = V_540 - V_539 ;
if ( F_192 ( V_539 , V_96 ) )
F_194 ( & V_541 , V_539 , & V_53 , V_96 ) ;
else
F_193 ( & V_543 , V_539 , & V_537 , V_96 ) ;
V_539 = V_540 + 1 ;
}
} while ( * V_540 ++ );
strcpy ( V_538 , V_542 ) ;
F_106 ( ( unsigned long ) V_542 ) ;
V_84:
return V_63 ;
}
static int F_197 ( struct V_57 * V_58 , void * V_166 )
{
int V_63 , V_94 , * V_87 ;
struct V_92 V_93 ;
char * V_545 , * * V_121 ;
struct V_46 * V_47 = V_58 -> V_49 ;
if ( ! ( V_47 -> V_87 & V_88 ) )
return 0 ;
if ( ! V_166 )
return 0 ;
if ( V_58 -> V_73 -> V_123 & V_124 )
return 0 ;
F_69 ( & V_93 ) ;
V_545 = F_198 () ;
if ( ! V_545 )
return - V_28 ;
V_63 = F_195 ( V_166 , V_545 ) ;
if ( V_63 )
goto V_546;
V_63 = F_85 ( V_545 , & V_93 ) ;
if ( V_63 )
goto V_546;
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
goto V_547;
}
V_63 = - V_98 ;
switch ( V_87 [ V_94 ] ) {
case V_106 :
if ( F_75 ( V_47 , V_106 , V_47 -> V_18 , V_18 ) )
goto V_548;
break;
case V_107 :
if ( F_75 ( V_47 , V_107 , V_47 -> V_62 , V_18 ) )
goto V_548;
break;
case V_109 : {
struct V_24 * V_116 ;
V_116 = F_39 ( V_58 -> V_77 ) ;
if ( F_75 ( V_47 , V_109 , V_116 -> V_18 , V_18 ) )
goto V_548;
break;
}
case V_108 :
if ( F_75 ( V_47 , V_108 , V_47 -> V_60 , V_18 ) )
goto V_548;
break;
default:
goto V_547;
}
}
V_63 = 0 ;
V_547:
F_74 ( & V_93 ) ;
V_546:
F_199 ( V_545 ) ;
return V_63 ;
V_548:
F_61 ( V_81 L_42
L_43 , V_58 -> V_82 ,
V_58 -> V_73 -> V_74 ) ;
goto V_547;
}
static int F_200 ( struct V_57 * V_58 , int V_87 , void * V_166 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_338 V_339 ;
int V_63 ;
V_63 = F_89 ( V_58 , V_166 ) ;
if ( V_63 )
return V_63 ;
if ( V_87 & V_549 )
return 0 ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_58 -> V_77 ;
return F_137 ( V_11 , V_58 , V_550 , & V_339 ) ;
}
static int F_201 ( struct V_37 * V_37 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_338 V_339 ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_37 -> V_314 -> V_77 ;
return F_137 ( V_11 , V_37 -> V_314 , V_551 , & V_339 ) ;
}
static int F_202 ( const char * V_552 ,
const struct V_316 * V_316 ,
const char * type ,
unsigned long V_87 ,
void * V_166 )
{
const struct V_11 * V_11 = F_77 () ;
if ( V_87 & V_553 )
return F_137 ( V_11 , V_316 -> V_37 -> V_314 ,
V_554 , NULL ) ;
else
return F_126 ( V_11 , V_316 , V_555 ) ;
}
static int F_203 ( struct V_556 * V_474 , int V_87 )
{
const struct V_11 * V_11 = F_77 () ;
return F_137 ( V_11 , V_474 -> V_557 ,
V_558 , NULL ) ;
}
static int F_204 ( struct V_23 * V_23 )
{
return F_25 ( V_23 ) ;
}
static void F_205 ( struct V_23 * V_23 )
{
F_43 ( V_23 ) ;
}
static int F_206 ( struct V_37 * V_37 , int V_176 ,
const struct V_360 * V_74 , void * * V_559 ,
T_2 * V_560 )
{
T_2 V_364 ;
int V_63 ;
V_63 = F_130 ( F_132 () ,
F_207 ( V_37 -> V_561 ) , V_74 ,
F_96 ( V_176 ) ,
& V_364 ) ;
if ( V_63 )
return V_63 ;
return F_72 ( V_364 , ( char * * ) V_559 , V_560 ) ;
}
static int F_208 ( struct V_37 * V_37 , int V_176 ,
struct V_360 * V_74 ,
const struct V_11 * V_137 ,
struct V_11 * V_138 )
{
T_2 V_364 ;
int V_63 ;
struct V_14 * V_15 ;
V_63 = F_130 ( V_137 -> V_20 ,
F_207 ( V_37 -> V_561 ) , V_74 ,
F_96 ( V_176 ) ,
& V_364 ) ;
if ( V_63 )
return V_63 ;
V_15 = V_138 -> V_20 ;
V_15 -> V_362 = V_364 ;
return 0 ;
}
static int F_209 ( struct V_23 * V_23 , struct V_23 * V_359 ,
const struct V_360 * V_360 ,
const char * * V_74 ,
void * * V_562 , T_7 * V_96 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_46 * V_47 ;
T_2 V_18 , V_364 , V_563 ;
int V_63 ;
char * V_95 ;
V_47 = V_359 -> V_48 -> V_49 ;
V_18 = V_15 -> V_18 ;
V_364 = V_15 -> V_362 ;
V_63 = F_130 ( F_132 () ,
V_359 , V_360 ,
F_96 ( V_23 -> V_319 ) ,
& V_364 ) ;
if ( V_63 )
return V_63 ;
if ( V_47 -> V_87 & V_88 ) {
struct V_24 * V_25 = V_23 -> V_36 ;
V_25 -> V_32 = F_96 ( V_23 -> V_319 ) ;
V_25 -> V_18 = V_364 ;
V_25 -> V_34 = V_41 ;
}
if ( ! V_40 || ! ( V_47 -> V_87 & V_89 ) )
return - V_83 ;
if ( V_74 )
* V_74 = V_564 ;
if ( V_562 && V_96 ) {
V_63 = F_210 ( V_364 , & V_95 , & V_563 ) ;
if ( V_63 )
return V_63 ;
* V_562 = V_95 ;
* V_96 = V_563 ;
}
return 0 ;
}
static int F_211 ( struct V_23 * V_359 , struct V_37 * V_37 , T_5 V_176 )
{
return F_131 ( V_359 , V_37 , V_33 ) ;
}
static int F_212 ( struct V_37 * V_378 , struct V_23 * V_359 , struct V_37 * V_380 )
{
return F_133 ( V_359 , V_378 , V_371 ) ;
}
static int F_213 ( struct V_23 * V_359 , struct V_37 * V_37 )
{
return F_133 ( V_359 , V_37 , V_373 ) ;
}
static int F_214 ( struct V_23 * V_359 , struct V_37 * V_37 , const char * V_74 )
{
return F_131 ( V_359 , V_37 , V_181 ) ;
}
static int F_215 ( struct V_23 * V_359 , struct V_37 * V_37 , T_5 V_389 )
{
return F_131 ( V_359 , V_37 , V_186 ) ;
}
static int F_216 ( struct V_23 * V_359 , struct V_37 * V_37 )
{
return F_133 ( V_359 , V_37 , V_375 ) ;
}
static int F_217 ( struct V_23 * V_359 , struct V_37 * V_37 , T_5 V_176 , T_8 V_323 )
{
return F_131 ( V_359 , V_37 , F_96 ( V_176 ) ) ;
}
static int F_218 ( struct V_23 * V_565 , struct V_37 * V_378 ,
struct V_23 * V_566 , struct V_37 * V_380 )
{
return F_134 ( V_565 , V_378 , V_566 , V_380 ) ;
}
static int F_219 ( struct V_37 * V_37 )
{
const struct V_11 * V_11 = F_77 () ;
return F_125 ( V_11 , V_37 , V_393 ) ;
}
static int F_220 ( struct V_37 * V_37 , struct V_23 * V_23 ,
bool V_43 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_338 V_339 ;
struct V_24 * V_25 ;
T_2 V_18 ;
F_123 ( V_11 ) ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_37 ;
V_18 = F_20 ( V_11 ) ;
V_25 = F_34 ( V_23 , V_43 ) ;
if ( F_103 ( V_25 ) )
return F_104 ( V_25 ) ;
return F_221 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_393 , & V_339 ,
V_43 ? V_567 : 0 ) ;
}
static T_9 int F_222 ( struct V_23 * V_23 ,
T_2 V_352 , T_2 V_568 , T_2 V_569 ,
int V_570 ,
unsigned V_87 )
{
struct V_338 V_339 ;
struct V_24 * V_25 = V_23 -> V_36 ;
int V_63 ;
V_339 . type = V_571 ;
V_339 . V_344 . V_23 = V_23 ;
V_63 = F_223 ( F_26 () , V_25 -> V_18 , V_25 -> V_32 , V_352 ,
V_568 , V_569 , V_570 , & V_339 , V_87 ) ;
if ( V_63 )
return V_63 ;
return 0 ;
}
static int F_224 ( struct V_23 * V_23 , int V_389 )
{
const struct V_11 * V_11 = F_77 () ;
T_2 V_352 ;
bool V_572 ;
unsigned V_87 = V_389 & V_567 ;
struct V_24 * V_25 ;
T_2 V_18 ;
struct V_340 V_341 ;
int V_63 , V_351 ;
T_2 V_568 , V_569 ;
V_572 = V_389 & V_573 ;
V_389 &= ( V_392 | V_396 | V_390 | V_394 ) ;
if ( ! V_389 )
return 0 ;
F_123 ( V_11 ) ;
if ( F_124 ( F_66 ( V_23 ) ) )
return 0 ;
V_352 = F_138 ( V_23 -> V_319 , V_389 ) ;
V_18 = F_20 ( V_11 ) ;
V_25 = F_34 ( V_23 , V_87 & V_567 ) ;
if ( F_103 ( V_25 ) )
return F_104 ( V_25 ) ;
V_63 = F_120 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_352 , 0 , & V_341 ) ;
V_568 = F_225 ( V_352 , & V_341 , V_63 ,
V_572 ? V_574 : 0 ,
& V_569 ) ;
if ( F_226 ( ! V_568 ) )
return V_63 ;
V_351 = F_222 ( V_23 , V_352 , V_568 , V_569 , V_63 , V_87 ) ;
if ( V_351 )
return V_351 ;
return V_63 ;
}
static int F_227 ( struct V_37 * V_37 , struct V_575 * V_575 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_23 * V_23 = F_38 ( V_37 ) ;
unsigned int V_576 = V_575 -> V_576 ;
T_10 V_342 = V_397 ;
if ( V_576 & V_577 ) {
V_576 &= ~ ( V_578 | V_579 | V_580 |
V_577 ) ;
if ( ! V_576 )
return 0 ;
}
if ( V_576 & ( V_580 | V_581 | V_582 |
V_583 | V_584 | V_585 ) )
return F_125 ( V_11 , V_37 , V_586 ) ;
if ( V_406 &&
V_23 -> V_48 -> V_407 != V_408 &&
( V_576 & V_587 ) &&
! ( V_576 & V_588 ) )
V_342 |= V_409 ;
return F_125 ( V_11 , V_37 , V_342 ) ;
}
static int F_228 ( const struct V_316 * V_316 )
{
return F_126 ( F_77 () , V_316 , V_589 ) ;
}
static int F_229 ( struct V_37 * V_37 , const char * V_74 )
{
const struct V_11 * V_11 = F_77 () ;
if ( ! strncmp ( V_74 , V_590 ,
sizeof V_590 - 1 ) ) {
if ( ! strcmp ( V_74 , V_591 ) ) {
if ( ! F_230 ( V_592 ) )
return - V_479 ;
} else if ( ! F_230 ( V_463 ) ) {
return - V_479 ;
}
}
return F_125 ( V_11 , V_37 , V_586 ) ;
}
static bool F_231 ( bool V_336 )
{
const struct V_11 * V_11 = F_77 () ;
int V_593 = V_336 ? V_350 : V_464 ;
if ( F_232 ( V_11 , & V_130 , V_594 , V_593 ) )
return false ;
if ( F_117 ( V_11 , V_594 , V_593 , true ) )
return false ;
return true ;
}
static int F_233 ( struct V_37 * V_37 , const char * V_74 ,
const void * V_562 , T_7 V_595 , int V_87 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
struct V_24 * V_25 ;
struct V_46 * V_47 ;
struct V_338 V_339 ;
T_2 V_364 , V_18 = F_26 () ;
int V_63 = 0 ;
if ( strcmp ( V_74 , V_85 ) )
return F_229 ( V_37 , V_74 ) ;
V_47 = V_23 -> V_48 -> V_49 ;
if ( ! ( V_47 -> V_87 & V_89 ) )
return - V_83 ;
if ( ! F_234 ( V_23 ) )
return - V_479 ;
V_339 . type = V_354 ;
V_339 . V_344 . V_37 = V_37 ;
V_25 = F_39 ( V_37 ) ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 ,
V_596 , & V_339 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_235 ( V_562 , V_595 , & V_364 , V_16 ) ;
if ( V_63 == - V_98 ) {
if ( ! F_231 ( true ) ) {
struct V_597 * V_598 ;
T_7 V_599 ;
const char * V_1 ;
if ( V_562 ) {
V_1 = V_562 ;
if ( V_1 [ V_595 - 1 ] == '\0' )
V_599 = V_595 - 1 ;
else
V_599 = V_595 ;
} else {
V_1 = L_44 ;
V_599 = 0 ;
}
V_598 = F_236 ( V_12 -> V_600 , V_103 , V_601 ) ;
F_237 ( V_598 , L_45 ) ;
F_238 ( V_598 , V_562 , V_599 ) ;
F_239 ( V_598 ) ;
return V_63 ;
}
V_63 = F_240 ( V_562 , V_595 , & V_364 ) ;
}
if ( V_63 )
return V_63 ;
V_63 = F_57 ( V_18 , V_364 , V_25 -> V_32 ,
V_602 , & V_339 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_241 ( V_25 -> V_18 , V_364 , V_18 ,
V_25 -> V_32 ) ;
if ( V_63 )
return V_63 ;
return F_57 ( V_364 ,
V_47 -> V_18 ,
V_64 ,
V_67 ,
& V_339 ) ;
}
static void F_242 ( struct V_37 * V_37 , const char * V_74 ,
const void * V_562 , T_7 V_595 ,
int V_87 )
{
struct V_23 * V_23 = F_38 ( V_37 ) ;
struct V_24 * V_25 ;
T_2 V_364 ;
int V_63 ;
if ( strcmp ( V_74 , V_85 ) ) {
return;
}
V_63 = F_240 ( V_562 , V_595 , & V_364 ) ;
if ( V_63 ) {
F_61 ( V_349 L_46
L_47 ,
V_23 -> V_48 -> V_82 , V_23 -> V_322 , - V_63 ) ;
return;
}
V_25 = F_39 ( V_37 ) ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_32 = F_96 ( V_23 -> V_319 ) ;
V_25 -> V_18 = V_364 ;
V_25 -> V_34 = V_41 ;
F_47 ( & V_25 -> V_29 ) ;
return;
}
static int F_243 ( struct V_37 * V_37 , const char * V_74 )
{
const struct V_11 * V_11 = F_77 () ;
return F_125 ( V_11 , V_37 , V_589 ) ;
}
static int F_244 ( struct V_37 * V_37 )
{
const struct V_11 * V_11 = F_77 () ;
return F_125 ( V_11 , V_37 , V_589 ) ;
}
static int F_245 ( struct V_37 * V_37 , const char * V_74 )
{
if ( strcmp ( V_74 , V_85 ) )
return F_229 ( V_37 , V_74 ) ;
return - V_131 ;
}
static int F_246 ( struct V_23 * V_23 , const char * V_74 , void * * V_315 , bool V_603 )
{
T_2 V_595 ;
int error ;
char * V_95 = NULL ;
struct V_24 * V_25 ;
if ( strcmp ( V_74 , V_564 ) )
return - V_83 ;
V_25 = F_36 ( V_23 ) ;
if ( F_231 ( false ) )
error = F_210 ( V_25 -> V_18 , & V_95 ,
& V_595 ) ;
else
error = F_72 ( V_25 -> V_18 , & V_95 , & V_595 ) ;
if ( error )
return error ;
error = V_595 ;
if ( V_603 ) {
* V_315 = V_95 ;
goto V_604;
}
F_54 ( V_95 ) ;
V_604:
return error ;
}
static int F_247 ( struct V_23 * V_23 , const char * V_74 ,
const void * V_562 , T_7 V_595 , int V_87 )
{
struct V_24 * V_25 = F_33 ( V_23 ) ;
T_2 V_364 ;
int V_63 ;
if ( strcmp ( V_74 , V_564 ) )
return - V_83 ;
if ( ! V_562 || ! V_595 )
return - V_131 ;
V_63 = F_235 ( V_562 , V_595 , & V_364 , V_16 ) ;
if ( V_63 )
return V_63 ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_32 = F_96 ( V_23 -> V_319 ) ;
V_25 -> V_18 = V_364 ;
V_25 -> V_34 = V_41 ;
F_47 ( & V_25 -> V_29 ) ;
return 0 ;
}
static int F_248 ( struct V_23 * V_23 , char * V_315 , T_7 V_605 )
{
const int V_96 = sizeof( V_85 ) ;
if ( V_315 && V_96 <= V_605 )
memcpy ( V_315 , V_85 , V_96 ) ;
return V_96 ;
}
static void F_249 ( struct V_23 * V_23 , T_2 * V_606 )
{
struct V_24 * V_25 = F_33 ( V_23 ) ;
* V_606 = V_25 -> V_18 ;
}
static int F_250 ( struct V_37 * V_607 , struct V_11 * * V_138 )
{
T_2 V_18 ;
struct V_14 * V_15 ;
struct V_11 * V_608 = * V_138 ;
if ( V_608 == NULL ) {
V_608 = F_251 () ;
if ( ! V_608 )
return - V_28 ;
}
V_15 = V_608 -> V_20 ;
F_249 ( F_207 ( V_607 ) , & V_18 ) ;
V_15 -> V_362 = V_18 ;
* V_138 = V_608 ;
return 0 ;
}
static int F_252 ( const char * V_74 )
{
if ( strcmp ( V_74 , V_85 ) == 0 )
return 1 ;
return - V_83 ;
}
static int F_253 ( struct V_51 * V_51 , int V_389 )
{
const struct V_11 * V_11 = F_77 () ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
if ( ( V_51 -> V_403 & V_404 ) && ( V_389 & V_396 ) )
V_389 |= V_394 ;
return F_129 ( V_11 , V_51 ,
F_138 ( V_23 -> V_319 , V_389 ) ) ;
}
static int F_254 ( struct V_51 * V_51 , int V_389 )
{
struct V_23 * V_23 = F_128 ( V_51 ) ;
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_24 * V_25 ;
T_2 V_18 = F_26 () ;
if ( ! V_389 )
return 0 ;
V_25 = F_36 ( V_23 ) ;
if ( V_18 == V_53 -> V_18 && V_53 -> V_609 == V_25 -> V_18 &&
V_53 -> V_610 == F_255 () )
return 0 ;
return F_253 ( V_51 , V_389 ) ;
}
static int F_256 ( struct V_51 * V_51 )
{
return F_49 ( V_51 ) ;
}
static void F_257 ( struct V_51 * V_51 )
{
F_50 ( V_51 ) ;
}
static int F_258 ( const struct V_11 * V_11 , struct V_51 * V_51 ,
T_2 V_611 , T_4 V_612 )
{
struct V_338 V_339 ;
struct V_52 * V_53 = V_51 -> V_56 ;
struct V_23 * V_23 = F_128 ( V_51 ) ;
struct V_24 * V_25 ;
struct V_613 V_614 ;
T_2 V_615 = F_20 ( V_11 ) ;
int V_63 ;
T_11 V_616 = V_612 >> 8 ;
T_11 V_617 = V_612 & 0xff ;
V_339 . type = V_618 ;
V_339 . V_344 . V_619 = & V_614 ;
V_339 . V_344 . V_619 -> V_612 = V_612 ;
V_339 . V_344 . V_619 -> V_316 = V_51 -> V_422 ;
if ( V_615 != V_53 -> V_18 ) {
V_63 = F_57 ( V_615 , V_53 -> V_18 ,
V_357 ,
V_358 ,
& V_339 ) ;
if ( V_63 )
goto V_84;
}
if ( F_124 ( F_66 ( V_23 ) ) )
return 0 ;
V_25 = F_36 ( V_23 ) ;
V_63 = F_259 ( V_615 , V_25 -> V_18 , V_25 -> V_32 ,
V_611 , V_616 , V_617 , & V_339 ) ;
V_84:
return V_63 ;
}
static int F_260 ( struct V_51 * V_51 , unsigned int V_612 ,
unsigned long V_620 )
{
const struct V_11 * V_11 = F_77 () ;
int error = 0 ;
switch ( V_612 ) {
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_625 :
error = F_129 ( V_11 , V_51 , V_589 ) ;
break;
case V_626 :
case V_627 :
error = F_129 ( V_11 , V_51 , V_586 ) ;
break;
case V_628 :
case V_629 :
error = F_129 ( V_11 , V_51 , 0 ) ;
break;
case V_630 :
case V_631 :
error = F_117 ( V_11 , V_632 ,
V_350 , true ) ;
break;
default:
error = F_258 ( V_11 , V_51 , V_405 , ( T_4 ) V_612 ) ;
}
return error ;
}
static int F_261 ( struct V_51 * V_51 , unsigned long V_633 , int V_634 )
{
const struct V_11 * V_11 = F_77 () ;
T_2 V_18 = F_20 ( V_11 ) ;
int V_63 = 0 ;
if ( V_635 &&
( V_633 & V_636 ) && ( ! V_51 || F_66 ( F_128 ( V_51 ) ) ||
( ! V_634 && ( V_633 & V_637 ) ) ) ) {
V_63 = F_57 ( V_18 , V_18 , V_426 ,
V_638 , NULL ) ;
if ( V_63 )
goto error;
}
if ( V_51 ) {
T_2 V_342 = V_393 ;
if ( V_634 && ( V_633 & V_637 ) )
V_342 |= V_397 ;
if ( V_633 & V_636 )
V_342 |= V_391 ;
return F_129 ( V_11 , V_51 , V_342 ) ;
}
error:
return V_63 ;
}
static int F_262 ( unsigned long V_639 )
{
int V_63 = 0 ;
if ( V_639 < V_640 ) {
T_2 V_18 = F_26 () ;
V_63 = F_57 ( V_18 , V_18 , V_641 ,
V_642 , NULL ) ;
}
return V_63 ;
}
static int F_263 ( struct V_51 * V_51 , unsigned long V_643 ,
unsigned long V_633 , unsigned long V_87 )
{
struct V_338 V_339 ;
int V_63 ;
if ( V_51 ) {
V_339 . type = V_356 ;
V_339 . V_344 . V_51 = V_51 ;
V_63 = F_122 ( F_77 () , F_128 ( V_51 ) ,
V_644 , & V_339 ) ;
if ( V_63 )
return V_63 ;
}
if ( V_645 )
V_633 = V_643 ;
return F_261 ( V_51 , V_633 ,
( V_87 & V_646 ) == V_647 ) ;
}
static int F_264 ( struct V_648 * V_649 ,
unsigned long V_643 ,
unsigned long V_633 )
{
const struct V_11 * V_11 = F_77 () ;
T_2 V_18 = F_20 ( V_11 ) ;
if ( V_645 )
V_633 = V_643 ;
if ( V_635 &&
( V_633 & V_636 ) && ! ( V_649 -> V_650 & V_651 ) ) {
int V_63 = 0 ;
if ( V_649 -> V_652 >= V_649 -> V_653 -> V_654 &&
V_649 -> V_655 <= V_649 -> V_653 -> V_656 ) {
V_63 = F_57 ( V_18 , V_18 , V_426 ,
V_657 , NULL ) ;
} else if ( ! V_649 -> V_658 &&
( ( V_649 -> V_652 <= V_649 -> V_653 -> V_659 &&
V_649 -> V_655 >= V_649 -> V_653 -> V_659 ) ||
F_265 ( V_649 ) ) ) {
V_63 = F_57 ( V_18 , V_18 , V_426 ,
V_660 , NULL ) ;
} else if ( V_649 -> V_658 && V_649 -> V_661 ) {
V_63 = F_129 ( V_11 , V_649 -> V_658 , V_662 ) ;
}
if ( V_63 )
return V_63 ;
}
return F_261 ( V_649 -> V_658 , V_633 , V_649 -> V_650 & V_663 ) ;
}
static int F_266 ( struct V_51 * V_51 , unsigned int V_612 )
{
const struct V_11 * V_11 = F_77 () ;
return F_129 ( V_11 , V_51 , V_664 ) ;
}
static int F_267 ( struct V_51 * V_51 , unsigned int V_612 ,
unsigned long V_620 )
{
const struct V_11 * V_11 = F_77 () ;
int V_665 = 0 ;
switch ( V_612 ) {
case V_666 :
if ( ( V_51 -> V_403 & V_404 ) && ! ( V_620 & V_404 ) ) {
V_665 = F_129 ( V_11 , V_51 , V_397 ) ;
break;
}
case V_667 :
case V_668 :
case V_669 :
case V_670 :
case V_671 :
case V_672 :
V_665 = F_129 ( V_11 , V_51 , 0 ) ;
break;
case V_673 :
case V_674 :
case V_675 :
case V_676 :
case V_677 :
case V_678 :
#if V_679 == 32
case V_680 :
case V_681 :
case V_682 :
#endif
V_665 = F_129 ( V_11 , V_51 , V_664 ) ;
break;
}
return V_665 ;
}
static void F_268 ( struct V_51 * V_51 )
{
struct V_52 * V_53 ;
V_53 = V_51 -> V_56 ;
V_53 -> V_55 = F_26 () ;
}
static int F_269 ( struct V_21 * V_683 ,
struct V_684 * V_685 , int V_686 )
{
struct V_51 * V_51 ;
T_2 V_18 = F_21 ( V_683 ) ;
T_2 V_327 ;
struct V_52 * V_53 ;
V_51 = F_41 ( V_685 , struct V_51 , V_687 ) ;
V_53 = V_51 -> V_56 ;
if ( ! V_686 )
V_327 = F_116 ( V_688 ) ;
else
V_327 = F_116 ( V_686 ) ;
return F_57 ( V_53 -> V_55 , V_18 ,
V_426 , V_327 , NULL ) ;
}
static int F_270 ( struct V_51 * V_51 )
{
const struct V_11 * V_11 = F_77 () ;
return F_129 ( V_11 , V_51 , F_140 ( V_51 ) ) ;
}
static int F_271 ( struct V_51 * V_51 , const struct V_11 * V_11 )
{
struct V_52 * V_53 ;
struct V_24 * V_25 ;
V_53 = V_51 -> V_56 ;
V_25 = F_36 ( F_128 ( V_51 ) ) ;
V_53 -> V_609 = V_25 -> V_18 ;
V_53 -> V_610 = F_255 () ;
return F_127 ( V_11 , V_51 , F_141 ( V_51 ) ) ;
}
static int F_272 ( struct V_21 * V_22 ,
unsigned long V_689 )
{
T_2 V_18 = F_26 () ;
return F_57 ( V_18 , V_18 , V_426 , V_690 , NULL ) ;
}
static int F_273 ( struct V_11 * V_11 , T_12 V_691 )
{
struct V_14 * V_15 ;
V_15 = F_18 ( sizeof( struct V_14 ) , V_691 ) ;
if ( ! V_15 )
return - V_28 ;
V_11 -> V_20 = V_15 ;
return 0 ;
}
static void F_274 ( struct V_11 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_20 ;
F_73 ( V_11 -> V_20 && ( unsigned long ) V_11 -> V_20 < V_317 ) ;
V_11 -> V_20 = ( void * ) 0x7UL ;
F_54 ( V_15 ) ;
}
static int F_275 ( struct V_11 * V_138 , const struct V_11 * V_137 ,
T_12 V_691 )
{
const struct V_14 * V_468 ;
struct V_14 * V_15 ;
V_468 = V_137 -> V_20 ;
V_15 = F_276 ( V_468 , sizeof( struct V_14 ) , V_691 ) ;
if ( ! V_15 )
return - V_28 ;
V_138 -> V_20 = V_15 ;
return 0 ;
}
static void F_277 ( struct V_11 * V_138 , const struct V_11 * V_137 )
{
const struct V_14 * V_468 = V_137 -> V_20 ;
struct V_14 * V_15 = V_138 -> V_20 ;
* V_15 = * V_468 ;
}
static int F_278 ( struct V_11 * V_138 , T_2 V_606 )
{
struct V_14 * V_15 = V_138 -> V_20 ;
T_2 V_18 = F_26 () ;
int V_692 ;
V_692 = F_57 ( V_18 , V_606 ,
V_693 ,
V_694 ,
NULL ) ;
if ( V_692 == 0 ) {
V_15 -> V_18 = V_606 ;
V_15 -> V_362 = 0 ;
V_15 -> V_481 = 0 ;
V_15 -> V_482 = 0 ;
}
return V_692 ;
}
static int F_279 ( struct V_11 * V_138 , struct V_23 * V_23 )
{
struct V_24 * V_25 = F_36 ( V_23 ) ;
struct V_14 * V_15 = V_138 -> V_20 ;
T_2 V_18 = F_26 () ;
int V_692 ;
V_692 = F_57 ( V_18 , V_25 -> V_18 ,
V_693 ,
V_695 ,
NULL ) ;
if ( V_692 == 0 )
V_15 -> V_362 = V_25 -> V_18 ;
return V_692 ;
}
static int F_280 ( char * V_696 )
{
struct V_338 V_339 ;
V_339 . type = V_697 ;
V_339 . V_344 . V_696 = V_696 ;
return F_57 ( F_26 () , V_19 , V_452 ,
V_698 , & V_339 ) ;
}
static int F_281 ( struct V_51 * V_51 )
{
struct V_338 V_339 ;
struct V_24 * V_25 ;
struct V_52 * V_53 ;
T_2 V_18 = F_26 () ;
int V_63 ;
if ( V_51 == NULL )
return F_57 ( V_18 , V_18 , V_452 ,
V_699 , NULL ) ;
V_339 . type = V_356 ;
V_339 . V_344 . V_51 = V_51 ;
V_53 = V_51 -> V_56 ;
if ( V_18 != V_53 -> V_18 ) {
V_63 = F_57 ( V_18 , V_53 -> V_18 , V_357 , V_358 , & V_339 ) ;
if ( V_63 )
return V_63 ;
}
V_25 = F_36 ( F_128 ( V_51 ) ) ;
return F_57 ( V_18 , V_25 -> V_18 , V_452 ,
V_699 , & V_339 ) ;
}
static int F_282 ( struct V_51 * V_51 ,
enum V_700 V_438 )
{
int V_63 = 0 ;
switch ( V_438 ) {
case V_701 :
V_63 = F_281 ( V_51 ) ;
break;
default:
break;
}
return V_63 ;
}
static int F_283 ( struct V_21 * V_153 , T_13 V_702 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_703 , NULL ) ;
}
static int F_284 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_704 , NULL ) ;
}
static int F_285 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_705 , NULL ) ;
}
static void F_286 ( struct V_21 * V_153 , T_2 * V_606 )
{
* V_606 = F_21 ( V_153 ) ;
}
static int F_287 ( struct V_21 * V_153 , int V_706 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_707 , NULL ) ;
}
static int F_288 ( struct V_21 * V_153 , int V_708 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_707 , NULL ) ;
}
static int F_289 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_709 , NULL ) ;
}
int F_290 ( const struct V_11 * V_11 , const struct V_11 * V_710 ,
unsigned int V_87 )
{
T_2 V_342 = 0 ;
if ( ! V_87 )
return 0 ;
if ( V_87 & V_711 )
V_342 |= V_712 ;
if ( V_87 & V_713 )
V_342 |= V_714 ;
return F_57 ( F_20 ( V_11 ) , F_20 ( V_710 ) ,
V_426 , V_342 , NULL ) ;
}
static int F_291 ( struct V_21 * V_153 , unsigned int V_715 ,
struct V_509 * V_716 )
{
struct V_509 * V_717 = V_153 -> signal -> V_510 + V_715 ;
if ( V_717 -> V_517 != V_716 -> V_517 )
return F_57 ( F_26 () , F_21 ( V_153 ) ,
V_426 , V_712 , NULL ) ;
return 0 ;
}
static int F_292 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_707 , NULL ) ;
}
static int F_293 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_709 , NULL ) ;
}
static int F_294 ( struct V_21 * V_153 )
{
return F_57 ( F_26 () , F_21 ( V_153 ) , V_426 ,
V_707 , NULL ) ;
}
static int F_295 ( struct V_21 * V_153 , struct V_718 * V_719 ,
int V_326 , T_2 V_606 )
{
T_2 V_327 ;
if ( ! V_326 )
V_327 = V_720 ;
else
V_327 = F_116 ( V_326 ) ;
if ( ! V_606 )
V_606 = F_26 () ;
return F_57 ( V_606 , F_21 ( V_153 ) , V_426 , V_327 , NULL ) ;
}
static void F_296 ( struct V_21 * V_153 ,
struct V_23 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_36 ;
T_2 V_18 = F_21 ( V_153 ) ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_32 = F_96 ( V_23 -> V_319 ) ;
V_25 -> V_18 = V_18 ;
V_25 -> V_34 = V_41 ;
F_47 ( & V_25 -> V_29 ) ;
}
static int F_297 ( struct V_721 * V_722 ,
struct V_338 * V_339 , T_11 * V_723 )
{
int V_724 , V_725 , V_692 = - V_98 ;
struct V_726 V_727 , * V_728 ;
V_724 = F_298 ( V_722 ) ;
V_728 = F_299 ( V_722 , V_724 , sizeof( V_727 ) , & V_727 ) ;
if ( V_728 == NULL )
goto V_84;
V_725 = V_728 -> V_729 * 4 ;
if ( V_725 < sizeof( V_727 ) )
goto V_84;
V_339 -> V_344 . V_730 -> V_731 . V_732 = V_728 -> V_732 ;
V_339 -> V_344 . V_730 -> V_731 . V_733 = V_728 -> V_733 ;
V_692 = 0 ;
if ( V_723 )
* V_723 = V_728 -> V_191 ;
switch ( V_728 -> V_191 ) {
case V_193 : {
struct V_734 V_735 , * V_736 ;
if ( F_300 ( V_728 -> V_737 ) & V_738 )
break;
V_724 += V_725 ;
V_736 = F_299 ( V_722 , V_724 , sizeof( V_735 ) , & V_735 ) ;
if ( V_736 == NULL )
break;
V_339 -> V_344 . V_730 -> V_739 = V_736 -> V_740 ;
V_339 -> V_344 . V_730 -> V_741 = V_736 -> V_742 ;
break;
}
case V_194 : {
struct V_743 V_744 , * V_745 ;
if ( F_300 ( V_728 -> V_737 ) & V_738 )
break;
V_724 += V_725 ;
V_745 = F_299 ( V_722 , V_724 , sizeof( V_744 ) , & V_744 ) ;
if ( V_745 == NULL )
break;
V_339 -> V_344 . V_730 -> V_739 = V_745 -> V_740 ;
V_339 -> V_344 . V_730 -> V_741 = V_745 -> V_742 ;
break;
}
case V_746 : {
struct V_747 V_748 , * V_749 ;
if ( F_300 ( V_728 -> V_737 ) & V_738 )
break;
V_724 += V_725 ;
V_749 = F_299 ( V_722 , V_724 , sizeof( V_748 ) , & V_748 ) ;
if ( V_749 == NULL )
break;
V_339 -> V_344 . V_730 -> V_739 = V_749 -> V_750 ;
V_339 -> V_344 . V_730 -> V_741 = V_749 -> V_751 ;
break;
}
default:
break;
}
V_84:
return V_692 ;
}
static int F_301 ( struct V_721 * V_722 ,
struct V_338 * V_339 , T_11 * V_723 )
{
T_11 V_752 ;
int V_692 = - V_98 , V_724 ;
struct V_753 V_754 , * V_755 ;
T_14 V_737 ;
V_724 = F_298 ( V_722 ) ;
V_755 = F_299 ( V_722 , V_724 , sizeof( V_754 ) , & V_754 ) ;
if ( V_755 == NULL )
goto V_84;
V_339 -> V_344 . V_730 -> V_756 . V_732 = V_755 -> V_732 ;
V_339 -> V_344 . V_730 -> V_756 . V_733 = V_755 -> V_733 ;
V_692 = 0 ;
V_752 = V_755 -> V_752 ;
V_724 += sizeof( V_754 ) ;
V_724 = F_302 ( V_722 , V_724 , & V_752 , & V_737 ) ;
if ( V_724 < 0 )
goto V_84;
if ( V_723 )
* V_723 = V_752 ;
switch ( V_752 ) {
case V_193 : {
struct V_734 V_735 , * V_736 ;
V_736 = F_299 ( V_722 , V_724 , sizeof( V_735 ) , & V_735 ) ;
if ( V_736 == NULL )
break;
V_339 -> V_344 . V_730 -> V_739 = V_736 -> V_740 ;
V_339 -> V_344 . V_730 -> V_741 = V_736 -> V_742 ;
break;
}
case V_194 : {
struct V_743 V_744 , * V_745 ;
V_745 = F_299 ( V_722 , V_724 , sizeof( V_744 ) , & V_744 ) ;
if ( V_745 == NULL )
break;
V_339 -> V_344 . V_730 -> V_739 = V_745 -> V_740 ;
V_339 -> V_344 . V_730 -> V_741 = V_745 -> V_742 ;
break;
}
case V_746 : {
struct V_747 V_748 , * V_749 ;
V_749 = F_299 ( V_722 , V_724 , sizeof( V_748 ) , & V_748 ) ;
if ( V_749 == NULL )
break;
V_339 -> V_344 . V_730 -> V_739 = V_749 -> V_750 ;
V_339 -> V_344 . V_730 -> V_741 = V_749 -> V_751 ;
break;
}
default:
break;
}
V_84:
return V_692 ;
}
static int F_303 ( struct V_721 * V_722 , struct V_338 * V_339 ,
char * * V_757 , int V_607 , T_11 * V_723 )
{
char * V_758 ;
int V_692 ;
switch ( V_339 -> V_344 . V_730 -> V_195 ) {
case V_205 :
V_692 = F_297 ( V_722 , V_339 , V_723 ) ;
if ( V_692 )
goto V_759;
V_758 = ( char * ) ( V_607 ? & V_339 -> V_344 . V_730 -> V_731 . V_732 :
& V_339 -> V_344 . V_730 -> V_731 . V_733 ) ;
goto V_760;
#if F_175 ( V_761 )
case V_206 :
V_692 = F_301 ( V_722 , V_339 , V_723 ) ;
if ( V_692 )
goto V_759;
V_758 = ( char * ) ( V_607 ? & V_339 -> V_344 . V_730 -> V_756 . V_732 :
& V_339 -> V_344 . V_730 -> V_756 . V_733 ) ;
goto V_760;
#endif
default:
V_758 = NULL ;
goto V_760;
}
V_759:
F_61 ( V_81
L_48
L_49 ) ;
return V_692 ;
V_760:
if ( V_757 )
* V_757 = V_758 ;
return 0 ;
}
static int F_304 ( struct V_721 * V_722 , T_4 V_195 , T_2 * V_18 )
{
int V_665 ;
T_2 V_762 ;
T_2 V_763 ;
T_2 V_764 ;
V_665 = F_305 ( V_722 , & V_762 ) ;
if ( F_124 ( V_665 ) )
return - V_131 ;
V_665 = F_306 ( V_722 , V_195 , & V_764 , & V_763 ) ;
if ( F_124 ( V_665 ) )
return - V_131 ;
V_665 = F_307 ( V_763 , V_764 , V_762 , V_18 ) ;
if ( F_124 ( V_665 ) ) {
F_61 ( V_81
L_50
L_51 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_308 ( T_2 V_765 , T_2 V_766 , T_2 * V_767 )
{
int V_665 = 0 ;
if ( V_766 != V_768 )
V_665 = F_309 ( V_765 , V_766 , V_767 ) ;
else
* V_767 = V_765 ;
return V_665 ;
}
static int F_310 ( const struct V_14 * V_15 ,
T_4 V_769 , T_2 * V_770 )
{
if ( V_15 -> V_482 > V_768 ) {
* V_770 = V_15 -> V_482 ;
return 0 ;
}
return F_81 ( V_15 -> V_18 , V_15 -> V_18 , V_769 , NULL ,
V_770 ) ;
}
static int F_311 ( struct V_771 * V_772 , T_2 V_352 )
{
struct V_773 * V_774 = V_772 -> V_775 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
if ( V_774 -> V_18 == V_19 )
return 0 ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_772 = V_772 ;
return F_57 ( F_26 () , V_774 -> V_18 , V_774 -> V_32 , V_352 ,
& V_339 ) ;
}
static int F_312 ( int V_195 , int type ,
int V_191 , int V_778 )
{
const struct V_14 * V_15 = F_132 () ;
T_2 V_364 ;
T_4 V_769 ;
int V_63 ;
if ( V_778 )
return 0 ;
V_769 = F_99 ( V_195 , type , V_191 ) ;
V_63 = F_310 ( V_15 , V_769 , & V_364 ) ;
if ( V_63 )
return V_63 ;
return F_57 ( V_15 -> V_18 , V_364 , V_769 , V_779 , NULL ) ;
}
static int F_313 ( struct V_780 * V_771 , int V_195 ,
int type , int V_191 , int V_778 )
{
const struct V_14 * V_15 = F_132 () ;
struct V_24 * V_25 = F_33 ( F_314 ( V_771 ) ) ;
struct V_773 * V_774 ;
T_4 V_32 = F_99 ( V_195 , type , V_191 ) ;
T_2 V_18 = V_19 ;
int V_665 = 0 ;
if ( ! V_778 ) {
V_665 = F_310 ( V_15 , V_32 , & V_18 ) ;
if ( V_665 )
return V_665 ;
}
V_25 -> V_32 = V_32 ;
V_25 -> V_18 = V_18 ;
V_25 -> V_34 = V_41 ;
if ( V_771 -> V_772 ) {
V_774 = V_771 -> V_772 -> V_775 ;
V_774 -> V_32 = V_32 ;
V_774 -> V_18 = V_18 ;
V_665 = F_315 ( V_771 -> V_772 , V_195 ) ;
}
return V_665 ;
}
static int F_316 ( struct V_780 * V_771 , struct V_781 * V_782 , int V_783 )
{
struct V_771 * V_772 = V_771 -> V_772 ;
T_4 V_195 ;
int V_665 ;
V_665 = F_311 ( V_772 , V_784 ) ;
if ( V_665 )
goto V_84;
V_195 = V_772 -> V_785 ;
if ( V_195 == V_205 || V_195 == V_206 ) {
char * V_758 ;
struct V_773 * V_774 = V_772 -> V_775 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
struct V_786 * V_787 = NULL ;
struct V_788 * V_789 = NULL ;
unsigned short V_790 ;
T_2 V_18 , V_791 ;
if ( V_195 == V_205 ) {
if ( V_783 < sizeof( struct V_786 ) ) {
V_665 = - V_98 ;
goto V_84;
}
V_787 = (struct V_786 * ) V_782 ;
V_790 = F_300 ( V_787 -> V_792 ) ;
V_758 = ( char * ) & V_787 -> V_793 . V_794 ;
} else {
if ( V_783 < V_795 ) {
V_665 = - V_98 ;
goto V_84;
}
V_789 = (struct V_788 * ) V_782 ;
V_790 = F_300 ( V_789 -> V_796 ) ;
V_758 = ( char * ) & V_789 -> V_797 . V_798 ;
}
if ( V_790 ) {
int V_799 , V_800 ;
F_317 ( F_318 ( V_772 ) , & V_799 , & V_800 ) ;
if ( V_790 < V_801 ( V_802 ( F_318 ( V_772 ) ), V_799 ) ||
V_790 > V_800 ) {
V_665 = F_319 ( V_772 -> V_803 ,
V_790 , & V_18 ) ;
if ( V_665 )
goto V_84;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_739 = F_320 ( V_790 ) ;
V_339 . V_344 . V_730 -> V_195 = V_195 ;
V_665 = F_57 ( V_774 -> V_18 , V_18 ,
V_774 -> V_32 ,
V_804 , & V_339 ) ;
if ( V_665 )
goto V_84;
}
}
switch ( V_774 -> V_32 ) {
case V_207 :
V_791 = V_805 ;
break;
case V_211 :
V_791 = V_806 ;
break;
case V_216 :
V_791 = V_807 ;
break;
default:
V_791 = V_808 ;
break;
}
V_665 = F_321 ( V_758 , V_195 , & V_18 ) ;
if ( V_665 )
goto V_84;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_739 = F_320 ( V_790 ) ;
V_339 . V_344 . V_730 -> V_195 = V_195 ;
if ( V_195 == V_205 )
V_339 . V_344 . V_730 -> V_731 . V_732 = V_787 -> V_793 . V_794 ;
else
V_339 . V_344 . V_730 -> V_756 . V_732 = V_789 -> V_797 ;
V_665 = F_57 ( V_774 -> V_18 , V_18 ,
V_774 -> V_32 , V_791 , & V_339 ) ;
if ( V_665 )
goto V_84;
}
V_84:
return V_665 ;
}
static int F_322 ( struct V_780 * V_771 , struct V_781 * V_782 , int V_783 )
{
struct V_771 * V_772 = V_771 -> V_772 ;
struct V_773 * V_774 = V_772 -> V_775 ;
int V_665 ;
V_665 = F_311 ( V_772 , V_809 ) ;
if ( V_665 )
return V_665 ;
if ( V_774 -> V_32 == V_207 ||
V_774 -> V_32 == V_216 ) {
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
struct V_786 * V_787 = NULL ;
struct V_788 * V_789 = NULL ;
unsigned short V_790 ;
T_2 V_18 , V_327 ;
if ( V_772 -> V_785 == V_205 ) {
V_787 = (struct V_786 * ) V_782 ;
if ( V_783 < sizeof( struct V_786 ) )
return - V_98 ;
V_790 = F_300 ( V_787 -> V_792 ) ;
} else {
V_789 = (struct V_788 * ) V_782 ;
if ( V_783 < V_795 )
return - V_98 ;
V_790 = F_300 ( V_789 -> V_796 ) ;
}
V_665 = F_319 ( V_772 -> V_803 , V_790 , & V_18 ) ;
if ( V_665 )
goto V_84;
V_327 = ( V_774 -> V_32 == V_207 ) ?
V_810 : V_811 ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_741 = F_320 ( V_790 ) ;
V_339 . V_344 . V_730 -> V_195 = V_772 -> V_785 ;
V_665 = F_57 ( V_774 -> V_18 , V_18 , V_774 -> V_32 , V_327 , & V_339 ) ;
if ( V_665 )
goto V_84;
}
V_665 = F_323 ( V_772 , V_782 ) ;
V_84:
return V_665 ;
}
static int F_324 ( struct V_780 * V_771 , int V_812 )
{
return F_311 ( V_771 -> V_772 , V_813 ) ;
}
static int F_325 ( struct V_780 * V_771 , struct V_780 * V_814 )
{
int V_665 ;
struct V_24 * V_25 ;
struct V_24 * V_150 ;
T_4 V_32 ;
T_2 V_18 ;
V_665 = F_311 ( V_771 -> V_772 , V_815 ) ;
if ( V_665 )
return V_665 ;
V_25 = F_33 ( F_314 ( V_771 ) ) ;
F_45 ( & V_25 -> V_29 ) ;
V_32 = V_25 -> V_32 ;
V_18 = V_25 -> V_18 ;
F_47 ( & V_25 -> V_29 ) ;
V_150 = F_33 ( F_314 ( V_814 ) ) ;
V_150 -> V_32 = V_32 ;
V_150 -> V_18 = V_18 ;
V_150 -> V_34 = V_41 ;
return 0 ;
}
static int F_326 ( struct V_780 * V_771 , struct V_816 * V_817 ,
int V_595 )
{
return F_311 ( V_771 -> V_772 , V_818 ) ;
}
static int F_327 ( struct V_780 * V_771 , struct V_816 * V_817 ,
int V_595 , int V_87 )
{
return F_311 ( V_771 -> V_772 , V_819 ) ;
}
static int F_328 ( struct V_780 * V_771 )
{
return F_311 ( V_771 -> V_772 , V_820 ) ;
}
static int F_329 ( struct V_780 * V_771 )
{
return F_311 ( V_771 -> V_772 , V_820 ) ;
}
static int F_330 ( struct V_780 * V_771 , int V_821 , int V_822 )
{
int V_665 ;
V_665 = F_311 ( V_771 -> V_772 , V_823 ) ;
if ( V_665 )
return V_665 ;
return F_331 ( V_771 , V_821 , V_822 ) ;
}
static int F_332 ( struct V_780 * V_771 , int V_821 ,
int V_822 )
{
return F_311 ( V_771 -> V_772 , V_824 ) ;
}
static int F_333 ( struct V_780 * V_771 , int V_825 )
{
return F_311 ( V_771 -> V_772 , V_826 ) ;
}
static int F_334 ( struct V_771 * V_771 ,
struct V_771 * V_827 ,
struct V_771 * V_828 )
{
struct V_773 * V_829 = V_771 -> V_775 ;
struct V_773 * V_830 = V_827 -> V_775 ;
struct V_773 * V_831 = V_828 -> V_775 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
int V_665 ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_772 = V_827 ;
V_665 = F_57 ( V_829 -> V_18 , V_830 -> V_18 ,
V_830 -> V_32 ,
V_832 , & V_339 ) ;
if ( V_665 )
return V_665 ;
V_831 -> V_833 = V_829 -> V_18 ;
V_665 = F_309 ( V_830 -> V_18 , V_829 -> V_18 ,
& V_831 -> V_18 ) ;
if ( V_665 )
return V_665 ;
V_829 -> V_833 = V_831 -> V_18 ;
return 0 ;
}
static int F_335 ( struct V_780 * V_771 ,
struct V_780 * V_827 )
{
struct V_773 * V_834 = V_771 -> V_772 -> V_775 ;
struct V_773 * V_835 = V_827 -> V_772 -> V_775 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_772 = V_827 -> V_772 ;
return F_57 ( V_834 -> V_18 , V_835 -> V_18 , V_835 -> V_32 , V_836 ,
& V_339 ) ;
}
static int F_336 ( struct V_730 * V_436 , int V_837 ,
char * V_758 , T_4 V_195 , T_2 V_833 ,
struct V_338 * V_339 )
{
int V_665 ;
T_2 V_838 ;
T_2 V_839 ;
V_665 = F_337 ( V_436 , V_837 , & V_838 ) ;
if ( V_665 )
return V_665 ;
V_665 = F_57 ( V_833 , V_838 ,
V_840 , V_841 , V_339 ) ;
if ( V_665 )
return V_665 ;
V_665 = F_321 ( V_758 , V_195 , & V_839 ) ;
if ( V_665 )
return V_665 ;
return F_57 ( V_833 , V_839 ,
V_842 , V_843 , V_339 ) ;
}
static int F_338 ( struct V_771 * V_772 , struct V_721 * V_722 ,
T_4 V_195 )
{
int V_665 = 0 ;
struct V_773 * V_774 = V_772 -> V_775 ;
T_2 V_765 = V_774 -> V_18 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
char * V_758 ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_844 = V_722 -> V_845 ;
V_339 . V_344 . V_730 -> V_195 = V_195 ;
V_665 = F_303 ( V_722 , & V_339 , & V_758 , 1 , NULL ) ;
if ( V_665 )
return V_665 ;
if ( F_4 () ) {
V_665 = F_57 ( V_765 , V_722 -> V_846 , V_847 ,
V_848 , & V_339 ) ;
if ( V_665 )
return V_665 ;
}
V_665 = F_339 ( V_774 , V_722 , V_195 , & V_339 ) ;
if ( V_665 )
return V_665 ;
V_665 = F_340 ( V_774 -> V_18 , V_722 , & V_339 ) ;
return V_665 ;
}
static int F_341 ( struct V_771 * V_772 , struct V_721 * V_722 )
{
int V_665 ;
struct V_773 * V_774 = V_772 -> V_775 ;
T_4 V_195 = V_772 -> V_785 ;
T_2 V_765 = V_774 -> V_18 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
char * V_758 ;
T_11 V_849 ;
T_11 V_850 ;
if ( V_195 != V_205 && V_195 != V_206 )
return 0 ;
if ( V_195 == V_206 && V_722 -> V_191 == F_320 ( V_851 ) )
V_195 = V_205 ;
if ( ! V_852 )
return F_338 ( V_772 , V_722 , V_195 ) ;
V_849 = F_4 () ;
V_850 = F_6 () ;
if ( ! V_849 && ! V_850 )
return 0 ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_844 = V_722 -> V_845 ;
V_339 . V_344 . V_730 -> V_195 = V_195 ;
V_665 = F_303 ( V_722 , & V_339 , & V_758 , 1 , NULL ) ;
if ( V_665 )
return V_665 ;
if ( V_850 ) {
T_2 V_833 ;
V_665 = F_304 ( V_722 , V_195 , & V_833 ) ;
if ( V_665 )
return V_665 ;
V_665 = F_336 ( F_318 ( V_772 ) , V_722 -> V_845 ,
V_758 , V_195 , V_833 , & V_339 ) ;
if ( V_665 ) {
F_342 ( V_722 , V_195 , V_665 , 0 ) ;
return V_665 ;
}
V_665 = F_57 ( V_765 , V_833 , V_853 ,
V_854 , & V_339 ) ;
if ( V_665 ) {
F_342 ( V_722 , V_195 , V_665 , 0 ) ;
return V_665 ;
}
}
if ( V_849 ) {
V_665 = F_57 ( V_765 , V_722 -> V_846 , V_847 ,
V_848 , & V_339 ) ;
if ( V_665 )
return V_665 ;
}
return V_665 ;
}
static int F_343 ( struct V_780 * V_771 , char T_15 * V_855 ,
int T_15 * V_856 , unsigned V_96 )
{
int V_665 = 0 ;
char * V_857 ;
T_2 V_858 ;
struct V_773 * V_774 = V_771 -> V_772 -> V_775 ;
T_2 V_833 = V_768 ;
if ( V_774 -> V_32 == V_201 ||
V_774 -> V_32 == V_207 )
V_833 = V_774 -> V_833 ;
if ( V_833 == V_768 )
return - V_859 ;
V_665 = F_72 ( V_833 , & V_857 , & V_858 ) ;
if ( V_665 )
return V_665 ;
if ( V_858 > V_96 ) {
V_665 = - V_321 ;
goto V_860;
}
if ( F_344 ( V_855 , V_857 , V_858 ) )
V_665 = - V_861 ;
V_860:
if ( F_345 ( V_858 , V_856 ) )
V_665 = - V_861 ;
F_54 ( V_857 ) ;
return V_665 ;
}
static int F_346 ( struct V_780 * V_771 , struct V_721 * V_722 , T_2 * V_606 )
{
T_2 V_862 = V_768 ;
T_4 V_195 ;
struct V_24 * V_25 ;
if ( V_722 && V_722 -> V_191 == F_320 ( V_851 ) )
V_195 = V_205 ;
else if ( V_722 && V_722 -> V_191 == F_320 ( V_863 ) )
V_195 = V_206 ;
else if ( V_771 )
V_195 = V_771 -> V_772 -> V_785 ;
else
goto V_84;
if ( V_771 && V_195 == V_198 ) {
V_25 = F_33 ( F_314 ( V_771 ) ) ;
V_862 = V_25 -> V_18 ;
} else if ( V_722 )
F_304 ( V_722 , V_195 , & V_862 ) ;
V_84:
* V_606 = V_862 ;
if ( V_862 == V_768 )
return - V_98 ;
return 0 ;
}
static int F_347 ( struct V_771 * V_772 , int V_195 , T_12 V_864 )
{
struct V_773 * V_774 ;
V_774 = F_18 ( sizeof( * V_774 ) , V_864 ) ;
if ( ! V_774 )
return - V_28 ;
V_774 -> V_833 = V_31 ;
V_774 -> V_18 = V_31 ;
V_774 -> V_32 = V_312 ;
F_348 ( V_774 ) ;
V_772 -> V_775 = V_774 ;
return 0 ;
}
static void F_349 ( struct V_771 * V_772 )
{
struct V_773 * V_774 = V_772 -> V_775 ;
V_772 -> V_775 = NULL ;
F_350 ( V_774 ) ;
F_54 ( V_774 ) ;
}
static void F_351 ( const struct V_771 * V_772 , struct V_771 * V_828 )
{
struct V_773 * V_774 = V_772 -> V_775 ;
struct V_773 * V_865 = V_828 -> V_775 ;
V_865 -> V_18 = V_774 -> V_18 ;
V_865 -> V_833 = V_774 -> V_833 ;
V_865 -> V_32 = V_774 -> V_32 ;
F_348 ( V_865 ) ;
}
static void F_352 ( struct V_771 * V_772 , T_2 * V_606 )
{
if ( ! V_772 )
* V_606 = V_866 ;
else {
struct V_773 * V_774 = V_772 -> V_775 ;
* V_606 = V_774 -> V_18 ;
}
}
static void F_353 ( struct V_771 * V_772 , struct V_780 * V_428 )
{
struct V_24 * V_25 =
F_33 ( F_314 ( V_428 ) ) ;
struct V_773 * V_774 = V_772 -> V_775 ;
if ( V_772 -> V_785 == V_205 || V_772 -> V_785 == V_206 ||
V_772 -> V_785 == V_198 )
V_25 -> V_18 = V_774 -> V_18 ;
V_774 -> V_32 = V_25 -> V_32 ;
}
static int F_354 ( struct V_771 * V_772 , struct V_721 * V_722 ,
struct V_867 * V_868 )
{
struct V_773 * V_774 = V_772 -> V_775 ;
int V_665 ;
T_4 V_195 = V_868 -> V_869 -> V_195 ;
T_2 V_870 ;
T_2 V_871 ;
V_665 = F_304 ( V_722 , V_195 , & V_871 ) ;
if ( V_665 )
return V_665 ;
V_665 = F_308 ( V_774 -> V_18 , V_871 , & V_870 ) ;
if ( V_665 )
return V_665 ;
V_868 -> V_606 = V_870 ;
V_868 -> V_862 = V_871 ;
return F_355 ( V_868 , V_195 ) ;
}
static void F_356 ( struct V_771 * V_828 ,
const struct V_867 * V_868 )
{
struct V_773 * V_865 = V_828 -> V_775 ;
V_865 -> V_18 = V_868 -> V_606 ;
V_865 -> V_833 = V_868 -> V_862 ;
F_357 ( V_828 , V_868 -> V_869 -> V_195 ) ;
}
static void F_358 ( struct V_771 * V_772 , struct V_721 * V_722 )
{
T_4 V_195 = V_772 -> V_785 ;
struct V_773 * V_774 = V_772 -> V_775 ;
if ( V_195 == V_206 && V_722 -> V_191 == F_320 ( V_851 ) )
V_195 = V_205 ;
F_304 ( V_722 , V_195 , & V_774 -> V_833 ) ;
}
static int F_359 ( T_2 V_18 )
{
const struct V_14 * V_872 ;
T_2 V_873 ;
V_872 = F_132 () ;
V_873 = V_872 -> V_18 ;
return F_57 ( V_873 , V_18 , V_847 , V_874 , NULL ) ;
}
static void F_360 ( void )
{
F_361 ( & V_7 ) ;
}
static void F_362 ( void )
{
F_363 ( & V_7 ) ;
}
static void F_364 ( const struct V_867 * V_868 ,
struct V_875 * V_876 )
{
V_876 -> V_877 = V_868 -> V_606 ;
}
static int F_365 ( void * * V_20 )
{
struct V_878 * V_879 ;
V_879 = F_18 ( sizeof( * V_879 ) , V_16 ) ;
if ( ! V_879 )
return - V_28 ;
V_879 -> V_18 = F_26 () ;
* V_20 = V_879 ;
return 0 ;
}
static void F_366 ( void * V_20 )
{
F_54 ( V_20 ) ;
}
static int F_367 ( void )
{
T_2 V_18 = F_26 () ;
return F_57 ( V_18 , V_18 , V_880 , V_881 ,
NULL ) ;
}
static int F_368 ( void * V_20 )
{
struct V_878 * V_879 = V_20 ;
return F_57 ( F_26 () , V_879 -> V_18 , V_880 ,
V_882 , NULL ) ;
}
static int F_369 ( struct V_771 * V_772 , void * V_20 )
{
struct V_878 * V_879 = V_20 ;
struct V_773 * V_774 = V_772 -> V_775 ;
V_774 -> V_18 = V_879 -> V_18 ;
V_774 -> V_32 = V_880 ;
return 0 ;
}
static int F_370 ( void * V_20 )
{
struct V_878 * V_879 = V_20 ;
T_2 V_18 = F_26 () ;
int V_665 ;
V_665 = F_57 ( V_18 , V_879 -> V_18 , V_880 ,
V_883 , NULL ) ;
if ( V_665 )
return V_665 ;
V_665 = F_57 ( V_18 , V_18 , V_880 ,
V_884 , NULL ) ;
if ( V_665 )
return V_665 ;
V_879 -> V_18 = V_18 ;
return 0 ;
}
static int F_371 ( struct V_771 * V_772 , struct V_721 * V_722 )
{
int V_665 = 0 ;
T_2 V_327 ;
struct V_885 * V_886 ;
struct V_773 * V_774 = V_772 -> V_775 ;
if ( V_722 -> V_96 < V_887 ) {
V_665 = - V_98 ;
goto V_84;
}
V_886 = F_372 ( V_722 ) ;
V_665 = F_373 ( V_774 -> V_32 , V_886 -> V_888 , & V_327 ) ;
if ( V_665 ) {
if ( V_665 == - V_98 ) {
F_374 ( L_52
L_53
L_54 ,
V_772 -> V_803 , V_886 -> V_888 ,
V_889 [ V_774 -> V_32 - 1 ] . V_74 ,
F_375 ( V_12 ) , V_12 -> V_890 ) ;
if ( ! V_3 || F_376 () )
V_665 = 0 ;
}
if ( V_665 == - V_891 )
V_665 = 0 ;
goto V_84;
}
V_665 = F_311 ( V_772 , V_327 ) ;
V_84:
return V_665 ;
}
static unsigned int F_377 ( struct V_721 * V_722 ,
const struct V_892 * V_893 ,
T_4 V_195 )
{
int V_665 ;
char * V_758 ;
T_2 V_833 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
T_11 V_849 ;
T_11 V_894 ;
T_11 V_850 ;
if ( ! V_852 )
return V_895 ;
V_849 = F_4 () ;
V_894 = F_7 () ;
V_850 = F_6 () ;
if ( ! V_849 && ! V_850 )
return V_895 ;
if ( F_304 ( V_722 , V_195 , & V_833 ) != 0 )
return V_896 ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_844 = V_893 -> V_837 ;
V_339 . V_344 . V_730 -> V_195 = V_195 ;
if ( F_303 ( V_722 , & V_339 , & V_758 , 1 , NULL ) != 0 )
return V_896 ;
if ( V_850 ) {
V_665 = F_336 ( F_378 ( V_893 ) , V_893 -> V_837 ,
V_758 , V_195 , V_833 , & V_339 ) ;
if ( V_665 ) {
F_342 ( V_722 , V_195 , V_665 , 1 ) ;
return V_896 ;
}
}
if ( V_849 )
if ( F_57 ( V_833 , V_722 -> V_846 ,
V_847 , V_897 , & V_339 ) )
return V_896 ;
if ( V_894 )
if ( F_379 ( V_722 , V_195 , V_833 ) != 0 )
return V_896 ;
return V_895 ;
}
static unsigned int F_380 ( void * V_898 ,
struct V_721 * V_722 ,
const struct V_899 * V_900 )
{
return F_377 ( V_722 , V_900 -> V_901 , V_205 ) ;
}
static unsigned int F_381 ( void * V_898 ,
struct V_721 * V_722 ,
const struct V_899 * V_900 )
{
return F_377 ( V_722 , V_900 -> V_901 , V_206 ) ;
}
static unsigned int F_382 ( struct V_721 * V_722 ,
T_4 V_195 )
{
struct V_771 * V_772 ;
T_2 V_18 ;
if ( ! F_7 () )
return V_895 ;
V_772 = V_722 -> V_772 ;
if ( V_772 ) {
struct V_773 * V_774 ;
if ( F_383 ( V_772 ) )
return V_895 ;
V_774 = V_772 -> V_775 ;
V_18 = V_774 -> V_18 ;
} else
V_18 = V_19 ;
if ( F_379 ( V_722 , V_195 , V_18 ) != 0 )
return V_896 ;
return V_895 ;
}
static unsigned int F_384 ( void * V_898 ,
struct V_721 * V_722 ,
const struct V_899 * V_900 )
{
return F_382 ( V_722 , V_205 ) ;
}
static unsigned int F_385 ( void * V_898 ,
struct V_721 * V_722 ,
const struct V_899 * V_900 )
{
return F_382 ( V_722 , V_206 ) ;
}
static unsigned int F_386 ( struct V_721 * V_722 ,
int V_837 ,
T_4 V_195 )
{
struct V_771 * V_772 = F_387 ( V_722 ) ;
struct V_773 * V_774 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
char * V_758 ;
T_11 V_723 ;
if ( V_772 == NULL )
return V_895 ;
V_774 = V_772 -> V_775 ;
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_844 = V_837 ;
V_339 . V_344 . V_730 -> V_195 = V_195 ;
if ( F_303 ( V_722 , & V_339 , & V_758 , 0 , & V_723 ) )
return V_896 ;
if ( F_4 () )
if ( F_57 ( V_774 -> V_18 , V_722 -> V_846 ,
V_847 , V_902 , & V_339 ) )
return F_388 ( - V_903 ) ;
if ( F_389 ( V_774 -> V_18 , V_722 , & V_339 , V_723 ) )
return F_388 ( - V_903 ) ;
return V_895 ;
}
static unsigned int F_390 ( struct V_721 * V_722 ,
const struct V_892 * V_904 ,
T_4 V_195 )
{
T_2 V_905 ;
T_2 V_833 ;
int V_837 = V_904 -> V_837 ;
struct V_771 * V_772 ;
struct V_338 V_339 ;
struct V_776 V_730 = { 0 ,} ;
char * V_758 ;
T_11 V_849 ;
T_11 V_850 ;
if ( ! V_852 )
return F_386 ( V_722 , V_837 , V_195 ) ;
V_849 = F_4 () ;
V_850 = F_6 () ;
if ( ! V_849 && ! V_850 )
return V_895 ;
V_772 = F_387 ( V_722 ) ;
#ifdef F_391
if ( F_392 ( V_722 ) != NULL && F_392 ( V_722 ) -> V_906 != NULL &&
! ( V_772 && F_383 ( V_772 ) ) )
return V_895 ;
#endif
if ( V_772 == NULL ) {
if ( V_722 -> V_845 ) {
V_905 = V_907 ;
if ( F_304 ( V_722 , V_195 , & V_833 ) )
return V_896 ;
} else {
V_905 = V_902 ;
V_833 = V_19 ;
}
} else if ( F_383 ( V_772 ) ) {
T_2 V_766 ;
struct V_773 * V_774 ;
V_774 = V_772 -> V_775 ;
if ( F_304 ( V_722 , V_195 , & V_766 ) )
return V_896 ;
if ( V_766 == V_768 ) {
switch ( V_195 ) {
case V_205 :
if ( F_393 ( V_722 ) -> V_87 & V_908 )
return V_895 ;
break;
case V_206 :
if ( F_394 ( V_722 ) -> V_87 & V_909 )
return V_895 ;
break;
default:
return F_388 ( - V_903 ) ;
}
}
if ( F_308 ( V_774 -> V_18 , V_766 , & V_833 ) )
return V_896 ;
V_905 = V_902 ;
} else {
struct V_773 * V_774 = V_772 -> V_775 ;
V_833 = V_774 -> V_18 ;
V_905 = V_902 ;
}
V_339 . type = V_777 ;
V_339 . V_344 . V_730 = & V_730 ;
V_339 . V_344 . V_730 -> V_844 = V_837 ;
V_339 . V_344 . V_730 -> V_195 = V_195 ;
if ( F_303 ( V_722 , & V_339 , & V_758 , 0 , NULL ) )
return V_896 ;
if ( V_849 )
if ( F_57 ( V_833 , V_722 -> V_846 ,
V_847 , V_905 , & V_339 ) )
return F_388 ( - V_903 ) ;
if ( V_850 ) {
T_2 V_838 ;
T_2 V_839 ;
if ( F_337 ( F_378 ( V_904 ) , V_837 , & V_838 ) )
return V_896 ;
if ( F_57 ( V_833 , V_838 ,
V_840 , V_910 , & V_339 ) )
return F_388 ( - V_903 ) ;
if ( F_321 ( V_758 , V_195 , & V_839 ) )
return V_896 ;
if ( F_57 ( V_833 , V_839 ,
V_842 , V_911 , & V_339 ) )
return F_388 ( - V_903 ) ;
}
return V_895 ;
}
static unsigned int F_395 ( void * V_898 ,
struct V_721 * V_722 ,
const struct V_899 * V_900 )
{
return F_390 ( V_722 , V_900 -> V_84 , V_205 ) ;
}
static unsigned int F_396 ( void * V_898 ,
struct V_721 * V_722 ,
const struct V_899 * V_900 )
{
return F_390 ( V_722 , V_900 -> V_84 , V_206 ) ;
}
static int F_397 ( struct V_771 * V_772 , struct V_721 * V_722 )
{
return F_371 ( V_772 , V_722 ) ;
}
static int F_398 ( struct V_912 * V_327 ,
T_4 V_32 )
{
struct V_913 * V_25 ;
V_25 = F_18 ( sizeof( struct V_913 ) , V_16 ) ;
if ( ! V_25 )
return - V_28 ;
V_25 -> V_32 = V_32 ;
V_25 -> V_18 = F_26 () ;
V_327 -> V_20 = V_25 ;
return 0 ;
}
static void F_399 ( struct V_912 * V_327 )
{
struct V_913 * V_25 = V_327 -> V_20 ;
V_327 -> V_20 = NULL ;
F_54 ( V_25 ) ;
}
static int F_400 ( struct V_914 * V_817 )
{
struct V_915 * V_916 ;
V_916 = F_18 ( sizeof( struct V_915 ) , V_16 ) ;
if ( ! V_916 )
return - V_28 ;
V_916 -> V_18 = V_31 ;
V_817 -> V_20 = V_916 ;
return 0 ;
}
static void F_401 ( struct V_914 * V_817 )
{
struct V_915 * V_916 = V_817 -> V_20 ;
V_817 -> V_20 = NULL ;
F_54 ( V_916 ) ;
}
static int F_402 ( struct V_912 * V_917 ,
T_2 V_352 )
{
struct V_913 * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
V_25 = V_917 -> V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_917 -> V_920 ;
return F_57 ( V_18 , V_25 -> V_18 , V_25 -> V_32 , V_352 , & V_339 ) ;
}
static int F_403 ( struct V_914 * V_817 )
{
return F_400 ( V_817 ) ;
}
static void F_404 ( struct V_914 * V_817 )
{
F_401 ( V_817 ) ;
}
static int F_405 ( struct V_921 * V_922 )
{
struct V_913 * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_63 = F_398 ( & V_922 -> V_923 , V_924 ) ;
if ( V_63 )
return V_63 ;
V_25 = V_922 -> V_923 . V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_922 -> V_923 . V_920 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_924 ,
V_925 , & V_339 ) ;
if ( V_63 ) {
F_399 ( & V_922 -> V_923 ) ;
return V_63 ;
}
return 0 ;
}
static void F_406 ( struct V_921 * V_922 )
{
F_399 ( & V_922 -> V_923 ) ;
}
static int F_407 ( struct V_921 * V_922 , int V_926 )
{
struct V_913 * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
V_25 = V_922 -> V_923 . V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_922 -> V_923 . V_920 ;
return F_57 ( V_18 , V_25 -> V_18 , V_924 ,
V_927 , & V_339 ) ;
}
static int F_408 ( struct V_921 * V_922 , int V_612 )
{
int V_665 ;
int V_352 ;
switch ( V_612 ) {
case V_928 :
case V_929 :
return F_57 ( F_26 () , V_19 ,
V_452 , V_930 , NULL ) ;
case V_931 :
case V_932 :
V_352 = V_933 | V_927 ;
break;
case V_934 :
V_352 = V_935 ;
break;
case V_936 :
V_352 = V_937 ;
break;
default:
return 0 ;
}
V_665 = F_402 ( & V_922 -> V_923 , V_352 ) ;
return V_665 ;
}
static int F_409 ( struct V_921 * V_922 , struct V_914 * V_817 , int V_926 )
{
struct V_913 * V_25 ;
struct V_915 * V_916 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_25 = V_922 -> V_923 . V_20 ;
V_916 = V_817 -> V_20 ;
if ( V_916 -> V_18 == V_31 ) {
V_63 = F_81 ( V_18 , V_25 -> V_18 , V_938 ,
NULL , & V_916 -> V_18 ) ;
if ( V_63 )
return V_63 ;
}
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_922 -> V_923 . V_920 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_924 ,
V_939 , & V_339 ) ;
if ( ! V_63 )
V_63 = F_57 ( V_18 , V_916 -> V_18 , V_938 ,
V_940 , & V_339 ) ;
if ( ! V_63 )
V_63 = F_57 ( V_916 -> V_18 , V_25 -> V_18 , V_924 ,
V_941 , & V_339 ) ;
return V_63 ;
}
static int F_410 ( struct V_921 * V_922 , struct V_914 * V_817 ,
struct V_21 * V_429 ,
long type , int V_176 )
{
struct V_913 * V_25 ;
struct V_915 * V_916 ;
struct V_338 V_339 ;
T_2 V_18 = F_21 ( V_429 ) ;
int V_63 ;
V_25 = V_922 -> V_923 . V_20 ;
V_916 = V_817 -> V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_922 -> V_923 . V_920 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 ,
V_924 , V_942 , & V_339 ) ;
if ( ! V_63 )
V_63 = F_57 ( V_18 , V_916 -> V_18 ,
V_938 , V_943 , & V_339 ) ;
return V_63 ;
}
static int F_411 ( struct V_944 * V_945 )
{
struct V_913 * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_63 = F_398 ( & V_945 -> V_946 , V_947 ) ;
if ( V_63 )
return V_63 ;
V_25 = V_945 -> V_946 . V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_945 -> V_946 . V_920 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_947 ,
V_948 , & V_339 ) ;
if ( V_63 ) {
F_399 ( & V_945 -> V_946 ) ;
return V_63 ;
}
return 0 ;
}
static void F_412 ( struct V_944 * V_945 )
{
F_399 ( & V_945 -> V_946 ) ;
}
static int F_413 ( struct V_944 * V_945 , int V_949 )
{
struct V_913 * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
V_25 = V_945 -> V_946 . V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_945 -> V_946 . V_920 ;
return F_57 ( V_18 , V_25 -> V_18 , V_947 ,
V_950 , & V_339 ) ;
}
static int F_414 ( struct V_944 * V_945 , int V_612 )
{
int V_352 ;
int V_665 ;
switch ( V_612 ) {
case V_928 :
case V_951 :
return F_57 ( F_26 () , V_19 ,
V_452 , V_930 , NULL ) ;
case V_931 :
case V_952 :
V_352 = V_953 | V_950 ;
break;
case V_934 :
V_352 = V_954 ;
break;
case V_955 :
case V_956 :
V_352 = V_957 ;
break;
case V_936 :
V_352 = V_958 ;
break;
default:
return 0 ;
}
V_665 = F_402 ( & V_945 -> V_946 , V_352 ) ;
return V_665 ;
}
static int F_415 ( struct V_944 * V_945 ,
char T_15 * V_959 , int V_949 )
{
T_2 V_352 ;
if ( V_949 & V_960 )
V_352 = V_961 ;
else
V_352 = V_961 | V_962 ;
return F_402 ( & V_945 -> V_946 , V_352 ) ;
}
static int F_416 ( struct V_963 * V_964 )
{
struct V_913 * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
int V_63 ;
V_63 = F_398 ( & V_964 -> V_965 , V_966 ) ;
if ( V_63 )
return V_63 ;
V_25 = V_964 -> V_965 . V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_964 -> V_965 . V_920 ;
V_63 = F_57 ( V_18 , V_25 -> V_18 , V_966 ,
V_967 , & V_339 ) ;
if ( V_63 ) {
F_399 ( & V_964 -> V_965 ) ;
return V_63 ;
}
return 0 ;
}
static void F_417 ( struct V_963 * V_964 )
{
F_399 ( & V_964 -> V_965 ) ;
}
static int F_418 ( struct V_963 * V_964 , int V_968 )
{
struct V_913 * V_25 ;
struct V_338 V_339 ;
T_2 V_18 = F_26 () ;
V_25 = V_964 -> V_965 . V_20 ;
V_339 . type = V_918 ;
V_339 . V_344 . V_919 = V_964 -> V_965 . V_920 ;
return F_57 ( V_18 , V_25 -> V_18 , V_966 ,
V_969 , & V_339 ) ;
}
static int F_419 ( struct V_963 * V_964 , int V_612 )
{
int V_665 ;
T_2 V_352 ;
switch ( V_612 ) {
case V_928 :
case V_970 :
return F_57 ( F_26 () , V_19 ,
V_452 , V_930 , NULL ) ;
case V_971 :
case V_972 :
case V_973 :
V_352 = V_974 ;
break;
case V_975 :
case V_976 :
V_352 = V_977 ;
break;
case V_978 :
case V_979 :
V_352 = V_980 ;
break;
case V_936 :
V_352 = V_981 ;
break;
case V_934 :
V_352 = V_982 ;
break;
case V_931 :
case V_983 :
V_352 = V_974 | V_969 ;
break;
default:
return 0 ;
}
V_665 = F_402 ( & V_964 -> V_965 , V_352 ) ;
return V_665 ;
}
static int F_420 ( struct V_963 * V_964 ,
struct V_984 * V_985 , unsigned V_986 , int V_987 )
{
T_2 V_352 ;
if ( V_987 )
V_352 = V_977 | V_980 ;
else
V_352 = V_977 ;
return F_402 ( & V_964 -> V_965 , V_352 ) ;
}
static int F_421 ( struct V_912 * V_988 , short V_110 )
{
T_2 V_342 = 0 ;
V_342 = 0 ;
if ( V_110 & V_989 )
V_342 |= V_990 ;
if ( V_110 & V_991 )
V_342 |= V_992 ;
if ( V_342 == 0 )
return 0 ;
return F_402 ( V_988 , V_342 ) ;
}
static void F_422 ( struct V_912 * V_988 , T_2 * V_606 )
{
struct V_913 * V_25 = V_988 -> V_20 ;
* V_606 = V_25 -> V_18 ;
}
static void F_423 ( struct V_37 * V_37 , struct V_23 * V_23 )
{
if ( V_23 )
F_32 ( V_23 , V_37 ) ;
}
static int F_424 ( struct V_21 * V_153 ,
char * V_74 , char * * V_562 )
{
const struct V_14 * V_872 ;
T_2 V_18 ;
int error ;
unsigned V_96 ;
F_22 () ;
V_872 = F_23 ( V_153 ) -> V_20 ;
if ( V_12 != V_153 ) {
error = F_57 ( F_26 () , V_872 -> V_18 ,
V_426 , V_993 , NULL ) ;
if ( error )
goto V_994;
}
if ( ! strcmp ( V_74 , L_55 ) )
V_18 = V_872 -> V_18 ;
else if ( ! strcmp ( V_74 , L_56 ) )
V_18 = V_872 -> V_17 ;
else if ( ! strcmp ( V_74 , L_57 ) )
V_18 = V_872 -> V_483 ;
else if ( ! strcmp ( V_74 , L_58 ) )
V_18 = V_872 -> V_362 ;
else if ( ! strcmp ( V_74 , L_59 ) )
V_18 = V_872 -> V_481 ;
else if ( ! strcmp ( V_74 , L_60 ) )
V_18 = V_872 -> V_482 ;
else {
error = - V_98 ;
goto V_994;
}
F_24 () ;
if ( ! V_18 )
return 0 ;
error = F_72 ( V_18 , V_562 , & V_96 ) ;
if ( error )
return error ;
return V_96 ;
V_994:
F_24 () ;
return error ;
}
static int F_425 ( const char * V_74 , void * V_562 , T_7 V_595 )
{
struct V_14 * V_15 ;
struct V_11 * V_138 ;
T_2 V_411 = F_26 () , V_18 = 0 , V_490 ;
int error ;
char * V_1 = V_562 ;
if ( ! strcmp ( V_74 , L_57 ) )
error = F_57 ( V_411 , V_411 , V_426 ,
V_995 , NULL ) ;
else if ( ! strcmp ( V_74 , L_58 ) )
error = F_57 ( V_411 , V_411 , V_426 ,
V_996 , NULL ) ;
else if ( ! strcmp ( V_74 , L_59 ) )
error = F_57 ( V_411 , V_411 , V_426 ,
V_997 , NULL ) ;
else if ( ! strcmp ( V_74 , L_60 ) )
error = F_57 ( V_411 , V_411 , V_426 ,
V_998 , NULL ) ;
else if ( ! strcmp ( V_74 , L_55 ) )
error = F_57 ( V_411 , V_411 , V_426 ,
V_999 , NULL ) ;
else
error = - V_98 ;
if ( error )
return error ;
if ( V_595 && V_1 [ 0 ] && V_1 [ 0 ] != '\n' ) {
if ( V_1 [ V_595 - 1 ] == '\n' ) {
V_1 [ V_595 - 1 ] = 0 ;
V_595 -- ;
}
error = F_235 ( V_562 , V_595 , & V_18 , V_16 ) ;
if ( error == - V_98 && ! strcmp ( V_74 , L_58 ) ) {
if ( ! F_231 ( true ) ) {
struct V_597 * V_598 ;
T_7 V_599 ;
if ( V_1 [ V_595 - 1 ] == '\0' )
V_599 = V_595 - 1 ;
else
V_599 = V_595 ;
V_598 = F_236 ( V_12 -> V_600 , V_103 , V_601 ) ;
F_237 ( V_598 , L_61 ) ;
F_238 ( V_598 , V_562 , V_599 ) ;
F_239 ( V_598 ) ;
return error ;
}
error = F_240 ( V_562 , V_595 ,
& V_18 ) ;
}
if ( error )
return error ;
}
V_138 = F_251 () ;
if ( ! V_138 )
return - V_28 ;
V_15 = V_138 -> V_20 ;
if ( ! strcmp ( V_74 , L_57 ) ) {
V_15 -> V_483 = V_18 ;
} else if ( ! strcmp ( V_74 , L_58 ) ) {
V_15 -> V_362 = V_18 ;
} else if ( ! strcmp ( V_74 , L_59 ) ) {
error = F_57 ( V_411 , V_18 , V_1000 , V_1001 ,
NULL ) ;
if ( error )
goto V_1002;
V_15 -> V_481 = V_18 ;
} else if ( ! strcmp ( V_74 , L_60 ) ) {
V_15 -> V_482 = V_18 ;
} else if ( ! strcmp ( V_74 , L_55 ) ) {
error = - V_98 ;
if ( V_18 == 0 )
goto V_1002;
error = - V_479 ;
if ( ! F_426 () ) {
error = F_159 ( V_15 -> V_18 , V_18 ) ;
if ( error )
goto V_1002;
}
error = F_57 ( V_15 -> V_18 , V_18 , V_426 ,
V_1003 , NULL ) ;
if ( error )
goto V_1002;
V_490 = F_155 () ;
if ( V_490 != 0 ) {
error = F_57 ( V_490 , V_18 , V_426 ,
V_427 , NULL ) ;
if ( error )
goto V_1002;
}
V_15 -> V_18 = V_18 ;
} else {
error = - V_98 ;
goto V_1002;
}
F_427 ( V_138 ) ;
return V_595 ;
V_1002:
F_428 ( V_138 ) ;
return error ;
}
static int F_429 ( const char * V_74 )
{
return ( strcmp ( V_74 , V_564 ) == 0 ) ;
}
static int F_430 ( T_2 V_606 , char * * V_545 , T_2 * V_1004 )
{
return F_72 ( V_606 , V_545 , V_1004 ) ;
}
static int F_431 ( const char * V_545 , T_2 V_1004 , T_2 * V_606 )
{
return F_235 ( V_545 , V_1004 , V_606 , V_16 ) ;
}
static void F_432 ( char * V_545 , T_2 V_1004 )
{
F_54 ( V_545 ) ;
}
static void F_433 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_36 ;
F_45 ( & V_25 -> V_29 ) ;
V_25 -> V_34 = V_35 ;
F_47 ( & V_25 -> V_29 ) ;
}
static int F_434 ( struct V_23 * V_23 , void * V_559 , T_2 V_560 )
{
return F_247 ( V_23 , V_564 , V_559 , V_560 , 0 ) ;
}
static int F_435 ( struct V_37 * V_37 , void * V_559 , T_2 V_560 )
{
return F_436 ( V_37 , V_85 , V_559 , V_560 , 0 ) ;
}
static int F_437 ( struct V_23 * V_23 , void * * V_559 , T_2 * V_560 )
{
int V_96 = 0 ;
V_96 = F_246 ( V_23 , V_564 ,
V_559 , true ) ;
if ( V_96 < 0 )
return V_96 ;
* V_560 = V_96 ;
return 0 ;
}
static int F_438 ( struct V_920 * V_1005 , const struct V_11 * V_11 ,
unsigned long V_87 )
{
const struct V_14 * V_15 ;
struct V_1006 * V_1007 ;
V_1007 = F_18 ( sizeof( struct V_1006 ) , V_16 ) ;
if ( ! V_1007 )
return - V_28 ;
V_15 = V_11 -> V_20 ;
if ( V_15 -> V_481 )
V_1007 -> V_18 = V_15 -> V_481 ;
else
V_1007 -> V_18 = V_15 -> V_18 ;
V_1005 -> V_20 = V_1007 ;
return 0 ;
}
static void F_439 ( struct V_920 * V_1005 )
{
struct V_1006 * V_1007 = V_1005 -> V_20 ;
V_1005 -> V_20 = NULL ;
F_54 ( V_1007 ) ;
}
static int F_440 ( T_16 V_1008 ,
const struct V_11 * V_11 ,
unsigned V_327 )
{
struct V_920 * V_920 ;
struct V_1006 * V_1007 ;
T_2 V_18 ;
if ( V_327 == 0 )
return 0 ;
V_18 = F_20 ( V_11 ) ;
V_920 = F_441 ( V_1008 ) ;
V_1007 = V_920 -> V_20 ;
return F_57 ( V_18 , V_1007 -> V_18 , V_1000 , V_327 , NULL ) ;
}
static int F_442 ( struct V_920 * V_920 , char * * V_1009 )
{
struct V_1006 * V_1007 = V_920 -> V_20 ;
char * V_95 = NULL ;
unsigned V_96 ;
int V_63 ;
V_63 = F_72 ( V_1007 -> V_18 , & V_95 , & V_96 ) ;
if ( ! V_63 )
V_63 = V_96 ;
* V_1009 = V_95 ;
return V_63 ;
}
static int F_443 ( void * V_1010 , T_17 V_1011 , T_4 V_1012 )
{
struct V_338 V_339 ;
int V_665 ;
T_2 V_18 = 0 ;
struct V_1013 * V_1014 = V_1010 ;
struct V_1015 V_1016 ;
V_665 = F_444 ( V_1011 , V_1012 , & V_18 ) ;
if ( V_665 )
return V_665 ;
V_339 . type = V_1017 ;
V_1016 . V_1011 = V_1011 ;
V_1016 . V_1018 = V_1012 ;
V_339 . V_344 . V_1016 = & V_1016 ;
return F_57 ( V_1014 -> V_18 , V_18 ,
V_1019 ,
V_1020 , & V_339 ) ;
}
static int F_445 ( void * V_1010 , const char * V_552 ,
T_11 V_1021 )
{
struct V_338 V_339 ;
int V_665 ;
T_2 V_18 = 0 ;
struct V_1013 * V_1014 = V_1010 ;
struct V_1022 V_1023 ;
V_665 = F_446 ( V_552 , V_1021 , & V_18 ) ;
if ( V_665 )
return V_665 ;
V_339 . type = V_1024 ;
strncpy ( V_1023 . V_552 , V_552 , sizeof( V_1023 . V_552 ) ) ;
V_1023 . V_1025 = V_1021 ;
V_339 . V_344 . V_1023 = & V_1023 ;
return F_57 ( V_1014 -> V_18 , V_18 ,
V_1026 ,
V_1027 , & V_339 ) ;
}
static int F_447 ( void * * V_1010 )
{
struct V_1013 * V_1014 ;
V_1014 = F_18 ( sizeof( * V_1014 ) , V_16 ) ;
if ( ! V_1014 )
return - V_28 ;
V_1014 -> V_18 = F_26 () ;
* V_1010 = V_1014 ;
return 0 ;
}
static void F_448 ( void * V_1010 )
{
F_54 ( V_1010 ) ;
}
static T_1 int F_449 ( void )
{
if ( ! F_450 ( L_62 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_61 ( V_1028 L_63 ) ;
return 0 ;
}
F_61 ( V_1028 L_64 ) ;
F_17 () ;
V_635 = ! ( V_1029 & V_651 ) ;
V_26 = F_451 ( L_65 ,
sizeof( struct V_24 ) ,
0 , V_1030 , NULL ) ;
V_54 = F_451 ( L_66 ,
sizeof( struct V_52 ) ,
0 , V_1030 , NULL ) ;
F_452 () ;
F_453 ( V_1031 , F_454 ( V_1031 ) , L_62 ) ;
if ( F_455 ( F_9 , V_9 ) )
F_19 ( L_67 ) ;
if ( F_455 ( F_14 , V_9 ) )
F_19 ( L_68 ) ;
if ( V_3 )
F_61 ( V_1032 L_69 ) ;
else
F_61 ( V_1032 L_70 ) ;
return 0 ;
}
static void F_456 ( struct V_57 * V_58 , void * V_1033 )
{
F_89 ( V_58 , NULL ) ;
}
void F_457 ( void )
{
F_61 ( V_1032 L_71 ) ;
F_61 ( V_1032 L_72 ) ;
F_458 ( F_456 , NULL ) ;
}
static int T_18 F_459 ( struct V_730 * V_730 )
{
return F_460 ( V_730 , V_1034 ,
F_454 ( V_1034 ) ) ;
}
static void T_19 F_461 ( struct V_730 * V_730 )
{
F_462 ( V_730 , V_1034 ,
F_454 ( V_1034 ) ) ;
}
static int T_1 F_463 ( void )
{
int V_665 ;
if ( ! V_5 )
return 0 ;
F_61 ( V_1032 L_73 ) ;
V_665 = F_464 ( & V_1035 ) ;
if ( V_665 )
F_19 ( L_74 , V_665 ) ;
return 0 ;
}
static void F_465 ( void )
{
F_61 ( V_1032 L_75 ) ;
F_466 ( & V_1035 ) ;
}
int F_467 ( void )
{
if ( V_40 ) {
return - V_98 ;
}
if ( V_1036 ) {
return - V_98 ;
}
F_61 ( V_1028 L_76 ) ;
V_1036 = 1 ;
V_5 = 0 ;
F_468 ( V_1031 , F_454 ( V_1031 ) ) ;
F_469 () ;
F_465 () ;
F_470 () ;
return 0 ;
}
