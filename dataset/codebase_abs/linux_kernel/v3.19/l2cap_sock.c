bool F_1 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_3 == & V_4 ;
}
static int F_2 ( T_1 V_5 )
{
if ( ( V_5 & 0x0101 ) != 0x0001 )
return - V_6 ;
if ( V_5 < 0x1001 && ! F_3 ( V_7 ) )
return - V_8 ;
return 0 ;
}
static int F_4 ( T_1 V_5 )
{
if ( V_5 > 0x00ff )
return - V_6 ;
if ( V_5 <= 0x007f && ! F_3 ( V_7 ) )
return - V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_9 * V_10 , int V_11 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_15 V_16 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( ! V_10 || V_10 -> V_19 != V_20 )
return - V_6 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_17 = F_8 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_16 , V_10 , V_17 ) ;
if ( V_16 . V_21 && V_16 . V_22 )
return - V_6 ;
if ( ! F_9 ( V_16 . V_23 ) )
return - V_6 ;
if ( F_10 ( V_16 . V_23 ) ) {
if ( V_16 . V_21 &&
V_16 . V_21 != F_11 ( V_24 ) )
return - V_6 ;
}
F_12 ( V_12 ) ;
if ( V_12 -> V_25 != V_26 ) {
V_18 = - V_27 ;
goto V_28;
}
if ( V_16 . V_22 ) {
T_2 V_5 = F_13 ( V_16 . V_22 ) ;
if ( V_16 . V_23 == V_29 )
V_18 = F_2 ( V_5 ) ;
else
V_18 = F_4 ( V_5 ) ;
if ( V_18 )
goto V_28;
}
if ( V_16 . V_21 )
V_18 = F_14 ( V_14 , F_13 ( V_16 . V_21 ) ) ;
else
V_18 = F_15 ( V_14 , & V_16 . V_30 , V_16 . V_22 ) ;
if ( V_18 < 0 )
goto V_28;
switch ( V_14 -> V_31 ) {
case V_32 :
if ( F_13 ( V_16 . V_22 ) == V_33 )
V_14 -> V_34 = V_35 ;
break;
case V_36 :
if ( F_13 ( V_16 . V_22 ) == V_37 ||
F_13 ( V_16 . V_22 ) == V_38 )
V_14 -> V_34 = V_35 ;
break;
case V_39 :
V_14 -> V_34 = V_35 ;
break;
case V_40 :
F_16 ( V_41 , & V_14 -> V_42 ) ;
break;
}
F_17 ( & V_14 -> V_43 , & V_16 . V_30 ) ;
V_14 -> V_44 = V_16 . V_23 ;
if ( V_14 -> V_5 && F_10 ( V_14 -> V_44 ) )
V_14 -> V_45 = V_46 ;
V_14 -> V_47 = V_48 ;
V_12 -> V_25 = V_48 ;
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_11 , int V_42 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_15 V_16 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( ! V_10 || V_11 < sizeof( V_10 -> V_19 ) ||
V_10 -> V_19 != V_20 )
return - V_6 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_17 = F_8 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_16 , V_10 , V_17 ) ;
if ( V_16 . V_21 && V_16 . V_22 )
return - V_6 ;
if ( ! F_9 ( V_16 . V_23 ) )
return - V_6 ;
if ( V_14 -> V_44 == V_29 && F_20 ( & V_14 -> V_43 , V_49 ) &&
F_10 ( V_16 . V_23 ) ) {
if ( V_14 -> V_50 != V_24 ||
V_16 . V_21 != F_11 ( V_24 ) )
return - V_6 ;
V_14 -> V_44 = V_51 ;
}
if ( V_14 -> V_44 != V_29 && V_16 . V_23 == V_29 )
return - V_6 ;
if ( F_10 ( V_16 . V_23 ) ) {
if ( V_16 . V_21 &&
V_16 . V_21 != F_11 ( V_24 ) )
return - V_6 ;
}
if ( V_14 -> V_5 && F_10 ( V_14 -> V_44 ) )
V_14 -> V_45 = V_46 ;
V_18 = F_21 ( V_14 , V_16 . V_22 , F_13 ( V_16 . V_21 ) ,
& V_16 . V_30 , V_16 . V_23 ) ;
if ( V_18 )
return V_18 ;
F_12 ( V_12 ) ;
V_18 = F_22 ( V_12 , V_52 ,
F_23 ( V_12 , V_42 & V_53 ) ) ;
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_24 ( struct V_1 * V_2 , int V_54 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 = 0 ;
F_7 ( L_2 , V_12 , V_54 ) ;
F_12 ( V_12 ) ;
if ( V_12 -> V_25 != V_48 ) {
V_18 = - V_27 ;
goto V_28;
}
if ( V_12 -> V_55 != V_56 && V_12 -> V_55 != V_57 ) {
V_18 = - V_6 ;
goto V_28;
}
switch ( V_14 -> V_45 ) {
case V_58 :
case V_46 :
break;
case V_59 :
case V_60 :
if ( ! V_61 )
break;
default:
V_18 = - V_62 ;
goto V_28;
}
V_12 -> V_63 = V_54 ;
V_12 -> V_64 = 0 ;
F_25 ( & V_14 -> V_65 , V_66 ) ;
V_14 -> V_47 = V_67 ;
V_12 -> V_25 = V_67 ;
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_1 * V_68 ,
int V_42 )
{
F_27 ( V_69 , V_70 ) ;
struct V_2 * V_12 = V_2 -> V_12 , * V_71 ;
long V_72 ;
int V_18 = 0 ;
F_28 ( V_12 , V_66 ) ;
V_72 = F_29 ( V_12 , V_42 & V_53 ) ;
F_7 ( L_3 , V_12 , V_72 ) ;
F_30 ( F_31 ( V_12 ) , & V_69 ) ;
while ( 1 ) {
F_32 ( V_73 ) ;
if ( V_12 -> V_25 != V_67 ) {
V_18 = - V_27 ;
break;
}
V_71 = F_33 ( V_12 , V_68 ) ;
if ( V_71 )
break;
if ( ! V_72 ) {
V_18 = - V_74 ;
break;
}
if ( F_34 ( V_70 ) ) {
V_18 = F_35 ( V_72 ) ;
break;
}
F_18 ( V_12 ) ;
V_72 = F_36 ( V_72 ) ;
F_28 ( V_12 , V_66 ) ;
}
F_37 ( V_75 ) ;
F_38 ( F_31 ( V_12 ) , & V_69 ) ;
if ( V_18 )
goto V_28;
V_68 -> V_47 = V_76 ;
F_7 ( L_4 , V_71 ) ;
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int * V_17 , int V_77 )
{
struct V_15 * V_16 = (struct V_15 * ) V_10 ;
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( V_77 && V_12 -> V_25 != V_52 &&
V_12 -> V_25 != V_78 && V_12 -> V_25 != V_79 &&
V_12 -> V_25 != V_80 )
return - V_81 ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_10 -> V_19 = V_20 ;
* V_17 = sizeof( struct V_15 ) ;
V_16 -> V_22 = V_14 -> V_5 ;
if ( V_77 ) {
F_17 ( & V_16 -> V_30 , & V_14 -> V_82 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_83 ) ;
V_16 -> V_23 = V_14 -> V_84 ;
} else {
F_17 ( & V_16 -> V_30 , & V_14 -> V_43 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_50 ) ;
V_16 -> V_23 = V_14 -> V_44 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , int V_85 ,
char T_3 * V_86 , int T_3 * V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_88 V_89 ;
struct V_90 V_91 ;
int V_17 , V_18 = 0 ;
T_4 V_92 ;
F_7 ( L_1 , V_12 ) ;
if ( F_41 ( V_17 , V_87 ) )
return - V_93 ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_94 :
if ( F_10 ( V_14 -> V_44 ) &&
V_14 -> V_50 != V_24 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_95 = V_14 -> V_95 ;
V_89 . V_96 = V_14 -> V_96 ;
V_89 . V_97 = V_14 -> V_97 ;
V_89 . V_45 = V_14 -> V_45 ;
V_89 . V_98 = V_14 -> V_98 ;
V_89 . V_99 = V_14 -> V_99 ;
V_89 . V_100 = V_14 -> V_101 ;
V_17 = F_8 (unsigned int, len, sizeof(opts)) ;
if ( F_42 ( V_86 , ( char * ) & V_89 , V_17 ) )
V_18 = - V_93 ;
break;
case V_102 :
switch ( V_14 -> V_34 ) {
case V_103 :
V_92 = V_104 ;
break;
case V_105 :
V_92 = V_104 | V_106 ;
break;
case V_107 :
V_92 = V_104 | V_106 |
V_108 ;
break;
case V_109 :
V_92 = V_104 | V_106 |
V_108 | V_110 ;
break;
default:
V_92 = 0 ;
break;
}
if ( F_43 ( V_111 , & V_14 -> V_42 ) )
V_92 |= V_112 ;
if ( F_43 ( V_113 , & V_14 -> V_42 ) )
V_92 |= V_114 ;
if ( F_44 ( V_92 , ( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_115 :
if ( V_12 -> V_25 != V_52 &&
! ( V_12 -> V_25 == V_79 &&
F_43 ( V_116 , & F_45 ( V_12 ) -> V_42 ) ) ) {
V_18 = - V_81 ;
break;
}
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_117 = V_14 -> V_118 -> V_119 -> V_120 ;
memcpy ( V_91 . V_121 , V_14 -> V_118 -> V_119 -> V_121 , 3 ) ;
V_17 = F_8 (unsigned int, len, sizeof(cinfo)) ;
if ( F_42 ( V_86 , ( char * ) & V_91 , V_17 ) )
V_18 = - V_93 ;
break;
default:
V_18 = - V_122 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_46 ( struct V_1 * V_2 , int V_123 , int V_85 ,
char T_3 * V_86 , int T_3 * V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_124 V_125 ;
struct V_126 V_127 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( V_123 == V_128 )
return F_40 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( V_123 != V_129 )
return - V_122 ;
if ( F_41 ( V_17 , V_87 ) )
return - V_93 ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_130 :
if ( V_14 -> V_31 != V_36 &&
V_14 -> V_31 != V_40 &&
V_14 -> V_31 != V_39 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
if ( V_14 -> V_118 ) {
V_125 . V_123 = V_14 -> V_118 -> V_119 -> V_34 ;
if ( V_12 -> V_25 == V_52 )
V_125 . V_131 = V_14 -> V_118 -> V_119 -> V_132 ;
} else {
V_125 . V_123 = V_14 -> V_34 ;
}
V_17 = F_8 (unsigned int, len, sizeof(sec)) ;
if ( F_42 ( V_86 , ( char * ) & V_125 , V_17 ) )
V_18 = - V_93 ;
break;
case V_133 :
if ( V_12 -> V_25 != V_48 && V_12 -> V_25 != V_67 ) {
V_18 = - V_6 ;
break;
}
if ( F_44 ( F_43 ( V_116 , & F_45 ( V_12 ) -> V_42 ) ,
( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_134 :
if ( F_44 ( F_43 ( V_135 , & V_14 -> V_42 ) ,
( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_136 :
if ( V_12 -> V_55 != V_56 && V_12 -> V_55 != V_57
&& V_12 -> V_55 != V_137 ) {
V_18 = - V_6 ;
break;
}
V_127 . V_138 = F_43 ( V_139 , & V_14 -> V_42 ) ;
V_17 = F_8 (unsigned int, len, sizeof(pwr)) ;
if ( F_42 ( V_86 , ( char * ) & V_127 , V_17 ) )
V_18 = - V_93 ;
break;
case V_140 :
if ( F_44 ( V_14 -> V_141 , ( T_4 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_142 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_25 != V_52 ) {
V_18 = - V_81 ;
break;
}
if ( F_44 ( V_14 -> V_96 , ( T_1 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
case V_143 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( F_44 ( V_14 -> V_95 , ( T_1 T_3 * ) V_86 ) )
V_18 = - V_93 ;
break;
default:
V_18 = - V_122 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static bool F_47 ( struct V_13 * V_14 , T_1 V_144 )
{
switch ( V_14 -> V_50 ) {
case V_24 :
if ( V_144 < V_145 )
return false ;
break;
default:
if ( V_144 < V_146 )
return false ;
}
return true ;
}
static int F_48 ( struct V_1 * V_2 , int V_85 ,
char T_3 * V_86 , unsigned int V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_88 V_89 ;
int V_17 , V_18 = 0 ;
T_4 V_92 ;
F_7 ( L_1 , V_12 ) ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_94 :
if ( F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_25 == V_52 ) {
V_18 = - V_6 ;
break;
}
V_89 . V_95 = V_14 -> V_95 ;
V_89 . V_96 = V_14 -> V_96 ;
V_89 . V_97 = V_14 -> V_97 ;
V_89 . V_45 = V_14 -> V_45 ;
V_89 . V_98 = V_14 -> V_98 ;
V_89 . V_99 = V_14 -> V_99 ;
V_89 . V_100 = V_14 -> V_101 ;
V_17 = F_8 (unsigned int, sizeof(opts), optlen) ;
if ( F_49 ( ( char * ) & V_89 , V_86 , V_17 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_89 . V_100 > V_147 ) {
V_18 = - V_6 ;
break;
}
if ( ! F_47 ( V_14 , V_89 . V_95 ) ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_45 = V_89 . V_45 ;
switch ( V_14 -> V_45 ) {
case V_46 :
break;
case V_58 :
F_50 ( V_148 , & V_14 -> V_149 ) ;
break;
case V_59 :
case V_60 :
if ( ! V_61 )
break;
default:
V_18 = - V_6 ;
break;
}
V_14 -> V_95 = V_89 . V_95 ;
V_14 -> V_96 = V_89 . V_96 ;
V_14 -> V_98 = V_89 . V_98 ;
V_14 -> V_99 = V_89 . V_99 ;
V_14 -> V_101 = V_89 . V_100 ;
V_14 -> V_97 = V_89 . V_97 ;
break;
case V_102 :
if ( F_41 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 & V_110 ) {
V_18 = - V_6 ;
break;
}
if ( V_92 & V_104 )
V_14 -> V_34 = V_103 ;
if ( V_92 & V_106 )
V_14 -> V_34 = V_105 ;
if ( V_92 & V_108 )
V_14 -> V_34 = V_107 ;
if ( V_92 & V_112 )
F_16 ( V_111 , & V_14 -> V_42 ) ;
else
F_50 ( V_111 , & V_14 -> V_42 ) ;
if ( V_92 & V_114 )
F_16 ( V_113 , & V_14 -> V_42 ) ;
else
F_50 ( V_113 , & V_14 -> V_42 ) ;
break;
default:
V_18 = - V_122 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_51 ( struct V_1 * V_2 , int V_123 , int V_85 ,
char T_3 * V_86 , unsigned int V_87 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_124 V_125 ;
struct V_126 V_127 ;
struct V_150 * V_118 ;
int V_17 , V_18 = 0 ;
T_4 V_92 ;
F_7 ( L_1 , V_12 ) ;
if ( V_123 == V_128 )
return F_48 ( V_2 , V_85 , V_86 , V_87 ) ;
if ( V_123 != V_129 )
return - V_122 ;
F_12 ( V_12 ) ;
switch ( V_85 ) {
case V_130 :
if ( V_14 -> V_31 != V_36 &&
V_14 -> V_31 != V_40 &&
V_14 -> V_31 != V_39 ) {
V_18 = - V_6 ;
break;
}
V_125 . V_123 = V_103 ;
V_17 = F_8 (unsigned int, sizeof(sec), optlen) ;
if ( F_49 ( ( char * ) & V_125 , V_86 , V_17 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_125 . V_123 < V_103 ||
V_125 . V_123 > V_107 ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_34 = V_125 . V_123 ;
if ( ! V_14 -> V_118 )
break;
V_118 = V_14 -> V_118 ;
if ( V_14 -> V_50 == V_24 ) {
if ( F_52 ( V_118 -> V_119 , V_125 . V_123 ) )
break;
F_16 ( V_151 , & V_14 -> V_42 ) ;
V_12 -> V_25 = V_80 ;
V_14 -> V_47 = V_80 ;
} else if ( ( V_12 -> V_25 == V_79 &&
F_43 ( V_116 , & F_45 ( V_12 ) -> V_42 ) ) ||
V_12 -> V_25 == V_52 ) {
if ( ! F_53 ( V_14 , true ) )
F_16 ( V_152 , & F_45 ( V_12 ) -> V_42 ) ;
else
V_12 -> V_153 ( V_12 ) ;
} else {
V_18 = - V_6 ;
}
break;
case V_133 :
if ( V_12 -> V_25 != V_48 && V_12 -> V_25 != V_67 ) {
V_18 = - V_6 ;
break;
}
if ( F_41 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 ) {
F_16 ( V_116 , & F_45 ( V_12 ) -> V_42 ) ;
F_16 ( V_154 , & V_14 -> V_42 ) ;
} else {
F_50 ( V_116 , & F_45 ( V_12 ) -> V_42 ) ;
F_50 ( V_154 , & V_14 -> V_42 ) ;
}
break;
case V_134 :
if ( F_41 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 > V_155 ) {
V_18 = - V_6 ;
break;
}
if ( V_92 == V_156 ) {
V_118 = V_14 -> V_118 ;
if ( ! V_118 || ! F_54 ( V_118 -> V_119 -> V_157 ) ) {
V_18 = - V_6 ;
break;
}
}
if ( V_92 )
F_16 ( V_135 , & V_14 -> V_42 ) ;
else
F_50 ( V_135 , & V_14 -> V_42 ) ;
break;
case V_136 :
if ( V_14 -> V_31 != V_36 &&
V_14 -> V_31 != V_39 ) {
V_18 = - V_6 ;
break;
}
V_127 . V_138 = V_158 ;
V_17 = F_8 (unsigned int, sizeof(pwr), optlen) ;
if ( F_49 ( ( char * ) & V_127 , V_86 , V_17 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_127 . V_138 )
F_16 ( V_139 , & V_14 -> V_42 ) ;
else
F_50 ( V_139 , & V_14 -> V_42 ) ;
break;
case V_140 :
if ( F_41 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
if ( V_92 > V_159 ) {
V_18 = - V_6 ;
break;
}
if ( V_14 -> V_45 != V_59 &&
V_14 -> V_45 != V_60 ) {
V_18 = - V_62 ;
break;
}
V_14 -> V_141 = ( V_160 ) V_92 ;
if ( V_12 -> V_25 == V_52 &&
V_14 -> V_161 == V_162 )
F_55 ( V_14 ) ;
break;
case V_142 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
V_18 = - V_163 ;
break;
case V_143 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_25 == V_52 ) {
V_18 = - V_164 ;
break;
}
if ( F_41 ( V_92 , ( T_4 T_3 * ) V_86 ) ) {
V_18 = - V_93 ;
break;
}
V_14 -> V_95 = V_92 ;
break;
default:
V_18 = - V_122 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_56 ( struct V_165 * V_166 , struct V_1 * V_2 ,
struct V_167 * V_168 , T_5 V_17 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
V_18 = F_57 ( V_12 ) ;
if ( V_18 )
return V_18 ;
if ( V_168 -> V_169 & V_170 )
return - V_62 ;
if ( V_12 -> V_25 != V_52 )
return - V_81 ;
F_12 ( V_12 ) ;
V_18 = F_58 ( V_12 , V_168 -> V_169 ) ;
F_18 ( V_12 ) ;
if ( V_18 )
return V_18 ;
F_59 ( V_14 ) ;
V_18 = F_60 ( V_14 , V_168 , V_17 ) ;
F_61 ( V_14 ) ;
return V_18 ;
}
static int F_62 ( struct V_165 * V_166 , struct V_1 * V_2 ,
struct V_167 * V_168 , T_5 V_17 , int V_42 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_171 * V_172 = F_6 ( V_12 ) ;
int V_18 ;
F_12 ( V_12 ) ;
if ( V_12 -> V_25 == V_79 && F_43 ( V_116 ,
& F_45 ( V_12 ) -> V_42 ) ) {
if ( F_10 ( V_172 -> V_14 -> V_44 ) ) {
V_12 -> V_25 = V_52 ;
V_172 -> V_14 -> V_47 = V_52 ;
F_63 ( V_172 -> V_14 ) ;
} else {
V_12 -> V_25 = V_80 ;
V_172 -> V_14 -> V_47 = V_80 ;
F_64 ( V_172 -> V_14 ) ;
}
V_18 = 0 ;
goto V_28;
}
F_18 ( V_12 ) ;
if ( V_2 -> type == V_57 )
V_18 = F_65 ( V_166 , V_2 , V_168 , V_17 , V_42 ) ;
else
V_18 = F_66 ( V_166 , V_2 , V_168 , V_17 , V_42 ) ;
if ( V_172 -> V_14 -> V_45 != V_59 )
return V_18 ;
F_12 ( V_12 ) ;
if ( ! F_43 ( V_173 , & V_172 -> V_14 -> V_174 ) )
goto V_28;
if ( V_172 -> V_175 ) {
if ( ! F_67 ( V_12 , V_172 -> V_175 ) )
V_172 -> V_175 = NULL ;
else
goto V_28;
}
if ( F_68 ( & V_12 -> V_176 ) <= V_12 -> V_177 >> 1 )
F_69 ( V_172 -> V_14 , 0 ) ;
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static void F_70 ( struct V_2 * V_12 )
{
if ( ! F_71 ( V_12 , V_178 ) || V_12 -> V_179 )
return;
F_7 ( L_6 , V_12 , F_72 ( V_12 -> V_25 ) ) ;
F_73 ( F_6 ( V_12 ) -> V_14 ) ;
F_74 ( V_12 , V_180 ) ;
F_75 ( V_12 ) ;
}
static int F_76 ( struct V_2 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_27 ( V_69 , V_70 ) ;
int V_18 = 0 ;
int V_72 = V_181 / 5 ;
F_77 ( F_31 ( V_12 ) , & V_69 ) ;
F_32 ( V_73 ) ;
while ( V_14 -> V_182 > 0 && V_14 -> V_118 ) {
if ( ! V_72 )
V_72 = V_181 / 5 ;
if ( F_34 ( V_70 ) ) {
V_18 = F_35 ( V_72 ) ;
break;
}
F_18 ( V_12 ) ;
V_72 = F_36 ( V_72 ) ;
F_12 ( V_12 ) ;
F_32 ( V_73 ) ;
V_18 = F_57 ( V_12 ) ;
if ( V_18 )
break;
}
F_32 ( V_75 ) ;
F_38 ( F_31 ( V_12 ) , & V_69 ) ;
return V_18 ;
}
static int F_78 ( struct V_1 * V_2 , int V_183 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 ;
struct V_150 * V_118 ;
int V_18 = 0 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
V_14 = F_6 ( V_12 ) -> V_14 ;
V_118 = V_14 -> V_118 ;
F_7 ( L_7 , V_14 , F_72 ( V_14 -> V_47 ) ) ;
if ( V_118 )
F_79 ( & V_118 -> V_184 ) ;
F_59 ( V_14 ) ;
F_12 ( V_12 ) ;
if ( ! V_12 -> V_185 ) {
if ( V_14 -> V_45 == V_59 )
V_18 = F_76 ( V_12 ) ;
V_12 -> V_185 = V_186 ;
F_18 ( V_12 ) ;
F_80 ( V_14 , 0 ) ;
F_12 ( V_12 ) ;
if ( F_71 ( V_12 , V_187 ) && V_12 -> V_188 &&
! ( V_70 -> V_42 & V_189 ) )
V_18 = F_22 ( V_12 , V_190 ,
V_12 -> V_188 ) ;
}
if ( ! V_18 && V_12 -> V_191 )
V_18 = - V_12 -> V_191 ;
F_18 ( V_12 ) ;
F_61 ( V_14 ) ;
if ( V_118 )
F_81 ( & V_118 -> V_184 ) ;
return V_18 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
F_83 ( & V_192 , V_12 ) ;
V_18 = F_78 ( V_2 , 2 ) ;
F_84 ( V_12 ) ;
F_70 ( V_12 ) ;
return V_18 ;
}
static void F_85 ( struct V_2 * V_193 )
{
struct V_2 * V_12 ;
F_7 ( L_8 , V_193 ,
F_72 ( V_193 -> V_25 ) ) ;
while ( ( V_12 = F_33 ( V_193 , NULL ) ) ) {
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_9 , V_14 ,
F_72 ( V_14 -> V_47 ) ) ;
F_59 ( V_14 ) ;
F_86 ( V_14 ) ;
F_80 ( V_14 , V_194 ) ;
F_61 ( V_14 ) ;
F_70 ( V_12 ) ;
}
}
static struct V_13 * F_87 ( struct V_13 * V_14 )
{
struct V_2 * V_12 , * V_193 = V_14 -> V_195 ;
F_12 ( V_193 ) ;
if ( F_88 ( V_193 ) ) {
F_7 ( L_10 , V_193 -> V_64 ) ;
F_18 ( V_193 ) ;
return NULL ;
}
V_12 = F_89 ( F_90 ( V_193 ) , NULL , V_196 ,
V_197 ) ;
if ( ! V_12 ) {
F_18 ( V_193 ) ;
return NULL ;
}
F_91 ( V_12 , V_196 ) ;
F_92 ( V_12 , V_193 ) ;
F_93 ( V_193 , V_12 ) ;
F_18 ( V_193 ) ;
return F_6 ( V_12 ) -> V_14 ;
}
static int F_94 ( struct V_13 * V_14 , struct V_198 * V_199 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
int V_18 ;
F_12 ( V_12 ) ;
if ( F_6 ( V_12 ) -> V_175 ) {
V_18 = - V_200 ;
goto V_28;
}
V_18 = F_67 ( V_12 , V_199 ) ;
if ( V_18 < 0 && V_14 -> V_45 == V_59 ) {
F_6 ( V_12 ) -> V_175 = V_199 ;
F_69 ( V_14 , 1 ) ;
V_18 = 0 ;
}
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static void F_95 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
F_70 ( V_12 ) ;
}
static void F_96 ( struct V_13 * V_14 , int V_18 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
struct V_2 * V_193 ;
F_7 ( L_7 , V_14 , F_72 ( V_14 -> V_47 ) ) ;
F_28 ( V_12 , F_68 ( & V_14 -> V_65 ) ) ;
V_193 = F_45 ( V_12 ) -> V_193 ;
F_74 ( V_12 , V_178 ) ;
switch ( V_14 -> V_47 ) {
case V_26 :
case V_48 :
case V_190 :
break;
case V_67 :
F_85 ( V_12 ) ;
V_12 -> V_25 = V_190 ;
V_14 -> V_47 = V_190 ;
break;
default:
V_12 -> V_25 = V_190 ;
V_14 -> V_47 = V_190 ;
V_12 -> V_191 = V_18 ;
if ( V_193 ) {
F_97 ( V_12 ) ;
V_193 -> V_201 ( V_193 ) ;
} else {
V_12 -> V_153 ( V_12 ) ;
}
break;
}
F_18 ( V_12 ) ;
}
static void F_98 ( struct V_13 * V_14 , int V_47 ,
int V_18 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
V_12 -> V_25 = V_47 ;
if ( V_18 )
V_12 -> V_191 = V_18 ;
}
static struct V_198 * F_99 ( struct V_13 * V_14 ,
unsigned long V_202 ,
unsigned long V_17 , int V_203 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
struct V_198 * V_199 ;
int V_18 ;
F_61 ( V_14 ) ;
V_199 = F_100 ( V_12 , V_202 + V_17 , V_203 , & V_18 ) ;
F_59 ( V_14 ) ;
if ( ! V_199 )
return F_101 ( V_18 ) ;
V_199 -> V_204 = V_12 -> V_205 ;
F_102 ( V_199 ) -> V_14 = V_14 ;
return V_199 ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
struct V_2 * V_193 ;
F_12 ( V_12 ) ;
V_193 = F_45 ( V_12 ) -> V_193 ;
F_7 ( L_11 , V_12 , V_193 ) ;
V_12 -> V_25 = V_52 ;
V_12 -> V_153 ( V_12 ) ;
if ( V_193 )
V_193 -> V_201 ( V_193 ) ;
F_18 ( V_12 ) ;
}
static void F_104 ( struct V_13 * V_14 )
{
struct V_2 * V_193 , * V_12 = V_14 -> V_195 ;
F_12 ( V_12 ) ;
V_193 = F_45 ( V_12 ) -> V_193 ;
if ( V_193 )
V_193 -> V_201 ( V_193 ) ;
F_18 ( V_12 ) ;
}
static void F_105 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
if ( F_106 ( V_151 , & V_14 -> V_42 ) ) {
V_12 -> V_25 = V_52 ;
V_14 -> V_47 = V_52 ;
}
F_50 ( V_152 , & F_45 ( V_12 ) -> V_42 ) ;
V_12 -> V_153 ( V_12 ) ;
}
static void F_107 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
F_12 ( V_12 ) ;
V_12 -> V_185 = V_186 ;
F_18 ( V_12 ) ;
}
static long F_108 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
return V_12 -> V_206 ;
}
static void F_109 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_195 ;
F_16 ( V_152 , & F_45 ( V_12 ) -> V_42 ) ;
V_12 -> V_153 ( V_12 ) ;
}
static void F_110 ( struct V_2 * V_12 )
{
F_7 ( L_1 , V_12 ) ;
if ( F_6 ( V_12 ) -> V_14 )
F_73 ( F_6 ( V_12 ) -> V_14 ) ;
if ( F_6 ( V_12 ) -> V_175 ) {
F_111 ( F_6 ( V_12 ) -> V_175 ) ;
F_6 ( V_12 ) -> V_175 = NULL ;
}
F_112 ( & V_12 -> V_207 ) ;
F_112 ( & V_12 -> V_208 ) ;
}
static void F_113 ( struct V_198 * V_199 , void * V_209 ,
int * V_210 )
{
F_114 ( struct V_15 * , V_16 , V_209 ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_211 = V_20 ;
V_16 -> V_22 = F_102 ( V_199 ) -> V_5 ;
F_17 ( & V_16 -> V_30 , & F_102 ( V_199 ) -> V_212 ) ;
* V_210 = sizeof( struct V_15 ) ;
}
static void F_92 ( struct V_2 * V_12 , struct V_2 * V_193 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_1 , V_12 ) ;
if ( V_193 ) {
struct V_13 * V_213 = F_6 ( V_193 ) -> V_14 ;
V_12 -> V_55 = V_193 -> V_55 ;
F_45 ( V_12 ) -> V_42 = F_45 ( V_193 ) -> V_42 ;
V_14 -> V_31 = V_213 -> V_31 ;
V_14 -> V_95 = V_213 -> V_95 ;
V_14 -> V_96 = V_213 -> V_96 ;
V_14 -> V_149 = V_213 -> V_149 ;
V_14 -> V_45 = V_213 -> V_45 ;
V_14 -> V_98 = V_213 -> V_98 ;
V_14 -> V_99 = V_213 -> V_99 ;
V_14 -> V_101 = V_213 -> V_101 ;
V_14 -> V_214 = V_213 -> V_214 ;
V_14 -> V_34 = V_213 -> V_34 ;
V_14 -> V_42 = V_213 -> V_42 ;
V_14 -> V_215 = V_213 -> V_215 ;
V_14 -> V_216 = V_213 -> V_216 ;
if ( V_14 -> V_31 == V_40 ) {
V_14 -> V_50 = V_213 -> V_50 ;
V_14 -> V_83 = V_213 -> V_50 ;
}
F_115 ( V_193 , V_12 ) ;
} else {
switch ( V_12 -> V_55 ) {
case V_137 :
V_14 -> V_31 = V_39 ;
break;
case V_217 :
V_14 -> V_31 = V_32 ;
F_45 ( V_12 ) -> V_218 = F_113 ;
break;
case V_56 :
case V_57 :
V_14 -> V_31 = V_36 ;
break;
}
V_14 -> V_95 = V_219 ;
V_14 -> V_96 = 0 ;
if ( ! V_61 && V_12 -> V_55 == V_57 ) {
V_14 -> V_45 = V_59 ;
F_16 ( V_148 , & V_14 -> V_149 ) ;
} else {
V_14 -> V_45 = V_58 ;
}
F_116 ( V_14 ) ;
}
V_14 -> V_97 = V_220 ;
V_14 -> V_195 = V_12 ;
V_14 -> V_3 = & V_221 ;
}
static struct V_2 * F_89 ( struct V_222 * V_222 , struct V_1 * V_2 ,
int V_223 , T_6 V_224 )
{
struct V_2 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_117 ( V_222 , V_225 , V_224 , & V_226 ) ;
if ( ! V_12 )
return NULL ;
F_118 ( V_2 , V_12 ) ;
F_119 ( & F_45 ( V_12 ) -> V_227 ) ;
V_12 -> V_228 = F_110 ;
V_12 -> V_206 = V_229 ;
F_120 ( V_12 , V_178 ) ;
V_12 -> V_230 = V_223 ;
V_12 -> V_25 = V_26 ;
V_14 = F_121 () ;
if ( ! V_14 ) {
F_122 ( V_12 ) ;
return NULL ;
}
F_123 ( V_14 ) ;
F_6 ( V_12 ) -> V_14 = V_14 ;
return V_12 ;
}
static int F_124 ( struct V_222 * V_222 , struct V_1 * V_2 , int V_231 ,
int V_232 )
{
struct V_2 * V_12 ;
F_7 ( L_12 , V_2 ) ;
V_2 -> V_47 = V_233 ;
if ( V_2 -> type != V_56 && V_2 -> type != V_57 &&
V_2 -> type != V_217 && V_2 -> type != V_137 )
return - V_234 ;
if ( V_2 -> type == V_137 && ! V_232 && ! F_3 ( V_235 ) )
return - V_163 ;
V_2 -> V_3 = & V_4 ;
V_12 = F_89 ( V_222 , V_2 , V_231 , V_197 ) ;
if ( ! V_12 )
return - V_200 ;
F_92 ( V_12 , NULL ) ;
F_125 ( & V_192 , V_12 ) ;
return 0 ;
}
int T_7 F_126 ( void )
{
int V_18 ;
V_18 = F_127 ( & V_226 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_128 ( V_196 , & V_236 ) ;
if ( V_18 < 0 ) {
F_129 ( L_13 ) ;
goto error;
}
V_18 = F_130 ( & V_237 , L_14 , & V_192 ,
NULL ) ;
if ( V_18 < 0 ) {
F_129 ( L_15 ) ;
F_131 ( V_196 ) ;
goto error;
}
F_132 ( L_16 ) ;
return 0 ;
error:
F_133 ( & V_226 ) ;
return V_18 ;
}
void F_134 ( void )
{
F_135 ( & V_237 , L_14 ) ;
F_131 ( V_196 ) ;
F_133 ( & V_226 ) ;
}
