static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 , ( 1 << V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
F_5 ( & V_4 -> V_5 , ( 1 << V_3 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 = ( unsigned int ) F_2 ( V_2 ) ;
F_7 ( & V_4 -> V_6 , ( 1 << V_3 ) ) ;
}
int F_8 ( void )
{
int V_3 ;
F_9 ( & V_4 -> V_7 , 1 ) ;
V_3 = F_10 ( & V_4 -> V_7 ) ;
V_3 >>= 11 ;
return F_11 ( V_8 , V_3 ) ;
}
static int F_12 ( struct V_9 * V_10 , unsigned int V_11 ,
T_1 V_12 )
{
F_13 ( L_1 , V_11 , V_12 ) ;
F_14 ( V_11 , V_13 ) ;
F_15 ( V_11 , & V_14 , V_15 ) ;
return 0 ;
}
static T_2 F_16 ( int V_16 , void * V_17 )
{
return V_18 ;
}
unsigned int F_17 ( void )
{
struct V_19 * V_20 = NULL ;
struct V_21 V_22 ;
unsigned int V_23 = V_24 , V_25 , V_26 ;
int V_27 ;
F_13 ( L_2 ) ;
V_20 = F_18 ( NULL , NULL , L_3 ) ;
if ( V_20 == NULL )
V_20 = F_18 ( NULL , L_4 , L_5 ) ;
if ( V_20 == NULL ) {
F_19 ( V_28 L_6 ) ;
return V_23 ;
}
V_27 = F_20 ( V_20 , 0 , & V_22 ) ;
if ( V_27 )
goto V_29;
V_4 = F_21 ( V_22 . V_30 , V_22 . V_29 - V_22 . V_30 + 1 ) ;
if ( V_4 == NULL )
goto V_29;
V_23 = F_22 ( V_20 , 0 ) ;
if ( V_23 == V_24 )
goto V_29;
V_25 = ( unsigned int ) F_23 ( V_23 ) ;
F_7 ( & V_4 -> V_31 ,
( V_32 | V_33 | V_34 | V_35 ) |
( ( V_25 / 2 ) << 13 ) | V_36 ) ;
F_7 ( & V_4 -> V_5 , 0 ) ;
V_8 = F_24 ( V_20 , V_37 ,
64 , & V_38 , 64 ) ;
if ( V_8 == NULL ) {
F_19 ( V_28 L_7 ) ;
V_23 = V_24 ;
goto V_29;
}
V_20 = F_18 ( NULL , NULL , L_8 ) ;
if ( V_20 == NULL )
V_20 = F_25 ( NULL , L_9 ) ;
if ( V_20 == NULL ) {
F_19 ( V_28 L_10 ) ;
goto V_29;
}
V_26 = F_22 ( V_20 , 0 ) ;
if ( V_26 == V_24 )
goto V_29;
if ( F_26 ( V_26 , & V_39 ) )
F_19 ( V_28 L_11 ) ;
F_5 ( & V_4 -> V_31 , V_40 ) ;
V_29:
F_27 ( V_20 ) ;
return V_23 ;
}
void T_3 F_28 ( void )
{
T_4 T_5 * V_41 ;
V_42 = F_21 ( F_29 () , 0x4000 ) ;
if ( ! V_42 ) {
F_19 ( V_43 L_12 ) ;
return;
}
V_44 = & V_42 -> V_45 ;
#ifndef F_30
F_9 ( & V_44 -> V_46 , V_47 | V_48 ) ;
while ( F_10 ( & V_44 -> V_46 ) & V_48 ) ;
#endif
#ifdef F_31
F_32 ( V_44 ) ;
#endif
V_41 = F_33 ( V_49 ) ;
F_7 ( & V_41 -> V_50 , 1 ) ;
F_34 ( V_41 ) ;
F_35 () ;
}
int F_36 ( T_6 V_51 , T_7 V_52 )
{
int V_53 , V_27 ;
unsigned long V_54 ;
if ( V_51 & 0xffffff0f )
return - V_55 ;
F_37 ( & V_56 , V_54 ) ;
V_27 = 0 ;
F_9 ( & V_44 -> V_46 , V_51 | V_48 | ( V_52 << 8 ) ) ;
for ( V_53 = 0 ; V_53 < V_57 ; V_53 ++ )
if ( ( F_10 ( & V_44 -> V_46 ) & V_48 ) == 0 )
goto V_58;
F_19 ( V_28 L_13 , V_59 ) ;
V_27 = - V_60 ;
V_58:
F_38 ( & V_56 , V_54 ) ;
return V_27 ;
}
void
F_39 ( T_8 V_61 , T_8 V_62 )
{
T_6 T_5 * V_63 ;
V_63 = & V_44 -> V_64 ;
V_63 += V_61 ;
if ( ( ( V_65 / V_62 ) - 1 ) < 4096 )
F_7 ( V_63 , ( ( ( V_65 / V_62 ) - 1 ) << 1 ) | V_66 ) ;
else
F_7 ( V_63 , ( ( ( V_67 / V_62 ) - 1 ) << 1 ) |
V_66 | V_68 ) ;
}
static void F_40 ( int V_69 , int V_70 , int V_54 )
{
struct V_71 T_5 * V_72 ;
V_70 = 1 << ( 31 - V_70 ) ;
if ( V_69 == V_73 )
V_72 = (struct V_71 T_5 * )
& V_42 -> V_45 . V_74 ;
else
V_72 = (struct V_71 T_5 * )
& V_42 -> V_45 . V_75 ;
if ( V_54 & V_76 )
F_5 ( & V_72 -> V_77 , V_70 ) ;
else
F_3 ( & V_72 -> V_77 , V_70 ) ;
if ( ! ( V_54 & V_78 ) )
F_5 ( & V_72 -> V_79 , V_70 ) ;
else
F_3 ( & V_72 -> V_79 , V_70 ) ;
if ( V_69 == V_73 ) {
if ( V_54 & V_80 )
F_41 ( & V_42 -> V_45 . V_81 , V_70 ) ;
else
F_42 ( & V_42 -> V_45 . V_81 , V_70 ) ;
}
if ( V_69 == V_82 ) {
if ( V_54 & V_83 )
F_5 ( & V_72 -> V_84 , V_70 ) ;
else
F_3 ( & V_72 -> V_84 , V_70 ) ;
if ( V_54 & V_80 )
F_5 ( & V_42 -> V_45 . V_85 , V_70 ) ;
else
F_3 ( & V_42 -> V_45 . V_85 , V_70 ) ;
}
}
static void F_43 ( int V_69 , int V_70 , int V_54 )
{
struct V_86 T_5 * V_72 =
(struct V_86 T_5 * ) & V_42 -> V_87 ;
V_70 = 1 << ( 15 - V_70 ) ;
if ( V_69 != 0 )
V_72 += V_69 - 1 ;
if ( V_54 & V_76 )
F_41 ( & V_72 -> V_77 , V_70 ) ;
else
F_42 ( & V_72 -> V_77 , V_70 ) ;
if ( ! ( V_54 & V_78 ) )
F_41 ( & V_72 -> V_79 , V_70 ) ;
else
F_42 ( & V_72 -> V_79 , V_70 ) ;
if ( V_69 == V_88 ) {
if ( V_54 & V_80 )
F_41 ( & V_72 -> V_89 , V_70 ) ;
else
F_42 ( & V_72 -> V_89 , V_70 ) ;
}
if ( V_69 == V_90 ) {
if ( V_54 & V_83 )
F_41 ( & V_72 -> V_89 , V_70 ) ;
else
F_42 ( & V_72 -> V_89 , V_70 ) ;
}
}
void F_44 ( enum V_91 V_69 , int V_70 , int V_54 )
{
if ( V_69 == V_73 || V_69 == V_82 )
F_40 ( V_69 , V_70 , V_54 ) ;
else
F_43 ( V_69 , V_70 , V_54 ) ;
}
int F_45 ( enum V_92 V_93 , int clock , int V_94 )
{
int V_95 ;
int V_53 , V_96 = 0 ;
T_6 T_5 * V_97 ;
T_6 V_98 = 7 ;
T_7 V_99 [] [ 3 ] = {
{ V_100 , V_101 , 0 } ,
{ V_100 , V_102 , 1 } ,
{ V_100 , V_103 , 2 } ,
{ V_100 , V_104 , 3 } ,
{ V_100 , V_105 , 4 } ,
{ V_100 , V_106 , 5 } ,
{ V_100 , V_107 , 6 } ,
{ V_100 , V_108 , 7 } ,
{ V_109 , V_101 , 0 } ,
{ V_109 , V_102 , 1 } ,
{ V_109 , V_103 , 2 } ,
{ V_109 , V_104 , 3 } ,
{ V_109 , V_105 , 4 } ,
{ V_109 , V_106 , 5 } ,
{ V_109 , V_107 , 6 } ,
{ V_109 , V_108 , 7 } ,
{ V_110 , V_101 , 0 } ,
{ V_110 , V_102 , 1 } ,
{ V_110 , V_103 , 2 } ,
{ V_110 , V_104 , 3 } ,
{ V_110 , V_111 , 4 } ,
{ V_110 , V_112 , 5 } ,
{ V_110 , V_113 , 6 } ,
{ V_110 , V_114 , 7 } ,
{ V_115 , V_101 , 0 } ,
{ V_115 , V_102 , 1 } ,
{ V_115 , V_103 , 2 } ,
{ V_115 , V_104 , 3 } ,
{ V_115 , V_111 , 4 } ,
{ V_115 , V_112 , 5 } ,
{ V_115 , V_113 , 6 } ,
{ V_115 , V_114 , 7 } ,
{ V_116 , V_101 , 0 } ,
{ V_116 , V_102 , 1 } ,
{ V_116 , V_103 , 2 } ,
{ V_116 , V_104 , 3 } ,
{ V_116 , V_105 , 4 } ,
{ V_116 , V_106 , 5 } ,
{ V_116 , V_107 , 6 } ,
{ V_116 , V_108 , 7 } ,
{ V_117 , V_101 , 0 } ,
{ V_117 , V_102 , 1 } ,
{ V_117 , V_103 , 2 } ,
{ V_117 , V_104 , 3 } ,
{ V_117 , V_111 , 4 } ,
{ V_117 , V_112 , 5 } ,
{ V_117 , V_113 , 6 } ,
{ V_117 , V_114 , 7 } ,
} ;
switch ( V_93 ) {
case V_100 :
V_97 = & V_42 -> V_45 . V_118 ;
V_95 = 0 ;
break;
case V_109 :
V_97 = & V_42 -> V_45 . V_118 ;
V_95 = 8 ;
break;
case V_110 :
V_97 = & V_42 -> V_45 . V_118 ;
V_95 = 16 ;
break;
case V_115 :
V_97 = & V_42 -> V_45 . V_118 ;
V_95 = 24 ;
break;
case V_116 :
V_97 = & V_42 -> V_45 . V_119 ;
V_95 = 12 ;
break;
case V_117 :
V_97 = & V_42 -> V_45 . V_119 ;
V_95 = 28 ;
break;
default:
F_19 ( V_28 L_14 ) ;
return - V_55 ;
}
for ( V_53 = 0 ; V_53 < F_46 ( V_99 ) ; V_53 ++ ) {
if ( V_99 [ V_53 ] [ 0 ] == V_93 && V_99 [ V_53 ] [ 1 ] == clock ) {
V_96 = V_99 [ V_53 ] [ 2 ] ;
break;
}
}
if ( V_53 == F_46 ( V_99 ) ) {
F_19 ( V_28 L_15 ) ;
return - V_55 ;
}
V_96 <<= V_95 ;
V_98 <<= V_95 ;
if ( V_97 == & V_42 -> V_45 . V_118 ) {
if ( V_94 == V_120 ) {
V_96 |= V_96 << 3 ;
V_98 |= V_98 << 3 ;
} else if ( V_94 == V_121 ) {
V_96 <<= 3 ;
V_98 <<= 3 ;
}
}
F_7 ( V_97 , ( F_47 ( V_97 ) & ~ V_98 ) | V_96 ) ;
return 0 ;
}
static inline struct V_122 *
F_48 ( struct V_123 * V_124 )
{
return F_49 ( V_124 , struct V_122 , V_124 ) ;
}
static void F_50 ( struct V_123 * V_124 )
{
struct V_122 * V_125 = F_48 ( V_124 ) ;
struct V_86 T_5 * V_72 = V_124 -> V_126 ;
V_125 -> V_127 = F_10 ( & V_72 -> V_128 ) ;
}
static int F_51 ( struct V_129 * V_130 , unsigned int V_131 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_86 T_5 * V_72 = V_124 -> V_126 ;
T_9 V_132 ;
V_132 = 1 << ( 15 - V_131 ) ;
return ! ! ( F_10 ( & V_72 -> V_128 ) & V_132 ) ;
}
static void F_53 ( struct V_123 * V_124 , T_9 V_132 ,
int V_133 )
{
struct V_122 * V_125 = F_48 ( V_124 ) ;
struct V_86 T_5 * V_72 = V_124 -> V_126 ;
if ( V_133 )
V_125 -> V_127 |= V_132 ;
else
V_125 -> V_127 &= ~ V_132 ;
F_9 ( & V_72 -> V_128 , V_125 -> V_127 ) ;
}
static void F_54 ( struct V_129 * V_130 , unsigned int V_131 , int V_133 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_122 * V_125 = F_48 ( V_124 ) ;
unsigned long V_54 ;
T_9 V_132 = 1 << ( 15 - V_131 ) ;
F_37 ( & V_125 -> V_134 , V_54 ) ;
F_53 ( V_124 , V_132 , V_133 ) ;
F_38 ( & V_125 -> V_134 , V_54 ) ;
}
static int F_55 ( struct V_129 * V_130 , unsigned int V_131 , int V_135 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_122 * V_125 = F_48 ( V_124 ) ;
struct V_86 T_5 * V_72 = V_124 -> V_126 ;
unsigned long V_54 ;
T_9 V_132 = 1 << ( 15 - V_131 ) ;
F_37 ( & V_125 -> V_134 , V_54 ) ;
F_41 ( & V_72 -> V_77 , V_132 ) ;
F_53 ( V_124 , V_132 , V_135 ) ;
F_38 ( & V_125 -> V_134 , V_54 ) ;
return 0 ;
}
static int F_56 ( struct V_129 * V_130 , unsigned int V_131 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_122 * V_125 = F_48 ( V_124 ) ;
struct V_86 T_5 * V_72 = V_124 -> V_126 ;
unsigned long V_54 ;
T_9 V_132 = 1 << ( 15 - V_131 ) ;
F_37 ( & V_125 -> V_134 , V_54 ) ;
F_42 ( & V_72 -> V_77 , V_132 ) ;
F_38 ( & V_125 -> V_134 , V_54 ) ;
return 0 ;
}
int F_57 ( struct V_19 * V_20 )
{
struct V_122 * V_125 ;
struct V_123 * V_124 ;
struct V_129 * V_130 ;
V_125 = F_58 ( sizeof( * V_125 ) , V_136 ) ;
if ( ! V_125 )
return - V_137 ;
F_59 ( & V_125 -> V_134 ) ;
V_124 = & V_125 -> V_124 ;
V_130 = & V_124 -> V_130 ;
V_124 -> V_138 = F_50 ;
V_130 -> V_139 = 16 ;
V_130 -> V_140 = F_56 ;
V_130 -> V_141 = F_55 ;
V_130 -> V_142 = F_51 ;
V_130 -> V_143 = F_54 ;
return F_60 ( V_20 , V_124 ) ;
}
static inline struct V_144 *
F_61 ( struct V_123 * V_124 )
{
return F_49 ( V_124 , struct V_144 , V_124 ) ;
}
static void F_62 ( struct V_123 * V_124 )
{
struct V_144 * V_125 = F_61 ( V_124 ) ;
struct V_145 T_5 * V_72 = V_124 -> V_126 ;
V_125 -> V_127 = F_47 ( & V_72 -> V_128 ) ;
}
static int F_63 ( struct V_129 * V_130 , unsigned int V_131 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_145 T_5 * V_72 = V_124 -> V_126 ;
T_6 V_132 ;
V_132 = 1 << ( 31 - V_131 ) ;
return ! ! ( F_47 ( & V_72 -> V_128 ) & V_132 ) ;
}
static void F_64 ( struct V_123 * V_124 , T_6 V_132 ,
int V_133 )
{
struct V_144 * V_125 = F_61 ( V_124 ) ;
struct V_145 T_5 * V_72 = V_124 -> V_126 ;
if ( V_133 )
V_125 -> V_127 |= V_132 ;
else
V_125 -> V_127 &= ~ V_132 ;
F_7 ( & V_72 -> V_128 , V_125 -> V_127 ) ;
}
static void F_65 ( struct V_129 * V_130 , unsigned int V_131 , int V_133 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_144 * V_125 = F_61 ( V_124 ) ;
unsigned long V_54 ;
T_6 V_132 = 1 << ( 31 - V_131 ) ;
F_37 ( & V_125 -> V_134 , V_54 ) ;
F_64 ( V_124 , V_132 , V_133 ) ;
F_38 ( & V_125 -> V_134 , V_54 ) ;
}
static int F_66 ( struct V_129 * V_130 , unsigned int V_131 , int V_135 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_144 * V_125 = F_61 ( V_124 ) ;
struct V_145 T_5 * V_72 = V_124 -> V_126 ;
unsigned long V_54 ;
T_6 V_132 = 1 << ( 31 - V_131 ) ;
F_37 ( & V_125 -> V_134 , V_54 ) ;
F_5 ( & V_72 -> V_77 , V_132 ) ;
F_64 ( V_124 , V_132 , V_135 ) ;
F_38 ( & V_125 -> V_134 , V_54 ) ;
return 0 ;
}
static int F_67 ( struct V_129 * V_130 , unsigned int V_131 )
{
struct V_123 * V_124 = F_52 ( V_130 ) ;
struct V_144 * V_125 = F_61 ( V_124 ) ;
struct V_145 T_5 * V_72 = V_124 -> V_126 ;
unsigned long V_54 ;
T_6 V_132 = 1 << ( 31 - V_131 ) ;
F_37 ( & V_125 -> V_134 , V_54 ) ;
F_3 ( & V_72 -> V_77 , V_132 ) ;
F_38 ( & V_125 -> V_134 , V_54 ) ;
return 0 ;
}
int F_68 ( struct V_19 * V_20 )
{
struct V_144 * V_125 ;
struct V_123 * V_124 ;
struct V_129 * V_130 ;
V_125 = F_58 ( sizeof( * V_125 ) , V_136 ) ;
if ( ! V_125 )
return - V_137 ;
F_59 ( & V_125 -> V_134 ) ;
V_124 = & V_125 -> V_124 ;
V_130 = & V_124 -> V_130 ;
V_124 -> V_138 = F_62 ;
V_130 -> V_139 = 32 ;
V_130 -> V_140 = F_67 ;
V_130 -> V_141 = F_66 ;
V_130 -> V_142 = F_63 ;
V_130 -> V_143 = F_65 ;
return F_60 ( V_20 , V_124 ) ;
}
static int F_69 ( void )
{
struct V_19 * V_20 ;
F_70 (np, NULL, L_16 )
F_57 ( V_20 ) ;
F_70 (np, NULL, L_17 )
F_68 ( V_20 ) ;
F_70 (np, NULL, L_18 )
F_57 ( V_20 ) ;
F_70 (np, NULL, L_19 )
F_57 ( V_20 ) ;
F_70 (np, NULL, L_20 )
F_71 ( V_20 ) ;
return 0 ;
}
