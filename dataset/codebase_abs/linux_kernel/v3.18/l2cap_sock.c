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
V_14 -> V_47 = V_65 ;
V_12 -> V_25 = V_65 ;
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_1 * V_66 ,
int V_42 )
{
F_26 ( V_67 , V_68 ) ;
struct V_2 * V_12 = V_2 -> V_12 , * V_69 ;
long V_70 ;
int V_18 = 0 ;
F_27 ( V_12 , V_71 ) ;
V_70 = F_28 ( V_12 , V_42 & V_53 ) ;
F_7 ( L_3 , V_12 , V_70 ) ;
F_29 ( F_30 ( V_12 ) , & V_67 ) ;
while ( 1 ) {
F_31 ( V_72 ) ;
if ( V_12 -> V_25 != V_65 ) {
V_18 = - V_27 ;
break;
}
V_69 = F_32 ( V_12 , V_66 ) ;
if ( V_69 )
break;
if ( ! V_70 ) {
V_18 = - V_73 ;
break;
}
if ( F_33 ( V_68 ) ) {
V_18 = F_34 ( V_70 ) ;
break;
}
F_18 ( V_12 ) ;
V_70 = F_35 ( V_70 ) ;
F_27 ( V_12 , V_71 ) ;
}
F_36 ( V_74 ) ;
F_37 ( F_30 ( V_12 ) , & V_67 ) ;
if ( V_18 )
goto V_28;
V_66 -> V_47 = V_75 ;
F_7 ( L_4 , V_69 ) ;
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int * V_17 , int V_76 )
{
struct V_15 * V_16 = (struct V_15 * ) V_10 ;
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( V_76 && V_12 -> V_25 != V_52 &&
V_12 -> V_25 != V_77 && V_12 -> V_25 != V_78 &&
V_12 -> V_25 != V_79 )
return - V_80 ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_10 -> V_19 = V_20 ;
* V_17 = sizeof( struct V_15 ) ;
V_16 -> V_22 = V_14 -> V_5 ;
if ( V_76 ) {
F_17 ( & V_16 -> V_30 , & V_14 -> V_81 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_82 ) ;
V_16 -> V_23 = V_14 -> V_83 ;
} else {
F_17 ( & V_16 -> V_30 , & V_14 -> V_43 ) ;
V_16 -> V_21 = F_11 ( V_14 -> V_50 ) ;
V_16 -> V_23 = V_14 -> V_44 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_84 ,
char T_3 * V_85 , int T_3 * V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_87 V_88 ;
struct V_89 V_90 ;
int V_17 , V_18 = 0 ;
T_4 V_91 ;
F_7 ( L_1 , V_12 ) ;
if ( F_40 ( V_17 , V_86 ) )
return - V_92 ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_93 :
if ( F_10 ( V_14 -> V_44 ) &&
V_14 -> V_50 != V_24 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_94 = V_14 -> V_94 ;
V_88 . V_95 = V_14 -> V_95 ;
V_88 . V_96 = V_14 -> V_96 ;
V_88 . V_45 = V_14 -> V_45 ;
V_88 . V_97 = V_14 -> V_97 ;
V_88 . V_98 = V_14 -> V_98 ;
V_88 . V_99 = V_14 -> V_100 ;
V_17 = F_8 (unsigned int, len, sizeof(opts)) ;
if ( F_41 ( V_85 , ( char * ) & V_88 , V_17 ) )
V_18 = - V_92 ;
break;
case V_101 :
switch ( V_14 -> V_34 ) {
case V_102 :
V_91 = V_103 ;
break;
case V_104 :
V_91 = V_103 | V_105 ;
break;
case V_106 :
V_91 = V_103 | V_105 |
V_107 ;
break;
case V_108 :
V_91 = V_103 | V_105 |
V_107 | V_109 ;
break;
default:
V_91 = 0 ;
break;
}
if ( F_42 ( V_110 , & V_14 -> V_42 ) )
V_91 |= V_111 ;
if ( F_42 ( V_112 , & V_14 -> V_42 ) )
V_91 |= V_113 ;
if ( F_43 ( V_91 , ( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_114 :
if ( V_12 -> V_25 != V_52 &&
! ( V_12 -> V_25 == V_78 &&
F_42 ( V_115 , & F_44 ( V_12 ) -> V_42 ) ) ) {
V_18 = - V_80 ;
break;
}
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_90 . V_116 = V_14 -> V_117 -> V_118 -> V_119 ;
memcpy ( V_90 . V_120 , V_14 -> V_117 -> V_118 -> V_120 , 3 ) ;
V_17 = F_8 (unsigned int, len, sizeof(cinfo)) ;
if ( F_41 ( V_85 , ( char * ) & V_90 , V_17 ) )
V_18 = - V_92 ;
break;
default:
V_18 = - V_121 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_45 ( struct V_1 * V_2 , int V_122 , int V_84 ,
char T_3 * V_85 , int T_3 * V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_123 V_124 ;
struct V_125 V_126 ;
int V_17 , V_18 = 0 ;
F_7 ( L_1 , V_12 ) ;
if ( V_122 == V_127 )
return F_39 ( V_2 , V_84 , V_85 , V_86 ) ;
if ( V_122 != V_128 )
return - V_121 ;
if ( F_40 ( V_17 , V_86 ) )
return - V_92 ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_129 :
if ( V_14 -> V_31 != V_36 &&
V_14 -> V_31 != V_40 &&
V_14 -> V_31 != V_39 ) {
V_18 = - V_6 ;
break;
}
memset ( & V_124 , 0 , sizeof( V_124 ) ) ;
if ( V_14 -> V_117 ) {
V_124 . V_122 = V_14 -> V_117 -> V_118 -> V_34 ;
if ( V_12 -> V_25 == V_52 )
V_124 . V_130 = V_14 -> V_117 -> V_118 -> V_131 ;
} else {
V_124 . V_122 = V_14 -> V_34 ;
}
V_17 = F_8 (unsigned int, len, sizeof(sec)) ;
if ( F_41 ( V_85 , ( char * ) & V_124 , V_17 ) )
V_18 = - V_92 ;
break;
case V_132 :
if ( V_12 -> V_25 != V_48 && V_12 -> V_25 != V_65 ) {
V_18 = - V_6 ;
break;
}
if ( F_43 ( F_42 ( V_115 , & F_44 ( V_12 ) -> V_42 ) ,
( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_133 :
if ( F_43 ( F_42 ( V_134 , & V_14 -> V_42 ) ,
( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_135 :
if ( V_12 -> V_55 != V_56 && V_12 -> V_55 != V_57
&& V_12 -> V_55 != V_136 ) {
V_18 = - V_6 ;
break;
}
V_126 . V_137 = F_42 ( V_138 , & V_14 -> V_42 ) ;
V_17 = F_8 (unsigned int, len, sizeof(pwr)) ;
if ( F_41 ( V_85 , ( char * ) & V_126 , V_17 ) )
V_18 = - V_92 ;
break;
case V_139 :
if ( F_43 ( V_14 -> V_140 , ( T_4 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_141 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_25 != V_52 ) {
V_18 = - V_80 ;
break;
}
if ( F_43 ( V_14 -> V_95 , ( T_1 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
case V_142 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( F_43 ( V_14 -> V_94 , ( T_1 T_3 * ) V_85 ) )
V_18 = - V_92 ;
break;
default:
V_18 = - V_121 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static bool F_46 ( struct V_13 * V_14 , T_1 V_143 )
{
switch ( V_14 -> V_50 ) {
case V_24 :
if ( V_143 < V_144 )
return false ;
break;
default:
if ( V_143 < V_145 )
return false ;
}
return true ;
}
static int F_47 ( struct V_1 * V_2 , int V_84 ,
char T_3 * V_85 , unsigned int V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_87 V_88 ;
int V_17 , V_18 = 0 ;
T_4 V_91 ;
F_7 ( L_1 , V_12 ) ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_93 :
if ( F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_25 == V_52 ) {
V_18 = - V_6 ;
break;
}
V_88 . V_94 = V_14 -> V_94 ;
V_88 . V_95 = V_14 -> V_95 ;
V_88 . V_96 = V_14 -> V_96 ;
V_88 . V_45 = V_14 -> V_45 ;
V_88 . V_97 = V_14 -> V_97 ;
V_88 . V_98 = V_14 -> V_98 ;
V_88 . V_99 = V_14 -> V_100 ;
V_17 = F_8 (unsigned int, sizeof(opts), optlen) ;
if ( F_48 ( ( char * ) & V_88 , V_85 , V_17 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_88 . V_99 > V_146 ) {
V_18 = - V_6 ;
break;
}
if ( ! F_46 ( V_14 , V_88 . V_94 ) ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_45 = V_88 . V_45 ;
switch ( V_14 -> V_45 ) {
case V_46 :
break;
case V_58 :
F_49 ( V_147 , & V_14 -> V_148 ) ;
break;
case V_59 :
case V_60 :
if ( ! V_61 )
break;
default:
V_18 = - V_6 ;
break;
}
V_14 -> V_94 = V_88 . V_94 ;
V_14 -> V_95 = V_88 . V_95 ;
V_14 -> V_97 = V_88 . V_97 ;
V_14 -> V_98 = V_88 . V_98 ;
V_14 -> V_100 = V_88 . V_99 ;
V_14 -> V_96 = V_88 . V_96 ;
break;
case V_101 :
if ( F_40 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 & V_109 ) {
V_18 = - V_6 ;
break;
}
if ( V_91 & V_103 )
V_14 -> V_34 = V_102 ;
if ( V_91 & V_105 )
V_14 -> V_34 = V_104 ;
if ( V_91 & V_107 )
V_14 -> V_34 = V_106 ;
if ( V_91 & V_111 )
F_16 ( V_110 , & V_14 -> V_42 ) ;
else
F_49 ( V_110 , & V_14 -> V_42 ) ;
if ( V_91 & V_113 )
F_16 ( V_112 , & V_14 -> V_42 ) ;
else
F_49 ( V_112 , & V_14 -> V_42 ) ;
break;
default:
V_18 = - V_121 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_50 ( struct V_1 * V_2 , int V_122 , int V_84 ,
char T_3 * V_85 , unsigned int V_86 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
struct V_123 V_124 ;
struct V_125 V_126 ;
struct V_149 * V_117 ;
int V_17 , V_18 = 0 ;
T_4 V_91 ;
F_7 ( L_1 , V_12 ) ;
if ( V_122 == V_127 )
return F_47 ( V_2 , V_84 , V_85 , V_86 ) ;
if ( V_122 != V_128 )
return - V_121 ;
F_12 ( V_12 ) ;
switch ( V_84 ) {
case V_129 :
if ( V_14 -> V_31 != V_36 &&
V_14 -> V_31 != V_40 &&
V_14 -> V_31 != V_39 ) {
V_18 = - V_6 ;
break;
}
V_124 . V_122 = V_102 ;
V_17 = F_8 (unsigned int, sizeof(sec), optlen) ;
if ( F_48 ( ( char * ) & V_124 , V_85 , V_17 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_124 . V_122 < V_102 ||
V_124 . V_122 > V_106 ) {
V_18 = - V_6 ;
break;
}
V_14 -> V_34 = V_124 . V_122 ;
if ( ! V_14 -> V_117 )
break;
V_117 = V_14 -> V_117 ;
if ( V_14 -> V_50 == V_24 ) {
if ( F_51 ( V_117 -> V_118 , V_124 . V_122 ) )
break;
F_16 ( V_150 , & V_14 -> V_42 ) ;
V_12 -> V_25 = V_79 ;
V_14 -> V_47 = V_79 ;
} else if ( ( V_12 -> V_25 == V_78 &&
F_42 ( V_115 , & F_44 ( V_12 ) -> V_42 ) ) ||
V_12 -> V_25 == V_52 ) {
if ( ! F_52 ( V_14 , true ) )
F_16 ( V_151 , & F_44 ( V_12 ) -> V_42 ) ;
else
V_12 -> V_152 ( V_12 ) ;
} else {
V_18 = - V_6 ;
}
break;
case V_132 :
if ( V_12 -> V_25 != V_48 && V_12 -> V_25 != V_65 ) {
V_18 = - V_6 ;
break;
}
if ( F_40 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 ) {
F_16 ( V_115 , & F_44 ( V_12 ) -> V_42 ) ;
F_16 ( V_153 , & V_14 -> V_42 ) ;
} else {
F_49 ( V_115 , & F_44 ( V_12 ) -> V_42 ) ;
F_49 ( V_153 , & V_14 -> V_42 ) ;
}
break;
case V_133 :
if ( F_40 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 > V_154 ) {
V_18 = - V_6 ;
break;
}
if ( V_91 == V_155 ) {
V_117 = V_14 -> V_117 ;
if ( ! V_117 || ! F_53 ( V_117 -> V_118 -> V_156 ) ) {
V_18 = - V_6 ;
break;
}
}
if ( V_91 )
F_16 ( V_134 , & V_14 -> V_42 ) ;
else
F_49 ( V_134 , & V_14 -> V_42 ) ;
break;
case V_135 :
if ( V_14 -> V_31 != V_36 &&
V_14 -> V_31 != V_39 ) {
V_18 = - V_6 ;
break;
}
V_126 . V_137 = V_157 ;
V_17 = F_8 (unsigned int, sizeof(pwr), optlen) ;
if ( F_48 ( ( char * ) & V_126 , V_85 , V_17 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_126 . V_137 )
F_16 ( V_138 , & V_14 -> V_42 ) ;
else
F_49 ( V_138 , & V_14 -> V_42 ) ;
break;
case V_139 :
if ( F_40 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
if ( V_91 > V_158 ) {
V_18 = - V_6 ;
break;
}
if ( V_14 -> V_45 != V_59 &&
V_14 -> V_45 != V_60 ) {
V_18 = - V_62 ;
break;
}
V_14 -> V_140 = ( V_159 ) V_91 ;
if ( V_12 -> V_25 == V_52 &&
V_14 -> V_160 == V_161 )
F_54 ( V_14 ) ;
break;
case V_141 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
V_18 = - V_162 ;
break;
case V_142 :
if ( ! F_10 ( V_14 -> V_44 ) ) {
V_18 = - V_6 ;
break;
}
if ( V_12 -> V_25 == V_52 ) {
V_18 = - V_163 ;
break;
}
if ( F_40 ( V_91 , ( T_4 T_3 * ) V_85 ) ) {
V_18 = - V_92 ;
break;
}
V_14 -> V_94 = V_91 ;
break;
default:
V_18 = - V_121 ;
break;
}
F_18 ( V_12 ) ;
return V_18 ;
}
static int F_55 ( struct V_164 * V_165 , struct V_1 * V_2 ,
struct V_166 * V_167 , T_5 V_17 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
V_18 = F_56 ( V_12 ) ;
if ( V_18 )
return V_18 ;
if ( V_167 -> V_168 & V_169 )
return - V_62 ;
if ( V_12 -> V_25 != V_52 )
return - V_80 ;
F_12 ( V_12 ) ;
V_18 = F_57 ( V_12 , V_167 -> V_168 ) ;
F_18 ( V_12 ) ;
if ( V_18 )
return V_18 ;
F_58 ( V_14 ) ;
V_18 = F_59 ( V_14 , V_167 , V_17 ) ;
F_60 ( V_14 ) ;
return V_18 ;
}
static int F_61 ( struct V_164 * V_165 , struct V_1 * V_2 ,
struct V_166 * V_167 , T_5 V_17 , int V_42 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_170 * V_171 = F_6 ( V_12 ) ;
int V_18 ;
F_12 ( V_12 ) ;
if ( V_12 -> V_25 == V_78 && F_42 ( V_115 ,
& F_44 ( V_12 ) -> V_42 ) ) {
if ( F_10 ( V_171 -> V_14 -> V_44 ) ) {
V_12 -> V_25 = V_52 ;
V_171 -> V_14 -> V_47 = V_52 ;
F_62 ( V_171 -> V_14 ) ;
} else {
V_12 -> V_25 = V_79 ;
V_171 -> V_14 -> V_47 = V_79 ;
F_63 ( V_171 -> V_14 ) ;
}
V_18 = 0 ;
goto V_28;
}
F_18 ( V_12 ) ;
if ( V_2 -> type == V_57 )
V_18 = F_64 ( V_165 , V_2 , V_167 , V_17 , V_42 ) ;
else
V_18 = F_65 ( V_165 , V_2 , V_167 , V_17 , V_42 ) ;
if ( V_171 -> V_14 -> V_45 != V_59 )
return V_18 ;
F_12 ( V_12 ) ;
if ( ! F_42 ( V_172 , & V_171 -> V_14 -> V_173 ) )
goto V_28;
if ( V_171 -> V_174 ) {
if ( ! F_66 ( V_12 , V_171 -> V_174 ) )
V_171 -> V_174 = NULL ;
else
goto V_28;
}
if ( F_67 ( & V_12 -> V_175 ) <= V_12 -> V_176 >> 1 )
F_68 ( V_171 -> V_14 , 0 ) ;
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static void F_69 ( struct V_2 * V_12 )
{
if ( ! F_70 ( V_12 , V_177 ) || V_12 -> V_178 )
return;
F_7 ( L_6 , V_12 , F_71 ( V_12 -> V_25 ) ) ;
F_72 ( F_6 ( V_12 ) -> V_14 ) ;
F_73 ( V_12 , V_179 ) ;
F_74 ( V_12 ) ;
}
static int F_75 ( struct V_2 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_26 ( V_67 , V_68 ) ;
int V_18 = 0 ;
int V_70 = V_180 / 5 ;
F_76 ( F_30 ( V_12 ) , & V_67 ) ;
F_31 ( V_72 ) ;
while ( V_14 -> V_181 > 0 && V_14 -> V_117 ) {
if ( ! V_70 )
V_70 = V_180 / 5 ;
if ( F_33 ( V_68 ) ) {
V_18 = F_34 ( V_70 ) ;
break;
}
F_18 ( V_12 ) ;
V_70 = F_35 ( V_70 ) ;
F_12 ( V_12 ) ;
F_31 ( V_72 ) ;
V_18 = F_56 ( V_12 ) ;
if ( V_18 )
break;
}
F_31 ( V_74 ) ;
F_37 ( F_30 ( V_12 ) , & V_67 ) ;
return V_18 ;
}
static int F_77 ( struct V_1 * V_2 , int V_182 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
struct V_13 * V_14 ;
struct V_149 * V_117 ;
int V_18 = 0 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
V_14 = F_6 ( V_12 ) -> V_14 ;
V_117 = V_14 -> V_117 ;
if ( V_117 )
F_78 ( & V_117 -> V_183 ) ;
F_58 ( V_14 ) ;
F_12 ( V_12 ) ;
if ( ! V_12 -> V_184 ) {
if ( V_14 -> V_45 == V_59 )
V_18 = F_75 ( V_12 ) ;
V_12 -> V_184 = V_185 ;
F_18 ( V_12 ) ;
F_79 ( V_14 , 0 ) ;
F_12 ( V_12 ) ;
if ( F_70 ( V_12 , V_186 ) && V_12 -> V_187 &&
! ( V_68 -> V_42 & V_188 ) )
V_18 = F_22 ( V_12 , V_189 ,
V_12 -> V_187 ) ;
}
if ( ! V_18 && V_12 -> V_190 )
V_18 = - V_12 -> V_190 ;
F_18 ( V_12 ) ;
F_60 ( V_14 ) ;
if ( V_117 )
F_80 ( & V_117 -> V_183 ) ;
return V_18 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_2 * V_12 = V_2 -> V_12 ;
int V_18 ;
F_7 ( L_5 , V_2 , V_12 ) ;
if ( ! V_12 )
return 0 ;
F_82 ( & V_191 , V_12 ) ;
V_18 = F_77 ( V_2 , 2 ) ;
F_83 ( V_12 ) ;
F_69 ( V_12 ) ;
return V_18 ;
}
static void F_84 ( struct V_2 * V_192 )
{
struct V_2 * V_12 ;
F_7 ( L_7 , V_192 ) ;
while ( ( V_12 = F_32 ( V_192 , NULL ) ) ) {
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_58 ( V_14 ) ;
F_85 ( V_14 ) ;
F_79 ( V_14 , V_193 ) ;
F_60 ( V_14 ) ;
F_69 ( V_12 ) ;
}
}
static struct V_13 * F_86 ( struct V_13 * V_14 )
{
struct V_2 * V_12 , * V_192 = V_14 -> V_194 ;
F_12 ( V_192 ) ;
if ( F_87 ( V_192 ) ) {
F_7 ( L_8 , V_192 -> V_64 ) ;
F_18 ( V_192 ) ;
return NULL ;
}
V_12 = F_88 ( F_89 ( V_192 ) , NULL , V_195 ,
V_196 ) ;
if ( ! V_12 ) {
F_18 ( V_192 ) ;
return NULL ;
}
F_90 ( V_12 , V_195 ) ;
F_91 ( V_12 , V_192 ) ;
F_92 ( V_192 , V_12 ) ;
F_18 ( V_192 ) ;
return F_6 ( V_12 ) -> V_14 ;
}
static int F_93 ( struct V_13 * V_14 , struct V_197 * V_198 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
int V_18 ;
F_12 ( V_12 ) ;
if ( F_6 ( V_12 ) -> V_174 ) {
V_18 = - V_199 ;
goto V_28;
}
V_18 = F_66 ( V_12 , V_198 ) ;
if ( V_18 < 0 && V_14 -> V_45 == V_59 ) {
F_6 ( V_12 ) -> V_174 = V_198 ;
F_68 ( V_14 , 1 ) ;
V_18 = 0 ;
}
V_28:
F_18 ( V_12 ) ;
return V_18 ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
F_69 ( V_12 ) ;
}
static void F_95 ( struct V_13 * V_14 , int V_18 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
struct V_2 * V_192 ;
F_12 ( V_12 ) ;
V_192 = F_44 ( V_12 ) -> V_192 ;
F_73 ( V_12 , V_177 ) ;
switch ( V_14 -> V_47 ) {
case V_26 :
case V_48 :
case V_189 :
break;
case V_65 :
F_84 ( V_12 ) ;
V_12 -> V_25 = V_189 ;
V_14 -> V_47 = V_189 ;
break;
default:
V_12 -> V_25 = V_189 ;
V_14 -> V_47 = V_189 ;
V_12 -> V_190 = V_18 ;
if ( V_192 ) {
F_96 ( V_12 ) ;
V_192 -> V_200 ( V_192 ) ;
} else {
V_12 -> V_152 ( V_12 ) ;
}
break;
}
F_18 ( V_12 ) ;
}
static void F_97 ( struct V_13 * V_14 , int V_47 ,
int V_18 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
V_12 -> V_25 = V_47 ;
if ( V_18 )
V_12 -> V_190 = V_18 ;
}
static struct V_197 * F_98 ( struct V_13 * V_14 ,
unsigned long V_201 ,
unsigned long V_17 , int V_202 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
struct V_197 * V_198 ;
int V_18 ;
F_60 ( V_14 ) ;
V_198 = F_99 ( V_12 , V_201 + V_17 , V_202 , & V_18 ) ;
F_58 ( V_14 ) ;
if ( ! V_198 )
return F_100 ( V_18 ) ;
V_198 -> V_203 = V_12 -> V_204 ;
F_101 ( V_198 ) -> V_14 = V_14 ;
return V_198 ;
}
static int F_102 ( struct V_13 * V_14 ,
unsigned char * V_205 ,
struct V_206 * V_207 , int V_17 )
{
return F_103 ( V_205 , V_207 , V_17 ) ;
}
static void F_104 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
struct V_2 * V_192 ;
F_12 ( V_12 ) ;
V_192 = F_44 ( V_12 ) -> V_192 ;
F_7 ( L_9 , V_12 , V_192 ) ;
V_12 -> V_25 = V_52 ;
V_12 -> V_152 ( V_12 ) ;
if ( V_192 )
V_192 -> V_200 ( V_192 ) ;
F_18 ( V_12 ) ;
}
static void F_105 ( struct V_13 * V_14 )
{
struct V_2 * V_192 , * V_12 = V_14 -> V_194 ;
F_12 ( V_12 ) ;
V_192 = F_44 ( V_12 ) -> V_192 ;
if ( V_192 )
V_192 -> V_200 ( V_192 ) ;
F_18 ( V_12 ) ;
}
static void F_106 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
if ( F_107 ( V_150 , & V_14 -> V_42 ) ) {
V_12 -> V_25 = V_52 ;
V_14 -> V_47 = V_52 ;
}
F_49 ( V_151 , & F_44 ( V_12 ) -> V_42 ) ;
V_12 -> V_152 ( V_12 ) ;
}
static void F_108 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
F_12 ( V_12 ) ;
V_12 -> V_184 = V_185 ;
F_18 ( V_12 ) ;
}
static long F_109 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
return V_12 -> V_208 ;
}
static void F_110 ( struct V_13 * V_14 )
{
struct V_2 * V_12 = V_14 -> V_194 ;
F_16 ( V_151 , & F_44 ( V_12 ) -> V_42 ) ;
V_12 -> V_152 ( V_12 ) ;
}
static void F_111 ( struct V_2 * V_12 )
{
F_7 ( L_1 , V_12 ) ;
if ( F_6 ( V_12 ) -> V_14 )
F_72 ( F_6 ( V_12 ) -> V_14 ) ;
if ( F_6 ( V_12 ) -> V_174 ) {
F_112 ( F_6 ( V_12 ) -> V_174 ) ;
F_6 ( V_12 ) -> V_174 = NULL ;
}
F_113 ( & V_12 -> V_209 ) ;
F_113 ( & V_12 -> V_210 ) ;
}
static void F_114 ( struct V_197 * V_198 , void * V_211 ,
int * V_212 )
{
F_115 ( struct V_15 * , V_16 , V_211 ) ;
memset ( V_16 , 0 , sizeof( struct V_15 ) ) ;
V_16 -> V_213 = V_20 ;
V_16 -> V_22 = F_101 ( V_198 ) -> V_5 ;
F_17 ( & V_16 -> V_30 , & F_101 ( V_198 ) -> V_214 ) ;
* V_212 = sizeof( struct V_15 ) ;
}
static void F_91 ( struct V_2 * V_12 , struct V_2 * V_192 )
{
struct V_13 * V_14 = F_6 ( V_12 ) -> V_14 ;
F_7 ( L_1 , V_12 ) ;
if ( V_192 ) {
struct V_13 * V_215 = F_6 ( V_192 ) -> V_14 ;
V_12 -> V_55 = V_192 -> V_55 ;
F_44 ( V_12 ) -> V_42 = F_44 ( V_192 ) -> V_42 ;
V_14 -> V_31 = V_215 -> V_31 ;
V_14 -> V_94 = V_215 -> V_94 ;
V_14 -> V_95 = V_215 -> V_95 ;
V_14 -> V_148 = V_215 -> V_148 ;
V_14 -> V_45 = V_215 -> V_45 ;
V_14 -> V_97 = V_215 -> V_97 ;
V_14 -> V_98 = V_215 -> V_98 ;
V_14 -> V_100 = V_215 -> V_100 ;
V_14 -> V_216 = V_215 -> V_216 ;
V_14 -> V_34 = V_215 -> V_34 ;
V_14 -> V_42 = V_215 -> V_42 ;
V_14 -> V_217 = V_215 -> V_217 ;
V_14 -> V_218 = V_215 -> V_218 ;
if ( V_14 -> V_31 == V_40 ) {
V_14 -> V_50 = V_215 -> V_50 ;
V_14 -> V_82 = V_215 -> V_50 ;
}
F_116 ( V_192 , V_12 ) ;
} else {
switch ( V_12 -> V_55 ) {
case V_136 :
V_14 -> V_31 = V_39 ;
break;
case V_219 :
V_14 -> V_31 = V_32 ;
F_44 ( V_12 ) -> V_220 = F_114 ;
break;
case V_56 :
case V_57 :
V_14 -> V_31 = V_36 ;
break;
}
V_14 -> V_94 = V_221 ;
V_14 -> V_95 = 0 ;
if ( ! V_61 && V_12 -> V_55 == V_57 ) {
V_14 -> V_45 = V_59 ;
F_16 ( V_147 , & V_14 -> V_148 ) ;
} else {
V_14 -> V_45 = V_58 ;
}
F_117 ( V_14 ) ;
}
V_14 -> V_96 = V_222 ;
V_14 -> V_194 = V_12 ;
V_14 -> V_3 = & V_223 ;
}
static struct V_2 * F_88 ( struct V_224 * V_224 , struct V_1 * V_2 ,
int V_225 , T_6 V_226 )
{
struct V_2 * V_12 ;
struct V_13 * V_14 ;
V_12 = F_118 ( V_224 , V_227 , V_226 , & V_228 ) ;
if ( ! V_12 )
return NULL ;
F_119 ( V_2 , V_12 ) ;
F_120 ( & F_44 ( V_12 ) -> V_229 ) ;
V_12 -> V_230 = F_111 ;
V_12 -> V_208 = V_231 ;
F_121 ( V_12 , V_177 ) ;
V_12 -> V_232 = V_225 ;
V_12 -> V_25 = V_26 ;
V_14 = F_122 () ;
if ( ! V_14 ) {
F_123 ( V_12 ) ;
return NULL ;
}
F_124 ( V_14 ) ;
F_6 ( V_12 ) -> V_14 = V_14 ;
return V_12 ;
}
static int F_125 ( struct V_224 * V_224 , struct V_1 * V_2 , int V_233 ,
int V_234 )
{
struct V_2 * V_12 ;
F_7 ( L_10 , V_2 ) ;
V_2 -> V_47 = V_235 ;
if ( V_2 -> type != V_56 && V_2 -> type != V_57 &&
V_2 -> type != V_219 && V_2 -> type != V_136 )
return - V_236 ;
if ( V_2 -> type == V_136 && ! V_234 && ! F_3 ( V_237 ) )
return - V_162 ;
V_2 -> V_3 = & V_4 ;
V_12 = F_88 ( V_224 , V_2 , V_233 , V_196 ) ;
if ( ! V_12 )
return - V_199 ;
F_91 ( V_12 , NULL ) ;
F_126 ( & V_191 , V_12 ) ;
return 0 ;
}
int T_7 F_127 ( void )
{
int V_18 ;
V_18 = F_128 ( & V_228 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_129 ( V_195 , & V_238 ) ;
if ( V_18 < 0 ) {
F_130 ( L_11 ) ;
goto error;
}
V_18 = F_131 ( & V_239 , L_12 , & V_191 ,
NULL ) ;
if ( V_18 < 0 ) {
F_130 ( L_13 ) ;
F_132 ( V_195 ) ;
goto error;
}
F_133 ( L_14 ) ;
return 0 ;
error:
F_134 ( & V_228 ) ;
return V_18 ;
}
void F_135 ( void )
{
F_136 ( & V_239 , L_12 ) ;
F_132 ( V_195 ) ;
F_134 ( & V_228 ) ;
}
