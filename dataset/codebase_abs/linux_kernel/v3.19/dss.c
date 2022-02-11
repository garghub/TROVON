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
void F_11 ( int V_12 )
{
T_1 V_13 ;
F_12 ( V_12 > 3 || V_12 < 1 ) ;
V_13 = F_3 ( V_14 ) ;
V_13 = F_13 ( V_13 , 0xf , 19 , 15 ) ;
V_13 = F_13 ( V_13 , V_12 - 1 , 3 , 2 ) ;
V_13 = F_13 ( V_13 , 2 , 1 , 0 ) ;
F_1 ( V_14 , V_13 ) ;
V_13 = F_3 ( V_15 ) ;
V_13 = F_13 ( V_13 , 0x7 , 25 , 22 ) ;
V_13 = F_13 ( V_13 , 0xb , 16 , 11 ) ;
V_13 = F_13 ( V_13 , 0xb4 , 10 , 1 ) ;
F_1 ( V_15 , V_13 ) ;
}
int F_14 ( void )
{
unsigned long V_16 ;
F_15 ( 1 ) ;
F_16 ( V_15 , 1 , 18 , 18 ) ;
F_17 ( 1 ) ;
F_16 ( V_15 , 1 , 28 , 28 ) ;
V_16 = V_17 + F_18 ( 500 ) ;
while ( F_3 ( V_18 ) & ( 1 << 6 ) ) {
if ( F_19 ( V_17 , V_16 ) ) {
F_20 ( L_5 ) ;
goto V_19;
}
}
F_16 ( V_15 , 0 , 28 , 28 ) ;
V_16 = V_17 + F_18 ( 500 ) ;
while ( ! ( F_3 ( V_18 ) & ( 1 << 5 ) ) ) {
if ( F_19 ( V_17 , V_16 ) ) {
F_20 ( L_6 ) ;
goto V_19;
}
}
F_21 ( 1 ) ;
V_16 = V_17 + F_18 ( 500 ) ;
while ( ! ( F_3 ( V_18 ) & ( 1 << 2 ) ) ) {
if ( F_19 ( V_17 , V_16 ) ) {
F_20 ( L_7 ) ;
goto V_20;
}
}
return 0 ;
V_20:
F_21 ( 0 ) ;
V_19:
F_16 ( V_15 , 0 , 18 , 18 ) ;
F_15 ( 0 ) ;
return - V_21 ;
}
void F_22 ( void )
{
F_21 ( 0 ) ;
F_15 ( 0 ) ;
F_16 ( V_15 , 0 , 18 , 18 ) ;
}
const char * F_23 ( enum V_22 V_23 )
{
return V_24 [ V_23 ] ;
}
void F_24 ( struct V_25 * V_26 )
{
const char * V_27 , * V_28 ;
unsigned long V_29 ;
if ( F_25 () )
return;
F_26 ( V_26 , L_8 ) ;
V_27 = F_23 ( V_30 ) ;
V_28 = F_27 ( V_30 ) ;
V_29 = F_28 ( V_4 . V_31 ) ;
F_26 ( V_26 , L_9 ,
V_27 , V_28 ,
V_29 ) ;
F_29 () ;
}
static void F_30 ( struct V_25 * V_26 )
{
#define F_31 ( T_2 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_25 () )
return;
F_31 ( V_32 ) ;
F_31 ( V_33 ) ;
F_31 ( V_34 ) ;
F_31 ( V_35 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_31 ( V_14 ) ;
F_31 ( V_15 ) ;
F_31 ( V_18 ) ;
}
F_29 () ;
#undef F_31
}
static void F_32 ( enum V_22 V_23 )
{
int V_36 ;
T_3 V_37 , V_38 ;
switch ( V_23 ) {
case V_30 :
V_36 = 0 ;
break;
case V_39 :
V_36 = 1 ;
break;
case V_40 :
V_36 = 2 ;
break;
default:
F_33 () ;
return;
}
F_34 ( V_41 , & V_37 , & V_38 ) ;
F_16 ( V_35 , V_36 , V_37 , V_38 ) ;
V_4 . V_42 = V_23 ;
}
void F_35 ( int V_43 ,
enum V_22 V_23 )
{
int V_36 , V_44 ;
switch ( V_23 ) {
case V_30 :
V_36 = 0 ;
break;
case V_45 :
F_12 ( V_43 != 0 ) ;
V_36 = 1 ;
break;
case V_46 :
F_12 ( V_43 != 1 ) ;
V_36 = 1 ;
break;
default:
F_33 () ;
return;
}
V_44 = V_43 == 0 ? 1 : 10 ;
F_16 ( V_35 , V_36 , V_44 , V_44 ) ;
V_4 . V_47 [ V_43 ] = V_23 ;
}
void F_36 ( enum V_48 V_49 ,
enum V_22 V_23 )
{
int V_36 , V_50 , V_44 ;
if ( ! F_37 ( V_51 ) ) {
F_32 ( V_23 ) ;
return;
}
switch ( V_23 ) {
case V_30 :
V_36 = 0 ;
break;
case V_39 :
F_12 ( V_49 != V_7 ) ;
V_36 = 1 ;
break;
case V_40 :
F_12 ( V_49 != V_52 &&
V_49 != V_53 ) ;
V_36 = 1 ;
break;
default:
F_33 () ;
return;
}
V_44 = V_49 == V_7 ? 0 :
( V_49 == V_52 ? 12 : 19 ) ;
F_16 ( V_35 , V_36 , V_44 , V_44 ) ;
V_50 = V_49 == V_7 ? 0 :
( V_49 == V_52 ? 1 : 2 ) ;
V_4 . V_54 [ V_50 ] = V_23 ;
}
enum V_22 F_38 ( void )
{
return V_4 . V_42 ;
}
enum V_22 F_39 ( int V_43 )
{
return V_4 . V_47 [ V_43 ] ;
}
enum V_22 F_40 ( enum V_48 V_49 )
{
if ( F_37 ( V_51 ) ) {
int V_50 = V_49 == V_7 ? 0 :
( V_49 == V_52 ? 1 : 2 ) ;
return V_4 . V_54 [ V_50 ] ;
} else {
return V_4 . V_42 ;
}
}
bool F_41 ( unsigned long V_55 , unsigned long V_56 ,
T_4 V_57 , void * V_58 )
{
int V_59 , V_60 , V_61 ;
unsigned long V_62 ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
unsigned V_66 ;
V_63 = F_42 ( V_67 ) ;
if ( V_4 . V_68 == NULL ) {
unsigned V_69 ;
V_69 = V_63 / V_55 ;
V_62 = V_55 * V_69 ;
V_62 = F_43 ( V_4 . V_31 , V_62 ) ;
return V_57 ( V_62 , V_58 ) ;
}
V_64 = V_4 . V_70 -> V_71 ;
V_66 = V_4 . V_70 -> V_72 ;
V_65 = F_28 ( V_4 . V_68 ) ;
V_56 = V_56 ? V_56 : 1 ;
V_60 = F_44 ( V_65 * V_66 / V_56 , V_64 ) ;
V_61 = F_45 ( F_46 ( V_65 * V_66 , V_63 ) , 1ul ) ;
for ( V_59 = V_60 ; V_59 >= V_61 ; -- V_59 ) {
V_62 = F_46 ( V_65 , V_59 ) * V_66 ;
if ( V_57 ( V_62 , V_58 ) )
return true ;
}
return false ;
}
int F_47 ( unsigned long V_73 )
{
int T_2 ;
F_6 ( L_10 , V_73 ) ;
T_2 = F_48 ( V_4 . V_31 , V_73 ) ;
if ( T_2 )
return T_2 ;
V_4 . V_74 = F_28 ( V_4 . V_31 ) ;
F_49 ( V_4 . V_74 != V_73 ,
L_11 , V_4 . V_74 ,
V_73 ) ;
return 0 ;
}
unsigned long F_50 ( void )
{
return V_4 . V_74 ;
}
static int F_51 ( void )
{
unsigned long V_75 , V_65 ;
unsigned long V_62 ;
unsigned V_76 ;
int T_2 ;
V_75 = F_42 ( V_67 ) ;
if ( V_4 . V_68 == NULL ) {
V_62 = F_43 ( V_4 . V_31 , V_75 ) ;
} else {
V_65 = F_28 ( V_4 . V_68 ) ;
V_76 = F_46 ( V_65 * V_4 . V_70 -> V_72 ,
V_75 ) ;
V_62 = F_46 ( V_65 , V_76 ) * V_4 . V_70 -> V_72 ;
}
T_2 = F_47 ( V_62 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
void F_52 ( enum V_77 type )
{
int V_13 = 0 ;
if ( type == V_78 )
V_13 = 0 ;
else if ( type == V_79 )
V_13 = 1 ;
else
F_33 () ;
F_16 ( V_35 , V_13 , 6 , 6 ) ;
}
void F_53 ( bool V_80 )
{
F_16 ( V_35 , V_80 , 5 , 5 ) ;
}
void F_54 ( enum V_81 V_82 )
{
enum V_83 V_84 ;
V_84 = F_8 ( V_85 ) ;
F_55 ( ( V_82 == V_86 ) && ! ( V_84 & V_87 ) ) ;
F_55 ( ( V_82 == V_88 ) && ! ( V_84 & V_89 ) ) ;
if ( ( V_84 & V_87 ) && ( V_84 & V_89 ) )
F_16 ( V_35 , V_82 , 15 , 15 ) ;
}
enum V_81 F_56 ( void )
{
enum V_83 V_90 ;
V_90 = F_8 ( V_85 ) ;
if ( ( V_90 & V_89 ) == 0 )
return V_86 ;
if ( ( V_90 & V_87 ) == 0 )
return V_88 ;
return F_57 ( V_35 , 15 , 15 ) ;
}
static int F_58 ( int V_91 , enum V_48 V_49 )
{
if ( V_49 != V_7 )
return - V_92 ;
return 0 ;
}
static int F_59 ( int V_91 , enum V_48 V_49 )
{
int V_3 ;
switch ( V_49 ) {
case V_52 :
V_3 = 0 ;
break;
case V_85 :
V_3 = 1 ;
break;
default:
return - V_92 ;
}
F_16 ( V_35 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_60 ( int V_91 , enum V_48 V_49 )
{
int V_3 ;
switch ( V_49 ) {
case V_7 :
V_3 = 1 ;
break;
case V_52 :
V_3 = 2 ;
break;
case V_53 :
V_3 = 3 ;
break;
case V_85 :
V_3 = 0 ;
break;
default:
return - V_92 ;
}
F_16 ( V_35 , V_3 , 17 , 16 ) ;
return 0 ;
}
int F_61 ( int V_91 , enum V_48 V_49 )
{
return V_4 . V_70 -> V_93 ( V_91 , V_49 ) ;
}
static int F_62 ( void )
{
struct V_94 * V_94 ;
V_94 = F_63 ( & V_4 . V_95 -> V_96 , L_12 ) ;
if ( F_64 ( V_94 ) ) {
F_20 ( L_13 ) ;
return F_65 ( V_94 ) ;
}
V_4 . V_31 = V_94 ;
if ( V_4 . V_70 -> V_97 ) {
V_94 = F_66 ( NULL , V_4 . V_70 -> V_97 ) ;
if ( F_64 ( V_94 ) ) {
F_20 ( L_14 , V_4 . V_70 -> V_97 ) ;
return F_65 ( V_94 ) ;
}
} else {
V_94 = NULL ;
}
V_4 . V_68 = V_94 ;
return 0 ;
}
static void F_67 ( void )
{
if ( V_4 . V_68 )
F_68 ( V_4 . V_68 ) ;
}
static int F_25 ( void )
{
int T_2 ;
F_6 ( L_15 ) ;
T_2 = F_69 ( & V_4 . V_95 -> V_96 ) ;
F_55 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
static void F_29 ( void )
{
int T_2 ;
F_6 ( L_16 ) ;
T_2 = F_70 ( & V_4 . V_95 -> V_96 ) ;
F_55 ( T_2 < 0 && T_2 != - V_98 && T_2 != - V_99 ) ;
}
void F_71 ( struct V_25 * V_26 )
{
F_24 ( V_26 ) ;
F_72 ( V_26 ) ;
#ifdef F_73
F_74 ( V_26 ) ;
#endif
}
static int T_5 F_75 ( struct V_100 * V_95 )
{
const struct V_101 * V_82 ;
struct V_101 * V_102 ;
V_102 = F_76 ( & V_95 -> V_96 , sizeof( * V_102 ) , V_103 ) ;
if ( ! V_102 ) {
F_77 ( & V_95 -> V_96 , L_17 ) ;
return - V_104 ;
}
switch ( F_78 () ) {
case V_105 :
V_82 = & V_106 ;
break;
case V_107 :
case V_108 :
case V_109 :
V_82 = & V_110 ;
break;
case V_111 :
V_82 = & V_112 ;
break;
case V_113 :
case V_114 :
case V_115 :
V_82 = & V_116 ;
break;
case V_117 :
V_82 = & V_118 ;
break;
case V_119 :
V_82 = & V_120 ;
break;
default:
return - V_121 ;
}
memcpy ( V_102 , V_82 , sizeof( * V_102 ) ) ;
V_4 . V_70 = V_102 ;
return 0 ;
}
static int T_5 F_79 ( struct V_100 * V_95 )
{
struct V_122 * V_123 = V_95 -> V_96 . V_124 ;
struct V_122 * V_91 ;
int T_2 ;
if ( V_123 == NULL )
return 0 ;
V_91 = F_80 ( V_123 , NULL ) ;
if ( ! V_91 )
return 0 ;
if ( V_4 . V_70 -> V_125 == 0 )
return 0 ;
do {
enum V_83 V_126 ;
T_1 V_127 ;
T_2 = F_81 ( V_91 , L_18 , & V_127 ) ;
if ( T_2 )
V_127 = 0 ;
if ( V_127 >= V_4 . V_70 -> V_125 )
continue;
V_126 = V_4 . V_70 -> V_128 [ V_127 ] ;
switch ( V_126 ) {
case V_129 :
F_82 ( V_95 , V_91 ) ;
break;
case V_8 :
F_83 ( V_95 , V_91 ) ;
break;
default:
break;
}
} while ( ( V_91 = F_80 ( V_123 , V_91 ) ) != NULL );
return 0 ;
}
static void T_6 F_84 ( struct V_100 * V_95 )
{
struct V_122 * V_123 = V_95 -> V_96 . V_124 ;
struct V_122 * V_91 ;
if ( V_123 == NULL )
return;
V_91 = F_80 ( V_123 , NULL ) ;
if ( ! V_91 )
return;
if ( V_4 . V_70 -> V_125 == 0 )
return;
do {
enum V_83 V_126 ;
T_1 V_127 ;
int T_2 ;
T_2 = F_81 ( V_91 , L_18 , & V_127 ) ;
if ( T_2 )
V_127 = 0 ;
if ( V_127 >= V_4 . V_70 -> V_125 )
continue;
V_126 = V_4 . V_70 -> V_128 [ V_127 ] ;
switch ( V_126 ) {
case V_129 :
F_85 ( V_91 ) ;
break;
case V_8 :
F_86 ( V_91 ) ;
break;
default:
break;
}
} while ( ( V_91 = F_80 ( V_123 , V_91 ) ) != NULL );
}
static int T_5 F_87 ( struct V_100 * V_95 )
{
struct V_130 * V_131 ;
T_1 V_132 ;
int T_2 ;
V_4 . V_95 = V_95 ;
T_2 = F_75 ( V_4 . V_95 ) ;
if ( T_2 )
return T_2 ;
V_131 = F_88 ( V_4 . V_95 , V_133 , 0 ) ;
if ( ! V_131 ) {
F_20 ( L_19 ) ;
return - V_92 ;
}
V_4 . V_5 = F_89 ( & V_95 -> V_96 , V_131 -> V_37 ,
F_90 ( V_131 ) ) ;
if ( ! V_4 . V_5 ) {
F_20 ( L_20 ) ;
return - V_104 ;
}
T_2 = F_62 () ;
if ( T_2 )
return T_2 ;
T_2 = F_51 () ;
if ( T_2 )
goto V_134;
F_91 ( & V_95 -> V_96 ) ;
T_2 = F_25 () ;
if ( T_2 )
goto V_135;
V_4 . V_74 = F_28 ( V_4 . V_31 ) ;
F_16 ( V_35 , 0 , 0 , 0 ) ;
F_32 ( V_30 ) ;
#ifdef F_92
F_16 ( V_35 , 1 , 4 , 4 ) ;
F_16 ( V_35 , 1 , 3 , 3 ) ;
F_16 ( V_35 , 0 , 2 , 2 ) ;
#endif
V_4 . V_47 [ 0 ] = V_30 ;
V_4 . V_47 [ 1 ] = V_30 ;
V_4 . V_42 = V_30 ;
V_4 . V_54 [ 0 ] = V_30 ;
V_4 . V_54 [ 1 ] = V_30 ;
F_79 ( V_95 ) ;
V_132 = F_3 ( V_32 ) ;
F_93 ( V_136 L_21 ,
F_94 ( V_132 , 7 , 4 ) , F_94 ( V_132 , 3 , 0 ) ) ;
F_29 () ;
F_95 ( L_22 , F_30 ) ;
return 0 ;
V_135:
F_96 ( & V_95 -> V_96 ) ;
V_134:
F_67 () ;
return T_2 ;
}
static int T_6 F_97 ( struct V_100 * V_95 )
{
F_84 ( V_95 ) ;
F_96 ( & V_95 -> V_96 ) ;
F_67 () ;
return 0 ;
}
static int F_98 ( struct V_137 * V_96 )
{
F_5 () ;
F_99 ( V_96 , 0 ) ;
return 0 ;
}
static int F_100 ( struct V_137 * V_96 )
{
int T_2 ;
T_2 = F_99 ( V_96 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_101 ( void )
{
return F_102 ( & V_138 , F_87 ) ;
}
void F_103 ( void )
{
F_104 ( & V_138 ) ;
}
