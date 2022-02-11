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
unsigned long V_27 ;
unsigned long V_28 ;
const char * V_29 , * V_30 ;
unsigned long V_31 ;
if ( F_25 () )
return;
F_26 ( V_26 , L_8 ) ;
V_29 = F_23 ( V_32 ) ;
V_30 = F_27 ( V_32 ) ;
V_31 = F_28 ( V_4 . V_33 ) ;
if ( V_4 . V_34 ) {
V_27 = F_28 ( F_29 ( V_4 . V_34 ) ) ;
V_28 = F_28 ( V_4 . V_34 ) ;
F_26 ( V_26 , L_9 , V_27 ) ;
F_26 ( V_26 , L_10 ,
V_29 , V_30 , V_27 ,
V_27 / V_28 ,
V_4 . V_35 -> V_36 , V_31 ) ;
} else {
F_26 ( V_26 , L_11 ,
V_29 , V_30 ,
V_31 ) ;
}
F_30 () ;
}
static void F_31 ( struct V_25 * V_26 )
{
#define F_32 ( T_2 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
if ( F_25 () )
return;
F_32 ( V_37 ) ;
F_32 ( V_38 ) ;
F_32 ( V_39 ) ;
F_32 ( V_40 ) ;
if ( F_8 ( V_7 ) &
V_8 ) {
F_32 ( V_14 ) ;
F_32 ( V_15 ) ;
F_32 ( V_18 ) ;
}
F_30 () ;
#undef F_32
}
void F_33 ( enum V_22 V_23 )
{
struct V_41 * V_42 ;
int V_43 ;
T_3 V_44 , V_45 ;
switch ( V_23 ) {
case V_32 :
V_43 = 0 ;
break;
case V_46 :
V_43 = 1 ;
V_42 = F_34 ( 0 ) ;
F_35 ( V_42 ) ;
break;
case V_47 :
V_43 = 2 ;
V_42 = F_34 ( 1 ) ;
F_35 ( V_42 ) ;
break;
default:
F_36 () ;
return;
}
F_37 ( V_48 , & V_44 , & V_45 ) ;
F_16 ( V_40 , V_43 , V_44 , V_45 ) ;
V_4 . V_49 = V_23 ;
}
void F_38 ( int V_50 ,
enum V_22 V_23 )
{
struct V_41 * V_42 ;
int V_43 , V_51 ;
switch ( V_23 ) {
case V_32 :
V_43 = 0 ;
break;
case V_52 :
F_12 ( V_50 != 0 ) ;
V_43 = 1 ;
V_42 = F_34 ( 0 ) ;
F_39 ( V_42 ) ;
break;
case V_53 :
F_12 ( V_50 != 1 ) ;
V_43 = 1 ;
V_42 = F_34 ( 1 ) ;
F_39 ( V_42 ) ;
break;
default:
F_36 () ;
return;
}
V_51 = V_50 == 0 ? 1 : 10 ;
F_16 ( V_40 , V_43 , V_51 , V_51 ) ;
V_4 . V_54 [ V_50 ] = V_23 ;
}
void F_40 ( enum V_55 V_56 ,
enum V_22 V_23 )
{
struct V_41 * V_42 ;
int V_43 , V_57 , V_51 ;
if ( ! F_41 ( V_58 ) )
return;
switch ( V_23 ) {
case V_32 :
V_43 = 0 ;
break;
case V_46 :
F_12 ( V_56 != V_7 ) ;
V_43 = 1 ;
V_42 = F_34 ( 0 ) ;
F_35 ( V_42 ) ;
break;
case V_47 :
F_12 ( V_56 != V_59 &&
V_56 != V_60 ) ;
V_43 = 1 ;
V_42 = F_34 ( 1 ) ;
F_35 ( V_42 ) ;
break;
default:
F_36 () ;
return;
}
V_51 = V_56 == V_7 ? 0 :
( V_56 == V_59 ? 12 : 19 ) ;
F_16 ( V_40 , V_43 , V_51 , V_51 ) ;
V_57 = V_56 == V_7 ? 0 :
( V_56 == V_59 ? 1 : 2 ) ;
V_4 . V_61 [ V_57 ] = V_23 ;
}
enum V_22 F_42 ( void )
{
return V_4 . V_49 ;
}
enum V_22 F_43 ( int V_50 )
{
return V_4 . V_54 [ V_50 ] ;
}
enum V_22 F_44 ( enum V_55 V_56 )
{
if ( F_41 ( V_58 ) ) {
int V_57 = V_56 == V_7 ? 0 :
( V_56 == V_59 ? 1 : 2 ) ;
return V_4 . V_61 [ V_57 ] ;
} else {
return V_4 . V_49 ;
}
}
int F_45 ( struct V_62 * V_63 )
{
if ( V_4 . V_34 ) {
unsigned long V_64 ;
int T_2 ;
V_64 = F_28 ( F_29 ( V_4 . V_34 ) ) ;
F_6 ( L_12 , V_64 ) ;
T_2 = F_46 ( V_4 . V_34 , V_64 / V_63 -> V_65 ) ;
if ( T_2 )
return T_2 ;
} else {
if ( V_63 -> V_65 != 0 )
return - V_66 ;
}
F_6 ( L_13 , V_63 -> V_67 , V_63 -> V_65 ) ;
return 0 ;
}
unsigned long F_47 ( void )
{
if ( V_4 . V_34 )
return F_28 ( F_29 ( V_4 . V_34 ) ) ;
else
return 0 ;
}
int F_48 ( unsigned long V_68 , struct V_62 * V_69 ,
struct V_70 * V_71 )
{
unsigned long V_64 ;
struct V_62 V_72 ;
struct V_70 V_73 ;
unsigned long V_67 , V_74 ;
T_4 V_65 ;
int V_75 = 0 ;
int V_76 ;
V_64 = F_47 () ;
V_74 = F_49 ( V_77 ) ;
V_67 = F_28 ( V_4 . V_33 ) ;
if ( V_68 == V_4 . V_78 && V_64 == V_4 . V_79 &&
V_4 . V_80 . V_67 == V_67 ) {
F_6 ( L_14 ) ;
* V_69 = V_4 . V_80 ;
* V_71 = V_4 . V_81 ;
return 0 ;
}
V_76 = V_82 ;
if ( V_76 &&
V_68 * V_76 > V_74 ) {
F_20 ( L_15
L_16
L_17 ) ;
V_76 = 0 ;
}
V_83:
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
if ( V_4 . V_34 == NULL ) {
struct V_70 V_84 ;
V_67 = F_28 ( V_4 . V_33 ) ;
V_65 = 1 ;
F_50 ( V_68 , V_67 , & V_84 ) ;
V_75 = 1 ;
V_72 . V_67 = V_67 ;
V_72 . V_65 = V_65 ;
V_73 = V_84 ;
goto V_85;
} else {
for ( V_65 = V_4 . V_35 -> V_86 ; V_65 > 0 ; -- V_65 ) {
struct V_70 V_84 ;
V_67 = V_64 / V_65 * V_4 . V_35 -> V_36 ;
if ( V_67 > V_74 )
continue;
if ( V_76 &&
V_67 < V_68 * V_76 )
continue;
V_75 = 1 ;
F_50 ( V_68 , V_67 , & V_84 ) ;
if ( abs ( V_84 . V_87 - V_68 ) <
abs ( V_73 . V_87 - V_68 ) ) {
V_72 . V_67 = V_67 ;
V_72 . V_65 = V_65 ;
V_73 = V_84 ;
if ( V_84 . V_87 == V_68 )
goto V_85;
}
}
}
V_85:
if ( ! V_75 ) {
if ( V_76 ) {
F_20 ( L_18
L_19
L_20 ) ;
V_76 = 0 ;
goto V_83;
}
F_20 ( L_18 ) ;
return - V_66 ;
}
if ( V_69 )
* V_69 = V_72 ;
if ( V_71 )
* V_71 = V_73 ;
V_4 . V_78 = V_68 ;
V_4 . V_79 = V_64 ;
V_4 . V_80 = V_72 ;
V_4 . V_81 = V_73 ;
return 0 ;
}
void F_51 ( enum V_88 type )
{
int V_13 = 0 ;
if ( type == V_89 )
V_13 = 0 ;
else if ( type == V_90 )
V_13 = 1 ;
else
F_36 () ;
F_16 ( V_40 , V_13 , 6 , 6 ) ;
}
void F_52 ( bool V_91 )
{
F_16 ( V_40 , V_91 , 5 , 5 ) ;
}
void F_53 ( enum V_92 V_93 )
{
enum V_94 V_95 ;
V_95 = F_8 ( V_96 ) ;
F_54 ( ( V_93 == V_97 ) && ! ( V_95 & V_98 ) ) ;
F_54 ( ( V_93 == V_99 ) && ! ( V_95 & V_100 ) ) ;
if ( ( V_95 & V_98 ) && ( V_95 & V_100 ) )
F_16 ( V_40 , V_93 , 15 , 15 ) ;
}
enum V_92 F_55 ( void )
{
enum V_94 V_101 ;
V_101 = F_8 ( V_96 ) ;
if ( ( V_101 & V_100 ) == 0 )
return V_97 ;
if ( ( V_101 & V_98 ) == 0 )
return V_99 ;
return F_56 ( V_40 , 15 , 15 ) ;
}
static int F_57 ( enum V_55 V_56 )
{
if ( V_56 != V_7 )
return - V_66 ;
return 0 ;
}
static int F_58 ( enum V_55 V_56 )
{
int V_3 ;
switch ( V_56 ) {
case V_59 :
V_3 = 0 ;
break;
case V_96 :
V_3 = 1 ;
break;
default:
return - V_66 ;
}
F_16 ( V_40 , V_3 , 17 , 17 ) ;
return 0 ;
}
static int F_59 ( enum V_55 V_56 )
{
int V_3 ;
switch ( V_56 ) {
case V_7 :
V_3 = 1 ;
break;
case V_59 :
V_3 = 2 ;
break;
case V_60 :
V_3 = 3 ;
break;
case V_96 :
V_3 = 0 ;
break;
default:
return - V_66 ;
}
F_16 ( V_40 , V_3 , 17 , 16 ) ;
return 0 ;
}
int F_60 ( enum V_55 V_56 )
{
return V_4 . V_35 -> V_102 ( V_56 ) ;
}
static int F_61 ( void )
{
struct V_103 * V_103 ;
int T_2 ;
V_103 = F_62 ( & V_4 . V_104 -> V_105 , L_21 ) ;
if ( F_63 ( V_103 ) ) {
F_20 ( L_22 ) ;
T_2 = F_64 ( V_103 ) ;
goto V_106;
}
V_4 . V_33 = V_103 ;
if ( V_4 . V_35 -> V_107 ) {
V_103 = F_62 ( NULL , V_4 . V_35 -> V_107 ) ;
if ( F_63 ( V_103 ) ) {
F_20 ( L_23 , V_4 . V_35 -> V_107 ) ;
T_2 = F_64 ( V_103 ) ;
goto V_106;
}
} else {
V_103 = NULL ;
}
V_4 . V_34 = V_103 ;
return 0 ;
V_106:
if ( V_4 . V_33 )
F_65 ( V_4 . V_33 ) ;
if ( V_4 . V_34 )
F_65 ( V_4 . V_34 ) ;
return T_2 ;
}
static void F_66 ( void )
{
if ( V_4 . V_34 )
F_65 ( V_4 . V_34 ) ;
F_65 ( V_4 . V_33 ) ;
}
static int F_25 ( void )
{
int T_2 ;
F_6 ( L_24 ) ;
T_2 = F_67 ( & V_4 . V_104 -> V_105 ) ;
F_54 ( T_2 < 0 ) ;
return T_2 < 0 ? T_2 : 0 ;
}
static void F_30 ( void )
{
int T_2 ;
F_6 ( L_25 ) ;
T_2 = F_68 ( & V_4 . V_104 -> V_105 ) ;
F_54 ( T_2 < 0 && T_2 != - V_108 && T_2 != - V_109 ) ;
}
void F_69 ( struct V_25 * V_26 )
{
F_24 ( V_26 ) ;
F_70 ( V_26 ) ;
#ifdef F_71
F_72 ( V_26 ) ;
#endif
}
static int T_5 F_73 ( struct V_110 * V_105 )
{
const struct V_111 * V_93 ;
struct V_111 * V_112 ;
V_112 = F_74 ( V_105 , sizeof( * V_112 ) , V_113 ) ;
if ( ! V_112 ) {
F_75 ( V_105 , L_26 ) ;
return - V_114 ;
}
if ( F_76 () )
V_93 = & V_115 ;
else if ( F_77 () )
V_93 = & V_116 ;
else if ( F_78 () )
V_93 = & V_117 ;
else if ( F_79 () )
V_93 = & V_118 ;
else if ( F_80 () )
V_93 = & V_119 ;
else
return - V_120 ;
memcpy ( V_112 , V_93 , sizeof( * V_112 ) ) ;
V_4 . V_35 = V_112 ;
return 0 ;
}
static int T_5 F_81 ( struct V_41 * V_104 )
{
struct V_121 * V_122 ;
T_1 V_123 ;
int T_2 ;
V_4 . V_104 = V_104 ;
T_2 = F_73 ( & V_4 . V_104 -> V_105 ) ;
if ( T_2 )
return T_2 ;
V_122 = F_82 ( V_4 . V_104 , V_124 , 0 ) ;
if ( ! V_122 ) {
F_20 ( L_27 ) ;
return - V_66 ;
}
V_4 . V_5 = F_83 ( & V_104 -> V_105 , V_122 -> V_44 ,
F_84 ( V_122 ) ) ;
if ( ! V_4 . V_5 ) {
F_20 ( L_28 ) ;
return - V_114 ;
}
T_2 = F_61 () ;
if ( T_2 )
return T_2 ;
F_85 ( & V_104 -> V_105 ) ;
T_2 = F_25 () ;
if ( T_2 )
goto V_125;
F_16 ( V_40 , 0 , 0 , 0 ) ;
#ifdef F_86
F_16 ( V_40 , 1 , 4 , 4 ) ;
F_16 ( V_40 , 1 , 3 , 3 ) ;
F_16 ( V_40 , 0 , 2 , 2 ) ;
#endif
V_4 . V_54 [ 0 ] = V_32 ;
V_4 . V_54 [ 1 ] = V_32 ;
V_4 . V_49 = V_32 ;
V_4 . V_61 [ 0 ] = V_32 ;
V_4 . V_61 [ 1 ] = V_32 ;
V_123 = F_3 ( V_37 ) ;
F_87 ( V_126 L_29 ,
F_88 ( V_123 , 7 , 4 ) , F_88 ( V_123 , 3 , 0 ) ) ;
F_30 () ;
F_89 ( L_30 , F_31 ) ;
return 0 ;
V_125:
F_90 ( & V_104 -> V_105 ) ;
F_66 () ;
return T_2 ;
}
static int T_6 F_91 ( struct V_41 * V_104 )
{
F_90 ( & V_104 -> V_105 ) ;
F_66 () ;
return 0 ;
}
static int F_92 ( struct V_110 * V_105 )
{
F_5 () ;
F_93 ( V_105 , 0 ) ;
return 0 ;
}
static int F_94 ( struct V_110 * V_105 )
{
int T_2 ;
T_2 = F_93 ( V_105 , 1000000000 ) ;
if ( T_2 )
return T_2 ;
F_9 () ;
return 0 ;
}
int T_5 F_95 ( void )
{
return F_96 ( & V_127 , F_81 ) ;
}
void F_97 ( void )
{
F_98 ( & V_127 ) ;
}
