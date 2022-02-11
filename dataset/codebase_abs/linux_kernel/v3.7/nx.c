int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
int V_6 , V_7 = 10 ;
struct V_8 * V_9 = V_10 . V_9 ;
F_2 ( & ( V_2 -> V_11 -> V_12 ) ) ;
do {
V_6 = F_3 ( V_9 , V_4 ) ;
} while ( ( V_6 == - V_13 && ! V_5 && V_7 -- ) ||
( V_6 == - V_13 && V_5 && F_4 () ) );
if ( V_6 ) {
F_5 ( & V_9 -> V_14 , L_1
L_2 , V_6 , V_4 -> V_15 ) ;
F_2 ( & ( V_2 -> V_11 -> V_16 ) ) ;
F_6 ( & ( V_2 -> V_11 -> V_17 ) , V_4 -> V_15 ) ;
F_6 ( & ( V_2 -> V_11 -> V_18 ) , V_19 -> V_20 ) ;
}
return V_6 ;
}
struct V_21 * F_7 ( struct V_21 * V_22 ,
T_2 * V_23 ,
unsigned int V_24 ,
T_1 V_25 )
{
unsigned int V_26 = 0 ;
struct V_21 * V_27 ;
T_3 V_28 = ( T_3 ) V_23 ;
T_3 V_29 ;
if ( F_8 ( V_23 ) )
V_28 = F_9 ( F_10 ( V_23 ) )
+ F_11 ( V_28 ) ;
else
V_28 = F_12 ( V_28 ) ;
V_29 = V_28 + V_24 ;
for ( V_27 = V_22 ; V_26 < V_24 ; V_27 ++ ) {
V_27 -> V_30 = V_28 ;
V_28 = F_13 ( T_3 , F_14 ( V_28 + V_31 ) , V_29 ) ;
V_27 -> V_24 = V_28 - V_27 -> V_30 ;
V_26 += V_27 -> V_24 ;
if ( ( V_27 - V_22 ) == V_25 ) {
F_15 ( L_3 ,
V_19 -> V_20 ) ;
return NULL ;
}
}
return V_27 ;
}
struct V_21 * F_16 ( struct V_21 * V_32 ,
unsigned int V_33 ,
struct V_34 * V_35 ,
unsigned int V_36 ,
unsigned int V_37 )
{
struct V_38 V_39 ;
struct V_21 * V_21 = V_32 ;
unsigned int V_40 , V_41 = 0 , V_24 = V_37 ;
char * V_42 ;
for (; ; ) {
F_17 ( & V_39 , V_35 ) ;
if ( V_36 < V_41 + V_35 -> V_43 )
break;
V_41 += V_35 -> V_43 ;
V_35 = F_18 ( V_35 ) ;
}
F_19 ( & V_39 , V_36 - V_41 ) ;
while ( V_24 && V_21 ) {
V_40 = F_20 ( & V_39 , V_24 ) ;
if ( ! V_40 ) {
F_17 ( & V_39 , F_21 ( V_39 . V_27 ) ) ;
V_40 = F_20 ( & V_39 , V_24 ) ;
}
V_42 = F_22 ( & V_39 ) ;
V_21 = F_7 ( V_21 , V_42 , V_40 , V_33 ) ;
V_24 -= V_40 ;
F_23 ( V_42 ) ;
F_19 ( & V_39 , V_40 ) ;
F_24 ( & V_39 , V_44 , V_24 ) ;
}
return V_21 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_34 * V_42 ,
struct V_34 * V_47 ,
unsigned int V_48 ,
T_2 * V_49 )
{
struct V_21 * V_50 = V_2 -> V_51 ;
struct V_21 * V_52 = V_2 -> V_53 ;
struct V_54 V_39 ;
int V_6 ;
F_26 ( & V_39 , V_42 , V_47 , V_48 ) ;
V_6 = F_27 ( V_46 , & V_39 , V_55 ) ;
if ( V_6 )
goto V_56;
if ( V_49 )
memcpy ( V_49 , V_39 . V_49 , V_55 ) ;
while ( V_39 . V_48 ) {
V_50 = F_7 ( V_50 , V_39 . V_47 . V_57 . V_30 ,
V_39 . V_48 , V_2 -> V_58 -> V_33 ) ;
V_52 = F_7 ( V_52 , V_39 . V_42 . V_57 . V_30 ,
V_39 . V_48 , V_2 -> V_58 -> V_33 ) ;
V_6 = F_28 ( V_46 , & V_39 , 0 ) ;
if ( V_6 )
break;
}
if ( V_39 . V_48 ) {
V_50 = F_7 ( V_50 , V_39 . V_47 . V_57 . V_30 ,
V_39 . V_48 , V_2 -> V_58 -> V_33 ) ;
V_52 = F_7 ( V_52 , V_39 . V_42 . V_57 . V_30 ,
V_39 . V_48 , V_2 -> V_58 -> V_33 ) ;
V_6 = 0 ;
}
V_2 -> V_4 . V_59 = ( V_2 -> V_51 - V_50 ) * sizeof( struct V_21 ) ;
V_2 -> V_4 . V_60 = ( V_2 -> V_53 - V_52 ) * sizeof( struct V_21 ) ;
V_56:
return V_6 ;
}
void F_29 ( struct V_1 * V_2 , unsigned int V_61 )
{
memset ( V_2 -> V_62 , 0 , V_2 -> V_63 ) ;
V_2 -> V_64 -> V_65 . V_66 |= V_67 ;
V_2 -> V_4 . V_68 = V_61 ;
V_2 -> V_4 . V_64 = F_12 ( V_2 -> V_64 ) ;
V_2 -> V_4 . V_69 = F_12 ( V_2 -> V_51 ) ;
V_2 -> V_4 . V_56 = F_12 ( V_2 -> V_53 ) ;
if ( V_2 -> V_70 ) {
V_2 -> V_70 -> V_65 . V_66 |= V_67 ;
V_2 -> V_71 . V_68 = V_61 ;
V_2 -> V_71 . V_64 = F_12 ( V_2 -> V_70 ) ;
V_2 -> V_71 . V_69 = F_12 ( V_2 -> V_51 ) ;
V_2 -> V_71 . V_56 = F_12 ( V_2 -> V_53 ) ;
}
}
static void F_30 ( struct V_72 * V_14 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
if ( ! strncmp ( V_74 -> V_77 , L_4 , V_74 -> V_43 ) ) {
V_76 -> V_78 = V_79 ;
V_76 -> V_68 |= V_80 ;
} else {
F_31 ( V_14 , L_5 , V_81 ,
( char * ) V_74 -> V_77 ) ;
}
}
static void F_32 ( struct V_72 * V_14 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
if ( V_74 -> V_43 != sizeof( V_76 -> V_82 ) ) {
F_33 ( V_14 , L_6
L_7 , V_81 ) ;
F_5 ( V_14 , L_8
L_9 , V_81 ,
V_74 -> V_43 , sizeof( V_76 -> V_82 ) ) ;
return;
}
V_76 -> V_82 = * ( T_1 * ) V_74 -> V_77 ;
V_76 -> V_68 |= V_83 ;
}
static void F_34 ( struct V_72 * V_14 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_84 * V_85 ;
struct V_86 * V_87 ;
unsigned int V_88 , V_89 , V_90 ;
V_87 = (struct V_86 * ) V_74 -> V_77 ;
V_90 = V_74 -> V_43 ;
V_88 = 0 ;
while ( ( V_88 + sizeof( struct V_86 ) ) <= V_90 ) {
V_88 += sizeof( struct V_86 ) ;
V_85 = V_87 -> V_85 ;
for ( V_89 = 0 ;
( ( V_88 + sizeof( struct V_84 ) ) <= V_90 ) &&
V_89 < V_87 -> V_91 ;
V_89 ++ ) {
if ( V_87 -> V_92 > V_93 || V_87 -> V_94 > V_95 ) {
F_33 ( V_14 , L_10
L_11 , V_87 -> V_92 ,
V_87 -> V_94 ) ;
goto V_96;
}
switch ( V_85 -> V_97 ) {
case 128 :
case 160 :
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 0 ] . V_98 =
V_85 -> V_98 ;
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 0 ] . V_33 =
V_85 -> V_33 ;
break;
case 192 :
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 1 ] . V_98 =
V_85 -> V_98 ;
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 1 ] . V_33 =
V_85 -> V_33 ;
break;
case 256 :
if ( V_87 -> V_92 == V_99 ) {
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 2 ] .
V_98 = V_85 -> V_98 ;
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 2 ] . V_33 =
V_85 -> V_33 ;
} else if ( V_87 -> V_92 == V_100 ||
V_87 -> V_92 == V_101 ) {
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 1 ] .
V_98 = V_85 -> V_98 ;
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 1 ] . V_33 =
V_85 -> V_33 ;
} else {
F_35 ( V_14 , L_12
L_13
L_14 , V_87 -> V_92 ) ;
}
break;
case 512 :
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 2 ] . V_98 =
V_85 -> V_98 ;
V_76 -> V_58 [ V_87 -> V_92 ] [ V_87 -> V_94 ] [ 2 ] . V_33 =
V_85 -> V_33 ;
break;
default:
F_35 ( V_14 , L_15
L_16 , V_87 -> V_92 ,
V_85 -> V_97 ) ;
break;
}
V_96:
V_88 += sizeof( struct V_84 ) ;
V_85 ++ ;
}
V_87 = (struct V_86 * ) V_85 ;
}
V_76 -> V_68 |= V_102 ;
}
static void F_36 ( struct V_72 * V_14 , struct V_75 * V_76 )
{
struct V_103 * V_104 = V_14 -> V_105 ;
struct V_73 * V_74 ;
V_74 = F_37 ( V_104 , L_17 , NULL ) ;
if ( ! V_74 )
F_31 ( V_14 , L_18 , V_81 ) ;
else
F_30 ( V_14 , V_74 , V_76 ) ;
V_74 = F_37 ( V_104 , L_19 , NULL ) ;
if ( ! V_74 )
F_31 ( V_14 , L_20 ,
V_81 ) ;
else
F_32 ( V_14 , V_74 , V_76 ) ;
V_74 = F_37 ( V_104 , L_21 , NULL ) ;
if ( ! V_74 )
F_31 ( V_14 , L_22 ,
V_81 ) ;
else
F_34 ( V_14 , V_74 , V_76 ) ;
}
static int F_38 ( void )
{
int V_6 = - 1 ;
if ( V_10 . V_106 . V_68 != V_107 )
goto V_56;
memset ( & V_10 . V_11 , 0 , sizeof( struct V_108 ) ) ;
V_6 = F_39 ( & V_10 ) ;
if ( V_6 )
goto V_56;
V_6 = F_40 ( & V_109 ) ;
if ( V_6 )
goto V_56;
V_6 = F_40 ( & V_110 ) ;
if ( V_6 )
goto V_111;
V_6 = F_40 ( & V_112 ) ;
if ( V_6 )
goto V_113;
V_6 = F_40 ( & V_114 ) ;
if ( V_6 )
goto V_115;
V_6 = F_40 ( & V_116 ) ;
if ( V_6 )
goto V_117;
V_6 = F_40 ( & V_118 ) ;
if ( V_6 )
goto V_119;
V_6 = F_40 ( & V_120 ) ;
if ( V_6 )
goto V_121;
V_6 = F_40 ( & V_122 ) ;
if ( V_6 )
goto V_123;
V_6 = F_41 ( & V_124 ) ;
if ( V_6 )
goto V_125;
V_6 = F_41 ( & V_126 ) ;
if ( V_6 )
goto V_127;
V_6 = F_41 ( & V_128 ) ;
if ( V_6 )
goto V_129;
V_10 . V_106 . V_78 = V_130 ;
goto V_56;
V_129:
F_42 ( & V_126 ) ;
V_127:
F_42 ( & V_124 ) ;
V_125:
F_43 ( & V_122 ) ;
V_123:
F_43 ( & V_120 ) ;
V_121:
F_43 ( & V_118 ) ;
V_119:
F_43 ( & V_116 ) ;
V_117:
F_43 ( & V_114 ) ;
V_115:
F_43 ( & V_112 ) ;
V_113:
F_43 ( & V_110 ) ;
V_111:
F_43 ( & V_109 ) ;
V_56:
return V_6 ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_92 , T_1 V_94 )
{
if ( V_10 . V_106 . V_78 != V_130 ) {
F_15 ( L_23
L_24 ) ;
return - V_131 ;
}
if ( V_94 == V_132 || V_94 == V_133 )
V_2 -> V_63 = ( 4 * V_31 ) +
sizeof( struct V_134 ) ;
else
V_2 -> V_63 = ( 3 * V_31 ) +
sizeof( struct V_134 ) ;
V_2 -> V_62 = F_45 ( V_2 -> V_63 , V_135 ) ;
if ( ! V_2 -> V_62 )
return - V_136 ;
V_2 -> V_64 = (struct V_134 * ) ( F_46 ( ( T_3 ) V_2 -> V_62 ,
( T_3 ) V_31 ) ) ;
V_2 -> V_51 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_64 + V_31 ) ;
V_2 -> V_53 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_51 + V_31 ) ;
if ( V_94 == V_132 || V_94 == V_133 )
V_2 -> V_70 =
(struct V_134 * ) ( ( T_2 * ) V_2 -> V_53 +
V_31 ) ;
V_2 -> V_11 = & V_10 . V_11 ;
memcpy ( V_2 -> V_76 , V_10 . V_106 . V_58 [ V_92 ] [ V_94 ] ,
sizeof( struct V_137 ) * 3 ) ;
return 0 ;
}
int F_47 ( struct V_138 * V_139 )
{
return F_44 ( F_48 ( V_139 ) , V_99 ,
V_133 ) ;
}
int F_49 ( struct V_138 * V_139 )
{
return F_44 ( F_48 ( V_139 ) , V_99 ,
V_132 ) ;
}
int F_50 ( struct V_138 * V_139 )
{
return F_44 ( F_48 ( V_139 ) , V_99 ,
V_140 ) ;
}
int F_51 ( struct V_138 * V_139 )
{
return F_44 ( F_48 ( V_139 ) , V_99 ,
V_141 ) ;
}
int F_52 ( struct V_138 * V_139 )
{
return F_44 ( F_48 ( V_139 ) , V_99 ,
V_142 ) ;
}
int F_53 ( struct V_138 * V_139 )
{
return F_44 ( F_48 ( V_139 ) , V_101 , V_143 ) ;
}
int F_54 ( struct V_138 * V_139 )
{
return F_44 ( F_48 ( V_139 ) , V_99 ,
V_144 ) ;
}
void F_55 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_48 ( V_139 ) ;
F_56 ( V_2 -> V_62 ) ;
V_2 -> V_64 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_51 = NULL ;
V_2 -> V_53 = NULL ;
}
static int T_4 F_57 ( struct V_8 * V_9 ,
const struct V_145 * V_146 )
{
F_5 ( & V_9 -> V_14 , L_25 ,
V_9 -> V_147 , V_9 -> V_148 ) ;
if ( V_10 . V_9 ) {
F_33 ( & V_9 -> V_14 , L_26
L_27 , V_81 ) ;
return - V_149 ;
}
V_10 . V_9 = V_9 ;
F_36 ( & V_9 -> V_14 , & V_10 . V_106 ) ;
return F_38 () ;
}
static int T_5 F_58 ( struct V_8 * V_9 )
{
F_5 ( & V_9 -> V_14 , L_28 ,
V_9 -> V_150 ) ;
if ( V_10 . V_106 . V_78 == V_130 ) {
F_59 ( & V_10 ) ;
F_43 ( & V_120 ) ;
F_43 ( & V_122 ) ;
F_43 ( & V_116 ) ;
F_43 ( & V_118 ) ;
F_43 ( & V_112 ) ;
F_43 ( & V_114 ) ;
F_43 ( & V_110 ) ;
F_43 ( & V_109 ) ;
F_42 ( & V_124 ) ;
F_42 ( & V_126 ) ;
F_42 ( & V_128 ) ;
}
return 0 ;
}
static int T_6 F_60 ( void )
{
return F_61 ( & V_10 . V_151 ) ;
}
static void T_7 F_62 ( void )
{
F_63 ( & V_10 . V_151 ) ;
}
