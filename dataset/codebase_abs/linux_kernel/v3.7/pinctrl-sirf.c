static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_3 [ V_4 ] . V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_4 ,
const unsigned * * V_6 ,
unsigned * V_7 )
{
* V_6 = V_3 [ V_4 ] . V_6 ;
* V_7 = V_3 [ V_4 ] . V_7 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 ,
unsigned V_10 )
{
F_6 ( V_9 , L_1 V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * * V_15 , unsigned * V_16 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_12 * V_19 ;
struct V_20 * V_21 ;
const char * V_22 , * V_23 ;
int V_24 , V_25 = 0 , V_26 = 0 ;
F_9 (np_config, np) {
V_24 = F_10 ( V_19 , L_2 , & V_22 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_11 ( V_19 , L_3 ) ;
if ( V_24 < 0 )
return V_24 ;
V_26 += V_24 ;
}
if ( ! V_26 ) {
F_12 ( V_18 -> V_27 , L_4 ) ;
return - V_28 ;
}
* V_15 = F_13 ( sizeof( * * V_15 ) * V_26 , V_29 ) ;
if ( ! * V_15 )
return - V_30 ;
F_9 (np_config, np) {
F_10 ( V_19 , L_2 , & V_22 ) ;
F_14 (np, L_3 , prop, group) {
( * V_15 ) [ V_25 ] . type = V_31 ;
( * V_15 ) [ V_25 ] . V_32 . V_33 . V_23 = V_23 ;
( * V_15 ) [ V_25 ] . V_32 . V_33 . V_22 = V_22 ;
V_25 ++ ;
}
}
* V_16 = V_26 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 , unsigned V_16 )
{
F_16 ( V_15 ) ;
}
static void F_17 ( struct V_17 * V_18 , unsigned V_4 ,
bool V_34 )
{
int V_35 ;
const struct V_36 * V_33 = V_37 [ V_4 ] . V_38 ;
const struct V_39 * V_40 = V_33 -> V_41 ;
for ( V_35 = 0 ; V_35 < V_33 -> V_42 ; V_35 ++ ) {
T_1 V_43 ;
V_43 = F_18 ( V_18 -> V_44 + F_19 ( V_40 [ V_35 ] . V_23 ) ) ;
if ( V_34 )
V_43 = V_43 & ~ V_40 [ V_35 ] . V_40 ;
else
V_43 = V_43 | V_40 [ V_35 ] . V_40 ;
F_20 ( V_43 , V_18 -> V_44 + F_19 ( V_40 [ V_35 ] . V_23 ) ) ;
}
if ( V_33 -> V_45 && V_34 ) {
T_1 V_46 ;
V_46 =
F_18 ( V_18 -> V_47 + V_48 ) ;
V_46 =
( V_46 & ~ V_33 -> V_45 ) | ( V_33 ->
V_49 ) ;
F_20 ( V_46 , V_18 -> V_47 + V_48 ) ;
}
}
static int F_21 ( struct V_1 * V_50 , unsigned V_4 ,
unsigned V_23 )
{
struct V_17 * V_18 ;
V_18 = F_8 ( V_50 ) ;
F_17 ( V_18 , V_4 , true ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_50 , unsigned V_4 ,
unsigned V_23 )
{
struct V_17 * V_18 ;
V_18 = F_8 ( V_50 ) ;
F_17 ( V_18 , V_4 , false ) ;
}
static int F_23 ( struct V_1 * V_50 )
{
return F_2 ( V_37 ) ;
}
static const char * F_24 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_37 [ V_4 ] . V_5 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_51 ,
unsigned * const V_52 )
{
* V_51 = V_37 [ V_4 ] . V_51 ;
* V_52 = V_37 [ V_4 ] . V_52 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_50 ,
struct V_53 * V_54 , unsigned V_10 )
{
struct V_17 * V_18 ;
int V_23 = V_54 -> V_55 ;
T_1 V_43 ;
V_18 = F_8 ( V_50 ) ;
V_43 = F_18 ( V_18 -> V_44 + F_19 ( V_23 ) ) ;
V_43 = V_43 | ( 1 << ( V_10 - V_54 -> V_56 ) ) ;
F_20 ( V_43 , V_18 -> V_44 + F_19 ( V_23 ) ) ;
return 0 ;
}
static void T_2 * F_27 ( void )
{
const struct V_57 V_58 [] = {
{ . V_59 = L_5 } ,
{}
} ;
struct V_12 * V_19 ;
V_19 = F_28 ( NULL , V_58 ) ;
if ( ! V_19 )
F_29 ( L_6 ) ;
return F_30 ( V_19 , 0 ) ;
}
static int T_3 F_31 ( struct V_60 * V_61 )
{
int V_24 ;
struct V_17 * V_18 ;
struct V_12 * V_19 = V_61 -> V_27 . V_62 ;
int V_35 ;
V_18 = F_32 ( & V_61 -> V_27 , sizeof( * V_18 ) , V_29 ) ;
if ( ! V_18 )
return - V_30 ;
V_18 -> V_27 = & V_61 -> V_27 ;
F_33 ( V_61 , V_18 ) ;
V_18 -> V_44 = F_30 ( V_19 , 0 ) ;
if ( ! V_18 -> V_44 ) {
V_24 = - V_30 ;
F_12 ( & V_61 -> V_27 , L_7 ) ;
goto V_63;
}
V_18 -> V_47 = F_27 () ;
if ( ! V_18 -> V_47 ) {
V_24 = - V_30 ;
F_12 ( & V_61 -> V_27 , L_8 ) ;
goto V_64;
}
V_18 -> V_65 = F_34 ( & V_66 , & V_61 -> V_27 , V_18 ) ;
if ( ! V_18 -> V_65 ) {
F_12 ( & V_61 -> V_27 , L_9 ) ;
V_24 = - V_67 ;
goto V_68;
}
for ( V_35 = 0 ; V_35 < F_2 ( V_69 ) ; V_35 ++ ) {
V_69 [ V_35 ] . V_70 = & V_71 [ V_35 ] . V_72 . V_70 ;
F_35 ( V_18 -> V_65 , & V_69 [ V_35 ] ) ;
}
F_36 ( & V_61 -> V_27 , L_10 ) ;
return 0 ;
V_68:
F_37 ( V_18 -> V_47 ) ;
V_64:
F_37 ( V_18 -> V_44 ) ;
V_63:
F_33 ( V_61 , NULL ) ;
return V_24 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_73 ) ;
}
static inline int F_40 ( struct V_74 * V_72 , unsigned V_10 )
{
struct V_75 * V_76 = F_41 ( F_42 ( V_72 ) ,
struct V_75 , V_72 ) ;
return F_43 ( V_76 -> V_77 , V_10 ) ;
}
static inline int F_44 ( unsigned int V_78 )
{
return V_78 % V_79 ;
}
static inline struct V_75 * F_45 ( unsigned int V_78 )
{
return & V_71 [ V_78 / V_79 ] ;
}
static inline struct V_75 * F_46 ( struct V_74 * V_72 )
{
return F_41 ( F_42 ( V_72 ) , struct V_75 , V_72 ) ;
}
static void F_47 ( struct V_80 * V_81 )
{
struct V_75 * V_76 = F_48 ( V_81 ) ;
int V_82 = V_81 -> V_83 % V_79 ;
T_1 V_84 , V_10 ;
unsigned long V_85 ;
V_10 = F_49 ( V_76 -> V_55 , V_82 ) ;
F_50 ( & V_86 , V_85 ) ;
V_84 = F_18 ( V_76 -> V_72 . V_87 + V_10 ) ;
F_20 ( V_84 , V_76 -> V_72 . V_87 + V_10 ) ;
F_51 ( & V_86 , V_85 ) ;
}
static void F_52 ( struct V_75 * V_76 , int V_82 )
{
T_1 V_84 , V_10 ;
unsigned long V_85 ;
V_10 = F_49 ( V_76 -> V_55 , V_82 ) ;
F_50 ( & V_86 , V_85 ) ;
V_84 = F_18 ( V_76 -> V_72 . V_87 + V_10 ) ;
V_84 &= ~ V_88 ;
V_84 &= ~ V_89 ;
F_20 ( V_84 , V_76 -> V_72 . V_87 + V_10 ) ;
F_51 ( & V_86 , V_85 ) ;
}
static void F_53 ( struct V_80 * V_81 )
{
struct V_75 * V_76 = F_48 ( V_81 ) ;
F_52 ( V_76 , V_81 -> V_83 % V_79 ) ;
}
static void F_54 ( struct V_80 * V_81 )
{
struct V_75 * V_76 = F_48 ( V_81 ) ;
int V_82 = V_81 -> V_83 % V_79 ;
T_1 V_84 , V_10 ;
unsigned long V_85 ;
V_10 = F_49 ( V_76 -> V_55 , V_82 ) ;
F_50 ( & V_86 , V_85 ) ;
V_84 = F_18 ( V_76 -> V_72 . V_87 + V_10 ) ;
V_84 &= ~ V_89 ;
V_84 |= V_88 ;
F_20 ( V_84 , V_76 -> V_72 . V_87 + V_10 ) ;
F_51 ( & V_86 , V_85 ) ;
}
static int F_55 ( struct V_80 * V_81 , unsigned type )
{
struct V_75 * V_76 = F_48 ( V_81 ) ;
int V_82 = V_81 -> V_83 % V_79 ;
T_1 V_84 , V_10 ;
unsigned long V_85 ;
V_10 = F_49 ( V_76 -> V_55 , V_82 ) ;
F_50 ( & V_86 , V_85 ) ;
V_84 = F_18 ( V_76 -> V_72 . V_87 + V_10 ) ;
V_84 &= ~ V_89 ;
switch ( type ) {
case V_90 :
break;
case V_91 :
V_84 |= V_92 | V_93 ;
V_84 &= ~ V_94 ;
break;
case V_95 :
V_84 &= ~ V_92 ;
V_84 |= V_94 | V_93 ;
break;
case V_96 :
V_84 |= V_92 | V_94 |
V_93 ;
break;
case V_97 :
V_84 &= ~ ( V_92 | V_93 ) ;
V_84 |= V_94 ;
break;
case V_98 :
V_84 |= V_92 ;
V_84 &= ~ ( V_94 | V_93 ) ;
break;
}
F_20 ( V_84 , V_76 -> V_72 . V_87 + V_10 ) ;
F_51 ( & V_86 , V_85 ) ;
return 0 ;
}
static void F_56 ( unsigned int V_99 , struct V_100 * V_101 )
{
struct V_75 * V_76 = F_57 ( V_99 ) ;
T_1 V_102 , V_103 ;
int V_82 = 0 ;
unsigned int V_104 ;
struct V_105 * V_72 = F_58 ( V_99 ) ;
F_59 ( V_72 , V_101 ) ;
V_102 = F_18 ( V_76 -> V_72 . V_87 + F_60 ( V_76 -> V_55 ) ) ;
if ( ! V_102 ) {
F_61 ( V_106
L_11 ,
V_107 , V_76 -> V_55 , V_102 ) ;
F_62 ( V_99 , V_101 ) ;
return;
}
V_104 = V_76 -> V_77 -> V_108 . V_109 . V_104 ;
while ( V_102 ) {
V_103 = F_18 ( V_76 -> V_72 . V_87 + F_49 ( V_76 -> V_55 , V_82 ) ) ;
if ( ( V_102 & 0x1 ) && ( V_103 & V_88 ) ) {
F_63 ( L_12 ,
V_107 , V_76 -> V_55 , V_82 ) ;
F_64 ( V_104 + V_82 ) ;
}
V_82 ++ ;
V_102 = V_102 >> 1 ;
}
F_65 ( V_72 , V_101 ) ;
}
static inline void F_66 ( struct V_75 * V_76 , unsigned V_110 )
{
T_1 V_84 ;
V_84 = F_18 ( V_76 -> V_72 . V_87 + V_110 ) ;
V_84 &= ~ V_111 ;
F_20 ( V_84 , V_76 -> V_72 . V_87 + V_110 ) ;
}
static int F_67 ( struct V_74 * V_72 , unsigned V_10 )
{
struct V_75 * V_76 = F_46 ( V_72 ) ;
unsigned long V_85 ;
if ( F_68 ( V_72 -> V_112 + V_10 ) )
return - V_28 ;
F_50 ( & V_76 -> V_113 , V_85 ) ;
F_66 ( V_76 , F_49 ( V_76 -> V_55 , V_10 ) ) ;
F_52 ( V_76 , V_10 ) ;
F_51 ( & V_76 -> V_113 , V_85 ) ;
return 0 ;
}
static void F_69 ( struct V_74 * V_72 , unsigned V_10 )
{
struct V_75 * V_76 = F_46 ( V_72 ) ;
unsigned long V_85 ;
F_50 ( & V_76 -> V_113 , V_85 ) ;
F_52 ( V_76 , V_10 ) ;
F_66 ( V_76 , F_49 ( V_76 -> V_55 , V_10 ) ) ;
F_51 ( & V_76 -> V_113 , V_85 ) ;
F_70 ( V_72 -> V_112 + V_10 ) ;
}
static int F_71 ( struct V_74 * V_72 , unsigned V_78 )
{
struct V_75 * V_76 = F_46 ( V_72 ) ;
int V_82 = F_44 ( V_78 ) ;
unsigned long V_85 ;
unsigned V_10 ;
V_10 = F_49 ( V_76 -> V_55 , V_82 ) ;
F_50 ( & V_76 -> V_113 , V_85 ) ;
F_66 ( V_76 , V_10 ) ;
F_51 ( & V_76 -> V_113 , V_85 ) ;
return 0 ;
}
static inline void F_72 ( struct V_75 * V_76 , unsigned V_10 ,
int V_114 )
{
T_1 V_115 ;
unsigned long V_85 ;
F_50 ( & V_76 -> V_113 , V_85 ) ;
V_115 = F_18 ( V_76 -> V_72 . V_87 + V_10 ) ;
if ( V_114 )
V_115 |= V_116 ;
else
V_115 &= ~ V_116 ;
V_115 &= ~ V_88 ;
V_115 |= V_111 ;
F_20 ( V_115 , V_76 -> V_72 . V_87 + V_10 ) ;
F_51 ( & V_76 -> V_113 , V_85 ) ;
}
static int F_73 ( struct V_74 * V_72 , unsigned V_78 , int V_114 )
{
struct V_75 * V_76 = F_46 ( V_72 ) ;
int V_82 = F_44 ( V_78 ) ;
T_1 V_10 ;
unsigned long V_85 ;
V_10 = F_49 ( V_76 -> V_55 , V_82 ) ;
F_50 ( & V_86 , V_85 ) ;
F_72 ( V_76 , V_10 , V_114 ) ;
F_51 ( & V_86 , V_85 ) ;
return 0 ;
}
static int F_74 ( struct V_74 * V_72 , unsigned V_10 )
{
struct V_75 * V_76 = F_46 ( V_72 ) ;
T_1 V_84 ;
unsigned long V_85 ;
F_50 ( & V_76 -> V_113 , V_85 ) ;
V_84 = F_18 ( V_76 -> V_72 . V_87 + F_49 ( V_76 -> V_55 , V_10 ) ) ;
F_51 ( & V_76 -> V_113 , V_85 ) ;
return ! ! ( V_84 & V_117 ) ;
}
static void F_75 ( struct V_74 * V_72 , unsigned V_10 ,
int V_114 )
{
struct V_75 * V_76 = F_46 ( V_72 ) ;
T_1 V_103 ;
unsigned long V_85 ;
F_50 ( & V_76 -> V_113 , V_85 ) ;
V_103 = F_18 ( V_76 -> V_72 . V_87 + F_49 ( V_76 -> V_55 , V_10 ) ) ;
if ( V_114 )
V_103 |= V_116 ;
else
V_103 &= ~ V_116 ;
F_20 ( V_103 , V_76 -> V_72 . V_87 + F_49 ( V_76 -> V_55 , V_10 ) ) ;
F_51 ( & V_76 -> V_113 , V_85 ) ;
}
int F_76 ( struct V_118 * V_81 , unsigned int V_99 ,
T_5 V_83 )
{
struct V_75 * V_76 = V_81 -> V_119 ;
if ( ! V_76 )
return - V_67 ;
F_77 ( V_99 , & V_120 ) ;
F_78 ( V_99 , V_121 ) ;
F_79 ( V_99 , V_76 ) ;
F_80 ( V_99 , V_122 ) ;
return 0 ;
}
static int T_3 F_81 ( struct V_12 * V_19 )
{
int V_35 , V_123 = 0 ;
struct V_75 * V_76 ;
void * V_87 ;
struct V_60 * V_61 ;
V_61 = F_82 ( V_19 ) ;
if ( ! V_61 )
return - V_28 ;
V_87 = F_30 ( V_19 , 0 ) ;
if ( ! V_87 )
return - V_30 ;
for ( V_35 = 0 ; V_35 < V_124 ; V_35 ++ ) {
V_76 = & V_71 [ V_35 ] ;
F_83 ( & V_76 -> V_113 ) ;
V_76 -> V_72 . V_70 . V_125 = F_67 ;
V_76 -> V_72 . V_70 . free = F_69 ;
V_76 -> V_72 . V_70 . V_126 = F_71 ;
V_76 -> V_72 . V_70 . V_127 = F_74 ;
V_76 -> V_72 . V_70 . V_128 = F_73 ;
V_76 -> V_72 . V_70 . V_129 = F_75 ;
V_76 -> V_72 . V_70 . V_130 = F_40 ;
V_76 -> V_72 . V_70 . V_112 = V_35 * V_79 ;
V_76 -> V_72 . V_70 . V_131 = V_79 ;
V_76 -> V_72 . V_70 . V_132 = F_84 ( V_19 -> V_133 , V_29 ) ;
V_76 -> V_72 . V_70 . V_62 = V_19 ;
V_76 -> V_72 . V_87 = V_87 ;
V_76 -> V_55 = V_35 ;
V_76 -> V_134 = F_85 ( V_61 , V_35 ) ;
if ( V_76 -> V_134 < 0 ) {
V_123 = V_76 -> V_134 ;
goto V_135;
}
V_123 = F_86 ( & V_76 -> V_72 . V_70 ) ;
if ( V_123 ) {
F_87 ( L_13 ,
V_19 -> V_133 , V_123 ) ;
goto V_135;
}
V_76 -> V_77 = F_88 ( V_19 , V_79 ,
V_136 + V_35 * V_79 , 0 ,
& V_137 , V_76 ) ;
if ( ! V_76 -> V_77 ) {
F_87 ( L_14 , V_19 -> V_133 ) ;
V_123 = - V_138 ;
goto V_135;
}
F_89 ( V_76 -> V_134 , F_56 ) ;
F_90 ( V_76 -> V_134 , V_76 ) ;
}
return 0 ;
V_135:
F_37 ( V_87 ) ;
return V_123 ;
}
static int T_4 F_91 ( void )
{
struct V_12 * V_19 ;
V_19 = F_28 ( NULL , V_139 ) ;
if ( ! V_19 )
return - V_28 ;
return F_81 ( V_19 ) ;
}
