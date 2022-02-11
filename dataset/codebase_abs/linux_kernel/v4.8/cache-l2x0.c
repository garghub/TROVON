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
V_5 . V_27 () ;
F_4 ( 0 , V_4 , V_25 ) ;
F_14 ( V_28 ) ;
}
static void F_15 ( void T_1 * V_4 )
{
V_14 . V_15 = F_2 ( V_26 + V_16 ) ;
}
static void F_16 ( void )
{
void T_1 * V_4 = V_26 ;
if ( ! ( F_2 ( V_4 + V_25 ) & V_24 ) )
F_10 ( V_4 , V_20 -> V_17 ) ;
}
static void F_17 ( void T_1 * V_4 )
{
F_5 ( 0 , V_4 + V_23 ) ;
}
static void F_18 ( void T_1 * V_1 , unsigned long V_29 ,
unsigned long V_30 )
{
while ( V_29 < V_30 ) {
F_5 ( V_29 , V_1 ) ;
V_29 += V_31 ;
}
}
static void F_19 ( unsigned long V_29 , unsigned long V_30 )
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
F_18 ( V_4 + V_33 , V_29 , V_30 ) ;
F_17 ( V_4 ) ;
}
static void F_20 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
V_29 &= ~ ( V_31 - 1 ) ;
F_18 ( V_4 + V_34 , V_29 , V_30 ) ;
F_17 ( V_4 ) ;
}
static void F_21 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
V_29 &= ~ ( V_31 - 1 ) ;
F_18 ( V_4 + V_32 , V_29 , V_30 ) ;
F_17 ( V_4 ) ;
}
static void F_22 ( void )
{
void T_1 * V_4 = V_26 ;
F_23 ( ! F_24 () ) ;
F_7 ( V_4 + V_35 ) ;
F_17 ( V_4 ) ;
}
static void F_25 ( void )
{
F_17 ( V_26 ) ;
}
static inline void F_26 ( void T_1 * V_4 )
{
F_5 ( 0 , V_4 + V_36 ) ;
F_1 ( V_4 + V_36 , 1 ) ;
}
static void F_27 ( void T_1 * V_4 , unsigned V_1 )
{
unsigned long V_18 ;
F_28 ( & V_37 , V_18 ) ;
F_7 ( V_4 + V_1 ) ;
F_26 ( V_4 ) ;
F_29 ( & V_37 , V_18 ) ;
}
static unsigned long F_30 ( void T_1 * V_1 , unsigned long V_29 ,
unsigned long V_30 , unsigned long V_18 )
{
T_2 * V_38 = & V_37 ;
while ( V_29 < V_30 ) {
unsigned long V_39 = V_29 + F_31 ( V_30 - V_29 , 4096UL ) ;
while ( V_29 < V_39 ) {
F_1 ( V_1 , 1 ) ;
F_5 ( V_29 , V_1 ) ;
V_29 += V_31 ;
}
if ( V_39 < V_30 ) {
F_29 ( V_38 , V_18 ) ;
F_28 ( V_38 , V_18 ) ;
}
}
return V_18 ;
}
static void F_32 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_28 ( & V_37 , V_18 ) ;
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
V_18 = F_30 ( V_4 + V_33 ,
V_29 , V_30 , V_18 ) ;
F_1 ( V_4 + V_33 , 1 ) ;
F_26 ( V_4 ) ;
F_29 ( & V_37 , V_18 ) ;
}
static void F_33 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
V_29 &= ~ ( V_31 - 1 ) ;
if ( ( V_30 - V_29 ) >= V_40 ) {
F_27 ( V_4 , V_41 ) ;
return;
}
F_28 ( & V_37 , V_18 ) ;
V_18 = F_30 ( V_4 + V_34 ,
V_29 , V_30 , V_18 ) ;
F_1 ( V_4 + V_32 , 1 ) ;
F_26 ( V_4 ) ;
F_29 ( & V_37 , V_18 ) ;
}
static void F_34 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
V_29 &= ~ ( V_31 - 1 ) ;
if ( ( V_30 - V_29 ) >= V_40 ) {
F_27 ( V_4 , V_35 ) ;
return;
}
F_28 ( & V_37 , V_18 ) ;
V_18 = F_30 ( V_4 + V_32 ,
V_29 , V_30 , V_18 ) ;
F_1 ( V_4 + V_32 , 1 ) ;
F_26 ( V_4 ) ;
F_29 ( & V_37 , V_18 ) ;
}
static void F_35 ( void )
{
F_27 ( V_26 , V_35 ) ;
}
static void F_36 ( void )
{
unsigned long V_18 ;
F_28 ( & V_37 , V_18 ) ;
F_26 ( V_26 ) ;
F_29 ( & V_37 , V_18 ) ;
}
static void F_37 ( void T_1 * V_4 , unsigned V_17 )
{
V_14 . V_15 |= V_42 ;
F_10 ( V_4 , V_17 ) ;
}
static void F_38 ( void T_1 * V_4 , unsigned V_17 )
{
if ( F_2 ( V_4 + V_16 ) & V_42 )
F_8 ( V_4 , V_17 ) ;
}
static void F_39 ( unsigned long V_29 , unsigned long V_30 )
{
void T_1 * V_4 = V_26 ;
if ( ( V_29 | V_30 ) & ( V_31 - 1 ) ) {
unsigned long V_18 ;
F_28 ( & V_37 , V_18 ) ;
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
F_29 ( & V_37 , V_18 ) ;
}
F_18 ( V_4 + V_33 , V_29 , V_30 ) ;
F_17 ( V_4 ) ;
}
static void F_40 ( unsigned long V_29 , unsigned long V_30 )
{
T_2 * V_38 = & V_37 ;
unsigned long V_18 ;
void T_1 * V_4 = V_26 ;
F_28 ( V_38 , V_18 ) ;
while ( V_29 < V_30 ) {
unsigned long V_39 = V_29 + F_31 ( V_30 - V_29 , 4096UL ) ;
F_6 ( V_4 , 0x03 ) ;
while ( V_29 < V_39 ) {
F_5 ( V_29 , V_4 + V_34 ) ;
F_5 ( V_29 , V_4 + V_33 ) ;
V_29 += V_31 ;
}
F_6 ( V_4 , 0x00 ) ;
if ( V_39 < V_30 ) {
F_29 ( V_38 , V_18 ) ;
F_28 ( V_38 , V_18 ) ;
}
}
F_29 ( V_38 , V_18 ) ;
F_17 ( V_4 ) ;
}
static void F_41 ( void )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_28 ( & V_37 , V_18 ) ;
F_6 ( V_4 , 0x03 ) ;
F_7 ( V_4 + V_35 ) ;
F_6 ( V_4 , 0x00 ) ;
F_17 ( V_4 ) ;
F_29 ( & V_37 , V_18 ) ;
}
static void T_3 F_42 ( void T_1 * V_4 )
{
unsigned V_43 ;
F_15 ( V_4 ) ;
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
static void F_43 ( void T_1 * V_4 )
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
static int F_44 ( unsigned int V_60 )
{
F_45 ( F_46 () | F_47 ( 3 ) | F_47 ( 2 ) | F_47 ( 1 ) ) ;
return 0 ;
}
static int F_48 ( unsigned int V_60 )
{
F_45 ( F_46 () & ~ ( F_47 ( 3 ) | F_47 ( 2 ) | F_47 ( 1 ) ) ) ;
return 0 ;
}
static void T_3 F_49 ( void T_1 * V_4 , unsigned V_17 )
{
unsigned V_61 = F_2 ( V_4 + V_52 ) & V_53 ;
bool V_62 = F_50 () == V_63 ;
T_4 V_64 = V_14 . V_15 ;
if ( V_61 >= V_54 ) {
if ( V_62 ) {
V_64 |= V_65 ;
F_51 ( L_1 ) ;
} else if ( V_64 & V_65 ) {
F_52 ( L_2 ) ;
V_64 &= ~ V_65 ;
}
}
if ( V_62 ) {
T_4 V_66 = F_2 ( V_4 + V_16 ) ;
T_4 V_67 = F_46 () ;
F_53 ( L_3 , V_67 ) ;
if ( V_67 & F_47 ( 3 ) && ! ( V_66 & V_68 ) )
F_54 ( L_4 ) ;
if ( V_64 & V_68 && ! ( V_67 & F_47 ( 3 ) ) )
F_54 ( L_5 ) ;
if ( ! ( V_64 & V_68 ) && ! V_5 . V_6 ) {
V_64 |= V_68 ;
F_51 ( L_6 ) ;
}
} else if ( V_64 & ( V_68 | V_65 ) ) {
F_54 ( L_7 ) ;
V_64 &= ~ ( V_68 | V_65 ) ;
}
V_14 . V_15 = V_64 | V_69 ;
F_10 ( V_4 , V_17 ) ;
V_64 = F_2 ( V_4 + V_16 ) ;
if ( V_64 & ( V_70 | V_71 ) ) {
T_4 V_72 = F_2 ( V_4 + V_56 ) ;
F_51 ( L_8 ,
V_64 & V_71 ? L_9 : L_10 ,
V_64 & V_70 ? L_11 : L_10 ,
1 + ( V_72 & V_73 ) ) ;
}
if ( V_61 >= V_57 ) {
T_4 V_74 ;
V_74 = F_2 ( V_4 + V_59 ) ;
F_51 ( L_12 ,
V_74 & V_75 ? L_13 : L_14 ,
V_74 & V_76 ? L_13 : L_14 ) ;
}
if ( V_64 & V_68 )
F_55 ( V_77 ,
L_15 , F_44 ,
F_48 ) ;
}
static void T_3 F_56 ( void T_1 * V_4 , T_4 V_78 ,
struct V_79 * V_80 )
{
unsigned V_43 = V_78 & V_53 ;
const char * V_81 [ 8 ] ;
unsigned V_82 = 0 ;
if ( F_57 ( V_83 ) &&
V_43 < V_54 &&
V_80 -> V_84 == F_19 ) {
V_80 -> V_84 = F_39 ;
V_80 -> V_85 = F_40 ;
V_81 [ V_82 ++ ] = L_16 ;
}
if ( F_57 ( V_86 ) &&
V_43 >= V_54 &&
V_43 < V_87 ) {
V_80 -> V_27 = F_41 ;
V_81 [ V_82 ++ ] = L_17 ;
}
if ( V_43 >= V_57 &&
V_43 < V_88 ) {
T_4 V_3 = V_14 . V_55 ;
if ( V_3 & ( F_47 ( 30 ) | F_47 ( 23 ) ) ) {
V_3 &= ~ ( F_47 ( 30 ) | F_47 ( 23 ) ) ;
V_14 . V_55 = V_3 ;
V_81 [ V_82 ++ ] = L_18 ;
}
}
if ( F_57 ( V_89 ) &&
V_43 == V_57 ) {
V_23 = V_90 ;
V_81 [ V_82 ++ ] = L_19 ;
}
if ( F_57 ( V_91 ) )
V_81 [ V_82 ++ ] = L_20 ;
if ( V_82 ) {
unsigned V_10 ;
F_51 ( L_21 , V_82 > 1 ? L_22 : L_23 ) ;
for ( V_10 = 0 ; V_10 < V_82 ; V_10 ++ )
F_58 ( L_24 , V_81 [ V_10 ] ) ;
F_58 ( L_25 ) ;
}
}
static void F_59 ( void )
{
if ( V_14 . V_15 & V_68 )
F_45 ( F_46 () & ~ ( F_47 ( 3 ) | F_47 ( 2 ) | F_47 ( 1 ) ) ) ;
F_13 () ;
}
static void F_60 ( void )
{
F_16 () ;
if ( V_14 . V_15 & V_68 )
F_45 ( F_46 () | F_47 ( 3 ) | F_47 ( 2 ) | F_47 ( 1 ) ) ;
}
static void F_61 ( void T_1 * V_4 , unsigned V_17 )
{
if ( F_2 ( V_4 + V_16 ) & V_69 )
F_8 ( V_4 , V_17 ) ;
}
static int T_3 F_62 ( const struct V_92 * V_93 ,
T_4 V_94 , T_4 V_95 , T_4 V_78 , bool V_96 )
{
struct V_79 V_80 ;
unsigned V_97 , V_98 ;
T_4 V_64 , V_99 ;
V_20 = F_63 ( V_93 , sizeof( * V_93 ) , V_100 ) ;
if ( ! V_20 )
return - V_101 ;
if ( V_94 & V_95 )
F_64 ( L_26 ) ;
V_99 = V_64 = F_2 ( V_26 + V_16 ) ;
V_64 &= V_95 ;
V_64 |= V_94 ;
if ( V_99 != V_64 )
F_52 ( L_27 ,
V_99 , V_64 ) ;
switch ( V_78 & V_102 ) {
case V_103 :
if ( ( V_94 | ~ V_95 ) & ( V_104 | V_105 ) )
F_52 ( L_28 ) ;
if ( V_64 & ( 1 << 16 ) )
V_98 = 16 ;
else
V_98 = 8 ;
break;
case V_106 :
case V_107 :
V_98 = ( V_64 >> 13 ) & 0xf ;
break;
case V_108 :
V_98 = ( V_64 >> 13 ) & 0xf ;
V_98 = 2 << ( ( V_98 + 1 ) >> 2 ) ;
break;
default:
V_98 = 8 ;
break;
}
V_8 = ( 1 << V_98 ) - 1 ;
V_97 = ( V_64 & V_104 ) >>
V_109 ;
V_40 = V_98 * ( V_93 -> V_110 << V_97 ) ;
V_80 = V_93 -> V_5 ;
V_80 . V_6 = V_5 . V_6 ;
V_80 . V_19 = V_5 . V_19 ;
if ( V_93 -> V_111 )
V_93 -> V_111 ( V_26 , V_78 , & V_80 ) ;
if ( V_96 ) {
F_51 ( L_29 ) ;
V_80 . V_112 = NULL ;
}
if ( ! ( F_2 ( V_26 + V_25 ) & V_24 ) ) {
V_14 . V_15 = V_64 ;
V_93 -> V_113 ( V_26 , V_93 -> V_17 ) ;
}
V_5 = V_80 ;
if ( V_93 -> V_114 )
V_93 -> V_114 ( V_26 ) ;
V_64 = F_2 ( V_26 + V_16 ) ;
F_51 ( L_30 ,
V_93 -> type , V_98 , V_40 >> 10 ) ;
F_51 ( L_31 ,
V_93 -> type , V_78 , V_64 ) ;
return 0 ;
}
void T_3 F_65 ( void T_1 * V_4 , T_4 V_94 , T_4 V_95 )
{
const struct V_92 * V_93 ;
T_4 V_78 ;
V_26 = V_4 ;
V_78 = F_2 ( V_4 + V_52 ) ;
switch ( V_78 & V_102 ) {
default:
case V_106 :
V_93 = & V_115 ;
break;
case V_107 :
V_93 = & V_116 ;
break;
case V_103 :
V_93 = & V_117 ;
break;
}
if ( V_93 -> V_114 )
V_93 -> V_114 ( V_26 ) ;
F_62 ( V_93 , V_94 , V_95 , V_78 , false ) ;
}
static int T_3 F_66 ( const struct V_118 * V_119 ,
T_4 * V_94 , T_4 * V_95 ,
T_4 * V_120 ,
T_4 V_121 )
{
T_4 V_2 = 0 , V_3 = 0 ;
T_4 V_122 = 0 , V_123 = 0 ;
T_4 V_97 = 1 ;
T_4 V_124 = 0 ;
T_4 V_125 = 0 ;
T_4 V_126 = 0 ;
F_67 ( V_119 , L_32 , & V_122 ) ;
F_67 ( V_119 , L_33 , & V_123 ) ;
F_67 ( V_119 , L_34 , & V_125 ) ;
F_67 ( V_119 , L_35 , & V_126 ) ;
if ( ! V_122 || ! V_123 )
return - V_127 ;
if ( ! V_126 ) {
if ( V_125 ) {
V_126 = V_125 ;
} else {
F_52 ( L_36
L_37 ,
V_31 ) ;
V_126 = V_31 ;
}
}
if ( V_126 != V_31 )
F_52 ( L_38
L_39 ,
V_126 ,
V_31 ) ;
V_124 = V_123 * V_126 ;
* V_120 = V_122 / V_124 ;
if ( V_124 > V_121 ) {
F_54 ( L_40 , V_124 ) ;
return - V_128 ;
}
F_51 ( L_41 ,
V_122 , V_122 >> 10 ) ;
F_51 ( L_42 , V_126 ) ;
F_51 ( L_43 ,
V_124 , V_124 >> 10 ) ;
F_51 ( L_44 , * V_120 ) ;
V_97 = F_68 ( V_124 >> 10 ) - 3 ;
if ( V_97 < 1 || V_97 > 6 ) {
F_54 ( L_45 ,
V_124 ) ;
return - V_128 ;
}
V_2 |= V_104 ;
V_3 |= ( V_97 << V_109 ) ;
* V_94 &= ~ V_2 ;
* V_94 |= V_3 ;
* V_95 &= ~ V_2 ;
return 0 ;
}
static void T_3 F_69 ( const struct V_118 * V_119 ,
T_4 * V_94 , T_4 * V_95 )
{
T_4 V_93 [ 2 ] = { 0 , 0 } ;
T_4 V_129 = 0 ;
T_4 V_130 = 0 ;
T_4 V_3 = 0 , V_2 = 0 ;
T_4 V_131 ;
int V_132 ;
F_67 ( V_119 , L_46 , & V_129 ) ;
if ( V_129 ) {
V_2 |= V_133 ;
V_3 |= ( V_129 - 1 ) << V_134 ;
}
F_70 ( V_119 , L_47 ,
V_93 , F_71 ( V_93 ) ) ;
if ( V_93 [ 0 ] && V_93 [ 1 ] ) {
V_2 |= V_135 |
V_136 ;
V_3 |= ( ( V_93 [ 0 ] - 1 ) << V_137 ) |
( ( V_93 [ 1 ] - 1 ) << V_138 ) ;
}
F_67 ( V_119 , L_48 , & V_130 ) ;
if ( V_130 ) {
V_2 |= V_139 ;
V_3 |= ( V_130 - 1 ) << V_140 ;
}
if ( F_72 ( V_119 , L_49 ) ) {
V_2 &= ~ V_141 ;
V_3 |= V_141 ;
} else if ( F_72 ( V_119 , L_50 ) ) {
V_2 &= ~ V_141 ;
}
if ( F_72 ( V_119 , L_51 ) ) {
V_2 &= ~ V_142 ;
V_3 |= V_142 ;
}
V_132 = F_66 ( V_119 , V_94 , V_95 , & V_131 , V_143 ) ;
if ( V_132 )
return;
if ( V_131 > 8 ) {
F_54 ( L_52 ) ;
F_54 ( L_53 , V_131 ) ;
} else {
V_2 |= V_144 ;
V_3 |= ( V_131 << V_145 ) ;
}
* V_94 &= ~ V_2 ;
* V_94 |= V_3 ;
* V_95 &= ~ V_2 ;
}
static void T_3 F_73 ( const struct V_118 * V_119 ,
T_4 * V_94 , T_4 * V_95 )
{
T_4 V_93 [ 3 ] = { 0 , 0 , 0 } ;
T_4 V_129 [ 3 ] = { 0 , 0 , 0 } ;
T_4 V_146 [ 2 ] = { 0 , 0 } ;
T_4 V_131 ;
T_4 V_72 ;
T_4 V_147 ;
T_4 V_3 ;
int V_132 ;
F_70 ( V_119 , L_46 , V_129 , F_71 ( V_129 ) ) ;
if ( V_129 [ 0 ] && V_129 [ 1 ] && V_129 [ 2 ] )
V_14 . V_44 =
F_74 ( V_129 [ 0 ] - 1 ) |
F_75 ( V_129 [ 1 ] - 1 ) |
F_76 ( V_129 [ 2 ] - 1 ) ;
F_70 ( V_119 , L_47 ,
V_93 , F_71 ( V_93 ) ) ;
if ( V_93 [ 0 ] && V_93 [ 1 ] && V_93 [ 2 ] )
V_14 . V_46 =
F_74 ( V_93 [ 0 ] - 1 ) |
F_75 ( V_93 [ 1 ] - 1 ) |
F_76 ( V_93 [ 2 ] - 1 ) ;
F_70 ( V_119 , L_54 ,
V_146 , F_71 ( V_146 ) ) ;
if ( V_146 [ 1 ] ) {
V_14 . V_48 =
F_77 ( V_146 [ 0 ] + V_146 [ 1 ] , V_148 ) ;
V_14 . V_50 = ( V_146 [ 0 ] & ~ ( V_148 - 1 ) )
| V_149 ;
}
V_132 = F_66 ( V_119 , V_94 , V_95 , & V_131 , V_150 ) ;
if ( ! V_132 ) {
switch ( V_131 ) {
case 16 :
* V_94 &= ~ V_144 ;
* V_94 |= V_105 ;
* V_95 &= ~ V_144 ;
break;
case 8 :
* V_94 &= ~ V_144 ;
* V_95 &= ~ V_144 ;
break;
default:
F_54 ( L_55 ,
V_131 ) ;
break;
}
}
if ( F_72 ( V_119 , L_51 ) ) {
* V_94 |= V_142 ;
* V_95 &= ~ V_142 ;
}
if ( F_72 ( V_119 , L_49 ) ) {
* V_94 |= V_141 ;
* V_95 &= ~ V_141 ;
} else if ( F_72 ( V_119 , L_50 ) ) {
* V_94 &= ~ V_141 ;
* V_95 &= ~ V_141 ;
}
V_72 = V_14 . V_55 ;
V_132 = F_67 ( V_119 , L_56 , & V_3 ) ;
if ( V_132 == 0 ) {
if ( V_3 )
V_72 |= V_151 ;
else
V_72 &= ~ V_151 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_57 ) ;
}
V_132 = F_67 ( V_119 , L_58 , & V_3 ) ;
if ( V_132 == 0 ) {
if ( V_3 )
V_72 |= V_152 ;
else
V_72 &= ~ V_152 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_59 ) ;
}
V_132 = F_67 ( V_119 , L_60 , & V_3 ) ;
if ( V_132 == 0 ) {
if ( ! V_3 )
V_72 |= V_153 ;
else
V_72 &= ~ V_153 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_61 ) ;
}
V_132 = F_67 ( V_119 , L_62 , & V_3 ) ;
if ( V_132 == 0 ) {
if ( V_3 )
V_72 |= V_154 ;
else
V_72 &= ~ V_154 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_63 ) ;
}
V_132 = F_67 ( V_119 , L_64 , & V_3 ) ;
if ( V_132 == 0 ) {
V_72 &= ~ V_73 ;
V_72 |= V_3 & V_73 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_65 ) ;
}
V_132 = F_67 ( V_119 , L_66 , & V_3 ) ;
if ( V_132 == 0 ) {
if ( V_3 )
V_72 |= V_155 ;
else
V_72 &= ~ V_155 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_67 ) ;
}
V_132 = F_67 ( V_119 , L_68 , & V_3 ) ;
if ( V_132 == 0 ) {
if ( V_3 )
V_72 |= V_156 ;
else
V_72 &= ~ V_156 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_69 ) ;
}
V_14 . V_55 = V_72 ;
V_147 = V_14 . V_58 |
V_75 | V_76 ;
V_132 = F_67 ( V_119 , L_70 , & V_3 ) ;
if ( ! V_132 ) {
if ( ! V_3 )
V_147 &= ~ V_75 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_71 ) ;
}
V_132 = F_67 ( V_119 , L_72 , & V_3 ) ;
if ( ! V_132 ) {
if ( ! V_3 )
V_147 &= ~ V_76 ;
} else if ( V_132 != - V_128 ) {
F_54 ( L_73 ) ;
}
V_14 . V_58 = V_147 ;
}
static unsigned long F_78 ( unsigned long V_29 , unsigned long V_30 )
{
if ( V_30 > V_29 + V_157 )
V_30 = V_29 + V_157 ;
if ( V_30 > F_79 ( V_29 + 1 ) )
V_30 = F_79 ( V_29 + 1 ) ;
return V_30 ;
}
static void F_80 ( unsigned long V_29 , unsigned long V_30 ,
unsigned long V_158 )
{
void T_1 * V_4 = V_26 ;
unsigned long V_159 ;
unsigned long V_18 ;
V_29 &= ~ ( V_31 - 1 ) ;
V_30 = F_77 ( V_30 , V_31 ) ;
while ( V_29 < V_30 ) {
V_159 = F_78 ( V_29 , V_30 ) ;
F_28 ( & V_37 , V_18 ) ;
F_5 ( V_29 , V_4 + V_160 ) ;
F_5 ( V_159 - V_31 , V_4 + V_158 ) ;
F_29 ( & V_37 , V_18 ) ;
F_5 ( 0 , V_4 + V_161 ) ;
V_29 = V_159 ;
}
}
static void F_81 ( unsigned long V_29 , unsigned long V_30 )
{
F_80 ( V_29 , V_30 , V_162 ) ;
}
static void F_82 ( unsigned long V_29 , unsigned long V_30 )
{
if ( ! V_163 )
F_80 ( V_29 , V_30 , V_164 ) ;
}
static void F_83 ( unsigned long V_29 , unsigned long V_30 )
{
if ( V_163 )
F_80 ( V_29 , V_30 , V_162 ) ;
else
F_80 ( V_29 , V_30 , V_165 ) ;
}
static void F_84 ( void )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_28 ( & V_37 , V_18 ) ;
F_7 ( V_4 + V_35 ) ;
F_29 ( & V_37 , V_18 ) ;
F_5 ( 0 , V_4 + V_161 ) ;
}
static void F_85 ( void )
{
F_5 ( 0 , V_26 + V_161 ) ;
}
static void F_86 ( void )
{
void T_1 * V_4 = V_26 ;
unsigned long V_18 ;
F_28 ( & V_37 , V_18 ) ;
F_7 ( V_4 + V_35 ) ;
F_5 ( 0 , V_4 + V_161 ) ;
F_4 ( 0 , V_4 , V_25 ) ;
F_14 ( V_28 ) ;
F_29 ( & V_37 , V_18 ) ;
}
static void F_87 ( void T_1 * V_4 )
{
V_14 . V_166 = F_2 ( V_4 + V_25 ) ;
V_14 . V_15 = F_2 ( V_4 + V_16 ) ;
}
static void T_3 F_88 ( void T_1 * V_4 ,
unsigned V_17 )
{
T_4 V_167 ;
asm volatile("mrc p15, 1, %0, c15, c2, 0" : "=r" (u));
V_167 |= V_168 ;
asm volatile("mcr p15, 1, %0, c15, c2, 0" : : "r" (u));
F_89 () ;
F_10 ( V_4 , V_17 ) ;
}
static void T_3 F_90 ( void T_1 * V_4 , T_4 V_78 ,
struct V_79 * V_80 )
{
V_23 = V_161 ;
}
static void T_3 F_91 ( const struct V_118 * V_119 ,
T_4 * V_94 , T_4 * V_95 )
{
T_4 V_3 = V_169 ;
T_4 V_2 = V_170 ;
F_67 ( V_119 , L_74 ,
& V_171 ) ;
V_163 = F_72 ( V_119 , L_75 ) ;
if ( V_163 ) {
V_3 |= V_172 ;
V_2 |= V_173 ;
}
* V_94 &= ~ V_2 ;
* V_94 |= V_3 ;
* V_95 &= ~ V_2 ;
}
static inline int F_92 ( unsigned long V_174 )
{
return ( V_174 >= V_175 ) &&
( V_174 < V_176 ) ;
}
static inline unsigned long F_93 ( unsigned long V_174 )
{
if ( F_92 ( V_174 ) )
return V_174 + V_177 ;
else
return V_174 + V_178 ;
}
static void F_94 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_179 , V_180 ;
F_23 ( V_29 < V_175 ) ;
if ( F_95 ( V_30 <= V_29 ) )
return;
V_179 = F_93 ( V_29 ) ;
V_180 = F_93 ( V_30 ) ;
if ( F_96 ( F_92 ( V_30 ) || ! F_92 ( V_29 ) ) ) {
F_19 ( V_179 , V_180 ) ;
return;
}
F_19 ( V_179 ,
F_93 ( V_176 - 1 ) ) ;
F_19 ( F_93 ( V_176 ) ,
V_180 ) ;
}
static void F_97 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_179 , V_180 ;
F_23 ( V_29 < V_175 ) ;
if ( F_95 ( V_30 <= V_29 ) )
return;
V_179 = F_93 ( V_29 ) ;
V_180 = F_93 ( V_30 ) ;
if ( F_96 ( F_92 ( V_30 ) || ! F_92 ( V_29 ) ) ) {
F_20 ( V_179 , V_180 ) ;
return;
}
F_20 ( V_179 ,
F_93 ( V_176 - 1 ) ) ;
F_20 ( F_93 ( V_176 ) ,
V_180 ) ;
}
static void F_98 ( unsigned long V_29 , unsigned long V_30 )
{
unsigned long V_179 , V_180 ;
F_23 ( V_29 < V_175 ) ;
if ( F_95 ( V_30 <= V_29 ) )
return;
if ( ( V_30 - V_29 ) >= V_40 ) {
V_5 . V_27 () ;
return;
}
V_179 = F_93 ( V_29 ) ;
V_180 = F_93 ( V_30 ) ;
if ( F_96 ( F_92 ( V_30 ) || ! F_92 ( V_29 ) ) ) {
F_21 ( V_179 , V_180 ) ;
return;
}
F_21 ( V_179 ,
F_93 ( V_176 - 1 ) ) ;
F_21 ( F_93 ( V_176 ) ,
V_180 ) ;
}
static void T_3 F_99 ( void T_1 * V_4 )
{
F_15 ( V_4 ) ;
V_14 . V_181 =
F_2 ( V_4 + V_182 ) ;
V_14 . V_55 =
F_2 ( V_4 + V_56 ) ;
}
static void F_100 ( void T_1 * V_4 )
{
F_9 ( V_4 ) ;
F_5 ( V_14 . V_181 ,
V_4 + V_182 ) ;
F_5 ( V_14 . V_55 ,
V_4 + V_56 ) ;
}
int T_3 F_101 ( T_4 V_94 , T_4 V_95 )
{
const struct V_92 * V_93 ;
struct V_118 * V_119 ;
struct V_183 V_184 ;
T_4 V_78 , V_99 ;
T_4 V_185 = 2 ;
bool V_96 = false ;
V_119 = F_102 ( NULL , V_186 ) ;
if ( ! V_119 )
return - V_127 ;
if ( F_103 ( V_119 , 0 , & V_184 ) )
return - V_127 ;
V_26 = F_104 ( V_184 . V_29 , F_105 ( & V_184 ) ) ;
if ( ! V_26 )
return - V_101 ;
V_14 . V_187 = V_184 . V_29 ;
V_93 = F_106 ( V_186 , V_119 ) -> V_93 ;
if ( F_107 ( V_119 , L_76 ) &&
F_72 ( V_119 , L_77 ) )
V_93 = & V_188 ;
V_99 = F_2 ( V_26 + V_16 ) ;
if ( V_99 != ( ( V_99 & V_95 ) | V_94 ) ) {
F_52 ( L_78 ,
V_99 , ( V_99 & V_95 ) | V_94 ) ;
} else if ( V_95 != ~ 0U && V_94 != 0 ) {
F_64 ( L_79 ) ;
}
if ( ! F_72 ( V_119 , L_80 ) )
F_54 ( L_81 ) ;
if ( F_67 ( V_119 , L_82 , & V_185 ) )
F_54 ( L_83 ) ;
if ( V_185 != 2 )
F_54 ( L_84 ) ;
V_96 = F_72 ( V_119 , L_85 ) ;
if ( V_93 -> V_114 )
V_93 -> V_114 ( V_26 ) ;
if ( ! ( F_2 ( V_26 + V_25 ) & V_24 ) )
if ( V_93 -> V_189 )
V_93 -> V_189 ( V_119 , & V_94 , & V_95 ) ;
if ( V_171 )
V_78 = V_171 ;
else
V_78 = F_2 ( V_26 + V_52 ) ;
return F_62 ( V_93 , V_94 , V_95 , V_78 , V_96 ) ;
}
