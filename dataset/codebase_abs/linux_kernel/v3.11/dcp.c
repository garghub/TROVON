static inline T_1 F_1 ( T_1 V_1 , int V_2 )
{
return V_1 + ( V_2 ) * 0x40 ;
}
static inline void F_2 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 )
{
F_3 ( V_5 , V_4 -> V_6 + V_1 ) ;
}
static inline void F_4 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 )
{
F_3 ( V_5 , V_4 -> V_6 + ( V_1 | 0x04 ) ) ;
}
static inline void F_5 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 )
{
F_3 ( V_5 , V_4 -> V_6 + ( V_1 | 0x08 ) ) ;
}
static inline void F_6 ( struct V_3 * V_4 , T_1 V_5 , T_1 V_1 )
{
F_3 ( V_5 , V_4 -> V_6 + ( V_1 | 0x0C ) ) ;
}
static inline unsigned int F_7 ( struct V_3 * V_4 , T_1 V_1 )
{
return F_8 ( V_4 -> V_6 + V_1 ) ;
}
static void F_9 ( struct V_3 * V_4 , struct V_7 * V_8 )
{
F_10 ( V_4 -> V_4 , V_8 -> V_9 , V_8 -> V_10 , V_11 ) ;
F_10 ( V_4 -> V_4 , V_8 -> V_12 , V_8 -> V_10 , V_13 ) ;
F_11 ( V_4 -> V_4 , L_1 , ( unsigned int ) V_8 ) ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_14 * V_15 , struct V_7 * V_8 )
{
F_11 ( V_4 -> V_4 , L_2 , ( unsigned int ) V_8 ) ;
V_8 -> V_10 = V_15 -> V_16 - ( V_15 -> V_16 % 16 ) ;
V_8 -> V_9 = F_13 ( V_4 -> V_4 , V_15 -> V_9 . V_17 , V_15 -> V_9 . V_18 ,
V_8 -> V_10 , V_11 ) ;
if ( V_8 -> V_9 == 0 ) {
F_14 ( V_4 -> V_4 , L_3 ) ;
return - V_19 ;
}
V_8 -> V_12 = F_13 ( V_4 -> V_4 , V_15 -> V_12 . V_17 , V_15 -> V_12 . V_18 ,
V_8 -> V_10 , V_13 ) ;
if ( V_8 -> V_12 == 0 ) {
F_14 ( V_4 -> V_4 , L_4 ) ;
F_10 ( V_4 -> V_4 , V_8 -> V_9 , V_8 -> V_10 , V_11 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_15 ( struct V_3 * V_4 , struct V_7 * V_8 ,
T_2 V_20 )
{
struct V_21 * V_22 = V_4 -> V_22 ;
V_8 -> V_23 = V_22 -> V_23 ;
V_8 -> V_24 = V_22 -> V_24 ;
V_8 -> V_25 = ( T_1 ) V_4 -> V_26 ;
V_8 -> V_27 = 0 ;
if ( V_22 -> V_28 & V_29 ) {
V_8 -> V_23 |= V_30 ;
V_22 -> V_28 &= ~ V_29 ;
}
F_16 ( & V_4 -> V_31 , V_32 + F_17 ( 500 ) ) ;
V_8 -> V_23 |= V_33 ;
if ( ! V_20 )
V_8 -> V_23 |= V_34 ;
V_4 -> V_35 ++ ;
F_2 ( V_4 , 1 ,
F_1 ( V_36 , V_37 ) ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_21 * V_22 = V_4 -> V_22 ;
struct V_7 * V_8 ;
while ( V_22 -> V_15 . V_16 ) {
int V_38 = 0 ;
V_8 = V_4 -> V_39 [ V_4 -> V_35 % V_40 ] ;
V_38 = F_12 ( V_4 , & V_22 -> V_15 , V_8 ) ;
if ( V_38 ) {
V_4 -> V_22 -> V_27 |= V_38 ;
F_16 ( & V_4 -> V_31 ,
V_32 + F_17 ( 500 ) ) ;
break;
}
V_38 = V_22 -> V_15 . V_16 - V_8 -> V_10 ;
F_19 ( V_4 -> V_22 -> V_41 , & V_4 -> V_22 -> V_15 , V_38 ) ;
F_15 ( V_4 , V_8 , V_22 -> V_15 . V_16 == 0 ) ;
if ( V_4 -> V_35 - V_4 -> V_42 == V_40 )
break;
}
F_20 ( V_43 , & V_4 -> V_28 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_2 V_44 )
{
struct V_21 * V_22 = V_4 -> V_22 ;
if ( V_22 -> V_28 & V_45 ) {
memcpy ( V_4 -> V_46 , V_22 -> V_47 , V_22 -> V_48 ) ;
V_22 -> V_28 &= ~ V_45 ;
}
V_22 -> V_23 = 0 ;
V_22 -> V_23 |= V_49 ;
V_22 -> V_23 |= V_50 ;
if ( V_22 -> V_28 & V_51 )
V_22 -> V_23 |= V_52 ;
else
V_22 -> V_23 |= V_53 ;
if ( V_22 -> V_28 & V_54 )
V_22 -> V_23 |= V_55 ;
V_22 -> V_24 = 0 ;
if ( V_22 -> V_28 & V_56 )
V_22 -> V_24 |= V_57 ;
V_4 -> V_35 = 0 ;
V_4 -> V_42 = 0 ;
V_22 -> V_27 = 0 ;
F_5 ( V_4 , - 1 , F_1 ( V_58 , V_37 ) ) ;
F_2 ( V_4 , ( T_1 ) V_4 -> V_59 ,
F_1 ( V_60 , V_37 ) ) ;
F_22 ( V_43 , & V_4 -> V_28 ) ;
if ( V_44 ) {
F_23 ( & V_22 -> V_15 , V_22 -> V_41 -> V_12 ,
V_22 -> V_41 -> V_9 , V_22 -> V_41 -> V_16 ) ;
F_24 ( V_22 -> V_41 , & V_22 -> V_15 ) ;
F_18 ( V_4 ) ;
} else {
F_15 ( V_4 , V_4 -> V_39 [ 0 ] , 1 ) ;
F_20 ( V_43 , & V_4 -> V_28 ) ;
}
}
static void F_25 ( unsigned long V_5 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 ;
struct V_7 * V_61 ;
int V_62 ;
V_62 = 0 ;
for ( V_61 = V_4 -> V_39 [ ( V_4 -> V_42 ) % V_40 ] ;
V_61 -> V_27 == 1 ;
V_61 =
V_4 -> V_39 [ ++ ( V_4 -> V_42 ) % V_40 ] ) {
F_9 ( V_4 , V_61 ) ;
V_61 -> V_27 = 0 ;
V_62 ++ ;
}
if ( V_62 == 0 )
return;
F_11 ( V_4 -> V_4 ,
L_5 ,
V_4 -> V_22 -> V_27 , V_62 , V_4 -> V_35 , V_4 -> V_42 ) ;
V_61 = V_4 -> V_39 [ ( V_4 -> V_42 - 1 ) % V_40 ] ;
if ( ! V_4 -> V_22 -> V_27 && V_61 -> V_23 & V_34 ) {
if ( ! F_26 ( V_43 , & V_4 -> V_28 ) )
F_18 ( V_4 ) ;
return;
}
while ( F_27 ( V_4 -> V_42 < V_4 -> V_35 ) ) {
F_9 ( V_4 ,
V_4 -> V_39 [ V_4 -> V_42 ++ % V_40 ] ) ;
}
if ( V_4 -> V_22 -> V_28 & V_51 ) {
F_20 ( V_63 , & V_4 -> V_28 ) ;
return;
}
F_28 ( & V_4 -> V_22 -> V_15 ) ;
V_4 -> V_22 -> V_41 -> V_64 . V_65 ( & V_4 -> V_22 -> V_41 -> V_64 ,
V_4 -> V_22 -> V_27 ) ;
V_4 -> V_22 -> V_41 = NULL ;
F_29 ( & V_4 -> V_66 ) ;
}
static void F_30 ( unsigned long V_5 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 ;
V_4 -> V_22 -> V_27 |= F_7 ( V_4 ,
F_1 ( V_58 , V_37 ) ) ;
F_14 ( V_4 -> V_4 , L_6 , V_4 -> V_22 -> V_27 ) ;
if ( ! V_4 -> V_22 -> V_27 )
V_4 -> V_22 -> V_27 = - V_67 ;
F_25 ( V_5 ) ;
}
static T_3 F_31 ( int V_68 , void * V_69 )
{
T_1 V_70 ;
struct V_3 * V_4 = (struct V_3 * ) V_69 ;
F_32 ( & V_4 -> V_31 ) ;
V_70 = F_33 ( F_7 ( V_4 , V_71 ) ) ;
F_5 ( V_4 , V_70 , V_71 ) ;
if ( V_70 == 0 )
return V_72 ;
V_4 -> V_22 -> V_27 |= F_7 ( V_4 ,
F_1 ( V_58 , V_37 ) ) ;
if ( V_70 & V_73 )
F_29 ( & V_4 -> V_74 ) ;
return V_75 ;
}
static T_3 F_34 ( int V_68 , void * V_69 )
{
return F_31 ( V_68 , V_69 ) ;
}
static T_3 F_35 ( int V_68 , void * V_69 )
{
return F_31 ( V_68 , V_69 ) ;
}
static void F_36 ( struct V_3 * V_4 , struct V_21 * V_22 )
{
V_4 -> V_22 = V_22 ;
if ( ( V_22 -> V_28 & V_56 ) && V_22 -> V_41 -> V_76 ) {
V_22 -> V_28 |= V_29 ;
memcpy ( V_4 -> V_46 + V_77 ,
V_22 -> V_41 -> V_76 , V_77 ) ;
}
F_21 ( V_4 , 1 ) ;
}
static void F_37 ( unsigned long V_5 )
{
struct V_3 * V_4 = (struct V_3 * ) V_5 ;
struct V_78 * V_79 , * V_80 ;
struct V_81 * V_82 ;
struct V_21 * V_22 ;
struct V_83 * V_84 ;
struct V_85 * V_41 ;
unsigned long V_28 ;
F_38 ( & V_4 -> V_86 , V_28 ) ;
V_80 = F_39 ( & V_4 -> V_87 ) ;
V_79 = F_40 ( & V_4 -> V_87 ) ;
F_41 ( & V_4 -> V_86 , V_28 ) ;
if ( ! V_79 )
goto V_88;
if ( V_80 )
V_80 -> V_65 ( V_80 , - V_89 ) ;
V_41 = F_42 ( V_79 ) ;
V_82 = F_43 ( V_41 ) ;
V_84 = F_44 ( V_41 ) ;
V_22 = F_45 ( V_82 ) ;
if ( ! V_41 -> V_9 || ! V_41 -> V_12 )
goto V_88;
V_22 -> V_28 |= V_84 -> V_90 ;
V_22 -> V_41 = V_41 ;
F_36 ( V_4 , V_22 ) ;
return;
V_88:
F_20 ( V_63 , & V_4 -> V_28 ) ;
}
static int F_46 ( struct V_91 * V_82 )
{
const char * V_92 = V_82 -> V_93 -> V_94 ;
struct V_21 * V_22 = F_47 ( V_82 ) ;
V_82 -> V_95 . V_96 = sizeof( struct V_83 ) ;
V_22 -> V_97 = F_48 ( V_92 , 0 ,
V_98 | V_99 ) ;
if ( F_49 ( V_22 -> V_97 ) ) {
F_14 ( V_100 -> V_4 , L_7 ,
V_92 ) ;
return F_50 ( V_22 -> V_97 ) ;
}
return 0 ;
}
static void F_51 ( struct V_91 * V_82 )
{
struct V_21 * V_22 = F_47 ( V_82 ) ;
if ( V_22 -> V_97 )
F_52 ( V_22 -> V_97 ) ;
V_22 -> V_97 = NULL ;
}
static int F_53 ( struct V_81 * V_82 , const T_4 * V_47 ,
unsigned int V_101 )
{
struct V_21 * V_22 = F_45 ( V_82 ) ;
unsigned int V_102 = 0 ;
V_22 -> V_48 = V_101 ;
V_22 -> V_28 = 0 ;
if ( V_101 == V_77 ) {
if ( memcmp ( V_22 -> V_47 , V_47 , V_77 ) ) {
memcpy ( V_22 -> V_47 , V_47 , V_101 ) ;
V_22 -> V_28 |= V_45 ;
}
return 0 ;
}
V_22 -> V_97 -> V_64 . V_103 &= ~ V_104 ;
V_22 -> V_97 -> V_64 . V_103 |=
( V_82 -> V_64 . V_103 & V_104 ) ;
V_102 = F_54 ( V_22 -> V_97 , V_47 , V_101 ) ;
if ( V_102 ) {
struct V_91 * V_105 = F_55 ( V_82 ) ;
V_105 -> V_103 &= ~ V_106 ;
V_105 -> V_103 |=
( V_22 -> V_97 -> V_64 . V_103 & V_106 ) ;
}
return V_102 ;
}
static int F_56 ( struct V_85 * V_41 , int V_90 )
{
struct V_83 * V_84 = F_44 ( V_41 ) ;
struct V_3 * V_4 = V_100 ;
unsigned long V_28 ;
int V_38 = 0 ;
if ( ! F_57 ( V_41 -> V_16 , V_107 ) )
return - V_108 ;
V_84 -> V_90 = V_90 ;
F_38 ( & V_4 -> V_86 , V_28 ) ;
V_38 = F_58 ( & V_4 -> V_87 , V_41 ) ;
F_41 ( & V_4 -> V_86 , V_28 ) ;
V_28 = F_26 ( V_63 , & V_4 -> V_28 ) ;
if ( ! ( V_28 & V_63 ) )
F_29 ( & V_4 -> V_66 ) ;
return V_38 ;
}
static int F_59 ( struct V_85 * V_41 )
{
struct V_91 * V_82 =
F_55 ( F_43 ( V_41 ) ) ;
struct V_21 * V_22 = F_45 (
F_43 ( V_41 ) ) ;
if ( F_27 ( V_22 -> V_48 != V_77 ) ) {
int V_38 = 0 ;
F_60 ( V_41 , V_22 -> V_97 ) ;
V_38 = F_61 ( V_41 ) ;
F_60 ( V_41 , F_62 ( V_82 ) ) ;
return V_38 ;
}
return F_56 ( V_41 , V_109 | V_54 | V_56 ) ;
}
static int F_63 ( struct V_85 * V_41 )
{
struct V_91 * V_82 =
F_55 ( F_43 ( V_41 ) ) ;
struct V_21 * V_22 = F_45 (
F_43 ( V_41 ) ) ;
if ( F_27 ( V_22 -> V_48 != V_77 ) ) {
int V_38 = 0 ;
F_60 ( V_41 , V_22 -> V_97 ) ;
V_38 = F_64 ( V_41 ) ;
F_60 ( V_41 , F_62 ( V_82 ) ) ;
return V_38 ;
}
return F_56 ( V_41 , V_109 | V_110 | V_56 ) ;
}
static int F_65 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
V_112 -> V_113 = F_66 ( ( V_112 -> V_113 ) ,
struct V_3 , V_114 ) ;
return 0 ;
}
static long F_67 ( struct V_112 * V_112 ,
unsigned int V_115 , unsigned long V_116 )
{
struct V_3 * V_4 = (struct V_3 * ) V_112 -> V_113 ;
void T_5 * V_117 = ( void T_5 * ) V_116 ;
int V_102 ;
if ( V_4 == NULL )
return - V_118 ;
if ( V_115 != V_119 && V_115 != V_120 )
return - V_108 ;
if ( F_68 ( V_4 -> V_46 , V_117 , 16 ) )
return - V_121 ;
if ( F_26 ( V_63 , & V_4 -> V_28 ) )
return - V_122 ;
V_4 -> V_22 = F_69 ( sizeof( struct V_21 ) , V_123 ) ;
if ( ! V_4 -> V_22 ) {
F_14 ( V_4 -> V_4 ,
L_8 ) ;
F_20 ( V_63 , & V_4 -> V_28 ) ;
return - V_19 ;
}
V_4 -> V_22 -> V_28 = V_109 | V_124 | V_51 | V_29 ;
V_4 -> V_22 -> V_28 |= ( V_115 == V_119 ) ? V_54 : V_110 ;
V_4 -> V_39 [ 0 ] -> V_9 = V_4 -> V_26 ;
V_4 -> V_39 [ 0 ] -> V_12 = V_4 -> V_26 ;
V_4 -> V_39 [ 0 ] -> V_10 = 16 ;
F_21 ( V_4 , 0 ) ;
while ( F_70 ( V_63 , & V_4 -> V_28 ) )
F_71 () ;
V_102 = V_4 -> V_22 -> V_27 ;
if ( ! V_102 && F_72 ( V_117 , V_4 -> V_46 , 16 ) )
V_102 = - V_121 ;
F_73 ( V_4 -> V_22 ) ;
return V_102 ;
}
static int F_74 ( struct V_125 * V_126 )
{
struct V_3 * V_4 = NULL ;
struct V_127 * V_128 ;
int V_129 , V_102 , V_130 ;
V_4 = F_75 ( & V_126 -> V_4 , sizeof( * V_4 ) , V_123 ) ;
if ( ! V_4 )
return - V_19 ;
V_100 = V_4 ;
V_4 -> V_4 = & V_126 -> V_4 ;
F_76 ( V_126 , V_4 ) ;
V_128 = F_77 ( V_126 , V_131 , 0 ) ;
if ( ! V_128 ) {
F_14 ( & V_126 -> V_4 , L_9 ) ;
return - V_132 ;
}
V_4 -> V_6 = F_78 ( & V_126 -> V_4 , V_128 -> V_133 ,
F_79 ( V_128 ) ) ;
F_4 ( V_4 , V_134 , V_135 ) ;
F_80 ( 10 ) ;
F_5 ( V_4 , V_134 | V_136 , V_135 ) ;
F_2 ( V_4 , V_137 |
V_138 | V_139 ,
V_135 ) ;
F_2 ( V_4 , V_140 , V_141 ) ;
for ( V_129 = 0 ; V_129 < 4 ; V_129 ++ )
F_5 ( V_4 , - 1 , F_1 ( V_58 , V_129 ) ) ;
F_5 ( V_4 , - 1 , V_71 ) ;
V_128 = F_77 ( V_126 , V_142 , 0 ) ;
if ( ! V_128 ) {
F_14 ( & V_126 -> V_4 , L_10 ) ;
return - V_143 ;
}
V_4 -> F_34 = V_128 -> V_133 ;
V_102 = F_81 ( V_4 -> F_34 , F_34 , 0 , L_11 , V_4 ) ;
if ( V_102 != 0 ) {
F_14 ( & V_126 -> V_4 , L_12 ) ;
return - V_143 ;
}
V_128 = F_77 ( V_126 , V_142 , 1 ) ;
if ( ! V_128 ) {
F_14 ( & V_126 -> V_4 , L_13 ) ;
V_102 = - V_143 ;
goto V_144;
}
V_4 -> F_35 = V_128 -> V_133 ;
V_102 = F_81 ( V_4 -> F_35 , F_35 , 0 , L_11 , V_4 ) ;
if ( V_102 != 0 ) {
F_14 ( & V_126 -> V_4 , L_14 ) ;
V_102 = - V_143 ;
goto V_144;
}
V_4 -> V_39 [ 0 ] = F_82 ( & V_126 -> V_4 ,
V_40 * sizeof( struct V_7 ) ,
& V_4 -> V_59 ,
V_123 ) ;
if ( ! V_4 -> V_39 [ 0 ] ) {
F_14 ( & V_126 -> V_4 , L_15 ) ;
V_102 = - V_19 ;
goto V_145;
}
for ( V_129 = 1 ; V_129 < V_40 ; V_129 ++ ) {
V_4 -> V_39 [ V_129 - 1 ] -> V_146 = V_4 -> V_59
+ V_129 * sizeof( struct V_7 ) ;
V_4 -> V_39 [ V_129 ] = V_4 -> V_39 [ V_129 - 1 ] + 1 ;
}
V_4 -> V_39 [ V_129 - 1 ] -> V_146 = V_4 -> V_59 ;
V_4 -> V_46 = F_82 ( & V_126 -> V_4 , 2 * V_77 ,
& V_4 -> V_26 , V_123 ) ;
if ( ! V_4 -> V_46 ) {
F_14 ( & V_126 -> V_4 , L_16 ) ;
V_102 = - V_19 ;
goto V_147;
}
F_83 ( & V_4 -> V_66 , F_37 ,
( unsigned long ) V_4 ) ;
F_83 ( & V_4 -> V_74 , F_25 ,
( unsigned long ) V_4 ) ;
F_84 ( & V_4 -> V_86 ) ;
F_85 ( & V_4 -> V_87 , 10 ) ;
F_86 ( & V_4 -> V_31 ) ;
V_4 -> V_31 . V_148 = & F_30 ;
V_4 -> V_31 . V_5 = ( unsigned long ) V_4 ;
V_4 -> V_114 . V_149 = V_150 ,
V_4 -> V_114 . V_92 = L_17 ,
V_4 -> V_114 . V_151 = & V_152 ,
V_102 = F_87 ( & V_4 -> V_114 ) ;
if ( V_102 != 0 ) {
F_14 ( V_4 -> V_4 , L_18 ) ;
goto V_153;
}
for ( V_129 = 0 ; V_129 < F_88 ( V_154 ) ; V_129 ++ ) {
V_154 [ V_129 ] . V_155 = 300 ;
V_154 [ V_129 ] . V_156 = sizeof( struct V_21 ) ;
V_154 [ V_129 ] . V_157 = V_158 ;
V_154 [ V_129 ] . V_159 = F_46 ;
V_154 [ V_129 ] . V_160 = F_51 ;
if ( F_89 ( & V_154 [ V_129 ] ) ) {
F_14 ( & V_126 -> V_4 , L_19 ) ;
V_102 = - V_19 ;
goto V_161;
}
}
F_90 ( & V_126 -> V_4 , L_20 ) ;
return 0 ;
V_161:
for ( V_130 = 0 ; V_130 < V_129 ; V_130 ++ )
F_91 ( & V_154 [ V_130 ] ) ;
V_153:
F_92 ( & V_126 -> V_4 , 2 * V_77 , V_4 -> V_46 ,
V_4 -> V_26 ) ;
V_147:
F_92 ( & V_126 -> V_4 , V_40 *
sizeof( struct V_7 ) , V_4 -> V_39 [ 0 ] ,
V_4 -> V_59 ) ;
V_145:
F_93 ( V_4 -> F_35 , V_4 ) ;
V_144:
F_93 ( V_4 -> F_34 , V_4 ) ;
return V_102 ;
}
static int F_94 ( struct V_125 * V_126 )
{
struct V_3 * V_4 ;
int V_130 ;
V_4 = F_95 ( V_126 ) ;
F_92 ( & V_126 -> V_4 ,
V_40 * sizeof( struct V_7 ) ,
V_4 -> V_39 [ 0 ] , V_4 -> V_59 ) ;
F_92 ( & V_126 -> V_4 , 2 * V_77 , V_4 -> V_46 ,
V_4 -> V_26 ) ;
F_93 ( V_4 -> F_35 , V_4 ) ;
F_93 ( V_4 -> F_34 , V_4 ) ;
F_96 ( & V_4 -> V_74 ) ;
F_96 ( & V_4 -> V_66 ) ;
for ( V_130 = 0 ; V_130 < F_88 ( V_154 ) ; V_130 ++ )
F_91 ( & V_154 [ V_130 ] ) ;
F_97 ( & V_4 -> V_114 ) ;
return 0 ;
}
