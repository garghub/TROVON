static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
return ! V_2 -> V_4 && V_2 -> V_5 &&
V_2 -> V_6 -> V_7 -> V_8 < V_9 ;
}
static void F_2 ( struct V_10 * V_11 )
{
T_1 T_2 * V_12 ;
T_1 V_13 ;
int V_14 ;
T_3 V_15 ;
struct V_16 * V_17 = F_3 ( V_11 ) ;
if ( ! V_11 -> V_18 )
return;
if ( ! F_4 ( NULL , F_1 ) )
return;
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
if ( F_6 ( V_14 , & V_11 -> V_18 ) ) {
V_12 = & V_11 -> V_20 -> V_21 [ V_14 ] ;
V_13 = F_7 ( V_11 , V_12 ) & ~ V_22 ;
if ( ! ( V_13 & V_23 ) )
F_8 ( V_11 , V_14 , true ) ;
}
}
F_9 ( 20 ) ;
F_10 ( & V_11 -> V_24 ) ;
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
if ( F_6 ( V_14 , & V_11 -> V_18 ) ) {
V_12 = & V_11 -> V_20 -> V_21 [ V_14 ] ;
V_13 = F_7 ( V_11 , V_12 ) & ~ V_22 ;
if ( V_13 & V_25 )
F_11 ( V_14 , & V_11 -> V_18 ) ;
else if ( F_6 ( V_14 , & V_11 -> V_26 ) )
F_12 ( V_11 , V_13 & ~ V_27 , V_12 ) ;
else {
F_13 ( & V_11 -> V_24 ) ;
F_14 ( V_17 , V_28 ,
V_29 , V_14 + 1 ,
NULL , 0 ) ;
F_10 ( & V_11 -> V_24 ) ;
}
}
}
F_13 ( & V_11 -> V_24 ) ;
if ( ! V_11 -> V_18 )
return;
F_9 ( 90 ) ;
F_10 ( & V_11 -> V_24 ) ;
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
if ( F_6 ( V_14 , & V_11 -> V_18 ) ) {
F_13 ( & V_11 -> V_24 ) ;
F_14 ( V_17 , V_30 ,
0 , V_14 + 1 ,
( char * ) & V_15 , sizeof( V_15 ) ) ;
F_10 ( & V_11 -> V_24 ) ;
V_12 = & V_11 -> V_20 -> V_21 [ V_14 ] ;
V_13 = F_7 ( V_11 , V_12 ) & ~ V_22 ;
if ( V_13 & V_25 )
F_12 ( V_11 , V_13 | V_31 , V_12 ) ;
else {
F_15 ( V_11 , L_1 ,
V_14 + 1 , V_13 ) ;
F_12 ( V_11 , V_13 & ~ V_27 , V_12 ) ;
}
}
}
V_11 -> V_18 = 0 ;
F_13 ( & V_11 -> V_24 ) ;
}
static int F_16 ( struct V_10 * V_11 )
{
int V_32 = F_5 ( V_11 -> V_19 ) ;
if ( F_7 ( V_11 , & V_11 -> V_20 -> V_13 ) & V_33 )
return 1 ;
while ( V_32 -- )
if ( F_7 ( V_11 , & V_11 -> V_20 -> V_21 [ V_32 ] ) & V_31 )
return 1 ;
return 0 ;
}
void F_17 ( struct V_10 * V_11 ,
bool V_34 , bool V_35 )
{
int V_14 ;
T_1 V_36 ;
if ( ! F_3 ( V_11 ) -> V_37 . V_7 -> V_38 || V_35 )
return;
F_10 ( & V_11 -> V_24 ) ;
if ( V_11 -> V_39 ) {
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
T_1 T_2 * V_40 = & V_11 -> V_20 -> V_41 [ V_14 ] ;
V_36 = F_7 ( V_11 , V_40 ) ;
F_12 ( V_11 , V_36 & ~ V_42 , V_40 ) ;
}
F_13 ( & V_11 -> V_24 ) ;
F_9 ( 5 ) ;
F_10 ( & V_11 -> V_24 ) ;
}
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
T_1 T_2 * V_12 = & V_11 -> V_20 -> V_21 [ V_14 ] ;
T_1 V_43 = F_7 ( V_11 , V_12 ) & ~ V_22 ;
T_1 V_44 = V_43 & ~ V_45 ;
if ( ! V_34 ) {
if ( V_43 & V_46 )
V_44 |= V_47 | V_48 ;
else
V_44 |= V_47 | V_49 ;
}
F_12 ( V_11 , V_44 , V_12 ) ;
}
if ( V_11 -> V_39 ) {
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
T_1 T_2 * V_40 = & V_11 -> V_20 -> V_41 [ V_14 ] ;
V_36 = F_7 ( V_11 , V_40 ) ;
F_12 ( V_11 , V_36 | V_42 , V_40 ) ;
}
}
if ( ! V_34 && F_16 ( V_11 ) )
F_18 ( F_3 ( V_11 ) ) ;
F_13 ( & V_11 -> V_24 ) ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_10 * V_11 = F_20 ( V_17 ) ;
int V_14 ;
int V_50 ;
int V_51 ;
bool V_52 ;
F_15 ( V_11 , L_2 ) ;
if ( F_21 ( V_53 , V_11 -> V_54 ) )
F_9 ( 5 ) ;
F_22 ( V_11 ) ;
F_10 ( & V_11 -> V_24 ) ;
if ( V_11 -> V_55 < V_56 )
goto V_57;
if ( V_17 -> V_37 . V_7 -> V_38 ) {
if ( V_11 -> V_58 ) {
F_13 ( & V_11 -> V_24 ) ;
F_15 ( V_11 , L_3 ) ;
return - V_59 ;
}
}
V_11 -> V_60 = 0 ;
V_11 -> V_18 = 0 ;
V_51 = 0 ;
V_52 = false ;
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
T_1 T_2 * V_12 = & V_11 -> V_20 -> V_21 [ V_14 ] ;
T_1 V_43 = F_7 ( V_11 , V_12 ) & ~ V_22 ;
T_1 V_44 = V_43 & ~ V_45 ;
if ( V_43 & V_25 )
F_23 ( V_14 , & V_11 -> V_18 ) ;
else if ( ( V_43 & V_27 ) && ! ( V_43 & V_61 ) ) {
V_44 |= V_61 ;
F_23 ( V_14 , & V_11 -> V_60 ) ;
}
if ( V_17 -> V_37 . V_7 -> V_38 ) {
if ( V_43 & V_46 )
V_44 |= V_47 | V_48 ;
else
V_44 |= V_47 | V_49 ;
}
if ( V_43 != V_44 ) {
if ( ( V_44 & V_48 ) &&
F_24 ( V_11 , V_44 ) ==
V_62 )
V_52 = true ;
F_12 ( V_11 , V_44 , V_12 ) ;
V_51 = 1 ;
}
}
F_13 ( & V_11 -> V_24 ) ;
if ( V_51 && F_25 ( V_11 ) )
F_26 ( 10000 , 20000 ) ;
if ( ( V_51 && V_11 -> V_39 ) || V_52 ) {
F_26 ( 5000 , 5500 ) ;
}
if ( V_51 && V_11 -> V_39 ) {
F_10 ( & V_11 -> V_24 ) ;
V_14 = F_5 ( V_11 -> V_19 ) ;
while ( V_14 -- ) {
T_1 T_2 * V_40 = & V_11 -> V_20 -> V_41 [ V_14 ] ;
T_1 V_63 ;
V_63 = F_7 ( V_11 , V_40 ) ;
F_12 ( V_11 , V_63 | V_42 , V_40 ) ;
V_63 = F_7 ( V_11 , V_40 ) ;
F_15 ( V_11 , L_4 ,
V_14 , ( V_63 & V_42 ) ?
L_5 : L_6 ) ;
}
F_13 ( & V_11 -> V_24 ) ;
}
if ( V_11 -> V_60 )
F_27 ( 150 ) ;
F_28 ( V_11 ) ;
F_10 ( & V_11 -> V_24 ) ;
if ( V_11 -> V_64 & F_29 ( V_65 ) )
F_30 ( V_11 ) ;
if ( V_11 -> V_55 != V_56 )
goto V_57;
V_11 -> V_55 = V_66 ;
F_31 ( V_11 ) ;
F_32 ( V_11 ) ;
F_33 ( V_11 ) ;
F_34 ( V_11 ) ;
F_35 ( V_11 ) ;
V_50 = V_67 ;
if ( ! V_17 -> V_37 . V_7 -> V_38 )
V_50 &= ~ V_33 ;
F_12 ( V_11 , V_50 , & V_11 -> V_20 -> V_68 ) ;
F_7 ( V_11 , & V_11 -> V_20 -> V_68 ) ;
V_57:
V_11 -> V_54 = V_53 + F_36 ( 10 ) ;
V_11 -> V_64 = 0 ;
V_11 -> V_69 = V_70 ;
F_13 ( & V_11 -> V_24 ) ;
F_37 ( & V_11 -> V_71 ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 )
{
struct V_10 * V_11 = F_20 ( V_17 ) ;
T_1 V_36 ;
T_1 V_72 ;
int V_32 ;
unsigned long V_73 = 0 ;
if ( F_21 ( V_53 , V_11 -> V_54 ) )
F_9 ( 5 ) ;
F_10 ( & V_11 -> V_24 ) ;
if ( ! F_39 ( V_17 ) || V_11 -> V_74 )
goto V_74;
if ( F_40 ( V_11 -> V_75 ) ) {
if ( ! F_41 ( V_17 ) )
V_11 -> V_75 = NULL ;
else
F_42 ( V_17 ) ;
}
V_72 = F_7 ( V_11 , & V_11 -> V_20 -> V_68 ) ;
F_15 ( V_11 , L_7 ,
V_72 ? L_8 : L_9 ) ;
F_12 ( V_11 , 0 , & V_11 -> V_20 -> V_68 ) ;
F_12 ( V_11 , 0 , & V_11 -> V_20 -> V_76 ) ;
F_12 ( V_11 , V_11 -> V_77 , & V_11 -> V_20 -> V_78 ) ;
F_12 ( V_11 , ( T_1 ) V_11 -> V_79 -> V_80 , & V_11 -> V_20 -> V_81 ) ;
V_11 -> V_82 |= V_83 ;
F_12 ( V_11 , V_11 -> V_82 , & V_11 -> V_20 -> V_82 ) ;
V_11 -> V_55 = V_56 ;
V_32 = F_5 ( V_11 -> V_19 ) ;
while ( V_32 -- ) {
V_36 = F_7 ( V_11 , & V_11 -> V_20 -> V_21 [ V_32 ] ) ;
if ( ( V_36 & V_27 ) &&
! ( V_36 & ( V_61 | V_84 ) ) ) {
F_15 ( V_11 , L_10 , V_36 ) ;
F_13 ( & V_11 -> V_24 ) ;
F_9 ( 8 ) ;
F_10 ( & V_11 -> V_24 ) ;
break;
}
}
if ( V_11 -> V_74 )
goto V_74;
if ( V_11 -> V_60 && V_11 -> V_39 ) {
V_32 = F_5 ( V_11 -> V_19 ) ;
while ( V_32 -- ) {
if ( F_6 ( V_32 , & V_11 -> V_60 ) ) {
T_1 T_2 * V_40 =
& V_11 -> V_20 -> V_41 [ V_32 ] ;
V_36 = F_7 ( V_11 , V_40 ) ;
F_12 ( V_11 , V_36 & ~ V_42 ,
V_40 ) ;
}
}
F_13 ( & V_11 -> V_24 ) ;
F_9 ( 5 ) ;
F_10 ( & V_11 -> V_24 ) ;
if ( V_11 -> V_74 )
goto V_74;
}
V_32 = F_5 ( V_11 -> V_19 ) ;
while ( V_32 -- ) {
V_36 = F_7 ( V_11 , & V_11 -> V_20 -> V_21 [ V_32 ] ) ;
V_36 &= ~ ( V_22 | V_45 ) ;
if ( F_6 ( V_32 , & V_11 -> V_60 ) &&
( V_36 & V_61 ) ) {
V_36 |= V_84 ;
F_23 ( V_32 , & V_73 ) ;
}
F_12 ( V_11 , V_36 , & V_11 -> V_20 -> V_21 [ V_32 ] ) ;
}
if ( V_73 ) {
F_13 ( & V_11 -> V_24 ) ;
F_9 ( V_85 ) ;
F_10 ( & V_11 -> V_24 ) ;
if ( V_11 -> V_74 )
goto V_74;
}
V_32 = F_5 ( V_11 -> V_19 ) ;
while ( V_32 -- ) {
V_36 = F_7 ( V_11 , & V_11 -> V_20 -> V_21 [ V_32 ] ) ;
if ( F_6 ( V_32 , & V_73 ) ) {
V_36 &= ~ ( V_22 | V_61 | V_84 ) ;
F_12 ( V_11 , V_36 , & V_11 -> V_20 -> V_21 [ V_32 ] ) ;
}
}
V_11 -> V_54 = V_53 + F_36 ( 5 ) ;
F_13 ( & V_11 -> V_24 ) ;
F_2 ( V_11 ) ;
F_10 ( & V_11 -> V_24 ) ;
if ( V_11 -> V_74 )
goto V_74;
F_12 ( V_11 , V_67 , & V_11 -> V_20 -> V_68 ) ;
( void ) F_7 ( V_11 , & V_11 -> V_20 -> V_68 ) ;
F_13 ( & V_11 -> V_24 ) ;
return 0 ;
V_74:
F_13 ( & V_11 -> V_24 ) ;
return - V_86 ;
}
static void F_43 ( struct V_10 * V_11 , int V_87 , int V_88 )
{
T_1 T_2 * V_89 ;
T_1 V_21 ;
int V_90 ;
V_89 = & V_11 -> V_20 -> V_21 [ V_87 ] ;
for ( V_90 = 4 ; V_90 > 0 ; -- V_90 ) {
F_10 ( & V_11 -> V_24 ) ;
V_21 = F_7 ( V_11 , V_89 ) ;
if ( ( V_21 & V_25 ) == V_88
|| ( V_21 & ( V_25 | V_46 ) )
== 0 )
V_90 = 0 ;
else {
V_21 ^= V_25 ;
V_21 &= ~ ( V_27 | V_22 ) ;
F_12 ( V_11 , V_21 , V_89 ) ;
}
F_13 ( & V_11 -> V_24 ) ;
if ( V_90 > 1 )
F_9 ( 5 ) ;
}
}
static int F_44 (
struct V_10 * V_11 ,
int V_91 ,
T_1 T_2 * V_89 ,
int V_21
) {
if ( ! ( V_21 & V_46 ) )
return V_21 ;
if ( ! ( V_21 & V_27 ) ) {
if ( F_45 ( V_11 ) ) {
F_15 ( V_11 ,
L_11 ,
V_91 + 1 ) ;
return V_21 ;
}
F_15 ( V_11 , L_12 ,
V_91 + 1 ) ;
V_21 |= V_25 ;
V_21 &= ~ V_22 ;
F_12 ( V_11 , V_21 , V_89 ) ;
if ( V_11 -> V_92 )
F_46 ( V_11 , 1 ) ;
} else {
F_15 ( V_11 , L_13 ,
V_91 + 1 ) ;
if ( V_11 -> V_92 )
F_46 ( V_11 , 0 ) ;
}
return V_21 ;
}
static int
F_47 ( struct V_16 * V_17 , char * V_15 )
{
struct V_10 * V_11 = F_20 ( V_17 ) ;
T_1 V_36 , V_13 ;
T_1 V_50 ;
int V_93 , V_32 , V_94 = 1 ;
unsigned long V_95 ;
T_1 V_96 = ~ 0 ;
V_15 [ 0 ] = 0 ;
V_93 = F_5 ( V_11 -> V_19 ) ;
if ( V_93 > 7 ) {
V_15 [ 1 ] = 0 ;
V_94 ++ ;
}
V_13 = V_11 -> V_58 ;
if ( ! V_97 )
V_50 = V_31 | V_98 | V_99 ;
else
V_50 = V_31 | V_98 ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
if ( V_11 -> V_100 )
V_96 = F_7 ( V_11 , & V_11 -> V_20 -> V_13 ) >> 16 ;
for ( V_32 = 0 ; V_32 < V_93 ; V_32 ++ ) {
if ( V_96 & ( 1 << V_32 ) )
V_36 = F_7 ( V_11 , & V_11 -> V_20 -> V_21 [ V_32 ] ) ;
else
V_36 = 0 ;
if ( ( V_36 & V_50 ) != 0 || F_6 ( V_32 , & V_11 -> V_101 )
|| ( V_11 -> V_102 [ V_32 ] && F_49 (
V_53 , V_11 -> V_102 [ V_32 ] ) ) ) {
if ( V_32 < 7 )
V_15 [ 0 ] |= 1 << ( V_32 + 1 ) ;
else
V_15 [ 1 ] |= 1 << ( V_32 - 7 ) ;
V_13 = V_33 ;
}
}
if ( V_11 -> V_58 )
F_50 ( & V_17 -> V_103 , V_53 + F_36 ( 25 ) ) ;
F_51 ( & V_11 -> V_24 , V_95 ) ;
return V_13 ? V_94 : 0 ;
}
static void
F_52 (
struct V_10 * V_11 ,
struct V_104 * V_105
) {
int V_93 = F_5 ( V_11 -> V_19 ) ;
T_4 V_36 ;
V_105 -> V_106 = V_107 ;
V_105 -> V_108 = 10 ;
V_105 -> V_109 = 0 ;
V_105 -> V_110 = V_93 ;
V_36 = 1 + ( V_93 / 8 ) ;
V_105 -> V_111 = 7 + 2 * V_36 ;
memset ( & V_105 -> V_112 . V_113 . V_114 [ 0 ] , 0 , V_36 ) ;
memset ( & V_105 -> V_112 . V_113 . V_114 [ V_36 ] , 0xff , V_36 ) ;
V_36 = V_115 ;
if ( F_53 ( V_11 -> V_19 ) )
V_36 |= V_116 ;
else
V_36 |= V_117 ;
#if 0
if (HCS_INDICATOR (ehci->hcs_params))
temp |= HUB_CHAR_PORTIND;
#endif
V_105 -> V_118 = F_54 ( V_36 ) ;
}
static void F_55 ( struct V_119 * V_119 )
{
struct V_120 * V_57 = V_119 -> V_121 ;
F_56 ( V_57 ) ;
}
static struct V_119 * F_57 (
struct V_1 * V_2 ,
void * V_122 ,
void * V_15 ,
struct V_120 * V_57
) {
struct V_119 * V_119 ;
struct V_16 * V_17 = F_58 ( V_2 -> V_6 ) ;
struct V_123 * V_124 ;
V_119 = F_59 ( 0 , V_125 ) ;
if ( ! V_119 )
return NULL ;
V_119 -> V_126 = F_60 ( V_2 , 0 ) ;
V_124 = ( F_61 ( V_119 -> V_126 ) ? V_2 -> V_127 : V_2 -> V_128 )
[ F_62 ( V_119 -> V_126 ) ] ;
if ( ! V_124 ) {
F_63 ( V_119 ) ;
return NULL ;
}
V_119 -> V_124 = V_124 ;
V_119 -> V_129 = V_2 ;
V_119 -> V_130 = ( void * ) V_122 ;
V_119 -> V_131 = V_15 ;
V_119 -> V_132 = V_133 ;
V_119 -> F_56 = F_55 ;
V_119 -> V_13 = - V_134 ;
V_119 -> V_135 = 0 ;
V_119 -> V_136 = V_137 ;
F_64 ( V_119 ) ;
F_65 ( & V_119 -> V_138 ) ;
F_65 ( & V_119 -> V_129 -> V_139 ) ;
V_119 -> V_140 = F_66 (
V_17 -> V_37 . V_141 ,
V_119 -> V_130 ,
sizeof( struct V_142 ) ,
V_143 ) ;
V_119 -> V_144 = F_66 (
V_17 -> V_37 . V_141 ,
V_119 -> V_131 ,
V_119 -> V_132 ,
V_145 ) ;
V_119 -> V_121 = V_57 ;
return V_119 ;
}
static int F_67 ( struct V_16 * V_17 , int V_14 )
{
int V_94 = - V_146 ;
struct V_142 * V_122 ;
struct V_119 * V_119 ;
struct V_1 * V_2 ;
struct V_10 * V_11 = F_20 ( V_17 ) ;
struct V_147 * V_15 ;
F_68 ( V_57 ) ;
V_2 = F_69 ( V_17 -> V_37 . V_7 , V_14 ) ;
if ( ! V_2 ) {
F_70 ( V_11 , L_14 ) ;
return - V_148 ;
}
V_15 = F_71 ( V_133 , V_125 ) ;
if ( ! V_15 )
return - V_146 ;
V_122 = F_71 ( sizeof( struct V_142 ) , V_125 ) ;
if ( ! V_122 ) {
F_72 ( V_15 ) ;
return - V_146 ;
}
V_122 -> V_149 = V_150 ;
V_122 -> V_151 = V_152 ;
V_122 -> V_153 = F_54 ( V_154 << 8 ) ;
V_122 -> V_155 = 0 ;
V_122 -> V_156 = F_54 ( V_133 ) ;
V_119 = F_57 ( V_2 , V_122 , V_15 , & V_57 ) ;
if ( ! V_119 )
goto V_157;
V_94 = F_73 ( V_17 , V_119 , 1 ) ;
if ( V_94 )
goto V_158;
if ( ! F_74 ( & V_57 , F_36 ( 2000 ) ) ) {
F_75 ( V_119 ) ;
V_94 = - V_159 ;
F_70 ( V_11 , L_15 , V_160 ) ;
goto V_158;
}
F_9 ( 15 * 1000 ) ;
V_119 -> V_13 = - V_134 ;
F_64 ( V_119 ) ;
F_65 ( & V_119 -> V_138 ) ;
F_65 ( & V_119 -> V_129 -> V_139 ) ;
V_94 = F_73 ( V_17 , V_119 , 0 ) ;
if ( ! V_94 && ! F_74 ( & V_57 ,
F_36 ( 2000 ) ) ) {
F_75 ( V_119 ) ;
V_94 = - V_159 ;
F_70 ( V_11 , L_16 , V_160 ) ;
}
V_158:
F_63 ( V_119 ) ;
V_157:
F_72 ( V_122 ) ;
F_72 ( V_15 ) ;
return V_94 ;
}
int F_14 (
struct V_16 * V_17 ,
T_4 V_161 ,
T_4 V_153 ,
T_4 V_155 ,
char * V_15 ,
T_4 V_156
) {
struct V_10 * V_11 = F_20 ( V_17 ) ;
int V_93 = F_5 ( V_11 -> V_19 ) ;
T_1 T_2 * V_89 , * V_40 ;
T_1 V_36 , V_162 , V_13 ;
unsigned long V_95 ;
int V_94 = 0 ;
unsigned V_163 ;
V_36 = V_155 & 0xff ;
V_36 -= ( V_36 > 0 ) ;
V_89 = & V_11 -> V_20 -> V_21 [ V_36 ] ;
V_40 = & V_11 -> V_20 -> V_41 [ V_36 ] ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
switch ( V_161 ) {
case V_164 :
switch ( V_153 ) {
case V_165 :
case V_166 :
break;
default:
goto error;
}
break;
case V_167 :
if ( ! V_155 || V_155 > V_93 )
goto error;
V_155 -- ;
V_36 = F_7 ( V_11 , V_89 ) ;
V_36 &= ~ V_22 ;
switch ( V_153 ) {
case V_168 :
F_12 ( V_11 , V_36 & ~ V_27 , V_89 ) ;
break;
case V_169 :
F_12 ( V_11 , V_36 | V_98 , V_89 ) ;
break;
case V_170 :
if ( V_36 & V_171 )
goto error;
if ( V_11 -> V_172 )
break;
#ifdef F_76
if ( ( V_17 -> V_37 . V_173 == ( V_155 + 1 ) )
&& V_17 -> V_37 . V_174 ) {
F_77 ( V_17 -> V_175 -> V_176 ) ;
break;
}
#endif
if ( ! ( V_36 & V_61 ) )
break;
if ( ( V_36 & V_27 ) == 0 )
goto error;
if ( V_11 -> V_39 ) {
V_162 = F_7 ( V_11 , V_40 ) ;
F_12 ( V_11 , V_162 & ~ V_42 ,
V_40 ) ;
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_9 ( 5 ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
}
V_36 &= ~ V_45 ;
F_12 ( V_11 , V_36 | V_84 , V_89 ) ;
V_11 -> V_102 [ V_155 ] = V_53
+ F_36 ( V_85 ) ;
F_23 ( V_155 , & V_11 -> V_58 ) ;
F_78 ( & V_17 -> V_37 , V_155 ) ;
break;
case V_177 :
F_11 ( V_155 , & V_11 -> V_101 ) ;
break;
case V_178 :
if ( F_53 ( V_11 -> V_19 ) ) {
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_8 ( V_11 , V_155 , false ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
}
break;
case V_179 :
F_12 ( V_11 , V_36 | V_31 , V_89 ) ;
break;
case V_180 :
F_12 ( V_11 , V_36 | V_99 , V_89 ) ;
break;
case V_181 :
break;
default:
goto error;
}
F_7 ( V_11 , & V_11 -> V_20 -> V_82 ) ;
break;
case V_182 :
F_52 ( V_11 , (struct V_104 * )
V_15 ) ;
break;
case V_183 :
memset ( V_15 , 0 , 4 ) ;
break;
case V_30 :
if ( ! V_155 || V_155 > V_93 )
goto error;
V_155 -- ;
V_13 = 0 ;
V_36 = F_7 ( V_11 , V_89 ) ;
if ( V_36 & V_31 )
V_13 |= V_184 << 16 ;
if ( V_36 & V_98 )
V_13 |= V_185 << 16 ;
if ( ( V_36 & V_99 ) && ! V_97 ) {
V_13 |= V_186 << 16 ;
if ( ( ( V_36 & V_187 ) || ( V_11 -> V_188 ) )
&& F_53 ( V_11 -> V_19 ) ) {
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_8 ( V_11 , V_155 , false ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
V_36 = F_7 ( V_11 , V_89 ) ;
}
}
if ( ! V_11 -> V_102 [ V_155 ] ) {
if ( V_36 & V_84 ) {
V_11 -> V_102 [ V_155 ] = V_53
+ F_36 ( 20 ) ;
F_78 ( & V_17 -> V_37 , V_155 ) ;
F_23 ( V_155 , & V_11 -> V_58 ) ;
F_50 ( & F_3 ( V_11 ) -> V_103 ,
V_11 -> V_102 [ V_155 ] ) ;
}
} else if ( ! F_49 ( V_53 , V_11 -> V_102 [ V_155 ] ) ) {
;
} else if ( F_6 ( V_155 , & V_11 -> V_58 ) ) {
F_11 ( V_155 , & V_11 -> V_189 ) ;
F_23 ( V_155 , & V_11 -> V_101 ) ;
V_11 -> V_102 [ V_155 ] = 0 ;
F_79 ( & V_17 -> V_37 , V_155 ) ;
V_36 &= ~ ( V_22 | V_61 | V_84 ) ;
F_12 ( V_11 , V_36 , V_89 ) ;
F_11 ( V_155 , & V_11 -> V_58 ) ;
V_94 = F_80 ( V_11 , V_89 ,
V_84 , 0 , 2000 ) ;
if ( V_94 != 0 ) {
F_70 ( V_11 , L_17 ,
V_155 + 1 , V_94 ) ;
goto error;
}
V_36 = F_7 ( V_11 , V_89 ) ;
} else {
V_13 |= V_190 << 16 ;
V_11 -> V_102 [ V_155 ] = 0 ;
F_12 ( V_11 , V_36 & ~ ( V_22 | V_171 ) ,
V_89 ) ;
V_94 = F_80 ( V_11 , V_89 ,
V_171 , 0 , 1000 ) ;
if ( V_94 != 0 ) {
F_70 ( V_11 , L_18 ,
V_155 + 1 , V_94 ) ;
goto error;
}
V_36 = F_44 ( V_11 , V_155 , V_89 ,
F_7 ( V_11 , V_89 ) ) ;
}
if ( ( V_36 & V_46 ) &&
F_6 ( V_155 , & V_11 -> V_26 ) ) {
V_36 &= ~ V_22 ;
V_36 |= V_25 ;
F_12 ( V_11 , V_36 , V_89 ) ;
F_15 ( V_11 , L_19 , V_155 + 1 ) ;
V_36 = F_7 ( V_11 , V_89 ) ;
}
if ( V_36 & V_46 ) {
V_13 |= V_191 ;
if ( V_11 -> V_192 ) {
V_162 = F_7 ( V_11 , V_40 ) ;
V_13 |= F_24 ( V_11 , V_162 ) ;
} else
V_13 |= F_24 ( V_11 , V_36 ) ;
}
if ( V_36 & V_27 )
V_13 |= V_193 ;
if ( V_36 & ( V_61 | V_84 ) ) {
V_13 |= V_194 ;
} else if ( F_6 ( V_155 , & V_11 -> V_189 ) ) {
F_11 ( V_155 , & V_11 -> V_189 ) ;
F_11 ( V_155 , & V_11 -> V_58 ) ;
V_11 -> V_102 [ V_155 ] = 0 ;
if ( V_36 & V_27 )
F_23 ( V_155 , & V_11 -> V_101 ) ;
F_79 ( & V_17 -> V_37 , V_155 ) ;
}
if ( V_36 & V_187 )
V_13 |= V_195 ;
if ( V_36 & V_171 )
V_13 |= V_196 ;
if ( V_36 & V_23 )
V_13 |= V_197 ;
if ( F_6 ( V_155 , & V_11 -> V_101 ) )
V_13 |= V_198 << 16 ;
if ( V_13 & ~ 0xffff )
F_81 ( V_11 , L_20 , V_155 + 1 , V_36 ) ;
F_82 ( V_13 , V_15 ) ;
break;
case V_199 :
switch ( V_153 ) {
case V_165 :
case V_166 :
break;
default:
goto error;
}
break;
case V_28 :
V_163 = V_155 >> 8 ;
V_155 &= 0xff ;
if ( F_40 ( V_11 -> V_75 ) ) {
if ( V_155 == F_83 ( V_11 -> V_19 ) &&
( F_84 ( & V_11 -> V_75 -> V_200 ) & V_201 ) ) {
V_94 = - V_148 ;
goto V_202;
}
}
if ( ! V_155 || V_155 > V_93 )
goto error;
V_155 -- ;
V_36 = F_7 ( V_11 , V_89 ) ;
if ( V_36 & V_25 )
break;
V_36 &= ~ V_22 ;
switch ( V_153 ) {
case V_170 :
if ( V_11 -> V_172 )
break;
if ( ( V_36 & V_27 ) == 0
|| ( V_36 & V_171 ) != 0 )
goto error;
V_36 &= ~ V_49 ;
V_36 |= V_48 | V_47 ;
F_12 ( V_11 , V_36 | V_61 , V_89 ) ;
if ( V_11 -> V_39 ) {
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_9 ( 5 ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
V_162 = F_7 ( V_11 , V_40 ) ;
F_12 ( V_11 , V_162 | V_42 ,
V_40 ) ;
V_162 = F_7 ( V_11 , V_40 ) ;
F_15 ( V_11 , L_21 ,
V_155 , ( V_162 & V_42 ) ?
L_5 : L_6 ) ;
}
if ( F_25 ( V_11 ) ) {
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_26 ( 10000 , 20000 ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
}
F_23 ( V_155 , & V_11 -> V_189 ) ;
break;
case V_178 :
if ( F_53 ( V_11 -> V_19 ) ) {
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_8 ( V_11 , V_155 , true ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
}
break;
case V_29 :
if ( V_36 & ( V_61 | V_84 ) )
goto error;
if ( ( V_36 & ( V_27 | V_46 ) ) == V_46
&& ! F_45 ( V_11 )
&& F_85 ( V_36 ) ) {
F_15 ( V_11 ,
L_22 ,
V_155 + 1 ) ;
V_36 |= V_25 ;
} else {
V_36 |= V_171 ;
V_36 &= ~ V_27 ;
V_11 -> V_102 [ V_155 ] = V_53
+ F_36 ( 50 ) ;
if ( F_86 ( V_11 ) )
V_36 |= ( 1 << V_203 ) ;
}
F_12 ( V_11 , V_36 , V_89 ) ;
break;
case V_204 :
#ifdef F_87
if ( V_163 == V_205 ) {
F_51 ( & V_11 -> V_24 , V_95 ) ;
V_94 = F_67 ( V_17 ,
V_155 + 1 ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
break;
}
#endif
if ( ! V_163 || V_163 > 5 )
goto error;
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_22 ( V_11 ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
while ( V_93 -- ) {
T_1 T_2 * V_206 =
& V_11 -> V_20 -> V_21 [ V_93 ] ;
V_36 = F_7 ( V_11 , V_206 ) & ~ V_22 ;
if ( V_36 & V_27 )
F_12 ( V_11 , V_36 | V_61 ,
V_206 ) ;
}
F_51 ( & V_11 -> V_24 , V_95 ) ;
F_28 ( V_11 ) ;
F_48 ( & V_11 -> V_24 , V_95 ) ;
V_36 = F_7 ( V_11 , V_89 ) ;
V_36 |= V_163 << 16 ;
F_12 ( V_11 , V_36 , V_89 ) ;
break;
default:
goto error;
}
F_7 ( V_11 , & V_11 -> V_20 -> V_82 ) ;
break;
default:
error:
V_94 = - V_207 ;
}
V_202:
F_51 ( & V_11 -> V_24 , V_95 ) ;
return V_94 ;
}
static void F_88 ( struct V_16 * V_17 , int V_87 )
{
struct V_10 * V_11 = F_20 ( V_17 ) ;
if ( F_45 ( V_11 ) )
return;
F_43 ( V_11 , -- V_87 , V_25 ) ;
}
static int F_89 ( struct V_16 * V_17 , int V_87 )
{
struct V_10 * V_11 = F_20 ( V_17 ) ;
T_1 T_2 * V_12 ;
if ( F_45 ( V_11 ) )
return 0 ;
V_12 = & V_11 -> V_20 -> V_21 [ V_87 - 1 ] ;
return F_7 ( V_11 , V_12 ) & V_25 ;
}
static int F_8 ( struct V_10 * V_11 , int V_87 , bool V_208 )
{
struct V_16 * V_17 = F_3 ( V_11 ) ;
T_1 T_2 * V_89 = & V_11 -> V_20 -> V_21 [ V_87 ] ;
T_1 V_36 = F_7 ( V_11 , V_89 ) & ~ V_22 ;
if ( V_208 )
F_12 ( V_11 , V_36 | V_23 , V_89 ) ;
else
F_12 ( V_11 , V_36 & ~ V_23 , V_89 ) ;
if ( V_17 -> V_209 -> V_210 )
V_17 -> V_209 -> V_210 ( V_17 , V_87 , V_208 ) ;
return 0 ;
}
