void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_5 ) ;
}
int F_8 ( struct V_8 * V_9 ,
T_1 * V_10 , T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct {
T_1 V_15 ;
T_2 V_16 ;
} * V_15 ;
T_1 V_17 = V_11 * V_12 * 4 ;
T_1 V_18 = sizeof( * V_15 ) + V_17 ;
if ( ! V_10 )
return - V_19 ;
V_15 = F_9 ( V_9 , V_18 ) ;
if ( F_10 ( V_15 == NULL ) ) {
F_11 ( L_1 ) ;
return - V_20 ;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
memcpy ( & V_15 [ 1 ] , V_10 , V_17 ) ;
V_15 -> V_15 = V_21 ;
V_15 -> V_16 . V_22 = 0 ;
V_15 -> V_16 . V_11 = V_11 ;
V_15 -> V_16 . V_12 = V_12 ;
V_15 -> V_16 . V_13 = V_13 ;
V_15 -> V_16 . V_14 = V_14 ;
F_12 ( V_9 , V_18 ) ;
return 0 ;
}
int F_13 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct V_25 V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
void * V_29 ;
bool V_30 ;
int V_31 ;
V_27 = 0 ;
V_28 = ( V_11 * V_12 * 4 + V_32 - 1 ) >> V_33 ;
V_31 = F_14 ( & V_24 -> V_34 , true , false , false , NULL ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_2 ) ;
return - V_19 ;
}
V_31 = F_15 ( & V_24 -> V_34 , V_27 , V_28 , & V_26 ) ;
if ( F_10 ( V_31 != 0 ) )
goto V_35;
V_29 = F_16 ( & V_26 , & V_30 ) ;
V_31 = F_8 ( V_9 , V_29 , V_11 , V_12 ,
V_13 , V_14 ) ;
F_17 ( & V_26 ) ;
V_35:
F_18 ( & V_24 -> V_34 ) ;
return V_31 ;
}
void F_19 ( struct V_8 * V_9 ,
bool V_36 , int V_37 , int V_38 )
{
T_1 T_3 * V_39 = V_9 -> V_40 ;
T_4 V_41 ;
F_20 ( V_36 ? 1 : 0 , V_39 + V_42 ) ;
F_20 ( V_37 , V_39 + V_43 ) ;
F_20 ( V_38 , V_39 + V_44 ) ;
V_41 = F_21 ( V_39 + V_45 ) ;
F_20 ( ++ V_41 , V_39 + V_45 ) ;
}
int F_22 ( struct V_46 * V_6 , struct V_47 * V_48 ,
T_4 V_49 , T_4 V_11 , T_4 V_12 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_50 ) ;
struct V_1 * V_2 = F_24 ( V_6 ) ;
struct V_51 * V_52 = NULL ;
struct V_23 * V_24 = NULL ;
int V_31 ;
F_25 ( V_6 ) ;
F_26 ( V_9 -> V_50 ) ;
if ( V_49 && ( V_11 != 64 || V_12 != 64 ) ) {
V_31 = - V_19 ;
goto V_53;
}
if ( V_49 ) {
struct V_54 * V_55 = F_27 ( V_48 ) -> V_55 ;
V_31 = F_28 ( V_9 , V_55 ,
V_49 , & V_52 , & V_24 ) ;
if ( V_31 ) {
F_11 ( L_3 , V_31 ) ;
V_31 = - V_19 ;
goto V_53;
}
}
if ( V_52 && ! V_52 -> V_56 . V_10 ) {
F_11 ( L_4 ) ;
F_2 ( & V_52 ) ;
V_31 = - V_19 ;
goto V_53;
}
if ( V_2 -> V_3 ) {
V_2 -> V_3 -> V_56 . V_6 = NULL ;
F_2 ( & V_2 -> V_3 ) ;
}
if ( V_2 -> V_4 )
F_3 ( & V_2 -> V_4 ) ;
if ( V_52 ) {
V_2 -> V_3 = V_52 ;
V_2 -> V_3 -> V_56 . V_6 = V_6 ;
V_2 -> V_57 = V_2 -> V_3 -> V_56 . V_58 ;
F_8 ( V_9 , V_52 -> V_56 . V_10 ,
64 , 64 , V_2 -> V_59 , V_2 -> V_60 ) ;
} else if ( V_24 ) {
V_2 -> V_4 = V_24 ;
V_31 = F_13 ( V_9 , V_24 , V_11 , V_12 ,
V_2 -> V_59 , V_2 -> V_60 ) ;
} else {
F_19 ( V_9 , false , 0 , 0 ) ;
V_31 = 0 ;
goto V_53;
}
F_19 ( V_9 , true ,
V_2 -> V_61 + V_2 -> V_59 ,
V_2 -> V_62 + V_2 -> V_60 ) ;
V_31 = 0 ;
V_53:
F_29 ( V_9 -> V_50 ) ;
F_30 ( V_6 , V_6 -> V_16 ) ;
return V_31 ;
}
int F_31 ( struct V_46 * V_6 , int V_37 , int V_38 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_50 ) ;
struct V_1 * V_2 = F_24 ( V_6 ) ;
bool V_63 = V_2 -> V_3 || V_2 -> V_4 ? true : false ;
V_2 -> V_61 = V_37 + V_6 -> V_37 ;
V_2 -> V_62 = V_38 + V_6 -> V_38 ;
F_25 ( V_6 ) ;
F_26 ( V_9 -> V_50 ) ;
F_19 ( V_9 , V_63 ,
V_2 -> V_61 + V_2 -> V_59 ,
V_2 -> V_62 + V_2 -> V_60 ) ;
F_29 ( V_9 -> V_50 ) ;
F_30 ( V_6 , V_6 -> V_16 ) ;
return 0 ;
}
void F_32 ( struct V_51 * V_64 ,
struct V_54 * V_55 ,
struct V_65 * V_66 ,
T_5 * V_67 )
{
struct V_25 V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
T_6 * V_68 ;
unsigned V_69 ;
void * V_29 ;
bool V_30 ;
struct V_70 {
T_5 V_67 ;
T_7 V_71 ;
} * V_15 ;
int V_72 , V_31 ;
V_15 = F_33 ( V_67 , struct V_70 , V_67 ) ;
if ( ! V_64 -> V_56 . V_10 )
return;
if ( V_15 -> V_71 . V_73 . V_74 != 0 || V_15 -> V_71 . V_73 . V_75 != 0 ) {
F_11 ( L_5 ) ;
return;
}
if ( V_15 -> V_67 . V_76 < 64 ) {
F_11 ( L_6 ) ;
return;
}
V_68 = ( T_6 * ) & V_15 [ 1 ] ;
V_69 = ( V_15 -> V_67 . V_76 - sizeof( T_7 ) ) /
sizeof( T_6 ) ;
if ( V_15 -> V_71 . V_77 . V_78 . V_79 % V_32 ||
V_68 -> V_37 != 0 || V_68 -> V_38 != 0 || V_68 -> V_80 != 0 ||
V_68 -> V_81 != 0 || V_68 -> V_82 != 0 || V_68 -> V_83 != 0 ||
V_68 -> V_84 != 1 || V_69 != 1 ) {
F_11 ( L_7 ) ;
F_11 ( L_8 ,
V_68 -> V_81 , V_68 -> V_82 , V_68 -> V_83 ,
V_68 -> V_37 , V_68 -> V_38 , V_68 -> V_80 ,
V_68 -> V_85 , V_68 -> V_86 , V_68 -> V_84 , V_69 ,
V_15 -> V_71 . V_77 . V_78 . V_79 ) ;
return;
}
V_27 = V_15 -> V_71 . V_77 . V_78 . V_79 >> V_33 ;
V_28 = ( 64 * 64 * 4 ) >> V_33 ;
V_31 = F_14 ( V_66 , true , false , false , NULL ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_2 ) ;
return;
}
V_31 = F_15 ( V_66 , V_27 , V_28 , & V_26 ) ;
if ( F_10 ( V_31 != 0 ) )
goto V_35;
V_29 = F_16 ( & V_26 , & V_30 ) ;
if ( V_68 -> V_85 == 64 && V_15 -> V_71 . V_77 . V_87 == 64 * 4 ) {
memcpy ( V_64 -> V_56 . V_10 , V_29 , 64 * 64 * 4 ) ;
} else {
for ( V_72 = 0 ; V_72 < V_68 -> V_86 ; V_72 ++ )
memcpy ( V_64 -> V_56 . V_10 + V_72 * 64 ,
V_29 + V_72 * V_15 -> V_71 . V_77 . V_87 ,
V_68 -> V_85 * 4 ) ;
}
V_64 -> V_56 . V_58 ++ ;
F_17 ( & V_26 ) ;
V_35:
F_18 ( V_66 ) ;
}
void F_34 ( struct V_8 * V_9 )
{
struct V_88 * V_50 = V_9 -> V_50 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
F_35 ( & V_50 -> V_89 . V_90 ) ;
F_36 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_24 ( V_6 ) ;
if ( ! V_2 -> V_3 ||
V_2 -> V_57 == V_2 -> V_3 -> V_56 . V_58 )
continue;
V_2 -> V_57 = V_2 -> V_3 -> V_56 . V_58 ;
F_8 ( V_9 ,
V_2 -> V_3 -> V_56 . V_10 ,
64 , 64 , V_2 -> V_59 , V_2 -> V_60 ) ;
}
F_37 ( & V_50 -> V_89 . V_90 ) ;
}
static void F_38 ( struct V_91 * V_92 )
{
struct V_93 * V_94 =
F_39 ( V_92 ) ;
F_40 ( V_92 ) ;
F_2 ( & V_94 -> V_52 ) ;
if ( V_94 -> V_34 . V_95 )
F_41 ( & V_94 -> V_34 . V_95 ) ;
F_42 ( V_94 ) ;
}
static int F_43 ( struct V_91 * V_92 ,
struct V_47 * V_48 ,
unsigned V_96 , unsigned V_97 ,
struct V_98 * V_99 ,
unsigned V_100 )
{
struct V_8 * V_9 = F_23 ( V_92 -> V_50 ) ;
struct V_93 * V_94 =
F_39 ( V_92 ) ;
struct V_98 V_101 ;
int V_31 , V_102 = 1 ;
if ( V_9 -> V_103 == V_104 )
return - V_19 ;
F_26 ( V_9 -> V_50 ) ;
V_31 = F_44 ( & V_9 -> V_105 , true ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_29 ( V_9 -> V_50 ) ;
return V_31 ;
}
if ( ! V_100 ) {
V_100 = 1 ;
V_99 = & V_101 ;
V_101 . V_106 = V_101 . y1 = 0 ;
V_101 . V_107 = V_92 -> V_11 ;
V_101 . V_108 = V_92 -> V_12 ;
} else if ( V_96 & V_109 ) {
V_100 /= 2 ;
V_102 = 2 ;
}
if ( V_9 -> V_103 == V_110 )
V_31 = F_45 ( V_9 , & V_94 -> V_34 ,
V_99 , NULL , NULL , 0 , 0 ,
V_100 , V_102 , NULL ) ;
else
V_31 = F_46 ( V_9 , & V_94 -> V_34 ,
V_99 , NULL , NULL , 0 , 0 ,
V_100 , V_102 , NULL ) ;
F_47 ( V_9 , false ) ;
F_48 ( & V_9 -> V_105 ) ;
F_29 ( V_9 -> V_50 ) ;
return 0 ;
}
int F_49 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_111 * V_112 ,
struct V_113 T_8 * V_114 ,
struct V_115 * V_116 ,
T_4 V_100 )
{
switch ( V_9 -> V_103 ) {
case V_110 :
return F_50 ( V_9 , V_48 , V_112 ,
V_114 , V_116 , V_100 ) ;
case V_117 :
return F_51 ( V_9 , V_48 , V_112 ,
V_114 , NULL , V_116 , V_100 ,
1 , false , true ) ;
default:
F_52 ( true ,
L_9 ) ;
}
return - V_118 ;
}
static int F_53 ( struct V_8 * V_9 ,
struct V_51 * V_52 ,
struct V_111 * * V_53 ,
const struct V_119
* V_120 ,
bool V_121 )
{
struct V_88 * V_50 = V_9 -> V_50 ;
struct V_93 * V_94 ;
enum V_122 V_123 ;
int V_31 ;
if ( V_9 -> V_103 == V_104 )
return - V_118 ;
if ( F_10 ( ! V_52 -> V_124 ) )
return - V_19 ;
if ( F_10 ( V_52 -> V_125 [ 0 ] != 1 ||
V_52 -> V_126 != 1 ||
V_52 -> V_127 . V_11 < V_120 -> V_11 ||
V_52 -> V_127 . V_12 < V_120 -> V_12 ||
V_52 -> V_127 . V_128 != 1 ) ) {
F_11 ( L_10
L_11 ) ;
return - V_19 ;
}
switch ( V_120 -> V_128 ) {
case 32 :
V_123 = V_129 ;
break;
case 24 :
V_123 = V_130 ;
break;
case 16 :
V_123 = V_131 ;
break;
case 15 :
V_123 = V_132 ;
break;
default:
F_11 ( L_12 , V_120 -> V_128 ) ;
return - V_19 ;
}
if ( ! V_9 -> V_133 && V_123 != V_52 -> V_123 ) {
F_11 ( L_13 ) ;
return - V_19 ;
}
V_94 = F_54 ( sizeof( * V_94 ) , V_134 ) ;
if ( ! V_94 ) {
V_31 = - V_20 ;
goto V_135;
}
V_94 -> V_34 . V_34 . V_136 = V_120 -> V_137 ;
V_94 -> V_34 . V_34 . V_138 [ 0 ] = V_120 -> V_87 ;
V_94 -> V_34 . V_34 . V_128 = V_120 -> V_128 ;
V_94 -> V_34 . V_34 . V_11 = V_120 -> V_11 ;
V_94 -> V_34 . V_34 . V_12 = V_120 -> V_12 ;
V_94 -> V_52 = F_55 ( V_52 ) ;
V_94 -> V_34 . V_139 = V_120 -> V_49 ;
V_94 -> V_121 = V_121 ;
* V_53 = & V_94 -> V_34 ;
V_31 = F_56 ( V_50 , & V_94 -> V_34 . V_34 ,
& V_140 ) ;
if ( V_31 )
goto V_141;
return 0 ;
V_141:
F_2 ( & V_52 ) ;
F_42 ( V_94 ) ;
V_135:
return V_31 ;
}
static void F_57 ( struct V_91 * V_92 )
{
struct V_142 * V_143 =
F_58 ( V_92 ) ;
F_40 ( V_92 ) ;
F_3 ( & V_143 -> V_144 ) ;
if ( V_143 -> V_34 . V_95 )
F_41 ( & V_143 -> V_34 . V_95 ) ;
F_42 ( V_143 ) ;
}
static int F_59 ( struct V_91 * V_92 ,
struct V_47 * V_48 ,
unsigned V_96 , unsigned V_97 ,
struct V_98 * V_99 ,
unsigned V_100 )
{
struct V_8 * V_9 = F_23 ( V_92 -> V_50 ) ;
struct V_142 * V_143 =
F_58 ( V_92 ) ;
struct V_98 V_101 ;
int V_31 , V_145 = 1 ;
F_26 ( V_9 -> V_50 ) ;
V_31 = F_44 ( & V_9 -> V_105 , true ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_29 ( V_9 -> V_50 ) ;
return V_31 ;
}
if ( ! V_100 ) {
V_100 = 1 ;
V_99 = & V_101 ;
V_101 . V_106 = V_101 . y1 = 0 ;
V_101 . V_107 = V_92 -> V_11 ;
V_101 . V_108 = V_92 -> V_12 ;
} else if ( V_96 & V_109 ) {
V_100 /= 2 ;
V_145 = 2 ;
}
switch ( V_9 -> V_103 ) {
case V_117 :
V_31 = F_51 ( V_9 , NULL , & V_143 -> V_34 , NULL ,
V_99 , NULL , V_100 , V_145 ,
true , true ) ;
break;
case V_110 :
V_31 = F_60 ( V_9 , & V_143 -> V_34 ,
V_99 , V_100 , V_145 ,
true ,
NULL ) ;
break;
case V_104 :
V_31 = F_61 ( V_9 , & V_143 -> V_34 , 0 , 0 ,
V_99 , V_100 , V_145 ) ;
break;
default:
V_31 = - V_19 ;
F_52 ( true , L_14 ) ;
break;
}
F_47 ( V_9 , false ) ;
F_48 ( & V_9 -> V_105 ) ;
F_29 ( V_9 -> V_50 ) ;
return V_31 ;
}
static int F_62 ( struct V_111 * V_112 )
{
struct V_8 * V_9 = F_23 ( V_112 -> V_34 . V_50 ) ;
struct V_23 * V_146 ;
int V_31 ;
V_146 = V_112 -> V_24 ? F_58 ( & V_112 -> V_34 ) -> V_144 :
F_39 ( & V_112 -> V_34 ) -> V_52 -> V_147 . V_148 ;
if ( ! V_146 )
return 0 ;
switch ( V_9 -> V_103 ) {
case V_104 :
F_63 ( V_9 ) ;
V_31 = F_64 ( V_9 , V_146 , false ) ;
F_65 ( V_9 ) ;
break;
case V_110 :
case V_117 :
if ( V_112 -> V_24 )
return F_66 ( V_9 , V_146 ,
false ) ;
return F_67 ( V_9 , V_146 ,
& V_149 , false ) ;
default:
return - V_19 ;
}
return V_31 ;
}
static int F_68 ( struct V_111 * V_112 )
{
struct V_8 * V_9 = F_23 ( V_112 -> V_34 . V_50 ) ;
struct V_23 * V_146 ;
V_146 = V_112 -> V_24 ? F_58 ( & V_112 -> V_34 ) -> V_144 :
F_39 ( & V_112 -> V_34 ) -> V_52 -> V_147 . V_148 ;
if ( F_69 ( ! V_146 ) )
return 0 ;
return F_70 ( V_9 , V_146 , false ) ;
}
static int F_71 ( struct V_88 * V_50 ,
const struct V_119 * V_120 ,
struct V_23 * V_150 ,
struct V_51 * * V_151 )
{
T_4 V_123 ;
struct V_152 V_153 ;
struct V_154 * V_147 ;
int V_31 ;
switch ( V_120 -> V_128 ) {
case 32 :
case 24 :
V_123 = V_130 ;
break;
case 16 :
case 15 :
V_123 = V_131 ;
break;
case 8 :
V_123 = V_155 ;
break;
default:
F_11 ( L_15 , V_120 -> V_128 ) ;
return - V_19 ;
}
V_153 . V_11 = V_120 -> V_11 ;
V_153 . V_12 = V_120 -> V_12 ;
V_153 . V_128 = 1 ;
V_31 = F_72 ( V_50 ,
0 ,
0 ,
V_123 ,
true ,
1 ,
0 ,
0 ,
V_153 ,
V_151 ) ;
if ( V_31 ) {
F_11 ( L_16 ) ;
return V_31 ;
}
V_147 = & ( * V_151 ) -> V_147 ;
F_35 ( & V_147 -> V_9 -> V_156 ) ;
( void ) F_73 ( V_147 , false , true ) ;
F_3 ( & V_147 -> V_148 ) ;
V_147 -> V_148 = F_74 ( V_150 ) ;
V_147 -> V_157 = 0 ;
F_75 ( V_147 , false , NULL , 0 ) ;
F_37 ( & V_147 -> V_9 -> V_156 ) ;
return 0 ;
}
static int F_76 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_111 * * V_53 ,
const struct V_119
* V_120 )
{
struct V_88 * V_50 = V_9 -> V_50 ;
struct V_142 * V_143 ;
unsigned int V_158 ;
int V_31 ;
V_158 = V_120 -> V_12 * V_120 -> V_87 ;
if ( F_10 ( V_158 > V_24 -> V_34 . V_159 * V_32 ) ) {
F_11 ( L_17
L_11 ) ;
return - V_19 ;
}
if ( V_9 -> V_103 == V_110 ) {
switch ( V_120 -> V_128 ) {
case 32 :
case 24 :
if ( V_120 -> V_137 == 32 )
break;
F_11 ( L_18 ,
V_120 -> V_128 , V_120 -> V_137 ) ;
return - V_19 ;
case 16 :
case 15 :
if ( V_120 -> V_137 == 16 )
break;
F_11 ( L_18 ,
V_120 -> V_128 , V_120 -> V_137 ) ;
return - V_19 ;
default:
F_11 ( L_12 , V_120 -> V_128 ) ;
return - V_19 ;
}
}
V_143 = F_54 ( sizeof( * V_143 ) , V_134 ) ;
if ( ! V_143 ) {
V_31 = - V_20 ;
goto V_135;
}
V_143 -> V_34 . V_34 . V_136 = V_120 -> V_137 ;
V_143 -> V_34 . V_34 . V_138 [ 0 ] = V_120 -> V_87 ;
V_143 -> V_34 . V_34 . V_128 = V_120 -> V_128 ;
V_143 -> V_34 . V_34 . V_11 = V_120 -> V_11 ;
V_143 -> V_34 . V_34 . V_12 = V_120 -> V_12 ;
V_143 -> V_34 . V_24 = true ;
V_143 -> V_144 = F_74 ( V_24 ) ;
V_143 -> V_34 . V_139 = V_120 -> V_49 ;
* V_53 = & V_143 -> V_34 ;
V_31 = F_56 ( V_50 , & V_143 -> V_34 . V_34 ,
& V_160 ) ;
if ( V_31 )
goto V_141;
return 0 ;
V_141:
F_3 ( & V_24 ) ;
F_42 ( V_143 ) ;
V_135:
return V_31 ;
}
struct V_111 *
F_77 ( struct V_8 * V_9 ,
struct V_23 * V_24 ,
struct V_51 * V_52 ,
bool V_161 ,
const struct V_119 * V_120 )
{
struct V_111 * V_112 = NULL ;
bool V_121 = false ;
int V_31 ;
if ( V_24 && V_161 &&
V_9 -> V_103 == V_117 ) {
V_31 = F_71 ( V_9 -> V_50 , V_120 ,
V_24 , & V_52 ) ;
if ( V_31 )
return F_78 ( V_31 ) ;
V_121 = true ;
}
if ( V_52 ) {
V_31 = F_53 ( V_9 , V_52 , & V_112 ,
V_120 ,
V_121 ) ;
if ( V_121 )
F_2 ( & V_52 ) ;
} else if ( V_24 ) {
V_31 = F_76 ( V_9 , V_24 , & V_112 ,
V_120 ) ;
} else {
F_79 () ;
}
if ( V_31 )
return F_78 ( V_31 ) ;
V_112 -> V_162 = F_62 ;
V_112 -> V_163 = F_68 ;
return V_112 ;
}
static struct V_91 * F_80 ( struct V_88 * V_50 ,
struct V_47 * V_48 ,
struct V_164 * V_165 )
{
struct V_8 * V_9 = F_23 ( V_50 ) ;
struct V_54 * V_55 = F_27 ( V_48 ) -> V_55 ;
struct V_111 * V_112 = NULL ;
struct V_51 * V_52 = NULL ;
struct V_23 * V_66 = NULL ;
struct V_166 * V_95 ;
struct V_119 V_120 ;
int V_31 ;
V_120 . V_11 = V_165 -> V_11 ;
V_120 . V_12 = V_165 -> V_12 ;
V_120 . V_87 = V_165 -> V_138 [ 0 ] ;
V_120 . V_49 = V_165 -> V_167 [ 0 ] ;
F_81 ( V_165 -> V_168 , & V_120 . V_128 ,
& V_120 . V_137 ) ;
if ( ! F_82 ( V_9 ,
V_120 . V_87 ,
V_120 . V_12 ) ) {
F_11 ( L_19 ) ;
return F_78 ( - V_20 ) ;
}
V_95 = F_83 ( V_55 , V_120 . V_49 ) ;
if ( F_10 ( V_95 == NULL ) ) {
F_11 ( L_20 ) ;
return F_78 ( - V_169 ) ;
}
V_31 = F_28 ( V_9 , V_55 ,
V_120 . V_49 ,
& V_52 , & V_66 ) ;
if ( V_31 )
goto V_170;
V_112 = F_77 ( V_9 , V_66 , V_52 ,
! ( V_9 -> V_171 & V_172 ) ,
& V_120 ) ;
if ( F_84 ( V_112 ) ) {
V_31 = F_85 ( V_112 ) ;
goto V_170;
}
V_170:
if ( V_66 )
F_3 ( & V_66 ) ;
if ( V_52 )
F_2 ( & V_52 ) ;
if ( V_31 ) {
F_11 ( L_21 , V_31 ) ;
F_41 ( & V_95 ) ;
return F_78 ( V_31 ) ;
} else
V_112 -> V_95 = V_95 ;
return & V_112 -> V_34 ;
}
static int F_86 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_111 * V_112 ,
struct V_51 * V_52 ,
T_4 V_173 ,
T_9 V_174 , T_9 V_175 ,
struct V_115 * V_99 ,
T_4 V_100 )
{
return F_45 ( V_9 , V_112 , NULL , V_99 ,
& V_52 -> V_147 , V_174 , V_175 ,
V_100 , 1 , NULL ) ;
}
int F_87 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_111 * V_112 ,
struct V_51 * V_52 ,
T_4 V_173 ,
T_9 V_174 , T_9 V_175 ,
struct V_115 * V_99 ,
T_4 V_100 )
{
int V_31 ;
switch ( V_9 -> V_103 ) {
case V_117 :
V_31 = F_46 ( V_9 , V_112 , NULL , V_99 ,
& V_52 -> V_147 , V_174 , V_175 ,
V_100 , 1 , NULL ) ;
break;
case V_110 :
V_31 = F_86 ( V_9 , V_48 , V_112 , V_52 ,
V_173 , V_174 , V_175 , V_99 ,
V_100 ) ;
break;
default:
F_52 ( true ,
L_22 ) ;
V_31 = - V_118 ;
break;
}
if ( V_31 )
return V_31 ;
F_47 ( V_9 , false ) ;
return 0 ;
}
int F_88 ( struct V_8 * V_9 )
{
struct V_88 * V_50 = V_9 -> V_50 ;
int V_31 ;
F_89 ( V_50 ) ;
V_50 -> V_89 . V_176 = & V_177 ;
V_50 -> V_89 . V_178 = 1 ;
V_50 -> V_89 . V_179 = 1 ;
V_50 -> V_89 . V_180 = V_9 -> V_181 ;
V_50 -> V_89 . V_182 = V_9 -> V_183 ;
V_31 = F_90 ( V_9 ) ;
if ( V_31 ) {
V_31 = F_91 ( V_9 ) ;
if ( V_31 )
V_31 = F_92 ( V_9 ) ;
}
return V_31 ;
}
int F_93 ( struct V_8 * V_9 )
{
int V_31 ;
F_94 ( V_9 -> V_50 ) ;
if ( V_9 -> V_103 == V_110 )
V_31 = F_95 ( V_9 ) ;
else if ( V_9 -> V_103 == V_117 )
V_31 = F_96 ( V_9 ) ;
else
V_31 = F_97 ( V_9 ) ;
return V_31 ;
}
int F_98 ( struct V_88 * V_50 , void * V_184 ,
struct V_47 * V_48 )
{
struct V_185 * V_186 = V_184 ;
struct V_1 * V_2 ;
struct V_46 * V_6 ;
int V_31 = 0 ;
F_35 ( & V_50 -> V_89 . V_90 ) ;
if ( V_186 -> V_96 & V_187 ) {
F_36 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_24 ( V_6 ) ;
V_2 -> V_59 = V_186 -> V_188 ;
V_2 -> V_60 = V_186 -> V_189 ;
}
F_37 ( & V_50 -> V_89 . V_90 ) ;
return 0 ;
}
V_6 = F_99 ( V_50 , V_186 -> V_190 ) ;
if ( ! V_6 ) {
V_31 = - V_169 ;
goto V_53;
}
V_2 = F_24 ( V_6 ) ;
V_2 -> V_59 = V_186 -> V_188 ;
V_2 -> V_60 = V_186 -> V_189 ;
V_53:
F_37 ( & V_50 -> V_89 . V_90 ) ;
return V_31 ;
}
int F_100 ( struct V_8 * F_23 ,
unsigned V_11 , unsigned V_12 , unsigned V_87 ,
unsigned V_137 , unsigned V_128 )
{
if ( F_23 -> V_171 & V_191 )
F_101 ( F_23 , V_192 , V_87 ) ;
else if ( F_102 ( F_23 ) )
F_20 ( V_87 , F_23 -> V_40 + V_193 ) ;
F_101 ( F_23 , V_194 , V_11 ) ;
F_101 ( F_23 , V_195 , V_12 ) ;
F_101 ( F_23 , V_196 , V_137 ) ;
if ( F_103 ( F_23 , V_197 ) != V_128 ) {
F_11 ( L_23 ,
V_128 , V_137 , F_103 ( F_23 , V_197 ) ) ;
return - V_19 ;
}
return 0 ;
}
int F_104 ( struct V_8 * F_23 )
{
struct V_198 * V_199 ;
T_4 V_72 ;
F_23 -> V_200 = F_103 ( F_23 , V_194 ) ;
F_23 -> V_201 = F_103 ( F_23 , V_195 ) ;
F_23 -> V_202 = F_103 ( F_23 , V_196 ) ;
if ( F_23 -> V_171 & V_191 )
F_23 -> V_203 =
F_103 ( F_23 , V_192 ) ;
else if ( F_102 ( F_23 ) )
F_23 -> V_203 = F_21 ( F_23 -> V_40 +
V_193 ) ;
if ( ! ( F_23 -> V_171 & V_204 ) )
return 0 ;
F_23 -> V_205 = F_103 ( F_23 ,
V_206 ) ;
if ( F_23 -> V_205 == 0 )
F_23 -> V_205 = 1 ;
for ( V_72 = 0 ; V_72 < F_23 -> V_205 ; ++ V_72 ) {
V_199 = & F_23 -> V_207 [ V_72 ] ;
F_101 ( F_23 , V_208 , V_72 ) ;
V_199 -> V_209 = F_103 ( F_23 , V_210 ) ;
V_199 -> V_211 = F_103 ( F_23 , V_212 ) ;
V_199 -> V_213 = F_103 ( F_23 , V_214 ) ;
V_199 -> V_11 = F_103 ( F_23 , V_215 ) ;
V_199 -> V_12 = F_103 ( F_23 , V_216 ) ;
F_101 ( F_23 , V_208 , V_217 ) ;
if ( V_72 == 0 && F_23 -> V_205 == 1 &&
V_199 -> V_11 == 0 && V_199 -> V_12 == 0 ) {
V_199 -> V_11 = F_23 -> V_200 - V_199 -> V_211 ;
V_199 -> V_12 = F_23 -> V_201 - V_199 -> V_213 ;
}
}
return 0 ;
}
int F_105 ( struct V_8 * F_23 )
{
struct V_198 * V_199 ;
T_4 V_72 ;
F_101 ( F_23 , V_194 , F_23 -> V_200 ) ;
F_101 ( F_23 , V_195 , F_23 -> V_201 ) ;
F_101 ( F_23 , V_196 , F_23 -> V_202 ) ;
if ( F_23 -> V_171 & V_191 )
F_101 ( F_23 , V_192 ,
F_23 -> V_203 ) ;
else if ( F_102 ( F_23 ) )
F_20 ( F_23 -> V_203 ,
F_23 -> V_40 + V_193 ) ;
if ( ! ( F_23 -> V_171 & V_204 ) )
return 0 ;
for ( V_72 = 0 ; V_72 < F_23 -> V_205 ; ++ V_72 ) {
V_199 = & F_23 -> V_207 [ V_72 ] ;
F_101 ( F_23 , V_208 , V_72 ) ;
F_101 ( F_23 , V_210 , V_199 -> V_209 ) ;
F_101 ( F_23 , V_212 , V_199 -> V_211 ) ;
F_101 ( F_23 , V_214 , V_199 -> V_213 ) ;
F_101 ( F_23 , V_215 , V_199 -> V_11 ) ;
F_101 ( F_23 , V_216 , V_199 -> V_12 ) ;
F_101 ( F_23 , V_208 , V_217 ) ;
}
return 0 ;
}
bool F_82 ( struct V_8 * V_9 ,
T_4 V_87 ,
T_4 V_12 )
{
return ( ( V_218 ) V_87 * ( V_218 ) V_12 ) < ( V_218 )
( ( V_9 -> V_103 == V_117 ) ?
V_9 -> V_219 : V_9 -> V_220 ) ;
}
T_1 F_106 ( struct V_88 * V_50 , int V_6 )
{
return 0 ;
}
int F_107 ( struct V_88 * V_50 , int V_6 )
{
return - V_118 ;
}
void F_108 ( struct V_88 * V_50 , int V_6 )
{
}
static int F_109 ( struct V_8 * V_9 , unsigned V_221 ,
struct V_115 * V_222 )
{
struct V_88 * V_50 = V_9 -> V_50 ;
struct V_1 * V_2 ;
struct V_223 * V_224 ;
F_35 ( & V_50 -> V_89 . V_90 ) ;
#if 0
{
unsigned int i;
DRM_INFO("%s: new layout ", __func__);
for (i = 0; i < num; i++)
DRM_INFO("(%i, %i %ux%u) ", rects[i].x, rects[i].y,
rects[i].w, rects[i].h);
DRM_INFO("\n");
}
#endif
F_36 (con, &dev->mode_config.connector_list, head) {
V_2 = F_110 ( V_224 ) ;
if ( V_221 > V_2 -> V_225 ) {
V_2 -> V_226 = V_222 [ V_2 -> V_225 ] . V_85 ;
V_2 -> V_227 = V_222 [ V_2 -> V_225 ] . V_86 ;
V_2 -> V_228 = true ;
V_2 -> V_229 = V_222 [ V_2 -> V_225 ] . V_37 ;
V_2 -> V_230 = V_222 [ V_2 -> V_225 ] . V_38 ;
} else {
V_2 -> V_226 = 800 ;
V_2 -> V_227 = 600 ;
V_2 -> V_228 = false ;
}
V_224 -> V_231 = F_111 ( V_224 , true ) ;
}
F_37 ( & V_50 -> V_89 . V_90 ) ;
return 0 ;
}
void F_112 ( struct V_46 * V_6 )
{
}
void F_113 ( struct V_46 * V_6 )
{
}
void F_114 ( struct V_46 * V_6 ,
T_10 * V_232 , T_10 * V_233 , T_10 * V_234 ,
T_4 V_235 , T_4 V_76 )
{
struct V_8 * V_9 = F_23 ( V_6 -> V_50 ) ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_76 ; V_72 ++ ) {
F_115 ( L_24 , V_72 ,
V_232 [ V_72 ] , V_233 [ V_72 ] , V_234 [ V_72 ] ) ;
F_101 ( V_9 , V_236 + V_72 * 3 + 0 , V_232 [ V_72 ] >> 8 ) ;
F_101 ( V_9 , V_236 + V_72 * 3 + 1 , V_233 [ V_72 ] >> 8 ) ;
F_101 ( V_9 , V_236 + V_72 * 3 + 2 , V_234 [ V_72 ] >> 8 ) ;
}
}
int F_116 ( struct V_223 * V_5 , int V_237 )
{
return 0 ;
}
void F_117 ( struct V_223 * V_5 )
{
}
void F_118 ( struct V_223 * V_5 )
{
}
enum V_238
F_111 ( struct V_223 * V_5 , bool V_239 )
{
T_4 V_205 ;
struct V_88 * V_50 = V_5 -> V_50 ;
struct V_8 * V_9 = F_23 ( V_50 ) ;
struct V_1 * V_2 = F_110 ( V_5 ) ;
V_205 = F_103 ( V_9 , V_240 ) ;
return ( ( F_110 ( V_5 ) -> V_225 < V_205 &&
V_2 -> V_228 ) ?
V_241 : V_242 ) ;
}
void F_119 ( struct V_243 * V_237 )
{
V_237 -> V_244 = V_237 -> V_245 + 50 ;
V_237 -> V_246 = V_237 -> V_244 + 50 ;
V_237 -> V_247 = V_237 -> V_246 + 50 ;
V_237 -> V_248 = V_237 -> V_249 + 50 ;
V_237 -> V_250 = V_237 -> V_248 + 50 ;
V_237 -> V_251 = V_237 -> V_250 + 50 ;
V_237 -> clock = ( T_1 ) V_237 -> V_247 * ( T_1 ) V_237 -> V_251 / 100 * 6 ;
V_237 -> V_252 = F_120 ( V_237 ) ;
}
int F_121 ( struct V_223 * V_5 ,
T_4 V_180 , T_4 V_182 )
{
struct V_1 * V_2 = F_110 ( V_5 ) ;
struct V_88 * V_50 = V_5 -> V_50 ;
struct V_8 * V_9 = F_23 ( V_50 ) ;
struct V_243 * V_237 = NULL ;
struct V_243 * V_253 ;
struct V_243 V_254 = { F_122 ( L_25 ,
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
} ;
int V_72 ;
T_1 V_255 = 2 ;
if ( V_9 -> V_103 == V_110 )
V_255 = 4 ;
if ( V_9 -> V_103 == V_117 ) {
V_180 = F_123 ( V_180 , V_9 -> V_256 ) ;
V_182 = F_123 ( V_182 , V_9 -> V_257 ) ;
}
V_237 = F_124 ( V_50 , & V_254 ) ;
if ( ! V_237 )
return 0 ;
V_237 -> V_245 = V_2 -> V_226 ;
V_237 -> V_249 = V_2 -> V_227 ;
F_119 ( V_237 ) ;
if ( F_82 ( V_9 ,
V_237 -> V_245 * V_255 ,
V_237 -> V_249 ) ) {
F_125 ( V_5 , V_237 ) ;
} else {
F_126 ( V_50 , V_237 ) ;
V_237 = NULL ;
}
if ( V_2 -> V_258 ) {
F_127 ( & V_2 -> V_258 -> V_259 ) ;
F_126 ( V_50 , V_2 -> V_258 ) ;
}
V_2 -> V_258 = V_237 ;
for ( V_72 = 0 ; V_260 [ V_72 ] . type != 0 ; V_72 ++ ) {
V_253 = & V_260 [ V_72 ] ;
if ( V_253 -> V_245 > V_180 ||
V_253 -> V_249 > V_182 )
continue;
if ( ! F_82 ( V_9 ,
V_253 -> V_245 * V_255 ,
V_253 -> V_249 ) )
continue;
V_237 = F_124 ( V_50 , V_253 ) ;
if ( ! V_237 )
return 0 ;
V_237 -> V_252 = F_120 ( V_237 ) ;
F_125 ( V_5 , V_237 ) ;
}
F_128 ( V_5 , true ) ;
F_129 ( & V_5 -> V_261 ) ;
return 1 ;
}
int F_130 ( struct V_223 * V_5 ,
struct V_262 * V_263 ,
T_11 V_264 )
{
return 0 ;
}
int F_131 ( struct V_88 * V_50 , void * V_184 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 = F_23 ( V_50 ) ;
struct V_265 * V_186 =
(struct V_265 * ) V_184 ;
void T_8 * V_266 ;
struct V_115 * V_222 ;
unsigned V_267 ;
int V_31 ;
int V_72 ;
V_218 V_268 = 0 ;
struct V_269 * V_89 = & V_50 -> V_89 ;
struct V_115 V_270 = { 0 } ;
if ( ! V_186 -> V_271 ) {
struct V_115 V_272 = { 0 , 0 , 800 , 600 } ;
F_109 ( V_9 , 1 , & V_272 ) ;
return 0 ;
}
V_267 = V_186 -> V_271 * sizeof( struct V_115 ) ;
V_222 = F_132 ( V_186 -> V_271 , sizeof( struct V_115 ) ,
V_134 ) ;
if ( F_10 ( ! V_222 ) )
return - V_20 ;
V_266 = ( void T_8 * ) ( unsigned long ) V_186 -> V_222 ;
V_31 = F_133 ( V_222 , V_266 , V_267 ) ;
if ( F_10 ( V_31 != 0 ) ) {
F_11 ( L_26 ) ;
V_31 = - V_273 ;
goto V_274;
}
for ( V_72 = 0 ; V_72 < V_186 -> V_271 ; ++ V_72 ) {
if ( V_222 [ V_72 ] . V_37 < 0 ||
V_222 [ V_72 ] . V_38 < 0 ||
V_222 [ V_72 ] . V_37 + V_222 [ V_72 ] . V_85 > V_89 -> V_180 ||
V_222 [ V_72 ] . V_38 + V_222 [ V_72 ] . V_86 > V_89 -> V_182 ) {
F_11 ( L_27 ) ;
V_31 = - V_19 ;
goto V_274;
}
if ( V_222 [ V_72 ] . V_37 + V_222 [ V_72 ] . V_85 > V_270 . V_85 )
V_270 . V_85 = V_222 [ V_72 ] . V_37 + V_222 [ V_72 ] . V_85 ;
if ( V_222 [ V_72 ] . V_38 + V_222 [ V_72 ] . V_86 > V_270 . V_86 )
V_270 . V_86 = V_222 [ V_72 ] . V_38 + V_222 [ V_72 ] . V_86 ;
V_268 += ( V_218 ) V_222 [ V_72 ] . V_85 * ( V_218 ) V_222 [ V_72 ] . V_86 ;
}
if ( V_9 -> V_103 == V_117 ) {
V_218 V_275 = V_270 . V_85 * V_270 . V_86 * 4 ;
V_218 V_276 = V_268 * 4 ;
if ( V_275 > V_9 -> V_219 ) {
F_11 ( L_28 ) ;
V_31 = - V_19 ;
goto V_274;
}
if ( V_276 > V_9 -> V_219 ) {
F_11 ( L_29 ) ;
V_31 = - V_19 ;
goto V_274;
}
}
F_109 ( V_9 , V_186 -> V_271 , V_222 ) ;
V_274:
F_42 ( V_222 ) ;
return V_31 ;
}
int F_134 ( struct V_8 * V_9 ,
struct V_111 * V_92 ,
const struct V_98 * V_99 ,
const struct V_115 * V_116 ,
T_12 V_277 , T_12 V_278 ,
int V_100 ,
int V_145 ,
struct V_279 * V_280 )
{
struct V_1 * V_281 [ V_282 ] ;
struct V_46 * V_6 ;
T_1 V_283 = 0 ;
T_1 V_72 , V_284 ;
V_280 -> V_9 = V_9 ;
F_36 (crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if ( V_6 -> V_209 -> V_285 != & V_92 -> V_34 )
continue;
V_281 [ V_283 ++ ] = F_24 ( V_6 ) ;
}
for ( V_284 = 0 ; V_284 < V_283 ; V_284 ++ ) {
struct V_1 * V_225 = V_281 [ V_284 ] ;
T_12 V_286 = V_225 -> V_6 . V_37 ;
T_12 V_287 = V_225 -> V_6 . V_38 ;
T_12 V_288 = V_225 -> V_6 . V_237 . V_245 ;
T_12 V_289 = V_225 -> V_6 . V_237 . V_249 ;
const struct V_98 * V_290 = V_99 ;
const struct V_115 * V_291 = V_116 ;
V_280 -> V_225 = V_225 ;
if ( V_280 -> V_292 > 0 ) {
V_280 -> V_15 = F_9 ( V_9 ,
V_280 -> V_292 ) ;
if ( ! V_280 -> V_15 ) {
F_11 ( L_30
L_31 ) ;
return - V_20 ;
}
memset ( V_280 -> V_15 , 0 , V_280 -> V_292 ) ;
}
V_280 -> V_293 = 0 ;
for ( V_72 = 0 ; V_72 < V_100 ; V_72 ++ , V_290 += V_145 ,
V_291 += V_145 ) {
T_12 V_294 ;
T_12 V_295 ;
if ( V_99 ) {
V_280 -> V_296 = ( T_12 ) V_290 -> V_106 ;
V_280 -> V_297 = ( T_12 ) V_290 -> y1 ;
V_280 -> V_298 = ( T_12 ) V_290 -> V_107 + V_277 -
V_286 ;
V_280 -> V_299 = ( T_12 ) V_290 -> V_108 + V_278 -
V_287 ;
} else {
V_280 -> V_296 = V_291 -> V_37 ;
V_280 -> V_297 = V_291 -> V_38 ;
V_280 -> V_298 = V_280 -> V_296 + V_291 -> V_85 +
V_277 - V_286 ;
V_280 -> V_299 = V_280 -> V_297 + V_291 -> V_86 +
V_278 - V_287 ;
}
V_280 -> V_300 = V_280 -> V_296 + V_277 - V_286 ;
V_280 -> V_301 = V_280 -> V_297 + V_278 - V_287 ;
if ( V_280 -> V_300 >= V_288 ||
V_280 -> V_301 >= V_289 ||
V_280 -> V_298 <= 0 || V_280 -> V_299 <= 0 )
continue;
V_280 -> V_298 = F_135 ( T_12 , V_280 -> V_298 ,
V_288 ) ;
V_280 -> V_299 = F_135 ( T_12 , V_280 -> V_299 ,
V_289 ) ;
V_294 = F_135 ( T_12 , V_280 -> V_300 , 0 ) ;
V_295 = F_135 ( T_12 , V_280 -> V_301 , 0 ) ;
V_280 -> V_300 -= V_294 ;
V_280 -> V_301 -= V_295 ;
V_280 -> V_296 -= V_294 ;
V_280 -> V_297 -= V_295 ;
V_280 -> V_302 ( V_280 ) ;
}
V_280 -> V_303 ( V_280 ) ;
}
return 0 ;
}
int F_136 ( struct V_8 * V_9 ,
struct V_23 * V_146 ,
bool V_304 ,
bool V_305 )
{
struct V_65 * V_66 = & V_146 -> V_34 ;
int V_31 ;
F_14 ( V_66 , false , false , V_304 , NULL ) ;
V_31 = F_137 ( V_9 , V_66 , V_304 ,
V_305 ) ;
if ( V_31 )
F_18 ( V_66 ) ;
return V_31 ;
}
void F_138 ( struct V_23 * V_146 )
{
if ( V_146 )
F_18 ( & V_146 -> V_34 ) ;
}
void F_139 ( struct V_8 * V_9 ,
struct V_47 * V_48 ,
struct V_23 * V_146 ,
struct V_306 * * V_307 ,
struct V_113 T_8 *
V_114 )
{
struct V_306 * V_308 ;
T_4 V_49 ;
int V_31 ;
V_31 = F_140 ( V_48 , V_9 , & V_308 ,
V_48 ? & V_49 : NULL ) ;
if ( V_146 )
F_141 ( & V_146 -> V_34 , V_308 ) ;
if ( V_48 )
F_142 ( V_9 , F_27 ( V_48 ) ,
V_31 , V_114 , V_308 ,
V_49 ) ;
if ( V_307 )
* V_307 = V_308 ;
else
F_143 ( & V_308 ) ;
F_138 ( V_146 ) ;
}
void F_144 ( struct V_154 * V_147 )
{
F_138 ( V_147 -> V_148 ) ;
F_75 ( V_147 , false , NULL , 0 ) ;
F_37 ( & V_147 -> V_9 -> V_156 ) ;
}
int F_145 ( struct V_154 * V_147 ,
bool V_304 )
{
int V_31 = 0 ;
if ( V_304 )
V_31 = F_146 ( & V_147 -> V_9 -> V_156 ) ;
else
F_35 ( & V_147 -> V_9 -> V_156 ) ;
if ( F_10 ( V_31 != 0 ) )
return - V_309 ;
V_31 = F_73 ( V_147 , V_304 , false ) ;
if ( V_31 )
goto V_310;
if ( V_147 -> V_148 ) {
V_31 = F_136 ( V_147 -> V_9 , V_147 -> V_148 ,
V_304 ,
V_147 -> V_9 -> V_311 ) ;
if ( V_31 )
goto V_312;
}
V_31 = F_147 ( V_147 ) ;
if ( V_31 )
goto V_313;
return 0 ;
V_313:
F_138 ( V_147 -> V_148 ) ;
V_312:
F_75 ( V_147 , false , NULL , 0 ) ;
V_310:
F_37 ( & V_147 -> V_9 -> V_156 ) ;
return V_31 ;
}
void F_148 ( struct V_154 * V_147 ,
struct V_306 * * V_307 )
{
if ( V_147 -> V_148 || V_307 )
F_139 ( V_147 -> V_9 , NULL , V_147 -> V_148 ,
V_307 , NULL ) ;
F_75 ( V_147 , false , NULL , 0 ) ;
F_37 ( & V_147 -> V_9 -> V_156 ) ;
}
int F_149 ( struct V_154 * V_147 ,
const struct V_98 * V_99 ,
unsigned V_100 ,
int V_145 )
{
struct V_8 * V_9 = V_147 -> V_9 ;
struct V_152 * V_76 = & F_150 ( V_147 ) -> V_127 ;
struct {
T_5 V_67 ;
T_13 V_314 ;
} * V_15 ;
T_14 * V_68 ;
T_15 V_315 = 0 ;
int V_72 ;
if ( ! V_99 )
return 0 ;
V_15 = F_9 ( V_9 , sizeof( * V_15 ) * V_100 ) ;
if ( ! V_15 ) {
F_11 ( L_32
L_33 ) ;
return - V_20 ;
}
for ( V_72 = 0 ; V_72 < V_100 ; ++ V_72 , V_99 += V_145 , ++ V_15 ) {
V_68 = & V_15 -> V_314 . V_68 ;
V_15 -> V_67 . V_22 = V_316 ;
V_15 -> V_67 . V_76 = sizeof( V_15 -> V_314 ) ;
V_15 -> V_314 . V_10 . V_173 = V_147 -> V_22 ;
V_15 -> V_314 . V_10 . V_74 = 0 ;
V_15 -> V_314 . V_10 . V_75 = 0 ;
if ( V_99 -> V_106 > V_76 -> V_11 || V_99 -> V_107 > V_76 -> V_11 ||
V_99 -> y1 > V_76 -> V_12 || V_99 -> V_108 > V_76 -> V_12 ) {
F_11 ( L_34 ) ;
return - V_19 ;
}
V_68 -> V_37 = V_99 -> V_106 ;
V_68 -> V_38 = V_99 -> y1 ;
V_68 -> V_80 = 0 ;
V_68 -> V_85 = V_99 -> V_107 - V_99 -> V_106 ;
V_68 -> V_86 = V_99 -> V_108 - V_99 -> y1 ;
V_68 -> V_84 = 1 ;
V_315 += sizeof( * V_15 ) ;
}
F_12 ( V_9 , V_315 ) ;
return 0 ;
}
int F_151 ( struct V_8 * V_9 ,
unsigned V_225 ,
T_1 V_180 ,
T_1 V_182 ,
struct V_223 * * V_317 ,
struct V_46 * * V_318 ,
struct V_243 * * V_319 )
{
struct V_223 * V_224 ;
struct V_1 * V_2 ;
struct V_243 * V_237 ;
int V_72 = 0 ;
F_36 (con, &dev_priv->dev->mode_config.connector_list,
head) {
if ( V_72 == V_225 )
break;
++ V_72 ;
}
if ( V_72 != V_225 ) {
F_11 ( L_35 ) ;
return - V_19 ;
}
if ( F_152 ( & V_224 -> V_261 ) )
( void ) F_121 ( V_224 , V_180 , V_182 ) ;
if ( F_152 ( & V_224 -> V_261 ) ) {
F_11 ( L_36 ) ;
return - V_19 ;
}
V_2 = F_110 ( V_224 ) ;
* V_317 = V_224 ;
* V_318 = & V_2 -> V_6 ;
F_36 (mode, &con->modes, head) {
if ( V_237 -> type & V_320 )
break;
}
if ( V_237 -> type & V_320 )
* V_319 = V_237 ;
else {
F_52 ( true , L_37 ) ;
* V_319 = F_153 ( & V_224 -> V_261 ,
struct V_243 ,
V_259 ) ;
}
return 0 ;
}
