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
int F_48 ( struct V_70 * V_71 )
{
if ( V_4 . V_42 ) {
unsigned long V_72 ;
int T_2 ;
V_72 = F_30 ( F_31 ( V_4 . V_42 ) ) ;
F_6 ( L_13 , V_72 ) ;
T_2 = F_49 ( V_4 . V_42 , V_72 / V_71 -> V_73 ) ;
if ( T_2 )
return T_2 ;
} else {
if ( V_71 -> V_73 != 0 )
return - V_75 ;
}
V_4 . V_77 = F_30 ( V_4 . V_41 ) ;
F_12 ( V_4 . V_77 != V_71 -> V_76 , L_14 ) ;
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
unsigned long F_51 ( void )
{
return V_4 . V_77 ;
}
static int F_52 ( void )
{
unsigned long V_78 , V_72 ;
unsigned V_73 ;
struct V_70 V_79 = { 0 } ;
int T_2 ;
if ( V_4 . V_42 == NULL )
return 0 ;
V_78 = F_53 ( V_80 ) ;
V_72 = F_50 () ;
V_73 = F_54 ( V_72 * V_4 . V_43 -> V_44 ,
V_78 ) ;
V_79 . V_73 = V_73 ;
T_2 = F_47 ( & V_79 ) ;
if ( T_2 )
return T_2 ;
T_2 = F_48 ( & V_79 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
int F_55 ( unsigned long V_81 , struct V_70 * V_79 ,
struct V_82 * V_83 )
{
unsigned long V_72 ;
struct V_70 V_84 ;
struct V_82 V_85 ;
unsigned long V_76 , V_78 ;
T_4 V_73 ;
int V_86 = 0 ;
int V_87 ;
V_72 = F_50 () ;
V_78 = F_53 ( V_80 ) ;
V_76 = F_30 ( V_4 . V_41 ) ;
if ( V_81 == V_4 . V_88 && V_72 == V_4 . V_89 &&
V_4 . V_90 . V_76 == V_76 ) {
F_6 ( L_16 ) ;
* V_79 = V_4 . V_90 ;
* V_83 = V_4 . V_91 ;
return 0 ;
}
V_87 = V_92 ;
if ( V_87 &&
V_81 * V_87 > V_78 ) {
F_22 ( L_17
L_18
L_19 ) ;
V_87 = 0 ;
}
V_93:
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
if ( V_4 . V_42 == NULL ) {
struct V_82 V_94 ;
V_76 = F_30 ( V_4 . V_41 ) ;
V_73 = 1 ;
F_56 ( V_81 , V_76 , & V_94 ) ;
V_86 = 1 ;
V_84 . V_76 = V_76 ;
V_84 . V_73 = V_73 ;
V_85 = V_94 ;
goto V_95;
} else {
for ( V_73 = V_4 . V_43 -> V_74 ; V_73 > 0 ; -- V_73 ) {
struct V_82 V_94 ;
V_76 = V_72 / V_73 * V_4 . V_43 -> V_44 ;
if ( V_76 > V_78 )
continue;
if ( V_87 &&
V_76 < V_81 * V_87 )
continue;
V_86 = 1 ;
F_56 ( V_81 , V_76 , & V_94 ) ;
if ( abs ( V_94 . V_96 - V_81 ) <
abs ( V_85 . V_96 - V_81 ) ) {
V_84 . V_76 = V_76 ;
V_84 . V_73 = V_73 ;
V_85 = V_94 ;
if ( V_94 . V_96 == V_81 )
goto V_95;
}
}
}
V_95:
if ( ! V_86 ) {
if ( V_87 ) {
F_22 ( L_20
L_21
L_22 ) ;
V_87 = 0 ;
goto V_93;
}
F_22 ( L_20 ) ;
return - V_75 ;
}
if ( V_79 )
* V_79 = V_84 ;
if ( V_83 )
* V_83 = V_85 ;
V_4 . V_88 = V_81 ;
V_4 . V_89 = V_72 ;
V_4 . V_90 = V_84 ;
V_4 . V_91 = V_85 ;
return 0 ;
}
void F_57 ( enum V_97 type )
{
int V_21 = 0 ;
if ( type == V_98 )
V_21 = 0 ;
else if ( type == V_99 )
V_21 = 1 ;
else
F_38 () ;
F_18 ( V_48 , V_21 , 6 , 6 ) ;
}
void F_58 ( bool V_100 )
{
F_18 ( V_48 , V_100 , 5 , 5 ) ;
}
void F_59 ( enum V_101 V_102 )
{
enum V_103 V_104 ;
V_104 = F_8 ( V_105 ) ;
F_60 ( ( V_102 == V_106 ) && ! ( V_104 & V_107 ) ) ;
F_60 ( ( V_102 == V_108 ) && ! ( V_104 & V_109 ) ) ;
if ( ( V_104 & V_107 ) && ( V_104 & V_109 ) )
F_18 ( V_48 , V_102 , 15 , 15 ) ;
}
enum V_101 F_61 ( void )
{
enum V_103 V_110 ;
V_110 = F_8 ( V_105 ) ;
if ( ( V_110 & V_109 ) == 0 )
return V_106 ;
if ( ( V_110 & V_107 ) == 0 )
return V_108 ;
return F_62 ( V_48 , 15 , 15 ) ;
}
static int F_63 ( enum V_63 V_64 )
{
if ( V_64 != V_7 )
return - V_75 ;
return 0 ;
}
static int F_64 ( enum V_63 V_64 )
{
int V_3 ;
switch ( V_64 ) {
case V_67 :
V_3 = 0 ;
break;
case V_105 :
V_3 = 1 ;
break;
default:
return - V_75 ;
}
F_18 ( V_48 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_65 ( enum V_63 V_64 )
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
case V_105 :
V_3 = 0 ;
break;
default:
return - V_75 ;
}
F_18 ( V_48 , V_3 , 17 , 16 ) ;
return 0 ;
}
int F_66 ( enum V_63 V_64 )
{
return V_4 . V_43 -> V_111 ( V_64 ) ;
}
static int F_67 ( void )
{
struct V_112 * V_112 ;
int T_2 ;
V_112 = F_68 ( & V_4 . V_14 -> V_15 , L_23 ) ;
if ( F_69 ( V_112 ) ) {
F_22 ( L_24 ) ;
T_2 = F_70 ( V_112 ) ;
goto V_113;
}
V_4 . V_41 = V_112 ;
if ( V_4 . V_43 -> V_114 ) {
V_112 = F_68 ( NULL , V_4 . V_43 -> V_114 ) ;
if ( F_69 ( V_112 ) ) {
F_22 ( L_25 , V_4 . V_43 -> V_114 ) ;
T_2 = F_70 ( V_112 ) ;
goto V_113;
}
} else {
V_112 = NULL ;
}
V_4 . V_42 = V_112 ;
return 0 ;
V_113:
if ( V_4 . V_41 )
F_71 ( V_4 . V_41 ) ;
if ( V_4 . V_42 )
F_71 ( V_4 . V_42 ) ;
return T_2 ;
}
static void F_72 ( void )
{
if ( V_4 . V_42 )
F_71 ( V_4 . V_42 ) ;
F_71 ( V_4 . V_41 ) ;
}
static int F_27 ( void )
{
int T_2 ;
F_6 ( L_26 ) ;
T_2 = F_73 ( & V_4 . V_14 -> V_15 ) ;
F_60 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
static void F_32 ( void )
{
int T_2 ;
F_6 ( L_27 ) ;
T_2 = F_74 ( & V_4 . V_14 -> V_15 ) ;
F_60 ( T_2 < 0 && T_2 != - V_115 && T_2 != - V_116 ) ;
}
void F_75 ( struct V_33 * V_34 )
{
F_26 ( V_34 ) ;
F_76 ( V_34 ) ;
#ifdef F_77
F_78 ( V_34 ) ;
#endif
}
static int T_5 F_79 ( struct V_49 * V_14 )
{
const struct V_117 * V_102 ;
struct V_117 * V_118 ;
V_118 = F_80 ( & V_14 -> V_15 , sizeof( * V_118 ) , V_119 ) ;
if ( ! V_118 ) {
F_81 ( & V_14 -> V_15 , L_28 ) ;
return - V_120 ;
}
switch ( F_82 () ) {
case V_121 :
V_102 = & V_122 ;
break;
case V_123 :
case V_124 :
case V_125 :
V_102 = & V_126 ;
break;
case V_127 :
V_102 = & V_128 ;
break;
case V_129 :
case V_130 :
case V_131 :
V_102 = & V_132 ;
break;
case V_133 :
V_102 = & V_134 ;
break;
default:
return - V_135 ;
}
memcpy ( V_118 , V_102 , sizeof( * V_118 ) ) ;
V_4 . V_43 = V_118 ;
return 0 ;
}
static int T_5 F_83 ( struct V_49 * V_14 )
{
struct V_136 * V_137 ;
T_1 V_138 ;
int T_2 ;
V_4 . V_14 = V_14 ;
T_2 = F_79 ( V_4 . V_14 ) ;
if ( T_2 )
return T_2 ;
V_137 = F_84 ( V_4 . V_14 , V_139 , 0 ) ;
if ( ! V_137 ) {
F_22 ( L_29 ) ;
return - V_75 ;
}
V_4 . V_5 = F_85 ( & V_14 -> V_15 , V_137 -> V_52 ,
F_86 ( V_137 ) ) ;
if ( ! V_4 . V_5 ) {
F_22 ( L_30 ) ;
return - V_120 ;
}
T_2 = F_67 () ;
if ( T_2 )
return T_2 ;
T_2 = F_52 () ;
if ( T_2 )
goto V_140;
F_87 ( & V_14 -> V_15 ) ;
T_2 = F_27 () ;
if ( T_2 )
goto V_141;
V_4 . V_77 = F_30 ( V_4 . V_41 ) ;
F_18 ( V_48 , 0 , 0 , 0 ) ;
F_35 ( V_40 ) ;
#ifdef F_88
F_18 ( V_48 , 1 , 4 , 4 ) ;
F_18 ( V_48 , 1 , 3 , 3 ) ;
F_18 ( V_48 , 0 , 2 , 2 ) ;
#endif
V_4 . V_62 [ 0 ] = V_40 ;
V_4 . V_62 [ 1 ] = V_40 ;
V_4 . V_57 = V_40 ;
V_4 . V_69 [ 0 ] = V_40 ;
V_4 . V_69 [ 1 ] = V_40 ;
V_138 = F_3 ( V_45 ) ;
F_89 ( V_142 L_31 ,
F_90 ( V_138 , 7 , 4 ) , F_90 ( V_138 , 3 , 0 ) ) ;
F_32 () ;
F_91 ( L_32 , F_33 ) ;
return 0 ;
V_141:
F_92 ( & V_14 -> V_15 ) ;
V_140:
F_72 () ;
return T_2 ;
}
static int T_6 F_93 ( struct V_49 * V_14 )
{
F_92 ( & V_14 -> V_15 ) ;
F_72 () ;
return 0 ;
}
static int F_94 ( struct V_143 * V_15 )
{
F_5 () ;
F_95 ( V_15 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_143 * V_15 )
{
int T_2 ;
T_2 = F_95 ( V_15 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_97 ( void )
{
return F_98 ( & V_144 , F_83 ) ;
}
void F_99 ( void )
{
F_100 ( & V_144 ) ;
}
