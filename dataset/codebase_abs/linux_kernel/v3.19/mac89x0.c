static inline int
F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( F_3 ( V_3 ) , V_2 -> V_4 + V_5 ) ;
return F_3 ( F_4 ( V_2 -> V_4 + V_6 ) ) ;
}
static inline void
F_5 ( struct V_1 * V_2 , int V_3 , int V_7 )
{
F_2 ( F_3 ( V_3 ) , V_2 -> V_4 + V_5 ) ;
F_2 ( F_3 ( V_7 ) , V_2 -> V_4 + V_6 ) ;
}
static inline int
F_6 ( struct V_1 * V_2 , int V_3 )
{
return F_3 ( F_4 ( V_2 -> V_8 + V_3 ) ) ;
}
static inline void
F_7 ( struct V_1 * V_2 , int V_3 , int V_7 )
{
F_2 ( F_3 ( V_7 ) , V_2 -> V_8 + V_3 ) ;
}
struct V_1 * T_1 F_8 ( int V_9 )
{
struct V_1 * V_2 ;
static int V_10 ;
struct V_11 * V_12 ;
static unsigned V_13 ;
int V_14 , V_15 ;
unsigned V_16 = 0 ;
unsigned long V_17 ;
unsigned short V_18 ;
int V_19 = - V_20 ;
if ( ! V_21 )
return F_9 ( - V_20 ) ;
V_2 = F_10 ( sizeof( struct V_11 ) ) ;
if ( ! V_2 )
return F_9 ( - V_22 ) ;
if ( V_9 >= 0 ) {
sprintf ( V_2 -> V_23 , L_1 , V_9 ) ;
F_11 ( V_2 ) ;
}
if ( V_10 )
goto V_24;
V_10 = 1 ;
V_15 = 0xE ;
if ( F_12 ( V_15 , NULL ) != NULL )
goto V_24;
V_17 = ( unsigned long )
F_13 ( V_15 ) | ( ( ( V_15 & 0xf ) << 20 ) + V_25 ) ;
{
int V_26 ;
V_26 = ( F_14 ( ( void * ) V_17 + 4 ) &&
F_14 ( ( void * ) V_17 + V_6 ) ) ;
if ( ! V_26 )
goto V_24;
}
F_2 ( 0 , V_17 + V_5 ) ;
V_18 = F_4 ( V_17 + V_6 ) ;
if ( V_18 != F_3 ( V_27 ) )
goto V_24;
V_12 = F_15 ( V_2 ) ;
V_2 -> V_4 = V_17 ;
V_2 -> V_8 = ( unsigned long )
F_13 ( V_15 ) | ( ( ( V_15 & 0xf ) << 20 ) + V_28 ) ;
V_2 -> V_29 = V_2 -> V_8 + 0x1000 ;
F_5 ( V_2 , V_30 , V_31 ) ;
V_16 = F_6 ( V_2 , V_32 ) ;
V_12 -> V_33 = V_16 & ~ V_34 ;
V_12 -> V_35 = ( ( V_16 & V_34 ) >> 8 ) + 'A' ;
V_12 -> V_36 = V_37 ;
if ( V_12 -> V_33 == V_38 && V_12 -> V_35 >= 'F' )
V_12 -> V_36 = V_39 ;
if ( V_12 -> V_33 != V_38 && V_12 -> V_35 >= 'C' )
V_12 -> V_36 = V_39 ;
if ( V_40 && V_13 ++ == 0 )
F_16 ( V_41 ) ;
F_16 ( V_42 L_2 ,
V_2 -> V_23 ,
V_12 -> V_33 == V_38 ? '0' : '2' ,
V_12 -> V_33 == V_43 ? L_3 : L_4 ,
V_12 -> V_35 ,
V_2 -> V_4 ) ;
if ( ( F_6 ( V_2 , V_44 ) & ( V_45 | V_46 ) ) == 0 ) {
F_16 ( L_5 ) ;
goto V_47;
} else {
for ( V_14 = 0 ; V_14 < V_48 ; V_14 += 2 ) {
unsigned short V_49 = F_6 ( V_2 , V_50 + V_14 ) ;
V_2 -> V_51 [ V_14 ] = V_49 >> 8 ;
V_2 -> V_51 [ V_14 + 1 ] = V_49 & 0xff ;
}
}
V_2 -> V_52 = F_17 ( V_15 ) ;
F_16 ( L_6 , V_2 -> V_52 , V_2 -> V_51 ) ;
V_2 -> V_53 = & V_54 ;
V_19 = F_18 ( V_2 ) ;
if ( V_19 )
goto V_47;
return NULL ;
V_47:
F_2 ( 0 , V_2 -> V_4 + V_5 ) ;
V_24:
F_19 ( V_2 ) ;
return F_9 ( V_19 ) ;
}
static int
F_20 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_15 ( V_2 ) ;
int V_14 ;
F_7 ( V_2 , V_30 , F_6 ( V_2 , V_30 ) & ~ V_55 ) ;
if ( F_21 ( V_2 -> V_52 , V_56 , 0 , L_7 , V_2 ) )
return - V_57 ;
if ( V_12 -> V_33 == V_38 )
F_7 ( V_2 , V_58 , 0 ) ;
else
F_7 ( V_2 , V_59 , 0 ) ;
for ( V_14 = 0 ; V_14 < V_48 / 2 ; V_14 ++ )
F_7 ( V_2 , V_50 + V_14 * 2 , V_2 -> V_51 [ V_14 * 2 ] | ( V_2 -> V_51 [ V_14 * 2 + 1 ] << 8 ) ) ;
F_7 ( V_2 , V_60 , F_6 ( V_2 , V_60 ) | V_61 | V_62 ) ;
V_12 -> V_63 = 0 ;
F_7 ( V_2 , V_64 , V_65 ) ;
V_12 -> V_66 = V_67 | V_68 ;
F_7 ( V_2 , V_69 , V_12 -> V_66 ) ;
F_7 ( V_2 , V_70 , V_71 | V_72 | V_73 |
V_74 | V_75 | V_76 | V_77 ) ;
F_7 ( V_2 , V_78 , V_79 | V_80 |
V_81 | V_82 ) ;
F_7 ( V_2 , V_30 , F_6 ( V_2 , V_30 ) | V_55 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int
F_23 ( struct V_83 * V_84 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_15 ( V_2 ) ;
unsigned long V_85 ;
if ( V_40 > 3 )
F_16 ( L_8 ,
V_2 -> V_23 , V_84 -> V_86 ,
( V_84 -> V_87 [ V_48 + V_48 ] << 8 )
| V_84 -> V_87 [ V_48 + V_48 + 1 ] ) ;
F_24 ( V_85 ) ;
F_25 ( V_2 ) ;
F_7 ( V_2 , V_88 , V_12 -> V_36 ) ;
F_7 ( V_2 , V_89 , V_84 -> V_86 ) ;
if ( ( F_6 ( V_2 , V_90 ) & V_91 ) == 0 ) {
F_26 ( V_85 ) ;
return V_92 ;
}
F_27 ( V_84 , ( void * ) ( V_2 -> V_8 + V_93 ) ,
V_84 -> V_86 + 1 ) ;
F_26 ( V_85 ) ;
F_28 ( V_84 ) ;
return V_94 ;
}
static T_2 V_56 ( int V_52 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_11 * V_12 ;
int V_17 , V_96 ;
if ( V_2 == NULL ) {
F_16 ( L_9 , V_52 ) ;
return V_97 ;
}
V_17 = V_2 -> V_4 ;
V_12 = F_15 ( V_2 ) ;
while ( ( V_96 = F_3 ( F_4 ( V_2 -> V_4 + V_98 ) ) ) ) {
if ( V_40 > 4 ) F_16 ( L_10 , V_2 -> V_23 , V_96 ) ;
switch( V_96 & V_99 ) {
case V_100 :
F_29 ( V_2 ) ;
break;
case V_101 :
V_2 -> V_102 . V_103 ++ ;
F_30 ( V_2 ) ;
if ( ( V_96 & V_104 ) == 0 )
V_2 -> V_102 . V_105 ++ ;
if ( V_96 & V_106 )
V_2 -> V_102 . V_107 ++ ;
if ( V_96 & V_108 )
V_2 -> V_102 . V_109 ++ ;
if ( V_96 & V_110 )
V_2 -> V_102 . V_111 ++ ;
if ( V_96 & V_112 )
V_2 -> V_102 . V_113 ++ ;
break;
case V_114 :
if ( V_96 & V_115 ) {
F_30 ( V_2 ) ;
}
if ( V_96 & V_116 ) {
if ( V_40 > 0 ) F_16 ( L_11 , V_2 -> V_23 ) ;
V_12 -> V_117 ++ ;
if ( V_12 -> V_117 == 3 ) V_12 -> V_36 = V_37 ;
else if ( V_12 -> V_117 == 6 ) V_12 -> V_36 = V_118 ;
}
break;
case V_119 :
V_2 -> V_102 . V_120 += ( V_96 >> 6 ) ;
break;
case V_121 :
V_2 -> V_102 . V_122 += ( V_96 >> 6 ) ;
break;
}
}
return V_123 ;
}
static void
F_29 ( struct V_1 * V_2 )
{
struct V_83 * V_84 ;
int V_96 , V_124 ;
V_96 = F_6 ( V_2 , V_125 ) ;
if ( ( V_96 & V_126 ) == 0 ) {
V_2 -> V_102 . V_127 ++ ;
if ( V_96 & V_128 )
V_2 -> V_102 . V_129 ++ ;
if ( V_96 & V_130 )
V_2 -> V_102 . V_129 ++ ;
if ( ( V_96 & V_131 ) &&
! ( V_96 & ( V_130 | V_128 ) ) )
V_2 -> V_102 . V_132 ++ ;
if ( V_96 & V_133 )
V_2 -> V_102 . V_134 ++ ;
return;
}
V_124 = F_6 ( V_2 , V_135 ) ;
V_84 = F_31 ( V_124 , V_136 ) ;
if ( V_84 == NULL ) {
F_16 ( L_12 , V_2 -> V_23 ) ;
V_2 -> V_102 . V_137 ++ ;
return;
}
F_32 ( V_84 , V_124 ) ;
F_33 ( V_84 , ( void * ) ( V_2 -> V_8 + V_138 ) ,
V_124 ) ;
if ( V_40 > 3 ) F_16 ( L_13 ,
V_2 -> V_23 , V_124 ,
( V_84 -> V_87 [ V_48 + V_48 ] << 8 )
| V_84 -> V_87 [ V_48 + V_48 + 1 ] ) ;
V_84 -> V_139 = F_34 ( V_84 , V_2 ) ;
F_35 ( V_84 ) ;
V_2 -> V_102 . V_140 ++ ;
V_2 -> V_102 . V_141 += V_124 ;
}
static int
F_36 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_69 , 0 ) ;
F_7 ( V_2 , V_70 , 0 ) ;
F_7 ( V_2 , V_78 , 0 ) ;
F_7 ( V_2 , V_30 , 0 ) ;
F_25 ( V_2 ) ;
F_37 ( V_2 -> V_52 , V_2 ) ;
return 0 ;
}
static struct V_142 *
F_38 ( struct V_1 * V_2 )
{
unsigned long V_85 ;
F_24 ( V_85 ) ;
V_2 -> V_102 . V_120 += ( F_6 ( V_2 , V_143 ) >> 6 ) ;
V_2 -> V_102 . V_122 += ( F_6 ( V_2 , V_144 ) >> 6 ) ;
F_26 ( V_85 ) ;
return & V_2 -> V_102 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_15 ( V_2 ) ;
if( V_2 -> V_85 & V_145 )
{
V_12 -> V_63 = V_146 ;
} else if ( ( V_2 -> V_85 & V_147 ) || ! F_40 ( V_2 ) ) {
V_12 -> V_63 = V_148 ;
}
else
V_12 -> V_63 = 0 ;
F_7 ( V_2 , V_64 , V_65 | V_12 -> V_63 ) ;
F_7 ( V_2 , V_69 , V_12 -> V_66 |
( V_12 -> V_63 == V_146 ? ( V_68 | V_149 | V_150 ) : 0 ) ) ;
}
static int F_41 ( struct V_1 * V_2 , void * V_151 )
{
struct V_152 * V_153 = V_151 ;
int V_14 ;
if ( ! F_42 ( V_153 -> V_154 ) )
return - V_155 ;
memcpy ( V_2 -> V_51 , V_153 -> V_154 , V_48 ) ;
F_16 ( L_14 , V_2 -> V_23 , V_2 -> V_51 ) ;
for ( V_14 = 0 ; V_14 < V_48 / 2 ; V_14 ++ )
F_7 ( V_2 , V_50 + V_14 * 2 , V_2 -> V_51 [ V_14 * 2 ] | ( V_2 -> V_51 [ V_14 * 2 + 1 ] << 8 ) ) ;
return 0 ;
}
int T_1
F_43 ( void )
{
V_40 = V_156 ;
V_157 = F_8 ( - 1 ) ;
if ( F_44 ( V_157 ) ) {
F_16 ( V_158 L_15 ) ;
return F_45 ( V_157 ) ;
}
return 0 ;
}
void
F_46 ( void )
{
F_47 ( V_157 ) ;
F_2 ( 0 , V_157 -> V_4 + V_5 ) ;
F_19 ( V_157 ) ;
}
