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
if ( V_49 )
memcpy ( V_49 , V_46 -> V_54 , V_55 ) ;
V_50 = F_16 ( V_50 , V_2 -> V_56 -> V_33 , V_47 , 0 , V_48 ) ;
V_52 = F_16 ( V_52 , V_2 -> V_56 -> V_33 , V_42 , 0 , V_48 ) ;
V_2 -> V_4 . V_57 = ( V_2 -> V_51 - V_50 ) * sizeof( struct V_21 ) ;
V_2 -> V_4 . V_58 = ( V_2 -> V_53 - V_52 ) * sizeof( struct V_21 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 , unsigned int V_59 )
{
memset ( V_2 -> V_60 , 0 , V_2 -> V_61 ) ;
V_2 -> V_62 -> V_63 . V_64 |= V_65 ;
V_2 -> V_4 . V_66 = V_59 ;
V_2 -> V_4 . V_62 = F_12 ( V_2 -> V_62 ) ;
V_2 -> V_4 . V_67 = F_12 ( V_2 -> V_51 ) ;
V_2 -> V_4 . V_68 = F_12 ( V_2 -> V_53 ) ;
if ( V_2 -> V_69 ) {
V_2 -> V_69 -> V_63 . V_64 |= V_65 ;
V_2 -> V_70 . V_66 = V_59 ;
V_2 -> V_70 . V_62 = F_12 ( V_2 -> V_69 ) ;
V_2 -> V_70 . V_67 = F_12 ( V_2 -> V_51 ) ;
V_2 -> V_70 . V_68 = F_12 ( V_2 -> V_53 ) ;
}
}
static void F_27 ( struct V_71 * V_14 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
if ( ! strncmp ( V_73 -> V_76 , L_4 , V_73 -> V_43 ) ) {
V_75 -> V_77 = V_78 ;
V_75 -> V_66 |= V_79 ;
} else {
F_28 ( V_14 , L_5 , V_80 ,
( char * ) V_73 -> V_76 ) ;
}
}
static void F_29 ( struct V_71 * V_14 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
if ( V_73 -> V_43 != sizeof( V_75 -> V_81 ) ) {
F_30 ( V_14 , L_6
L_7 , V_80 ) ;
F_5 ( V_14 , L_8
L_9 , V_80 ,
V_73 -> V_43 , sizeof( V_75 -> V_81 ) ) ;
return;
}
V_75 -> V_81 = * ( T_1 * ) V_73 -> V_76 ;
V_75 -> V_66 |= V_82 ;
}
static void F_31 ( struct V_71 * V_14 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_83 * V_84 ;
struct V_85 * V_86 ;
unsigned int V_87 , V_88 , V_89 ;
V_86 = (struct V_85 * ) V_73 -> V_76 ;
V_89 = V_73 -> V_43 ;
V_87 = 0 ;
while ( ( V_87 + sizeof( struct V_85 ) ) <= V_89 ) {
V_87 += sizeof( struct V_85 ) ;
V_84 = V_86 -> V_84 ;
for ( V_88 = 0 ;
( ( V_87 + sizeof( struct V_83 ) ) <= V_89 ) &&
V_88 < V_86 -> V_90 ;
V_88 ++ ) {
if ( V_86 -> V_91 > V_92 || V_86 -> V_93 > V_94 ) {
F_30 ( V_14 , L_10
L_11 , V_86 -> V_91 ,
V_86 -> V_93 ) ;
goto V_95;
}
switch ( V_84 -> V_96 ) {
case 128 :
case 160 :
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 0 ] . V_97 =
V_84 -> V_97 ;
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 0 ] . V_33 =
V_84 -> V_33 ;
break;
case 192 :
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 1 ] . V_97 =
V_84 -> V_97 ;
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 1 ] . V_33 =
V_84 -> V_33 ;
break;
case 256 :
if ( V_86 -> V_91 == V_98 ) {
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 2 ] .
V_97 = V_84 -> V_97 ;
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 2 ] . V_33 =
V_84 -> V_33 ;
} else if ( V_86 -> V_91 == V_99 ||
V_86 -> V_91 == V_100 ) {
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 1 ] .
V_97 = V_84 -> V_97 ;
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 1 ] . V_33 =
V_84 -> V_33 ;
} else {
F_32 ( V_14 , L_12
L_13
L_14 , V_86 -> V_91 ) ;
}
break;
case 512 :
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 2 ] . V_97 =
V_84 -> V_97 ;
V_75 -> V_56 [ V_86 -> V_91 ] [ V_86 -> V_93 ] [ 2 ] . V_33 =
V_84 -> V_33 ;
break;
default:
F_32 ( V_14 , L_15
L_16 , V_86 -> V_91 ,
V_84 -> V_96 ) ;
break;
}
V_95:
V_87 += sizeof( struct V_83 ) ;
V_84 ++ ;
}
V_86 = (struct V_85 * ) V_84 ;
}
V_75 -> V_66 |= V_101 ;
}
static void F_33 ( struct V_71 * V_14 , struct V_74 * V_75 )
{
struct V_102 * V_103 = V_14 -> V_104 ;
struct V_72 * V_73 ;
V_73 = F_34 ( V_103 , L_17 , NULL ) ;
if ( ! V_73 )
F_28 ( V_14 , L_18 , V_80 ) ;
else
F_27 ( V_14 , V_73 , V_75 ) ;
V_73 = F_34 ( V_103 , L_19 , NULL ) ;
if ( ! V_73 )
F_28 ( V_14 , L_20 ,
V_80 ) ;
else
F_29 ( V_14 , V_73 , V_75 ) ;
V_73 = F_34 ( V_103 , L_21 , NULL ) ;
if ( ! V_73 )
F_28 ( V_14 , L_22 ,
V_80 ) ;
else
F_31 ( V_14 , V_73 , V_75 ) ;
}
static int F_35 ( void )
{
int V_6 = - 1 ;
if ( V_10 . V_105 . V_66 != V_106 )
goto V_68;
memset ( & V_10 . V_11 , 0 , sizeof( struct V_107 ) ) ;
V_6 = F_36 ( & V_10 ) ;
if ( V_6 )
goto V_68;
V_10 . V_105 . V_77 = V_108 ;
V_6 = F_37 ( & V_109 ) ;
if ( V_6 )
goto V_68;
V_6 = F_37 ( & V_110 ) ;
if ( V_6 )
goto V_111;
V_6 = F_37 ( & V_112 ) ;
if ( V_6 )
goto V_113;
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
V_6 = F_38 ( & V_124 ) ;
if ( V_6 )
goto V_125;
V_6 = F_38 ( & V_126 ) ;
if ( V_6 )
goto V_127;
V_6 = F_38 ( & V_128 ) ;
if ( V_6 )
goto V_129;
goto V_68;
V_129:
F_39 ( & V_126 ) ;
V_127:
F_39 ( & V_124 ) ;
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
F_40 ( & V_112 ) ;
V_113:
F_40 ( & V_110 ) ;
V_111:
F_40 ( & V_109 ) ;
V_68:
return V_6 ;
}
static int F_41 ( struct V_1 * V_2 , T_1 V_91 , T_1 V_93 )
{
if ( V_10 . V_105 . V_77 != V_108 ) {
F_15 ( L_23
L_24 ) ;
return - V_130 ;
}
if ( V_93 == V_131 || V_93 == V_132 )
V_2 -> V_61 = ( 4 * V_31 ) +
sizeof( struct V_133 ) ;
else
V_2 -> V_61 = ( 3 * V_31 ) +
sizeof( struct V_133 ) ;
V_2 -> V_60 = F_42 ( V_2 -> V_61 , V_134 ) ;
if ( ! V_2 -> V_60 )
return - V_135 ;
V_2 -> V_62 = (struct V_133 * ) ( F_43 ( ( T_3 ) V_2 -> V_60 ,
( T_3 ) V_31 ) ) ;
V_2 -> V_51 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_62 + V_31 ) ;
V_2 -> V_53 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_51 + V_31 ) ;
if ( V_93 == V_131 || V_93 == V_132 )
V_2 -> V_69 =
(struct V_133 * ) ( ( T_2 * ) V_2 -> V_53 +
V_31 ) ;
V_2 -> V_11 = & V_10 . V_11 ;
memcpy ( V_2 -> V_75 , V_10 . V_105 . V_56 [ V_91 ] [ V_93 ] ,
sizeof( struct V_136 ) * 3 ) ;
return 0 ;
}
int F_44 ( struct V_137 * V_138 )
{
return F_41 ( F_45 ( V_138 ) , V_98 ,
V_132 ) ;
}
int F_46 ( struct V_137 * V_138 )
{
return F_41 ( F_45 ( V_138 ) , V_98 ,
V_131 ) ;
}
int F_47 ( struct V_137 * V_138 )
{
return F_41 ( F_45 ( V_138 ) , V_98 ,
V_139 ) ;
}
int F_48 ( struct V_137 * V_138 )
{
return F_41 ( F_45 ( V_138 ) , V_98 ,
V_140 ) ;
}
int F_49 ( struct V_137 * V_138 )
{
return F_41 ( F_45 ( V_138 ) , V_98 ,
V_141 ) ;
}
int F_50 ( struct V_137 * V_138 )
{
return F_41 ( F_45 ( V_138 ) , V_100 , V_142 ) ;
}
int F_51 ( struct V_137 * V_138 )
{
return F_41 ( F_45 ( V_138 ) , V_98 ,
V_143 ) ;
}
void F_52 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_45 ( V_138 ) ;
F_53 ( V_2 -> V_60 ) ;
V_2 -> V_62 = NULL ;
V_2 -> V_69 = NULL ;
V_2 -> V_51 = NULL ;
V_2 -> V_53 = NULL ;
}
static int F_54 ( struct V_8 * V_9 , const struct V_144 * V_145 )
{
F_5 ( & V_9 -> V_14 , L_25 ,
V_9 -> V_146 , V_9 -> V_147 ) ;
if ( V_10 . V_9 ) {
F_30 ( & V_9 -> V_14 , L_26
L_27 , V_80 ) ;
return - V_148 ;
}
V_10 . V_9 = V_9 ;
F_33 ( & V_9 -> V_14 , & V_10 . V_105 ) ;
return F_35 () ;
}
static int F_55 ( struct V_8 * V_9 )
{
F_5 ( & V_9 -> V_14 , L_28 ,
V_9 -> V_149 ) ;
if ( V_10 . V_105 . V_77 == V_108 ) {
F_56 ( & V_10 ) ;
F_40 ( & V_120 ) ;
F_40 ( & V_122 ) ;
F_40 ( & V_116 ) ;
F_40 ( & V_118 ) ;
F_40 ( & V_112 ) ;
F_40 ( & V_114 ) ;
F_40 ( & V_110 ) ;
F_40 ( & V_109 ) ;
F_39 ( & V_124 ) ;
F_39 ( & V_126 ) ;
F_39 ( & V_128 ) ;
}
return 0 ;
}
static int T_4 F_57 ( void )
{
return F_58 ( & V_10 . V_150 ) ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_10 . V_150 ) ;
}
