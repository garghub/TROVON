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
}
}
void F_45 ( enum V_90 V_68 , int V_69 , int V_53 )
{
if ( V_68 == V_72 || V_68 == V_81 )
F_41 ( V_68 , V_69 , V_53 ) ;
else
F_44 ( V_68 , V_69 , V_53 ) ;
}
int F_46 ( enum V_91 V_92 , int clock , int V_93 )
{
int V_94 ;
int V_52 , V_95 = 0 ;
T_6 T_5 * V_96 ;
T_6 V_97 = 7 ;
T_7 V_98 [] [ 3 ] = {
{ V_99 , V_100 , 0 } ,
{ V_99 , V_101 , 1 } ,
{ V_99 , V_102 , 2 } ,
{ V_99 , V_103 , 3 } ,
{ V_99 , V_104 , 4 } ,
{ V_99 , V_105 , 5 } ,
{ V_99 , V_106 , 6 } ,
{ V_99 , V_107 , 7 } ,
{ V_108 , V_100 , 0 } ,
{ V_108 , V_101 , 1 } ,
{ V_108 , V_102 , 2 } ,
{ V_108 , V_103 , 3 } ,
{ V_108 , V_104 , 4 } ,
{ V_108 , V_105 , 5 } ,
{ V_108 , V_106 , 6 } ,
{ V_108 , V_107 , 7 } ,
{ V_109 , V_100 , 0 } ,
{ V_109 , V_101 , 1 } ,
{ V_109 , V_102 , 2 } ,
{ V_109 , V_103 , 3 } ,
{ V_109 , V_110 , 4 } ,
{ V_109 , V_111 , 5 } ,
{ V_109 , V_112 , 6 } ,
{ V_109 , V_113 , 7 } ,
{ V_114 , V_100 , 0 } ,
{ V_114 , V_101 , 1 } ,
{ V_114 , V_102 , 2 } ,
{ V_114 , V_103 , 3 } ,
{ V_114 , V_110 , 4 } ,
{ V_114 , V_111 , 5 } ,
{ V_114 , V_112 , 6 } ,
{ V_114 , V_113 , 7 } ,
{ V_115 , V_100 , 0 } ,
{ V_115 , V_101 , 1 } ,
{ V_115 , V_102 , 2 } ,
{ V_115 , V_103 , 3 } ,
{ V_115 , V_104 , 4 } ,
{ V_115 , V_105 , 5 } ,
{ V_115 , V_106 , 6 } ,
{ V_115 , V_107 , 7 } ,
{ V_116 , V_100 , 0 } ,
{ V_116 , V_101 , 1 } ,
{ V_116 , V_102 , 2 } ,
{ V_116 , V_103 , 3 } ,
{ V_116 , V_110 , 4 } ,
{ V_116 , V_111 , 5 } ,
{ V_116 , V_112 , 6 } ,
{ V_116 , V_113 , 7 } ,
} ;
switch ( V_92 ) {
case V_99 :
V_96 = & V_40 -> V_43 . V_117 ;
V_94 = 0 ;
break;
case V_108 :
V_96 = & V_40 -> V_43 . V_117 ;
V_94 = 8 ;
break;
case V_109 :
V_96 = & V_40 -> V_43 . V_117 ;
V_94 = 16 ;
break;
case V_114 :
V_96 = & V_40 -> V_43 . V_117 ;
V_94 = 24 ;
break;
case V_115 :
V_96 = & V_40 -> V_43 . V_118 ;
V_94 = 12 ;
break;
case V_116 :
V_96 = & V_40 -> V_43 . V_118 ;
V_94 = 28 ;
break;
default:
F_19 ( V_27 L_14 ) ;
return - V_54 ;
}
for ( V_52 = 0 ; V_52 < F_47 ( V_98 ) ; V_52 ++ ) {
if ( V_98 [ V_52 ] [ 0 ] == V_92 && V_98 [ V_52 ] [ 1 ] == clock ) {
V_95 = V_98 [ V_52 ] [ 2 ] ;
break;
}
}
if ( V_52 == F_47 ( V_98 ) ) {
F_19 ( V_27 L_15 ) ;
return - V_54 ;
}
V_95 <<= V_94 ;
V_97 <<= V_94 ;
if ( V_96 == & V_40 -> V_43 . V_117 ) {
if ( V_93 == V_119 ) {
V_95 |= V_95 << 3 ;
V_97 |= V_97 << 3 ;
} else if ( V_93 == V_120 ) {
V_95 <<= 3 ;
V_97 <<= 3 ;
}
}
F_7 ( V_96 , ( F_48 ( V_96 ) & ~ V_97 ) | V_95 ) ;
return 0 ;
}
static void F_49 ( struct V_121 * V_122 )
{
struct V_123 * V_124 =
F_50 ( V_122 , struct V_123 , V_122 ) ;
struct V_85 T_5 * V_71 = V_122 -> V_125 ;
V_124 -> V_126 = F_10 ( & V_71 -> V_127 ) ;
}
static int F_51 ( struct V_128 * V_129 , unsigned int V_130 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_85 T_5 * V_71 = V_122 -> V_125 ;
T_9 V_131 ;
V_131 = 1 << ( 15 - V_130 ) ;
return ! ! ( F_10 ( & V_71 -> V_127 ) & V_131 ) ;
}
static void F_53 ( struct V_121 * V_122 , T_9 V_131 ,
int V_132 )
{
struct V_123 * V_124 = F_54 ( & V_122 -> V_129 ) ;
struct V_85 T_5 * V_71 = V_122 -> V_125 ;
if ( V_132 )
V_124 -> V_126 |= V_131 ;
else
V_124 -> V_126 &= ~ V_131 ;
F_9 ( & V_71 -> V_127 , V_124 -> V_126 ) ;
}
static void F_55 ( struct V_128 * V_129 , unsigned int V_130 , int V_132 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_123 * V_124 = F_54 ( & V_122 -> V_129 ) ;
unsigned long V_53 ;
T_9 V_131 = 1 << ( 15 - V_130 ) ;
F_38 ( & V_124 -> V_133 , V_53 ) ;
F_53 ( V_122 , V_131 , V_132 ) ;
F_39 ( & V_124 -> V_133 , V_53 ) ;
}
static int F_56 ( struct V_128 * V_129 , unsigned int V_130 , int V_134 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_123 * V_124 = F_54 ( & V_122 -> V_129 ) ;
struct V_85 T_5 * V_71 = V_122 -> V_125 ;
unsigned long V_53 ;
T_9 V_131 = 1 << ( 15 - V_130 ) ;
F_38 ( & V_124 -> V_133 , V_53 ) ;
F_42 ( & V_71 -> V_76 , V_131 ) ;
F_53 ( V_122 , V_131 , V_134 ) ;
F_39 ( & V_124 -> V_133 , V_53 ) ;
return 0 ;
}
static int F_57 ( struct V_128 * V_129 , unsigned int V_130 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_123 * V_124 = F_54 ( & V_122 -> V_129 ) ;
struct V_85 T_5 * V_71 = V_122 -> V_125 ;
unsigned long V_53 ;
T_9 V_131 = 1 << ( 15 - V_130 ) ;
F_38 ( & V_124 -> V_133 , V_53 ) ;
F_43 ( & V_71 -> V_76 , V_131 ) ;
F_39 ( & V_124 -> V_133 , V_53 ) ;
return 0 ;
}
int F_58 ( struct V_19 * V_20 )
{
struct V_123 * V_124 ;
struct V_121 * V_122 ;
struct V_128 * V_129 ;
V_124 = F_59 ( sizeof( * V_124 ) , V_135 ) ;
if ( ! V_124 )
return - V_136 ;
F_60 ( & V_124 -> V_133 ) ;
V_122 = & V_124 -> V_122 ;
V_129 = & V_122 -> V_129 ;
V_122 -> V_137 = F_49 ;
V_129 -> V_138 = 16 ;
V_129 -> V_139 = F_57 ;
V_129 -> V_140 = F_56 ;
V_129 -> V_141 = F_51 ;
V_129 -> V_142 = F_55 ;
return F_61 ( V_20 , V_122 , V_124 ) ;
}
static void F_62 ( struct V_121 * V_122 )
{
struct V_143 * V_124 =
F_50 ( V_122 , struct V_143 , V_122 ) ;
struct V_144 T_5 * V_71 = V_122 -> V_125 ;
V_124 -> V_126 = F_48 ( & V_71 -> V_127 ) ;
}
static int F_63 ( struct V_128 * V_129 , unsigned int V_130 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_144 T_5 * V_71 = V_122 -> V_125 ;
T_6 V_131 ;
V_131 = 1 << ( 31 - V_130 ) ;
return ! ! ( F_48 ( & V_71 -> V_127 ) & V_131 ) ;
}
static void F_64 ( struct V_121 * V_122 , T_6 V_131 ,
int V_132 )
{
struct V_143 * V_124 = F_54 ( & V_122 -> V_129 ) ;
struct V_144 T_5 * V_71 = V_122 -> V_125 ;
if ( V_132 )
V_124 -> V_126 |= V_131 ;
else
V_124 -> V_126 &= ~ V_131 ;
F_7 ( & V_71 -> V_127 , V_124 -> V_126 ) ;
}
static void F_65 ( struct V_128 * V_129 , unsigned int V_130 , int V_132 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_143 * V_124 = F_54 ( & V_122 -> V_129 ) ;
unsigned long V_53 ;
T_6 V_131 = 1 << ( 31 - V_130 ) ;
F_38 ( & V_124 -> V_133 , V_53 ) ;
F_64 ( V_122 , V_131 , V_132 ) ;
F_39 ( & V_124 -> V_133 , V_53 ) ;
}
static int F_66 ( struct V_128 * V_129 , unsigned int V_130 , int V_134 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_143 * V_124 = F_54 ( & V_122 -> V_129 ) ;
struct V_144 T_5 * V_71 = V_122 -> V_125 ;
unsigned long V_53 ;
T_6 V_131 = 1 << ( 31 - V_130 ) ;
F_38 ( & V_124 -> V_133 , V_53 ) ;
F_5 ( & V_71 -> V_76 , V_131 ) ;
F_64 ( V_122 , V_131 , V_134 ) ;
F_39 ( & V_124 -> V_133 , V_53 ) ;
return 0 ;
}
static int F_67 ( struct V_128 * V_129 , unsigned int V_130 )
{
struct V_121 * V_122 = F_52 ( V_129 ) ;
struct V_143 * V_124 = F_54 ( & V_122 -> V_129 ) ;
struct V_144 T_5 * V_71 = V_122 -> V_125 ;
unsigned long V_53 ;
T_6 V_131 = 1 << ( 31 - V_130 ) ;
F_38 ( & V_124 -> V_133 , V_53 ) ;
F_3 ( & V_71 -> V_76 , V_131 ) ;
F_39 ( & V_124 -> V_133 , V_53 ) ;
return 0 ;
}
int F_68 ( struct V_19 * V_20 )
{
struct V_143 * V_124 ;
struct V_121 * V_122 ;
struct V_128 * V_129 ;
V_124 = F_59 ( sizeof( * V_124 ) , V_135 ) ;
if ( ! V_124 )
return - V_136 ;
F_60 ( & V_124 -> V_133 ) ;
V_122 = & V_124 -> V_122 ;
V_129 = & V_122 -> V_129 ;
V_122 -> V_137 = F_62 ;
V_129 -> V_138 = 32 ;
V_129 -> V_139 = F_67 ;
V_129 -> V_140 = F_66 ;
V_129 -> V_141 = F_63 ;
V_129 -> V_142 = F_65 ;
return F_61 ( V_20 , V_122 , V_124 ) ;
}
static int F_69 ( void )
{
struct V_19 * V_20 ;
F_70 (np, NULL, L_16 )
F_58 ( V_20 ) ;
F_70 (np, NULL, L_17 )
F_68 ( V_20 ) ;
F_70 (np, NULL, L_18 )
F_58 ( V_20 ) ;
F_70 (np, NULL, L_19 )
F_58 ( V_20 ) ;
F_70 (np, NULL, L_20 )
F_71 ( V_20 ) ;
return 0 ;
}
