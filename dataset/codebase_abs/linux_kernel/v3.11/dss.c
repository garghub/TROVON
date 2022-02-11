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
int F_11 ( void )
{
struct V_12 * V_13 = F_12 () ;
struct V_14 * V_15 = V_13 -> V_16 . V_17 ;
int V_18 ;
if ( ! V_15 -> V_19 )
return - V_20 ;
V_18 = V_15 -> V_19 ( & V_4 . V_21 -> V_16 ) ;
F_13 ( V_18 < 0 , L_5 , V_18 ) ;
return V_18 ;
}
void F_14 ( int V_22 )
{
T_1 V_23 ;
F_15 ( V_22 > 3 || V_22 < 1 ) ;
V_23 = F_3 ( V_24 ) ;
V_23 = F_16 ( V_23 , 0xf , 19 , 15 ) ;
V_23 = F_16 ( V_23 , V_22 - 1 , 3 , 2 ) ;
V_23 = F_16 ( V_23 , 2 , 1 , 0 ) ;
F_1 ( V_24 , V_23 ) ;
V_23 = F_3 ( V_25 ) ;
V_23 = F_16 ( V_23 , 0x7 , 25 , 22 ) ;
V_23 = F_16 ( V_23 , 0xb , 16 , 11 ) ;
V_23 = F_16 ( V_23 , 0xb4 , 10 , 1 ) ;
F_1 ( V_25 , V_23 ) ;
}
int F_17 ( void )
{
unsigned long V_26 ;
F_18 ( 1 ) ;
F_19 ( V_25 , 1 , 18 , 18 ) ;
F_20 ( 1 ) ;
F_19 ( V_25 , 1 , 28 , 28 ) ;
V_26 = V_27 + F_21 ( 500 ) ;
while ( F_3 ( V_28 ) & ( 1 << 6 ) ) {
if ( F_22 ( V_27 , V_26 ) ) {
F_23 ( L_6 ) ;
goto V_29;
}
}
F_19 ( V_25 , 0 , 28 , 28 ) ;
V_26 = V_27 + F_21 ( 500 ) ;
while ( ! ( F_3 ( V_28 ) & ( 1 << 5 ) ) ) {
if ( F_22 ( V_27 , V_26 ) ) {
F_23 ( L_7 ) ;
goto V_29;
}
}
F_24 ( 1 ) ;
V_26 = V_27 + F_21 ( 500 ) ;
while ( ! ( F_3 ( V_28 ) & ( 1 << 2 ) ) ) {
if ( F_22 ( V_27 , V_26 ) ) {
F_23 ( L_8 ) ;
goto V_30;
}
}
return 0 ;
V_30:
F_24 ( 0 ) ;
V_29:
F_19 ( V_25 , 0 , 18 , 18 ) ;
F_18 ( 0 ) ;
return - V_31 ;
}
void F_25 ( void )
{
F_24 ( 0 ) ;
F_18 ( 0 ) ;
F_19 ( V_25 , 0 , 18 , 18 ) ;
}
const char * F_26 ( enum V_32 V_33 )
{
return V_34 [ V_33 ] ;
}
void F_27 ( struct V_35 * V_36 )
{
unsigned long V_37 ;
unsigned long V_38 ;
const char * V_39 , * V_40 ;
unsigned long V_41 ;
if ( F_28 () )
return;
F_29 ( V_36 , L_9 ) ;
V_39 = F_26 ( V_42 ) ;
V_40 = F_30 ( V_42 ) ;
V_41 = F_31 ( V_4 . V_43 ) ;
if ( V_4 . V_44 ) {
V_37 = F_31 ( F_32 ( V_4 . V_44 ) ) ;
V_38 = F_31 ( V_4 . V_44 ) ;
F_29 ( V_36 , L_10 , V_37 ) ;
F_29 ( V_36 , L_11 ,
V_39 , V_40 , V_37 ,
V_37 / V_38 ,
V_4 . V_45 -> V_46 , V_41 ) ;
} else {
F_29 ( V_36 , L_12 ,
V_39 , V_40 ,
V_41 ) ;
}
F_33 () ;
}
static void F_34 ( struct V_35 * V_36 )
{
#define F_35 ( T_2 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_28 () )
return;
F_35 ( V_47 ) ;
F_35 ( V_48 ) ;
F_35 ( V_49 ) ;
F_35 ( V_50 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_35 ( V_24 ) ;
F_35 ( V_25 ) ;
F_35 ( V_28 ) ;
}
F_33 () ;
#undef F_35
}
static void F_36 ( enum V_32 V_33 )
{
struct V_12 * V_51 ;
int V_52 ;
T_3 V_53 , V_54 ;
switch ( V_33 ) {
case V_42 :
V_52 = 0 ;
break;
case V_55 :
V_52 = 1 ;
V_51 = F_37 ( 0 ) ;
F_38 ( V_51 ) ;
break;
case V_56 :
V_52 = 2 ;
V_51 = F_37 ( 1 ) ;
F_38 ( V_51 ) ;
break;
default:
F_39 () ;
return;
}
F_40 ( V_57 , & V_53 , & V_54 ) ;
F_19 ( V_50 , V_52 , V_53 , V_54 ) ;
V_4 . V_58 = V_33 ;
}
void F_41 ( int V_59 ,
enum V_32 V_33 )
{
struct V_12 * V_51 ;
int V_52 , V_60 ;
switch ( V_33 ) {
case V_42 :
V_52 = 0 ;
break;
case V_61 :
F_15 ( V_59 != 0 ) ;
V_52 = 1 ;
V_51 = F_37 ( 0 ) ;
F_42 ( V_51 ) ;
break;
case V_62 :
F_15 ( V_59 != 1 ) ;
V_52 = 1 ;
V_51 = F_37 ( 1 ) ;
F_42 ( V_51 ) ;
break;
default:
F_39 () ;
return;
}
V_60 = V_59 == 0 ? 1 : 10 ;
F_19 ( V_50 , V_52 , V_60 , V_60 ) ;
V_4 . V_63 [ V_59 ] = V_33 ;
}
void F_43 ( enum V_64 V_65 ,
enum V_32 V_33 )
{
struct V_12 * V_51 ;
int V_52 , V_66 , V_60 ;
if ( ! F_44 ( V_67 ) ) {
F_36 ( V_33 ) ;
return;
}
switch ( V_33 ) {
case V_42 :
V_52 = 0 ;
break;
case V_55 :
F_15 ( V_65 != V_7 ) ;
V_52 = 1 ;
V_51 = F_37 ( 0 ) ;
F_38 ( V_51 ) ;
break;
case V_56 :
F_15 ( V_65 != V_68 &&
V_65 != V_69 ) ;
V_52 = 1 ;
V_51 = F_37 ( 1 ) ;
F_38 ( V_51 ) ;
break;
default:
F_39 () ;
return;
}
V_60 = V_65 == V_7 ? 0 :
( V_65 == V_68 ? 12 : 19 ) ;
F_19 ( V_50 , V_52 , V_60 , V_60 ) ;
V_66 = V_65 == V_7 ? 0 :
( V_65 == V_68 ? 1 : 2 ) ;
V_4 . V_70 [ V_66 ] = V_33 ;
}
enum V_32 F_45 ( void )
{
return V_4 . V_58 ;
}
enum V_32 F_46 ( int V_59 )
{
return V_4 . V_63 [ V_59 ] ;
}
enum V_32 F_47 ( enum V_64 V_65 )
{
if ( F_44 ( V_67 ) ) {
int V_66 = V_65 == V_7 ? 0 :
( V_65 == V_68 ? 1 : 2 ) ;
return V_4 . V_70 [ V_66 ] ;
} else {
return V_4 . V_58 ;
}
}
int F_48 ( struct V_71 * V_72 )
{
if ( V_4 . V_44 ) {
unsigned long V_73 ;
if ( V_72 -> V_74 > V_4 . V_45 -> V_75 ||
V_72 -> V_74 == 0 )
return - V_76 ;
V_73 = F_31 ( F_32 ( V_4 . V_44 ) ) ;
V_72 -> V_77 = V_73 / V_72 -> V_74 *
V_4 . V_45 -> V_46 ;
} else {
if ( V_72 -> V_74 != 0 )
return - V_76 ;
V_72 -> V_77 = F_31 ( V_4 . V_43 ) ;
}
return 0 ;
}
bool F_49 ( unsigned long V_78 , T_4 V_79 , void * V_80 )
{
int V_81 , V_82 , V_83 ;
unsigned long V_77 ;
unsigned long V_84 ;
unsigned long V_85 ;
unsigned long V_73 ;
unsigned V_86 ;
if ( V_4 . V_44 == NULL ) {
V_77 = F_31 ( V_4 . V_43 ) ;
V_81 = 1 ;
return V_79 ( V_81 , V_77 , V_80 ) ;
}
V_84 = F_50 ( V_87 ) ;
V_85 = V_4 . V_45 -> V_75 ;
V_86 = V_4 . V_45 -> V_46 ;
V_73 = F_51 () ;
V_78 = V_78 ? V_78 : 1 ;
V_82 = F_52 ( V_73 * V_86 / V_78 , V_85 ) ;
V_83 = F_53 ( F_54 ( V_73 * V_86 , V_84 ) , 1ul ) ;
for ( V_81 = V_82 ; V_81 >= V_83 ; -- V_81 ) {
V_77 = V_73 / V_81 * V_86 ;
if ( V_79 ( V_81 , V_77 , V_80 ) )
return true ;
}
return false ;
}
int F_55 ( struct V_71 * V_72 )
{
if ( V_4 . V_44 ) {
unsigned long V_73 ;
int T_2 ;
V_73 = F_31 ( F_32 ( V_4 . V_44 ) ) ;
F_6 ( L_13 , V_73 ) ;
T_2 = F_56 ( V_4 . V_44 ,
F_54 ( V_73 , V_72 -> V_74 ) ) ;
if ( T_2 )
return T_2 ;
} else {
if ( V_72 -> V_74 != 0 )
return - V_76 ;
}
V_4 . V_88 = F_31 ( V_4 . V_43 ) ;
F_13 ( V_4 . V_88 != V_72 -> V_77 ,
L_14 , V_4 . V_88 ,
V_72 -> V_77 ) ;
F_6 ( L_15 , V_72 -> V_77 , V_72 -> V_74 ) ;
return 0 ;
}
unsigned long F_51 ( void )
{
if ( V_4 . V_44 )
return F_31 ( F_32 ( V_4 . V_44 ) ) ;
else
return 0 ;
}
unsigned long F_57 ( void )
{
return V_4 . V_88 ;
}
static int F_58 ( void )
{
unsigned long V_89 , V_73 ;
unsigned V_74 ;
struct V_71 V_90 = { 0 } ;
int T_2 ;
if ( V_4 . V_44 == NULL )
return 0 ;
V_89 = F_50 ( V_87 ) ;
V_73 = F_51 () ;
V_74 = F_54 ( V_73 * V_4 . V_45 -> V_46 ,
V_89 ) ;
V_90 . V_74 = V_74 ;
T_2 = F_48 ( & V_90 ) ;
if ( T_2 )
return T_2 ;
T_2 = F_55 ( & V_90 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
void F_59 ( enum V_91 type )
{
int V_23 = 0 ;
if ( type == V_92 )
V_23 = 0 ;
else if ( type == V_93 )
V_23 = 1 ;
else
F_39 () ;
F_19 ( V_50 , V_23 , 6 , 6 ) ;
}
void F_60 ( bool V_94 )
{
F_19 ( V_50 , V_94 , 5 , 5 ) ;
}
void F_61 ( enum V_95 V_96 )
{
enum V_97 V_98 ;
V_98 = F_8 ( V_99 ) ;
F_62 ( ( V_96 == V_100 ) && ! ( V_98 & V_101 ) ) ;
F_62 ( ( V_96 == V_102 ) && ! ( V_98 & V_103 ) ) ;
if ( ( V_98 & V_101 ) && ( V_98 & V_103 ) )
F_19 ( V_50 , V_96 , 15 , 15 ) ;
}
enum V_95 F_63 ( void )
{
enum V_97 V_104 ;
V_104 = F_8 ( V_99 ) ;
if ( ( V_104 & V_103 ) == 0 )
return V_100 ;
if ( ( V_104 & V_101 ) == 0 )
return V_102 ;
return F_64 ( V_50 , 15 , 15 ) ;
}
static int F_65 ( enum V_64 V_65 )
{
if ( V_65 != V_7 )
return - V_76 ;
return 0 ;
}
static int F_66 ( enum V_64 V_65 )
{
int V_3 ;
switch ( V_65 ) {
case V_68 :
V_3 = 0 ;
break;
case V_99 :
V_3 = 1 ;
break;
default:
return - V_76 ;
}
F_19 ( V_50 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_67 ( enum V_64 V_65 )
{
int V_3 ;
switch ( V_65 ) {
case V_7 :
V_3 = 1 ;
break;
case V_68 :
V_3 = 2 ;
break;
case V_69 :
V_3 = 3 ;
break;
case V_99 :
V_3 = 0 ;
break;
default:
return - V_76 ;
}
F_19 ( V_50 , V_3 , 17 , 16 ) ;
return 0 ;
}
int F_68 ( enum V_64 V_65 )
{
return V_4 . V_45 -> V_105 ( V_65 ) ;
}
static int F_69 ( void )
{
struct V_106 * V_106 ;
V_106 = F_70 ( & V_4 . V_21 -> V_16 , L_16 ) ;
if ( F_71 ( V_106 ) ) {
F_23 ( L_17 ) ;
return F_72 ( V_106 ) ;
}
V_4 . V_43 = V_106 ;
if ( V_4 . V_45 -> V_107 ) {
V_106 = F_73 ( NULL , V_4 . V_45 -> V_107 ) ;
if ( F_71 ( V_106 ) ) {
F_23 ( L_18 , V_4 . V_45 -> V_107 ) ;
return F_72 ( V_106 ) ;
}
} else {
V_106 = NULL ;
}
V_4 . V_44 = V_106 ;
return 0 ;
}
static void F_74 ( void )
{
if ( V_4 . V_44 )
F_75 ( V_4 . V_44 ) ;
}
static int F_28 ( void )
{
int T_2 ;
F_6 ( L_19 ) ;
T_2 = F_76 ( & V_4 . V_21 -> V_16 ) ;
F_62 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
static void F_33 ( void )
{
int T_2 ;
F_6 ( L_20 ) ;
T_2 = F_77 ( & V_4 . V_21 -> V_16 ) ;
F_62 ( T_2 < 0 && T_2 != - V_108 && T_2 != - V_109 ) ;
}
void F_78 ( struct V_35 * V_36 )
{
F_27 ( V_36 ) ;
F_79 ( V_36 ) ;
#ifdef F_80
F_81 ( V_36 ) ;
#endif
}
static int T_5 F_82 ( struct V_12 * V_21 )
{
const struct V_110 * V_96 ;
struct V_110 * V_111 ;
V_111 = F_83 ( & V_21 -> V_16 , sizeof( * V_111 ) , V_112 ) ;
if ( ! V_111 ) {
F_84 ( & V_21 -> V_16 , L_21 ) ;
return - V_113 ;
}
switch ( F_85 () ) {
case V_114 :
V_96 = & V_115 ;
break;
case V_116 :
case V_117 :
case V_118 :
V_96 = & V_119 ;
break;
case V_120 :
V_96 = & V_121 ;
break;
case V_122 :
case V_123 :
case V_124 :
V_96 = & V_125 ;
break;
case V_126 :
V_96 = & V_127 ;
break;
default:
return - V_128 ;
}
memcpy ( V_111 , V_96 , sizeof( * V_111 ) ) ;
V_4 . V_45 = V_111 ;
return 0 ;
}
static int T_5 F_86 ( struct V_12 * V_21 )
{
struct V_129 * V_130 ;
T_1 V_131 ;
int T_2 ;
V_4 . V_21 = V_21 ;
T_2 = F_82 ( V_4 . V_21 ) ;
if ( T_2 )
return T_2 ;
V_130 = F_87 ( V_4 . V_21 , V_132 , 0 ) ;
if ( ! V_130 ) {
F_23 ( L_22 ) ;
return - V_76 ;
}
V_4 . V_5 = F_88 ( & V_21 -> V_16 , V_130 -> V_53 ,
F_89 ( V_130 ) ) ;
if ( ! V_4 . V_5 ) {
F_23 ( L_23 ) ;
return - V_113 ;
}
T_2 = F_69 () ;
if ( T_2 )
return T_2 ;
T_2 = F_58 () ;
if ( T_2 )
goto V_133;
F_90 ( & V_21 -> V_16 ) ;
T_2 = F_28 () ;
if ( T_2 )
goto V_134;
V_4 . V_88 = F_31 ( V_4 . V_43 ) ;
F_19 ( V_50 , 0 , 0 , 0 ) ;
F_36 ( V_42 ) ;
#ifdef F_91
F_19 ( V_50 , 1 , 4 , 4 ) ;
F_19 ( V_50 , 1 , 3 , 3 ) ;
F_19 ( V_50 , 0 , 2 , 2 ) ;
#endif
V_4 . V_63 [ 0 ] = V_42 ;
V_4 . V_63 [ 1 ] = V_42 ;
V_4 . V_58 = V_42 ;
V_4 . V_70 [ 0 ] = V_42 ;
V_4 . V_70 [ 1 ] = V_42 ;
V_131 = F_3 ( V_47 ) ;
F_92 ( V_135 L_24 ,
F_93 ( V_131 , 7 , 4 ) , F_93 ( V_131 , 3 , 0 ) ) ;
F_33 () ;
F_94 ( L_25 , F_34 ) ;
return 0 ;
V_134:
F_95 ( & V_21 -> V_16 ) ;
V_133:
F_74 () ;
return T_2 ;
}
static int T_6 F_96 ( struct V_12 * V_21 )
{
F_95 ( & V_21 -> V_16 ) ;
F_74 () ;
return 0 ;
}
static int F_97 ( struct V_136 * V_16 )
{
F_5 () ;
F_98 ( V_16 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_136 * V_16 )
{
int T_2 ;
T_2 = F_98 ( V_16 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_100 ( void )
{
return F_101 ( & V_137 , F_86 ) ;
}
void F_102 ( void )
{
F_103 ( & V_137 ) ;
}
