static inline int F_1 ( void )
{
switch ( F_2 () ) {
case V_1 :
case V_2 :
return 1 ;
default:
return 0 ;
}
}
static inline void F_3 ( struct V_3 * V_4 , T_1 V_5 )
{
T_1 V_6 = F_4 ( F_5 ( V_4 ) ) ;
V_6 |= V_5 ;
F_6 ( V_6 , F_5 ( V_4 ) ) ;
F_7 () ;
}
static inline void F_8 ( struct V_3 * V_4 )
{
T_1 V_6 = F_4 ( F_9 ( V_4 ) ) ;
F_6 ( V_6 | V_7 , F_9 ( V_4 ) ) ;
F_10 ( 1 ) ;
V_6 &= ~ V_8 ;
F_6 ( V_6 , F_9 ( V_4 ) ) ;
F_7 () ;
}
static inline void F_11 ( struct V_3 * V_4 , T_1 V_5 )
{
T_1 V_6 = F_4 ( F_5 ( V_4 ) ) ;
V_6 &= ~ V_5 ;
F_6 ( V_6 , F_5 ( V_4 ) ) ;
F_7 () ;
}
static inline void F_12 ( struct V_3 * V_4 )
{
T_1 V_9 ;
F_13 ( V_4 -> V_10 != V_11 ) ;
V_4 -> V_10 = V_12 ;
V_9 = F_4 ( F_9 ( V_4 ) ) ;
F_6 ( V_9 | V_8 , F_9 ( V_4 ) ) ;
F_7 () ;
F_6 ( V_13 , F_14 ( V_4 ) ) ;
}
static void F_15 ( struct V_3 * V_4 , int V_14 )
{
if ( V_4 -> V_15 && V_4 -> V_15 -> V_16 )
V_4 -> V_15 -> V_16 ( V_4 -> V_17 , V_14 ) ;
}
static int F_16 ( struct V_18 * V_17 )
{
struct V_3 * V_4 = F_17 ( V_17 ) ;
if ( V_4 -> V_15 && V_4 -> V_15 -> V_19 )
return ! ! V_4 -> V_15 -> V_19 ( V_4 -> V_17 ) ;
return - V_20 ;
}
static int F_18 ( struct V_18 * V_17 )
{
struct V_3 * V_4 = F_17 ( V_17 ) ;
if ( V_4 -> V_15 && V_4 -> V_15 -> V_21 )
return ! ! V_4 -> V_15 -> V_21 ( V_17 ) ;
return - V_20 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 &= V_25 | V_26 ;
V_4 -> V_27 . V_28 = 0 ;
V_4 -> V_27 . V_29 = 0 ;
V_4 -> V_30 . V_31 = 0 ;
V_4 -> V_30 . V_32 = 0 ;
V_4 -> V_30 . V_28 = 0 ;
V_4 -> V_10 = V_33 ;
F_20 ( V_4 -> V_17 , V_23 ) ;
}
static void F_21 ( unsigned long V_34 )
{
struct V_3 * V_4 = (struct V_3 * ) V_34 ;
F_19 ( V_4 ) ;
}
static int F_22 ( struct V_3 * V_4 , int V_35 ,
struct V_36 * V_37 , struct V_38 * V_39 )
{
T_1 V_40 = ( V_37 -> V_41 << V_42 ) ;
switch ( F_23 ( V_37 ) ) {
case V_43 :
break;
case V_44 :
V_40 |= V_45 ;
break;
case V_46 :
V_40 |= V_47 ;
break;
case V_48 :
V_40 |= V_49 ;
break;
case V_50 :
V_40 |= V_51 ;
break;
default:
F_24 ( L_1 ,
F_23 ( V_37 ) ) ;
return - V_52 ;
}
if ( V_39 ) {
if ( V_39 -> V_24 & V_53 ) {
if ( V_39 -> V_54 > 1 )
V_40 |= V_55 ;
else
V_40 |= V_56 ;
} else if ( V_39 -> V_24 & V_57 ) {
if ( V_39 -> V_54 > 1 )
V_40 |= V_58 ;
else
V_40 |= V_59 ;
}
}
F_6 ( V_37 -> V_60 , F_25 ( V_4 ) ) ;
F_7 () ;
if ( V_35 )
F_11 ( V_4 , V_61 ) ;
F_6 ( ( V_40 | V_62 ) , F_14 ( V_4 ) ) ;
F_7 () ;
while ( F_4 ( F_14 ( V_4 ) ) & V_62 )
;
if ( V_35 ) {
T_1 V_10 = F_4 ( F_26 ( V_4 ) ) ;
while ( ! ( V_10 & V_63 ) )
V_10 = F_4 ( F_26 ( V_4 ) ) ;
F_6 ( V_63 , F_26 ( V_4 ) ) ;
F_3 ( V_4 , V_61 ) ;
}
return 0 ;
}
static void F_27 ( struct V_3 * V_4 , T_1 V_10 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
struct V_38 * V_39 ;
T_1 V_64 ;
F_13 ( ( V_4 -> V_10 != V_11 ) && ( V_4 -> V_10 != V_12 ) ) ;
if ( V_4 -> V_23 == NULL )
return;
V_39 = V_23 -> V_37 -> V_39 ;
if ( V_10 == 0 )
V_10 = F_4 ( F_26 ( V_4 ) ) ;
while ( ( V_4 -> V_24 & V_65 ) && ( V_10 & V_66 ) )
V_10 = F_4 ( F_26 ( V_4 ) ) ;
V_39 -> error = 0 ;
F_28 ( F_29 ( V_4 -> V_17 ) , V_39 -> V_67 , V_39 -> V_68 , V_4 -> V_27 . V_29 ) ;
V_64 = ( V_10 & ( V_69 | V_70 ) ) ;
if ( V_4 -> V_24 & V_65 )
V_64 |= ( ( V_10 & 0x07 ) == 0x02 ) ? 0 : 1 ;
if ( V_64 )
V_39 -> error = - V_71 ;
F_6 ( V_69 | V_70 , F_26 ( V_4 ) ) ;
V_39 -> V_72 = 0 ;
if ( ! V_39 -> error ) {
if ( V_4 -> V_24 & ( V_26 | V_73 ) ) {
T_1 V_74 = F_30 ( V_4 ) ;
T_2 * V_75 = * ( ( T_2 * * ) V_74 ) ;
T_3 * V_76 = V_75 -> V_77 ;
V_39 -> V_72 = V_76 -> V_78 ;
} else
V_39 -> V_72 =
( V_39 -> V_54 * V_39 -> V_79 ) - V_4 -> V_30 . V_28 ;
}
F_19 ( V_4 ) ;
}
static void F_31 ( unsigned long V_34 )
{
struct V_3 * V_4 = (struct V_3 * ) V_34 ;
T_1 V_10 = F_4 ( F_26 ( V_4 ) ) ;
F_27 ( V_4 , V_10 ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_38 * V_39 ;
int V_68 , V_80 , V_81 ;
unsigned char * V_82 , V_6 ;
T_1 V_10 ;
struct V_83 * V_67 ;
V_39 = V_4 -> V_23 -> V_39 ;
if ( ! ( V_4 -> V_24 & V_65 ) )
return;
V_67 = & V_39 -> V_67 [ V_4 -> V_30 . V_31 ] ;
V_82 = F_33 ( V_67 ) + V_4 -> V_30 . V_32 ;
V_68 = V_39 -> V_67 [ V_4 -> V_30 . V_31 ] . V_84 - V_4 -> V_30 . V_32 ;
V_80 = ( V_68 > V_4 -> V_30 . V_28 ) ? V_4 -> V_30 . V_28 : V_68 ;
if ( V_80 > V_85 )
V_80 = V_85 ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
V_10 = F_4 ( F_26 ( V_4 ) ) ;
if ( ! ( V_10 & V_86 ) )
break;
V_6 = * V_82 ++ ;
F_6 ( ( unsigned long ) V_6 , F_34 ( V_4 ) ) ;
F_7 () ;
}
V_4 -> V_30 . V_28 -= V_81 ;
V_4 -> V_30 . V_32 += V_81 ;
if ( V_81 == V_68 ) {
V_4 -> V_30 . V_31 ++ ;
V_4 -> V_30 . V_32 = 0 ;
}
if ( V_4 -> V_30 . V_28 == 0 ) {
F_11 ( V_4 , V_87 ) ;
if ( V_4 -> V_24 & V_88 )
F_12 ( V_4 ) ;
F_35 ( & V_4 -> V_89 ) ;
}
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_38 * V_39 ;
int V_80 , V_81 , V_68 = 0 ;
unsigned char * V_82 = NULL ;
T_1 V_10 , V_6 ;
struct V_83 * V_67 ;
V_39 = V_4 -> V_23 -> V_39 ;
if ( ! ( V_4 -> V_24 & V_90 ) )
return;
V_80 = V_4 -> V_30 . V_28 ;
if ( V_4 -> V_30 . V_31 < V_4 -> V_27 . V_28 ) {
V_67 = & V_39 -> V_67 [ V_4 -> V_30 . V_31 ] ;
V_82 = F_33 ( V_67 ) + V_4 -> V_30 . V_32 ;
V_68 = F_37 ( & V_39 -> V_67 [ V_4 -> V_30 . V_31 ] ) - V_4 -> V_30 . V_32 ;
if ( V_68 < V_80 )
V_80 = V_68 ;
}
if ( V_80 > V_85 )
V_80 = V_85 ;
for ( V_81 = 0 ; V_81 < V_80 ; V_81 ++ ) {
V_10 = F_4 ( F_26 ( V_4 ) ) ;
if ( ! ( V_10 & V_91 ) )
break;
if ( V_10 & V_70 ) {
F_38 ( L_2 , V_4 -> V_92 -> V_93 ,
V_4 -> V_30 . V_28 , V_81 ) ;
break;
}
if ( V_10 & V_94 ) {
F_38 ( L_3 , V_4 -> V_92 -> V_93 ,
V_4 -> V_30 . V_28 , V_81 ) ;
break;
}
else if ( V_10 & V_95 ) {
F_38 ( L_4 , V_4 -> V_92 -> V_93 ,
V_4 -> V_30 . V_28 , V_81 ) ;
break;
}
V_6 = F_4 ( F_39 ( V_4 ) ) ;
if ( V_82 )
* V_82 ++ = ( unsigned char ) ( V_6 & 0xFF ) ;
}
V_4 -> V_30 . V_28 -= V_81 ;
V_4 -> V_30 . V_32 += V_81 ;
if ( V_68 && V_81 == V_68 ) {
V_4 -> V_30 . V_31 ++ ;
V_4 -> V_30 . V_32 = 0 ;
}
if ( V_4 -> V_30 . V_28 == 0 ) {
F_11 ( V_4 , V_96 ) ;
if ( V_4 -> V_24 & V_88 )
F_12 ( V_4 ) ;
F_35 ( & V_4 -> V_89 ) ;
}
}
static void F_40 ( struct V_3 * V_4 , T_1 V_10 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
struct V_36 * V_37 ;
T_1 V_97 [ 4 ] ;
int V_98 , V_99 ;
if ( ! V_4 -> V_23 )
return;
V_37 = V_23 -> V_37 ;
V_37 -> error = 0 ;
if ( V_37 -> V_24 & V_100 ) {
if ( V_37 -> V_24 & V_101 ) {
V_97 [ 0 ] = F_4 ( V_4 -> V_102 + V_103 ) ;
V_97 [ 1 ] = F_4 ( V_4 -> V_102 + V_104 ) ;
V_97 [ 2 ] = F_4 ( V_4 -> V_102 + V_105 ) ;
V_97 [ 3 ] = F_4 ( V_4 -> V_102 + V_106 ) ;
for ( V_98 = 0 ; V_98 < 4 ; V_98 ++ ) {
V_37 -> V_107 [ V_98 ] = ( V_97 [ V_98 ] & 0x00FFFFFF ) << 8 ;
if ( V_98 != 3 )
V_37 -> V_107 [ V_98 ] |= ( V_97 [ V_98 + 1 ] & 0xFF000000 ) >> 24 ;
}
} else {
V_37 -> V_107 [ 0 ] = F_4 ( V_4 -> V_102 + V_106 ) ;
}
}
if ( V_10 & ( V_108 | V_69 | V_70 ) )
V_37 -> error = - V_71 ;
V_99 = V_4 -> V_24 & ( V_65 | V_90 ) ;
if ( ! V_99 || V_37 -> error ) {
F_11 ( V_4 , V_87 | V_109 | V_110 ) ;
F_35 ( & V_4 -> V_111 ) ;
return;
}
V_4 -> V_10 = V_11 ;
if ( ( V_4 -> V_24 & ( V_26 | V_73 ) ) ) {
T_1 V_112 = F_30 ( V_4 ) ;
if ( V_4 -> V_24 & V_90 ) {
T_1 V_5 = V_66 | V_91 ;
while( ( V_10 & V_5 ) != V_5 )
V_10 = F_4 ( F_26 ( V_4 ) ) ;
}
F_41 ( V_112 ) ;
}
}
static void F_42 ( struct V_3 * V_4 , int V_113 )
{
unsigned int V_114 = F_43 () ;
unsigned int V_115 ;
T_1 V_116 ;
V_114 /= ( ( F_4 ( V_117 ) & 0x3 ) + 2 ) ;
V_114 /= 2 ;
V_115 = ( ( V_114 / V_113 ) / 2 ) - 1 ;
V_116 = F_4 ( F_5 ( V_4 ) ) ;
V_116 &= ~ ( V_118 ) ;
V_116 |= ( V_115 & V_118 ) | V_119 ;
F_6 ( V_116 , F_5 ( V_4 ) ) ;
F_7 () ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_38 * V_39 )
{
int V_120 = V_39 -> V_54 * V_39 -> V_79 ;
if ( V_39 -> V_24 & V_53 )
V_4 -> V_24 |= V_90 ;
else
V_4 -> V_24 |= V_65 ;
if ( V_4 -> V_23 -> V_121 )
V_4 -> V_24 |= V_88 ;
V_4 -> V_27 . V_29 = V_122 ;
V_4 -> V_27 . V_28 = F_45 ( F_29 ( V_4 -> V_17 ) , V_39 -> V_67 ,
V_39 -> V_68 , V_4 -> V_27 . V_29 ) ;
if ( V_4 -> V_27 . V_28 == 0 )
return - V_123 ;
F_6 ( V_39 -> V_79 - 1 , F_46 ( V_4 ) ) ;
if ( V_4 -> V_24 & ( V_26 | V_73 ) ) {
int V_98 ;
T_1 V_112 = F_30 ( V_4 ) ;
F_47 ( V_112 ) ;
for ( V_98 = 0 ; V_98 < V_4 -> V_27 . V_28 ; V_98 ++ ) {
T_1 V_124 = 0 , V_24 = V_125 ;
struct V_83 * V_67 = & V_39 -> V_67 [ V_98 ] ;
int V_68 = V_67 -> V_84 ;
int V_28 = ( V_120 > V_68 ) ? V_68 : V_120 ;
if ( V_98 == V_4 -> V_27 . V_28 - 1 )
V_24 = V_126 ;
if ( V_4 -> V_24 & V_65 ) {
V_124 = F_48 ( V_112 ,
F_49 ( V_67 ) , V_28 , V_24 ) ;
} else {
V_124 = F_50 ( V_112 ,
F_49 ( V_67 ) , V_28 , V_24 ) ;
}
if ( ! V_124 )
goto V_127;
V_120 -= V_28 ;
}
} else {
V_4 -> V_30 . V_31 = 0 ;
V_4 -> V_30 . V_32 = 0 ;
V_4 -> V_30 . V_28 = V_120 ;
if ( V_4 -> V_24 & V_65 )
F_3 ( V_4 , V_87 ) ;
else
F_3 ( V_4 , V_96 ) ;
}
return 0 ;
V_127:
F_28 ( F_29 ( V_4 -> V_17 ) , V_39 -> V_67 , V_39 -> V_68 ,
V_4 -> V_27 . V_29 ) ;
return - V_123 ;
}
static void F_51 ( struct V_18 * V_17 , struct V_22 * V_23 )
{
struct V_3 * V_4 = F_17 ( V_17 ) ;
int V_124 = 0 ;
F_13 ( F_52 () ) ;
F_13 ( V_4 -> V_10 != V_33 ) ;
V_4 -> V_23 = V_23 ;
V_4 -> V_10 = V_128 ;
if ( 0 == F_16 ( V_17 ) ) {
V_23 -> V_37 -> error = - V_129 ;
F_19 ( V_4 ) ;
return;
}
if ( V_23 -> V_39 ) {
F_8 ( V_4 ) ;
V_124 = F_44 ( V_4 , V_23 -> V_39 ) ;
}
if ( ! V_124 )
V_124 = F_22 ( V_4 , 0 , V_23 -> V_37 , V_23 -> V_39 ) ;
if ( V_124 ) {
V_23 -> V_37 -> error = V_124 ;
F_19 ( V_4 ) ;
}
}
static void F_53 ( struct V_3 * V_4 )
{
F_6 ( V_130 , F_54 ( V_4 ) ) ;
F_10 ( 1 ) ;
F_6 ( V_131 | V_130 , F_54 ( V_4 ) ) ;
F_10 ( 5 ) ;
F_6 ( ~ 0 , F_26 ( V_4 ) ) ;
F_7 () ;
F_6 ( 0 , F_46 ( V_4 ) ) ;
F_6 ( 0x001fffff , F_55 ( V_4 ) ) ;
F_7 () ;
F_6 ( V_132 , F_9 ( V_4 ) ) ;
F_7 () ;
F_6 ( V_132 | V_7 , F_9 ( V_4 ) ) ;
F_10 ( 1 ) ;
F_6 ( V_132 , F_9 ( V_4 ) ) ;
F_7 () ;
F_6 ( V_133 , F_5 ( V_4 ) ) ;
F_7 () ;
}
static void F_56 ( struct V_18 * V_17 , struct V_134 * V_135 )
{
struct V_3 * V_4 = F_17 ( V_17 ) ;
T_1 V_9 ;
if ( V_135 -> V_136 == V_137 )
F_15 ( V_4 , 0 ) ;
else if ( V_135 -> V_136 == V_138 ) {
F_15 ( V_4 , 1 ) ;
}
if ( V_135 -> clock && V_135 -> clock != V_4 -> clock ) {
F_42 ( V_4 , V_135 -> clock ) ;
V_4 -> clock = V_135 -> clock ;
}
V_9 = F_4 ( F_9 ( V_4 ) ) ;
switch ( V_135 -> V_139 ) {
case V_140 :
V_9 |= V_141 ;
break;
case V_142 :
V_9 &= ~ V_141 ;
V_9 |= V_143 ;
break;
case V_144 :
V_9 &= ~ ( V_143 | V_141 ) ;
break;
}
F_6 ( V_9 , F_9 ( V_4 ) ) ;
F_7 () ;
}
static T_4 F_57 ( int V_145 , void * V_146 )
{
struct V_3 * V_4 = V_146 ;
T_1 V_10 ;
V_10 = F_4 ( F_26 ( V_4 ) ) ;
if ( ! ( V_10 & V_147 ) )
return V_148 ;
if ( V_10 & V_149 )
F_58 ( V_4 -> V_17 ) ;
if ( V_4 -> V_23 && ( V_10 & V_150 ) ) {
if ( V_10 & V_151 )
V_4 -> V_23 -> V_37 -> error = - V_123 ;
else if ( V_10 & V_152 )
V_4 -> V_23 -> V_39 -> error = - V_123 ;
F_11 ( V_4 , V_96 | V_87 ) ;
F_35 ( & V_4 -> V_111 ) ;
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
else if ( V_10 & V_63 ) {
if ( V_4 -> V_10 == V_128 )
F_40 ( V_4 , V_10 ) ;
} else if ( ! ( V_4 -> V_24 & V_26 ) ) {
if ( ( V_4 -> V_24 & V_65 ) && ( V_10 & V_153 ) )
F_32 ( V_4 ) ;
else if ( ( V_4 -> V_24 & V_90 ) && ( V_10 & V_154 ) )
F_36 ( V_4 ) ;
} else if ( V_10 & 0x203F3C70 ) {
F_38 ( L_5 , V_4 -> V_92 -> V_93 ,
V_10 ) ;
}
F_6 ( V_10 , F_26 ( V_4 ) ) ;
F_7 () ;
return V_155 ;
}
static void F_59 ( int V_145 , void * V_146 )
{
struct V_3 * V_4 = (struct V_3 * ) V_146 ;
if ( ! V_4 -> V_23 )
return;
if ( V_4 -> V_24 & V_88 )
F_12 ( V_4 ) ;
F_35 ( & V_4 -> V_89 ) ;
}
static int F_60 ( struct V_3 * V_4 )
{
struct V_156 * V_157 ;
int V_158 , V_159 ;
V_157 = F_61 ( V_4 -> V_92 , V_160 , 0 ) ;
if ( ! V_157 )
return - V_161 ;
V_158 = V_157 -> V_162 ;
V_157 = F_61 ( V_4 -> V_92 , V_160 , 1 ) ;
if ( ! V_157 )
return - V_161 ;
V_159 = V_157 -> V_162 ;
if ( ! V_163 )
return - V_161 ;
V_4 -> V_164 = F_62 ( V_163 , V_158 ,
F_59 , ( void * ) V_4 ) ;
if ( ! V_4 -> V_164 ) {
F_63 ( & V_4 -> V_92 -> V_165 , L_6 ) ;
return - V_161 ;
}
V_4 -> V_166 = F_62 ( V_159 , V_163 ,
F_59 , ( void * ) V_4 ) ;
if ( ! V_4 -> V_166 ) {
F_63 ( & V_4 -> V_92 -> V_165 , L_7 ) ;
F_64 ( V_4 -> V_164 ) ;
return - V_161 ;
}
F_65 ( V_4 -> V_164 , 8 ) ;
F_65 ( V_4 -> V_166 , 8 ) ;
F_66 ( V_4 -> V_164 , V_167 ) ;
F_66 ( V_4 -> V_166 , V_167 ) ;
V_4 -> V_24 |= V_26 | V_73 ;
return 0 ;
}
static void F_67 ( struct V_3 * V_4 )
{
if ( V_4 -> V_24 & V_26 ) {
V_4 -> V_24 &= ~ V_26 ;
F_64 ( V_4 -> V_164 ) ;
F_64 ( V_4 -> V_166 ) ;
}
}
static void F_68 ( struct V_18 * V_17 , int V_168 )
{
struct V_3 * V_4 = F_17 ( V_17 ) ;
if ( V_168 )
F_3 ( V_4 , V_169 ) ;
else
F_11 ( V_4 , V_169 ) ;
}
static int F_69 ( struct V_170 * V_92 )
{
struct V_18 * V_17 ;
struct V_3 * V_4 ;
struct V_156 * V_97 ;
int V_124 , V_171 ;
V_17 = F_70 ( sizeof( struct V_3 ) , & V_92 -> V_165 ) ;
if ( ! V_17 ) {
F_63 ( & V_92 -> V_165 , L_8 ) ;
V_124 = - V_172 ;
goto V_173;
}
V_4 = F_17 ( V_17 ) ;
V_4 -> V_17 = V_17 ;
V_4 -> V_15 = V_92 -> V_165 . V_174 ;
V_4 -> V_92 = V_92 ;
V_124 = - V_161 ;
V_97 = F_61 ( V_92 , V_175 , 0 ) ;
if ( ! V_97 ) {
F_63 ( & V_92 -> V_165 , L_9 ) ;
goto V_176;
}
V_4 -> V_177 = F_71 ( V_97 -> V_162 , F_72 ( V_97 ) ,
V_92 -> V_178 ) ;
if ( ! V_4 -> V_177 ) {
F_63 ( & V_92 -> V_165 , L_10 ) ;
goto V_176;
}
V_4 -> V_102 = ( unsigned long ) F_73 ( V_97 -> V_162 , 0x3c ) ;
if ( ! V_4 -> V_102 ) {
F_63 ( & V_92 -> V_165 , L_11 ) ;
goto V_179;
}
V_97 = F_61 ( V_92 , V_180 , 0 ) ;
if ( ! V_97 ) {
F_63 ( & V_92 -> V_165 , L_12 ) ;
goto V_181;
}
V_4 -> V_145 = V_97 -> V_162 ;
V_17 -> V_182 = & V_183 ;
V_17 -> V_184 = 450000 ;
V_17 -> V_185 = 24000000 ;
V_17 -> V_186 = 2048 ;
V_17 -> V_187 = 512 ;
V_17 -> V_188 = V_189 ;
V_17 -> V_190 = V_191 | V_192 ;
V_17 -> V_193 = V_167 ;
V_171 = V_194 ;
switch ( F_2 () ) {
case V_195 :
V_17 -> V_196 = V_197 ;
break;
case V_1 :
V_17 -> V_196 = V_198 ;
break;
case V_2 :
V_171 = 0 ;
V_17 -> V_196 = V_198 ;
V_17 -> V_185 = 52000000 ;
if ( V_4 -> V_177 -> V_162 == V_199 )
V_17 -> V_190 |= V_200 ;
break;
}
V_124 = F_74 ( V_4 -> V_145 , F_57 , V_171 , V_201 , V_4 ) ;
if ( V_124 ) {
F_63 ( & V_92 -> V_165 , L_13 ) ;
goto V_181;
}
V_4 -> V_10 = V_33 ;
if ( V_4 -> V_15 && V_4 -> V_15 -> V_202 ) {
V_124 = V_4 -> V_15 -> V_202 ( V_17 , 1 ) ;
if ( V_124 ) {
F_75 ( & V_92 -> V_165 , L_14 ) ;
V_17 -> V_190 |= V_203 ;
}
} else
V_17 -> V_190 |= V_203 ;
if ( V_4 -> V_15 )
V_17 -> V_190 &= ~ ( V_4 -> V_15 -> V_204 ) ;
F_76 ( & V_4 -> V_89 , F_31 ,
( unsigned long ) V_4 ) ;
F_76 ( & V_4 -> V_111 , F_21 ,
( unsigned long ) V_4 ) ;
if ( F_1 () ) {
V_124 = F_60 ( V_4 ) ;
if ( V_124 )
F_24 ( V_201 L_15 ) ;
}
#ifdef F_77
if ( V_4 -> V_15 && V_4 -> V_15 -> V_205 ) {
struct V_206 * V_205 = V_4 -> V_15 -> V_205 ;
V_205 -> V_178 = F_78 ( V_17 ) ;
V_205 -> V_207 = V_208 ;
V_205 -> V_209 = F_78 ( V_17 ) ;
V_124 = F_79 ( F_29 ( V_17 ) , V_205 ) ;
if ( V_124 )
goto V_210;
}
#endif
F_53 ( V_4 ) ;
V_124 = F_80 ( V_17 ) ;
if ( V_124 ) {
F_63 ( & V_92 -> V_165 , L_16 ) ;
goto V_211;
}
F_81 ( V_92 , V_4 ) ;
F_24 ( V_201 L_17
L_18 , V_92 -> V_93 , V_4 -> V_102 ,
V_4 -> V_24 & V_26 ? L_19 : L_20 ) ;
return 0 ;
V_211:
#ifdef F_77
if ( V_4 -> V_15 && V_4 -> V_15 -> V_205 )
F_82 ( V_4 -> V_15 -> V_205 ) ;
V_210:
#endif
F_6 ( 0 , F_54 ( V_4 ) ) ;
F_6 ( 0 , F_5 ( V_4 ) ) ;
F_6 ( 0 , F_9 ( V_4 ) ) ;
F_7 () ;
if ( V_4 -> V_24 & V_73 )
F_67 ( V_4 ) ;
F_83 ( & V_4 -> V_89 ) ;
F_83 ( & V_4 -> V_111 ) ;
if ( V_4 -> V_15 && V_4 -> V_15 -> V_202 &&
! ( V_17 -> V_190 & V_203 ) )
V_4 -> V_15 -> V_202 ( V_17 , 0 ) ;
F_84 ( V_4 -> V_145 , V_4 ) ;
V_181:
F_85 ( ( void * ) V_4 -> V_102 ) ;
V_179:
F_86 ( V_4 -> V_177 ) ;
F_87 ( V_4 -> V_177 ) ;
V_176:
F_88 ( V_17 ) ;
V_173:
return V_124 ;
}
static int F_89 ( struct V_170 * V_92 )
{
struct V_3 * V_4 = F_90 ( V_92 ) ;
if ( V_4 ) {
F_91 ( V_4 -> V_17 ) ;
#ifdef F_77
if ( V_4 -> V_15 && V_4 -> V_15 -> V_205 )
F_82 ( V_4 -> V_15 -> V_205 ) ;
#endif
if ( V_4 -> V_15 && V_4 -> V_15 -> V_202 &&
! ( V_4 -> V_17 -> V_190 & V_203 ) )
V_4 -> V_15 -> V_202 ( V_4 -> V_17 , 0 ) ;
F_6 ( 0 , F_54 ( V_4 ) ) ;
F_6 ( 0 , F_5 ( V_4 ) ) ;
F_6 ( 0 , F_9 ( V_4 ) ) ;
F_7 () ;
F_83 ( & V_4 -> V_89 ) ;
F_83 ( & V_4 -> V_111 ) ;
if ( V_4 -> V_24 & V_73 )
F_67 ( V_4 ) ;
F_15 ( V_4 , 0 ) ;
F_84 ( V_4 -> V_145 , V_4 ) ;
F_85 ( ( void * ) V_4 -> V_102 ) ;
F_86 ( V_4 -> V_177 ) ;
F_87 ( V_4 -> V_177 ) ;
F_88 ( V_4 -> V_17 ) ;
}
return 0 ;
}
static int F_92 ( struct V_170 * V_92 , T_5 V_14 )
{
struct V_3 * V_4 = F_90 ( V_92 ) ;
F_6 ( 0 , F_9 ( V_4 ) ) ;
F_6 ( 0 , F_5 ( V_4 ) ) ;
F_6 ( 0xffffffff , F_26 ( V_4 ) ) ;
F_6 ( 0 , F_54 ( V_4 ) ) ;
F_7 () ;
return 0 ;
}
static int F_93 ( struct V_170 * V_92 )
{
struct V_3 * V_4 = F_90 ( V_92 ) ;
F_53 ( V_4 ) ;
return 0 ;
}
static int T_6 F_94 ( void )
{
if ( F_1 () ) {
V_163 = F_95 ( & V_212 ) ;
if ( ! V_163 )
F_96 ( L_21 ) ;
}
return F_97 ( & V_213 ) ;
}
static void T_7 F_98 ( void )
{
if ( F_1 () && V_163 )
F_99 ( V_163 ) ;
F_100 ( & V_213 ) ;
}
