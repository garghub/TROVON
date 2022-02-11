static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 ) {
if ( F_2 ( V_4 , V_3 ) ) {
F_3 ( V_2 -> V_6 ,
L_1 , V_4 ) ;
}
} else {
F_4 ( V_3 , V_2 -> V_7 + V_4 ) ;
}
}
static inline unsigned int F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_3 ;
if ( V_2 -> V_5 ) {
if ( F_6 ( V_4 , & V_3 ) ) {
F_3 ( V_2 -> V_6 ,
L_1 , V_4 ) ;
}
} else {
V_3 = F_7 ( V_2 -> V_7 + V_4 ) ;
}
return V_3 ;
}
static void F_8 ( void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
F_1 ( V_2 , 0x0 , V_9 ) ;
F_9 () ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_10 ;
F_11 () ;
F_9 () ;
V_10 = F_5 ( V_2 , V_11 ) ;
V_10 |= V_12 ;
F_1 ( V_2 , V_10 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = F_5 ( V_2 , V_11 ) ;
V_10 &= ~ V_12 ;
F_1 ( V_2 , V_10 , V_11 ) ;
F_11 () ;
F_9 () ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_13 ;
V_13 = F_7 ( V_2 -> V_7 + V_14 ) ;
V_13 |= V_15 ;
F_4 ( V_13 , V_2 -> V_7 + V_14 ) ;
F_11 () ;
F_9 () ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_13 ;
F_11 () ;
F_9 () ;
V_13 = F_7 ( V_2 -> V_7 + V_14 ) ;
V_13 &= ~ V_15 ;
F_4 ( V_13 , V_2 -> V_7 + V_14 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_16 ,
int V_17 , int V_18 )
{
int V_19 ;
T_1 V_3 ;
for ( V_19 = V_20 ; V_19 > 0 ; V_19 -- ) {
V_3 = F_5 ( V_2 , V_16 ) ;
if ( V_18 ) {
if ( V_3 & F_16 ( V_17 ) )
return 0 ;
} else {
if ( ! ( V_3 & F_16 ( V_17 ) ) )
return 0 ;
}
if ( V_19 - 1 )
F_17 ( 1 ) ;
}
return - V_21 ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = F_5 ( V_2 , V_11 ) ;
V_10 |= V_22 ;
F_1 ( V_2 , V_10 , V_11 ) ;
F_9 () ;
if ( F_15 ( V_2 , V_23 , V_24 , 1 ) ) {
F_3 ( V_2 -> V_6 ,
L_2 ,
V_25 , V_23 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = F_5 ( V_2 , V_11 ) ;
V_10 &= ~ V_22 ;
F_1 ( V_2 , V_10 , V_11 ) ;
F_9 () ;
if ( F_15 ( V_2 , V_23 , V_24 , 0 ) ) {
F_3 ( V_2 -> V_6 ,
L_2 ,
V_25 , V_23 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
int V_19 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_28 = V_29 ;
V_2 -> V_30 = V_27 ;
V_2 -> V_31 = V_27 ;
V_2 -> V_32 = V_27 ;
V_2 -> V_33 = V_27 ;
V_2 -> V_34 = V_27 ;
V_2 -> V_35 = V_27 ;
V_2 -> V_36 = V_27 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_37 ; V_19 ++ ) {
V_2 -> V_38 [ V_19 ] = 0x0 ;
V_2 -> V_39 [ V_19 ] = V_27 ;
V_2 -> V_40 [ V_19 ] = V_27 ;
V_2 -> V_41 [ V_19 ] = 0x0 ;
}
V_2 -> V_42 = 0x0 ;
V_2 -> V_43 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_44 ; V_19 ++ ) {
V_2 -> V_45 [ V_19 ] = 0x0 ;
V_2 -> V_46 [ V_19 ] = 0x0 ;
}
V_2 -> V_47 = 0x0 ;
}
static void F_21 ( void * V_8 )
{
int V_19 ;
T_1 V_10 ;
struct V_1 * V_2 = V_8 ;
F_22 ( V_2 -> V_7 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_8 ( V_2 ) ;
F_18 ( V_2 ) ;
V_10 = F_5 ( V_2 , V_11 ) ;
V_10 &= ( V_12 | V_22 ) ;
V_10 |= V_2 -> V_48 ;
F_1 ( V_2 , V_2 -> V_49 | V_10 , V_11 ) ;
F_1 ( V_2 , V_2 -> V_26 , V_50 ) ;
F_1 ( V_2 , V_2 -> V_51 , V_52 ) ;
F_1 ( V_2 , V_2 -> V_28 , V_53 ) ;
F_1 ( V_2 , V_2 -> V_54 , V_55 ) ;
F_1 ( V_2 , V_2 -> V_56 , V_57 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_58 ; V_19 ++ ) {
F_1 ( V_2 , V_2 -> V_59 [ V_19 ] , F_23 ( V_19 ) ) ;
F_1 ( V_2 , V_2 -> V_60 [ V_19 ] , F_24 ( V_19 ) ) ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_37 ; V_19 ++ ) {
F_1 ( V_2 , V_2 -> V_38 [ V_19 ] , F_25 ( V_19 ) ) ;
F_1 ( V_2 , V_2 -> V_39 [ V_19 ] , F_26 ( V_19 ) ) ;
F_1 ( V_2 , V_2 -> V_40 [ V_19 ] ,
F_27 ( V_19 ) ) ;
F_1 ( V_2 , V_2 -> V_41 [ V_19 ] , F_28 ( V_19 ) ) ;
}
F_1 ( V_2 , V_2 -> V_30 , V_61 ) ;
F_1 ( V_2 , V_2 -> V_31 , V_62 ) ;
F_1 ( V_2 , V_2 -> V_32 , V_63 ) ;
F_1 ( V_2 , V_2 -> V_33 , V_64 ) ;
F_1 ( V_2 , V_2 -> V_34 , V_65 ) ;
F_1 ( V_2 , V_2 -> V_35 , V_66 ) ;
F_1 ( V_2 , V_2 -> V_42 , V_67 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_68 ; V_19 ++ )
F_1 ( V_2 , V_27 , F_29 ( V_19 ) ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_44 ; V_19 ++ )
F_1 ( V_2 , V_2 -> V_45 [ V_19 ] , F_30 ( V_19 ) ) ;
F_1 ( V_2 , V_2 -> V_47 , V_69 ) ;
F_1 ( V_2 , V_2 -> V_70 , V_71 ) ;
F_1 ( V_2 , 0x0 , V_72 ) ;
F_1 ( V_2 , V_2 -> V_36 , V_73 ) ;
F_1 ( V_2 , 0x0 , V_74 ) ;
F_1 ( V_2 , V_2 -> V_75 , V_76 ) ;
F_1 ( V_2 , 0x0 , V_77 ) ;
F_1 ( V_2 , V_2 -> V_49 | V_78 | V_10 , V_11 ) ;
F_19 ( V_2 ) ;
F_31 ( V_2 -> V_7 ) ;
F_32 ( V_2 -> V_6 , L_3 , V_2 -> V_79 ) ;
}
static int F_33 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_34 ( V_81 -> V_6 . V_82 ) ;
unsigned long V_83 ;
int V_84 = - 1 ;
if ( ! V_2 -> V_85 )
return V_2 -> V_75 ;
F_35 ( V_81 -> V_6 . V_82 ) ;
F_36 ( & V_2 -> V_86 , V_83 ) ;
F_22 ( V_2 -> V_7 ) ;
V_84 = ( F_5 ( V_2 , V_76 ) & V_87 ) ;
F_31 ( V_2 -> V_7 ) ;
F_37 ( & V_2 -> V_86 , V_83 ) ;
F_38 ( V_81 -> V_6 . V_82 ) ;
return V_84 ;
}
static int F_39 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_34 ( V_81 -> V_6 . V_82 ) ;
int V_88 ;
F_35 ( V_81 -> V_6 . V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
if ( F_41 ( V_2 -> V_79 ) ) {
V_88 = F_42 ( V_2 -> V_79 ,
F_21 , V_2 , 1 ) ;
if ( V_88 )
goto V_89;
}
V_2 -> V_85 = true ;
V_2 -> V_90 = true ;
F_43 ( & V_2 -> V_86 ) ;
F_44 ( V_2 -> V_6 , L_4 ) ;
return 0 ;
V_89:
F_43 ( & V_2 -> V_86 ) ;
F_38 ( V_81 -> V_6 . V_82 ) ;
return V_88 ;
}
static void F_45 ( void * V_8 )
{
int V_19 ;
struct V_1 * V_2 = V_8 ;
F_22 ( V_2 -> V_7 ) ;
F_18 ( V_2 ) ;
F_1 ( V_2 , V_29 | V_91 , V_53 ) ;
V_2 -> V_42 = ( F_5 ( V_2 , V_67 ) & V_92 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_37 ; V_19 ++ )
V_2 -> V_41 [ V_19 ] = F_5 ( V_2 , F_28 ( V_19 ) ) ;
F_10 ( V_2 ) ;
F_31 ( V_2 -> V_7 ) ;
F_32 ( V_2 -> V_6 , L_5 , V_2 -> V_79 ) ;
}
static void F_46 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_34 ( V_81 -> V_6 . V_82 ) ;
F_47 () ;
F_40 ( & V_2 -> V_86 ) ;
F_42 ( V_2 -> V_79 , F_45 , V_2 , 1 ) ;
V_2 -> V_85 = false ;
F_43 ( & V_2 -> V_86 ) ;
F_48 () ;
F_38 ( V_81 -> V_6 . V_82 ) ;
F_44 ( V_2 -> V_6 , L_6 ) ;
}
static T_2 F_49 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_58 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_50 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{ unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_37 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_51 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_44 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_52 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_83 , V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_35 ( V_2 -> V_6 ) ;
F_36 ( & V_2 -> V_86 , V_83 ) ;
F_22 ( V_2 -> V_7 ) ;
V_3 = F_5 ( V_2 , V_23 ) ;
F_31 ( V_2 -> V_7 ) ;
F_37 ( & V_2 -> V_86 , V_83 ) ;
F_38 ( V_2 -> V_6 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_53 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_19 , V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
if ( V_3 ) {
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_98 = V_99 ;
V_2 -> V_49 = 0x0 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_51 = 0x0 ;
V_2 -> V_100 = 0x0 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_58 ; V_19 ++ ) {
V_2 -> V_59 [ V_19 ] = 0x0 ;
V_2 -> V_60 [ V_19 ] = 0x0 ;
V_2 -> V_101 [ V_19 ] = V_102 ;
}
V_2 -> V_103 = 0x0 ;
F_20 ( V_2 ) ;
F_43 ( & V_2 -> V_86 ) ;
}
return V_97 ;
}
static T_2 F_55 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_98 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_56 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_98 = V_3 & V_104 ;
if ( V_2 -> V_98 & V_99 )
V_2 -> V_54 |= V_105 ;
else
V_2 -> V_54 &= ~ V_105 ;
if ( V_2 -> V_98 & V_106 )
V_2 -> V_49 |= V_107 ;
else
V_2 -> V_49 &= ~ V_107 ;
if ( V_2 -> V_98 & V_108 ) {
if ( ! ( V_2 -> V_109 & V_110 ) ) {
F_57 ( V_2 -> V_6 , L_8 ) ;
V_88 = - V_111 ;
goto V_112;
}
V_2 -> V_49 |= V_113 ;
} else
V_2 -> V_49 &= ~ V_113 ;
if ( V_2 -> V_98 & V_114 ) {
if ( ! ( V_2 -> V_115 & V_116 ) ) {
F_57 ( V_2 -> V_6 , L_9 ) ;
V_88 = - V_111 ;
goto V_112;
}
V_2 -> V_49 |= V_117 ;
} else
V_2 -> V_49 &= ~ V_117 ;
if ( V_2 -> V_98 & V_118 )
V_2 -> V_49 |= V_119 ;
else
V_2 -> V_49 &= ~ V_119 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
V_112:
F_43 ( & V_2 -> V_86 ) ;
return V_88 ;
}
static T_2 F_58 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_26 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_59 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_26 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_60 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_28 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_61 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_28 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_62 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_56 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_63 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_56 = V_3 ;
return V_97 ;
}
static T_2 F_64 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_100 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_65 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
if ( V_3 >= V_2 -> V_58 )
return - V_111 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_100 = V_3 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_66 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
T_4 V_121 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( ! ( V_2 -> V_101 [ V_121 ] == V_102 ||
V_2 -> V_101 [ V_121 ] == V_122 ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_111 ;
}
V_3 = V_2 -> V_59 [ V_121 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_67 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
T_4 V_121 ;
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( ! ( V_2 -> V_101 [ V_121 ] == V_102 ||
V_2 -> V_101 [ V_121 ] == V_122 ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_111 ;
}
V_2 -> V_59 [ V_121 ] = V_3 ;
V_2 -> V_101 [ V_121 ] = V_122 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_68 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
T_4 V_121 ;
unsigned long V_123 , V_124 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( V_121 % 2 != 0 ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
if ( ! ( ( V_2 -> V_101 [ V_121 ] == V_102 &&
V_2 -> V_101 [ V_121 + 1 ] == V_102 ) ||
( V_2 -> V_101 [ V_121 ] == V_126 &&
V_2 -> V_101 [ V_121 + 1 ] == V_126 ) ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
V_123 = V_2 -> V_59 [ V_121 ] ;
V_124 = V_2 -> V_59 [ V_121 + 1 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_10 , V_123 , V_124 ) ;
}
static T_2 F_69 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
T_4 V_121 ;
unsigned long V_123 , V_124 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
if ( sscanf ( V_96 , L_11 , & V_123 , & V_124 ) != 2 )
return - V_111 ;
if ( V_123 > V_124 )
return - V_111 ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( V_121 % 2 != 0 ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
if ( ! ( ( V_2 -> V_101 [ V_121 ] == V_102 &&
V_2 -> V_101 [ V_121 + 1 ] == V_102 ) ||
( V_2 -> V_101 [ V_121 ] == V_126 &&
V_2 -> V_101 [ V_121 + 1 ] == V_126 ) ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
V_2 -> V_59 [ V_121 ] = V_123 ;
V_2 -> V_101 [ V_121 ] = V_126 ;
V_2 -> V_59 [ V_121 + 1 ] = V_124 ;
V_2 -> V_101 [ V_121 + 1 ] = V_126 ;
V_2 -> V_54 |= ( 1 << ( V_121 / 2 ) ) ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_70 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
T_4 V_121 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( ! ( V_2 -> V_101 [ V_121 ] == V_102 ||
V_2 -> V_101 [ V_121 ] == V_127 ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
V_3 = V_2 -> V_59 [ V_121 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_71 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
T_4 V_121 ;
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( ! ( V_2 -> V_101 [ V_121 ] == V_102 ||
V_2 -> V_101 [ V_121 ] == V_127 ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
V_2 -> V_59 [ V_121 ] = V_3 ;
V_2 -> V_101 [ V_121 ] = V_127 ;
V_2 -> V_51 |= ( 1 << V_121 ) ;
V_2 -> V_54 |= F_16 ( 25 ) ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_72 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
T_4 V_121 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( ! ( V_2 -> V_101 [ V_121 ] == V_102 ||
V_2 -> V_101 [ V_121 ] == V_128 ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
V_3 = V_2 -> V_59 [ V_121 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_73 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
T_4 V_121 ;
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_121 = V_2 -> V_100 ;
if ( ! ( V_2 -> V_101 [ V_121 ] == V_102 ||
V_2 -> V_101 [ V_121 ] == V_128 ) ) {
F_43 ( & V_2 -> V_86 ) ;
return - V_125 ;
}
V_2 -> V_59 [ V_121 ] = V_3 ;
V_2 -> V_101 [ V_121 ] = V_128 ;
V_2 -> V_51 |= ( 1 << ( V_121 + 16 ) ) ;
V_2 -> V_54 |= V_129 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_74 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_3 = V_2 -> V_60 [ V_2 -> V_100 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_75 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_60 [ V_2 -> V_100 ] = V_3 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_76 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_103 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_77 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
if ( V_3 >= V_2 -> V_37 )
return - V_111 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_103 = V_3 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_78 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_3 = V_2 -> V_38 [ V_2 -> V_103 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_79 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_38 [ V_2 -> V_103 ] = V_3 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_80 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_3 = V_2 -> V_39 [ V_2 -> V_103 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_81 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_39 [ V_2 -> V_103 ] = V_3 & V_120 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_82 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_3 = V_2 -> V_40 [ V_2 -> V_103 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_83 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_40 [ V_2 -> V_103 ] = V_3 & V_120 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_84 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
int V_19 , V_88 = 0 ;
T_1 V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
if ( ! V_2 -> V_85 ) {
F_40 ( & V_2 -> V_86 ) ;
for ( V_19 = 0 ; V_19 < V_2 -> V_37 ; V_19 ++ )
V_88 += sprintf ( V_96 , L_12 ,
V_19 , V_2 -> V_41 [ V_19 ] ) ;
F_43 ( & V_2 -> V_86 ) ;
return V_88 ;
}
for ( V_19 = 0 ; V_19 < V_2 -> V_37 ; V_19 ++ ) {
V_3 = F_5 ( V_2 , F_28 ( V_19 ) ) ;
V_88 += sprintf ( V_96 , L_12 , V_19 , V_3 ) ;
}
return V_88 ;
}
static T_2 F_85 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_41 [ V_2 -> V_103 ] = V_3 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_86 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_30 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_87 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_30 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_88 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_31 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_89 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_31 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_90 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_32 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_91 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_32 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_92 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_33 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_93 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_33 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_94 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_34 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_95 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_34 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_96 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_35 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_97 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_35 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_98 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 , V_83 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
if ( ! V_2 -> V_85 ) {
V_3 = V_2 -> V_42 ;
goto V_130;
}
F_35 ( V_2 -> V_6 ) ;
F_36 ( & V_2 -> V_86 , V_83 ) ;
F_22 ( V_2 -> V_7 ) ;
V_3 = ( F_5 ( V_2 , V_67 ) & V_92 ) ;
F_31 ( V_2 -> V_7 ) ;
F_37 ( & V_2 -> V_86 , V_83 ) ;
F_38 ( V_2 -> V_6 ) ;
V_130:
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_99 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
if ( V_3 > V_131 )
return - V_111 ;
V_2 -> V_42 = V_3 ;
return V_97 ;
}
static T_2 F_100 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_43 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_101 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
if ( V_3 >= V_2 -> V_44 )
return - V_111 ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_43 = V_3 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_102 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_3 = V_2 -> V_46 [ V_2 -> V_43 ] ;
F_43 ( & V_2 -> V_86 ) ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_103 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_132 , V_133 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_132 ) ;
if ( V_88 )
return V_88 ;
V_133 = F_104 ( V_132 ) ;
F_40 ( & V_2 -> V_86 ) ;
V_2 -> V_45 [ V_2 -> V_43 ] = V_133 ;
V_2 -> V_46 [ V_2 -> V_43 ] = V_132 ;
F_43 ( & V_2 -> V_86 ) ;
return V_97 ;
}
static T_2 F_105 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_47 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_106 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_47 = V_3 ;
return V_97 ;
}
static T_2 F_107 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_70 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_108 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_70 = V_3 & V_134 ;
return V_97 ;
}
static T_2 F_109 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_36 ;
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_110 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_36 = V_3 & V_120 ;
return V_97 ;
}
static T_2 F_111 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
int V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_3 = V_2 -> V_79 ;
return F_112 ( V_96 , V_135 , L_13 , V_3 ) ;
}
static T_2 F_113 ( struct V_93 * V_6 ,
struct V_94 * V_95 , char * V_96 )
{
unsigned long V_3 , V_83 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
if ( ! V_2 -> V_85 ) {
V_3 = V_2 -> V_75 ;
goto V_130;
}
F_35 ( V_2 -> V_6 ) ;
F_36 ( & V_2 -> V_86 , V_83 ) ;
F_22 ( V_2 -> V_7 ) ;
V_3 = ( F_5 ( V_2 , V_76 ) & V_87 ) ;
F_31 ( V_2 -> V_7 ) ;
F_37 ( & V_2 -> V_86 , V_83 ) ;
F_38 ( V_2 -> V_6 ) ;
V_130:
return sprintf ( V_96 , L_7 , V_3 ) ;
}
static T_2 F_114 ( struct V_93 * V_6 ,
struct V_94 * V_95 ,
const char * V_96 , T_3 V_97 )
{
int V_88 ;
unsigned long V_3 ;
struct V_1 * V_2 = F_34 ( V_6 -> V_82 ) ;
V_88 = F_54 ( V_96 , 16 , & V_3 ) ;
if ( V_88 )
return V_88 ;
V_2 -> V_75 = V_3 & V_87 ;
return V_97 ;
}
static int F_115 ( struct V_136 * V_137 , unsigned long V_138 ,
void * V_139 )
{
unsigned int V_79 = ( unsigned long ) V_139 ;
if ( ! V_140 [ V_79 ] )
goto V_130;
switch ( V_138 & ( ~ V_141 ) ) {
case V_142 :
F_40 ( & V_140 [ V_79 ] -> V_86 ) ;
if ( ! V_140 [ V_79 ] -> V_143 ) {
F_8 ( V_140 [ V_79 ] ) ;
V_140 [ V_79 ] -> V_143 = true ;
}
if ( V_140 [ V_79 ] -> V_85 )
F_21 ( V_140 [ V_79 ] ) ;
F_43 ( & V_140 [ V_79 ] -> V_86 ) ;
break;
case V_144 :
if ( V_140 [ V_79 ] -> V_145 &&
! V_140 [ V_79 ] -> V_90 )
F_116 ( V_140 [ V_79 ] -> V_81 ) ;
break;
case V_146 :
F_40 ( & V_140 [ V_79 ] -> V_86 ) ;
if ( V_140 [ V_79 ] -> V_85 )
F_45 ( V_140 [ V_79 ] ) ;
F_43 ( & V_140 [ V_79 ] -> V_86 ) ;
break;
}
V_130:
return V_147 ;
}
static bool F_117 ( T_4 V_148 )
{
switch ( V_148 ) {
case V_149 :
break;
case V_150 :
break;
case V_151 :
break;
case V_152 :
break;
default:
return false ;
}
return true ;
}
static void F_118 ( void * V_8 )
{
T_1 V_153 ;
T_1 V_109 ;
struct V_1 * V_2 = V_8 ;
F_22 ( V_2 -> V_7 ) ;
( void ) F_5 ( V_2 , V_154 ) ;
F_13 ( V_2 ) ;
F_12 ( V_2 ) ;
F_18 ( V_2 ) ;
V_153 = F_5 ( V_2 , V_155 ) ;
V_2 -> V_148 = F_119 ( V_153 , 4 , 11 ) ;
V_2 -> V_48 = F_5 ( V_2 , V_11 ) & V_156 ;
V_2 -> V_115 = F_5 ( V_2 , V_157 ) ;
V_109 = F_5 ( V_2 , V_158 ) ;
V_2 -> V_109 = V_109 ;
V_2 -> V_58 = F_119 ( V_109 , 0 , 3 ) * 2 ;
V_2 -> V_37 = F_119 ( V_109 , 13 , 15 ) ;
V_2 -> V_159 = F_119 ( V_109 , 17 , 19 ) ;
V_2 -> V_68 = F_119 ( V_109 , 20 , 22 ) ;
V_2 -> V_44 = F_119 ( V_109 , 24 , 25 ) ;
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
F_31 ( V_2 -> V_7 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
static int V_160 = 0x10 ;
T_1 V_83 = ( 1 << 0 |
3 << 3 |
0 << 5 |
0 << 7 |
0 << 8 |
0 << 10 ) ;
V_2 -> V_75 = V_160 ++ ;
V_2 -> V_49 = ( V_107 | V_117 ) ;
V_2 -> V_54 = V_161 ;
if ( V_2 -> V_58 >= 2 ) {
V_2 -> V_59 [ 0 ] = ( T_1 ) V_162 ;
V_2 -> V_59 [ 1 ] = ( T_1 ) V_163 ;
V_2 -> V_60 [ 0 ] = V_83 ;
V_2 -> V_60 [ 1 ] = V_83 ;
V_2 -> V_101 [ 0 ] = V_126 ;
V_2 -> V_101 [ 1 ] = V_126 ;
}
F_20 ( V_2 ) ;
}
static int F_121 ( struct V_164 * V_165 , const struct V_166 * V_167 )
{
int V_88 ;
void T_5 * V_7 ;
struct V_93 * V_6 = & V_165 -> V_6 ;
struct V_168 * V_169 = NULL ;
struct V_1 * V_2 ;
struct V_170 * V_171 = & V_165 -> V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 = V_165 -> V_6 . V_176 ;
V_173 = F_122 ( V_6 , sizeof( * V_173 ) , V_177 ) ;
if ( ! V_173 )
return - V_178 ;
V_2 = F_122 ( V_6 , sizeof( * V_2 ) , V_177 ) ;
if ( ! V_2 )
return - V_178 ;
if ( V_175 ) {
V_169 = F_123 ( V_6 , V_175 ) ;
if ( F_124 ( V_169 ) )
return F_125 ( V_169 ) ;
V_165 -> V_6 . V_179 = V_169 ;
V_2 -> V_5 = F_126 ( V_175 , L_14 ) ;
}
V_2 -> V_6 = & V_165 -> V_6 ;
F_127 ( V_6 , V_2 ) ;
V_7 = F_128 ( V_6 , V_171 ) ;
if ( F_124 ( V_7 ) )
return F_125 ( V_7 ) ;
V_2 -> V_7 = V_7 ;
F_129 ( & V_2 -> V_86 ) ;
V_2 -> V_180 = F_130 ( & V_165 -> V_6 , L_15 ) ;
if ( ! F_124 ( V_2 -> V_180 ) ) {
V_88 = F_131 ( V_2 -> V_180 ) ;
if ( V_88 )
return V_88 ;
}
V_2 -> V_79 = V_169 ? V_169 -> V_79 : 0 ;
F_47 () ;
V_140 [ V_2 -> V_79 ] = V_2 ;
if ( ! F_42 ( V_2 -> V_79 , F_8 , V_2 , 1 ) )
V_2 -> V_143 = true ;
if ( F_42 ( V_2 -> V_79 ,
F_118 , V_2 , 1 ) )
F_3 ( V_6 , L_16 ) ;
if ( ! V_181 ++ )
F_132 ( & V_182 ) ;
F_48 () ;
if ( F_117 ( V_2 -> V_148 ) == false ) {
V_88 = - V_111 ;
goto V_183;
}
F_120 ( V_2 ) ;
V_173 -> type = V_184 ;
V_173 -> V_185 . V_186 = V_187 ;
V_173 -> V_188 = & V_189 ;
V_173 -> V_169 = V_169 ;
V_173 -> V_6 = V_6 ;
V_173 -> V_190 = V_191 ;
V_2 -> V_81 = F_133 ( V_173 ) ;
if ( F_124 ( V_2 -> V_81 ) ) {
V_88 = F_125 ( V_2 -> V_81 ) ;
goto V_183;
}
F_38 ( & V_165 -> V_6 ) ;
F_44 ( V_6 , L_17 , ( char * ) V_167 -> V_192 ) ;
if ( V_145 ) {
F_116 ( V_2 -> V_81 ) ;
V_2 -> V_145 = true ;
}
return 0 ;
V_183:
if ( -- V_181 == 0 )
F_134 ( & V_182 ) ;
return V_88 ;
}
static int F_135 ( struct V_164 * V_165 )
{
struct V_1 * V_2 = F_136 ( V_165 ) ;
F_137 ( V_2 -> V_81 ) ;
if ( -- V_181 == 0 )
F_134 ( & V_182 ) ;
return 0 ;
}
static int F_138 ( struct V_93 * V_6 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
if ( V_2 && ! F_124 ( V_2 -> V_180 ) )
F_139 ( V_2 -> V_180 ) ;
return 0 ;
}
static int F_140 ( struct V_93 * V_6 )
{
struct V_1 * V_2 = F_34 ( V_6 ) ;
if ( V_2 && ! F_124 ( V_2 -> V_180 ) )
F_131 ( V_2 -> V_180 ) ;
return 0 ;
}
