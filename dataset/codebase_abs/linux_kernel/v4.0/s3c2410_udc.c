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
F_5 ( V_4 , ( V_46
| V_47 ) ,
V_44 ) ;
}
static void F_22 ( struct V_50 * V_51 ,
struct V_52 * V_53 , int V_54 )
{
unsigned V_55 = V_51 -> V_55 ;
F_23 ( & V_53 -> V_56 ) ;
if ( F_24 ( V_53 -> V_53 . V_54 == - V_57 ) )
V_53 -> V_53 . V_54 = V_54 ;
else
V_54 = V_53 -> V_53 . V_54 ;
V_51 -> V_55 = 1 ;
F_25 ( & V_51 -> V_51 , & V_53 -> V_53 ) ;
V_51 -> V_55 = V_55 ;
}
static void F_26 ( struct V_58 * V_59 ,
struct V_50 * V_51 , int V_54 )
{
if ( & V_51 -> V_56 == NULL )
return;
while ( ! F_27 ( & V_51 -> V_56 ) ) {
struct V_52 * V_53 ;
V_53 = F_28 ( V_51 -> V_56 . V_60 , struct V_52 ,
V_56 ) ;
F_22 ( V_51 , V_53 , V_54 ) ;
}
}
static inline int F_29 ( void )
{
int V_61 ;
V_61 = F_1 ( V_62 ) << 8 ;
V_61 |= F_1 ( V_63 ) ;
return V_61 ;
}
static inline int F_30 ( int V_64 ,
struct V_52 * V_53 ,
unsigned V_65 )
{
unsigned V_10 = F_31 ( V_53 -> V_53 . V_66 - V_53 -> V_53 . V_67 , V_65 ) ;
T_4 * V_68 = V_53 -> V_53 . V_68 + V_53 -> V_53 . V_67 ;
F_32 ( V_68 ) ;
F_6 ( V_69 , L_18 , V_70 ,
V_53 -> V_53 . V_67 , V_53 -> V_53 . V_66 , V_10 , V_53 -> V_53 . V_67 + V_10 ) ;
V_53 -> V_53 . V_67 += V_10 ;
F_33 ( 5 ) ;
F_34 ( V_2 + V_64 , V_68 , V_10 ) ;
return V_10 ;
}
static int F_35 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
unsigned V_71 ;
int V_72 ;
T_1 V_73 ;
int V_74 ;
T_1 V_75 ;
V_73 = V_51 -> V_76 & 0x7F ;
switch ( V_73 ) {
default:
V_73 = 0 ;
case 0 :
V_74 = V_77 ;
break;
case 1 :
V_74 = V_78 ;
break;
case 2 :
V_74 = V_79 ;
break;
case 3 :
V_74 = V_80 ;
break;
case 4 :
V_74 = V_81 ;
break;
}
V_71 = F_30 ( V_74 , V_53 , V_51 -> V_51 . V_82 ) ;
if ( V_71 != V_51 -> V_51 . V_82 )
V_72 = 1 ;
else if ( V_53 -> V_53 . V_66 != V_53 -> V_53 . V_67 || V_53 -> V_53 . V_83 )
V_72 = 0 ;
else
V_72 = 2 ;
if ( V_73 == 0 )
F_6 ( V_84 ,
L_19 ,
V_73 , V_71 , V_53 -> V_53 . V_67 , V_53 -> V_53 . V_66 ,
V_72 , V_53 -> V_53 . V_83 ) ;
if ( V_72 ) {
if ( V_73 == 0 ) {
if ( ! ( F_1 ( V_34 )
& V_85 ) )
F_21 ( V_2 ) ;
V_51 -> V_86 -> V_87 = V_88 ;
} else {
F_3 ( V_73 , V_37 ) ;
V_75 = F_1 ( V_38 ) ;
F_3 ( V_73 , V_37 ) ;
F_3 ( V_75 | V_89 ,
V_38 ) ;
}
F_22 ( V_51 , V_53 , 0 ) ;
V_72 = 1 ;
} else {
if ( V_73 == 0 ) {
if ( ! ( F_1 ( V_34 )
& V_85 ) )
F_17 ( V_2 ) ;
} else {
F_3 ( V_73 , V_37 ) ;
V_75 = F_1 ( V_38 ) ;
F_3 ( V_73 , V_37 ) ;
F_3 ( V_75 | V_89 ,
V_38 ) ;
}
}
return V_72 ;
}
static inline int F_36 ( int V_64 , T_4 * V_68 ,
struct V_52 * V_53 , unsigned V_90 )
{
unsigned V_10 ;
V_10 = F_31 ( V_53 -> V_53 . V_66 - V_53 -> V_53 . V_67 , V_90 ) ;
V_53 -> V_53 . V_67 += V_10 ;
F_37 ( V_64 + V_2 , V_68 , V_10 ) ;
return V_10 ;
}
static int F_38 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
T_4 * V_68 ;
T_1 V_75 ;
unsigned V_91 ;
int V_72 = 1 ;
unsigned V_90 ;
int V_92 = 0 ;
T_1 V_73 ;
int V_74 ;
V_73 = V_51 -> V_76 & 0x7F ;
switch ( V_73 ) {
default:
V_73 = 0 ;
case 0 :
V_74 = V_77 ;
break;
case 1 :
V_74 = V_78 ;
break;
case 2 :
V_74 = V_79 ;
break;
case 3 :
V_74 = V_80 ;
break;
case 4 :
V_74 = V_81 ;
break;
}
if ( ! V_53 -> V_53 . V_66 )
return 1 ;
V_68 = V_53 -> V_53 . V_68 + V_53 -> V_53 . V_67 ;
V_91 = V_53 -> V_53 . V_66 - V_53 -> V_53 . V_67 ;
if ( ! V_91 ) {
F_6 ( V_84 , L_20 , V_70 ) ;
return - 1 ;
}
F_3 ( V_73 , V_37 ) ;
V_92 = F_29 () ;
F_6 ( V_84 , L_21 , V_70 , V_92 ) ;
if ( V_92 > V_51 -> V_51 . V_82 )
V_90 = V_51 -> V_51 . V_82 ;
else
V_90 = V_92 ;
V_92 = F_36 ( V_74 , V_68 , V_53 , V_90 ) ;
if ( V_73 != 0 && V_92 < V_51 -> V_51 . V_82 ) {
V_72 = 1 ;
if ( V_92 != V_90 )
V_53 -> V_53 . V_54 = - V_93 ;
} else {
V_72 = ( V_53 -> V_53 . V_66 <= V_53 -> V_53 . V_67 ) ? 1 : 0 ;
}
F_3 ( V_73 , V_37 ) ;
V_92 = F_29 () ;
if ( V_73 == 0 )
F_6 ( V_69 , L_22 ,
V_70 , V_92 , V_72 ) ;
if ( V_72 ) {
if ( V_73 == 0 ) {
F_20 ( V_2 ) ;
V_51 -> V_86 -> V_87 = V_88 ;
} else {
F_3 ( V_73 , V_37 ) ;
V_75 = F_1 ( V_94 ) ;
F_3 ( V_73 , V_37 ) ;
F_3 ( V_75 & ~ V_95 ,
V_94 ) ;
}
F_22 ( V_51 , V_53 , 0 ) ;
} else {
if ( V_73 == 0 ) {
F_14 ( V_2 ) ;
} else {
F_3 ( V_73 , V_37 ) ;
V_75 = F_1 ( V_94 ) ;
F_3 ( V_73 , V_37 ) ;
F_3 ( V_75 & ~ V_95 ,
V_94 ) ;
}
}
return V_72 ;
}
static int F_39 ( struct V_96 * V_97 )
{
unsigned char * V_98 = ( unsigned char * ) V_97 ;
int V_99 = 0 ;
F_3 ( 0 , V_37 ) ;
V_99 = F_29 () ;
F_6 ( V_84 , L_23 , V_70 , V_99 ) ;
if ( V_99 > sizeof( struct V_96 ) )
V_99 = sizeof( struct V_96 ) ;
F_37 ( V_77 + V_2 , V_98 , V_99 ) ;
F_6 ( V_69 , L_24 , V_70 ,
V_99 , V_97 -> V_100 , V_97 -> V_101 ,
V_97 -> V_102 , V_97 -> V_103 , V_97 -> V_104 ) ;
return V_99 ;
}
static int F_40 ( struct V_58 * V_86 ,
struct V_96 * V_97 )
{
T_5 V_54 = 0 ;
T_4 V_105 = V_97 -> V_103 & 0x7F ;
T_4 V_106 = V_97 -> V_103 & V_107 ;
switch ( V_97 -> V_101 & V_108 ) {
case V_109 :
break;
case V_110 :
V_54 = V_86 -> V_111 ;
break;
case V_112 :
if ( V_105 > 4 || V_97 -> V_104 > 2 )
return 1 ;
if ( V_105 == 0 ) {
F_3 ( 0 , V_37 ) ;
V_54 = F_1 ( V_38 ) ;
V_54 = V_54 & V_49 ;
} else {
F_3 ( V_105 , V_37 ) ;
if ( V_106 ) {
V_54 = F_1 ( V_38 ) ;
V_54 = V_54 & V_113 ;
} else {
V_54 = F_1 ( V_94 ) ;
V_54 = V_54 & V_114 ;
}
}
V_54 = V_54 ? 1 : 0 ;
break;
default:
return 1 ;
}
F_33 ( 5 ) ;
F_3 ( V_54 & 0xFF , V_77 ) ;
F_3 ( V_54 >> 8 , V_77 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_58 * V_86 ,
struct V_50 * V_51 ,
struct V_96 * V_97 ,
T_1 V_115 )
{
int V_10 , V_116 , V_61 ;
if ( ! ( V_115 & V_117 ) )
return;
F_26 ( V_86 , V_51 , - V_118 ) ;
V_10 = F_39 ( V_97 ) ;
if ( V_10 != sizeof( * V_97 ) ) {
F_6 ( V_84 , L_25
L_26 ,
sizeof( * V_97 ) , V_10 ) ;
F_19 ( V_2 ) ;
return;
}
F_6 ( V_84 , L_27 ,
V_97 -> V_100 , V_97 -> V_101 , V_97 -> V_104 ) ;
V_86 -> V_119 = ( V_97 -> V_101 & V_120 )
== V_121 ;
V_86 -> V_122 = 0 ;
V_86 -> V_123 = 1 ;
switch ( V_97 -> V_100 ) {
case V_124 :
F_6 ( V_84 , L_28 ) ;
if ( V_97 -> V_101 == V_110 ) {
V_86 -> V_122 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_125 :
F_6 ( V_84 , L_29 ) ;
if ( V_97 -> V_101 == V_109 ) {
V_86 -> V_122 = 1 ;
F_20 ( V_2 ) ;
}
break;
case V_126 :
F_6 ( V_84 , L_30 ) ;
if ( V_97 -> V_101 == V_110 ) {
V_61 = V_97 -> V_102 & 0x7F ;
V_86 -> V_127 = V_61 ;
F_3 ( ( V_61 | V_128 ) ,
V_31 ) ;
F_20 ( V_2 ) ;
return;
}
break;
case V_129 :
F_6 ( V_84 , L_31 ) ;
F_14 ( V_2 ) ;
if ( V_86 -> V_119 ) {
if ( ! F_40 ( V_86 , V_97 ) )
return;
}
break;
case V_130 :
F_14 ( V_2 ) ;
if ( V_97 -> V_101 != V_112 )
break;
if ( V_97 -> V_102 != V_131 || V_97 -> V_104 != 0 )
break;
F_42 ( & V_86 -> V_51 [ V_97 -> V_103 & 0x7f ] . V_51 , 0 ) ;
F_20 ( V_2 ) ;
return;
case V_132 :
F_14 ( V_2 ) ;
if ( V_97 -> V_101 != V_112 )
break;
if ( V_97 -> V_102 != V_131 || V_97 -> V_104 != 0 )
break;
F_42 ( & V_86 -> V_51 [ V_97 -> V_103 & 0x7f ] . V_51 , 1 ) ;
F_20 ( V_2 ) ;
return;
default:
F_14 ( V_2 ) ;
break;
}
if ( V_97 -> V_101 & V_107 )
V_86 -> V_87 = V_133 ;
else
V_86 -> V_87 = V_134 ;
if ( ! V_86 -> V_135 )
return;
V_116 = V_86 -> V_135 -> V_136 ( & V_86 -> V_137 , V_97 ) ;
if ( V_116 < 0 ) {
if ( V_86 -> V_122 ) {
F_6 ( V_84 , L_32 ,
V_97 -> V_100 , V_116 ) ;
return;
}
if ( V_116 == - V_138 )
F_6 ( V_84 , L_33 ) ;
else
F_6 ( V_84 ,
L_34 , V_116 ) ;
F_33 ( 5 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
V_86 -> V_87 = V_88 ;
} else if ( V_86 -> V_123 ) {
F_6 ( V_69 , L_35 ) ;
V_86 -> V_123 = 0 ;
}
F_6 ( V_69 , L_36 , V_139 [ V_86 -> V_87 ] ) ;
}
static void F_43 ( struct V_58 * V_86 )
{
T_1 V_115 ;
struct V_50 * V_51 = & V_86 -> V_51 [ 0 ] ;
struct V_52 * V_53 ;
struct V_96 V_97 ;
if ( F_27 ( & V_51 -> V_56 ) )
V_53 = NULL ;
else
V_53 = F_28 ( V_51 -> V_56 . V_60 , struct V_52 , V_56 ) ;
F_3 ( 0 , V_37 ) ;
V_115 = F_1 ( V_38 ) ;
F_6 ( V_84 , L_37 ,
V_115 , V_139 [ V_86 -> V_87 ] ) ;
if ( V_115 & V_140 ) {
F_26 ( V_86 , V_51 , - V_141 ) ;
F_6 ( V_84 , L_38 ) ;
F_15 ( V_2 ) ;
V_86 -> V_87 = V_88 ;
return;
}
if ( V_115 & V_142 ) {
F_6 ( V_84 , L_39 ) ;
F_26 ( V_86 , V_51 , 0 ) ;
F_16 ( V_2 ) ;
V_86 -> V_87 = V_88 ;
}
switch ( V_86 -> V_87 ) {
case V_88 :
F_41 ( V_86 , V_51 , & V_97 , V_115 ) ;
break;
case V_133 :
F_6 ( V_84 , L_40 ) ;
if ( ! ( V_115 & V_46 ) && V_53 )
F_35 ( V_51 , V_53 ) ;
break;
case V_134 :
F_6 ( V_84 , L_41 ) ;
if ( ( V_115 & V_117 ) && V_53 )
F_38 ( V_51 , V_53 ) ;
break;
case V_143 :
F_6 ( V_84 , L_42 ) ;
V_86 -> V_87 = V_88 ;
break;
case V_144 :
F_6 ( V_84 , L_43 ) ;
V_86 -> V_87 = V_88 ;
break;
}
}
static void F_44 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
int V_106 = V_51 -> V_76 & V_107 ;
T_1 V_145 ;
T_1 V_73 ;
if ( F_24 ( ! F_27 ( & V_51 -> V_56 ) ) )
V_53 = F_28 ( V_51 -> V_56 . V_60 ,
struct V_52 , V_56 ) ;
else
V_53 = NULL ;
V_73 = V_51 -> V_76 & 0x7F ;
if ( V_106 ) {
F_3 ( V_73 , V_37 ) ;
V_145 = F_1 ( V_38 ) ;
F_6 ( V_69 , L_44 ,
V_73 , V_145 , V_53 ? 1 : 0 ) ;
if ( V_145 & V_146 ) {
F_6 ( V_69 , L_45 ) ;
F_3 ( V_73 , V_37 ) ;
F_3 ( V_145 & ~ V_146 ,
V_38 ) ;
return;
}
if ( ! ( V_145 & V_89 ) && V_53 )
F_35 ( V_51 , V_53 ) ;
} else {
F_3 ( V_73 , V_37 ) ;
V_145 = F_1 ( V_94 ) ;
F_6 ( V_69 , L_46 , V_73 , V_145 ) ;
if ( V_145 & V_147 ) {
F_3 ( V_73 , V_37 ) ;
F_3 ( V_145 & ~ V_147 ,
V_94 ) ;
return;
}
if ( ( V_145 & V_95 ) && V_53 )
F_38 ( V_51 , V_53 ) ;
}
}
static T_6 F_45 ( int V_148 , void * V_149 )
{
struct V_58 * V_86 = V_149 ;
int V_150 ;
int V_151 ;
int V_17 ;
int V_115 ;
int V_152 ;
T_1 V_73 , V_153 ;
unsigned long V_154 ;
F_46 ( & V_86 -> V_155 , V_154 ) ;
if ( ! V_86 -> V_135 ) {
F_3 ( F_1 ( V_34 ) ,
V_34 ) ;
F_3 ( F_1 ( V_33 ) ,
V_33 ) ;
}
V_73 = F_1 ( V_37 ) ;
V_150 = F_1 ( V_34 ) ;
V_151 = F_1 ( V_33 ) ;
V_17 = F_1 ( V_32 ) ;
F_5 ( V_2 , V_42 , V_37 ) ;
V_115 = F_1 ( V_38 ) ;
F_6 ( V_84 , L_47 ,
V_150 , V_151 , V_17 , V_115 ) ;
if ( V_150 & V_85 ) {
F_6 ( V_84 , L_48 ,
V_115 , V_17 ) ;
V_86 -> V_137 . V_156 = V_157 ;
F_3 ( 0x00 , V_37 ) ;
F_3 ( ( V_86 -> V_51 [ 0 ] . V_51 . V_82 & 0x7ff ) >> 3 ,
V_158 ) ;
V_86 -> V_127 = 0 ;
V_86 -> V_87 = V_88 ;
V_86 -> V_137 . V_156 = V_159 ;
F_3 ( V_85 ,
V_34 ) ;
F_3 ( V_73 , V_37 ) ;
F_47 ( & V_86 -> V_155 , V_154 ) ;
return V_160 ;
}
if ( V_150 & V_161 ) {
F_6 ( V_84 , L_49 ) ;
F_3 ( V_161 ,
V_34 ) ;
if ( V_86 -> V_137 . V_156 != V_157
&& V_86 -> V_135
&& V_86 -> V_135 -> V_162 )
V_86 -> V_135 -> V_162 ( & V_86 -> V_137 ) ;
}
if ( V_150 & V_163 ) {
F_6 ( V_84 , L_50 ) ;
F_3 ( V_163 ,
V_34 ) ;
if ( V_86 -> V_137 . V_156 != V_157
&& V_86 -> V_135
&& V_86 -> V_135 -> V_164 )
V_86 -> V_135 -> V_164 ( & V_86 -> V_137 ) ;
V_86 -> V_87 = V_88 ;
}
if ( V_151 & V_165 ) {
F_6 ( V_69 , L_51 ) ;
F_3 ( V_165 , V_33 ) ;
F_43 ( V_86 ) ;
}
for ( V_152 = 1 ; V_152 < V_166 ; V_152 ++ ) {
T_1 V_61 = 1 << V_152 ;
if ( V_151 & V_61 ) {
F_6 ( V_69 , L_52 , V_152 ) ;
F_3 ( V_61 , V_33 ) ;
F_44 ( & V_86 -> V_51 [ V_152 ] ) ;
}
}
if ( ! V_150 && ! V_151 && ! V_17 && ! V_115 ) {
for ( V_152 = 1 ; V_152 < V_166 ; V_152 ++ ) {
V_153 = F_1 ( V_37 ) ;
F_3 ( V_152 , V_37 ) ;
if ( F_1 ( V_94 ) & 0x1 )
F_44 ( & V_86 -> V_51 [ V_152 ] ) ;
F_3 ( V_153 , V_37 ) ;
}
}
F_6 ( V_69 , L_53 , V_167 ) ;
F_3 ( V_73 , V_37 ) ;
F_47 ( & V_86 -> V_155 , V_154 ) ;
return V_160 ;
}
static inline struct V_50 * F_48 ( struct V_168 * V_51 )
{
return F_49 ( V_51 , struct V_50 , V_51 ) ;
}
static inline struct V_58 * F_50 ( struct V_169 * V_137 )
{
return F_49 ( V_137 , struct V_58 , V_137 ) ;
}
static inline struct V_52 * F_51 ( struct V_170 * V_53 )
{
return F_49 ( V_53 , struct V_52 , V_53 ) ;
}
static int F_52 ( struct V_168 * V_171 ,
const struct V_172 * V_173 )
{
struct V_58 * V_86 ;
struct V_50 * V_51 ;
T_1 V_65 , V_61 ;
unsigned long V_154 ;
T_1 V_174 , V_175 ;
T_1 V_176 ;
V_51 = F_48 ( V_171 ) ;
if ( ! V_171 || ! V_173
|| V_171 -> V_177 == V_178
|| V_173 -> V_179 != V_180 )
return - V_181 ;
V_86 = V_51 -> V_86 ;
if ( ! V_86 -> V_135 || V_86 -> V_137 . V_156 == V_157 )
return - V_182 ;
V_65 = F_53 ( V_173 ) & 0x1fff ;
F_54 ( V_154 ) ;
V_171 -> V_82 = V_65 & 0x7ff ;
V_51 -> V_51 . V_173 = V_173 ;
V_51 -> V_55 = 0 ;
V_51 -> V_76 = V_173 -> V_76 ;
F_3 ( V_51 -> V_183 , V_37 ) ;
F_3 ( V_65 >> 3 , V_158 ) ;
if ( V_173 -> V_76 & V_107 ) {
V_174 = V_184 | V_185 ;
V_175 = V_186 | V_187 ;
F_3 ( V_51 -> V_183 , V_37 ) ;
F_3 ( V_174 , V_38 ) ;
F_3 ( V_51 -> V_183 , V_37 ) ;
F_3 ( V_175 , V_39 ) ;
} else {
V_174 = V_185 ;
V_175 = V_187 ;
F_3 ( V_51 -> V_183 , V_37 ) ;
F_3 ( V_174 , V_38 ) ;
F_3 ( V_51 -> V_183 , V_37 ) ;
F_3 ( V_175 , V_39 ) ;
V_174 = V_188 | V_189 ;
V_175 = V_190 ;
F_3 ( V_51 -> V_183 , V_37 ) ;
F_3 ( V_174 , V_94 ) ;
F_3 ( V_51 -> V_183 , V_37 ) ;
F_3 ( V_175 , V_191 ) ;
}
V_176 = F_1 ( V_35 ) ;
F_3 ( V_176 | ( 1 << V_51 -> V_183 ) , V_35 ) ;
V_61 = V_173 -> V_76 ;
F_6 ( V_84 , L_54 ,
V_171 -> V_177 , V_51 -> V_183 , V_61 ,
V_173 -> V_76 & V_107 ? L_55 : L_56 , V_65 ) ;
F_55 ( V_154 ) ;
F_42 ( V_171 , 0 ) ;
return 0 ;
}
static int F_56 ( struct V_168 * V_171 )
{
struct V_50 * V_51 = F_48 ( V_171 ) ;
unsigned long V_154 ;
T_1 V_176 ;
if ( ! V_171 || ! V_51 -> V_51 . V_173 ) {
F_6 ( V_84 , L_57 ,
V_171 ? V_51 -> V_51 . V_177 : NULL ) ;
return - V_181 ;
}
F_54 ( V_154 ) ;
F_6 ( V_84 , L_58 , V_171 -> V_177 ) ;
V_51 -> V_51 . V_173 = NULL ;
V_51 -> V_55 = 1 ;
F_26 ( V_51 -> V_86 , V_51 , - V_182 ) ;
V_176 = F_1 ( V_35 ) ;
F_3 ( V_176 & ~ ( 1 << V_51 -> V_183 ) , V_35 ) ;
F_55 ( V_154 ) ;
F_6 ( V_84 , L_59 , V_171 -> V_177 ) ;
return 0 ;
}
static struct V_170 *
F_57 ( struct V_168 * V_171 , T_7 V_192 )
{
struct V_52 * V_53 ;
F_6 ( V_69 , L_60 , V_70 , V_171 , V_192 ) ;
if ( ! V_171 )
return NULL ;
V_53 = F_58 ( sizeof( struct V_52 ) , V_192 ) ;
if ( ! V_53 )
return NULL ;
F_59 ( & V_53 -> V_56 ) ;
return & V_53 -> V_53 ;
}
static void
F_60 ( struct V_168 * V_171 , struct V_170 * V_193 )
{
struct V_50 * V_51 = F_48 ( V_171 ) ;
struct V_52 * V_53 = F_51 ( V_193 ) ;
F_6 ( V_69 , L_61 , V_70 , V_171 , V_193 ) ;
if ( ! V_51 || ! V_193 || ( ! V_51 -> V_51 . V_173 && V_171 -> V_177 != V_178 ) )
return;
F_61 ( ! F_27 ( & V_53 -> V_56 ) ) ;
F_62 ( V_53 ) ;
}
static int F_63 ( struct V_168 * V_171 , struct V_170 * V_193 ,
T_7 V_194 )
{
struct V_52 * V_53 = F_51 ( V_193 ) ;
struct V_50 * V_51 = F_48 ( V_171 ) ;
struct V_58 * V_86 ;
T_1 V_75 = 0 ;
int V_92 = 0 ;
unsigned long V_154 ;
if ( F_64 ( ! V_171 || ( ! V_51 -> V_51 . V_173 && V_51 -> V_51 . V_177 != V_178 ) ) ) {
F_6 ( V_84 , L_62 , V_70 ) ;
return - V_181 ;
}
V_86 = V_51 -> V_86 ;
if ( F_64 ( ! V_86 -> V_135
|| V_86 -> V_137 . V_156 == V_157 ) ) {
return - V_182 ;
}
F_54 ( V_154 ) ;
if ( F_64 ( ! V_193 || ! V_193 -> V_195
|| ! V_193 -> V_68 || ! F_27 ( & V_53 -> V_56 ) ) ) {
if ( ! V_193 )
F_6 ( V_84 , L_63 , V_70 ) ;
else {
F_6 ( V_84 , L_64 ,
V_70 , ! V_193 -> V_195 , ! V_193 -> V_68 ,
! F_27 ( & V_53 -> V_56 ) ) ;
}
F_55 ( V_154 ) ;
return - V_181 ;
}
V_193 -> V_54 = - V_57 ;
V_193 -> V_67 = 0 ;
F_6 ( V_69 , L_65 ,
V_70 , V_51 -> V_76 , V_193 -> V_66 ) ;
if ( V_51 -> V_76 ) {
F_3 ( V_51 -> V_76 & 0x7F , V_37 ) ;
V_75 = F_1 ( ( V_51 -> V_76 & V_107 )
? V_38
: V_94 ) ;
V_92 = F_29 () ;
} else {
F_3 ( 0 , V_37 ) ;
V_75 = F_1 ( V_38 ) ;
V_92 = F_29 () ;
}
if ( F_27 ( & V_51 -> V_56 ) && ! V_51 -> V_55 ) {
if ( V_51 -> V_76 == 0 ) {
switch ( V_86 -> V_87 ) {
case V_133 :
if ( ! ( V_75 & V_46 )
&& F_35 ( V_51 ,
V_53 ) ) {
V_86 -> V_87 = V_88 ;
V_53 = NULL ;
}
break;
case V_134 :
if ( ( ! V_193 -> V_66 )
|| ( ( V_75 & V_95 )
&& F_38 ( V_51 ,
V_53 ) ) ) {
V_86 -> V_87 = V_88 ;
V_53 = NULL ;
}
break;
default:
F_55 ( V_154 ) ;
return - V_196 ;
}
} else if ( ( V_51 -> V_76 & V_107 ) != 0
&& ( ! ( V_75 & V_95 ) )
&& F_35 ( V_51 , V_53 ) ) {
V_53 = NULL ;
} else if ( ( V_75 & V_95 )
&& V_92
&& F_38 ( V_51 , V_53 ) ) {
V_53 = NULL ;
}
}
if ( F_24 ( V_53 ) )
F_65 ( & V_53 -> V_56 , & V_51 -> V_56 ) ;
F_55 ( V_154 ) ;
F_6 ( V_69 , L_66 , V_70 ) ;
return 0 ;
}
static int F_66 ( struct V_168 * V_171 , struct V_170 * V_193 )
{
struct V_50 * V_51 = F_48 ( V_171 ) ;
struct V_58 * V_59 ;
int V_197 = - V_181 ;
unsigned long V_154 ;
struct V_52 * V_53 = NULL ;
F_6 ( V_69 , L_61 , V_70 , V_171 , V_193 ) ;
if ( ! V_198 -> V_135 )
return - V_182 ;
if ( ! V_171 || ! V_193 )
return V_197 ;
V_59 = F_50 ( V_51 -> V_137 ) ;
F_54 ( V_154 ) ;
F_67 (req, &ep->queue, queue) {
if ( & V_53 -> V_53 == V_193 ) {
F_23 ( & V_53 -> V_56 ) ;
V_193 -> V_54 = - V_199 ;
V_197 = 0 ;
break;
}
}
if ( V_197 == 0 ) {
F_6 ( V_69 ,
L_67 ,
V_53 , V_171 -> V_177 , V_193 -> V_66 , V_193 -> V_68 ) ;
F_22 ( V_51 , V_53 , - V_199 ) ;
}
F_55 ( V_154 ) ;
return V_197 ;
}
static int F_42 ( struct V_168 * V_171 , int V_3 )
{
struct V_50 * V_51 = F_48 ( V_171 ) ;
T_1 V_75 = 0 ;
unsigned long V_154 ;
T_1 V_73 ;
if ( F_64 ( ! V_171 || ( ! V_51 -> V_51 . V_173 && V_51 -> V_51 . V_177 != V_178 ) ) ) {
F_6 ( V_84 , L_68 , V_70 ) ;
return - V_181 ;
}
F_54 ( V_154 ) ;
V_73 = V_51 -> V_76 & 0x7F ;
if ( V_73 == 0 ) {
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
} else {
F_3 ( V_73 , V_37 ) ;
V_75 = F_1 ( ( V_51 -> V_76 & V_107 )
? V_38
: V_94 ) ;
if ( ( V_51 -> V_76 & V_107 ) != 0 ) {
if ( V_3 )
F_3 ( V_75 | V_113 ,
V_38 ) ;
else {
V_75 &= ~ V_113 ;
F_3 ( V_75 , V_38 ) ;
V_75 |= V_185 ;
F_3 ( V_75 , V_38 ) ;
}
} else {
if ( V_3 )
F_3 ( V_75 | V_114 ,
V_94 ) ;
else {
V_75 &= ~ V_114 ;
F_3 ( V_75 , V_94 ) ;
V_75 |= V_189 ;
F_3 ( V_75 , V_94 ) ;
}
}
}
V_51 -> V_55 = V_3 ? 1 : 0 ;
F_55 ( V_154 ) ;
return 0 ;
}
static int F_68 ( struct V_169 * V_200 )
{
int V_61 ;
F_6 ( V_69 , L_69 , V_70 ) ;
V_61 = F_1 ( V_201 ) << 8 ;
V_61 |= F_1 ( V_202 ) ;
return V_61 ;
}
static int F_69 ( struct V_169 * V_200 )
{
F_6 ( V_84 , L_69 , V_70 ) ;
return 0 ;
}
static int F_70 ( struct V_169 * V_137 , int V_3 )
{
struct V_58 * V_59 = F_50 ( V_137 ) ;
F_6 ( V_84 , L_69 , V_70 ) ;
V_137 -> V_203 = ( V_3 != 0 ) ;
if ( V_3 )
V_59 -> V_111 |= ( 1 << V_204 ) ;
else
V_59 -> V_111 &= ~ ( 1 << V_204 ) ;
return 0 ;
}
static int F_71 ( struct V_58 * V_59 , int V_205 )
{
F_6 ( V_84 , L_69 , V_70 ) ;
if ( V_206 && ( V_206 -> V_207 ||
F_72 ( V_206 -> V_208 ) ) ) {
if ( V_205 )
F_73 ( V_59 ) ;
else {
if ( V_59 -> V_137 . V_156 != V_157 ) {
if ( V_59 -> V_135 && V_59 -> V_135 -> V_209 )
V_59 -> V_135 -> V_209 ( & V_59 -> V_137 ) ;
}
F_74 ( V_59 ) ;
}
} else {
return - V_138 ;
}
return 0 ;
}
static int F_75 ( struct V_169 * V_137 , int V_210 )
{
struct V_58 * V_59 = F_50 ( V_137 ) ;
F_6 ( V_84 , L_69 , V_70 ) ;
V_59 -> V_211 = ( V_210 != 0 ) ;
F_71 ( V_59 , V_210 ) ;
return 0 ;
}
static int F_76 ( struct V_169 * V_137 , int V_205 )
{
struct V_58 * V_59 = F_50 ( V_137 ) ;
F_6 ( V_84 , L_69 , V_70 ) ;
F_71 ( V_59 , V_205 ? 0 : 1 ) ;
return 0 ;
}
static T_6 F_77 ( int V_212 , void * V_149 )
{
struct V_58 * V_86 = V_149 ;
unsigned int V_3 ;
F_6 ( V_84 , L_69 , V_70 ) ;
V_3 = F_78 ( V_206 -> V_213 ) ? 1 : 0 ;
if ( V_206 -> V_214 )
V_3 = ! V_3 ;
if ( V_3 != V_86 -> V_211 )
F_75 ( & V_86 -> V_137 , V_3 ) ;
return V_160 ;
}
static int F_79 ( struct V_169 * V_200 , unsigned V_215 )
{
F_6 ( V_84 , L_69 , V_70 ) ;
if ( V_206 && V_206 -> V_216 ) {
V_206 -> V_216 ( V_215 ) ;
return 0 ;
}
return - V_217 ;
}
static void F_80 ( enum V_218 V_219 )
{
if ( ! V_206 )
return;
if ( V_206 -> V_207 ) {
V_206 -> V_207 ( V_219 ) ;
} else if ( F_72 ( V_206 -> V_208 ) ) {
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
F_81 ( V_206 -> V_208 , V_3 ) ;
}
}
static void F_74 ( struct V_58 * V_86 )
{
F_6 ( V_84 , L_69 , V_70 ) ;
F_3 ( 0x00 , V_36 ) ;
F_3 ( 0x00 , V_35 ) ;
F_3 ( V_85
| V_161
| V_163 ,
V_34 ) ;
F_3 ( 0x1F , V_33 ) ;
F_80 ( V_221 ) ;
V_86 -> V_137 . V_156 = V_157 ;
}
static void F_82 ( struct V_58 * V_86 )
{
T_1 V_152 ;
F_59 ( & V_86 -> V_137 . V_223 ) ;
F_59 ( & V_86 -> V_137 . V_224 -> V_223 ) ;
V_86 -> V_87 = V_88 ;
for ( V_152 = 0 ; V_152 < V_166 ; V_152 ++ ) {
struct V_50 * V_51 = & V_86 -> V_51 [ V_152 ] ;
if ( V_152 != 0 )
F_65 ( & V_51 -> V_51 . V_223 , & V_86 -> V_137 . V_223 ) ;
V_51 -> V_86 = V_86 ;
V_51 -> V_51 . V_173 = NULL ;
V_51 -> V_55 = 0 ;
F_59 ( & V_51 -> V_56 ) ;
F_83 ( & V_51 -> V_51 , V_51 -> V_51 . V_82 ) ;
}
}
static void F_73 ( struct V_58 * V_86 )
{
int V_152 ;
F_6 ( V_84 , L_70 ) ;
V_86 -> V_137 . V_156 = V_159 ;
for ( V_152 = 0 ; V_152 < V_166 ; V_152 ++ ) {
F_3 ( V_152 , V_37 ) ;
F_3 ( ( V_86 -> V_51 [ V_152 ] . V_51 . V_82 & 0x7ff ) >> 3 ,
V_158 ) ;
}
F_3 ( V_225 , V_32 ) ;
F_3 ( V_85 | V_163 ,
V_36 ) ;
F_3 ( V_165 , V_35 ) ;
F_80 ( V_220 ) ;
}
static int F_84 ( struct V_169 * V_226 ,
struct V_227 * V_135 )
{
struct V_58 * V_59 = F_85 ( V_226 ) ;
F_6 ( V_84 , L_71 , V_70 , V_135 -> V_135 . V_177 ) ;
V_59 -> V_135 = V_135 ;
F_73 ( V_59 ) ;
return 0 ;
}
static int F_86 ( struct V_169 * V_226 )
{
struct V_58 * V_59 = F_85 ( V_226 ) ;
V_59 -> V_135 = NULL ;
F_74 ( V_59 ) ;
return 0 ;
}
static int F_87 ( struct V_228 * V_229 )
{
struct V_58 * V_59 = & V_230 ;
struct V_231 * V_86 = & V_229 -> V_86 ;
int V_197 ;
int V_212 ;
F_88 ( V_86 , L_69 , V_70 ) ;
V_232 = F_89 ( NULL , L_72 ) ;
if ( F_90 ( V_232 ) ) {
F_91 ( V_86 , L_73 ) ;
return F_92 ( V_232 ) ;
}
F_93 ( V_232 ) ;
V_233 = F_89 ( NULL , L_74 ) ;
if ( F_90 ( V_233 ) ) {
F_91 ( V_86 , L_75 ) ;
return F_92 ( V_233 ) ;
}
F_93 ( V_233 ) ;
F_94 ( 10 ) ;
F_88 ( V_86 , L_76 ) ;
if ( strncmp ( V_229 -> V_177 , L_77 , 7 ) == 0 ) {
F_95 ( V_86 , L_78 ) ;
V_230 . V_51 [ 1 ] . V_234 = V_235 ;
V_230 . V_51 [ 2 ] . V_234 = V_235 ;
V_230 . V_51 [ 3 ] . V_234 = V_235 ;
V_230 . V_51 [ 4 ] . V_234 = V_235 ;
}
F_96 ( & V_59 -> V_155 ) ;
V_206 = F_97 ( & V_229 -> V_86 ) ;
V_236 = V_237 ;
V_238 = V_239 ;
if ( ! F_98 ( V_236 , V_238 , V_240 ) )
return - V_241 ;
V_2 = F_99 ( V_236 , V_238 ) ;
if ( ! V_2 ) {
V_197 = - V_242 ;
goto V_243;
}
V_198 = V_59 ;
F_100 ( V_229 , V_59 ) ;
F_74 ( V_59 ) ;
F_82 ( V_59 ) ;
V_197 = F_101 ( V_167 , F_45 ,
0 , V_240 , V_59 ) ;
if ( V_197 != 0 ) {
F_91 ( V_86 , L_79 , V_167 , V_197 ) ;
V_197 = - V_241 ;
goto V_244;
}
F_88 ( V_86 , L_80 , V_167 ) ;
if ( V_206 && V_206 -> V_213 > 0 ) {
V_197 = F_102 ( V_206 -> V_213 , L_81 ) ;
if ( V_197 < 0 ) {
F_91 ( V_86 , L_82 ) ;
goto V_245;
}
V_212 = F_103 ( V_206 -> V_213 ) ;
if ( V_212 < 0 ) {
F_91 ( V_86 , L_83 ) ;
V_197 = V_212 ;
goto V_246;
}
V_197 = F_101 ( V_212 , F_77 ,
V_247
| V_248 | V_249 ,
V_240 , V_59 ) ;
if ( V_197 != 0 ) {
F_91 ( V_86 , L_84 ,
V_212 , V_197 ) ;
V_197 = - V_241 ;
goto V_246;
}
F_88 ( V_86 , L_80 , V_212 ) ;
} else {
V_59 -> V_211 = 1 ;
}
if ( V_206 && ! V_206 -> V_207 &&
F_72 ( V_206 -> V_208 ) ) {
V_197 = F_104 ( V_206 -> V_208 ,
V_206 -> V_214 ?
V_250 : V_251 ,
L_85 ) ;
if ( V_197 )
goto V_252;
}
V_197 = F_105 ( & V_229 -> V_86 , & V_59 -> V_137 ) ;
if ( V_197 )
goto V_253;
if ( V_254 ) {
V_59 -> V_255 = F_106 ( L_86 , V_256 ,
V_254 ,
V_59 , & V_257 ) ;
if ( ! V_59 -> V_255 )
F_107 ( V_86 , L_87 ) ;
}
F_88 ( V_86 , L_88 ) ;
return 0 ;
V_253:
if ( V_206 && ! V_206 -> V_207 &&
F_72 ( V_206 -> V_208 ) )
F_108 ( V_206 -> V_208 ) ;
V_252:
if ( V_206 && V_206 -> V_213 > 0 )
F_109 ( F_103 ( V_206 -> V_213 ) , V_59 ) ;
V_246:
if ( V_206 && V_206 -> V_213 > 0 )
F_108 ( V_206 -> V_213 ) ;
V_245:
F_109 ( V_167 , V_59 ) ;
V_244:
F_110 ( V_2 ) ;
V_243:
F_111 ( V_236 , V_238 ) ;
return V_197 ;
}
static int F_112 ( struct V_228 * V_229 )
{
struct V_58 * V_59 = F_113 ( V_229 ) ;
unsigned int V_212 ;
F_88 ( & V_229 -> V_86 , L_69 , V_70 ) ;
if ( V_59 -> V_135 )
return - V_241 ;
F_114 ( & V_59 -> V_137 ) ;
F_115 ( V_59 -> V_255 ) ;
if ( V_206 && ! V_206 -> V_207 &&
F_72 ( V_206 -> V_208 ) )
F_108 ( V_206 -> V_208 ) ;
if ( V_206 && V_206 -> V_213 > 0 ) {
V_212 = F_103 ( V_206 -> V_213 ) ;
F_109 ( V_212 , V_59 ) ;
}
F_109 ( V_167 , V_59 ) ;
F_110 ( V_2 ) ;
F_111 ( V_236 , V_238 ) ;
if ( ! F_90 ( V_233 ) && V_233 != NULL ) {
F_116 ( V_233 ) ;
F_117 ( V_233 ) ;
V_233 = NULL ;
}
if ( ! F_90 ( V_232 ) && V_232 != NULL ) {
F_116 ( V_232 ) ;
F_117 ( V_232 ) ;
V_232 = NULL ;
}
F_88 ( & V_229 -> V_86 , L_89 , V_70 ) ;
return 0 ;
}
static int
F_118 ( struct V_228 * V_229 , T_8 V_258 )
{
F_80 ( V_221 ) ;
return 0 ;
}
static int F_119 ( struct V_228 * V_229 )
{
F_80 ( V_220 ) ;
return 0 ;
}
static int T_9 F_120 ( void )
{
int V_197 ;
F_6 ( V_84 , L_90 , V_240 , V_259 ) ;
V_254 = F_121 ( V_240 , NULL ) ;
if ( F_90 ( V_254 ) ) {
F_122 ( L_91 ,
V_240 , F_92 ( V_254 ) ) ;
V_254 = NULL ;
}
V_197 = F_123 ( & V_260 ) ;
if ( V_197 )
goto V_261;
return 0 ;
V_261:
F_115 ( V_254 ) ;
return V_197 ;
}
static void T_10 F_124 ( void )
{
F_125 ( & V_260 ) ;
F_115 ( V_254 ) ;
}
