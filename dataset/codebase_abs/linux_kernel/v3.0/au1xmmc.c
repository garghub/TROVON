static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( F_3 ( V_2 ) ) ;
V_4 |= V_3 ;
F_4 ( V_4 , F_3 ( V_2 ) ) ;
F_5 () ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
T_1 V_4 = F_2 ( F_7 ( V_2 ) ) ;
F_4 ( V_4 | V_5 , F_7 ( V_2 ) ) ;
F_8 ( 1 ) ;
V_4 &= ~ V_6 ;
F_4 ( V_4 , F_7 ( V_2 ) ) ;
F_5 () ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( F_3 ( V_2 ) ) ;
V_4 &= ~ V_3 ;
F_4 ( V_4 , F_3 ( V_2 ) ) ;
F_5 () ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
T_1 V_7 ;
F_11 ( V_2 -> V_8 != V_9 ) ;
V_2 -> V_8 = V_10 ;
V_7 = F_2 ( F_7 ( V_2 ) ) ;
F_4 ( V_7 | V_6 , F_7 ( V_2 ) ) ;
F_5 () ;
F_4 ( V_11 , F_12 ( V_2 ) ) ;
}
static void F_13 ( struct V_1 * V_2 , int V_12 )
{
if ( V_2 -> V_13 && V_2 -> V_13 -> V_14 )
V_2 -> V_13 -> V_14 ( V_2 -> V_15 , V_12 ) ;
}
static int F_14 ( struct V_16 * V_15 )
{
struct V_1 * V_2 = F_15 ( V_15 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_17 )
return ! ! V_2 -> V_13 -> V_17 ( V_2 -> V_15 ) ;
return - V_18 ;
}
static int F_16 ( struct V_16 * V_15 )
{
struct V_1 * V_2 = F_15 ( V_15 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_19 )
return ! ! V_2 -> V_13 -> V_19 ( V_15 ) ;
return - V_18 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
V_2 -> V_21 = NULL ;
V_2 -> V_22 &= V_23 | V_24 ;
V_2 -> V_25 . V_26 = 0 ;
V_2 -> V_25 . V_27 = 0 ;
V_2 -> V_28 . V_29 = 0 ;
V_2 -> V_28 . V_30 = 0 ;
V_2 -> V_28 . V_26 = 0 ;
V_2 -> V_8 = V_31 ;
F_18 ( V_2 -> V_15 , V_21 ) ;
}
static void F_19 ( unsigned long V_32 )
{
struct V_1 * V_2 = (struct V_1 * ) V_32 ;
F_17 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_33 ,
struct V_34 * V_35 , struct V_36 * V_37 )
{
T_1 V_38 = ( V_35 -> V_39 << V_40 ) ;
switch ( F_21 ( V_35 ) ) {
case V_41 :
break;
case V_42 :
V_38 |= V_43 ;
break;
case V_44 :
V_38 |= V_45 ;
break;
case V_46 :
V_38 |= V_47 ;
break;
case V_48 :
V_38 |= V_49 ;
break;
default:
F_22 ( V_50 L_1 ,
F_21 ( V_35 ) ) ;
return - V_51 ;
}
if ( V_37 ) {
if ( V_37 -> V_22 & V_52 ) {
if ( V_37 -> V_53 > 1 )
V_38 |= V_54 ;
else
V_38 |= V_55 ;
} else if ( V_37 -> V_22 & V_56 ) {
if ( V_37 -> V_53 > 1 )
V_38 |= V_57 ;
else
V_38 |= V_58 ;
}
}
F_4 ( V_35 -> V_59 , F_23 ( V_2 ) ) ;
F_5 () ;
if ( V_33 )
F_9 ( V_2 , V_60 ) ;
F_4 ( ( V_38 | V_61 ) , F_12 ( V_2 ) ) ;
F_5 () ;
while ( F_2 ( F_12 ( V_2 ) ) & V_61 )
;
if ( V_33 ) {
T_1 V_8 = F_2 ( F_24 ( V_2 ) ) ;
while ( ! ( V_8 & V_62 ) )
V_8 = F_2 ( F_24 ( V_2 ) ) ;
F_4 ( V_62 , F_24 ( V_2 ) ) ;
F_1 ( V_2 , V_60 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_36 * V_37 ;
T_1 V_63 ;
F_11 ( ( V_2 -> V_8 != V_9 ) && ( V_2 -> V_8 != V_10 ) ) ;
if ( V_2 -> V_21 == NULL )
return;
V_37 = V_21 -> V_35 -> V_37 ;
if ( V_8 == 0 )
V_8 = F_2 ( F_24 ( V_2 ) ) ;
while ( ( V_2 -> V_22 & V_64 ) && ( V_8 & V_65 ) )
V_8 = F_2 ( F_24 ( V_2 ) ) ;
V_37 -> error = 0 ;
F_26 ( F_27 ( V_2 -> V_15 ) , V_37 -> V_66 , V_37 -> V_67 , V_2 -> V_25 . V_27 ) ;
V_63 = ( V_8 & ( V_68 | V_69 ) ) ;
if ( V_2 -> V_22 & V_64 )
V_63 |= ( ( V_8 & 0x07 ) == 0x02 ) ? 0 : 1 ;
if ( V_63 )
V_37 -> error = - V_70 ;
F_4 ( V_68 | V_69 , F_24 ( V_2 ) ) ;
V_37 -> V_71 = 0 ;
if ( ! V_37 -> error ) {
if ( V_2 -> V_22 & V_24 ) {
#ifdef F_28
T_1 V_72 = F_29 ( V_2 ) ;
T_2 * V_73 = * ( ( T_2 * * ) V_72 ) ;
T_3 * V_74 = V_73 -> V_75 ;
V_37 -> V_71 = V_74 -> V_76 ;
#endif
} else
V_37 -> V_71 =
( V_37 -> V_53 * V_37 -> V_77 ) - V_2 -> V_28 . V_26 ;
}
F_17 ( V_2 ) ;
}
static void F_30 ( unsigned long V_32 )
{
struct V_1 * V_2 = (struct V_1 * ) V_32 ;
T_1 V_8 = F_2 ( F_24 ( V_2 ) ) ;
F_25 ( V_2 , V_8 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
int V_67 , V_78 , V_79 ;
unsigned char * V_80 , V_4 ;
T_1 V_8 ;
struct V_81 * V_66 ;
V_37 = V_2 -> V_21 -> V_37 ;
if ( ! ( V_2 -> V_22 & V_64 ) )
return;
V_66 = & V_37 -> V_66 [ V_2 -> V_28 . V_29 ] ;
V_80 = F_32 ( V_66 ) + V_2 -> V_28 . V_30 ;
V_67 = V_37 -> V_66 [ V_2 -> V_28 . V_29 ] . V_82 - V_2 -> V_28 . V_30 ;
V_78 = ( V_67 > V_2 -> V_28 . V_26 ) ? V_2 -> V_28 . V_26 : V_67 ;
if ( V_78 > V_83 )
V_78 = V_83 ;
for ( V_79 = 0 ; V_79 < V_78 ; V_79 ++ ) {
V_8 = F_2 ( F_24 ( V_2 ) ) ;
if ( ! ( V_8 & V_84 ) )
break;
V_4 = * V_80 ++ ;
F_4 ( ( unsigned long ) V_4 , F_33 ( V_2 ) ) ;
F_5 () ;
}
V_2 -> V_28 . V_26 -= V_79 ;
V_2 -> V_28 . V_30 += V_79 ;
if ( V_79 == V_67 ) {
V_2 -> V_28 . V_29 ++ ;
V_2 -> V_28 . V_30 = 0 ;
}
if ( V_2 -> V_28 . V_26 == 0 ) {
F_9 ( V_2 , V_85 ) ;
if ( V_2 -> V_22 & V_86 )
F_10 ( V_2 ) ;
F_34 ( & V_2 -> V_87 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_36 * V_37 ;
int V_78 , V_79 , V_67 = 0 ;
unsigned char * V_80 = NULL ;
T_1 V_8 , V_4 ;
struct V_81 * V_66 ;
V_37 = V_2 -> V_21 -> V_37 ;
if ( ! ( V_2 -> V_22 & V_88 ) )
return;
V_78 = V_2 -> V_28 . V_26 ;
if ( V_2 -> V_28 . V_29 < V_2 -> V_25 . V_26 ) {
V_66 = & V_37 -> V_66 [ V_2 -> V_28 . V_29 ] ;
V_80 = F_32 ( V_66 ) + V_2 -> V_28 . V_30 ;
V_67 = F_36 ( & V_37 -> V_66 [ V_2 -> V_28 . V_29 ] ) - V_2 -> V_28 . V_30 ;
if ( V_67 < V_78 )
V_78 = V_67 ;
}
if ( V_78 > V_83 )
V_78 = V_83 ;
for ( V_79 = 0 ; V_79 < V_78 ; V_79 ++ ) {
V_8 = F_2 ( F_24 ( V_2 ) ) ;
if ( ! ( V_8 & V_89 ) )
break;
if ( V_8 & V_69 ) {
F_37 ( L_2 , V_2 -> V_90 -> V_91 ,
V_2 -> V_28 . V_26 , V_79 ) ;
break;
}
if ( V_8 & V_92 ) {
F_37 ( L_3 , V_2 -> V_90 -> V_91 ,
V_2 -> V_28 . V_26 , V_79 ) ;
break;
}
else if ( V_8 & V_93 ) {
F_37 ( L_4 , V_2 -> V_90 -> V_91 ,
V_2 -> V_28 . V_26 , V_79 ) ;
break;
}
V_4 = F_2 ( F_38 ( V_2 ) ) ;
if ( V_80 )
* V_80 ++ = ( unsigned char ) ( V_4 & 0xFF ) ;
}
V_2 -> V_28 . V_26 -= V_79 ;
V_2 -> V_28 . V_30 += V_79 ;
if ( V_67 && V_79 == V_67 ) {
V_2 -> V_28 . V_29 ++ ;
V_2 -> V_28 . V_30 = 0 ;
}
if ( V_2 -> V_28 . V_26 == 0 ) {
F_9 ( V_2 , V_94 ) ;
if ( V_2 -> V_22 & V_86 )
F_10 ( V_2 ) ;
F_34 ( & V_2 -> V_87 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_20 * V_21 = V_2 -> V_21 ;
struct V_34 * V_35 ;
T_1 V_95 [ 4 ] ;
int V_96 , V_97 ;
if ( ! V_2 -> V_21 )
return;
V_35 = V_21 -> V_35 ;
V_35 -> error = 0 ;
if ( V_35 -> V_22 & V_98 ) {
if ( V_35 -> V_22 & V_99 ) {
V_95 [ 0 ] = F_2 ( V_2 -> V_100 + V_101 ) ;
V_95 [ 1 ] = F_2 ( V_2 -> V_100 + V_102 ) ;
V_95 [ 2 ] = F_2 ( V_2 -> V_100 + V_103 ) ;
V_95 [ 3 ] = F_2 ( V_2 -> V_100 + V_104 ) ;
for ( V_96 = 0 ; V_96 < 4 ; V_96 ++ ) {
V_35 -> V_105 [ V_96 ] = ( V_95 [ V_96 ] & 0x00FFFFFF ) << 8 ;
if ( V_96 != 3 )
V_35 -> V_105 [ V_96 ] |= ( V_95 [ V_96 + 1 ] & 0xFF000000 ) >> 24 ;
}
} else {
V_35 -> V_105 [ 0 ] = F_2 ( V_2 -> V_100 + V_104 ) ;
}
}
if ( V_8 & ( V_106 | V_68 | V_69 ) )
V_35 -> error = - V_70 ;
V_97 = V_2 -> V_22 & ( V_64 | V_88 ) ;
if ( ! V_97 || V_35 -> error ) {
F_9 ( V_2 , V_85 | V_107 | V_108 ) ;
F_34 ( & V_2 -> V_109 ) ;
return;
}
V_2 -> V_8 = V_9 ;
if ( V_2 -> V_22 & V_24 ) {
#ifdef F_28
T_1 V_110 = F_29 ( V_2 ) ;
if ( V_2 -> V_22 & V_88 ) {
T_1 V_3 = V_65 | V_89 ;
while( ( V_8 & V_3 ) != V_3 )
V_8 = F_2 ( F_24 ( V_2 ) ) ;
}
F_40 ( V_110 ) ;
#endif
}
}
static void F_41 ( struct V_1 * V_2 , int V_111 )
{
unsigned int V_112 = F_42 () ;
unsigned int V_113 ;
T_1 V_114 ;
V_112 /= ( ( F_2 ( V_115 ) & 0x3 ) + 2 ) ;
V_112 /= 2 ;
V_113 = ( ( V_112 / V_111 ) / 2 ) - 1 ;
V_114 = F_2 ( F_3 ( V_2 ) ) ;
V_114 &= ~ ( V_116 ) ;
V_114 |= ( V_113 & V_116 ) | V_117 ;
F_4 ( V_114 , F_3 ( V_2 ) ) ;
F_5 () ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_118 = V_37 -> V_53 * V_37 -> V_77 ;
if ( V_37 -> V_22 & V_52 )
V_2 -> V_22 |= V_88 ;
else
V_2 -> V_22 |= V_64 ;
if ( V_2 -> V_21 -> V_119 )
V_2 -> V_22 |= V_86 ;
V_2 -> V_25 . V_27 = V_120 ;
V_2 -> V_25 . V_26 = F_44 ( F_27 ( V_2 -> V_15 ) , V_37 -> V_66 ,
V_37 -> V_67 , V_2 -> V_25 . V_27 ) ;
if ( V_2 -> V_25 . V_26 == 0 )
return - V_121 ;
F_4 ( V_37 -> V_77 - 1 , F_45 ( V_2 ) ) ;
if ( V_2 -> V_22 & V_24 ) {
#ifdef F_28
int V_96 ;
T_1 V_110 = F_29 ( V_2 ) ;
F_46 ( V_110 ) ;
for ( V_96 = 0 ; V_96 < V_2 -> V_25 . V_26 ; V_96 ++ ) {
T_1 V_122 = 0 , V_22 = V_123 ;
struct V_81 * V_66 = & V_37 -> V_66 [ V_96 ] ;
int V_67 = V_66 -> V_82 ;
int V_26 = ( V_118 > V_67 ) ? V_67 : V_118 ;
if ( V_96 == V_2 -> V_25 . V_26 - 1 )
V_22 = V_124 ;
if ( V_2 -> V_22 & V_64 ) {
V_122 = F_47 ( V_110 ,
F_48 ( V_66 ) , V_26 , V_22 ) ;
} else {
V_122 = F_49 ( V_110 ,
F_48 ( V_66 ) , V_26 , V_22 ) ;
}
if ( ! V_122 )
goto V_125;
V_118 -= V_26 ;
}
#endif
} else {
V_2 -> V_28 . V_29 = 0 ;
V_2 -> V_28 . V_30 = 0 ;
V_2 -> V_28 . V_26 = V_118 ;
if ( V_2 -> V_22 & V_64 )
F_1 ( V_2 , V_85 ) ;
else
F_1 ( V_2 , V_94 ) ;
}
return 0 ;
V_125:
F_26 ( F_27 ( V_2 -> V_15 ) , V_37 -> V_66 , V_37 -> V_67 ,
V_2 -> V_25 . V_27 ) ;
return - V_121 ;
}
static void F_50 ( struct V_16 * V_15 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_15 ( V_15 ) ;
int V_122 = 0 ;
F_11 ( F_51 () ) ;
F_11 ( V_2 -> V_8 != V_31 ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_8 = V_126 ;
if ( 0 == F_14 ( V_15 ) ) {
V_21 -> V_35 -> error = - V_127 ;
F_17 ( V_2 ) ;
return;
}
if ( V_21 -> V_37 ) {
F_6 ( V_2 ) ;
V_122 = F_43 ( V_2 , V_21 -> V_37 ) ;
}
if ( ! V_122 )
V_122 = F_20 ( V_2 , 0 , V_21 -> V_35 , V_21 -> V_37 ) ;
if ( V_122 ) {
V_21 -> V_35 -> error = V_122 ;
F_17 ( V_2 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
F_4 ( V_128 , F_53 ( V_2 ) ) ;
F_8 ( 1 ) ;
F_4 ( V_129 | V_128 , F_53 ( V_2 ) ) ;
F_8 ( 5 ) ;
F_4 ( ~ 0 , F_24 ( V_2 ) ) ;
F_5 () ;
F_4 ( 0 , F_45 ( V_2 ) ) ;
F_4 ( 0x001fffff , F_54 ( V_2 ) ) ;
F_5 () ;
F_4 ( V_130 , F_7 ( V_2 ) ) ;
F_5 () ;
F_4 ( V_130 | V_5 , F_7 ( V_2 ) ) ;
F_8 ( 1 ) ;
F_4 ( V_130 , F_7 ( V_2 ) ) ;
F_5 () ;
F_4 ( V_131 , F_3 ( V_2 ) ) ;
F_5 () ;
}
static void F_55 ( struct V_16 * V_15 , struct V_132 * V_133 )
{
struct V_1 * V_2 = F_15 ( V_15 ) ;
T_1 V_7 ;
if ( V_133 -> V_134 == V_135 )
F_13 ( V_2 , 0 ) ;
else if ( V_133 -> V_134 == V_136 ) {
F_13 ( V_2 , 1 ) ;
}
if ( V_133 -> clock && V_133 -> clock != V_2 -> clock ) {
F_41 ( V_2 , V_133 -> clock ) ;
V_2 -> clock = V_133 -> clock ;
}
V_7 = F_2 ( F_7 ( V_2 ) ) ;
switch ( V_133 -> V_137 ) {
case V_138 :
V_7 |= V_139 ;
break;
case V_140 :
V_7 &= ~ V_139 ;
break;
}
F_4 ( V_7 , F_7 ( V_2 ) ) ;
F_5 () ;
}
static T_4 F_56 ( int V_141 , void * V_142 )
{
struct V_1 * V_2 = V_142 ;
T_1 V_8 ;
V_8 = F_2 ( F_24 ( V_2 ) ) ;
if ( ! ( V_8 & V_143 ) )
return V_144 ;
if ( V_8 & V_145 )
F_57 ( V_2 -> V_15 ) ;
if ( V_2 -> V_21 && ( V_8 & V_146 ) ) {
if ( V_8 & V_147 )
V_2 -> V_21 -> V_35 -> error = - V_121 ;
else if ( V_8 & V_148 )
V_2 -> V_21 -> V_37 -> error = - V_121 ;
F_9 ( V_2 , V_94 | V_85 ) ;
F_34 ( & V_2 -> V_109 ) ;
}
#if 0
else if (status & SD_STATUS_DD) {
if (!(host->flags & HOST_F_DMA) && (status & SD_STATUS_NE))
au1xmmc_receive_pio(host);
else {
au1xmmc_data_complete(host, status);
}
}
#endif
else if ( V_8 & V_62 ) {
if ( V_2 -> V_8 == V_126 )
F_39 ( V_2 , V_8 ) ;
} else if ( ! ( V_2 -> V_22 & V_24 ) ) {
if ( ( V_2 -> V_22 & V_64 ) && ( V_8 & V_149 ) )
F_31 ( V_2 ) ;
else if ( ( V_2 -> V_22 & V_88 ) && ( V_8 & V_150 ) )
F_35 ( V_2 ) ;
} else if ( V_8 & 0x203F3C70 ) {
F_37 ( L_5 , V_2 -> V_90 -> V_91 ,
V_8 ) ;
}
F_4 ( V_8 , F_24 ( V_2 ) ) ;
F_5 () ;
return V_151 ;
}
static void F_58 ( int V_141 , void * V_142 )
{
struct V_1 * V_2 = (struct V_1 * ) V_142 ;
if ( ! V_2 -> V_21 )
return;
if ( V_2 -> V_22 & V_86 )
F_10 ( V_2 ) ;
F_34 ( & V_2 -> V_87 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_152 * V_153 ;
int V_154 , V_155 ;
V_153 = F_60 ( V_2 -> V_90 , V_156 , 0 ) ;
if ( ! V_153 )
return - V_157 ;
V_154 = V_153 -> V_158 ;
V_153 = F_60 ( V_2 -> V_90 , V_156 , 1 ) ;
if ( ! V_153 )
return - V_157 ;
V_155 = V_153 -> V_158 ;
if ( ! V_159 )
return - V_157 ;
V_2 -> V_160 = F_61 ( V_159 , V_154 ,
F_58 , ( void * ) V_2 ) ;
if ( ! V_2 -> V_160 ) {
F_62 ( & V_2 -> V_90 -> V_161 , L_6 ) ;
return - V_157 ;
}
V_2 -> V_162 = F_61 ( V_155 , V_159 ,
F_58 , ( void * ) V_2 ) ;
if ( ! V_2 -> V_162 ) {
F_62 ( & V_2 -> V_90 -> V_161 , L_7 ) ;
F_63 ( V_2 -> V_160 ) ;
return - V_157 ;
}
F_64 ( V_2 -> V_160 , 8 ) ;
F_64 ( V_2 -> V_162 , 8 ) ;
F_65 ( V_2 -> V_160 , V_163 ) ;
F_65 ( V_2 -> V_162 , V_163 ) ;
V_2 -> V_22 |= V_24 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 & V_24 ) {
V_2 -> V_22 &= ~ V_24 ;
F_63 ( V_2 -> V_160 ) ;
F_63 ( V_2 -> V_162 ) ;
}
}
static void F_67 ( struct V_16 * V_15 , int V_164 )
{
struct V_1 * V_2 = F_15 ( V_15 ) ;
if ( V_164 )
F_1 ( V_2 , V_165 ) ;
else
F_9 ( V_2 , V_165 ) ;
}
static int T_5 F_68 ( struct V_166 * V_90 )
{
struct V_16 * V_15 ;
struct V_1 * V_2 ;
struct V_152 * V_95 ;
int V_122 ;
V_15 = F_69 ( sizeof( struct V_1 ) , & V_90 -> V_161 ) ;
if ( ! V_15 ) {
F_62 ( & V_90 -> V_161 , L_8 ) ;
V_122 = - V_167 ;
goto V_168;
}
V_2 = F_15 ( V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_13 = V_90 -> V_161 . V_169 ;
V_2 -> V_90 = V_90 ;
V_122 = - V_157 ;
V_95 = F_60 ( V_90 , V_170 , 0 ) ;
if ( ! V_95 ) {
F_62 ( & V_90 -> V_161 , L_9 ) ;
goto V_171;
}
V_2 -> V_172 = F_70 ( V_95 -> V_158 , F_71 ( V_95 ) ,
V_90 -> V_173 ) ;
if ( ! V_2 -> V_172 ) {
F_62 ( & V_90 -> V_161 , L_10 ) ;
goto V_171;
}
V_2 -> V_100 = ( unsigned long ) F_72 ( V_95 -> V_158 , 0x3c ) ;
if ( ! V_2 -> V_100 ) {
F_62 ( & V_90 -> V_161 , L_11 ) ;
goto V_174;
}
V_95 = F_60 ( V_90 , V_175 , 0 ) ;
if ( ! V_95 ) {
F_62 ( & V_90 -> V_161 , L_12 ) ;
goto V_176;
}
V_2 -> V_141 = V_95 -> V_158 ;
V_122 = F_73 ( V_2 -> V_141 , F_56 , V_177 ,
V_178 , V_2 ) ;
if ( V_122 ) {
F_62 ( & V_90 -> V_161 , L_13 ) ;
goto V_176;
}
V_15 -> V_179 = & V_180 ;
V_15 -> V_181 = 450000 ;
V_15 -> V_182 = 24000000 ;
V_15 -> V_183 = V_184 ;
V_15 -> V_185 = V_163 ;
V_15 -> V_186 = 2048 ;
V_15 -> V_187 = 512 ;
V_15 -> V_188 = V_189 ;
V_15 -> V_190 = V_191 | V_192 ;
V_2 -> V_8 = V_31 ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_193 ) {
V_122 = V_2 -> V_13 -> V_193 ( V_15 , 1 ) ;
if ( V_122 ) {
F_74 ( & V_90 -> V_161 , L_14 ) ;
V_15 -> V_190 |= V_194 ;
}
} else
V_15 -> V_190 |= V_194 ;
if ( V_2 -> V_13 )
V_15 -> V_190 &= ~ ( V_2 -> V_13 -> V_195 ) ;
F_75 ( & V_2 -> V_87 , F_30 ,
( unsigned long ) V_2 ) ;
F_75 ( & V_2 -> V_109 , F_19 ,
( unsigned long ) V_2 ) ;
#ifdef F_28
V_122 = F_59 ( V_2 ) ;
if ( V_122 )
F_22 (KERN_INFO DRIVER_NAME L_15 ) ;
#endif
#ifdef F_76
if ( V_2 -> V_13 && V_2 -> V_13 -> V_196 ) {
struct V_197 * V_196 = V_2 -> V_13 -> V_196 ;
V_196 -> V_173 = F_77 ( V_15 ) ;
V_196 -> V_198 = V_199 ;
V_196 -> V_200 = F_77 ( V_15 ) ;
V_122 = F_78 ( F_27 ( V_15 ) , V_196 ) ;
if ( V_122 )
goto V_201;
}
#endif
F_52 ( V_2 ) ;
V_122 = F_79 ( V_15 ) ;
if ( V_122 ) {
F_62 ( & V_90 -> V_161 , L_16 ) ;
goto V_202;
}
F_80 ( V_90 , V_2 ) ;
F_22 (KERN_INFO DRIVER_NAME L_17
L_18 , pdev->id, host->iobase,
host->flags & HOST_F_DMA ? L_19 : L_20 ) ;
return 0 ;
V_202:
#ifdef F_76
if ( V_2 -> V_13 && V_2 -> V_13 -> V_196 )
F_81 ( V_2 -> V_13 -> V_196 ) ;
V_201:
#endif
F_4 ( 0 , F_53 ( V_2 ) ) ;
F_4 ( 0 , F_3 ( V_2 ) ) ;
F_4 ( 0 , F_7 ( V_2 ) ) ;
F_5 () ;
#ifdef F_28
F_66 ( V_2 ) ;
#endif
F_82 ( & V_2 -> V_87 ) ;
F_82 ( & V_2 -> V_109 ) ;
if ( V_2 -> V_13 && V_2 -> V_13 -> V_193 &&
! ( V_15 -> V_190 & V_194 ) )
V_2 -> V_13 -> V_193 ( V_15 , 0 ) ;
F_83 ( V_2 -> V_141 , V_2 ) ;
V_176:
F_84 ( ( void * ) V_2 -> V_100 ) ;
V_174:
F_85 ( V_2 -> V_172 ) ;
F_86 ( V_2 -> V_172 ) ;
V_171:
F_87 ( V_15 ) ;
V_168:
return V_122 ;
}
static int T_6 F_88 ( struct V_166 * V_90 )
{
struct V_1 * V_2 = F_89 ( V_90 ) ;
if ( V_2 ) {
F_90 ( V_2 -> V_15 ) ;
#ifdef F_76
if ( V_2 -> V_13 && V_2 -> V_13 -> V_196 )
F_81 ( V_2 -> V_13 -> V_196 ) ;
#endif
if ( V_2 -> V_13 && V_2 -> V_13 -> V_193 &&
! ( V_2 -> V_15 -> V_190 & V_194 ) )
V_2 -> V_13 -> V_193 ( V_2 -> V_15 , 0 ) ;
F_4 ( 0 , F_53 ( V_2 ) ) ;
F_4 ( 0 , F_3 ( V_2 ) ) ;
F_4 ( 0 , F_7 ( V_2 ) ) ;
F_5 () ;
F_82 ( & V_2 -> V_87 ) ;
F_82 ( & V_2 -> V_109 ) ;
#ifdef F_28
F_66 ( V_2 ) ;
#endif
F_13 ( V_2 , 0 ) ;
F_83 ( V_2 -> V_141 , V_2 ) ;
F_84 ( ( void * ) V_2 -> V_100 ) ;
F_85 ( V_2 -> V_172 ) ;
F_86 ( V_2 -> V_172 ) ;
F_87 ( V_2 -> V_15 ) ;
F_80 ( V_90 , NULL ) ;
}
return 0 ;
}
static int F_91 ( struct V_166 * V_90 , T_7 V_12 )
{
struct V_1 * V_2 = F_89 ( V_90 ) ;
int V_122 ;
V_122 = F_92 ( V_2 -> V_15 ) ;
if ( V_122 )
return V_122 ;
F_4 ( 0 , F_7 ( V_2 ) ) ;
F_4 ( 0 , F_3 ( V_2 ) ) ;
F_4 ( 0xffffffff , F_24 ( V_2 ) ) ;
F_4 ( 0 , F_53 ( V_2 ) ) ;
F_5 () ;
return 0 ;
}
static int F_93 ( struct V_166 * V_90 )
{
struct V_1 * V_2 = F_89 ( V_90 ) ;
F_52 ( V_2 ) ;
return F_94 ( V_2 -> V_15 ) ;
}
static int T_8 F_95 ( void )
{
#ifdef F_28
V_159 = F_96 ( & V_203 ) ;
if ( ! V_159 )
F_22 ( V_204 L_21 ) ;
#endif
return F_97 ( & V_205 ) ;
}
static void T_9 F_98 ( void )
{
#ifdef F_28
if ( V_159 )
F_99 ( V_159 ) ;
#endif
F_100 ( & V_205 ) ;
}
