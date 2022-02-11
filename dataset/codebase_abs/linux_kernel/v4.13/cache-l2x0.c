static inline void F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
while ( F_2 ( V_1 ) & V_2 )
F_3 () ;
}
static void F_4 ( unsigned long V_3 , void T_1 * V_4 , unsigned V_1 )
{
if ( V_3 == F_2 ( V_4 + V_1 ) )
return;
if ( V_5 . V_6 )
V_5 . V_6 ( V_3 , V_1 ) ;
else
F_5 ( V_3 , V_4 + V_1 ) ;
}
static inline void F_6 ( void T_1 * V_4 , unsigned long V_3 )
{
F_4 ( V_3 , V_4 , V_7 ) ;
}
static void F_7 ( void T_1 * V_1 )
{
F_5 ( V_8 , V_1 ) ;
F_1 ( V_1 , V_8 ) ;
}
static inline void F_8 ( void T_1 * V_4 , unsigned V_9 )
{
unsigned V_10 ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
F_5 ( 0 , V_4 + V_11 +
V_10 * V_12 ) ;
F_5 ( 0 , V_4 + V_13 +
V_10 * V_12 ) ;
}
}
static void F_9 ( void T_1 * V_4 )
{
F_4 ( V_14 . V_15 , V_4 , V_16 ) ;
}
static void F_10 ( void T_1 * V_4 , unsigned V_17 )
{
unsigned long V_18 ;
if ( V_5 . V_19 )
V_5 . V_19 ( & V_14 ) ;
else
V_20 -> V_19 ( V_4 ) ;
V_20 -> V_21 ( V_4 , V_17 ) ;
F_11 ( V_18 ) ;
F_7 ( V_4 + V_22 ) ;
F_5 ( 0 , V_4 + V_23 ) ;
F_1 ( V_4 + V_23 , 1 ) ;
F_12 ( V_18 ) ;
F_4 ( V_24 , V_4 , V_25 ) ;
}
static void F_13 ( void )
{
void T_1 * V_4 = V_26 ;
F_14 () ;
V_5 . V_27 () ;
F_4 ( 0 , V_4 , V_25 ) ;
F_15 ( V_28 ) ;
}
static void F_16 ( void T_1 * V_4 )
{
V_14 . V_15 = F_2 ( V_26 + V_16 ) ;
}
static void F_17 ( void )
{
void T_1 * V_4 = V_26 ;
if ( ! ( F_2 ( V_4 + V_25 ) & V_24 ) )
F_10 ( V_4 , V_20 -> V_17 ) ;
F_18 () ;
}
static void F_19 ( void T_1 * V_4 )
{
F_5 ( 0 , V_4 + V_23 ) ;
}
static void F_20 ( void T_1 * V_1 , unsigned long V_29 ,
unsigned long V_30 )
{
while ( V_29 < V_30 ) {
F_5 ( V_29 , V_1 ) ;
V_29 += V_31 ;
}
}
static void F_21 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
if ( V_29 & ( V_31 - 1 ) ) {
V_29 &= ~ ( V_31 - 1 ) ;
F_5 ( V_29 , V_4 + V_32 ) ;
V_29 += V_31 ;
}
if ( V_30 & ( V_31 - 1 ) ) {
V_30 &= ~ ( V_31 - 1 ) ;
F_5 ( V_30 , V_4 + V_32 ) ;
}
F_20 ( V_4 + V_33 , V_29 , V_30 ) ;
F_19 ( V_4 ) ;
}
static void F_22 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
V_29 &= ~ ( V_31 - 1 ) ;
F_20 ( V_4 + V_34 , V_29 , V_30 ) ;
F_19 ( V_4 ) ;
}
static void F_23 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
V_29 &= ~ ( V_31 - 1 ) ;
F_20 ( V_4 + V_32 , V_29 , V_30 ) ;
F_19 ( V_4 ) ;
}
static void F_24 ( void )
{
void T_1 * V_4 = V_26 ;
F_25 ( ! F_26 () ) ;
F_7 ( V_4 + V_35 ) ;
F_19 ( V_4 ) ;
}
static void F_27 ( void )
{
F_19 ( V_26 ) ;
}
static inline void F_28 ( void T_1 * V_4 )
{
F_5 ( 0 , V_4 + V_36 ) ;
F_1 ( V_4 + V_36 , 1 ) ;
}
static void F_29 ( void T_1 * V_4 , unsigned V_1 )
{
unsigned long V_18 ;
F_30 ( & V_37 , V_18 ) ;
F_7 ( V_4 + V_1 ) ;
F_28 ( V_4 ) ;
F_31 ( & V_37 , V_18 ) ;
}
static unsigned long F_32 ( void T_1 * V_1 , unsigned long V_29 ,
unsigned long V_30 , unsigned long V_18 )
{
T_2 * V_38 = & V_37 ;
while ( V_29 < V_30 ) {
unsigned long V_39 = V_29 + F_33 ( V_30 - V_29 , 4096UL ) ;
while ( V_29 < V_39 ) {
F_1 ( V_1 , 1 ) ;
F_5 ( V_29 , V_1 ) ;
V_29 += V_31 ;
}
if ( V_39 < V_30 ) {
F_31 ( V_38 , V_18 ) ;
F_30 ( V_38 , V_18 ) ;
}
}
return V_18 ;
}
static void F_34 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_30 ( & V_37 , V_18 ) ;
if ( ( V_29 | V_30 ) & ( V_31 - 1 ) ) {
if ( V_29 & ( V_31 - 1 ) ) {
V_29 &= ~ ( V_31 - 1 ) ;
F_5 ( V_29 , V_4 + V_32 ) ;
V_29 += V_31 ;
}
if ( V_30 & ( V_31 - 1 ) ) {
V_30 &= ~ ( V_31 - 1 ) ;
F_1 ( V_4 + V_32 , 1 ) ;
F_5 ( V_30 , V_4 + V_32 ) ;
}
}
V_18 = F_32 ( V_4 + V_33 ,
V_29 , V_30 , V_18 ) ;
F_1 ( V_4 + V_33 , 1 ) ;
F_28 ( V_4 ) ;
F_31 ( & V_37 , V_18 ) ;
}
static void F_35 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
V_29 &= ~ ( V_31 - 1 ) ;
if ( ( V_30 - V_29 ) >= V_40 ) {
F_29 ( V_4 , V_41 ) ;
return;
}
F_30 ( & V_37 , V_18 ) ;
V_18 = F_32 ( V_4 + V_34 ,
V_29 , V_30 , V_18 ) ;
F_1 ( V_4 + V_32 , 1 ) ;
F_28 ( V_4 ) ;
F_31 ( & V_37 , V_18 ) ;
}
static void F_36 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
V_29 &= ~ ( V_31 - 1 ) ;
if ( ( V_30 - V_29 ) >= V_40 ) {
F_29 ( V_4 , V_35 ) ;
return;
}
F_30 ( & V_37 , V_18 ) ;
V_18 = F_32 ( V_4 + V_32 ,
V_29 , V_30 , V_18 ) ;
F_1 ( V_4 + V_32 , 1 ) ;
F_28 ( V_4 ) ;
F_31 ( & V_37 , V_18 ) ;
}
static void F_37 ( void )
{
F_29 ( V_26 , V_35 ) ;
}
static void F_38 ( void )
{
unsigned long V_18 ;
F_30 ( & V_37 , V_18 ) ;
F_28 ( V_26 ) ;
F_31 ( & V_37 , V_18 ) ;
}
static void F_39 ( void T_1 * V_4 , unsigned V_17 )
{
V_14 . V_15 |= V_42 ;
F_10 ( V_4 , V_17 ) ;
}
static void F_40 ( void T_1 * V_4 , unsigned V_17 )
{
if ( F_2 ( V_4 + V_16 ) & V_42 )
F_8 ( V_4 , V_17 ) ;
}
static void F_41 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
if ( ( V_29 | V_30 ) & ( V_31 - 1 ) ) {
unsigned long V_18 ;
F_30 ( & V_37 , V_18 ) ;
F_6 ( V_4 , 0x03 ) ;
if ( V_29 & ( V_31 - 1 ) ) {
V_29 &= ~ ( V_31 - 1 ) ;
F_5 ( V_29 , V_4 + V_34 ) ;
F_5 ( V_29 , V_4 + V_33 ) ;
V_29 += V_31 ;
}
if ( V_30 & ( V_31 - 1 ) ) {
V_30 &= ~ ( V_31 - 1 ) ;
F_5 ( V_30 , V_4 + V_34 ) ;
F_5 ( V_30 , V_4 + V_33 ) ;
}
F_6 ( V_4 , 0x00 ) ;
F_31 ( & V_37 , V_18 ) ;
}
F_20 ( V_4 + V_33 , V_29 , V_30 ) ;
F_19 ( V_4 ) ;
}
static void F_42 ( unsigned long V_29 , unsigned long V_30 )
{
T_2 * V_38 = & V_37 ;
unsigned long V_18 ;
void T_1 * V_4 = V_26 ;
F_30 ( V_38 , V_18 ) ;
while ( V_29 < V_30 ) {
unsigned long V_39 = V_29 + F_33 ( V_30 - V_29 , 4096UL ) ;
F_6 ( V_4 , 0x03 ) ;
while ( V_29 < V_39 ) {
F_5 ( V_29 , V_4 + V_34 ) ;
F_5 ( V_29 , V_4 + V_33 ) ;
V_29 += V_31 ;
}
F_6 ( V_4 , 0x00 ) ;
if ( V_39 < V_30 ) {
F_31 ( V_38 , V_18 ) ;
F_30 ( V_38 , V_18 ) ;
}
}
F_31 ( V_38 , V_18 ) ;
F_19 ( V_4 ) ;
}
static void F_43 ( void )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_30 ( & V_37 , V_18 ) ;
F_6 ( V_4 , 0x03 ) ;
F_7 ( V_4 + V_35 ) ;
F_6 ( V_4 , 0x00 ) ;
F_19 ( V_4 ) ;
F_31 ( & V_37 , V_18 ) ;
}
static void T_3 F_44 ( void T_1 * V_4 )
{
unsigned V_43 ;
F_16 ( V_4 ) ;
V_14 . V_44 = F_2 ( V_4 +
V_45 ) ;
V_14 . V_46 = F_2 ( V_4 +
V_47 ) ;
V_14 . V_48 = F_2 ( V_4 +
V_49 ) ;
V_14 . V_50 = F_2 ( V_4 +
V_51 ) ;
V_43 = F_2 ( V_4 + V_52 ) &
V_53 ;
if ( V_43 >= V_54 )
V_14 . V_55 = F_2 ( V_4 +
V_56 ) ;
if ( V_43 >= V_57 )
V_14 . V_58 = F_2 ( V_4 +
V_59 ) ;
}
static void F_45 ( void T_1 * V_4 )
{
unsigned V_43 ;
F_9 ( V_4 ) ;
F_4 ( V_14 . V_44 , V_4 ,
V_45 ) ;
F_4 ( V_14 . V_46 , V_4 ,
V_47 ) ;
F_4 ( V_14 . V_48 , V_4 ,
V_49 ) ;
F_4 ( V_14 . V_50 , V_4 ,
V_51 ) ;
V_43 = F_2 ( V_4 + V_52 ) &
V_53 ;
if ( V_43 >= V_54 )
F_4 ( V_14 . V_55 , V_4 ,
V_56 ) ;
if ( V_43 >= V_57 )
F_4 ( V_14 . V_58 , V_4 ,
V_59 ) ;
}
static int F_46 ( unsigned int V_60 )
{
F_47 ( F_48 () | F_49 ( 3 ) | F_49 ( 2 ) | F_49 ( 1 ) ) ;
return 0 ;
}
static int F_50 ( unsigned int V_60 )
{
F_47 ( F_48 () & ~ ( F_49 ( 3 ) | F_49 ( 2 ) | F_49 ( 1 ) ) ) ;
return 0 ;
}
static void T_3 F_51 ( void T_1 * V_4 , unsigned V_17 )
{
unsigned V_61 = F_2 ( V_4 + V_52 ) & V_53 ;
bool V_62 = F_52 () == V_63 ;
T_4 V_64 = V_14 . V_15 ;
if ( V_61 >= V_54 ) {
if ( V_62 && ! V_65 ) {
V_64 |= V_66 ;
F_53 ( L_1 ) ;
} else if ( V_64 & V_66 ) {
F_54 ( L_2 ) ;
V_64 &= ~ V_66 ;
}
}
if ( V_62 && ! V_67 ) {
T_4 V_68 = F_2 ( V_4 + V_16 ) ;
T_4 V_69 = F_48 () ;
F_55 ( L_3 , V_69 ) ;
if ( V_69 & F_49 ( 3 ) && ! ( V_68 & V_70 ) )
F_56 ( L_4 ) ;
if ( V_64 & V_70 && ! ( V_69 & F_49 ( 3 ) ) )
F_56 ( L_5 ) ;
if ( ! ( V_64 & V_70 ) && ! V_5 . V_6 ) {
V_64 |= V_70 ;
F_53 ( L_6 ) ;
}
} else if ( V_64 & ( V_70 | V_66 ) ) {
F_56 ( L_7 ) ;
V_64 &= ~ ( V_70 | V_66 ) ;
}
V_14 . V_15 = V_64 | V_71 ;
F_10 ( V_4 , V_17 ) ;
V_64 = F_2 ( V_4 + V_16 ) ;
if ( V_64 & ( V_72 | V_73 ) ) {
T_4 V_74 = F_2 ( V_4 + V_56 ) ;
F_53 ( L_8 ,
V_64 & V_73 ? L_9 : L_10 ,
V_64 & V_72 ? L_11 : L_10 ,
1 + ( V_74 & V_75 ) ) ;
}
if ( V_61 >= V_57 ) {
T_4 V_76 ;
V_76 = F_2 ( V_4 + V_59 ) ;
F_53 ( L_12 ,
V_76 & V_77 ? L_13 : L_14 ,
V_76 & V_78 ? L_13 : L_14 ) ;
}
if ( V_64 & V_70 )
F_57 ( V_79 ,
L_15 , F_46 ,
F_50 ) ;
}
static void T_3 F_58 ( void T_1 * V_4 , T_4 V_80 ,
struct V_81 * V_82 )
{
unsigned V_43 = V_80 & V_53 ;
const char * V_83 [ 8 ] ;
unsigned V_84 = 0 ;
if ( F_59 ( V_85 ) &&
V_43 < V_54 &&
V_82 -> V_86 == F_21 ) {
V_82 -> V_86 = F_41 ;
V_82 -> V_87 = F_42 ;
V_83 [ V_84 ++ ] = L_16 ;
}
if ( F_59 ( V_88 ) &&
V_43 >= V_54 &&
V_43 < V_89 ) {
V_82 -> V_27 = F_43 ;
V_83 [ V_84 ++ ] = L_17 ;
}
if ( V_43 >= V_57 &&
V_43 < V_90 ) {
T_4 V_3 = V_14 . V_55 ;
if ( V_3 & V_91 ) {
V_3 &= ~ V_91 ;
V_14 . V_55 = V_3 ;
V_83 [ V_84 ++ ] = L_18 ;
}
}
if ( F_59 ( V_92 ) &&
V_43 == V_57 ) {
V_23 = V_93 ;
V_83 [ V_84 ++ ] = L_19 ;
}
if ( F_59 ( V_94 ) )
V_83 [ V_84 ++ ] = L_20 ;
if ( V_84 ) {
unsigned V_10 ;
F_53 ( L_21 , V_84 > 1 ? L_22 : L_23 ) ;
for ( V_10 = 0 ; V_10 < V_84 ; V_10 ++ )
F_60 ( L_24 , V_83 [ V_10 ] ) ;
F_60 ( L_25 ) ;
}
}
static void F_61 ( void )
{
if ( V_14 . V_15 & V_70 )
F_47 ( F_48 () & ~ ( F_49 ( 3 ) | F_49 ( 2 ) | F_49 ( 1 ) ) ) ;
F_13 () ;
}
static void F_62 ( void )
{
F_17 () ;
if ( V_14 . V_15 & V_70 )
F_47 ( F_48 () | F_49 ( 3 ) | F_49 ( 2 ) | F_49 ( 1 ) ) ;
}
static void F_63 ( void T_1 * V_4 , unsigned V_17 )
{
if ( F_2 ( V_4 + V_16 ) & V_71 )
F_8 ( V_4 , V_17 ) ;
}
static int T_3 F_64 ( const struct V_95 * V_96 ,
T_4 V_97 , T_4 V_98 , T_4 V_80 , bool V_99 )
{
struct V_81 V_82 ;
unsigned V_100 , V_101 ;
T_4 V_64 , V_102 ;
V_20 = F_65 ( V_96 , sizeof( * V_96 ) , V_103 ) ;
if ( ! V_20 )
return - V_104 ;
if ( V_97 & V_98 )
F_66 ( L_26 ) ;
V_102 = V_64 = F_2 ( V_26 + V_16 ) ;
V_64 &= V_98 ;
V_64 |= V_97 ;
if ( V_102 != V_64 )
F_54 ( L_27 ,
V_102 , V_64 ) ;
switch ( V_80 & V_105 ) {
case V_106 :
if ( ( V_97 | ~ V_98 ) & ( V_107 | V_108 ) )
F_54 ( L_28 ) ;
if ( V_64 & ( 1 << 16 ) )
V_101 = 16 ;
else
V_101 = 8 ;
break;
case V_109 :
case V_110 :
V_101 = ( V_64 >> 13 ) & 0xf ;
break;
case V_111 :
V_101 = ( V_64 >> 13 ) & 0xf ;
V_101 = 2 << ( ( V_101 + 1 ) >> 2 ) ;
break;
default:
V_101 = 8 ;
break;
}
V_8 = ( 1 << V_101 ) - 1 ;
V_100 = ( V_64 & V_107 ) >>
V_112 ;
V_40 = V_101 * ( V_96 -> V_113 << V_100 ) ;
V_82 = V_96 -> V_5 ;
V_82 . V_6 = V_5 . V_6 ;
V_82 . V_19 = V_5 . V_19 ;
if ( V_96 -> V_114 )
V_96 -> V_114 ( V_26 , V_80 , & V_82 ) ;
if ( V_99 ) {
F_53 ( L_29 ) ;
V_82 . V_115 = NULL ;
}
if ( ! ( F_2 ( V_26 + V_25 ) & V_24 ) ) {
V_14 . V_15 = V_64 ;
V_96 -> V_116 ( V_26 , V_96 -> V_17 ) ;
}
V_5 = V_82 ;
if ( V_96 -> V_117 )
V_96 -> V_117 ( V_26 ) ;
V_64 = F_2 ( V_26 + V_16 ) ;
F_53 ( L_30 ,
V_96 -> type , V_101 , V_40 >> 10 ) ;
F_53 ( L_31 ,
V_96 -> type , V_80 , V_64 ) ;
F_67 ( V_26 , V_80 ) ;
return 0 ;
}
void T_3 F_68 ( void T_1 * V_4 , T_4 V_97 , T_4 V_98 )
{
const struct V_95 * V_96 ;
T_4 V_80 ;
V_26 = V_4 ;
V_80 = F_2 ( V_4 + V_52 ) ;
switch ( V_80 & V_105 ) {
default:
case V_109 :
V_96 = & V_118 ;
break;
case V_110 :
V_96 = & V_119 ;
break;
case V_106 :
V_96 = & V_120 ;
break;
}
if ( V_96 -> V_117 )
V_96 -> V_117 ( V_26 ) ;
F_64 ( V_96 , V_97 , V_98 , V_80 , false ) ;
}
static int T_3 F_69 ( const struct V_121 * V_122 ,
T_4 * V_97 , T_4 * V_98 ,
T_4 * V_123 ,
T_4 V_124 )
{
T_4 V_2 = 0 , V_3 = 0 ;
T_4 V_125 = 0 , V_126 = 0 ;
T_4 V_100 = 1 ;
T_4 V_127 = 0 ;
T_4 V_128 = 0 ;
T_4 V_129 = 0 ;
F_70 ( V_122 , L_32 , & V_125 ) ;
F_70 ( V_122 , L_33 , & V_126 ) ;
F_70 ( V_122 , L_34 , & V_128 ) ;
F_70 ( V_122 , L_35 , & V_129 ) ;
if ( ! V_125 || ! V_126 )
return - V_130 ;
if ( ! V_129 ) {
if ( V_128 ) {
V_129 = V_128 ;
} else {
F_54 ( L_36
L_37 ,
V_31 ) ;
V_129 = V_31 ;
}
}
if ( V_129 != V_31 )
F_54 ( L_38
L_39 ,
V_129 ,
V_31 ) ;
V_127 = V_126 * V_129 ;
* V_123 = V_125 / V_127 ;
if ( V_127 > V_124 ) {
F_56 ( L_40 , V_127 ) ;
return - V_131 ;
}
F_53 ( L_41 ,
V_125 , V_125 >> 10 ) ;
F_53 ( L_42 , V_129 ) ;
F_53 ( L_43 ,
V_127 , V_127 >> 10 ) ;
F_53 ( L_44 , * V_123 ) ;
V_100 = F_71 ( V_127 >> 10 ) - 3 ;
if ( V_100 < 1 || V_100 > 6 ) {
F_56 ( L_45 ,
V_127 ) ;
return - V_131 ;
}
V_2 |= V_107 ;
V_3 |= ( V_100 << V_112 ) ;
* V_97 &= ~ V_2 ;
* V_97 |= V_3 ;
* V_98 &= ~ V_2 ;
return 0 ;
}
static void T_3 F_72 ( const struct V_121 * V_122 ,
T_4 * V_97 , T_4 * V_98 )
{
T_4 V_96 [ 2 ] = { 0 , 0 } ;
T_4 V_132 = 0 ;
T_4 V_133 = 0 ;
T_4 V_3 = 0 , V_2 = 0 ;
T_4 V_134 ;
int V_135 ;
F_70 ( V_122 , L_46 , & V_132 ) ;
if ( V_132 ) {
V_2 |= V_136 ;
V_3 |= ( V_132 - 1 ) << V_137 ;
}
F_73 ( V_122 , L_47 ,
V_96 , F_74 ( V_96 ) ) ;
if ( V_96 [ 0 ] && V_96 [ 1 ] ) {
V_2 |= V_138 |
V_139 ;
V_3 |= ( ( V_96 [ 0 ] - 1 ) << V_140 ) |
( ( V_96 [ 1 ] - 1 ) << V_141 ) ;
}
F_70 ( V_122 , L_48 , & V_133 ) ;
if ( V_133 ) {
V_2 |= V_142 ;
V_3 |= ( V_133 - 1 ) << V_143 ;
}
if ( F_75 ( V_122 , L_49 ) ) {
V_2 &= ~ V_144 ;
V_3 |= V_144 ;
} else if ( F_75 ( V_122 , L_50 ) ) {
V_2 &= ~ V_144 ;
}
if ( F_75 ( V_122 , L_51 ) ) {
V_2 &= ~ V_145 ;
V_3 |= V_145 ;
}
V_135 = F_69 ( V_122 , V_97 , V_98 , & V_134 , V_146 ) ;
if ( V_135 )
return;
if ( V_134 > 8 ) {
F_56 ( L_52 ) ;
F_56 ( L_53 , V_134 ) ;
} else {
V_2 |= V_147 ;
V_3 |= ( V_134 << V_148 ) ;
}
* V_97 &= ~ V_2 ;
* V_97 |= V_3 ;
* V_98 &= ~ V_2 ;
}
static void T_3 F_76 ( const struct V_121 * V_122 ,
T_4 * V_97 , T_4 * V_98 )
{
T_4 V_96 [ 3 ] = { 0 , 0 , 0 } ;
T_4 V_132 [ 3 ] = { 0 , 0 , 0 } ;
T_4 V_149 [ 2 ] = { 0 , 0 } ;
T_4 V_134 ;
T_4 V_74 ;
T_4 V_150 ;
T_4 V_3 ;
int V_135 ;
F_73 ( V_122 , L_46 , V_132 , F_74 ( V_132 ) ) ;
if ( V_132 [ 0 ] && V_132 [ 1 ] && V_132 [ 2 ] )
V_14 . V_44 =
F_77 ( V_132 [ 0 ] - 1 ) |
F_78 ( V_132 [ 1 ] - 1 ) |
F_79 ( V_132 [ 2 ] - 1 ) ;
F_73 ( V_122 , L_47 ,
V_96 , F_74 ( V_96 ) ) ;
if ( V_96 [ 0 ] && V_96 [ 1 ] && V_96 [ 2 ] )
V_14 . V_46 =
F_77 ( V_96 [ 0 ] - 1 ) |
F_78 ( V_96 [ 1 ] - 1 ) |
F_79 ( V_96 [ 2 ] - 1 ) ;
F_73 ( V_122 , L_54 ,
V_149 , F_74 ( V_149 ) ) ;
if ( V_149 [ 1 ] ) {
V_14 . V_48 =
F_80 ( V_149 [ 0 ] + V_149 [ 1 ] , V_151 ) ;
V_14 . V_50 = ( V_149 [ 0 ] & ~ ( V_151 - 1 ) )
| V_152 ;
}
V_135 = F_69 ( V_122 , V_97 , V_98 , & V_134 , V_153 ) ;
if ( ! V_135 ) {
switch ( V_134 ) {
case 16 :
* V_97 &= ~ V_147 ;
* V_97 |= V_108 ;
* V_98 &= ~ V_147 ;
break;
case 8 :
* V_97 &= ~ V_147 ;
* V_98 &= ~ V_147 ;
break;
default:
F_56 ( L_55 ,
V_134 ) ;
break;
}
}
if ( F_75 ( V_122 , L_51 ) ) {
* V_97 |= V_145 ;
* V_98 &= ~ V_145 ;
}
if ( F_75 ( V_122 , L_49 ) ) {
* V_97 |= V_144 ;
* V_98 &= ~ V_144 ;
} else if ( F_75 ( V_122 , L_50 ) ) {
* V_97 &= ~ V_144 ;
* V_98 &= ~ V_144 ;
}
if ( F_75 ( V_122 , L_56 ) )
V_65 = true ;
if ( F_75 ( V_122 , L_57 ) )
V_67 = true ;
V_74 = V_14 . V_55 ;
V_135 = F_70 ( V_122 , L_58 , & V_3 ) ;
if ( V_135 == 0 ) {
if ( V_3 )
V_74 |= V_91 ;
else
V_74 &= ~ V_91 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_59 ) ;
}
V_135 = F_70 ( V_122 , L_60 , & V_3 ) ;
if ( V_135 == 0 ) {
if ( V_3 )
V_74 |= V_154 ;
else
V_74 &= ~ V_154 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_61 ) ;
}
V_135 = F_70 ( V_122 , L_62 , & V_3 ) ;
if ( V_135 == 0 ) {
if ( ! V_3 )
V_74 |= V_155 ;
else
V_74 &= ~ V_155 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_63 ) ;
}
V_135 = F_70 ( V_122 , L_64 , & V_3 ) ;
if ( V_135 == 0 ) {
if ( V_3 )
V_74 |= V_156 ;
else
V_74 &= ~ V_156 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_65 ) ;
}
V_135 = F_70 ( V_122 , L_66 , & V_3 ) ;
if ( V_135 == 0 ) {
V_74 &= ~ V_75 ;
V_74 |= V_3 & V_75 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_67 ) ;
}
V_135 = F_70 ( V_122 , L_68 , & V_3 ) ;
if ( V_135 == 0 ) {
if ( V_3 )
V_74 |= V_157 ;
else
V_74 &= ~ V_157 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_69 ) ;
}
V_135 = F_70 ( V_122 , L_70 , & V_3 ) ;
if ( V_135 == 0 ) {
if ( V_3 )
V_74 |= V_158 ;
else
V_74 &= ~ V_158 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_71 ) ;
}
V_14 . V_55 = V_74 ;
V_150 = V_14 . V_58 |
V_77 | V_78 ;
V_135 = F_70 ( V_122 , L_72 , & V_3 ) ;
if ( ! V_135 ) {
if ( ! V_3 )
V_150 &= ~ V_77 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_73 ) ;
}
V_135 = F_70 ( V_122 , L_74 , & V_3 ) ;
if ( ! V_135 ) {
if ( ! V_3 )
V_150 &= ~ V_78 ;
} else if ( V_135 != - V_131 ) {
F_56 ( L_75 ) ;
}
V_14 . V_58 = V_150 ;
}
static unsigned long F_81 ( unsigned long V_29 , unsigned long V_30 )
{
if ( V_30 > V_29 + V_159 )
V_30 = V_29 + V_159 ;
if ( V_30 > F_82 ( V_29 + 1 ) )
V_30 = F_82 ( V_29 + 1 ) ;
return V_30 ;
}
static void F_83 ( unsigned long V_29 , unsigned long V_30 ,
unsigned long V_160 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_161 ;
unsigned long V_18 ;
V_29 &= ~ ( V_31 - 1 ) ;
V_30 = F_80 ( V_30 , V_31 ) ;
while ( V_29 < V_30 ) {
V_161 = F_81 ( V_29 , V_30 ) ;
F_30 ( & V_37 , V_18 ) ;
F_5 ( V_29 , V_4 + V_162 ) ;
F_5 ( V_161 - V_31 , V_4 + V_160 ) ;
F_31 ( & V_37 , V_18 ) ;
F_5 ( 0 , V_4 + V_163 ) ;
V_29 = V_161 ;
}
}
static void F_84 ( unsigned long V_29 , unsigned long V_30 )
{
F_83 ( V_29 , V_30 , V_164 ) ;
}
static void F_85 ( unsigned long V_29 , unsigned long V_30 )
{
if ( ! V_165 )
F_83 ( V_29 , V_30 , V_166 ) ;
}
static void F_86 ( unsigned long V_29 , unsigned long V_30 )
{
if ( V_165 )
F_83 ( V_29 , V_30 , V_164 ) ;
else
F_83 ( V_29 , V_30 , V_167 ) ;
}
static void F_87 ( void )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_30 ( & V_37 , V_18 ) ;
F_7 ( V_4 + V_35 ) ;
F_31 ( & V_37 , V_18 ) ;
F_5 ( 0 , V_4 + V_163 ) ;
}
static void F_88 ( void )
{
F_5 ( 0 , V_26 + V_163 ) ;
}
static void F_89 ( void )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_30 ( & V_37 , V_18 ) ;
F_7 ( V_4 + V_35 ) ;
F_5 ( 0 , V_4 + V_163 ) ;
F_4 ( 0 , V_4 , V_25 ) ;
F_15 ( V_28 ) ;
F_31 ( & V_37 , V_18 ) ;
}
static void F_90 ( void T_1 * V_4 )
{
V_14 . V_168 = F_2 ( V_4 + V_25 ) ;
V_14 . V_15 = F_2 ( V_4 + V_16 ) ;
}
static void T_3 F_91 ( void T_1 * V_4 ,
unsigned V_17 )
{
T_4 V_169 ;
asm volatile("mrc p15, 1, %0, c15, c2, 0" : "=r" (u));
V_169 |= V_170 ;
asm volatile("mcr p15, 1, %0, c15, c2, 0" : : "r" (u));
F_92 () ;
F_10 ( V_4 , V_17 ) ;
}
static void T_3 F_93 ( void T_1 * V_4 , T_4 V_80 ,
struct V_81 * V_82 )
{
V_23 = V_163 ;
}
static void T_3 F_94 ( const struct V_121 * V_122 ,
T_4 * V_97 , T_4 * V_98 )
{
T_4 V_3 = V_171 ;
T_4 V_2 = V_172 ;
F_70 ( V_122 , L_76 ,
& V_173 ) ;
V_165 = F_75 ( V_122 , L_77 ) ;
if ( V_165 ) {
V_3 |= V_174 ;
V_2 |= V_175 ;
}
* V_97 &= ~ V_2 ;
* V_97 |= V_3 ;
* V_98 &= ~ V_2 ;
}
static inline int F_95 ( unsigned long V_176 )
{
return ( V_176 >= V_177 ) &&
( V_176 < V_178 ) ;
}
static inline unsigned long F_96 ( unsigned long V_176 )
{
if ( F_95 ( V_176 ) )
return V_176 + V_179 ;
else
return V_176 + V_180 ;
}
static void F_97 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_181 , V_182 ;
F_25 ( V_29 < V_177 ) ;
if ( F_98 ( V_30 <= V_29 ) )
return;
V_181 = F_96 ( V_29 ) ;
V_182 = F_96 ( V_30 ) ;
if ( F_99 ( F_95 ( V_30 ) || ! F_95 ( V_29 ) ) ) {
F_21 ( V_181 , V_182 ) ;
return;
}
F_21 ( V_181 ,
F_96 ( V_178 - 1 ) ) ;
F_21 ( F_96 ( V_178 ) ,
V_182 ) ;
}
static void F_100 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_181 , V_182 ;
F_25 ( V_29 < V_177 ) ;
if ( F_98 ( V_30 <= V_29 ) )
return;
V_181 = F_96 ( V_29 ) ;
V_182 = F_96 ( V_30 ) ;
if ( F_99 ( F_95 ( V_30 ) || ! F_95 ( V_29 ) ) ) {
F_22 ( V_181 , V_182 ) ;
return;
}
F_22 ( V_181 ,
F_96 ( V_178 - 1 ) ) ;
F_22 ( F_96 ( V_178 ) ,
V_182 ) ;
}
static void F_101 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_181 , V_182 ;
F_25 ( V_29 < V_177 ) ;
if ( F_98 ( V_30 <= V_29 ) )
return;
if ( ( V_30 - V_29 ) >= V_40 ) {
V_5 . V_27 () ;
return;
}
V_181 = F_96 ( V_29 ) ;
V_182 = F_96 ( V_30 ) ;
if ( F_99 ( F_95 ( V_30 ) || ! F_95 ( V_29 ) ) ) {
F_23 ( V_181 , V_182 ) ;
return;
}
F_23 ( V_181 ,
F_96 ( V_178 - 1 ) ) ;
F_23 ( F_96 ( V_178 ) ,
V_182 ) ;
}
static void T_3 F_102 ( void T_1 * V_4 )
{
F_16 ( V_4 ) ;
V_14 . V_183 =
F_2 ( V_4 + V_184 ) ;
V_14 . V_55 =
F_2 ( V_4 + V_56 ) ;
}
static void F_103 ( void T_1 * V_4 )
{
F_9 ( V_4 ) ;
F_5 ( V_14 . V_183 ,
V_4 + V_184 ) ;
F_5 ( V_14 . V_55 ,
V_4 + V_56 ) ;
}
int T_3 F_104 ( T_4 V_97 , T_4 V_98 )
{
const struct V_95 * V_96 ;
struct V_121 * V_122 ;
struct V_185 V_186 ;
T_4 V_80 , V_102 ;
T_4 V_187 = 2 ;
bool V_99 = false ;
V_122 = F_105 ( NULL , V_188 ) ;
if ( ! V_122 )
return - V_130 ;
if ( F_106 ( V_122 , 0 , & V_186 ) )
return - V_130 ;
V_26 = F_107 ( V_186 . V_29 , F_108 ( & V_186 ) ) ;
if ( ! V_26 )
return - V_104 ;
V_14 . V_189 = V_186 . V_29 ;
V_96 = F_109 ( V_188 , V_122 ) -> V_96 ;
if ( F_110 ( V_122 , L_78 ) &&
F_75 ( V_122 , L_79 ) )
V_96 = & V_190 ;
V_102 = F_2 ( V_26 + V_16 ) ;
if ( V_102 != ( ( V_102 & V_98 ) | V_97 ) ) {
F_54 ( L_80 ,
V_102 , ( V_102 & V_98 ) | V_97 ) ;
} else if ( V_98 != ~ 0U && V_97 != 0 ) {
F_66 ( L_81 ) ;
}
if ( ! F_75 ( V_122 , L_82 ) )
F_56 ( L_83 ) ;
if ( F_70 ( V_122 , L_84 , & V_187 ) )
F_56 ( L_85 ) ;
if ( V_187 != 2 )
F_56 ( L_86 ) ;
V_99 = F_75 ( V_122 , L_87 ) ;
if ( V_96 -> V_117 )
V_96 -> V_117 ( V_26 ) ;
if ( ! ( F_2 ( V_26 + V_25 ) & V_24 ) )
if ( V_96 -> V_191 )
V_96 -> V_191 ( V_122 , & V_97 , & V_98 ) ;
if ( V_173 )
V_80 = V_173 ;
else
V_80 = F_2 ( V_26 + V_52 ) ;
return F_64 ( V_96 , V_97 , V_98 , V_80 , V_99 ) ;
}
