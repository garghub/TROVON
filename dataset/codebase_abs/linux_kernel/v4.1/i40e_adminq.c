static inline bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == F_2 ( V_4 ) ) ||
( V_2 -> V_3 == F_2 ( V_5 ) ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
if ( F_4 ( V_7 ) ) {
V_7 -> V_8 . V_9 . V_10 = V_11 ;
V_7 -> V_8 . V_9 . V_12 = V_13 ;
V_7 -> V_8 . V_9 . V_14 = V_15 ;
V_7 -> V_8 . V_9 . V_16 = V_17 ;
V_7 -> V_8 . V_9 . V_18 = V_19 ;
V_7 -> V_8 . V_20 . V_10 = V_21 ;
V_7 -> V_8 . V_20 . V_12 = V_22 ;
V_7 -> V_8 . V_20 . V_14 = V_23 ;
V_7 -> V_8 . V_20 . V_16 = V_24 ;
V_7 -> V_8 . V_20 . V_18 = V_25 ;
} else {
V_7 -> V_8 . V_9 . V_10 = V_26 ;
V_7 -> V_8 . V_9 . V_12 = V_27 ;
V_7 -> V_8 . V_9 . V_14 = V_28 ;
V_7 -> V_8 . V_9 . V_16 = V_29 ;
V_7 -> V_8 . V_9 . V_18 = V_30 ;
V_7 -> V_8 . V_20 . V_10 = V_31 ;
V_7 -> V_8 . V_20 . V_12 = V_32 ;
V_7 -> V_8 . V_20 . V_14 = V_33 ;
V_7 -> V_8 . V_20 . V_16 = V_34 ;
V_7 -> V_8 . V_20 . V_18 = V_35 ;
}
}
static T_1 F_5 ( struct V_6 * V_7 )
{
T_1 V_36 ;
V_36 = F_6 ( V_7 , & V_7 -> V_8 . V_9 . V_37 ,
V_38 ,
( V_7 -> V_8 . V_39 *
sizeof( struct V_1 ) ) ,
V_40 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_7 ( V_7 , & V_7 -> V_8 . V_9 . V_41 ,
( V_7 -> V_8 . V_39 *
sizeof( struct V_42 ) ) ) ;
if ( V_36 ) {
F_8 ( V_7 , & V_7 -> V_8 . V_9 . V_37 ) ;
return V_36 ;
}
return V_36 ;
}
static T_1 F_9 ( struct V_6 * V_7 )
{
T_1 V_36 ;
V_36 = F_6 ( V_7 , & V_7 -> V_8 . V_20 . V_37 ,
V_43 ,
( V_7 -> V_8 . V_44 *
sizeof( struct V_1 ) ) ,
V_40 ) ;
return V_36 ;
}
static void F_10 ( struct V_6 * V_7 )
{
F_8 ( V_7 , & V_7 -> V_8 . V_9 . V_37 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
F_8 ( V_7 , & V_7 -> V_8 . V_20 . V_37 ) ;
}
static T_1 F_12 ( struct V_6 * V_7 )
{
T_1 V_36 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
int V_47 ;
V_36 = F_7 ( V_7 , & V_7 -> V_8 . V_20 . V_48 ,
( V_7 -> V_8 . V_44 * sizeof( struct V_45 ) ) ) ;
if ( V_36 )
goto V_49;
V_7 -> V_8 . V_20 . V_50 . V_51 = (struct V_45 * ) V_7 -> V_8 . V_20 . V_48 . V_52 ;
for ( V_47 = 0 ; V_47 < V_7 -> V_8 . V_44 ; V_47 ++ ) {
V_46 = & V_7 -> V_8 . V_20 . V_50 . V_51 [ V_47 ] ;
V_36 = F_6 ( V_7 , V_46 ,
V_53 ,
V_7 -> V_8 . V_54 ,
V_40 ) ;
if ( V_36 )
goto V_55;
V_2 = F_13 ( V_7 -> V_8 . V_20 , V_47 ) ;
V_2 -> V_56 = F_2 ( V_57 ) ;
if ( V_7 -> V_8 . V_54 > V_58 )
V_2 -> V_56 |= F_2 ( V_59 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_60 = F_2 ( ( V_61 ) V_46 -> V_62 ) ;
V_2 -> V_63 = 0 ;
V_2 -> V_64 = 0 ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 . V_67 . V_68 =
F_14 ( F_15 ( V_46 -> V_69 ) ) ;
V_2 -> V_66 . V_67 . V_70 =
F_14 ( F_16 ( V_46 -> V_69 ) ) ;
V_2 -> V_66 . V_67 . V_71 = 0 ;
V_2 -> V_66 . V_67 . V_72 = 0 ;
}
V_49:
return V_36 ;
V_55:
V_47 -- ;
for (; V_47 >= 0 ; V_47 -- )
F_8 ( V_7 , & V_7 -> V_8 . V_20 . V_50 . V_51 [ V_47 ] ) ;
F_17 ( V_7 , & V_7 -> V_8 . V_20 . V_48 ) ;
return V_36 ;
}
static T_1 F_18 ( struct V_6 * V_7 )
{
T_1 V_36 ;
struct V_45 * V_46 ;
int V_47 ;
V_36 = F_7 ( V_7 , & V_7 -> V_8 . V_9 . V_48 ,
( V_7 -> V_8 . V_39 * sizeof( struct V_45 ) ) ) ;
if ( V_36 )
goto V_73;
V_7 -> V_8 . V_9 . V_50 . V_74 = (struct V_45 * ) V_7 -> V_8 . V_9 . V_48 . V_52 ;
for ( V_47 = 0 ; V_47 < V_7 -> V_8 . V_39 ; V_47 ++ ) {
V_46 = & V_7 -> V_8 . V_9 . V_50 . V_74 [ V_47 ] ;
V_36 = F_6 ( V_7 , V_46 ,
V_75 ,
V_7 -> V_8 . V_76 ,
V_40 ) ;
if ( V_36 )
goto V_77;
}
V_73:
return V_36 ;
V_77:
V_47 -- ;
for (; V_47 >= 0 ; V_47 -- )
F_8 ( V_7 , & V_7 -> V_8 . V_9 . V_50 . V_74 [ V_47 ] ) ;
F_17 ( V_7 , & V_7 -> V_8 . V_9 . V_48 ) ;
return V_36 ;
}
static void F_19 ( struct V_6 * V_7 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_7 -> V_8 . V_44 ; V_47 ++ )
F_8 ( V_7 , & V_7 -> V_8 . V_20 . V_50 . V_51 [ V_47 ] ) ;
F_8 ( V_7 , & V_7 -> V_8 . V_20 . V_37 ) ;
F_17 ( V_7 , & V_7 -> V_8 . V_20 . V_48 ) ;
}
static void F_20 ( struct V_6 * V_7 )
{
int V_47 ;
for ( V_47 = 0 ; V_47 < V_7 -> V_8 . V_39 ; V_47 ++ )
if ( V_7 -> V_8 . V_9 . V_50 . V_74 [ V_47 ] . V_69 )
F_8 ( V_7 , & V_7 -> V_8 . V_9 . V_50 . V_74 [ V_47 ] ) ;
F_17 ( V_7 , & V_7 -> V_8 . V_9 . V_41 ) ;
F_8 ( V_7 , & V_7 -> V_8 . V_9 . V_37 ) ;
F_17 ( V_7 , & V_7 -> V_8 . V_9 . V_48 ) ;
}
static T_1 F_21 ( struct V_6 * V_7 )
{
T_1 V_36 = 0 ;
T_2 V_78 = 0 ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_12 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_10 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_14 , ( V_7 -> V_8 . V_39 |
V_79 ) ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_16 , F_16 ( V_7 -> V_8 . V_9 . V_37 . V_69 ) ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_18 , F_15 ( V_7 -> V_8 . V_9 . V_37 . V_69 ) ) ;
V_78 = F_23 ( V_7 , V_7 -> V_8 . V_9 . V_16 ) ;
if ( V_78 != F_16 ( V_7 -> V_8 . V_9 . V_37 . V_69 ) )
V_36 = V_80 ;
return V_36 ;
}
static T_1 F_24 ( struct V_6 * V_7 )
{
T_1 V_36 = 0 ;
T_2 V_78 = 0 ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_12 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_10 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_14 , ( V_7 -> V_8 . V_44 |
V_81 ) ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_16 , F_16 ( V_7 -> V_8 . V_20 . V_37 . V_69 ) ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_18 , F_15 ( V_7 -> V_8 . V_20 . V_37 . V_69 ) ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_10 , V_7 -> V_8 . V_44 - 1 ) ;
V_78 = F_23 ( V_7 , V_7 -> V_8 . V_20 . V_16 ) ;
if ( V_78 != F_16 ( V_7 -> V_8 . V_20 . V_37 . V_69 ) )
V_36 = V_80 ;
return V_36 ;
}
static T_1 F_25 ( struct V_6 * V_7 )
{
T_1 V_36 = 0 ;
if ( V_7 -> V_8 . V_9 . V_82 > 0 ) {
V_36 = V_83 ;
goto V_84;
}
if ( ( V_7 -> V_8 . V_39 == 0 ) ||
( V_7 -> V_8 . V_76 == 0 ) ) {
V_36 = V_85 ;
goto V_84;
}
V_7 -> V_8 . V_9 . V_86 = 0 ;
V_7 -> V_8 . V_9 . V_87 = 0 ;
V_7 -> V_8 . V_9 . V_82 = V_7 -> V_8 . V_39 ;
V_36 = F_5 ( V_7 ) ;
if ( V_36 )
goto V_84;
V_36 = F_18 ( V_7 ) ;
if ( V_36 )
goto V_88;
V_36 = F_21 ( V_7 ) ;
if ( V_36 )
goto V_88;
goto V_84;
V_88:
F_10 ( V_7 ) ;
V_84:
return V_36 ;
}
static T_1 F_26 ( struct V_6 * V_7 )
{
T_1 V_36 = 0 ;
if ( V_7 -> V_8 . V_20 . V_82 > 0 ) {
V_36 = V_83 ;
goto V_84;
}
if ( ( V_7 -> V_8 . V_44 == 0 ) ||
( V_7 -> V_8 . V_54 == 0 ) ) {
V_36 = V_85 ;
goto V_84;
}
V_7 -> V_8 . V_20 . V_86 = 0 ;
V_7 -> V_8 . V_20 . V_87 = 0 ;
V_7 -> V_8 . V_20 . V_82 = V_7 -> V_8 . V_44 ;
V_36 = F_9 ( V_7 ) ;
if ( V_36 )
goto V_84;
V_36 = F_12 ( V_7 ) ;
if ( V_36 )
goto V_88;
V_36 = F_24 ( V_7 ) ;
if ( V_36 )
goto V_88;
goto V_84;
V_88:
F_11 ( V_7 ) ;
V_84:
return V_36 ;
}
static T_1 F_27 ( struct V_6 * V_7 )
{
T_1 V_36 = 0 ;
if ( V_7 -> V_8 . V_9 . V_82 == 0 )
return V_83 ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_12 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_10 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_14 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_16 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_18 , 0 ) ;
F_28 ( & V_7 -> V_8 . V_89 ) ;
V_7 -> V_8 . V_9 . V_82 = 0 ;
F_20 ( V_7 ) ;
F_29 ( & V_7 -> V_8 . V_89 ) ;
return V_36 ;
}
static T_1 F_30 ( struct V_6 * V_7 )
{
T_1 V_36 = 0 ;
if ( V_7 -> V_8 . V_20 . V_82 == 0 )
return V_83 ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_12 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_10 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_14 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_16 , 0 ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_18 , 0 ) ;
F_28 ( & V_7 -> V_8 . V_90 ) ;
V_7 -> V_8 . V_20 . V_82 = 0 ;
F_19 ( V_7 ) ;
F_29 ( & V_7 -> V_8 . V_90 ) ;
return V_36 ;
}
T_1 F_31 ( struct V_6 * V_7 )
{
T_1 V_36 ;
V_61 V_91 , V_92 ;
int V_93 = 0 ;
if ( ( V_7 -> V_8 . V_44 == 0 ) ||
( V_7 -> V_8 . V_39 == 0 ) ||
( V_7 -> V_8 . V_54 == 0 ) ||
( V_7 -> V_8 . V_76 == 0 ) ) {
V_36 = V_85 ;
goto V_84;
}
F_32 ( & V_7 -> V_8 . V_89 ) ;
F_32 ( & V_7 -> V_8 . V_90 ) ;
F_3 ( V_7 ) ;
V_7 -> V_8 . V_94 = V_95 ;
V_36 = F_25 ( V_7 ) ;
if ( V_36 )
goto V_96;
V_36 = F_26 ( V_7 ) ;
if ( V_36 )
goto V_97;
do {
V_36 = F_33 ( V_7 ,
& V_7 -> V_8 . V_98 ,
& V_7 -> V_8 . V_99 ,
& V_7 -> V_8 . V_100 ,
& V_7 -> V_8 . V_101 ,
& V_7 -> V_8 . V_102 ,
NULL ) ;
if ( V_36 != V_103 )
break;
V_93 ++ ;
F_34 ( 100 ) ;
F_35 ( V_7 ) ;
} while ( V_93 < 10 );
if ( V_36 != V_104 )
goto V_105;
F_36 ( V_7 , V_106 ,
& V_7 -> V_107 . V_108 ) ;
F_36 ( V_7 , V_109 , & V_91 ) ;
F_36 ( V_7 , V_110 , & V_92 ) ;
V_7 -> V_107 . V_111 = ( V_92 << 16 ) | V_91 ;
if ( V_7 -> V_8 . V_101 > V_112 ) {
V_36 = V_113 ;
goto V_105;
}
F_37 ( V_7 , V_114 , 0 , NULL ) ;
V_7 -> V_8 . V_115 = false ;
V_7 -> V_116 = V_117 ;
V_36 = F_38 ( V_7 ,
V_118 ,
0 ,
NULL ) ;
V_36 = 0 ;
goto V_84;
V_105:
F_30 ( V_7 ) ;
V_97:
F_27 ( V_7 ) ;
V_96:
V_84:
return V_36 ;
}
T_1 F_39 ( struct V_6 * V_7 )
{
T_1 V_36 = 0 ;
if ( F_40 ( V_7 ) )
F_41 ( V_7 , true ) ;
F_27 ( V_7 ) ;
F_30 ( V_7 ) ;
return V_36 ;
}
static V_61 F_42 ( struct V_6 * V_7 )
{
struct V_119 * V_9 = & ( V_7 -> V_8 . V_9 ) ;
struct V_42 * V_120 ;
V_61 V_121 = V_9 -> V_87 ;
struct V_1 V_122 ;
struct V_1 * V_2 ;
V_2 = F_13 ( * V_9 , V_121 ) ;
V_120 = F_43 ( * V_9 , V_121 ) ;
while ( F_23 ( V_7 , V_7 -> V_8 . V_9 . V_12 ) != V_121 ) {
F_44 ( V_7 , V_123 ,
L_1 , V_124 , V_121 ,
F_23 ( V_7 , V_7 -> V_8 . V_9 . V_12 ) ) ;
if ( V_120 -> V_125 ) {
T_3 V_126 =
( T_3 ) V_120 -> V_125 ;
V_122 = * V_2 ;
V_126 ( V_7 , & V_122 ) ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
V_121 ++ ;
if ( V_121 == V_9 -> V_82 )
V_121 = 0 ;
V_2 = F_13 ( * V_9 , V_121 ) ;
V_120 = F_43 ( * V_9 , V_121 ) ;
}
V_9 -> V_87 = V_121 ;
return F_45 ( V_9 ) ;
}
static bool F_46 ( struct V_6 * V_7 )
{
return F_23 ( V_7 , V_7 -> V_8 . V_9 . V_12 ) == V_7 -> V_8 . V_9 . V_86 ;
}
T_1 F_47 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
void * V_127 ,
V_61 V_128 ,
struct V_42 * V_129 )
{
T_1 V_130 = 0 ;
struct V_45 * V_131 = NULL ;
struct V_42 * V_120 ;
struct V_1 * V_132 ;
bool V_133 = false ;
V_61 V_63 = 0 ;
T_2 V_134 = 0 ;
V_134 = F_23 ( V_7 , V_7 -> V_8 . V_9 . V_12 ) ;
if ( V_134 >= V_7 -> V_8 . V_39 ) {
F_44 ( V_7 , V_123 ,
L_2 , V_134 ) ;
V_130 = V_135 ;
goto V_136;
}
if ( V_7 -> V_8 . V_9 . V_82 == 0 ) {
F_44 ( V_7 , V_123 ,
L_3 ) ;
V_130 = V_135 ;
goto V_136;
}
V_120 = F_43 ( V_7 -> V_8 . V_9 , V_7 -> V_8 . V_9 . V_86 ) ;
if ( V_129 ) {
* V_120 = * V_129 ;
if ( V_120 -> V_137 ) {
V_2 -> V_64 =
F_14 ( F_15 ( V_120 -> V_137 ) ) ;
V_2 -> V_65 =
F_14 ( F_16 ( V_120 -> V_137 ) ) ;
}
} else {
memset ( V_120 , 0 , sizeof( struct V_42 ) ) ;
}
V_2 -> V_56 &= ~ F_2 ( V_120 -> V_138 ) ;
V_2 -> V_56 |= F_2 ( V_120 -> V_139 ) ;
F_28 ( & V_7 -> V_8 . V_89 ) ;
if ( V_128 > V_7 -> V_8 . V_76 ) {
F_44 ( V_7 ,
V_123 ,
L_4 ,
V_128 ) ;
V_130 = V_140 ;
goto V_141;
}
if ( V_120 -> V_142 && ! V_120 -> V_143 ) {
F_44 ( V_7 ,
V_123 ,
L_5 ) ;
V_130 = V_144 ;
goto V_141;
}
if ( F_42 ( V_7 ) == 0 ) {
F_44 ( V_7 ,
V_123 ,
L_6 ) ;
V_130 = V_145 ;
goto V_141;
}
V_132 = F_13 ( V_7 -> V_8 . V_9 , V_7 -> V_8 . V_9 . V_86 ) ;
* V_132 = * V_2 ;
if ( V_127 != NULL ) {
V_131 = & ( V_7 -> V_8 . V_9 . V_50 . V_74 [ V_7 -> V_8 . V_9 . V_86 ] ) ;
memcpy ( V_131 -> V_52 , V_127 , V_128 ) ;
V_132 -> V_60 = F_2 ( V_128 ) ;
V_132 -> V_66 . V_67 . V_68 =
F_14 ( F_15 ( V_131 -> V_69 ) ) ;
V_132 -> V_66 . V_67 . V_70 =
F_14 ( F_16 ( V_131 -> V_69 ) ) ;
}
F_44 ( V_7 , V_123 , L_7 ) ;
F_48 ( V_7 , V_146 , ( void * ) V_132 ,
V_127 , V_128 ) ;
( V_7 -> V_8 . V_9 . V_86 ) ++ ;
if ( V_7 -> V_8 . V_9 . V_86 == V_7 -> V_8 . V_9 . V_82 )
V_7 -> V_8 . V_9 . V_86 = 0 ;
if ( ! V_120 -> V_142 )
F_22 ( V_7 , V_7 -> V_8 . V_9 . V_10 , V_7 -> V_8 . V_9 . V_86 ) ;
if ( ! V_120 -> V_143 && ! V_120 -> V_142 ) {
T_2 V_147 = 0 ;
do {
if ( F_46 ( V_7 ) )
break;
F_49 ( 1000 , 2000 ) ;
V_147 ++ ;
} while ( V_147 < V_7 -> V_8 . V_94 );
}
if ( F_46 ( V_7 ) ) {
* V_2 = * V_132 ;
if ( V_127 != NULL )
memcpy ( V_127 , V_131 -> V_52 , V_128 ) ;
V_63 = F_50 ( V_2 -> V_63 ) ;
if ( V_63 != 0 ) {
F_44 ( V_7 ,
V_123 ,
L_8 ,
V_63 ) ;
V_63 &= 0xff ;
}
V_133 = true ;
if ( (enum V_148 ) V_63 == V_149 )
V_130 = 0 ;
else
V_130 = V_80 ;
V_7 -> V_8 . V_150 = (enum V_148 ) V_63 ;
}
F_44 ( V_7 , V_123 ,
L_9 ) ;
F_48 ( V_7 , V_146 , ( void * ) V_2 , V_127 , V_128 ) ;
if ( ( ! V_133 ) &&
( ! V_120 -> V_143 && ! V_120 -> V_142 ) ) {
F_44 ( V_7 ,
V_123 ,
L_10 ) ;
V_130 = V_103 ;
}
V_141:
F_29 ( & V_7 -> V_8 . V_89 ) ;
V_136:
return V_130 ;
}
void F_51 ( struct V_1 * V_2 ,
V_61 V_3 )
{
memset ( ( void * ) V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = F_2 ( V_3 ) ;
V_2 -> V_56 = F_2 ( V_151 ) ;
}
T_1 F_52 ( struct V_6 * V_7 ,
struct V_152 * V_153 ,
V_61 * V_154 )
{
T_1 V_36 = 0 ;
V_61 V_121 = V_7 -> V_8 . V_20 . V_87 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
V_61 V_155 ;
V_61 V_60 ;
V_61 V_56 ;
V_61 V_156 ;
F_28 ( & V_7 -> V_8 . V_90 ) ;
V_156 = ( F_23 ( V_7 , V_7 -> V_8 . V_20 . V_12 ) & V_157 ) ;
if ( V_156 == V_121 ) {
V_36 = V_158 ;
goto V_159;
}
V_2 = F_13 ( V_7 -> V_8 . V_20 , V_121 ) ;
V_155 = V_121 ;
V_56 = F_50 ( V_2 -> V_56 ) ;
if ( V_56 & V_160 ) {
V_36 = V_80 ;
V_7 -> V_8 . V_161 =
(enum V_148 ) F_50 ( V_2 -> V_63 ) ;
F_44 ( V_7 ,
V_123 ,
L_11 ,
V_7 -> V_8 . V_161 ) ;
}
V_153 -> V_2 = * V_2 ;
V_60 = F_50 ( V_2 -> V_60 ) ;
V_153 -> V_162 = F_53 ( V_60 , V_153 -> V_163 ) ;
if ( V_153 -> V_164 != NULL && ( V_153 -> V_162 != 0 ) )
memcpy ( V_153 -> V_164 , V_7 -> V_8 . V_20 . V_50 . V_51 [ V_155 ] . V_52 ,
V_153 -> V_162 ) ;
F_44 ( V_7 , V_123 , L_12 ) ;
F_48 ( V_7 , V_146 , ( void * ) V_2 , V_153 -> V_164 ,
V_7 -> V_8 . V_54 ) ;
V_46 = & V_7 -> V_8 . V_20 . V_50 . V_51 [ V_121 ] ;
memset ( ( void * ) V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_56 = F_2 ( V_57 ) ;
if ( V_7 -> V_8 . V_54 > V_58 )
V_2 -> V_56 |= F_2 ( V_59 ) ;
V_2 -> V_60 = F_2 ( ( V_61 ) V_46 -> V_62 ) ;
V_2 -> V_66 . V_67 . V_68 = F_14 ( F_15 ( V_46 -> V_69 ) ) ;
V_2 -> V_66 . V_67 . V_70 = F_14 ( F_16 ( V_46 -> V_69 ) ) ;
F_22 ( V_7 , V_7 -> V_8 . V_20 . V_10 , V_121 ) ;
V_121 ++ ;
if ( V_121 == V_7 -> V_8 . V_44 )
V_121 = 0 ;
V_7 -> V_8 . V_20 . V_87 = V_121 ;
V_7 -> V_8 . V_20 . V_86 = V_156 ;
V_159:
if ( V_154 != NULL )
* V_154 = ( V_121 > V_156 ? V_7 -> V_8 . V_20 . V_82 : 0 ) + ( V_156 - V_121 ) ;
F_29 ( & V_7 -> V_8 . V_90 ) ;
if ( F_1 ( & V_153 -> V_2 ) ) {
if ( V_7 -> V_8 . V_115 ) {
F_54 ( V_7 ) ;
V_7 -> V_8 . V_115 = false ;
}
}
return V_36 ;
}
static void F_35 ( struct V_6 * V_7 )
{
V_7 -> V_8 . V_9 . V_86 = 0 ;
V_7 -> V_8 . V_9 . V_87 = 0 ;
F_21 ( V_7 ) ;
V_7 -> V_8 . V_20 . V_86 = 0 ;
V_7 -> V_8 . V_20 . V_87 = 0 ;
F_24 ( V_7 ) ;
}
