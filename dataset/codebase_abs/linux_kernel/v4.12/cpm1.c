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
unsigned int V_23 = 0 , V_24 , V_25 ;
int V_26 ;
F_13 ( L_2 ) ;
V_20 = F_18 ( NULL , NULL , L_3 ) ;
if ( V_20 == NULL )
V_20 = F_18 ( NULL , L_4 , L_5 ) ;
if ( V_20 == NULL ) {
F_19 ( V_27 L_6 ) ;
return V_23 ;
}
V_26 = F_20 ( V_20 , 0 , & V_22 ) ;
if ( V_26 )
goto V_28;
V_4 = F_21 ( V_22 . V_29 , F_22 ( & V_22 ) ) ;
if ( V_4 == NULL )
goto V_28;
V_23 = F_23 ( V_20 , 0 ) ;
if ( ! V_23 )
goto V_28;
V_24 = ( unsigned int ) F_24 ( V_23 ) ;
F_7 ( & V_4 -> V_30 ,
( V_31 | V_32 | V_33 | V_34 ) |
( ( V_24 / 2 ) << 13 ) | V_35 ) ;
F_7 ( & V_4 -> V_5 , 0 ) ;
V_8 = F_25 ( V_20 , 64 , & V_36 , NULL ) ;
if ( V_8 == NULL ) {
F_19 ( V_27 L_7 ) ;
V_23 = 0 ;
goto V_28;
}
V_20 = F_18 ( NULL , NULL , L_8 ) ;
if ( V_20 == NULL )
V_20 = F_26 ( NULL , L_9 ) ;
if ( V_20 == NULL ) {
F_19 ( V_27 L_10 ) ;
goto V_28;
}
V_25 = F_23 ( V_20 , 0 ) ;
if ( ! V_25 )
goto V_28;
if ( F_27 ( V_25 , & V_37 ) )
F_19 ( V_27 L_11 ) ;
F_5 ( & V_4 -> V_30 , V_38 ) ;
V_28:
F_28 ( V_20 ) ;
return V_23 ;
}
void T_3 F_29 ( void )
{
T_4 T_5 * V_39 ;
V_40 = F_21 ( F_30 () , 0x4000 ) ;
if ( ! V_40 ) {
F_19 ( V_41 L_12 ) ;
return;
}
V_42 = & V_40 -> V_43 ;
#ifndef F_31
F_9 ( & V_42 -> V_44 , V_45 | V_46 ) ;
while ( F_10 ( & V_42 -> V_44 ) & V_46 ) ;
#endif
#ifdef F_32
F_33 ( V_42 ) ;
#endif
V_39 = F_34 ( V_47 ) ;
if ( ( F_35 ( V_48 ) & 0xffff ) == 0x0900 )
F_7 ( & V_39 -> V_49 , 0x40 ) ;
else
F_7 ( & V_39 -> V_49 , 1 ) ;
F_36 ( V_39 ) ;
}
int F_37 ( T_6 V_50 , T_7 V_51 )
{
int V_52 , V_26 ;
unsigned long V_53 ;
if ( V_50 & 0xffffff0f )
return - V_54 ;
F_38 ( & V_55 , V_53 ) ;
V_26 = 0 ;
F_9 ( & V_42 -> V_44 , V_50 | V_46 | ( V_51 << 8 ) ) ;
for ( V_52 = 0 ; V_52 < V_56 ; V_52 ++ )
if ( ( F_10 ( & V_42 -> V_44 ) & V_46 ) == 0 )
goto V_57;
F_19 ( V_27 L_13 , V_58 ) ;
V_26 = - V_59 ;
V_57:
F_39 ( & V_55 , V_53 ) ;
return V_26 ;
}
void
F_40 ( T_8 V_60 , T_8 V_61 )
{
T_6 T_5 * V_62 ;
V_62 = & V_42 -> V_63 ;
V_62 += V_60 ;
if ( ( ( V_64 / V_61 ) - 1 ) < 4096 )
F_7 ( V_62 , ( ( ( V_64 / V_61 ) - 1 ) << 1 ) | V_65 ) ;
else
F_7 ( V_62 , ( ( ( V_66 / V_61 ) - 1 ) << 1 ) |
V_65 | V_67 ) ;
}
static void F_41 ( int V_68 , int V_69 , int V_53 )
{
struct V_70 T_5 * V_71 ;
V_69 = 1 << ( 31 - V_69 ) ;
if ( V_68 == V_72 )
V_71 = (struct V_70 T_5 * )
& V_40 -> V_43 . V_73 ;
else
V_71 = (struct V_70 T_5 * )
& V_40 -> V_43 . V_74 ;
if ( V_53 & V_75 )
F_5 ( & V_71 -> V_76 , V_69 ) ;
else
F_3 ( & V_71 -> V_76 , V_69 ) ;
if ( ! ( V_53 & V_77 ) )
F_5 ( & V_71 -> V_78 , V_69 ) ;
else
F_3 ( & V_71 -> V_78 , V_69 ) ;
if ( V_68 == V_72 ) {
if ( V_53 & V_79 )
F_42 ( & V_40 -> V_43 . V_80 , V_69 ) ;
else
F_43 ( & V_40 -> V_43 . V_80 , V_69 ) ;
}
if ( V_68 == V_81 ) {
if ( V_53 & V_82 )
F_5 ( & V_71 -> V_83 , V_69 ) ;
else
F_3 ( & V_71 -> V_83 , V_69 ) ;
if ( V_53 & V_79 )
F_5 ( & V_40 -> V_43 . V_84 , V_69 ) ;
else
F_3 ( & V_40 -> V_43 . V_84 , V_69 ) ;
}
}
static void F_44 ( int V_68 , int V_69 , int V_53 )
{
struct V_85 T_5 * V_71 =
(struct V_85 T_5 * ) & V_40 -> V_86 ;
V_69 = 1 << ( 15 - V_69 ) ;
if ( V_68 != 0 )
V_71 += V_68 - 1 ;
if ( V_53 & V_75 )
F_42 ( & V_71 -> V_76 , V_69 ) ;
else
F_43 ( & V_71 -> V_76 , V_69 ) ;
if ( ! ( V_53 & V_77 ) )
F_42 ( & V_71 -> V_78 , V_69 ) ;
else
F_43 ( & V_71 -> V_78 , V_69 ) ;
if ( V_68 == V_87 ) {
if ( V_53 & V_79 )
F_42 ( & V_71 -> V_88 , V_69 ) ;
else
F_43 ( & V_71 -> V_88 , V_69 ) ;
}
if ( V_68 == V_89 ) {
if ( V_53 & V_82 )
F_42 ( & V_71 -> V_88 , V_69 ) ;
else
F_43 ( & V_71 -> V_88 , V_69 ) ;
if ( V_53 & V_90 )
F_42 ( & V_71 -> V_91 , V_69 ) ;
else
F_43 ( & V_71 -> V_91 , V_69 ) ;
}
}
void F_45 ( enum V_92 V_68 , int V_69 , int V_53 )
{
if ( V_68 == V_72 || V_68 == V_81 )
F_41 ( V_68 , V_69 , V_53 ) ;
else
F_44 ( V_68 , V_69 , V_53 ) ;
}
int F_46 ( enum V_93 V_94 , int clock , int V_95 )
{
int V_96 ;
int V_52 , V_97 = 0 ;
T_6 T_5 * V_98 ;
T_6 V_99 = 7 ;
T_7 V_100 [] [ 3 ] = {
{ V_101 , V_102 , 0 } ,
{ V_101 , V_103 , 1 } ,
{ V_101 , V_104 , 2 } ,
{ V_101 , V_105 , 3 } ,
{ V_101 , V_106 , 4 } ,
{ V_101 , V_107 , 5 } ,
{ V_101 , V_108 , 6 } ,
{ V_101 , V_109 , 7 } ,
{ V_110 , V_102 , 0 } ,
{ V_110 , V_103 , 1 } ,
{ V_110 , V_104 , 2 } ,
{ V_110 , V_105 , 3 } ,
{ V_110 , V_106 , 4 } ,
{ V_110 , V_107 , 5 } ,
{ V_110 , V_108 , 6 } ,
{ V_110 , V_109 , 7 } ,
{ V_111 , V_102 , 0 } ,
{ V_111 , V_103 , 1 } ,
{ V_111 , V_104 , 2 } ,
{ V_111 , V_105 , 3 } ,
{ V_111 , V_112 , 4 } ,
{ V_111 , V_113 , 5 } ,
{ V_111 , V_114 , 6 } ,
{ V_111 , V_115 , 7 } ,
{ V_116 , V_102 , 0 } ,
{ V_116 , V_103 , 1 } ,
{ V_116 , V_104 , 2 } ,
{ V_116 , V_105 , 3 } ,
{ V_116 , V_112 , 4 } ,
{ V_116 , V_113 , 5 } ,
{ V_116 , V_114 , 6 } ,
{ V_116 , V_115 , 7 } ,
{ V_117 , V_102 , 0 } ,
{ V_117 , V_103 , 1 } ,
{ V_117 , V_104 , 2 } ,
{ V_117 , V_105 , 3 } ,
{ V_117 , V_106 , 4 } ,
{ V_117 , V_107 , 5 } ,
{ V_117 , V_108 , 6 } ,
{ V_117 , V_109 , 7 } ,
{ V_118 , V_102 , 0 } ,
{ V_118 , V_103 , 1 } ,
{ V_118 , V_104 , 2 } ,
{ V_118 , V_105 , 3 } ,
{ V_118 , V_112 , 4 } ,
{ V_118 , V_113 , 5 } ,
{ V_118 , V_114 , 6 } ,
{ V_118 , V_115 , 7 } ,
} ;
switch ( V_94 ) {
case V_101 :
V_98 = & V_40 -> V_43 . V_119 ;
V_96 = 0 ;
break;
case V_110 :
V_98 = & V_40 -> V_43 . V_119 ;
V_96 = 8 ;
break;
case V_111 :
V_98 = & V_40 -> V_43 . V_119 ;
V_96 = 16 ;
break;
case V_116 :
V_98 = & V_40 -> V_43 . V_119 ;
V_96 = 24 ;
break;
case V_117 :
V_98 = & V_40 -> V_43 . V_120 ;
V_96 = 12 ;
break;
case V_118 :
V_98 = & V_40 -> V_43 . V_120 ;
V_96 = 28 ;
break;
default:
F_19 ( V_27 L_14 ) ;
return - V_54 ;
}
for ( V_52 = 0 ; V_52 < F_47 ( V_100 ) ; V_52 ++ ) {
if ( V_100 [ V_52 ] [ 0 ] == V_94 && V_100 [ V_52 ] [ 1 ] == clock ) {
V_97 = V_100 [ V_52 ] [ 2 ] ;
break;
}
}
if ( V_52 == F_47 ( V_100 ) ) {
F_19 ( V_27 L_15 ) ;
return - V_54 ;
}
V_97 <<= V_96 ;
V_99 <<= V_96 ;
if ( V_98 == & V_40 -> V_43 . V_119 ) {
if ( V_95 == V_121 ) {
V_97 |= V_97 << 3 ;
V_99 |= V_99 << 3 ;
} else if ( V_95 == V_122 ) {
V_97 <<= 3 ;
V_99 <<= 3 ;
}
}
F_7 ( V_98 , ( F_48 ( V_98 ) & ~ V_99 ) | V_97 ) ;
return 0 ;
}
static void F_49 ( struct V_123 * V_124 )
{
struct V_125 * V_126 =
F_50 ( V_124 , struct V_125 , V_124 ) ;
struct V_85 T_5 * V_71 = V_124 -> V_127 ;
V_126 -> V_128 = F_10 ( & V_71 -> V_129 ) ;
}
static int F_51 ( struct V_130 * V_131 , unsigned int V_132 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_85 T_5 * V_71 = V_124 -> V_127 ;
T_9 V_133 ;
V_133 = 1 << ( 15 - V_132 ) ;
return ! ! ( F_10 ( & V_71 -> V_129 ) & V_133 ) ;
}
static void F_53 ( struct V_123 * V_124 , T_9 V_133 ,
int V_134 )
{
struct V_125 * V_126 = F_54 ( & V_124 -> V_131 ) ;
struct V_85 T_5 * V_71 = V_124 -> V_127 ;
if ( V_134 )
V_126 -> V_128 |= V_133 ;
else
V_126 -> V_128 &= ~ V_133 ;
F_9 ( & V_71 -> V_129 , V_126 -> V_128 ) ;
}
static void F_55 ( struct V_130 * V_131 , unsigned int V_132 , int V_134 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_125 * V_126 = F_54 ( & V_124 -> V_131 ) ;
unsigned long V_53 ;
T_9 V_133 = 1 << ( 15 - V_132 ) ;
F_38 ( & V_126 -> V_135 , V_53 ) ;
F_53 ( V_124 , V_133 , V_134 ) ;
F_39 ( & V_126 -> V_135 , V_53 ) ;
}
static int F_56 ( struct V_130 * V_131 , unsigned int V_132 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_125 * V_126 = F_54 ( & V_124 -> V_131 ) ;
return V_126 -> V_16 [ V_132 ] ? : - V_136 ;
}
static int F_57 ( struct V_130 * V_131 , unsigned int V_132 , int V_137 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_125 * V_126 = F_54 ( & V_124 -> V_131 ) ;
struct V_85 T_5 * V_71 = V_124 -> V_127 ;
unsigned long V_53 ;
T_9 V_133 = 1 << ( 15 - V_132 ) ;
F_38 ( & V_126 -> V_135 , V_53 ) ;
F_42 ( & V_71 -> V_76 , V_133 ) ;
F_53 ( V_124 , V_133 , V_137 ) ;
F_39 ( & V_126 -> V_135 , V_53 ) ;
return 0 ;
}
static int F_58 ( struct V_130 * V_131 , unsigned int V_132 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_125 * V_126 = F_54 ( & V_124 -> V_131 ) ;
struct V_85 T_5 * V_71 = V_124 -> V_127 ;
unsigned long V_53 ;
T_9 V_133 = 1 << ( 15 - V_132 ) ;
F_38 ( & V_126 -> V_135 , V_53 ) ;
F_43 ( & V_71 -> V_76 , V_133 ) ;
F_39 ( & V_126 -> V_135 , V_53 ) ;
return 0 ;
}
int F_59 ( struct V_19 * V_20 )
{
struct V_125 * V_126 ;
struct V_123 * V_124 ;
struct V_130 * V_131 ;
T_9 V_99 ;
V_126 = F_60 ( sizeof( * V_126 ) , V_138 ) ;
if ( ! V_126 )
return - V_139 ;
F_61 ( & V_126 -> V_135 ) ;
if ( ! F_62 ( V_20 , L_16 , & V_99 ) ) {
int V_52 , V_140 ;
for ( V_52 = 0 , V_140 = 0 ; V_52 < 16 ; V_52 ++ )
if ( V_99 & ( 1 << ( 15 - V_52 ) ) )
V_126 -> V_16 [ V_52 ] = F_23 ( V_20 , V_140 ++ ) ;
}
V_124 = & V_126 -> V_124 ;
V_131 = & V_124 -> V_131 ;
V_124 -> V_141 = F_49 ;
V_131 -> V_142 = 16 ;
V_131 -> V_143 = F_58 ;
V_131 -> V_144 = F_57 ;
V_131 -> V_145 = F_51 ;
V_131 -> V_146 = F_55 ;
V_131 -> V_147 = F_56 ;
return F_63 ( V_20 , V_124 , V_126 ) ;
}
static void F_64 ( struct V_123 * V_124 )
{
struct V_148 * V_126 =
F_50 ( V_124 , struct V_148 , V_124 ) ;
struct V_149 T_5 * V_71 = V_124 -> V_127 ;
V_126 -> V_128 = F_48 ( & V_71 -> V_129 ) ;
}
static int F_65 ( struct V_130 * V_131 , unsigned int V_132 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_149 T_5 * V_71 = V_124 -> V_127 ;
T_6 V_133 ;
V_133 = 1 << ( 31 - V_132 ) ;
return ! ! ( F_48 ( & V_71 -> V_129 ) & V_133 ) ;
}
static void F_66 ( struct V_123 * V_124 , T_6 V_133 ,
int V_134 )
{
struct V_148 * V_126 = F_54 ( & V_124 -> V_131 ) ;
struct V_149 T_5 * V_71 = V_124 -> V_127 ;
if ( V_134 )
V_126 -> V_128 |= V_133 ;
else
V_126 -> V_128 &= ~ V_133 ;
F_7 ( & V_71 -> V_129 , V_126 -> V_128 ) ;
}
static void F_67 ( struct V_130 * V_131 , unsigned int V_132 , int V_134 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_148 * V_126 = F_54 ( & V_124 -> V_131 ) ;
unsigned long V_53 ;
T_6 V_133 = 1 << ( 31 - V_132 ) ;
F_38 ( & V_126 -> V_135 , V_53 ) ;
F_66 ( V_124 , V_133 , V_134 ) ;
F_39 ( & V_126 -> V_135 , V_53 ) ;
}
static int F_68 ( struct V_130 * V_131 , unsigned int V_132 , int V_137 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_148 * V_126 = F_54 ( & V_124 -> V_131 ) ;
struct V_149 T_5 * V_71 = V_124 -> V_127 ;
unsigned long V_53 ;
T_6 V_133 = 1 << ( 31 - V_132 ) ;
F_38 ( & V_126 -> V_135 , V_53 ) ;
F_5 ( & V_71 -> V_76 , V_133 ) ;
F_66 ( V_124 , V_133 , V_137 ) ;
F_39 ( & V_126 -> V_135 , V_53 ) ;
return 0 ;
}
static int F_69 ( struct V_130 * V_131 , unsigned int V_132 )
{
struct V_123 * V_124 = F_52 ( V_131 ) ;
struct V_148 * V_126 = F_54 ( & V_124 -> V_131 ) ;
struct V_149 T_5 * V_71 = V_124 -> V_127 ;
unsigned long V_53 ;
T_6 V_133 = 1 << ( 31 - V_132 ) ;
F_38 ( & V_126 -> V_135 , V_53 ) ;
F_3 ( & V_71 -> V_76 , V_133 ) ;
F_39 ( & V_126 -> V_135 , V_53 ) ;
return 0 ;
}
int F_70 ( struct V_19 * V_20 )
{
struct V_148 * V_126 ;
struct V_123 * V_124 ;
struct V_130 * V_131 ;
V_126 = F_60 ( sizeof( * V_126 ) , V_138 ) ;
if ( ! V_126 )
return - V_139 ;
F_61 ( & V_126 -> V_135 ) ;
V_124 = & V_126 -> V_124 ;
V_131 = & V_124 -> V_131 ;
V_124 -> V_141 = F_64 ;
V_131 -> V_142 = 32 ;
V_131 -> V_143 = F_69 ;
V_131 -> V_144 = F_68 ;
V_131 -> V_145 = F_65 ;
V_131 -> V_146 = F_67 ;
return F_63 ( V_20 , V_124 , V_126 ) ;
}
static int F_71 ( void )
{
struct V_19 * V_20 ;
F_72 (np, NULL, L_17 )
F_59 ( V_20 ) ;
F_72 (np, NULL, L_18 )
F_70 ( V_20 ) ;
F_72 (np, NULL, L_19 )
F_59 ( V_20 ) ;
F_72 (np, NULL, L_20 )
F_59 ( V_20 ) ;
F_72 (np, NULL, L_21 )
F_73 ( V_20 ) ;
return 0 ;
}
