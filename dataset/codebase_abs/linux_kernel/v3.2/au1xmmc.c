static inline int F_1 ( void )
{
switch ( F_2 () ) {
case V_1 :
return 1 ;
default:
return 0 ;
}
}
static inline void F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
T_1 V_5 = F_4 ( F_5 ( V_3 ) ) ;
V_5 |= V_4 ;
F_6 ( V_5 , F_5 ( V_3 ) ) ;
F_7 () ;
}
static inline void F_8 ( struct V_2 * V_3 )
{
T_1 V_5 = F_4 ( F_9 ( V_3 ) ) ;
F_6 ( V_5 | V_6 , F_9 ( V_3 ) ) ;
F_10 ( 1 ) ;
V_5 &= ~ V_7 ;
F_6 ( V_5 , F_9 ( V_3 ) ) ;
F_7 () ;
}
static inline void F_11 ( struct V_2 * V_3 , T_1 V_4 )
{
T_1 V_5 = F_4 ( F_5 ( V_3 ) ) ;
V_5 &= ~ V_4 ;
F_6 ( V_5 , F_5 ( V_3 ) ) ;
F_7 () ;
}
static inline void F_12 ( struct V_2 * V_3 )
{
T_1 V_8 ;
F_13 ( V_3 -> V_9 != V_10 ) ;
V_3 -> V_9 = V_11 ;
V_8 = F_4 ( F_9 ( V_3 ) ) ;
F_6 ( V_8 | V_7 , F_9 ( V_3 ) ) ;
F_7 () ;
F_6 ( V_12 , F_14 ( V_3 ) ) ;
}
static void F_15 ( struct V_2 * V_3 , int V_13 )
{
if ( V_3 -> V_14 && V_3 -> V_14 -> V_15 )
V_3 -> V_14 -> V_15 ( V_3 -> V_16 , V_13 ) ;
}
static int F_16 ( struct V_17 * V_16 )
{
struct V_2 * V_3 = F_17 ( V_16 ) ;
if ( V_3 -> V_14 && V_3 -> V_14 -> V_18 )
return ! ! V_3 -> V_14 -> V_18 ( V_3 -> V_16 ) ;
return - V_19 ;
}
static int F_18 ( struct V_17 * V_16 )
{
struct V_2 * V_3 = F_17 ( V_16 ) ;
if ( V_3 -> V_14 && V_3 -> V_14 -> V_20 )
return ! ! V_3 -> V_14 -> V_20 ( V_16 ) ;
return - V_19 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_21 * V_22 = V_3 -> V_22 ;
V_3 -> V_22 = NULL ;
V_3 -> V_23 &= V_24 | V_25 ;
V_3 -> V_26 . V_27 = 0 ;
V_3 -> V_26 . V_28 = 0 ;
V_3 -> V_29 . V_30 = 0 ;
V_3 -> V_29 . V_31 = 0 ;
V_3 -> V_29 . V_27 = 0 ;
V_3 -> V_9 = V_32 ;
F_20 ( V_3 -> V_16 , V_22 ) ;
}
static void F_21 ( unsigned long V_33 )
{
struct V_2 * V_3 = (struct V_2 * ) V_33 ;
F_19 ( V_3 ) ;
}
static int F_22 ( struct V_2 * V_3 , int V_34 ,
struct V_35 * V_36 , struct V_37 * V_38 )
{
T_1 V_39 = ( V_36 -> V_40 << V_41 ) ;
switch ( F_23 ( V_36 ) ) {
case V_42 :
break;
case V_43 :
V_39 |= V_44 ;
break;
case V_45 :
V_39 |= V_46 ;
break;
case V_47 :
V_39 |= V_48 ;
break;
case V_49 :
V_39 |= V_50 ;
break;
default:
F_24 ( L_1 ,
F_23 ( V_36 ) ) ;
return - V_51 ;
}
if ( V_38 ) {
if ( V_38 -> V_23 & V_52 ) {
if ( V_38 -> V_53 > 1 )
V_39 |= V_54 ;
else
V_39 |= V_55 ;
} else if ( V_38 -> V_23 & V_56 ) {
if ( V_38 -> V_53 > 1 )
V_39 |= V_57 ;
else
V_39 |= V_58 ;
}
}
F_6 ( V_36 -> V_59 , F_25 ( V_3 ) ) ;
F_7 () ;
if ( V_34 )
F_11 ( V_3 , V_60 ) ;
F_6 ( ( V_39 | V_61 ) , F_14 ( V_3 ) ) ;
F_7 () ;
while ( F_4 ( F_14 ( V_3 ) ) & V_61 )
;
if ( V_34 ) {
T_1 V_9 = F_4 ( F_26 ( V_3 ) ) ;
while ( ! ( V_9 & V_62 ) )
V_9 = F_4 ( F_26 ( V_3 ) ) ;
F_6 ( V_62 , F_26 ( V_3 ) ) ;
F_3 ( V_3 , V_60 ) ;
}
return 0 ;
}
static void F_27 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_21 * V_22 = V_3 -> V_22 ;
struct V_37 * V_38 ;
T_1 V_63 ;
F_13 ( ( V_3 -> V_9 != V_10 ) && ( V_3 -> V_9 != V_11 ) ) ;
if ( V_3 -> V_22 == NULL )
return;
V_38 = V_22 -> V_36 -> V_38 ;
if ( V_9 == 0 )
V_9 = F_4 ( F_26 ( V_3 ) ) ;
while ( ( V_3 -> V_23 & V_64 ) && ( V_9 & V_65 ) )
V_9 = F_4 ( F_26 ( V_3 ) ) ;
V_38 -> error = 0 ;
F_28 ( F_29 ( V_3 -> V_16 ) , V_38 -> V_66 , V_38 -> V_67 , V_3 -> V_26 . V_28 ) ;
V_63 = ( V_9 & ( V_68 | V_69 ) ) ;
if ( V_3 -> V_23 & V_64 )
V_63 |= ( ( V_9 & 0x07 ) == 0x02 ) ? 0 : 1 ;
if ( V_63 )
V_38 -> error = - V_70 ;
F_6 ( V_68 | V_69 , F_26 ( V_3 ) ) ;
V_38 -> V_71 = 0 ;
if ( ! V_38 -> error ) {
if ( V_3 -> V_23 & ( V_25 | V_72 ) ) {
T_1 V_73 = F_30 ( V_3 ) ;
T_2 * V_74 = * ( ( T_2 * * ) V_73 ) ;
T_3 * V_75 = V_74 -> V_76 ;
V_38 -> V_71 = V_75 -> V_77 ;
} else
V_38 -> V_71 =
( V_38 -> V_53 * V_38 -> V_78 ) - V_3 -> V_29 . V_27 ;
}
F_19 ( V_3 ) ;
}
static void F_31 ( unsigned long V_33 )
{
struct V_2 * V_3 = (struct V_2 * ) V_33 ;
T_1 V_9 = F_4 ( F_26 ( V_3 ) ) ;
F_27 ( V_3 , V_9 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_37 * V_38 ;
int V_67 , V_79 , V_80 ;
unsigned char * V_81 , V_5 ;
T_1 V_9 ;
struct V_82 * V_66 ;
V_38 = V_3 -> V_22 -> V_38 ;
if ( ! ( V_3 -> V_23 & V_64 ) )
return;
V_66 = & V_38 -> V_66 [ V_3 -> V_29 . V_30 ] ;
V_81 = F_33 ( V_66 ) + V_3 -> V_29 . V_31 ;
V_67 = V_38 -> V_66 [ V_3 -> V_29 . V_30 ] . V_83 - V_3 -> V_29 . V_31 ;
V_79 = ( V_67 > V_3 -> V_29 . V_27 ) ? V_3 -> V_29 . V_27 : V_67 ;
if ( V_79 > V_84 )
V_79 = V_84 ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_9 = F_4 ( F_26 ( V_3 ) ) ;
if ( ! ( V_9 & V_85 ) )
break;
V_5 = * V_81 ++ ;
F_6 ( ( unsigned long ) V_5 , F_34 ( V_3 ) ) ;
F_7 () ;
}
V_3 -> V_29 . V_27 -= V_80 ;
V_3 -> V_29 . V_31 += V_80 ;
if ( V_80 == V_67 ) {
V_3 -> V_29 . V_30 ++ ;
V_3 -> V_29 . V_31 = 0 ;
}
if ( V_3 -> V_29 . V_27 == 0 ) {
F_11 ( V_3 , V_86 ) ;
if ( V_3 -> V_23 & V_87 )
F_12 ( V_3 ) ;
F_35 ( & V_3 -> V_88 ) ;
}
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_37 * V_38 ;
int V_79 , V_80 , V_67 = 0 ;
unsigned char * V_81 = NULL ;
T_1 V_9 , V_5 ;
struct V_82 * V_66 ;
V_38 = V_3 -> V_22 -> V_38 ;
if ( ! ( V_3 -> V_23 & V_89 ) )
return;
V_79 = V_3 -> V_29 . V_27 ;
if ( V_3 -> V_29 . V_30 < V_3 -> V_26 . V_27 ) {
V_66 = & V_38 -> V_66 [ V_3 -> V_29 . V_30 ] ;
V_81 = F_33 ( V_66 ) + V_3 -> V_29 . V_31 ;
V_67 = F_37 ( & V_38 -> V_66 [ V_3 -> V_29 . V_30 ] ) - V_3 -> V_29 . V_31 ;
if ( V_67 < V_79 )
V_79 = V_67 ;
}
if ( V_79 > V_84 )
V_79 = V_84 ;
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ ) {
V_9 = F_4 ( F_26 ( V_3 ) ) ;
if ( ! ( V_9 & V_90 ) )
break;
if ( V_9 & V_69 ) {
F_38 ( L_2 , V_3 -> V_91 -> V_92 ,
V_3 -> V_29 . V_27 , V_80 ) ;
break;
}
if ( V_9 & V_93 ) {
F_38 ( L_3 , V_3 -> V_91 -> V_92 ,
V_3 -> V_29 . V_27 , V_80 ) ;
break;
}
else if ( V_9 & V_94 ) {
F_38 ( L_4 , V_3 -> V_91 -> V_92 ,
V_3 -> V_29 . V_27 , V_80 ) ;
break;
}
V_5 = F_4 ( F_39 ( V_3 ) ) ;
if ( V_81 )
* V_81 ++ = ( unsigned char ) ( V_5 & 0xFF ) ;
}
V_3 -> V_29 . V_27 -= V_80 ;
V_3 -> V_29 . V_31 += V_80 ;
if ( V_67 && V_80 == V_67 ) {
V_3 -> V_29 . V_30 ++ ;
V_3 -> V_29 . V_31 = 0 ;
}
if ( V_3 -> V_29 . V_27 == 0 ) {
F_11 ( V_3 , V_95 ) ;
if ( V_3 -> V_23 & V_87 )
F_12 ( V_3 ) ;
F_35 ( & V_3 -> V_88 ) ;
}
}
static void F_40 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_21 * V_22 = V_3 -> V_22 ;
struct V_35 * V_36 ;
T_1 V_96 [ 4 ] ;
int V_97 , V_98 ;
if ( ! V_3 -> V_22 )
return;
V_36 = V_22 -> V_36 ;
V_36 -> error = 0 ;
if ( V_36 -> V_23 & V_99 ) {
if ( V_36 -> V_23 & V_100 ) {
V_96 [ 0 ] = F_4 ( V_3 -> V_101 + V_102 ) ;
V_96 [ 1 ] = F_4 ( V_3 -> V_101 + V_103 ) ;
V_96 [ 2 ] = F_4 ( V_3 -> V_101 + V_104 ) ;
V_96 [ 3 ] = F_4 ( V_3 -> V_101 + V_105 ) ;
for ( V_97 = 0 ; V_97 < 4 ; V_97 ++ ) {
V_36 -> V_106 [ V_97 ] = ( V_96 [ V_97 ] & 0x00FFFFFF ) << 8 ;
if ( V_97 != 3 )
V_36 -> V_106 [ V_97 ] |= ( V_96 [ V_97 + 1 ] & 0xFF000000 ) >> 24 ;
}
} else {
V_36 -> V_106 [ 0 ] = F_4 ( V_3 -> V_101 + V_105 ) ;
}
}
if ( V_9 & ( V_107 | V_68 | V_69 ) )
V_36 -> error = - V_70 ;
V_98 = V_3 -> V_23 & ( V_64 | V_89 ) ;
if ( ! V_98 || V_36 -> error ) {
F_11 ( V_3 , V_86 | V_108 | V_109 ) ;
F_35 ( & V_3 -> V_110 ) ;
return;
}
V_3 -> V_9 = V_10 ;
if ( ( V_3 -> V_23 & ( V_25 | V_72 ) ) ) {
T_1 V_111 = F_30 ( V_3 ) ;
if ( V_3 -> V_23 & V_89 ) {
T_1 V_4 = V_65 | V_90 ;
while( ( V_9 & V_4 ) != V_4 )
V_9 = F_4 ( F_26 ( V_3 ) ) ;
}
F_41 ( V_111 ) ;
}
}
static void F_42 ( struct V_2 * V_3 , int V_112 )
{
unsigned int V_113 = F_43 () ;
unsigned int V_114 ;
T_1 V_115 ;
V_113 /= ( ( F_4 ( V_116 ) & 0x3 ) + 2 ) ;
V_113 /= 2 ;
V_114 = ( ( V_113 / V_112 ) / 2 ) - 1 ;
V_115 = F_4 ( F_5 ( V_3 ) ) ;
V_115 &= ~ ( V_117 ) ;
V_115 |= ( V_114 & V_117 ) | V_118 ;
F_6 ( V_115 , F_5 ( V_3 ) ) ;
F_7 () ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
int V_119 = V_38 -> V_53 * V_38 -> V_78 ;
if ( V_38 -> V_23 & V_52 )
V_3 -> V_23 |= V_89 ;
else
V_3 -> V_23 |= V_64 ;
if ( V_3 -> V_22 -> V_120 )
V_3 -> V_23 |= V_87 ;
V_3 -> V_26 . V_28 = V_121 ;
V_3 -> V_26 . V_27 = F_45 ( F_29 ( V_3 -> V_16 ) , V_38 -> V_66 ,
V_38 -> V_67 , V_3 -> V_26 . V_28 ) ;
if ( V_3 -> V_26 . V_27 == 0 )
return - V_122 ;
F_6 ( V_38 -> V_78 - 1 , F_46 ( V_3 ) ) ;
if ( V_3 -> V_23 & ( V_25 | V_72 ) ) {
int V_97 ;
T_1 V_111 = F_30 ( V_3 ) ;
F_47 ( V_111 ) ;
for ( V_97 = 0 ; V_97 < V_3 -> V_26 . V_27 ; V_97 ++ ) {
T_1 V_123 = 0 , V_23 = V_124 ;
struct V_82 * V_66 = & V_38 -> V_66 [ V_97 ] ;
int V_67 = V_66 -> V_83 ;
int V_27 = ( V_119 > V_67 ) ? V_67 : V_119 ;
if ( V_97 == V_3 -> V_26 . V_27 - 1 )
V_23 = V_125 ;
if ( V_3 -> V_23 & V_64 ) {
V_123 = F_48 ( V_111 ,
F_49 ( V_66 ) , V_27 , V_23 ) ;
} else {
V_123 = F_50 ( V_111 ,
F_49 ( V_66 ) , V_27 , V_23 ) ;
}
if ( ! V_123 )
goto V_126;
V_119 -= V_27 ;
}
} else {
V_3 -> V_29 . V_30 = 0 ;
V_3 -> V_29 . V_31 = 0 ;
V_3 -> V_29 . V_27 = V_119 ;
if ( V_3 -> V_23 & V_64 )
F_3 ( V_3 , V_86 ) ;
else
F_3 ( V_3 , V_95 ) ;
}
return 0 ;
V_126:
F_28 ( F_29 ( V_3 -> V_16 ) , V_38 -> V_66 , V_38 -> V_67 ,
V_3 -> V_26 . V_28 ) ;
return - V_122 ;
}
static void F_51 ( struct V_17 * V_16 , struct V_21 * V_22 )
{
struct V_2 * V_3 = F_17 ( V_16 ) ;
int V_123 = 0 ;
F_13 ( F_52 () ) ;
F_13 ( V_3 -> V_9 != V_32 ) ;
V_3 -> V_22 = V_22 ;
V_3 -> V_9 = V_127 ;
if ( 0 == F_16 ( V_16 ) ) {
V_22 -> V_36 -> error = - V_128 ;
F_19 ( V_3 ) ;
return;
}
if ( V_22 -> V_38 ) {
F_8 ( V_3 ) ;
V_123 = F_44 ( V_3 , V_22 -> V_38 ) ;
}
if ( ! V_123 )
V_123 = F_22 ( V_3 , 0 , V_22 -> V_36 , V_22 -> V_38 ) ;
if ( V_123 ) {
V_22 -> V_36 -> error = V_123 ;
F_19 ( V_3 ) ;
}
}
static void F_53 ( struct V_2 * V_3 )
{
F_6 ( V_129 , F_54 ( V_3 ) ) ;
F_10 ( 1 ) ;
F_6 ( V_130 | V_129 , F_54 ( V_3 ) ) ;
F_10 ( 5 ) ;
F_6 ( ~ 0 , F_26 ( V_3 ) ) ;
F_7 () ;
F_6 ( 0 , F_46 ( V_3 ) ) ;
F_6 ( 0x001fffff , F_55 ( V_3 ) ) ;
F_7 () ;
F_6 ( V_131 , F_9 ( V_3 ) ) ;
F_7 () ;
F_6 ( V_131 | V_6 , F_9 ( V_3 ) ) ;
F_10 ( 1 ) ;
F_6 ( V_131 , F_9 ( V_3 ) ) ;
F_7 () ;
F_6 ( V_132 , F_5 ( V_3 ) ) ;
F_7 () ;
}
static void F_56 ( struct V_17 * V_16 , struct V_133 * V_134 )
{
struct V_2 * V_3 = F_17 ( V_16 ) ;
T_1 V_8 ;
if ( V_134 -> V_135 == V_136 )
F_15 ( V_3 , 0 ) ;
else if ( V_134 -> V_135 == V_137 ) {
F_15 ( V_3 , 1 ) ;
}
if ( V_134 -> clock && V_134 -> clock != V_3 -> clock ) {
F_42 ( V_3 , V_134 -> clock ) ;
V_3 -> clock = V_134 -> clock ;
}
V_8 = F_4 ( F_9 ( V_3 ) ) ;
switch ( V_134 -> V_138 ) {
case V_139 :
V_8 |= V_140 ;
break;
case V_141 :
V_8 &= ~ V_140 ;
break;
}
F_6 ( V_8 , F_9 ( V_3 ) ) ;
F_7 () ;
}
static T_4 F_57 ( int V_142 , void * V_143 )
{
struct V_2 * V_3 = V_143 ;
T_1 V_9 ;
V_9 = F_4 ( F_26 ( V_3 ) ) ;
if ( ! ( V_9 & V_144 ) )
return V_145 ;
if ( V_9 & V_146 )
F_58 ( V_3 -> V_16 ) ;
if ( V_3 -> V_22 && ( V_9 & V_147 ) ) {
if ( V_9 & V_148 )
V_3 -> V_22 -> V_36 -> error = - V_122 ;
else if ( V_9 & V_149 )
V_3 -> V_22 -> V_38 -> error = - V_122 ;
F_11 ( V_3 , V_95 | V_86 ) ;
F_35 ( & V_3 -> V_110 ) ;
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
else if ( V_9 & V_62 ) {
if ( V_3 -> V_9 == V_127 )
F_40 ( V_3 , V_9 ) ;
} else if ( ! ( V_3 -> V_23 & V_25 ) ) {
if ( ( V_3 -> V_23 & V_64 ) && ( V_9 & V_150 ) )
F_32 ( V_3 ) ;
else if ( ( V_3 -> V_23 & V_89 ) && ( V_9 & V_151 ) )
F_36 ( V_3 ) ;
} else if ( V_9 & 0x203F3C70 ) {
F_38 ( L_5 , V_3 -> V_91 -> V_92 ,
V_9 ) ;
}
F_6 ( V_9 , F_26 ( V_3 ) ) ;
F_7 () ;
return V_152 ;
}
static void F_59 ( int V_142 , void * V_143 )
{
struct V_2 * V_3 = (struct V_2 * ) V_143 ;
if ( ! V_3 -> V_22 )
return;
if ( V_3 -> V_23 & V_87 )
F_12 ( V_3 ) ;
F_35 ( & V_3 -> V_88 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_153 * V_154 ;
int V_155 , V_156 ;
V_154 = F_61 ( V_3 -> V_91 , V_157 , 0 ) ;
if ( ! V_154 )
return - V_158 ;
V_155 = V_154 -> V_159 ;
V_154 = F_61 ( V_3 -> V_91 , V_157 , 1 ) ;
if ( ! V_154 )
return - V_158 ;
V_156 = V_154 -> V_159 ;
if ( ! V_160 )
return - V_158 ;
V_3 -> V_161 = F_62 ( V_160 , V_155 ,
F_59 , ( void * ) V_3 ) ;
if ( ! V_3 -> V_161 ) {
F_63 ( & V_3 -> V_91 -> V_162 , L_6 ) ;
return - V_158 ;
}
V_3 -> V_163 = F_62 ( V_156 , V_160 ,
F_59 , ( void * ) V_3 ) ;
if ( ! V_3 -> V_163 ) {
F_63 ( & V_3 -> V_91 -> V_162 , L_7 ) ;
F_64 ( V_3 -> V_161 ) ;
return - V_158 ;
}
F_65 ( V_3 -> V_161 , 8 ) ;
F_65 ( V_3 -> V_163 , 8 ) ;
F_66 ( V_3 -> V_161 , V_164 ) ;
F_66 ( V_3 -> V_163 , V_164 ) ;
V_3 -> V_23 |= V_25 | V_72 ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
if ( V_3 -> V_23 & V_25 ) {
V_3 -> V_23 &= ~ V_25 ;
F_64 ( V_3 -> V_161 ) ;
F_64 ( V_3 -> V_163 ) ;
}
}
static void F_68 ( struct V_17 * V_16 , int V_165 )
{
struct V_2 * V_3 = F_17 ( V_16 ) ;
if ( V_165 )
F_3 ( V_3 , V_166 ) ;
else
F_11 ( V_3 , V_166 ) ;
}
static int T_5 F_69 ( struct V_167 * V_91 )
{
struct V_17 * V_16 ;
struct V_2 * V_3 ;
struct V_153 * V_96 ;
int V_123 ;
V_16 = F_70 ( sizeof( struct V_2 ) , & V_91 -> V_162 ) ;
if ( ! V_16 ) {
F_63 ( & V_91 -> V_162 , L_8 ) ;
V_123 = - V_168 ;
goto V_169;
}
V_3 = F_17 ( V_16 ) ;
V_3 -> V_16 = V_16 ;
V_3 -> V_14 = V_91 -> V_162 . V_170 ;
V_3 -> V_91 = V_91 ;
V_123 = - V_158 ;
V_96 = F_61 ( V_91 , V_171 , 0 ) ;
if ( ! V_96 ) {
F_63 ( & V_91 -> V_162 , L_9 ) ;
goto V_172;
}
V_3 -> V_173 = F_71 ( V_96 -> V_159 , F_72 ( V_96 ) ,
V_91 -> V_174 ) ;
if ( ! V_3 -> V_173 ) {
F_63 ( & V_91 -> V_162 , L_10 ) ;
goto V_172;
}
V_3 -> V_101 = ( unsigned long ) F_73 ( V_96 -> V_159 , 0x3c ) ;
if ( ! V_3 -> V_101 ) {
F_63 ( & V_91 -> V_162 , L_11 ) ;
goto V_175;
}
V_96 = F_61 ( V_91 , V_176 , 0 ) ;
if ( ! V_96 ) {
F_63 ( & V_91 -> V_162 , L_12 ) ;
goto V_177;
}
V_3 -> V_142 = V_96 -> V_159 ;
V_123 = F_74 ( V_3 -> V_142 , F_57 , V_178 ,
V_179 , V_3 ) ;
if ( V_123 ) {
F_63 ( & V_91 -> V_162 , L_13 ) ;
goto V_177;
}
V_16 -> V_180 = & V_181 ;
V_16 -> V_182 = 450000 ;
V_16 -> V_183 = 24000000 ;
switch ( F_2 () ) {
case V_184 :
V_16 -> V_185 = V_186 ;
V_16 -> V_187 = V_164 ;
break;
case V_1 :
V_16 -> V_185 = V_188 ;
V_16 -> V_187 = V_164 ;
break;
}
V_16 -> V_189 = 2048 ;
V_16 -> V_190 = 512 ;
V_16 -> V_191 = V_192 ;
V_16 -> V_193 = V_194 | V_195 ;
V_3 -> V_9 = V_32 ;
if ( V_3 -> V_14 && V_3 -> V_14 -> V_196 ) {
V_123 = V_3 -> V_14 -> V_196 ( V_16 , 1 ) ;
if ( V_123 ) {
F_75 ( & V_91 -> V_162 , L_14 ) ;
V_16 -> V_193 |= V_197 ;
}
} else
V_16 -> V_193 |= V_197 ;
if ( V_3 -> V_14 )
V_16 -> V_193 &= ~ ( V_3 -> V_14 -> V_198 ) ;
F_76 ( & V_3 -> V_88 , F_31 ,
( unsigned long ) V_3 ) ;
F_76 ( & V_3 -> V_110 , F_21 ,
( unsigned long ) V_3 ) ;
if ( F_1 () ) {
V_123 = F_60 ( V_3 ) ;
if ( V_123 )
F_24 ( V_179 L_15 ) ;
}
#ifdef F_77
if ( V_3 -> V_14 && V_3 -> V_14 -> V_199 ) {
struct V_200 * V_199 = V_3 -> V_14 -> V_199 ;
V_199 -> V_174 = F_78 ( V_16 ) ;
V_199 -> V_201 = V_202 ;
V_199 -> V_203 = F_78 ( V_16 ) ;
V_123 = F_79 ( F_29 ( V_16 ) , V_199 ) ;
if ( V_123 )
goto V_204;
}
#endif
F_53 ( V_3 ) ;
V_123 = F_80 ( V_16 ) ;
if ( V_123 ) {
F_63 ( & V_91 -> V_162 , L_16 ) ;
goto V_205;
}
F_81 ( V_91 , V_3 ) ;
F_24 ( V_179 L_17
L_18 , V_91 -> V_92 , V_3 -> V_101 ,
V_3 -> V_23 & V_25 ? L_19 : L_20 ) ;
return 0 ;
V_205:
#ifdef F_77
if ( V_3 -> V_14 && V_3 -> V_14 -> V_199 )
F_82 ( V_3 -> V_14 -> V_199 ) ;
V_204:
#endif
F_6 ( 0 , F_54 ( V_3 ) ) ;
F_6 ( 0 , F_5 ( V_3 ) ) ;
F_6 ( 0 , F_9 ( V_3 ) ) ;
F_7 () ;
if ( V_3 -> V_23 & V_72 )
F_67 ( V_3 ) ;
F_83 ( & V_3 -> V_88 ) ;
F_83 ( & V_3 -> V_110 ) ;
if ( V_3 -> V_14 && V_3 -> V_14 -> V_196 &&
! ( V_16 -> V_193 & V_197 ) )
V_3 -> V_14 -> V_196 ( V_16 , 0 ) ;
F_84 ( V_3 -> V_142 , V_3 ) ;
V_177:
F_85 ( ( void * ) V_3 -> V_101 ) ;
V_175:
F_86 ( V_3 -> V_173 ) ;
F_87 ( V_3 -> V_173 ) ;
V_172:
F_88 ( V_16 ) ;
V_169:
return V_123 ;
}
static int T_6 F_89 ( struct V_167 * V_91 )
{
struct V_2 * V_3 = F_90 ( V_91 ) ;
if ( V_3 ) {
F_91 ( V_3 -> V_16 ) ;
#ifdef F_77
if ( V_3 -> V_14 && V_3 -> V_14 -> V_199 )
F_82 ( V_3 -> V_14 -> V_199 ) ;
#endif
if ( V_3 -> V_14 && V_3 -> V_14 -> V_196 &&
! ( V_3 -> V_16 -> V_193 & V_197 ) )
V_3 -> V_14 -> V_196 ( V_3 -> V_16 , 0 ) ;
F_6 ( 0 , F_54 ( V_3 ) ) ;
F_6 ( 0 , F_5 ( V_3 ) ) ;
F_6 ( 0 , F_9 ( V_3 ) ) ;
F_7 () ;
F_83 ( & V_3 -> V_88 ) ;
F_83 ( & V_3 -> V_110 ) ;
if ( V_3 -> V_23 & V_72 )
F_67 ( V_3 ) ;
F_15 ( V_3 , 0 ) ;
F_84 ( V_3 -> V_142 , V_3 ) ;
F_85 ( ( void * ) V_3 -> V_101 ) ;
F_86 ( V_3 -> V_173 ) ;
F_87 ( V_3 -> V_173 ) ;
F_88 ( V_3 -> V_16 ) ;
F_81 ( V_91 , NULL ) ;
}
return 0 ;
}
static int F_92 ( struct V_167 * V_91 , T_7 V_13 )
{
struct V_2 * V_3 = F_90 ( V_91 ) ;
int V_123 ;
V_123 = F_93 ( V_3 -> V_16 ) ;
if ( V_123 )
return V_123 ;
F_6 ( 0 , F_9 ( V_3 ) ) ;
F_6 ( 0 , F_5 ( V_3 ) ) ;
F_6 ( 0xffffffff , F_26 ( V_3 ) ) ;
F_6 ( 0 , F_54 ( V_3 ) ) ;
F_7 () ;
return 0 ;
}
static int F_94 ( struct V_167 * V_91 )
{
struct V_2 * V_3 = F_90 ( V_91 ) ;
F_53 ( V_3 ) ;
return F_95 ( V_3 -> V_16 ) ;
}
static int T_8 F_96 ( void )
{
if ( F_1 () ) {
V_160 = F_97 ( & V_206 ) ;
if ( ! V_160 )
F_98 ( L_21 ) ;
}
return F_99 ( & V_207 ) ;
}
static void T_9 F_100 ( void )
{
if ( F_1 () && V_160 )
F_101 ( V_160 ) ;
F_102 ( & V_207 ) ;
}
