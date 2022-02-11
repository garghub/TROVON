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
static int F_10 ( void )
{
int V_13 ;
int V_14 = 0 ;
if ( V_2 . V_3 ) {
if ( 0 == F_11 (
& V_2 . V_4 , V_15 * V_16 ) )
V_14 = - V_17 ;
} else {
int V_18 = V_19 ;
while ( ( F_4 () & V_20 ) && -- V_18 )
F_12 ( 1 ) ;
if ( V_18 == 0 )
V_14 = - V_17 ;
}
V_13 = F_4 () ;
if ( V_14 == - V_17 ) {
F_13 ( V_2 . V_21 ,
L_1 ,
V_13 , V_2 . V_1 ) ;
return V_14 ;
}
if ( V_13 & V_22 ) {
int V_23 ;
V_14 = - V_24 ;
V_23 = ( V_13 >> V_25 ) & 0xFF ;
if ( V_23 < F_14 ( V_26 ) )
F_13 ( V_2 . V_21 ,
L_2 ,
V_26 [ V_23 ] , V_13 , V_2 . V_1 ) ;
else
F_13 ( V_2 . V_21 ,
L_3 ,
V_13 , V_2 . V_1 ) ;
if ( ( V_23 == V_27 ) || ( V_23 == V_28 ) )
V_14 = - V_29 ;
}
return V_14 ;
}
int F_15 ( int V_1 , int V_30 )
{
int V_14 ;
F_16 ( & V_31 ) ;
if ( V_2 . V_21 == NULL ) {
F_17 ( & V_31 ) ;
return - V_32 ;
}
F_1 ( V_30 << V_33 | V_1 ) ;
V_14 = F_10 () ;
F_17 ( & V_31 ) ;
return V_14 ;
}
int F_18 ( T_1 V_1 , T_1 V_30 , T_2 * V_34 , T_1 V_35 , T_1 * V_36 ,
T_1 V_37 , T_1 V_38 , T_1 V_39 )
{
T_1 V_40 [ 4 ] = { 0 } ;
int V_14 ;
int V_23 ;
if ( V_35 > V_41 || V_37 > V_41 / 4 )
return - V_42 ;
F_16 ( & V_31 ) ;
if ( V_2 . V_21 == NULL ) {
F_17 ( & V_31 ) ;
return - V_32 ;
}
memcpy ( V_40 , V_34 , V_35 ) ;
F_3 ( V_38 , V_2 . V_6 + V_43 ) ;
F_3 ( V_39 , V_2 . V_6 + V_44 ) ;
for ( V_23 = 0 ; V_23 < ( ( V_35 + 3 ) / 4 ) ; V_23 ++ )
F_6 ( V_40 [ V_23 ] , 4 * V_23 ) ;
F_1 ( ( V_35 << V_25 ) |
( V_30 << V_33 ) | V_1 ) ;
V_14 = F_10 () ;
if ( ! V_14 ) {
for ( V_23 = 0 ; V_23 < V_37 ; V_23 ++ )
* V_36 ++ = F_9 ( 4 * V_23 ) ;
}
F_17 ( & V_31 ) ;
return V_14 ;
}
int F_19 ( T_1 V_1 , T_1 V_30 , T_2 * V_34 , T_1 V_35 ,
T_1 * V_36 , T_1 V_37 )
{
return F_18 ( V_1 , V_30 , V_34 , V_35 , V_36 , V_37 , 0 , 0 ) ;
}
static T_3 F_20 ( int V_45 , void * V_46 )
{
int V_13 ;
if ( V_2 . V_3 ) {
V_13 = F_4 () ;
F_3 ( V_13 | V_47 , V_2 . V_6 + V_8 ) ;
}
F_21 ( & V_2 . V_4 ) ;
return V_48 ;
}
static int F_22 ( struct V_49 * V_50 , const struct V_51 * V_52 )
{
T_4 V_53 ;
int V_14 ;
int V_54 ;
V_2 . V_21 = & F_23 ( V_50 ) -> V_21 ;
V_2 . V_3 = V_55 ;
V_14 = F_24 ( V_50 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_25 ( V_50 , L_4 ) ;
if ( V_14 )
return V_14 ;
V_53 = F_26 ( V_50 , 0 ) ;
V_54 = F_27 ( V_50 , 0 ) ;
if ( ! V_53 || ! V_54 ) {
F_13 ( & V_50 -> V_21 , L_5 ) ;
return - V_56 ;
}
F_28 ( & V_2 . V_4 ) ;
if ( F_29 ( V_50 -> V_45 , F_20 , 0 , L_4 , & V_2 ) ) {
F_13 ( & V_50 -> V_21 , L_6 ) ;
return - V_57 ;
}
V_2 . V_6 = F_30 ( V_53 , V_54 ) ;
if ( ! V_2 . V_6 ) {
F_13 ( & V_50 -> V_21 , L_7 ) ;
F_31 ( V_50 -> V_45 , & V_2 ) ;
V_14 = - V_56 ;
}
return V_14 ;
}
static void F_32 ( struct V_49 * V_50 )
{
F_31 ( V_50 -> V_45 , & V_2 ) ;
F_33 ( V_50 ) ;
F_34 ( V_50 ) ;
F_35 ( V_2 . V_6 ) ;
V_2 . V_21 = NULL ;
}
static T_5 F_36 ( struct V_58 * V_21 ,
struct V_59 * V_60 ,
const char * V_61 , T_6 V_62 )
{
int V_63 ;
int V_1 ;
int V_14 ;
V_14 = sscanf ( V_61 , L_8 , & V_1 , & V_63 ) ;
if ( V_14 != 2 ) {
F_13 ( V_21 , L_9 ) ;
return - V_42 ;
}
V_14 = F_15 ( V_1 , V_63 ) ;
if ( V_14 ) {
F_13 ( V_21 , L_10 , V_1 , V_14 ) ;
return V_14 ;
}
return ( T_5 ) V_62 ;
}
static T_5 F_37 ( struct V_58 * V_21 ,
struct V_59 * V_60 ,
const char * V_61 , T_6 V_62 )
{
unsigned long V_64 ;
int V_63 ;
int V_14 ;
if ( F_38 ( V_61 , 0 , & V_64 ) )
return - V_42 ;
if ( V_64 )
V_63 = 1 ;
else
V_63 = 0 ;
V_14 = F_15 ( V_65 , V_63 ) ;
if ( V_14 ) {
F_13 ( V_21 , L_11 , V_63 , V_14 ) ;
return V_14 ;
}
return ( T_5 ) V_62 ;
}
static int F_39 ( void )
{
struct V_66 * V_50 ;
const struct V_67 V_68 = {
. V_69 = V_2 . V_21 ,
. V_70 = V_71 ,
. V_52 = - 1 ,
. V_72 = V_73 ,
. V_74 = F_14 ( V_73 ) ,
} ;
V_50 = F_40 ( & V_68 ) ;
if ( F_41 ( V_50 ) )
return F_42 ( V_50 ) ;
V_2 . V_75 = V_50 ;
return 0 ;
}
static int F_43 ( void )
{
struct V_66 * V_50 ;
struct V_76 * V_72 ;
const struct V_67 V_68 = {
. V_69 = V_2 . V_21 ,
. V_70 = V_77 ,
. V_52 = - 1 ,
. V_72 = V_78 ,
. V_74 = F_14 ( V_78 ) ,
. V_9 = & V_79 ,
. V_80 = sizeof( V_79 ) ,
} ;
V_72 = V_78 + V_81 ;
V_72 -> V_82 = V_2 . V_83 + V_84 ;
V_72 -> V_85 = V_72 -> V_82 + V_86 - 1 ;
V_72 = V_78 + V_87 ;
V_72 -> V_82 = V_2 . V_83 + V_88 ;
V_72 -> V_85 = V_72 -> V_82 + V_89 - 1 ;
V_72 = V_78 + V_90 ;
V_72 -> V_82 = V_2 . V_91 + V_92 ;
V_72 -> V_85 = V_72 -> V_82 + V_93 - 1 ;
V_50 = F_40 ( & V_68 ) ;
if ( F_41 ( V_50 ) )
return F_42 ( V_50 ) ;
V_2 . V_94 = V_50 ;
return 0 ;
}
static int F_44 ( void )
{
struct V_66 * V_50 ;
struct V_76 * V_72 ;
const struct V_67 V_68 = {
. V_69 = V_2 . V_21 ,
. V_70 = V_95 ,
. V_52 = - 1 ,
. V_72 = V_96 ,
. V_74 = F_14 ( V_96 ) ,
} ;
V_72 = V_96 + V_97 ;
V_72 -> V_82 = V_2 . V_98 ;
V_72 -> V_85 = V_72 -> V_82 + V_2 . V_99 - 1 ;
V_72 = V_96 + V_100 ;
V_72 -> V_82 = V_2 . V_101 ;
V_72 -> V_85 = V_72 -> V_82 + V_2 . V_102 - 1 ;
V_50 = F_40 ( & V_68 ) ;
if ( F_41 ( V_50 ) )
return F_42 ( V_50 ) ;
V_2 . V_103 = V_50 ;
return 0 ;
}
static int F_45 ( void )
{
int V_14 ;
if ( ! F_46 () ) {
V_14 = F_43 () ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_12 ) ;
return V_14 ;
}
}
V_14 = F_39 () ;
if ( V_14 ) {
F_13 ( V_2 . V_21 , L_13 ) ;
F_47 ( V_2 . V_94 ) ;
}
if ( ! V_2 . V_104 ) {
V_14 = F_44 () ;
if ( V_14 )
F_48 ( V_2 . V_21 ,
L_14 ) ;
}
return V_14 ;
}
static int F_49 ( struct V_66 * V_50 )
{
struct V_76 * V_72 , * V_105 ;
void T_7 * V_106 ;
int V_107 ;
V_72 = F_50 ( V_50 , V_108 ,
V_109 ) ;
if ( ! V_72 ) {
F_13 ( & V_50 -> V_21 , L_15 ) ;
return - V_110 ;
}
V_107 = F_51 ( V_72 ) ;
V_2 . V_83 = V_72 -> V_82 ;
V_2 . V_111 = V_107 ;
F_52 ( & V_50 -> V_21 , L_16 , V_72 ) ;
V_105 = V_73 ;
V_72 = F_50 ( V_50 , V_112 ,
V_113 ) ;
if ( ! V_72 ) {
F_13 ( & V_50 -> V_21 , L_17 ) ;
return - V_110 ;
}
* V_105 = * V_72 ;
F_52 ( & V_50 -> V_21 , L_18 , V_72 ) ;
V_72 = F_50 ( V_50 , V_112 ,
V_114 ) ;
if ( ! V_72 ) {
F_13 ( & V_50 -> V_21 , L_19 ) ;
return - V_110 ;
}
* ++ V_105 = * V_72 ;
F_52 ( & V_50 -> V_21 , L_20 , V_72 ) ;
V_72 = F_50 ( V_50 , V_112 ,
V_115 ) ;
++ V_105 ;
if ( V_72 ) {
* V_105 = * V_72 ;
F_52 ( & V_50 -> V_21 , L_21 , V_72 ) ;
}
V_72 = F_50 ( V_50 , V_112 ,
V_116 ) ;
++ V_105 ;
if ( V_72 ) {
* V_105 = * V_72 ;
F_52 ( & V_50 -> V_21 , L_22 , V_72 ) ;
}
V_72 = F_50 ( V_50 , V_112 ,
V_117 ) ;
++ V_105 ;
if ( V_72 ) {
* V_105 = * V_72 ;
F_52 ( & V_50 -> V_21 , L_23 , V_72 ) ;
}
V_72 = F_50 ( V_50 , V_112 ,
V_118 ) ;
++ V_105 ;
if ( V_72 ) {
* V_105 = * V_72 ;
F_52 ( & V_50 -> V_21 , L_24 , V_72 ) ;
}
V_72 = F_50 ( V_50 , V_112 ,
V_119 ) ;
if ( ! V_72 ) {
F_13 ( & V_50 -> V_21 , L_25 ) ;
return - V_110 ;
}
V_107 = V_120 ;
if ( ! F_53 ( V_72 -> V_82 , V_107 , V_50 -> V_70 ) ) {
F_13 ( & V_50 -> V_21 , L_26 ) ;
return - V_57 ;
}
V_106 = F_30 ( V_72 -> V_82 , V_107 ) ;
if ( ! V_106 ) {
F_13 ( & V_50 -> V_21 , L_27 ) ;
F_54 ( V_72 -> V_82 , V_107 ) ;
return - V_56 ;
}
V_2 . V_6 = V_106 ;
V_2 . V_91 = V_72 -> V_82 + V_121 ;
V_2 . V_122 = V_123 ;
F_52 ( & V_50 -> V_21 , L_28 , V_72 ) ;
V_2 . V_104 = 0 ;
V_72 = F_50 ( V_50 , V_112 ,
V_124 ) ;
if ( ! V_72 ) {
F_13 ( & V_50 -> V_21 , L_29 ) ;
V_2 . V_104 = 1 ;
} else {
V_2 . V_98 = V_72 -> V_82 +
V_125 ;
V_2 . V_99 = V_126 ;
V_2 . V_101 = V_72 -> V_82 +
V_127 ;
V_2 . V_102 = V_126 ;
F_52 ( & V_50 -> V_21 , L_30 , V_72 ) ;
}
return 0 ;
}
static int F_55 ( struct V_66 * V_50 )
{
struct V_76 * V_72 ;
int V_14 ;
V_2 . V_21 = & V_50 -> V_21 ;
V_2 . V_3 = V_55 ;
F_28 ( & V_2 . V_4 ) ;
V_2 . V_45 = F_56 ( V_50 , 0 ) ;
if ( V_2 . V_45 < 0 ) {
F_13 ( & V_50 -> V_21 , L_31 ) ;
return - V_42 ;
}
V_14 = F_49 ( V_50 ) ;
if ( V_14 ) {
F_13 ( & V_50 -> V_21 , L_32 ) ;
return V_14 ;
}
V_14 = F_45 () ;
if ( V_14 ) {
F_13 ( & V_50 -> V_21 , L_33 ) ;
goto V_128;
}
if ( F_29 ( V_2 . V_45 , F_20 , V_129 ,
L_4 , & V_2 ) ) {
F_13 ( & V_50 -> V_21 , L_6 ) ;
V_14 = - V_57 ;
goto V_130;
}
V_14 = F_57 ( & V_50 -> V_21 . V_131 , & V_132 ) ;
if ( V_14 ) {
F_13 ( & V_50 -> V_21 , L_34 ,
V_14 ) ;
goto V_133;
}
return 0 ;
V_133:
F_31 ( V_2 . V_45 , & V_2 ) ;
V_130:
F_47 ( V_2 . V_94 ) ;
F_47 ( V_2 . V_75 ) ;
F_47 ( V_2 . V_103 ) ;
V_128:
F_35 ( V_2 . V_6 ) ;
V_72 = F_50 ( V_50 , V_112 ,
V_119 ) ;
if ( V_72 )
F_54 ( V_72 -> V_82 , V_120 ) ;
return V_14 ;
}
static int F_58 ( struct V_66 * V_50 )
{
struct V_76 * V_72 ;
F_59 ( & V_50 -> V_21 . V_131 , & V_132 ) ;
F_31 ( V_2 . V_45 , & V_2 ) ;
F_47 ( V_2 . V_94 ) ;
F_47 ( V_2 . V_75 ) ;
F_47 ( V_2 . V_103 ) ;
F_35 ( V_2 . V_6 ) ;
V_72 = F_50 ( V_50 , V_112 ,
V_119 ) ;
if ( V_72 )
F_54 ( V_72 -> V_82 , V_120 ) ;
V_2 . V_21 = NULL ;
return 0 ;
}
static int T_8 F_60 ( void )
{
int V_14 ;
V_14 = F_61 ( & V_134 ) ;
if ( V_14 ) {
F_62 ( L_35 ) ;
return V_14 ;
}
V_14 = F_63 ( & V_135 ) ;
if ( V_14 ) {
F_62 ( L_36 ) ;
F_64 ( & V_134 ) ;
return V_14 ;
}
return V_14 ;
}
static void T_9 F_65 ( void )
{
F_66 ( & V_135 ) ;
F_64 ( & V_134 ) ;
}
