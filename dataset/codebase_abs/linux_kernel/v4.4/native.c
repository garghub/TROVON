static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 , bool V_6 )
{
T_1 V_7 = F_2 ( V_2 , V_8 ) ;
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
int V_13 = 0 ;
F_3 ( & V_2 -> V_14 ) ;
F_4 ( L_1 , V_3 ) ;
F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_8 , V_7 | V_3 ) ;
V_7 = F_2 ( V_2 , V_8 ) ;
while ( ( V_7 & V_5 ) != V_4 ) {
if ( F_7 ( V_10 , V_9 ) ) {
F_8 ( & V_2 -> V_15 , L_2 ) ;
V_13 = - V_16 ;
goto V_17;
}
if ( ! F_9 ( V_2 -> V_18 ) ) {
V_2 -> V_6 = V_6 ;
V_13 = - V_19 ;
goto V_17;
}
F_10 ( L_3 ,
V_7 | V_3 ) ;
F_11 () ;
V_7 = F_2 ( V_2 , V_8 ) ;
} ;
F_4 ( L_4 , V_3 ) ;
V_2 -> V_6 = V_6 ;
V_17:
F_12 ( V_2 , V_3 , V_13 ) ;
F_13 ( & V_2 -> V_14 ) ;
return V_13 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_4 ( L_5 ) ;
return F_1 ( V_2 , V_20 ,
V_21 ,
V_22 , true ) ;
}
int F_15 ( struct V_1 * V_2 )
{
F_4 ( L_6 ) ;
return F_1 ( V_2 , 0 , V_23 ,
V_22 , false ) ;
}
int F_16 ( struct V_1 * V_2 )
{
F_4 ( L_7 ) ;
return F_1 ( V_2 , V_24 ,
V_25 | V_23 ,
V_26 | V_22 ,
false ) ;
}
int F_17 ( struct V_1 * V_2 )
{
if ( ! F_9 ( V_2 -> V_18 ) ) {
F_18 ( 1 , L_8 ) ;
return - V_19 ;
}
if ( V_2 -> V_6 )
return 0 ;
return F_14 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
T_1 V_27 = F_20 ( V_2 , V_28 ) ;
T_1 V_7 = F_2 ( V_2 , V_8 ) ;
T_1 V_29 , V_30 ;
T_1 V_31 , V_32 ;
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
int V_13 = 0 ;
F_21 ( V_2 , V_33 ) ;
F_4 ( L_9 ) ;
if ( ! F_9 ( V_2 -> V_18 ) ) {
F_8 ( & V_2 -> V_15 , L_10 ) ;
V_13 = - V_19 ;
goto V_17;
}
if ( ( V_7 & V_22 ) != V_23 ) {
F_18 ( 1 , L_11 ) ;
F_15 ( V_2 ) ;
}
F_22 ( V_2 , V_28 ,
V_27 | V_33 ) ;
V_31 = F_23 () ;
V_27 = F_20 ( V_2 , V_28 ) ;
while ( ( V_27 & V_34 )
== V_35 ) {
if ( F_7 ( V_10 , V_9 ) ) {
F_8 ( & V_2 -> V_15 , L_12 ) ;
V_13 = - V_16 ;
goto V_17;
}
if ( ! F_9 ( V_2 -> V_18 ) ) {
V_13 = - V_19 ;
goto V_17;
}
V_29 = F_2 ( V_2 , V_36 ) ;
F_10 ( L_13 , V_27 , V_29 ) ;
if ( V_29 & V_37 ) {
V_30 = F_2 ( V_2 , V_38 ) ;
F_24 ( & V_2 -> V_15 , L_14 , V_29 , V_30 ) ;
F_6 ( V_2 , V_39 , V_40 ) ;
} else if ( V_29 ) {
F_24 ( & V_2 -> V_15 , L_15 , V_29 ) ;
F_6 ( V_2 , V_39 , V_41 ) ;
} else {
F_11 () ;
}
V_27 = F_20 ( V_2 , V_28 ) ;
} ;
V_32 = F_23 () ;
F_4 ( L_16 , V_32 - V_31 ) ;
F_22 ( V_2 , V_28 ,
V_27 & ~ V_33 ) ;
V_17:
F_25 ( V_2 , V_33 , V_13 ) ;
return V_13 ;
}
static int F_26 ( int V_42 )
{
return ( ( V_42 / 8 ) - 96 ) / 17 ;
}
int F_27 ( struct V_1 * V_2 )
{
V_2 -> V_43 = 0 ;
do {
V_2 -> V_43 ++ ;
V_2 -> V_42 = ( 1 << V_2 -> V_43 ) * V_44 ;
V_2 -> F_26 = F_26 ( V_2 -> V_42 ) ;
} while ( V_2 -> F_26 < V_2 -> V_45 );
F_28 ( V_2 -> V_42 > 0x100000 ) ;
if ( ! ( V_2 -> V_46 = (struct V_47 * )
F_29 ( V_48 | V_49 , V_2 -> V_43 ) ) ) {
F_30 ( L_17 ) ;
return - V_50 ;
}
F_4 ( L_18 ,
1 << V_2 -> V_43 , V_2 -> F_26 , V_2 -> V_45 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_51 ;
V_2 -> V_52 = ( V_53 * ) ( ( char * ) V_2 -> V_46 +
( ( V_2 -> F_26 + 3 ) * 128 ) ) ;
V_51 = F_32 ( V_2 -> V_46 ) & V_54 ;
V_51 |= ( ( V_2 -> V_42 >> ( 12 - V_55 ) ) - 1 ) & V_56 ;
V_51 |= V_57 ;
F_4 ( L_19 , V_2 -> V_46 , V_2 -> F_26 , V_2 -> V_52 , V_51 ) ;
F_22 ( V_2 , V_58 , V_51 ) ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_58 , 0 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_35 ( ( unsigned long ) V_2 -> V_46 , V_2 -> V_43 ) ;
V_2 -> V_46 = NULL ;
}
}
int F_36 ( struct V_59 * V_18 )
{
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
F_4 ( L_20 ) ;
F_37 ( V_18 , V_60 , V_61 ) ;
F_37 ( V_18 , V_62 , V_63 ) ;
while ( F_38 ( V_18 , V_62 ) & V_64 ) {
if ( F_7 ( V_10 , V_9 ) ) {
F_8 ( & V_18 -> V_15 , L_21 ) ;
return - V_16 ;
}
if ( ! F_9 ( V_18 ) )
return - V_19 ;
F_11 () ;
}
F_37 ( V_18 , V_65 , V_63 ) ;
while ( F_38 ( V_18 , V_65 ) & V_64 ) {
if ( F_7 ( V_10 , V_9 ) ) {
F_8 ( & V_18 -> V_15 , L_22 ) ;
return - V_16 ;
}
if ( ! F_9 ( V_18 ) )
return - V_19 ;
F_11 () ;
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
F_4 ( L_23 ) ;
F_6 ( V_2 , V_66 , V_63 ) ;
while ( F_2 ( V_2 , V_66 ) & V_64 ) {
if ( F_7 ( V_10 , V_9 ) ) {
F_8 ( & V_2 -> V_15 , L_24 ) ;
return - V_16 ;
}
if ( ! F_9 ( V_2 -> V_18 ) )
return - V_19 ;
F_11 () ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_67 , T_1 V_68 )
{
int V_13 ;
F_6 ( V_2 , V_69 , 0 ) ;
if ( ( V_13 = F_39 ( V_2 ) ) )
return V_13 ;
F_6 ( V_2 , V_70 , V_67 ) ;
F_6 ( V_2 , V_69 , V_68 ) ;
return 0 ;
}
static void F_41 ( struct V_71 * V_72 )
{
struct V_59 * V_18 = V_72 -> V_2 -> V_18 ;
T_1 V_73 ;
F_28 ( ! F_42 ( & V_72 -> V_2 -> V_74 ) ) ;
F_37 ( V_18 , V_75 ,
( ( T_1 ) F_43 ( V_72 -> V_76 -> V_77 . V_78 ) << 32 ) |
F_43 ( V_72 -> V_76 -> V_79 ) ) ;
F_37 ( V_18 , V_65 , V_80 ) ;
while ( 1 ) {
if ( ! F_9 ( V_18 ) )
break;
V_73 = F_38 ( V_18 , V_65 ) ;
if ( ! ( V_73 & V_64 ) )
break;
F_11 () ;
}
}
static int F_44 ( struct V_71 * V_72 ,
T_1 V_81 , T_1 V_82 )
{
T_1 V_83 ;
unsigned long V_9 = V_10 + ( V_11 * V_12 ) ;
int V_13 = 0 ;
F_45 ( V_72 , V_81 ) ;
F_28 ( ! V_72 -> V_2 -> V_6 ) ;
V_72 -> V_76 -> V_84 = F_46 ( V_82 ) ;
F_47 () ;
* ( V_72 -> V_2 -> V_52 ) = F_48 ( V_81 | 0 | V_72 -> V_85 ) ;
F_49 () ;
F_22 ( V_72 -> V_2 , V_86 , V_81 | V_72 -> V_85 ) ;
while ( 1 ) {
if ( F_7 ( V_10 , V_9 ) ) {
F_8 ( & V_72 -> V_2 -> V_15 , L_25 ) ;
V_13 = - V_16 ;
goto V_17;
}
if ( ! F_9 ( V_72 -> V_2 -> V_18 ) ) {
F_8 ( & V_72 -> V_2 -> V_15 , L_26 ) ;
V_13 = - V_19 ;
goto V_17;
}
V_83 = F_50 ( V_72 -> V_2 -> V_52 ) ;
if ( V_83 == ~ 0ULL ) {
F_30 ( L_27 ) ;
V_13 = - 1 ;
goto V_17;
}
if ( ( V_83 & ( V_87 | V_88 | V_89 ) ) ==
( V_81 | ( V_81 >> 16 ) | V_72 -> V_85 ) )
break;
F_51 () ;
}
V_17:
F_52 ( V_72 , V_81 , V_13 ) ;
return V_13 ;
}
static int F_53 ( struct V_71 * V_72 )
{
int V_13 = 0 ;
F_54 ( & V_72 -> V_2 -> V_74 ) ;
F_4 ( L_28 , V_90 , V_72 -> V_85 ) ;
if ( ! ( V_13 = F_44 ( V_72 , V_91 , V_92 ) ) )
V_72 -> V_93 = true ;
F_4 ( L_29 , V_90 , V_72 -> V_85 ) ;
F_55 ( & V_72 -> V_2 -> V_74 ) ;
return V_13 ;
}
static int F_56 ( struct V_71 * V_72 )
{
int V_13 = 0 ;
if ( ! ( V_72 -> V_76 -> V_84 & F_46 ( V_92 ) ) )
return V_13 ;
F_54 ( & V_72 -> V_2 -> V_74 ) ;
F_4 ( L_30 , V_90 , V_72 -> V_85 ) ;
if ( F_9 ( V_72 -> V_2 -> V_18 ) )
V_13 = F_44 ( V_72 , V_94 ,
V_92 | V_95 ) ;
V_72 -> V_76 -> V_84 = 0 ;
F_4 ( L_31 , V_90 , V_72 -> V_85 ) ;
F_55 ( & V_72 -> V_2 -> V_74 ) ;
return V_13 ;
}
static int F_57 ( struct V_71 * V_72 )
{
int V_13 = 0 ;
F_54 ( & V_72 -> V_2 -> V_74 ) ;
F_4 ( L_32 , V_90 , V_72 -> V_85 ) ;
if ( F_9 ( V_72 -> V_2 -> V_18 ) )
V_13 = F_44 ( V_72 , V_96 , 0 ) ;
if ( ! V_13 )
V_72 -> V_93 = false ;
F_41 ( V_72 ) ;
F_4 ( L_33 , V_90 , V_72 -> V_85 ) ;
F_55 ( & V_72 -> V_2 -> V_74 ) ;
return V_13 ;
}
void F_58 ( struct V_71 * V_72 )
{
if ( ! V_72 -> V_2 -> V_97 || V_72 -> V_98 ) {
V_72 -> V_99 = V_72 -> V_2 -> V_99 ;
V_72 -> V_100 = V_72 -> V_2 -> V_18 -> V_101 ;
} else {
V_72 -> V_99 = V_72 -> V_2 -> V_99 +
( V_72 -> V_2 -> V_102 + V_72 -> V_2 -> V_97 * V_72 -> V_85 ) ;
V_72 -> V_100 = V_72 -> V_2 -> V_97 ;
}
}
static int F_59 ( struct V_1 * V_2 )
{
int V_13 ;
F_60 ( & V_2 -> V_15 , L_34 ) ;
V_2 -> V_45 = V_2 -> V_103 ;
if ( V_2 -> V_46 == NULL ) {
if ( F_27 ( V_2 ) )
return - V_50 ;
}
F_31 ( V_2 ) ;
F_22 ( V_2 , V_28 , V_104 ) ;
F_22 ( V_2 , V_105 , 0xFFFFFFFFFFFFFFFFULL ) ;
F_22 ( V_2 , V_106 , V_107 | V_108 ) ;
V_2 -> V_109 = V_110 ;
if ( ( V_13 = F_61 ( V_2 ) ) )
return V_13 ;
if ( ( V_13 = F_62 ( V_2 ) ) )
goto V_111;
if ( ( V_13 = F_63 ( V_2 ) ) )
goto V_112;
return 0 ;
V_112:
F_64 ( V_2 ) ;
V_111:
F_65 ( V_2 ) ;
return V_13 ;
}
static T_1 F_66 ( struct V_71 * V_72 )
{
T_1 V_113 = 0 ;
F_67 ( V_113 ) ;
if ( V_72 -> V_98 )
V_113 |= V_114 ;
if ( F_68 ( V_115 ) & V_116 )
V_113 |= V_117 ;
if ( V_72 -> V_118 ) {
V_113 |= V_119 | ( F_69 () & V_120 ) ;
V_113 |= V_121 ;
} else {
V_113 |= V_122 | V_119 ;
V_113 &= ~ ( V_121 ) ;
if ( ! F_70 ( V_123 , V_124 ) )
V_113 |= V_125 ;
}
return V_113 ;
}
static int F_71 ( struct V_71 * V_72 , T_1 V_126 , T_1 V_127 )
{
T_2 V_78 ;
int V_128 , V_4 ;
F_58 ( V_72 ) ;
V_72 -> V_76 -> V_129 = 0 ;
V_72 -> V_76 -> V_79 = F_46 ( F_68 ( V_130 ) ) ;
V_72 -> V_76 -> V_131 = 0 ;
V_72 -> V_76 -> V_132 = F_48 ( F_68 ( V_133 ) ) ;
V_78 = V_123 -> V_78 ;
if ( V_72 -> V_118 )
V_78 = 0 ;
V_72 -> V_76 -> V_77 . V_134 = 0 ;
V_72 -> V_76 -> V_77 . V_78 = F_46 ( V_78 ) ;
V_72 -> V_76 -> V_113 = F_48 ( F_66 ( V_72 ) ) ;
V_72 -> V_76 -> V_77 . V_135 = 0 ;
V_72 -> V_76 -> V_77 . V_136 = 0 ;
V_72 -> V_76 -> V_77 . V_137 = 0 ;
F_72 ( V_72 , V_126 ) ;
V_72 -> V_76 -> V_77 . V_67 = F_48 ( V_72 -> V_67 ) ;
V_72 -> V_76 -> V_77 . V_68 = F_48 ( V_72 -> V_68 ) ;
for ( V_128 = 0 ; V_128 < V_138 ; V_128 ++ ) {
V_72 -> V_76 -> V_139 [ V_128 ] = F_73 ( V_72 -> V_140 . V_141 [ V_128 ] ) ;
V_72 -> V_76 -> V_142 [ V_128 ] = F_73 ( V_72 -> V_140 . V_143 [ V_128 ] ) ;
}
V_72 -> V_76 -> V_77 . V_127 = F_48 ( V_127 ) ;
V_72 -> V_76 -> V_77 . V_126 = F_48 ( V_126 ) ;
if ( ( V_4 = F_17 ( V_72 -> V_2 ) ) )
return V_4 ;
return F_53 ( V_72 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
F_60 ( & V_2 -> V_15 , L_35 ) ;
V_2 -> V_109 = 0 ;
V_2 -> V_45 = 0 ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
F_16 ( V_2 ) ;
F_15 ( V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
F_60 ( & V_2 -> V_15 , L_36 ) ;
F_22 ( V_2 , V_28 , V_144 ) ;
F_22 ( V_2 , V_145 , 0 ) ;
F_22 ( V_2 , V_58 , 0 ) ;
F_22 ( V_2 , V_105 , 0xFFFFFFFFFFFFFFFFULL ) ;
F_22 ( V_2 , V_146 , F_68 ( V_130 ) ) ;
F_22 ( V_2 , V_147 , 0 ) ;
F_22 ( V_2 , V_148 , F_68 ( V_133 ) ) ;
F_6 ( V_2 , V_149 , 0 ) ;
F_6 ( V_2 , V_150 , 0 ) ;
F_6 ( V_2 , V_151 , 0 ) ;
V_2 -> V_109 = V_152 ;
V_2 -> V_45 = 1 ;
return F_76 ( V_2 ) ;
}
static int F_77 ( struct V_71 * V_72 , T_1 V_126 , T_1 V_127 )
{
struct V_1 * V_2 = V_72 -> V_2 ;
T_1 V_78 ;
int V_13 ;
V_78 = ( T_1 ) V_123 -> V_78 << 32 ;
if ( V_72 -> V_118 )
V_78 = 0 ;
F_6 ( V_2 , V_153 , V_78 ) ;
F_22 ( V_2 , V_154 , F_66 ( V_72 ) ) ;
if ( ( V_13 = F_40 ( V_2 , V_72 -> V_67 , V_72 -> V_68 ) ) )
return V_13 ;
F_72 ( V_72 , V_126 ) ;
F_22 ( V_2 , V_155 ,
( ( ( T_1 ) V_72 -> V_140 . V_141 [ 0 ] & 0xffff ) << 48 ) |
( ( ( T_1 ) V_72 -> V_140 . V_141 [ 1 ] & 0xffff ) << 32 ) |
( ( ( T_1 ) V_72 -> V_140 . V_141 [ 2 ] & 0xffff ) << 16 ) |
( ( T_1 ) V_72 -> V_140 . V_141 [ 3 ] & 0xffff ) ) ;
F_22 ( V_2 , V_156 , ( T_1 )
( ( ( T_1 ) V_72 -> V_140 . V_143 [ 0 ] & 0xffff ) << 48 ) |
( ( ( T_1 ) V_72 -> V_140 . V_143 [ 1 ] & 0xffff ) << 32 ) |
( ( ( T_1 ) V_72 -> V_140 . V_143 [ 2 ] & 0xffff ) << 16 ) |
( ( T_1 ) V_72 -> V_140 . V_143 [ 3 ] & 0xffff ) ) ;
F_6 ( V_2 , V_157 , V_127 ) ;
F_58 ( V_72 ) ;
if ( ( V_13 = F_16 ( V_2 ) ) )
return V_13 ;
F_6 ( V_2 , V_158 , V_126 ) ;
return F_14 ( V_2 ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
F_60 ( & V_2 -> V_15 , L_37 ) ;
V_2 -> V_109 = 0 ;
V_2 -> V_45 = 0 ;
F_65 ( V_2 ) ;
return 0 ;
}
int F_79 ( struct V_1 * V_2 , int V_159 )
{
if ( V_159 == V_110 )
return F_74 ( V_2 ) ;
if ( V_159 == V_152 )
return F_78 ( V_2 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
return F_79 ( V_2 , V_2 -> V_109 ) ;
}
int F_81 ( struct V_1 * V_2 , int V_159 )
{
if ( ! V_159 )
return 0 ;
if ( ! ( V_159 & V_2 -> V_160 ) )
return - V_161 ;
if ( ! F_9 ( V_2 -> V_18 ) ) {
F_18 ( 1 , L_38 ) ;
return - V_19 ;
}
if ( V_159 == V_110 )
return F_59 ( V_2 ) ;
if ( V_159 == V_152 )
return F_75 ( V_2 ) ;
return - V_161 ;
}
int F_82 ( struct V_71 * V_72 , bool V_118 , T_1 V_126 , T_1 V_127 )
{
if ( ! F_9 ( V_72 -> V_2 -> V_18 ) ) {
F_18 ( 1 , L_39 ) ;
return - V_19 ;
}
V_72 -> V_118 = V_118 ;
if ( V_72 -> V_2 -> V_109 == V_110 )
return F_71 ( V_72 , V_126 , V_127 ) ;
if ( V_72 -> V_2 -> V_109 == V_152 )
return F_77 ( V_72 , V_126 , V_127 ) ;
return - V_161 ;
}
static inline int F_83 ( struct V_71 * V_72 )
{
F_16 ( V_72 -> V_2 ) ;
F_15 ( V_72 -> V_2 ) ;
F_19 ( V_72 -> V_2 ) ;
return 0 ;
}
static inline int F_84 ( struct V_71 * V_72 )
{
if ( ! V_72 -> V_93 )
return 0 ;
if ( F_56 ( V_72 ) )
return - 1 ;
if ( F_57 ( V_72 ) )
return - 1 ;
return 0 ;
}
int F_85 ( struct V_71 * V_72 )
{
F_86 ( V_72 ) ;
if ( V_72 -> V_2 -> V_109 == V_152 )
return F_83 ( V_72 ) ;
return F_84 ( V_72 ) ;
}
int F_87 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
T_1 V_164 ;
if ( ! F_9 ( V_2 -> V_18 ) )
return - V_19 ;
V_163 -> V_29 = F_2 ( V_2 , V_36 ) ;
V_163 -> V_30 = F_2 ( V_2 , V_38 ) ;
V_163 -> V_165 = F_2 ( V_2 , V_166 ) ;
V_164 = F_2 ( V_2 , V_153 ) ;
V_163 -> V_78 = V_164 >> 32 ;
V_163 -> V_134 = V_164 & 0xffffffff ;
V_163 -> V_167 = F_2 ( V_2 , V_168 ) ;
V_163 -> V_169 = F_2 ( V_2 , V_170 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 , T_1 V_169 )
{
T_1 V_29 ;
F_4 ( L_40 , V_169 ) ;
V_29 = F_2 ( V_2 , V_36 ) ;
F_6 ( V_2 , V_36 , V_29 & ~ V_171 ) ;
F_6 ( V_2 , V_170 , V_169 ) ;
}
int F_89 ( struct V_71 * V_72 , T_1 V_172 , T_1 V_173 )
{
F_90 ( V_72 , V_172 ) ;
if ( V_172 )
F_6 ( V_72 -> V_2 , V_39 , V_172 ) ;
if ( V_173 )
F_88 ( V_72 -> V_2 , V_173 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_2 )
{
return ( F_20 ( V_2 , V_28 ) == ~ 0ULL ) ;
}
