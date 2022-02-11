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
int V_94 ;
V_93 = & V_21 -> V_21 . V_34 ;
V_35 = V_95 + V_93 -> V_35 ;
V_34 -> V_65 -= V_35 ;
V_34 -> V_67 [ 0 ] . V_71 += V_35 ;
V_34 -> V_67 [ 0 ] . V_70 -= V_35 ;
if ( V_34 -> V_67 [ 0 ] . V_71 >= V_72 ) {
V_34 -> V_67 [ 1 ] . V_71 = V_34 -> V_67 [ 0 ] . V_71 - V_72 ;
V_34 -> V_67 [ 1 ] . V_70 -= V_34 -> V_67 [ 1 ] . V_71 ;
V_34 -> V_66 -- ;
for ( V_94 = 0 ; V_94 < V_34 -> V_66 ; V_94 ++ )
V_34 -> V_67 [ V_94 ] = V_34 -> V_67 [ V_94 + 1 ] ;
}
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
F_22 ( V_32 , L_20
L_21 ) ;
return - V_100 ;
}
V_96 = (struct V_1 * ) V_79 -> V_99 ;
if ( V_96 -> V_6 == V_7 ) {
F_22 ( V_32 , L_22
L_23 ) ;
return - V_100 ;
}
V_97 = (struct V_13 * ) F_29 (
F_30 ( V_34 -> V_67 [ 0 ] . V_68 ) , V_101 ) ;
V_97 = ( void * ) ( ( unsigned long ) V_97 +
V_34 -> V_67 [ 0 ] . V_71 ) ;
if ( ( V_97 -> V_20 != V_33 ) &&
( V_97 -> V_11 > sizeof( struct V_13 ) ) ) {
F_22 ( V_32 , L_24
L_25 ,
V_97 -> V_11 ,
sizeof( struct V_13 ) ) ;
}
memcpy ( & V_14 , V_97 ,
( V_97 -> V_11 > sizeof( struct V_13 ) ) ?
sizeof( struct V_13 ) :
V_97 -> V_11 ) ;
F_31 ( V_97 - V_34 -> V_67 [ 0 ] . V_71 , V_101 ) ;
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
L_26 ,
V_14 . V_20 ,
V_14 . V_11 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_9 , T_1 V_102 ,
void * V_103 , T_1 * V_104 )
{
struct V_8 * V_12 ;
T_1 V_105 = * V_104 ;
struct V_106 * V_107 ;
struct V_108 * V_52 ;
int V_61 = 0 ;
int V_109 ;
if ( ! V_103 )
return - V_98 ;
* V_104 = 0 ;
V_12 = F_5 ( V_9 , V_110 ,
F_33 ( struct V_106 ) ) ;
if ( ! V_12 ) {
V_61 = - V_111 ;
goto V_112;
}
V_107 = & V_12 -> V_19 . V_21 . V_113 ;
V_107 -> V_102 = V_102 ;
V_107 -> V_54 = sizeof( struct V_106 ) ;
V_107 -> V_53 = 0 ;
V_107 -> V_114 = 0 ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 )
goto V_112;
V_109 = F_34 ( & V_12 -> V_18 , 5 * V_115 ) ;
if ( V_109 == 0 ) {
V_61 = - V_116 ;
goto V_112;
}
V_52 = & V_12 -> V_83 . V_21 . V_52 ;
if ( V_52 -> V_53 > V_105 ) {
V_61 = - 1 ;
goto V_112;
}
memcpy ( V_103 ,
( void * ) ( ( unsigned long ) V_52 +
V_52 -> V_54 ) ,
V_52 -> V_53 ) ;
* V_104 = V_52 -> V_53 ;
V_112:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_61 ;
}
static int F_35 ( struct V_1 * V_9 )
{
T_1 V_117 = V_118 ;
return F_32 ( V_9 ,
V_119 ,
V_9 -> V_120 , & V_117 ) ;
}
static int F_36 ( struct V_1 * V_9 )
{
T_1 V_117 = sizeof( T_1 ) ;
T_1 V_121 ;
int V_61 ;
V_61 = F_32 ( V_9 ,
V_122 ,
& V_121 , & V_117 ) ;
V_9 -> V_123 = ( V_121 != 0 ) ? true : false ;
return V_61 ;
}
static int F_37 ( struct V_1 * V_9 ,
T_1 V_124 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_125 * V_56 ;
T_1 V_44 ;
int V_61 , V_109 ;
struct V_29 * V_32 ;
V_32 = V_9 -> V_79 -> V_32 ;
V_12 = F_5 ( V_9 , V_126 ,
F_33 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_61 = - V_111 ;
goto V_112;
}
V_16 = & V_12 -> V_19 . V_21 . V_22 ;
V_16 -> V_102 = V_127 ;
V_16 -> V_53 = sizeof( T_1 ) ;
V_16 -> V_54 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_124 , sizeof( T_1 ) ) ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 )
goto V_112;
V_109 = F_34 ( & V_12 -> V_18 , 5 * V_115 ) ;
if ( V_109 == 0 ) {
F_22 ( V_32 ,
L_27 ) ;
goto exit;
} else {
V_56 = & V_12 -> V_83 . V_21 . V_56 ;
V_44 = V_56 -> V_44 ;
}
V_112:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
exit:
return V_61 ;
}
static int F_38 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_128 * V_129 ;
struct V_130 * V_43 ;
T_1 V_44 ;
int V_61 , V_109 ;
V_12 = F_5 ( V_9 , V_131 ,
F_33 ( struct V_128 ) ) ;
if ( ! V_12 ) {
V_61 = - V_111 ;
goto V_112;
}
V_129 = & V_12 -> V_19 . V_21 . V_82 ;
V_129 -> V_45 = V_132 ;
V_129 -> V_46 = V_133 ;
V_129 -> V_48 = 2048 ;
V_9 -> V_6 = V_134 ;
V_61 = F_17 ( V_9 , V_12 ) ;
if ( V_61 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_112;
}
V_109 = F_34 ( & V_12 -> V_18 , 5 * V_115 ) ;
if ( V_109 == 0 ) {
V_61 = - V_116 ;
goto V_112;
}
V_43 = & V_12 -> V_83 . V_21 . V_43 ;
V_44 = V_43 -> V_44 ;
if ( V_44 == V_135 ) {
V_9 -> V_6 = V_136 ;
V_61 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_61 = - V_98 ;
}
V_112:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_61 ;
}
static void F_39 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_137 * V_138 ;
V_12 = F_5 ( V_9 , V_139 ,
F_33 ( struct V_137 ) ) ;
if ( ! V_12 )
goto V_112;
V_138 = & V_12 -> V_19 . V_21 . V_140 ;
V_138 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_112:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_40 ( struct V_1 * V_9 )
{
int V_61 ;
if ( V_9 -> V_6 != V_136 )
return 0 ;
V_61 = F_37 ( V_9 ,
V_141 |
V_142 |
V_143 ) ;
if ( V_61 == 0 )
V_9 -> V_6 = V_144 ;
return V_61 ;
}
static int F_41 ( struct V_1 * V_9 )
{
int V_61 ;
if ( V_9 -> V_6 != V_144 )
return 0 ;
V_61 = F_37 ( V_9 , 0 ) ;
if ( V_61 == 0 )
V_9 -> V_6 = V_136 ;
return V_61 ;
}
int F_42 ( struct V_27 * V_9 ,
void * V_145 )
{
int V_61 ;
struct V_31 * V_29 ;
struct V_1 * V_1 ;
struct V_146 * V_147 = V_145 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_100 ;
V_61 = F_43 ( V_9 , V_145 ) ;
if ( V_61 != 0 ) {
F_13 ( V_1 ) ;
return V_61 ;
}
V_29 = F_15 ( V_9 ) ;
V_29 -> V_99 = V_1 ;
V_1 -> V_79 = V_29 ;
V_61 = F_38 ( V_1 ) ;
if ( V_61 != 0 ) {
}
V_61 = F_35 ( V_1 ) ;
if ( V_61 != 0 ) {
}
memcpy ( V_147 -> V_148 , V_1 -> V_120 , V_118 ) ;
F_36 ( V_1 ) ;
V_147 -> V_123 = V_1 -> V_123 ;
F_44 ( & V_9 -> V_2 , L_28 ,
V_1 -> V_120 ,
V_147 -> V_123 ? L_29 : L_30 ) ;
return V_61 ;
}
void F_45 ( struct V_27 * V_9 )
{
struct V_31 * V_79 = F_15 ( V_9 ) ;
struct V_1 * V_96 = V_79 -> V_99 ;
F_39 ( V_96 ) ;
F_13 ( V_96 ) ;
V_79 -> V_99 = NULL ;
F_46 ( V_9 ) ;
}
int F_47 ( struct V_27 * V_9 )
{
struct V_31 * V_29 = F_15 ( V_9 ) ;
if ( ! V_29 )
return - V_98 ;
return F_40 ( V_29 -> V_99 ) ;
}
int F_48 ( struct V_27 * V_9 )
{
struct V_31 * V_149 = F_15 ( V_9 ) ;
if ( ! V_149 )
return - V_98 ;
return F_41 ( V_149 -> V_99 ) ;
}
int F_49 ( struct V_27 * V_9 ,
struct V_62 * V_34 )
{
int V_61 ;
struct V_84 * V_150 ;
struct V_13 * V_151 ;
struct V_92 * V_152 ;
T_1 V_153 ;
V_150 = (struct V_84 * ) V_34 -> V_99 ;
memset ( V_150 , 0 , sizeof( struct V_84 ) ) ;
V_151 = & V_150 -> V_21 ;
V_153 = F_33 ( struct V_92 ) ;
V_151 -> V_20 = V_33 ;
V_151 -> V_11 = V_34 -> V_65 +
V_153 ;
V_152 = & V_151 -> V_21 . V_34 ;
V_152 -> V_35 = sizeof( struct V_92 ) ;
V_152 -> V_36 = V_34 -> V_65 ;
V_34 -> V_64 = true ;
V_34 -> V_67 [ 0 ] . V_68 = F_18 ( V_151 ) >> V_69 ;
V_34 -> V_67 [ 0 ] . V_71 =
( unsigned long ) V_151 & ( V_72 - 1 ) ;
V_34 -> V_67 [ 0 ] . V_70 = V_153 ;
V_150 -> V_73 = V_34 -> V_73 . V_74 . V_76 ;
V_150 -> V_154 =
V_34 -> V_73 . V_74 . V_75 ;
V_34 -> V_73 . V_74 . V_76 = V_155 ;
V_34 -> V_73 . V_74 . V_75 = V_150 ;
V_61 = F_19 ( V_9 , V_34 ) ;
if ( V_61 != 0 ) {
V_34 -> V_73 . V_74 . V_76 =
V_150 -> V_73 ;
V_34 -> V_73 . V_74 . V_75 =
V_150 -> V_154 ;
}
return V_61 ;
}
static void V_155 ( void * V_156 )
{
struct V_84 * V_150 = V_156 ;
V_150 -> V_73 ( V_150 -> V_154 ) ;
}
static void V_77 ( void * V_156 )
{
}
