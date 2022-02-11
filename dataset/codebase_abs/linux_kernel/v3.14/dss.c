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
const char * V_37 , * V_38 ;
unsigned long V_39 ;
if ( F_28 () )
return;
F_29 ( V_36 , L_9 ) ;
V_37 = F_26 ( V_40 ) ;
V_38 = F_30 ( V_40 ) ;
V_39 = F_31 ( V_4 . V_41 ) ;
F_29 ( V_36 , L_10 ,
V_37 , V_38 ,
V_39 ) ;
F_32 () ;
}
static void F_33 ( struct V_35 * V_36 )
{
#define F_34 ( T_2 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_28 () )
return;
F_34 ( V_42 ) ;
F_34 ( V_43 ) ;
F_34 ( V_44 ) ;
F_34 ( V_45 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_34 ( V_24 ) ;
F_34 ( V_25 ) ;
F_34 ( V_28 ) ;
}
F_32 () ;
#undef F_34
}
static void F_35 ( enum V_32 V_33 )
{
struct V_12 * V_46 ;
int V_47 ;
T_3 V_48 , V_49 ;
switch ( V_33 ) {
case V_40 :
V_47 = 0 ;
break;
case V_50 :
V_47 = 1 ;
V_46 = F_36 ( 0 ) ;
F_37 ( V_46 ) ;
break;
case V_51 :
V_47 = 2 ;
V_46 = F_36 ( 1 ) ;
F_37 ( V_46 ) ;
break;
default:
F_38 () ;
return;
}
F_39 ( V_52 , & V_48 , & V_49 ) ;
F_19 ( V_45 , V_47 , V_48 , V_49 ) ;
V_4 . V_53 = V_33 ;
}
void F_40 ( int V_54 ,
enum V_32 V_33 )
{
struct V_12 * V_46 ;
int V_47 , V_55 ;
switch ( V_33 ) {
case V_40 :
V_47 = 0 ;
break;
case V_56 :
F_15 ( V_54 != 0 ) ;
V_47 = 1 ;
V_46 = F_36 ( 0 ) ;
F_41 ( V_46 ) ;
break;
case V_57 :
F_15 ( V_54 != 1 ) ;
V_47 = 1 ;
V_46 = F_36 ( 1 ) ;
F_41 ( V_46 ) ;
break;
default:
F_38 () ;
return;
}
V_55 = V_54 == 0 ? 1 : 10 ;
F_19 ( V_45 , V_47 , V_55 , V_55 ) ;
V_4 . V_58 [ V_54 ] = V_33 ;
}
void F_42 ( enum V_59 V_60 ,
enum V_32 V_33 )
{
struct V_12 * V_46 ;
int V_47 , V_61 , V_55 ;
if ( ! F_43 ( V_62 ) ) {
F_35 ( V_33 ) ;
return;
}
switch ( V_33 ) {
case V_40 :
V_47 = 0 ;
break;
case V_50 :
F_15 ( V_60 != V_7 ) ;
V_47 = 1 ;
V_46 = F_36 ( 0 ) ;
F_37 ( V_46 ) ;
break;
case V_51 :
F_15 ( V_60 != V_63 &&
V_60 != V_64 ) ;
V_47 = 1 ;
V_46 = F_36 ( 1 ) ;
F_37 ( V_46 ) ;
break;
default:
F_38 () ;
return;
}
V_55 = V_60 == V_7 ? 0 :
( V_60 == V_63 ? 12 : 19 ) ;
F_19 ( V_45 , V_47 , V_55 , V_55 ) ;
V_61 = V_60 == V_7 ? 0 :
( V_60 == V_63 ? 1 : 2 ) ;
V_4 . V_65 [ V_61 ] = V_33 ;
}
enum V_32 F_44 ( void )
{
return V_4 . V_53 ;
}
enum V_32 F_45 ( int V_54 )
{
return V_4 . V_58 [ V_54 ] ;
}
enum V_32 F_46 ( enum V_59 V_60 )
{
if ( F_43 ( V_62 ) ) {
int V_61 = V_60 == V_7 ? 0 :
( V_60 == V_63 ? 1 : 2 ) ;
return V_4 . V_65 [ V_61 ] ;
} else {
return V_4 . V_53 ;
}
}
bool F_47 ( unsigned long V_66 , unsigned long V_67 ,
T_4 V_68 , void * V_69 )
{
int V_70 , V_71 , V_72 ;
unsigned long V_73 ;
unsigned long V_74 ;
unsigned long V_75 ;
unsigned long V_76 ;
unsigned V_77 ;
V_74 = F_48 ( V_78 ) ;
if ( V_4 . V_79 == NULL ) {
unsigned V_80 ;
V_80 = V_74 / V_66 ;
V_73 = V_66 * V_80 ;
V_73 = F_49 ( V_4 . V_41 , V_73 ) ;
return V_68 ( V_73 , V_69 ) ;
}
V_75 = V_4 . V_81 -> V_82 ;
V_77 = V_4 . V_81 -> V_83 ;
V_76 = F_31 ( V_4 . V_79 ) ;
V_67 = V_67 ? V_67 : 1 ;
V_71 = F_50 ( V_76 * V_77 / V_67 , V_75 ) ;
V_72 = F_51 ( F_52 ( V_76 * V_77 , V_74 ) , 1ul ) ;
for ( V_70 = V_71 ; V_70 >= V_72 ; -- V_70 ) {
V_73 = V_76 / V_70 * V_77 ;
if ( V_68 ( V_73 , V_69 ) )
return true ;
}
return false ;
}
int F_53 ( unsigned long V_84 )
{
int T_2 ;
F_6 ( L_11 , V_84 ) ;
T_2 = F_54 ( V_4 . V_41 , V_84 ) ;
if ( T_2 )
return T_2 ;
V_4 . V_85 = F_31 ( V_4 . V_41 ) ;
F_13 ( V_4 . V_85 != V_84 ,
L_12 , V_4 . V_85 ,
V_84 ) ;
return 0 ;
}
unsigned long F_55 ( void )
{
return V_4 . V_85 ;
}
static int F_56 ( void )
{
unsigned long V_86 , V_76 ;
unsigned long V_73 ;
unsigned V_87 ;
int T_2 ;
V_86 = F_48 ( V_78 ) ;
if ( V_4 . V_79 == NULL ) {
V_73 = F_49 ( V_4 . V_41 , V_86 ) ;
} else {
V_76 = F_31 ( V_4 . V_79 ) ;
V_87 = F_52 ( V_76 * V_4 . V_81 -> V_83 ,
V_86 ) ;
V_73 = V_76 / V_87 * V_4 . V_81 -> V_83 ;
}
T_2 = F_53 ( V_73 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
void F_57 ( enum V_88 type )
{
int V_23 = 0 ;
if ( type == V_89 )
V_23 = 0 ;
else if ( type == V_90 )
V_23 = 1 ;
else
F_38 () ;
F_19 ( V_45 , V_23 , 6 , 6 ) ;
}
void F_58 ( bool V_91 )
{
F_19 ( V_45 , V_91 , 5 , 5 ) ;
}
void F_59 ( enum V_92 V_93 )
{
enum V_94 V_95 ;
V_95 = F_8 ( V_96 ) ;
F_60 ( ( V_93 == V_97 ) && ! ( V_95 & V_98 ) ) ;
F_60 ( ( V_93 == V_99 ) && ! ( V_95 & V_100 ) ) ;
if ( ( V_95 & V_98 ) && ( V_95 & V_100 ) )
F_19 ( V_45 , V_93 , 15 , 15 ) ;
}
enum V_92 F_61 ( void )
{
enum V_94 V_101 ;
V_101 = F_8 ( V_96 ) ;
if ( ( V_101 & V_100 ) == 0 )
return V_97 ;
if ( ( V_101 & V_98 ) == 0 )
return V_99 ;
return F_62 ( V_45 , 15 , 15 ) ;
}
static int F_63 ( enum V_59 V_60 )
{
if ( V_60 != V_7 )
return - V_102 ;
return 0 ;
}
static int F_64 ( enum V_59 V_60 )
{
int V_3 ;
switch ( V_60 ) {
case V_63 :
V_3 = 0 ;
break;
case V_96 :
V_3 = 1 ;
break;
default:
return - V_102 ;
}
F_19 ( V_45 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_65 ( enum V_59 V_60 )
{
int V_3 ;
switch ( V_60 ) {
case V_7 :
V_3 = 1 ;
break;
case V_63 :
V_3 = 2 ;
break;
case V_64 :
V_3 = 3 ;
break;
case V_96 :
V_3 = 0 ;
break;
default:
return - V_102 ;
}
F_19 ( V_45 , V_3 , 17 , 16 ) ;
return 0 ;
}
int F_66 ( enum V_59 V_60 )
{
return V_4 . V_81 -> V_103 ( V_60 ) ;
}
static int F_67 ( void )
{
struct V_104 * V_104 ;
V_104 = F_68 ( & V_4 . V_21 -> V_16 , L_13 ) ;
if ( F_69 ( V_104 ) ) {
F_23 ( L_14 ) ;
return F_70 ( V_104 ) ;
}
V_4 . V_41 = V_104 ;
if ( V_4 . V_81 -> V_105 ) {
V_104 = F_71 ( NULL , V_4 . V_81 -> V_105 ) ;
if ( F_69 ( V_104 ) ) {
F_23 ( L_15 , V_4 . V_81 -> V_105 ) ;
return F_70 ( V_104 ) ;
}
} else {
V_104 = NULL ;
}
V_4 . V_79 = V_104 ;
return 0 ;
}
static void F_72 ( void )
{
if ( V_4 . V_79 )
F_73 ( V_4 . V_79 ) ;
}
static int F_28 ( void )
{
int T_2 ;
F_6 ( L_16 ) ;
T_2 = F_74 ( & V_4 . V_21 -> V_16 ) ;
F_60 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
static void F_32 ( void )
{
int T_2 ;
F_6 ( L_17 ) ;
T_2 = F_75 ( & V_4 . V_21 -> V_16 ) ;
F_60 ( T_2 < 0 && T_2 != - V_106 && T_2 != - V_107 ) ;
}
void F_76 ( struct V_35 * V_36 )
{
F_27 ( V_36 ) ;
F_77 ( V_36 ) ;
#ifdef F_78
F_79 ( V_36 ) ;
#endif
}
static int T_5 F_80 ( struct V_12 * V_21 )
{
const struct V_108 * V_93 ;
struct V_108 * V_109 ;
V_109 = F_81 ( & V_21 -> V_16 , sizeof( * V_109 ) , V_110 ) ;
if ( ! V_109 ) {
F_82 ( & V_21 -> V_16 , L_18 ) ;
return - V_111 ;
}
switch ( F_83 () ) {
case V_112 :
V_93 = & V_113 ;
break;
case V_114 :
case V_115 :
case V_116 :
V_93 = & V_117 ;
break;
case V_118 :
V_93 = & V_119 ;
break;
case V_120 :
case V_121 :
case V_122 :
V_93 = & V_123 ;
break;
case V_124 :
V_93 = & V_125 ;
break;
default:
return - V_126 ;
}
memcpy ( V_109 , V_93 , sizeof( * V_109 ) ) ;
V_4 . V_81 = V_109 ;
return 0 ;
}
static int T_5 F_84 ( struct V_12 * V_21 )
{
struct V_127 * V_128 ;
T_1 V_129 ;
int T_2 ;
V_4 . V_21 = V_21 ;
T_2 = F_80 ( V_4 . V_21 ) ;
if ( T_2 )
return T_2 ;
V_128 = F_85 ( V_4 . V_21 , V_130 , 0 ) ;
if ( ! V_128 ) {
F_23 ( L_19 ) ;
return - V_102 ;
}
V_4 . V_5 = F_86 ( & V_21 -> V_16 , V_128 -> V_48 ,
F_87 ( V_128 ) ) ;
if ( ! V_4 . V_5 ) {
F_23 ( L_20 ) ;
return - V_111 ;
}
T_2 = F_67 () ;
if ( T_2 )
return T_2 ;
T_2 = F_56 () ;
if ( T_2 )
goto V_131;
F_88 ( & V_21 -> V_16 ) ;
T_2 = F_28 () ;
if ( T_2 )
goto V_132;
V_4 . V_85 = F_31 ( V_4 . V_41 ) ;
F_19 ( V_45 , 0 , 0 , 0 ) ;
F_35 ( V_40 ) ;
#ifdef F_89
F_19 ( V_45 , 1 , 4 , 4 ) ;
F_19 ( V_45 , 1 , 3 , 3 ) ;
F_19 ( V_45 , 0 , 2 , 2 ) ;
#endif
V_4 . V_58 [ 0 ] = V_40 ;
V_4 . V_58 [ 1 ] = V_40 ;
V_4 . V_53 = V_40 ;
V_4 . V_65 [ 0 ] = V_40 ;
V_4 . V_65 [ 1 ] = V_40 ;
V_129 = F_3 ( V_42 ) ;
F_90 ( V_133 L_21 ,
F_91 ( V_129 , 7 , 4 ) , F_91 ( V_129 , 3 , 0 ) ) ;
F_32 () ;
F_92 ( L_22 , F_33 ) ;
return 0 ;
V_132:
F_93 ( & V_21 -> V_16 ) ;
V_131:
F_72 () ;
return T_2 ;
}
static int T_6 F_94 ( struct V_12 * V_21 )
{
F_93 ( & V_21 -> V_16 ) ;
F_72 () ;
return 0 ;
}
static int F_95 ( struct V_134 * V_16 )
{
F_5 () ;
F_96 ( V_16 , 0 ) ;
return 0 ;
}
static int F_97 ( struct V_134 * V_16 )
{
int T_2 ;
T_2 = F_96 ( V_16 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_98 ( void )
{
return F_99 ( & V_135 , F_84 ) ;
}
void F_100 ( void )
{
F_101 ( & V_135 ) ;
}
