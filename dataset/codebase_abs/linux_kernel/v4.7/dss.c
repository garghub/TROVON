bool F_1 ( void )
{
return V_1 ;
}
static inline void F_2 ( const struct V_2 V_3 , T_1 V_4 )
{
F_3 ( V_4 , V_5 . V_6 + V_3 . V_3 ) ;
}
static inline T_1 F_4 ( const struct V_2 V_3 )
{
return F_5 ( V_5 . V_6 + V_3 . V_3 ) ;
}
static void F_6 ( void )
{
F_7 ( L_1 ) ;
F_8 ( V_7 ) ;
if ( F_9 ( V_8 ) &
V_9 ) {
F_8 ( V_10 ) ;
F_8 ( V_11 ) ;
}
V_5 . V_12 = true ;
F_7 ( L_2 ) ;
}
static void F_10 ( void )
{
F_7 ( L_3 ) ;
if ( ! V_5 . V_12 )
return;
F_11 ( V_7 ) ;
if ( F_9 ( V_8 ) &
V_9 ) {
F_11 ( V_10 ) ;
F_11 ( V_11 ) ;
}
F_7 ( L_4 ) ;
}
void F_12 ( enum V_13 V_14 , bool V_15 )
{
unsigned V_16 ;
unsigned V_4 ;
if ( ! V_5 . V_17 )
return;
V_4 = ! V_15 ;
switch ( V_14 ) {
case V_18 :
V_16 = 0 ;
break;
case V_19 :
V_16 = 1 ;
break;
case V_20 :
V_16 = 2 ;
break;
default:
F_13 ( L_5 , V_14 ) ;
return;
}
F_14 ( V_5 . V_17 , V_5 . V_21 ,
1 << V_16 , V_4 << V_16 ) ;
}
void F_15 ( enum V_13 V_14 ,
enum V_22 V_23 )
{
unsigned V_16 , V_4 ;
if ( ! V_5 . V_17 )
return;
switch ( V_23 ) {
case V_8 :
V_16 = 3 ;
switch ( V_14 ) {
case V_18 :
V_4 = 0 ; break;
case V_20 :
V_4 = 1 ; break;
default:
F_13 ( L_6 ) ;
return;
}
break;
case V_24 :
V_16 = 5 ;
switch ( V_14 ) {
case V_18 :
V_4 = 0 ; break;
case V_19 :
V_4 = 1 ; break;
case V_20 :
V_4 = 2 ; break;
default:
F_13 ( L_7 ) ;
return;
}
break;
case V_25 :
V_16 = 7 ;
switch ( V_14 ) {
case V_18 :
V_4 = 1 ; break;
case V_19 :
V_4 = 0 ; break;
case V_20 :
V_4 = 2 ; break;
default:
F_13 ( L_8 ) ;
return;
}
break;
default:
F_13 ( L_9 ) ;
return;
}
F_14 ( V_5 . V_17 , V_5 . V_21 ,
0x3 << V_16 , V_4 << V_16 ) ;
}
void F_16 ( int V_26 )
{
T_1 V_27 ;
F_17 ( V_26 > 3 || V_26 < 1 ) ;
V_27 = F_4 ( V_28 ) ;
V_27 = F_18 ( V_27 , 0xf , 19 , 15 ) ;
V_27 = F_18 ( V_27 , V_26 - 1 , 3 , 2 ) ;
V_27 = F_18 ( V_27 , 2 , 1 , 0 ) ;
F_2 ( V_28 , V_27 ) ;
V_27 = F_4 ( V_29 ) ;
V_27 = F_18 ( V_27 , 0x7 , 25 , 22 ) ;
V_27 = F_18 ( V_27 , 0xb , 16 , 11 ) ;
V_27 = F_18 ( V_27 , 0xb4 , 10 , 1 ) ;
F_2 ( V_29 , V_27 ) ;
}
int F_19 ( void )
{
unsigned long V_30 ;
F_20 ( 1 ) ;
F_21 ( V_29 , 1 , 18 , 18 ) ;
F_22 ( 1 ) ;
F_21 ( V_29 , 1 , 28 , 28 ) ;
V_30 = V_31 + F_23 ( 500 ) ;
while ( F_4 ( V_32 ) & ( 1 << 6 ) ) {
if ( F_24 ( V_31 , V_30 ) ) {
F_13 ( L_10 ) ;
goto V_33;
}
}
F_21 ( V_29 , 0 , 28 , 28 ) ;
V_30 = V_31 + F_23 ( 500 ) ;
while ( ! ( F_4 ( V_32 ) & ( 1 << 5 ) ) ) {
if ( F_24 ( V_31 , V_30 ) ) {
F_13 ( L_11 ) ;
goto V_33;
}
}
F_25 ( 1 ) ;
V_30 = V_31 + F_23 ( 500 ) ;
while ( ! ( F_4 ( V_32 ) & ( 1 << 2 ) ) ) {
if ( F_24 ( V_31 , V_30 ) ) {
F_13 ( L_12 ) ;
goto V_34;
}
}
return 0 ;
V_34:
F_25 ( 0 ) ;
V_33:
F_21 ( V_29 , 0 , 18 , 18 ) ;
F_20 ( 0 ) ;
return - V_35 ;
}
void F_26 ( void )
{
F_25 ( 0 ) ;
F_20 ( 0 ) ;
F_21 ( V_29 , 0 , 18 , 18 ) ;
}
const char * F_27 ( enum V_36 V_37 )
{
return V_38 [ V_37 ] ;
}
void F_28 ( struct V_39 * V_40 )
{
const char * V_41 , * V_42 ;
unsigned long V_43 ;
if ( F_29 () )
return;
F_30 ( V_40 , L_13 ) ;
V_41 = F_27 ( V_44 ) ;
V_42 = F_31 ( V_44 ) ;
V_43 = F_32 ( V_5 . V_45 ) ;
F_30 ( V_40 , L_14 ,
V_41 , V_42 ,
V_43 ) ;
F_33 () ;
}
static void F_34 ( struct V_39 * V_40 )
{
#define F_35 ( T_2 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_29 () )
return;
F_35 ( V_46 ) ;
F_35 ( V_47 ) ;
F_35 ( V_48 ) ;
F_35 ( V_49 ) ;
if ( F_9 ( V_8 ) &
V_9 ) {
F_35 ( V_28 ) ;
F_35 ( V_29 ) ;
F_35 ( V_32 ) ;
}
F_33 () ;
#undef F_35
}
static void F_36 ( enum V_36 V_37 )
{
int V_50 ;
T_3 V_51 , V_52 ;
switch ( V_37 ) {
case V_44 :
V_50 = 0 ;
break;
case V_53 :
V_50 = 1 ;
break;
case V_54 :
V_50 = 2 ;
break;
default:
F_37 () ;
return;
}
F_38 ( V_55 , & V_51 , & V_52 ) ;
F_21 ( V_49 , V_50 , V_51 , V_52 ) ;
V_5 . V_56 = V_37 ;
}
void F_39 ( int V_57 ,
enum V_36 V_37 )
{
int V_50 , V_58 ;
switch ( V_37 ) {
case V_44 :
V_50 = 0 ;
break;
case V_59 :
F_17 ( V_57 != 0 ) ;
V_50 = 1 ;
break;
case V_60 :
F_17 ( V_57 != 1 ) ;
V_50 = 1 ;
break;
default:
F_37 () ;
return;
}
V_58 = V_57 == 0 ? 1 : 10 ;
F_21 ( V_49 , V_50 , V_58 , V_58 ) ;
V_5 . V_61 [ V_57 ] = V_37 ;
}
void F_40 ( enum V_22 V_23 ,
enum V_36 V_37 )
{
int V_50 , V_62 , V_58 ;
if ( ! F_41 ( V_63 ) ) {
F_36 ( V_37 ) ;
return;
}
switch ( V_37 ) {
case V_44 :
V_50 = 0 ;
break;
case V_53 :
F_17 ( V_23 != V_8 ) ;
V_50 = 1 ;
break;
case V_54 :
F_17 ( V_23 != V_24 &&
V_23 != V_25 ) ;
V_50 = 1 ;
break;
default:
F_37 () ;
return;
}
V_58 = V_23 == V_8 ? 0 :
( V_23 == V_24 ? 12 : 19 ) ;
F_21 ( V_49 , V_50 , V_58 , V_58 ) ;
V_62 = V_23 == V_8 ? 0 :
( V_23 == V_24 ? 1 : 2 ) ;
V_5 . V_64 [ V_62 ] = V_37 ;
}
enum V_36 F_42 ( void )
{
return V_5 . V_56 ;
}
enum V_36 F_43 ( int V_57 )
{
return V_5 . V_61 [ V_57 ] ;
}
enum V_36 F_44 ( enum V_22 V_23 )
{
if ( F_41 ( V_63 ) ) {
int V_62 = V_23 == V_8 ? 0 :
( V_23 == V_24 ? 1 : 2 ) ;
return V_5 . V_64 [ V_62 ] ;
} else {
return V_5 . V_56 ;
}
}
bool F_45 ( unsigned long V_65 , unsigned long V_66 ,
T_4 V_67 , void * V_68 )
{
int V_69 , V_70 , V_71 ;
unsigned long V_72 ;
unsigned long V_73 ;
unsigned long V_74 ;
unsigned long V_75 ;
unsigned V_76 ;
V_73 = F_46 ( V_77 ) ;
if ( V_5 . V_78 == NULL ) {
unsigned V_79 ;
V_79 = V_73 / V_65 ;
V_72 = V_65 * V_79 ;
V_72 = F_47 ( V_5 . V_45 , V_72 ) ;
return V_67 ( V_72 , V_68 ) ;
}
V_74 = V_5 . V_80 -> V_81 ;
V_76 = V_5 . V_80 -> V_82 ;
V_75 = F_32 ( V_5 . V_78 ) ;
V_66 = V_66 ? V_66 : 1 ;
V_70 = F_48 ( V_75 * V_76 / V_66 , V_74 ) ;
V_71 = F_49 ( F_50 ( V_75 * V_76 , V_73 ) , 1ul ) ;
for ( V_69 = V_70 ; V_69 >= V_71 ; -- V_69 ) {
V_72 = F_50 ( V_75 , V_69 ) * V_76 ;
if ( V_67 ( V_72 , V_68 ) )
return true ;
}
return false ;
}
int F_51 ( unsigned long V_83 )
{
int T_2 ;
F_7 ( L_15 , V_83 ) ;
T_2 = F_52 ( V_5 . V_45 , V_83 ) ;
if ( T_2 )
return T_2 ;
V_5 . V_84 = F_32 ( V_5 . V_45 ) ;
F_53 ( V_5 . V_84 != V_83 ,
L_16 , V_5 . V_84 ,
V_83 ) ;
return 0 ;
}
unsigned long F_54 ( void )
{
return V_5 . V_84 ;
}
static int F_55 ( void )
{
unsigned long V_85 , V_75 ;
unsigned long V_72 ;
unsigned V_86 ;
int T_2 ;
V_85 = F_46 ( V_77 ) ;
if ( V_5 . V_78 == NULL ) {
V_72 = F_47 ( V_5 . V_45 , V_85 ) ;
} else {
V_75 = F_32 ( V_5 . V_78 ) ;
V_86 = F_50 ( V_75 * V_5 . V_80 -> V_82 ,
V_85 ) ;
V_72 = F_50 ( V_75 , V_86 ) * V_5 . V_80 -> V_82 ;
}
T_2 = F_51 ( V_72 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
void F_56 ( enum V_87 type )
{
int V_27 = 0 ;
if ( type == V_88 )
V_27 = 0 ;
else if ( type == V_89 )
V_27 = 1 ;
else
F_37 () ;
F_21 ( V_49 , V_27 , 6 , 6 ) ;
}
void F_57 ( bool V_15 )
{
F_21 ( V_49 , V_15 , 5 , 5 ) ;
}
void F_58 ( enum V_90 V_91 )
{
enum V_92 V_93 ;
V_93 = F_9 ( V_94 ) ;
F_59 ( ( V_91 == V_95 ) && ! ( V_93 & V_96 ) ) ;
F_59 ( ( V_91 == V_97 ) && ! ( V_93 & V_98 ) ) ;
if ( ( V_93 & V_96 ) && ( V_93 & V_98 ) )
F_21 ( V_49 , V_91 , 15 , 15 ) ;
}
enum V_90 F_60 ( void )
{
enum V_92 V_99 ;
V_99 = F_9 ( V_94 ) ;
if ( ( V_99 & V_98 ) == 0 )
return V_95 ;
if ( ( V_99 & V_96 ) == 0 )
return V_97 ;
return F_61 ( V_49 , 15 , 15 ) ;
}
static int F_62 ( int V_100 , enum V_22 V_23 )
{
if ( V_23 != V_8 )
return - V_101 ;
return 0 ;
}
static int F_63 ( int V_100 , enum V_22 V_23 )
{
int V_4 ;
switch ( V_23 ) {
case V_24 :
V_4 = 0 ;
break;
case V_94 :
V_4 = 1 ;
break;
default:
return - V_101 ;
}
F_21 ( V_49 , V_4 , 17 , 17 ) ;
return 0 ;
}
static int F_64 ( int V_100 , enum V_22 V_23 )
{
int V_4 ;
switch ( V_23 ) {
case V_8 :
V_4 = 1 ;
break;
case V_24 :
V_4 = 2 ;
break;
case V_25 :
V_4 = 3 ;
break;
case V_94 :
V_4 = 0 ;
break;
default:
return - V_101 ;
}
F_21 ( V_49 , V_4 , 17 , 16 ) ;
return 0 ;
}
static int F_65 ( int V_100 , enum V_22 V_23 )
{
switch ( V_100 ) {
case 0 :
return F_64 ( V_100 , V_23 ) ;
case 1 :
if ( V_23 != V_24 )
return - V_101 ;
break;
case 2 :
if ( V_23 != V_25 )
return - V_101 ;
break;
default:
return - V_101 ;
}
return 0 ;
}
int F_66 ( int V_100 , enum V_22 V_23 )
{
return V_5 . V_80 -> V_102 ( V_100 , V_23 ) ;
}
static int F_67 ( void )
{
struct V_103 * V_103 ;
V_103 = F_68 ( & V_5 . V_104 -> V_105 , L_17 ) ;
if ( F_69 ( V_103 ) ) {
F_13 ( L_18 ) ;
return F_70 ( V_103 ) ;
}
V_5 . V_45 = V_103 ;
if ( V_5 . V_80 -> V_106 ) {
V_103 = F_71 ( NULL , V_5 . V_80 -> V_106 ) ;
if ( F_69 ( V_103 ) ) {
F_13 ( L_19 , V_5 . V_80 -> V_106 ) ;
return F_70 ( V_103 ) ;
}
} else {
V_103 = NULL ;
}
V_5 . V_78 = V_103 ;
return 0 ;
}
static void F_72 ( void )
{
if ( V_5 . V_78 )
F_73 ( V_5 . V_78 ) ;
}
int F_29 ( void )
{
int T_2 ;
F_7 ( L_20 ) ;
T_2 = F_74 ( & V_5 . V_104 -> V_105 ) ;
F_59 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
void F_33 ( void )
{
int T_2 ;
F_7 ( L_21 ) ;
T_2 = F_75 ( & V_5 . V_104 -> V_105 ) ;
F_59 ( T_2 < 0 && T_2 != - V_107 && T_2 != - V_108 ) ;
}
void F_76 ( struct V_39 * V_40 )
{
F_28 ( V_40 ) ;
F_77 ( V_40 ) ;
#ifdef F_78
F_79 ( V_40 ) ;
#endif
}
static int F_80 ( struct V_109 * V_104 )
{
const struct V_110 * V_91 ;
struct V_110 * V_111 ;
V_111 = F_81 ( & V_104 -> V_105 , sizeof( * V_111 ) , V_112 ) ;
if ( ! V_111 ) {
F_82 ( & V_104 -> V_105 , L_22 ) ;
return - V_113 ;
}
switch ( F_83 () ) {
case V_114 :
V_91 = & V_115 ;
break;
case V_116 :
case V_117 :
case V_118 :
V_91 = & V_119 ;
break;
case V_120 :
V_91 = & V_121 ;
break;
case V_122 :
case V_123 :
case V_124 :
V_91 = & V_125 ;
break;
case V_126 :
V_91 = & V_127 ;
break;
case V_128 :
V_91 = & V_129 ;
break;
case V_130 :
V_91 = & V_131 ;
break;
default:
return - V_132 ;
}
memcpy ( V_111 , V_91 , sizeof( * V_111 ) ) ;
V_5 . V_80 = V_111 ;
return 0 ;
}
static int F_84 ( struct V_109 * V_104 )
{
struct V_133 * V_134 = V_104 -> V_105 . V_135 ;
struct V_133 * V_100 ;
int T_2 ;
if ( V_134 == NULL )
return 0 ;
V_100 = F_85 ( V_134 , NULL ) ;
if ( ! V_100 )
return 0 ;
if ( V_5 . V_80 -> V_136 == 0 )
return 0 ;
do {
enum V_92 V_137 ;
T_1 V_138 ;
T_2 = F_86 ( V_100 , L_23 , & V_138 ) ;
if ( T_2 )
V_138 = 0 ;
if ( V_138 >= V_5 . V_80 -> V_136 )
continue;
V_137 = V_5 . V_80 -> V_139 [ V_138 ] ;
switch ( V_137 ) {
case V_140 :
F_87 ( V_104 , V_100 ) ;
break;
case V_9 :
F_88 ( V_104 , V_100 ) ;
break;
default:
break;
}
} while ( ( V_100 = F_85 ( V_134 , V_100 ) ) != NULL );
return 0 ;
}
static void F_89 ( struct V_109 * V_104 )
{
struct V_133 * V_134 = V_104 -> V_105 . V_135 ;
struct V_133 * V_100 ;
if ( V_134 == NULL )
return;
V_100 = F_85 ( V_134 , NULL ) ;
if ( ! V_100 )
return;
if ( V_5 . V_80 -> V_136 == 0 )
return;
do {
enum V_92 V_137 ;
T_1 V_138 ;
int T_2 ;
T_2 = F_86 ( V_100 , L_23 , & V_138 ) ;
if ( T_2 )
V_138 = 0 ;
if ( V_138 >= V_5 . V_80 -> V_136 )
continue;
V_137 = V_5 . V_80 -> V_139 [ V_138 ] ;
switch ( V_137 ) {
case V_140 :
F_90 ( V_100 ) ;
break;
case V_9 :
F_91 ( V_100 ) ;
break;
default:
break;
}
} while ( ( V_100 = F_85 ( V_134 , V_100 ) ) != NULL );
}
static int F_92 ( struct V_109 * V_104 )
{
struct V_133 * V_141 = V_104 -> V_105 . V_135 ;
struct V_142 * V_143 ;
int T_2 ;
if ( ! V_141 )
return 0 ;
if ( F_93 ( V_141 , L_24 ) ) {
V_5 . V_17 = F_94 ( V_141 ,
L_24 ) ;
if ( F_69 ( V_5 . V_17 ) ) {
F_82 ( & V_104 -> V_105 ,
L_25 ) ;
return F_70 ( V_5 . V_17 ) ;
}
if ( F_95 ( V_141 , L_24 , 1 ,
& V_5 . V_21 ) ) {
F_82 ( & V_104 -> V_105 ,
L_26 ) ;
return - V_101 ;
}
}
V_143 = F_96 ( & V_104 -> V_105 , L_27 ) ;
if ( F_69 ( V_143 ) ) {
T_2 = F_70 ( V_143 ) ;
switch ( T_2 ) {
case - V_144 :
V_143 = NULL ;
break;
case - V_145 :
return - V_145 ;
default:
F_13 ( L_28 ) ;
return T_2 ;
}
}
if ( F_97 ( V_141 , L_29 , L_30 ) >= 0 ) {
V_5 . V_146 = F_98 ( V_104 , 0 , V_143 ) ;
if ( F_69 ( V_5 . V_146 ) )
return F_70 ( V_5 . V_146 ) ;
}
if ( F_97 ( V_141 , L_29 , L_31 ) >= 0 ) {
V_5 . V_147 = F_98 ( V_104 , 1 , V_143 ) ;
if ( F_69 ( V_5 . V_147 ) ) {
F_99 ( V_5 . V_146 ) ;
return F_70 ( V_5 . V_147 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_148 * V_105 )
{
struct V_109 * V_104 = F_101 ( V_105 ) ;
struct V_149 * V_150 ;
T_1 V_151 ;
int T_2 ;
V_5 . V_104 = V_104 ;
T_2 = F_80 ( V_5 . V_104 ) ;
if ( T_2 )
return T_2 ;
V_150 = F_102 ( V_5 . V_104 , V_152 , 0 ) ;
if ( ! V_150 ) {
F_13 ( L_32 ) ;
return - V_101 ;
}
V_5 . V_6 = F_103 ( & V_104 -> V_105 , V_150 -> V_51 ,
F_104 ( V_150 ) ) ;
if ( ! V_5 . V_6 ) {
F_13 ( L_33 ) ;
return - V_113 ;
}
T_2 = F_67 () ;
if ( T_2 )
return T_2 ;
T_2 = F_55 () ;
if ( T_2 )
goto V_153;
T_2 = F_92 ( V_104 ) ;
if ( T_2 )
goto V_154;
T_2 = F_84 ( V_104 ) ;
if ( T_2 )
goto V_155;
F_105 ( & V_104 -> V_105 ) ;
T_2 = F_29 () ;
if ( T_2 )
goto V_156;
V_5 . V_84 = F_32 ( V_5 . V_45 ) ;
F_21 ( V_49 , 0 , 0 , 0 ) ;
F_36 ( V_44 ) ;
#ifdef F_106
F_21 ( V_49 , 1 , 4 , 4 ) ;
F_21 ( V_49 , 1 , 3 , 3 ) ;
F_21 ( V_49 , 0 , 2 , 2 ) ;
#endif
V_5 . V_61 [ 0 ] = V_44 ;
V_5 . V_61 [ 1 ] = V_44 ;
V_5 . V_56 = V_44 ;
V_5 . V_64 [ 0 ] = V_44 ;
V_5 . V_64 [ 1 ] = V_44 ;
V_151 = F_4 ( V_46 ) ;
F_107 ( V_157 L_34 ,
F_108 ( V_151 , 7 , 4 ) , F_108 ( V_151 , 3 , 0 ) ) ;
F_33 () ;
T_2 = F_109 ( & V_104 -> V_105 , NULL ) ;
if ( T_2 )
goto V_158;
F_110 ( L_35 , F_34 ) ;
F_111 ( 0 ) ;
V_1 = true ;
return 0 ;
V_158:
V_156:
F_112 ( & V_104 -> V_105 ) ;
F_89 ( V_104 ) ;
V_155:
if ( V_5 . V_146 )
F_99 ( V_5 . V_146 ) ;
if ( V_5 . V_147 )
F_99 ( V_5 . V_147 ) ;
V_154:
V_153:
F_72 () ;
return T_2 ;
}
static void F_113 ( struct V_148 * V_105 )
{
struct V_109 * V_104 = F_101 ( V_105 ) ;
V_1 = false ;
F_114 ( & V_104 -> V_105 , NULL ) ;
if ( V_5 . V_146 )
F_99 ( V_5 . V_146 ) ;
if ( V_5 . V_147 )
F_99 ( V_5 . V_147 ) ;
F_89 ( V_104 ) ;
F_112 ( & V_104 -> V_105 ) ;
F_72 () ;
}
static int F_115 ( struct V_148 * V_105 , void * V_68 )
{
struct V_148 * V_159 = V_68 ;
return V_105 == V_159 ;
}
static int F_116 ( struct V_148 * V_105 , void * V_68 )
{
struct V_160 * * V_161 = V_68 ;
if ( strstr ( F_117 ( V_105 ) , L_36 ) )
return 0 ;
F_118 ( V_105 -> V_134 , V_161 , F_115 , V_105 ) ;
return 0 ;
}
static int F_119 ( struct V_109 * V_104 )
{
struct V_160 * V_161 = NULL ;
int T_2 ;
F_120 ( & V_104 -> V_105 , & V_161 , F_116 ) ;
T_2 = F_121 ( & V_104 -> V_105 , & V_162 , V_161 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
static int F_122 ( struct V_109 * V_104 )
{
F_123 ( & V_104 -> V_105 , & V_162 ) ;
return 0 ;
}
static int F_124 ( struct V_148 * V_105 )
{
F_6 () ;
F_125 ( V_105 , 0 ) ;
F_126 ( V_105 ) ;
return 0 ;
}
static int F_127 ( struct V_148 * V_105 )
{
int T_2 ;
F_128 ( V_105 ) ;
T_2 = F_125 ( V_105 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_10 () ;
return 0 ;
}
int T_5 F_129 ( void )
{
return F_130 ( & V_163 ) ;
}
void F_131 ( void )
{
F_132 ( & V_163 ) ;
}
