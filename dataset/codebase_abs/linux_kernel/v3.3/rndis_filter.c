static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_7 ;
return V_2 ;
}
static struct V_8 * F_5 ( struct V_1 * V_9 ,
T_1 V_10 ,
T_1 V_11 )
{
struct V_8 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
unsigned long V_17 ;
V_12 = F_2 ( sizeof( struct V_8 ) , V_3 ) ;
if ( ! V_12 )
return NULL ;
F_6 ( & V_12 -> V_18 ) ;
V_14 = & V_12 -> V_19 ;
V_14 -> V_20 = V_10 ;
V_14 -> V_11 = V_11 ;
V_16 = & V_14 -> V_21 . V_22 ;
V_16 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_9 ( & V_12 -> V_25 , & V_9 -> V_5 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
return V_12 ;
}
static void F_11 ( struct V_1 * V_9 ,
struct V_8 * V_26 )
{
unsigned long V_17 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_12 ( & V_26 -> V_25 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
F_13 ( V_26 ) ;
}
static void F_14 ( struct V_27 * V_28 ,
struct V_13 * V_14 )
{
struct V_29 * V_30 ;
struct V_31 * V_29 ;
V_29 = F_15 ( V_28 ) ;
V_30 = V_29 -> V_32 ;
switch ( V_14 -> V_20 ) {
case V_33 :
F_16 ( V_30 , L_1
L_2
L_3
L_4 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_34 . V_35 ,
V_14 -> V_21 . V_34 . V_36 ,
V_14 -> V_21 . V_34 . V_37 ,
V_14 -> V_21 . V_34 . V_38 ,
V_14 -> V_21 . V_34 . V_39 ,
V_14 -> V_21 . V_34 . V_40 ,
V_14 -> V_21 . V_34 . V_41 ) ;
break;
case V_42 :
F_16 ( V_30 , L_5
L_6
L_7
L_8 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_43 . V_23 ,
V_14 -> V_21 . V_43 . V_44 ,
V_14 -> V_21 . V_43 . V_45 ,
V_14 -> V_21 . V_43 . V_46 ,
V_14 -> V_21 . V_43 . V_47 ,
V_14 -> V_21 . V_43 . V_48 ,
V_14 -> V_21 . V_43 .
V_49 ,
V_14 -> V_21 . V_43 .
V_50 ) ;
break;
case V_51 :
F_16 ( V_30 , L_9
L_10
L_11 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_52 . V_23 ,
V_14 -> V_21 . V_52 . V_44 ,
V_14 -> V_21 . V_52 .
V_53 ,
V_14 -> V_21 . V_52 .
V_54 ) ;
break;
case V_55 :
F_16 ( V_30 ,
L_12 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_56 . V_23 ,
V_14 -> V_21 . V_56 . V_44 ) ;
break;
case V_57 :
F_16 ( V_30 , L_13
L_14 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_58 . V_44 ,
V_14 -> V_21 . V_58 . V_59 ,
V_14 -> V_21 . V_58 . V_60 ) ;
break;
default:
F_16 ( V_30 , L_15 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
}
static int F_17 ( struct V_1 * V_9 ,
struct V_8 * V_26 )
{
int V_61 ;
struct V_62 * V_63 ;
V_63 = & V_26 -> V_34 ;
V_63 -> V_64 = false ;
V_63 -> V_65 = V_26 -> V_19 . V_11 ;
V_63 -> V_66 = 1 ;
V_63 -> V_67 [ 0 ] . V_68 = F_18 ( & V_26 -> V_19 ) >>
V_69 ;
V_63 -> V_67 [ 0 ] . V_70 = V_26 -> V_19 . V_11 ;
V_63 -> V_67 [ 0 ] . V_71 =
( unsigned long ) & V_26 -> V_19 & ( V_72 - 1 ) ;
V_63 -> V_73 . V_74 . V_75 = V_26 ;
V_63 -> V_73 . V_74 . V_76 =
V_77 ;
V_63 -> V_73 . V_74 . V_78 = ( unsigned long ) V_9 ;
V_61 = F_19 ( V_9 -> V_79 -> V_9 , V_63 ) ;
return V_61 ;
}
static void F_20 ( struct V_1 * V_9 ,
struct V_13 * V_80 )
{
struct V_8 * V_12 = NULL ;
bool V_81 = false ;
unsigned long V_17 ;
struct V_29 * V_32 ;
V_32 = V_9 -> V_79 -> V_32 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_21 (request, &dev->req_list, list_ent) {
if ( V_12 -> V_19 . V_21 . V_82 . V_23
== V_80 -> V_21 . V_43 . V_23 ) {
V_81 = true ;
break;
}
}
F_10 ( & V_9 -> V_4 , V_17 ) ;
if ( V_81 ) {
if ( V_80 -> V_11 <= sizeof( struct V_13 ) ) {
memcpy ( & V_12 -> V_83 , V_80 ,
V_80 -> V_11 ) ;
} else {
F_22 ( V_32 ,
L_16
L_17 ,
V_80 -> V_11 ,
sizeof( struct V_84 ) ) ;
if ( V_80 -> V_20 ==
V_85 ) {
V_12 -> V_83 . V_21 . V_86 .
V_44 = V_87 ;
} else {
V_12 -> V_83 . V_21 .
V_43 . V_44 =
V_87 ;
}
}
F_23 ( & V_12 -> V_18 ) ;
} else {
F_22 ( V_32 ,
L_18
L_19 ,
V_80 -> V_21 . V_43 . V_23 ,
V_80 -> V_20 ) ;
}
}
static void F_24 ( struct V_1 * V_9 ,
struct V_13 * V_80 )
{
struct V_88 * V_89 =
& V_80 -> V_21 . V_58 ;
if ( V_89 -> V_44 == V_90 ) {
F_25 (
V_9 -> V_79 -> V_9 , 1 ) ;
} else if ( V_89 -> V_44 == V_91 ) {
F_25 (
V_9 -> V_79 -> V_9 , 0 ) ;
} else {
}
}
static void F_26 ( struct V_1 * V_9 ,
struct V_13 * V_21 ,
struct V_62 * V_34 )
{
struct V_92 * V_93 ;
T_1 V_35 ;
V_93 = & V_21 -> V_21 . V_34 ;
V_35 = V_94 + V_93 -> V_35 ;
V_34 -> V_65 -= V_35 ;
if ( V_34 -> V_65 < V_93 -> V_36 ) {
F_22 ( V_9 -> V_79 -> V_32 , L_20
L_21
L_22 ,
V_34 -> V_65 , V_93 -> V_36 ) ;
return;
}
V_34 -> V_65 = V_93 -> V_36 ;
V_34 -> V_95 = ( void * ) ( ( unsigned long ) V_34 -> V_95 + V_35 ) ;
V_34 -> V_64 = true ;
F_27 ( V_9 -> V_79 -> V_9 , V_34 ) ;
}
int F_28 ( struct V_27 * V_9 ,
struct V_62 * V_34 )
{
struct V_31 * V_79 = F_15 ( V_9 ) ;
struct V_1 * V_96 ;
struct V_13 V_14 ;
struct V_13 * V_97 ;
struct V_29 * V_32 ;
if ( ! V_79 )
return - V_98 ;
V_32 = V_79 -> V_32 ;
if ( ! V_79 -> V_99 ) {
F_22 ( V_32 , L_23
L_24 ) ;
return - V_100 ;
}
V_96 = (struct V_1 * ) V_79 -> V_99 ;
if ( V_96 -> V_6 == V_7 ) {
F_22 ( V_32 , L_25
L_26 ) ;
return - V_100 ;
}
V_97 = V_34 -> V_95 ;
if ( ( V_97 -> V_20 != V_33 ) &&
( V_97 -> V_11 > sizeof( struct V_13 ) ) ) {
F_22 ( V_32 , L_27
L_28 ,
V_97 -> V_11 ,
sizeof( struct V_13 ) ) ;
}
memcpy ( & V_14 , V_97 ,
( V_97 -> V_11 > sizeof( struct V_13 ) ) ?
sizeof( struct V_13 ) :
V_97 -> V_11 ) ;
F_14 ( V_9 , & V_14 ) ;
switch ( V_14 . V_20 ) {
case V_33 :
F_26 ( V_96 , & V_14 , V_34 ) ;
break;
case V_42 :
case V_51 :
case V_55 :
F_20 ( V_96 , & V_14 ) ;
break;
case V_57 :
F_24 ( V_96 , & V_14 ) ;
break;
default:
F_22 ( V_32 ,
L_29 ,
V_14 . V_20 ,
V_14 . V_11 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_9 , T_1 V_101 ,
void * V_102 , T_1 * V_103 )
{
struct V_8 * V_12 ;
T_1 V_104 = * V_103 ;
struct V_105 * V_106 ;
struct V_107 * V_52 ;
int V_61 = 0 ;
int V_108 ;
if ( ! V_102 )
return - V_98 ;
* V_103 = 0 ;
V_12 = F_5 ( V_9 , V_109 ,
F_30 ( struct V_105 ) ) ;
if ( ! V_12 ) {
V_61 = - V_110 ;
goto V_111;
}
V_106 = & V_12 -> V_19 . V_21 . V_112 ;
V_106 -> V_101 = V_101 ;
V_106 -> V_54 = sizeof( struct V_105 ) ;
V_106 -> V_53 = 0 ;
V_106 -> V_113 = 0 ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 )
goto V_111;
V_108 = F_31 ( & V_12 -> V_18 , 5 * V_114 ) ;
if ( V_108 == 0 ) {
V_61 = - V_115 ;
goto V_111;
}
V_52 = & V_12 -> V_83 . V_21 . V_52 ;
if ( V_52 -> V_53 > V_104 ) {
V_61 = - 1 ;
goto V_111;
}
memcpy ( V_102 ,
( void * ) ( ( unsigned long ) V_52 +
V_52 -> V_54 ) ,
V_52 -> V_53 ) ;
* V_103 = V_52 -> V_53 ;
V_111:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_61 ;
}
static int F_32 ( struct V_1 * V_9 )
{
T_1 V_116 = V_117 ;
return F_29 ( V_9 ,
V_118 ,
V_9 -> V_119 , & V_116 ) ;
}
static int F_33 ( struct V_1 * V_9 )
{
T_1 V_116 = sizeof( T_1 ) ;
T_1 V_120 ;
int V_61 ;
V_61 = F_29 ( V_9 ,
V_121 ,
& V_120 , & V_116 ) ;
V_9 -> V_122 = ( V_120 != 0 ) ? true : false ;
return V_61 ;
}
int F_34 ( struct V_1 * V_9 , T_1 V_123 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_124 * V_56 ;
T_1 V_44 ;
int V_61 , V_108 ;
struct V_29 * V_32 ;
V_32 = V_9 -> V_79 -> V_32 ;
V_12 = F_5 ( V_9 , V_125 ,
F_30 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_61 = - V_110 ;
goto V_111;
}
V_16 = & V_12 -> V_19 . V_21 . V_22 ;
V_16 -> V_101 = V_126 ;
V_16 -> V_53 = sizeof( T_1 ) ;
V_16 -> V_54 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_123 , sizeof( T_1 ) ) ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 )
goto V_111;
V_108 = F_31 ( & V_12 -> V_18 , 5 * V_114 ) ;
if ( V_108 == 0 ) {
F_22 ( V_32 ,
L_30 ) ;
goto exit;
} else {
V_56 = & V_12 -> V_83 . V_21 . V_56 ;
V_44 = V_56 -> V_44 ;
}
V_111:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
exit:
return V_61 ;
}
static int F_35 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_127 * V_128 ;
struct V_129 * V_43 ;
T_1 V_44 ;
int V_61 , V_108 ;
V_12 = F_5 ( V_9 , V_130 ,
F_30 ( struct V_127 ) ) ;
if ( ! V_12 ) {
V_61 = - V_110 ;
goto V_111;
}
V_128 = & V_12 -> V_19 . V_21 . V_82 ;
V_128 -> V_45 = V_131 ;
V_128 -> V_46 = V_132 ;
V_128 -> V_48 = 2048 ;
V_9 -> V_6 = V_133 ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_111;
}
V_108 = F_31 ( & V_12 -> V_18 , 5 * V_114 ) ;
if ( V_108 == 0 ) {
V_61 = - V_115 ;
goto V_111;
}
V_43 = & V_12 -> V_83 . V_21 . V_43 ;
V_44 = V_43 -> V_44 ;
if ( V_44 == V_134 ) {
V_9 -> V_6 = V_135 ;
V_61 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_61 = - V_98 ;
}
V_111:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_61 ;
}
static void F_36 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_136 * V_137 ;
V_12 = F_5 ( V_9 , V_138 ,
F_30 ( struct V_136 ) ) ;
if ( ! V_12 )
goto V_111;
V_137 = & V_12 -> V_19 . V_21 . V_139 ;
V_137 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_111:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_37 ( struct V_1 * V_9 )
{
int V_61 ;
if ( V_9 -> V_6 != V_135 )
return 0 ;
V_61 = F_34 ( V_9 ,
V_140 |
V_141 |
V_142 ) ;
if ( V_61 == 0 )
V_9 -> V_6 = V_143 ;
return V_61 ;
}
static int F_38 ( struct V_1 * V_9 )
{
int V_61 ;
if ( V_9 -> V_6 != V_143 )
return 0 ;
V_61 = F_34 ( V_9 , 0 ) ;
if ( V_61 == 0 )
V_9 -> V_6 = V_135 ;
return V_61 ;
}
int F_39 ( struct V_27 * V_9 ,
void * V_144 )
{
int V_61 ;
struct V_31 * V_29 ;
struct V_1 * V_1 ;
struct V_145 * V_146 = V_144 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_100 ;
V_61 = F_40 ( V_9 , V_144 ) ;
if ( V_61 != 0 ) {
F_13 ( V_1 ) ;
return V_61 ;
}
V_29 = F_15 ( V_9 ) ;
V_29 -> V_99 = V_1 ;
V_1 -> V_79 = V_29 ;
V_61 = F_35 ( V_1 ) ;
if ( V_61 != 0 ) {
}
V_61 = F_32 ( V_1 ) ;
if ( V_61 != 0 ) {
}
memcpy ( V_146 -> V_147 , V_1 -> V_119 , V_117 ) ;
F_33 ( V_1 ) ;
V_146 -> V_122 = V_1 -> V_122 ;
F_41 ( & V_9 -> V_2 , L_31 ,
V_1 -> V_119 ,
V_146 -> V_122 ? L_32 : L_33 ) ;
return V_61 ;
}
void F_42 ( struct V_27 * V_9 )
{
struct V_31 * V_79 = F_15 ( V_9 ) ;
struct V_1 * V_96 = V_79 -> V_99 ;
F_36 ( V_96 ) ;
F_13 ( V_96 ) ;
V_79 -> V_99 = NULL ;
F_43 ( V_9 ) ;
}
int F_44 ( struct V_27 * V_9 )
{
struct V_31 * V_29 = F_15 ( V_9 ) ;
if ( ! V_29 )
return - V_98 ;
return F_37 ( V_29 -> V_99 ) ;
}
int F_45 ( struct V_27 * V_9 )
{
struct V_31 * V_148 = F_15 ( V_9 ) ;
if ( ! V_148 )
return - V_98 ;
return F_38 ( V_148 -> V_99 ) ;
}
int F_46 ( struct V_27 * V_9 ,
struct V_62 * V_34 )
{
int V_61 ;
struct V_84 * V_149 ;
struct V_13 * V_150 ;
struct V_92 * V_151 ;
T_1 V_152 ;
V_149 = (struct V_84 * ) V_34 -> V_99 ;
memset ( V_149 , 0 , sizeof( struct V_84 ) ) ;
V_150 = & V_149 -> V_21 ;
V_152 = F_30 ( struct V_92 ) ;
V_150 -> V_20 = V_33 ;
V_150 -> V_11 = V_34 -> V_65 +
V_152 ;
V_151 = & V_150 -> V_21 . V_34 ;
V_151 -> V_35 = sizeof( struct V_92 ) ;
V_151 -> V_36 = V_34 -> V_65 ;
V_34 -> V_64 = true ;
V_34 -> V_67 [ 0 ] . V_68 = F_18 ( V_150 ) >> V_69 ;
V_34 -> V_67 [ 0 ] . V_71 =
( unsigned long ) V_150 & ( V_72 - 1 ) ;
V_34 -> V_67 [ 0 ] . V_70 = V_152 ;
if ( V_34 -> V_67 [ 0 ] . V_71 + V_152 > V_72 ) {
int V_153 ;
for ( V_153 = V_34 -> V_66 ; V_153 > 1 ; V_153 -- )
V_34 -> V_67 [ V_153 ] = V_34 -> V_67 [ V_153 - 1 ] ;
V_34 -> V_66 ++ ;
V_34 -> V_67 [ 0 ] . V_70 = V_72 - V_34 -> V_67 [ 0 ] . V_71 ;
V_34 -> V_67 [ 1 ] . V_68 = F_18 ( ( void * ) ( ( V_154 )
V_150 + V_34 -> V_67 [ 0 ] . V_70 ) ) >> V_69 ;
V_34 -> V_67 [ 1 ] . V_71 = 0 ;
V_34 -> V_67 [ 1 ] . V_70 = V_152 - V_34 -> V_67 [ 0 ] . V_70 ;
}
V_149 -> V_73 = V_34 -> V_73 . V_74 . V_76 ;
V_149 -> V_155 =
V_34 -> V_73 . V_74 . V_75 ;
V_34 -> V_73 . V_74 . V_76 = V_156 ;
V_34 -> V_73 . V_74 . V_75 = V_149 ;
V_61 = F_19 ( V_9 , V_34 ) ;
if ( V_61 != 0 ) {
V_34 -> V_73 . V_74 . V_76 =
V_149 -> V_73 ;
V_34 -> V_73 . V_74 . V_75 =
V_149 -> V_155 ;
}
return V_61 ;
}
static void V_156 ( void * V_157 )
{
struct V_84 * V_149 = V_157 ;
V_149 -> V_73 ( V_149 -> V_155 ) ;
}
static void V_77 ( void * V_157 )
{
}
