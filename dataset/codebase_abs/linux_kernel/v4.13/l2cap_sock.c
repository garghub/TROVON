bool F_1 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_3 == & V_4 ;
}
static int F_2 ( T_1 V_5 )
{
if ( ( V_5 & 0x0101 ) != 0x0001 )
return - V_6 ;
if ( V_5 < V_7 && ! F_3 ( V_8 ) )
return - V_9 ;
return 0 ;
}
static int F_4 ( T_1 V_5 )
{
if ( V_5 > V_10 )
return - V_6 ;
if ( V_5 < V_11 && ! F_3 ( V_8 ) )
return - V_9 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_12 * V_13 , int V_14 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_18 V_19 ;
int V_20 , V_21 = 0 ;
F_7 ( L_1 , V_15 ) ;
if ( ! V_13 || V_14 < F_8 ( struct V_12 , V_22 ) ||
V_13 -> V_22 != V_23 )
return - V_6 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_20 = F_9 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_19 , V_13 , V_20 ) ;
if ( V_19 . V_24 && V_19 . V_25 )
return - V_6 ;
if ( ! F_10 ( V_19 . V_26 ) )
return - V_6 ;
if ( F_11 ( V_19 . V_26 ) ) {
if ( V_19 . V_24 &&
V_19 . V_24 != F_12 ( V_27 ) )
return - V_6 ;
}
F_13 ( V_15 ) ;
if ( V_15 -> V_28 != V_29 ) {
V_21 = - V_30 ;
goto V_31;
}
if ( V_19 . V_25 ) {
T_2 V_5 = F_14 ( V_19 . V_25 ) ;
if ( V_19 . V_26 == V_32 )
V_21 = F_2 ( V_5 ) ;
else
V_21 = F_4 ( V_5 ) ;
if ( V_21 )
goto V_31;
}
F_15 ( & V_17 -> V_33 , & V_19 . V_34 ) ;
V_17 -> V_35 = V_19 . V_26 ;
if ( V_19 . V_24 )
V_21 = F_16 ( V_17 , F_14 ( V_19 . V_24 ) ) ;
else
V_21 = F_17 ( V_17 , & V_19 . V_34 , V_19 . V_25 ) ;
if ( V_21 < 0 )
goto V_31;
switch ( V_17 -> V_36 ) {
case V_37 :
if ( F_14 ( V_19 . V_25 ) == V_38 )
V_17 -> V_39 = V_40 ;
break;
case V_41 :
if ( F_14 ( V_19 . V_25 ) == V_42 ||
F_14 ( V_19 . V_25 ) == V_43 )
V_17 -> V_39 = V_40 ;
break;
case V_44 :
V_17 -> V_39 = V_40 ;
break;
case V_45 :
F_18 ( V_46 , & V_17 -> V_47 ) ;
break;
}
if ( V_17 -> V_5 && F_11 ( V_17 -> V_35 ) )
V_17 -> V_48 = V_49 ;
V_17 -> V_50 = V_51 ;
V_15 -> V_28 = V_51 ;
V_31:
F_19 ( V_15 ) ;
return V_21 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_14 , int V_47 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_18 V_19 ;
int V_20 , V_21 = 0 ;
F_7 ( L_1 , V_15 ) ;
if ( ! V_13 || V_14 < F_8 ( struct V_12 , V_22 ) ||
V_13 -> V_22 != V_23 )
return - V_6 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_20 = F_9 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_19 , V_13 , V_20 ) ;
if ( V_19 . V_24 && V_19 . V_25 )
return - V_6 ;
if ( ! F_10 ( V_19 . V_26 ) )
return - V_6 ;
if ( V_17 -> V_35 == V_32 && F_21 ( & V_17 -> V_33 , V_52 ) &&
F_11 ( V_19 . V_26 ) ) {
if ( V_17 -> V_53 != V_27 ||
V_19 . V_24 != F_12 ( V_27 ) )
return - V_6 ;
V_17 -> V_35 = V_54 ;
}
if ( V_17 -> V_35 != V_32 && V_19 . V_26 == V_32 )
return - V_6 ;
if ( F_11 ( V_19 . V_26 ) ) {
if ( V_19 . V_24 &&
V_19 . V_24 != F_12 ( V_27 ) )
return - V_6 ;
}
if ( V_17 -> V_5 && F_11 ( V_17 -> V_35 ) )
V_17 -> V_48 = V_49 ;
V_21 = F_22 ( V_17 , V_19 . V_25 , F_14 ( V_19 . V_24 ) ,
& V_19 . V_34 , V_19 . V_26 ) ;
if ( V_21 )
return V_21 ;
F_13 ( V_15 ) ;
V_21 = F_23 ( V_15 , V_55 ,
F_24 ( V_15 , V_47 & V_56 ) ) ;
F_19 ( V_15 ) ;
return V_21 ;
}
static int F_25 ( struct V_1 * V_2 , int V_57 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
int V_21 = 0 ;
F_7 ( L_2 , V_15 , V_57 ) ;
F_13 ( V_15 ) ;
if ( V_15 -> V_28 != V_51 ) {
V_21 = - V_30 ;
goto V_31;
}
if ( V_15 -> V_58 != V_59 && V_15 -> V_58 != V_60 ) {
V_21 = - V_6 ;
goto V_31;
}
switch ( V_17 -> V_48 ) {
case V_61 :
case V_49 :
break;
case V_62 :
case V_63 :
if ( ! V_64 )
break;
default:
V_21 = - V_65 ;
goto V_31;
}
V_15 -> V_66 = V_57 ;
V_15 -> V_67 = 0 ;
F_26 ( & V_17 -> V_68 , V_69 ) ;
V_17 -> V_50 = V_70 ;
V_15 -> V_28 = V_70 ;
V_31:
F_19 ( V_15 ) ;
return V_21 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_1 * V_71 ,
int V_47 , bool V_72 )
{
F_28 ( V_73 , V_74 ) ;
struct V_2 * V_15 = V_2 -> V_15 , * V_75 ;
long V_76 ;
int V_21 = 0 ;
F_29 ( V_15 , V_69 ) ;
V_76 = F_30 ( V_15 , V_47 & V_56 ) ;
F_7 ( L_3 , V_15 , V_76 ) ;
F_31 ( F_32 ( V_15 ) , & V_73 ) ;
while ( 1 ) {
if ( V_15 -> V_28 != V_70 ) {
V_21 = - V_30 ;
break;
}
V_75 = F_33 ( V_15 , V_71 ) ;
if ( V_75 )
break;
if ( ! V_76 ) {
V_21 = - V_77 ;
break;
}
if ( F_34 ( V_78 ) ) {
V_21 = F_35 ( V_76 ) ;
break;
}
F_19 ( V_15 ) ;
V_76 = F_36 ( & V_73 , V_79 , V_76 ) ;
F_29 ( V_15 , V_69 ) ;
}
F_37 ( F_32 ( V_15 ) , & V_73 ) ;
if ( V_21 )
goto V_31;
V_71 -> V_50 = V_80 ;
F_7 ( L_4 , V_75 ) ;
V_31:
F_19 ( V_15 ) ;
return V_21 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int * V_20 , int V_81 )
{
struct V_18 * V_19 = (struct V_18 * ) V_13 ;
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
F_7 ( L_5 , V_2 , V_15 ) ;
if ( V_81 && V_15 -> V_28 != V_55 &&
V_15 -> V_28 != V_82 && V_15 -> V_28 != V_83 &&
V_15 -> V_28 != V_84 )
return - V_85 ;
memset ( V_19 , 0 , sizeof( struct V_18 ) ) ;
V_13 -> V_22 = V_23 ;
* V_20 = sizeof( struct V_18 ) ;
V_19 -> V_25 = V_17 -> V_5 ;
if ( V_81 ) {
F_15 ( & V_19 -> V_34 , & V_17 -> V_86 ) ;
V_19 -> V_24 = F_12 ( V_17 -> V_87 ) ;
V_19 -> V_26 = V_17 -> V_88 ;
} else {
F_15 ( & V_19 -> V_34 , & V_17 -> V_33 ) ;
V_19 -> V_24 = F_12 ( V_17 -> V_53 ) ;
V_19 -> V_26 = V_17 -> V_35 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_89 ,
char T_3 * V_90 , int T_3 * V_91 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_92 V_93 ;
struct V_94 V_95 ;
int V_20 , V_21 = 0 ;
T_4 V_96 ;
F_7 ( L_1 , V_15 ) ;
if ( F_40 ( V_20 , V_91 ) )
return - V_97 ;
F_13 ( V_15 ) ;
switch ( V_89 ) {
case V_98 :
if ( F_11 ( V_17 -> V_35 ) &&
V_17 -> V_53 != V_27 ) {
V_21 = - V_6 ;
break;
}
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_93 . V_99 = V_17 -> V_99 ;
V_93 . V_100 = V_17 -> V_100 ;
V_93 . V_101 = V_17 -> V_101 ;
V_93 . V_48 = V_17 -> V_48 ;
V_93 . V_102 = V_17 -> V_102 ;
V_93 . V_103 = V_17 -> V_103 ;
V_93 . V_104 = V_17 -> V_105 ;
V_20 = F_9 (unsigned int, len, sizeof(opts)) ;
if ( F_41 ( V_90 , ( char * ) & V_93 , V_20 ) )
V_21 = - V_97 ;
break;
case V_106 :
switch ( V_17 -> V_39 ) {
case V_107 :
V_96 = V_108 ;
break;
case V_109 :
V_96 = V_108 | V_110 ;
break;
case V_111 :
V_96 = V_108 | V_110 |
V_112 ;
break;
case V_113 :
V_96 = V_108 | V_110 |
V_112 | V_114 ;
break;
default:
V_96 = 0 ;
break;
}
if ( F_42 ( V_115 , & V_17 -> V_47 ) )
V_96 |= V_116 ;
if ( F_42 ( V_117 , & V_17 -> V_47 ) )
V_96 |= V_118 ;
if ( F_43 ( V_96 , ( T_4 T_3 * ) V_90 ) )
V_21 = - V_97 ;
break;
case V_119 :
if ( V_15 -> V_28 != V_55 &&
! ( V_15 -> V_28 == V_83 &&
F_42 ( V_120 , & F_44 ( V_15 ) -> V_47 ) ) ) {
V_21 = - V_85 ;
break;
}
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_121 = V_17 -> V_122 -> V_123 -> V_124 ;
memcpy ( V_95 . V_125 , V_17 -> V_122 -> V_123 -> V_125 , 3 ) ;
V_20 = F_9 (unsigned int, len, sizeof(cinfo)) ;
if ( F_41 ( V_90 , ( char * ) & V_95 , V_20 ) )
V_21 = - V_97 ;
break;
default:
V_21 = - V_126 ;
break;
}
F_19 ( V_15 ) ;
return V_21 ;
}
static int F_45 ( struct V_1 * V_2 , int V_127 , int V_89 ,
char T_3 * V_90 , int T_3 * V_91 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_128 V_129 ;
struct V_130 V_131 ;
int V_20 , V_21 = 0 ;
F_7 ( L_1 , V_15 ) ;
if ( V_127 == V_132 )
return F_39 ( V_2 , V_89 , V_90 , V_91 ) ;
if ( V_127 != V_133 )
return - V_126 ;
if ( F_40 ( V_20 , V_91 ) )
return - V_97 ;
F_13 ( V_15 ) ;
switch ( V_89 ) {
case V_134 :
if ( V_17 -> V_36 != V_41 &&
V_17 -> V_36 != V_45 &&
V_17 -> V_36 != V_44 ) {
V_21 = - V_6 ;
break;
}
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
if ( V_17 -> V_122 ) {
V_129 . V_127 = V_17 -> V_122 -> V_123 -> V_39 ;
if ( V_15 -> V_28 == V_55 )
V_129 . V_135 = V_17 -> V_122 -> V_123 -> V_136 ;
} else {
V_129 . V_127 = V_17 -> V_39 ;
}
V_20 = F_9 (unsigned int, len, sizeof(sec)) ;
if ( F_41 ( V_90 , ( char * ) & V_129 , V_20 ) )
V_21 = - V_97 ;
break;
case V_137 :
if ( V_15 -> V_28 != V_51 && V_15 -> V_28 != V_70 ) {
V_21 = - V_6 ;
break;
}
if ( F_43 ( F_42 ( V_120 , & F_44 ( V_15 ) -> V_47 ) ,
( T_4 T_3 * ) V_90 ) )
V_21 = - V_97 ;
break;
case V_138 :
if ( F_43 ( F_42 ( V_139 , & V_17 -> V_47 ) ,
( T_4 T_3 * ) V_90 ) )
V_21 = - V_97 ;
break;
case V_140 :
if ( V_15 -> V_58 != V_59 && V_15 -> V_58 != V_60
&& V_15 -> V_58 != V_141 ) {
V_21 = - V_6 ;
break;
}
V_131 . V_142 = F_42 ( V_143 , & V_17 -> V_47 ) ;
V_20 = F_9 (unsigned int, len, sizeof(pwr)) ;
if ( F_41 ( V_90 , ( char * ) & V_131 , V_20 ) )
V_21 = - V_97 ;
break;
case V_144 :
if ( F_43 ( V_17 -> V_145 , ( T_4 T_3 * ) V_90 ) )
V_21 = - V_97 ;
break;
case V_146 :
if ( ! F_11 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( V_15 -> V_28 != V_55 ) {
V_21 = - V_85 ;
break;
}
if ( F_43 ( V_17 -> V_100 , ( T_1 T_3 * ) V_90 ) )
V_21 = - V_97 ;
break;
case V_147 :
if ( ! F_11 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( F_43 ( V_17 -> V_99 , ( T_1 T_3 * ) V_90 ) )
V_21 = - V_97 ;
break;
default:
V_21 = - V_126 ;
break;
}
F_19 ( V_15 ) ;
return V_21 ;
}
static bool F_46 ( struct V_16 * V_17 , T_1 V_148 )
{
switch ( V_17 -> V_53 ) {
case V_27 :
if ( V_148 < V_149 )
return false ;
break;
default:
if ( V_148 < V_150 )
return false ;
}
return true ;
}
static int F_47 ( struct V_1 * V_2 , int V_89 ,
char T_3 * V_90 , unsigned int V_91 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_92 V_93 ;
int V_20 , V_21 = 0 ;
T_4 V_96 ;
F_7 ( L_1 , V_15 ) ;
F_13 ( V_15 ) ;
switch ( V_89 ) {
case V_98 :
if ( F_11 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( V_15 -> V_28 == V_55 ) {
V_21 = - V_6 ;
break;
}
V_93 . V_99 = V_17 -> V_99 ;
V_93 . V_100 = V_17 -> V_100 ;
V_93 . V_101 = V_17 -> V_101 ;
V_93 . V_48 = V_17 -> V_48 ;
V_93 . V_102 = V_17 -> V_102 ;
V_93 . V_103 = V_17 -> V_103 ;
V_93 . V_104 = V_17 -> V_105 ;
V_20 = F_9 (unsigned int, sizeof(opts), optlen) ;
if ( F_48 ( ( char * ) & V_93 , V_90 , V_20 ) ) {
V_21 = - V_97 ;
break;
}
if ( V_93 . V_104 > V_151 ) {
V_21 = - V_6 ;
break;
}
if ( ! F_46 ( V_17 , V_93 . V_99 ) ) {
V_21 = - V_6 ;
break;
}
V_17 -> V_48 = V_93 . V_48 ;
switch ( V_17 -> V_48 ) {
case V_49 :
break;
case V_61 :
F_49 ( V_152 , & V_17 -> V_153 ) ;
break;
case V_62 :
case V_63 :
if ( ! V_64 )
break;
default:
V_21 = - V_6 ;
break;
}
V_17 -> V_99 = V_93 . V_99 ;
V_17 -> V_100 = V_93 . V_100 ;
V_17 -> V_102 = V_93 . V_102 ;
V_17 -> V_103 = V_93 . V_103 ;
V_17 -> V_105 = V_93 . V_104 ;
V_17 -> V_101 = V_93 . V_101 ;
break;
case V_106 :
if ( F_40 ( V_96 , ( T_4 T_3 * ) V_90 ) ) {
V_21 = - V_97 ;
break;
}
if ( V_96 & V_114 ) {
V_21 = - V_6 ;
break;
}
if ( V_96 & V_108 )
V_17 -> V_39 = V_107 ;
if ( V_96 & V_110 )
V_17 -> V_39 = V_109 ;
if ( V_96 & V_112 )
V_17 -> V_39 = V_111 ;
if ( V_96 & V_116 )
F_18 ( V_115 , & V_17 -> V_47 ) ;
else
F_49 ( V_115 , & V_17 -> V_47 ) ;
if ( V_96 & V_118 )
F_18 ( V_117 , & V_17 -> V_47 ) ;
else
F_49 ( V_117 , & V_17 -> V_47 ) ;
break;
default:
V_21 = - V_126 ;
break;
}
F_19 ( V_15 ) ;
return V_21 ;
}
static int F_50 ( struct V_1 * V_2 , int V_127 , int V_89 ,
char T_3 * V_90 , unsigned int V_91 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
struct V_128 V_129 ;
struct V_130 V_131 ;
struct V_154 * V_122 ;
int V_20 , V_21 = 0 ;
T_4 V_96 ;
F_7 ( L_1 , V_15 ) ;
if ( V_127 == V_132 )
return F_47 ( V_2 , V_89 , V_90 , V_91 ) ;
if ( V_127 != V_133 )
return - V_126 ;
F_13 ( V_15 ) ;
switch ( V_89 ) {
case V_134 :
if ( V_17 -> V_36 != V_41 &&
V_17 -> V_36 != V_45 &&
V_17 -> V_36 != V_44 ) {
V_21 = - V_6 ;
break;
}
V_129 . V_127 = V_107 ;
V_20 = F_9 (unsigned int, sizeof(sec), optlen) ;
if ( F_48 ( ( char * ) & V_129 , V_90 , V_20 ) ) {
V_21 = - V_97 ;
break;
}
if ( V_129 . V_127 < V_107 ||
V_129 . V_127 > V_113 ) {
V_21 = - V_6 ;
break;
}
V_17 -> V_39 = V_129 . V_127 ;
if ( ! V_17 -> V_122 )
break;
V_122 = V_17 -> V_122 ;
if ( V_17 -> V_53 == V_27 ) {
if ( F_51 ( V_122 -> V_123 , V_129 . V_127 ) )
break;
F_18 ( V_155 , & V_17 -> V_47 ) ;
V_15 -> V_28 = V_84 ;
V_17 -> V_50 = V_84 ;
} else if ( ( V_15 -> V_28 == V_83 &&
F_42 ( V_120 , & F_44 ( V_15 ) -> V_47 ) ) ||
V_15 -> V_28 == V_55 ) {
if ( ! F_52 ( V_17 , true ) )
F_18 ( V_156 , & F_44 ( V_15 ) -> V_47 ) ;
else
V_15 -> V_157 ( V_15 ) ;
} else {
V_21 = - V_6 ;
}
break;
case V_137 :
if ( V_15 -> V_28 != V_51 && V_15 -> V_28 != V_70 ) {
V_21 = - V_6 ;
break;
}
if ( F_40 ( V_96 , ( T_4 T_3 * ) V_90 ) ) {
V_21 = - V_97 ;
break;
}
if ( V_96 ) {
F_18 ( V_120 , & F_44 ( V_15 ) -> V_47 ) ;
F_18 ( V_158 , & V_17 -> V_47 ) ;
} else {
F_49 ( V_120 , & F_44 ( V_15 ) -> V_47 ) ;
F_49 ( V_158 , & V_17 -> V_47 ) ;
}
break;
case V_138 :
if ( F_40 ( V_96 , ( T_4 T_3 * ) V_90 ) ) {
V_21 = - V_97 ;
break;
}
if ( V_96 > V_159 ) {
V_21 = - V_6 ;
break;
}
if ( V_96 == V_160 ) {
V_122 = V_17 -> V_122 ;
if ( ! V_122 || ! F_53 ( V_122 -> V_123 -> V_161 ) ) {
V_21 = - V_6 ;
break;
}
}
if ( V_96 )
F_18 ( V_139 , & V_17 -> V_47 ) ;
else
F_49 ( V_139 , & V_17 -> V_47 ) ;
break;
case V_140 :
if ( V_17 -> V_36 != V_41 &&
V_17 -> V_36 != V_44 ) {
V_21 = - V_6 ;
break;
}
V_131 . V_142 = V_162 ;
V_20 = F_9 (unsigned int, sizeof(pwr), optlen) ;
if ( F_48 ( ( char * ) & V_131 , V_90 , V_20 ) ) {
V_21 = - V_97 ;
break;
}
if ( V_131 . V_142 )
F_18 ( V_143 , & V_17 -> V_47 ) ;
else
F_49 ( V_143 , & V_17 -> V_47 ) ;
break;
case V_144 :
if ( F_40 ( V_96 , ( T_4 T_3 * ) V_90 ) ) {
V_21 = - V_97 ;
break;
}
if ( V_96 > V_163 ) {
V_21 = - V_6 ;
break;
}
if ( V_17 -> V_48 != V_62 &&
V_17 -> V_48 != V_63 ) {
V_21 = - V_65 ;
break;
}
V_17 -> V_145 = ( V_164 ) V_96 ;
if ( V_15 -> V_28 == V_55 &&
V_17 -> V_165 == V_166 )
F_54 ( V_17 ) ;
break;
case V_146 :
if ( ! F_11 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
V_21 = - V_167 ;
break;
case V_147 :
if ( ! F_11 ( V_17 -> V_35 ) ) {
V_21 = - V_6 ;
break;
}
if ( V_15 -> V_28 == V_55 ) {
V_21 = - V_168 ;
break;
}
if ( F_40 ( V_96 , ( T_1 T_3 * ) V_90 ) ) {
V_21 = - V_97 ;
break;
}
V_17 -> V_99 = V_96 ;
break;
default:
V_21 = - V_126 ;
break;
}
F_19 ( V_15 ) ;
return V_21 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_169 * V_170 ,
T_5 V_20 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
int V_21 ;
F_7 ( L_5 , V_2 , V_15 ) ;
V_21 = F_56 ( V_15 ) ;
if ( V_21 )
return V_21 ;
if ( V_170 -> V_171 & V_172 )
return - V_65 ;
if ( V_15 -> V_28 != V_55 )
return - V_85 ;
F_13 ( V_15 ) ;
V_21 = F_57 ( V_15 , V_170 -> V_171 ) ;
F_19 ( V_15 ) ;
if ( V_21 )
return V_21 ;
F_58 ( V_17 ) ;
V_21 = F_59 ( V_17 , V_170 , V_20 ) ;
F_60 ( V_17 ) ;
return V_21 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_169 * V_170 ,
T_5 V_20 , int V_47 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_173 * V_174 = F_6 ( V_15 ) ;
int V_21 ;
F_13 ( V_15 ) ;
if ( V_15 -> V_28 == V_83 && F_42 ( V_120 ,
& F_44 ( V_15 ) -> V_47 ) ) {
if ( F_11 ( V_174 -> V_17 -> V_35 ) ) {
V_15 -> V_28 = V_55 ;
V_174 -> V_17 -> V_50 = V_55 ;
F_62 ( V_174 -> V_17 ) ;
} else {
V_15 -> V_28 = V_84 ;
V_174 -> V_17 -> V_50 = V_84 ;
F_63 ( V_174 -> V_17 ) ;
}
V_21 = 0 ;
goto V_31;
}
F_19 ( V_15 ) ;
if ( V_2 -> type == V_60 )
V_21 = F_64 ( V_2 , V_170 , V_20 , V_47 ) ;
else
V_21 = F_65 ( V_2 , V_170 , V_20 , V_47 ) ;
if ( V_174 -> V_17 -> V_48 != V_62 )
return V_21 ;
F_13 ( V_15 ) ;
if ( ! F_42 ( V_175 , & V_174 -> V_17 -> V_176 ) )
goto V_31;
if ( V_174 -> V_177 ) {
if ( ! F_66 ( V_15 , V_174 -> V_177 ) )
V_174 -> V_177 = NULL ;
else
goto V_31;
}
if ( F_67 ( & V_15 -> V_178 ) <= V_15 -> V_179 >> 1 )
F_68 ( V_174 -> V_17 , 0 ) ;
V_31:
F_19 ( V_15 ) ;
return V_21 ;
}
static void F_69 ( struct V_2 * V_15 )
{
if ( ! F_70 ( V_15 , V_180 ) || V_15 -> V_181 )
return;
F_7 ( L_6 , V_15 , F_71 ( V_15 -> V_28 ) ) ;
F_72 ( F_6 ( V_15 ) -> V_17 ) ;
F_73 ( V_15 , V_182 ) ;
F_74 ( V_15 ) ;
}
static int F_75 ( struct V_2 * V_15 , struct V_16 * V_17 )
{
F_76 ( V_73 , V_78 ) ;
int V_21 = 0 ;
int V_76 = V_183 ;
unsigned long V_184 = V_185 + V_186 ;
F_77 ( F_32 ( V_15 ) , & V_73 ) ;
F_78 ( V_79 ) ;
do {
F_7 ( L_7 ,
V_17 -> V_187 , F_79 ( V_185 , V_184 ) ? 0 :
F_80 ( V_184 - V_185 ) ) ;
if ( ! V_76 )
V_76 = V_183 ;
if ( F_34 ( V_78 ) ) {
V_21 = F_35 ( V_76 ) ;
break;
}
F_19 ( V_15 ) ;
V_76 = F_81 ( V_76 ) ;
F_13 ( V_15 ) ;
F_78 ( V_79 ) ;
V_21 = F_56 ( V_15 ) ;
if ( V_21 )
break;
if ( F_79 ( V_185 , V_184 ) ) {
V_21 = - V_188 ;
break;
}
} while ( V_17 -> V_187 > 0 &&
V_17 -> V_50 == V_55 );
F_78 ( V_189 ) ;
F_37 ( F_32 ( V_15 ) , & V_73 ) ;
return V_21 ;
}
static int F_82 ( struct V_1 * V_2 , int V_190 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
struct V_16 * V_17 ;
struct V_154 * V_122 ;
int V_21 = 0 ;
F_7 ( L_5 , V_2 , V_15 ) ;
if ( ! V_15 )
return 0 ;
F_13 ( V_15 ) ;
if ( V_15 -> V_191 )
goto V_192;
F_7 ( L_8 ) ;
F_83 ( V_15 ) ;
V_17 = F_6 ( V_15 ) -> V_17 ;
F_84 ( V_17 ) ;
F_7 ( L_9 , V_17 , F_71 ( V_17 -> V_50 ) ) ;
if ( V_17 -> V_48 == V_62 &&
V_17 -> V_187 > 0 &&
V_17 -> V_50 == V_55 ) {
V_21 = F_75 ( V_15 , V_17 ) ;
if ( V_15 -> V_191 )
goto V_193;
}
V_15 -> V_191 = V_194 ;
F_19 ( V_15 ) ;
F_58 ( V_17 ) ;
V_122 = V_17 -> V_122 ;
if ( V_122 )
F_85 ( V_122 ) ;
F_60 ( V_17 ) ;
if ( V_122 )
F_86 ( & V_122 -> V_195 ) ;
F_58 ( V_17 ) ;
F_87 ( V_17 , 0 ) ;
F_60 ( V_17 ) ;
if ( V_122 ) {
F_88 ( & V_122 -> V_195 ) ;
F_89 ( V_122 ) ;
}
F_13 ( V_15 ) ;
if ( F_70 ( V_15 , V_196 ) && V_15 -> V_197 &&
! ( V_78 -> V_47 & V_198 ) )
V_21 = F_23 ( V_15 , V_199 ,
V_15 -> V_197 ) ;
V_193:
F_72 ( V_17 ) ;
F_74 ( V_15 ) ;
V_192:
if ( ! V_21 && V_15 -> V_200 )
V_21 = - V_15 -> V_200 ;
F_19 ( V_15 ) ;
F_7 ( L_10 , V_21 ) ;
return V_21 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_2 * V_15 = V_2 -> V_15 ;
int V_21 ;
F_7 ( L_5 , V_2 , V_15 ) ;
if ( ! V_15 )
return 0 ;
F_91 ( & V_201 , V_15 ) ;
V_21 = F_82 ( V_2 , 2 ) ;
F_92 ( V_15 ) ;
F_69 ( V_15 ) ;
return V_21 ;
}
static void F_93 ( struct V_2 * V_202 )
{
struct V_2 * V_15 ;
F_7 ( L_11 , V_202 ,
F_71 ( V_202 -> V_28 ) ) ;
while ( ( V_15 = F_33 ( V_202 , NULL ) ) ) {
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
F_7 ( L_12 , V_17 ,
F_71 ( V_17 -> V_50 ) ) ;
F_58 ( V_17 ) ;
F_94 ( V_17 ) ;
F_87 ( V_17 , V_203 ) ;
F_60 ( V_17 ) ;
F_69 ( V_15 ) ;
}
}
static struct V_16 * F_95 ( struct V_16 * V_17 )
{
struct V_2 * V_15 , * V_202 = V_17 -> V_204 ;
F_13 ( V_202 ) ;
if ( F_96 ( V_202 ) ) {
F_7 ( L_13 , V_202 -> V_67 ) ;
F_19 ( V_202 ) ;
return NULL ;
}
V_15 = F_97 ( F_98 ( V_202 ) , NULL , V_205 ,
V_206 , 0 ) ;
if ( ! V_15 ) {
F_19 ( V_202 ) ;
return NULL ;
}
F_99 ( V_15 , V_205 ) ;
F_100 ( V_15 , V_202 ) ;
F_101 ( V_202 , V_15 ) ;
F_19 ( V_202 ) ;
return F_6 ( V_15 ) -> V_17 ;
}
static int F_102 ( struct V_16 * V_17 , struct V_207 * V_208 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
int V_21 ;
F_13 ( V_15 ) ;
if ( F_6 ( V_15 ) -> V_177 ) {
V_21 = - V_209 ;
goto V_31;
}
if ( V_17 -> V_48 != V_62 &&
V_17 -> V_48 != V_63 ) {
V_21 = F_103 ( V_15 , V_208 ) ;
if ( V_21 )
goto V_31;
}
V_21 = F_66 ( V_15 , V_208 ) ;
if ( V_21 < 0 && V_17 -> V_48 == V_62 ) {
F_6 ( V_15 ) -> V_177 = V_208 ;
F_68 ( V_17 , 1 ) ;
V_21 = 0 ;
}
V_31:
F_19 ( V_15 ) ;
return V_21 ;
}
static void F_104 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
F_69 ( V_15 ) ;
}
static void F_105 ( struct V_16 * V_17 , int V_21 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
struct V_2 * V_202 ;
F_7 ( L_9 , V_17 , F_71 ( V_17 -> V_50 ) ) ;
F_29 ( V_15 , F_67 ( & V_17 -> V_68 ) ) ;
V_202 = F_44 ( V_15 ) -> V_202 ;
F_73 ( V_15 , V_180 ) ;
switch ( V_17 -> V_50 ) {
case V_29 :
case V_51 :
case V_199 :
break;
case V_70 :
F_93 ( V_15 ) ;
V_15 -> V_28 = V_199 ;
V_17 -> V_50 = V_199 ;
break;
default:
V_15 -> V_28 = V_199 ;
V_17 -> V_50 = V_199 ;
V_15 -> V_200 = V_21 ;
if ( V_202 ) {
F_106 ( V_15 ) ;
V_202 -> V_210 ( V_202 ) ;
} else {
V_15 -> V_157 ( V_15 ) ;
}
break;
}
F_19 ( V_15 ) ;
}
static void F_107 ( struct V_16 * V_17 , int V_50 ,
int V_21 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
V_15 -> V_28 = V_50 ;
if ( V_21 )
V_15 -> V_200 = V_21 ;
}
static struct V_207 * F_108 ( struct V_16 * V_17 ,
unsigned long V_211 ,
unsigned long V_20 , int V_212 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
struct V_207 * V_208 ;
int V_21 ;
F_60 ( V_17 ) ;
V_208 = F_109 ( V_15 , V_211 + V_20 , V_212 , & V_21 ) ;
F_58 ( V_17 ) ;
if ( ! V_208 )
return F_110 ( V_21 ) ;
V_208 -> V_213 = V_15 -> V_214 ;
F_111 ( V_208 ) -> V_215 . V_17 = V_17 ;
return V_208 ;
}
static void F_112 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
struct V_2 * V_202 ;
F_13 ( V_15 ) ;
V_202 = F_44 ( V_15 ) -> V_202 ;
F_7 ( L_14 , V_15 , V_202 ) ;
V_15 -> V_28 = V_55 ;
V_15 -> V_157 ( V_15 ) ;
if ( V_202 )
V_202 -> V_210 ( V_202 ) ;
F_19 ( V_15 ) ;
}
static void F_113 ( struct V_16 * V_17 )
{
struct V_2 * V_202 , * V_15 = V_17 -> V_204 ;
F_13 ( V_15 ) ;
V_202 = F_44 ( V_15 ) -> V_202 ;
if ( V_202 )
V_202 -> V_210 ( V_202 ) ;
F_19 ( V_15 ) ;
}
static void F_114 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
if ( F_115 ( V_155 , & V_17 -> V_47 ) ) {
V_15 -> V_28 = V_55 ;
V_17 -> V_50 = V_55 ;
}
F_49 ( V_156 , & F_44 ( V_15 ) -> V_47 ) ;
V_15 -> V_157 ( V_15 ) ;
}
static void F_116 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
F_13 ( V_15 ) ;
V_15 -> V_191 = V_194 ;
F_19 ( V_15 ) ;
}
static long F_117 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
return V_15 -> V_216 ;
}
static void F_118 ( struct V_16 * V_17 )
{
struct V_2 * V_15 = V_17 -> V_204 ;
F_18 ( V_156 , & F_44 ( V_15 ) -> V_47 ) ;
V_15 -> V_157 ( V_15 ) ;
}
static void F_119 ( struct V_2 * V_15 )
{
F_7 ( L_1 , V_15 ) ;
if ( F_6 ( V_15 ) -> V_17 )
F_72 ( F_6 ( V_15 ) -> V_17 ) ;
if ( F_6 ( V_15 ) -> V_177 ) {
F_120 ( F_6 ( V_15 ) -> V_177 ) ;
F_6 ( V_15 ) -> V_177 = NULL ;
}
F_121 ( & V_15 -> V_217 ) ;
F_121 ( & V_15 -> V_218 ) ;
}
static void F_122 ( struct V_207 * V_208 , void * V_219 ,
int * V_220 )
{
F_123 ( struct V_18 * , V_19 , V_219 ) ;
memset ( V_19 , 0 , sizeof( struct V_18 ) ) ;
V_19 -> V_221 = V_23 ;
V_19 -> V_25 = F_111 ( V_208 ) -> V_215 . V_5 ;
F_15 ( & V_19 -> V_34 , & F_111 ( V_208 ) -> V_215 . V_222 ) ;
* V_220 = sizeof( struct V_18 ) ;
}
static void F_100 ( struct V_2 * V_15 , struct V_2 * V_202 )
{
struct V_16 * V_17 = F_6 ( V_15 ) -> V_17 ;
F_7 ( L_1 , V_15 ) ;
if ( V_202 ) {
struct V_16 * V_223 = F_6 ( V_202 ) -> V_17 ;
V_15 -> V_58 = V_202 -> V_58 ;
F_44 ( V_15 ) -> V_47 = F_44 ( V_202 ) -> V_47 ;
V_17 -> V_36 = V_223 -> V_36 ;
V_17 -> V_99 = V_223 -> V_99 ;
V_17 -> V_100 = V_223 -> V_100 ;
V_17 -> V_153 = V_223 -> V_153 ;
V_17 -> V_48 = V_223 -> V_48 ;
V_17 -> V_102 = V_223 -> V_102 ;
V_17 -> V_103 = V_223 -> V_103 ;
V_17 -> V_105 = V_223 -> V_105 ;
V_17 -> V_224 = V_223 -> V_224 ;
V_17 -> V_39 = V_223 -> V_39 ;
V_17 -> V_47 = V_223 -> V_47 ;
V_17 -> V_225 = V_223 -> V_225 ;
V_17 -> V_226 = V_223 -> V_226 ;
if ( V_17 -> V_36 == V_45 ) {
V_17 -> V_53 = V_223 -> V_53 ;
V_17 -> V_87 = V_223 -> V_53 ;
}
F_124 ( V_202 , V_15 ) ;
} else {
switch ( V_15 -> V_58 ) {
case V_141 :
V_17 -> V_36 = V_44 ;
break;
case V_227 :
V_17 -> V_36 = V_37 ;
F_44 ( V_15 ) -> V_228 = F_122 ;
break;
case V_59 :
case V_60 :
V_17 -> V_36 = V_41 ;
break;
}
V_17 -> V_99 = V_229 ;
V_17 -> V_100 = 0 ;
if ( ! V_64 && V_15 -> V_58 == V_60 ) {
V_17 -> V_48 = V_62 ;
F_18 ( V_152 , & V_17 -> V_153 ) ;
} else {
V_17 -> V_48 = V_61 ;
}
F_125 ( V_17 ) ;
}
V_17 -> V_101 = V_230 ;
V_17 -> V_204 = V_15 ;
V_17 -> V_3 = & V_231 ;
}
static struct V_2 * F_97 ( struct V_232 * V_232 , struct V_1 * V_2 ,
int V_233 , T_6 V_234 , int V_72 )
{
struct V_2 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_126 ( V_232 , V_235 , V_234 , & V_236 , V_72 ) ;
if ( ! V_15 )
return NULL ;
F_127 ( V_2 , V_15 ) ;
F_128 ( & F_44 ( V_15 ) -> V_237 ) ;
V_15 -> V_238 = F_119 ;
V_15 -> V_216 = V_239 ;
F_129 ( V_15 , V_180 ) ;
V_15 -> V_240 = V_233 ;
V_15 -> V_28 = V_29 ;
V_17 = F_130 () ;
if ( ! V_17 ) {
F_131 ( V_15 ) ;
return NULL ;
}
F_84 ( V_17 ) ;
F_6 ( V_15 ) -> V_17 = V_17 ;
return V_15 ;
}
static int F_132 ( struct V_232 * V_232 , struct V_1 * V_2 , int V_241 ,
int V_72 )
{
struct V_2 * V_15 ;
F_7 ( L_15 , V_2 ) ;
V_2 -> V_50 = V_242 ;
if ( V_2 -> type != V_59 && V_2 -> type != V_60 &&
V_2 -> type != V_227 && V_2 -> type != V_141 )
return - V_243 ;
if ( V_2 -> type == V_141 && ! V_72 && ! F_3 ( V_244 ) )
return - V_167 ;
V_2 -> V_3 = & V_4 ;
V_15 = F_97 ( V_232 , V_2 , V_241 , V_206 , V_72 ) ;
if ( ! V_15 )
return - V_209 ;
F_100 ( V_15 , NULL ) ;
F_133 ( & V_201 , V_15 ) ;
return 0 ;
}
int T_7 F_134 ( void )
{
int V_21 ;
F_135 ( sizeof( struct V_18 ) > sizeof( struct V_12 ) ) ;
V_21 = F_136 ( & V_236 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_137 ( V_205 , & V_245 ) ;
if ( V_21 < 0 ) {
F_138 ( L_16 ) ;
goto error;
}
V_21 = F_139 ( & V_246 , L_17 , & V_201 ,
NULL ) ;
if ( V_21 < 0 ) {
F_138 ( L_18 ) ;
F_140 ( V_205 ) ;
goto error;
}
F_141 ( L_19 ) ;
return 0 ;
error:
F_142 ( & V_236 ) ;
return V_21 ;
}
void F_143 ( void )
{
F_144 ( & V_246 , L_17 ) ;
F_140 ( V_205 ) ;
F_142 ( & V_236 ) ;
}
