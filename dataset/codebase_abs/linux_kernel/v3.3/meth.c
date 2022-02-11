static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
F_2 ( L_1 , V_2 -> V_5 ) ;
V_4 = 0 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ )
V_4 |= ( T_1 ) V_2 -> V_5 [ V_3 ] << ( ( 5 - V_3 ) * 8 ) ;
V_6 -> V_7 . V_8 = V_4 ;
}
static unsigned long F_3 ( struct V_9 * V_10 , unsigned long V_11 )
{
unsigned long V_12 ;
F_4 ( V_12 ) ;
V_6 -> V_7 . V_13 = ( V_10 -> V_14 << 5 ) | ( V_11 & 0x1f ) ;
F_5 ( 25 ) ;
V_6 -> V_7 . V_15 = 1 ;
F_5 ( 25 ) ;
F_4 ( V_12 ) ;
return V_12 & V_16 ;
}
static int F_6 ( struct V_9 * V_10 )
{
int V_3 ;
unsigned long V_17 , V_18 , V_19 ;
if( V_10 -> V_14 >= 0 && V_10 -> V_14 < 32 )
return 0 ;
F_7 ( & V_10 -> V_20 , V_19 ) ;
for ( V_3 = 0 ; V_3 < 32 ; ++ V_3 ) {
V_10 -> V_14 = V_3 ;
V_17 = F_3 ( V_10 , 2 ) ;
V_18 = F_3 ( V_10 , 3 ) ;
#if V_21 >= 2
switch ( ( V_17 << 12 ) | ( V_18 >> 4 ) ) {
case V_22 :
F_2 ( L_2 ) ;
break;
case V_23 :
F_2 ( L_3 ) ;
break;
case V_24 :
F_2 ( L_4 ) ;
break;
case V_25 :
F_2 ( L_5 ) ;
break;
}
#endif
if( V_17 != 0xffff && V_17 != 0x0000 ) {
F_2 ( L_6 , ( V_17 << 12 ) | ( V_18 >> 4 ) ) ;
break;
}
}
F_8 ( & V_10 -> V_20 , V_19 ) ;
if( V_10 -> V_14 < 32 ) {
return 0 ;
}
F_2 ( L_7 ) ;
V_10 -> V_14 = - 1 ;
return - V_26 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_27 = F_3 ( V_10 , 4 ) ;
unsigned long V_28 = F_3 ( V_10 , 5 ) ;
unsigned long V_29 = V_27 & V_28 ;
unsigned long V_30 , V_31 ;
if ( V_28 == 0xffff )
return;
V_31 = ( V_29 & 0x0380 ) ? V_32 : 0 ;
V_30 = ( ( V_29 & 0x0100 ) || ( V_29 & 0x01C0 ) == 0x0040 ) ?
V_33 : 0 ;
if ( ( V_10 -> V_34 & V_33 ) ^ V_30 ) {
F_2 ( L_8 , V_30 ? L_9 : L_10 ) ;
if ( V_30 )
V_10 -> V_34 |= V_33 ;
else
V_10 -> V_34 &= ~ V_33 ;
V_6 -> V_7 . V_34 = V_10 -> V_34 ;
}
if ( ( V_10 -> V_34 & V_32 ) ^ V_31 ) {
F_2 ( L_11 , V_31 ? 100 : 10 ) ;
if ( V_30 )
V_10 -> V_34 |= V_32 ;
else
V_10 -> V_34 &= ~ V_32 ;
V_6 -> V_7 . V_34 = V_10 -> V_34 ;
}
}
static int F_11 ( struct V_9 * V_10 )
{
V_10 -> V_35 = F_12 ( NULL , V_36 ,
& V_10 -> V_37 , V_38 ) ;
if ( ! V_10 -> V_35 )
return - V_39 ;
memset ( V_10 -> V_35 , 0 , V_36 ) ;
V_10 -> V_40 = V_10 -> V_41 = V_10 -> V_42 = 0 ;
V_6 -> V_7 . V_43 = V_10 -> V_37 ;
memset ( V_10 -> V_44 , 0 , sizeof( V_10 -> V_44 ) ) ;
memset ( V_10 -> V_45 , 0 , sizeof( V_10 -> V_45 ) ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
V_10 -> V_47 [ V_3 ] = F_14 ( V_48 , 0 ) ;
F_15 ( V_10 -> V_47 [ V_3 ] , V_49 ) ;
V_10 -> V_50 [ V_3 ] = ( V_51 * ) ( V_10 -> V_47 [ V_3 ] -> V_52 ) ;
V_10 -> V_53 [ V_3 ] =
F_16 ( NULL , V_10 -> V_50 [ V_3 ] ,
V_48 , V_54 ) ;
V_6 -> V_7 . V_55 = V_10 -> V_53 [ V_3 ] ;
}
V_10 -> V_56 = 0 ;
return 0 ;
}
static void F_17 ( struct V_9 * V_10 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ ) {
if ( V_10 -> V_44 [ V_3 ] )
F_18 ( V_10 -> V_44 [ V_3 ] ) ;
V_10 -> V_44 [ V_3 ] = NULL ;
}
F_19 ( NULL , V_36 , V_10 -> V_35 ,
V_10 -> V_37 ) ;
}
static void F_20 ( struct V_9 * V_10 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_46 ; V_3 ++ ) {
F_21 ( NULL , V_10 -> V_53 [ V_3 ] ,
V_48 , V_54 ) ;
V_10 -> V_50 [ V_3 ] = 0 ;
V_10 -> V_53 [ V_3 ] = 0 ;
F_22 ( V_10 -> V_47 [ V_3 ] ) ;
}
}
int F_23 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
V_6 -> V_7 . V_34 = V_58 ;
F_5 ( 1 ) ;
V_6 -> V_7 . V_34 = 0 ;
F_5 ( 25 ) ;
F_1 ( V_2 ) ;
if ( F_6 ( V_10 ) < 0 ) {
F_2 ( L_12 ) ;
return - V_26 ;
}
V_10 -> V_34 = V_59 | V_60 ;
if ( V_2 -> V_19 & V_61 )
V_10 -> V_34 |= V_62 ;
V_6 -> V_7 . V_34 = V_10 -> V_34 ;
F_9 ( V_2 ) ;
V_10 -> V_63 = ( 4 << V_64 ) |
( V_46 << V_65 ) ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
int V_66 ;
V_10 -> V_14 = - 1 ;
V_66 = F_23 ( V_2 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_11 ( V_10 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_13 ( V_10 ) ;
if ( V_66 < 0 )
goto V_67;
V_66 = F_25 ( V_2 -> V_68 , V_69 , 0 , V_70 , V_2 ) ;
if ( V_66 ) {
F_26 ( V_71 L_13 , V_2 -> V_72 , V_2 -> V_68 ) ;
goto V_73;
}
V_10 -> V_63 |= V_74 |
V_75 | V_76 ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
F_2 ( L_14 ) ;
F_27 ( V_2 ) ;
return 0 ;
V_73:
F_20 ( V_10 ) ;
V_67:
F_17 ( V_10 ) ;
return V_66 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
F_2 ( L_15 ) ;
F_29 ( V_2 ) ;
V_10 -> V_63 &= ~ ( V_74 | V_77 |
V_75 | V_76 ) ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
F_30 ( V_2 -> V_68 , V_2 ) ;
F_17 ( V_10 ) ;
F_20 ( V_10 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned long V_78 )
{
struct V_79 * V_80 ;
unsigned long V_81 , V_19 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_82 = ( V_78 & V_83 ) >> 8 ;
F_7 ( & V_10 -> V_20 , V_19 ) ;
V_10 -> V_63 &= ~ V_76 ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
F_8 ( & V_10 -> V_20 , V_19 ) ;
if ( V_78 & V_84 ) {
V_82 = ( V_82 - 1 ) & 0x0f ;
}
while ( V_10 -> V_56 != V_82 ) {
F_21 ( NULL , V_10 -> V_53 [ V_10 -> V_56 ] ,
V_48 , V_54 ) ;
V_81 = V_10 -> V_50 [ V_10 -> V_56 ] -> V_81 . V_85 ;
#if V_21
if ( ! ( V_81 & V_86 ) ) {
F_2 ( L_16 , V_81 ) ;
}
#endif
if ( ( ! ( V_81 & V_87 ) ) && ( V_81 & V_86 ) ) {
int V_88 = ( V_81 & 0xffff ) - 4 ;
if ( V_88 < 60 || V_88 > 1518 ) {
F_26 ( V_89 L_17 ,
V_2 -> V_72 , V_10 -> V_56 ,
V_10 -> V_50 [ V_10 -> V_56 ] -> V_81 . V_85 ) ;
V_2 -> V_90 . V_91 ++ ;
V_2 -> V_90 . V_92 ++ ;
V_80 = V_10 -> V_47 [ V_10 -> V_56 ] ;
} else {
V_80 = F_14 ( V_48 , V_38 ) ;
if ( ! V_80 ) {
F_2 ( L_18 ) ;
V_2 -> V_90 . V_93 ++ ;
V_80 = V_10 -> V_47 [ V_10 -> V_56 ] ;
} else {
struct V_79 * V_94 = V_10 -> V_47 [ V_10 -> V_56 ] ;
F_15 ( V_80 , V_49 ) ;
F_32 ( V_94 , V_88 ) ;
V_10 -> V_47 [ V_10 -> V_56 ] = V_80 ;
V_94 -> V_95 = F_33 ( V_94 , V_2 ) ;
V_2 -> V_90 . V_96 ++ ;
V_2 -> V_90 . V_97 += V_88 ;
F_34 ( V_94 ) ;
}
}
} else {
V_2 -> V_90 . V_91 ++ ;
V_80 = V_10 -> V_47 [ V_10 -> V_56 ] ;
#if V_21 > 0
F_26 ( V_98 L_19 , V_81 ) ;
if( V_81 & V_99 )
F_26 ( V_98 L_20 ) ;
if( V_81 & V_100 )
F_26 ( V_98 L_21 ) ;
if( V_81 & V_101 )
F_26 ( V_98 L_22 ) ;
if( V_81 & V_102 )
F_26 ( V_98 L_23 ) ;
if( V_81 & V_103 )
F_26 ( V_98 L_24 ) ;
if( V_81 & V_104 )
F_26 ( V_98 L_25 ) ;
#endif
}
V_10 -> V_50 [ V_10 -> V_56 ] = ( V_51 * ) V_80 -> V_52 ;
V_10 -> V_50 [ V_10 -> V_56 ] -> V_81 . V_85 = 0 ;
V_10 -> V_53 [ V_10 -> V_56 ] =
F_16 ( NULL , V_10 -> V_50 [ V_10 -> V_56 ] ,
V_48 , V_54 ) ;
V_6 -> V_7 . V_55 = V_10 -> V_53 [ V_10 -> V_56 ] ;
F_35 ( V_10 -> V_56 ) ;
}
F_7 ( & V_10 -> V_20 , V_19 ) ;
V_10 -> V_63 |= V_76 | V_75 ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
V_6 -> V_7 . V_105 = V_106 ;
F_8 ( & V_10 -> V_20 , V_19 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
return V_10 -> V_40 >= V_57 - 1 ;
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_78 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_81 , V_19 ;
struct V_79 * V_80 ;
unsigned long V_107 = ( V_78 & V_108 ) >> 16 ;
F_7 ( & V_10 -> V_20 , V_19 ) ;
V_10 -> V_63 &= ~ ( V_77 ) ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
while ( V_10 -> V_41 != V_107 ) {
V_80 = V_10 -> V_44 [ V_10 -> V_41 ] ;
V_81 = V_10 -> V_35 [ V_10 -> V_41 ] . V_109 . V_85 ;
#if V_21 >= 1
if ( V_10 -> V_41 == V_10 -> V_42 )
F_2 ( L_26 , V_10 -> V_41 , V_10 -> V_42 , V_107 ) ;
#endif
if ( V_81 & V_110 ) {
if ( V_81 & V_111 ) {
V_2 -> V_90 . V_112 ++ ;
V_2 -> V_90 . V_113 += V_80 -> V_88 ;
} else {
V_2 -> V_90 . V_114 ++ ;
#if V_21 >= 1
F_2 ( L_27 , V_81 ) ;
if( V_81 & V_111 )
F_26 ( L_28 ) ;
if( V_81 & V_115 )
F_26 ( L_29 ) ;
if( V_81 & V_116 )
F_26 ( L_30 ) ;
if( V_81 & V_117 )
F_26 ( L_31 ) ;
if( V_81 & V_118 )
F_26 ( L_32 ) ;
if( V_81 & V_119 )
F_26 ( L_33 ) ;
F_26 ( L_34 ) ;
#endif
}
} else {
F_2 ( L_35 ) ;
break;
}
F_38 ( V_80 ) ;
V_10 -> V_44 [ V_10 -> V_41 ] = NULL ;
V_10 -> V_35 [ V_10 -> V_41 ] . V_109 . V_85 = 0 ;
V_10 -> V_41 = ( V_10 -> V_41 + 1 ) & ( V_57 - 1 ) ;
V_10 -> V_40 -- ;
}
if ( F_39 ( V_2 ) && ! F_36 ( V_2 ) ) {
F_40 ( V_2 ) ;
}
V_6 -> V_7 . V_105 = V_120 | V_121 ;
F_8 ( & V_10 -> V_20 , V_19 ) ;
}
static void F_41 ( struct V_1 * V_2 , unsigned V_81 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_19 ;
F_26 ( V_98 L_36 , V_81 ) ;
if ( V_81 & ( V_122 ) )
F_26 ( V_98 L_37 ) ;
if ( V_81 & ( V_123 ) )
F_26 ( V_98 L_38 ) ;
if ( V_81 & ( V_124 ) )
F_26 ( V_98 L_39 ) ;
if ( V_81 & ( V_125 ) )
F_26 ( V_98 L_40 ) ;
if ( V_81 & ( V_84 ) ) {
F_26 ( V_98 L_41 ) ;
F_7 ( & V_10 -> V_20 , V_19 ) ;
V_6 -> V_7 . V_105 = V_84 ;
V_10 -> V_63 &= ~ V_75 ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
F_2 ( L_42 ) ;
F_8 ( & V_10 -> V_20 , V_19 ) ;
}
V_6 -> V_7 . V_105 = V_126 ;
}
static T_2 V_69 ( int V_68 , void * V_127 )
{
struct V_1 * V_2 = (struct V_1 * ) V_127 ;
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_81 ;
V_81 = V_6 -> V_7 . V_105 ;
while ( V_81 & 0xff ) {
if ( V_81 & V_126 ) {
F_41 ( V_2 , V_81 ) ;
}
if ( V_81 & ( V_120 | V_121 ) ) {
F_37 ( V_2 , V_81 ) ;
}
if ( V_81 & V_106 ) {
if ( ! ( V_10 -> V_63 & V_76 ) )
break;
F_31 ( V_2 , V_81 ) ;
}
V_81 = V_6 -> V_7 . V_105 ;
}
return V_128 ;
}
static void F_42 ( struct V_9 * V_10 ,
struct V_79 * V_80 )
{
T_3 * V_129 = & V_10 -> V_35 [ V_10 -> V_42 ] ;
int V_88 = ( V_80 -> V_88 < V_130 ) ? V_130 : V_80 -> V_88 ;
V_129 -> V_109 . V_85 = V_131 | ( V_88 - 1 ) | ( ( 128 - V_88 ) << 16 ) ;
F_43 ( V_80 , V_129 -> V_132 . V_133 + ( 120 - V_88 ) , V_80 -> V_88 ) ;
if ( V_80 -> V_88 < V_88 )
memset ( V_129 -> V_132 . V_133 + 120 - V_88 + V_80 -> V_88 , 0 , V_88 - V_80 -> V_88 ) ;
}
static void F_44 ( struct V_9 * V_10 ,
struct V_79 * V_80 )
{
T_3 * V_129 = & V_10 -> V_35 [ V_10 -> V_42 ] ;
void * V_134 = ( void * ) ( ( ( unsigned long ) V_80 -> V_132 + 7 ) & ~ 7 ) ;
int V_135 = ( int ) ( ( unsigned long ) V_134 - ( unsigned long ) V_80 -> V_132 ) ;
int V_136 = V_80 -> V_88 - V_135 ;
T_4 V_137 ;
V_129 -> V_109 . V_85 = V_131 | V_138 | ( V_80 -> V_88 - 1 ) ;
if ( V_135 ) {
F_43 ( V_80 , V_129 -> V_132 . V_133 + ( 120 - V_135 ) ,
V_135 ) ;
V_129 -> V_109 . V_85 |= ( 128 - V_135 ) << 16 ;
}
V_137 = F_16 ( NULL , V_134 , V_136 ,
V_139 ) ;
V_129 -> V_132 . V_140 [ 0 ] . V_141 . V_142 = V_137 >> 3 ;
V_129 -> V_132 . V_140 [ 0 ] . V_141 . V_88 = V_136 - 1 ;
}
static void F_45 ( struct V_9 * V_10 ,
struct V_79 * V_80 )
{
T_3 * V_129 = & V_10 -> V_35 [ V_10 -> V_42 ] ;
void * V_143 = ( void * ) ( ( ( unsigned long ) V_80 -> V_132 + 7 ) & ~ 7 ) ;
void * V_144 = ( void * ) F_46 ( ( unsigned long ) V_80 -> V_132 ) ;
int V_135 = ( int ) ( ( unsigned long ) V_143 - ( unsigned long ) V_80 -> V_132 ) ;
int V_145 = ( int ) ( ( unsigned long ) V_144 - ( unsigned long ) V_143 ) ;
int V_146 = V_80 -> V_88 - V_145 - V_135 ;
T_4 V_147 , V_148 ;
V_129 -> V_109 . V_85 = V_131 | V_138 | V_149 | ( V_80 -> V_88 - 1 ) ;
if ( V_135 ) {
F_43 ( V_80 , V_129 -> V_132 . V_133 + ( 120 - V_135 ) ,
V_135 ) ;
V_129 -> V_109 . V_85 |= ( 128 - V_135 ) << 16 ;
}
V_147 = F_16 ( NULL , V_143 , V_145 ,
V_139 ) ;
V_129 -> V_132 . V_140 [ 0 ] . V_141 . V_142 = V_147 >> 3 ;
V_129 -> V_132 . V_140 [ 0 ] . V_141 . V_88 = V_145 - 1 ;
V_148 = F_16 ( NULL , V_144 , V_146 ,
V_139 ) ;
V_129 -> V_132 . V_140 [ 1 ] . V_141 . V_142 = V_148 >> 3 ;
V_129 -> V_132 . V_140 [ 1 ] . V_141 . V_88 = V_146 - 1 ;
}
static void F_47 ( struct V_9 * V_10 , struct V_79 * V_80 )
{
V_10 -> V_44 [ V_10 -> V_42 ] = V_80 ;
if ( V_80 -> V_88 <= 120 ) {
F_42 ( V_10 , V_80 ) ;
} else if ( F_46 ( ( unsigned long ) V_80 -> V_132 ) !=
F_46 ( ( unsigned long ) V_80 -> V_132 + V_80 -> V_88 - 1 ) ) {
F_45 ( V_10 , V_80 ) ;
} else {
F_44 ( V_10 , V_80 ) ;
}
V_10 -> V_42 = ( V_10 -> V_42 + 1 ) & ( V_57 - 1 ) ;
V_6 -> V_7 . V_150 = V_10 -> V_42 ;
V_10 -> V_40 ++ ;
}
static int F_48 ( struct V_79 * V_80 , struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_19 ;
F_7 ( & V_10 -> V_20 , V_19 ) ;
V_10 -> V_63 &= ~ ( V_77 ) ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
F_47 ( V_10 , V_80 ) ;
V_2 -> V_151 = V_152 ;
if ( F_36 ( V_2 ) ) {
F_26 ( V_89 L_43 ) ;
F_29 ( V_2 ) ;
}
V_10 -> V_63 |= V_77 ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
F_8 ( & V_10 -> V_20 , V_19 ) ;
return V_153 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_19 ;
F_26 ( V_98 L_44 , V_2 -> V_72 ) ;
F_7 ( & V_10 -> V_20 , V_19 ) ;
F_23 ( V_2 ) ;
V_2 -> V_90 . V_114 ++ ;
F_17 ( V_10 ) ;
F_20 ( V_10 ) ;
F_11 ( V_10 ) ;
F_13 ( V_10 ) ;
V_10 -> V_63 |= V_74 | V_75 | V_76 ;
V_6 -> V_7 . V_63 = V_10 -> V_63 ;
F_8 ( & V_10 -> V_20 , V_19 ) ;
V_2 -> V_151 = V_152 ;
F_40 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_154 * V_155 , int V_156 )
{
switch( V_156 ) {
case V_157 :
case V_158 :
case V_159 :
default:
return - V_160 ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
unsigned long V_19 ;
F_29 ( V_2 ) ;
F_7 ( & V_10 -> V_20 , V_19 ) ;
V_10 -> V_34 &= ~ V_62 ;
if ( V_2 -> V_19 & V_61 ) {
V_10 -> V_34 |= V_62 ;
V_10 -> V_161 = 0xffffffffffffffffUL ;
} else if ( ( F_52 ( V_2 ) > V_162 ) ||
( V_2 -> V_19 & V_163 ) ) {
V_10 -> V_34 |= V_164 ;
V_10 -> V_161 = 0xffffffffffffffffUL ;
} else {
struct V_165 * V_166 ;
V_10 -> V_34 |= V_59 ;
F_53 (ha, dev)
F_54 ( ( F_55 ( V_167 , V_166 -> V_168 ) >> 26 ) ,
( volatile unsigned long * ) & V_10 -> V_161 ) ;
}
V_6 -> V_7 . V_34 = V_10 -> V_34 ;
V_6 -> V_7 . V_161 = V_10 -> V_161 ;
F_8 ( & V_10 -> V_20 , V_19 ) ;
F_40 ( V_2 ) ;
}
static int T_5 F_56 ( struct V_169 * V_170 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_171 ;
V_2 = F_57 ( sizeof( struct V_9 ) ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_172 = & V_173 ;
V_2 -> V_174 = V_175 ;
V_2 -> V_68 = V_176 ;
V_2 -> V_177 = ( unsigned long ) & V_6 -> V_7 ;
memcpy ( V_2 -> V_5 , V_178 , 6 ) ;
V_10 = F_10 ( V_2 ) ;
F_58 ( & V_10 -> V_20 ) ;
F_59 ( V_2 , & V_170 -> V_2 ) ;
V_171 = F_60 ( V_2 ) ;
if ( V_171 ) {
F_61 ( V_2 ) ;
return V_171 ;
}
F_26 ( V_179 L_45 ,
V_2 -> V_72 , ( unsigned int ) ( V_6 -> V_7 . V_34 >> 29 ) ) ;
return 0 ;
}
static int T_6 F_62 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = F_63 ( V_170 ) ;
F_64 ( V_2 ) ;
F_61 ( V_2 ) ;
F_65 ( V_170 , NULL ) ;
return 0 ;
}
