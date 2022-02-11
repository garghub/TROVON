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
F_12 ( L_1 , F_13 ( V_2 -> V_34 ) ) ;
V_12 = F_9 ( V_2 , V_14 ) ;
V_12 |= V_16 ;
F_8 ( V_2 , V_14 , V_12 ) ;
}
static void F_14 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
unsigned long V_37 ;
if ( V_2 -> V_38 >= 0 ) {
V_37 = F_15 () ;
F_16 ( V_2 -> V_38 ) ;
F_17 ( V_2 -> V_38 ) ;
F_18 ( V_37 ) ;
F_8 ( V_2 , V_39 , 0 ) ;
}
V_2 -> V_36 = NULL ;
F_19 ( & V_2 -> V_40 ) ;
F_20 ( V_2 -> V_34 , V_36 ) ;
F_21 ( & V_2 -> V_40 ) ;
}
static inline void F_22 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
V_2 -> V_43 = V_42 -> V_44 ;
V_2 -> V_45 = V_42 -> V_46 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = V_2 -> V_43 -> V_49 ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
V_2 -> V_43 ++ ;
V_2 -> V_45 -- ;
if ( V_2 -> V_45 > 0 ) {
V_2 -> V_47 = 0 ;
V_2 -> V_48 = V_2 -> V_43 -> V_49 ;
}
return V_2 -> V_45 ;
}
static inline char * F_24 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_43 ) ;
}
static inline void F_26 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned int V_50 , V_51 ;
struct V_52 * V_44 ;
char * V_53 = V_2 -> V_54 ;
char * V_55 ;
V_44 = V_42 -> V_44 ;
V_50 = V_42 -> V_46 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_55 = F_25 ( & V_44 [ V_51 ] ) ;
memcpy ( V_53 , V_55 , V_44 [ V_51 ] . V_49 ) ;
V_53 += V_44 [ V_51 ] . V_49 ;
}
}
static inline void F_27 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned int V_50 , V_51 ;
struct V_52 * V_44 ;
char * V_53 = V_2 -> V_54 ;
char * V_55 ;
V_44 = V_42 -> V_44 ;
V_50 = V_42 -> V_46 ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_55 = F_25 ( & V_44 [ V_51 ] ) ;
memcpy ( V_55 , V_53 , V_44 [ V_51 ] . V_49 ) ;
V_53 += V_44 [ V_51 ] . V_49 ;
}
}
static inline void F_28 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
if ( F_9 ( V_2 , V_58 ) != V_59 ) {
V_57 -> error = - V_60 ;
return;
}
V_57 -> V_61 [ 0 ] = F_9 ( V_2 , V_62 ) << 24 ;
V_57 -> V_61 [ 0 ] |= F_9 ( V_2 , V_63 ) << 16 ;
V_57 -> V_61 [ 0 ] |= F_9 ( V_2 , V_64 ) << 8 ;
V_57 -> V_61 [ 0 ] |= F_9 ( V_2 , V_65 ) << 0 ;
V_57 -> V_61 [ 1 ] = F_9 ( V_2 , V_66 ) << 24 ;
}
static inline void F_29 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
int V_51 ;
if ( F_9 ( V_2 , V_58 ) != V_67 ) {
V_57 -> error = - V_60 ;
return;
}
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
V_57 -> V_61 [ V_51 ] =
F_9 ( V_2 , V_68 + V_51 * 4 ) << 24 ;
V_57 -> V_61 [ V_51 ] |=
F_9 ( V_2 , V_69 + V_51 * 4 ) << 16 ;
V_57 -> V_61 [ V_51 ] |=
F_9 ( V_2 , V_70 + V_51 * 4 ) << 8 ;
V_57 -> V_61 [ V_51 ] |=
F_9 ( V_2 , V_71 + V_51 * 4 ) << 0 ;
}
}
static void F_30 ( struct V_1 * V_2 , struct V_56 * V_57 )
{
int V_51 ;
T_1 V_72 , V_73 ;
V_2 -> V_73 = 0 ;
F_3 ( V_57 -> V_74 , V_2 -> V_9 + V_75 ) ;
for ( V_51 = 3 ; V_51 >= 0 ; V_51 -- )
F_3 ( ( V_57 -> V_76 >> ( V_51 * 8 ) ) & 0xff , V_2 -> V_9 + V_75 ) ;
V_57 -> error = 0 ;
do {
V_72 = F_9 ( V_2 , V_77 ) ;
} while ( V_72 & V_78 );
if ( V_57 -> V_18 & V_79 ) {
V_73 = V_2 -> V_73 ;
if ( V_73 & V_80 )
V_57 -> error = - V_81 ;
else if ( V_73 & V_82 )
V_57 -> error = - V_83 ;
else if ( ( V_57 -> V_18 & V_84 ) && ( V_73 & V_85 ) )
V_57 -> error = - V_60 ;
else {
if ( V_57 -> V_18 & V_86 )
F_29 ( V_2 , V_57 ) ;
else
F_28 ( V_2 , V_57 ) ;
}
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_36 -> V_57 -> V_42 ;
char * V_87 ;
int V_51 , V_88 , V_89 ;
if ( V_2 -> V_45 == 0 )
return;
V_87 = F_24 ( V_2 ) + V_2 -> V_47 ;
while ( ! ( ( V_88 = F_7 ( V_2 -> V_9 + V_90 ) ) & V_91 ) ) {
if ( V_88 & V_92 )
V_89 = 16 ;
else if ( V_88 & V_93 )
V_89 = 8 ;
else
V_89 = 1 ;
for ( V_51 = 0 ; V_51 < V_89 ; V_51 ++ ) {
* V_87 = F_7 ( V_2 -> V_9 + V_94 ) ;
V_87 ++ ;
V_2 -> V_47 ++ ;
V_2 -> V_48 -- ;
V_42 -> V_95 ++ ;
if ( V_2 -> V_48 == 0 ) {
if ( ! F_23 ( V_2 ) )
return;
V_87 = F_24 ( V_2 ) ;
}
}
}
if ( ( V_42 -> V_96 * V_42 -> V_97 - V_42 -> V_95 ) < 16 )
F_32 ( & V_2 -> V_98 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_36 -> V_57 -> V_42 ;
char * V_87 ;
int V_51 , V_88 , V_89 ;
if ( V_2 -> V_45 == 0 )
return;
V_87 = F_24 ( V_2 ) + V_2 -> V_47 ;
while ( ! ( ( V_88 = F_7 ( V_2 -> V_9 + V_90 ) ) & V_92 ) ) {
if ( V_88 & V_91 )
V_89 = 0 ;
else if ( V_88 & V_99 )
V_89 = 8 ;
else
V_89 = 15 ;
for ( V_51 = 16 ; V_51 > V_89 ; V_51 -- ) {
F_3 ( * V_87 , V_2 -> V_9 + V_94 ) ;
V_87 ++ ;
V_2 -> V_47 ++ ;
V_2 -> V_48 -- ;
V_42 -> V_95 ++ ;
if ( V_2 -> V_48 == 0 ) {
if ( ! F_23 ( V_2 ) )
return;
V_87 = F_24 ( V_2 ) ;
}
}
}
F_32 ( & V_2 -> V_98 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
T_2 V_100 ;
T_1 V_12 ;
unsigned long V_37 ;
unsigned int V_101 ;
V_101 = V_42 -> V_96 * V_42 -> V_97 ;
if ( V_42 -> V_102 > 127000000 )
F_8 ( V_2 , V_24 , 127 ) ;
else {
F_8 ( V_2 , V_24 ,
V_42 -> V_102 / 1000000 ) ;
}
if ( V_42 -> V_103 > 255 )
F_8 ( V_2 , V_104 , 255 ) ;
else
F_8 ( V_2 , V_104 , V_42 -> V_103 ) ;
if ( V_2 -> V_105 == V_106 ) {
V_100 = V_42 -> V_97 + 2 ;
F_8 ( V_2 , V_107 , ( V_100 >> 4 ) & 0xF0 ) ;
F_8 ( V_2 , V_108 , V_100 & 0xFF ) ;
} else if ( V_2 -> V_105 == V_109 ) {
V_100 = V_42 -> V_97 + 2 * 4 ;
F_8 ( V_2 , V_107 ,
( ( V_100 >> 4 ) & 0xF0 ) | V_110 ) ;
F_8 ( V_2 , V_108 , V_100 & 0xFF ) ;
} else {
V_42 -> error = - V_111 ;
return;
}
V_12 = F_9 ( V_2 , V_14 ) ;
V_12 |= V_15 ;
F_8 ( V_2 , V_14 , V_12 ) ;
if ( V_2 -> V_38 >= 0 ) {
F_2 ( V_101 > 0x10000 ) ;
if ( V_101 > 0x10000 ) {
V_42 -> error = - V_111 ;
return;
}
if ( V_42 -> V_18 & V_112 )
F_26 ( V_2 , V_42 ) ;
V_37 = F_15 () ;
F_16 ( V_2 -> V_38 ) ;
F_17 ( V_2 -> V_38 ) ;
if ( V_42 -> V_18 & V_113 )
F_35 ( V_2 -> V_38 , V_114 & ~ 0x40 ) ;
else
F_35 ( V_2 -> V_38 , V_115 & ~ 0x40 ) ;
F_36 ( V_2 -> V_38 , V_2 -> V_116 ) ;
F_37 ( V_2 -> V_38 , V_101 ) ;
F_38 ( V_2 -> V_38 ) ;
F_18 ( V_37 ) ;
F_8 ( V_2 , V_39 , V_117 ) ;
} else {
V_2 -> V_118 = 1 ;
F_22 ( V_2 , V_42 ) ;
F_8 ( V_2 , V_39 , 0 ) ;
if ( V_42 -> V_18 & V_113 ) {
F_8 ( V_2 , V_119 ,
V_120 | 8 ) ;
} else {
F_8 ( V_2 , V_119 ,
V_121 | 8 ) ;
F_33 ( V_2 ) ;
}
}
V_42 -> error = 0 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
unsigned long V_37 ;
int V_122 ;
T_1 V_72 ;
F_40 ( V_2 -> V_36 == NULL ) ;
if ( V_42 -> V_123 )
F_30 ( V_2 , V_42 -> V_123 ) ;
do {
V_72 = F_9 ( V_2 , V_77 ) ;
} while ( V_72 & ( V_124 | V_125 ) );
if ( V_2 -> V_38 >= 0 ) {
F_8 ( V_2 , V_39 , 0 ) ;
V_37 = F_15 () ;
F_16 ( V_2 -> V_38 ) ;
F_17 ( V_2 -> V_38 ) ;
V_122 = F_41 ( V_2 -> V_38 ) ;
F_18 ( V_37 ) ;
V_42 -> V_95 = V_2 -> V_36 -> V_42 -> V_96 *
V_2 -> V_36 -> V_42 -> V_97 - V_122 ;
V_42 -> V_95 -= V_42 -> V_95 % V_42 -> V_97 ;
if ( V_122 ) {
F_12 ( L_2
L_3 ,
F_13 ( V_2 -> V_34 ) , V_122 ) ;
if ( ! V_42 -> error )
V_42 -> error = - V_126 ;
} else {
if ( V_42 -> V_18 & V_113 )
F_27 ( V_2 , V_42 ) ;
}
if ( V_42 -> error ) {
if ( V_42 -> V_95 )
V_42 -> V_95 -= V_42 -> V_97 ;
}
}
F_14 ( V_2 , V_2 -> V_36 ) ;
}
static void F_42 ( struct V_127 * V_34 , struct V_35 * V_36 )
{
struct V_1 * V_2 = F_43 ( V_34 ) ;
struct V_56 * V_57 ;
F_44 ( & V_2 -> V_40 ) ;
F_2 ( V_2 -> V_36 != NULL ) ;
V_57 = V_36 -> V_57 ;
V_2 -> V_36 = V_36 ;
if ( ! ( V_2 -> V_18 & V_26 ) ) {
V_57 -> error = - V_81 ;
goto V_128;
}
if ( V_57 -> V_42 ) {
switch ( V_57 -> V_74 ) {
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
F_46 ( L_4 ,
F_13 ( V_2 -> V_34 ) , V_57 -> V_74 ) ;
#endif
V_57 -> error = - V_111 ;
goto V_128;
}
}
if ( V_57 -> V_42 ) {
F_34 ( V_2 , V_57 -> V_42 ) ;
if ( V_57 -> V_42 -> error )
goto V_128;
}
F_30 ( V_2 , V_57 ) ;
if ( V_57 -> V_42 && ! V_57 -> error ) {
if ( V_2 -> V_38 == - 1 )
F_32 ( & V_2 -> V_98 ) ;
F_47 ( & V_2 -> V_40 ) ;
return;
}
V_128:
F_14 ( V_2 , V_36 ) ;
F_47 ( & V_2 -> V_40 ) ;
}
static void F_48 ( struct V_127 * V_34 , struct V_129 * V_130 )
{
struct V_1 * V_2 = F_43 ( V_34 ) ;
T_1 V_20 , V_12 , V_131 ;
F_44 ( & V_2 -> V_40 ) ;
if ( V_130 -> V_132 == V_133 )
F_10 ( V_2 ) ;
if ( V_130 -> clock >= 24000000 )
V_20 = V_134 ;
else if ( V_130 -> clock >= 16000000 )
V_20 = V_135 ;
else if ( V_130 -> clock >= 12000000 )
V_20 = V_136 ;
else
V_20 = V_137 ;
if ( V_20 != V_2 -> V_20 ) {
F_8 ( V_2 , V_21 , V_20 ) ;
V_2 -> V_20 = V_20 ;
}
if ( V_130 -> V_132 != V_133 ) {
V_131 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_131 &= ~ V_22 ;
F_3 ( V_131 , V_2 -> V_9 + V_23 ) ;
}
V_12 = F_9 ( V_2 , V_14 ) ;
if ( V_130 -> V_138 == V_139 ) {
F_2 ( V_130 -> V_105 != V_106 ) ;
V_12 |= V_17 ;
V_2 -> V_18 |= V_19 ;
} else {
if ( V_12 & V_17 ) {
V_12 &= ~ V_17 ;
F_49 ( & V_2 -> V_140 , V_141 + V_142 / 100 ) ;
}
}
F_8 ( V_2 , V_14 , V_12 ) ;
V_2 -> V_105 = V_130 -> V_105 ;
F_47 ( & V_2 -> V_40 ) ;
}
static int F_50 ( struct V_127 * V_34 )
{
struct V_1 * V_2 = F_43 ( V_34 ) ;
T_1 V_143 ;
F_44 ( & V_2 -> V_40 ) ;
V_143 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_143 |= V_144 ;
F_3 ( V_143 , V_2 -> V_9 + V_23 ) ;
F_51 ( 1 ) ;
V_143 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_143 &= ~ V_144 ;
F_3 ( V_143 , V_2 -> V_9 + V_23 ) ;
F_47 ( & V_2 -> V_40 ) ;
return ! ! ( V_143 & V_145 ) ;
}
static void F_52 ( unsigned long V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
F_2 ( V_2 == NULL ) ;
F_53 ( L_5 ) ;
F_44 ( & V_2 -> V_40 ) ;
V_2 -> V_18 &= ~ V_19 ;
F_32 ( & V_2 -> V_146 ) ;
F_47 ( & V_2 -> V_40 ) ;
}
static inline struct V_41 * F_54 ( struct V_1 * V_2 )
{
F_40 ( ! V_2 -> V_36 ) ;
if ( ! V_2 -> V_36 )
return NULL ;
F_40 ( ! V_2 -> V_36 -> V_57 ) ;
if ( ! V_2 -> V_36 -> V_57 )
return NULL ;
F_40 ( ! V_2 -> V_36 -> V_57 -> V_42 ) ;
if ( ! V_2 -> V_36 -> V_57 -> V_42 )
return NULL ;
return V_2 -> V_36 -> V_57 -> V_42 ;
}
static void F_55 ( unsigned long V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_147 ;
T_1 V_143 ;
int V_148 = - 1 ;
F_21 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_18 & V_19 ) {
F_19 ( & V_2 -> V_40 ) ;
return;
}
V_143 = F_7 ( V_2 -> V_9 + V_23 ) ;
F_40 ( V_143 == 0xff ) ;
if ( V_143 & V_25 ) {
if ( ! ( V_2 -> V_18 & V_26 ) ) {
F_53 ( L_6 ) ;
V_2 -> V_18 |= V_26 ;
V_148 = 500 ;
}
} else if ( V_2 -> V_18 & V_26 ) {
F_53 ( L_7 ) ;
V_2 -> V_18 &= ~ V_26 ;
if ( V_2 -> V_36 ) {
F_12 ( L_8 ,
F_13 ( V_2 -> V_34 ) ) ;
F_11 ( V_2 ) ;
V_2 -> V_36 -> V_57 -> error = - V_81 ;
F_32 ( & V_2 -> V_149 ) ;
}
V_148 = 0 ;
}
F_19 ( & V_2 -> V_40 ) ;
if ( V_148 != - 1 )
F_56 ( V_2 -> V_34 , F_57 ( V_148 ) ) ;
}
static void F_58 ( unsigned long V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_147 ;
struct V_41 * V_42 ;
F_21 ( & V_2 -> V_40 ) ;
if ( ! V_2 -> V_36 )
goto V_150;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 )
goto V_150;
if ( V_42 -> V_18 & V_112 )
F_33 ( V_2 ) ;
else
F_31 ( V_2 ) ;
if ( V_2 -> V_45 == 0 ) {
F_8 ( V_2 , V_119 , 0 ) ;
F_32 ( & V_2 -> V_149 ) ;
}
V_150:
F_19 ( & V_2 -> V_40 ) ;
}
static void F_59 ( unsigned long V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_147 ;
struct V_41 * V_42 ;
F_21 ( & V_2 -> V_40 ) ;
if ( ! V_2 -> V_36 )
goto V_150;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 )
goto V_150;
F_60 ( L_9 ) ;
V_42 -> error = - V_60 ;
F_32 ( & V_2 -> V_149 ) ;
V_150:
F_19 ( & V_2 -> V_40 ) ;
}
static void F_61 ( unsigned long V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_147 ;
struct V_41 * V_42 ;
F_21 ( & V_2 -> V_40 ) ;
if ( ! V_2 -> V_36 )
goto V_150;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 )
goto V_150;
F_60 ( L_10 ) ;
V_42 -> error = - V_83 ;
F_32 ( & V_2 -> V_149 ) ;
V_150:
F_19 ( & V_2 -> V_40 ) ;
}
static void F_62 ( unsigned long V_147 )
{
struct V_1 * V_2 = (struct V_1 * ) V_147 ;
struct V_41 * V_42 ;
F_21 ( & V_2 -> V_40 ) ;
F_40 ( ! V_2 -> V_36 ) ;
if ( ! V_2 -> V_36 )
goto V_150;
V_42 = F_54 ( V_2 ) ;
if ( ! V_42 )
goto V_150;
F_39 ( V_2 , V_42 ) ;
V_150:
F_19 ( & V_2 -> V_40 ) ;
}
static T_3 F_63 ( int V_151 , void * V_152 )
{
struct V_1 * V_2 = V_152 ;
int V_73 ;
V_73 = F_7 ( V_2 -> V_9 + V_33 ) ;
if ( V_73 == 0xff || V_73 == 0x00 )
return V_153 ;
V_2 -> V_73 |= V_73 ;
if ( V_73 & V_80 )
F_32 ( & V_2 -> V_146 ) ;
if ( V_73 & V_154 )
F_32 ( & V_2 -> V_98 ) ;
if ( V_73 & V_85 )
F_64 ( & V_2 -> V_155 ) ;
if ( V_73 & V_82 )
F_64 ( & V_2 -> V_156 ) ;
if ( V_73 & V_157 )
F_32 ( & V_2 -> V_149 ) ;
return V_158 ;
}
static int F_65 ( struct V_159 * V_160 )
{
struct V_127 * V_34 ;
struct V_1 * V_2 ;
V_34 = F_66 ( sizeof( struct V_1 ) , V_160 ) ;
if ( ! V_34 )
return - V_161 ;
V_2 = F_43 ( V_34 ) ;
V_2 -> V_34 = V_34 ;
V_2 -> V_38 = - 1 ;
V_34 -> V_162 = & V_163 ;
V_34 -> V_164 = 375000 ;
V_34 -> V_165 = 24000000 ;
V_34 -> V_166 = V_167 | V_168 ;
V_34 -> V_169 = V_170 ;
F_67 ( & V_2 -> V_40 ) ;
F_68 ( & V_2 -> V_140 ) ;
V_2 -> V_140 . V_42 = ( unsigned long ) V_2 ;
V_2 -> V_140 . V_171 = F_52 ;
V_34 -> V_172 = 128 ;
V_34 -> V_173 = 65536 ;
V_34 -> V_174 = V_34 -> V_173 ;
V_34 -> V_175 = 4087 ;
V_34 -> V_176 = V_34 -> V_173 ;
F_69 ( V_160 , V_34 ) ;
return 0 ;
}
static void F_70 ( struct V_159 * V_160 )
{
struct V_127 * V_34 ;
struct V_1 * V_2 ;
V_34 = F_71 ( V_160 ) ;
if ( ! V_34 )
return;
V_2 = F_43 ( V_34 ) ;
F_2 ( V_2 == NULL ) ;
F_72 ( & V_2 -> V_140 ) ;
F_73 ( V_34 ) ;
F_69 ( V_160 , NULL ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_51 , V_177 , V_178 ;
int V_179 ;
for ( V_51 = 0 ; V_51 < F_75 ( V_180 ) ; V_51 ++ ) {
if ( ! F_76 ( V_180 [ V_51 ] , 2 , V_181 ) )
continue;
for ( V_177 = 0 ; V_177 < F_75 ( V_182 ) ; V_177 ++ ) {
V_179 = 0xFFFF ;
V_2 -> V_3 = V_180 [ V_51 ] ;
V_2 -> V_4 = V_182 [ V_177 ] ;
F_1 ( V_2 ) ;
F_3 ( V_183 , V_180 [ V_51 ] ) ;
V_179 = F_7 ( V_180 [ V_51 ] + 1 ) << 8 ;
F_3 ( V_184 , V_180 [ V_51 ] ) ;
V_179 |= F_7 ( V_180 [ V_51 ] + 1 ) ;
F_4 ( V_2 ) ;
for ( V_178 = 0 ; V_178 < F_75 ( V_185 ) ; V_178 ++ ) {
if ( V_179 == V_185 [ V_178 ] ) {
V_2 -> V_186 = V_179 ;
return 0 ;
}
}
if ( V_179 != 0xFFFF ) {
F_53 ( L_11 ,
V_179 , V_180 [ V_51 ] ) ;
}
}
F_77 ( V_180 [ V_51 ] , 2 ) ;
}
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
return - V_187 ;
}
static int F_78 ( struct V_1 * V_2 , int V_9 )
{
if ( V_9 & 0x7 )
return - V_111 ;
if ( ! F_76 ( V_9 , 8 , V_181 ) )
return - V_126 ;
V_2 -> V_9 = V_9 ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_77 ( V_2 -> V_9 , 8 ) ;
V_2 -> V_9 = 0 ;
if ( V_2 -> V_3 )
F_77 ( V_2 -> V_3 , 2 ) ;
V_2 -> V_3 = 0 ;
}
static void F_80 ( struct V_1 * V_2 , int V_38 )
{
if ( V_38 < 0 )
return;
if ( F_81 ( V_38 , V_181 ) )
goto V_188;
V_2 -> V_54 = F_82 ( V_189 ,
V_190 | V_191 | V_192 | V_193 ) ;
if ( ! V_2 -> V_54 )
goto free;
V_2 -> V_116 = F_83 ( F_84 ( V_2 -> V_34 ) , V_2 -> V_54 ,
V_189 , V_194 ) ;
if ( F_85 ( F_84 ( V_2 -> V_34 ) , V_2 -> V_116 ) )
goto V_195;
if ( ( V_2 -> V_116 & 0xffff ) != 0 )
goto V_196;
else if ( V_2 -> V_116 >= 0x1000000 )
goto V_196;
V_2 -> V_38 = V_38 ;
return;
V_196:
F_2 ( 1 ) ;
F_86 ( F_84 ( V_2 -> V_34 ) , V_2 -> V_116 ,
V_189 , V_194 ) ;
V_2 -> V_116 = 0 ;
V_195:
V_195 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
free:
F_87 ( V_38 ) ;
V_188:
F_46 ( V_181 L_12 ,
V_38 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
if ( V_2 -> V_54 ) {
F_86 ( F_84 ( V_2 -> V_34 ) , V_2 -> V_116 ,
V_189 , V_194 ) ;
V_195 ( V_2 -> V_54 ) ;
}
if ( V_2 -> V_38 >= 0 )
F_87 ( V_2 -> V_38 ) ;
V_2 -> V_38 = - 1 ;
V_2 -> V_54 = NULL ;
V_2 -> V_116 = 0 ;
}
static int F_89 ( struct V_1 * V_2 , int V_151 )
{
int V_197 ;
F_90 ( & V_2 -> V_146 , F_55 ,
( unsigned long ) V_2 ) ;
F_90 ( & V_2 -> V_98 , F_58 ,
( unsigned long ) V_2 ) ;
F_90 ( & V_2 -> V_155 , F_59 ,
( unsigned long ) V_2 ) ;
F_90 ( & V_2 -> V_156 , F_61 ,
( unsigned long ) V_2 ) ;
F_90 ( & V_2 -> V_149 , F_62 ,
( unsigned long ) V_2 ) ;
V_197 = F_91 ( V_151 , F_63 , V_198 , V_181 , V_2 ) ;
if ( V_197 )
return V_197 ;
V_2 -> V_151 = V_151 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_151 )
return;
F_93 ( V_2 -> V_151 , V_2 ) ;
V_2 -> V_151 = 0 ;
F_94 ( & V_2 -> V_146 ) ;
F_94 ( & V_2 -> V_98 ) ;
F_94 ( & V_2 -> V_155 ) ;
F_94 ( & V_2 -> V_156 ) ;
F_94 ( & V_2 -> V_149 ) ;
}
static int F_95 ( struct V_1 * V_2 ,
int V_9 , int V_151 , int V_38 )
{
int V_197 ;
V_197 = F_78 ( V_2 , V_9 ) ;
if ( V_197 )
return V_197 ;
V_197 = F_89 ( V_2 , V_151 ) ;
if ( V_197 )
return V_197 ;
F_80 ( V_2 , V_38 ) ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_88 ( V_2 ) ;
F_92 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( V_2 , V_199 , 1 ) ;
F_5 ( V_2 , V_199 , 0 ) ;
F_5 ( V_2 , V_200 , V_201 ) ;
F_5 ( V_2 , V_202 , V_203 ) ;
F_5 ( V_2 , V_204 , V_2 -> V_9 >> 8 ) ;
F_5 ( V_2 , V_205 , V_2 -> V_9 & 0xff ) ;
F_5 ( V_2 , V_206 , V_2 -> V_151 ) ;
if ( V_2 -> V_38 >= 0 )
F_5 ( V_2 , V_207 , V_2 -> V_38 ) ;
F_5 ( V_2 , V_208 , 1 ) ;
F_5 ( V_2 , V_209 , 0x20 ) ;
F_4 ( V_2 ) ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_9 , V_151 , V_38 ;
F_1 ( V_2 ) ;
F_5 ( V_2 , V_200 , V_201 ) ;
V_9 = F_6 ( V_2 , V_204 ) << 8 ;
V_9 |= F_6 ( V_2 , V_205 ) ;
V_151 = F_6 ( V_2 , V_206 ) ;
V_38 = F_6 ( V_2 , V_207 ) ;
F_4 ( V_2 ) ;
if ( V_9 != V_2 -> V_9 )
return 0 ;
if ( V_151 != V_2 -> V_151 )
return 0 ;
if ( ( V_38 != V_2 -> V_38 ) && ( V_2 -> V_38 != - 1 ) )
return 0 ;
return 1 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_5 ( V_2 , V_200 , V_201 ) ;
F_5 ( V_2 , V_208 , 0 ) ;
F_4 ( V_2 ) ;
}
static int F_100 ( struct V_159 * V_160 , int V_9 , int V_151 , int V_38 ,
int V_210 )
{
struct V_1 * V_2 = NULL ;
struct V_127 * V_34 = NULL ;
int V_197 ;
V_197 = F_65 ( V_160 ) ;
if ( V_197 )
return V_197 ;
V_34 = F_71 ( V_160 ) ;
V_2 = F_43 ( V_34 ) ;
V_197 = F_74 ( V_2 ) ;
if ( V_197 ) {
if ( V_210 && ( V_197 == - V_187 ) ) {
F_46 ( V_181 L_13 ) ;
} else {
F_70 ( V_160 ) ;
return V_197 ;
}
}
V_197 = F_95 ( V_2 , V_9 , V_151 , V_38 ) ;
if ( V_197 ) {
F_96 ( V_2 ) ;
F_70 ( V_160 ) ;
return V_197 ;
}
if ( V_210 ) {
if ( ( V_2 -> V_3 != 0 ) && ! F_98 ( V_2 ) ) {
F_46 ( V_181 L_14 ) ;
F_97 ( V_2 ) ;
}
} else
F_97 ( V_2 ) ;
#ifdef F_101
if ( V_2 -> V_3 ) {
F_1 ( V_2 ) ;
F_5 ( V_2 , V_211 , 0xA0 ) ;
F_4 ( V_2 ) ;
}
#endif
F_51 ( 5 ) ;
F_10 ( V_2 ) ;
F_102 ( V_34 ) ;
F_103 ( L_15 , F_13 ( V_34 ) ) ;
if ( V_2 -> V_186 != 0 )
F_104 ( L_16 , ( int ) V_2 -> V_186 ) ;
F_104 ( L_17 , ( int ) V_2 -> V_9 , ( int ) V_2 -> V_151 ) ;
if ( V_2 -> V_38 >= 0 )
F_104 ( L_18 , ( int ) V_2 -> V_38 ) ;
else
F_104 ( L_19 ) ;
if ( V_210 )
F_104 ( L_20 ) ;
F_104 ( L_21 ) ;
return 0 ;
}
static void F_105 ( struct V_159 * V_160 , int V_210 )
{
struct V_127 * V_34 = F_71 ( V_160 ) ;
struct V_1 * V_2 ;
if ( ! V_34 )
return;
V_2 = F_43 ( V_34 ) ;
F_106 ( V_34 ) ;
if ( ! V_210 )
F_99 ( V_2 ) ;
F_96 ( V_2 ) ;
F_70 ( V_160 ) ;
}
static int F_107 ( struct V_212 * V_160 )
{
return F_100 ( & V_160 -> V_160 , V_213 , V_214 , V_215 , 0 ) ;
}
static int F_108 ( struct V_212 * V_160 )
{
F_105 ( & V_160 -> V_160 , 0 ) ;
return 0 ;
}
static int
F_109 ( struct V_216 * V_217 , const struct V_218 * V_152 )
{
int V_219 , V_151 , V_38 ;
V_219 = F_110 ( V_217 , 0 ) ;
V_151 = F_111 ( V_217 , 0 ) ;
if ( F_112 ( V_217 , 0 ) )
V_38 = F_113 ( V_217 , 0 ) ;
else
V_38 = - 1 ;
F_60 ( L_22 , V_219 , V_151 , V_38 ) ;
return F_100 ( & V_217 -> V_160 , V_219 , V_151 , V_38 , 1 ) ;
}
static void F_114 ( struct V_216 * V_160 )
{
F_105 ( & V_160 -> V_160 , 1 ) ;
}
static int F_115 ( struct V_212 * V_160 ,
T_4 V_220 )
{
struct V_127 * V_34 = F_116 ( V_160 ) ;
struct V_1 * V_2 ;
if ( V_34 == NULL )
return 0 ;
F_60 ( L_23 ) ;
V_2 = F_43 ( V_34 ) ;
F_99 ( V_2 ) ;
return 0 ;
}
static int F_117 ( struct V_212 * V_160 )
{
struct V_127 * V_34 = F_116 ( V_160 ) ;
struct V_1 * V_2 ;
if ( V_34 == NULL )
return 0 ;
F_60 ( L_24 ) ;
V_2 = F_43 ( V_34 ) ;
F_97 ( V_2 ) ;
F_51 ( 5 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_118 ( struct V_216 * V_216 , T_4 V_220 )
{
struct V_127 * V_34 = F_71 ( & V_216 -> V_160 ) ;
if ( V_34 == NULL )
return 0 ;
F_60 ( L_23 ) ;
return 0 ;
}
static int F_119 ( struct V_216 * V_216 )
{
struct V_127 * V_34 = F_71 ( & V_216 -> V_160 ) ;
struct V_1 * V_2 ;
if ( V_34 == NULL )
return 0 ;
F_60 ( L_24 ) ;
V_2 = F_43 ( V_34 ) ;
if ( V_2 -> V_3 != 0 ) {
if ( ! F_98 ( V_2 ) ) {
F_46 ( V_181 L_14 ) ;
F_97 ( V_2 ) ;
}
}
F_51 ( 5 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int T_5 F_120 ( void )
{
int V_221 ;
F_103 ( V_181
L_25 ) ;
F_103 ( V_181 L_26 ) ;
#ifdef F_121
if ( ! V_222 ) {
V_221 = F_122 ( & V_223 ) ;
if ( V_221 < 0 )
return V_221 ;
}
#endif
if ( V_222 ) {
V_221 = F_123 ( & V_224 ) ;
if ( V_221 < 0 )
return V_221 ;
V_225 = F_124 ( V_181 , - 1 ) ;
if ( ! V_225 ) {
F_125 ( & V_224 ) ;
return - V_161 ;
}
V_221 = F_126 ( V_225 ) ;
if ( V_221 ) {
F_127 ( V_225 ) ;
F_125 ( & V_224 ) ;
return V_221 ;
}
}
return 0 ;
}
static void T_6 F_128 ( void )
{
#ifdef F_121
if ( ! V_222 )
F_129 ( & V_223 ) ;
#endif
if ( V_222 ) {
F_130 ( V_225 ) ;
F_125 ( & V_224 ) ;
}
F_53 ( L_27 ) ;
}
