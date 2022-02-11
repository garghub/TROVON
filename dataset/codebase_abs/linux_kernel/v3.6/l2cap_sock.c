static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_9 V_10 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( ! V_4 || V_4 -> V_13 != V_14 )
return - V_15 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = F_4 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_10 , V_4 , V_11 ) ;
if ( V_10 . V_16 && V_10 . V_17 )
return - V_15 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 != V_19 ) {
V_12 = - V_20 ;
goto V_21;
}
if ( V_10 . V_17 ) {
T_1 V_22 = F_6 ( V_10 . V_17 ) ;
if ( ( V_22 & 0x0101 ) != 0x0001 ) {
V_12 = - V_15 ;
goto V_21;
}
if ( V_22 < 0x1001 && ! F_7 ( V_23 ) ) {
V_12 = - V_24 ;
goto V_21;
}
}
if ( V_10 . V_16 )
V_12 = F_8 ( V_8 , F_6 ( V_10 . V_16 ) ) ;
else
V_12 = F_9 ( V_8 , & V_10 . V_25 , V_10 . V_17 ) ;
if ( V_12 < 0 )
goto V_21;
if ( F_6 ( V_10 . V_17 ) == V_26 ||
F_6 ( V_10 . V_17 ) == V_27 )
V_8 -> V_28 = V_29 ;
F_10 ( & F_11 ( V_6 ) -> V_30 , & V_10 . V_25 ) ;
V_8 -> V_31 = V_32 ;
V_6 -> V_18 = V_32 ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_33 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_9 V_10 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( ! V_4 || V_5 < sizeof( V_4 -> V_13 ) ||
V_4 -> V_13 != V_14 )
return - V_15 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_11 = F_4 (unsigned int, sizeof(la), alen) ;
memcpy ( & V_10 , V_4 , V_11 ) ;
if ( V_10 . V_16 && V_10 . V_17 )
return - V_15 ;
V_12 = F_14 ( V_8 , V_10 . V_17 , F_6 ( V_10 . V_16 ) ,
& V_10 . V_25 , V_10 . V_34 ) ;
if ( V_12 )
return V_12 ;
F_5 ( V_6 ) ;
V_12 = F_15 ( V_6 , V_35 ,
F_16 ( V_6 , V_33 & V_36 ) ) ;
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 , int V_37 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 = 0 ;
F_3 ( L_2 , V_6 , V_37 ) ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 != V_32 ) {
V_12 = - V_20 ;
goto V_21;
}
if ( V_6 -> V_38 != V_39 && V_6 -> V_38 != V_40 ) {
V_12 = - V_15 ;
goto V_21;
}
switch ( V_8 -> V_41 ) {
case V_42 :
break;
case V_43 :
case V_44 :
if ( ! V_45 )
break;
default:
V_12 = - V_46 ;
goto V_21;
}
V_6 -> V_47 = V_37 ;
V_6 -> V_48 = 0 ;
V_8 -> V_31 = V_49 ;
V_6 -> V_18 = V_49 ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_1 * V_50 , int V_33 )
{
F_19 ( V_51 , V_52 ) ;
struct V_2 * V_6 = V_2 -> V_6 , * V_53 ;
long V_54 ;
int V_12 = 0 ;
F_20 ( V_6 , V_55 ) ;
V_54 = F_21 ( V_6 , V_33 & V_36 ) ;
F_3 ( L_3 , V_6 , V_54 ) ;
F_22 ( F_23 ( V_6 ) , & V_51 ) ;
while ( 1 ) {
F_24 ( V_56 ) ;
if ( V_6 -> V_18 != V_49 ) {
V_12 = - V_20 ;
break;
}
V_53 = F_25 ( V_6 , V_50 ) ;
if ( V_53 )
break;
if ( ! V_54 ) {
V_12 = - V_57 ;
break;
}
if ( F_26 ( V_52 ) ) {
V_12 = F_27 ( V_54 ) ;
break;
}
F_12 ( V_6 ) ;
V_54 = F_28 ( V_54 ) ;
F_20 ( V_6 , V_55 ) ;
}
F_29 ( V_58 ) ;
F_30 ( F_23 ( V_6 ) , & V_51 ) ;
if ( V_12 )
goto V_21;
V_50 -> V_31 = V_59 ;
F_3 ( L_4 , V_53 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 , int * V_11 , int V_60 )
{
struct V_9 * V_10 = (struct V_9 * ) V_4 ;
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
F_3 ( L_5 , V_2 , V_6 ) ;
memset ( V_10 , 0 , sizeof( struct V_9 ) ) ;
V_4 -> V_13 = V_14 ;
* V_11 = sizeof( struct V_9 ) ;
if ( V_60 ) {
V_10 -> V_17 = V_8 -> V_22 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_61 ) ;
V_10 -> V_16 = F_32 ( V_8 -> V_62 ) ;
} else {
V_10 -> V_17 = V_8 -> V_63 ;
F_10 ( & V_10 -> V_25 , & F_11 ( V_6 ) -> V_30 ) ;
V_10 -> V_16 = F_32 ( V_8 -> V_64 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_65 , char T_2 * V_66 , int T_2 * V_67 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_68 V_69 ;
struct V_70 V_71 ;
int V_11 , V_12 = 0 ;
T_3 V_72 ;
F_3 ( L_1 , V_6 ) ;
if ( F_34 ( V_11 , V_67 ) )
return - V_73 ;
F_5 ( V_6 ) ;
switch ( V_65 ) {
case V_74 :
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_75 = V_8 -> V_75 ;
V_69 . V_76 = V_8 -> V_76 ;
V_69 . V_77 = V_8 -> V_77 ;
V_69 . V_41 = V_8 -> V_41 ;
V_69 . V_78 = V_8 -> V_78 ;
V_69 . V_79 = V_8 -> V_79 ;
V_69 . V_80 = V_8 -> V_81 ;
V_11 = F_4 (unsigned int, len, sizeof(opts)) ;
if ( F_35 ( V_66 , ( char * ) & V_69 , V_11 ) )
V_12 = - V_73 ;
break;
case V_82 :
switch ( V_8 -> V_28 ) {
case V_83 :
V_72 = V_84 ;
break;
case V_85 :
V_72 = V_84 | V_86 ;
break;
case V_87 :
V_72 = V_84 | V_86 |
V_88 ;
break;
default:
V_72 = 0 ;
break;
}
if ( F_36 ( V_89 , & V_8 -> V_33 ) )
V_72 |= V_90 ;
if ( F_36 ( V_91 , & V_8 -> V_33 ) )
V_72 |= V_92 ;
if ( F_37 ( V_72 , ( T_3 T_2 * ) V_66 ) )
V_12 = - V_73 ;
break;
case V_93 :
if ( V_6 -> V_18 != V_35 &&
! ( V_6 -> V_18 == V_94 &&
F_36 ( V_95 , & F_11 ( V_6 ) -> V_33 ) ) ) {
V_12 = - V_96 ;
break;
}
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_97 = V_8 -> V_98 -> V_99 -> V_100 ;
memcpy ( V_71 . V_101 , V_8 -> V_98 -> V_99 -> V_101 , 3 ) ;
V_11 = F_4 (unsigned int, len, sizeof(cinfo)) ;
if ( F_35 ( V_66 , ( char * ) & V_71 , V_11 ) )
V_12 = - V_73 ;
break;
default:
V_12 = - V_102 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_38 ( struct V_1 * V_2 , int V_103 , int V_65 , char T_2 * V_66 , int T_2 * V_67 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_104 V_105 ;
struct V_106 V_107 ;
int V_11 , V_12 = 0 ;
F_3 ( L_1 , V_6 ) ;
if ( V_103 == V_108 )
return F_33 ( V_2 , V_65 , V_66 , V_67 ) ;
if ( V_103 != V_109 )
return - V_102 ;
if ( F_34 ( V_11 , V_67 ) )
return - V_73 ;
F_5 ( V_6 ) ;
switch ( V_65 ) {
case V_110 :
if ( V_8 -> V_111 != V_112 &&
V_8 -> V_111 != V_113 ) {
V_12 = - V_15 ;
break;
}
memset ( & V_105 , 0 , sizeof( V_105 ) ) ;
if ( V_8 -> V_98 )
V_105 . V_103 = V_8 -> V_98 -> V_99 -> V_28 ;
else
V_105 . V_103 = V_8 -> V_28 ;
if ( V_6 -> V_18 == V_35 )
V_105 . V_114 = V_8 -> V_98 -> V_99 -> V_115 ;
V_11 = F_4 (unsigned int, len, sizeof(sec)) ;
if ( F_35 ( V_66 , ( char * ) & V_105 , V_11 ) )
V_12 = - V_73 ;
break;
case V_116 :
if ( V_6 -> V_18 != V_32 && V_6 -> V_18 != V_49 ) {
V_12 = - V_15 ;
break;
}
if ( F_37 ( F_36 ( V_95 , & F_11 ( V_6 ) -> V_33 ) ,
( T_3 T_2 * ) V_66 ) )
V_12 = - V_73 ;
break;
case V_117 :
if ( F_37 ( F_36 ( V_118 , & V_8 -> V_33 ) ,
( T_3 T_2 * ) V_66 ) )
V_12 = - V_73 ;
break;
case V_119 :
if ( V_6 -> V_38 != V_39 && V_6 -> V_38 != V_40
&& V_6 -> V_38 != V_120 ) {
V_12 = - V_15 ;
break;
}
V_107 . V_121 = F_36 ( V_122 , & V_8 -> V_33 ) ;
V_11 = F_4 (unsigned int, len, sizeof(pwr)) ;
if ( F_35 ( V_66 , ( char * ) & V_107 , V_11 ) )
V_12 = - V_73 ;
break;
case V_123 :
if ( ! V_124 ) {
V_12 = - V_102 ;
break;
}
if ( F_37 ( V_8 -> V_125 , ( T_3 T_2 * ) V_66 ) )
V_12 = - V_73 ;
break;
default:
V_12 = - V_102 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static bool F_39 ( struct V_7 * V_8 , T_4 V_126 )
{
switch ( V_8 -> V_64 ) {
case V_127 :
if ( V_126 < V_128 )
return false ;
break;
default:
if ( V_126 < V_129 )
return false ;
}
return true ;
}
static int F_40 ( struct V_1 * V_2 , int V_65 , char T_2 * V_66 , unsigned int V_67 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_68 V_69 ;
int V_11 , V_12 = 0 ;
T_3 V_72 ;
F_3 ( L_1 , V_6 ) ;
F_5 ( V_6 ) ;
switch ( V_65 ) {
case V_74 :
if ( V_6 -> V_18 == V_35 ) {
V_12 = - V_15 ;
break;
}
V_69 . V_75 = V_8 -> V_75 ;
V_69 . V_76 = V_8 -> V_76 ;
V_69 . V_77 = V_8 -> V_77 ;
V_69 . V_41 = V_8 -> V_41 ;
V_69 . V_78 = V_8 -> V_78 ;
V_69 . V_79 = V_8 -> V_79 ;
V_69 . V_80 = V_8 -> V_81 ;
V_11 = F_4 (unsigned int, sizeof(opts), optlen) ;
if ( F_41 ( ( char * ) & V_69 , V_66 , V_11 ) ) {
V_12 = - V_73 ;
break;
}
if ( V_69 . V_80 > V_130 ) {
V_12 = - V_15 ;
break;
}
if ( ! F_39 ( V_8 , V_69 . V_75 ) ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_41 = V_69 . V_41 ;
switch ( V_8 -> V_41 ) {
case V_42 :
F_42 ( V_131 , & V_8 -> V_132 ) ;
break;
case V_43 :
case V_44 :
if ( ! V_45 )
break;
default:
V_12 = - V_15 ;
break;
}
V_8 -> V_75 = V_69 . V_75 ;
V_8 -> V_76 = V_69 . V_76 ;
V_8 -> V_78 = V_69 . V_78 ;
V_8 -> V_79 = V_69 . V_79 ;
V_8 -> V_81 = V_69 . V_80 ;
break;
case V_82 :
if ( F_34 ( V_72 , ( T_3 T_2 * ) V_66 ) ) {
V_12 = - V_73 ;
break;
}
if ( V_72 & V_84 )
V_8 -> V_28 = V_83 ;
if ( V_72 & V_86 )
V_8 -> V_28 = V_85 ;
if ( V_72 & V_88 )
V_8 -> V_28 = V_87 ;
if ( V_72 & V_90 )
F_43 ( V_89 , & V_8 -> V_33 ) ;
else
F_42 ( V_89 , & V_8 -> V_33 ) ;
if ( V_72 & V_92 )
F_43 ( V_91 , & V_8 -> V_33 ) ;
else
F_42 ( V_91 , & V_8 -> V_33 ) ;
break;
default:
V_12 = - V_102 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_44 ( struct V_1 * V_2 , int V_103 , int V_65 , char T_2 * V_66 , unsigned int V_67 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
struct V_104 V_105 ;
struct V_106 V_107 ;
struct V_133 * V_98 ;
int V_11 , V_12 = 0 ;
T_3 V_72 ;
F_3 ( L_1 , V_6 ) ;
if ( V_103 == V_108 )
return F_40 ( V_2 , V_65 , V_66 , V_67 ) ;
if ( V_103 != V_109 )
return - V_102 ;
F_5 ( V_6 ) ;
switch ( V_65 ) {
case V_110 :
if ( V_8 -> V_111 != V_112 &&
V_8 -> V_111 != V_113 ) {
V_12 = - V_15 ;
break;
}
V_105 . V_103 = V_83 ;
V_11 = F_4 (unsigned int, sizeof(sec), optlen) ;
if ( F_41 ( ( char * ) & V_105 , V_66 , V_11 ) ) {
V_12 = - V_73 ;
break;
}
if ( V_105 . V_103 < V_83 ||
V_105 . V_103 > V_87 ) {
V_12 = - V_15 ;
break;
}
V_8 -> V_28 = V_105 . V_103 ;
if ( ! V_8 -> V_98 )
break;
V_98 = V_8 -> V_98 ;
if ( V_8 -> V_64 == V_127 ) {
if ( ! V_98 -> V_99 -> V_134 ) {
V_12 = - V_15 ;
break;
}
if ( F_45 ( V_98 -> V_99 , V_105 . V_103 ) )
break;
V_6 -> V_18 = V_135 ;
V_8 -> V_31 = V_135 ;
} else if ( ( V_6 -> V_18 == V_94 &&
F_36 ( V_95 , & F_11 ( V_6 ) -> V_33 ) ) ||
V_6 -> V_18 == V_35 ) {
if ( ! F_46 ( V_8 ) )
F_43 ( V_136 , & F_11 ( V_6 ) -> V_33 ) ;
else
V_6 -> V_137 ( V_6 ) ;
} else {
V_12 = - V_15 ;
}
break;
case V_116 :
if ( V_6 -> V_18 != V_32 && V_6 -> V_18 != V_49 ) {
V_12 = - V_15 ;
break;
}
if ( F_34 ( V_72 , ( T_3 T_2 * ) V_66 ) ) {
V_12 = - V_73 ;
break;
}
if ( V_72 )
F_43 ( V_95 , & F_11 ( V_6 ) -> V_33 ) ;
else
F_42 ( V_95 , & F_11 ( V_6 ) -> V_33 ) ;
break;
case V_117 :
if ( F_34 ( V_72 , ( T_3 T_2 * ) V_66 ) ) {
V_12 = - V_73 ;
break;
}
if ( V_72 > V_138 ) {
V_12 = - V_15 ;
break;
}
if ( V_72 == V_139 ) {
struct V_133 * V_98 = V_8 -> V_98 ;
if ( ! V_98 || ! F_47 ( V_98 -> V_99 -> V_140 ) ) {
V_12 = - V_15 ;
break;
}
}
if ( V_72 )
F_43 ( V_118 , & V_8 -> V_33 ) ;
else
F_42 ( V_118 , & V_8 -> V_33 ) ;
break;
case V_119 :
if ( V_8 -> V_111 != V_112 &&
V_8 -> V_111 != V_113 ) {
V_12 = - V_15 ;
break;
}
V_107 . V_121 = V_141 ;
V_11 = F_4 (unsigned int, sizeof(pwr), optlen) ;
if ( F_41 ( ( char * ) & V_107 , V_66 , V_11 ) ) {
V_12 = - V_73 ;
break;
}
if ( V_107 . V_121 )
F_43 ( V_122 , & V_8 -> V_33 ) ;
else
F_42 ( V_122 , & V_8 -> V_33 ) ;
break;
case V_123 :
if ( ! V_124 ) {
V_12 = - V_102 ;
break;
}
if ( F_34 ( V_72 , ( T_3 T_2 * ) V_66 ) ) {
V_12 = - V_73 ;
break;
}
if ( V_72 > V_142 ) {
V_12 = - V_15 ;
break;
}
if ( V_8 -> V_41 != V_43 &&
V_8 -> V_41 != V_44 ) {
V_12 = - V_143 ;
break;
}
V_8 -> V_125 = ( V_144 ) V_72 ;
break;
default:
V_12 = - V_102 ;
break;
}
F_12 ( V_6 ) ;
return V_12 ;
}
static int F_48 ( struct V_145 * V_146 , struct V_1 * V_2 , struct V_147 * V_148 , T_5 V_11 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
V_12 = F_49 ( V_6 ) ;
if ( V_12 )
return V_12 ;
if ( V_148 -> V_149 & V_150 )
return - V_143 ;
if ( V_6 -> V_18 != V_35 )
return - V_96 ;
F_50 ( V_8 ) ;
V_12 = F_51 ( V_8 , V_148 , V_11 , V_6 -> V_151 ) ;
F_52 ( V_8 ) ;
return V_12 ;
}
static int F_53 ( struct V_145 * V_146 , struct V_1 * V_2 , struct V_147 * V_148 , T_5 V_11 , int V_33 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_152 * V_153 = F_2 ( V_6 ) ;
int V_12 ;
F_5 ( V_6 ) ;
if ( V_6 -> V_18 == V_94 && F_36 ( V_95 ,
& F_11 ( V_6 ) -> V_33 ) ) {
V_6 -> V_18 = V_135 ;
V_153 -> V_8 -> V_31 = V_135 ;
F_54 ( V_153 -> V_8 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
F_12 ( V_6 ) ;
if ( V_2 -> type == V_40 )
V_12 = F_55 ( V_146 , V_2 , V_148 , V_11 , V_33 ) ;
else
V_12 = F_56 ( V_146 , V_2 , V_148 , V_11 , V_33 ) ;
if ( V_153 -> V_8 -> V_41 != V_43 )
return V_12 ;
F_5 ( V_6 ) ;
if ( ! F_36 ( V_154 , & V_153 -> V_8 -> V_155 ) )
goto V_21;
if ( V_153 -> V_156 ) {
if ( ! F_57 ( V_6 , V_153 -> V_156 ) )
V_153 -> V_156 = NULL ;
else
goto V_21;
}
if ( F_58 ( & V_6 -> V_157 ) <= V_6 -> V_158 >> 1 )
F_59 ( V_153 -> V_8 , 0 ) ;
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static void F_60 ( struct V_2 * V_6 )
{
if ( ! F_61 ( V_6 , V_159 ) || V_6 -> V_160 )
return;
F_3 ( L_6 , V_6 , F_62 ( V_6 -> V_18 ) ) ;
F_63 ( F_2 ( V_6 ) -> V_8 ) ;
F_64 ( V_6 , V_161 ) ;
F_65 ( V_6 ) ;
}
static int F_66 ( struct V_1 * V_2 , int V_162 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_133 * V_98 ;
int V_12 = 0 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
V_8 = F_2 ( V_6 ) -> V_8 ;
V_98 = V_8 -> V_98 ;
if ( V_98 )
F_67 ( & V_98 -> V_163 ) ;
F_50 ( V_8 ) ;
F_5 ( V_6 ) ;
if ( ! V_6 -> V_164 ) {
if ( V_8 -> V_41 == V_43 )
V_12 = F_68 ( V_6 ) ;
V_6 -> V_164 = V_165 ;
F_12 ( V_6 ) ;
F_69 ( V_8 , 0 ) ;
F_5 ( V_6 ) ;
if ( F_61 ( V_6 , V_166 ) && V_6 -> V_167 )
V_12 = F_15 ( V_6 , V_168 ,
V_6 -> V_167 ) ;
}
if ( ! V_12 && V_6 -> V_169 )
V_12 = - V_6 -> V_169 ;
F_12 ( V_6 ) ;
F_52 ( V_8 ) ;
if ( V_98 )
F_70 ( & V_98 -> V_163 ) ;
return V_12 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_2 * V_6 = V_2 -> V_6 ;
int V_12 ;
F_3 ( L_5 , V_2 , V_6 ) ;
if ( ! V_6 )
return 0 ;
V_12 = F_66 ( V_2 , 2 ) ;
F_72 ( V_6 ) ;
F_60 ( V_6 ) ;
return V_12 ;
}
static void F_73 ( struct V_2 * V_170 )
{
struct V_2 * V_6 ;
F_3 ( L_7 , V_170 ) ;
while ( ( V_6 = F_25 ( V_170 , NULL ) ) ) {
struct V_7 * V_8 = F_2 ( V_6 ) -> V_8 ;
F_50 ( V_8 ) ;
F_74 ( V_8 ) ;
F_69 ( V_8 , V_171 ) ;
F_52 ( V_8 ) ;
F_60 ( V_6 ) ;
}
}
static struct V_7 * F_75 ( struct V_7 * V_8 )
{
struct V_2 * V_6 , * V_170 = V_8 -> V_172 ;
if ( F_76 ( V_170 ) ) {
F_3 ( L_8 , V_170 -> V_48 ) ;
return NULL ;
}
V_6 = F_77 ( F_78 ( V_170 ) , NULL , V_173 ,
V_174 ) ;
if ( ! V_6 )
return NULL ;
F_79 ( V_6 , V_173 ) ;
F_80 ( V_6 , V_170 ) ;
return F_2 ( V_6 ) -> V_8 ;
}
static int F_81 ( struct V_7 * V_8 , struct V_175 * V_176 )
{
int V_12 ;
struct V_2 * V_6 = V_8 -> V_172 ;
struct V_152 * V_153 = F_2 ( V_6 ) ;
F_5 ( V_6 ) ;
if ( V_153 -> V_156 ) {
V_12 = - V_177 ;
goto V_21;
}
V_12 = F_57 ( V_6 , V_176 ) ;
if ( V_12 < 0 && V_153 -> V_8 -> V_41 == V_43 ) {
V_153 -> V_156 = V_176 ;
F_59 ( V_153 -> V_8 , 1 ) ;
V_12 = 0 ;
}
V_21:
F_12 ( V_6 ) ;
return V_12 ;
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_2 * V_6 = V_8 -> V_172 ;
F_60 ( V_6 ) ;
}
static void F_83 ( struct V_7 * V_8 , int V_12 )
{
struct V_2 * V_6 = V_8 -> V_172 ;
struct V_2 * V_170 ;
F_5 ( V_6 ) ;
V_170 = F_11 ( V_6 ) -> V_170 ;
F_64 ( V_6 , V_159 ) ;
switch ( V_8 -> V_31 ) {
case V_19 :
case V_32 :
case V_168 :
break;
case V_49 :
F_73 ( V_6 ) ;
V_6 -> V_18 = V_168 ;
V_8 -> V_31 = V_168 ;
break;
default:
V_6 -> V_18 = V_168 ;
V_8 -> V_31 = V_168 ;
V_6 -> V_169 = V_12 ;
if ( V_170 ) {
F_84 ( V_6 ) ;
V_170 -> V_178 ( V_170 , 0 ) ;
} else {
V_6 -> V_137 ( V_6 ) ;
}
break;
}
F_12 ( V_6 ) ;
}
static void F_85 ( struct V_7 * V_8 , int V_31 )
{
struct V_2 * V_6 = V_8 -> V_172 ;
V_6 -> V_18 = V_31 ;
}
static struct V_175 * F_86 ( struct V_7 * V_8 ,
unsigned long V_11 , int V_179 )
{
struct V_175 * V_176 ;
int V_12 ;
F_52 ( V_8 ) ;
V_176 = F_87 ( V_8 -> V_6 , V_11 , V_179 , & V_12 ) ;
F_50 ( V_8 ) ;
if ( ! V_176 )
return F_88 ( V_12 ) ;
return V_176 ;
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_2 * V_6 = V_8 -> V_172 ;
struct V_2 * V_170 ;
F_5 ( V_6 ) ;
V_170 = F_11 ( V_6 ) -> V_170 ;
F_3 ( L_9 , V_6 , V_170 ) ;
V_6 -> V_18 = V_35 ;
V_6 -> V_137 ( V_6 ) ;
if ( V_170 )
V_170 -> V_178 ( V_170 , 0 ) ;
F_12 ( V_6 ) ;
}
static void F_90 ( struct V_2 * V_6 )
{
F_3 ( L_1 , V_6 ) ;
F_91 ( F_2 ( V_6 ) -> V_8 ) ;
if ( F_2 ( V_6 ) -> V_156 ) {
F_92 ( F_2 ( V_6 ) -> V_156 ) ;
F_2 ( V_6 ) -> V_156 = NULL ;
}
F_93 ( & V_6 -> V_180 ) ;
F_93 ( & V_6 -> V_181 ) ;
}
static void F_80 ( struct V_2 * V_6 , struct V_2 * V_170 )
{
struct V_152 * V_153 = F_2 ( V_6 ) ;
struct V_7 * V_8 = V_153 -> V_8 ;
F_3 ( L_1 , V_6 ) ;
if ( V_170 ) {
struct V_7 * V_182 = F_2 ( V_170 ) -> V_8 ;
V_6 -> V_38 = V_170 -> V_38 ;
F_11 ( V_6 ) -> V_33 = F_11 ( V_170 ) -> V_33 ;
V_8 -> V_111 = V_182 -> V_111 ;
V_8 -> V_75 = V_182 -> V_75 ;
V_8 -> V_76 = V_182 -> V_76 ;
V_8 -> V_132 = V_182 -> V_132 ;
V_8 -> V_41 = V_182 -> V_41 ;
V_8 -> V_78 = V_182 -> V_78 ;
V_8 -> V_79 = V_182 -> V_79 ;
V_8 -> V_81 = V_182 -> V_81 ;
V_8 -> V_183 = V_182 -> V_183 ;
V_8 -> V_28 = V_182 -> V_28 ;
V_8 -> V_33 = V_182 -> V_33 ;
F_94 ( V_170 , V_6 ) ;
} else {
switch ( V_6 -> V_38 ) {
case V_120 :
V_8 -> V_111 = V_113 ;
break;
case V_184 :
V_8 -> V_111 = V_185 ;
break;
case V_39 :
case V_40 :
V_8 -> V_111 = V_112 ;
break;
}
V_8 -> V_75 = V_186 ;
V_8 -> V_76 = 0 ;
if ( ! V_45 && V_6 -> V_38 == V_40 ) {
V_8 -> V_41 = V_43 ;
F_43 ( V_131 , & V_8 -> V_132 ) ;
} else {
V_8 -> V_41 = V_42 ;
}
F_95 ( V_8 ) ;
}
V_8 -> V_77 = V_187 ;
V_8 -> V_172 = V_6 ;
V_8 -> V_188 = & V_189 ;
}
static struct V_2 * F_77 ( struct V_190 * V_190 , struct V_1 * V_2 , int V_191 , T_6 V_192 )
{
struct V_2 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_96 ( V_190 , V_193 , V_192 , & V_194 ) ;
if ( ! V_6 )
return NULL ;
F_97 ( V_2 , V_6 ) ;
F_98 ( & F_11 ( V_6 ) -> V_195 ) ;
V_6 -> V_196 = F_90 ;
V_6 -> V_197 = V_198 ;
F_99 ( V_6 , V_159 ) ;
V_6 -> V_199 = V_191 ;
V_6 -> V_18 = V_19 ;
V_8 = F_100 () ;
if ( ! V_8 ) {
F_101 ( V_6 ) ;
return NULL ;
}
F_102 ( V_8 ) ;
V_8 -> V_6 = V_6 ;
F_2 ( V_6 ) -> V_8 = V_8 ;
return V_6 ;
}
static int F_103 ( struct V_190 * V_190 , struct V_1 * V_2 , int V_200 ,
int V_201 )
{
struct V_2 * V_6 ;
F_3 ( L_10 , V_2 ) ;
V_2 -> V_31 = V_202 ;
if ( V_2 -> type != V_39 && V_2 -> type != V_40 &&
V_2 -> type != V_184 && V_2 -> type != V_120 )
return - V_203 ;
if ( V_2 -> type == V_120 && ! V_201 && ! F_7 ( V_204 ) )
return - V_205 ;
V_2 -> V_188 = & V_206 ;
V_6 = F_77 ( V_190 , V_2 , V_200 , V_174 ) ;
if ( ! V_6 )
return - V_177 ;
F_80 ( V_6 , NULL ) ;
return 0 ;
}
int T_7 F_104 ( void )
{
int V_12 ;
V_12 = F_105 ( & V_194 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_106 ( V_173 , & V_207 ) ;
if ( V_12 < 0 )
goto error;
F_107 ( L_11 ) ;
return 0 ;
error:
F_108 ( L_12 ) ;
F_109 ( & V_194 ) ;
return V_12 ;
}
void F_110 ( void )
{
if ( F_111 ( V_173 ) < 0 )
F_108 ( L_13 ) ;
F_109 ( & V_194 ) ;
}
