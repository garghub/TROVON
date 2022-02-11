static int F_1 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_7 -> V_8 -> type == V_9 )
return 0 ;
return F_2 ( V_3 , V_2 -> V_10 & V_11 ) ;
}
static int F_3 ( T_1 * V_12 )
{
unsigned long V_13 ;
int V_14 ;
F_4 ( & V_15 , V_13 ) ;
V_14 = V_12 -> V_16 ;
F_5 ( & V_15 , V_13 ) ;
return V_14 ;
}
static int F_6 ( T_1 * V_12 , char V_17 )
{
unsigned long V_13 ;
F_4 ( & V_15 , V_13 ) ;
V_12 -> V_16 = V_17 ;
F_5 ( & V_15 , V_13 ) ;
return V_17 ;
}
static int F_7 ( T_1 * V_12 )
{
unsigned long V_13 ;
int V_14 ;
F_8 ( & V_18 , V_13 ) ;
V_14 = F_9 ( & V_12 -> V_19 ) ;
F_10 ( & V_18 , V_13 ) ;
return V_14 ;
}
static int
F_11 ( struct V_20 * V_20 , struct V_1 * V_2 )
{
int V_21 = F_12 ( V_20 ) ;
int V_13 = V_2 -> V_22 ;
struct V_23 * V_24 ;
T_1 * V_12 ;
T_2 * V_5 ;
int V_25 ;
int V_26 ;
F_13 ( V_20 , V_2 ) ;
F_14 ( 3 , F_15 ( L_1 , V_21 , V_13 ) ) ;
V_12 = F_16 ( V_21 ) ;
if ( F_17 ( V_12 ) ) {
V_26 = F_18 ( V_12 ) ;
V_12 = NULL ;
goto V_27;
}
V_26 = F_19 ( V_12 -> V_8 ) ;
if ( V_26 )
goto V_27;
V_26 = F_20 ( V_12 -> V_8 ) ;
if ( V_26 )
goto V_28;
if ( ! ( ( V_13 & V_29 ) ||
F_21 ( V_12 -> V_8 ) ) ) {
V_26 = - V_30 ;
goto V_31;
}
if ( V_13 & V_32 ) {
if ( V_33 == ( V_13 & V_34 ) ) {
V_26 = - V_35 ;
goto V_31;
}
if ( ! F_7 ( V_12 ) && ( V_13 & V_29 ) ) {
V_26 = - V_36 ;
goto V_31;
}
V_25 = F_22 ( V_12 -> V_37 ,
( ( ! F_7 ( V_12 ) || F_3 ( V_12 ) ) ? 0 : F_6 ( V_12 , 1 ) ) ) ;
if ( V_25 ) {
V_26 = V_25 ;
goto V_31;
}
} else if ( F_3 ( V_12 ) ) {
if ( V_13 & V_29 ) {
V_26 = - V_36 ;
goto V_31;
}
V_25 = F_22 ( V_12 -> V_37 , ! F_3 ( V_12 ) ) ;
if ( V_25 ) {
V_26 = V_25 ;
goto V_31;
}
}
if ( V_12 -> V_38 ) {
V_26 = - V_39 ;
goto V_31;
}
if ( F_7 ( V_12 ) ) {
V_12 -> V_40 = 0 ;
V_24 = V_12 -> V_8 -> V_23 ;
V_12 -> V_41 = F_23 ( V_24 ) ;
}
if ( ( V_5 = F_24 ( V_12 , V_21 ) ) )
V_2 -> V_6 = V_5 ;
else {
if ( V_13 & V_32 ) {
F_6 ( V_12 , 0 ) ;
F_25 ( & V_12 -> V_37 ) ;
}
V_26 = - V_42 ;
goto V_31;
}
V_26 = 0 ;
V_31:
if ( V_26 ) {
F_26 ( V_12 -> V_8 ) ;
V_28:
F_27 ( V_12 -> V_8 ) ;
}
V_27:
if ( V_12 )
F_28 ( V_12 ) ;
return V_26 ;
}
static int
F_29 ( struct V_20 * V_20 , struct V_1 * V_2 )
{
T_1 * V_12 ;
T_2 * V_5 ;
if ( ( ! ( V_5 = ( T_2 * ) V_2 -> V_6 ) ) || ( ! ( V_12 = V_5 -> V_7 ) ) )
return - V_30 ;
F_14 ( 3 , F_15 ( L_2 , V_12 -> V_43 -> V_44 ) ) ;
F_6 ( V_12 , 0 ) ;
F_25 ( & V_12 -> V_37 ) ;
F_26 ( V_12 -> V_8 ) ;
F_30 ( & V_5 -> V_45 , V_46 ) ;
return 0 ;
}
static T_3
F_31 ( struct V_1 * V_2 , char T_4 * V_47 , T_5 V_48 , T_6 * V_49 )
{
T_1 * V_12 ;
T_2 * V_5 ;
T_7 * V_50 ;
int V_51 = - 1 ;
T_8 * V_52 ;
struct V_53 * V_54 = NULL ;
int V_26 = 0 ;
if ( ( ! ( V_5 = ( T_2 * ) V_2 -> V_6 ) ) || ( ! ( V_12 = V_5 -> V_7 ) ) )
return - V_30 ;
F_14 ( 3 , F_15 ( L_3 ,
V_12 -> V_43 -> V_44 , ( int ) V_48 ) ) ;
if ( ! F_32 ( V_55 , V_47 , V_48 ) )
return - V_56 ;
if ( V_5 -> V_57 && ( V_48 >= V_58 ) ) {
V_54 = F_33 ( V_58 , V_59 ) ;
if ( ! V_54 )
return - V_42 ;
if ( F_34 ( V_54 , V_47 , V_58 ) ) {
V_26 = - V_56 ;
goto V_60;
}
if ( V_54 -> V_61 < 0 ) {
if ( V_48 >= V_62 ) {
T_8 * V_63 ;
V_63 = F_33 ( V_62 , V_59 ) ;
if ( ! V_63 ) {
V_26 = - V_42 ;
goto V_60;
}
V_26 = F_34
( V_63 , V_47 , V_62 ) ;
V_51 = V_63 -> V_64 ;
F_35 ( V_63 ) ;
if ( V_26 ) {
V_26 = - V_56 ;
goto V_60;
}
}
} else
V_51 = V_54 -> V_64 ;
}
V_50 = F_36 ( V_5 , V_51 ) ;
if ( ! V_50 ) {
if ( V_12 -> V_38 ) {
V_26 = - V_39 ;
goto V_60;
}
if ( V_2 -> V_22 & V_29 ) {
V_26 = - V_65 ;
goto V_60;
}
V_26 = F_22 ( V_5 -> V_66 ,
( V_12 -> V_38 ||
( V_50 = F_36 ( V_5 , V_51 ) ) ) ) ;
if ( V_12 -> V_38 ) {
V_26 = - V_39 ;
goto V_60;
}
if ( V_26 ) {
goto V_60;
}
}
if ( V_50 -> V_67 . V_68 != '\0' ) {
V_26 = F_37 ( V_5 , V_47 , V_48 , V_50 ) ;
goto V_60;
}
V_52 = & V_50 -> V_67 ;
if ( V_54 == NULL ) {
V_54 = F_33 ( V_58 , V_59 ) ;
if ( ! V_54 ) {
V_26 = - V_42 ;
goto V_60;
}
}
memset ( V_54 , 0 , V_58 ) ;
V_54 -> V_61 = ( int ) V_52 -> V_69 ;
V_54 -> V_70 = V_54 -> V_61 ;
V_54 -> V_64 = V_52 -> V_64 ;
V_54 -> V_71 =
( ( V_50 -> V_72 . V_73 >= 0xc0 ) && ( 12 == V_52 -> V_74 ) ) ? 1 : 0 ;
V_54 -> V_75 = V_52 -> V_76 ;
V_54 -> V_77 = V_52 -> V_77 ;
V_54 -> V_78 = V_52 -> V_78 ;
if ( ( V_79 & V_52 -> V_76 ) ||
( V_80 & V_52 -> V_78 ) )
memcpy ( V_54 -> V_81 , V_50 -> V_82 ,
sizeof ( V_54 -> V_81 ) ) ;
switch ( V_52 -> V_77 ) {
case V_83 :
case V_84 :
case V_85 :
V_54 -> V_86 = 0 ;
break;
case V_87 :
case V_88 :
case V_89 :
V_54 -> V_86 = V_36 ;
break;
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
V_54 -> V_86 = V_95 ;
break;
case V_96 :
V_54 -> V_86 = ( V_50 -> V_82 [ 0 ] == 0 &&
V_52 -> V_76 == V_97 ) ? 0 : V_95 ;
break;
default:
V_54 -> V_86 = V_95 ;
break;
}
if ( V_48 >= V_58 ) {
if ( F_38 ( V_47 , V_54 , V_58 ) ) {
V_26 = - V_56 ;
goto V_60;
}
V_47 += V_58 ;
if ( V_48 > V_54 -> V_61 )
V_48 = V_54 -> V_61 ;
if ( V_48 > V_58 ) {
if ( F_39 ( V_50 , V_47 , V_48 - V_58 ) ) {
V_26 = - V_56 ;
goto V_60;
}
}
} else
V_48 = ( V_54 -> V_86 == 0 ) ? 0 : - V_95 ;
F_40 ( V_50 ) ;
V_26 = V_48 ;
V_60:
F_35 ( V_54 ) ;
return V_26 ;
}
static T_3
F_37 ( T_2 * V_5 , char T_4 * V_47 , T_5 V_48 , T_7 * V_50 )
{
T_8 * V_52 = & V_50 -> V_67 ;
int V_98 = 0 ;
int V_99 ;
if ( V_48 < V_62 ) {
V_98 = - V_100 ;
goto V_101;
}
V_52 -> V_102 = 0 ;
if ( ( V_52 -> V_103 > 0 ) && V_52 -> V_104 ) {
if ( ( V_79 & V_52 -> V_76 ) ||
( V_80 & V_52 -> V_78 ) ) {
int V_105 = V_106 ;
V_105 = ( V_52 -> V_103 > V_105 ) ? V_105 : V_52 -> V_103 ;
V_99 = 8 + ( int ) V_50 -> V_82 [ 7 ] ;
V_99 = ( V_99 > V_105 ) ? V_105 : V_99 ;
if ( F_41 ( V_52 -> V_104 , V_50 -> V_82 , V_99 ) ) {
V_98 = - V_56 ;
goto V_101;
}
V_52 -> V_102 = V_99 ;
}
}
if ( V_52 -> V_76 || V_52 -> V_77 || V_52 -> V_78 )
V_52 -> V_107 |= V_108 ;
if ( F_41 ( V_47 , V_52 , V_62 ) ) {
V_98 = - V_56 ;
goto V_101;
}
V_101:
V_98 = F_40 ( V_50 ) ;
return ( 0 == V_98 ) ? V_48 : V_98 ;
}
static T_3
F_42 ( struct V_1 * V_2 , const char T_4 * V_47 , T_5 V_48 , T_6 * V_49 )
{
int V_109 , V_110 , V_111 ;
int V_112 , V_113 ;
unsigned char V_114 ;
T_1 * V_12 ;
T_2 * V_5 ;
T_7 * V_50 ;
struct V_53 V_54 ;
T_8 * V_52 ;
unsigned char V_115 [ V_116 ] ;
if ( ( ! ( V_5 = ( T_2 * ) V_2 -> V_6 ) ) || ( ! ( V_12 = V_5 -> V_7 ) ) )
return - V_30 ;
F_14 ( 3 , F_15 ( L_4 ,
V_12 -> V_43 -> V_44 , ( int ) V_48 ) ) ;
if ( V_12 -> V_38 )
return - V_39 ;
if ( ! ( ( V_2 -> V_22 & V_29 ) ||
F_21 ( V_12 -> V_8 ) ) )
return - V_30 ;
if ( ! F_32 ( V_117 , V_47 , V_48 ) )
return - V_56 ;
if ( V_48 < V_58 )
return - V_95 ;
if ( F_34 ( & V_54 , V_47 , V_58 ) )
return - V_56 ;
V_113 = ! ( V_2 -> V_22 & V_29 ) ;
if ( V_54 . V_61 < 0 )
return F_43 ( V_5 , V_2 , V_47 , V_48 ,
V_113 , 0 , 0 , NULL ) ;
if ( V_48 < ( V_58 + 6 ) )
return - V_95 ;
if ( ! ( V_50 = F_44 ( V_5 ) ) ) {
F_14 ( 1 , F_15 ( L_5 ) ) ;
return - V_118 ;
}
V_47 += V_58 ;
F_45 ( V_114 , V_47 ) ;
if ( V_5 -> V_119 > 0 ) {
if ( V_5 -> V_119 > V_116 ) {
F_14 ( 1 , F_15 ( L_6 ) ) ;
V_5 -> V_119 = 0 ;
F_46 ( V_5 , V_50 ) ;
return - V_95 ;
}
V_110 = V_5 -> V_119 ;
V_5 -> V_119 = 0 ;
} else {
V_110 = F_47 ( V_114 ) ;
if ( ( V_114 >= 0xc0 ) && V_54 . V_71 )
V_110 = 12 ;
}
F_14 ( 4 , F_15 (
L_7 , ( int ) V_114 , V_110 ) ) ;
V_112 = V_48 - V_110 ;
V_109 = ( V_112 > V_54 . V_61 ) ? V_112 : V_54 . V_61 ;
V_109 -= V_58 ;
V_112 -= V_58 ;
if ( V_112 < 0 ) {
F_46 ( V_5 , V_50 ) ;
return - V_95 ;
}
V_52 = & V_50 -> V_67 ;
V_52 -> V_68 = '\0' ;
V_52 -> V_74 = ( unsigned char ) V_110 ;
V_52 -> V_120 = 0 ;
V_52 -> V_103 = 0 ;
if ( V_112 > 0 )
V_52 -> V_121 = ( V_54 . V_61 > V_58 ) ?
V_122 : V_123 ;
else
V_52 -> V_121 = ( V_109 > 0 ) ? V_124 : V_125 ;
V_52 -> V_126 = V_109 ;
if ( V_52 -> V_121 == V_123 )
V_52 -> V_127 = ( char T_4 * ) V_47 + V_110 ;
else
V_52 -> V_127 = NULL ;
V_52 -> V_104 = NULL ;
V_52 -> V_69 = V_54 . V_61 ;
V_52 -> V_13 = V_112 ;
V_52 -> V_64 = V_54 . V_64 ;
V_52 -> V_128 = NULL ;
if ( F_34 ( V_115 , V_47 , V_110 ) )
return - V_56 ;
if ( V_52 -> V_121 == V_122 ) {
static char V_3 [ V_129 ] ;
if ( strcmp ( V_130 -> V_131 , V_3 ) ) {
F_48 ( V_132
L_8
L_9
L_10
L_11 ,
V_54 . V_61 - ( int ) V_58 ,
V_112 , ( unsigned int ) V_115 [ 0 ] ,
V_130 -> V_131 ) ;
strcpy ( V_3 , V_130 -> V_131 ) ;
}
}
V_111 = F_49 ( V_5 , V_50 , V_115 , V_5 -> V_69 , V_113 ) ;
return ( V_111 < 0 ) ? V_111 : V_48 ;
}
static T_3
F_43 ( T_2 * V_5 , struct V_1 * V_1 , const char T_4 * V_47 ,
T_5 V_48 , int V_113 , int V_133 , int V_134 ,
T_7 * * V_135 )
{
int V_111 ;
T_7 * V_50 ;
T_8 * V_52 ;
unsigned char V_115 [ V_116 ] ;
int V_69 ;
unsigned long V_136 ;
if ( V_48 < V_62 )
return - V_100 ;
if ( ! F_32 ( V_117 , V_47 , V_48 ) )
return - V_56 ;
V_5 -> V_137 = 1 ;
if ( ! ( V_50 = F_44 ( V_5 ) ) ) {
F_14 ( 1 , F_15 ( L_12 ) ) ;
return - V_118 ;
}
V_50 -> V_134 = V_134 ;
V_52 = & V_50 -> V_67 ;
if ( F_34 ( V_52 , V_47 , V_62 ) ) {
F_46 ( V_5 , V_50 ) ;
return - V_56 ;
}
if ( V_52 -> V_68 != 'S' ) {
F_46 ( V_5 , V_50 ) ;
return - V_138 ;
}
if ( V_52 -> V_13 & V_139 ) {
if ( V_52 -> V_126 > V_5 -> V_140 . V_141 ) {
F_46 ( V_5 , V_50 ) ;
return - V_42 ;
}
if ( V_52 -> V_13 & V_142 ) {
F_46 ( V_5 , V_50 ) ;
return - V_100 ;
}
if ( F_50 ( V_5 ) ) {
F_46 ( V_5 , V_50 ) ;
return - V_36 ;
}
}
V_136 = F_51 ( V_50 -> V_67 . V_69 ) ;
V_69 = ( V_136 < V_143 ) ? V_136 : V_143 ;
if ( ( ! V_52 -> V_144 ) || ( V_52 -> V_74 < 6 ) || ( V_52 -> V_74 > sizeof ( V_115 ) ) ) {
F_46 ( V_5 , V_50 ) ;
return - V_145 ;
}
if ( ! F_32 ( V_117 , V_52 -> V_144 , V_52 -> V_74 ) ) {
F_46 ( V_5 , V_50 ) ;
return - V_56 ;
}
if ( F_34 ( V_115 , V_52 -> V_144 , V_52 -> V_74 ) ) {
F_46 ( V_5 , V_50 ) ;
return - V_56 ;
}
if ( V_133 && F_1 ( V_1 , V_115 ) ) {
F_46 ( V_5 , V_50 ) ;
return - V_35 ;
}
V_111 = F_49 ( V_5 , V_50 , V_115 , V_69 , V_113 ) ;
if ( V_111 < 0 )
return V_111 ;
if ( V_135 )
* V_135 = V_50 ;
return V_48 ;
}
static int
F_49 ( T_2 * V_5 , T_7 * V_50 ,
unsigned char * V_115 , int V_69 , int V_113 )
{
int V_111 , V_146 ;
T_1 * V_12 = V_5 -> V_7 ;
T_8 * V_52 = & V_50 -> V_67 ;
V_50 -> V_72 . V_73 = V_115 [ 0 ] ;
V_52 -> V_147 = 0 ;
V_52 -> V_76 = 0 ;
V_52 -> V_148 = 0 ;
V_52 -> V_107 = 0 ;
V_52 -> V_77 = 0 ;
V_52 -> V_78 = 0 ;
V_52 -> V_149 = 0 ;
F_14 ( 4 , F_15 ( L_13 ,
( int ) V_115 [ 0 ] , ( int ) V_52 -> V_74 ) ) ;
V_111 = F_52 ( V_50 , V_115 ) ;
if ( V_111 ) {
F_14 ( 1 , F_15 ( L_14 , V_111 ) ) ;
F_40 ( V_50 ) ;
return V_111 ;
}
if ( V_12 -> V_38 ) {
if ( V_50 -> V_150 )
F_53 ( V_50 -> V_151 , - V_95 ) ;
F_40 ( V_50 ) ;
return - V_39 ;
}
switch ( V_52 -> V_121 ) {
case V_122 :
case V_124 :
V_146 = V_152 ;
break;
case V_123 :
V_146 = V_153 ;
break;
case V_154 :
V_146 = V_155 ;
break;
default:
V_146 = V_156 ;
break;
}
V_52 -> V_157 = F_54 ( V_158 ) ;
V_50 -> V_151 -> V_69 = V_69 ;
F_55 ( & V_5 -> V_45 ) ;
F_56 ( V_12 -> V_8 -> V_23 , V_12 -> V_43 ,
V_50 -> V_151 , 1 , V_159 ) ;
return 0 ;
}
static int F_57 ( T_2 * V_5 , T_7 * V_50 )
{
unsigned long V_13 ;
int V_14 ;
F_8 ( & V_5 -> V_160 , V_13 ) ;
V_14 = V_50 -> V_161 ;
F_10 ( & V_5 -> V_160 , V_13 ) ;
return V_14 ;
}
static long
F_58 ( struct V_1 * V_2 , unsigned int V_162 , unsigned long V_163 )
{
void T_4 * V_164 = ( void T_4 * ) V_163 ;
int T_4 * V_165 = V_164 ;
int V_86 , V_17 , V_133 ;
T_1 * V_12 ;
T_2 * V_5 ;
T_7 * V_50 ;
unsigned long V_166 ;
if ( ( ! ( V_5 = ( T_2 * ) V_2 -> V_6 ) ) || ( ! ( V_12 = V_5 -> V_7 ) ) )
return - V_30 ;
F_14 ( 3 , F_15 ( L_15 ,
V_12 -> V_43 -> V_44 , ( int ) V_162 ) ) ;
V_133 = ( V_167 != ( V_2 -> V_22 & V_34 ) ) ;
switch ( V_162 ) {
case V_168 :
if ( V_12 -> V_38 )
return - V_39 ;
if ( ! F_21 ( V_12 -> V_8 ) )
return - V_30 ;
if ( ! F_32 ( V_55 , V_164 , V_62 ) )
return - V_56 ;
V_86 = F_43 ( V_5 , V_2 , V_164 , V_62 ,
1 , V_133 , 1 , & V_50 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_22 ( V_5 -> V_66 ,
( F_57 ( V_5 , V_50 ) || V_12 -> V_38 ) ) ;
if ( V_12 -> V_38 )
return - V_39 ;
F_59 ( & V_5 -> V_160 ) ;
if ( V_50 -> V_161 ) {
V_50 -> V_161 = 2 ;
F_60 ( & V_5 -> V_160 ) ;
V_86 = F_37 ( V_5 , V_164 , V_62 , V_50 ) ;
return ( V_86 < 0 ) ? V_86 : 0 ;
}
V_50 -> V_169 = 1 ;
F_60 ( & V_5 -> V_160 ) ;
return V_86 ;
case V_170 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
if ( V_17 < 0 )
return - V_95 ;
if ( V_17 >= F_62 ( V_143 , V_171 , V_172 ) )
V_17 = F_62 ( V_143 , V_171 , V_172 ) ;
V_5 -> V_173 = V_17 ;
V_5 -> V_69 = F_62 ( V_17 , V_172 , V_171 ) ;
return 0 ;
case V_174 :
return V_5 -> V_173 ;
case V_175 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
if ( V_17 ) {
V_5 -> V_176 = 1 ;
if ( ( 0 == V_5 -> V_176 ) && ( 0 == F_50 ( V_5 ) ) ) {
V_17 = ( int ) V_5 -> V_140 . V_141 ;
F_63 ( & V_5 -> V_140 ) ;
F_64 ( V_5 , V_17 ) ;
}
} else {
if ( V_12 -> V_38 )
return - V_39 ;
V_5 -> V_176 = V_12 -> V_8 -> V_177 -> V_178 ;
}
return 0 ;
case V_179 :
return F_65 ( ( int ) V_5 -> V_176 , V_165 ) ;
case V_180 :
if ( ! F_32 ( V_55 , V_164 , sizeof ( V_181 ) ) )
return - V_56 ;
else {
V_181 T_4 * V_182 = V_164 ;
if ( V_12 -> V_38 )
return - V_39 ;
F_66 ( ( int ) V_12 -> V_8 -> V_177 -> V_183 ,
& V_182 -> V_183 ) ;
F_66 ( ( int ) V_12 -> V_8 -> V_184 ,
& V_182 -> V_184 ) ;
F_66 ( ( int ) V_12 -> V_8 -> V_185 , & V_182 -> V_186 ) ;
F_66 ( ( int ) V_12 -> V_8 -> V_187 , & V_182 -> V_187 ) ;
F_66 ( ( int ) V_12 -> V_8 -> type , & V_182 -> V_188 ) ;
F_66 ( ( short ) V_12 -> V_8 -> V_177 -> V_189 ,
& V_182 -> V_190 ) ;
F_66 ( ( short ) V_12 -> V_8 -> V_191 ,
& V_182 -> V_192 ) ;
F_66 ( 0 , & V_182 -> V_193 [ 0 ] ) ;
F_66 ( 0 , & V_182 -> V_193 [ 1 ] ) ;
return 0 ;
}
case V_194 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
V_5 -> V_57 = V_17 ? 1 : 0 ;
return 0 ;
case V_195 :
if ( ! F_32 ( V_55 , V_165 , sizeof ( int ) ) )
return - V_56 ;
F_8 ( & V_5 -> V_160 , V_166 ) ;
for ( V_50 = V_5 -> V_196 ; V_50 ; V_50 = V_50 -> V_197 ) {
if ( ( 1 == V_50 -> V_161 ) && ( ! V_50 -> V_134 ) ) {
F_10 ( & V_5 -> V_160 ,
V_166 ) ;
F_66 ( V_50 -> V_67 . V_64 , V_165 ) ;
return 0 ;
}
}
F_10 ( & V_5 -> V_160 , V_166 ) ;
F_66 ( - 1 , V_165 ) ;
return 0 ;
case V_198 :
F_8 ( & V_5 -> V_160 , V_166 ) ;
for ( V_17 = 0 , V_50 = V_5 -> V_196 ; V_50 ; V_50 = V_50 -> V_197 ) {
if ( ( 1 == V_50 -> V_161 ) && ( ! V_50 -> V_134 ) )
++ V_17 ;
}
F_10 ( & V_5 -> V_160 , V_166 ) ;
return F_65 ( V_17 , V_165 ) ;
case V_199 :
return F_65 ( V_12 -> V_41 , V_165 ) ;
case V_200 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
if ( V_17 < 0 )
return - V_100 ;
V_17 = F_67 ( int , V_17 ,
F_68 ( V_12 -> V_8 -> V_23 ) * 512 ) ;
if ( V_17 != V_5 -> V_140 . V_141 ) {
if ( F_50 ( V_5 ) || V_5 -> V_201 )
return - V_36 ;
F_63 ( & V_5 -> V_140 ) ;
F_64 ( V_5 , V_17 ) ;
}
return 0 ;
case V_202 :
V_17 = F_67 ( int , V_5 -> V_140 . V_141 ,
F_68 ( V_12 -> V_8 -> V_23 ) * 512 ) ;
return F_65 ( V_17 , V_165 ) ;
case V_203 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
V_5 -> V_137 = V_17 ? 1 : 0 ;
return 0 ;
case V_204 :
return F_65 ( ( int ) V_5 -> V_137 , V_165 ) ;
case V_205 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
V_5 -> V_206 = V_17 ;
return 0 ;
case V_207 :
return F_65 ( ( int ) V_5 -> V_206 , V_165 ) ;
case V_208 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
V_5 -> V_119 = ( V_17 > 0 ) ? V_17 : 0 ;
return 0 ;
case V_209 :
return F_65 ( V_210 , V_165 ) ;
case V_211 :
V_17 = ( V_12 -> V_8 ? 1 : 0 ) ;
return F_65 ( V_17 , V_165 ) ;
case V_212 :
if ( ! F_32 ( V_55 , V_164 , V_213 * V_214 ) )
return - V_56 ;
else {
T_9 * V_215 ;
unsigned int V_216 ;
V_215 = F_33 ( V_213 * V_214 ,
V_59 ) ;
if ( ! V_215 )
return - V_42 ;
F_8 ( & V_5 -> V_160 , V_166 ) ;
for ( V_50 = V_5 -> V_196 , V_17 = 0 ; V_17 < V_214 ;
++ V_17 , V_50 = V_50 ? V_50 -> V_197 : V_50 ) {
memset ( & V_215 [ V_17 ] , 0 , V_213 ) ;
if ( V_50 ) {
V_215 [ V_17 ] . V_217 = V_50 -> V_161 + 1 ;
V_215 [ V_17 ] . V_218 =
V_50 -> V_67 . V_76 &
V_50 -> V_67 . V_77 &
V_50 -> V_67 . V_78 ;
if ( V_50 -> V_161 )
V_215 [ V_17 ] . V_157 =
V_50 -> V_67 . V_157 ;
else {
V_216 = F_54 ( V_158 ) ;
V_215 [ V_17 ] . V_157 =
( V_216 > V_50 -> V_67 . V_157 ) ?
( V_216 - V_50 -> V_67 . V_157 ) : 0 ;
}
V_215 [ V_17 ] . V_169 = V_50 -> V_169 ;
V_215 [ V_17 ] . V_134 =
V_50 -> V_134 ;
V_215 [ V_17 ] . V_64 =
V_50 -> V_67 . V_64 ;
V_215 [ V_17 ] . V_128 =
V_50 -> V_67 . V_128 ;
}
}
F_10 ( & V_5 -> V_160 , V_166 ) ;
V_86 = F_38 ( V_164 , V_215 ,
V_213 * V_214 ) ;
V_86 = V_86 ? - V_56 : 0 ;
F_35 ( V_215 ) ;
return V_86 ;
}
case V_219 :
if ( V_12 -> V_38 )
return - V_39 ;
return F_65 ( V_12 -> V_8 -> V_177 -> V_220 -> V_221 , V_165 ) ;
case V_222 :
if ( V_12 -> V_38 )
return - V_39 ;
if ( V_2 -> V_22 & V_29 ) {
if ( F_69 ( V_12 -> V_8 -> V_177 ) )
return - V_36 ;
} else if ( ! F_21 ( V_12 -> V_8 ) )
return - V_36 ;
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
if ( V_223 == V_17 )
return 0 ;
switch ( V_17 ) {
case V_224 :
V_17 = V_225 ;
break;
case V_226 :
V_17 = V_227 ;
break;
case V_228 :
V_17 = V_229 ;
break;
case V_230 :
V_17 = V_231 ;
break;
default:
return - V_100 ;
}
if ( ! F_70 ( V_232 ) || ! F_70 ( V_233 ) )
return - V_234 ;
return ( F_71 ( V_12 -> V_8 , V_17 ) ==
V_235 ) ? 0 : - V_95 ;
case V_236 :
if ( V_12 -> V_38 )
return - V_39 ;
if ( V_133 ) {
unsigned char V_114 = V_237 ;
T_10 T_4 * V_238 = V_164 ;
if ( F_72 ( & V_114 , V_238 -> V_72 , 1 ) )
return - V_56 ;
if ( F_1 ( V_2 , & V_114 ) )
return - V_35 ;
}
return F_73 ( V_12 -> V_8 -> V_23 , NULL , V_2 -> V_10 , V_164 ) ;
case V_239 :
V_86 = F_61 ( V_17 , V_165 ) ;
if ( V_86 )
return V_86 ;
V_12 -> V_40 = ( char ) V_17 ;
return 0 ;
case V_240 :
case V_241 :
case V_242 :
case V_243 :
if ( V_12 -> V_38 )
return - V_39 ;
return F_74 ( V_12 -> V_8 , V_162 , V_164 ) ;
case V_244 :
return F_65 ( F_68 ( V_12 -> V_8 -> V_23 ) * 512 ,
V_165 ) ;
case V_245 :
return F_75 ( V_12 -> V_8 -> V_23 ,
V_12 -> V_43 -> V_44 ,
F_76 ( V_246 , V_12 -> V_247 ) ,
NULL ,
( char * ) V_163 ) ;
case V_248 :
return F_77 ( V_12 -> V_8 -> V_23 , 1 ) ;
case V_249 :
return F_77 ( V_12 -> V_8 -> V_23 , 0 ) ;
case V_250 :
return F_78 ( V_12 -> V_8 -> V_23 ) ;
default:
if ( V_133 )
return - V_35 ;
return F_74 ( V_12 -> V_8 , V_162 , V_164 ) ;
}
}
static long F_79 ( struct V_1 * V_2 , unsigned int V_162 , unsigned long V_163 )
{
T_1 * V_12 ;
T_2 * V_5 ;
struct V_251 * V_252 ;
if ( ( ! ( V_5 = ( T_2 * ) V_2 -> V_6 ) ) || ( ! ( V_12 = V_5 -> V_7 ) ) )
return - V_30 ;
V_252 = V_12 -> V_8 ;
if ( V_252 -> V_177 -> V_220 -> V_253 ) {
int V_14 ;
V_14 = V_252 -> V_177 -> V_220 -> V_253 ( V_252 , V_162 , ( void T_4 * ) V_163 ) ;
return V_14 ;
}
return - V_254 ;
}
static unsigned int
F_80 ( struct V_1 * V_2 , T_11 * V_255 )
{
unsigned int V_25 = 0 ;
T_1 * V_12 ;
T_2 * V_5 ;
T_7 * V_50 ;
int V_48 = 0 ;
unsigned long V_166 ;
V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return V_256 ;
V_12 = V_5 -> V_7 ;
if ( ! V_12 )
return V_256 ;
F_81 ( V_2 , & V_5 -> V_66 , V_255 ) ;
F_8 ( & V_5 -> V_160 , V_166 ) ;
for ( V_50 = V_5 -> V_196 ; V_50 ; V_50 = V_50 -> V_197 ) {
if ( ( 0 == V_25 ) && ( 1 == V_50 -> V_161 ) && ( ! V_50 -> V_134 ) )
V_25 = V_257 | V_258 ;
++ V_48 ;
}
F_10 ( & V_5 -> V_160 , V_166 ) ;
if ( V_12 -> V_38 )
V_25 |= V_259 ;
else if ( ! V_5 -> V_137 ) {
if ( 0 == V_48 )
V_25 |= V_260 | V_261 ;
} else if ( V_48 < V_214 )
V_25 |= V_260 | V_261 ;
F_14 ( 3 , F_15 ( L_16 ,
V_12 -> V_43 -> V_44 , ( int ) V_25 ) ) ;
return V_25 ;
}
static int
F_82 ( int V_262 , struct V_1 * V_2 , int V_263 )
{
T_1 * V_12 ;
T_2 * V_5 ;
if ( ( ! ( V_5 = ( T_2 * ) V_2 -> V_6 ) ) || ( ! ( V_12 = V_5 -> V_7 ) ) )
return - V_30 ;
F_14 ( 3 , F_15 ( L_17 ,
V_12 -> V_43 -> V_44 , V_263 ) ) ;
return F_83 ( V_262 , V_2 , V_263 , & V_5 -> V_264 ) ;
}
static int
F_84 ( struct V_265 * V_266 , struct V_267 * V_268 )
{
T_2 * V_5 ;
unsigned long V_269 , V_99 , V_270 ;
T_12 * V_271 ;
int V_111 , V_272 ;
if ( ( NULL == V_266 ) || ( ! ( V_5 = ( T_2 * ) V_266 -> V_273 ) ) )
return V_274 ;
V_271 = & V_5 -> V_140 ;
V_269 = V_268 -> V_275 << V_276 ;
if ( V_269 >= V_271 -> V_141 )
return V_274 ;
F_14 ( 3 , F_15 ( L_18 ,
V_269 , V_271 -> V_277 ) ) ;
V_270 = V_266 -> V_278 ;
V_272 = 1 << ( V_276 + V_271 -> V_279 ) ;
for ( V_111 = 0 ; V_111 < V_271 -> V_277 && V_270 < V_266 -> V_280 ; V_111 ++ ) {
V_99 = V_266 -> V_280 - V_270 ;
V_99 = ( V_99 < V_272 ) ? V_99 : V_272 ;
if ( V_269 < V_99 ) {
struct V_281 * V_281 = F_85 ( V_271 -> V_282 [ V_111 ] ,
V_269 >> V_276 ) ;
F_86 ( V_281 ) ;
V_268 -> V_281 = V_281 ;
return 0 ;
}
V_270 += V_99 ;
V_269 -= V_99 ;
}
return V_274 ;
}
static int
F_87 ( struct V_1 * V_2 , struct V_265 * V_266 )
{
T_2 * V_5 ;
unsigned long V_283 , V_99 , V_270 ;
T_12 * V_271 ;
int V_111 , V_272 ;
if ( ( ! V_2 ) || ( ! V_266 ) || ( ! ( V_5 = ( T_2 * ) V_2 -> V_6 ) ) )
return - V_30 ;
V_283 = V_266 -> V_280 - V_266 -> V_278 ;
F_14 ( 3 , F_15 ( L_19 ,
( void * ) V_266 -> V_278 , ( int ) V_283 ) ) ;
if ( V_266 -> V_284 )
return - V_100 ;
V_271 = & V_5 -> V_140 ;
if ( V_283 > V_271 -> V_141 )
return - V_42 ;
V_270 = V_266 -> V_278 ;
V_272 = 1 << ( V_276 + V_271 -> V_279 ) ;
for ( V_111 = 0 ; V_111 < V_271 -> V_277 && V_270 < V_266 -> V_280 ; V_111 ++ ) {
V_99 = V_266 -> V_280 - V_270 ;
V_99 = ( V_99 < V_272 ) ? V_99 : V_272 ;
V_270 += V_99 ;
}
V_5 -> V_201 = 1 ;
V_266 -> V_285 |= V_286 | V_287 ;
V_266 -> V_273 = V_5 ;
V_266 -> V_288 = & V_289 ;
return 0 ;
}
static void F_88 ( struct V_290 * V_291 )
{
struct V_292 * V_50 = F_89 ( V_291 , struct V_292 , V_293 . V_291 ) ;
struct V_4 * V_5 = V_50 -> V_294 ;
F_40 ( V_50 ) ;
F_30 ( & V_5 -> V_45 , V_46 ) ;
}
static void V_159 ( struct V_295 * V_151 , int V_296 )
{
struct V_292 * V_50 = V_151 -> V_297 ;
T_1 * V_12 ;
T_2 * V_5 ;
unsigned long V_166 ;
unsigned int V_216 ;
char * V_298 ;
int V_86 , V_149 , V_161 = 1 ;
if ( F_90 ( V_50 -> V_161 != 0 ) )
return;
V_5 = V_50 -> V_294 ;
if ( F_90 ( V_5 == NULL ) )
return;
V_12 = V_5 -> V_7 ;
if ( F_91 ( V_12 -> V_38 ) )
F_15 ( V_299 L_20 ) ;
V_298 = V_151 -> V_298 ;
V_86 = V_151 -> V_300 ;
V_149 = V_151 -> V_301 ;
F_14 ( 4 , F_15 ( L_21 ,
V_12 -> V_43 -> V_44 , V_50 -> V_67 . V_64 , V_86 ) ) ;
V_50 -> V_67 . V_149 = V_149 ;
V_216 = F_54 ( V_158 ) ;
V_50 -> V_67 . V_157 = ( V_216 > V_50 -> V_67 . V_157 ) ?
( V_216 - V_50 -> V_67 . V_157 ) : 0 ;
if ( 0 != V_86 ) {
struct V_302 V_303 ;
V_50 -> V_67 . V_147 = 0xff & V_86 ;
V_50 -> V_67 . V_76 = F_92 ( V_86 ) ;
V_50 -> V_67 . V_148 = F_93 ( V_86 ) ;
V_50 -> V_67 . V_77 = F_94 ( V_86 ) ;
V_50 -> V_67 . V_78 = F_95 ( V_86 ) ;
if ( ( V_12 -> V_40 > 0 ) &&
( ( V_79 == V_50 -> V_67 . V_76 ) ||
( V_304 == V_50 -> V_67 . V_76 ) ) )
F_96 ( L_22 , V_298 ,
V_106 ) ;
if ( F_95 ( V_86 ) != 0
&& F_97 ( V_298 , V_106 , & V_303 )
&& ! F_98 ( & V_303 )
&& V_303 . V_305 == V_306
&& V_12 -> V_8 -> V_307 ) {
V_12 -> V_8 -> V_308 = 1 ;
}
}
F_99 ( & V_5 -> V_160 , V_166 ) ;
if ( F_91 ( V_50 -> V_169 ) ) {
if ( V_5 -> V_206 )
V_50 -> V_134 = 0 ;
else
V_161 = 0 ;
}
V_50 -> V_161 = V_161 ;
F_100 ( & V_5 -> V_160 , V_166 ) ;
if ( F_101 ( V_161 ) ) {
F_25 ( & V_5 -> V_66 ) ;
F_102 ( & V_5 -> V_264 , V_309 , V_310 ) ;
F_30 ( & V_5 -> V_45 , V_46 ) ;
} else {
F_103 ( & V_50 -> V_293 . V_291 , F_88 ) ;
F_104 ( & V_50 -> V_293 . V_291 ) ;
}
}
static T_1 * F_105 ( struct V_311 * V_43 , struct V_251 * V_312 )
{
struct V_23 * V_24 = V_312 -> V_23 ;
T_1 * V_12 ;
unsigned long V_166 ;
int error ;
T_13 V_111 ;
V_12 = F_106 ( sizeof( T_1 ) , V_59 ) ;
if ( ! V_12 ) {
F_15 ( V_132 L_23 ) ;
return F_107 ( - V_42 ) ;
}
F_108 ( V_59 ) ;
F_99 ( & V_18 , V_166 ) ;
error = F_109 ( & V_313 , V_12 , 0 , V_314 , V_315 ) ;
if ( error < 0 ) {
if ( error == - V_316 ) {
F_110 ( V_132 , V_312 ,
L_24 ,
V_312 -> type , V_314 - 1 ) ;
error = - V_39 ;
} else {
F_15 ( V_132
L_25 , error ) ;
}
goto V_317;
}
V_111 = error ;
F_14 ( 3 , F_15 ( L_26 , V_111 ) ) ;
sprintf ( V_43 -> V_44 , L_27 , V_111 ) ;
V_43 -> V_318 = V_111 ;
V_12 -> V_43 = V_43 ;
V_12 -> V_8 = V_312 ;
F_111 ( & V_12 -> V_19 ) ;
F_112 ( & V_12 -> V_37 ) ;
V_12 -> V_41 = F_23 ( V_24 ) ;
V_12 -> V_247 = V_111 ;
F_113 ( & V_12 -> V_319 ) ;
error = 0 ;
V_317:
F_100 ( & V_18 , V_166 ) ;
F_114 () ;
if ( error ) {
F_35 ( V_12 ) ;
return F_107 ( error ) ;
}
return V_12 ;
}
static int
F_115 ( struct V_8 * V_320 , struct V_321 * V_322 )
{
struct V_251 * V_312 = F_116 ( V_320 -> V_323 ) ;
struct V_311 * V_43 ;
T_1 * V_12 = NULL ;
struct V_324 * V_324 = NULL ;
int error ;
unsigned long V_166 ;
V_43 = F_117 ( 1 ) ;
if ( ! V_43 ) {
F_15 ( V_132 L_28 ) ;
return - V_42 ;
}
V_43 -> V_325 = V_246 ;
error = - V_42 ;
V_324 = F_118 () ;
if ( ! V_324 ) {
F_15 ( V_132 L_29 ) ;
goto V_326;
}
V_324 -> V_327 = V_328 ;
V_324 -> V_329 = & V_330 ;
V_12 = F_105 ( V_43 , V_312 ) ;
if ( F_17 ( V_12 ) ) {
F_15 ( V_132 L_30 ) ;
error = F_18 ( V_12 ) ;
goto V_326;
}
error = F_119 ( V_324 , F_76 ( V_246 , V_12 -> V_247 ) , 1 ) ;
if ( error )
goto V_331;
V_12 -> V_324 = V_324 ;
if ( V_332 ) {
struct V_8 * V_333 ;
V_333 = F_120 ( V_334 , V_320 -> V_323 ,
F_76 ( V_246 ,
V_12 -> V_247 ) ,
V_12 , L_31 , V_43 -> V_44 ) ;
if ( F_17 ( V_333 ) ) {
F_15 ( V_335 L_32
L_33 ) ;
error = F_18 ( V_333 ) ;
goto V_331;
}
error = F_121 ( & V_312 -> V_336 . V_337 ,
& V_333 -> V_337 , L_34 ) ;
if ( error )
F_15 ( V_335 L_35
L_36 , V_12 -> V_247 ) ;
} else
F_15 ( V_132 L_37 ) ;
F_110 ( V_338 , V_312 ,
L_38 , V_12 -> V_247 ,
V_312 -> type ) ;
F_122 ( V_320 , V_12 ) ;
return 0 ;
V_331:
F_99 ( & V_18 , V_166 ) ;
F_123 ( & V_313 , V_12 -> V_247 ) ;
F_100 ( & V_18 , V_166 ) ;
F_35 ( V_12 ) ;
V_326:
F_124 ( V_43 ) ;
if ( V_324 )
F_125 ( V_324 ) ;
return error ;
}
static void F_126 ( struct V_339 * V_339 )
{
struct V_340 * V_12 = F_89 ( V_339 , struct V_340 , V_319 ) ;
unsigned long V_13 ;
F_99 ( & V_18 , V_13 ) ;
F_123 ( & V_313 , V_12 -> V_247 ) ;
F_100 ( & V_18 , V_13 ) ;
F_14 ( 3 ,
F_15 ( L_39 ,
V_12 -> V_43 -> V_44 ) ) ;
F_124 ( V_12 -> V_43 ) ;
F_35 ( V_12 ) ;
}
static void F_127 ( struct V_8 * V_320 , struct V_321 * V_322 )
{
struct V_251 * V_312 = F_116 ( V_320 -> V_323 ) ;
T_1 * V_12 = F_128 ( V_320 ) ;
unsigned long V_166 ;
T_2 * V_5 ;
if ( ! V_12 || V_12 -> V_38 )
return;
F_14 ( 3 , F_15 ( L_40 , V_12 -> V_43 -> V_44 ) ) ;
F_99 ( & V_18 , V_166 ) ;
V_12 -> V_38 = 1 ;
F_129 (sfp, &sdp->sfds, sfd_siblings) {
F_25 ( & V_5 -> V_66 ) ;
F_102 ( & V_5 -> V_264 , V_309 , V_341 ) ;
}
F_100 ( & V_18 , V_166 ) ;
F_130 ( & V_312 -> V_336 . V_337 , L_34 ) ;
F_131 ( V_334 , F_76 ( V_246 , V_12 -> V_247 ) ) ;
F_125 ( V_12 -> V_324 ) ;
V_12 -> V_324 = NULL ;
F_28 ( V_12 ) ;
}
static int T_14
F_132 ( void )
{
int V_342 ;
if ( V_343 < V_344 ) {
V_343 = V_344 ;
V_345 = V_343 ;
}
if ( V_346 >= 0 )
V_347 = V_346 ;
else
V_346 = V_347 ;
V_342 = F_133 ( F_76 ( V_246 , 0 ) ,
V_314 , L_41 ) ;
if ( V_342 )
return V_342 ;
V_334 = F_134 ( V_328 , L_42 ) ;
if ( F_17 ( V_334 ) ) {
V_342 = F_18 ( V_334 ) ;
goto V_101;
}
V_332 = 1 ;
V_342 = F_135 ( & V_348 ) ;
if ( 0 == V_342 ) {
#ifdef F_136
F_137 () ;
#endif
return 0 ;
}
F_138 ( V_334 ) ;
V_101:
F_139 ( F_76 ( V_246 , 0 ) , V_314 ) ;
return V_342 ;
}
static void T_15
F_140 ( void )
{
#ifdef F_136
F_141 () ;
#endif
F_142 ( & V_348 ) ;
F_138 ( V_334 ) ;
V_332 = 0 ;
F_139 ( F_76 ( V_246 , 0 ) ,
V_314 ) ;
F_143 ( & V_313 ) ;
}
static int F_52 ( T_7 * V_50 , unsigned char * V_3 )
{
int V_25 ;
struct V_295 * V_151 ;
T_2 * V_5 = V_50 -> V_294 ;
T_8 * V_52 = & V_50 -> V_67 ;
int V_126 = ( int ) V_52 -> V_126 ;
int V_349 = V_52 -> V_121 ;
unsigned int V_350 = V_52 -> V_120 ;
T_12 * V_351 = & V_50 -> V_72 ;
T_12 * V_271 = & V_5 -> V_140 ;
struct V_23 * V_24 = V_5 -> V_7 -> V_8 -> V_23 ;
struct V_352 * V_353 , V_354 ;
int V_355 = V_52 -> V_121 == V_123 ? V_356 : V_357 ;
F_14 ( 4 , F_15 ( V_299 L_43 ,
V_126 ) ) ;
V_151 = F_144 ( V_24 , V_355 , V_358 ) ;
if ( ! V_151 )
return - V_42 ;
memcpy ( V_151 -> V_3 , V_3 , V_52 -> V_74 ) ;
V_151 -> V_74 = V_52 -> V_74 ;
V_151 -> V_359 = V_360 ;
V_50 -> V_151 = V_151 ;
V_151 -> V_297 = V_50 ;
V_151 -> V_298 = V_50 -> V_82 ;
V_151 -> V_361 = V_362 ;
if ( ( V_126 <= 0 ) || ( V_349 == V_125 ) )
return 0 ;
if ( V_363 && V_52 -> V_13 & V_142 &&
V_349 != V_154 && ! V_350 &&
! V_5 -> V_7 -> V_8 -> V_177 -> V_178 &&
F_145 ( V_24 , ( unsigned long ) V_52 -> V_127 , V_126 ) )
V_353 = NULL ;
else
V_353 = & V_354 ;
if ( V_353 ) {
if ( ! F_50 ( V_5 ) && V_126 <= V_271 -> V_141 )
F_146 ( V_5 , V_50 , V_126 ) ;
else {
V_25 = F_147 ( V_351 , V_5 , V_126 ) ;
if ( V_25 )
return V_25 ;
}
V_353 -> V_282 = V_351 -> V_282 ;
V_353 -> V_279 = V_351 -> V_279 ;
V_353 -> V_364 = V_351 -> V_277 ;
V_353 -> V_269 = 0 ;
V_353 -> V_365 = V_52 -> V_127 ? 0 : 1 ;
if ( V_349 == V_122 )
V_353 -> V_366 = 1 ;
else
V_353 -> V_366 = 0 ;
}
if ( V_350 ) {
int V_99 , V_367 = sizeof( struct V_368 ) * V_350 ;
struct V_369 * V_370 ;
V_370 = F_148 ( V_52 -> V_127 , V_367 ) ;
if ( F_17 ( V_370 ) )
return F_18 ( V_370 ) ;
V_99 = F_149 ( V_370 , V_350 ) ;
if ( V_52 -> V_126 < V_99 ) {
V_350 = F_150 ( V_370 , V_350 , V_52 -> V_126 ) ;
V_99 = V_52 -> V_126 ;
}
V_25 = F_151 ( V_24 , V_151 , V_353 , (struct V_368 * ) V_370 ,
V_350 ,
V_99 , V_358 ) ;
F_35 ( V_370 ) ;
} else
V_25 = F_152 ( V_24 , V_151 , V_353 , V_52 -> V_127 ,
V_52 -> V_126 , V_358 ) ;
if ( ! V_25 ) {
V_50 -> V_150 = V_151 -> V_150 ;
if ( ! V_353 ) {
V_351 -> V_371 = 1 ;
V_52 -> V_107 |= V_372 ;
}
}
return V_25 ;
}
static int F_40 ( T_7 * V_50 )
{
int V_14 = 0 ;
T_2 * V_5 = V_50 -> V_294 ;
T_12 * V_351 = & V_50 -> V_72 ;
F_14 ( 4 , F_15 ( L_44 , ( int ) V_50 -> V_373 ) ) ;
if ( V_50 -> V_151 ) {
if ( V_50 -> V_150 )
V_14 = F_153 ( V_50 -> V_150 ) ;
F_154 ( V_50 -> V_151 ) ;
}
if ( V_50 -> V_373 )
F_155 ( V_5 , V_50 ) ;
else
F_63 ( V_351 ) ;
F_46 ( V_5 , V_50 ) ;
return V_14 ;
}
static int
F_156 ( T_12 * V_374 , const T_2 * V_5 , int V_375 )
{
int V_376 = V_375 * sizeof( struct V_281 * ) ;
T_16 V_377 = V_358 | V_378 ;
V_374 -> V_282 = F_106 ( V_376 , V_377 ) ;
if ( ! V_374 -> V_282 )
return - V_42 ;
V_374 -> V_379 = V_376 ;
return V_375 ;
}
static int
F_147 ( T_12 * V_374 , T_2 * V_5 , int V_380 )
{
int V_381 = 0 , V_382 , V_111 , V_383 , V_384 , V_385 ;
int V_41 = V_5 -> V_7 -> V_41 ;
int V_386 = V_380 , V_387 ;
T_16 V_388 = V_358 | V_389 | V_378 ;
if ( V_386 < 0 )
return - V_56 ;
if ( 0 == V_386 )
++ V_386 ;
V_386 = F_157 ( V_386 , V_390 ) ;
F_14 ( 4 , F_15 ( L_45 ,
V_380 , V_386 ) ) ;
V_385 = F_156 ( V_374 , V_5 , V_41 ) ;
if ( V_385 < 0 )
return V_385 ;
V_384 = V_343 ;
if ( F_91 ( V_384 != V_345 ) ) {
if ( V_384 < V_344 ) {
V_343 = V_344 ;
V_345 = V_344 ;
} else
V_345 = V_384 ;
}
if ( V_5 -> V_176 )
V_388 |= V_391 ;
if ( ! F_70 ( V_232 ) || ! F_70 ( V_233 ) )
V_388 |= V_392 ;
V_387 = F_158 ( V_384 ) ;
V_393:
V_381 = 1 << ( V_276 + V_387 ) ;
for ( V_111 = 0 , V_383 = V_386 ; V_383 > 0 && V_111 < V_385 ;
V_111 ++ , V_383 -= V_381 ) {
V_384 = ( V_383 > V_345 ) ?
V_345 : V_383 ;
V_374 -> V_282 [ V_111 ] = F_159 ( V_388 , V_387 ) ;
if ( ! V_374 -> V_282 [ V_111 ] )
goto V_326;
if ( V_384 == V_345 ) {
if ( F_91 ( V_381 > V_345 ) ) {
V_343 = V_381 ;
V_345 = V_381 ;
}
}
F_14 ( 5 , F_15 ( L_46
L_47 , V_111 , V_384 , V_381 ) ) ;
}
V_374 -> V_279 = V_387 ;
V_374 -> V_277 = V_111 ;
F_14 ( 5 , F_15 ( L_48
L_49 , V_111 , V_383 ) ) ;
V_374 -> V_141 = V_386 ;
if ( V_383 > 0 )
return - V_42 ;
return 0 ;
V_326:
for ( V_382 = 0 ; V_382 < V_111 ; V_382 ++ )
F_160 ( V_374 -> V_282 [ V_382 ] , V_387 ) ;
if ( -- V_387 >= 0 )
goto V_393;
return - V_42 ;
}
static void
F_63 ( T_12 * V_374 )
{
F_14 ( 4 , F_15 ( L_50 , V_374 -> V_277 ) ) ;
if ( V_374 -> V_282 && V_374 -> V_379 > 0 ) {
if ( ! V_374 -> V_371 ) {
int V_111 ;
for ( V_111 = 0 ; V_111 < V_374 -> V_277 && V_374 -> V_282 [ V_111 ] ; V_111 ++ ) {
F_14 ( 5 , F_15 (
L_51 ,
V_111 , V_374 -> V_282 [ V_111 ] ) ) ;
F_160 ( V_374 -> V_282 [ V_111 ] , V_374 -> V_279 ) ;
}
F_35 ( V_374 -> V_282 ) ;
}
}
memset ( V_374 , 0 , sizeof ( * V_374 ) ) ;
}
static int
F_39 ( T_7 * V_50 , char T_4 * V_394 , int V_395 )
{
T_12 * V_374 = & V_50 -> V_72 ;
int V_111 , V_384 ;
F_14 ( 4 , F_15 ( L_52 ,
V_395 ) ) ;
if ( ( ! V_394 ) || ( V_395 <= 0 ) )
return 0 ;
V_384 = 1 << ( V_276 + V_374 -> V_279 ) ;
for ( V_111 = 0 ; V_111 < V_374 -> V_277 && V_374 -> V_282 [ V_111 ] ; V_111 ++ ) {
if ( V_384 > V_395 ) {
if ( F_38 ( V_394 , F_161 ( V_374 -> V_282 [ V_111 ] ) ,
V_395 ) )
return - V_56 ;
break;
} else {
if ( F_38 ( V_394 , F_161 ( V_374 -> V_282 [ V_111 ] ) ,
V_384 ) )
return - V_56 ;
V_395 -= V_384 ;
if ( V_395 <= 0 )
break;
V_394 += V_384 ;
}
}
return 0 ;
}
static void
F_64 ( T_2 * V_5 , int V_396 )
{
T_12 * V_374 = & V_5 -> V_140 ;
F_14 ( 4 , F_15 ( L_53 , V_396 ) ) ;
do {
if ( V_396 < V_344 )
V_396 = V_344 ;
if ( 0 == F_147 ( V_374 , V_5 , V_396 ) )
return;
else
F_63 ( V_374 ) ;
V_396 >>= 1 ;
} while ( V_396 > ( V_344 / 2 ) );
}
static void
F_146 ( T_2 * V_5 , T_7 * V_50 , int V_367 )
{
T_12 * V_351 = & V_50 -> V_72 ;
T_12 * V_271 = & V_5 -> V_140 ;
int V_111 , V_384 , V_397 ;
V_50 -> V_373 = 1 ;
F_14 ( 4 , F_15 ( L_54 , V_367 ) ) ;
V_397 = V_367 ;
V_384 = 1 << ( V_276 + V_271 -> V_279 ) ;
for ( V_111 = 0 ; V_111 < V_271 -> V_277 ; V_111 ++ ) {
if ( V_397 <= V_384 ) {
V_351 -> V_277 = V_111 + 1 ;
V_351 -> V_379 = V_271 -> V_379 ;
V_351 -> V_282 = V_271 -> V_282 ;
V_351 -> V_141 = V_367 ;
V_351 -> V_279 = V_271 -> V_279 ;
break;
} else
V_397 -= V_384 ;
}
if ( V_111 >= V_271 -> V_277 )
F_14 ( 1 , F_15 ( L_55 ) ) ;
}
static void
F_155 ( T_2 * V_5 , T_7 * V_50 )
{
T_12 * V_351 = & V_50 -> V_72 ;
F_14 ( 4 , F_15 ( L_56 ,
( int ) V_351 -> V_277 ) ) ;
V_351 -> V_277 = 0 ;
V_351 -> V_141 = 0 ;
V_351 -> V_282 = NULL ;
V_351 -> V_279 = 0 ;
V_351 -> V_379 = 0 ;
V_5 -> V_398 = 0 ;
V_50 -> V_373 = 0 ;
}
static T_7 *
F_36 ( T_2 * V_5 , int V_64 )
{
T_7 * V_399 ;
unsigned long V_166 ;
F_99 ( & V_5 -> V_160 , V_166 ) ;
for ( V_399 = V_5 -> V_196 ; V_399 ; V_399 = V_399 -> V_197 ) {
if ( ( 1 == V_399 -> V_161 ) && ( ! V_399 -> V_134 ) &&
( ( - 1 == V_64 ) || ( V_399 -> V_67 . V_64 == V_64 ) ) ) {
V_399 -> V_161 = 2 ;
break;
}
}
F_100 ( & V_5 -> V_160 , V_166 ) ;
return V_399 ;
}
static T_7 *
F_44 ( T_2 * V_5 )
{
int V_111 ;
unsigned long V_166 ;
T_7 * V_399 ;
T_7 * V_400 = V_5 -> V_401 ;
F_99 ( & V_5 -> V_160 , V_166 ) ;
V_399 = V_5 -> V_196 ;
if ( ! V_399 ) {
memset ( V_400 , 0 , sizeof ( T_7 ) ) ;
V_400 -> V_294 = V_5 ;
V_399 = V_400 ;
V_5 -> V_196 = V_399 ;
} else {
if ( 0 == V_5 -> V_137 )
V_399 = NULL ;
else {
for ( V_111 = 0 ; V_111 < V_214 ; ++ V_111 , ++ V_400 ) {
if ( ! V_400 -> V_294 )
break;
}
if ( V_111 < V_214 ) {
memset ( V_400 , 0 , sizeof ( T_7 ) ) ;
V_400 -> V_294 = V_5 ;
while ( V_399 -> V_197 )
V_399 = V_399 -> V_197 ;
V_399 -> V_197 = V_400 ;
V_399 = V_400 ;
} else
V_399 = NULL ;
}
}
if ( V_399 ) {
V_399 -> V_197 = NULL ;
V_399 -> V_67 . V_157 = F_54 ( V_158 ) ;
}
F_100 ( & V_5 -> V_160 , V_166 ) ;
return V_399 ;
}
static int
F_46 ( T_2 * V_5 , T_7 * V_50 )
{
T_7 * V_402 ;
T_7 * V_400 ;
unsigned long V_166 ;
int V_25 = 0 ;
if ( ( ! V_5 ) || ( ! V_50 ) || ( ! V_5 -> V_196 ) )
return V_25 ;
F_99 ( & V_5 -> V_160 , V_166 ) ;
V_402 = V_5 -> V_196 ;
if ( V_50 == V_402 ) {
V_5 -> V_196 = V_402 -> V_197 ;
V_402 -> V_294 = NULL ;
V_25 = 1 ;
} else {
while ( ( V_400 = V_402 -> V_197 ) ) {
if ( V_50 == V_400 ) {
V_402 -> V_197 = V_400 -> V_197 ;
V_400 -> V_294 = NULL ;
V_25 = 1 ;
break;
}
V_402 = V_400 ;
}
}
F_100 ( & V_5 -> V_160 , V_166 ) ;
return V_25 ;
}
static T_2 *
F_24 ( T_1 * V_12 , int V_21 )
{
T_2 * V_5 ;
unsigned long V_166 ;
int V_141 ;
V_5 = F_106 ( sizeof( * V_5 ) , V_358 | V_378 ) ;
if ( ! V_5 )
return NULL ;
F_112 ( & V_5 -> V_66 ) ;
F_162 ( & V_5 -> V_160 ) ;
F_113 ( & V_5 -> V_45 ) ;
V_5 -> V_69 = V_403 ;
V_5 -> V_173 = V_404 ;
V_5 -> V_57 = V_405 ;
V_5 -> V_176 = ( V_406 == 0 ) ?
V_12 -> V_8 -> V_177 -> V_178 : 1 ;
V_5 -> V_137 = V_407 ;
V_5 -> V_206 = V_408 ;
V_5 -> V_7 = V_12 ;
F_99 ( & V_18 , V_166 ) ;
F_163 ( & V_5 -> V_409 , & V_12 -> V_19 ) ;
F_100 ( & V_18 , V_166 ) ;
F_14 ( 3 , F_15 ( L_57 , V_5 ) ) ;
if ( F_91 ( V_347 != V_346 ) )
V_347 = V_346 ;
V_141 = F_67 ( int , V_347 ,
F_68 ( V_12 -> V_8 -> V_23 ) * 512 ) ;
F_64 ( V_5 , V_141 ) ;
F_14 ( 3 , F_15 ( L_58 ,
V_5 -> V_140 . V_141 , V_5 -> V_140 . V_277 ) ) ;
F_55 ( & V_12 -> V_319 ) ;
F_164 ( V_328 ) ;
return V_5 ;
}
static void F_165 ( struct V_290 * V_291 )
{
struct V_4 * V_5 = F_89 ( V_291 , struct V_4 , V_293 . V_291 ) ;
struct V_340 * V_12 = V_5 -> V_7 ;
while ( V_5 -> V_196 )
F_40 ( V_5 -> V_196 ) ;
if ( V_5 -> V_140 . V_141 > 0 ) {
F_14 ( 6 ,
F_15 ( L_59 ,
( int ) V_5 -> V_140 . V_141 ,
( int ) V_5 -> V_140 . V_277 ) ) ;
F_63 ( & V_5 -> V_140 ) ;
}
F_14 ( 6 ,
F_15 ( L_60 ,
V_12 -> V_43 -> V_44 ,
V_5 ) ) ;
F_35 ( V_5 ) ;
F_27 ( V_12 -> V_8 ) ;
F_28 ( V_12 ) ;
F_166 ( V_328 ) ;
}
static void V_46 ( struct V_339 * V_339 )
{
struct V_4 * V_5 = F_89 ( V_339 , struct V_4 , V_45 ) ;
struct V_340 * V_12 = V_5 -> V_7 ;
unsigned long V_166 ;
F_99 ( & V_18 , V_166 ) ;
F_167 ( & V_5 -> V_409 ) ;
F_100 ( & V_18 , V_166 ) ;
F_25 ( & V_12 -> V_37 ) ;
F_103 ( & V_5 -> V_293 . V_291 , F_165 ) ;
F_104 ( & V_5 -> V_293 . V_291 ) ;
}
static int
F_50 ( T_2 * V_5 )
{
const T_7 * V_50 ;
unsigned long V_166 ;
F_8 ( & V_5 -> V_160 , V_166 ) ;
for ( V_50 = V_5 -> V_196 ; V_50 ; V_50 = V_50 -> V_197 )
if ( V_50 -> V_373 )
break;
F_10 ( & V_5 -> V_160 , V_166 ) ;
return V_50 ? 1 : 0 ;
}
static int
F_168 ( int V_185 , void * V_164 , void * V_72 )
{
int * V_111 = V_72 ;
if ( * V_111 < V_185 )
* V_111 = V_185 ;
return 0 ;
}
static int
F_169 ( void )
{
int V_111 = - 1 ;
unsigned long V_166 ;
F_8 ( & V_18 , V_166 ) ;
F_170 ( & V_313 , F_168 , & V_111 ) ;
F_10 ( & V_18 , V_166 ) ;
return V_111 + 1 ;
}
static T_1 * F_171 ( int V_21 )
{
return F_172 ( & V_313 , V_21 ) ;
}
static T_1 * F_16 ( int V_21 )
{
struct V_340 * V_12 ;
unsigned long V_13 ;
F_8 ( & V_18 , V_13 ) ;
V_12 = F_171 ( V_21 ) ;
if ( ! V_12 )
V_12 = F_107 ( - V_30 ) ;
else if ( V_12 -> V_38 ) {
V_12 = F_107 ( - V_39 ) ;
} else
F_55 ( & V_12 -> V_319 ) ;
F_10 ( & V_18 , V_13 ) ;
return V_12 ;
}
static void F_28 ( struct V_340 * V_12 )
{
F_30 ( & V_12 -> V_319 , F_126 ) ;
}
static int
F_137 ( void )
{
int V_410 = F_173 ( V_411 ) ;
int V_111 ;
V_412 = F_174 ( V_413 , NULL ) ;
if ( ! V_412 )
return 1 ;
for ( V_111 = 0 ; V_111 < V_410 ; ++ V_111 ) {
const struct V_414 * V_415 = & V_411 [ V_111 ] ;
T_17 V_416 = V_415 -> V_417 -> V_418 ? V_419 | V_420 : V_419 ;
F_175 ( V_415 -> V_421 , V_416 , V_412 , V_415 -> V_417 ) ;
}
return 0 ;
}
static void
F_141 ( void )
{
int V_111 ;
int V_410 = F_173 ( V_411 ) ;
if ( ! V_412 )
return;
for ( V_111 = 0 ; V_111 < V_410 ; ++ V_111 )
F_176 ( V_411 [ V_111 ] . V_421 , V_412 ) ;
F_176 ( V_413 , NULL ) ;
}
static int F_177 ( struct V_422 * V_423 , void * V_424 )
{
F_178 ( V_423 , L_61 , * ( ( int * ) V_423 -> V_425 ) ) ;
return 0 ;
}
static int F_179 ( struct V_20 * V_20 , struct V_1 * V_1 )
{
return F_180 ( V_1 , F_177 , & V_363 ) ;
}
static T_3
F_181 ( struct V_1 * V_2 , const char T_4 * V_426 ,
T_5 V_48 , T_6 * V_427 )
{
int V_98 ;
unsigned long V_384 ;
if ( ! F_70 ( V_232 ) || ! F_70 ( V_233 ) )
return - V_234 ;
V_98 = F_182 ( V_426 , V_48 , 0 , & V_384 ) ;
if ( V_98 )
return V_98 ;
V_363 = V_384 ? 1 : 0 ;
return V_48 ;
}
static int F_183 ( struct V_20 * V_20 , struct V_1 * V_1 )
{
return F_180 ( V_1 , F_177 , & V_347 ) ;
}
static T_3
F_184 ( struct V_1 * V_2 , const char T_4 * V_426 ,
T_5 V_48 , T_6 * V_427 )
{
int V_98 ;
unsigned long V_111 = V_428 ;
if ( ! F_70 ( V_232 ) || ! F_70 ( V_233 ) )
return - V_234 ;
V_98 = F_182 ( V_426 , V_48 , 0 , & V_111 ) ;
if ( V_98 )
return V_98 ;
if ( V_111 <= 1048576 ) {
V_347 = V_111 ;
return V_48 ;
}
return - V_429 ;
}
static int F_185 ( struct V_422 * V_423 , void * V_424 )
{
F_178 ( V_423 , L_62 , V_210 , V_430 ,
V_431 ) ;
return 0 ;
}
static int F_186 ( struct V_20 * V_20 , struct V_1 * V_1 )
{
return F_180 ( V_1 , F_185 , NULL ) ;
}
static int F_187 ( struct V_422 * V_423 , void * V_424 )
{
F_178 ( V_423 , L_63
L_64 ) ;
return 0 ;
}
static int F_188 ( struct V_20 * V_20 , struct V_1 * V_1 )
{
return F_180 ( V_1 , F_187 , NULL ) ;
}
static void * F_189 ( struct V_422 * V_423 , T_6 * V_432 )
{
struct V_433 * V_434 = F_33 ( sizeof( * V_434 ) , V_59 ) ;
V_423 -> V_425 = V_434 ;
if ( ! V_434 )
return NULL ;
V_434 -> V_247 = * V_432 ;
V_434 -> V_435 = F_169 () ;
if ( V_434 -> V_247 >= V_434 -> V_435 )
return NULL ;
return V_434 ;
}
static void * F_190 ( struct V_422 * V_423 , void * V_424 , T_6 * V_432 )
{
struct V_433 * V_434 = V_423 -> V_425 ;
* V_432 = ++ V_434 -> V_247 ;
return ( V_434 -> V_247 < V_434 -> V_435 ) ? V_434 : NULL ;
}
static void F_191 ( struct V_422 * V_423 , void * V_424 )
{
F_35 ( V_423 -> V_425 ) ;
}
static int F_192 ( struct V_20 * V_20 , struct V_1 * V_1 )
{
return F_193 ( V_1 , & V_436 ) ;
}
static int F_194 ( struct V_422 * V_423 , void * V_424 )
{
struct V_433 * V_434 = (struct V_433 * ) V_424 ;
T_1 * V_12 ;
struct V_251 * V_312 ;
unsigned long V_166 ;
F_8 ( & V_18 , V_166 ) ;
V_12 = V_434 ? F_171 ( V_434 -> V_247 ) : NULL ;
if ( V_12 && ( V_312 = V_12 -> V_8 ) && ( ! V_12 -> V_38 ) )
F_178 ( V_423 , L_65 ,
V_312 -> V_177 -> V_183 , V_312 -> V_184 ,
V_312 -> V_185 , V_312 -> V_187 , ( int ) V_312 -> type ,
1 ,
( int ) V_312 -> V_191 ,
( int ) V_312 -> V_437 ,
( int ) F_195 ( V_312 ) ) ;
else
F_178 ( V_423 , L_66 ) ;
F_10 ( & V_18 , V_166 ) ;
return 0 ;
}
static int F_196 ( struct V_20 * V_20 , struct V_1 * V_1 )
{
return F_193 ( V_1 , & V_438 ) ;
}
static int F_197 ( struct V_422 * V_423 , void * V_424 )
{
struct V_433 * V_434 = (struct V_433 * ) V_424 ;
T_1 * V_12 ;
struct V_251 * V_312 ;
unsigned long V_166 ;
F_8 ( & V_18 , V_166 ) ;
V_12 = V_434 ? F_171 ( V_434 -> V_247 ) : NULL ;
if ( V_12 && ( V_312 = V_12 -> V_8 ) && ( ! V_12 -> V_38 ) )
F_178 ( V_423 , L_67 ,
V_312 -> V_439 , V_312 -> V_440 , V_312 -> V_441 ) ;
else
F_178 ( V_423 , L_68 ) ;
F_10 ( & V_18 , V_166 ) ;
return 0 ;
}
static void F_198 ( struct V_422 * V_423 , T_1 * V_12 )
{
int V_111 , V_442 , V_443 , V_444 , V_445 ;
T_7 * V_50 ;
T_2 * V_446 ;
const T_8 * V_52 ;
const char * V_447 ;
unsigned int V_216 ;
V_111 = 0 ;
F_129 (fp, &sdp->sfds, sfd_siblings) {
V_111 ++ ;
F_199 ( & V_446 -> V_160 ) ;
F_178 ( V_423 , L_69
L_70 , V_111 ,
F_54 ( V_446 -> V_69 ) ,
V_446 -> V_140 . V_141 ,
( int ) V_446 -> V_140 . V_277 ,
( int ) V_446 -> V_176 ) ;
F_178 ( V_423 , L_71 ,
( int ) V_446 -> V_137 , ( int ) V_446 -> V_57 ,
( int ) V_446 -> V_206 ) ;
for ( V_442 = 0 , V_50 = V_446 -> V_196 ;
V_50 != NULL ;
++ V_442 , V_50 = V_50 -> V_197 ) {
V_52 = & V_50 -> V_67 ;
V_443 = ( V_52 -> V_68 == '\0' ) ? 0 : 1 ;
if ( V_50 -> V_373 ) {
if ( V_443 &&
( V_139 & V_52 -> V_13 ) )
V_447 = L_72 ;
else
V_447 = L_73 ;
} else {
if ( V_448 & V_52 -> V_107 )
V_447 = L_74 ;
else
V_447 = L_75 ;
}
F_178 ( V_423 , V_447 ) ;
V_444 = V_50 -> V_72 . V_141 ;
V_445 = V_50 -> V_72 . V_277 ;
F_178 ( V_423 , V_50 -> V_161 ?
( ( 1 == V_50 -> V_161 ) ? L_76 : L_77 )
: L_78 ) ;
F_178 ( V_423 , L_79 ,
V_50 -> V_67 . V_64 , V_444 ) ;
if ( V_50 -> V_161 )
F_178 ( V_423 , L_80 , V_52 -> V_157 ) ;
else {
V_216 = F_54 ( V_158 ) ;
F_178 ( V_423 , L_81 ,
( V_443 ? V_52 -> V_69 :
F_54 ( V_446 -> V_69 ) ) ,
( V_216 > V_52 -> V_157 ? V_216 - V_52 -> V_157 : 0 ) ) ;
}
F_178 ( V_423 , L_82 , V_445 ,
( int ) V_50 -> V_72 . V_73 ) ;
}
if ( 0 == V_442 )
F_178 ( V_423 , L_83 ) ;
F_200 ( & V_446 -> V_160 ) ;
}
}
static int F_201 ( struct V_20 * V_20 , struct V_1 * V_1 )
{
return F_193 ( V_1 , & V_449 ) ;
}
static int F_202 ( struct V_422 * V_423 , void * V_424 )
{
struct V_433 * V_434 = (struct V_433 * ) V_424 ;
T_1 * V_12 ;
unsigned long V_166 ;
if ( V_434 && ( 0 == V_434 -> V_247 ) ) {
F_178 ( V_423 , L_84 ,
( int ) V_434 -> V_435 ) ;
F_178 ( V_423 , L_85 , V_347 ) ;
}
F_8 ( & V_18 , V_166 ) ;
V_12 = V_434 ? F_171 ( V_434 -> V_247 ) : NULL ;
if ( V_12 && ! F_9 ( & V_12 -> V_19 ) ) {
struct V_251 * V_312 = V_12 -> V_8 ;
F_178 ( V_423 , L_86 , V_12 -> V_43 -> V_44 ) ;
if ( V_12 -> V_38 )
F_178 ( V_423 , L_87 ) ;
else
F_178
( V_423 , L_88 ,
V_312 -> V_177 -> V_183 ,
V_312 -> V_184 , V_312 -> V_185 ,
V_312 -> V_187 ,
V_312 -> V_177 -> V_220 -> V_221 ) ;
F_178 ( V_423 , L_89 ,
V_12 -> V_41 , F_3 ( V_12 ) ) ;
F_198 ( V_423 , V_12 ) ;
}
F_10 ( & V_18 , V_166 ) ;
return 0 ;
}
