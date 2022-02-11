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
static int F_6 ( int V_5 , const char * V_6 , ... )
{
static char V_7 [ 1024 ] ;
static long V_8 ;
static int V_9 ;
T_3 args ;
int V_10 ;
if ( V_5 > V_11 )
return 0 ;
if ( V_12 != V_8 ) {
V_8 = V_12 ;
V_9 = 0 ;
}
V_10 = F_7 ( V_7 ,
sizeof( V_7 ) , L_1 ,
V_8 , V_9 ++ ) ;
va_start ( args , V_6 ) ;
V_10 = F_8 ( V_7 + V_10 ,
sizeof( V_7 ) - V_10 , V_6 , args ) ;
va_end ( args ) ;
F_9 ( L_2 , V_7 ) ;
return V_10 ;
}
static int F_6 ( int V_5 , const char * V_6 , ... )
{
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , void * V_15 )
{
T_1 V_16 , V_17 , V_18 , V_19 ;
T_1 V_20 , V_21 , V_22 ;
T_1 V_23 , V_24 , V_25 , V_26 ;
T_1 V_27 , V_28 , V_29 , V_30 ;
V_16 = F_1 ( V_31 ) ;
V_17 = F_1 ( V_32 ) ;
V_18 = F_1 ( V_33 ) ;
V_19 = F_1 ( V_34 ) ;
V_20 = F_1 ( V_35 ) ;
V_21 = F_1 ( V_36 ) ;
F_3 ( 0 , V_37 ) ;
V_22 = F_1 ( V_38 ) ;
F_3 ( 1 , V_37 ) ;
V_23 = F_1 ( V_38 ) ;
V_24 = F_1 ( V_39 ) ;
V_25 = F_1 ( V_38 ) ;
V_26 = F_1 ( V_39 ) ;
F_3 ( 2 , V_37 ) ;
V_27 = F_1 ( V_38 ) ;
V_28 = F_1 ( V_39 ) ;
V_29 = F_1 ( V_38 ) ;
V_30 = F_1 ( V_39 ) ;
F_11 ( V_14 , L_3
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
L_16
L_17 ,
V_16 , V_17 , V_18 , V_19 ,
V_20 , V_21 , V_22 ,
V_23 , V_24 , V_25 , V_26 ,
V_27 , V_28 , V_29 , V_30
) ;
return 0 ;
}
static int F_12 ( struct V_40 * V_40 ,
struct V_41 * V_41 )
{
return F_13 ( V_41 , F_10 , NULL ) ;
}
static inline void F_14 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_5 ( V_4 , V_43 ,
V_44 ) ;
}
static inline void F_15 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_4 ( 0x00 , V_4 + V_44 ) ;
}
static inline void F_16 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_5 ( V_4 , V_45 , V_44 ) ;
}
static inline void F_17 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_5 ( V_4 , V_46 , V_44 ) ;
}
static inline void F_18 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_5 ( V_4 , V_47 , V_44 ) ;
}
inline void F_19 ( void T_2 * V_48 )
{
F_5 ( V_48 , V_42 , V_37 ) ;
F_5 ( V_48 , V_49 , V_44 ) ;
}
static inline void F_20 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_5 ( V_4 , ( V_43
| V_47 ) ,
V_44 ) ;
}
static inline void F_21 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_5 ( V_4 , ( V_43
| V_45 ) ,
V_44 ) ;
}
static inline void F_22 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_42 , V_37 ) ;
F_5 ( V_4 , ( V_46
| V_47 ) ,
V_44 ) ;
}
static void F_23 ( struct V_50 * V_51 ,
struct V_52 * V_53 , int V_54 )
{
unsigned V_55 = V_51 -> V_55 ;
F_24 ( & V_53 -> V_56 ) ;
if ( F_25 ( V_53 -> V_53 . V_54 == - V_57 ) )
V_53 -> V_53 . V_54 = V_54 ;
else
V_54 = V_53 -> V_53 . V_54 ;
V_51 -> V_55 = 1 ;
F_26 ( & V_51 -> V_51 , & V_53 -> V_53 ) ;
V_51 -> V_55 = V_55 ;
}
static void F_27 ( struct V_58 * V_59 ,
struct V_50 * V_51 , int V_54 )
{
if ( & V_51 -> V_56 == NULL )
return;
while ( ! F_28 ( & V_51 -> V_56 ) ) {
struct V_52 * V_53 ;
V_53 = F_29 ( V_51 -> V_56 . V_60 , struct V_52 ,
V_56 ) ;
F_23 ( V_51 , V_53 , V_54 ) ;
}
}
static inline void F_30 ( struct V_58 * V_61 )
{
unsigned V_62 ;
for ( V_62 = 1 ; V_62 < V_63 ; V_62 ++ )
F_27 ( V_61 , & V_61 -> V_51 [ V_62 ] , - V_64 ) ;
}
static inline int F_31 ( void )
{
int V_65 ;
V_65 = F_1 ( V_66 ) << 8 ;
V_65 |= F_1 ( V_67 ) ;
return V_65 ;
}
static inline int F_32 ( int V_68 ,
struct V_52 * V_53 ,
unsigned V_69 )
{
unsigned V_10 = F_33 ( V_53 -> V_53 . V_70 - V_53 -> V_53 . V_71 , V_69 ) ;
T_4 * V_72 = V_53 -> V_53 . V_72 + V_53 -> V_53 . V_71 ;
F_34 ( V_72 ) ;
F_6 ( V_73 , L_18 , V_74 ,
V_53 -> V_53 . V_71 , V_53 -> V_53 . V_70 , V_10 , V_53 -> V_53 . V_71 + V_10 ) ;
V_53 -> V_53 . V_71 += V_10 ;
F_35 ( 5 ) ;
F_36 ( V_2 + V_68 , V_72 , V_10 ) ;
return V_10 ;
}
static int F_37 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
unsigned V_75 ;
int V_76 ;
T_1 V_77 ;
int V_78 ;
T_1 V_79 ;
V_77 = V_51 -> V_80 & 0x7F ;
switch ( V_77 ) {
default:
V_77 = 0 ;
case 0 :
V_78 = V_81 ;
break;
case 1 :
V_78 = V_82 ;
break;
case 2 :
V_78 = V_83 ;
break;
case 3 :
V_78 = V_84 ;
break;
case 4 :
V_78 = V_85 ;
break;
}
V_75 = F_32 ( V_78 , V_53 , V_51 -> V_51 . V_86 ) ;
if ( V_75 != V_51 -> V_51 . V_86 )
V_76 = 1 ;
else if ( V_53 -> V_53 . V_70 != V_53 -> V_53 . V_71 || V_53 -> V_53 . V_87 )
V_76 = 0 ;
else
V_76 = 2 ;
if ( V_77 == 0 )
F_6 ( V_88 ,
L_19 ,
V_77 , V_75 , V_53 -> V_53 . V_71 , V_53 -> V_53 . V_70 ,
V_76 , V_53 -> V_53 . V_87 ) ;
if ( V_76 ) {
if ( V_77 == 0 ) {
if ( ! ( F_1 ( V_34 )
& V_89 ) )
F_22 ( V_2 ) ;
V_51 -> V_61 -> V_90 = V_91 ;
} else {
F_3 ( V_77 , V_37 ) ;
V_79 = F_1 ( V_38 ) ;
F_3 ( V_77 , V_37 ) ;
F_3 ( V_79 | V_92 ,
V_38 ) ;
}
F_23 ( V_51 , V_53 , 0 ) ;
V_76 = 1 ;
} else {
if ( V_77 == 0 ) {
if ( ! ( F_1 ( V_34 )
& V_89 ) )
F_17 ( V_2 ) ;
} else {
F_3 ( V_77 , V_37 ) ;
V_79 = F_1 ( V_38 ) ;
F_3 ( V_77 , V_37 ) ;
F_3 ( V_79 | V_92 ,
V_38 ) ;
}
}
return V_76 ;
}
static inline int F_38 ( int V_68 , T_4 * V_72 ,
struct V_52 * V_53 , unsigned V_93 )
{
unsigned V_10 ;
V_10 = F_33 ( V_53 -> V_53 . V_70 - V_53 -> V_53 . V_71 , V_93 ) ;
V_53 -> V_53 . V_71 += V_10 ;
F_39 ( V_68 + V_2 , V_72 , V_10 ) ;
return V_10 ;
}
static int F_40 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
T_4 * V_72 ;
T_1 V_79 ;
unsigned V_94 ;
int V_76 = 1 ;
unsigned V_93 ;
int V_95 = 0 ;
T_1 V_77 ;
int V_78 ;
V_77 = V_51 -> V_80 & 0x7F ;
switch ( V_77 ) {
default:
V_77 = 0 ;
case 0 :
V_78 = V_81 ;
break;
case 1 :
V_78 = V_82 ;
break;
case 2 :
V_78 = V_83 ;
break;
case 3 :
V_78 = V_84 ;
break;
case 4 :
V_78 = V_85 ;
break;
}
if ( ! V_53 -> V_53 . V_70 )
return 1 ;
V_72 = V_53 -> V_53 . V_72 + V_53 -> V_53 . V_71 ;
V_94 = V_53 -> V_53 . V_70 - V_53 -> V_53 . V_71 ;
if ( ! V_94 ) {
F_6 ( V_88 , L_20 , V_74 ) ;
return - 1 ;
}
F_3 ( V_77 , V_37 ) ;
V_95 = F_31 () ;
F_6 ( V_88 , L_21 , V_74 , V_95 ) ;
if ( V_95 > V_51 -> V_51 . V_86 )
V_93 = V_51 -> V_51 . V_86 ;
else
V_93 = V_95 ;
V_95 = F_38 ( V_78 , V_72 , V_53 , V_93 ) ;
if ( V_77 != 0 && V_95 < V_51 -> V_51 . V_86 ) {
V_76 = 1 ;
if ( V_95 != V_93 )
V_53 -> V_53 . V_54 = - V_96 ;
} else {
V_76 = ( V_53 -> V_53 . V_70 <= V_53 -> V_53 . V_71 ) ? 1 : 0 ;
}
F_3 ( V_77 , V_37 ) ;
V_95 = F_31 () ;
if ( V_77 == 0 )
F_6 ( V_73 , L_22 ,
V_74 , V_95 , V_76 ) ;
if ( V_76 ) {
if ( V_77 == 0 ) {
F_20 ( V_2 ) ;
V_51 -> V_61 -> V_90 = V_91 ;
} else {
F_3 ( V_77 , V_37 ) ;
V_79 = F_1 ( V_97 ) ;
F_3 ( V_77 , V_37 ) ;
F_3 ( V_79 & ~ V_98 ,
V_97 ) ;
}
F_23 ( V_51 , V_53 , 0 ) ;
} else {
if ( V_77 == 0 ) {
F_14 ( V_2 ) ;
} else {
F_3 ( V_77 , V_37 ) ;
V_79 = F_1 ( V_97 ) ;
F_3 ( V_77 , V_37 ) ;
F_3 ( V_79 & ~ V_98 ,
V_97 ) ;
}
}
return V_76 ;
}
static int F_41 ( struct V_99 * V_100 )
{
unsigned char * V_101 = ( unsigned char * ) V_100 ;
int V_102 = 0 ;
F_3 ( 0 , V_37 ) ;
V_102 = F_31 () ;
F_6 ( V_88 , L_23 , V_74 , V_102 ) ;
if ( V_102 > sizeof( struct V_99 ) )
V_102 = sizeof( struct V_99 ) ;
F_39 ( V_81 + V_2 , V_101 , V_102 ) ;
F_6 ( V_73 , L_24 , V_74 ,
V_102 , V_100 -> V_103 , V_100 -> V_104 ,
V_100 -> V_105 , V_100 -> V_106 , V_100 -> V_107 ) ;
return V_102 ;
}
static int F_42 ( struct V_58 * V_61 ,
struct V_99 * V_100 )
{
T_5 V_54 = 0 ;
T_4 V_108 = V_100 -> V_106 & 0x7F ;
T_4 V_109 = V_100 -> V_106 & V_110 ;
switch ( V_100 -> V_104 & V_111 ) {
case V_112 :
break;
case V_113 :
V_54 = V_61 -> V_114 ;
break;
case V_115 :
if ( V_108 > 4 || V_100 -> V_107 > 2 )
return 1 ;
if ( V_108 == 0 ) {
F_3 ( 0 , V_37 ) ;
V_54 = F_1 ( V_38 ) ;
V_54 = V_54 & V_49 ;
} else {
F_3 ( V_108 , V_37 ) ;
if ( V_109 ) {
V_54 = F_1 ( V_38 ) ;
V_54 = V_54 & V_116 ;
} else {
V_54 = F_1 ( V_97 ) ;
V_54 = V_54 & V_117 ;
}
}
V_54 = V_54 ? 1 : 0 ;
break;
default:
return 1 ;
}
F_35 ( 5 ) ;
F_3 ( V_54 & 0xFF , V_81 ) ;
F_3 ( V_54 >> 8 , V_81 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_43 ( struct V_58 * V_61 ,
struct V_50 * V_51 ,
struct V_99 * V_100 ,
T_1 V_118 )
{
int V_10 , V_119 , V_65 ;
if ( ! ( V_118 & V_120 ) )
return;
F_27 ( V_61 , V_51 , - V_121 ) ;
V_10 = F_41 ( V_100 ) ;
if ( V_10 != sizeof( * V_100 ) ) {
F_6 ( V_88 , L_25
L_26 ,
sizeof( * V_100 ) , V_10 ) ;
F_19 ( V_2 ) ;
return;
}
F_6 ( V_88 , L_27 ,
V_100 -> V_103 , V_100 -> V_104 , V_100 -> V_107 ) ;
V_61 -> V_122 = ( V_100 -> V_104 & V_123 )
== V_124 ;
V_61 -> V_125 = 0 ;
V_61 -> V_126 = 1 ;
switch ( V_100 -> V_103 ) {
case V_127 :
F_6 ( V_88 , L_28 ) ;
if ( V_100 -> V_104 == V_113 ) {
V_61 -> V_125 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_128 :
F_6 ( V_88 , L_29 ) ;
if ( V_100 -> V_104 == V_112 ) {
V_61 -> V_125 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_129 :
F_6 ( V_88 , L_30 ) ;
if ( V_100 -> V_104 == V_113 ) {
V_65 = V_100 -> V_105 & 0x7F ;
V_61 -> V_130 = V_65 ;
F_3 ( ( V_65 | V_131 ) ,
V_31 ) ;
F_20 ( V_2 ) ;
return;
}
break;
case V_132 :
F_6 ( V_88 , L_31 ) ;
F_14 ( V_2 ) ;
if ( V_61 -> V_122 ) {
if ( ! F_42 ( V_61 , V_100 ) )
return;
}
break;
case V_133 :
F_14 ( V_2 ) ;
if ( V_100 -> V_104 != V_115 )
break;
if ( V_100 -> V_105 != V_134 || V_100 -> V_107 != 0 )
break;
F_44 ( & V_61 -> V_51 [ V_100 -> V_106 & 0x7f ] . V_51 , 0 ) ;
F_20 ( V_2 ) ;
return;
case V_135 :
F_14 ( V_2 ) ;
if ( V_100 -> V_104 != V_115 )
break;
if ( V_100 -> V_105 != V_134 || V_100 -> V_107 != 0 )
break;
F_44 ( & V_61 -> V_51 [ V_100 -> V_106 & 0x7f ] . V_51 , 1 ) ;
F_20 ( V_2 ) ;
return;
default:
F_14 ( V_2 ) ;
break;
}
if ( V_100 -> V_104 & V_110 )
V_61 -> V_90 = V_136 ;
else
V_61 -> V_90 = V_137 ;
if ( ! V_61 -> V_138 )
return;
V_119 = V_61 -> V_138 -> V_139 ( & V_61 -> V_140 , V_100 ) ;
if ( V_119 < 0 ) {
if ( V_61 -> V_125 ) {
F_6 ( V_88 , L_32 ,
V_100 -> V_103 , V_119 ) ;
return;
}
if ( V_119 == - V_141 )
F_6 ( V_88 , L_33 ) ;
else
F_6 ( V_88 ,
L_34 , V_119 ) ;
F_35 ( 5 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_61 -> V_90 = V_91 ;
} else if ( V_61 -> V_126 ) {
F_6 ( V_73 , L_35 ) ;
V_61 -> V_126 = 0 ;
}
F_6 ( V_73 , L_36 , V_142 [ V_61 -> V_90 ] ) ;
}
static void F_45 ( struct V_58 * V_61 )
{
T_1 V_118 ;
struct V_50 * V_51 = & V_61 -> V_51 [ 0 ] ;
struct V_52 * V_53 ;
struct V_99 V_100 ;
if ( F_28 ( & V_51 -> V_56 ) )
V_53 = NULL ;
else
V_53 = F_29 ( V_51 -> V_56 . V_60 , struct V_52 , V_56 ) ;
F_3 ( 0 , V_37 ) ;
V_118 = F_1 ( V_38 ) ;
F_6 ( V_88 , L_37 ,
V_118 , V_142 [ V_61 -> V_90 ] ) ;
if ( V_118 & V_143 ) {
F_27 ( V_61 , V_51 , - V_144 ) ;
F_6 ( V_88 , L_38 ) ;
F_15 ( V_2 ) ;
V_61 -> V_90 = V_91 ;
return;
}
if ( V_118 & V_145 ) {
F_6 ( V_88 , L_39 ) ;
F_27 ( V_61 , V_51 , 0 ) ;
F_16 ( V_2 ) ;
V_61 -> V_90 = V_91 ;
}
switch ( V_61 -> V_90 ) {
case V_91 :
F_43 ( V_61 , V_51 , & V_100 , V_118 ) ;
break;
case V_136 :
F_6 ( V_88 , L_40 ) ;
if ( ! ( V_118 & V_46 ) && V_53 )
F_37 ( V_51 , V_53 ) ;
break;
case V_137 :
F_6 ( V_88 , L_41 ) ;
if ( ( V_118 & V_120 ) && V_53 )
F_40 ( V_51 , V_53 ) ;
break;
case V_146 :
F_6 ( V_88 , L_42 ) ;
V_61 -> V_90 = V_91 ;
break;
case V_147 :
F_6 ( V_88 , L_43 ) ;
V_61 -> V_90 = V_91 ;
break;
}
}
static void F_46 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
int V_109 = V_51 -> V_80 & V_110 ;
T_1 V_148 ;
T_1 V_77 ;
if ( F_25 ( ! F_28 ( & V_51 -> V_56 ) ) )
V_53 = F_29 ( V_51 -> V_56 . V_60 ,
struct V_52 , V_56 ) ;
else
V_53 = NULL ;
V_77 = V_51 -> V_80 & 0x7F ;
if ( V_109 ) {
F_3 ( V_77 , V_37 ) ;
V_148 = F_1 ( V_38 ) ;
F_6 ( V_73 , L_44 ,
V_77 , V_148 , V_53 ? 1 : 0 ) ;
if ( V_148 & V_149 ) {
F_6 ( V_73 , L_45 ) ;
F_3 ( V_77 , V_37 ) ;
F_3 ( V_148 & ~ V_149 ,
V_38 ) ;
return;
}
if ( ! ( V_148 & V_92 ) && V_53 )
F_37 ( V_51 , V_53 ) ;
} else {
F_3 ( V_77 , V_37 ) ;
V_148 = F_1 ( V_97 ) ;
F_6 ( V_73 , L_46 , V_77 , V_148 ) ;
if ( V_148 & V_150 ) {
F_3 ( V_77 , V_37 ) ;
F_3 ( V_148 & ~ V_150 ,
V_97 ) ;
return;
}
if ( ( V_148 & V_98 ) && V_53 )
F_40 ( V_51 , V_53 ) ;
}
}
static T_6 F_47 ( int V_151 , void * V_152 )
{
struct V_58 * V_61 = V_152 ;
int V_153 ;
int V_154 ;
int V_17 ;
int V_118 ;
int V_62 ;
T_1 V_77 , V_155 ;
unsigned long V_156 ;
F_48 ( & V_61 -> V_157 , V_156 ) ;
if ( ! V_61 -> V_138 ) {
F_3 ( F_1 ( V_34 ) ,
V_34 ) ;
F_3 ( F_1 ( V_33 ) ,
V_33 ) ;
}
V_77 = F_1 ( V_37 ) ;
V_153 = F_1 ( V_34 ) ;
V_154 = F_1 ( V_33 ) ;
V_17 = F_1 ( V_32 ) ;
F_5 ( V_2 , V_42 , V_37 ) ;
V_118 = F_1 ( V_38 ) ;
F_6 ( V_88 , L_47 ,
V_153 , V_154 , V_17 , V_118 ) ;
if ( V_153 & V_89 ) {
F_6 ( V_88 , L_48 ,
V_118 , V_17 ) ;
V_61 -> V_140 . V_158 = V_159 ;
F_3 ( 0x00 , V_37 ) ;
F_3 ( ( V_61 -> V_51 [ 0 ] . V_51 . V_86 & 0x7ff ) >> 3 ,
V_160 ) ;
V_61 -> V_130 = 0 ;
V_61 -> V_90 = V_91 ;
V_61 -> V_140 . V_158 = V_161 ;
F_3 ( V_89 ,
V_34 ) ;
F_3 ( V_77 , V_37 ) ;
F_49 ( & V_61 -> V_157 , V_156 ) ;
return V_162 ;
}
if ( V_153 & V_163 ) {
F_6 ( V_88 , L_49 ) ;
F_3 ( V_163 ,
V_34 ) ;
if ( V_61 -> V_140 . V_158 != V_159
&& V_61 -> V_138
&& V_61 -> V_138 -> V_164 )
V_61 -> V_138 -> V_164 ( & V_61 -> V_140 ) ;
}
if ( V_153 & V_165 ) {
F_6 ( V_88 , L_50 ) ;
F_3 ( V_165 ,
V_34 ) ;
if ( V_61 -> V_140 . V_158 != V_159
&& V_61 -> V_138
&& V_61 -> V_138 -> V_166 )
V_61 -> V_138 -> V_166 ( & V_61 -> V_140 ) ;
V_61 -> V_90 = V_91 ;
}
if ( V_154 & V_167 ) {
F_6 ( V_73 , L_51 ) ;
F_3 ( V_167 , V_33 ) ;
F_45 ( V_61 ) ;
}
for ( V_62 = 1 ; V_62 < V_63 ; V_62 ++ ) {
T_1 V_65 = 1 << V_62 ;
if ( V_154 & V_65 ) {
F_6 ( V_73 , L_52 , V_62 ) ;
F_3 ( V_65 , V_33 ) ;
F_46 ( & V_61 -> V_51 [ V_62 ] ) ;
}
}
if ( ! V_153 && ! V_154 && ! V_17 && ! V_118 ) {
for ( V_62 = 1 ; V_62 < V_63 ; V_62 ++ ) {
V_155 = F_1 ( V_37 ) ;
F_3 ( V_62 , V_37 ) ;
if ( F_1 ( V_97 ) & 0x1 )
F_46 ( & V_61 -> V_51 [ V_62 ] ) ;
F_3 ( V_155 , V_37 ) ;
}
}
F_6 ( V_73 , L_53 , V_168 ) ;
F_3 ( V_77 , V_37 ) ;
F_49 ( & V_61 -> V_157 , V_156 ) ;
return V_162 ;
}
static inline struct V_50 * F_50 ( struct V_169 * V_51 )
{
return F_51 ( V_51 , struct V_50 , V_51 ) ;
}
static inline struct V_58 * F_52 ( struct V_170 * V_140 )
{
return F_51 ( V_140 , struct V_58 , V_140 ) ;
}
static inline struct V_52 * F_53 ( struct V_171 * V_53 )
{
return F_51 ( V_53 , struct V_52 , V_53 ) ;
}
static int F_54 ( struct V_169 * V_172 ,
const struct V_173 * V_174 )
{
struct V_58 * V_61 ;
struct V_50 * V_51 ;
T_1 V_69 , V_65 ;
unsigned long V_156 ;
T_1 V_175 , V_176 ;
T_1 V_177 ;
V_51 = F_50 ( V_172 ) ;
if ( ! V_172 || ! V_174
|| V_172 -> V_178 == V_179
|| V_174 -> V_180 != V_181 )
return - V_182 ;
V_61 = V_51 -> V_61 ;
if ( ! V_61 -> V_138 || V_61 -> V_140 . V_158 == V_159 )
return - V_183 ;
V_69 = F_55 ( V_174 ) & 0x1fff ;
F_56 ( V_156 ) ;
V_172 -> V_86 = V_69 & 0x7ff ;
V_51 -> V_51 . V_174 = V_174 ;
V_51 -> V_55 = 0 ;
V_51 -> V_80 = V_174 -> V_80 ;
F_3 ( V_51 -> V_184 , V_37 ) ;
F_3 ( V_69 >> 3 , V_160 ) ;
if ( V_174 -> V_80 & V_110 ) {
V_175 = V_185 | V_186 ;
V_176 = V_187 | V_188 ;
F_3 ( V_51 -> V_184 , V_37 ) ;
F_3 ( V_175 , V_38 ) ;
F_3 ( V_51 -> V_184 , V_37 ) ;
F_3 ( V_176 , V_39 ) ;
} else {
V_175 = V_186 ;
V_176 = V_188 ;
F_3 ( V_51 -> V_184 , V_37 ) ;
F_3 ( V_175 , V_38 ) ;
F_3 ( V_51 -> V_184 , V_37 ) ;
F_3 ( V_176 , V_39 ) ;
V_175 = V_189 | V_190 ;
V_176 = V_191 ;
F_3 ( V_51 -> V_184 , V_37 ) ;
F_3 ( V_175 , V_97 ) ;
F_3 ( V_51 -> V_184 , V_37 ) ;
F_3 ( V_176 , V_192 ) ;
}
V_177 = F_1 ( V_35 ) ;
F_3 ( V_177 | ( 1 << V_51 -> V_184 ) , V_35 ) ;
V_65 = V_174 -> V_80 ;
F_6 ( V_88 , L_54 ,
V_172 -> V_178 , V_51 -> V_184 , V_65 ,
V_174 -> V_80 & V_110 ? L_55 : L_56 , V_69 ) ;
F_57 ( V_156 ) ;
F_44 ( V_172 , 0 ) ;
return 0 ;
}
static int F_58 ( struct V_169 * V_172 )
{
struct V_50 * V_51 = F_50 ( V_172 ) ;
unsigned long V_156 ;
T_1 V_177 ;
if ( ! V_172 || ! V_51 -> V_51 . V_174 ) {
F_6 ( V_88 , L_57 ,
V_172 ? V_51 -> V_51 . V_178 : NULL ) ;
return - V_182 ;
}
F_56 ( V_156 ) ;
F_6 ( V_88 , L_58 , V_172 -> V_178 ) ;
V_51 -> V_51 . V_174 = NULL ;
V_51 -> V_55 = 1 ;
F_27 ( V_51 -> V_61 , V_51 , - V_183 ) ;
V_177 = F_1 ( V_35 ) ;
F_3 ( V_177 & ~ ( 1 << V_51 -> V_184 ) , V_35 ) ;
F_57 ( V_156 ) ;
F_6 ( V_88 , L_59 , V_172 -> V_178 ) ;
return 0 ;
}
static struct V_171 *
F_59 ( struct V_169 * V_172 , T_7 V_193 )
{
struct V_52 * V_53 ;
F_6 ( V_73 , L_60 , V_74 , V_172 , V_193 ) ;
if ( ! V_172 )
return NULL ;
V_53 = F_60 ( sizeof( struct V_52 ) , V_193 ) ;
if ( ! V_53 )
return NULL ;
F_61 ( & V_53 -> V_56 ) ;
return & V_53 -> V_53 ;
}
static void
F_62 ( struct V_169 * V_172 , struct V_171 * V_194 )
{
struct V_50 * V_51 = F_50 ( V_172 ) ;
struct V_52 * V_53 = F_53 ( V_194 ) ;
F_6 ( V_73 , L_61 , V_74 , V_172 , V_194 ) ;
if ( ! V_51 || ! V_194 || ( ! V_51 -> V_51 . V_174 && V_172 -> V_178 != V_179 ) )
return;
F_63 ( ! F_28 ( & V_53 -> V_56 ) ) ;
F_64 ( V_53 ) ;
}
static int F_65 ( struct V_169 * V_172 , struct V_171 * V_194 ,
T_7 V_195 )
{
struct V_52 * V_53 = F_53 ( V_194 ) ;
struct V_50 * V_51 = F_50 ( V_172 ) ;
struct V_58 * V_61 ;
T_1 V_79 = 0 ;
int V_95 = 0 ;
unsigned long V_156 ;
if ( F_66 ( ! V_172 || ( ! V_51 -> V_51 . V_174 && V_51 -> V_51 . V_178 != V_179 ) ) ) {
F_6 ( V_88 , L_62 , V_74 ) ;
return - V_182 ;
}
V_61 = V_51 -> V_61 ;
if ( F_66 ( ! V_61 -> V_138
|| V_61 -> V_140 . V_158 == V_159 ) ) {
return - V_183 ;
}
F_56 ( V_156 ) ;
if ( F_66 ( ! V_194 || ! V_194 -> V_196
|| ! V_194 -> V_72 || ! F_28 ( & V_53 -> V_56 ) ) ) {
if ( ! V_194 )
F_6 ( V_88 , L_63 , V_74 ) ;
else {
F_6 ( V_88 , L_64 ,
V_74 , ! V_194 -> V_196 , ! V_194 -> V_72 ,
! F_28 ( & V_53 -> V_56 ) ) ;
}
F_57 ( V_156 ) ;
return - V_182 ;
}
V_194 -> V_54 = - V_57 ;
V_194 -> V_71 = 0 ;
F_6 ( V_73 , L_65 ,
V_74 , V_51 -> V_80 , V_194 -> V_70 ) ;
if ( V_51 -> V_80 ) {
F_3 ( V_51 -> V_80 & 0x7F , V_37 ) ;
V_79 = F_1 ( ( V_51 -> V_80 & V_110 )
? V_38
: V_97 ) ;
V_95 = F_31 () ;
} else {
F_3 ( 0 , V_37 ) ;
V_79 = F_1 ( V_38 ) ;
V_95 = F_31 () ;
}
if ( F_28 ( & V_51 -> V_56 ) && ! V_51 -> V_55 ) {
if ( V_51 -> V_80 == 0 ) {
switch ( V_61 -> V_90 ) {
case V_136 :
if ( ! ( V_79 & V_46 )
&& F_37 ( V_51 ,
V_53 ) ) {
V_61 -> V_90 = V_91 ;
V_53 = NULL ;
}
break;
case V_137 :
if ( ( ! V_194 -> V_70 )
|| ( ( V_79 & V_98 )
&& F_40 ( V_51 ,
V_53 ) ) ) {
V_61 -> V_90 = V_91 ;
V_53 = NULL ;
}
break;
default:
F_57 ( V_156 ) ;
return - V_197 ;
}
} else if ( ( V_51 -> V_80 & V_110 ) != 0
&& ( ! ( V_79 & V_98 ) )
&& F_37 ( V_51 , V_53 ) ) {
V_53 = NULL ;
} else if ( ( V_79 & V_98 )
&& V_95
&& F_40 ( V_51 , V_53 ) ) {
V_53 = NULL ;
}
}
if ( F_25 ( V_53 ) )
F_67 ( & V_53 -> V_56 , & V_51 -> V_56 ) ;
F_57 ( V_156 ) ;
F_6 ( V_73 , L_66 , V_74 ) ;
return 0 ;
}
static int F_68 ( struct V_169 * V_172 , struct V_171 * V_194 )
{
struct V_50 * V_51 = F_50 ( V_172 ) ;
struct V_58 * V_59 ;
int V_198 = - V_182 ;
unsigned long V_156 ;
struct V_52 * V_53 = NULL ;
F_6 ( V_73 , L_61 , V_74 , V_172 , V_194 ) ;
if ( ! V_199 -> V_138 )
return - V_183 ;
if ( ! V_172 || ! V_194 )
return V_198 ;
V_59 = F_52 ( V_51 -> V_140 ) ;
F_56 ( V_156 ) ;
F_69 (req, &ep->queue, queue) {
if ( & V_53 -> V_53 == V_194 ) {
F_24 ( & V_53 -> V_56 ) ;
V_194 -> V_54 = - V_200 ;
V_198 = 0 ;
break;
}
}
if ( V_198 == 0 ) {
F_6 ( V_73 ,
L_67 ,
V_53 , V_172 -> V_178 , V_194 -> V_70 , V_194 -> V_72 ) ;
F_23 ( V_51 , V_53 , - V_200 ) ;
}
F_57 ( V_156 ) ;
return V_198 ;
}
static int F_44 ( struct V_169 * V_172 , int V_3 )
{
struct V_50 * V_51 = F_50 ( V_172 ) ;
T_1 V_79 = 0 ;
unsigned long V_156 ;
T_1 V_77 ;
if ( F_66 ( ! V_172 || ( ! V_51 -> V_51 . V_174 && V_51 -> V_51 . V_178 != V_179 ) ) ) {
F_6 ( V_88 , L_68 , V_74 ) ;
return - V_182 ;
}
F_56 ( V_156 ) ;
V_77 = V_51 -> V_80 & 0x7F ;
if ( V_77 == 0 ) {
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
} else {
F_3 ( V_77 , V_37 ) ;
V_79 = F_1 ( ( V_51 -> V_80 & V_110 )
? V_38
: V_97 ) ;
if ( ( V_51 -> V_80 & V_110 ) != 0 ) {
if ( V_3 )
F_3 ( V_79 | V_116 ,
V_38 ) ;
else {
V_79 &= ~ V_116 ;
F_3 ( V_79 , V_38 ) ;
V_79 |= V_186 ;
F_3 ( V_79 , V_38 ) ;
}
} else {
if ( V_3 )
F_3 ( V_79 | V_117 ,
V_97 ) ;
else {
V_79 &= ~ V_117 ;
F_3 ( V_79 , V_97 ) ;
V_79 |= V_190 ;
F_3 ( V_79 , V_97 ) ;
}
}
}
V_51 -> V_55 = V_3 ? 1 : 0 ;
F_57 ( V_156 ) ;
return 0 ;
}
static int F_70 ( struct V_170 * V_201 )
{
int V_65 ;
F_6 ( V_73 , L_69 , V_74 ) ;
V_65 = F_1 ( V_202 ) << 8 ;
V_65 |= F_1 ( V_203 ) ;
return V_65 ;
}
static int F_71 ( struct V_170 * V_201 )
{
F_6 ( V_88 , L_69 , V_74 ) ;
return 0 ;
}
static int F_72 ( struct V_170 * V_140 , int V_3 )
{
struct V_58 * V_59 = F_52 ( V_140 ) ;
F_6 ( V_88 , L_69 , V_74 ) ;
if ( V_3 )
V_59 -> V_114 |= ( 1 << V_204 ) ;
else
V_59 -> V_114 &= ~ ( 1 << V_204 ) ;
return 0 ;
}
static int F_73 ( struct V_58 * V_59 , int V_205 )
{
F_6 ( V_88 , L_69 , V_74 ) ;
if ( V_206 && ( V_206 -> V_207 ||
F_74 ( V_206 -> V_208 ) ) ) {
if ( V_205 )
F_75 ( V_59 ) ;
else {
if ( V_59 -> V_140 . V_158 != V_159 ) {
if ( V_59 -> V_138 && V_59 -> V_138 -> V_209 )
V_59 -> V_138 -> V_209 ( & V_59 -> V_140 ) ;
}
F_76 ( V_59 ) ;
}
} else {
return - V_141 ;
}
return 0 ;
}
static int F_77 ( struct V_170 * V_140 , int V_210 )
{
struct V_58 * V_59 = F_52 ( V_140 ) ;
F_6 ( V_88 , L_69 , V_74 ) ;
V_59 -> V_211 = ( V_210 != 0 ) ;
F_73 ( V_59 , V_210 ) ;
return 0 ;
}
static int F_78 ( struct V_170 * V_140 , int V_205 )
{
struct V_58 * V_59 = F_52 ( V_140 ) ;
F_6 ( V_88 , L_69 , V_74 ) ;
F_73 ( V_59 , V_205 ? 0 : 1 ) ;
return 0 ;
}
static T_6 F_79 ( int V_212 , void * V_152 )
{
struct V_58 * V_61 = V_152 ;
unsigned int V_3 ;
F_6 ( V_88 , L_69 , V_74 ) ;
V_3 = F_80 ( V_206 -> V_213 ) ? 1 : 0 ;
if ( V_206 -> V_214 )
V_3 = ! V_3 ;
if ( V_3 != V_61 -> V_211 )
F_77 ( & V_61 -> V_140 , V_3 ) ;
return V_162 ;
}
static int F_81 ( struct V_170 * V_201 , unsigned V_215 )
{
F_6 ( V_88 , L_69 , V_74 ) ;
if ( V_206 && V_206 -> V_216 ) {
V_206 -> V_216 ( V_215 ) ;
return 0 ;
}
return - V_217 ;
}
static void F_82 ( enum V_218 V_219 )
{
if ( ! V_206 )
return;
if ( V_206 -> V_207 ) {
V_206 -> V_207 ( V_219 ) ;
} else if ( F_74 ( V_206 -> V_208 ) ) {
int V_3 ;
switch ( V_219 ) {
case V_220 :
V_3 = 1 ;
break;
case V_221 :
V_3 = 0 ;
break;
default:
return;
}
V_3 ^= V_206 -> V_222 ;
F_83 ( V_206 -> V_208 , V_3 ) ;
}
}
static void F_76 ( struct V_58 * V_61 )
{
F_6 ( V_88 , L_69 , V_74 ) ;
F_3 ( 0x00 , V_36 ) ;
F_3 ( 0x00 , V_35 ) ;
F_3 ( V_89
| V_163
| V_165 ,
V_34 ) ;
F_3 ( 0x1F , V_33 ) ;
F_82 ( V_221 ) ;
V_61 -> V_140 . V_158 = V_159 ;
}
static void F_84 ( struct V_58 * V_61 )
{
T_1 V_62 ;
F_61 ( & V_61 -> V_140 . V_223 ) ;
F_61 ( & V_61 -> V_140 . V_224 -> V_223 ) ;
V_61 -> V_90 = V_91 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
struct V_50 * V_51 = & V_61 -> V_51 [ V_62 ] ;
if ( V_62 != 0 )
F_67 ( & V_51 -> V_51 . V_223 , & V_61 -> V_140 . V_223 ) ;
V_51 -> V_61 = V_61 ;
V_51 -> V_51 . V_174 = NULL ;
V_51 -> V_55 = 0 ;
F_61 ( & V_51 -> V_56 ) ;
F_85 ( & V_51 -> V_51 , V_51 -> V_51 . V_86 ) ;
}
}
static void F_75 ( struct V_58 * V_61 )
{
int V_62 ;
F_6 ( V_88 , L_70 ) ;
V_61 -> V_140 . V_158 = V_161 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
F_3 ( V_62 , V_37 ) ;
F_3 ( ( V_61 -> V_51 [ V_62 ] . V_51 . V_86 & 0x7ff ) >> 3 ,
V_160 ) ;
}
F_3 ( V_225 , V_32 ) ;
F_3 ( V_89 | V_165 ,
V_36 ) ;
F_3 ( V_167 , V_35 ) ;
F_82 ( V_220 ) ;
}
static int F_86 ( struct V_170 * V_226 ,
struct V_227 * V_138 )
{
struct V_58 * V_59 = F_87 ( V_226 ) ;
F_6 ( V_88 , L_71 , V_74 , V_138 -> V_138 . V_178 ) ;
V_59 -> V_138 = V_138 ;
F_75 ( V_59 ) ;
return 0 ;
}
static int F_88 ( struct V_170 * V_226 ,
struct V_227 * V_138 )
{
struct V_58 * V_59 = F_87 ( V_226 ) ;
V_59 -> V_138 = NULL ;
F_76 ( V_59 ) ;
return 0 ;
}
static int F_89 ( struct V_228 * V_229 )
{
struct V_58 * V_59 = & V_230 ;
struct V_231 * V_61 = & V_229 -> V_61 ;
int V_198 ;
int V_212 ;
F_90 ( V_61 , L_69 , V_74 ) ;
V_232 = F_91 ( NULL , L_72 ) ;
if ( F_92 ( V_232 ) ) {
F_93 ( V_61 , L_73 ) ;
return F_94 ( V_232 ) ;
}
F_95 ( V_232 ) ;
V_233 = F_91 ( NULL , L_74 ) ;
if ( F_92 ( V_233 ) ) {
F_93 ( V_61 , L_75 ) ;
return F_94 ( V_233 ) ;
}
F_95 ( V_233 ) ;
F_96 ( 10 ) ;
F_90 ( V_61 , L_76 ) ;
if ( strncmp ( V_229 -> V_178 , L_77 , 7 ) == 0 ) {
F_97 ( V_61 , L_78 ) ;
V_230 . V_51 [ 1 ] . V_234 = V_235 ;
V_230 . V_51 [ 2 ] . V_234 = V_235 ;
V_230 . V_51 [ 3 ] . V_234 = V_235 ;
V_230 . V_51 [ 4 ] . V_234 = V_235 ;
}
F_98 ( & V_59 -> V_157 ) ;
V_206 = F_99 ( & V_229 -> V_61 ) ;
V_236 = V_237 ;
V_238 = V_239 ;
if ( ! F_100 ( V_236 , V_238 , V_240 ) )
return - V_241 ;
V_2 = F_101 ( V_236 , V_238 ) ;
if ( ! V_2 ) {
V_198 = - V_242 ;
goto V_243;
}
V_199 = V_59 ;
F_102 ( V_229 , V_59 ) ;
F_76 ( V_59 ) ;
F_84 ( V_59 ) ;
V_198 = F_103 ( V_168 , F_47 ,
0 , V_240 , V_59 ) ;
if ( V_198 != 0 ) {
F_93 ( V_61 , L_79 , V_168 , V_198 ) ;
V_198 = - V_241 ;
goto V_244;
}
F_90 ( V_61 , L_80 , V_168 ) ;
if ( V_206 && V_206 -> V_213 > 0 ) {
V_198 = F_104 ( V_206 -> V_213 , L_81 ) ;
if ( V_198 < 0 ) {
F_93 ( V_61 , L_82 ) ;
goto V_245;
}
V_212 = F_105 ( V_206 -> V_213 ) ;
if ( V_212 < 0 ) {
F_93 ( V_61 , L_83 ) ;
V_198 = V_212 ;
goto V_246;
}
V_198 = F_103 ( V_212 , F_79 ,
V_247
| V_248 | V_249 ,
V_240 , V_59 ) ;
if ( V_198 != 0 ) {
F_93 ( V_61 , L_84 ,
V_212 , V_198 ) ;
V_198 = - V_241 ;
goto V_246;
}
F_90 ( V_61 , L_80 , V_212 ) ;
} else {
V_59 -> V_211 = 1 ;
}
if ( V_206 && ! V_206 -> V_207 &&
F_74 ( V_206 -> V_208 ) ) {
V_198 = F_106 ( V_206 -> V_208 ,
V_206 -> V_214 ?
V_250 : V_251 ,
L_85 ) ;
if ( V_198 )
goto V_252;
}
V_198 = F_107 ( & V_229 -> V_61 , & V_59 -> V_140 ) ;
if ( V_198 )
goto V_253;
if ( V_254 ) {
V_59 -> V_255 = F_108 ( L_86 , V_256 ,
V_254 ,
V_59 , & V_257 ) ;
if ( ! V_59 -> V_255 )
F_109 ( V_61 , L_87 ) ;
}
F_90 ( V_61 , L_88 ) ;
return 0 ;
V_253:
if ( V_206 && ! V_206 -> V_207 &&
F_74 ( V_206 -> V_208 ) )
F_110 ( V_206 -> V_208 ) ;
V_252:
if ( V_206 && V_206 -> V_213 > 0 )
F_111 ( F_105 ( V_206 -> V_213 ) , V_59 ) ;
V_246:
if ( V_206 && V_206 -> V_213 > 0 )
F_110 ( V_206 -> V_213 ) ;
V_245:
F_111 ( V_168 , V_59 ) ;
V_244:
F_112 ( V_2 ) ;
V_243:
F_113 ( V_236 , V_238 ) ;
return V_198 ;
}
static int F_114 ( struct V_228 * V_229 )
{
struct V_58 * V_59 = F_115 ( V_229 ) ;
unsigned int V_212 ;
F_90 ( & V_229 -> V_61 , L_69 , V_74 ) ;
if ( V_59 -> V_138 )
return - V_241 ;
F_116 ( & V_59 -> V_140 ) ;
F_117 ( V_59 -> V_255 ) ;
if ( V_206 && ! V_206 -> V_207 &&
F_74 ( V_206 -> V_208 ) )
F_110 ( V_206 -> V_208 ) ;
if ( V_206 && V_206 -> V_213 > 0 ) {
V_212 = F_105 ( V_206 -> V_213 ) ;
F_111 ( V_212 , V_59 ) ;
}
F_111 ( V_168 , V_59 ) ;
F_112 ( V_2 ) ;
F_113 ( V_236 , V_238 ) ;
if ( ! F_92 ( V_233 ) && V_233 != NULL ) {
F_118 ( V_233 ) ;
F_119 ( V_233 ) ;
V_233 = NULL ;
}
if ( ! F_92 ( V_232 ) && V_232 != NULL ) {
F_118 ( V_232 ) ;
F_119 ( V_232 ) ;
V_232 = NULL ;
}
F_90 ( & V_229 -> V_61 , L_89 , V_74 ) ;
return 0 ;
}
static int
F_120 ( struct V_228 * V_229 , T_8 V_258 )
{
F_82 ( V_221 ) ;
return 0 ;
}
static int F_121 ( struct V_228 * V_229 )
{
F_82 ( V_220 ) ;
return 0 ;
}
static int T_9 F_122 ( void )
{
int V_198 ;
F_6 ( V_88 , L_90 , V_240 , V_259 ) ;
V_254 = F_123 ( V_240 , NULL ) ;
if ( F_92 ( V_254 ) ) {
F_124 ( L_91 ,
V_240 , F_94 ( V_254 ) ) ;
V_254 = NULL ;
}
V_198 = F_125 ( & V_260 ) ;
if ( V_198 )
goto V_261;
return 0 ;
V_261:
F_117 ( V_254 ) ;
return V_198 ;
}
static void T_10 F_126 ( void )
{
F_127 ( & V_260 ) ;
F_117 ( V_254 ) ;
}
