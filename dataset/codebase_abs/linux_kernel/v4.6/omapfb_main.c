static void F_1 ( struct V_1 * V_2 )
{
}
static void F_2 ( struct V_3 * V_4 )
{
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_5 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
int V_6 ;
int V_7 ;
if ( V_8 ) {
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ )
V_4 -> V_9 . V_10 [ V_7 ] . V_11 =
F_7 ( V_12 [ V_7 ] ) ;
V_4 -> V_9 . V_13 = V_7 ;
}
if ( ! V_4 -> V_9 . V_13 ) {
struct V_14 * V_15 = V_4 -> V_15 ;
int V_16 ;
int V_17 = V_15 -> V_17 ;
if ( V_17 == 12 )
V_17 = 16 ;
V_16 = V_18 * V_19 * V_17 / 8 ;
V_4 -> V_9 . V_13 = 1 ;
V_4 -> V_9 . V_10 [ 0 ] . V_11 = F_7 ( V_16 ) ;
}
V_6 = V_4 -> V_20 -> V_21 ( V_4 , 0 , & V_4 -> V_9 ) ;
if ( V_6 < 0 ) {
F_8 ( V_4 -> V_2 , L_1 ,
V_6 ) ;
return V_6 ;
}
#ifdef F_9
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
F_10 ( V_4 -> V_2 , L_2 ,
V_7 ,
V_4 -> V_9 . V_10 [ V_7 ] . V_22 ,
V_4 -> V_9 . V_10 [ V_7 ] . V_23 ,
V_4 -> V_9 . V_10 [ V_7 ] . V_11 ) ;
}
#endif
return 0 ;
}
static void F_11 ( struct V_3 * V_4 )
{
V_4 -> V_20 -> V_24 () ;
}
static int F_12 ( struct V_25 * V_26 )
{
int V_6 ;
unsigned long V_27 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_31 * V_32 = & V_26 -> V_32 ;
V_27 = V_32 -> V_33 * V_26 -> V_34 . V_35 +
V_32 -> V_36 * V_32 -> V_37 / 8 ;
if ( V_4 -> V_20 -> V_38 )
V_4 -> V_20 -> V_38 () ;
V_6 = V_4 -> V_20 -> V_39 ( V_29 -> V_40 , V_29 -> V_41 . V_42 ,
V_27 , V_32 -> V_43 ,
V_29 -> V_41 . V_44 , V_29 -> V_41 . V_45 ,
V_32 -> V_46 , V_32 -> V_47 , V_29 -> V_48 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_4 -> V_20 -> V_49 != NULL ) {
V_6 = V_4 -> V_20 -> V_49 ( V_32 -> V_50 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_4 -> V_20 -> V_51 != NULL )
V_6 = V_4 -> V_20 -> V_51 ( V_29 -> V_40 ,
V_32 -> V_46 , V_32 -> V_47 ,
V_29 -> V_41 . V_52 ,
V_29 -> V_41 . V_53 ) ;
return V_6 ;
}
static int F_13 ( struct V_25 * V_41 , int V_54 )
{
return 0 ;
}
static int F_14 ( struct V_25 * V_41 , int V_54 )
{
F_15 ( V_41 ) ;
return 0 ;
}
static int F_16 ( struct V_25 * V_41 , T_1 V_55 , T_1 V_56 , T_1 V_57 ,
T_1 V_58 , T_1 V_59 , int V_60 )
{
struct V_28 * V_29 = V_41 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_31 * V_32 = & V_41 -> V_32 ;
int V_6 = 0 ;
switch ( V_29 -> V_48 ) {
case V_61 :
case V_62 :
case V_63 :
V_6 = - V_64 ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
if ( V_4 -> V_20 -> V_69 )
V_6 = V_4 -> V_20 -> V_69 ( V_55 , V_56 , V_57 , V_58 ,
V_59 , V_60 ) ;
case V_70 :
case V_71 :
if ( V_6 != 0 )
break;
if ( V_55 < 16 ) {
T_2 V_72 ;
V_72 = ( ( V_56 >> ( 16 - V_32 -> V_56 . V_73 ) ) <<
V_32 -> V_56 . V_27 ) |
( ( V_57 >> ( 16 - V_32 -> V_57 . V_73 ) ) <<
V_32 -> V_57 . V_27 ) |
( V_58 >> ( 16 - V_32 -> V_58 . V_73 ) ) ;
( ( V_74 * ) ( V_41 -> V_75 ) ) [ V_55 ] = V_72 ;
}
break;
default:
F_17 () ;
}
return V_6 ;
}
static int F_18 ( T_1 V_55 , T_1 V_56 , T_1 V_57 , T_1 V_58 ,
T_1 V_59 , struct V_25 * V_41 )
{
return F_16 ( V_41 , V_55 , V_56 , V_57 , V_58 , V_59 , 1 ) ;
}
static int F_19 ( struct V_76 * V_77 , struct V_25 * V_41 )
{
int V_78 , V_79 , V_6 ;
T_2 * V_56 , * V_57 , * V_58 , * V_59 ;
T_2 V_80 = 0xffff ;
V_56 = V_77 -> V_56 ;
V_57 = V_77 -> V_57 ;
V_58 = V_77 -> V_58 ;
V_59 = V_77 -> V_59 ;
V_79 = V_77 -> V_81 ;
for ( V_78 = 0 ; V_78 < V_77 -> V_82 ; V_78 ++ ) {
if ( V_59 )
V_80 = * V_59 ++ ;
V_6 = F_16 ( V_41 , V_79 ++ , * V_56 ++ , * V_57 ++ , * V_58 ++ , V_80 ,
V_78 == V_77 -> V_82 - 1 ) ;
if ( V_6 != 0 )
return V_6 ;
}
return 0 ;
}
static int F_20 ( int V_83 , struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
int V_84 = 0 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
switch ( V_83 ) {
case V_85 :
if ( V_4 -> V_86 == V_87 ) {
if ( V_4 -> V_20 -> V_88 )
V_4 -> V_20 -> V_88 () ;
V_4 -> V_15 -> V_89 ( V_4 -> V_15 ) ;
V_4 -> V_86 = V_90 ;
if ( V_4 -> V_20 -> V_91 () ==
V_92 )
V_84 = 1 ;
}
break;
case V_93 :
if ( V_4 -> V_86 == V_90 ) {
V_4 -> V_15 -> V_94 ( V_4 -> V_15 ) ;
if ( V_4 -> V_20 -> V_95 )
V_4 -> V_20 -> V_95 () ;
V_4 -> V_86 = V_87 ;
}
break;
default:
V_6 = - V_64 ;
}
F_4 ( V_4 ) ;
if ( V_6 == 0 && V_84 )
V_6 = F_21 ( V_26 ) ;
return V_6 ;
}
static void F_15 ( struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
F_2 ( V_4 ) ;
if ( V_4 -> V_20 -> V_38 )
V_4 -> V_20 -> V_38 () ;
F_4 ( V_4 ) ;
}
static void F_22 ( struct V_25 * V_26 , int V_96 )
{
struct V_97 * V_34 = & V_26 -> V_34 ;
struct V_31 * V_32 = & V_26 -> V_32 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_98 * V_99 ;
int V_17 ;
V_99 = & V_29 -> V_4 -> V_9 . V_10 [ V_29 -> V_40 ] ;
V_26 -> V_100 = V_99 -> V_23 ;
if ( ! V_96 ) {
F_3 ( & V_26 -> V_101 ) ;
V_34 -> V_102 = V_99 -> V_22 ;
V_34 -> V_103 = V_99 -> V_11 ;
F_5 ( & V_26 -> V_101 ) ;
} else {
V_34 -> V_102 = V_99 -> V_22 ;
V_34 -> V_103 = V_99 -> V_11 ;
}
V_34 -> type = V_104 ;
V_17 = V_32 -> V_37 ;
if ( V_32 -> V_105 )
V_34 -> V_106 = V_107 ;
else switch ( V_32 -> V_37 ) {
case 16 :
case 12 :
V_34 -> V_106 = V_108 ;
V_17 = 16 ;
break;
case 1 :
case 2 :
case 4 :
case 8 :
V_34 -> V_106 = V_107 ;
break;
}
V_34 -> V_109 = V_110 ;
V_34 -> V_35 = V_32 -> V_43 * V_17 / 8 ;
}
static int F_23 ( struct V_28 * V_29 ,
struct V_31 * V_32 )
{
switch ( V_32 -> V_105 ) {
case 0 :
break;
case V_61 :
V_32 -> V_37 = 16 ;
V_29 -> V_48 = V_32 -> V_105 ;
return 0 ;
case V_62 :
V_32 -> V_37 = 12 ;
V_29 -> V_48 = V_32 -> V_105 ;
return 0 ;
case V_63 :
V_32 -> V_37 = 16 ;
V_29 -> V_48 = V_32 -> V_105 ;
return 0 ;
default:
return - V_64 ;
}
switch ( V_32 -> V_37 ) {
case 1 :
V_29 -> V_48 = V_68 ;
return 0 ;
case 2 :
V_29 -> V_48 = V_67 ;
return 0 ;
case 4 :
V_29 -> V_48 = V_66 ;
return 0 ;
case 8 :
V_29 -> V_48 = V_65 ;
return 0 ;
case 12 :
V_32 -> V_37 = 16 ;
case 16 :
if ( V_29 -> V_4 -> V_15 -> V_17 == 12 )
V_29 -> V_48 = V_71 ;
else
V_29 -> V_48 = V_70 ;
return 0 ;
default:
return - V_64 ;
}
}
static int F_24 ( struct V_25 * V_26 ,
struct V_31 * V_32 )
{
int V_17 ;
unsigned long V_111 ;
unsigned long V_112 ;
int V_113 , V_114 ;
int V_115 , V_116 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_14 * V_15 = V_4 -> V_15 ;
if ( F_23 ( V_29 , V_32 ) < 0 )
return - V_64 ;
V_17 = V_32 -> V_37 ;
if ( V_29 -> V_48 == V_71 )
V_17 = 16 ;
switch ( V_32 -> V_50 ) {
case 0 :
case 180 :
V_113 = V_117 ;
V_114 = V_15 -> V_118 ;
V_115 = V_119 ;
V_116 = V_15 -> V_120 ;
if ( F_25 () ) {
V_32 -> V_46 = V_15 -> V_118 ;
V_32 -> V_47 = V_15 -> V_120 ;
}
break;
case 90 :
case 270 :
V_113 = V_119 ;
V_114 = V_15 -> V_120 ;
V_115 = V_117 ;
V_116 = V_15 -> V_118 ;
if ( F_25 () ) {
V_32 -> V_46 = V_15 -> V_120 ;
V_32 -> V_47 = V_15 -> V_118 ;
}
break;
default:
return - V_64 ;
}
if ( V_32 -> V_46 < V_113 )
V_32 -> V_46 = V_113 ;
if ( V_32 -> V_47 < V_115 )
V_32 -> V_47 = V_115 ;
if ( V_32 -> V_46 > V_114 )
V_32 -> V_46 = V_114 ;
if ( V_32 -> V_47 > V_116 )
V_32 -> V_47 = V_116 ;
if ( V_32 -> V_43 < V_32 -> V_46 )
V_32 -> V_43 = V_32 -> V_46 ;
if ( V_32 -> V_121 < V_32 -> V_47 )
V_32 -> V_121 = V_32 -> V_47 ;
V_111 = V_4 -> V_9 . V_10 [ V_29 -> V_40 ] . V_11 ;
V_112 = V_32 -> V_43 * V_17 / 8 ;
if ( V_112 * V_32 -> V_121 > V_111 ) {
V_112 = V_111 / V_32 -> V_121 ;
V_32 -> V_43 = V_112 * 8 / V_17 ;
if ( V_32 -> V_43 < V_32 -> V_46 ) {
V_32 -> V_43 = V_32 -> V_46 ;
V_112 = V_32 -> V_46 * V_17 / 8 ;
V_32 -> V_121 = V_111 / V_112 ;
}
if ( V_32 -> V_43 < V_32 -> V_46 )
V_32 -> V_46 = V_32 -> V_43 ;
if ( V_32 -> V_121 < V_32 -> V_47 )
V_32 -> V_47 = V_32 -> V_121 ;
if ( V_32 -> V_46 < V_113 || V_32 -> V_47 < V_115 )
return - V_64 ;
}
if ( V_32 -> V_46 + V_32 -> V_36 > V_32 -> V_43 )
V_32 -> V_36 = V_32 -> V_43 - V_32 -> V_46 ;
if ( V_32 -> V_47 + V_32 -> V_33 > V_32 -> V_121 )
V_32 -> V_33 = V_32 -> V_121 - V_32 -> V_47 ;
if ( V_29 -> V_48 == V_71 ) {
V_32 -> V_56 . V_27 = 8 ; V_32 -> V_56 . V_73 = 4 ;
V_32 -> V_56 . V_122 = 0 ;
V_32 -> V_57 . V_27 = 4 ; V_32 -> V_57 . V_73 = 4 ;
V_32 -> V_57 . V_122 = 0 ;
V_32 -> V_58 . V_27 = 0 ; V_32 -> V_58 . V_73 = 4 ;
V_32 -> V_58 . V_122 = 0 ;
} else {
V_32 -> V_56 . V_27 = 11 ; V_32 -> V_56 . V_73 = 5 ;
V_32 -> V_56 . V_122 = 0 ;
V_32 -> V_57 . V_27 = 5 ; V_32 -> V_57 . V_73 = 6 ;
V_32 -> V_57 . V_122 = 0 ;
V_32 -> V_58 . V_27 = 0 ; V_32 -> V_58 . V_73 = 5 ;
V_32 -> V_58 . V_122 = 0 ;
}
V_32 -> V_123 = - 1 ;
V_32 -> V_124 = - 1 ;
V_32 -> V_125 = 0 ;
V_32 -> V_126 = 10000000 / ( V_15 -> V_127 / 100 ) ;
V_32 -> V_128 = V_15 -> V_129 ;
V_32 -> V_130 = V_15 -> V_131 ;
V_32 -> V_132 = V_15 -> V_133 ;
V_32 -> V_134 = V_15 -> V_135 ;
V_32 -> V_136 = V_15 -> V_137 ;
V_32 -> V_138 = V_15 -> V_139 ;
V_32 -> V_140 = V_141 ;
V_32 -> V_38 = 0 ;
return 0 ;
}
static int F_26 ( struct V_31 * V_32 ,
struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
if ( V_32 -> V_36 != V_26 -> V_32 . V_36 ||
V_32 -> V_33 != V_26 -> V_32 . V_33 ) {
struct V_31 * V_142 = & V_4 -> V_142 ;
memcpy ( V_142 , & V_26 -> V_32 , sizeof( * V_142 ) ) ;
V_142 -> V_36 = V_32 -> V_36 ;
V_142 -> V_33 = V_32 -> V_33 ;
if ( F_24 ( V_26 , V_142 ) )
V_6 = - V_64 ;
else {
memcpy ( & V_26 -> V_32 , V_142 , sizeof( * V_142 ) ) ;
F_12 ( V_26 ) ;
}
}
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_27 ( struct V_25 * V_26 , int V_143 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
V_143 = V_143 ? 1 : 0 ;
if ( F_25 () )
V_6 = - V_64 ;
else if ( V_143 != V_29 -> V_41 . V_143 ) {
V_29 -> V_41 . V_143 = V_143 ;
V_6 = F_12 ( V_26 ) ;
}
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_28 ( struct V_31 * V_32 , struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
int V_6 ;
F_2 ( V_4 ) ;
if ( V_4 -> V_20 -> V_38 != NULL )
V_4 -> V_20 -> V_38 () ;
V_6 = F_24 ( V_26 , V_32 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_29 ( struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
int V_6 = 0 ;
F_2 ( V_4 ) ;
F_22 ( V_26 , 0 ) ;
V_6 = F_12 ( V_26 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
int F_30 ( struct V_25 * V_26 ,
struct V_144 * V_145 ,
void (* F_31)( void * ) ,
void * V_146 )
{
int V_46 , V_47 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_31 * V_32 = & V_26 -> V_32 ;
switch ( V_32 -> V_50 ) {
case 0 :
case 180 :
V_46 = V_4 -> V_15 -> V_118 ;
V_47 = V_4 -> V_15 -> V_120 ;
break;
case 90 :
case 270 :
V_46 = V_4 -> V_15 -> V_120 ;
V_47 = V_4 -> V_15 -> V_118 ;
break;
default:
return - V_64 ;
}
if ( V_145 -> V_147 >= V_46 || V_145 -> V_148 >= V_47 ||
V_145 -> V_149 > V_46 || V_145 -> V_150 > V_47 )
return - V_64 ;
if ( ! V_4 -> V_20 -> V_151 ||
V_4 -> V_20 -> V_91 () != V_92 )
return - V_152 ;
if ( V_145 -> V_147 + V_145 -> V_124 > V_46 )
V_145 -> V_124 = V_46 - V_145 -> V_147 ;
if ( V_145 -> V_148 + V_145 -> V_123 > V_47 )
V_145 -> V_123 = V_47 - V_145 -> V_148 ;
if ( V_145 -> V_149 + V_145 -> V_52 > V_46 )
V_145 -> V_52 = V_46 - V_145 -> V_149 ;
if ( V_145 -> V_150 + V_145 -> V_53 > V_47 )
V_145 -> V_53 = V_47 - V_145 -> V_150 ;
if ( ! V_145 -> V_124 || ! V_145 -> V_123 || ! V_145 -> V_52 || ! V_145 -> V_53 )
return 0 ;
return V_4 -> V_20 -> V_151 ( V_26 , V_145 , F_31 , V_146 ) ;
}
static int F_32 ( struct V_25 * V_26 ,
struct V_144 * V_145 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
int V_153 ;
F_2 ( V_29 -> V_4 ) ;
V_153 = F_30 ( V_26 , V_145 , NULL , NULL ) ;
F_4 ( V_29 -> V_4 ) ;
return V_153 ;
}
static int F_21 ( struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_144 V_145 ;
int V_6 ;
if ( ! V_4 -> V_20 -> V_151 ||
V_4 -> V_20 -> V_91 () != V_92 )
return - V_152 ;
V_145 . V_147 = 0 ;
V_145 . V_148 = 0 ;
V_145 . V_124 = V_26 -> V_32 . V_46 ;
V_145 . V_123 = V_26 -> V_32 . V_47 ;
V_145 . V_149 = 0 ;
V_145 . V_150 = 0 ;
V_145 . V_52 = V_26 -> V_32 . V_46 ;
V_145 . V_53 = V_26 -> V_32 . V_47 ;
V_145 . V_154 = 0 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_20 -> V_151 ( V_26 , & V_145 , NULL , NULL ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_33 ( struct V_25 * V_26 , struct V_155 * V_156 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_14 * V_15 = V_4 -> V_15 ;
struct V_155 V_157 ;
int V_6 = 0 ;
if ( V_156 -> V_44 + V_156 -> V_52 > V_15 -> V_118 ||
V_156 -> V_45 + V_156 -> V_53 > V_15 -> V_120 )
return - V_64 ;
F_2 ( V_4 ) ;
if ( V_156 -> V_158 && ! V_4 -> V_9 . V_10 [ V_29 -> V_40 ] . V_11 ) {
V_6 = - V_64 ;
goto V_159;
}
V_157 = V_29 -> V_41 ;
V_29 -> V_41 = * V_156 ;
if ( V_156 -> V_158 ) {
V_6 = F_12 ( V_26 ) ;
if ( V_6 < 0 ) {
V_29 -> V_41 = V_157 ;
goto V_159;
}
}
V_6 = V_4 -> V_20 -> V_160 ( V_29 -> V_40 , V_156 -> V_158 ) ;
if ( V_6 < 0 ) {
V_29 -> V_41 = V_157 ;
goto V_159;
}
V_159:
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_34 ( struct V_25 * V_26 , struct V_155 * V_156 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
* V_156 = V_29 -> V_41 ;
return 0 ;
}
static int F_35 ( struct V_25 * V_26 , struct V_161 * V_162 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_98 * V_99 = & V_4 -> V_9 . V_10 [ V_29 -> V_40 ] ;
T_3 V_11 ;
int V_6 = 0 ;
if ( V_4 -> V_20 -> V_163 == NULL )
return - V_152 ;
if ( V_162 -> type != V_164 )
return - V_64 ;
V_11 = F_7 ( V_162 -> V_11 ) ;
F_2 ( V_4 ) ;
if ( V_29 -> V_41 . V_158 ) {
V_6 = - V_165 ;
goto V_159;
}
if ( V_99 -> V_11 != V_11 || V_99 -> type != V_162 -> type ) {
struct V_31 * V_142 = & V_4 -> V_142 ;
unsigned long V_166 = V_99 -> V_11 ;
T_4 V_167 = V_99 -> type ;
unsigned long V_22 ;
V_99 -> V_11 = V_11 ;
V_99 -> type = V_162 -> type ;
if ( V_166 != V_11 && V_11 ) {
if ( V_11 ) {
memcpy ( V_142 , & V_26 -> V_32 , sizeof( * V_142 ) ) ;
V_6 = F_24 ( V_26 , V_142 ) ;
if ( V_6 < 0 )
goto V_159;
}
}
if ( V_4 -> V_20 -> V_38 )
V_4 -> V_20 -> V_38 () ;
V_6 = V_4 -> V_20 -> V_163 ( V_29 -> V_40 , V_11 , V_162 -> type , & V_22 ) ;
if ( V_6 < 0 ) {
V_99 -> V_11 = V_166 ;
V_99 -> type = V_167 ;
goto V_159;
}
V_99 -> V_22 = V_22 ;
if ( V_166 != V_11 ) {
if ( V_11 ) {
memcpy ( & V_26 -> V_32 , V_142 , sizeof( V_26 -> V_32 ) ) ;
F_22 ( V_26 , 0 ) ;
} else {
F_3 ( & V_26 -> V_101 ) ;
V_26 -> V_34 . V_102 = 0 ;
V_26 -> V_34 . V_103 = 0 ;
F_5 ( & V_26 -> V_101 ) ;
}
}
}
V_159:
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_36 ( struct V_25 * V_26 , struct V_161 * V_162 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_98 * V_99 ;
V_99 = & V_4 -> V_9 . V_10 [ V_29 -> V_40 ] ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
V_162 -> V_11 = V_99 -> V_11 ;
V_162 -> type = V_99 -> type ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_168 * V_169 )
{
int V_6 ;
if ( ! V_4 -> V_20 -> V_170 )
return - V_152 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_20 -> V_170 ( V_169 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_168 * V_169 )
{
int V_6 ;
if ( ! V_4 -> V_20 -> V_171 )
return - V_152 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_20 -> V_171 ( V_169 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static void F_39 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_172 ; V_7 ++ )
F_40 ( & V_173 [ V_7 ] ) ;
}
int F_41 ( struct V_174 * V_175 ,
T_5 F_31 ,
void * V_146 )
{
int V_6 ;
if ( ( unsigned ) V_175 -> V_176 > V_172 )
return - V_64 ;
if ( ! V_177 ) {
F_39 () ;
V_177 = 1 ;
}
V_175 -> V_178 . V_179 = ( int (*) (struct V_180 * ,
unsigned long , void * ) ) F_31 ;
V_175 -> V_181 = V_146 ;
V_6 = F_42 (
& V_173 [ V_175 -> V_176 ] ,
& V_175 -> V_178 ) ;
if ( V_6 )
return V_6 ;
if ( V_182 != NULL &&
V_182 -> V_20 && V_182 -> V_20 -> V_183 ) {
V_182 -> V_20 -> V_183 ( V_175 ) ;
}
return 0 ;
}
int F_43 ( struct V_174 * V_175 )
{
return F_44 (
& V_173 [ V_175 -> V_176 ] , & V_175 -> V_178 ) ;
}
void F_45 ( struct V_3 * V_4 , unsigned long V_184 )
{
int V_7 ;
if ( ! V_177 )
return;
for ( V_7 = 0 ; V_7 < V_172 ; V_7 ++ )
F_46 ( & V_173 [ V_7 ] , V_184 ,
V_4 -> V_25 [ V_7 ] ) ;
}
static int F_47 ( struct V_3 * V_4 ,
enum V_185 V_186 )
{
int V_6 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_20 -> V_187 ( V_186 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static enum V_185 F_48 ( struct V_3 * V_4 )
{
int V_6 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_20 -> V_91 () ;
F_4 ( V_4 ) ;
return V_6 ;
}
static void F_49 ( struct V_3 * V_4 , int V_29 ,
struct V_188 * V_189 )
{
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
V_4 -> V_20 -> V_190 ( V_29 , V_189 ) ;
V_189 -> V_20 |= V_4 -> V_15 -> V_190 ( V_4 -> V_15 ) ;
}
void F_50 ( struct V_3 * V_4 , T_2 V_191 )
{
F_2 ( V_4 ) ;
* ( T_2 * ) V_4 -> V_9 . V_10 [ 0 ] . V_23 = V_191 ;
if ( V_4 -> V_20 -> V_91 () == V_92 ) {
struct V_144 V_145 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_124 = 2 ;
V_145 . V_123 = 2 ;
V_145 . V_52 = 2 ;
V_145 . V_53 = 2 ;
V_4 -> V_20 -> V_151 ( V_4 -> V_25 [ 0 ] , & V_145 , NULL , NULL ) ;
}
F_4 ( V_4 ) ;
}
static int F_51 ( struct V_25 * V_26 , unsigned int V_192 ,
unsigned long V_193 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_194 * V_195 = V_26 -> V_196 ;
union {
struct V_144 V_151 ;
struct V_155 V_197 ;
struct V_161 V_198 ;
struct V_168 V_199 ;
enum V_185 V_200 ;
struct V_188 V_189 ;
unsigned int V_143 ;
int V_201 ;
int V_160 ;
} V_202 ;
int V_6 = 0 ;
F_52 ( ! V_195 ) ;
switch ( V_192 ) {
case V_203 :
if ( F_53 ( V_202 . V_143 , ( int V_204 * ) V_193 ) )
V_6 = - V_205 ;
else
F_27 ( V_26 , V_202 . V_143 ) ;
break;
case V_206 :
F_15 ( V_26 ) ;
break;
case V_207 :
break;
case V_208 :
if ( F_53 ( V_202 . V_200 , ( int V_204 * ) V_193 ) )
V_6 = - V_205 ;
else
V_6 = F_47 ( V_4 , V_202 . V_200 ) ;
break;
case V_209 :
V_202 . V_200 = F_48 ( V_4 ) ;
if ( F_54 ( V_202 . V_200 ,
(enum V_185 V_204 * ) V_193 ) )
V_6 = - V_205 ;
break;
case V_210 :
if ( F_55 ( & V_202 . V_151 , ( void V_204 * ) V_193 ,
sizeof( struct V_211 ) ) )
V_6 = - V_205 ;
else {
struct V_144 * V_212 = & V_202 . V_151 ;
V_212 -> V_149 = V_212 -> V_147 ;
V_212 -> V_150 = V_212 -> V_148 ;
V_212 -> V_52 = V_212 -> V_124 ;
V_212 -> V_53 = V_212 -> V_123 ;
memset ( V_212 -> V_213 , 0 , sizeof( V_212 -> V_213 ) ) ;
V_6 = F_32 ( V_26 , V_212 ) ;
}
break;
case V_214 :
if ( F_55 ( & V_202 . V_151 , ( void V_204 * ) V_193 ,
sizeof( V_202 . V_151 ) ) )
V_6 = - V_205 ;
else
V_6 = F_32 ( V_26 , & V_202 . V_151 ) ;
break;
case V_215 :
if ( F_55 ( & V_202 . V_197 , ( void V_204 * ) V_193 ,
sizeof( V_202 . V_197 ) ) )
V_6 = - V_205 ;
else
V_6 = F_33 ( V_26 , & V_202 . V_197 ) ;
break;
case V_216 :
if ( ( V_6 = F_34 ( V_26 , & V_202 . V_197 ) ) < 0 )
break;
if ( F_56 ( ( void V_204 * ) V_193 , & V_202 . V_197 ,
sizeof( V_202 . V_197 ) ) )
V_6 = - V_205 ;
break;
case V_217 :
if ( F_55 ( & V_202 . V_198 , ( void V_204 * ) V_193 ,
sizeof( V_202 . V_198 ) ) )
V_6 = - V_205 ;
else
V_6 = F_35 ( V_26 , & V_202 . V_198 ) ;
break;
case V_218 :
if ( ( V_6 = F_36 ( V_26 , & V_202 . V_198 ) ) < 0 )
break;
if ( F_56 ( ( void V_204 * ) V_193 , & V_202 . V_198 ,
sizeof( V_202 . V_198 ) ) )
V_6 = - V_205 ;
break;
case V_219 :
if ( F_55 ( & V_202 . V_199 , ( void V_204 * ) V_193 ,
sizeof( V_202 . V_199 ) ) )
V_6 = - V_205 ;
else
V_6 = F_37 ( V_4 , & V_202 . V_199 ) ;
break;
case V_220 :
if ( ( V_6 = F_38 ( V_4 , & V_202 . V_199 ) ) < 0 )
break;
if ( F_56 ( ( void V_204 * ) V_193 , & V_202 . V_199 ,
sizeof( V_202 . V_199 ) ) )
V_6 = - V_205 ;
break;
case V_221 :
F_49 ( V_4 , V_29 -> V_40 , & V_202 . V_189 ) ;
if ( F_56 ( ( void V_204 * ) V_193 , & V_202 . V_189 , sizeof( V_202 . V_189 ) ) )
V_6 = - V_205 ;
break;
case V_222 :
{
int V_223 ;
if ( F_53 ( V_223 , ( int V_204 * ) V_193 ) ) {
V_6 = - V_205 ;
break;
}
if ( ! V_4 -> V_15 -> V_224 ) {
V_6 = - V_64 ;
break;
}
V_6 = V_4 -> V_15 -> V_224 ( V_4 -> V_15 , V_223 ) ;
break;
}
case V_225 :
{
int V_223 ;
if ( F_53 ( V_223 , ( int V_204 * ) V_193 ) ) {
V_6 = - V_205 ;
break;
}
if ( ! V_4 -> V_20 -> V_224 ) {
V_6 = - V_64 ;
break;
}
V_6 = V_4 -> V_20 -> V_224 ( V_223 ) ;
break;
}
default:
V_6 = - V_64 ;
}
return V_6 ;
}
static int F_57 ( struct V_25 * V_41 , struct V_226 * V_227 )
{
struct V_28 * V_29 = V_41 -> V_30 ;
struct V_3 * V_4 = V_29 -> V_4 ;
int V_6 ;
F_2 ( V_4 ) ;
V_6 = V_4 -> V_20 -> V_228 ( V_41 , V_227 ) ;
F_4 ( V_4 ) ;
return V_6 ;
}
static T_6 F_58 ( struct V_1 * V_2 ,
struct V_229 * V_230 , char * V_231 )
{
struct V_3 * V_4 = F_59 ( V_2 ) ;
int V_29 ;
T_3 V_11 ;
struct V_188 V_189 ;
V_29 = 0 ;
V_11 = 0 ;
while ( V_11 < V_232 && V_29 < V_172 ) {
F_49 ( V_4 , V_29 , & V_189 ) ;
V_11 += snprintf ( & V_231 [ V_11 ] , V_232 - V_11 ,
L_3 ,
V_29 , V_189 . V_20 , V_189 . V_233 , V_189 . V_234 ) ;
V_29 ++ ;
}
return V_11 ;
}
static T_6 F_60 ( struct V_1 * V_2 ,
struct V_229 * V_230 , char * V_231 )
{
struct V_3 * V_4 = F_59 ( V_2 ) ;
int V_7 ;
struct V_188 V_189 ;
int V_29 ;
T_3 V_11 ;
V_29 = 0 ;
V_11 = 0 ;
while ( V_11 < V_232 && V_29 < V_172 ) {
F_49 ( V_4 , V_29 , & V_189 ) ;
V_11 += snprintf ( & V_231 [ V_11 ] , V_232 - V_11 ,
L_4 , V_29 ) ;
for ( V_7 = 0 ; V_7 < F_61 ( V_235 ) &&
V_11 < V_232 ; V_7 ++ ) {
if ( V_235 [ V_7 ] . V_236 & V_189 . V_20 )
V_11 += snprintf ( & V_231 [ V_11 ] , V_232 - V_11 ,
L_5 , V_235 [ V_7 ] . V_237 ) ;
}
V_11 += snprintf ( & V_231 [ V_11 ] , V_232 - V_11 ,
L_6 ) ;
for ( V_7 = 0 ; V_7 < F_61 ( V_238 ) &&
V_11 < V_232 ; V_7 ++ ) {
if ( V_238 [ V_7 ] . V_236 & V_189 . V_233 )
V_11 += snprintf ( & V_231 [ V_11 ] , V_232 - V_11 ,
L_7 , V_238 [ V_7 ] . V_237 ) ;
}
V_11 += snprintf ( & V_231 [ V_11 ] , V_232 - V_11 ,
L_8 ) ;
for ( V_7 = 0 ; V_7 < F_61 ( V_238 ) &&
V_11 < V_232 ; V_7 ++ ) {
if ( V_238 [ V_7 ] . V_236 & V_189 . V_234 )
V_11 += snprintf ( & V_231 [ V_11 ] , V_232 - V_11 ,
L_7 , V_238 [ V_7 ] . V_237 ) ;
}
V_29 ++ ;
}
return V_11 ;
}
static T_6 F_62 ( struct V_1 * V_2 ,
struct V_229 * V_230 , char * V_231 )
{
struct V_3 * V_4 = F_59 ( V_2 ) ;
return snprintf ( V_231 , V_232 , L_9 , V_4 -> V_15 -> V_237 ) ;
}
static T_6 F_63 ( struct V_1 * V_2 ,
struct V_229 * V_230 ,
char * V_231 )
{
struct V_3 * V_4 = F_59 ( V_2 ) ;
int V_6 ;
if ( V_4 -> V_15 -> V_239 ) {
V_6 = snprintf ( V_231 , V_232 , L_10 ,
V_4 -> V_15 -> V_239 ( V_4 -> V_15 ) ) ;
} else
V_6 = - V_152 ;
return V_6 ;
}
static T_6 F_64 ( struct V_1 * V_2 ,
struct V_229 * V_230 ,
const char * V_231 , T_3 V_11 )
{
struct V_3 * V_4 = F_59 ( V_2 ) ;
int V_6 ;
if ( V_4 -> V_15 -> V_240 ) {
unsigned int V_241 ;
if ( sscanf ( V_231 , L_11 , & V_241 ) == 1 ) {
V_6 = V_4 -> V_15 -> V_240 ( V_4 -> V_15 ,
V_241 ) ;
} else
V_6 = - V_64 ;
} else
V_6 = - V_152 ;
return V_6 ? V_6 : V_11 ;
}
static T_6 F_65 ( struct V_1 * V_2 ,
struct V_229 * V_230 , char * V_231 )
{
struct V_3 * V_4 = F_59 ( V_2 ) ;
int V_6 ;
if ( V_4 -> V_15 -> V_239 ) {
V_6 = snprintf ( V_231 , V_232 , L_10 ,
V_4 -> V_15 -> V_242 ( V_4 -> V_15 ) ) ;
} else
V_6 = - V_152 ;
return V_6 ;
}
static T_6 F_66 ( struct V_1 * V_2 ,
struct V_229 * V_230 , char * V_231 )
{
struct V_3 * V_4 = F_59 ( V_2 ) ;
return snprintf ( V_231 , V_232 , L_9 , V_4 -> V_20 -> V_237 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
int V_6 ;
if ( ( V_6 = F_68 ( V_4 -> V_2 , & V_243 ) ) )
goto V_244;
if ( ( V_6 = F_68 ( V_4 -> V_2 , & V_245 ) ) )
goto V_246;
if ( ( V_6 = F_69 ( & V_4 -> V_2 -> V_247 , & V_248 ) ) )
goto V_249;
if ( ( V_6 = F_69 ( & V_4 -> V_2 -> V_247 , & V_250 ) ) )
goto V_251;
return 0 ;
V_251:
F_70 ( & V_4 -> V_2 -> V_247 , & V_248 ) ;
V_249:
F_71 ( V_4 -> V_2 , & V_245 ) ;
V_246:
F_71 ( V_4 -> V_2 , & V_243 ) ;
V_244:
F_8 ( V_4 -> V_2 , L_12 ) ;
return V_6 ;
}
static void F_72 ( struct V_3 * V_4 )
{
F_70 ( & V_4 -> V_2 -> V_247 , & V_250 ) ;
F_70 ( & V_4 -> V_2 -> V_247 , & V_248 ) ;
F_71 ( V_4 -> V_2 , & V_243 ) ;
F_71 ( V_4 -> V_2 , & V_245 ) ;
}
static int F_73 ( struct V_3 * V_4 , struct V_25 * V_41 )
{
struct V_31 * V_32 = & V_41 -> V_32 ;
struct V_97 * V_34 = & V_41 -> V_34 ;
int V_6 = 0 ;
V_41 -> V_196 = & V_252 ;
V_41 -> V_253 = V_254 ;
strncpy ( V_34 -> V_255 , V_256 , sizeof( V_34 -> V_255 ) ) ;
V_41 -> V_75 = V_4 -> V_75 ;
V_32 -> V_257 = V_258 ? V_259 : 0 ;
V_32 -> V_46 = V_18 ;
V_32 -> V_47 = V_19 ;
V_32 -> V_43 = V_18 ;
V_32 -> V_121 = V_19 ;
V_32 -> V_50 = V_260 ;
V_32 -> V_37 = V_4 -> V_15 -> V_17 ;
F_24 ( V_41 , V_32 ) ;
F_22 ( V_41 , 1 ) ;
V_6 = F_74 ( & V_41 -> V_77 , 16 , 0 ) ;
if ( V_6 != 0 )
F_8 ( V_4 -> V_2 , L_13 ) ;
return V_6 ;
}
static void F_75 ( struct V_3 * V_4 , struct V_25 * V_26 )
{
F_76 ( & V_26 -> V_77 ) ;
}
static void F_77 ( struct V_3 * V_4 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
if ( V_4 -> V_25 [ V_7 ] == NULL )
break;
F_75 ( V_4 , V_4 -> V_25 [ V_7 ] ) ;
F_78 ( V_4 -> V_25 [ V_7 ] ) ;
}
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_25 * V_26 ;
int V_7 ;
int V_6 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
struct V_28 * V_29 ;
V_26 = F_80 ( sizeof( struct V_28 ) ,
V_4 -> V_2 ) ;
if ( V_26 == NULL ) {
F_8 ( V_4 -> V_2 ,
L_14 ) ;
F_77 ( V_4 ) ;
return - V_261 ;
}
V_29 = V_26 -> V_30 ;
V_29 -> V_40 = V_7 ;
V_29 -> V_4 = V_4 ;
V_29 -> V_41 . V_143 = V_262 ;
V_4 -> V_25 [ V_7 ] = V_26 ;
if ( ( V_6 = F_73 ( V_4 , V_26 ) ) < 0 ) {
F_78 ( V_26 ) ;
F_77 ( V_4 ) ;
return V_6 ;
}
V_29 -> V_41 . V_52 = V_26 -> V_32 . V_46 ;
V_29 -> V_41 . V_53 = V_26 -> V_32 . V_47 ;
}
return 0 ;
}
static void F_81 ( struct V_3 * V_4 , int V_86 )
{
int V_7 ;
switch ( V_86 ) {
case V_90 :
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ )
F_82 ( V_4 -> V_25 [ V_7 ] ) ;
case 7 :
F_72 ( V_4 ) ;
case 6 :
V_4 -> V_15 -> V_94 ( V_4 -> V_15 ) ;
case 5 :
F_47 ( V_4 , V_263 ) ;
case 4 :
F_77 ( V_4 ) ;
case 3 :
F_11 ( V_4 ) ;
case 2 :
V_4 -> V_15 -> V_24 ( V_4 -> V_15 ) ;
case 1 :
F_83 ( V_4 -> V_2 , NULL ) ;
F_84 ( V_4 ) ;
case 0 :
break;
default:
F_17 () ;
}
}
static int F_85 ( struct V_3 * V_4 )
{
struct V_264 * V_265 ;
char V_237 [ 17 ] ;
int V_7 ;
V_265 = F_86 ( V_4 -> V_2 ) ;
V_4 -> V_20 = NULL ;
strncpy ( V_237 , V_265 -> V_266 . V_267 , sizeof( V_237 ) - 1 ) ;
V_237 [ sizeof( V_237 ) - 1 ] = '\0' ;
if ( strcmp ( V_237 , L_15 ) == 0 ) {
V_4 -> V_20 = V_4 -> V_268 ;
return 0 ;
}
for ( V_7 = 0 ; V_7 < F_61 ( V_269 ) ; V_7 ++ ) {
F_10 ( V_4 -> V_2 , L_16 , V_269 [ V_7 ] -> V_237 ) ;
if ( strcmp ( V_269 [ V_7 ] -> V_237 , V_237 ) == 0 ) {
V_4 -> V_20 = V_269 [ V_7 ] ;
break;
}
}
if ( V_4 -> V_20 == NULL ) {
F_10 ( V_4 -> V_2 , L_17 , V_237 ) ;
return - 1 ;
}
return 0 ;
}
static void F_87 ( struct V_3 * V_4 )
{
#define F_88 ( V_147 ) (fbdev->ctrl->x != NULL)
#define F_89 ( V_147 ) (fbdev->panel->x != NULL)
F_52 ( V_4 -> V_20 == NULL || V_4 -> V_15 == NULL ) ;
F_52 ( ! ( F_88 ( V_21 ) && F_88 ( V_24 ) && F_88 ( V_190 ) &&
F_88 ( V_187 ) && F_88 ( V_39 ) && F_88 ( V_160 ) &&
F_89 ( V_21 ) && F_89 ( V_24 ) && F_89 ( V_89 ) && F_89 ( V_94 ) &&
F_89 ( V_190 ) ) ) ;
#undef F_89
#undef F_88
}
static int F_90 ( struct V_270 * V_271 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = NULL ;
int V_272 ;
unsigned long V_273 , V_274 , V_275 ;
unsigned long V_276 ;
int V_7 ;
int V_6 = 0 ;
V_272 = 0 ;
if ( V_271 -> V_277 != 0 ) {
F_8 ( & V_271 -> V_2 , L_18 ) ;
V_6 = - V_152 ;
goto V_24;
}
if ( F_86 ( & V_271 -> V_2 ) == NULL ) {
F_8 ( & V_271 -> V_2 , L_19 ) ;
V_6 = - V_278 ;
goto V_24;
}
V_4 = F_91 ( sizeof( struct V_3 ) , V_279 ) ;
if ( V_4 == NULL ) {
F_8 ( & V_271 -> V_2 ,
L_20 ) ;
V_6 = - V_261 ;
goto V_24;
}
V_272 ++ ;
V_4 -> V_2 = & V_271 -> V_2 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_280 = & V_281 ;
F_92 ( V_271 , V_4 ) ;
F_93 ( & V_4 -> V_5 ) ;
V_4 -> V_268 = & V_282 ;
#ifdef F_94
V_4 -> V_283 = & V_284 ;
#endif
if ( F_85 ( V_4 ) < 0 ) {
F_8 ( V_4 -> V_2 ,
L_21 ) ;
V_6 = - V_152 ;
goto V_24;
}
V_6 = V_4 -> V_15 -> V_21 ( V_4 -> V_15 , V_4 ) ;
if ( V_6 )
goto V_24;
F_95 ( L_22 , V_4 -> V_15 -> V_237 ) ;
V_18 = V_18 ? V_18 : V_4 -> V_15 -> V_118 ;
V_19 = V_19 ? V_19 : V_4 -> V_15 -> V_120 ;
V_272 ++ ;
V_6 = F_6 ( V_4 ) ;
if ( V_6 )
goto V_24;
if ( V_4 -> V_20 -> V_228 != NULL )
V_252 . V_285 = F_57 ;
V_272 ++ ;
F_87 ( V_4 ) ;
V_6 = F_79 ( V_4 ) ;
if ( V_6 )
goto V_24;
V_272 ++ ;
#ifdef F_96
F_97 ( 0 , V_286 , 15 ) ;
#endif
V_6 = F_12 ( V_4 -> V_25 [ 0 ] ) ;
if ( V_6 ) {
F_8 ( V_4 -> V_2 , L_23 ) ;
goto V_24;
}
V_6 = V_4 -> V_20 -> V_160 ( V_287 , 1 ) ;
if ( V_6 )
goto V_24;
F_47 ( V_4 , V_288 ?
V_92 : V_289 ) ;
V_272 ++ ;
V_6 = V_4 -> V_15 -> V_89 ( V_4 -> V_15 ) ;
if ( V_6 )
goto V_24;
V_272 ++ ;
V_6 = F_67 ( V_4 ) ;
if ( V_6 )
goto V_24;
V_272 ++ ;
V_276 = 0 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 . V_13 ; V_7 ++ ) {
V_6 = F_98 ( V_4 -> V_25 [ V_7 ] ) ;
if ( V_6 != 0 ) {
F_8 ( V_4 -> V_2 ,
L_24 , V_7 ) ;
goto V_24;
}
V_276 += V_4 -> V_9 . V_10 [ V_7 ] . V_11 ;
}
V_4 -> V_86 = V_90 ;
V_15 = V_4 -> V_15 ;
V_273 = V_15 -> V_127 * 1000 ;
V_274 = V_273 * 10 / ( V_15 -> V_129 + V_15 -> V_118 + V_15 -> V_131 + V_15 -> V_137 ) ;
V_275 = V_274 / ( V_15 -> V_133 + V_15 -> V_120 + V_15 -> V_135 + V_15 -> V_139 ) ;
V_182 = V_4 ;
F_95 ( L_25 ,
V_276 , V_4 -> V_9 . V_13 ) ;
F_95 ( L_26
L_27 ,
V_273 / 1000 , V_274 / 10000 , V_274 % 10 , V_275 / 10 , V_275 % 10 ) ;
return 0 ;
V_24:
F_81 ( V_4 , V_272 ) ;
return V_6 ;
}
static int F_99 ( struct V_270 * V_271 )
{
int V_6 ;
F_52 ( V_290 != NULL ) ;
V_6 = F_100 ( & V_281 ) ;
if ( V_6 ) {
F_8 ( & V_271 -> V_2 , L_28 ) ;
return V_6 ;
}
V_290 = V_271 ;
if ( V_291 != NULL )
F_90 ( V_290 , V_291 ) ;
return 0 ;
}
void F_101 ( struct V_14 * V_15 )
{
F_52 ( V_291 != NULL ) ;
V_291 = V_15 ;
if ( V_290 != NULL )
F_90 ( V_290 , V_291 ) ;
}
static int F_102 ( struct V_270 * V_271 )
{
struct V_3 * V_4 = F_103 ( V_271 ) ;
enum V_292 V_293 = V_4 -> V_86 ;
V_4 -> V_86 = V_294 ;
F_81 ( V_4 , V_293 ) ;
F_104 ( & V_281 ) ;
V_4 -> V_280 = NULL ;
return 0 ;
}
static int F_105 ( struct V_270 * V_271 , T_7 V_295 )
{
struct V_3 * V_4 = F_103 ( V_271 ) ;
if ( V_4 != NULL )
F_20 ( V_93 , V_4 -> V_25 [ 0 ] ) ;
return 0 ;
}
static int F_106 ( struct V_270 * V_271 )
{
struct V_3 * V_4 = F_103 ( V_271 ) ;
if ( V_4 != NULL )
F_20 ( V_85 , V_4 -> V_25 [ 0 ] ) ;
return 0 ;
}
static int T_8 F_107 ( char * V_296 )
{
char * V_297 = NULL ;
int V_6 = 0 ;
F_108 ( L_29 , V_296 ) ;
if ( ! V_296 || ! * V_296 )
return 0 ;
while ( ! V_6 && ( V_297 = F_109 ( & V_296 , L_30 ) ) != NULL ) {
if ( ! strncmp ( V_297 , L_31 , 5 ) )
V_258 = 1 ;
else if ( ! strncmp ( V_297 , L_32 , 5 ) ) {
char * V_298 ;
unsigned long V_276 ;
V_276 = ( F_110 ( V_297 + 5 , & V_298 , 0 ) ) ;
switch ( V_298 [ 0 ] ) {
case '\0' :
break;
case 'm' :
case 'M' :
V_276 *= 1024 ;
case 'k' :
case 'K' :
V_276 *= 1024 ;
break;
default:
F_108 ( L_33 ,
V_298 [ 0 ] ) ;
V_6 = - 1 ;
}
V_12 [ V_8 ++ ] = V_276 ;
}
else if ( ! strncmp ( V_297 , L_34 , 6 ) )
V_18 = F_110 ( V_297 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_297 , L_35 , 6 ) )
V_19 = F_110 ( V_297 + 6 , NULL , 0 ) ;
else if ( ! strncmp ( V_297 , L_36 , 7 ) )
V_260 = ( F_110 ( V_297 + 7 , NULL , 0 ) ) ;
else if ( ! strncmp ( V_297 , L_37 , 7 ) )
V_262 = ( F_110 ( V_297 + 7 , NULL , 0 ) ) ;
else if ( ! strncmp ( V_297 , L_38 , 13 ) )
V_288 = 1 ;
else {
F_108 ( L_39 ) ;
V_6 = - 1 ;
}
}
return V_6 ;
}
static int T_8 F_111 ( void )
{
#ifndef F_112
char * V_299 ;
if ( F_113 ( L_40 , & V_299 ) )
return - V_152 ;
F_107 ( V_299 ) ;
#endif
if ( F_114 ( & V_300 ) ) {
F_108 ( L_41 ) ;
return - V_152 ;
}
return 0 ;
}
static void T_9 F_115 ( void )
{
F_116 ( & V_300 ) ;
}
