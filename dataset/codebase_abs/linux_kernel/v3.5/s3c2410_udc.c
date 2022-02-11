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
return F_9 ( V_13 L_2 , V_7 ) ;
}
static int F_6 ( int V_5 , const char * V_6 , ... )
{
return 0 ;
}
static int F_10 ( struct V_14 * V_15 , void * V_16 )
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
F_11 ( V_15 , L_3
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
V_17 , V_18 , V_19 , V_20 ,
V_21 , V_22 , V_23 ,
V_24 , V_25 , V_26 , V_27 ,
V_28 , V_29 , V_30 , V_31
) ;
return 0 ;
}
static int F_12 ( struct V_41 * V_41 ,
struct V_42 * V_42 )
{
return F_13 ( V_42 , F_10 , NULL ) ;
}
static inline void F_14 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_44 ,
V_45 ) ;
}
static inline void F_15 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_4 ( 0x00 , V_4 + V_45 ) ;
}
static inline void F_16 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_46 , V_45 ) ;
}
static inline void F_17 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_47 , V_45 ) ;
}
static inline void F_18 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , V_48 , V_45 ) ;
}
inline void F_19 ( void T_2 * V_49 )
{
F_5 ( V_49 , V_43 , V_38 ) ;
F_5 ( V_49 , V_50 , V_45 ) ;
}
static inline void F_20 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , ( V_44
| V_48 ) ,
V_45 ) ;
}
static inline void F_21 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , ( V_44
| V_46 ) ,
V_45 ) ;
}
static inline void F_22 ( void T_2 * V_4 )
{
F_5 ( V_4 , V_43 , V_38 ) ;
F_5 ( V_4 , ( V_47
| V_48 ) ,
V_45 ) ;
}
static void F_23 ( struct V_51 * V_52 ,
struct V_53 * V_54 , int V_55 )
{
unsigned V_56 = V_52 -> V_56 ;
F_24 ( & V_54 -> V_57 ) ;
if ( F_25 ( V_54 -> V_54 . V_55 == - V_58 ) )
V_54 -> V_54 . V_55 = V_55 ;
else
V_55 = V_54 -> V_54 . V_55 ;
V_52 -> V_56 = 1 ;
V_54 -> V_54 . V_59 ( & V_52 -> V_52 , & V_54 -> V_54 ) ;
V_52 -> V_56 = V_56 ;
}
static void F_26 ( struct V_60 * V_61 ,
struct V_51 * V_52 , int V_55 )
{
if ( & V_52 -> V_57 == NULL )
return;
while ( ! F_27 ( & V_52 -> V_57 ) ) {
struct V_53 * V_54 ;
V_54 = F_28 ( V_52 -> V_57 . V_62 , struct V_53 ,
V_57 ) ;
F_23 ( V_52 , V_54 , V_55 ) ;
}
}
static inline void F_29 ( struct V_60 * V_63 )
{
unsigned V_64 ;
for ( V_64 = 1 ; V_64 < V_65 ; V_64 ++ )
F_26 ( V_63 , & V_63 -> V_52 [ V_64 ] , - V_66 ) ;
}
static inline int F_30 ( void )
{
int V_67 ;
V_67 = F_1 ( V_68 ) << 8 ;
V_67 |= F_1 ( V_69 ) ;
return V_67 ;
}
static inline int F_31 ( int V_70 ,
struct V_53 * V_54 ,
unsigned V_71 )
{
unsigned V_10 = F_32 ( V_54 -> V_54 . V_72 - V_54 -> V_54 . V_73 , V_71 ) ;
T_4 * V_74 = V_54 -> V_54 . V_74 + V_54 -> V_54 . V_73 ;
F_33 ( V_74 ) ;
F_6 ( V_75 , L_18 , V_76 ,
V_54 -> V_54 . V_73 , V_54 -> V_54 . V_72 , V_10 , V_54 -> V_54 . V_73 + V_10 ) ;
V_54 -> V_54 . V_73 += V_10 ;
F_34 ( 5 ) ;
F_35 ( V_2 + V_70 , V_74 , V_10 ) ;
return V_10 ;
}
static int F_36 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
unsigned V_77 ;
int V_78 ;
T_1 V_79 ;
int V_80 ;
T_1 V_81 ;
V_79 = V_52 -> V_82 & 0x7F ;
switch ( V_79 ) {
default:
V_79 = 0 ;
case 0 :
V_80 = V_83 ;
break;
case 1 :
V_80 = V_84 ;
break;
case 2 :
V_80 = V_85 ;
break;
case 3 :
V_80 = V_86 ;
break;
case 4 :
V_80 = V_87 ;
break;
}
V_77 = F_31 ( V_80 , V_54 , V_52 -> V_52 . V_88 ) ;
if ( V_77 != V_52 -> V_52 . V_88 )
V_78 = 1 ;
else if ( V_54 -> V_54 . V_72 != V_54 -> V_54 . V_73 || V_54 -> V_54 . V_89 )
V_78 = 0 ;
else
V_78 = 2 ;
if ( V_79 == 0 )
F_6 ( V_90 ,
L_19 ,
V_79 , V_77 , V_54 -> V_54 . V_73 , V_54 -> V_54 . V_72 ,
V_78 , V_54 -> V_54 . V_89 ) ;
if ( V_78 ) {
if ( V_79 == 0 ) {
if ( ! ( F_1 ( V_35 )
& V_91 ) )
F_22 ( V_2 ) ;
V_52 -> V_63 -> V_92 = V_93 ;
} else {
F_3 ( V_79 , V_38 ) ;
V_81 = F_1 ( V_39 ) ;
F_3 ( V_79 , V_38 ) ;
F_3 ( V_81 | V_94 ,
V_39 ) ;
}
F_23 ( V_52 , V_54 , 0 ) ;
V_78 = 1 ;
} else {
if ( V_79 == 0 ) {
if ( ! ( F_1 ( V_35 )
& V_91 ) )
F_17 ( V_2 ) ;
} else {
F_3 ( V_79 , V_38 ) ;
V_81 = F_1 ( V_39 ) ;
F_3 ( V_79 , V_38 ) ;
F_3 ( V_81 | V_94 ,
V_39 ) ;
}
}
return V_78 ;
}
static inline int F_37 ( int V_70 , T_4 * V_74 ,
struct V_53 * V_54 , unsigned V_95 )
{
unsigned V_10 ;
V_10 = F_32 ( V_54 -> V_54 . V_72 - V_54 -> V_54 . V_73 , V_95 ) ;
V_54 -> V_54 . V_73 += V_10 ;
F_38 ( V_70 + V_2 , V_74 , V_10 ) ;
return V_10 ;
}
static int F_39 ( struct V_51 * V_52 ,
struct V_53 * V_54 )
{
T_4 * V_74 ;
T_1 V_81 ;
unsigned V_96 ;
int V_78 = 1 ;
unsigned V_95 ;
int V_97 = 0 ;
T_1 V_79 ;
int V_80 ;
V_79 = V_52 -> V_82 & 0x7F ;
switch ( V_79 ) {
default:
V_79 = 0 ;
case 0 :
V_80 = V_83 ;
break;
case 1 :
V_80 = V_84 ;
break;
case 2 :
V_80 = V_85 ;
break;
case 3 :
V_80 = V_86 ;
break;
case 4 :
V_80 = V_87 ;
break;
}
if ( ! V_54 -> V_54 . V_72 )
return 1 ;
V_74 = V_54 -> V_54 . V_74 + V_54 -> V_54 . V_73 ;
V_96 = V_54 -> V_54 . V_72 - V_54 -> V_54 . V_73 ;
if ( ! V_96 ) {
F_6 ( V_90 , L_20 , V_76 ) ;
return - 1 ;
}
F_3 ( V_79 , V_38 ) ;
V_97 = F_30 () ;
F_6 ( V_90 , L_21 , V_76 , V_97 ) ;
if ( V_97 > V_52 -> V_52 . V_88 )
V_95 = V_52 -> V_52 . V_88 ;
else
V_95 = V_97 ;
V_97 = F_37 ( V_80 , V_74 , V_54 , V_95 ) ;
if ( V_79 != 0 && V_97 < V_52 -> V_52 . V_88 ) {
V_78 = 1 ;
if ( V_97 != V_95 )
V_54 -> V_54 . V_55 = - V_98 ;
} else {
V_78 = ( V_54 -> V_54 . V_72 <= V_54 -> V_54 . V_73 ) ? 1 : 0 ;
}
F_3 ( V_79 , V_38 ) ;
V_97 = F_30 () ;
if ( V_79 == 0 )
F_6 ( V_75 , L_22 ,
V_76 , V_97 , V_78 ) ;
if ( V_78 ) {
if ( V_79 == 0 ) {
F_20 ( V_2 ) ;
V_52 -> V_63 -> V_92 = V_93 ;
} else {
F_3 ( V_79 , V_38 ) ;
V_81 = F_1 ( V_99 ) ;
F_3 ( V_79 , V_38 ) ;
F_3 ( V_81 & ~ V_100 ,
V_99 ) ;
}
F_23 ( V_52 , V_54 , 0 ) ;
} else {
if ( V_79 == 0 ) {
F_14 ( V_2 ) ;
} else {
F_3 ( V_79 , V_38 ) ;
V_81 = F_1 ( V_99 ) ;
F_3 ( V_79 , V_38 ) ;
F_3 ( V_81 & ~ V_100 ,
V_99 ) ;
}
}
return V_78 ;
}
static int F_40 ( struct V_101 * V_102 )
{
unsigned char * V_103 = ( unsigned char * ) V_102 ;
int V_104 = 0 ;
F_3 ( 0 , V_38 ) ;
V_104 = F_30 () ;
F_6 ( V_90 , L_23 , V_76 , V_104 ) ;
if ( V_104 > sizeof( struct V_101 ) )
V_104 = sizeof( struct V_101 ) ;
F_38 ( V_83 + V_2 , V_103 , V_104 ) ;
F_6 ( V_75 , L_24 , V_76 ,
V_104 , V_102 -> V_105 , V_102 -> V_106 ,
V_102 -> V_107 , V_102 -> V_108 , V_102 -> V_109 ) ;
return V_104 ;
}
static int F_41 ( struct V_60 * V_63 ,
struct V_101 * V_102 )
{
T_5 V_55 = 0 ;
T_4 V_110 = V_102 -> V_108 & 0x7F ;
T_4 V_111 = V_102 -> V_108 & V_112 ;
switch ( V_102 -> V_106 & V_113 ) {
case V_114 :
break;
case V_115 :
V_55 = V_63 -> V_116 ;
break;
case V_117 :
if ( V_110 > 4 || V_102 -> V_109 > 2 )
return 1 ;
if ( V_110 == 0 ) {
F_3 ( 0 , V_38 ) ;
V_55 = F_1 ( V_39 ) ;
V_55 = V_55 & V_50 ;
} else {
F_3 ( V_110 , V_38 ) ;
if ( V_111 ) {
V_55 = F_1 ( V_39 ) ;
V_55 = V_55 & V_118 ;
} else {
V_55 = F_1 ( V_99 ) ;
V_55 = V_55 & V_119 ;
}
}
V_55 = V_55 ? 1 : 0 ;
break;
default:
return 1 ;
}
F_34 ( 5 ) ;
F_3 ( V_55 & 0xFF , V_83 ) ;
F_3 ( V_55 >> 8 , V_83 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static void F_42 ( struct V_60 * V_63 ,
struct V_51 * V_52 ,
struct V_101 * V_102 ,
T_1 V_120 )
{
int V_10 , V_121 , V_67 ;
if ( ! ( V_120 & V_122 ) )
return;
F_26 ( V_63 , V_52 , - V_123 ) ;
V_10 = F_40 ( V_102 ) ;
if ( V_10 != sizeof( * V_102 ) ) {
F_6 ( V_90 , L_25
L_26 ,
sizeof( * V_102 ) , V_10 ) ;
F_19 ( V_2 ) ;
return;
}
F_6 ( V_90 , L_27 ,
V_102 -> V_105 , V_102 -> V_106 , V_102 -> V_109 ) ;
V_63 -> V_124 = ( V_102 -> V_106 & V_125 )
== V_126 ;
V_63 -> V_127 = 0 ;
V_63 -> V_128 = 1 ;
switch ( V_102 -> V_105 ) {
case V_129 :
F_6 ( V_90 , L_28 ) ;
if ( V_102 -> V_106 == V_115 ) {
V_63 -> V_127 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_130 :
F_6 ( V_90 , L_29 ) ;
if ( V_102 -> V_106 == V_114 ) {
V_63 -> V_127 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_131 :
F_6 ( V_90 , L_30 ) ;
if ( V_102 -> V_106 == V_115 ) {
V_67 = V_102 -> V_107 & 0x7F ;
V_63 -> V_132 = V_67 ;
F_3 ( ( V_67 | V_133 ) ,
V_32 ) ;
F_20 ( V_2 ) ;
return;
}
break;
case V_134 :
F_6 ( V_90 , L_31 ) ;
F_14 ( V_2 ) ;
if ( V_63 -> V_124 ) {
if ( ! F_41 ( V_63 , V_102 ) ) {
return;
}
}
break;
case V_135 :
F_14 ( V_2 ) ;
if ( V_102 -> V_106 != V_117 )
break;
if ( V_102 -> V_107 != V_136 || V_102 -> V_109 != 0 )
break;
F_43 ( & V_63 -> V_52 [ V_102 -> V_108 & 0x7f ] . V_52 , 0 ) ;
F_20 ( V_2 ) ;
return;
case V_137 :
F_14 ( V_2 ) ;
if ( V_102 -> V_106 != V_117 )
break;
if ( V_102 -> V_107 != V_136 || V_102 -> V_109 != 0 )
break;
F_43 ( & V_63 -> V_52 [ V_102 -> V_108 & 0x7f ] . V_52 , 1 ) ;
F_20 ( V_2 ) ;
return;
default:
F_14 ( V_2 ) ;
break;
}
if ( V_102 -> V_106 & V_112 )
V_63 -> V_92 = V_138 ;
else
V_63 -> V_92 = V_139 ;
if ( ! V_63 -> V_140 )
return;
V_121 = V_63 -> V_140 -> V_141 ( & V_63 -> V_142 , V_102 ) ;
if ( V_121 < 0 ) {
if ( V_63 -> V_127 ) {
F_6 ( V_90 , L_32 ,
V_102 -> V_105 , V_121 ) ;
return;
}
if ( V_121 == - V_143 )
F_6 ( V_90 , L_33 ) ;
else
F_6 ( V_90 ,
L_34 , V_121 ) ;
F_34 ( 5 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_63 -> V_92 = V_93 ;
} else if ( V_63 -> V_128 ) {
F_6 ( V_75 , L_35 ) ;
V_63 -> V_128 = 0 ;
}
F_6 ( V_75 , L_36 , V_144 [ V_63 -> V_92 ] ) ;
}
static void F_44 ( struct V_60 * V_63 )
{
T_1 V_120 ;
struct V_51 * V_52 = & V_63 -> V_52 [ 0 ] ;
struct V_53 * V_54 ;
struct V_101 V_102 ;
if ( F_27 ( & V_52 -> V_57 ) )
V_54 = NULL ;
else
V_54 = F_28 ( V_52 -> V_57 . V_62 , struct V_53 , V_57 ) ;
F_3 ( 0 , V_38 ) ;
V_120 = F_1 ( V_39 ) ;
F_6 ( V_90 , L_37 ,
V_120 , V_144 [ V_63 -> V_92 ] ) ;
if ( V_120 & V_145 ) {
F_26 ( V_63 , V_52 , - V_146 ) ;
F_6 ( V_90 , L_38 ) ;
F_15 ( V_2 ) ;
V_63 -> V_92 = V_93 ;
return;
}
if ( V_120 & V_147 ) {
F_6 ( V_90 , L_39 ) ;
F_26 ( V_63 , V_52 , 0 ) ;
F_16 ( V_2 ) ;
V_63 -> V_92 = V_93 ;
}
switch ( V_63 -> V_92 ) {
case V_93 :
F_42 ( V_63 , V_52 , & V_102 , V_120 ) ;
break;
case V_138 :
F_6 ( V_90 , L_40 ) ;
if ( ! ( V_120 & V_47 ) && V_54 ) {
F_36 ( V_52 , V_54 ) ;
}
break;
case V_139 :
F_6 ( V_90 , L_41 ) ;
if ( ( V_120 & V_122 ) && V_54 ) {
F_39 ( V_52 , V_54 ) ;
}
break;
case V_148 :
F_6 ( V_90 , L_42 ) ;
V_63 -> V_92 = V_93 ;
break;
case V_149 :
F_6 ( V_90 , L_43 ) ;
V_63 -> V_92 = V_93 ;
break;
}
}
static void F_45 ( struct V_51 * V_52 )
{
struct V_53 * V_54 ;
int V_111 = V_52 -> V_82 & V_112 ;
T_1 V_150 ;
T_1 V_79 ;
if ( F_25 ( ! F_27 ( & V_52 -> V_57 ) ) )
V_54 = F_28 ( V_52 -> V_57 . V_62 ,
struct V_53 , V_57 ) ;
else
V_54 = NULL ;
V_79 = V_52 -> V_82 & 0x7F ;
if ( V_111 ) {
F_3 ( V_79 , V_38 ) ;
V_150 = F_1 ( V_39 ) ;
F_6 ( V_75 , L_44 ,
V_79 , V_150 , V_54 ? 1 : 0 ) ;
if ( V_150 & V_151 ) {
F_6 ( V_75 , L_45 ) ;
F_3 ( V_79 , V_38 ) ;
F_3 ( V_150 & ~ V_151 ,
V_39 ) ;
return;
}
if ( ! ( V_150 & V_94 ) && V_54 ) {
F_36 ( V_52 , V_54 ) ;
}
} else {
F_3 ( V_79 , V_38 ) ;
V_150 = F_1 ( V_99 ) ;
F_6 ( V_75 , L_46 , V_79 , V_150 ) ;
if ( V_150 & V_152 ) {
F_3 ( V_79 , V_38 ) ;
F_3 ( V_150 & ~ V_152 ,
V_99 ) ;
return;
}
if ( ( V_150 & V_100 ) && V_54 ) {
F_39 ( V_52 , V_54 ) ;
}
}
}
static T_6 F_46 ( int V_153 , void * V_154 )
{
struct V_60 * V_63 = V_154 ;
int V_155 ;
int V_156 ;
int V_18 ;
int V_120 ;
int V_64 ;
T_1 V_79 , V_157 ;
unsigned long V_158 ;
F_47 ( & V_63 -> V_159 , V_158 ) ;
if ( ! V_63 -> V_140 ) {
F_3 ( F_1 ( V_35 ) ,
V_35 ) ;
F_3 ( F_1 ( V_34 ) ,
V_34 ) ;
}
V_79 = F_1 ( V_38 ) ;
V_155 = F_1 ( V_35 ) ;
V_156 = F_1 ( V_34 ) ;
V_18 = F_1 ( V_33 ) ;
F_5 ( V_2 , V_43 , V_38 ) ;
V_120 = F_1 ( V_39 ) ;
F_6 ( V_90 , L_47 ,
V_155 , V_156 , V_18 , V_120 ) ;
if ( V_155 & V_91 ) {
F_6 ( V_90 , L_48 ,
V_120 , V_18 ) ;
V_63 -> V_142 . V_160 = V_161 ;
F_3 ( 0x00 , V_38 ) ;
F_3 ( ( V_63 -> V_52 [ 0 ] . V_52 . V_88 & 0x7ff ) >> 3 ,
V_162 ) ;
V_63 -> V_132 = 0 ;
V_63 -> V_92 = V_93 ;
V_63 -> V_142 . V_160 = V_163 ;
F_3 ( V_91 ,
V_35 ) ;
F_3 ( V_79 , V_38 ) ;
F_48 ( & V_63 -> V_159 , V_158 ) ;
return V_164 ;
}
if ( V_155 & V_165 ) {
F_6 ( V_90 , L_49 ) ;
F_3 ( V_165 ,
V_35 ) ;
if ( V_63 -> V_142 . V_160 != V_161
&& V_63 -> V_140
&& V_63 -> V_140 -> V_166 )
V_63 -> V_140 -> V_166 ( & V_63 -> V_142 ) ;
}
if ( V_155 & V_167 ) {
F_6 ( V_90 , L_50 ) ;
F_3 ( V_167 ,
V_35 ) ;
if ( V_63 -> V_142 . V_160 != V_161
&& V_63 -> V_140
&& V_63 -> V_140 -> V_168 )
V_63 -> V_140 -> V_168 ( & V_63 -> V_142 ) ;
V_63 -> V_92 = V_93 ;
}
if ( V_156 & V_169 ) {
F_6 ( V_75 , L_51 ) ;
F_3 ( V_169 , V_34 ) ;
F_44 ( V_63 ) ;
}
for ( V_64 = 1 ; V_64 < V_65 ; V_64 ++ ) {
T_1 V_67 = 1 << V_64 ;
if ( V_156 & V_67 ) {
F_6 ( V_75 , L_52 , V_64 ) ;
F_3 ( V_67 , V_34 ) ;
F_45 ( & V_63 -> V_52 [ V_64 ] ) ;
}
}
if ( ! V_155 && ! V_156 && ! V_18 && ! V_120 ) {
for ( V_64 = 1 ; V_64 < V_65 ; V_64 ++ ) {
V_157 = F_1 ( V_38 ) ;
F_3 ( V_64 , V_38 ) ;
if ( F_1 ( V_99 ) & 0x1 )
F_45 ( & V_63 -> V_52 [ V_64 ] ) ;
F_3 ( V_157 , V_38 ) ;
}
}
F_6 ( V_75 , L_53 , V_170 ) ;
F_3 ( V_79 , V_38 ) ;
F_48 ( & V_63 -> V_159 , V_158 ) ;
return V_164 ;
}
static inline struct V_51 * F_49 ( struct V_171 * V_52 )
{
return F_50 ( V_52 , struct V_51 , V_52 ) ;
}
static inline struct V_60 * F_51 ( struct V_172 * V_142 )
{
return F_50 ( V_142 , struct V_60 , V_142 ) ;
}
static inline struct V_53 * F_52 ( struct V_173 * V_54 )
{
return F_50 ( V_54 , struct V_53 , V_54 ) ;
}
static int F_53 ( struct V_171 * V_174 ,
const struct V_175 * V_176 )
{
struct V_60 * V_63 ;
struct V_51 * V_52 ;
T_1 V_71 , V_67 ;
unsigned long V_158 ;
T_1 V_177 , V_178 ;
T_1 V_179 ;
V_52 = F_49 ( V_174 ) ;
if ( ! V_174 || ! V_176
|| V_174 -> V_180 == V_181
|| V_176 -> V_182 != V_183 )
return - V_184 ;
V_63 = V_52 -> V_63 ;
if ( ! V_63 -> V_140 || V_63 -> V_142 . V_160 == V_161 )
return - V_185 ;
V_71 = F_54 ( V_176 ) & 0x1fff ;
F_55 ( V_158 ) ;
V_174 -> V_88 = V_71 & 0x7ff ;
V_52 -> V_52 . V_176 = V_176 ;
V_52 -> V_56 = 0 ;
V_52 -> V_82 = V_176 -> V_82 ;
F_3 ( V_52 -> V_186 , V_38 ) ;
F_3 ( V_71 >> 3 , V_162 ) ;
if ( V_176 -> V_82 & V_112 ) {
V_177 = V_187 | V_188 ;
V_178 = V_189 | V_190 ;
F_3 ( V_52 -> V_186 , V_38 ) ;
F_3 ( V_177 , V_39 ) ;
F_3 ( V_52 -> V_186 , V_38 ) ;
F_3 ( V_178 , V_40 ) ;
} else {
V_177 = V_188 ;
V_178 = V_190 ;
F_3 ( V_52 -> V_186 , V_38 ) ;
F_3 ( V_177 , V_39 ) ;
F_3 ( V_52 -> V_186 , V_38 ) ;
F_3 ( V_178 , V_40 ) ;
V_177 = V_191 | V_192 ;
V_178 = V_193 ;
F_3 ( V_52 -> V_186 , V_38 ) ;
F_3 ( V_177 , V_99 ) ;
F_3 ( V_52 -> V_186 , V_38 ) ;
F_3 ( V_178 , V_194 ) ;
}
V_179 = F_1 ( V_36 ) ;
F_3 ( V_179 | ( 1 << V_52 -> V_186 ) , V_36 ) ;
V_67 = V_176 -> V_82 ;
F_6 ( V_90 , L_54 ,
V_174 -> V_180 , V_52 -> V_186 , V_67 ,
V_176 -> V_82 & V_112 ? L_55 : L_56 , V_71 ) ;
F_56 ( V_158 ) ;
F_43 ( V_174 , 0 ) ;
return 0 ;
}
static int F_57 ( struct V_171 * V_174 )
{
struct V_51 * V_52 = F_49 ( V_174 ) ;
unsigned long V_158 ;
T_1 V_179 ;
if ( ! V_174 || ! V_52 -> V_52 . V_176 ) {
F_6 ( V_90 , L_57 ,
V_174 ? V_52 -> V_52 . V_180 : NULL ) ;
return - V_184 ;
}
F_55 ( V_158 ) ;
F_6 ( V_90 , L_58 , V_174 -> V_180 ) ;
V_52 -> V_52 . V_176 = NULL ;
V_52 -> V_56 = 1 ;
F_26 ( V_52 -> V_63 , V_52 , - V_185 ) ;
V_179 = F_1 ( V_36 ) ;
F_3 ( V_179 & ~ ( 1 << V_52 -> V_186 ) , V_36 ) ;
F_56 ( V_158 ) ;
F_6 ( V_90 , L_59 , V_174 -> V_180 ) ;
return 0 ;
}
static struct V_173 *
F_58 ( struct V_171 * V_174 , T_7 V_195 )
{
struct V_53 * V_54 ;
F_6 ( V_75 , L_60 , V_76 , V_174 , V_195 ) ;
if ( ! V_174 )
return NULL ;
V_54 = F_59 ( sizeof( struct V_53 ) , V_195 ) ;
if ( ! V_54 )
return NULL ;
F_60 ( & V_54 -> V_57 ) ;
return & V_54 -> V_54 ;
}
static void
F_61 ( struct V_171 * V_174 , struct V_173 * V_196 )
{
struct V_51 * V_52 = F_49 ( V_174 ) ;
struct V_53 * V_54 = F_52 ( V_196 ) ;
F_6 ( V_75 , L_61 , V_76 , V_174 , V_196 ) ;
if ( ! V_52 || ! V_196 || ( ! V_52 -> V_52 . V_176 && V_174 -> V_180 != V_181 ) )
return;
F_62 ( ! F_27 ( & V_54 -> V_57 ) ) ;
F_63 ( V_54 ) ;
}
static int F_64 ( struct V_171 * V_174 , struct V_173 * V_196 ,
T_7 V_197 )
{
struct V_53 * V_54 = F_52 ( V_196 ) ;
struct V_51 * V_52 = F_49 ( V_174 ) ;
struct V_60 * V_63 ;
T_1 V_81 = 0 ;
int V_97 = 0 ;
unsigned long V_158 ;
if ( F_65 ( ! V_174 || ( ! V_52 -> V_52 . V_176 && V_52 -> V_52 . V_180 != V_181 ) ) ) {
F_6 ( V_90 , L_62 , V_76 ) ;
return - V_184 ;
}
V_63 = V_52 -> V_63 ;
if ( F_65 ( ! V_63 -> V_140
|| V_63 -> V_142 . V_160 == V_161 ) ) {
return - V_185 ;
}
F_55 ( V_158 ) ;
if ( F_65 ( ! V_196 || ! V_196 -> V_59
|| ! V_196 -> V_74 || ! F_27 ( & V_54 -> V_57 ) ) ) {
if ( ! V_196 )
F_6 ( V_90 , L_63 , V_76 ) ;
else {
F_6 ( V_90 , L_64 ,
V_76 , ! V_196 -> V_59 , ! V_196 -> V_74 ,
! F_27 ( & V_54 -> V_57 ) ) ;
}
F_56 ( V_158 ) ;
return - V_184 ;
}
V_196 -> V_55 = - V_58 ;
V_196 -> V_73 = 0 ;
F_6 ( V_75 , L_65 ,
V_76 , V_52 -> V_82 , V_196 -> V_72 ) ;
if ( V_52 -> V_82 ) {
F_3 ( V_52 -> V_82 & 0x7F , V_38 ) ;
V_81 = F_1 ( ( V_52 -> V_82 & V_112 )
? V_39
: V_99 ) ;
V_97 = F_30 () ;
} else {
F_3 ( 0 , V_38 ) ;
V_81 = F_1 ( V_39 ) ;
V_97 = F_30 () ;
}
if ( F_27 ( & V_52 -> V_57 ) && ! V_52 -> V_56 ) {
if ( V_52 -> V_82 == 0 ) {
switch ( V_63 -> V_92 ) {
case V_138 :
if ( ! ( V_81 & V_47 )
&& F_36 ( V_52 ,
V_54 ) ) {
V_63 -> V_92 = V_93 ;
V_54 = NULL ;
}
break;
case V_139 :
if ( ( ! V_196 -> V_72 )
|| ( ( V_81 & V_100 )
&& F_39 ( V_52 ,
V_54 ) ) ) {
V_63 -> V_92 = V_93 ;
V_54 = NULL ;
}
break;
default:
F_56 ( V_158 ) ;
return - V_198 ;
}
} else if ( ( V_52 -> V_82 & V_112 ) != 0
&& ( ! ( V_81 & V_100 ) )
&& F_36 ( V_52 , V_54 ) ) {
V_54 = NULL ;
} else if ( ( V_81 & V_100 )
&& V_97
&& F_39 ( V_52 , V_54 ) ) {
V_54 = NULL ;
}
}
if ( F_25 ( V_54 != 0 ) )
F_66 ( & V_54 -> V_57 , & V_52 -> V_57 ) ;
F_56 ( V_158 ) ;
F_6 ( V_75 , L_66 , V_76 ) ;
return 0 ;
}
static int F_67 ( struct V_171 * V_174 , struct V_173 * V_196 )
{
struct V_51 * V_52 = F_49 ( V_174 ) ;
struct V_60 * V_61 ;
int V_199 = - V_184 ;
unsigned long V_158 ;
struct V_53 * V_54 = NULL ;
F_6 ( V_75 , L_61 , V_76 , V_174 , V_196 ) ;
if ( ! V_200 -> V_140 )
return - V_185 ;
if ( ! V_174 || ! V_196 )
return V_199 ;
V_61 = F_51 ( V_52 -> V_142 ) ;
F_55 ( V_158 ) ;
F_68 (req, &ep->queue, queue) {
if ( & V_54 -> V_54 == V_196 ) {
F_24 ( & V_54 -> V_57 ) ;
V_196 -> V_55 = - V_201 ;
V_199 = 0 ;
break;
}
}
if ( V_199 == 0 ) {
F_6 ( V_75 ,
L_67 ,
V_54 , V_174 -> V_180 , V_196 -> V_72 , V_196 -> V_74 ) ;
F_23 ( V_52 , V_54 , - V_201 ) ;
}
F_56 ( V_158 ) ;
return V_199 ;
}
static int F_43 ( struct V_171 * V_174 , int V_3 )
{
struct V_51 * V_52 = F_49 ( V_174 ) ;
T_1 V_81 = 0 ;
unsigned long V_158 ;
T_1 V_79 ;
if ( F_65 ( ! V_174 || ( ! V_52 -> V_52 . V_176 && V_52 -> V_52 . V_180 != V_181 ) ) ) {
F_6 ( V_90 , L_68 , V_76 ) ;
return - V_184 ;
}
F_55 ( V_158 ) ;
V_79 = V_52 -> V_82 & 0x7F ;
if ( V_79 == 0 ) {
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
} else {
F_3 ( V_79 , V_38 ) ;
V_81 = F_1 ( ( V_52 -> V_82 & V_112 )
? V_39
: V_99 ) ;
if ( ( V_52 -> V_82 & V_112 ) != 0 ) {
if ( V_3 )
F_3 ( V_81 | V_118 ,
V_39 ) ;
else {
V_81 &= ~ V_118 ;
F_3 ( V_81 , V_39 ) ;
V_81 |= V_188 ;
F_3 ( V_81 , V_39 ) ;
}
} else {
if ( V_3 )
F_3 ( V_81 | V_119 ,
V_99 ) ;
else {
V_81 &= ~ V_119 ;
F_3 ( V_81 , V_99 ) ;
V_81 |= V_192 ;
F_3 ( V_81 , V_99 ) ;
}
}
}
V_52 -> V_56 = V_3 ? 1 : 0 ;
F_56 ( V_158 ) ;
return 0 ;
}
static int F_69 ( struct V_172 * V_202 )
{
int V_67 ;
F_6 ( V_75 , L_69 , V_76 ) ;
V_67 = F_1 ( V_203 ) << 8 ;
V_67 |= F_1 ( V_204 ) ;
return V_67 ;
}
static int F_70 ( struct V_172 * V_202 )
{
F_6 ( V_90 , L_69 , V_76 ) ;
return 0 ;
}
static int F_71 ( struct V_172 * V_142 , int V_3 )
{
struct V_60 * V_61 = F_51 ( V_142 ) ;
F_6 ( V_90 , L_69 , V_76 ) ;
if ( V_3 )
V_61 -> V_116 |= ( 1 << V_205 ) ;
else
V_61 -> V_116 &= ~ ( 1 << V_205 ) ;
return 0 ;
}
static int F_72 ( struct V_60 * V_61 , int V_206 )
{
F_6 ( V_90 , L_69 , V_76 ) ;
if ( V_207 && ( V_207 -> V_208 ||
F_73 ( V_207 -> V_209 ) ) ) {
if ( V_206 )
F_74 ( V_61 ) ;
else {
if ( V_61 -> V_142 . V_160 != V_161 ) {
if ( V_61 -> V_140 && V_61 -> V_140 -> V_210 )
V_61 -> V_140 -> V_210 ( & V_61 -> V_142 ) ;
}
F_75 ( V_61 ) ;
}
}
else
return - V_143 ;
return 0 ;
}
static int F_76 ( struct V_172 * V_142 , int V_211 )
{
struct V_60 * V_61 = F_51 ( V_142 ) ;
F_6 ( V_90 , L_69 , V_76 ) ;
V_61 -> V_212 = ( V_211 != 0 ) ;
F_72 ( V_61 , V_211 ) ;
return 0 ;
}
static int F_77 ( struct V_172 * V_142 , int V_206 )
{
struct V_60 * V_61 = F_51 ( V_142 ) ;
F_6 ( V_90 , L_69 , V_76 ) ;
F_72 ( V_61 , V_206 ? 0 : 1 ) ;
return 0 ;
}
static T_6 F_78 ( int V_213 , void * V_154 )
{
struct V_60 * V_63 = V_154 ;
unsigned int V_3 ;
F_6 ( V_90 , L_69 , V_76 ) ;
V_3 = F_79 ( V_207 -> V_214 ) ? 1 : 0 ;
if ( V_207 -> V_215 )
V_3 = ! V_3 ;
if ( V_3 != V_63 -> V_212 )
F_76 ( & V_63 -> V_142 , V_3 ) ;
return V_164 ;
}
static int F_80 ( struct V_172 * V_202 , unsigned V_216 )
{
F_6 ( V_90 , L_69 , V_76 ) ;
if ( V_207 && V_207 -> V_217 ) {
V_207 -> V_217 ( V_216 ) ;
return 0 ;
}
return - V_218 ;
}
static void F_81 ( enum V_219 V_220 )
{
if ( ! V_207 )
return;
if ( V_207 -> V_208 ) {
V_207 -> V_208 ( V_220 ) ;
} else if ( F_73 ( V_207 -> V_209 ) ) {
int V_3 ;
switch ( V_220 ) {
case V_221 :
V_3 = 1 ;
break;
case V_222 :
V_3 = 0 ;
break;
default:
return;
}
V_3 ^= V_207 -> V_223 ;
F_82 ( V_207 -> V_209 , V_3 ) ;
}
}
static void F_75 ( struct V_60 * V_63 )
{
F_6 ( V_90 , L_69 , V_76 ) ;
F_3 ( 0x00 , V_37 ) ;
F_3 ( 0x00 , V_36 ) ;
F_3 ( V_91
| V_165
| V_167 ,
V_35 ) ;
F_3 ( 0x1F , V_34 ) ;
F_81 ( V_222 ) ;
V_63 -> V_142 . V_160 = V_161 ;
}
static void F_83 ( struct V_60 * V_63 )
{
T_1 V_64 ;
F_60 ( & V_63 -> V_142 . V_224 ) ;
F_60 ( & V_63 -> V_142 . V_225 -> V_224 ) ;
V_63 -> V_92 = V_93 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
struct V_51 * V_52 = & V_63 -> V_52 [ V_64 ] ;
if ( V_64 != 0 )
F_66 ( & V_52 -> V_52 . V_224 , & V_63 -> V_142 . V_224 ) ;
V_52 -> V_63 = V_63 ;
V_52 -> V_52 . V_176 = NULL ;
V_52 -> V_56 = 0 ;
F_60 ( & V_52 -> V_57 ) ;
}
}
static void F_74 ( struct V_60 * V_63 )
{
int V_64 ;
F_6 ( V_90 , L_70 ) ;
V_63 -> V_142 . V_160 = V_163 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
F_3 ( V_64 , V_38 ) ;
F_3 ( ( V_63 -> V_52 [ V_64 ] . V_52 . V_88 & 0x7ff ) >> 3 ,
V_162 ) ;
}
F_3 ( V_226 , V_33 ) ;
F_3 ( V_91 | V_167 ,
V_37 ) ;
F_3 ( V_169 , V_36 ) ;
F_81 ( V_221 ) ;
}
static int F_84 ( struct V_227 * V_140 ,
int (* F_85)( struct V_172 * ) )
{
struct V_60 * V_61 = V_200 ;
int V_199 ;
F_6 ( V_90 , L_71 , V_76 , V_140 -> V_140 . V_180 ) ;
if ( ! V_61 )
return - V_228 ;
if ( V_61 -> V_140 )
return - V_229 ;
if ( ! F_85 || ! V_140 -> V_141 || V_140 -> V_230 < V_163 ) {
F_9 ( V_231 L_72 ,
F_85 , V_140 -> V_141 , V_140 -> V_230 ) ;
return - V_184 ;
}
#if F_86 ( V_232 )
if ( ! V_140 -> V_233 ) {
F_9 ( V_231 L_73 ) ;
return - V_184 ;
}
#endif
V_61 -> V_140 = V_140 ;
V_61 -> V_142 . V_63 . V_140 = & V_140 -> V_140 ;
if ( ( V_199 = F_87 ( & V_61 -> V_142 . V_63 ) ) != 0 ) {
F_9 ( V_231 L_74 , V_199 ) ;
goto V_234;
}
F_6 ( V_90 , L_75 ,
V_140 -> V_140 . V_180 ) ;
if ( ( V_199 = F_85 ( & V_61 -> V_142 ) ) != 0 ) {
F_88 ( & V_61 -> V_142 . V_63 ) ;
goto V_234;
}
F_74 ( V_61 ) ;
return 0 ;
V_234:
V_61 -> V_140 = NULL ;
V_61 -> V_142 . V_63 . V_140 = NULL ;
return V_199 ;
}
static int F_89 ( struct V_227 * V_140 )
{
struct V_60 * V_61 = V_200 ;
if ( ! V_61 )
return - V_228 ;
if ( ! V_140 || V_140 != V_61 -> V_140 || ! V_140 -> V_233 )
return - V_184 ;
F_6 ( V_90 , L_76 ,
V_140 -> V_140 . V_180 ) ;
if ( V_140 -> V_210 )
V_140 -> V_210 ( & V_61 -> V_142 ) ;
V_140 -> V_233 ( & V_61 -> V_142 ) ;
F_88 ( & V_61 -> V_142 . V_63 ) ;
V_61 -> V_140 = NULL ;
F_75 ( V_61 ) ;
return 0 ;
}
static int F_90 ( struct V_235 * V_236 )
{
struct V_60 * V_61 = & V_237 ;
struct V_238 * V_63 = & V_236 -> V_63 ;
int V_199 ;
int V_213 ;
F_91 ( V_63 , L_69 , V_76 ) ;
V_239 = F_92 ( NULL , L_77 ) ;
if ( F_93 ( V_239 ) ) {
F_94 ( V_63 , L_78 ) ;
return F_95 ( V_239 ) ;
}
F_96 ( V_239 ) ;
V_240 = F_92 ( NULL , L_79 ) ;
if ( F_93 ( V_240 ) ) {
F_94 ( V_63 , L_80 ) ;
return F_95 ( V_240 ) ;
}
F_96 ( V_240 ) ;
F_97 ( 10 ) ;
F_91 ( V_63 , L_81 ) ;
if ( strncmp ( V_236 -> V_180 , L_82 , 7 ) == 0 ) {
F_98 ( V_63 , L_83 ) ;
V_237 . V_52 [ 1 ] . V_241 = V_242 ;
V_237 . V_52 [ 2 ] . V_241 = V_242 ;
V_237 . V_52 [ 3 ] . V_241 = V_242 ;
V_237 . V_52 [ 4 ] . V_241 = V_242 ;
}
F_99 ( & V_61 -> V_159 ) ;
V_207 = V_236 -> V_63 . V_243 ;
V_244 = V_245 ;
V_246 = V_247 ;
if ( ! F_100 ( V_244 , V_246 , V_248 ) )
return - V_229 ;
V_2 = F_101 ( V_244 , V_246 ) ;
if ( ! V_2 ) {
V_199 = - V_249 ;
goto V_250;
}
F_102 ( & V_61 -> V_142 . V_63 ) ;
V_61 -> V_142 . V_63 . V_251 = & V_236 -> V_63 ;
V_61 -> V_142 . V_63 . V_252 = V_236 -> V_63 . V_252 ;
V_200 = V_61 ;
F_103 ( V_236 , V_61 ) ;
F_75 ( V_61 ) ;
F_83 ( V_61 ) ;
V_199 = F_104 ( V_170 , F_46 ,
0 , V_248 , V_61 ) ;
if ( V_199 != 0 ) {
F_94 ( V_63 , L_84 , V_170 , V_199 ) ;
V_199 = - V_229 ;
goto V_253;
}
F_91 ( V_63 , L_85 , V_170 ) ;
if ( V_207 && V_207 -> V_214 > 0 ) {
V_199 = F_105 ( V_207 -> V_214 , L_86 ) ;
if ( V_199 < 0 ) {
F_94 ( V_63 , L_87 ) ;
goto V_254;
}
V_213 = F_106 ( V_207 -> V_214 ) ;
if ( V_213 < 0 ) {
F_94 ( V_63 , L_88 ) ;
goto V_255;
}
V_199 = F_104 ( V_213 , F_78 ,
V_256
| V_257 | V_258 ,
V_248 , V_61 ) ;
if ( V_199 != 0 ) {
F_94 ( V_63 , L_89 ,
V_213 , V_199 ) ;
V_199 = - V_229 ;
goto V_255;
}
F_91 ( V_63 , L_85 , V_213 ) ;
} else {
V_61 -> V_212 = 1 ;
}
if ( V_207 && ! V_207 -> V_208 &&
F_73 ( V_207 -> V_209 ) ) {
V_199 = F_107 ( V_207 -> V_209 ,
V_207 -> V_215 ?
V_259 : V_260 ,
L_90 ) ;
if ( V_199 )
goto V_261;
}
V_199 = F_108 ( & V_236 -> V_63 , & V_61 -> V_142 ) ;
if ( V_199 )
goto V_262;
if ( V_263 ) {
V_61 -> V_264 = F_109 ( L_91 , V_265 ,
V_263 ,
V_61 , & V_266 ) ;
if ( ! V_61 -> V_264 )
F_110 ( V_63 , L_92 ) ;
}
F_91 ( V_63 , L_93 ) ;
return 0 ;
V_262:
if ( V_207 && ! V_207 -> V_208 &&
F_73 ( V_207 -> V_209 ) )
F_111 ( V_207 -> V_209 ) ;
V_261:
if ( V_207 && V_207 -> V_214 > 0 )
F_112 ( F_106 ( V_207 -> V_214 ) , V_61 ) ;
V_255:
if ( V_207 && V_207 -> V_214 > 0 )
F_111 ( V_207 -> V_214 ) ;
V_254:
F_112 ( V_170 , V_61 ) ;
V_253:
F_113 ( V_2 ) ;
V_250:
F_114 ( V_244 , V_246 ) ;
return V_199 ;
}
static int F_115 ( struct V_235 * V_236 )
{
struct V_60 * V_61 = F_116 ( V_236 ) ;
unsigned int V_213 ;
F_91 ( & V_236 -> V_63 , L_69 , V_76 ) ;
F_117 ( & V_61 -> V_142 ) ;
if ( V_61 -> V_140 )
return - V_229 ;
F_118 ( V_61 -> V_264 ) ;
if ( V_207 && ! V_207 -> V_208 &&
F_73 ( V_207 -> V_209 ) )
F_111 ( V_207 -> V_209 ) ;
if ( V_207 && V_207 -> V_214 > 0 ) {
V_213 = F_106 ( V_207 -> V_214 ) ;
F_112 ( V_213 , V_61 ) ;
}
F_112 ( V_170 , V_61 ) ;
F_113 ( V_2 ) ;
F_114 ( V_244 , V_246 ) ;
F_103 ( V_236 , NULL ) ;
if ( ! F_93 ( V_240 ) && V_240 != NULL ) {
F_119 ( V_240 ) ;
F_120 ( V_240 ) ;
V_240 = NULL ;
}
if ( ! F_93 ( V_239 ) && V_239 != NULL ) {
F_119 ( V_239 ) ;
F_120 ( V_239 ) ;
V_239 = NULL ;
}
F_91 ( & V_236 -> V_63 , L_94 , V_76 ) ;
return 0 ;
}
static int F_121 ( struct V_235 * V_236 , T_8 V_267 )
{
F_81 ( V_222 ) ;
return 0 ;
}
static int F_122 ( struct V_235 * V_236 )
{
F_81 ( V_221 ) ;
return 0 ;
}
static int T_9 F_123 ( void )
{
int V_199 ;
F_6 ( V_90 , L_95 , V_248 , V_268 ) ;
V_263 = F_124 ( V_248 , NULL ) ;
if ( F_93 ( V_263 ) ) {
F_9 ( V_231 L_96 ,
V_248 , F_95 ( V_263 ) ) ;
V_263 = NULL ;
}
V_199 = F_125 ( & V_269 ) ;
if ( V_199 )
goto V_270;
return 0 ;
V_270:
F_118 ( V_263 ) ;
return V_199 ;
}
static void T_10 F_126 ( void )
{
F_127 ( & V_269 ) ;
F_118 ( V_263 ) ;
}
