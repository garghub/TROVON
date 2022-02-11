static inline void F_1 ( const struct V_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 . V_5 + V_2 . V_2 ) ;
}
static inline T_1 F_3 ( const struct V_1 V_2 )
{
return F_4 ( V_4 . V_5 + V_2 . V_2 ) ;
}
void F_5 ( void )
{
if ( F_6 () )
return;
F_7 ( V_6 ) ;
F_7 ( V_7 ) ;
if ( F_8 ( V_8 ) &
V_9 ) {
F_7 ( V_10 ) ;
F_7 ( V_11 ) ;
}
}
void F_9 ( void )
{
if ( F_10 () )
F_11 ( L_1 ) ;
F_12 ( V_6 ) ;
F_12 ( V_7 ) ;
if ( F_8 ( V_8 ) &
V_9 ) {
F_12 ( V_10 ) ;
F_12 ( V_11 ) ;
}
}
void F_13 ( T_2 V_12 )
{
T_1 V_13 ;
F_14 ( V_12 > 3 || V_12 < 1 ) ;
V_13 = F_3 ( V_14 ) ;
V_13 = F_15 ( V_13 , 0xf , 19 , 15 ) ;
V_13 = F_15 ( V_13 , V_12 - 1 , 3 , 2 ) ;
V_13 = F_15 ( V_13 , 2 , 1 , 0 ) ;
F_1 ( V_14 , V_13 ) ;
V_13 = F_3 ( V_15 ) ;
V_13 = F_15 ( V_13 , 0x7 , 25 , 22 ) ;
V_13 = F_15 ( V_13 , 0xb , 16 , 11 ) ;
V_13 = F_15 ( V_13 , 0xb4 , 10 , 1 ) ;
F_1 ( V_15 , V_13 ) ;
}
int F_16 ( void )
{
unsigned long V_16 ;
F_17 ( 1 ) ;
F_18 ( V_15 , 1 , 18 , 18 ) ;
F_19 ( 1 ) ;
F_18 ( V_15 , 1 , 28 , 28 ) ;
V_16 = V_17 + F_20 ( 500 ) ;
while ( F_3 ( V_18 ) & ( 1 << 6 ) ) {
if ( F_21 ( V_17 , V_16 ) ) {
F_11 ( L_2 ) ;
goto V_19;
}
}
F_18 ( V_15 , 0 , 28 , 28 ) ;
V_16 = V_17 + F_20 ( 500 ) ;
while ( ! ( F_3 ( V_18 ) & ( 1 << 5 ) ) ) {
if ( F_21 ( V_17 , V_16 ) ) {
F_11 ( L_3 ) ;
goto V_19;
}
}
F_22 ( 1 ) ;
V_16 = V_17 + F_20 ( 500 ) ;
while ( ! ( F_3 ( V_18 ) & ( 1 << 2 ) ) ) {
if ( F_21 ( V_17 , V_16 ) ) {
F_11 ( L_4 ) ;
goto V_20;
}
}
return 0 ;
V_20:
F_22 ( 0 ) ;
V_19:
F_18 ( V_15 , 0 , 18 , 18 ) ;
F_17 ( 0 ) ;
return - V_21 ;
}
void F_23 ( void )
{
F_22 ( 0 ) ;
F_17 ( 0 ) ;
F_18 ( V_15 , 0 , 18 , 18 ) ;
}
const char * F_24 ( enum V_22 V_23 )
{
return V_24 [ V_23 ] ;
}
void F_25 ( struct V_25 * V_26 )
{
unsigned long V_27 ;
unsigned long V_28 ;
const char * V_29 , * V_30 ;
unsigned long V_31 ;
F_26 ( V_32 | V_33 ) ;
F_27 ( V_26 , L_5 ) ;
V_29 = F_24 ( V_34 ) ;
V_30 = F_28 ( V_34 ) ;
V_31 = F_29 ( V_33 ) ;
if ( V_4 . V_35 ) {
V_27 = F_30 ( F_31 ( V_4 . V_35 ) ) ;
V_28 = F_30 ( V_4 . V_35 ) ;
F_27 ( V_26 , L_6 , V_27 ) ;
if ( F_32 () || F_33 () )
F_27 ( V_26 , L_7 ,
V_29 , V_30 ,
V_27 ,
V_27 / V_28 ,
V_31 ) ;
else
F_27 ( V_26 , L_8 ,
V_29 , V_30 ,
V_27 ,
V_27 / V_28 ,
V_31 ) ;
} else {
F_27 ( V_26 , L_9 ,
V_29 , V_30 ,
V_31 ) ;
}
F_34 ( V_32 | V_33 ) ;
}
void F_35 ( struct V_25 * V_26 )
{
#define F_36 ( T_3 ) seq_printf(s, "%-35s %08x\n", #r, dss_read_reg(r))
F_26 ( V_32 | V_33 ) ;
F_36 ( V_36 ) ;
F_36 ( V_37 ) ;
F_36 ( V_38 ) ;
F_36 ( V_39 ) ;
if ( F_8 ( V_8 ) &
V_9 ) {
F_36 ( V_14 ) ;
F_36 ( V_15 ) ;
F_36 ( V_18 ) ;
}
F_34 ( V_32 | V_33 ) ;
#undef F_36
}
void F_37 ( enum V_22 V_23 )
{
struct V_40 * V_41 ;
int V_42 ;
T_2 V_43 , V_44 ;
switch ( V_23 ) {
case V_34 :
V_42 = 0 ;
break;
case V_45 :
V_42 = 1 ;
V_41 = F_38 ( 0 ) ;
F_39 ( V_41 ) ;
break;
case V_46 :
V_42 = 2 ;
V_41 = F_38 ( 1 ) ;
F_39 ( V_41 ) ;
break;
default:
F_40 () ;
}
F_41 ( V_47 , & V_43 , & V_44 ) ;
F_18 ( V_39 , V_42 , V_43 , V_44 ) ;
V_4 . V_48 = V_23 ;
}
void F_42 ( int V_49 ,
enum V_22 V_23 )
{
struct V_40 * V_41 ;
int V_42 ;
switch ( V_23 ) {
case V_34 :
V_42 = 0 ;
break;
case V_50 :
F_14 ( V_49 != 0 ) ;
V_42 = 1 ;
V_41 = F_38 ( 0 ) ;
F_43 ( V_41 ) ;
break;
case V_51 :
F_14 ( V_49 != 1 ) ;
V_42 = 1 ;
V_41 = F_38 ( 1 ) ;
F_43 ( V_41 ) ;
break;
default:
F_40 () ;
}
F_18 ( V_39 , V_42 , 1 , 1 ) ;
V_4 . V_52 [ V_49 ] = V_23 ;
}
void F_44 ( enum V_53 V_54 ,
enum V_22 V_23 )
{
struct V_40 * V_41 ;
int V_42 , V_55 , V_56 ;
if ( ! F_45 ( V_57 ) )
return;
switch ( V_23 ) {
case V_34 :
V_42 = 0 ;
break;
case V_45 :
F_14 ( V_54 != V_8 ) ;
V_42 = 1 ;
V_41 = F_38 ( 0 ) ;
F_39 ( V_41 ) ;
break;
case V_46 :
F_14 ( V_54 != V_58 ) ;
V_42 = 1 ;
V_41 = F_38 ( 1 ) ;
F_39 ( V_41 ) ;
break;
default:
F_40 () ;
}
V_56 = V_54 == V_8 ? 0 : 12 ;
F_18 ( V_39 , V_42 , V_56 , V_56 ) ;
V_55 = V_54 == V_8 ? 0 : 1 ;
V_4 . V_59 [ V_55 ] = V_23 ;
}
enum V_22 F_46 ( void )
{
return V_4 . V_48 ;
}
enum V_22 F_47 ( int V_49 )
{
return V_4 . V_52 [ V_49 ] ;
}
enum V_22 F_48 ( enum V_53 V_54 )
{
if ( F_45 ( V_57 ) ) {
int V_55 = V_54 == V_8 ? 0 : 1 ;
return V_4 . V_59 [ V_55 ] ;
} else {
return V_4 . V_48 ;
}
}
int F_49 ( struct V_60 * V_61 )
{
if ( V_4 . V_35 ) {
unsigned long V_62 ;
T_4 V_63 = 16 ;
if ( F_32 () || F_33 () )
V_63 = 32 ;
if ( V_61 -> V_64 > V_63 || V_61 -> V_64 == 0 )
return - V_65 ;
V_62 = F_30 ( F_31 ( V_4 . V_35 ) ) ;
V_61 -> V_66 = V_62 / V_61 -> V_64 ;
} else {
if ( V_61 -> V_64 != 0 )
return - V_65 ;
V_61 -> V_66 = F_29 ( V_33 ) ;
}
return 0 ;
}
int F_50 ( struct V_60 * V_61 )
{
if ( V_4 . V_35 ) {
unsigned long V_62 ;
int T_3 ;
V_62 = F_30 ( F_31 ( V_4 . V_35 ) ) ;
F_51 ( L_10 , V_62 ) ;
T_3 = F_52 ( V_4 . V_35 , V_62 / V_61 -> V_64 ) ;
if ( T_3 )
return T_3 ;
} else {
if ( V_61 -> V_64 != 0 )
return - V_65 ;
}
F_51 ( L_11 , V_61 -> V_66 , V_61 -> V_64 ) ;
return 0 ;
}
int F_53 ( struct V_60 * V_61 )
{
V_61 -> V_66 = F_29 ( V_33 ) ;
if ( V_4 . V_35 ) {
unsigned long V_62 ;
V_62 = F_30 ( F_31 ( V_4 . V_35 ) ) ;
if ( F_32 () || F_33 () )
V_61 -> V_64 = V_62 / ( V_61 -> V_66 ) ;
else
V_61 -> V_64 = V_62 / ( V_61 -> V_66 / 2 ) ;
} else {
V_61 -> V_64 = 0 ;
}
return 0 ;
}
unsigned long F_54 ( void )
{
if ( V_4 . V_35 )
return F_30 ( F_31 ( V_4 . V_35 ) ) ;
else
return 0 ;
}
int F_55 ( bool V_67 , unsigned long V_68 ,
struct V_60 * V_69 ,
struct V_70 * V_71 )
{
unsigned long V_62 ;
struct V_60 V_72 ;
struct V_70 V_73 ;
unsigned long V_66 , V_74 ;
T_4 V_64 , V_63 = 16 ;
int V_75 = 0 ;
int V_76 ;
V_62 = F_54 () ;
V_74 = F_56 ( V_77 ) ;
V_66 = F_29 ( V_33 ) ;
if ( V_68 == V_4 . V_78 &&
( ( F_57 () && V_62 == V_4 . V_79 ) ||
V_4 . V_80 . V_66 == V_66 ) ) {
F_51 ( L_12 ) ;
* V_69 = V_4 . V_80 ;
* V_71 = V_4 . V_81 ;
return 0 ;
}
V_76 = V_82 ;
if ( V_76 &&
V_68 * V_76 > V_74 ) {
F_11 ( L_13
L_14
L_15 ) ;
V_76 = 0 ;
}
V_83:
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
if ( V_4 . V_35 == NULL ) {
struct V_70 V_84 ;
V_66 = F_29 ( V_33 ) ;
V_64 = 1 ;
F_58 ( V_67 , V_68 , V_66 , & V_84 ) ;
V_75 = 1 ;
V_72 . V_66 = V_66 ;
V_72 . V_64 = V_64 ;
V_73 = V_84 ;
goto V_85;
} else {
if ( F_32 () || F_33 () )
V_63 = 32 ;
for ( V_64 = V_63 ; V_64 > 0 ; -- V_64 ) {
struct V_70 V_84 ;
if ( V_63 == 32 )
V_66 = V_62 / V_64 ;
else
V_66 = V_62 / V_64 * 2 ;
if ( V_66 > V_74 )
continue;
if ( V_76 &&
V_66 < V_68 * V_76 )
continue;
V_75 = 1 ;
F_58 ( V_67 , V_68 , V_66 , & V_84 ) ;
if ( abs ( V_84 . V_86 - V_68 ) <
abs ( V_73 . V_86 - V_68 ) ) {
V_72 . V_66 = V_66 ;
V_72 . V_64 = V_64 ;
V_73 = V_84 ;
if ( V_84 . V_86 == V_68 )
goto V_85;
}
}
}
V_85:
if ( ! V_75 ) {
if ( V_76 ) {
F_11 ( L_16
L_17
L_18 ) ;
V_76 = 0 ;
goto V_83;
}
F_11 ( L_16 ) ;
return - V_65 ;
}
if ( V_69 )
* V_69 = V_72 ;
if ( V_71 )
* V_71 = V_73 ;
V_4 . V_78 = V_68 ;
V_4 . V_79 = V_62 ;
V_4 . V_80 = V_72 ;
V_4 . V_81 = V_73 ;
return 0 ;
}
static int F_10 ( void )
{
int V_87 = 0 ;
while ( F_59 ( V_38 , 0 , 0 ) == 0 ) {
if ( ++ V_87 > 1000 ) {
F_11 ( L_19 ) ;
return - V_88 ;
}
F_19 ( 1 ) ;
}
return 0 ;
}
static int F_60 ( void )
{
F_18 ( V_37 , 1 , 1 , 1 ) ;
return F_10 () ;
}
void F_61 ( enum V_89 type )
{
int V_13 = 0 ;
if ( type == V_90 )
V_13 = 0 ;
else if ( type == V_91 )
V_13 = 1 ;
else
F_40 () ;
F_18 ( V_39 , V_13 , 6 , 6 ) ;
}
void F_62 ( bool V_92 )
{
F_18 ( V_39 , V_92 , 5 , 5 ) ;
}
void F_63 ( enum V_93 V_94 )
{
F_18 ( V_39 , V_94 , 15 , 15 ) ;
}
static int F_64 ( void )
{
int T_3 ;
T_1 V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_35 ;
V_97 = F_65 ( V_4 . V_99 , V_100 , 0 ) ;
if ( ! V_97 ) {
F_11 ( L_20 ) ;
T_3 = - V_65 ;
goto V_101;
}
V_4 . V_5 = F_66 ( V_97 -> V_43 , F_67 ( V_97 ) ) ;
if ( ! V_4 . V_5 ) {
F_11 ( L_21 ) ;
T_3 = - V_102 ;
goto V_101;
}
F_68 ( F_69 ( 0x48050440 ) & ~ 0x3 , 0x48050440 ) ;
#ifdef F_70
F_71 ( 50 ) ;
#endif
F_60 () ;
F_18 ( V_37 , 1 , 0 , 0 ) ;
F_18 ( V_39 , 0 , 0 , 0 ) ;
#ifdef F_72
F_18 ( V_39 , 1 , 4 , 4 ) ;
F_18 ( V_39 , 1 , 3 , 3 ) ;
F_18 ( V_39 , 0 , 2 , 2 ) ;
#endif
if ( F_57 () ) {
V_35 = F_73 ( NULL , L_22 ) ;
if ( F_74 ( V_35 ) ) {
F_11 ( L_23 ) ;
T_3 = F_75 ( V_35 ) ;
goto V_103;
}
} else if ( F_33 () ) {
V_35 = F_73 ( NULL , L_24 ) ;
if ( F_74 ( V_35 ) ) {
F_11 ( L_23 ) ;
T_3 = F_75 ( V_35 ) ;
goto V_103;
}
} else {
V_35 = NULL ;
}
V_4 . V_35 = V_35 ;
V_4 . V_52 [ 0 ] = V_34 ;
V_4 . V_52 [ 1 ] = V_34 ;
V_4 . V_48 = V_34 ;
V_4 . V_59 [ 0 ] = V_34 ;
V_4 . V_59 [ 1 ] = V_34 ;
F_5 () ;
V_95 = F_3 ( V_36 ) ;
F_76 ( V_104 L_25 ,
F_77 ( V_95 , 7 , 4 ) , F_77 ( V_95 , 3 , 0 ) ) ;
return 0 ;
V_103:
F_78 ( V_4 . V_5 ) ;
V_101:
return T_3 ;
}
static void F_79 ( void )
{
if ( V_4 . V_35 )
F_80 ( V_4 . V_35 ) ;
F_78 ( V_4 . V_5 ) ;
}
static int F_81 ( void )
{
struct V_105 * V_106 = V_4 . V_99 -> V_107 . V_108 ;
int T_3 ;
if ( ! V_106 -> V_109 -> V_110 )
return 0 ;
T_3 = V_106 -> V_109 -> V_110 ( & V_4 . V_99 -> V_107 ) ;
if ( T_3 < 0 ) {
F_82 ( & V_4 . V_99 -> V_107 , L_26
L_27 ) ;
T_3 = - 1 ;
}
return T_3 ;
}
int F_83 ( void )
{
int V_111 = F_81 () ;
if ( V_111 < 0 || V_111 != V_4 . V_112 ) {
F_51 ( L_28 ,
V_4 . V_112 , V_111 ) ;
V_4 . V_112 = V_111 ;
return 1 ;
} else {
return 0 ;
}
}
static void F_84 ( void )
{
F_51 ( L_29 ) ;
F_85 ( V_32 | V_33 ) ;
F_5 () ;
F_86 () ;
#ifdef F_87
F_88 () ;
#endif
F_89 ( V_32 | V_33 ) ;
}
static void F_90 ( void )
{
F_51 ( L_30 ) ;
F_91 () ;
F_9 () ;
F_92 () ;
#ifdef F_87
F_93 () ;
#endif
F_94 () ;
}
static int F_95 ( struct V_98 * * clock , const char * V_113 )
{
struct V_98 * V_98 ;
V_98 = F_73 ( & V_4 . V_99 -> V_107 , V_113 ) ;
if ( F_74 ( V_98 ) ) {
F_11 ( L_31 , V_113 ) ;
return F_75 ( V_98 ) ;
}
* clock = V_98 ;
F_51 ( L_32 , V_113 , F_30 ( V_98 ) ) ;
return 0 ;
}
static int F_96 ( void )
{
int T_3 ;
struct V_105 * V_106 = V_4 . V_99 -> V_107 . V_108 ;
V_4 . V_114 = NULL ;
V_4 . V_115 = NULL ;
V_4 . V_116 = NULL ;
V_4 . V_117 = NULL ;
V_4 . V_118 = NULL ;
T_3 = F_95 ( & V_4 . V_114 , L_33 ) ;
if ( T_3 )
goto V_119;
T_3 = F_95 ( & V_4 . V_115 , L_34 ) ;
if ( T_3 )
goto V_119;
if ( ! V_106 -> V_120 ) {
T_3 = - V_88 ;
goto V_119;
}
if ( V_106 -> V_120 ( L_35 ) ) {
T_3 = F_95 ( & V_4 . V_116 , L_35 ) ;
if ( T_3 )
goto V_119;
}
if ( V_106 -> V_120 ( L_36 ) ) {
T_3 = F_95 ( & V_4 . V_117 , L_36 ) ;
if ( T_3 )
goto V_119;
}
if ( V_106 -> V_120 ( L_37 ) ) {
T_3 = F_95 ( & V_4 . V_118 , L_37 ) ;
if ( T_3 )
goto V_119;
}
return 0 ;
V_119:
if ( V_4 . V_114 )
F_80 ( V_4 . V_114 ) ;
if ( V_4 . V_115 )
F_80 ( V_4 . V_115 ) ;
if ( V_4 . V_116 )
F_80 ( V_4 . V_116 ) ;
if ( V_4 . V_117 )
F_80 ( V_4 . V_117 ) ;
if ( V_4 . V_118 )
F_80 ( V_4 . V_118 ) ;
return T_3 ;
}
static void F_97 ( void )
{
if ( V_4 . V_118 )
F_80 ( V_4 . V_118 ) ;
if ( V_4 . V_117 )
F_80 ( V_4 . V_117 ) ;
if ( V_4 . V_116 )
F_80 ( V_4 . V_116 ) ;
F_80 ( V_4 . V_115 ) ;
F_80 ( V_4 . V_114 ) ;
}
unsigned long F_29 ( enum V_121 V_98 )
{
switch ( V_98 ) {
case V_32 :
return F_30 ( V_4 . V_114 ) ;
case V_33 :
return F_30 ( V_4 . V_115 ) ;
case V_122 :
return F_30 ( V_4 . V_116 ) ;
case V_123 :
return F_30 ( V_4 . V_117 ) ;
case V_124 :
return F_30 ( V_4 . V_118 ) ;
}
F_40 () ;
return 0 ;
}
static unsigned F_98 ( enum V_121 V_125 )
{
unsigned V_126 = 0 ;
if ( V_125 & V_32 )
++ V_126 ;
if ( V_125 & V_33 )
++ V_126 ;
if ( V_125 & V_122 )
++ V_126 ;
if ( V_125 & V_123 )
++ V_126 ;
if ( V_125 & V_124 )
++ V_126 ;
return V_126 ;
}
static void F_85 ( enum V_121 V_125 )
{
unsigned V_126 = F_98 ( V_125 ) ;
if ( V_125 & V_32 )
F_99 ( V_4 . V_114 ) ;
if ( V_125 & V_33 )
F_99 ( V_4 . V_115 ) ;
if ( ( V_125 & V_122 ) && V_4 . V_116 )
F_99 ( V_4 . V_116 ) ;
if ( ( V_125 & V_123 ) && V_4 . V_117 )
F_99 ( V_4 . V_117 ) ;
if ( ( V_125 & V_124 ) && V_4 . V_118 )
F_99 ( V_4 . V_118 ) ;
V_4 . V_127 += V_126 ;
}
void F_26 ( enum V_121 V_125 )
{
bool V_128 = V_4 . V_127 == 0 ;
F_85 ( V_125 ) ;
if ( F_33 () && V_128 )
F_19 ( 10 ) ;
if ( V_128 && F_57 () && F_83 () )
F_90 () ;
}
static void F_89 ( enum V_121 V_125 )
{
unsigned V_126 = F_98 ( V_125 ) ;
if ( V_125 & V_32 )
F_100 ( V_4 . V_114 ) ;
if ( V_125 & V_33 )
F_100 ( V_4 . V_115 ) ;
if ( ( V_125 & V_122 ) && V_4 . V_116 )
F_100 ( V_4 . V_116 ) ;
if ( ( V_125 & V_123 ) && V_4 . V_117 )
F_100 ( V_4 . V_117 ) ;
if ( ( V_125 & V_124 ) && V_4 . V_118 )
F_100 ( V_4 . V_118 ) ;
V_4 . V_127 -= V_126 ;
}
void F_34 ( enum V_121 V_125 )
{
if ( F_57 () ) {
unsigned V_126 = F_98 ( V_125 ) ;
F_14 ( V_4 . V_127 < V_126 ) ;
if ( V_4 . V_127 == V_126 )
F_84 () ;
}
F_89 ( V_125 ) ;
}
static void F_91 ( void )
{
enum V_121 V_125 ;
V_125 = V_32 | V_33 | V_122 | V_123 ;
if ( F_57 () )
V_125 |= V_124 ;
F_85 ( V_125 ) ;
}
static void F_94 ( void )
{
enum V_121 V_125 ;
V_125 = V_32 | V_33 | V_122 | V_123 ;
if ( F_57 () )
V_125 |= V_124 ;
F_89 ( V_125 ) ;
}
static void F_101 ( struct V_25 * V_26 )
{
int V_129 ;
struct V_98 * V_130 [ 5 ] = {
V_4 . V_114 ,
V_4 . V_115 ,
V_4 . V_116 ,
V_4 . V_117 ,
V_4 . V_118
} ;
const char * V_131 [ 5 ] = {
L_33 ,
L_34 ,
L_35 ,
L_38 ,
L_39
} ;
F_27 ( V_26 , L_40 ) ;
F_27 ( V_26 , L_41 , V_4 . V_127 ) ;
for ( V_129 = 0 ; V_129 < 5 ; V_129 ++ ) {
if ( ! V_130 [ V_129 ] )
continue;
F_27 ( V_26 , L_42 ,
V_131 [ V_129 ] ,
V_130 [ V_129 ] -> V_132 ,
24 - strlen ( V_131 [ V_129 ] ) - strlen ( V_130 [ V_129 ] -> V_132 ) ,
L_43 ,
F_30 ( V_130 [ V_129 ] ) ,
V_130 [ V_129 ] -> V_133 ) ;
}
}
void F_102 ( struct V_25 * V_26 )
{
F_101 ( V_26 ) ;
F_25 ( V_26 ) ;
F_103 ( V_26 ) ;
#ifdef F_87
F_104 ( V_26 ) ;
#endif
}
static int F_105 ( struct V_40 * V_99 )
{
int T_3 ;
V_4 . V_99 = V_99 ;
T_3 = F_96 () ;
if ( T_3 )
goto V_134;
F_91 () ;
V_4 . V_112 = F_81 () ;
F_51 ( L_44 , V_4 . V_112 ) ;
T_3 = F_64 () ;
if ( T_3 ) {
F_11 ( L_45 ) ;
goto V_135;
}
T_3 = F_106 () ;
if ( T_3 ) {
F_11 ( L_46 ) ;
goto V_136;
}
T_3 = F_107 () ;
if ( T_3 ) {
F_11 ( L_47 ) ;
goto V_137;
}
F_94 () ;
return 0 ;
V_137:
F_108 () ;
V_136:
F_79 () ;
V_135:
F_94 () ;
F_97 () ;
V_134:
return T_3 ;
}
static int F_109 ( struct V_40 * V_99 )
{
F_79 () ;
F_110 ( V_4 . V_127 > 0 ) ;
F_97 () ;
return 0 ;
}
int F_111 ( void )
{
return F_112 ( & V_138 ) ;
}
void F_113 ( void )
{
return F_114 ( & V_138 ) ;
}
