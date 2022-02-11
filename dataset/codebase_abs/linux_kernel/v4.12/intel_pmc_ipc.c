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
static inline T_2 F_7 ( T_1 V_10 )
{
return F_8 ( V_2 . V_6 + V_12 + V_10 ) ;
}
static inline T_1 F_9 ( T_1 V_10 )
{
return F_5 ( V_2 . V_6 + V_12 + V_10 ) ;
}
static inline T_3 F_10 ( T_1 V_10 )
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
F_14 ( & V_19 ) ;
V_18 = F_12 ( V_10 ) ;
if ( V_18 < 0 ) {
F_15 ( & V_19 ) ;
return V_18 ;
}
* V_9 = F_5 ( V_2 . V_13 + V_10 ) ;
F_15 ( & V_19 ) ;
return 0 ;
}
int F_16 ( T_1 V_10 , T_1 V_9 )
{
int V_18 ;
F_14 ( & V_19 ) ;
V_18 = F_12 ( V_10 ) ;
if ( V_18 < 0 ) {
F_15 ( & V_19 ) ;
return V_18 ;
}
F_3 ( V_9 , V_2 . V_13 + V_10 ) ;
F_15 ( & V_19 ) ;
return 0 ;
}
int F_17 ( T_1 V_10 , T_1 V_20 , T_1 V_21 )
{
T_1 V_22 ;
int V_18 = 0 ;
F_14 ( & V_19 ) ;
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
F_15 ( & V_19 ) ;
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
F_14 ( & V_19 ) ;
if ( V_2 . V_39 == NULL ) {
F_15 ( & V_19 ) ;
return - V_47 ;
}
F_1 ( V_46 << V_48 | V_1 ) ;
V_18 = F_19 () ;
F_15 ( & V_19 ) ;
return V_18 ;
}
int F_25 ( T_1 V_1 , T_1 V_46 , T_2 * V_49 , T_1 V_50 , T_1 * V_51 ,
T_1 V_52 , T_1 V_53 , T_1 V_54 )
{
T_1 V_55 [ 4 ] = { 0 } ;
int V_18 ;
int V_41 ;
if ( V_50 > V_56 || V_52 > V_56 / 4 )
return - V_17 ;
F_14 ( & V_19 ) ;
if ( V_2 . V_39 == NULL ) {
F_15 ( & V_19 ) ;
return - V_47 ;
}
memcpy ( V_55 , V_49 , V_50 ) ;
F_3 ( V_53 , V_2 . V_6 + V_57 ) ;
F_3 ( V_54 , V_2 . V_6 + V_58 ) ;
for ( V_41 = 0 ; V_41 < ( ( V_50 + 3 ) / 4 ) ; V_41 ++ )
F_6 ( V_55 [ V_41 ] , 4 * V_41 ) ;
F_1 ( ( V_50 << V_42 ) |
( V_46 << V_48 ) | V_1 ) ;
V_18 = F_19 () ;
if ( ! V_18 ) {
for ( V_41 = 0 ; V_41 < V_52 ; V_41 ++ )
* V_51 ++ = F_9 ( 4 * V_41 ) ;
}
F_15 ( & V_19 ) ;
return V_18 ;
}
int F_26 ( T_1 V_1 , T_1 V_46 , T_2 * V_49 , T_1 V_50 ,
T_1 * V_51 , T_1 V_52 )
{
return F_25 ( V_1 , V_46 , V_49 , V_50 , V_51 , V_52 , 0 , 0 ) ;
}
static T_4 F_27 ( int V_59 , void * V_60 )
{
int V_32 ;
if ( V_2 . V_3 ) {
V_32 = F_4 () ;
F_3 ( V_32 | V_61 , V_2 . V_6 + V_8 ) ;
}
F_28 ( & V_2 . V_4 ) ;
return V_62 ;
}
static int F_29 ( struct V_63 * V_64 , const struct V_65 * V_66 )
{
T_5 V_67 ;
int V_18 ;
int V_68 ;
V_2 . V_39 = & F_30 ( V_64 ) -> V_39 ;
V_2 . V_3 = V_69 ;
V_18 = F_31 ( V_64 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_32 ( V_64 , L_4 ) ;
if ( V_18 )
return V_18 ;
V_67 = F_33 ( V_64 , 0 ) ;
V_68 = F_34 ( V_64 , 0 ) ;
if ( ! V_67 || ! V_68 ) {
F_22 ( & V_64 -> V_39 , L_5 ) ;
return - V_70 ;
}
F_35 ( & V_2 . V_4 ) ;
if ( F_36 ( V_64 -> V_59 , F_27 , 0 , L_4 , & V_2 ) ) {
F_22 ( & V_64 -> V_39 , L_6 ) ;
return - V_71 ;
}
V_2 . V_6 = F_37 ( V_67 , V_68 ) ;
if ( ! V_2 . V_6 ) {
F_22 ( & V_64 -> V_39 , L_7 ) ;
F_38 ( V_64 -> V_59 , & V_2 ) ;
V_18 = - V_70 ;
}
return V_18 ;
}
static void F_39 ( struct V_63 * V_64 )
{
F_38 ( V_64 -> V_59 , & V_2 ) ;
F_40 ( V_64 ) ;
F_41 ( V_64 ) ;
F_42 ( V_2 . V_6 ) ;
V_2 . V_39 = NULL ;
}
static T_6 F_43 ( struct V_72 * V_39 ,
struct V_73 * V_74 ,
const char * V_75 , T_7 V_76 )
{
int V_77 ;
int V_1 ;
int V_18 ;
V_18 = sscanf ( V_75 , L_8 , & V_1 , & V_77 ) ;
if ( V_18 != 2 ) {
F_22 ( V_39 , L_9 ) ;
return - V_17 ;
}
V_18 = F_24 ( V_1 , V_77 ) ;
if ( V_18 ) {
F_22 ( V_39 , L_10 , V_1 , V_18 ) ;
return V_18 ;
}
return ( T_6 ) V_76 ;
}
static T_6 F_44 ( struct V_72 * V_39 ,
struct V_73 * V_74 ,
const char * V_75 , T_7 V_76 )
{
unsigned long V_21 ;
int V_77 ;
int V_18 ;
if ( F_45 ( V_75 , 0 , & V_21 ) )
return - V_17 ;
if ( V_21 )
V_77 = 1 ;
else
V_77 = 0 ;
V_18 = F_24 ( V_78 , V_77 ) ;
if ( V_18 ) {
F_22 ( V_39 , L_11 , V_77 , V_18 ) ;
return V_18 ;
}
return ( T_6 ) V_76 ;
}
static int F_46 ( void )
{
struct V_79 * V_64 ;
const struct V_80 V_81 = {
. V_82 = V_2 . V_39 ,
. V_83 = V_84 ,
. V_66 = - 1 ,
. V_85 = V_86 ,
. V_87 = F_23 ( V_86 ) ,
} ;
V_64 = F_47 ( & V_81 ) ;
if ( F_48 ( V_64 ) )
return F_49 ( V_64 ) ;
V_2 . V_88 = V_64 ;
return 0 ;
}
static int F_50 ( void )
{
struct V_79 * V_64 ;
struct V_89 * V_85 ;
const struct V_80 V_81 = {
. V_82 = V_2 . V_39 ,
. V_83 = V_90 ,
. V_66 = - 1 ,
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
V_64 = F_47 ( & V_81 ) ;
if ( F_48 ( V_64 ) )
return F_49 ( V_64 ) ;
V_2 . V_103 = V_64 ;
return 0 ;
}
static int F_51 ( void )
{
struct V_79 * V_64 ;
struct V_89 * V_85 ;
const struct V_80 V_81 = {
. V_82 = V_2 . V_39 ,
. V_83 = V_104 ,
. V_66 = - 1 ,
. V_85 = V_105 ,
. V_87 = F_23 ( V_105 ) ,
} ;
V_85 = V_105 + V_106 ;
V_85 -> V_95 = V_2 . V_107 ;
V_85 -> V_98 = V_85 -> V_95 + V_2 . V_108 - 1 ;
V_85 = V_105 + V_109 ;
V_85 -> V_95 = V_2 . V_110 ;
V_85 -> V_98 = V_85 -> V_95 + V_2 . V_111 - 1 ;
V_64 = F_47 ( & V_81 ) ;
if ( F_48 ( V_64 ) )
return F_49 ( V_64 ) ;
V_2 . V_112 = V_64 ;
return 0 ;
}
static int F_52 ( void )
{
int V_18 ;
if ( ! F_53 () ) {
V_18 = F_50 () ;
if ( V_18 ) {
F_22 ( V_2 . V_39 , L_12 ) ;
return V_18 ;
}
}
V_18 = F_46 () ;
if ( V_18 ) {
F_22 ( V_2 . V_39 , L_13 ) ;
F_54 ( V_2 . V_103 ) ;
}
if ( ! V_2 . V_113 ) {
V_18 = F_51 () ;
if ( V_18 )
F_55 ( V_2 . V_39 ,
L_14 ) ;
}
return V_18 ;
}
static int F_56 ( struct V_79 * V_64 )
{
struct V_89 * V_85 , * V_114 ;
void T_8 * V_115 ;
int V_116 ;
V_85 = F_57 ( V_64 , V_117 ,
V_118 ) ;
if ( ! V_85 ) {
F_22 ( & V_64 -> V_39 , L_15 ) ;
return - V_119 ;
}
V_116 = F_58 ( V_85 ) ;
V_2 . V_96 = V_85 -> V_95 ;
V_2 . V_120 = V_116 ;
F_59 ( & V_64 -> V_39 , L_16 , V_85 ) ;
V_114 = V_86 ;
V_85 = F_57 ( V_64 , V_121 ,
V_122 ) ;
if ( ! V_85 ) {
F_22 ( & V_64 -> V_39 , L_17 ) ;
return - V_119 ;
}
* V_114 = * V_85 ;
F_59 ( & V_64 -> V_39 , L_18 , V_85 ) ;
V_85 = F_57 ( V_64 , V_121 ,
V_123 ) ;
if ( ! V_85 ) {
F_22 ( & V_64 -> V_39 , L_19 ) ;
return - V_119 ;
}
* ++ V_114 = * V_85 ;
F_59 ( & V_64 -> V_39 , L_20 , V_85 ) ;
V_85 = F_57 ( V_64 , V_121 ,
V_124 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_59 ( & V_64 -> V_39 , L_21 , V_85 ) ;
}
V_85 = F_57 ( V_64 , V_121 ,
V_125 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_59 ( & V_64 -> V_39 , L_22 , V_85 ) ;
}
V_85 = F_57 ( V_64 , V_121 ,
V_126 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_59 ( & V_64 -> V_39 , L_23 , V_85 ) ;
}
V_85 = F_57 ( V_64 , V_121 ,
V_127 ) ;
++ V_114 ;
if ( V_85 ) {
* V_114 = * V_85 ;
F_59 ( & V_64 -> V_39 , L_24 , V_85 ) ;
}
V_85 = F_57 ( V_64 , V_121 ,
V_128 ) ;
if ( ! V_85 ) {
F_22 ( & V_64 -> V_39 , L_25 ) ;
return - V_119 ;
}
V_116 = V_129 + V_16 ;
if ( ! F_60 ( V_85 -> V_95 , V_116 , V_64 -> V_83 ) ) {
F_22 ( & V_64 -> V_39 , L_26 ) ;
return - V_71 ;
}
V_115 = F_37 ( V_85 -> V_95 , V_116 ) ;
if ( ! V_115 ) {
F_22 ( & V_64 -> V_39 , L_27 ) ;
F_61 ( V_85 -> V_95 , V_116 ) ;
return - V_70 ;
}
V_2 . V_6 = V_115 ;
V_2 . V_13 = V_115 + V_130 ;
F_59 ( & V_64 -> V_39 , L_28 , V_85 ) ;
V_2 . V_113 = 0 ;
V_85 = F_57 ( V_64 , V_121 ,
V_131 ) ;
if ( ! V_85 ) {
F_22 ( & V_64 -> V_39 , L_29 ) ;
V_2 . V_113 = 1 ;
} else {
V_2 . V_107 = V_85 -> V_95 +
V_132 ;
V_2 . V_108 = V_133 ;
V_2 . V_110 = V_85 -> V_95 +
V_134 ;
V_2 . V_111 = V_133 ;
F_59 ( & V_64 -> V_39 , L_30 , V_85 ) ;
}
return 0 ;
}
int F_62 ( T_3 * V_9 )
{
T_3 V_135 , V_136 ;
if ( ! V_2 . V_14 )
return - V_15 ;
V_135 = F_10 ( V_137 ) ;
V_136 = F_10 ( V_138 ) ;
* V_9 = F_63 ( V_135 , V_136 ) ;
return 0 ;
}
static int F_64 ( struct V_79 * V_64 )
{
struct V_89 * V_85 ;
int V_18 ;
V_2 . V_39 = & V_64 -> V_39 ;
V_2 . V_3 = V_69 ;
F_35 ( & V_2 . V_4 ) ;
V_2 . V_59 = F_65 ( V_64 , 0 ) ;
if ( V_2 . V_59 < 0 ) {
F_22 ( & V_64 -> V_39 , L_31 ) ;
return - V_17 ;
}
V_18 = F_56 ( V_64 ) ;
if ( V_18 ) {
F_22 ( & V_64 -> V_39 , L_32 ) ;
return V_18 ;
}
V_18 = F_52 () ;
if ( V_18 ) {
F_22 ( & V_64 -> V_39 , L_33 ) ;
goto V_139;
}
if ( F_36 ( V_2 . V_59 , F_27 , V_140 ,
L_4 , & V_2 ) ) {
F_22 ( & V_64 -> V_39 , L_6 ) ;
V_18 = - V_71 ;
goto V_141;
}
V_18 = F_66 ( & V_64 -> V_39 . V_142 , & V_143 ) ;
if ( V_18 ) {
F_22 ( & V_64 -> V_39 , L_34 ,
V_18 ) ;
goto V_144;
}
V_2 . V_14 = true ;
return 0 ;
V_144:
F_38 ( V_2 . V_59 , & V_2 ) ;
V_141:
F_54 ( V_2 . V_103 ) ;
F_54 ( V_2 . V_88 ) ;
F_54 ( V_2 . V_112 ) ;
V_139:
F_42 ( V_2 . V_6 ) ;
V_85 = F_57 ( V_64 , V_121 ,
V_128 ) ;
if ( V_85 ) {
F_61 ( V_85 -> V_95 ,
V_129 +
V_16 ) ;
}
return V_18 ;
}
static int F_67 ( struct V_79 * V_64 )
{
struct V_89 * V_85 ;
F_68 ( & V_64 -> V_39 . V_142 , & V_143 ) ;
F_38 ( V_2 . V_59 , & V_2 ) ;
F_54 ( V_2 . V_103 ) ;
F_54 ( V_2 . V_88 ) ;
F_54 ( V_2 . V_112 ) ;
F_42 ( V_2 . V_6 ) ;
V_85 = F_57 ( V_64 , V_121 ,
V_128 ) ;
if ( V_85 ) {
F_61 ( V_85 -> V_95 ,
V_129 +
V_16 ) ;
}
V_2 . V_39 = NULL ;
return 0 ;
}
static int T_9 F_69 ( void )
{
int V_18 ;
V_18 = F_70 ( & V_145 ) ;
if ( V_18 ) {
F_71 ( L_35 ) ;
return V_18 ;
}
V_18 = F_72 ( & V_146 ) ;
if ( V_18 ) {
F_71 ( L_36 ) ;
F_73 ( & V_145 ) ;
return V_18 ;
}
return V_18 ;
}
static void T_10 F_74 ( void )
{
F_75 ( & V_146 ) ;
F_73 ( & V_145 ) ;
}
