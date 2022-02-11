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
struct V_12 * V_13 = V_4 . V_14 -> V_15 . V_16 ;
int V_17 ;
if ( ! V_13 -> V_18 )
return - V_19 ;
V_17 = V_13 -> V_18 ( & V_4 . V_14 -> V_15 ) ;
F_12 ( V_17 < 0 , L_5 , V_17 ) ;
return V_17 ;
}
void F_13 ( int V_20 )
{
T_1 V_21 ;
F_14 ( V_20 > 3 || V_20 < 1 ) ;
V_21 = F_3 ( V_22 ) ;
V_21 = F_15 ( V_21 , 0xf , 19 , 15 ) ;
V_21 = F_15 ( V_21 , V_20 - 1 , 3 , 2 ) ;
V_21 = F_15 ( V_21 , 2 , 1 , 0 ) ;
F_1 ( V_22 , V_21 ) ;
V_21 = F_3 ( V_23 ) ;
V_21 = F_15 ( V_21 , 0x7 , 25 , 22 ) ;
V_21 = F_15 ( V_21 , 0xb , 16 , 11 ) ;
V_21 = F_15 ( V_21 , 0xb4 , 10 , 1 ) ;
F_1 ( V_23 , V_21 ) ;
}
int F_16 ( void )
{
unsigned long V_24 ;
F_17 ( 1 ) ;
F_18 ( V_23 , 1 , 18 , 18 ) ;
F_19 ( 1 ) ;
F_18 ( V_23 , 1 , 28 , 28 ) ;
V_24 = V_25 + F_20 ( 500 ) ;
while ( F_3 ( V_26 ) & ( 1 << 6 ) ) {
if ( F_21 ( V_25 , V_24 ) ) {
F_22 ( L_6 ) ;
goto V_27;
}
}
F_18 ( V_23 , 0 , 28 , 28 ) ;
V_24 = V_25 + F_20 ( 500 ) ;
while ( ! ( F_3 ( V_26 ) & ( 1 << 5 ) ) ) {
if ( F_21 ( V_25 , V_24 ) ) {
F_22 ( L_7 ) ;
goto V_27;
}
}
F_23 ( 1 ) ;
V_24 = V_25 + F_20 ( 500 ) ;
while ( ! ( F_3 ( V_26 ) & ( 1 << 2 ) ) ) {
if ( F_21 ( V_25 , V_24 ) ) {
F_22 ( L_8 ) ;
goto V_28;
}
}
return 0 ;
V_28:
F_23 ( 0 ) ;
V_27:
F_18 ( V_23 , 0 , 18 , 18 ) ;
F_17 ( 0 ) ;
return - V_29 ;
}
void F_24 ( void )
{
F_23 ( 0 ) ;
F_17 ( 0 ) ;
F_18 ( V_23 , 0 , 18 , 18 ) ;
}
const char * F_25 ( enum V_30 V_31 )
{
return V_32 [ V_31 ] ;
}
void F_26 ( struct V_33 * V_34 )
{
unsigned long V_35 ;
unsigned long V_36 ;
const char * V_37 , * V_38 ;
unsigned long V_39 ;
if ( F_27 () )
return;
F_28 ( V_34 , L_9 ) ;
V_37 = F_25 ( V_40 ) ;
V_38 = F_29 ( V_40 ) ;
V_39 = F_30 ( V_4 . V_41 ) ;
if ( V_4 . V_42 ) {
V_35 = F_30 ( F_31 ( V_4 . V_42 ) ) ;
V_36 = F_30 ( V_4 . V_42 ) ;
F_28 ( V_34 , L_10 , V_35 ) ;
F_28 ( V_34 , L_11 ,
V_37 , V_38 , V_35 ,
V_35 / V_36 ,
V_4 . V_43 -> V_44 , V_39 ) ;
} else {
F_28 ( V_34 , L_12 ,
V_37 , V_38 ,
V_39 ) ;
}
F_32 () ;
}
static void F_33 ( struct V_33 * V_34 )
{
#define F_34 ( T_2 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_27 () )
return;
F_34 ( V_45 ) ;
F_34 ( V_46 ) ;
F_34 ( V_47 ) ;
F_34 ( V_48 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_34 ( V_22 ) ;
F_34 ( V_23 ) ;
F_34 ( V_26 ) ;
}
F_32 () ;
#undef F_34
}
static void F_35 ( enum V_30 V_31 )
{
struct V_49 * V_50 ;
int V_51 ;
T_3 V_52 , V_53 ;
switch ( V_31 ) {
case V_40 :
V_51 = 0 ;
break;
case V_54 :
V_51 = 1 ;
V_50 = F_36 ( 0 ) ;
F_37 ( V_50 ) ;
break;
case V_55 :
V_51 = 2 ;
V_50 = F_36 ( 1 ) ;
F_37 ( V_50 ) ;
break;
default:
F_38 () ;
return;
}
F_39 ( V_56 , & V_52 , & V_53 ) ;
F_18 ( V_48 , V_51 , V_52 , V_53 ) ;
V_4 . V_57 = V_31 ;
}
void F_40 ( int V_58 ,
enum V_30 V_31 )
{
struct V_49 * V_50 ;
int V_51 , V_59 ;
switch ( V_31 ) {
case V_40 :
V_51 = 0 ;
break;
case V_60 :
F_14 ( V_58 != 0 ) ;
V_51 = 1 ;
V_50 = F_36 ( 0 ) ;
F_41 ( V_50 ) ;
break;
case V_61 :
F_14 ( V_58 != 1 ) ;
V_51 = 1 ;
V_50 = F_36 ( 1 ) ;
F_41 ( V_50 ) ;
break;
default:
F_38 () ;
return;
}
V_59 = V_58 == 0 ? 1 : 10 ;
F_18 ( V_48 , V_51 , V_59 , V_59 ) ;
V_4 . V_62 [ V_58 ] = V_31 ;
}
void F_42 ( enum V_63 V_64 ,
enum V_30 V_31 )
{
struct V_49 * V_50 ;
int V_51 , V_65 , V_59 ;
if ( ! F_43 ( V_66 ) ) {
F_35 ( V_31 ) ;
return;
}
switch ( V_31 ) {
case V_40 :
V_51 = 0 ;
break;
case V_54 :
F_14 ( V_64 != V_7 ) ;
V_51 = 1 ;
V_50 = F_36 ( 0 ) ;
F_37 ( V_50 ) ;
break;
case V_55 :
F_14 ( V_64 != V_67 &&
V_64 != V_68 ) ;
V_51 = 1 ;
V_50 = F_36 ( 1 ) ;
F_37 ( V_50 ) ;
break;
default:
F_38 () ;
return;
}
V_59 = V_64 == V_7 ? 0 :
( V_64 == V_67 ? 12 : 19 ) ;
F_18 ( V_48 , V_51 , V_59 , V_59 ) ;
V_65 = V_64 == V_7 ? 0 :
( V_64 == V_67 ? 1 : 2 ) ;
V_4 . V_69 [ V_65 ] = V_31 ;
}
enum V_30 F_44 ( void )
{
return V_4 . V_57 ;
}
enum V_30 F_45 ( int V_58 )
{
return V_4 . V_62 [ V_58 ] ;
}
enum V_30 F_46 ( enum V_63 V_64 )
{
if ( F_43 ( V_66 ) ) {
int V_65 = V_64 == V_7 ? 0 :
( V_64 == V_67 ? 1 : 2 ) ;
return V_4 . V_69 [ V_65 ] ;
} else {
return V_4 . V_57 ;
}
}
int F_47 ( struct V_70 * V_71 )
{
if ( V_4 . V_42 ) {
unsigned long V_72 ;
if ( V_71 -> V_73 > V_4 . V_43 -> V_74 ||
V_71 -> V_73 == 0 )
return - V_75 ;
V_72 = F_30 ( F_31 ( V_4 . V_42 ) ) ;
V_71 -> V_76 = V_72 / V_71 -> V_73 *
V_4 . V_43 -> V_44 ;
} else {
if ( V_71 -> V_73 != 0 )
return - V_75 ;
V_71 -> V_76 = F_30 ( V_4 . V_41 ) ;
}
return 0 ;
}
bool F_48 ( unsigned long V_77 , T_4 V_78 , void * V_79 )
{
int V_80 , V_81 , V_82 ;
unsigned long V_76 ;
unsigned long V_83 ;
unsigned long V_84 ;
unsigned long V_72 ;
unsigned V_85 ;
if ( V_4 . V_42 == NULL ) {
V_76 = F_30 ( V_4 . V_41 ) ;
V_80 = 1 ;
return V_78 ( V_80 , V_76 , V_79 ) ;
}
V_83 = F_49 ( V_86 ) ;
V_84 = V_4 . V_43 -> V_74 ;
V_85 = V_4 . V_43 -> V_44 ;
V_72 = F_50 () ;
V_77 = V_77 ? V_77 : 1 ;
V_81 = F_51 ( V_72 * V_85 / V_77 , V_84 ) ;
V_82 = F_52 ( F_53 ( V_72 * V_85 , V_83 ) , 1ul ) ;
for ( V_80 = V_81 ; V_80 >= V_82 ; -- V_80 ) {
V_76 = V_72 / V_80 * V_85 ;
if ( V_78 ( V_80 , V_76 , V_79 ) )
return true ;
}
return false ;
}
int F_54 ( struct V_70 * V_71 )
{
if ( V_4 . V_42 ) {
unsigned long V_72 ;
int T_2 ;
V_72 = F_30 ( F_31 ( V_4 . V_42 ) ) ;
F_6 ( L_13 , V_72 ) ;
T_2 = F_55 ( V_4 . V_42 ,
F_53 ( V_72 , V_71 -> V_73 ) ) ;
if ( T_2 )
return T_2 ;
} else {
if ( V_71 -> V_73 != 0 )
return - V_75 ;
}
V_4 . V_87 = F_30 ( V_4 . V_41 ) ;
F_12 ( V_4 . V_87 != V_71 -> V_76 ,
L_14 , V_4 . V_87 ,
V_71 -> V_76 ) ;
F_6 ( L_15 , V_71 -> V_76 , V_71 -> V_73 ) ;
return 0 ;
}
unsigned long F_50 ( void )
{
if ( V_4 . V_42 )
return F_30 ( F_31 ( V_4 . V_42 ) ) ;
else
return 0 ;
}
unsigned long F_56 ( void )
{
return V_4 . V_87 ;
}
static int F_57 ( void )
{
unsigned long V_88 , V_72 ;
unsigned V_73 ;
struct V_70 V_89 = { 0 } ;
int T_2 ;
if ( V_4 . V_42 == NULL )
return 0 ;
V_88 = F_49 ( V_86 ) ;
V_72 = F_50 () ;
V_73 = F_53 ( V_72 * V_4 . V_43 -> V_44 ,
V_88 ) ;
V_89 . V_73 = V_73 ;
T_2 = F_47 ( & V_89 ) ;
if ( T_2 )
return T_2 ;
T_2 = F_54 ( & V_89 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
void F_58 ( enum V_90 type )
{
int V_21 = 0 ;
if ( type == V_91 )
V_21 = 0 ;
else if ( type == V_92 )
V_21 = 1 ;
else
F_38 () ;
F_18 ( V_48 , V_21 , 6 , 6 ) ;
}
void F_59 ( bool V_93 )
{
F_18 ( V_48 , V_93 , 5 , 5 ) ;
}
void F_60 ( enum V_94 V_95 )
{
enum V_96 V_97 ;
V_97 = F_8 ( V_98 ) ;
F_61 ( ( V_95 == V_99 ) && ! ( V_97 & V_100 ) ) ;
F_61 ( ( V_95 == V_101 ) && ! ( V_97 & V_102 ) ) ;
if ( ( V_97 & V_100 ) && ( V_97 & V_102 ) )
F_18 ( V_48 , V_95 , 15 , 15 ) ;
}
enum V_94 F_62 ( void )
{
enum V_96 V_103 ;
V_103 = F_8 ( V_98 ) ;
if ( ( V_103 & V_102 ) == 0 )
return V_99 ;
if ( ( V_103 & V_100 ) == 0 )
return V_101 ;
return F_63 ( V_48 , 15 , 15 ) ;
}
static int F_64 ( enum V_63 V_64 )
{
if ( V_64 != V_7 )
return - V_75 ;
return 0 ;
}
static int F_65 ( enum V_63 V_64 )
{
int V_3 ;
switch ( V_64 ) {
case V_67 :
V_3 = 0 ;
break;
case V_98 :
V_3 = 1 ;
break;
default:
return - V_75 ;
}
F_18 ( V_48 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_66 ( enum V_63 V_64 )
{
int V_3 ;
switch ( V_64 ) {
case V_7 :
V_3 = 1 ;
break;
case V_67 :
V_3 = 2 ;
break;
case V_68 :
V_3 = 3 ;
break;
case V_98 :
V_3 = 0 ;
break;
default:
return - V_75 ;
}
F_18 ( V_48 , V_3 , 17 , 16 ) ;
return 0 ;
}
int F_67 ( enum V_63 V_64 )
{
return V_4 . V_43 -> V_104 ( V_64 ) ;
}
static int F_68 ( void )
{
struct V_105 * V_105 ;
V_105 = F_69 ( & V_4 . V_14 -> V_15 , L_16 ) ;
if ( F_70 ( V_105 ) ) {
F_22 ( L_17 ) ;
return F_71 ( V_105 ) ;
}
V_4 . V_41 = V_105 ;
if ( V_4 . V_43 -> V_106 ) {
V_105 = F_72 ( NULL , V_4 . V_43 -> V_106 ) ;
if ( F_70 ( V_105 ) ) {
F_22 ( L_18 , V_4 . V_43 -> V_106 ) ;
return F_71 ( V_105 ) ;
}
} else {
V_105 = NULL ;
}
V_4 . V_42 = V_105 ;
return 0 ;
}
static void F_73 ( void )
{
if ( V_4 . V_42 )
F_74 ( V_4 . V_42 ) ;
}
static int F_27 ( void )
{
int T_2 ;
F_6 ( L_19 ) ;
T_2 = F_75 ( & V_4 . V_14 -> V_15 ) ;
F_61 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
static void F_32 ( void )
{
int T_2 ;
F_6 ( L_20 ) ;
T_2 = F_76 ( & V_4 . V_14 -> V_15 ) ;
F_61 ( T_2 < 0 && T_2 != - V_107 && T_2 != - V_108 ) ;
}
void F_77 ( struct V_33 * V_34 )
{
F_26 ( V_34 ) ;
F_78 ( V_34 ) ;
#ifdef F_79
F_80 ( V_34 ) ;
#endif
}
static int T_5 F_81 ( struct V_49 * V_14 )
{
const struct V_109 * V_95 ;
struct V_109 * V_110 ;
V_110 = F_82 ( & V_14 -> V_15 , sizeof( * V_110 ) , V_111 ) ;
if ( ! V_110 ) {
F_83 ( & V_14 -> V_15 , L_21 ) ;
return - V_112 ;
}
switch ( F_84 () ) {
case V_113 :
V_95 = & V_114 ;
break;
case V_115 :
case V_116 :
case V_117 :
V_95 = & V_118 ;
break;
case V_119 :
V_95 = & V_120 ;
break;
case V_121 :
case V_122 :
case V_123 :
V_95 = & V_124 ;
break;
case V_125 :
V_95 = & V_126 ;
break;
default:
return - V_127 ;
}
memcpy ( V_110 , V_95 , sizeof( * V_110 ) ) ;
V_4 . V_43 = V_110 ;
return 0 ;
}
static int T_5 F_85 ( struct V_49 * V_14 )
{
struct V_128 * V_129 ;
T_1 V_130 ;
int T_2 ;
V_4 . V_14 = V_14 ;
T_2 = F_81 ( V_4 . V_14 ) ;
if ( T_2 )
return T_2 ;
V_129 = F_86 ( V_4 . V_14 , V_131 , 0 ) ;
if ( ! V_129 ) {
F_22 ( L_22 ) ;
return - V_75 ;
}
V_4 . V_5 = F_87 ( & V_14 -> V_15 , V_129 -> V_52 ,
F_88 ( V_129 ) ) ;
if ( ! V_4 . V_5 ) {
F_22 ( L_23 ) ;
return - V_112 ;
}
T_2 = F_68 () ;
if ( T_2 )
return T_2 ;
T_2 = F_57 () ;
if ( T_2 )
goto V_132;
F_89 ( & V_14 -> V_15 ) ;
T_2 = F_27 () ;
if ( T_2 )
goto V_133;
V_4 . V_87 = F_30 ( V_4 . V_41 ) ;
F_18 ( V_48 , 0 , 0 , 0 ) ;
F_35 ( V_40 ) ;
#ifdef F_90
F_18 ( V_48 , 1 , 4 , 4 ) ;
F_18 ( V_48 , 1 , 3 , 3 ) ;
F_18 ( V_48 , 0 , 2 , 2 ) ;
#endif
V_4 . V_62 [ 0 ] = V_40 ;
V_4 . V_62 [ 1 ] = V_40 ;
V_4 . V_57 = V_40 ;
V_4 . V_69 [ 0 ] = V_40 ;
V_4 . V_69 [ 1 ] = V_40 ;
V_130 = F_3 ( V_45 ) ;
F_91 ( V_134 L_24 ,
F_92 ( V_130 , 7 , 4 ) , F_92 ( V_130 , 3 , 0 ) ) ;
F_32 () ;
F_93 ( L_25 , F_33 ) ;
return 0 ;
V_133:
F_94 ( & V_14 -> V_15 ) ;
V_132:
F_73 () ;
return T_2 ;
}
static int T_6 F_95 ( struct V_49 * V_14 )
{
F_94 ( & V_14 -> V_15 ) ;
F_73 () ;
return 0 ;
}
static int F_96 ( struct V_135 * V_15 )
{
F_5 () ;
F_97 ( V_15 , 0 ) ;
return 0 ;
}
static int F_98 ( struct V_135 * V_15 )
{
int T_2 ;
T_2 = F_97 ( V_15 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_99 ( void )
{
return F_100 ( & V_136 , F_85 ) ;
}
void F_101 ( void )
{
F_102 ( & V_136 ) ;
}
