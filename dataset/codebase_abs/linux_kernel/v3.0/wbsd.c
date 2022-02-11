static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 == 0 ) ;
F_3 ( V_2 -> V_4 , V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 , V_2 -> V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 == 0 ) ;
F_3 ( V_5 , V_2 -> V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 )
{
F_2 ( V_2 -> V_3 == 0 ) ;
F_3 ( V_6 , V_2 -> V_3 ) ;
F_3 ( V_7 , V_2 -> V_3 + 1 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_6 )
{
F_2 ( V_2 -> V_3 == 0 ) ;
F_3 ( V_6 , V_2 -> V_3 ) ;
return F_7 ( V_2 -> V_3 + 1 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_7 )
{
F_3 ( V_8 , V_2 -> V_9 + V_10 ) ;
F_3 ( V_7 , V_2 -> V_9 + V_11 ) ;
}
static inline T_1 F_9 ( struct V_1 * V_2 , T_1 V_8 )
{
F_3 ( V_8 , V_2 -> V_9 + V_10 ) ;
return F_7 ( V_2 -> V_9 + V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_12 , V_13 ;
V_12 = F_9 ( V_2 , V_14 ) ;
V_12 |= V_15 | V_16 ;
F_8 ( V_2 , V_14 , V_12 ) ;
V_12 &= ~ V_17 ;
F_8 ( V_2 , V_14 , V_12 ) ;
V_2 -> V_18 &= ~ V_19 ;
V_2 -> V_20 = F_9 ( V_2 , V_21 ) ;
F_3 ( V_22 , V_2 -> V_9 + V_23 ) ;
F_8 ( V_2 , V_24 , 0x7F ) ;
if ( F_7 ( V_2 -> V_9 + V_23 ) & V_25 )
V_2 -> V_18 |= V_26 ;
else
V_2 -> V_18 &= ~ V_26 ;
V_13 = 0 ;
V_13 |= V_27 ;
V_13 |= V_28 ;
V_13 |= V_29 ;
V_13 |= V_30 ;
V_13 |= V_31 ;
F_3 ( V_13 , V_2 -> V_9 + V_32 ) ;
F_7 ( V_2 -> V_9 + V_33 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_12 ;
F_12 ( V_34 L_1 , F_13 ( V_2 -> V_35 ) ) ;
V_12 = F_9 ( V_2 , V_14 ) ;
V_12 |= V_16 ;
F_8 ( V_2 , V_14 , V_12 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
unsigned long V_38 ;
if ( V_2 -> V_39 >= 0 ) {
V_38 = F_15 () ;
F_16 ( V_2 -> V_39 ) ;
F_17 ( V_2 -> V_39 ) ;
F_18 ( V_38 ) ;
F_8 ( V_2 , V_40 , 0 ) ;
}
V_2 -> V_37 = NULL ;
F_19 ( & V_2 -> V_41 ) ;
F_20 ( V_2 -> V_35 , V_37 ) ;
F_21 ( & V_2 -> V_41 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
V_2 -> V_44 = V_43 -> V_45 ;
V_2 -> V_46 = V_43 -> V_47 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = V_2 -> V_44 -> V_50 ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
V_2 -> V_44 ++ ;
V_2 -> V_46 -- ;
if ( V_2 -> V_46 > 0 ) {
V_2 -> V_48 = 0 ;
V_2 -> V_49 = V_2 -> V_44 -> V_50 ;
}
return V_2 -> V_46 ;
}
static inline char * F_24 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_44 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned int V_51 , V_52 ;
struct V_53 * V_45 ;
char * V_54 = V_2 -> V_55 ;
char * V_56 ;
V_45 = V_43 -> V_45 ;
V_51 = V_43 -> V_47 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
V_56 = F_25 ( & V_45 [ V_52 ] ) ;
memcpy ( V_54 , V_56 , V_45 [ V_52 ] . V_50 ) ;
V_54 += V_45 [ V_52 ] . V_50 ;
}
}
static inline void F_27 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned int V_51 , V_52 ;
struct V_53 * V_45 ;
char * V_54 = V_2 -> V_55 ;
char * V_56 ;
V_45 = V_43 -> V_45 ;
V_51 = V_43 -> V_47 ;
for ( V_52 = 0 ; V_52 < V_51 ; V_52 ++ ) {
V_56 = F_25 ( & V_45 [ V_52 ] ) ;
memcpy ( V_56 , V_54 , V_45 [ V_52 ] . V_50 ) ;
V_54 += V_45 [ V_52 ] . V_50 ;
}
}
static inline void F_28 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
if ( F_9 ( V_2 , V_59 ) != V_60 ) {
V_58 -> error = - V_61 ;
return;
}
V_58 -> V_62 [ 0 ] = F_9 ( V_2 , V_63 ) << 24 ;
V_58 -> V_62 [ 0 ] |= F_9 ( V_2 , V_64 ) << 16 ;
V_58 -> V_62 [ 0 ] |= F_9 ( V_2 , V_65 ) << 8 ;
V_58 -> V_62 [ 0 ] |= F_9 ( V_2 , V_66 ) << 0 ;
V_58 -> V_62 [ 1 ] = F_9 ( V_2 , V_67 ) << 24 ;
}
static inline void F_29 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
int V_52 ;
if ( F_9 ( V_2 , V_59 ) != V_68 ) {
V_58 -> error = - V_61 ;
return;
}
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
V_58 -> V_62 [ V_52 ] =
F_9 ( V_2 , V_69 + V_52 * 4 ) << 24 ;
V_58 -> V_62 [ V_52 ] |=
F_9 ( V_2 , V_70 + V_52 * 4 ) << 16 ;
V_58 -> V_62 [ V_52 ] |=
F_9 ( V_2 , V_71 + V_52 * 4 ) << 8 ;
V_58 -> V_62 [ V_52 ] |=
F_9 ( V_2 , V_72 + V_52 * 4 ) << 0 ;
}
}
static void F_30 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
int V_52 ;
T_1 V_73 , V_74 ;
V_2 -> V_74 = 0 ;
F_3 ( V_58 -> V_75 , V_2 -> V_9 + V_76 ) ;
for ( V_52 = 3 ; V_52 >= 0 ; V_52 -- )
F_3 ( ( V_58 -> V_77 >> ( V_52 * 8 ) ) & 0xff , V_2 -> V_9 + V_76 ) ;
V_58 -> error = 0 ;
do {
V_73 = F_9 ( V_2 , V_78 ) ;
} while ( V_73 & V_79 );
if ( V_58 -> V_18 & V_80 ) {
V_74 = V_2 -> V_74 ;
if ( V_74 & V_81 )
V_58 -> error = - V_82 ;
else if ( V_74 & V_83 )
V_58 -> error = - V_84 ;
else if ( ( V_58 -> V_18 & V_85 ) && ( V_74 & V_86 ) )
V_58 -> error = - V_61 ;
else {
if ( V_58 -> V_18 & V_87 )
F_29 ( V_2 , V_58 ) ;
else
F_28 ( V_2 , V_58 ) ;
}
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_37 -> V_58 -> V_43 ;
char * V_88 ;
int V_52 , V_89 , V_90 ;
if ( V_2 -> V_46 == 0 )
return;
V_88 = F_24 ( V_2 ) + V_2 -> V_48 ;
while ( ! ( ( V_89 = F_7 ( V_2 -> V_9 + V_91 ) ) & V_92 ) ) {
if ( V_89 & V_93 )
V_90 = 16 ;
else if ( V_89 & V_94 )
V_90 = 8 ;
else
V_90 = 1 ;
for ( V_52 = 0 ; V_52 < V_90 ; V_52 ++ ) {
* V_88 = F_7 ( V_2 -> V_9 + V_95 ) ;
V_88 ++ ;
V_2 -> V_48 ++ ;
V_2 -> V_49 -- ;
V_43 -> V_96 ++ ;
if ( V_2 -> V_49 == 0 ) {
if ( ! F_23 ( V_2 ) )
return;
V_88 = F_24 ( V_2 ) ;
}
}
}
if ( ( V_43 -> V_97 * V_43 -> V_98 - V_43 -> V_96 ) < 16 )
F_32 ( & V_2 -> V_99 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = V_2 -> V_37 -> V_58 -> V_43 ;
char * V_88 ;
int V_52 , V_89 , V_90 ;
if ( V_2 -> V_46 == 0 )
return;
V_88 = F_24 ( V_2 ) + V_2 -> V_48 ;
while ( ! ( ( V_89 = F_7 ( V_2 -> V_9 + V_91 ) ) & V_93 ) ) {
if ( V_89 & V_92 )
V_90 = 0 ;
else if ( V_89 & V_100 )
V_90 = 8 ;
else
V_90 = 15 ;
for ( V_52 = 16 ; V_52 > V_90 ; V_52 -- ) {
F_3 ( * V_88 , V_2 -> V_9 + V_95 ) ;
V_88 ++ ;
V_2 -> V_48 ++ ;
V_2 -> V_49 -- ;
V_43 -> V_96 ++ ;
if ( V_2 -> V_49 == 0 ) {
if ( ! F_23 ( V_2 ) )
return;
V_88 = F_24 ( V_2 ) ;
}
}
}
F_32 ( & V_2 -> V_99 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
T_2 V_101 ;
T_1 V_12 ;
unsigned long V_38 ;
unsigned int V_102 ;
V_102 = V_43 -> V_97 * V_43 -> V_98 ;
if ( V_43 -> V_103 > 127000000 )
F_8 ( V_2 , V_24 , 127 ) ;
else {
F_8 ( V_2 , V_24 ,
V_43 -> V_103 / 1000000 ) ;
}
if ( V_43 -> V_104 > 255 )
F_8 ( V_2 , V_105 , 255 ) ;
else
F_8 ( V_2 , V_105 , V_43 -> V_104 ) ;
if ( V_2 -> V_106 == V_107 ) {
V_101 = V_43 -> V_98 + 2 ;
F_8 ( V_2 , V_108 , ( V_101 >> 4 ) & 0xF0 ) ;
F_8 ( V_2 , V_109 , V_101 & 0xFF ) ;
} else if ( V_2 -> V_106 == V_110 ) {
V_101 = V_43 -> V_98 + 2 * 4 ;
F_8 ( V_2 , V_108 ,
( ( V_101 >> 4 ) & 0xF0 ) | V_111 ) ;
F_8 ( V_2 , V_109 , V_101 & 0xFF ) ;
} else {
V_43 -> error = - V_112 ;
return;
}
V_12 = F_9 ( V_2 , V_14 ) ;
V_12 |= V_15 ;
F_8 ( V_2 , V_14 , V_12 ) ;
if ( V_2 -> V_39 >= 0 ) {
F_2 ( V_102 > 0x10000 ) ;
if ( V_102 > 0x10000 ) {
V_43 -> error = - V_112 ;
return;
}
if ( V_43 -> V_18 & V_113 )
F_26 ( V_2 , V_43 ) ;
V_38 = F_15 () ;
F_16 ( V_2 -> V_39 ) ;
F_17 ( V_2 -> V_39 ) ;
if ( V_43 -> V_18 & V_114 )
F_35 ( V_2 -> V_39 , V_115 & ~ 0x40 ) ;
else
F_35 ( V_2 -> V_39 , V_116 & ~ 0x40 ) ;
F_36 ( V_2 -> V_39 , V_2 -> V_117 ) ;
F_37 ( V_2 -> V_39 , V_102 ) ;
F_38 ( V_2 -> V_39 ) ;
F_18 ( V_38 ) ;
F_8 ( V_2 , V_40 , V_118 ) ;
} else {
V_2 -> V_119 = 1 ;
F_22 ( V_2 , V_43 ) ;
F_8 ( V_2 , V_40 , 0 ) ;
if ( V_43 -> V_18 & V_114 ) {
F_8 ( V_2 , V_120 ,
V_121 | 8 ) ;
} else {
F_8 ( V_2 , V_120 ,
V_122 | 8 ) ;
F_33 ( V_2 ) ;
}
}
V_43 -> error = 0 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
unsigned long V_38 ;
int V_123 ;
T_1 V_73 ;
F_40 ( V_2 -> V_37 == NULL ) ;
if ( V_43 -> V_124 )
F_30 ( V_2 , V_43 -> V_124 ) ;
do {
V_73 = F_9 ( V_2 , V_78 ) ;
} while ( V_73 & ( V_125 | V_126 ) );
if ( V_2 -> V_39 >= 0 ) {
F_8 ( V_2 , V_40 , 0 ) ;
V_38 = F_15 () ;
F_16 ( V_2 -> V_39 ) ;
F_17 ( V_2 -> V_39 ) ;
V_123 = F_41 ( V_2 -> V_39 ) ;
F_18 ( V_38 ) ;
V_43 -> V_96 = V_2 -> V_37 -> V_43 -> V_97 *
V_2 -> V_37 -> V_43 -> V_98 - V_123 ;
V_43 -> V_96 -= V_43 -> V_96 % V_43 -> V_98 ;
if ( V_123 ) {
F_12 ( V_34 L_2
L_3 ,
F_13 ( V_2 -> V_35 ) , V_123 ) ;
if ( ! V_43 -> error )
V_43 -> error = - V_127 ;
} else {
if ( V_43 -> V_18 & V_114 )
F_27 ( V_2 , V_43 ) ;
}
if ( V_43 -> error ) {
if ( V_43 -> V_96 )
V_43 -> V_96 -= V_43 -> V_98 ;
}
}
F_14 ( V_2 , V_2 -> V_37 ) ;
}
static void F_42 ( struct V_128 * V_35 , struct V_36 * V_37 )
{
struct V_1 * V_2 = F_43 ( V_35 ) ;
struct V_57 * V_58 ;
F_44 ( & V_2 -> V_41 ) ;
F_2 ( V_2 -> V_37 != NULL ) ;
V_58 = V_37 -> V_58 ;
V_2 -> V_37 = V_37 ;
if ( ! ( V_2 -> V_18 & V_26 ) ) {
V_58 -> error = - V_82 ;
goto V_129;
}
if ( V_58 -> V_43 ) {
switch ( V_58 -> V_75 ) {
case 11 :
case 17 :
case 18 :
case 20 :
case 24 :
case 25 :
case 26 :
case 27 :
case 30 :
case 42 :
case 56 :
break;
case 51 :
break;
default:
#ifdef F_45
F_12 ( V_130 L_4
L_5 ,
F_13 ( V_2 -> V_35 ) , V_58 -> V_75 ) ;
#endif
V_58 -> error = - V_112 ;
goto V_129;
} ;
}
if ( V_58 -> V_43 ) {
F_34 ( V_2 , V_58 -> V_43 ) ;
if ( V_58 -> V_43 -> error )
goto V_129;
}
F_30 ( V_2 , V_58 ) ;
if ( V_58 -> V_43 && ! V_58 -> error ) {
if ( V_2 -> V_39 == - 1 )
F_32 ( & V_2 -> V_99 ) ;
F_46 ( & V_2 -> V_41 ) ;
return;
}
V_129:
F_14 ( V_2 , V_37 ) ;
F_46 ( & V_2 -> V_41 ) ;
}
static void F_47 ( struct V_128 * V_35 , struct V_131 * V_132 )
{
struct V_1 * V_2 = F_43 ( V_35 ) ;
T_1 V_20 , V_12 , V_133 ;
F_44 ( & V_2 -> V_41 ) ;
if ( V_132 -> V_134 == V_135 )
F_10 ( V_2 ) ;
if ( V_132 -> clock >= 24000000 )
V_20 = V_136 ;
else if ( V_132 -> clock >= 16000000 )
V_20 = V_137 ;
else if ( V_132 -> clock >= 12000000 )
V_20 = V_138 ;
else
V_20 = V_139 ;
if ( V_20 != V_2 -> V_20 ) {
F_8 ( V_2 , V_21 , V_20 ) ;
V_2 -> V_20 = V_20 ;
}
if ( V_132 -> V_134 != V_135 ) {
V_133 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_133 &= ~ V_22 ;
F_3 ( V_133 , V_2 -> V_9 + V_23 ) ;
}
V_12 = F_9 ( V_2 , V_14 ) ;
if ( V_132 -> V_140 == V_141 ) {
F_2 ( V_132 -> V_106 != V_107 ) ;
V_12 |= V_17 ;
V_2 -> V_18 |= V_19 ;
} else {
if ( V_12 & V_17 ) {
V_12 &= ~ V_17 ;
F_48 ( & V_2 -> V_142 , V_143 + V_144 / 100 ) ;
}
}
F_8 ( V_2 , V_14 , V_12 ) ;
V_2 -> V_106 = V_132 -> V_106 ;
F_46 ( & V_2 -> V_41 ) ;
}
static int F_49 ( struct V_128 * V_35 )
{
struct V_1 * V_2 = F_43 ( V_35 ) ;
T_1 V_145 ;
F_44 ( & V_2 -> V_41 ) ;
V_145 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_145 |= V_146 ;
F_3 ( V_145 , V_2 -> V_9 + V_23 ) ;
F_50 ( 1 ) ;
V_145 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_145 &= ~ V_146 ;
F_3 ( V_145 , V_2 -> V_9 + V_23 ) ;
F_46 ( & V_2 -> V_41 ) ;
return ! ! ( V_145 & V_147 ) ;
}
static void F_51 ( unsigned long V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
F_2 ( V_2 == NULL ) ;
F_52 ( L_6 ) ;
F_44 ( & V_2 -> V_41 ) ;
V_2 -> V_18 &= ~ V_19 ;
F_32 ( & V_2 -> V_148 ) ;
F_46 ( & V_2 -> V_41 ) ;
}
static inline struct V_42 * F_53 ( struct V_1 * V_2 )
{
F_40 ( ! V_2 -> V_37 ) ;
if ( ! V_2 -> V_37 )
return NULL ;
F_40 ( ! V_2 -> V_37 -> V_58 ) ;
if ( ! V_2 -> V_37 -> V_58 )
return NULL ;
F_40 ( ! V_2 -> V_37 -> V_58 -> V_43 ) ;
if ( ! V_2 -> V_37 -> V_58 -> V_43 )
return NULL ;
return V_2 -> V_37 -> V_58 -> V_43 ;
}
static void F_54 ( unsigned long V_149 )
{
struct V_1 * V_2 = (struct V_1 * ) V_149 ;
T_1 V_145 ;
int V_150 = - 1 ;
F_21 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_18 & V_19 ) {
F_19 ( & V_2 -> V_41 ) ;
return;
}
V_145 = F_7 ( V_2 -> V_9 + V_23 ) ;
F_40 ( V_145 == 0xff ) ;
if ( V_145 & V_25 ) {
if ( ! ( V_2 -> V_18 & V_26 ) ) {
F_52 ( L_7 ) ;
V_2 -> V_18 |= V_26 ;
V_150 = 500 ;
}
} else if ( V_2 -> V_18 & V_26 ) {
F_52 ( L_8 ) ;
V_2 -> V_18 &= ~ V_26 ;
if ( V_2 -> V_37 ) {
F_12 ( V_34 L_9 ,
F_13 ( V_2 -> V_35 ) ) ;
F_11 ( V_2 ) ;
V_2 -> V_37 -> V_58 -> error = - V_82 ;
F_32 ( & V_2 -> V_151 ) ;
}
V_150 = 0 ;
}
F_19 ( & V_2 -> V_41 ) ;
if ( V_150 != - 1 )
F_55 ( V_2 -> V_35 , F_56 ( V_150 ) ) ;
}
static void F_57 ( unsigned long V_149 )
{
struct V_1 * V_2 = (struct V_1 * ) V_149 ;
struct V_42 * V_43 ;
F_21 ( & V_2 -> V_41 ) ;
if ( ! V_2 -> V_37 )
goto V_152;
V_43 = F_53 ( V_2 ) ;
if ( ! V_43 )
goto V_152;
if ( V_43 -> V_18 & V_113 )
F_33 ( V_2 ) ;
else
F_31 ( V_2 ) ;
if ( V_2 -> V_46 == 0 ) {
F_8 ( V_2 , V_120 , 0 ) ;
F_32 ( & V_2 -> V_151 ) ;
}
V_152:
F_19 ( & V_2 -> V_41 ) ;
}
static void F_58 ( unsigned long V_149 )
{
struct V_1 * V_2 = (struct V_1 * ) V_149 ;
struct V_42 * V_43 ;
F_21 ( & V_2 -> V_41 ) ;
if ( ! V_2 -> V_37 )
goto V_152;
V_43 = F_53 ( V_2 ) ;
if ( ! V_43 )
goto V_152;
F_59 ( L_10 ) ;
V_43 -> error = - V_61 ;
F_32 ( & V_2 -> V_151 ) ;
V_152:
F_19 ( & V_2 -> V_41 ) ;
}
static void F_60 ( unsigned long V_149 )
{
struct V_1 * V_2 = (struct V_1 * ) V_149 ;
struct V_42 * V_43 ;
F_21 ( & V_2 -> V_41 ) ;
if ( ! V_2 -> V_37 )
goto V_152;
V_43 = F_53 ( V_2 ) ;
if ( ! V_43 )
goto V_152;
F_59 ( L_11 ) ;
V_43 -> error = - V_84 ;
F_32 ( & V_2 -> V_151 ) ;
V_152:
F_19 ( & V_2 -> V_41 ) ;
}
static void F_61 ( unsigned long V_149 )
{
struct V_1 * V_2 = (struct V_1 * ) V_149 ;
struct V_42 * V_43 ;
F_21 ( & V_2 -> V_41 ) ;
F_40 ( ! V_2 -> V_37 ) ;
if ( ! V_2 -> V_37 )
goto V_152;
V_43 = F_53 ( V_2 ) ;
if ( ! V_43 )
goto V_152;
F_39 ( V_2 , V_43 ) ;
V_152:
F_19 ( & V_2 -> V_41 ) ;
}
static T_3 F_62 ( int V_153 , void * V_154 )
{
struct V_1 * V_2 = V_154 ;
int V_74 ;
V_74 = F_7 ( V_2 -> V_9 + V_33 ) ;
if ( V_74 == 0xff || V_74 == 0x00 )
return V_155 ;
V_2 -> V_74 |= V_74 ;
if ( V_74 & V_81 )
F_32 ( & V_2 -> V_148 ) ;
if ( V_74 & V_156 )
F_32 ( & V_2 -> V_99 ) ;
if ( V_74 & V_86 )
F_63 ( & V_2 -> V_157 ) ;
if ( V_74 & V_83 )
F_63 ( & V_2 -> V_158 ) ;
if ( V_74 & V_159 )
F_32 ( & V_2 -> V_151 ) ;
return V_160 ;
}
static int T_4 F_64 ( struct V_161 * V_162 )
{
struct V_128 * V_35 ;
struct V_1 * V_2 ;
V_35 = F_65 ( sizeof( struct V_1 ) , V_162 ) ;
if ( ! V_35 )
return - V_163 ;
V_2 = F_43 ( V_35 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_39 = - 1 ;
V_35 -> V_164 = & V_165 ;
V_35 -> V_166 = 375000 ;
V_35 -> V_167 = 24000000 ;
V_35 -> V_168 = V_169 | V_170 ;
V_35 -> V_171 = V_172 ;
F_66 ( & V_2 -> V_41 ) ;
F_67 ( & V_2 -> V_142 ) ;
V_2 -> V_142 . V_43 = ( unsigned long ) V_2 ;
V_2 -> V_142 . V_173 = F_51 ;
V_35 -> V_174 = 128 ;
V_35 -> V_175 = 65536 ;
V_35 -> V_176 = V_35 -> V_175 ;
V_35 -> V_177 = 4087 ;
V_35 -> V_178 = V_35 -> V_175 ;
F_68 ( V_162 , V_35 ) ;
return 0 ;
}
static void F_69 ( struct V_161 * V_162 )
{
struct V_128 * V_35 ;
struct V_1 * V_2 ;
V_35 = F_70 ( V_162 ) ;
if ( ! V_35 )
return;
V_2 = F_43 ( V_35 ) ;
F_2 ( V_2 == NULL ) ;
F_71 ( & V_2 -> V_142 ) ;
F_72 ( V_35 ) ;
F_68 ( V_162 , NULL ) ;
}
static int T_4 F_73 ( struct V_1 * V_2 )
{
int V_52 , V_179 , V_180 ;
int V_181 ;
for ( V_52 = 0 ; V_52 < F_74 ( V_182 ) ; V_52 ++ ) {
if ( ! F_75 ( V_182 [ V_52 ] , 2 , V_183 ) )
continue;
for ( V_179 = 0 ; V_179 < F_74 ( V_184 ) ; V_179 ++ ) {
V_181 = 0xFFFF ;
V_2 -> V_3 = V_182 [ V_52 ] ;
V_2 -> V_4 = V_184 [ V_179 ] ;
F_1 ( V_2 ) ;
F_3 ( V_185 , V_182 [ V_52 ] ) ;
V_181 = F_7 ( V_182 [ V_52 ] + 1 ) << 8 ;
F_3 ( V_186 , V_182 [ V_52 ] ) ;
V_181 |= F_7 ( V_182 [ V_52 ] + 1 ) ;
F_4 ( V_2 ) ;
for ( V_180 = 0 ; V_180 < F_74 ( V_187 ) ; V_180 ++ ) {
if ( V_181 == V_187 [ V_180 ] ) {
V_2 -> V_188 = V_181 ;
return 0 ;
}
}
if ( V_181 != 0xFFFF ) {
F_52 ( L_12 ,
V_181 , V_182 [ V_52 ] ) ;
}
}
F_76 ( V_182 [ V_52 ] , 2 ) ;
}
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
return - V_189 ;
}
static int T_4 F_77 ( struct V_1 * V_2 , int V_9 )
{
if ( V_9 & 0x7 )
return - V_112 ;
if ( ! F_75 ( V_9 , 8 , V_183 ) )
return - V_127 ;
V_2 -> V_9 = V_9 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_76 ( V_2 -> V_9 , 8 ) ;
V_2 -> V_9 = 0 ;
if ( V_2 -> V_3 )
F_76 ( V_2 -> V_3 , 2 ) ;
V_2 -> V_3 = 0 ;
}
static void T_4 F_79 ( struct V_1 * V_2 , int V_39 )
{
if ( V_39 < 0 )
return;
if ( F_80 ( V_39 , V_183 ) )
goto V_190;
V_2 -> V_55 = F_81 ( V_191 ,
V_192 | V_193 | V_194 | V_195 ) ;
if ( ! V_2 -> V_55 )
goto free;
V_2 -> V_117 = F_82 ( F_83 ( V_2 -> V_35 ) , V_2 -> V_55 ,
V_191 , V_196 ) ;
if ( ( V_2 -> V_117 & 0xffff ) != 0 )
goto V_197;
else if ( V_2 -> V_117 >= 0x1000000 )
goto V_197;
V_2 -> V_39 = V_39 ;
return;
V_197:
F_2 ( 1 ) ;
F_84 ( F_83 ( V_2 -> V_35 ) , V_2 -> V_117 ,
V_191 , V_196 ) ;
V_2 -> V_117 = 0 ;
V_197 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
free:
F_85 ( V_39 ) ;
V_190:
F_12 (KERN_WARNING DRIVER_NAME L_13
L_14 , dma) ;
}
static void F_86 ( struct V_1 * V_2 )
{
if ( V_2 -> V_117 ) {
F_84 ( F_83 ( V_2 -> V_35 ) , V_2 -> V_117 ,
V_191 , V_196 ) ;
}
V_197 ( V_2 -> V_55 ) ;
if ( V_2 -> V_39 >= 0 )
F_85 ( V_2 -> V_39 ) ;
V_2 -> V_39 = - 1 ;
V_2 -> V_55 = NULL ;
V_2 -> V_117 = 0 ;
}
static int T_4 F_87 ( struct V_1 * V_2 , int V_153 )
{
int V_198 ;
F_88 ( & V_2 -> V_148 , F_54 ,
( unsigned long ) V_2 ) ;
F_88 ( & V_2 -> V_99 , F_57 ,
( unsigned long ) V_2 ) ;
F_88 ( & V_2 -> V_157 , F_58 ,
( unsigned long ) V_2 ) ;
F_88 ( & V_2 -> V_158 , F_60 ,
( unsigned long ) V_2 ) ;
F_88 ( & V_2 -> V_151 , F_61 ,
( unsigned long ) V_2 ) ;
V_198 = F_89 ( V_153 , F_62 , V_199 , V_183 , V_2 ) ;
if ( V_198 )
return V_198 ;
V_2 -> V_153 = V_153 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_153 )
return;
F_91 ( V_2 -> V_153 , V_2 ) ;
V_2 -> V_153 = 0 ;
F_92 ( & V_2 -> V_148 ) ;
F_92 ( & V_2 -> V_99 ) ;
F_92 ( & V_2 -> V_157 ) ;
F_92 ( & V_2 -> V_158 ) ;
F_92 ( & V_2 -> V_151 ) ;
}
static int T_4 F_93 ( struct V_1 * V_2 ,
int V_9 , int V_153 , int V_39 )
{
int V_198 ;
V_198 = F_77 ( V_2 , V_9 ) ;
if ( V_198 )
return V_198 ;
V_198 = F_87 ( V_2 , V_153 ) ;
if ( V_198 )
return V_198 ;
F_79 ( V_2 , V_39 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_86 ( V_2 ) ;
F_90 ( V_2 ) ;
F_78 ( V_2 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( V_2 , V_200 , 1 ) ;
F_5 ( V_2 , V_200 , 0 ) ;
F_5 ( V_2 , V_201 , V_202 ) ;
F_5 ( V_2 , V_203 , V_204 ) ;
F_5 ( V_2 , V_205 , V_2 -> V_9 >> 8 ) ;
F_5 ( V_2 , V_206 , V_2 -> V_9 & 0xff ) ;
F_5 ( V_2 , V_207 , V_2 -> V_153 ) ;
if ( V_2 -> V_39 >= 0 )
F_5 ( V_2 , V_208 , V_2 -> V_39 ) ;
F_5 ( V_2 , V_209 , 1 ) ;
F_5 ( V_2 , V_210 , 0x20 ) ;
F_4 ( V_2 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_9 , V_153 , V_39 ;
F_1 ( V_2 ) ;
F_5 ( V_2 , V_201 , V_202 ) ;
V_9 = F_6 ( V_2 , V_205 ) << 8 ;
V_9 |= F_6 ( V_2 , V_206 ) ;
V_153 = F_6 ( V_2 , V_207 ) ;
V_39 = F_6 ( V_2 , V_208 ) ;
F_4 ( V_2 ) ;
if ( V_9 != V_2 -> V_9 )
return 0 ;
if ( V_153 != V_2 -> V_153 )
return 0 ;
if ( ( V_39 != V_2 -> V_39 ) && ( V_2 -> V_39 != - 1 ) )
return 0 ;
return 1 ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( V_2 , V_201 , V_202 ) ;
F_5 ( V_2 , V_209 , 0 ) ;
F_4 ( V_2 ) ;
}
static int T_4 F_98 ( struct V_161 * V_162 , int V_9 , int V_153 , int V_39 ,
int V_211 )
{
struct V_1 * V_2 = NULL ;
struct V_128 * V_35 = NULL ;
int V_198 ;
V_198 = F_64 ( V_162 ) ;
if ( V_198 )
return V_198 ;
V_35 = F_70 ( V_162 ) ;
V_2 = F_43 ( V_35 ) ;
V_198 = F_73 ( V_2 ) ;
if ( V_198 ) {
if ( V_211 && ( V_198 == - V_189 ) ) {
F_12 (KERN_WARNING DRIVER_NAME
L_15
L_16 ) ;
} else {
F_69 ( V_162 ) ;
return V_198 ;
}
}
V_198 = F_93 ( V_2 , V_9 , V_153 , V_39 ) ;
if ( V_198 ) {
F_94 ( V_2 ) ;
F_69 ( V_162 ) ;
return V_198 ;
}
if ( V_211 ) {
if ( ( V_2 -> V_3 != 0 ) && ! F_96 ( V_2 ) ) {
F_12 (KERN_WARNING DRIVER_NAME
L_17
L_18
L_19 ) ;
F_95 ( V_2 ) ;
}
} else
F_95 ( V_2 ) ;
#ifdef F_99
if ( V_2 -> V_3 ) {
F_1 ( V_2 ) ;
F_5 ( V_2 , V_212 , 0xA0 ) ;
F_4 ( V_2 ) ;
}
#endif
F_50 ( 5 ) ;
F_10 ( V_2 ) ;
F_100 ( V_35 ) ;
F_12 ( V_213 L_20 , F_13 ( V_35 ) ) ;
if ( V_2 -> V_188 != 0 )
F_12 ( L_21 , ( int ) V_2 -> V_188 ) ;
F_12 ( L_22 , ( int ) V_2 -> V_9 , ( int ) V_2 -> V_153 ) ;
if ( V_2 -> V_39 >= 0 )
F_12 ( L_23 , ( int ) V_2 -> V_39 ) ;
else
F_12 ( L_24 ) ;
if ( V_211 )
F_12 ( L_25 ) ;
F_12 ( L_26 ) ;
return 0 ;
}
static void T_5 F_101 ( struct V_161 * V_162 , int V_211 )
{
struct V_128 * V_35 = F_70 ( V_162 ) ;
struct V_1 * V_2 ;
if ( ! V_35 )
return;
V_2 = F_43 ( V_35 ) ;
F_102 ( V_35 ) ;
if ( ! V_211 )
F_97 ( V_2 ) ;
F_94 ( V_2 ) ;
F_69 ( V_162 ) ;
}
static int T_4 F_103 ( struct V_214 * V_162 )
{
return F_98 ( & V_162 -> V_162 , V_215 , V_216 , V_217 , 0 ) ;
}
static int T_5 F_104 ( struct V_214 * V_162 )
{
F_101 ( & V_162 -> V_162 , 0 ) ;
return 0 ;
}
static int T_4
F_105 ( struct V_218 * V_219 , const struct V_220 * V_154 )
{
int V_221 , V_153 , V_39 ;
V_221 = F_106 ( V_219 , 0 ) ;
V_153 = F_107 ( V_219 , 0 ) ;
if ( F_108 ( V_219 , 0 ) )
V_39 = F_109 ( V_219 , 0 ) ;
else
V_39 = - 1 ;
F_59 ( L_27 , V_221 , V_153 , V_39 ) ;
return F_98 ( & V_219 -> V_162 , V_221 , V_153 , V_39 , 1 ) ;
}
static void T_5 F_110 ( struct V_218 * V_162 )
{
F_101 ( & V_162 -> V_162 , 1 ) ;
}
static int F_111 ( struct V_1 * V_2 , T_6 V_222 )
{
F_2 ( V_2 == NULL ) ;
return F_112 ( V_2 -> V_35 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
F_2 ( V_2 == NULL ) ;
F_10 ( V_2 ) ;
return F_114 ( V_2 -> V_35 ) ;
}
static int F_115 ( struct V_214 * V_162 ,
T_6 V_222 )
{
struct V_128 * V_35 = F_116 ( V_162 ) ;
struct V_1 * V_2 ;
int V_198 ;
if ( V_35 == NULL )
return 0 ;
F_59 ( L_28 ) ;
V_2 = F_43 ( V_35 ) ;
V_198 = F_111 ( V_2 , V_222 ) ;
if ( V_198 )
return V_198 ;
F_97 ( V_2 ) ;
return 0 ;
}
static int F_117 ( struct V_214 * V_162 )
{
struct V_128 * V_35 = F_116 ( V_162 ) ;
struct V_1 * V_2 ;
if ( V_35 == NULL )
return 0 ;
F_59 ( L_29 ) ;
V_2 = F_43 ( V_35 ) ;
F_95 ( V_2 ) ;
F_50 ( 5 ) ;
return F_113 ( V_2 ) ;
}
static int F_118 ( struct V_218 * V_218 , T_6 V_222 )
{
struct V_128 * V_35 = F_70 ( & V_218 -> V_162 ) ;
struct V_1 * V_2 ;
if ( V_35 == NULL )
return 0 ;
F_59 ( L_28 ) ;
V_2 = F_43 ( V_35 ) ;
return F_111 ( V_2 , V_222 ) ;
}
static int F_119 ( struct V_218 * V_218 )
{
struct V_128 * V_35 = F_70 ( & V_218 -> V_162 ) ;
struct V_1 * V_2 ;
if ( V_35 == NULL )
return 0 ;
F_59 ( L_29 ) ;
V_2 = F_43 ( V_35 ) ;
if ( V_2 -> V_3 != 0 ) {
if ( ! F_96 ( V_2 ) ) {
F_12 (KERN_WARNING DRIVER_NAME
L_17
L_18
L_19 ) ;
F_95 ( V_2 ) ;
}
}
F_50 ( 5 ) ;
return F_113 ( V_2 ) ;
}
static int T_7 F_120 ( void )
{
int V_223 ;
F_12 (KERN_INFO DRIVER_NAME
L_30 ) ;
F_12 (KERN_INFO DRIVER_NAME L_31 ) ;
#ifdef F_121
if ( ! V_224 ) {
V_223 = F_122 ( & V_225 ) ;
if ( V_223 < 0 )
return V_223 ;
}
#endif
if ( V_224 ) {
V_223 = F_123 ( & V_226 ) ;
if ( V_223 < 0 )
return V_223 ;
V_227 = F_124 ( V_183 , - 1 ) ;
if ( ! V_227 ) {
F_125 ( & V_226 ) ;
return - V_163 ;
}
V_223 = F_126 ( V_227 ) ;
if ( V_223 ) {
F_127 ( V_227 ) ;
F_125 ( & V_226 ) ;
return V_223 ;
}
}
return 0 ;
}
static void T_8 F_128 ( void )
{
#ifdef F_121
if ( ! V_224 )
F_129 ( & V_225 ) ;
#endif
if ( V_224 ) {
F_130 ( V_227 ) ;
F_125 ( & V_226 ) ;
}
F_52 ( L_32 ) ;
}
