int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 , enum V_7 V_8 ,
unsigned int V_9 ,
T_1 V_10 ,
unsigned int V_11 )
{
if ( V_10 == NULL )
return - V_12 ;
V_2 -> V_13 = F_2 ( V_11 , V_14 ) ;
if ( ! V_2 -> V_13 )
return - V_15 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_16 = V_6 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = F_3 ( - 1 ) ;
F_4 ( & V_2 -> V_18 ) ;
F_5 ( & V_2 -> V_19 , V_20 , ( unsigned long ) V_2 ) ;
V_2 -> V_21 = 0 ;
F_6 ( & V_2 -> V_22 ) ;
V_2 -> V_23 = false ;
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_13 == NULL )
return;
F_8 ( F_9 ( V_2 ) ) ;
F_10 ( V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_18 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_13 ( V_25 ,
V_27 ,
5000 , V_28 ) ;
if ( V_26 < 0 )
goto V_29;
if ( ! ( V_2 -> V_8 & V_30 ) )
goto V_29;
V_26 = F_14 ( V_25 , 0 ,
V_31 , 32 ) ;
if ( V_26 < 0 )
goto V_29;
V_26 = F_14 ( V_25 , 0 ,
V_32 , 32 ) ;
V_29:
return V_26 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_33 ,
unsigned int V_34 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < F_16 ( V_36 ) ; ++ V_35 ) {
if ( V_36 [ V_35 ] == V_33 )
break;
}
if ( V_35 == F_16 ( V_36 ) )
return - V_12 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_37 = V_38 [ V_35 ] ;
V_2 -> V_39 = V_40 - V_41 ;
if ( V_2 -> V_8 & V_30 )
V_2 -> V_39 += V_42 * V_2 -> V_37 / V_33 ;
return 0 ;
}
unsigned int F_17 ( struct V_1 * V_2 )
{
unsigned int V_43 = 1 ;
if ( V_2 -> V_8 & V_44 )
V_43 = 5 ;
return 8 + V_2 -> V_37 * V_2 -> V_34 * 4 * V_43 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_19 ) ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0 ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
unsigned int V_47 )
{
unsigned int V_48 , V_49 ;
if ( V_2 -> V_8 & V_30 ) {
if ( V_47 == V_50 )
V_49 = 0 ;
else
V_49 = V_2 -> V_37 ;
} else {
if ( ! F_21 ( V_2 -> V_35 ) ) {
V_49 = V_2 -> V_51 ;
} else {
V_48 = V_2 -> V_51 ;
if ( V_2 -> V_35 == V_52 )
V_49 = 5 + ( ( V_48 & 1 ) ^
( V_48 == 0 || V_48 >= 40 ) ) ;
else
V_49 = 11 * ( V_2 -> V_35 >> 1 ) + ( V_48 == 0 ) ;
if ( ++ V_48 >= ( 80 >> ( V_2 -> V_35 >> 1 ) ) )
V_48 = 0 ;
V_2 -> V_51 = V_48 ;
}
}
return V_49 ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
unsigned int V_53 )
{
unsigned int V_54 , V_48 , V_55 , V_47 ;
if ( V_2 -> V_56 < V_41 ) {
if ( ! F_21 ( V_2 -> V_35 ) )
V_54 = V_2 -> V_56 + V_2 -> V_57 ;
else {
V_48 = V_2 -> V_57 ;
V_55 = V_48 % 13 ;
V_54 = V_2 -> V_56 ;
V_54 += 1386 + ( ( V_55 && ! ( V_55 & 3 ) ) ||
V_48 == 146 ) ;
if ( ++ V_48 >= 147 )
V_48 = 0 ;
V_2 -> V_57 = V_48 ;
}
} else
V_54 = V_2 -> V_56 - V_41 ;
V_2 -> V_56 = V_54 ;
if ( V_54 < V_41 ) {
V_54 += V_2 -> V_39 ;
V_47 = ( V_53 + V_54 / V_41 ) << 12 ;
V_47 += V_54 % V_41 ;
return V_47 & V_58 ;
} else {
return V_50 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
unsigned int V_61 )
{
unsigned int V_62 ;
V_62 = V_2 -> V_45 + V_61 ;
if ( V_62 >= V_60 -> V_25 -> V_63 )
V_62 -= V_60 -> V_25 -> V_63 ;
F_24 ( V_2 -> V_45 ) = V_62 ;
V_2 -> V_46 += V_61 ;
if ( V_2 -> V_46 >= V_60 -> V_25 -> V_64 ) {
V_2 -> V_46 -= V_60 -> V_25 -> V_64 ;
F_25 ( & V_2 -> V_19 ) ;
}
}
static void V_20 ( unsigned long V_65 )
{
struct V_1 * V_2 = ( void * ) V_65 ;
struct V_59 * V_60 = F_24 ( V_2 -> V_60 ) ;
if ( V_60 )
F_26 ( V_60 ) ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_66 ,
unsigned int V_67 )
{
struct V_68 V_69 = { 0 } ;
int V_26 = 0 ;
if ( F_28 ( V_2 -> V_17 ) )
goto V_29;
V_69 . V_70 = F_29 ( V_2 -> V_21 + 1 , V_71 ) ;
V_69 . V_72 = V_73 ;
V_69 . V_66 = V_66 ;
if ( V_67 > 0 )
V_69 . V_67 = V_67 ;
else
V_69 . V_74 = true ;
V_26 = F_30 ( V_2 -> V_17 , & V_69 , & V_2 -> V_75 . V_76 ,
V_2 -> V_75 . V_77 [ V_2 -> V_21 ] . V_78 ) ;
if ( V_26 < 0 ) {
F_31 ( & V_2 -> V_4 -> V_79 , L_1 , V_26 ) ;
goto V_29;
}
if ( ++ V_2 -> V_21 >= V_80 )
V_2 -> V_21 = 0 ;
V_29:
return V_26 ;
}
static inline int F_32 ( struct V_1 * V_2 ,
unsigned int V_67 )
{
return F_27 ( V_2 , V_81 , V_67 ) ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return F_27 ( V_2 , V_82 ,
F_17 ( V_2 ) ) ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_53 ,
unsigned int V_55 )
{
T_2 * V_75 ;
unsigned int V_47 ;
unsigned int V_49 ;
unsigned int V_67 ;
unsigned int V_83 ;
struct V_59 * V_60 ;
V_75 = V_2 -> V_75 . V_77 [ V_2 -> V_21 ] . V_75 ;
V_47 = F_22 ( V_2 , V_53 ) ;
V_49 = F_20 ( V_2 , V_47 ) ;
V_83 = V_2 -> V_10 ( V_2 , V_75 + 2 , V_49 , & V_47 ) ;
V_75 [ 0 ] = F_35 ( F_24 ( V_2 -> V_84 ) |
( V_2 -> V_34 << V_85 ) |
V_2 -> V_86 ) ;
V_75 [ 1 ] = F_35 ( V_87 |
( ( V_2 -> V_9 << V_88 ) & V_89 ) |
( ( V_2 -> V_90 << V_91 ) & V_92 ) |
( V_47 & V_58 ) ) ;
V_2 -> V_86 = ( V_2 -> V_86 + V_49 ) & 0xff ;
V_67 = 8 + V_49 * 4 * V_2 -> V_34 ;
F_36 ( V_2 , V_53 , V_75 , V_67 , V_55 ) ;
if ( F_32 ( V_2 , V_67 ) < 0 )
return - V_93 ;
V_60 = F_24 ( V_2 -> V_60 ) ;
if ( V_60 && V_83 > 0 )
F_23 ( V_2 , V_60 , V_83 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned int V_94 , unsigned int V_53 ,
unsigned int V_55 )
{
T_2 * V_75 ;
T_3 V_95 [ 2 ] ;
unsigned int V_9 , V_90 , V_47 ;
unsigned int V_34 , V_86 , V_96 ;
unsigned int V_49 ;
struct V_59 * V_60 ;
unsigned int V_83 ;
bool V_97 ;
V_75 = V_2 -> V_75 . V_77 [ V_2 -> V_21 ] . V_75 ;
V_95 [ 0 ] = F_38 ( V_75 [ 0 ] ) ;
V_95 [ 1 ] = F_38 ( V_75 [ 1 ] ) ;
F_39 ( V_2 , V_53 , V_95 , V_94 , V_55 ) ;
if ( ( ( V_95 [ 0 ] & V_98 ) == V_87 ) ||
( ( V_95 [ 1 ] & V_98 ) != V_87 ) ) {
F_40 ( & V_2 -> V_4 -> V_79 ,
L_2 ,
V_95 [ 0 ] , V_95 [ 1 ] ) ;
V_49 = 0 ;
V_83 = 0 ;
goto V_29;
}
V_9 = ( V_95 [ 1 ] & V_89 ) >> V_88 ;
if ( V_9 != V_2 -> V_9 ) {
F_40 ( & V_2 -> V_4 -> V_79 ,
L_3 ,
V_95 [ 0 ] , V_95 [ 1 ] ) ;
V_49 = 0 ;
V_83 = 0 ;
goto V_29;
}
V_90 = ( V_95 [ 1 ] & V_92 ) >> V_91 ;
if ( V_94 < 3 ||
( V_9 == V_99 && V_90 == V_100 ) ) {
V_49 = 0 ;
} else {
V_34 =
( V_95 [ 0 ] & V_101 ) >> V_85 ;
if ( V_34 == 0 ) {
F_31 ( & V_2 -> V_4 -> V_79 ,
L_4 ,
V_95 [ 0 ] ) ;
return - V_102 ;
}
if ( V_2 -> V_8 & V_103 )
V_34 = V_2 -> V_34 ;
V_49 = ( V_94 - 2 ) / V_34 ;
}
V_86 = V_95 [ 0 ] & V_104 ;
if ( V_49 == 0 && ( V_2 -> V_8 & V_105 ) &&
V_2 -> V_86 != V_28 )
V_86 = V_2 -> V_86 ;
if ( ( ( V_2 -> V_8 & V_106 ) &&
V_86 == V_2 -> V_107 ) ||
V_2 -> V_86 == V_28 ) {
V_97 = false ;
} else if ( ! ( V_2 -> V_8 & V_108 ) ) {
V_97 = V_86 != V_2 -> V_86 ;
} else {
if ( V_49 > 0 && V_2 -> V_109 > 0 )
V_96 = V_2 -> V_109 ;
else
V_96 = V_49 ;
V_97 = V_86 !=
( ( V_2 -> V_86 + V_96 ) & 0xff ) ;
}
if ( V_97 ) {
F_31 ( & V_2 -> V_4 -> V_79 ,
L_5 ,
V_2 -> V_86 , V_86 ) ;
return - V_93 ;
}
V_47 = F_38 ( V_75 [ 1 ] ) & V_58 ;
V_83 = V_2 -> V_10 ( V_2 , V_75 + 2 , V_49 , & V_47 ) ;
if ( V_2 -> V_8 & V_108 )
V_2 -> V_86 = V_86 ;
else
V_2 -> V_86 =
( V_86 + V_49 ) & 0xff ;
V_29:
if ( F_33 ( V_2 ) < 0 )
return - V_93 ;
V_60 = F_24 ( V_2 -> V_60 ) ;
if ( V_60 && V_83 > 0 )
F_23 ( V_2 , V_60 , V_83 ) ;
return 0 ;
}
static inline T_3 F_41 ( T_3 V_110 )
{
return ( ( ( V_110 >> 13 ) & 0x07 ) * 8000 ) + ( V_110 & 0x1fff ) ;
}
static inline T_3 F_42 ( T_3 V_53 , unsigned int V_111 )
{
V_53 += V_111 ;
if ( V_53 >= 8 * V_112 )
V_53 -= 8 * V_112 ;
return V_53 ;
}
static inline T_3 F_43 ( T_3 V_53 , unsigned int V_113 )
{
if ( V_53 < V_113 )
V_53 += 8 * V_112 ;
return V_53 - V_113 ;
}
static void F_44 ( struct V_114 * V_17 , T_3 V_110 ,
T_4 V_66 , void * V_115 ,
void * V_116 )
{
struct V_1 * V_2 = V_116 ;
unsigned int V_117 , V_77 = V_66 / 4 ;
T_3 V_53 ;
if ( V_2 -> V_21 < 0 )
return;
V_53 = F_41 ( V_110 ) ;
V_53 = F_42 ( V_53 , V_80 - V_77 ) ;
for ( V_117 = 0 ; V_117 < V_77 ; ++ V_117 ) {
V_53 = F_42 ( V_53 , 1 ) ;
if ( F_34 ( V_2 , V_53 , V_117 ) < 0 ) {
V_2 -> V_21 = - 1 ;
F_45 ( V_2 ) ;
return;
}
}
F_46 ( V_2 -> V_17 ) ;
}
static void F_47 ( struct V_114 * V_17 , T_3 V_110 ,
T_4 V_66 , void * V_115 ,
void * V_116 )
{
struct V_1 * V_2 = V_116 ;
unsigned int V_117 , V_77 ;
unsigned int V_94 , V_118 ;
T_2 * V_119 = V_115 ;
T_3 V_53 ;
if ( V_2 -> V_21 < 0 )
return;
V_77 = V_66 / V_82 ;
V_53 = F_41 ( V_110 ) ;
V_53 = F_43 ( V_53 , V_77 ) ;
V_118 = F_17 ( V_2 ) / 4 ;
for ( V_117 = 0 ; V_117 < V_77 ; V_117 ++ ) {
V_53 = F_42 ( V_53 , 1 ) ;
V_94 =
( F_38 ( V_119 [ V_117 ] ) >> V_120 ) / 4 ;
if ( V_94 > V_118 ) {
F_31 ( & V_2 -> V_4 -> V_79 ,
L_6 ,
V_94 , V_118 ) ;
break;
}
if ( F_37 ( V_2 , V_94 , V_53 , V_117 ) < 0 )
break;
}
if ( V_117 < V_77 ) {
V_2 -> V_21 = - 1 ;
F_45 ( V_2 ) ;
return;
}
F_46 ( V_2 -> V_17 ) ;
}
static void F_48 ( struct V_114 * V_17 ,
T_3 V_110 , T_4 V_66 ,
void * V_115 , void * V_116 )
{
struct V_1 * V_2 = V_116 ;
V_2 -> V_23 = true ;
F_49 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_16 == V_121 )
V_17 -> V_122 . V_123 = F_47 ;
else
V_17 -> V_122 . V_123 = F_44 ;
V_17 -> V_122 . V_123 ( V_17 , V_110 , V_66 , V_115 , V_2 ) ;
}
int F_50 ( struct V_1 * V_2 , int V_124 , int V_125 )
{
static const struct {
unsigned int V_126 ;
unsigned int V_54 ;
} V_127 [] = {
[ V_128 ] = { 4 , 3072 } ,
[ V_129 ] = { 6 , 1024 } ,
[ V_130 ] = { 12 , 1024 } ,
[ V_131 ] = { 24 , 1024 } ,
[ V_52 ] = { 0 , 67 } ,
[ V_132 ] = { 0 , 67 } ,
[ V_133 ] = { 0 , 67 } ,
} ;
unsigned int V_134 ;
enum V_135 V_6 ;
int type , V_72 , V_26 ;
F_51 ( & V_2 -> V_18 ) ;
if ( F_8 ( F_9 ( V_2 ) ||
( V_2 -> V_34 < 1 ) ) ) {
V_26 = - V_136 ;
goto V_137;
}
if ( V_2 -> V_16 == V_121 )
V_2 -> V_86 = V_28 ;
else
V_2 -> V_86 = 0 ;
V_2 -> V_51 = V_127 [ V_2 -> V_35 ] . V_126 ;
V_2 -> V_57 = V_127 [ V_2 -> V_35 ] . V_54 ;
V_2 -> V_56 = V_41 ;
if ( V_2 -> V_16 == V_121 ) {
V_6 = V_138 ;
type = V_139 ;
V_134 = V_82 ;
} else {
V_6 = V_140 ;
type = V_141 ;
V_134 = V_81 ;
}
V_26 = F_52 ( & V_2 -> V_75 , V_2 -> V_4 , V_80 ,
F_17 ( V_2 ) , V_6 ) ;
if ( V_26 < 0 )
goto V_137;
V_2 -> V_17 = F_53 ( F_54 ( V_2 -> V_4 ) -> V_142 ,
type , V_124 , V_125 , V_134 ,
F_48 , V_2 ) ;
if ( F_28 ( V_2 -> V_17 ) ) {
V_26 = F_55 ( V_2 -> V_17 ) ;
if ( V_26 == - V_143 )
F_31 ( & V_2 -> V_4 -> V_79 ,
L_7 ) ;
goto V_144;
}
F_56 ( V_2 ) ;
V_2 -> V_21 = 0 ;
do {
if ( V_2 -> V_16 == V_121 )
V_26 = F_33 ( V_2 ) ;
else
V_26 = F_32 ( V_2 , 0 ) ;
if ( V_26 < 0 )
goto V_145;
} while ( V_2 -> V_21 > 0 );
V_72 = V_146 ;
if ( V_2 -> V_8 & V_147 )
V_72 |= V_148 ;
V_2 -> V_23 = false ;
V_26 = F_57 ( V_2 -> V_17 , - 1 , 0 , V_72 ) ;
if ( V_26 < 0 )
goto V_145;
F_58 ( & V_2 -> V_18 ) ;
return 0 ;
V_145:
F_59 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
V_144:
F_60 ( & V_2 -> V_75 , V_2 -> V_4 ) ;
V_137:
F_58 ( & V_2 -> V_18 ) ;
return V_26 ;
}
unsigned long F_61 ( struct V_1 * V_2 )
{
if ( ! F_62 () && F_9 ( V_2 ) )
F_63 ( V_2 -> V_17 ) ;
return F_24 ( V_2 -> V_45 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_84 ) =
( F_54 ( V_2 -> V_4 ) -> V_142 -> V_149 << V_150 ) &
V_151 ;
}
void F_64 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_18 ) ;
if ( ! F_9 ( V_2 ) ) {
F_58 ( & V_2 -> V_18 ) ;
return;
}
F_19 ( & V_2 -> V_19 ) ;
F_65 ( V_2 -> V_17 ) ;
F_59 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
F_60 ( & V_2 -> V_75 , V_2 -> V_4 ) ;
V_2 -> V_23 = false ;
F_58 ( & V_2 -> V_18 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
V_60 = F_24 ( V_2 -> V_60 ) ;
if ( V_60 )
F_66 ( V_60 ) ;
}
