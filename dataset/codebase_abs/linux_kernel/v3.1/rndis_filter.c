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
struct V_29 * V_30 = F_15 ( & V_28 -> V_2 ) ;
switch ( V_14 -> V_20 ) {
case V_31 :
F_16 ( V_30 , L_1
L_2
L_3
L_4 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_32 . V_33 ,
V_14 -> V_21 . V_32 . V_34 ,
V_14 -> V_21 . V_32 . V_35 ,
V_14 -> V_21 . V_32 . V_36 ,
V_14 -> V_21 . V_32 . V_37 ,
V_14 -> V_21 . V_32 . V_38 ,
V_14 -> V_21 . V_32 . V_39 ) ;
break;
case V_40 :
F_16 ( V_30 , L_5
L_6
L_7
L_8 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_41 . V_23 ,
V_14 -> V_21 . V_41 . V_42 ,
V_14 -> V_21 . V_41 . V_43 ,
V_14 -> V_21 . V_41 . V_44 ,
V_14 -> V_21 . V_41 . V_45 ,
V_14 -> V_21 . V_41 . V_46 ,
V_14 -> V_21 . V_41 .
V_47 ,
V_14 -> V_21 . V_41 .
V_48 ) ;
break;
case V_49 :
F_16 ( V_30 , L_9
L_10
L_11 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_50 . V_23 ,
V_14 -> V_21 . V_50 . V_42 ,
V_14 -> V_21 . V_50 .
V_51 ,
V_14 -> V_21 . V_50 .
V_52 ) ;
break;
case V_53 :
F_16 ( V_30 ,
L_12 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_54 . V_23 ,
V_14 -> V_21 . V_54 . V_42 ) ;
break;
case V_55 :
F_16 ( V_30 , L_13
L_14 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_56 . V_42 ,
V_14 -> V_21 . V_56 . V_57 ,
V_14 -> V_21 . V_56 . V_58 ) ;
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
int V_59 ;
struct V_60 * V_61 ;
V_61 = & V_26 -> V_32 ;
V_61 -> V_62 = false ;
V_61 -> V_63 = V_26 -> V_19 . V_11 ;
V_61 -> V_64 = 1 ;
V_61 -> V_65 [ 0 ] . V_66 = F_18 ( & V_26 -> V_19 ) >>
V_67 ;
V_61 -> V_65 [ 0 ] . V_68 = V_26 -> V_19 . V_11 ;
V_61 -> V_65 [ 0 ] . V_69 =
( unsigned long ) & V_26 -> V_19 & ( V_70 - 1 ) ;
V_61 -> V_71 . V_72 . V_73 = V_26 ;
V_61 -> V_71 . V_72 . V_74 =
V_75 ;
V_61 -> V_71 . V_72 . V_76 = ( unsigned long ) V_9 ;
V_59 = F_19 ( V_9 -> V_77 -> V_9 , V_61 ) ;
return V_59 ;
}
static void F_20 ( struct V_1 * V_9 ,
struct V_13 * V_78 )
{
struct V_8 * V_12 = NULL ;
bool V_79 = false ;
unsigned long V_17 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_21 (request, &dev->req_list, list_ent) {
if ( V_12 -> V_19 . V_21 . V_80 . V_23
== V_78 -> V_21 . V_41 . V_23 ) {
V_79 = true ;
break;
}
}
F_10 ( & V_9 -> V_4 , V_17 ) ;
if ( V_79 ) {
if ( V_78 -> V_11 <= sizeof( struct V_13 ) ) {
memcpy ( & V_12 -> V_81 , V_78 ,
V_78 -> V_11 ) ;
} else {
F_22 ( & V_9 -> V_77 -> V_9 -> V_2 ,
L_16
L_17 ,
V_78 -> V_11 ,
sizeof( struct V_82 ) ) ;
if ( V_78 -> V_20 ==
V_83 ) {
V_12 -> V_81 . V_21 . V_84 .
V_42 = V_85 ;
} else {
V_12 -> V_81 . V_21 .
V_41 . V_42 =
V_85 ;
}
}
F_23 ( & V_12 -> V_18 ) ;
} else {
F_22 ( & V_9 -> V_77 -> V_9 -> V_2 ,
L_18
L_19 ,
V_78 -> V_21 . V_41 . V_23 ,
V_78 -> V_20 ) ;
}
}
static void F_24 ( struct V_1 * V_9 ,
struct V_13 * V_78 )
{
struct V_86 * V_87 =
& V_78 -> V_21 . V_56 ;
if ( V_87 -> V_42 == V_88 ) {
F_25 (
V_9 -> V_77 -> V_9 , 1 ) ;
} else if ( V_87 -> V_42 == V_89 ) {
F_25 (
V_9 -> V_77 -> V_9 , 0 ) ;
} else {
}
}
static void F_26 ( struct V_1 * V_9 ,
struct V_13 * V_21 ,
struct V_60 * V_32 )
{
struct V_90 * V_91 ;
T_1 V_33 ;
V_91 = & V_21 -> V_21 . V_32 ;
V_33 = V_92 + V_91 -> V_33 ;
V_32 -> V_63 -= V_33 ;
V_32 -> V_65 [ 0 ] . V_69 += V_33 ;
V_32 -> V_65 [ 0 ] . V_68 -= V_33 ;
V_32 -> V_62 = true ;
F_27 ( V_9 -> V_77 -> V_9 , V_32 ) ;
}
int F_28 ( struct V_27 * V_9 ,
struct V_60 * V_32 )
{
struct V_93 * V_77 = V_9 -> V_94 ;
struct V_1 * V_95 ;
struct V_13 V_14 ;
struct V_13 * V_96 ;
if ( ! V_77 )
return - V_97 ;
if ( ! V_77 -> V_98 ) {
F_22 ( & V_9 -> V_2 , L_20
L_21 ) ;
return - 1 ;
}
V_95 = (struct V_1 * ) V_77 -> V_98 ;
if ( V_95 -> V_6 == V_7 ) {
F_22 ( & V_9 -> V_2 , L_22
L_23 ) ;
return - 1 ;
}
V_96 = (struct V_13 * ) F_29 (
F_30 ( V_32 -> V_65 [ 0 ] . V_66 ) , V_99 ) ;
V_96 = ( void * ) ( ( unsigned long ) V_96 +
V_32 -> V_65 [ 0 ] . V_69 ) ;
if ( ( V_96 -> V_20 != V_31 ) &&
( V_96 -> V_11 > sizeof( struct V_13 ) ) ) {
F_22 ( & V_9 -> V_2 , L_24
L_25 ,
V_96 -> V_11 ,
sizeof( struct V_13 ) ) ;
}
memcpy ( & V_14 , V_96 ,
( V_96 -> V_11 > sizeof( struct V_13 ) ) ?
sizeof( struct V_13 ) :
V_96 -> V_11 ) ;
F_31 ( V_96 - V_32 -> V_65 [ 0 ] . V_69 , V_99 ) ;
F_14 ( V_9 , & V_14 ) ;
switch ( V_14 . V_20 ) {
case V_31 :
F_26 ( V_95 , & V_14 , V_32 ) ;
break;
case V_40 :
case V_49 :
case V_53 :
F_20 ( V_95 , & V_14 ) ;
break;
case V_55 :
F_24 ( V_95 , & V_14 ) ;
break;
default:
F_22 ( & V_9 -> V_2 ,
L_26 ,
V_14 . V_20 ,
V_14 . V_11 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_9 , T_1 V_100 ,
void * V_101 , T_1 * V_102 )
{
struct V_8 * V_12 ;
T_1 V_103 = * V_102 ;
struct V_104 * V_105 ;
struct V_106 * V_50 ;
int V_59 = 0 ;
int V_107 ;
if ( ! V_101 )
return - V_97 ;
* V_102 = 0 ;
V_12 = F_5 ( V_9 , V_108 ,
F_33 ( struct V_104 ) ) ;
if ( ! V_12 ) {
V_59 = - 1 ;
goto V_109;
}
V_105 = & V_12 -> V_19 . V_21 . V_110 ;
V_105 -> V_100 = V_100 ;
V_105 -> V_52 = sizeof( struct V_104 ) ;
V_105 -> V_51 = 0 ;
V_105 -> V_111 = 0 ;
V_59 = F_17 ( V_9 , V_12 ) ;
if ( V_59 != 0 )
goto V_109;
V_107 = F_34 ( & V_12 -> V_18 , 5 * V_112 ) ;
if ( V_107 == 0 ) {
V_59 = - V_113 ;
goto V_109;
}
V_50 = & V_12 -> V_81 . V_21 . V_50 ;
if ( V_50 -> V_51 > V_103 ) {
V_59 = - 1 ;
goto V_109;
}
memcpy ( V_101 ,
( void * ) ( ( unsigned long ) V_50 +
V_50 -> V_52 ) ,
V_50 -> V_51 ) ;
* V_102 = V_50 -> V_51 ;
V_109:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_59 ;
}
static int F_35 ( struct V_1 * V_9 )
{
T_1 V_114 = V_115 ;
return F_32 ( V_9 ,
V_116 ,
V_9 -> V_117 , & V_114 ) ;
}
static int F_36 ( struct V_1 * V_9 )
{
T_1 V_114 = sizeof( T_1 ) ;
return F_32 ( V_9 ,
V_118 ,
& V_9 -> V_119 , & V_114 ) ;
}
static int F_37 ( struct V_1 * V_9 ,
T_1 V_120 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_121 * V_54 ;
T_1 V_42 ;
int V_59 , V_107 ;
V_12 = F_5 ( V_9 , V_122 ,
F_33 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_59 = - 1 ;
goto V_109;
}
V_16 = & V_12 -> V_19 . V_21 . V_22 ;
V_16 -> V_100 = V_123 ;
V_16 -> V_51 = sizeof( T_1 ) ;
V_16 -> V_52 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_120 , sizeof( T_1 ) ) ;
V_59 = F_17 ( V_9 , V_12 ) ;
if ( V_59 != 0 )
goto V_109;
V_107 = F_34 ( & V_12 -> V_18 , 5 * V_112 ) ;
if ( V_107 == 0 ) {
V_59 = - 1 ;
F_22 ( & V_9 -> V_77 -> V_9 -> V_2 ,
L_27 ) ;
goto Exit;
} else {
if ( V_59 > 0 )
V_59 = 0 ;
V_54 = & V_12 -> V_81 . V_21 . V_54 ;
V_42 = V_54 -> V_42 ;
}
V_109:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
Exit:
return V_59 ;
}
static int F_38 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_124 * V_125 ;
struct V_126 * V_41 ;
T_1 V_42 ;
int V_59 , V_107 ;
V_12 = F_5 ( V_9 , V_127 ,
F_33 ( struct V_124 ) ) ;
if ( ! V_12 ) {
V_59 = - 1 ;
goto V_109;
}
V_125 = & V_12 -> V_19 . V_21 . V_80 ;
V_125 -> V_43 = V_128 ;
V_125 -> V_44 = V_129 ;
V_125 -> V_46 = 2048 ;
V_9 -> V_6 = V_130 ;
V_59 = F_17 ( V_9 , V_12 ) ;
if ( V_59 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_109;
}
V_107 = F_34 ( & V_12 -> V_18 , 5 * V_112 ) ;
if ( V_107 == 0 ) {
V_59 = - V_113 ;
goto V_109;
}
V_41 = & V_12 -> V_81 . V_21 . V_41 ;
V_42 = V_41 -> V_42 ;
if ( V_42 == V_131 ) {
V_9 -> V_6 = V_132 ;
V_59 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_59 = - 1 ;
}
V_109:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_59 ;
}
static void F_39 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_133 * V_134 ;
V_12 = F_5 ( V_9 , V_135 ,
F_33 ( struct V_133 ) ) ;
if ( ! V_12 )
goto V_109;
V_134 = & V_12 -> V_19 . V_21 . V_136 ;
V_134 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_109:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_40 ( struct V_1 * V_9 )
{
int V_59 ;
if ( V_9 -> V_6 != V_132 )
return 0 ;
V_59 = F_37 ( V_9 ,
V_137 |
V_138 |
V_139 ) ;
if ( V_59 == 0 )
V_9 -> V_6 = V_140 ;
return V_59 ;
}
static int F_41 ( struct V_1 * V_9 )
{
int V_59 ;
if ( V_9 -> V_6 != V_140 )
return 0 ;
V_59 = F_37 ( V_9 , 0 ) ;
if ( V_59 == 0 )
V_9 -> V_6 = V_132 ;
return V_59 ;
}
int F_42 ( struct V_27 * V_9 ,
void * V_141 )
{
int V_59 ;
struct V_93 * V_142 ;
struct V_1 * V_143 ;
struct V_144 * V_145 = V_141 ;
V_143 = F_1 () ;
if ( ! V_143 )
return - 1 ;
V_59 = F_43 ( V_9 , V_141 ) ;
if ( V_59 != 0 ) {
F_13 ( V_143 ) ;
return V_59 ;
}
V_142 = V_9 -> V_94 ;
V_142 -> V_98 = V_143 ;
V_143 -> V_77 = V_142 ;
V_59 = F_38 ( V_143 ) ;
if ( V_59 != 0 ) {
}
V_59 = F_35 ( V_143 ) ;
if ( V_59 != 0 ) {
}
memcpy ( V_145 -> V_146 , V_143 -> V_117 , V_115 ) ;
F_36 ( V_143 ) ;
V_145 -> V_147 = V_143 -> V_119 ;
F_44 ( & V_9 -> V_2 , L_28 ,
V_143 -> V_117 ,
( ( V_145 -> V_147 ) ? ( L_29 ) : ( L_30 ) ) ) ;
return V_59 ;
}
void F_45 ( struct V_27 * V_9 )
{
struct V_93 * V_77 = V_9 -> V_94 ;
struct V_1 * V_95 = V_77 -> V_98 ;
F_39 ( V_95 ) ;
F_13 ( V_95 ) ;
V_77 -> V_98 = NULL ;
F_46 ( V_9 ) ;
}
int F_47 ( struct V_27 * V_9 )
{
struct V_93 * V_142 = V_9 -> V_94 ;
if ( ! V_142 )
return - V_97 ;
return F_40 ( V_142 -> V_98 ) ;
}
int F_48 ( struct V_27 * V_9 )
{
struct V_93 * V_142 = V_9 -> V_94 ;
if ( ! V_142 )
return - V_97 ;
return F_41 ( V_142 -> V_98 ) ;
}
int F_49 ( struct V_27 * V_9 ,
struct V_60 * V_32 )
{
int V_59 ;
struct V_82 * V_148 ;
struct V_13 * V_149 ;
struct V_90 * V_150 ;
T_1 V_151 ;
V_148 = (struct V_82 * ) V_32 -> V_98 ;
memset ( V_148 , 0 , sizeof( struct V_82 ) ) ;
V_149 = & V_148 -> V_21 ;
V_151 = F_33 ( struct V_90 ) ;
V_149 -> V_20 = V_31 ;
V_149 -> V_11 = V_32 -> V_63 +
V_151 ;
V_150 = & V_149 -> V_21 . V_32 ;
V_150 -> V_33 = sizeof( struct V_90 ) ;
V_150 -> V_34 = V_32 -> V_63 ;
V_32 -> V_62 = true ;
V_32 -> V_65 [ 0 ] . V_66 = F_18 ( V_149 ) >> V_67 ;
V_32 -> V_65 [ 0 ] . V_69 =
( unsigned long ) V_149 & ( V_70 - 1 ) ;
V_32 -> V_65 [ 0 ] . V_68 = V_151 ;
V_148 -> V_71 = V_32 -> V_71 . V_72 . V_74 ;
V_148 -> V_152 =
V_32 -> V_71 . V_72 . V_73 ;
V_32 -> V_71 . V_72 . V_74 = V_153 ;
V_32 -> V_71 . V_72 . V_73 = V_148 ;
V_59 = F_19 ( V_9 , V_32 ) ;
if ( V_59 != 0 ) {
V_32 -> V_71 . V_72 . V_74 =
V_148 -> V_71 ;
V_32 -> V_71 . V_72 . V_73 =
V_148 -> V_152 ;
}
return V_59 ;
}
static void V_153 ( void * V_154 )
{
struct V_82 * V_148 = V_154 ;
V_148 -> V_71 ( V_148 -> V_152 ) ;
}
static void V_75 ( void * V_154 )
{
}
