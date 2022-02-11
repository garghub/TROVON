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
V_53 -> V_53 . V_58 ( & V_51 -> V_51 , & V_53 -> V_53 ) ;
V_51 -> V_55 = V_55 ;
}
static void F_26 ( struct V_59 * V_60 ,
struct V_50 * V_51 , int V_54 )
{
if ( & V_51 -> V_56 == NULL )
return;
while ( ! F_27 ( & V_51 -> V_56 ) ) {
struct V_52 * V_53 ;
V_53 = F_28 ( V_51 -> V_56 . V_61 , struct V_52 ,
V_56 ) ;
F_23 ( V_51 , V_53 , V_54 ) ;
}
}
static inline void F_29 ( struct V_59 * V_62 )
{
unsigned V_63 ;
for ( V_63 = 1 ; V_63 < V_64 ; V_63 ++ )
F_26 ( V_62 , & V_62 -> V_51 [ V_63 ] , - V_65 ) ;
}
static inline int F_30 ( void )
{
int V_66 ;
V_66 = F_1 ( V_67 ) << 8 ;
V_66 |= F_1 ( V_68 ) ;
return V_66 ;
}
static inline int F_31 ( int V_69 ,
struct V_52 * V_53 ,
unsigned V_70 )
{
unsigned V_10 = F_32 ( V_53 -> V_53 . V_71 - V_53 -> V_53 . V_72 , V_70 ) ;
T_4 * V_73 = V_53 -> V_53 . V_73 + V_53 -> V_53 . V_72 ;
F_33 ( V_73 ) ;
F_6 ( V_74 , L_18 , V_75 ,
V_53 -> V_53 . V_72 , V_53 -> V_53 . V_71 , V_10 , V_53 -> V_53 . V_72 + V_10 ) ;
V_53 -> V_53 . V_72 += V_10 ;
F_34 ( 5 ) ;
F_35 ( V_2 + V_69 , V_73 , V_10 ) ;
return V_10 ;
}
static int F_36 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
unsigned V_76 ;
int V_77 ;
T_1 V_78 ;
int V_79 ;
T_1 V_80 ;
V_78 = V_51 -> V_81 & 0x7F ;
switch ( V_78 ) {
default:
V_78 = 0 ;
case 0 :
V_79 = V_82 ;
break;
case 1 :
V_79 = V_83 ;
break;
case 2 :
V_79 = V_84 ;
break;
case 3 :
V_79 = V_85 ;
break;
case 4 :
V_79 = V_86 ;
break;
}
V_76 = F_31 ( V_79 , V_53 , V_51 -> V_51 . V_87 ) ;
if ( V_76 != V_51 -> V_51 . V_87 )
V_77 = 1 ;
else if ( V_53 -> V_53 . V_71 != V_53 -> V_53 . V_72 || V_53 -> V_53 . V_88 )
V_77 = 0 ;
else
V_77 = 2 ;
if ( V_78 == 0 )
F_6 ( V_89 ,
L_19 ,
V_78 , V_76 , V_53 -> V_53 . V_72 , V_53 -> V_53 . V_71 ,
V_77 , V_53 -> V_53 . V_88 ) ;
if ( V_77 ) {
if ( V_78 == 0 ) {
if ( ! ( F_1 ( V_34 )
& V_90 ) )
F_22 ( V_2 ) ;
V_51 -> V_62 -> V_91 = V_92 ;
} else {
F_3 ( V_78 , V_37 ) ;
V_80 = F_1 ( V_38 ) ;
F_3 ( V_78 , V_37 ) ;
F_3 ( V_80 | V_93 ,
V_38 ) ;
}
F_23 ( V_51 , V_53 , 0 ) ;
V_77 = 1 ;
} else {
if ( V_78 == 0 ) {
if ( ! ( F_1 ( V_34 )
& V_90 ) )
F_17 ( V_2 ) ;
} else {
F_3 ( V_78 , V_37 ) ;
V_80 = F_1 ( V_38 ) ;
F_3 ( V_78 , V_37 ) ;
F_3 ( V_80 | V_93 ,
V_38 ) ;
}
}
return V_77 ;
}
static inline int F_37 ( int V_69 , T_4 * V_73 ,
struct V_52 * V_53 , unsigned V_94 )
{
unsigned V_10 ;
V_10 = F_32 ( V_53 -> V_53 . V_71 - V_53 -> V_53 . V_72 , V_94 ) ;
V_53 -> V_53 . V_72 += V_10 ;
F_38 ( V_69 + V_2 , V_73 , V_10 ) ;
return V_10 ;
}
static int F_39 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
T_4 * V_73 ;
T_1 V_80 ;
unsigned V_95 ;
int V_77 = 1 ;
unsigned V_94 ;
int V_96 = 0 ;
T_1 V_78 ;
int V_79 ;
V_78 = V_51 -> V_81 & 0x7F ;
switch ( V_78 ) {
default:
V_78 = 0 ;
case 0 :
V_79 = V_82 ;
break;
case 1 :
V_79 = V_83 ;
break;
case 2 :
V_79 = V_84 ;
break;
case 3 :
V_79 = V_85 ;
break;
case 4 :
V_79 = V_86 ;
break;
}
if ( ! V_53 -> V_53 . V_71 )
return 1 ;
V_73 = V_53 -> V_53 . V_73 + V_53 -> V_53 . V_72 ;
V_95 = V_53 -> V_53 . V_71 - V_53 -> V_53 . V_72 ;
if ( ! V_95 ) {
F_6 ( V_89 , L_20 , V_75 ) ;
return - 1 ;
}
F_3 ( V_78 , V_37 ) ;
V_96 = F_30 () ;
F_6 ( V_89 , L_21 , V_75 , V_96 ) ;
if ( V_96 > V_51 -> V_51 . V_87 )
V_94 = V_51 -> V_51 . V_87 ;
else
V_94 = V_96 ;
V_96 = F_37 ( V_79 , V_73 , V_53 , V_94 ) ;
if ( V_78 != 0 && V_96 < V_51 -> V_51 . V_87 ) {
V_77 = 1 ;
if ( V_96 != V_94 )
V_53 -> V_53 . V_54 = - V_97 ;
} else {
V_77 = ( V_53 -> V_53 . V_71 <= V_53 -> V_53 . V_72 ) ? 1 : 0 ;
}
F_3 ( V_78 , V_37 ) ;
V_96 = F_30 () ;
if ( V_78 == 0 )
F_6 ( V_74 , L_22 ,
V_75 , V_96 , V_77 ) ;
if ( V_77 ) {
if ( V_78 == 0 ) {
F_20 ( V_2 ) ;
V_51 -> V_62 -> V_91 = V_92 ;
} else {
F_3 ( V_78 , V_37 ) ;
V_80 = F_1 ( V_98 ) ;
F_3 ( V_78 , V_37 ) ;
F_3 ( V_80 & ~ V_99 ,
V_98 ) ;
}
F_23 ( V_51 , V_53 , 0 ) ;
} else {
if ( V_78 == 0 ) {
F_14 ( V_2 ) ;
} else {
F_3 ( V_78 , V_37 ) ;
V_80 = F_1 ( V_98 ) ;
F_3 ( V_78 , V_37 ) ;
F_3 ( V_80 & ~ V_99 ,
V_98 ) ;
}
}
return V_77 ;
}
static int F_40 ( struct V_100 * V_101 )
{
unsigned char * V_102 = ( unsigned char * ) V_101 ;
int V_103 = 0 ;
F_3 ( 0 , V_37 ) ;
V_103 = F_30 () ;
F_6 ( V_89 , L_23 , V_75 , V_103 ) ;
if ( V_103 > sizeof( struct V_100 ) )
V_103 = sizeof( struct V_100 ) ;
F_38 ( V_82 + V_2 , V_102 , V_103 ) ;
F_6 ( V_74 , L_24 , V_75 ,
V_103 , V_101 -> V_104 , V_101 -> V_105 ,
V_101 -> V_106 , V_101 -> V_107 , V_101 -> V_108 ) ;
return V_103 ;
}
static int F_41 ( struct V_59 * V_62 ,
struct V_100 * V_101 )
{
T_5 V_54 = 0 ;
T_4 V_109 = V_101 -> V_107 & 0x7F ;
T_4 V_110 = V_101 -> V_107 & V_111 ;
switch ( V_101 -> V_105 & V_112 ) {
case V_113 :
break;
case V_114 :
V_54 = V_62 -> V_115 ;
break;
case V_116 :
if ( V_109 > 4 || V_101 -> V_108 > 2 )
return 1 ;
if ( V_109 == 0 ) {
F_3 ( 0 , V_37 ) ;
V_54 = F_1 ( V_38 ) ;
V_54 = V_54 & V_49 ;
} else {
F_3 ( V_109 , V_37 ) ;
if ( V_110 ) {
V_54 = F_1 ( V_38 ) ;
V_54 = V_54 & V_117 ;
} else {
V_54 = F_1 ( V_98 ) ;
V_54 = V_54 & V_118 ;
}
}
V_54 = V_54 ? 1 : 0 ;
break;
default:
return 1 ;
}
F_34 ( 5 ) ;
F_3 ( V_54 & 0xFF , V_82 ) ;
F_3 ( V_54 >> 8 , V_82 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_42 ( struct V_59 * V_62 ,
struct V_50 * V_51 ,
struct V_100 * V_101 ,
T_1 V_119 )
{
int V_10 , V_120 , V_66 ;
if ( ! ( V_119 & V_121 ) )
return;
F_26 ( V_62 , V_51 , - V_122 ) ;
V_10 = F_40 ( V_101 ) ;
if ( V_10 != sizeof( * V_101 ) ) {
F_6 ( V_89 , L_25
L_26 ,
sizeof( * V_101 ) , V_10 ) ;
F_19 ( V_2 ) ;
return;
}
F_6 ( V_89 , L_27 ,
V_101 -> V_104 , V_101 -> V_105 , V_101 -> V_108 ) ;
V_62 -> V_123 = ( V_101 -> V_105 & V_124 )
== V_125 ;
V_62 -> V_126 = 0 ;
V_62 -> V_127 = 1 ;
switch ( V_101 -> V_104 ) {
case V_128 :
F_6 ( V_89 , L_28 ) ;
if ( V_101 -> V_105 == V_114 ) {
V_62 -> V_126 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_129 :
F_6 ( V_89 , L_29 ) ;
if ( V_101 -> V_105 == V_113 ) {
V_62 -> V_126 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_130 :
F_6 ( V_89 , L_30 ) ;
if ( V_101 -> V_105 == V_114 ) {
V_66 = V_101 -> V_106 & 0x7F ;
V_62 -> V_131 = V_66 ;
F_3 ( ( V_66 | V_132 ) ,
V_31 ) ;
F_20 ( V_2 ) ;
return;
}
break;
case V_133 :
F_6 ( V_89 , L_31 ) ;
F_14 ( V_2 ) ;
if ( V_62 -> V_123 ) {
if ( ! F_41 ( V_62 , V_101 ) )
return;
}
break;
case V_134 :
F_14 ( V_2 ) ;
if ( V_101 -> V_105 != V_116 )
break;
if ( V_101 -> V_106 != V_135 || V_101 -> V_108 != 0 )
break;
F_43 ( & V_62 -> V_51 [ V_101 -> V_107 & 0x7f ] . V_51 , 0 ) ;
F_20 ( V_2 ) ;
return;
case V_136 :
F_14 ( V_2 ) ;
if ( V_101 -> V_105 != V_116 )
break;
if ( V_101 -> V_106 != V_135 || V_101 -> V_108 != 0 )
break;
F_43 ( & V_62 -> V_51 [ V_101 -> V_107 & 0x7f ] . V_51 , 1 ) ;
F_20 ( V_2 ) ;
return;
default:
F_14 ( V_2 ) ;
break;
}
if ( V_101 -> V_105 & V_111 )
V_62 -> V_91 = V_137 ;
else
V_62 -> V_91 = V_138 ;
if ( ! V_62 -> V_139 )
return;
V_120 = V_62 -> V_139 -> V_140 ( & V_62 -> V_141 , V_101 ) ;
if ( V_120 < 0 ) {
if ( V_62 -> V_126 ) {
F_6 ( V_89 , L_32 ,
V_101 -> V_104 , V_120 ) ;
return;
}
if ( V_120 == - V_142 )
F_6 ( V_89 , L_33 ) ;
else
F_6 ( V_89 ,
L_34 , V_120 ) ;
F_34 ( 5 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_62 -> V_91 = V_92 ;
} else if ( V_62 -> V_127 ) {
F_6 ( V_74 , L_35 ) ;
V_62 -> V_127 = 0 ;
}
F_6 ( V_74 , L_36 , V_143 [ V_62 -> V_91 ] ) ;
}
static void F_44 ( struct V_59 * V_62 )
{
T_1 V_119 ;
struct V_50 * V_51 = & V_62 -> V_51 [ 0 ] ;
struct V_52 * V_53 ;
struct V_100 V_101 ;
if ( F_27 ( & V_51 -> V_56 ) )
V_53 = NULL ;
else
V_53 = F_28 ( V_51 -> V_56 . V_61 , struct V_52 , V_56 ) ;
F_3 ( 0 , V_37 ) ;
V_119 = F_1 ( V_38 ) ;
F_6 ( V_89 , L_37 ,
V_119 , V_143 [ V_62 -> V_91 ] ) ;
if ( V_119 & V_144 ) {
F_26 ( V_62 , V_51 , - V_145 ) ;
F_6 ( V_89 , L_38 ) ;
F_15 ( V_2 ) ;
V_62 -> V_91 = V_92 ;
return;
}
if ( V_119 & V_146 ) {
F_6 ( V_89 , L_39 ) ;
F_26 ( V_62 , V_51 , 0 ) ;
F_16 ( V_2 ) ;
V_62 -> V_91 = V_92 ;
}
switch ( V_62 -> V_91 ) {
case V_92 :
F_42 ( V_62 , V_51 , & V_101 , V_119 ) ;
break;
case V_137 :
F_6 ( V_89 , L_40 ) ;
if ( ! ( V_119 & V_46 ) && V_53 )
F_36 ( V_51 , V_53 ) ;
break;
case V_138 :
F_6 ( V_89 , L_41 ) ;
if ( ( V_119 & V_121 ) && V_53 )
F_39 ( V_51 , V_53 ) ;
break;
case V_147 :
F_6 ( V_89 , L_42 ) ;
V_62 -> V_91 = V_92 ;
break;
case V_148 :
F_6 ( V_89 , L_43 ) ;
V_62 -> V_91 = V_92 ;
break;
}
}
static void F_45 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
int V_110 = V_51 -> V_81 & V_111 ;
T_1 V_149 ;
T_1 V_78 ;
if ( F_25 ( ! F_27 ( & V_51 -> V_56 ) ) )
V_53 = F_28 ( V_51 -> V_56 . V_61 ,
struct V_52 , V_56 ) ;
else
V_53 = NULL ;
V_78 = V_51 -> V_81 & 0x7F ;
if ( V_110 ) {
F_3 ( V_78 , V_37 ) ;
V_149 = F_1 ( V_38 ) ;
F_6 ( V_74 , L_44 ,
V_78 , V_149 , V_53 ? 1 : 0 ) ;
if ( V_149 & V_150 ) {
F_6 ( V_74 , L_45 ) ;
F_3 ( V_78 , V_37 ) ;
F_3 ( V_149 & ~ V_150 ,
V_38 ) ;
return;
}
if ( ! ( V_149 & V_93 ) && V_53 )
F_36 ( V_51 , V_53 ) ;
} else {
F_3 ( V_78 , V_37 ) ;
V_149 = F_1 ( V_98 ) ;
F_6 ( V_74 , L_46 , V_78 , V_149 ) ;
if ( V_149 & V_151 ) {
F_3 ( V_78 , V_37 ) ;
F_3 ( V_149 & ~ V_151 ,
V_98 ) ;
return;
}
if ( ( V_149 & V_99 ) && V_53 )
F_39 ( V_51 , V_53 ) ;
}
}
static T_6 F_46 ( int V_152 , void * V_153 )
{
struct V_59 * V_62 = V_153 ;
int V_154 ;
int V_155 ;
int V_17 ;
int V_119 ;
int V_63 ;
T_1 V_78 , V_156 ;
unsigned long V_157 ;
F_47 ( & V_62 -> V_158 , V_157 ) ;
if ( ! V_62 -> V_139 ) {
F_3 ( F_1 ( V_34 ) ,
V_34 ) ;
F_3 ( F_1 ( V_33 ) ,
V_33 ) ;
}
V_78 = F_1 ( V_37 ) ;
V_154 = F_1 ( V_34 ) ;
V_155 = F_1 ( V_33 ) ;
V_17 = F_1 ( V_32 ) ;
F_5 ( V_2 , V_42 , V_37 ) ;
V_119 = F_1 ( V_38 ) ;
F_6 ( V_89 , L_47 ,
V_154 , V_155 , V_17 , V_119 ) ;
if ( V_154 & V_90 ) {
F_6 ( V_89 , L_48 ,
V_119 , V_17 ) ;
V_62 -> V_141 . V_159 = V_160 ;
F_3 ( 0x00 , V_37 ) ;
F_3 ( ( V_62 -> V_51 [ 0 ] . V_51 . V_87 & 0x7ff ) >> 3 ,
V_161 ) ;
V_62 -> V_131 = 0 ;
V_62 -> V_91 = V_92 ;
V_62 -> V_141 . V_159 = V_162 ;
F_3 ( V_90 ,
V_34 ) ;
F_3 ( V_78 , V_37 ) ;
F_48 ( & V_62 -> V_158 , V_157 ) ;
return V_163 ;
}
if ( V_154 & V_164 ) {
F_6 ( V_89 , L_49 ) ;
F_3 ( V_164 ,
V_34 ) ;
if ( V_62 -> V_141 . V_159 != V_160
&& V_62 -> V_139
&& V_62 -> V_139 -> V_165 )
V_62 -> V_139 -> V_165 ( & V_62 -> V_141 ) ;
}
if ( V_154 & V_166 ) {
F_6 ( V_89 , L_50 ) ;
F_3 ( V_166 ,
V_34 ) ;
if ( V_62 -> V_141 . V_159 != V_160
&& V_62 -> V_139
&& V_62 -> V_139 -> V_167 )
V_62 -> V_139 -> V_167 ( & V_62 -> V_141 ) ;
V_62 -> V_91 = V_92 ;
}
if ( V_155 & V_168 ) {
F_6 ( V_74 , L_51 ) ;
F_3 ( V_168 , V_33 ) ;
F_44 ( V_62 ) ;
}
for ( V_63 = 1 ; V_63 < V_64 ; V_63 ++ ) {
T_1 V_66 = 1 << V_63 ;
if ( V_155 & V_66 ) {
F_6 ( V_74 , L_52 , V_63 ) ;
F_3 ( V_66 , V_33 ) ;
F_45 ( & V_62 -> V_51 [ V_63 ] ) ;
}
}
if ( ! V_154 && ! V_155 && ! V_17 && ! V_119 ) {
for ( V_63 = 1 ; V_63 < V_64 ; V_63 ++ ) {
V_156 = F_1 ( V_37 ) ;
F_3 ( V_63 , V_37 ) ;
if ( F_1 ( V_98 ) & 0x1 )
F_45 ( & V_62 -> V_51 [ V_63 ] ) ;
F_3 ( V_156 , V_37 ) ;
}
}
F_6 ( V_74 , L_53 , V_169 ) ;
F_3 ( V_78 , V_37 ) ;
F_48 ( & V_62 -> V_158 , V_157 ) ;
return V_163 ;
}
static inline struct V_50 * F_49 ( struct V_170 * V_51 )
{
return F_50 ( V_51 , struct V_50 , V_51 ) ;
}
static inline struct V_59 * F_51 ( struct V_171 * V_141 )
{
return F_50 ( V_141 , struct V_59 , V_141 ) ;
}
static inline struct V_52 * F_52 ( struct V_172 * V_53 )
{
return F_50 ( V_53 , struct V_52 , V_53 ) ;
}
static int F_53 ( struct V_170 * V_173 ,
const struct V_174 * V_175 )
{
struct V_59 * V_62 ;
struct V_50 * V_51 ;
T_1 V_70 , V_66 ;
unsigned long V_157 ;
T_1 V_176 , V_177 ;
T_1 V_178 ;
V_51 = F_49 ( V_173 ) ;
if ( ! V_173 || ! V_175
|| V_173 -> V_179 == V_180
|| V_175 -> V_181 != V_182 )
return - V_183 ;
V_62 = V_51 -> V_62 ;
if ( ! V_62 -> V_139 || V_62 -> V_141 . V_159 == V_160 )
return - V_184 ;
V_70 = F_54 ( V_175 ) & 0x1fff ;
F_55 ( V_157 ) ;
V_173 -> V_87 = V_70 & 0x7ff ;
V_51 -> V_51 . V_175 = V_175 ;
V_51 -> V_55 = 0 ;
V_51 -> V_81 = V_175 -> V_81 ;
F_3 ( V_51 -> V_185 , V_37 ) ;
F_3 ( V_70 >> 3 , V_161 ) ;
if ( V_175 -> V_81 & V_111 ) {
V_176 = V_186 | V_187 ;
V_177 = V_188 | V_189 ;
F_3 ( V_51 -> V_185 , V_37 ) ;
F_3 ( V_176 , V_38 ) ;
F_3 ( V_51 -> V_185 , V_37 ) ;
F_3 ( V_177 , V_39 ) ;
} else {
V_176 = V_187 ;
V_177 = V_189 ;
F_3 ( V_51 -> V_185 , V_37 ) ;
F_3 ( V_176 , V_38 ) ;
F_3 ( V_51 -> V_185 , V_37 ) ;
F_3 ( V_177 , V_39 ) ;
V_176 = V_190 | V_191 ;
V_177 = V_192 ;
F_3 ( V_51 -> V_185 , V_37 ) ;
F_3 ( V_176 , V_98 ) ;
F_3 ( V_51 -> V_185 , V_37 ) ;
F_3 ( V_177 , V_193 ) ;
}
V_178 = F_1 ( V_35 ) ;
F_3 ( V_178 | ( 1 << V_51 -> V_185 ) , V_35 ) ;
V_66 = V_175 -> V_81 ;
F_6 ( V_89 , L_54 ,
V_173 -> V_179 , V_51 -> V_185 , V_66 ,
V_175 -> V_81 & V_111 ? L_55 : L_56 , V_70 ) ;
F_56 ( V_157 ) ;
F_43 ( V_173 , 0 ) ;
return 0 ;
}
static int F_57 ( struct V_170 * V_173 )
{
struct V_50 * V_51 = F_49 ( V_173 ) ;
unsigned long V_157 ;
T_1 V_178 ;
if ( ! V_173 || ! V_51 -> V_51 . V_175 ) {
F_6 ( V_89 , L_57 ,
V_173 ? V_51 -> V_51 . V_179 : NULL ) ;
return - V_183 ;
}
F_55 ( V_157 ) ;
F_6 ( V_89 , L_58 , V_173 -> V_179 ) ;
V_51 -> V_51 . V_175 = NULL ;
V_51 -> V_55 = 1 ;
F_26 ( V_51 -> V_62 , V_51 , - V_184 ) ;
V_178 = F_1 ( V_35 ) ;
F_3 ( V_178 & ~ ( 1 << V_51 -> V_185 ) , V_35 ) ;
F_56 ( V_157 ) ;
F_6 ( V_89 , L_59 , V_173 -> V_179 ) ;
return 0 ;
}
static struct V_172 *
F_58 ( struct V_170 * V_173 , T_7 V_194 )
{
struct V_52 * V_53 ;
F_6 ( V_74 , L_60 , V_75 , V_173 , V_194 ) ;
if ( ! V_173 )
return NULL ;
V_53 = F_59 ( sizeof( struct V_52 ) , V_194 ) ;
if ( ! V_53 )
return NULL ;
F_60 ( & V_53 -> V_56 ) ;
return & V_53 -> V_53 ;
}
static void
F_61 ( struct V_170 * V_173 , struct V_172 * V_195 )
{
struct V_50 * V_51 = F_49 ( V_173 ) ;
struct V_52 * V_53 = F_52 ( V_195 ) ;
F_6 ( V_74 , L_61 , V_75 , V_173 , V_195 ) ;
if ( ! V_51 || ! V_195 || ( ! V_51 -> V_51 . V_175 && V_173 -> V_179 != V_180 ) )
return;
F_62 ( ! F_27 ( & V_53 -> V_56 ) ) ;
F_63 ( V_53 ) ;
}
static int F_64 ( struct V_170 * V_173 , struct V_172 * V_195 ,
T_7 V_196 )
{
struct V_52 * V_53 = F_52 ( V_195 ) ;
struct V_50 * V_51 = F_49 ( V_173 ) ;
struct V_59 * V_62 ;
T_1 V_80 = 0 ;
int V_96 = 0 ;
unsigned long V_157 ;
if ( F_65 ( ! V_173 || ( ! V_51 -> V_51 . V_175 && V_51 -> V_51 . V_179 != V_180 ) ) ) {
F_6 ( V_89 , L_62 , V_75 ) ;
return - V_183 ;
}
V_62 = V_51 -> V_62 ;
if ( F_65 ( ! V_62 -> V_139
|| V_62 -> V_141 . V_159 == V_160 ) ) {
return - V_184 ;
}
F_55 ( V_157 ) ;
if ( F_65 ( ! V_195 || ! V_195 -> V_58
|| ! V_195 -> V_73 || ! F_27 ( & V_53 -> V_56 ) ) ) {
if ( ! V_195 )
F_6 ( V_89 , L_63 , V_75 ) ;
else {
F_6 ( V_89 , L_64 ,
V_75 , ! V_195 -> V_58 , ! V_195 -> V_73 ,
! F_27 ( & V_53 -> V_56 ) ) ;
}
F_56 ( V_157 ) ;
return - V_183 ;
}
V_195 -> V_54 = - V_57 ;
V_195 -> V_72 = 0 ;
F_6 ( V_74 , L_65 ,
V_75 , V_51 -> V_81 , V_195 -> V_71 ) ;
if ( V_51 -> V_81 ) {
F_3 ( V_51 -> V_81 & 0x7F , V_37 ) ;
V_80 = F_1 ( ( V_51 -> V_81 & V_111 )
? V_38
: V_98 ) ;
V_96 = F_30 () ;
} else {
F_3 ( 0 , V_37 ) ;
V_80 = F_1 ( V_38 ) ;
V_96 = F_30 () ;
}
if ( F_27 ( & V_51 -> V_56 ) && ! V_51 -> V_55 ) {
if ( V_51 -> V_81 == 0 ) {
switch ( V_62 -> V_91 ) {
case V_137 :
if ( ! ( V_80 & V_46 )
&& F_36 ( V_51 ,
V_53 ) ) {
V_62 -> V_91 = V_92 ;
V_53 = NULL ;
}
break;
case V_138 :
if ( ( ! V_195 -> V_71 )
|| ( ( V_80 & V_99 )
&& F_39 ( V_51 ,
V_53 ) ) ) {
V_62 -> V_91 = V_92 ;
V_53 = NULL ;
}
break;
default:
F_56 ( V_157 ) ;
return - V_197 ;
}
} else if ( ( V_51 -> V_81 & V_111 ) != 0
&& ( ! ( V_80 & V_99 ) )
&& F_36 ( V_51 , V_53 ) ) {
V_53 = NULL ;
} else if ( ( V_80 & V_99 )
&& V_96
&& F_39 ( V_51 , V_53 ) ) {
V_53 = NULL ;
}
}
if ( F_25 ( V_53 ) )
F_66 ( & V_53 -> V_56 , & V_51 -> V_56 ) ;
F_56 ( V_157 ) ;
F_6 ( V_74 , L_66 , V_75 ) ;
return 0 ;
}
static int F_67 ( struct V_170 * V_173 , struct V_172 * V_195 )
{
struct V_50 * V_51 = F_49 ( V_173 ) ;
struct V_59 * V_60 ;
int V_198 = - V_183 ;
unsigned long V_157 ;
struct V_52 * V_53 = NULL ;
F_6 ( V_74 , L_61 , V_75 , V_173 , V_195 ) ;
if ( ! V_199 -> V_139 )
return - V_184 ;
if ( ! V_173 || ! V_195 )
return V_198 ;
V_60 = F_51 ( V_51 -> V_141 ) ;
F_55 ( V_157 ) ;
F_68 (req, &ep->queue, queue) {
if ( & V_53 -> V_53 == V_195 ) {
F_24 ( & V_53 -> V_56 ) ;
V_195 -> V_54 = - V_200 ;
V_198 = 0 ;
break;
}
}
if ( V_198 == 0 ) {
F_6 ( V_74 ,
L_67 ,
V_53 , V_173 -> V_179 , V_195 -> V_71 , V_195 -> V_73 ) ;
F_23 ( V_51 , V_53 , - V_200 ) ;
}
F_56 ( V_157 ) ;
return V_198 ;
}
static int F_43 ( struct V_170 * V_173 , int V_3 )
{
struct V_50 * V_51 = F_49 ( V_173 ) ;
T_1 V_80 = 0 ;
unsigned long V_157 ;
T_1 V_78 ;
if ( F_65 ( ! V_173 || ( ! V_51 -> V_51 . V_175 && V_51 -> V_51 . V_179 != V_180 ) ) ) {
F_6 ( V_89 , L_68 , V_75 ) ;
return - V_183 ;
}
F_55 ( V_157 ) ;
V_78 = V_51 -> V_81 & 0x7F ;
if ( V_78 == 0 ) {
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
} else {
F_3 ( V_78 , V_37 ) ;
V_80 = F_1 ( ( V_51 -> V_81 & V_111 )
? V_38
: V_98 ) ;
if ( ( V_51 -> V_81 & V_111 ) != 0 ) {
if ( V_3 )
F_3 ( V_80 | V_117 ,
V_38 ) ;
else {
V_80 &= ~ V_117 ;
F_3 ( V_80 , V_38 ) ;
V_80 |= V_187 ;
F_3 ( V_80 , V_38 ) ;
}
} else {
if ( V_3 )
F_3 ( V_80 | V_118 ,
V_98 ) ;
else {
V_80 &= ~ V_118 ;
F_3 ( V_80 , V_98 ) ;
V_80 |= V_191 ;
F_3 ( V_80 , V_98 ) ;
}
}
}
V_51 -> V_55 = V_3 ? 1 : 0 ;
F_56 ( V_157 ) ;
return 0 ;
}
static int F_69 ( struct V_171 * V_201 )
{
int V_66 ;
F_6 ( V_74 , L_69 , V_75 ) ;
V_66 = F_1 ( V_202 ) << 8 ;
V_66 |= F_1 ( V_203 ) ;
return V_66 ;
}
static int F_70 ( struct V_171 * V_201 )
{
F_6 ( V_89 , L_69 , V_75 ) ;
return 0 ;
}
static int F_71 ( struct V_171 * V_141 , int V_3 )
{
struct V_59 * V_60 = F_51 ( V_141 ) ;
F_6 ( V_89 , L_69 , V_75 ) ;
if ( V_3 )
V_60 -> V_115 |= ( 1 << V_204 ) ;
else
V_60 -> V_115 &= ~ ( 1 << V_204 ) ;
return 0 ;
}
static int F_72 ( struct V_59 * V_60 , int V_205 )
{
F_6 ( V_89 , L_69 , V_75 ) ;
if ( V_206 && ( V_206 -> V_207 ||
F_73 ( V_206 -> V_208 ) ) ) {
if ( V_205 )
F_74 ( V_60 ) ;
else {
if ( V_60 -> V_141 . V_159 != V_160 ) {
if ( V_60 -> V_139 && V_60 -> V_139 -> V_209 )
V_60 -> V_139 -> V_209 ( & V_60 -> V_141 ) ;
}
F_75 ( V_60 ) ;
}
} else {
return - V_142 ;
}
return 0 ;
}
static int F_76 ( struct V_171 * V_141 , int V_210 )
{
struct V_59 * V_60 = F_51 ( V_141 ) ;
F_6 ( V_89 , L_69 , V_75 ) ;
V_60 -> V_211 = ( V_210 != 0 ) ;
F_72 ( V_60 , V_210 ) ;
return 0 ;
}
static int F_77 ( struct V_171 * V_141 , int V_205 )
{
struct V_59 * V_60 = F_51 ( V_141 ) ;
F_6 ( V_89 , L_69 , V_75 ) ;
F_72 ( V_60 , V_205 ? 0 : 1 ) ;
return 0 ;
}
static T_6 F_78 ( int V_212 , void * V_153 )
{
struct V_59 * V_62 = V_153 ;
unsigned int V_3 ;
F_6 ( V_89 , L_69 , V_75 ) ;
V_3 = F_79 ( V_206 -> V_213 ) ? 1 : 0 ;
if ( V_206 -> V_214 )
V_3 = ! V_3 ;
if ( V_3 != V_62 -> V_211 )
F_76 ( & V_62 -> V_141 , V_3 ) ;
return V_163 ;
}
static int F_80 ( struct V_171 * V_201 , unsigned V_215 )
{
F_6 ( V_89 , L_69 , V_75 ) ;
if ( V_206 && V_206 -> V_216 ) {
V_206 -> V_216 ( V_215 ) ;
return 0 ;
}
return - V_217 ;
}
static void F_81 ( enum V_218 V_219 )
{
if ( ! V_206 )
return;
if ( V_206 -> V_207 ) {
V_206 -> V_207 ( V_219 ) ;
} else if ( F_73 ( V_206 -> V_208 ) ) {
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
F_82 ( V_206 -> V_208 , V_3 ) ;
}
}
static void F_75 ( struct V_59 * V_62 )
{
F_6 ( V_89 , L_69 , V_75 ) ;
F_3 ( 0x00 , V_36 ) ;
F_3 ( 0x00 , V_35 ) ;
F_3 ( V_90
| V_164
| V_166 ,
V_34 ) ;
F_3 ( 0x1F , V_33 ) ;
F_81 ( V_221 ) ;
V_62 -> V_141 . V_159 = V_160 ;
}
static void F_83 ( struct V_59 * V_62 )
{
T_1 V_63 ;
F_60 ( & V_62 -> V_141 . V_223 ) ;
F_60 ( & V_62 -> V_141 . V_224 -> V_223 ) ;
V_62 -> V_91 = V_92 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
struct V_50 * V_51 = & V_62 -> V_51 [ V_63 ] ;
if ( V_63 != 0 )
F_66 ( & V_51 -> V_51 . V_223 , & V_62 -> V_141 . V_223 ) ;
V_51 -> V_62 = V_62 ;
V_51 -> V_51 . V_175 = NULL ;
V_51 -> V_55 = 0 ;
F_60 ( & V_51 -> V_56 ) ;
F_84 ( & V_51 -> V_51 , V_51 -> V_51 . V_87 ) ;
}
}
static void F_74 ( struct V_59 * V_62 )
{
int V_63 ;
F_6 ( V_89 , L_70 ) ;
V_62 -> V_141 . V_159 = V_162 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
F_3 ( V_63 , V_37 ) ;
F_3 ( ( V_62 -> V_51 [ V_63 ] . V_51 . V_87 & 0x7ff ) >> 3 ,
V_161 ) ;
}
F_3 ( V_225 , V_32 ) ;
F_3 ( V_90 | V_166 ,
V_36 ) ;
F_3 ( V_168 , V_35 ) ;
F_81 ( V_220 ) ;
}
static int F_85 ( struct V_171 * V_226 ,
struct V_227 * V_139 )
{
struct V_59 * V_60 = F_86 ( V_226 ) ;
F_6 ( V_89 , L_71 , V_75 , V_139 -> V_139 . V_179 ) ;
V_60 -> V_139 = V_139 ;
F_74 ( V_60 ) ;
return 0 ;
}
static int F_87 ( struct V_171 * V_226 ,
struct V_227 * V_139 )
{
struct V_59 * V_60 = F_86 ( V_226 ) ;
V_60 -> V_139 = NULL ;
F_75 ( V_60 ) ;
return 0 ;
}
static int F_88 ( struct V_228 * V_229 )
{
struct V_59 * V_60 = & V_230 ;
struct V_231 * V_62 = & V_229 -> V_62 ;
int V_198 ;
int V_212 ;
F_89 ( V_62 , L_69 , V_75 ) ;
V_232 = F_90 ( NULL , L_72 ) ;
if ( F_91 ( V_232 ) ) {
F_92 ( V_62 , L_73 ) ;
return F_93 ( V_232 ) ;
}
F_94 ( V_232 ) ;
V_233 = F_90 ( NULL , L_74 ) ;
if ( F_91 ( V_233 ) ) {
F_92 ( V_62 , L_75 ) ;
return F_93 ( V_233 ) ;
}
F_94 ( V_233 ) ;
F_95 ( 10 ) ;
F_89 ( V_62 , L_76 ) ;
if ( strncmp ( V_229 -> V_179 , L_77 , 7 ) == 0 ) {
F_96 ( V_62 , L_78 ) ;
V_230 . V_51 [ 1 ] . V_234 = V_235 ;
V_230 . V_51 [ 2 ] . V_234 = V_235 ;
V_230 . V_51 [ 3 ] . V_234 = V_235 ;
V_230 . V_51 [ 4 ] . V_234 = V_235 ;
}
F_97 ( & V_60 -> V_158 ) ;
V_206 = F_98 ( & V_229 -> V_62 ) ;
V_236 = V_237 ;
V_238 = V_239 ;
if ( ! F_99 ( V_236 , V_238 , V_240 ) )
return - V_241 ;
V_2 = F_100 ( V_236 , V_238 ) ;
if ( ! V_2 ) {
V_198 = - V_242 ;
goto V_243;
}
V_199 = V_60 ;
F_101 ( V_229 , V_60 ) ;
F_75 ( V_60 ) ;
F_83 ( V_60 ) ;
V_198 = F_102 ( V_169 , F_46 ,
0 , V_240 , V_60 ) ;
if ( V_198 != 0 ) {
F_92 ( V_62 , L_79 , V_169 , V_198 ) ;
V_198 = - V_241 ;
goto V_244;
}
F_89 ( V_62 , L_80 , V_169 ) ;
if ( V_206 && V_206 -> V_213 > 0 ) {
V_198 = F_103 ( V_206 -> V_213 , L_81 ) ;
if ( V_198 < 0 ) {
F_92 ( V_62 , L_82 ) ;
goto V_245;
}
V_212 = F_104 ( V_206 -> V_213 ) ;
if ( V_212 < 0 ) {
F_92 ( V_62 , L_83 ) ;
V_198 = V_212 ;
goto V_246;
}
V_198 = F_102 ( V_212 , F_78 ,
V_247
| V_248 | V_249 ,
V_240 , V_60 ) ;
if ( V_198 != 0 ) {
F_92 ( V_62 , L_84 ,
V_212 , V_198 ) ;
V_198 = - V_241 ;
goto V_246;
}
F_89 ( V_62 , L_80 , V_212 ) ;
} else {
V_60 -> V_211 = 1 ;
}
if ( V_206 && ! V_206 -> V_207 &&
F_73 ( V_206 -> V_208 ) ) {
V_198 = F_105 ( V_206 -> V_208 ,
V_206 -> V_214 ?
V_250 : V_251 ,
L_85 ) ;
if ( V_198 )
goto V_252;
}
V_198 = F_106 ( & V_229 -> V_62 , & V_60 -> V_141 ) ;
if ( V_198 )
goto V_253;
if ( V_254 ) {
V_60 -> V_255 = F_107 ( L_86 , V_256 ,
V_254 ,
V_60 , & V_257 ) ;
if ( ! V_60 -> V_255 )
F_108 ( V_62 , L_87 ) ;
}
F_89 ( V_62 , L_88 ) ;
return 0 ;
V_253:
if ( V_206 && ! V_206 -> V_207 &&
F_73 ( V_206 -> V_208 ) )
F_109 ( V_206 -> V_208 ) ;
V_252:
if ( V_206 && V_206 -> V_213 > 0 )
F_110 ( F_104 ( V_206 -> V_213 ) , V_60 ) ;
V_246:
if ( V_206 && V_206 -> V_213 > 0 )
F_109 ( V_206 -> V_213 ) ;
V_245:
F_110 ( V_169 , V_60 ) ;
V_244:
F_111 ( V_2 ) ;
V_243:
F_112 ( V_236 , V_238 ) ;
return V_198 ;
}
static int F_113 ( struct V_228 * V_229 )
{
struct V_59 * V_60 = F_114 ( V_229 ) ;
unsigned int V_212 ;
F_89 ( & V_229 -> V_62 , L_69 , V_75 ) ;
if ( V_60 -> V_139 )
return - V_241 ;
F_115 ( & V_60 -> V_141 ) ;
F_116 ( V_60 -> V_255 ) ;
if ( V_206 && ! V_206 -> V_207 &&
F_73 ( V_206 -> V_208 ) )
F_109 ( V_206 -> V_208 ) ;
if ( V_206 && V_206 -> V_213 > 0 ) {
V_212 = F_104 ( V_206 -> V_213 ) ;
F_110 ( V_212 , V_60 ) ;
}
F_110 ( V_169 , V_60 ) ;
F_111 ( V_2 ) ;
F_112 ( V_236 , V_238 ) ;
if ( ! F_91 ( V_233 ) && V_233 != NULL ) {
F_117 ( V_233 ) ;
F_118 ( V_233 ) ;
V_233 = NULL ;
}
if ( ! F_91 ( V_232 ) && V_232 != NULL ) {
F_117 ( V_232 ) ;
F_118 ( V_232 ) ;
V_232 = NULL ;
}
F_89 ( & V_229 -> V_62 , L_89 , V_75 ) ;
return 0 ;
}
static int
F_119 ( struct V_228 * V_229 , T_8 V_258 )
{
F_81 ( V_221 ) ;
return 0 ;
}
static int F_120 ( struct V_228 * V_229 )
{
F_81 ( V_220 ) ;
return 0 ;
}
static int T_9 F_121 ( void )
{
int V_198 ;
F_6 ( V_89 , L_90 , V_240 , V_259 ) ;
V_254 = F_122 ( V_240 , NULL ) ;
if ( F_91 ( V_254 ) ) {
F_123 ( L_91 ,
V_240 , F_93 ( V_254 ) ) ;
V_254 = NULL ;
}
V_198 = F_124 ( & V_260 ) ;
if ( V_198 )
goto V_261;
return 0 ;
V_261:
F_116 ( V_254 ) ;
return V_198 ;
}
static void T_10 F_125 ( void )
{
F_126 ( & V_260 ) ;
F_116 ( V_254 ) ;
}
