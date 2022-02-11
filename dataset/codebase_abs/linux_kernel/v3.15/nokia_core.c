static void F_1 ( struct V_1 * V_2 , int * clock , int V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
if ( V_3 && ! * clock ) {
F_3 ( L_1 , clock ) ;
F_4 ( V_2 -> V_6 ) ;
F_4 ( V_2 -> V_7 ) ;
if ( F_5 ( & V_2 -> V_8 ) == 0 )
F_6 ( V_2 ) ;
F_7 ( & V_2 -> V_8 ) ;
}
if ( ! V_3 && * clock ) {
F_3 ( L_2 , clock ) ;
if ( F_8 ( & V_2 -> V_8 ) )
F_9 ( V_2 ) ;
F_10 ( V_2 -> V_6 ) ;
F_10 ( V_2 -> V_7 ) ;
}
* clock = V_3 ;
F_11 ( & V_2 -> V_5 , V_4 ) ;
}
static void F_12 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
if ( ! V_2 -> V_11 )
F_1 ( V_2 , & V_2 -> V_12 , 0 ) ;
F_11 ( & V_2 -> V_10 , V_4 ) ;
}
void F_13 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_13 ;
V_13 = F_14 ( V_2 , V_14 ) ;
V_13 &= ~ ( V_15 ) ;
if ( V_3 )
V_13 |= V_16 ;
else
V_13 |= V_17 ;
F_15 ( V_2 , V_14 , V_13 ) ;
}
static inline void F_16 ( struct V_1 * V_2 )
{
}
static void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 )
return;
F_13 ( V_2 , 1 ) ;
F_18 ( V_2 -> V_19 , 0 ) ;
F_19 ( & V_2 -> V_20 , V_21 + F_20 ( 100 ) ) ;
V_2 -> V_11 = 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
if ( ! V_2 -> V_18 )
return;
F_16 ( V_2 ) ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_22 ( & V_2 -> V_20 ) ;
F_1 ( V_2 , & V_2 -> V_12 , 1 ) ;
V_2 -> V_11 = 1 ;
F_18 ( V_2 -> V_19 , 1 ) ;
F_15 ( V_2 , V_22 , F_14 ( V_2 , V_22 ) |
V_23 ) ;
F_13 ( V_2 , 0 ) ;
F_11 ( & V_2 -> V_10 , V_4 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 )
return;
V_2 -> V_24 = 0 ;
if ( F_14 ( V_2 , V_25 ) & V_26 )
return;
if ( ! ( F_14 ( V_2 , V_25 ) & V_27 ) )
return;
F_24 ( V_2 , 0 , V_28 ) ;
V_2 -> V_29 = 0 ;
F_1 ( V_2 , & V_2 -> V_30 , 0 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_18 )
return;
F_16 ( V_2 ) ;
F_1 ( V_2 , & V_2 -> V_30 , 1 ) ;
V_2 -> V_24 = 1 ;
if ( ! ( F_14 ( V_2 , V_25 ) & V_27 ) )
return;
F_24 ( V_2 , 1 , V_28 ) ;
V_2 -> V_29 = 1 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned long V_4 ;
int V_37 ;
F_3 ( L_3 ) ;
V_37 = V_38 + sizeof( * V_32 ) + sizeof( * V_34 ) ;
V_36 = F_27 ( V_37 , V_39 ) ;
if ( ! V_36 )
return - V_40 ;
memset ( V_36 -> V_9 , 0x00 , V_37 ) ;
* F_28 ( V_36 , 1 ) = V_41 ;
V_32 = (struct V_31 * ) F_28 ( V_36 , sizeof( * V_32 ) ) ;
V_32 -> V_42 = sizeof( * V_34 ) ;
V_34 = (struct V_33 * ) F_28 ( V_36 , sizeof( * V_34 ) ) ;
V_34 -> V_43 = V_44 ;
F_29 ( & V_2 -> V_45 , V_36 ) ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_15 ( V_2 , V_22 , F_14 ( V_2 , V_22 ) |
V_23 ) ;
F_11 ( & V_2 -> V_10 , V_4 ) ;
F_3 ( L_4 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 ;
F_3 ( L_5 ) ;
V_32 = (struct V_31 * ) V_36 -> V_9 ;
if ( V_32 -> V_42 != sizeof( * V_34 ) ) {
F_31 ( V_2 -> V_46 , L_6 ) ;
V_2 -> V_47 = - V_48 ;
goto V_49;
}
V_34 = (struct V_33 * ) F_32 ( V_36 , sizeof( * V_32 ) ) ;
if ( V_34 -> V_43 != V_50 ) {
F_31 ( V_2 -> V_46 , L_7 ) ;
V_2 -> V_47 = - V_51 ;
}
V_49:
F_33 ( & V_2 -> V_52 ) ;
F_34 ( V_36 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_35 * V_36 ;
unsigned long V_4 ;
int V_57 , V_37 ;
T_2 V_58 ;
F_3 ( L_8 ) ;
switch ( V_2 -> V_59 ) {
case 1 :
V_58 = 12000 ;
break;
case 2 :
V_58 = 38400 ;
break;
default:
return - V_51 ;
}
V_37 = sizeof( * V_54 ) + sizeof( * V_56 ) + V_38 ;
V_36 = F_27 ( V_37 , V_39 ) ;
if ( ! V_36 )
return - V_40 ;
memset ( V_36 -> V_9 , 0x00 , V_37 ) ;
* F_28 ( V_36 , 1 ) = V_60 ;
V_56 = (struct V_55 * ) F_28 ( V_36 , sizeof( * V_56 ) ) ;
V_54 = (struct V_53 * ) F_28 ( V_36 , sizeof( * V_54 ) ) ;
V_56 -> V_42 = sizeof( * V_54 ) ;
V_54 -> V_61 = V_62 ;
V_54 -> V_63 = F_36 ( V_64 / V_65 ) ;
V_54 -> V_66 = V_67 ;
V_54 -> V_68 = F_36 ( V_58 ) ;
F_37 ( V_2 , V_69 ) ;
F_38 ( V_2 , 1 ) ;
V_2 -> V_47 = 0 ;
V_52 ( & V_2 -> V_52 ) ;
F_29 ( & V_2 -> V_45 , V_36 ) ;
F_2 ( & V_2 -> V_10 , V_4 ) ;
F_15 ( V_2 , V_22 , F_14 ( V_2 , V_22 ) |
V_23 ) ;
F_11 ( & V_2 -> V_10 , V_4 ) ;
if ( ! F_39 ( & V_2 -> V_52 ,
F_20 ( 1000 ) ) )
return - V_70 ;
if ( V_2 -> V_47 < 0 )
return V_2 -> V_47 ;
F_40 ( V_2 , 0 , V_28 ) ;
F_38 ( V_2 , 0 ) ;
F_37 ( V_2 , V_65 ) ;
V_57 = F_41 ( V_2 , 1 , 100 ) ;
if ( V_57 < 0 )
return V_57 ;
F_40 ( V_2 , 1 , V_28 ) ;
V_52 ( & V_2 -> V_52 ) ;
V_57 = F_26 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! F_39 ( & V_2 -> V_52 ,
F_20 ( 1000 ) ) )
return - V_70 ;
if ( V_2 -> V_47 < 0 )
return V_2 -> V_47 ;
F_3 ( L_9 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_55 * V_32 ;
struct V_71 * V_72 ;
V_32 = (struct V_55 * ) V_36 -> V_9 ;
if ( V_32 -> V_42 != sizeof( * V_72 ) ) {
V_2 -> V_47 = - V_48 ;
goto V_73;
}
V_72 = (struct V_71 * ) F_32 ( V_36 , sizeof( * V_32 ) ) ;
if ( V_72 -> V_61 != V_74 ) {
F_31 ( V_2 -> V_46 , L_7 ) ;
V_2 -> V_47 = - V_51 ;
}
V_2 -> V_75 = V_72 -> V_75 ;
V_2 -> V_76 = V_72 -> V_76 ;
V_73:
F_33 ( & V_2 -> V_52 ) ;
F_34 ( V_36 ) ;
}
static int F_43 ( struct V_1 * V_2 , T_1 V_77 )
{
long V_78 ;
switch ( V_77 ) {
case V_79 :
V_78 = V_80 ;
break;
case V_81 :
V_78 = V_82 ;
break;
case V_83 :
V_78 = V_84 ;
break;
case V_60 :
V_78 = V_85 ;
break;
case V_41 :
V_78 = V_86 ;
break;
case V_87 :
V_78 = V_88 ;
break;
default:
F_31 ( V_2 -> V_46 , L_10 , V_77 ) ;
V_78 = - 1 ;
break;
}
return V_78 ;
}
static unsigned int F_44 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
long V_78 = - 1 ;
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_55 * V_56 ;
struct V_31 * V_95 ;
struct V_96 * V_97 ;
switch ( F_45 ( V_36 ) -> V_77 ) {
case V_79 :
V_94 = (struct V_93 * ) V_36 -> V_9 ;
V_78 = V_94 -> V_98 ;
break;
case V_81 :
V_90 = (struct V_89 * ) V_36 -> V_9 ;
V_78 = F_46 ( V_90 -> V_42 ) ;
break;
case V_83 :
V_92 = (struct V_91 * ) V_36 -> V_9 ;
V_78 = V_92 -> V_42 ;
break;
case V_87 :
V_97 = (struct V_96 * ) V_36 -> V_9 ;
V_78 = V_97 -> V_42 ;
break;
case V_60 :
V_56 = (struct V_55 * ) V_36 -> V_9 ;
V_78 = V_56 -> V_42 ;
break;
case V_41 :
V_95 = (struct V_31 * ) V_36 -> V_9 ;
V_78 = V_95 -> V_42 ;
break;
}
return V_78 ;
}
static inline void F_47 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
if ( F_48 ( ! F_49 ( V_99 , & V_2 -> V_100 -> V_4 ) ) ) {
switch ( F_45 ( V_36 ) -> V_77 ) {
case V_60 :
F_42 ( V_2 , V_36 ) ;
V_2 -> V_101 = V_102 ;
return;
case V_41 :
F_30 ( V_2 , V_36 ) ;
V_2 -> V_101 = V_102 ;
return;
}
if ( ! F_49 ( V_103 , & V_2 -> V_100 -> V_4 ) ) {
F_3 ( L_11 ) ;
F_50 ( V_2 , V_36 ) ;
return;
}
}
F_51 ( V_2 -> V_100 , V_36 ) ;
F_3 ( L_12 ) ;
}
static inline void F_52 ( struct V_1 * V_2 , T_1 V_104 )
{
switch ( V_2 -> V_101 ) {
case V_102 :
F_45 ( V_2 -> V_105 ) -> V_77 = V_104 ;
V_2 -> V_106 = F_43 ( V_2 , V_104 ) ;
if ( V_2 -> V_106 < 0 ) {
V_2 -> V_100 -> V_107 . V_108 ++ ;
F_34 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
} else {
V_2 -> V_101 = V_109 ;
}
break;
case V_109 :
V_2 -> V_106 -- ;
* F_28 ( V_2 -> V_105 , 1 ) = V_104 ;
if ( V_2 -> V_106 != 0 )
break;
V_2 -> V_106 = F_44 ( V_2 , V_2 -> V_105 ) ;
if ( V_2 -> V_106 > F_53 ( V_2 -> V_105 ) ) {
F_31 ( V_2 -> V_46 , L_13 ) ;
V_2 -> V_110 = V_2 -> V_106
- F_53 ( V_2 -> V_105 ) ;
F_34 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
break;
}
V_2 -> V_101 = V_111 ;
break;
case V_111 :
V_2 -> V_106 -- ;
* F_28 ( V_2 -> V_105 , 1 ) = V_104 ;
break;
default:
F_54 ( 1 ) ;
break;
}
if ( V_2 -> V_106 == 0 ) {
if ( ! ( V_2 -> V_105 -> V_37 % 2 ) )
V_2 -> V_110 ++ ;
F_47 ( V_2 , V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
}
}
static void F_55 ( unsigned long V_9 )
{
T_1 V_104 ;
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_3 ( L_14 ) ;
F_3 ( L_15 ) ;
while ( F_14 ( V_2 , V_25 ) & V_26 ) {
V_104 = F_14 ( V_2 , V_112 ) ;
if ( V_2 -> V_110 ) {
V_2 -> V_110 -- ;
continue;
}
if ( V_2 -> V_105 == NULL ) {
V_2 -> V_105 = F_27 ( V_113 ,
V_114 | V_115 ) ;
if ( ! V_2 -> V_105 ) {
F_31 ( V_2 -> V_46 ,
L_16 ) ;
goto V_116;
}
V_2 -> V_101 = V_102 ;
V_2 -> V_105 -> V_46 = ( void * ) V_2 -> V_100 ;
}
V_2 -> V_100 -> V_107 . V_117 ++ ;
F_52 ( V_2 , V_104 ) ;
}
if ( ! V_2 -> V_24 ) {
if ( F_14 ( V_2 , V_25 ) & V_27 &&
V_2 -> V_29 ) {
F_24 ( V_2 , 0 , V_28 ) ;
V_2 -> V_29 = 0 ;
}
F_14 ( V_2 , V_118 ) ;
F_1 ( V_2 , & V_2 -> V_30 , 0 ) ;
}
V_116:
F_3 ( L_17 ) ;
}
static void F_56 ( unsigned long V_9 )
{
unsigned int V_119 = 0 ;
struct V_35 * V_36 ;
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_3 ( L_14 ) ;
F_3 ( L_18 ) ;
if ( V_2 -> V_29 != V_2 -> V_24 ) {
if ( F_14 ( V_2 , V_25 ) & V_27 ) {
if ( V_2 -> V_29 && ! V_2 -> V_24 ) {
F_24 ( V_2 , 0 ,
V_28 ) ;
V_2 -> V_29 = 0 ;
}
if ( ! V_2 -> V_29 && V_2 -> V_24 ) {
F_24 ( V_2 , 1 ,
V_28 ) ;
V_2 -> V_29 = 1 ;
}
} else {
F_15 ( V_2 , V_118 ,
F_14 ( V_2 , V_118 ) |
V_120 ) ;
goto V_121;
}
}
V_36 = F_57 ( & V_2 -> V_45 ) ;
if ( ! V_36 ) {
F_3 ( L_19 ) ;
if ( F_14 ( V_2 , V_25 ) & V_27 ) {
F_15 ( V_2 , V_22 ,
F_14 ( V_2 , V_22 ) &
~ V_23 ) ;
F_14 ( V_2 , V_118 ) ;
F_17 ( V_2 ) ;
return;
}
F_15 ( V_2 , V_118 ,
F_14 ( V_2 , V_118 ) |
V_120 ) ;
goto V_121;
}
while ( ! ( F_14 ( V_2 , V_122 ) & V_123 ) &&
( V_119 < V_36 -> V_37 ) ) {
F_15 ( V_2 , V_124 , V_36 -> V_9 [ V_119 ] ) ;
V_119 ++ ;
}
V_2 -> V_100 -> V_107 . V_125 += V_119 ;
if ( V_36 -> V_37 == V_119 ) {
F_34 ( V_36 ) ;
} else {
F_32 ( V_36 , V_119 ) ;
F_58 ( & V_2 -> V_45 , V_36 ) ;
}
F_15 ( V_2 , V_118 , F_14 ( V_2 , V_118 ) &
~ V_120 ) ;
F_15 ( V_2 , V_22 , F_14 ( V_2 , V_22 ) |
V_23 ) ;
V_121:
F_14 ( V_2 , V_118 ) ;
}
static T_3 F_59 ( int V_126 , void * V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
T_1 V_127 , V_128 ;
int V_129 ;
V_129 = V_130 ;
V_127 = F_14 ( V_2 , V_131 ) ;
if ( V_127 & V_132 )
return V_133 ;
F_3 ( L_20 , V_127 ) ;
V_127 &= V_134 ;
if ( V_127 == V_135 ) {
V_128 = F_14 ( V_2 , V_136 ) ;
V_129 = V_133 ;
}
if ( V_127 == V_137 ) {
F_14 ( V_2 , V_112 ) ;
F_14 ( V_2 , V_25 ) ;
V_129 = V_133 ;
}
if ( V_127 == V_138 ) {
F_55 ( ( unsigned long ) V_9 ) ;
V_129 = V_133 ;
}
if ( V_127 == V_139 ) {
F_56 ( ( unsigned long ) V_9 ) ;
V_129 = V_133 ;
}
return V_129 ;
}
static T_3 F_60 ( int V_126 , void * V_140 )
{
struct V_1 * V_2 = V_140 ;
int V_141 ;
struct V_142 * V_100 ;
if ( ! V_2 -> V_100 )
return V_133 ;
V_141 = F_61 ( V_2 -> V_143 ) ;
V_100 = V_2 -> V_100 ;
if ( ! F_49 ( V_99 , & V_100 -> V_4 ) ) {
if ( V_141 == 1 )
F_62 ( & V_2 -> V_144 ) ;
return V_133 ;
}
F_3 ( L_21 , V_141 ) ;
if ( V_2 -> V_24 == V_141 )
return V_133 ;
if ( V_141 )
F_25 ( V_2 ) ;
else
F_23 ( V_2 ) ;
return V_133 ;
}
static inline void F_63 ( struct V_1 * V_2 , bool V_145 )
{
struct V_146 * V_147 = V_2 -> V_46 -> V_148 ;
const char * V_149 = V_145 ? L_22 : L_23 ;
if ( F_48 ( ! V_147 || ! V_147 -> V_150 ) )
return;
if ( V_145 != ! ! F_49 ( V_151 , & V_2 -> V_152 ) ) {
V_147 -> V_150 ( V_2 -> V_46 , V_145 ) ;
if ( V_145 )
F_64 ( V_151 , & V_2 -> V_152 ) ;
else
F_65 ( V_151 , & V_2 -> V_152 ) ;
F_3 ( L_24 , V_149 ) ;
return;
}
F_3 ( L_25 , V_149 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_57 ;
V_57 = F_67 ( V_2 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_26 ) ;
return V_57 ;
}
F_68 ( V_2 ) ;
F_38 ( V_2 , 0 ) ;
F_18 ( V_2 -> V_153 , 0 ) ;
F_18 ( V_2 -> V_19 , 1 ) ;
F_69 ( 10 ) ;
if ( F_61 ( V_2 -> V_143 ) == 1 ) {
F_31 ( V_2 -> V_46 , L_27 ) ;
return - V_154 ;
}
V_52 ( & V_2 -> V_144 ) ;
F_18 ( V_2 -> V_153 , 1 ) ;
if ( ! F_39 ( & V_2 -> V_144 ,
F_20 ( 100 ) ) ) {
F_31 ( V_2 -> V_46 , L_28 ) ;
F_62 ( & V_2 -> V_144 ) ;
return - V_154 ;
}
V_57 = F_41 ( V_2 , 1 , 100 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_29 ) ;
return V_57 ;
}
F_38 ( V_2 , 1 ) ;
return 0 ;
}
static int F_70 ( struct V_142 * V_100 )
{
struct V_1 * V_2 = F_71 ( V_100 ) ;
F_72 ( & V_2 -> V_45 ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_57 ;
int V_129 = - V_155 ;
if ( ! V_2 )
return - V_51 ;
F_74 ( F_75 ( V_2 -> V_143 ) ) ;
F_18 ( V_2 -> V_19 , 0 ) ;
V_57 = F_41 ( V_2 , 0 , 100 ) ;
if ( V_57 ) {
F_76 ( V_2 -> V_46 ,
L_30 ,
V_57 ) ;
goto V_156;
}
F_18 ( V_2 -> V_19 , 1 ) ;
V_57 = F_41 ( V_2 , 1 , 100 ) ;
if ( V_57 ) {
F_76 ( V_2 -> V_46 ,
L_31 ,
V_57 ) ;
goto V_156;
}
F_18 ( V_2 -> V_19 , 0 ) ;
V_57 = F_41 ( V_2 , 0 , 100 ) ;
if ( V_57 ) {
F_76 ( V_2 -> V_46 ,
L_32 ,
V_57 ) ;
goto V_156;
}
V_129 = 0 ;
V_156:
F_77 ( F_75 ( V_2 -> V_143 ) ) ;
return V_129 ;
}
static int F_78 ( struct V_142 * V_100 )
{
struct V_1 * V_2 ;
int V_57 , V_157 = 0 ;
struct V_158 V_159 ;
unsigned long V_4 ;
V_2 = F_71 ( V_100 ) ;
if ( F_49 ( V_99 , & V_100 -> V_4 ) )
return 0 ;
V_160:
V_2 -> V_24 = 1 ;
V_2 -> V_101 = V_102 ;
V_2 -> V_106 = 0 ;
V_2 -> V_110 = 0 ;
V_2 -> V_105 = NULL ;
V_2 -> V_18 = 0 ;
V_52 ( & V_2 -> V_161 ) ;
F_1 ( V_2 , & V_2 -> V_12 , 1 ) ;
F_1 ( V_2 , & V_2 -> V_30 , 1 ) ;
F_79 ( & V_159 ) ;
V_57 = F_66 ( V_2 ) ;
if ( V_57 < 0 )
goto V_162;
F_40 ( V_2 , 1 , V_163 | V_28 ) ;
V_2 -> V_29 = 1 ;
V_57 = F_35 ( V_2 ) ;
V_57 = F_80 ( V_2 , & V_159 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_33 ) ;
goto V_162;
}
V_57 = F_81 ( V_2 , & V_159 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_34 ) ;
goto V_162;
}
V_2 -> V_18 = 1 ;
V_57 = F_73 ( V_2 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_35 ) ;
goto V_162;
}
F_2 ( & V_2 -> V_10 , V_4 ) ;
V_2 -> V_24 = F_61 ( V_2 -> V_143 ) ;
F_1 ( V_2 , & V_2 -> V_30 , V_2 -> V_24 ) ;
F_11 ( & V_2 -> V_10 , V_4 ) ;
F_1 ( V_2 , & V_2 -> V_12 , 0 ) ;
F_34 ( V_2 -> V_164 ) ;
V_2 -> V_164 = NULL ;
F_64 ( V_99 , & V_100 -> V_4 ) ;
F_3 ( L_36 ) ;
return 0 ;
V_162:
F_70 ( V_100 ) ;
F_67 ( V_2 ) ;
F_82 ( & V_2 -> V_20 ) ;
F_1 ( V_2 , & V_2 -> V_12 , 0 ) ;
F_1 ( V_2 , & V_2 -> V_30 , 0 ) ;
F_18 ( V_2 -> V_153 , 0 ) ;
F_18 ( V_2 -> V_19 , 0 ) ;
F_72 ( & V_159 ) ;
F_34 ( V_2 -> V_164 ) ;
V_2 -> V_164 = NULL ;
F_34 ( V_2 -> V_105 ) ;
V_2 -> V_105 = NULL ;
if ( V_157 ++ < 3 ) {
F_31 ( V_2 -> V_46 , L_37 , V_157 ) ;
goto V_160;
}
return V_57 ;
}
static int F_83 ( struct V_142 * V_100 )
{
struct V_1 * V_2 = F_71 ( V_100 ) ;
if ( ! F_84 ( V_99 , & V_100 -> V_4 ) )
return 0 ;
F_70 ( V_100 ) ;
F_1 ( V_2 , & V_2 -> V_12 , 1 ) ;
F_1 ( V_2 , & V_2 -> V_30 , 1 ) ;
F_67 ( V_2 ) ;
F_82 ( & V_2 -> V_20 ) ;
F_1 ( V_2 , & V_2 -> V_12 , 0 ) ;
F_1 ( V_2 , & V_2 -> V_30 , 0 ) ;
F_18 ( V_2 -> V_153 , 0 ) ;
F_18 ( V_2 -> V_19 , 0 ) ;
F_34 ( V_2 -> V_105 ) ;
return 0 ;
}
static int F_85 ( struct V_142 * V_100 , struct V_35 * V_36 )
{
struct V_1 * V_2 ;
int V_57 = 0 ;
F_3 ( L_38 , V_100 , V_36 ) ;
V_2 = F_71 ( V_100 ) ;
if ( ! F_49 ( V_99 , & V_100 -> V_4 ) ) {
F_76 ( V_2 -> V_46 , L_39 ) ;
return - V_48 ;
}
switch ( F_45 ( V_36 ) -> V_77 ) {
case V_165 :
V_100 -> V_107 . V_166 ++ ;
break;
case V_167 :
V_100 -> V_107 . V_168 ++ ;
break;
case V_169 :
V_100 -> V_107 . V_170 ++ ;
break;
}
* F_86 ( V_36 , 1 ) = ( F_45 ( V_36 ) -> V_77 ) ;
if ( V_36 -> V_37 % 2 ) {
V_57 = F_87 ( V_36 , 1 ) ;
if ( ! V_57 )
* F_28 ( V_36 , 1 ) = 0x00 ;
}
if ( V_57 )
return V_57 ;
F_29 ( & V_2 -> V_45 , V_36 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static T_4 F_88 ( struct V_171 * V_46 ,
struct V_172 * V_173 ,
const char * V_174 , T_5 V_175 )
{
struct V_1 * V_2 = F_89 ( V_46 ) ;
unsigned int V_176 [ 6 ] ;
int V_129 , V_177 ;
V_129 = sscanf ( V_174 , L_40 ,
& V_176 [ 0 ] , & V_176 [ 1 ] , & V_176 [ 2 ] ,
& V_176 [ 3 ] , & V_176 [ 4 ] , & V_176 [ 5 ] ) ;
if ( V_129 != 6 )
return - V_51 ;
for ( V_177 = 0 ; V_177 < 6 ; V_177 ++ ) {
if ( V_176 [ V_177 ] > 0xff )
return - V_51 ;
V_2 -> V_178 [ V_177 ] = V_176 [ V_177 ] & 0xff ;
}
return V_175 ;
}
static T_4 F_90 ( struct V_171 * V_46 ,
struct V_172 * V_173 , char * V_174 )
{
struct V_1 * V_2 = F_89 ( V_46 ) ;
return sprintf ( V_174 , L_41 , V_2 -> V_178 ) ;
}
static int F_91 ( struct V_171 * V_46 )
{
return F_92 ( V_46 , & V_179 ) ;
}
static void F_93 ( struct V_171 * V_46 )
{
F_94 ( V_46 , & V_179 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_142 * V_100 ;
V_100 = F_96 () ;
if ( ! V_100 ) {
F_31 ( V_2 -> V_46 , L_42 ) ;
return - V_40 ;
}
V_2 -> V_100 = V_100 ;
V_100 -> V_180 = V_181 ;
F_97 ( V_100 , V_2 ) ;
V_100 -> V_182 = F_78 ;
V_100 -> V_183 = F_83 ;
V_100 -> V_184 = F_70 ;
V_100 -> V_185 = F_85 ;
F_64 ( V_186 , & V_100 -> V_187 ) ;
F_98 ( V_100 , V_2 -> V_46 ) ;
if ( F_91 ( V_2 -> V_46 ) < 0 ) {
F_31 ( V_2 -> V_46 , L_43 ) ;
goto free;
}
if ( F_99 ( V_100 ) >= 0 )
return 0 ;
F_31 ( V_2 -> V_46 , L_44 , V_100 -> V_188 ) ;
F_93 ( V_2 -> V_46 ) ;
free:
F_100 ( V_2 -> V_100 ) ;
return - V_189 ;
}
static int F_101 ( struct V_190 * V_191 )
{
struct V_146 * V_147 ;
struct V_1 * V_2 ;
int V_57 ;
F_102 ( & V_191 -> V_46 , L_45 ) ;
V_2 = F_103 ( & V_191 -> V_46 , sizeof( struct V_1 ) ,
V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_2 -> V_46 = & V_191 -> V_46 ;
V_2 -> V_11 = 1 ;
V_2 -> V_24 = 1 ;
F_104 ( & V_2 -> V_10 ) ;
F_104 ( & V_2 -> V_5 ) ;
F_79 ( & V_2 -> V_45 ) ;
if ( V_191 -> V_46 . V_148 == NULL ) {
F_31 ( & V_191 -> V_46 , L_46 ) ;
return - V_192 ;
}
V_147 = V_191 -> V_46 . V_148 ;
V_2 -> V_193 = V_147 -> V_193 ;
V_2 -> V_19 = V_147 -> V_19 ;
V_2 -> V_143 = V_147 -> V_143 ;
V_2 -> V_153 = V_147 -> V_153 ;
V_2 -> V_194 = V_147 -> V_194 ;
V_2 -> V_59 = V_147 -> V_59 ;
F_3 ( L_47 , V_2 -> V_153 ) ;
F_3 ( L_48 , V_2 -> V_19 ) ;
F_3 ( L_49 , V_2 -> V_143 ) ;
F_3 ( L_50 , V_2 -> V_59 ) ;
V_52 ( & V_2 -> V_144 ) ;
F_62 ( & V_2 -> V_144 ) ;
if ( ! V_2 -> V_194 ) {
V_57 = F_105 ( & V_191 -> V_46 , V_2 -> V_153 ,
V_195 , L_51 ) ;
if ( V_57 < 0 ) {
F_31 ( & V_191 -> V_46 , L_52 ,
V_2 -> V_153 ) ;
return V_57 ;
}
}
V_57 = F_105 ( & V_191 -> V_46 , V_2 -> V_19 ,
V_195 , L_53 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_54 ,
V_2 -> V_19 ) ;
return V_57 ;
}
V_57 = F_105 ( & V_191 -> V_46 , V_2 -> V_143 ,
V_196 , L_55 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_56 ,
V_2 -> V_143 ) ;
return V_57 ;
}
V_2 -> V_126 = V_147 -> V_197 ;
V_2 -> V_198 = F_106 ( & V_191 -> V_46 , V_147 -> V_198 ,
V_199 ) ;
V_2 -> V_7 = F_107 ( & V_191 -> V_46 , V_147 -> V_7 ) ;
V_2 -> V_6 = F_107 ( & V_191 -> V_46 , V_147 -> V_6 ) ;
V_57 = F_108 ( & V_191 -> V_46 , V_2 -> V_126 , F_59 ,
V_200 , L_57 , V_2 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_58 ,
V_2 -> V_126 ) ;
return V_57 ;
}
V_57 = F_108 ( & V_191 -> V_46 , F_75 ( V_2 -> V_143 ) ,
F_60 , V_201 |
V_202 | V_200 ,
L_59 , V_2 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_60 ,
F_75 ( V_2 -> V_143 ) ) ;
return V_57 ;
}
V_57 = F_109 ( F_75 ( V_2 -> V_143 ) , 1 ) ;
if ( V_57 < 0 ) {
F_31 ( V_2 -> V_46 , L_61 ,
F_75 ( V_2 -> V_143 ) ) ;
return V_57 ;
}
F_110 ( & V_2 -> V_20 ) ;
V_2 -> V_20 . V_203 = F_12 ;
V_2 -> V_20 . V_9 = ( unsigned long ) V_2 ;
F_1 ( V_2 , & V_2 -> V_12 , 1 ) ;
V_57 = F_67 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
F_18 ( V_2 -> V_153 , 0 ) ;
F_1 ( V_2 , & V_2 -> V_12 , 0 ) ;
F_111 ( V_191 , V_2 ) ;
if ( F_95 ( V_2 ) < 0 ) {
F_31 ( V_2 -> V_46 , L_62 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_112 ( struct V_190 * V_191 )
{
struct V_1 * V_2 ;
V_2 = F_113 ( V_191 ) ;
F_93 ( V_2 -> V_46 ) ;
F_83 ( V_2 -> V_100 ) ;
F_114 ( V_2 -> V_100 ) ;
F_100 ( V_2 -> V_100 ) ;
return 0 ;
}
