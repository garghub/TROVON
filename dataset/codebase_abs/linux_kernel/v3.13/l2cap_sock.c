bool F_1 ( struct V_1 * V_2 )
{
return V_2 && V_2 -> V_3 == & V_4 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_5 * V_6 , int V_7 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_11 V_12 ;
int V_13 , V_14 = 0 ;
F_4 ( L_1 , V_8 ) ;
if ( ! V_6 || V_6 -> V_15 != V_16 )
return - V_17 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_13 = F_5 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_12 , V_6 , V_13 ) ;
if ( V_12 . V_18 && V_12 . V_19 )
return - V_17 ;
if ( ! F_6 ( V_12 . V_20 ) )
return - V_17 ;
if ( F_7 ( V_12 . V_20 ) ) {
if ( V_12 . V_19 )
return - V_17 ;
if ( V_12 . V_18 != F_8 ( V_21 ) )
return - V_17 ;
}
F_9 ( V_8 ) ;
if ( V_8 -> V_22 != V_23 ) {
V_14 = - V_24 ;
goto V_25;
}
if ( V_12 . V_19 ) {
T_1 V_26 = F_10 ( V_12 . V_19 ) ;
if ( ( V_26 & 0x0101 ) != 0x0001 ) {
V_14 = - V_17 ;
goto V_25;
}
if ( V_26 < 0x1001 && ! F_11 ( V_27 ) ) {
V_14 = - V_28 ;
goto V_25;
}
}
if ( V_12 . V_18 )
V_14 = F_12 ( V_10 , F_10 ( V_12 . V_18 ) ) ;
else
V_14 = F_13 ( V_10 , & V_12 . V_29 , V_12 . V_19 ) ;
if ( V_14 < 0 )
goto V_25;
switch ( V_10 -> V_30 ) {
case V_31 :
if ( F_10 ( V_12 . V_19 ) == V_32 )
V_10 -> V_33 = V_34 ;
break;
case V_35 :
if ( F_10 ( V_12 . V_19 ) == V_36 ||
F_10 ( V_12 . V_19 ) == V_37 )
V_10 -> V_33 = V_34 ;
break;
}
F_14 ( & V_10 -> V_38 , & V_12 . V_29 ) ;
V_10 -> V_39 = V_12 . V_20 ;
V_10 -> V_40 = V_41 ;
V_8 -> V_22 = V_41 ;
V_25:
F_15 ( V_8 ) ;
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_7 , int V_42 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_11 V_12 ;
int V_13 , V_14 = 0 ;
F_4 ( L_1 , V_8 ) ;
if ( ! V_6 || V_7 < sizeof( V_6 -> V_15 ) ||
V_6 -> V_15 != V_16 )
return - V_17 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_13 = F_5 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_12 , V_6 , V_13 ) ;
if ( V_12 . V_18 && V_12 . V_19 )
return - V_17 ;
if ( ! F_6 ( V_12 . V_20 ) )
return - V_17 ;
if ( V_10 -> V_39 == V_43 && F_17 ( & V_10 -> V_38 , V_44 ) &&
F_7 ( V_12 . V_20 ) ) {
if ( V_10 -> V_45 != V_21 ||
V_12 . V_18 != F_8 ( V_21 ) )
return - V_17 ;
V_10 -> V_39 = V_46 ;
}
if ( V_10 -> V_39 != V_43 && V_12 . V_20 == V_43 )
return - V_17 ;
if ( F_7 ( V_12 . V_20 ) ) {
if ( V_12 . V_19 )
return - V_17 ;
if ( V_12 . V_18 != F_8 ( V_21 ) )
return - V_17 ;
}
V_14 = F_18 ( V_10 , V_12 . V_19 , F_10 ( V_12 . V_18 ) ,
& V_12 . V_29 , V_12 . V_20 ) ;
if ( V_14 )
return V_14 ;
F_9 ( V_8 ) ;
V_14 = F_19 ( V_8 , V_47 ,
F_20 ( V_8 , V_42 & V_48 ) ) ;
F_15 ( V_8 ) ;
return V_14 ;
}
static int F_21 ( struct V_1 * V_2 , int V_49 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
int V_14 = 0 ;
F_4 ( L_2 , V_8 , V_49 ) ;
F_9 ( V_8 ) ;
if ( V_8 -> V_22 != V_41 ) {
V_14 = - V_24 ;
goto V_25;
}
if ( V_8 -> V_50 != V_51 && V_8 -> V_50 != V_52 ) {
V_14 = - V_17 ;
goto V_25;
}
switch ( V_10 -> V_53 ) {
case V_54 :
break;
case V_55 :
case V_56 :
if ( ! V_57 )
break;
default:
V_14 = - V_58 ;
goto V_25;
}
V_8 -> V_59 = V_49 ;
V_8 -> V_60 = 0 ;
V_10 -> V_40 = V_61 ;
V_8 -> V_22 = V_61 ;
V_25:
F_15 ( V_8 ) ;
return V_14 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_1 * V_62 ,
int V_42 )
{
F_23 ( V_63 , V_64 ) ;
struct V_2 * V_8 = V_2 -> V_8 , * V_65 ;
long V_66 ;
int V_14 = 0 ;
F_24 ( V_8 , V_67 ) ;
V_66 = F_25 ( V_8 , V_42 & V_48 ) ;
F_4 ( L_3 , V_8 , V_66 ) ;
F_26 ( F_27 ( V_8 ) , & V_63 ) ;
while ( 1 ) {
F_28 ( V_68 ) ;
if ( V_8 -> V_22 != V_61 ) {
V_14 = - V_24 ;
break;
}
V_65 = F_29 ( V_8 , V_62 ) ;
if ( V_65 )
break;
if ( ! V_66 ) {
V_14 = - V_69 ;
break;
}
if ( F_30 ( V_64 ) ) {
V_14 = F_31 ( V_66 ) ;
break;
}
F_15 ( V_8 ) ;
V_66 = F_32 ( V_66 ) ;
F_24 ( V_8 , V_67 ) ;
}
F_33 ( V_70 ) ;
F_34 ( F_27 ( V_8 ) , & V_63 ) ;
if ( V_14 )
goto V_25;
V_62 -> V_40 = V_71 ;
F_4 ( L_4 , V_65 ) ;
V_25:
F_15 ( V_8 ) ;
return V_14 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_13 , int V_72 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
F_4 ( L_5 , V_2 , V_8 ) ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
V_6 -> V_15 = V_16 ;
* V_13 = sizeof( struct V_11 ) ;
if ( V_72 ) {
V_12 -> V_19 = V_10 -> V_26 ;
F_14 ( & V_12 -> V_29 , & V_10 -> V_73 ) ;
V_12 -> V_18 = F_36 ( V_10 -> V_74 ) ;
V_12 -> V_20 = V_10 -> V_75 ;
} else {
V_12 -> V_19 = V_10 -> V_76 ;
F_14 ( & V_12 -> V_29 , & V_10 -> V_38 ) ;
V_12 -> V_18 = F_36 ( V_10 -> V_45 ) ;
V_12 -> V_20 = V_10 -> V_39 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , int V_77 ,
char T_2 * V_78 , int T_2 * V_79 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_80 V_81 ;
struct V_82 V_83 ;
int V_13 , V_14 = 0 ;
T_3 V_84 ;
F_4 ( L_1 , V_8 ) ;
if ( F_38 ( V_13 , V_79 ) )
return - V_85 ;
F_9 ( V_8 ) ;
switch ( V_77 ) {
case V_86 :
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_87 = V_10 -> V_87 ;
V_81 . V_88 = V_10 -> V_88 ;
V_81 . V_89 = V_10 -> V_89 ;
V_81 . V_53 = V_10 -> V_53 ;
V_81 . V_90 = V_10 -> V_90 ;
V_81 . V_91 = V_10 -> V_91 ;
V_81 . V_92 = V_10 -> V_93 ;
V_13 = F_5 (unsigned int, len, sizeof(opts)) ;
if ( F_39 ( V_78 , ( char * ) & V_81 , V_13 ) )
V_14 = - V_85 ;
break;
case V_94 :
switch ( V_10 -> V_33 ) {
case V_95 :
V_84 = V_96 ;
break;
case V_97 :
V_84 = V_96 | V_98 ;
break;
case V_99 :
V_84 = V_96 | V_98 |
V_100 ;
break;
default:
V_84 = 0 ;
break;
}
if ( F_40 ( V_101 , & V_10 -> V_42 ) )
V_84 |= V_102 ;
if ( F_40 ( V_103 , & V_10 -> V_42 ) )
V_84 |= V_104 ;
if ( F_41 ( V_84 , ( T_3 T_2 * ) V_78 ) )
V_14 = - V_85 ;
break;
case V_105 :
if ( V_8 -> V_22 != V_47 &&
! ( V_8 -> V_22 == V_106 &&
F_40 ( V_107 , & F_42 ( V_8 ) -> V_42 ) ) ) {
V_14 = - V_108 ;
break;
}
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_109 = V_10 -> V_110 -> V_111 -> V_112 ;
memcpy ( V_83 . V_113 , V_10 -> V_110 -> V_111 -> V_113 , 3 ) ;
V_13 = F_5 (unsigned int, len, sizeof(cinfo)) ;
if ( F_39 ( V_78 , ( char * ) & V_83 , V_13 ) )
V_14 = - V_85 ;
break;
default:
V_14 = - V_114 ;
break;
}
F_15 ( V_8 ) ;
return V_14 ;
}
static int F_43 ( struct V_1 * V_2 , int V_115 , int V_77 ,
char T_2 * V_78 , int T_2 * V_79 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_116 V_117 ;
struct V_118 V_119 ;
int V_13 , V_14 = 0 ;
F_4 ( L_1 , V_8 ) ;
if ( V_115 == V_120 )
return F_37 ( V_2 , V_77 , V_78 , V_79 ) ;
if ( V_115 != V_121 )
return - V_114 ;
if ( F_38 ( V_13 , V_79 ) )
return - V_85 ;
F_9 ( V_8 ) ;
switch ( V_77 ) {
case V_122 :
if ( V_10 -> V_30 != V_35 &&
V_10 -> V_30 != V_123 ) {
V_14 = - V_17 ;
break;
}
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
if ( V_10 -> V_110 ) {
V_117 . V_115 = V_10 -> V_110 -> V_111 -> V_33 ;
if ( V_8 -> V_22 == V_47 )
V_117 . V_124 = V_10 -> V_110 -> V_111 -> V_125 ;
} else {
V_117 . V_115 = V_10 -> V_33 ;
}
V_13 = F_5 (unsigned int, len, sizeof(sec)) ;
if ( F_39 ( V_78 , ( char * ) & V_117 , V_13 ) )
V_14 = - V_85 ;
break;
case V_126 :
if ( V_8 -> V_22 != V_41 && V_8 -> V_22 != V_61 ) {
V_14 = - V_17 ;
break;
}
if ( F_41 ( F_40 ( V_107 , & F_42 ( V_8 ) -> V_42 ) ,
( T_3 T_2 * ) V_78 ) )
V_14 = - V_85 ;
break;
case V_127 :
if ( F_41 ( F_40 ( V_128 , & V_10 -> V_42 ) ,
( T_3 T_2 * ) V_78 ) )
V_14 = - V_85 ;
break;
case V_129 :
if ( V_8 -> V_50 != V_51 && V_8 -> V_50 != V_52
&& V_8 -> V_50 != V_130 ) {
V_14 = - V_17 ;
break;
}
V_119 . V_131 = F_40 ( V_132 , & V_10 -> V_42 ) ;
V_13 = F_5 (unsigned int, len, sizeof(pwr)) ;
if ( F_39 ( V_78 , ( char * ) & V_119 , V_13 ) )
V_14 = - V_85 ;
break;
case V_133 :
if ( F_41 ( V_10 -> V_134 , ( T_3 T_2 * ) V_78 ) )
V_14 = - V_85 ;
break;
default:
V_14 = - V_114 ;
break;
}
F_15 ( V_8 ) ;
return V_14 ;
}
static bool F_44 ( struct V_9 * V_10 , T_4 V_135 )
{
switch ( V_10 -> V_45 ) {
case V_21 :
if ( V_135 < V_136 )
return false ;
break;
default:
if ( V_135 < V_137 )
return false ;
}
return true ;
}
static int F_45 ( struct V_1 * V_2 , int V_77 ,
char T_2 * V_78 , unsigned int V_79 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_80 V_81 ;
int V_13 , V_14 = 0 ;
T_3 V_84 ;
F_4 ( L_1 , V_8 ) ;
F_9 ( V_8 ) ;
switch ( V_77 ) {
case V_86 :
if ( V_8 -> V_22 == V_47 ) {
V_14 = - V_17 ;
break;
}
V_81 . V_87 = V_10 -> V_87 ;
V_81 . V_88 = V_10 -> V_88 ;
V_81 . V_89 = V_10 -> V_89 ;
V_81 . V_53 = V_10 -> V_53 ;
V_81 . V_90 = V_10 -> V_90 ;
V_81 . V_91 = V_10 -> V_91 ;
V_81 . V_92 = V_10 -> V_93 ;
V_13 = F_5 (unsigned int, sizeof(opts), optlen) ;
if ( F_46 ( ( char * ) & V_81 , V_78 , V_13 ) ) {
V_14 = - V_85 ;
break;
}
if ( V_81 . V_92 > V_138 ) {
V_14 = - V_17 ;
break;
}
if ( ! F_44 ( V_10 , V_81 . V_87 ) ) {
V_14 = - V_17 ;
break;
}
V_10 -> V_53 = V_81 . V_53 ;
switch ( V_10 -> V_53 ) {
case V_54 :
F_47 ( V_139 , & V_10 -> V_140 ) ;
break;
case V_55 :
case V_56 :
if ( ! V_57 )
break;
default:
V_14 = - V_17 ;
break;
}
V_10 -> V_87 = V_81 . V_87 ;
V_10 -> V_88 = V_81 . V_88 ;
V_10 -> V_90 = V_81 . V_90 ;
V_10 -> V_91 = V_81 . V_91 ;
V_10 -> V_93 = V_81 . V_92 ;
V_10 -> V_89 = V_81 . V_89 ;
break;
case V_94 :
if ( F_38 ( V_84 , ( T_3 T_2 * ) V_78 ) ) {
V_14 = - V_85 ;
break;
}
if ( V_84 & V_96 )
V_10 -> V_33 = V_95 ;
if ( V_84 & V_98 )
V_10 -> V_33 = V_97 ;
if ( V_84 & V_100 )
V_10 -> V_33 = V_99 ;
if ( V_84 & V_102 )
F_48 ( V_101 , & V_10 -> V_42 ) ;
else
F_47 ( V_101 , & V_10 -> V_42 ) ;
if ( V_84 & V_104 )
F_48 ( V_103 , & V_10 -> V_42 ) ;
else
F_47 ( V_103 , & V_10 -> V_42 ) ;
break;
default:
V_14 = - V_114 ;
break;
}
F_15 ( V_8 ) ;
return V_14 ;
}
static int F_49 ( struct V_1 * V_2 , int V_115 , int V_77 ,
char T_2 * V_78 , unsigned int V_79 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_116 V_117 ;
struct V_118 V_119 ;
struct V_141 * V_110 ;
int V_13 , V_14 = 0 ;
T_3 V_84 ;
F_4 ( L_1 , V_8 ) ;
if ( V_115 == V_120 )
return F_45 ( V_2 , V_77 , V_78 , V_79 ) ;
if ( V_115 != V_121 )
return - V_114 ;
F_9 ( V_8 ) ;
switch ( V_77 ) {
case V_122 :
if ( V_10 -> V_30 != V_35 &&
V_10 -> V_30 != V_123 ) {
V_14 = - V_17 ;
break;
}
V_117 . V_115 = V_95 ;
V_13 = F_5 (unsigned int, sizeof(sec), optlen) ;
if ( F_46 ( ( char * ) & V_117 , V_78 , V_13 ) ) {
V_14 = - V_85 ;
break;
}
if ( V_117 . V_115 < V_95 ||
V_117 . V_115 > V_99 ) {
V_14 = - V_17 ;
break;
}
V_10 -> V_33 = V_117 . V_115 ;
if ( ! V_10 -> V_110 )
break;
V_110 = V_10 -> V_110 ;
if ( V_10 -> V_45 == V_21 ) {
if ( ! V_110 -> V_111 -> V_142 ) {
V_14 = - V_17 ;
break;
}
if ( F_50 ( V_110 -> V_111 , V_117 . V_115 ) )
break;
V_8 -> V_22 = V_143 ;
V_10 -> V_40 = V_143 ;
} else if ( ( V_8 -> V_22 == V_106 &&
F_40 ( V_107 , & F_42 ( V_8 ) -> V_42 ) ) ||
V_8 -> V_22 == V_47 ) {
if ( ! F_51 ( V_10 ) )
F_48 ( V_144 , & F_42 ( V_8 ) -> V_42 ) ;
else
V_8 -> V_145 ( V_8 ) ;
} else {
V_14 = - V_17 ;
}
break;
case V_126 :
if ( V_8 -> V_22 != V_41 && V_8 -> V_22 != V_61 ) {
V_14 = - V_17 ;
break;
}
if ( F_38 ( V_84 , ( T_3 T_2 * ) V_78 ) ) {
V_14 = - V_85 ;
break;
}
if ( V_84 ) {
F_48 ( V_107 , & F_42 ( V_8 ) -> V_42 ) ;
F_48 ( V_146 , & V_10 -> V_42 ) ;
} else {
F_47 ( V_107 , & F_42 ( V_8 ) -> V_42 ) ;
F_47 ( V_146 , & V_10 -> V_42 ) ;
}
break;
case V_127 :
if ( F_38 ( V_84 , ( T_3 T_2 * ) V_78 ) ) {
V_14 = - V_85 ;
break;
}
if ( V_84 > V_147 ) {
V_14 = - V_17 ;
break;
}
if ( V_84 == V_148 ) {
V_110 = V_10 -> V_110 ;
if ( ! V_110 || ! F_52 ( V_110 -> V_111 -> V_149 ) ) {
V_14 = - V_17 ;
break;
}
}
if ( V_84 )
F_48 ( V_128 , & V_10 -> V_42 ) ;
else
F_47 ( V_128 , & V_10 -> V_42 ) ;
break;
case V_129 :
if ( V_10 -> V_30 != V_35 &&
V_10 -> V_30 != V_123 ) {
V_14 = - V_17 ;
break;
}
V_119 . V_131 = V_150 ;
V_13 = F_5 (unsigned int, sizeof(pwr), optlen) ;
if ( F_46 ( ( char * ) & V_119 , V_78 , V_13 ) ) {
V_14 = - V_85 ;
break;
}
if ( V_119 . V_131 )
F_48 ( V_132 , & V_10 -> V_42 ) ;
else
F_47 ( V_132 , & V_10 -> V_42 ) ;
break;
case V_133 :
if ( F_38 ( V_84 , ( T_3 T_2 * ) V_78 ) ) {
V_14 = - V_85 ;
break;
}
if ( V_84 > V_151 ) {
V_14 = - V_17 ;
break;
}
if ( V_10 -> V_53 != V_55 &&
V_10 -> V_53 != V_56 ) {
V_14 = - V_152 ;
break;
}
V_10 -> V_134 = ( V_153 ) V_84 ;
if ( V_8 -> V_22 == V_47 &&
V_10 -> V_154 == V_155 )
F_53 ( V_10 ) ;
break;
default:
V_14 = - V_114 ;
break;
}
F_15 ( V_8 ) ;
return V_14 ;
}
static int F_54 ( struct V_156 * V_157 , struct V_1 * V_2 ,
struct V_158 * V_159 , T_5 V_13 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
int V_14 ;
F_4 ( L_5 , V_2 , V_8 ) ;
V_14 = F_55 ( V_8 ) ;
if ( V_14 )
return V_14 ;
if ( V_159 -> V_160 & V_161 )
return - V_152 ;
if ( V_8 -> V_22 != V_47 )
return - V_108 ;
F_9 ( V_8 ) ;
V_14 = F_56 ( V_8 , V_159 -> V_160 ) ;
F_15 ( V_8 ) ;
if ( V_14 )
return V_14 ;
F_57 ( V_10 ) ;
V_14 = F_58 ( V_10 , V_159 , V_13 , V_8 -> V_162 ) ;
F_59 ( V_10 ) ;
return V_14 ;
}
static int F_60 ( struct V_156 * V_157 , struct V_1 * V_2 ,
struct V_158 * V_159 , T_5 V_13 , int V_42 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_163 * V_164 = F_3 ( V_8 ) ;
int V_14 ;
F_9 ( V_8 ) ;
if ( V_8 -> V_22 == V_106 && F_40 ( V_107 ,
& F_42 ( V_8 ) -> V_42 ) ) {
V_8 -> V_22 = V_143 ;
V_164 -> V_10 -> V_40 = V_143 ;
F_61 ( V_164 -> V_10 ) ;
V_14 = 0 ;
goto V_25;
}
F_15 ( V_8 ) ;
if ( V_2 -> type == V_52 )
V_14 = F_62 ( V_157 , V_2 , V_159 , V_13 , V_42 ) ;
else
V_14 = F_63 ( V_157 , V_2 , V_159 , V_13 , V_42 ) ;
if ( V_164 -> V_10 -> V_53 != V_55 )
return V_14 ;
F_9 ( V_8 ) ;
if ( ! F_40 ( V_165 , & V_164 -> V_10 -> V_166 ) )
goto V_25;
if ( V_164 -> V_167 ) {
if ( ! F_64 ( V_8 , V_164 -> V_167 ) )
V_164 -> V_167 = NULL ;
else
goto V_25;
}
if ( F_65 ( & V_8 -> V_168 ) <= V_8 -> V_169 >> 1 )
F_66 ( V_164 -> V_10 , 0 ) ;
V_25:
F_15 ( V_8 ) ;
return V_14 ;
}
static void F_67 ( struct V_2 * V_8 )
{
if ( ! F_68 ( V_8 , V_170 ) || V_8 -> V_171 )
return;
F_4 ( L_6 , V_8 , F_69 ( V_8 -> V_22 ) ) ;
F_70 ( F_3 ( V_8 ) -> V_10 ) ;
F_71 ( V_8 , V_172 ) ;
F_72 ( V_8 ) ;
}
static int F_73 ( struct V_2 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
F_23 ( V_63 , V_64 ) ;
int V_14 = 0 ;
int V_66 = V_173 / 5 ;
F_74 ( F_27 ( V_8 ) , & V_63 ) ;
F_28 ( V_68 ) ;
while ( V_10 -> V_174 > 0 && V_10 -> V_110 ) {
if ( ! V_66 )
V_66 = V_173 / 5 ;
if ( F_30 ( V_64 ) ) {
V_14 = F_31 ( V_66 ) ;
break;
}
F_15 ( V_8 ) ;
V_66 = F_32 ( V_66 ) ;
F_9 ( V_8 ) ;
F_28 ( V_68 ) ;
V_14 = F_55 ( V_8 ) ;
if ( V_14 )
break;
}
F_28 ( V_70 ) ;
F_34 ( F_27 ( V_8 ) , & V_63 ) ;
return V_14 ;
}
static int F_75 ( struct V_1 * V_2 , int V_175 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_141 * V_110 ;
int V_14 = 0 ;
F_4 ( L_5 , V_2 , V_8 ) ;
if ( ! V_8 )
return 0 ;
V_10 = F_3 ( V_8 ) -> V_10 ;
V_110 = V_10 -> V_110 ;
if ( V_110 )
F_76 ( & V_110 -> V_176 ) ;
F_57 ( V_10 ) ;
F_9 ( V_8 ) ;
if ( ! V_8 -> V_177 ) {
if ( V_10 -> V_53 == V_55 )
V_14 = F_73 ( V_8 ) ;
V_8 -> V_177 = V_178 ;
F_15 ( V_8 ) ;
F_77 ( V_10 , 0 ) ;
F_9 ( V_8 ) ;
if ( F_68 ( V_8 , V_179 ) && V_8 -> V_180 )
V_14 = F_19 ( V_8 , V_181 ,
V_8 -> V_180 ) ;
}
if ( ! V_14 && V_8 -> V_182 )
V_14 = - V_8 -> V_182 ;
F_15 ( V_8 ) ;
F_59 ( V_10 ) ;
if ( V_110 )
F_78 ( & V_110 -> V_176 ) ;
return V_14 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
int V_14 ;
F_4 ( L_5 , V_2 , V_8 ) ;
if ( ! V_8 )
return 0 ;
F_80 ( & V_183 , V_8 ) ;
V_14 = F_75 ( V_2 , 2 ) ;
F_81 ( V_8 ) ;
F_67 ( V_8 ) ;
return V_14 ;
}
static void F_82 ( struct V_2 * V_184 )
{
struct V_2 * V_8 ;
F_4 ( L_7 , V_184 ) ;
while ( ( V_8 = F_29 ( V_184 , NULL ) ) ) {
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
F_57 ( V_10 ) ;
F_83 ( V_10 ) ;
F_77 ( V_10 , V_185 ) ;
F_59 ( V_10 ) ;
F_67 ( V_8 ) ;
}
}
static struct V_9 * F_84 ( struct V_9 * V_10 )
{
struct V_2 * V_8 , * V_184 = V_10 -> V_186 ;
F_9 ( V_184 ) ;
if ( F_85 ( V_184 ) ) {
F_4 ( L_8 , V_184 -> V_60 ) ;
return NULL ;
}
V_8 = F_86 ( F_87 ( V_184 ) , NULL , V_187 ,
V_188 ) ;
if ( ! V_8 )
return NULL ;
F_88 ( V_8 , V_187 ) ;
F_89 ( V_8 , V_184 ) ;
F_90 ( V_184 , V_8 ) ;
F_15 ( V_184 ) ;
return F_3 ( V_8 ) -> V_10 ;
}
static int F_91 ( struct V_9 * V_10 , struct V_189 * V_190 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
int V_14 ;
F_9 ( V_8 ) ;
if ( F_3 ( V_8 ) -> V_167 ) {
V_14 = - V_191 ;
goto V_25;
}
V_14 = F_64 ( V_8 , V_190 ) ;
if ( V_14 < 0 && V_10 -> V_53 == V_55 ) {
F_3 ( V_8 ) -> V_167 = V_190 ;
F_66 ( V_10 , 1 ) ;
V_14 = 0 ;
}
V_25:
F_15 ( V_8 ) ;
return V_14 ;
}
static void F_92 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
F_67 ( V_8 ) ;
}
static void F_93 ( struct V_9 * V_10 , int V_14 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
struct V_2 * V_184 ;
F_9 ( V_8 ) ;
V_184 = F_42 ( V_8 ) -> V_184 ;
F_71 ( V_8 , V_170 ) ;
switch ( V_10 -> V_40 ) {
case V_23 :
case V_41 :
case V_181 :
break;
case V_61 :
F_82 ( V_8 ) ;
V_8 -> V_22 = V_181 ;
V_10 -> V_40 = V_181 ;
break;
default:
V_8 -> V_22 = V_181 ;
V_10 -> V_40 = V_181 ;
V_8 -> V_182 = V_14 ;
if ( V_184 ) {
F_94 ( V_8 ) ;
V_184 -> V_192 ( V_184 , 0 ) ;
} else {
V_8 -> V_145 ( V_8 ) ;
}
break;
}
F_15 ( V_8 ) ;
}
static void F_95 ( struct V_9 * V_10 , int V_40 ,
int V_14 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
V_8 -> V_22 = V_40 ;
if ( V_14 )
V_8 -> V_182 = V_14 ;
}
static struct V_189 * F_96 ( struct V_9 * V_10 ,
unsigned long V_13 , int V_193 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
struct V_189 * V_190 ;
int V_14 ;
F_59 ( V_10 ) ;
V_190 = F_97 ( V_8 , V_13 , V_193 , & V_14 ) ;
F_57 ( V_10 ) ;
if ( ! V_190 )
return F_98 ( V_14 ) ;
F_99 ( V_190 ) -> V_10 = V_10 ;
return V_190 ;
}
static void F_100 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
struct V_2 * V_184 ;
F_9 ( V_8 ) ;
V_184 = F_42 ( V_8 ) -> V_184 ;
F_4 ( L_9 , V_8 , V_184 ) ;
V_8 -> V_22 = V_47 ;
V_8 -> V_145 ( V_8 ) ;
if ( V_184 )
V_184 -> V_192 ( V_184 , 0 ) ;
F_15 ( V_8 ) ;
}
static void F_101 ( struct V_9 * V_10 )
{
struct V_2 * V_184 , * V_8 = V_10 -> V_186 ;
F_9 ( V_8 ) ;
V_184 = F_42 ( V_8 ) -> V_184 ;
if ( V_184 )
V_184 -> V_192 ( V_184 , 0 ) ;
F_15 ( V_8 ) ;
}
static void F_102 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
F_47 ( V_144 , & F_42 ( V_8 ) -> V_42 ) ;
V_8 -> V_145 ( V_8 ) ;
}
static void F_103 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
F_9 ( V_8 ) ;
V_8 -> V_177 = V_178 ;
F_15 ( V_8 ) ;
}
static long F_104 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_186 ;
return V_8 -> V_194 ;
}
static void F_105 ( struct V_2 * V_8 )
{
F_4 ( L_1 , V_8 ) ;
if ( F_3 ( V_8 ) -> V_10 )
F_70 ( F_3 ( V_8 ) -> V_10 ) ;
if ( F_3 ( V_8 ) -> V_167 ) {
F_106 ( F_3 ( V_8 ) -> V_167 ) ;
F_3 ( V_8 ) -> V_167 = NULL ;
}
F_107 ( & V_8 -> V_195 ) ;
F_107 ( & V_8 -> V_196 ) ;
}
static void F_108 ( struct V_189 * V_190 , void * V_197 ,
int * V_198 )
{
struct V_11 * V_12 = (struct V_11 * ) V_197 ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
V_12 -> V_199 = V_16 ;
V_12 -> V_19 = F_99 ( V_190 ) -> V_26 ;
F_14 ( & V_12 -> V_29 , & F_99 ( V_190 ) -> V_200 ) ;
* V_198 = sizeof( struct V_11 ) ;
}
static void F_89 ( struct V_2 * V_8 , struct V_2 * V_184 )
{
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
F_4 ( L_1 , V_8 ) ;
if ( V_184 ) {
struct V_9 * V_201 = F_3 ( V_184 ) -> V_10 ;
V_8 -> V_50 = V_184 -> V_50 ;
F_42 ( V_8 ) -> V_42 = F_42 ( V_184 ) -> V_42 ;
V_10 -> V_30 = V_201 -> V_30 ;
V_10 -> V_87 = V_201 -> V_87 ;
V_10 -> V_88 = V_201 -> V_88 ;
V_10 -> V_140 = V_201 -> V_140 ;
V_10 -> V_53 = V_201 -> V_53 ;
V_10 -> V_90 = V_201 -> V_90 ;
V_10 -> V_91 = V_201 -> V_91 ;
V_10 -> V_93 = V_201 -> V_93 ;
V_10 -> V_202 = V_201 -> V_202 ;
V_10 -> V_33 = V_201 -> V_33 ;
V_10 -> V_42 = V_201 -> V_42 ;
F_109 ( V_184 , V_8 ) ;
} else {
switch ( V_8 -> V_50 ) {
case V_130 :
V_10 -> V_30 = V_123 ;
break;
case V_203 :
V_10 -> V_30 = V_31 ;
F_42 ( V_8 ) -> V_204 = F_108 ;
break;
case V_51 :
case V_52 :
V_10 -> V_30 = V_35 ;
break;
}
V_10 -> V_87 = V_205 ;
V_10 -> V_88 = 0 ;
if ( ! V_57 && V_8 -> V_50 == V_52 ) {
V_10 -> V_53 = V_55 ;
F_48 ( V_139 , & V_10 -> V_140 ) ;
} else {
V_10 -> V_53 = V_54 ;
}
F_110 ( V_10 ) ;
}
V_10 -> V_89 = V_206 ;
V_10 -> V_186 = V_8 ;
V_10 -> V_3 = & V_207 ;
}
static struct V_2 * F_86 ( struct V_208 * V_208 , struct V_1 * V_2 ,
int V_209 , T_6 V_210 )
{
struct V_2 * V_8 ;
struct V_9 * V_10 ;
V_8 = F_111 ( V_208 , V_211 , V_210 , & V_212 ) ;
if ( ! V_8 )
return NULL ;
F_112 ( V_2 , V_8 ) ;
F_113 ( & F_42 ( V_8 ) -> V_213 ) ;
V_8 -> V_214 = F_105 ;
V_8 -> V_194 = V_215 ;
F_114 ( V_8 , V_170 ) ;
V_8 -> V_216 = V_209 ;
V_8 -> V_22 = V_23 ;
V_10 = F_115 () ;
if ( ! V_10 ) {
F_116 ( V_8 ) ;
return NULL ;
}
F_117 ( V_10 ) ;
F_3 ( V_8 ) -> V_10 = V_10 ;
return V_8 ;
}
static int F_118 ( struct V_208 * V_208 , struct V_1 * V_2 , int V_217 ,
int V_218 )
{
struct V_2 * V_8 ;
F_4 ( L_10 , V_2 ) ;
V_2 -> V_40 = V_219 ;
if ( V_2 -> type != V_51 && V_2 -> type != V_52 &&
V_2 -> type != V_203 && V_2 -> type != V_130 )
return - V_220 ;
if ( V_2 -> type == V_130 && ! V_218 && ! F_11 ( V_221 ) )
return - V_222 ;
V_2 -> V_3 = & V_4 ;
V_8 = F_86 ( V_208 , V_2 , V_217 , V_188 ) ;
if ( ! V_8 )
return - V_191 ;
F_89 ( V_8 , NULL ) ;
F_119 ( & V_183 , V_8 ) ;
return 0 ;
}
int T_7 F_120 ( void )
{
int V_14 ;
V_14 = F_121 ( & V_212 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_122 ( V_187 , & V_223 ) ;
if ( V_14 < 0 ) {
F_123 ( L_11 ) ;
goto error;
}
V_14 = F_124 ( & V_224 , L_12 , & V_183 ,
NULL ) ;
if ( V_14 < 0 ) {
F_123 ( L_13 ) ;
F_125 ( V_187 ) ;
goto error;
}
F_126 ( L_14 ) ;
return 0 ;
error:
F_127 ( & V_212 ) ;
return V_14 ;
}
void F_128 ( void )
{
F_129 ( & V_224 , L_12 ) ;
F_125 ( V_187 ) ;
F_127 ( & V_212 ) ;
}
