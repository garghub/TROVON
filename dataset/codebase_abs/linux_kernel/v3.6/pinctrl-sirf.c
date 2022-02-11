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
static void F_7 ( struct V_12 * V_13 , unsigned V_4 ,
bool V_14 )
{
int V_15 ;
const struct V_16 * V_17 = V_18 [ V_4 ] . V_19 ;
const struct V_20 * V_21 = V_17 -> V_22 ;
for ( V_15 = 0 ; V_15 < V_17 -> V_23 ; V_15 ++ ) {
T_1 V_24 ;
V_24 = F_8 ( V_13 -> V_25 + F_9 ( V_21 [ V_15 ] . V_26 ) ) ;
if ( V_14 )
V_24 = V_24 & ~ V_21 [ V_15 ] . V_21 ;
else
V_24 = V_24 | V_21 [ V_15 ] . V_21 ;
F_10 ( V_24 , V_13 -> V_25 + F_9 ( V_21 [ V_15 ] . V_26 ) ) ;
}
if ( V_17 -> V_27 && V_14 ) {
T_1 V_28 ;
V_28 =
F_8 ( V_13 -> V_29 + V_30 ) ;
V_28 =
( V_28 & ~ V_17 -> V_27 ) | ( V_17 ->
V_31 ) ;
F_10 ( V_28 , V_13 -> V_29 + V_30 ) ;
}
}
static int F_11 ( struct V_1 * V_32 , unsigned V_4 ,
unsigned V_26 )
{
struct V_12 * V_13 ;
V_13 = F_12 ( V_32 ) ;
F_7 ( V_13 , V_4 , true ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_32 , unsigned V_4 ,
unsigned V_26 )
{
struct V_12 * V_13 ;
V_13 = F_12 ( V_32 ) ;
F_7 ( V_13 , V_4 , false ) ;
}
static int F_14 ( struct V_1 * V_32 )
{
return F_2 ( V_18 ) ;
}
static const char * F_15 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_18 [ V_4 ] . V_5 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_33 ,
unsigned * const V_34 )
{
* V_33 = V_18 [ V_4 ] . V_33 ;
* V_34 = V_18 [ V_4 ] . V_34 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_32 ,
struct V_35 * V_36 , unsigned V_10 )
{
struct V_12 * V_13 ;
int V_26 = V_36 -> V_37 ;
T_1 V_24 ;
V_13 = F_12 ( V_32 ) ;
V_24 = F_8 ( V_13 -> V_25 + F_9 ( V_26 ) ) ;
V_24 = V_24 | ( 1 << ( V_10 - V_36 -> V_38 ) ) ;
F_10 ( V_24 , V_13 -> V_25 + F_9 ( V_26 ) ) ;
return 0 ;
}
static void T_2 * F_18 ( void )
{
const struct V_39 V_40 [] = {
{ . V_41 = L_2 } ,
{}
} ;
struct V_42 * V_43 ;
V_43 = F_19 ( NULL , V_40 ) ;
if ( ! V_43 )
F_20 ( L_3 ) ;
return F_21 ( V_43 , 0 ) ;
}
static int T_3 F_22 ( struct V_44 * V_45 )
{
int V_46 ;
struct V_12 * V_13 ;
struct V_42 * V_43 = V_45 -> V_47 . V_48 ;
int V_15 ;
V_13 = F_23 ( & V_45 -> V_47 , sizeof( * V_13 ) , V_49 ) ;
if ( ! V_13 )
return - V_50 ;
V_13 -> V_47 = & V_45 -> V_47 ;
F_24 ( V_45 , V_13 ) ;
V_13 -> V_25 = F_21 ( V_43 , 0 ) ;
if ( ! V_13 -> V_25 ) {
V_46 = - V_50 ;
F_25 ( & V_45 -> V_47 , L_4 ) ;
goto V_51;
}
V_13 -> V_29 = F_18 () ;
if ( ! V_13 -> V_29 ) {
V_46 = - V_50 ;
F_25 ( & V_45 -> V_47 , L_5 ) ;
goto V_52;
}
V_13 -> V_53 = F_26 ( & V_54 , & V_45 -> V_47 , V_13 ) ;
if ( ! V_13 -> V_53 ) {
F_25 ( & V_45 -> V_47 , L_6 ) ;
V_46 = - V_55 ;
goto V_56;
}
for ( V_15 = 0 ; V_15 < F_2 ( V_57 ) ; V_15 ++ )
F_27 ( V_13 -> V_53 , & V_57 [ V_15 ] ) ;
F_28 ( & V_45 -> V_47 , L_7 ) ;
return 0 ;
V_56:
F_29 ( V_13 -> V_29 ) ;
V_52:
F_29 ( V_13 -> V_25 ) ;
V_51:
F_24 ( V_45 , NULL ) ;
return V_46 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_58 ) ;
}
static inline int F_32 ( struct V_59 * V_60 , unsigned V_10 )
{
struct V_61 * V_62 = F_33 ( F_34 ( V_60 ) ,
struct V_61 , V_60 ) ;
return F_35 ( V_62 -> V_63 , V_10 ) ;
}
static inline int F_36 ( unsigned int V_64 )
{
return V_64 % V_65 ;
}
static inline struct V_61 * F_37 ( unsigned int V_64 )
{
return & V_66 [ V_64 / V_65 ] ;
}
void F_38 ( unsigned V_64 , unsigned V_67 )
{
struct V_61 * V_62 = F_37 ( V_64 ) ;
int V_68 = F_36 ( V_64 ) ;
T_1 V_69 , V_10 ;
unsigned long V_70 ;
V_10 = F_39 ( V_62 -> V_37 , V_68 ) ;
F_40 ( & V_71 , V_70 ) ;
V_69 = F_8 ( V_62 -> V_60 . V_72 + V_10 ) ;
switch ( V_67 ) {
case V_73 :
V_69 &= ~ V_74 ;
break;
case V_75 :
V_69 |= V_74 ;
V_69 |= V_76 ;
break;
case V_77 :
V_69 |= V_74 ;
V_69 &= ~ V_76 ;
break;
default:
break;
}
F_10 ( V_69 , V_62 -> V_60 . V_72 + V_10 ) ;
F_41 ( & V_71 , V_70 ) ;
}
static inline struct V_61 * F_42 ( struct V_59 * V_60 )
{
return F_33 ( F_34 ( V_60 ) , struct V_61 , V_60 ) ;
}
static void F_43 ( struct V_78 * V_79 )
{
struct V_61 * V_62 = F_44 ( V_79 ) ;
int V_68 = V_79 -> V_80 % V_65 ;
T_1 V_69 , V_10 ;
unsigned long V_70 ;
V_10 = F_39 ( V_62 -> V_37 , V_68 ) ;
F_40 ( & V_71 , V_70 ) ;
V_69 = F_8 ( V_62 -> V_60 . V_72 + V_10 ) ;
F_10 ( V_69 , V_62 -> V_60 . V_72 + V_10 ) ;
F_41 ( & V_71 , V_70 ) ;
}
static void F_45 ( struct V_61 * V_62 , int V_68 )
{
T_1 V_69 , V_10 ;
unsigned long V_70 ;
V_10 = F_39 ( V_62 -> V_37 , V_68 ) ;
F_40 ( & V_71 , V_70 ) ;
V_69 = F_8 ( V_62 -> V_60 . V_72 + V_10 ) ;
V_69 &= ~ V_81 ;
V_69 &= ~ V_82 ;
F_10 ( V_69 , V_62 -> V_60 . V_72 + V_10 ) ;
F_41 ( & V_71 , V_70 ) ;
}
static void F_46 ( struct V_78 * V_79 )
{
struct V_61 * V_62 = F_44 ( V_79 ) ;
F_45 ( V_62 , V_79 -> V_80 % V_65 ) ;
}
static void F_47 ( struct V_78 * V_79 )
{
struct V_61 * V_62 = F_44 ( V_79 ) ;
int V_68 = V_79 -> V_80 % V_65 ;
T_1 V_69 , V_10 ;
unsigned long V_70 ;
V_10 = F_39 ( V_62 -> V_37 , V_68 ) ;
F_40 ( & V_71 , V_70 ) ;
V_69 = F_8 ( V_62 -> V_60 . V_72 + V_10 ) ;
V_69 &= ~ V_82 ;
V_69 |= V_81 ;
F_10 ( V_69 , V_62 -> V_60 . V_72 + V_10 ) ;
F_41 ( & V_71 , V_70 ) ;
}
static int F_48 ( struct V_78 * V_79 , unsigned type )
{
struct V_61 * V_62 = F_44 ( V_79 ) ;
int V_68 = V_79 -> V_80 % V_65 ;
T_1 V_69 , V_10 ;
unsigned long V_70 ;
V_10 = F_39 ( V_62 -> V_37 , V_68 ) ;
F_40 ( & V_71 , V_70 ) ;
V_69 = F_8 ( V_62 -> V_60 . V_72 + V_10 ) ;
V_69 &= ~ V_82 ;
switch ( type ) {
case V_83 :
break;
case V_84 :
V_69 |= V_85 | V_86 ;
V_69 &= ~ V_87 ;
break;
case V_88 :
V_69 &= ~ V_85 ;
V_69 |= V_87 | V_86 ;
break;
case V_89 :
V_69 |= V_85 | V_87 |
V_86 ;
break;
case V_90 :
V_69 &= ~ ( V_85 | V_86 ) ;
V_69 |= V_87 ;
break;
case V_91 :
V_69 |= V_85 ;
V_69 &= ~ ( V_87 | V_86 ) ;
break;
}
F_10 ( V_69 , V_62 -> V_60 . V_72 + V_10 ) ;
F_41 ( & V_71 , V_70 ) ;
return 0 ;
}
static void F_49 ( unsigned int V_92 , struct V_93 * V_94 )
{
struct V_61 * V_62 = F_50 ( V_92 ) ;
T_1 V_95 , V_96 ;
int V_68 = 0 ;
unsigned int V_97 ;
V_95 = F_8 ( V_62 -> V_60 . V_72 + F_51 ( V_62 -> V_37 ) ) ;
if ( ! V_95 ) {
F_52 ( V_98
L_8 ,
V_99 , V_62 -> V_37 , V_95 ) ;
F_53 ( V_92 , V_94 ) ;
return;
}
V_97 = V_62 -> V_63 -> V_100 . V_101 . V_97 ;
while ( V_95 ) {
V_96 = F_8 ( V_62 -> V_60 . V_72 + F_39 ( V_62 -> V_37 , V_68 ) ) ;
if ( ( V_95 & 0x1 ) && ( V_96 & V_81 ) ) {
F_54 ( L_9 ,
V_99 , V_62 -> V_37 , V_68 ) ;
F_55 ( V_97 + V_68 ) ;
}
V_68 ++ ;
V_95 = V_95 >> 1 ;
}
}
static inline void F_56 ( struct V_61 * V_62 , unsigned V_102 )
{
T_1 V_69 ;
unsigned long V_70 ;
F_40 ( & V_62 -> V_103 , V_70 ) ;
V_69 = F_8 ( V_62 -> V_60 . V_72 + V_102 ) ;
V_69 &= ~ V_104 ;
F_10 ( V_69 , V_62 -> V_60 . V_72 + V_102 ) ;
F_41 ( & V_62 -> V_103 , V_70 ) ;
}
static int F_57 ( struct V_59 * V_60 , unsigned V_10 )
{
struct V_61 * V_62 = F_42 ( V_60 ) ;
unsigned long V_70 ;
if ( F_58 ( V_60 -> V_105 + V_10 ) )
return - V_106 ;
F_40 ( & V_62 -> V_103 , V_70 ) ;
F_56 ( V_62 , F_39 ( V_62 -> V_37 , V_10 ) ) ;
F_45 ( V_62 , V_10 ) ;
F_41 ( & V_62 -> V_103 , V_70 ) ;
return 0 ;
}
static void F_59 ( struct V_59 * V_60 , unsigned V_10 )
{
struct V_61 * V_62 = F_42 ( V_60 ) ;
unsigned long V_70 ;
F_40 ( & V_62 -> V_103 , V_70 ) ;
F_45 ( V_62 , V_10 ) ;
F_56 ( V_62 , F_39 ( V_62 -> V_37 , V_10 ) ) ;
F_41 ( & V_62 -> V_103 , V_70 ) ;
F_60 ( V_60 -> V_105 + V_10 ) ;
}
static int F_61 ( struct V_59 * V_60 , unsigned V_64 )
{
struct V_61 * V_62 = F_42 ( V_60 ) ;
int V_68 = F_36 ( V_64 ) ;
unsigned long V_70 ;
unsigned V_10 ;
V_10 = F_39 ( V_62 -> V_37 , V_68 ) ;
F_40 ( & V_62 -> V_103 , V_70 ) ;
F_56 ( V_62 , V_10 ) ;
F_41 ( & V_62 -> V_103 , V_70 ) ;
return 0 ;
}
static inline void F_62 ( struct V_61 * V_62 , unsigned V_10 ,
int V_107 )
{
T_1 V_108 ;
unsigned long V_70 ;
F_40 ( & V_62 -> V_103 , V_70 ) ;
V_108 = F_8 ( V_62 -> V_60 . V_72 + V_10 ) ;
if ( V_107 )
V_108 |= V_109 ;
else
V_108 &= ~ V_109 ;
V_108 &= ~ V_81 ;
V_108 |= V_104 ;
F_10 ( V_108 , V_62 -> V_60 . V_72 + V_10 ) ;
F_41 ( & V_62 -> V_103 , V_70 ) ;
}
static int F_63 ( struct V_59 * V_60 , unsigned V_64 , int V_107 )
{
struct V_61 * V_62 = F_42 ( V_60 ) ;
int V_68 = F_36 ( V_64 ) ;
T_1 V_10 ;
unsigned long V_70 ;
V_10 = F_39 ( V_62 -> V_37 , V_68 ) ;
F_40 ( & V_71 , V_70 ) ;
F_62 ( V_62 , V_10 , V_107 ) ;
F_41 ( & V_71 , V_70 ) ;
return 0 ;
}
static int F_64 ( struct V_59 * V_60 , unsigned V_10 )
{
struct V_61 * V_62 = F_42 ( V_60 ) ;
T_1 V_69 ;
unsigned long V_70 ;
F_40 ( & V_62 -> V_103 , V_70 ) ;
V_69 = F_8 ( V_62 -> V_60 . V_72 + F_39 ( V_62 -> V_37 , V_10 ) ) ;
F_41 ( & V_62 -> V_103 , V_70 ) ;
return ! ! ( V_69 & V_110 ) ;
}
static void F_65 ( struct V_59 * V_60 , unsigned V_10 ,
int V_107 )
{
struct V_61 * V_62 = F_42 ( V_60 ) ;
T_1 V_96 ;
unsigned long V_70 ;
F_40 ( & V_62 -> V_103 , V_70 ) ;
V_96 = F_8 ( V_62 -> V_60 . V_72 + F_39 ( V_62 -> V_37 , V_10 ) ) ;
if ( V_107 )
V_96 |= V_109 ;
else
V_96 &= ~ V_109 ;
F_10 ( V_96 , V_62 -> V_60 . V_72 + F_39 ( V_62 -> V_37 , V_10 ) ) ;
F_41 ( & V_62 -> V_103 , V_70 ) ;
}
int F_66 ( struct V_111 * V_79 , unsigned int V_92 ,
T_5 V_80 )
{
struct V_61 * V_62 = V_79 -> V_112 ;
if ( ! V_62 )
return - V_55 ;
F_67 ( V_92 , & V_113 ) ;
F_68 ( V_92 , V_114 ) ;
F_69 ( V_92 , V_62 ) ;
F_70 ( V_92 , V_115 ) ;
return 0 ;
}
static int T_3 F_71 ( struct V_42 * V_43 )
{
int V_15 , V_116 = 0 ;
struct V_61 * V_62 ;
void * V_72 ;
struct V_44 * V_45 ;
V_45 = F_72 ( V_43 ) ;
if ( ! V_45 )
return - V_106 ;
V_72 = F_21 ( V_43 , 0 ) ;
if ( ! V_72 )
return - V_50 ;
for ( V_15 = 0 ; V_15 < V_117 ; V_15 ++ ) {
V_62 = & V_66 [ V_15 ] ;
F_73 ( & V_62 -> V_103 ) ;
V_62 -> V_60 . V_118 . V_119 = F_57 ;
V_62 -> V_60 . V_118 . free = F_59 ;
V_62 -> V_60 . V_118 . V_120 = F_61 ;
V_62 -> V_60 . V_118 . V_121 = F_64 ;
V_62 -> V_60 . V_118 . V_122 = F_63 ;
V_62 -> V_60 . V_118 . V_123 = F_65 ;
V_62 -> V_60 . V_118 . V_124 = F_32 ;
V_62 -> V_60 . V_118 . V_105 = V_15 * V_65 ;
V_62 -> V_60 . V_118 . V_125 = V_65 ;
V_62 -> V_60 . V_118 . V_126 = F_74 ( V_43 -> V_127 , V_49 ) ;
V_62 -> V_60 . V_118 . V_48 = V_43 ;
V_62 -> V_60 . V_72 = V_72 ;
V_62 -> V_37 = V_15 ;
V_62 -> V_128 = F_75 ( V_45 , V_15 ) ;
if ( V_62 -> V_128 < 0 ) {
V_116 = V_62 -> V_128 ;
goto V_129;
}
V_116 = F_76 ( & V_62 -> V_60 . V_118 ) ;
if ( V_116 ) {
F_77 ( L_10 ,
V_43 -> V_127 , V_116 ) ;
goto V_129;
}
V_62 -> V_63 = F_78 ( V_43 , V_65 ,
V_130 + V_15 * V_65 , 0 ,
& V_131 , V_62 ) ;
if ( ! V_62 -> V_63 ) {
F_77 ( L_11 , V_43 -> V_127 ) ;
V_116 = - V_132 ;
goto V_129;
}
F_79 ( V_62 -> V_128 , F_49 ) ;
F_80 ( V_62 -> V_128 , V_62 ) ;
}
V_129:
F_29 ( V_72 ) ;
return V_116 ;
}
static int T_4 F_81 ( void )
{
struct V_42 * V_43 ;
V_43 = F_19 ( NULL , V_133 ) ;
if ( ! V_43 )
return - V_106 ;
return F_71 ( V_43 ) ;
}
