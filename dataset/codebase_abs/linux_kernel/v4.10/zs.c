static void F_1 ( void )
{
F_2 ( 2 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
void T_2 * V_4 = V_2 -> V_5 . V_6 + V_7 ;
T_1 V_8 ;
if ( V_3 != 0 ) {
F_4 ( V_3 & 0xf , V_4 ) ;
F_5 () ;
F_1 () ;
}
V_8 = F_6 ( V_4 ) ;
F_1 () ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_9 )
{
void T_2 * V_4 = V_2 -> V_5 . V_6 + V_7 ;
if ( V_3 != 0 ) {
F_4 ( V_3 & 0xf , V_4 ) ;
F_5 () ; F_1 () ;
}
F_4 ( V_9 , V_4 ) ;
F_5 () ;
F_1 () ;
return;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_5 . V_6 +
V_11 + V_7 ;
T_1 V_8 ;
V_8 = F_6 ( V_10 ) ;
F_1 () ;
return V_8 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_9 )
{
void T_2 * V_10 = V_2 -> V_5 . V_6 +
V_11 + V_7 ;
F_4 ( V_9 , V_10 ) ;
F_5 () ;
F_1 () ;
return;
}
void F_10 ( void )
{
struct V_1 * V_2 ;
int V_12 , V_13 ;
for ( V_12 = 0 ; V_12 < V_14 * V_15 ; V_12 ++ ) {
V_2 = & V_16 [ V_12 / V_15 ] . V_2 [ V_12 % V_15 ] ;
if ( ! V_2 -> V_17 )
continue;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
F_11 ( L_1 , V_13 , V_2 -> V_18 [ V_13 ] ) ;
F_11 ( L_2 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
F_11 ( L_3 , V_13 , F_3 ( V_2 , V_13 ) ) ;
F_11 ( L_4 ) ;
}
}
static void F_12 ( T_3 * V_19 , int V_20 )
{
if ( V_20 )
F_13 ( V_19 ) ;
else
F_14 ( V_19 ) ;
}
static void F_15 ( T_3 * V_19 , int V_20 )
{
if ( V_20 )
F_16 ( V_19 ) ;
else
F_17 ( V_19 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_21 = 10000 ;
while ( ( F_3 ( V_2 , V_22 ) & V_23 ) && -- V_21 )
F_8 ( V_2 ) ;
return V_21 ;
}
static int F_19 ( struct V_1 * V_2 , int V_20 )
{
struct V_24 * V_17 = V_2 -> V_17 ;
int V_21 = 10000 ;
while ( ! ( F_3 ( V_2 , V_22 ) & V_25 ) && -- V_21 ) {
F_15 ( & V_17 -> V_26 , V_20 ) ;
F_2 ( 2 ) ;
F_12 ( & V_17 -> V_26 , V_20 ) ;
}
return V_21 ;
}
static int F_20 ( struct V_1 * V_2 , int V_20 )
{
struct V_24 * V_17 = V_2 -> V_17 ;
int V_21 = 10000 ;
while ( ! ( F_3 ( V_2 , V_27 ) & V_28 ) && -- V_21 ) {
F_15 ( & V_17 -> V_26 , V_20 ) ;
F_2 ( 2 ) ;
F_12 ( & V_17 -> V_26 , V_20 ) ;
}
return V_21 ;
}
static void F_21 ( struct V_1 * V_2 , T_1 * V_18 , int V_20 )
{
F_20 ( V_2 , V_20 ) ;
F_7 ( V_2 , V_29 , V_18 [ 3 ] & ~ V_30 ) ;
F_7 ( V_2 , V_31 , V_18 [ 5 ] & ~ V_32 ) ;
F_7 ( V_2 , V_33 , V_18 [ 4 ] ) ;
F_7 ( V_2 , V_34 , V_18 [ 9 ] ) ;
F_7 ( V_2 , V_27 , V_18 [ 1 ] ) ;
F_7 ( V_2 , V_35 , V_18 [ 2 ] ) ;
F_7 ( V_2 , V_36 , V_18 [ 10 ] ) ;
F_7 ( V_2 , V_37 , V_18 [ 14 ] & ~ V_38 ) ;
F_7 ( V_2 , V_39 , V_18 [ 11 ] ) ;
F_7 ( V_2 , V_40 , V_18 [ 12 ] ) ;
F_7 ( V_2 , V_41 , V_18 [ 13 ] ) ;
F_7 ( V_2 , V_37 , V_18 [ 14 ] ) ;
F_7 ( V_2 , V_42 , V_18 [ 15 ] ) ;
if ( V_18 [ 3 ] & V_30 )
F_7 ( V_2 , V_29 , V_18 [ 3 ] ) ;
if ( V_18 [ 5 ] & V_32 )
F_7 ( V_2 , V_31 , V_18 [ 5 ] ) ;
return;
}
static unsigned int F_22 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
T_1 V_46 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_46 = F_3 ( V_2 , V_27 ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
return V_46 & V_28 ? V_47 : 0 ;
}
static unsigned int F_26 ( struct V_1 * V_48 ,
struct V_1 * V_49 )
{
T_1 V_50 , V_51 ;
unsigned int V_52 ;
V_50 = F_3 ( V_48 , V_22 ) ;
V_51 = F_3 ( V_49 , V_22 ) ;
V_52 = ( ( V_51 & V_53 ) ? V_54 : 0 ) |
( ( V_51 & V_55 ) ? V_56 : 0 ) |
( ( V_50 & V_55 ) ? V_57 : 0 ) |
( ( V_50 & V_58 ) ? V_59 : 0 ) ;
return V_52 ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
struct V_1 * V_48 = & V_2 -> V_17 -> V_2 [ V_60 ] ;
return V_2 != V_48 ? F_26 ( V_48 , V_2 ) : 0 ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
struct V_1 * V_48 = & V_2 -> V_17 -> V_2 [ V_60 ] ;
unsigned int V_61 , V_52 , V_62 ;
T_1 V_63 , V_64 ;
if ( V_2 == V_48 )
return 0 ;
V_63 = V_48 -> V_18 [ 15 ] ;
V_64 = V_2 -> V_18 [ 15 ] ;
V_61 = ( ( V_64 & V_65 ) ? V_54 : 0 ) |
( ( V_64 & V_66 ) ? V_56 : 0 ) |
( ( V_63 & V_66 ) ? V_57 : 0 ) |
( ( V_63 & V_67 ) ? V_59 : 0 ) ;
V_52 = V_2 -> V_52 ;
if ( V_61 ) {
V_52 &= ~ V_61 ;
V_52 |= F_26 ( V_48 , V_2 ) & V_61 ;
}
V_62 = V_52 ^ V_2 -> V_52 ;
if ( V_62 )
V_2 -> V_52 = V_52 ;
return V_62 ;
}
static unsigned int F_29 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned int V_52 ;
F_14 ( & V_17 -> V_26 ) ;
V_52 = F_27 ( V_2 ) ;
F_17 ( & V_17 -> V_26 ) ;
return V_52 ;
}
static void F_30 ( struct V_43 * V_44 , unsigned int V_52 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
struct V_1 * V_48 = & V_17 -> V_2 [ V_60 ] ;
T_1 V_68 , V_69 ;
F_14 ( & V_17 -> V_26 ) ;
if ( V_2 != V_48 ) {
if ( V_52 & V_70 )
V_48 -> V_18 [ 5 ] |= V_71 ;
else
V_48 -> V_18 [ 5 ] &= ~ V_71 ;
if ( V_52 & V_72 )
V_48 -> V_18 [ 5 ] |= V_73 ;
else
V_48 -> V_18 [ 5 ] &= ~ V_73 ;
F_7 ( V_48 , V_31 , V_48 -> V_18 [ 5 ] ) ;
}
V_68 = V_2 -> V_18 [ 14 ] ;
V_69 = V_68 ;
if ( V_52 & V_74 )
V_69 |= V_75 ;
else
V_69 &= ~ V_75 ;
if ( V_69 != V_68 ) {
V_2 -> V_18 [ 14 ] = V_69 ;
F_7 ( V_2 , V_37 , V_2 -> V_18 [ 14 ] ) ;
}
F_17 ( & V_17 -> V_26 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_22 , V_76 ) ;
V_2 -> V_77 = 1 ;
}
static void F_32 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
F_14 ( & V_17 -> V_26 ) ;
F_31 ( V_2 ) ;
F_17 ( & V_17 -> V_26 ) ;
}
static void F_33 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
F_14 ( & V_17 -> V_26 ) ;
if ( V_2 -> V_77 ) {
F_19 ( V_2 , 0 ) ;
V_2 -> V_77 = 0 ;
F_34 ( V_2 ) ;
}
F_17 ( & V_17 -> V_26 ) ;
}
static void F_35 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
struct V_1 * V_48 = & V_17 -> V_2 [ V_60 ] ;
F_14 ( & V_17 -> V_26 ) ;
V_2 -> V_18 [ 15 ] &= ~ V_78 ;
V_2 -> V_18 [ 1 ] &= ~ ( V_79 | V_80 ) ;
V_2 -> V_18 [ 1 ] |= V_81 ;
if ( V_2 != V_48 ) {
V_48 -> V_18 [ 15 ] &= ~ ( V_66 | V_67 ) ;
F_7 ( V_48 , V_42 , V_48 -> V_18 [ 15 ] ) ;
if ( ! ( V_48 -> V_18 [ 15 ] & V_78 ) ) {
V_48 -> V_18 [ 1 ] &= ~ V_82 ;
F_7 ( V_48 , V_27 , V_48 -> V_18 [ 1 ] ) ;
}
V_2 -> V_18 [ 15 ] &= ~ ( V_66 | V_65 ) ;
V_2 -> V_18 [ 1 ] &= ~ V_82 ;
} else {
if ( ! ( V_2 -> V_18 [ 15 ] & ( V_66 | V_67 ) ) )
V_2 -> V_18 [ 1 ] &= ~ V_82 ;
}
F_7 ( V_2 , V_42 , V_2 -> V_18 [ 15 ] ) ;
F_7 ( V_2 , V_27 , V_2 -> V_18 [ 1 ] ) ;
F_17 ( & V_17 -> V_26 ) ;
}
static void F_36 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
struct V_1 * V_48 = & V_17 -> V_2 [ V_60 ] ;
if ( V_2 == V_48 )
return;
F_14 ( & V_17 -> V_26 ) ;
if ( ! ( V_48 -> V_18 [ 1 ] & V_82 ) )
F_7 ( V_48 , V_22 , V_83 ) ;
V_48 -> V_18 [ 1 ] |= V_82 ;
V_48 -> V_18 [ 15 ] |= V_66 | V_67 ;
V_2 -> V_18 [ 15 ] |= V_66 | V_65 ;
F_28 ( V_2 ) ;
F_7 ( V_48 , V_27 , V_48 -> V_18 [ 1 ] ) ;
F_7 ( V_48 , V_42 , V_48 -> V_18 [ 15 ] ) ;
F_7 ( V_2 , V_42 , V_2 -> V_18 [ 15 ] ) ;
F_17 ( & V_17 -> V_26 ) ;
}
static void F_37 ( struct V_43 * V_44 , int V_84 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
if ( V_84 == - 1 )
V_2 -> V_18 [ 5 ] |= V_85 ;
else
V_2 -> V_18 [ 5 ] &= ~ V_85 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_5 ;
struct V_24 * V_17 = V_2 -> V_17 ;
struct V_86 * V_87 ;
unsigned int V_88 , V_46 , V_89 , V_90 ;
int V_91 ;
for ( V_91 = 16 ; V_91 ; V_91 -- ) {
F_14 ( & V_17 -> V_26 ) ;
V_88 = F_3 ( V_2 , V_22 ) & V_23 ;
F_17 ( & V_17 -> V_26 ) ;
if ( ! V_88 )
break;
F_14 ( & V_17 -> V_26 ) ;
V_46 = F_3 ( V_2 , V_27 ) & ( V_92 | V_93 | V_94 ) ;
V_89 = F_8 ( V_2 ) ;
F_17 ( & V_17 -> V_26 ) ;
V_90 = V_95 ;
V_87 = & V_44 -> V_87 ;
V_87 -> V_96 ++ ;
if ( ! V_89 )
V_46 |= V_2 -> V_97 ;
if ( F_39 ( V_46 &
( V_92 | V_93 | V_94 | V_98 | V_99 ) ) ) {
V_2 -> V_97 = 0 ;
if ( V_46 & ( V_92 | V_93 | V_94 ) ) {
F_14 ( & V_17 -> V_26 ) ;
F_7 ( V_2 , V_22 , V_100 ) ;
F_17 ( & V_17 -> V_26 ) ;
}
if ( V_46 & ( V_98 | V_99 ) ) {
V_87 -> V_101 ++ ;
if ( V_46 & V_98 )
continue;
} else if ( V_46 & V_93 )
V_87 -> V_102 ++ ;
else if ( V_46 & V_94 )
V_87 -> V_103 ++ ;
if ( V_46 & V_92 )
V_87 -> V_104 ++ ;
V_46 &= V_44 -> V_105 ;
if ( V_46 & V_99 )
V_90 = V_106 ;
else if ( V_46 & V_93 )
V_90 = V_107 ;
else if ( V_46 & V_94 )
V_90 = V_108 ;
}
if ( F_40 ( V_44 , V_89 ) )
continue;
F_41 ( V_44 , V_46 , V_92 , V_89 , V_90 ) ;
}
F_42 ( & V_44 -> V_109 -> V_5 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_110 * V_111 = & V_2 -> V_5 . V_109 -> V_111 ;
if ( V_2 -> V_5 . V_112 ) {
F_9 ( V_2 , V_2 -> V_5 . V_112 ) ;
V_2 -> V_5 . V_87 . V_113 ++ ;
V_2 -> V_5 . V_112 = 0 ;
return;
}
if ( F_43 ( V_111 ) || F_44 ( & V_2 -> V_5 ) ) {
F_31 ( V_2 ) ;
return;
}
F_9 ( V_2 , V_111 -> V_114 [ V_111 -> V_115 ] ) ;
V_111 -> V_115 = ( V_111 -> V_115 + 1 ) & ( V_116 - 1 ) ;
V_2 -> V_5 . V_87 . V_113 ++ ;
if ( F_45 ( V_111 ) < V_117 )
F_46 ( & V_2 -> V_5 ) ;
if ( F_43 ( V_111 ) )
F_31 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_24 * V_17 = V_2 -> V_17 ;
F_14 ( & V_17 -> V_26 ) ;
F_34 ( V_2 ) ;
F_17 ( & V_17 -> V_26 ) ;
}
static void F_48 ( struct V_1 * V_2 , struct V_1 * V_48 )
{
struct V_43 * V_44 = & V_2 -> V_5 ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned int V_62 ;
T_1 V_46 , V_101 ;
F_14 ( & V_17 -> V_26 ) ;
V_46 = F_3 ( V_2 , V_22 ) ;
if ( V_2 -> V_18 [ 15 ] & V_78 ) {
V_101 = V_46 & V_118 ;
if ( V_101 && ! V_2 -> V_101 ) {
F_17 ( & V_17 -> V_26 ) ;
if ( F_49 ( V_44 ) )
V_2 -> V_97 = V_98 ;
else
V_2 -> V_97 = V_99 ;
F_14 ( & V_17 -> V_26 ) ;
}
V_2 -> V_101 = V_101 ;
}
if ( V_2 != V_48 ) {
V_62 = F_28 ( V_2 ) ;
F_17 ( & V_17 -> V_26 ) ;
if ( V_62 & V_54 )
F_50 ( V_44 ,
V_2 -> V_52 & V_54 ) ;
if ( V_62 & V_56 )
F_51 ( V_44 ,
V_2 -> V_52 & V_56 ) ;
if ( V_62 & V_57 )
V_44 -> V_87 . V_119 ++ ;
if ( V_62 & V_59 )
V_44 -> V_87 . V_120 ++ ;
if ( V_62 )
F_52 ( & V_44 -> V_109 -> V_5 . V_121 ) ;
F_14 ( & V_17 -> V_26 ) ;
}
F_7 ( V_2 , V_22 , V_83 ) ;
F_17 ( & V_17 -> V_26 ) ;
}
static T_4 F_53 ( int V_20 , void * V_122 )
{
struct V_24 * V_17 = V_122 ;
struct V_1 * V_48 = & V_17 -> V_2 [ V_60 ] ;
struct V_1 * V_49 = & V_17 -> V_2 [ V_123 ] ;
T_4 V_46 = V_124 ;
T_1 V_125 ;
int V_91 ;
for ( V_91 = 16 ; V_91 ; V_91 -- ) {
F_14 ( & V_17 -> V_26 ) ;
V_125 = F_3 ( V_48 , V_29 ) ;
F_17 ( & V_17 -> V_26 ) ;
if ( ! V_125 )
break;
if ( V_125 & V_126 )
F_38 ( V_49 ) ;
if ( V_125 & V_127 )
F_38 ( V_48 ) ;
if ( V_125 & V_128 )
F_48 ( V_49 , V_48 ) ;
if ( V_125 & V_129 )
F_48 ( V_48 , V_48 ) ;
if ( V_125 & V_130 )
F_47 ( V_49 ) ;
if ( V_125 & V_131 )
F_47 ( V_48 ) ;
V_46 = V_132 ;
}
return V_46 ;
}
static int F_54 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
int V_133 ;
int V_134 ;
V_133 = F_55 ( 1 , & V_17 -> V_133 ) ;
if ( V_133 == 1 ) {
V_134 = F_56 ( V_2 -> V_5 . V_20 , F_53 ,
V_135 , L_5 , V_17 ) ;
if ( V_134 ) {
F_57 ( - 1 , & V_17 -> V_133 ) ;
F_11 ( V_136 L_6 ,
V_2 -> V_5 . V_20 ) ;
return V_134 ;
}
}
F_24 ( & V_17 -> V_26 , V_45 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , V_22 , V_100 ) ;
F_7 ( V_2 , V_22 , V_76 ) ;
if ( ! ( V_2 -> V_18 [ 1 ] & V_82 ) )
F_7 ( V_2 , V_22 , V_83 ) ;
V_2 -> V_18 [ 1 ] &= ~ V_79 ;
V_2 -> V_18 [ 1 ] |= V_137 | V_80 | V_82 ;
V_2 -> V_18 [ 3 ] |= V_30 ;
V_2 -> V_18 [ 15 ] |= V_78 ;
F_7 ( V_2 , V_27 , V_2 -> V_18 [ 1 ] ) ;
F_7 ( V_2 , V_29 , V_2 -> V_18 [ 3 ] ) ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
F_7 ( V_2 , V_42 , V_2 -> V_18 [ 15 ] ) ;
V_2 -> V_52 = F_27 ( V_2 ) ;
V_2 -> V_101 = F_3 ( V_2 , V_22 ) & V_118 ;
V_2 -> V_77 = 1 ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
return 0 ;
}
static void F_58 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
int V_133 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_2 -> V_18 [ 3 ] &= ~ V_30 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
F_7 ( V_2 , V_29 , V_2 -> V_18 [ 3 ] ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
V_133 = F_55 ( - 1 , & V_17 -> V_133 ) ;
if ( ! V_133 )
F_59 ( V_2 -> V_5 . V_20 , V_17 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_24 * V_17 = V_2 -> V_17 ;
int V_20 ;
unsigned long V_45 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_20 = ! F_61 ( V_45 ) ;
if ( ! V_17 -> V_138 ) {
F_3 ( V_2 , V_22 ) ;
F_20 ( V_2 , V_20 ) ;
F_7 ( V_2 , V_34 , V_139 ) ;
F_2 ( 10 ) ;
F_7 ( V_2 , V_34 , 0 ) ;
V_17 -> V_138 = 1 ;
}
F_21 ( V_2 , V_2 -> V_18 , V_20 ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static void F_62 ( struct V_43 * V_44 , struct V_140 * V_141 ,
struct V_140 * V_142 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
struct V_1 * V_48 = & V_17 -> V_2 [ V_60 ] ;
int V_20 ;
unsigned int V_143 , V_144 ;
unsigned long V_45 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_20 = ! F_61 ( V_45 ) ;
V_2 -> V_18 [ 3 ] &= ~ V_145 ;
V_2 -> V_18 [ 5 ] &= ~ V_146 ;
switch ( V_141 -> V_147 & V_148 ) {
case V_149 :
V_2 -> V_18 [ 3 ] |= V_150 ;
V_2 -> V_18 [ 5 ] |= V_151 ;
break;
case V_152 :
V_2 -> V_18 [ 3 ] |= V_153 ;
V_2 -> V_18 [ 5 ] |= V_154 ;
break;
case V_155 :
V_2 -> V_18 [ 3 ] |= V_156 ;
V_2 -> V_18 [ 5 ] |= V_157 ;
break;
case V_158 :
default:
V_2 -> V_18 [ 3 ] |= V_159 ;
V_2 -> V_18 [ 5 ] |= V_160 ;
break;
}
V_2 -> V_18 [ 4 ] &= ~ ( V_161 | V_162 | V_163 | V_164 ) ;
if ( V_141 -> V_147 & V_165 )
V_2 -> V_18 [ 4 ] |= V_166 ;
else
V_2 -> V_18 [ 4 ] |= V_167 ;
if ( V_141 -> V_147 & V_168 )
V_2 -> V_18 [ 4 ] |= V_163 ;
if ( ! ( V_141 -> V_147 & V_169 ) )
V_2 -> V_18 [ 4 ] |= V_164 ;
switch ( V_2 -> V_170 ) {
case 64 :
V_2 -> V_18 [ 4 ] |= V_171 ;
break;
case 32 :
V_2 -> V_18 [ 4 ] |= V_172 ;
break;
case 16 :
V_2 -> V_18 [ 4 ] |= V_173 ;
break;
case 1 :
V_2 -> V_18 [ 4 ] |= V_174 ;
break;
default:
F_63 () ;
}
V_143 = F_64 ( V_44 , V_141 , V_142 , 0 ,
V_44 -> V_175 / V_2 -> V_170 / 4 ) ;
V_144 = F_65 ( V_143 , V_44 -> V_175 / V_2 -> V_170 ) ;
V_2 -> V_18 [ 12 ] = V_144 & 0xff ;
V_2 -> V_18 [ 13 ] = ( V_144 >> 8 ) & 0xff ;
F_66 ( V_44 , V_141 -> V_147 , V_143 ) ;
V_44 -> V_105 = V_92 ;
if ( V_141 -> V_176 & V_177 )
V_44 -> V_105 |= V_93 | V_94 ;
if ( V_141 -> V_176 & ( V_178 | V_179 | V_180 ) )
V_44 -> V_105 |= V_99 ;
V_44 -> V_181 = 0 ;
if ( V_141 -> V_176 & V_182 )
V_44 -> V_181 |= V_93 | V_94 ;
if ( V_141 -> V_176 & V_178 ) {
V_44 -> V_181 |= V_99 ;
if ( V_141 -> V_176 & V_182 )
V_44 -> V_181 |= V_92 ;
}
if ( V_141 -> V_147 & V_183 )
V_2 -> V_18 [ 3 ] |= V_30 ;
else
V_2 -> V_18 [ 3 ] &= ~ V_30 ;
if ( V_2 != V_48 ) {
if ( ! ( V_141 -> V_147 & V_184 ) ) {
V_2 -> V_18 [ 15 ] |= V_66 ;
} else
V_2 -> V_18 [ 15 ] &= ~ V_66 ;
if ( V_141 -> V_147 & V_185 ) {
V_2 -> V_18 [ 15 ] |= V_65 ;
} else
V_2 -> V_18 [ 15 ] &= ~ V_65 ;
F_28 ( V_2 ) ;
}
F_21 ( V_2 , V_2 -> V_18 , V_20 ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static void F_67 ( struct V_43 * V_44 , unsigned int V_109 ,
unsigned int V_186 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
if ( V_109 < 3 )
V_2 -> V_18 [ 5 ] |= V_32 ;
else
V_2 -> V_18 [ 5 ] &= ~ V_32 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
}
static const char * F_68 ( struct V_43 * V_44 )
{
return L_7 ;
}
static void F_69 ( struct V_43 * V_44 )
{
F_70 ( V_44 -> V_6 ) ;
V_44 -> V_6 = 0 ;
F_71 ( V_44 -> V_187 , V_188 ) ;
}
static int F_72 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_6 )
V_44 -> V_6 = F_73 ( V_44 -> V_187 ,
V_188 ) ;
if ( ! V_44 -> V_6 ) {
F_11 ( V_136 L_8 ) ;
return - V_189 ;
}
return 0 ;
}
static int F_74 ( struct V_43 * V_44 )
{
int V_134 ;
if ( ! F_75 ( V_44 -> V_187 , V_188 , L_5 ) ) {
F_11 ( V_136 L_9 ) ;
return - V_190 ;
}
V_134 = F_72 ( V_44 ) ;
if ( V_134 ) {
F_71 ( V_44 -> V_187 , V_188 ) ;
return V_134 ;
}
return 0 ;
}
static void F_76 ( struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
if ( V_45 & V_191 ) {
if ( F_74 ( V_44 ) )
return;
V_44 -> type = V_192 ;
F_60 ( V_2 ) ;
}
}
static int F_77 ( struct V_43 * V_44 , struct V_193 * V_194 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
int V_134 = 0 ;
if ( V_194 -> type != V_195 && V_194 -> type != V_192 )
V_134 = - V_196 ;
if ( V_194 -> V_20 != V_44 -> V_20 )
V_134 = - V_196 ;
if ( V_194 -> V_197 != V_44 -> V_175 / V_2 -> V_170 / 4 )
V_134 = - V_196 ;
return V_134 ;
}
static int T_5 F_78 ( void )
{
static int V_198 ;
struct V_199 V_199 ;
int V_200 , V_201 , V_20 ;
int V_202 = 0 ;
int V_12 ;
if ( V_198 )
return 0 ;
V_20 = V_203 [ V_204 ] ;
if ( V_20 >= 0 ) {
V_199 . V_17 [ V_202 ] = V_205 ;
V_199 . V_20 [ V_202 ] = V_203 [ V_204 ] ;
V_202 ++ ;
}
V_20 = V_203 [ V_206 ] ;
if ( V_20 >= 0 ) {
V_199 . V_17 [ V_202 ] = V_207 ;
V_199 . V_20 [ V_202 ] = V_203 [ V_206 ] ;
V_202 ++ ;
}
if ( ! V_202 )
return - V_208 ;
V_198 = 1 ;
for ( V_200 = 0 ; V_200 < V_202 ; V_200 ++ ) {
F_79 ( & V_16 [ V_200 ] . V_26 ) ;
for ( V_201 = 0 ; V_201 < V_15 ; V_201 ++ ) {
struct V_1 * V_2 = & V_16 [ V_200 ] . V_2 [ V_201 ] ;
struct V_43 * V_44 = & V_2 -> V_5 ;
V_2 -> V_17 = & V_16 [ V_200 ] ;
V_2 -> V_170 = 16 ;
V_44 -> V_20 = V_199 . V_20 [ V_200 ] ;
V_44 -> V_175 = V_209 ;
V_44 -> V_210 = 1 ;
V_44 -> V_211 = V_212 ;
V_44 -> V_45 = V_213 ;
V_44 -> V_214 = & V_215 ;
V_44 -> line = V_200 * V_15 + V_201 ;
V_44 -> V_187 = V_216 +
V_199 . V_17 [ V_200 ] +
( V_201 ^ V_123 ) * V_188 ;
for ( V_12 = 0 ; V_12 < V_217 ; V_12 ++ )
V_2 -> V_18 [ V_12 ] = V_218 [ V_12 ] ;
}
}
return 0 ;
}
static void F_80 ( struct V_43 * V_44 , int V_89 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
int V_20 ;
unsigned long V_45 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_20 = ! F_61 ( V_45 ) ;
if ( F_19 ( V_2 , V_20 ) )
F_9 ( V_2 , V_89 ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static void F_81 ( struct V_219 * V_220 , const char * V_221 ,
unsigned int V_91 )
{
int V_200 = V_220 -> V_222 / V_15 , V_201 = V_220 -> V_222 % V_15 ;
struct V_1 * V_2 = & V_16 [ V_200 ] . V_2 [ V_201 ] ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
T_1 V_223 , V_224 ;
int V_20 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_223 = V_2 -> V_18 [ 1 ] ;
V_224 = V_2 -> V_18 [ 5 ] ;
if ( V_223 & V_80 ) {
V_2 -> V_18 [ 1 ] = V_223 & ~ V_80 ;
F_7 ( V_2 , V_27 , V_2 -> V_18 [ 1 ] ) ;
}
if ( ! ( V_224 & V_32 ) ) {
V_2 -> V_18 [ 5 ] = V_224 | V_32 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
}
F_25 ( & V_17 -> V_26 , V_45 ) ;
F_82 ( & V_2 -> V_5 , V_221 , V_91 , F_80 ) ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_20 = ! F_61 ( V_45 ) ;
F_20 ( V_2 , V_20 ) ;
if ( ! ( V_224 & V_32 ) ) {
V_2 -> V_18 [ 5 ] &= ~ V_32 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
}
if ( V_223 & V_80 ) {
V_2 -> V_18 [ 1 ] |= V_80 ;
F_7 ( V_2 , V_27 , V_2 -> V_18 [ 1 ] ) ;
if ( ! V_2 -> V_77 )
F_34 ( V_2 ) ;
}
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static int T_5 F_83 ( struct V_219 * V_220 , char * V_225 )
{
int V_200 = V_220 -> V_222 / V_15 , V_201 = V_220 -> V_222 % V_15 ;
struct V_1 * V_2 = & V_16 [ V_200 ] . V_2 [ V_201 ] ;
struct V_43 * V_44 = & V_2 -> V_5 ;
int V_143 = 9600 ;
int V_226 = 8 ;
int V_103 = 'n' ;
int V_227 = 'n' ;
int V_134 ;
V_134 = F_72 ( V_44 ) ;
if ( V_134 )
return V_134 ;
F_60 ( V_2 ) ;
F_67 ( V_44 , 0 , - 1 ) ;
if ( V_225 )
F_84 ( V_225 , & V_143 , & V_103 , & V_226 , & V_227 ) ;
return F_85 ( V_44 , V_220 , V_143 , V_103 , V_226 , V_227 ) ;
}
static int T_5 F_86 ( void )
{
int V_134 ;
V_134 = F_78 () ;
if ( V_134 )
return V_134 ;
F_87 ( & V_228 ) ;
return 0 ;
}
static int T_5 F_88 ( void )
{
int V_12 , V_134 ;
F_89 ( L_10 , V_229 , V_230 ) ;
V_134 = F_78 () ;
if ( V_134 )
return V_134 ;
V_134 = F_90 ( & V_231 ) ;
if ( V_134 )
return V_134 ;
for ( V_12 = 0 ; V_12 < V_14 * V_15 ; V_12 ++ ) {
struct V_24 * V_17 = & V_16 [ V_12 / V_15 ] ;
struct V_1 * V_2 = & V_17 -> V_2 [ V_12 % V_15 ] ;
struct V_43 * V_44 = & V_2 -> V_5 ;
if ( V_2 -> V_17 )
F_91 ( & V_231 , V_44 ) ;
}
return 0 ;
}
static void T_6 F_92 ( void )
{
int V_12 ;
for ( V_12 = V_14 * V_15 - 1 ; V_12 >= 0 ; V_12 -- ) {
struct V_24 * V_17 = & V_16 [ V_12 / V_15 ] ;
struct V_1 * V_2 = & V_17 -> V_2 [ V_12 % V_15 ] ;
struct V_43 * V_44 = & V_2 -> V_5 ;
if ( V_2 -> V_17 )
F_93 ( & V_231 , V_44 ) ;
}
F_94 ( & V_231 ) ;
}
