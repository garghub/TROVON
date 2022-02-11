int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
int V_6 , V_7 = 10 ;
struct V_8 * V_9 = V_10 . V_9 ;
F_2 ( & ( V_2 -> V_11 -> V_12 ) ) ;
do {
V_6 = F_3 ( V_9 , V_4 ) ;
} while ( V_6 == - V_13 && ! V_5 && V_7 -- );
if ( V_6 ) {
F_4 ( & V_9 -> V_14 , L_1
L_2 , V_6 , V_4 -> V_15 ) ;
F_2 ( & ( V_2 -> V_11 -> V_16 ) ) ;
F_5 ( & ( V_2 -> V_11 -> V_17 ) , V_4 -> V_15 ) ;
F_5 ( & ( V_2 -> V_11 -> V_18 ) , V_19 -> V_20 ) ;
}
return V_6 ;
}
struct V_21 * F_6 ( struct V_21 * V_22 ,
T_2 * V_23 ,
unsigned int V_24 ,
T_1 V_25 )
{
unsigned int V_26 = 0 ;
struct V_21 * V_27 ;
T_3 V_28 = ( T_3 ) V_23 ;
T_3 V_29 ;
if ( F_7 ( V_23 ) )
V_28 = F_8 ( F_9 ( V_23 ) )
+ F_10 ( V_28 ) ;
else
V_28 = F_11 ( V_28 ) ;
V_29 = V_28 + V_24 ;
for ( V_27 = V_22 ; V_26 < V_24 ; V_27 ++ ) {
T_3 V_30 ;
V_27 -> V_31 = V_28 ;
V_28 = F_12 ( T_3 , F_13 ( V_28 + V_32 ) ,
V_29 ) ;
V_30 = ( V_27 -> V_31 & V_33 ) + V_34 ;
V_27 -> V_24 = F_12 ( T_3 , V_28 , V_30 ) - V_27 -> V_31 ;
V_26 += V_27 -> V_24 ;
if ( V_28 >= V_30 &&
F_7 ( V_23 + V_26 ) ) {
V_28 = F_8 ( F_9 (
V_23 + V_26 ) ) ;
V_29 = V_28 + V_24 - V_26 ;
}
if ( ( V_27 - V_22 ) == V_25 ) {
F_14 ( L_3 ,
V_19 -> V_20 ) ;
return NULL ;
}
}
return V_27 ;
}
struct V_21 * F_15 ( struct V_21 * V_35 ,
unsigned int V_36 ,
struct V_37 * V_38 ,
unsigned int V_39 ,
unsigned int V_40 )
{
struct V_41 V_42 ;
struct V_21 * V_21 = V_35 ;
unsigned int V_43 , V_44 = 0 , V_24 = V_40 ;
char * V_45 ;
for (; ; ) {
F_16 ( & V_42 , V_38 ) ;
if ( V_39 < V_44 + V_38 -> V_46 )
break;
V_44 += V_38 -> V_46 ;
V_38 = F_17 ( V_38 ) ;
}
F_18 ( & V_42 , V_39 - V_44 ) ;
while ( V_24 && V_21 ) {
V_43 = F_19 ( & V_42 , V_24 ) ;
if ( ! V_43 ) {
F_16 ( & V_42 , F_20 ( V_42 . V_27 ) ) ;
V_43 = F_19 ( & V_42 , V_24 ) ;
}
V_45 = F_21 ( & V_42 ) ;
V_21 = F_6 ( V_21 , V_45 , V_43 , V_36 ) ;
V_24 -= V_43 ;
F_22 ( V_45 ) ;
F_18 ( & V_42 , V_43 ) ;
F_23 ( & V_42 , V_47 , V_24 ) ;
}
return V_21 ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_37 * V_45 ,
struct V_37 * V_50 ,
unsigned int V_51 ,
unsigned int V_44 ,
T_2 * V_52 )
{
struct V_21 * V_53 = V_2 -> V_54 ;
struct V_21 * V_55 = V_2 -> V_56 ;
if ( V_52 )
memcpy ( V_52 , V_49 -> V_57 , V_58 ) ;
V_53 = F_15 ( V_53 , V_2 -> V_59 -> V_36 , V_50 ,
V_44 , V_51 ) ;
V_55 = F_15 ( V_55 , V_2 -> V_59 -> V_36 , V_45 ,
V_44 , V_51 ) ;
V_2 -> V_4 . V_60 = ( V_2 -> V_54 - V_53 ) * sizeof( struct V_21 ) ;
V_2 -> V_4 . V_61 = ( V_2 -> V_56 - V_55 ) * sizeof( struct V_21 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , unsigned int V_62 )
{
F_26 ( & V_2 -> V_63 ) ;
memset ( V_2 -> V_64 , 0 , V_2 -> V_65 ) ;
V_2 -> V_66 -> V_67 . V_68 |= V_69 ;
V_2 -> V_4 . V_70 = V_62 ;
V_2 -> V_4 . V_66 = F_11 ( V_2 -> V_66 ) ;
V_2 -> V_4 . V_71 = F_11 ( V_2 -> V_54 ) ;
V_2 -> V_4 . V_72 = F_11 ( V_2 -> V_56 ) ;
if ( V_2 -> V_73 ) {
V_2 -> V_73 -> V_67 . V_68 |= V_69 ;
V_2 -> V_74 . V_70 = V_62 ;
V_2 -> V_74 . V_66 = F_11 ( V_2 -> V_73 ) ;
V_2 -> V_74 . V_71 = F_11 ( V_2 -> V_54 ) ;
V_2 -> V_74 . V_72 = F_11 ( V_2 -> V_56 ) ;
}
}
static void F_27 ( struct V_75 * V_14 ,
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
if ( ! strncmp ( V_77 -> V_80 , L_4 , V_77 -> V_46 ) ) {
V_79 -> V_81 = V_82 ;
V_79 -> V_70 |= V_83 ;
} else {
F_28 ( V_14 , L_5 , V_84 ,
( char * ) V_77 -> V_80 ) ;
}
}
static void F_29 ( struct V_75 * V_14 ,
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
if ( V_77 -> V_46 != sizeof( V_79 -> V_85 ) ) {
F_30 ( V_14 , L_6
L_7 , V_84 ) ;
F_4 ( V_14 , L_8
L_9 , V_84 ,
V_77 -> V_46 , sizeof( V_79 -> V_85 ) ) ;
return;
}
V_79 -> V_85 = * ( T_1 * ) V_77 -> V_80 ;
V_79 -> V_70 |= V_86 ;
}
static void F_31 ( struct V_75 * V_14 ,
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_87 * V_88 ;
struct V_89 * V_90 ;
unsigned int V_91 , V_92 , V_93 ;
V_90 = (struct V_89 * ) V_77 -> V_80 ;
V_93 = V_77 -> V_46 ;
V_91 = 0 ;
while ( ( V_91 + sizeof( struct V_89 ) ) <= V_93 ) {
V_91 += sizeof( struct V_89 ) ;
V_88 = V_90 -> V_88 ;
for ( V_92 = 0 ;
( ( V_91 + sizeof( struct V_87 ) ) <= V_93 ) &&
V_92 < V_90 -> V_94 ;
V_92 ++ ) {
if ( V_90 -> V_95 > V_96 || V_90 -> V_97 > V_98 ) {
F_30 ( V_14 , L_10
L_11 , V_90 -> V_95 ,
V_90 -> V_97 ) ;
goto V_99;
}
switch ( V_88 -> V_100 ) {
case 128 :
case 160 :
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 0 ] . V_101 =
V_88 -> V_101 ;
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 0 ] . V_36 =
V_88 -> V_36 ;
break;
case 192 :
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 1 ] . V_101 =
V_88 -> V_101 ;
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 1 ] . V_36 =
V_88 -> V_36 ;
break;
case 256 :
if ( V_90 -> V_95 == V_102 ) {
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 2 ] .
V_101 = V_88 -> V_101 ;
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 2 ] . V_36 =
V_88 -> V_36 ;
} else if ( V_90 -> V_95 == V_103 ||
V_90 -> V_95 == V_104 ) {
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 1 ] .
V_101 = V_88 -> V_101 ;
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 1 ] . V_36 =
V_88 -> V_36 ;
} else {
F_32 ( V_14 , L_12
L_13
L_14 , V_90 -> V_95 ) ;
}
break;
case 512 :
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 2 ] . V_101 =
V_88 -> V_101 ;
V_79 -> V_59 [ V_90 -> V_95 ] [ V_90 -> V_97 ] [ 2 ] . V_36 =
V_88 -> V_36 ;
break;
default:
F_32 ( V_14 , L_15
L_16 , V_90 -> V_95 ,
V_88 -> V_100 ) ;
break;
}
V_99:
V_91 += sizeof( struct V_87 ) ;
V_88 ++ ;
}
V_90 = (struct V_89 * ) V_88 ;
}
V_79 -> V_70 |= V_105 ;
}
static void F_33 ( struct V_75 * V_14 , struct V_78 * V_79 )
{
struct V_106 * V_107 = V_14 -> V_108 ;
struct V_76 * V_77 ;
V_77 = F_34 ( V_107 , L_17 , NULL ) ;
if ( ! V_77 )
F_28 ( V_14 , L_18 , V_84 ) ;
else
F_27 ( V_14 , V_77 , V_79 ) ;
V_77 = F_34 ( V_107 , L_19 , NULL ) ;
if ( ! V_77 )
F_28 ( V_14 , L_20 ,
V_84 ) ;
else
F_29 ( V_14 , V_77 , V_79 ) ;
V_77 = F_34 ( V_107 , L_21 , NULL ) ;
if ( ! V_77 )
F_28 ( V_14 , L_22 ,
V_84 ) ;
else
F_31 ( V_14 , V_77 , V_79 ) ;
}
static int F_35 ( void )
{
int V_6 = - 1 ;
if ( V_10 . V_109 . V_70 != V_110 )
goto V_72;
memset ( & V_10 . V_11 , 0 , sizeof( struct V_111 ) ) ;
V_6 = F_36 ( & V_10 ) ;
if ( V_6 )
goto V_72;
V_10 . V_109 . V_81 = V_112 ;
V_6 = F_37 ( & V_113 ) ;
if ( V_6 )
goto V_72;
V_6 = F_37 ( & V_114 ) ;
if ( V_6 )
goto V_115;
V_6 = F_37 ( & V_116 ) ;
if ( V_6 )
goto V_117;
V_6 = F_37 ( & V_118 ) ;
if ( V_6 )
goto V_119;
V_6 = F_37 ( & V_120 ) ;
if ( V_6 )
goto V_121;
V_6 = F_37 ( & V_122 ) ;
if ( V_6 )
goto V_123;
V_6 = F_37 ( & V_124 ) ;
if ( V_6 )
goto V_125;
V_6 = F_37 ( & V_126 ) ;
if ( V_6 )
goto V_127;
V_6 = F_38 ( & V_128 ) ;
if ( V_6 )
goto V_129;
V_6 = F_38 ( & V_130 ) ;
if ( V_6 )
goto V_131;
V_6 = F_38 ( & V_132 ) ;
if ( V_6 )
goto V_133;
goto V_72;
V_133:
F_39 ( & V_130 ) ;
V_131:
F_39 ( & V_128 ) ;
V_129:
F_40 ( & V_126 ) ;
V_127:
F_40 ( & V_124 ) ;
V_125:
F_40 ( & V_122 ) ;
V_123:
F_40 ( & V_120 ) ;
V_121:
F_40 ( & V_118 ) ;
V_119:
F_40 ( & V_116 ) ;
V_117:
F_40 ( & V_114 ) ;
V_115:
F_40 ( & V_113 ) ;
V_72:
return V_6 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_95 , T_1 V_97 )
{
if ( V_10 . V_109 . V_81 != V_112 ) {
F_14 ( L_23
L_24 ) ;
return - V_134 ;
}
if ( V_97 == V_135 || V_97 == V_136 )
V_2 -> V_65 = ( 4 * V_32 ) +
sizeof( struct V_137 ) ;
else
V_2 -> V_65 = ( 3 * V_32 ) +
sizeof( struct V_137 ) ;
V_2 -> V_64 = F_42 ( V_2 -> V_65 , V_138 ) ;
if ( ! V_2 -> V_64 )
return - V_139 ;
V_2 -> V_66 = (struct V_137 * ) ( F_43 ( ( T_3 ) V_2 -> V_64 ,
( T_3 ) V_32 ) ) ;
V_2 -> V_54 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_66 + V_32 ) ;
V_2 -> V_56 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_54 + V_32 ) ;
if ( V_97 == V_135 || V_97 == V_136 )
V_2 -> V_73 =
(struct V_137 * ) ( ( T_2 * ) V_2 -> V_56 +
V_32 ) ;
V_2 -> V_11 = & V_10 . V_11 ;
memcpy ( V_2 -> V_79 , V_10 . V_109 . V_59 [ V_95 ] [ V_97 ] ,
sizeof( struct V_140 ) * 3 ) ;
return 0 ;
}
int F_44 ( struct V_141 * V_142 )
{
return F_41 ( F_45 ( V_142 ) , V_102 ,
V_136 ) ;
}
int F_46 ( struct V_141 * V_142 )
{
return F_41 ( F_45 ( V_142 ) , V_102 ,
V_135 ) ;
}
int F_47 ( struct V_141 * V_142 )
{
return F_41 ( F_45 ( V_142 ) , V_102 ,
V_143 ) ;
}
int F_48 ( struct V_141 * V_142 )
{
return F_41 ( F_45 ( V_142 ) , V_102 ,
V_144 ) ;
}
int F_49 ( struct V_141 * V_142 )
{
return F_41 ( F_45 ( V_142 ) , V_102 ,
V_145 ) ;
}
int F_50 ( struct V_141 * V_142 )
{
return F_41 ( F_45 ( V_142 ) , V_104 , V_146 ) ;
}
int F_51 ( struct V_141 * V_142 )
{
return F_41 ( F_45 ( V_142 ) , V_102 ,
V_147 ) ;
}
void F_52 ( struct V_141 * V_142 )
{
struct V_1 * V_2 = F_45 ( V_142 ) ;
F_53 ( V_2 -> V_64 ) ;
V_2 -> V_66 = NULL ;
V_2 -> V_73 = NULL ;
V_2 -> V_54 = NULL ;
V_2 -> V_56 = NULL ;
}
static int F_54 ( struct V_8 * V_9 , const struct V_148 * V_149 )
{
F_4 ( & V_9 -> V_14 , L_25 ,
V_9 -> V_150 , V_9 -> V_151 ) ;
if ( V_10 . V_9 ) {
F_30 ( & V_9 -> V_14 , L_26
L_27 , V_84 ) ;
return - V_152 ;
}
V_10 . V_9 = V_9 ;
F_33 ( & V_9 -> V_14 , & V_10 . V_109 ) ;
return F_35 () ;
}
static int F_55 ( struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_14 , L_28 ,
V_9 -> V_153 ) ;
if ( V_10 . V_109 . V_81 == V_112 ) {
F_56 ( & V_10 ) ;
F_40 ( & V_124 ) ;
F_40 ( & V_126 ) ;
F_40 ( & V_120 ) ;
F_40 ( & V_122 ) ;
F_40 ( & V_116 ) ;
F_40 ( & V_118 ) ;
F_40 ( & V_114 ) ;
F_40 ( & V_113 ) ;
F_39 ( & V_128 ) ;
F_39 ( & V_130 ) ;
F_39 ( & V_132 ) ;
}
return 0 ;
}
static int T_4 F_57 ( void )
{
return F_58 ( & V_10 . V_154 ) ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_10 . V_154 ) ;
}
