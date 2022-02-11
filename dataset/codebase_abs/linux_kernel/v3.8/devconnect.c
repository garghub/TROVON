static void F_1 ( struct V_1 * V_1 )
{
if ( V_1 ) {
F_2 ( V_1 -> V_2 ) ;
F_3 ( V_1 -> V_3 ) ;
F_2 ( V_1 ) ;
}
}
static struct V_1 * F_4 ( struct V_4 * V_4 )
{
struct V_1 * V_1 ;
struct V_5 * V_5 ;
struct V_6 * V_7 ;
V_1 = F_5 ( sizeof( * V_1 ) , V_8 ) ;
if ( V_1 == NULL )
goto V_9;
V_1 -> V_4 = V_4 ;
F_6 ( & V_1 -> V_10 , V_11 ) ;
V_5 = F_7 ( 0 , V_8 ) ;
if ( V_5 == NULL )
goto V_9;
V_1 -> V_3 = V_5 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL )
goto V_9;
V_1 -> V_2 = V_7 ;
V_7 -> V_12 = V_13 | V_14 | V_15 ;
V_7 -> V_16 = V_17 ;
V_7 -> V_18 = F_9 ( V_19 << 8 | V_4 -> V_20 ) ;
V_7 -> V_21 = 0 ;
V_7 -> V_22 = F_9 ( V_4 -> V_23 . V_24 . V_25 ) ;
return V_1 ;
V_9:
F_1 ( V_1 ) ;
return NULL ;
}
static void F_10 ( struct V_4 * V_4 )
{
unsigned V_26 ;
struct V_1 * V_27 ;
struct V_28 * V_29 ;
V_29 = & V_4 -> V_29 ;
V_26 = 0 ;
F_11 (dev_itr, &wusbhc->cack_list, cack_node) {
V_29 -> V_30 [ V_26 ] . V_31 = V_27 -> V_32 ;
V_29 -> V_30 [ V_26 ] . V_33 = V_27 -> V_34 ;
if ( ++ V_26 >= V_35 )
break;
}
V_29 -> V_36 . V_25 = sizeof( V_29 -> V_36 )
+ V_26 * sizeof( V_29 -> V_30 [ 0 ] ) ;
}
static struct V_1 * F_12 ( struct V_4 * V_4 ,
struct V_37 * V_38 ,
const char * V_39 , T_1 V_40 )
{
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_1 * V_1 ;
int V_43 = F_13 ( V_38 ) ;
T_1 V_44 ;
int V_45 ;
F_11 (wusb_dev, &wusbhc->cack_list, cack_node)
if ( ! memcmp ( & V_1 -> V_32 , & V_38 -> V_31 ,
sizeof( V_1 -> V_32 ) ) )
return V_1 ;
V_1 = F_4 ( V_4 ) ;
if ( V_1 == NULL )
return NULL ;
F_14 ( V_1 ) ;
V_1 -> V_32 = V_38 -> V_31 ;
V_1 -> V_40 = V_40 ;
F_15 ( V_1 -> V_46 . V_47 , V_48 ) ;
if ( 1 && V_43 == 0 )
V_43 = 1 ;
if ( V_43 ) {
V_44 = ( V_40 + 2 ) | V_49 ;
F_16 ( V_42 , L_1
L_2 , V_44 , V_40 ) ;
V_45 = F_17 ( V_4 , V_1 , V_44 ) ;
if ( V_45 < 0 )
return NULL ;
}
V_1 -> V_50 = V_51 ;
F_18 ( & V_1 -> V_52 , & V_4 -> V_53 ) ;
V_4 -> V_54 ++ ;
F_10 ( V_4 ) ;
return V_1 ;
}
static void F_19 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
F_20 ( & V_1 -> V_52 ) ;
V_4 -> V_54 -- ;
F_10 ( V_4 ) ;
}
static
void F_21 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
F_19 ( V_4 , V_1 ) ;
if ( V_4 -> V_54 )
F_22 ( V_4 , 0 , 0 , & V_4 -> V_29 . V_36 ) ;
else
F_23 ( V_4 , & V_4 -> V_29 . V_36 ) ;
}
static void V_11 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = F_24 ( V_56 , struct V_1 ,
V_10 ) ;
struct V_4 * V_4 = V_1 -> V_4 ;
F_25 ( & V_4 -> V_57 ) ;
F_21 ( V_4 , V_1 ) ;
F_26 ( & V_4 -> V_57 ) ;
F_27 ( V_1 ) ;
}
static
void F_28 ( struct V_4 * V_4 , struct V_37 * V_38 ,
const char * V_39 )
{
int V_45 ;
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_1 * V_1 ;
struct V_58 * V_59 ;
unsigned V_60 , V_61 ;
F_25 ( & V_4 -> V_57 ) ;
for ( V_60 = 0 ; V_60 < V_4 -> V_62 ; V_60 ++ ) {
V_59 = F_29 ( V_4 , V_60 ) ;
if ( V_59 -> V_1
&& memcmp ( & V_38 -> V_31 , & V_59 -> V_1 -> V_32 , sizeof( V_38 -> V_31 ) ) == 0 )
goto V_63;
}
for ( V_60 = 0 ; V_60 < V_4 -> V_62 ; V_60 ++ ) {
V_59 = F_29 ( V_4 , V_60 ) ;
if ( ( V_59 -> V_64 & V_65 )
&& ! ( V_59 -> V_64 & V_66 ) )
break;
}
if ( V_60 >= V_4 -> V_62 ) {
F_30 ( V_42 , L_3
L_4 ,
V_4 -> V_62 , V_39 ) ;
goto V_63;
}
V_61 = V_60 + 2 ;
V_4 -> V_67 ( V_4 , V_60 , 0 , NULL , 0 ) ;
V_1 = F_12 ( V_4 , V_38 , V_39 , V_60 ) ;
if ( V_1 == NULL )
goto V_63;
V_45 = F_22 ( V_4 , 0 , 0 , & V_4 -> V_29 . V_36 ) ;
if ( V_45 < 0 )
goto V_63;
F_31 ( 3 ) ;
V_59 -> V_1 = V_1 ;
V_59 -> V_64 |= V_66 ;
V_59 -> V_68 |= V_69 ;
V_63:
F_26 ( & V_4 -> V_57 ) ;
return;
}
static void F_32 ( struct V_4 * V_4 ,
struct V_58 * V_59 )
{
struct V_1 * V_1 = V_59 -> V_1 ;
V_59 -> V_64 &= ~ ( V_66 | V_70
| V_71 | V_72
| V_73 | V_74 ) ;
V_59 -> V_68 |= V_69 | V_75 ;
if ( V_1 ) {
F_33 ( V_4 -> V_42 , L_5 , V_1 -> V_40 ) ;
if ( ! F_34 ( & V_1 -> V_52 ) )
F_20 ( & V_1 -> V_52 ) ;
F_27 ( V_1 ) ;
}
V_59 -> V_1 = NULL ;
if ( V_4 -> V_76 )
F_35 ( V_4 ) ;
}
static void F_36 ( struct V_4 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_42 ;
unsigned V_26 ;
struct V_1 * V_1 ;
struct V_58 * V_58 ;
struct V_77 * V_78 = & V_4 -> V_79 ;
unsigned V_80 , V_81 ;
V_81 = V_78 -> V_36 . V_25 - sizeof( V_78 -> V_36 ) ;
V_80 = 0 ;
for ( V_26 = 0 ;
V_80 < V_35 && V_26 < V_4 -> V_62 ;
V_26 ++ ) {
unsigned V_82 = F_37 ( V_4 -> V_83 ) ;
V_58 = F_29 ( V_4 , V_26 ) ;
V_1 = V_58 -> V_1 ;
if ( V_1 == NULL )
continue;
if ( V_1 -> V_84 == NULL || ! V_1 -> V_84 -> V_85 )
continue;
if ( F_38 ( V_51 , V_1 -> V_50 + V_82 ) ) {
F_30 ( V_42 , L_6 ,
V_1 -> V_34 ) ;
F_32 ( V_4 , V_58 ) ;
} else if ( F_38 ( V_51 , V_1 -> V_50 + V_82 / 2 ) ) {
V_78 -> V_33 [ V_80 ++ ] = V_1 -> V_34 ;
}
}
if ( V_80 & 0x1 )
V_78 -> V_33 [ V_80 ++ ] = 0x7f ;
V_78 -> V_36 . V_25 = sizeof( V_78 -> V_36 ) +
V_80 * sizeof( V_78 -> V_33 [ 0 ] ) ;
if ( V_80 > 0 )
F_22 ( V_4 , 10 , 5 , & V_78 -> V_36 ) ;
else if ( V_81 != 0 )
F_23 ( V_4 , & V_78 -> V_36 ) ;
}
static void F_39 ( struct V_55 * V_86 )
{
struct V_87 * V_88 = F_40 ( V_86 ) ;
struct V_4 * V_4 = F_24 ( V_88 , struct V_4 , V_89 ) ;
F_25 ( & V_4 -> V_57 ) ;
F_36 ( V_4 ) ;
F_26 ( & V_4 -> V_57 ) ;
F_41 ( V_90 , & V_4 -> V_89 ,
F_37 ( V_4 -> V_83 / 2 ) ) ;
}
static struct V_1 * F_42 ( struct V_4 * V_4 , T_1 V_34 )
{
int V_91 ;
if ( V_34 == 0xff )
return NULL ;
if ( V_34 > 0 ) {
int V_59 = ( V_34 & ~ 0x80 ) - 2 ;
if ( V_59 < 0 || V_59 >= V_4 -> V_62 )
return NULL ;
return F_29 ( V_4 , V_59 ) -> V_1 ;
}
for ( V_91 = 0 ; V_91 < V_4 -> V_62 ; V_91 ++ ) {
struct V_1 * V_1 = F_29 ( V_4 , V_91 ) -> V_1 ;
if ( V_1 && V_1 -> V_34 == V_34 )
return V_1 ;
}
return NULL ;
}
static void F_43 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
F_25 ( & V_4 -> V_57 ) ;
V_1 -> V_50 = V_51 ;
F_36 ( V_4 ) ;
F_26 ( & V_4 -> V_57 ) ;
}
static void F_44 ( struct V_4 * V_4 ,
struct V_92 * V_93 ,
T_2 V_94 )
{
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_37 * V_38 ;
char V_39 [ V_95 ] ;
static const char * V_96 [] = {
L_7 ,
L_8 ,
L_9 ,
L_10
} ;
if ( V_94 < sizeof( * V_38 ) ) {
F_30 ( V_42 , L_11 ,
V_94 , sizeof( * V_38 ) ) ;
return;
}
V_38 = F_24 ( V_93 , struct V_37 , V_36 ) ;
F_45 ( V_39 , sizeof( V_39 ) , & V_38 -> V_31 ) ;
F_16 ( V_42 , L_12 ,
V_39 ,
F_46 ( V_38 ) ,
V_96 [ F_47 ( V_38 ) ] ,
F_13 ( V_38 ) ? L_13 : L_14 ) ;
F_28 ( V_4 , V_38 , V_39 ) ;
}
static void F_48 ( struct V_4 * V_4 , struct V_1 * V_1 )
{
struct V_41 * V_42 = V_4 -> V_42 ;
F_16 ( V_42 , L_15 , V_1 -> V_34 ) ;
F_25 ( & V_4 -> V_57 ) ;
F_32 ( V_4 , F_29 ( V_4 , V_1 -> V_40 ) ) ;
F_26 ( & V_4 -> V_57 ) ;
}
void F_49 ( struct V_4 * V_4 , T_1 V_97 ,
struct V_92 * V_93 , T_2 V_94 )
{
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_1 * V_1 ;
if ( V_94 < sizeof( struct V_92 ) ) {
F_30 ( V_42 , L_16 ,
( int ) V_94 , ( int ) sizeof( struct V_92 ) ) ;
return;
}
V_1 = F_42 ( V_4 , V_97 ) ;
if ( V_1 == NULL && V_93 -> V_98 != V_99 ) {
F_33 ( V_42 , L_17 ,
V_93 -> V_98 , V_97 ) ;
return;
}
switch ( V_93 -> V_98 ) {
case V_99 :
F_44 ( V_4 , V_93 , V_94 ) ;
break;
case V_100 :
F_43 ( V_4 , V_1 ) ;
break;
case V_101 :
F_48 ( V_4 , V_1 ) ;
break;
case V_102 :
case V_103 :
case V_104 :
break;
case V_105 :
break;
default:
F_50 ( V_42 , L_18 ,
V_93 -> V_98 , ( int ) V_94 , V_97 ) ;
}
}
void F_51 ( struct V_4 * V_4 , T_1 V_40 )
{
int V_45 ;
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_1 * V_1 ;
struct V_106 * V_78 ;
V_1 = F_29 ( V_4 , V_40 ) -> V_1 ;
if ( V_1 == NULL ) {
F_33 ( V_42 , L_19 ,
V_40 ) ;
return;
}
F_32 ( V_4 , F_29 ( V_4 , V_40 ) ) ;
V_78 = F_5 ( sizeof( * V_78 ) , V_8 ) ;
if ( V_78 == NULL )
return;
V_78 -> V_36 . V_25 = sizeof( * V_78 ) ;
V_78 -> V_36 . V_107 = V_108 ;
V_78 -> V_33 = V_1 -> V_34 ;
V_45 = F_22 ( V_4 , 0 , 0 , & V_78 -> V_36 ) ;
if ( V_45 < 0 )
F_30 ( V_42 , L_20 , V_45 ) ;
else {
F_31 ( 7 * 4 ) ;
F_23 ( V_4 , & V_78 -> V_36 ) ;
}
F_2 ( V_78 ) ;
}
static int F_52 ( struct V_109 * V_84 ,
struct V_1 * V_1 ,
struct V_110 * V_111 , T_2 V_112 )
{
T_3 V_45 ;
struct V_41 * V_42 = & V_84 -> V_42 ;
void * V_113 , * V_114 ;
V_113 = ( void * ) V_111 + sizeof( * V_111 ) ;
V_114 = V_113 + V_112 - sizeof( * V_111 ) ;
while ( V_113 < V_114 ) {
struct V_115 * V_116 = V_113 ;
T_2 V_117 ;
T_1 V_118 ;
if ( V_114 - V_113 < sizeof( * V_116 ) ) {
F_30 ( V_42 , L_21
L_22 ,
( int ) ( V_113 - ( void * ) V_111 ) , V_114 - V_113 ) ;
V_45 = - V_119 ;
goto V_120;
}
V_117 = V_116 -> V_25 ;
V_118 = V_116 -> V_121 ;
if ( V_117 == 0 )
break;
if ( V_117 > V_114 - V_113 ) {
F_30 ( V_42 , L_23
L_24
L_25 ,
( int ) ( V_113 - ( void * ) V_111 ) ,
V_118 , V_117 , V_114 - V_113 ) ;
V_45 = - V_122 ;
goto V_120;
}
switch ( V_118 ) {
case V_123 :
if ( V_117 != sizeof( * V_1 -> V_124 ) )
F_30 ( V_42 , L_26
L_27
L_28 , V_117 ,
sizeof( * V_1 -> V_124 ) ) ;
else
V_1 -> V_124 = V_113 ;
break;
default:
F_30 ( V_42 , L_29
L_30 , V_118 ,
V_117 , ( int ) ( V_113 - ( void * ) V_111 ) ) ;
}
V_113 += V_117 ;
}
V_45 = 0 ;
V_120:
return V_45 ;
}
static int F_53 ( struct V_109 * V_84 ,
struct V_1 * V_1 )
{
T_3 V_45 ;
struct V_41 * V_42 = & V_84 -> V_42 ;
struct V_110 * V_111 ;
T_2 V_125 = 32 , V_112 = 4 ;
V_111 = F_8 ( V_125 , V_8 ) ;
if ( V_111 == NULL )
return - V_126 ;
V_45 = F_54 ( V_84 , V_127 , 0 , V_111 , V_112 ) ;
if ( V_45 < 4 ) {
F_30 ( V_42 , L_31 ,
V_45 ) ;
goto V_128;
}
V_112 = F_55 ( V_111 -> V_129 ) ;
if ( V_112 >= V_125 ) {
F_2 ( V_111 ) ;
V_125 = V_112 ;
V_111 = F_8 ( V_125 , V_8 ) ;
if ( V_111 == NULL )
return - V_126 ;
}
V_45 = F_54 ( V_84 , V_127 , 0 , V_111 , V_112 ) ;
if ( V_45 < 0 || V_45 != V_112 ) {
F_30 ( V_42 , L_32
L_33 , V_112 , V_45 ) ;
goto V_128;
}
if ( V_45 < sizeof( * V_111 )
|| F_55 ( V_111 -> V_129 ) != V_112 ) {
F_30 ( V_42 , L_32
L_33 , V_112 , V_45 ) ;
goto V_128;
}
V_45 = F_52 ( V_84 , V_1 , V_111 , V_45 ) ;
if ( V_45 < 0 )
goto V_130;
V_1 -> V_111 = V_111 ;
return 0 ;
V_130:
V_128:
F_2 ( V_111 ) ;
V_1 -> V_124 = NULL ;
return V_45 ;
}
static void F_56 ( struct V_1 * V_1 )
{
F_2 ( V_1 -> V_111 ) ;
V_1 -> V_124 = NULL ;
}
static void F_57 ( struct V_109 * V_84 )
{
int V_45 = 0 ;
struct V_1 * V_1 ;
struct V_4 * V_4 ;
struct V_41 * V_42 = & V_84 -> V_42 ;
T_1 V_40 ;
if ( V_84 -> V_131 == 0 || V_84 -> V_61 == 1 )
return;
F_58 ( V_84 , V_132 ) ;
V_4 = F_59 ( V_84 ) ;
if ( V_4 == NULL )
goto V_133;
F_25 ( & V_4 -> V_57 ) ;
V_1 = F_60 ( V_4 , V_84 ) ;
V_40 = F_61 ( V_84 -> V_134 ) ;
F_26 ( & V_4 -> V_57 ) ;
if ( V_1 == NULL )
goto V_133;
V_1 -> V_84 = F_62 ( V_84 ) ;
V_84 -> V_1 = F_63 ( V_1 ) ;
V_45 = F_64 ( V_4 , V_84 , V_1 ) ;
if ( V_45 < 0 ) {
F_30 ( V_42 , L_34 , V_45 ) ;
goto V_135;
}
V_45 = F_53 ( V_84 , V_1 ) ;
if ( V_45 < 0 ) {
F_30 ( V_42 , L_35 , V_45 ) ;
goto V_136;
}
V_45 = F_65 ( V_4 , V_84 , V_1 ) ;
if ( V_45 < 0 )
goto V_137;
V_138:
F_27 ( V_1 ) ;
F_66 ( V_4 ) ;
V_133:
return;
F_67 ( V_1 ) ;
V_137:
F_56 ( V_1 ) ;
V_136:
F_68 ( V_1 ) ;
V_135:
F_25 ( & V_4 -> V_57 ) ;
F_32 ( V_4 , F_29 ( V_4 , V_40 ) ) ;
F_26 ( & V_4 -> V_57 ) ;
goto V_138;
}
static void F_69 ( struct V_109 * V_84 )
{
struct V_1 * V_1 = V_84 -> V_1 ;
if ( V_84 -> V_131 == 0 || V_84 -> V_61 == 1 )
return;
F_67 ( V_1 ) ;
F_56 ( V_1 ) ;
F_68 ( V_1 ) ;
V_1 -> V_84 = NULL ;
V_84 -> V_1 = NULL ;
F_27 ( V_1 ) ;
F_70 ( V_84 ) ;
}
int F_71 ( struct V_139 * V_140 , unsigned long V_141 ,
void * V_142 )
{
int V_45 = V_143 ;
switch ( V_141 ) {
case V_144 :
F_57 ( V_142 ) ;
break;
case V_145 :
F_69 ( V_142 ) ;
break;
case V_146 :
case V_147 :
break;
default:
F_72 ( 1 ) ;
V_45 = V_148 ;
} ;
return V_45 ;
}
struct V_1 * F_60 ( struct V_4 * V_4 ,
struct V_109 * V_84 )
{
struct V_1 * V_1 ;
T_1 V_40 ;
V_40 = F_61 ( V_84 -> V_134 ) ;
F_73 ( V_40 > V_4 -> V_62 ) ;
V_1 = F_29 ( V_4 , V_40 ) -> V_1 ;
if ( V_1 != NULL )
F_63 ( V_1 ) ;
return V_1 ;
}
void F_74 ( struct V_149 * V_150 )
{
struct V_1 * V_1 = F_24 ( V_150 , struct V_1 , V_151 ) ;
F_20 ( & V_1 -> V_52 ) ;
F_1 ( V_1 ) ;
}
int F_75 ( struct V_4 * V_4 )
{
V_4 -> V_79 . V_36 . V_107 = V_152 ;
V_4 -> V_79 . V_36 . V_25 = sizeof( V_4 -> V_79 . V_36 ) ;
F_76 ( & V_4 -> V_89 , F_39 ) ;
V_4 -> V_29 . V_36 . V_107 = V_153 ;
V_4 -> V_29 . V_36 . V_25 = sizeof( V_4 -> V_29 . V_36 ) ;
F_77 ( & V_4 -> V_53 ) ;
return 0 ;
}
void F_78 ( struct V_4 * V_4 )
{
}
int F_79 ( struct V_4 * V_4 )
{
struct V_41 * V_42 = V_4 -> V_42 ;
struct V_154 * V_155 ;
int V_45 ;
V_155 = F_5 ( sizeof( * V_155 ) , V_8 ) ;
if ( V_155 == NULL )
return - V_126 ;
V_155 -> V_36 . V_25 = sizeof( * V_155 ) ;
V_155 -> V_36 . V_107 = V_156 ;
V_155 -> V_157 = F_9 ( ( V_4 -> V_158 -> V_159 << 3 ) | V_160 ) ;
V_155 -> V_161 = V_4 -> V_162 ;
V_45 = F_22 ( V_4 , 0 , 0 , & V_155 -> V_36 ) ;
if ( V_45 < 0 ) {
F_30 ( V_42 , L_36 , V_45 ) ;
goto V_163;
}
V_4 -> V_154 = V_155 ;
F_41 ( V_90 , & V_4 -> V_89 ,
( V_4 -> V_83 * V_164 ) / 1000 / 2 ) ;
return 0 ;
V_163:
F_2 ( V_155 ) ;
return V_45 ;
}
void F_80 ( struct V_4 * V_4 )
{
int V_165 ;
F_25 ( & V_4 -> V_57 ) ;
for ( V_165 = 0 ; V_165 < V_4 -> V_62 ; V_165 ++ ) {
if ( V_4 -> V_59 [ V_165 ] . V_1 )
F_32 ( V_4 , & V_4 -> V_59 [ V_165 ] ) ;
}
F_26 ( & V_4 -> V_57 ) ;
F_81 ( & V_4 -> V_89 ) ;
F_23 ( V_4 , & V_4 -> V_154 -> V_36 ) ;
F_2 ( V_4 -> V_154 ) ;
V_4 -> V_154 = NULL ;
}
int F_17 ( struct V_4 * V_4 , struct V_1 * V_1 , T_1 V_34 )
{
int V_45 ;
V_1 -> V_34 = V_34 ;
V_45 = V_4 -> V_166 ( V_4 , V_1 ) ;
if ( V_45 < 0 )
F_30 ( V_4 -> V_42 , L_37
L_38 , V_1 -> V_40 ) ;
else
F_16 ( V_4 -> V_42 , L_39 ,
V_1 -> V_40 ,
( V_34 & V_49 ) ? L_40 : L_41 ,
V_1 -> V_34 ) ;
return V_45 ;
}
