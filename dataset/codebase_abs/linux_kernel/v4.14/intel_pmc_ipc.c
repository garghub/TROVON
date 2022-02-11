static inline void F_1 ( T_1 V_1 )
{
V_2 . V_1 = V_1 ;
if ( V_2 . V_3 ) {
F_2 ( & V_2 . V_4 ) ;
V_1 |= V_5 ;
}
F_3 ( V_1 , V_2 . V_6 + V_7 ) ;
}
static inline T_1 F_4 ( void )
{
return F_5 ( V_2 . V_6 + V_8 ) ;
}
static inline void F_6 ( T_1 V_9 , T_1 V_10 )
{
F_3 ( V_9 , V_2 . V_6 + V_11 + V_10 ) ;
}
static inline T_2 T_3 F_7 ( T_1 V_10 )
{
return F_8 ( V_2 . V_6 + V_12 + V_10 ) ;
}
static inline T_1 F_9 ( T_1 V_10 )
{
return F_5 ( V_2 . V_6 + V_12 + V_10 ) ;
}
static inline T_4 F_10 ( T_1 V_10 )
{
return F_11 ( V_2 . V_13 + V_10 ) ;
}
static inline int F_12 ( T_1 V_10 )
{
if ( ! V_2 . V_14 )
return - V_15 ;
if ( V_10 > V_16 )
return - V_17 ;
return 0 ;
}
int F_13 ( T_1 V_10 , T_1 * V_9 )
{
int V_18 ;
F_14 ( & V_2 . V_19 ) ;
V_18 = F_12 ( V_10 ) ;
if ( V_18 < 0 ) {
F_15 ( & V_2 . V_19 ) ;
return V_18 ;
}
* V_9 = F_5 ( V_2 . V_13 + V_10 ) ;
F_15 ( & V_2 . V_19 ) ;
return 0 ;
}
int F_16 ( T_1 V_10 , T_1 V_9 )
{
int V_18 ;
F_14 ( & V_2 . V_19 ) ;
V_18 = F_12 ( V_10 ) ;
if ( V_18 < 0 ) {
F_15 ( & V_2 . V_19 ) ;
return V_18 ;
}
F_3 ( V_9 , V_2 . V_13 + V_10 ) ;
F_15 ( & V_2 . V_19 ) ;
return 0 ;
}
int F_17 ( T_1 V_10 , T_1 V_20 , T_1 V_21 )
{
T_1 V_22 ;
int V_18 = 0 ;
F_14 ( & V_2 . V_19 ) ;
V_18 = F_12 ( V_10 ) ;
if ( V_18 < 0 )
goto V_23;
V_22 = F_5 ( V_2 . V_13 + V_10 ) ;
V_22 &= ~ V_20 ;
V_22 |= V_21 & V_20 ;
F_3 ( V_22 , V_2 . V_13 + V_10 ) ;
V_22 = F_5 ( V_2 . V_13 + V_10 ) ;
if ( ( V_22 & V_20 ) != ( V_21 & V_20 ) ) {
V_18 = - V_24 ;
goto V_23;
}
V_23:
F_15 ( & V_2 . V_19 ) ;
return V_18 ;
}
static int F_18 ( void * V_25 , bool V_26 )
{
T_1 V_27 = V_26 ? V_28 : V_29 ;
return F_17 ( V_30 ,
V_31 , V_27 ) ;
}
static int F_19 ( void )
{
int V_32 ;
int V_18 = 0 ;
if ( V_2 . V_3 ) {
if ( 0 == F_20 (
& V_2 . V_4 , V_33 * V_34 ) )
V_18 = - V_35 ;
} else {
int V_36 = V_37 ;
while ( ( F_4 () & V_38 ) && -- V_36 )
F_21 ( 1 ) ;
if ( V_36 == 0 )
V_18 = - V_35 ;
}
V_32 = F_4 () ;
if ( V_18 == - V_35 ) {
F_22 ( V_2 . V_39 ,
L_1 ,
V_32 , V_2 . V_1 ) ;
return V_18 ;
}
if ( V_32 & V_40 ) {
int V_41 ;
V_18 = - V_24 ;
V_41 = ( V_32 >> V_42 ) & 0xFF ;
if ( V_41 < F_23 ( V_43 ) )
F_22 ( V_2 . V_39 ,
L_2 ,
V_43 [ V_41 ] , V_32 , V_2 . V_1 ) ;
else
F_22 ( V_2 . V_39 ,
L_3 ,
V_32 , V_2 . V_1 ) ;
if ( ( V_41 == V_44 ) || ( V_41 == V_45 ) )
V_18 = - V_15 ;
}
return V_18 ;
}
int F_24 ( int V_1 , int V_46 )
{
int V_18 ;
F_25 ( & V_47 ) ;
if ( V_2 . V_39 == NULL ) {
F_26 ( & V_47 ) ;
return - V_48 ;
}
F_1 ( V_46 << V_49 | V_1 ) ;
V_18 = F_19 () ;
F_26 ( & V_47 ) ;
return V_18 ;
}
int F_27 ( T_1 V_1 , T_1 V_46 , T_2 * V_50 , T_1 V_51 , T_1 * V_52 ,
T_1 V_53 , T_1 V_54 , T_1 V_55 )
{
T_1 V_56 [ 4 ] = { 0 } ;
int V_18 ;
int V_41 ;
if ( V_51 > V_57 || V_53 > V_57 / 4 )
return - V_17 ;
F_25 ( & V_47 ) ;
if ( V_2 . V_39 == NULL ) {
F_26 ( & V_47 ) ;
return - V_48 ;
}
memcpy ( V_56 , V_50 , V_51 ) ;
F_3 ( V_54 , V_2 . V_6 + V_58 ) ;
F_3 ( V_55 , V_2 . V_6 + V_59 ) ;
for ( V_41 = 0 ; V_41 < ( ( V_51 + 3 ) / 4 ) ; V_41 ++ )
F_6 ( V_56 [ V_41 ] , 4 * V_41 ) ;
F_1 ( ( V_51 << V_42 ) |
( V_46 << V_49 ) | V_1 ) ;
V_18 = F_19 () ;
if ( ! V_18 ) {
for ( V_41 = 0 ; V_41 < V_53 ; V_41 ++ )
* V_52 ++ = F_9 ( 4 * V_41 ) ;
}
F_26 ( & V_47 ) ;
return V_18 ;
}
int F_28 ( T_1 V_1 , T_1 V_46 , T_2 * V_50 , T_1 V_51 ,
T_1 * V_52 , T_1 V_53 )
{
return F_27 ( V_1 , V_46 , V_50 , V_51 , V_52 , V_53 , 0 , 0 ) ;
}
static T_5 F_29 ( int V_60 , void * V_61 )
{
int V_32 ;
if ( V_2 . V_3 ) {
V_32 = F_4 () ;
F_3 ( V_32 | V_62 , V_2 . V_6 + V_8 ) ;
}
F_30 ( & V_2 . V_4 ) ;
return V_63 ;
}
static int F_31 ( struct V_64 * V_65 , const struct V_66 * V_67 )
{
struct V_68 * V_69 = & V_2 ;
int V_18 ;
if ( V_69 -> V_39 )
return - V_70 ;
V_69 -> V_3 = V_71 ;
F_32 ( & V_2 . V_19 ) ;
V_18 = F_33 ( V_65 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_34 ( V_65 , 1 << 0 , F_35 ( V_65 ) ) ;
if ( V_18 )
return V_18 ;
F_36 ( & V_69 -> V_4 ) ;
V_69 -> V_6 = F_37 ( V_65 ) [ 0 ] ;
V_18 = F_38 ( & V_65 -> V_39 , V_65 -> V_60 , F_29 , 0 , L_4 ,
V_69 ) ;
if ( V_18 ) {
F_22 ( & V_65 -> V_39 , L_5 ) ;
return V_18 ;
}
V_69 -> V_39 = & V_65 -> V_39 ;
F_39 ( V_65 , V_69 ) ;
return 0 ;
}
static T_6 F_40 ( struct V_72 * V_39 ,
struct V_73 * V_74 ,
const char * V_75 , T_7 V_76 )
{
int V_77 ;
int V_1 ;
int V_18 ;
V_18 = sscanf ( V_75 , L_6 , & V_1 , & V_77 ) ;
if ( V_18 != 2 ) {
F_22 ( V_39 , L_7 ) ;
return - V_17 ;
}
V_18 = F_24 ( V_1 , V_77 ) ;
if ( V_18 ) {
F_22 ( V_39 , L_8 , V_1 , V_18 ) ;
return V_18 ;
}
return ( T_6 ) V_76 ;
}
static T_6 F_41 ( struct V_72 * V_39 ,
struct V_73 * V_74 ,
const char * V_75 , T_7 V_76 )
{
unsigned long V_21 ;
int V_77 ;
int V_18 ;
if ( F_42 ( V_75 , 0 , & V_21 ) )
return - V_17 ;
if ( V_21 )
V_77 = 1 ;
else
V_77 = 0 ;
V_18 = F_24 ( V_78 , V_77 ) ;
if ( V_18 ) {
F_22 ( V_39 , L_9 , V_77 , V_18 ) ;
return V_18 ;
}
return ( T_6 ) V_76 ;
}
static int F_43 ( void )
{
struct V_79 * V_65 ;
const struct V_80 V_81 = {
. V_82 = V_2 . V_39 ,
. V_83 = V_84 ,
. V_67 = - 1 ,
. V_85 = V_86 ,
. V_87 = F_23 ( V_86 ) ,
} ;
V_65 = F_44 ( & V_81 ) ;
if ( F_45 ( V_65 ) )
return F_46 ( V_65 ) ;
V_2 . V_88 = V_65 ;
return 0 ;
}
static int F_47 ( void )
{
struct V_79 * V_65 ;
struct V_89 * V_85 ;
const struct V_80 V_81 = {
. V_82 = V_2 . V_39 ,
. V_83 = V_90 ,
. V_67 = - 1 ,
. V_85 = V_91 ,
. V_87 = F_23 ( V_91 ) ,
. V_9 = & V_92 ,
. V_93 = sizeof( V_92 ) ,
} ;
V_85 = V_91 + V_94 ;
V_85 -> V_95 = V_2 . V_96 + V_97 ;
V_85 -> V_98 = V_85 -> V_95 + V_99 - 1 ;
V_85 = V_91 + V_100 ;
V_85 -> V_95 = V_2 . V_96 + V_101 ;
V_85 -> V_98 = V_85 -> V_95 + V_102 - 1 ;
V_65 = F_44 ( & V_81 ) ;
if ( F_45 ( V_65 ) )
return F_46 ( V_65 ) ;
V_2 . V_103 = V_65 ;
return 0 ;
}
static int F_48 ( void )
{
struct V_79 * V_65 ;
struct V_89 * V_85 ;
const struct V_80 V_81 = {
. V_82 = V_2 . V_39 ,
. V_83 = V_104 ,
. V_67 = - 1 ,
. V_85 = V_105 ,
. V_87 = F_23 ( V_105 ) ,
} ;
V_85 = V_105 + V_106 ;
V_85 -> V_95 = V_2 . V_107 ;
V_85 -> V_98 = V_85 -> V_95 + V_2 . V_108 - 1 ;
V_85 = V_105 + V_109 ;
V_85 -> V_95 = V_2 . V_110 ;
V_85 -> V_98 = V_85 -> V_95 + V_2 . V_111 - 1 ;
V_65 = F_44 ( & V_81 ) ;
if ( F_45 ( V_65 ) )
return F_46 ( V_65 ) ;
V_2 . V_112 = V_65 ;
return 0 ;
}
static int F_49 ( void )
{
int V_18 ;
if ( ! F_50 () ) {
V_18 = F_47 () ;
if ( V_18 ) {
F_22 ( V_2 . V_39 , L_10 ) ;
return V_18 ;
}
}
V_18 = F_43 () ;
if ( V_18 ) {
F_22 ( V_2 . V_39 , L_11 ) ;
F_51 ( V_2 . V_103 ) ;
}
if ( ! V_2 . V_113 ) {
V_18 = F_48 () ;
if ( V_18 )
F_52 ( V_2 . V_39 ,
L_12 ) ;
}
return V_18 ;
}
static int F_53 ( struct V_79 * V_65 )
{
struct V_89 * V_85 , * V_114 ;
void T_8 * V_115 ;
int V_116 ;
V_85 = F_54 ( V_65 , V_117 ,
V_118 ) ;
if ( ! V_85 ) {
F_22 ( & V_65 -> V_39 , L_13 ) ;
return - V_119 ;
}
V_116 = F_55 ( V_85 ) ;
V_2 . V_96 = V_85 -> V_95 ;
V_2 . V_120 = V_116 ;
F_56 ( & V_65 -> V_39 , L_14 , V_85 ) ;
V_114 = V_86 ;
V_85 = F_54 ( V_65 , V_121 ,
V_122 ) ;
if ( ! V_85 ) {
F_22 ( & V_65 -> V_39 , L_15 ) ;
return - V_119 ;
}
* V_114 = * V_85 ;
F_56 ( & V_65 -> V_39 , L_16 , V_85 ) ;
V_85 = F_54 ( V_65 , V_121 ,
V_123 ) ;
if ( ! V_85 ) {
F_22 ( & V_65 -> V_39 , L_17 ) ;
return - V_119 ;
}
* ++ V_114 = * V_85 ;
F_56 ( & V_65 -> V_39 , L_18 , V_85 ) ;
V_85 = F_54 ( V_65 , V_121 ,
V_124 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_56 ( & V_65 -> V_39 , L_19 , V_85 ) ;
}
V_85 = F_54 ( V_65 , V_121 ,
V_125 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_56 ( & V_65 -> V_39 , L_20 , V_85 ) ;
}
V_85 = F_54 ( V_65 , V_121 ,
V_126 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_56 ( & V_65 -> V_39 , L_21 , V_85 ) ;
}
V_85 = F_54 ( V_65 , V_121 ,
V_127 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_56 ( & V_65 -> V_39 , L_22 , V_85 ) ;
}
V_85 = F_54 ( V_65 , V_121 ,
V_128 ) ;
if ( ! V_85 ) {
F_22 ( & V_65 -> V_39 , L_23 ) ;
return - V_119 ;
}
V_116 = V_129 + V_16 ;
V_85 -> V_98 = V_85 -> V_95 + V_116 - 1 ;
V_115 = F_57 ( & V_65 -> V_39 , V_85 ) ;
if ( F_45 ( V_115 ) )
return F_46 ( V_115 ) ;
V_2 . V_6 = V_115 ;
V_2 . V_13 = V_115 + V_130 ;
F_56 ( & V_65 -> V_39 , L_24 , V_85 ) ;
V_2 . V_113 = 0 ;
V_85 = F_54 ( V_65 , V_121 ,
V_131 ) ;
if ( ! V_85 ) {
F_22 ( & V_65 -> V_39 , L_25 ) ;
V_2 . V_113 = 1 ;
} else {
V_2 . V_107 = V_85 -> V_95 +
V_132 ;
V_2 . V_108 = V_133 ;
V_2 . V_110 = V_85 -> V_95 +
V_134 ;
V_2 . V_111 = V_133 ;
F_56 ( & V_65 -> V_39 , L_26 , V_85 ) ;
}
return 0 ;
}
int F_58 ( T_4 * V_9 )
{
T_4 V_135 , V_136 ;
if ( ! V_2 . V_14 )
return - V_15 ;
V_135 = F_10 ( V_137 ) ;
V_136 = F_10 ( V_138 ) ;
* V_9 = F_59 ( V_135 , V_136 ) ;
return 0 ;
}
static int F_60 ( struct V_79 * V_65 )
{
int V_18 ;
V_2 . V_39 = & V_65 -> V_39 ;
V_2 . V_3 = V_71 ;
F_36 ( & V_2 . V_4 ) ;
F_32 ( & V_2 . V_19 ) ;
V_2 . V_60 = F_61 ( V_65 , 0 ) ;
if ( V_2 . V_60 < 0 ) {
F_22 ( & V_65 -> V_39 , L_27 ) ;
return - V_17 ;
}
V_18 = F_53 ( V_65 ) ;
if ( V_18 ) {
F_22 ( & V_65 -> V_39 , L_28 ) ;
return V_18 ;
}
V_18 = F_49 () ;
if ( V_18 ) {
F_22 ( & V_65 -> V_39 , L_29 ) ;
return V_18 ;
}
if ( F_38 ( & V_65 -> V_39 , V_2 . V_60 , F_29 , V_139 ,
L_4 , & V_2 ) ) {
F_22 ( & V_65 -> V_39 , L_5 ) ;
V_18 = - V_70 ;
goto V_140;
}
V_18 = F_62 ( & V_65 -> V_39 . V_141 , & V_142 ) ;
if ( V_18 ) {
F_22 ( & V_65 -> V_39 , L_30 ,
V_18 ) ;
goto V_143;
}
V_2 . V_14 = true ;
return 0 ;
V_143:
F_63 ( & V_65 -> V_39 , V_2 . V_60 , & V_2 ) ;
V_140:
F_51 ( V_2 . V_103 ) ;
F_51 ( V_2 . V_88 ) ;
F_51 ( V_2 . V_112 ) ;
return V_18 ;
}
static int F_64 ( struct V_79 * V_65 )
{
F_65 ( & V_65 -> V_39 . V_141 , & V_142 ) ;
F_63 ( & V_65 -> V_39 , V_2 . V_60 , & V_2 ) ;
F_51 ( V_2 . V_103 ) ;
F_51 ( V_2 . V_88 ) ;
F_51 ( V_2 . V_112 ) ;
V_2 . V_39 = NULL ;
return 0 ;
}
static int T_9 F_66 ( void )
{
int V_18 ;
V_18 = F_67 ( & V_144 ) ;
if ( V_18 ) {
F_68 ( L_31 ) ;
return V_18 ;
}
V_18 = F_69 ( & V_145 ) ;
if ( V_18 ) {
F_68 ( L_32 ) ;
F_70 ( & V_144 ) ;
return V_18 ;
}
return V_18 ;
}
static void T_10 F_71 ( void )
{
F_72 ( & V_145 ) ;
F_70 ( & V_144 ) ;
}
