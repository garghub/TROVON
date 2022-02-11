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
F_42 ( V_44 -> V_109 -> V_5 . V_110 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_111 * V_112 = & V_2 -> V_5 . V_109 -> V_112 ;
if ( V_2 -> V_5 . V_113 ) {
F_9 ( V_2 , V_2 -> V_5 . V_113 ) ;
V_2 -> V_5 . V_87 . V_114 ++ ;
V_2 -> V_5 . V_113 = 0 ;
return;
}
if ( F_43 ( V_112 ) || F_44 ( & V_2 -> V_5 ) ) {
F_31 ( V_2 ) ;
return;
}
F_9 ( V_2 , V_112 -> V_115 [ V_112 -> V_116 ] ) ;
V_112 -> V_116 = ( V_112 -> V_116 + 1 ) & ( V_117 - 1 ) ;
V_2 -> V_5 . V_87 . V_114 ++ ;
if ( F_45 ( V_112 ) < V_118 )
F_46 ( & V_2 -> V_5 ) ;
if ( F_43 ( V_112 ) )
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
V_101 = V_46 & V_119 ;
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
V_44 -> V_87 . V_120 ++ ;
if ( V_62 & V_59 )
V_44 -> V_87 . V_121 ++ ;
if ( V_62 )
F_52 ( & V_44 -> V_109 -> V_5 . V_122 ) ;
F_14 ( & V_17 -> V_26 ) ;
}
F_7 ( V_2 , V_22 , V_83 ) ;
F_17 ( & V_17 -> V_26 ) ;
}
static T_4 F_53 ( int V_20 , void * V_123 )
{
struct V_24 * V_17 = V_123 ;
struct V_1 * V_48 = & V_17 -> V_2 [ V_60 ] ;
struct V_1 * V_49 = & V_17 -> V_2 [ V_124 ] ;
T_4 V_46 = V_125 ;
T_1 V_126 ;
int V_91 ;
for ( V_91 = 16 ; V_91 ; V_91 -- ) {
F_14 ( & V_17 -> V_26 ) ;
V_126 = F_3 ( V_48 , V_29 ) ;
F_17 ( & V_17 -> V_26 ) ;
if ( ! V_126 )
break;
if ( V_126 & V_127 )
F_38 ( V_49 ) ;
if ( V_126 & V_128 )
F_38 ( V_48 ) ;
if ( V_126 & V_129 )
F_48 ( V_49 , V_48 ) ;
if ( V_126 & V_130 )
F_48 ( V_48 , V_48 ) ;
if ( V_126 & V_131 )
F_47 ( V_49 ) ;
if ( V_126 & V_132 )
F_47 ( V_48 ) ;
V_46 = V_133 ;
}
return V_46 ;
}
static int F_54 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
int V_134 ;
int V_135 ;
V_134 = F_55 ( 1 , & V_17 -> V_134 ) ;
if ( V_134 == 1 ) {
V_135 = F_56 ( V_2 -> V_5 . V_20 , F_53 ,
V_136 , L_5 , V_17 ) ;
if ( V_135 ) {
F_57 ( - 1 , & V_17 -> V_134 ) ;
F_11 ( V_137 L_6 ,
V_2 -> V_5 . V_20 ) ;
return V_135 ;
}
}
F_24 ( & V_17 -> V_26 , V_45 ) ;
F_18 ( V_2 ) ;
F_7 ( V_2 , V_22 , V_100 ) ;
F_7 ( V_2 , V_22 , V_76 ) ;
if ( ! ( V_2 -> V_18 [ 1 ] & V_82 ) )
F_7 ( V_2 , V_22 , V_83 ) ;
V_2 -> V_18 [ 1 ] &= ~ V_79 ;
V_2 -> V_18 [ 1 ] |= V_138 | V_80 | V_82 ;
V_2 -> V_18 [ 3 ] |= V_30 ;
V_2 -> V_18 [ 15 ] |= V_78 ;
F_7 ( V_2 , V_27 , V_2 -> V_18 [ 1 ] ) ;
F_7 ( V_2 , V_29 , V_2 -> V_18 [ 3 ] ) ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
F_7 ( V_2 , V_42 , V_2 -> V_18 [ 15 ] ) ;
V_2 -> V_52 = F_27 ( V_2 ) ;
V_2 -> V_101 = F_3 ( V_2 , V_22 ) & V_119 ;
V_2 -> V_77 = 1 ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
return 0 ;
}
static void F_58 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
int V_134 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_2 -> V_18 [ 3 ] &= ~ V_30 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
F_7 ( V_2 , V_29 , V_2 -> V_18 [ 3 ] ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
V_134 = F_55 ( - 1 , & V_17 -> V_134 ) ;
if ( ! V_134 )
F_59 ( V_2 -> V_5 . V_20 , V_17 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_24 * V_17 = V_2 -> V_17 ;
int V_20 ;
unsigned long V_45 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_20 = ! F_61 ( V_45 ) ;
if ( ! V_17 -> V_139 ) {
F_3 ( V_2 , V_22 ) ;
F_20 ( V_2 , V_20 ) ;
F_7 ( V_2 , V_34 , V_140 ) ;
F_2 ( 10 ) ;
F_7 ( V_2 , V_34 , 0 ) ;
V_17 -> V_139 = 1 ;
}
F_21 ( V_2 , V_2 -> V_18 , V_20 ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static void F_62 ( struct V_43 * V_44 , struct V_141 * V_142 ,
struct V_141 * V_143 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
struct V_24 * V_17 = V_2 -> V_17 ;
struct V_1 * V_48 = & V_17 -> V_2 [ V_60 ] ;
int V_20 ;
unsigned int V_144 , V_145 ;
unsigned long V_45 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_20 = ! F_61 ( V_45 ) ;
V_2 -> V_18 [ 3 ] &= ~ V_146 ;
V_2 -> V_18 [ 5 ] &= ~ V_147 ;
switch ( V_142 -> V_148 & V_149 ) {
case V_150 :
V_2 -> V_18 [ 3 ] |= V_151 ;
V_2 -> V_18 [ 5 ] |= V_152 ;
break;
case V_153 :
V_2 -> V_18 [ 3 ] |= V_154 ;
V_2 -> V_18 [ 5 ] |= V_155 ;
break;
case V_156 :
V_2 -> V_18 [ 3 ] |= V_157 ;
V_2 -> V_18 [ 5 ] |= V_158 ;
break;
case V_159 :
default:
V_2 -> V_18 [ 3 ] |= V_160 ;
V_2 -> V_18 [ 5 ] |= V_161 ;
break;
}
V_2 -> V_18 [ 4 ] &= ~ ( V_162 | V_163 | V_164 | V_165 ) ;
if ( V_142 -> V_148 & V_166 )
V_2 -> V_18 [ 4 ] |= V_167 ;
else
V_2 -> V_18 [ 4 ] |= V_168 ;
if ( V_142 -> V_148 & V_169 )
V_2 -> V_18 [ 4 ] |= V_164 ;
if ( ! ( V_142 -> V_148 & V_170 ) )
V_2 -> V_18 [ 4 ] |= V_165 ;
switch ( V_2 -> V_171 ) {
case 64 :
V_2 -> V_18 [ 4 ] |= V_172 ;
break;
case 32 :
V_2 -> V_18 [ 4 ] |= V_173 ;
break;
case 16 :
V_2 -> V_18 [ 4 ] |= V_174 ;
break;
case 1 :
V_2 -> V_18 [ 4 ] |= V_175 ;
break;
default:
F_63 () ;
}
V_144 = F_64 ( V_44 , V_142 , V_143 , 0 ,
V_44 -> V_176 / V_2 -> V_171 / 4 ) ;
V_145 = F_65 ( V_144 , V_44 -> V_176 / V_2 -> V_171 ) ;
V_2 -> V_18 [ 12 ] = V_145 & 0xff ;
V_2 -> V_18 [ 13 ] = ( V_145 >> 8 ) & 0xff ;
F_66 ( V_44 , V_142 -> V_148 , V_144 ) ;
V_44 -> V_105 = V_92 ;
if ( V_142 -> V_177 & V_178 )
V_44 -> V_105 |= V_93 | V_94 ;
if ( V_142 -> V_177 & ( V_179 | V_180 ) )
V_44 -> V_105 |= V_99 ;
V_44 -> V_181 = 0 ;
if ( V_142 -> V_177 & V_182 )
V_44 -> V_181 |= V_93 | V_94 ;
if ( V_142 -> V_177 & V_183 ) {
V_44 -> V_181 |= V_99 ;
if ( V_142 -> V_177 & V_182 )
V_44 -> V_181 |= V_92 ;
}
if ( V_142 -> V_148 & V_184 )
V_2 -> V_18 [ 3 ] |= V_30 ;
else
V_2 -> V_18 [ 3 ] &= ~ V_30 ;
if ( V_2 != V_48 ) {
if ( ! ( V_142 -> V_148 & V_185 ) ) {
V_2 -> V_18 [ 15 ] |= V_66 ;
} else
V_2 -> V_18 [ 15 ] &= ~ V_66 ;
if ( V_142 -> V_148 & V_186 ) {
V_2 -> V_18 [ 15 ] |= V_65 ;
} else
V_2 -> V_18 [ 15 ] &= ~ V_65 ;
F_28 ( V_2 ) ;
}
F_21 ( V_2 , V_2 -> V_18 , V_20 ) ;
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static void F_67 ( struct V_43 * V_44 , unsigned int V_109 ,
unsigned int V_187 )
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
F_71 ( V_44 -> V_188 , V_189 ) ;
}
static int F_72 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_6 )
V_44 -> V_6 = F_73 ( V_44 -> V_188 ,
V_189 ) ;
if ( ! V_44 -> V_6 ) {
F_11 ( V_137 L_8 ) ;
return - V_190 ;
}
return 0 ;
}
static int F_74 ( struct V_43 * V_44 )
{
int V_135 ;
if ( ! F_75 ( V_44 -> V_188 , V_189 , L_5 ) ) {
F_11 ( V_137 L_9 ) ;
return - V_191 ;
}
V_135 = F_72 ( V_44 ) ;
if ( V_135 ) {
F_71 ( V_44 -> V_188 , V_189 ) ;
return V_135 ;
}
return 0 ;
}
static void F_76 ( struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
if ( V_45 & V_192 ) {
if ( F_74 ( V_44 ) )
return;
V_44 -> type = V_193 ;
F_60 ( V_2 ) ;
}
}
static int F_77 ( struct V_43 * V_44 , struct V_194 * V_195 )
{
struct V_1 * V_2 = F_23 ( V_44 ) ;
int V_135 = 0 ;
if ( V_195 -> type != V_196 && V_195 -> type != V_193 )
V_135 = - V_197 ;
if ( V_195 -> V_20 != V_44 -> V_20 )
V_135 = - V_197 ;
if ( V_195 -> V_198 != V_44 -> V_176 / V_2 -> V_171 / 4 )
V_135 = - V_197 ;
return V_135 ;
}
static int T_5 F_78 ( void )
{
static int V_199 ;
struct V_200 V_200 ;
int V_201 , V_202 , V_20 ;
int V_203 = 0 ;
int V_12 ;
if ( V_199 )
return 0 ;
V_20 = V_204 [ V_205 ] ;
if ( V_20 >= 0 ) {
V_200 . V_17 [ V_203 ] = V_206 ;
V_200 . V_20 [ V_203 ] = V_204 [ V_205 ] ;
V_203 ++ ;
}
V_20 = V_204 [ V_207 ] ;
if ( V_20 >= 0 ) {
V_200 . V_17 [ V_203 ] = V_208 ;
V_200 . V_20 [ V_203 ] = V_204 [ V_207 ] ;
V_203 ++ ;
}
if ( ! V_203 )
return - V_209 ;
V_199 = 1 ;
for ( V_201 = 0 ; V_201 < V_203 ; V_201 ++ ) {
F_79 ( & V_16 [ V_201 ] . V_26 ) ;
for ( V_202 = 0 ; V_202 < V_15 ; V_202 ++ ) {
struct V_1 * V_2 = & V_16 [ V_201 ] . V_2 [ V_202 ] ;
struct V_43 * V_44 = & V_2 -> V_5 ;
V_2 -> V_17 = & V_16 [ V_201 ] ;
V_2 -> V_171 = 16 ;
V_44 -> V_20 = V_200 . V_20 [ V_201 ] ;
V_44 -> V_176 = V_210 ;
V_44 -> V_211 = 1 ;
V_44 -> V_212 = V_213 ;
V_44 -> V_45 = V_214 ;
V_44 -> V_215 = & V_216 ;
V_44 -> line = V_201 * V_15 + V_202 ;
V_44 -> V_188 = V_217 +
V_200 . V_17 [ V_201 ] +
( V_202 ^ V_124 ) * V_189 ;
for ( V_12 = 0 ; V_12 < V_218 ; V_12 ++ )
V_2 -> V_18 [ V_12 ] = V_219 [ V_12 ] ;
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
static void F_81 ( struct V_220 * V_221 , const char * V_222 ,
unsigned int V_91 )
{
int V_201 = V_221 -> V_223 / V_15 , V_202 = V_221 -> V_223 % V_15 ;
struct V_1 * V_2 = & V_16 [ V_201 ] . V_2 [ V_202 ] ;
struct V_24 * V_17 = V_2 -> V_17 ;
unsigned long V_45 ;
T_1 V_224 , V_225 ;
int V_20 ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_224 = V_2 -> V_18 [ 1 ] ;
V_225 = V_2 -> V_18 [ 5 ] ;
if ( V_224 & V_80 ) {
V_2 -> V_18 [ 1 ] = V_224 & ~ V_80 ;
F_7 ( V_2 , V_27 , V_2 -> V_18 [ 1 ] ) ;
}
if ( ! ( V_225 & V_32 ) ) {
V_2 -> V_18 [ 5 ] = V_225 | V_32 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
}
F_25 ( & V_17 -> V_26 , V_45 ) ;
F_82 ( & V_2 -> V_5 , V_222 , V_91 , F_80 ) ;
F_24 ( & V_17 -> V_26 , V_45 ) ;
V_20 = ! F_61 ( V_45 ) ;
F_20 ( V_2 , V_20 ) ;
if ( ! ( V_225 & V_32 ) ) {
V_2 -> V_18 [ 5 ] &= ~ V_32 ;
F_7 ( V_2 , V_31 , V_2 -> V_18 [ 5 ] ) ;
}
if ( V_224 & V_80 ) {
V_2 -> V_18 [ 1 ] |= V_80 ;
F_7 ( V_2 , V_27 , V_2 -> V_18 [ 1 ] ) ;
}
F_25 ( & V_17 -> V_26 , V_45 ) ;
}
static int T_5 F_83 ( struct V_220 * V_221 , char * V_226 )
{
int V_201 = V_221 -> V_223 / V_15 , V_202 = V_221 -> V_223 % V_15 ;
struct V_1 * V_2 = & V_16 [ V_201 ] . V_2 [ V_202 ] ;
struct V_43 * V_44 = & V_2 -> V_5 ;
int V_144 = 9600 ;
int V_227 = 8 ;
int V_103 = 'n' ;
int V_228 = 'n' ;
int V_135 ;
V_135 = F_72 ( V_44 ) ;
if ( V_135 )
return V_135 ;
F_60 ( V_2 ) ;
F_67 ( V_44 , 0 , - 1 ) ;
if ( V_226 )
F_84 ( V_226 , & V_144 , & V_103 , & V_227 , & V_228 ) ;
return F_85 ( V_44 , V_221 , V_144 , V_103 , V_227 , V_228 ) ;
}
static int T_5 F_86 ( void )
{
int V_135 ;
V_135 = F_78 () ;
if ( V_135 )
return V_135 ;
F_87 ( & V_229 ) ;
return 0 ;
}
static int T_5 F_88 ( void )
{
int V_12 , V_135 ;
F_89 ( L_10 , V_230 , V_231 ) ;
V_135 = F_78 () ;
if ( V_135 )
return V_135 ;
V_135 = F_90 ( & V_232 ) ;
if ( V_135 )
return V_135 ;
for ( V_12 = 0 ; V_12 < V_14 * V_15 ; V_12 ++ ) {
struct V_24 * V_17 = & V_16 [ V_12 / V_15 ] ;
struct V_1 * V_2 = & V_17 -> V_2 [ V_12 % V_15 ] ;
struct V_43 * V_44 = & V_2 -> V_5 ;
if ( V_2 -> V_17 )
F_91 ( & V_232 , V_44 ) ;
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
F_93 ( & V_232 , V_44 ) ;
}
F_94 ( & V_232 ) ;
}
