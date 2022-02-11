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
V_2 -> V_24 = NULL ;
V_2 -> V_9 = V_9 ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
F_8 ( F_9 ( V_2 ) ) ;
F_10 ( V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_18 ) ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
int V_27 ;
V_27 = F_13 ( V_26 ,
V_28 ,
5000 , V_29 ) ;
if ( V_27 < 0 )
goto V_30;
if ( ! ( V_2 -> V_8 & V_31 ) )
goto V_30;
V_27 = F_14 ( V_26 , 0 ,
V_32 , 32 ) ;
if ( V_27 < 0 )
goto V_30;
V_27 = F_14 ( V_26 , 0 ,
V_33 , 32 ) ;
V_30:
return V_27 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_34 ,
unsigned int V_35 )
{
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < F_16 ( V_37 ) ; ++ V_36 ) {
if ( V_37 [ V_36 ] == V_34 )
break;
}
if ( V_36 == F_16 ( V_37 ) )
return - V_12 ;
V_2 -> V_36 = V_36 ;
V_2 -> V_35 = V_35 ;
V_2 -> V_38 = V_39 [ V_36 ] ;
V_2 -> V_40 = V_41 - V_42 ;
if ( V_2 -> V_8 & V_31 )
V_2 -> V_40 += V_43 * V_2 -> V_38 / V_34 ;
return 0 ;
}
unsigned int F_17 ( struct V_1 * V_2 )
{
unsigned int V_44 = 1 ;
if ( V_2 -> V_8 & V_45 )
V_44 = 5 ;
return 8 + V_2 -> V_38 * V_2 -> V_35 * 4 * V_44 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_19 ) ;
V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = true ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
unsigned int V_49 )
{
unsigned int V_50 , V_51 ;
if ( V_2 -> V_8 & V_31 ) {
if ( V_49 == V_52 )
V_51 = 0 ;
else
V_51 = V_2 -> V_38 ;
} else {
if ( ! F_21 ( V_2 -> V_36 ) ) {
V_51 = V_2 -> V_53 ;
} else {
V_50 = V_2 -> V_53 ;
if ( V_2 -> V_36 == V_54 )
V_51 = 5 + ( ( V_50 & 1 ) ^
( V_50 == 0 || V_50 >= 40 ) ) ;
else
V_51 = 11 * ( V_2 -> V_36 >> 1 ) + ( V_50 == 0 ) ;
if ( ++ V_50 >= ( 80 >> ( V_2 -> V_36 >> 1 ) ) )
V_50 = 0 ;
V_2 -> V_53 = V_50 ;
}
}
return V_51 ;
}
static unsigned int F_22 ( struct V_1 * V_2 ,
unsigned int V_55 )
{
unsigned int V_56 , V_50 , V_57 , V_49 ;
if ( V_2 -> V_58 < V_42 ) {
if ( ! F_21 ( V_2 -> V_36 ) )
V_56 = V_2 -> V_58 + V_2 -> V_59 ;
else {
V_50 = V_2 -> V_59 ;
V_57 = V_50 % 13 ;
V_56 = V_2 -> V_58 ;
V_56 += 1386 + ( ( V_57 && ! ( V_57 & 3 ) ) ||
V_50 == 146 ) ;
if ( ++ V_50 >= 147 )
V_50 = 0 ;
V_2 -> V_59 = V_50 ;
}
} else
V_56 = V_2 -> V_58 - V_42 ;
V_2 -> V_58 = V_56 ;
if ( V_56 < V_42 ) {
V_56 += V_2 -> V_40 ;
V_49 = ( V_55 + V_56 / V_42 ) << 12 ;
V_49 += V_56 % V_42 ;
return V_49 & V_60 ;
} else {
return V_52 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
unsigned int V_63 )
{
unsigned int V_64 ;
V_64 = V_2 -> V_46 + V_63 ;
if ( V_64 >= V_62 -> V_26 -> V_65 )
V_64 -= V_62 -> V_26 -> V_65 ;
F_24 ( V_2 -> V_46 ) = V_64 ;
V_2 -> V_47 += V_63 ;
if ( V_2 -> V_47 >= V_62 -> V_26 -> V_66 ) {
V_2 -> V_47 -= V_62 -> V_26 -> V_66 ;
V_2 -> V_48 = false ;
F_25 ( & V_2 -> V_19 ) ;
}
}
static void V_20 ( unsigned long V_67 )
{
struct V_1 * V_2 = ( void * ) V_67 ;
struct V_61 * V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 )
F_26 ( V_62 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int V_68 ,
unsigned int V_69 , bool V_70 )
{
struct V_71 V_72 = { 0 } ;
int V_27 = 0 ;
if ( F_28 ( V_2 -> V_17 ) )
goto V_30;
V_72 . V_73 = F_29 ( V_2 -> V_21 + 1 , V_74 ) ;
V_72 . V_75 = V_76 ;
V_72 . V_68 = V_68 ;
V_72 . V_69 = ( ! V_70 ) ? V_69 : 0 ;
V_72 . V_70 = V_70 ;
V_27 = F_30 ( V_2 -> V_17 , & V_72 , & V_2 -> V_77 . V_78 ,
V_2 -> V_77 . V_79 [ V_2 -> V_21 ] . V_80 ) ;
if ( V_27 < 0 ) {
F_31 ( & V_2 -> V_4 -> V_81 , L_1 , V_27 ) ;
goto V_30;
}
if ( ++ V_2 -> V_21 >= V_82 )
V_2 -> V_21 = 0 ;
V_30:
return V_27 ;
}
static inline int F_32 ( struct V_1 * V_2 ,
unsigned int V_69 , bool V_70 )
{
return F_27 ( V_2 , V_83 ,
V_69 , V_70 ) ;
}
static inline int F_33 ( struct V_1 * V_2 )
{
return F_27 ( V_2 , V_84 ,
F_17 ( V_2 ) , false ) ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_51 ,
unsigned int V_49 )
{
T_2 * V_77 ;
unsigned int V_69 ;
unsigned int V_85 ;
struct V_61 * V_62 ;
V_77 = V_2 -> V_77 . V_79 [ V_2 -> V_21 ] . V_77 ;
V_85 = V_2 -> V_10 ( V_2 , V_77 + 2 , V_51 , & V_49 ) ;
V_77 [ 0 ] = F_35 ( F_24 ( V_2 -> V_86 ) |
( V_2 -> V_35 << V_87 ) |
V_2 -> V_88 ) ;
V_77 [ 1 ] = F_35 ( V_89 |
( ( V_2 -> V_9 << V_90 ) & V_91 ) |
( ( V_2 -> V_92 << V_93 ) & V_94 ) |
( V_49 & V_60 ) ) ;
V_2 -> V_88 = ( V_2 -> V_88 + V_51 ) & 0xff ;
V_69 = 8 + V_51 * 4 * V_2 -> V_35 ;
if ( F_32 ( V_2 , V_69 , false ) < 0 )
return - V_95 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 && V_85 > 0 )
F_23 ( V_2 , V_62 , V_85 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
unsigned int V_96 , T_2 * V_77 ,
unsigned int * V_51 , unsigned int V_49 )
{
T_3 V_97 [ 2 ] ;
unsigned int V_9 , V_92 ;
unsigned int V_35 , V_88 , V_98 ;
struct V_61 * V_62 ;
unsigned int V_85 ;
bool V_99 ;
V_97 [ 0 ] = F_37 ( V_77 [ 0 ] ) ;
V_97 [ 1 ] = F_37 ( V_77 [ 1 ] ) ;
if ( ( ( V_97 [ 0 ] & V_100 ) == V_89 ) ||
( ( V_97 [ 1 ] & V_100 ) != V_89 ) ) {
F_38 ( & V_2 -> V_4 -> V_81 ,
L_2 ,
V_97 [ 0 ] , V_97 [ 1 ] ) ;
* V_51 = 0 ;
V_85 = 0 ;
goto V_30;
}
V_9 = ( V_97 [ 1 ] & V_91 ) >> V_90 ;
if ( V_9 != V_2 -> V_9 ) {
F_38 ( & V_2 -> V_4 -> V_81 ,
L_3 ,
V_97 [ 0 ] , V_97 [ 1 ] ) ;
* V_51 = 0 ;
V_85 = 0 ;
goto V_30;
}
V_92 = ( V_97 [ 1 ] & V_94 ) >> V_93 ;
if ( V_96 < 3 ||
( V_9 == V_101 && V_92 == V_102 ) ) {
* V_51 = 0 ;
} else {
V_35 =
( V_97 [ 0 ] & V_103 ) >> V_87 ;
if ( V_35 == 0 ) {
F_31 ( & V_2 -> V_4 -> V_81 ,
L_4 ,
V_97 [ 0 ] ) ;
return - V_104 ;
}
if ( V_2 -> V_8 & V_105 )
V_35 = V_2 -> V_35 ;
* V_51 = ( V_96 - 2 ) / V_35 ;
}
V_88 = V_97 [ 0 ] & V_106 ;
if ( * V_51 == 0 && ( V_2 -> V_8 & V_107 ) &&
V_2 -> V_88 != V_29 )
V_88 = V_2 -> V_88 ;
if ( ( ( V_2 -> V_8 & V_108 ) &&
V_88 == V_2 -> V_109 ) ||
V_2 -> V_88 == V_29 ) {
V_99 = false ;
} else if ( ! ( V_2 -> V_8 & V_110 ) ) {
V_99 = V_88 != V_2 -> V_88 ;
} else {
if ( ( * V_51 > 0 ) && ( V_2 -> V_111 > 0 ) )
V_98 = V_2 -> V_111 ;
else
V_98 = * V_51 ;
V_99 = V_88 !=
( ( V_2 -> V_88 + V_98 ) & 0xff ) ;
}
if ( V_99 ) {
F_31 ( & V_2 -> V_4 -> V_81 ,
L_5 ,
V_2 -> V_88 , V_88 ) ;
return - V_95 ;
}
V_85 = V_2 -> V_10 ( V_2 , V_77 + 2 , * V_51 , & V_49 ) ;
if ( V_2 -> V_8 & V_110 )
V_2 -> V_88 = V_88 ;
else
V_2 -> V_88 =
( V_88 + * V_51 ) & 0xff ;
V_30:
if ( F_33 ( V_2 ) < 0 )
return - V_95 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 && V_85 > 0 )
F_23 ( V_2 , V_62 , V_85 ) ;
return 0 ;
}
static void F_39 ( struct V_112 * V_17 , T_3 V_55 ,
T_4 V_68 , void * V_113 ,
void * V_114 )
{
struct V_1 * V_2 = V_114 ;
unsigned int V_115 , V_49 , V_79 = V_68 / 4 ;
unsigned int V_51 ;
if ( V_2 -> V_21 < 0 )
return;
V_55 += V_82 - V_79 ;
for ( V_115 = 0 ; V_115 < V_79 ; ++ V_115 ) {
V_49 = F_22 ( V_2 , ++ V_55 ) ;
V_51 = F_20 ( V_2 , V_49 ) ;
if ( F_34 ( V_2 , V_51 , V_49 ) < 0 ) {
V_2 -> V_21 = - 1 ;
F_40 ( V_2 ) ;
return;
}
}
F_41 ( V_2 -> V_17 ) ;
}
static void F_42 ( struct V_112 * V_17 , T_3 V_55 ,
T_4 V_68 , void * V_113 ,
void * V_114 )
{
struct V_1 * V_2 = V_114 ;
unsigned int V_72 , V_49 , V_79 ;
unsigned int V_96 , V_116 ;
unsigned int V_51 ;
T_2 * V_77 , * V_117 = V_113 ;
if ( V_2 -> V_21 < 0 )
return;
V_79 = V_68 / V_84 ;
V_116 = F_17 ( V_2 ) / 4 ;
for ( V_72 = 0 ; V_72 < V_79 ; V_72 ++ ) {
V_77 = V_2 -> V_77 . V_79 [ V_2 -> V_21 ] . V_77 ;
V_96 =
( F_37 ( V_117 [ V_72 ] ) >> V_118 ) / 4 ;
if ( V_96 > V_116 ) {
F_31 ( & V_2 -> V_4 -> V_81 ,
L_6 ,
V_96 , V_116 ) ;
V_2 -> V_21 = - 1 ;
break;
}
V_49 = F_37 ( V_77 [ 1 ] ) & V_60 ;
if ( F_36 ( V_2 , V_96 , V_77 ,
& V_51 , V_49 ) < 0 ) {
V_2 -> V_21 = - 1 ;
break;
}
if ( V_2 -> V_24 && V_2 -> V_24 -> V_23 ) {
if ( F_34 ( V_2 -> V_24 ,
V_51 , V_49 ) < 0 ) {
V_2 -> V_21 = - 1 ;
break;
}
}
}
if ( V_2 -> V_21 < 0 ) {
F_40 ( V_2 ) ;
if ( V_2 -> V_24 ) {
V_2 -> V_24 -> V_21 = - 1 ;
F_40 ( V_2 -> V_24 ) ;
}
return;
}
if ( V_2 -> V_24 && V_2 -> V_24 -> V_23 )
F_41 ( V_2 -> V_24 -> V_17 ) ;
F_41 ( V_2 -> V_17 ) ;
}
static void F_43 ( struct V_112 * V_17 , T_3 V_55 ,
T_4 V_68 , void * V_113 ,
void * V_114 )
{
return;
}
static void F_44 ( struct V_112 * V_17 ,
T_3 V_55 , T_4 V_68 ,
void * V_113 , void * V_114 )
{
struct V_1 * V_2 = V_114 ;
V_2 -> V_23 = true ;
F_45 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_16 == V_119 )
V_17 -> V_120 . V_121 = F_42 ;
else if ( V_2 -> V_8 & V_122 )
V_17 -> V_120 . V_121 = F_43 ;
else
V_17 -> V_120 . V_121 = F_39 ;
V_17 -> V_120 . V_121 ( V_17 , V_55 , V_68 , V_113 , V_2 ) ;
}
int F_46 ( struct V_1 * V_2 , int V_123 , int V_124 )
{
static const struct {
unsigned int V_125 ;
unsigned int V_56 ;
} V_126 [] = {
[ V_127 ] = { 4 , 3072 } ,
[ V_128 ] = { 6 , 1024 } ,
[ V_129 ] = { 12 , 1024 } ,
[ V_130 ] = { 24 , 1024 } ,
[ V_54 ] = { 0 , 67 } ,
[ V_131 ] = { 0 , 67 } ,
[ V_132 ] = { 0 , 67 } ,
} ;
unsigned int V_133 ;
enum V_134 V_6 ;
int type , V_75 , V_27 ;
F_47 ( & V_2 -> V_18 ) ;
if ( F_8 ( F_9 ( V_2 ) ||
( V_2 -> V_35 < 1 ) ) ) {
V_27 = - V_135 ;
goto V_136;
}
if ( V_2 -> V_16 == V_119 &&
V_2 -> V_8 & V_137 )
V_2 -> V_88 = V_29 ;
else
V_2 -> V_88 = 0 ;
V_2 -> V_53 = V_126 [ V_2 -> V_36 ] . V_125 ;
V_2 -> V_59 = V_126 [ V_2 -> V_36 ] . V_56 ;
V_2 -> V_58 = V_42 ;
if ( V_2 -> V_16 == V_119 ) {
V_6 = V_138 ;
type = V_139 ;
V_133 = V_84 ;
} else {
V_6 = V_140 ;
type = V_141 ;
V_133 = V_83 ;
}
V_27 = F_48 ( & V_2 -> V_77 , V_2 -> V_4 , V_82 ,
F_17 ( V_2 ) , V_6 ) ;
if ( V_27 < 0 )
goto V_136;
V_2 -> V_17 = F_49 ( F_50 ( V_2 -> V_4 ) -> V_142 ,
type , V_123 , V_124 , V_133 ,
F_44 , V_2 ) ;
if ( F_28 ( V_2 -> V_17 ) ) {
V_27 = F_51 ( V_2 -> V_17 ) ;
if ( V_27 == - V_143 )
F_31 ( & V_2 -> V_4 -> V_81 ,
L_7 ) ;
goto V_144;
}
F_52 ( V_2 ) ;
V_2 -> V_21 = 0 ;
do {
if ( V_2 -> V_16 == V_119 )
V_27 = F_33 ( V_2 ) ;
else
V_27 = F_32 ( V_2 , 0 , true ) ;
if ( V_27 < 0 )
goto V_145;
} while ( V_2 -> V_21 > 0 );
V_75 = V_146 ;
if ( V_2 -> V_8 & V_147 )
V_75 |= V_148 ;
V_2 -> V_23 = false ;
V_27 = F_53 ( V_2 -> V_17 , - 1 , 0 , V_75 ) ;
if ( V_27 < 0 )
goto V_145;
F_54 ( & V_2 -> V_18 ) ;
return 0 ;
V_145:
F_55 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
V_144:
F_56 ( & V_2 -> V_77 , V_2 -> V_4 ) ;
V_136:
F_54 ( & V_2 -> V_18 ) ;
return V_27 ;
}
unsigned long F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_48 && F_9 ( V_2 ) )
F_58 ( V_2 -> V_17 ) ;
else
V_2 -> V_48 = true ;
return F_24 ( V_2 -> V_46 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_86 ) =
( F_50 ( V_2 -> V_4 ) -> V_142 -> V_149 << V_150 ) &
V_151 ;
}
void F_59 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_18 ) ;
if ( ! F_9 ( V_2 ) ) {
F_54 ( & V_2 -> V_18 ) ;
return;
}
F_19 ( & V_2 -> V_19 ) ;
F_60 ( V_2 -> V_17 ) ;
F_55 ( V_2 -> V_17 ) ;
V_2 -> V_17 = F_3 ( - 1 ) ;
F_56 ( & V_2 -> V_77 , V_2 -> V_4 ) ;
V_2 -> V_23 = false ;
F_54 ( & V_2 -> V_18 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
V_62 = F_24 ( V_2 -> V_62 ) ;
if ( V_62 )
F_61 ( V_62 ) ;
}
