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
F_6 ( V_8 ) ;
if ( V_8 -> V_20 != V_21 ) {
V_14 = - V_22 ;
goto V_23;
}
if ( V_12 . V_19 ) {
T_1 V_24 = F_7 ( V_12 . V_19 ) ;
if ( ( V_24 & 0x0101 ) != 0x0001 ) {
V_14 = - V_17 ;
goto V_23;
}
if ( V_24 < 0x1001 && ! F_8 ( V_25 ) ) {
V_14 = - V_26 ;
goto V_23;
}
}
if ( V_12 . V_18 )
V_14 = F_9 ( V_10 , F_7 ( V_12 . V_18 ) ) ;
else
V_14 = F_10 ( V_10 , & V_12 . V_27 , V_12 . V_19 ) ;
if ( V_14 < 0 )
goto V_23;
if ( F_7 ( V_12 . V_19 ) == V_28 ||
F_7 ( V_12 . V_19 ) == V_29 )
V_10 -> V_30 = V_31 ;
F_11 ( & F_12 ( V_8 ) -> V_32 , & V_12 . V_27 ) ;
V_10 -> V_33 = V_34 ;
V_8 -> V_20 = V_34 ;
V_23:
F_13 ( V_8 ) ;
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int V_7 , int V_35 )
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
V_14 = F_15 ( V_10 , V_12 . V_19 , F_7 ( V_12 . V_18 ) ,
& V_12 . V_27 , V_12 . V_36 ) ;
if ( V_14 )
return V_14 ;
F_6 ( V_8 ) ;
V_14 = F_16 ( V_8 , V_37 ,
F_17 ( V_8 , V_35 & V_38 ) ) ;
F_13 ( V_8 ) ;
return V_14 ;
}
static int F_18 ( struct V_1 * V_2 , int V_39 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
int V_14 = 0 ;
F_4 ( L_2 , V_8 , V_39 ) ;
F_6 ( V_8 ) ;
if ( V_8 -> V_20 != V_34 ) {
V_14 = - V_22 ;
goto V_23;
}
if ( V_8 -> V_40 != V_41 && V_8 -> V_40 != V_42 ) {
V_14 = - V_17 ;
goto V_23;
}
switch ( V_10 -> V_43 ) {
case V_44 :
break;
case V_45 :
case V_46 :
if ( ! V_47 )
break;
default:
V_14 = - V_48 ;
goto V_23;
}
V_8 -> V_49 = V_39 ;
V_8 -> V_50 = 0 ;
V_10 -> V_33 = V_51 ;
V_8 -> V_20 = V_51 ;
V_23:
F_13 ( V_8 ) ;
return V_14 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_1 * V_52 ,
int V_35 )
{
F_20 ( V_53 , V_54 ) ;
struct V_2 * V_8 = V_2 -> V_8 , * V_55 ;
long V_56 ;
int V_14 = 0 ;
F_21 ( V_8 , V_57 ) ;
V_56 = F_22 ( V_8 , V_35 & V_38 ) ;
F_4 ( L_3 , V_8 , V_56 ) ;
F_23 ( F_24 ( V_8 ) , & V_53 ) ;
while ( 1 ) {
F_25 ( V_58 ) ;
if ( V_8 -> V_20 != V_51 ) {
V_14 = - V_22 ;
break;
}
V_55 = F_26 ( V_8 , V_52 ) ;
if ( V_55 )
break;
if ( ! V_56 ) {
V_14 = - V_59 ;
break;
}
if ( F_27 ( V_54 ) ) {
V_14 = F_28 ( V_56 ) ;
break;
}
F_13 ( V_8 ) ;
V_56 = F_29 ( V_56 ) ;
F_21 ( V_8 , V_57 ) ;
}
F_30 ( V_60 ) ;
F_31 ( F_24 ( V_8 ) , & V_53 ) ;
if ( V_14 )
goto V_23;
V_52 -> V_33 = V_61 ;
F_4 ( L_4 , V_55 ) ;
V_23:
F_13 ( V_8 ) ;
return V_14 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_5 * V_6 ,
int * V_13 , int V_62 )
{
struct V_11 * V_12 = (struct V_11 * ) V_6 ;
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
F_4 ( L_5 , V_2 , V_8 ) ;
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
V_6 -> V_15 = V_16 ;
* V_13 = sizeof( struct V_11 ) ;
if ( V_62 ) {
V_12 -> V_19 = V_10 -> V_24 ;
F_11 ( & V_12 -> V_27 , & F_12 ( V_8 ) -> V_63 ) ;
V_12 -> V_18 = F_33 ( V_10 -> V_64 ) ;
} else {
V_12 -> V_19 = V_10 -> V_65 ;
F_11 ( & V_12 -> V_27 , & F_12 ( V_8 ) -> V_32 ) ;
V_12 -> V_18 = F_33 ( V_10 -> V_66 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_67 ,
char T_2 * V_68 , int T_2 * V_69 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_70 V_71 ;
struct V_72 V_73 ;
int V_13 , V_14 = 0 ;
T_3 V_74 ;
F_4 ( L_1 , V_8 ) ;
if ( F_35 ( V_13 , V_69 ) )
return - V_75 ;
F_6 ( V_8 ) ;
switch ( V_67 ) {
case V_76 :
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 . V_77 = V_10 -> V_77 ;
V_71 . V_78 = V_10 -> V_78 ;
V_71 . V_79 = V_10 -> V_79 ;
V_71 . V_43 = V_10 -> V_43 ;
V_71 . V_80 = V_10 -> V_80 ;
V_71 . V_81 = V_10 -> V_81 ;
V_71 . V_82 = V_10 -> V_83 ;
V_13 = F_5 (unsigned int, len, sizeof(opts)) ;
if ( F_36 ( V_68 , ( char * ) & V_71 , V_13 ) )
V_14 = - V_75 ;
break;
case V_84 :
switch ( V_10 -> V_30 ) {
case V_85 :
V_74 = V_86 ;
break;
case V_87 :
V_74 = V_86 | V_88 ;
break;
case V_89 :
V_74 = V_86 | V_88 |
V_90 ;
break;
default:
V_74 = 0 ;
break;
}
if ( F_37 ( V_91 , & V_10 -> V_35 ) )
V_74 |= V_92 ;
if ( F_37 ( V_93 , & V_10 -> V_35 ) )
V_74 |= V_94 ;
if ( F_38 ( V_74 , ( T_3 T_2 * ) V_68 ) )
V_14 = - V_75 ;
break;
case V_95 :
if ( V_8 -> V_20 != V_37 &&
! ( V_8 -> V_20 == V_96 &&
F_37 ( V_97 , & F_12 ( V_8 ) -> V_35 ) ) ) {
V_14 = - V_98 ;
break;
}
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 . V_99 = V_10 -> V_100 -> V_101 -> V_102 ;
memcpy ( V_73 . V_103 , V_10 -> V_100 -> V_101 -> V_103 , 3 ) ;
V_13 = F_5 (unsigned int, len, sizeof(cinfo)) ;
if ( F_36 ( V_68 , ( char * ) & V_73 , V_13 ) )
V_14 = - V_75 ;
break;
default:
V_14 = - V_104 ;
break;
}
F_13 ( V_8 ) ;
return V_14 ;
}
static int F_39 ( struct V_1 * V_2 , int V_105 , int V_67 ,
char T_2 * V_68 , int T_2 * V_69 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_106 V_107 ;
struct V_108 V_109 ;
int V_13 , V_14 = 0 ;
F_4 ( L_1 , V_8 ) ;
if ( V_105 == V_110 )
return F_34 ( V_2 , V_67 , V_68 , V_69 ) ;
if ( V_105 != V_111 )
return - V_104 ;
if ( F_35 ( V_13 , V_69 ) )
return - V_75 ;
F_6 ( V_8 ) ;
switch ( V_67 ) {
case V_112 :
if ( V_10 -> V_113 != V_114 &&
V_10 -> V_113 != V_115 ) {
V_14 = - V_17 ;
break;
}
memset ( & V_107 , 0 , sizeof( V_107 ) ) ;
if ( V_10 -> V_100 ) {
V_107 . V_105 = V_10 -> V_100 -> V_101 -> V_30 ;
if ( V_8 -> V_20 == V_37 )
V_107 . V_116 = V_10 -> V_100 -> V_101 -> V_117 ;
} else {
V_107 . V_105 = V_10 -> V_30 ;
}
V_13 = F_5 (unsigned int, len, sizeof(sec)) ;
if ( F_36 ( V_68 , ( char * ) & V_107 , V_13 ) )
V_14 = - V_75 ;
break;
case V_118 :
if ( V_8 -> V_20 != V_34 && V_8 -> V_20 != V_51 ) {
V_14 = - V_17 ;
break;
}
if ( F_38 ( F_37 ( V_97 , & F_12 ( V_8 ) -> V_35 ) ,
( T_3 T_2 * ) V_68 ) )
V_14 = - V_75 ;
break;
case V_119 :
if ( F_38 ( F_37 ( V_120 , & V_10 -> V_35 ) ,
( T_3 T_2 * ) V_68 ) )
V_14 = - V_75 ;
break;
case V_121 :
if ( V_8 -> V_40 != V_41 && V_8 -> V_40 != V_42
&& V_8 -> V_40 != V_122 ) {
V_14 = - V_17 ;
break;
}
V_109 . V_123 = F_37 ( V_124 , & V_10 -> V_35 ) ;
V_13 = F_5 (unsigned int, len, sizeof(pwr)) ;
if ( F_36 ( V_68 , ( char * ) & V_109 , V_13 ) )
V_14 = - V_75 ;
break;
case V_125 :
if ( ! V_126 ) {
V_14 = - V_104 ;
break;
}
if ( F_38 ( V_10 -> V_127 , ( T_3 T_2 * ) V_68 ) )
V_14 = - V_75 ;
break;
default:
V_14 = - V_104 ;
break;
}
F_13 ( V_8 ) ;
return V_14 ;
}
static bool F_40 ( struct V_9 * V_10 , T_4 V_128 )
{
switch ( V_10 -> V_66 ) {
case V_129 :
if ( V_128 < V_130 )
return false ;
break;
default:
if ( V_128 < V_131 )
return false ;
}
return true ;
}
static int F_41 ( struct V_1 * V_2 , int V_67 ,
char T_2 * V_68 , unsigned int V_69 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_70 V_71 ;
int V_13 , V_14 = 0 ;
T_3 V_74 ;
F_4 ( L_1 , V_8 ) ;
F_6 ( V_8 ) ;
switch ( V_67 ) {
case V_76 :
if ( V_8 -> V_20 == V_37 ) {
V_14 = - V_17 ;
break;
}
V_71 . V_77 = V_10 -> V_77 ;
V_71 . V_78 = V_10 -> V_78 ;
V_71 . V_79 = V_10 -> V_79 ;
V_71 . V_43 = V_10 -> V_43 ;
V_71 . V_80 = V_10 -> V_80 ;
V_71 . V_81 = V_10 -> V_81 ;
V_71 . V_82 = V_10 -> V_83 ;
V_13 = F_5 (unsigned int, sizeof(opts), optlen) ;
if ( F_42 ( ( char * ) & V_71 , V_68 , V_13 ) ) {
V_14 = - V_75 ;
break;
}
if ( V_71 . V_82 > V_132 ) {
V_14 = - V_17 ;
break;
}
if ( ! F_40 ( V_10 , V_71 . V_77 ) ) {
V_14 = - V_17 ;
break;
}
V_10 -> V_43 = V_71 . V_43 ;
switch ( V_10 -> V_43 ) {
case V_44 :
F_43 ( V_133 , & V_10 -> V_134 ) ;
break;
case V_45 :
case V_46 :
if ( ! V_47 )
break;
default:
V_14 = - V_17 ;
break;
}
V_10 -> V_77 = V_71 . V_77 ;
V_10 -> V_78 = V_71 . V_78 ;
V_10 -> V_80 = V_71 . V_80 ;
V_10 -> V_81 = V_71 . V_81 ;
V_10 -> V_83 = V_71 . V_82 ;
V_10 -> V_79 = V_71 . V_79 ;
break;
case V_84 :
if ( F_35 ( V_74 , ( T_3 T_2 * ) V_68 ) ) {
V_14 = - V_75 ;
break;
}
if ( V_74 & V_86 )
V_10 -> V_30 = V_85 ;
if ( V_74 & V_88 )
V_10 -> V_30 = V_87 ;
if ( V_74 & V_90 )
V_10 -> V_30 = V_89 ;
if ( V_74 & V_92 )
F_44 ( V_91 , & V_10 -> V_35 ) ;
else
F_43 ( V_91 , & V_10 -> V_35 ) ;
if ( V_74 & V_94 )
F_44 ( V_93 , & V_10 -> V_35 ) ;
else
F_43 ( V_93 , & V_10 -> V_35 ) ;
break;
default:
V_14 = - V_104 ;
break;
}
F_13 ( V_8 ) ;
return V_14 ;
}
static int F_45 ( struct V_1 * V_2 , int V_105 , int V_67 ,
char T_2 * V_68 , unsigned int V_69 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
struct V_106 V_107 ;
struct V_108 V_109 ;
struct V_135 * V_100 ;
int V_13 , V_14 = 0 ;
T_3 V_74 ;
F_4 ( L_1 , V_8 ) ;
if ( V_105 == V_110 )
return F_41 ( V_2 , V_67 , V_68 , V_69 ) ;
if ( V_105 != V_111 )
return - V_104 ;
F_6 ( V_8 ) ;
switch ( V_67 ) {
case V_112 :
if ( V_10 -> V_113 != V_114 &&
V_10 -> V_113 != V_115 ) {
V_14 = - V_17 ;
break;
}
V_107 . V_105 = V_85 ;
V_13 = F_5 (unsigned int, sizeof(sec), optlen) ;
if ( F_42 ( ( char * ) & V_107 , V_68 , V_13 ) ) {
V_14 = - V_75 ;
break;
}
if ( V_107 . V_105 < V_85 ||
V_107 . V_105 > V_89 ) {
V_14 = - V_17 ;
break;
}
V_10 -> V_30 = V_107 . V_105 ;
if ( ! V_10 -> V_100 )
break;
V_100 = V_10 -> V_100 ;
if ( V_10 -> V_66 == V_129 ) {
if ( ! V_100 -> V_101 -> V_136 ) {
V_14 = - V_17 ;
break;
}
if ( F_46 ( V_100 -> V_101 , V_107 . V_105 ) )
break;
V_8 -> V_20 = V_137 ;
V_10 -> V_33 = V_137 ;
} else if ( ( V_8 -> V_20 == V_96 &&
F_37 ( V_97 , & F_12 ( V_8 ) -> V_35 ) ) ||
V_8 -> V_20 == V_37 ) {
if ( ! F_47 ( V_10 ) )
F_44 ( V_138 , & F_12 ( V_8 ) -> V_35 ) ;
else
V_8 -> V_139 ( V_8 ) ;
} else {
V_14 = - V_17 ;
}
break;
case V_118 :
if ( V_8 -> V_20 != V_34 && V_8 -> V_20 != V_51 ) {
V_14 = - V_17 ;
break;
}
if ( F_35 ( V_74 , ( T_3 T_2 * ) V_68 ) ) {
V_14 = - V_75 ;
break;
}
if ( V_74 )
F_44 ( V_97 , & F_12 ( V_8 ) -> V_35 ) ;
else
F_43 ( V_97 , & F_12 ( V_8 ) -> V_35 ) ;
break;
case V_119 :
if ( F_35 ( V_74 , ( T_3 T_2 * ) V_68 ) ) {
V_14 = - V_75 ;
break;
}
if ( V_74 > V_140 ) {
V_14 = - V_17 ;
break;
}
if ( V_74 == V_141 ) {
struct V_135 * V_100 = V_10 -> V_100 ;
if ( ! V_100 || ! F_48 ( V_100 -> V_101 -> V_142 ) ) {
V_14 = - V_17 ;
break;
}
}
if ( V_74 )
F_44 ( V_120 , & V_10 -> V_35 ) ;
else
F_43 ( V_120 , & V_10 -> V_35 ) ;
break;
case V_121 :
if ( V_10 -> V_113 != V_114 &&
V_10 -> V_113 != V_115 ) {
V_14 = - V_17 ;
break;
}
V_109 . V_123 = V_143 ;
V_13 = F_5 (unsigned int, sizeof(pwr), optlen) ;
if ( F_42 ( ( char * ) & V_109 , V_68 , V_13 ) ) {
V_14 = - V_75 ;
break;
}
if ( V_109 . V_123 )
F_44 ( V_124 , & V_10 -> V_35 ) ;
else
F_43 ( V_124 , & V_10 -> V_35 ) ;
break;
case V_125 :
if ( ! V_126 ) {
V_14 = - V_104 ;
break;
}
if ( F_35 ( V_74 , ( T_3 T_2 * ) V_68 ) ) {
V_14 = - V_75 ;
break;
}
if ( V_74 > V_144 ) {
V_14 = - V_17 ;
break;
}
if ( V_10 -> V_43 != V_45 &&
V_10 -> V_43 != V_46 ) {
V_14 = - V_145 ;
break;
}
V_10 -> V_127 = ( V_146 ) V_74 ;
if ( V_8 -> V_20 == V_37 &&
V_10 -> V_147 == V_148 )
F_49 ( V_10 ) ;
break;
default:
V_14 = - V_104 ;
break;
}
F_13 ( V_8 ) ;
return V_14 ;
}
static int F_50 ( struct V_149 * V_150 , struct V_1 * V_2 ,
struct V_151 * V_152 , T_5 V_13 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
int V_14 ;
F_4 ( L_5 , V_2 , V_8 ) ;
V_14 = F_51 ( V_8 ) ;
if ( V_14 )
return V_14 ;
if ( V_152 -> V_153 & V_154 )
return - V_145 ;
if ( V_8 -> V_20 != V_37 )
return - V_98 ;
F_52 ( V_10 ) ;
V_14 = F_53 ( V_10 , V_152 , V_13 , V_8 -> V_155 ) ;
F_54 ( V_10 ) ;
return V_14 ;
}
static int F_55 ( struct V_149 * V_150 , struct V_1 * V_2 ,
struct V_151 * V_152 , T_5 V_13 , int V_35 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_156 * V_157 = F_3 ( V_8 ) ;
int V_14 ;
F_6 ( V_8 ) ;
if ( V_8 -> V_20 == V_96 && F_37 ( V_97 ,
& F_12 ( V_8 ) -> V_35 ) ) {
V_8 -> V_20 = V_137 ;
V_157 -> V_10 -> V_33 = V_137 ;
F_56 ( V_157 -> V_10 ) ;
F_13 ( V_8 ) ;
return 0 ;
}
F_13 ( V_8 ) ;
if ( V_2 -> type == V_42 )
V_14 = F_57 ( V_150 , V_2 , V_152 , V_13 , V_35 ) ;
else
V_14 = F_58 ( V_150 , V_2 , V_152 , V_13 , V_35 ) ;
if ( V_157 -> V_10 -> V_43 != V_45 )
return V_14 ;
F_6 ( V_8 ) ;
if ( ! F_37 ( V_158 , & V_157 -> V_10 -> V_159 ) )
goto V_23;
if ( V_157 -> V_160 ) {
if ( ! F_59 ( V_8 , V_157 -> V_160 ) )
V_157 -> V_160 = NULL ;
else
goto V_23;
}
if ( F_60 ( & V_8 -> V_161 ) <= V_8 -> V_162 >> 1 )
F_61 ( V_157 -> V_10 , 0 ) ;
V_23:
F_13 ( V_8 ) ;
return V_14 ;
}
static void F_62 ( struct V_2 * V_8 )
{
if ( ! F_63 ( V_8 , V_163 ) || V_8 -> V_164 )
return;
F_4 ( L_6 , V_8 , F_64 ( V_8 -> V_20 ) ) ;
F_65 ( F_3 ( V_8 ) -> V_10 ) ;
F_66 ( V_8 , V_165 ) ;
F_67 ( V_8 ) ;
}
static int F_68 ( struct V_1 * V_2 , int V_166 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_135 * V_100 ;
int V_14 = 0 ;
F_4 ( L_5 , V_2 , V_8 ) ;
if ( ! V_8 )
return 0 ;
V_10 = F_3 ( V_8 ) -> V_10 ;
V_100 = V_10 -> V_100 ;
if ( V_100 )
F_69 ( & V_100 -> V_167 ) ;
F_52 ( V_10 ) ;
F_6 ( V_8 ) ;
if ( ! V_8 -> V_168 ) {
if ( V_10 -> V_43 == V_45 )
V_14 = F_70 ( V_8 ) ;
V_8 -> V_168 = V_169 ;
F_13 ( V_8 ) ;
F_71 ( V_10 , 0 ) ;
F_6 ( V_8 ) ;
if ( F_63 ( V_8 , V_170 ) && V_8 -> V_171 )
V_14 = F_16 ( V_8 , V_172 ,
V_8 -> V_171 ) ;
}
if ( ! V_14 && V_8 -> V_173 )
V_14 = - V_8 -> V_173 ;
F_13 ( V_8 ) ;
F_54 ( V_10 ) ;
if ( V_100 )
F_72 ( & V_100 -> V_167 ) ;
return V_14 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_2 * V_8 = V_2 -> V_8 ;
int V_14 ;
F_4 ( L_5 , V_2 , V_8 ) ;
if ( ! V_8 )
return 0 ;
F_74 ( & V_174 , V_8 ) ;
V_14 = F_68 ( V_2 , 2 ) ;
F_75 ( V_8 ) ;
F_62 ( V_8 ) ;
return V_14 ;
}
static void F_76 ( struct V_2 * V_175 )
{
struct V_2 * V_8 ;
F_4 ( L_7 , V_175 ) ;
while ( ( V_8 = F_26 ( V_175 , NULL ) ) ) {
struct V_9 * V_10 = F_3 ( V_8 ) -> V_10 ;
F_52 ( V_10 ) ;
F_77 ( V_10 ) ;
F_71 ( V_10 , V_176 ) ;
F_54 ( V_10 ) ;
F_62 ( V_8 ) ;
}
}
static struct V_9 * F_78 ( struct V_9 * V_10 )
{
struct V_2 * V_8 , * V_175 = V_10 -> V_177 ;
if ( F_79 ( V_175 ) ) {
F_4 ( L_8 , V_175 -> V_50 ) ;
return NULL ;
}
V_8 = F_80 ( F_81 ( V_175 ) , NULL , V_178 ,
V_179 ) ;
if ( ! V_8 )
return NULL ;
F_82 ( V_8 , V_178 ) ;
F_83 ( V_8 , V_175 ) ;
F_84 ( V_175 , V_8 ) ;
return F_3 ( V_8 ) -> V_10 ;
}
static int F_85 ( struct V_9 * V_10 , struct V_180 * V_181 )
{
int V_14 ;
struct V_2 * V_8 = V_10 -> V_177 ;
struct V_156 * V_157 = F_3 ( V_8 ) ;
F_6 ( V_8 ) ;
if ( V_157 -> V_160 ) {
V_14 = - V_182 ;
goto V_23;
}
V_14 = F_59 ( V_8 , V_181 ) ;
if ( V_14 < 0 && V_157 -> V_10 -> V_43 == V_45 ) {
V_157 -> V_160 = V_181 ;
F_61 ( V_157 -> V_10 , 1 ) ;
V_14 = 0 ;
}
V_23:
F_13 ( V_8 ) ;
return V_14 ;
}
static void F_86 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_177 ;
F_62 ( V_8 ) ;
}
static void F_87 ( struct V_9 * V_10 , int V_14 )
{
struct V_2 * V_8 = V_10 -> V_177 ;
struct V_2 * V_175 ;
F_6 ( V_8 ) ;
V_175 = F_12 ( V_8 ) -> V_175 ;
F_66 ( V_8 , V_163 ) ;
switch ( V_10 -> V_33 ) {
case V_21 :
case V_34 :
case V_172 :
break;
case V_51 :
F_76 ( V_8 ) ;
V_8 -> V_20 = V_172 ;
V_10 -> V_33 = V_172 ;
break;
default:
V_8 -> V_20 = V_172 ;
V_10 -> V_33 = V_172 ;
V_8 -> V_173 = V_14 ;
if ( V_175 ) {
F_88 ( V_8 ) ;
V_175 -> V_183 ( V_175 , 0 ) ;
} else {
V_8 -> V_139 ( V_8 ) ;
}
break;
}
F_13 ( V_8 ) ;
}
static void F_89 ( struct V_9 * V_10 , int V_33 )
{
struct V_2 * V_8 = V_10 -> V_177 ;
V_8 -> V_20 = V_33 ;
}
static struct V_180 * F_90 ( struct V_9 * V_10 ,
unsigned long V_13 , int V_184 )
{
struct V_180 * V_181 ;
int V_14 ;
F_54 ( V_10 ) ;
V_181 = F_91 ( V_10 -> V_8 , V_13 , V_184 , & V_14 ) ;
F_52 ( V_10 ) ;
if ( ! V_181 )
return F_92 ( V_14 ) ;
return V_181 ;
}
static void F_93 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_177 ;
struct V_2 * V_175 ;
F_6 ( V_8 ) ;
V_175 = F_12 ( V_8 ) -> V_175 ;
F_4 ( L_9 , V_8 , V_175 ) ;
V_8 -> V_20 = V_37 ;
V_8 -> V_139 ( V_8 ) ;
if ( V_175 )
V_175 -> V_183 ( V_175 , 0 ) ;
F_13 ( V_8 ) ;
}
static void F_94 ( struct V_9 * V_10 )
{
struct V_2 * V_8 = V_10 -> V_177 ;
struct V_2 * V_175 = F_12 ( V_8 ) -> V_175 ;
if ( V_175 )
V_175 -> V_183 ( V_175 , 0 ) ;
}
static void F_95 ( struct V_2 * V_8 )
{
F_4 ( L_1 , V_8 ) ;
if ( F_3 ( V_8 ) -> V_10 )
F_65 ( F_3 ( V_8 ) -> V_10 ) ;
if ( F_3 ( V_8 ) -> V_160 ) {
F_96 ( F_3 ( V_8 ) -> V_160 ) ;
F_3 ( V_8 ) -> V_160 = NULL ;
}
F_97 ( & V_8 -> V_185 ) ;
F_97 ( & V_8 -> V_186 ) ;
}
static void F_83 ( struct V_2 * V_8 , struct V_2 * V_175 )
{
struct V_156 * V_157 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_157 -> V_10 ;
F_4 ( L_1 , V_8 ) ;
if ( V_175 ) {
struct V_9 * V_187 = F_3 ( V_175 ) -> V_10 ;
V_8 -> V_40 = V_175 -> V_40 ;
F_12 ( V_8 ) -> V_35 = F_12 ( V_175 ) -> V_35 ;
V_10 -> V_113 = V_187 -> V_113 ;
V_10 -> V_77 = V_187 -> V_77 ;
V_10 -> V_78 = V_187 -> V_78 ;
V_10 -> V_134 = V_187 -> V_134 ;
V_10 -> V_43 = V_187 -> V_43 ;
V_10 -> V_80 = V_187 -> V_80 ;
V_10 -> V_81 = V_187 -> V_81 ;
V_10 -> V_83 = V_187 -> V_83 ;
V_10 -> V_188 = V_187 -> V_188 ;
V_10 -> V_30 = V_187 -> V_30 ;
V_10 -> V_35 = V_187 -> V_35 ;
F_98 ( V_175 , V_8 ) ;
} else {
switch ( V_8 -> V_40 ) {
case V_122 :
V_10 -> V_113 = V_115 ;
break;
case V_189 :
V_10 -> V_113 = V_190 ;
break;
case V_41 :
case V_42 :
V_10 -> V_113 = V_114 ;
break;
}
V_10 -> V_77 = V_191 ;
V_10 -> V_78 = 0 ;
if ( ! V_47 && V_8 -> V_40 == V_42 ) {
V_10 -> V_43 = V_45 ;
F_44 ( V_133 , & V_10 -> V_134 ) ;
} else {
V_10 -> V_43 = V_44 ;
}
F_99 ( V_10 ) ;
}
V_10 -> V_79 = V_192 ;
V_10 -> V_177 = V_8 ;
V_10 -> V_3 = & V_193 ;
}
static struct V_2 * F_80 ( struct V_194 * V_194 , struct V_1 * V_2 ,
int V_195 , T_6 V_196 )
{
struct V_2 * V_8 ;
struct V_9 * V_10 ;
V_8 = F_100 ( V_194 , V_197 , V_196 , & V_198 ) ;
if ( ! V_8 )
return NULL ;
F_101 ( V_2 , V_8 ) ;
F_102 ( & F_12 ( V_8 ) -> V_199 ) ;
V_8 -> V_200 = F_95 ;
V_8 -> V_201 = V_202 ;
F_103 ( V_8 , V_163 ) ;
V_8 -> V_203 = V_195 ;
V_8 -> V_20 = V_21 ;
V_10 = F_104 () ;
if ( ! V_10 ) {
F_105 ( V_8 ) ;
return NULL ;
}
F_106 ( V_10 ) ;
V_10 -> V_8 = V_8 ;
F_3 ( V_8 ) -> V_10 = V_10 ;
return V_8 ;
}
static int F_107 ( struct V_194 * V_194 , struct V_1 * V_2 , int V_204 ,
int V_205 )
{
struct V_2 * V_8 ;
F_4 ( L_10 , V_2 ) ;
V_2 -> V_33 = V_206 ;
if ( V_2 -> type != V_41 && V_2 -> type != V_42 &&
V_2 -> type != V_189 && V_2 -> type != V_122 )
return - V_207 ;
if ( V_2 -> type == V_122 && ! V_205 && ! F_8 ( V_208 ) )
return - V_209 ;
V_2 -> V_3 = & V_4 ;
V_8 = F_80 ( V_194 , V_2 , V_204 , V_179 ) ;
if ( ! V_8 )
return - V_182 ;
F_83 ( V_8 , NULL ) ;
F_108 ( & V_174 , V_8 ) ;
return 0 ;
}
int T_7 F_109 ( void )
{
int V_14 ;
V_14 = F_110 ( & V_198 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_111 ( V_178 , & V_210 ) ;
if ( V_14 < 0 ) {
F_112 ( L_11 ) ;
goto error;
}
V_14 = F_113 ( & V_211 , L_12 , & V_174 ,
NULL ) ;
if ( V_14 < 0 ) {
F_112 ( L_13 ) ;
F_114 ( V_178 ) ;
goto error;
}
F_115 ( L_14 ) ;
return 0 ;
error:
F_116 ( & V_198 ) ;
return V_14 ;
}
void F_117 ( void )
{
F_118 ( & V_211 , L_12 ) ;
F_114 ( V_178 ) ;
F_116 ( & V_198 ) ;
}
