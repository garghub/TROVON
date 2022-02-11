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
struct V_36 * V_37 ;
int V_38 ;
T_3 V_39 , V_40 ;
switch ( V_23 ) {
case V_30 :
V_38 = 0 ;
break;
case V_41 :
V_38 = 1 ;
V_37 = F_33 ( 0 ) ;
F_34 ( V_37 ) ;
break;
case V_42 :
V_38 = 2 ;
V_37 = F_33 ( 1 ) ;
F_34 ( V_37 ) ;
break;
default:
F_35 () ;
return;
}
F_36 ( V_43 , & V_39 , & V_40 ) ;
F_16 ( V_35 , V_38 , V_39 , V_40 ) ;
V_4 . V_44 = V_23 ;
}
void F_37 ( int V_45 ,
enum V_22 V_23 )
{
struct V_36 * V_37 ;
int V_38 , V_46 ;
switch ( V_23 ) {
case V_30 :
V_38 = 0 ;
break;
case V_47 :
F_12 ( V_45 != 0 ) ;
V_38 = 1 ;
V_37 = F_33 ( 0 ) ;
F_38 ( V_37 ) ;
break;
case V_48 :
F_12 ( V_45 != 1 ) ;
V_38 = 1 ;
V_37 = F_33 ( 1 ) ;
F_38 ( V_37 ) ;
break;
default:
F_35 () ;
return;
}
V_46 = V_45 == 0 ? 1 : 10 ;
F_16 ( V_35 , V_38 , V_46 , V_46 ) ;
V_4 . V_49 [ V_45 ] = V_23 ;
}
void F_39 ( enum V_50 V_51 ,
enum V_22 V_23 )
{
struct V_36 * V_37 ;
int V_38 , V_52 , V_46 ;
if ( ! F_40 ( V_53 ) ) {
F_32 ( V_23 ) ;
return;
}
switch ( V_23 ) {
case V_30 :
V_38 = 0 ;
break;
case V_41 :
F_12 ( V_51 != V_7 ) ;
V_38 = 1 ;
V_37 = F_33 ( 0 ) ;
F_34 ( V_37 ) ;
break;
case V_42 :
F_12 ( V_51 != V_54 &&
V_51 != V_55 ) ;
V_38 = 1 ;
V_37 = F_33 ( 1 ) ;
F_34 ( V_37 ) ;
break;
default:
F_35 () ;
return;
}
V_46 = V_51 == V_7 ? 0 :
( V_51 == V_54 ? 12 : 19 ) ;
F_16 ( V_35 , V_38 , V_46 , V_46 ) ;
V_52 = V_51 == V_7 ? 0 :
( V_51 == V_54 ? 1 : 2 ) ;
V_4 . V_56 [ V_52 ] = V_23 ;
}
enum V_22 F_41 ( void )
{
return V_4 . V_44 ;
}
enum V_22 F_42 ( int V_45 )
{
return V_4 . V_49 [ V_45 ] ;
}
enum V_22 F_43 ( enum V_50 V_51 )
{
if ( F_40 ( V_53 ) ) {
int V_52 = V_51 == V_7 ? 0 :
( V_51 == V_54 ? 1 : 2 ) ;
return V_4 . V_56 [ V_52 ] ;
} else {
return V_4 . V_44 ;
}
}
bool F_44 ( unsigned long V_57 , unsigned long V_58 ,
T_4 V_59 , void * V_60 )
{
int V_61 , V_62 , V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
unsigned long V_66 ;
unsigned long V_67 ;
unsigned V_68 ;
V_65 = F_45 ( V_69 ) ;
if ( V_4 . V_70 == NULL ) {
unsigned V_71 ;
V_71 = V_65 / V_57 ;
V_64 = V_57 * V_71 ;
V_64 = F_46 ( V_4 . V_31 , V_64 ) ;
return V_59 ( V_64 , V_60 ) ;
}
V_66 = V_4 . V_72 -> V_73 ;
V_68 = V_4 . V_72 -> V_74 ;
V_67 = F_28 ( V_4 . V_70 ) ;
V_58 = V_58 ? V_58 : 1 ;
V_62 = F_47 ( V_67 * V_68 / V_58 , V_66 ) ;
V_63 = F_48 ( F_49 ( V_67 * V_68 , V_65 ) , 1ul ) ;
for ( V_61 = V_62 ; V_61 >= V_63 ; -- V_61 ) {
V_64 = F_49 ( V_67 , V_61 ) * V_68 ;
if ( V_59 ( V_64 , V_60 ) )
return true ;
}
return false ;
}
int F_50 ( unsigned long V_75 )
{
int T_2 ;
F_6 ( L_10 , V_75 ) ;
T_2 = F_51 ( V_4 . V_31 , V_75 ) ;
if ( T_2 )
return T_2 ;
V_4 . V_76 = F_28 ( V_4 . V_31 ) ;
F_52 ( V_4 . V_76 != V_75 ,
L_11 , V_4 . V_76 ,
V_75 ) ;
return 0 ;
}
unsigned long F_53 ( void )
{
return V_4 . V_76 ;
}
static int F_54 ( void )
{
unsigned long V_77 , V_67 ;
unsigned long V_64 ;
unsigned V_78 ;
int T_2 ;
V_77 = F_45 ( V_69 ) ;
if ( V_4 . V_70 == NULL ) {
V_64 = F_46 ( V_4 . V_31 , V_77 ) ;
} else {
V_67 = F_28 ( V_4 . V_70 ) ;
V_78 = F_49 ( V_67 * V_4 . V_72 -> V_74 ,
V_77 ) ;
V_64 = F_49 ( V_67 , V_78 ) * V_4 . V_72 -> V_74 ;
}
T_2 = F_50 ( V_64 ) ;
if ( T_2 )
return T_2 ;
return 0 ;
}
void F_55 ( enum V_79 type )
{
int V_13 = 0 ;
if ( type == V_80 )
V_13 = 0 ;
else if ( type == V_81 )
V_13 = 1 ;
else
F_35 () ;
F_16 ( V_35 , V_13 , 6 , 6 ) ;
}
void F_56 ( bool V_82 )
{
F_16 ( V_35 , V_82 , 5 , 5 ) ;
}
void F_57 ( enum V_83 V_84 )
{
enum V_85 V_86 ;
V_86 = F_8 ( V_87 ) ;
F_58 ( ( V_84 == V_88 ) && ! ( V_86 & V_89 ) ) ;
F_58 ( ( V_84 == V_90 ) && ! ( V_86 & V_91 ) ) ;
if ( ( V_86 & V_89 ) && ( V_86 & V_91 ) )
F_16 ( V_35 , V_84 , 15 , 15 ) ;
}
enum V_83 F_59 ( void )
{
enum V_85 V_92 ;
V_92 = F_8 ( V_87 ) ;
if ( ( V_92 & V_91 ) == 0 )
return V_88 ;
if ( ( V_92 & V_89 ) == 0 )
return V_90 ;
return F_60 ( V_35 , 15 , 15 ) ;
}
static int F_61 ( enum V_50 V_51 )
{
if ( V_51 != V_7 )
return - V_93 ;
return 0 ;
}
static int F_62 ( enum V_50 V_51 )
{
int V_3 ;
switch ( V_51 ) {
case V_54 :
V_3 = 0 ;
break;
case V_87 :
V_3 = 1 ;
break;
default:
return - V_93 ;
}
F_16 ( V_35 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_63 ( enum V_50 V_51 )
{
int V_3 ;
switch ( V_51 ) {
case V_7 :
V_3 = 1 ;
break;
case V_54 :
V_3 = 2 ;
break;
case V_55 :
V_3 = 3 ;
break;
case V_87 :
V_3 = 0 ;
break;
default:
return - V_93 ;
}
F_16 ( V_35 , V_3 , 17 , 16 ) ;
return 0 ;
}
int F_64 ( enum V_50 V_51 )
{
return V_4 . V_72 -> V_94 ( V_51 ) ;
}
static int F_65 ( void )
{
struct V_95 * V_95 ;
V_95 = F_66 ( & V_4 . V_96 -> V_97 , L_12 ) ;
if ( F_67 ( V_95 ) ) {
F_20 ( L_13 ) ;
return F_68 ( V_95 ) ;
}
V_4 . V_31 = V_95 ;
if ( V_4 . V_72 -> V_98 ) {
V_95 = F_69 ( NULL , V_4 . V_72 -> V_98 ) ;
if ( F_67 ( V_95 ) ) {
F_20 ( L_14 , V_4 . V_72 -> V_98 ) ;
return F_68 ( V_95 ) ;
}
} else {
V_95 = NULL ;
}
V_4 . V_70 = V_95 ;
return 0 ;
}
static void F_70 ( void )
{
if ( V_4 . V_70 )
F_71 ( V_4 . V_70 ) ;
}
static int F_25 ( void )
{
int T_2 ;
F_6 ( L_15 ) ;
T_2 = F_72 ( & V_4 . V_96 -> V_97 ) ;
F_58 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
static void F_29 ( void )
{
int T_2 ;
F_6 ( L_16 ) ;
T_2 = F_73 ( & V_4 . V_96 -> V_97 ) ;
F_58 ( T_2 < 0 && T_2 != - V_99 && T_2 != - V_100 ) ;
}
void F_74 ( struct V_25 * V_26 )
{
F_24 ( V_26 ) ;
F_75 ( V_26 ) ;
#ifdef F_76
F_77 ( V_26 ) ;
#endif
}
static int T_5 F_78 ( struct V_36 * V_96 )
{
const struct V_101 * V_84 ;
struct V_101 * V_102 ;
V_102 = F_79 ( & V_96 -> V_97 , sizeof( * V_102 ) , V_103 ) ;
if ( ! V_102 ) {
F_80 ( & V_96 -> V_97 , L_17 ) ;
return - V_104 ;
}
switch ( F_81 () ) {
case V_105 :
V_84 = & V_106 ;
break;
case V_107 :
case V_108 :
case V_109 :
V_84 = & V_110 ;
break;
case V_111 :
V_84 = & V_112 ;
break;
case V_113 :
case V_114 :
case V_115 :
V_84 = & V_116 ;
break;
case V_117 :
V_84 = & V_118 ;
break;
default:
return - V_119 ;
}
memcpy ( V_102 , V_84 , sizeof( * V_102 ) ) ;
V_4 . V_72 = V_102 ;
return 0 ;
}
static int T_5 F_82 ( struct V_36 * V_96 )
{
struct V_120 * V_121 = V_96 -> V_97 . V_122 ;
struct V_120 * V_123 ;
int T_2 ;
if ( V_121 == NULL )
return 0 ;
V_123 = F_83 ( V_121 , NULL ) ;
if ( ! V_123 ) {
#ifdef F_84
F_85 ( V_96 , V_121 ) ;
#endif
return 0 ;
}
do {
T_1 V_124 ;
T_2 = F_86 ( V_123 , L_18 , & V_124 ) ;
if ( T_2 )
V_124 = 0 ;
#ifdef F_84
if ( V_124 == 0 )
F_85 ( V_96 , V_123 ) ;
#endif
#ifdef F_87
if ( V_124 == 1 )
F_88 ( V_96 , V_123 ) ;
#endif
} while ( ( V_123 = F_83 ( V_121 , V_123 ) ) != NULL );
return 0 ;
}
static void F_89 ( void )
{
#ifdef F_84
F_90 () ;
#endif
#ifdef F_87
F_91 () ;
#endif
}
static int T_5 F_92 ( struct V_36 * V_96 )
{
struct V_125 * V_126 ;
T_1 V_127 ;
int T_2 ;
V_4 . V_96 = V_96 ;
T_2 = F_78 ( V_4 . V_96 ) ;
if ( T_2 )
return T_2 ;
V_126 = F_93 ( V_4 . V_96 , V_128 , 0 ) ;
if ( ! V_126 ) {
F_20 ( L_19 ) ;
return - V_93 ;
}
V_4 . V_5 = F_94 ( & V_96 -> V_97 , V_126 -> V_39 ,
F_95 ( V_126 ) ) ;
if ( ! V_4 . V_5 ) {
F_20 ( L_20 ) ;
return - V_104 ;
}
T_2 = F_65 () ;
if ( T_2 )
return T_2 ;
T_2 = F_54 () ;
if ( T_2 )
goto V_129;
F_96 ( & V_96 -> V_97 ) ;
T_2 = F_25 () ;
if ( T_2 )
goto V_130;
V_4 . V_76 = F_28 ( V_4 . V_31 ) ;
F_16 ( V_35 , 0 , 0 , 0 ) ;
F_32 ( V_30 ) ;
#ifdef F_97
F_16 ( V_35 , 1 , 4 , 4 ) ;
F_16 ( V_35 , 1 , 3 , 3 ) ;
F_16 ( V_35 , 0 , 2 , 2 ) ;
#endif
V_4 . V_49 [ 0 ] = V_30 ;
V_4 . V_49 [ 1 ] = V_30 ;
V_4 . V_44 = V_30 ;
V_4 . V_56 [ 0 ] = V_30 ;
V_4 . V_56 [ 1 ] = V_30 ;
F_82 ( V_96 ) ;
V_127 = F_3 ( V_32 ) ;
F_98 ( V_131 L_21 ,
F_99 ( V_127 , 7 , 4 ) , F_99 ( V_127 , 3 , 0 ) ) ;
F_29 () ;
F_100 ( L_22 , F_30 ) ;
return 0 ;
V_130:
F_101 ( & V_96 -> V_97 ) ;
V_129:
F_70 () ;
return T_2 ;
}
static int T_6 F_102 ( struct V_36 * V_96 )
{
F_89 () ;
F_101 ( & V_96 -> V_97 ) ;
F_70 () ;
return 0 ;
}
static int F_103 ( struct V_132 * V_97 )
{
F_5 () ;
F_104 ( V_97 , 0 ) ;
return 0 ;
}
static int F_105 ( struct V_132 * V_97 )
{
int T_2 ;
T_2 = F_104 ( V_97 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_106 ( void )
{
return F_107 ( & V_133 , F_92 ) ;
}
void F_108 ( void )
{
F_109 ( & V_133 ) ;
}
