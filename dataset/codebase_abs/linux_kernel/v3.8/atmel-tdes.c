static int F_1 ( struct V_1 * * V_2 , T_1 * V_3 ,
void * V_4 , T_1 V_5 , T_1 V_6 , int V_7 )
{
unsigned int V_8 , V_9 = 0 ;
while ( V_5 && V_6 ) {
V_8 = F_2 ( ( * V_2 ) -> V_10 - * V_3 , V_6 ) ;
V_8 = F_2 ( V_8 , V_5 ) ;
if ( ! V_8 )
return V_9 ;
F_3 ( V_4 + V_9 , * V_2 , * V_3 , V_8 , V_7 ) ;
V_9 += V_8 ;
V_5 -= V_8 ;
* V_3 += V_8 ;
V_6 -= V_8 ;
if ( * V_3 == ( * V_2 ) -> V_10 ) {
* V_2 = F_4 ( * V_2 ) ;
if ( * V_2 )
* V_3 = 0 ;
else
V_6 = 0 ;
}
}
return V_9 ;
}
static inline T_2 F_5 ( struct V_11 * V_12 , T_2 V_3 )
{
return F_6 ( V_12 -> V_13 + V_3 ) ;
}
static inline void F_7 ( struct V_11 * V_12 ,
T_2 V_3 , T_2 V_14 )
{
F_8 ( V_14 , V_12 -> V_13 + V_3 ) ;
}
static void F_9 ( struct V_11 * V_12 , T_2 V_3 ,
T_2 * V_14 , int V_8 )
{
for (; V_8 -- ; V_14 ++ , V_3 += 4 )
F_7 ( V_12 , V_3 , * V_14 ) ;
}
static struct V_11 * F_10 ( struct V_15 * V_16 )
{
struct V_11 * V_17 = NULL ;
struct V_11 * V_18 ;
F_11 ( & V_19 . V_20 ) ;
if ( ! V_16 -> V_12 ) {
F_12 (tmp, &atmel_tdes.dev_list, list) {
V_17 = V_18 ;
break;
}
V_16 -> V_12 = V_17 ;
} else {
V_17 = V_16 -> V_12 ;
}
F_13 ( & V_19 . V_20 ) ;
return V_17 ;
}
static int F_14 ( struct V_11 * V_12 )
{
F_15 ( V_12 -> V_21 ) ;
if ( ! ( V_12 -> V_22 & V_23 ) ) {
F_7 ( V_12 , V_24 , V_25 ) ;
V_12 -> V_22 |= V_23 ;
V_12 -> V_26 = 0 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
int V_26 ;
T_2 V_27 = 0 , V_28 = V_29 ;
V_26 = F_14 ( V_12 ) ;
if ( V_26 )
return V_26 ;
F_7 ( V_12 , V_30 , V_31 | V_32 ) ;
if ( V_12 -> V_16 -> V_33 > ( V_34 << 1 ) ) {
V_28 |= V_35 ;
V_28 |= V_36 ;
} else if ( V_12 -> V_16 -> V_33 > V_34 ) {
V_28 |= V_37 ;
V_28 |= V_36 ;
} else {
V_28 |= V_38 ;
}
if ( V_12 -> V_22 & V_39 ) {
V_28 |= V_40 ;
} else if ( V_12 -> V_22 & V_41 ) {
V_28 |= V_42 ;
if ( V_12 -> V_22 & V_43 )
V_28 |= V_44 ;
else if ( V_12 -> V_22 & V_45 )
V_28 |= V_46 ;
else if ( V_12 -> V_22 & V_47 )
V_28 |= V_48 ;
} else if ( V_12 -> V_22 & V_49 ) {
V_28 |= V_50 ;
}
if ( ( V_12 -> V_22 & V_51 ) || ( V_12 -> V_22 & V_49 ) )
V_28 |= V_52 ;
F_7 ( V_12 , V_24 , V_27 ) ;
F_7 ( V_12 , V_53 , V_28 ) ;
F_9 ( V_12 , V_54 , V_12 -> V_16 -> V_55 ,
V_12 -> V_16 -> V_33 >> 2 ) ;
if ( ( ( V_12 -> V_22 & V_39 ) || ( V_12 -> V_22 & V_41 ) ||
( V_12 -> V_22 & V_49 ) ) && V_12 -> V_56 -> V_57 ) {
F_9 ( V_12 , V_58 , V_12 -> V_56 -> V_57 , 2 ) ;
}
return 0 ;
}
static int F_17 ( struct V_11 * V_12 )
{
int V_26 = 0 ;
T_1 V_8 ;
F_7 ( V_12 , V_30 , V_31 | V_32 ) ;
if ( V_12 -> V_22 & V_59 ) {
F_18 ( V_12 -> V_60 , V_12 -> V_61 , 1 , V_62 ) ;
F_18 ( V_12 -> V_60 , V_12 -> V_63 , 1 , V_64 ) ;
} else {
F_19 ( V_12 -> V_60 , V_12 -> V_65 ,
V_12 -> V_66 , V_62 ) ;
V_8 = F_1 ( & V_12 -> V_61 , & V_12 -> V_67 ,
V_12 -> V_68 , V_12 -> V_5 , V_12 -> V_66 , 1 ) ;
if ( V_8 != V_12 -> V_66 ) {
V_26 = - V_69 ;
F_20 ( L_1 , V_8 ) ;
}
}
return V_26 ;
}
static int F_21 ( struct V_11 * V_12 )
{
int V_26 = - V_70 ;
V_12 -> V_71 = ( void * ) F_22 ( V_72 , 0 ) ;
V_12 -> V_68 = ( void * ) F_22 ( V_72 , 0 ) ;
V_12 -> V_5 = V_73 ;
V_12 -> V_5 &= ~ ( V_74 - 1 ) ;
if ( ! V_12 -> V_71 || ! V_12 -> V_68 ) {
F_23 ( V_12 -> V_60 , L_2 ) ;
goto V_75;
}
V_12 -> V_76 = F_24 ( V_12 -> V_60 , V_12 -> V_71 ,
V_12 -> V_5 , V_64 ) ;
if ( F_25 ( V_12 -> V_60 , V_12 -> V_76 ) ) {
F_23 ( V_12 -> V_60 , L_3 , V_12 -> V_5 ) ;
V_26 = - V_69 ;
goto V_77;
}
V_12 -> V_65 = F_24 ( V_12 -> V_60 , V_12 -> V_68 ,
V_12 -> V_5 , V_62 ) ;
if ( F_25 ( V_12 -> V_60 , V_12 -> V_65 ) ) {
F_23 ( V_12 -> V_60 , L_3 , V_12 -> V_5 ) ;
V_26 = - V_69 ;
goto V_78;
}
return 0 ;
V_78:
F_26 ( V_12 -> V_60 , V_12 -> V_76 , V_12 -> V_5 ,
V_64 ) ;
V_77:
F_27 ( ( unsigned long ) V_12 -> V_68 ) ;
F_27 ( ( unsigned long ) V_12 -> V_71 ) ;
V_75:
if ( V_26 )
F_20 ( L_4 , V_26 ) ;
return V_26 ;
}
static void F_28 ( struct V_11 * V_12 )
{
F_26 ( V_12 -> V_60 , V_12 -> V_65 , V_12 -> V_5 ,
V_62 ) ;
F_26 ( V_12 -> V_60 , V_12 -> V_76 , V_12 -> V_5 ,
V_64 ) ;
F_27 ( ( unsigned long ) V_12 -> V_68 ) ;
F_27 ( ( unsigned long ) V_12 -> V_71 ) ;
}
static int F_29 ( struct V_79 * V_80 , T_3 V_76 ,
T_3 V_65 , int V_10 )
{
struct V_15 * V_16 = F_30 ( V_80 ) ;
struct V_11 * V_12 = V_16 -> V_12 ;
int V_81 ;
V_12 -> V_66 = V_10 ;
if ( ! ( V_12 -> V_22 & V_59 ) ) {
F_19 ( V_12 -> V_60 , V_76 , V_10 ,
V_64 ) ;
}
if ( ( V_12 -> V_22 & V_41 ) && ( V_12 -> V_22 & V_43 ) )
V_81 = F_31 ( V_10 , sizeof( V_82 ) ) ;
else if ( ( V_12 -> V_22 & V_41 ) && ( V_12 -> V_22 & V_45 ) )
V_81 = F_31 ( V_10 , sizeof( V_83 ) ) ;
else
V_81 = F_31 ( V_10 , sizeof( T_2 ) ) ;
F_7 ( V_12 , V_30 , V_31 | V_32 ) ;
F_7 ( V_12 , V_84 , V_76 ) ;
F_7 ( V_12 , V_85 , V_81 ) ;
F_7 ( V_12 , V_86 , V_65 ) ;
F_7 ( V_12 , V_87 , V_81 ) ;
F_7 ( V_12 , V_88 , V_89 ) ;
F_7 ( V_12 , V_30 , V_90 | V_91 ) ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_79 * V_80 = F_33 (
F_34 ( V_12 -> V_56 ) ) ;
int V_26 , V_92 = 0 , V_93 , V_7 ;
T_1 V_8 ;
T_3 V_94 , V_95 ;
if ( F_35 ( V_12 -> V_63 ) && F_35 ( V_12 -> V_61 ) ) {
V_93 = F_36 ( ( T_2 ) V_12 -> V_63 -> V_3 , sizeof( T_2 ) ) ;
V_7 = F_36 ( ( T_2 ) V_12 -> V_61 -> V_3 , sizeof( T_2 ) ) ;
V_92 = V_93 && V_7 ;
}
if ( V_92 ) {
V_8 = F_2 ( V_12 -> V_6 , F_37 ( V_12 -> V_63 ) ) ;
V_8 = F_2 ( V_8 , F_37 ( V_12 -> V_61 ) ) ;
if ( V_8 != V_12 -> V_6 ) {
F_20 ( L_5 ) ;
return - V_69 ;
}
V_26 = F_38 ( V_12 -> V_60 , V_12 -> V_63 , 1 , V_64 ) ;
if ( ! V_26 ) {
F_23 ( V_12 -> V_60 , L_6 ) ;
return - V_69 ;
}
V_26 = F_38 ( V_12 -> V_60 , V_12 -> V_61 , 1 ,
V_62 ) ;
if ( ! V_26 ) {
F_23 ( V_12 -> V_60 , L_6 ) ;
F_18 ( V_12 -> V_60 , V_12 -> V_63 , 1 ,
V_64 ) ;
return - V_69 ;
}
V_94 = F_39 ( V_12 -> V_63 ) ;
V_95 = F_39 ( V_12 -> V_61 ) ;
V_12 -> V_22 |= V_59 ;
} else {
V_8 = F_1 ( & V_12 -> V_63 , & V_12 -> V_96 ,
V_12 -> V_71 , V_12 -> V_5 , V_12 -> V_6 , 0 ) ;
V_94 = V_12 -> V_76 ;
V_95 = V_12 -> V_65 ;
V_12 -> V_22 &= ~ V_59 ;
}
V_12 -> V_6 -= V_8 ;
V_26 = F_29 ( V_80 , V_94 , V_95 , V_8 ) ;
if ( V_26 ) {
F_18 ( V_12 -> V_60 , V_12 -> V_63 , 1 , V_64 ) ;
F_18 ( V_12 -> V_60 , V_12 -> V_61 , 1 , V_64 ) ;
}
return V_26 ;
}
static void F_40 ( struct V_11 * V_12 , int V_26 )
{
struct V_97 * V_56 = V_12 -> V_56 ;
F_41 ( V_12 -> V_21 ) ;
V_12 -> V_22 &= ~ V_98 ;
V_56 -> V_99 . V_100 ( & V_56 -> V_99 , V_26 ) ;
}
static int F_42 ( struct V_11 * V_12 ,
struct V_97 * V_56 )
{
struct V_101 * V_102 , * V_103 ;
struct V_15 * V_16 ;
struct V_104 * V_105 ;
unsigned long V_22 ;
int V_26 , V_106 = 0 ;
F_43 ( & V_12 -> V_20 , V_22 ) ;
if ( V_56 )
V_106 = F_44 ( & V_12 -> V_107 , V_56 ) ;
if ( V_12 -> V_22 & V_98 ) {
F_45 ( & V_12 -> V_20 , V_22 ) ;
return V_106 ;
}
V_103 = F_46 ( & V_12 -> V_107 ) ;
V_102 = F_47 ( & V_12 -> V_107 ) ;
if ( V_102 )
V_12 -> V_22 |= V_98 ;
F_45 ( & V_12 -> V_20 , V_22 ) ;
if ( ! V_102 )
return V_106 ;
if ( V_103 )
V_103 -> V_100 ( V_103 , - V_108 ) ;
V_56 = F_48 ( V_102 ) ;
V_12 -> V_56 = V_56 ;
V_12 -> V_6 = V_56 -> V_109 ;
V_12 -> V_96 = 0 ;
V_12 -> V_63 = V_56 -> V_110 ;
V_12 -> V_67 = 0 ;
V_12 -> V_61 = V_56 -> V_111 ;
V_105 = F_49 ( V_56 ) ;
V_16 = F_50 ( F_34 ( V_56 ) ) ;
V_105 -> V_112 &= V_113 ;
V_12 -> V_22 = ( V_12 -> V_22 & ~ V_113 ) | V_105 -> V_112 ;
V_12 -> V_16 = V_16 ;
V_16 -> V_12 = V_12 ;
V_26 = F_16 ( V_12 ) ;
if ( ! V_26 )
V_26 = F_32 ( V_12 ) ;
if ( V_26 ) {
F_40 ( V_12 , V_26 ) ;
F_51 ( & V_12 -> V_114 ) ;
}
return V_106 ;
}
static int F_52 ( struct V_97 * V_56 , unsigned long V_112 )
{
struct V_15 * V_16 = F_50 (
F_34 ( V_56 ) ) ;
struct V_104 * V_105 = F_49 ( V_56 ) ;
struct V_11 * V_12 ;
if ( V_112 & V_43 ) {
if ( ! F_36 ( V_56 -> V_109 , V_115 ) ) {
F_20 ( L_7 ) ;
return - V_69 ;
}
} else if ( V_112 & V_45 ) {
if ( ! F_36 ( V_56 -> V_109 , V_116 ) ) {
F_20 ( L_8 ) ;
return - V_69 ;
}
} else if ( V_112 & V_47 ) {
if ( ! F_36 ( V_56 -> V_109 , V_117 ) ) {
F_20 ( L_9 ) ;
return - V_69 ;
}
} else if ( ! F_36 ( V_56 -> V_109 , V_74 ) ) {
F_20 ( L_10 ) ;
return - V_69 ;
}
V_12 = F_10 ( V_16 ) ;
if ( ! V_12 )
return - V_118 ;
V_105 -> V_112 = V_112 ;
return F_42 ( V_12 , V_56 ) ;
}
static int F_53 ( struct V_119 * V_80 , const V_82 * V_55 ,
unsigned int V_33 )
{
T_2 V_18 [ V_120 ] ;
int V_26 ;
struct V_79 * V_121 = F_33 ( V_80 ) ;
struct V_15 * V_16 = F_50 ( V_80 ) ;
if ( V_33 != V_34 ) {
F_54 ( V_80 , V_122 ) ;
return - V_69 ;
}
V_26 = F_55 ( V_18 , V_55 ) ;
if ( V_26 == 0 && ( V_121 -> V_123 & V_124 ) ) {
V_121 -> V_123 |= V_125 ;
return - V_69 ;
}
memcpy ( V_16 -> V_55 , V_55 , V_33 ) ;
V_16 -> V_33 = V_33 ;
return 0 ;
}
static int F_56 ( struct V_119 * V_80 , const V_82 * V_55 ,
unsigned int V_33 )
{
struct V_15 * V_16 = F_50 ( V_80 ) ;
const char * V_126 ;
V_126 = F_57 ( F_33 ( V_80 ) ) ;
if ( strstr ( V_126 , L_11 ) && ( V_33 != 2 * V_34 ) ) {
F_54 ( V_80 , V_122 ) ;
return - V_69 ;
} else if ( ( V_33 != 2 * V_34 ) && ( V_33 != 3 * V_34 ) ) {
F_54 ( V_80 , V_122 ) ;
return - V_69 ;
}
memcpy ( V_16 -> V_55 , V_55 , V_33 ) ;
V_16 -> V_33 = V_33 ;
return 0 ;
}
static int F_58 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_51 ) ;
}
static int F_59 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , 0 ) ;
}
static int F_60 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_51 | V_39 ) ;
}
static int F_61 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_39 ) ;
}
static int F_62 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_51 | V_41 ) ;
}
static int F_63 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_41 ) ;
}
static int F_64 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_51 | V_41 |
V_43 ) ;
}
static int F_65 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_41 | V_43 ) ;
}
static int F_66 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_51 | V_41 |
V_45 ) ;
}
static int F_67 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_41 | V_45 ) ;
}
static int F_68 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_51 | V_41 |
V_47 ) ;
}
static int F_69 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_41 | V_47 ) ;
}
static int F_70 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_51 | V_49 ) ;
}
static int F_71 ( struct V_97 * V_56 )
{
return F_52 ( V_56 , V_49 ) ;
}
static int F_72 ( struct V_79 * V_80 )
{
V_80 -> V_127 . V_128 = sizeof( struct V_104 ) ;
return 0 ;
}
static void F_73 ( struct V_79 * V_80 )
{
}
static void F_74 ( unsigned long V_129 )
{
struct V_11 * V_12 = (struct V_11 * ) V_129 ;
F_42 ( V_12 , NULL ) ;
}
static void F_75 ( unsigned long V_129 )
{
struct V_11 * V_12 = (struct V_11 * ) V_129 ;
int V_26 ;
V_26 = F_17 ( V_12 ) ;
V_26 = V_12 -> V_26 ? : V_26 ;
if ( V_12 -> V_6 && ! V_26 ) {
V_26 = F_32 ( V_12 ) ;
if ( ! V_26 )
return;
}
F_40 ( V_12 , V_26 ) ;
F_42 ( V_12 , NULL ) ;
}
static T_4 F_76 ( int V_130 , void * V_131 )
{
struct V_11 * V_17 = V_131 ;
T_2 V_132 ;
V_132 = F_5 ( V_17 , V_133 ) ;
if ( V_132 & F_5 ( V_17 , V_134 ) ) {
F_7 ( V_17 , V_135 , V_132 ) ;
if ( V_98 & V_17 -> V_22 )
F_51 ( & V_17 -> V_136 ) ;
else
F_77 ( V_17 -> V_60 , L_12 ) ;
return V_137 ;
}
return V_138 ;
}
static void F_78 ( struct V_11 * V_12 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < F_79 ( V_140 ) ; V_139 ++ )
F_80 ( & V_140 [ V_139 ] ) ;
}
static int F_81 ( struct V_11 * V_12 )
{
int V_26 , V_139 , V_141 ;
for ( V_139 = 0 ; V_139 < F_79 ( V_140 ) ; V_139 ++ ) {
V_26 = F_82 ( & V_140 [ V_139 ] ) ;
if ( V_26 )
goto V_142;
}
return 0 ;
V_142:
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ )
F_80 ( & V_140 [ V_141 ] ) ;
return V_26 ;
}
static int F_83 ( struct V_143 * V_144 )
{
struct V_11 * V_17 ;
struct V_145 * V_60 = & V_144 -> V_60 ;
struct V_146 * V_147 ;
unsigned long V_148 ;
int V_26 ;
V_17 = F_84 ( sizeof( struct V_11 ) , V_72 ) ;
if ( V_17 == NULL ) {
F_23 ( V_60 , L_13 ) ;
V_26 = - V_70 ;
goto V_149;
}
V_17 -> V_60 = V_60 ;
F_85 ( V_144 , V_17 ) ;
F_86 ( & V_17 -> V_150 ) ;
F_87 ( & V_17 -> V_136 , F_75 ,
( unsigned long ) V_17 ) ;
F_87 ( & V_17 -> V_114 , F_74 ,
( unsigned long ) V_17 ) ;
F_88 ( & V_17 -> V_107 , V_151 ) ;
V_17 -> V_130 = - 1 ;
V_147 = F_89 ( V_144 , V_152 , 0 ) ;
if ( ! V_147 ) {
F_23 ( V_60 , L_14 ) ;
V_26 = - V_118 ;
goto V_153;
}
V_17 -> V_154 = V_147 -> V_155 ;
V_148 = F_90 ( V_147 ) ;
V_17 -> V_130 = F_91 ( V_144 , 0 ) ;
if ( V_17 -> V_130 < 0 ) {
F_23 ( V_60 , L_15 ) ;
V_26 = V_17 -> V_130 ;
goto V_153;
}
V_26 = F_92 ( V_17 -> V_130 , F_76 , V_156 ,
L_16 , V_17 ) ;
if ( V_26 ) {
F_23 ( V_60 , L_17 ) ;
goto V_157;
}
V_17 -> V_21 = F_93 ( & V_144 -> V_60 , NULL ) ;
if ( F_94 ( V_17 -> V_21 ) ) {
F_23 ( V_60 , L_18 ) ;
V_26 = F_95 ( V_17 -> V_21 ) ;
goto V_158;
}
V_17 -> V_13 = F_96 ( V_17 -> V_154 , V_148 ) ;
if ( ! V_17 -> V_13 ) {
F_23 ( V_60 , L_19 ) ;
V_26 = - V_70 ;
goto V_159;
}
V_26 = F_21 ( V_17 ) ;
if ( V_26 )
goto V_160;
F_97 ( & V_19 . V_20 ) ;
F_98 ( & V_17 -> V_150 , & V_19 . V_161 ) ;
F_99 ( & V_19 . V_20 ) ;
V_26 = F_81 ( V_17 ) ;
if ( V_26 )
goto V_162;
F_100 ( V_60 , L_20 ) ;
return 0 ;
V_162:
F_97 ( & V_19 . V_20 ) ;
F_101 ( & V_17 -> V_150 ) ;
F_99 ( & V_19 . V_20 ) ;
F_28 ( V_17 ) ;
V_160:
F_102 ( V_17 -> V_13 ) ;
V_159:
F_103 ( V_17 -> V_21 ) ;
V_158:
F_104 ( V_17 -> V_130 , V_17 ) ;
V_157:
V_153:
F_105 ( & V_17 -> V_136 ) ;
F_105 ( & V_17 -> V_114 ) ;
F_106 ( V_17 ) ;
V_17 = NULL ;
V_149:
F_23 ( V_60 , L_21 ) ;
return V_26 ;
}
static int F_107 ( struct V_143 * V_144 )
{
static struct V_11 * V_17 ;
V_17 = F_108 ( V_144 ) ;
if ( ! V_17 )
return - V_118 ;
F_97 ( & V_19 . V_20 ) ;
F_101 ( & V_17 -> V_150 ) ;
F_99 ( & V_19 . V_20 ) ;
F_78 ( V_17 ) ;
F_105 ( & V_17 -> V_136 ) ;
F_105 ( & V_17 -> V_114 ) ;
F_28 ( V_17 ) ;
F_102 ( V_17 -> V_13 ) ;
F_103 ( V_17 -> V_21 ) ;
if ( V_17 -> V_130 >= 0 )
F_104 ( V_17 -> V_130 , V_17 ) ;
F_106 ( V_17 ) ;
V_17 = NULL ;
return 0 ;
}
