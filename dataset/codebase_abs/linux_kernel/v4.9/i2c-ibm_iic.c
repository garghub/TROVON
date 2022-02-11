static void F_1 ( const char * V_1 , struct V_2 * V_3 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
F_2 ( V_7 L_1 , V_3 -> V_8 , V_1 ) ;
F_2 ( V_7
L_2
L_3
L_4
L_5 ,
F_3 ( & V_5 -> V_9 ) , F_3 ( & V_5 -> V_10 ) , F_3 ( & V_5 -> V_11 ) ,
F_3 ( & V_5 -> V_12 ) , F_3 ( & V_5 -> V_13 ) , F_3 ( & V_5 -> V_14 ) ,
F_3 ( & V_5 -> V_15 ) , F_3 ( & V_5 -> V_16 ) ) ;
}
static inline void F_4 ( struct V_2 * V_3 , int V_17 )
{
F_5 ( & V_3 -> V_6 -> V_18 , V_17 ? V_19 : 0 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
F_7 ( L_6 , V_3 -> V_8 ) ;
F_5 ( & V_5 -> V_20 , 0 ) ;
F_5 ( & V_5 -> V_21 , 0 ) ;
F_5 ( & V_5 -> V_22 , 0 ) ;
F_5 ( & V_5 -> V_23 , 0 ) ;
F_5 ( & V_5 -> V_11 , V_24 | V_25 ) ;
F_5 ( & V_5 -> V_12 , V_26 | V_27 | V_28
| V_29 | V_30 ) ;
F_5 ( & V_5 -> V_13 , V_3 -> V_31 ) ;
F_5 ( & V_5 -> V_14 , 0 ) ;
F_5 ( & V_5 -> V_15 , V_32 | V_33 | V_34
| V_35 ) ;
F_5 ( & V_5 -> V_9 , 0 ) ;
F_4 ( V_3 , V_3 -> V_36 >= 0 ) ;
F_5 ( & V_5 -> V_10 , V_37 | V_38 | V_39
| ( V_3 -> V_40 ? V_41 : 0 ) ) ;
F_8 ( L_7 , V_3 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
int V_42 ;
T_2 V_43 ;
F_7 ( L_8 , V_3 -> V_8 ) ;
F_8 ( L_9 , V_3 ) ;
F_5 ( & V_5 -> V_15 , V_44 ) ;
V_43 = F_3 ( & V_5 -> V_16 ) ;
if ( ! F_10 ( V_43 ) ) {
F_7 ( L_10 , V_3 -> V_8 ) ;
F_5 ( & V_5 -> V_16 , V_45 | V_46 ) ;
for ( V_42 = 0 ; V_42 < 100 ; ++ V_42 ) {
V_43 = F_3 ( & V_5 -> V_16 ) ;
if ( F_10 ( V_43 ) )
break;
V_43 ^= V_46 ;
F_5 ( & V_5 -> V_16 , V_43 ) ;
F_11 ( 10 ) ;
V_43 ^= V_46 ;
F_5 ( & V_5 -> V_16 , V_43 ) ;
F_12 () ;
}
}
F_5 ( & V_5 -> V_15 , 0 ) ;
F_6 ( V_3 ) ;
}
static int F_13 ( volatile struct V_4 T_1 * V_5 , T_2 V_47 )
{
unsigned long V_48 = V_49 + V_50 / 28 + 2 ;
while ( ( F_3 ( & V_5 -> V_16 ) & V_47 ) != V_47 ) {
if ( F_14 ( F_15 ( V_49 , V_48 ) ) )
return - 1 ;
F_12 () ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , const struct V_51 * V_52 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
const struct V_53 * V_54 = & V_55 [ V_3 -> V_40 ? 1 : 0 ] ;
T_2 V_47 , V_56 , V_57 ;
int V_42 , V_58 ;
if ( F_14 ( V_52 -> V_59 & V_60 ) ) {
F_7 ( L_11 ,
V_3 -> V_8 ) ;
return - V_61 ;
}
F_7 ( L_12 , V_3 -> V_8 , V_52 -> V_62 ) ;
F_5 ( & V_5 -> V_15 , V_44 ) ;
F_5 ( & V_5 -> V_16 , V_45 | V_46 ) ;
if ( F_14 ( F_13 ( V_5 , V_63 | V_64 ) ) )
goto V_65;
F_17 ( V_54 -> V_66 ) ;
F_5 ( & V_5 -> V_16 , V_46 ) ;
V_57 = 0 ;
F_17 ( V_54 -> V_67 ) ;
V_56 = F_18 ( V_52 ) ;
for ( V_42 = 0 , V_47 = 0x80 ; V_42 < 8 ; ++ V_42 , V_47 >>= 1 ) {
F_5 ( & V_5 -> V_16 , V_57 ) ;
F_17 ( V_54 -> V_68 / 2 ) ;
V_57 = ( V_56 & V_47 ) ? V_45 : 0 ;
F_5 ( & V_5 -> V_16 , V_57 ) ;
F_17 ( V_54 -> V_68 / 2 ) ;
F_5 ( & V_5 -> V_16 , V_46 | V_57 ) ;
if ( F_14 ( F_13 ( V_5 , V_64 ) ) )
goto V_65;
F_17 ( V_54 -> V_69 ) ;
}
F_5 ( & V_5 -> V_16 , V_57 ) ;
F_17 ( V_54 -> V_68 / 2 ) ;
F_5 ( & V_5 -> V_16 , V_45 ) ;
F_17 ( V_54 -> V_68 / 2 ) ;
F_5 ( & V_5 -> V_16 , V_45 | V_46 ) ;
if ( F_14 ( F_13 ( V_5 , V_64 ) ) )
goto V_65;
V_58 = ( F_3 ( & V_5 -> V_16 ) & V_63 ) ? - V_70 : 1 ;
F_17 ( V_54 -> V_69 ) ;
F_5 ( & V_5 -> V_16 , 0 ) ;
F_17 ( V_54 -> V_68 ) ;
F_5 ( & V_5 -> V_16 , V_46 ) ;
if ( F_14 ( F_13 ( V_5 , V_64 ) ) )
goto V_65;
F_17 ( V_54 -> V_71 ) ;
F_5 ( & V_5 -> V_16 , V_45 | V_46 ) ;
F_17 ( V_54 -> V_66 ) ;
F_7 ( L_13 , V_3 -> V_8 , V_58 ? L_14 : L_15 ) ;
V_72:
F_5 ( & V_5 -> V_15 , 0 ) ;
F_6 ( V_3 ) ;
return V_58 ;
V_65:
F_7 ( L_16 , V_3 -> V_8 ) ;
V_58 = - V_70 ;
goto V_72;
}
static T_3 F_19 ( int V_36 , void * V_73 )
{
struct V_2 * V_3 = (struct V_2 * ) V_73 ;
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
F_20 ( L_17 ,
V_3 -> V_8 , F_3 ( & V_5 -> V_11 ) , F_3 ( & V_5 -> V_12 ) ) ;
F_5 ( & V_5 -> V_11 , V_25 | V_24 ) ;
F_21 ( & V_3 -> V_74 ) ;
return V_75 ;
}
static int F_22 ( struct V_2 * V_3 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
if ( F_14 ( F_3 ( & V_5 -> V_11 ) & V_76 ) ) {
F_7 ( L_18 , V_3 -> V_8 ,
F_3 ( & V_5 -> V_12 ) ) ;
F_5 ( & V_5 -> V_12 , V_26 | V_27 |
V_28 | V_29 | V_30 ) ;
F_5 ( & V_5 -> V_10 , F_3 ( & V_5 -> V_10 ) | V_37 ) ;
if ( ( F_3 ( & V_5 -> V_12 ) & V_77 ) != V_78 ) {
F_7 ( L_19 , V_3 -> V_8 ) ;
F_9 ( V_3 ) ;
}
return - V_70 ;
}
else
return F_3 ( & V_5 -> V_14 ) & V_79 ;
}
static void F_23 ( struct V_2 * V_3 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
unsigned long V_48 ;
F_7 ( L_20 , V_3 -> V_8 ) ;
F_5 ( & V_5 -> V_9 , V_80 ) ;
V_48 = V_49 + 2 ;
while ( ( F_3 ( & V_5 -> V_12 ) & V_77 ) != V_78 ) {
if ( F_15 ( V_49 , V_48 ) ) {
F_7 ( L_21 , V_3 -> V_8 ) ;
F_9 ( V_3 ) ;
return;
}
F_24 () ;
}
F_22 ( V_3 ) ;
}
static int F_25 ( struct V_2 * V_3 ) {
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
int V_81 = 0 ;
if ( V_3 -> V_36 >= 0 ) {
V_81 = F_26 ( V_3 -> V_74 ,
! ( F_3 ( & V_5 -> V_11 ) & V_82 ) , V_3 -> V_83 . V_84 ) ;
if ( F_14 ( V_81 < 0 ) )
F_7 ( L_22 , V_3 -> V_8 ) ;
else if ( F_14 ( F_3 ( & V_5 -> V_11 ) & V_82 ) ) {
F_7 ( L_23 , V_3 -> V_8 ) ;
V_81 = - V_85 ;
}
}
else {
unsigned long V_48 = V_49 + V_3 -> V_83 . V_84 ;
while ( F_3 ( & V_5 -> V_11 ) & V_82 ) {
if ( F_14 ( F_15 ( V_49 , V_48 ) ) ) {
F_7 ( L_24 , V_3 -> V_8 ) ;
V_81 = - V_85 ;
break;
}
if ( F_14 ( F_27 ( V_86 ) ) ) {
F_7 ( L_25 , V_3 -> V_8 ) ;
V_81 = - V_87 ;
break;
}
F_24 () ;
}
}
if ( F_14 ( V_81 < 0 ) )
F_23 ( V_3 ) ;
else
V_81 = F_22 ( V_3 ) ;
F_20 ( L_26 , V_3 -> V_8 , V_81 ) ;
return V_81 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_51 * V_88 ,
int V_89 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
char * V_66 = V_88 -> V_66 ;
int V_42 , V_90 , V_91 , V_81 = 0 ;
int V_92 = V_88 -> V_92 ;
T_2 V_9 = ( F_3 ( & V_5 -> V_9 ) & V_93 ) | V_94 ;
if ( V_88 -> V_59 & V_95 )
V_9 |= V_96 ;
V_91 = ( V_92 + 3 ) / 4 ;
for ( V_42 = 0 ; V_42 < V_91 ; ++ V_42 , V_92 -= 4 ) {
int V_97 = V_92 > 4 ? 4 : V_92 ;
T_2 V_98 = V_9 | ( ( V_97 - 1 ) << V_99 ) ;
if ( ! ( V_9 & V_96 ) )
for ( V_90 = 0 ; V_90 < V_97 ; ++ V_90 )
F_5 ( ( void T_1 * ) & V_5 -> V_100 , * V_66 ++ ) ;
if ( V_42 < V_91 - 1 )
V_98 |= V_101 ;
else if ( V_89 )
V_98 |= V_102 ;
F_20 ( L_27 , V_3 -> V_8 , V_97 , V_98 ) ;
F_5 ( & V_5 -> V_9 , V_98 ) ;
V_81 = F_25 ( V_3 ) ;
if ( F_14 ( V_81 < 0 ) )
break;
else if ( F_14 ( V_81 != V_97 ) ) {
F_7 ( L_28 ,
V_3 -> V_8 , V_97 , V_81 ) ;
if ( V_89 || ( V_42 < V_91 - 1 ) )
F_23 ( V_3 ) ;
V_81 = - V_70 ;
break;
}
if ( V_9 & V_96 )
for ( V_90 = 0 ; V_90 < V_97 ; ++ V_90 )
* V_66 ++ = F_3 ( ( void T_1 * ) & V_5 -> V_100 ) ;
}
return V_81 > 0 ? 0 : V_81 ;
}
static inline void F_29 ( struct V_2 * V_3 , struct V_51 * V_103 )
{
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
T_4 V_62 = V_103 -> V_62 ;
F_20 ( L_29 , V_3 -> V_8 ,
V_62 , V_103 -> V_59 & V_60 ? 10 : 7 ) ;
if ( V_103 -> V_59 & V_60 ) {
F_5 ( & V_5 -> V_9 , V_93 ) ;
F_5 ( & V_5 -> V_20 , V_62 ) ;
F_5 ( & V_5 -> V_21 , 0xf0 | ( ( V_62 >> 7 ) & 0x06 ) ) ;
}
else {
F_5 ( & V_5 -> V_9 , 0 ) ;
F_5 ( & V_5 -> V_20 , V_62 << 1 ) ;
}
}
static inline int F_30 ( const struct V_51 * V_52 )
{
return ( V_52 -> V_62 > 0x3ff ) || ( ! ( V_52 -> V_59 & V_60 ) && ( V_52 -> V_62 > 0x7f ) ) ;
}
static inline int F_31 ( const struct V_51 * V_104 ,
const struct V_51 * V_105 )
{
return ( V_104 -> V_62 != V_105 -> V_62 )
|| ( ( V_104 -> V_59 & V_60 ) != ( V_105 -> V_59 & V_60 ) ) ;
}
static int F_32 ( struct V_106 * V_83 , struct V_51 * V_107 , int V_108 )
{
struct V_2 * V_3 = (struct V_2 * ) ( F_33 ( V_83 ) ) ;
volatile struct V_4 T_1 * V_5 = V_3 -> V_6 ;
int V_42 , V_81 = 0 ;
F_20 ( L_30 , V_3 -> V_8 , V_108 ) ;
if ( ! V_108 )
return 0 ;
if ( F_14 ( F_30 ( & V_107 [ 0 ] ) ) ) {
F_7 ( L_31 , V_3 -> V_8 ,
V_107 [ 0 ] . V_62 , V_107 [ 0 ] . V_59 & V_60 ? 10 : 7 ) ;
return - V_61 ;
}
for ( V_42 = 0 ; V_42 < V_108 ; ++ V_42 ) {
if ( F_14 ( V_107 [ V_42 ] . V_92 <= 0 ) ) {
if ( V_108 == 1 && ! V_107 [ 0 ] . V_92 ) {
return F_16 ( V_3 , & V_107 [ 0 ] ) ;
}
F_7 ( L_32 , V_3 -> V_8 ,
V_107 [ V_42 ] . V_92 , V_42 ) ;
return - V_61 ;
}
if ( F_14 ( F_31 ( & V_107 [ 0 ] , & V_107 [ V_42 ] ) ) ) {
F_7 ( L_33 , V_3 -> V_8 , V_42 ) ;
return - V_61 ;
}
}
if ( F_14 ( ( F_3 ( & V_5 -> V_12 ) & V_77 ) != V_78 ) ) {
F_7 ( L_34 , V_3 -> V_8 ) ;
F_9 ( V_3 ) ;
if ( ( F_3 ( & V_5 -> V_12 ) & V_77 ) != V_78 ) {
F_7 ( L_35 , V_3 -> V_8 ) ;
return - V_70 ;
}
}
else {
F_5 ( & V_5 -> V_10 , F_3 ( & V_5 -> V_10 ) | V_37 ) ;
}
F_29 ( V_3 , & V_107 [ 0 ] ) ;
for ( V_42 = 0 ; V_42 < V_108 && ! V_81 ; ++ V_42 )
V_81 = F_28 ( V_3 , & V_107 [ V_42 ] , V_42 < V_108 - 1 ) ;
return V_81 < 0 ? V_81 : V_108 ;
}
static T_5 F_34 ( struct V_106 * V_83 )
{
return V_109 | V_110 | V_111 ;
}
static inline T_2 F_35 ( unsigned int V_112 )
{
if ( ! V_112 ) {
F_2 ( V_113 L_36
L_37 ) ;
V_112 = 50000000 ;
}
V_112 /= 1000000 ;
if ( V_112 < 20 || V_112 > 150 ) {
F_2 ( V_113 L_38 ,
V_112 ) ;
V_112 = V_112 < 20 ? 20 : 150 ;
}
return ( T_2 ) ( ( V_112 + 9 ) / 10 - 1 ) ;
}
static int F_36 ( struct V_114 * V_115 ,
struct V_2 * V_3 )
{
struct V_116 * V_117 = V_115 -> V_3 . V_118 ;
int V_36 ;
if ( V_119 )
return 0 ;
V_36 = F_37 ( V_117 , 0 ) ;
if ( ! V_36 ) {
F_38 ( & V_115 -> V_3 , L_39 ) ;
return 0 ;
}
F_4 ( V_3 , 0 ) ;
if ( F_39 ( V_36 , F_19 , 0 , L_40 , V_3 ) ) {
F_38 ( & V_115 -> V_3 , L_41 , V_36 ) ;
return 0 ;
}
return V_36 ;
}
static int F_40 ( struct V_114 * V_115 )
{
struct V_116 * V_117 = V_115 -> V_3 . V_118 ;
struct V_2 * V_3 ;
struct V_106 * V_83 ;
const T_5 * V_120 ;
int V_81 ;
V_3 = F_41 ( sizeof( * V_3 ) , V_121 ) ;
if ( ! V_3 ) {
F_38 ( & V_115 -> V_3 , L_42 ) ;
return - V_122 ;
}
F_42 ( V_115 , V_3 ) ;
V_3 -> V_6 = F_43 ( V_117 , 0 ) ;
if ( V_3 -> V_6 == NULL ) {
F_38 ( & V_115 -> V_3 , L_43 ) ;
V_81 = - V_123 ;
goto V_124;
}
F_44 ( & V_3 -> V_74 ) ;
V_3 -> V_36 = F_36 ( V_115 , V_3 ) ;
if ( ! V_3 -> V_36 )
F_45 ( & V_115 -> V_3 , L_44 ) ;
if ( V_125 || F_46 ( V_117 , L_45 , NULL ) )
V_3 -> V_40 = 1 ;
V_120 = F_46 ( V_117 , L_46 , NULL ) ;
if ( V_120 == NULL ) {
V_120 = F_46 ( V_117 -> V_126 , L_46 , NULL ) ;
if ( V_120 == NULL ) {
F_38 ( & V_115 -> V_3 , L_47 ) ;
V_81 = - V_61 ;
goto V_124;
}
}
V_3 -> V_31 = F_35 ( * V_120 ) ;
F_47 ( & V_115 -> V_3 , L_48 , V_3 -> V_31 ) ;
F_6 ( V_3 ) ;
V_83 = & V_3 -> V_83 ;
V_83 -> V_3 . V_126 = & V_115 -> V_3 ;
V_83 -> V_3 . V_118 = F_48 ( V_117 ) ;
F_49 ( V_83 -> V_127 , L_40 , sizeof( V_83 -> V_127 ) ) ;
F_50 ( V_83 , V_3 ) ;
V_83 -> V_128 = V_129 | V_130 ;
V_83 -> V_131 = & V_132 ;
V_83 -> V_84 = V_50 ;
V_81 = F_51 ( V_83 ) ;
if ( V_81 < 0 )
goto V_124;
F_52 ( & V_115 -> V_3 , L_49 ,
V_3 -> V_40 ? L_50 : L_51 ) ;
return 0 ;
V_124:
if ( V_3 -> V_36 ) {
F_4 ( V_3 , 0 ) ;
F_53 ( V_3 -> V_36 , V_3 ) ;
}
if ( V_3 -> V_6 )
F_54 ( V_3 -> V_6 ) ;
F_55 ( V_3 ) ;
return V_81 ;
}
static int F_56 ( struct V_114 * V_115 )
{
struct V_2 * V_3 = F_57 ( V_115 ) ;
F_58 ( & V_3 -> V_83 ) ;
if ( V_3 -> V_36 ) {
F_4 ( V_3 , 0 ) ;
F_53 ( V_3 -> V_36 , V_3 ) ;
}
F_54 ( V_3 -> V_6 ) ;
F_55 ( V_3 ) ;
return 0 ;
}
