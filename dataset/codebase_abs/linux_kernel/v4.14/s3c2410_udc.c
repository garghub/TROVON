static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_3 , T_1 V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static inline void F_5 ( void T_2 * V_4 , T_1 V_3 , T_1 V_1 )
{
F_4 ( V_3 , V_4 + V_1 ) ;
}
static void F_6 ( int V_5 , const char * V_6 , ... )
{
static long V_7 ;
static int V_8 ;
struct V_9 V_10 ;
T_3 args ;
if ( V_5 > V_11 )
return;
va_start ( args , V_6 ) ;
V_10 . V_6 = V_6 ;
V_10 . V_12 = & args ;
if ( V_13 != V_7 ) {
V_7 = V_13 ;
V_8 = 0 ;
}
F_7 ( L_1 , V_7 , V_8 ++ , & V_10 ) ;
va_end ( args ) ;
}
static void F_6 ( int V_5 , const char * V_6 , ... )
{
}
static int F_8 ( struct V_14 * V_15 , void * V_16 )
{
T_1 V_17 , V_18 , V_19 , V_20 ;
T_1 V_21 , V_22 , V_23 ;
T_1 V_24 , V_25 , V_26 , V_27 ;
T_1 V_28 , V_29 , V_30 , V_31 ;
V_17 = F_1 ( V_32 ) ;
V_18 = F_1 ( V_33 ) ;
V_19 = F_1 ( V_34 ) ;
V_20 = F_1 ( V_35 ) ;
V_21 = F_1 ( V_36 ) ;
V_22 = F_1 ( V_37 ) ;
F_3 ( 0 , V_38 ) ;
V_23 = F_1 ( V_39 ) ;
F_3 ( 1 , V_38 ) ;
V_24 = F_1 ( V_39 ) ;
V_25 = F_1 ( V_40 ) ;
V_26 = F_1 ( V_39 ) ;
V_27 = F_1 ( V_40 ) ;
F_3 ( 2 , V_38 ) ;
V_28 = F_1 ( V_39 ) ;
V_29 = F_1 ( V_40 ) ;
V_30 = F_1 ( V_39 ) ;
V_31 = F_1 ( V_40 ) ;
F_9 ( V_15 , L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ,
V_17 , V_18 , V_19 , V_20 ,
V_21 , V_22 , V_23 ,
V_24 , V_25 , V_26 , V_27 ,
V_28 , V_29 , V_30 , V_31
) ;
return 0 ;
}
static int F_10 ( struct V_41 * V_41 ,
struct V_42 * V_42 )
{
return F_11 ( V_42 , F_8 , NULL ) ;
}
static inline void F_12 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_44 ,
V_45 ) ;
}
static inline void F_13 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_4 ( 0x00 , V_4 + V_45 ) ;
}
static inline void F_14 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_46 , V_45 ) ;
}
static inline void F_15 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_47 , V_45 ) ;
}
static inline void F_16 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_48 , V_45 ) ;
}
inline void F_17 ( void T_2 * V_49 )
{
F_5 ( V_49 , V_43 , V_38 ) ;
F_5 ( V_49 , V_50 , V_45 ) ;
}
static inline void F_18 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , ( V_44
| V_48 ) ,
V_45 ) ;
}
static inline void F_19 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , ( V_47
| V_48 ) ,
V_45 ) ;
}
static void F_20 ( struct V_51 * V_52 ,
struct V_53 * V_54 , int V_55 )
{
unsigned V_56 = V_52 -> V_56 ;
F_21 ( & V_54 -> V_57 ) ;
if ( F_22 ( V_54 -> V_54 . V_55 == - V_58 ) )
V_54 -> V_54 . V_55 = V_55 ;
else
V_55 = V_54 -> V_54 . V_55 ;
V_52 -> V_56 = 1 ;
F_23 ( & V_52 -> V_52 , & V_54 -> V_54 ) ;
V_52 -> V_56 = V_56 ;
}
static void F_24 ( struct V_59 * V_60 ,
struct V_51 * V_52 , int V_55 )
{
if ( & V_52 -> V_57 == NULL )
return;
while ( ! F_25 ( & V_52 -> V_57 ) ) {
struct V_53 * V_54 ;
V_54 = F_26 ( V_52 -> V_57 . V_61 , struct V_53 ,
V_57 ) ;
F_20 ( V_52 , V_54 , V_55 ) ;
}
}
static inline int F_27 ( void )
{
int V_62 ;
V_62 = F_1 ( V_63 ) << 8 ;
V_62 |= F_1 ( V_64 ) ;
return V_62 ;
}
static inline int F_28 ( int V_65 ,
struct V_53 * V_54 ,
unsigned V_66 )
{
unsigned V_67 = F_29 ( V_54 -> V_54 . V_68 - V_54 -> V_54 . V_69 , V_66 ) ;
T_4 * V_70 = V_54 -> V_54 . V_70 + V_54 -> V_54 . V_69 ;
F_30 ( V_70 ) ;
F_6 ( V_71 , L_17 , V_72 ,
V_54 -> V_54 . V_69 , V_54 -> V_54 . V_68 , V_67 , V_54 -> V_54 . V_69 + V_67 ) ;
V_54 -> V_54 . V_69 += V_67 ;
F_31 ( 5 ) ;
F_32 ( V_2 + V_65 , V_70 , V_67 ) ;
return V_67 ;
}
static int F_33 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
unsigned V_73 ;
int V_74 ;
T_1 V_75 ;
int V_76 ;
T_1 V_77 ;
V_75 = V_52 -> V_78 & 0x7F ;
switch ( V_75 ) {
default:
V_75 = 0 ;
case 0 :
V_76 = V_79 ;
break;
case 1 :
V_76 = V_80 ;
break;
case 2 :
V_76 = V_81 ;
break;
case 3 :
V_76 = V_82 ;
break;
case 4 :
V_76 = V_83 ;
break;
}
V_73 = F_28 ( V_76 , V_54 , V_52 -> V_52 . V_84 ) ;
if ( V_73 != V_52 -> V_52 . V_84 )
V_74 = 1 ;
else if ( V_54 -> V_54 . V_68 != V_54 -> V_54 . V_69 || V_54 -> V_54 . V_85 )
V_74 = 0 ;
else
V_74 = 2 ;
if ( V_75 == 0 )
F_6 ( V_86 ,
L_18 ,
V_75 , V_73 , V_54 -> V_54 . V_69 , V_54 -> V_54 . V_68 ,
V_74 , V_54 -> V_54 . V_85 ) ;
if ( V_74 ) {
if ( V_75 == 0 ) {
if ( ! ( F_1 ( V_35 )
& V_87 ) )
F_19 ( V_2 ) ;
V_52 -> V_88 -> V_89 = V_90 ;
} else {
F_3 ( V_75 , V_38 ) ;
V_77 = F_1 ( V_39 ) ;
F_3 ( V_75 , V_38 ) ;
F_3 ( V_77 | V_91 ,
V_39 ) ;
}
F_20 ( V_52 , V_54 , 0 ) ;
V_74 = 1 ;
} else {
if ( V_75 == 0 ) {
if ( ! ( F_1 ( V_35 )
& V_87 ) )
F_15 ( V_2 ) ;
} else {
F_3 ( V_75 , V_38 ) ;
V_77 = F_1 ( V_39 ) ;
F_3 ( V_75 , V_38 ) ;
F_3 ( V_77 | V_91 ,
V_39 ) ;
}
}
return V_74 ;
}
static inline int F_34 ( int V_65 , T_4 * V_70 ,
struct V_53 * V_54 , unsigned V_92 )
{
unsigned V_67 ;
V_67 = F_29 ( V_54 -> V_54 . V_68 - V_54 -> V_54 . V_69 , V_92 ) ;
V_54 -> V_54 . V_69 += V_67 ;
F_35 ( V_65 + V_2 , V_70 , V_67 ) ;
return V_67 ;
}
static int F_36 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
T_4 * V_70 ;
T_1 V_77 ;
unsigned V_93 ;
int V_74 = 1 ;
unsigned V_92 ;
int V_94 = 0 ;
T_1 V_75 ;
int V_76 ;
V_75 = V_52 -> V_78 & 0x7F ;
switch ( V_75 ) {
default:
V_75 = 0 ;
case 0 :
V_76 = V_79 ;
break;
case 1 :
V_76 = V_80 ;
break;
case 2 :
V_76 = V_81 ;
break;
case 3 :
V_76 = V_82 ;
break;
case 4 :
V_76 = V_83 ;
break;
}
if ( ! V_54 -> V_54 . V_68 )
return 1 ;
V_70 = V_54 -> V_54 . V_70 + V_54 -> V_54 . V_69 ;
V_93 = V_54 -> V_54 . V_68 - V_54 -> V_54 . V_69 ;
if ( ! V_93 ) {
F_6 ( V_86 , L_19 , V_72 ) ;
return - 1 ;
}
F_3 ( V_75 , V_38 ) ;
V_94 = F_27 () ;
F_6 ( V_86 , L_20 , V_72 , V_94 ) ;
if ( V_94 > V_52 -> V_52 . V_84 )
V_92 = V_52 -> V_52 . V_84 ;
else
V_92 = V_94 ;
V_94 = F_34 ( V_76 , V_70 , V_54 , V_92 ) ;
if ( V_75 != 0 && V_94 < V_52 -> V_52 . V_84 ) {
V_74 = 1 ;
if ( V_94 != V_92 )
V_54 -> V_54 . V_55 = - V_95 ;
} else {
V_74 = ( V_54 -> V_54 . V_68 <= V_54 -> V_54 . V_69 ) ? 1 : 0 ;
}
F_3 ( V_75 , V_38 ) ;
V_94 = F_27 () ;
if ( V_75 == 0 )
F_6 ( V_71 , L_21 ,
V_72 , V_94 , V_74 ) ;
if ( V_74 ) {
if ( V_75 == 0 ) {
F_18 ( V_2 ) ;
V_52 -> V_88 -> V_89 = V_90 ;
} else {
F_3 ( V_75 , V_38 ) ;
V_77 = F_1 ( V_96 ) ;
F_3 ( V_75 , V_38 ) ;
F_3 ( V_77 & ~ V_97 ,
V_96 ) ;
}
F_20 ( V_52 , V_54 , 0 ) ;
} else {
if ( V_75 == 0 ) {
F_12 ( V_2 ) ;
} else {
F_3 ( V_75 , V_38 ) ;
V_77 = F_1 ( V_96 ) ;
F_3 ( V_75 , V_38 ) ;
F_3 ( V_77 & ~ V_97 ,
V_96 ) ;
}
}
return V_74 ;
}
static int F_37 ( struct V_98 * V_99 )
{
unsigned char * V_100 = ( unsigned char * ) V_99 ;
int V_101 = 0 ;
F_3 ( 0 , V_38 ) ;
V_101 = F_27 () ;
F_6 ( V_86 , L_22 , V_72 , V_101 ) ;
if ( V_101 > sizeof( struct V_98 ) )
V_101 = sizeof( struct V_98 ) ;
F_35 ( V_79 + V_2 , V_100 , V_101 ) ;
F_6 ( V_71 , L_23 , V_72 ,
V_101 , V_99 -> V_102 , V_99 -> V_103 ,
V_99 -> V_104 , V_99 -> V_105 , V_99 -> V_106 ) ;
return V_101 ;
}
static int F_38 ( struct V_59 * V_88 ,
struct V_98 * V_99 )
{
T_5 V_55 = 0 ;
T_4 V_107 = V_99 -> V_105 & 0x7F ;
T_4 V_108 = V_99 -> V_105 & V_109 ;
switch ( V_99 -> V_103 & V_110 ) {
case V_111 :
break;
case V_112 :
V_55 = V_88 -> V_113 ;
break;
case V_114 :
if ( V_107 > 4 || V_99 -> V_106 > 2 )
return 1 ;
if ( V_107 == 0 ) {
F_3 ( 0 , V_38 ) ;
V_55 = F_1 ( V_39 ) ;
V_55 = V_55 & V_50 ;
} else {
F_3 ( V_107 , V_38 ) ;
if ( V_108 ) {
V_55 = F_1 ( V_39 ) ;
V_55 = V_55 & V_115 ;
} else {
V_55 = F_1 ( V_96 ) ;
V_55 = V_55 & V_116 ;
}
}
V_55 = V_55 ? 1 : 0 ;
break;
default:
return 1 ;
}
F_31 ( 5 ) ;
F_3 ( V_55 & 0xFF , V_79 ) ;
F_3 ( V_55 >> 8 , V_79 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static void F_39 ( struct V_59 * V_88 ,
struct V_51 * V_52 ,
struct V_98 * V_99 ,
T_1 V_117 )
{
int V_67 , V_118 , V_62 ;
if ( ! ( V_117 & V_119 ) )
return;
F_24 ( V_88 , V_52 , - V_120 ) ;
V_67 = F_37 ( V_99 ) ;
if ( V_67 != sizeof( * V_99 ) ) {
F_6 ( V_86 , L_24
L_25 ,
sizeof( * V_99 ) , V_67 ) ;
F_17 ( V_2 ) ;
return;
}
F_6 ( V_86 , L_26 ,
V_99 -> V_102 , V_99 -> V_103 , V_99 -> V_106 ) ;
V_88 -> V_121 = ( V_99 -> V_103 & V_122 )
== V_123 ;
V_88 -> V_124 = 0 ;
V_88 -> V_125 = 1 ;
switch ( V_99 -> V_102 ) {
case V_126 :
F_6 ( V_86 , L_27 ) ;
if ( V_99 -> V_103 == V_112 ) {
V_88 -> V_124 = 1 ;
F_18 ( V_2 ) ;
}
break;
case V_127 :
F_6 ( V_86 , L_28 ) ;
if ( V_99 -> V_103 == V_111 ) {
V_88 -> V_124 = 1 ;
F_18 ( V_2 ) ;
}
break;
case V_128 :
F_6 ( V_86 , L_29 ) ;
if ( V_99 -> V_103 == V_112 ) {
V_62 = V_99 -> V_104 & 0x7F ;
V_88 -> V_129 = V_62 ;
F_3 ( ( V_62 | V_130 ) ,
V_32 ) ;
F_18 ( V_2 ) ;
return;
}
break;
case V_131 :
F_6 ( V_86 , L_30 ) ;
F_12 ( V_2 ) ;
if ( V_88 -> V_121 ) {
if ( ! F_38 ( V_88 , V_99 ) )
return;
}
break;
case V_132 :
F_12 ( V_2 ) ;
if ( V_99 -> V_103 != V_114 )
break;
if ( V_99 -> V_104 != V_133 || V_99 -> V_106 != 0 )
break;
F_40 ( & V_88 -> V_52 [ V_99 -> V_105 & 0x7f ] . V_52 , 0 ) ;
F_18 ( V_2 ) ;
return;
case V_134 :
F_12 ( V_2 ) ;
if ( V_99 -> V_103 != V_114 )
break;
if ( V_99 -> V_104 != V_133 || V_99 -> V_106 != 0 )
break;
F_40 ( & V_88 -> V_52 [ V_99 -> V_105 & 0x7f ] . V_52 , 1 ) ;
F_18 ( V_2 ) ;
return;
default:
F_12 ( V_2 ) ;
break;
}
if ( V_99 -> V_103 & V_109 )
V_88 -> V_89 = V_135 ;
else
V_88 -> V_89 = V_136 ;
if ( ! V_88 -> V_137 )
return;
V_118 = V_88 -> V_137 -> V_138 ( & V_88 -> V_139 , V_99 ) ;
if ( V_118 < 0 ) {
if ( V_88 -> V_124 ) {
F_6 ( V_86 , L_31 ,
V_99 -> V_102 , V_118 ) ;
return;
}
if ( V_118 == - V_140 )
F_6 ( V_86 , L_32 ) ;
else
F_6 ( V_86 ,
L_33 , V_118 ) ;
F_31 ( 5 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_88 -> V_89 = V_90 ;
} else if ( V_88 -> V_125 ) {
F_6 ( V_71 , L_34 ) ;
V_88 -> V_125 = 0 ;
}
F_6 ( V_71 , L_35 , V_141 [ V_88 -> V_89 ] ) ;
}
static void F_41 ( struct V_59 * V_88 )
{
T_1 V_117 ;
struct V_51 * V_52 = & V_88 -> V_52 [ 0 ] ;
struct V_53 * V_54 ;
struct V_98 V_99 ;
if ( F_25 ( & V_52 -> V_57 ) )
V_54 = NULL ;
else
V_54 = F_26 ( V_52 -> V_57 . V_61 , struct V_53 , V_57 ) ;
F_3 ( 0 , V_38 ) ;
V_117 = F_1 ( V_39 ) ;
F_6 ( V_86 , L_36 ,
V_117 , V_141 [ V_88 -> V_89 ] ) ;
if ( V_117 & V_142 ) {
F_24 ( V_88 , V_52 , - V_143 ) ;
F_6 ( V_86 , L_37 ) ;
F_13 ( V_2 ) ;
V_88 -> V_89 = V_90 ;
return;
}
if ( V_117 & V_144 ) {
F_6 ( V_86 , L_38 ) ;
F_24 ( V_88 , V_52 , 0 ) ;
F_14 ( V_2 ) ;
V_88 -> V_89 = V_90 ;
}
switch ( V_88 -> V_89 ) {
case V_90 :
F_39 ( V_88 , V_52 , & V_99 , V_117 ) ;
break;
case V_135 :
F_6 ( V_86 , L_39 ) ;
if ( ! ( V_117 & V_47 ) && V_54 )
F_33 ( V_52 , V_54 ) ;
break;
case V_136 :
F_6 ( V_86 , L_40 ) ;
if ( ( V_117 & V_119 ) && V_54 )
F_36 ( V_52 , V_54 ) ;
break;
case V_145 :
F_6 ( V_86 , L_41 ) ;
V_88 -> V_89 = V_90 ;
break;
case V_146 :
F_6 ( V_86 , L_42 ) ;
V_88 -> V_89 = V_90 ;
break;
}
}
static void F_42 ( struct V_51 * V_52 )
{
struct V_53 * V_54 ;
int V_108 = V_52 -> V_78 & V_109 ;
T_1 V_147 ;
T_1 V_75 ;
if ( F_22 ( ! F_25 ( & V_52 -> V_57 ) ) )
V_54 = F_26 ( V_52 -> V_57 . V_61 ,
struct V_53 , V_57 ) ;
else
V_54 = NULL ;
V_75 = V_52 -> V_78 & 0x7F ;
if ( V_108 ) {
F_3 ( V_75 , V_38 ) ;
V_147 = F_1 ( V_39 ) ;
F_6 ( V_71 , L_43 ,
V_75 , V_147 , V_54 ? 1 : 0 ) ;
if ( V_147 & V_148 ) {
F_6 ( V_71 , L_44 ) ;
F_3 ( V_75 , V_38 ) ;
F_3 ( V_147 & ~ V_148 ,
V_39 ) ;
return;
}
if ( ! ( V_147 & V_91 ) && V_54 )
F_33 ( V_52 , V_54 ) ;
} else {
F_3 ( V_75 , V_38 ) ;
V_147 = F_1 ( V_96 ) ;
F_6 ( V_71 , L_45 , V_75 , V_147 ) ;
if ( V_147 & V_149 ) {
F_3 ( V_75 , V_38 ) ;
F_3 ( V_147 & ~ V_149 ,
V_96 ) ;
return;
}
if ( ( V_147 & V_97 ) && V_54 )
F_36 ( V_52 , V_54 ) ;
}
}
static T_6 F_43 ( int V_150 , void * V_151 )
{
struct V_59 * V_88 = V_151 ;
int V_152 ;
int V_153 ;
int V_18 ;
int V_117 ;
int V_154 ;
T_1 V_75 , V_155 ;
unsigned long V_156 ;
F_44 ( & V_88 -> V_157 , V_156 ) ;
if ( ! V_88 -> V_137 ) {
F_3 ( F_1 ( V_35 ) ,
V_35 ) ;
F_3 ( F_1 ( V_34 ) ,
V_34 ) ;
}
V_75 = F_1 ( V_38 ) ;
V_152 = F_1 ( V_35 ) ;
V_153 = F_1 ( V_34 ) ;
V_18 = F_1 ( V_33 ) ;
F_5 ( V_2 , V_43 , V_38 ) ;
V_117 = F_1 ( V_39 ) ;
F_6 ( V_86 , L_46 ,
V_152 , V_153 , V_18 , V_117 ) ;
if ( V_152 & V_87 ) {
F_6 ( V_86 , L_47 ,
V_117 , V_18 ) ;
V_88 -> V_139 . V_158 = V_159 ;
F_3 ( 0x00 , V_38 ) ;
F_3 ( ( V_88 -> V_52 [ 0 ] . V_52 . V_84 & 0x7ff ) >> 3 ,
V_160 ) ;
V_88 -> V_129 = 0 ;
V_88 -> V_89 = V_90 ;
V_88 -> V_139 . V_158 = V_161 ;
F_3 ( V_87 ,
V_35 ) ;
F_3 ( V_75 , V_38 ) ;
F_45 ( & V_88 -> V_157 , V_156 ) ;
return V_162 ;
}
if ( V_152 & V_163 ) {
F_6 ( V_86 , L_48 ) ;
F_3 ( V_163 ,
V_35 ) ;
if ( V_88 -> V_139 . V_158 != V_159
&& V_88 -> V_137
&& V_88 -> V_137 -> V_164 )
V_88 -> V_137 -> V_164 ( & V_88 -> V_139 ) ;
}
if ( V_152 & V_165 ) {
F_6 ( V_86 , L_49 ) ;
F_3 ( V_165 ,
V_35 ) ;
if ( V_88 -> V_139 . V_158 != V_159
&& V_88 -> V_137
&& V_88 -> V_137 -> V_166 )
V_88 -> V_137 -> V_166 ( & V_88 -> V_139 ) ;
V_88 -> V_89 = V_90 ;
}
if ( V_153 & V_167 ) {
F_6 ( V_71 , L_50 ) ;
F_3 ( V_167 , V_34 ) ;
F_41 ( V_88 ) ;
}
for ( V_154 = 1 ; V_154 < V_168 ; V_154 ++ ) {
T_1 V_62 = 1 << V_154 ;
if ( V_153 & V_62 ) {
F_6 ( V_71 , L_51 , V_154 ) ;
F_3 ( V_62 , V_34 ) ;
F_42 ( & V_88 -> V_52 [ V_154 ] ) ;
}
}
if ( ! V_152 && ! V_153 && ! V_18 && ! V_117 ) {
for ( V_154 = 1 ; V_154 < V_168 ; V_154 ++ ) {
V_155 = F_1 ( V_38 ) ;
F_3 ( V_154 , V_38 ) ;
if ( F_1 ( V_96 ) & 0x1 )
F_42 ( & V_88 -> V_52 [ V_154 ] ) ;
F_3 ( V_155 , V_38 ) ;
}
}
F_6 ( V_71 , L_52 , V_169 ) ;
F_3 ( V_75 , V_38 ) ;
F_45 ( & V_88 -> V_157 , V_156 ) ;
return V_162 ;
}
static inline struct V_51 * F_46 ( struct V_170 * V_52 )
{
return F_47 ( V_52 , struct V_51 , V_52 ) ;
}
static inline struct V_59 * F_48 ( struct V_171 * V_139 )
{
return F_47 ( V_139 , struct V_59 , V_139 ) ;
}
static inline struct V_53 * F_49 ( struct V_172 * V_54 )
{
return F_47 ( V_54 , struct V_53 , V_54 ) ;
}
static int F_50 ( struct V_170 * V_173 ,
const struct V_174 * V_175 )
{
struct V_59 * V_88 ;
struct V_51 * V_52 ;
T_1 V_66 , V_62 ;
unsigned long V_156 ;
T_1 V_176 , V_177 ;
T_1 V_178 ;
V_52 = F_46 ( V_173 ) ;
if ( ! V_173 || ! V_175
|| V_173 -> V_179 == V_180
|| V_175 -> V_181 != V_182 )
return - V_183 ;
V_88 = V_52 -> V_88 ;
if ( ! V_88 -> V_137 || V_88 -> V_139 . V_158 == V_159 )
return - V_184 ;
V_66 = F_51 ( V_175 ) ;
F_52 ( V_156 ) ;
V_173 -> V_84 = V_66 ;
V_52 -> V_52 . V_175 = V_175 ;
V_52 -> V_56 = 0 ;
V_52 -> V_78 = V_175 -> V_78 ;
F_3 ( V_52 -> V_185 , V_38 ) ;
F_3 ( V_66 >> 3 , V_160 ) ;
if ( V_175 -> V_78 & V_109 ) {
V_176 = V_186 | V_187 ;
V_177 = V_188 | V_189 ;
F_3 ( V_52 -> V_185 , V_38 ) ;
F_3 ( V_176 , V_39 ) ;
F_3 ( V_52 -> V_185 , V_38 ) ;
F_3 ( V_177 , V_40 ) ;
} else {
V_176 = V_187 ;
V_177 = V_189 ;
F_3 ( V_52 -> V_185 , V_38 ) ;
F_3 ( V_176 , V_39 ) ;
F_3 ( V_52 -> V_185 , V_38 ) ;
F_3 ( V_177 , V_40 ) ;
V_176 = V_190 | V_191 ;
V_177 = V_192 ;
F_3 ( V_52 -> V_185 , V_38 ) ;
F_3 ( V_176 , V_96 ) ;
F_3 ( V_52 -> V_185 , V_38 ) ;
F_3 ( V_177 , V_193 ) ;
}
V_178 = F_1 ( V_36 ) ;
F_3 ( V_178 | ( 1 << V_52 -> V_185 ) , V_36 ) ;
V_62 = V_175 -> V_78 ;
F_6 ( V_86 , L_53 ,
V_173 -> V_179 , V_52 -> V_185 , V_62 ,
V_175 -> V_78 & V_109 ? L_54 : L_55 , V_66 ) ;
F_53 ( V_156 ) ;
F_40 ( V_173 , 0 ) ;
return 0 ;
}
static int F_54 ( struct V_170 * V_173 )
{
struct V_51 * V_52 = F_46 ( V_173 ) ;
unsigned long V_156 ;
T_1 V_178 ;
if ( ! V_173 || ! V_52 -> V_52 . V_175 ) {
F_6 ( V_86 , L_56 ,
V_173 ? V_52 -> V_52 . V_179 : NULL ) ;
return - V_183 ;
}
F_52 ( V_156 ) ;
F_6 ( V_86 , L_57 , V_173 -> V_179 ) ;
V_52 -> V_52 . V_175 = NULL ;
V_52 -> V_56 = 1 ;
F_24 ( V_52 -> V_88 , V_52 , - V_184 ) ;
V_178 = F_1 ( V_36 ) ;
F_3 ( V_178 & ~ ( 1 << V_52 -> V_185 ) , V_36 ) ;
F_53 ( V_156 ) ;
F_6 ( V_86 , L_58 , V_173 -> V_179 ) ;
return 0 ;
}
static struct V_172 *
F_55 ( struct V_170 * V_173 , T_7 V_194 )
{
struct V_53 * V_54 ;
F_6 ( V_71 , L_59 , V_72 , V_173 , V_194 ) ;
if ( ! V_173 )
return NULL ;
V_54 = F_56 ( sizeof( struct V_53 ) , V_194 ) ;
if ( ! V_54 )
return NULL ;
F_57 ( & V_54 -> V_57 ) ;
return & V_54 -> V_54 ;
}
static void
F_58 ( struct V_170 * V_173 , struct V_172 * V_195 )
{
struct V_51 * V_52 = F_46 ( V_173 ) ;
struct V_53 * V_54 = F_49 ( V_195 ) ;
F_6 ( V_71 , L_60 , V_72 , V_173 , V_195 ) ;
if ( ! V_52 || ! V_195 || ( ! V_52 -> V_52 . V_175 && V_173 -> V_179 != V_180 ) )
return;
F_59 ( ! F_25 ( & V_54 -> V_57 ) ) ;
F_60 ( V_54 ) ;
}
static int F_61 ( struct V_170 * V_173 , struct V_172 * V_195 ,
T_7 V_196 )
{
struct V_53 * V_54 = F_49 ( V_195 ) ;
struct V_51 * V_52 = F_46 ( V_173 ) ;
struct V_59 * V_88 ;
T_1 V_77 = 0 ;
int V_94 = 0 ;
unsigned long V_156 ;
if ( F_62 ( ! V_173 || ( ! V_52 -> V_52 . V_175 && V_52 -> V_52 . V_179 != V_180 ) ) ) {
F_6 ( V_86 , L_61 , V_72 ) ;
return - V_183 ;
}
V_88 = V_52 -> V_88 ;
if ( F_62 ( ! V_88 -> V_137
|| V_88 -> V_139 . V_158 == V_159 ) ) {
return - V_184 ;
}
F_52 ( V_156 ) ;
if ( F_62 ( ! V_195 || ! V_195 -> V_197
|| ! V_195 -> V_70 || ! F_25 ( & V_54 -> V_57 ) ) ) {
if ( ! V_195 )
F_6 ( V_86 , L_62 , V_72 ) ;
else {
F_6 ( V_86 , L_63 ,
V_72 , ! V_195 -> V_197 , ! V_195 -> V_70 ,
! F_25 ( & V_54 -> V_57 ) ) ;
}
F_53 ( V_156 ) ;
return - V_183 ;
}
V_195 -> V_55 = - V_58 ;
V_195 -> V_69 = 0 ;
F_6 ( V_71 , L_64 ,
V_72 , V_52 -> V_78 , V_195 -> V_68 ) ;
if ( V_52 -> V_78 ) {
F_3 ( V_52 -> V_78 & 0x7F , V_38 ) ;
V_77 = F_1 ( ( V_52 -> V_78 & V_109 )
? V_39
: V_96 ) ;
V_94 = F_27 () ;
} else {
F_3 ( 0 , V_38 ) ;
V_77 = F_1 ( V_39 ) ;
V_94 = F_27 () ;
}
if ( F_25 ( & V_52 -> V_57 ) && ! V_52 -> V_56 ) {
if ( V_52 -> V_78 == 0 ) {
switch ( V_88 -> V_89 ) {
case V_135 :
if ( ! ( V_77 & V_47 )
&& F_33 ( V_52 ,
V_54 ) ) {
V_88 -> V_89 = V_90 ;
V_54 = NULL ;
}
break;
case V_136 :
if ( ( ! V_195 -> V_68 )
|| ( ( V_77 & V_97 )
&& F_36 ( V_52 ,
V_54 ) ) ) {
V_88 -> V_89 = V_90 ;
V_54 = NULL ;
}
break;
default:
F_53 ( V_156 ) ;
return - V_198 ;
}
} else if ( ( V_52 -> V_78 & V_109 ) != 0
&& ( ! ( V_77 & V_97 ) )
&& F_33 ( V_52 , V_54 ) ) {
V_54 = NULL ;
} else if ( ( V_77 & V_97 )
&& V_94
&& F_36 ( V_52 , V_54 ) ) {
V_54 = NULL ;
}
}
if ( F_22 ( V_54 ) )
F_63 ( & V_54 -> V_57 , & V_52 -> V_57 ) ;
F_53 ( V_156 ) ;
F_6 ( V_71 , L_65 , V_72 ) ;
return 0 ;
}
static int F_64 ( struct V_170 * V_173 , struct V_172 * V_195 )
{
struct V_51 * V_52 = F_46 ( V_173 ) ;
struct V_59 * V_60 ;
int V_199 = - V_183 ;
unsigned long V_156 ;
struct V_53 * V_54 = NULL ;
F_6 ( V_71 , L_60 , V_72 , V_173 , V_195 ) ;
if ( ! V_200 -> V_137 )
return - V_184 ;
if ( ! V_173 || ! V_195 )
return V_199 ;
V_60 = F_48 ( V_52 -> V_139 ) ;
F_52 ( V_156 ) ;
F_65 (req, &ep->queue, queue) {
if ( & V_54 -> V_54 == V_195 ) {
F_21 ( & V_54 -> V_57 ) ;
V_195 -> V_55 = - V_201 ;
V_199 = 0 ;
break;
}
}
if ( V_199 == 0 ) {
F_6 ( V_71 ,
L_66 ,
V_54 , V_173 -> V_179 , V_195 -> V_68 , V_195 -> V_70 ) ;
F_20 ( V_52 , V_54 , - V_201 ) ;
}
F_53 ( V_156 ) ;
return V_199 ;
}
static int F_40 ( struct V_170 * V_173 , int V_3 )
{
struct V_51 * V_52 = F_46 ( V_173 ) ;
T_1 V_77 = 0 ;
unsigned long V_156 ;
T_1 V_75 ;
if ( F_62 ( ! V_173 || ( ! V_52 -> V_52 . V_175 && V_52 -> V_52 . V_179 != V_180 ) ) ) {
F_6 ( V_86 , L_67 , V_72 ) ;
return - V_183 ;
}
F_52 ( V_156 ) ;
V_75 = V_52 -> V_78 & 0x7F ;
if ( V_75 == 0 ) {
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
} else {
F_3 ( V_75 , V_38 ) ;
V_77 = F_1 ( ( V_52 -> V_78 & V_109 )
? V_39
: V_96 ) ;
if ( ( V_52 -> V_78 & V_109 ) != 0 ) {
if ( V_3 )
F_3 ( V_77 | V_115 ,
V_39 ) ;
else {
V_77 &= ~ V_115 ;
F_3 ( V_77 , V_39 ) ;
V_77 |= V_187 ;
F_3 ( V_77 , V_39 ) ;
}
} else {
if ( V_3 )
F_3 ( V_77 | V_116 ,
V_96 ) ;
else {
V_77 &= ~ V_116 ;
F_3 ( V_77 , V_96 ) ;
V_77 |= V_191 ;
F_3 ( V_77 , V_96 ) ;
}
}
}
V_52 -> V_56 = V_3 ? 1 : 0 ;
F_53 ( V_156 ) ;
return 0 ;
}
static int F_66 ( struct V_171 * V_202 )
{
int V_62 ;
F_6 ( V_71 , L_68 , V_72 ) ;
V_62 = F_1 ( V_203 ) << 8 ;
V_62 |= F_1 ( V_204 ) ;
return V_62 ;
}
static int F_67 ( struct V_171 * V_202 )
{
F_6 ( V_86 , L_68 , V_72 ) ;
return 0 ;
}
static int F_68 ( struct V_171 * V_139 , int V_3 )
{
struct V_59 * V_60 = F_48 ( V_139 ) ;
F_6 ( V_86 , L_68 , V_72 ) ;
V_139 -> V_205 = ( V_3 != 0 ) ;
if ( V_3 )
V_60 -> V_113 |= ( 1 << V_206 ) ;
else
V_60 -> V_113 &= ~ ( 1 << V_206 ) ;
return 0 ;
}
static int F_69 ( struct V_59 * V_60 , int V_207 )
{
F_6 ( V_86 , L_68 , V_72 ) ;
if ( V_208 && ( V_208 -> V_209 ||
F_70 ( V_208 -> V_210 ) ) ) {
if ( V_207 )
F_71 ( V_60 ) ;
else {
if ( V_60 -> V_139 . V_158 != V_159 ) {
if ( V_60 -> V_137 && V_60 -> V_137 -> V_211 )
V_60 -> V_137 -> V_211 ( & V_60 -> V_139 ) ;
}
F_72 ( V_60 ) ;
}
} else {
return - V_140 ;
}
return 0 ;
}
static int F_73 ( struct V_171 * V_139 , int V_212 )
{
struct V_59 * V_60 = F_48 ( V_139 ) ;
F_6 ( V_86 , L_68 , V_72 ) ;
V_60 -> V_213 = ( V_212 != 0 ) ;
F_69 ( V_60 , V_212 ) ;
return 0 ;
}
static int F_74 ( struct V_171 * V_139 , int V_207 )
{
struct V_59 * V_60 = F_48 ( V_139 ) ;
F_6 ( V_86 , L_68 , V_72 ) ;
F_69 ( V_60 , V_207 ) ;
return 0 ;
}
static T_6 F_75 ( int V_214 , void * V_151 )
{
struct V_59 * V_88 = V_151 ;
unsigned int V_3 ;
F_6 ( V_86 , L_68 , V_72 ) ;
V_3 = F_76 ( V_208 -> V_215 ) ? 1 : 0 ;
if ( V_208 -> V_216 )
V_3 = ! V_3 ;
if ( V_3 != V_88 -> V_213 )
F_73 ( & V_88 -> V_139 , V_3 ) ;
return V_162 ;
}
static int F_77 ( struct V_171 * V_202 , unsigned V_217 )
{
F_6 ( V_86 , L_68 , V_72 ) ;
if ( V_208 && V_208 -> V_218 ) {
V_208 -> V_218 ( V_217 ) ;
return 0 ;
}
return - V_219 ;
}
static void F_78 ( enum V_220 V_221 )
{
if ( ! V_208 )
return;
if ( V_208 -> V_209 ) {
V_208 -> V_209 ( V_221 ) ;
} else if ( F_70 ( V_208 -> V_210 ) ) {
int V_3 ;
switch ( V_221 ) {
case V_222 :
V_3 = 1 ;
break;
case V_223 :
V_3 = 0 ;
break;
default:
return;
}
V_3 ^= V_208 -> V_224 ;
F_79 ( V_208 -> V_210 , V_3 ) ;
}
}
static void F_72 ( struct V_59 * V_88 )
{
F_6 ( V_86 , L_68 , V_72 ) ;
F_3 ( 0x00 , V_37 ) ;
F_3 ( 0x00 , V_36 ) ;
F_3 ( V_87
| V_163
| V_165 ,
V_35 ) ;
F_3 ( 0x1F , V_34 ) ;
F_78 ( V_223 ) ;
V_88 -> V_139 . V_158 = V_159 ;
}
static void F_80 ( struct V_59 * V_88 )
{
T_1 V_154 ;
F_57 ( & V_88 -> V_139 . V_225 ) ;
F_57 ( & V_88 -> V_139 . V_226 -> V_225 ) ;
V_88 -> V_89 = V_90 ;
for ( V_154 = 0 ; V_154 < V_168 ; V_154 ++ ) {
struct V_51 * V_52 = & V_88 -> V_52 [ V_154 ] ;
if ( V_154 != 0 )
F_63 ( & V_52 -> V_52 . V_225 , & V_88 -> V_139 . V_225 ) ;
V_52 -> V_88 = V_88 ;
V_52 -> V_52 . V_175 = NULL ;
V_52 -> V_56 = 0 ;
F_57 ( & V_52 -> V_57 ) ;
F_81 ( & V_52 -> V_52 , V_52 -> V_52 . V_84 ) ;
}
}
static void F_71 ( struct V_59 * V_88 )
{
int V_154 ;
F_6 ( V_86 , L_69 ) ;
V_88 -> V_139 . V_158 = V_161 ;
for ( V_154 = 0 ; V_154 < V_168 ; V_154 ++ ) {
F_3 ( V_154 , V_38 ) ;
F_3 ( ( V_88 -> V_52 [ V_154 ] . V_52 . V_84 & 0x7ff ) >> 3 ,
V_160 ) ;
}
F_3 ( V_227 , V_33 ) ;
F_3 ( V_87 | V_165 ,
V_37 ) ;
F_3 ( V_167 , V_36 ) ;
F_78 ( V_222 ) ;
}
static int F_82 ( struct V_171 * V_228 ,
struct V_229 * V_137 )
{
struct V_59 * V_60 = F_83 ( V_228 ) ;
F_6 ( V_86 , L_70 , V_72 , V_137 -> V_137 . V_179 ) ;
V_60 -> V_137 = V_137 ;
F_71 ( V_60 ) ;
return 0 ;
}
static int F_84 ( struct V_171 * V_228 )
{
struct V_59 * V_60 = F_83 ( V_228 ) ;
V_60 -> V_137 = NULL ;
F_72 ( V_60 ) ;
return 0 ;
}
static int F_85 ( struct V_230 * V_231 )
{
struct V_59 * V_60 = & V_232 ;
struct V_233 * V_88 = & V_231 -> V_88 ;
int V_199 ;
int V_214 ;
F_86 ( V_88 , L_68 , V_72 ) ;
V_234 = F_87 ( NULL , L_71 ) ;
if ( F_88 ( V_234 ) ) {
F_89 ( V_88 , L_72 ) ;
return F_90 ( V_234 ) ;
}
F_91 ( V_234 ) ;
V_235 = F_87 ( NULL , L_73 ) ;
if ( F_88 ( V_235 ) ) {
F_89 ( V_88 , L_74 ) ;
return F_90 ( V_235 ) ;
}
F_91 ( V_235 ) ;
F_92 ( 10 ) ;
F_86 ( V_88 , L_75 ) ;
if ( strncmp ( V_231 -> V_179 , L_76 , 7 ) == 0 ) {
F_93 ( V_88 , L_77 ) ;
V_232 . V_52 [ 1 ] . V_236 = V_237 ;
V_232 . V_52 [ 2 ] . V_236 = V_237 ;
V_232 . V_52 [ 3 ] . V_236 = V_237 ;
V_232 . V_52 [ 4 ] . V_236 = V_237 ;
}
F_94 ( & V_60 -> V_157 ) ;
V_208 = F_95 ( & V_231 -> V_88 ) ;
V_238 = V_239 ;
V_240 = V_241 ;
if ( ! F_96 ( V_238 , V_240 , V_242 ) )
return - V_243 ;
V_2 = F_97 ( V_238 , V_240 ) ;
if ( ! V_2 ) {
V_199 = - V_244 ;
goto V_245;
}
V_200 = V_60 ;
F_98 ( V_231 , V_60 ) ;
F_72 ( V_60 ) ;
F_80 ( V_60 ) ;
V_199 = F_99 ( V_169 , F_43 ,
0 , V_242 , V_60 ) ;
if ( V_199 != 0 ) {
F_89 ( V_88 , L_78 , V_169 , V_199 ) ;
V_199 = - V_243 ;
goto V_246;
}
F_86 ( V_88 , L_79 , V_169 ) ;
if ( V_208 && V_208 -> V_215 > 0 ) {
V_199 = F_100 ( V_208 -> V_215 , L_80 ) ;
if ( V_199 < 0 ) {
F_89 ( V_88 , L_81 ) ;
goto V_247;
}
V_214 = F_101 ( V_208 -> V_215 ) ;
if ( V_214 < 0 ) {
F_89 ( V_88 , L_82 ) ;
V_199 = V_214 ;
goto V_248;
}
V_199 = F_99 ( V_214 , F_75 ,
V_249
| V_250 | V_251 ,
V_242 , V_60 ) ;
if ( V_199 != 0 ) {
F_89 ( V_88 , L_83 ,
V_214 , V_199 ) ;
V_199 = - V_243 ;
goto V_248;
}
F_86 ( V_88 , L_79 , V_214 ) ;
} else {
V_60 -> V_213 = 1 ;
}
if ( V_208 && ! V_208 -> V_209 &&
F_70 ( V_208 -> V_210 ) ) {
V_199 = F_102 ( V_208 -> V_210 ,
V_208 -> V_216 ?
V_252 : V_253 ,
L_84 ) ;
if ( V_199 )
goto V_254;
}
V_199 = F_103 ( & V_231 -> V_88 , & V_60 -> V_139 ) ;
if ( V_199 )
goto V_255;
if ( V_256 ) {
V_60 -> V_257 = F_104 ( L_85 , V_258 ,
V_256 ,
V_60 , & V_259 ) ;
if ( ! V_60 -> V_257 )
F_105 ( V_88 , L_86 ) ;
}
F_86 ( V_88 , L_87 ) ;
return 0 ;
V_255:
if ( V_208 && ! V_208 -> V_209 &&
F_70 ( V_208 -> V_210 ) )
F_106 ( V_208 -> V_210 ) ;
V_254:
if ( V_208 && V_208 -> V_215 > 0 )
F_107 ( F_101 ( V_208 -> V_215 ) , V_60 ) ;
V_248:
if ( V_208 && V_208 -> V_215 > 0 )
F_106 ( V_208 -> V_215 ) ;
V_247:
F_107 ( V_169 , V_60 ) ;
V_246:
F_108 ( V_2 ) ;
V_245:
F_109 ( V_238 , V_240 ) ;
return V_199 ;
}
static int F_110 ( struct V_230 * V_231 )
{
struct V_59 * V_60 = F_111 ( V_231 ) ;
unsigned int V_214 ;
F_86 ( & V_231 -> V_88 , L_68 , V_72 ) ;
if ( V_60 -> V_137 )
return - V_243 ;
F_112 ( & V_60 -> V_139 ) ;
F_113 ( V_60 -> V_257 ) ;
if ( V_208 && ! V_208 -> V_209 &&
F_70 ( V_208 -> V_210 ) )
F_106 ( V_208 -> V_210 ) ;
if ( V_208 && V_208 -> V_215 > 0 ) {
V_214 = F_101 ( V_208 -> V_215 ) ;
F_107 ( V_214 , V_60 ) ;
}
F_107 ( V_169 , V_60 ) ;
F_108 ( V_2 ) ;
F_109 ( V_238 , V_240 ) ;
if ( ! F_88 ( V_235 ) && V_235 != NULL ) {
F_114 ( V_235 ) ;
F_115 ( V_235 ) ;
V_235 = NULL ;
}
if ( ! F_88 ( V_234 ) && V_234 != NULL ) {
F_114 ( V_234 ) ;
F_115 ( V_234 ) ;
V_234 = NULL ;
}
F_86 ( & V_231 -> V_88 , L_88 , V_72 ) ;
return 0 ;
}
static int
F_116 ( struct V_230 * V_231 , T_8 V_260 )
{
F_78 ( V_223 ) ;
return 0 ;
}
static int F_117 ( struct V_230 * V_231 )
{
F_78 ( V_222 ) ;
return 0 ;
}
static int T_9 F_118 ( void )
{
int V_199 ;
F_6 ( V_86 , L_89 , V_242 ) ;
V_256 = F_119 ( V_242 , NULL ) ;
if ( F_88 ( V_256 ) ) {
F_120 ( L_90 ,
V_242 , F_90 ( V_256 ) ) ;
V_256 = NULL ;
}
V_199 = F_121 ( & V_261 ) ;
if ( V_199 )
goto V_262;
return 0 ;
V_262:
F_113 ( V_256 ) ;
return V_199 ;
}
static void T_10 F_122 ( void )
{
F_123 ( & V_261 ) ;
F_113 ( V_256 ) ;
}
