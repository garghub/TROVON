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
unsigned int * V_24 ,
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
V_29 = V_28 + * V_24 ;
for ( V_27 = V_22 ; V_26 < * V_24 ; V_27 ++ ) {
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
V_29 = V_28 + * V_24 - V_26 ;
}
if ( ( V_27 - V_22 ) == V_25 ) {
F_14 ( L_3 ,
V_19 -> V_20 ) ;
V_27 ++ ;
break;
}
}
* V_24 = V_26 ;
return V_27 ;
}
struct V_21 * F_15 ( struct V_21 * V_35 ,
unsigned int V_36 ,
struct V_37 * V_38 ,
unsigned int V_39 ,
unsigned int * V_40 )
{
struct V_41 V_42 ;
struct V_21 * V_21 = V_35 ;
unsigned int V_43 , V_44 = 0 , V_24 = * V_40 ;
char * V_45 ;
for (; ; ) {
F_16 ( & V_42 , V_38 ) ;
if ( V_39 < V_44 + V_38 -> V_46 )
break;
V_44 += V_38 -> V_46 ;
V_38 = F_17 ( V_38 ) ;
}
F_18 ( & V_42 , V_39 - V_44 ) ;
while ( V_24 && ( V_21 - V_35 ) < V_36 ) {
V_43 = F_19 ( & V_42 , V_24 ) ;
if ( ! V_43 ) {
F_16 ( & V_42 , F_17 ( V_42 . V_27 ) ) ;
V_43 = F_19 ( & V_42 , V_24 ) ;
}
V_45 = F_20 ( & V_42 ) ;
V_21 = F_6 ( V_21 , V_45 , & V_43 , V_36 - ( V_21 - V_35 ) ) ;
V_24 -= V_43 ;
F_21 ( V_45 ) ;
F_18 ( & V_42 , V_43 ) ;
F_22 ( & V_42 , V_47 , V_24 ) ;
}
* V_40 -= V_24 ;
return V_21 ;
}
static long int F_23 ( struct V_21 * V_27 , struct V_21 * V_48 , unsigned int V_49 )
{
while ( V_49 && V_48 > V_27 ) {
struct V_21 * V_50 = V_48 - 1 ;
if ( V_50 -> V_24 > V_49 ) {
V_50 -> V_24 -= V_49 ;
V_49 = 0 ;
} else {
V_48 -- ;
V_49 -= V_50 -> V_24 ;
}
}
return ( V_27 - V_48 ) * sizeof( struct V_21 ) ;
}
int F_24 ( struct V_1 * V_2 ,
struct V_21 * V_51 ,
T_4 * V_52 ,
unsigned int * V_53 ,
T_2 * V_44 ,
T_1 V_54 )
{
unsigned int V_49 = 0 ;
unsigned int V_55 = * V_53 ;
struct V_21 * V_56 = V_51 ;
unsigned int V_57 ;
V_57 = F_12 ( T_3 , V_2 -> V_58 -> V_36 ,
V_10 . V_59 . V_57 / sizeof( struct V_21 ) ) ;
V_57 = F_12 ( T_3 , V_57 ,
V_2 -> V_58 -> V_60 / V_32 ) ;
* V_53 = F_12 ( T_3 , * V_53 , V_2 -> V_58 -> V_60 ) ;
V_56 = F_6 ( V_56 , V_44 , V_53 , V_57 ) ;
switch ( V_54 ) {
case V_61 :
if ( * V_53 < V_55 )
V_49 = * V_53 - ( * V_53 & ~ ( V_62 - 1 ) ) ;
break;
case V_63 :
if ( * V_53 < V_55 )
V_49 = * V_53 - ( * V_53 & ~ ( V_64 - 1 ) ) ;
break;
default:
return - V_65 ;
}
* V_52 = F_23 ( V_51 , V_56 , V_49 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_37 * V_45 ,
struct V_37 * V_68 ,
unsigned int * V_53 ,
unsigned int V_44 ,
T_2 * V_69 )
{
unsigned int V_49 = 0 ;
unsigned int V_55 = * V_53 ;
struct V_21 * V_56 = V_2 -> V_70 ;
struct V_21 * V_71 = V_2 -> V_72 ;
unsigned int V_57 ;
V_57 = F_12 ( T_3 , V_2 -> V_58 -> V_36 ,
V_10 . V_59 . V_57 / sizeof( struct V_21 ) ) ;
V_57 = F_12 ( T_3 , V_57 ,
V_2 -> V_58 -> V_60 / V_32 ) ;
if ( V_69 )
memcpy ( V_69 , V_67 -> V_73 , V_74 ) ;
* V_53 = F_12 ( T_3 , * V_53 , V_2 -> V_58 -> V_60 ) ;
V_71 = F_15 ( V_71 , V_57 , V_45 ,
V_44 , V_53 ) ;
V_56 = F_15 ( V_56 , V_57 , V_68 ,
V_44 , V_53 ) ;
if ( * V_53 < V_55 )
V_49 = * V_53 - ( * V_53 & ~ ( V_74 - 1 ) ) ;
V_2 -> V_4 . V_75 = F_23 ( V_2 -> V_70 , V_56 , V_49 ) ;
V_2 -> V_4 . V_76 = F_23 ( V_2 -> V_72 , V_71 , V_49 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_2 , unsigned int V_77 )
{
F_27 ( & V_2 -> V_78 ) ;
memset ( V_2 -> V_79 , 0 , V_2 -> V_80 ) ;
V_2 -> V_81 -> V_82 . V_83 |= V_84 ;
V_2 -> V_4 . V_85 = V_77 ;
V_2 -> V_4 . V_81 = F_11 ( V_2 -> V_81 ) ;
V_2 -> V_4 . V_86 = F_11 ( V_2 -> V_70 ) ;
V_2 -> V_4 . V_87 = F_11 ( V_2 -> V_72 ) ;
if ( V_2 -> V_88 ) {
V_2 -> V_88 -> V_82 . V_83 |= V_84 ;
V_2 -> V_89 . V_85 = V_77 ;
V_2 -> V_89 . V_81 = F_11 ( V_2 -> V_88 ) ;
V_2 -> V_89 . V_86 = F_11 ( V_2 -> V_70 ) ;
V_2 -> V_89 . V_87 = F_11 ( V_2 -> V_72 ) ;
}
}
static void F_28 ( struct V_90 * V_14 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
if ( ! strncmp ( V_92 -> V_95 , L_4 , V_92 -> V_46 ) ) {
V_94 -> V_96 = V_97 ;
V_94 -> V_85 |= V_98 ;
} else {
F_29 ( V_14 , L_5 , V_99 ,
( char * ) V_92 -> V_95 ) ;
}
}
static void F_30 ( struct V_90 * V_14 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
if ( V_92 -> V_46 != sizeof( V_94 -> V_57 ) ) {
F_31 ( V_14 , L_6
L_7 , V_99 ) ;
F_4 ( V_14 , L_8
L_9 , V_99 ,
V_92 -> V_46 , sizeof( V_94 -> V_57 ) ) ;
return;
}
V_94 -> V_57 = * ( T_1 * ) V_92 -> V_95 ;
V_94 -> V_85 |= V_100 ;
}
static void F_32 ( struct V_90 * V_14 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
unsigned int V_105 , V_106 , V_107 ;
V_104 = (struct V_103 * ) V_92 -> V_95 ;
V_107 = V_92 -> V_46 ;
V_105 = 0 ;
while ( ( V_105 + sizeof( struct V_103 ) ) <= V_107 ) {
V_105 += sizeof( struct V_103 ) ;
V_102 = V_104 -> V_102 ;
for ( V_106 = 0 ;
( ( V_105 + sizeof( struct V_101 ) ) <= V_107 ) &&
V_106 < V_104 -> V_108 ;
V_106 ++ ) {
if ( V_104 -> V_109 > V_110 || V_104 -> V_54 > V_111 ) {
F_31 ( V_14 , L_10
L_11 , V_104 -> V_109 ,
V_104 -> V_54 ) ;
goto V_112;
}
switch ( V_102 -> V_113 ) {
case 128 :
case 160 :
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 0 ] . V_60 =
V_102 -> V_60 ;
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 0 ] . V_36 =
V_102 -> V_36 ;
break;
case 192 :
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 1 ] . V_60 =
V_102 -> V_60 ;
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 1 ] . V_36 =
V_102 -> V_36 ;
break;
case 256 :
if ( V_104 -> V_109 == V_114 ) {
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 2 ] .
V_60 = V_102 -> V_60 ;
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 2 ] . V_36 =
V_102 -> V_36 ;
} else if ( V_104 -> V_109 == V_115 ||
V_104 -> V_109 == V_116 ) {
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 1 ] .
V_60 = V_102 -> V_60 ;
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 1 ] . V_36 =
V_102 -> V_36 ;
} else {
F_33 ( V_14 , L_12
L_13
L_14 , V_104 -> V_109 ) ;
}
break;
case 512 :
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 2 ] . V_60 =
V_102 -> V_60 ;
V_94 -> V_58 [ V_104 -> V_109 ] [ V_104 -> V_54 ] [ 2 ] . V_36 =
V_102 -> V_36 ;
break;
default:
F_33 ( V_14 , L_15
L_16 , V_104 -> V_109 ,
V_102 -> V_113 ) ;
break;
}
V_112:
V_105 += sizeof( struct V_101 ) ;
V_102 ++ ;
}
V_104 = (struct V_103 * ) V_102 ;
}
V_94 -> V_85 |= V_117 ;
}
static void F_34 ( struct V_90 * V_14 , struct V_93 * V_94 )
{
struct V_118 * V_119 = V_14 -> V_120 ;
struct V_91 * V_92 ;
V_92 = F_35 ( V_119 , L_17 , NULL ) ;
if ( ! V_92 )
F_29 ( V_14 , L_18 , V_99 ) ;
else
F_28 ( V_14 , V_92 , V_94 ) ;
V_92 = F_35 ( V_119 , L_19 , NULL ) ;
if ( ! V_92 )
F_29 ( V_14 , L_20 ,
V_99 ) ;
else
F_30 ( V_14 , V_92 , V_94 ) ;
V_92 = F_35 ( V_119 , L_21 , NULL ) ;
if ( ! V_92 )
F_29 ( V_14 , L_22 ,
V_99 ) ;
else
F_32 ( V_14 , V_92 , V_94 ) ;
}
static int F_36 ( void )
{
int V_6 = - 1 ;
if ( V_10 . V_59 . V_85 != V_121 )
goto V_87;
memset ( & V_10 . V_11 , 0 , sizeof( struct V_122 ) ) ;
V_6 = F_37 ( & V_10 ) ;
if ( V_6 )
goto V_87;
V_10 . V_59 . V_96 = V_123 ;
V_6 = F_38 ( & V_124 ) ;
if ( V_6 )
goto V_87;
V_6 = F_38 ( & V_125 ) ;
if ( V_6 )
goto V_126;
V_6 = F_38 ( & V_127 ) ;
if ( V_6 )
goto V_128;
V_6 = F_38 ( & V_129 ) ;
if ( V_6 )
goto V_130;
V_6 = F_38 ( & V_131 ) ;
if ( V_6 )
goto V_132;
V_6 = F_38 ( & V_133 ) ;
if ( V_6 )
goto V_134;
V_6 = F_38 ( & V_135 ) ;
if ( V_6 )
goto V_136;
V_6 = F_38 ( & V_137 ) ;
if ( V_6 )
goto V_138;
V_6 = F_39 ( & V_139 ) ;
if ( V_6 )
goto V_140;
V_6 = F_39 ( & V_141 ) ;
if ( V_6 )
goto V_142;
V_6 = F_39 ( & V_143 ) ;
if ( V_6 )
goto V_144;
goto V_87;
V_144:
F_40 ( & V_141 ) ;
V_142:
F_40 ( & V_139 ) ;
V_140:
F_41 ( & V_137 ) ;
V_138:
F_41 ( & V_135 ) ;
V_136:
F_41 ( & V_133 ) ;
V_134:
F_41 ( & V_131 ) ;
V_132:
F_41 ( & V_129 ) ;
V_130:
F_41 ( & V_127 ) ;
V_128:
F_41 ( & V_125 ) ;
V_126:
F_41 ( & V_124 ) ;
V_87:
return V_6 ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_109 , T_1 V_54 )
{
if ( V_10 . V_59 . V_96 != V_123 ) {
F_14 ( L_23
L_24 ) ;
return - V_145 ;
}
if ( V_54 == V_146 || V_54 == V_147 )
V_2 -> V_80 = ( 5 * V_32 ) +
sizeof( struct V_148 ) ;
else
V_2 -> V_80 = ( 4 * V_32 ) +
sizeof( struct V_148 ) ;
V_2 -> V_79 = F_43 ( V_2 -> V_80 , V_149 ) ;
if ( ! V_2 -> V_79 )
return - V_150 ;
V_2 -> V_81 = (struct V_148 * ) ( F_44 ( ( T_3 ) V_2 -> V_79 ,
( T_3 ) V_32 ) ) ;
V_2 -> V_70 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_81 + V_32 ) ;
V_2 -> V_72 = (struct V_21 * ) ( ( T_2 * ) V_2 -> V_70 + V_32 ) ;
if ( V_54 == V_146 || V_54 == V_147 )
V_2 -> V_88 =
(struct V_148 * ) ( ( T_2 * ) V_2 -> V_72 +
V_32 ) ;
V_2 -> V_11 = & V_10 . V_11 ;
memcpy ( V_2 -> V_94 , V_10 . V_59 . V_58 [ V_109 ] [ V_54 ] ,
sizeof( struct V_151 ) * 3 ) ;
return 0 ;
}
int F_45 ( struct V_152 * V_153 )
{
return F_42 ( F_46 ( V_153 ) , V_114 ,
V_147 ) ;
}
int F_47 ( struct V_152 * V_153 )
{
return F_42 ( F_46 ( V_153 ) , V_114 ,
V_146 ) ;
}
int F_48 ( struct V_152 * V_153 )
{
return F_42 ( F_46 ( V_153 ) , V_114 ,
V_154 ) ;
}
int F_49 ( struct V_152 * V_153 )
{
return F_42 ( F_46 ( V_153 ) , V_114 ,
V_155 ) ;
}
int F_50 ( struct V_152 * V_153 )
{
return F_42 ( F_46 ( V_153 ) , V_114 ,
V_156 ) ;
}
int F_51 ( struct V_152 * V_153 )
{
return F_42 ( F_46 ( V_153 ) , V_116 , V_157 ) ;
}
int F_52 ( struct V_152 * V_153 )
{
return F_42 ( F_46 ( V_153 ) , V_114 ,
V_158 ) ;
}
void F_53 ( struct V_152 * V_153 )
{
struct V_1 * V_2 = F_46 ( V_153 ) ;
F_54 ( V_2 -> V_79 ) ;
V_2 -> V_81 = NULL ;
V_2 -> V_88 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_72 = NULL ;
}
static int F_55 ( struct V_8 * V_9 , const struct V_159 * V_160 )
{
F_4 ( & V_9 -> V_14 , L_25 ,
V_9 -> V_161 , V_9 -> V_162 ) ;
if ( V_10 . V_9 ) {
F_31 ( & V_9 -> V_14 , L_26
L_27 , V_99 ) ;
return - V_65 ;
}
V_10 . V_9 = V_9 ;
F_34 ( & V_9 -> V_14 , & V_10 . V_59 ) ;
return F_36 () ;
}
static int F_56 ( struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_14 , L_28 ,
V_9 -> V_163 ) ;
if ( V_10 . V_59 . V_96 == V_123 ) {
F_57 ( & V_10 ) ;
F_41 ( & V_135 ) ;
F_41 ( & V_137 ) ;
F_41 ( & V_131 ) ;
F_41 ( & V_133 ) ;
F_41 ( & V_127 ) ;
F_41 ( & V_129 ) ;
F_41 ( & V_125 ) ;
F_41 ( & V_124 ) ;
F_40 ( & V_139 ) ;
F_40 ( & V_141 ) ;
F_40 ( & V_143 ) ;
}
return 0 ;
}
static int T_5 F_58 ( void )
{
return F_59 ( & V_10 . V_164 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_10 . V_164 ) ;
}
