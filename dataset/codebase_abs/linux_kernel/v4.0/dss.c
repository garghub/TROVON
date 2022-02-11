static inline void F_1 ( const struct V_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 . V_5 + V_2 . V_2 ) ;
}
static inline T_1 F_3 ( const struct V_1 V_2 )
{
return F_4 ( V_4 . V_5 + V_2 . V_2 ) ;
}
static void F_5 ( void )
{
F_6 ( L_1 ) ;
F_7 ( V_6 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_7 ( V_9 ) ;
F_7 ( V_10 ) ;
}
V_4 . V_11 = true ;
F_6 ( L_2 ) ;
}
static void F_9 ( void )
{
F_6 ( L_3 ) ;
if ( ! V_4 . V_11 )
return;
F_10 ( V_6 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_10 ( V_9 ) ;
F_10 ( V_10 ) ;
}
F_6 ( L_4 ) ;
}
void F_11 ( enum V_12 V_13 , bool V_14 )
{
unsigned V_15 ;
unsigned V_3 ;
if ( ! V_4 . V_16 )
return;
V_3 = ! V_14 ;
switch ( V_13 ) {
case V_17 :
V_15 = 0 ;
break;
case V_18 :
V_15 = 1 ;
break;
case V_19 :
V_15 = 2 ;
break;
default:
F_12 ( L_5 , V_13 ) ;
return;
}
F_13 ( V_4 . V_16 , V_4 . V_20 ,
1 << V_15 , V_3 << V_15 ) ;
}
void F_14 ( enum V_12 V_13 ,
enum V_21 V_22 )
{
unsigned V_15 , V_3 ;
if ( ! V_4 . V_16 )
return;
switch ( V_22 ) {
case V_7 :
V_15 = 3 ;
switch ( V_13 ) {
case V_17 :
V_3 = 0 ; break;
case V_19 :
V_3 = 1 ; break;
default:
F_12 ( L_6 ) ;
return;
}
break;
case V_23 :
V_15 = 5 ;
switch ( V_13 ) {
case V_17 :
V_3 = 0 ; break;
case V_18 :
V_3 = 1 ; break;
case V_19 :
V_3 = 2 ; break;
default:
F_12 ( L_7 ) ;
return;
}
break;
case V_24 :
V_15 = 7 ;
switch ( V_13 ) {
case V_17 :
V_3 = 1 ; break;
case V_18 :
V_3 = 0 ; break;
case V_19 :
V_3 = 2 ; break;
default:
F_12 ( L_8 ) ;
return;
}
break;
default:
F_12 ( L_9 ) ;
return;
}
F_13 ( V_4 . V_16 , V_4 . V_20 ,
0x3 << V_15 , V_3 << V_15 ) ;
}
void F_15 ( int V_25 )
{
T_1 V_26 ;
F_16 ( V_25 > 3 || V_25 < 1 ) ;
V_26 = F_3 ( V_27 ) ;
V_26 = F_17 ( V_26 , 0xf , 19 , 15 ) ;
V_26 = F_17 ( V_26 , V_25 - 1 , 3 , 2 ) ;
V_26 = F_17 ( V_26 , 2 , 1 , 0 ) ;
F_1 ( V_27 , V_26 ) ;
V_26 = F_3 ( V_28 ) ;
V_26 = F_17 ( V_26 , 0x7 , 25 , 22 ) ;
V_26 = F_17 ( V_26 , 0xb , 16 , 11 ) ;
V_26 = F_17 ( V_26 , 0xb4 , 10 , 1 ) ;
F_1 ( V_28 , V_26 ) ;
}
int F_18 ( void )
{
unsigned long V_29 ;
F_19 ( 1 ) ;
F_20 ( V_28 , 1 , 18 , 18 ) ;
F_21 ( 1 ) ;
F_20 ( V_28 , 1 , 28 , 28 ) ;
V_29 = V_30 + F_22 ( 500 ) ;
while ( F_3 ( V_31 ) & ( 1 << 6 ) ) {
if ( F_23 ( V_30 , V_29 ) ) {
F_12 ( L_10 ) ;
goto V_32;
}
}
F_20 ( V_28 , 0 , 28 , 28 ) ;
V_29 = V_30 + F_22 ( 500 ) ;
while ( ! ( F_3 ( V_31 ) & ( 1 << 5 ) ) ) {
if ( F_23 ( V_30 , V_29 ) ) {
F_12 ( L_11 ) ;
goto V_32;
}
}
F_24 ( 1 ) ;
V_29 = V_30 + F_22 ( 500 ) ;
while ( ! ( F_3 ( V_31 ) & ( 1 << 2 ) ) ) {
if ( F_23 ( V_30 , V_29 ) ) {
F_12 ( L_12 ) ;
goto V_33;
}
}
return 0 ;
V_33:
F_24 ( 0 ) ;
V_32:
F_20 ( V_28 , 0 , 18 , 18 ) ;
F_19 ( 0 ) ;
return - V_34 ;
}
void F_25 ( void )
{
F_24 ( 0 ) ;
F_19 ( 0 ) ;
F_20 ( V_28 , 0 , 18 , 18 ) ;
}
const char * F_26 ( enum V_35 V_36 )
{
return V_37 [ V_36 ] ;
}
void F_27 ( struct V_38 * V_39 )
{
const char * V_40 , * V_41 ;
unsigned long V_42 ;
if ( F_28 () )
return;
F_29 ( V_39 , L_13 ) ;
V_40 = F_26 ( V_43 ) ;
V_41 = F_30 ( V_43 ) ;
V_42 = F_31 ( V_4 . V_44 ) ;
F_29 ( V_39 , L_14 ,
V_40 , V_41 ,
V_42 ) ;
F_32 () ;
}
static void F_33 ( struct V_38 * V_39 )
{
#define F_34 ( T_2 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_28 () )
return;
F_34 ( V_45 ) ;
F_34 ( V_46 ) ;
F_34 ( V_47 ) ;
F_34 ( V_48 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_34 ( V_27 ) ;
F_34 ( V_28 ) ;
F_34 ( V_31 ) ;
}
F_32 () ;
#undef F_34
}
static void F_35 ( enum V_35 V_36 )
{
int V_49 ;
T_3 V_50 , V_51 ;
switch ( V_36 ) {
case V_43 :
V_49 = 0 ;
break;
case V_52 :
V_49 = 1 ;
break;
case V_53 :
V_49 = 2 ;
break;
default:
F_36 () ;
return;
}
F_37 ( V_54 , & V_50 , & V_51 ) ;
F_20 ( V_48 , V_49 , V_50 , V_51 ) ;
V_4 . V_55 = V_36 ;
}
void F_38 ( int V_56 ,
enum V_35 V_36 )
{
int V_49 , V_57 ;
switch ( V_36 ) {
case V_43 :
V_49 = 0 ;
break;
case V_58 :
F_16 ( V_56 != 0 ) ;
V_49 = 1 ;
break;
case V_59 :
F_16 ( V_56 != 1 ) ;
V_49 = 1 ;
break;
default:
F_36 () ;
return;
}
V_57 = V_56 == 0 ? 1 : 10 ;
F_20 ( V_48 , V_49 , V_57 , V_57 ) ;
V_4 . V_60 [ V_56 ] = V_36 ;
}
void F_39 ( enum V_21 V_22 ,
enum V_35 V_36 )
{
int V_49 , V_61 , V_57 ;
if ( ! F_40 ( V_62 ) ) {
F_35 ( V_36 ) ;
return;
}
switch ( V_36 ) {
case V_43 :
V_49 = 0 ;
break;
case V_52 :
F_16 ( V_22 != V_7 ) ;
V_49 = 1 ;
break;
case V_53 :
F_16 ( V_22 != V_23 &&
V_22 != V_24 ) ;
V_49 = 1 ;
break;
default:
F_36 () ;
return;
}
V_57 = V_22 == V_7 ? 0 :
( V_22 == V_23 ? 12 : 19 ) ;
F_20 ( V_48 , V_49 , V_57 , V_57 ) ;
V_61 = V_22 == V_7 ? 0 :
( V_22 == V_23 ? 1 : 2 ) ;
V_4 . V_63 [ V_61 ] = V_36 ;
}
enum V_35 F_41 ( void )
{
return V_4 . V_55 ;
}
enum V_35 F_42 ( int V_56 )
{
return V_4 . V_60 [ V_56 ] ;
}
enum V_35 F_43 ( enum V_21 V_22 )
{
if ( F_40 ( V_62 ) ) {
int V_61 = V_22 == V_7 ? 0 :
( V_22 == V_23 ? 1 : 2 ) ;
return V_4 . V_63 [ V_61 ] ;
} else {
return V_4 . V_55 ;
}
}
bool F_44 ( unsigned long V_64 , unsigned long V_65 ,
T_4 V_66 , void * V_67 )
{
int V_68 , V_69 , V_70 ;
unsigned long V_71 ;
unsigned long V_72 ;
unsigned long V_73 ;
unsigned long V_74 ;
unsigned V_75 ;
V_72 = F_45 ( V_76 ) ;
if ( V_4 . V_77 == NULL ) {
unsigned V_78 ;
V_78 = V_72 / V_64 ;
V_71 = V_64 * V_78 ;
V_71 = F_46 ( V_4 . V_44 , V_71 ) ;
return V_66 ( V_71 , V_67 ) ;
}
V_73 = V_4 . V_79 -> V_80 ;
V_75 = V_4 . V_79 -> V_81 ;
V_74 = F_31 ( V_4 . V_77 ) ;
V_65 = V_65 ? V_65 : 1 ;
V_69 = F_47 ( V_74 * V_75 / V_65 , V_73 ) ;
V_70 = F_48 ( F_49 ( V_74 * V_75 , V_72 ) , 1ul ) ;
for ( V_68 = V_69 ; V_68 >= V_70 ; -- V_68 ) {
V_71 = F_49 ( V_74 , V_68 ) * V_75 ;
if ( V_66 ( V_71 , V_67 ) )
return true ;
}
return false ;
}
int F_50 ( unsigned long V_82 )
{
int T_2 ;
F_6 ( L_15 , V_82 ) ;
T_2 = F_51 ( V_4 . V_44 , V_82 ) ;
if ( T_2 )
return T_2 ;
V_4 . V_83 = F_31 ( V_4 . V_44 ) ;
F_52 ( V_4 . V_83 != V_82 ,
L_16 , V_4 . V_83 ,
V_82 ) ;
return 0 ;
}
unsigned long F_53 ( void )
{
return V_4 . V_83 ;
}
static int F_54 ( void )
{
unsigned long V_84 , V_74 ;
unsigned long V_71 ;
unsigned V_85 ;
int T_2 ;
V_84 = F_45 ( V_76 ) ;
if ( V_4 . V_77 == NULL ) {
V_71 = F_46 ( V_4 . V_44 , V_84 ) ;
} else {
V_74 = F_31 ( V_4 . V_77 ) ;
V_85 = F_49 ( V_74 * V_4 . V_79 -> V_81 ,
V_84 ) ;
V_71 = F_49 ( V_74 , V_85 ) * V_4 . V_79 -> V_81 ;
}
T_2 = F_50 ( V_71 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
void F_55 ( enum V_86 type )
{
int V_26 = 0 ;
if ( type == V_87 )
V_26 = 0 ;
else if ( type == V_88 )
V_26 = 1 ;
else
F_36 () ;
F_20 ( V_48 , V_26 , 6 , 6 ) ;
}
void F_56 ( bool V_14 )
{
F_20 ( V_48 , V_14 , 5 , 5 ) ;
}
void F_57 ( enum V_89 V_90 )
{
enum V_91 V_92 ;
V_92 = F_8 ( V_93 ) ;
F_58 ( ( V_90 == V_94 ) && ! ( V_92 & V_95 ) ) ;
F_58 ( ( V_90 == V_96 ) && ! ( V_92 & V_97 ) ) ;
if ( ( V_92 & V_95 ) && ( V_92 & V_97 ) )
F_20 ( V_48 , V_90 , 15 , 15 ) ;
}
enum V_89 F_59 ( void )
{
enum V_91 V_98 ;
V_98 = F_8 ( V_93 ) ;
if ( ( V_98 & V_97 ) == 0 )
return V_94 ;
if ( ( V_98 & V_95 ) == 0 )
return V_96 ;
return F_60 ( V_48 , 15 , 15 ) ;
}
static int F_61 ( int V_99 , enum V_21 V_22 )
{
if ( V_22 != V_7 )
return - V_100 ;
return 0 ;
}
static int F_62 ( int V_99 , enum V_21 V_22 )
{
int V_3 ;
switch ( V_22 ) {
case V_23 :
V_3 = 0 ;
break;
case V_93 :
V_3 = 1 ;
break;
default:
return - V_100 ;
}
F_20 ( V_48 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_63 ( int V_99 , enum V_21 V_22 )
{
int V_3 ;
switch ( V_22 ) {
case V_7 :
V_3 = 1 ;
break;
case V_23 :
V_3 = 2 ;
break;
case V_24 :
V_3 = 3 ;
break;
case V_93 :
V_3 = 0 ;
break;
default:
return - V_100 ;
}
F_20 ( V_48 , V_3 , 17 , 16 ) ;
return 0 ;
}
static int F_64 ( int V_99 , enum V_21 V_22 )
{
switch ( V_99 ) {
case 0 :
return F_63 ( V_99 , V_22 ) ;
case 1 :
if ( V_22 != V_23 )
return - V_100 ;
break;
case 2 :
if ( V_22 != V_24 )
return - V_100 ;
break;
default:
return - V_100 ;
}
return 0 ;
}
int F_65 ( int V_99 , enum V_21 V_22 )
{
return V_4 . V_79 -> V_101 ( V_99 , V_22 ) ;
}
static int F_66 ( void )
{
struct V_102 * V_102 ;
V_102 = F_67 ( & V_4 . V_103 -> V_104 , L_17 ) ;
if ( F_68 ( V_102 ) ) {
F_12 ( L_18 ) ;
return F_69 ( V_102 ) ;
}
V_4 . V_44 = V_102 ;
if ( V_4 . V_79 -> V_105 ) {
V_102 = F_70 ( NULL , V_4 . V_79 -> V_105 ) ;
if ( F_68 ( V_102 ) ) {
F_12 ( L_19 , V_4 . V_79 -> V_105 ) ;
return F_69 ( V_102 ) ;
}
} else {
V_102 = NULL ;
}
V_4 . V_77 = V_102 ;
return 0 ;
}
static void F_71 ( void )
{
if ( V_4 . V_77 )
F_72 ( V_4 . V_77 ) ;
}
int F_28 ( void )
{
int T_2 ;
F_6 ( L_20 ) ;
T_2 = F_73 ( & V_4 . V_103 -> V_104 ) ;
F_58 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
void F_32 ( void )
{
int T_2 ;
F_6 ( L_21 ) ;
T_2 = F_74 ( & V_4 . V_103 -> V_104 ) ;
F_58 ( T_2 < 0 && T_2 != - V_106 && T_2 != - V_107 ) ;
}
void F_75 ( struct V_38 * V_39 )
{
F_27 ( V_39 ) ;
F_76 ( V_39 ) ;
#ifdef F_77
F_78 ( V_39 ) ;
#endif
}
static int T_5 F_79 ( struct V_108 * V_103 )
{
const struct V_109 * V_90 ;
struct V_109 * V_110 ;
V_110 = F_80 ( & V_103 -> V_104 , sizeof( * V_110 ) , V_111 ) ;
if ( ! V_110 ) {
F_81 ( & V_103 -> V_104 , L_22 ) ;
return - V_112 ;
}
switch ( F_82 () ) {
case V_113 :
V_90 = & V_114 ;
break;
case V_115 :
case V_116 :
case V_117 :
V_90 = & V_118 ;
break;
case V_119 :
V_90 = & V_120 ;
break;
case V_121 :
case V_122 :
case V_123 :
V_90 = & V_124 ;
break;
case V_125 :
V_90 = & V_126 ;
break;
case V_127 :
V_90 = & V_128 ;
break;
case V_129 :
V_90 = & V_130 ;
break;
default:
return - V_131 ;
}
memcpy ( V_110 , V_90 , sizeof( * V_110 ) ) ;
V_4 . V_79 = V_110 ;
return 0 ;
}
static int T_5 F_83 ( struct V_108 * V_103 )
{
struct V_132 * V_133 = V_103 -> V_104 . V_134 ;
struct V_132 * V_99 ;
int T_2 ;
if ( V_133 == NULL )
return 0 ;
V_99 = F_84 ( V_133 , NULL ) ;
if ( ! V_99 )
return 0 ;
if ( V_4 . V_79 -> V_135 == 0 )
return 0 ;
do {
enum V_91 V_136 ;
T_1 V_137 ;
T_2 = F_85 ( V_99 , L_23 , & V_137 ) ;
if ( T_2 )
V_137 = 0 ;
if ( V_137 >= V_4 . V_79 -> V_135 )
continue;
V_136 = V_4 . V_79 -> V_138 [ V_137 ] ;
switch ( V_136 ) {
case V_139 :
F_86 ( V_103 , V_99 ) ;
break;
case V_8 :
F_87 ( V_103 , V_99 ) ;
break;
default:
break;
}
} while ( ( V_99 = F_84 ( V_133 , V_99 ) ) != NULL );
return 0 ;
}
static void T_6 F_88 ( struct V_108 * V_103 )
{
struct V_132 * V_133 = V_103 -> V_104 . V_134 ;
struct V_132 * V_99 ;
if ( V_133 == NULL )
return;
V_99 = F_84 ( V_133 , NULL ) ;
if ( ! V_99 )
return;
if ( V_4 . V_79 -> V_135 == 0 )
return;
do {
enum V_91 V_136 ;
T_1 V_137 ;
int T_2 ;
T_2 = F_85 ( V_99 , L_23 , & V_137 ) ;
if ( T_2 )
V_137 = 0 ;
if ( V_137 >= V_4 . V_79 -> V_135 )
continue;
V_136 = V_4 . V_79 -> V_138 [ V_137 ] ;
switch ( V_136 ) {
case V_139 :
F_89 ( V_99 ) ;
break;
case V_8 :
F_90 ( V_99 ) ;
break;
default:
break;
}
} while ( ( V_99 = F_84 ( V_133 , V_99 ) ) != NULL );
}
static int T_5 F_91 ( struct V_108 * V_103 )
{
struct V_140 * V_141 ;
struct V_132 * V_142 = V_103 -> V_104 . V_134 ;
T_1 V_143 ;
int T_2 ;
struct V_144 * V_145 ;
V_4 . V_103 = V_103 ;
T_2 = F_79 ( V_4 . V_103 ) ;
if ( T_2 )
return T_2 ;
V_141 = F_92 ( V_4 . V_103 , V_146 , 0 ) ;
if ( ! V_141 ) {
F_12 ( L_24 ) ;
return - V_100 ;
}
V_4 . V_5 = F_93 ( & V_103 -> V_104 , V_141 -> V_50 ,
F_94 ( V_141 ) ) ;
if ( ! V_4 . V_5 ) {
F_12 ( L_25 ) ;
return - V_112 ;
}
T_2 = F_66 () ;
if ( T_2 )
return T_2 ;
T_2 = F_54 () ;
if ( T_2 )
goto V_147;
F_95 ( & V_103 -> V_104 ) ;
T_2 = F_28 () ;
if ( T_2 )
goto V_148;
V_4 . V_83 = F_31 ( V_4 . V_44 ) ;
F_20 ( V_48 , 0 , 0 , 0 ) ;
F_35 ( V_43 ) ;
#ifdef F_96
F_20 ( V_48 , 1 , 4 , 4 ) ;
F_20 ( V_48 , 1 , 3 , 3 ) ;
F_20 ( V_48 , 0 , 2 , 2 ) ;
#endif
V_4 . V_60 [ 0 ] = V_43 ;
V_4 . V_60 [ 1 ] = V_43 ;
V_4 . V_55 = V_43 ;
V_4 . V_63 [ 0 ] = V_43 ;
V_4 . V_63 [ 1 ] = V_43 ;
F_83 ( V_103 ) ;
if ( V_142 && F_97 ( V_142 , L_26 ) ) {
V_4 . V_16 = F_98 ( V_142 ,
L_26 ) ;
if ( F_68 ( V_4 . V_16 ) ) {
F_81 ( & V_103 -> V_104 ,
L_27 ) ;
return F_69 ( V_4 . V_16 ) ;
}
if ( F_99 ( V_142 , L_26 , 1 ,
& V_4 . V_20 ) ) {
F_81 ( & V_103 -> V_104 ,
L_28 ) ;
return - V_100 ;
}
}
V_145 = F_100 ( & V_103 -> V_104 , L_29 ) ;
if ( F_68 ( V_145 ) ) {
T_2 = F_69 ( V_145 ) ;
switch ( T_2 ) {
case - V_149 :
V_145 = NULL ;
break;
case - V_150 :
return - V_150 ;
default:
F_12 ( L_30 ) ;
return T_2 ;
}
}
if ( F_101 ( V_142 , L_31 , L_32 ) >= 0 ) {
V_4 . V_151 = F_102 ( V_103 , 0 , V_145 ) ;
if ( F_68 ( V_4 . V_151 ) ) {
T_2 = F_69 ( V_4 . V_151 ) ;
goto V_152;
}
}
if ( F_101 ( V_142 , L_31 , L_33 ) >= 0 ) {
V_4 . V_153 = F_102 ( V_103 , 1 , V_145 ) ;
if ( F_68 ( V_4 . V_153 ) ) {
T_2 = F_69 ( V_4 . V_153 ) ;
goto V_152;
}
}
V_143 = F_3 ( V_45 ) ;
F_103 ( V_154 L_34 ,
F_104 ( V_143 , 7 , 4 ) , F_104 ( V_143 , 3 , 0 ) ) ;
F_32 () ;
F_105 ( L_35 , F_33 ) ;
return 0 ;
V_152:
if ( V_4 . V_151 )
F_106 ( V_4 . V_151 ) ;
if ( V_4 . V_153 )
F_106 ( V_4 . V_153 ) ;
V_148:
F_107 ( & V_103 -> V_104 ) ;
V_147:
F_71 () ;
return T_2 ;
}
static int T_6 F_108 ( struct V_108 * V_103 )
{
if ( V_4 . V_151 )
F_106 ( V_4 . V_151 ) ;
if ( V_4 . V_153 )
F_106 ( V_4 . V_153 ) ;
F_88 ( V_103 ) ;
F_107 ( & V_103 -> V_104 ) ;
F_71 () ;
return 0 ;
}
static int F_109 ( struct V_155 * V_104 )
{
F_5 () ;
F_110 ( V_104 , 0 ) ;
return 0 ;
}
static int F_111 ( struct V_155 * V_104 )
{
int T_2 ;
T_2 = F_110 ( V_104 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_112 ( void )
{
return F_113 ( & V_156 , F_91 ) ;
}
void F_114 ( void )
{
F_115 ( & V_156 ) ;
}
