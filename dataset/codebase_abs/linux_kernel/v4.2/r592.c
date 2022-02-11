const char * F_1 ( int V_1 )
{
return V_2 [ V_1 - 1 ] ;
}
static inline T_1 F_2 ( struct V_3 * V_4 , int V_5 )
{
T_1 V_6 = F_3 ( V_4 -> V_7 + V_5 ) ;
F_4 ( L_1 , V_5 , V_6 ) ;
return V_6 ;
}
static inline void F_5 ( struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
F_4 ( L_2 , V_5 , V_6 ) ;
F_6 ( V_6 , V_4 -> V_7 + V_5 ) ;
}
static inline T_1 F_7 ( struct V_3 * V_4 , int V_5 )
{
T_1 V_6 = F_8 ( V_4 -> V_7 + V_5 ) ;
F_4 ( L_1 , V_5 , V_6 ) ;
return F_9 ( V_6 ) ;
}
static inline void F_10 ( struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
F_4 ( L_2 , V_5 , V_6 ) ;
F_11 ( F_12 ( V_6 ) , V_4 -> V_7 + V_5 ) ;
}
static inline void F_13 ( struct V_3 * V_4 ,
int V_5 , T_1 V_8 )
{
T_1 V_9 = F_3 ( V_4 -> V_7 + V_5 ) ;
F_4 ( L_3 , V_5 , V_8 , V_9 ) ;
F_6 ( V_9 | V_8 , V_4 -> V_7 + V_5 ) ;
}
static inline void F_14 ( struct V_3 * V_4 ,
int V_5 , T_1 V_8 )
{
T_1 V_9 = F_3 ( V_4 -> V_7 + V_5 ) ;
F_4 ( L_4 ,
V_5 , ~ V_8 , V_9 , V_8 ) ;
F_6 ( V_9 & ~ V_8 , V_4 -> V_7 + V_5 ) ;
}
static int F_15 ( struct V_3 * V_4 , T_1 V_8 , T_1 V_10 )
{
unsigned long V_11 = V_12 + F_16 ( 1000 ) ;
T_1 V_9 = F_2 ( V_4 , V_13 ) ;
if ( ( V_9 & V_8 ) == V_10 )
return 0 ;
while ( F_17 ( V_12 , V_11 ) ) {
V_9 = F_2 ( V_4 , V_13 ) ;
if ( ( V_9 & V_8 ) == V_10 )
return 0 ;
if ( V_9 & ( V_14 | V_15 ) )
return - V_16 ;
F_18 () ;
}
return - V_17 ;
}
static int F_19 ( struct V_3 * V_4 , bool V_18 )
{
F_20 ( L_5 , V_18 ? L_6 : L_7 ) ;
if ( V_18 ) {
F_5 ( V_4 , V_19 , V_20 | V_21 ) ;
F_13 ( V_4 , V_22 , V_23 ) ;
F_21 ( 100 ) ;
} else
F_5 ( V_4 , V_19 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , bool V_24 )
{
if ( ! V_24 ) {
F_20 ( L_8 ) ;
F_5 ( V_4 , V_25 , V_26 ) ;
F_14 ( V_4 , V_19 , V_27 ) ;
} else {
F_20 ( L_9 ) ;
F_13 ( V_4 , V_19 , V_27 ) ;
F_14 ( V_4 , V_22 ,
V_28 | V_29 ) ;
F_5 ( V_4 , V_25 , V_30 ) ;
}
V_4 -> V_24 = V_24 ;
return 0 ;
}
static void F_23 ( struct V_3 * V_4 )
{
F_13 ( V_4 , V_22 , V_23 ) ;
F_21 ( 100 ) ;
F_22 ( V_4 , V_4 -> V_24 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
F_14 ( V_4 , V_31 , V_32 ) ;
F_14 ( V_4 , V_31 , V_33 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
if ( ! ( F_2 ( V_4 , V_13 ) &
( V_14 | V_15 ) ) )
return 0 ;
return - V_16 ;
}
static int F_26 ( struct V_3 * V_4 )
{
if ( F_2 ( V_4 , V_31 ) & V_34 )
return 0 ;
F_20 ( L_10 ) ;
F_23 ( V_4 ) ;
if ( F_2 ( V_4 , V_31 ) & V_34 )
return 0 ;
F_27 ( L_11 ) ;
return - V_16 ;
}
static void F_28 ( struct V_3 * V_4 , bool V_35 )
{
unsigned long V_36 ;
T_1 V_9 ;
F_29 ( & V_4 -> V_37 , V_36 ) ;
F_14 ( V_4 , V_31 , V_38 ) ;
F_13 ( V_4 , V_31 , V_39 ) ;
F_5 ( V_4 , V_40 , F_30 ( & V_4 -> V_41 -> V_42 ) ) ;
V_9 = F_2 ( V_4 , V_43 ) ;
V_9 |= V_44 ;
if ( ! V_35 )
V_9 |= V_45 ;
else
V_9 &= ~ V_45 ;
F_5 ( V_4 , V_43 , V_9 ) ;
F_31 ( & V_4 -> V_37 , V_36 ) ;
}
static void F_32 ( struct V_3 * V_4 , int error )
{
F_14 ( V_4 , V_43 ,
V_44 ) ;
F_5 ( V_4 , V_40 ,
V_4 -> V_46 ) ;
F_14 ( V_4 , V_31 , V_39 ) ;
F_14 ( V_4 , V_31 , V_38 ) ;
V_4 -> V_47 = error ;
}
static void F_33 ( struct V_3 * V_4 )
{
V_4 -> V_48 = V_49 &&
( F_2 ( V_4 , V_43 ) &
V_50 ) ;
}
static int F_34 ( struct V_3 * V_4 )
{
int V_51 , V_52 ;
bool V_35 ;
if ( ! V_4 -> V_48 || ! V_4 -> V_41 -> V_53 )
return - V_54 ;
V_51 = V_4 -> V_41 -> V_42 . V_55 ;
V_35 = V_4 -> V_41 -> V_56 == V_57 ;
if ( V_51 != V_58 )
return - V_54 ;
F_35 ( L_12 ) ;
V_4 -> V_47 = 0 ;
F_36 ( & V_4 -> V_59 ) ;
V_52 = F_37 ( & V_4 -> V_60 -> V_4 , & V_4 -> V_41 -> V_42 , 1 , V_35 ?
V_61 : V_62 ) ;
if ( V_52 != 1 ||
( F_38 ( & V_4 -> V_41 -> V_42 ) < V_4 -> V_41 -> V_42 . V_55 ) ) {
F_27 ( L_13 ) ;
return - V_16 ;
}
F_28 ( V_4 , V_35 ) ;
if ( ! F_39 (
& V_4 -> V_59 , F_16 ( 1000 ) ) ) {
F_27 ( L_14 ) ;
F_32 ( V_4 , - V_63 ) ;
}
F_40 ( & V_4 -> V_60 -> V_4 , & V_4 -> V_41 -> V_42 , 1 , V_35 ?
V_61 : V_62 ) ;
return V_4 -> V_47 ;
}
static void F_41 ( struct V_3 * V_4 ,
unsigned char * V_64 , int V_51 )
{
if ( ! F_42 ( & V_4 -> V_65 ) ) {
T_2 V_66 [ 4 ] = { 0 } ;
int V_67 = F_43 ( & V_4 -> V_65 , V_64 , V_51 ) ;
if ( ! F_44 ( & V_4 -> V_65 ) )
return;
V_51 -= V_67 ;
V_64 += V_67 ;
V_67 = F_45 ( & V_4 -> V_65 , V_66 , 4 ) ;
F_46 ( V_67 != 4 ) ;
F_10 ( V_4 , V_68 , * ( T_1 * ) V_66 ) ;
}
F_46 ( ! F_42 ( & V_4 -> V_65 ) ) ;
while ( V_51 >= 4 ) {
F_10 ( V_4 , V_68 , * ( T_1 * ) V_64 ) ;
V_64 += 4 ;
V_51 -= 4 ;
}
if ( V_51 )
F_43 ( & V_4 -> V_65 , V_64 , V_51 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
T_2 V_64 [ 4 ] = { 0 } ;
int V_51 ;
if ( F_42 ( & V_4 -> V_65 ) )
return;
V_51 = F_45 ( & V_4 -> V_65 , V_64 , 4 ) ;
F_10 ( V_4 , V_68 , * ( T_1 * ) V_64 ) ;
}
static void F_48 ( struct V_3 * V_4 ,
unsigned char * V_64 , int V_51 )
{
T_2 V_66 [ 4 ] ;
if ( ! F_42 ( & V_4 -> V_65 ) ) {
int V_69 =
F_45 ( & V_4 -> V_65 , V_64 , F_49 ( 4 , V_51 ) ) ;
V_64 += V_69 ;
V_51 -= V_69 ;
if ( ! F_42 ( & V_4 -> V_65 ) )
return;
}
while ( V_51 >= 4 ) {
* ( T_1 * ) V_64 = F_7 ( V_4 , V_68 ) ;
V_64 += 4 ;
V_51 -= 4 ;
}
if ( V_51 ) {
* ( T_1 * ) V_66 = F_7 ( V_4 , V_68 ) ;
F_43 ( & V_4 -> V_65 , V_66 , 4 ) ;
V_51 -= F_45 ( & V_4 -> V_65 , V_64 , V_51 ) ;
}
F_46 ( V_51 ) ;
return;
}
static int F_50 ( struct V_3 * V_4 )
{
unsigned long V_36 ;
bool V_35 = V_4 -> V_41 -> V_1 >= V_70 ;
struct V_71 V_72 ;
F_51 ( & V_4 -> V_65 ) ;
if ( ! V_4 -> V_41 -> V_53 ) {
if ( V_35 ) {
F_41 ( V_4 , V_4 -> V_41 -> V_73 ,
V_4 -> V_41 -> V_74 ) ;
F_47 ( V_4 ) ;
} else
F_48 ( V_4 , V_4 -> V_41 -> V_73 ,
V_4 -> V_41 -> V_74 ) ;
return 0 ;
}
F_52 ( V_36 ) ;
F_53 ( & V_72 , & V_4 -> V_41 -> V_42 , 1 , V_75 |
( V_35 ? V_76 : V_77 ) ) ;
while ( F_54 ( & V_72 ) )
if ( V_35 )
F_41 ( V_4 , V_72 . V_78 , V_72 . V_55 ) ;
else
F_48 ( V_4 , V_72 . V_78 , V_72 . V_55 ) ;
if ( V_35 )
F_47 ( V_4 ) ;
F_55 ( & V_72 ) ;
F_56 ( V_36 ) ;
return 0 ;
}
static void F_57 ( struct V_3 * V_4 )
{
bool V_35 ;
int V_51 , error ;
T_1 V_79 , V_9 ;
if ( ! V_4 -> V_41 ) {
F_27 ( L_15 ) ;
return;
}
V_35 = V_4 -> V_41 -> V_1 >= V_70 ;
V_51 = V_4 -> V_41 -> V_53 ?
V_4 -> V_41 -> V_42 . V_55 : V_4 -> V_41 -> V_74 ;
if ( V_51 > V_58 ) {
F_27 ( L_16 ) ;
error = - V_80 ;
goto V_81;
}
if ( ! ( F_2 ( V_4 , V_31 ) & V_82 ) ) {
F_20 ( L_17 ) ;
error = - V_83 ;
goto V_81;
}
F_20 ( L_18 ,
F_1 ( V_4 -> V_41 -> V_1 ) , V_51 ) ;
if ( V_35 )
F_13 ( V_4 , V_22 , V_84 ) ;
else
F_14 ( V_4 , V_22 , V_84 ) ;
error = F_26 ( V_4 ) ;
if ( error )
goto V_81;
if ( V_35 ) {
error = F_34 ( V_4 ) ;
if ( error == - V_54 )
error = F_50 ( V_4 ) ;
}
if ( error )
goto V_81;
V_9 = ( V_51 << V_85 ) |
( V_4 -> V_41 -> V_1 << V_86 ) |
V_87 ;
F_5 ( V_4 , V_88 , V_9 ) ;
V_79 = V_89 ;
if ( V_4 -> V_41 -> V_90 )
V_79 |= V_91 ;
error = F_15 ( V_4 , V_79 , V_79 ) ;
if ( error ) {
F_27 ( L_19 ) ;
goto V_81;
}
error = F_25 ( V_4 ) ;
if ( error ) {
F_20 ( L_20 ) ;
goto V_81;
}
if ( ! V_35 ) {
error = F_34 ( V_4 ) ;
if ( error == - V_54 )
error = F_50 ( V_4 ) ;
}
if ( V_4 -> V_24 && V_4 -> V_41 -> V_90 ) {
V_4 -> V_41 -> V_92 = 0 ;
V_79 = F_2 ( V_4 , V_13 ) ;
if ( V_79 & V_93 )
V_4 -> V_41 -> V_92 |= V_94 ;
if ( V_79 & V_95 )
V_4 -> V_41 -> V_92 |= V_96 ;
if ( V_79 & V_97 )
V_4 -> V_41 -> V_92 |= V_98 ;
if ( V_79 & V_99 )
V_4 -> V_41 -> V_92 |= V_100 ;
}
if ( error )
F_20 ( L_21 ) ;
V_81:
V_4 -> V_41 -> error = error ;
F_14 ( V_4 , V_31 , V_101 ) ;
return;
}
static int F_58 ( void * V_73 )
{
int error ;
struct V_3 * V_4 = (struct V_3 * ) V_73 ;
unsigned long V_36 ;
while ( ! F_59 () ) {
F_29 ( & V_4 -> V_102 , V_36 ) ;
F_60 ( V_103 ) ;
error = F_61 ( V_4 -> V_104 , & V_4 -> V_41 ) ;
F_31 ( & V_4 -> V_102 , V_36 ) ;
if ( error ) {
if ( error == - V_105 || error == - V_106 ) {
F_35 ( L_22 ) ;
} else {
F_20 ( L_23
L_24 , error ) ;
}
if ( F_59 () )
F_60 ( V_107 ) ;
F_62 () ;
} else {
F_60 ( V_107 ) ;
F_57 ( V_4 ) ;
}
}
return 0 ;
}
static void F_63 ( struct V_3 * V_4 )
{
T_1 V_9 = F_2 ( V_4 , V_31 ) ;
bool V_108 = V_9 & V_82 ;
F_20 ( L_25 , V_108 ?
L_26 : L_27 ) ;
V_9 &= ~ ( ( V_109 | V_110 ) << 16 ) ;
if ( V_108 )
V_9 |= ( V_109 << 16 ) ;
else
V_9 |= ( V_110 << 16 ) ;
F_5 ( V_4 , V_31 , V_9 ) ;
}
static void F_64 ( long unsigned int V_73 )
{
struct V_3 * V_4 = (struct V_3 * ) V_73 ;
F_63 ( V_4 ) ;
F_65 ( V_4 -> V_104 ) ;
}
static T_3 F_66 ( int V_111 , void * V_73 )
{
struct V_3 * V_4 = (struct V_3 * ) V_73 ;
T_3 V_112 = V_113 ;
T_1 V_9 ;
T_4 V_114 , V_115 ;
unsigned long V_36 ;
int error ;
F_29 ( & V_4 -> V_37 , V_36 ) ;
V_9 = F_2 ( V_4 , V_31 ) ;
V_114 = V_9 >> 16 ;
V_115 = V_9 & 0xFFFF ;
V_9 &= ~ V_115 ;
F_5 ( V_4 , V_31 , V_9 ) ;
V_115 &= ( V_114 ) ;
if ( V_115 & ( V_110 | V_109 ) ) {
bool V_116 = V_115 & V_110 ;
V_112 = V_117 ;
F_27 ( L_28 , V_116 ? L_29 : L_30 ) ;
F_67 ( & V_4 -> V_118 ,
V_12 + F_16 ( V_116 ? 500 : 50 ) ) ;
}
if ( V_115 &
( V_119 | V_120 ) ) {
V_112 = V_117 ;
if ( V_115 & V_120 ) {
F_27 ( L_31 ) ;
error = - V_16 ;
} else {
F_35 ( L_32 ) ;
error = 0 ;
}
F_32 ( V_4 , error ) ;
F_68 ( & V_4 -> V_59 ) ;
}
F_31 ( & V_4 -> V_37 , V_36 ) ;
return V_112 ;
}
static int F_69 ( struct V_121 * V_104 ,
enum V_122 V_123 , int V_6 )
{
struct V_3 * V_4 = F_70 ( V_104 ) ;
switch ( V_123 ) {
case V_124 :
switch ( V_6 ) {
case V_125 :
return F_19 ( V_4 , true ) ;
case V_126 :
return F_19 ( V_4 , false ) ;
default:
return - V_54 ;
}
case V_127 :
switch ( V_6 ) {
case V_128 :
return F_22 ( V_4 , 0 ) ;
case V_129 :
return F_22 ( V_4 , 1 ) ;
default:
return - V_54 ;
}
default:
return - V_54 ;
}
}
static void F_71 ( struct V_121 * V_104 )
{
struct V_3 * V_4 = F_70 ( V_104 ) ;
unsigned long V_36 ;
if ( V_4 -> V_41 )
return;
F_29 ( & V_4 -> V_102 , V_36 ) ;
if ( F_72 ( V_4 -> V_130 ) )
F_35 ( L_33 ) ;
F_31 ( & V_4 -> V_102 , V_36 ) ;
}
static int F_73 ( struct V_60 * V_131 , const struct V_132 * V_133 )
{
int error = - V_134 ;
struct V_121 * V_104 ;
struct V_3 * V_4 ;
V_104 = F_74 ( sizeof( struct V_3 ) , & V_131 -> V_4 ) ;
if ( ! V_104 )
goto V_135;
V_4 = F_70 ( V_104 ) ;
V_4 -> V_104 = V_104 ;
V_4 -> V_60 = V_131 ;
F_75 ( V_131 , V_4 ) ;
error = F_76 ( V_131 ) ;
if ( error )
goto V_136;
F_77 ( V_131 ) ;
error = F_78 ( & V_131 -> V_4 , F_79 ( 32 ) ) ;
if ( error )
goto V_137;
error = F_80 ( V_131 , V_138 ) ;
if ( error )
goto V_137;
V_4 -> V_7 = F_81 ( V_131 , 0 ) ;
if ( ! V_4 -> V_7 )
goto V_139;
V_4 -> V_111 = V_131 -> V_111 ;
F_82 ( & V_4 -> V_37 ) ;
F_82 ( & V_4 -> V_102 ) ;
F_83 ( & V_4 -> V_59 ) ;
F_84 ( V_4 -> V_65 ) ;
F_85 ( & V_4 -> V_118 ,
F_64 , ( long unsigned int ) V_4 ) ;
V_104 -> V_140 = V_141 ;
V_104 -> V_142 = F_71 ;
V_104 -> V_143 = F_69 ;
F_33 ( V_4 ) ;
V_4 -> V_130 = F_86 ( F_58 , V_4 , L_34 ) ;
if ( F_87 ( V_4 -> V_130 ) ) {
error = F_88 ( V_4 -> V_130 ) ;
goto V_144;
}
V_4 -> V_145 = F_89 ( & V_131 -> V_4 , V_146 ,
& V_4 -> V_46 , V_147 ) ;
F_32 ( V_4 , 0 ) ;
if ( F_90 ( V_4 -> V_111 , & F_66 , V_148 ,
V_138 , V_4 ) )
goto V_149;
F_63 ( V_4 ) ;
if ( F_91 ( V_104 ) )
goto V_150;
F_27 ( L_35 ) ;
return 0 ;
V_150:
F_92 ( V_4 -> V_111 , V_4 ) ;
V_149:
if ( V_4 -> V_145 )
F_93 ( & V_131 -> V_4 , V_146 , V_4 -> V_145 ,
V_4 -> V_46 ) ;
F_94 ( V_4 -> V_130 ) ;
V_144:
F_95 ( V_4 -> V_7 ) ;
V_139:
F_96 ( V_131 ) ;
V_137:
F_97 ( V_131 ) ;
V_136:
F_98 ( V_104 ) ;
V_135:
return error ;
}
static void F_99 ( struct V_60 * V_131 )
{
int error = 0 ;
struct V_3 * V_4 = F_100 ( V_131 ) ;
F_94 ( V_4 -> V_130 ) ;
F_19 ( V_4 , false ) ;
while ( ! error && V_4 -> V_41 ) {
V_4 -> V_41 -> error = - V_17 ;
error = F_61 ( V_4 -> V_104 , & V_4 -> V_41 ) ;
}
F_101 ( V_4 -> V_104 ) ;
F_92 ( V_4 -> V_111 , V_4 ) ;
F_95 ( V_4 -> V_7 ) ;
F_96 ( V_131 ) ;
F_97 ( V_131 ) ;
F_98 ( V_4 -> V_104 ) ;
if ( V_4 -> V_145 )
F_93 ( & V_131 -> V_4 , V_146 , V_4 -> V_145 ,
V_4 -> V_46 ) ;
}
static int F_102 ( struct V_151 * V_152 )
{
struct V_60 * V_131 = F_103 ( V_152 ) ;
struct V_3 * V_4 = F_100 ( V_131 ) ;
F_24 ( V_4 ) ;
F_104 ( V_4 -> V_104 ) ;
F_105 ( & V_4 -> V_118 ) ;
return 0 ;
}
static int F_106 ( struct V_151 * V_152 )
{
struct V_60 * V_131 = F_103 ( V_152 ) ;
struct V_3 * V_4 = F_100 ( V_131 ) ;
F_24 ( V_4 ) ;
F_19 ( V_4 , false ) ;
F_107 ( V_4 -> V_104 ) ;
F_63 ( V_4 ) ;
return 0 ;
}
